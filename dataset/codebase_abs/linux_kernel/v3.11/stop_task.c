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
V_6 -> V_8 . V_9 = F_5 ( V_5 ) ;
return V_6 ;
}
return NULL ;
}
static void
F_6 ( struct V_5 * V_5 , struct V_1 * V_2 , int V_4 )
{
F_7 ( V_5 ) ;
}
static void
F_8 ( struct V_5 * V_5 , struct V_1 * V_2 , int V_4 )
{
F_9 ( V_5 ) ;
}
static void F_10 ( struct V_5 * V_5 )
{
F_11 () ;
}
static void F_12 ( struct V_5 * V_5 , struct V_1 * V_10 )
{
struct V_1 * V_11 = V_5 -> V_11 ;
T_1 V_12 ;
V_12 = F_5 ( V_5 ) - V_11 -> V_8 . V_9 ;
if ( F_13 ( ( V_13 ) V_12 < 0 ) )
V_12 = 0 ;
F_14 ( V_11 -> V_8 . V_14 . V_15 ,
F_15 ( V_11 -> V_8 . V_14 . V_15 , V_12 ) ) ;
V_11 -> V_8 . V_16 += V_12 ;
F_16 ( V_11 , V_12 ) ;
V_11 -> V_8 . V_9 = F_5 ( V_5 ) ;
F_17 ( V_11 , V_12 ) ;
}
static void F_18 ( struct V_5 * V_5 , struct V_1 * V_11 , int V_17 )
{
}
static void F_19 ( struct V_5 * V_5 )
{
struct V_1 * V_6 = V_5 -> V_6 ;
V_6 -> V_8 . V_9 = F_5 ( V_5 ) ;
}
static void F_20 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
F_11 () ;
}
static void
F_21 ( struct V_5 * V_5 , struct V_1 * V_2 , int V_18 )
{
F_11 () ;
}
static unsigned int
F_22 ( struct V_5 * V_5 , struct V_1 * V_19 )
{
return 0 ;
}
