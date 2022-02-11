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
* V_15 = F_7 ( ( T_2 * ) V_21 ) ;
F_8 ( 4 , V_18 , V_13 ,
L_2 ,
V_19 , V_14 , * V_15 ) ;
return 0 ;
}
F_9 ( V_13 , L_3 , V_14 , V_17 ) ;
return V_17 >= 0 ? - V_20 : V_17 ;
}
int F_10 ( struct V_29 * V_30 , T_1 V_14 , T_2 V_15 )
{
struct V_12 * V_13 = V_30 -> V_12 ;
int V_17 ;
if ( ( V_14 ^ V_30 -> V_31 ) & 0xffff0000 ) {
V_17 = F_2 ( V_13 , V_32 , V_14 >> 16 ) ;
if ( V_17 < 0 ) {
V_30 -> V_31 = 0 ;
return V_17 ;
}
}
if ( ( V_14 ^ V_30 -> V_31 ) & 0xffff ) {
V_17 = F_2 ( V_13 , V_33 , V_14 & 0xffff ) ;
if ( V_17 < 0 ) {
V_30 -> V_31 = 0 ;
return V_17 ;
}
}
V_30 -> V_31 = V_14 ;
V_17 = F_2 ( V_13 , V_34 , V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
V_30 -> V_31 += 2 ;
return V_17 ;
}
int F_11 ( struct V_29 * V_30 , T_1 V_14 , T_2 * V_15 )
{
struct V_12 * V_13 = V_30 -> V_12 ;
int V_17 ;
if ( ( V_14 ^ V_30 -> V_35 ) & 0xffff0000 ) {
V_17 = F_2 ( V_13 , V_36 , V_14 >> 16 ) ;
if ( V_17 < 0 ) {
V_30 -> V_35 = 0 ;
return V_17 ;
}
}
if ( ( V_14 ^ V_30 -> V_35 ) & 0xffff ) {
V_17 = F_2 ( V_13 , V_37 , V_14 & 0xffff ) ;
if ( V_17 < 0 ) {
V_30 -> V_35 = 0 ;
return V_17 ;
}
}
V_30 -> V_35 = V_14 ;
V_17 = F_5 ( V_13 , V_34 , V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
V_30 -> V_35 += 2 ;
return V_17 ;
}
static int F_12 ( struct V_29 * V_30 , unsigned int V_38 )
{
unsigned long V_39 = V_40 ;
unsigned long V_41 = V_39 + F_13 ( 2000 ) ;
int V_17 = 0 ;
T_2 V_42 ;
int V_43 = 0 ;
while ( F_14 ( V_41 ) ) {
V_17 = F_11 ( V_30 , V_44 , & V_42 ) ;
if ( V_17 < 0 || V_42 == V_38 )
break;
F_15 ( 500 , 1000 ) ;
++ V_43 ;
}
if ( V_43 > 0 )
F_8 ( 1 , V_18 , & V_30 -> V_45 ,
L_4 ,
F_16 ( V_40 - V_39 ) ) ;
if ( V_17 == 0 && V_42 != V_38 ) {
T_2 V_46 = 0 ;
T_2 V_47 = 0 ;
F_11 ( V_30 , V_48 , & V_46 ) ;
F_11 ( V_30 , V_49 , & V_47 ) ;
F_9 ( & V_30 -> V_45 ,
L_5 ,
V_42 , V_38 , V_46 , V_47 ) ;
return - V_50 ;
}
return V_17 ;
}
int F_17 ( struct V_29 * V_30 , T_2 V_51 , T_2 V_15 )
{
int V_17 ;
V_17 = F_12 ( V_30 , V_52 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_10 ( V_30 , 0x00095000 , V_51 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_10 ( V_30 , 0x00095002 , V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
return F_10 ( V_30 , V_44 , 0x0001 ) ;
}
static int F_18 ( struct V_29 * V_30 , T_2 V_51 ,
T_2 * V_15 )
{
return F_11 ( V_30 , V_53 + V_51 , V_15 ) ;
}
static int F_19 ( struct V_29 * V_30 )
{
unsigned long V_39 = V_40 ;
T_2 V_54 ;
int V_43 = 0 ;
int V_17 ;
const char * V_24 ;
V_17 = F_17 ( V_30 , V_55 ,
V_56 ) ;
if ( V_17 < 0 ) {
F_20 ( & V_30 -> V_45 , L_6 ) ;
return V_17 ;
}
for (; ; ) {
V_17 = F_18 ( V_30 , V_55 ,
& V_54 ) ;
if ( V_17 < 0 ) {
V_24 = L_7 ;
break;
}
if ( V_54 == V_57 ) {
V_24 = L_8 ;
break;
}
if ( ++ V_43 > 100 ) {
V_17 = - V_58 ;
V_24 = L_9 ;
break;
}
F_21 ( 25 ) ;
}
F_20 ( & V_30 -> V_45 , L_10 ,
V_24 , F_16 ( V_40 - V_39 ) ) ;
return V_17 ;
}
static int F_22 ( struct V_59 * V_60 )
{
struct V_29 * V_30 = F_23 ( V_60 ) ;
struct V_12 * V_13 = V_30 -> V_12 ;
const struct V_61 * V_62 ;
int V_17 ;
char V_63 [ 20 ] ;
snprintf ( V_63 , sizeof( V_63 ) , L_11 ,
V_30 -> V_64 ) ;
V_17 = F_24 ( & V_62 , V_63 , & V_13 -> V_65 ) ;
if ( V_17 < 0 ) {
F_9 ( V_60 , L_12 , V_63 ) ;
return - V_66 ;
}
F_20 ( V_60 , L_13 , V_63 , V_62 -> V_67 ) ;
V_17 = F_25 ( V_30 , V_62 -> V_15 , V_62 -> V_67 , 64 ) ;
if ( V_17 >= 0 )
V_30 -> V_68 = 1 ;
else
F_9 ( V_60 , L_14 ) ;
F_26 ( V_62 ) ;
return V_17 ;
}
static int F_27 ( struct V_29 * V_30 )
{
const struct V_3 * V_69 =
V_30 -> V_70 [ V_71 ] ;
const struct V_3 * V_72 =
V_30 -> V_70 [ V_73 ] ;
unsigned int V_74 ;
F_8 ( 1 , V_18 , & V_30 -> V_45 ,
L_15 ,
V_69 -> V_6 , V_69 -> V_7 , V_69 -> V_75 ) ;
V_74 = V_69 -> V_75 | V_76 ;
if ( V_30 -> V_77 == V_78 ) {
F_8 ( 1 , V_18 , & V_30 -> V_45 ,
L_16 ,
V_72 -> V_6 , V_72 -> V_7 , V_72 -> V_75 ) ;
V_74 |= V_72 -> V_75 ;
}
return F_17 ( V_30 , V_79 , V_74 ) ;
}
static int F_28 ( struct V_29 * V_30 )
{
int V_17 ;
if ( V_30 -> V_80 . V_81 -> V_82 )
return 0 ;
if ( F_29 ( V_30 -> V_83 == NULL ) )
return - V_66 ;
V_17 = F_17 ( V_30 , V_84 , V_30 -> V_83 -> V_85 ) ;
if ( ! V_17 )
V_30 -> V_86 = 0 ;
return V_17 ;
}
static int F_30 ( struct V_29 * V_30 , struct V_59 * V_60 ,
int V_87 )
{
T_2 V_88 ;
int V_17 ;
if ( V_87 && V_30 -> V_89 ) {
if ( V_30 -> V_77 == V_78 )
V_88 = V_90 ;
else
V_88 = V_91 ;
V_17 = F_17 ( V_30 , V_92 , V_88 ) ;
if ( ! V_17 )
V_17 = F_27 ( V_30 ) ;
if ( V_17 )
return V_17 ;
V_30 -> V_89 = 0 ;
}
V_17 = F_17 ( V_30 , V_93 , ! ! V_87 ) ;
if ( V_17 )
return V_17 ;
V_30 -> V_94 = ! ! V_87 ;
if ( ! V_87 )
return V_17 ;
if ( V_30 -> V_86 ) {
V_17 = F_28 ( V_30 ) ;
if ( V_17 < 0 )
F_9 ( V_60 , L_17 , V_17 ) ;
}
return F_12 ( V_30 , V_52 ) ;
}
static int F_31 ( struct V_59 * V_60 , int V_87 )
{
struct V_29 * V_30 = F_32 ( V_60 ) ;
int V_17 ;
F_33 ( & V_30 -> V_95 ) ;
V_17 = F_30 ( V_30 , V_60 , V_87 ) ;
F_34 ( & V_30 -> V_95 ) ;
return V_17 ;
}
static int F_35 ( struct V_29 * V_30 , T_1 V_38 ,
unsigned int V_96 , unsigned int V_97 )
{
T_2 V_98 = 0 ;
while ( V_97 -- > 0 ) {
int V_17 = F_11 ( V_30 , 0x30100010 , & V_98 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_98 == V_38 )
return 0 ;
F_15 ( V_96 , V_96 + 25 ) ;
}
return - V_50 ;
}
static int F_36 ( struct V_29 * V_30 )
{
struct V_59 * V_60 = & V_30 -> V_45 ;
int V_99 , V_17 ;
T_2 V_15 [ 2 ] ;
int V_100 ;
V_100 = V_30 -> V_68 ? 0x60 : 0 ;
for ( V_99 = 0 ; V_99 < V_101 / 2 ; V_99 ++ ) {
V_17 = F_11 ( V_30 , V_100 + V_99 * 2 , V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
V_30 -> V_102 [ V_99 * 2 ] = ( char ) ( * V_15 & 0xff ) ;
V_30 -> V_102 [ V_99 * 2 + 1 ] = ( char ) ( * V_15 >> 8 ) ;
}
V_30 -> V_102 [ V_101 ] = '\0' ;
for ( V_99 = 0 ; V_99 < V_103 / 2 ; V_99 ++ ) {
V_17 = F_11 ( V_30 , V_100 + 6 + V_99 * 2 , V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
V_30 -> V_104 [ V_99 * 2 ] = ( char ) ( * V_15 & 0xff ) ;
V_30 -> V_104 [ V_99 * 2 + 1 ] = ( char ) ( * V_15 >> 8 ) ;
}
V_30 -> V_104 [ V_103 ] = '\0' ;
V_17 = F_11 ( V_30 , V_100 + 0x14 , V_15 ) ;
if ( V_17 >= 0 ) {
V_17 = F_11 ( V_30 , V_100 + 0x16 , V_15 + 1 ) ;
if ( V_17 >= 0 )
V_30 -> V_105 = V_15 [ 0 ] + ( V_15 [ 1 ] << 16 ) ;
}
F_20 ( V_60 , L_18 ,
V_30 -> V_104 , V_30 -> V_102 ) ;
return V_17 ;
}
static int F_37 ( struct V_29 * V_30 )
{
struct V_59 * V_60 = & V_30 -> V_45 ;
T_2 V_42 = V_106 ;
int V_17 ;
int V_43 = 0 ;
F_38 ( V_60 , L_19 ) ;
do {
if ( V_42 == V_106 ) {
V_17 = F_17 ( V_30 , V_107 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
}
V_17 = F_11 ( V_30 , 0x00095906 , & V_42 ) ;
if ( V_17 < 0 )
return V_17 ;
switch ( V_42 ) {
case V_108 :
F_38 ( V_60 , L_20 ) ;
return - V_109 ;
case V_110 :
F_38 ( V_60 , L_21 ) ;
return 0 ;
}
++ V_43 ;
F_21 ( 20 ) ;
} while ( V_43 < 500 );
F_38 ( V_60 , L_22 ) ;
return - V_50 ;
}
static int F_39 ( struct V_29 * V_30 , bool V_111 )
{
struct V_59 * V_60 = & V_30 -> V_45 ;
int V_17 ;
V_17 = F_10 ( V_30 , 0x30000004 , 0xffff ) ;
if ( V_17 < 0 )
return V_17 ;
F_15 ( 400 , 500 ) ;
V_17 = F_35 ( V_30 , 0x0c , 100 , 3 ) ;
if ( V_17 < 0 ) {
F_9 ( V_60 , L_23 , V_17 ) ;
return V_17 ;
}
V_17 = F_10 ( V_30 , 0x30100014 , 0x2146 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_10 ( V_30 , 0x30100010 , 0x210c ) ;
if ( V_17 < 0 )
return V_17 ;
F_15 ( 200 , 250 ) ;
V_17 = F_35 ( V_30 , 0x210d , 100 , 300 ) ;
if ( V_17 < 0 )
F_9 ( V_60 , L_24 , V_17 ) ;
if ( V_111 )
F_22 ( V_60 ) ;
V_17 = F_10 ( V_30 , 0x30000004 , 0xfffd ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_10 ( V_30 , 0x301000a4 , 0x0183 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_10 ( V_30 , 0x30000004 , 0xffff ) ;
if ( V_17 < 0 || ! V_111 )
return V_17 ;
V_17 = F_36 ( V_30 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_111 && V_112 ) {
V_17 = F_37 ( V_30 ) ;
V_112 = 0 ;
}
return V_17 ;
}
static int F_40 ( struct V_29 * V_30 )
{
static const T_1 V_113 [] [ 2 ] = {
{ 0x30100018 , 0x0618 } ,
{ 0x3010001c , 0x10c1 } ,
{ 0x30100020 , 0x249e }
} ;
int V_17 ;
int V_99 ;
for ( V_99 = 0 ; V_99 < F_41 ( V_113 ) ; V_99 ++ ) {
V_17 = F_10 ( V_30 , V_113 [ V_99 ] [ 0 ] , V_113 [ V_99 ] [ 1 ] ) ;
if ( V_17 < 0 )
return V_17 ;
}
return 0 ;
}
static void F_42 ( struct V_29 * V_30 )
{
switch ( V_30 -> V_102 [ 0 ] ) {
case 'G' :
case 'O' :
V_30 -> V_64 [ 0 ] = 'G' ;
break;
case 'S' :
case 'Z' :
V_30 -> V_64 [ 0 ] = 'Z' ;
break;
}
switch ( V_30 -> V_102 [ 1 ] ) {
case 'C' ... 'F' :
V_30 -> V_64 [ 1 ] = V_30 -> V_102 [ 1 ] ;
break;
}
}
static int F_43 ( struct V_29 * V_30 )
{
struct V_59 * V_60 = & V_30 -> V_45 ;
int V_17 ;
V_17 = F_10 ( V_30 , 0x30000004 , 0xffff ) ;
if ( V_17 < 0 )
return V_17 ;
F_15 ( 400 , 500 ) ;
V_17 = F_35 ( V_30 , 0x0c , 100 , 3 ) ;
if ( V_17 < 0 ) {
F_9 ( V_60 , L_25 , V_19 , V_17 ) ;
return V_17 ;
}
V_17 = F_10 ( V_30 , 0x30100120 , 0x0820 ) ;
V_17 = F_10 ( V_30 , 0x30100124 , 0x0820 ) ;
V_17 = F_10 ( V_30 , 0x00010418 , 0x0008 ) ;
V_17 = F_10 ( V_30 , 0x30100014 , 0x2146 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_10 ( V_30 , 0x30100010 , 0x230c ) ;
if ( V_17 < 0 )
return V_17 ;
F_15 ( 200 , 250 ) ;
V_17 = F_35 ( V_30 , 0x230e , 100 , 300 ) ;
if ( V_17 < 0 )
F_9 ( V_60 , L_24 , V_17 ) ;
V_17 = F_10 ( V_30 , 0x30000004 , 0xfffd ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_10 ( V_30 , 0x301000a4 , 0x0183 ) ;
if ( V_17 < 0 )
return V_17 ;
F_40 ( V_30 ) ;
V_17 = F_36 ( V_30 ) ;
F_42 ( V_30 ) ;
return V_17 ;
}
static int F_44 ( struct V_29 * V_30 , bool V_111 )
{
static const T_1 V_114 [] [ 2 ] = {
{ 0x3100010c , 0x0044 } ,
{ 0x31000108 , 0x000d } ,
{ 0x31000304 , 0x0001 } ,
{ 0x00010000 , 0x5800 } ,
{ 0x00010002 , 0x0002 } ,
{ 0x31000000 , 0x0001 } ,
{ 0x30100014 , 0x1b85 } ,
{ 0x30100010 , 0x230c }
} ;
struct V_59 * V_60 = & V_30 -> V_45 ;
int V_99 , V_17 ;
V_17 = F_10 ( V_30 , 0x30000004 , 0xffff ) ;
if ( V_17 < 0 )
return V_17 ;
F_15 ( 400 , 450 ) ;
V_17 = F_35 ( V_30 , 0x0c , 100 , 4 ) ;
if ( V_17 < 0 ) {
F_9 ( V_60 , L_26 , V_17 ) ;
return V_17 ;
}
for ( V_99 = 0 ; V_99 < F_41 ( V_114 ) ; V_99 ++ ) {
V_17 = F_10 ( V_30 , V_114 [ V_99 ] [ 0 ] , V_114 [ V_99 ] [ 1 ] ) ;
if ( V_17 < 0 )
return V_17 ;
}
F_21 ( 200 ) ;
V_17 = F_35 ( V_30 , 0x230e , 1000 , 150 ) ;
if ( V_17 < 0 ) {
F_9 ( V_60 , L_27 , V_17 ) ;
return V_17 ;
}
V_17 = F_10 ( V_30 , 0x30000004 , 0xfffd ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_10 ( V_30 , 0x301000a4 , 0x0183 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_10 ( V_30 , 0x30000004 , 0xffff ) ;
if ( V_17 < 0 )
return V_17 ;
V_30 -> V_68 = 1 ;
return F_36 ( V_30 ) ;
}
static int F_45 ( struct V_29 * V_30 )
{
int V_17 ;
V_30 -> V_35 = 0 ;
V_30 -> V_31 = 0 ;
V_17 = F_2 ( V_30 -> V_12 , V_115 , 0x3310 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_116 )
return F_44 ( V_30 , true ) ;
else
return F_39 ( V_30 , true ) ;
}
static const struct V_3 * F_46 (
struct V_1 * V_117 ,
enum V_118 V_119 )
{
const struct V_3 * V_4 ;
const struct V_3 * V_120 ;
int V_121 = V_122 ;
int V_99 ;
V_4 = V_123 [ V_119 ] ;
V_120 = NULL ;
for ( V_99 = 0 ; V_99 < V_124 [ V_119 ] ; ++ V_99 ) {
int V_125 = abs ( V_4 -> V_6 - V_117 -> V_6 ) +
abs ( V_4 -> V_7 - V_117 -> V_7 ) ;
if ( V_125 < V_121 ) {
V_121 = V_125 ;
V_120 = V_4 ;
}
++ V_4 ;
}
return V_120 ;
}
static void F_47 ( struct V_29 * V_30 ,
struct V_126 * V_127 ,
struct V_128 * V_117 ,
const struct V_3 * * V_4 )
{
struct V_59 * V_60 = & V_30 -> V_45 ;
T_1 V_5 ;
switch ( V_117 -> V_129 ) {
case V_130 :
* V_4 = F_46 ( & V_117 -> V_131 , V_71 ) ;
V_5 = V_132 ;
break;
case V_133 :
* V_4 = F_46 ( & V_117 -> V_131 , V_73 ) ;
V_5 = V_78 ;
break;
case V_134 :
default:
if ( V_117 -> V_131 . V_5 == V_78 )
V_5 = V_78 ;
else
V_5 = V_132 ;
if ( V_117 -> V_135 == V_136 )
* V_4 = V_30 -> V_137 [ V_71 ] ;
else
* V_4 = F_46 (
F_48 ( V_60 , V_127 ,
V_130 ) ,
V_71 ) ;
break;
}
F_1 ( & V_117 -> V_131 , * V_4 , V_5 ) ;
}
static void F_49 ( struct V_29 * V_30 ,
struct V_126 * V_127 ,
struct V_128 * V_117 ,
const struct V_3 * * V_4 )
{
T_1 V_5 ;
if ( V_117 -> V_129 == V_138 ) {
* V_4 = F_46 ( & V_117 -> V_131 , V_71 ) ;
V_5 = V_132 ;
} else {
* V_4 = F_46 ( & V_117 -> V_131 , V_73 ) ;
V_5 = V_78 ;
}
F_1 ( & V_117 -> V_131 , * V_4 , V_5 ) ;
}
static int F_50 ( struct V_59 * V_60 ,
struct V_139 * V_140 )
{
struct V_29 * V_30 = F_32 ( V_60 ) ;
if ( V_140 -> V_129 != V_134 )
return - V_66 ;
F_33 ( & V_30 -> V_95 ) ;
V_140 -> V_141 = V_30 -> V_83 -> V_141 ;
F_34 ( & V_30 -> V_95 ) ;
return 0 ;
}
static int F_51 ( struct V_29 * V_30 ,
struct V_139 * V_140 )
{
const struct V_3 * V_69 =
V_30 -> V_70 [ V_71 ] ;
const struct V_142 * V_83 = & V_143 [ 0 ] ;
unsigned int V_17 , V_144 = V_145 ;
unsigned int V_99 , V_146 ;
if ( V_140 -> V_141 . V_147 == 0 )
return - V_66 ;
V_146 = V_140 -> V_141 . V_148 * 1000 / V_140 -> V_141 . V_147 ;
for ( V_99 = 0 ; V_99 < F_41 ( V_143 ) ; V_99 ++ ) {
const struct V_142 * V_149 = & V_143 [ V_99 ] ;
if ( V_69 -> V_6 > V_149 -> V_67 . V_6 ||
V_69 -> V_7 > V_149 -> V_67 . V_7 )
continue;
V_17 = abs ( V_149 -> V_141 . V_148 / 1000 - V_146 ) ;
if ( V_17 < V_144 ) {
V_83 = V_149 ;
V_144 = V_17 ;
}
}
V_30 -> V_83 = V_83 ;
F_8 ( 1 , V_18 , & V_30 -> V_45 ,
L_28 , V_83 -> V_141 . V_148 ) ;
return 0 ;
}
static int F_52 ( struct V_59 * V_60 ,
struct V_139 * V_140 )
{
struct V_29 * V_30 = F_32 ( V_60 ) ;
int V_17 ;
if ( V_140 -> V_129 != V_134 )
return - V_66 ;
F_8 ( 1 , V_18 , V_60 , L_29 ,
V_140 -> V_141 . V_148 , V_140 -> V_141 . V_147 ) ;
F_33 ( & V_30 -> V_95 ) ;
V_17 = F_51 ( V_30 , V_140 ) ;
if ( ! V_17 ) {
if ( V_30 -> V_94 )
V_17 = F_28 ( V_30 ) ;
else
V_30 -> V_86 = 1 ;
}
F_34 ( & V_30 -> V_95 ) ;
return V_17 ;
}
static int F_53 ( struct V_59 * V_60 ,
struct V_126 * V_127 ,
struct V_150 * V_151 )
{
struct V_29 * V_30 = F_32 ( V_60 ) ;
const struct V_142 * V_140 ;
int V_17 = 0 ;
if ( V_151 -> V_129 != V_134 )
return - V_66 ;
if ( V_151 -> V_152 >= F_41 ( V_143 ) )
return - V_66 ;
F_33 ( & V_30 -> V_95 ) ;
V_140 = & V_143 [ V_151 -> V_152 ] ;
if ( V_151 -> V_6 > V_140 -> V_67 . V_6 || V_151 -> V_7 > V_140 -> V_67 . V_7 )
V_17 = - V_66 ;
else
V_151 -> V_141 = V_140 -> V_141 ;
F_34 ( & V_30 -> V_95 ) ;
return V_17 ;
}
static int F_54 ( int V_129 , int V_152 )
{
if ( V_129 == V_134 ) {
if ( V_152 > 1 )
return - V_66 ;
return ( V_152 == 0 ) ? V_132 : V_78 ;
}
if ( V_152 > 0 )
return - V_66 ;
return ( V_129 == V_130 ) ? V_132 : V_78 ;
}
static int F_55 ( struct V_59 * V_60 ,
struct V_126 * V_127 ,
struct V_128 * V_117 )
{
struct V_29 * V_30 = F_23 ( V_60 ) ;
const struct V_3 * V_4 ;
T_1 V_5 ;
if ( V_117 -> V_135 == V_153 ) {
V_117 -> V_131 = * F_48 ( V_60 , V_127 , V_117 -> V_129 ) ;
return 0 ;
}
F_33 ( & V_30 -> V_95 ) ;
switch ( V_117 -> V_129 ) {
case V_138 :
V_5 = V_132 ;
V_4 = V_30 -> V_70 [ V_71 ] ;
break;
case V_154 :
V_5 = V_78 ;
V_4 = V_30 -> V_70 [ V_73 ] ;
break;
default:
F_34 ( & V_30 -> V_95 ) ;
return - V_66 ;
}
F_1 ( & V_117 -> V_131 , V_4 , V_5 ) ;
F_34 ( & V_30 -> V_95 ) ;
return 0 ;
}
static int F_56 ( struct V_59 * V_60 ,
struct V_126 * V_127 ,
struct V_128 * V_117 )
{
struct V_29 * V_30 = F_32 ( V_60 ) ;
const struct V_3 * V_4 ;
T_1 V_5 ;
if ( V_117 -> V_135 == V_153 ) {
V_117 -> V_131 = * F_48 ( V_60 , V_127 , V_117 -> V_129 ) ;
return 0 ;
}
F_33 ( & V_30 -> V_95 ) ;
switch ( V_117 -> V_129 ) {
case V_130 :
V_5 = V_132 ;
V_4 = V_30 -> V_137 [ V_71 ] ;
break;
case V_133 :
V_5 = V_78 ;
V_4 = V_30 -> V_137 [ V_73 ] ;
break;
case V_134 :
V_5 = V_30 -> V_77 ;
V_4 = V_30 -> V_137 [ V_71 ] ;
break;
default:
F_34 ( & V_30 -> V_95 ) ;
return - V_66 ;
}
F_1 ( & V_117 -> V_131 , V_4 , V_5 ) ;
F_34 ( & V_30 -> V_95 ) ;
return 0 ;
}
static int F_57 ( struct V_59 * V_60 ,
struct V_126 * V_127 ,
struct V_128 * V_117 )
{
const struct V_3 * V_155 = NULL ;
struct V_29 * V_30 = F_23 ( V_60 ) ;
struct V_1 * V_2 ;
int V_17 = 0 ;
F_33 ( & V_30 -> V_95 ) ;
F_49 ( V_30 , V_127 , V_117 , & V_155 ) ;
if ( V_117 -> V_135 == V_153 ) {
V_2 = F_48 ( V_60 , V_127 , V_117 -> V_129 ) ;
* V_2 = V_117 -> V_131 ;
} else {
switch ( V_117 -> V_129 ) {
case V_138 :
V_30 -> V_70 [ V_71 ] = V_155 ;
break;
case V_154 :
V_30 -> V_70 [ V_73 ] = V_155 ;
break;
default:
V_17 = - V_156 ;
}
if ( V_30 -> V_94 )
V_17 = - V_156 ;
else
V_30 -> V_89 = 1 ;
}
F_34 ( & V_30 -> V_95 ) ;
return V_17 ;
}
static int F_58 ( struct V_59 * V_60 ,
struct V_126 * V_127 ,
struct V_128 * V_117 )
{
const struct V_3 * V_155 = NULL ;
struct V_29 * V_30 = F_32 ( V_60 ) ;
struct V_1 * V_2 ;
int V_17 = 0 ;
F_33 ( & V_30 -> V_95 ) ;
F_47 ( V_30 , V_127 , V_117 , & V_155 ) ;
if ( V_117 -> V_135 == V_153 ) {
V_2 = F_48 ( V_60 , V_127 , V_117 -> V_129 ) ;
* V_2 = V_117 -> V_131 ;
if ( V_117 -> V_129 == V_130 ) {
V_2 = F_48 ( V_60 , V_127 , V_134 ) ;
V_2 -> V_6 = V_117 -> V_131 . V_6 ;
V_2 -> V_7 = V_117 -> V_131 . V_7 ;
}
} else {
switch ( V_117 -> V_129 ) {
case V_130 :
V_30 -> V_137 [ V_71 ] = V_155 ;
break;
case V_133 :
V_30 -> V_137 [ V_73 ] = V_155 ;
break;
case V_134 :
V_30 -> V_77 = V_117 -> V_131 . V_5 ;
break;
default:
V_17 = - V_156 ;
}
if ( V_30 -> V_94 )
V_17 = - V_156 ;
else
V_30 -> V_89 = 1 ;
}
F_34 ( & V_30 -> V_95 ) ;
return V_17 ;
}
static int F_59 ( struct V_59 * V_60 , unsigned int V_129 ,
struct V_157 * V_158 )
{
struct V_29 * V_30 = F_32 ( V_60 ) ;
int V_99 ;
if ( V_129 != V_134 || V_158 == NULL )
return - V_66 ;
F_33 ( & V_30 -> V_95 ) ;
V_158 -> V_159 = 2 ;
for ( V_99 = 0 ; V_99 < V_158 -> V_159 ; V_99 ++ )
V_158 -> V_160 [ V_99 ] = V_30 -> V_161 . V_160 [ V_99 ] ;
F_34 ( & V_30 -> V_95 ) ;
return 0 ;
}
static int F_60 ( struct V_59 * V_60 , unsigned int V_129 ,
struct V_157 * V_158 )
{
struct V_29 * V_30 = F_32 ( V_60 ) ;
struct V_157 * V_161 = & V_30 -> V_161 ;
int V_99 ;
if ( V_129 != V_134 || V_158 == NULL )
return - V_66 ;
V_158 -> V_160 [ 0 ] . V_162 = 10 * V_163 ;
V_158 -> V_160 [ 1 ] . V_162 = F_61 ( T_1 , V_158 -> V_160 [ 1 ] . V_162 ,
V_164 ) ;
V_158 -> V_159 = 2 ;
F_33 ( & V_30 -> V_95 ) ;
for ( V_99 = 0 ; V_99 < V_158 -> V_159 ; V_99 ++ )
V_161 -> V_160 [ V_99 ] = V_158 -> V_160 [ V_99 ] ;
F_34 ( & V_30 -> V_95 ) ;
return 0 ;
}
static int F_62 ( struct V_59 * V_60 ,
struct V_126 * V_127 ,
struct V_165 * V_5 )
{
static const int V_166 [] = {
[ V_138 ] = V_132 ,
[ V_154 ] = V_78 } ;
if ( V_5 -> V_152 > 0 || V_5 -> V_129 >= V_167 )
return - V_66 ;
V_5 -> V_5 = V_166 [ V_5 -> V_129 ] ;
return 0 ;
}
static int F_63 ( struct V_59 * V_60 ,
struct V_126 * V_127 ,
struct V_165 * V_5 )
{
int V_17 ;
V_17 = F_54 ( V_5 -> V_129 , V_5 -> V_152 ) ;
if ( V_17 < 0 )
return V_17 ;
V_5 -> V_5 = V_17 ;
return 0 ;
}
static int F_64 ( struct V_59 * V_60 ,
struct V_126 * V_127 ,
struct V_168 * V_169 )
{
int V_119 ;
if ( V_169 -> V_129 == V_138 ) {
if ( V_169 -> V_5 != V_132 )
return - V_66 ;
V_119 = V_71 ;
} else{
if ( V_169 -> V_5 != V_78 )
return - V_66 ;
V_119 = V_73 ;
}
if ( V_169 -> V_152 >= V_124 [ V_119 ] )
return - V_66 ;
V_169 -> V_170 = V_123 [ V_119 ] [ V_169 -> V_152 ] . V_6 ;
V_169 -> V_171 = V_169 -> V_170 ;
V_169 -> V_172 = V_123 [ V_119 ] [ V_169 -> V_152 ] . V_7 ;
V_169 -> V_173 = V_169 -> V_172 ;
return 0 ;
}
static int F_65 ( struct V_59 * V_60 ,
struct V_126 * V_127 ,
struct V_168 * V_169 )
{
struct V_29 * V_30 = F_32 ( V_60 ) ;
int V_119 ;
if ( V_169 -> V_129 == V_134 ) {
if ( V_169 -> V_152 > 0 )
return - V_66 ;
switch ( V_169 -> V_5 ) {
case V_78 :
case V_132 : {
unsigned V_174 , V_175 ;
if ( V_169 -> V_135 == V_153 ) {
struct V_1 * V_2 ;
V_2 = F_48 ( V_60 , V_127 ,
V_130 ) ;
V_174 = V_2 -> V_6 ;
V_175 = V_2 -> V_7 ;
} else {
const struct V_3 * V_4 ;
V_4 = V_30 -> V_137 [ V_71 ] ;
V_174 = V_4 -> V_6 ;
V_175 = V_4 -> V_7 ;
}
V_169 -> V_171 = V_169 -> V_170 = V_174 ;
V_169 -> V_172 = V_169 -> V_173 = V_175 ;
return 0 ;
}
default:
return - V_66 ;
}
}
if ( V_169 -> V_5 != F_54 ( V_169 -> V_129 , 0 ) )
return - V_66 ;
if ( V_169 -> V_129 == V_133 )
V_119 = V_73 ;
else
V_119 = V_71 ;
if ( V_169 -> V_152 >= V_124 [ V_119 ] )
return - V_66 ;
V_169 -> V_170 = V_123 [ V_119 ] [ V_169 -> V_152 ] . V_6 ;
V_169 -> V_171 = V_169 -> V_170 ;
V_169 -> V_172 = V_123 [ V_119 ] [ V_169 -> V_152 ] . V_7 ;
V_169 -> V_173 = V_169 -> V_172 ;
return 0 ;
}
static int F_66 ( struct V_59 * V_60 )
{
struct V_29 * V_30 = F_32 ( V_60 ) ;
F_67 ( V_60 -> V_176 , V_60 -> V_177 ) ;
F_20 ( V_60 , L_30 , V_30 -> V_178 ,
V_30 -> V_89 ) ;
return 0 ;
}
static int F_68 ( struct V_59 * V_60 , struct V_179 * V_180 )
{
struct V_1 * V_2 ;
V_2 = F_48 ( V_60 , V_180 -> V_129 , V_138 ) ;
F_1 ( V_2 , & V_181 [ 1 ] ,
V_132 ) ;
V_2 = F_48 ( V_60 , V_180 -> V_129 , V_154 ) ;
F_1 ( V_2 , & V_182 [ 1 ] ,
V_78 ) ;
return 0 ;
}
static int F_69 ( struct V_59 * V_60 , struct V_179 * V_180 )
{
struct V_1 * V_2 ;
V_2 = F_48 ( V_60 , V_180 -> V_129 , V_130 ) ;
F_1 ( V_2 , & V_181 [ 1 ] ,
V_132 ) ;
V_2 = F_48 ( V_60 , V_180 -> V_129 , V_133 ) ;
F_1 ( V_2 , & V_182 [ 1 ] ,
V_78 ) ;
V_2 = F_48 ( V_60 , V_180 -> V_129 , V_134 ) ;
F_1 ( V_2 , & V_181 [ 1 ] ,
V_132 ) ;
return 0 ;
}
static int F_70 ( struct V_29 * V_183 , int V_184 , T_1 V_82 )
{
if ( ! F_71 ( V_183 -> V_185 [ V_184 ] . V_185 ) )
return 0 ;
F_72 ( V_183 -> V_185 [ V_184 ] . V_185 , ! ! V_82 ) ;
return 1 ;
}
static int F_73 ( struct V_29 * V_183 , int V_184 )
{
return F_70 ( V_183 , V_184 , V_183 -> V_185 [ V_184 ] . V_186 ) ;
}
static int F_74 ( struct V_29 * V_183 , int V_184 )
{
return F_70 ( V_183 , V_184 , ! V_183 -> V_185 [ V_184 ] . V_186 ) ;
}
static int F_75 ( struct V_29 * V_30 )
{
int V_99 , V_17 ;
for ( V_99 = 0 ; V_99 < V_187 ; V_99 ++ ) {
V_17 = F_76 ( V_30 -> V_188 [ V_99 ] . V_189 ) ;
if ( V_17 )
goto V_190;
}
V_17 = F_77 ( V_30 -> clock , V_30 -> V_191 ) ;
if ( V_17 < 0 )
goto V_190;
V_17 = F_78 ( V_30 -> clock ) ;
if ( V_17 < 0 )
goto V_190;
F_8 ( 1 , V_18 , & V_30 -> V_192 , L_31 ,
F_79 ( V_30 -> clock ) ) ;
F_74 ( V_30 , V_193 ) ;
F_15 ( 100 , 200 ) ;
F_74 ( V_30 , V_194 ) ;
F_15 ( 50 , 100 ) ;
return 0 ;
V_190:
for ( -- V_99 ; V_99 >= 0 ; V_99 -- )
F_80 ( V_30 -> V_188 [ V_99 ] . V_189 ) ;
return V_17 ;
}
static int F_81 ( struct V_29 * V_30 )
{
int V_99 , V_17 ;
if ( F_73 ( V_30 , V_194 ) )
F_15 ( 10 , 50 ) ;
if ( F_73 ( V_30 , V_193 ) )
F_15 ( 100 , 200 ) ;
F_82 ( V_30 -> clock ) ;
V_30 -> V_94 = 0 ;
V_30 -> V_68 = 0 ;
for ( V_99 = V_187 - 1 ; V_99 >= 0 ; V_99 -- ) {
V_17 = F_80 ( V_30 -> V_188 [ V_99 ] . V_189 ) ;
if ( V_17 )
goto V_195;
}
return 0 ;
V_195:
for ( ++ V_99 ; V_99 < V_187 ; V_99 ++ ) {
int V_196 = F_76 ( V_30 -> V_188 [ V_99 ] . V_189 ) ;
if ( V_196 < 0 )
F_9 ( & V_30 -> V_192 , L_32 ,
V_30 -> V_188 [ V_99 ] . V_197 , V_196 ) ;
}
F_78 ( V_30 -> clock ) ;
return V_17 ;
}
static int F_83 ( struct V_59 * V_60 , int V_87 )
{
struct V_29 * V_30 = F_32 ( V_60 ) ;
int V_17 = 0 ;
F_33 ( & V_30 -> V_95 ) ;
if ( V_87 && ! V_30 -> V_178 ) {
V_17 = F_75 ( V_30 ) ;
if ( ! V_17 )
V_17 = F_45 ( V_30 ) ;
if ( ! V_17 ) {
V_30 -> V_86 = 1 ;
V_30 -> V_89 = 1 ;
}
} else if ( ! V_87 == V_30 -> V_178 ) {
V_17 = F_19 ( V_30 ) ;
if ( ! V_17 )
V_17 = F_81 ( V_30 ) ;
else
F_9 ( V_60 , L_33 ) ;
}
if ( ! V_17 )
V_30 -> V_178 += V_87 ? 1 : - 1 ;
F_8 ( 1 , V_18 , V_60 , L_34 ,
V_19 , V_30 -> V_178 ) ;
F_34 ( & V_30 -> V_95 ) ;
return V_17 ;
}
static int F_84 ( struct V_59 * V_60 )
{
struct V_29 * V_30 = F_32 ( V_60 ) ;
int V_17 ;
V_17 = F_85 ( V_60 -> V_198 , & V_30 -> V_45 ) ;
if ( V_17 ) {
F_9 ( V_60 -> V_198 , L_35 ,
V_30 -> V_192 . V_177 ) ;
return V_17 ;
}
V_17 = F_86 ( & V_30 -> V_45 . V_199 ,
V_138 , & V_30 -> V_192 . V_199 , V_130 ,
V_200 | V_201 ) ;
V_17 = F_86 ( & V_30 -> V_45 . V_199 ,
V_154 , & V_30 -> V_192 . V_199 , V_133 ,
V_200 | V_201 ) ;
return V_17 ;
}
static void F_87 ( struct V_59 * V_60 )
{
struct V_29 * V_30 = F_32 ( V_60 ) ;
F_88 ( & V_30 -> V_45 ) ;
}
static int F_89 ( struct V_29 * V_30 )
{
static const char * const V_202 [] = {
L_36 , L_37
} ;
struct V_12 * V_203 = V_30 -> V_12 ;
struct V_204 * V_205 = V_30 -> V_185 ;
int V_17 , V_99 ;
for ( V_99 = 0 ; V_99 < V_206 ; ++ V_99 ) {
unsigned int V_25 = V_207 ;
if ( V_205 [ V_99 ] . V_186 )
V_25 |= V_208 ;
V_17 = F_90 ( & V_203 -> V_65 , V_205 [ V_99 ] . V_185 , V_25 ,
V_202 [ V_99 ] ) ;
if ( V_17 ) {
F_9 ( V_203 , L_38 ,
V_202 [ V_99 ] ) ;
return V_17 ;
}
}
return 0 ;
}
static int F_91 ( struct V_29 * V_30 )
{
static const char * const V_209 [] = {
L_39 , L_40 ,
} ;
struct V_210 * V_65 = & V_30 -> V_12 -> V_65 ;
struct V_211 * V_212 = V_65 -> V_213 ;
int V_17 , V_99 ;
for ( V_99 = 0 ; V_99 < V_206 ; ++ V_99 ) {
enum V_214 V_215 ;
V_17 = F_92 ( V_212 , V_209 [ V_99 ] ,
0 , & V_215 ) ;
if ( V_17 < 0 ) {
F_93 ( V_65 , L_41 ,
V_209 [ V_99 ] ) ;
return - V_66 ;
}
V_30 -> V_185 [ V_99 ] . V_185 = V_17 ;
V_30 -> V_185 [ V_99 ] . V_186 = ! ( V_215 & V_216 ) ;
}
return 0 ;
}
static int F_94 ( struct V_29 * V_30 )
{
struct V_210 * V_65 = & V_30 -> V_12 -> V_65 ;
const struct V_217 * V_218 = V_65 -> V_219 ;
struct V_211 * V_212 = V_65 -> V_213 ;
struct V_211 * V_220 ;
struct V_221 V_222 ;
int V_17 ;
if ( ! V_212 ) {
if ( ! V_218 ) {
F_93 ( V_65 , L_42 ) ;
return - V_66 ;
}
V_30 -> V_191 = V_218 -> V_191 ;
V_30 -> V_185 [ V_193 ] = V_218 -> V_223 ;
V_30 -> V_185 [ V_194 ] = V_218 -> V_224 ;
return 0 ;
}
V_30 -> clock = F_95 ( V_65 , V_225 ) ;
if ( F_96 ( V_30 -> clock ) )
return F_97 ( V_30 -> clock ) ;
if ( F_98 ( V_212 , L_43 ,
& V_30 -> V_191 ) ) {
V_30 -> V_191 = V_226 ;
F_99 ( V_65 , L_44 ,
V_30 -> V_191 ) ;
}
V_17 = F_91 ( V_30 ) ;
if ( V_17 < 0 )
return - V_66 ;
V_220 = F_100 ( V_212 , NULL ) ;
if ( ! V_220 ) {
F_101 ( V_65 , L_45 ,
V_212 -> V_227 ) ;
return 0 ;
}
F_102 ( V_220 , & V_222 ) ;
F_103 ( V_220 ) ;
if ( V_222 . V_228 != V_229 ) {
F_93 ( V_65 , L_46 ) ;
return - V_66 ;
}
if ( V_222 . V_230 . V_231 . V_232 != V_233 )
F_99 ( V_65 , L_47 ) ;
return 0 ;
}
static int F_104 ( struct V_12 * V_13 ,
const struct V_234 * V_184 )
{
struct V_210 * V_65 = & V_13 -> V_65 ;
struct V_59 * V_60 ;
struct V_59 * V_192 ;
struct V_29 * V_30 ;
int V_17 , V_99 ;
V_30 = F_105 ( V_65 , sizeof( * V_30 ) , V_235 ) ;
if ( ! V_30 )
return - V_236 ;
V_30 -> V_12 = V_13 ;
V_17 = F_94 ( V_30 ) ;
if ( V_17 < 0 )
return V_17 ;
F_106 ( & V_30 -> V_95 ) ;
V_60 = & V_30 -> V_45 ;
V_192 = & V_30 -> V_192 ;
F_107 ( V_60 , & V_237 ) ;
V_60 -> V_238 = V_13 -> V_65 . V_239 -> V_238 ;
F_108 ( V_60 , V_30 ) ;
F_109 ( V_60 -> V_177 , L_48 , sizeof( V_60 -> V_177 ) ) ;
V_60 -> V_240 = & V_241 ;
V_60 -> V_25 |= V_242 ;
V_30 -> V_243 [ V_154 ] . V_25 = V_244 ;
V_30 -> V_243 [ V_138 ] . V_25 = V_244 ;
V_60 -> V_199 . type = V_245 ;
V_17 = F_110 ( & V_60 -> V_199 , V_167 ,
V_30 -> V_243 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
F_111 ( V_192 , V_13 , & V_246 ) ;
strcpy ( V_192 -> V_177 , L_49 ) ;
V_192 -> V_240 = & V_247 ;
V_192 -> V_25 |= V_242 ;
V_30 -> V_248 [ V_130 ] . V_25 = V_249 ;
V_30 -> V_248 [ V_133 ] . V_25 = V_249 ;
V_30 -> V_248 [ V_134 ] . V_25 = V_244 ;
V_192 -> V_199 . type = V_245 ;
V_17 = F_110 ( & V_192 -> V_199 , V_250 ,
V_30 -> V_248 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_89 ( V_30 ) ;
if ( V_17 )
goto V_251;
for ( V_99 = 0 ; V_99 < V_187 ; V_99 ++ )
V_30 -> V_188 [ V_99 ] . V_197 = V_252 [ V_99 ] ;
V_17 = F_112 ( V_65 , V_187 ,
V_30 -> V_188 ) ;
if ( V_17 ) {
F_93 ( V_65 , L_50 ) ;
goto V_251;
}
V_17 = F_113 ( V_30 ) ;
if ( V_17 )
goto V_251;
V_30 -> V_70 [ V_71 ] = & V_181 [ 1 ] ;
V_30 -> V_70 [ V_73 ] = & V_182 [ 1 ] ;
V_30 -> V_137 [ V_71 ] = V_30 -> V_70 [ V_71 ] ;
V_30 -> V_137 [ V_73 ] = V_30 -> V_70 [ V_73 ] ;
V_30 -> V_77 = V_132 ;
V_30 -> V_83 = & V_143 [ V_253 ] ;
V_30 -> V_64 [ 0 ] = 'G' ;
V_30 -> V_64 [ 1 ] = 'C' ;
V_17 = F_114 ( V_30 ) ;
if ( V_17 < 0 )
goto V_251;
V_192 -> V_65 = V_65 ;
V_17 = F_75 ( V_30 ) ;
if ( V_17 < 0 )
goto V_254;
V_17 = F_43 ( V_30 ) ;
F_81 ( V_30 ) ;
if ( V_17 < 0 ) {
F_93 ( V_65 , L_51 , V_17 ) ;
goto V_254;
}
V_17 = F_115 ( V_192 ) ;
if ( V_17 < 0 )
goto V_254;
F_20 ( V_60 , L_52 , V_19 ) ;
return 0 ;
V_254:
F_116 ( V_30 ) ;
V_251:
F_117 ( & V_60 -> V_199 ) ;
return V_17 ;
}
static int F_118 ( struct V_12 * V_13 )
{
struct V_59 * V_192 = F_119 ( V_13 ) ;
struct V_29 * V_30 = F_32 ( V_192 ) ;
struct V_59 * V_45 = & V_30 -> V_45 ;
F_120 ( V_192 ) ;
F_121 ( V_192 -> V_176 ) ;
F_117 ( & V_192 -> V_199 ) ;
F_88 ( V_45 ) ;
F_117 ( & V_45 -> V_199 ) ;
F_116 ( V_30 ) ;
return 0 ;
}
