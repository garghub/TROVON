static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
T_1 V_5 )
{
V_2 -> V_6 = V_4 -> V_6 ;
V_2 -> V_7 = V_4 -> V_7 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_8 = V_9 ;
V_2 -> V_10 = V_11 ;
}
static int F_2 ( struct V_12 * V_13 , T_2 V_14 , T_2 V_15 )
{
T_3 V_16 [ 4 ] = { V_14 >> 8 , V_14 & 0xff , V_15 >> 8 , V_15 & 0xff } ;
int V_17 = F_3 ( V_13 , V_16 , sizeof( V_16 ) ) ;
F_4 ( 4 , V_18 , V_13 , L_1 ,
V_19 , V_14 , V_15 ) ;
if ( V_17 == 4 )
return 0 ;
return V_17 < 0 ? V_17 : - V_20 ;
}
static int F_5 ( struct V_12 * V_13 , T_2 V_14 , T_2 * V_15 )
{
int V_17 ;
T_3 V_21 [ 2 ] , V_22 [ 2 ] = { V_14 >> 8 , V_14 & 0xff } ;
struct V_23 V_24 [ 2 ] = {
{
. V_14 = V_13 -> V_14 ,
. V_25 = 0 ,
. V_26 = sizeof( V_22 ) ,
. V_16 = V_22
} , {
. V_14 = V_13 -> V_14 ,
. V_25 = V_27 ,
. V_26 = sizeof( V_21 ) ,
. V_16 = V_21
}
} ;
V_17 = F_6 ( V_13 -> V_28 , V_24 , 2 ) ;
if ( V_17 == 2 ) {
* V_15 = F_7 ( ( V_29 * ) V_21 ) ;
F_8 ( 4 , V_18 , V_13 ,
L_2 ,
V_19 , V_14 , * V_15 ) ;
return 0 ;
}
F_9 ( V_13 , L_3 , V_14 , V_17 ) ;
return V_17 >= 0 ? - V_20 : V_17 ;
}
int F_10 ( struct V_30 * V_31 , T_1 V_14 , T_2 V_15 )
{
struct V_12 * V_13 = V_31 -> V_12 ;
int V_17 ;
if ( ( V_14 ^ V_31 -> V_32 ) & 0xffff0000 ) {
V_17 = F_2 ( V_13 , V_33 , V_14 >> 16 ) ;
if ( V_17 < 0 ) {
V_31 -> V_32 = 0 ;
return V_17 ;
}
}
if ( ( V_14 ^ V_31 -> V_32 ) & 0xffff ) {
V_17 = F_2 ( V_13 , V_34 , V_14 & 0xffff ) ;
if ( V_17 < 0 ) {
V_31 -> V_32 = 0 ;
return V_17 ;
}
}
V_31 -> V_32 = V_14 ;
V_17 = F_2 ( V_13 , V_35 , V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
V_31 -> V_32 += 2 ;
return V_17 ;
}
int F_11 ( struct V_30 * V_31 , T_1 V_14 , T_2 * V_15 )
{
struct V_12 * V_13 = V_31 -> V_12 ;
int V_17 ;
if ( ( V_14 ^ V_31 -> V_36 ) & 0xffff0000 ) {
V_17 = F_2 ( V_13 , V_37 , V_14 >> 16 ) ;
if ( V_17 < 0 ) {
V_31 -> V_36 = 0 ;
return V_17 ;
}
}
if ( ( V_14 ^ V_31 -> V_36 ) & 0xffff ) {
V_17 = F_2 ( V_13 , V_38 , V_14 & 0xffff ) ;
if ( V_17 < 0 ) {
V_31 -> V_36 = 0 ;
return V_17 ;
}
}
V_31 -> V_36 = V_14 ;
V_17 = F_5 ( V_13 , V_35 , V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
V_31 -> V_36 += 2 ;
return V_17 ;
}
static int F_12 ( struct V_30 * V_31 , unsigned int V_39 )
{
unsigned long V_40 = V_41 ;
unsigned long V_42 = V_40 + F_13 ( 2000 ) ;
int V_17 = 0 ;
T_2 V_43 ;
int V_44 = 0 ;
while ( F_14 ( V_42 ) ) {
V_17 = F_11 ( V_31 , V_45 , & V_43 ) ;
if ( V_17 < 0 || V_43 == V_39 )
break;
F_15 ( 500 , 1000 ) ;
++ V_44 ;
}
if ( V_44 > 0 )
F_8 ( 1 , V_18 , & V_31 -> V_46 ,
L_4 ,
F_16 ( V_41 - V_40 ) ) ;
if ( V_17 == 0 && V_43 != V_39 ) {
T_2 V_47 = 0 ;
T_2 V_48 = 0 ;
F_11 ( V_31 , V_49 , & V_47 ) ;
F_11 ( V_31 , V_50 , & V_48 ) ;
F_9 ( & V_31 -> V_46 ,
L_5 ,
V_43 , V_39 , V_47 , V_48 ) ;
return - V_51 ;
}
return V_17 ;
}
int F_17 ( struct V_30 * V_31 , T_2 V_52 , T_2 V_15 )
{
int V_17 ;
V_17 = F_12 ( V_31 , V_53 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_10 ( V_31 , 0x00095000 , V_52 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_10 ( V_31 , 0x00095002 , V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
return F_10 ( V_31 , V_45 , 0x0001 ) ;
}
static int F_18 ( struct V_30 * V_31 , T_2 V_52 ,
T_2 * V_15 )
{
return F_11 ( V_31 , V_54 + V_52 , V_15 ) ;
}
static int F_19 ( struct V_30 * V_31 )
{
unsigned long V_40 = V_41 ;
T_2 V_55 ;
int V_44 = 0 ;
int V_17 ;
const char * V_24 ;
V_17 = F_17 ( V_31 , V_56 ,
V_57 ) ;
if ( V_17 < 0 ) {
F_20 ( & V_31 -> V_46 , L_6 ) ;
return V_17 ;
}
for (; ; ) {
V_17 = F_18 ( V_31 , V_56 ,
& V_55 ) ;
if ( V_17 < 0 ) {
V_24 = L_7 ;
break;
}
if ( V_55 == V_58 ) {
V_24 = L_8 ;
break;
}
if ( ++ V_44 > 100 ) {
V_17 = - V_59 ;
V_24 = L_9 ;
break;
}
F_21 ( 25 ) ;
}
F_20 ( & V_31 -> V_46 , L_10 ,
V_24 , F_16 ( V_41 - V_40 ) ) ;
return V_17 ;
}
static int F_22 ( struct V_60 * V_61 )
{
struct V_30 * V_31 = F_23 ( V_61 ) ;
struct V_12 * V_13 = V_31 -> V_12 ;
const struct V_62 * V_63 ;
int V_17 ;
char V_64 [ 20 ] ;
snprintf ( V_64 , sizeof( V_64 ) , L_11 ,
V_31 -> V_65 ) ;
V_17 = F_24 ( & V_63 , V_64 , & V_13 -> V_66 ) ;
if ( V_17 < 0 ) {
F_9 ( V_61 , L_12 , V_64 ) ;
return - V_67 ;
}
F_20 ( V_61 , L_13 , V_64 , V_63 -> V_68 ) ;
V_17 = F_25 ( V_31 , V_63 -> V_15 , V_63 -> V_68 , 64 ) ;
if ( V_17 >= 0 )
V_31 -> V_69 = 1 ;
else
F_9 ( V_61 , L_14 ) ;
F_26 ( V_63 ) ;
return V_17 ;
}
static int F_27 ( struct V_30 * V_31 )
{
const struct V_3 * V_70 =
V_31 -> V_71 [ V_72 ] ;
const struct V_3 * V_73 =
V_31 -> V_71 [ V_74 ] ;
unsigned int V_75 ;
F_8 ( 1 , V_18 , & V_31 -> V_46 ,
L_15 ,
V_70 -> V_6 , V_70 -> V_7 , V_70 -> V_76 ) ;
V_75 = V_70 -> V_76 | V_77 ;
if ( V_31 -> V_78 == V_79 ) {
F_8 ( 1 , V_18 , & V_31 -> V_46 ,
L_16 ,
V_73 -> V_6 , V_73 -> V_7 , V_73 -> V_76 ) ;
V_75 |= V_73 -> V_76 ;
}
return F_17 ( V_31 , V_80 , V_75 ) ;
}
static int F_28 ( struct V_30 * V_31 )
{
int V_17 ;
if ( V_31 -> V_81 . V_82 -> V_83 )
return 0 ;
if ( F_29 ( V_31 -> V_84 == NULL ) )
return - V_67 ;
V_17 = F_17 ( V_31 , V_85 , V_31 -> V_84 -> V_86 ) ;
if ( ! V_17 )
V_31 -> V_87 = 0 ;
return V_17 ;
}
static int F_30 ( struct V_30 * V_31 , struct V_60 * V_61 ,
int V_88 )
{
T_2 V_89 ;
int V_17 ;
if ( V_88 && V_31 -> V_90 ) {
if ( V_31 -> V_78 == V_79 )
V_89 = V_91 ;
else
V_89 = V_92 ;
V_17 = F_17 ( V_31 , V_93 , V_89 ) ;
if ( ! V_17 )
V_17 = F_27 ( V_31 ) ;
if ( V_17 )
return V_17 ;
V_31 -> V_90 = 0 ;
}
V_17 = F_17 ( V_31 , V_94 , ! ! V_88 ) ;
if ( V_17 )
return V_17 ;
V_31 -> V_95 = ! ! V_88 ;
if ( ! V_88 )
return V_17 ;
if ( V_31 -> V_87 ) {
V_17 = F_28 ( V_31 ) ;
if ( V_17 < 0 )
F_9 ( V_61 , L_17 , V_17 ) ;
}
return F_12 ( V_31 , V_53 ) ;
}
static int F_31 ( struct V_60 * V_61 , int V_88 )
{
struct V_30 * V_31 = F_32 ( V_61 ) ;
int V_17 ;
F_33 ( & V_31 -> V_96 ) ;
V_17 = F_30 ( V_31 , V_61 , V_88 ) ;
F_34 ( & V_31 -> V_96 ) ;
return V_17 ;
}
static int F_35 ( struct V_30 * V_31 , T_1 V_39 ,
unsigned int V_97 , unsigned int V_98 )
{
T_2 V_99 = 0 ;
while ( V_98 -- > 0 ) {
int V_17 = F_11 ( V_31 , 0x30100010 , & V_99 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_99 == V_39 )
return 0 ;
F_15 ( V_97 , V_97 + 25 ) ;
}
return - V_51 ;
}
static int F_36 ( struct V_30 * V_31 )
{
struct V_60 * V_61 = & V_31 -> V_46 ;
int V_100 , V_17 ;
T_2 V_15 [ 2 ] ;
int V_101 ;
V_101 = V_31 -> V_69 ? 0x60 : 0 ;
for ( V_100 = 0 ; V_100 < V_102 / 2 ; V_100 ++ ) {
V_17 = F_11 ( V_31 , V_101 + V_100 * 2 , V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
V_31 -> V_103 [ V_100 * 2 ] = ( char ) ( * V_15 & 0xff ) ;
V_31 -> V_103 [ V_100 * 2 + 1 ] = ( char ) ( * V_15 >> 8 ) ;
}
V_31 -> V_103 [ V_102 ] = '\0' ;
for ( V_100 = 0 ; V_100 < V_104 / 2 ; V_100 ++ ) {
V_17 = F_11 ( V_31 , V_101 + 6 + V_100 * 2 , V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
V_31 -> V_105 [ V_100 * 2 ] = ( char ) ( * V_15 & 0xff ) ;
V_31 -> V_105 [ V_100 * 2 + 1 ] = ( char ) ( * V_15 >> 8 ) ;
}
V_31 -> V_105 [ V_104 ] = '\0' ;
V_17 = F_11 ( V_31 , V_101 + 0x14 , V_15 ) ;
if ( V_17 >= 0 ) {
V_17 = F_11 ( V_31 , V_101 + 0x16 , V_15 + 1 ) ;
if ( V_17 >= 0 )
V_31 -> V_106 = V_15 [ 0 ] + ( V_15 [ 1 ] << 16 ) ;
}
F_20 ( V_61 , L_18 ,
V_31 -> V_105 , V_31 -> V_103 ) ;
return V_17 ;
}
static int F_37 ( struct V_30 * V_31 )
{
struct V_60 * V_61 = & V_31 -> V_46 ;
T_2 V_43 = V_107 ;
int V_17 ;
int V_44 = 0 ;
F_38 ( V_61 , L_19 ) ;
do {
if ( V_43 == V_107 ) {
V_17 = F_17 ( V_31 , V_108 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
}
V_17 = F_11 ( V_31 , 0x00095906 , & V_43 ) ;
if ( V_17 < 0 )
return V_17 ;
switch ( V_43 ) {
case V_109 :
F_38 ( V_61 , L_20 ) ;
return - V_110 ;
case V_111 :
F_38 ( V_61 , L_21 ) ;
return 0 ;
}
++ V_44 ;
F_21 ( 20 ) ;
} while ( V_44 < 500 );
F_38 ( V_61 , L_22 ) ;
return - V_51 ;
}
static int F_39 ( struct V_30 * V_31 , bool V_112 )
{
struct V_60 * V_61 = & V_31 -> V_46 ;
int V_17 ;
V_17 = F_10 ( V_31 , 0x30000004 , 0xffff ) ;
if ( V_17 < 0 )
return V_17 ;
F_15 ( 400 , 500 ) ;
V_17 = F_35 ( V_31 , 0x0c , 100 , 3 ) ;
if ( V_17 < 0 ) {
F_9 ( V_61 , L_23 , V_17 ) ;
return V_17 ;
}
V_17 = F_10 ( V_31 , 0x30100014 , 0x2146 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_10 ( V_31 , 0x30100010 , 0x210c ) ;
if ( V_17 < 0 )
return V_17 ;
F_15 ( 200 , 250 ) ;
V_17 = F_35 ( V_31 , 0x210d , 100 , 300 ) ;
if ( V_17 < 0 )
F_9 ( V_61 , L_24 , V_17 ) ;
if ( V_112 )
F_22 ( V_61 ) ;
V_17 = F_10 ( V_31 , 0x30000004 , 0xfffd ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_10 ( V_31 , 0x301000a4 , 0x0183 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_10 ( V_31 , 0x30000004 , 0xffff ) ;
if ( V_17 < 0 || ! V_112 )
return V_17 ;
V_17 = F_36 ( V_31 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_112 && V_113 ) {
V_17 = F_37 ( V_31 ) ;
V_113 = 0 ;
}
return V_17 ;
}
static int F_40 ( struct V_30 * V_31 )
{
static const T_1 V_114 [] [ 2 ] = {
{ 0x30100018 , 0x0618 } ,
{ 0x3010001c , 0x10c1 } ,
{ 0x30100020 , 0x249e }
} ;
int V_17 ;
int V_100 ;
for ( V_100 = 0 ; V_100 < F_41 ( V_114 ) ; V_100 ++ ) {
V_17 = F_10 ( V_31 , V_114 [ V_100 ] [ 0 ] , V_114 [ V_100 ] [ 1 ] ) ;
if ( V_17 < 0 )
return V_17 ;
}
return 0 ;
}
static void F_42 ( struct V_30 * V_31 )
{
switch ( V_31 -> V_103 [ 0 ] ) {
case 'G' :
case 'O' :
V_31 -> V_65 [ 0 ] = 'G' ;
break;
case 'S' :
case 'Z' :
V_31 -> V_65 [ 0 ] = 'Z' ;
break;
}
switch ( V_31 -> V_103 [ 1 ] ) {
case 'C' ... 'F' :
V_31 -> V_65 [ 1 ] = V_31 -> V_103 [ 1 ] ;
break;
}
}
static int F_43 ( struct V_30 * V_31 )
{
struct V_60 * V_61 = & V_31 -> V_46 ;
int V_17 ;
V_17 = F_10 ( V_31 , 0x30000004 , 0xffff ) ;
if ( V_17 < 0 )
return V_17 ;
F_15 ( 400 , 500 ) ;
V_17 = F_35 ( V_31 , 0x0c , 100 , 3 ) ;
if ( V_17 < 0 ) {
F_9 ( V_61 , L_25 , V_19 , V_17 ) ;
return V_17 ;
}
V_17 = F_10 ( V_31 , 0x30100120 , 0x0820 ) ;
V_17 = F_10 ( V_31 , 0x30100124 , 0x0820 ) ;
V_17 = F_10 ( V_31 , 0x00010418 , 0x0008 ) ;
V_17 = F_10 ( V_31 , 0x30100014 , 0x2146 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_10 ( V_31 , 0x30100010 , 0x230c ) ;
if ( V_17 < 0 )
return V_17 ;
F_15 ( 200 , 250 ) ;
V_17 = F_35 ( V_31 , 0x230e , 100 , 300 ) ;
if ( V_17 < 0 )
F_9 ( V_61 , L_24 , V_17 ) ;
V_17 = F_10 ( V_31 , 0x30000004 , 0xfffd ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_10 ( V_31 , 0x301000a4 , 0x0183 ) ;
if ( V_17 < 0 )
return V_17 ;
F_40 ( V_31 ) ;
V_17 = F_36 ( V_31 ) ;
F_42 ( V_31 ) ;
return V_17 ;
}
static int F_44 ( struct V_30 * V_31 , bool V_112 )
{
static const T_1 V_115 [] [ 2 ] = {
{ 0x3100010c , 0x0044 } ,
{ 0x31000108 , 0x000d } ,
{ 0x31000304 , 0x0001 } ,
{ 0x00010000 , 0x5800 } ,
{ 0x00010002 , 0x0002 } ,
{ 0x31000000 , 0x0001 } ,
{ 0x30100014 , 0x1b85 } ,
{ 0x30100010 , 0x230c }
} ;
struct V_60 * V_61 = & V_31 -> V_46 ;
int V_100 , V_17 ;
V_17 = F_10 ( V_31 , 0x30000004 , 0xffff ) ;
if ( V_17 < 0 )
return V_17 ;
F_15 ( 400 , 450 ) ;
V_17 = F_35 ( V_31 , 0x0c , 100 , 4 ) ;
if ( V_17 < 0 ) {
F_9 ( V_61 , L_26 , V_17 ) ;
return V_17 ;
}
for ( V_100 = 0 ; V_100 < F_41 ( V_115 ) ; V_100 ++ ) {
V_17 = F_10 ( V_31 , V_115 [ V_100 ] [ 0 ] , V_115 [ V_100 ] [ 1 ] ) ;
if ( V_17 < 0 )
return V_17 ;
}
F_21 ( 200 ) ;
V_17 = F_35 ( V_31 , 0x230e , 1000 , 150 ) ;
if ( V_17 < 0 ) {
F_9 ( V_61 , L_27 , V_17 ) ;
return V_17 ;
}
V_17 = F_10 ( V_31 , 0x30000004 , 0xfffd ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_10 ( V_31 , 0x301000a4 , 0x0183 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_10 ( V_31 , 0x30000004 , 0xffff ) ;
if ( V_17 < 0 )
return V_17 ;
V_31 -> V_69 = 1 ;
return F_36 ( V_31 ) ;
}
static int F_45 ( struct V_30 * V_31 )
{
int V_17 ;
V_31 -> V_36 = 0 ;
V_31 -> V_32 = 0 ;
V_17 = F_2 ( V_31 -> V_12 , V_116 , 0x3310 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_117 )
return F_44 ( V_31 , true ) ;
else
return F_39 ( V_31 , true ) ;
}
static const struct V_3 * F_46 (
struct V_1 * V_118 ,
enum V_119 V_120 )
{
const struct V_3 * V_4 ;
const struct V_3 * V_121 ;
int V_122 = V_123 ;
int V_100 ;
V_4 = V_124 [ V_120 ] ;
V_121 = NULL ;
for ( V_100 = 0 ; V_100 < V_125 [ V_120 ] ; ++ V_100 ) {
int V_126 = abs ( V_4 -> V_6 - V_118 -> V_6 ) +
abs ( V_4 -> V_7 - V_118 -> V_7 ) ;
if ( V_126 < V_122 ) {
V_122 = V_126 ;
V_121 = V_4 ;
}
++ V_4 ;
}
return V_121 ;
}
static void F_47 ( struct V_30 * V_31 ,
struct V_127 * V_128 ,
struct V_129 * V_118 ,
const struct V_3 * * V_4 )
{
struct V_60 * V_61 = & V_31 -> V_46 ;
T_1 V_5 ;
switch ( V_118 -> V_130 ) {
case V_131 :
* V_4 = F_46 ( & V_118 -> V_132 , V_72 ) ;
V_5 = V_133 ;
break;
case V_134 :
* V_4 = F_46 ( & V_118 -> V_132 , V_74 ) ;
V_5 = V_79 ;
break;
case V_135 :
default:
if ( V_118 -> V_132 . V_5 == V_79 )
V_5 = V_79 ;
else
V_5 = V_133 ;
if ( V_118 -> V_136 == V_137 )
* V_4 = V_31 -> V_138 [ V_72 ] ;
else
* V_4 = F_46 (
F_48 ( V_61 , V_128 ,
V_131 ) ,
V_72 ) ;
break;
}
F_1 ( & V_118 -> V_132 , * V_4 , V_5 ) ;
}
static void F_49 ( struct V_30 * V_31 ,
struct V_127 * V_128 ,
struct V_129 * V_118 ,
const struct V_3 * * V_4 )
{
T_1 V_5 ;
if ( V_118 -> V_130 == V_139 ) {
* V_4 = F_46 ( & V_118 -> V_132 , V_72 ) ;
V_5 = V_133 ;
} else {
* V_4 = F_46 ( & V_118 -> V_132 , V_74 ) ;
V_5 = V_79 ;
}
F_1 ( & V_118 -> V_132 , * V_4 , V_5 ) ;
}
static int F_50 ( struct V_60 * V_61 ,
struct V_140 * V_141 )
{
struct V_30 * V_31 = F_32 ( V_61 ) ;
if ( V_141 -> V_130 != V_135 )
return - V_67 ;
F_33 ( & V_31 -> V_96 ) ;
V_141 -> V_142 = V_31 -> V_84 -> V_142 ;
F_34 ( & V_31 -> V_96 ) ;
return 0 ;
}
static int F_51 ( struct V_30 * V_31 ,
struct V_140 * V_141 )
{
const struct V_3 * V_70 =
V_31 -> V_71 [ V_72 ] ;
const struct V_143 * V_84 = & V_144 [ 0 ] ;
unsigned int V_17 , V_145 = V_146 ;
unsigned int V_100 , V_147 ;
if ( V_141 -> V_142 . V_148 == 0 )
return - V_67 ;
V_147 = V_141 -> V_142 . V_149 * 1000 / V_141 -> V_142 . V_148 ;
for ( V_100 = 0 ; V_100 < F_41 ( V_144 ) ; V_100 ++ ) {
const struct V_143 * V_150 = & V_144 [ V_100 ] ;
if ( V_70 -> V_6 > V_150 -> V_68 . V_6 ||
V_70 -> V_7 > V_150 -> V_68 . V_7 )
continue;
V_17 = abs ( V_150 -> V_142 . V_149 / 1000 - V_147 ) ;
if ( V_17 < V_145 ) {
V_84 = V_150 ;
V_145 = V_17 ;
}
}
V_31 -> V_84 = V_84 ;
F_8 ( 1 , V_18 , & V_31 -> V_46 ,
L_28 , V_84 -> V_142 . V_149 ) ;
return 0 ;
}
static int F_52 ( struct V_60 * V_61 ,
struct V_140 * V_141 )
{
struct V_30 * V_31 = F_32 ( V_61 ) ;
int V_17 ;
if ( V_141 -> V_130 != V_135 )
return - V_67 ;
F_8 ( 1 , V_18 , V_61 , L_29 ,
V_141 -> V_142 . V_149 , V_141 -> V_142 . V_148 ) ;
F_33 ( & V_31 -> V_96 ) ;
V_17 = F_51 ( V_31 , V_141 ) ;
if ( ! V_17 ) {
if ( V_31 -> V_95 )
V_17 = F_28 ( V_31 ) ;
else
V_31 -> V_87 = 1 ;
}
F_34 ( & V_31 -> V_96 ) ;
return V_17 ;
}
static int F_53 ( struct V_60 * V_61 ,
struct V_127 * V_128 ,
struct V_151 * V_152 )
{
struct V_30 * V_31 = F_32 ( V_61 ) ;
const struct V_143 * V_141 ;
int V_17 = 0 ;
if ( V_152 -> V_130 != V_135 )
return - V_67 ;
if ( V_152 -> V_153 >= F_41 ( V_144 ) )
return - V_67 ;
F_33 ( & V_31 -> V_96 ) ;
V_141 = & V_144 [ V_152 -> V_153 ] ;
if ( V_152 -> V_6 > V_141 -> V_68 . V_6 || V_152 -> V_7 > V_141 -> V_68 . V_7 )
V_17 = - V_67 ;
else
V_152 -> V_142 = V_141 -> V_142 ;
F_34 ( & V_31 -> V_96 ) ;
return V_17 ;
}
static int F_54 ( int V_130 , int V_153 )
{
if ( V_130 == V_135 ) {
if ( V_153 > 1 )
return - V_67 ;
return ( V_153 == 0 ) ? V_133 : V_79 ;
}
if ( V_153 > 0 )
return - V_67 ;
return ( V_130 == V_131 ) ? V_133 : V_79 ;
}
static int F_55 ( struct V_60 * V_61 ,
struct V_127 * V_128 ,
struct V_129 * V_118 )
{
struct V_30 * V_31 = F_23 ( V_61 ) ;
const struct V_3 * V_4 ;
T_1 V_5 ;
if ( V_118 -> V_136 == V_154 ) {
V_118 -> V_132 = * F_48 ( V_61 , V_128 , V_118 -> V_130 ) ;
return 0 ;
}
F_33 ( & V_31 -> V_96 ) ;
switch ( V_118 -> V_130 ) {
case V_139 :
V_5 = V_133 ;
V_4 = V_31 -> V_71 [ V_72 ] ;
break;
case V_155 :
V_5 = V_79 ;
V_4 = V_31 -> V_71 [ V_74 ] ;
break;
default:
F_34 ( & V_31 -> V_96 ) ;
return - V_67 ;
}
F_1 ( & V_118 -> V_132 , V_4 , V_5 ) ;
F_34 ( & V_31 -> V_96 ) ;
return 0 ;
}
static int F_56 ( struct V_60 * V_61 ,
struct V_127 * V_128 ,
struct V_129 * V_118 )
{
struct V_30 * V_31 = F_32 ( V_61 ) ;
const struct V_3 * V_4 ;
T_1 V_5 ;
if ( V_118 -> V_136 == V_154 ) {
V_118 -> V_132 = * F_48 ( V_61 , V_128 , V_118 -> V_130 ) ;
return 0 ;
}
F_33 ( & V_31 -> V_96 ) ;
switch ( V_118 -> V_130 ) {
case V_131 :
V_5 = V_133 ;
V_4 = V_31 -> V_138 [ V_72 ] ;
break;
case V_134 :
V_5 = V_79 ;
V_4 = V_31 -> V_138 [ V_74 ] ;
break;
case V_135 :
V_5 = V_31 -> V_78 ;
V_4 = V_31 -> V_138 [ V_72 ] ;
break;
default:
F_34 ( & V_31 -> V_96 ) ;
return - V_67 ;
}
F_1 ( & V_118 -> V_132 , V_4 , V_5 ) ;
F_34 ( & V_31 -> V_96 ) ;
return 0 ;
}
static int F_57 ( struct V_60 * V_61 ,
struct V_127 * V_128 ,
struct V_129 * V_118 )
{
const struct V_3 * V_156 = NULL ;
struct V_30 * V_31 = F_23 ( V_61 ) ;
struct V_1 * V_2 ;
int V_17 = 0 ;
F_33 ( & V_31 -> V_96 ) ;
F_49 ( V_31 , V_128 , V_118 , & V_156 ) ;
if ( V_118 -> V_136 == V_154 ) {
V_2 = F_48 ( V_61 , V_128 , V_118 -> V_130 ) ;
* V_2 = V_118 -> V_132 ;
} else {
switch ( V_118 -> V_130 ) {
case V_139 :
V_31 -> V_71 [ V_72 ] = V_156 ;
break;
case V_155 :
V_31 -> V_71 [ V_74 ] = V_156 ;
break;
default:
V_17 = - V_157 ;
}
if ( V_31 -> V_95 )
V_17 = - V_157 ;
else
V_31 -> V_90 = 1 ;
}
F_34 ( & V_31 -> V_96 ) ;
return V_17 ;
}
static int F_58 ( struct V_60 * V_61 ,
struct V_127 * V_128 ,
struct V_129 * V_118 )
{
const struct V_3 * V_156 = NULL ;
struct V_30 * V_31 = F_32 ( V_61 ) ;
struct V_1 * V_2 ;
int V_17 = 0 ;
F_33 ( & V_31 -> V_96 ) ;
F_47 ( V_31 , V_128 , V_118 , & V_156 ) ;
if ( V_118 -> V_136 == V_154 ) {
V_2 = F_48 ( V_61 , V_128 , V_118 -> V_130 ) ;
* V_2 = V_118 -> V_132 ;
if ( V_118 -> V_130 == V_131 ) {
V_2 = F_48 ( V_61 , V_128 , V_135 ) ;
V_2 -> V_6 = V_118 -> V_132 . V_6 ;
V_2 -> V_7 = V_118 -> V_132 . V_7 ;
}
} else {
switch ( V_118 -> V_130 ) {
case V_131 :
V_31 -> V_138 [ V_72 ] = V_156 ;
break;
case V_134 :
V_31 -> V_138 [ V_74 ] = V_156 ;
break;
case V_135 :
V_31 -> V_78 = V_118 -> V_132 . V_5 ;
break;
default:
V_17 = - V_157 ;
}
if ( V_31 -> V_95 )
V_17 = - V_157 ;
else
V_31 -> V_90 = 1 ;
}
F_34 ( & V_31 -> V_96 ) ;
return V_17 ;
}
static int F_59 ( struct V_60 * V_61 , unsigned int V_130 ,
struct V_158 * V_159 )
{
struct V_30 * V_31 = F_32 ( V_61 ) ;
int V_100 ;
if ( V_130 != V_135 || V_159 == NULL )
return - V_67 ;
F_33 ( & V_31 -> V_96 ) ;
V_159 -> V_160 = 2 ;
for ( V_100 = 0 ; V_100 < V_159 -> V_160 ; V_100 ++ )
V_159 -> V_161 [ V_100 ] = V_31 -> V_162 . V_161 [ V_100 ] ;
F_34 ( & V_31 -> V_96 ) ;
return 0 ;
}
static int F_60 ( struct V_60 * V_61 , unsigned int V_130 ,
struct V_158 * V_159 )
{
struct V_30 * V_31 = F_32 ( V_61 ) ;
struct V_158 * V_162 = & V_31 -> V_162 ;
int V_100 ;
if ( V_130 != V_135 || V_159 == NULL )
return - V_67 ;
V_159 -> V_161 [ 0 ] . V_163 = 10 * V_164 ;
V_159 -> V_161 [ 1 ] . V_163 = F_61 ( T_1 , V_159 -> V_161 [ 1 ] . V_163 ,
V_165 ) ;
V_159 -> V_160 = 2 ;
F_33 ( & V_31 -> V_96 ) ;
for ( V_100 = 0 ; V_100 < V_159 -> V_160 ; V_100 ++ )
V_162 -> V_161 [ V_100 ] = V_159 -> V_161 [ V_100 ] ;
F_34 ( & V_31 -> V_96 ) ;
return 0 ;
}
static int F_62 ( struct V_60 * V_61 ,
struct V_127 * V_128 ,
struct V_166 * V_5 )
{
static const int V_167 [] = {
[ V_139 ] = V_133 ,
[ V_155 ] = V_79 } ;
if ( V_5 -> V_153 > 0 || V_5 -> V_130 >= V_168 )
return - V_67 ;
V_5 -> V_5 = V_167 [ V_5 -> V_130 ] ;
return 0 ;
}
static int F_63 ( struct V_60 * V_61 ,
struct V_127 * V_128 ,
struct V_166 * V_5 )
{
int V_17 ;
V_17 = F_54 ( V_5 -> V_130 , V_5 -> V_153 ) ;
if ( V_17 < 0 )
return V_17 ;
V_5 -> V_5 = V_17 ;
return 0 ;
}
static int F_64 ( struct V_60 * V_61 ,
struct V_127 * V_128 ,
struct V_169 * V_170 )
{
int V_120 ;
if ( V_170 -> V_130 == V_139 ) {
if ( V_170 -> V_5 != V_133 )
return - V_67 ;
V_120 = V_72 ;
} else{
if ( V_170 -> V_5 != V_79 )
return - V_67 ;
V_120 = V_74 ;
}
if ( V_170 -> V_153 >= V_125 [ V_120 ] )
return - V_67 ;
V_170 -> V_171 = V_124 [ V_120 ] [ V_170 -> V_153 ] . V_6 ;
V_170 -> V_172 = V_170 -> V_171 ;
V_170 -> V_173 = V_124 [ V_120 ] [ V_170 -> V_153 ] . V_7 ;
V_170 -> V_174 = V_170 -> V_173 ;
return 0 ;
}
static int F_65 ( struct V_60 * V_61 ,
struct V_127 * V_128 ,
struct V_169 * V_170 )
{
struct V_30 * V_31 = F_32 ( V_61 ) ;
int V_120 ;
if ( V_170 -> V_130 == V_135 ) {
if ( V_170 -> V_153 > 0 )
return - V_67 ;
switch ( V_170 -> V_5 ) {
case V_79 :
case V_133 : {
unsigned V_175 , V_176 ;
if ( V_170 -> V_136 == V_154 ) {
struct V_1 * V_2 ;
V_2 = F_48 ( V_61 , V_128 ,
V_131 ) ;
V_175 = V_2 -> V_6 ;
V_176 = V_2 -> V_7 ;
} else {
const struct V_3 * V_4 ;
V_4 = V_31 -> V_138 [ V_72 ] ;
V_175 = V_4 -> V_6 ;
V_176 = V_4 -> V_7 ;
}
V_170 -> V_172 = V_170 -> V_171 = V_175 ;
V_170 -> V_173 = V_170 -> V_174 = V_176 ;
return 0 ;
}
default:
return - V_67 ;
}
}
if ( V_170 -> V_5 != F_54 ( V_170 -> V_130 , 0 ) )
return - V_67 ;
if ( V_170 -> V_130 == V_134 )
V_120 = V_74 ;
else
V_120 = V_72 ;
if ( V_170 -> V_153 >= V_125 [ V_120 ] )
return - V_67 ;
V_170 -> V_171 = V_124 [ V_120 ] [ V_170 -> V_153 ] . V_6 ;
V_170 -> V_172 = V_170 -> V_171 ;
V_170 -> V_173 = V_124 [ V_120 ] [ V_170 -> V_153 ] . V_7 ;
V_170 -> V_174 = V_170 -> V_173 ;
return 0 ;
}
static int F_66 ( struct V_60 * V_61 )
{
struct V_30 * V_31 = F_32 ( V_61 ) ;
F_67 ( V_61 -> V_177 , V_61 -> V_178 ) ;
F_20 ( V_61 , L_30 , V_31 -> V_179 ,
V_31 -> V_90 ) ;
return 0 ;
}
static int F_68 ( struct V_60 * V_61 , struct V_180 * V_181 )
{
struct V_1 * V_2 ;
V_2 = F_48 ( V_61 , V_181 -> V_130 , V_139 ) ;
F_1 ( V_2 , & V_182 [ 1 ] ,
V_133 ) ;
V_2 = F_48 ( V_61 , V_181 -> V_130 , V_155 ) ;
F_1 ( V_2 , & V_183 [ 1 ] ,
V_79 ) ;
return 0 ;
}
static int F_69 ( struct V_60 * V_61 , struct V_180 * V_181 )
{
struct V_1 * V_2 ;
V_2 = F_48 ( V_61 , V_181 -> V_130 , V_131 ) ;
F_1 ( V_2 , & V_182 [ 1 ] ,
V_133 ) ;
V_2 = F_48 ( V_61 , V_181 -> V_130 , V_134 ) ;
F_1 ( V_2 , & V_183 [ 1 ] ,
V_79 ) ;
V_2 = F_48 ( V_61 , V_181 -> V_130 , V_135 ) ;
F_1 ( V_2 , & V_182 [ 1 ] ,
V_133 ) ;
return 0 ;
}
static int F_70 ( struct V_30 * V_184 , int V_185 , T_1 V_83 )
{
if ( ! F_71 ( V_184 -> V_186 [ V_185 ] . V_186 ) )
return 0 ;
F_72 ( V_184 -> V_186 [ V_185 ] . V_186 , ! ! V_83 ) ;
return 1 ;
}
static int F_73 ( struct V_30 * V_184 , int V_185 )
{
return F_70 ( V_184 , V_185 , V_184 -> V_186 [ V_185 ] . V_187 ) ;
}
static int F_74 ( struct V_30 * V_184 , int V_185 )
{
return F_70 ( V_184 , V_185 , ! V_184 -> V_186 [ V_185 ] . V_187 ) ;
}
static int F_75 ( struct V_30 * V_31 )
{
int V_100 , V_17 ;
for ( V_100 = 0 ; V_100 < V_188 ; V_100 ++ ) {
V_17 = F_76 ( V_31 -> V_189 [ V_100 ] . V_190 ) ;
if ( V_17 )
goto V_191;
}
V_17 = F_77 ( V_31 -> clock , V_31 -> V_192 ) ;
if ( V_17 < 0 )
goto V_191;
V_17 = F_78 ( V_31 -> clock ) ;
if ( V_17 < 0 )
goto V_191;
F_8 ( 1 , V_18 , & V_31 -> V_193 , L_31 ,
F_79 ( V_31 -> clock ) ) ;
F_74 ( V_31 , V_194 ) ;
F_15 ( 100 , 200 ) ;
F_74 ( V_31 , V_195 ) ;
F_15 ( 50 , 100 ) ;
return 0 ;
V_191:
for ( -- V_100 ; V_100 >= 0 ; V_100 -- )
F_80 ( V_31 -> V_189 [ V_100 ] . V_190 ) ;
return V_17 ;
}
static int F_81 ( struct V_30 * V_31 )
{
int V_100 , V_17 ;
if ( F_73 ( V_31 , V_195 ) )
F_15 ( 10 , 50 ) ;
if ( F_73 ( V_31 , V_194 ) )
F_15 ( 100 , 200 ) ;
F_82 ( V_31 -> clock ) ;
V_31 -> V_95 = 0 ;
V_31 -> V_69 = 0 ;
for ( V_100 = V_188 - 1 ; V_100 >= 0 ; V_100 -- ) {
V_17 = F_80 ( V_31 -> V_189 [ V_100 ] . V_190 ) ;
if ( V_17 )
goto V_196;
}
return 0 ;
V_196:
for ( ++ V_100 ; V_100 < V_188 ; V_100 ++ ) {
int V_197 = F_76 ( V_31 -> V_189 [ V_100 ] . V_190 ) ;
if ( V_197 < 0 )
F_9 ( & V_31 -> V_193 , L_32 ,
V_31 -> V_189 [ V_100 ] . V_198 , V_197 ) ;
}
F_78 ( V_31 -> clock ) ;
return V_17 ;
}
static int F_83 ( struct V_60 * V_61 , int V_88 )
{
struct V_30 * V_31 = F_32 ( V_61 ) ;
int V_17 = 0 ;
F_33 ( & V_31 -> V_96 ) ;
if ( V_88 && ! V_31 -> V_179 ) {
V_17 = F_75 ( V_31 ) ;
if ( ! V_17 )
V_17 = F_45 ( V_31 ) ;
if ( ! V_17 ) {
V_31 -> V_87 = 1 ;
V_31 -> V_90 = 1 ;
}
} else if ( V_31 -> V_179 == ! V_88 ) {
V_17 = F_19 ( V_31 ) ;
if ( ! V_17 )
V_17 = F_81 ( V_31 ) ;
else
F_9 ( V_61 , L_33 ) ;
}
if ( ! V_17 )
V_31 -> V_179 += V_88 ? 1 : - 1 ;
F_8 ( 1 , V_18 , V_61 , L_34 ,
V_19 , V_31 -> V_179 ) ;
F_34 ( & V_31 -> V_96 ) ;
return V_17 ;
}
static int F_84 ( struct V_60 * V_61 )
{
struct V_30 * V_31 = F_32 ( V_61 ) ;
int V_17 ;
V_17 = F_85 ( V_61 -> V_199 , & V_31 -> V_46 ) ;
if ( V_17 ) {
F_9 ( V_61 -> V_199 , L_35 ,
V_31 -> V_193 . V_178 ) ;
return V_17 ;
}
V_17 = F_86 ( & V_31 -> V_46 . V_200 ,
V_139 , & V_31 -> V_193 . V_200 , V_131 ,
V_201 | V_202 ) ;
V_17 = F_86 ( & V_31 -> V_46 . V_200 ,
V_155 , & V_31 -> V_193 . V_200 , V_134 ,
V_201 | V_202 ) ;
return V_17 ;
}
static void F_87 ( struct V_60 * V_61 )
{
struct V_30 * V_31 = F_32 ( V_61 ) ;
F_88 ( & V_31 -> V_46 ) ;
}
static int F_89 ( struct V_30 * V_31 )
{
static const char * const V_203 [] = {
L_36 , L_37
} ;
struct V_12 * V_204 = V_31 -> V_12 ;
struct V_205 * V_206 = V_31 -> V_186 ;
int V_17 , V_100 ;
for ( V_100 = 0 ; V_100 < V_207 ; ++ V_100 ) {
unsigned int V_25 = V_208 ;
if ( V_206 [ V_100 ] . V_187 )
V_25 |= V_209 ;
V_17 = F_90 ( & V_204 -> V_66 , V_206 [ V_100 ] . V_186 , V_25 ,
V_203 [ V_100 ] ) ;
if ( V_17 ) {
F_9 ( V_204 , L_38 ,
V_203 [ V_100 ] ) ;
return V_17 ;
}
}
return 0 ;
}
static int F_91 ( struct V_30 * V_31 )
{
static const char * const V_210 [] = {
L_39 , L_40 ,
} ;
struct V_211 * V_66 = & V_31 -> V_12 -> V_66 ;
struct V_212 * V_213 = V_66 -> V_214 ;
int V_17 , V_100 ;
for ( V_100 = 0 ; V_100 < V_207 ; ++ V_100 ) {
enum V_215 V_216 ;
V_17 = F_92 ( V_213 , V_210 [ V_100 ] ,
0 , & V_216 ) ;
if ( V_17 < 0 ) {
F_93 ( V_66 , L_41 ,
V_210 [ V_100 ] ) ;
return - V_67 ;
}
V_31 -> V_186 [ V_100 ] . V_186 = V_17 ;
V_31 -> V_186 [ V_100 ] . V_187 = ! ( V_216 & V_217 ) ;
}
return 0 ;
}
static int F_94 ( struct V_30 * V_31 )
{
struct V_211 * V_66 = & V_31 -> V_12 -> V_66 ;
const struct V_218 * V_219 = V_66 -> V_220 ;
struct V_212 * V_213 = V_66 -> V_214 ;
struct V_212 * V_221 ;
struct V_222 V_223 ;
int V_17 ;
if ( ! V_213 ) {
if ( ! V_219 ) {
F_93 ( V_66 , L_42 ) ;
return - V_67 ;
}
V_31 -> V_192 = V_219 -> V_192 ;
V_31 -> V_186 [ V_194 ] = V_219 -> V_224 ;
V_31 -> V_186 [ V_195 ] = V_219 -> V_225 ;
return 0 ;
}
V_31 -> clock = F_95 ( V_66 , V_226 ) ;
if ( F_96 ( V_31 -> clock ) )
return F_97 ( V_31 -> clock ) ;
if ( F_98 ( V_213 , L_43 ,
& V_31 -> V_192 ) ) {
V_31 -> V_192 = V_227 ;
F_99 ( V_66 , L_44 ,
V_31 -> V_192 ) ;
}
V_17 = F_91 ( V_31 ) ;
if ( V_17 < 0 )
return - V_67 ;
V_221 = F_100 ( V_213 , NULL ) ;
if ( ! V_221 ) {
F_101 ( V_66 , L_45 ,
V_213 -> V_228 ) ;
return 0 ;
}
F_102 ( V_221 , & V_223 ) ;
F_103 ( V_221 ) ;
if ( V_223 . V_229 != V_230 ) {
F_93 ( V_66 , L_46 ) ;
return - V_67 ;
}
if ( V_223 . V_231 . V_232 . V_233 != V_234 )
F_99 ( V_66 , L_47 ) ;
return 0 ;
}
static int F_104 ( struct V_12 * V_13 ,
const struct V_235 * V_185 )
{
struct V_211 * V_66 = & V_13 -> V_66 ;
struct V_60 * V_61 ;
struct V_60 * V_193 ;
struct V_30 * V_31 ;
int V_17 , V_100 ;
V_31 = F_105 ( V_66 , sizeof( * V_31 ) , V_236 ) ;
if ( ! V_31 )
return - V_237 ;
V_31 -> V_12 = V_13 ;
V_17 = F_94 ( V_31 ) ;
if ( V_17 < 0 )
return V_17 ;
F_106 ( & V_31 -> V_96 ) ;
V_61 = & V_31 -> V_46 ;
V_193 = & V_31 -> V_193 ;
F_107 ( V_61 , & V_238 ) ;
V_61 -> V_239 = V_13 -> V_66 . V_240 -> V_239 ;
F_108 ( V_61 , V_31 ) ;
F_109 ( V_61 -> V_178 , L_48 , sizeof( V_61 -> V_178 ) ) ;
V_61 -> V_241 = & V_242 ;
V_61 -> V_25 |= V_243 ;
V_31 -> V_244 [ V_155 ] . V_25 = V_245 ;
V_31 -> V_244 [ V_139 ] . V_25 = V_245 ;
V_61 -> V_200 . V_246 = V_247 ;
V_17 = F_110 ( & V_61 -> V_200 , V_168 ,
V_31 -> V_244 ) ;
if ( V_17 < 0 )
return V_17 ;
F_111 ( V_193 , V_13 , & V_248 ) ;
strcpy ( V_193 -> V_178 , L_49 ) ;
V_193 -> V_241 = & V_249 ;
V_193 -> V_25 |= V_243 ;
V_31 -> V_250 [ V_131 ] . V_25 = V_251 ;
V_31 -> V_250 [ V_134 ] . V_25 = V_251 ;
V_31 -> V_250 [ V_135 ] . V_25 = V_245 ;
V_193 -> V_200 . V_246 = V_252 ;
V_17 = F_110 ( & V_193 -> V_200 , V_253 ,
V_31 -> V_250 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_89 ( V_31 ) ;
if ( V_17 )
goto V_254;
for ( V_100 = 0 ; V_100 < V_188 ; V_100 ++ )
V_31 -> V_189 [ V_100 ] . V_198 = V_255 [ V_100 ] ;
V_17 = F_112 ( V_66 , V_188 ,
V_31 -> V_189 ) ;
if ( V_17 ) {
F_93 ( V_66 , L_50 ) ;
goto V_254;
}
V_17 = F_113 ( V_31 ) ;
if ( V_17 )
goto V_254;
V_31 -> V_71 [ V_72 ] = & V_182 [ 1 ] ;
V_31 -> V_71 [ V_74 ] = & V_183 [ 1 ] ;
V_31 -> V_138 [ V_72 ] = V_31 -> V_71 [ V_72 ] ;
V_31 -> V_138 [ V_74 ] = V_31 -> V_71 [ V_74 ] ;
V_31 -> V_78 = V_133 ;
V_31 -> V_84 = & V_144 [ V_256 ] ;
V_31 -> V_65 [ 0 ] = 'G' ;
V_31 -> V_65 [ 1 ] = 'C' ;
V_17 = F_114 ( V_31 ) ;
if ( V_17 < 0 )
goto V_254;
V_193 -> V_66 = V_66 ;
V_17 = F_75 ( V_31 ) ;
if ( V_17 < 0 )
goto V_257;
V_17 = F_43 ( V_31 ) ;
F_81 ( V_31 ) ;
if ( V_17 < 0 ) {
F_93 ( V_66 , L_51 , V_17 ) ;
goto V_257;
}
V_17 = F_115 ( V_193 ) ;
if ( V_17 < 0 )
goto V_257;
F_20 ( V_61 , L_52 , V_19 ) ;
return 0 ;
V_257:
F_116 ( V_31 ) ;
V_254:
F_117 ( & V_61 -> V_200 ) ;
return V_17 ;
}
static int F_118 ( struct V_12 * V_13 )
{
struct V_60 * V_193 = F_119 ( V_13 ) ;
struct V_30 * V_31 = F_32 ( V_193 ) ;
struct V_60 * V_46 = & V_31 -> V_46 ;
F_120 ( V_193 ) ;
F_121 ( V_193 -> V_177 ) ;
F_117 ( & V_193 -> V_200 ) ;
F_88 ( V_46 ) ;
F_117 ( & V_46 -> V_200 ) ;
F_116 ( V_31 ) ;
return 0 ;
}
