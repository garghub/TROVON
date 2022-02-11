static int F_1 ( struct V_1 * V_2 , T_1 V_3 , const T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_7 [ V_8 ] ;
struct V_9 V_10 [ 1 ] = {
{
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = 0 ,
. V_5 = 1 + V_5 ,
. V_7 = V_7 ,
}
} ;
if ( 1 + V_5 > sizeof( V_7 ) ) {
F_2 ( & V_2 -> V_15 -> V_16 ,
L_1 ,
V_17 , V_3 , V_5 ) ;
return - V_18 ;
}
V_7 [ 0 ] = V_3 ;
memcpy ( & V_7 [ 1 ] , V_4 , V_5 ) ;
V_6 = F_3 ( V_2 -> V_15 , V_10 , 1 ) ;
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_2 ( & V_2 -> V_15 -> V_16 , L_2 \
L_3 , V_17 , V_6 , V_3 , V_5 ) ;
V_6 = - V_19 ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
struct V_9 V_10 [ 2 ] = {
{
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = 0 ,
. V_5 = 1 ,
. V_7 = & V_3 ,
} , {
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = V_20 ,
. V_5 = V_5 ,
. V_7 = V_4 ,
}
} ;
V_6 = F_3 ( V_2 -> V_15 , V_10 , 2 ) ;
if ( V_6 == 2 ) {
V_6 = 0 ;
} else {
F_2 ( & V_2 -> V_15 -> V_16 , L_4 \
L_3 , V_17 , V_6 , V_3 , V_5 ) ;
V_6 = - V_19 ;
}
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_3 , const T_1 * V_4 ,
int V_5 )
{
int V_6 ;
T_1 V_21 = ( V_3 >> 0 ) & 0xff ;
T_1 V_22 = ( V_3 >> 8 ) & 0xff ;
if ( V_22 != V_2 -> V_22 ) {
V_6 = F_1 ( V_2 , 0x00 , & V_22 , 1 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_22 = V_22 ;
}
return F_1 ( V_2 , V_21 , V_4 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_21 = ( V_3 >> 0 ) & 0xff ;
T_1 V_22 = ( V_3 >> 8 ) & 0xff ;
if ( V_22 != V_2 -> V_22 ) {
V_6 = F_1 ( V_2 , 0x00 , & V_22 , 1 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_22 = V_22 ;
}
return F_4 ( V_2 , V_21 , V_4 , V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 )
{
return F_6 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_4 , T_1 V_23 )
{
int V_6 ;
T_1 V_24 ;
if ( V_23 != 0xff ) {
V_6 = F_6 ( V_2 , V_3 , & V_24 , 1 ) ;
if ( V_6 )
return V_6 ;
V_4 &= V_23 ;
V_24 &= ~ V_23 ;
V_4 |= V_24 ;
}
return F_5 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 , T_1 V_23 )
{
int V_6 , V_25 ;
T_1 V_24 ;
V_6 = F_6 ( V_2 , V_3 , & V_24 , 1 ) ;
if ( V_6 )
return V_6 ;
V_24 &= V_23 ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ ) {
if ( ( V_23 >> V_25 ) & 0x01 )
break;
}
* V_4 = V_24 >> V_25 ;
return 0 ;
}
static int F_10 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
int V_6 , V_25 ;
struct V_29 V_30 [] = {
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
{ 0x106 , V_2 -> V_12 . V_31 , 0x3f } ,
{ 0x107 , V_2 -> V_12 . V_32 , 0x3f } ,
{ 0x112 , 0x28 , 0xff } ,
{ 0x103 , V_2 -> V_12 . V_33 , 0xff } ,
{ 0x00a , 0x02 , 0x07 } ,
{ 0x140 , 0x0c , 0x3c } ,
{ 0x140 , 0x40 , 0xc0 } ,
{ 0x15b , 0x05 , 0x07 } ,
{ 0x15b , 0x28 , 0x38 } ,
{ 0x15c , 0x05 , 0x07 } ,
{ 0x15c , 0x28 , 0x38 } ,
{ 0x115 , V_2 -> V_12 . V_34 , 0x01 } ,
{ 0x16f , 0x01 , 0x07 } ,
{ 0x170 , 0x18 , 0x38 } ,
{ 0x172 , 0x0f , 0x0f } ,
{ 0x173 , 0x08 , 0x38 } ,
{ 0x175 , 0x01 , 0x07 } ,
{ 0x176 , 0x00 , 0xc0 } ,
} ;
for ( V_25 = 0 ; V_25 < F_11 ( V_30 ) ; V_25 ++ ) {
V_6 = F_8 ( V_2 , V_30 [ V_25 ] . V_3 , V_30 [ V_25 ] . V_4 ,
V_30 [ V_25 ] . V_23 ) ;
if ( V_6 )
goto V_35;
}
V_6 = F_5 ( V_2 , 0x18f , L_5 , 2 ) ;
if ( V_6 )
goto V_35;
V_6 = F_5 ( V_2 , 0x195 ,
L_6 , 8 ) ;
if ( V_6 )
goto V_35;
V_6 = F_8 ( V_2 , 0x101 , 0x04 , 0x04 ) ;
if ( V_6 )
goto V_35;
V_6 = F_8 ( V_2 , 0x101 , 0x00 , 0x04 ) ;
if ( V_6 )
goto V_35;
V_2 -> V_36 = false ;
return V_6 ;
V_35:
F_12 ( & V_2 -> V_15 -> V_16 , L_7 , V_37 , V_6 ) ;
return V_6 ;
}
static int F_13 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
V_2 -> V_36 = true ;
return 0 ;
}
static int F_14 ( struct V_26 * V_27 ,
struct V_38 * V_39 )
{
V_39 -> V_40 = 500 ;
V_39 -> V_41 = V_27 -> V_42 . V_43 . V_44 * 2 ;
V_39 -> V_45 = ( V_27 -> V_42 . V_43 . V_44 * 2 ) + 1 ;
return 0 ;
}
static int F_15 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
struct V_46 * V_47 = & V_27 -> V_48 ;
int V_6 , V_25 ;
T_3 V_49 ;
T_1 V_7 [ 3 ] , V_24 ;
T_4 V_50 , V_51 ;
static const T_1 V_52 [ 3 ] [ 34 ] = {
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
static const T_1 V_53 [ 3 ] [ 6 ] = {
{ 0xc3 , 0x0c , 0x44 , 0x33 , 0x33 , 0x30 } ,
{ 0xb8 , 0xe3 , 0x93 , 0x99 , 0x99 , 0x98 } ,
{ 0xae , 0xba , 0xf3 , 0x26 , 0x66 , 0x64 } ,
} ;
F_12 ( & V_2 -> V_15 -> V_16 ,
L_8 ,
V_37 , V_47 -> V_54 , V_47 -> V_55 , V_47 -> V_56 ) ;
if ( V_27 -> V_42 . V_57 . V_58 )
V_27 -> V_42 . V_57 . V_58 ( V_27 ) ;
switch ( V_47 -> V_55 ) {
case 6000000 :
V_25 = 0 ;
break;
case 7000000 :
V_25 = 1 ;
break;
case 8000000 :
V_25 = 2 ;
break;
default:
F_12 ( & V_2 -> V_15 -> V_16 , L_9 , V_37 ) ;
return - V_18 ;
}
V_6 = F_8 ( V_2 , 0x008 , V_25 << 1 , 0x06 ) ;
if ( V_6 )
goto V_35;
if ( V_27 -> V_42 . V_57 . V_59 )
V_6 = V_27 -> V_42 . V_57 . V_59 ( V_27 , & V_51 ) ;
else
V_6 = - V_18 ;
if ( V_6 < 0 )
goto V_35;
V_49 = V_51 % V_2 -> V_12 . V_60 ;
V_49 *= 0x400000 ;
V_49 = F_16 ( V_49 , V_2 -> V_12 . V_60 ) ;
V_49 = - V_49 ;
V_50 = V_49 & 0x3fffff ;
F_12 ( & V_2 -> V_15 -> V_16 , L_10 ,
V_37 , V_51 , V_50 ) ;
V_6 = F_9 ( V_2 , 0x119 , & V_24 , 0xc0 ) ;
if ( V_6 )
goto V_35;
V_7 [ 0 ] = V_24 << 6 ;
V_7 [ 0 ] |= ( V_50 >> 16 ) & 0x3f ;
V_7 [ 1 ] = ( V_50 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_50 >> 0 ) & 0xff ;
V_6 = F_5 ( V_2 , 0x119 , V_7 , 3 ) ;
if ( V_6 )
goto V_35;
V_6 = F_5 ( V_2 , 0x11c , & V_52 [ V_25 ] [ 0 ] , 17 ) ;
if ( V_6 )
goto V_35;
V_6 = F_5 ( V_2 , 0x12d , & V_52 [ V_25 ] [ 17 ] , 17 ) ;
if ( V_6 )
goto V_35;
V_6 = F_5 ( V_2 , 0x19d , V_53 [ V_25 ] , 6 ) ;
if ( V_6 )
goto V_35;
return V_6 ;
V_35:
F_12 ( & V_2 -> V_15 -> V_16 , L_7 , V_37 , V_6 ) ;
return V_6 ;
}
static int F_17 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
struct V_46 * V_47 = & V_27 -> V_48 ;
int V_6 ;
T_1 V_7 [ 3 ] ;
if ( V_2 -> V_36 )
return 0 ;
V_6 = F_6 ( V_2 , 0x33c , V_7 , 2 ) ;
if ( V_6 )
goto V_35;
V_6 = F_7 ( V_2 , 0x351 , & V_7 [ 2 ] ) ;
if ( V_6 )
goto V_35;
F_12 ( & V_2 -> V_15 -> V_16 , L_11 , V_37 , 3 , V_7 ) ;
switch ( ( V_7 [ 0 ] >> 2 ) & 3 ) {
case 0 :
V_47 -> V_61 = V_62 ;
break;
case 1 :
V_47 -> V_61 = V_63 ;
break;
case 2 :
V_47 -> V_61 = V_64 ;
break;
}
switch ( ( V_7 [ 2 ] >> 2 ) & 1 ) {
case 0 :
V_47 -> V_65 = V_66 ;
break;
case 1 :
V_47 -> V_65 = V_67 ;
}
switch ( ( V_7 [ 2 ] >> 0 ) & 3 ) {
case 0 :
V_47 -> V_68 = V_69 ;
break;
case 1 :
V_47 -> V_68 = V_70 ;
break;
case 2 :
V_47 -> V_68 = V_71 ;
break;
case 3 :
V_47 -> V_68 = V_72 ;
break;
}
switch ( ( V_7 [ 0 ] >> 4 ) & 7 ) {
case 0 :
V_47 -> V_73 = V_74 ;
break;
case 1 :
V_47 -> V_73 = V_75 ;
break;
case 2 :
V_47 -> V_73 = V_76 ;
break;
case 3 :
V_47 -> V_73 = V_77 ;
break;
}
switch ( ( V_7 [ 1 ] >> 3 ) & 7 ) {
case 0 :
V_47 -> V_78 = V_79 ;
break;
case 1 :
V_47 -> V_78 = V_80 ;
break;
case 2 :
V_47 -> V_78 = V_81 ;
break;
case 3 :
V_47 -> V_78 = V_82 ;
break;
case 4 :
V_47 -> V_78 = V_83 ;
break;
}
switch ( ( V_7 [ 1 ] >> 0 ) & 7 ) {
case 0 :
V_47 -> V_84 = V_79 ;
break;
case 1 :
V_47 -> V_84 = V_80 ;
break;
case 2 :
V_47 -> V_84 = V_81 ;
break;
case 3 :
V_47 -> V_84 = V_82 ;
break;
case 4 :
V_47 -> V_84 = V_83 ;
break;
}
return 0 ;
V_35:
F_12 ( & V_2 -> V_15 -> V_16 , L_7 , V_37 , V_6 ) ;
return V_6 ;
}
static int F_18 ( struct V_26 * V_27 , T_5 * V_85 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
int V_6 ;
T_1 V_24 ;
* V_85 = 0 ;
if ( V_2 -> V_36 )
return 0 ;
V_6 = F_9 ( V_2 , 0x351 , & V_24 , 0x78 ) ;
if ( V_6 )
goto V_35;
if ( V_24 == 11 ) {
* V_85 |= V_86 | V_87 |
V_88 | V_89 | V_90 ;
} else if ( V_24 == 10 ) {
* V_85 |= V_86 | V_87 |
V_88 ;
}
return V_6 ;
V_35:
F_12 ( & V_2 -> V_15 -> V_16 , L_7 , V_37 , V_6 ) ;
return V_6 ;
}
static int F_19 ( struct V_26 * V_27 , T_2 * V_91 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
int V_6 , V_73 , V_92 ;
T_1 V_7 [ 2 ] , V_24 ;
T_2 V_93 ;
#define F_20 3
#define F_21 4
static const T_4 V_94 [ F_20 ] [ F_21 ] = {
{ 70705899 , 70705899 , 70705899 , 70705899 } ,
{ 82433173 , 82433173 , 87483115 , 94445660 } ,
{ 92888734 , 92888734 , 95487525 , 99770748 } ,
} ;
if ( V_2 -> V_36 )
return 0 ;
V_6 = F_7 ( V_2 , 0x33c , & V_24 ) ;
if ( V_6 )
goto V_35;
V_92 = ( V_24 >> 2 ) & 0x03 ;
if ( V_92 > F_20 - 1 )
goto V_35;
V_73 = ( V_24 >> 4 ) & 0x07 ;
if ( V_73 > F_21 - 1 )
goto V_35;
V_6 = F_6 ( V_2 , 0x40c , V_7 , 2 ) ;
if ( V_6 )
goto V_35;
V_93 = V_7 [ 0 ] << 8 | V_7 [ 1 ] ;
if ( V_93 )
* V_91 = ( V_94 [ V_92 ] [ V_73 ] -
F_22 ( V_93 ) ) / ( ( 1 << 24 ) / 100 ) ;
else
* V_91 = 0 ;
return 0 ;
V_35:
F_12 ( & V_2 -> V_15 -> V_16 , L_7 , V_37 , V_6 ) ;
return V_6 ;
}
static int F_23 ( struct V_26 * V_27 , T_4 * V_95 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
int V_6 ;
T_1 V_7 [ 2 ] ;
if ( V_2 -> V_36 )
return 0 ;
V_6 = F_6 ( V_2 , 0x34e , V_7 , 2 ) ;
if ( V_6 )
goto V_35;
* V_95 = V_7 [ 0 ] << 8 | V_7 [ 1 ] ;
return 0 ;
V_35:
F_12 ( & V_2 -> V_15 -> V_16 , L_7 , V_37 , V_6 ) ;
return V_6 ;
}
static int F_24 ( struct V_26 * V_27 , T_4 * V_96 )
{
* V_96 = 0 ;
return 0 ;
}
static int F_25 ( struct V_26 * V_27 , T_2 * V_97 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
int V_6 ;
T_1 V_7 [ 2 ] ;
T_2 V_98 , V_99 ;
if ( V_2 -> V_36 )
return 0 ;
V_6 = F_6 ( V_2 , 0x359 , V_7 , 2 ) ;
if ( V_6 )
goto V_35;
V_98 = ( V_7 [ 0 ] << 8 | V_7 [ 1 ] ) & 0x3fff ;
if ( V_98 & ( 1 << 9 ) )
V_99 = - ( ~ ( V_98 - 1 ) & 0x1ff ) ;
else
V_99 = V_98 ;
* V_97 = ( T_1 ) ( 55 - V_99 / 182 ) ;
* V_97 |= * V_97 << 8 ;
return 0 ;
V_35:
F_12 ( & V_2 -> V_15 -> V_16 , L_7 , V_37 , V_6 ) ;
return V_6 ;
}
static T_4 F_26 ( struct V_100 * V_101 )
{
return V_102 ;
}
static int F_27 ( struct V_100 * V_103 ,
struct V_9 V_10 [] , int V_49 )
{
struct V_1 * V_2 = F_28 ( V_103 ) ;
int V_6 ;
V_6 = F_8 ( V_2 , 0x101 , 0x08 , 0x08 ) ;
if ( V_6 )
goto V_35;
V_6 = F_3 ( V_2 -> V_15 , V_10 , V_49 ) ;
if ( V_6 < 0 )
F_2 ( & V_2 -> V_15 -> V_16 , L_12 ,
V_17 , V_6 ) ;
return V_6 ;
V_35:
F_12 ( & V_2 -> V_15 -> V_16 , L_7 , V_37 , V_6 ) ;
return V_6 ;
}
struct V_100 * F_29 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
return & V_2 -> V_104 ;
}
static void F_30 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
F_31 ( & V_2 -> V_104 ) ;
F_32 ( V_2 ) ;
}
struct V_26 * F_33 ( const struct V_105 * V_12 ,
struct V_100 * V_15 )
{
struct V_1 * V_2 = NULL ;
int V_6 = 0 ;
T_1 V_24 ;
V_2 = F_34 ( sizeof( struct V_1 ) , V_106 ) ;
if ( V_2 == NULL )
goto V_35;
V_2 -> V_15 = V_15 ;
memcpy ( & V_2 -> V_12 , V_12 , sizeof( struct V_105 ) ) ;
V_6 = F_7 ( V_2 , 0x000 , & V_24 ) ;
if ( V_6 )
goto V_35;
memcpy ( & V_2 -> V_27 . V_42 , & V_107 , sizeof( struct V_108 ) ) ;
V_2 -> V_27 . V_28 = V_2 ;
F_35 ( V_2 -> V_104 . V_109 , L_13 ,
sizeof( V_2 -> V_104 . V_109 ) ) ;
V_2 -> V_104 . V_110 = & V_111 ;
V_2 -> V_104 . V_112 = NULL ;
V_2 -> V_104 . V_16 . V_113 = & V_15 -> V_16 ;
F_36 ( & V_2 -> V_104 , V_2 ) ;
if ( F_37 ( & V_2 -> V_104 ) < 0 ) {
F_38 ( & V_15 -> V_16 ,
L_14 ,
V_17 ) ;
goto V_35;
}
V_2 -> V_36 = true ;
return & V_2 -> V_27 ;
V_35:
F_12 ( & V_15 -> V_16 , L_7 , V_37 , V_6 ) ;
F_32 ( V_2 ) ;
return NULL ;
}
