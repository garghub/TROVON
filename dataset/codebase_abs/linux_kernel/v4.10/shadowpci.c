static T_1
F_1 ( void * V_1 , T_1 V_2 , T_1 V_3 , struct V_4 * V_5 )
{
struct V_6 * V_6 = V_1 ;
if ( V_2 + V_3 <= V_6 -> V_7 ) {
F_2 ( V_5 -> V_1 + V_2 , V_6 -> V_8 + V_2 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
static void
F_3 ( void * V_1 )
{
struct V_6 * V_6 = V_1 ;
F_4 ( V_6 -> V_9 , V_6 -> V_8 ) ;
F_5 ( V_6 -> V_9 ) ;
F_6 ( V_6 ) ;
}
static void *
F_7 ( struct V_4 * V_5 , const char * V_10 )
{
struct V_11 * V_12 = V_5 -> V_13 . V_12 ;
struct V_6 * V_6 = NULL ;
struct V_14 * V_9 ;
int V_15 ;
if ( V_12 -> V_16 -> V_17 )
V_9 = V_12 -> V_16 -> V_17 ( V_12 ) -> V_9 ;
else
return F_8 ( - V_18 ) ;
if ( ! ( V_15 = F_9 ( V_9 ) ) ) {
if ( V_15 = - V_19 ,
( V_6 = F_10 ( sizeof( * V_6 ) , V_20 ) ) ) {
if ( V_15 = - V_21 ,
( V_6 -> V_8 = F_11 ( V_9 , & V_6 -> V_7 ) ) ) {
V_6 -> V_9 = V_9 ;
return V_6 ;
}
F_6 ( V_6 ) ;
}
F_5 ( V_9 ) ;
}
return F_8 ( V_15 ) ;
}
static void *
F_12 ( struct V_4 * V_5 , const char * V_10 )
{
struct V_11 * V_12 = V_5 -> V_13 . V_12 ;
struct V_14 * V_9 ;
struct V_6 * V_6 ;
int V_15 = - V_19 ;
if ( V_12 -> V_16 -> V_17 )
V_9 = V_12 -> V_16 -> V_17 ( V_12 ) -> V_9 ;
else
return F_8 ( - V_18 ) ;
if ( ( V_6 = F_10 ( sizeof( * V_6 ) , V_20 ) ) ) {
if ( V_15 = - V_18 ,
( V_6 -> V_8 = F_13 ( V_9 , & V_6 -> V_7 ) ) )
return V_6 ;
F_6 ( V_6 ) ;
}
return F_8 ( V_15 ) ;
}
