void T_1 F_1 ( void )
{
F_2 () ;
}
static int T_1 F_3 ( void )
{
if ( F_4 () ) {
F_5 ( V_1 ) ;
F_6 ( V_2 ) ;
F_7 ( V_3 + 0x50000 ,
V_4 + 0x82800 ,
V_3 + 0x15000 ) ;
}
return 0 ;
}
void T_1 F_8 ( void )
{
F_9 ( V_5 | V_6 , V_7 ) ;
F_9 ( V_8 , V_7 ) ;
F_10 ( V_9 ) ;
}
void F_11 ( void )
{
T_2 V_10 ;
T_2 V_11 = V_12 ;
V_10 = F_12 ( V_13 ) ;
F_9 ( V_10 | V_11 , V_13 ) ;
}
int T_1 F_13 ( struct V_14 * V_15 )
{
V_16 . V_17 . V_18 = V_15 ;
return F_14 ( & V_16 ) ;
}
void F_15 ( enum V_19 V_20 , const char * V_21 )
{
F_16 ( 0xffff0000 ) ;
}
