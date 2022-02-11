static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 * V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 -> V_9 ) ;
struct V_10 V_11 ;
struct V_12 V_13 [ 2 ] ;
T_1 * V_14 = & V_2 -> V_15 [ 0 ] ;
T_1 * V_16 = & V_2 -> V_15 [ V_17 ] ;
int V_18 ;
int V_19 ;
if ( V_6 > V_20 ) {
F_3 ( V_2 -> V_9 , L_1 ,
V_21 , V_6 ) ;
return - V_22 ;
}
memset ( V_14 , 0 , V_17 ) ;
memset ( V_16 , 0 , V_17 ) ;
V_14 [ 0 ] = 0x00 ;
V_14 [ 1 ] = 0xFF ;
V_14 [ 2 ] = V_4 ;
V_14 [ 3 ] = V_3 ;
if ( V_3 == V_23 )
memcpy ( V_14 + V_24 , V_5 , V_6 ) ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
F_4 ( & V_11 ) ;
V_13 [ 0 ] . V_25 = V_14 ;
V_13 [ 0 ] . V_26 = V_16 ;
switch ( V_3 ) {
case V_23 :
V_13 [ 0 ] . V_27 = V_6 + V_24 ;
F_5 ( & V_13 [ 0 ] , & V_11 ) ;
break;
case V_28 :
V_13 [ 0 ] . V_27 = V_24 ;
F_5 ( & V_13 [ 0 ] , & V_11 ) ;
V_13 [ 1 ] . V_26 = V_5 ;
V_13 [ 1 ] . V_27 = V_6 ;
F_5 ( & V_13 [ 1 ] , & V_11 ) ;
break;
default:
F_3 ( V_2 -> V_9 , L_2 , V_21 , V_3 ) ;
return - V_22 ;
}
V_18 = F_6 ( V_8 , & V_11 ) ;
if ( V_18 < 0 ) {
F_7 ( V_2 -> V_9 , L_3 ,
V_21 , V_18 , V_13 [ 1 ] . V_27 , V_3 ) ;
}
if ( V_16 [ V_29 ] != V_30 ||
V_16 [ V_29 + 1 ] != V_31 ) {
F_7 ( V_2 -> V_9 , L_4 , V_21 , V_3 ) ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ )
F_7 ( V_2 -> V_9 , L_5 ,
V_21 , V_19 , V_16 [ V_19 ] ) ;
for ( V_19 = 0 ; V_19 < V_6 ; V_19 ++ )
F_7 ( V_2 -> V_9 , L_6 ,
V_21 , V_19 , V_5 [ V_19 ] ) ;
return - V_32 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_33 , T_1 V_6 , void * V_34 )
{
return F_1 ( V_2 , V_28 , V_33 , V_34 , V_6 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
T_1 V_33 , T_1 V_6 , const void * V_34 )
{
return F_1 ( V_2 , V_23 , V_33 , ( void * ) V_34 , V_6 ) ;
}
static int F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int error ;
V_8 -> V_35 = V_36 ;
V_8 -> V_37 = V_38 ;
error = F_11 ( V_8 ) ;
if ( error < 0 ) {
F_3 ( & V_8 -> V_9 , L_7 ,
V_21 , error ) ;
return error ;
}
V_2 = F_12 ( & V_39 , & V_8 -> V_9 , V_8 -> V_40 ,
V_17 * 2 ) ;
if ( F_13 ( V_2 ) )
return F_14 ( V_2 ) ;
F_15 ( V_8 , V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_17 ( V_8 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
