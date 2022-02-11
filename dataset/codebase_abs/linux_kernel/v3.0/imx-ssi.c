static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 , int V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_9 ;
V_9 = F_3 ( V_8 -> V_10 + V_11 ) ;
V_9 &= ~ V_12 ;
V_9 |= F_4 ( V_5 - 1 ) ;
F_5 ( V_9 , V_8 -> V_10 + V_11 ) ;
V_9 = F_3 ( V_8 -> V_10 + V_13 ) ;
V_9 &= ~ V_12 ;
V_9 |= F_4 ( V_5 - 1 ) ;
F_5 ( V_9 , V_8 -> V_10 + V_13 ) ;
F_5 ( V_3 , V_8 -> V_10 + V_14 ) ;
F_5 ( V_4 , V_8 -> V_10 + V_15 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_16 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_17 = 0 , V_18 ;
V_18 = F_3 ( V_8 -> V_10 + V_19 ) & ~ ( V_20 | V_21 ) ;
switch ( V_16 & V_22 ) {
case V_23 :
V_17 |= V_24 | V_25 | V_26 ;
V_18 |= V_21 ;
if ( V_8 -> V_27 & V_28 ) {
V_18 &= ~ V_29 ;
V_18 |= V_30 ;
}
break;
case V_31 :
V_17 |= V_26 ;
break;
case V_32 :
V_17 |= V_33 | V_26 ;
break;
case V_34 :
V_17 |= V_33 | V_25 ;
break;
}
switch ( V_16 & V_35 ) {
case V_36 :
V_17 |= V_24 ;
V_17 &= ~ V_37 ;
break;
case V_38 :
V_17 &= ~ ( V_37 | V_24 ) ;
break;
case V_39 :
V_17 |= V_24 | V_37 ;
break;
case V_40 :
V_17 &= ~ V_24 ;
V_17 |= V_37 ;
break;
}
switch ( V_16 & V_41 ) {
case V_42 :
break;
default:
return - V_43 ;
}
V_17 |= V_44 ;
if ( V_8 -> V_27 & V_45 )
V_18 |= V_21 ;
if ( V_8 -> V_27 & V_46 )
V_18 |= V_20 ;
F_5 ( V_17 , V_8 -> V_10 + V_47 ) ;
F_5 ( V_17 , V_8 -> V_10 + V_48 ) ;
F_5 ( V_18 , V_8 -> V_10 + V_19 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
int V_49 , unsigned int V_50 , int V_51 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_18 ;
V_18 = F_3 ( V_8 -> V_10 + V_19 ) ;
switch ( V_49 ) {
case V_52 :
if ( V_51 == V_53 )
V_18 |= V_54 ;
else
V_18 &= ~ V_54 ;
break;
default:
return - V_43 ;
}
F_5 ( V_18 , V_8 -> V_10 + V_19 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
int V_55 , int div )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_56 , V_57 ;
V_56 = F_3 ( V_8 -> V_10 + V_11 ) ;
V_57 = F_3 ( V_8 -> V_10 + V_13 ) ;
switch ( V_55 ) {
case V_58 :
V_56 &= ~ V_59 ;
V_56 |= div ;
break;
case V_60 :
V_56 &= ~ V_61 ;
V_56 |= div ;
break;
case V_62 :
V_56 &= ~ 0xff ;
V_56 |= F_9 ( div ) ;
break;
case V_63 :
V_56 &= ~ V_59 ;
V_56 |= div ;
break;
case V_64 :
V_56 &= ~ V_61 ;
V_56 |= div ;
break;
case V_65 :
V_56 &= ~ 0xff ;
V_56 |= F_9 ( div ) ;
break;
default:
return - V_43 ;
}
F_5 ( V_56 , V_8 -> V_10 + V_11 ) ;
F_5 ( V_57 , V_8 -> V_10 + V_13 ) ;
return 0 ;
}
static int F_10 ( struct V_66 * V_67 ,
struct V_68 * V_69 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_70 * V_71 ;
T_1 V_72 , V_9 ;
if ( V_67 -> V_73 == V_74 ) {
V_72 = V_11 ;
V_71 = & V_8 -> V_75 ;
} else {
V_72 = V_13 ;
V_71 = & V_8 -> V_76 ;
}
if ( V_8 -> V_27 & V_46 )
V_72 = V_11 ;
F_11 ( V_2 , V_67 , V_71 ) ;
V_9 = F_3 ( V_8 -> V_10 + V_72 ) & ~ V_77 ;
switch ( F_12 ( V_69 ) ) {
case V_78 :
V_9 |= F_13 ( 16 ) ;
break;
case V_79 :
V_9 |= F_13 ( 20 ) ;
break;
case V_80 :
V_9 |= F_13 ( 24 ) ;
break;
}
F_5 ( V_9 , V_8 -> V_10 + V_72 ) ;
return 0 ;
}
static int F_14 ( struct V_66 * V_67 , int V_81 ,
struct V_1 * V_82 )
{
struct V_7 * V_8 = F_2 ( V_82 ) ;
unsigned int V_83 , V_84 ;
unsigned int V_18 ;
V_18 = F_3 ( V_8 -> V_10 + V_19 ) ;
V_84 = F_3 ( V_8 -> V_10 + V_85 ) ;
if ( V_67 -> V_73 == V_74 ) {
if ( V_8 -> V_27 & V_86 )
V_83 = V_87 ;
else
V_83 = V_88 | V_89 ;
} else {
if ( V_8 -> V_27 & V_86 )
V_83 = V_90 ;
else
V_83 = V_91 | V_92 ;
}
switch ( V_81 ) {
case V_93 :
case V_94 :
case V_95 :
if ( V_67 -> V_73 == V_74 )
V_18 |= V_96 ;
else
V_18 |= V_97 ;
V_84 |= V_83 ;
if ( ++ V_8 -> V_98 == 1 )
V_18 |= V_99 ;
break;
case V_100 :
case V_101 :
case V_102 :
if ( V_67 -> V_73 == V_74 )
V_18 &= ~ V_96 ;
else
V_18 &= ~ V_97 ;
V_84 &= ~ V_83 ;
if ( -- V_8 -> V_98 == 0 )
V_18 &= ~ V_99 ;
break;
default:
return - V_43 ;
}
if ( ! ( V_8 -> V_27 & V_103 ) )
F_5 ( V_18 , V_8 -> V_10 + V_19 ) ;
F_5 ( V_84 , V_8 -> V_10 + V_85 ) ;
return 0 ;
}
int F_15 ( struct V_66 * V_67 ,
struct V_104 * V_105 )
{
struct V_106 * V_107 = V_67 -> V_107 ;
int V_108 ;
V_108 = F_16 ( NULL , V_105 , V_107 -> V_109 ,
V_107 -> V_110 , V_107 -> V_111 ) ;
F_17 ( L_1 , V_112 , V_108 ,
V_107 -> V_109 ,
V_107 -> V_110 ,
V_107 -> V_111 ) ;
return V_108 ;
}
static int F_18 ( struct V_113 * V_114 , int V_73 )
{
struct V_66 * V_67 = V_114 -> V_115 [ V_73 ] . V_67 ;
struct V_116 * V_117 = & V_67 -> V_118 ;
T_2 V_119 = V_120 ;
V_117 -> V_121 . type = V_122 ;
V_117 -> V_121 . V_121 = V_114 -> V_123 -> V_121 ;
V_117 -> V_124 = NULL ;
V_117 -> V_125 = F_19 ( V_114 -> V_123 -> V_121 , V_119 ,
& V_117 -> V_126 , V_127 ) ;
if ( ! V_117 -> V_125 )
return - V_128 ;
V_117 -> V_129 = V_119 ;
return 0 ;
}
int F_20 ( struct V_130 * V_123 , struct V_1 * V_82 ,
struct V_113 * V_114 )
{
int V_108 = 0 ;
if ( ! V_123 -> V_121 -> V_131 )
V_123 -> V_121 -> V_131 = & V_132 ;
if ( ! V_123 -> V_121 -> V_133 )
V_123 -> V_121 -> V_133 = F_21 ( 32 ) ;
if ( V_82 -> V_134 -> V_135 . V_136 ) {
V_108 = F_18 ( V_114 ,
V_74 ) ;
if ( V_108 )
goto V_137;
}
if ( V_82 -> V_134 -> V_138 . V_136 ) {
V_108 = F_18 ( V_114 ,
V_139 ) ;
if ( V_108 )
goto V_137;
}
V_137:
return V_108 ;
}
void F_22 ( struct V_113 * V_114 )
{
struct V_66 * V_67 ;
struct V_116 * V_117 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < 2 ; V_73 ++ ) {
V_67 = V_114 -> V_115 [ V_73 ] . V_67 ;
if ( ! V_67 )
continue;
V_117 = & V_67 -> V_118 ;
if ( ! V_117 -> V_125 )
continue;
F_23 ( V_114 -> V_123 -> V_121 , V_117 -> V_129 ,
V_117 -> V_125 , V_117 -> V_126 ) ;
V_117 -> V_125 = NULL ;
}
}
static int F_24 ( struct V_1 * V_82 )
{
struct V_7 * V_8 = F_25 ( V_82 -> V_121 ) ;
T_3 V_140 ;
F_26 ( V_82 , V_8 ) ;
V_140 = F_27 ( V_8 -> V_75 . V_141 ) |
F_28 ( V_8 -> V_76 . V_141 ) ;
F_5 ( V_140 , V_8 -> V_10 + V_142 ) ;
return 0 ;
}
static void F_29 ( struct V_7 * V_7 )
{
void T_4 * V_10 = V_7 -> V_10 ;
F_5 ( 0x0 , V_10 + V_19 ) ;
F_5 ( 0x0 , V_10 + V_47 ) ;
F_5 ( 0x0 , V_10 + V_48 ) ;
F_5 ( V_20 | V_21 , V_10 + V_19 ) ;
F_5 ( F_28 ( 8 ) |
F_27 ( 8 ) |
F_30 ( 8 ) |
F_31 ( 8 ) , V_10 + V_142 ) ;
F_5 ( F_32 ( 16 ) | F_4 ( 12 ) , V_10 + V_11 ) ;
F_5 ( F_32 ( 16 ) | F_4 ( 12 ) , V_10 + V_13 ) ;
F_5 ( V_20 | V_21 | V_99 , V_10 + V_19 ) ;
F_5 ( F_33 ( 3 ) , V_10 + V_143 ) ;
F_5 ( V_20 | V_21 | V_99 |
V_96 | V_97 ,
V_10 + V_19 ) ;
F_5 ( V_144 , V_10 + V_145 ) ;
F_5 ( 0xff , V_10 + V_146 ) ;
F_5 ( 0x300 , V_10 + V_147 ) ;
}
static void F_34 ( struct V_148 * V_149 , unsigned short V_72 ,
unsigned short V_140 )
{
struct V_7 * V_7 = V_150 ;
void T_4 * V_10 = V_7 -> V_10 ;
unsigned int V_151 ;
unsigned int V_152 ;
if ( V_72 > 0x7f )
return;
F_17 ( L_2 , V_112 , V_72 , V_140 ) ;
V_151 = V_72 << 12 ;
F_5 ( V_151 , V_10 + V_153 ) ;
V_152 = V_140 << 4 ;
F_5 ( V_152 , V_10 + V_154 ) ;
F_5 ( V_144 | V_155 , V_10 + V_145 ) ;
F_35 ( 100 ) ;
}
static unsigned short F_36 ( struct V_148 * V_149 ,
unsigned short V_72 )
{
struct V_7 * V_7 = V_150 ;
void T_4 * V_10 = V_7 -> V_10 ;
unsigned short V_140 = - 1 ;
unsigned int V_151 ;
V_151 = ( V_72 & 0x7f ) << 12 ;
F_5 ( V_151 , V_10 + V_153 ) ;
F_5 ( V_144 | V_156 , V_10 + V_145 ) ;
F_35 ( 100 ) ;
V_140 = ( F_3 ( V_10 + V_154 ) >> 4 ) & 0xffff ;
F_17 ( L_2 , V_112 , V_72 , V_140 ) ;
return V_140 ;
}
static void F_37 ( struct V_148 * V_149 )
{
struct V_7 * V_7 = V_150 ;
if ( V_7 -> V_157 )
V_7 -> V_157 ( V_149 ) ;
}
static void F_38 ( struct V_148 * V_149 )
{
struct V_7 * V_7 = V_150 ;
if ( V_7 -> V_158 )
V_7 -> V_158 ( V_149 ) ;
}
static int F_39 ( struct V_159 * V_160 )
{
struct V_161 * V_162 ;
struct V_7 * V_8 ;
struct V_163 * V_164 = V_160 -> V_121 . V_165 ;
int V_108 = 0 ;
struct V_166 * V_82 ;
V_8 = F_40 ( sizeof( * V_8 ) , V_127 ) ;
if ( ! V_8 )
return - V_128 ;
F_41 ( & V_160 -> V_121 , V_8 ) ;
if ( V_164 ) {
V_8 -> V_157 = V_164 -> V_157 ;
V_8 -> V_158 = V_164 -> V_158 ;
V_8 -> V_27 = V_164 -> V_27 ;
}
V_8 -> V_167 = F_42 ( V_160 , 0 ) ;
V_8 -> V_168 = F_43 ( & V_160 -> V_121 , NULL ) ;
if ( F_44 ( V_8 -> V_168 ) ) {
V_108 = F_45 ( V_8 -> V_168 ) ;
F_46 ( & V_160 -> V_121 , L_3 ,
V_108 ) ;
goto V_169;
}
F_47 ( V_8 -> V_168 ) ;
V_162 = F_48 ( V_160 , V_170 , 0 ) ;
if ( ! V_162 ) {
V_108 = - V_171 ;
goto V_172;
}
if ( ! F_49 ( V_162 -> V_173 , F_50 ( V_162 ) , V_174 ) ) {
F_46 ( & V_160 -> V_121 , L_4 ) ;
V_108 = - V_175 ;
goto V_172;
}
V_8 -> V_10 = F_51 ( V_162 -> V_173 , F_50 ( V_162 ) ) ;
if ( ! V_8 -> V_10 ) {
F_46 ( & V_160 -> V_121 , L_5 ) ;
V_108 = - V_171 ;
goto V_176;
}
if ( V_8 -> V_27 & V_103 ) {
if ( V_150 ) {
V_108 = - V_175 ;
goto V_177;
}
V_150 = V_8 ;
F_29 ( V_8 ) ;
V_82 = & V_178 ;
} else
V_82 = & V_179 ;
F_5 ( 0x0 , V_8 -> V_10 + V_85 ) ;
V_8 -> V_76 . V_110 = V_162 -> V_173 + V_180 ;
V_8 -> V_75 . V_110 = V_162 -> V_173 + V_181 ;
V_8 -> V_75 . V_141 = 4 ;
V_8 -> V_76 . V_141 = 4 ;
V_162 = F_52 ( V_160 , V_182 , L_6 ) ;
if ( V_162 )
V_8 -> V_75 . V_183 = V_162 -> V_173 ;
V_162 = F_52 ( V_160 , V_182 , L_7 ) ;
if ( V_162 )
V_8 -> V_76 . V_183 = V_162 -> V_173 ;
F_53 ( V_160 , V_8 ) ;
V_108 = F_54 ( & V_160 -> V_121 , V_82 ) ;
if ( V_108 ) {
F_46 ( & V_160 -> V_121 , L_8 ) ;
goto V_184;
}
V_8 -> V_185 = F_55 ( L_9 , V_160 -> V_186 ) ;
if ( ! V_8 -> V_185 ) {
V_108 = - V_128 ;
goto V_187;
}
F_53 ( V_8 -> V_185 , V_8 ) ;
V_108 = F_56 ( V_8 -> V_185 ) ;
if ( V_108 ) {
F_46 ( & V_160 -> V_121 , L_10 ) ;
goto V_188;
}
V_8 -> V_189 = F_55 ( L_11 , V_160 -> V_186 ) ;
if ( ! V_8 -> V_189 ) {
V_108 = - V_128 ;
goto V_190;
}
F_53 ( V_8 -> V_189 , V_8 ) ;
V_108 = F_56 ( V_8 -> V_189 ) ;
if ( V_108 ) {
F_46 ( & V_160 -> V_121 , L_10 ) ;
goto V_191;
}
return 0 ;
V_191:
F_57 ( V_8 -> V_189 ) ;
V_190:
F_58 ( V_8 -> V_185 ) ;
V_188:
F_57 ( V_8 -> V_185 ) ;
V_187:
F_59 ( & V_160 -> V_121 ) ;
V_184:
V_177:
F_60 ( V_8 -> V_10 ) ;
V_176:
F_61 ( V_162 -> V_173 , F_50 ( V_162 ) ) ;
V_172:
F_62 ( V_8 -> V_168 ) ;
F_63 ( V_8 -> V_168 ) ;
V_169:
F_64 ( V_8 ) ;
return V_108 ;
}
static int T_5 F_65 ( struct V_159 * V_160 )
{
struct V_161 * V_162 = F_48 ( V_160 , V_170 , 0 ) ;
struct V_7 * V_8 = F_66 ( V_160 ) ;
F_67 ( V_8 -> V_189 ) ;
F_67 ( V_8 -> V_185 ) ;
F_59 ( & V_160 -> V_121 ) ;
if ( V_8 -> V_27 & V_103 )
V_150 = NULL ;
F_60 ( V_8 -> V_10 ) ;
F_61 ( V_162 -> V_173 , F_50 ( V_162 ) ) ;
F_62 ( V_8 -> V_168 ) ;
F_63 ( V_8 -> V_168 ) ;
F_64 ( V_8 ) ;
return 0 ;
}
static int T_6 F_68 ( void )
{
return F_69 ( & V_192 ) ;
}
static void T_7 F_70 ( void )
{
F_71 ( & V_192 ) ;
}
