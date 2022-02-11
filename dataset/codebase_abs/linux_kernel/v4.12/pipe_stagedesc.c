void F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 [] ,
struct V_5 * V_7 ,
struct V_5 * V_8 )
{
unsigned int V_9 ;
F_2 ( L_1 ,
V_2 , V_4 , V_6 , V_7 , V_8 ) ;
assert ( V_2 != NULL && V_4 != NULL && V_4 -> V_10 != NULL ) ;
if ( V_2 == NULL || V_4 == NULL || V_4 -> V_10 == NULL ) {
F_3 ( L_2 ) ;
goto V_11;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_12 = NULL ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = V_4 -> V_10 -> V_17 . V_18 . V_16 ;
V_2 -> V_7 = V_7 ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_2 -> V_6 [ V_9 ] = V_6 [ V_9 ] ;
}
V_2 -> V_8 = V_8 ;
V_11:
F_4 ( L_3 ) ;
}
void F_5 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 [] ,
struct V_5 * V_7 ,
struct V_5 * V_8 ,
const struct V_20 * V_21 ,
unsigned int V_16 )
{
unsigned int V_9 ;
F_6 ( V_22 , L_4 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_12 = V_21 ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_7 = V_7 ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_2 -> V_6 [ V_9 ] = V_6 [ V_9 ] ;
}
V_2 -> V_8 = V_8 ;
}
void F_7 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_20 * V_21 )
{
unsigned int V_9 ;
F_6 ( V_22 , L_5 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_12 = V_21 ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = V_23 ;
V_2 -> V_7 = NULL ;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
V_2 -> V_6 [ V_9 ] = NULL ;
}
V_2 -> V_8 = NULL ;
}
void F_8 (
struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_24 V_13 ,
unsigned V_15 )
{
unsigned int V_9 ;
F_6 ( V_22 , L_6 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_12 = NULL ;
V_2 -> V_13 = V_13 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_16 = ( unsigned int ) - 1 ;
V_2 -> V_7 = NULL ;
V_2 -> V_6 [ 0 ] = V_6 ;
for ( V_9 = 1 ; V_9 < V_19 ; V_9 ++ ) {
V_2 -> V_6 [ V_9 ] = NULL ;
}
V_2 -> V_8 = NULL ;
}
