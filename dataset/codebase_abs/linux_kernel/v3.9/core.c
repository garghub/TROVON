static void F_1 ( char V_1 , const char * V_2 )
{
short V_3 ;
F_2 ( 0x09 , 0x24 ) ;
V_3 = F_3 ( 0x26 ) ;
V_3 = V_3 | ( 1 << 3 ) | ( 1 << 10 ) ;
F_2 ( 0x09 , 0x24 ) ;
F_2 ( V_3 , 0x26 ) ;
}
static int T_1 F_4 ( void )
{
int V_4 ;
if ( F_5 () )
{
V_4 = F_6 ( & V_5 ) ;
if ( V_4 ) F_7 ( V_6 L_1 , V_4 ) ;
V_4 = F_6 ( & V_7 ) ;
if ( V_4 ) F_7 ( V_6 L_2 , V_4 ) ;
}
return 0 ;
}
static T_2
F_8 ( int V_8 , void * V_9 )
{
F_9 () ;
return V_10 ;
}
static void T_1 F_10 ( void )
{
F_11 ( 0x34 , 0x43 ) ;
F_11 ( V_11 & 0xff , 0x40 ) ;
F_11 ( V_11 >> 8 , 0x40 ) ;
F_12 ( V_12 , & V_13 ) ;
}
static void F_13 ( void )
{
F_14 () ;
}
