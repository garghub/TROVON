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
F_3 ( & V_2 -> V_14 -> V_15 , L_1 ,
V_16 , V_5 , V_3 ) ;
V_5 = - V_17 ;
}
return V_5 ;
}
static int F_4 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
int V_5 = 0 ;
F_5 ( & V_2 -> V_14 -> V_15 , L_2 , V_21 ) ;
if ( V_19 -> V_22 )
V_5 = V_19 -> V_22 ( V_2 -> V_14 , V_23 ,
V_24 , 0 ) ;
F_6 ( V_19 -> V_20 ) ;
V_19 -> V_20 = NULL ;
return V_5 ;
}
static int F_7 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
int V_5 = 0 ;
T_1 V_25 ;
struct V_26 V_27 [] = {
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
F_5 ( & V_2 -> V_14 -> V_15 , L_2 , V_21 ) ;
if ( V_19 -> V_22 ) {
V_5 = V_19 -> V_22 ( V_2 -> V_14 , V_23 ,
V_28 , 0 ) ;
if ( V_5 < 0 )
goto V_29;
}
if ( V_19 -> V_30 . V_31 )
V_19 -> V_30 . V_31 ( V_19 , 1 ) ;
for ( V_25 = 0 ; V_25 < F_8 ( V_27 ) ; V_25 ++ ) {
V_5 = F_1 ( V_2 , V_27 [ V_25 ] . V_3 , V_27 [ V_25 ] . V_4 ) ;
if ( V_5 < 0 )
goto V_32;
}
V_32:
if ( V_19 -> V_30 . V_31 )
V_19 -> V_30 . V_31 ( V_19 , 0 ) ;
V_29:
if ( V_5 < 0 )
F_5 ( & V_2 -> V_14 -> V_15 , L_3 , V_21 , V_5 ) ;
return V_5 ;
}
static int F_9 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
int V_5 = 0 ;
F_5 ( & V_2 -> V_14 -> V_15 , L_2 , V_21 ) ;
if ( V_19 -> V_22 )
V_5 = V_19 -> V_22 ( V_2 -> V_14 , V_23 ,
V_28 , 1 ) ;
if ( V_5 < 0 )
F_5 ( & V_2 -> V_14 -> V_15 , L_3 , V_21 , V_5 ) ;
return V_5 ;
}
static int F_10 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
struct V_33 * V_34 = & V_19 -> V_35 ;
int V_5 = 0 , V_25 ;
T_2 V_4 ;
T_3 V_36 ;
struct V_26 V_27 [ 2 ] ;
F_5 ( & V_2 -> V_14 -> V_15 , L_4 \
L_5 , V_21 ,
V_34 -> V_37 , V_34 -> V_36 , V_34 -> V_38 ) ;
switch ( V_34 -> V_37 ) {
case V_39 :
switch ( V_34 -> V_38 ) {
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
V_5 = - V_40 ;
goto V_29;
}
break;
default:
V_5 = - V_40 ;
goto V_29;
}
V_27 [ 0 ] . V_3 = 0x04 ;
V_27 [ 0 ] . V_4 = V_4 ;
V_36 = ( V_34 -> V_36 - 150000000 ) ;
V_36 /= 100 ;
V_36 *= 48 ;
V_36 /= 10000 ;
V_27 [ 1 ] . V_3 = 0x1f ;
V_27 [ 1 ] . V_4 = V_36 ;
if ( V_19 -> V_30 . V_31 )
V_19 -> V_30 . V_31 ( V_19 , 1 ) ;
if ( V_19 -> V_22 ) {
V_5 = V_19 -> V_22 ( V_2 -> V_14 , V_23 ,
V_41 , 0 ) ;
if ( V_5 < 0 )
goto V_32;
}
for ( V_25 = 0 ; V_25 < F_8 ( V_27 ) ; V_25 ++ ) {
V_5 = F_1 ( V_2 , V_27 [ V_25 ] . V_3 , V_27 [ V_25 ] . V_4 ) ;
if ( V_5 < 0 )
goto V_32;
}
if ( V_19 -> V_22 ) {
V_5 = V_19 -> V_22 ( V_2 -> V_14 , V_23 ,
V_41 , 1 ) ;
if ( V_5 < 0 )
goto V_32;
}
V_32:
if ( V_19 -> V_30 . V_31 )
V_19 -> V_30 . V_31 ( V_19 , 0 ) ;
V_29:
if ( V_5 < 0 )
F_5 ( & V_2 -> V_14 -> V_15 , L_3 , V_21 , V_5 ) ;
return V_5 ;
}
static int F_11 ( struct V_18 * V_19 , T_3 * V_36 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
F_5 ( & V_2 -> V_14 -> V_15 , L_2 , V_21 ) ;
* V_36 = 0 ;
return 0 ;
}
struct V_18 * F_12 ( struct V_18 * V_19 ,
struct V_42 * V_14 , struct V_43 * V_10 )
{
struct V_1 * V_2 = NULL ;
int V_5 ;
V_2 = F_13 ( sizeof( struct V_1 ) , V_44 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_10 = V_10 ;
V_2 -> V_14 = V_14 ;
if ( V_19 -> V_22 ) {
V_5 = V_19 -> V_22 ( V_2 -> V_14 , V_23 ,
V_24 , 1 ) ;
if ( V_5 < 0 )
goto V_29;
V_5 = V_19 -> V_22 ( V_2 -> V_14 , V_23 ,
V_41 , 0 ) ;
if ( V_5 < 0 )
goto V_29;
V_5 = V_19 -> V_22 ( V_2 -> V_14 , V_23 ,
V_28 , 1 ) ;
if ( V_5 < 0 )
goto V_29;
}
F_14 ( & V_2 -> V_14 -> V_15 ,
L_6 ,
V_16 ) ;
memcpy ( & V_19 -> V_30 . V_45 , & V_46 ,
sizeof( struct V_47 ) ) ;
V_19 -> V_20 = V_2 ;
return V_19 ;
V_29:
F_5 ( & V_14 -> V_15 , L_3 , V_21 , V_5 ) ;
F_6 ( V_2 ) ;
return NULL ;
}
