static int T_1 F_1 ( void )
{
F_2 ( NULL , V_1 , NULL ) ;
return 0 ;
}
static int T_1 F_3 ( void )
{
if ( F_4 ( L_1 ) ) {
F_5 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static int T_1 F_6 ( void )
{
T_2 T_3 * V_3 ;
void T_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 = 0 ;
V_6 = F_7 ( NULL , NULL , L_2 ) ;
if ( ! V_6 ) {
F_8 ( V_8 L_3 ) ;
return - V_9 ;
}
V_3 = F_9 ( V_6 , 0 ) ;
F_10 ( V_6 ) ;
if ( ! V_3 ) {
F_8 ( V_10 L_4 ) ;
V_7 = - V_9 ;
goto V_11;
}
V_6 = F_7 ( NULL , NULL , L_5 ) ;
if ( ! V_6 ) {
F_8 ( V_8 L_6 ) ;
return - V_9 ;
}
V_4 = F_9 ( V_6 , 0 ) ;
F_10 ( V_6 ) ;
if ( ! V_4 ) {
F_8 ( V_10 L_7 ) ;
V_7 = - V_9 ;
goto V_12;
}
F_11 ( & V_3 [ 7 ] , V_13 ) ;
F_12 ( 100 ) ;
F_13 ( & V_3 [ 7 ] , V_13 ) ;
F_14 ( ( V_4 + V_14 ) , 0x42000000 ) ;
F_14 ( ( V_4 + V_15 ) , 0x42000000 ) ;
V_12:
F_15 ( V_4 ) ;
V_11:
F_15 ( V_3 ) ;
return V_7 ;
}
