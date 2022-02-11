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
struct V_10 * V_14 ;
struct V_15 * V_16 ;
int V_5 , V_17 ;
F_5 ( & V_4 -> V_2 -> V_7 -> V_8 . V_9 ) ;
V_5 = F_9 ( V_13 >> V_18 ) - 1 ;
if ( V_5 >= F_2 ( V_4 -> V_6 ) )
V_5 = F_2 ( V_4 -> V_6 ) - 1 ;
V_16 = & V_4 -> V_6 [ V_5 ] ;
F_10 (tmp, list, batch_pool_link) {
if ( F_11 ( V_14 ) )
break;
F_12 ( ! F_13 ( V_14 -> V_19 ,
true ) ) ;
if ( V_14 -> V_20 . V_13 >= V_13 ) {
F_14 ( & V_14 -> V_19 -> V_21 , NULL ) ;
F_15 ( V_14 -> V_19 , NULL ) ;
F_16 ( & V_14 -> V_19 -> V_21 ) ;
V_11 = V_14 ;
break;
}
}
if ( V_11 == NULL ) {
V_11 = F_17 ( V_4 -> V_2 -> V_7 , V_13 ) ;
if ( F_18 ( V_11 ) )
return V_11 ;
}
V_17 = F_19 ( V_11 ) ;
if ( V_17 )
return F_20 ( V_17 ) ;
F_21 ( & V_11 -> V_22 , V_16 ) ;
return V_11 ;
}
