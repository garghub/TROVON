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
F_7 ( V_19 L_1 , V_8 , V_4 ) ;
}
static unsigned short F_8 ( struct V_6 * V_7 ,
unsigned short V_8 )
{
struct V_1 * V_2 = V_7 -> V_9 ;
int V_10 ;
unsigned short V_20 ;
volatile int V_21 = ( ( volatile struct V_6 * ) V_7 ) -> V_17 ;
F_3 ( V_2 , V_21 ? V_22 : V_23 ) ;
F_1 ( V_2 , V_11 , V_8 ) ;
F_1 ( V_2 , V_12 , 0 ) ;
F_1 ( V_2 , V_13 , V_14 | V_24 |
V_15 | V_16 |
( V_21 ? V_18 : 0 ) ) ;
for ( V_10 = 0 ; V_10 < 500 ; V_10 ++ ) {
F_6 ( 10 ) ;
if ( ! ( F_3 ( V_2 , V_13 ) & V_14 ) )
goto V_25;
}
F_7 ( V_19 L_2 , V_8 ) ;
V_20 = 0xffff ;
goto V_26;
V_25:
for ( V_10 = 0 ; V_10 < 100 ; V_10 ++ ) {
if ( F_3 ( V_2 , V_21 ? V_27 : V_28 ) & V_29 )
goto V_30;
F_6 ( 10 ) ;
}
F_7 ( V_19 L_3 , V_8 ) ;
V_20 = 0xffff ;
goto V_26;
V_30:
V_20 = F_3 ( V_2 , V_21 ? V_22 : V_23 ) ;
V_26:
return V_20 ;
}
static int F_9 ( struct V_31 * V_32 , int V_33 )
{
struct V_34 * V_35 = V_32 -> V_36 -> V_9 ;
struct V_1 * V_2 = F_10 ( V_32 ) ;
F_11 ( & V_2 -> V_37 ) ;
switch ( V_33 ) {
case V_38 :
V_35 -> V_39 |= V_40 ;
V_35 -> V_41 |= V_42 ;
break;
case V_43 :
V_35 -> V_39 &= ~ V_40 ;
V_35 -> V_41 &= ~ V_42 ;
break;
case V_44 :
case V_45 :
F_1 ( V_2 , V_35 -> V_46 , V_35 -> V_47 & ~ V_48 ) ;
V_35 -> V_47 |= V_48 ;
V_35 -> V_39 &= ~ V_40 ;
V_35 -> V_41 |= V_42 ;
break;
case V_49 :
case V_50 :
V_35 -> V_47 &= ~ ( V_48 | V_51 ) ;
V_35 -> V_39 |= V_40 ;
V_35 -> V_41 &= ~ V_42 ;
if ( V_35 -> V_52 != V_53 )
V_35 -> V_41 &= ~ V_42 ;
break;
default:
F_12 ( & V_2 -> V_37 ) ;
return - V_54 ;
}
F_1 ( V_2 , V_35 -> V_46 , V_35 -> V_47 ) ;
F_1 ( V_2 , V_35 -> V_52 , V_35 -> V_41 ) ;
F_1 ( V_2 , V_35 -> V_55 , V_35 -> V_39 ) ;
F_12 ( & V_2 -> V_37 ) ;
return 0 ;
}
static unsigned int F_13 ( unsigned int V_56 , unsigned int * V_57 )
{
unsigned int V_4 = ~ 0 ;
if ( V_57 )
* V_57 = V_56 ;
switch ( V_56 ) {
case 8000 : return 5 ;
case 11025 : return 4 ;
case 16000 : return 3 ;
case 22050 : return 2 ;
case 44100 : return 1 ;
case 48000 : return 0 ;
default:
goto V_58;
}
V_58:
V_4 = 1536000 / V_56 ;
if ( V_57 )
* V_57 = 1536000 / V_4 ;
return V_4 ;
}
static void F_14 ( struct V_1 * V_2 , struct V_34 * V_35 ,
struct V_59 * V_36 ,
int V_60 , int V_61 )
{
int V_62 ;
V_35 -> V_47 = V_63 | V_64 |
( V_60 ? V_65 : V_66 ) ;
if ( V_36 -> V_67 == 1 )
V_35 -> V_47 |= V_68 ;
if ( F_15 ( V_36 -> V_69 ) > 0 )
V_35 -> V_47 |= V_70 ;
if ( F_16 ( V_36 -> V_69 ) > 0 )
V_35 -> V_47 |= V_71 ;
switch ( F_17 ( V_36 -> V_69 ) ) {
case 8 : V_35 -> V_47 |= V_72 ;
if ( V_36 -> V_67 == 1 )
V_35 -> V_47 |= V_73 ;
break;
case 32 : V_35 -> V_47 |= V_74 ; break;
}
V_35 -> V_75 = 0 ;
V_35 -> V_39 = V_76 | V_40 ;
if ( V_36 -> V_77 != V_36 -> V_78 )
V_35 -> V_39 |= V_79 ;
F_1 ( V_2 , V_35 -> V_80 , V_36 -> V_81 ) ;
F_1 ( V_2 , V_35 -> V_82 , V_36 -> V_77 - 1 ) ;
V_62 = ( V_2 -> V_35 [ 1 ] . V_47 & V_68 ) == V_68 ;
F_1 ( V_2 , V_83 , ( V_2 -> V_84 << 0 ) |
( V_2 -> V_85 << 8 ) |
( V_2 -> V_86 << 16 ) |
( ( V_62 ? 31 : V_2 -> V_87 ) << 24 ) ) ;
if ( ! V_61 )
goto V_88;
if ( ! V_60 ) {
if ( V_35 -> V_89 == V_2 -> V_84 ) {
unsigned int V_4 = F_13 ( V_36 -> V_56 , NULL ) ;
F_18 ( V_35 -> V_90 != V_2 -> V_85 ) ;
F_1 ( V_2 , V_91 , V_4 ) ;
}
} else {
if ( V_35 -> V_89 == V_2 -> V_86 ) {
unsigned int V_4 = F_13 ( V_36 -> V_56 , NULL ) ;
F_18 ( V_35 -> V_90 != V_2 -> V_87 ) ;
F_1 ( V_2 , V_92 , V_4 ) ;
}
}
V_88:
if ( V_35 -> V_52 == V_53 )
F_1 ( V_2 , V_35 -> V_52 , F_3 ( V_2 , V_35 -> V_52 ) & ~ V_42 ) ;
V_35 -> V_41 = F_19 ( V_35 -> V_89 ) |
F_20 ( V_60 && ( V_35 -> V_47 & V_68 ) ? 31 : V_35 -> V_90 ) |
F_21 ( V_93 ) |
F_22 ( V_35 -> V_94 ) ;
F_1 ( V_2 , V_35 -> V_52 , V_35 -> V_41 | ( V_60 ? V_95 : 0 ) ) ;
if ( V_35 -> V_52 == V_53 )
F_1 ( V_2 , V_35 -> V_52 , V_35 -> V_41 | V_42 ) ;
F_1 ( V_2 , V_35 -> V_96 , 0 ) ;
}
static int F_23 ( struct V_31 * V_32 ,
struct V_97 * V_98 )
{
return F_24 ( V_32 , F_25 ( V_98 ) ) ;
}
static int F_26 ( struct V_31 * V_32 )
{
return F_27 ( V_32 ) ;
}
static int F_28 ( struct V_31 * V_32 )
{
struct V_59 * V_36 = V_32 -> V_36 ;
struct V_34 * V_35 = V_36 -> V_9 ;
struct V_1 * V_2 = F_10 ( V_32 ) ;
F_29 ( & V_2 -> V_37 ) ;
F_14 ( V_2 , V_35 , V_36 , 0 , 1 ) ;
F_30 ( & V_2 -> V_37 ) ;
return 0 ;
}
static int F_31 ( struct V_31 * V_32 )
{
struct V_59 * V_36 = V_32 -> V_36 ;
struct V_34 * V_35 = V_36 -> V_9 ;
struct V_1 * V_2 = F_10 ( V_32 ) ;
F_29 ( & V_2 -> V_37 ) ;
F_14 ( V_2 , V_35 , V_36 , 1 , 1 ) ;
F_30 ( & V_2 -> V_37 ) ;
return 0 ;
}
static T_1 F_32 ( struct V_31 * V_32 )
{
struct V_59 * V_36 = V_32 -> V_36 ;
struct V_34 * V_35 = V_36 -> V_9 ;
struct V_1 * V_2 = F_10 ( V_32 ) ;
return V_36 -> V_77 -
F_3 ( V_2 , V_35 -> V_99 ) - 1 ;
}
static int F_33 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_10 ( V_32 ) ;
struct V_59 * V_36 = V_32 -> V_36 ;
struct V_34 * V_35 ;
V_35 = & V_2 -> V_35 [ 0 ] ;
V_35 -> V_32 = V_32 ;
V_35 -> V_89 = 0 ;
V_35 -> V_90 = 1 ;
V_36 -> V_9 = V_35 ;
V_36 -> V_100 = V_101 ;
F_34 ( V_36 , 0 , 32 , 20 ) ;
return 0 ;
}
static int F_35 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_10 ( V_32 ) ;
struct V_59 * V_36 = V_32 -> V_36 ;
struct V_34 * V_35 ;
V_35 = & V_2 -> V_35 [ 1 ] ;
V_35 -> V_32 = V_32 ;
V_35 -> V_89 = 10 ;
V_35 -> V_90 = 11 ;
V_36 -> V_9 = V_35 ;
V_36 -> V_100 = V_102 ;
F_34 ( V_36 , 0 , 32 , 20 ) ;
return 0 ;
}
static int F_36 ( struct V_31 * V_32 )
{
struct V_34 * V_35 = V_32 -> V_36 -> V_9 ;
V_35 -> V_32 = NULL ;
return 0 ;
}
static int F_37 ( struct V_31 * V_32 )
{
struct V_34 * V_35 = V_32 -> V_36 -> V_9 ;
V_35 -> V_32 = NULL ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , int V_103 ,
struct V_104 * * V_105 )
{
struct V_104 * V_106 ;
int V_107 ;
if ( V_105 )
* V_105 = NULL ;
V_107 = F_39 ( V_2 -> V_108 , L_4 , V_103 , 1 , 1 , & V_106 ) ;
if ( V_107 < 0 )
return V_107 ;
F_40 ( V_106 , V_109 , & V_110 ) ;
F_40 ( V_106 , V_111 , & V_112 ) ;
V_106 -> V_9 = V_2 ;
V_106 -> V_113 = 0 ;
strcpy ( V_106 -> V_114 , L_4 ) ;
V_2 -> V_106 = V_106 ;
F_41 ( V_106 , V_115 ,
F_42 ( V_2 -> V_116 ) , 64 * 1024 , 512 * 1024 ) ;
if ( V_105 )
* V_105 = V_106 ;
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
struct V_138 * V_108 = V_2 -> V_108 ;
struct V_139 V_7 ;
int V_107 ;
static struct V_140 V_141 = {
. V_142 = F_5 ,
. V_143 = F_8 ,
} ;
if ( ( V_107 = V_134 ( V_108 , 0 , & V_141 , V_2 , & V_2 -> V_136 ) ) < 0 )
return V_107 ;
V_2 -> V_136 -> V_144 = F_47 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_9 = V_2 ;
V_7 . V_144 = F_48 ;
if ( ( V_107 = F_50 ( V_2 -> V_136 , & V_7 , & V_2 -> V_7 ) ) < 0 )
return V_107 ;
if ( V_2 -> V_145 ) {
V_7 . V_17 = 1 ;
if ( ( V_107 = F_50 ( V_2 -> V_136 , & V_7 , & V_2 -> V_137 ) ) < 0 )
return V_107 ;
}
if ( ( V_107 = F_51 ( V_108 , F_52 ( & V_146 , V_2 ) ) ) < 0 )
return V_107 ;
if ( ( V_107 = F_51 ( V_108 , F_52 ( & V_147 , V_2 ) ) ) < 0 )
return V_107 ;
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
if ( ! F_59 ( V_2 -> V_108 , L_8 , & V_149 ) )
F_60 ( V_149 , V_2 , F_53 ) ;
if ( ! F_59 ( V_2 -> V_108 , L_9 , & V_149 ) ) {
V_149 -> V_160 = V_161 ;
V_149 -> V_9 = V_2 ;
V_149 -> V_162 . V_141 = & V_163 ;
V_149 -> V_164 = V_165 ;
}
if ( ! F_59 ( V_2 -> V_108 , L_10 , & V_149 ) ) {
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
F_69 ( V_19 L_11 ) ;
return - V_189 ;
}
F_70 ( V_188 , L_12 ) ;
F_71 ( V_188 , L_13 , F_72 ( V_2 -> V_116 ) ) ;
F_73 ( V_188 , & V_2 -> V_116 -> V_190 ) ;
V_188 -> V_191 = F_65 ;
V_188 -> V_143 = F_63 ;
V_188 -> V_192 = F_61 ;
V_188 -> V_193 = F_64 ;
F_74 ( V_188 , V_2 ) ;
F_1 ( V_2 , V_194 , 0xFF ) ;
F_1 ( V_2 , V_195 , V_196 ) ;
F_75 ( V_188 ) ;
return 0 ;
}
static void F_76 ( struct V_1 * V_2 )
{
if ( V_2 -> V_168 ) {
F_77 ( V_2 -> V_168 ) ;
V_2 -> V_168 = NULL ;
}
}
static inline int F_67 ( struct V_1 * V_2 ) { return - V_197 ; }
static inline void F_76 ( struct V_1 * V_2 ) { }
static int F_78 ( struct V_1 * V_2 )
{
F_76 ( V_2 ) ;
if ( V_2 -> V_198 >= 0 )
F_79 ( V_2 -> V_198 ) ;
F_1 ( V_2 , V_199 , 0x7fffffff ) ;
F_1 ( V_2 , V_200 , 0 ) ;
F_1 ( V_2 , V_201 , 0 ) ;
F_80 ( V_2 -> V_116 , 3 ) ;
if ( V_2 -> V_198 >= 0 )
F_81 ( V_2 -> V_198 , V_2 ) ;
if ( V_2 -> V_5 )
F_82 ( V_2 -> V_5 ) ;
if ( V_2 -> V_159 )
F_82 ( V_2 -> V_159 ) ;
F_83 ( V_2 -> V_116 ) ;
F_84 ( V_2 -> V_116 ) ;
F_85 ( V_2 ) ;
return 0 ;
}
static int F_86 ( struct V_202 * V_103 )
{
struct V_1 * V_2 = V_103 -> V_203 ;
return F_78 ( V_2 ) ;
}
static int F_87 ( struct V_138 * V_108 ,
struct V_204 * V_116 ,
struct V_1 * * V_205 ,
int V_145 )
{
struct V_1 * V_2 ;
unsigned int V_206 ;
int V_107 ;
static struct V_207 V_141 = {
. V_208 = F_86 ,
} ;
* V_205 = NULL ;
if ( ( V_107 = F_88 ( V_116 ) ) < 0 )
return V_107 ;
V_2 = F_89 ( sizeof( * V_2 ) , V_209 ) ;
if ( V_2 == NULL ) {
F_84 ( V_116 ) ;
return - V_189 ;
}
F_90 ( & V_2 -> V_37 ) ;
V_2 -> V_108 = V_108 ;
V_2 -> V_116 = V_116 ;
V_2 -> V_198 = - 1 ;
F_91 ( V_116 ) ;
if ( V_145 < 0 || V_145 > 3 ) {
F_7 ( V_19 L_14 , V_145 ) ;
V_145 = 0 ;
}
V_2 -> V_145 = V_145 ;
if ( ( V_107 = F_92 ( V_116 , L_4 ) ) < 0 ) {
F_85 ( V_2 ) ;
F_84 ( V_116 ) ;
return V_107 ;
}
V_2 -> V_210 = F_93 ( V_116 , 0 ) ;
V_2 -> V_211 = F_93 ( V_116 , 1 ) ;
V_2 -> V_5 = F_94 ( V_116 , 0 ) ;
V_2 -> V_159 = F_94 ( V_116 , 1 ) ;
if ( ! V_2 -> V_5 || ! V_2 -> V_159 ) {
F_78 ( V_2 ) ;
return - V_189 ;
}
if ( F_95 ( V_116 -> V_198 , V_212 , V_213 ,
V_214 , V_2 ) ) {
F_7 ( V_19 L_15 , V_116 -> V_198 ) ;
F_78 ( V_2 ) ;
return - V_189 ;
}
V_2 -> V_198 = V_116 -> V_198 ;
V_206 = F_96 ( V_2 ) ;
if ( V_206 ) {
F_78 ( V_2 ) ;
return V_206 ;
}
if ( ( V_107 = F_97 ( V_108 , V_215 , V_2 , & V_141 ) ) < 0 ) {
F_78 ( V_2 ) ;
return V_107 ;
}
F_58 ( V_2 ) ;
F_98 ( V_108 , & V_116 -> V_190 ) ;
* V_205 = V_2 ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
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
F_7 ( V_19 L_16 , V_206 ) ;
return - V_223 ;
}
}
F_1 ( V_2 , V_224 , 0x4281 ) ;
if ( ( V_206 = F_3 ( V_2 , V_225 ) ) != ( V_226 | V_227 ) ) {
F_7 ( V_19 L_17 , V_206 ) ;
return - V_223 ;
}
if ( ( V_206 = F_3 ( V_2 , V_228 ) ) != ( V_229 | V_230 ) ) {
F_7 ( V_19 L_18 , V_206 ) ;
return - V_223 ;
}
F_1 ( V_2 , V_201 , V_231 | V_232 |
V_233 | V_234 |
V_235 | V_236 ) ;
F_1 ( V_2 , V_200 , 0 ) ;
F_1 ( V_2 , V_237 , 0 ) ;
F_1 ( V_2 , V_13 , 0 ) ;
F_6 ( 50 ) ;
F_1 ( V_2 , V_238 , 0 ) ;
F_6 ( 50 ) ;
F_1 ( V_2 , V_238 , V_239 ) ;
F_99 ( 50 ) ;
if ( V_2 -> V_145 )
F_1 ( V_2 , V_238 , V_239 | V_240 ) ;
F_1 ( V_2 , V_237 ,
( V_2 -> V_145 ? F_100 ( V_2 -> V_145 ) : F_100 ( 1 ) ) |
V_241 | V_242 ) ;
F_1 ( V_2 , V_200 , V_243 ) ;
F_99 ( 50 ) ;
F_1 ( V_2 , V_200 , V_244 | V_243 ) ;
V_216 = V_245 + V_246 ;
do {
if ( F_3 ( V_2 , V_200 ) & V_247 )
goto V_248;
F_101 ( 1 ) ;
} while ( F_102 ( V_216 , V_245 ) );
F_7 ( V_19 L_19 ) ;
return - V_223 ;
V_248:
F_1 ( V_2 , V_13 , V_16 ) ;
V_216 = V_245 + V_246 ;
do {
if ( F_3 ( V_2 , V_28 ) & V_249 )
goto V_25;
F_101 ( 1 ) ;
} while ( F_102 ( V_216 , V_245 ) );
F_7 ( V_19 L_20 , F_3 ( V_2 , V_28 ) ) ;
return - V_223 ;
V_25:
if ( V_2 -> V_145 ) {
V_216 = V_245 + V_246 ;
do {
if ( F_3 ( V_2 , V_27 ) & V_249 )
goto V_250;
F_101 ( 1 ) ;
} while ( F_102 ( V_216 , V_245 ) );
F_7 ( V_251 L_21 ) ;
V_2 -> V_145 = 0 ;
V_250: ;
}
F_1 ( V_2 , V_13 , V_15 | V_16 ) ;
V_216 = V_245 + V_246 ;
do {
if ( ( F_3 ( V_2 , V_252 ) & ( F_103 ( 3 ) | F_103 ( 4 ) ) ) == ( F_103 ( 3 ) | F_103 ( 4 ) ) )
goto V_30;
F_101 ( 1 ) ;
} while ( F_102 ( V_216 , V_245 ) );
if ( -- V_217 > 0 )
goto V_220;
F_7 ( V_19 L_22 ) ;
return - V_223 ;
V_30:
F_1 ( V_2 , V_253 , F_104 ( 3 ) | F_104 ( 4 ) ) ;
for ( V_206 = 0 ; V_206 < 4 ; V_206 ++ ) {
struct V_34 * V_35 = & V_2 -> V_35 [ V_206 ] ;
V_35 -> V_80 = V_254 + ( V_206 * 0x10 ) ;
V_35 -> V_255 = V_256 + ( V_206 * 0x10 ) ;
V_35 -> V_82 = V_257 + ( V_206 * 0x10 ) ;
V_35 -> V_99 = V_258 + ( V_206 * 0x10 ) ;
V_35 -> V_46 = V_259 + ( V_206 * 8 ) ;
V_35 -> V_55 = V_260 + ( V_206 * 8 ) ;
V_35 -> V_261 = V_262 + ( V_206 * 4 ) ;
V_35 -> V_52 = V_53 + ( V_206 * 4 ) ;
V_35 -> V_96 = V_263 + ( V_206 * 4 ) ;
V_35 -> V_94 = V_206 * V_93 ;
F_1 ( V_2 , V_35 -> V_52 ,
F_19 ( 31 ) |
F_20 ( 31 ) |
F_21 ( V_93 ) |
F_22 ( V_35 -> V_94 ) ) ;
}
V_2 -> V_84 = 0 ;
V_2 -> V_85 = 1 ;
V_2 -> V_86 = 10 ;
V_2 -> V_87 = 11 ;
V_2 -> V_35 [ 0 ] . V_41 = V_42 | F_19 ( 0 ) |
F_20 ( 1 ) |
F_21 ( V_93 ) |
F_22 ( V_2 -> V_35 [ 0 ] . V_94 ) ;
F_1 ( V_2 , V_2 -> V_35 [ 0 ] . V_52 , V_2 -> V_35 [ 0 ] . V_41 ) ;
F_1 ( V_2 , V_83 , ( V_2 -> V_84 << 0 ) |
( V_2 -> V_85 << 8 ) |
( V_2 -> V_86 << 16 ) |
( V_2 -> V_87 << 24 ) ) ;
F_1 ( V_2 , V_264 , 0 ) ;
F_1 ( V_2 , V_265 , 0 ) ;
F_1 ( V_2 , V_266 , V_267 ) ;
F_1 ( V_2 , V_199 , 0x7fffffff & ~ (
V_268 |
V_269 |
F_105 ( 0 ) |
F_105 ( 1 ) |
F_105 ( 2 ) |
F_105 ( 3 ) ) ) ;
F_79 ( V_2 -> V_198 ) ;
return 0 ;
}
static void F_106 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_270 , V_2 -> V_271 | V_272 ) ;
F_6 ( 100 ) ;
F_1 ( V_2 , V_270 , V_2 -> V_271 ) ;
}
static int F_107 ( struct V_273 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_274 -> V_9 ;
F_29 ( & V_2 -> V_37 ) ;
V_2 -> V_271 |= V_275 ;
V_2 -> V_276 = V_32 ;
if ( ! ( V_2 -> V_277 & V_278 ) ) {
F_106 ( V_2 ) ;
} else {
F_1 ( V_2 , V_270 , V_2 -> V_271 ) ;
}
F_30 ( & V_2 -> V_37 ) ;
return 0 ;
}
static int F_108 ( struct V_273 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_274 -> V_9 ;
F_29 ( & V_2 -> V_37 ) ;
V_2 -> V_271 &= ~ ( V_275 | V_279 ) ;
V_2 -> V_276 = NULL ;
if ( ! ( V_2 -> V_277 & V_278 ) ) {
F_106 ( V_2 ) ;
} else {
F_1 ( V_2 , V_270 , V_2 -> V_271 ) ;
}
V_2 -> V_277 &= ~ V_280 ;
F_30 ( & V_2 -> V_37 ) ;
return 0 ;
}
static int F_109 ( struct V_273 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_274 -> V_9 ;
F_29 ( & V_2 -> V_37 ) ;
V_2 -> V_277 |= V_278 ;
V_2 -> V_271 |= V_281 ;
V_2 -> V_282 = V_32 ;
if ( ! ( V_2 -> V_277 & V_280 ) ) {
F_106 ( V_2 ) ;
} else {
F_1 ( V_2 , V_270 , V_2 -> V_271 ) ;
}
F_30 ( & V_2 -> V_37 ) ;
return 0 ;
}
static int F_110 ( struct V_273 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_274 -> V_9 ;
F_29 ( & V_2 -> V_37 ) ;
V_2 -> V_271 &= ~ ( V_281 | V_283 ) ;
V_2 -> V_282 = NULL ;
if ( ! ( V_2 -> V_277 & V_280 ) ) {
F_106 ( V_2 ) ;
} else {
F_1 ( V_2 , V_270 , V_2 -> V_271 ) ;
}
V_2 -> V_277 &= ~ V_278 ;
F_30 ( & V_2 -> V_37 ) ;
return 0 ;
}
static void F_111 ( struct V_273 * V_32 , int V_284 )
{
unsigned long V_285 ;
struct V_1 * V_2 = V_32 -> V_274 -> V_9 ;
F_112 ( & V_2 -> V_37 , V_285 ) ;
if ( V_284 ) {
if ( ( V_2 -> V_271 & V_279 ) == 0 ) {
V_2 -> V_271 |= V_279 ;
F_1 ( V_2 , V_270 , V_2 -> V_271 ) ;
}
} else {
if ( V_2 -> V_271 & V_279 ) {
V_2 -> V_271 &= ~ V_279 ;
F_1 ( V_2 , V_270 , V_2 -> V_271 ) ;
}
}
F_113 ( & V_2 -> V_37 , V_285 ) ;
}
static void F_114 ( struct V_273 * V_32 , int V_284 )
{
unsigned long V_285 ;
struct V_1 * V_2 = V_32 -> V_274 -> V_9 ;
unsigned char V_286 ;
F_112 ( & V_2 -> V_37 , V_285 ) ;
if ( V_284 ) {
if ( ( V_2 -> V_271 & V_283 ) == 0 ) {
V_2 -> V_271 |= V_283 ;
while ( ( V_2 -> V_271 & V_283 ) &&
( F_3 ( V_2 , V_287 ) & V_288 ) == 0 ) {
if ( F_115 ( V_32 , & V_286 , 1 ) != 1 ) {
V_2 -> V_271 &= ~ V_283 ;
} else {
F_1 ( V_2 , V_289 , V_286 ) ;
}
}
F_1 ( V_2 , V_270 , V_2 -> V_271 ) ;
}
} else {
if ( V_2 -> V_271 & V_283 ) {
V_2 -> V_271 &= ~ V_283 ;
F_1 ( V_2 , V_270 , V_2 -> V_271 ) ;
}
}
F_113 ( & V_2 -> V_37 , V_285 ) ;
}
static int F_116 ( struct V_1 * V_2 , int V_103 ,
struct V_290 * * V_291 )
{
struct V_290 * V_274 ;
int V_107 ;
if ( V_291 )
* V_291 = NULL ;
if ( ( V_107 = F_117 ( V_2 -> V_108 , L_4 , V_103 , 1 , 1 , & V_274 ) ) < 0 )
return V_107 ;
strcpy ( V_274 -> V_114 , L_4 ) ;
F_118 ( V_274 , V_292 , & V_293 ) ;
F_118 ( V_274 , V_294 , & V_295 ) ;
V_274 -> V_113 |= V_296 | V_297 | V_298 ;
V_274 -> V_9 = V_2 ;
V_2 -> V_274 = V_274 ;
if ( V_291 )
* V_291 = V_274 ;
return 0 ;
}
static T_6 V_212 ( int V_198 , void * V_299 )
{
struct V_1 * V_2 = V_299 ;
unsigned int V_300 , V_35 , V_4 ;
struct V_34 * V_301 ;
if ( V_2 == NULL )
return V_302 ;
V_300 = F_3 ( V_2 , V_303 ) ;
if ( ( V_300 & 0x7fffffff ) == 0 ) {
F_1 ( V_2 , V_266 , V_267 ) ;
return V_302 ;
}
if ( V_300 & ( F_105 ( 0 ) | F_105 ( 1 ) | F_105 ( 2 ) | F_105 ( 3 ) ) ) {
for ( V_35 = 0 ; V_35 < 4 ; V_35 ++ )
if ( V_300 & F_105 ( V_35 ) ) {
V_301 = & V_2 -> V_35 [ V_35 ] ;
F_11 ( & V_2 -> V_37 ) ;
V_4 = F_3 ( V_2 , V_301 -> V_261 ) ;
V_301 -> V_75 ++ ;
if ( ( V_4 & V_304 ) && ! ( V_301 -> V_75 & 1 ) ) {
V_301 -> V_75 -- ;
V_2 -> V_152 ++ ;
F_12 ( & V_2 -> V_37 ) ;
continue;
}
if ( ( V_4 & V_305 ) && ( V_301 -> V_75 & 1 ) ) {
V_301 -> V_75 -- ;
V_2 -> V_153 ++ ;
F_12 ( & V_2 -> V_37 ) ;
continue;
}
F_12 ( & V_2 -> V_37 ) ;
F_119 ( V_301 -> V_32 ) ;
}
}
if ( ( V_300 & V_268 ) && V_2 -> V_274 ) {
unsigned char V_162 ;
F_11 ( & V_2 -> V_37 ) ;
while ( ( F_3 ( V_2 , V_287 ) & V_306 ) == 0 ) {
V_162 = F_3 ( V_2 , V_307 ) ;
if ( ( V_2 -> V_271 & V_279 ) == 0 )
continue;
F_120 ( V_2 -> V_276 , & V_162 , 1 ) ;
}
while ( ( F_3 ( V_2 , V_287 ) & V_288 ) == 0 ) {
if ( ( V_2 -> V_271 & V_283 ) == 0 )
break;
if ( F_115 ( V_2 -> V_282 , & V_162 , 1 ) != 1 ) {
V_2 -> V_271 &= ~ V_283 ;
F_1 ( V_2 , V_270 , V_2 -> V_271 ) ;
break;
}
F_1 ( V_2 , V_289 , V_162 ) ;
}
F_12 ( & V_2 -> V_37 ) ;
}
F_1 ( V_2 , V_266 , V_267 ) ;
return V_308 ;
}
static void F_121 ( struct V_309 * V_310 , unsigned short V_33 ,
unsigned char V_4 )
{
unsigned long V_285 ;
struct V_1 * V_2 = V_310 -> V_9 ;
void T_7 * V_311 ;
if ( V_33 & V_312 )
V_311 = V_2 -> V_5 + V_313 ;
else
V_311 = V_2 -> V_5 + V_314 ;
F_112 ( & V_310 -> V_37 , V_285 ) ;
F_2 ( ( unsigned int ) V_33 , V_311 ) ;
F_6 ( 10 ) ;
F_2 ( ( unsigned int ) V_4 , V_311 + 4 ) ;
F_6 ( 30 ) ;
F_113 ( & V_310 -> V_37 , V_285 ) ;
}
static int F_122 ( struct V_204 * V_116 ,
const struct V_315 * V_316 )
{
static int V_190 ;
struct V_138 * V_108 ;
struct V_1 * V_2 ;
struct V_309 * V_310 ;
int V_107 ;
if ( V_190 >= V_317 )
return - V_318 ;
if ( ! V_319 [ V_190 ] ) {
V_190 ++ ;
return - V_320 ;
}
V_107 = F_123 ( V_321 [ V_190 ] , V_322 [ V_190 ] , V_323 , 0 , & V_108 ) ;
if ( V_107 < 0 )
return V_107 ;
if ( ( V_107 = F_87 ( V_108 , V_116 , & V_2 , V_145 [ V_190 ] ) ) < 0 ) {
F_124 ( V_108 ) ;
return V_107 ;
}
V_108 -> V_9 = V_2 ;
if ( ( V_107 = F_49 ( V_2 ) ) < 0 ) {
F_124 ( V_108 ) ;
return V_107 ;
}
if ( ( V_107 = F_38 ( V_2 , 0 , NULL ) ) < 0 ) {
F_124 ( V_108 ) ;
return V_107 ;
}
if ( ( V_107 = F_116 ( V_2 , 0 , NULL ) ) < 0 ) {
F_124 ( V_108 ) ;
return V_107 ;
}
if ( ( V_107 = F_125 ( V_108 , V_324 , & V_310 ) ) < 0 ) {
F_124 ( V_108 ) ;
return V_107 ;
}
V_310 -> V_9 = V_2 ;
V_310 -> V_325 = F_121 ;
F_126 ( V_310 ) ;
if ( ( V_107 = F_127 ( V_310 , 0 , 1 , NULL ) ) < 0 ) {
F_124 ( V_108 ) ;
return V_107 ;
}
F_67 ( V_2 ) ;
strcpy ( V_108 -> V_326 , L_4 ) ;
strcpy ( V_108 -> V_327 , L_23 ) ;
sprintf ( V_108 -> V_328 , L_24 ,
V_108 -> V_327 ,
V_2 -> V_210 ,
V_2 -> V_198 ) ;
if ( ( V_107 = F_128 ( V_108 ) ) < 0 ) {
F_124 ( V_108 ) ;
return V_107 ;
}
F_129 ( V_116 , V_108 ) ;
V_190 ++ ;
return 0 ;
}
static void F_130 ( struct V_204 * V_116 )
{
F_124 ( F_131 ( V_116 ) ) ;
F_129 ( V_116 , NULL ) ;
}
static int F_132 ( struct V_103 * V_190 )
{
struct V_204 * V_116 = F_133 ( V_190 ) ;
struct V_138 * V_108 = F_134 ( V_190 ) ;
struct V_1 * V_2 = V_108 -> V_9 ;
T_8 V_329 ;
unsigned int V_330 ;
F_135 ( V_108 , V_331 ) ;
F_136 ( V_2 -> V_106 ) ;
F_137 ( V_2 -> V_7 ) ;
F_137 ( V_2 -> V_137 ) ;
V_329 = F_3 ( V_2 , V_200 ) ;
V_329 |= V_332 ;
F_1 ( V_2 , V_200 , V_329 ) ;
F_1 ( V_2 , V_266 , V_333 ) ;
for ( V_330 = 0 ; V_330 < F_138 ( V_334 ) ; V_330 ++ )
if ( V_334 [ V_330 ] )
V_2 -> V_335 [ V_330 ] = F_3 ( V_2 , V_334 [ V_330 ] ) ;
F_1 ( V_2 , V_237 , 0 ) ;
F_1 ( V_2 , V_201 , 0 ) ;
F_1 ( V_2 , V_200 , 0 ) ;
F_1 ( V_2 , V_238 , 0 ) ;
V_329 = F_3 ( V_2 , V_200 ) ;
V_329 &= ~ V_332 ;
F_1 ( V_2 , V_200 , V_329 ) ;
F_84 ( V_116 ) ;
F_139 ( V_116 ) ;
F_80 ( V_116 , V_336 ) ;
return 0 ;
}
static int F_140 ( struct V_103 * V_190 )
{
struct V_204 * V_116 = F_133 ( V_190 ) ;
struct V_138 * V_108 = F_134 ( V_190 ) ;
struct V_1 * V_2 = V_108 -> V_9 ;
unsigned int V_330 ;
T_8 V_329 ;
F_80 ( V_116 , V_337 ) ;
F_141 ( V_116 ) ;
if ( F_88 ( V_116 ) < 0 ) {
F_69 ( V_19 L_25
L_26 ) ;
F_142 ( V_108 ) ;
return - V_223 ;
}
F_91 ( V_116 ) ;
V_329 = F_3 ( V_2 , V_200 ) ;
V_329 |= V_332 ;
F_1 ( V_2 , V_200 , V_329 ) ;
F_96 ( V_2 ) ;
for ( V_330 = 0 ; V_330 < F_138 ( V_334 ) ; V_330 ++ )
if ( V_334 [ V_330 ] )
F_1 ( V_2 , V_334 [ V_330 ] , V_2 -> V_335 [ V_330 ] ) ;
F_143 ( V_2 -> V_7 ) ;
F_143 ( V_2 -> V_137 ) ;
V_329 = F_3 ( V_2 , V_200 ) ;
V_329 &= ~ V_332 ;
F_1 ( V_2 , V_200 , V_329 ) ;
F_135 ( V_108 , V_338 ) ;
return 0 ;
}
