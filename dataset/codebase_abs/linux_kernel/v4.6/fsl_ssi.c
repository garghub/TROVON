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
case V_16 :
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
case V_10 :
case V_13 :
case V_14 :
case V_15 :
return true ;
default:
return false ;
}
}
static bool F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_8 :
case V_9 :
case V_16 :
return false ;
default:
return true ;
}
}
static bool F_5 ( struct V_17 * V_18 )
{
return ( V_18 -> V_19 & V_20 ) ==
V_21 ;
}
static bool F_6 ( struct V_17 * V_18 )
{
return ( V_18 -> V_19 & V_22 ) ==
V_23 ;
}
static bool F_7 ( struct V_17 * V_18 )
{
return ( V_18 -> V_19 & V_22 ) ==
V_24 ;
}
static T_1 F_8 ( int V_25 , void * V_26 )
{
struct V_17 * V_18 = V_26 ;
struct V_27 * V_28 = V_18 -> V_28 ;
T_2 V_29 ;
T_2 V_30 ;
F_9 ( V_28 , V_10 , & V_29 ) ;
V_30 = V_29 & V_18 -> V_31 -> V_32 ;
if ( V_30 )
F_10 ( V_28 , V_10 , V_30 ) ;
F_11 ( & V_18 -> V_33 , V_29 ) ;
return V_34 ;
}
static void F_12 ( struct V_17 * V_18 ,
bool V_35 )
{
struct V_27 * V_28 = V_18 -> V_28 ;
struct V_36 * V_37 = & V_18 -> V_38 ;
if ( V_35 ) {
F_13 ( V_28 , V_39 ,
V_37 -> V_40 . V_41 | V_37 -> V_42 . V_41 ,
V_37 -> V_40 . V_41 | V_37 -> V_42 . V_41 ) ;
F_13 ( V_28 , V_43 ,
V_37 -> V_40 . V_44 | V_37 -> V_42 . V_44 ,
V_37 -> V_40 . V_44 | V_37 -> V_42 . V_44 ) ;
F_13 ( V_28 , V_45 ,
V_37 -> V_40 . V_46 | V_37 -> V_42 . V_46 ,
V_37 -> V_40 . V_46 | V_37 -> V_42 . V_46 ) ;
} else {
F_13 ( V_28 , V_43 ,
V_37 -> V_40 . V_44 | V_37 -> V_42 . V_44 , 0 ) ;
F_13 ( V_28 , V_45 ,
V_37 -> V_40 . V_46 | V_37 -> V_42 . V_46 , 0 ) ;
F_13 ( V_28 , V_39 ,
V_37 -> V_40 . V_41 | V_37 -> V_42 . V_41 , 0 ) ;
}
}
static void F_14 ( struct V_17 * V_18 , bool V_35 ,
struct V_47 * V_37 )
{
struct V_27 * V_28 = V_18 -> V_28 ;
struct V_47 * V_48 ;
int V_49 ;
T_3 V_50 ;
int V_51 ;
F_9 ( V_28 , V_52 , & V_50 ) ;
V_49 = ! ! ( V_50 & V_53 ) +
! ! ( V_50 & V_54 ) ;
if ( V_49 - 1 > 0 )
V_51 = 1 ;
else
V_51 = 0 ;
if ( & V_18 -> V_38 . V_40 == V_37 )
V_48 = & V_18 -> V_38 . V_42 ;
else
V_48 = & V_18 -> V_38 . V_40 ;
if ( ! V_35 ) {
T_3 V_55 = F_15 ( V_37 -> V_55 , V_48 -> V_55 ,
V_51 ) ;
F_13 ( V_28 , V_52 , V_55 , 0 ) ;
}
if ( V_18 -> V_31 -> V_56 ) {
if ( ( V_35 && ! V_49 ) ||
( ! V_35 && ! V_51 ) )
F_12 ( V_18 , V_35 ) ;
goto V_57;
}
if ( V_35 ) {
F_13 ( V_28 , V_39 , V_37 -> V_41 , V_37 -> V_41 ) ;
F_13 ( V_28 , V_43 , V_37 -> V_44 , V_37 -> V_44 ) ;
F_13 ( V_28 , V_45 , V_37 -> V_46 , V_37 -> V_46 ) ;
} else {
T_3 V_41 ;
T_3 V_44 ;
T_3 V_46 ;
V_41 = F_15 ( V_37 -> V_41 , V_48 -> V_41 ,
V_51 ) ;
V_44 = F_15 ( V_37 -> V_44 , V_48 -> V_44 ,
V_51 ) ;
V_46 = F_15 ( V_37 -> V_46 , V_48 -> V_46 ,
V_51 ) ;
F_13 ( V_28 , V_43 , V_44 , 0 ) ;
F_13 ( V_28 , V_45 , V_46 , 0 ) ;
F_13 ( V_28 , V_39 , V_41 , 0 ) ;
}
V_57:
if ( V_35 )
F_13 ( V_28 , V_52 , V_37 -> V_55 , V_37 -> V_55 ) ;
}
static void F_16 ( struct V_17 * V_18 , bool V_35 )
{
F_14 ( V_18 , V_35 , & V_18 -> V_38 . V_40 ) ;
}
static void F_17 ( struct V_17 * V_18 , bool V_35 )
{
F_14 ( V_18 , V_35 , & V_18 -> V_38 . V_42 ) ;
}
static void F_18 ( struct V_17 * V_18 )
{
struct V_36 * V_3 = & V_18 -> V_38 ;
V_3 -> V_40 . V_41 = V_58 ;
V_3 -> V_40 . V_44 = V_59 ;
V_3 -> V_40 . V_55 = 0 ;
V_3 -> V_42 . V_41 = V_60 ;
V_3 -> V_42 . V_46 = V_61 ;
V_3 -> V_42 . V_55 = 0 ;
if ( ! F_5 ( V_18 ) ) {
V_3 -> V_40 . V_55 = V_62 | V_54 ;
V_3 -> V_40 . V_41 |= V_58 ;
V_3 -> V_42 . V_55 = V_62 | V_53 ;
V_3 -> V_42 . V_41 |= V_60 ;
}
if ( V_18 -> V_63 ) {
V_3 -> V_40 . V_41 |= V_64 ;
V_3 -> V_42 . V_41 |= V_65 ;
} else {
V_3 -> V_40 . V_41 |= V_66 ;
V_3 -> V_42 . V_41 |= V_67 ;
}
V_3 -> V_40 . V_41 |= V_68 ;
V_3 -> V_42 . V_41 |= V_69 ;
}
static void F_19 ( struct V_17 * V_18 )
{
struct V_27 * V_28 = V_18 -> V_28 ;
F_10 ( V_28 , V_70 ,
F_20 ( 17 ) | F_21 ( 13 ) ) ;
F_10 ( V_28 , V_71 ,
F_20 ( 17 ) | F_21 ( 13 ) ) ;
F_10 ( V_28 , V_12 ,
V_72 | V_73 ) ;
if ( ! V_18 -> V_31 -> V_74 ) {
F_10 ( V_28 , V_5 , 0xff ) ;
F_10 ( V_28 , V_4 , 0x300 ) ;
}
F_13 ( V_28 , V_52 ,
V_62 | V_53 | V_54 ,
V_62 | V_53 | V_54 ) ;
F_10 ( V_28 , V_75 , F_22 ( 3 ) ) ;
}
static int F_23 ( struct V_76 * V_77 ,
struct V_78 * V_79 )
{
struct V_80 * V_81 = V_77 -> V_82 ;
struct V_17 * V_18 =
F_24 ( V_81 -> V_83 ) ;
int V_84 ;
V_84 = F_25 ( V_18 -> V_85 ) ;
if ( V_84 )
return V_84 ;
if ( V_18 -> V_86 )
F_26 ( V_77 -> V_87 , 0 ,
V_88 , 2 ) ;
return 0 ;
}
static void F_27 ( struct V_76 * V_77 ,
struct V_78 * V_79 )
{
struct V_80 * V_81 = V_77 -> V_82 ;
struct V_17 * V_18 =
F_24 ( V_81 -> V_83 ) ;
F_28 ( V_18 -> V_85 ) ;
}
static int F_29 ( struct V_76 * V_77 ,
struct V_78 * V_83 ,
struct V_89 * V_90 )
{
struct V_17 * V_18 = F_24 ( V_83 ) ;
struct V_27 * V_28 = V_18 -> V_28 ;
int V_91 = V_18 -> V_92 . V_93 , V_84 ;
T_3 V_94 = 999 , V_95 , V_96 , V_97 , V_98 , V_99 , V_100 , V_101 ;
unsigned long V_102 , V_103 , V_104 ;
T_4 V_105 , V_106 = 100000 ;
unsigned int V_107 ;
bool V_108 ;
if ( V_18 -> V_109 )
V_107 = V_18 -> V_109 ;
else
V_107 = F_30 ( V_90 ) * 32 * F_31 ( V_90 ) ;
if ( F_32 ( V_18 -> V_110 ) )
return - V_111 ;
V_108 = V_18 -> V_112 & ~ ( F_33 ( V_77 -> V_113 ) ) ;
V_96 = 0 ;
V_95 = 0 ;
V_100 = ( V_95 + 1 ) * ( 7 * V_96 + 1 ) * 2 ;
for ( V_101 = 0 ; V_101 < 255 ; V_101 ++ ) {
V_104 = V_107 * V_100 * ( V_101 + 1 ) ;
if ( V_108 )
V_102 = F_34 ( V_18 -> V_110 ) ;
else
V_102 = F_35 ( V_18 -> V_110 , V_104 ) ;
if ( V_102 * 5 > F_34 ( V_18 -> V_85 ) )
continue;
V_102 /= V_100 ;
V_99 = V_102 / ( V_101 + 1 ) ;
if ( V_107 == V_99 )
V_105 = 0 ;
else if ( V_107 / V_99 == 1 )
V_105 = V_107 - V_99 ;
else if ( V_99 / V_107 == 1 )
V_105 = V_99 - V_107 ;
else
continue;
V_105 *= 100000 ;
F_36 ( V_105 , V_107 ) ;
if ( V_105 < V_106 && ! ( V_101 == 0 && V_96 == 0 && V_95 == 0 ) ) {
V_103 = V_104 ;
V_106 = V_105 ;
V_94 = V_101 ;
}
if ( V_106 == 0 )
break;
}
if ( V_94 == 999 ) {
F_37 ( V_83 -> V_2 , L_1 ) ;
return - V_111 ;
}
V_97 = F_38 ( V_94 + 1 ) | ( V_95 ? V_114 : 0 ) |
( V_96 ? V_115 : 0 ) ;
V_98 = V_116 | V_114 |
V_115 ;
if ( V_77 -> V_113 == V_117 || V_91 )
F_13 ( V_28 , V_70 , V_98 , V_97 ) ;
else
F_13 ( V_28 , V_71 , V_98 , V_97 ) ;
if ( ! V_108 ) {
V_84 = F_39 ( V_18 -> V_110 , V_103 ) ;
if ( V_84 ) {
F_37 ( V_83 -> V_2 , L_2 ) ;
return - V_111 ;
}
}
return 0 ;
}
static int F_40 ( struct V_78 * V_83 ,
int V_118 , unsigned int V_107 , int V_119 )
{
struct V_17 * V_18 = F_24 ( V_83 ) ;
V_18 -> V_109 = V_107 ;
return 0 ;
}
static int F_41 ( struct V_76 * V_77 ,
struct V_89 * V_90 , struct V_78 * V_83 )
{
struct V_17 * V_18 = F_24 ( V_83 ) ;
struct V_27 * V_28 = V_18 -> V_28 ;
unsigned int V_120 = F_30 ( V_90 ) ;
unsigned int V_121 = F_42 ( V_90 ) ;
T_3 V_122 = F_20 ( V_121 ) ;
int V_84 ;
T_3 V_50 ;
int V_123 ;
F_9 ( V_28 , V_52 , & V_50 ) ;
V_123 = V_50 & V_62 ;
if ( V_123 && V_18 -> V_92 . V_93 )
return 0 ;
if ( F_6 ( V_18 ) ) {
V_84 = F_29 ( V_77 , V_83 , V_90 ) ;
if ( V_84 )
return V_84 ;
if ( ! ( V_18 -> V_112 & F_33 ( V_77 -> V_113 ) ) ) {
V_84 = F_25 ( V_18 -> V_110 ) ;
if ( V_84 )
return V_84 ;
V_18 -> V_112 |= F_33 ( V_77 -> V_113 ) ;
}
}
if ( ! F_5 ( V_18 ) ) {
T_5 V_124 ;
if ( F_7 ( V_18 ) && V_121 == 16 )
V_124 = V_125 |
V_126 ;
else
V_124 = V_18 -> V_127 ;
F_13 ( V_28 , V_52 ,
V_126 | V_128 ,
V_120 == 1 ? 0 : V_124 ) ;
}
if ( ( V_77 -> V_113 == V_117 ) ||
V_18 -> V_92 . V_93 )
F_13 ( V_28 , V_70 , V_129 ,
V_122 ) ;
else
F_13 ( V_28 , V_71 , V_129 ,
V_122 ) ;
return 0 ;
}
static int F_43 ( struct V_76 * V_77 ,
struct V_78 * V_83 )
{
struct V_80 * V_81 = V_77 -> V_82 ;
struct V_17 * V_18 =
F_24 ( V_81 -> V_83 ) ;
if ( F_6 ( V_18 ) &&
V_18 -> V_112 & F_33 ( V_77 -> V_113 ) ) {
F_28 ( V_18 -> V_110 ) ;
V_18 -> V_112 &= ~ F_33 ( V_77 -> V_113 ) ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
unsigned int V_130 )
{
struct V_27 * V_28 = V_18 -> V_28 ;
T_3 V_131 = 0 , V_46 , V_44 , V_55 , V_98 ;
T_5 V_132 ;
V_18 -> V_19 = V_130 ;
if ( F_6 ( V_18 ) && F_32 ( V_18 -> V_110 ) ) {
F_37 ( V_2 , L_3 ) ;
return - V_111 ;
}
F_18 ( V_18 ) ;
F_9 ( V_28 , V_52 , & V_55 ) ;
V_55 &= ~ ( V_133 | V_128 ) ;
V_55 |= V_134 ;
V_98 = V_135 | V_136 | V_137 |
V_138 | V_139 | V_140 |
V_141 ;
F_9 ( V_28 , V_45 , & V_46 ) ;
F_9 ( V_28 , V_43 , & V_44 ) ;
V_46 &= ~ V_98 ;
V_44 &= ~ V_98 ;
V_18 -> V_127 = V_126 ;
switch ( V_130 & V_20 ) {
case V_142 :
switch ( V_130 & V_22 ) {
case V_24 :
case V_23 :
V_18 -> V_127 |= V_143 ;
F_13 ( V_28 , V_70 ,
V_144 ,
F_21 ( 2 ) ) ;
F_13 ( V_28 , V_71 ,
V_144 ,
F_21 ( 2 ) ) ;
break;
case V_145 :
V_18 -> V_127 |= V_146 ;
break;
default:
return - V_111 ;
}
V_131 |= V_139 | V_138 |
V_135 | V_141 ;
break;
case V_147 :
V_131 |= V_135 | V_138 ;
break;
case V_148 :
V_131 |= V_140 | V_138 |
V_135 | V_141 ;
break;
case V_149 :
V_131 |= V_140 | V_138 |
V_135 ;
break;
case V_21 :
V_18 -> V_127 |= V_125 ;
break;
default:
return - V_111 ;
}
V_55 |= V_18 -> V_127 ;
switch ( V_130 & V_150 ) {
case V_151 :
break;
case V_152 :
V_131 ^= V_138 ;
break;
case V_153 :
V_131 ^= V_139 ;
break;
case V_154 :
V_131 ^= V_138 ;
V_131 ^= V_139 ;
break;
default:
return - V_111 ;
}
switch ( V_130 & V_22 ) {
case V_23 :
V_131 |= V_136 | V_137 ;
V_55 |= V_155 ;
break;
case V_145 :
V_55 &= ~ V_155 ;
break;
case V_24 :
V_131 &= ~ V_137 ;
V_131 |= V_136 ;
V_55 &= ~ V_155 ;
break;
default:
if ( ! F_5 ( V_18 ) )
return - V_111 ;
}
V_46 |= V_131 ;
V_44 |= V_131 ;
if ( V_18 -> V_92 . V_93
|| F_5 ( V_18 ) ) {
V_44 &= ~ V_156 ;
V_55 |= V_133 ;
}
F_10 ( V_28 , V_45 , V_46 ) ;
F_10 ( V_28 , V_43 , V_44 ) ;
F_10 ( V_28 , V_52 , V_55 ) ;
if ( V_18 -> V_63 )
V_132 = V_18 -> V_157 - 2 ;
else
V_132 = V_18 -> V_157 ;
F_10 ( V_28 , V_11 ,
F_45 ( V_132 ) | F_46 ( V_132 ) |
F_47 ( V_132 ) | F_48 ( V_132 ) ) ;
if ( V_18 -> V_86 ) {
F_13 ( V_28 , V_43 , V_158 ,
V_158 ) ;
F_13 ( V_28 , V_45 , V_159 ,
V_159 ) ;
F_13 ( V_28 , V_52 , V_160 ,
V_160 ) ;
}
if ( ( V_130 & V_20 ) == V_21 )
F_19 ( V_18 ) ;
return 0 ;
}
static int F_49 ( struct V_78 * V_83 , unsigned int V_130 )
{
struct V_17 * V_18 = F_24 ( V_83 ) ;
return F_44 ( V_83 -> V_2 , V_18 , V_130 ) ;
}
static int F_50 ( struct V_78 * V_83 , T_3 V_161 ,
T_3 V_162 , int V_163 , int V_164 )
{
struct V_17 * V_18 = F_24 ( V_83 ) ;
struct V_27 * V_28 = V_18 -> V_28 ;
T_3 V_165 ;
F_9 ( V_28 , V_52 , & V_165 ) ;
V_165 &= V_128 | V_126 ;
if ( V_165 && V_163 < 2 ) {
F_37 ( V_83 -> V_2 , L_4 ) ;
return - V_111 ;
}
F_13 ( V_28 , V_70 , V_144 ,
F_21 ( V_163 ) ) ;
F_13 ( V_28 , V_71 , V_144 ,
F_21 ( V_163 ) ) ;
F_9 ( V_28 , V_52 , & V_165 ) ;
V_165 &= V_62 ;
F_13 ( V_28 , V_52 , V_62 ,
V_62 ) ;
F_10 ( V_28 , V_166 , ~ V_161 ) ;
F_10 ( V_28 , V_167 , ~ V_162 ) ;
F_13 ( V_28 , V_52 , V_62 , V_165 ) ;
return 0 ;
}
static int F_51 ( struct V_76 * V_77 , int V_168 ,
struct V_78 * V_79 )
{
struct V_80 * V_81 = V_77 -> V_82 ;
struct V_17 * V_18 = F_24 ( V_81 -> V_83 ) ;
struct V_27 * V_28 = V_18 -> V_28 ;
switch ( V_168 ) {
case V_169 :
case V_170 :
case V_171 :
if ( V_77 -> V_113 == V_117 )
F_17 ( V_18 , true ) ;
else
F_16 ( V_18 , true ) ;
break;
case V_172 :
case V_173 :
case V_174 :
if ( V_77 -> V_113 == V_117 )
F_17 ( V_18 , false ) ;
else
F_16 ( V_18 , false ) ;
break;
default:
return - V_111 ;
}
if ( F_5 ( V_18 ) ) {
if ( V_77 -> V_113 == V_117 )
F_10 ( V_28 , V_75 , V_175 ) ;
else
F_10 ( V_28 , V_75 , V_176 ) ;
}
return 0 ;
}
static int F_52 ( struct V_78 * V_79 )
{
struct V_17 * V_18 = F_24 ( V_79 ) ;
if ( V_18 -> V_31 -> V_177 && V_18 -> V_63 ) {
V_79 -> V_178 = & V_18 -> V_179 ;
V_79 -> V_180 = & V_18 -> V_181 ;
}
return 0 ;
}
static void F_53 ( struct V_182 * V_183 , unsigned short V_3 ,
unsigned short V_165 )
{
struct V_27 * V_28 = V_184 -> V_28 ;
unsigned int V_185 ;
unsigned int V_186 ;
int V_84 ;
if ( V_3 > 0x7f )
return;
V_84 = F_25 ( V_184 -> V_85 ) ;
if ( V_84 ) {
F_54 ( L_5 ,
V_84 ) ;
return;
}
V_185 = V_3 << 12 ;
F_10 ( V_28 , V_13 , V_185 ) ;
V_186 = V_165 << 4 ;
F_10 ( V_28 , V_14 , V_186 ) ;
F_13 ( V_28 , V_12 , V_187 ,
V_188 ) ;
F_55 ( 100 ) ;
F_28 ( V_184 -> V_85 ) ;
}
static unsigned short F_56 ( struct V_182 * V_183 ,
unsigned short V_3 )
{
struct V_27 * V_28 = V_184 -> V_28 ;
unsigned short V_165 = - 1 ;
T_3 V_189 ;
unsigned int V_185 ;
int V_84 ;
V_84 = F_25 ( V_184 -> V_85 ) ;
if ( V_84 ) {
F_54 ( L_6 ,
V_84 ) ;
return - 1 ;
}
V_185 = ( V_3 & 0x7f ) << 12 ;
F_10 ( V_28 , V_13 , V_185 ) ;
F_13 ( V_28 , V_12 , V_187 ,
V_190 ) ;
F_55 ( 100 ) ;
F_9 ( V_28 , V_14 , & V_189 ) ;
V_165 = ( V_189 >> 4 ) & 0xffff ;
F_28 ( V_184 -> V_85 ) ;
return V_165 ;
}
static void F_57 ( char * V_191 )
{
char * V_192 = V_191 ;
char V_193 ;
while ( ( V_193 = * V_192 ) ) {
if ( ( V_193 >= 'A' ) && ( V_193 <= 'Z' ) )
* V_192 = V_193 + ( 'a' - 'A' ) ;
V_192 ++ ;
}
}
static int F_58 ( struct V_194 * V_195 ,
struct V_17 * V_18 , void T_6 * V_196 )
{
struct V_197 * V_198 = V_195 -> V_2 . V_199 ;
T_3 V_200 [ 4 ] ;
int V_84 ;
if ( V_18 -> V_201 )
V_18 -> V_85 = F_59 ( & V_195 -> V_2 , L_7 ) ;
else
V_18 -> V_85 = F_59 ( & V_195 -> V_2 , NULL ) ;
if ( F_32 ( V_18 -> V_85 ) ) {
V_84 = F_60 ( V_18 -> V_85 ) ;
F_37 ( & V_195 -> V_2 , L_8 , V_84 ) ;
return V_84 ;
}
if ( ! V_18 -> V_201 ) {
V_84 = F_25 ( V_18 -> V_85 ) ;
if ( V_84 ) {
F_37 ( & V_195 -> V_2 , L_9 , V_84 ) ;
return V_84 ;
}
}
V_18 -> V_110 = F_59 ( & V_195 -> V_2 , L_10 ) ;
if ( F_32 ( V_18 -> V_110 ) )
F_61 ( & V_195 -> V_2 , L_11 ,
F_60 ( V_18 -> V_110 ) ) ;
V_18 -> V_179 . V_202 = V_18 -> V_157 - 2 ;
V_18 -> V_181 . V_202 = V_18 -> V_157 - 2 ;
V_18 -> V_179 . V_203 = V_18 -> V_204 + V_6 ;
V_18 -> V_181 . V_203 = V_18 -> V_204 + V_8 ;
V_84 = F_62 ( V_198 , L_12 , V_200 , 4 ) ;
if ( V_18 -> V_63 && ! V_84 && V_200 [ 2 ] == V_205 ) {
V_18 -> V_86 = true ;
V_18 -> V_179 . V_202 &= ~ 0x1 ;
V_18 -> V_181 . V_202 &= ~ 0x1 ;
}
if ( ! V_18 -> V_63 ) {
V_18 -> V_206 . V_25 = V_18 -> V_25 ;
V_18 -> V_206 . V_207 = V_196 ;
V_18 -> V_206 . V_181 =
& V_18 -> V_181 ;
V_18 -> V_206 . V_179 =
& V_18 -> V_179 ;
V_84 = F_63 ( V_195 , & V_18 -> V_206 ) ;
if ( V_84 )
goto V_208;
} else {
V_84 = F_64 ( V_195 , V_209 ) ;
if ( V_84 )
goto V_208;
}
return 0 ;
V_208:
if ( ! V_18 -> V_201 )
F_28 ( V_18 -> V_85 ) ;
return V_84 ;
}
static void F_65 ( struct V_194 * V_195 ,
struct V_17 * V_18 )
{
if ( ! V_18 -> V_63 )
F_66 ( V_195 ) ;
if ( ! V_18 -> V_201 )
F_28 ( V_18 -> V_85 ) ;
}
static int F_67 ( struct V_194 * V_195 )
{
struct V_17 * V_18 ;
int V_84 = 0 ;
struct V_197 * V_198 = V_195 -> V_2 . V_199 ;
const struct V_210 * V_211 ;
const char * V_192 , * V_212 ;
const T_7 * V_213 ;
struct V_214 * V_215 ;
void T_6 * V_196 ;
char V_216 [ 64 ] ;
struct V_217 V_218 = V_219 ;
V_211 = F_68 ( V_220 , & V_195 -> V_2 ) ;
if ( ! V_211 || ! V_211 -> V_221 )
return - V_111 ;
V_18 = F_69 ( & V_195 -> V_2 , sizeof( * V_18 ) ,
V_222 ) ;
if ( ! V_18 ) {
F_37 ( & V_195 -> V_2 , L_13 ) ;
return - V_223 ;
}
V_18 -> V_31 = V_211 -> V_221 ;
V_212 = F_70 ( V_198 , L_14 , NULL ) ;
if ( V_212 ) {
if ( ! strcmp ( V_212 , L_15 ) )
V_18 -> V_19 = V_21 ;
}
V_18 -> V_63 = ! F_71 ( V_198 ,
L_16 ) ;
if ( F_5 ( V_18 ) ) {
memcpy ( & V_18 -> V_92 , & V_224 ,
sizeof( V_224 ) ) ;
V_184 = V_18 ;
V_84 = F_72 ( & V_225 , V_195 ) ;
if ( V_84 ) {
F_37 ( & V_195 -> V_2 , L_17 ) ;
return V_84 ;
}
} else {
memcpy ( & V_18 -> V_92 , & V_226 ,
sizeof( V_226 ) ) ;
}
V_18 -> V_92 . V_216 = F_73 ( & V_195 -> V_2 ) ;
V_215 = F_74 ( V_195 , V_227 , 0 ) ;
V_196 = F_75 ( & V_195 -> V_2 , V_215 ) ;
if ( F_32 ( V_196 ) )
return F_60 ( V_196 ) ;
V_18 -> V_204 = V_215 -> V_228 ;
if ( V_18 -> V_31 -> V_74 ) {
V_218 . V_229 = V_167 ;
V_218 . V_230 =
V_167 / sizeof( T_7 ) + 1 ;
}
V_84 = F_76 ( V_198 , L_18 , L_7 ) ;
if ( V_84 < 0 ) {
V_18 -> V_201 = false ;
V_18 -> V_28 = F_77 ( & V_195 -> V_2 , V_196 ,
& V_218 ) ;
} else {
V_18 -> V_201 = true ;
V_18 -> V_28 = F_78 ( & V_195 -> V_2 ,
L_7 , V_196 , & V_218 ) ;
}
if ( F_32 ( V_18 -> V_28 ) ) {
F_37 ( & V_195 -> V_2 , L_19 ) ;
return F_60 ( V_18 -> V_28 ) ;
}
V_18 -> V_25 = F_79 ( V_195 , 0 ) ;
if ( V_18 -> V_25 < 0 ) {
F_37 ( & V_195 -> V_2 , L_20 , V_195 -> V_216 ) ;
return V_18 -> V_25 ;
}
if ( ! F_80 ( V_198 , L_21 , NULL ) ) {
if ( ! F_5 ( V_18 ) )
V_18 -> V_92 . V_93 = 1 ;
V_18 -> V_92 . V_231 = 1 ;
V_18 -> V_92 . V_232 = 1 ;
}
V_213 = F_70 ( V_198 , L_22 , NULL ) ;
if ( V_213 )
V_18 -> V_157 = F_81 ( V_213 ) ;
else
V_18 -> V_157 = 8 ;
F_82 ( & V_195 -> V_2 , V_18 ) ;
if ( V_18 -> V_31 -> V_177 ) {
V_84 = F_58 ( V_195 , V_18 , V_196 ) ;
if ( V_84 )
return V_84 ;
}
V_84 = F_83 ( & V_195 -> V_2 , & V_233 ,
& V_18 -> V_92 , 1 ) ;
if ( V_84 ) {
F_37 ( & V_195 -> V_2 , L_23 , V_84 ) ;
goto V_234;
}
if ( V_18 -> V_63 ) {
V_84 = F_84 ( & V_195 -> V_2 , V_18 -> V_25 ,
F_8 , 0 , F_73 ( & V_195 -> V_2 ) ,
V_18 ) ;
if ( V_84 < 0 ) {
F_37 ( & V_195 -> V_2 , L_24 ,
V_18 -> V_25 ) ;
goto V_234;
}
}
V_84 = F_85 ( & V_18 -> V_33 , & V_195 -> V_2 ) ;
if ( V_84 )
goto V_234;
if ( ! F_70 ( V_198 , L_25 , NULL ) )
goto V_235;
V_212 = F_70 ( F_86 ( L_26 ) , L_27 , NULL ) ;
V_192 = strrchr ( V_212 , ',' ) ;
if ( V_192 )
V_212 = V_192 + 1 ;
snprintf ( V_216 , sizeof( V_216 ) , L_28 , V_212 ) ;
F_57 ( V_216 ) ;
V_18 -> V_195 =
F_87 ( & V_195 -> V_2 , V_216 , 0 , NULL , 0 ) ;
if ( F_32 ( V_18 -> V_195 ) ) {
V_84 = F_60 ( V_18 -> V_195 ) ;
F_37 ( & V_195 -> V_2 , L_29 , V_84 ) ;
goto V_236;
}
V_235:
if ( V_18 -> V_19 )
F_44 ( & V_195 -> V_2 , V_18 ,
V_18 -> V_19 ) ;
if ( F_5 ( V_18 ) ) {
T_3 V_237 ;
V_84 = F_88 ( V_198 , L_30 , & V_237 ) ;
if ( V_84 ) {
F_37 ( & V_195 -> V_2 , L_31 ) ;
goto V_236;
}
V_18 -> V_195 =
F_87 ( NULL ,
L_32 , V_237 , NULL , 0 ) ;
if ( F_32 ( V_18 -> V_195 ) ) {
V_84 = F_60 ( V_18 -> V_195 ) ;
F_37 ( & V_195 -> V_2 ,
L_33 ,
V_84 ) ;
goto V_236;
}
}
return 0 ;
V_236:
F_89 ( & V_18 -> V_33 ) ;
V_234:
if ( V_18 -> V_31 -> V_177 )
F_65 ( V_195 , V_18 ) ;
return V_84 ;
}
static int F_90 ( struct V_194 * V_195 )
{
struct V_17 * V_18 = F_91 ( & V_195 -> V_2 ) ;
F_89 ( & V_18 -> V_33 ) ;
if ( V_18 -> V_195 )
F_92 ( V_18 -> V_195 ) ;
if ( V_18 -> V_31 -> V_177 )
F_65 ( V_195 , V_18 ) ;
if ( F_5 ( V_18 ) )
F_93 ( NULL ) ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_91 ( V_2 ) ;
struct V_27 * V_28 = V_18 -> V_28 ;
F_9 ( V_28 , V_11 ,
& V_18 -> V_238 ) ;
F_9 ( V_28 , V_12 ,
& V_18 -> V_239 ) ;
F_95 ( V_28 , true ) ;
F_96 ( V_28 ) ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_91 ( V_2 ) ;
struct V_27 * V_28 = V_18 -> V_28 ;
F_95 ( V_28 , false ) ;
F_13 ( V_28 , V_11 ,
V_240 | V_241 |
V_242 | V_243 ,
V_18 -> V_238 ) ;
F_10 ( V_28 , V_12 ,
V_18 -> V_239 ) ;
return F_98 ( V_28 ) ;
}
