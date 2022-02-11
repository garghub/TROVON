void
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 , T_1 V_5 , T_1 V_6 ,
T_1 V_7 , struct V_8 * V_9 )
{
if ( ! ( V_7 & 4 ) ) {
V_9 -> V_4 = ( 0 << 4 ) ;
} else {
if ( V_2 -> V_10 -> V_9 . V_11 )
V_2 -> V_10 -> V_9 . V_11 ( V_2 , V_3 , V_5 , V_7 , V_9 ) ;
V_9 -> V_4 = ( 1 << 4 ) ;
}
V_9 -> V_4 |= 0x00000001 ;
V_9 -> V_4 |= V_4 ;
V_9 -> V_12 = F_2 ( 1u , V_4 + V_5 ) - 1 ;
V_9 -> V_6 = V_6 ;
}
static void
F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_5 , T_1 V_7 ,
struct V_8 * V_9 )
{
T_1 V_13 = F_4 ( V_5 , 0x40 ) ;
T_1 V_14 = F_5 ( V_13 / V_2 -> V_15 -> V_16 , 0x40 ) ;
if ( ! F_6 ( & V_2 -> V_15 -> V_14 , 0 , 1 , V_14 , V_14 , 1 , & V_9 -> V_17 ) ) {
if ( V_7 & 2 ) V_9 -> V_18 |= 0x01000000 ;
else V_9 -> V_18 |= 0x02000000 ;
V_9 -> V_18 |= ( ( V_9 -> V_17 -> V_19 ) >> 6 ) ;
V_9 -> V_18 |= ( ( V_9 -> V_17 -> V_19 + V_14 - 1 ) >> 6 ) << 12 ;
#ifdef F_7
V_9 -> V_18 |= 0x10000000 ;
#endif
}
}
static int
F_8 ( struct V_1 * V_2 , int V_20 , int V_3 , int V_21 )
{
struct V_22 * V_23 = V_2 -> V_24 . V_23 ;
int V_25 = ( V_23 -> V_26 > 0x30 ?
F_9 ( V_23 , 0x122c + 0x10 * V_20 + 0x4 * V_21 ) >>
( 4 * ( V_3 ^ 1 ) ) :
0 ) & 0xf ;
return 2 * ( V_25 & 0x8 ? V_25 - 0x10 : V_25 ) ;
}
static int
F_10 ( struct V_1 * V_2 , int V_27 , int V_20 , int V_3 )
{
int V_21 , V_28 = 0 ;
for ( V_21 = 0 ; V_21 < 4 ; V_21 ++ ) {
int V_29 = ( V_27 >> ( 8 * V_3 ) & 0xff ) + F_8 ( V_2 , V_20 , V_3 , V_21 ) ;
V_28 |= ( 0x80 | F_11 ( V_29 , 0 , 0x1f ) ) << ( 8 * V_21 ) ;
}
return V_28 ;
}
void
F_12 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_24 . V_23 ;
int V_3 , V_21 ;
if ( V_23 -> V_26 == 0x30 ||
V_23 -> V_26 == 0x31 ||
V_23 -> V_26 == 0x35 ) {
int V_30 = ( V_23 -> V_26 == 0x31 ? 2 : 4 ) ;
int V_27 = F_9 ( V_23 , 0x1003d0 ) ;
for ( V_3 = 0 ; V_3 < V_30 ; V_3 ++ ) {
for ( V_21 = 0 ; V_21 < 3 ; V_21 ++ )
F_13 ( V_23 , 0x10037c + 0xc * V_3 + 0x4 * V_21 ,
F_10 ( V_2 , V_27 , 0 , V_21 ) ) ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ )
F_13 ( V_23 , 0x1003ac + 0x8 * V_3 + 0x4 * V_21 ,
F_10 ( V_2 , V_27 , 1 , V_21 ) ) ;
}
}
}
int
F_14 ( struct V_22 * V_23 , int V_31 , struct V_1 * * V_32 )
{
return F_15 ( & V_33 , V_23 , V_31 , V_32 ) ;
}
