static int F_1 ( void )
{
struct V_1 * V_2 ;
void T_1 * V_3 = NULL ;
T_2 V_4 ;
F_2 () ;
V_2 = F_3 ( NULL , L_1 ) ;
if ( V_2 ) {
struct V_5 V_6 ;
F_4 ( V_2 , 0 , & V_6 ) ;
V_3 = F_5 ( V_6 . V_7 , F_6 ( & V_6 ) ) ;
F_7 ( V_2 ) ;
}
if ( ! V_3 )
return - 1 ;
V_4 = F_8 ( V_3 + 5 ) ;
if ( ! ( V_4 & V_8 ) )
F_9 ( V_3 + 5 , ( V_4 | V_8 ) ) ;
F_10 ( V_3 ) ;
return 0 ;
}
static void T_3 F_11 ( void )
{
#ifdef F_12
struct V_1 * V_2 ;
#endif
if ( V_9 . V_10 )
V_9 . V_10 ( L_2 , 0 ) ;
#ifdef F_12
F_13 (np, L_3 , L_4 )
F_14 ( V_2 ) ;
#endif
F_1 () ;
}
static void T_3 F_15 ( void )
{
struct V_1 * V_2 ;
V_2 = F_16 ( NULL , L_5 ) ;
if ( ! V_2 )
return;
F_17 ( V_2 , 0 ) ;
F_18 () ;
}
static int T_3 F_19 ( void )
{
F_20 ( NULL , V_11 , NULL ) ;
return 0 ;
}
static int T_3 F_21 ( void )
{
unsigned long V_12 = F_22 () ;
return F_23 ( V_12 , L_6 ) ;
}
