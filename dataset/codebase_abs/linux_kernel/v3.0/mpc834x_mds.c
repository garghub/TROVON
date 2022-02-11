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
V_3 = F_5 ( V_6 . V_7 , V_6 . V_8 - V_6 . V_7 + 1 ) ;
F_6 ( V_2 ) ;
}
if ( ! V_3 )
return - 1 ;
V_4 = F_7 ( V_3 + 5 ) ;
if ( ! ( V_4 & V_9 ) )
F_8 ( V_3 + 5 , ( V_4 | V_9 ) ) ;
F_9 ( V_3 ) ;
return 0 ;
}
static void T_3 F_10 ( void )
{
#ifdef F_11
struct V_1 * V_2 ;
#endif
if ( V_10 . V_11 )
V_10 . V_11 ( L_2 , 0 ) ;
#ifdef F_11
F_12 (np, L_3 , L_4 )
F_13 ( V_2 ) ;
#endif
F_1 () ;
}
static void T_3 F_14 ( void )
{
struct V_1 * V_2 ;
V_2 = F_15 ( NULL , L_5 ) ;
if ( ! V_2 )
return;
F_16 ( V_2 , 0 ) ;
F_17 () ;
}
static int T_3 F_18 ( void )
{
F_19 ( NULL , V_12 , NULL ) ;
return 0 ;
}
static int T_3 F_20 ( void )
{
unsigned long V_13 = F_21 () ;
return F_22 ( V_13 , L_6 ) ;
}
