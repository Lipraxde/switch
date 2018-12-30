#include <stdio.h>

#define MAGIC_NUM 10

class Base {
public:
    constexpr static const char name[] = "Base";
    enum E {
        A = MAGIC_NUM,
        B,
        C,
        D,
    };
};

class Arch1 : public Base {
public:
    constexpr static const char name[] = "Arch1";
    enum E {
        A = 1,
        B = 2,
    };
};

class Arch2 : public Base {
public:
    constexpr static const char name[] = "Arch2";
    enum E {
        B = 3,
        D = 5,
    };
};

template <typename Arch>
class Magic {
public:
    static void foo(int num) {
        printf("%s %d:\t", Arch::name, num);
        switch (num) {
            case Arch::A:
                if (Arch::A >= MAGIC_NUM)
                    goto preserve_label;
                printf("A: %d\n", num);
                break;
            case Arch::B:
                if (Arch::B >= MAGIC_NUM)
                    goto preserve_label;
                printf("B: %d\n", num);
                break;
            case Arch::C:
                if (Arch::C >= MAGIC_NUM)
                    goto preserve_label;
                printf("C: %d\n", num);
                break;
            case Arch::D:
                if (Arch::D >= MAGIC_NUM)
                    goto preserve_label;
                printf("D: %d\n", num);
                break;
            default:
preserve_label:
                printf("unsupport\n");
                break;
        }
    }
};

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    for (int i=0; i<12; i++) {
        Magic<Arch1>::foo(i);
    }

    for (int i=0; i<12; i++) {
        Magic<Arch2>::foo(i);
    }
}
