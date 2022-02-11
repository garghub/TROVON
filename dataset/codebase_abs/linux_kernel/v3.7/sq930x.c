static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 , int V_3 )
{
int V_4 ;
if ( V_1 -> V_5 < 0 )
return;
V_4 = F_2 ( V_1 -> V_6 ,
F_3 ( V_1 -> V_6 , 0 ) ,
0x0c ,
V_7 | V_8 | V_9 ,
V_2 , 0 , V_1 -> V_10 , V_3 ,
500 ) ;
if ( V_4 < 0 ) {
F_4 ( L_1 , V_2 , V_4 ) ;
V_1 -> V_5 = V_4 ;
}
}
static void F_5 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_11 )
{
int V_4 ;
if ( V_1 -> V_5 < 0 )
return;
F_6 ( V_12 , L_2 , V_2 , V_11 ) ;
V_4 = F_2 ( V_1 -> V_6 ,
F_7 ( V_1 -> V_6 , 0 ) ,
0x0c ,
V_13 | V_8 | V_9 ,
V_2 , V_11 , NULL , 0 ,
500 ) ;
F_8 ( 30 ) ;
if ( V_4 < 0 ) {
F_4 ( L_3 , V_2 , V_11 , V_4 ) ;
V_1 -> V_5 = V_4 ;
}
}
static void F_9 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_11 ,
const T_2 * V_14 , int V_3 )
{
int V_4 ;
if ( V_1 -> V_5 < 0 )
return;
F_6 ( V_12 , L_4 ,
V_2 , V_11 , * V_14 , V_14 [ V_3 - 1 ] ) ;
memcpy ( V_1 -> V_10 , V_14 , V_3 ) ;
V_4 = F_2 ( V_1 -> V_6 ,
F_7 ( V_1 -> V_6 , 0 ) ,
0x0c ,
V_13 | V_8 | V_9 ,
V_2 , V_11 , V_1 -> V_10 , V_3 ,
1000 ) ;
F_8 ( 30 ) ;
if ( V_4 < 0 ) {
F_4 ( L_5 , V_2 , V_11 , V_4 ) ;
V_1 -> V_5 = V_4 ;
}
}
static void F_10 ( struct V_15 * V_15 ,
const struct V_16 * V_17 ,
int V_18 )
{
struct V_1 * V_1 = & V_15 -> V_1 ;
const struct V_19 * V_20 ;
T_1 V_21 , V_22 ;
T_2 * V_23 ;
int V_4 ;
if ( V_1 -> V_5 < 0 )
return;
V_20 = & V_24 [ V_15 -> V_20 ] ;
V_21 = ( V_20 -> V_25 << 8 ) | V_26 ;
V_22 = ( V_17 -> V_21 & 0xff00 ) | V_17 -> V_27 ;
V_23 = V_1 -> V_10 ;
* V_23 ++ = V_20 -> V_28 ;
* V_23 ++ = V_17 -> V_21 ;
while ( -- V_18 > 0 ) {
V_17 ++ ;
* V_23 ++ = V_17 -> V_27 ;
* V_23 ++ = V_17 -> V_21 >> 8 ;
* V_23 ++ = V_20 -> V_28 ;
* V_23 ++ = V_17 -> V_21 ;
}
F_6 ( V_12 , L_6 ,
V_21 , V_22 , V_1 -> V_10 [ 0 ] , V_23 [ - 1 ] ) ;
V_4 = F_2 ( V_1 -> V_6 ,
F_7 ( V_1 -> V_6 , 0 ) ,
0x0c ,
V_13 | V_8 | V_9 ,
V_21 , V_22 ,
V_1 -> V_10 , V_23 - V_1 -> V_10 ,
500 ) ;
if ( V_4 < 0 ) {
F_4 ( L_7 , V_4 ) ;
V_1 -> V_5 = V_4 ;
}
}
static void F_11 ( struct V_1 * V_1 ,
const struct V_29 * V_17 ,
int V_18 ,
int V_30 )
{
T_2 * V_23 ;
T_1 V_21 , V_22 ;
int V_3 , V_4 ;
if ( V_1 -> V_5 < 0 )
return;
#ifdef F_12
if ( ( V_30 - 1 ) * 3 > V_31 ) {
F_4 ( L_8 ) ;
V_1 -> V_5 = - V_32 ;
return;
}
#endif
for (; ; ) {
V_3 = V_18 ;
if ( V_3 > V_30 )
V_3 = V_30 ;
V_18 -= V_3 ;
V_21 = ( V_17 -> V_33 << 8 ) | V_34 ;
V_22 = ( V_17 -> V_35 << 8 ) | ( V_17 -> V_33 >> 8 ) ;
V_23 = V_1 -> V_10 ;
while ( -- V_3 > 0 ) {
V_17 ++ ;
* V_23 ++ = V_17 -> V_33 ;
* V_23 ++ = V_17 -> V_33 >> 8 ;
* V_23 ++ = V_17 -> V_35 ;
}
if ( V_23 != V_1 -> V_10 )
F_6 ( V_12 , L_9 ,
V_21 , V_22 ,
V_1 -> V_10 [ 0 ] , V_23 [ - 1 ] ) ;
else
F_6 ( V_12 , L_10 ,
V_21 , V_22 ) ;
V_4 = F_2 ( V_1 -> V_6 ,
F_7 ( V_1 -> V_6 , 0 ) ,
0x0c ,
V_13 | V_8 | V_9 ,
V_21 , V_22 ,
V_1 -> V_10 , V_23 - V_1 -> V_10 ,
500 ) ;
if ( V_4 < 0 ) {
F_4 ( L_11 , V_4 ) ;
V_1 -> V_5 = V_4 ;
return;
}
F_8 ( 30 ) ;
if ( V_18 <= 0 )
break;
V_17 ++ ;
}
}
static void F_13 ( struct V_15 * V_15 , T_1 V_21 , T_1 V_36 )
{
struct V_1 * V_1 = & V_15 -> V_1 ;
if ( V_36 & 0x00ff ) {
V_15 -> V_37 [ 0 ] &= ~ V_36 ;
V_15 -> V_37 [ 0 ] |= V_21 ;
F_5 ( V_1 , 0x0100 | V_38 ,
~ V_15 -> V_37 [ 0 ] << 8 ) ;
}
V_36 >>= 8 ;
V_21 >>= 8 ;
if ( V_36 ) {
V_15 -> V_37 [ 1 ] &= ~ V_36 ;
V_15 -> V_37 [ 1 ] |= V_21 ;
F_5 ( V_1 , 0x0300 | V_38 ,
~ V_15 -> V_37 [ 1 ] << 8 ) ;
}
}
static void F_14 ( struct V_15 * V_15 ,
const T_2 * V_37 )
{
F_13 ( V_15 , * V_37 ++ , 0x000f ) ;
F_13 ( V_15 , * V_37 ++ , 0x000f ) ;
F_13 ( V_15 , * V_37 ++ , 0x000f ) ;
F_13 ( V_15 , * V_37 ++ , 0x000f ) ;
F_13 ( V_15 , * V_37 , 0x000f ) ;
}
static void F_15 ( struct V_15 * V_15 )
{
static const struct V_29 V_39 = {
0xf031 , 0
} ;
F_11 ( & V_15 -> V_1 , & V_39 , 1 , 1 ) ;
F_13 ( V_15 , V_40 , 0xff00 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
int V_41 ;
const struct V_19 * V_20 ;
static const T_2 V_42 [] = {
V_43 ,
V_44 ,
V_45 ,
V_46 ,
} ;
for ( V_41 = 0 ; V_41 < F_17 ( V_42 ) ; V_41 ++ ) {
V_20 = & V_24 [ V_42 [ V_41 ] ] ;
F_11 ( & V_15 -> V_1 , V_20 -> V_17 , V_20 -> V_47 , 8 ) ;
F_14 ( V_15 , V_20 -> V_37 ) ;
F_8 ( 100 ) ;
F_1 ( V_1 , ( V_20 -> V_25 << 8 ) | 0x001c , 1 ) ;
F_8 ( 100 ) ;
if ( V_1 -> V_10 [ 0 ] != 0 )
break;
}
if ( V_41 >= F_17 ( V_42 ) ) {
F_4 ( L_12 ) ;
V_1 -> V_5 = - V_48 ;
return;
}
V_15 -> V_20 = V_42 [ V_41 ] ;
switch ( V_15 -> V_20 ) {
case V_45 :
case V_43 :
F_4 ( L_13 ,
V_24 [ V_15 -> V_20 ] . V_49 ) ;
V_1 -> V_5 = - V_48 ;
break;
}
}
static void F_18 ( struct V_1 * V_1 )
{
int V_41 , V_50 ;
static const T_2 V_51 [] = {
0x00 , 0x3b , 0xf6 , 0x01 , 0x03 , 0x02 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00
} ;
static const T_2 V_52 [] [ 7 ] = {
{ 0x10 , 0x01 , 0x66 , 0x08 , 0x00 , 0x00 , 0x00 } ,
{ 0x01 , 0x00 , 0x1a , 0x04 , 0x00 , 0x00 , 0x00 } ,
{ 0x20 , 0x00 , 0x10 , 0x04 , 0x00 , 0x00 , 0x00 } ,
{ 0x02 , 0x01 , 0xae , 0x01 , 0x00 , 0x00 , 0x00 } ,
} ;
F_9 ( V_1 , 0x001b , 0x0000 , V_51 , sizeof V_51 ) ;
for ( V_41 = 0 ; V_41 < F_17 ( V_52 ) ; V_41 ++ ) {
F_9 ( V_1 , 0x001b , 0x0000 , V_52 [ V_41 ] ,
F_17 ( V_52 [ 0 ] ) ) ;
F_8 ( 400 ) ;
V_50 = 20 ;
for (; ; ) {
F_1 ( V_1 , 0x031b , 1 ) ;
if ( V_1 -> V_10 [ 0 ] == 0
|| V_1 -> V_5 != 0 )
break;
if ( -- V_50 < 0 ) {
F_6 ( V_53 , L_14 ) ;
V_1 -> V_5 = - V_54 ;
return;
}
F_8 ( 50 ) ;
}
}
}
static void F_19 ( struct V_15 * V_15 , int V_55 )
{
switch ( V_15 -> V_20 ) {
case V_56 :
if ( V_55 )
F_11 ( & V_15 -> V_1 ,
V_57 ,
8 , 8 ) ;
F_14 ( V_15 , V_24 [ V_15 -> V_20 ] . V_37 ) ;
break;
case V_58 :
if ( V_15 -> type != V_59 )
F_13 ( V_15 , V_60 , 0x00ff ) ;
else
F_13 ( V_15 , 0 , 0x00ff ) ;
F_8 ( 50 ) ;
if ( V_55 )
F_11 ( & V_15 -> V_1 ,
V_61 ,
8 , 8 ) ;
F_14 ( V_15 , V_24 [ V_15 -> V_20 ] . V_37 ) ;
break;
case V_44 :
if ( V_55 )
F_11 ( & V_15 -> V_1 ,
V_62 ,
F_17 ( V_62 ) ,
8 ) ;
F_14 ( V_15 , V_24 [ V_15 -> V_20 ] . V_37 ) ;
F_13 ( V_15 , V_63 , V_63 ) ;
break;
default:
if ( V_55 )
F_18 ( & V_15 -> V_1 ) ;
else
F_14 ( V_15 , V_24 [ V_15 -> V_20 ] . V_37 ) ;
break;
}
}
static void F_20 ( struct V_15 * V_15 , T_1 V_64 )
{
struct V_29 V_65 [ 2 ] = {
{ 0xf810 , V_64 >> 8 } ,
{ 0xf811 , V_64 }
} ;
F_11 ( & V_15 -> V_1 , V_65 , F_17 ( V_65 ) , 2 ) ;
}
static void F_21 ( struct V_1 * V_1 , T_3 V_66 , T_3 V_67 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
int V_41 , V_68 , V_69 , V_70 , V_71 ;
const struct V_19 * V_20 ;
T_1 V_17 ;
T_2 V_23 [ 15 ] ;
V_68 = V_66 ;
V_41 = 0 ;
V_17 = V_72 ;
switch ( V_15 -> V_20 ) {
case V_56 :
case V_58 :
V_71 = V_15 -> V_20 == V_56 ? 0x210 : 0x26f ;
if ( V_68 >= V_71 ) {
V_69 = 0 ;
V_70 = V_68 ;
} else {
V_69 = V_71 - V_68 ;
V_70 = V_71 ;
}
V_23 [ V_41 ++ ] = V_69 >> 8 ;
V_23 [ V_41 ++ ] = V_69 ;
V_23 [ V_41 ++ ] = V_70 >> 8 ;
V_23 [ V_41 ++ ] = V_70 ;
V_23 [ V_41 ++ ] = V_67 ;
break;
default:
V_17 |= 0x0100 ;
V_20 = & V_24 [ V_15 -> V_20 ] ;
V_23 [ V_41 ++ ] = V_20 -> V_25 ;
V_23 [ V_41 ++ ] = 0x08 ;
V_23 [ V_41 ++ ] = 0x09 ;
V_23 [ V_41 ++ ] = V_68 >> 8 ;
V_23 [ V_41 ++ ] = V_20 -> V_28 ;
V_23 [ V_41 ++ ] = V_68 ;
V_23 [ V_41 ++ ] = 0x35 ;
V_23 [ V_41 ++ ] = 0x00 ;
V_23 [ V_41 ++ ] = V_20 -> V_28 ;
V_23 [ V_41 ++ ] = 0x80 + V_67 / 2 ;
V_23 [ V_41 ++ ] = 0x00 ;
V_23 [ V_41 ++ ] = 0x00 ;
V_23 [ V_41 ++ ] = 0x00 ;
V_23 [ V_41 ++ ] = 0x00 ;
V_23 [ V_41 ++ ] = 0x83 ;
break;
}
F_9 ( V_1 , V_17 , 0 , V_23 , V_41 ) ;
}
static int F_22 ( struct V_1 * V_1 ,
const struct V_73 * V_74 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
struct V_75 * V_75 = & V_1 -> V_75 ;
V_15 -> V_20 = V_74 -> V_76 >> 8 ;
V_15 -> type = V_74 -> V_76 ;
V_75 -> V_77 = V_78 ;
V_75 -> V_79 = F_17 ( V_78 ) ;
V_75 -> V_80 = 1 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
V_15 -> V_37 [ 0 ] = V_15 -> V_37 [ 1 ] = 0xff ;
F_1 ( V_1 , V_81 , 8 ) ;
if ( V_1 -> V_5 < 0 )
return V_1 -> V_5 ;
F_6 ( V_53 , L_15 , 8 , V_1 -> V_10 ) ;
F_15 ( V_15 ) ;
if ( V_15 -> V_20 == V_44 ) {
if ( V_1 -> V_10 [ 5 ] == 0xf6 )
V_15 -> V_20 = V_56 ;
else
F_16 ( V_1 ) ;
}
if ( V_1 -> V_5 >= 0 ) {
F_6 ( V_53 , L_16 , V_24 [ V_15 -> V_20 ] . V_49 ) ;
F_19 ( V_15 , 1 ) ;
}
return V_1 -> V_5 ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
const struct V_82 * V_83 ;
int V_84 ;
V_84 = V_1 -> V_75 . V_77 [ V_1 -> V_85 ] . V_86 ;
V_83 = & V_87 [ V_15 -> V_20 ] [ V_84 ] ;
F_9 ( V_1 , 0x0900 | V_88 ,
0x0a00 | V_83 -> V_89 ,
V_83 -> V_90 , 32 ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
F_5 ( V_1 , V_91 , 0 ) ;
}
static int F_26 ( struct V_1 * V_1 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
V_1 -> V_75 . V_92 = 1 ;
V_15 -> V_93 = 0 ;
V_1 -> V_75 . V_94 = V_1 -> V_95 * V_1 -> V_96 + 8 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_1 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
int V_84 ;
F_15 ( V_15 ) ;
F_19 ( V_15 , 0 ) ;
F_8 ( 100 ) ;
switch ( V_15 -> V_20 ) {
case V_56 :
F_11 ( V_1 , V_57 ,
F_17 ( V_57 ) ,
8 ) ;
F_11 ( V_1 , V_97 ,
F_17 ( V_97 ) ,
5 ) ;
F_11 ( V_1 , V_98 ,
F_17 ( V_98 ) ,
6 ) ;
F_8 ( 50 ) ;
F_24 ( V_1 ) ;
F_13 ( V_15 , V_63 | V_99 , 0x00ff ) ;
F_8 ( 70 ) ;
F_5 ( V_1 , V_91 , 0x0000 ) ;
F_13 ( V_15 , 0x7f , 0x00ff ) ;
F_24 ( V_1 ) ;
F_13 ( V_15 , V_63 | V_99 , 0x00ff ) ;
goto V_100;
case V_58 :
F_11 ( V_1 , V_61 ,
F_17 ( V_61 ) ,
8 ) ;
if ( V_15 -> type != V_59 )
F_11 ( V_1 , V_101 ,
F_17 ( V_101 ) ,
5 ) ;
else
F_11 ( V_1 , V_102 ,
F_17 ( V_102 ) ,
5 ) ;
F_11 ( V_1 , V_103 ,
F_17 ( V_103 ) ,
6 ) ;
V_84 = V_1 -> V_75 . V_77 [ V_1 -> V_85 ] . V_86 ;
F_20 ( V_15 , V_84 == 1 ? 0x0564 : 0x0310 ) ;
F_8 ( 10 ) ;
break;
case V_44 :
F_11 ( V_1 , V_62 ,
F_17 ( V_62 ) ,
8 ) ;
F_10 ( V_15 , V_104 ,
F_17 ( V_104 ) ) ;
F_10 ( V_15 , V_105 ,
F_17 ( V_105 ) ) ;
F_10 ( V_15 , V_106 ,
F_17 ( V_106 ) ) ;
F_11 ( V_1 , V_107 ,
F_17 ( V_107 ) ,
5 ) ;
F_10 ( V_15 , V_108 ,
F_17 ( V_108 ) ) ;
F_10 ( V_15 , V_109 ,
F_17 ( V_109 ) ) ;
F_24 ( V_1 ) ;
F_8 ( 60 ) ;
F_25 ( V_1 ) ;
F_10 ( V_15 ,
V_110 , F_17 ( V_110 ) ) ;
break;
default:
F_11 ( V_1 , V_62 ,
F_17 ( V_62 ) ,
8 ) ;
F_10 ( V_15 , V_111 ,
F_17 ( V_111 ) ) ;
F_10 ( V_15 , V_112 ,
F_17 ( V_112 ) ) ;
F_10 ( V_15 , V_113 ,
F_17 ( V_113 ) ) ;
F_11 ( V_1 , V_114 ,
F_17 ( V_114 ) ,
5 ) ;
F_10 ( V_15 , V_115 ,
F_17 ( V_115 ) ) ;
F_10 ( V_15 , V_116 ,
F_17 ( V_116 ) ) ;
break;
}
F_24 ( V_1 ) ;
V_100:
F_8 ( 1000 ) ;
if ( V_15 -> V_20 == V_46 )
F_13 ( V_15 , V_117 , V_117 ) ;
V_15 -> V_93 = 1 ;
return V_1 -> V_5 ;
}
static void F_28 ( struct V_1 * V_1 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
if ( V_15 -> V_20 == V_46 )
F_13 ( V_15 , 0 , V_117 ) ;
F_25 ( V_1 ) ;
}
static void F_29 ( struct V_1 * V_1 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
int V_4 ;
if ( ! V_15 -> V_93 || V_1 -> V_75 . V_92 != 0 )
return;
V_15 -> V_93 = 0 ;
F_21 ( V_1 , F_30 ( V_15 -> V_118 ) ,
F_30 ( V_15 -> V_67 ) ) ;
V_1 -> V_75 . V_92 = 1 ;
V_4 = F_31 ( V_1 -> V_119 [ 0 ] , V_120 ) ;
if ( V_4 < 0 )
F_4 ( L_17 , V_4 ) ;
F_8 ( 100 ) ;
}
static void F_32 ( struct V_1 * V_1 ,
T_2 * V_14 ,
int V_3 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
if ( V_15 -> V_93 )
V_1 -> V_75 . V_92 = 0 ;
F_33 ( V_1 , V_121 , NULL , 0 ) ;
F_33 ( V_1 , V_122 , V_14 , V_3 - 8 ) ;
F_33 ( V_1 , V_123 , NULL , 0 ) ;
}
static int F_34 ( struct V_124 * V_125 )
{
struct V_1 * V_1 =
F_35 ( V_125 -> V_126 , struct V_1 , V_127 ) ;
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
V_1 -> V_5 = 0 ;
if ( ! V_1 -> V_128 )
return 0 ;
switch ( V_125 -> V_74 ) {
case V_129 :
F_21 ( V_1 , V_125 -> V_21 , V_15 -> V_67 -> V_21 ) ;
break;
}
return V_1 -> V_5 ;
}
static int F_36 ( struct V_1 * V_1 )
{
struct V_130 * V_131 = & V_1 -> V_127 ;
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
V_1 -> V_132 . V_127 = V_131 ;
F_37 ( V_131 , 2 ) ;
V_15 -> V_118 = F_38 ( V_131 , & V_133 ,
V_129 , 1 , 0xfff , 1 , 0x356 ) ;
V_15 -> V_67 = F_38 ( V_131 , & V_133 ,
V_134 , 1 , 255 , 1 , 0x8d ) ;
if ( V_131 -> error ) {
F_4 ( L_18 ) ;
return V_131 -> error ;
}
F_39 ( 2 , & V_15 -> V_118 ) ;
return 0 ;
}
static int F_40 ( struct V_135 * V_136 ,
const struct V_73 * V_74 )
{
return F_41 ( V_136 , V_74 , & V_137 , sizeof( struct V_15 ) ,
V_138 ) ;
}
