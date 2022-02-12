void prom_putchar(char c)
{
ULONG cnt;
CHAR it = c;
bc_disable();
ArcWrite(1, &it, 1, &cnt);
bc_enable();
}
char prom_getchar(void)
{
ULONG cnt;
CHAR c;
bc_disable();
ArcRead(0, &c, 1, &cnt);
bc_enable();
return c;
}
