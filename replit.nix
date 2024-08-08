{ pkgs }: {
	deps = [
		pkgs.clang
		pkgs.ccls
		pkgs.gdb
		pkgs.cmake
		pkgs.SDL2
	];
}