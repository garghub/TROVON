static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_2 -> V_8 ;
int V_9 , V_10 ;
T_1 V_11 ;
T_2 V_12 [ 9 ] ;
#define F_2 0
#define F_3 1
#define F_4 2
#define F_5 3
#define F_6 4
#define F_7 5
#define F_8 6
#define F_9 7
#define F_10 8
#define F_11 9
static const T_2 V_13 [] [ 3 ] = {
[ F_2 ] = { 0xb3 , 0x20 , 0x03 } ,
[ F_3 ] = { 0xb3 , 0x31 , 0x01 } ,
[ F_4 ] = { 0xb3 , 0x22 , 0x01 } ,
[ F_5 ] = { 0xbc , 0x20 , 0x03 } ,
[ F_6 ] = { 0xbc , 0x72 , 0x03 } ,
[ F_7 ] = { 0xbc , 0x22 , 0x01 } ,
[ F_8 ] = { 0x92 , 0x50 , 0x03 } ,
[ F_9 ] = { 0x92 , 0x53 , 0x03 } ,
[ F_10 ] = { 0x7d , 0x20 , 0x63 } ,
[ F_11 ] = { 0x7d , 0x20 , 0x63 } ,
} ;
F_12 ( & V_4 -> V_14 -> V_4 ,
L_1 ,
V_7 -> V_15 , V_7 -> V_16 ,
V_7 -> V_17 ) ;
if ( V_2 -> V_18 . V_19 )
V_2 -> V_18 . V_19 ( V_2 , 1 ) ;
switch ( V_7 -> V_15 ) {
case V_20 :
V_11 = V_4 -> V_21 . V_22 ;
V_10 = F_10 ;
break;
case V_23 :
V_11 = V_4 -> V_21 . V_24 ;
V_10 = F_11 ;
break;
case V_25 :
switch ( V_7 -> V_17 ) {
case 6000000 :
V_11 = V_4 -> V_21 . V_26 ;
V_10 = F_2 ;
break;
case 7000000 :
V_11 = V_4 -> V_21 . V_27 ;
V_10 = F_3 ;
break;
case 8000000 :
V_11 = V_4 -> V_21 . V_28 ;
V_10 = F_4 ;
break;
default:
V_9 = - V_29 ;
goto error;
}
break;
case V_30 :
switch ( V_7 -> V_17 ) {
case 6000000 :
V_11 = V_4 -> V_21 . V_31 ;
V_10 = F_5 ;
break;
case 7000000 :
V_11 = V_4 -> V_21 . V_32 ;
V_10 = F_6 ;
break;
case 8000000 :
V_11 = V_4 -> V_21 . V_33 ;
V_10 = F_7 ;
break;
default:
V_9 = - V_29 ;
goto error;
}
break;
case V_34 :
case V_35 :
V_11 = V_4 -> V_21 . V_36 ;
V_10 = F_9 ;
break;
default:
V_9 = - V_29 ;
goto error;
}
V_9 = F_13 ( V_4 -> V_37 , 0x23 , V_13 [ V_10 ] [ 2 ] ) ;
if ( V_9 )
goto error;
V_9 = F_13 ( V_4 -> V_37 , 0x06 , 0x00 ) ;
if ( V_9 )
goto error;
V_9 = F_13 ( V_4 -> V_37 , 0x0f , V_13 [ V_10 ] [ 0 ] ) ;
if ( V_9 )
goto error;
V_12 [ 0 ] = 0x02 ;
V_12 [ 1 ] = V_13 [ V_10 ] [ 1 ] ;
V_12 [ 2 ] = 0x03 ;
V_12 [ 3 ] = F_14 ( V_11 , 50 ) ;
V_12 [ 4 ] = ( ( V_7 -> V_16 / 1000 ) >> 16 ) & 0xff ;
V_12 [ 5 ] = ( ( V_7 -> V_16 / 1000 ) >> 8 ) & 0xff ;
V_12 [ 6 ] = ( ( V_7 -> V_16 / 1000 ) >> 0 ) & 0xff ;
V_12 [ 7 ] = 0xc1 ;
V_12 [ 8 ] = 0x01 ;
V_9 = F_15 ( V_4 -> V_37 , 0x12 , V_12 , sizeof( V_12 ) ) ;
if ( V_9 )
goto error;
V_4 -> V_38 = V_12 [ 3 ] * 50 * 1000 ;
exit:
if ( V_2 -> V_18 . V_19 )
V_2 -> V_18 . V_19 ( V_2 , 0 ) ;
return V_9 ;
error:
F_12 ( & V_4 -> V_14 -> V_4 , L_2 , V_9 ) ;
goto exit;
}
static int F_16 ( struct V_1 * V_2 , T_1 * V_16 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
* V_16 = V_4 -> V_38 ;
return 0 ;
}
static int F_17 ( struct V_39 * V_14 ,
const struct V_40 * V_41 )
{
struct V_42 * V_21 = V_14 -> V_4 . V_43 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 ;
int V_9 ;
unsigned int V_44 ;
char * V_45 ;
static const struct V_46 V_46 = {
. V_47 = 8 ,
. V_48 = 8 ,
} ;
V_4 = F_18 ( sizeof( * V_4 ) , V_49 ) ;
if ( V_4 == NULL ) {
V_9 = - V_50 ;
F_19 ( & V_14 -> V_4 , L_3 ) ;
goto V_51;
}
memcpy ( & V_4 -> V_21 , V_21 , sizeof( struct V_42 ) ) ;
V_4 -> V_14 = V_14 ;
V_4 -> V_37 = F_20 ( V_14 , & V_46 ) ;
if ( F_21 ( V_4 -> V_37 ) ) {
V_9 = F_22 ( V_4 -> V_37 ) ;
goto V_51;
}
if ( V_2 -> V_18 . V_19 )
V_2 -> V_18 . V_19 ( V_2 , 1 ) ;
V_9 = F_23 ( V_4 -> V_37 , 0x00 , & V_44 ) ;
F_12 ( & V_4 -> V_14 -> V_4 , L_4 , V_44 ) ;
if ( V_2 -> V_18 . V_19 )
V_2 -> V_18 . V_19 ( V_2 , 0 ) ;
if ( V_9 )
goto V_51;
switch ( V_44 ) {
case 0xc7 :
V_45 = L_5 ;
break;
case 0x47 :
V_45 = L_6 ;
break;
default:
V_9 = - V_52 ;
goto V_51;
}
F_24 ( & V_4 -> V_14 -> V_4 ,
L_7 , V_45 ) ;
V_2 -> V_5 = V_4 ;
memcpy ( & V_2 -> V_18 . V_53 , & V_54 ,
sizeof( struct V_55 ) ) ;
F_25 ( V_14 , V_4 ) ;
return 0 ;
V_51:
F_12 ( & V_14 -> V_4 , L_2 , V_9 ) ;
F_26 ( V_4 ) ;
return V_9 ;
}
static int F_27 ( struct V_39 * V_14 )
{
struct V_3 * V_4 = F_28 ( V_14 ) ;
struct V_1 * V_2 = V_4 -> V_21 . V_2 ;
F_12 ( & V_14 -> V_4 , L_8 ) ;
memset ( & V_2 -> V_18 . V_53 , 0 , sizeof( struct V_55 ) ) ;
V_2 -> V_5 = NULL ;
F_26 ( V_4 ) ;
return 0 ;
}
