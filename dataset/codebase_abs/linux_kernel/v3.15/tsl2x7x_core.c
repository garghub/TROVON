static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 = 0 ;
V_5 = F_2 ( V_2 , ( V_6 | V_3 ) ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_7 , L_1
, V_8 , V_3 ) ;
return V_5 ;
}
V_5 = F_4 ( V_2 ) ;
if ( V_5 >= 0 )
* V_4 = ( T_1 ) V_5 ;
else
F_3 ( & V_2 -> V_7 , L_2
, V_8 , V_3 ) ;
return V_5 ;
}
static int F_5 ( struct V_9 * V_10 )
{
T_2 V_11 , V_12 ;
T_3 V_13 ;
T_4 V_14 ;
T_3 V_15 ;
T_1 V_16 [ 4 ] ;
struct V_17 * V_18 ;
struct V_19 * V_20 = F_6 ( V_10 ) ;
int V_21 , V_5 ;
T_3 V_22 = 0 ;
T_3 V_23 = 0 ;
if ( F_7 ( & V_20 -> V_24 ) == 0 )
return V_20 -> V_25 . V_13 ;
if ( V_20 -> V_26 != V_27 ) {
F_3 ( & V_20 -> V_2 -> V_7 , L_3 ,
V_8 ) ;
V_5 = - V_28 ;
goto V_29;
}
V_5 = F_1 ( V_20 -> V_2 ,
( V_6 | V_30 ) , & V_16 [ 0 ] ) ;
if ( V_5 < 0 ) {
F_3 ( & V_20 -> V_2 -> V_7 ,
L_4 , V_8 ) ;
goto V_29;
}
if ( ! ( V_16 [ 0 ] & V_31 ) ) {
F_3 ( & V_20 -> V_2 -> V_7 ,
L_5 , V_8 ) ;
V_5 = V_20 -> V_25 . V_13 ;
goto V_29;
}
for ( V_21 = 0 ; V_21 < 4 ; V_21 ++ ) {
V_5 = F_1 ( V_20 -> V_2 ,
( V_6 | ( V_32 + V_21 ) ) ,
& V_16 [ V_21 ] ) ;
if ( V_5 < 0 ) {
F_3 ( & V_20 -> V_2 -> V_7 ,
L_6 , V_8 , V_5 ) ;
goto V_29;
}
}
V_5 = F_2 ( V_20 -> V_2 ,
( V_6 |
V_33 |
V_34 ) ) ;
if ( V_5 < 0 ) {
F_3 ( & V_20 -> V_2 -> V_7 ,
L_7 ,
V_8 , V_5 ) ;
goto V_29;
}
V_11 = F_8 ( ( const V_35 * ) & V_16 [ 0 ] ) ;
V_12 = F_8 ( ( const V_35 * ) & V_16 [ 2 ] ) ;
V_20 -> V_25 . V_36 = V_11 ;
V_20 -> V_25 . V_37 = V_12 ;
if ( ( V_11 >= V_20 -> V_38 ) || ( V_12 >= V_20 -> V_38 ) ) {
V_13 = V_39 ;
goto V_40;
}
if ( V_11 == 0 ) {
V_5 = V_20 -> V_25 . V_13 ;
goto V_29;
}
V_15 = ( V_12 << 15 ) / V_11 ;
V_18 = (struct V_17 * ) V_20 -> V_41 ;
while ( V_18 -> V_15 != 0 && V_18 -> V_15 < V_15 )
V_18 ++ ;
if ( V_18 -> V_15 == 0 ) {
V_13 = 0 ;
} else {
V_22 = F_9 ( ( V_11 * V_18 -> V_11 ) ,
V_42 [ V_20 -> V_43 . V_44 ] ) ;
V_23 = F_9 ( ( V_12 * V_18 -> V_12 ) ,
V_42 [ V_20 -> V_43 . V_44 ] ) ;
V_13 = V_22 - V_23 ;
}
if ( V_23 > V_22 ) {
F_10 ( & V_20 -> V_2 -> V_7 , L_8 ) ;
V_5 = V_20 -> V_25 . V_13 ;
goto V_29;
}
if ( V_20 -> V_45 == 0 )
V_13 = 0 ;
else
V_13 = ( V_13 + ( V_20 -> V_45 >> 1 ) ) /
V_20 -> V_45 ;
V_14 = V_13 ;
V_14 = V_14 * V_20 -> V_43 . V_46 ;
V_14 >>= 8 ;
V_13 = V_14 ;
V_13 = ( V_13 + 500 ) / 1000 ;
if ( V_13 > V_39 )
V_13 = V_39 ;
V_40:
V_20 -> V_25 . V_13 = V_13 ;
V_5 = V_13 ;
V_29:
F_11 ( & V_20 -> V_24 ) ;
return V_5 ;
}
static int F_12 ( struct V_9 * V_10 )
{
int V_21 ;
int V_5 ;
T_1 V_47 ;
T_1 V_48 [ 2 ] ;
struct V_19 * V_20 = F_6 ( V_10 ) ;
if ( F_7 ( & V_20 -> V_49 ) == 0 ) {
F_3 ( & V_20 -> V_2 -> V_7 ,
L_9 , V_8 ) ;
return - V_28 ;
}
V_5 = F_1 ( V_20 -> V_2 ,
( V_6 | V_30 ) , & V_47 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_20 -> V_2 -> V_7 ,
L_10 , V_8 , V_5 ) ;
goto V_50;
}
switch ( V_20 -> V_51 ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
if ( ! ( V_47 & V_31 ) )
goto V_50;
break;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
if ( ! ( V_47 & V_62 ) )
goto V_50;
break;
}
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
V_5 = F_1 ( V_20 -> V_2 ,
( V_6 |
( V_63 + V_21 ) ) , & V_48 [ V_21 ] ) ;
if ( V_5 < 0 )
goto V_50;
}
V_20 -> V_64 =
F_8 ( ( const V_35 * ) & V_48 [ 0 ] ) ;
V_50:
F_11 ( & V_20 -> V_49 ) ;
return V_20 -> V_64 ;
}
static void F_13 ( struct V_19 * V_20 )
{
if ( V_20 -> V_65 && V_20 -> V_65 -> V_66 )
memcpy ( & ( V_20 -> V_43 ) ,
V_20 -> V_65 -> V_66 ,
sizeof( V_67 ) ) ;
else
memcpy ( & ( V_20 -> V_43 ) ,
& V_67 ,
sizeof( V_67 ) ) ;
if ( V_20 -> V_65 && V_20 -> V_65 -> V_68 [ 0 ] . V_15 != 0 )
memcpy ( V_20 -> V_41 ,
V_20 -> V_65 -> V_68 ,
sizeof( V_20 -> V_65 -> V_68 ) ) ;
else
memcpy ( V_20 -> V_41 ,
(struct V_17 * ) V_69 [ V_20 -> V_51 ] ,
V_70 ) ;
}
static int F_14 ( struct V_9 * V_10 )
{
struct V_19 * V_20 = F_6 ( V_10 ) ;
T_1 V_71 ;
int V_72 ;
int V_5 ;
int V_73 ;
V_5 = F_2 ( V_20 -> V_2 ,
( V_6 | V_74 ) ) ;
if ( V_5 < 0 ) {
F_3 ( & V_20 -> V_2 -> V_7 ,
L_11 ,
V_8 , V_5 ) ;
return V_5 ;
}
V_71 = F_4 ( V_20 -> V_2 ) ;
if ( ( V_71 & ( V_75 | V_76 ) )
!= ( V_75 | V_76 ) ) {
F_3 ( & V_20 -> V_2 -> V_7 ,
L_12 , V_8 ) ;
return - 1 ;
}
V_5 = F_2 ( V_20 -> V_2 ,
( V_6 | V_74 ) ) ;
if ( V_5 < 0 ) {
F_3 ( & V_20 -> V_2 -> V_7 ,
L_13 ,
V_8 , V_5 ) ;
return V_5 ;
}
V_71 = F_4 ( V_20 -> V_2 ) ;
if ( ( V_71 & V_31 ) != V_31 ) {
F_3 ( & V_20 -> V_2 -> V_7 ,
L_14 , V_8 ) ;
return - V_77 ;
}
V_73 = F_5 ( V_10 ) ;
if ( V_73 < 0 ) {
F_3 ( & V_20 -> V_2 -> V_7 ,
L_15 , V_8 ) ;
return V_73 ;
}
V_72 = ( ( ( V_20 -> V_43 . V_78 )
* V_20 -> V_43 . V_46 ) / V_73 ) ;
if ( ( V_72 < 250 ) || ( V_72 > 4000 ) )
return - V_79 ;
V_20 -> V_43 . V_46 = V_72 ;
F_15 ( & V_20 -> V_2 -> V_7 ,
L_16 , V_20 -> V_2 -> V_80 ) ;
return ( int ) V_72 ;
}
static int F_16 ( struct V_9 * V_10 )
{
int V_21 ;
int V_5 = 0 ;
T_1 * V_81 ;
T_1 V_82 ;
int V_83 ;
int V_84 ;
struct V_19 * V_20 = F_6 ( V_10 ) ;
T_1 V_71 = 0 ;
if ( V_20 -> V_65 && V_20 -> V_65 -> V_85 )
V_20 -> V_65 -> V_85 ( V_10 ) ;
V_20 -> V_86 [ V_87 ] =
V_20 -> V_43 . V_88 ;
V_20 -> V_86 [ V_89 ] =
V_20 -> V_43 . V_90 ;
V_20 -> V_86 [ V_91 ] =
V_20 -> V_43 . V_92 ;
V_20 -> V_86 [ V_93 ] =
( V_20 -> V_43 . V_94 ) & 0xFF ;
V_20 -> V_86 [ V_95 ] =
( V_20 -> V_43 . V_94 >> 8 ) & 0xFF ;
V_20 -> V_86 [ V_96 ] =
( V_20 -> V_43 . V_97 ) & 0xFF ;
V_20 -> V_86 [ V_98 ] =
( V_20 -> V_43 . V_97 >> 8 ) & 0xFF ;
V_20 -> V_86 [ V_99 ] =
V_20 -> V_43 . V_100 ;
V_20 -> V_86 [ V_101 ] =
V_20 -> V_43 . V_102 ;
V_20 -> V_86 [ V_103 ] =
V_20 -> V_43 . V_104 ;
V_20 -> V_86 [ V_105 ] =
V_20 -> V_43 . V_106 ;
if ( V_20 -> V_26 == V_27 ) {
F_15 ( & V_20 -> V_2 -> V_7 , L_17 ) ;
return - V_107 ;
}
V_83 = ( V_20 -> V_43 . V_84 * 100 + 135 ) / 270 ;
if ( V_83 == 0 )
V_83 = 1 ;
V_84 = ( V_83 * 27 + 5 ) / 10 ;
V_20 -> V_86 [ V_108 ] = 256 - V_83 ;
V_20 -> V_86 [ V_109 ] =
( V_20 -> V_43 . V_44 |
( V_110 | V_111 )
| ( ( V_20 -> V_43 . V_112 ) << 2 ) ) ;
V_20 -> V_38 = V_83 * 922 ;
V_20 -> V_45 = ( V_84 + 25 ) / 50 ;
V_82 = V_76 ;
V_5 = F_17 ( V_20 -> V_2 ,
V_6 | V_74 , V_82 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_20 -> V_2 -> V_7 ,
L_18 , V_8 ) ;
return V_5 ;
}
for ( V_21 = 0 , V_81 = V_20 -> V_86 ;
V_21 < V_113 ; V_21 ++ ) {
V_5 = F_17 ( V_20 -> V_2 ,
V_6 + V_21 , * V_81 ++ ) ;
if ( V_5 < 0 ) {
F_3 ( & V_20 -> V_2 -> V_7 ,
L_19 , V_8 , V_21 ) ;
return V_5 ;
}
}
F_18 ( 3 ) ;
V_82 = V_76 |
V_75 |
V_114 ;
V_5 = F_17 ( V_20 -> V_2 ,
V_6 | V_74 , V_82 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_20 -> V_2 -> V_7 ,
L_20 , V_8 ) ;
return V_5 ;
}
V_20 -> V_26 = V_27 ;
if ( V_20 -> V_43 . V_115 != 0 ) {
F_15 ( & V_20 -> V_2 -> V_7 , L_21 ) ;
V_71 = V_76 | V_75 ;
if ( ( V_20 -> V_43 . V_115 == 0x20 ) ||
( V_20 -> V_43 . V_115 == 0x30 ) )
V_71 |= V_114 ;
V_71 |= V_20 -> V_43 . V_115 ;
V_5 = F_17 ( V_20 -> V_2 ,
( V_6 | V_74 ) , V_71 ) ;
if ( V_5 < 0 )
F_3 ( & V_20 -> V_2 -> V_7 ,
L_22 ,
V_8 ) ;
V_5 = F_2 ( V_20 -> V_2 ,
V_6 | V_33 |
V_116 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_20 -> V_2 -> V_7 ,
L_23 ,
V_8 ) ;
return V_5 ;
}
}
return V_5 ;
}
static int F_19 ( struct V_9 * V_10 )
{
int V_5 ;
struct V_19 * V_20 = F_6 ( V_10 ) ;
V_20 -> V_26 = V_117 ;
V_5 = F_17 ( V_20 -> V_2 ,
V_6 | V_74 , 0x00 ) ;
if ( V_20 -> V_65 && V_20 -> V_65 -> V_118 )
V_20 -> V_65 -> V_118 ( V_20 -> V_2 ) ;
return V_5 ;
}
static
int F_20 ( struct V_9 * V_10 )
{
struct V_19 * V_20 = F_6 ( V_10 ) ;
int V_119 = V_20 -> V_26 ;
F_21 ( & V_20 -> V_24 ) ;
F_21 ( & V_20 -> V_49 ) ;
if ( V_119 == V_27 )
F_19 ( V_10 ) ;
F_16 ( V_10 ) ;
if ( V_119 != V_27 )
F_19 ( V_10 ) ;
F_11 ( & V_20 -> V_49 ) ;
F_11 ( & V_20 -> V_24 ) ;
return 0 ;
}
static
void F_22 ( int * V_120 , int V_121 ,
struct V_122 * V_123 )
{
int V_21 ;
int V_124 ;
int V_125 ;
if ( V_121 == 0 )
V_121 = 1 ;
V_124 = 0 ;
V_123 -> V_126 = V_127 ;
V_123 -> V_128 = V_129 ;
for ( V_21 = 0 ; V_21 < V_121 ; V_21 ++ ) {
V_124 += V_120 [ V_21 ] ;
V_123 -> V_126 = V_126 ( V_123 -> V_126 , V_120 [ V_21 ] ) ;
V_123 -> V_128 = V_128 ( V_123 -> V_128 , V_120 [ V_21 ] ) ;
}
V_123 -> V_130 = V_124 / V_121 ;
V_124 = 0 ;
for ( V_21 = 0 ; V_21 < V_121 ; V_21 ++ ) {
V_125 = V_120 [ V_21 ] - V_123 -> V_130 ;
V_124 += V_125 * V_125 ;
}
V_123 -> V_131 = F_23 ( ( long ) V_124 ) / V_121 ;
}
static void F_24 ( struct V_9 * V_10 )
{
int V_132 [ V_133 + 1 ] ;
int V_21 ;
struct V_122 V_134 [ 2 ] ;
struct V_122 * V_135 ;
struct V_19 * V_20 = F_6 ( V_10 ) ;
T_1 V_136 ;
T_1 V_137 = V_20 -> V_26 ;
if ( V_20 -> V_43 . V_138 > V_133 ) {
F_3 ( & V_20 -> V_2 -> V_7 ,
L_24 ,
V_8 , V_20 -> V_43 . V_138 ) ;
V_20 -> V_43 . V_138 = V_133 ;
}
F_19 ( V_10 ) ;
V_136 = V_20 -> V_43 . V_115 ;
V_20 -> V_43 . V_115 |= V_139 ;
F_16 ( V_10 ) ;
for ( V_21 = 0 ; V_21 < V_20 -> V_43 . V_138 ; V_21 ++ ) {
F_18 ( 15 ) ;
F_12 ( V_10 ) ;
V_132 [ V_21 ] = V_20 -> V_64 ;
F_15 ( & V_20 -> V_2 -> V_7 , L_25 ,
V_21 , V_20 -> V_64 ) ;
}
F_19 ( V_10 ) ;
V_135 = & V_134 [ V_140 ] ;
F_22 ( V_132 ,
V_20 -> V_43 . V_138 , V_135 ) ;
V_20 -> V_43 . V_106 = ( V_135 -> V_128 << 1 ) - V_135 -> V_130 ;
F_15 ( & V_20 -> V_2 -> V_7 , L_26 ,
V_135 -> V_126 , V_135 -> V_130 , V_135 -> V_128 ) ;
F_15 ( & V_20 -> V_2 -> V_7 ,
L_27 ,
V_20 -> V_2 -> V_80 , V_20 -> V_43 . V_106 ) ;
V_20 -> V_43 . V_115 = V_136 ;
if ( V_137 == V_27 )
F_16 ( V_10 ) ;
}
static T_5 F_25 ( struct V_141 * V_7 ,
struct V_142 * V_143 , char * V_16 )
{
struct V_19 * V_20 = F_6 ( F_26 ( V_7 ) ) ;
return snprintf ( V_16 , V_144 , L_28 , V_20 -> V_26 ) ;
}
static T_5 F_27 ( struct V_141 * V_7 ,
struct V_142 * V_143 , const char * V_16 , T_6 V_145 )
{
struct V_9 * V_10 = F_26 ( V_7 ) ;
bool V_146 ;
if ( F_28 ( V_16 , & V_146 ) )
return - V_107 ;
if ( V_146 )
F_16 ( V_10 ) ;
else
F_19 ( V_10 ) ;
return V_145 ;
}
static T_5 F_29 ( struct V_141 * V_7 ,
struct V_142 * V_143 , char * V_16 )
{
struct V_19 * V_20 = F_6 ( F_26 ( V_7 ) ) ;
switch ( V_20 -> V_51 ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
return snprintf ( V_16 , V_144 , L_29 , L_30 ) ;
}
return snprintf ( V_16 , V_144 , L_29 , L_31 ) ;
}
static T_5 F_30 ( struct V_141 * V_7 ,
struct V_142 * V_143 , char * V_16 )
{
return snprintf ( V_16 , V_144 , L_29 , L_32 ) ;
}
static T_5 F_31 ( struct V_141 * V_7 ,
struct V_142 * V_143 , char * V_16 )
{
struct V_19 * V_20 = F_6 ( F_26 ( V_7 ) ) ;
int V_147 , V_148 ;
V_147 = ( V_149 - ( T_1 ) V_20 -> V_43 . V_84 ) + 1 ;
V_148 = V_147 * V_150 ;
V_147 /= 1000 ;
V_148 %= 1000 ;
return snprintf ( V_16 , V_144 , L_33 , V_147 , V_148 ) ;
}
static T_5 F_32 ( struct V_141 * V_7 ,
struct V_142 * V_143 , const char * V_16 , T_6 V_145 )
{
struct V_9 * V_10 = F_26 ( V_7 ) ;
struct V_19 * V_20 = F_6 ( V_10 ) ;
struct V_151 V_152 ;
int V_5 ;
V_5 = F_33 ( V_16 , 100 , & V_152 . integer , & V_152 . V_153 ) ;
if ( V_5 )
return V_5 ;
V_152 . V_153 /= 3 ;
V_20 -> V_43 . V_84 =
( V_149 - ( T_1 ) V_152 . V_153 ) ;
F_15 ( & V_20 -> V_2 -> V_7 , L_34 ,
V_8 , V_20 -> V_43 . V_84 ) ;
F_20 ( V_10 ) ;
return V_154 ;
}
static T_5 F_34 ( struct V_141 * V_7 ,
struct V_142 * V_143 , char * V_16 )
{
struct V_19 * V_20 = F_6 ( F_26 ( V_7 ) ) ;
return snprintf ( V_16 , V_144 , L_28 ,
V_20 -> V_43 . V_78 ) ;
}
static T_5 F_35 ( struct V_141 * V_7 ,
struct V_142 * V_143 , const char * V_16 , T_6 V_145 )
{
struct V_9 * V_10 = F_26 ( V_7 ) ;
struct V_19 * V_20 = F_6 ( V_10 ) ;
unsigned long V_146 ;
if ( F_36 ( V_16 , 0 , & V_146 ) )
return - V_107 ;
if ( V_146 )
V_20 -> V_43 . V_78 = V_146 ;
F_20 ( V_10 ) ;
return V_145 ;
}
static T_5 F_37 ( struct V_141 * V_7 ,
struct V_142 * V_143 , char * V_16 )
{
struct V_19 * V_20 = F_6 ( F_26 ( V_7 ) ) ;
int V_147 , V_148 , V_155 ;
V_147 = ( V_149 - ( T_1 ) V_20 -> V_43 . V_84 ) + 1 ;
V_148 = V_147 * V_150 ;
V_155 = V_148 * ( V_20 -> V_43 . V_100 & 0x0F ) ;
V_147 = ( V_155 / 1000 ) ;
V_148 = ( V_155 % 1000 ) ;
return snprintf ( V_16 , V_144 , L_33 , V_147 , V_148 ) ;
}
static T_5 F_38 ( struct V_141 * V_7 ,
struct V_142 * V_143 , const char * V_16 , T_6 V_145 )
{
struct V_9 * V_10 = F_26 ( V_7 ) ;
struct V_19 * V_20 = F_6 ( V_10 ) ;
struct V_151 V_152 ;
int V_147 , V_148 , V_155 ;
int V_5 ;
V_5 = F_33 ( V_16 , 100 , & V_152 . integer , & V_152 . V_153 ) ;
if ( V_5 )
return V_5 ;
V_147 = ( V_149 - ( T_1 ) V_20 -> V_43 . V_84 ) + 1 ;
V_148 = V_147 * V_150 ;
V_155 =
F_9 ( ( ( V_152 . integer * 1000 ) + V_152 . V_153 ) , V_148 ) ;
V_20 -> V_43 . V_100 &= 0xF0 ;
V_20 -> V_43 . V_100 |= ( V_155 & 0x0F ) ;
F_15 ( & V_20 -> V_2 -> V_7 , L_35 ,
V_8 , V_155 ) ;
F_20 ( V_10 ) ;
return V_154 ;
}
static T_5 F_39 ( struct V_141 * V_7 ,
struct V_142 * V_143 , char * V_16 )
{
struct V_19 * V_20 = F_6 ( F_26 ( V_7 ) ) ;
int V_147 , V_148 , V_155 ;
V_147 = ( V_149 - ( T_1 ) V_20 -> V_43 . V_88 ) + 1 ;
V_148 = V_147 * V_150 ;
V_155 = V_148 * ( ( V_20 -> V_43 . V_100 & 0xF0 ) >> 4 ) ;
V_147 = ( V_155 / 1000 ) ;
V_148 = ( V_155 % 1000 ) ;
return snprintf ( V_16 , V_144 , L_33 , V_147 , V_148 ) ;
}
static T_5 F_40 ( struct V_141 * V_7 ,
struct V_142 * V_143 , const char * V_16 , T_6 V_145 )
{
struct V_9 * V_10 = F_26 ( V_7 ) ;
struct V_19 * V_20 = F_6 ( V_10 ) ;
struct V_151 V_152 ;
int V_147 , V_148 , V_155 ;
int V_5 ;
V_5 = F_33 ( V_16 , 100 , & V_152 . integer , & V_152 . V_153 ) ;
if ( V_5 )
return V_5 ;
V_147 = ( V_149 - ( T_1 ) V_20 -> V_43 . V_88 ) + 1 ;
V_148 = V_147 * V_150 ;
V_155 =
F_9 ( ( ( V_152 . integer * 1000 ) + V_152 . V_153 ) , V_148 ) ;
V_20 -> V_43 . V_100 &= 0x0F ;
V_20 -> V_43 . V_100 |= ( ( V_155 << 4 ) & 0xF0 ) ;
F_15 ( & V_20 -> V_2 -> V_7 , L_36 ,
V_8 , V_155 ) ;
F_20 ( V_10 ) ;
return V_154 ;
}
static T_5 F_41 ( struct V_141 * V_7 ,
struct V_142 * V_143 , const char * V_16 , T_6 V_145 )
{
struct V_9 * V_10 = F_26 ( V_7 ) ;
bool V_146 ;
if ( F_28 ( V_16 , & V_146 ) )
return - V_107 ;
if ( V_146 )
F_14 ( V_10 ) ;
F_20 ( V_10 ) ;
return V_145 ;
}
static T_5 F_42 ( struct V_141 * V_7 ,
struct V_142 * V_143 , char * V_16 )
{
struct V_19 * V_20 = F_6 ( F_26 ( V_7 ) ) ;
int V_21 = 0 ;
int V_156 = 0 ;
while ( V_21 < ( V_157 * 3 ) ) {
V_156 += snprintf ( V_16 + V_156 , V_144 , L_37 ,
V_20 -> V_41 [ V_21 ] . V_15 ,
V_20 -> V_41 [ V_21 ] . V_11 ,
V_20 -> V_41 [ V_21 ] . V_12 ) ;
if ( V_20 -> V_41 [ V_21 ] . V_15 == 0 ) {
V_156 -- ;
break;
}
V_21 ++ ;
}
V_156 += snprintf ( V_16 + V_156 , V_144 , L_38 ) ;
return V_156 ;
}
static T_5 F_43 ( struct V_141 * V_7 ,
struct V_142 * V_143 , const char * V_16 , T_6 V_145 )
{
struct V_9 * V_10 = F_26 ( V_7 ) ;
struct V_19 * V_20 = F_6 ( V_10 ) ;
int V_146 [ F_44 ( V_20 -> V_41 ) * 3 + 1 ] ;
int V_158 ;
F_45 ( V_16 , F_44 ( V_146 ) , V_146 ) ;
V_158 = V_146 [ 0 ] ;
if ( ( V_158 % 3 ) || V_158 < 6 ||
V_158 > ( ( F_44 ( V_20 -> V_41 ) - 1 ) * 3 ) ) {
F_15 ( V_7 , L_39 , V_158 ) ;
return - V_107 ;
}
if ( ( V_146 [ ( V_158 - 2 ) ] | V_146 [ ( V_158 - 1 ) ] | V_146 [ V_158 ] ) != 0 ) {
F_15 ( V_7 , L_40 , V_158 ) ;
return - V_107 ;
}
if ( V_20 -> V_26 == V_27 )
F_19 ( V_10 ) ;
memset ( V_20 -> V_41 , 0 , sizeof( V_20 -> V_41 ) ) ;
memcpy ( V_20 -> V_41 , & V_146 [ 1 ] , ( V_146 [ 0 ] * 4 ) ) ;
F_20 ( V_10 ) ;
return V_145 ;
}
static T_5 F_46 ( struct V_141 * V_7 ,
struct V_142 * V_143 , const char * V_16 , T_6 V_145 )
{
struct V_9 * V_10 = F_26 ( V_7 ) ;
bool V_146 ;
if ( F_28 ( V_16 , & V_146 ) )
return - V_107 ;
if ( V_146 )
F_24 ( V_10 ) ;
F_20 ( V_10 ) ;
return V_145 ;
}
static int F_47 ( struct V_9 * V_10 ,
const struct V_159 * V_160 ,
enum V_161 type ,
enum V_162 V_163 )
{
struct V_19 * V_20 = F_6 ( V_10 ) ;
int V_5 ;
if ( V_160 -> type == V_164 )
V_5 = ! ! ( V_20 -> V_43 . V_115 & 0x10 ) ;
else
V_5 = ! ! ( V_20 -> V_43 . V_115 & 0x20 ) ;
return V_5 ;
}
static int F_48 ( struct V_9 * V_10 ,
const struct V_159 * V_160 ,
enum V_161 type ,
enum V_162 V_163 ,
int V_4 )
{
struct V_19 * V_20 = F_6 ( V_10 ) ;
if ( V_160 -> type == V_164 ) {
if ( V_4 )
V_20 -> V_43 . V_115 |= 0x10 ;
else
V_20 -> V_43 . V_115 &= 0x20 ;
} else {
if ( V_4 )
V_20 -> V_43 . V_115 |= 0x20 ;
else
V_20 -> V_43 . V_115 &= 0x10 ;
}
F_20 ( V_10 ) ;
return 0 ;
}
static int F_49 ( struct V_9 * V_10 ,
const struct V_159 * V_160 ,
enum V_161 type ,
enum V_162 V_163 ,
enum V_165 V_166 ,
int V_4 , int V_167 )
{
struct V_19 * V_20 = F_6 ( V_10 ) ;
if ( V_160 -> type == V_164 ) {
switch ( V_163 ) {
case V_168 :
V_20 -> V_43 . V_97 = V_4 ;
break;
case V_169 :
V_20 -> V_43 . V_94 = V_4 ;
break;
default:
return - V_107 ;
}
} else {
switch ( V_163 ) {
case V_168 :
V_20 -> V_43 . V_106 = V_4 ;
break;
case V_169 :
V_20 -> V_43 . V_104 = V_4 ;
break;
default:
return - V_107 ;
}
}
F_20 ( V_10 ) ;
return 0 ;
}
static int F_50 ( struct V_9 * V_10 ,
const struct V_159 * V_160 ,
enum V_161 type ,
enum V_162 V_163 ,
enum V_165 V_166 ,
int * V_4 , int * V_167 )
{
struct V_19 * V_20 = F_6 ( V_10 ) ;
if ( V_160 -> type == V_164 ) {
switch ( V_163 ) {
case V_168 :
* V_4 = V_20 -> V_43 . V_97 ;
break;
case V_169 :
* V_4 = V_20 -> V_43 . V_94 ;
break;
default:
return - V_107 ;
}
} else {
switch ( V_163 ) {
case V_168 :
* V_4 = V_20 -> V_43 . V_106 ;
break;
case V_169 :
* V_4 = V_20 -> V_43 . V_104 ;
break;
default:
return - V_107 ;
}
}
return V_170 ;
}
static int F_51 ( struct V_9 * V_10 ,
struct V_159 const * V_160 ,
int * V_4 ,
int * V_167 ,
long V_171 )
{
int V_5 = - V_107 ;
struct V_19 * V_20 = F_6 ( V_10 ) ;
switch ( V_171 ) {
case V_172 :
switch ( V_160 -> type ) {
case V_173 :
F_5 ( V_10 ) ;
* V_4 = V_20 -> V_25 . V_13 ;
V_5 = V_170 ;
break;
default:
return - V_107 ;
}
break;
case V_174 :
switch ( V_160 -> type ) {
case V_164 :
F_5 ( V_10 ) ;
if ( V_160 -> V_175 == 0 )
* V_4 = V_20 -> V_25 . V_36 ;
else
* V_4 = V_20 -> V_25 . V_37 ;
V_5 = V_170 ;
break;
case V_176 :
F_12 ( V_10 ) ;
* V_4 = V_20 -> V_64 ;
V_5 = V_170 ;
break;
default:
return - V_107 ;
}
break;
case V_177 :
if ( V_160 -> type == V_173 )
* V_4 =
V_42 [ V_20 -> V_43 . V_44 ] ;
else
* V_4 =
V_178 [ V_20 -> V_43 . V_112 ] ;
V_5 = V_170 ;
break;
case V_179 :
* V_4 = V_20 -> V_43 . V_46 ;
V_5 = V_170 ;
break;
default:
V_5 = - V_107 ;
}
return V_5 ;
}
static int F_52 ( struct V_9 * V_10 ,
struct V_159 const * V_160 ,
int V_4 ,
int V_167 ,
long V_171 )
{
struct V_19 * V_20 = F_6 ( V_10 ) ;
switch ( V_171 ) {
case V_177 :
if ( V_160 -> type == V_164 ) {
switch ( V_4 ) {
case 1 :
V_20 -> V_43 . V_44 = 0 ;
break;
case 8 :
V_20 -> V_43 . V_44 = 1 ;
break;
case 16 :
V_20 -> V_43 . V_44 = 2 ;
break;
case 120 :
switch ( V_20 -> V_51 ) {
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
return - V_107 ;
}
V_20 -> V_43 . V_44 = 3 ;
break;
case 128 :
switch ( V_20 -> V_51 ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
return - V_107 ;
}
V_20 -> V_43 . V_44 = 3 ;
break;
default:
return - V_107 ;
}
} else {
switch ( V_4 ) {
case 1 :
V_20 -> V_43 . V_112 = 0 ;
break;
case 2 :
V_20 -> V_43 . V_112 = 1 ;
break;
case 4 :
V_20 -> V_43 . V_112 = 2 ;
break;
case 8 :
V_20 -> V_43 . V_112 = 3 ;
break;
default:
return - V_107 ;
}
}
break;
case V_179 :
V_20 -> V_43 . V_46 = V_4 ;
break;
default:
return - V_107 ;
}
F_20 ( V_10 ) ;
return 0 ;
}
static int F_53 ( unsigned char * V_51 , int V_180 )
{
switch ( V_180 ) {
case V_52 :
case V_53 :
case V_55 :
return ( * V_51 & 0xf0 ) == V_181 ;
case V_54 :
case V_56 :
return ( * V_51 & 0xf0 ) == V_182 ;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
return ( * V_51 & 0xf0 ) == V_183 ;
}
return - V_107 ;
}
static T_7 F_54 ( int V_184 , void * V_185 )
{
struct V_9 * V_10 = V_185 ;
struct V_19 * V_20 = F_6 ( V_10 ) ;
T_8 V_186 = F_55 () ;
int V_5 ;
T_1 V_146 ;
V_146 = F_56 ( V_20 -> V_2 ,
V_6 | V_30 ) ;
if ( V_146 & V_187 ) {
F_12 ( V_10 ) ;
F_57 ( V_10 ,
F_58 ( V_176 ,
0 ,
V_188 ,
V_189 ) ,
V_186 ) ;
}
if ( V_146 & V_190 ) {
F_5 ( V_10 ) ;
F_57 ( V_10 ,
F_58 ( V_173 ,
0 ,
V_188 ,
V_189 ) ,
V_186 ) ;
}
V_5 = F_2 ( V_20 -> V_2 ,
V_6 | V_33 |
V_116 ) ;
if ( V_5 < 0 )
F_3 ( & V_20 -> V_2 -> V_7 ,
L_41 ,
V_8 , V_5 ) ;
return V_191 ;
}
static int F_59 ( struct V_1 * V_192 ,
const struct V_193 * V_51 )
{
int V_5 ;
unsigned char V_194 ;
struct V_9 * V_10 ;
struct V_19 * V_20 ;
V_10 = F_60 ( & V_192 -> V_7 , sizeof( * V_20 ) ) ;
if ( ! V_10 )
return - V_195 ;
V_20 = F_6 ( V_10 ) ;
V_20 -> V_2 = V_192 ;
F_61 ( V_192 , V_10 ) ;
V_5 = F_1 ( V_20 -> V_2 ,
V_196 , & V_194 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ( ! F_53 ( & V_194 , V_51 -> V_197 ) ) ||
( F_53 ( & V_194 , V_51 -> V_197 ) == - V_107 ) ) {
F_15 ( & V_20 -> V_2 -> V_7 ,
L_42 ,
V_8 ) ;
return - V_107 ;
}
V_5 = F_2 ( V_192 , ( V_6 | V_74 ) ) ;
if ( V_5 < 0 ) {
F_3 ( & V_192 -> V_7 , L_43 ,
V_8 , V_5 ) ;
return V_5 ;
}
F_62 ( & V_20 -> V_24 ) ;
F_62 ( & V_20 -> V_49 ) ;
V_20 -> V_26 = V_198 ;
V_20 -> V_65 = V_192 -> V_7 . V_199 ;
V_20 -> V_51 = V_51 -> V_197 ;
V_20 -> V_200 =
& V_201 [ V_202 [ V_51 -> V_197 ] ] ;
V_10 -> V_166 = V_20 -> V_200 -> V_166 ;
V_10 -> V_7 . V_203 = & V_192 -> V_7 ;
V_10 -> V_204 = V_205 ;
V_10 -> V_80 = V_20 -> V_2 -> V_80 ;
V_10 -> V_206 = V_20 -> V_200 -> V_175 ;
V_10 -> V_207 = V_20 -> V_200 -> V_208 ;
if ( V_192 -> V_184 ) {
V_5 = F_63 ( & V_192 -> V_7 , V_192 -> V_184 ,
NULL ,
& F_54 ,
V_209 |
V_210 ,
L_44 ,
V_10 ) ;
if ( V_5 ) {
F_3 ( & V_192 -> V_7 ,
L_45 , V_8 ) ;
return V_5 ;
}
}
F_13 ( V_20 ) ;
F_16 ( V_10 ) ;
V_5 = F_64 ( V_10 ) ;
if ( V_5 ) {
F_3 ( & V_192 -> V_7 ,
L_46 , V_8 ) ;
return V_5 ;
}
F_15 ( & V_192 -> V_7 , L_47 , V_51 -> V_80 ) ;
return 0 ;
}
static int F_65 ( struct V_141 * V_7 )
{
struct V_9 * V_10 = F_66 ( V_7 ) ;
struct V_19 * V_20 = F_6 ( V_10 ) ;
int V_5 = 0 ;
if ( V_20 -> V_26 == V_27 ) {
V_5 = F_19 ( V_10 ) ;
V_20 -> V_26 = V_117 ;
}
if ( V_20 -> V_65 && V_20 -> V_65 -> V_211 ) {
T_9 V_212 = { V_213 } ;
V_20 -> V_65 -> V_211 ( V_7 , V_212 ) ;
}
return V_5 ;
}
static int F_67 ( struct V_141 * V_7 )
{
struct V_9 * V_10 = F_66 ( V_7 ) ;
struct V_19 * V_20 = F_6 ( V_10 ) ;
int V_5 = 0 ;
if ( V_20 -> V_65 && V_20 -> V_65 -> V_211 ) {
T_9 V_212 = { V_214 } ;
V_20 -> V_65 -> V_211 ( V_7 , V_212 ) ;
}
if ( V_20 -> V_26 == V_117 )
V_5 = F_16 ( V_10 ) ;
return V_5 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_69 ( V_2 ) ;
F_19 ( V_10 ) ;
F_70 ( V_10 ) ;
return 0 ;
}
