static int T_1 F_1 ( void )
{
T_2 V_1 = 0 ;
if ( ! V_2 )
return - 1 ;
V_1 = F_2 ( V_2 + V_3 ) ;
if ( V_4 ) {
F_3 ( L_1 ) ;
F_4 ( V_1 | V_5 ,
V_2 + V_3 ) ;
} else if ( V_1 & V_5 ) {
F_3 ( L_2 ) ;
F_4 ( V_1 & ~ V_5 ,
V_2 + V_3 ) ;
} else {
F_3 ( L_3 ) ;
}
return 0 ;
}
static int T_1 F_5 ( void )
{
struct V_6 * V_7 ;
int V_8 = 0 ;
V_7 = F_6 ( NULL , NULL , L_4 ) ;
if ( ! V_7 ) {
F_7 ( L_5 ) ;
return - V_9 ;
}
V_2 = F_8 ( V_7 , 0 ) ;
if ( ! V_2 ) {
F_7 ( L_6 ) ;
V_8 = - V_10 ;
goto V_11;
}
V_4 = F_9 ( V_7 , L_7 ) ;
V_11:
F_10 ( V_7 ) ;
return V_8 ;
}
static int F_11 ( void )
{
if ( V_2 )
V_12 =
F_2 ( V_2 + V_3 ) ;
return 0 ;
}
static void F_12 ( void )
{
if ( V_2 )
F_4 ( V_12 ,
V_2 + V_3 ) ;
}
void T_1 F_13 ( void )
{
int V_8 ;
F_5 () ;
V_8 = F_1 () ;
if ( V_8 ) {
F_7 ( L_8 ) ;
return;
}
#ifdef F_14
F_15 ( & V_13 ) ;
#endif
}
