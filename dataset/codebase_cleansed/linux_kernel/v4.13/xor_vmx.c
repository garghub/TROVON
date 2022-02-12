void __xor_altivec_2(unsigned long bytes, unsigned long *v1_in,
unsigned long *v2_in)
{
DEFINE(v1);
DEFINE(v2);
unsigned long lines = bytes / (sizeof(unative_t)) / 4;
do {
LOAD(v1);
LOAD(v2);
XOR(v1, v2);
STORE(v1);
v1 += 4;
v2 += 4;
} while (--lines > 0);
}
void __xor_altivec_3(unsigned long bytes, unsigned long *v1_in,
unsigned long *v2_in, unsigned long *v3_in)
{
DEFINE(v1);
DEFINE(v2);
DEFINE(v3);
unsigned long lines = bytes / (sizeof(unative_t)) / 4;
do {
LOAD(v1);
LOAD(v2);
LOAD(v3);
XOR(v1, v2);
XOR(v1, v3);
STORE(v1);
v1 += 4;
v2 += 4;
v3 += 4;
} while (--lines > 0);
}
void __xor_altivec_4(unsigned long bytes, unsigned long *v1_in,
unsigned long *v2_in, unsigned long *v3_in,
unsigned long *v4_in)
{
DEFINE(v1);
DEFINE(v2);
DEFINE(v3);
DEFINE(v4);
unsigned long lines = bytes / (sizeof(unative_t)) / 4;
do {
LOAD(v1);
LOAD(v2);
LOAD(v3);
LOAD(v4);
XOR(v1, v2);
XOR(v3, v4);
XOR(v1, v3);
STORE(v1);
v1 += 4;
v2 += 4;
v3 += 4;
v4 += 4;
} while (--lines > 0);
}
void __xor_altivec_5(unsigned long bytes, unsigned long *v1_in,
unsigned long *v2_in, unsigned long *v3_in,
unsigned long *v4_in, unsigned long *v5_in)
{
DEFINE(v1);
DEFINE(v2);
DEFINE(v3);
DEFINE(v4);
DEFINE(v5);
unsigned long lines = bytes / (sizeof(unative_t)) / 4;
do {
LOAD(v1);
LOAD(v2);
LOAD(v3);
LOAD(v4);
LOAD(v5);
XOR(v1, v2);
XOR(v3, v4);
XOR(v1, v5);
XOR(v1, v3);
STORE(v1);
v1 += 4;
v2 += 4;
v3 += 4;
v4 += 4;
v5 += 4;
} while (--lines > 0);
}
