static int F_1 ( struct V_1 * V_1 )
{
int V_2 ;
F_2 ( V_1 -> V_3 , true ) ;
V_2 = F_3 ( V_1 -> V_3 , V_4 ,
V_5 ) ;
F_2 ( V_1 -> V_3 , false ) ;
if ( V_2 )
return V_2 ;
return V_2 ;
}
static int F_4 ( unsigned int V_6 )
{
if ( V_6 >= 8000 && V_6 <= 12000 )
return V_7 ;
else if ( V_6 >= 16000 && V_6 <= 24000 )
return V_8 ;
else if ( V_6 >= 32000 && V_6 <= 48000 )
return V_9 ;
else if ( V_6 >= 64000 && V_6 <= 96000 )
return V_10 ;
else if ( V_6 >= 128000 && V_6 <= 192000 )
return V_11 ;
else
return - V_12 ;
}
static int F_5 ( struct V_1 * V_1 , unsigned int V_6 ,
unsigned int V_13 )
{
unsigned int V_14 ;
V_6 *= 512 >> V_13 ;
if ( V_1 -> V_15 % V_6 != 0 )
return - V_12 ;
V_14 = V_1 -> V_15 / V_6 ;
if ( V_14 < 1 || V_14 > 6 || V_14 == 5 )
return - V_12 ;
V_14 = V_14 - 1 ;
if ( V_14 == 5 )
V_14 = 4 ;
return V_14 ;
}
static int F_6 ( struct V_16 * V_17 ,
struct V_18 * V_19 , struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
struct V_1 * V_1 = F_7 ( V_23 ) ;
unsigned int V_6 = F_8 ( V_19 ) ;
unsigned int V_24 ;
unsigned int V_25 , V_26 ;
unsigned int V_27 ;
int V_14 , V_13 ;
int V_2 ;
V_13 = F_4 ( V_6 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_1 -> V_28 == V_29 ) {
V_14 = F_5 ( V_1 , V_6 , V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
} else {
V_14 = 0 ;
}
V_26 = V_30 ;
V_25 = V_13 ;
if ( V_1 -> V_31 ) {
switch ( F_9 ( V_19 ) ) {
case 16 :
V_25 |= V_32 ;
break;
case 24 :
V_25 |= V_33 ;
break;
default:
return - V_12 ;
}
V_26 |= V_34 ;
}
if ( V_1 -> V_35 ) {
switch ( F_9 ( V_19 ) ) {
case 16 :
V_27 = V_36 ;
V_24 = 16 ;
break;
case 24 :
case 32 :
V_27 = V_37 ;
V_24 = 32 ;
break;
default:
return - V_12 ;
}
if ( V_1 -> V_24 )
V_24 = V_1 -> V_24 ;
if ( V_24 == 16 )
V_27 |= V_38 ;
else
V_27 |= V_39 ;
V_2 = F_10 ( V_1 -> V_3 ,
V_40 ,
V_41 |
V_42 ,
V_27 ) ;
if ( V_2 < 0 )
return V_2 ;
}
V_2 = F_10 ( V_1 -> V_3 , V_43 ,
V_26 , V_25 ) ;
if ( V_2 < 0 )
return V_2 ;
return F_10 ( V_1 -> V_3 , V_44 ,
V_45 , V_14 ) ;
}
static int F_11 ( struct V_1 * V_1 )
{
int V_2 = 0 ;
if ( ! V_1 -> V_46 )
return 0 ;
V_2 = F_10 ( V_1 -> V_3 , V_4 ,
V_47 , 0 ) ;
if ( V_2 )
return V_2 ;
F_12 ( V_1 -> V_3 ) ;
if ( V_1 -> V_48 )
F_13 ( V_1 -> V_48 , 0 ) ;
F_14 ( V_1 -> V_3 , true ) ;
F_15 ( V_1 -> V_49 ) ;
if ( V_1 -> V_50 )
F_15 ( V_1 -> V_50 ) ;
V_1 -> V_46 = false ;
return 0 ;
}
static int F_16 ( struct V_1 * V_1 )
{
unsigned int V_51 ;
int V_2 = 0 ;
if ( V_1 -> V_46 )
return 0 ;
V_2 = F_17 ( V_1 -> V_49 ) ;
if ( V_2 )
return V_2 ;
if ( V_1 -> V_50 ) {
V_2 = F_17 ( V_1 -> V_50 ) ;
if ( V_2 )
goto V_52;
}
if ( V_1 -> V_48 )
F_13 ( V_1 -> V_48 , 1 ) ;
F_14 ( V_1 -> V_3 , false ) ;
if ( V_1 -> V_53 )
V_1 -> V_53 ( V_1 -> V_54 ) ;
V_2 = F_1 ( V_1 ) ;
if ( V_2 )
goto V_55;
V_2 = F_10 ( V_1 -> V_3 , V_4 ,
V_47 , V_47 ) ;
if ( V_2 )
goto V_55;
V_2 = F_18 ( V_1 -> V_3 ) ;
if ( V_2 )
goto V_55;
V_2 = F_19 ( V_1 -> V_3 , V_44 , & V_51 ) ;
if ( V_2 )
goto V_55;
if ( V_51 == 0x41 ) {
F_2 ( V_1 -> V_3 , true ) ;
V_2 = F_3 ( V_1 -> V_3 , V_44 ,
0x41 ) ;
if ( V_2 )
goto V_55;
F_2 ( V_1 -> V_3 , false ) ;
}
V_1 -> V_46 = true ;
return V_2 ;
V_55:
if ( V_1 -> V_50 )
F_15 ( V_1 -> V_50 ) ;
V_52:
F_15 ( V_1 -> V_49 ) ;
return V_2 ;
}
static int F_20 ( struct V_22 * V_23 ,
enum V_56 V_57 )
{
struct V_1 * V_1 = F_7 ( V_23 ) ;
int V_2 = 0 ;
switch ( V_57 ) {
case V_58 :
break;
case V_59 :
break;
case V_60 :
if ( F_21 ( V_23 ) == V_61 )
V_2 = F_16 ( V_1 ) ;
break;
case V_61 :
V_2 = F_11 ( V_1 ) ;
break;
}
return V_2 ;
}
static int F_22 ( struct V_20 * V_21 , unsigned int V_62 ,
unsigned int V_63 , int V_64 , int V_65 )
{
struct V_1 * V_1 = F_7 ( V_21 -> V_23 ) ;
unsigned int V_25 , V_27 , V_66 ;
unsigned int V_67 [ 4 ] ;
unsigned int V_68 ;
int V_2 ;
if ( V_64 == 0 ) {
V_1 -> V_24 = 0 ;
V_1 -> V_69 = 192000 ;
return F_10 ( V_1 -> V_3 ,
V_43 , V_70 ,
V_71 ) ;
}
if ( V_63 == 0 || V_62 != 0 )
return - V_12 ;
V_66 = 0 ;
for ( V_68 = 0 ; V_68 < 4 ; V_68 ++ ) {
V_67 [ V_68 ] = F_23 ( V_63 ) ;
V_66 |= F_24 ( V_68 ) ;
V_63 &= ~ ( 1 << V_67 [ V_68 ] ) ;
if ( V_67 [ V_68 ] >= V_64 )
return - V_12 ;
if ( V_63 == 0 )
break;
}
if ( V_63 != 0 )
return - V_12 ;
switch ( V_65 ) {
case 16 :
V_27 = V_72 ;
break;
case 24 :
if ( V_1 -> V_35 )
return - V_12 ;
V_27 = V_73 ;
break;
case 32 :
V_27 = V_74 ;
break;
default:
return - V_12 ;
}
switch ( V_64 ) {
case 2 :
V_25 = V_75 ;
break;
case 4 :
V_25 = V_76 ;
break;
case 8 :
V_25 = V_77 ;
break;
case 16 :
V_25 = V_78 ;
break;
default:
return - V_12 ;
}
V_2 = F_10 ( V_1 -> V_3 , V_79 ,
F_24 ( 0 ) |
F_24 ( 1 ) |
F_24 ( 2 ) |
F_24 ( 3 ) , V_66 ) ;
if ( V_2 )
return V_2 ;
V_2 = F_3 ( V_1 -> V_3 , V_80 ,
( V_67 [ 1 ] << V_81 ) |
( V_67 [ 0 ] << V_82 ) ) ;
if ( V_2 )
return V_2 ;
V_2 = F_3 ( V_1 -> V_3 , V_83 ,
( V_67 [ 3 ] << V_81 ) |
( V_67 [ 2 ] << V_82 ) ) ;
if ( V_2 )
return V_2 ;
V_2 = F_10 ( V_1 -> V_3 , V_43 ,
V_70 , V_25 ) ;
if ( V_2 )
return V_2 ;
V_2 = F_10 ( V_1 -> V_3 , V_40 ,
V_84 , V_27 ) ;
if ( V_2 )
return V_2 ;
V_1 -> V_24 = V_65 ;
V_1 -> V_69 = F_25 ( 192000 , 24576000 / V_65 / V_64 ) ;
return 0 ;
}
static int F_26 ( struct V_20 * V_21 , int V_85 , int V_86 )
{
struct V_1 * V_1 = F_7 ( V_21 -> V_23 ) ;
unsigned int V_51 ;
if ( V_85 )
V_51 = V_87 ;
else
V_51 = 0 ;
return F_10 ( V_1 -> V_3 , V_88 ,
V_87 , V_51 ) ;
}
static int F_27 ( struct V_20 * V_21 , unsigned int V_89 )
{
struct V_1 * V_1 = F_7 ( V_21 -> V_23 ) ;
unsigned int V_25 = 0 , V_27 = 0 , V_90 = 0 ;
bool V_91 ;
int V_2 ;
switch ( V_89 & V_92 ) {
case V_93 :
V_1 -> V_35 = false ;
break;
case V_94 :
V_27 |= V_95 ;
V_1 -> V_35 = true ;
break;
default:
return - V_12 ;
}
switch ( V_89 & V_96 ) {
case V_97 :
V_91 = false ;
break;
case V_98 :
V_90 |= V_99 ;
V_91 = false ;
break;
case V_100 :
V_91 = true ;
break;
case V_101 :
V_90 |= V_99 ;
V_91 = true ;
break;
default:
return - V_12 ;
}
V_1 -> V_31 = false ;
switch ( V_89 & V_102 ) {
case V_103 :
V_25 |= V_104 ;
break;
case V_105 :
V_25 |= V_106 ;
V_91 = ! V_91 ;
break;
case V_107 :
V_25 |= V_33 ;
V_1 -> V_31 = true ;
V_91 = ! V_91 ;
break;
case V_108 :
V_27 |= V_109 ;
V_25 |= V_104 ;
V_91 = false ;
break;
case V_110 :
V_27 |= V_109 ;
V_25 |= V_106 ;
V_91 = false ;
break;
default:
return - V_12 ;
}
if ( V_91 )
V_90 |= V_111 ;
V_2 = F_10 ( V_1 -> V_3 , V_112 ,
V_111 |
V_99 , V_90 ) ;
if ( V_2 )
return V_2 ;
V_2 = F_10 ( V_1 -> V_3 , V_43 ,
V_34 ,
V_25 ) ;
if ( V_2 )
return V_2 ;
return F_10 ( V_1 -> V_3 , V_40 ,
V_95 | V_109 ,
V_27 ) ;
}
static int F_28 ( struct V_16 * V_17 ,
struct V_20 * V_21 )
{
struct V_1 * V_1 = F_7 ( V_21 -> V_23 ) ;
T_1 V_113 = 0 ;
if ( V_1 -> V_24 == 16 )
V_113 = V_114 | V_115 ;
else if ( V_1 -> V_31 || V_1 -> V_24 == 24 )
V_113 = V_114 | V_115 |
V_116 | V_117 ;
F_29 ( V_17 -> V_118 , 0 ,
V_119 , & V_1 -> V_120 ) ;
if ( V_1 -> V_35 )
F_30 ( V_17 -> V_118 ,
V_119 , 8000 , V_1 -> V_69 ) ;
if ( V_113 != 0 )
F_31 ( V_17 -> V_118 ,
V_121 , V_113 ) ;
return 0 ;
}
static int F_32 ( struct V_20 * V_21 , int V_122 )
{
struct V_1 * V_1 = F_7 ( V_21 -> V_23 ) ;
unsigned int V_51 ;
if ( V_122 )
V_51 = V_123 ;
else
V_51 = 0 ;
return F_10 ( V_1 -> V_3 , V_79 ,
V_123 , V_51 ) ;
}
static bool F_33 ( unsigned int V_124 , unsigned int V_125 )
{
unsigned int V_14 ;
if ( V_124 % ( V_125 * 128 ) != 0 )
return false ;
V_14 = V_124 / ( 128 * V_125 ) ;
if ( V_14 < 1 || V_14 > 6 || V_14 == 5 )
return false ;
return true ;
}
static int F_34 ( struct V_22 * V_23 ,
int V_126 , int V_127 , unsigned int V_128 , int V_129 )
{
struct V_1 * V_1 = F_7 ( V_23 ) ;
unsigned int V_130 = 0 ;
unsigned int V_131 ;
unsigned int V_2 ;
if ( V_129 != V_132 )
return - V_12 ;
if ( V_126 != V_133 )
return - V_12 ;
switch ( V_127 ) {
case V_29 :
V_131 = 0 ;
break;
case V_134 :
V_131 = V_135 ;
break;
default:
return - V_12 ;
}
if ( V_128 != 0 && V_127 == V_29 ) {
if ( V_128 < 4000000 || V_128 > 36864000 )
return - V_12 ;
if ( F_33 ( V_128 , 32000 ) )
V_130 |= V_136 ;
if ( F_33 ( V_128 , 44100 ) )
V_130 |= V_137 ;
if ( F_33 ( V_128 , 48000 ) )
V_130 |= V_138 ;
if ( V_130 == 0 )
return - V_12 ;
} else if ( V_127 == V_134 ) {
V_130 = V_139 ;
}
V_2 = F_10 ( V_1 -> V_3 , V_44 ,
V_135 , V_131 ) ;
if ( V_2 )
return V_2 ;
V_1 -> V_120 . V_130 = V_130 ;
V_1 -> V_28 = V_127 ;
V_1 -> V_15 = V_128 ;
return 0 ;
}
static int F_35 ( struct V_22 * V_23 )
{
struct V_140 * V_141 = F_36 ( V_23 ) ;
struct V_1 * V_1 = F_7 ( V_23 ) ;
int V_2 ;
switch ( V_1 -> type ) {
case V_142 :
V_2 = F_37 ( V_141 ,
V_143 ,
F_38 ( V_143 ) ) ;
if ( V_2 < 0 )
return V_2 ;
break;
default:
break;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_1 )
{
struct V_144 * V_145 = V_1 -> V_54 -> V_146 ;
unsigned int V_147 ;
if ( V_145 ) {
V_147 = V_145 -> V_147 ;
if ( V_147 > V_148 )
return - V_12 ;
} else {
V_147 = V_149 ;
}
return F_10 ( V_1 -> V_3 , V_150 ,
V_151 ,
V_147 << V_152 ) ;
}
int F_40 ( struct V_153 * V_54 , struct V_3 * V_3 ,
enum V_154 type , void (* V_53)( struct V_153 * V_54 ) )
{
unsigned int V_155 ;
struct V_1 * V_1 ;
int V_2 ;
if ( F_41 ( V_3 ) )
return F_42 ( V_3 ) ;
V_1 = F_43 ( V_54 , sizeof( * V_1 ) , V_156 ) ;
if ( V_1 == NULL )
return - V_157 ;
V_1 -> V_54 = V_54 ;
V_1 -> type = type ;
V_1 -> V_3 = V_3 ;
V_1 -> V_53 = V_53 ;
V_1 -> V_69 = 192000 ;
V_1 -> V_120 . V_158 = V_159 ;
V_1 -> V_120 . V_160 = F_38 ( V_159 ) ;
V_1 -> V_49 = F_44 ( V_54 , L_1 ) ;
if ( F_41 ( V_1 -> V_49 ) )
return F_42 ( V_1 -> V_49 ) ;
V_1 -> V_50 = F_45 ( V_54 , L_2 ) ;
if ( F_41 ( V_1 -> V_50 ) ) {
if ( F_42 ( V_1 -> V_50 ) != - V_161 )
return F_42 ( V_1 -> V_50 ) ;
V_1 -> V_50 = NULL ;
}
V_1 -> V_48 = F_46 ( V_54 , L_3 ,
V_162 ) ;
if ( F_41 ( V_1 -> V_48 ) )
return F_42 ( V_1 -> V_48 ) ;
F_47 ( V_54 , V_1 ) ;
if ( V_1 -> V_48 )
F_48 ( 100 ) ;
V_2 = F_16 ( V_1 ) ;
if ( V_2 )
return V_2 ;
if ( type == V_142 ) {
V_2 = F_39 ( V_1 ) ;
if ( V_2 )
goto V_163;
}
if ( V_1 -> V_50 )
V_155 = ~ 0 ;
else
V_155 = ( unsigned int ) ~ V_164 ;
V_2 = F_10 ( V_1 -> V_3 , V_112 ,
V_155 , 0x00 ) ;
if ( V_2 )
goto V_163;
V_2 = F_11 ( V_1 ) ;
if ( V_2 )
return V_2 ;
return F_49 ( V_54 , & V_165 ,
& V_166 , 1 ) ;
V_163:
F_11 ( V_1 ) ;
return V_2 ;
}
static bool F_50 ( struct V_153 * V_54 , unsigned int V_167 )
{
switch ( V_167 ) {
case F_51 ( 0 ) :
case F_51 ( 1 ) :
case F_51 ( 2 ) :
case F_51 ( 3 ) :
case V_168 :
return true ;
}
return false ;
}
