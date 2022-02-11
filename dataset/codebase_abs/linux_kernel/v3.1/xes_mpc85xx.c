void T_1 F_1 ( void )
{
struct V_1 * V_1 ;
struct V_2 V_3 ;
struct V_4 * V_5 ;
V_5 = F_2 ( NULL , L_1 ) ;
if ( V_5 == NULL ) {
F_3 ( V_6 L_2 ) ;
return;
}
if ( F_4 ( V_5 , 0 , & V_3 ) ) {
F_3 ( V_6 L_3 ) ;
F_5 ( V_5 ) ;
return;
}
V_1 = F_6 ( V_5 , V_3 . V_7 ,
V_8 | V_9 |
V_10 | V_11 ,
0 , 256 , L_4 ) ;
F_7 ( V_1 == NULL ) ;
F_5 ( V_5 ) ;
F_8 ( V_1 ) ;
}
static void F_9 ( void T_2 * V_12 )
{
volatile T_3 V_13 , V_14 ;
asm volatile("msync; isync");
V_14 = F_10 ( V_12 ) ;
F_3 ( V_15 L_5 ) ;
V_13 = V_16 | V_17 ;
if ( F_11 ( L_6 ) ||
F_11 ( L_7 ) )
V_13 |= ( V_14 & V_18 ) >> 2 ;
asm volatile("msync; isync");
F_12 ( V_12 , V_13 ) ;
asm volatile("msync; isync");
}
static void F_13 ( void )
{
struct V_4 * V_5 ;
int V_19 ;
F_14 (np, L_8 ) {
struct V_2 V_3 [ 2 ] ;
void T_2 * V_12 ;
if ( ! F_15 ( V_5 ,
L_9 ) &&
! F_15 ( V_5 ,
L_10 ) &&
! F_15 ( V_5 ,
L_11 ) )
continue;
V_19 = F_4 ( V_5 , 0 , & V_3 [ 0 ] ) ;
if ( V_19 ) {
F_3 ( V_20 L_12
L_13 ,
V_5 -> V_21 ) ;
continue;
}
V_12 = F_16 ( V_3 [ 0 ] . V_7 , F_17 ( & V_3 [ 0 ] ) ) ;
F_9 ( V_12 ) ;
}
}
static void T_1 F_18 ( void )
{
#ifdef F_19
struct V_4 * V_5 ;
#endif
struct V_4 * V_22 ;
const char * V_23 = L_14 ;
V_22 = F_20 ( L_15 ) ;
if ( V_22 == NULL )
return;
V_23 = F_21 ( V_22 , L_16 , NULL ) ;
F_3 ( V_15 L_17 ,
V_23 + strlen ( L_18 ) ) ;
F_13 () ;
#ifdef F_19
F_22 (np, L_19 ) {
if ( F_15 ( V_5 , L_20 ) ||
F_15 ( V_5 , L_21 ) ) {
struct V_2 V_24 ;
F_4 ( V_5 , 0 , & V_24 ) ;
if ( ( V_24 . V_7 & 0xfffff ) == V_25 )
F_23 ( V_5 , 1 ) ;
else
F_23 ( V_5 , 0 ) ;
}
}
#endif
#ifdef F_24
F_25 () ;
#endif
}
static int T_1 F_26 ( void )
{
return F_27 ( NULL , V_26 , NULL ) ;
}
static int T_1 F_28 ( void )
{
unsigned long V_22 = F_29 () ;
if ( F_30 ( V_22 , L_22 ) ) {
#ifdef F_19
V_25 = 0x8000 ;
#endif
return 1 ;
} else {
return 0 ;
}
}
static int T_1 F_31 ( void )
{
unsigned long V_22 = F_29 () ;
if ( F_30 ( V_22 , L_23 ) ) {
#ifdef F_19
V_25 = 0xb000 ;
#endif
return 1 ;
} else {
return 0 ;
}
}
static int T_1 F_32 ( void )
{
unsigned long V_22 = F_29 () ;
if ( F_30 ( V_22 , L_24 ) ) {
#ifdef F_19
V_25 = 0xb000 ;
#endif
return 1 ;
} else {
return 0 ;
}
}
