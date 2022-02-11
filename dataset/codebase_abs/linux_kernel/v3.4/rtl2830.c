static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_7 [ 1 + V_5 ] ;
struct V_8 V_9 [ 1 ] = {
{
. V_10 = V_2 -> V_11 . V_12 ,
. V_13 = 0 ,
. V_5 = 1 + V_5 ,
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
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
struct V_8 V_9 [ 2 ] = {
{
. V_10 = V_2 -> V_11 . V_12 ,
. V_13 = 0 ,
. V_5 = 1 ,
. V_7 = & V_3 ,
} , {
. V_10 = V_2 -> V_11 . V_12 ,
. V_13 = V_16 ,
. V_5 = V_5 ,
. V_7 = V_4 ,
}
} ;
V_6 = F_2 ( V_2 -> V_14 , V_9 , 2 ) ;
if ( V_6 == 2 ) {
V_6 = 0 ;
} else {
F_3 ( L_2 , V_6 , V_3 , V_5 ) ;
V_6 = - V_15 ;
}
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_17 = ( V_3 >> 0 ) & 0xff ;
T_1 V_18 = ( V_3 >> 8 ) & 0xff ;
if ( V_18 != V_2 -> V_18 ) {
V_6 = F_1 ( V_2 , 0x00 , & V_18 , 1 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_18 = V_18 ;
}
return F_1 ( V_2 , V_17 , V_4 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_17 = ( V_3 >> 0 ) & 0xff ;
T_1 V_18 = ( V_3 >> 8 ) & 0xff ;
if ( V_18 != V_2 -> V_18 ) {
V_6 = F_1 ( V_2 , 0x00 , & V_18 , 1 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_18 = V_18 ;
}
return F_4 ( V_2 , V_17 , V_4 , V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 )
{
return F_6 ( V_2 , V_3 , V_4 , 1 ) ;
}
int F_8 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_4 , T_1 V_19 )
{
int V_6 ;
T_1 V_20 ;
if ( V_19 != 0xff ) {
V_6 = F_6 ( V_2 , V_3 , & V_20 , 1 ) ;
if ( V_6 )
return V_6 ;
V_4 &= V_19 ;
V_20 &= ~ V_19 ;
V_4 |= V_20 ;
}
return F_5 ( V_2 , V_3 , & V_4 , 1 ) ;
}
int F_9 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 , T_1 V_19 )
{
int V_6 , V_21 ;
T_1 V_20 ;
V_6 = F_6 ( V_2 , V_3 , & V_20 , 1 ) ;
if ( V_6 )
return V_6 ;
V_20 &= V_19 ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
if ( ( V_19 >> V_21 ) & 0x01 )
break;
}
* V_4 = V_20 >> V_21 ;
return 0 ;
}
static int F_10 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
int V_6 , V_21 ;
T_3 V_25 ;
T_1 V_7 [ 3 ] , V_20 ;
T_4 V_26 ;
struct V_27 V_28 [] = {
{ 0x00d , 0x01 , 0x03 } ,
{ 0x00d , 0x10 , 0x10 } ,
{ 0x104 , 0x00 , 0x1e } ,
{ 0x105 , 0x80 , 0x80 } ,
{ 0x110 , 0x02 , 0x03 } ,
{ 0x110 , 0x08 , 0x0c } ,
{ 0x17b , 0x00 , 0x40 } ,
{ 0x17d , 0x05 , 0x0f } ,
{ 0x17d , 0x50 , 0xf0 } ,
{ 0x18c , 0x08 , 0x0f } ,
{ 0x18d , 0x00 , 0xc0 } ,
{ 0x188 , 0x05 , 0x0f } ,
{ 0x189 , 0x00 , 0xfc } ,
{ 0x2d5 , 0x02 , 0x02 } ,
{ 0x2f1 , 0x02 , 0x06 } ,
{ 0x2f1 , 0x20 , 0xf8 } ,
{ 0x16d , 0x00 , 0x01 } ,
{ 0x1a6 , 0x00 , 0x80 } ,
{ 0x106 , V_2 -> V_11 . V_29 , 0x3f } ,
{ 0x107 , V_2 -> V_11 . V_30 , 0x3f } ,
{ 0x112 , 0x28 , 0xff } ,
{ 0x103 , V_2 -> V_11 . V_31 , 0xff } ,
{ 0x00a , 0x02 , 0x07 } ,
{ 0x140 , 0x0c , 0x3c } ,
{ 0x140 , 0x40 , 0xc0 } ,
{ 0x15b , 0x05 , 0x07 } ,
{ 0x15b , 0x28 , 0x38 } ,
{ 0x15c , 0x05 , 0x07 } ,
{ 0x15c , 0x28 , 0x38 } ,
{ 0x115 , V_2 -> V_11 . V_32 , 0x01 } ,
{ 0x16f , 0x01 , 0x07 } ,
{ 0x170 , 0x18 , 0x38 } ,
{ 0x172 , 0x0f , 0x0f } ,
{ 0x173 , 0x08 , 0x38 } ,
{ 0x175 , 0x01 , 0x07 } ,
{ 0x176 , 0x00 , 0xc0 } ,
} ;
for ( V_21 = 0 ; V_21 < F_11 ( V_28 ) ; V_21 ++ ) {
V_6 = F_8 ( V_2 , V_28 [ V_21 ] . V_3 , V_28 [ V_21 ] . V_4 ,
V_28 [ V_21 ] . V_19 ) ;
if ( V_6 )
goto V_33;
}
V_6 = F_5 ( V_2 , 0x18f , L_3 , 2 ) ;
if ( V_6 )
goto V_33;
V_6 = F_5 ( V_2 , 0x195 ,
L_4 , 8 ) ;
if ( V_6 )
goto V_33;
V_25 = V_2 -> V_11 . V_34 % V_2 -> V_11 . V_35 ;
V_25 *= 0x400000 ;
V_25 = F_12 ( V_25 , V_2 -> V_11 . V_35 ) ;
V_25 = - V_25 ;
V_26 = V_25 & 0x3fffff ;
F_13 ( L_5 , V_36 , V_26 ) ;
V_6 = F_9 ( V_2 , 0x119 , & V_20 , 0xc0 ) ;
if ( V_6 )
goto V_33;
V_7 [ 0 ] = V_20 << 6 ;
V_7 [ 0 ] = ( V_26 >> 16 ) & 0x3f ;
V_7 [ 1 ] = ( V_26 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_26 >> 0 ) & 0xff ;
V_6 = F_5 ( V_2 , 0x119 , V_7 , 3 ) ;
if ( V_6 )
goto V_33;
V_6 = F_8 ( V_2 , 0x101 , 0x04 , 0x04 ) ;
if ( V_6 )
goto V_33;
V_6 = F_8 ( V_2 , 0x101 , 0x00 , 0x04 ) ;
if ( V_6 )
goto V_33;
V_2 -> V_37 = false ;
return V_6 ;
V_33:
F_13 ( L_6 , V_36 , V_6 ) ;
return V_6 ;
}
static int F_14 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
V_2 -> V_37 = true ;
return 0 ;
}
int F_15 ( struct V_22 * V_23 ,
struct V_38 * V_39 )
{
V_39 -> V_40 = 500 ;
V_39 -> V_41 = V_23 -> V_42 . V_43 . V_44 * 2 ;
V_39 -> V_45 = ( V_23 -> V_42 . V_43 . V_44 * 2 ) + 1 ;
return 0 ;
}
static int F_16 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
struct V_46 * V_47 = & V_23 -> V_48 ;
int V_6 , V_21 ;
static T_1 V_49 [ 3 ] [ 34 ] = {
{
0x1f , 0xf0 , 0x1f , 0xf0 , 0x1f , 0xfa , 0x00 , 0x17 , 0x00 , 0x41 ,
0x00 , 0x64 , 0x00 , 0x67 , 0x00 , 0x38 , 0x1f , 0xde , 0x1f , 0x7a ,
0x1f , 0x47 , 0x1f , 0x7c , 0x00 , 0x30 , 0x01 , 0x4b , 0x02 , 0x82 ,
0x03 , 0x73 , 0x03 , 0xcf ,
} , {
0x1f , 0xfa , 0x1f , 0xda , 0x1f , 0xc1 , 0x1f , 0xb3 , 0x1f , 0xca ,
0x00 , 0x07 , 0x00 , 0x4d , 0x00 , 0x6d , 0x00 , 0x40 , 0x1f , 0xca ,
0x1f , 0x4d , 0x1f , 0x2a , 0x1f , 0xb2 , 0x00 , 0xec , 0x02 , 0x7e ,
0x03 , 0xd0 , 0x04 , 0x53 ,
} , {
0x00 , 0x10 , 0x00 , 0x0e , 0x1f , 0xf7 , 0x1f , 0xc9 , 0x1f , 0xa0 ,
0x1f , 0xa6 , 0x1f , 0xec , 0x00 , 0x4e , 0x00 , 0x7d , 0x00 , 0x3a ,
0x1f , 0x98 , 0x1f , 0x10 , 0x1f , 0x40 , 0x00 , 0x75 , 0x02 , 0x5f ,
0x04 , 0x24 , 0x04 , 0xdb ,
} ,
} ;
static T_1 V_50 [ 3 ] [ 6 ] = {
{ 0xc3 , 0x0c , 0x44 , 0x33 , 0x33 , 0x30 ,} ,
{ 0xb8 , 0xe3 , 0x93 , 0x99 , 0x99 , 0x98 ,} ,
{ 0xae , 0xba , 0xf3 , 0x26 , 0x66 , 0x64 ,} ,
} ;
F_13 ( L_7 , V_36 ,
V_47 -> V_51 , V_47 -> V_52 , V_47 -> V_53 ) ;
if ( V_23 -> V_42 . V_54 . V_55 )
V_23 -> V_42 . V_54 . V_55 ( V_23 ) ;
switch ( V_47 -> V_52 ) {
case 6000000 :
V_21 = 0 ;
break;
case 7000000 :
V_21 = 1 ;
break;
case 8000000 :
V_21 = 2 ;
break;
default:
F_13 ( L_8 ) ;
return - V_56 ;
}
V_6 = F_8 ( V_2 , 0x008 , V_21 << 1 , 0x06 ) ;
if ( V_6 )
goto V_33;
V_6 = F_5 ( V_2 , 0x11c , & V_49 [ V_21 ] [ 0 ] , 17 ) ;
if ( V_6 )
goto V_33;
V_6 = F_5 ( V_2 , 0x12d , & V_49 [ V_21 ] [ 17 ] , 17 ) ;
if ( V_6 )
goto V_33;
V_6 = F_5 ( V_2 , 0x19d , V_50 [ V_21 ] , 6 ) ;
if ( V_6 )
goto V_33;
return V_6 ;
V_33:
F_13 ( L_6 , V_36 , V_6 ) ;
return V_6 ;
}
static int F_17 ( struct V_22 * V_23 , T_5 * V_57 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
int V_6 ;
T_1 V_20 ;
* V_57 = 0 ;
if ( V_2 -> V_37 )
return 0 ;
V_6 = F_9 ( V_2 , 0x351 , & V_20 , 0x78 ) ;
if ( V_6 )
goto V_33;
if ( V_20 == 11 ) {
* V_57 |= V_58 | V_59 |
V_60 | V_61 | V_62 ;
} else if ( V_20 == 10 ) {
* V_57 |= V_58 | V_59 |
V_60 ;
}
return V_6 ;
V_33:
F_13 ( L_6 , V_36 , V_6 ) ;
return V_6 ;
}
static int F_18 ( struct V_22 * V_23 , T_2 * V_63 )
{
* V_63 = 0 ;
return 0 ;
}
static int F_19 ( struct V_22 * V_23 , T_4 * V_64 )
{
* V_64 = 0 ;
return 0 ;
}
static int F_20 ( struct V_22 * V_23 , T_4 * V_65 )
{
* V_65 = 0 ;
return 0 ;
}
static int F_21 ( struct V_22 * V_23 , T_2 * V_66 )
{
* V_66 = 0 ;
return 0 ;
}
static T_4 F_22 ( struct V_67 * V_68 )
{
return V_69 ;
}
static int F_23 ( struct V_67 * V_70 ,
struct V_8 V_9 [] , int V_25 )
{
struct V_1 * V_2 = F_24 ( V_70 ) ;
int V_6 ;
V_6 = F_8 ( V_2 , 0x101 , 0x08 , 0x08 ) ;
if ( V_6 )
goto V_33;
V_6 = F_2 ( V_2 -> V_14 , V_9 , V_25 ) ;
if ( V_6 < 0 )
F_3 ( L_9 , V_6 ) ;
return V_6 ;
V_33:
F_13 ( L_6 , V_36 , V_6 ) ;
return V_6 ;
}
struct V_67 * F_25 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
return & V_2 -> V_71 ;
}
static void F_26 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
F_27 ( & V_2 -> V_71 ) ;
F_28 ( V_2 ) ;
}
struct V_22 * F_29 ( const struct V_72 * V_11 ,
struct V_67 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_6 = 0 ;
T_1 V_20 ;
V_2 = F_30 ( sizeof( struct V_1 ) , V_73 ) ;
if ( V_2 == NULL )
goto V_33;
V_2 -> V_14 = V_14 ;
memcpy ( & V_2 -> V_11 , V_11 , sizeof( struct V_72 ) ) ;
V_6 = F_7 ( V_2 , 0x000 , & V_20 ) ;
if ( V_6 )
goto V_33;
memcpy ( & V_2 -> V_23 . V_42 , & V_74 , sizeof( struct V_75 ) ) ;
V_2 -> V_23 . V_24 = V_2 ;
F_31 ( V_2 -> V_71 . V_76 , L_10 ,
sizeof( V_2 -> V_71 . V_76 ) ) ;
V_2 -> V_71 . V_77 = & V_78 ;
V_2 -> V_71 . V_79 = NULL ;
F_32 ( & V_2 -> V_71 , V_2 ) ;
if ( F_33 ( & V_2 -> V_71 ) < 0 ) {
V_33 ( L_11 ) ;
goto V_33;
}
V_2 -> V_37 = true ;
return & V_2 -> V_23 ;
V_33:
F_13 ( L_6 , V_36 , V_6 ) ;
F_28 ( V_2 ) ;
return NULL ;
}
