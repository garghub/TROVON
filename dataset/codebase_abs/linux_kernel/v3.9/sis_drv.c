static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_1 * V_4 ;
F_2 ( V_2 -> V_5 ) ;
V_4 = F_3 ( sizeof( T_1 ) , V_6 ) ;
if ( V_4 == NULL )
return - V_7 ;
F_4 ( & V_4 -> V_8 ) ;
V_2 -> V_9 = ( void * ) V_4 ;
V_4 -> V_3 = V_3 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 * V_4 = V_2 -> V_9 ;
F_6 ( & V_4 -> V_8 ) ;
F_7 ( V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 ;
F_9 ( L_1 ) ;
V_13 = F_10 ( sizeof( * V_13 ) , V_6 ) ;
if ( ! V_13 )
return - V_7 ;
V_11 -> V_14 = V_13 ;
F_11 ( & V_13 -> V_15 ) ;
return 0 ;
}
void F_12 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
F_7 ( V_13 ) ;
}
static int T_2 F_13 ( void )
{
V_16 . V_17 = V_18 ;
return F_14 ( & V_16 , & V_19 ) ;
}
static void T_3 F_15 ( void )
{
F_16 ( & V_16 , & V_19 ) ;
}
