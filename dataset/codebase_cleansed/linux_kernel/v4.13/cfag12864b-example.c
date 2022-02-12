static int cfag12864b_init(char *path)
{
cfag12864b_fd = open(path, O_RDWR);
if (cfag12864b_fd == -1)
return -1;
cfag12864b_mem = mmap(0, CFAG12864B_SIZE, PROT_READ | PROT_WRITE,
MAP_SHARED, cfag12864b_fd, 0);
if (cfag12864b_mem == MAP_FAILED) {
close(cfag12864b_fd);
return -2;
}
return 0;
}
static void cfag12864b_exit(void)
{
munmap(cfag12864b_mem, CFAG12864B_SIZE);
close(cfag12864b_fd);
}
static void cfag12864b_set(unsigned char x, unsigned char y)
{
if (CFAG12864B_CHECK(x, y))
cfag12864b_buffer[CFAG12864B_ADDRESS(x, y)] |=
CFAG12864B_BIT(x % CFAG12864B_BPB);
}
static void cfag12864b_unset(unsigned char x, unsigned char y)
{
if (CFAG12864B_CHECK(x, y))
cfag12864b_buffer[CFAG12864B_ADDRESS(x, y)] &=
~CFAG12864B_BIT(x % CFAG12864B_BPB);
}
static unsigned char cfag12864b_isset(unsigned char x, unsigned char y)
{
if (CFAG12864B_CHECK(x, y))
if (cfag12864b_buffer[CFAG12864B_ADDRESS(x, y)] &
CFAG12864B_BIT(x % CFAG12864B_BPB))
return 1;
return 0;
}
static void cfag12864b_not(unsigned char x, unsigned char y)
{
if (cfag12864b_isset(x, y))
cfag12864b_unset(x, y);
else
cfag12864b_set(x, y);
}
static void cfag12864b_fill(void)
{
unsigned short i;
for (i = 0; i < CFAG12864B_SIZE; i++)
cfag12864b_buffer[i] = 0xFF;
}
static void cfag12864b_clear(void)
{
unsigned short i;
for (i = 0; i < CFAG12864B_SIZE; i++)
cfag12864b_buffer[i] = 0;
}
static void cfag12864b_format(unsigned char * matrix)
{
unsigned char i, j, n;
for (i = 0; i < CFAG12864B_HEIGHT; i++)
for (j = 0; j < CFAG12864B_WIDTH / CFAG12864B_BPB; j++) {
cfag12864b_buffer[i * CFAG12864B_WIDTH / CFAG12864B_BPB +
j] = 0;
for (n = 0; n < CFAG12864B_BPB; n++)
if (matrix[i * CFAG12864B_WIDTH +
j * CFAG12864B_BPB + n])
cfag12864b_buffer[i * CFAG12864B_WIDTH /
CFAG12864B_BPB + j] |=
CFAG12864B_BIT(n);
}
}
static void cfag12864b_blit(void)
{
memcpy(cfag12864b_mem, cfag12864b_buffer, CFAG12864B_SIZE);
}
static void example(unsigned char n)
{
unsigned short i, j;
unsigned char matrix[CFAG12864B_WIDTH * CFAG12864B_HEIGHT];
if (n > EXAMPLES)
return;
printf("Example %i/%i - ", n, EXAMPLES);
switch (n) {
case 1:
printf("Draw points setting bits");
cfag12864b_clear();
for (i = 0; i < CFAG12864B_WIDTH; i += 2)
for (j = 0; j < CFAG12864B_HEIGHT; j += 2)
cfag12864b_set(i, j);
break;
case 2:
printf("Clear the LCD");
cfag12864b_clear();
break;
case 3:
printf("Draw rows formatting a [128*64] matrix");
memset(matrix, 0, CFAG12864B_WIDTH * CFAG12864B_HEIGHT);
for (i = 0; i < CFAG12864B_WIDTH; i++)
for (j = 0; j < CFAG12864B_HEIGHT; j += 2)
matrix[j * CFAG12864B_WIDTH + i] = 1;
cfag12864b_format(matrix);
break;
case 4:
printf("Fill the lcd");
cfag12864b_fill();
break;
case 5:
printf("Draw columns unsetting bits");
for (i = 0; i < CFAG12864B_WIDTH; i += 2)
for (j = 0; j < CFAG12864B_HEIGHT; j++)
cfag12864b_unset(i, j);
break;
case 6:
printf("Do negative not-ing all bits");
for (i = 0; i < CFAG12864B_WIDTH; i++)
for (j = 0; j < CFAG12864B_HEIGHT; j ++)
cfag12864b_not(i, j);
break;
}
puts(" - [Press Enter]");
}
int main(int argc, char *argv[])
{
unsigned char n;
if (argc != 2) {
printf(
"Sintax: %s fbdev\n"
"Usually: /dev/fb0, /dev/fb1...\n", argv[0]);
return -1;
}
if (cfag12864b_init(argv[1])) {
printf("Can't init %s fbdev\n", argv[1]);
return -2;
}
for (n = 1; n <= EXAMPLES; n++) {
example(n);
cfag12864b_blit();
while (getchar() != '\n');
}
cfag12864b_exit();
return 0;
}
