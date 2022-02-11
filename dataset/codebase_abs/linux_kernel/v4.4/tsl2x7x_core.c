static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 = 0 ;
V_5 = F_2 ( V_2 , ( V_6 | V_3 ) ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_7 , L_1 , V_3 ) ;
return V_5 ;
}
V_5 = F_4 ( V_2 ) ;
if ( V_5 >= 0 )
* V_4 = ( T_1 ) V_5 ;
else
F_3 ( & V_2 -> V_7 , L_2 , V_3 ) ;
return V_5 ;
}
static int F_5 ( struct V_8 * V_9 )
{
T_2 V_10 , V_11 ;
T_3 V_12 ;
T_4 V_13 ;
T_3 V_14 ;
T_1 V_15 [ 4 ] ;
struct V_16 * V_17 ;
struct V_18 * V_19 = F_6 ( V_9 ) ;
int V_20 , V_5 ;
T_3 V_21 = 0 ;
T_3 V_22 = 0 ;
if ( F_7 ( & V_19 -> V_23 ) == 0 )
return V_19 -> V_24 . V_12 ;
if ( V_19 -> V_25 != V_26 ) {
F_3 ( & V_19 -> V_2 -> V_7 , L_3 ,
V_27 ) ;
V_5 = - V_28 ;
goto V_29;
}
V_5 = F_1 ( V_19 -> V_2 ,
( V_6 | V_30 ) , & V_15 [ 0 ] ) ;
if ( V_5 < 0 ) {
F_3 ( & V_19 -> V_2 -> V_7 ,
L_4 , V_27 ) ;
goto V_29;
}
if ( ! ( V_15 [ 0 ] & V_31 ) ) {
F_3 ( & V_19 -> V_2 -> V_7 ,
L_5 , V_27 ) ;
V_5 = V_19 -> V_24 . V_12 ;
goto V_29;
}
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ ) {
V_5 = F_1 ( V_19 -> V_2 ,
( V_6 | ( V_32 + V_20 ) ) ,
& V_15 [ V_20 ] ) ;
if ( V_5 < 0 ) {
F_3 ( & V_19 -> V_2 -> V_7 ,
L_6 , V_5 ) ;
goto V_29;
}
}
V_5 = F_2 ( V_19 -> V_2 ,
( V_6 |
V_33 |
V_34 ) ) ;
if ( V_5 < 0 ) {
F_3 ( & V_19 -> V_2 -> V_7 ,
L_7 , V_5 ) ;
goto V_29;
}
V_10 = F_8 ( ( const V_35 * ) & V_15 [ 0 ] ) ;
V_11 = F_8 ( ( const V_35 * ) & V_15 [ 2 ] ) ;
V_19 -> V_24 . V_36 = V_10 ;
V_19 -> V_24 . V_37 = V_11 ;
if ( ( V_10 >= V_19 -> V_38 ) || ( V_11 >= V_19 -> V_38 ) ) {
V_12 = V_39 ;
goto V_40;
}
if ( ! V_10 ) {
V_5 = V_19 -> V_24 . V_12 ;
goto V_29;
}
V_14 = ( V_11 << 15 ) / V_10 ;
V_17 = (struct V_16 * ) V_19 -> V_41 ;
while ( V_17 -> V_14 != 0 && V_17 -> V_14 < V_14 )
V_17 ++ ;
if ( V_17 -> V_14 == 0 ) {
V_12 = 0 ;
} else {
V_21 = F_9 ( V_10 * V_17 -> V_10 ,
V_42 [ V_19 -> V_43 . V_44 ] ) ;
V_22 = F_9 ( V_11 * V_17 -> V_11 ,
V_42 [ V_19 -> V_43 . V_44 ] ) ;
V_12 = V_21 - V_22 ;
}
if ( V_22 > V_21 ) {
F_10 ( & V_19 -> V_2 -> V_7 , L_8 ) ;
V_5 = V_19 -> V_24 . V_12 ;
goto V_29;
}
if ( V_19 -> V_45 == 0 )
V_12 = 0 ;
else
V_12 = ( V_12 + ( V_19 -> V_45 >> 1 ) ) /
V_19 -> V_45 ;
V_13 = V_12 ;
V_13 = V_13 * V_19 -> V_43 . V_46 ;
V_13 >>= 8 ;
V_12 = V_13 ;
V_12 = ( V_12 + 500 ) / 1000 ;
if ( V_12 > V_39 )
V_12 = V_39 ;
V_40:
V_19 -> V_24 . V_12 = V_12 ;
V_5 = V_12 ;
V_29:
F_11 ( & V_19 -> V_23 ) ;
return V_5 ;
}
static int F_12 ( struct V_8 * V_9 )
{
int V_20 ;
int V_5 ;
T_1 V_47 ;
T_1 V_48 [ 2 ] ;
struct V_18 * V_19 = F_6 ( V_9 ) ;
if ( F_7 ( & V_19 -> V_49 ) == 0 ) {
F_3 ( & V_19 -> V_2 -> V_7 ,
L_9 , V_27 ) ;
return - V_28 ;
}
V_5 = F_1 ( V_19 -> V_2 ,
( V_6 | V_30 ) , & V_47 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_19 -> V_2 -> V_7 , L_10 , V_5 ) ;
goto V_50;
}
switch ( V_19 -> V_51 ) {
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
for ( V_20 = 0 ; V_20 < 2 ; V_20 ++ ) {
V_5 = F_1 ( V_19 -> V_2 ,
( V_6 |
( V_63 + V_20 ) ) , & V_48 [ V_20 ] ) ;
if ( V_5 < 0 )
goto V_50;
}
V_19 -> V_64 =
F_8 ( ( const V_35 * ) & V_48 [ 0 ] ) ;
V_50:
F_11 ( & V_19 -> V_49 ) ;
return V_19 -> V_64 ;
}
static void F_13 ( struct V_18 * V_19 )
{
if ( V_19 -> V_65 && V_19 -> V_65 -> V_66 )
memcpy ( & ( V_19 -> V_43 ) ,
V_19 -> V_65 -> V_66 ,
sizeof( V_67 ) ) ;
else
memcpy ( & ( V_19 -> V_43 ) ,
& V_67 ,
sizeof( V_67 ) ) ;
if ( V_19 -> V_65 && V_19 -> V_65 -> V_68 [ 0 ] . V_14 != 0 )
memcpy ( V_19 -> V_41 ,
V_19 -> V_65 -> V_68 ,
sizeof( V_19 -> V_65 -> V_68 ) ) ;
else
memcpy ( V_19 -> V_41 ,
(struct V_16 * ) V_69 [ V_19 -> V_51 ] ,
V_70 ) ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_18 * V_19 = F_6 ( V_9 ) ;
T_1 V_71 ;
int V_72 ;
int V_5 ;
int V_73 ;
V_5 = F_2 ( V_19 -> V_2 ,
( V_6 | V_74 ) ) ;
if ( V_5 < 0 ) {
F_3 ( & V_19 -> V_2 -> V_7 ,
L_11 , V_5 ) ;
return V_5 ;
}
V_71 = F_4 ( V_19 -> V_2 ) ;
if ( ( V_71 & ( V_75 | V_76 ) )
!= ( V_75 | V_76 ) ) {
F_3 ( & V_19 -> V_2 -> V_7 ,
L_12 , V_27 ) ;
return - 1 ;
}
V_5 = F_2 ( V_19 -> V_2 ,
( V_6 | V_74 ) ) ;
if ( V_5 < 0 ) {
F_3 ( & V_19 -> V_2 -> V_7 ,
L_13 , V_5 ) ;
return V_5 ;
}
V_71 = F_4 ( V_19 -> V_2 ) ;
if ( ( V_71 & V_31 ) != V_31 ) {
F_3 ( & V_19 -> V_2 -> V_7 ,
L_14 , V_27 ) ;
return - V_77 ;
}
V_73 = F_5 ( V_9 ) ;
if ( V_73 < 0 ) {
F_3 ( & V_19 -> V_2 -> V_7 ,
L_15 , V_27 ) ;
return V_73 ;
}
V_72 = ( ( V_19 -> V_43 . V_78 )
* V_19 -> V_43 . V_46 ) / V_73 ;
if ( ( V_72 < 250 ) || ( V_72 > 4000 ) )
return - V_79 ;
V_19 -> V_43 . V_46 = V_72 ;
F_15 ( & V_19 -> V_2 -> V_7 ,
L_16 , V_19 -> V_2 -> V_80 ) ;
return ( int ) V_72 ;
}
static int F_16 ( struct V_8 * V_9 )
{
int V_20 ;
int V_5 = 0 ;
T_1 * V_81 ;
T_1 V_82 ;
int V_83 ;
int V_84 ;
struct V_18 * V_19 = F_6 ( V_9 ) ;
T_1 V_71 = 0 ;
if ( V_19 -> V_65 && V_19 -> V_65 -> V_85 )
V_19 -> V_65 -> V_85 ( V_9 ) ;
V_19 -> V_86 [ V_87 ] =
V_19 -> V_43 . V_88 ;
V_19 -> V_86 [ V_89 ] =
V_19 -> V_43 . V_90 ;
V_19 -> V_86 [ V_91 ] =
V_19 -> V_43 . V_92 ;
V_19 -> V_86 [ V_93 ] =
( V_19 -> V_43 . V_94 ) & 0xFF ;
V_19 -> V_86 [ V_95 ] =
( V_19 -> V_43 . V_94 >> 8 ) & 0xFF ;
V_19 -> V_86 [ V_96 ] =
( V_19 -> V_43 . V_97 ) & 0xFF ;
V_19 -> V_86 [ V_98 ] =
( V_19 -> V_43 . V_97 >> 8 ) & 0xFF ;
V_19 -> V_86 [ V_99 ] =
V_19 -> V_43 . V_100 ;
V_19 -> V_86 [ V_101 ] =
V_19 -> V_43 . V_102 ;
V_19 -> V_86 [ V_103 ] =
( V_19 -> V_43 . V_104 ) & 0xFF ;
V_19 -> V_86 [ V_105 ] =
( V_19 -> V_43 . V_104 >> 8 ) & 0xFF ;
V_19 -> V_86 [ V_106 ] =
( V_19 -> V_43 . V_107 ) & 0xFF ;
V_19 -> V_86 [ V_108 ] =
( V_19 -> V_43 . V_107 >> 8 ) & 0xFF ;
if ( V_19 -> V_25 == V_26 ) {
F_15 ( & V_19 -> V_2 -> V_7 , L_17 ) ;
return - V_109 ;
}
V_83 = ( V_19 -> V_43 . V_84 * 100 + 135 ) / 270 ;
if ( ! V_83 )
V_83 = 1 ;
V_84 = ( V_83 * 27 + 5 ) / 10 ;
V_19 -> V_86 [ V_110 ] = 256 - V_83 ;
V_19 -> V_86 [ V_111 ] =
( V_19 -> V_43 . V_44 |
( V_112 | V_113 )
| ( ( V_19 -> V_43 . V_114 ) << 2 ) ) ;
V_19 -> V_38 = V_83 * 922 ;
V_19 -> V_45 = ( V_84 + 25 ) / 50 ;
V_82 = V_76 ;
V_5 = F_17 ( V_19 -> V_2 ,
V_6 | V_74 , V_82 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_19 -> V_2 -> V_7 ,
L_18 , V_27 ) ;
return V_5 ;
}
for ( V_20 = 0 , V_81 = V_19 -> V_86 ;
V_20 < V_115 ; V_20 ++ ) {
V_5 = F_17 ( V_19 -> V_2 ,
V_6 + V_20 , * V_81 ++ ) ;
if ( V_5 < 0 ) {
F_3 ( & V_19 -> V_2 -> V_7 ,
L_19 , V_20 ) ;
return V_5 ;
}
}
F_18 ( 3 ) ;
V_82 = V_76 |
V_75 |
V_116 ;
V_5 = F_17 ( V_19 -> V_2 ,
V_6 | V_74 , V_82 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_19 -> V_2 -> V_7 ,
L_20 , V_27 ) ;
return V_5 ;
}
V_19 -> V_25 = V_26 ;
if ( V_19 -> V_43 . V_117 != 0 ) {
F_15 ( & V_19 -> V_2 -> V_7 , L_21 ) ;
V_71 = V_76 | V_75 ;
if ( ( V_19 -> V_43 . V_117 == 0x20 ) ||
( V_19 -> V_43 . V_117 == 0x30 ) )
V_71 |= V_116 ;
V_71 |= V_19 -> V_43 . V_117 ;
V_5 = F_17 ( V_19 -> V_2 ,
( V_6 | V_74 ) , V_71 ) ;
if ( V_5 < 0 )
F_3 ( & V_19 -> V_2 -> V_7 ,
L_22 ,
V_27 ) ;
V_5 = F_2 ( V_19 -> V_2 ,
V_6 | V_33 |
V_118 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_19 -> V_2 -> V_7 ,
L_23 ,
V_27 ) ;
return V_5 ;
}
}
return V_5 ;
}
static int F_19 ( struct V_8 * V_9 )
{
int V_5 ;
struct V_18 * V_19 = F_6 ( V_9 ) ;
V_19 -> V_25 = V_119 ;
V_5 = F_17 ( V_19 -> V_2 ,
V_6 | V_74 , 0x00 ) ;
if ( V_19 -> V_65 && V_19 -> V_65 -> V_120 )
V_19 -> V_65 -> V_120 ( V_19 -> V_2 ) ;
return V_5 ;
}
static
int F_20 ( struct V_8 * V_9 )
{
struct V_18 * V_19 = F_6 ( V_9 ) ;
int V_121 = V_19 -> V_25 ;
F_21 ( & V_19 -> V_23 ) ;
F_21 ( & V_19 -> V_49 ) ;
if ( V_121 == V_26 )
F_19 ( V_9 ) ;
F_16 ( V_9 ) ;
if ( V_121 != V_26 )
F_19 ( V_9 ) ;
F_11 ( & V_19 -> V_49 ) ;
F_11 ( & V_19 -> V_23 ) ;
return 0 ;
}
static
void F_22 ( int * V_122 , int V_123 ,
struct V_124 * V_125 )
{
int V_20 ;
int V_126 ;
int V_127 ;
if ( ! V_123 )
V_123 = 1 ;
V_126 = 0 ;
V_125 -> V_128 = V_129 ;
V_125 -> V_130 = V_131 ;
for ( V_20 = 0 ; V_20 < V_123 ; V_20 ++ ) {
V_126 += V_122 [ V_20 ] ;
V_125 -> V_128 = V_128 ( V_125 -> V_128 , V_122 [ V_20 ] ) ;
V_125 -> V_130 = V_130 ( V_125 -> V_130 , V_122 [ V_20 ] ) ;
}
V_125 -> V_132 = V_126 / V_123 ;
V_126 = 0 ;
for ( V_20 = 0 ; V_20 < V_123 ; V_20 ++ ) {
V_127 = V_122 [ V_20 ] - V_125 -> V_132 ;
V_126 += V_127 * V_127 ;
}
V_125 -> V_133 = F_23 ( ( long ) V_126 ) / V_123 ;
}
static void F_24 ( struct V_8 * V_9 )
{
int V_134 [ V_135 + 1 ] ;
int V_20 ;
struct V_124 V_136 [ 2 ] ;
struct V_124 * V_137 ;
struct V_18 * V_19 = F_6 ( V_9 ) ;
T_1 V_138 ;
T_1 V_139 = V_19 -> V_25 ;
if ( V_19 -> V_43 . V_140 > V_135 ) {
F_3 ( & V_19 -> V_2 -> V_7 ,
L_24 ,
V_19 -> V_43 . V_140 ) ;
V_19 -> V_43 . V_140 = V_135 ;
}
F_19 ( V_9 ) ;
V_138 = V_19 -> V_43 . V_117 ;
V_19 -> V_43 . V_117 |= V_141 ;
F_16 ( V_9 ) ;
for ( V_20 = 0 ; V_20 < V_19 -> V_43 . V_140 ; V_20 ++ ) {
F_18 ( 15 ) ;
F_12 ( V_9 ) ;
V_134 [ V_20 ] = V_19 -> V_64 ;
F_15 ( & V_19 -> V_2 -> V_7 , L_25 ,
V_20 , V_19 -> V_64 ) ;
}
F_19 ( V_9 ) ;
V_137 = & V_136 [ V_142 ] ;
F_22 ( V_134 ,
V_19 -> V_43 . V_140 , V_137 ) ;
V_19 -> V_43 . V_107 = ( V_137 -> V_130 << 1 ) - V_137 -> V_132 ;
F_15 ( & V_19 -> V_2 -> V_7 , L_26 ,
V_137 -> V_128 , V_137 -> V_132 , V_137 -> V_130 ) ;
F_15 ( & V_19 -> V_2 -> V_7 ,
L_27 ,
V_19 -> V_2 -> V_80 , V_19 -> V_43 . V_107 ) ;
V_19 -> V_43 . V_117 = V_138 ;
if ( V_139 == V_26 )
F_16 ( V_9 ) ;
}
static T_5 F_25 ( struct V_143 * V_7 ,
struct V_144 * V_145 , char * V_15 )
{
struct V_18 * V_19 = F_6 ( F_26 ( V_7 ) ) ;
return snprintf ( V_15 , V_146 , L_28 , V_19 -> V_25 ) ;
}
static T_5 F_27 ( struct V_143 * V_7 ,
struct V_144 * V_145 , const char * V_15 , T_6 V_147 )
{
struct V_8 * V_9 = F_26 ( V_7 ) ;
bool V_148 ;
if ( F_28 ( V_15 , & V_148 ) )
return - V_109 ;
if ( V_148 )
F_16 ( V_9 ) ;
else
F_19 ( V_9 ) ;
return V_147 ;
}
static T_5 F_29 ( struct V_143 * V_7 ,
struct V_144 * V_145 , char * V_15 )
{
struct V_18 * V_19 = F_6 ( F_26 ( V_7 ) ) ;
switch ( V_19 -> V_51 ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
return snprintf ( V_15 , V_146 , L_29 , L_30 ) ;
}
return snprintf ( V_15 , V_146 , L_29 , L_31 ) ;
}
static T_5 F_30 ( struct V_143 * V_7 ,
struct V_144 * V_145 , char * V_15 )
{
return snprintf ( V_15 , V_146 , L_29 , L_32 ) ;
}
static T_5 F_31 ( struct V_143 * V_7 ,
struct V_144 * V_145 , char * V_15 )
{
struct V_18 * V_19 = F_6 ( F_26 ( V_7 ) ) ;
int V_149 , V_150 ;
V_149 = ( V_151 - ( T_1 ) V_19 -> V_43 . V_84 ) + 1 ;
V_150 = V_149 * V_152 ;
V_149 /= 1000 ;
V_150 %= 1000 ;
return snprintf ( V_15 , V_146 , L_33 , V_149 , V_150 ) ;
}
static T_5 F_32 ( struct V_143 * V_7 ,
struct V_144 * V_145 , const char * V_15 , T_6 V_147 )
{
struct V_8 * V_9 = F_26 ( V_7 ) ;
struct V_18 * V_19 = F_6 ( V_9 ) ;
struct V_153 V_154 ;
int V_5 ;
V_5 = F_33 ( V_15 , 100 , & V_154 . integer , & V_154 . V_155 ) ;
if ( V_5 )
return V_5 ;
V_154 . V_155 /= 3 ;
V_19 -> V_43 . V_84 =
( V_151 - ( T_1 ) V_154 . V_155 ) ;
F_15 ( & V_19 -> V_2 -> V_7 , L_34 ,
V_27 , V_19 -> V_43 . V_84 ) ;
F_20 ( V_9 ) ;
return V_156 ;
}
static T_5 F_34 ( struct V_143 * V_7 ,
struct V_144 * V_145 , char * V_15 )
{
struct V_18 * V_19 = F_6 ( F_26 ( V_7 ) ) ;
return snprintf ( V_15 , V_146 , L_28 ,
V_19 -> V_43 . V_78 ) ;
}
static T_5 F_35 ( struct V_143 * V_7 ,
struct V_144 * V_145 , const char * V_15 , T_6 V_147 )
{
struct V_8 * V_9 = F_26 ( V_7 ) ;
struct V_18 * V_19 = F_6 ( V_9 ) ;
unsigned long V_148 ;
if ( F_36 ( V_15 , 0 , & V_148 ) )
return - V_109 ;
if ( V_148 )
V_19 -> V_43 . V_78 = V_148 ;
F_20 ( V_9 ) ;
return V_147 ;
}
static T_5 F_37 ( struct V_143 * V_7 ,
struct V_144 * V_145 , char * V_15 )
{
struct V_18 * V_19 = F_6 ( F_26 ( V_7 ) ) ;
int V_149 , V_150 , V_157 ;
V_149 = ( V_151 - ( T_1 ) V_19 -> V_43 . V_84 ) + 1 ;
V_150 = V_149 * V_152 ;
V_157 = V_150 * ( V_19 -> V_43 . V_100 & 0x0F ) ;
V_149 = V_157 / 1000 ;
V_150 = V_157 % 1000 ;
return snprintf ( V_15 , V_146 , L_33 , V_149 , V_150 ) ;
}
static T_5 F_38 ( struct V_143 * V_7 ,
struct V_144 * V_145 , const char * V_15 , T_6 V_147 )
{
struct V_8 * V_9 = F_26 ( V_7 ) ;
struct V_18 * V_19 = F_6 ( V_9 ) ;
struct V_153 V_154 ;
int V_149 , V_150 , V_157 ;
int V_5 ;
V_5 = F_33 ( V_15 , 100 , & V_154 . integer , & V_154 . V_155 ) ;
if ( V_5 )
return V_5 ;
V_149 = ( V_151 - ( T_1 ) V_19 -> V_43 . V_84 ) + 1 ;
V_150 = V_149 * V_152 ;
V_157 =
F_9 ( ( V_154 . integer * 1000 ) + V_154 . V_155 , V_150 ) ;
V_19 -> V_43 . V_100 &= 0xF0 ;
V_19 -> V_43 . V_100 |= ( V_157 & 0x0F ) ;
F_15 ( & V_19 -> V_2 -> V_7 , L_35 ,
V_27 , V_157 ) ;
F_20 ( V_9 ) ;
return V_156 ;
}
static T_5 F_39 ( struct V_143 * V_7 ,
struct V_144 * V_145 , char * V_15 )
{
struct V_18 * V_19 = F_6 ( F_26 ( V_7 ) ) ;
int V_149 , V_150 , V_157 ;
V_149 = ( V_151 - ( T_1 ) V_19 -> V_43 . V_88 ) + 1 ;
V_150 = V_149 * V_152 ;
V_157 = V_150 * ( ( V_19 -> V_43 . V_100 & 0xF0 ) >> 4 ) ;
V_149 = V_157 / 1000 ;
V_150 = V_157 % 1000 ;
return snprintf ( V_15 , V_146 , L_33 , V_149 , V_150 ) ;
}
static T_5 F_40 ( struct V_143 * V_7 ,
struct V_144 * V_145 , const char * V_15 , T_6 V_147 )
{
struct V_8 * V_9 = F_26 ( V_7 ) ;
struct V_18 * V_19 = F_6 ( V_9 ) ;
struct V_153 V_154 ;
int V_149 , V_150 , V_157 ;
int V_5 ;
V_5 = F_33 ( V_15 , 100 , & V_154 . integer , & V_154 . V_155 ) ;
if ( V_5 )
return V_5 ;
V_149 = ( V_151 - ( T_1 ) V_19 -> V_43 . V_88 ) + 1 ;
V_150 = V_149 * V_152 ;
V_157 =
F_9 ( ( V_154 . integer * 1000 ) + V_154 . V_155 , V_150 ) ;
V_19 -> V_43 . V_100 &= 0x0F ;
V_19 -> V_43 . V_100 |= ( ( V_157 << 4 ) & 0xF0 ) ;
F_15 ( & V_19 -> V_2 -> V_7 , L_36 ,
V_27 , V_157 ) ;
F_20 ( V_9 ) ;
return V_156 ;
}
static T_5 F_41 ( struct V_143 * V_7 ,
struct V_144 * V_145 , const char * V_15 , T_6 V_147 )
{
struct V_8 * V_9 = F_26 ( V_7 ) ;
bool V_148 ;
if ( F_28 ( V_15 , & V_148 ) )
return - V_109 ;
if ( V_148 )
F_14 ( V_9 ) ;
F_20 ( V_9 ) ;
return V_147 ;
}
static T_5 F_42 ( struct V_143 * V_7 ,
struct V_144 * V_145 , char * V_15 )
{
struct V_18 * V_19 = F_6 ( F_26 ( V_7 ) ) ;
int V_20 = 0 ;
int V_158 = 0 ;
while ( V_20 < ( V_159 * 3 ) ) {
V_158 += snprintf ( V_15 + V_158 , V_146 , L_37 ,
V_19 -> V_41 [ V_20 ] . V_14 ,
V_19 -> V_41 [ V_20 ] . V_10 ,
V_19 -> V_41 [ V_20 ] . V_11 ) ;
if ( V_19 -> V_41 [ V_20 ] . V_14 == 0 ) {
V_158 -- ;
break;
}
V_20 ++ ;
}
V_158 += snprintf ( V_15 + V_158 , V_146 , L_38 ) ;
return V_158 ;
}
static T_5 F_43 ( struct V_143 * V_7 ,
struct V_144 * V_145 , const char * V_15 , T_6 V_147 )
{
struct V_8 * V_9 = F_26 ( V_7 ) ;
struct V_18 * V_19 = F_6 ( V_9 ) ;
int V_148 [ F_44 ( V_19 -> V_41 ) * 3 + 1 ] ;
int V_160 ;
F_45 ( V_15 , F_44 ( V_148 ) , V_148 ) ;
V_160 = V_148 [ 0 ] ;
if ( ( V_160 % 3 ) || V_160 < 6 ||
V_160 > ( ( F_44 ( V_19 -> V_41 ) - 1 ) * 3 ) ) {
F_15 ( V_7 , L_39 , V_160 ) ;
return - V_109 ;
}
if ( ( V_148 [ ( V_160 - 2 ) ] | V_148 [ ( V_160 - 1 ) ] | V_148 [ V_160 ] ) != 0 ) {
F_15 ( V_7 , L_40 , V_160 ) ;
return - V_109 ;
}
if ( V_19 -> V_25 == V_26 )
F_19 ( V_9 ) ;
memset ( V_19 -> V_41 , 0 , sizeof( V_19 -> V_41 ) ) ;
memcpy ( V_19 -> V_41 , & V_148 [ 1 ] , ( V_148 [ 0 ] * 4 ) ) ;
F_20 ( V_9 ) ;
return V_147 ;
}
static T_5 F_46 ( struct V_143 * V_7 ,
struct V_144 * V_145 , const char * V_15 , T_6 V_147 )
{
struct V_8 * V_9 = F_26 ( V_7 ) ;
bool V_148 ;
if ( F_28 ( V_15 , & V_148 ) )
return - V_109 ;
if ( V_148 )
F_24 ( V_9 ) ;
F_20 ( V_9 ) ;
return V_147 ;
}
static int F_47 ( struct V_8 * V_9 ,
const struct V_161 * V_162 ,
enum V_163 type ,
enum V_164 V_165 )
{
struct V_18 * V_19 = F_6 ( V_9 ) ;
int V_5 ;
if ( V_162 -> type == V_166 )
V_5 = ! ! ( V_19 -> V_43 . V_117 & 0x10 ) ;
else
V_5 = ! ! ( V_19 -> V_43 . V_117 & 0x20 ) ;
return V_5 ;
}
static int F_48 ( struct V_8 * V_9 ,
const struct V_161 * V_162 ,
enum V_163 type ,
enum V_164 V_165 ,
int V_4 )
{
struct V_18 * V_19 = F_6 ( V_9 ) ;
if ( V_162 -> type == V_166 ) {
if ( V_4 )
V_19 -> V_43 . V_117 |= 0x10 ;
else
V_19 -> V_43 . V_117 &= 0x20 ;
} else {
if ( V_4 )
V_19 -> V_43 . V_117 |= 0x20 ;
else
V_19 -> V_43 . V_117 &= 0x10 ;
}
F_20 ( V_9 ) ;
return 0 ;
}
static int F_49 ( struct V_8 * V_9 ,
const struct V_161 * V_162 ,
enum V_163 type ,
enum V_164 V_165 ,
enum V_167 V_168 ,
int V_4 , int V_169 )
{
struct V_18 * V_19 = F_6 ( V_9 ) ;
if ( V_162 -> type == V_166 ) {
switch ( V_165 ) {
case V_170 :
V_19 -> V_43 . V_97 = V_4 ;
break;
case V_171 :
V_19 -> V_43 . V_94 = V_4 ;
break;
default:
return - V_109 ;
}
} else {
switch ( V_165 ) {
case V_170 :
V_19 -> V_43 . V_107 = V_4 ;
break;
case V_171 :
V_19 -> V_43 . V_104 = V_4 ;
break;
default:
return - V_109 ;
}
}
F_20 ( V_9 ) ;
return 0 ;
}
static int F_50 ( struct V_8 * V_9 ,
const struct V_161 * V_162 ,
enum V_163 type ,
enum V_164 V_165 ,
enum V_167 V_168 ,
int * V_4 , int * V_169 )
{
struct V_18 * V_19 = F_6 ( V_9 ) ;
if ( V_162 -> type == V_166 ) {
switch ( V_165 ) {
case V_170 :
* V_4 = V_19 -> V_43 . V_97 ;
break;
case V_171 :
* V_4 = V_19 -> V_43 . V_94 ;
break;
default:
return - V_109 ;
}
} else {
switch ( V_165 ) {
case V_170 :
* V_4 = V_19 -> V_43 . V_107 ;
break;
case V_171 :
* V_4 = V_19 -> V_43 . V_104 ;
break;
default:
return - V_109 ;
}
}
return V_172 ;
}
static int F_51 ( struct V_8 * V_9 ,
struct V_161 const * V_162 ,
int * V_4 ,
int * V_169 ,
long V_173 )
{
int V_5 = - V_109 ;
struct V_18 * V_19 = F_6 ( V_9 ) ;
switch ( V_173 ) {
case V_174 :
switch ( V_162 -> type ) {
case V_175 :
F_5 ( V_9 ) ;
* V_4 = V_19 -> V_24 . V_12 ;
V_5 = V_172 ;
break;
default:
return - V_109 ;
}
break;
case V_176 :
switch ( V_162 -> type ) {
case V_166 :
F_5 ( V_9 ) ;
if ( V_162 -> V_177 == 0 )
* V_4 = V_19 -> V_24 . V_36 ;
else
* V_4 = V_19 -> V_24 . V_37 ;
V_5 = V_172 ;
break;
case V_178 :
F_12 ( V_9 ) ;
* V_4 = V_19 -> V_64 ;
V_5 = V_172 ;
break;
default:
return - V_109 ;
}
break;
case V_179 :
if ( V_162 -> type == V_175 )
* V_4 =
V_42 [ V_19 -> V_43 . V_44 ] ;
else
* V_4 =
V_180 [ V_19 -> V_43 . V_114 ] ;
V_5 = V_172 ;
break;
case V_181 :
* V_4 = V_19 -> V_43 . V_46 ;
V_5 = V_172 ;
break;
default:
V_5 = - V_109 ;
}
return V_5 ;
}
static int F_52 ( struct V_8 * V_9 ,
struct V_161 const * V_162 ,
int V_4 ,
int V_169 ,
long V_173 )
{
struct V_18 * V_19 = F_6 ( V_9 ) ;
switch ( V_173 ) {
case V_179 :
if ( V_162 -> type == V_166 ) {
switch ( V_4 ) {
case 1 :
V_19 -> V_43 . V_44 = 0 ;
break;
case 8 :
V_19 -> V_43 . V_44 = 1 ;
break;
case 16 :
V_19 -> V_43 . V_44 = 2 ;
break;
case 120 :
switch ( V_19 -> V_51 ) {
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
return - V_109 ;
}
V_19 -> V_43 . V_44 = 3 ;
break;
case 128 :
switch ( V_19 -> V_51 ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
return - V_109 ;
}
V_19 -> V_43 . V_44 = 3 ;
break;
default:
return - V_109 ;
}
} else {
switch ( V_4 ) {
case 1 :
V_19 -> V_43 . V_114 = 0 ;
break;
case 2 :
V_19 -> V_43 . V_114 = 1 ;
break;
case 4 :
V_19 -> V_43 . V_114 = 2 ;
break;
case 8 :
V_19 -> V_43 . V_114 = 3 ;
break;
default:
return - V_109 ;
}
}
break;
case V_181 :
V_19 -> V_43 . V_46 = V_4 ;
break;
default:
return - V_109 ;
}
F_20 ( V_9 ) ;
return 0 ;
}
static int F_53 ( unsigned char * V_51 , int V_182 )
{
switch ( V_182 ) {
case V_52 :
case V_53 :
case V_55 :
return ( * V_51 & 0xf0 ) == V_183 ;
case V_54 :
case V_56 :
return ( * V_51 & 0xf0 ) == V_184 ;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
return ( * V_51 & 0xf0 ) == V_185 ;
}
return - V_109 ;
}
static T_7 F_54 ( int V_186 , void * V_187 )
{
struct V_8 * V_9 = V_187 ;
struct V_18 * V_19 = F_6 ( V_9 ) ;
T_8 V_188 = F_55 () ;
int V_5 ;
T_1 V_148 ;
V_148 = F_56 ( V_19 -> V_2 ,
V_6 | V_30 ) ;
if ( V_148 & V_189 ) {
F_12 ( V_9 ) ;
F_57 ( V_9 ,
F_58 ( V_178 ,
0 ,
V_190 ,
V_191 ) ,
V_188 ) ;
}
if ( V_148 & V_192 ) {
F_5 ( V_9 ) ;
F_57 ( V_9 ,
F_58 ( V_175 ,
0 ,
V_190 ,
V_191 ) ,
V_188 ) ;
}
V_5 = F_2 ( V_19 -> V_2 ,
V_6 | V_33 |
V_118 ) ;
if ( V_5 < 0 )
F_3 ( & V_19 -> V_2 -> V_7 ,
L_41 ,
V_5 ) ;
return V_193 ;
}
static int F_59 ( struct V_1 * V_194 ,
const struct V_195 * V_51 )
{
int V_5 ;
unsigned char V_196 ;
struct V_8 * V_9 ;
struct V_18 * V_19 ;
V_9 = F_60 ( & V_194 -> V_7 , sizeof( * V_19 ) ) ;
if ( ! V_9 )
return - V_197 ;
V_19 = F_6 ( V_9 ) ;
V_19 -> V_2 = V_194 ;
F_61 ( V_194 , V_9 ) ;
V_5 = F_1 ( V_19 -> V_2 ,
V_198 , & V_196 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ( ! F_53 ( & V_196 , V_51 -> V_199 ) ) ||
( F_53 ( & V_196 , V_51 -> V_199 ) == - V_109 ) ) {
F_15 ( & V_19 -> V_2 -> V_7 ,
L_42 ,
V_27 ) ;
return - V_109 ;
}
V_5 = F_2 ( V_194 , ( V_6 | V_74 ) ) ;
if ( V_5 < 0 ) {
F_3 ( & V_194 -> V_7 , L_43 ,
V_5 ) ;
return V_5 ;
}
F_62 ( & V_19 -> V_23 ) ;
F_62 ( & V_19 -> V_49 ) ;
V_19 -> V_25 = V_200 ;
V_19 -> V_65 = V_194 -> V_7 . V_201 ;
V_19 -> V_51 = V_51 -> V_199 ;
V_19 -> V_202 =
& V_203 [ V_204 [ V_51 -> V_199 ] ] ;
V_9 -> V_168 = V_19 -> V_202 -> V_168 ;
V_9 -> V_7 . V_205 = & V_194 -> V_7 ;
V_9 -> V_206 = V_207 ;
V_9 -> V_80 = V_19 -> V_2 -> V_80 ;
V_9 -> V_208 = V_19 -> V_202 -> V_177 ;
V_9 -> V_209 = V_19 -> V_202 -> V_210 ;
if ( V_194 -> V_186 ) {
V_5 = F_63 ( & V_194 -> V_7 , V_194 -> V_186 ,
NULL ,
& F_54 ,
V_211 |
V_212 ,
L_44 ,
V_9 ) ;
if ( V_5 ) {
F_3 ( & V_194 -> V_7 ,
L_45 , V_27 ) ;
return V_5 ;
}
}
F_13 ( V_19 ) ;
F_16 ( V_9 ) ;
V_5 = F_64 ( V_9 ) ;
if ( V_5 ) {
F_3 ( & V_194 -> V_7 ,
L_46 , V_27 ) ;
return V_5 ;
}
F_15 ( & V_194 -> V_7 , L_47 , V_51 -> V_80 ) ;
return 0 ;
}
static int F_65 ( struct V_143 * V_7 )
{
struct V_8 * V_9 = F_66 ( V_7 ) ;
struct V_18 * V_19 = F_6 ( V_9 ) ;
int V_5 = 0 ;
if ( V_19 -> V_25 == V_26 ) {
V_5 = F_19 ( V_9 ) ;
V_19 -> V_25 = V_119 ;
}
if ( V_19 -> V_65 && V_19 -> V_65 -> V_213 ) {
T_9 V_214 = { V_215 } ;
V_19 -> V_65 -> V_213 ( V_7 , V_214 ) ;
}
return V_5 ;
}
static int F_67 ( struct V_143 * V_7 )
{
struct V_8 * V_9 = F_66 ( V_7 ) ;
struct V_18 * V_19 = F_6 ( V_9 ) ;
int V_5 = 0 ;
if ( V_19 -> V_65 && V_19 -> V_65 -> V_213 ) {
T_9 V_214 = { V_216 } ;
V_19 -> V_65 -> V_213 ( V_7 , V_214 ) ;
}
if ( V_19 -> V_25 == V_119 )
V_5 = F_16 ( V_9 ) ;
return V_5 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_69 ( V_2 ) ;
F_19 ( V_9 ) ;
F_70 ( V_9 ) ;
return 0 ;
}
