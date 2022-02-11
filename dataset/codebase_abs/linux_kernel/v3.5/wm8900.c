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
struct V_1 * V_2 = V_30 -> V_2 ;
T_1 V_3 ;
V_3 = F_5 ( V_2 , V_31 ) & ~ 0x60 ;
switch ( F_9 ( V_28 ) ) {
case V_32 :
break;
case V_33 :
V_3 |= 0x20 ;
break;
case V_34 :
V_3 |= 0x40 ;
break;
case V_35 :
V_3 |= 0x60 ;
break;
default:
return - V_36 ;
}
F_3 ( V_2 , V_31 , V_3 ) ;
if ( V_26 -> V_37 == V_38 ) {
V_3 = F_5 ( V_2 , V_39 ) ;
if ( F_10 ( V_28 ) <= 24000 )
V_3 |= V_40 ;
else
V_3 &= ~ V_40 ;
F_3 ( V_2 , V_39 , V_3 ) ;
}
return 0 ;
}
static int F_11 ( struct V_41 * V_42 , unsigned int V_43 ,
unsigned int V_44 )
{
T_2 V_45 ;
unsigned int V_46 , V_47 , V_48 , V_49 ;
unsigned int div ;
F_12 ( ! V_44 ) ;
V_49 = V_44 ;
div = 1 ;
while ( V_49 < 90000000 ) {
div *= 2 ;
V_49 *= 2 ;
}
if ( V_49 > 100000000 )
F_13 ( V_50 L_1
L_2 , V_49 , V_43 , V_44 ) ;
if ( div > 32 ) {
F_13 ( V_51 L_3
L_4 ,
div , V_43 , V_44 , V_49 ) ;
return - V_36 ;
}
V_42 -> V_52 = div >> 2 ;
if ( V_43 < 48000 )
V_42 -> V_53 = 1 ;
else
V_42 -> V_53 = 0 ;
V_47 = V_49 / V_43 ;
if ( V_43 < 1000000 )
V_42 -> V_54 = 8 ;
else
V_42 -> V_54 = 1 ;
V_42 -> V_55 = V_47 / V_42 -> V_54 ;
V_48 = ( V_49 / V_42 -> V_54 ) % V_43 ;
V_45 = V_56 * ( long long ) V_48 ;
F_14 ( V_45 , V_43 ) ;
V_46 = V_45 & 0xFFFFFFFF ;
if ( ( V_46 % 10 ) >= 5 )
V_46 += 5 ;
V_42 -> V_57 = V_46 / 10 ;
F_12 ( V_49 != V_44 * ( V_42 -> V_52 << 2 ) ) ;
F_12 ( ! V_46 && V_49 != V_43 * V_42 -> V_54 * V_42 -> V_55 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
int V_58 , unsigned int V_59 , unsigned int V_60 )
{
struct V_61 * V_62 = F_16 ( V_2 ) ;
struct V_41 V_42 ;
if ( V_62 -> V_63 == V_59 && V_62 -> V_64 == V_60 )
return 0 ;
F_17 ( V_2 , V_65 ,
V_66 , 0 ) ;
if ( ! V_59 || ! V_60 ) {
F_17 ( V_2 , V_67 ,
V_68 , 0 ) ;
F_17 ( V_2 , V_69 ,
V_70 , 0 ) ;
V_62 -> V_63 = V_59 ;
V_62 -> V_64 = V_60 ;
return 0 ;
}
if ( F_11 ( & V_42 , V_59 , V_60 ) != 0 )
goto V_71;
V_62 -> V_63 = V_59 ;
V_62 -> V_64 = V_60 ;
F_3 ( V_2 , V_69 ,
V_42 . V_54 | V_70 ) ;
F_3 ( V_2 , V_72 , V_42 . V_55 >> 5 ) ;
F_3 ( V_2 , V_73 ,
( V_42 . V_52 << 6 ) | ( V_42 . V_55 & 0x1f ) ) ;
if ( V_42 . V_57 ) {
F_3 ( V_2 , V_74 ,
( V_42 . V_57 >> 8 ) | 0x100 ) ;
F_3 ( V_2 , V_75 , V_42 . V_57 & 0xff ) ;
} else
F_3 ( V_2 , V_74 , 0 ) ;
if ( V_42 . V_53 )
F_3 ( V_2 , V_76 ,
V_77 ) ;
else
F_3 ( V_2 , V_76 , 0 ) ;
F_17 ( V_2 , V_65 ,
V_66 ,
V_66 ) ;
V_71:
F_17 ( V_2 , V_67 ,
V_68 ,
V_68 ) ;
return 0 ;
}
static int F_18 ( struct V_29 * V_78 , int V_79 ,
int V_80 , unsigned int V_59 , unsigned int V_60 )
{
return F_15 ( V_78 -> V_2 , V_79 , V_59 , V_60 ) ;
}
static int F_19 ( struct V_29 * V_78 ,
int V_81 , int div )
{
struct V_1 * V_2 = V_78 -> V_2 ;
switch ( V_81 ) {
case V_82 :
F_17 ( V_2 , V_67 ,
V_83 , div ) ;
break;
case V_84 :
F_17 ( V_2 , V_67 ,
V_85 , div ) ;
break;
case V_86 :
F_17 ( V_2 , V_87 ,
V_88 , div ) ;
break;
case V_89 :
F_17 ( V_2 , V_90 ,
V_88 , div ) ;
break;
case V_91 :
F_17 ( V_2 , V_92 ,
V_93 , div ) ;
break;
case V_94 :
F_17 ( V_2 , V_92 ,
V_95 , div ) ;
break;
case V_96 :
F_17 ( V_2 , V_39 ,
V_97 , div ) ;
break;
default:
return - V_36 ;
}
return 0 ;
}
static int F_20 ( struct V_29 * V_78 ,
unsigned int V_98 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
unsigned int V_99 , V_100 , V_101 , V_102 ;
V_99 = F_5 ( V_2 , V_67 ) ;
V_100 = F_5 ( V_2 , V_31 ) ;
V_101 = F_5 ( V_2 , V_90 ) ;
V_102 = F_5 ( V_2 , V_87 ) ;
switch ( V_98 & V_103 ) {
case V_104 :
V_99 &= ~ V_105 ;
V_101 &= ~ V_106 ;
V_102 &= ~ V_107 ;
break;
case V_108 :
V_99 &= ~ V_105 ;
V_101 |= V_106 ;
V_102 |= V_107 ;
break;
case V_109 :
V_99 |= V_105 ;
V_101 |= V_106 ;
V_102 |= V_107 ;
break;
case V_110 :
V_99 |= V_105 ;
V_101 &= ~ V_106 ;
V_102 &= ~ V_107 ;
break;
default:
return - V_36 ;
}
switch ( V_98 & V_111 ) {
case V_112 :
V_100 |= V_113 ;
V_100 &= ~ V_114 ;
break;
case V_115 :
V_100 |= V_113 ;
V_100 |= V_114 ;
break;
case V_116 :
V_100 &= ~ V_113 ;
V_100 |= 0x10 ;
break;
case V_117 :
V_100 &= ~ V_113 ;
break;
case V_118 :
V_100 &= ~ V_113 ;
V_100 |= 0x8 ;
break;
default:
return - V_36 ;
}
switch ( V_98 & V_111 ) {
case V_112 :
case V_115 :
switch ( V_98 & V_119 ) {
case V_120 :
V_100 &= ~ V_121 ;
break;
case V_122 :
V_100 |= V_121 ;
break;
default:
return - V_36 ;
}
break;
case V_116 :
case V_117 :
case V_118 :
switch ( V_98 & V_119 ) {
case V_120 :
V_100 &= ~ V_121 ;
V_100 &= ~ V_114 ;
break;
case V_123 :
V_100 |= V_121 ;
V_100 |= V_114 ;
break;
case V_122 :
V_100 |= V_121 ;
V_100 &= ~ V_114 ;
break;
case V_124 :
V_100 &= ~ V_121 ;
V_100 |= V_114 ;
break;
default:
return - V_36 ;
}
break;
default:
return - V_36 ;
}
F_3 ( V_2 , V_67 , V_99 ) ;
F_3 ( V_2 , V_31 , V_100 ) ;
F_3 ( V_2 , V_90 , V_101 ) ;
F_3 ( V_2 , V_87 , V_102 ) ;
return 0 ;
}
static int F_21 ( struct V_29 * V_78 , int V_125 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
T_1 V_3 ;
V_3 = F_5 ( V_2 , V_39 ) ;
if ( V_125 )
V_3 |= V_126 ;
else
V_3 &= ~ V_126 ;
F_3 ( V_2 , V_39 , V_3 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
enum V_127 V_128 )
{
T_1 V_3 ;
switch ( V_128 ) {
case V_129 :
F_17 ( V_2 , V_130 ,
V_131 ,
V_131 ) ;
F_17 ( V_2 , V_132 ,
V_133 ,
V_133 ) ;
break;
case V_134 :
break;
case V_135 :
if ( V_2 -> V_136 . V_137 == V_138 ) {
F_3 ( V_2 , V_65 ,
V_139 ) ;
F_3 ( V_2 , V_132 ,
V_140 |
V_141 ) ;
F_3 ( V_2 , V_65 ,
V_139 | 0x1 ) ;
F_23 ( F_24 ( 400 ) ) ;
F_3 ( V_2 , V_65 ,
V_139 |
V_142 | 0x1 ) ;
F_3 ( V_2 , V_132 , 0 ) ;
F_3 ( V_2 , V_65 ,
V_142 | 0x1 ) ;
}
V_3 = F_5 ( V_2 , V_65 ) ;
F_3 ( V_2 , V_65 ,
( V_3 & V_66 ) |
V_142 | 0x1 ) ;
F_3 ( V_2 , V_143 ,
V_144 ) ;
F_3 ( V_2 , V_145 , 0 ) ;
break;
case V_138 :
V_3 = F_5 ( V_2 , V_65 ) ;
F_3 ( V_2 , V_65 ,
V_3 & V_139 ) ;
F_3 ( V_2 , V_132 ,
V_140 |
V_141 ) ;
F_3 ( V_2 , V_65 ,
V_139 ) ;
F_23 ( F_24 ( 500 ) ) ;
F_3 ( V_2 , V_14 , 0 ) ;
F_3 ( V_2 , V_132 , 0 ) ;
F_3 ( V_2 , V_65 , 0 ) ;
F_3 ( V_2 , V_143 , 0 ) ;
F_3 ( V_2 , V_145 , 0 ) ;
F_23 ( F_24 ( 1 ) ) ;
F_3 ( V_2 , V_143 ,
V_144 ) ;
break;
}
V_2 -> V_136 . V_137 = V_128 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = F_16 ( V_2 ) ;
int V_64 = V_62 -> V_64 ;
int V_63 = V_62 -> V_63 ;
int V_146 ;
V_146 = F_15 ( V_2 , 0 , 0 , 0 ) ;
if ( V_146 != 0 ) {
F_26 ( V_2 -> V_147 , L_5 ) ;
return V_146 ;
}
V_62 -> V_64 = V_64 ;
V_62 -> V_63 = V_63 ;
F_22 ( V_2 , V_138 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = F_16 ( V_2 ) ;
T_1 * V_148 ;
int V_149 , V_146 ;
V_148 = F_28 ( V_2 -> V_6 , sizeof( V_7 ) ,
V_150 ) ;
F_2 ( V_2 ) ;
F_22 ( V_2 , V_135 ) ;
if ( V_62 -> V_64 ) {
int V_64 = V_62 -> V_64 ;
int V_63 = V_62 -> V_63 ;
V_62 -> V_63 = 0 ;
V_62 -> V_64 = 0 ;
V_146 = F_15 ( V_2 , 0 , V_63 , V_64 ) ;
if ( V_146 != 0 ) {
F_26 ( V_2 -> V_147 , L_6 ) ;
F_29 ( V_148 ) ;
return V_146 ;
}
}
if ( V_148 ) {
for ( V_149 = 0 ; V_149 < V_151 ; V_149 ++ )
F_3 ( V_2 , V_149 , V_148 [ V_149 ] ) ;
F_29 ( V_148 ) ;
} else
F_26 ( V_2 -> V_147 , L_7 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = F_16 ( V_2 ) ;
int V_146 = 0 , V_3 ;
V_146 = F_31 ( V_2 , 8 , 16 , V_62 -> V_152 ) ;
if ( V_146 != 0 ) {
F_26 ( V_2 -> V_147 , L_8 , V_146 ) ;
return V_146 ;
}
V_3 = F_5 ( V_2 , V_4 ) ;
if ( V_3 != 0x8900 ) {
F_26 ( V_2 -> V_147 , L_9 , V_3 ) ;
return - V_153 ;
}
F_2 ( V_2 ) ;
F_22 ( V_2 , V_135 ) ;
F_17 ( V_2 , V_154 , 0x100 , 0x100 ) ;
F_17 ( V_2 , V_155 , 0x100 , 0x100 ) ;
F_17 ( V_2 , V_156 , 0x100 , 0x100 ) ;
F_17 ( V_2 , V_157 , 0x100 , 0x100 ) ;
F_17 ( V_2 , V_158 , 0x100 , 0x100 ) ;
F_17 ( V_2 , V_159 , 0x100 , 0x100 ) ;
F_17 ( V_2 , V_160 , 0x100 , 0x100 ) ;
F_17 ( V_2 , V_161 , 0x100 , 0x100 ) ;
F_17 ( V_2 , V_162 , 0x100 , 0x100 ) ;
F_17 ( V_2 , V_163 , 0x100 , 0x100 ) ;
F_3 ( V_2 , V_164 , 0x81 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_138 ) ;
return 0 ;
}
static int T_3 F_33 ( struct V_165 * V_166 )
{
struct V_61 * V_62 ;
int V_146 ;
V_62 = F_34 ( sizeof( struct V_61 ) , V_150 ) ;
if ( V_62 == NULL )
return - V_167 ;
V_62 -> V_152 = V_168 ;
F_35 ( V_166 , V_62 ) ;
V_146 = F_36 ( & V_166 -> V_147 ,
& V_169 , & V_170 , 1 ) ;
if ( V_146 < 0 )
F_29 ( V_62 ) ;
return V_146 ;
}
static int T_4 F_37 ( struct V_165 * V_166 )
{
F_38 ( & V_166 -> V_147 ) ;
F_29 ( F_39 ( V_166 ) ) ;
return 0 ;
}
static T_3 int F_40 ( struct V_171 * V_172 ,
const struct V_173 * V_174 )
{
struct V_61 * V_62 ;
int V_146 ;
V_62 = F_34 ( sizeof( struct V_61 ) , V_150 ) ;
if ( V_62 == NULL )
return - V_167 ;
F_41 ( V_172 , V_62 ) ;
V_62 -> V_152 = V_175 ;
V_146 = F_36 ( & V_172 -> V_147 ,
& V_169 , & V_170 , 1 ) ;
if ( V_146 < 0 )
F_29 ( V_62 ) ;
return V_146 ;
}
static T_4 int F_42 ( struct V_171 * V_176 )
{
F_38 ( & V_176 -> V_147 ) ;
F_29 ( F_43 ( V_176 ) ) ;
return 0 ;
}
static int T_5 F_44 ( void )
{
int V_146 = 0 ;
#if F_45 ( V_177 ) || F_45 ( V_178 )
V_146 = F_46 ( & V_179 ) ;
if ( V_146 != 0 ) {
F_13 ( V_51 L_10 ,
V_146 ) ;
}
#endif
#if F_45 ( V_180 )
V_146 = F_47 ( & V_181 ) ;
if ( V_146 != 0 ) {
F_13 ( V_51 L_11 ,
V_146 ) ;
}
#endif
return V_146 ;
}
static void T_6 F_48 ( void )
{
#if F_45 ( V_177 ) || F_45 ( V_178 )
F_49 ( & V_179 ) ;
#endif
#if F_45 ( V_180 )
F_50 ( & V_181 ) ;
#endif
}
