void
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 , T_1 V_5 , T_1 V_6 ,
T_1 V_7 , struct V_8 * V_9 )
{
if ( ! ( V_7 & 4 ) ) {
V_9 -> V_4 = ( 0 << 4 ) ;
} else {
if ( V_2 -> V_9 . V_10 )
V_2 -> V_9 . V_10 ( V_2 , V_3 , V_5 , V_7 , V_9 ) ;
V_9 -> V_4 = ( 1 << 4 ) ;
}
V_9 -> V_4 |= 0x00000001 ;
V_9 -> V_4 |= V_4 ;
V_9 -> V_11 = F_2 ( 1u , V_4 + V_5 ) - 1 ;
V_9 -> V_6 = V_6 ;
}
static void
F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_5 , T_1 V_7 ,
struct V_8 * V_9 )
{
T_1 V_12 = F_4 ( V_5 , 0x40 ) ;
T_1 V_13 = F_5 ( V_12 / V_2 -> V_14 -> V_15 , 0x40 ) ;
if ( ! F_6 ( & V_2 -> V_13 , 1 , V_13 , V_13 , 1 , & V_9 -> V_16 ) ) {
if ( V_7 & 2 ) V_9 -> V_17 |= 0x01000000 ;
else V_9 -> V_17 |= 0x02000000 ;
V_9 -> V_17 |= ( ( V_9 -> V_16 -> V_18 ) >> 6 ) ;
V_9 -> V_17 |= ( ( V_9 -> V_16 -> V_18 + V_13 - 1 ) >> 6 ) << 12 ;
#ifdef F_7
V_9 -> V_17 |= 0x10000000 ;
#endif
}
}
static int
F_8 ( struct V_19 * V_20 , int V_21 , int V_3 , int V_22 )
{
struct V_23 * V_24 = F_9 ( V_20 ) ;
int V_25 = ( V_24 -> V_26 > 0x30 ?
F_10 ( V_20 , 0x122c + 0x10 * V_21 + 0x4 * V_22 ) >> ( 4 * ( V_3 ^ 1 ) ) :
0 ) & 0xf ;
return 2 * ( V_25 & 0x8 ? V_25 - 0x10 : V_25 ) ;
}
static int
F_11 ( struct V_19 * V_20 , int V_27 , int V_21 , int V_3 )
{
int V_22 , V_28 = 0 ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
int V_29 = ( V_27 >> ( 8 * V_3 ) & 0xff ) + F_8 ( V_20 , V_21 , V_3 , V_22 ) ;
V_28 |= ( 0x80 | F_12 ( V_29 , 0 , 0x1f ) ) << ( 8 * V_22 ) ;
}
return V_28 ;
}
int
F_13 ( struct V_30 * V_31 )
{
struct V_23 * V_24 = F_9 ( V_31 ) ;
struct V_19 * V_20 = ( void * ) V_31 ;
int V_32 , V_3 , V_22 ;
V_32 = F_14 ( & V_20 -> V_33 ) ;
if ( V_32 )
return V_32 ;
if ( V_24 -> V_26 == 0x30 ||
V_24 -> V_26 == 0x31 ||
V_24 -> V_26 == 0x35 ) {
int V_34 = ( V_24 -> V_26 == 0x31 ? 2 : 4 ) ;
int V_27 = F_10 ( V_20 , 0x1003d0 ) ;
for ( V_3 = 0 ; V_3 < V_34 ; V_3 ++ ) {
for ( V_22 = 0 ; V_22 < 3 ; V_22 ++ )
F_15 ( V_20 , 0x10037c + 0xc * V_3 + 0x4 * V_22 ,
F_11 ( V_20 , V_27 , 0 , V_22 ) ) ;
for ( V_22 = 0 ; V_22 < 2 ; V_22 ++ )
F_15 ( V_20 , 0x1003ac + 0x8 * V_3 + 0x4 * V_22 ,
F_11 ( V_20 , V_27 , 1 , V_22 ) ) ;
}
}
return 0 ;
}
static int
F_16 ( struct V_30 * V_35 , struct V_30 * V_36 ,
struct V_37 * V_38 , void * V_39 , T_1 V_5 ,
struct V_30 * * V_40 )
{
struct V_19 * V_20 ;
int V_32 ;
V_32 = F_17 ( V_35 , V_36 , V_38 , & V_41 , & V_20 ) ;
* V_40 = F_18 ( V_20 ) ;
if ( V_32 )
return V_32 ;
V_20 -> V_33 . V_42 = V_43 ;
V_20 -> V_33 . V_9 . V_44 = 8 ;
V_20 -> V_33 . V_9 . V_45 = F_1 ;
V_20 -> V_33 . V_9 . V_10 = F_3 ;
V_20 -> V_33 . V_9 . V_46 = V_47 ;
V_20 -> V_33 . V_9 . V_48 = V_49 ;
return 0 ;
}
