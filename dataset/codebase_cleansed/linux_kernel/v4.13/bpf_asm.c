int main(int argc, char **argv)
{
FILE *fp = stdin;
bool cstyle = false;
int i;
for (i = 1; i < argc; i++) {
if (!strncmp("-c", argv[i], 2)) {
cstyle = true;
continue;
}
fp = fopen(argv[i], "r");
if (!fp) {
fp = stdin;
continue;
}
break;
}
bpf_asm_compile(fp, cstyle);
return 0;
}
