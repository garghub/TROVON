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
static void T_1 F_9 ( void )
{
#ifdef F_10
struct V_4 * V_5 ;
struct V_12 * V_13 ;
#endif
T_2 V_14 = 0xffffffff ;
if ( V_15 . V_16 )
V_15 . V_16 ( L_5 , 0 ) ;
#ifdef F_10
F_11 (np, L_6 ) {
if ( F_12 ( V_5 , L_7 ) ||
F_12 ( V_5 , L_8 ) ) {
struct V_2 V_17 ;
F_4 ( V_5 , 0 , & V_17 ) ;
if ( ( V_17 . V_7 & 0xfffff ) == 0x8000 )
F_13 ( V_5 , 1 ) ;
else
F_13 ( V_5 , 0 ) ;
V_13 = F_14 ( V_5 ) ;
V_14 = F_15 ( V_14 , V_13 -> V_18 +
V_13 -> V_19 ) ;
}
}
#endif
#ifdef F_16
if ( F_17 () > V_14 ) {
V_20 = 1 ;
F_18 ( & V_21 ) ;
V_15 . V_22 = V_23 ;
}
#endif
F_3 ( L_9 ) ;
}
static int T_1 F_19 ( void )
{
return F_20 ( NULL , V_24 , NULL ) ;
}
static int T_1 F_21 ( void )
{
unsigned long V_25 = F_22 () ;
return F_23 ( V_25 , L_10 ) ;
}
