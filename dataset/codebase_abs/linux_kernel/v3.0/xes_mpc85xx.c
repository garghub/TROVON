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
V_12 = F_16 ( V_3 [ 0 ] . V_7 , V_3 [ 0 ] . V_22 - V_3 [ 0 ] . V_7 + 1 ) ;
F_9 ( V_12 ) ;
}
}
static void T_1 F_17 ( void )
{
#ifdef F_18
struct V_4 * V_5 ;
#endif
struct V_4 * V_23 ;
const char * V_24 = L_14 ;
V_23 = F_19 ( L_15 ) ;
if ( V_23 == NULL )
return;
V_24 = F_20 ( V_23 , L_16 , NULL ) ;
F_3 ( V_15 L_17 ,
V_24 + strlen ( L_18 ) ) ;
F_13 () ;
#ifdef F_18
F_21 (np, L_19 ) {
if ( F_15 ( V_5 , L_20 ) ||
F_15 ( V_5 , L_21 ) ) {
struct V_2 V_25 ;
F_4 ( V_5 , 0 , & V_25 ) ;
if ( ( V_25 . V_7 & 0xfffff ) == V_26 )
F_22 ( V_5 , 1 ) ;
else
F_22 ( V_5 , 0 ) ;
}
}
#endif
#ifdef F_23
F_24 () ;
#endif
}
static int T_1 F_25 ( void )
{
return F_26 ( NULL , V_27 , NULL ) ;
}
static int T_1 F_27 ( void )
{
unsigned long V_23 = F_28 () ;
if ( F_29 ( V_23 , L_22 ) ) {
#ifdef F_18
V_26 = 0x8000 ;
#endif
return 1 ;
} else {
return 0 ;
}
}
static int T_1 F_30 ( void )
{
unsigned long V_23 = F_28 () ;
if ( F_29 ( V_23 , L_23 ) ) {
#ifdef F_18
V_26 = 0xb000 ;
#endif
return 1 ;
} else {
return 0 ;
}
}
static int T_1 F_31 ( void )
{
unsigned long V_23 = F_28 () ;
if ( F_29 ( V_23 , L_24 ) ) {
#ifdef F_18
V_26 = 0xb000 ;
#endif
return 1 ;
} else {
return 0 ;
}
}
