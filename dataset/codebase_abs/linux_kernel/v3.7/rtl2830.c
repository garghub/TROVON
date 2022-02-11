static int F_1 ( struct V_1 * V_2 , T_1 V_3 , const T_1 * V_4 , int V_5 )
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
F_3 ( & V_2 -> V_14 -> V_15 , L_1 \
L_2 , V_16 , V_6 , V_3 , V_5 ) ;
V_6 = - V_17 ;
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
. V_13 = V_18 ,
. V_5 = V_5 ,
. V_7 = V_4 ,
}
} ;
V_6 = F_2 ( V_2 -> V_14 , V_9 , 2 ) ;
if ( V_6 == 2 ) {
V_6 = 0 ;
} else {
F_3 ( & V_2 -> V_14 -> V_15 , L_3 \
L_2 , V_16 , V_6 , V_3 , V_5 ) ;
V_6 = - V_17 ;
}
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_3 , const T_1 * V_4 ,
int V_5 )
{
int V_6 ;
T_1 V_19 = ( V_3 >> 0 ) & 0xff ;
T_1 V_20 = ( V_3 >> 8 ) & 0xff ;
if ( V_20 != V_2 -> V_20 ) {
V_6 = F_1 ( V_2 , 0x00 , & V_20 , 1 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_20 = V_20 ;
}
return F_1 ( V_2 , V_19 , V_4 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_19 = ( V_3 >> 0 ) & 0xff ;
T_1 V_20 = ( V_3 >> 8 ) & 0xff ;
if ( V_20 != V_2 -> V_20 ) {
V_6 = F_1 ( V_2 , 0x00 , & V_20 , 1 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_20 = V_20 ;
}
return F_4 ( V_2 , V_19 , V_4 , V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 )
{
return F_6 ( V_2 , V_3 , V_4 , 1 ) ;
}
int F_8 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_4 , T_1 V_21 )
{
int V_6 ;
T_1 V_22 ;
if ( V_21 != 0xff ) {
V_6 = F_6 ( V_2 , V_3 , & V_22 , 1 ) ;
if ( V_6 )
return V_6 ;
V_4 &= V_21 ;
V_22 &= ~ V_21 ;
V_4 |= V_22 ;
}
return F_5 ( V_2 , V_3 , & V_4 , 1 ) ;
}
int F_9 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 , T_1 V_21 )
{
int V_6 , V_23 ;
T_1 V_22 ;
V_6 = F_6 ( V_2 , V_3 , & V_22 , 1 ) ;
if ( V_6 )
return V_6 ;
V_22 &= V_21 ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ ) {
if ( ( V_21 >> V_23 ) & 0x01 )
break;
}
* V_4 = V_22 >> V_23 ;
return 0 ;
}
static int F_10 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
int V_6 , V_23 ;
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
for ( V_23 = 0 ; V_23 < F_11 ( V_28 ) ; V_23 ++ ) {
V_6 = F_8 ( V_2 , V_28 [ V_23 ] . V_3 , V_28 [ V_23 ] . V_4 ,
V_28 [ V_23 ] . V_21 ) ;
if ( V_6 )
goto V_33;
}
V_6 = F_5 ( V_2 , 0x18f , L_4 , 2 ) ;
if ( V_6 )
goto V_33;
V_6 = F_5 ( V_2 , 0x195 ,
L_5 , 8 ) ;
if ( V_6 )
goto V_33;
V_6 = F_8 ( V_2 , 0x101 , 0x04 , 0x04 ) ;
if ( V_6 )
goto V_33;
V_6 = F_8 ( V_2 , 0x101 , 0x00 , 0x04 ) ;
if ( V_6 )
goto V_33;
V_2 -> V_34 = false ;
return V_6 ;
V_33:
F_12 ( & V_2 -> V_14 -> V_15 , L_6 , V_35 , V_6 ) ;
return V_6 ;
}
static int F_13 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
V_2 -> V_34 = true ;
return 0 ;
}
int F_14 ( struct V_24 * V_25 ,
struct V_36 * V_37 )
{
V_37 -> V_38 = 500 ;
V_37 -> V_39 = V_25 -> V_40 . V_41 . V_42 * 2 ;
V_37 -> V_43 = ( V_25 -> V_40 . V_41 . V_42 * 2 ) + 1 ;
return 0 ;
}
static int F_15 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
struct V_44 * V_45 = & V_25 -> V_46 ;
int V_6 , V_23 ;
T_3 V_47 ;
T_1 V_7 [ 3 ] , V_22 ;
T_4 V_48 , V_49 ;
static const T_1 V_50 [ 3 ] [ 34 ] = {
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
static const T_1 V_51 [ 3 ] [ 6 ] = {
{ 0xc3 , 0x0c , 0x44 , 0x33 , 0x33 , 0x30 } ,
{ 0xb8 , 0xe3 , 0x93 , 0x99 , 0x99 , 0x98 } ,
{ 0xae , 0xba , 0xf3 , 0x26 , 0x66 , 0x64 } ,
} ;
F_12 ( & V_2 -> V_14 -> V_15 ,
L_7 ,
V_35 , V_45 -> V_52 , V_45 -> V_53 , V_45 -> V_54 ) ;
if ( V_25 -> V_40 . V_55 . V_56 )
V_25 -> V_40 . V_55 . V_56 ( V_25 ) ;
switch ( V_45 -> V_53 ) {
case 6000000 :
V_23 = 0 ;
break;
case 7000000 :
V_23 = 1 ;
break;
case 8000000 :
V_23 = 2 ;
break;
default:
F_12 ( & V_2 -> V_14 -> V_15 , L_8 , V_35 ) ;
return - V_57 ;
}
V_6 = F_8 ( V_2 , 0x008 , V_23 << 1 , 0x06 ) ;
if ( V_6 )
goto V_33;
if ( V_25 -> V_40 . V_55 . V_58 )
V_6 = V_25 -> V_40 . V_55 . V_58 ( V_25 , & V_49 ) ;
else
V_6 = - V_57 ;
if ( V_6 < 0 )
goto V_33;
V_47 = V_49 % V_2 -> V_11 . V_59 ;
V_47 *= 0x400000 ;
V_47 = F_16 ( V_47 , V_2 -> V_11 . V_59 ) ;
V_47 = - V_47 ;
V_48 = V_47 & 0x3fffff ;
F_12 ( & V_2 -> V_14 -> V_15 , L_9 ,
V_35 , V_49 , V_48 ) ;
V_6 = F_9 ( V_2 , 0x119 , & V_22 , 0xc0 ) ;
if ( V_6 )
goto V_33;
V_7 [ 0 ] = V_22 << 6 ;
V_7 [ 0 ] |= ( V_48 >> 16 ) & 0x3f ;
V_7 [ 1 ] = ( V_48 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_48 >> 0 ) & 0xff ;
V_6 = F_5 ( V_2 , 0x119 , V_7 , 3 ) ;
if ( V_6 )
goto V_33;
V_6 = F_5 ( V_2 , 0x11c , & V_50 [ V_23 ] [ 0 ] , 17 ) ;
if ( V_6 )
goto V_33;
V_6 = F_5 ( V_2 , 0x12d , & V_50 [ V_23 ] [ 17 ] , 17 ) ;
if ( V_6 )
goto V_33;
V_6 = F_5 ( V_2 , 0x19d , V_51 [ V_23 ] , 6 ) ;
if ( V_6 )
goto V_33;
return V_6 ;
V_33:
F_12 ( & V_2 -> V_14 -> V_15 , L_6 , V_35 , V_6 ) ;
return V_6 ;
}
static int F_17 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
struct V_44 * V_45 = & V_25 -> V_46 ;
int V_6 ;
T_1 V_7 [ 3 ] ;
if ( V_2 -> V_34 )
return 0 ;
V_6 = F_6 ( V_2 , 0x33c , V_7 , 2 ) ;
if ( V_6 )
goto V_33;
V_6 = F_7 ( V_2 , 0x351 , & V_7 [ 2 ] ) ;
if ( V_6 )
goto V_33;
F_12 ( & V_2 -> V_14 -> V_15 , L_10 , V_35 , 3 , V_7 ) ;
switch ( ( V_7 [ 0 ] >> 2 ) & 3 ) {
case 0 :
V_45 -> V_60 = V_61 ;
break;
case 1 :
V_45 -> V_60 = V_62 ;
break;
case 2 :
V_45 -> V_60 = V_63 ;
break;
}
switch ( ( V_7 [ 2 ] >> 2 ) & 1 ) {
case 0 :
V_45 -> V_64 = V_65 ;
break;
case 1 :
V_45 -> V_64 = V_66 ;
}
switch ( ( V_7 [ 2 ] >> 0 ) & 3 ) {
case 0 :
V_45 -> V_67 = V_68 ;
break;
case 1 :
V_45 -> V_67 = V_69 ;
break;
case 2 :
V_45 -> V_67 = V_70 ;
break;
case 3 :
V_45 -> V_67 = V_71 ;
break;
}
switch ( ( V_7 [ 0 ] >> 4 ) & 7 ) {
case 0 :
V_45 -> V_72 = V_73 ;
break;
case 1 :
V_45 -> V_72 = V_74 ;
break;
case 2 :
V_45 -> V_72 = V_75 ;
break;
case 3 :
V_45 -> V_72 = V_76 ;
break;
}
switch ( ( V_7 [ 1 ] >> 3 ) & 7 ) {
case 0 :
V_45 -> V_77 = V_78 ;
break;
case 1 :
V_45 -> V_77 = V_79 ;
break;
case 2 :
V_45 -> V_77 = V_80 ;
break;
case 3 :
V_45 -> V_77 = V_81 ;
break;
case 4 :
V_45 -> V_77 = V_82 ;
break;
}
switch ( ( V_7 [ 1 ] >> 0 ) & 7 ) {
case 0 :
V_45 -> V_83 = V_78 ;
break;
case 1 :
V_45 -> V_83 = V_79 ;
break;
case 2 :
V_45 -> V_83 = V_80 ;
break;
case 3 :
V_45 -> V_83 = V_81 ;
break;
case 4 :
V_45 -> V_83 = V_82 ;
break;
}
return 0 ;
V_33:
F_12 ( & V_2 -> V_14 -> V_15 , L_6 , V_35 , V_6 ) ;
return V_6 ;
}
static int F_18 ( struct V_24 * V_25 , T_5 * V_84 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
int V_6 ;
T_1 V_22 ;
* V_84 = 0 ;
if ( V_2 -> V_34 )
return 0 ;
V_6 = F_9 ( V_2 , 0x351 , & V_22 , 0x78 ) ;
if ( V_6 )
goto V_33;
if ( V_22 == 11 ) {
* V_84 |= V_85 | V_86 |
V_87 | V_88 | V_89 ;
} else if ( V_22 == 10 ) {
* V_84 |= V_85 | V_86 |
V_87 ;
}
return V_6 ;
V_33:
F_12 ( & V_2 -> V_14 -> V_15 , L_6 , V_35 , V_6 ) ;
return V_6 ;
}
static int F_19 ( struct V_24 * V_25 , T_2 * V_90 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
int V_6 , V_72 , V_91 ;
T_1 V_7 [ 2 ] , V_22 ;
T_2 V_92 ;
#define F_20 3
#define F_21 4
static const T_4 V_93 [ F_20 ] [ F_21 ] = {
{ 70705899 , 70705899 , 70705899 , 70705899 } ,
{ 82433173 , 82433173 , 87483115 , 94445660 } ,
{ 92888734 , 92888734 , 95487525 , 99770748 } ,
} ;
if ( V_2 -> V_34 )
return 0 ;
V_6 = F_7 ( V_2 , 0x33c , & V_22 ) ;
if ( V_6 )
goto V_33;
V_91 = ( V_22 >> 2 ) & 0x03 ;
if ( V_91 > F_20 - 1 )
goto V_33;
V_72 = ( V_22 >> 4 ) & 0x07 ;
if ( V_72 > F_21 - 1 )
goto V_33;
V_6 = F_6 ( V_2 , 0x40c , V_7 , 2 ) ;
if ( V_6 )
goto V_33;
V_92 = V_7 [ 0 ] << 8 | V_7 [ 1 ] ;
if ( V_92 )
* V_90 = ( V_93 [ V_91 ] [ V_72 ] -
F_22 ( V_92 ) ) / ( ( 1 << 24 ) / 100 ) ;
else
* V_90 = 0 ;
return 0 ;
V_33:
F_12 ( & V_2 -> V_14 -> V_15 , L_6 , V_35 , V_6 ) ;
return V_6 ;
}
static int F_23 ( struct V_24 * V_25 , T_4 * V_94 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
int V_6 ;
T_1 V_7 [ 2 ] ;
if ( V_2 -> V_34 )
return 0 ;
V_6 = F_6 ( V_2 , 0x34e , V_7 , 2 ) ;
if ( V_6 )
goto V_33;
* V_94 = V_7 [ 0 ] << 8 | V_7 [ 1 ] ;
return 0 ;
V_33:
F_12 ( & V_2 -> V_14 -> V_15 , L_6 , V_35 , V_6 ) ;
return V_6 ;
}
static int F_24 ( struct V_24 * V_25 , T_4 * V_95 )
{
* V_95 = 0 ;
return 0 ;
}
static int F_25 ( struct V_24 * V_25 , T_2 * V_96 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
int V_6 ;
T_1 V_7 [ 2 ] ;
T_2 V_97 , V_98 ;
if ( V_2 -> V_34 )
return 0 ;
V_6 = F_6 ( V_2 , 0x359 , V_7 , 2 ) ;
if ( V_6 )
goto V_33;
V_97 = ( V_7 [ 0 ] << 8 | V_7 [ 1 ] ) & 0x3fff ;
if ( V_97 & ( 1 << 9 ) )
V_98 = - ( ~ ( V_97 - 1 ) & 0x1ff ) ;
else
V_98 = V_97 ;
* V_96 = ( T_1 ) ( 55 - V_98 / 182 ) ;
* V_96 |= * V_96 << 8 ;
return 0 ;
V_33:
F_12 ( & V_2 -> V_14 -> V_15 , L_6 , V_35 , V_6 ) ;
return V_6 ;
}
static T_4 F_26 ( struct V_99 * V_100 )
{
return V_101 ;
}
static int F_27 ( struct V_99 * V_102 ,
struct V_8 V_9 [] , int V_47 )
{
struct V_1 * V_2 = F_28 ( V_102 ) ;
int V_6 ;
V_6 = F_8 ( V_2 , 0x101 , 0x08 , 0x08 ) ;
if ( V_6 )
goto V_33;
V_6 = F_2 ( V_2 -> V_14 , V_9 , V_47 ) ;
if ( V_6 < 0 )
F_3 ( & V_2 -> V_14 -> V_15 , L_11 ,
V_16 , V_6 ) ;
return V_6 ;
V_33:
F_12 ( & V_2 -> V_14 -> V_15 , L_6 , V_35 , V_6 ) ;
return V_6 ;
}
struct V_99 * F_29 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
return & V_2 -> V_103 ;
}
static void F_30 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
F_31 ( & V_2 -> V_103 ) ;
F_32 ( V_2 ) ;
}
struct V_24 * F_33 ( const struct V_104 * V_11 ,
struct V_99 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_6 = 0 ;
T_1 V_22 ;
V_2 = F_34 ( sizeof( struct V_1 ) , V_105 ) ;
if ( V_2 == NULL )
goto V_33;
V_2 -> V_14 = V_14 ;
memcpy ( & V_2 -> V_11 , V_11 , sizeof( struct V_104 ) ) ;
V_6 = F_7 ( V_2 , 0x000 , & V_22 ) ;
if ( V_6 )
goto V_33;
memcpy ( & V_2 -> V_25 . V_40 , & V_106 , sizeof( struct V_107 ) ) ;
V_2 -> V_25 . V_26 = V_2 ;
F_35 ( V_2 -> V_103 . V_108 , L_12 ,
sizeof( V_2 -> V_103 . V_108 ) ) ;
V_2 -> V_103 . V_109 = & V_110 ;
V_2 -> V_103 . V_111 = NULL ;
F_36 ( & V_2 -> V_103 , V_2 ) ;
if ( F_37 ( & V_2 -> V_103 ) < 0 ) {
F_38 ( & V_14 -> V_15 ,
L_13 ,
V_16 ) ;
goto V_33;
}
V_2 -> V_34 = true ;
return & V_2 -> V_25 ;
V_33:
F_12 ( & V_14 -> V_15 , L_6 , V_35 , V_6 ) ;
F_32 ( V_2 ) ;
return NULL ;
}
