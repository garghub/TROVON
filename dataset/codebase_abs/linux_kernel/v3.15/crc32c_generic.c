static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
V_7 -> V_8 = V_4 -> V_9 ;
return 0 ;
}
static int F_4 ( struct V_10 * V_5 , const T_1 * V_9 ,
unsigned int V_11 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
if ( V_11 != sizeof( V_4 -> V_9 ) ) {
F_5 ( V_5 , V_12 ) ;
return - V_13 ;
}
V_4 -> V_9 = F_6 ( * ( V_14 * ) V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , const T_1 * V_15 ,
unsigned int V_16 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
V_7 -> V_8 = F_8 ( V_7 -> V_8 , V_15 , V_16 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 * V_17 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
* ( V_14 * ) V_17 = ~ F_10 ( & V_7 -> V_8 ) ;
return 0 ;
}
static int F_11 ( T_2 * V_18 , const T_1 * V_15 , unsigned int V_19 , T_1 * V_17 )
{
* ( V_14 * ) V_17 = ~ F_12 ( F_8 ( * V_18 , V_15 , V_19 ) ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , const T_1 * V_15 ,
unsigned int V_19 , T_1 * V_17 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
return F_11 ( & V_7 -> V_8 , V_15 , V_19 , V_17 ) ;
}
static int F_14 ( struct V_1 * V_2 , const T_1 * V_15 ,
unsigned int V_16 , T_1 * V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
return F_11 ( & V_4 -> V_9 , V_15 , V_16 , V_17 ) ;
}
static int F_15 ( struct V_20 * V_5 )
{
struct V_3 * V_4 = F_16 ( V_5 ) ;
V_4 -> V_9 = ~ 0 ;
return 0 ;
}
static int T_3 F_17 ( void )
{
return F_18 ( & V_21 ) ;
}
static void T_4 F_19 ( void )
{
F_20 ( & V_21 ) ;
}
