static void T_1 F_1 ( void )
{
int V_1 ;
struct V_2 * V_3 ;
F_2 (cpu_id) {
V_3 = F_3 ( V_4 , V_1 ) ;
F_4 ( V_3 ) ;
}
F_5 ( V_4 ) ;
}
int T_1 F_6 ( struct V_5 * V_6 )
{
struct V_2 * V_3 ;
int V_1 , V_7 ;
if ( V_6 -> V_8 > V_9 ) {
F_7 ( L_1 , V_10 ) ;
return - V_11 ;
}
V_7 = F_8 ( V_6 ) ;
if ( V_7 ) {
F_7 ( L_2 ,
V_10 , V_7 ) ;
return V_7 ;
}
V_4 = F_9 ( struct V_2 ) ;
if ( V_4 == NULL ) {
V_7 = - V_12 ;
goto V_13;
}
F_2 (cpu_id) {
V_3 = F_3 ( V_4 , V_1 ) ;
V_3 -> V_14 = V_1 ;
V_3 -> V_8 = V_6 -> V_8 ;
V_7 = F_10 ( V_3 ) ;
if ( V_7 ) {
F_7 ( L_3 ,
V_10 , V_1 , V_7 ) ;
goto V_15;
}
}
return 0 ;
V_15:
F_1 () ;
V_13:
F_11 ( V_6 ) ;
return V_7 ;
}
