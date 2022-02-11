static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
const void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
F_3 ( V_2 -> V_9 ) ;
V_8 = F_4 ( V_7 -> V_10 , V_3 , V_4 , V_5 ) ;
F_5 ( V_2 -> V_9 ) ;
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_11 , unsigned int V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
F_3 ( V_2 -> V_9 ) ;
V_8 = F_7 ( V_7 -> V_10 , V_3 , V_11 , V_4 ) ;
F_5 ( V_2 -> V_9 ) ;
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
F_3 ( V_2 -> V_9 ) ;
V_8 = F_9 ( V_7 -> V_10 , V_3 , V_4 , V_5 ) ;
F_5 ( V_2 -> V_9 ) ;
return V_8 ;
}
static int F_10 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = & V_7 -> V_13 . V_17 ;
int V_8 , V_18 ;
struct V_19 V_20 [] = {
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
{ 0x106 , V_7 -> V_21 -> V_22 , 0x3f } ,
{ 0x107 , V_7 -> V_21 -> V_23 , 0x3f } ,
{ 0x112 , 0x28 , 0xff } ,
{ 0x103 , V_7 -> V_21 -> V_24 , 0xff } ,
{ 0x00a , 0x02 , 0x07 } ,
{ 0x140 , 0x0c , 0x3c } ,
{ 0x140 , 0x40 , 0xc0 } ,
{ 0x15b , 0x05 , 0x07 } ,
{ 0x15b , 0x28 , 0x38 } ,
{ 0x15c , 0x05 , 0x07 } ,
{ 0x15c , 0x28 , 0x38 } ,
{ 0x115 , V_7 -> V_21 -> V_25 , 0x01 } ,
{ 0x16f , 0x01 , 0x07 } ,
{ 0x170 , 0x18 , 0x38 } ,
{ 0x172 , 0x0f , 0x0f } ,
{ 0x173 , 0x08 , 0x38 } ,
{ 0x175 , 0x01 , 0x07 } ,
{ 0x176 , 0x00 , 0xc0 } ,
} ;
for ( V_18 = 0 ; V_18 < F_11 ( V_20 ) ; V_18 ++ ) {
V_8 = F_6 ( V_2 , V_20 [ V_18 ] . V_3 , V_20 [ V_18 ] . V_11 ,
V_20 [ V_18 ] . V_4 ) ;
if ( V_8 )
goto V_26;
}
V_8 = F_1 ( V_2 , 0x18f , L_1 , 2 ) ;
if ( V_8 )
goto V_26;
V_8 = F_1 ( V_2 , 0x195 ,
L_2 , 8 ) ;
if ( V_8 )
goto V_26;
V_8 = F_6 ( V_2 , 0x101 , 0x04 , 0x04 ) ;
if ( V_8 )
goto V_26;
V_8 = F_6 ( V_2 , 0x101 , 0x04 , 0x00 ) ;
if ( V_8 )
goto V_26;
V_16 -> V_27 . V_28 = 1 ;
V_16 -> V_27 . V_29 [ 0 ] . V_30 = V_31 ;
V_16 -> V_32 . V_28 = 1 ;
V_16 -> V_32 . V_29 [ 0 ] . V_30 = V_31 ;
V_16 -> V_33 . V_28 = 1 ;
V_16 -> V_33 . V_29 [ 0 ] . V_30 = V_31 ;
V_16 -> V_34 . V_28 = 1 ;
V_16 -> V_34 . V_29 [ 0 ] . V_30 = V_31 ;
F_12 ( & V_7 -> V_35 , F_13 ( 2000 ) ) ;
V_7 -> V_36 = false ;
return V_8 ;
V_26:
F_14 ( & V_2 -> V_7 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_15 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_36 = true ;
F_16 ( & V_7 -> V_35 ) ;
V_7 -> V_37 = 0 ;
return 0 ;
}
static int F_17 ( struct V_12 * V_13 ,
struct V_38 * V_39 )
{
V_39 -> V_40 = 500 ;
V_39 -> V_41 = V_13 -> V_42 . V_43 . V_44 * 2 ;
V_39 -> V_45 = ( V_13 -> V_42 . V_43 . V_44 * 2 ) + 1 ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = & V_13 -> V_17 ;
int V_8 , V_18 ;
T_2 V_46 ;
T_3 V_47 [ 3 ] , V_48 ;
T_4 V_49 , V_50 ;
static const T_3 V_51 [ 3 ] [ 34 ] = {
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
static const T_3 V_52 [ 3 ] [ 6 ] = {
{ 0xc3 , 0x0c , 0x44 , 0x33 , 0x33 , 0x30 } ,
{ 0xb8 , 0xe3 , 0x93 , 0x99 , 0x99 , 0x98 } ,
{ 0xae , 0xba , 0xf3 , 0x26 , 0x66 , 0x64 } ,
} ;
F_14 ( & V_2 -> V_7 , L_4 ,
V_16 -> V_53 , V_16 -> V_54 , V_16 -> V_55 ) ;
if ( V_13 -> V_42 . V_56 . V_57 )
V_13 -> V_42 . V_56 . V_57 ( V_13 ) ;
switch ( V_16 -> V_54 ) {
case 6000000 :
V_18 = 0 ;
break;
case 7000000 :
V_18 = 1 ;
break;
case 8000000 :
V_18 = 2 ;
break;
default:
F_19 ( & V_2 -> V_7 , L_5 ,
V_16 -> V_54 ) ;
return - V_58 ;
}
V_8 = F_6 ( V_2 , 0x008 , 0x06 , V_18 << 1 ) ;
if ( V_8 )
goto V_26;
if ( V_13 -> V_42 . V_56 . V_59 )
V_8 = V_13 -> V_42 . V_56 . V_59 ( V_13 , & V_50 ) ;
else
V_8 = - V_58 ;
if ( V_8 )
goto V_26;
V_46 = V_50 % V_7 -> V_21 -> V_60 ;
V_46 *= 0x400000 ;
V_46 = F_20 ( V_46 , V_7 -> V_21 -> V_60 ) ;
V_46 = - V_46 ;
V_49 = V_46 & 0x3fffff ;
F_14 ( & V_2 -> V_7 , L_6 ,
V_50 , V_49 ) ;
V_47 [ 0 ] = ( V_49 >> 16 ) & 0x3f ;
V_47 [ 1 ] = ( V_49 >> 8 ) & 0xff ;
V_47 [ 2 ] = ( V_49 >> 0 ) & 0xff ;
V_8 = F_8 ( V_2 , 0x119 , & V_48 , 1 ) ;
if ( V_8 )
goto V_26;
V_47 [ 0 ] |= V_48 & 0xc0 ;
V_8 = F_1 ( V_2 , 0x119 , V_47 , 3 ) ;
if ( V_8 )
goto V_26;
V_8 = F_1 ( V_2 , 0x11c , & V_51 [ V_18 ] [ 0 ] , 17 ) ;
if ( V_8 )
goto V_26;
V_8 = F_1 ( V_2 , 0x12d , & V_51 [ V_18 ] [ 17 ] , 17 ) ;
if ( V_8 )
goto V_26;
V_8 = F_1 ( V_2 , 0x19d , V_52 [ V_18 ] , 6 ) ;
if ( V_8 )
goto V_26;
return V_8 ;
V_26:
F_14 ( & V_2 -> V_7 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_21 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = & V_13 -> V_17 ;
int V_8 ;
T_3 V_47 [ 3 ] ;
if ( V_7 -> V_36 )
return 0 ;
V_8 = F_8 ( V_2 , 0x33c , V_47 , 2 ) ;
if ( V_8 )
goto V_26;
V_8 = F_8 ( V_2 , 0x351 , & V_47 [ 2 ] , 1 ) ;
if ( V_8 )
goto V_26;
F_14 ( & V_2 -> V_7 , L_7 , 3 , V_47 ) ;
switch ( ( V_47 [ 0 ] >> 2 ) & 3 ) {
case 0 :
V_16 -> V_61 = V_62 ;
break;
case 1 :
V_16 -> V_61 = V_63 ;
break;
case 2 :
V_16 -> V_61 = V_64 ;
break;
}
switch ( ( V_47 [ 2 ] >> 2 ) & 1 ) {
case 0 :
V_16 -> V_65 = V_66 ;
break;
case 1 :
V_16 -> V_65 = V_67 ;
}
switch ( ( V_47 [ 2 ] >> 0 ) & 3 ) {
case 0 :
V_16 -> V_68 = V_69 ;
break;
case 1 :
V_16 -> V_68 = V_70 ;
break;
case 2 :
V_16 -> V_68 = V_71 ;
break;
case 3 :
V_16 -> V_68 = V_72 ;
break;
}
switch ( ( V_47 [ 0 ] >> 4 ) & 7 ) {
case 0 :
V_16 -> V_73 = V_74 ;
break;
case 1 :
V_16 -> V_73 = V_75 ;
break;
case 2 :
V_16 -> V_73 = V_76 ;
break;
case 3 :
V_16 -> V_73 = V_77 ;
break;
}
switch ( ( V_47 [ 1 ] >> 3 ) & 7 ) {
case 0 :
V_16 -> V_78 = V_79 ;
break;
case 1 :
V_16 -> V_78 = V_80 ;
break;
case 2 :
V_16 -> V_78 = V_81 ;
break;
case 3 :
V_16 -> V_78 = V_82 ;
break;
case 4 :
V_16 -> V_78 = V_83 ;
break;
}
switch ( ( V_47 [ 1 ] >> 0 ) & 7 ) {
case 0 :
V_16 -> V_84 = V_79 ;
break;
case 1 :
V_16 -> V_84 = V_80 ;
break;
case 2 :
V_16 -> V_84 = V_81 ;
break;
case 3 :
V_16 -> V_84 = V_82 ;
break;
case 4 :
V_16 -> V_84 = V_83 ;
break;
}
return 0 ;
V_26:
F_14 ( & V_2 -> V_7 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_22 ( struct V_12 * V_13 , T_5 * V_85 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
T_3 V_48 ;
* V_85 = 0 ;
if ( V_7 -> V_36 )
return 0 ;
V_8 = F_8 ( V_2 , 0x351 , & V_48 , 1 ) ;
if ( V_8 )
goto V_26;
V_48 = ( V_48 >> 3 ) & 0x0f ;
if ( V_48 == 11 ) {
* V_85 |= V_86 | V_87 |
V_88 | V_89 | V_90 ;
} else if ( V_48 == 10 ) {
* V_85 |= V_86 | V_87 |
V_88 ;
}
V_7 -> V_37 = * V_85 ;
return V_8 ;
V_26:
F_14 ( & V_2 -> V_7 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_23 ( struct V_12 * V_13 , T_6 * V_91 )
{
struct V_15 * V_16 = & V_13 -> V_17 ;
if ( V_16 -> V_32 . V_29 [ 0 ] . V_30 == V_92 )
* V_91 = F_24 ( V_16 -> V_32 . V_29 [ 0 ] . V_93 , 100 ) ;
else
* V_91 = 0 ;
return 0 ;
}
static int F_25 ( struct V_12 * V_13 , T_4 * V_94 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
* V_94 = ( V_7 -> V_33 - V_7 -> V_95 ) ;
V_7 -> V_95 = V_7 -> V_33 ;
return 0 ;
}
static int F_26 ( struct V_12 * V_13 , T_4 * V_96 )
{
* V_96 = 0 ;
return 0 ;
}
static int F_27 ( struct V_12 * V_13 , T_6 * V_27 )
{
struct V_15 * V_16 = & V_13 -> V_17 ;
if ( V_16 -> V_27 . V_29 [ 0 ] . V_30 == V_97 )
* V_27 = V_16 -> V_27 . V_29 [ 0 ] . V_98 ;
else
* V_27 = 0 ;
return 0 ;
}
static void F_28 ( struct V_99 * V_100 )
{
struct V_6 * V_7 = F_29 ( V_100 , struct V_6 , V_35 . V_100 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_15 * V_16 = & V_7 -> V_13 . V_17 ;
int V_8 , V_101 ;
T_3 V_48 , V_47 [ 2 ] ;
T_6 V_102 ;
F_14 ( & V_2 -> V_7 , L_8 ) ;
if ( V_7 -> V_37 & V_86 ) {
struct { signed int V_103 : 14 ; } V_39 ;
V_8 = F_8 ( V_2 , 0x359 , V_47 , 2 ) ;
if ( V_8 )
goto V_26;
V_102 = V_47 [ 0 ] << 8 | V_47 [ 1 ] << 0 ;
V_102 &= 0x3fff ;
V_101 = V_39 . V_103 = V_102 ;
V_102 = F_30 ( - 4 * V_101 + 32767 , 0x0000 , 0xffff ) ;
F_14 ( & V_2 -> V_7 , L_9 , V_101 ) ;
V_16 -> V_27 . V_29 [ 0 ] . V_30 = V_97 ;
V_16 -> V_27 . V_29 [ 0 ] . V_98 = V_102 ;
} else {
V_16 -> V_27 . V_29 [ 0 ] . V_30 = V_31 ;
}
if ( V_7 -> V_37 & V_88 ) {
unsigned V_73 , V_104 ;
#define F_31 3
#define F_32 4
static const T_4 V_105 [ F_31 ] [ F_32 ] = {
{ 70705899 , 70705899 , 70705899 , 70705899 } ,
{ 82433173 , 82433173 , 87483115 , 94445660 } ,
{ 92888734 , 92888734 , 95487525 , 99770748 } ,
} ;
V_8 = F_8 ( V_2 , 0x33c , & V_48 , 1 ) ;
if ( V_8 )
goto V_26;
V_104 = ( V_48 >> 2 ) & 0x03 ;
if ( V_104 > F_31 - 1 )
goto V_106;
V_73 = ( V_48 >> 4 ) & 0x07 ;
if ( V_73 > F_32 - 1 )
goto V_106;
V_8 = F_8 ( V_2 , 0x40c , V_47 , 2 ) ;
if ( V_8 )
goto V_26;
V_102 = V_47 [ 0 ] << 8 | V_47 [ 1 ] << 0 ;
if ( V_102 )
V_101 = ( V_105 [ V_104 ] [ V_73 ] -
F_33 ( V_102 ) ) / ( ( 1 << 24 ) / 10000 ) ;
else
V_101 = 0 ;
F_14 ( & V_2 -> V_7 , L_10 , V_102 ) ;
V_16 -> V_32 . V_29 [ 0 ] . V_30 = V_92 ;
V_16 -> V_32 . V_29 [ 0 ] . V_93 = V_101 ;
} else {
V_16 -> V_32 . V_29 [ 0 ] . V_30 = V_31 ;
}
if ( V_7 -> V_37 & V_90 ) {
V_8 = F_8 ( V_2 , 0x34e , V_47 , 2 ) ;
if ( V_8 )
goto V_26;
V_102 = V_47 [ 0 ] << 8 | V_47 [ 1 ] << 0 ;
V_7 -> V_33 += V_102 ;
V_7 -> V_34 += 1000000 ;
F_14 ( & V_2 -> V_7 , L_11 , V_102 ) ;
V_16 -> V_33 . V_29 [ 0 ] . V_30 = V_107 ;
V_16 -> V_33 . V_29 [ 0 ] . V_98 = V_7 -> V_33 ;
V_16 -> V_34 . V_29 [ 0 ] . V_30 = V_107 ;
V_16 -> V_34 . V_29 [ 0 ] . V_98 = V_7 -> V_34 ;
} else {
V_16 -> V_33 . V_29 [ 0 ] . V_30 = V_31 ;
V_16 -> V_34 . V_29 [ 0 ] . V_30 = V_31 ;
}
V_106:
F_12 ( & V_7 -> V_35 , F_13 ( 2000 ) ) ;
return;
V_26:
F_14 ( & V_2 -> V_7 , L_3 , V_8 ) ;
}
static int F_34 ( struct V_12 * V_13 , int V_108 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
int V_8 ;
T_3 V_48 ;
F_14 ( & V_2 -> V_7 , L_12 , V_108 ) ;
if ( V_108 )
V_48 = 0x80 ;
else
V_48 = 0x00 ;
V_8 = F_6 ( V_2 , 0x061 , 0x80 , V_48 ) ;
if ( V_8 )
goto V_26;
return 0 ;
V_26:
F_14 ( & V_2 -> V_7 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_35 ( struct V_12 * V_13 , T_3 V_109 , T_6 V_110 , int V_108 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
T_3 V_47 [ 4 ] ;
F_14 ( & V_2 -> V_7 , L_13 ,
V_109 , V_110 , V_108 ) ;
if ( V_110 > 0x1fff || V_109 > 32 )
return 0 ;
if ( V_108 )
F_36 ( V_109 , & V_7 -> V_111 ) ;
else
F_37 ( V_109 , & V_7 -> V_111 ) ;
V_47 [ 0 ] = ( V_7 -> V_111 >> 0 ) & 0xff ;
V_47 [ 1 ] = ( V_7 -> V_111 >> 8 ) & 0xff ;
V_47 [ 2 ] = ( V_7 -> V_111 >> 16 ) & 0xff ;
V_47 [ 3 ] = ( V_7 -> V_111 >> 24 ) & 0xff ;
V_8 = F_1 ( V_2 , 0x062 , V_47 , 4 ) ;
if ( V_8 )
goto V_26;
V_47 [ 0 ] = ( V_110 >> 8 ) & 0xff ;
V_47 [ 1 ] = ( V_110 >> 0 ) & 0xff ;
V_8 = F_1 ( V_2 , 0x066 + 2 * V_109 , V_47 , 2 ) ;
if ( V_8 )
goto V_26;
return 0 ;
V_26:
F_14 ( & V_2 -> V_7 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_38 ( struct V_112 * V_113 , void * V_114 , T_4 V_115 )
{
struct V_1 * V_2 = V_114 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
F_14 ( & V_2 -> V_7 , L_8 ) ;
V_8 = F_7 ( V_7 -> V_10 , 0x101 , 0x08 , 0x08 ) ;
if ( V_8 )
goto V_26;
return 0 ;
V_26:
F_14 ( & V_2 -> V_7 , L_3 , V_8 ) ;
return V_8 ;
}
static struct V_12 * F_39 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_14 ( & V_2 -> V_7 , L_8 ) ;
return & V_7 -> V_13 ;
}
static struct V_112 * F_40 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_14 ( & V_2 -> V_7 , L_8 ) ;
return V_7 -> V_9 ;
}
static int F_41 ( void * V_116 , const void * V_117 ,
T_1 V_118 , void * V_119 , T_1 V_120 )
{
struct V_1 * V_2 = V_116 ;
int V_8 ;
struct V_121 V_122 [ 2 ] = {
{
. V_123 = V_2 -> V_123 ,
. V_124 = 0 ,
. V_28 = V_118 ,
. V_47 = ( T_3 * ) V_117 ,
} , {
. V_123 = V_2 -> V_123 ,
. V_124 = V_125 ,
. V_28 = V_120 ,
. V_47 = V_119 ,
}
} ;
V_8 = F_42 ( V_2 -> V_9 , V_122 , 2 ) ;
if ( V_8 != 2 ) {
F_43 ( & V_2 -> V_7 , L_14 , V_8 ) ;
if ( V_8 >= 0 )
V_8 = - V_126 ;
return V_8 ;
}
return 0 ;
}
static int F_44 ( void * V_116 , const void * V_127 , T_1 V_128 )
{
struct V_1 * V_2 = V_116 ;
int V_8 ;
struct V_121 V_122 [ 1 ] = {
{
. V_123 = V_2 -> V_123 ,
. V_124 = 0 ,
. V_28 = V_128 ,
. V_47 = ( T_3 * ) V_127 ,
}
} ;
V_8 = F_42 ( V_2 -> V_9 , V_122 , 1 ) ;
if ( V_8 != 1 ) {
F_43 ( & V_2 -> V_7 , L_15 , V_8 ) ;
if ( V_8 >= 0 )
V_8 = - V_126 ;
return V_8 ;
}
return 0 ;
}
static int F_45 ( void * V_116 , const void * V_3 ,
T_1 V_129 , const void * V_4 ,
T_1 V_130 )
{
struct V_1 * V_2 = V_116 ;
int V_8 ;
T_3 V_47 [ 256 ] ;
struct V_121 V_122 [ 1 ] = {
{
. V_123 = V_2 -> V_123 ,
. V_124 = 0 ,
. V_28 = 1 + V_130 ,
. V_47 = V_47 ,
}
} ;
V_47 [ 0 ] = * ( T_3 const * ) V_3 ;
memcpy ( & V_47 [ 1 ] , V_4 , V_130 ) ;
V_8 = F_42 ( V_2 -> V_9 , V_122 , 1 ) ;
if ( V_8 != 1 ) {
F_43 ( & V_2 -> V_7 , L_15 , V_8 ) ;
if ( V_8 >= 0 )
V_8 = - V_126 ;
return V_8 ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
const struct V_131 * V_132 )
{
struct V_133 * V_21 = V_2 -> V_7 . V_134 ;
struct V_6 * V_7 ;
int V_8 ;
T_3 V_48 ;
static const struct V_135 V_135 = {
. V_136 = F_41 ,
. V_137 = F_44 ,
. V_138 = F_45 ,
. V_139 = V_140 ,
} ;
static const struct V_141 V_141 [] = {
{
. V_142 = 0x00 ,
. V_143 = 0xff ,
. V_144 = 0 ,
. V_145 = 0 ,
. V_146 = 0x100 ,
. V_147 = 0 * 0x100 ,
. V_148 = 5 * 0x100 ,
} ,
} ;
static const struct V_149 V_149 = {
. V_150 = 8 ,
. V_151 = 8 ,
. V_152 = 5 * 0x100 ,
. V_153 = V_141 ,
. V_154 = F_11 ( V_141 ) ,
} ;
F_14 ( & V_2 -> V_7 , L_8 ) ;
if ( V_21 == NULL ) {
V_8 = - V_58 ;
goto V_26;
}
V_7 = F_47 ( sizeof( * V_7 ) , V_155 ) ;
if ( V_7 == NULL ) {
V_8 = - V_156 ;
goto V_26;
}
F_48 ( V_2 , V_7 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_21 = V_2 -> V_7 . V_134 ;
V_7 -> V_36 = true ;
F_49 ( & V_7 -> V_35 , F_28 ) ;
V_7 -> V_10 = F_50 ( & V_2 -> V_7 , & V_135 , V_2 ,
& V_149 ) ;
if ( F_51 ( V_7 -> V_10 ) ) {
V_8 = F_52 ( V_7 -> V_10 ) ;
goto V_157;
}
V_8 = F_8 ( V_2 , 0x000 , & V_48 , 1 ) ;
if ( V_8 )
goto V_158;
V_7 -> V_9 = F_53 ( V_2 -> V_9 , & V_2 -> V_7 ,
V_2 , 0 , 0 , 0 , F_38 , NULL ) ;
if ( V_7 -> V_9 == NULL ) {
V_8 = - V_159 ;
goto V_158;
}
memcpy ( & V_7 -> V_13 . V_42 , & V_160 , sizeof( V_7 -> V_13 . V_42 ) ) ;
V_7 -> V_13 . V_14 = V_2 ;
V_21 -> V_161 = F_39 ;
V_21 -> V_162 = F_40 ;
V_21 -> V_163 = F_35 ;
V_21 -> V_164 = F_34 ;
F_54 ( & V_2 -> V_7 , L_16 ) ;
return 0 ;
V_158:
F_55 ( V_7 -> V_10 ) ;
V_157:
F_56 ( V_7 ) ;
V_26:
F_14 ( & V_2 -> V_7 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_14 ( & V_2 -> V_7 , L_8 ) ;
F_58 ( V_7 -> V_9 ) ;
F_55 ( V_7 -> V_10 ) ;
F_56 ( V_7 ) ;
return 0 ;
}
