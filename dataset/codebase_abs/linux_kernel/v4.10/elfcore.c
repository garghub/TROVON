T_1 F_1 ( void )
{
return V_1 ? ( ( (struct V_2 * ) V_1 ) -> V_3 ) : 0 ;
}
int F_2 ( struct V_4 * V_5 , T_2 V_6 )
{
if ( V_1 ) {
const struct V_2 * const V_7 =
(struct V_2 * ) V_1 ;
const struct V_8 * const V_9 =
( const struct V_8 * ) ( V_1 + V_7 -> V_10 ) ;
int V_11 ;
T_3 V_12 = 0 ;
for ( V_11 = 0 ; V_11 < V_7 -> V_3 ; ++ V_11 ) {
struct V_8 V_13 = V_9 [ V_11 ] ;
if ( V_13 . V_14 == V_15 ) {
V_12 = V_13 . V_16 = V_6 ;
V_6 += V_13 . V_17 ;
} else {
V_13 . V_16 += V_12 ;
}
V_13 . V_18 = 0 ;
if ( ! F_3 ( V_5 , & V_13 , sizeof( V_13 ) ) )
return 0 ;
}
}
return 1 ;
}
int F_4 ( struct V_4 * V_5 )
{
if ( V_1 ) {
const struct V_2 * const V_7 =
(struct V_2 * ) V_1 ;
const struct V_8 * const V_9 =
( const struct V_8 * ) ( V_1 + V_7 -> V_10 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_7 -> V_3 ; ++ V_11 ) {
if ( V_9 [ V_11 ] . V_14 == V_15 ) {
void * V_19 = ( void * ) V_9 [ V_11 ] . V_20 ;
T_4 V_21 = V_9 [ V_11 ] . V_17 ;
if ( ! F_3 ( V_5 , V_19 , V_21 ) )
return 0 ;
}
}
}
return 1 ;
}
T_4 F_5 ( void )
{
if ( V_1 ) {
const struct V_2 * const V_7 =
(struct V_2 * ) V_1 ;
const struct V_8 * const V_9 =
( const struct V_8 * ) ( V_1 + V_7 -> V_10 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_7 -> V_3 ; ++ V_11 )
if ( V_9 [ V_11 ] . V_14 == V_15 )
return ( T_4 ) V_9 [ V_11 ] . V_17 ;
}
return 0 ;
}
