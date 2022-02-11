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
F_4 ( struct V_6 * V_6 , struct V_1 * V_7 , struct V_8 V_9 )
{
struct V_1 * V_10 = V_6 -> V_10 ;
if ( ! V_10 || ! F_5 ( V_10 ) )
return NULL ;
F_6 ( V_6 , V_7 ) ;
V_10 -> V_11 . V_12 = F_7 ( V_6 ) ;
return V_10 ;
}
static void
F_8 ( struct V_6 * V_6 , struct V_1 * V_2 , int V_5 )
{
F_9 ( V_6 , 1 ) ;
}
static void
F_10 ( struct V_6 * V_6 , struct V_1 * V_2 , int V_5 )
{
F_11 ( V_6 , 1 ) ;
}
static void F_12 ( struct V_6 * V_6 )
{
F_13 () ;
}
static void F_14 ( struct V_6 * V_6 , struct V_1 * V_7 )
{
struct V_1 * V_13 = V_6 -> V_13 ;
T_1 V_14 ;
V_14 = F_7 ( V_6 ) - V_13 -> V_11 . V_12 ;
if ( F_15 ( ( V_15 ) V_14 < 0 ) )
V_14 = 0 ;
F_16 ( V_13 -> V_11 . V_16 . V_17 ,
F_17 ( V_13 -> V_11 . V_16 . V_17 , V_14 ) ) ;
V_13 -> V_11 . V_18 += V_14 ;
F_18 ( V_13 , V_14 ) ;
V_13 -> V_11 . V_12 = F_7 ( V_6 ) ;
F_19 ( V_13 , V_14 ) ;
}
static void F_20 ( struct V_6 * V_6 , struct V_1 * V_13 , int V_19 )
{
}
static void F_21 ( struct V_6 * V_6 )
{
struct V_1 * V_10 = V_6 -> V_10 ;
V_10 -> V_11 . V_12 = F_7 ( V_6 ) ;
}
static void F_22 ( struct V_6 * V_6 , struct V_1 * V_2 )
{
F_13 () ;
}
static void
F_23 ( struct V_6 * V_6 , struct V_1 * V_2 , int V_20 )
{
F_13 () ;
}
static unsigned int
F_24 ( struct V_6 * V_6 , struct V_1 * V_21 )
{
return 0 ;
}
static void F_25 ( struct V_6 * V_6 )
{
}
