static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return false ;
default:
return true ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_8 :
case V_9 :
case V_15 :
return false ;
default:
return true ;
}
}
static bool F_4 ( struct V_16 * V_17 )
{
return ( V_17 -> V_18 & V_19 ) ==
V_20 ;
}
static bool F_5 ( struct V_16 * V_17 )
{
return ( V_17 -> V_18 & V_21 ) ==
V_22 ;
}
static bool F_6 ( struct V_16 * V_17 )
{
return ( V_17 -> V_18 & V_21 ) ==
V_23 ;
}
static T_1 F_7 ( int V_24 , void * V_25 )
{
struct V_16 * V_17 = V_25 ;
struct V_26 * V_27 = V_17 -> V_27 ;
T_2 V_28 ;
T_2 V_29 ;
F_8 ( V_27 , V_10 , & V_28 ) ;
V_29 = V_28 & V_17 -> V_30 -> V_31 ;
if ( V_29 )
F_9 ( V_27 , V_10 , V_29 ) ;
F_10 ( & V_17 -> V_32 , V_28 ) ;
return V_33 ;
}
static void F_11 ( struct V_16 * V_17 ,
bool V_34 )
{
struct V_26 * V_27 = V_17 -> V_27 ;
struct V_35 * V_36 = & V_17 -> V_37 ;
if ( V_34 ) {
F_12 ( V_27 , V_38 ,
V_36 -> V_39 . V_40 | V_36 -> V_41 . V_40 ,
V_36 -> V_39 . V_40 | V_36 -> V_41 . V_40 ) ;
F_12 ( V_27 , V_42 ,
V_36 -> V_39 . V_43 | V_36 -> V_41 . V_43 ,
V_36 -> V_39 . V_43 | V_36 -> V_41 . V_43 ) ;
F_12 ( V_27 , V_44 ,
V_36 -> V_39 . V_45 | V_36 -> V_41 . V_45 ,
V_36 -> V_39 . V_45 | V_36 -> V_41 . V_45 ) ;
} else {
F_12 ( V_27 , V_42 ,
V_36 -> V_39 . V_43 | V_36 -> V_41 . V_43 , 0 ) ;
F_12 ( V_27 , V_44 ,
V_36 -> V_39 . V_45 | V_36 -> V_41 . V_45 , 0 ) ;
F_12 ( V_27 , V_38 ,
V_36 -> V_39 . V_40 | V_36 -> V_41 . V_40 , 0 ) ;
}
}
static void F_13 ( struct V_16 * V_17 , bool V_34 ,
struct V_46 * V_36 )
{
struct V_26 * V_27 = V_17 -> V_27 ;
struct V_46 * V_47 ;
int V_48 ;
T_3 V_49 ;
int V_50 ;
F_8 ( V_27 , V_51 , & V_49 ) ;
V_48 = ! ! ( V_49 & V_52 ) +
! ! ( V_49 & V_53 ) ;
if ( V_48 - 1 > 0 )
V_50 = 1 ;
else
V_50 = 0 ;
if ( & V_17 -> V_37 . V_39 == V_36 )
V_47 = & V_17 -> V_37 . V_41 ;
else
V_47 = & V_17 -> V_37 . V_39 ;
if ( ! V_34 ) {
T_3 V_54 = F_14 ( V_36 -> V_54 , V_47 -> V_54 ,
V_50 ) ;
F_12 ( V_27 , V_51 , V_54 , 0 ) ;
}
if ( V_17 -> V_30 -> V_55 ) {
if ( ( V_34 && ! V_48 ) ||
( ! V_34 && ! V_50 ) )
F_11 ( V_17 , V_34 ) ;
goto V_56;
}
if ( V_34 ) {
F_12 ( V_27 , V_38 , V_36 -> V_40 , V_36 -> V_40 ) ;
F_12 ( V_27 , V_42 , V_36 -> V_43 , V_36 -> V_43 ) ;
F_12 ( V_27 , V_44 , V_36 -> V_45 , V_36 -> V_45 ) ;
} else {
T_3 V_40 ;
T_3 V_43 ;
T_3 V_45 ;
V_40 = F_14 ( V_36 -> V_40 , V_47 -> V_40 ,
V_50 ) ;
V_43 = F_14 ( V_36 -> V_43 , V_47 -> V_43 ,
V_50 ) ;
V_45 = F_14 ( V_36 -> V_45 , V_47 -> V_45 ,
V_50 ) ;
F_12 ( V_27 , V_42 , V_43 , 0 ) ;
F_12 ( V_27 , V_44 , V_45 , 0 ) ;
F_12 ( V_27 , V_38 , V_40 , 0 ) ;
}
V_56:
if ( V_34 )
F_12 ( V_27 , V_51 , V_36 -> V_54 , V_36 -> V_54 ) ;
}
static void F_15 ( struct V_16 * V_17 , bool V_34 )
{
F_13 ( V_17 , V_34 , & V_17 -> V_37 . V_39 ) ;
}
static void F_16 ( struct V_16 * V_17 , bool V_34 )
{
F_13 ( V_17 , V_34 , & V_17 -> V_37 . V_41 ) ;
}
static void F_17 ( struct V_16 * V_17 )
{
struct V_35 * V_3 = & V_17 -> V_37 ;
V_3 -> V_39 . V_40 = V_57 ;
V_3 -> V_39 . V_43 = V_58 ;
V_3 -> V_39 . V_54 = 0 ;
V_3 -> V_41 . V_40 = V_59 ;
V_3 -> V_41 . V_45 = V_60 ;
V_3 -> V_41 . V_54 = 0 ;
if ( ! F_4 ( V_17 ) ) {
V_3 -> V_39 . V_54 = V_61 | V_53 ;
V_3 -> V_39 . V_40 |= V_57 ;
V_3 -> V_41 . V_54 = V_61 | V_52 ;
V_3 -> V_41 . V_40 |= V_59 ;
}
if ( V_17 -> V_62 ) {
V_3 -> V_39 . V_40 |= V_63 ;
V_3 -> V_41 . V_40 |= V_64 ;
} else {
V_3 -> V_39 . V_40 |= V_65 ;
V_3 -> V_41 . V_40 |= V_66 ;
}
V_3 -> V_39 . V_40 |= V_67 ;
V_3 -> V_41 . V_40 |= V_68 ;
}
static void F_18 ( struct V_16 * V_17 )
{
struct V_26 * V_27 = V_17 -> V_27 ;
F_9 ( V_27 , V_69 ,
F_19 ( 17 ) | F_20 ( 13 ) ) ;
F_9 ( V_27 , V_70 ,
F_19 ( 17 ) | F_20 ( 13 ) ) ;
F_9 ( V_27 , V_71 ,
V_72 | V_73 ) ;
F_9 ( V_27 , V_5 , 0xff ) ;
F_9 ( V_27 , V_4 , 0x300 ) ;
F_12 ( V_27 , V_51 ,
V_61 | V_52 | V_53 ,
V_61 | V_52 | V_53 ) ;
F_9 ( V_27 , V_74 , F_21 ( 3 ) ) ;
}
static int F_22 ( struct V_75 * V_76 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 = V_76 -> V_81 ;
struct V_16 * V_17 =
F_23 ( V_80 -> V_82 ) ;
int V_83 ;
V_83 = F_24 ( V_17 -> V_84 ) ;
if ( V_83 )
return V_83 ;
if ( V_17 -> V_85 )
F_25 ( V_76 -> V_86 , 0 ,
V_87 , 2 ) ;
return 0 ;
}
static void F_26 ( struct V_75 * V_76 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 = V_76 -> V_81 ;
struct V_16 * V_17 =
F_23 ( V_80 -> V_82 ) ;
F_27 ( V_17 -> V_84 ) ;
}
static int F_28 ( struct V_75 * V_76 ,
struct V_77 * V_82 ,
struct V_88 * V_89 )
{
struct V_16 * V_17 = F_23 ( V_82 ) ;
struct V_26 * V_27 = V_17 -> V_27 ;
int V_90 = V_17 -> V_91 . V_92 , V_83 ;
T_3 V_93 = 999 , V_94 , V_95 , V_96 , V_97 , V_98 , V_99 , V_100 ;
unsigned long V_101 , V_102 , V_103 ;
T_4 V_104 , V_105 = 100000 ;
unsigned int V_106 ;
bool V_107 ;
if ( V_17 -> V_108 )
V_106 = V_17 -> V_108 ;
else
V_106 = F_29 ( V_89 ) * 32 * F_30 ( V_89 ) ;
if ( F_31 ( V_17 -> V_109 ) )
return - V_110 ;
V_107 = V_17 -> V_111 & ~ ( F_32 ( V_76 -> V_112 ) ) ;
V_95 = 0 ;
V_94 = 0 ;
V_99 = ( V_94 + 1 ) * ( 7 * V_95 + 1 ) * 2 ;
for ( V_100 = 0 ; V_100 < 255 ; V_100 ++ ) {
V_103 = V_106 * V_99 * ( V_100 + 1 ) ;
if ( V_107 )
V_101 = F_33 ( V_17 -> V_109 ) ;
else
V_101 = F_34 ( V_17 -> V_109 , V_103 ) ;
if ( V_101 * 5 > F_33 ( V_17 -> V_84 ) )
continue;
V_101 /= V_99 ;
V_98 = V_101 / ( V_100 + 1 ) ;
if ( V_106 == V_98 )
V_104 = 0 ;
else if ( V_106 / V_98 == 1 )
V_104 = V_106 - V_98 ;
else if ( V_98 / V_106 == 1 )
V_104 = V_98 - V_106 ;
else
continue;
V_104 *= 100000 ;
F_35 ( V_104 , V_106 ) ;
if ( V_104 < V_105 && ! ( V_100 == 0 && V_95 == 0 && V_94 == 0 ) ) {
V_102 = V_103 ;
V_105 = V_104 ;
V_93 = V_100 ;
}
if ( V_105 == 0 )
break;
}
if ( V_93 == 999 ) {
F_36 ( V_82 -> V_2 , L_1 ) ;
return - V_110 ;
}
V_96 = F_37 ( V_93 + 1 ) | ( V_94 ? V_113 : 0 ) |
( V_95 ? V_114 : 0 ) ;
V_97 = V_115 | V_113 |
V_114 ;
if ( V_76 -> V_112 == V_116 || V_90 )
F_12 ( V_27 , V_69 , V_97 , V_96 ) ;
else
F_12 ( V_27 , V_70 , V_97 , V_96 ) ;
if ( ! V_107 ) {
V_83 = F_38 ( V_17 -> V_109 , V_102 ) ;
if ( V_83 ) {
F_36 ( V_82 -> V_2 , L_2 ) ;
return - V_110 ;
}
}
return 0 ;
}
static int F_39 ( struct V_77 * V_82 ,
int V_117 , unsigned int V_106 , int V_118 )
{
struct V_16 * V_17 = F_23 ( V_82 ) ;
V_17 -> V_108 = V_106 ;
return 0 ;
}
static int F_40 ( struct V_75 * V_76 ,
struct V_88 * V_89 , struct V_77 * V_82 )
{
struct V_16 * V_17 = F_23 ( V_82 ) ;
struct V_26 * V_27 = V_17 -> V_27 ;
unsigned int V_119 = F_29 ( V_89 ) ;
unsigned int V_120 =
F_41 ( F_42 ( V_89 ) ) ;
T_3 V_121 = F_19 ( V_120 ) ;
int V_83 ;
T_3 V_49 ;
int V_122 ;
F_8 ( V_27 , V_51 , & V_49 ) ;
V_122 = V_49 & V_61 ;
if ( V_122 && V_17 -> V_91 . V_92 )
return 0 ;
if ( F_5 ( V_17 ) ) {
V_83 = F_28 ( V_76 , V_82 , V_89 ) ;
if ( V_83 )
return V_83 ;
if ( ! ( V_17 -> V_111 & F_32 ( V_76 -> V_112 ) ) ) {
V_83 = F_24 ( V_17 -> V_109 ) ;
if ( V_83 )
return V_83 ;
V_17 -> V_111 |= F_32 ( V_76 -> V_112 ) ;
}
}
if ( ! F_4 ( V_17 ) ) {
T_5 V_123 ;
if ( F_6 ( V_17 ) && V_120 == 16 )
V_123 = V_124 |
V_125 ;
else
V_123 = V_17 -> V_126 ;
F_12 ( V_27 , V_51 ,
V_125 | V_127 ,
V_119 == 1 ? 0 : V_123 ) ;
}
if ( ( V_76 -> V_112 == V_116 ) ||
V_17 -> V_91 . V_92 )
F_12 ( V_27 , V_69 , V_128 ,
V_121 ) ;
else
F_12 ( V_27 , V_70 , V_128 ,
V_121 ) ;
return 0 ;
}
static int F_43 ( struct V_75 * V_76 ,
struct V_77 * V_82 )
{
struct V_79 * V_80 = V_76 -> V_81 ;
struct V_16 * V_17 =
F_23 ( V_80 -> V_82 ) ;
if ( F_5 ( V_17 ) &&
V_17 -> V_111 & F_32 ( V_76 -> V_112 ) ) {
F_27 ( V_17 -> V_109 ) ;
V_17 -> V_111 &= ~ F_32 ( V_76 -> V_112 ) ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
unsigned int V_129 )
{
struct V_26 * V_27 = V_17 -> V_27 ;
T_3 V_130 = 0 , V_45 , V_43 , V_54 , V_97 ;
T_5 V_131 ;
V_17 -> V_18 = V_129 ;
if ( F_5 ( V_17 ) && F_31 ( V_17 -> V_109 ) ) {
F_36 ( V_2 , L_3 ) ;
return - V_110 ;
}
F_17 ( V_17 ) ;
F_8 ( V_27 , V_51 , & V_54 ) ;
V_54 &= ~ ( V_132 | V_127 ) ;
V_54 |= V_133 ;
V_97 = V_134 | V_135 | V_136 |
V_137 | V_138 | V_139 |
V_140 ;
F_8 ( V_27 , V_44 , & V_45 ) ;
F_8 ( V_27 , V_42 , & V_43 ) ;
V_45 &= ~ V_97 ;
V_43 &= ~ V_97 ;
V_17 -> V_126 = V_125 ;
switch ( V_129 & V_19 ) {
case V_141 :
switch ( V_129 & V_21 ) {
case V_23 :
case V_22 :
V_17 -> V_126 |= V_142 ;
F_12 ( V_27 , V_69 ,
V_143 ,
F_20 ( 2 ) ) ;
F_12 ( V_27 , V_70 ,
V_143 ,
F_20 ( 2 ) ) ;
break;
case V_144 :
V_17 -> V_126 |= V_145 ;
break;
default:
return - V_110 ;
}
V_130 |= V_138 | V_137 |
V_134 | V_140 ;
break;
case V_146 :
V_130 |= V_134 | V_137 ;
break;
case V_147 :
V_130 |= V_139 | V_137 |
V_134 | V_140 ;
break;
case V_148 :
V_130 |= V_139 | V_137 |
V_134 ;
break;
case V_20 :
V_17 -> V_126 |= V_124 ;
break;
default:
return - V_110 ;
}
V_54 |= V_17 -> V_126 ;
switch ( V_129 & V_149 ) {
case V_150 :
break;
case V_151 :
V_130 ^= V_137 ;
break;
case V_152 :
V_130 ^= V_138 ;
break;
case V_153 :
V_130 ^= V_137 ;
V_130 ^= V_138 ;
break;
default:
return - V_110 ;
}
switch ( V_129 & V_21 ) {
case V_22 :
V_130 |= V_135 | V_136 ;
V_54 |= V_154 ;
break;
case V_144 :
V_54 &= ~ V_154 ;
break;
case V_23 :
V_130 &= ~ V_136 ;
V_130 |= V_135 ;
V_54 &= ~ V_154 ;
break;
default:
if ( ! F_4 ( V_17 ) )
return - V_110 ;
}
V_45 |= V_130 ;
V_43 |= V_130 ;
if ( V_17 -> V_91 . V_92
|| F_4 ( V_17 ) ) {
V_43 &= ~ V_155 ;
V_54 |= V_132 ;
}
F_9 ( V_27 , V_44 , V_45 ) ;
F_9 ( V_27 , V_42 , V_43 ) ;
F_9 ( V_27 , V_51 , V_54 ) ;
if ( V_17 -> V_62 )
V_131 = V_17 -> V_156 - 2 ;
else
V_131 = V_17 -> V_156 ;
F_9 ( V_27 , V_11 ,
F_45 ( V_131 ) | F_46 ( V_131 ) |
F_47 ( V_131 ) | F_48 ( V_131 ) ) ;
if ( V_17 -> V_85 ) {
F_12 ( V_27 , V_42 , V_157 ,
V_157 ) ;
F_12 ( V_27 , V_44 , V_158 ,
V_158 ) ;
F_12 ( V_27 , V_51 , V_159 ,
V_159 ) ;
}
if ( ( V_129 & V_19 ) == V_20 )
F_18 ( V_17 ) ;
return 0 ;
}
static int F_49 ( struct V_77 * V_82 , unsigned int V_129 )
{
struct V_16 * V_17 = F_23 ( V_82 ) ;
return F_44 ( V_82 -> V_2 , V_17 , V_129 ) ;
}
static int F_50 ( struct V_77 * V_82 , T_3 V_160 ,
T_3 V_161 , int V_162 , int V_163 )
{
struct V_16 * V_17 = F_23 ( V_82 ) ;
struct V_26 * V_27 = V_17 -> V_27 ;
T_3 V_164 ;
F_8 ( V_27 , V_51 , & V_164 ) ;
V_164 &= V_127 | V_125 ;
if ( V_164 && V_162 < 2 ) {
F_36 ( V_82 -> V_2 , L_4 ) ;
return - V_110 ;
}
F_12 ( V_27 , V_69 , V_143 ,
F_20 ( V_162 ) ) ;
F_12 ( V_27 , V_70 , V_143 ,
F_20 ( V_162 ) ) ;
F_8 ( V_27 , V_51 , & V_164 ) ;
V_164 &= V_61 ;
F_12 ( V_27 , V_51 , V_61 ,
V_61 ) ;
F_9 ( V_27 , V_165 , ~ V_160 ) ;
F_9 ( V_27 , V_166 , ~ V_161 ) ;
F_12 ( V_27 , V_51 , V_61 , V_164 ) ;
return 0 ;
}
static int F_51 ( struct V_75 * V_76 , int V_167 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 = V_76 -> V_81 ;
struct V_16 * V_17 = F_23 ( V_80 -> V_82 ) ;
struct V_26 * V_27 = V_17 -> V_27 ;
switch ( V_167 ) {
case V_168 :
case V_169 :
case V_170 :
if ( V_76 -> V_112 == V_116 )
F_16 ( V_17 , true ) ;
else
F_15 ( V_17 , true ) ;
break;
case V_171 :
case V_172 :
case V_173 :
if ( V_76 -> V_112 == V_116 )
F_16 ( V_17 , false ) ;
else
F_15 ( V_17 , false ) ;
break;
default:
return - V_110 ;
}
if ( F_4 ( V_17 ) ) {
if ( V_76 -> V_112 == V_116 )
F_9 ( V_27 , V_74 , V_174 ) ;
else
F_9 ( V_27 , V_74 , V_175 ) ;
}
return 0 ;
}
static int F_52 ( struct V_77 * V_78 )
{
struct V_16 * V_17 = F_23 ( V_78 ) ;
if ( V_17 -> V_30 -> V_176 && V_17 -> V_62 ) {
V_78 -> V_177 = & V_17 -> V_178 ;
V_78 -> V_179 = & V_17 -> V_180 ;
}
return 0 ;
}
static void F_53 ( struct V_181 * V_182 , unsigned short V_3 ,
unsigned short V_164 )
{
struct V_26 * V_27 = V_183 -> V_27 ;
unsigned int V_184 ;
unsigned int V_185 ;
int V_83 ;
if ( V_3 > 0x7f )
return;
V_83 = F_24 ( V_183 -> V_84 ) ;
if ( V_83 ) {
F_54 ( L_5 ,
V_83 ) ;
return;
}
V_184 = V_3 << 12 ;
F_9 ( V_27 , V_12 , V_184 ) ;
V_185 = V_164 << 4 ;
F_9 ( V_27 , V_13 , V_185 ) ;
F_12 ( V_27 , V_71 , V_186 ,
V_187 ) ;
F_55 ( 100 ) ;
F_27 ( V_183 -> V_84 ) ;
}
static unsigned short F_56 ( struct V_181 * V_182 ,
unsigned short V_3 )
{
struct V_26 * V_27 = V_183 -> V_27 ;
unsigned short V_164 = - 1 ;
T_3 V_188 ;
unsigned int V_184 ;
int V_83 ;
V_83 = F_24 ( V_183 -> V_84 ) ;
if ( V_83 ) {
F_54 ( L_6 ,
V_83 ) ;
return - 1 ;
}
V_184 = ( V_3 & 0x7f ) << 12 ;
F_9 ( V_27 , V_12 , V_184 ) ;
F_12 ( V_27 , V_71 , V_186 ,
V_189 ) ;
F_55 ( 100 ) ;
F_8 ( V_27 , V_13 , & V_188 ) ;
V_164 = ( V_188 >> 4 ) & 0xffff ;
F_27 ( V_183 -> V_84 ) ;
return V_164 ;
}
static void F_57 ( char * V_190 )
{
char * V_191 = V_190 ;
char V_192 ;
while ( ( V_192 = * V_191 ) ) {
if ( ( V_192 >= 'A' ) && ( V_192 <= 'Z' ) )
* V_191 = V_192 + ( 'a' - 'A' ) ;
V_191 ++ ;
}
}
static int F_58 ( struct V_193 * V_194 ,
struct V_16 * V_17 , void T_6 * V_195 )
{
struct V_196 * V_197 = V_194 -> V_2 . V_198 ;
T_3 V_199 [ 4 ] ;
int V_83 ;
if ( V_17 -> V_200 )
V_17 -> V_84 = F_59 ( & V_194 -> V_2 , L_7 ) ;
else
V_17 -> V_84 = F_59 ( & V_194 -> V_2 , NULL ) ;
if ( F_31 ( V_17 -> V_84 ) ) {
V_83 = F_60 ( V_17 -> V_84 ) ;
F_36 ( & V_194 -> V_2 , L_8 , V_83 ) ;
return V_83 ;
}
if ( ! V_17 -> V_200 ) {
V_83 = F_24 ( V_17 -> V_84 ) ;
if ( V_83 ) {
F_36 ( & V_194 -> V_2 , L_9 , V_83 ) ;
return V_83 ;
}
}
V_17 -> V_109 = F_59 ( & V_194 -> V_2 , L_10 ) ;
if ( F_31 ( V_17 -> V_109 ) )
F_61 ( & V_194 -> V_2 , L_11 ,
F_60 ( V_17 -> V_109 ) ) ;
V_17 -> V_178 . V_201 = V_17 -> V_156 - 2 ;
V_17 -> V_180 . V_201 = V_17 -> V_156 - 2 ;
V_17 -> V_178 . V_202 = V_17 -> V_203 + V_6 ;
V_17 -> V_180 . V_202 = V_17 -> V_203 + V_8 ;
V_83 = F_62 ( V_197 , L_12 , V_199 , 4 ) ;
if ( V_17 -> V_62 && ! V_83 && V_199 [ 2 ] == V_204 ) {
V_17 -> V_85 = true ;
V_17 -> V_178 . V_201 &= ~ 0x1 ;
V_17 -> V_180 . V_201 &= ~ 0x1 ;
}
if ( ! V_17 -> V_62 ) {
V_17 -> V_205 . V_24 = V_17 -> V_24 ;
V_17 -> V_205 . V_206 = V_195 ;
V_17 -> V_205 . V_180 =
& V_17 -> V_180 ;
V_17 -> V_205 . V_178 =
& V_17 -> V_178 ;
V_83 = F_63 ( V_194 , & V_17 -> V_205 ) ;
if ( V_83 )
goto V_207;
} else {
V_83 = F_64 ( V_194 , V_208 ) ;
if ( V_83 )
goto V_207;
}
return 0 ;
V_207:
if ( ! V_17 -> V_200 )
F_27 ( V_17 -> V_84 ) ;
return V_83 ;
}
static void F_65 ( struct V_193 * V_194 ,
struct V_16 * V_17 )
{
if ( ! V_17 -> V_62 )
F_66 ( V_194 ) ;
if ( ! V_17 -> V_200 )
F_27 ( V_17 -> V_84 ) ;
}
static int F_67 ( struct V_193 * V_194 )
{
struct V_16 * V_17 ;
int V_83 = 0 ;
struct V_196 * V_197 = V_194 -> V_2 . V_198 ;
const struct V_209 * V_210 ;
const char * V_191 , * V_211 ;
const T_7 * V_212 ;
struct V_213 * V_214 ;
void T_6 * V_195 ;
char V_215 [ 64 ] ;
V_210 = F_68 ( V_216 , & V_194 -> V_2 ) ;
if ( ! V_210 || ! V_210 -> V_217 )
return - V_110 ;
V_17 = F_69 ( & V_194 -> V_2 , sizeof( * V_17 ) ,
V_218 ) ;
if ( ! V_17 ) {
F_36 ( & V_194 -> V_2 , L_13 ) ;
return - V_219 ;
}
V_17 -> V_30 = V_210 -> V_217 ;
V_211 = F_70 ( V_197 , L_14 , NULL ) ;
if ( V_211 ) {
if ( ! strcmp ( V_211 , L_15 ) )
V_17 -> V_18 = V_20 ;
}
V_17 -> V_62 = ! F_71 ( V_197 ,
L_16 ) ;
if ( F_4 ( V_17 ) ) {
memcpy ( & V_17 -> V_91 , & V_220 ,
sizeof( V_220 ) ) ;
V_183 = V_17 ;
V_83 = F_72 ( & V_221 , V_194 ) ;
if ( V_83 ) {
F_36 ( & V_194 -> V_2 , L_17 ) ;
return V_83 ;
}
} else {
memcpy ( & V_17 -> V_91 , & V_222 ,
sizeof( V_222 ) ) ;
}
V_17 -> V_91 . V_215 = F_73 ( & V_194 -> V_2 ) ;
V_214 = F_74 ( V_194 , V_223 , 0 ) ;
V_195 = F_75 ( & V_194 -> V_2 , V_214 ) ;
if ( F_31 ( V_195 ) )
return F_60 ( V_195 ) ;
V_17 -> V_203 = V_214 -> V_224 ;
V_83 = F_76 ( V_197 , L_18 , L_7 ) ;
if ( V_83 < 0 ) {
V_17 -> V_200 = false ;
V_17 -> V_27 = F_77 ( & V_194 -> V_2 , V_195 ,
& V_225 ) ;
} else {
V_17 -> V_200 = true ;
V_17 -> V_27 = F_78 ( & V_194 -> V_2 ,
L_7 , V_195 , & V_225 ) ;
}
if ( F_31 ( V_17 -> V_27 ) ) {
F_36 ( & V_194 -> V_2 , L_19 ) ;
return F_60 ( V_17 -> V_27 ) ;
}
V_17 -> V_24 = F_79 ( V_194 , 0 ) ;
if ( V_17 -> V_24 < 0 ) {
F_36 ( & V_194 -> V_2 , L_20 , V_194 -> V_215 ) ;
return V_17 -> V_24 ;
}
if ( ! F_80 ( V_197 , L_21 , NULL ) ) {
if ( ! F_4 ( V_17 ) )
V_17 -> V_91 . V_92 = 1 ;
V_17 -> V_91 . V_226 = 1 ;
V_17 -> V_91 . V_227 = 1 ;
}
V_212 = F_70 ( V_197 , L_22 , NULL ) ;
if ( V_212 )
V_17 -> V_156 = F_81 ( V_212 ) ;
else
V_17 -> V_156 = 8 ;
F_82 ( & V_194 -> V_2 , V_17 ) ;
if ( V_17 -> V_30 -> V_176 ) {
V_83 = F_58 ( V_194 , V_17 , V_195 ) ;
if ( V_83 )
return V_83 ;
}
V_83 = F_83 ( & V_194 -> V_2 , & V_228 ,
& V_17 -> V_91 , 1 ) ;
if ( V_83 ) {
F_36 ( & V_194 -> V_2 , L_23 , V_83 ) ;
goto V_229;
}
if ( V_17 -> V_62 ) {
V_83 = F_84 ( & V_194 -> V_2 , V_17 -> V_24 ,
F_7 , 0 , F_73 ( & V_194 -> V_2 ) ,
V_17 ) ;
if ( V_83 < 0 ) {
F_36 ( & V_194 -> V_2 , L_24 ,
V_17 -> V_24 ) ;
goto V_229;
}
}
V_83 = F_85 ( & V_17 -> V_32 , & V_194 -> V_2 ) ;
if ( V_83 )
goto V_229;
if ( ! F_70 ( V_197 , L_25 , NULL ) )
goto V_230;
V_211 = F_70 ( F_86 ( L_26 ) , L_27 , NULL ) ;
V_191 = strrchr ( V_211 , ',' ) ;
if ( V_191 )
V_211 = V_191 + 1 ;
snprintf ( V_215 , sizeof( V_215 ) , L_28 , V_211 ) ;
F_57 ( V_215 ) ;
V_17 -> V_194 =
F_87 ( & V_194 -> V_2 , V_215 , 0 , NULL , 0 ) ;
if ( F_31 ( V_17 -> V_194 ) ) {
V_83 = F_60 ( V_17 -> V_194 ) ;
F_36 ( & V_194 -> V_2 , L_29 , V_83 ) ;
goto V_231;
}
V_230:
if ( V_17 -> V_18 )
F_44 ( & V_194 -> V_2 , V_17 ,
V_17 -> V_18 ) ;
if ( F_4 ( V_17 ) ) {
T_3 V_232 ;
V_83 = F_88 ( V_197 , L_30 , & V_232 ) ;
if ( V_83 ) {
F_36 ( & V_194 -> V_2 , L_31 ) ;
goto V_231;
}
V_17 -> V_194 =
F_87 ( NULL ,
L_32 , V_232 , NULL , 0 ) ;
if ( F_31 ( V_17 -> V_194 ) ) {
V_83 = F_60 ( V_17 -> V_194 ) ;
F_36 ( & V_194 -> V_2 ,
L_33 ,
V_83 ) ;
goto V_231;
}
}
return 0 ;
V_231:
F_89 ( & V_17 -> V_32 ) ;
V_229:
if ( V_17 -> V_30 -> V_176 )
F_65 ( V_194 , V_17 ) ;
return V_83 ;
}
static int F_90 ( struct V_193 * V_194 )
{
struct V_16 * V_17 = F_91 ( & V_194 -> V_2 ) ;
F_89 ( & V_17 -> V_32 ) ;
if ( V_17 -> V_194 )
F_92 ( V_17 -> V_194 ) ;
if ( V_17 -> V_30 -> V_176 )
F_65 ( V_194 , V_17 ) ;
if ( F_4 ( V_17 ) )
F_93 ( NULL ) ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_91 ( V_2 ) ;
struct V_26 * V_27 = V_17 -> V_27 ;
F_8 ( V_27 , V_11 ,
& V_17 -> V_233 ) ;
F_95 ( V_27 , true ) ;
F_96 ( V_27 ) ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_91 ( V_2 ) ;
struct V_26 * V_27 = V_17 -> V_27 ;
F_95 ( V_27 , false ) ;
F_12 ( V_27 , V_11 ,
V_234 | V_235 |
V_236 | V_237 ,
V_17 -> V_233 ) ;
return F_98 ( V_27 ) ;
}
