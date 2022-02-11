static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 = 0 ;
V_9 -> V_12 = V_13 ;
if ( V_7 [ 0 ] == V_14 ) {
V_11 = F_2 ( V_9 -> V_15 + V_16 ) ;
V_11 = V_11 & 0xFFFFF9FEUL ;
F_3 ( V_11 , V_9 -> V_15 + V_16 ) ;
V_9 -> V_17 = V_14 ;
if ( V_7 [ 1 ] == 1 ) {
F_3 ( 0x02 , V_9 -> V_15 + V_16 ) ;
F_3 ( 0x0 , V_9 -> V_15 + V_18 ) ;
F_3 ( 0x0 , V_9 -> V_15 + V_19 ) ;
F_3 ( 0x0 , V_9 -> V_15 + V_20 ) ;
F_3 ( 0x0 , V_2 -> V_21 +
F_4 ( V_22 ) ) ;
F_3 ( 0x0 , V_2 -> V_21 +
F_4 ( V_23 ) ) ;
F_3 ( 0x0 , V_2 -> V_21 +
F_4 ( V_24 ) ) ;
F_3 ( 0x0 , V_2 -> V_21 +
F_4 ( V_25 ) ) ;
} else {
F_3 ( 0x0 , V_9 -> V_15 + V_16 ) ;
}
F_3 ( V_7 [ 2 ] , V_9 -> V_15 + V_26 ) ;
F_3 ( V_7 [ 3 ] , V_9 -> V_15 + V_27 ) ;
V_11 = F_2 ( V_9 -> V_15 + V_16 ) ;
V_11 = ( V_11 & 0xFFF719E2UL ) | 2UL << 13UL | 0x10UL ;
F_3 ( V_11 , V_9 -> V_15 + V_16 ) ;
} else if ( V_7 [ 0 ] == V_28 ) {
V_9 -> V_17 = V_28 ;
V_9 -> V_29 = V_7 [ 5 ] ;
V_11 = F_2 ( V_2 -> V_21 +
F_5 ( V_7 [ 5 ] - 1 ) ) ;
V_11 = V_11 & 0xFFFFF9FEUL ;
F_3 ( V_11 , V_2 -> V_21 +
F_5 ( V_7 [ 5 ] - 1 ) ) ;
F_3 ( V_7 [ 3 ] , V_2 -> V_21 +
F_6 ( V_7 [ 5 ] - 1 ) ) ;
V_11 =
( V_11 & 0xFFFC19E2UL ) | 0x80000UL |
( unsigned int ) ( ( unsigned int ) V_7 [ 4 ] << 16UL ) ;
F_3 ( V_11 , V_2 -> V_21 +
F_5 ( V_7 [ 5 ] - 1 ) ) ;
V_11 = ( V_11 & 0xFFFFF9FD ) | ( V_7 [ 1 ] << 1 ) ;
F_3 ( V_11 , V_2 -> V_21 +
F_5 ( V_7 [ 5 ] - 1 ) ) ;
V_11 = ( V_11 & 0xFFFBF9FFUL ) | ( V_7 [ 6 ] << 18 ) ;
F_3 ( V_11 , V_2 -> V_21 +
F_5 ( V_7 [ 5 ] - 1 ) ) ;
} else {
F_7 ( V_2 -> V_30 , L_1 ) ;
}
return V_6 -> V_31 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 = 0 ;
if ( V_9 -> V_17 == V_14 ) {
if ( V_7 [ 1 ] == 1 ) {
V_11 = F_2 ( V_9 -> V_15 + V_16 ) ;
V_11 = ( V_11 & 0xFFFFF9FFUL ) | 0x1UL ;
F_3 ( V_11 , V_9 -> V_15 + V_16 ) ;
} else if ( V_7 [ 1 ] == 0 ) {
V_11 = F_2 ( V_9 -> V_15 + V_16 ) ;
V_11 = V_11 & 0xFFFFF9FEUL ;
F_3 ( V_11 , V_9 -> V_15 + V_16 ) ;
}
} else if ( V_9 -> V_17 == V_28 ) {
V_11 =
F_2 ( V_2 -> V_21 +
F_5 ( V_9 -> V_29 - 1 ) ) ;
if ( V_7 [ 1 ] == 1 ) {
V_11 = ( V_11 & 0xFFFFF9FFUL ) | 0x1UL ;
} else if ( V_7 [ 1 ] == 0 ) {
V_11 = 0 ;
} else if ( V_7 [ 1 ] == 2 ) {
V_11 = ( V_11 & 0xFFFFF9FFUL ) | 0x400 ;
}
F_3 ( V_11 , V_2 -> V_21 +
F_5 ( V_9 -> V_29 - 1 ) ) ;
} else {
F_7 ( V_2 -> V_30 , L_1 ) ;
}
return V_6 -> V_31 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 = 0 ;
if ( V_9 -> V_17 == V_14 ) {
V_7 [ 0 ] = F_2 ( V_9 -> V_15 + V_32 ) & 0x1 ;
V_7 [ 1 ] = F_2 ( V_9 -> V_15 + V_33 ) ;
} else if ( V_9 -> V_17 == V_28 ) {
V_7 [ 0 ] =
F_2 ( V_2 -> V_21 +
F_10 ( V_9 -> V_29 - 1 ) ) ;
V_11 =
F_2 ( V_2 -> V_21 +
F_11 ( V_9 -> V_29 - 1 ) ) ;
V_7 [ 1 ] = ( unsigned char ) ( ( V_11 >> 1 ) & 1 ) ;
V_7 [ 2 ] = ( unsigned char ) ( ( V_11 >> 2 ) & 1 ) ;
V_7 [ 3 ] = ( unsigned char ) ( ( V_11 >> 3 ) & 1 ) ;
V_7 [ 4 ] = ( unsigned char ) ( ( V_11 >> 0 ) & 1 ) ;
} else {
F_7 ( V_2 -> V_30 , L_1 ) ;
}
return V_6 -> V_31 ;
}
