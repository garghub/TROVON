static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
return F_2 ( V_6 -> V_8 ) ;
}
static T_1 F_3 ( const struct V_1 * V_2 )
{
const struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( ( V_11 T_1 ) V_10 -> V_12 < ( V_11 T_1 ) V_10 -> V_13 )
return F_5 ( ( V_11 T_1 ) V_10 -> V_12 ,
( V_11 T_1 ) V_10 -> V_13 , V_10 -> V_14 , V_15 ) ;
return F_5 ( ( V_11 T_1 ) V_10 -> V_13 ,
( V_11 T_1 ) V_10 -> V_12 , V_10 -> V_14 , V_15 ) ;
}
static T_1 F_6 ( const struct V_1 * V_2 )
{
const struct V_16 * V_17 = F_7 ( V_2 ) ;
T_1 V_18 , V_19 , V_20 ;
if ( ( V_11 T_1 ) V_17 -> V_12 . V_21 [ 3 ] <
( V_11 T_1 ) V_17 -> V_13 . V_21 [ 3 ] ) {
V_18 = ( V_11 T_1 ) V_17 -> V_12 . V_21 [ 3 ] ;
V_19 = ( V_11 T_1 ) V_17 -> V_13 . V_21 [ 3 ] ;
} else {
V_19 = ( V_11 T_1 ) V_17 -> V_12 . V_21 [ 3 ] ;
V_18 = ( V_11 T_1 ) V_17 -> V_13 . V_21 [ 3 ] ;
}
if ( ( V_11 T_1 ) V_17 -> V_12 . V_21 [ 1 ] <
( V_11 T_1 ) V_17 -> V_13 . V_21 [ 1 ] )
V_20 = ( V_11 T_1 ) V_17 -> V_12 . V_21 [ 1 ] ;
else
V_20 = ( V_11 T_1 ) V_17 -> V_13 . V_21 [ 1 ] ;
return F_5 ( V_18 , V_19 , V_20 , V_15 ) ;
}
static T_1
F_8 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_22 * V_23 = V_4 -> V_7 ;
T_1 V_24 = V_23 -> V_8 ;
if ( V_4 -> V_25 == V_26 )
V_24 += ( ( V_27 ) F_3 ( V_2 ) * V_23 -> V_28 ) >> 32 ;
#if F_9 ( V_29 )
else if ( V_4 -> V_25 == V_30 )
V_24 += ( ( V_27 ) F_6 ( V_2 ) * V_23 -> V_28 ) >> 32 ;
#endif
return V_24 ;
}
static unsigned int
F_10 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_22 * V_23 = V_4 -> V_7 ;
T_1 V_24 = V_23 -> V_8 ;
if ( V_23 -> V_28 > 1 )
V_24 = F_8 ( V_2 , V_4 ) ;
return F_2 ( V_24 ) ;
}
static unsigned int
F_11 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_31 * V_23 = V_4 -> V_7 ;
unsigned int V_32 = F_10 ( V_2 , V_4 ) ;
if ( V_23 -> V_33 )
V_32 |= V_34 ;
return V_32 ;
}
static int F_12 ( const struct V_35 * V_4 )
{
const struct V_36 * V_23 = V_4 -> V_7 ;
T_1 V_37 ;
if ( F_13 ( ! V_38 ) ) {
F_14 ( & V_15 , sizeof( V_15 ) ) ;
V_38 = true ;
}
if ( V_23 -> V_28 == 0 ) {
F_15 ( L_1 ) ;
return - V_39 ;
}
V_37 = V_23 -> V_28 - 1 + V_23 -> V_8 ;
if ( V_37 > 0xffff ) {
F_15 ( L_2 ,
V_23 -> V_28 , V_37 ) ;
return - V_40 ;
}
if ( V_4 -> V_41 -> V_42 == 2 && V_23 -> V_43 > 1 )
return - V_39 ;
if ( V_4 -> V_41 -> V_42 == 3 && V_23 -> V_43 & ~ V_44 )
return - V_39 ;
return 0 ;
}
static unsigned int
F_16 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_36 * V_23 = V_4 -> V_7 ;
T_1 V_24 = V_23 -> V_8 ;
if ( V_23 -> V_28 > 1 ) {
if ( V_23 -> V_43 & V_45 ) {
int V_46 = F_17 () ;
V_24 = V_23 -> V_8 + V_46 % V_23 -> V_28 ;
} else
V_24 = F_8 ( V_2 , V_4 ) ;
}
return F_2 ( V_24 ) ;
}
static int T_2 F_18 ( void )
{
return F_19 ( V_47 , F_20 ( V_47 ) ) ;
}
static void T_3 F_21 ( void )
{
F_22 ( V_47 , F_20 ( V_47 ) ) ;
}
