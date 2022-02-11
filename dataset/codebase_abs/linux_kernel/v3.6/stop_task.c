static int
F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
return F_2 ( V_2 ) ;
}
static void
F_3 ( struct V_5 * V_5 , struct V_1 * V_2 , int V_4 )
{
}
static struct V_1 * F_4 ( struct V_5 * V_5 )
{
struct V_1 * V_6 = V_5 -> V_6 ;
if ( V_6 && V_6 -> V_7 ) {
V_6 -> V_8 . V_9 = V_5 -> V_10 ;
return V_6 ;
}
return NULL ;
}
static void
F_5 ( struct V_5 * V_5 , struct V_1 * V_2 , int V_4 )
{
F_6 ( V_5 ) ;
}
static void
F_7 ( struct V_5 * V_5 , struct V_1 * V_2 , int V_4 )
{
F_8 ( V_5 ) ;
}
static void F_9 ( struct V_5 * V_5 )
{
F_10 () ;
}
static void F_11 ( struct V_5 * V_5 , struct V_1 * V_11 )
{
struct V_1 * V_12 = V_5 -> V_12 ;
T_1 V_13 ;
V_13 = V_5 -> V_10 - V_12 -> V_8 . V_9 ;
if ( F_12 ( ( V_14 ) V_13 < 0 ) )
V_13 = 0 ;
F_13 ( V_12 -> V_8 . V_15 . V_16 ,
F_14 ( V_12 -> V_8 . V_15 . V_16 , V_13 ) ) ;
V_12 -> V_8 . V_17 += V_13 ;
F_15 ( V_12 , V_13 ) ;
V_12 -> V_8 . V_9 = V_5 -> V_10 ;
F_16 ( V_12 , V_13 ) ;
}
static void F_17 ( struct V_5 * V_5 , struct V_1 * V_12 , int V_18 )
{
}
static void F_18 ( struct V_5 * V_5 )
{
struct V_1 * V_6 = V_5 -> V_6 ;
V_6 -> V_8 . V_9 = V_5 -> V_10 ;
}
static void F_19 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
F_10 () ;
}
static void
F_20 ( struct V_5 * V_5 , struct V_1 * V_2 , int V_19 )
{
F_10 () ;
}
static unsigned int
F_21 ( struct V_5 * V_5 , struct V_1 * V_20 )
{
return 0 ;
}
