int F_1 ( unsigned int V_1 ,
const struct V_2 * * V_3 )
{
if ( ! V_4 )
return - V_5 ;
if ( V_1 != V_6 )
return - V_7 ;
* V_3 = & V_8 ;
return 0 ;
}
void F_2 ( void )
{
}
static int T_1 F_3 ( void )
{
int V_9 ;
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
return V_9 ;
V_9 = F_6 () ;
if ( V_9 < 0 )
goto V_15;
V_9 = F_7 () ;
if ( V_9 < 0 )
goto V_16;
F_8 () ;
V_4 = 1 ;
F_9 ( V_17 , L_3 ) ;
return 0 ;
V_16:
F_10 () ;
V_15:
F_11 () ;
return V_9 ;
}
static void T_2 F_12 ( void )
{
V_4 = 0 ;
F_13 () ;
F_14 () ;
F_10 () ;
F_11 () ;
F_9 ( V_17 , L_4 ) ;
}
