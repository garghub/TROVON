static T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_6 , V_7 , V_8 ;
int V_9 , V_10 , V_11 , V_12 , V_13 , V_14 ;
V_13 = F_2 ( V_2 -> V_15 , V_16 , & V_6 ) ;
if ( V_13 < 0 ) {
F_3 ( V_5 , L_1 ) ;
return V_13 ;
}
V_13 = F_4 ( V_2 -> V_15 , V_17 , & V_8 , 2 ) ;
if ( V_13 < 0 ) {
F_3 ( V_5 , L_2 ) ;
return V_13 ;
}
V_9 = F_5 ( F_6 ( V_8 ) , 15 ) ;
V_13 = F_2 ( V_2 -> V_15 , V_18 , & V_7 ) ;
if ( V_13 < 0 ) {
F_3 ( V_5 , L_3 ) ;
return V_13 ;
}
V_13 = F_4 ( V_2 -> V_15 , V_19 , & V_8 , 2 ) ;
if ( V_13 < 0 ) {
F_3 ( V_5 , L_4 ) ;
return V_13 ;
}
V_10 = F_5 ( ( ( F_7 ( V_8 ) >> 4 ) & 0xff0 ) |
( F_7 ( V_8 ) & 0xf ) , 11 ) ;
V_13 = F_4 ( V_2 -> V_15 , V_20 , & V_8 , 2 ) ;
if ( V_13 < 0 ) {
F_3 ( V_5 , L_5 ) ;
return V_13 ;
}
V_11 = F_5 ( ( ( F_6 ( V_8 ) >> 4 ) & 0xfff ) , 11 ) ;
V_13 = F_2 ( V_2 -> V_15 , V_21 , & V_8 ) ;
if ( V_13 < 0 ) {
F_3 ( V_5 , L_6 ) ;
return V_13 ;
}
V_12 = F_5 ( V_8 , 7 ) ;
V_14 = ( ( T_2 ) V_2 -> V_22 ) - ( T_2 ) 76800 ;
V_14 = ( ( ( ( V_3 << 14 ) - ( V_10 << 20 ) - ( V_11 * V_14 ) )
+ ( T_2 ) 16384 ) >> 15 ) * ( ( ( ( ( ( ( V_14 * V_12 ) >> 10 )
* ( ( ( V_14 * ( T_2 ) V_7 ) >> 11 ) + ( T_2 ) 32768 ) ) >> 10 )
+ ( T_2 ) 2097152 ) * V_9 + 8192 ) >> 14 ) ;
V_14 -= ( ( ( ( V_14 >> 15 ) * ( V_14 >> 15 ) ) >> 7 ) * ( T_2 ) V_6 ) >> 4 ;
return V_14 >> 12 ;
}
static T_2 F_8 ( struct V_1 * V_2 ,
T_2 V_23 )
{
int V_13 ;
T_2 V_24 , V_25 ;
T_3 V_26 [ V_27 / 2 ] ;
V_13 = F_4 ( V_2 -> V_15 , V_28 ,
V_26 , V_27 ) ;
if ( V_13 < 0 ) {
F_3 ( V_2 -> V_5 ,
L_7 ) ;
return V_13 ;
}
V_24 = ( ( ( V_23 >> 3 ) - ( ( T_2 ) F_6 ( V_26 [ V_29 ] ) << 1 ) ) *
( ( T_2 ) ( V_30 ) F_6 ( V_26 [ V_31 ] ) ) ) >> 11 ;
V_25 = ( ( ( ( ( V_23 >> 4 ) - ( ( T_2 ) F_6 ( V_26 [ V_29 ] ) ) ) *
( ( V_23 >> 4 ) - ( ( T_2 ) F_6 ( V_26 [ V_29 ] ) ) ) ) >> 12 ) *
( ( T_2 ) ( V_30 ) F_6 ( V_26 [ V_32 ] ) ) ) >> 14 ;
V_2 -> V_22 = V_24 + V_25 ;
return ( V_2 -> V_22 * 5 + 128 ) >> 8 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
T_2 V_33 )
{
int V_13 ;
T_4 V_24 , V_25 , V_34 ;
T_3 V_26 [ V_35 / 2 ] ;
V_13 = F_4 ( V_2 -> V_15 , V_36 ,
V_26 , V_35 ) ;
if ( V_13 < 0 ) {
F_3 ( V_2 -> V_5 ,
L_8 ) ;
return V_13 ;
}
V_24 = ( ( T_4 ) V_2 -> V_22 ) - 128000 ;
V_25 = V_24 * V_24 * ( T_4 ) ( V_30 ) F_6 ( V_26 [ V_37 ] ) ;
V_25 += ( V_24 * ( T_4 ) ( V_30 ) F_6 ( V_26 [ V_38 ] ) ) << 17 ;
V_25 += ( ( T_4 ) ( V_30 ) F_6 ( V_26 [ V_39 ] ) ) << 35 ;
V_24 = ( ( V_24 * V_24 * ( T_4 ) ( V_30 ) F_6 ( V_26 [ V_40 ] ) ) >> 8 ) +
( ( V_24 * ( T_4 ) ( V_30 ) F_6 ( V_26 [ V_41 ] ) ) << 12 ) ;
V_24 = ( ( ( ( T_4 ) 1 ) << 47 ) + V_24 ) * ( ( T_4 ) F_6 ( V_26 [ V_42 ] ) ) >> 33 ;
if ( V_24 == 0 )
return 0 ;
V_34 = ( ( ( ( T_4 ) 1048576 - V_33 ) << 31 ) - V_25 ) * 3125 ;
V_34 = F_10 ( V_34 , V_24 ) ;
V_24 = ( ( ( T_4 ) ( V_30 ) F_6 ( V_26 [ V_43 ] ) ) * ( V_34 >> 13 ) * ( V_34 >> 13 ) ) >> 25 ;
V_25 = ( ( ( T_4 ) ( V_30 ) F_6 ( V_26 [ V_44 ] ) ) * V_34 ) >> 19 ;
V_34 = ( ( V_34 + V_24 + V_25 ) >> 8 ) + ( ( ( T_4 ) ( V_30 ) F_6 ( V_26 [ V_45 ] ) ) << 4 ) ;
return ( T_1 ) V_34 ;
}
static int F_11 ( struct V_1 * V_2 ,
int * V_46 )
{
int V_13 ;
T_5 V_8 = 0 ;
T_2 V_23 , V_47 ;
V_13 = F_4 ( V_2 -> V_15 , V_48 ,
( V_49 * ) & V_8 , 3 ) ;
if ( V_13 < 0 ) {
F_3 ( V_2 -> V_5 , L_9 ) ;
return V_13 ;
}
V_23 = F_12 ( V_8 ) >> 12 ;
if ( V_23 == V_50 ) {
F_3 ( V_2 -> V_5 , L_10 ) ;
return - V_51 ;
}
V_47 = F_8 ( V_2 , V_23 ) ;
if ( V_46 ) {
* V_46 = V_47 * 10 ;
return V_52 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
int * V_46 , int * V_53 )
{
int V_13 ;
T_5 V_8 = 0 ;
T_2 V_33 ;
T_1 V_54 ;
V_13 = F_11 ( V_2 , NULL ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_4 ( V_2 -> V_15 , V_55 ,
( V_49 * ) & V_8 , 3 ) ;
if ( V_13 < 0 ) {
F_3 ( V_2 -> V_5 , L_11 ) ;
return V_13 ;
}
V_33 = F_12 ( V_8 ) >> 12 ;
if ( V_33 == V_56 ) {
F_3 ( V_2 -> V_5 , L_12 ) ;
return - V_51 ;
}
V_54 = F_9 ( V_2 , V_33 ) ;
* V_46 = V_54 ;
* V_53 = 256000 ;
return V_57 ;
}
static int F_14 ( struct V_1 * V_2 , int * V_46 , int * V_53 )
{
int V_13 ;
T_6 V_8 = 0 ;
T_2 V_3 ;
T_1 V_58 ;
V_13 = F_11 ( V_2 , NULL ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_4 ( V_2 -> V_15 , V_59 ,
( V_49 * ) & V_8 , 2 ) ;
if ( V_13 < 0 ) {
F_3 ( V_2 -> V_5 , L_13 ) ;
return V_13 ;
}
V_3 = F_7 ( V_8 ) ;
if ( V_3 == V_60 ) {
F_3 ( V_2 -> V_5 , L_14 ) ;
return - V_51 ;
}
V_58 = F_1 ( V_2 , V_3 ) ;
* V_46 = V_58 ;
* V_53 = 1024 ;
return V_57 ;
}
static int F_15 ( struct V_61 * V_62 ,
struct V_63 const * V_64 ,
int * V_46 , int * V_53 , long V_65 )
{
int V_13 ;
struct V_1 * V_2 = F_16 ( V_62 ) ;
F_17 ( V_2 -> V_5 ) ;
F_18 ( & V_2 -> V_66 ) ;
switch ( V_65 ) {
case V_67 :
switch ( V_64 -> type ) {
case V_68 :
V_13 = V_2 -> V_69 -> V_70 ( V_2 , V_46 , V_53 ) ;
break;
case V_71 :
V_13 = V_2 -> V_69 -> V_72 ( V_2 , V_46 , V_53 ) ;
break;
case V_73 :
V_13 = V_2 -> V_69 -> V_74 ( V_2 , V_46 ) ;
break;
default:
V_13 = - V_75 ;
break;
}
break;
case V_76 :
switch ( V_64 -> type ) {
case V_68 :
* V_46 = 1 << V_2 -> V_77 ;
V_13 = V_52 ;
break;
case V_71 :
* V_46 = 1 << V_2 -> V_78 ;
V_13 = V_52 ;
break;
case V_73 :
* V_46 = 1 << V_2 -> V_79 ;
V_13 = V_52 ;
break;
default:
V_13 = - V_75 ;
break;
}
break;
default:
V_13 = - V_75 ;
break;
}
F_19 ( & V_2 -> V_66 ) ;
F_20 ( V_2 -> V_5 ) ;
F_21 ( V_2 -> V_5 ) ;
return V_13 ;
}
static int F_22 ( struct V_1 * V_2 ,
int V_46 )
{
int V_80 ;
const int * V_81 = V_2 -> V_69 -> V_82 ;
const int V_83 = V_2 -> V_69 -> V_84 ;
for ( V_80 = 0 ; V_80 < V_83 ; V_80 ++ ) {
if ( V_81 [ V_80 ] == V_46 ) {
V_2 -> V_77 = F_23 ( V_46 ) ;
return V_2 -> V_69 -> V_85 ( V_2 ) ;
}
}
return - V_75 ;
}
static int F_24 ( struct V_1 * V_2 ,
int V_46 )
{
int V_80 ;
const int * V_81 = V_2 -> V_69 -> V_86 ;
const int V_83 = V_2 -> V_69 -> V_87 ;
for ( V_80 = 0 ; V_80 < V_83 ; V_80 ++ ) {
if ( V_81 [ V_80 ] == V_46 ) {
V_2 -> V_79 = F_23 ( V_46 ) ;
return V_2 -> V_69 -> V_85 ( V_2 ) ;
}
}
return - V_75 ;
}
static int F_25 ( struct V_1 * V_2 ,
int V_46 )
{
int V_80 ;
const int * V_81 = V_2 -> V_69 -> V_88 ;
const int V_83 = V_2 -> V_69 -> V_89 ;
for ( V_80 = 0 ; V_80 < V_83 ; V_80 ++ ) {
if ( V_81 [ V_80 ] == V_46 ) {
V_2 -> V_78 = F_23 ( V_46 ) ;
return V_2 -> V_69 -> V_85 ( V_2 ) ;
}
}
return - V_75 ;
}
static int F_26 ( struct V_61 * V_62 ,
struct V_63 const * V_64 ,
int V_46 , int V_53 , long V_65 )
{
int V_13 = 0 ;
struct V_1 * V_2 = F_16 ( V_62 ) ;
switch ( V_65 ) {
case V_76 :
F_17 ( V_2 -> V_5 ) ;
F_18 ( & V_2 -> V_66 ) ;
switch ( V_64 -> type ) {
case V_68 :
V_13 = F_22 ( V_2 , V_46 ) ;
break;
case V_71 :
V_13 = F_25 ( V_2 , V_46 ) ;
break;
case V_73 :
V_13 = F_24 ( V_2 , V_46 ) ;
break;
default:
V_13 = - V_75 ;
break;
}
F_19 ( & V_2 -> V_66 ) ;
F_20 ( V_2 -> V_5 ) ;
F_21 ( V_2 -> V_5 ) ;
break;
default:
return - V_75 ;
}
return V_13 ;
}
static T_7 F_27 ( char * V_26 , const int * V_90 , const int V_83 )
{
T_8 V_91 = 0 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_83 ; V_80 ++ )
V_91 += F_28 ( V_26 + V_91 , V_92 - V_91 , L_15 , V_90 [ V_80 ] ) ;
V_26 [ V_91 - 1 ] = '\n' ;
return V_91 ;
}
static T_7 F_29 ( struct V_4 * V_5 ,
struct V_93 * V_94 , char * V_26 )
{
struct V_1 * V_2 = F_16 ( F_30 ( V_5 ) ) ;
return F_27 ( V_26 , V_2 -> V_69 -> V_86 ,
V_2 -> V_69 -> V_87 ) ;
}
static T_7 F_31 ( struct V_4 * V_5 ,
struct V_93 * V_94 , char * V_26 )
{
struct V_1 * V_2 = F_16 ( F_30 ( V_5 ) ) ;
return F_27 ( V_26 , V_2 -> V_69 -> V_88 ,
V_2 -> V_69 -> V_89 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_13 ;
V_49 V_95 = F_33 ( V_2 -> V_79 + 1 ) |
F_34 ( V_2 -> V_78 + 1 ) ;
V_13 = F_35 ( V_2 -> V_15 , V_96 ,
V_97 |
V_98 |
V_99 ,
V_95 | V_100 ) ;
if ( V_13 < 0 ) {
F_3 ( V_2 -> V_5 ,
L_16 ) ;
return V_13 ;
}
V_13 = F_35 ( V_2 -> V_15 , V_101 ,
V_102 ,
V_103 ) ;
if ( V_13 < 0 ) {
F_3 ( V_2 -> V_5 ,
L_17 ) ;
return V_13 ;
}
return V_13 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_13 ;
V_49 V_95 = F_37 ( V_2 -> V_77 + 1 ) ;
V_13 = F_35 ( V_2 -> V_15 , V_104 ,
V_105 , V_95 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_32 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 , V_49 V_106 )
{
int V_13 ;
const int V_107 [] = { 4500 , 7500 , 13500 , 25500 } ;
unsigned int V_108 ;
unsigned int V_109 ;
if ( V_2 -> V_110 )
F_39 ( & V_2 -> V_111 ) ;
V_13 = F_40 ( V_2 -> V_15 , V_96 , V_106 ) ;
if ( V_13 )
return V_13 ;
if ( V_2 -> V_110 ) {
V_13 = F_41 ( & V_2 -> V_111 ,
1 + F_42 ( 100 ) ) ;
if ( ! V_13 )
F_3 ( V_2 -> V_5 , L_18 ) ;
} else {
if ( V_106 == V_112 )
V_108 = 4500 ;
else
V_108 =
V_107 [ V_2 -> V_78 ] ;
F_43 ( V_108 , V_108 + 1000 ) ;
}
V_13 = F_2 ( V_2 -> V_15 , V_96 , & V_109 ) ;
if ( V_13 )
return V_13 ;
if ( V_109 & V_113 )
return - V_51 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , int * V_46 )
{
int V_13 ;
T_6 V_8 = 0 ;
V_13 = F_38 ( V_2 , V_112 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_4 ( V_2 -> V_15 , V_114 , ( V_49 * ) & V_8 , 2 ) ;
if ( V_13 )
return V_13 ;
* V_46 = F_7 ( V_8 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_115 * V_116 )
{
int V_13 ;
int V_80 ;
T_6 V_26 [ V_117 / 2 ] ;
V_13 = F_4 ( V_2 -> V_15 , V_118 , V_26 ,
sizeof( V_26 ) ) ;
if ( V_13 < 0 )
return V_13 ;
for ( V_80 = 0 ; V_80 < F_46 ( V_26 ) ; V_80 ++ ) {
if ( V_26 [ V_80 ] == F_47 ( 0 ) || V_26 [ V_80 ] == F_47 ( 0xffff ) )
return - V_51 ;
}
F_48 ( V_26 , sizeof( V_26 ) ) ;
V_116 -> V_119 = F_7 ( V_26 [ V_119 ] ) ;
V_116 -> V_120 = F_7 ( V_26 [ V_120 ] ) ;
V_116 -> V_121 = F_7 ( V_26 [ V_121 ] ) ;
V_116 -> V_122 = F_7 ( V_26 [ V_122 ] ) ;
V_116 -> V_123 = F_7 ( V_26 [ V_123 ] ) ;
V_116 -> V_124 = F_7 ( V_26 [ V_124 ] ) ;
V_116 -> V_125 = F_7 ( V_26 [ V_125 ] ) ;
V_116 -> V_126 = F_7 ( V_26 [ V_126 ] ) ;
V_116 -> V_127 = F_7 ( V_26 [ V_127 ] ) ;
V_116 -> V_128 = F_7 ( V_26 [ V_128 ] ) ;
V_116 -> V_129 = F_7 ( V_26 [ V_129 ] ) ;
return 0 ;
}
static T_2 F_49 ( struct V_1 * V_2 , T_2 V_23 )
{
T_2 V_130 , V_131 ;
struct V_115 * V_116 = & V_2 -> V_116 ;
V_130 = ( ( V_23 - V_116 -> V_124 ) * V_116 -> V_123 ) >> 15 ;
V_131 = ( V_116 -> V_128 << 11 ) / ( V_130 + V_116 -> V_129 ) ;
V_2 -> V_22 = V_130 + V_131 ;
return ( V_2 -> V_22 + 8 ) >> 4 ;
}
static int F_50 ( struct V_1 * V_2 , int * V_46 )
{
int V_13 ;
T_2 V_23 , V_47 ;
V_13 = F_44 ( V_2 , & V_23 ) ;
if ( V_13 )
return V_13 ;
V_47 = F_49 ( V_2 , V_23 ) ;
if ( V_46 ) {
* V_46 = V_47 * 100 ;
return V_52 ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , int * V_46 )
{
int V_13 ;
T_5 V_8 = 0 ;
V_49 V_132 = V_2 -> V_78 ;
V_13 = F_38 ( V_2 , F_52 ( V_132 ) ) ;
if ( V_13 )
return V_13 ;
V_13 = F_4 ( V_2 -> V_15 , V_114 , ( V_49 * ) & V_8 , 3 ) ;
if ( V_13 )
return V_13 ;
* V_46 = ( F_12 ( V_8 ) >> 8 ) >> ( 8 - V_132 ) ;
return 0 ;
}
static T_1 F_53 ( struct V_1 * V_2 , T_2 V_33 )
{
T_2 V_130 , V_131 , V_133 , V_34 ;
T_2 V_134 , V_135 ;
T_1 V_136 , V_137 ;
T_2 V_132 = V_2 -> V_78 ;
struct V_115 * V_116 = & V_2 -> V_116 ;
V_135 = V_2 -> V_22 - 4000 ;
V_130 = ( V_116 -> V_126 * ( V_135 * V_135 >> 12 ) ) >> 11 ;
V_131 = V_116 -> V_120 * V_135 >> 11 ;
V_133 = V_130 + V_131 ;
V_134 = ( ( ( ( T_2 ) V_116 -> V_119 * 4 + V_133 ) << V_132 ) + 2 ) / 4 ;
V_130 = V_116 -> V_121 * V_135 >> 13 ;
V_131 = ( V_116 -> V_125 * ( ( V_135 * V_135 ) >> 12 ) ) >> 16 ;
V_133 = ( V_130 + V_131 + 2 ) >> 2 ;
V_136 = V_116 -> V_122 * ( T_1 ) ( V_133 + 32768 ) >> 15 ;
V_137 = ( ( T_1 ) V_33 - V_134 ) * ( 50000 >> V_132 ) ;
if ( V_137 < 0x80000000 )
V_34 = ( V_137 * 2 ) / V_136 ;
else
V_34 = ( V_137 / V_136 ) * 2 ;
V_130 = ( V_34 >> 8 ) * ( V_34 >> 8 ) ;
V_130 = ( V_130 * 3038 ) >> 16 ;
V_131 = ( - 7357 * V_34 ) >> 16 ;
return V_34 + ( ( V_130 + V_131 + 3791 ) >> 4 ) ;
}
static int F_54 ( struct V_1 * V_2 ,
int * V_46 , int * V_53 )
{
int V_13 ;
T_2 V_33 ;
T_1 V_54 ;
V_13 = F_50 ( V_2 , NULL ) ;
if ( V_13 )
return V_13 ;
V_13 = F_51 ( V_2 , & V_33 ) ;
if ( V_13 )
return V_13 ;
V_54 = F_53 ( V_2 , V_33 ) ;
* V_46 = V_54 ;
* V_53 = 1000 ;
return V_57 ;
}
static int F_55 ( struct V_1 * V_2 )
{
return 0 ;
}
static T_9 F_56 ( int V_138 , void * V_139 )
{
struct V_1 * V_2 = V_139 ;
F_57 ( & V_2 -> V_111 ) ;
return V_140 ;
}
static int F_58 ( struct V_4 * V_5 ,
const char * V_141 ,
int V_138 ,
struct V_1 * V_2 )
{
unsigned long V_142 ;
int V_13 ;
V_142 = F_59 ( F_60 ( V_138 ) ) ;
if ( V_142 != V_143 ) {
F_3 ( V_5 , L_19
L_20 ) ;
V_142 = V_143 ;
}
V_13 = F_61 ( V_5 ,
V_138 ,
F_56 ,
NULL ,
V_142 ,
V_141 ,
V_2 ) ;
if ( V_13 ) {
F_3 ( V_5 , L_21 ) ;
return 0 ;
}
V_2 -> V_110 = true ;
return 0 ;
}
int F_62 ( struct V_4 * V_5 ,
struct V_15 * V_15 ,
unsigned int V_144 ,
const char * V_141 ,
int V_138 )
{
int V_13 ;
struct V_61 * V_62 ;
struct V_1 * V_2 ;
unsigned int V_145 ;
struct V_146 * V_147 ;
V_62 = F_63 ( V_5 , sizeof( * V_2 ) ) ;
if ( ! V_62 )
return - V_148 ;
V_2 = F_16 ( V_62 ) ;
F_64 ( & V_2 -> V_66 ) ;
V_2 -> V_5 = V_5 ;
V_62 -> V_5 . V_149 = V_5 ;
V_62 -> V_141 = V_141 ;
V_62 -> V_150 = V_151 ;
V_62 -> V_152 = & V_153 ;
V_62 -> V_154 = V_155 ;
switch ( V_144 ) {
case V_156 :
V_62 -> V_157 = 2 ;
V_2 -> V_69 = & V_158 ;
V_2 -> V_78 = F_23 ( 8 ) ;
V_2 -> V_79 = F_23 ( 1 ) ;
V_2 -> V_159 = 10000 ;
break;
case V_160 :
V_62 -> V_157 = 2 ;
V_2 -> V_69 = & V_161 ;
V_2 -> V_78 = F_23 ( 16 ) ;
V_2 -> V_79 = F_23 ( 2 ) ;
V_2 -> V_159 = 2000 ;
break;
case V_162 :
V_62 -> V_157 = 3 ;
V_2 -> V_69 = & V_163 ;
V_2 -> V_78 = F_23 ( 16 ) ;
V_2 -> V_77 = F_23 ( 16 ) ;
V_2 -> V_79 = F_23 ( 2 ) ;
V_2 -> V_159 = 2000 ;
break;
default:
return - V_75 ;
}
V_2 -> V_164 = F_65 ( V_5 , L_22 ) ;
if ( F_66 ( V_2 -> V_164 ) ) {
F_3 ( V_5 , L_23 ) ;
return F_67 ( V_2 -> V_164 ) ;
}
V_13 = F_68 ( V_2 -> V_164 ) ;
if ( V_13 ) {
F_3 ( V_5 , L_24 ) ;
return V_13 ;
}
V_2 -> V_165 = F_65 ( V_5 , L_25 ) ;
if ( F_66 ( V_2 -> V_165 ) ) {
F_3 ( V_5 , L_26 ) ;
V_13 = F_67 ( V_2 -> V_165 ) ;
goto V_166;
}
V_13 = F_68 ( V_2 -> V_165 ) ;
if ( V_13 ) {
F_3 ( V_5 , L_27 ) ;
goto V_166;
}
F_43 ( V_2 -> V_159 , V_2 -> V_159 + 100 ) ;
V_147 = F_69 ( V_5 , L_28 , V_167 ) ;
if ( ! F_66 ( V_147 ) ) {
F_70 ( V_5 , L_29 ) ;
F_71 ( V_147 , 0 ) ;
}
V_2 -> V_15 = V_15 ;
V_13 = F_2 ( V_15 , V_168 , & V_145 ) ;
if ( V_13 < 0 )
goto V_169;
if ( V_145 != V_144 ) {
F_3 ( V_5 , L_30 ,
V_144 , V_145 ) ;
V_13 = - V_75 ;
goto V_169;
}
V_13 = V_2 -> V_69 -> V_85 ( V_2 ) ;
if ( V_13 < 0 )
goto V_169;
F_72 ( V_5 , V_62 ) ;
if ( V_145 == V_156 ) {
V_13 = F_45 ( V_2 , & V_2 -> V_116 ) ;
if ( V_13 < 0 ) {
F_3 ( V_2 -> V_5 ,
L_31 ) ;
goto V_169;
}
}
if ( V_138 > 0 || ( V_145 == V_156 ) ) {
V_13 = F_58 ( V_5 , V_141 , V_138 , V_2 ) ;
if ( V_13 )
goto V_169;
}
F_73 ( V_5 ) ;
F_74 ( V_5 ) ;
F_75 ( V_5 ) ;
F_76 ( V_5 , V_2 -> V_159 / 10 ) ;
F_77 ( V_5 ) ;
F_78 ( V_5 ) ;
V_13 = F_79 ( V_62 ) ;
if ( V_13 )
goto V_170;
return 0 ;
V_170:
F_17 ( V_2 -> V_5 ) ;
F_80 ( V_2 -> V_5 ) ;
F_81 ( V_2 -> V_5 ) ;
V_169:
F_82 ( V_2 -> V_165 ) ;
V_166:
F_82 ( V_2 -> V_164 ) ;
return V_13 ;
}
int F_83 ( struct V_4 * V_5 )
{
struct V_61 * V_62 = F_84 ( V_5 ) ;
struct V_1 * V_2 = F_16 ( V_62 ) ;
F_85 ( V_62 ) ;
F_17 ( V_2 -> V_5 ) ;
F_80 ( V_2 -> V_5 ) ;
F_81 ( V_2 -> V_5 ) ;
F_82 ( V_2 -> V_165 ) ;
F_82 ( V_2 -> V_164 ) ;
return 0 ;
}
static int F_86 ( struct V_4 * V_5 )
{
struct V_61 * V_62 = F_84 ( V_5 ) ;
struct V_1 * V_2 = F_16 ( V_62 ) ;
int V_13 ;
V_13 = F_82 ( V_2 -> V_165 ) ;
if ( V_13 )
return V_13 ;
return F_82 ( V_2 -> V_164 ) ;
}
static int F_87 ( struct V_4 * V_5 )
{
struct V_61 * V_62 = F_84 ( V_5 ) ;
struct V_1 * V_2 = F_16 ( V_62 ) ;
int V_13 ;
V_13 = F_68 ( V_2 -> V_164 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_68 ( V_2 -> V_165 ) ;
if ( V_13 )
return V_13 ;
F_43 ( V_2 -> V_159 , V_2 -> V_159 + 100 ) ;
return V_2 -> V_69 -> V_85 ( V_2 ) ;
}
