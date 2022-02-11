static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
return F_2 ( V_6 -> V_8 ) ;
}
static T_1 F_3 ( const struct V_1 * V_2 )
{
const struct V_9 * V_10 = F_4 ( V_2 ) ;
T_2 V_11 ;
V_11 = V_10 -> V_12 ^ V_10 -> V_13 ;
return F_5 ( ( V_14 T_1 ) V_11 , V_10 -> V_15 , V_16 ) ;
}
static T_1 F_6 ( const struct V_1 * V_2 )
{
const struct V_17 * V_18 = F_7 ( V_2 ) ;
T_2 V_19 [ 4 ] ;
V_19 [ 0 ] = V_18 -> V_12 . V_20 [ 0 ] ^ V_18 -> V_13 . V_20 [ 0 ] ;
V_19 [ 1 ] = V_18 -> V_12 . V_20 [ 1 ] ^ V_18 -> V_13 . V_20 [ 1 ] ;
V_19 [ 2 ] = V_18 -> V_12 . V_20 [ 2 ] ^ V_18 -> V_13 . V_20 [ 2 ] ;
V_19 [ 3 ] = V_18 -> V_12 . V_20 [ 3 ] ^ V_18 -> V_13 . V_20 [ 3 ] ;
return F_8 ( ( V_14 T_1 * ) V_19 , F_9 ( V_19 ) , V_16 ) ;
}
static unsigned int
F_10 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_21 * V_22 = V_4 -> V_7 ;
T_1 V_23 = V_22 -> V_8 ;
if ( V_22 -> V_24 > 1 ) {
if ( V_4 -> V_25 == V_26 )
V_23 = ( ( ( V_27 ) F_3 ( V_2 ) * V_22 -> V_24 ) >>
32 ) + V_23 ;
#if F_11 ( V_28 )
else if ( V_4 -> V_25 == V_29 )
V_23 = ( ( ( V_27 ) F_6 ( V_2 ) * V_22 -> V_24 ) >>
32 ) + V_23 ;
#endif
}
return F_2 ( V_23 ) ;
}
static unsigned int
F_12 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_30 * V_22 = V_4 -> V_7 ;
unsigned int V_31 = F_10 ( V_2 , V_4 ) ;
if ( V_22 -> V_32 )
V_31 |= V_33 ;
return V_31 ;
}
static int F_13 ( const struct V_34 * V_4 )
{
const struct V_30 * V_22 = V_4 -> V_7 ;
T_1 V_35 ;
if ( F_14 ( ! V_36 ) ) {
F_15 ( & V_16 , sizeof( V_16 ) ) ;
V_36 = true ;
}
if ( V_22 -> V_24 == 0 ) {
F_16 ( L_1 ) ;
return - V_37 ;
}
V_35 = V_22 -> V_24 - 1 + V_22 -> V_8 ;
if ( V_35 > 0xffff ) {
F_16 ( L_2 ,
V_22 -> V_24 , V_35 ) ;
return - V_38 ;
}
if ( V_4 -> V_39 -> V_40 == 2 && V_22 -> V_32 > 1 )
return - V_37 ;
return 0 ;
}
static int T_3 F_17 ( void )
{
return F_18 ( V_41 , F_9 ( V_41 ) ) ;
}
static void T_4 F_19 ( void )
{
F_20 ( V_41 , F_9 ( V_41 ) ) ;
}
