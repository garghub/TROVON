static void T_1 F_1 ( char * V_1 , T_2 V_2 )
{
int V_3 , V_4 ;
for ( V_3 = 1 ; V_3 <= 4 ; V_3 ++ ) {
V_4 = ( V_2 >> ( 16 - 4 * V_3 ) ) & 0xf ;
if ( V_4 >= 10 )
V_4 += 7 ;
* V_1 ++ = '0' + V_4 ;
}
* V_1 = '\0' ;
}
static void T_1 F_2 ( void )
{
static char V_5 [ 80 ] V_6 = L_1 ;
char V_7 [ 5 ] ;
struct V_8 V_9 ;
F_3 ( & V_9 ) ;
F_1 ( V_7 , V_9 . V_10 ) ;
strcat ( V_5 , V_7 ) ;
strcat ( V_5 , L_2 ) ;
F_4 ( V_5 ) ;
}
static void T_1 F_5 ( char * V_1 , T_2 V_2 )
{
int div = 1 ;
while ( div * 10 <= V_2 )
div *= 10 ;
while ( div ) {
* V_1 ++ = '0' + V_2 / div ;
V_2 %= div ;
div /= 10 ;
}
* V_1 = '\0' ;
}
static void T_1 F_6 ( void )
{
static char V_11 [ 80 ] V_6 = L_3 ;
unsigned long V_2 ;
char V_12 [ 6 ] ;
int V_3 , V_13 , V_14 ;
V_14 = 1 ;
for ( V_3 = 0 ; V_3 < F_7 ( V_15 ) ; V_3 ++ ) {
V_2 = ~ V_16 . V_17 [ V_3 ] & V_15 [ V_3 ] ;
for ( V_13 = 0 ; V_13 < V_18 ; V_13 ++ ) {
if ( ! ( V_2 & ( 1UL << ( V_18 - 1 - V_13 ) ) ) )
continue;
if ( ! V_14 )
strcat ( V_11 , L_4 ) ;
if ( strlen ( V_11 ) > 70 ) {
strcat ( V_11 , L_2 ) ;
F_4 ( V_11 ) ;
* V_11 = '\0' ;
}
F_5 ( V_12 , V_3 * V_18 + V_13 ) ;
strcat ( V_11 , V_12 ) ;
V_14 = 0 ;
}
}
strcat ( V_11 , L_2 ) ;
F_4 ( V_11 ) ;
F_4 ( L_5 ) ;
}
static void T_1 F_8 ( void )
{
F_4 ( L_6 ) ;
F_2 () ;
F_6 () ;
F_9 ( 0x8badcccc ) ;
}
void T_1 F_10 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_7 ( V_16 . V_17 ) ; V_3 ++ )
V_16 . V_17 [ V_3 ] = 0 ;
asm volatile(
" stfl 0(0)\n"
: "=m" (S390_lowcore.stfl_fac_list));
V_16 . V_17 [ 0 ] = ( V_19 ) V_16 . V_20 << 32 ;
if ( V_16 . V_20 & 0x01000000 ) {
register unsigned long T_3 V_21 ( L_7 ) = F_7 ( V_15 ) - 1 ;
asm volatile(".insn s,0xb2b00000,0(%1)"
: "+d" (reg0)
: "a" (&S390_lowcore.stfle_fac_list)
: "memory", "cc");
}
for ( V_3 = 0 ; V_3 < F_7 ( V_15 ) ; V_3 ++ ) {
if ( ( V_16 . V_17 [ V_3 ] & V_15 [ V_3 ] ) != V_15 [ V_3 ] )
F_8 () ;
}
}
