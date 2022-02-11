void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
V_4 -> V_2 = V_2 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_4 -> V_6 ) ; V_5 ++ )
F_3 ( & V_4 -> V_6 [ V_5 ] ) ;
}
void F_4 ( struct V_3 * V_4 )
{
int V_5 ;
F_5 ( & V_4 -> V_2 -> V_7 -> V_8 . V_9 ) ;
for ( V_5 = 0 ; V_5 < F_2 ( V_4 -> V_6 ) ; V_5 ++ ) {
struct V_10 * V_11 , * V_12 ;
F_6 (obj, next,
&pool->cache_list[n],
batch_pool_link)
F_7 ( V_11 ) ;
F_3 ( & V_4 -> V_6 [ V_5 ] ) ;
}
}
struct V_10 *
F_8 ( struct V_3 * V_4 ,
T_1 V_13 )
{
struct V_10 * V_11 = NULL ;
struct V_10 * V_14 , * V_12 ;
struct V_15 * V_16 ;
int V_5 ;
F_5 ( & V_4 -> V_2 -> V_7 -> V_8 . V_9 ) ;
V_5 = F_9 ( V_13 >> V_17 ) - 1 ;
if ( V_5 >= F_2 ( V_4 -> V_6 ) )
V_5 = F_2 ( V_4 -> V_6 ) - 1 ;
V_16 = & V_4 -> V_6 [ V_5 ] ;
F_6 (tmp, next, list, batch_pool_link) {
if ( ! F_10 ( & V_14 -> V_18 [ V_4 -> V_2 -> V_19 ] ,
& V_14 -> V_20 . V_21 -> V_9 ) )
break;
if ( V_14 -> V_22 == V_23 ) {
F_11 ( & V_14 -> V_24 ) ;
F_7 ( V_14 ) ;
continue;
}
if ( V_14 -> V_20 . V_13 >= V_13 ) {
V_11 = V_14 ;
break;
}
}
if ( V_11 == NULL ) {
int V_25 ;
V_11 = F_12 ( & V_4 -> V_2 -> V_7 -> V_8 , V_13 ) ;
if ( F_13 ( V_11 ) )
return V_11 ;
V_25 = F_14 ( V_11 ) ;
if ( V_25 )
return F_15 ( V_25 ) ;
V_11 -> V_22 = V_26 ;
}
F_16 ( & V_11 -> V_24 , V_16 ) ;
F_17 ( V_11 ) ;
return V_11 ;
}
