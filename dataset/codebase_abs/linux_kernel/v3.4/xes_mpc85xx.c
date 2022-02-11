void T_1 F_1 ( void )
{
struct V_1 * V_1 = F_2 ( NULL , 0 , V_2 ,
0 , 256 , L_1 ) ;
F_3 ( V_1 == NULL ) ;
F_4 ( V_1 ) ;
}
static void F_5 ( void T_2 * V_3 )
{
volatile T_3 V_4 , V_5 ;
asm volatile("msync; isync");
V_5 = F_6 ( V_3 ) ;
F_7 ( V_6 L_2 ) ;
V_4 = V_7 | V_8 ;
if ( F_8 ( L_3 ) ||
F_8 ( L_4 ) )
V_4 |= ( V_5 & V_9 ) >> 2 ;
asm volatile("msync; isync");
F_9 ( V_3 , V_4 ) ;
asm volatile("msync; isync");
}
static void F_10 ( void )
{
struct V_10 * V_11 ;
int V_12 ;
F_11 (np, L_5 ) {
struct V_13 V_14 [ 2 ] ;
void T_2 * V_3 ;
if ( ! F_12 ( V_11 ,
L_6 ) &&
! F_12 ( V_11 ,
L_7 ) &&
! F_12 ( V_11 ,
L_8 ) )
continue;
V_12 = F_13 ( V_11 , 0 , & V_14 [ 0 ] ) ;
if ( V_12 ) {
F_7 ( V_15 L_9
L_10 ,
V_11 -> V_16 ) ;
continue;
}
V_3 = F_14 ( V_14 [ 0 ] . V_17 , F_15 ( & V_14 [ 0 ] ) ) ;
F_5 ( V_3 ) ;
}
}
static void T_1 F_16 ( void )
{
#ifdef F_17
struct V_10 * V_11 ;
#endif
struct V_10 * V_18 ;
const char * V_19 = L_11 ;
V_18 = F_18 ( L_12 ) ;
if ( V_18 == NULL )
return;
V_19 = F_19 ( V_18 , L_13 , NULL ) ;
F_7 ( V_6 L_14 ,
V_19 + strlen ( L_15 ) ) ;
F_10 () ;
#ifdef F_17
F_20 (np, L_16 ) {
if ( F_12 ( V_11 , L_17 ) ||
F_12 ( V_11 , L_18 ) ) {
struct V_13 V_20 ;
F_13 ( V_11 , 0 , & V_20 ) ;
if ( ( V_20 . V_17 & 0xfffff ) == V_21 )
F_21 ( V_11 , 1 ) ;
else
F_21 ( V_11 , 0 ) ;
}
}
#endif
F_22 () ;
}
static int T_1 F_23 ( void )
{
unsigned long V_18 = F_24 () ;
if ( F_25 ( V_18 , L_19 ) ) {
#ifdef F_17
V_21 = 0x8000 ;
#endif
return 1 ;
} else {
return 0 ;
}
}
static int T_1 F_26 ( void )
{
unsigned long V_18 = F_24 () ;
if ( F_25 ( V_18 , L_20 ) ) {
#ifdef F_17
V_21 = 0xb000 ;
#endif
return 1 ;
} else {
return 0 ;
}
}
static int T_1 F_27 ( void )
{
unsigned long V_18 = F_24 () ;
if ( F_25 ( V_18 , L_21 ) ) {
#ifdef F_17
V_21 = 0xb000 ;
#endif
return 1 ;
} else {
return 0 ;
}
}
