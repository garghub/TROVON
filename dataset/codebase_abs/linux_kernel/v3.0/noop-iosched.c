static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 )
{
F_2 ( & V_5 -> V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 -> V_11 ;
if ( ! F_4 ( & V_9 -> V_12 ) ) {
struct V_3 * V_4 ;
V_4 = F_5 ( V_9 -> V_12 . V_5 , struct V_3 , V_6 ) ;
F_2 ( & V_4 -> V_6 ) ;
F_6 ( V_2 , V_4 ) ;
return 1 ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 -> V_11 ;
F_8 ( & V_4 -> V_6 , & V_9 -> V_12 ) ;
}
static struct V_3 *
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 -> V_11 ;
if ( V_4 -> V_6 . V_13 == & V_9 -> V_12 )
return NULL ;
return F_5 ( V_4 -> V_6 . V_13 , struct V_3 , V_6 ) ;
}
static struct V_3 *
F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 -> V_11 ;
if ( V_4 -> V_6 . V_5 == & V_9 -> V_12 )
return NULL ;
return F_5 ( V_4 -> V_6 . V_5 , struct V_3 , V_6 ) ;
}
static void * F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = F_12 ( sizeof( * V_9 ) , V_14 , V_2 -> V_15 ) ;
if ( ! V_9 )
return NULL ;
F_13 ( & V_9 -> V_12 ) ;
return V_9 ;
}
static void F_14 ( struct V_16 * V_17 )
{
struct V_8 * V_9 = V_17 -> V_11 ;
F_15 ( ! F_4 ( & V_9 -> V_12 ) ) ;
F_16 ( V_9 ) ;
}
static int T_1 F_17 ( void )
{
F_18 ( & V_18 ) ;
return 0 ;
}
static void T_2 F_19 ( void )
{
F_20 ( & V_18 ) ;
}
