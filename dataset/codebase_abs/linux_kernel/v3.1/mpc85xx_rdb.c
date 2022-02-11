void T_1 F_1 ( void )
{
struct V_1 * V_1 ;
struct V_2 V_3 ;
struct V_4 * V_5 ;
unsigned long V_6 = F_2 () ;
V_5 = F_3 ( NULL , L_1 ) ;
if ( V_5 == NULL ) {
F_4 ( V_7 L_2 ) ;
return;
}
if ( F_5 ( V_5 , 0 , & V_3 ) ) {
F_4 ( V_7 L_3 ) ;
F_6 ( V_5 ) ;
return;
}
if ( F_7 ( V_6 , L_4 ) ) {
V_1 = F_8 ( V_5 , V_3 . V_8 ,
V_9 |
V_10 | V_11 |
V_12 ,
0 , 256 , L_5 ) ;
} else {
V_1 = F_8 ( V_5 , V_3 . V_8 ,
V_9 | V_13 |
V_10 | V_11 |
V_12 ,
0 , 256 , L_5 ) ;
}
F_9 ( V_1 == NULL ) ;
F_6 ( V_5 ) ;
F_10 ( V_1 ) ;
}
static void T_1 F_11 ( void )
{
#ifdef F_12
struct V_4 * V_5 ;
#endif
if ( V_14 . V_15 )
V_14 . V_15 ( L_6 , 0 ) ;
#ifdef F_12
F_13 (np, L_7 ) {
if ( F_14 ( V_5 , L_8 ) )
F_15 ( V_5 , 0 ) ;
}
#endif
#ifdef F_16
F_17 () ;
#endif
F_4 ( V_16 L_9 ) ;
}
static int T_1 F_18 ( void )
{
return F_19 ( NULL , V_17 , NULL ) ;
}
static int T_1 F_20 ( void )
{
unsigned long V_6 = F_2 () ;
if ( F_7 ( V_6 , L_10 ) )
return 1 ;
return 0 ;
}
static int T_1 F_21 ( void )
{
unsigned long V_6 = F_2 () ;
if ( F_7 ( V_6 , L_11 ) )
return 1 ;
return 0 ;
}
