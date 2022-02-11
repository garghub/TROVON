static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & V_3 -> V_4 . V_5 ;
}
static void * F_2 ( const struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 ;
V_11 = F_3 ( V_12 , V_13 ) ;
if ( ! V_11 )
V_11 = F_4 ( - V_14 ) ;
return V_11 ;
}
static void F_5 ( const struct V_6 * V_7 ,
struct V_8 * V_9 , void * V_15 )
{
struct V_10 * V_11 = V_15 ;
F_6 ( V_12 , V_11 ) ;
}
static void * F_7 ( const struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_16 * V_11 ;
V_11 = F_3 ( V_17 , V_13 ) ;
if ( ! V_11 )
V_11 = F_4 ( - V_14 ) ;
return V_11 ;
}
static void F_8 ( const struct V_6 * V_7 ,
struct V_8 * V_9 , void * V_15 )
{
struct V_16 * V_11 = V_15 ;
F_6 ( V_17 , V_11 ) ;
}
static int F_9 ( const struct V_18 * V_19 ,
struct V_1 * V_20 , struct V_21 * V_22 )
{
return F_10 ( V_20 -> V_23 , V_22 ) ;
}
static int F_11 ( const struct V_18 * V_19 , struct V_1 * V_20 ,
const char * V_24 , struct V_1 * V_25 )
{
return 0 ;
}
static struct V_1 * F_12 ( const struct V_18 * V_19 ,
struct V_1 * V_20 )
{
return NULL ;
}
static struct V_1 * F_13 ( const struct V_18 * V_19 ,
struct V_1 * V_20 )
{
struct V_2 * V_26 = F_14 ( V_20 ) ;
F_15 ( F_16 ( V_20 ) ) ;
F_17 ( V_26 ) ;
return NULL ;
}
static struct V_1 * F_18 ( const struct V_18 * V_19 ,
struct V_27 * V_28 ,
struct V_21 * V_22 )
{
struct V_1 * V_20 ;
struct V_2 * V_26 ;
struct V_29 * V_30 ;
int V_31 ;
V_26 = F_19 ( sizeof( * V_26 ) , V_13 ) ;
if ( ! V_26 )
return F_4 ( - V_14 ) ;
F_20 ( & V_26 -> V_4 , V_28 ) ;
V_20 = F_1 ( V_26 ) ;
V_20 -> V_32 = & V_33 ;
V_26 -> V_4 . V_34 = & V_35 ;
V_30 = F_21 ( F_22 ( V_22 , 0 ) ) ;
F_23 ( V_30 ) ;
V_31 = F_24 ( V_30 , V_22 ) ;
if ( V_31 ) {
F_13 ( V_19 , V_20 ) ;
return F_4 ( V_31 ) ;
}
V_26 -> V_36 = V_30 -> V_37 ;
return V_20 ;
}
