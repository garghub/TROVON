unsigned int F_1 (
const struct V_1 * const V_2 )
{
assert ( V_2 != NULL ) ;
assert ( V_2 -> V_3 != NULL ) ;
return F_2 ( V_2 -> V_3 -> V_4 . V_5 . V_6 ,
V_2 -> V_3 -> V_4 . V_7 == 2 ) ;
}
void F_3 (
struct V_8 * V_9 [] )
{
unsigned int V_10 ;
assert ( V_9 != NULL ) ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_9 [ V_10 ] = NULL ;
}
}
void F_4 (
struct V_8 * V_9 [] ,
unsigned int V_12 ,
struct V_8 * V_13 )
{
assert ( V_12 < V_11 ) ;
V_9 [ V_12 ] = V_13 ;
}
