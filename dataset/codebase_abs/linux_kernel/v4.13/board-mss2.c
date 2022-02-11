static int T_1 F_1 ( const struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_5 != - 1 )
return V_5 ;
return - 1 ;
}
static int T_1 F_3 ( void )
{
if ( F_4 () )
F_5 ( & V_6 ) ;
return 0 ;
}
static void F_6 ( void )
{
T_3 V_7 ;
V_7 = F_7 ( V_8 ) ;
V_7 |= 1 << 2 ;
F_8 ( V_7 , V_8 ) ;
V_7 = F_7 ( V_9 ) ;
V_7 |= 1 ;
F_8 ( V_7 , V_9 ) ;
}
void T_1 F_9 ( void )
{
V_10 = F_6 ;
}
