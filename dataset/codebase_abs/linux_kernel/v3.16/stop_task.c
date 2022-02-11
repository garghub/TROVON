static int
F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , int V_5 )
{
return F_2 ( V_2 ) ;
}
static void
F_3 ( struct V_6 * V_6 , struct V_1 * V_2 , int V_5 )
{
}
static struct V_1 *
F_4 ( struct V_6 * V_6 , struct V_1 * V_7 )
{
struct V_1 * V_8 = V_6 -> V_8 ;
if ( ! V_8 || ! V_8 -> V_9 )
return NULL ;
F_5 ( V_6 , V_7 ) ;
V_8 -> V_10 . V_11 = F_6 ( V_6 ) ;
return V_8 ;
}
static void
F_7 ( struct V_6 * V_6 , struct V_1 * V_2 , int V_5 )
{
F_8 ( V_6 , 1 ) ;
}
static void
F_9 ( struct V_6 * V_6 , struct V_1 * V_2 , int V_5 )
{
F_10 ( V_6 , 1 ) ;
}
static void F_11 ( struct V_6 * V_6 )
{
F_12 () ;
}
static void F_13 ( struct V_6 * V_6 , struct V_1 * V_7 )
{
struct V_1 * V_12 = V_6 -> V_12 ;
T_1 V_13 ;
V_13 = F_6 ( V_6 ) - V_12 -> V_10 . V_11 ;
if ( F_14 ( ( V_14 ) V_13 < 0 ) )
V_13 = 0 ;
F_15 ( V_12 -> V_10 . V_15 . V_16 ,
F_16 ( V_12 -> V_10 . V_15 . V_16 , V_13 ) ) ;
V_12 -> V_10 . V_17 += V_13 ;
F_17 ( V_12 , V_13 ) ;
V_12 -> V_10 . V_11 = F_6 ( V_6 ) ;
F_18 ( V_12 , V_13 ) ;
}
static void F_19 ( struct V_6 * V_6 , struct V_1 * V_12 , int V_18 )
{
}
static void F_20 ( struct V_6 * V_6 )
{
struct V_1 * V_8 = V_6 -> V_8 ;
V_8 -> V_10 . V_11 = F_6 ( V_6 ) ;
}
static void F_21 ( struct V_6 * V_6 , struct V_1 * V_2 )
{
F_12 () ;
}
static void
F_22 ( struct V_6 * V_6 , struct V_1 * V_2 , int V_19 )
{
F_12 () ;
}
static unsigned int
F_23 ( struct V_6 * V_6 , struct V_1 * V_20 )
{
return 0 ;
}
