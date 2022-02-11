static struct V_1 *
V_1 ( struct V_2 * V_3 )
{
return F_1 ( V_3 , struct V_1 , V_4 . V_3 ) ;
}
static void F_2 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_1 * V_7 = V_1 ( V_3 ) ;
int V_8 ;
V_8 = F_3 ( V_6 , V_7 -> V_9 ) ;
F_4 ( V_8 != 0 ) ;
}
static int F_5 ( struct V_2 * V_3 , void * V_10 )
{
struct V_1 * V_7 = V_1 ( V_3 ) ;
return F_6 ( V_3 -> V_6 , & V_7 -> V_9 ) ;
}
static void F_7 ( void * V_10 , T_1 V_11 )
{
struct V_12 * V_13 = (struct V_12 * ) V_10 ;
V_13 -> V_9 = V_11 ;
}
int F_8 ( struct V_14 * V_15 , void * V_10 ,
struct V_16 * V_17 )
{
struct V_12 * V_13 = (struct V_12 * ) V_10 ;
return F_9 ( F_10 ( V_17 ) -> V_18 ,
V_13 -> V_9 , V_19 ) ;
}
int F_11 ( struct V_14 * V_15 , void * V_10 ,
struct V_16 * V_17 )
{
return F_12 ( V_15 , V_10 , V_17 ,
& V_20 ) ;
}
int F_13 ( struct V_5 * V_6 ,
struct V_21 * V_18 ,
T_2 * V_22 , struct V_2 * * V_23 )
{
struct V_1 * V_7 ;
struct V_2 * V_3 =
F_14 ( V_18 , * V_22 , & V_20 ) ;
if ( F_15 ( V_3 ) )
return F_16 ( V_3 ) ;
V_7 = V_1 ( V_3 ) ;
* V_22 = V_7 -> V_9 ;
* V_23 = V_3 ;
return 0 ;
}
