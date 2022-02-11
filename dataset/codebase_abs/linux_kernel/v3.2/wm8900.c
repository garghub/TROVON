static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
return 1 ;
default:
return 0 ;
}
}
static void F_2 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_5 , 0 ) ;
memcpy ( V_2 -> V_6 , V_7 ,
sizeof( V_7 ) ) ;
}
static int F_4 ( struct V_8 * V_9 ,
struct V_10 * V_11 , int V_12 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_1 V_13 = F_5 ( V_2 , V_14 ) ;
switch ( V_12 ) {
case V_15 :
V_13 = V_16 |
V_17 ;
F_3 ( V_2 , V_14 , V_13 ) ;
break;
case V_18 :
V_13 &= ~ V_16 ;
V_13 |= V_19 |
V_20 |
V_21 ;
F_3 ( V_2 , V_14 , V_13 ) ;
F_6 ( 400 ) ;
V_13 &= ~ V_17 ;
V_13 |= V_22 ;
F_3 ( V_2 , V_14 , V_13 ) ;
V_13 &= ~ V_20 ;
F_3 ( V_2 , V_14 , V_13 ) ;
V_13 &= ~ V_19 ;
F_3 ( V_2 , V_14 , V_13 ) ;
break;
case V_23 :
V_13 |= V_19 ;
F_3 ( V_2 , V_14 , V_13 ) ;
V_13 &= ~ V_22 ;
F_3 ( V_2 , V_14 , V_13 ) ;
V_13 |= V_16 |
V_17 ;
V_13 &= ~ V_21 ;
F_3 ( V_2 , V_14 , V_13 ) ;
break;
case V_24 :
F_3 ( V_2 , V_14 , 0 ) ;
break;
default:
F_7 () ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_26 ;
F_9 ( V_26 , V_27 ,
F_10 ( V_27 ) ) ;
F_11 ( V_26 , V_28 , F_10 ( V_28 ) ) ;
return 0 ;
}
static int F_12 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = V_30 -> V_37 ;
struct V_1 * V_2 = V_36 -> V_2 ;
T_1 V_3 ;
V_3 = F_5 ( V_2 , V_38 ) & ~ 0x60 ;
switch ( F_13 ( V_32 ) ) {
case V_39 :
break;
case V_40 :
V_3 |= 0x20 ;
break;
case V_41 :
V_3 |= 0x40 ;
break;
case V_42 :
V_3 |= 0x60 ;
break;
default:
return - V_43 ;
}
F_3 ( V_2 , V_38 , V_3 ) ;
if ( V_30 -> V_44 == V_45 ) {
V_3 = F_5 ( V_2 , V_46 ) ;
if ( F_14 ( V_32 ) <= 24000 )
V_3 |= V_47 ;
else
V_3 &= ~ V_47 ;
F_3 ( V_2 , V_46 , V_3 ) ;
}
return 0 ;
}
static int F_15 ( struct V_48 * V_49 , unsigned int V_50 ,
unsigned int V_51 )
{
T_2 V_52 ;
unsigned int V_53 , V_54 , V_55 , V_56 ;
unsigned int div ;
F_16 ( ! V_51 ) ;
V_56 = V_51 ;
div = 1 ;
while ( V_56 < 90000000 ) {
div *= 2 ;
V_56 *= 2 ;
}
if ( V_56 > 100000000 )
F_17 ( V_57 L_1
L_2 , V_56 , V_50 , V_51 ) ;
if ( div > 32 ) {
F_17 ( V_58 L_3
L_4 ,
div , V_50 , V_51 , V_56 ) ;
return - V_43 ;
}
V_49 -> V_59 = div >> 2 ;
if ( V_50 < 48000 )
V_49 -> V_60 = 1 ;
else
V_49 -> V_60 = 0 ;
V_54 = V_56 / V_50 ;
if ( V_50 < 1000000 )
V_49 -> V_61 = 8 ;
else
V_49 -> V_61 = 1 ;
V_49 -> V_62 = V_54 / V_49 -> V_61 ;
V_55 = ( V_56 / V_49 -> V_61 ) % V_50 ;
V_52 = V_63 * ( long long ) V_55 ;
F_18 ( V_52 , V_50 ) ;
V_53 = V_52 & 0xFFFFFFFF ;
if ( ( V_53 % 10 ) >= 5 )
V_53 += 5 ;
V_49 -> V_64 = V_53 / 10 ;
F_16 ( V_56 != V_51 * ( V_49 -> V_59 << 2 ) ) ;
F_16 ( ! V_53 && V_56 != V_50 * V_49 -> V_61 * V_49 -> V_62 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
int V_65 , unsigned int V_66 , unsigned int V_67 )
{
struct V_68 * V_69 = F_20 ( V_2 ) ;
struct V_48 V_49 ;
if ( V_69 -> V_70 == V_66 && V_69 -> V_71 == V_67 )
return 0 ;
F_21 ( V_2 , V_72 ,
V_73 , 0 ) ;
if ( ! V_66 || ! V_67 ) {
F_21 ( V_2 , V_74 ,
V_75 , 0 ) ;
F_21 ( V_2 , V_76 ,
V_77 , 0 ) ;
V_69 -> V_70 = V_66 ;
V_69 -> V_71 = V_67 ;
return 0 ;
}
if ( F_15 ( & V_49 , V_66 , V_67 ) != 0 )
goto V_78;
V_69 -> V_70 = V_66 ;
V_69 -> V_71 = V_67 ;
F_3 ( V_2 , V_76 ,
V_49 . V_61 | V_77 ) ;
F_3 ( V_2 , V_79 , V_49 . V_62 >> 5 ) ;
F_3 ( V_2 , V_80 ,
( V_49 . V_59 << 6 ) | ( V_49 . V_62 & 0x1f ) ) ;
if ( V_49 . V_64 ) {
F_3 ( V_2 , V_81 ,
( V_49 . V_64 >> 8 ) | 0x100 ) ;
F_3 ( V_2 , V_82 , V_49 . V_64 & 0xff ) ;
} else
F_3 ( V_2 , V_81 , 0 ) ;
if ( V_49 . V_60 )
F_3 ( V_2 , V_83 ,
V_84 ) ;
else
F_3 ( V_2 , V_83 , 0 ) ;
F_21 ( V_2 , V_72 ,
V_73 ,
V_73 ) ;
V_78:
F_21 ( V_2 , V_74 ,
V_75 ,
V_75 ) ;
return 0 ;
}
static int F_22 ( struct V_33 * V_85 , int V_86 ,
int V_87 , unsigned int V_66 , unsigned int V_67 )
{
return F_19 ( V_85 -> V_2 , V_86 , V_66 , V_67 ) ;
}
static int F_23 ( struct V_33 * V_85 ,
int V_88 , int div )
{
struct V_1 * V_2 = V_85 -> V_2 ;
switch ( V_88 ) {
case V_89 :
F_21 ( V_2 , V_74 ,
V_90 , div ) ;
break;
case V_91 :
F_21 ( V_2 , V_74 ,
V_92 , div ) ;
break;
case V_93 :
F_21 ( V_2 , V_94 ,
V_95 , div ) ;
break;
case V_96 :
F_21 ( V_2 , V_97 ,
V_95 , div ) ;
break;
case V_98 :
F_21 ( V_2 , V_99 ,
V_100 , div ) ;
break;
case V_101 :
F_21 ( V_2 , V_99 ,
V_102 , div ) ;
break;
case V_103 :
F_21 ( V_2 , V_46 ,
V_104 , div ) ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_24 ( struct V_33 * V_85 ,
unsigned int V_105 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned int V_106 , V_107 , V_108 , V_109 ;
V_106 = F_5 ( V_2 , V_74 ) ;
V_107 = F_5 ( V_2 , V_38 ) ;
V_108 = F_5 ( V_2 , V_97 ) ;
V_109 = F_5 ( V_2 , V_94 ) ;
switch ( V_105 & V_110 ) {
case V_111 :
V_106 &= ~ V_112 ;
V_108 &= ~ V_113 ;
V_109 &= ~ V_114 ;
break;
case V_115 :
V_106 &= ~ V_112 ;
V_108 |= V_113 ;
V_109 |= V_114 ;
break;
case V_116 :
V_106 |= V_112 ;
V_108 |= V_113 ;
V_109 |= V_114 ;
break;
case V_117 :
V_106 |= V_112 ;
V_108 &= ~ V_113 ;
V_109 &= ~ V_114 ;
break;
default:
return - V_43 ;
}
switch ( V_105 & V_118 ) {
case V_119 :
V_107 |= V_120 ;
V_107 &= ~ V_121 ;
break;
case V_122 :
V_107 |= V_120 ;
V_107 |= V_121 ;
break;
case V_123 :
V_107 &= ~ V_120 ;
V_107 |= 0x10 ;
break;
case V_124 :
V_107 &= ~ V_120 ;
break;
case V_125 :
V_107 &= ~ V_120 ;
V_107 |= 0x8 ;
break;
default:
return - V_43 ;
}
switch ( V_105 & V_118 ) {
case V_119 :
case V_122 :
switch ( V_105 & V_126 ) {
case V_127 :
V_107 &= ~ V_128 ;
break;
case V_129 :
V_107 |= V_128 ;
break;
default:
return - V_43 ;
}
break;
case V_123 :
case V_124 :
case V_125 :
switch ( V_105 & V_126 ) {
case V_127 :
V_107 &= ~ V_128 ;
V_107 &= ~ V_121 ;
break;
case V_130 :
V_107 |= V_128 ;
V_107 |= V_121 ;
break;
case V_129 :
V_107 |= V_128 ;
V_107 &= ~ V_121 ;
break;
case V_131 :
V_107 &= ~ V_128 ;
V_107 |= V_121 ;
break;
default:
return - V_43 ;
}
break;
default:
return - V_43 ;
}
F_3 ( V_2 , V_74 , V_106 ) ;
F_3 ( V_2 , V_38 , V_107 ) ;
F_3 ( V_2 , V_97 , V_108 ) ;
F_3 ( V_2 , V_94 , V_109 ) ;
return 0 ;
}
static int F_25 ( struct V_33 * V_85 , int V_132 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
T_1 V_3 ;
V_3 = F_5 ( V_2 , V_46 ) ;
if ( V_132 )
V_3 |= V_133 ;
else
V_3 &= ~ V_133 ;
F_3 ( V_2 , V_46 , V_3 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
enum V_134 V_135 )
{
T_1 V_3 ;
switch ( V_135 ) {
case V_136 :
F_21 ( V_2 , V_137 ,
V_138 ,
V_138 ) ;
F_21 ( V_2 , V_139 ,
V_140 ,
V_140 ) ;
break;
case V_141 :
break;
case V_142 :
if ( V_2 -> V_26 . V_143 == V_144 ) {
F_3 ( V_2 , V_72 ,
V_145 ) ;
F_3 ( V_2 , V_139 ,
V_146 |
V_147 ) ;
F_3 ( V_2 , V_72 ,
V_145 | 0x1 ) ;
F_27 ( F_28 ( 400 ) ) ;
F_3 ( V_2 , V_72 ,
V_145 |
V_148 | 0x1 ) ;
F_3 ( V_2 , V_139 , 0 ) ;
F_3 ( V_2 , V_72 ,
V_148 | 0x1 ) ;
}
V_3 = F_5 ( V_2 , V_72 ) ;
F_3 ( V_2 , V_72 ,
( V_3 & V_73 ) |
V_148 | 0x1 ) ;
F_3 ( V_2 , V_149 ,
V_150 ) ;
F_3 ( V_2 , V_151 , 0 ) ;
break;
case V_144 :
V_3 = F_5 ( V_2 , V_72 ) ;
F_3 ( V_2 , V_72 ,
V_3 & V_145 ) ;
F_3 ( V_2 , V_139 ,
V_146 |
V_147 ) ;
F_3 ( V_2 , V_72 ,
V_145 ) ;
F_27 ( F_28 ( 500 ) ) ;
F_3 ( V_2 , V_14 , 0 ) ;
F_3 ( V_2 , V_139 , 0 ) ;
F_3 ( V_2 , V_72 , 0 ) ;
F_3 ( V_2 , V_149 , 0 ) ;
F_3 ( V_2 , V_151 , 0 ) ;
F_27 ( F_28 ( 1 ) ) ;
F_3 ( V_2 , V_149 ,
V_150 ) ;
break;
}
V_2 -> V_26 . V_143 = V_135 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , T_3 V_152 )
{
struct V_68 * V_69 = F_20 ( V_2 ) ;
int V_71 = V_69 -> V_71 ;
int V_70 = V_69 -> V_70 ;
int V_153 ;
V_153 = F_19 ( V_2 , 0 , 0 , 0 ) ;
if ( V_153 != 0 ) {
F_30 ( V_2 -> V_154 , L_5 ) ;
return V_153 ;
}
V_69 -> V_71 = V_71 ;
V_69 -> V_70 = V_70 ;
F_26 ( V_2 , V_144 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = F_20 ( V_2 ) ;
T_1 * V_155 ;
int V_156 , V_153 ;
V_155 = F_32 ( V_2 -> V_6 , sizeof( V_7 ) ,
V_157 ) ;
F_2 ( V_2 ) ;
F_26 ( V_2 , V_142 ) ;
if ( V_69 -> V_71 ) {
int V_71 = V_69 -> V_71 ;
int V_70 = V_69 -> V_70 ;
V_69 -> V_70 = 0 ;
V_69 -> V_71 = 0 ;
V_153 = F_19 ( V_2 , 0 , V_70 , V_71 ) ;
if ( V_153 != 0 ) {
F_30 ( V_2 -> V_154 , L_6 ) ;
F_33 ( V_155 ) ;
return V_153 ;
}
}
if ( V_155 ) {
for ( V_156 = 0 ; V_156 < V_158 ; V_156 ++ )
F_3 ( V_2 , V_156 , V_155 [ V_156 ] ) ;
F_33 ( V_155 ) ;
} else
F_30 ( V_2 -> V_154 , L_7 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = F_20 ( V_2 ) ;
int V_153 = 0 , V_3 ;
V_153 = F_35 ( V_2 , 8 , 16 , V_69 -> V_159 ) ;
if ( V_153 != 0 ) {
F_30 ( V_2 -> V_154 , L_8 , V_153 ) ;
return V_153 ;
}
V_3 = F_5 ( V_2 , V_4 ) ;
if ( V_3 != 0x8900 ) {
F_30 ( V_2 -> V_154 , L_9 , V_3 ) ;
return - V_160 ;
}
F_2 ( V_2 ) ;
F_26 ( V_2 , V_142 ) ;
F_21 ( V_2 , V_161 , 0x100 , 0x100 ) ;
F_21 ( V_2 , V_162 , 0x100 , 0x100 ) ;
F_21 ( V_2 , V_163 , 0x100 , 0x100 ) ;
F_21 ( V_2 , V_164 , 0x100 , 0x100 ) ;
F_21 ( V_2 , V_165 , 0x100 , 0x100 ) ;
F_21 ( V_2 , V_166 , 0x100 , 0x100 ) ;
F_21 ( V_2 , V_167 , 0x100 , 0x100 ) ;
F_21 ( V_2 , V_168 , 0x100 , 0x100 ) ;
F_21 ( V_2 , V_169 , 0x100 , 0x100 ) ;
F_21 ( V_2 , V_170 , 0x100 , 0x100 ) ;
F_3 ( V_2 , V_171 , 0x81 ) ;
F_36 ( V_2 , V_172 ,
F_10 ( V_172 ) ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
F_26 ( V_2 , V_144 ) ;
return 0 ;
}
static int T_4 F_38 ( struct V_173 * V_174 )
{
struct V_68 * V_69 ;
int V_153 ;
V_69 = F_39 ( sizeof( struct V_68 ) , V_157 ) ;
if ( V_69 == NULL )
return - V_175 ;
V_69 -> V_159 = V_176 ;
F_40 ( V_174 , V_69 ) ;
V_153 = F_41 ( & V_174 -> V_154 ,
& V_177 , & V_178 , 1 ) ;
if ( V_153 < 0 )
F_33 ( V_69 ) ;
return V_153 ;
}
static int T_5 F_42 ( struct V_173 * V_174 )
{
F_43 ( & V_174 -> V_154 ) ;
F_33 ( F_44 ( V_174 ) ) ;
return 0 ;
}
static T_4 int F_45 ( struct V_179 * V_180 ,
const struct V_181 * V_182 )
{
struct V_68 * V_69 ;
int V_153 ;
V_69 = F_39 ( sizeof( struct V_68 ) , V_157 ) ;
if ( V_69 == NULL )
return - V_175 ;
F_46 ( V_180 , V_69 ) ;
V_69 -> V_159 = V_183 ;
V_153 = F_41 ( & V_180 -> V_154 ,
& V_177 , & V_178 , 1 ) ;
if ( V_153 < 0 )
F_33 ( V_69 ) ;
return V_153 ;
}
static T_5 int F_47 ( struct V_179 * V_184 )
{
F_43 ( & V_184 -> V_154 ) ;
F_33 ( F_48 ( V_184 ) ) ;
return 0 ;
}
static int T_6 F_49 ( void )
{
int V_153 = 0 ;
#if F_50 ( V_185 ) || F_50 ( V_186 )
V_153 = F_51 ( & V_187 ) ;
if ( V_153 != 0 ) {
F_17 ( V_58 L_10 ,
V_153 ) ;
}
#endif
#if F_50 ( V_188 )
V_153 = F_52 ( & V_189 ) ;
if ( V_153 != 0 ) {
F_17 ( V_58 L_11 ,
V_153 ) ;
}
#endif
return V_153 ;
}
static void T_7 F_53 ( void )
{
#if F_50 ( V_185 ) || F_50 ( V_186 )
F_54 ( & V_187 ) ;
#endif
#if F_50 ( V_188 )
F_55 ( & V_189 ) ;
#endif
}
