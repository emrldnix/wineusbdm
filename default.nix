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
    runHook preInstall

    mkdir -p $out/lib/wine
    mv usbdm.4.dll.so $out/lib/wine

    runHook postInstall
  '';

  postInstall = ''
    export WINEDLLPATH="$out/lib/wine"''${WINEDLLPATH:+':'}$WINEDLLPATH
    export WINEDLLOVERRIDES="usbdm.4=b"''${WINEDLLOVERRIDES:+','}$WINEDLLOVERRIDES
  '';
}
