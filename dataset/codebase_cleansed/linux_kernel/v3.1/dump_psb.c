static int
decode_pst(char *p, int npstates)
{
int i;
int freq, fid, vid;
for (i = 0; i < npstates; ++i) {
fid = *p++;
vid = *p++;
freq = 100 * fid_to_mult[fid] * fsb;
printf(" %2d %8dkHz FID %02x (%2d.%01d) VID %02x (%4dmV)\n",
i,
freq,
fid, fid_to_mult[fid]/10, fid_to_mult[fid]%10,
vid, vid_to_voltage[vid]);
}
return 0;
}
static
void decode_psb(char *p, int numpst)
{
int i;
struct psb_header *psb;
struct pst_header *pst;
psb = (struct psb_header*) p;
if (psb->version != 0x12)
return;
printf("PSB version: %hhx flags: %hhx settling time %hhuus res1 %hhx num pst %hhu\n",
psb->version,
psb->flags,
psb->settlingtime,
psb->res1,
psb->numpst);
sgtc = psb->settlingtime * 100;
if (sgtc < 10000)
sgtc = 10000;
p = ((char *) psb) + sizeof(struct psb_header);
if (numpst < 0)
numpst = psb->numpst;
else
printf("Overriding number of pst :%d\n", numpst);
for (i = 0; i < numpst; i++) {
pst = (struct pst_header*) p;
if (relevant != 0) {
if (relevant!= pst->cpuid)
goto next_one;
}
printf(" PST %d cpuid %.3x fsb %hhu mfid %hhx svid %hhx numberstates %hhu\n",
i+1,
pst->cpuid,
pst->fsb,
pst->maxfid,
pst->startvid,
pst->numpstates);
fsb = pst->fsb;
decode_pst(p + sizeof(struct pst_header), pst->numpstates);
next_one:
p += sizeof(struct pst_header) + 2*pst->numpstates;
}
}
void print_help(void)
{
printf ("Usage: dump_psb [options]\n");
printf ("Options:\n");
printf (" -n, --numpst Set number of PST tables to scan\n");
printf (" -r, --relevant Only display PSTs relevant to cpuid N\n");
}
int
main(int argc, char *argv[])
{
int fd;
int numpst=-1;
int ret=0, cont=1;
char *mem = NULL;
char *p;
do {
ret = getopt_long(argc, argv, "hr:n:", info_opts, NULL);
switch (ret){
case '?':
case 'h':
print_help();
cont = 0;
break;
case 'r':
relevant = strtol(optarg, NULL, 16);
break;
case 'n':
numpst = strtol(optarg, NULL, 10);
break;
case -1:
cont = 0;
break;
}
} while(cont);
fd = open("/dev/mem", O_RDONLY);
if (fd < 0) {
printf ("Couldn't open /dev/mem. Are you root?\n");
exit(1);
}
mem = mmap(mem, 0x100000 - 0xc0000, PROT_READ, MAP_SHARED, fd, 0xc0000);
close(fd);
for (p = mem; p - mem < LEN; p+=16) {
if (memcmp(p, "AMDK7PNOW!", 10) == 0) {
decode_psb(p, numpst);
break;
}
}
munmap(mem, LEN);
return 0;
}
