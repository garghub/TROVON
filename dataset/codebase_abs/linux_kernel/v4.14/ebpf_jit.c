static void F_1 ( T_1 * V_1 , int V_2 , enum V_3 type )
{
* V_1 &= ~ ( 7ull << ( V_2 * 3 ) ) ;
* V_1 |= ( ( T_1 ) type << ( V_2 * 3 ) ) ;
}
static enum V_3 F_2 ( const struct V_4 * V_5 ,
int V_6 , int V_2 )
{
return ( V_5 -> V_7 [ V_6 ] >> ( V_2 * 3 ) ) & 7 ;
}
static unsigned int F_3 ( struct V_4 * V_5 , int V_8 )
{
unsigned long V_9 , V_10 ;
unsigned int V_11 ;
if ( ! V_5 -> V_12 )
return 0 ;
V_10 = ( unsigned long ) V_5 -> V_12 ;
V_9 = V_10 + ( V_5 -> V_13 [ V_8 ] & ~ V_14 ) ;
if ( ( V_10 & ~ 0x0ffffffful ) != ( V_9 & ~ 0x0ffffffful ) )
return ( unsigned int ) - 1 ;
V_11 = V_9 & 0x0ffffffful ;
return V_11 ;
}
static T_2 F_4 ( unsigned int V_15 , struct V_4 * V_5 )
{
if ( ! V_5 -> V_16 )
return 0 ;
return ( V_5 -> V_13 [ V_15 ] & ~ V_14 ) -
( V_5 -> V_17 * 4 ) - 4 ;
}
int F_5 ( struct V_4 * V_5 , const struct V_18 * V_19 ,
enum V_20 V_21 )
{
int V_22 = ( V_21 == V_23 || V_21 == V_24 ) ?
V_19 -> V_23 : V_19 -> V_25 ;
switch ( V_22 ) {
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
case V_30 :
return V_31 ;
case V_32 :
return V_33 ;
case V_34 :
return V_35 ;
case V_36 :
return V_37 ;
case V_38 :
V_5 -> V_39 |= V_40 ;
return V_41 ;
case V_42 :
V_5 -> V_39 |= V_43 ;
return V_44 ;
case V_45 :
V_5 -> V_39 |= V_46 ;
return V_47 ;
case V_48 :
V_5 -> V_39 |= V_49 ;
return V_50 ;
case V_51 :
if ( V_21 == V_25 || V_21 == V_24 )
goto V_52;
V_5 -> V_39 |= V_53 ;
return V_54 ;
case V_55 :
return V_56 ;
default:
V_52:
F_6 ( 1 , L_1 , V_22 ) ;
return - V_57 ;
}
}
static int F_7 ( struct V_4 * V_5 )
{
int V_58 = 0 ;
int V_59 ;
int V_60 ;
if ( V_5 -> V_39 & V_61 )
V_58 += 16 ;
if ( V_5 -> V_39 & V_40 )
V_58 += 8 ;
if ( V_5 -> V_39 & V_43 )
V_58 += 8 ;
if ( V_5 -> V_39 & V_46 )
V_58 += 8 ;
if ( V_5 -> V_39 & V_49 )
V_58 += 8 ;
if ( V_5 -> V_39 & V_62 )
V_58 += 8 ;
F_8 ( V_63 & 7 ) ;
V_60 = ( V_5 -> V_39 & V_53 ) ? V_63 : 0 ;
V_58 += V_60 ;
V_5 -> V_64 = V_60 ;
V_5 -> V_65 = V_58 ;
F_9 ( V_5 , V_66 , V_67 , V_54 , V_68 ) ;
if ( V_58 )
F_9 ( V_5 , V_66 , V_69 , V_69 , - V_58 ) ;
else
return 0 ;
V_59 = V_58 - 8 ;
if ( V_5 -> V_39 & V_61 ) {
F_9 ( V_5 , V_70 , V_71 , V_59 , V_69 ) ;
V_59 -= 8 ;
}
if ( V_5 -> V_39 & V_40 ) {
F_9 ( V_5 , V_70 , V_41 , V_59 , V_69 ) ;
V_59 -= 8 ;
}
if ( V_5 -> V_39 & V_43 ) {
F_9 ( V_5 , V_70 , V_44 , V_59 , V_69 ) ;
V_59 -= 8 ;
}
if ( V_5 -> V_39 & V_46 ) {
F_9 ( V_5 , V_70 , V_47 , V_59 , V_69 ) ;
V_59 -= 8 ;
}
if ( V_5 -> V_39 & V_49 ) {
F_9 ( V_5 , V_70 , V_50 , V_59 , V_69 ) ;
V_59 -= 8 ;
}
if ( V_5 -> V_39 & V_62 ) {
F_9 ( V_5 , V_70 , V_72 , V_59 , V_69 ) ;
V_59 -= 8 ;
}
if ( ( V_5 -> V_39 & V_73 ) && ! ( V_5 -> V_39 & V_74 ) )
F_9 ( V_5 , V_75 , V_72 , V_67 , V_54 ) ;
return 0 ;
}
static int F_10 ( struct V_4 * V_5 , int V_76 )
{
const struct V_77 * V_78 = V_5 -> V_79 ;
int V_58 = V_5 -> V_65 ;
int V_59 = V_58 - 8 ;
int V_80 = V_27 ;
if ( V_76 == V_71 &&
F_2 ( V_5 , V_78 -> V_81 , V_26 ) == V_82 )
F_9 ( V_5 , V_83 , V_80 , V_80 , 0 ) ;
if ( V_5 -> V_39 & V_61 ) {
F_9 ( V_5 , V_84 , V_71 , V_59 , V_69 ) ;
V_59 -= 8 ;
}
if ( V_5 -> V_39 & V_40 ) {
F_9 ( V_5 , V_84 , V_41 , V_59 , V_69 ) ;
V_59 -= 8 ;
}
if ( V_5 -> V_39 & V_43 ) {
F_9 ( V_5 , V_84 , V_44 , V_59 , V_69 ) ;
V_59 -= 8 ;
}
if ( V_5 -> V_39 & V_46 ) {
F_9 ( V_5 , V_84 , V_47 , V_59 , V_69 ) ;
V_59 -= 8 ;
}
if ( V_5 -> V_39 & V_49 ) {
F_9 ( V_5 , V_84 , V_50 , V_59 , V_69 ) ;
V_59 -= 8 ;
}
if ( V_5 -> V_39 & V_62 ) {
F_9 ( V_5 , V_84 , V_72 , V_59 , V_69 ) ;
V_59 -= 8 ;
}
F_9 ( V_5 , V_85 , V_76 ) ;
if ( V_58 )
F_9 ( V_5 , V_66 , V_69 , V_69 , V_58 ) ;
else
F_9 ( V_5 , V_86 ) ;
return 0 ;
}
static void F_11 ( const struct V_18 * V_19 , int V_2 ,
struct V_4 * V_5 )
{
if ( V_19 -> V_87 >= V_88 && V_19 -> V_87 <= V_89 ) {
F_9 ( V_5 , V_90 , V_2 , V_54 , V_19 -> V_87 ) ;
} else {
int V_91 = ( V_92 ) ( V_19 -> V_87 & 0xffff ) ;
int V_93 = V_19 -> V_87 - V_91 ;
F_9 ( V_5 , V_94 , V_2 , V_93 >> 16 ) ;
F_9 ( V_5 , V_90 , V_2 , V_2 , V_91 ) ;
}
}
static int F_12 ( const struct V_18 * V_19 , struct V_4 * V_5 ,
int V_17 )
{
int V_95 , V_96 ;
int V_97 = F_5 ( V_5 , V_19 , V_25 ) ;
if ( V_97 < 0 )
return V_97 ;
switch ( F_13 ( V_19 -> V_98 ) ) {
case V_99 :
case V_100 :
V_95 = V_89 ;
V_96 = V_88 ;
break;
case V_101 :
V_95 = - ( int ) V_88 ;
V_96 = - ( int ) V_89 ;
break;
case V_102 :
case V_103 :
case V_104 :
V_95 = 0xffff ;
V_96 = 0 ;
break;
case V_105 :
case V_106 :
case V_107 :
V_95 = V_108 ;
V_96 = V_109 ;
break;
default:
return - V_57 ;
}
if ( F_14 ( V_19 -> V_98 ) == V_110 &&
F_13 ( V_19 -> V_98 ) != V_99 &&
F_2 ( V_5 , V_17 , V_19 -> V_25 ) == V_111 )
F_9 ( V_5 , V_112 , V_97 , V_54 , 32 , 32 ) ;
if ( F_14 ( V_19 -> V_98 ) == V_113 &&
F_13 ( V_19 -> V_98 ) != V_106 &&
F_13 ( V_19 -> V_98 ) != V_99 &&
F_2 ( V_5 , V_17 , V_19 -> V_25 ) != V_111 )
F_9 ( V_5 , V_83 , V_97 , V_97 , 0 ) ;
if ( V_19 -> V_87 >= V_96 && V_19 -> V_87 <= V_95 ) {
switch ( F_13 ( V_19 -> V_98 ) | F_14 ( V_19 -> V_98 ) ) {
case V_110 | V_99 :
F_9 ( V_5 , V_66 , V_97 , V_54 , V_19 -> V_87 ) ;
break;
case V_110 | V_102 :
case V_113 | V_102 :
F_9 ( V_5 , V_114 , V_97 , V_97 , V_19 -> V_87 ) ;
break;
case V_110 | V_103 :
case V_113 | V_103 :
F_9 ( V_5 , V_115 , V_97 , V_97 , V_19 -> V_87 ) ;
break;
case V_110 | V_104 :
case V_113 | V_104 :
F_9 ( V_5 , V_116 , V_97 , V_97 , V_19 -> V_87 ) ;
break;
case V_110 | V_100 :
F_9 ( V_5 , V_66 , V_97 , V_97 , V_19 -> V_87 ) ;
break;
case V_110 | V_101 :
F_9 ( V_5 , V_66 , V_97 , V_97 , - V_19 -> V_87 ) ;
break;
case V_110 | V_105 :
F_9 ( V_5 , V_117 , V_97 , V_97 , V_19 -> V_87 & 0x3f ) ;
break;
case V_113 | V_105 :
F_9 ( V_5 , V_118 , V_97 , V_97 , V_19 -> V_87 & 0x1f ) ;
break;
case V_110 | V_106 :
F_9 ( V_5 , V_119 , V_97 , V_97 , V_19 -> V_87 & 0x3f ) ;
break;
case V_113 | V_106 :
F_9 ( V_5 , V_83 , V_97 , V_97 , V_19 -> V_87 & 0x1f ) ;
break;
case V_110 | V_107 :
F_9 ( V_5 , V_120 , V_97 , V_97 , V_19 -> V_87 & 0x3f ) ;
break;
case V_113 | V_107 :
F_9 ( V_5 , V_121 , V_97 , V_97 , V_19 -> V_87 & 0x1f ) ;
break;
case V_113 | V_99 :
F_9 ( V_5 , V_90 , V_97 , V_54 , V_19 -> V_87 ) ;
break;
case V_113 | V_100 :
F_9 ( V_5 , V_90 , V_97 , V_97 , V_19 -> V_87 ) ;
break;
case V_113 | V_101 :
F_9 ( V_5 , V_90 , V_97 , V_97 , - V_19 -> V_87 ) ;
break;
default:
return - V_57 ;
}
} else {
if ( F_13 ( V_19 -> V_98 ) == V_99 ) {
F_11 ( V_19 , V_97 , V_5 ) ;
} else {
F_11 ( V_19 , V_122 , V_5 ) ;
switch ( F_13 ( V_19 -> V_98 ) | F_14 ( V_19 -> V_98 ) ) {
case V_110 | V_102 :
case V_113 | V_102 :
F_9 ( V_5 , V_123 , V_97 , V_97 , V_122 ) ;
break;
case V_110 | V_103 :
case V_113 | V_103 :
F_9 ( V_5 , V_124 , V_97 , V_97 , V_122 ) ;
break;
case V_110 | V_104 :
case V_113 | V_104 :
F_9 ( V_5 , V_125 , V_97 , V_97 , V_122 ) ;
break;
case V_110 | V_100 :
F_9 ( V_5 , V_75 , V_97 , V_97 , V_122 ) ;
break;
case V_110 | V_101 :
F_9 ( V_5 , V_126 , V_97 , V_97 , V_122 ) ;
break;
case V_113 | V_100 :
F_9 ( V_5 , V_127 , V_97 , V_97 , V_122 ) ;
break;
case V_113 | V_101 :
F_9 ( V_5 , V_128 , V_97 , V_97 , V_122 ) ;
break;
default:
return - V_57 ;
}
}
}
return 0 ;
}
static void * T_3
F_15 ( const struct V_129 * V_130 , int V_131 ,
int V_81 , void * V_132 )
{
return F_16 ( V_130 , V_131 , V_81 , V_132 ) ;
}
static int F_17 ( const struct V_18 * V_19 )
{
switch ( F_18 ( V_19 -> V_98 ) ) {
case V_133 :
return 1 ;
case V_134 :
return 2 ;
case V_135 :
return 4 ;
case V_136 :
return 8 ;
}
return 0 ;
}
static void F_19 ( struct V_4 * V_5 , int V_97 , T_1 V_137 )
{
if ( V_137 >= 0xffffffffffff8000ull || V_137 < 0x8000ull ) {
F_9 ( V_5 , V_66 , V_97 , V_54 , ( int ) V_137 ) ;
} else if ( V_137 >= 0xffffffff80000000ull ||
( V_137 < 0x80000000 && V_137 > 0xffff ) ) {
F_9 ( V_5 , V_94 , V_97 , ( V_138 ) ( V_92 ) ( V_137 >> 16 ) ) ;
F_9 ( V_5 , V_115 , V_97 , V_97 , ( unsigned int ) ( V_137 & 0xffff ) ) ;
} else {
int V_139 ;
bool V_140 = false ;
int V_141 = 0 ;
for ( V_139 = 0 ; V_139 < 4 ; V_139 ++ ) {
T_1 V_142 = ( V_137 >> ( 16 * ( 3 - V_139 ) ) ) & 0xffff ;
if ( V_140 && V_141 > 0 && ( V_142 || V_139 == 3 ) ) {
F_9 ( V_5 , V_119 , V_97 , V_97 , V_141 ) ;
V_141 = 0 ;
}
if ( V_142 ) {
if ( V_139 == 0 || ( ! V_140 && V_139 < 3 && V_142 < 0x8000 ) ) {
F_9 ( V_5 , V_94 , V_97 , ( V_138 ) ( V_92 ) V_142 ) ;
V_141 = - 16 ;
} else {
F_9 ( V_5 , V_115 , V_97 ,
V_140 ? V_97 : V_54 ,
( unsigned int ) V_142 ) ;
}
V_140 = true ;
}
if ( V_140 )
V_141 += 16 ;
}
}
}
static int F_20 ( struct V_4 * V_5 , int V_143 )
{
int V_144 , V_145 ;
V_5 -> V_39 |= V_73 ;
V_144 = F_21 ( struct V_146 , V_147 . V_148 ) ;
F_9 ( V_5 , V_149 , V_150 , V_144 , V_31 ) ;
F_9 ( V_5 , V_151 , V_122 , V_150 , V_33 ) ;
V_145 = F_4 ( V_143 + 1 , V_5 ) ;
F_9 ( V_5 , V_152 , V_122 , V_54 , V_145 ) ;
F_9 ( V_5 , V_66 , V_150 ,
( V_5 -> V_39 & V_74 ) ? V_67 : V_72 , - 1 ) ;
V_145 = F_4 ( V_143 + 1 , V_5 ) ;
F_9 ( V_5 , V_153 , V_150 , V_145 ) ;
F_9 ( V_5 , V_154 , V_155 , V_33 , 3 ) ;
F_9 ( V_5 , V_75 , V_155 , V_155 , V_31 ) ;
V_144 = F_21 ( struct V_146 , V_156 ) ;
F_9 ( V_5 , V_84 , V_122 , V_144 , V_155 ) ;
V_145 = F_4 ( V_143 + 1 , V_5 ) ;
F_9 ( V_5 , V_157 , V_122 , V_54 , V_145 ) ;
F_9 ( V_5 , V_86 ) ;
V_144 = F_21 ( struct V_77 , V_158 ) ;
F_9 ( V_5 , V_84 , V_159 , V_144 , V_122 ) ;
F_9 ( V_5 , V_75 , V_67 , V_150 , V_54 ) ;
F_9 ( V_5 , V_66 , V_159 , V_159 , 4 ) ;
return F_10 ( V_5 , V_159 ) ;
}
static bool F_22 ( int V_145 )
{
return V_145 > 0x1ffff || V_145 < - 0x20000 ;
}
static int F_23 ( const struct V_18 * V_19 , struct V_4 * V_5 ,
int V_143 , int V_160 )
{
int V_161 , V_97 , V_11 , V_162 , V_163 , V_164 , V_145 ;
bool V_165 , V_166 , V_167 ;
unsigned int V_12 = 0 ;
T_1 V_168 ;
T_4 V_169 ;
int V_170 = F_13 ( V_19 -> V_98 ) ;
switch ( V_19 -> V_98 ) {
case V_110 | V_100 | V_171 :
case V_110 | V_101 | V_171 :
case V_110 | V_103 | V_171 :
case V_110 | V_102 | V_171 :
case V_110 | V_106 | V_171 :
case V_110 | V_105 | V_171 :
case V_110 | V_104 | V_171 :
case V_110 | V_107 | V_171 :
case V_110 | V_99 | V_171 :
case V_113 | V_99 | V_171 :
case V_113 | V_100 | V_171 :
case V_113 | V_101 | V_171 :
case V_113 | V_103 | V_171 :
case V_113 | V_102 | V_171 :
case V_113 | V_106 | V_171 :
case V_113 | V_105 | V_171 :
case V_113 | V_104 | V_171 :
case V_113 | V_107 | V_171 :
V_11 = F_12 ( V_19 , V_5 , V_143 ) ;
if ( V_11 < 0 )
return V_11 ;
break;
case V_110 | V_172 | V_171 :
V_97 = F_5 ( V_5 , V_19 , V_25 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( F_2 ( V_5 , V_143 , V_19 -> V_25 ) == V_111 )
F_9 ( V_5 , V_112 , V_97 , V_54 , 32 , 32 ) ;
if ( V_19 -> V_87 == 1 )
break;
F_11 ( V_19 , V_122 , V_5 ) ;
F_9 ( V_5 , V_173 , V_122 , V_97 ) ;
F_9 ( V_5 , V_174 , V_97 ) ;
break;
case V_110 | V_175 | V_171 :
V_97 = F_5 ( V_5 , V_19 , V_25 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( F_2 ( V_5 , V_143 , V_19 -> V_25 ) == V_111 )
F_9 ( V_5 , V_112 , V_97 , V_54 , 32 , 32 ) ;
F_9 ( V_5 , V_126 , V_97 , V_54 , V_97 ) ;
break;
case V_113 | V_172 | V_171 :
V_97 = F_5 ( V_5 , V_19 , V_25 ) ;
if ( V_97 < 0 )
return V_97 ;
V_162 = F_2 ( V_5 , V_143 , V_19 -> V_25 ) ;
if ( V_162 == V_176 || V_162 == V_82 ) {
F_9 ( V_5 , V_83 , V_97 , V_97 , 0 ) ;
}
if ( V_19 -> V_87 == 1 )
break;
F_11 ( V_19 , V_122 , V_5 ) ;
F_9 ( V_5 , V_177 , V_97 , V_122 ) ;
F_9 ( V_5 , V_174 , V_97 ) ;
break;
case V_113 | V_175 | V_171 :
V_97 = F_5 ( V_5 , V_19 , V_25 ) ;
if ( V_97 < 0 )
return V_97 ;
V_162 = F_2 ( V_5 , V_143 , V_19 -> V_25 ) ;
if ( V_162 == V_176 || V_162 == V_82 ) {
F_9 ( V_5 , V_83 , V_97 , V_97 , 0 ) ;
}
F_9 ( V_5 , V_128 , V_97 , V_54 , V_97 ) ;
break;
case V_113 | V_178 | V_171 :
case V_113 | V_179 | V_171 :
V_97 = F_5 ( V_5 , V_19 , V_25 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( V_19 -> V_87 == 0 ) {
V_145 = F_4 ( V_160 , V_5 ) ;
if ( F_22 ( V_145 ) )
return - V_180 ;
F_9 ( V_5 , V_157 , V_54 , V_54 , V_145 ) ;
F_9 ( V_5 , V_127 , V_27 , V_54 , V_54 ) ;
}
V_162 = F_2 ( V_5 , V_143 , V_19 -> V_25 ) ;
if ( V_162 == V_176 || V_162 == V_82 )
F_9 ( V_5 , V_83 , V_97 , V_97 , 0 ) ;
if ( V_19 -> V_87 == 1 ) {
if ( V_170 == V_179 )
F_9 ( V_5 , V_127 , V_97 , V_54 , V_54 ) ;
break;
}
F_11 ( V_19 , V_122 , V_5 ) ;
F_9 ( V_5 , V_181 , V_97 , V_122 ) ;
if ( V_170 == V_178 )
F_9 ( V_5 , V_174 , V_97 ) ;
else
F_9 ( V_5 , V_182 , V_97 ) ;
break;
case V_110 | V_178 | V_171 :
case V_110 | V_179 | V_171 :
V_97 = F_5 ( V_5 , V_19 , V_25 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( V_19 -> V_87 == 0 ) {
V_145 = F_4 ( V_160 , V_5 ) ;
if ( F_22 ( V_145 ) )
return - V_180 ;
F_9 ( V_5 , V_157 , V_54 , V_54 , V_145 ) ;
F_9 ( V_5 , V_127 , V_27 , V_54 , V_54 ) ;
}
if ( F_2 ( V_5 , V_143 , V_19 -> V_25 ) == V_111 )
F_9 ( V_5 , V_112 , V_97 , V_54 , 32 , 32 ) ;
if ( V_19 -> V_87 == 1 ) {
if ( V_170 == V_179 )
F_9 ( V_5 , V_127 , V_97 , V_54 , V_54 ) ;
break;
}
F_11 ( V_19 , V_122 , V_5 ) ;
F_9 ( V_5 , V_183 , V_97 , V_122 ) ;
if ( V_170 == V_178 )
F_9 ( V_5 , V_174 , V_97 ) ;
else
F_9 ( V_5 , V_182 , V_97 ) ;
break;
case V_110 | V_99 | V_184 :
case V_110 | V_100 | V_184 :
case V_110 | V_101 | V_184 :
case V_110 | V_104 | V_184 :
case V_110 | V_103 | V_184 :
case V_110 | V_102 | V_184 :
case V_110 | V_172 | V_184 :
case V_110 | V_178 | V_184 :
case V_110 | V_179 | V_184 :
case V_110 | V_106 | V_184 :
case V_110 | V_105 | V_184 :
case V_110 | V_107 | V_184 :
V_161 = F_5 ( V_5 , V_19 , V_23 ) ;
V_97 = F_5 ( V_5 , V_19 , V_25 ) ;
if ( V_161 < 0 || V_97 < 0 )
return - V_57 ;
if ( F_2 ( V_5 , V_143 , V_19 -> V_25 ) == V_111 )
F_9 ( V_5 , V_112 , V_97 , V_54 , 32 , 32 ) ;
V_166 = false ;
if ( V_19 -> V_23 == V_51 ) {
if ( V_170 == V_99 ) {
F_9 ( V_5 , V_66 , V_97 , V_69 , V_63 ) ;
V_166 = true ;
} else {
F_9 ( V_5 , V_66 , V_122 , V_69 , V_63 ) ;
V_161 = V_122 ;
}
} else if ( F_2 ( V_5 , V_143 , V_19 -> V_23 ) == V_111 ) {
int V_185 = V_122 ;
if ( V_170 == V_99 ) {
V_185 = V_97 ;
V_166 = true ;
}
F_9 ( V_5 , V_75 , V_185 , V_161 , V_54 ) ;
F_9 ( V_5 , V_112 , V_185 , V_54 , 32 , 32 ) ;
V_161 = V_122 ;
}
switch ( V_170 ) {
case V_99 :
if ( ! V_166 )
F_9 ( V_5 , V_75 , V_97 , V_161 , V_54 ) ;
break;
case V_100 :
F_9 ( V_5 , V_75 , V_97 , V_97 , V_161 ) ;
break;
case V_101 :
F_9 ( V_5 , V_126 , V_97 , V_97 , V_161 ) ;
break;
case V_104 :
F_9 ( V_5 , V_125 , V_97 , V_97 , V_161 ) ;
break;
case V_103 :
F_9 ( V_5 , V_124 , V_97 , V_97 , V_161 ) ;
break;
case V_102 :
F_9 ( V_5 , V_123 , V_97 , V_97 , V_161 ) ;
break;
case V_172 :
F_9 ( V_5 , V_173 , V_97 , V_161 ) ;
F_9 ( V_5 , V_174 , V_97 ) ;
break;
case V_178 :
case V_179 :
V_145 = F_4 ( V_160 , V_5 ) ;
if ( F_22 ( V_145 ) )
return - V_180 ;
F_9 ( V_5 , V_157 , V_161 , V_54 , V_145 ) ;
F_9 ( V_5 , V_186 , V_27 , V_54 , V_161 ) ;
F_9 ( V_5 , V_183 , V_97 , V_161 ) ;
if ( V_170 == V_178 )
F_9 ( V_5 , V_174 , V_97 ) ;
else
F_9 ( V_5 , V_182 , V_97 ) ;
break;
case V_106 :
F_9 ( V_5 , V_187 , V_97 , V_97 , V_161 ) ;
break;
case V_105 :
F_9 ( V_5 , V_188 , V_97 , V_97 , V_161 ) ;
break;
case V_107 :
F_9 ( V_5 , V_189 , V_97 , V_97 , V_161 ) ;
break;
default:
F_24 ( L_2 ) ;
return - V_57 ;
}
break;
case V_113 | V_99 | V_184 :
case V_113 | V_100 | V_184 :
case V_113 | V_101 | V_184 :
case V_113 | V_104 | V_184 :
case V_113 | V_103 | V_184 :
case V_113 | V_102 | V_184 :
case V_113 | V_172 | V_184 :
case V_113 | V_178 | V_184 :
case V_113 | V_179 | V_184 :
case V_113 | V_106 | V_184 :
case V_113 | V_105 | V_184 :
V_161 = F_5 ( V_5 , V_19 , V_24 ) ;
V_97 = F_5 ( V_5 , V_19 , V_25 ) ;
if ( V_161 < 0 || V_97 < 0 )
return - V_57 ;
V_162 = F_2 ( V_5 , V_143 , V_19 -> V_25 ) ;
if ( V_162 == V_176 || V_162 == V_82 ) {
F_9 ( V_5 , V_83 , V_97 , V_97 , 0 ) ;
}
V_166 = false ;
V_163 = F_2 ( V_5 , V_143 , V_19 -> V_23 ) ;
if ( V_163 == V_176 || V_163 == V_82 ) {
int V_185 = V_122 ;
if ( V_170 == V_99 ) {
V_185 = V_97 ;
V_166 = true ;
}
F_9 ( V_5 , V_83 , V_185 , V_161 , 0 ) ;
V_161 = V_122 ;
}
switch ( V_170 ) {
case V_99 :
if ( ! V_166 )
F_9 ( V_5 , V_127 , V_97 , V_161 , V_54 ) ;
break;
case V_100 :
F_9 ( V_5 , V_127 , V_97 , V_97 , V_161 ) ;
break;
case V_101 :
F_9 ( V_5 , V_128 , V_97 , V_97 , V_161 ) ;
break;
case V_104 :
F_9 ( V_5 , V_125 , V_97 , V_97 , V_161 ) ;
break;
case V_103 :
F_9 ( V_5 , V_124 , V_97 , V_97 , V_161 ) ;
break;
case V_102 :
F_9 ( V_5 , V_123 , V_97 , V_97 , V_161 ) ;
break;
case V_172 :
F_9 ( V_5 , V_190 , V_97 , V_97 , V_161 ) ;
break;
case V_178 :
case V_179 :
V_145 = F_4 ( V_160 , V_5 ) ;
if ( F_22 ( V_145 ) )
return - V_180 ;
F_9 ( V_5 , V_157 , V_161 , V_54 , V_145 ) ;
F_9 ( V_5 , V_186 , V_27 , V_54 , V_161 ) ;
F_9 ( V_5 , V_181 , V_97 , V_161 ) ;
if ( V_170 == V_178 )
F_9 ( V_5 , V_174 , V_97 ) ;
else
F_9 ( V_5 , V_182 , V_97 ) ;
break;
case V_106 :
F_9 ( V_5 , V_191 , V_97 , V_97 , V_161 ) ;
break;
case V_105 :
F_9 ( V_5 , V_192 , V_97 , V_97 , V_161 ) ;
break;
default:
F_24 ( L_3 ) ;
return - V_57 ;
}
break;
case V_193 | V_194 :
if ( V_143 + 1 < V_160 ) {
V_145 = F_4 ( V_160 , V_5 ) ;
if ( F_22 ( V_145 ) )
return - V_180 ;
F_9 ( V_5 , V_157 , V_54 , V_54 , V_145 ) ;
F_9 ( V_5 , V_86 ) ;
}
break;
case V_193 | V_195 | V_171 :
case V_193 | V_196 | V_171 :
V_167 = ( V_170 == V_195 ) ;
V_97 = F_5 ( V_5 , V_19 , V_197 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( V_19 -> V_87 == 0 ) {
V_161 = V_54 ;
} else {
F_11 ( V_19 , V_122 , V_5 ) ;
V_161 = V_122 ;
}
goto V_198;
case V_193 | V_195 | V_184 :
case V_193 | V_196 | V_184 :
case V_193 | V_199 | V_184 :
case V_193 | V_200 | V_184 :
case V_193 | V_201 | V_184 :
case V_193 | V_202 | V_184 :
case V_193 | V_203 | V_184 :
case V_193 | V_204 | V_184 :
case V_193 | V_205 | V_184 :
case V_193 | V_206 | V_184 :
case V_193 | V_207 | V_184 :
V_161 = F_5 ( V_5 , V_19 , V_24 ) ;
V_97 = F_5 ( V_5 , V_19 , V_25 ) ;
if ( V_161 < 0 || V_97 < 0 )
return - V_57 ;
V_162 = F_2 ( V_5 , V_143 , V_19 -> V_25 ) ;
V_163 = F_2 ( V_5 , V_143 , V_19 -> V_23 ) ;
if ( V_162 == V_111 && V_163 != V_111 ) {
F_9 ( V_5 , V_83 , V_122 , V_161 , 0 ) ;
V_161 = V_122 ;
} else if ( V_163 == V_111 && V_162 != V_111 ) {
F_9 ( V_5 , V_83 , V_122 , V_97 , 0 ) ;
V_97 = V_122 ;
}
if ( V_170 == V_207 ) {
F_9 ( V_5 , V_123 , V_122 , V_97 , V_161 ) ;
V_167 = false ;
V_97 = V_122 ;
V_161 = V_54 ;
} else if ( V_170 == V_201 || V_170 == V_200 ) {
F_9 ( V_5 , V_126 , V_122 , V_97 , V_161 ) ;
if ( ( V_19 + 1 ) -> V_98 == ( V_193 | V_194 ) && V_19 -> V_144 == 1 ) {
V_145 = F_4 ( V_160 , V_5 ) ;
if ( F_22 ( V_145 ) )
return - V_180 ;
if ( V_170 == V_201 )
F_9 ( V_5 , V_208 , V_122 , V_145 ) ;
else
F_9 ( V_5 , V_209 , V_122 , V_145 ) ;
F_9 ( V_5 , V_86 ) ;
return 2 ;
}
V_145 = F_4 ( V_143 + V_19 -> V_144 + 1 , V_5 ) ;
if ( F_22 ( V_145 ) )
return - V_180 ;
if ( V_170 == V_201 )
F_9 ( V_5 , V_209 , V_122 , V_145 ) ;
else
F_9 ( V_5 , V_208 , V_122 , V_145 ) ;
F_9 ( V_5 , V_86 ) ;
break;
} else if ( V_170 == V_202 || V_170 == V_199 ) {
F_9 ( V_5 , V_210 , V_122 , V_97 , V_161 ) ;
V_167 = V_170 == V_202 ;
V_97 = V_122 ;
V_161 = V_54 ;
} else if ( V_170 == V_205 || V_170 == V_204 ) {
F_9 ( V_5 , V_126 , V_155 , V_97 , V_161 ) ;
F_9 ( V_5 , V_151 , V_122 , V_97 , V_161 ) ;
F_9 ( V_5 , V_186 , V_159 , V_69 , V_155 ) ;
F_9 ( V_5 , V_211 , V_159 , V_54 , V_155 ) ;
F_9 ( V_5 , V_124 , V_122 , V_159 , V_122 ) ;
V_167 = V_170 == V_205 ;
V_97 = V_122 ;
V_161 = V_54 ;
} else if ( V_170 == V_206 || V_170 == V_203 ) {
F_9 ( V_5 , V_151 , V_122 , V_97 , V_161 ) ;
V_167 = V_170 == V_206 ;
V_97 = V_122 ;
V_161 = V_54 ;
} else {
V_167 = ( V_170 == V_195 ) ;
}
V_198:
if ( ( V_19 + 1 ) -> V_98 == ( V_193 | V_194 ) && V_19 -> V_144 == 1 ) {
V_145 = F_4 ( V_160 , V_5 ) ;
if ( F_22 ( V_145 ) ) {
V_12 = F_3 ( V_5 , V_160 ) ;
if ( V_12 == ( unsigned int ) - 1 )
return - V_180 ;
V_167 = ! V_167 ;
V_145 = 4 * 3 ;
if ( ! ( V_5 -> V_13 [ V_143 ] & V_14 ) ) {
V_5 -> V_13 [ V_143 ] |= V_14 ;
V_5 -> V_212 = 1 ;
}
}
if ( V_167 )
F_9 ( V_5 , V_152 , V_97 , V_161 , V_145 ) ;
else
F_9 ( V_5 , V_157 , V_97 , V_161 , V_145 ) ;
F_9 ( V_5 , V_86 ) ;
if ( V_5 -> V_13 [ V_143 ] & V_14 ) {
F_9 ( V_5 , V_213 , V_12 ) ;
F_9 ( V_5 , V_86 ) ;
}
return 2 ;
}
V_145 = F_4 ( V_143 + V_19 -> V_144 + 1 , V_5 ) ;
if ( F_22 ( V_145 ) ) {
V_12 = F_3 ( V_5 , V_143 + V_19 -> V_144 + 1 ) ;
if ( V_12 == ( unsigned int ) - 1 )
return - V_180 ;
V_167 = ! V_167 ;
V_145 = 4 * 3 ;
if ( ! ( V_5 -> V_13 [ V_143 ] & V_14 ) ) {
V_5 -> V_13 [ V_143 ] |= V_14 ;
V_5 -> V_212 = 1 ;
}
}
if ( V_167 )
F_9 ( V_5 , V_157 , V_97 , V_161 , V_145 ) ;
else
F_9 ( V_5 , V_152 , V_97 , V_161 , V_145 ) ;
F_9 ( V_5 , V_86 ) ;
if ( V_5 -> V_13 [ V_143 ] & V_14 ) {
F_9 ( V_5 , V_213 , V_12 ) ;
F_9 ( V_5 , V_86 ) ;
}
break;
case V_193 | V_201 | V_171 :
case V_193 | V_202 | V_171 :
case V_193 | V_199 | V_171 :
case V_193 | V_200 | V_171 :
V_167 = ( V_170 == V_202 ) ;
V_97 = F_5 ( V_5 , V_19 , V_197 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( V_19 -> V_87 == 0 ) {
if ( ( V_19 + 1 ) -> V_98 == ( V_193 | V_194 ) && V_19 -> V_144 == 1 ) {
V_145 = F_4 ( V_160 , V_5 ) ;
if ( F_22 ( V_145 ) )
return - V_180 ;
switch ( V_170 ) {
case V_201 :
F_9 ( V_5 , V_208 , V_97 , V_145 ) ;
break;
case V_202 :
F_9 ( V_5 , V_153 , V_97 , V_145 ) ;
break;
case V_199 :
F_9 ( V_5 , V_214 , V_97 , V_145 ) ;
break;
case V_200 :
F_9 ( V_5 , V_209 , V_97 , V_145 ) ;
break;
}
F_9 ( V_5 , V_86 ) ;
return 2 ;
}
V_145 = F_4 ( V_143 + V_19 -> V_144 + 1 , V_5 ) ;
if ( F_22 ( V_145 ) )
return - V_180 ;
switch ( V_170 ) {
case V_201 :
F_9 ( V_5 , V_209 , V_97 , V_145 ) ;
break;
case V_202 :
F_9 ( V_5 , V_214 , V_97 , V_145 ) ;
break;
case V_199 :
F_9 ( V_5 , V_153 , V_97 , V_145 ) ;
break;
case V_200 :
F_9 ( V_5 , V_208 , V_97 , V_145 ) ;
break;
}
F_9 ( V_5 , V_86 ) ;
break;
}
if ( V_170 == V_201 )
V_169 = V_19 -> V_87 + 1 ;
else if ( V_170 == V_200 )
V_169 = V_19 -> V_87 + 1 ;
else
V_169 = V_19 -> V_87 ;
V_167 = V_170 == V_201 || V_170 == V_202 ;
if ( V_169 >= V_88 && V_169 <= V_89 ) {
F_9 ( V_5 , V_215 , V_122 , V_97 , ( int ) V_169 ) ;
V_161 = V_122 ;
V_97 = V_54 ;
goto V_198;
}
F_19 ( V_5 , V_122 , ( T_1 ) V_169 ) ;
F_9 ( V_5 , V_210 , V_122 , V_97 , V_122 ) ;
V_161 = V_122 ;
V_97 = V_54 ;
goto V_198;
case V_193 | V_205 | V_171 :
case V_193 | V_206 | V_171 :
case V_193 | V_203 | V_171 :
case V_193 | V_204 | V_171 :
V_167 = ( V_170 == V_206 ) ;
V_97 = F_5 ( V_5 , V_19 , V_197 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( V_170 == V_205 )
V_169 = ( T_1 ) ( T_2 ) ( V_19 -> V_87 ) + 1 ;
else if ( V_170 == V_204 )
V_169 = ( T_1 ) ( T_2 ) ( V_19 -> V_87 ) + 1 ;
else
V_169 = ( T_1 ) ( T_2 ) ( V_19 -> V_87 ) ;
V_167 = V_170 == V_205 || V_170 == V_206 ;
F_19 ( V_5 , V_122 , ( T_1 ) V_169 ) ;
F_9 ( V_5 , V_151 , V_122 , V_97 , V_122 ) ;
V_161 = V_122 ;
V_97 = V_54 ;
goto V_198;
case V_193 | V_207 | V_171 :
V_97 = F_5 ( V_5 , V_19 , V_197 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( V_5 -> V_216 && F_25 ( ( T_2 ) V_19 -> V_87 ) == 1 ) {
if ( ( V_19 + 1 ) -> V_98 == ( V_193 | V_194 ) && V_19 -> V_144 == 1 ) {
V_145 = F_4 ( V_160 , V_5 ) ;
if ( F_22 ( V_145 ) )
return - V_180 ;
F_9 ( V_5 , V_217 , V_97 , F_26 ( ( T_2 ) V_19 -> V_87 ) - 1 , V_145 ) ;
F_9 ( V_5 , V_86 ) ;
return 2 ;
}
V_145 = F_4 ( V_143 + V_19 -> V_144 + 1 , V_5 ) ;
if ( F_22 ( V_145 ) )
return - V_180 ;
F_9 ( V_5 , V_218 , V_97 , F_26 ( ( T_2 ) V_19 -> V_87 ) - 1 , V_145 ) ;
F_9 ( V_5 , V_86 ) ;
break;
}
V_168 = ( T_2 ) V_19 -> V_87 ;
F_19 ( V_5 , V_122 , V_168 ) ;
F_9 ( V_5 , V_123 , V_122 , V_97 , V_122 ) ;
V_161 = V_122 ;
V_97 = V_54 ;
V_167 = false ;
goto V_198;
case V_193 | V_219 :
V_145 = F_4 ( V_143 + V_19 -> V_144 + 1 , V_5 ) ;
if ( F_22 ( V_145 ) ) {
V_12 = F_3 ( V_5 , V_143 + V_19 -> V_144 + 1 ) ;
if ( V_12 == ( unsigned int ) - 1 )
return - V_180 ;
F_9 ( V_5 , V_213 , V_12 ) ;
} else {
F_9 ( V_5 , V_220 , V_145 ) ;
}
F_9 ( V_5 , V_86 ) ;
break;
case V_221 | V_136 | V_222 :
if ( V_19 -> V_23 != 0 )
return - V_57 ;
V_97 = F_5 ( V_5 , V_19 , V_25 ) ;
if ( V_97 < 0 )
return V_97 ;
V_168 = ( ( T_1 ) ( T_2 ) V_19 -> V_87 ) | ( ( T_1 ) ( V_19 + 1 ) -> V_87 << 32 ) ;
F_19 ( V_5 , V_97 , V_168 ) ;
return 2 ;
case V_193 | V_223 :
V_5 -> V_39 |= V_61 ;
V_169 = ( T_4 ) V_19 -> V_87 + ( T_4 ) V_224 ;
F_19 ( V_5 , V_159 , ( T_1 ) V_169 ) ;
F_9 ( V_5 , V_225 , V_71 , V_159 ) ;
F_9 ( V_5 , V_86 ) ;
break;
case V_193 | V_226 :
if ( F_20 ( V_5 , V_143 ) )
return - V_57 ;
break;
case V_221 | V_133 | V_227 :
case V_221 | V_134 | V_227 :
case V_221 | V_135 | V_227 :
case V_221 | V_136 | V_227 :
V_5 -> V_39 |= V_61 ;
F_11 ( V_19 , V_31 , V_5 ) ;
F_9 ( V_5 , V_90 , V_33 , V_54 , F_17 ( V_19 ) ) ;
if ( V_19 -> V_87 < 0 ) {
F_19 ( V_5 , V_159 , ( T_1 ) V_228 ) ;
} else {
F_19 ( V_5 , V_159 , ( T_1 ) F_15 ) ;
F_9 ( V_5 , V_66 , V_35 , V_69 , V_5 -> V_64 ) ;
}
goto V_229;
case V_221 | V_133 | V_230 :
case V_221 | V_134 | V_230 :
case V_221 | V_135 | V_230 :
case V_221 | V_136 | V_230 :
V_5 -> V_39 |= V_61 ;
V_161 = F_5 ( V_5 , V_19 , V_24 ) ;
if ( V_161 < 0 )
return V_161 ;
V_163 = F_2 ( V_5 , V_143 , V_19 -> V_23 ) ;
if ( V_163 == V_82 ) {
F_9 ( V_5 , V_83 , V_31 , V_161 , 0 ) ;
V_161 = V_31 ;
}
if ( V_19 -> V_87 >= V_88 && V_19 -> V_87 <= V_89 ) {
F_9 ( V_5 , V_66 , V_31 , V_161 , V_19 -> V_87 ) ;
} else {
F_11 ( V_19 , V_122 , V_5 ) ;
F_9 ( V_5 , V_75 , V_31 , V_122 , V_161 ) ;
}
F_9 ( V_5 , V_83 , V_31 , V_31 , 0 ) ;
F_9 ( V_5 , V_66 , V_35 , V_69 , V_5 -> V_64 ) ;
F_9 ( V_5 , V_210 , V_122 , V_31 , V_54 ) ;
F_19 ( V_5 , V_155 , ( T_1 ) V_228 ) ;
F_19 ( V_5 , V_159 , ( T_1 ) F_15 ) ;
F_9 ( V_5 , V_90 , V_33 , V_54 , F_17 ( V_19 ) ) ;
F_9 ( V_5 , V_211 , V_159 , V_155 , V_122 ) ;
V_229:
F_9 ( V_5 , V_225 , V_71 , V_159 ) ;
F_9 ( V_5 , V_75 , V_29 , V_41 , V_54 ) ;
V_145 = F_4 ( V_160 , V_5 ) ;
if ( F_22 ( V_145 ) ) {
V_12 = F_3 ( V_5 , V_160 ) ;
if ( V_12 == ( unsigned int ) - 1 )
return - V_180 ;
if ( ! ( V_5 -> V_13 [ V_143 ] & V_14 ) ) {
V_5 -> V_13 [ V_143 ] |= V_14 ;
V_5 -> V_212 = 1 ;
}
F_9 ( V_5 , V_152 , V_27 , V_54 , 4 * 3 ) ;
F_9 ( V_5 , V_86 ) ;
F_9 ( V_5 , V_213 , V_12 ) ;
F_9 ( V_5 , V_86 ) ;
} else {
F_9 ( V_5 , V_157 , V_27 , V_54 , V_145 ) ;
F_9 ( V_5 , V_86 ) ;
}
#ifdef F_27
V_165 = false ;
#else
V_165 = true ;
#endif
V_97 = V_27 ;
switch ( F_18 ( V_19 -> V_98 ) ) {
case V_133 :
F_9 ( V_5 , V_231 , V_97 , 0 , V_27 ) ;
break;
case V_134 :
F_9 ( V_5 , V_232 , V_97 , 0 , V_27 ) ;
if ( V_165 )
F_9 ( V_5 , V_233 , V_97 , V_97 ) ;
break;
case V_135 :
F_9 ( V_5 , V_234 , V_97 , 0 , V_27 ) ;
if ( V_165 ) {
F_9 ( V_5 , V_233 , V_97 , V_97 ) ;
F_9 ( V_5 , V_235 , V_97 , V_97 , 16 ) ;
}
break;
case V_136 :
F_9 ( V_5 , V_84 , V_97 , 0 , V_27 ) ;
if ( V_165 ) {
F_9 ( V_5 , V_236 , V_97 , V_97 ) ;
F_9 ( V_5 , V_237 , V_97 , V_97 ) ;
}
break;
}
break;
case V_113 | V_238 | V_239 :
case V_113 | V_238 | V_240 :
V_97 = F_5 ( V_5 , V_19 , V_25 ) ;
if ( V_97 < 0 )
return V_97 ;
V_162 = F_2 ( V_5 , V_143 , V_19 -> V_25 ) ;
if ( V_19 -> V_87 == 64 && V_162 == V_111 )
F_9 ( V_5 , V_112 , V_97 , V_54 , 32 , 32 ) ;
if ( V_19 -> V_87 != 64 &&
( V_162 == V_176 || V_162 == V_82 ) ) {
F_9 ( V_5 , V_83 , V_97 , V_97 , 0 ) ;
}
#ifdef F_27
V_165 = ( F_28 ( V_19 -> V_98 ) == V_240 ) ;
#else
V_165 = ( F_28 ( V_19 -> V_98 ) == V_239 ) ;
#endif
if ( V_19 -> V_87 == 16 ) {
if ( V_165 )
F_9 ( V_5 , V_233 , V_97 , V_97 ) ;
F_9 ( V_5 , V_114 , V_97 , V_97 , 0xffff ) ;
} else if ( V_19 -> V_87 == 32 ) {
if ( V_165 ) {
F_9 ( V_5 , V_233 , V_97 , V_97 ) ;
F_9 ( V_5 , V_235 , V_97 , V_97 , 16 ) ;
}
} else {
if ( V_165 ) {
F_9 ( V_5 , V_236 , V_97 , V_97 ) ;
F_9 ( V_5 , V_237 , V_97 , V_97 ) ;
}
}
break;
case V_241 | V_133 | V_242 :
case V_241 | V_134 | V_242 :
case V_241 | V_135 | V_242 :
case V_241 | V_136 | V_242 :
if ( V_19 -> V_25 == V_51 ) {
V_5 -> V_39 |= V_53 ;
V_97 = V_69 ;
V_164 = V_19 -> V_144 + V_63 ;
} else {
V_97 = F_5 ( V_5 , V_19 , V_25 ) ;
if ( V_97 < 0 )
return V_97 ;
V_164 = V_19 -> V_144 ;
}
F_11 ( V_19 , V_122 , V_5 ) ;
switch ( F_18 ( V_19 -> V_98 ) ) {
case V_133 :
F_9 ( V_5 , V_243 , V_122 , V_164 , V_97 ) ;
break;
case V_134 :
F_9 ( V_5 , V_244 , V_122 , V_164 , V_97 ) ;
break;
case V_135 :
F_9 ( V_5 , V_245 , V_122 , V_164 , V_97 ) ;
break;
case V_136 :
F_9 ( V_5 , V_70 , V_122 , V_164 , V_97 ) ;
break;
}
break;
case V_246 | V_133 | V_242 :
case V_246 | V_134 | V_242 :
case V_246 | V_135 | V_242 :
case V_246 | V_136 | V_242 :
if ( V_19 -> V_23 == V_51 ) {
V_5 -> V_39 |= V_53 ;
V_161 = V_69 ;
V_164 = V_19 -> V_144 + V_63 ;
} else {
V_161 = F_5 ( V_5 , V_19 , V_24 ) ;
if ( V_161 < 0 )
return V_161 ;
V_164 = V_19 -> V_144 ;
}
V_97 = F_5 ( V_5 , V_19 , V_25 ) ;
if ( V_97 < 0 )
return V_97 ;
switch ( F_18 ( V_19 -> V_98 ) ) {
case V_133 :
F_9 ( V_5 , V_231 , V_97 , V_164 , V_161 ) ;
break;
case V_134 :
F_9 ( V_5 , V_232 , V_97 , V_164 , V_161 ) ;
break;
case V_135 :
F_9 ( V_5 , V_234 , V_97 , V_164 , V_161 ) ;
break;
case V_136 :
F_9 ( V_5 , V_84 , V_97 , V_164 , V_161 ) ;
break;
}
break;
case V_247 | V_133 | V_242 :
case V_247 | V_134 | V_242 :
case V_247 | V_135 | V_242 :
case V_247 | V_136 | V_242 :
case V_247 | V_135 | V_248 :
case V_247 | V_136 | V_248 :
if ( V_19 -> V_25 == V_51 ) {
V_5 -> V_39 |= V_53 ;
V_97 = V_69 ;
V_164 = V_19 -> V_144 + V_63 ;
} else {
V_97 = F_5 ( V_5 , V_19 , V_25 ) ;
if ( V_97 < 0 )
return V_97 ;
V_164 = V_19 -> V_144 ;
}
V_161 = F_5 ( V_5 , V_19 , V_24 ) ;
if ( V_161 < 0 )
return V_161 ;
if ( F_29 ( V_19 -> V_98 ) == V_248 ) {
switch ( F_18 ( V_19 -> V_98 ) ) {
case V_135 :
if ( F_2 ( V_5 , V_143 , V_19 -> V_23 ) == V_111 ) {
F_9 ( V_5 , V_83 , V_122 , V_161 , 0 ) ;
V_161 = V_122 ;
}
F_9 ( V_5 , V_249 , V_155 , V_164 , V_97 ) ;
F_9 ( V_5 , V_127 , V_155 , V_155 , V_161 ) ;
F_9 ( V_5 , V_250 , V_155 , V_164 , V_97 ) ;
F_9 ( V_5 , V_157 , V_155 , V_54 , - 4 * 4 ) ;
F_9 ( V_5 , V_86 ) ;
break;
case V_136 :
if ( F_2 ( V_5 , V_143 , V_19 -> V_23 ) == V_111 ) {
F_9 ( V_5 , V_75 , V_122 , V_161 , V_54 ) ;
F_9 ( V_5 , V_112 , V_122 , V_54 , 32 , 32 ) ;
V_161 = V_122 ;
}
F_9 ( V_5 , V_251 , V_155 , V_164 , V_97 ) ;
F_9 ( V_5 , V_75 , V_155 , V_155 , V_161 ) ;
F_9 ( V_5 , V_252 , V_155 , V_164 , V_97 ) ;
F_9 ( V_5 , V_157 , V_155 , V_54 , - 4 * 4 ) ;
F_9 ( V_5 , V_86 ) ;
break;
}
} else {
switch ( F_18 ( V_19 -> V_98 ) ) {
case V_133 :
F_9 ( V_5 , V_243 , V_161 , V_164 , V_97 ) ;
break;
case V_134 :
F_9 ( V_5 , V_244 , V_161 , V_164 , V_97 ) ;
break;
case V_135 :
F_9 ( V_5 , V_245 , V_161 , V_164 , V_97 ) ;
break;
case V_136 :
if ( F_2 ( V_5 , V_143 , V_19 -> V_23 ) == V_111 ) {
F_9 ( V_5 , V_75 , V_122 , V_161 , V_54 ) ;
F_9 ( V_5 , V_112 , V_122 , V_54 , 32 , 32 ) ;
V_161 = V_122 ;
}
F_9 ( V_5 , V_70 , V_161 , V_164 , V_97 ) ;
break;
}
}
break;
default:
F_24 ( L_4 ,
V_143 , ( unsigned int ) V_19 -> V_98 ) ;
return - V_57 ;
}
return 1 ;
}
static int F_30 ( struct V_4 * V_5 )
{
const struct V_77 * V_78 = V_5 -> V_79 ;
const struct V_18 * V_19 ;
int V_139 , V_11 ;
for ( V_139 = 0 ; V_139 < V_78 -> V_81 ; ) {
V_19 = V_78 -> V_253 + V_139 ;
if ( ( V_5 -> V_7 [ V_139 ] & V_254 ) == 0 ) {
V_139 ++ ;
continue;
}
if ( V_5 -> V_12 == NULL )
V_5 -> V_13 [ V_139 ] = ( V_5 -> V_13 [ V_139 ] & V_14 ) | ( V_5 -> V_17 * 4 ) ;
V_11 = F_23 ( V_19 , V_5 , V_139 , V_78 -> V_81 ) ;
if ( V_11 < 0 )
return V_11 ;
V_139 += V_11 ;
}
if ( V_5 -> V_12 == NULL )
V_5 -> V_13 [ V_139 ] = V_5 -> V_17 * 4 ;
if ( V_5 -> V_12 == NULL )
for ( V_139 = 0 ; V_139 < V_78 -> V_81 ; V_139 ++ ) {
V_19 = V_78 -> V_253 + V_139 ;
if ( V_19 -> V_98 == ( V_193 | V_194 ) )
V_5 -> V_13 [ V_139 ] = V_5 -> V_17 * 4 ;
}
return 0 ;
}
static int F_31 ( struct V_4 * V_5 , T_1 V_255 ,
int V_256 , bool V_257 )
{
const struct V_77 * V_78 = V_5 -> V_79 ;
const struct V_18 * V_19 ;
T_1 V_258 = V_255 ;
T_1 * V_1 = V_5 -> V_7 ;
int V_17 ;
int V_2 ;
for ( V_17 = V_256 ; V_17 < V_78 -> V_81 ; V_17 ++ ) {
V_1 [ V_17 ] = ( V_1 [ V_17 ] & V_254 ) | V_258 ;
V_19 = V_78 -> V_253 + V_17 ;
switch ( F_14 ( V_19 -> V_98 ) ) {
case V_113 :
switch ( F_13 ( V_19 -> V_98 ) ) {
case V_100 :
case V_101 :
case V_172 :
case V_178 :
case V_103 :
case V_102 :
case V_106 :
case V_105 :
case V_175 :
case V_179 :
case V_104 :
F_1 ( & V_258 , V_19 -> V_25 , V_111 ) ;
break;
case V_99 :
if ( F_28 ( V_19 -> V_98 ) ) {
F_1 ( & V_258 , V_19 -> V_25 , V_111 ) ;
} else {
if ( V_19 -> V_87 >= 0 )
F_1 ( & V_258 , V_19 -> V_25 , V_259 ) ;
else
F_1 ( & V_258 , V_19 -> V_25 , V_111 ) ;
}
break;
case V_238 :
if ( V_19 -> V_87 == 64 )
F_1 ( & V_258 , V_19 -> V_25 , V_176 ) ;
else if ( V_19 -> V_87 == 32 )
F_1 ( & V_258 , V_19 -> V_25 , V_111 ) ;
else
F_1 ( & V_258 , V_19 -> V_25 , V_259 ) ;
break;
}
V_1 [ V_17 ] |= V_260 ;
break;
case V_110 :
switch ( F_13 ( V_19 -> V_98 ) ) {
case V_99 :
if ( F_28 ( V_19 -> V_98 ) ) {
F_1 ( & V_258 , V_19 -> V_25 , V_176 ) ;
} else {
if ( V_19 -> V_87 >= 0 )
F_1 ( & V_258 , V_19 -> V_25 , V_259 ) ;
else
F_1 ( & V_258 , V_19 -> V_25 , V_261 ) ;
}
break;
default:
F_1 ( & V_258 , V_19 -> V_25 , V_176 ) ;
}
V_1 [ V_17 ] |= V_260 ;
break;
case V_221 :
switch ( F_18 ( V_19 -> V_98 ) ) {
case V_136 :
if ( F_29 ( V_19 -> V_98 ) == V_222 ) {
T_4 V_262 ;
V_262 = ( T_4 ) ( ( T_2 ) V_19 -> V_87 | ( ( T_1 ) ( V_19 + 1 ) -> V_87 << 32 ) ) ;
if ( V_262 > 0 && V_262 <= V_108 )
F_1 ( & V_258 , V_19 -> V_25 , V_259 ) ;
else if ( V_262 >= V_109 && V_262 <= V_108 )
F_1 ( & V_258 , V_19 -> V_25 , V_261 ) ;
else
F_1 ( & V_258 , V_19 -> V_25 , V_176 ) ;
V_1 [ V_17 ] |= V_260 ;
V_17 ++ ;
} else {
F_1 ( & V_258 , V_19 -> V_25 , V_176 ) ;
}
break;
case V_133 :
case V_134 :
F_1 ( & V_258 , V_19 -> V_25 , V_259 ) ;
break;
case V_135 :
if ( F_29 ( V_19 -> V_98 ) == V_222 )
F_1 ( & V_258 , V_19 -> V_25 ,
V_19 -> V_87 >= 0 ? V_259 : V_111 ) ;
else
F_1 ( & V_258 , V_19 -> V_25 , V_111 ) ;
break;
}
V_1 [ V_17 ] |= V_260 ;
break;
case V_246 :
switch ( F_18 ( V_19 -> V_98 ) ) {
case V_136 :
F_1 ( & V_258 , V_19 -> V_25 , V_176 ) ;
break;
case V_133 :
case V_134 :
F_1 ( & V_258 , V_19 -> V_25 , V_259 ) ;
break;
case V_135 :
F_1 ( & V_258 , V_19 -> V_25 , V_111 ) ;
break;
}
V_1 [ V_17 ] |= V_260 ;
break;
case V_193 :
switch ( F_13 ( V_19 -> V_98 ) ) {
case V_194 :
V_1 [ V_17 ] = V_260 | V_258 ;
V_1 [ V_78 -> V_81 ] = V_258 ;
return V_17 ;
case V_219 :
V_1 [ V_17 ] |= V_260 ;
V_17 += V_19 -> V_144 ;
break;
case V_195 :
case V_205 :
case V_206 :
case V_203 :
case V_204 :
case V_207 :
case V_196 :
case V_201 :
case V_202 :
case V_199 :
case V_200 :
if ( V_257 ) {
V_1 [ V_17 ] |= V_263 ;
V_17 += V_19 -> V_144 ;
V_257 = false ;
} else {
V_1 [ V_17 ] |= V_264 ;
}
break;
case V_223 :
F_1 ( & V_258 , V_26 , V_176 ) ;
for ( V_2 = V_26 ; V_2 <= V_36 ; V_2 ++ )
F_1 ( & V_258 , V_2 , V_176 ) ;
V_1 [ V_17 ] |= V_260 ;
break;
default:
F_6 ( 1 , L_5 ) ;
V_1 [ V_17 ] |= V_260 ;
break;
}
break;
default:
V_1 [ V_17 ] |= V_260 ;
break;
}
}
return V_17 ;
}
static int F_32 ( struct V_4 * V_5 )
{
const struct V_77 * V_78 = V_5 -> V_79 ;
T_1 V_258 ;
int V_2 ;
int V_139 ;
V_258 = 0 ;
for ( V_2 = V_28 ; V_2 <= V_36 ; V_2 ++ )
F_1 ( & V_258 , V_2 , V_176 ) ;
F_31 ( V_5 , V_258 , 0 , false ) ;
V_265:
for ( V_139 = 0 ; V_139 < V_78 -> V_81 ; V_139 ++ ) {
T_1 V_1 = V_5 -> V_7 [ V_139 ] ;
if ( ( V_1 & V_254 ) == V_260 ||
( V_1 & V_254 ) == 0 )
continue;
if ( ( V_1 & V_254 ) == V_264 ) {
F_31 ( V_5 , V_1 & ~ V_254 , V_139 , true ) ;
} else {
F_6 ( 1 , L_6 ) ;
F_31 ( V_5 , V_1 & ~ V_254 , V_139 , false ) ;
}
goto V_265;
}
return 0 ;
}
static void F_33 ( void * V_266 , unsigned int V_267 )
{
T_2 * V_268 ;
for ( V_268 = V_266 ; V_267 >= sizeof( T_2 ) ; V_267 -= sizeof( T_2 ) )
F_34 ( & V_268 , V_269 ) ;
}
struct V_77 * F_35 ( struct V_77 * V_78 )
{
struct V_77 * V_270 = V_78 ;
bool V_271 = false ;
struct V_77 * V_272 ;
struct V_273 * V_274 = NULL ;
struct V_4 V_5 ;
unsigned int V_275 ;
T_5 * V_276 ;
if ( ! V_277 || ! V_278 )
return V_78 ;
V_272 = F_36 ( V_78 ) ;
if ( F_37 ( V_272 ) )
return V_270 ;
if ( V_272 != V_78 ) {
V_271 = true ;
V_78 = V_272 ;
}
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
F_38 () ;
switch ( F_39 () ) {
case V_279 :
case V_280 :
case V_281 :
case V_282 :
V_5 . V_216 = 1 ;
break;
default:
V_5 . V_216 = 0 ;
}
F_40 () ;
V_5 . V_13 = F_41 ( V_78 -> V_81 + 1 , sizeof( * V_5 . V_13 ) , V_283 ) ;
if ( V_5 . V_13 == NULL )
goto V_284;
V_5 . V_7 = F_41 ( V_78 -> V_81 + 1 , sizeof( * V_5 . V_7 ) , V_283 ) ;
if ( V_5 . V_7 == NULL )
goto V_284;
V_5 . V_79 = V_78 ;
if ( F_32 ( & V_5 ) )
goto V_284;
if ( F_30 ( & V_5 ) )
goto V_284;
if ( V_5 . V_39 & V_73 ) {
if ( V_5 . V_39 & V_61 )
V_5 . V_39 |= V_62 ;
else
V_5 . V_39 |= V_74 ;
}
do {
V_5 . V_17 = 0 ;
V_5 . V_16 = 1 ;
V_5 . V_212 = 0 ;
if ( F_7 ( & V_5 ) )
goto V_284;
if ( F_30 ( & V_5 ) )
goto V_284;
if ( F_10 ( & V_5 , V_71 ) )
goto V_284;
} while ( V_5 . V_212 );
V_275 = 4 * V_5 . V_17 ;
V_274 = F_42 ( V_275 , & V_276 ,
sizeof( T_2 ) , F_33 ) ;
if ( V_274 == NULL )
goto V_284;
V_5 . V_12 = ( T_2 * ) V_276 ;
V_5 . V_17 = 0 ;
if ( F_7 ( & V_5 ) )
goto V_284;
if ( F_30 ( & V_5 ) )
goto V_284;
if ( F_10 ( & V_5 , V_71 ) )
goto V_284;
F_43 ( ( unsigned long ) V_5 . V_12 ,
( unsigned long ) ( V_5 . V_12 + V_5 . V_17 * sizeof( T_2 ) ) ) ;
if ( V_277 > 1 )
F_44 ( V_78 -> V_81 , V_275 , 2 , V_5 . V_12 ) ;
F_45 ( V_274 ) ;
V_78 -> V_158 = ( void * ) V_5 . V_12 ;
V_78 -> V_285 = 1 ;
V_78 -> V_286 = V_275 ;
V_287:
if ( V_271 )
F_46 ( V_78 , V_78 == V_270 ?
V_272 : V_270 ) ;
F_47 ( V_5 . V_13 ) ;
F_47 ( V_5 . V_7 ) ;
return V_78 ;
V_284:
V_78 = V_270 ;
if ( V_274 )
F_48 ( V_274 ) ;
goto V_287;
}
