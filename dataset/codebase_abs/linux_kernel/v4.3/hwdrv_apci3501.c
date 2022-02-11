static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 ;
if ( V_7 [ 0 ] != V_12 &&
V_7 [ 0 ] != V_13 )
return - V_14 ;
V_9 -> V_15 = V_16 ;
V_9 -> V_17 = V_7 [ 0 ] ;
if ( V_9 -> V_17 == V_12 ) {
V_11 = 0 ;
} else {
V_11 = F_2 ( V_9 -> V_18 + V_19 ) ;
V_11 &= ~ ( V_20 | V_21 |
V_22 ) ;
}
F_3 ( V_11 , V_9 -> V_18 + V_19 ) ;
V_11 = ( V_7 [ 1 ] == 1 ) ? V_23 : 0 ;
F_3 ( V_11 , V_9 -> V_18 + V_19 ) ;
F_3 ( V_7 [ 2 ] , V_9 -> V_18 + V_24 ) ;
F_3 ( V_7 [ 3 ] , V_9 -> V_18 + V_25 ) ;
V_11 = F_2 ( V_9 -> V_18 + V_19 ) ;
if ( V_9 -> V_17 == V_12 ) {
V_11 |= ~ ( V_26 | V_27 |
V_28 | V_20 |
V_21 | V_29 |
V_30 | V_31 |
V_23 | V_22 ) ;
} else {
V_11 &= ~ ( V_32 | V_28 |
V_20 | V_21 |
V_29 | V_30 |
V_31 | V_22 ) ;
V_11 |= F_4 ( 2 ) | V_29 ;
}
F_3 ( V_11 , V_9 -> V_18 + V_19 ) ;
return V_6 -> V_33 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 ;
if ( V_9 -> V_17 == V_12 ||
V_9 -> V_17 == V_13 ) {
V_11 = F_2 ( V_9 -> V_18 + V_19 ) ;
V_11 &= ~ ( V_20 | V_21 ) ;
if ( V_7 [ 1 ] == 1 ) {
V_11 |= V_22 ;
} else if ( V_7 [ 1 ] == 0 ) {
if ( V_9 -> V_17 == V_12 )
V_11 = 0 ;
else
V_11 &= ~ V_22 ;
} else if ( V_7 [ 1 ] == 2 ) {
V_11 |= V_21 ;
}
F_3 ( V_11 , V_9 -> V_18 + V_19 ) ;
}
F_2 ( V_9 -> V_18 + V_34 ) ;
return V_6 -> V_33 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 -> V_17 != V_13 &&
V_9 -> V_17 != V_12 )
return - V_14 ;
V_7 [ 0 ] = F_2 ( V_9 -> V_18 + V_34 ) &
V_35 ;
V_7 [ 1 ] = F_2 ( V_9 -> V_18 + V_36 ) ;
return V_6 -> V_33 ;
}
