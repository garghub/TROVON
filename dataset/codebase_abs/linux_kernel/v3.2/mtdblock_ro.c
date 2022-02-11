static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , char * V_4 )
{
T_1 V_5 ;
if ( V_2 -> V_6 -> V_7 ( V_2 -> V_6 , ( V_3 * 512 ) , 512 , & V_5 , V_4 ) )
return 1 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
unsigned long V_3 , char * V_4 )
{
T_1 V_5 ;
if ( V_2 -> V_6 -> V_8 ( V_2 -> V_6 , ( V_3 * 512 ) , 512 , & V_5 , V_4 ) )
return 1 ;
return 0 ;
}
static void F_3 ( struct V_9 * V_10 , struct V_11 * V_6 )
{
struct V_1 * V_2 = F_4 ( sizeof( * V_2 ) , V_12 ) ;
if ( ! V_2 )
return;
V_2 -> V_6 = V_6 ;
V_2 -> V_13 = V_6 -> V_14 ;
V_2 -> V_15 = V_6 -> V_15 >> 9 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_16 = 1 ;
if ( F_5 ( V_2 ) )
F_6 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
}
static int T_2 F_9 ( void )
{
return F_10 ( & V_17 ) ;
}
static void T_3 F_11 ( void )
{
F_12 ( & V_17 ) ;
}
