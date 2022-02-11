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
V_14 = ( ( T_2 ) V_2 -> V_22 ) - 76800 ;
V_14 = ( ( ( ( V_3 << 14 ) - ( V_10 << 20 ) - ( V_11 * V_14 ) ) + 16384 ) >> 15 )
* ( ( ( ( ( ( ( V_14 * V_12 ) >> 10 ) * ( ( ( V_14 * V_7 ) >> 11 ) + 32768 ) ) >> 10 )
+ 2097152 ) * V_9 + 8192 ) >> 14 ) ;
V_14 -= ( ( ( ( V_14 >> 15 ) * ( V_14 >> 15 ) ) >> 7 ) * V_6 ) >> 4 ;
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
V_47 = F_8 ( V_2 , V_23 ) ;
if ( V_46 ) {
* V_46 = V_47 * 10 ;
return V_50 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
int * V_46 , int * V_51 )
{
int V_13 ;
T_5 V_8 = 0 ;
T_2 V_33 ;
T_1 V_52 ;
V_13 = F_11 ( V_2 , NULL ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_4 ( V_2 -> V_15 , V_53 ,
( V_49 * ) & V_8 , 3 ) ;
if ( V_13 < 0 ) {
F_3 ( V_2 -> V_5 , L_10 ) ;
return V_13 ;
}
V_33 = F_12 ( V_8 ) >> 12 ;
V_52 = F_9 ( V_2 , V_33 ) ;
* V_46 = V_52 ;
* V_51 = 256000 ;
return V_54 ;
}
static int F_14 ( struct V_1 * V_2 , int * V_46 , int * V_51 )
{
int V_13 ;
T_6 V_8 = 0 ;
T_2 V_3 ;
T_1 V_55 ;
V_13 = F_11 ( V_2 , NULL ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_4 ( V_2 -> V_15 , V_56 ,
( V_49 * ) & V_8 , 2 ) ;
if ( V_13 < 0 ) {
F_3 ( V_2 -> V_5 , L_11 ) ;
return V_13 ;
}
V_3 = F_7 ( V_8 ) ;
V_55 = F_1 ( V_2 , V_3 ) ;
* V_46 = V_55 ;
* V_51 = 1024 ;
return V_54 ;
}
static int F_15 ( struct V_57 * V_58 ,
struct V_59 const * V_60 ,
int * V_46 , int * V_51 , long V_61 )
{
int V_13 ;
struct V_1 * V_2 = F_16 ( V_58 ) ;
F_17 ( V_2 -> V_5 ) ;
F_18 ( & V_2 -> V_62 ) ;
switch ( V_61 ) {
case V_63 :
switch ( V_60 -> type ) {
case V_64 :
V_13 = V_2 -> V_65 -> V_66 ( V_2 , V_46 , V_51 ) ;
break;
case V_67 :
V_13 = V_2 -> V_65 -> V_68 ( V_2 , V_46 , V_51 ) ;
break;
case V_69 :
V_13 = V_2 -> V_65 -> V_70 ( V_2 , V_46 ) ;
break;
default:
V_13 = - V_71 ;
break;
}
break;
case V_72 :
switch ( V_60 -> type ) {
case V_64 :
* V_46 = 1 << V_2 -> V_73 ;
V_13 = V_50 ;
break;
case V_67 :
* V_46 = 1 << V_2 -> V_74 ;
V_13 = V_50 ;
break;
case V_69 :
* V_46 = 1 << V_2 -> V_75 ;
V_13 = V_50 ;
break;
default:
V_13 = - V_71 ;
break;
}
break;
default:
V_13 = - V_71 ;
break;
}
F_19 ( & V_2 -> V_62 ) ;
F_20 ( V_2 -> V_5 ) ;
F_21 ( V_2 -> V_5 ) ;
return V_13 ;
}
static int F_22 ( struct V_1 * V_2 ,
int V_46 )
{
int V_76 ;
const int * V_77 = V_2 -> V_65 -> V_78 ;
const int V_79 = V_2 -> V_65 -> V_80 ;
for ( V_76 = 0 ; V_76 < V_79 ; V_76 ++ ) {
if ( V_77 [ V_76 ] == V_46 ) {
V_2 -> V_73 = F_23 ( V_46 ) ;
return V_2 -> V_65 -> V_81 ( V_2 ) ;
}
}
return - V_71 ;
}
static int F_24 ( struct V_1 * V_2 ,
int V_46 )
{
int V_76 ;
const int * V_77 = V_2 -> V_65 -> V_82 ;
const int V_79 = V_2 -> V_65 -> V_83 ;
for ( V_76 = 0 ; V_76 < V_79 ; V_76 ++ ) {
if ( V_77 [ V_76 ] == V_46 ) {
V_2 -> V_75 = F_23 ( V_46 ) ;
return V_2 -> V_65 -> V_81 ( V_2 ) ;
}
}
return - V_71 ;
}
static int F_25 ( struct V_1 * V_2 ,
int V_46 )
{
int V_76 ;
const int * V_77 = V_2 -> V_65 -> V_84 ;
const int V_79 = V_2 -> V_65 -> V_85 ;
for ( V_76 = 0 ; V_76 < V_79 ; V_76 ++ ) {
if ( V_77 [ V_76 ] == V_46 ) {
V_2 -> V_74 = F_23 ( V_46 ) ;
return V_2 -> V_65 -> V_81 ( V_2 ) ;
}
}
return - V_71 ;
}
static int F_26 ( struct V_57 * V_58 ,
struct V_59 const * V_60 ,
int V_46 , int V_51 , long V_61 )
{
int V_13 = 0 ;
struct V_1 * V_2 = F_16 ( V_58 ) ;
switch ( V_61 ) {
case V_72 :
F_17 ( V_2 -> V_5 ) ;
F_18 ( & V_2 -> V_62 ) ;
switch ( V_60 -> type ) {
case V_64 :
V_13 = F_22 ( V_2 , V_46 ) ;
break;
case V_67 :
V_13 = F_25 ( V_2 , V_46 ) ;
break;
case V_69 :
V_13 = F_24 ( V_2 , V_46 ) ;
break;
default:
V_13 = - V_71 ;
break;
}
F_19 ( & V_2 -> V_62 ) ;
F_20 ( V_2 -> V_5 ) ;
F_21 ( V_2 -> V_5 ) ;
break;
default:
return - V_71 ;
}
return V_13 ;
}
static T_7 F_27 ( char * V_26 , const int * V_86 , const int V_79 )
{
T_8 V_87 = 0 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_79 ; V_76 ++ )
V_87 += F_28 ( V_26 + V_87 , V_88 - V_87 , L_12 , V_86 [ V_76 ] ) ;
V_26 [ V_87 - 1 ] = '\n' ;
return V_87 ;
}
static T_7 F_29 ( struct V_4 * V_5 ,
struct V_89 * V_90 , char * V_26 )
{
struct V_1 * V_2 = F_16 ( F_30 ( V_5 ) ) ;
return F_27 ( V_26 , V_2 -> V_65 -> V_82 ,
V_2 -> V_65 -> V_83 ) ;
}
static T_7 F_31 ( struct V_4 * V_5 ,
struct V_89 * V_90 , char * V_26 )
{
struct V_1 * V_2 = F_16 ( F_30 ( V_5 ) ) ;
return F_27 ( V_26 , V_2 -> V_65 -> V_84 ,
V_2 -> V_65 -> V_85 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_13 ;
V_49 V_91 = F_33 ( V_2 -> V_75 + 1 ) |
F_34 ( V_2 -> V_74 + 1 ) ;
V_13 = F_35 ( V_2 -> V_15 , V_92 ,
V_93 |
V_94 |
V_95 ,
V_91 | V_96 ) ;
if ( V_13 < 0 ) {
F_3 ( V_2 -> V_5 ,
L_13 ) ;
return V_13 ;
}
V_13 = F_35 ( V_2 -> V_15 , V_97 ,
V_98 ,
V_99 ) ;
if ( V_13 < 0 ) {
F_3 ( V_2 -> V_5 ,
L_14 ) ;
return V_13 ;
}
return V_13 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_13 = F_32 ( V_2 ) ;
V_49 V_91 = F_37 ( V_2 -> V_73 + 1 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_35 ( V_2 -> V_15 , V_100 ,
V_101 , V_91 ) ;
}
static int F_38 ( struct V_1 * V_2 , V_49 V_102 )
{
int V_13 ;
const int V_103 [] = { 4500 , 7500 , 13500 , 25500 } ;
unsigned int V_104 ;
unsigned int V_105 ;
if ( V_2 -> V_106 )
F_39 ( & V_2 -> V_107 ) ;
V_13 = F_40 ( V_2 -> V_15 , V_92 , V_102 ) ;
if ( V_13 )
return V_13 ;
if ( V_2 -> V_106 ) {
V_13 = F_41 ( & V_2 -> V_107 ,
1 + F_42 ( 100 ) ) ;
if ( ! V_13 )
F_3 ( V_2 -> V_5 , L_15 ) ;
} else {
if ( V_102 == V_108 )
V_104 = 4500 ;
else
V_104 =
V_103 [ V_2 -> V_74 ] ;
F_43 ( V_104 , V_104 + 1000 ) ;
}
V_13 = F_2 ( V_2 -> V_15 , V_92 , & V_105 ) ;
if ( V_13 )
return V_13 ;
if ( V_105 & V_109 )
return - V_110 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , int * V_46 )
{
int V_13 ;
T_6 V_8 = 0 ;
V_13 = F_38 ( V_2 , V_108 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_4 ( V_2 -> V_15 , V_111 , ( V_49 * ) & V_8 , 2 ) ;
if ( V_13 )
return V_13 ;
* V_46 = F_7 ( V_8 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
int V_13 ;
int V_76 ;
T_6 V_26 [ V_114 / 2 ] ;
V_13 = F_4 ( V_2 -> V_15 , V_115 , V_26 ,
sizeof( V_26 ) ) ;
if ( V_13 < 0 )
return V_13 ;
for ( V_76 = 0 ; V_76 < F_46 ( V_26 ) ; V_76 ++ ) {
if ( V_26 [ V_76 ] == F_47 ( 0 ) || V_26 [ V_76 ] == F_47 ( 0xffff ) )
return - V_110 ;
}
F_48 ( V_26 , sizeof( V_26 ) ) ;
V_113 -> V_116 = F_7 ( V_26 [ V_116 ] ) ;
V_113 -> V_117 = F_7 ( V_26 [ V_117 ] ) ;
V_113 -> V_118 = F_7 ( V_26 [ V_118 ] ) ;
V_113 -> V_119 = F_7 ( V_26 [ V_119 ] ) ;
V_113 -> V_120 = F_7 ( V_26 [ V_120 ] ) ;
V_113 -> V_121 = F_7 ( V_26 [ V_121 ] ) ;
V_113 -> V_122 = F_7 ( V_26 [ V_122 ] ) ;
V_113 -> V_123 = F_7 ( V_26 [ V_123 ] ) ;
V_113 -> V_124 = F_7 ( V_26 [ V_124 ] ) ;
V_113 -> V_125 = F_7 ( V_26 [ V_125 ] ) ;
V_113 -> V_126 = F_7 ( V_26 [ V_126 ] ) ;
return 0 ;
}
static T_2 F_49 ( struct V_1 * V_2 , T_2 V_23 )
{
T_2 V_127 , V_128 ;
struct V_112 * V_113 = & V_2 -> V_113 ;
V_127 = ( ( V_23 - V_113 -> V_121 ) * V_113 -> V_120 ) >> 15 ;
V_128 = ( V_113 -> V_125 << 11 ) / ( V_127 + V_113 -> V_126 ) ;
V_2 -> V_22 = V_127 + V_128 ;
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
return V_50 ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , int * V_46 )
{
int V_13 ;
T_5 V_8 = 0 ;
V_49 V_129 = V_2 -> V_74 ;
V_13 = F_38 ( V_2 , F_52 ( V_129 ) ) ;
if ( V_13 )
return V_13 ;
V_13 = F_4 ( V_2 -> V_15 , V_111 , ( V_49 * ) & V_8 , 3 ) ;
if ( V_13 )
return V_13 ;
* V_46 = ( F_12 ( V_8 ) >> 8 ) >> ( 8 - V_129 ) ;
return 0 ;
}
static T_1 F_53 ( struct V_1 * V_2 , T_2 V_33 )
{
T_2 V_127 , V_128 , V_130 , V_34 ;
T_2 V_131 , V_132 ;
T_1 V_133 , V_134 ;
T_2 V_129 = V_2 -> V_74 ;
struct V_112 * V_113 = & V_2 -> V_113 ;
V_132 = V_2 -> V_22 - 4000 ;
V_127 = ( V_113 -> V_123 * ( V_132 * V_132 >> 12 ) ) >> 11 ;
V_128 = V_113 -> V_117 * V_132 >> 11 ;
V_130 = V_127 + V_128 ;
V_131 = ( ( ( ( T_2 ) V_113 -> V_116 * 4 + V_130 ) << V_129 ) + 2 ) / 4 ;
V_127 = V_113 -> V_118 * V_132 >> 13 ;
V_128 = ( V_113 -> V_122 * ( ( V_132 * V_132 ) >> 12 ) ) >> 16 ;
V_130 = ( V_127 + V_128 + 2 ) >> 2 ;
V_133 = V_113 -> V_119 * ( T_1 ) ( V_130 + 32768 ) >> 15 ;
V_134 = ( ( T_1 ) V_33 - V_131 ) * ( 50000 >> V_129 ) ;
if ( V_134 < 0x80000000 )
V_34 = ( V_134 * 2 ) / V_133 ;
else
V_34 = ( V_134 / V_133 ) * 2 ;
V_127 = ( V_34 >> 8 ) * ( V_34 >> 8 ) ;
V_127 = ( V_127 * 3038 ) >> 16 ;
V_128 = ( - 7357 * V_34 ) >> 16 ;
return V_34 + ( ( V_127 + V_128 + 3791 ) >> 4 ) ;
}
static int F_54 ( struct V_1 * V_2 ,
int * V_46 , int * V_51 )
{
int V_13 ;
T_2 V_33 ;
T_1 V_52 ;
V_13 = F_50 ( V_2 , NULL ) ;
if ( V_13 )
return V_13 ;
V_13 = F_51 ( V_2 , & V_33 ) ;
if ( V_13 )
return V_13 ;
V_52 = F_53 ( V_2 , V_33 ) ;
* V_46 = V_52 ;
* V_51 = 1000 ;
return V_54 ;
}
static int F_55 ( struct V_1 * V_2 )
{
return 0 ;
}
static T_9 F_56 ( int V_135 , void * V_136 )
{
struct V_1 * V_2 = V_136 ;
F_57 ( & V_2 -> V_107 ) ;
return V_137 ;
}
static int F_58 ( struct V_4 * V_5 ,
const char * V_138 ,
int V_135 ,
struct V_1 * V_2 )
{
unsigned long V_139 ;
int V_13 ;
V_139 = F_59 ( F_60 ( V_135 ) ) ;
if ( V_139 != V_140 ) {
F_3 ( V_5 , L_16
L_17 ) ;
V_139 = V_140 ;
}
V_13 = F_61 ( V_5 ,
V_135 ,
F_56 ,
NULL ,
V_139 ,
V_138 ,
V_2 ) ;
if ( V_13 ) {
F_3 ( V_5 , L_18 ) ;
return 0 ;
}
V_2 -> V_106 = true ;
return 0 ;
}
int F_62 ( struct V_4 * V_5 ,
struct V_15 * V_15 ,
unsigned int V_141 ,
const char * V_138 ,
int V_135 )
{
int V_13 ;
struct V_57 * V_58 ;
struct V_1 * V_2 ;
unsigned int V_142 ;
struct V_143 * V_144 ;
V_58 = F_63 ( V_5 , sizeof( * V_2 ) ) ;
if ( ! V_58 )
return - V_145 ;
V_2 = F_16 ( V_58 ) ;
F_64 ( & V_2 -> V_62 ) ;
V_2 -> V_5 = V_5 ;
V_58 -> V_5 . V_146 = V_5 ;
V_58 -> V_138 = V_138 ;
V_58 -> V_147 = V_148 ;
V_58 -> V_149 = & V_150 ;
V_58 -> V_151 = V_152 ;
switch ( V_141 ) {
case V_153 :
V_58 -> V_154 = 2 ;
V_2 -> V_65 = & V_155 ;
V_2 -> V_74 = F_23 ( 8 ) ;
V_2 -> V_75 = F_23 ( 1 ) ;
V_2 -> V_156 = 10000 ;
break;
case V_157 :
V_58 -> V_154 = 2 ;
V_2 -> V_65 = & V_158 ;
V_2 -> V_74 = F_23 ( 16 ) ;
V_2 -> V_75 = F_23 ( 2 ) ;
V_2 -> V_156 = 2000 ;
break;
case V_159 :
V_58 -> V_154 = 3 ;
V_2 -> V_65 = & V_160 ;
V_2 -> V_74 = F_23 ( 16 ) ;
V_2 -> V_73 = F_23 ( 16 ) ;
V_2 -> V_75 = F_23 ( 2 ) ;
V_2 -> V_156 = 2000 ;
break;
default:
return - V_71 ;
}
V_2 -> V_161 = F_65 ( V_5 , L_19 ) ;
if ( F_66 ( V_2 -> V_161 ) ) {
F_3 ( V_5 , L_20 ) ;
return F_67 ( V_2 -> V_161 ) ;
}
V_13 = F_68 ( V_2 -> V_161 ) ;
if ( V_13 ) {
F_3 ( V_5 , L_21 ) ;
return V_13 ;
}
V_2 -> V_162 = F_65 ( V_5 , L_22 ) ;
if ( F_66 ( V_2 -> V_162 ) ) {
F_3 ( V_5 , L_23 ) ;
V_13 = F_67 ( V_2 -> V_162 ) ;
goto V_163;
}
V_13 = F_68 ( V_2 -> V_162 ) ;
if ( V_13 ) {
F_3 ( V_5 , L_24 ) ;
goto V_163;
}
F_43 ( V_2 -> V_156 , V_2 -> V_156 + 100 ) ;
V_144 = F_69 ( V_5 , L_25 , V_164 ) ;
if ( ! F_66 ( V_144 ) ) {
F_70 ( V_5 , L_26 ) ;
F_71 ( V_144 , 0 ) ;
}
V_2 -> V_15 = V_15 ;
V_13 = F_2 ( V_15 , V_165 , & V_142 ) ;
if ( V_13 < 0 )
goto V_166;
if ( V_142 != V_141 ) {
F_3 ( V_5 , L_27 ,
V_141 , V_142 ) ;
V_13 = - V_71 ;
goto V_166;
}
V_13 = V_2 -> V_65 -> V_81 ( V_2 ) ;
if ( V_13 < 0 )
goto V_166;
F_72 ( V_5 , V_58 ) ;
if ( V_142 == V_153 ) {
V_13 = F_45 ( V_2 , & V_2 -> V_113 ) ;
if ( V_13 < 0 ) {
F_3 ( V_2 -> V_5 ,
L_28 ) ;
goto V_166;
}
}
if ( V_135 > 0 || ( V_142 == V_153 ) ) {
V_13 = F_58 ( V_5 , V_138 , V_135 , V_2 ) ;
if ( V_13 )
goto V_166;
}
F_73 ( V_5 ) ;
F_74 ( V_5 ) ;
F_75 ( V_5 ) ;
F_76 ( V_5 , V_2 -> V_156 / 10 ) ;
F_77 ( V_5 ) ;
F_78 ( V_5 ) ;
V_13 = F_79 ( V_58 ) ;
if ( V_13 )
goto V_167;
return 0 ;
V_167:
F_17 ( V_2 -> V_5 ) ;
F_80 ( V_2 -> V_5 ) ;
F_81 ( V_2 -> V_5 ) ;
V_166:
F_82 ( V_2 -> V_162 ) ;
V_163:
F_82 ( V_2 -> V_161 ) ;
return V_13 ;
}
int F_83 ( struct V_4 * V_5 )
{
struct V_57 * V_58 = F_84 ( V_5 ) ;
struct V_1 * V_2 = F_16 ( V_58 ) ;
F_85 ( V_58 ) ;
F_17 ( V_2 -> V_5 ) ;
F_80 ( V_2 -> V_5 ) ;
F_81 ( V_2 -> V_5 ) ;
F_82 ( V_2 -> V_162 ) ;
F_82 ( V_2 -> V_161 ) ;
return 0 ;
}
static int F_86 ( struct V_4 * V_5 )
{
struct V_57 * V_58 = F_84 ( V_5 ) ;
struct V_1 * V_2 = F_16 ( V_58 ) ;
int V_13 ;
V_13 = F_82 ( V_2 -> V_162 ) ;
if ( V_13 )
return V_13 ;
return F_82 ( V_2 -> V_161 ) ;
}
static int F_87 ( struct V_4 * V_5 )
{
struct V_57 * V_58 = F_84 ( V_5 ) ;
struct V_1 * V_2 = F_16 ( V_58 ) ;
int V_13 ;
V_13 = F_68 ( V_2 -> V_161 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_68 ( V_2 -> V_162 ) ;
if ( V_13 )
return V_13 ;
F_43 ( V_2 -> V_156 , V_2 -> V_156 + 100 ) ;
return V_2 -> V_65 -> V_81 ( V_2 ) ;
}
