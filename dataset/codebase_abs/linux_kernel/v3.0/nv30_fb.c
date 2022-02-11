void
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 ,
T_1 V_5 , T_1 V_6 , T_1 V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = & V_9 -> V_12 . V_13 [ V_3 ] ;
V_12 -> V_4 = V_4 | 1 ;
V_12 -> V_14 = F_2 ( 1u , V_4 + V_5 ) - 1 ;
V_12 -> V_6 = V_6 ;
}
void
F_3 ( struct V_1 * V_2 , int V_3 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = & V_9 -> V_12 . V_13 [ V_3 ] ;
V_12 -> V_4 = V_12 -> V_14 = V_12 -> V_6 = 0 ;
}
static int
F_4 ( struct V_1 * V_2 , int V_15 , int V_3 , int V_16 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_17 = ( V_9 -> V_18 > 0x30 ?
F_5 ( V_2 , 0x122c + 0x10 * V_15 + 0x4 * V_16 ) >> ( 4 * ( V_3 ^ 1 ) ) :
0 ) & 0xf ;
return 2 * ( V_17 & 0x8 ? V_17 - 0x10 : V_17 ) ;
}
static int
F_6 ( struct V_1 * V_2 , int V_19 , int V_15 , int V_3 )
{
int V_16 , V_20 = 0 ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
int V_21 = ( V_19 >> ( 8 * V_3 ) & 0xff ) + F_4 ( V_2 , V_15 , V_3 , V_16 ) ;
V_20 |= ( 0x80 | F_7 ( V_21 , 0 , 0x1f ) ) << ( 8 * V_16 ) ;
}
return V_20 ;
}
int
F_8 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_22 * V_23 = & V_9 -> V_24 . V_25 ;
int V_3 , V_16 ;
V_23 -> V_26 = V_27 ;
for ( V_3 = 0 ; V_3 < V_23 -> V_26 ; V_3 ++ )
V_23 -> V_28 ( V_2 , V_3 ) ;
if ( V_9 -> V_18 == 0x30 ||
V_9 -> V_18 == 0x31 ||
V_9 -> V_18 == 0x35 ) {
int V_29 = ( V_9 -> V_18 == 0x31 ? 2 : 4 ) ;
int V_19 = F_5 ( V_2 , 0x1003d0 ) ;
for ( V_3 = 0 ; V_3 < V_29 ; V_3 ++ ) {
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
F_9 ( V_2 , 0x10037c + 0xc * V_3 + 0x4 * V_16 ,
F_6 ( V_2 , V_19 , 0 , V_16 ) ) ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
F_9 ( V_2 , 0x1003ac + 0x8 * V_3 + 0x4 * V_16 ,
F_6 ( V_2 , V_19 , 1 , V_16 ) ) ;
}
}
return 0 ;
}
void
F_10 ( struct V_1 * V_2 )
{
}
