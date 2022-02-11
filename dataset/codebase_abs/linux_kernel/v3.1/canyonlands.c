static int T_1 F_1 ( void )
{
F_2 ( NULL , V_1 , NULL ) ;
return 0 ;
}
static int T_1 F_3 ( void )
{
unsigned long V_2 = F_4 () ;
if ( F_5 ( V_2 , L_1 ) ) {
F_6 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int T_1 F_7 ( void )
{
T_2 T_3 * V_4 ;
void T_3 * V_5 ;
struct V_6 * V_7 ;
int V_8 = 0 ;
V_7 = F_8 ( NULL , NULL , L_2 ) ;
if ( ! V_7 ) {
F_9 ( V_9 L_3 ) ;
return - V_10 ;
}
V_4 = F_10 ( V_7 , 0 ) ;
F_11 ( V_7 ) ;
if ( ! V_4 ) {
F_9 ( V_11 L_4 ) ;
V_8 = - V_10 ;
goto V_12;
}
V_7 = F_8 ( NULL , NULL , L_5 ) ;
if ( ! V_7 ) {
F_9 ( V_9 L_6 ) ;
return - V_10 ;
}
V_5 = F_10 ( V_7 , 0 ) ;
F_11 ( V_7 ) ;
if ( ! V_5 ) {
F_9 ( V_11 L_7 ) ;
V_8 = - V_10 ;
goto V_13;
}
F_12 ( & V_4 [ 7 ] , V_14 ) ;
F_13 ( 100 ) ;
F_14 ( & V_4 [ 7 ] , V_14 ) ;
F_15 ( ( V_5 + V_15 ) , 0x42000000 ) ;
F_15 ( ( V_5 + V_16 ) , 0x42000000 ) ;
V_13:
F_16 ( V_5 ) ;
V_12:
F_16 ( V_4 ) ;
return V_8 ;
}
