static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 ,
int V_5 )
{
int V_6 ;
T_1 V_7 [ V_5 + 1 ] ;
struct V_8 V_9 [ 1 ] = {
{
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = 0 ,
. V_5 = sizeof( V_7 ) ,
. V_7 = V_7 ,
}
} ;
V_7 [ 0 ] = V_3 ;
memcpy ( & V_7 [ 1 ] , V_4 , V_5 ) ;
V_6 = F_2 ( V_2 -> V_14 , V_9 , 1 ) ;
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_3 ( L_1 , V_6 , V_3 , V_5 ) ;
V_6 = - V_15 ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 ,
int V_5 )
{
int V_6 ;
T_1 V_7 [ V_5 ] ;
struct V_8 V_9 [ 2 ] = {
{
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = 0 ,
. V_5 = 1 ,
. V_7 = & V_3 ,
} , {
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = V_16 ,
. V_5 = sizeof( V_7 ) ,
. V_7 = V_7 ,
}
} ;
V_6 = F_2 ( V_2 -> V_14 , V_9 , 2 ) ;
if ( V_6 == 2 ) {
memcpy ( V_4 , V_7 , V_5 ) ;
V_6 = 0 ;
} else {
F_3 ( L_2 , V_6 , V_3 , V_5 ) ;
V_6 = - V_15 ;
}
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
return F_4 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int F_7 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = V_18 -> V_21 ;
struct V_22 * V_23 = & V_18 -> V_24 ;
int V_6 , V_25 ;
T_2 V_26 ;
T_1 V_7 [ 9 ] ;
static const T_1 V_27 [] [ 3 ] = {
{ 0xb3 , 0x20 , 0x03 } ,
{ 0xb3 , 0x31 , 0x01 } ,
{ 0xb3 , 0x22 , 0x01 } ,
{ 0x92 , 0x53 , 0x03 } ,
} ;
F_8 ( L_3 , V_28 ,
V_23 -> V_29 , V_23 -> V_30 , V_23 -> V_31 ) ;
if ( V_18 -> V_32 . V_33 )
V_18 -> V_32 . V_33 ( V_18 , 1 ) ;
switch ( V_23 -> V_29 ) {
case V_34 :
switch ( V_23 -> V_31 ) {
case 6000000 :
V_26 = V_2 -> V_11 -> V_35 ;
V_25 = 0 ;
break;
case 7000000 :
V_26 = V_2 -> V_11 -> V_36 ;
V_25 = 1 ;
break;
case 8000000 :
V_26 = V_2 -> V_11 -> V_37 ;
V_25 = 2 ;
break;
default:
V_6 = - V_38 ;
goto error;
}
break;
case V_39 :
V_26 = V_2 -> V_11 -> V_40 ;
V_25 = 3 ;
break;
default:
V_6 = - V_38 ;
goto error;
}
V_6 = F_5 ( V_2 , 0x23 , V_27 [ V_25 ] [ 2 ] ) ;
if ( V_6 )
goto error;
V_6 = F_5 ( V_2 , 0x06 , 0x00 ) ;
if ( V_6 )
goto error;
V_6 = F_5 ( V_2 , 0x0f , V_27 [ V_25 ] [ 0 ] ) ;
if ( V_6 )
goto error;
V_7 [ 0 ] = 0x02 ;
V_7 [ 1 ] = V_27 [ V_25 ] [ 1 ] ;
V_7 [ 2 ] = 0x03 ;
V_7 [ 3 ] = V_26 / 50 ;
V_7 [ 4 ] = ( ( V_23 -> V_30 / 1000 ) >> 16 ) & 0xff ;
V_7 [ 5 ] = ( ( V_23 -> V_30 / 1000 ) >> 8 ) & 0xff ;
V_7 [ 6 ] = ( ( V_23 -> V_30 / 1000 ) >> 0 ) & 0xff ;
V_7 [ 7 ] = 0xc1 ;
V_7 [ 8 ] = 0x01 ;
V_6 = F_1 ( V_2 , 0x12 , V_7 , sizeof( V_7 ) ) ;
if ( V_6 )
goto error;
exit:
if ( V_18 -> V_32 . V_33 )
V_18 -> V_32 . V_33 ( V_18 , 0 ) ;
return V_6 ;
error:
F_8 ( L_4 , V_28 , V_6 ) ;
goto exit;
}
static int F_9 ( struct V_17 * V_18 )
{
F_10 ( V_18 -> V_21 ) ;
V_18 -> V_21 = NULL ;
return 0 ;
}
struct V_17 * F_11 ( struct V_17 * V_18 ,
struct V_41 * V_14 , struct V_42 * V_11 )
{
struct V_1 * V_2 = NULL ;
int V_6 ;
T_1 V_4 ;
V_2 = F_12 ( sizeof( struct V_1 ) , V_43 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_11 = V_11 ;
V_2 -> V_14 = V_14 ;
V_18 -> V_21 = V_2 ;
if ( V_18 -> V_32 . V_33 )
V_18 -> V_32 . V_33 ( V_18 , 1 ) ;
V_6 = F_6 ( V_2 , 0x00 , & V_4 ) ;
if ( V_18 -> V_32 . V_33 )
V_18 -> V_32 . V_33 ( V_18 , 0 ) ;
F_8 ( L_5 , V_28 , V_6 , V_4 ) ;
if ( V_6 || V_4 != 0xc7 ) {
F_10 ( V_2 ) ;
return NULL ;
}
F_13 ( L_6 ) ;
memcpy ( & V_18 -> V_32 . V_44 , & V_45 ,
sizeof( struct V_46 ) ) ;
return V_18 ;
}
