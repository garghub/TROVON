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
struct V_10 * V_11 ;
struct V_14 * V_15 ;
int V_5 , V_16 ;
F_5 ( & V_4 -> V_2 -> V_7 -> V_8 . V_9 ) ;
V_5 = F_9 ( V_13 >> V_17 ) - 1 ;
if ( V_5 >= F_2 ( V_4 -> V_6 ) )
V_5 = F_2 ( V_4 -> V_6 ) - 1 ;
V_15 = & V_4 -> V_6 [ V_5 ] ;
F_10 (obj, list, batch_pool_link) {
if ( F_11 ( V_11 ) ) {
struct V_18 * V_19 = V_11 -> V_19 ;
if ( ! F_12 ( V_19 , true ) )
break;
F_13 ( V_4 -> V_2 -> V_7 ) ;
F_14 ( F_11 ( V_11 ) ) ;
if ( F_15 ( V_19 -> V_20 ) ) {
F_16 ( V_19 , NULL ) ;
F_17 ( V_19 , NULL ) ;
F_18 ( V_19 ) ;
}
}
F_14 ( ! F_12 ( V_11 -> V_19 ,
true ) ) ;
if ( V_11 -> V_21 . V_13 >= V_13 )
goto V_22;
}
V_11 = F_19 ( V_4 -> V_2 -> V_7 , V_13 ) ;
if ( F_20 ( V_11 ) )
return V_11 ;
V_22:
V_16 = F_21 ( V_11 ) ;
if ( V_16 )
return F_22 ( V_16 ) ;
F_23 ( & V_11 -> V_23 , V_15 ) ;
return V_11 ;
}
