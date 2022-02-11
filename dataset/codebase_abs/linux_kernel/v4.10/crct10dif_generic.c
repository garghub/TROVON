static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = 0 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , const T_1 * V_6 ,
unsigned int V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = F_4 ( V_4 -> V_5 , V_6 , V_7 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* ( V_9 * ) V_8 = V_4 -> V_5 ;
return 0 ;
}
static int F_6 ( V_9 * V_10 , const T_1 * V_6 , unsigned int V_11 ,
T_1 * V_8 )
{
* ( V_9 * ) V_8 = F_4 ( * V_10 , V_6 , V_11 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , const T_1 * V_6 ,
unsigned int V_11 , T_1 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_6 ( & V_4 -> V_5 , V_6 , V_11 , V_8 ) ;
}
static int F_8 ( struct V_1 * V_2 , const T_1 * V_6 ,
unsigned int V_7 , T_1 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_6 ( & V_4 -> V_5 , V_6 , V_7 , V_8 ) ;
}
static int T_2 F_9 ( void )
{
return F_10 ( & V_12 ) ;
}
static void T_3 F_11 ( void )
{
F_12 ( & V_12 ) ;
}
