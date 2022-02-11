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
static int F_8 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_31 * V_32 = V_26 -> V_33 ;
struct V_1 * V_2 = V_32 -> V_2 ;
T_1 V_3 ;
V_3 = F_5 ( V_2 , V_34 ) & ~ 0x60 ;
switch ( F_9 ( V_28 ) ) {
case V_35 :
break;
case V_36 :
V_3 |= 0x20 ;
break;
case V_37 :
V_3 |= 0x40 ;
break;
case V_38 :
V_3 |= 0x60 ;
break;
default:
return - V_39 ;
}
F_3 ( V_2 , V_34 , V_3 ) ;
if ( V_26 -> V_40 == V_41 ) {
V_3 = F_5 ( V_2 , V_42 ) ;
if ( F_10 ( V_28 ) <= 24000 )
V_3 |= V_43 ;
else
V_3 &= ~ V_43 ;
F_3 ( V_2 , V_42 , V_3 ) ;
}
return 0 ;
}
static int F_11 ( struct V_44 * V_45 , unsigned int V_46 ,
unsigned int V_47 )
{
T_2 V_48 ;
unsigned int V_49 , V_50 , V_51 , V_52 ;
unsigned int div ;
F_12 ( ! V_47 ) ;
V_52 = V_47 ;
div = 1 ;
while ( V_52 < 90000000 ) {
div *= 2 ;
V_52 *= 2 ;
}
if ( V_52 > 100000000 )
F_13 ( V_53 L_1
L_2 , V_52 , V_46 , V_47 ) ;
if ( div > 32 ) {
F_13 ( V_54 L_3
L_4 ,
div , V_46 , V_47 , V_52 ) ;
return - V_39 ;
}
V_45 -> V_55 = div >> 2 ;
if ( V_46 < 48000 )
V_45 -> V_56 = 1 ;
else
V_45 -> V_56 = 0 ;
V_50 = V_52 / V_46 ;
if ( V_46 < 1000000 )
V_45 -> V_57 = 8 ;
else
V_45 -> V_57 = 1 ;
V_45 -> V_58 = V_50 / V_45 -> V_57 ;
V_51 = ( V_52 / V_45 -> V_57 ) % V_46 ;
V_48 = V_59 * ( long long ) V_51 ;
F_14 ( V_48 , V_46 ) ;
V_49 = V_48 & 0xFFFFFFFF ;
if ( ( V_49 % 10 ) >= 5 )
V_49 += 5 ;
V_45 -> V_60 = V_49 / 10 ;
F_12 ( V_52 != V_47 * ( V_45 -> V_55 << 2 ) ) ;
F_12 ( ! V_49 && V_52 != V_46 * V_45 -> V_57 * V_45 -> V_58 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
int V_61 , unsigned int V_62 , unsigned int V_63 )
{
struct V_64 * V_65 = F_16 ( V_2 ) ;
struct V_44 V_45 ;
if ( V_65 -> V_66 == V_62 && V_65 -> V_67 == V_63 )
return 0 ;
F_17 ( V_2 , V_68 ,
V_69 , 0 ) ;
if ( ! V_62 || ! V_63 ) {
F_17 ( V_2 , V_70 ,
V_71 , 0 ) ;
F_17 ( V_2 , V_72 ,
V_73 , 0 ) ;
V_65 -> V_66 = V_62 ;
V_65 -> V_67 = V_63 ;
return 0 ;
}
if ( F_11 ( & V_45 , V_62 , V_63 ) != 0 )
goto V_74;
V_65 -> V_66 = V_62 ;
V_65 -> V_67 = V_63 ;
F_3 ( V_2 , V_72 ,
V_45 . V_57 | V_73 ) ;
F_3 ( V_2 , V_75 , V_45 . V_58 >> 5 ) ;
F_3 ( V_2 , V_76 ,
( V_45 . V_55 << 6 ) | ( V_45 . V_58 & 0x1f ) ) ;
if ( V_45 . V_60 ) {
F_3 ( V_2 , V_77 ,
( V_45 . V_60 >> 8 ) | 0x100 ) ;
F_3 ( V_2 , V_78 , V_45 . V_60 & 0xff ) ;
} else
F_3 ( V_2 , V_77 , 0 ) ;
if ( V_45 . V_56 )
F_3 ( V_2 , V_79 ,
V_80 ) ;
else
F_3 ( V_2 , V_79 , 0 ) ;
F_17 ( V_2 , V_68 ,
V_69 ,
V_69 ) ;
V_74:
F_17 ( V_2 , V_70 ,
V_71 ,
V_71 ) ;
return 0 ;
}
static int F_18 ( struct V_29 * V_81 , int V_82 ,
int V_83 , unsigned int V_62 , unsigned int V_63 )
{
return F_15 ( V_81 -> V_2 , V_82 , V_62 , V_63 ) ;
}
static int F_19 ( struct V_29 * V_81 ,
int V_84 , int div )
{
struct V_1 * V_2 = V_81 -> V_2 ;
switch ( V_84 ) {
case V_85 :
F_17 ( V_2 , V_70 ,
V_86 , div ) ;
break;
case V_87 :
F_17 ( V_2 , V_70 ,
V_88 , div ) ;
break;
case V_89 :
F_17 ( V_2 , V_90 ,
V_91 , div ) ;
break;
case V_92 :
F_17 ( V_2 , V_93 ,
V_91 , div ) ;
break;
case V_94 :
F_17 ( V_2 , V_95 ,
V_96 , div ) ;
break;
case V_97 :
F_17 ( V_2 , V_95 ,
V_98 , div ) ;
break;
case V_99 :
F_17 ( V_2 , V_42 ,
V_100 , div ) ;
break;
default:
return - V_39 ;
}
return 0 ;
}
static int F_20 ( struct V_29 * V_81 ,
unsigned int V_101 )
{
struct V_1 * V_2 = V_81 -> V_2 ;
unsigned int V_102 , V_103 , V_104 , V_105 ;
V_102 = F_5 ( V_2 , V_70 ) ;
V_103 = F_5 ( V_2 , V_34 ) ;
V_104 = F_5 ( V_2 , V_93 ) ;
V_105 = F_5 ( V_2 , V_90 ) ;
switch ( V_101 & V_106 ) {
case V_107 :
V_102 &= ~ V_108 ;
V_104 &= ~ V_109 ;
V_105 &= ~ V_110 ;
break;
case V_111 :
V_102 &= ~ V_108 ;
V_104 |= V_109 ;
V_105 |= V_110 ;
break;
case V_112 :
V_102 |= V_108 ;
V_104 |= V_109 ;
V_105 |= V_110 ;
break;
case V_113 :
V_102 |= V_108 ;
V_104 &= ~ V_109 ;
V_105 &= ~ V_110 ;
break;
default:
return - V_39 ;
}
switch ( V_101 & V_114 ) {
case V_115 :
V_103 |= V_116 ;
V_103 &= ~ V_117 ;
break;
case V_118 :
V_103 |= V_116 ;
V_103 |= V_117 ;
break;
case V_119 :
V_103 &= ~ V_116 ;
V_103 |= 0x10 ;
break;
case V_120 :
V_103 &= ~ V_116 ;
break;
case V_121 :
V_103 &= ~ V_116 ;
V_103 |= 0x8 ;
break;
default:
return - V_39 ;
}
switch ( V_101 & V_114 ) {
case V_115 :
case V_118 :
switch ( V_101 & V_122 ) {
case V_123 :
V_103 &= ~ V_124 ;
break;
case V_125 :
V_103 |= V_124 ;
break;
default:
return - V_39 ;
}
break;
case V_119 :
case V_120 :
case V_121 :
switch ( V_101 & V_122 ) {
case V_123 :
V_103 &= ~ V_124 ;
V_103 &= ~ V_117 ;
break;
case V_126 :
V_103 |= V_124 ;
V_103 |= V_117 ;
break;
case V_125 :
V_103 |= V_124 ;
V_103 &= ~ V_117 ;
break;
case V_127 :
V_103 &= ~ V_124 ;
V_103 |= V_117 ;
break;
default:
return - V_39 ;
}
break;
default:
return - V_39 ;
}
F_3 ( V_2 , V_70 , V_102 ) ;
F_3 ( V_2 , V_34 , V_103 ) ;
F_3 ( V_2 , V_93 , V_104 ) ;
F_3 ( V_2 , V_90 , V_105 ) ;
return 0 ;
}
static int F_21 ( struct V_29 * V_81 , int V_128 )
{
struct V_1 * V_2 = V_81 -> V_2 ;
T_1 V_3 ;
V_3 = F_5 ( V_2 , V_42 ) ;
if ( V_128 )
V_3 |= V_129 ;
else
V_3 &= ~ V_129 ;
F_3 ( V_2 , V_42 , V_3 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
enum V_130 V_131 )
{
T_1 V_3 ;
switch ( V_131 ) {
case V_132 :
F_17 ( V_2 , V_133 ,
V_134 ,
V_134 ) ;
F_17 ( V_2 , V_135 ,
V_136 ,
V_136 ) ;
break;
case V_137 :
break;
case V_138 :
if ( V_2 -> V_139 . V_140 == V_141 ) {
F_3 ( V_2 , V_68 ,
V_142 ) ;
F_3 ( V_2 , V_135 ,
V_143 |
V_144 ) ;
F_3 ( V_2 , V_68 ,
V_142 | 0x1 ) ;
F_23 ( F_24 ( 400 ) ) ;
F_3 ( V_2 , V_68 ,
V_142 |
V_145 | 0x1 ) ;
F_3 ( V_2 , V_135 , 0 ) ;
F_3 ( V_2 , V_68 ,
V_145 | 0x1 ) ;
}
V_3 = F_5 ( V_2 , V_68 ) ;
F_3 ( V_2 , V_68 ,
( V_3 & V_69 ) |
V_145 | 0x1 ) ;
F_3 ( V_2 , V_146 ,
V_147 ) ;
F_3 ( V_2 , V_148 , 0 ) ;
break;
case V_141 :
V_3 = F_5 ( V_2 , V_68 ) ;
F_3 ( V_2 , V_68 ,
V_3 & V_142 ) ;
F_3 ( V_2 , V_135 ,
V_143 |
V_144 ) ;
F_3 ( V_2 , V_68 ,
V_142 ) ;
F_23 ( F_24 ( 500 ) ) ;
F_3 ( V_2 , V_14 , 0 ) ;
F_3 ( V_2 , V_135 , 0 ) ;
F_3 ( V_2 , V_68 , 0 ) ;
F_3 ( V_2 , V_146 , 0 ) ;
F_3 ( V_2 , V_148 , 0 ) ;
F_23 ( F_24 ( 1 ) ) ;
F_3 ( V_2 , V_146 ,
V_147 ) ;
break;
}
V_2 -> V_139 . V_140 = V_131 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = F_16 ( V_2 ) ;
int V_67 = V_65 -> V_67 ;
int V_66 = V_65 -> V_66 ;
int V_149 ;
V_149 = F_15 ( V_2 , 0 , 0 , 0 ) ;
if ( V_149 != 0 ) {
F_26 ( V_2 -> V_150 , L_5 ) ;
return V_149 ;
}
V_65 -> V_67 = V_67 ;
V_65 -> V_66 = V_66 ;
F_22 ( V_2 , V_141 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = F_16 ( V_2 ) ;
T_1 * V_151 ;
int V_152 , V_149 ;
V_151 = F_28 ( V_2 -> V_6 , sizeof( V_7 ) ,
V_153 ) ;
F_2 ( V_2 ) ;
F_22 ( V_2 , V_138 ) ;
if ( V_65 -> V_67 ) {
int V_67 = V_65 -> V_67 ;
int V_66 = V_65 -> V_66 ;
V_65 -> V_66 = 0 ;
V_65 -> V_67 = 0 ;
V_149 = F_15 ( V_2 , 0 , V_66 , V_67 ) ;
if ( V_149 != 0 ) {
F_26 ( V_2 -> V_150 , L_6 ) ;
F_29 ( V_151 ) ;
return V_149 ;
}
}
if ( V_151 ) {
for ( V_152 = 0 ; V_152 < V_154 ; V_152 ++ )
F_3 ( V_2 , V_152 , V_151 [ V_152 ] ) ;
F_29 ( V_151 ) ;
} else
F_26 ( V_2 -> V_150 , L_7 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = F_16 ( V_2 ) ;
int V_149 = 0 , V_3 ;
V_149 = F_31 ( V_2 , 8 , 16 , V_65 -> V_155 ) ;
if ( V_149 != 0 ) {
F_26 ( V_2 -> V_150 , L_8 , V_149 ) ;
return V_149 ;
}
V_3 = F_5 ( V_2 , V_4 ) ;
if ( V_3 != 0x8900 ) {
F_26 ( V_2 -> V_150 , L_9 , V_3 ) ;
return - V_156 ;
}
F_2 ( V_2 ) ;
F_22 ( V_2 , V_138 ) ;
F_17 ( V_2 , V_157 , 0x100 , 0x100 ) ;
F_17 ( V_2 , V_158 , 0x100 , 0x100 ) ;
F_17 ( V_2 , V_159 , 0x100 , 0x100 ) ;
F_17 ( V_2 , V_160 , 0x100 , 0x100 ) ;
F_17 ( V_2 , V_161 , 0x100 , 0x100 ) ;
F_17 ( V_2 , V_162 , 0x100 , 0x100 ) ;
F_17 ( V_2 , V_163 , 0x100 , 0x100 ) ;
F_17 ( V_2 , V_164 , 0x100 , 0x100 ) ;
F_17 ( V_2 , V_165 , 0x100 , 0x100 ) ;
F_17 ( V_2 , V_166 , 0x100 , 0x100 ) ;
F_3 ( V_2 , V_167 , 0x81 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_141 ) ;
return 0 ;
}
static int T_3 F_33 ( struct V_168 * V_169 )
{
struct V_64 * V_65 ;
int V_149 ;
V_65 = F_34 ( sizeof( struct V_64 ) , V_153 ) ;
if ( V_65 == NULL )
return - V_170 ;
V_65 -> V_155 = V_171 ;
F_35 ( V_169 , V_65 ) ;
V_149 = F_36 ( & V_169 -> V_150 ,
& V_172 , & V_173 , 1 ) ;
if ( V_149 < 0 )
F_29 ( V_65 ) ;
return V_149 ;
}
static int T_4 F_37 ( struct V_168 * V_169 )
{
F_38 ( & V_169 -> V_150 ) ;
F_29 ( F_39 ( V_169 ) ) ;
return 0 ;
}
static T_3 int F_40 ( struct V_174 * V_175 ,
const struct V_176 * V_177 )
{
struct V_64 * V_65 ;
int V_149 ;
V_65 = F_34 ( sizeof( struct V_64 ) , V_153 ) ;
if ( V_65 == NULL )
return - V_170 ;
F_41 ( V_175 , V_65 ) ;
V_65 -> V_155 = V_178 ;
V_149 = F_36 ( & V_175 -> V_150 ,
& V_172 , & V_173 , 1 ) ;
if ( V_149 < 0 )
F_29 ( V_65 ) ;
return V_149 ;
}
static T_4 int F_42 ( struct V_174 * V_179 )
{
F_38 ( & V_179 -> V_150 ) ;
F_29 ( F_43 ( V_179 ) ) ;
return 0 ;
}
static int T_5 F_44 ( void )
{
int V_149 = 0 ;
#if F_45 ( V_180 ) || F_45 ( V_181 )
V_149 = F_46 ( & V_182 ) ;
if ( V_149 != 0 ) {
F_13 ( V_54 L_10 ,
V_149 ) ;
}
#endif
#if F_45 ( V_183 )
V_149 = F_47 ( & V_184 ) ;
if ( V_149 != 0 ) {
F_13 ( V_54 L_11 ,
V_149 ) ;
}
#endif
return V_149 ;
}
static void T_6 F_48 ( void )
{
#if F_45 ( V_180 ) || F_45 ( V_181 )
F_49 ( & V_182 ) ;
#endif
#if F_45 ( V_183 )
F_50 ( & V_184 ) ;
#endif
}
