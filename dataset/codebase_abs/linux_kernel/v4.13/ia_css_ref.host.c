void
F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned V_5 )
{
unsigned V_6 = V_7 , V_8 ;
( void ) V_5 ;
F_2 ( & V_2 -> V_9 , & ( V_4 -> V_10 [ 0 ] -> V_11 ) ) ;
V_2 -> V_12 = V_6 / V_2 -> V_9 . V_13 ;
V_2 -> V_14 = V_4 -> V_14 ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ ) {
if ( V_4 -> V_10 [ V_8 ] ) {
V_2 -> V_16 [ V_8 ] = V_4 -> V_10 [ V_8 ] -> V_17 + V_4 -> V_10 [ V_8 ] -> V_18 . V_19 . V_20 . V_21 ;
V_2 -> V_22 [ V_8 ] = V_4 -> V_10 [ V_8 ] -> V_17 + V_4 -> V_10 [ V_8 ] -> V_18 . V_19 . V_23 . V_21 ;
} else {
V_2 -> V_16 [ V_8 ] = 0 ;
V_2 -> V_22 [ V_8 ] = 0 ;
}
}
assert ( V_6 % V_2 -> V_9 . V_13 == 0 ) ;
}
void
F_3 (
const struct V_24 * V_25 ,
const struct V_26 * * V_10 ,
const T_1 V_14 )
{
struct V_3 V_27 ;
unsigned V_8 ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ )
V_27 . V_10 [ V_8 ] = V_10 [ V_8 ] ;
V_27 . V_14 = V_14 ;
F_4 ( V_25 , & V_27 ) ;
}
void
F_5 (
struct V_28 * V_29 ,
unsigned V_5 )
{
( void ) V_5 ;
assert ( V_15 >= 2 ) ;
V_29 -> V_30 = 0 ;
V_29 -> V_31 = 1 ;
}
