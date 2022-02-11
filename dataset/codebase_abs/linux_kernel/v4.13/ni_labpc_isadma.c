static unsigned int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_5 )
{
struct V_6 * V_7 = & V_4 -> V_8 -> V_7 ;
unsigned int V_9 = F_2 ( V_4 ) ;
unsigned int V_10 ;
unsigned int V_11 ;
if ( V_7 -> V_12 == V_13 )
V_11 = 1000000000 / V_7 -> V_14 ;
else
V_11 = 0xffffffff ;
V_10 = ( V_11 / 3 ) * V_9 ;
if ( V_10 > V_5 )
V_10 = V_5 ;
else if ( V_10 < V_9 )
V_10 = V_9 ;
return V_10 ;
}
void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_18 * V_19 = & V_16 -> V_20 -> V_19 [ 0 ] ;
struct V_6 * V_7 = & V_4 -> V_8 -> V_7 ;
unsigned int V_9 = F_2 ( V_4 ) ;
V_19 -> V_10 = F_1 ( V_2 , V_4 , V_19 -> V_21 ) ;
if ( V_7 -> V_22 == V_23 &&
V_16 -> V_24 * V_9 < V_19 -> V_10 )
V_19 -> V_10 = V_16 -> V_24 * V_9 ;
F_4 ( V_19 ) ;
V_16 -> V_25 |= ( V_26 | V_27 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_18 * V_19 = & V_16 -> V_20 -> V_19 [ 0 ] ;
struct V_3 * V_4 = V_2 -> V_28 ;
struct V_29 * V_8 = V_4 -> V_8 ;
struct V_6 * V_7 = & V_8 -> V_7 ;
unsigned int V_30 = F_6 ( V_4 , V_19 -> V_10 ) ;
unsigned int V_31 ;
unsigned int V_32 ;
unsigned int V_33 ;
V_31 = F_7 ( V_19 -> V_34 ) ;
V_32 = V_30 - F_6 ( V_4 , V_31 ) ;
if ( V_7 -> V_22 == V_23 ) {
if ( V_16 -> V_24 <= V_32 ) {
V_32 = V_16 -> V_24 ;
V_33 = 0 ;
} else {
V_33 = V_16 -> V_24 - V_32 ;
if ( V_33 > V_30 )
V_33 = V_30 ;
}
V_16 -> V_24 -= V_32 ;
} else {
V_33 = V_30 ;
}
V_19 -> V_10 = F_8 ( V_4 , V_33 ) ;
F_9 ( V_4 , V_19 -> V_35 , V_32 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_18 * V_19 = & V_16 -> V_20 -> V_19 [ 0 ] ;
F_5 ( V_2 ) ;
if ( V_19 -> V_10 )
F_4 ( V_19 ) ;
V_16 -> V_36 ( V_2 , 0x1 , V_37 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
const struct V_38 * V_39 = V_2 -> V_40 ;
struct V_15 * V_16 = V_2 -> V_17 ;
if ( V_16 -> V_41 & V_42 ||
( V_39 -> V_43 && V_16 -> V_44 & V_45 ) )
F_10 ( V_2 ) ;
}
void F_12 ( struct V_1 * V_2 , unsigned int V_46 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
if ( V_46 != 1 && V_46 != 3 )
return;
V_16 -> V_20 = F_13 ( V_2 , 1 , V_46 , V_46 ,
V_47 ,
V_48 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
if ( V_16 )
F_15 ( V_16 -> V_20 ) ;
}
static int T_1 F_16 ( void )
{
return 0 ;
}
static void T_2 F_17 ( void )
{
}
