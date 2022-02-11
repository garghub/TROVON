static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 )
{
F_2 ( & V_5 -> V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 -> V_11 ;
struct V_3 * V_4 ;
V_4 = F_4 ( & V_9 -> V_12 , struct V_3 , V_6 ) ;
if ( V_4 ) {
F_2 ( & V_4 -> V_6 ) ;
F_5 ( V_2 , V_4 ) ;
return 1 ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 -> V_11 ;
F_7 ( & V_4 -> V_6 , & V_9 -> V_12 ) ;
}
static struct V_3 *
F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 -> V_11 ;
if ( V_4 -> V_6 . V_13 == & V_9 -> V_12 )
return NULL ;
return F_9 ( V_4 , V_6 ) ;
}
static struct V_3 *
F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 -> V_11 ;
if ( V_4 -> V_6 . V_5 == & V_9 -> V_12 )
return NULL ;
return F_11 ( V_4 , V_6 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_8 * V_9 ;
struct V_16 * V_17 ;
V_17 = F_13 ( V_2 , V_15 ) ;
if ( ! V_17 )
return - V_18 ;
V_9 = F_14 ( sizeof( * V_9 ) , V_19 , V_2 -> V_20 ) ;
if ( ! V_9 ) {
F_15 ( & V_17 -> V_21 ) ;
return - V_18 ;
}
V_17 -> V_11 = V_9 ;
F_16 ( & V_9 -> V_12 ) ;
F_17 ( V_2 -> V_22 ) ;
V_2 -> V_10 = V_17 ;
F_18 ( V_2 -> V_22 ) ;
return 0 ;
}
static void F_19 ( struct V_16 * V_15 )
{
struct V_8 * V_9 = V_15 -> V_11 ;
F_20 ( ! F_21 ( & V_9 -> V_12 ) ) ;
F_22 ( V_9 ) ;
}
static int T_1 F_23 ( void )
{
return F_24 ( & V_23 ) ;
}
static void T_2 F_25 ( void )
{
F_26 ( & V_23 ) ;
}
