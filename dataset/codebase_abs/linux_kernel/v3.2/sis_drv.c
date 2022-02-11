static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_1 * V_4 ;
int V_5 ;
V_4 = F_2 ( sizeof( T_1 ) , V_6 ) ;
if ( V_4 == NULL )
return - V_7 ;
V_2 -> V_8 = ( void * ) V_4 ;
V_4 -> V_3 = V_3 ;
V_5 = F_3 ( & V_4 -> V_9 , 2 , 12 , 8 ) ;
if ( V_5 )
F_4 ( V_4 ) ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 * V_4 = V_2 -> V_8 ;
F_6 ( & V_4 -> V_9 ) ;
F_4 ( V_4 ) ;
return 0 ;
}
static int T_2 F_7 ( void )
{
V_10 . V_11 = V_12 ;
return F_8 ( & V_10 , & V_13 ) ;
}
static void T_3 F_9 ( void )
{
F_10 ( & V_10 , & V_13 ) ;
}
