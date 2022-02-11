static int T_1 F_1 ( void )
{
const struct V_1 * V_2 ;
const struct V_3 * V_4 ;
struct V_5 * V_6 ;
void T_2 * V_7 ;
int error = 0 ;
V_6 = F_2 ( NULL , V_8 , & V_2 ) ;
if ( ! V_6 )
return - V_9 ;
V_7 = F_3 ( V_6 , 0 ) ;
if ( ! V_7 ) {
F_4 ( L_1 , V_6 -> V_10 ) ;
error = - V_11 ;
goto V_12;
}
V_13 = V_7 ;
V_4 = V_2 -> V_14 ;
V_15 = F_5 ( V_7 + V_4 -> V_16 ) ;
F_6 ( L_2 , V_6 -> V_10 , V_15 ) ;
V_12:
F_7 ( V_6 ) ;
return error ;
}
int T_1 F_8 ( T_3 * V_17 )
{
int error ;
if ( ! V_13 ) {
error = F_1 () ;
if ( error )
return error ;
}
* V_17 = V_15 ;
return 0 ;
}
