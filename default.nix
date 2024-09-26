{
  stdenv,
  wine,
  usbdm,
}:

stdenv.mkDerivation {
  pname = "wineusbdm";
  version = "0.0.0";

  src = ./.;

  buildInputs = [
    wine
    usbdm
  ];

  buildPhase = ''
    winegcc usbdm.spec -shared -m32 -o usbdm.4.dll usbdm.c -lusbdm
  '';

  installPhase = ''
    mkdir -p $out/lib/wine
    mv usbdm.4.dll.so $out/lib/wine
  '';
}
