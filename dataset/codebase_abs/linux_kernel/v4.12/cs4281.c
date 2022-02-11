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
static int F_38 ( struct V_1 * V_2 , int V_104 )
{
struct V_105 * V_106 ;
int V_107 ;
V_107 = F_39 ( V_2 -> V_19 , L_4 , V_104 , 1 , 1 , & V_106 ) ;
if ( V_107 < 0 )
return V_107 ;
F_40 ( V_106 , V_108 , & V_109 ) ;
F_40 ( V_106 , V_110 , & V_111 ) ;
V_106 -> V_9 = V_2 ;
V_106 -> V_112 = 0 ;
strcpy ( V_106 -> V_113 , L_4 ) ;
V_2 -> V_106 = V_106 ;
F_41 ( V_106 , V_114 ,
F_42 ( V_2 -> V_115 ) , 64 * 1024 , 512 * 1024 ) ;
return 0 ;
}
static int F_43 ( struct V_116 * V_117 ,
struct V_118 * V_119 )
{
V_119 -> type = V_120 ;
V_119 -> V_10 = 2 ;
V_119 -> V_121 . integer . V_122 = 0 ;
V_119 -> V_121 . integer . V_123 = V_124 ;
return 0 ;
}
static int F_44 ( struct V_116 * V_117 ,
struct V_125 * V_126 )
{
struct V_1 * V_2 = F_45 ( V_117 ) ;
int V_127 = ( V_117 -> V_128 >> 16 ) & 0xffff ;
int V_129 = V_117 -> V_128 & 0xffff ;
int V_130 , V_131 ;
V_130 = V_124 - ( F_3 ( V_2 , V_127 ) & V_124 ) ;
V_131 = V_124 - ( F_3 ( V_2 , V_129 ) & V_124 ) ;
V_126 -> V_121 . integer . V_121 [ 0 ] = V_130 ;
V_126 -> V_121 . integer . V_121 [ 1 ] = V_131 ;
return 0 ;
}
static int F_46 ( struct V_116 * V_117 ,
struct V_125 * V_126 )
{
struct V_1 * V_2 = F_45 ( V_117 ) ;
int V_132 = 0 ;
int V_127 = ( V_117 -> V_128 >> 16 ) & 0xffff ;
int V_129 = V_117 -> V_128 & 0xffff ;
int V_130 , V_131 ;
V_130 = V_124 - ( F_3 ( V_2 , V_127 ) & V_124 ) ;
V_131 = V_124 - ( F_3 ( V_2 , V_129 ) & V_124 ) ;
if ( V_126 -> V_121 . integer . V_121 [ 0 ] != V_130 ) {
V_130 = V_124 - ( V_126 -> V_121 . integer . V_121 [ 0 ] & V_124 ) ;
F_1 ( V_2 , V_127 , V_130 ) ;
V_132 = 1 ;
}
if ( V_126 -> V_121 . integer . V_121 [ 1 ] != V_131 ) {
V_131 = V_124 - ( V_126 -> V_121 . integer . V_121 [ 1 ] & V_124 ) ;
F_1 ( V_2 , V_129 , V_131 ) ;
V_132 = 1 ;
}
return V_132 ;
}
static void F_47 ( struct V_133 * V_134 )
{
struct V_1 * V_2 = V_134 -> V_9 ;
V_2 -> V_135 = NULL ;
}
static void F_48 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_9 ;
if ( V_7 -> V_17 )
V_2 -> V_136 = NULL ;
else
V_2 -> V_7 = NULL ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_137 * V_19 = V_2 -> V_19 ;
struct V_138 V_7 ;
int V_107 ;
static struct V_139 V_140 = {
. V_141 = F_5 ,
. V_142 = F_8 ,
} ;
if ( ( V_107 = V_133 ( V_19 , 0 , & V_140 , V_2 , & V_2 -> V_135 ) ) < 0 )
return V_107 ;
V_2 -> V_135 -> V_143 = F_47 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_9 = V_2 ;
V_7 . V_143 = F_48 ;
if ( ( V_107 = F_50 ( V_2 -> V_135 , & V_7 , & V_2 -> V_7 ) ) < 0 )
return V_107 ;
if ( V_2 -> V_144 ) {
V_7 . V_17 = 1 ;
if ( ( V_107 = F_50 ( V_2 -> V_135 , & V_7 , & V_2 -> V_136 ) ) < 0 )
return V_107 ;
}
if ( ( V_107 = F_51 ( V_19 , F_52 ( & V_145 , V_2 ) ) ) < 0 )
return V_107 ;
if ( ( V_107 = F_51 ( V_19 , F_52 ( & V_146 , V_2 ) ) ) < 0 )
return V_107 ;
return 0 ;
}
static void F_53 ( struct V_147 * V_148 ,
struct V_149 * V_150 )
{
struct V_1 * V_2 = V_148 -> V_9 ;
F_54 ( V_150 , L_5 ) ;
F_54 ( V_150 , L_6 , V_2 -> V_151 ) ;
F_54 ( V_150 , L_7 , V_2 -> V_152 ) ;
}
static T_2 F_55 ( struct V_147 * V_148 ,
void * V_153 ,
struct V_154 * V_154 , char T_3 * V_155 ,
T_4 V_10 , T_5 V_156 )
{
struct V_1 * V_2 = V_148 -> V_9 ;
if ( F_56 ( V_155 , V_2 -> V_5 + V_156 , V_10 ) )
return - V_157 ;
return V_10 ;
}
static T_2 F_57 ( struct V_147 * V_148 ,
void * V_153 ,
struct V_154 * V_154 , char T_3 * V_155 ,
T_4 V_10 , T_5 V_156 )
{
struct V_1 * V_2 = V_148 -> V_9 ;
if ( F_56 ( V_155 , V_2 -> V_158 + V_156 , V_10 ) )
return - V_157 ;
return V_10 ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_147 * V_148 ;
if ( ! F_59 ( V_2 -> V_19 , L_8 , & V_148 ) )
F_60 ( V_148 , V_2 , F_53 ) ;
if ( ! F_59 ( V_2 -> V_19 , L_9 , & V_148 ) ) {
V_148 -> V_159 = V_160 ;
V_148 -> V_9 = V_2 ;
V_148 -> V_161 . V_140 = & V_162 ;
V_148 -> V_163 = V_164 ;
}
if ( ! F_59 ( V_2 -> V_19 , L_10 , & V_148 ) ) {
V_148 -> V_159 = V_160 ;
V_148 -> V_9 = V_2 ;
V_148 -> V_161 . V_140 = & V_165 ;
V_148 -> V_163 = V_166 ;
}
}
static void F_61 ( struct V_167 * V_167 )
{
struct V_1 * V_2 = F_62 ( V_167 ) ;
if ( F_18 ( ! V_2 ) )
return;
F_1 ( V_2 , V_168 , 0xff ) ;
}
static unsigned char F_63 ( struct V_167 * V_167 )
{
struct V_1 * V_2 = F_62 ( V_167 ) ;
if ( F_18 ( ! V_2 ) )
return 0 ;
return F_3 ( V_2 , V_168 ) ;
}
static int F_64 ( struct V_167 * V_167 ,
int * V_169 , int * V_170 )
{
struct V_1 * V_2 = F_62 ( V_167 ) ;
unsigned V_171 , V_172 , V_173 ;
if ( F_18 ( ! V_2 ) )
return 0 ;
V_171 = F_3 ( V_2 , V_174 ) ;
V_172 = F_3 ( V_2 , V_175 ) ;
V_173 = F_3 ( V_2 , V_168 ) ;
* V_170 = ( ~ V_173 >> 4 ) & 0x0F ;
V_169 [ 0 ] = ( ( V_171 & V_176 ) >> V_177 ) & 0xFFFF ;
V_169 [ 1 ] = ( ( V_171 & V_178 ) >> V_179 ) & 0xFFFF ;
V_169 [ 2 ] = ( ( V_172 & V_180 ) >> V_181 ) & 0xFFFF ;
V_169 [ 3 ] = ( ( V_172 & V_182 ) >> V_183 ) & 0xFFFF ;
for ( V_173 = 0 ; V_173 < 4 ; ++ V_173 )
if ( V_169 [ V_173 ] == 0xFFFF ) V_169 [ V_173 ] = - 1 ;
return 0 ;
}
static int F_65 ( struct V_167 * V_167 , int V_184 )
{
switch ( V_184 ) {
#ifdef F_66
case V_185 :
return 0 ;
#endif
case V_186 :
return 0 ;
default:
return - 1 ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_167 * V_187 ;
V_2 -> V_167 = V_187 = F_68 () ;
if ( ! V_187 ) {
F_7 ( V_2 -> V_19 -> V_20 ,
L_11 ) ;
return - V_188 ;
}
F_69 ( V_187 , L_12 ) ;
F_70 ( V_187 , L_13 , F_71 ( V_2 -> V_115 ) ) ;
F_72 ( V_187 , & V_2 -> V_115 -> V_20 ) ;
V_187 -> V_189 = F_65 ;
V_187 -> V_142 = F_63 ;
V_187 -> V_190 = F_61 ;
V_187 -> V_191 = F_64 ;
F_73 ( V_187 , V_2 ) ;
F_1 ( V_2 , V_192 , 0xFF ) ;
F_1 ( V_2 , V_193 , V_194 ) ;
F_74 ( V_187 ) ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 )
{
if ( V_2 -> V_167 ) {
F_76 ( V_2 -> V_167 ) ;
V_2 -> V_167 = NULL ;
}
}
static inline int F_67 ( struct V_1 * V_2 ) { return - V_195 ; }
static inline void F_75 ( struct V_1 * V_2 ) { }
static int F_77 ( struct V_1 * V_2 )
{
F_75 ( V_2 ) ;
if ( V_2 -> V_196 >= 0 )
F_78 ( V_2 -> V_196 ) ;
F_1 ( V_2 , V_197 , 0x7fffffff ) ;
F_1 ( V_2 , V_198 , 0 ) ;
F_1 ( V_2 , V_199 , 0 ) ;
F_79 ( V_2 -> V_115 , V_200 ) ;
if ( V_2 -> V_196 >= 0 )
F_80 ( V_2 -> V_196 , V_2 ) ;
F_81 ( V_2 -> V_5 ) ;
F_81 ( V_2 -> V_158 ) ;
F_82 ( V_2 -> V_115 ) ;
F_83 ( V_2 -> V_115 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
static int F_85 ( struct V_201 * V_104 )
{
struct V_1 * V_2 = V_104 -> V_202 ;
return F_77 ( V_2 ) ;
}
static int F_86 ( struct V_137 * V_19 ,
struct V_203 * V_115 ,
struct V_1 * * V_204 ,
int V_144 )
{
struct V_1 * V_2 ;
unsigned int V_205 ;
int V_107 ;
static struct V_206 V_140 = {
. V_207 = F_85 ,
} ;
* V_204 = NULL ;
if ( ( V_107 = F_87 ( V_115 ) ) < 0 )
return V_107 ;
V_2 = F_88 ( sizeof( * V_2 ) , V_208 ) ;
if ( V_2 == NULL ) {
F_83 ( V_115 ) ;
return - V_188 ;
}
F_89 ( & V_2 -> V_38 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_115 = V_115 ;
V_2 -> V_196 = - 1 ;
F_90 ( V_115 ) ;
if ( V_144 < 0 || V_144 > 3 ) {
F_7 ( V_19 -> V_20 , L_14 , V_144 ) ;
V_144 = 0 ;
}
V_2 -> V_144 = V_144 ;
if ( ( V_107 = F_91 ( V_115 , L_4 ) ) < 0 ) {
F_84 ( V_2 ) ;
F_83 ( V_115 ) ;
return V_107 ;
}
V_2 -> V_209 = F_92 ( V_115 , 0 ) ;
V_2 -> V_210 = F_92 ( V_115 , 1 ) ;
V_2 -> V_5 = F_93 ( V_115 , 0 ) ;
V_2 -> V_158 = F_93 ( V_115 , 1 ) ;
if ( ! V_2 -> V_5 || ! V_2 -> V_158 ) {
F_77 ( V_2 ) ;
return - V_188 ;
}
if ( F_94 ( V_115 -> V_196 , V_211 , V_212 ,
V_213 , V_2 ) ) {
F_7 ( V_19 -> V_20 , L_15 , V_115 -> V_196 ) ;
F_77 ( V_2 ) ;
return - V_188 ;
}
V_2 -> V_196 = V_115 -> V_196 ;
V_205 = F_95 ( V_2 ) ;
if ( V_205 ) {
F_77 ( V_2 ) ;
return V_205 ;
}
if ( ( V_107 = F_96 ( V_19 , V_214 , V_2 , & V_140 ) ) < 0 ) {
F_77 ( V_2 ) ;
return V_107 ;
}
F_58 ( V_2 ) ;
* V_204 = V_2 ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 )
{
unsigned int V_205 ;
unsigned long V_215 ;
int V_216 = 2 ;
V_205 = F_3 ( V_2 , V_217 ) ;
if ( V_205 & V_218 )
F_1 ( V_2 , V_217 , V_205 & ~ V_218 ) ;
V_219:
V_205 = F_3 ( V_2 , V_220 ) ;
if ( V_205 != V_221 ) {
F_1 ( V_2 , V_220 , V_221 ) ;
V_205 = F_3 ( V_2 , V_220 ) ;
if ( V_205 != V_221 ) {
F_7 ( V_2 -> V_19 -> V_20 ,
L_16 , V_205 ) ;
return - V_222 ;
}
}
F_1 ( V_2 , V_223 , 0x4281 ) ;
if ( ( V_205 = F_3 ( V_2 , V_224 ) ) != ( V_225 | V_226 ) ) {
F_7 ( V_2 -> V_19 -> V_20 ,
L_17 , V_205 ) ;
return - V_222 ;
}
if ( ( V_205 = F_3 ( V_2 , V_227 ) ) != ( V_228 | V_229 ) ) {
F_7 ( V_2 -> V_19 -> V_20 ,
L_18 , V_205 ) ;
return - V_222 ;
}
F_1 ( V_2 , V_199 , V_230 | V_231 |
V_232 | V_233 |
V_234 | V_235 ) ;
F_1 ( V_2 , V_198 , 0 ) ;
F_1 ( V_2 , V_236 , 0 ) ;
F_1 ( V_2 , V_13 , 0 ) ;
F_6 ( 50 ) ;
F_1 ( V_2 , V_237 , 0 ) ;
F_6 ( 50 ) ;
F_1 ( V_2 , V_237 , V_238 ) ;
F_97 ( 50 ) ;
if ( V_2 -> V_144 )
F_1 ( V_2 , V_237 , V_238 | V_239 ) ;
F_1 ( V_2 , V_236 ,
( V_2 -> V_144 ? F_98 ( V_2 -> V_144 ) : F_98 ( 1 ) ) |
V_240 | V_241 ) ;
F_1 ( V_2 , V_198 , V_242 ) ;
F_97 ( 50 ) ;
F_1 ( V_2 , V_198 , V_243 | V_242 ) ;
V_215 = V_244 + V_245 ;
do {
if ( F_3 ( V_2 , V_198 ) & V_246 )
goto V_247;
F_99 ( 1 ) ;
} while ( F_100 ( V_215 , V_244 ) );
F_7 ( V_2 -> V_19 -> V_20 , L_19 ) ;
return - V_222 ;
V_247:
F_1 ( V_2 , V_13 , V_16 ) ;
V_215 = V_244 + V_245 ;
do {
if ( F_3 ( V_2 , V_29 ) & V_248 )
goto V_26;
F_99 ( 1 ) ;
} while ( F_100 ( V_215 , V_244 ) );
F_7 ( V_2 -> V_19 -> V_20 ,
L_20 ,
F_3 ( V_2 , V_29 ) ) ;
return - V_222 ;
V_26:
if ( V_2 -> V_144 ) {
V_215 = V_244 + V_245 ;
do {
if ( F_3 ( V_2 , V_28 ) & V_248 )
goto V_249;
F_99 ( 1 ) ;
} while ( F_100 ( V_215 , V_244 ) );
F_101 ( V_2 -> V_19 -> V_20 ,
L_21 ) ;
V_2 -> V_144 = 0 ;
V_249: ;
}
F_1 ( V_2 , V_13 , V_15 | V_16 ) ;
V_215 = V_244 + V_245 ;
do {
if ( ( F_3 ( V_2 , V_250 ) & ( F_102 ( 3 ) | F_102 ( 4 ) ) ) == ( F_102 ( 3 ) | F_102 ( 4 ) ) )
goto V_31;
F_99 ( 1 ) ;
} while ( F_100 ( V_215 , V_244 ) );
if ( -- V_216 > 0 )
goto V_219;
F_7 ( V_2 -> V_19 -> V_20 , L_22 ) ;
return - V_222 ;
V_31:
F_1 ( V_2 , V_251 , F_103 ( 3 ) | F_103 ( 4 ) ) ;
for ( V_205 = 0 ; V_205 < 4 ; V_205 ++ ) {
struct V_35 * V_36 = & V_2 -> V_36 [ V_205 ] ;
V_36 -> V_81 = V_252 + ( V_205 * 0x10 ) ;
V_36 -> V_253 = V_254 + ( V_205 * 0x10 ) ;
V_36 -> V_83 = V_255 + ( V_205 * 0x10 ) ;
V_36 -> V_100 = V_256 + ( V_205 * 0x10 ) ;
V_36 -> V_47 = V_257 + ( V_205 * 8 ) ;
V_36 -> V_56 = V_258 + ( V_205 * 8 ) ;
V_36 -> V_259 = V_260 + ( V_205 * 4 ) ;
V_36 -> V_53 = V_54 + ( V_205 * 4 ) ;
V_36 -> V_97 = V_261 + ( V_205 * 4 ) ;
V_36 -> V_95 = V_205 * V_94 ;
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
F_1 ( V_2 , V_262 , 0 ) ;
F_1 ( V_2 , V_263 , 0 ) ;
F_1 ( V_2 , V_264 , V_265 ) ;
F_1 ( V_2 , V_197 , 0x7fffffff & ~ (
V_266 |
V_267 |
F_104 ( 0 ) |
F_104 ( 1 ) |
F_104 ( 2 ) |
F_104 ( 3 ) ) ) ;
F_78 ( V_2 -> V_196 ) ;
return 0 ;
}
static void F_105 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_268 , V_2 -> V_269 | V_270 ) ;
F_6 ( 100 ) ;
F_1 ( V_2 , V_268 , V_2 -> V_269 ) ;
}
static int F_106 ( struct V_271 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_272 -> V_9 ;
F_29 ( & V_2 -> V_38 ) ;
V_2 -> V_269 |= V_273 ;
V_2 -> V_274 = V_33 ;
if ( ! ( V_2 -> V_275 & V_276 ) ) {
F_105 ( V_2 ) ;
} else {
F_1 ( V_2 , V_268 , V_2 -> V_269 ) ;
}
F_30 ( & V_2 -> V_38 ) ;
return 0 ;
}
static int F_107 ( struct V_271 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_272 -> V_9 ;
F_29 ( & V_2 -> V_38 ) ;
V_2 -> V_269 &= ~ ( V_273 | V_277 ) ;
V_2 -> V_274 = NULL ;
if ( ! ( V_2 -> V_275 & V_276 ) ) {
F_105 ( V_2 ) ;
} else {
F_1 ( V_2 , V_268 , V_2 -> V_269 ) ;
}
V_2 -> V_275 &= ~ V_278 ;
F_30 ( & V_2 -> V_38 ) ;
return 0 ;
}
static int F_108 ( struct V_271 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_272 -> V_9 ;
F_29 ( & V_2 -> V_38 ) ;
V_2 -> V_275 |= V_276 ;
V_2 -> V_269 |= V_279 ;
V_2 -> V_280 = V_33 ;
if ( ! ( V_2 -> V_275 & V_278 ) ) {
F_105 ( V_2 ) ;
} else {
F_1 ( V_2 , V_268 , V_2 -> V_269 ) ;
}
F_30 ( & V_2 -> V_38 ) ;
return 0 ;
}
static int F_109 ( struct V_271 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_272 -> V_9 ;
F_29 ( & V_2 -> V_38 ) ;
V_2 -> V_269 &= ~ ( V_279 | V_281 ) ;
V_2 -> V_280 = NULL ;
if ( ! ( V_2 -> V_275 & V_278 ) ) {
F_105 ( V_2 ) ;
} else {
F_1 ( V_2 , V_268 , V_2 -> V_269 ) ;
}
V_2 -> V_275 &= ~ V_276 ;
F_30 ( & V_2 -> V_38 ) ;
return 0 ;
}
static void F_110 ( struct V_271 * V_33 , int V_282 )
{
unsigned long V_283 ;
struct V_1 * V_2 = V_33 -> V_272 -> V_9 ;
F_111 ( & V_2 -> V_38 , V_283 ) ;
if ( V_282 ) {
if ( ( V_2 -> V_269 & V_277 ) == 0 ) {
V_2 -> V_269 |= V_277 ;
F_1 ( V_2 , V_268 , V_2 -> V_269 ) ;
}
} else {
if ( V_2 -> V_269 & V_277 ) {
V_2 -> V_269 &= ~ V_277 ;
F_1 ( V_2 , V_268 , V_2 -> V_269 ) ;
}
}
F_112 ( & V_2 -> V_38 , V_283 ) ;
}
static void F_113 ( struct V_271 * V_33 , int V_282 )
{
unsigned long V_283 ;
struct V_1 * V_2 = V_33 -> V_272 -> V_9 ;
unsigned char V_284 ;
F_111 ( & V_2 -> V_38 , V_283 ) ;
if ( V_282 ) {
if ( ( V_2 -> V_269 & V_281 ) == 0 ) {
V_2 -> V_269 |= V_281 ;
while ( ( V_2 -> V_269 & V_281 ) &&
( F_3 ( V_2 , V_285 ) & V_286 ) == 0 ) {
if ( F_114 ( V_33 , & V_284 , 1 ) != 1 ) {
V_2 -> V_269 &= ~ V_281 ;
} else {
F_1 ( V_2 , V_287 , V_284 ) ;
}
}
F_1 ( V_2 , V_268 , V_2 -> V_269 ) ;
}
} else {
if ( V_2 -> V_269 & V_281 ) {
V_2 -> V_269 &= ~ V_281 ;
F_1 ( V_2 , V_268 , V_2 -> V_269 ) ;
}
}
F_112 ( & V_2 -> V_38 , V_283 ) ;
}
static int F_115 ( struct V_1 * V_2 , int V_104 )
{
struct V_288 * V_272 ;
int V_107 ;
if ( ( V_107 = F_116 ( V_2 -> V_19 , L_4 , V_104 , 1 , 1 , & V_272 ) ) < 0 )
return V_107 ;
strcpy ( V_272 -> V_113 , L_4 ) ;
F_117 ( V_272 , V_289 , & V_290 ) ;
F_117 ( V_272 , V_291 , & V_292 ) ;
V_272 -> V_112 |= V_293 | V_294 | V_295 ;
V_272 -> V_9 = V_2 ;
V_2 -> V_272 = V_272 ;
return 0 ;
}
static T_6 V_211 ( int V_196 , void * V_296 )
{
struct V_1 * V_2 = V_296 ;
unsigned int V_297 , V_36 , V_4 ;
struct V_35 * V_298 ;
if ( V_2 == NULL )
return V_299 ;
V_297 = F_3 ( V_2 , V_300 ) ;
if ( ( V_297 & 0x7fffffff ) == 0 ) {
F_1 ( V_2 , V_264 , V_265 ) ;
return V_299 ;
}
if ( V_297 & ( F_104 ( 0 ) | F_104 ( 1 ) | F_104 ( 2 ) | F_104 ( 3 ) ) ) {
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ )
if ( V_297 & F_104 ( V_36 ) ) {
V_298 = & V_2 -> V_36 [ V_36 ] ;
F_11 ( & V_2 -> V_38 ) ;
V_4 = F_3 ( V_2 , V_298 -> V_259 ) ;
V_298 -> V_76 ++ ;
if ( ( V_4 & V_301 ) && ! ( V_298 -> V_76 & 1 ) ) {
V_298 -> V_76 -- ;
V_2 -> V_151 ++ ;
F_12 ( & V_2 -> V_38 ) ;
continue;
}
if ( ( V_4 & V_302 ) && ( V_298 -> V_76 & 1 ) ) {
V_298 -> V_76 -- ;
V_2 -> V_152 ++ ;
F_12 ( & V_2 -> V_38 ) ;
continue;
}
F_12 ( & V_2 -> V_38 ) ;
F_118 ( V_298 -> V_33 ) ;
}
}
if ( ( V_297 & V_266 ) && V_2 -> V_272 ) {
unsigned char V_161 ;
F_11 ( & V_2 -> V_38 ) ;
while ( ( F_3 ( V_2 , V_285 ) & V_303 ) == 0 ) {
V_161 = F_3 ( V_2 , V_304 ) ;
if ( ( V_2 -> V_269 & V_277 ) == 0 )
continue;
F_119 ( V_2 -> V_274 , & V_161 , 1 ) ;
}
while ( ( F_3 ( V_2 , V_285 ) & V_286 ) == 0 ) {
if ( ( V_2 -> V_269 & V_281 ) == 0 )
break;
if ( F_114 ( V_2 -> V_280 , & V_161 , 1 ) != 1 ) {
V_2 -> V_269 &= ~ V_281 ;
F_1 ( V_2 , V_268 , V_2 -> V_269 ) ;
break;
}
F_1 ( V_2 , V_287 , V_161 ) ;
}
F_12 ( & V_2 -> V_38 ) ;
}
F_1 ( V_2 , V_264 , V_265 ) ;
return V_305 ;
}
static void F_120 ( struct V_306 * V_307 , unsigned short V_34 ,
unsigned char V_4 )
{
unsigned long V_283 ;
struct V_1 * V_2 = V_307 -> V_9 ;
void T_7 * V_308 ;
if ( V_34 & V_309 )
V_308 = V_2 -> V_5 + V_310 ;
else
V_308 = V_2 -> V_5 + V_311 ;
F_111 ( & V_307 -> V_38 , V_283 ) ;
F_2 ( ( unsigned int ) V_34 , V_308 ) ;
F_6 ( 10 ) ;
F_2 ( ( unsigned int ) V_4 , V_308 + 4 ) ;
F_6 ( 30 ) ;
F_112 ( & V_307 -> V_38 , V_283 ) ;
}
static int F_121 ( struct V_203 * V_115 ,
const struct V_312 * V_313 )
{
static int V_20 ;
struct V_137 * V_19 ;
struct V_1 * V_2 ;
struct V_306 * V_307 ;
int V_107 ;
if ( V_20 >= V_314 )
return - V_315 ;
if ( ! V_316 [ V_20 ] ) {
V_20 ++ ;
return - V_317 ;
}
V_107 = F_122 ( & V_115 -> V_20 , V_318 [ V_20 ] , V_319 [ V_20 ] , V_320 ,
0 , & V_19 ) ;
if ( V_107 < 0 )
return V_107 ;
if ( ( V_107 = F_86 ( V_19 , V_115 , & V_2 , V_144 [ V_20 ] ) ) < 0 ) {
F_123 ( V_19 ) ;
return V_107 ;
}
V_19 -> V_9 = V_2 ;
if ( ( V_107 = F_49 ( V_2 ) ) < 0 ) {
F_123 ( V_19 ) ;
return V_107 ;
}
if ( ( V_107 = F_38 ( V_2 , 0 ) ) < 0 ) {
F_123 ( V_19 ) ;
return V_107 ;
}
if ( ( V_107 = F_115 ( V_2 , 0 ) ) < 0 ) {
F_123 ( V_19 ) ;
return V_107 ;
}
if ( ( V_107 = F_124 ( V_19 , V_321 , & V_307 ) ) < 0 ) {
F_123 ( V_19 ) ;
return V_107 ;
}
V_307 -> V_9 = V_2 ;
V_307 -> V_322 = F_120 ;
F_125 ( V_307 ) ;
if ( ( V_107 = F_126 ( V_307 , 0 , 1 , NULL ) ) < 0 ) {
F_123 ( V_19 ) ;
return V_107 ;
}
F_67 ( V_2 ) ;
strcpy ( V_19 -> V_323 , L_4 ) ;
strcpy ( V_19 -> V_324 , L_23 ) ;
sprintf ( V_19 -> V_325 , L_24 ,
V_19 -> V_324 ,
V_2 -> V_209 ,
V_2 -> V_196 ) ;
if ( ( V_107 = F_127 ( V_19 ) ) < 0 ) {
F_123 ( V_19 ) ;
return V_107 ;
}
F_128 ( V_115 , V_19 ) ;
V_20 ++ ;
return 0 ;
}
static void F_129 ( struct V_203 * V_115 )
{
F_123 ( F_130 ( V_115 ) ) ;
}
static int F_131 ( struct V_104 * V_20 )
{
struct V_137 * V_19 = F_132 ( V_20 ) ;
struct V_1 * V_2 = V_19 -> V_9 ;
T_8 V_326 ;
unsigned int V_327 ;
F_133 ( V_19 , V_328 ) ;
F_134 ( V_2 -> V_106 ) ;
F_135 ( V_2 -> V_7 ) ;
F_135 ( V_2 -> V_136 ) ;
V_326 = F_3 ( V_2 , V_198 ) ;
V_326 |= V_329 ;
F_1 ( V_2 , V_198 , V_326 ) ;
F_1 ( V_2 , V_264 , V_330 ) ;
for ( V_327 = 0 ; V_327 < F_136 ( V_331 ) ; V_327 ++ )
if ( V_331 [ V_327 ] )
V_2 -> V_332 [ V_327 ] = F_3 ( V_2 , V_331 [ V_327 ] ) ;
F_1 ( V_2 , V_236 , 0 ) ;
F_1 ( V_2 , V_199 , 0 ) ;
F_1 ( V_2 , V_198 , 0 ) ;
F_1 ( V_2 , V_237 , 0 ) ;
V_326 = F_3 ( V_2 , V_198 ) ;
V_326 &= ~ V_329 ;
F_1 ( V_2 , V_198 , V_326 ) ;
return 0 ;
}
static int F_137 ( struct V_104 * V_20 )
{
struct V_137 * V_19 = F_132 ( V_20 ) ;
struct V_1 * V_2 = V_19 -> V_9 ;
unsigned int V_327 ;
T_8 V_326 ;
V_326 = F_3 ( V_2 , V_198 ) ;
V_326 |= V_329 ;
F_1 ( V_2 , V_198 , V_326 ) ;
F_95 ( V_2 ) ;
for ( V_327 = 0 ; V_327 < F_136 ( V_331 ) ; V_327 ++ )
if ( V_331 [ V_327 ] )
F_1 ( V_2 , V_331 [ V_327 ] , V_2 -> V_332 [ V_327 ] ) ;
F_138 ( V_2 -> V_7 ) ;
F_138 ( V_2 -> V_136 ) ;
V_326 = F_3 ( V_2 , V_198 ) ;
V_326 &= ~ V_329 ;
F_1 ( V_2 , V_198 , V_326 ) ;
F_133 ( V_19 , V_333 ) ;
return 0 ;
}
