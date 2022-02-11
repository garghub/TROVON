static void T_1 F_1 ( void )
{
struct V_1 * V_1 ;
struct V_2 V_3 ;
struct V_4 * V_5 ;
V_5 = F_2 ( NULL , L_1 ) ;
if ( ! V_5 ) {
F_3 ( V_6 L_2 ) ;
return;
}
if ( F_4 ( V_5 , 0 , & V_3 ) ) {
F_3 ( V_6 L_3 ) ;
F_5 ( V_5 ) ;
return;
}
V_1 = F_6 ( V_5 , V_3 . V_7 ,
V_8 | V_9 | V_10 ,
0 , 256 , L_4 ) ;
F_7 ( V_1 == NULL ) ;
F_5 ( V_5 ) ;
F_8 ( V_1 ) ;
V_5 = F_9 ( NULL , NULL , L_5 ) ;
if ( ! V_5 ) {
F_3 ( V_6 L_6 ) ;
return;
}
F_10 ( V_5 ) ;
F_5 ( V_5 ) ;
}
static void T_1 F_11 ( void )
{
#ifdef F_12
struct V_4 * V_5 ;
#endif
if ( V_11 . V_12 )
V_11 . V_12 ( L_7 , 0 ) ;
#ifdef F_12
F_13 (np, L_8 , L_9 )
F_14 ( V_5 , 1 ) ;
#endif
}
static int T_1 F_15 ( void )
{
return F_16 ( NULL , V_13 , NULL ) ;
}
static int T_1 F_17 ( void )
{
unsigned long V_14 = F_18 () ;
if ( F_19 ( V_14 , L_10 ) )
return 1 ;
return 0 ;
}
