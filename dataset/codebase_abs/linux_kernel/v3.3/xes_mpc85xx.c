void T_1 F_1 ( void )
{
struct V_1 * V_1 = F_2 ( NULL , 0 ,
V_2 |
V_3 | V_4 ,
0 , 256 , L_1 ) ;
F_3 ( V_1 == NULL ) ;
F_4 ( V_1 ) ;
}
static void F_5 ( void T_2 * V_5 )
{
volatile T_3 V_6 , V_7 ;
asm volatile("msync; isync");
V_7 = F_6 ( V_5 ) ;
F_7 ( V_8 L_2 ) ;
V_6 = V_9 | V_10 ;
if ( F_8 ( L_3 ) ||
F_8 ( L_4 ) )
V_6 |= ( V_7 & V_11 ) >> 2 ;
asm volatile("msync; isync");
F_9 ( V_5 , V_6 ) ;
asm volatile("msync; isync");
}
static void F_10 ( void )
{
struct V_12 * V_13 ;
int V_14 ;
F_11 (np, L_5 ) {
struct V_15 V_16 [ 2 ] ;
void T_2 * V_5 ;
if ( ! F_12 ( V_13 ,
L_6 ) &&
! F_12 ( V_13 ,
L_7 ) &&
! F_12 ( V_13 ,
L_8 ) )
continue;
V_14 = F_13 ( V_13 , 0 , & V_16 [ 0 ] ) ;
if ( V_14 ) {
F_7 ( V_17 L_9
L_10 ,
V_13 -> V_18 ) ;
continue;
}
V_5 = F_14 ( V_16 [ 0 ] . V_19 , F_15 ( & V_16 [ 0 ] ) ) ;
F_5 ( V_5 ) ;
}
}
static void T_1 F_16 ( void )
{
#ifdef F_17
struct V_12 * V_13 ;
#endif
struct V_12 * V_20 ;
const char * V_21 = L_11 ;
V_20 = F_18 ( L_12 ) ;
if ( V_20 == NULL )
return;
V_21 = F_19 ( V_20 , L_13 , NULL ) ;
F_7 ( V_8 L_14 ,
V_21 + strlen ( L_15 ) ) ;
F_10 () ;
#ifdef F_17
F_20 (np, L_16 ) {
if ( F_12 ( V_13 , L_17 ) ||
F_12 ( V_13 , L_18 ) ) {
struct V_15 V_22 ;
F_13 ( V_13 , 0 , & V_22 ) ;
if ( ( V_22 . V_19 & 0xfffff ) == V_23 )
F_21 ( V_13 , 1 ) ;
else
F_21 ( V_13 , 0 ) ;
}
}
#endif
F_22 () ;
}
static int T_1 F_23 ( void )
{
unsigned long V_20 = F_24 () ;
if ( F_25 ( V_20 , L_19 ) ) {
#ifdef F_17
V_23 = 0x8000 ;
#endif
return 1 ;
} else {
return 0 ;
}
}
static int T_1 F_26 ( void )
{
unsigned long V_20 = F_24 () ;
if ( F_25 ( V_20 , L_20 ) ) {
#ifdef F_17
V_23 = 0xb000 ;
#endif
return 1 ;
} else {
return 0 ;
}
}
static int T_1 F_27 ( void )
{
unsigned long V_20 = F_24 () ;
if ( F_25 ( V_20 , L_21 ) ) {
#ifdef F_17
V_23 = 0xb000 ;
#endif
return 1 ;
} else {
return 0 ;
}
}
