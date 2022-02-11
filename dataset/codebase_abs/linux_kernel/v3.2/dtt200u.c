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
static int F_5 ( struct V_1 * V_2 , T_3 * V_17 , int * V_18 )
{
T_1 V_19 [ 5 ] , V_20 = V_21 ;
F_6 ( V_2 , & V_20 , 1 , V_19 , 5 , 0 ) ;
F_7 ( V_2 , V_19 , V_17 , V_18 ) ;
if ( V_19 [ 0 ] != 0 )
F_8 ( L_1 , V_19 [ 0 ] , V_19 [ 1 ] , V_19 [ 2 ] , V_19 [ 3 ] , V_19 [ 4 ] ) ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 )
{
V_7 -> V_22 [ 0 ] . V_23 = F_10 ( V_7 -> V_12 ) ;
return 0 ;
}
static int F_11 ( struct V_24 * V_25 ,
const struct V_26 * V_27 )
{
if ( 0 == F_12 ( V_25 , & V_28 ,
V_29 , NULL , V_30 ) ||
0 == F_12 ( V_25 , & V_31 ,
V_29 , NULL , V_30 ) ||
0 == F_12 ( V_25 , & V_32 ,
V_29 , NULL , V_30 ) ||
0 == F_12 ( V_25 , & V_33 ,
V_29 , NULL , V_30 ) ||
0 == F_12 ( V_25 , & V_34 ,
V_29 , NULL , V_30 ) )
return 0 ;
return - V_35 ;
}
static int T_4 F_13 ( void )
{
int V_36 ;
if ( ( V_36 = F_14 ( & V_37 ) ) ) {
F_15 ( L_2 , V_36 ) ;
return V_36 ;
}
return 0 ;
}
static void T_5 F_16 ( void )
{
F_17 ( & V_37 ) ;
}
