static int F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 = V_5 ;
if ( V_3 )
F_2 ( V_2 , & V_4 , 2 ) ;
return 0 ;
}
static int F_3 ( struct V_6 * V_7 , int V_3 )
{
T_1 V_8 [ 2 ] = { V_9 , V_3 } ;
T_1 V_10 = V_11 ;
F_2 ( V_7 -> V_12 , V_8 , 2 ) ;
if ( V_3 == 0 )
F_2 ( V_7 -> V_12 , & V_10 , 1 ) ;
return 0 ;
}
static int F_4 ( struct V_6 * V_7 , int V_13 , T_2 V_14 , int V_3 )
{
T_1 V_15 [ 4 ] ;
V_14 = V_3 ? V_14 : 0 ;
V_15 [ 0 ] = V_16 ;
V_15 [ 1 ] = V_13 ;
V_15 [ 2 ] = V_14 & 0xff ;
V_15 [ 3 ] = ( V_14 >> 8 ) & 0x1f ;
return F_2 ( V_7 -> V_12 , V_15 , 4 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 V_17 [ 5 ] , V_18 = V_19 ;
T_3 V_20 ;
F_6 ( V_2 , & V_18 , 1 , V_17 , 5 , 0 ) ;
if ( V_17 [ 0 ] == 1 ) {
V_20 = V_17 [ 1 ] ;
if ( ( T_1 ) ~ V_17 [ 1 ] != V_17 [ 2 ] ) {
V_20 = V_20 << 8 ;
V_20 |= V_17 [ 2 ] ;
}
V_20 = V_20 << 8 ;
V_20 |= V_17 [ 3 ] ;
if ( ( T_1 ) ~ V_17 [ 3 ] == V_17 [ 4 ] )
F_7 ( V_2 -> V_21 , V_22 , V_20 , 0 ) ;
else
F_8 ( V_2 -> V_21 ) ;
} else if ( V_17 [ 0 ] == 2 ) {
F_9 ( V_2 -> V_21 ) ;
} else {
F_8 ( V_2 -> V_21 ) ;
}
if ( V_17 [ 0 ] != 0 )
F_10 ( L_1 , 5 , V_17 ) ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 )
{
V_7 -> V_23 [ 0 ] . V_24 = F_12 ( V_7 -> V_12 ) ;
return 0 ;
}
static int F_13 ( struct V_25 * V_26 ,
const struct V_27 * V_28 )
{
if ( 0 == F_14 ( V_26 , & V_29 ,
V_30 , NULL , V_31 ) ||
0 == F_14 ( V_26 , & V_32 ,
V_30 , NULL , V_31 ) ||
0 == F_14 ( V_26 , & V_33 ,
V_30 , NULL , V_31 ) ||
0 == F_14 ( V_26 , & V_34 ,
V_30 , NULL , V_31 ) ||
0 == F_14 ( V_26 , & V_35 ,
V_30 , NULL , V_31 ) )
return 0 ;
return - V_36 ;
}
