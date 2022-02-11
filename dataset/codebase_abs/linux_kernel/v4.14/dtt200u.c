static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 = 0 ;
F_2 ( & V_2 -> V_8 ) ;
V_5 -> V_9 [ 0 ] = V_10 ;
if ( V_3 )
V_7 = F_3 ( V_2 , V_5 -> V_9 , 2 ) ;
F_4 ( & V_2 -> V_8 ) ;
return V_7 ;
}
static int F_5 ( struct V_11 * V_12 , int V_3 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
F_2 ( & V_2 -> V_8 ) ;
V_5 -> V_9 [ 0 ] = V_14 ;
V_5 -> V_9 [ 1 ] = V_3 ;
V_7 = F_3 ( V_12 -> V_13 , V_5 -> V_9 , 2 ) ;
if ( V_7 < 0 )
goto V_7;
if ( V_3 )
goto V_7;
V_5 -> V_9 [ 0 ] = V_15 ;
V_7 = F_3 ( V_12 -> V_13 , V_5 -> V_9 , 1 ) ;
V_7:
F_4 ( & V_2 -> V_8 ) ;
return V_7 ;
}
static int F_6 ( struct V_11 * V_12 , int V_16 , T_1 V_17 , int V_3 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
V_17 = V_3 ? V_17 : 0 ;
F_2 ( & V_2 -> V_8 ) ;
V_5 -> V_9 [ 0 ] = V_18 ;
V_5 -> V_9 [ 1 ] = V_16 ;
V_5 -> V_9 [ 2 ] = V_17 & 0xff ;
V_5 -> V_9 [ 3 ] = ( V_17 >> 8 ) & 0x1f ;
V_7 = F_3 ( V_12 -> V_13 , V_5 -> V_9 , 4 ) ;
F_4 ( & V_2 -> V_8 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_19 ;
int V_7 ;
F_2 ( & V_2 -> V_8 ) ;
V_5 -> V_9 [ 0 ] = V_20 ;
V_7 = F_8 ( V_2 , V_5 -> V_9 , 1 , V_5 -> V_9 , 5 , 0 ) ;
if ( V_7 < 0 )
goto V_7;
if ( V_5 -> V_9 [ 0 ] == 1 ) {
enum V_21 V_22 = V_23 ;
V_19 = V_5 -> V_9 [ 1 ] ;
if ( ( V_24 ) ~ V_5 -> V_9 [ 1 ] != V_5 -> V_9 [ 2 ] ) {
V_19 = V_19 << 8 ;
V_19 |= V_5 -> V_9 [ 2 ] ;
V_22 = V_25 ;
}
V_19 = V_19 << 8 ;
V_19 |= V_5 -> V_9 [ 3 ] ;
if ( ( V_24 ) ~ V_5 -> V_9 [ 3 ] == V_5 -> V_9 [ 4 ] )
F_9 ( V_2 -> V_26 , V_22 , V_19 , 0 ) ;
else
F_10 ( V_2 -> V_26 ) ;
} else if ( V_5 -> V_9 [ 0 ] == 2 ) {
F_11 ( V_2 -> V_26 ) ;
} else {
F_10 ( V_2 -> V_26 ) ;
}
if ( V_5 -> V_9 [ 0 ] != 0 )
F_12 ( L_1 , 5 , V_5 -> V_9 ) ;
V_7:
F_4 ( & V_2 -> V_8 ) ;
return V_7 ;
}
static int F_13 ( struct V_11 * V_12 )
{
V_12 -> V_27 [ 0 ] . V_28 = F_14 ( V_12 -> V_13 ) ;
return 0 ;
}
static int F_15 ( struct V_29 * V_30 ,
const struct V_31 * V_32 )
{
if ( 0 == F_16 ( V_30 , & V_33 ,
V_34 , NULL , V_35 ) ||
0 == F_16 ( V_30 , & V_36 ,
V_34 , NULL , V_35 ) ||
0 == F_16 ( V_30 , & V_37 ,
V_34 , NULL , V_35 ) ||
0 == F_16 ( V_30 , & V_38 ,
V_34 , NULL , V_35 ) ||
0 == F_16 ( V_30 , & V_39 ,
V_34 , NULL , V_35 ) )
return 0 ;
return - V_40 ;
}
