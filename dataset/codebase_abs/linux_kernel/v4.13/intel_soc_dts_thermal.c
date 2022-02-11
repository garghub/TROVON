static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( L_1 ) ;
F_3 ( V_3 ) ;
return V_4 ;
}
static int T_2 F_4 ( void )
{
int V_5 = 0 ;
const struct V_6 * V_7 ;
V_7 = F_5 ( V_8 ) ;
if ( ! V_7 )
return - V_9 ;
V_3 = F_6 ( V_10 , 2 , 1 ) ;
if ( F_7 ( V_3 ) ) {
V_5 = F_8 ( V_3 ) ;
return V_5 ;
}
V_11 = ( int ) V_7 -> V_12 ;
if ( V_11 ) {
V_5 = F_9 ( V_11 , NULL ,
F_1 ,
V_13 | V_14 ,
L_2 , V_3 ) ;
if ( V_5 ) {
F_10 ( L_3 , V_5 ) ;
}
}
V_5 = F_11 ( V_3 ,
V_15 ) ;
if ( V_5 )
goto V_16;
return 0 ;
V_16:
if ( V_11 )
F_12 ( V_11 , V_3 ) ;
F_13 ( V_3 ) ;
return V_5 ;
}
static void T_3 F_14 ( void )
{
if ( V_11 )
F_12 ( V_11 , V_3 ) ;
F_13 ( V_3 ) ;
}
