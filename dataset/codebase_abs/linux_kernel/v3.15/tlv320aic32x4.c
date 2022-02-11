static inline int F_1 ( int V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( ( V_4 [ V_3 ] . V_2 == V_2 )
&& ( V_4 [ V_3 ] . V_1 == V_1 ) ) {
return V_3 ;
}
}
F_3 ( V_5 L_1 ) ;
return - V_6 ;
}
static int F_4 ( struct V_7 * V_8 ,
int V_9 , unsigned int V_10 , int V_11 )
{
struct V_12 * V_13 = V_8 -> V_13 ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
switch ( V_10 ) {
case V_16 :
case V_17 :
case V_18 :
V_15 -> V_19 = V_10 ;
return 0 ;
}
F_3 ( V_5 L_2 ) ;
return - V_6 ;
}
static int F_6 ( struct V_7 * V_8 , unsigned int V_20 )
{
struct V_12 * V_13 = V_8 -> V_13 ;
T_1 V_21 ;
T_1 V_22 ;
T_1 V_23 ;
V_21 = F_7 ( V_13 , V_24 ) ;
V_21 = V_21 & ~ ( 3 << 6 | 3 << 2 ) ;
V_22 = F_7 ( V_13 , V_25 ) ;
V_22 = 0 ;
V_23 = F_7 ( V_13 , V_26 ) ;
V_23 = V_23 & ~ ( 1 << 3 ) ;
switch ( V_20 & V_27 ) {
case V_28 :
V_21 |= V_29 | V_30 ;
break;
case V_31 :
break;
default:
F_3 ( V_5 L_3 ) ;
return - V_6 ;
}
switch ( V_20 & V_32 ) {
case V_33 :
break;
case V_34 :
V_21 |= ( V_35 << V_36 ) ;
V_23 |= ( 1 << 3 ) ;
V_22 = 0x01 ;
break;
case V_37 :
V_21 |= ( V_35 << V_36 ) ;
V_23 |= ( 1 << 3 ) ;
break;
case V_38 :
V_21 |=
( V_39 << V_36 ) ;
break;
case V_40 :
V_21 |=
( V_41 << V_36 ) ;
break;
default:
F_3 ( V_5 L_4 ) ;
return - V_6 ;
}
F_8 ( V_13 , V_24 , V_21 ) ;
F_8 ( V_13 , V_25 , V_22 ) ;
F_8 ( V_13 , V_26 , V_23 ) ;
return 0 ;
}
static int F_9 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
struct V_7 * V_46 )
{
struct V_12 * V_13 = V_46 -> V_13 ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
T_1 V_47 ;
int V_3 ;
V_3 = F_1 ( V_15 -> V_19 , F_10 ( V_45 ) ) ;
if ( V_3 < 0 ) {
F_3 ( V_5 L_5 ) ;
return V_3 ;
}
F_8 ( V_13 , V_48 , V_49 ) ;
F_8 ( V_13 , V_26 , V_50 ) ;
V_47 = F_7 ( V_13 , V_51 ) ;
V_47 &= ~ ( 7 << 4 ) ;
F_8 ( V_13 , V_51 ,
( V_47 | ( V_4 [ V_3 ] . V_52 << 4 ) | 0x01 ) ) ;
F_8 ( V_13 , V_53 , V_4 [ V_3 ] . V_54 ) ;
F_8 ( V_13 , V_55 , ( V_4 [ V_3 ] . V_56 >> 8 ) ) ;
F_8 ( V_13 , V_57 ,
( V_4 [ V_3 ] . V_56 & 0xff ) ) ;
V_47 = F_7 ( V_13 , V_58 ) ;
V_47 &= ~ ( 0x7f ) ;
F_8 ( V_13 , V_58 , V_47 | V_4 [ V_3 ] . V_59 ) ;
V_47 = F_7 ( V_13 , V_60 ) ;
V_47 &= ~ ( 0x7f ) ;
F_8 ( V_13 , V_60 , V_47 | V_4 [ V_3 ] . V_61 ) ;
F_8 ( V_13 , V_62 , V_4 [ V_3 ] . V_63 >> 8 ) ;
F_8 ( V_13 , V_64 ,
( V_4 [ V_3 ] . V_63 & 0xff ) ) ;
V_47 = F_7 ( V_13 , V_65 ) ;
V_47 &= ~ ( 0x7f ) ;
F_8 ( V_13 , V_65 , V_47 | V_4 [ V_3 ] . V_66 ) ;
V_47 = F_7 ( V_13 , V_67 ) ;
V_47 &= ~ ( 0x7f ) ;
F_8 ( V_13 , V_67 , V_47 | V_4 [ V_3 ] . V_68 ) ;
F_8 ( V_13 , V_69 , V_4 [ V_3 ] . V_70 ) ;
V_47 = F_7 ( V_13 , V_71 ) ;
V_47 &= ~ ( 0x7f ) ;
F_8 ( V_13 , V_71 , V_47 | V_4 [ V_3 ] . V_72 ) ;
V_47 = F_7 ( V_13 , V_24 ) ;
V_47 = V_47 & ~ ( 3 << 4 ) ;
switch ( F_11 ( V_45 ) ) {
case V_73 :
break;
case V_74 :
V_47 |= ( V_75 << V_76 ) ;
break;
case V_77 :
V_47 |= ( V_78 << V_76 ) ;
break;
case V_79 :
V_47 |= ( V_80 << V_76 ) ;
break;
}
F_8 ( V_13 , V_24 , V_47 ) ;
if ( F_12 ( V_45 ) == 1 ) {
V_47 = V_81 | V_82 ;
} else {
if ( V_15 -> V_83 )
V_47 = V_81 | V_84 ;
else
V_47 = V_82 | V_85 ;
}
F_13 ( V_13 , V_86 , V_87 ,
V_47 ) ;
return 0 ;
}
static int F_14 ( struct V_7 * V_46 , int V_88 )
{
struct V_12 * V_13 = V_46 -> V_13 ;
T_1 V_89 ;
V_89 = F_7 ( V_13 , V_90 ) & ~ V_91 ;
if ( V_88 )
F_8 ( V_13 , V_90 , V_89 | V_91 ) ;
else
F_8 ( V_13 , V_90 , V_89 ) ;
return 0 ;
}
static int F_15 ( struct V_12 * V_13 ,
enum V_92 V_93 )
{
struct V_14 * V_15 = F_5 ( V_13 ) ;
int V_94 ;
switch ( V_93 ) {
case V_95 :
V_94 = F_16 ( V_15 -> V_1 ) ;
if ( V_94 ) {
F_17 ( V_13 -> V_96 , L_6 ) ;
return V_94 ;
}
F_13 ( V_13 , V_51 ,
V_97 , V_97 ) ;
F_13 ( V_13 , V_58 ,
V_98 , V_98 ) ;
F_13 ( V_13 , V_60 ,
V_99 , V_99 ) ;
F_13 ( V_13 , V_65 ,
V_100 , V_100 ) ;
F_13 ( V_13 , V_67 ,
V_101 , V_101 ) ;
F_13 ( V_13 , V_71 ,
V_102 , V_102 ) ;
break;
case V_103 :
break;
case V_104 :
F_13 ( V_13 , V_71 ,
V_102 , 0 ) ;
F_13 ( V_13 , V_67 ,
V_101 , 0 ) ;
F_13 ( V_13 , V_65 ,
V_100 , 0 ) ;
F_13 ( V_13 , V_60 ,
V_99 , 0 ) ;
F_13 ( V_13 , V_58 ,
V_98 , 0 ) ;
F_13 ( V_13 , V_51 ,
V_97 , 0 ) ;
F_18 ( V_15 -> V_1 ) ;
break;
case V_105 :
break;
}
V_13 -> V_106 . V_107 = V_93 ;
return 0 ;
}
static int F_19 ( struct V_12 * V_13 )
{
F_15 ( V_13 , V_105 ) ;
return 0 ;
}
static int F_20 ( struct V_12 * V_13 )
{
F_15 ( V_13 , V_104 ) ;
return 0 ;
}
static int F_21 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_5 ( V_13 ) ;
T_2 V_108 ;
if ( F_22 ( V_15 -> V_109 ) ) {
F_23 ( 10 ) ;
F_24 ( V_15 -> V_109 , 1 ) ;
}
F_8 ( V_13 , V_110 , 0x01 ) ;
if ( V_15 -> V_111 & V_112 ) {
F_8 ( V_13 , V_113 , V_114 |
V_115 ) ;
}
if ( V_15 -> V_111 & V_116 ) {
F_8 ( V_13 , V_117 , V_118 ) ;
}
V_108 = ( V_15 -> V_111 & V_119 ) ?
V_120 : 0 ;
F_8 ( V_13 , V_121 , V_108 ) ;
V_108 = F_7 ( V_13 , V_122 ) ;
if ( V_15 -> V_111 & V_123 ) {
V_108 |= V_124 ;
}
if ( V_15 -> V_111 & V_125 ) {
V_108 |= V_126 ;
}
F_8 ( V_13 , V_122 , V_108 ) ;
if ( V_15 -> V_127 & V_128 )
F_8 ( V_13 , V_129 , V_130 ) ;
else
F_8 ( V_13 , V_129 , V_131 ) ;
if ( V_15 -> V_127 & V_132 )
F_8 ( V_13 , V_133 , V_134 ) ;
else
F_8 ( V_13 , V_133 , V_135 ) ;
F_15 ( V_13 , V_104 ) ;
V_108 = F_7 ( V_13 , V_136 ) ;
F_8 ( V_13 , V_136 , V_108 |
V_137 | V_138 ) ;
F_8 ( V_13 , V_136 , V_108 ) ;
return 0 ;
}
static int F_25 ( struct V_12 * V_13 )
{
F_15 ( V_13 , V_105 ) ;
return 0 ;
}
static int F_26 ( struct V_14 * V_15 ,
struct V_139 * V_140 )
{
V_15 -> V_83 = false ;
V_15 -> V_127 = 0 ;
V_15 -> V_109 = F_27 ( V_140 , L_7 , 0 ) ;
return 0 ;
}
static void F_28 ( struct V_14 * V_15 )
{
F_29 ( V_15 -> V_141 ) ;
if ( ! F_30 ( V_15 -> V_142 ) )
F_29 ( V_15 -> V_142 ) ;
if ( ! F_30 ( V_15 -> V_143 ) )
F_29 ( V_15 -> V_143 ) ;
if ( ! F_30 ( V_15 -> V_144 ) )
F_29 ( V_15 -> V_144 ) ;
}
static int F_31 ( struct V_145 * V_96 ,
struct V_14 * V_15 )
{
int V_94 = 0 ;
V_15 -> V_142 = F_32 ( V_96 , L_8 ) ;
V_15 -> V_141 = F_33 ( V_96 , L_9 ) ;
V_15 -> V_143 = F_32 ( V_96 , L_10 ) ;
V_15 -> V_144 = F_32 ( V_96 , L_11 ) ;
if ( F_30 ( V_15 -> V_141 ) ) {
F_17 ( V_96 , L_12 ) ;
return F_34 ( V_15 -> V_141 ) ;
}
if ( F_30 ( V_15 -> V_142 ) ) {
if ( F_34 ( V_15 -> V_142 ) == - V_146 )
return - V_146 ;
if ( F_30 ( V_15 -> V_143 ) ) {
F_17 ( V_96 , L_13 ) ;
return F_34 ( V_15 -> V_143 ) ;
}
if ( F_30 ( V_15 -> V_144 ) ) {
F_17 ( V_96 , L_14 ) ;
return F_34 ( V_15 -> V_144 ) ;
}
} else {
if ( F_30 ( V_15 -> V_143 ) &&
F_34 ( V_15 -> V_143 ) == - V_146 )
return - V_146 ;
if ( F_30 ( V_15 -> V_144 ) &&
F_34 ( V_15 -> V_144 ) == - V_146 )
return - V_146 ;
}
V_94 = F_35 ( V_15 -> V_141 ) ;
if ( V_94 ) {
F_17 ( V_96 , L_15 ) ;
return V_94 ;
}
if ( ! F_30 ( V_15 -> V_142 ) ) {
V_94 = F_35 ( V_15 -> V_142 ) ;
if ( V_94 ) {
F_17 ( V_96 , L_16 ) ;
goto V_147;
}
}
if ( ! F_30 ( V_15 -> V_143 ) ) {
V_94 = F_35 ( V_15 -> V_143 ) ;
if ( V_94 ) {
F_17 ( V_96 , L_17 ) ;
goto V_148;
}
}
if ( ! F_30 ( V_15 -> V_144 ) ) {
V_94 = F_35 ( V_15 -> V_144 ) ;
if ( V_94 ) {
F_17 ( V_96 , L_18 ) ;
goto V_149;
}
}
if ( ! F_30 ( V_15 -> V_142 ) && F_30 ( V_15 -> V_144 ) )
V_15 -> V_111 |= V_119 ;
return 0 ;
V_149:
if ( ! F_30 ( V_15 -> V_143 ) )
F_29 ( V_15 -> V_143 ) ;
V_148:
if ( ! F_30 ( V_15 -> V_142 ) )
F_29 ( V_15 -> V_142 ) ;
V_147:
F_29 ( V_15 -> V_141 ) ;
return V_94 ;
}
static int F_36 ( struct V_150 * V_151 ,
const struct V_152 * V_153 )
{
struct V_154 * V_155 = V_151 -> V_96 . V_156 ;
struct V_14 * V_15 ;
struct V_139 * V_140 = V_151 -> V_96 . V_157 ;
int V_94 ;
V_15 = F_37 ( & V_151 -> V_96 , sizeof( struct V_14 ) ,
V_158 ) ;
if ( V_15 == NULL )
return - V_159 ;
V_15 -> V_160 = F_38 ( V_151 , & V_161 ) ;
if ( F_30 ( V_15 -> V_160 ) )
return F_34 ( V_15 -> V_160 ) ;
F_39 ( V_151 , V_15 ) ;
if ( V_155 ) {
V_15 -> V_111 = V_155 -> V_111 ;
V_15 -> V_83 = V_155 -> V_83 ;
V_15 -> V_127 = V_155 -> V_127 ;
V_15 -> V_109 = V_155 -> V_109 ;
} else if ( V_140 ) {
V_94 = F_26 ( V_15 , V_140 ) ;
if ( V_94 ) {
F_17 ( & V_151 -> V_96 , L_19 ) ;
return V_94 ;
}
} else {
V_15 -> V_111 = 0 ;
V_15 -> V_83 = false ;
V_15 -> V_127 = 0 ;
V_15 -> V_109 = - 1 ;
}
V_15 -> V_1 = F_40 ( & V_151 -> V_96 , L_20 ) ;
if ( F_30 ( V_15 -> V_1 ) ) {
F_17 ( & V_151 -> V_96 , L_21 ) ;
return F_34 ( V_15 -> V_1 ) ;
}
if ( F_22 ( V_15 -> V_109 ) ) {
V_94 = F_41 ( & V_151 -> V_96 , V_15 -> V_109 ,
V_162 , L_22 ) ;
if ( V_94 != 0 )
return V_94 ;
}
V_94 = F_31 ( & V_151 -> V_96 , V_15 ) ;
if ( V_94 ) {
F_17 ( & V_151 -> V_96 , L_23 ) ;
return V_94 ;
}
V_94 = F_42 ( & V_151 -> V_96 ,
& V_163 , & V_164 , 1 ) ;
if ( V_94 ) {
F_17 ( & V_151 -> V_96 , L_24 ) ;
F_28 ( V_15 ) ;
return V_94 ;
}
F_39 ( V_151 , V_15 ) ;
return 0 ;
}
static int F_43 ( struct V_150 * V_165 )
{
struct V_14 * V_15 = F_44 ( V_165 ) ;
F_28 ( V_15 ) ;
F_45 ( & V_165 -> V_96 ) ;
return 0 ;
}
