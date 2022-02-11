static int F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
T_1 V_4 , T_2 V_5 , T_1 * V_6 , int V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 V_11 ;
struct V_12 V_13 [ 2 ] ;
T_1 * V_14 = & V_3 [ 0 ] ;
T_1 V_15 [ V_16 ] ;
int V_17 ;
int V_18 ;
if ( V_7 > V_19 ) {
F_3 ( V_2 , L_1 ,
V_20 , V_7 ) ;
return - V_21 ;
}
memset ( V_14 , 0 , V_22 ) ;
memset ( V_15 , 0 , V_16 ) ;
V_14 [ 0 ] = V_4 + ( ( ( V_5 >> 8 ) & 0x1 ) ? V_23 : 0 ) ;
if ( V_4 == V_24 ) {
V_14 [ 1 ] = V_5 & 0xFF ;
if ( V_7 > 0 )
memcpy ( V_14 + V_16 , V_6 , V_7 ) ;
}
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
F_4 ( & V_11 ) ;
V_13 [ 0 ] . V_25 = V_14 ;
V_13 [ 0 ] . V_26 = V_15 ;
switch ( V_4 ) {
case V_24 :
V_13 [ 0 ] . V_27 = V_7 + V_16 ;
F_5 ( & V_13 [ 0 ] , & V_11 ) ;
break;
case V_28 :
V_13 [ 0 ] . V_27 = V_29 ;
F_5 ( & V_13 [ 0 ] , & V_11 ) ;
V_13 [ 1 ] . V_26 = V_6 ;
V_13 [ 1 ] . V_27 = V_7 ;
F_5 ( & V_13 [ 1 ] , & V_11 ) ;
break;
default:
F_3 ( V_2 , L_2 , V_20 , V_4 ) ;
return - V_21 ;
}
V_17 = F_6 ( V_9 , & V_11 ) ;
if ( V_17 < 0 ) {
F_7 ( V_2 , L_3 ,
V_20 , V_17 , V_13 [ 1 ] . V_27 , V_4 ) ;
}
if ( V_15 [ V_30 ] != V_31 ) {
F_7 ( V_2 , L_4 , V_20 , V_4 ) ;
for ( V_18 = 0 ; V_18 < V_16 ; V_18 ++ )
F_7 ( V_2 , L_5 ,
V_20 , V_18 , V_15 [ V_18 ] ) ;
for ( V_18 = 0 ; V_18 < V_7 ; V_18 ++ )
F_7 ( V_2 , L_6 ,
V_20 , V_18 , V_6 [ V_18 ] ) ;
return - V_32 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_33 , T_1 V_7 , void * V_34 )
{
int V_35 ;
V_35 = F_1 ( V_2 , V_3 , V_24 , V_33 , NULL , 0 ) ;
if ( V_35 )
return V_35 ;
else
return F_1 ( V_2 , V_3 , V_28 , V_33 , V_34 ,
V_7 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_33 , T_1 V_7 , const void * V_34 )
{
return F_1 ( V_2 , V_3 , V_24 , V_33 , ( void * ) V_34 ,
V_7 ) ;
}
static int F_10 ( struct V_8 * V_9 )
{
struct V_36 * V_37 ;
int error ;
V_9 -> V_38 = V_39 ;
V_9 -> V_40 = V_41 ;
error = F_11 ( V_9 ) ;
if ( error < 0 ) {
F_3 ( & V_9 -> V_2 , L_7 ,
V_20 , error ) ;
return error ;
}
V_37 = F_12 ( & V_42 , & V_9 -> V_2 , V_9 -> V_43 ,
V_22 ) ;
if ( F_13 ( V_37 ) )
return F_14 ( V_37 ) ;
return 0 ;
}
static int F_15 ( struct V_8 * V_9 )
{
struct V_36 * V_37 = F_16 ( V_9 ) ;
F_17 ( V_37 ) ;
return 0 ;
}
