{
  pkgs,
  ...
}:

{
  packages = with pkgs; [
    llvmPackages_19.clang-tools
    meson
    gcc14
    just
  ];
}
