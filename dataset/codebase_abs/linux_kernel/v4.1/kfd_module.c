bool F_1 ( unsigned V_1 , const struct V_2 * * V_3 )
{
if ( V_1 != V_4 )
return false ;
* V_3 = & V_5 ;
return true ;
}
void F_2 ( void )
{
}
static int T_1 F_3 ( void )
{
int V_6 ;
if ( ( V_7 < V_8 ) ||
( V_7 > V_9 ) ) {
F_4 ( L_1 ) ;
return - 1 ;
}
if ( ( V_10 < 1 ) ||
( V_10 >
V_11 ) ) {
F_4 ( L_2 ) ;
return - 1 ;
}
V_6 = F_5 () ;
if ( V_6 < 0 )
goto V_12;
V_6 = F_6 () ;
if ( V_6 < 0 )
goto V_13;
V_6 = F_7 () ;
if ( V_6 < 0 )
goto V_14;
F_8 () ;
F_9 ( V_15 , L_3 ) ;
return 0 ;
V_14:
F_10 () ;
V_13:
F_11 () ;
V_12:
return V_6 ;
}
static void T_2 F_12 ( void )
{
F_13 () ;
F_14 () ;
F_10 () ;
F_11 () ;
F_9 ( V_15 , L_4 ) ;
}
