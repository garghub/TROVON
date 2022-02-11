static int
F_1 ( const char * V_1 , struct V_2 * V_3 )
{
int integer = 0 , V_4 = 0 , V_5 = 100000 ;
bool V_6 = true , V_7 = false ;
if ( V_1 [ 0 ] == '-' ) {
V_7 = true ;
V_1 ++ ;
}
while ( * V_1 ) {
if ( '0' <= * V_1 && * V_1 <= '9' ) {
if ( V_6 )
integer = integer * 10 + * V_1 - '0' ;
else {
V_4 += V_5 * ( * V_1 - '0' ) ;
if ( V_5 == 1 )
break;
V_5 /= 10 ;
}
} else if ( * V_1 == '\n' ) {
if ( * ( V_1 + 1 ) == '\0' )
break;
else
return - V_8 ;
} else if ( * V_1 == '.' ) {
V_6 = false ;
} else {
return - V_8 ;
}
V_1 ++ ;
}
if ( V_7 ) {
if ( integer )
integer = - integer ;
else
V_4 = - V_4 ;
}
V_3 -> integer = integer ;
V_3 -> V_4 = V_4 ;
return 0 ;
}
static int
F_2 ( struct V_9 * V_10 , T_1 V_11 , T_1 * V_12 )
{
int V_13 = 0 ;
V_13 = F_3 ( V_10 , ( V_14 | V_11 ) ) ;
if ( V_13 < 0 ) {
F_4 ( & V_10 -> V_15 , L_1
, V_16 , V_11 ) ;
return V_13 ;
}
V_13 = F_5 ( V_10 ) ;
if ( V_13 >= 0 )
* V_12 = ( T_1 ) V_13 ;
else
F_4 ( & V_10 -> V_15 , L_2
, V_16 , V_11 ) ;
return V_13 ;
}
static int F_6 ( struct V_17 * V_18 )
{
T_2 V_19 , V_20 ;
T_3 V_21 ;
T_4 V_22 ;
T_3 V_23 ;
T_1 V_1 [ 4 ] ;
struct V_24 * V_25 ;
struct V_26 * V_27 = F_7 ( V_18 ) ;
int V_28 , V_13 ;
T_3 V_29 = 0 ;
T_3 V_30 = 0 ;
if ( F_8 ( & V_27 -> V_31 ) == 0 )
return V_27 -> V_32 . V_21 ;
if ( V_27 -> V_33 != V_34 ) {
F_4 ( & V_27 -> V_10 -> V_15 , L_3 ,
V_16 ) ;
V_13 = - V_35 ;
goto V_36;
}
V_13 = F_2 ( V_27 -> V_10 ,
( V_14 | V_37 ) , & V_1 [ 0 ] ) ;
if ( V_13 < 0 ) {
F_4 ( & V_27 -> V_10 -> V_15 ,
L_4 , V_16 ) ;
goto V_36;
}
if ( ! ( V_1 [ 0 ] & V_38 ) ) {
F_4 ( & V_27 -> V_10 -> V_15 ,
L_5 , V_16 ) ;
V_13 = V_27 -> V_32 . V_21 ;
goto V_36;
}
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ ) {
V_13 = F_2 ( V_27 -> V_10 ,
( V_14 | ( V_39 + V_28 ) ) ,
& V_1 [ V_28 ] ) ;
if ( V_13 < 0 ) {
F_4 ( & V_27 -> V_10 -> V_15 ,
L_6 , V_16 , V_13 ) ;
goto V_36;
}
}
V_13 = F_3 ( V_27 -> V_10 ,
( V_14 |
V_40 |
V_41 ) ) ;
if ( V_13 < 0 ) {
F_4 ( & V_27 -> V_10 -> V_15 ,
L_7 ,
V_16 , V_13 ) ;
goto V_36;
}
V_19 = F_9 ( ( const V_42 * ) & V_1 [ 0 ] ) ;
V_20 = F_9 ( ( const V_42 * ) & V_1 [ 2 ] ) ;
V_27 -> V_32 . V_43 = V_19 ;
V_27 -> V_32 . V_44 = V_20 ;
if ( ( V_19 >= V_27 -> V_45 ) || ( V_20 >= V_27 -> V_45 ) ) {
V_21 = V_46 ;
goto V_47;
}
if ( V_19 == 0 ) {
V_13 = V_27 -> V_32 . V_21 ;
goto V_36;
}
V_23 = ( V_20 << 15 ) / V_19 ;
V_25 = (struct V_24 * ) V_27 -> V_48 ;
while ( V_25 -> V_23 != 0 && V_25 -> V_23 < V_23 )
V_25 ++ ;
if ( V_25 -> V_23 == 0 ) {
V_21 = 0 ;
} else {
V_29 = F_10 ( ( V_19 * V_25 -> V_19 ) ,
V_49 [ V_27 -> V_50 . V_51 ] ) ;
V_30 = F_10 ( ( V_20 * V_25 -> V_20 ) ,
V_49 [ V_27 -> V_50 . V_51 ] ) ;
V_21 = V_29 - V_30 ;
}
if ( V_30 > V_29 ) {
F_11 ( & V_27 -> V_10 -> V_15 , L_8 ) ;
V_13 = V_27 -> V_32 . V_21 ;
goto V_36;
}
if ( V_27 -> V_52 == 0 )
V_21 = 0 ;
else
V_21 = ( V_21 + ( V_27 -> V_52 >> 1 ) ) /
V_27 -> V_52 ;
V_22 = V_21 ;
V_22 = V_22 * V_27 -> V_50 . V_53 ;
V_22 >>= 8 ;
V_21 = V_22 ;
V_21 = ( V_21 + 500 ) / 1000 ;
if ( V_21 > V_46 )
V_21 = V_46 ;
V_47:
V_27 -> V_32 . V_21 = V_21 ;
V_13 = V_21 ;
V_36:
F_12 ( & V_27 -> V_31 ) ;
return V_13 ;
}
static int F_13 ( struct V_17 * V_18 )
{
int V_28 ;
int V_13 ;
T_1 V_54 ;
T_1 V_55 [ 2 ] ;
struct V_26 * V_27 = F_7 ( V_18 ) ;
if ( F_8 ( & V_27 -> V_56 ) == 0 ) {
F_4 ( & V_27 -> V_10 -> V_15 ,
L_9 , V_16 ) ;
return - V_35 ;
}
V_13 = F_2 ( V_27 -> V_10 ,
( V_14 | V_37 ) , & V_54 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_27 -> V_10 -> V_15 ,
L_10 , V_16 , V_13 ) ;
goto V_57;
}
switch ( V_27 -> V_58 ) {
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
if ( ! ( V_54 & V_38 ) )
goto V_57;
break;
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
if ( ! ( V_54 & V_69 ) )
goto V_57;
break;
}
for ( V_28 = 0 ; V_28 < 2 ; V_28 ++ ) {
V_13 = F_2 ( V_27 -> V_10 ,
( V_14 |
( V_70 + V_28 ) ) , & V_55 [ V_28 ] ) ;
if ( V_13 < 0 )
goto V_57;
}
V_27 -> V_71 =
F_9 ( ( const V_42 * ) & V_55 [ 0 ] ) ;
V_57:
F_12 ( & V_27 -> V_56 ) ;
return V_27 -> V_71 ;
}
static void F_14 ( struct V_26 * V_27 )
{
if ( V_27 -> V_72 && V_27 -> V_72 -> V_73 != 0 )
memcpy ( & ( V_27 -> V_50 ) ,
V_27 -> V_72 -> V_73 ,
sizeof( V_74 ) ) ;
else
memcpy ( & ( V_27 -> V_50 ) ,
& V_74 ,
sizeof( V_74 ) ) ;
if ( V_27 -> V_72 && V_27 -> V_72 -> V_75 [ 0 ] . V_23 != 0 )
memcpy ( V_27 -> V_48 ,
V_27 -> V_72 -> V_75 ,
sizeof( V_27 -> V_72 -> V_75 ) ) ;
else
memcpy ( V_27 -> V_48 ,
(struct V_24 * ) V_76 [ V_27 -> V_58 ] ,
V_77 ) ;
}
static int F_15 ( struct V_17 * V_18 )
{
struct V_26 * V_27 = F_7 ( V_18 ) ;
T_1 V_78 ;
int V_79 ;
int V_13 ;
int V_80 ;
V_13 = F_3 ( V_27 -> V_10 ,
( V_14 | V_81 ) ) ;
if ( V_13 < 0 ) {
F_4 ( & V_27 -> V_10 -> V_15 ,
L_11 ,
V_16 , V_13 ) ;
return V_13 ;
}
V_78 = F_5 ( V_27 -> V_10 ) ;
if ( ( V_78 & ( V_82 | V_83 ) )
!= ( V_82 | V_83 ) ) {
F_4 ( & V_27 -> V_10 -> V_15 ,
L_12 , V_16 ) ;
return - 1 ;
}
V_13 = F_3 ( V_27 -> V_10 ,
( V_14 | V_81 ) ) ;
if ( V_13 < 0 ) {
F_4 ( & V_27 -> V_10 -> V_15 ,
L_13 ,
V_16 , V_13 ) ;
return V_13 ;
}
V_78 = F_5 ( V_27 -> V_10 ) ;
if ( ( V_78 & V_38 ) != V_38 ) {
F_4 ( & V_27 -> V_10 -> V_15 ,
L_14 , V_16 ) ;
return - V_84 ;
}
V_80 = F_6 ( V_18 ) ;
if ( V_80 < 0 ) {
F_4 ( & V_27 -> V_10 -> V_15 ,
L_15 , V_16 ) ;
return V_80 ;
}
V_79 = ( ( ( V_27 -> V_50 . V_85 )
* V_27 -> V_50 . V_53 ) / V_80 ) ;
if ( ( V_79 < 250 ) || ( V_79 > 4000 ) )
return - V_86 ;
V_27 -> V_50 . V_53 = V_79 ;
F_16 ( & V_27 -> V_10 -> V_15 ,
L_16 , V_27 -> V_10 -> V_87 ) ;
return ( int ) V_79 ;
}
static int F_17 ( struct V_17 * V_18 )
{
int V_28 ;
int V_13 = 0 ;
T_1 * V_88 ;
T_1 V_89 ;
int V_90 ;
int V_91 ;
struct V_26 * V_27 = F_7 ( V_18 ) ;
T_1 V_78 = 0 ;
if ( V_27 -> V_72 && V_27 -> V_72 -> V_92 )
V_27 -> V_72 -> V_92 ( V_18 ) ;
V_27 -> V_93 [ V_94 ] =
V_27 -> V_50 . V_95 ;
V_27 -> V_93 [ V_96 ] =
V_27 -> V_50 . V_97 ;
V_27 -> V_93 [ V_98 ] =
V_27 -> V_50 . V_99 ;
V_27 -> V_93 [ V_100 ] =
( V_27 -> V_50 . V_101 ) & 0xFF ;
V_27 -> V_93 [ V_102 ] =
( V_27 -> V_50 . V_101 >> 8 ) & 0xFF ;
V_27 -> V_93 [ V_103 ] =
( V_27 -> V_50 . V_104 ) & 0xFF ;
V_27 -> V_93 [ V_105 ] =
( V_27 -> V_50 . V_104 >> 8 ) & 0xFF ;
V_27 -> V_93 [ V_106 ] =
V_27 -> V_50 . V_107 ;
V_27 -> V_93 [ V_108 ] =
V_27 -> V_50 . V_109 ;
V_27 -> V_93 [ V_110 ] =
V_27 -> V_50 . V_111 ;
V_27 -> V_93 [ V_112 ] =
V_27 -> V_50 . V_113 ;
if ( V_27 -> V_33 == V_34 ) {
F_16 ( & V_27 -> V_10 -> V_15 , L_17 ) ;
return - V_8 ;
}
V_90 = ( V_27 -> V_50 . V_91 * 100 + 135 ) / 270 ;
if ( V_90 == 0 )
V_90 = 1 ;
V_91 = ( V_90 * 27 + 5 ) / 10 ;
V_27 -> V_93 [ V_114 ] = 256 - V_90 ;
V_27 -> V_93 [ V_115 ] =
( V_27 -> V_50 . V_51 |
( V_116 | V_117 )
| ( ( V_27 -> V_50 . V_118 ) << 2 ) ) ;
V_27 -> V_45 = V_90 * 922 ;
V_27 -> V_52 = ( V_91 + 25 ) / 50 ;
V_89 = V_83 ;
V_13 = F_18 ( V_27 -> V_10 ,
V_14 | V_81 , V_89 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_27 -> V_10 -> V_15 ,
L_18 , V_16 ) ;
return V_13 ;
}
for ( V_28 = 0 , V_88 = V_27 -> V_93 ;
V_28 < V_119 ; V_28 ++ ) {
V_13 = F_18 ( V_27 -> V_10 ,
V_14 + V_28 , * V_88 ++ ) ;
if ( V_13 < 0 ) {
F_4 ( & V_27 -> V_10 -> V_15 ,
L_19 , V_16 , V_28 ) ;
return V_13 ;
}
}
F_19 ( 3 ) ;
V_89 = V_83 |
V_82 |
V_120 ;
V_13 = F_18 ( V_27 -> V_10 ,
V_14 | V_81 , V_89 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_27 -> V_10 -> V_15 ,
L_20 , V_16 ) ;
return V_13 ;
}
V_27 -> V_33 = V_34 ;
if ( V_27 -> V_50 . V_121 != 0 ) {
F_16 ( & V_27 -> V_10 -> V_15 , L_21 ) ;
V_78 = V_83 | V_82 ;
if ( ( V_27 -> V_50 . V_121 == 0x20 ) ||
( V_27 -> V_50 . V_121 == 0x30 ) )
V_78 |= V_120 ;
V_78 |= V_27 -> V_50 . V_121 ;
V_13 = F_18 ( V_27 -> V_10 ,
( V_14 | V_81 ) , V_78 ) ;
if ( V_13 < 0 )
F_4 ( & V_27 -> V_10 -> V_15 ,
L_22 ,
V_16 ) ;
V_13 = F_3 ( V_27 -> V_10 ,
V_14 | V_40 |
V_122 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_27 -> V_10 -> V_15 ,
L_23 ,
V_16 ) ;
return V_13 ;
}
}
return V_13 ;
}
static int F_20 ( struct V_17 * V_18 )
{
int V_13 ;
struct V_26 * V_27 = F_7 ( V_18 ) ;
V_27 -> V_33 = V_123 ;
V_13 = F_18 ( V_27 -> V_10 ,
V_14 | V_81 , 0x00 ) ;
if ( V_27 -> V_72 && V_27 -> V_72 -> V_124 )
V_27 -> V_72 -> V_124 ( V_27 -> V_10 ) ;
return V_13 ;
}
static
int F_21 ( struct V_17 * V_18 )
{
struct V_26 * V_27 = F_7 ( V_18 ) ;
int V_125 = V_27 -> V_33 ;
F_22 ( & V_27 -> V_31 ) ;
F_22 ( & V_27 -> V_56 ) ;
if ( V_125 == V_34 )
F_20 ( V_18 ) ;
F_17 ( V_18 ) ;
if ( V_125 != V_34 )
F_20 ( V_18 ) ;
F_12 ( & V_27 -> V_56 ) ;
F_12 ( & V_27 -> V_31 ) ;
return 0 ;
}
static
void F_23 ( int * V_126 , int V_127 ,
struct V_128 * V_129 )
{
int V_28 ;
int V_130 ;
int V_131 ;
if ( V_127 == 0 )
V_127 = 1 ;
V_130 = 0 ;
V_129 -> V_132 = V_133 ;
V_129 -> V_134 = V_135 ;
for ( V_28 = 0 ; V_28 < V_127 ; V_28 ++ ) {
V_130 += V_126 [ V_28 ] ;
V_129 -> V_132 = V_132 ( V_129 -> V_132 , V_126 [ V_28 ] ) ;
V_129 -> V_134 = V_134 ( V_129 -> V_134 , V_126 [ V_28 ] ) ;
}
V_129 -> V_136 = V_130 / V_127 ;
V_130 = 0 ;
for ( V_28 = 0 ; V_28 < V_127 ; V_28 ++ ) {
V_131 = V_126 [ V_28 ] - V_129 -> V_136 ;
V_130 += V_131 * V_131 ;
}
V_129 -> V_137 = F_24 ( ( long ) V_130 ) / V_127 ;
}
static void F_25 ( struct V_17 * V_18 )
{
int V_138 [ V_139 + 1 ] ;
int V_28 ;
struct V_128 V_140 [ 2 ] ;
struct V_128 * V_141 ;
struct V_26 * V_27 = F_7 ( V_18 ) ;
T_1 V_142 ;
T_1 V_143 = V_27 -> V_33 ;
if ( V_27 -> V_50 . V_144 > V_139 ) {
F_4 ( & V_27 -> V_10 -> V_15 ,
L_24 ,
V_16 , V_27 -> V_50 . V_144 ) ;
V_27 -> V_50 . V_144 = V_139 ;
}
F_20 ( V_18 ) ;
V_142 = V_27 -> V_50 . V_121 ;
V_27 -> V_50 . V_121 |= V_145 ;
F_17 ( V_18 ) ;
for ( V_28 = 0 ; V_28 < V_27 -> V_50 . V_144 ; V_28 ++ ) {
F_19 ( 15 ) ;
F_13 ( V_18 ) ;
V_138 [ V_28 ] = V_27 -> V_71 ;
F_16 ( & V_27 -> V_10 -> V_15 , L_25 ,
V_28 , V_27 -> V_71 ) ;
}
F_20 ( V_18 ) ;
V_141 = & V_140 [ V_146 ] ;
F_23 ( V_138 ,
V_27 -> V_50 . V_144 , V_141 ) ;
V_27 -> V_50 . V_113 = ( V_141 -> V_134 << 1 ) - V_141 -> V_136 ;
F_16 ( & V_27 -> V_10 -> V_15 , L_26 ,
V_141 -> V_132 , V_141 -> V_136 , V_141 -> V_134 ) ;
F_16 ( & V_27 -> V_10 -> V_15 ,
L_27 ,
V_27 -> V_10 -> V_87 , V_27 -> V_50 . V_113 ) ;
V_27 -> V_50 . V_121 = V_142 ;
if ( V_143 == V_34 )
F_17 ( V_18 ) ;
}
static T_5 F_26 ( struct V_147 * V_15 ,
struct V_148 * V_149 , char * V_1 )
{
struct V_26 * V_27 = F_7 ( F_27 ( V_15 ) ) ;
return snprintf ( V_1 , V_150 , L_28 , V_27 -> V_33 ) ;
}
static T_5 F_28 ( struct V_147 * V_15 ,
struct V_148 * V_149 , const char * V_1 , T_6 V_151 )
{
struct V_17 * V_18 = F_27 ( V_15 ) ;
bool V_152 ;
if ( F_29 ( V_1 , & V_152 ) )
return - V_8 ;
if ( V_152 )
F_17 ( V_18 ) ;
else
F_20 ( V_18 ) ;
return V_151 ;
}
static T_5 F_30 ( struct V_147 * V_15 ,
struct V_148 * V_149 , char * V_1 )
{
struct V_26 * V_27 = F_7 ( F_27 ( V_15 ) ) ;
switch ( V_27 -> V_58 ) {
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
return snprintf ( V_1 , V_150 , L_29 , L_30 ) ;
break;
}
return snprintf ( V_1 , V_150 , L_29 , L_31 ) ;
}
static T_5 F_31 ( struct V_147 * V_15 ,
struct V_148 * V_149 , char * V_1 )
{
return snprintf ( V_1 , V_150 , L_29 , L_32 ) ;
}
static T_5 F_32 ( struct V_147 * V_15 ,
struct V_148 * V_149 , char * V_1 )
{
struct V_26 * V_27 = F_7 ( F_27 ( V_15 ) ) ;
int V_153 , V_154 ;
V_153 = ( V_155 - ( T_1 ) V_27 -> V_50 . V_91 ) + 1 ;
V_154 = V_153 * V_156 ;
V_153 /= 1000 ;
V_154 %= 1000 ;
return snprintf ( V_1 , V_150 , L_33 , V_153 , V_154 ) ;
}
static T_5 F_33 ( struct V_147 * V_15 ,
struct V_148 * V_149 , const char * V_1 , T_6 V_151 )
{
struct V_17 * V_18 = F_27 ( V_15 ) ;
struct V_26 * V_27 = F_7 ( V_18 ) ;
struct V_2 V_3 ;
V_3 . integer = 0 ;
V_3 . V_4 = 0 ;
F_1 ( V_1 , & V_3 ) ;
V_3 . V_4 /= 1000 ;
V_3 . V_4 /= 3 ;
V_27 -> V_50 . V_91 =
( V_155 - ( T_1 ) V_3 . V_4 ) ;
F_16 ( & V_27 -> V_10 -> V_15 , L_34 ,
V_16 , V_27 -> V_50 . V_91 ) ;
F_21 ( V_18 ) ;
return V_157 ;
}
static T_5 F_34 ( struct V_147 * V_15 ,
struct V_148 * V_149 , char * V_1 )
{
struct V_26 * V_27 = F_7 ( F_27 ( V_15 ) ) ;
return snprintf ( V_1 , V_150 , L_28 ,
V_27 -> V_50 . V_85 ) ;
}
static T_5 F_35 ( struct V_147 * V_15 ,
struct V_148 * V_149 , const char * V_1 , T_6 V_151 )
{
struct V_17 * V_18 = F_27 ( V_15 ) ;
struct V_26 * V_27 = F_7 ( V_18 ) ;
unsigned long V_152 ;
if ( F_36 ( V_1 , 0 , & V_152 ) )
return - V_8 ;
if ( V_152 )
V_27 -> V_50 . V_85 = V_152 ;
F_21 ( V_18 ) ;
return V_151 ;
}
static T_5 F_37 ( struct V_147 * V_15 ,
struct V_148 * V_149 , char * V_1 )
{
struct V_26 * V_27 = F_7 ( F_27 ( V_15 ) ) ;
int V_153 , V_154 , V_158 ;
V_153 = ( V_155 - ( T_1 ) V_27 -> V_50 . V_91 ) + 1 ;
V_154 = V_153 * V_156 ;
V_158 = V_154 * ( V_27 -> V_50 . V_107 & 0x0F ) ;
V_153 = ( V_158 / 1000 ) ;
V_154 = ( V_158 % 1000 ) ;
return snprintf ( V_1 , V_150 , L_33 , V_153 , V_154 ) ;
}
static T_5 F_38 ( struct V_147 * V_15 ,
struct V_148 * V_149 , const char * V_1 , T_6 V_151 )
{
struct V_17 * V_18 = F_27 ( V_15 ) ;
struct V_26 * V_27 = F_7 ( V_18 ) ;
struct V_2 V_3 ;
int V_153 , V_154 , V_158 ;
V_3 . integer = 0 ;
V_3 . V_4 = 0 ;
F_1 ( V_1 , & V_3 ) ;
V_3 . V_4 /= 1000 ;
V_153 = ( V_155 - ( T_1 ) V_27 -> V_50 . V_91 ) + 1 ;
V_154 = V_153 * V_156 ;
V_158 =
F_10 ( ( ( V_3 . integer * 1000 ) + V_3 . V_4 ) , V_154 ) ;
V_27 -> V_50 . V_107 &= 0xF0 ;
V_27 -> V_50 . V_107 |= ( V_158 & 0x0F ) ;
F_16 ( & V_27 -> V_10 -> V_15 , L_35 ,
V_16 , V_158 ) ;
F_21 ( V_18 ) ;
return V_157 ;
}
static T_5 F_39 ( struct V_147 * V_15 ,
struct V_148 * V_149 , char * V_1 )
{
struct V_26 * V_27 = F_7 ( F_27 ( V_15 ) ) ;
int V_153 , V_154 , V_158 ;
V_153 = ( V_155 - ( T_1 ) V_27 -> V_50 . V_95 ) + 1 ;
V_154 = V_153 * V_156 ;
V_158 = V_154 * ( ( V_27 -> V_50 . V_107 & 0xF0 ) >> 4 ) ;
V_153 = ( V_158 / 1000 ) ;
V_154 = ( V_158 % 1000 ) ;
return snprintf ( V_1 , V_150 , L_33 , V_153 , V_154 ) ;
}
static T_5 F_40 ( struct V_147 * V_15 ,
struct V_148 * V_149 , const char * V_1 , T_6 V_151 )
{
struct V_17 * V_18 = F_27 ( V_15 ) ;
struct V_26 * V_27 = F_7 ( V_18 ) ;
struct V_2 V_3 ;
int V_153 , V_154 , V_158 ;
V_3 . integer = 0 ;
V_3 . V_4 = 0 ;
F_1 ( V_1 , & V_3 ) ;
V_3 . V_4 /= 1000 ;
V_153 = ( V_155 - ( T_1 ) V_27 -> V_50 . V_95 ) + 1 ;
V_154 = V_153 * V_156 ;
V_158 =
F_10 ( ( ( V_3 . integer * 1000 ) + V_3 . V_4 ) , V_154 ) ;
V_27 -> V_50 . V_107 &= 0x0F ;
V_27 -> V_50 . V_107 |= ( ( V_158 << 4 ) & 0xF0 ) ;
F_16 ( & V_27 -> V_10 -> V_15 , L_36 ,
V_16 , V_158 ) ;
F_21 ( V_18 ) ;
return V_157 ;
}
static T_5 F_41 ( struct V_147 * V_15 ,
struct V_148 * V_149 , const char * V_1 , T_6 V_151 )
{
struct V_17 * V_18 = F_27 ( V_15 ) ;
bool V_152 ;
if ( F_29 ( V_1 , & V_152 ) )
return - V_8 ;
if ( V_152 )
F_15 ( V_18 ) ;
F_21 ( V_18 ) ;
return V_151 ;
}
static T_5 F_42 ( struct V_147 * V_15 ,
struct V_148 * V_149 , char * V_1 )
{
struct V_26 * V_27 = F_7 ( F_27 ( V_15 ) ) ;
int V_28 = 0 ;
int V_159 = 0 ;
while ( V_28 < ( V_160 * 3 ) ) {
V_159 += snprintf ( V_1 + V_159 , V_150 , L_37 ,
V_27 -> V_48 [ V_28 ] . V_23 ,
V_27 -> V_48 [ V_28 ] . V_19 ,
V_27 -> V_48 [ V_28 ] . V_20 ) ;
if ( V_27 -> V_48 [ V_28 ] . V_23 == 0 ) {
V_159 -- ;
break;
}
V_28 ++ ;
}
V_159 += snprintf ( V_1 + V_159 , V_150 , L_38 ) ;
return V_159 ;
}
static T_5 F_43 ( struct V_147 * V_15 ,
struct V_148 * V_149 , const char * V_1 , T_6 V_151 )
{
struct V_17 * V_18 = F_27 ( V_15 ) ;
struct V_26 * V_27 = F_7 ( V_18 ) ;
int V_152 [ F_44 ( V_27 -> V_48 ) * 3 + 1 ] ;
int V_161 ;
F_45 ( V_1 , F_44 ( V_152 ) , V_152 ) ;
V_161 = V_152 [ 0 ] ;
if ( ( V_161 % 3 ) || V_161 < 6 ||
V_161 > ( ( F_44 ( V_27 -> V_48 ) - 1 ) * 3 ) ) {
F_16 ( V_15 , L_39 , V_161 ) ;
return - V_8 ;
}
if ( ( V_152 [ ( V_161 - 2 ) ] | V_152 [ ( V_161 - 1 ) ] | V_152 [ V_161 ] ) != 0 ) {
F_16 ( V_15 , L_40 , V_161 ) ;
return - V_8 ;
}
if ( V_27 -> V_33 == V_34 )
F_20 ( V_18 ) ;
memset ( V_27 -> V_48 , 0 , sizeof( V_27 -> V_48 ) ) ;
memcpy ( V_27 -> V_48 , & V_152 [ 1 ] , ( V_152 [ 0 ] * 4 ) ) ;
F_21 ( V_18 ) ;
return V_151 ;
}
static T_5 F_46 ( struct V_147 * V_15 ,
struct V_148 * V_149 , const char * V_1 , T_6 V_151 )
{
struct V_17 * V_18 = F_27 ( V_15 ) ;
bool V_152 ;
if ( F_29 ( V_1 , & V_152 ) )
return - V_8 ;
if ( V_152 )
F_25 ( V_18 ) ;
F_21 ( V_18 ) ;
return V_151 ;
}
static int F_47 ( struct V_17 * V_18 ,
T_4 V_162 )
{
struct V_26 * V_27 = F_7 ( V_18 ) ;
int V_13 ;
if ( F_48 ( V_162 ) == V_163 )
V_13 = ! ! ( V_27 -> V_50 . V_121 & 0x10 ) ;
else
V_13 = ! ! ( V_27 -> V_50 . V_121 & 0x20 ) ;
return V_13 ;
}
static int F_49 ( struct V_17 * V_18 ,
T_4 V_162 ,
int V_12 )
{
struct V_26 * V_27 = F_7 ( V_18 ) ;
if ( F_48 ( V_162 ) == V_163 ) {
if ( V_12 )
V_27 -> V_50 . V_121 |= 0x10 ;
else
V_27 -> V_50 . V_121 &= 0x20 ;
} else {
if ( V_12 )
V_27 -> V_50 . V_121 |= 0x20 ;
else
V_27 -> V_50 . V_121 &= 0x10 ;
}
F_21 ( V_18 ) ;
return 0 ;
}
static int F_50 ( struct V_17 * V_18 ,
T_4 V_162 ,
int V_12 )
{
struct V_26 * V_27 = F_7 ( V_18 ) ;
if ( F_48 ( V_162 ) == V_163 ) {
switch ( F_51 ( V_162 ) ) {
case V_164 :
V_27 -> V_50 . V_104 = V_12 ;
break;
case V_165 :
V_27 -> V_50 . V_101 = V_12 ;
break;
default:
return - V_8 ;
}
} else {
switch ( F_51 ( V_162 ) ) {
case V_164 :
V_27 -> V_50 . V_113 = V_12 ;
break;
case V_165 :
V_27 -> V_50 . V_111 = V_12 ;
break;
default:
return - V_8 ;
}
}
F_21 ( V_18 ) ;
return 0 ;
}
static int F_52 ( struct V_17 * V_18 ,
T_4 V_162 ,
int * V_12 )
{
struct V_26 * V_27 = F_7 ( V_18 ) ;
if ( F_48 ( V_162 ) == V_163 ) {
switch ( F_51 ( V_162 ) ) {
case V_164 :
* V_12 = V_27 -> V_50 . V_104 ;
break;
case V_165 :
* V_12 = V_27 -> V_50 . V_101 ;
break;
default:
return - V_8 ;
}
} else {
switch ( F_51 ( V_162 ) ) {
case V_164 :
* V_12 = V_27 -> V_50 . V_113 ;
break;
case V_165 :
* V_12 = V_27 -> V_50 . V_111 ;
break;
default:
return - V_8 ;
}
}
return 0 ;
}
static int F_53 ( struct V_17 * V_18 ,
struct V_166 const * V_167 ,
int * V_12 ,
int * V_168 ,
long V_169 )
{
int V_13 = - V_8 ;
struct V_26 * V_27 = F_7 ( V_18 ) ;
switch ( V_169 ) {
case V_170 :
switch ( V_167 -> type ) {
case V_171 :
F_6 ( V_18 ) ;
* V_12 = V_27 -> V_32 . V_21 ;
V_13 = V_172 ;
break;
default:
return - V_8 ;
break;
}
break;
case V_173 :
switch ( V_167 -> type ) {
case V_163 :
F_6 ( V_18 ) ;
if ( V_167 -> V_174 == 0 )
* V_12 = V_27 -> V_32 . V_43 ;
else
* V_12 = V_27 -> V_32 . V_44 ;
V_13 = V_172 ;
break;
case V_175 :
F_13 ( V_18 ) ;
* V_12 = V_27 -> V_71 ;
V_13 = V_172 ;
break;
default:
return - V_8 ;
break;
}
break;
case V_176 :
if ( V_167 -> type == V_171 )
* V_12 =
V_49 [ V_27 -> V_50 . V_51 ] ;
else
* V_12 =
V_177 [ V_27 -> V_50 . V_118 ] ;
V_13 = V_172 ;
break;
case V_178 :
* V_12 = V_27 -> V_50 . V_53 ;
V_13 = V_172 ;
break;
default:
V_13 = - V_8 ;
}
return V_13 ;
}
static int F_54 ( struct V_17 * V_18 ,
struct V_166 const * V_167 ,
int V_12 ,
int V_168 ,
long V_169 )
{
struct V_26 * V_27 = F_7 ( V_18 ) ;
switch ( V_169 ) {
case V_176 :
if ( V_167 -> type == V_163 ) {
switch ( V_12 ) {
case 1 :
V_27 -> V_50 . V_51 = 0 ;
break;
case 8 :
V_27 -> V_50 . V_51 = 1 ;
break;
case 16 :
V_27 -> V_50 . V_51 = 2 ;
break;
case 120 :
switch ( V_27 -> V_58 ) {
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
return - V_8 ;
break;
}
V_27 -> V_50 . V_51 = 3 ;
break;
case 128 :
switch ( V_27 -> V_58 ) {
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
return - V_8 ;
break;
}
V_27 -> V_50 . V_51 = 3 ;
break;
default:
return - V_8 ;
}
} else {
switch ( V_12 ) {
case 1 :
V_27 -> V_50 . V_118 = 0 ;
break;
case 2 :
V_27 -> V_50 . V_118 = 1 ;
break;
case 4 :
V_27 -> V_50 . V_118 = 2 ;
break;
case 8 :
V_27 -> V_50 . V_118 = 3 ;
break;
default:
return - V_8 ;
}
}
break;
case V_178 :
V_27 -> V_50 . V_53 = V_12 ;
break;
default:
return - V_8 ;
}
F_21 ( V_18 ) ;
return 0 ;
}
static int F_55 ( unsigned char * V_58 , int V_179 )
{
switch ( V_179 ) {
case V_59 :
case V_60 :
case V_62 :
return ( ( * V_58 & 0xf0 ) == V_180 ) ;
break;
case V_61 :
case V_63 :
return ( ( * V_58 & 0xf0 ) == V_181 ) ;
break;
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
return ( ( * V_58 & 0xf0 ) == V_182 ) ;
break;
}
return - V_8 ;
}
static T_7 F_56 ( int V_183 , void * V_184 )
{
struct V_17 * V_18 = V_184 ;
struct V_26 * V_27 = F_7 ( V_18 ) ;
T_8 V_185 = F_57 () ;
int V_13 ;
T_1 V_152 ;
V_152 = F_58 ( V_27 -> V_10 ,
V_14 | V_37 ) ;
if ( V_152 & V_186 ) {
F_13 ( V_18 ) ;
F_59 ( V_18 ,
F_60 ( V_175 ,
0 ,
V_187 ,
V_188 ) ,
V_185 ) ;
}
if ( V_152 & V_189 ) {
F_6 ( V_18 ) ;
F_59 ( V_18 ,
F_60 ( V_171 ,
0 ,
V_187 ,
V_188 ) ,
V_185 ) ;
}
V_13 = F_3 ( V_27 -> V_10 ,
V_14 | V_40 |
V_122 ) ;
if ( V_13 < 0 )
F_4 ( & V_27 -> V_10 -> V_15 ,
L_41 ,
V_16 , V_13 ) ;
return V_190 ;
}
static int T_9 F_61 ( struct V_9 * V_191 ,
const struct V_192 * V_58 )
{
int V_13 ;
unsigned char V_193 ;
struct V_17 * V_18 ;
struct V_26 * V_27 ;
V_18 = F_62 ( sizeof( * V_27 ) ) ;
if ( ! V_18 )
return - V_194 ;
V_27 = F_7 ( V_18 ) ;
V_27 -> V_10 = V_191 ;
F_63 ( V_191 , V_18 ) ;
V_13 = F_2 ( V_27 -> V_10 ,
V_195 , & V_193 ) ;
if ( V_13 < 0 )
goto V_196;
if ( ( ! F_55 ( & V_193 , V_58 -> V_197 ) ) ||
( F_55 ( & V_193 , V_58 -> V_197 ) == - V_8 ) ) {
F_16 ( & V_27 -> V_10 -> V_15 ,
L_42 ,
V_16 ) ;
goto V_196;
}
V_13 = F_3 ( V_191 , ( V_14 | V_81 ) ) ;
if ( V_13 < 0 ) {
F_4 ( & V_191 -> V_15 , L_43 ,
V_16 , V_13 ) ;
goto V_196;
}
F_64 ( & V_27 -> V_31 ) ;
F_64 ( & V_27 -> V_56 ) ;
V_27 -> V_33 = V_198 ;
V_27 -> V_72 = V_191 -> V_15 . V_199 ;
V_27 -> V_58 = V_58 -> V_197 ;
V_27 -> V_200 =
& V_201 [ V_202 [ V_58 -> V_197 ] ] ;
V_18 -> V_203 = V_27 -> V_200 -> V_203 ;
V_18 -> V_15 . V_204 = & V_191 -> V_15 ;
V_18 -> V_205 = V_206 ;
V_18 -> V_87 = V_27 -> V_10 -> V_87 ;
V_18 -> V_207 = V_27 -> V_200 -> V_174 ;
V_18 -> V_208 = V_27 -> V_200 -> V_209 ;
if ( V_191 -> V_183 ) {
V_13 = F_65 ( V_191 -> V_183 ,
NULL ,
& F_56 ,
V_210 | V_211 ,
L_44 ,
V_18 ) ;
if ( V_13 ) {
F_4 ( & V_191 -> V_15 ,
L_45 , V_16 ) ;
goto V_212;
}
}
F_14 ( V_27 ) ;
F_17 ( V_18 ) ;
V_13 = F_66 ( V_18 ) ;
if ( V_13 ) {
F_4 ( & V_191 -> V_15 ,
L_46 , V_16 ) ;
goto V_196;
}
F_16 ( & V_191 -> V_15 , L_47 , V_58 -> V_87 ) ;
return 0 ;
V_196:
if ( V_191 -> V_183 )
F_67 ( V_191 -> V_183 , V_18 ) ;
V_212:
F_68 ( V_18 ) ;
return V_13 ;
}
static int F_69 ( struct V_147 * V_15 )
{
struct V_17 * V_18 = F_70 ( V_15 ) ;
struct V_26 * V_27 = F_7 ( V_18 ) ;
int V_13 = 0 ;
if ( V_27 -> V_33 == V_34 ) {
V_13 = F_20 ( V_18 ) ;
V_27 -> V_33 = V_123 ;
}
if ( V_27 -> V_72 && V_27 -> V_72 -> V_213 ) {
T_10 V_214 = { V_215 } ;
V_27 -> V_72 -> V_213 ( V_15 , V_214 ) ;
}
return V_13 ;
}
static int F_71 ( struct V_147 * V_15 )
{
struct V_17 * V_18 = F_70 ( V_15 ) ;
struct V_26 * V_27 = F_7 ( V_18 ) ;
int V_13 = 0 ;
if ( V_27 -> V_72 && V_27 -> V_72 -> V_213 ) {
T_10 V_214 = { V_216 } ;
V_27 -> V_72 -> V_213 ( V_15 , V_214 ) ;
}
if ( V_27 -> V_33 == V_123 )
V_13 = F_17 ( V_18 ) ;
return V_13 ;
}
static int T_11 F_72 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_73 ( V_10 ) ;
F_20 ( V_18 ) ;
F_74 ( V_18 ) ;
if ( V_10 -> V_183 )
F_67 ( V_10 -> V_183 , V_18 ) ;
F_68 ( V_18 ) ;
return 0 ;
}
