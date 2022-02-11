static void F_1 ( void )
{
F_2 ( V_1 , V_2 ) ;
F_3 ( 850 ) ;
F_2 ( V_3 , V_2 ) ;
}
static int F_4 ( void )
{
unsigned char V_4 ;
if ( V_5 != 1 ) {
F_5 ( V_6 L_1 ) ;
return - V_7 ;
}
V_4 = F_6 ( V_8 ) ;
if ( V_4 == V_9 ) {
F_5 ( V_6 L_2 ) ;
return - V_7 ;
}
V_10 = V_11 ;
V_11 = & F_1 ;
F_5 ( V_12 L_3 ) ;
return 0 ;
}
static void F_7 ( void )
{
V_11 = V_10 ;
F_5 ( V_12 L_4 ) ;
}
