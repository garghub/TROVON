static int F_1 ( void )
{
unsigned char V_1 ;
unsigned long V_2 ;
if ( V_3 != 0 ) {
V_1 = F_2 ( V_3 ) ;
} else {
F_3 ( V_2 ) ;
F_4 ( 0x8e , 0xe4 ) ;
V_1 = F_2 ( 0xe5 ) ;
F_5 ( V_2 ) ;
}
return ( int ) V_1 ;
}
static int F_6 ( T_1 * V_4 )
{
unsigned long V_5 , V_6 , V_2 ;
unsigned char V_7 ;
V_5 = V_4 -> V_5 & 0xff00 ;
V_6 = V_4 -> V_6 & 0xffff ;
if ( V_8 == 0xfccb ) {
if ( V_5 == 0xfe00 ) {
F_3 ( V_2 ) ;
F_4 ( 0xbe , 0xe4 ) ;
V_7 = F_2 ( 0xe5 ) ;
F_5 ( V_2 ) ;
V_4 -> V_5 = 0x00 ;
V_4 -> V_6 = ( unsigned int ) ( V_7 & 0x01 ) ;
}
if ( ( V_5 == 0xff00 ) && ( V_6 == 0x0000 ) ) {
F_3 ( V_2 ) ;
F_4 ( 0xbe , 0xe4 ) ;
V_7 = F_2 ( 0xe5 ) ;
F_4 ( 0xbe , 0xe4 ) ;
F_4 ( V_7 | 0x01 , 0xe5 ) ;
F_5 ( V_2 ) ;
V_4 -> V_5 = 0x00 ;
V_4 -> V_6 = 0x00 ;
}
if ( ( V_5 == 0xff00 ) && ( V_6 == 0x0001 ) ) {
F_3 ( V_2 ) ;
F_4 ( 0xbe , 0xe4 ) ;
V_7 = F_2 ( 0xe5 ) ;
F_4 ( 0xbe , 0xe4 ) ;
F_4 ( V_7 & 0xfe , 0xe5 ) ;
F_5 ( V_2 ) ;
V_4 -> V_5 = 0x00 ;
V_4 -> V_6 = 0x01 ;
}
}
if ( V_8 == 0xfccc ) {
if ( V_5 == 0xfe00 ) {
F_3 ( V_2 ) ;
F_4 ( 0xe0 , 0xe4 ) ;
V_7 = F_2 ( 0xe5 ) ;
F_5 ( V_2 ) ;
V_4 -> V_5 = 0x00 ;
V_4 -> V_6 = V_7 & 0x01 ;
}
if ( ( V_5 == 0xff00 ) && ( V_6 == 0x0000 ) ) {
F_3 ( V_2 ) ;
F_4 ( 0xe0 , 0xe4 ) ;
V_7 = F_2 ( 0xe5 ) ;
F_7 ( 0xe0 | ( ( V_7 & 0xfe ) << 8 ) , 0xe4 ) ;
F_5 ( V_2 ) ;
V_4 -> V_5 = 0x00 ;
V_4 -> V_6 = 0x00 ;
}
if ( ( V_5 == 0xff00 ) && ( V_6 == 0x0001 ) ) {
F_3 ( V_2 ) ;
F_4 ( 0xe0 , 0xe4 ) ;
V_7 = F_2 ( 0xe5 ) ;
F_7 ( 0xe0 | ( ( V_7 | 0x01 ) << 8 ) , 0xe4 ) ;
F_5 ( V_2 ) ;
V_4 -> V_5 = 0x00 ;
V_4 -> V_6 = 0x01 ;
}
}
return 0 ;
}
int F_8 ( T_1 * V_4 )
{
int V_5 ;
asm ("# load the values into the registers\n\t" \
"pushl %%eax\n\t" \
"movl 0(%%eax),%%edx\n\t" \
"push %%edx\n\t" \
"movl 4(%%eax),%%ebx\n\t" \
"movl 8(%%eax),%%ecx\n\t" \
"movl 12(%%eax),%%edx\n\t" \
"movl 16(%%eax),%%esi\n\t" \
"movl 20(%%eax),%%edi\n\t" \
"popl %%eax\n\t" \
"# call the System Management mode\n\t" \
"inb $0xb2,%%al\n\t"
"# fill out the memory with the values in the registers\n\t" \
"xchgl %%eax,(%%esp)\n\t"
"movl %%ebx,4(%%eax)\n\t" \
"movl %%ecx,8(%%eax)\n\t" \
"movl %%edx,12(%%eax)\n\t" \
"movl %%esi,16(%%eax)\n\t" \
"movl %%edi,20(%%eax)\n\t" \
"popl %%edx\n\t" \
"movl %%edx,0(%%eax)\n\t" \
"# setup the return value to the carry flag\n\t" \
"lahf\n\t" \
"shrl $8,%%eax\n\t" \
"andl $1,%%eax\n" \
: "=a" (eax)
: "a" (regs)
: "%ebx", "%ecx", "%edx", "%esi", "%edi", "memory");
return V_5 ;
}
static long F_9 ( struct V_9 * V_10 , unsigned int V_11 , unsigned long V_12 )
{
T_1 V_4 ;
T_1 T_2 * V_13 = ( T_1 T_2 * ) V_12 ;
unsigned short V_14 , V_15 ;
int V_16 ;
if ( ! V_13 )
return - V_17 ;
if ( F_10 ( & V_4 , V_13 , sizeof( T_1 ) ) )
return - V_18 ;
switch ( V_11 ) {
case V_19 :
V_14 = V_4 . V_5 & 0xff00 ;
V_15 = V_4 . V_20 & 0xffff ;
if ( ( ( V_14 == 0xff00 ) || ( V_14 == 0xfe00 ) ) && ( V_15 > 0x0069 ) )
return - V_17 ;
F_11 ( & V_21 ) ;
if ( V_22 == 1 ) {
if ( ( ( V_14 == 0xf300 ) || ( V_14 == 0xf400 ) ) && ( V_15 == 0x0004 ) ) {
V_16 = F_6 ( & V_4 ) ;
F_12 ( & V_21 ) ;
break;
}
}
V_16 = F_8 ( & V_4 ) ;
F_12 ( & V_21 ) ;
break;
default:
return - V_17 ;
}
if ( F_13 ( V_13 , & V_4 , sizeof( T_1 ) ) )
return - V_18 ;
return ( V_16 == 0 ) ? 0 : - V_17 ;
}
static int F_14 ( struct V_23 * V_24 , void * V_25 )
{
int V_26 ;
V_26 = F_1 () ;
F_15 ( V_24 , L_1 ,
V_8 ,
( V_27 & 0xff00 ) >> 8 ,
V_27 & 0xff ,
( V_28 & 0xff00 ) >> 8 ,
V_28 & 0xff ,
V_29 ,
V_26 ) ;
return 0 ;
}
static int F_16 ( struct V_30 * V_30 , struct V_9 * V_9 )
{
return F_17 ( V_9 , F_14 , NULL ) ;
}
static void F_18 ( void )
{
switch ( V_8 ) {
case 0xfc02 : case 0xfc04 : case 0xfc09 : case 0xfc0a : case 0xfc10 :
case 0xfc11 : case 0xfc13 : case 0xfc15 : case 0xfc1a : case 0xfc1b :
case 0xfc5a :
V_3 = 0x62 ;
break;
case 0xfc08 : case 0xfc17 : case 0xfc1d : case 0xfcd1 : case 0xfce0 :
case 0xfce2 :
V_3 = 0x68 ;
break;
default:
V_3 = 0x00 ;
break;
}
return;
}
static int F_19 ( void T_3 * V_31 )
{
int V_32 ;
T_1 V_4 ;
unsigned short V_15 , V_33 ;
unsigned long V_34 ;
V_32 = ( 0x100 * ( int ) F_20 ( V_31 + 0xfffe ) ) + ( ( int ) F_20 ( V_31 + 0xfffa ) ) ;
if ( V_32 == 0xfc2f ) {
V_4 . V_5 = 0xc000 ;
V_4 . V_20 = 0x0000 ;
V_4 . V_6 = 0x0000 ;
F_8 ( & V_4 ) ;
V_15 = ( unsigned short ) ( V_4 . V_20 & 0xffff ) ;
#if V_35
F_21 ( L_2 , V_4 . V_20 ) ;
#endif
V_15 = 0xe6f5 ;
V_34 = V_15 ;
V_33 = F_22 ( V_31 + V_34 ) ;
V_34 = 9 + V_15 + V_33 ;
V_33 = F_22 ( V_31 + V_34 ) ;
V_34 = 0xa + V_33 ;
V_33 = F_22 ( V_31 + V_34 ) ;
V_32 = ( ( V_33 & 0xff ) << 8 ) + ( ( V_33 & 0xff00 ) >> 8 ) ;
}
return V_32 ;
}
static int F_23 ( void )
{
int V_36 , V_37 , V_38 , V_39 , V_40 , V_41 , V_42 ;
unsigned char V_43 [ 7 ] = { 0x54 , 0x4f , 0x53 , 0x48 , 0x49 , 0x42 , 0x41 } ;
T_1 V_4 ;
void T_3 * V_31 = F_24 ( 0xf0000 , 0x10000 ) ;
if ( ! V_31 )
return - V_44 ;
for ( V_36 = 0 ; V_36 < 7 ; V_36 ++ ) {
if ( F_20 ( V_31 + 0xe010 + V_36 ) != V_43 [ V_36 ] ) {
F_21 ( L_3 ) ;
F_25 ( V_31 ) ;
return - V_45 ;
}
}
V_4 . V_5 = 0xf0f0 ;
V_4 . V_20 = 0x0000 ;
V_4 . V_6 = 0x0000 ;
V_42 = F_8 ( & V_4 ) ;
if ( ( V_42 == 1 ) || ( ( V_4 . V_5 & 0xff00 ) == 0x8600 ) ) {
F_21 ( L_3 ) ;
F_25 ( V_31 ) ;
return - V_45 ;
}
V_27 = V_4 . V_46 & 0xffff ;
V_8 = F_19 ( V_31 ) ;
V_37 = F_20 ( V_31 + 0xe009 ) - '0' ;
V_38 = ( ( F_20 ( V_31 + 0xe00b ) - '0' ) * 10 ) + ( F_20 ( V_31 + 0xe00c ) - '0' ) ;
V_28 = ( V_37 * 0x100 ) + V_38 ;
V_39 = ( ( F_20 ( V_31 + 0xfff5 ) - '0' ) * 10 ) + ( F_20 ( V_31 + 0xfff6 ) - '0' ) ;
V_41 = ( ( F_20 ( V_31 + 0xfff8 ) - '0' ) * 10 ) + ( F_20 ( V_31 + 0xfff9 ) - '0' ) ;
V_40 = ( ( F_20 ( V_31 + 0xfffb ) - '0' ) * 10 ) + ( F_20 ( V_31 + 0xfffc ) - '0' ) ;
V_29 = ( ( ( V_40 - 90 ) & 0x1f ) << 10 ) | ( ( V_41 & 0xf ) << 6 )
| ( ( V_39 & 0x1f ) << 1 ) ;
if ( ( V_8 == 0xfccb ) || ( V_8 == 0xfccc ) )
V_22 = 1 ;
F_25 ( V_31 ) ;
return 0 ;
}
static int T_4 F_26 ( void )
{
int V_47 ;
if ( F_23 () )
return - V_45 ;
F_21 ( V_48 L_4 V_49 L_5 ) ;
if ( V_3 == 0x00 )
F_18 () ;
V_47 = F_27 ( & V_50 ) ;
if ( V_47 < 0 )
return V_47 ;
#ifdef F_28
{
struct V_51 * V_52 ;
V_52 = F_29 ( L_6 , 0 , NULL , & V_53 ) ;
if ( ! V_52 ) {
F_30 ( & V_50 ) ;
return - V_44 ;
}
}
#endif
return 0 ;
}
static void T_5 F_31 ( void )
{
F_32 ( L_6 , NULL ) ;
F_30 ( & V_50 ) ;
}
