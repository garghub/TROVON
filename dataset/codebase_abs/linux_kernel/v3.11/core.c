static void F_1 ( enum V_1 V_2 , const char * V_3 )
{
short V_4 ;
F_2 ( 0x09 , 0x24 ) ;
V_4 = F_3 ( 0x26 ) ;
V_4 = V_4 | ( 1 << 3 ) | ( 1 << 10 ) ;
F_2 ( 0x09 , 0x24 ) ;
F_2 ( V_4 , 0x26 ) ;
}
static int T_1 F_4 ( void )
{
int V_5 ;
if ( F_5 () )
{
V_5 = F_6 ( & V_6 ) ;
if ( V_5 ) F_7 ( V_7 L_1 , V_5 ) ;
V_5 = F_6 ( & V_8 ) ;
if ( V_5 ) F_7 ( V_7 L_2 , V_5 ) ;
}
return 0 ;
}
static T_2
F_8 ( int V_9 , void * V_10 )
{
F_9 () ;
return V_11 ;
}
static void T_1 F_10 ( void )
{
F_11 ( 0x34 , 0x43 ) ;
F_11 ( V_12 & 0xff , 0x40 ) ;
F_11 ( V_12 >> 8 , 0x40 ) ;
F_12 ( V_13 , & V_14 ) ;
}
static void F_13 ( void )
{
F_14 ( true ) ;
}
