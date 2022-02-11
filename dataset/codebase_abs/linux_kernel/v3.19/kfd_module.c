bool F_1 ( unsigned V_1 ,
const struct V_2 * V_3 ,
const struct V_4 * * V_5 )
{
if ( V_1 != V_6 )
return false ;
if ( V_7 )
return true ;
V_7 = V_3 ;
* V_5 = & V_8 ;
return true ;
}
void F_2 ( void )
{
}
static int T_1 F_3 ( void )
{
int V_9 ;
V_7 = NULL ;
if ( ( V_10 < V_11 ) ||
( V_10 > V_12 ) ) {
F_4 ( L_1 ) ;
return - 1 ;
}
if ( ( V_13 < 1 ) ||
( V_13 >
V_14 ) ) {
F_4 ( L_2 ) ;
return - 1 ;
}
V_9 = F_5 () ;
if ( V_9 < 0 )
goto V_15;
V_9 = F_6 () ;
if ( V_9 < 0 )
goto V_16;
V_9 = F_7 () ;
if ( V_9 < 0 )
goto V_17;
F_8 () ;
F_9 ( V_18 , L_3 ) ;
return 0 ;
V_17:
F_10 () ;
V_16:
F_11 () ;
V_15:
return V_9 ;
}
static void T_2 F_12 ( void )
{
F_13 () ;
F_14 () ;
F_10 () ;
F_11 () ;
F_9 ( V_18 , L_4 ) ;
}
