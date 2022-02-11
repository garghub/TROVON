static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 = 0 ;
V_9 -> V_12 = V_13 ;
if ( V_7 [ 0 ] == V_14 ) {
V_9 -> V_15 = V_14 ;
F_2 ( 0x0 , V_2 -> V_16 + V_17 ) ;
if ( V_7 [ 1 ] == 1 ) {
F_2 ( 0x02 , V_2 -> V_16 + V_17 ) ;
} else {
F_2 ( 0x0 , V_2 -> V_16 + V_17 ) ;
}
F_2 ( V_7 [ 2 ] , V_2 -> V_16 + V_18 ) ;
F_2 ( V_7 [ 3 ] , V_2 -> V_16 + V_19 ) ;
V_11 = F_3 ( V_2 -> V_16 + V_17 ) | 0xFFF819E0UL ;
F_2 ( V_11 , V_2 -> V_16 + V_17 ) ;
}
else if ( V_7 [ 0 ] == V_20 ) {
V_11 = F_3 ( V_2 -> V_16 + V_17 ) ;
V_11 = V_11 & 0xFFFFF9FEUL ;
F_2 ( V_11 , V_2 -> V_16 + V_17 ) ;
V_9 -> V_15 = V_20 ;
if ( V_7 [ 1 ] == 1 ) {
F_2 ( 0x02 , V_2 -> V_16 + V_17 ) ;
} else {
F_2 ( 0x0 , V_2 -> V_16 + V_17 ) ;
}
F_2 ( V_7 [ 2 ] , V_2 -> V_16 + V_18 ) ;
F_2 ( V_7 [ 3 ] , V_2 -> V_16 + V_19 ) ;
V_11 = F_3 ( V_2 -> V_16 + V_17 ) ;
V_11 =
( V_11 & 0xFFF719E2UL ) | 2UL << 13UL | 0x10UL ;
F_2 ( V_11 , V_2 -> V_16 + V_17 ) ;
}
return V_6 -> V_21 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 = 0 ;
int V_22 ;
if ( V_9 -> V_15 == V_14 ) {
if ( V_7 [ 1 ] == 1 ) {
V_11 = F_3 ( V_2 -> V_16 + V_17 ) ;
V_11 = ( V_11 & 0xFFFFF9FFUL ) | 0x1UL ;
F_2 ( V_11 , V_2 -> V_16 + V_17 ) ;
} else if ( V_7 [ 1 ] == 0 ) {
V_11 = F_3 ( V_2 -> V_16 + V_17 ) ;
V_11 = V_11 & 0xFFFFF9FEUL ;
F_2 ( 0x0 , V_2 -> V_16 + V_17 ) ;
} else if ( V_7 [ 1 ] == 2 ) {
V_11 = F_3 ( V_2 -> V_16 + V_17 ) ;
V_11 = ( V_11 & 0xFFFFF9FFUL ) | 0x200UL ;
F_2 ( V_11 , V_2 -> V_16 + V_17 ) ;
}
}
if ( V_9 -> V_15 == V_20 ) {
if ( V_7 [ 1 ] == 1 ) {
V_11 = F_3 ( V_2 -> V_16 + V_17 ) ;
V_11 = ( V_11 & 0xFFFFF9FFUL ) | 0x1UL ;
F_2 ( V_11 , V_2 -> V_16 + V_17 ) ;
} else if ( V_7 [ 1 ] == 0 ) {
V_11 = F_3 ( V_2 -> V_16 + V_17 ) ;
V_11 = V_11 & 0xFFFFF9FEUL ;
F_2 ( V_11 , V_2 -> V_16 + V_17 ) ;
}
else if ( V_7 [ 1 ] == 2 ) {
V_11 = F_3 ( V_2 -> V_16 + V_17 ) ;
V_11 = ( V_11 & 0xFFFFF9FFUL ) | 0x200UL ;
F_2 ( V_11 , V_2 -> V_16 + V_17 ) ;
}
}
V_22 = F_3 ( V_2 -> V_16 + V_23 ) & 0x1 ;
return V_6 -> V_21 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 -> V_15 == V_14 ) {
V_7 [ 0 ] = F_3 ( V_2 -> V_16 + V_23 ) & 0x1 ;
V_7 [ 1 ] = F_3 ( V_2 -> V_16 + V_24 ) ;
}
else if ( V_9 -> V_15 == V_20 ) {
V_7 [ 0 ] = F_3 ( V_2 -> V_16 + V_23 ) & 0x1 ;
V_7 [ 1 ] = F_3 ( V_2 -> V_16 + V_24 ) ;
}
else if ( ( V_9 -> V_15 != V_20 )
&& ( V_9 -> V_15 != V_14 ) ) {
F_6 ( V_2 -> V_25 , L_1 ) ;
}
return V_6 -> V_21 ;
}
