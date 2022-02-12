static int align(int n)
{
if (is64bit)
return (n + 0x1fff) & ~0x1fff;
else
return (n + 0xfff) & ~0xfff;
}
static unsigned short ld2(char *p)
{
return (p[0] << 8) | p[1];
}
static void st4(char *p, unsigned int x)
{
p[0] = x >> 24;
p[1] = x >> 16;
p[2] = x >> 8;
p[3] = x;
}
static void die(const char *str)
{
perror(str);
exit(1);
}
static void usage(void)
{
fprintf(stderr, "Usage: piggyback bits vmlinux.aout System.map fs_img.gz\n");
fprintf(stderr, "\tKernel image will be modified in place.\n");
exit(1);
}
static int start_line(const char *line)
{
if (strcmp(line + 10, " _start\n") == 0)
return 1;
else if (strcmp(line + 18, " _start\n") == 0)
return 1;
return 0;
}
static int end_line(const char *line)
{
if (strcmp(line + 10, " _end\n") == 0)
return 1;
else if (strcmp (line + 18, " _end\n") == 0)
return 1;
return 0;
}
static int get_start_end(const char *filename, unsigned int *start,
unsigned int *end)
{
FILE *map;
char buffer[1024];
*start = 0;
*end = 0;
map = fopen(filename, "r");
if (!map)
die(filename);
while (fgets(buffer, 1024, map)) {
if (start_line(buffer))
*start = strtoul(buffer, NULL, 16);
else if (end_line(buffer))
*end = strtoul(buffer, NULL, 16);
}
fclose (map);
if (*start == 0 || *end == 0)
return 0;
return 1;
}
static off_t get_hdrs_offset(int kernelfd, const char *filename)
{
char buffer[BUFSIZE];
off_t offset;
int i;
if (lseek(kernelfd, 0, SEEK_SET) < 0)
die("lseek");
if (read(kernelfd, buffer, BUFSIZE) != BUFSIZE)
die(filename);
if (buffer[40] == 'H' && buffer[41] == 'd' &&
buffer[42] == 'r' && buffer[43] == 'S') {
return 40;
} else {
offset = ld2(buffer + AOUT_TEXT_OFFSET + 2) << 2;
offset -= LOOKBACK;
offset += AOUT_TEXT_OFFSET;
if (lseek(kernelfd, offset, SEEK_SET) < 0)
die("lseek");
if (read(kernelfd, buffer, BUFSIZE) != BUFSIZE)
die(filename);
for (i = 0; i < LOOKBACK; i += 4) {
if (buffer[i + 0] == 'H' && buffer[i + 1] == 'd' &&
buffer[i + 2] == 'r' && buffer[i + 3] == 'S') {
return offset + i;
}
}
}
fprintf (stderr, "Couldn't find headers signature in %s\n", filename);
exit(1);
}
int main(int argc,char **argv)
{
static char aout_magic[] = { 0x01, 0x03, 0x01, 0x07 };
char buffer[1024];
unsigned int i, start, end;
off_t offset;
struct stat s;
int image, tail;
if (argc != 5)
usage();
if (strcmp(argv[1], "64") == 0)
is64bit = 1;
if (stat (argv[4], &s) < 0)
die(argv[4]);
if (!get_start_end(argv[3], &start, &end)) {
fprintf(stderr, "Could not determine start and end from %s\n",
argv[3]);
exit(1);
}
if ((image = open(argv[2], O_RDWR)) < 0)
die(argv[2]);
if (read(image, buffer, 512) != 512)
die(argv[2]);
if (memcmp(buffer, aout_magic, 4) != 0) {
fprintf (stderr, "Not a.out. Don't blame me.\n");
exit(1);
}
offset = get_hdrs_offset(image, argv[2]);
offset += 10;
if (lseek(image, offset, 0) < 0)
die("lseek");
st4(buffer, 0);
st4(buffer + 4, 0x01000000);
st4(buffer + 8, align(end + 32));
st4(buffer + 12, s.st_size);
if (write(image, buffer + 2, 14) != 14)
die(argv[2]);
if (is64bit)
{
if (lseek(image, 4, 0) < 0)
die("lseek");
st4(buffer, align(end + 32 + 8191) - (start & ~0x3fffffUL) +
s.st_size);
st4(buffer + 4, 0);
st4(buffer + 8, 0);
if (write(image, buffer, 12) != 12)
die(argv[2]);
}
if (lseek(image, AOUT_TEXT_OFFSET - start + align(end + 32), 0) < 0)
die("lseek");
if ((tail = open(argv[4], O_RDONLY)) < 0)
die(argv[4]);
while ((i = read(tail, buffer, 1024)) > 0)
if (write(image, buffer, i) != i)
die(argv[2]);
if (close(image) < 0)
die("close");
if (close(tail) < 0)
die("close");
return 0;
}
