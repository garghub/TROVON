void T_1 F_1 ( void )
{
struct V_1 * V_1 ;
unsigned long V_2 = F_2 () ;
if ( F_3 ( V_2 , L_1 ) ) {
V_1 = F_4 ( NULL , 0 ,
V_3 | V_4 |
V_5 ,
0 , 256 , L_2 ) ;
} else {
V_1 = F_4 ( NULL , 0 ,
V_6 |
V_3 | V_4 |
V_5 ,
0 , 256 , L_2 ) ;
}
F_5 ( V_1 == NULL ) ;
F_6 ( V_1 ) ;
}
static void T_1 F_7 ( void )
{
#ifdef F_8
struct V_7 * V_8 ;
#endif
if ( V_9 . V_10 )
V_9 . V_10 ( L_3 , 0 ) ;
#ifdef F_8
F_9 (np, L_4 ) {
if ( F_10 ( V_8 , L_5 ) )
F_11 ( V_8 , 0 ) ;
}
#endif
F_12 () ;
F_13 ( V_11 L_6 ) ;
}
static int T_1 F_14 ( void )
{
unsigned long V_2 = F_2 () ;
if ( F_3 ( V_2 , L_7 ) )
return 1 ;
return 0 ;
}
static int T_1 F_15 ( void )
{
unsigned long V_2 = F_2 () ;
if ( F_3 ( V_2 , L_8 ) )
return 1 ;
return 0 ;
}
