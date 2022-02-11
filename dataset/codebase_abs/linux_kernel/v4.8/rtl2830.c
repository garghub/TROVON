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
V_7 -> V_35 = false ;
return V_8 ;
V_26:
F_12 ( & V_2 -> V_7 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_13 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_35 = true ;
V_7 -> V_36 = 0 ;
return 0 ;
}
static int F_14 ( struct V_12 * V_13 ,
struct V_37 * V_38 )
{
V_38 -> V_39 = 500 ;
V_38 -> V_40 = V_13 -> V_41 . V_42 . V_43 * 2 ;
V_38 -> V_44 = ( V_13 -> V_41 . V_42 . V_43 * 2 ) + 1 ;
return 0 ;
}
static int F_15 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = & V_13 -> V_17 ;
int V_8 , V_18 ;
T_2 V_45 ;
T_3 V_46 [ 3 ] , V_47 ;
T_4 V_48 , V_49 ;
static const T_3 V_50 [ 3 ] [ 34 ] = {
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
static const T_3 V_51 [ 3 ] [ 6 ] = {
{ 0xc3 , 0x0c , 0x44 , 0x33 , 0x33 , 0x30 } ,
{ 0xb8 , 0xe3 , 0x93 , 0x99 , 0x99 , 0x98 } ,
{ 0xae , 0xba , 0xf3 , 0x26 , 0x66 , 0x64 } ,
} ;
F_12 ( & V_2 -> V_7 , L_4 ,
V_16 -> V_52 , V_16 -> V_53 , V_16 -> V_54 ) ;
if ( V_13 -> V_41 . V_55 . V_56 )
V_13 -> V_41 . V_55 . V_56 ( V_13 ) ;
switch ( V_16 -> V_53 ) {
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
F_16 ( & V_2 -> V_7 , L_5 ,
V_16 -> V_53 ) ;
return - V_57 ;
}
V_8 = F_6 ( V_2 , 0x008 , 0x06 , V_18 << 1 ) ;
if ( V_8 )
goto V_26;
if ( V_13 -> V_41 . V_55 . V_58 )
V_8 = V_13 -> V_41 . V_55 . V_58 ( V_13 , & V_49 ) ;
else
V_8 = - V_57 ;
if ( V_8 )
goto V_26;
V_45 = V_49 % V_7 -> V_21 -> V_59 ;
V_45 *= 0x400000 ;
V_45 = F_17 ( V_45 , V_7 -> V_21 -> V_59 ) ;
V_45 = - V_45 ;
V_48 = V_45 & 0x3fffff ;
F_12 ( & V_2 -> V_7 , L_6 ,
V_49 , V_48 ) ;
V_46 [ 0 ] = ( V_48 >> 16 ) & 0x3f ;
V_46 [ 1 ] = ( V_48 >> 8 ) & 0xff ;
V_46 [ 2 ] = ( V_48 >> 0 ) & 0xff ;
V_8 = F_8 ( V_2 , 0x119 , & V_47 , 1 ) ;
if ( V_8 )
goto V_26;
V_46 [ 0 ] |= V_47 & 0xc0 ;
V_8 = F_1 ( V_2 , 0x119 , V_46 , 3 ) ;
if ( V_8 )
goto V_26;
V_8 = F_1 ( V_2 , 0x11c , & V_50 [ V_18 ] [ 0 ] , 17 ) ;
if ( V_8 )
goto V_26;
V_8 = F_1 ( V_2 , 0x12d , & V_50 [ V_18 ] [ 17 ] , 17 ) ;
if ( V_8 )
goto V_26;
V_8 = F_1 ( V_2 , 0x19d , V_51 [ V_18 ] , 6 ) ;
if ( V_8 )
goto V_26;
return V_8 ;
V_26:
F_12 ( & V_2 -> V_7 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_18 ( struct V_12 * V_13 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
T_3 V_46 [ 3 ] ;
if ( V_7 -> V_35 )
return 0 ;
V_8 = F_8 ( V_2 , 0x33c , V_46 , 2 ) ;
if ( V_8 )
goto V_26;
V_8 = F_8 ( V_2 , 0x351 , & V_46 [ 2 ] , 1 ) ;
if ( V_8 )
goto V_26;
F_12 ( & V_2 -> V_7 , L_7 , 3 , V_46 ) ;
switch ( ( V_46 [ 0 ] >> 2 ) & 3 ) {
case 0 :
V_16 -> V_60 = V_61 ;
break;
case 1 :
V_16 -> V_60 = V_62 ;
break;
case 2 :
V_16 -> V_60 = V_63 ;
break;
}
switch ( ( V_46 [ 2 ] >> 2 ) & 1 ) {
case 0 :
V_16 -> V_64 = V_65 ;
break;
case 1 :
V_16 -> V_64 = V_66 ;
}
switch ( ( V_46 [ 2 ] >> 0 ) & 3 ) {
case 0 :
V_16 -> V_67 = V_68 ;
break;
case 1 :
V_16 -> V_67 = V_69 ;
break;
case 2 :
V_16 -> V_67 = V_70 ;
break;
case 3 :
V_16 -> V_67 = V_71 ;
break;
}
switch ( ( V_46 [ 0 ] >> 4 ) & 7 ) {
case 0 :
V_16 -> V_72 = V_73 ;
break;
case 1 :
V_16 -> V_72 = V_74 ;
break;
case 2 :
V_16 -> V_72 = V_75 ;
break;
case 3 :
V_16 -> V_72 = V_76 ;
break;
}
switch ( ( V_46 [ 1 ] >> 3 ) & 7 ) {
case 0 :
V_16 -> V_77 = V_78 ;
break;
case 1 :
V_16 -> V_77 = V_79 ;
break;
case 2 :
V_16 -> V_77 = V_80 ;
break;
case 3 :
V_16 -> V_77 = V_81 ;
break;
case 4 :
V_16 -> V_77 = V_82 ;
break;
}
switch ( ( V_46 [ 1 ] >> 0 ) & 7 ) {
case 0 :
V_16 -> V_83 = V_78 ;
break;
case 1 :
V_16 -> V_83 = V_79 ;
break;
case 2 :
V_16 -> V_83 = V_80 ;
break;
case 3 :
V_16 -> V_83 = V_81 ;
break;
case 4 :
V_16 -> V_83 = V_82 ;
break;
}
return 0 ;
V_26:
F_12 ( & V_2 -> V_7 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_19 ( struct V_12 * V_13 , enum V_36 * V_84 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = & V_7 -> V_13 . V_17 ;
int V_8 , V_85 ;
unsigned int V_86 ;
T_3 V_47 , V_46 [ 2 ] ;
* V_84 = 0 ;
if ( V_7 -> V_35 )
return 0 ;
V_8 = F_8 ( V_2 , 0x351 , & V_47 , 1 ) ;
if ( V_8 )
goto V_26;
V_47 = ( V_47 >> 3 ) & 0x0f ;
if ( V_47 == 11 ) {
* V_84 |= V_87 | V_88 |
V_89 | V_90 | V_91 ;
} else if ( V_47 == 10 ) {
* V_84 |= V_87 | V_88 |
V_89 ;
}
V_7 -> V_36 = * V_84 ;
if ( V_7 -> V_36 & V_87 ) {
V_8 = F_8 ( V_2 , 0x359 , V_46 , 2 ) ;
if ( V_8 )
goto V_26;
V_85 = V_46 [ 0 ] << 8 | V_46 [ 1 ] << 0 ;
V_85 = F_20 ( V_85 , 13 ) ;
V_86 = F_21 ( - 4 * V_85 + 32767 , 0x0000 , 0xffff ) ;
F_12 ( & V_2 -> V_7 , L_8 , V_85 ) ;
V_16 -> V_27 . V_29 [ 0 ] . V_30 = V_92 ;
V_16 -> V_27 . V_29 [ 0 ] . V_93 = V_86 ;
} else {
V_16 -> V_27 . V_29 [ 0 ] . V_30 = V_31 ;
}
if ( V_7 -> V_36 & V_89 ) {
unsigned int V_72 , V_94 ;
#define F_22 3
#define F_23 4
static const T_4 V_95 [ F_22 ] [ F_23 ] = {
{ 70705899 , 70705899 , 70705899 , 70705899 } ,
{ 82433173 , 82433173 , 87483115 , 94445660 } ,
{ 92888734 , 92888734 , 95487525 , 99770748 } ,
} ;
V_8 = F_8 ( V_2 , 0x33c , & V_47 , 1 ) ;
if ( V_8 )
goto V_26;
V_94 = ( V_47 >> 2 ) & 0x03 ;
if ( V_94 > F_22 - 1 )
goto V_26;
V_72 = ( V_47 >> 4 ) & 0x07 ;
if ( V_72 > F_23 - 1 )
goto V_26;
V_8 = F_8 ( V_2 , 0x40c , V_46 , 2 ) ;
if ( V_8 )
goto V_26;
V_86 = V_46 [ 0 ] << 8 | V_46 [ 1 ] << 0 ;
if ( V_86 )
V_85 = ( V_95 [ V_94 ] [ V_72 ] -
F_24 ( V_86 ) ) / ( ( 1 << 24 ) / 10000 ) ;
else
V_85 = 0 ;
F_12 ( & V_2 -> V_7 , L_9 , V_86 ) ;
V_16 -> V_32 . V_29 [ 0 ] . V_30 = V_96 ;
V_16 -> V_32 . V_29 [ 0 ] . V_97 = V_85 ;
} else {
V_16 -> V_32 . V_29 [ 0 ] . V_30 = V_31 ;
}
if ( V_7 -> V_36 & V_91 ) {
V_8 = F_8 ( V_2 , 0x34e , V_46 , 2 ) ;
if ( V_8 )
goto V_26;
V_86 = V_46 [ 0 ] << 8 | V_46 [ 1 ] << 0 ;
V_7 -> V_33 += V_86 ;
V_7 -> V_34 += 1000000 ;
F_12 ( & V_2 -> V_7 , L_10 , V_86 ) ;
V_16 -> V_33 . V_29 [ 0 ] . V_30 = V_98 ;
V_16 -> V_33 . V_29 [ 0 ] . V_93 = V_7 -> V_33 ;
V_16 -> V_34 . V_29 [ 0 ] . V_30 = V_98 ;
V_16 -> V_34 . V_29 [ 0 ] . V_93 = V_7 -> V_34 ;
} else {
V_16 -> V_33 . V_29 [ 0 ] . V_30 = V_31 ;
V_16 -> V_34 . V_29 [ 0 ] . V_30 = V_31 ;
}
return V_8 ;
V_26:
F_12 ( & V_2 -> V_7 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_25 ( struct V_12 * V_13 , T_5 * V_99 )
{
struct V_15 * V_16 = & V_13 -> V_17 ;
if ( V_16 -> V_32 . V_29 [ 0 ] . V_30 == V_96 )
* V_99 = F_26 ( V_16 -> V_32 . V_29 [ 0 ] . V_97 , 100 ) ;
else
* V_99 = 0 ;
return 0 ;
}
static int F_27 ( struct V_12 * V_13 , T_4 * V_100 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
* V_100 = ( V_7 -> V_33 - V_7 -> V_101 ) ;
V_7 -> V_101 = V_7 -> V_33 ;
return 0 ;
}
static int F_28 ( struct V_12 * V_13 , T_4 * V_102 )
{
* V_102 = 0 ;
return 0 ;
}
static int F_29 ( struct V_12 * V_13 , T_5 * V_27 )
{
struct V_15 * V_16 = & V_13 -> V_17 ;
if ( V_16 -> V_27 . V_29 [ 0 ] . V_30 == V_92 )
* V_27 = V_16 -> V_27 . V_29 [ 0 ] . V_93 ;
else
* V_27 = 0 ;
return 0 ;
}
static int F_30 ( struct V_12 * V_13 , int V_103 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
int V_8 ;
T_3 V_47 ;
F_12 ( & V_2 -> V_7 , L_11 , V_103 ) ;
if ( V_103 )
V_47 = 0x80 ;
else
V_47 = 0x00 ;
V_8 = F_6 ( V_2 , 0x061 , 0x80 , V_47 ) ;
if ( V_8 )
goto V_26;
return 0 ;
V_26:
F_12 ( & V_2 -> V_7 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_31 ( struct V_12 * V_13 , T_3 V_104 , T_5 V_105 , int V_103 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
T_3 V_46 [ 4 ] ;
F_12 ( & V_2 -> V_7 , L_12 ,
V_104 , V_105 , V_103 ) ;
if ( V_105 > 0x1fff || V_104 > 32 )
return 0 ;
if ( V_103 )
F_32 ( V_104 , & V_7 -> V_106 ) ;
else
F_33 ( V_104 , & V_7 -> V_106 ) ;
V_46 [ 0 ] = ( V_7 -> V_106 >> 0 ) & 0xff ;
V_46 [ 1 ] = ( V_7 -> V_106 >> 8 ) & 0xff ;
V_46 [ 2 ] = ( V_7 -> V_106 >> 16 ) & 0xff ;
V_46 [ 3 ] = ( V_7 -> V_106 >> 24 ) & 0xff ;
V_8 = F_1 ( V_2 , 0x062 , V_46 , 4 ) ;
if ( V_8 )
goto V_26;
V_46 [ 0 ] = ( V_105 >> 8 ) & 0xff ;
V_46 [ 1 ] = ( V_105 >> 0 ) & 0xff ;
V_8 = F_1 ( V_2 , 0x066 + 2 * V_104 , V_46 , 2 ) ;
if ( V_8 )
goto V_26;
return 0 ;
V_26:
F_12 ( & V_2 -> V_7 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_34 ( struct V_107 * V_108 , T_4 V_109 )
{
struct V_1 * V_2 = F_35 ( V_108 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
F_12 ( & V_2 -> V_7 , L_13 ) ;
V_8 = F_7 ( V_7 -> V_10 , 0x101 , 0x08 , 0x08 ) ;
if ( V_8 )
goto V_26;
return 0 ;
V_26:
F_12 ( & V_2 -> V_7 , L_3 , V_8 ) ;
return V_8 ;
}
static struct V_12 * F_36 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_12 ( & V_2 -> V_7 , L_13 ) ;
return & V_7 -> V_13 ;
}
static struct V_110 * F_37 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_12 ( & V_2 -> V_7 , L_13 ) ;
return V_7 -> V_108 -> V_9 [ 0 ] ;
}
static int F_38 ( void * V_111 , const void * V_112 ,
T_1 V_113 , void * V_114 , T_1 V_115 )
{
struct V_1 * V_2 = V_111 ;
int V_8 ;
struct V_116 V_117 [ 2 ] = {
{
. V_118 = V_2 -> V_118 ,
. V_119 = 0 ,
. V_28 = V_113 ,
. V_46 = ( T_3 * ) V_112 ,
} , {
. V_118 = V_2 -> V_118 ,
. V_119 = V_120 ,
. V_28 = V_115 ,
. V_46 = V_114 ,
}
} ;
V_8 = F_39 ( V_2 -> V_9 , V_117 , 2 ) ;
if ( V_8 != 2 ) {
F_40 ( & V_2 -> V_7 , L_14 , V_8 ) ;
if ( V_8 >= 0 )
V_8 = - V_121 ;
return V_8 ;
}
return 0 ;
}
static int F_41 ( void * V_111 , const void * V_122 , T_1 V_123 )
{
struct V_1 * V_2 = V_111 ;
int V_8 ;
struct V_116 V_117 [ 1 ] = {
{
. V_118 = V_2 -> V_118 ,
. V_119 = 0 ,
. V_28 = V_123 ,
. V_46 = ( T_3 * ) V_122 ,
}
} ;
V_8 = F_39 ( V_2 -> V_9 , V_117 , 1 ) ;
if ( V_8 != 1 ) {
F_40 ( & V_2 -> V_7 , L_15 , V_8 ) ;
if ( V_8 >= 0 )
V_8 = - V_121 ;
return V_8 ;
}
return 0 ;
}
static int F_42 ( void * V_111 , const void * V_3 ,
T_1 V_124 , const void * V_4 ,
T_1 V_125 )
{
struct V_1 * V_2 = V_111 ;
int V_8 ;
T_3 V_46 [ 256 ] ;
struct V_116 V_117 [ 1 ] = {
{
. V_118 = V_2 -> V_118 ,
. V_119 = 0 ,
. V_28 = 1 + V_125 ,
. V_46 = V_46 ,
}
} ;
V_46 [ 0 ] = * ( T_3 const * ) V_3 ;
memcpy ( & V_46 [ 1 ] , V_4 , V_125 ) ;
V_8 = F_39 ( V_2 -> V_9 , V_117 , 1 ) ;
if ( V_8 != 1 ) {
F_40 ( & V_2 -> V_7 , L_15 , V_8 ) ;
if ( V_8 >= 0 )
V_8 = - V_121 ;
return V_8 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
const struct V_126 * V_127 )
{
struct V_128 * V_21 = V_2 -> V_7 . V_129 ;
struct V_6 * V_7 ;
int V_8 ;
T_3 V_47 ;
static const struct V_130 V_130 = {
. V_131 = F_38 ,
. V_132 = F_41 ,
. V_133 = F_42 ,
. V_134 = V_135 ,
} ;
static const struct V_136 V_136 [] = {
{
. V_137 = 0x00 ,
. V_138 = 0xff ,
. V_139 = 0 ,
. V_140 = 0 ,
. V_141 = 0x100 ,
. V_142 = 0 * 0x100 ,
. V_143 = 5 * 0x100 ,
} ,
} ;
static const struct V_144 V_144 = {
. V_145 = 8 ,
. V_146 = 8 ,
. V_147 = 5 * 0x100 ,
. V_148 = V_136 ,
. V_149 = F_11 ( V_136 ) ,
} ;
F_12 ( & V_2 -> V_7 , L_13 ) ;
if ( V_21 == NULL ) {
V_8 = - V_57 ;
goto V_26;
}
V_7 = F_44 ( sizeof( * V_7 ) , V_150 ) ;
if ( V_7 == NULL ) {
V_8 = - V_151 ;
goto V_26;
}
F_45 ( V_2 , V_7 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_21 = V_2 -> V_7 . V_129 ;
V_7 -> V_35 = true ;
V_7 -> V_10 = F_46 ( & V_2 -> V_7 , & V_130 , V_2 ,
& V_144 ) ;
if ( F_47 ( V_7 -> V_10 ) ) {
V_8 = F_48 ( V_7 -> V_10 ) ;
goto V_152;
}
V_8 = F_8 ( V_2 , 0x000 , & V_47 , 1 ) ;
if ( V_8 )
goto V_153;
V_7 -> V_108 = F_49 ( V_2 -> V_9 , & V_2 -> V_7 , 1 , 0 , 0 ,
F_34 , NULL ) ;
if ( ! V_7 -> V_108 ) {
V_8 = - V_151 ;
goto V_153;
}
V_7 -> V_108 -> V_154 = V_2 ;
V_8 = F_50 ( V_7 -> V_108 , 0 , 0 , 0 ) ;
if ( V_8 )
goto V_153;
memcpy ( & V_7 -> V_13 . V_41 , & V_155 , sizeof( V_7 -> V_13 . V_41 ) ) ;
V_7 -> V_13 . V_14 = V_2 ;
V_21 -> V_156 = F_36 ;
V_21 -> V_157 = F_37 ;
V_21 -> V_158 = F_31 ;
V_21 -> V_159 = F_30 ;
F_51 ( & V_2 -> V_7 , L_16 ) ;
return 0 ;
V_153:
F_52 ( V_7 -> V_10 ) ;
V_152:
F_53 ( V_7 ) ;
V_26:
F_12 ( & V_2 -> V_7 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_12 ( & V_2 -> V_7 , L_13 ) ;
F_55 ( V_7 -> V_108 ) ;
F_52 ( V_7 -> V_10 ) ;
F_53 ( V_7 ) ;
return 0 ;
}
