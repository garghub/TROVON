static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , char * V_4 )
{
T_1 V_5 ;
if ( F_2 ( V_2 -> V_6 , ( V_3 * 512 ) , 512 , & V_5 , V_4 ) )
return 1 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned long V_3 , char * V_4 )
{
T_1 V_5 ;
if ( F_4 ( V_2 -> V_6 , ( V_3 * 512 ) , 512 , & V_5 , V_4 ) )
return 1 ;
return 0 ;
}
static void F_5 ( struct V_7 * V_8 , struct V_9 * V_6 )
{
struct V_1 * V_2 = F_6 ( sizeof( * V_2 ) , V_10 ) ;
if ( ! V_2 )
return;
V_2 -> V_6 = V_6 ;
V_2 -> V_11 = V_6 -> V_12 ;
V_2 -> V_13 = V_6 -> V_13 >> 9 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_14 = 1 ;
if ( F_7 ( V_2 ) )
F_8 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
}
static int T_2 F_11 ( void )
{
return F_12 ( & V_15 ) ;
}
static void T_3 F_13 ( void )
{
F_14 ( & V_15 ) ;
}
