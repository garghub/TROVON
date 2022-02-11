static int T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
switch ( V_3 ) {
case 1 :
switch ( V_4 ) {
case 1 : return V_5 ;
case 2 : return V_6 ;
case 3 : return V_7 ;
case 4 : return V_8 ;
default: return - 1 ;
}
case 2 :
switch ( V_4 ) {
case 1 : return V_6 ;
case 2 : return V_7 ;
case 3 : return V_6 ;
case 4 : return V_7 ;
default: return - 1 ;
}
default: return - 1 ;
}
}
static int T_1 F_2 ( void )
{
F_3 ( & V_9 ) ;
F_4 ( & V_9 ) ;
F_5 () ;
return 0 ;
}
static void T_1 F_6 ( void )
{
F_7 () ;
F_2 () ;
F_8 () ;
}
static void T_1 F_9 ( void )
{
unsigned long V_10 = F_10 () / F_11 () ;
F_12 ( V_11 L_1 , V_12 , V_10 ) ;
F_13 ( V_10 ) ;
}
