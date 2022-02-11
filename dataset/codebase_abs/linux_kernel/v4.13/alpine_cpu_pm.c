int F_1 ( unsigned int V_1 , T_1 V_2 )
{
if ( ! V_3 )
return - V_4 ;
F_2 ( V_2 ,
& V_5 -> V_6 [ V_1 ] . V_7 ) ;
F_3 ( V_8 , F_4 ( V_1 ) , 0 ) ;
return 0 ;
}
void T_2 F_5 ( void )
{
struct V_9 * V_10 ;
T_1 V_11 ;
V_8 = F_6 ( L_1 ) ;
V_10 = F_7 ( NULL , NULL , L_2 ) ;
V_5 = F_8 ( V_10 , 0 ) ;
V_3 = ! F_9 ( V_8 ) && V_5 ;
if ( V_3 ) {
V_11 = F_10 ( & V_5 -> V_11 ) ;
V_3 = ( V_11 & V_12 )
== V_13 ;
}
}
