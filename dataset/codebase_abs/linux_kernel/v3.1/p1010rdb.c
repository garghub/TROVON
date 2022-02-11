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
V_1 = F_6 ( V_5 , V_3 . V_7 , V_8 | V_9 |
V_10 | V_11 | V_12 ,
0 , 256 , L_4 ) ;
F_7 ( V_1 == NULL ) ;
F_5 ( V_5 ) ;
F_8 ( V_1 ) ;
}
static void T_1 F_9 ( void )
{
#ifdef F_10
struct V_4 * V_5 ;
#endif
if ( V_13 . V_14 )
V_13 . V_14 ( L_5 , 0 ) ;
#ifdef F_10
F_11 (np, L_6 ) {
if ( F_12 ( V_5 , L_7 ) )
F_13 ( V_5 , 0 ) ;
}
#endif
F_3 ( V_15 L_8 ) ;
}
static int T_1 F_14 ( void )
{
return F_15 ( NULL , V_16 , NULL ) ;
}
static int T_1 F_16 ( void )
{
unsigned long V_17 = F_17 () ;
if ( F_18 ( V_17 , L_9 ) )
return 1 ;
return 0 ;
}
