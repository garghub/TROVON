static int F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
T_1 V_4 , T_2 V_5 , T_1 * V_6 , int V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 V_11 ;
struct V_12 V_13 [ 2 ] ;
T_1 * V_14 = & V_3 [ 0 ] ;
T_1 * V_15 = & V_3 [ V_16 ] ;
int V_17 ;
int V_18 ;
if ( V_7 > V_19 ) {
F_3 ( V_2 , L_1 ,
V_20 , V_7 ) ;
return - V_21 ;
}
memset ( V_14 , 0 , V_16 ) ;
memset ( V_15 , 0 , V_16 ) ;
V_14 [ 0 ] = 0x00 ;
V_14 [ 1 ] = 0xFF ;
V_14 [ 2 ] = V_5 ;
V_14 [ 3 ] = V_4 ;
if ( V_4 == V_22 )
memcpy ( V_14 + V_23 , V_6 , V_7 ) ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
F_4 ( & V_11 ) ;
V_13 [ 0 ] . V_24 = V_14 ;
V_13 [ 0 ] . V_25 = V_15 ;
switch ( V_4 ) {
case V_22 :
V_13 [ 0 ] . V_26 = V_7 + V_23 ;
F_5 ( & V_13 [ 0 ] , & V_11 ) ;
break;
case V_27 :
V_13 [ 0 ] . V_26 = V_23 ;
F_5 ( & V_13 [ 0 ] , & V_11 ) ;
V_13 [ 1 ] . V_25 = V_6 ;
V_13 [ 1 ] . V_26 = V_7 ;
F_5 ( & V_13 [ 1 ] , & V_11 ) ;
break;
default:
F_3 ( V_2 , L_2 , V_20 , V_4 ) ;
return - V_21 ;
}
V_17 = F_6 ( V_9 , & V_11 ) ;
if ( V_17 < 0 ) {
F_7 ( V_2 , L_3 ,
V_20 , V_17 , V_13 [ 1 ] . V_26 , V_4 ) ;
}
if ( V_15 [ V_28 ] != V_29 ||
V_15 [ V_28 + 1 ] != V_30 ) {
F_7 ( V_2 , L_4 , V_20 , V_4 ) ;
for ( V_18 = 0 ; V_18 < V_23 ; V_18 ++ )
F_7 ( V_2 , L_5 ,
V_20 , V_18 , V_15 [ V_18 ] ) ;
for ( V_18 = 0 ; V_18 < V_7 ; V_18 ++ )
F_7 ( V_2 , L_6 ,
V_20 , V_18 , V_6 [ V_18 ] ) ;
return - V_31 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_32 , T_1 V_7 , void * V_33 )
{
return F_1 ( V_2 , V_3 , V_27 , V_32 , V_33 ,
V_7 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_32 , T_1 V_7 , const void * V_33 )
{
return F_1 ( V_2 , V_3 , V_22 , V_32 , ( void * ) V_33 ,
V_7 ) ;
}
static int F_10 ( struct V_8 * V_9 )
{
struct V_34 * V_35 ;
int error ;
V_9 -> V_36 = V_37 ;
V_9 -> V_38 = V_39 ;
error = F_11 ( V_9 ) ;
if ( error < 0 ) {
F_3 ( & V_9 -> V_2 , L_7 ,
V_20 , error ) ;
return error ;
}
V_35 = F_12 ( & V_40 , & V_9 -> V_2 , V_9 -> V_41 ,
V_16 * 2 ) ;
if ( F_13 ( V_35 ) )
return F_14 ( V_35 ) ;
F_15 ( V_9 , V_35 ) ;
return 0 ;
}
static int F_16 ( struct V_8 * V_9 )
{
struct V_34 * V_35 = F_17 ( V_9 ) ;
F_18 ( V_35 ) ;
return 0 ;
}
