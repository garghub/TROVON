static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = & V_2 -> V_6 . V_7 . V_5 ;
T_1 V_8 ;
memset ( V_2 -> V_9 , 0 , V_2 -> V_10 ) ;
V_5 -> V_10 = V_2 -> V_10 ;
V_8 = V_5 -> V_8 ;
V_3 = F_2 ( & V_2 -> V_6 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( F_3 ( V_5 -> V_10 > V_2 -> V_10 ) ) {
F_4 ( V_2 -> V_9 ) ;
V_2 -> V_10 = V_5 -> V_10 ;
V_2 -> V_9 = F_5 ( V_2 -> V_10 , V_11 ) ;
if ( ! V_2 -> V_9 )
return - V_12 ;
F_6 ( V_5 -> V_9 , V_2 -> V_9 ) ;
V_5 -> V_8 -- ;
V_3 = F_2 ( & V_2 -> V_6 ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_5 -> V_8 == V_8 )
return 1 ;
return 0 ;
}
static void * F_7 ( struct V_13 * V_14 , T_2 * V_15 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 -> V_16 ;
V_2 -> V_6 . V_7 . V_5 . V_8 = * V_15 ;
if ( F_1 ( V_2 ) )
return NULL ;
return V_14 -> V_16 ;
}
static void * F_8 ( struct V_13 * V_14 , void * V_17 , T_2 * V_15 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 -> V_16 ;
V_2 -> V_6 . V_7 . V_5 . V_8 = ++ ( * V_15 ) ;
if ( F_1 ( V_2 ) )
return NULL ;
return V_17 ;
}
static int F_9 ( struct V_13 * V_14 , void * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 -> V_16 ;
struct V_4 * V_5 = & V_2 -> V_6 . V_7 . V_5 ;
F_10 ( V_14 , L_1 , V_5 -> V_18 ,
V_5 -> type , V_2 -> V_9 ) ;
return 0 ;
}
static void F_11 ( struct V_13 * V_14 , void * V_17 )
{
}
static int F_12 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 ;
int V_3 ;
V_3 = F_13 ( V_20 , & V_21 ,
sizeof( struct V_1 ) ) ;
if ( V_3 )
return V_3 ;
V_14 = V_20 -> V_22 ;
V_2 = (struct V_1 * ) V_14 -> V_16 ;
V_2 -> V_10 = V_23 + 1 ;
V_2 -> V_9 = F_5 ( V_2 -> V_10 , V_11 ) ;
if ( ! V_2 -> V_9 ) {
F_14 ( V_19 , V_20 ) ;
return - V_12 ;
}
F_6 ( V_2 -> V_6 . V_7 . V_5 . V_9 , V_2 -> V_9 ) ;
V_2 -> V_6 . V_24 = V_25 ;
V_2 -> V_6 . V_7 . V_5 . V_10 = V_2 -> V_10 ;
return 0 ;
}
static int F_15 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
struct V_13 * V_14 = V_20 -> V_22 ;
struct V_1 * V_2 = (struct V_1 * ) V_14 -> V_16 ;
F_4 ( V_2 -> V_9 ) ;
return F_14 ( V_19 , V_20 ) ;
}
