static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 ;
T_1 V_6 [ 3 ] = { V_3 , ( V_4 >> 8 ) & 0xff , ( V_4 >> 0 ) & 0xff } ;
struct V_7 V_8 [ 1 ] = {
{
. V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = 0 ,
. V_13 = sizeof( V_6 ) ,
. V_6 = V_6 ,
}
} ;
V_5 = F_2 ( V_2 -> V_14 , V_8 , 1 ) ;
if ( V_5 == 1 ) {
V_5 = 0 ;
} else {
F_3 ( V_15 L_1 ,
V_16 , V_5 , V_3 ) ;
V_5 = - V_17 ;
}
return V_5 ;
}
static int F_4 ( struct V_18 * V_19 )
{
F_5 ( V_19 -> V_20 ) ;
V_19 -> V_20 = NULL ;
return 0 ;
}
static int F_6 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
int V_5 = 0 ;
T_1 V_21 ;
struct V_22 V_23 [] = {
{ 0x1e , 0x6512 } ,
{ 0x25 , 0xb888 } ,
{ 0x39 , 0x5460 } ,
{ 0x3b , 0x00c0 } ,
{ 0x3a , 0xf000 } ,
{ 0x08 , 0x0000 } ,
{ 0x32 , 0x0030 } ,
{ 0x41 , 0x703a } ,
{ 0x40 , 0x1c78 } ,
{ 0x2c , 0x1c00 } ,
{ 0x36 , 0xc013 } ,
{ 0x37 , 0x6f18 } ,
{ 0x27 , 0x0008 } ,
{ 0x2a , 0x0001 } ,
{ 0x34 , 0x0a40 } ,
} ;
if ( V_19 -> V_24 . V_25 )
V_19 -> V_24 . V_25 ( V_19 , 1 ) ;
for ( V_21 = 0 ; V_21 < F_7 ( V_23 ) ; V_21 ++ ) {
V_5 = F_1 ( V_2 , V_23 [ V_21 ] . V_3 , V_23 [ V_21 ] . V_4 ) ;
if ( V_5 )
break;
}
if ( V_19 -> V_24 . V_25 )
V_19 -> V_24 . V_25 ( V_19 , 0 ) ;
if ( V_5 < 0 )
F_8 ( L_2 , V_16 , V_5 ) ;
return V_5 ;
}
static int F_9 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
struct V_26 * V_27 = & V_19 -> V_28 ;
int V_5 , V_21 ;
T_2 V_4 ;
T_3 V_29 ;
struct V_22 V_23 [ 2 ] ;
F_8 ( L_3 ,
V_16 , V_27 -> V_30 , V_27 -> V_29 ,
V_27 -> V_31 ) ;
switch ( V_27 -> V_30 ) {
case V_32 :
switch ( V_27 -> V_31 ) {
case 8000000 :
V_4 = 0x0000 ;
break;
case 7000000 :
V_4 = 0x1000 ;
break;
case 6000000 :
V_4 = 0x2000 ;
break;
case 5000000 :
V_4 = 0x3000 ;
break;
default:
V_5 = - V_33 ;
goto V_34;
}
break;
default:
V_5 = - V_33 ;
goto V_34;
}
V_23 [ 0 ] . V_3 = 0x04 ;
V_23 [ 0 ] . V_4 = V_4 ;
V_29 = ( V_27 -> V_29 - 150000000 ) ;
V_29 /= 100 ;
V_29 *= 48 ;
V_29 /= 10000 ;
V_23 [ 1 ] . V_3 = 0x1f ;
V_23 [ 1 ] . V_4 = V_29 ;
if ( V_19 -> V_24 . V_25 )
V_19 -> V_24 . V_25 ( V_19 , 1 ) ;
for ( V_21 = 0 ; V_21 < F_7 ( V_23 ) ; V_21 ++ ) {
V_5 = F_1 ( V_2 , V_23 [ V_21 ] . V_3 , V_23 [ V_21 ] . V_4 ) ;
if ( V_5 < 0 )
break;
}
if ( V_19 -> V_24 . V_25 )
V_19 -> V_24 . V_25 ( V_19 , 0 ) ;
V_34:
if ( V_5 < 0 )
F_8 ( L_2 , V_16 , V_5 ) ;
return V_5 ;
}
static int F_10 ( struct V_18 * V_19 , T_3 * V_29 )
{
* V_29 = 0 ;
return 0 ;
}
struct V_18 * F_11 ( struct V_18 * V_19 ,
struct V_35 * V_14 , struct V_36 * V_10 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_12 ( sizeof( struct V_1 ) , V_37 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_10 = V_10 ;
V_2 -> V_14 = V_14 ;
F_3 ( V_38 L_4 ) ;
memcpy ( & V_19 -> V_24 . V_39 , & V_40 ,
sizeof( struct V_41 ) ) ;
V_19 -> V_20 = V_2 ;
return V_19 ;
}
