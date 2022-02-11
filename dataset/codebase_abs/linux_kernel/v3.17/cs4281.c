static inline void F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned int V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline unsigned int F_3 ( struct V_1 * V_2 , unsigned long V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_6 * V_7 ,
unsigned short V_8 , unsigned short V_4 )
{
struct V_1 * V_2 = V_7 -> V_9 ;
int V_10 ;
F_1 ( V_2 , V_11 , V_8 ) ;
F_1 ( V_2 , V_12 , V_4 ) ;
F_1 ( V_2 , V_13 , V_14 | V_15 |
V_16 | ( V_7 -> V_17 ? V_18 : 0 ) ) ;
for ( V_10 = 0 ; V_10 < 2000 ; V_10 ++ ) {
F_6 ( 10 ) ;
if ( ! ( F_3 ( V_2 , V_13 ) & V_14 ) ) {
return;
}
}
F_7 ( V_2 -> V_19 -> V_20 ,
L_1 , V_8 , V_4 ) ;
}
static unsigned short F_8 ( struct V_6 * V_7 ,
unsigned short V_8 )
{
struct V_1 * V_2 = V_7 -> V_9 ;
int V_10 ;
unsigned short V_21 ;
volatile int V_22 = ( ( volatile struct V_6 * ) V_7 ) -> V_17 ;
F_3 ( V_2 , V_22 ? V_23 : V_24 ) ;
F_1 ( V_2 , V_11 , V_8 ) ;
F_1 ( V_2 , V_12 , 0 ) ;
F_1 ( V_2 , V_13 , V_14 | V_25 |
V_15 | V_16 |
( V_22 ? V_18 : 0 ) ) ;
for ( V_10 = 0 ; V_10 < 500 ; V_10 ++ ) {
F_6 ( 10 ) ;
if ( ! ( F_3 ( V_2 , V_13 ) & V_14 ) )
goto V_26;
}
F_7 ( V_2 -> V_19 -> V_20 ,
L_2 , V_8 ) ;
V_21 = 0xffff ;
goto V_27;
V_26:
for ( V_10 = 0 ; V_10 < 100 ; V_10 ++ ) {
if ( F_3 ( V_2 , V_22 ? V_28 : V_29 ) & V_30 )
goto V_31;
F_6 ( 10 ) ;
}
F_7 ( V_2 -> V_19 -> V_20 ,
L_3 , V_8 ) ;
V_21 = 0xffff ;
goto V_27;
V_31:
V_21 = F_3 ( V_2 , V_22 ? V_23 : V_24 ) ;
V_27:
return V_21 ;
}
static int F_9 ( struct V_32 * V_33 , int V_34 )
{
struct V_35 * V_36 = V_33 -> V_37 -> V_9 ;
struct V_1 * V_2 = F_10 ( V_33 ) ;
F_11 ( & V_2 -> V_38 ) ;
switch ( V_34 ) {
case V_39 :
V_36 -> V_40 |= V_41 ;
V_36 -> V_42 |= V_43 ;
break;
case V_44 :
V_36 -> V_40 &= ~ V_41 ;
V_36 -> V_42 &= ~ V_43 ;
break;
case V_45 :
case V_46 :
F_1 ( V_2 , V_36 -> V_47 , V_36 -> V_48 & ~ V_49 ) ;
V_36 -> V_48 |= V_49 ;
V_36 -> V_40 &= ~ V_41 ;
V_36 -> V_42 |= V_43 ;
break;
case V_50 :
case V_51 :
V_36 -> V_48 &= ~ ( V_49 | V_52 ) ;
V_36 -> V_40 |= V_41 ;
V_36 -> V_42 &= ~ V_43 ;
if ( V_36 -> V_53 != V_54 )
V_36 -> V_42 &= ~ V_43 ;
break;
default:
F_12 ( & V_2 -> V_38 ) ;
return - V_55 ;
}
F_1 ( V_2 , V_36 -> V_47 , V_36 -> V_48 ) ;
F_1 ( V_2 , V_36 -> V_53 , V_36 -> V_42 ) ;
F_1 ( V_2 , V_36 -> V_56 , V_36 -> V_40 ) ;
F_12 ( & V_2 -> V_38 ) ;
return 0 ;
}
static unsigned int F_13 ( unsigned int V_57 , unsigned int * V_58 )
{
unsigned int V_4 = ~ 0 ;
if ( V_58 )
* V_58 = V_57 ;
switch ( V_57 ) {
case 8000 : return 5 ;
case 11025 : return 4 ;
case 16000 : return 3 ;
case 22050 : return 2 ;
case 44100 : return 1 ;
case 48000 : return 0 ;
default:
goto V_59;
}
V_59:
V_4 = 1536000 / V_57 ;
if ( V_58 )
* V_58 = 1536000 / V_4 ;
return V_4 ;
}
static void F_14 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_60 * V_37 ,
int V_61 , int V_62 )
{
int V_63 ;
V_36 -> V_48 = V_64 | V_65 |
( V_61 ? V_66 : V_67 ) ;
if ( V_37 -> V_68 == 1 )
V_36 -> V_48 |= V_69 ;
if ( F_15 ( V_37 -> V_70 ) > 0 )
V_36 -> V_48 |= V_71 ;
if ( F_16 ( V_37 -> V_70 ) > 0 )
V_36 -> V_48 |= V_72 ;
switch ( F_17 ( V_37 -> V_70 ) ) {
case 8 : V_36 -> V_48 |= V_73 ;
if ( V_37 -> V_68 == 1 )
V_36 -> V_48 |= V_74 ;
break;
case 32 : V_36 -> V_48 |= V_75 ; break;
}
V_36 -> V_76 = 0 ;
V_36 -> V_40 = V_77 | V_41 ;
if ( V_37 -> V_78 != V_37 -> V_79 )
V_36 -> V_40 |= V_80 ;
F_1 ( V_2 , V_36 -> V_81 , V_37 -> V_82 ) ;
F_1 ( V_2 , V_36 -> V_83 , V_37 -> V_78 - 1 ) ;
V_63 = ( V_2 -> V_36 [ 1 ] . V_48 & V_69 ) == V_69 ;
F_1 ( V_2 , V_84 , ( V_2 -> V_85 << 0 ) |
( V_2 -> V_86 << 8 ) |
( V_2 -> V_87 << 16 ) |
( ( V_63 ? 31 : V_2 -> V_88 ) << 24 ) ) ;
if ( ! V_62 )
goto V_89;
if ( ! V_61 ) {
if ( V_36 -> V_90 == V_2 -> V_85 ) {
unsigned int V_4 = F_13 ( V_37 -> V_57 , NULL ) ;
F_18 ( V_36 -> V_91 != V_2 -> V_86 ) ;
F_1 ( V_2 , V_92 , V_4 ) ;
}
} else {
if ( V_36 -> V_90 == V_2 -> V_87 ) {
unsigned int V_4 = F_13 ( V_37 -> V_57 , NULL ) ;
F_18 ( V_36 -> V_91 != V_2 -> V_88 ) ;
F_1 ( V_2 , V_93 , V_4 ) ;
}
}
V_89:
if ( V_36 -> V_53 == V_54 )
F_1 ( V_2 , V_36 -> V_53 , F_3 ( V_2 , V_36 -> V_53 ) & ~ V_43 ) ;
V_36 -> V_42 = F_19 ( V_36 -> V_90 ) |
F_20 ( V_61 && ( V_36 -> V_48 & V_69 ) ? 31 : V_36 -> V_91 ) |
F_21 ( V_94 ) |
F_22 ( V_36 -> V_95 ) ;
F_1 ( V_2 , V_36 -> V_53 , V_36 -> V_42 | ( V_61 ? V_96 : 0 ) ) ;
if ( V_36 -> V_53 == V_54 )
F_1 ( V_2 , V_36 -> V_53 , V_36 -> V_42 | V_43 ) ;
F_1 ( V_2 , V_36 -> V_97 , 0 ) ;
}
static int F_23 ( struct V_32 * V_33 ,
struct V_98 * V_99 )
{
return F_24 ( V_33 , F_25 ( V_99 ) ) ;
}
static int F_26 ( struct V_32 * V_33 )
{
return F_27 ( V_33 ) ;
}
static int F_28 ( struct V_32 * V_33 )
{
struct V_60 * V_37 = V_33 -> V_37 ;
struct V_35 * V_36 = V_37 -> V_9 ;
struct V_1 * V_2 = F_10 ( V_33 ) ;
F_29 ( & V_2 -> V_38 ) ;
F_14 ( V_2 , V_36 , V_37 , 0 , 1 ) ;
F_30 ( & V_2 -> V_38 ) ;
return 0 ;
}
static int F_31 ( struct V_32 * V_33 )
{
struct V_60 * V_37 = V_33 -> V_37 ;
struct V_35 * V_36 = V_37 -> V_9 ;
struct V_1 * V_2 = F_10 ( V_33 ) ;
F_29 ( & V_2 -> V_38 ) ;
F_14 ( V_2 , V_36 , V_37 , 1 , 1 ) ;
F_30 ( & V_2 -> V_38 ) ;
return 0 ;
}
static T_1 F_32 ( struct V_32 * V_33 )
{
struct V_60 * V_37 = V_33 -> V_37 ;
struct V_35 * V_36 = V_37 -> V_9 ;
struct V_1 * V_2 = F_10 ( V_33 ) ;
return V_37 -> V_78 -
F_3 ( V_2 , V_36 -> V_100 ) - 1 ;
}
static int F_33 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_10 ( V_33 ) ;
struct V_60 * V_37 = V_33 -> V_37 ;
struct V_35 * V_36 ;
V_36 = & V_2 -> V_36 [ 0 ] ;
V_36 -> V_33 = V_33 ;
V_36 -> V_90 = 0 ;
V_36 -> V_91 = 1 ;
V_37 -> V_9 = V_36 ;
V_37 -> V_101 = V_102 ;
F_34 ( V_37 , 0 , 32 , 20 ) ;
return 0 ;
}
static int F_35 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_10 ( V_33 ) ;
struct V_60 * V_37 = V_33 -> V_37 ;
struct V_35 * V_36 ;
V_36 = & V_2 -> V_36 [ 1 ] ;
V_36 -> V_33 = V_33 ;
V_36 -> V_90 = 10 ;
V_36 -> V_91 = 11 ;
V_37 -> V_9 = V_36 ;
V_37 -> V_101 = V_103 ;
F_34 ( V_37 , 0 , 32 , 20 ) ;
return 0 ;
}
static int F_36 ( struct V_32 * V_33 )
{
struct V_35 * V_36 = V_33 -> V_37 -> V_9 ;
V_36 -> V_33 = NULL ;
return 0 ;
}
static int F_37 ( struct V_32 * V_33 )
{
struct V_35 * V_36 = V_33 -> V_37 -> V_9 ;
V_36 -> V_33 = NULL ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , int V_104 ,
struct V_105 * * V_106 )
{
struct V_105 * V_107 ;
int V_108 ;
if ( V_106 )
* V_106 = NULL ;
V_108 = F_39 ( V_2 -> V_19 , L_4 , V_104 , 1 , 1 , & V_107 ) ;
if ( V_108 < 0 )
return V_108 ;
F_40 ( V_107 , V_109 , & V_110 ) ;
F_40 ( V_107 , V_111 , & V_112 ) ;
V_107 -> V_9 = V_2 ;
V_107 -> V_113 = 0 ;
strcpy ( V_107 -> V_114 , L_4 ) ;
V_2 -> V_107 = V_107 ;
F_41 ( V_107 , V_115 ,
F_42 ( V_2 -> V_116 ) , 64 * 1024 , 512 * 1024 ) ;
if ( V_106 )
* V_106 = V_107 ;
return 0 ;
}
static int F_43 ( struct V_117 * V_118 ,
struct V_119 * V_120 )
{
V_120 -> type = V_121 ;
V_120 -> V_10 = 2 ;
V_120 -> V_122 . integer . V_123 = 0 ;
V_120 -> V_122 . integer . V_124 = V_125 ;
return 0 ;
}
static int F_44 ( struct V_117 * V_118 ,
struct V_126 * V_127 )
{
struct V_1 * V_2 = F_45 ( V_118 ) ;
int V_128 = ( V_118 -> V_129 >> 16 ) & 0xffff ;
int V_130 = V_118 -> V_129 & 0xffff ;
int V_131 , V_132 ;
V_131 = V_125 - ( F_3 ( V_2 , V_128 ) & V_125 ) ;
V_132 = V_125 - ( F_3 ( V_2 , V_130 ) & V_125 ) ;
V_127 -> V_122 . integer . V_122 [ 0 ] = V_131 ;
V_127 -> V_122 . integer . V_122 [ 1 ] = V_132 ;
return 0 ;
}
static int F_46 ( struct V_117 * V_118 ,
struct V_126 * V_127 )
{
struct V_1 * V_2 = F_45 ( V_118 ) ;
int V_133 = 0 ;
int V_128 = ( V_118 -> V_129 >> 16 ) & 0xffff ;
int V_130 = V_118 -> V_129 & 0xffff ;
int V_131 , V_132 ;
V_131 = V_125 - ( F_3 ( V_2 , V_128 ) & V_125 ) ;
V_132 = V_125 - ( F_3 ( V_2 , V_130 ) & V_125 ) ;
if ( V_127 -> V_122 . integer . V_122 [ 0 ] != V_131 ) {
V_131 = V_125 - ( V_127 -> V_122 . integer . V_122 [ 0 ] & V_125 ) ;
F_1 ( V_2 , V_128 , V_131 ) ;
V_133 = 1 ;
}
if ( V_127 -> V_122 . integer . V_122 [ 1 ] != V_132 ) {
V_132 = V_125 - ( V_127 -> V_122 . integer . V_122 [ 1 ] & V_125 ) ;
F_1 ( V_2 , V_130 , V_132 ) ;
V_133 = 1 ;
}
return V_133 ;
}
static void F_47 ( struct V_134 * V_135 )
{
struct V_1 * V_2 = V_135 -> V_9 ;
V_2 -> V_136 = NULL ;
}
static void F_48 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_9 ;
if ( V_7 -> V_17 )
V_2 -> V_137 = NULL ;
else
V_2 -> V_7 = NULL ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_138 * V_19 = V_2 -> V_19 ;
struct V_139 V_7 ;
int V_108 ;
static struct V_140 V_141 = {
. V_142 = F_5 ,
. V_143 = F_8 ,
} ;
if ( ( V_108 = V_134 ( V_19 , 0 , & V_141 , V_2 , & V_2 -> V_136 ) ) < 0 )
return V_108 ;
V_2 -> V_136 -> V_144 = F_47 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_9 = V_2 ;
V_7 . V_144 = F_48 ;
if ( ( V_108 = F_50 ( V_2 -> V_136 , & V_7 , & V_2 -> V_7 ) ) < 0 )
return V_108 ;
if ( V_2 -> V_145 ) {
V_7 . V_17 = 1 ;
if ( ( V_108 = F_50 ( V_2 -> V_136 , & V_7 , & V_2 -> V_137 ) ) < 0 )
return V_108 ;
}
if ( ( V_108 = F_51 ( V_19 , F_52 ( & V_146 , V_2 ) ) ) < 0 )
return V_108 ;
if ( ( V_108 = F_51 ( V_19 , F_52 ( & V_147 , V_2 ) ) ) < 0 )
return V_108 ;
return 0 ;
}
static void F_53 ( struct V_148 * V_149 ,
struct V_150 * V_151 )
{
struct V_1 * V_2 = V_149 -> V_9 ;
F_54 ( V_151 , L_5 ) ;
F_54 ( V_151 , L_6 , V_2 -> V_152 ) ;
F_54 ( V_151 , L_7 , V_2 -> V_153 ) ;
}
static T_2 F_55 ( struct V_148 * V_149 ,
void * V_154 ,
struct V_155 * V_155 , char T_3 * V_156 ,
T_4 V_10 , T_5 V_157 )
{
struct V_1 * V_2 = V_149 -> V_9 ;
if ( F_56 ( V_156 , V_2 -> V_5 + V_157 , V_10 ) )
return - V_158 ;
return V_10 ;
}
static T_2 F_57 ( struct V_148 * V_149 ,
void * V_154 ,
struct V_155 * V_155 , char T_3 * V_156 ,
T_4 V_10 , T_5 V_157 )
{
struct V_1 * V_2 = V_149 -> V_9 ;
if ( F_56 ( V_156 , V_2 -> V_159 + V_157 , V_10 ) )
return - V_158 ;
return V_10 ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_148 * V_149 ;
if ( ! F_59 ( V_2 -> V_19 , L_8 , & V_149 ) )
F_60 ( V_149 , V_2 , F_53 ) ;
if ( ! F_59 ( V_2 -> V_19 , L_9 , & V_149 ) ) {
V_149 -> V_160 = V_161 ;
V_149 -> V_9 = V_2 ;
V_149 -> V_162 . V_141 = & V_163 ;
V_149 -> V_164 = V_165 ;
}
if ( ! F_59 ( V_2 -> V_19 , L_10 , & V_149 ) ) {
V_149 -> V_160 = V_161 ;
V_149 -> V_9 = V_2 ;
V_149 -> V_162 . V_141 = & V_166 ;
V_149 -> V_164 = V_167 ;
}
}
static void F_61 ( struct V_168 * V_168 )
{
struct V_1 * V_2 = F_62 ( V_168 ) ;
if ( F_18 ( ! V_2 ) )
return;
F_1 ( V_2 , V_169 , 0xff ) ;
}
static unsigned char F_63 ( struct V_168 * V_168 )
{
struct V_1 * V_2 = F_62 ( V_168 ) ;
if ( F_18 ( ! V_2 ) )
return 0 ;
return F_3 ( V_2 , V_169 ) ;
}
static int F_64 ( struct V_168 * V_168 ,
int * V_170 , int * V_171 )
{
struct V_1 * V_2 = F_62 ( V_168 ) ;
unsigned V_172 , V_173 , V_174 ;
if ( F_18 ( ! V_2 ) )
return 0 ;
V_172 = F_3 ( V_2 , V_175 ) ;
V_173 = F_3 ( V_2 , V_176 ) ;
V_174 = F_3 ( V_2 , V_169 ) ;
* V_171 = ( ~ V_174 >> 4 ) & 0x0F ;
V_170 [ 0 ] = ( ( V_172 & V_177 ) >> V_178 ) & 0xFFFF ;
V_170 [ 1 ] = ( ( V_172 & V_179 ) >> V_180 ) & 0xFFFF ;
V_170 [ 2 ] = ( ( V_173 & V_181 ) >> V_182 ) & 0xFFFF ;
V_170 [ 3 ] = ( ( V_173 & V_183 ) >> V_184 ) & 0xFFFF ;
for ( V_174 = 0 ; V_174 < 4 ; ++ V_174 )
if ( V_170 [ V_174 ] == 0xFFFF ) V_170 [ V_174 ] = - 1 ;
return 0 ;
}
static int F_65 ( struct V_168 * V_168 , int V_185 )
{
switch ( V_185 ) {
#ifdef F_66
case V_186 :
return 0 ;
#endif
case V_187 :
return 0 ;
default:
return - 1 ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_168 * V_188 ;
V_2 -> V_168 = V_188 = F_68 () ;
if ( ! V_188 ) {
F_7 ( V_2 -> V_19 -> V_20 ,
L_11 ) ;
return - V_189 ;
}
F_69 ( V_188 , L_12 ) ;
F_70 ( V_188 , L_13 , F_71 ( V_2 -> V_116 ) ) ;
F_72 ( V_188 , & V_2 -> V_116 -> V_20 ) ;
V_188 -> V_190 = F_65 ;
V_188 -> V_143 = F_63 ;
V_188 -> V_191 = F_61 ;
V_188 -> V_192 = F_64 ;
F_73 ( V_188 , V_2 ) ;
F_1 ( V_2 , V_193 , 0xFF ) ;
F_1 ( V_2 , V_194 , V_195 ) ;
F_74 ( V_188 ) ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 )
{
if ( V_2 -> V_168 ) {
F_76 ( V_2 -> V_168 ) ;
V_2 -> V_168 = NULL ;
}
}
static inline int F_67 ( struct V_1 * V_2 ) { return - V_196 ; }
static inline void F_75 ( struct V_1 * V_2 ) { }
static int F_77 ( struct V_1 * V_2 )
{
F_75 ( V_2 ) ;
if ( V_2 -> V_197 >= 0 )
F_78 ( V_2 -> V_197 ) ;
F_1 ( V_2 , V_198 , 0x7fffffff ) ;
F_1 ( V_2 , V_199 , 0 ) ;
F_1 ( V_2 , V_200 , 0 ) ;
F_79 ( V_2 -> V_116 , V_201 ) ;
if ( V_2 -> V_197 >= 0 )
F_80 ( V_2 -> V_197 , V_2 ) ;
if ( V_2 -> V_5 )
F_81 ( V_2 -> V_5 ) ;
if ( V_2 -> V_159 )
F_81 ( V_2 -> V_159 ) ;
F_82 ( V_2 -> V_116 ) ;
F_83 ( V_2 -> V_116 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
static int F_85 ( struct V_202 * V_104 )
{
struct V_1 * V_2 = V_104 -> V_203 ;
return F_77 ( V_2 ) ;
}
static int F_86 ( struct V_138 * V_19 ,
struct V_204 * V_116 ,
struct V_1 * * V_205 ,
int V_145 )
{
struct V_1 * V_2 ;
unsigned int V_206 ;
int V_108 ;
static struct V_207 V_141 = {
. V_208 = F_85 ,
} ;
* V_205 = NULL ;
if ( ( V_108 = F_87 ( V_116 ) ) < 0 )
return V_108 ;
V_2 = F_88 ( sizeof( * V_2 ) , V_209 ) ;
if ( V_2 == NULL ) {
F_83 ( V_116 ) ;
return - V_189 ;
}
F_89 ( & V_2 -> V_38 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_116 = V_116 ;
V_2 -> V_197 = - 1 ;
F_90 ( V_116 ) ;
if ( V_145 < 0 || V_145 > 3 ) {
F_7 ( V_19 -> V_20 , L_14 , V_145 ) ;
V_145 = 0 ;
}
V_2 -> V_145 = V_145 ;
if ( ( V_108 = F_91 ( V_116 , L_4 ) ) < 0 ) {
F_84 ( V_2 ) ;
F_83 ( V_116 ) ;
return V_108 ;
}
V_2 -> V_210 = F_92 ( V_116 , 0 ) ;
V_2 -> V_211 = F_92 ( V_116 , 1 ) ;
V_2 -> V_5 = F_93 ( V_116 , 0 ) ;
V_2 -> V_159 = F_93 ( V_116 , 1 ) ;
if ( ! V_2 -> V_5 || ! V_2 -> V_159 ) {
F_77 ( V_2 ) ;
return - V_189 ;
}
if ( F_94 ( V_116 -> V_197 , V_212 , V_213 ,
V_214 , V_2 ) ) {
F_7 ( V_19 -> V_20 , L_15 , V_116 -> V_197 ) ;
F_77 ( V_2 ) ;
return - V_189 ;
}
V_2 -> V_197 = V_116 -> V_197 ;
V_206 = F_95 ( V_2 ) ;
if ( V_206 ) {
F_77 ( V_2 ) ;
return V_206 ;
}
if ( ( V_108 = F_96 ( V_19 , V_215 , V_2 , & V_141 ) ) < 0 ) {
F_77 ( V_2 ) ;
return V_108 ;
}
F_58 ( V_2 ) ;
* V_205 = V_2 ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 )
{
unsigned int V_206 ;
unsigned long V_216 ;
int V_217 = 2 ;
V_206 = F_3 ( V_2 , V_218 ) ;
if ( V_206 & V_219 )
F_1 ( V_2 , V_218 , V_206 & ~ V_219 ) ;
V_220:
V_206 = F_3 ( V_2 , V_221 ) ;
if ( V_206 != V_222 ) {
F_1 ( V_2 , V_221 , V_222 ) ;
V_206 = F_3 ( V_2 , V_221 ) ;
if ( V_206 != V_222 ) {
F_7 ( V_2 -> V_19 -> V_20 ,
L_16 , V_206 ) ;
return - V_223 ;
}
}
F_1 ( V_2 , V_224 , 0x4281 ) ;
if ( ( V_206 = F_3 ( V_2 , V_225 ) ) != ( V_226 | V_227 ) ) {
F_7 ( V_2 -> V_19 -> V_20 ,
L_17 , V_206 ) ;
return - V_223 ;
}
if ( ( V_206 = F_3 ( V_2 , V_228 ) ) != ( V_229 | V_230 ) ) {
F_7 ( V_2 -> V_19 -> V_20 ,
L_18 , V_206 ) ;
return - V_223 ;
}
F_1 ( V_2 , V_200 , V_231 | V_232 |
V_233 | V_234 |
V_235 | V_236 ) ;
F_1 ( V_2 , V_199 , 0 ) ;
F_1 ( V_2 , V_237 , 0 ) ;
F_1 ( V_2 , V_13 , 0 ) ;
F_6 ( 50 ) ;
F_1 ( V_2 , V_238 , 0 ) ;
F_6 ( 50 ) ;
F_1 ( V_2 , V_238 , V_239 ) ;
F_97 ( 50 ) ;
if ( V_2 -> V_145 )
F_1 ( V_2 , V_238 , V_239 | V_240 ) ;
F_1 ( V_2 , V_237 ,
( V_2 -> V_145 ? F_98 ( V_2 -> V_145 ) : F_98 ( 1 ) ) |
V_241 | V_242 ) ;
F_1 ( V_2 , V_199 , V_243 ) ;
F_97 ( 50 ) ;
F_1 ( V_2 , V_199 , V_244 | V_243 ) ;
V_216 = V_245 + V_246 ;
do {
if ( F_3 ( V_2 , V_199 ) & V_247 )
goto V_248;
F_99 ( 1 ) ;
} while ( F_100 ( V_216 , V_245 ) );
F_7 ( V_2 -> V_19 -> V_20 , L_19 ) ;
return - V_223 ;
V_248:
F_1 ( V_2 , V_13 , V_16 ) ;
V_216 = V_245 + V_246 ;
do {
if ( F_3 ( V_2 , V_29 ) & V_249 )
goto V_26;
F_99 ( 1 ) ;
} while ( F_100 ( V_216 , V_245 ) );
F_7 ( V_2 -> V_19 -> V_20 ,
L_20 ,
F_3 ( V_2 , V_29 ) ) ;
return - V_223 ;
V_26:
if ( V_2 -> V_145 ) {
V_216 = V_245 + V_246 ;
do {
if ( F_3 ( V_2 , V_28 ) & V_249 )
goto V_250;
F_99 ( 1 ) ;
} while ( F_100 ( V_216 , V_245 ) );
F_101 ( V_2 -> V_19 -> V_20 ,
L_21 ) ;
V_2 -> V_145 = 0 ;
V_250: ;
}
F_1 ( V_2 , V_13 , V_15 | V_16 ) ;
V_216 = V_245 + V_246 ;
do {
if ( ( F_3 ( V_2 , V_251 ) & ( F_102 ( 3 ) | F_102 ( 4 ) ) ) == ( F_102 ( 3 ) | F_102 ( 4 ) ) )
goto V_31;
F_99 ( 1 ) ;
} while ( F_100 ( V_216 , V_245 ) );
if ( -- V_217 > 0 )
goto V_220;
F_7 ( V_2 -> V_19 -> V_20 , L_22 ) ;
return - V_223 ;
V_31:
F_1 ( V_2 , V_252 , F_103 ( 3 ) | F_103 ( 4 ) ) ;
for ( V_206 = 0 ; V_206 < 4 ; V_206 ++ ) {
struct V_35 * V_36 = & V_2 -> V_36 [ V_206 ] ;
V_36 -> V_81 = V_253 + ( V_206 * 0x10 ) ;
V_36 -> V_254 = V_255 + ( V_206 * 0x10 ) ;
V_36 -> V_83 = V_256 + ( V_206 * 0x10 ) ;
V_36 -> V_100 = V_257 + ( V_206 * 0x10 ) ;
V_36 -> V_47 = V_258 + ( V_206 * 8 ) ;
V_36 -> V_56 = V_259 + ( V_206 * 8 ) ;
V_36 -> V_260 = V_261 + ( V_206 * 4 ) ;
V_36 -> V_53 = V_54 + ( V_206 * 4 ) ;
V_36 -> V_97 = V_262 + ( V_206 * 4 ) ;
V_36 -> V_95 = V_206 * V_94 ;
F_1 ( V_2 , V_36 -> V_53 ,
F_19 ( 31 ) |
F_20 ( 31 ) |
F_21 ( V_94 ) |
F_22 ( V_36 -> V_95 ) ) ;
}
V_2 -> V_85 = 0 ;
V_2 -> V_86 = 1 ;
V_2 -> V_87 = 10 ;
V_2 -> V_88 = 11 ;
V_2 -> V_36 [ 0 ] . V_42 = V_43 | F_19 ( 0 ) |
F_20 ( 1 ) |
F_21 ( V_94 ) |
F_22 ( V_2 -> V_36 [ 0 ] . V_95 ) ;
F_1 ( V_2 , V_2 -> V_36 [ 0 ] . V_53 , V_2 -> V_36 [ 0 ] . V_42 ) ;
F_1 ( V_2 , V_84 , ( V_2 -> V_85 << 0 ) |
( V_2 -> V_86 << 8 ) |
( V_2 -> V_87 << 16 ) |
( V_2 -> V_88 << 24 ) ) ;
F_1 ( V_2 , V_263 , 0 ) ;
F_1 ( V_2 , V_264 , 0 ) ;
F_1 ( V_2 , V_265 , V_266 ) ;
F_1 ( V_2 , V_198 , 0x7fffffff & ~ (
V_267 |
V_268 |
F_104 ( 0 ) |
F_104 ( 1 ) |
F_104 ( 2 ) |
F_104 ( 3 ) ) ) ;
F_78 ( V_2 -> V_197 ) ;
return 0 ;
}
static void F_105 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_269 , V_2 -> V_270 | V_271 ) ;
F_6 ( 100 ) ;
F_1 ( V_2 , V_269 , V_2 -> V_270 ) ;
}
static int F_106 ( struct V_272 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_273 -> V_9 ;
F_29 ( & V_2 -> V_38 ) ;
V_2 -> V_270 |= V_274 ;
V_2 -> V_275 = V_33 ;
if ( ! ( V_2 -> V_276 & V_277 ) ) {
F_105 ( V_2 ) ;
} else {
F_1 ( V_2 , V_269 , V_2 -> V_270 ) ;
}
F_30 ( & V_2 -> V_38 ) ;
return 0 ;
}
static int F_107 ( struct V_272 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_273 -> V_9 ;
F_29 ( & V_2 -> V_38 ) ;
V_2 -> V_270 &= ~ ( V_274 | V_278 ) ;
V_2 -> V_275 = NULL ;
if ( ! ( V_2 -> V_276 & V_277 ) ) {
F_105 ( V_2 ) ;
} else {
F_1 ( V_2 , V_269 , V_2 -> V_270 ) ;
}
V_2 -> V_276 &= ~ V_279 ;
F_30 ( & V_2 -> V_38 ) ;
return 0 ;
}
static int F_108 ( struct V_272 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_273 -> V_9 ;
F_29 ( & V_2 -> V_38 ) ;
V_2 -> V_276 |= V_277 ;
V_2 -> V_270 |= V_280 ;
V_2 -> V_281 = V_33 ;
if ( ! ( V_2 -> V_276 & V_279 ) ) {
F_105 ( V_2 ) ;
} else {
F_1 ( V_2 , V_269 , V_2 -> V_270 ) ;
}
F_30 ( & V_2 -> V_38 ) ;
return 0 ;
}
static int F_109 ( struct V_272 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_273 -> V_9 ;
F_29 ( & V_2 -> V_38 ) ;
V_2 -> V_270 &= ~ ( V_280 | V_282 ) ;
V_2 -> V_281 = NULL ;
if ( ! ( V_2 -> V_276 & V_279 ) ) {
F_105 ( V_2 ) ;
} else {
F_1 ( V_2 , V_269 , V_2 -> V_270 ) ;
}
V_2 -> V_276 &= ~ V_277 ;
F_30 ( & V_2 -> V_38 ) ;
return 0 ;
}
static void F_110 ( struct V_272 * V_33 , int V_283 )
{
unsigned long V_284 ;
struct V_1 * V_2 = V_33 -> V_273 -> V_9 ;
F_111 ( & V_2 -> V_38 , V_284 ) ;
if ( V_283 ) {
if ( ( V_2 -> V_270 & V_278 ) == 0 ) {
V_2 -> V_270 |= V_278 ;
F_1 ( V_2 , V_269 , V_2 -> V_270 ) ;
}
} else {
if ( V_2 -> V_270 & V_278 ) {
V_2 -> V_270 &= ~ V_278 ;
F_1 ( V_2 , V_269 , V_2 -> V_270 ) ;
}
}
F_112 ( & V_2 -> V_38 , V_284 ) ;
}
static void F_113 ( struct V_272 * V_33 , int V_283 )
{
unsigned long V_284 ;
struct V_1 * V_2 = V_33 -> V_273 -> V_9 ;
unsigned char V_285 ;
F_111 ( & V_2 -> V_38 , V_284 ) ;
if ( V_283 ) {
if ( ( V_2 -> V_270 & V_282 ) == 0 ) {
V_2 -> V_270 |= V_282 ;
while ( ( V_2 -> V_270 & V_282 ) &&
( F_3 ( V_2 , V_286 ) & V_287 ) == 0 ) {
if ( F_114 ( V_33 , & V_285 , 1 ) != 1 ) {
V_2 -> V_270 &= ~ V_282 ;
} else {
F_1 ( V_2 , V_288 , V_285 ) ;
}
}
F_1 ( V_2 , V_269 , V_2 -> V_270 ) ;
}
} else {
if ( V_2 -> V_270 & V_282 ) {
V_2 -> V_270 &= ~ V_282 ;
F_1 ( V_2 , V_269 , V_2 -> V_270 ) ;
}
}
F_112 ( & V_2 -> V_38 , V_284 ) ;
}
static int F_115 ( struct V_1 * V_2 , int V_104 ,
struct V_289 * * V_290 )
{
struct V_289 * V_273 ;
int V_108 ;
if ( V_290 )
* V_290 = NULL ;
if ( ( V_108 = F_116 ( V_2 -> V_19 , L_4 , V_104 , 1 , 1 , & V_273 ) ) < 0 )
return V_108 ;
strcpy ( V_273 -> V_114 , L_4 ) ;
F_117 ( V_273 , V_291 , & V_292 ) ;
F_117 ( V_273 , V_293 , & V_294 ) ;
V_273 -> V_113 |= V_295 | V_296 | V_297 ;
V_273 -> V_9 = V_2 ;
V_2 -> V_273 = V_273 ;
if ( V_290 )
* V_290 = V_273 ;
return 0 ;
}
static T_6 V_212 ( int V_197 , void * V_298 )
{
struct V_1 * V_2 = V_298 ;
unsigned int V_299 , V_36 , V_4 ;
struct V_35 * V_300 ;
if ( V_2 == NULL )
return V_301 ;
V_299 = F_3 ( V_2 , V_302 ) ;
if ( ( V_299 & 0x7fffffff ) == 0 ) {
F_1 ( V_2 , V_265 , V_266 ) ;
return V_301 ;
}
if ( V_299 & ( F_104 ( 0 ) | F_104 ( 1 ) | F_104 ( 2 ) | F_104 ( 3 ) ) ) {
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ )
if ( V_299 & F_104 ( V_36 ) ) {
V_300 = & V_2 -> V_36 [ V_36 ] ;
F_11 ( & V_2 -> V_38 ) ;
V_4 = F_3 ( V_2 , V_300 -> V_260 ) ;
V_300 -> V_76 ++ ;
if ( ( V_4 & V_303 ) && ! ( V_300 -> V_76 & 1 ) ) {
V_300 -> V_76 -- ;
V_2 -> V_152 ++ ;
F_12 ( & V_2 -> V_38 ) ;
continue;
}
if ( ( V_4 & V_304 ) && ( V_300 -> V_76 & 1 ) ) {
V_300 -> V_76 -- ;
V_2 -> V_153 ++ ;
F_12 ( & V_2 -> V_38 ) ;
continue;
}
F_12 ( & V_2 -> V_38 ) ;
F_118 ( V_300 -> V_33 ) ;
}
}
if ( ( V_299 & V_267 ) && V_2 -> V_273 ) {
unsigned char V_162 ;
F_11 ( & V_2 -> V_38 ) ;
while ( ( F_3 ( V_2 , V_286 ) & V_305 ) == 0 ) {
V_162 = F_3 ( V_2 , V_306 ) ;
if ( ( V_2 -> V_270 & V_278 ) == 0 )
continue;
F_119 ( V_2 -> V_275 , & V_162 , 1 ) ;
}
while ( ( F_3 ( V_2 , V_286 ) & V_287 ) == 0 ) {
if ( ( V_2 -> V_270 & V_282 ) == 0 )
break;
if ( F_114 ( V_2 -> V_281 , & V_162 , 1 ) != 1 ) {
V_2 -> V_270 &= ~ V_282 ;
F_1 ( V_2 , V_269 , V_2 -> V_270 ) ;
break;
}
F_1 ( V_2 , V_288 , V_162 ) ;
}
F_12 ( & V_2 -> V_38 ) ;
}
F_1 ( V_2 , V_265 , V_266 ) ;
return V_307 ;
}
static void F_120 ( struct V_308 * V_309 , unsigned short V_34 ,
unsigned char V_4 )
{
unsigned long V_284 ;
struct V_1 * V_2 = V_309 -> V_9 ;
void T_7 * V_310 ;
if ( V_34 & V_311 )
V_310 = V_2 -> V_5 + V_312 ;
else
V_310 = V_2 -> V_5 + V_313 ;
F_111 ( & V_309 -> V_38 , V_284 ) ;
F_2 ( ( unsigned int ) V_34 , V_310 ) ;
F_6 ( 10 ) ;
F_2 ( ( unsigned int ) V_4 , V_310 + 4 ) ;
F_6 ( 30 ) ;
F_112 ( & V_309 -> V_38 , V_284 ) ;
}
static int F_121 ( struct V_204 * V_116 ,
const struct V_314 * V_315 )
{
static int V_20 ;
struct V_138 * V_19 ;
struct V_1 * V_2 ;
struct V_308 * V_309 ;
int V_108 ;
if ( V_20 >= V_316 )
return - V_317 ;
if ( ! V_318 [ V_20 ] ) {
V_20 ++ ;
return - V_319 ;
}
V_108 = F_122 ( & V_116 -> V_20 , V_320 [ V_20 ] , V_321 [ V_20 ] , V_322 ,
0 , & V_19 ) ;
if ( V_108 < 0 )
return V_108 ;
if ( ( V_108 = F_86 ( V_19 , V_116 , & V_2 , V_145 [ V_20 ] ) ) < 0 ) {
F_123 ( V_19 ) ;
return V_108 ;
}
V_19 -> V_9 = V_2 ;
if ( ( V_108 = F_49 ( V_2 ) ) < 0 ) {
F_123 ( V_19 ) ;
return V_108 ;
}
if ( ( V_108 = F_38 ( V_2 , 0 , NULL ) ) < 0 ) {
F_123 ( V_19 ) ;
return V_108 ;
}
if ( ( V_108 = F_115 ( V_2 , 0 , NULL ) ) < 0 ) {
F_123 ( V_19 ) ;
return V_108 ;
}
if ( ( V_108 = F_124 ( V_19 , V_323 , & V_309 ) ) < 0 ) {
F_123 ( V_19 ) ;
return V_108 ;
}
V_309 -> V_9 = V_2 ;
V_309 -> V_324 = F_120 ;
F_125 ( V_309 ) ;
if ( ( V_108 = F_126 ( V_309 , 0 , 1 , NULL ) ) < 0 ) {
F_123 ( V_19 ) ;
return V_108 ;
}
F_67 ( V_2 ) ;
strcpy ( V_19 -> V_325 , L_4 ) ;
strcpy ( V_19 -> V_326 , L_23 ) ;
sprintf ( V_19 -> V_327 , L_24 ,
V_19 -> V_326 ,
V_2 -> V_210 ,
V_2 -> V_197 ) ;
if ( ( V_108 = F_127 ( V_19 ) ) < 0 ) {
F_123 ( V_19 ) ;
return V_108 ;
}
F_128 ( V_116 , V_19 ) ;
V_20 ++ ;
return 0 ;
}
static void F_129 ( struct V_204 * V_116 )
{
F_123 ( F_130 ( V_116 ) ) ;
}
static int F_131 ( struct V_104 * V_20 )
{
struct V_204 * V_116 = F_132 ( V_20 ) ;
struct V_138 * V_19 = F_133 ( V_20 ) ;
struct V_1 * V_2 = V_19 -> V_9 ;
T_8 V_328 ;
unsigned int V_329 ;
F_134 ( V_19 , V_330 ) ;
F_135 ( V_2 -> V_107 ) ;
F_136 ( V_2 -> V_7 ) ;
F_136 ( V_2 -> V_137 ) ;
V_328 = F_3 ( V_2 , V_199 ) ;
V_328 |= V_331 ;
F_1 ( V_2 , V_199 , V_328 ) ;
F_1 ( V_2 , V_265 , V_332 ) ;
for ( V_329 = 0 ; V_329 < F_137 ( V_333 ) ; V_329 ++ )
if ( V_333 [ V_329 ] )
V_2 -> V_334 [ V_329 ] = F_3 ( V_2 , V_333 [ V_329 ] ) ;
F_1 ( V_2 , V_237 , 0 ) ;
F_1 ( V_2 , V_200 , 0 ) ;
F_1 ( V_2 , V_199 , 0 ) ;
F_1 ( V_2 , V_238 , 0 ) ;
V_328 = F_3 ( V_2 , V_199 ) ;
V_328 &= ~ V_331 ;
F_1 ( V_2 , V_199 , V_328 ) ;
F_83 ( V_116 ) ;
F_138 ( V_116 ) ;
F_79 ( V_116 , V_201 ) ;
return 0 ;
}
static int F_139 ( struct V_104 * V_20 )
{
struct V_204 * V_116 = F_132 ( V_20 ) ;
struct V_138 * V_19 = F_133 ( V_20 ) ;
struct V_1 * V_2 = V_19 -> V_9 ;
unsigned int V_329 ;
T_8 V_328 ;
F_79 ( V_116 , V_335 ) ;
F_140 ( V_116 ) ;
if ( F_87 ( V_116 ) < 0 ) {
F_7 ( V_20 , L_25 ) ;
F_141 ( V_19 ) ;
return - V_223 ;
}
F_90 ( V_116 ) ;
V_328 = F_3 ( V_2 , V_199 ) ;
V_328 |= V_331 ;
F_1 ( V_2 , V_199 , V_328 ) ;
F_95 ( V_2 ) ;
for ( V_329 = 0 ; V_329 < F_137 ( V_333 ) ; V_329 ++ )
if ( V_333 [ V_329 ] )
F_1 ( V_2 , V_333 [ V_329 ] , V_2 -> V_334 [ V_329 ] ) ;
F_142 ( V_2 -> V_7 ) ;
F_142 ( V_2 -> V_137 ) ;
V_328 = F_3 ( V_2 , V_199 ) ;
V_328 &= ~ V_331 ;
F_1 ( V_2 , V_199 , V_328 ) ;
F_134 ( V_19 , V_336 ) ;
return 0 ;
}
