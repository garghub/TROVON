static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return - V_6 ;
V_2 -> V_7 . V_8 = V_4 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_9 * V_7 = & V_2 -> V_7 ;
struct V_3 * V_4 = V_7 -> V_8 ;
F_4 ( V_4 ) ;
V_7 -> V_8 = NULL ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_11 ,
T_1 V_12 )
{
F_6 ( V_2 , V_13 , V_10 ) ;
F_7 ( V_2 , V_14 ,
( F_8 ( V_2 , V_14 ) & V_11 ) | V_12 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_1 V_10 )
{
F_6 ( V_2 , V_15 , V_10 ) ;
return F_8 ( V_2 , V_16 ) ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_10 ,
T_1 V_17 )
{
F_6 ( V_2 , V_15 , V_10 ) ;
F_7 ( V_2 , V_16 , V_17 ) ;
}
static unsigned int F_11 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 -> V_18 ) == V_19 )
return 11 ;
return 36 ;
}
static enum V_20
F_13 ( struct V_1 * V_2 , bool V_21 )
{
return V_22 ;
}
static void F_14 ( struct V_1 * V_2 )
{
}
