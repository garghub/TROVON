T_1 F_1 ( void )
{
return V_1 ? ( ( (struct V_2 * ) V_1 ) -> V_3 ) : 0 ;
}
int F_2 ( struct V_4 * V_4 , T_2 V_5 , T_3 * V_6 ,
unsigned long V_7 )
{
if ( V_1 ) {
const struct V_2 * const V_8 =
(struct V_2 * ) V_1 ;
const struct V_9 * const V_10 =
( const struct V_9 * ) ( V_1 + V_8 -> V_11 ) ;
int V_12 ;
T_4 V_13 = 0 ;
for ( V_12 = 0 ; V_12 < V_8 -> V_3 ; ++ V_12 ) {
struct V_9 V_14 = V_10 [ V_12 ] ;
if ( V_14 . V_15 == V_16 ) {
V_13 = V_14 . V_17 = V_5 ;
V_5 += V_14 . V_18 ;
} else {
V_14 . V_17 += V_13 ;
}
V_14 . V_19 = 0 ;
* V_6 += sizeof( V_14 ) ;
if ( * V_6 > V_7
|| ! F_3 ( V_4 , & V_14 , sizeof( V_14 ) ) )
return 0 ;
}
}
return 1 ;
}
int F_4 ( struct V_4 * V_4 , T_3 * V_6 ,
unsigned long V_7 )
{
if ( V_1 ) {
const struct V_2 * const V_8 =
(struct V_2 * ) V_1 ;
const struct V_9 * const V_10 =
( const struct V_9 * ) ( V_1 + V_8 -> V_11 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_8 -> V_3 ; ++ V_12 ) {
if ( V_10 [ V_12 ] . V_15 == V_16 ) {
void * V_20 = ( void * ) V_10 [ V_12 ] . V_21 ;
T_3 V_22 = V_10 [ V_12 ] . V_18 ;
* V_6 += V_22 ;
if ( * V_6 > V_7
|| ! F_3 ( V_4 , V_20 , V_22 ) )
return 0 ;
}
}
}
return 1 ;
}
T_3 F_5 ( void )
{
if ( V_1 ) {
const struct V_2 * const V_8 =
(struct V_2 * ) V_1 ;
const struct V_9 * const V_10 =
( const struct V_9 * ) ( V_1 + V_8 -> V_11 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_8 -> V_3 ; ++ V_12 )
if ( V_10 [ V_12 ] . V_15 == V_16 )
return ( T_3 ) V_10 [ V_12 ] . V_18 ;
}
return 0 ;
}
