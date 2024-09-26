{
  description = "wineusbdm";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-23.11";
    usbdm-flake = {
      url = "github:ryand56/usbdm-nix";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs = { self, nixpkgs, usbdm-flake }:
    let
      systems = [ "x86_64-linux" "i686-linux" ];
      overlay = final: prev: {
        wineusbdm = final.pkgsi686Linux.callPackage ./default.nix {
          usbdm = usbdm-flake.packages.i686-linux.usbdm;
        };
      };
      forAllSystems = f: nixpkgs.lib.genAttrs systems (system: f system);
      nixpkgsFor = forAllSystems (system:
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
      packages = forAllSystems (system: {
        inherit (nixpkgsFor.${system}) wineusbdm;
      });
    };
}
