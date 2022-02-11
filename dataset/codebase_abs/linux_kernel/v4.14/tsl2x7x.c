static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
T_2 V_5 ;
T_3 V_6 ;
T_2 V_7 ;
T_4 V_8 [ 4 ] ;
struct V_9 * V_10 ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
int V_13 , V_14 ;
T_2 V_15 = 0 ;
T_2 V_16 = 0 ;
if ( F_3 ( & V_12 -> V_17 ) == 0 )
return V_12 -> V_18 . V_5 ;
if ( V_12 -> V_19 != V_20 ) {
F_4 ( & V_12 -> V_21 -> V_22 , L_1 ,
V_23 ) ;
V_14 = - V_24 ;
goto V_25;
}
V_14 = F_5 ( V_12 -> V_21 ,
V_26 | V_27 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_12 -> V_21 -> V_22 ,
L_2 , V_23 ) ;
goto V_25;
}
if ( ! ( V_14 & V_28 ) ) {
F_4 ( & V_12 -> V_21 -> V_22 ,
L_3 , V_23 ) ;
V_14 = V_12 -> V_18 . V_5 ;
goto V_25;
}
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
int V_29 = V_26 | ( V_30 + V_13 ) ;
V_14 = F_5 ( V_12 -> V_21 , V_29 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_12 -> V_21 -> V_22 ,
L_4 , V_14 ) ;
goto V_25;
}
V_8 [ V_13 ] = V_14 ;
}
V_14 = F_6 ( V_12 -> V_21 ,
( V_26 |
V_31 |
V_32 ) ) ;
if ( V_14 < 0 ) {
F_4 ( & V_12 -> V_21 -> V_22 ,
L_5 , V_14 ) ;
goto V_25;
}
V_3 = F_7 ( ( const V_33 * ) & V_8 [ 0 ] ) ;
V_4 = F_7 ( ( const V_33 * ) & V_8 [ 2 ] ) ;
V_12 -> V_18 . V_34 = V_3 ;
V_12 -> V_18 . V_35 = V_4 ;
if ( ( V_3 >= V_12 -> V_36 ) || ( V_4 >= V_12 -> V_36 ) ) {
V_5 = V_37 ;
goto V_38;
}
if ( ! V_3 ) {
V_14 = V_12 -> V_18 . V_5 ;
goto V_25;
}
V_7 = ( V_4 << 15 ) / V_3 ;
V_10 = (struct V_9 * ) V_12 -> V_39 ;
while ( V_10 -> V_7 != 0 && V_10 -> V_7 < V_7 )
V_10 ++ ;
if ( V_10 -> V_7 == 0 ) {
V_5 = 0 ;
} else {
V_15 = F_8 ( V_3 * V_10 -> V_3 ,
V_40 [ V_12 -> V_41 . V_42 ] ) ;
V_16 = F_8 ( V_4 * V_10 -> V_4 ,
V_40 [ V_12 -> V_41 . V_42 ] ) ;
V_5 = V_15 - V_16 ;
}
if ( V_16 > V_15 ) {
F_9 ( & V_12 -> V_21 -> V_22 , L_6 ) ;
V_14 = V_12 -> V_18 . V_5 ;
goto V_25;
}
if ( V_12 -> V_43 == 0 )
V_5 = 0 ;
else
V_5 = ( V_5 + ( V_12 -> V_43 >> 1 ) ) /
V_12 -> V_43 ;
V_6 = V_5 ;
V_6 = V_6 * V_12 -> V_41 . V_44 ;
V_6 >>= 8 ;
V_5 = V_6 ;
V_5 = ( V_5 + 500 ) / 1000 ;
if ( V_5 > V_37 )
V_5 = V_37 ;
V_38:
V_12 -> V_18 . V_5 = V_5 ;
V_14 = V_5 ;
V_25:
F_10 ( & V_12 -> V_17 ) ;
return V_14 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_13 ;
int V_14 ;
T_4 V_45 [ 2 ] ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
if ( F_3 ( & V_12 -> V_46 ) == 0 ) {
F_4 ( & V_12 -> V_21 -> V_22 ,
L_7 , V_23 ) ;
return - V_24 ;
}
V_14 = F_5 ( V_12 -> V_21 ,
V_26 | V_27 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_12 -> V_21 -> V_22 , L_8 , V_14 ) ;
goto V_47;
}
switch ( V_12 -> V_48 ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
if ( ! ( V_14 & V_28 ) )
goto V_47;
break;
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
if ( ! ( V_14 & V_59 ) )
goto V_47;
break;
}
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ ) {
int V_29 = V_26 | ( V_60 + V_13 ) ;
V_14 = F_5 ( V_12 -> V_21 , V_29 ) ;
if ( V_14 < 0 )
goto V_47;
V_45 [ V_13 ] = V_14 ;
}
V_12 -> V_61 =
F_7 ( ( const V_33 * ) & V_45 [ 0 ] ) ;
V_47:
F_10 ( & V_12 -> V_46 ) ;
return V_12 -> V_61 ;
}
static void F_12 ( struct V_11 * V_12 )
{
if ( V_12 -> V_62 && V_12 -> V_62 -> V_63 )
memcpy ( & V_12 -> V_41 ,
V_12 -> V_62 -> V_63 ,
sizeof( V_64 ) ) ;
else
memcpy ( & V_12 -> V_41 ,
& V_64 ,
sizeof( V_64 ) ) ;
if ( V_12 -> V_62 && V_12 -> V_62 -> V_65 [ 0 ] . V_7 != 0 )
memcpy ( V_12 -> V_39 ,
V_12 -> V_62 -> V_65 ,
sizeof( V_12 -> V_62 -> V_65 ) ) ;
else
memcpy ( V_12 -> V_39 ,
(struct V_9 * ) V_66 [ V_12 -> V_48 ] ,
V_67 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_2 ( V_2 ) ;
int V_68 ;
int V_14 ;
int V_69 ;
V_14 = F_5 ( V_12 -> V_21 ,
V_26 | V_70 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_12 -> V_21 -> V_22 ,
L_9 ,
V_23 ) ;
return V_14 ;
}
if ( ( V_14 & ( V_71 | V_72 ) )
!= ( V_71 | V_72 ) ) {
F_4 ( & V_12 -> V_21 -> V_22 ,
L_10 ,
V_23 ) ;
return - V_73 ;
} else if ( ( V_14 & V_28 ) != V_28 ) {
F_4 ( & V_12 -> V_21 -> V_22 ,
L_11 ,
V_23 ) ;
return - V_74 ;
}
V_69 = F_1 ( V_2 ) ;
if ( V_69 < 0 ) {
F_4 ( & V_12 -> V_21 -> V_22 ,
L_12 , V_23 ) ;
return V_69 ;
}
V_68 = ( ( V_12 -> V_41 . V_75 )
* V_12 -> V_41 . V_44 ) / V_69 ;
if ( ( V_68 < 250 ) || ( V_68 > 4000 ) )
return - V_76 ;
V_12 -> V_41 . V_44 = V_68 ;
F_14 ( & V_12 -> V_21 -> V_22 ,
L_13 , V_12 -> V_21 -> V_77 ) ;
return ( int ) V_68 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_13 ;
int V_14 = 0 ;
T_4 * V_78 ;
T_4 V_79 ;
int V_80 ;
int V_81 ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
T_4 V_82 = 0 ;
if ( V_12 -> V_62 && V_12 -> V_62 -> V_83 )
V_12 -> V_62 -> V_83 ( V_2 ) ;
V_12 -> V_84 [ V_85 ] =
V_12 -> V_41 . V_86 ;
V_12 -> V_84 [ V_87 ] =
V_12 -> V_41 . V_88 ;
V_12 -> V_84 [ V_89 ] =
V_12 -> V_41 . V_90 ;
V_12 -> V_84 [ V_91 ] =
( V_12 -> V_41 . V_92 ) & 0xFF ;
V_12 -> V_84 [ V_93 ] =
( V_12 -> V_41 . V_92 >> 8 ) & 0xFF ;
V_12 -> V_84 [ V_94 ] =
( V_12 -> V_41 . V_95 ) & 0xFF ;
V_12 -> V_84 [ V_96 ] =
( V_12 -> V_41 . V_95 >> 8 ) & 0xFF ;
V_12 -> V_84 [ V_97 ] =
V_12 -> V_41 . V_98 ;
V_12 -> V_84 [ V_99 ] =
V_12 -> V_41 . V_100 ;
V_12 -> V_84 [ V_101 ] =
( V_12 -> V_41 . V_102 ) & 0xFF ;
V_12 -> V_84 [ V_103 ] =
( V_12 -> V_41 . V_102 >> 8 ) & 0xFF ;
V_12 -> V_84 [ V_104 ] =
( V_12 -> V_41 . V_105 ) & 0xFF ;
V_12 -> V_84 [ V_106 ] =
( V_12 -> V_41 . V_105 >> 8 ) & 0xFF ;
if ( V_12 -> V_19 == V_20 ) {
F_14 ( & V_12 -> V_21 -> V_22 , L_14 ) ;
return - V_73 ;
}
V_80 = ( V_12 -> V_41 . V_81 * 100 + 135 ) / 270 ;
if ( ! V_80 )
V_80 = 1 ;
V_81 = ( V_80 * 27 + 5 ) / 10 ;
V_12 -> V_84 [ V_107 ] = 256 - V_80 ;
V_12 -> V_84 [ V_108 ] =
V_12 -> V_41 . V_42 |
( V_109 | V_110 )
| ( ( V_12 -> V_41 . V_111 ) << 2 ) ;
V_12 -> V_36 = V_80 * 922 ;
V_12 -> V_43 = ( V_81 + 25 ) / 50 ;
V_79 = V_72 ;
V_14 = F_16 ( V_12 -> V_21 ,
V_26 | V_70 , V_79 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_12 -> V_21 -> V_22 ,
L_15 , V_23 ) ;
return V_14 ;
}
for ( V_13 = 0 , V_78 = V_12 -> V_84 ;
V_13 < V_112 ; V_13 ++ ) {
V_14 = F_16 ( V_12 -> V_21 ,
V_26 + V_13 ,
* V_78 ++ ) ;
if ( V_14 < 0 ) {
F_4 ( & V_12 -> V_21 -> V_22 ,
L_16 , V_13 ) ;
return V_14 ;
}
}
F_17 ( 3000 , 3500 ) ;
V_79 = V_72 |
V_71 |
V_113 ;
V_14 = F_16 ( V_12 -> V_21 ,
V_26 | V_70 , V_79 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_12 -> V_21 -> V_22 ,
L_17 , V_23 ) ;
return V_14 ;
}
V_12 -> V_19 = V_20 ;
if ( V_12 -> V_41 . V_114 != 0 ) {
F_14 ( & V_12 -> V_21 -> V_22 , L_18 ) ;
V_82 = V_72 | V_71 ;
if ( ( V_12 -> V_41 . V_114 == 0x20 ) ||
( V_12 -> V_41 . V_114 == 0x30 ) )
V_82 |= V_113 ;
V_82 |= V_12 -> V_41 . V_114 ;
V_14 = F_16 ( V_12 -> V_21 ,
( V_26 |
V_70 ) , V_82 ) ;
if ( V_14 < 0 )
F_4 ( & V_12 -> V_21 -> V_22 ,
L_19 ,
V_23 ) ;
V_14 = F_6 ( V_12 -> V_21 ,
V_26 |
V_31 |
V_115 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_12 -> V_21 -> V_22 ,
L_20 ,
V_23 ) ;
return V_14 ;
}
}
return V_14 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_14 ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
V_12 -> V_19 = V_116 ;
V_14 = F_16 ( V_12 -> V_21 ,
V_26 | V_70 , 0x00 ) ;
if ( V_12 -> V_62 && V_12 -> V_62 -> V_117 )
V_12 -> V_62 -> V_117 ( V_12 -> V_21 ) ;
return V_14 ;
}
static
int F_19 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_2 ( V_2 ) ;
int V_118 = V_12 -> V_19 ;
int V_14 ;
F_20 ( & V_12 -> V_17 ) ;
F_20 ( & V_12 -> V_46 ) ;
if ( V_118 == V_20 ) {
V_14 = F_18 ( V_2 ) ;
if ( V_14 < 0 )
goto V_119;
}
V_14 = F_15 ( V_2 ) ;
V_119:
F_10 ( & V_12 -> V_46 ) ;
F_10 ( & V_12 -> V_17 ) ;
return V_14 ;
}
static
void F_21 ( int * V_120 , int V_121 ,
struct V_122 * V_123 )
{
int V_13 ;
int V_124 ;
int V_125 ;
if ( ! V_121 )
V_121 = 1 ;
V_124 = 0 ;
V_123 -> V_126 = V_127 ;
V_123 -> V_128 = V_129 ;
for ( V_13 = 0 ; V_13 < V_121 ; V_13 ++ ) {
V_124 += V_120 [ V_13 ] ;
V_123 -> V_126 = V_126 ( V_123 -> V_126 , V_120 [ V_13 ] ) ;
V_123 -> V_128 = V_128 ( V_123 -> V_128 , V_120 [ V_13 ] ) ;
}
V_123 -> V_130 = V_124 / V_121 ;
V_124 = 0 ;
for ( V_13 = 0 ; V_13 < V_121 ; V_13 ++ ) {
V_125 = V_120 [ V_13 ] - V_123 -> V_130 ;
V_124 += V_125 * V_125 ;
}
V_123 -> V_131 = F_22 ( ( long ) V_124 / V_121 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
int V_132 [ V_133 + 1 ] ;
int V_13 ;
struct V_122 V_134 [ 2 ] ;
struct V_122 * V_135 ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
T_4 V_136 ;
T_4 V_137 = V_12 -> V_19 ;
if ( V_12 -> V_41 . V_138 > V_133 ) {
F_4 ( & V_12 -> V_21 -> V_22 ,
L_21 ,
V_12 -> V_41 . V_138 ) ;
V_12 -> V_41 . V_138 = V_133 ;
}
F_18 ( V_2 ) ;
V_136 = V_12 -> V_41 . V_114 ;
V_12 -> V_41 . V_114 |= V_139 ;
F_15 ( V_2 ) ;
for ( V_13 = 0 ; V_13 < V_12 -> V_41 . V_138 ; V_13 ++ ) {
F_17 ( 15000 , 17500 ) ;
F_11 ( V_2 ) ;
V_132 [ V_13 ] = V_12 -> V_61 ;
F_14 ( & V_12 -> V_21 -> V_22 , L_22 ,
V_13 , V_12 -> V_61 ) ;
}
F_18 ( V_2 ) ;
V_135 = & V_134 [ V_140 ] ;
F_21 ( V_132 ,
V_12 -> V_41 . V_138 ,
V_135 ) ;
V_12 -> V_41 . V_105 = ( V_135 -> V_128 << 1 ) - V_135 -> V_130 ;
F_14 ( & V_12 -> V_21 -> V_22 , L_23 ,
V_135 -> V_126 , V_135 -> V_130 , V_135 -> V_128 ) ;
F_14 ( & V_12 -> V_21 -> V_22 ,
L_24 ,
V_12 -> V_21 -> V_77 , V_12 -> V_41 . V_105 ) ;
V_12 -> V_41 . V_114 = V_136 ;
if ( V_137 == V_20 )
F_15 ( V_2 ) ;
}
static T_5 F_24 ( struct V_141 * V_22 ,
struct V_142 * V_143 ,
char * V_8 )
{
struct V_11 * V_12 = F_2 ( F_25 ( V_22 ) ) ;
switch ( V_12 -> V_48 ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
return snprintf ( V_8 , V_144 , L_25 , L_26 ) ;
}
return snprintf ( V_8 , V_144 , L_25 , L_27 ) ;
}
static T_5 F_26 ( struct V_141 * V_22 ,
struct V_142 * V_143 ,
char * V_8 )
{
return snprintf ( V_8 , V_144 , L_25 , L_28 ) ;
}
static T_5 F_27 ( struct V_141 * V_22 ,
struct V_142 * V_143 ,
char * V_8 )
{
struct V_11 * V_12 = F_2 ( F_25 ( V_22 ) ) ;
int V_145 , V_146 ;
V_145 = ( V_147 - ( T_4 ) V_12 -> V_41 . V_81 ) + 1 ;
V_146 = V_145 * V_148 ;
V_145 /= 1000 ;
V_146 %= 1000 ;
return snprintf ( V_8 , V_144 , L_29 , V_145 , V_146 ) ;
}
static T_5 F_28 ( struct V_141 * V_22 ,
struct V_142 * V_143 ,
const char * V_8 , T_6 V_149 )
{
struct V_1 * V_2 = F_25 ( V_22 ) ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
struct V_150 V_151 ;
int V_14 ;
V_14 = F_29 ( V_8 , 100 , & V_151 . integer , & V_151 . V_152 ) ;
if ( V_14 )
return V_14 ;
V_151 . V_152 /= 3 ;
V_12 -> V_41 . V_81 =
V_147 - ( T_4 ) V_151 . V_152 ;
F_14 ( & V_12 -> V_21 -> V_22 , L_30 ,
V_23 , V_12 -> V_41 . V_81 ) ;
F_19 ( V_2 ) ;
return V_153 ;
}
static T_5 F_30 ( struct V_141 * V_22 ,
struct V_142 * V_143 ,
char * V_8 )
{
struct V_11 * V_12 = F_2 ( F_25 ( V_22 ) ) ;
return snprintf ( V_8 , V_144 , L_31 ,
V_12 -> V_41 . V_75 ) ;
}
static T_5 F_31 ( struct V_141 * V_22 ,
struct V_142 * V_143 ,
const char * V_8 , T_6 V_149 )
{
struct V_1 * V_2 = F_25 ( V_22 ) ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
unsigned long V_154 ;
int V_14 ;
if ( F_32 ( V_8 , 0 , & V_154 ) )
return - V_73 ;
if ( V_154 )
V_12 -> V_41 . V_75 = V_154 ;
V_14 = F_19 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_149 ;
}
static T_5 F_33 ( struct V_141 * V_22 ,
struct V_142 * V_143 ,
char * V_8 )
{
struct V_11 * V_12 = F_2 ( F_25 ( V_22 ) ) ;
int V_145 , V_146 , V_155 ;
V_145 = ( V_147 - ( T_4 ) V_12 -> V_41 . V_81 ) + 1 ;
V_146 = V_145 * V_148 ;
V_155 = V_146 * ( V_12 -> V_41 . V_98 & 0x0F ) ;
V_145 = V_155 / 1000 ;
V_146 = V_155 % 1000 ;
return snprintf ( V_8 , V_144 , L_29 , V_145 , V_146 ) ;
}
static T_5 F_34 ( struct V_141 * V_22 ,
struct V_142 * V_143 ,
const char * V_8 , T_6 V_149 )
{
struct V_1 * V_2 = F_25 ( V_22 ) ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
struct V_150 V_151 ;
int V_145 , V_146 , V_155 ;
int V_14 ;
V_14 = F_29 ( V_8 , 100 , & V_151 . integer , & V_151 . V_152 ) ;
if ( V_14 )
return V_14 ;
V_145 = ( V_147 - ( T_4 ) V_12 -> V_41 . V_81 ) + 1 ;
V_146 = V_145 * V_148 ;
V_155 =
F_8 ( ( V_151 . integer * 1000 ) + V_151 . V_152 , V_146 ) ;
V_12 -> V_41 . V_98 &= 0xF0 ;
V_12 -> V_41 . V_98 |= ( V_155 & 0x0F ) ;
F_14 ( & V_12 -> V_21 -> V_22 , L_32 ,
V_23 , V_155 ) ;
V_14 = F_19 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_153 ;
}
static T_5 F_35 ( struct V_141 * V_22 ,
struct V_142 * V_143 ,
char * V_8 )
{
struct V_11 * V_12 = F_2 ( F_25 ( V_22 ) ) ;
int V_145 , V_146 , V_155 ;
V_145 = ( V_147 - ( T_4 ) V_12 -> V_41 . V_86 ) + 1 ;
V_146 = V_145 * V_148 ;
V_155 = V_146 * ( ( V_12 -> V_41 . V_98 & 0xF0 ) >> 4 ) ;
V_145 = V_155 / 1000 ;
V_146 = V_155 % 1000 ;
return snprintf ( V_8 , V_144 , L_29 , V_145 , V_146 ) ;
}
static T_5 F_36 ( struct V_141 * V_22 ,
struct V_142 * V_143 ,
const char * V_8 , T_6 V_149 )
{
struct V_1 * V_2 = F_25 ( V_22 ) ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
struct V_150 V_151 ;
int V_145 , V_146 , V_155 ;
int V_14 ;
V_14 = F_29 ( V_8 , 100 , & V_151 . integer , & V_151 . V_152 ) ;
if ( V_14 )
return V_14 ;
V_145 = ( V_147 - ( T_4 ) V_12 -> V_41 . V_86 ) + 1 ;
V_146 = V_145 * V_148 ;
V_155 =
F_8 ( ( V_151 . integer * 1000 ) + V_151 . V_152 , V_146 ) ;
V_12 -> V_41 . V_98 &= 0x0F ;
V_12 -> V_41 . V_98 |= ( ( V_155 << 4 ) & 0xF0 ) ;
F_14 ( & V_12 -> V_21 -> V_22 , L_33 ,
V_23 , V_155 ) ;
V_14 = F_19 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_153 ;
}
static T_5 F_37 ( struct V_141 * V_22 ,
struct V_142 * V_143 ,
const char * V_8 , T_6 V_149 )
{
struct V_1 * V_2 = F_25 ( V_22 ) ;
bool V_154 ;
int V_14 ;
if ( F_38 ( V_8 , & V_154 ) )
return - V_73 ;
if ( V_154 )
F_13 ( V_2 ) ;
V_14 = F_19 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_149 ;
}
static T_5 F_39 ( struct V_141 * V_22 ,
struct V_142 * V_143 ,
char * V_8 )
{
struct V_11 * V_12 = F_2 ( F_25 ( V_22 ) ) ;
int V_13 = 0 ;
int V_156 = 0 ;
while ( V_13 < ( V_157 * 3 ) ) {
V_156 += snprintf ( V_8 + V_156 , V_144 , L_34 ,
V_12 -> V_39 [ V_13 ] . V_7 ,
V_12 -> V_39 [ V_13 ] . V_3 ,
V_12 -> V_39 [ V_13 ] . V_4 ) ;
if ( V_12 -> V_39 [ V_13 ] . V_7 == 0 ) {
V_156 -- ;
break;
}
V_13 ++ ;
}
V_156 += snprintf ( V_8 + V_156 , V_144 , L_35 ) ;
return V_156 ;
}
static T_5 F_40 ( struct V_141 * V_22 ,
struct V_142 * V_143 ,
const char * V_8 , T_6 V_149 )
{
struct V_1 * V_2 = F_25 ( V_22 ) ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
int V_154 [ F_41 ( V_12 -> V_39 ) * 3 + 1 ] ;
int V_158 , V_14 ;
F_42 ( V_8 , F_41 ( V_154 ) , V_154 ) ;
V_158 = V_154 [ 0 ] ;
if ( ( V_158 % 3 ) || V_158 < 6 ||
V_158 > ( ( F_41 ( V_12 -> V_39 ) - 1 ) * 3 ) ) {
F_14 ( V_22 , L_36 , V_158 ) ;
return - V_73 ;
}
if ( ( V_154 [ ( V_158 - 2 ) ] | V_154 [ ( V_158 - 1 ) ] | V_154 [ V_158 ] ) != 0 ) {
F_14 ( V_22 , L_37 , V_158 ) ;
return - V_73 ;
}
if ( V_12 -> V_19 == V_20 )
F_18 ( V_2 ) ;
memset ( V_12 -> V_39 , 0 , sizeof( V_12 -> V_39 ) ) ;
memcpy ( V_12 -> V_39 , & V_154 [ 1 ] , ( V_154 [ 0 ] * 4 ) ) ;
V_14 = F_19 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_149 ;
}
static T_5 F_43 ( struct V_141 * V_22 ,
struct V_142 * V_143 ,
const char * V_8 , T_6 V_149 )
{
struct V_1 * V_2 = F_25 ( V_22 ) ;
bool V_154 ;
int V_14 ;
if ( F_38 ( V_8 , & V_154 ) )
return - V_73 ;
if ( V_154 )
F_23 ( V_2 ) ;
V_14 = F_19 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_149 ;
}
static int F_44 ( struct V_1 * V_2 ,
const struct V_159 * V_160 ,
enum V_161 type ,
enum V_162 V_163 )
{
struct V_11 * V_12 = F_2 ( V_2 ) ;
int V_14 ;
if ( V_160 -> type == V_164 )
V_14 = ! ! ( V_12 -> V_41 . V_114 & 0x10 ) ;
else
V_14 = ! ! ( V_12 -> V_41 . V_114 & 0x20 ) ;
return V_14 ;
}
static int F_45 ( struct V_1 * V_2 ,
const struct V_159 * V_160 ,
enum V_161 type ,
enum V_162 V_163 ,
int V_165 )
{
struct V_11 * V_12 = F_2 ( V_2 ) ;
int V_14 ;
if ( V_160 -> type == V_164 ) {
if ( V_165 )
V_12 -> V_41 . V_114 |= 0x10 ;
else
V_12 -> V_41 . V_114 &= 0x20 ;
} else {
if ( V_165 )
V_12 -> V_41 . V_114 |= 0x20 ;
else
V_12 -> V_41 . V_114 &= 0x10 ;
}
V_14 = F_19 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
const struct V_159 * V_160 ,
enum V_161 type ,
enum V_162 V_163 ,
enum V_166 V_167 ,
int V_165 , int V_168 )
{
struct V_11 * V_12 = F_2 ( V_2 ) ;
int V_14 = - V_73 ;
switch ( V_167 ) {
case V_169 :
if ( V_160 -> type == V_164 ) {
switch ( V_163 ) {
case V_170 :
V_12 -> V_41 . V_95 = V_165 ;
V_14 = 0 ;
break;
case V_171 :
V_12 -> V_41 . V_92 = V_165 ;
V_14 = 0 ;
break;
default:
break;
}
} else {
switch ( V_163 ) {
case V_170 :
V_12 -> V_41 . V_105 = V_165 ;
V_14 = 0 ;
break;
case V_171 :
V_12 -> V_41 . V_102 = V_165 ;
V_14 = 0 ;
break;
default:
break;
}
}
break;
default:
break;
}
if ( V_14 < 0 )
return V_14 ;
return F_19 ( V_2 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
const struct V_159 * V_160 ,
enum V_161 type ,
enum V_162 V_163 ,
enum V_166 V_167 ,
int * V_165 , int * V_168 )
{
struct V_11 * V_12 = F_2 ( V_2 ) ;
int V_14 = - V_73 ;
switch ( V_167 ) {
case V_169 :
if ( V_160 -> type == V_164 ) {
switch ( V_163 ) {
case V_170 :
* V_165 = V_12 -> V_41 . V_95 ;
V_14 = V_172 ;
break;
case V_171 :
* V_165 = V_12 -> V_41 . V_92 ;
V_14 = V_172 ;
break;
default:
break;
}
} else {
switch ( V_163 ) {
case V_170 :
* V_165 = V_12 -> V_41 . V_105 ;
V_14 = V_172 ;
break;
case V_171 :
* V_165 = V_12 -> V_41 . V_102 ;
V_14 = V_172 ;
break;
default:
break;
}
}
break;
default:
break;
}
return V_14 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_159 const * V_160 ,
int * V_165 ,
int * V_168 ,
long V_173 )
{
int V_14 = - V_73 ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
switch ( V_173 ) {
case V_174 :
switch ( V_160 -> type ) {
case V_175 :
F_1 ( V_2 ) ;
* V_165 = V_12 -> V_18 . V_5 ;
V_14 = V_172 ;
break;
default:
return - V_73 ;
}
break;
case V_176 :
switch ( V_160 -> type ) {
case V_164 :
F_1 ( V_2 ) ;
if ( V_160 -> V_177 == 0 )
* V_165 = V_12 -> V_18 . V_34 ;
else
* V_165 = V_12 -> V_18 . V_35 ;
V_14 = V_172 ;
break;
case V_178 :
F_11 ( V_2 ) ;
* V_165 = V_12 -> V_61 ;
V_14 = V_172 ;
break;
default:
return - V_73 ;
}
break;
case V_179 :
if ( V_160 -> type == V_175 )
* V_165 =
V_40 [ V_12 -> V_41 . V_42 ] ;
else
* V_165 =
V_180 [ V_12 -> V_41 . V_111 ] ;
V_14 = V_172 ;
break;
case V_181 :
* V_165 = V_12 -> V_41 . V_44 ;
V_14 = V_172 ;
break;
default:
V_14 = - V_73 ;
}
return V_14 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_159 const * V_160 ,
int V_165 ,
int V_168 ,
long V_173 )
{
struct V_11 * V_12 = F_2 ( V_2 ) ;
switch ( V_173 ) {
case V_179 :
if ( V_160 -> type == V_164 ) {
switch ( V_165 ) {
case 1 :
V_12 -> V_41 . V_42 = 0 ;
break;
case 8 :
V_12 -> V_41 . V_42 = 1 ;
break;
case 16 :
V_12 -> V_41 . V_42 = 2 ;
break;
case 120 :
switch ( V_12 -> V_48 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
return - V_73 ;
}
V_12 -> V_41 . V_42 = 3 ;
break;
case 128 :
switch ( V_12 -> V_48 ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
return - V_73 ;
}
V_12 -> V_41 . V_42 = 3 ;
break;
default:
return - V_73 ;
}
} else {
switch ( V_165 ) {
case 1 :
V_12 -> V_41 . V_111 = 0 ;
break;
case 2 :
V_12 -> V_41 . V_111 = 1 ;
break;
case 4 :
V_12 -> V_41 . V_111 = 2 ;
break;
case 8 :
V_12 -> V_41 . V_111 = 3 ;
break;
default:
return - V_73 ;
}
}
break;
case V_181 :
V_12 -> V_41 . V_44 = V_165 ;
break;
default:
return - V_73 ;
}
return F_19 ( V_2 ) ;
}
static int F_50 ( int * V_48 , int V_182 )
{
switch ( V_182 ) {
case V_49 :
case V_50 :
case V_52 :
return ( * V_48 & 0xf0 ) == V_183 ;
case V_51 :
case V_53 :
return ( * V_48 & 0xf0 ) == V_184 ;
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
return ( * V_48 & 0xf0 ) == V_185 ;
}
return - V_73 ;
}
static T_7 F_51 ( int V_186 , void * V_187 )
{
struct V_1 * V_2 = V_187 ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
T_8 V_188 = F_52 ( V_2 ) ;
int V_14 ;
T_4 V_154 ;
V_154 = F_5 ( V_12 -> V_21 ,
V_26 | V_27 ) ;
if ( V_154 & V_189 ) {
F_11 ( V_2 ) ;
F_53 ( V_2 ,
F_54 ( V_178 ,
0 ,
V_190 ,
V_191 ) ,
V_188 ) ;
}
if ( V_154 & V_192 ) {
F_1 ( V_2 ) ;
F_53 ( V_2 ,
F_54 ( V_175 ,
0 ,
V_190 ,
V_191 ) ,
V_188 ) ;
}
V_14 = F_6 ( V_12 -> V_21 ,
V_26 | V_31 |
V_115 ) ;
if ( V_14 < 0 )
F_4 ( & V_12 -> V_21 -> V_22 ,
L_38 ,
V_14 ) ;
return V_193 ;
}
static int F_55 ( struct V_194 * V_195 ,
const struct V_196 * V_48 )
{
int V_14 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
V_2 = F_56 ( & V_195 -> V_22 , sizeof( * V_12 ) ) ;
if ( ! V_2 )
return - V_197 ;
V_12 = F_2 ( V_2 ) ;
V_12 -> V_21 = V_195 ;
F_57 ( V_195 , V_2 ) ;
V_14 = F_5 ( V_12 -> V_21 ,
V_26 | V_198 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( ( ! F_50 ( & V_14 , V_48 -> V_199 ) ) ||
( F_50 ( & V_14 , V_48 -> V_199 ) == - V_73 ) ) {
F_14 ( & V_12 -> V_21 -> V_22 ,
L_39 ,
V_23 ) ;
return - V_73 ;
}
V_14 = F_6 ( V_195 , ( V_26 | V_70 ) ) ;
if ( V_14 < 0 ) {
F_4 ( & V_195 -> V_22 , L_40 ,
V_14 ) ;
return V_14 ;
}
F_58 ( & V_12 -> V_17 ) ;
F_58 ( & V_12 -> V_46 ) ;
V_12 -> V_19 = V_200 ;
V_12 -> V_62 = F_59 ( & V_195 -> V_22 ) ;
V_12 -> V_48 = V_48 -> V_199 ;
V_12 -> V_201 =
& V_202 [ V_203 [ V_48 -> V_199 ] ] ;
V_2 -> V_167 = V_12 -> V_201 -> V_167 ;
V_2 -> V_22 . V_204 = & V_195 -> V_22 ;
V_2 -> V_205 = V_206 ;
V_2 -> V_77 = V_12 -> V_21 -> V_77 ;
V_2 -> V_207 = V_12 -> V_201 -> V_177 ;
V_2 -> V_208 = V_12 -> V_201 -> V_209 ;
if ( V_195 -> V_186 ) {
V_14 = F_60 ( & V_195 -> V_22 , V_195 -> V_186 ,
NULL ,
& F_51 ,
V_210 |
V_211 ,
L_41 ,
V_2 ) ;
if ( V_14 ) {
F_4 ( & V_195 -> V_22 ,
L_42 , V_23 ) ;
return V_14 ;
}
}
F_12 ( V_12 ) ;
F_15 ( V_2 ) ;
V_14 = F_61 ( V_2 ) ;
if ( V_14 ) {
F_4 ( & V_195 -> V_22 ,
L_43 , V_23 ) ;
return V_14 ;
}
F_14 ( & V_195 -> V_22 , L_44 , V_48 -> V_77 ) ;
return 0 ;
}
static int F_62 ( struct V_141 * V_22 )
{
struct V_1 * V_2 = F_63 ( V_22 ) ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
int V_14 = 0 ;
if ( V_12 -> V_19 == V_20 ) {
V_14 = F_18 ( V_2 ) ;
V_12 -> V_19 = V_116 ;
}
if ( V_12 -> V_62 && V_12 -> V_62 -> V_212 ) {
T_9 V_213 = { V_214 } ;
V_12 -> V_62 -> V_212 ( V_22 , V_213 ) ;
}
return V_14 ;
}
static int F_64 ( struct V_141 * V_22 )
{
struct V_1 * V_2 = F_63 ( V_22 ) ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
int V_14 = 0 ;
if ( V_12 -> V_62 && V_12 -> V_62 -> V_212 ) {
T_9 V_213 = { V_215 } ;
V_12 -> V_62 -> V_212 ( V_22 , V_213 ) ;
}
if ( V_12 -> V_19 == V_116 )
V_14 = F_15 ( V_2 ) ;
return V_14 ;
}
static int F_65 ( struct V_194 * V_21 )
{
struct V_1 * V_2 = F_66 ( V_21 ) ;
F_18 ( V_2 ) ;
F_67 ( V_2 ) ;
return 0 ;
}
