static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
void T_2 * V_4 = ( void T_2 * ) V_2 -> V_5 ;
* V_3 = F_2 ( V_4 ) ;
return 4 ;
}
static int T_3 F_3 ( void )
{
void T_2 * V_4 ;
int V_6 ;
V_4 = F_4 ( 0x70002100 , 4 ) ;
if ( ! V_4 )
return - V_7 ;
V_8 . V_5 = ( unsigned long ) V_4 ;
V_6 = F_5 ( & V_8 ) ;
if ( V_6 )
F_6 ( V_4 ) ;
return V_6 ;
}
static void T_4 F_7 ( void )
{
void T_2 * V_4 = ( void T_2 * ) V_8 . V_5 ;
F_8 ( & V_8 ) ;
F_6 ( V_4 ) ;
}
