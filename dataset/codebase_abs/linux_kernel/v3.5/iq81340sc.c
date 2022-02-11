static int T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
F_2 ( V_3 < 1 || V_3 > 2 ) ;
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
case 2 : return V_6 ;
case 3 : return V_6 ;
case 4 : return V_6 ;
default: return - 1 ;
}
default: return - 1 ;
}
}
static int T_1 F_3 ( void )
{
F_4 ( & V_9 ) ;
F_5 ( & V_9 ) ;
F_6 () ;
return 0 ;
}
static void T_1 F_7 ( void )
{
F_8 () ;
F_3 () ;
F_9 () ;
}
static void T_1 F_10 ( void )
{
unsigned long V_10 = F_11 () / F_12 () ;
F_13 ( V_11 L_1 , V_12 , V_10 ) ;
F_14 ( V_10 ) ;
}
