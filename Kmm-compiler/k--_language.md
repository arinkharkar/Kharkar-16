This programming language is very similar to C (the greatest language fyi), just dumbed down (thus minus minus :D)

types:
    For now, the only type is u16, a 16 bit unsigned integer

differences from C:
    no union, volatile (no optimization will be done so this is redundant), switch, for loops (just while loops), inline, enum, typedef, struct, static, sizeof, floating point anything, const

    Essentially, the most important parts are all that are left

    Also, no header files. They are a remnant of the past and are not needed. The built in build system (Kake) will take in a list of files to build and built to a flat binary. No function headers are necessary, import will be used to import from other files.

    Pointers: 
        Since the only type is u16, any variable can be a pointer simply by appending a * behind it. (Ex. u16 a = 7; *a = 3; does Memory[7] = 3)

example program:

    import os;

    u16 main() {
        u16 i = 0;
        while (i < 15) {
            os.print("Hello World");
            i++;
        }
        return 0;
    }
    