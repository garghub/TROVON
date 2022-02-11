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
F_5 ( ! F_6 ( & V_4 -> V_2 -> V_7 ) ) ;
for ( V_5 = 0 ; V_5 < F_2 ( V_4 -> V_6 ) ; V_5 ++ ) {
while ( ! F_7 ( & V_4 -> V_6 [ V_5 ] ) ) {
struct V_8 * V_9 =
F_8 ( & V_4 -> V_6 [ V_5 ] ,
struct V_8 ,
V_10 ) ;
F_9 ( & V_9 -> V_10 ) ;
F_10 ( & V_9 -> V_11 ) ;
}
}
}
struct V_8 *
F_11 ( struct V_3 * V_4 ,
T_1 V_12 )
{
struct V_8 * V_9 = NULL ;
struct V_8 * V_13 , * V_14 ;
struct V_15 * V_16 ;
int V_5 ;
F_5 ( ! F_6 ( & V_4 -> V_2 -> V_7 ) ) ;
V_5 = F_12 ( V_12 >> V_17 ) - 1 ;
if ( V_5 >= F_2 ( V_4 -> V_6 ) )
V_5 = F_2 ( V_4 -> V_6 ) - 1 ;
V_16 = & V_4 -> V_6 [ V_5 ] ;
F_13 (tmp, next, list, batch_pool_link) {
if ( V_13 -> V_18 )
break;
if ( V_13 -> V_19 == V_20 ) {
F_9 ( & V_13 -> V_10 ) ;
F_10 ( & V_13 -> V_11 ) ;
continue;
}
if ( V_13 -> V_11 . V_12 >= V_12 ) {
V_9 = V_13 ;
break;
}
}
if ( V_9 == NULL ) {
int V_21 ;
V_9 = F_14 ( V_4 -> V_2 , V_12 ) ;
if ( V_9 == NULL )
return F_15 ( - V_22 ) ;
V_21 = F_16 ( V_9 ) ;
if ( V_21 )
return F_15 ( V_21 ) ;
V_9 -> V_19 = V_23 ;
}
F_17 ( & V_9 -> V_10 , V_16 ) ;
F_18 ( V_9 ) ;
return V_9 ;
}
