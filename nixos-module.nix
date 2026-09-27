self:
{
  inputs,
  config,
  lib,
  pkgs,
  ...
}:
let
  cfg = config.hardware.usbdm;
  usbdmPackage = self.inputs.usbdm-flake.packages.${pkgs.stdenv.hostPlatform.system}.default;
  defaultPackage = self.packages.${pkgs.stdenv.hostPlatform.system}.wineusbdm;
in
{
  options.hardware.usbdm = {
    enable = lib.mkEnableOption "Whether or not to enable USBDM.";
    package = lib.mkPackageOption pkgs "USBDM" {
      default = usbdmPackage;
    };
    wineLibPackage = lib.mkPackageOption pkgs "WineUSBDM" {
      default = defaultPackage;
    };

    udev = lib.mkEnableOption "Whether to add the udev rules for USBDM.";
  };

  config = lib.mkIf cfg.enable {
    environment.systemPackages = [
      cfg.package
      cfg.wineLibPackage
    ];
    services.udev.packages = lib.mkIf cfg.udev [ cfg.package ];
  };
}
