#shell.nix

{pkgs ? import <nixpkgs> {}}:

pkgs.mkShell
{
  buildInputs = with pkgs; [
    libgcc
    gnumake42
    SDL2    
  ];
  nativeBuildInputs = with pkgs; [

  ];
}
