void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_2 = V_2 ;
F_2 ( & V_4 -> V_5 ) ;
}
void F_3 ( struct V_3 * V_4 )
{
F_4 ( ! F_5 ( & V_4 -> V_2 -> V_6 ) ) ;
while ( ! F_6 ( & V_4 -> V_5 ) ) {
struct V_7 * V_8 =
F_7 ( & V_4 -> V_5 ,
struct V_7 ,
V_9 ) ;
F_4 ( V_8 -> V_10 ) ;
F_8 ( & V_8 -> V_9 ) ;
F_9 ( & V_8 -> V_11 ) ;
}
}
struct V_7 *
F_10 ( struct V_3 * V_4 ,
T_1 V_12 )
{
struct V_7 * V_8 = NULL ;
struct V_7 * V_13 , * V_14 ;
F_4 ( ! F_5 ( & V_4 -> V_2 -> V_6 ) ) ;
F_11 (tmp, next,
&pool->cache_list, batch_pool_list) {
if ( V_13 -> V_10 )
continue;
if ( V_13 -> V_15 == V_16 ) {
F_12 ( & V_13 -> V_9 ) ;
F_9 ( & V_13 -> V_11 ) ;
continue;
}
if ( V_13 -> V_11 . V_12 >= V_12 &&
V_13 -> V_11 . V_12 <= ( 2 * V_12 ) ) {
V_8 = V_13 ;
break;
}
}
if ( ! V_8 ) {
V_8 = F_13 ( V_4 -> V_2 , V_12 ) ;
if ( ! V_8 )
return F_14 ( - V_17 ) ;
F_15 ( & V_8 -> V_9 , & V_4 -> V_5 ) ;
}
else
F_16 ( & V_8 -> V_9 , & V_4 -> V_5 ) ;
V_8 -> V_15 = V_18 ;
return V_8 ;
}
