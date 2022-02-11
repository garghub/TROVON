static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_2 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_5 [ V_6 ] != 0x00 ; V_6 += 2 )
if ( F_2 ( V_2 , V_5 [ V_6 ] , V_5 [ V_6 + 1 ] ) < 0 )
return - 1 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_7 , void * V_8 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
switch ( V_7 ) {
case V_11 :
{
int * V_12 = V_8 ;
F_2 ( V_2 , 0x02 , 0xC0 | * V_12 ) ;
F_2 ( V_2 , 0x09 ,
* V_12 < 6 ? 0x40 : 0xC0 ) ;
break;
}
case V_13 :
{
struct V_14 * V_15 = V_8 ;
int V_16 = V_15 -> V_17 < 704 ? 704 / V_15 -> V_17 : 1 ;
int V_18 = ( 704 / V_16 ) *
1024 / V_15 -> V_17 ;
int V_19 = ( V_10 -> V_20 & V_21 ?
240 : 288 ) * 1024 / V_15 -> V_22 ;
T_1 V_5 [] = {
0x88 , 0xc0 ,
0x9c , V_15 -> V_17 & 0xff ,
0x9d , V_15 -> V_17 >> 8 ,
0x9e , V_15 -> V_22 & 0xff ,
0x9f , V_15 -> V_22 >> 8 ,
0xa0 , V_16 ,
0xa1 , 1 ,
0xa2 , 1 ,
0xa8 , V_18 & 0xff ,
0xa9 , V_18 >> 8 ,
0xac , ( V_18 / 2 ) & 0xff ,
0xad , ( V_18 / 2 ) >> 8 ,
0xb0 , V_19 & 0xff ,
0xb1 , V_19 >> 8 ,
0xb2 , V_19 & 0xff ,
0xb3 , V_19 >> 8 ,
0xcc , V_15 -> V_17 & 0xff ,
0xcd , V_15 -> V_17 >> 8 ,
0xce , V_15 -> V_22 & 0xff ,
0xcf , V_15 -> V_22 >> 8 ,
0xd0 , V_16 ,
0xd1 , 1 ,
0xd2 , 1 ,
0xd8 , V_18 & 0xff ,
0xd9 , V_18 >> 8 ,
0xdc , ( V_18 / 2 ) & 0xff ,
0xdd , ( V_18 / 2 ) >> 8 ,
0xe0 , V_19 & 0xff ,
0xe1 , V_19 >> 8 ,
0xe2 , V_19 & 0xff ,
0xe3 , V_19 >> 8 ,
0x88 , 0xf0 ,
0 , 0 ,
} ;
F_3 ( V_2 , V_5 ) ;
break;
}
case V_23 :
{
T_2 * V_12 = V_8 ;
T_1 V_5 [] = {
0x88 , 0xc0 ,
0x98 , * V_12 & V_21 ? 0x12 : 0x16 ,
0x9a , * V_12 & V_21 ? 0xf2 : 0x20 ,
0x9b , * V_12 & V_21 ? 0x00 : 0x01 ,
0xc8 , * V_12 & V_21 ? 0x12 : 0x16 ,
0xca , * V_12 & V_21 ? 0xf2 : 0x20 ,
0xcb , * V_12 & V_21 ? 0x00 : 0x01 ,
0x88 , 0xf0 ,
0x30 , * V_12 & V_21 ? 0x66 : 0x00 ,
0x31 , * V_12 & V_21 ? 0x90 : 0xe0 ,
0 , 0 ,
} ;
F_3 ( V_2 , V_5 ) ;
V_10 -> V_20 = * V_12 ;
break;
}
case V_24 :
{
struct V_25 * V_26 = V_8 ;
switch ( V_26 -> V_27 ) {
case V_28 :
V_26 -> type = V_29 ;
strncpy ( V_26 -> V_30 , L_1 , sizeof( V_26 -> V_30 ) ) ;
V_26 -> V_31 = 0 ;
V_26 -> V_32 = 255 ;
V_26 -> V_33 = 1 ;
V_26 -> V_34 = 128 ;
V_26 -> V_35 = 0 ;
break;
case V_36 :
V_26 -> type = V_29 ;
strncpy ( V_26 -> V_30 , L_2 , sizeof( V_26 -> V_30 ) ) ;
V_26 -> V_31 = 0 ;
V_26 -> V_32 = 127 ;
V_26 -> V_33 = 1 ;
V_26 -> V_34 = 64 ;
V_26 -> V_35 = 0 ;
break;
case V_37 :
V_26 -> type = V_29 ;
strncpy ( V_26 -> V_30 , L_3 , sizeof( V_26 -> V_30 ) ) ;
V_26 -> V_31 = 0 ;
V_26 -> V_32 = 127 ;
V_26 -> V_33 = 1 ;
V_26 -> V_34 = 64 ;
V_26 -> V_35 = 0 ;
break;
case V_38 :
V_26 -> type = V_29 ;
strncpy ( V_26 -> V_30 , L_4 , sizeof( V_26 -> V_30 ) ) ;
V_26 -> V_31 = - 128 ;
V_26 -> V_32 = 127 ;
V_26 -> V_33 = 1 ;
V_26 -> V_34 = 0 ;
V_26 -> V_35 = 0 ;
break;
}
break;
}
case V_39 :
{
struct V_40 * V_26 = V_8 ;
switch ( V_26 -> V_27 ) {
case V_28 :
if ( V_26 -> V_4 > 255 )
V_10 -> V_41 = 255 ;
else if ( V_26 -> V_4 < 0 )
V_10 -> V_41 = 0 ;
else
V_10 -> V_41 = V_26 -> V_4 ;
F_1 ( V_2 , 0x0a , V_10 -> V_41 ) ;
break;
case V_36 :
if ( V_26 -> V_4 > 127 )
V_10 -> V_42 = 127 ;
else if ( V_26 -> V_4 < 0 )
V_10 -> V_42 = 0 ;
else
V_10 -> V_42 = V_26 -> V_4 ;
F_1 ( V_2 , 0x0b , V_10 -> V_42 ) ;
break;
case V_37 :
if ( V_26 -> V_4 > 127 )
V_10 -> V_43 = 127 ;
else if ( V_26 -> V_4 < 0 )
V_10 -> V_43 = 0 ;
else
V_10 -> V_43 = V_26 -> V_4 ;
F_1 ( V_2 , 0x0c , V_10 -> V_43 ) ;
break;
case V_38 :
if ( V_26 -> V_4 > 127 )
V_10 -> V_44 = 127 ;
else if ( V_26 -> V_4 < - 128 )
V_10 -> V_44 = - 128 ;
else
V_10 -> V_44 = V_26 -> V_4 ;
F_1 ( V_2 , 0x0d , V_10 -> V_44 ) ;
break;
}
break;
}
case V_45 :
{
struct V_40 * V_26 = V_8 ;
switch ( V_26 -> V_27 ) {
case V_28 :
V_26 -> V_4 = V_10 -> V_41 ;
break;
case V_36 :
V_26 -> V_4 = V_10 -> V_42 ;
break;
case V_37 :
V_26 -> V_4 = V_10 -> V_43 ;
break;
case V_38 :
V_26 -> V_4 = V_10 -> V_44 ;
break;
}
break;
}
default:
break;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_46 * V_27 )
{
struct V_47 * V_48 = V_2 -> V_48 ;
struct V_9 * V_10 ;
if ( ! F_7 ( V_48 , V_49 ) )
return - V_50 ;
V_10 = F_8 ( sizeof( struct V_9 ) , V_51 ) ;
if ( V_10 == NULL )
return - V_52 ;
V_10 -> V_20 = V_21 ;
V_10 -> V_41 = 128 ;
V_10 -> V_42 = 64 ;
V_10 -> V_43 = 64 ;
V_10 -> V_44 = 0 ;
F_9 ( V_2 , V_10 ) ;
F_10 ( V_53
L_5 ,
V_2 -> V_54 , V_48 -> V_30 ) ;
if ( F_3 ( V_2 , V_55 ) < 0 ) {
F_10 ( V_56
L_6 ) ;
F_11 ( V_10 ) ;
return - V_50 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
F_11 ( V_10 ) ;
return 0 ;
}
static int T_3 F_13 ( void )
{
return F_14 ( & V_57 ) ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_57 ) ;
}
