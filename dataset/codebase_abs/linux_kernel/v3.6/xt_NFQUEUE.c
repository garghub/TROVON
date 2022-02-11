static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
return F_2 ( V_6 -> V_8 ) ;
}
static T_1 F_3 ( const struct V_1 * V_2 )
{
const struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( V_10 -> V_11 < V_10 -> V_12 )
return F_5 ( ( V_13 T_1 ) V_10 -> V_11 ,
( V_13 T_1 ) V_10 -> V_12 , V_10 -> V_14 , V_15 ) ;
return F_5 ( ( V_13 T_1 ) V_10 -> V_12 ,
( V_13 T_1 ) V_10 -> V_11 , V_10 -> V_14 , V_15 ) ;
}
static T_1 F_6 ( const struct V_1 * V_2 )
{
const struct V_16 * V_17 = F_7 ( V_2 ) ;
T_1 V_18 , V_19 , V_20 ;
if ( V_17 -> V_11 . V_21 [ 3 ] < V_17 -> V_12 . V_21 [ 3 ] ) {
V_18 = ( V_13 T_1 ) V_17 -> V_11 . V_21 [ 3 ] ;
V_19 = ( V_13 T_1 ) V_17 -> V_12 . V_21 [ 3 ] ;
} else {
V_19 = ( V_13 T_1 ) V_17 -> V_11 . V_21 [ 3 ] ;
V_18 = ( V_13 T_1 ) V_17 -> V_12 . V_21 [ 3 ] ;
}
if ( V_17 -> V_11 . V_21 [ 1 ] < V_17 -> V_12 . V_21 [ 1 ] )
V_20 = ( V_13 T_1 ) V_17 -> V_11 . V_21 [ 1 ] ;
else
V_20 = ( V_13 T_1 ) V_17 -> V_12 . V_21 [ 1 ] ;
return F_5 ( V_18 , V_19 , V_20 , V_15 ) ;
}
static unsigned int
F_8 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_22 * V_23 = V_4 -> V_7 ;
T_1 V_24 = V_23 -> V_8 ;
if ( V_23 -> V_25 > 1 ) {
if ( V_4 -> V_26 == V_27 )
V_24 = ( ( ( V_28 ) F_3 ( V_2 ) * V_23 -> V_25 ) >>
32 ) + V_24 ;
#if F_9 ( V_29 )
else if ( V_4 -> V_26 == V_30 )
V_24 = ( ( ( V_28 ) F_6 ( V_2 ) * V_23 -> V_25 ) >>
32 ) + V_24 ;
#endif
}
return F_2 ( V_24 ) ;
}
static unsigned int
F_10 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_31 * V_23 = V_4 -> V_7 ;
unsigned int V_32 = F_8 ( V_2 , V_4 ) ;
if ( V_23 -> V_33 )
V_32 |= V_34 ;
return V_32 ;
}
static int F_11 ( const struct V_35 * V_4 )
{
const struct V_31 * V_23 = V_4 -> V_7 ;
T_1 V_36 ;
if ( F_12 ( ! V_37 ) ) {
F_13 ( & V_15 , sizeof( V_15 ) ) ;
V_37 = true ;
}
if ( V_23 -> V_25 == 0 ) {
F_14 ( L_1 ) ;
return - V_38 ;
}
V_36 = V_23 -> V_25 - 1 + V_23 -> V_8 ;
if ( V_36 > 0xffff ) {
F_14 ( L_2 ,
V_23 -> V_25 , V_36 ) ;
return - V_39 ;
}
if ( V_4 -> V_40 -> V_41 == 2 && V_23 -> V_33 > 1 )
return - V_38 ;
return 0 ;
}
static int T_2 F_15 ( void )
{
return F_16 ( V_42 , F_17 ( V_42 ) ) ;
}
static void T_3 F_18 ( void )
{
F_19 ( V_42 , F_17 ( V_42 ) ) ;
}
