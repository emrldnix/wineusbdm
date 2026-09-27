{
  description = "wineusbdm";

  inputs = {
    nixpkgs.url = "https://channels.nixos.org/nixpkgs-unstable/nixexprs.tar.zst";

    usbdm-flake = {
      url = "github:ryand56/usbdm-nix";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs =
    {
      self,
      nixpkgs,
      usbdm-flake,
    }:
    let
      systems = [
        "x86_64-linux"
        "i686-linux"
      ];
      overlay = final: prev: {
        spidermonkey_140 =
          if final.stdenv.hostPlatform.system == "i686-linux" then
            prev.spidermonkey_140.overrideAttrs (oa: {
              env.NIX_CFLAGS_COMPILE = "-Wno-error=format -Wno-error=format-security";
            })
          else prev.spidermonkey_140;
      };
      forAllSystems = f: nixpkgs.lib.genAttrs systems (system: f system);

      nixpkgsFor = forAllSystems (
        system:
        import nixpkgs {
          inherit system;
          overlays = [ self.overlay ];
          config.allowUnfree = true;
        }
      );
    in
    {
      inherit overlay;
      defaultPackage = forAllSystems (system: nixpkgsFor.${system}.wineusbdm);

      formatter = forAllSystems (system: nixpkgsFor.${system}.nixfmt-rfc-style);

      packages = forAllSystems (system: {
        wineusbdm = nixpkgsFor.${system}.callPackage ./default.nix {
          usbdm = usbdm-flake.packages.${system}.usbdm;
        };
      });

      nixosModules =
        let
          default = import ./nixos-module.nix self;
        in
        {
          inherit default;
          wineusbdm = default;
        };
    };
}
