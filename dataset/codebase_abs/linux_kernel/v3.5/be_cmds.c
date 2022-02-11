static inline void * F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . F_1 ;
}
static void F_2 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 . V_9 ;
T_1 V_10 = 0 ;
if ( F_3 ( V_5 ) )
return;
V_10 |= V_7 -> V_11 & V_12 ;
V_10 |= 1 << V_13 ;
F_4 () ;
F_5 ( V_10 , V_5 -> V_14 + V_15 ) ;
}
static inline bool F_6 ( struct V_16 * V_17 )
{
if ( V_17 -> V_18 != 0 ) {
V_17 -> V_18 = F_7 ( V_17 -> V_18 ) ;
F_8 ( ( V_17 -> V_18 & V_19 ) == 0 ) ;
return true ;
} else {
return false ;
}
}
static inline void F_9 ( struct V_16 * V_17 )
{
V_17 -> V_18 = 0 ;
}
static struct V_20 * F_10 ( T_1 V_21 , T_1 V_22 )
{
unsigned long V_23 ;
V_23 = V_22 ;
V_23 = ( ( V_23 << 16 ) << 16 ) | V_21 ;
return ( void * ) V_23 ;
}
static int F_11 ( struct V_4 * V_5 ,
struct V_16 * V_17 )
{
T_2 V_24 , V_25 ;
struct V_20 * V_26 ;
T_3 V_27 = 0 , V_28 = 0 ;
F_12 ( V_17 , 4 ) ;
V_24 = ( V_17 -> V_29 >> V_30 ) &
V_31 ;
V_26 = F_10 ( V_17 -> V_21 , V_17 -> V_22 ) ;
if ( V_26 ) {
V_27 = V_26 -> V_27 ;
V_28 = V_26 -> V_28 ;
}
if ( ( ( V_27 == V_32 ) ||
( V_27 == V_33 ) ) &&
( V_28 == V_34 ) ) {
V_5 -> V_35 = V_24 ;
F_13 ( & V_5 -> V_36 ) ;
}
if ( V_24 == V_37 ) {
if ( ( ( V_27 == V_38 ) ||
( V_27 == V_39 ) ) &&
( V_28 == V_40 ) ) {
F_14 ( V_5 ) ;
V_5 -> V_41 = false ;
}
if ( V_27 == V_42 &&
V_28 == V_34 ) {
struct V_43 * V_44 =
( void * ) V_26 ;
V_5 -> V_45 . V_46 =
V_44 -> V_47 ;
}
} else {
if ( V_27 == V_42 )
V_48 = 0 ;
if ( V_24 == V_49 ||
V_24 == V_50 )
goto V_51;
if ( V_24 == V_52 ) {
F_15 ( & V_5 -> V_53 -> V_54 ,
L_1 ,
V_27 , V_28 ) ;
} else {
V_25 = ( V_17 -> V_29 >> V_55 ) &
V_56 ;
F_16 ( & V_5 -> V_53 -> V_54 ,
L_2 ,
V_27 , V_28 , V_24 , V_25 ) ;
}
}
V_51:
return V_24 ;
}
static void F_17 ( struct V_4 * V_5 ,
struct V_57 * V_58 )
{
V_5 -> V_59 . V_60 = - 1 ;
if ( V_5 -> V_18 & V_61 )
F_18 ( V_5 , V_58 -> V_62 ) ;
}
static void F_19 ( struct V_4 * V_5 ,
struct V_63 * V_58 )
{
if ( V_58 -> V_64 ) {
V_5 -> V_65 = V_58 -> V_66 ;
V_5 -> V_67 &= ~ V_68 ;
V_5 -> V_67 =
V_58 -> V_69 << V_70 ;
}
}
static void F_20 ( struct V_4 * V_5 ,
struct V_71 * V_58 )
{
if ( V_58 -> V_72 == V_5 -> V_73 ) {
V_5 -> V_59 . V_60 = V_58 -> V_74 * 10 ;
}
}
static void F_21 ( struct V_4 * V_5 ,
struct V_75 * V_58 )
{
if ( V_58 -> V_76 )
V_5 -> V_77 = F_22 ( V_58 -> V_78 ) & V_79 ;
else
V_5 -> V_77 = 0 ;
}
static void F_23 ( struct V_4 * V_5 ,
T_1 V_80 , struct V_16 * V_58 )
{
T_3 V_81 = 0 ;
V_81 = ( V_80 >> V_82 ) &
V_83 ;
switch ( V_81 ) {
case V_84 :
F_19 ( V_5 ,
(struct V_63 * ) V_58 ) ;
break;
case V_85 :
F_20 ( V_5 ,
(struct V_71 * ) V_58 ) ;
break;
case V_86 :
F_21 ( V_5 ,
(struct V_75 * ) V_58 ) ;
break;
default:
F_15 ( & V_5 -> V_53 -> V_54 , L_3 ) ;
break;
}
}
static inline bool F_24 ( T_1 V_80 )
{
return ( ( V_80 >> V_87 ) &
V_88 ) ==
V_89 ;
}
static inline bool F_25 ( T_1 V_80 )
{
return ( ( ( V_80 >> V_87 ) &
V_88 ) ==
V_90 ) ;
}
static struct V_16 * F_26 ( struct V_4 * V_5 )
{
struct V_6 * V_91 = & V_5 -> V_8 . V_92 ;
struct V_16 * V_17 = F_27 ( V_91 ) ;
if ( F_6 ( V_17 ) ) {
F_28 ( V_91 ) ;
return V_17 ;
}
return NULL ;
}
void F_29 ( struct V_4 * V_5 )
{
F_30 ( & V_5 -> V_93 ) ;
F_31 ( V_5 , V_5 -> V_8 . V_92 . V_11 , true , 0 ) ;
V_5 -> V_8 . V_94 = true ;
F_32 ( & V_5 -> V_93 ) ;
}
void F_33 ( struct V_4 * V_5 )
{
V_5 -> V_8 . V_94 = false ;
}
int F_34 ( struct V_4 * V_5 )
{
struct V_16 * V_17 ;
int V_95 = 0 , V_29 = 0 ;
struct V_96 * V_8 = & V_5 -> V_8 ;
F_30 ( & V_5 -> V_93 ) ;
while ( ( V_17 = F_26 ( V_5 ) ) ) {
if ( V_17 -> V_18 & V_97 ) {
if ( F_24 ( V_17 -> V_18 ) )
F_17 ( V_5 ,
(struct V_57 * ) V_17 ) ;
else if ( F_25 ( V_17 -> V_18 ) )
F_23 ( V_5 ,
V_17 -> V_18 , V_17 ) ;
} else if ( V_17 -> V_18 & V_98 ) {
V_29 = F_11 ( V_5 , V_17 ) ;
F_35 ( & V_8 -> V_9 . V_99 ) ;
}
F_9 ( V_17 ) ;
V_95 ++ ;
}
if ( V_95 )
F_31 ( V_5 , V_8 -> V_92 . V_11 , V_8 -> V_94 , V_95 ) ;
F_32 ( & V_5 -> V_93 ) ;
return V_29 ;
}
static int F_36 ( struct V_4 * V_5 )
{
#define F_37 120000
int V_100 , V_29 = 0 ;
struct V_96 * V_8 = & V_5 -> V_8 ;
for ( V_100 = 0 ; V_100 < F_37 ; V_100 ++ ) {
if ( F_3 ( V_5 ) )
return - V_101 ;
V_29 = F_34 ( V_5 ) ;
if ( F_38 ( & V_8 -> V_9 . V_99 ) == 0 )
break;
F_39 ( 100 ) ;
}
if ( V_100 == F_37 ) {
F_16 ( & V_5 -> V_53 -> V_54 , L_4 ) ;
V_5 -> V_102 = true ;
return - V_101 ;
}
return V_29 ;
}
static int F_40 ( struct V_4 * V_5 )
{
int V_29 ;
struct V_1 * V_2 ;
struct V_96 * V_8 = & V_5 -> V_8 ;
T_2 V_103 = V_8 -> V_9 . V_104 ;
struct V_20 * V_44 ;
F_41 ( & V_103 , V_8 -> V_9 . V_105 ) ;
V_2 = F_42 ( & V_8 -> V_9 , V_103 ) ;
V_44 = F_10 ( V_2 -> V_21 , V_2 -> V_22 ) ;
F_2 ( V_5 ) ;
V_29 = F_36 ( V_5 ) ;
if ( V_29 == - V_101 )
goto V_106;
V_29 = V_44 -> V_29 ;
V_106:
return V_29 ;
}
static int F_43 ( struct V_4 * V_5 , void T_4 * V_14 )
{
int V_107 = 0 ;
T_1 V_108 ;
do {
if ( F_3 ( V_5 ) )
return - V_101 ;
V_108 = F_44 ( V_14 ) ;
if ( V_108 == 0xffffffff )
return - 1 ;
V_108 &= V_109 ;
if ( V_108 )
break;
if ( V_107 > 4000 ) {
F_16 ( & V_5 -> V_53 -> V_54 , L_4 ) ;
V_5 -> V_102 = true ;
F_45 ( V_5 ) ;
return - 1 ;
}
F_46 ( 1 ) ;
V_107 ++ ;
} while ( true );
return 0 ;
}
static int F_47 ( struct V_4 * V_5 )
{
int V_29 ;
T_1 V_10 = 0 ;
void T_4 * V_14 = V_5 -> V_14 + V_110 ;
struct V_111 * V_112 = & V_5 -> V_112 ;
struct V_113 * V_114 = V_112 -> V_115 ;
struct V_16 * V_17 = & V_114 -> V_17 ;
V_29 = F_43 ( V_5 , V_14 ) ;
if ( V_29 != 0 )
return V_29 ;
V_10 |= V_116 ;
V_10 |= ( F_48 ( V_112 -> V_117 ) >> 2 ) << 2 ;
F_5 ( V_10 , V_14 ) ;
V_29 = F_43 ( V_5 , V_14 ) ;
if ( V_29 != 0 )
return V_29 ;
V_10 = 0 ;
V_10 |= ( T_1 ) ( V_112 -> V_117 >> 4 ) << 2 ;
F_5 ( V_10 , V_14 ) ;
V_29 = F_43 ( V_5 , V_14 ) ;
if ( V_29 != 0 )
return V_29 ;
if ( F_6 ( V_17 ) ) {
V_29 = F_11 ( V_5 , & V_114 -> V_17 ) ;
F_9 ( V_17 ) ;
if ( V_29 )
return V_29 ;
} else {
F_16 ( & V_5 -> V_53 -> V_54 , L_5 ) ;
return - 1 ;
}
return 0 ;
}
static int F_49 ( struct V_4 * V_5 , T_2 * V_118 )
{
T_1 V_119 ;
if ( F_50 ( V_5 ) )
V_119 = F_44 ( V_5 -> V_14 + V_120 ) ;
else
V_119 = F_44 ( V_5 -> V_121 + V_122 ) ;
* V_118 = V_119 & V_123 ;
if ( ( V_119 >> V_124 ) & V_125 )
return - 1 ;
else
return 0 ;
}
int F_51 ( struct V_4 * V_5 )
{
T_2 V_118 ;
int V_29 , V_126 = 0 ;
struct V_127 * V_54 = & V_5 -> V_53 -> V_54 ;
do {
V_29 = F_49 ( V_5 , & V_118 ) ;
if ( V_29 ) {
F_16 ( V_54 , L_6 , V_118 ) ;
return - 1 ;
} else if ( V_118 != V_128 ) {
if ( F_52 ( 2000 ) ) {
F_16 ( V_54 , L_7 ) ;
return - V_129 ;
}
V_126 += 2 ;
} else {
return 0 ;
}
} while ( V_126 < 60 );
F_16 ( V_54 , L_8 , V_118 ) ;
return - 1 ;
}
static inline struct V_130 * F_53 ( struct V_1 * V_2 )
{
return & V_2 -> V_3 . V_131 [ 0 ] ;
}
static void F_54 ( struct V_132 * V_133 ,
T_3 V_28 , T_3 V_27 , int V_134 ,
struct V_1 * V_2 , struct V_111 * V_135 )
{
struct V_130 * V_136 ;
unsigned long V_23 = ( unsigned long ) V_133 ;
T_5 V_137 = V_23 ;
V_133 -> V_27 = V_27 ;
V_133 -> V_28 = V_28 ;
V_133 -> V_138 = F_55 ( V_134 - sizeof( * V_133 ) ) ;
V_133 -> V_139 = 0 ;
V_2 -> V_21 = V_137 & 0xFFFFFFFF ;
V_2 -> V_22 = F_48 ( V_137 ) ;
V_2 -> V_140 = V_134 ;
if ( V_135 ) {
V_2 -> V_141 |= ( 1 & V_142 ) <<
V_143 ;
V_136 = F_53 ( V_2 ) ;
V_136 -> V_144 = F_55 ( F_48 ( V_135 -> V_117 ) ) ;
V_136 -> V_145 = F_55 ( V_135 -> V_117 & 0xFFFFFFFF ) ;
V_136 -> V_105 = F_55 ( V_135 -> V_146 ) ;
} else
V_2 -> V_141 |= V_147 ;
F_56 ( V_2 , 8 ) ;
}
static void F_57 ( struct V_148 * V_149 , T_1 V_150 ,
struct V_111 * V_135 )
{
int V_100 , V_151 = F_58 ( F_59 ( V_135 -> V_115 , V_135 -> V_146 ) , V_150 ) ;
T_5 V_117 = ( T_5 ) V_135 -> V_117 ;
for ( V_100 = 0 ; V_100 < V_151 ; V_100 ++ ) {
V_149 [ V_100 ] . V_152 = F_55 ( V_117 & 0xFFFFFFFF ) ;
V_149 [ V_100 ] . V_153 = F_55 ( F_48 ( V_117 ) ) ;
V_117 += V_154 ;
}
}
static T_1 F_60 ( T_1 V_155 )
{
#define F_61 651042
const T_1 V_156 = 10 ;
T_1 V_157 ;
if ( V_155 == 0 )
V_157 = 0 ;
else {
T_1 V_158 = 1000000 / V_155 ;
if ( V_158 == 0 )
V_157 = 1023 ;
else {
V_157 = ( F_61 - V_158 ) * V_156 ;
V_157 /= V_158 ;
V_157 = ( V_157 + V_156 / 2 ) / V_156 ;
V_157 = F_58 ( V_157 , ( T_1 ) 1023 ) ;
}
}
return V_157 ;
}
static inline struct V_1 * F_62 ( struct V_4 * V_5 )
{
struct V_111 * V_112 = & V_5 -> V_112 ;
struct V_1 * V_2
= & ( (struct V_113 * ) ( V_112 -> V_115 ) ) -> V_2 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
return V_2 ;
}
static struct V_1 * F_63 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 . V_9 ;
struct V_1 * V_2 ;
if ( F_38 ( & V_7 -> V_99 ) >= V_7 -> V_105 ) {
F_16 ( & V_5 -> V_53 -> V_54 , L_9 ) ;
return NULL ;
}
V_2 = F_64 ( V_7 ) ;
F_65 ( V_7 ) ;
F_66 ( & V_7 -> V_99 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
return V_2 ;
}
int F_67 ( struct V_4 * V_5 )
{
T_3 * V_2 ;
int V_29 ;
if ( F_68 ( & V_5 -> V_159 ) )
return - 1 ;
V_2 = ( T_3 * ) F_62 ( V_5 ) ;
* V_2 ++ = 0xFF ;
* V_2 ++ = 0x12 ;
* V_2 ++ = 0x34 ;
* V_2 ++ = 0xFF ;
* V_2 ++ = 0xFF ;
* V_2 ++ = 0x56 ;
* V_2 ++ = 0x78 ;
* V_2 = 0xFF ;
V_29 = F_47 ( V_5 ) ;
F_69 ( & V_5 -> V_159 ) ;
return V_29 ;
}
int F_70 ( struct V_4 * V_5 )
{
T_3 * V_2 ;
int V_29 ;
if ( F_68 ( & V_5 -> V_159 ) )
return - 1 ;
V_2 = ( T_3 * ) F_62 ( V_5 ) ;
* V_2 ++ = 0xFF ;
* V_2 ++ = 0xAA ;
* V_2 ++ = 0xBB ;
* V_2 ++ = 0xFF ;
* V_2 ++ = 0xFF ;
* V_2 ++ = 0xCC ;
* V_2 ++ = 0xDD ;
* V_2 = 0xFF ;
V_29 = F_47 ( V_5 ) ;
F_69 ( & V_5 -> V_159 ) ;
return V_29 ;
}
int F_71 ( struct V_4 * V_5 ,
struct V_6 * V_160 , int V_161 )
{
struct V_1 * V_2 ;
struct V_162 * V_163 ;
struct V_111 * V_164 = & V_160 -> V_165 ;
int V_29 ;
if ( F_68 ( & V_5 -> V_159 ) )
return - 1 ;
V_2 = F_62 ( V_5 ) ;
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_167 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_168 = F_72 ( F_59 ( V_164 -> V_115 , V_164 -> V_146 ) ) ;
F_73 ( struct V_169 , V_64 , V_163 -> V_170 , 1 ) ;
F_73 ( struct V_169 , V_146 , V_163 -> V_170 , 0 ) ;
F_73 ( struct V_169 , V_171 , V_163 -> V_170 ,
F_74 ( V_160 -> V_105 / 256 ) ) ;
F_73 ( struct V_169 , V_172 , V_163 -> V_170 ,
F_60 ( V_161 ) ) ;
F_56 ( V_163 -> V_170 , sizeof( V_163 -> V_170 ) ) ;
F_57 ( V_163 -> V_149 , F_75 ( V_163 -> V_149 ) , V_164 ) ;
V_29 = F_47 ( V_5 ) ;
if ( ! V_29 ) {
struct V_173 * V_44 = F_1 ( V_2 ) ;
V_160 -> V_11 = F_22 ( V_44 -> V_174 ) ;
V_160 -> V_175 = true ;
}
F_69 ( & V_5 -> V_159 ) ;
return V_29 ;
}
int F_76 ( struct V_4 * V_5 , T_3 * V_176 ,
T_3 type , bool V_177 , T_1 V_178 , T_1 V_179 )
{
struct V_1 * V_2 ;
struct V_180 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_184 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> type = type ;
if ( V_177 ) {
V_163 -> V_177 = 1 ;
} else {
V_163 -> V_185 = F_72 ( ( T_2 ) V_178 ) ;
V_163 -> V_179 = F_55 ( V_179 ) ;
V_163 -> V_177 = 0 ;
}
V_29 = F_40 ( V_5 ) ;
if ( ! V_29 ) {
struct V_186 * V_44 = F_1 ( V_2 ) ;
memcpy ( V_176 , V_44 -> V_187 . V_23 , V_188 ) ;
}
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_77 ( struct V_4 * V_5 , T_3 * V_176 ,
T_1 V_185 , T_1 * V_179 , T_1 V_189 )
{
struct V_1 * V_2 ;
struct V_190 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_191 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_166 . V_189 = V_189 ;
V_163 -> V_185 = F_55 ( V_185 ) ;
memcpy ( V_163 -> V_192 , V_176 , V_188 ) ;
V_29 = F_40 ( V_5 ) ;
if ( ! V_29 ) {
struct V_193 * V_44 = F_1 ( V_2 ) ;
* V_179 = F_7 ( V_44 -> V_179 ) ;
}
V_183:
F_32 ( & V_5 -> V_181 ) ;
if ( V_29 == V_52 )
V_29 = - V_194 ;
return V_29 ;
}
int F_78 ( struct V_4 * V_5 , T_1 V_185 , int V_179 , T_1 V_195 )
{
struct V_1 * V_2 ;
struct V_196 * V_163 ;
int V_29 ;
if ( V_179 == - 1 )
return 0 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_197 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_166 . V_189 = V_195 ;
V_163 -> V_185 = F_55 ( V_185 ) ;
V_163 -> V_179 = F_55 ( V_179 ) ;
V_29 = F_40 ( V_5 ) ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_79 ( struct V_4 * V_5 , struct V_6 * V_92 ,
struct V_6 * V_160 , bool V_198 , int V_199 )
{
struct V_1 * V_2 ;
struct V_200 * V_163 ;
struct V_111 * V_164 = & V_92 -> V_165 ;
void * V_201 ;
int V_29 ;
if ( F_68 ( & V_5 -> V_159 ) )
return - 1 ;
V_2 = F_62 ( V_5 ) ;
V_163 = F_1 ( V_2 ) ;
V_201 = & V_163 -> V_170 ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_202 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_168 = F_72 ( F_59 ( V_164 -> V_115 , V_164 -> V_146 ) ) ;
if ( F_50 ( V_5 ) ) {
V_163 -> V_166 . V_139 = 2 ;
V_163 -> V_203 = 1 ;
F_73 ( struct V_204 , V_205 , V_201 ,
V_198 ) ;
F_73 ( struct V_204 , V_171 , V_201 ,
F_74 ( V_92 -> V_105 / 256 ) ) ;
F_73 ( struct V_204 , V_64 , V_201 , 1 ) ;
F_73 ( struct V_204 , V_206 ,
V_201 , 1 ) ;
F_73 ( struct V_204 , V_207 ,
V_201 , V_160 -> V_11 ) ;
} else {
F_73 ( struct V_208 , V_209 , V_201 ,
V_199 ) ;
F_73 ( struct V_208 , V_205 ,
V_201 , V_198 ) ;
F_73 ( struct V_208 , V_171 , V_201 ,
F_74 ( V_92 -> V_105 / 256 ) ) ;
F_73 ( struct V_208 , V_64 , V_201 , 1 ) ;
F_73 ( struct V_208 , V_206 , V_201 , 1 ) ;
F_73 ( struct V_208 , V_207 , V_201 , V_160 -> V_11 ) ;
}
F_56 ( V_201 , sizeof( V_163 -> V_170 ) ) ;
F_57 ( V_163 -> V_149 , F_75 ( V_163 -> V_149 ) , V_164 ) ;
V_29 = F_47 ( V_5 ) ;
if ( ! V_29 ) {
struct V_210 * V_44 = F_1 ( V_2 ) ;
V_92 -> V_11 = F_22 ( V_44 -> V_211 ) ;
V_92 -> V_175 = true ;
}
F_69 ( & V_5 -> V_159 ) ;
return V_29 ;
}
static T_1 F_80 ( int V_212 )
{
T_1 V_213 = F_81 ( V_212 ) ;
if ( V_213 == 16 )
V_213 = 0 ;
return V_213 ;
}
int F_82 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_92 )
{
struct V_1 * V_2 ;
struct V_214 * V_163 ;
struct V_111 * V_164 = & V_7 -> V_165 ;
void * V_201 ;
int V_29 ;
if ( F_68 ( & V_5 -> V_159 ) )
return - 1 ;
V_2 = F_62 ( V_5 ) ;
V_163 = F_1 ( V_2 ) ;
V_201 = & V_163 -> V_170 ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_215 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_168 = F_72 ( F_59 ( V_164 -> V_115 , V_164 -> V_146 ) ) ;
if ( F_50 ( V_5 ) ) {
V_163 -> V_166 . V_139 = 1 ;
V_163 -> V_211 = F_72 ( V_92 -> V_11 ) ;
F_73 ( struct V_216 , V_217 , V_201 ,
F_80 ( V_7 -> V_105 ) ) ;
F_73 ( struct V_216 , V_64 , V_201 , 1 ) ;
F_73 ( struct V_216 , V_218 ,
V_201 , V_92 -> V_11 ) ;
F_73 ( struct V_216 , V_219 ,
V_201 , 1 ) ;
} else {
F_73 ( struct V_220 , V_64 , V_201 , 1 ) ;
F_73 ( struct V_220 , V_217 , V_201 ,
F_80 ( V_7 -> V_105 ) ) ;
F_73 ( struct V_220 , V_211 , V_201 , V_92 -> V_11 ) ;
}
V_163 -> V_221 [ 0 ] = F_55 ( 0x00000022 ) ;
F_56 ( V_201 , sizeof( V_163 -> V_170 ) ) ;
F_57 ( V_163 -> V_149 , F_75 ( V_163 -> V_149 ) , V_164 ) ;
V_29 = F_47 ( V_5 ) ;
if ( ! V_29 ) {
struct V_222 * V_44 = F_1 ( V_2 ) ;
V_7 -> V_11 = F_22 ( V_44 -> V_11 ) ;
V_7 -> V_175 = true ;
}
F_69 ( & V_5 -> V_159 ) ;
return V_29 ;
}
int F_83 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_92 )
{
struct V_1 * V_2 ;
struct V_223 * V_163 ;
struct V_111 * V_164 = & V_7 -> V_165 ;
void * V_201 ;
int V_29 ;
if ( F_68 ( & V_5 -> V_159 ) )
return - 1 ;
V_2 = F_62 ( V_5 ) ;
V_163 = F_1 ( V_2 ) ;
V_201 = & V_163 -> V_170 ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_224 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_168 = F_72 ( F_59 ( V_164 -> V_115 , V_164 -> V_146 ) ) ;
F_73 ( struct V_220 , V_64 , V_201 , 1 ) ;
F_73 ( struct V_220 , V_217 , V_201 ,
F_80 ( V_7 -> V_105 ) ) ;
F_73 ( struct V_220 , V_211 , V_201 , V_92 -> V_11 ) ;
F_56 ( V_201 , sizeof( V_163 -> V_170 ) ) ;
F_57 ( V_163 -> V_149 , F_75 ( V_163 -> V_149 ) , V_164 ) ;
V_29 = F_47 ( V_5 ) ;
if ( ! V_29 ) {
struct V_222 * V_44 = F_1 ( V_2 ) ;
V_7 -> V_11 = F_22 ( V_44 -> V_11 ) ;
V_7 -> V_175 = true ;
}
F_69 ( & V_5 -> V_159 ) ;
return V_29 ;
}
int F_84 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_92 )
{
int V_29 ;
V_29 = F_82 ( V_5 , V_7 , V_92 ) ;
if ( V_29 && ! F_50 ( V_5 ) ) {
F_15 ( & V_5 -> V_53 -> V_54 , L_10
L_11
L_12 ) ;
V_29 = F_83 ( V_5 , V_7 , V_92 ) ;
}
return V_29 ;
}
int F_85 ( struct V_4 * V_5 ,
struct V_6 * V_225 ,
struct V_6 * V_92 )
{
struct V_1 * V_2 ;
struct V_226 * V_163 ;
struct V_111 * V_164 = & V_225 -> V_165 ;
void * V_201 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
V_201 = & V_163 -> V_170 ;
F_54 ( & V_163 -> V_166 , V_40 ,
V_227 , sizeof( * V_163 ) , V_2 , NULL ) ;
if ( F_50 ( V_5 ) ) {
V_163 -> V_166 . V_139 = 1 ;
F_73 ( struct V_228 , V_185 , V_201 ,
V_5 -> V_178 ) ;
}
V_163 -> V_168 = F_59 ( V_164 -> V_115 , V_164 -> V_146 ) ;
V_163 -> V_229 = V_230 ;
V_163 -> type = V_231 ;
F_73 ( struct V_228 , V_232 , V_201 ,
F_80 ( V_225 -> V_105 ) ) ;
F_73 ( struct V_228 , V_233 , V_201 , 1 ) ;
F_73 ( struct V_228 , V_234 , V_201 , V_92 -> V_11 ) ;
F_56 ( V_201 , sizeof( V_163 -> V_170 ) ) ;
F_57 ( V_163 -> V_149 , F_75 ( V_163 -> V_149 ) , V_164 ) ;
V_29 = F_40 ( V_5 ) ;
if ( ! V_29 ) {
struct V_235 * V_44 = F_1 ( V_2 ) ;
V_225 -> V_11 = F_22 ( V_44 -> V_236 ) ;
V_225 -> V_175 = true ;
}
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_86 ( struct V_4 * V_5 ,
struct V_6 * V_237 , T_2 V_211 , T_2 V_238 ,
T_1 V_185 , T_1 V_239 , T_3 * V_240 )
{
struct V_1 * V_2 ;
struct V_241 * V_163 ;
struct V_111 * V_164 = & V_237 -> V_165 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_40 ,
V_242 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_211 = F_72 ( V_211 ) ;
V_163 -> V_238 = F_81 ( V_238 ) - 1 ;
V_163 -> V_168 = 2 ;
F_57 ( V_163 -> V_149 , F_75 ( V_163 -> V_149 ) , V_164 ) ;
V_163 -> V_243 = F_55 ( V_185 ) ;
V_163 -> V_244 = F_72 ( V_245 ) ;
V_163 -> V_246 = F_55 ( V_239 ) ;
V_29 = F_40 ( V_5 ) ;
if ( ! V_29 ) {
struct V_247 * V_44 = F_1 ( V_2 ) ;
V_237 -> V_11 = F_22 ( V_44 -> V_11 ) ;
V_237 -> V_175 = true ;
* V_240 = V_44 -> V_240 ;
}
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_87 ( struct V_4 * V_5 , struct V_6 * V_9 ,
int V_248 )
{
struct V_1 * V_2 ;
struct V_249 * V_163 ;
T_3 V_250 = 0 , V_27 = 0 ;
int V_29 ;
if ( F_68 ( & V_5 -> V_159 ) )
return - 1 ;
V_2 = F_62 ( V_5 ) ;
V_163 = F_1 ( V_2 ) ;
switch ( V_248 ) {
case V_251 :
V_250 = V_34 ;
V_27 = V_252 ;
break;
case V_253 :
V_250 = V_34 ;
V_27 = V_254 ;
break;
case V_255 :
V_250 = V_40 ;
V_27 = V_256 ;
break;
case V_257 :
V_250 = V_40 ;
V_27 = V_258 ;
break;
case V_259 :
V_250 = V_34 ;
V_27 = V_260 ;
break;
default:
F_88 () ;
}
F_54 ( & V_163 -> V_166 , V_250 , V_27 , sizeof( * V_163 ) , V_2 ,
NULL ) ;
V_163 -> V_11 = F_72 ( V_9 -> V_11 ) ;
V_29 = F_47 ( V_5 ) ;
if ( ! V_29 )
V_9 -> V_175 = false ;
F_69 ( & V_5 -> V_159 ) ;
return V_29 ;
}
int F_89 ( struct V_4 * V_5 , struct V_6 * V_9 )
{
struct V_1 * V_2 ;
struct V_249 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_40 ,
V_258 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_11 = F_72 ( V_9 -> V_11 ) ;
V_29 = F_40 ( V_5 ) ;
if ( ! V_29 )
V_9 -> V_175 = false ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_90 ( struct V_4 * V_5 , T_1 V_261 , T_1 V_262 ,
T_3 * V_187 , T_1 * V_178 , T_1 * V_179 , T_1 V_189 )
{
struct V_1 * V_2 ;
struct V_263 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_264 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_166 . V_189 = V_189 ;
V_163 -> V_265 = F_55 ( V_261 ) ;
V_163 -> V_266 = F_55 ( V_262 ) ;
if ( V_187 )
memcpy ( V_163 -> V_176 , V_187 , V_188 ) ;
else
V_163 -> V_267 = true ;
V_29 = F_40 ( V_5 ) ;
if ( ! V_29 ) {
struct V_268 * V_44 = F_1 ( V_2 ) ;
* V_178 = F_7 ( V_44 -> V_243 ) ;
if ( V_187 )
* V_179 = F_7 ( V_44 -> V_179 ) ;
}
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_91 ( struct V_4 * V_5 , int V_243 , T_1 V_189 )
{
struct V_1 * V_2 ;
struct V_269 * V_163 ;
int V_29 ;
if ( V_243 == - 1 )
return 0 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_270 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_166 . V_189 = V_189 ;
V_163 -> V_243 = F_55 ( V_243 ) ;
V_29 = F_40 ( V_5 ) ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_92 ( struct V_4 * V_5 , struct V_111 * V_271 )
{
struct V_1 * V_2 ;
struct V_132 * V_166 ;
int V_29 = 0 ;
if ( F_93 ( V_5 -> V_272 , V_48 ) == 0 )
F_94 ( V_5 ) ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_166 = V_271 -> V_115 ;
F_54 ( V_166 , V_40 ,
V_38 , V_271 -> V_146 , V_2 , V_271 ) ;
if ( V_5 -> V_273 == V_274 )
V_166 -> V_139 = 1 ;
F_2 ( V_5 ) ;
V_5 -> V_41 = true ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_95 ( struct V_4 * V_5 ,
struct V_111 * V_271 )
{
struct V_1 * V_2 ;
struct V_275 * V_163 ;
int V_29 = 0 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = V_271 -> V_115 ;
F_54 ( & V_163 -> V_166 , V_40 ,
V_39 , V_271 -> V_146 , V_2 ,
V_271 ) ;
V_163 -> V_276 . V_277 . V_278 = F_72 ( V_5 -> V_279 ) ;
V_163 -> V_276 . V_277 . V_280 = 0 ;
F_2 ( V_5 ) ;
V_5 -> V_41 = true ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_96 ( struct V_4 * V_5 , T_3 * V_281 ,
T_2 * V_60 , T_3 * V_282 , T_1 V_195 )
{
struct V_1 * V_2 ;
struct V_283 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
if ( V_282 )
* V_282 = V_284 ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_285 , sizeof( * V_163 ) , V_2 , NULL ) ;
if ( V_5 -> V_273 == V_274 || F_50 ( V_5 ) )
V_163 -> V_166 . V_139 = 1 ;
V_163 -> V_166 . V_189 = V_195 ;
V_29 = F_40 ( V_5 ) ;
if ( ! V_29 ) {
struct V_286 * V_44 = F_1 ( V_2 ) ;
if ( V_44 -> V_281 != V_287 ) {
if ( V_60 )
* V_60 = F_22 ( V_44 -> V_60 ) ;
if ( V_281 )
* V_281 = V_44 -> V_281 ;
}
if ( V_282 )
* V_282 = V_44 -> V_288 ;
}
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_94 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_289 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_42 , sizeof( * V_163 ) ,
V_2 , NULL ) ;
F_2 ( V_5 ) ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_97 ( struct V_4 * V_5 , T_1 * V_290 )
{
struct V_1 * V_2 ;
struct V_291 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_292 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_293 = F_55 ( V_294 ) ;
V_29 = F_40 ( V_5 ) ;
if ( ! V_29 ) {
struct V_295 * V_44 = F_1 ( V_2 ) ;
if ( V_290 && V_44 -> V_290 )
* V_290 = F_7 ( V_44 -> V_290 ) -
sizeof( T_1 ) ;
}
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
void F_98 ( struct V_4 * V_5 , T_1 V_296 , void * V_297 )
{
struct V_111 V_298 ;
struct V_1 * V_2 ;
struct V_291 * V_163 ;
T_1 V_299 = 0 , V_300 , V_301 ,
V_302 = sizeof( T_1 ) , V_303 ;
int V_29 ;
if ( V_296 == 0 )
return;
V_300 = V_296 ;
V_298 . V_146 = sizeof( struct V_291 ) + 60 * 1024 ;
V_298 . V_115 = F_99 ( V_5 -> V_53 ,
V_298 . V_146 ,
& V_298 . V_117 ) ;
if ( ! V_298 . V_115 ) {
V_29 = - V_304 ;
F_16 ( & V_5 -> V_53 -> V_54 ,
L_13 ) ;
return;
}
F_30 ( & V_5 -> V_181 ) ;
while ( V_300 ) {
V_301 = F_58 ( V_300 , ( T_1 ) 60 * 1024 ) ;
V_300 -= V_301 ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = V_298 . V_115 ;
V_303 = sizeof( struct V_291 ) + V_301 ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_292 , V_303 , V_2 ,
& V_298 ) ;
V_163 -> V_293 = F_55 ( V_305 ) ;
V_163 -> V_306 = F_55 ( V_302 ) ;
V_163 -> V_307 = F_55 ( V_301 ) ;
V_163 -> V_308 = F_55 ( V_301 ) ;
V_29 = F_40 ( V_5 ) ;
if ( ! V_29 ) {
struct V_295 * V_44 = V_298 . V_115 ;
memcpy ( V_297 + V_299 ,
V_44 -> V_309 ,
F_7 ( V_44 -> V_307 ) ) ;
} else {
F_16 ( & V_5 -> V_53 -> V_54 , L_14 ) ;
goto V_183;
}
V_299 += V_301 ;
V_302 += V_301 ;
}
V_183:
F_100 ( V_5 -> V_53 , V_298 . V_146 ,
V_298 . V_115 ,
V_298 . V_117 ) ;
F_32 ( & V_5 -> V_181 ) ;
}
int F_101 ( struct V_4 * V_5 , char * V_310 ,
char * V_311 )
{
struct V_1 * V_2 ;
struct V_312 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_313 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_29 = F_40 ( V_5 ) ;
if ( ! V_29 ) {
struct V_314 * V_44 = F_1 ( V_2 ) ;
strcpy ( V_310 , V_44 -> V_315 ) ;
if ( V_311 )
strcpy ( V_311 , V_44 -> V_316 ) ;
}
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_102 ( struct V_4 * V_5 , T_1 V_174 , T_1 V_317 )
{
struct V_1 * V_2 ;
struct V_318 * V_163 ;
int V_29 = 0 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_319 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_320 = F_55 ( 1 ) ;
V_163 -> V_321 [ 0 ] . V_174 = F_55 ( V_174 ) ;
V_163 -> V_321 [ 0 ] . V_322 = 0 ;
V_163 -> V_321 [ 0 ] . V_323 = F_55 ( V_317 ) ;
F_2 ( V_5 ) ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_103 ( struct V_4 * V_5 , T_1 V_185 , T_2 * V_324 ,
T_1 V_95 , bool V_325 , bool V_326 )
{
struct V_1 * V_2 ;
struct V_327 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_328 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_243 = V_185 ;
V_163 -> V_326 = V_326 ;
V_163 -> V_325 = V_325 ;
V_163 -> V_329 = V_95 ;
if ( ! V_326 ) {
memcpy ( V_163 -> V_330 , V_324 ,
V_163 -> V_329 * sizeof( V_324 [ 0 ] ) ) ;
}
V_29 = F_40 ( V_5 ) ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_104 ( struct V_4 * V_5 , T_1 V_18 , T_1 V_331 )
{
struct V_1 * V_2 ;
struct V_111 * V_135 = & V_5 -> V_332 ;
struct V_333 * V_163 = V_135 -> V_115 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
memset ( V_163 , 0 , sizeof( * V_163 ) ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_334 , sizeof( * V_163 ) ,
V_2 , V_135 ) ;
V_163 -> V_185 = F_55 ( V_5 -> V_178 ) ;
if ( V_18 & V_335 ) {
V_163 -> V_336 = F_55 ( V_337 |
V_338 ) ;
if ( V_331 == V_339 )
V_163 -> V_340 = F_55 ( V_337 |
V_338 ) ;
} else if ( V_18 & V_341 ) {
V_163 -> V_336 = V_163 -> V_340 =
F_55 ( V_342 ) ;
} else {
struct V_343 * V_344 ;
int V_100 = 0 ;
V_163 -> V_336 = V_163 -> V_340 =
F_55 ( V_345 ) ;
V_163 -> V_336 |=
F_55 ( V_342 ) ;
V_163 -> V_346 = F_55 ( F_105 ( V_5 -> V_347 ) ) ;
F_106 (ha, adapter->netdev)
memcpy ( V_163 -> V_348 [ V_100 ++ ] . V_349 , V_344 -> V_23 , V_188 ) ;
}
V_29 = F_40 ( V_5 ) ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_107 ( struct V_4 * V_5 , T_1 V_350 , T_1 V_351 )
{
struct V_1 * V_2 ;
struct V_352 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_353 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_354 = F_72 ( ( T_2 ) V_350 ) ;
V_163 -> V_355 = F_72 ( ( T_2 ) V_351 ) ;
V_29 = F_40 ( V_5 ) ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_108 ( struct V_4 * V_5 , T_1 * V_350 , T_1 * V_351 )
{
struct V_1 * V_2 ;
struct V_356 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_357 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_29 = F_40 ( V_5 ) ;
if ( ! V_29 ) {
struct V_358 * V_44 =
F_1 ( V_2 ) ;
* V_350 = F_22 ( V_44 -> V_354 ) ;
* V_351 = F_22 ( V_44 -> V_355 ) ;
}
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_109 ( struct V_4 * V_5 , T_1 * V_73 ,
T_1 * V_359 , T_1 * V_360 )
{
struct V_1 * V_2 ;
struct V_361 * V_163 ;
int V_29 ;
if ( F_68 ( & V_5 -> V_159 ) )
return - 1 ;
V_2 = F_62 ( V_5 ) ;
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_362 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_29 = F_47 ( V_5 ) ;
if ( ! V_29 ) {
struct V_363 * V_44 = F_1 ( V_2 ) ;
* V_73 = F_7 ( V_44 -> V_364 ) ;
* V_359 = F_7 ( V_44 -> V_365 ) ;
* V_360 = F_7 ( V_44 -> V_366 ) ;
}
F_69 ( & V_5 -> V_159 ) ;
return V_29 ;
}
int F_110 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_132 * V_163 ;
int V_29 ;
if ( F_68 ( & V_5 -> V_159 ) )
return - 1 ;
V_2 = F_62 ( V_5 ) ;
V_163 = F_1 ( V_2 ) ;
F_54 ( V_163 , V_34 ,
V_367 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_29 = F_47 ( V_5 ) ;
F_69 ( & V_5 -> V_159 ) ;
return V_29 ;
}
int F_111 ( struct V_4 * V_5 , T_3 * V_368 , T_2 V_369 )
{
struct V_1 * V_2 ;
struct V_370 * V_163 ;
T_1 V_371 [ 10 ] = { 0x15d43fa5 , 0x2534685a , 0x5f87693a , 0x5668494e ,
0x33cf6a53 , 0x383334c6 , 0x76ac4257 , 0x59b242b2 ,
0x3ea83c02 , 0x4a110304 } ;
int V_29 ;
if ( F_68 ( & V_5 -> V_159 ) )
return - 1 ;
V_2 = F_62 ( V_5 ) ;
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_40 ,
V_372 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_185 = F_55 ( V_5 -> V_178 ) ;
V_163 -> V_373 = F_72 ( V_374 | V_375 |
V_376 | V_377 ) ;
V_163 -> V_378 = F_72 ( F_81 ( V_369 ) - 1 ) ;
memcpy ( V_163 -> V_379 , V_368 , V_369 ) ;
memcpy ( V_163 -> V_380 , V_371 , sizeof( V_371 ) ) ;
F_56 ( V_163 -> V_380 , sizeof( V_163 -> V_380 ) ) ;
V_29 = F_47 ( V_5 ) ;
F_69 ( & V_5 -> V_159 ) ;
return V_29 ;
}
int F_112 ( struct V_4 * V_5 , T_3 V_73 ,
T_3 V_381 , T_3 V_382 , T_3 V_383 )
{
struct V_1 * V_2 ;
struct V_384 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_385 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_73 = V_73 ;
V_163 -> V_386 = V_383 ;
V_163 -> V_387 = V_381 ;
V_163 -> V_388 = V_382 ;
V_29 = F_40 ( V_5 ) ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_113 ( struct V_4 * V_5 , T_3 V_73 , T_1 * V_383 )
{
struct V_1 * V_2 ;
struct V_389 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_390 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_73 = V_73 ;
V_29 = F_40 ( V_5 ) ;
if ( ! V_29 ) {
struct V_391 * V_44 =
F_1 ( V_2 ) ;
* V_383 = V_44 -> V_386 ;
}
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_114 ( struct V_4 * V_5 , struct V_111 * V_392 ,
T_1 V_393 , T_1 V_394 , const char * V_395 ,
T_1 * V_396 , T_3 * V_397 )
{
struct V_1 * V_2 ;
struct V_398 * V_163 ;
struct V_399 * V_44 ;
void * V_201 = NULL ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_5 -> V_35 = 0 ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_400;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_33 ,
sizeof( struct V_398 ) , V_2 ,
NULL ) ;
V_201 = & V_163 -> V_170 ;
F_73 ( struct V_401 ,
V_402 , V_201 , V_393 ) ;
if ( V_393 == 0 )
F_73 ( struct V_401 ,
V_403 , V_201 , 1 ) ;
else
F_73 ( struct V_401 ,
V_403 , V_201 , 0 ) ;
F_56 ( V_201 , sizeof( V_163 -> V_170 ) ) ;
V_163 -> V_404 = F_55 ( V_394 ) ;
strcpy ( V_163 -> V_405 , V_395 ) ;
V_163 -> V_406 = F_55 ( 1 ) ;
V_163 -> V_296 = F_55 ( V_393 ) ;
V_163 -> V_407 = F_55 ( ( V_392 -> V_117 +
sizeof( struct V_398 ) )
& 0xFFFFFFFF ) ;
V_163 -> V_408 = F_55 ( F_48 ( V_392 -> V_117 +
sizeof( struct V_398 ) ) ) ;
F_2 ( V_5 ) ;
F_32 ( & V_5 -> V_181 ) ;
if ( ! F_115 ( & V_5 -> V_36 ,
F_116 ( 30000 ) ) )
V_29 = - 1 ;
else
V_29 = V_5 -> V_35 ;
V_44 = F_1 ( V_2 ) ;
if ( ! V_29 )
* V_396 = F_7 ( V_44 -> V_409 ) ;
else
* V_397 = V_44 -> V_410 ;
return V_29 ;
V_400:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_117 ( struct V_4 * V_5 , struct V_111 * V_392 ,
T_1 V_393 , T_1 V_394 , const char * V_395 ,
T_1 * V_411 , T_1 * V_403 , T_3 * V_397 )
{
struct V_1 * V_2 ;
struct V_412 * V_163 ;
struct V_413 * V_44 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_400;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_414 ,
sizeof( struct V_412 ) , V_2 ,
NULL ) ;
V_163 -> V_415 = F_55 ( V_393 ) ;
V_163 -> V_416 = F_55 ( V_394 ) ;
strcpy ( V_163 -> V_405 , V_395 ) ;
V_163 -> V_406 = F_55 ( 1 ) ;
V_163 -> V_296 = F_55 ( V_393 ) ;
V_163 -> V_407 = F_55 ( ( V_392 -> V_117 & 0xFFFFFFFF ) ) ;
V_163 -> V_408 = F_55 ( F_48 ( V_392 -> V_117 ) ) ;
V_29 = F_40 ( V_5 ) ;
V_44 = F_1 ( V_2 ) ;
if ( ! V_29 ) {
* V_411 = F_7 ( V_44 -> V_417 ) ;
* V_403 = F_7 ( V_44 -> V_403 ) ;
} else {
* V_397 = V_44 -> V_410 ;
}
V_400:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_118 ( struct V_4 * V_5 , struct V_111 * V_392 ,
T_1 V_418 , T_1 V_419 , T_1 V_301 )
{
struct V_1 * V_2 ;
struct F_118 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_5 -> V_35 = 0 ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_400;
}
V_163 = V_392 -> V_115 ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_32 , V_392 -> V_146 , V_2 , V_392 ) ;
V_163 -> V_277 . V_420 = F_55 ( V_418 ) ;
V_163 -> V_277 . V_421 = F_55 ( V_419 ) ;
V_163 -> V_277 . V_422 = F_55 ( V_301 ) ;
F_2 ( V_5 ) ;
F_32 ( & V_5 -> V_181 ) ;
if ( ! F_115 ( & V_5 -> V_36 ,
F_116 ( 40000 ) ) )
V_29 = - 1 ;
else
V_29 = V_5 -> V_35 ;
return V_29 ;
V_400:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_119 ( struct V_4 * V_5 , T_3 * V_423 ,
int V_299 )
{
struct V_1 * V_2 ;
struct F_118 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_424 , sizeof( * V_163 ) + 4 , V_2 , NULL ) ;
V_163 -> V_277 . V_420 = F_55 ( V_425 ) ;
V_163 -> V_277 . V_421 = F_55 ( V_426 ) ;
V_163 -> V_277 . V_299 = F_55 ( V_299 ) ;
V_163 -> V_277 . V_422 = F_55 ( 0x4 ) ;
V_29 = F_40 ( V_5 ) ;
if ( ! V_29 )
memcpy ( V_423 , V_163 -> V_277 . V_427 , 4 ) ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_120 ( struct V_4 * V_5 , T_3 * V_187 ,
struct V_111 * V_271 )
{
struct V_1 * V_2 ;
struct V_428 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = V_271 -> V_115 ;
F_54 ( & V_163 -> V_166 , V_40 ,
V_429 , sizeof( * V_163 ) , V_2 ,
V_271 ) ;
memcpy ( V_163 -> V_430 , V_187 , V_188 ) ;
V_29 = F_40 ( V_5 ) ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_121 ( struct V_4 * V_5 , T_3 V_73 ,
T_3 V_431 , T_3 V_432 )
{
struct V_1 * V_2 ;
struct V_433 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_434 ,
V_435 , sizeof( * V_163 ) , V_2 ,
NULL ) ;
V_163 -> V_436 = V_73 ;
V_163 -> V_437 = V_73 ;
V_163 -> V_431 = V_431 ;
V_163 -> V_438 = V_432 ;
V_29 = F_40 ( V_5 ) ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_122 ( struct V_4 * V_5 , T_1 V_73 ,
T_1 V_431 , T_1 V_439 , T_1 V_440 , T_5 V_441 )
{
struct V_1 * V_2 ;
struct V_442 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_434 ,
V_443 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_166 . V_126 = F_55 ( 4 ) ;
V_163 -> V_441 = F_123 ( V_441 ) ;
V_163 -> V_436 = F_55 ( V_73 ) ;
V_163 -> V_437 = F_55 ( V_73 ) ;
V_163 -> V_439 = F_55 ( V_439 ) ;
V_163 -> V_440 = F_55 ( V_440 ) ;
V_163 -> V_431 = F_55 ( V_431 ) ;
V_29 = F_40 ( V_5 ) ;
if ( ! V_29 ) {
struct V_444 * V_44 = F_1 ( V_2 ) ;
V_29 = F_7 ( V_44 -> V_29 ) ;
}
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_124 ( struct V_4 * V_5 , T_5 V_441 ,
T_1 V_445 , struct V_111 * V_392 )
{
struct V_1 * V_2 ;
struct V_446 * V_163 ;
int V_29 ;
int V_100 , V_447 = 0 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = V_392 -> V_115 ;
F_54 ( & V_163 -> V_166 , V_434 ,
V_448 , V_392 -> V_146 , V_2 , V_392 ) ;
V_163 -> V_441 = F_123 ( V_441 ) ;
V_163 -> V_449 = F_55 ( V_445 ) ;
for ( V_100 = 0 ; V_100 < V_445 ; V_100 ++ ) {
V_163 -> V_450 [ V_100 ] = ( T_3 ) ( V_441 >> ( V_447 * 8 ) ) ;
V_447 ++ ;
if ( V_447 > 7 )
V_447 = 0 ;
}
V_29 = F_40 ( V_5 ) ;
if ( ! V_29 ) {
struct V_451 * V_44 ;
V_44 = V_392 -> V_115 ;
if ( ( memcmp ( V_44 -> V_452 , V_163 -> V_450 , V_445 ) != 0 ) ||
V_44 -> V_453 ) {
V_29 = - 1 ;
}
}
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_125 ( struct V_4 * V_5 ,
struct V_111 * V_271 )
{
struct V_1 * V_2 ;
struct V_454 * V_163 ;
struct V_130 * V_136 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = V_271 -> V_115 ;
V_136 = F_53 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_455 , sizeof( * V_163 ) , V_2 ,
V_271 ) ;
V_29 = F_40 ( V_5 ) ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_126 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_456 * V_163 ;
struct V_111 V_392 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_392 . V_146 = sizeof( struct V_456 ) ;
V_392 . V_115 = F_99 ( V_5 -> V_53 , V_392 . V_146 ,
& V_392 . V_117 ) ;
if ( ! V_392 . V_115 ) {
F_16 ( & V_5 -> V_53 -> V_54 , L_15 ) ;
V_29 = - V_304 ;
goto V_183;
}
V_163 = V_392 . V_115 ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_457 , sizeof( * V_163 ) ,
V_2 , & V_392 ) ;
V_29 = F_40 ( V_5 ) ;
if ( ! V_29 ) {
struct V_458 * V_459 =
V_392 . V_115 + sizeof( struct V_132 ) ;
V_5 -> V_59 . V_460 = F_22 ( V_459 -> V_460 ) ;
V_5 -> V_59 . V_461 =
F_22 ( V_459 -> V_461 ) ;
V_5 -> V_59 . V_462 =
F_22 ( V_459 -> V_462 ) ;
V_5 -> V_59 . V_463 =
F_22 ( V_459 -> V_463 ) ;
V_5 -> V_59 . V_464 =
F_7 ( V_459 -> V_464 ) ;
}
F_100 ( V_5 -> V_53 , V_392 . V_146 ,
V_392 . V_115 , V_392 . V_117 ) ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_127 ( struct V_4 * V_5 , T_1 V_465 , T_1 V_189 )
{
struct V_1 * V_2 ;
struct V_466 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_467 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_166 . V_189 = V_189 ;
V_163 -> V_468 = F_55 ( V_469 ) ;
V_163 -> V_470 = F_55 ( V_465 ) ;
V_29 = F_40 ( V_5 ) ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_128 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_471 * V_163 ;
struct V_472 * V_44 ;
int V_29 ;
int V_303 = F_129 ( sizeof( * V_163 ) , sizeof( * V_44 ) ) ;
struct V_473 * V_474 ;
struct V_111 V_475 ;
memset ( & V_475 , 0 , sizeof( struct V_111 ) ) ;
V_475 . V_146 = sizeof( struct V_472 ) ;
V_475 . V_115 = F_99 ( V_5 -> V_53 , V_475 . V_146 ,
& V_475 . V_117 ) ;
if ( ! V_475 . V_115 ) {
F_16 ( & V_5 -> V_53 -> V_54 ,
L_16 ) ;
return - V_304 ;
}
if ( F_68 ( & V_5 -> V_159 ) )
return - 1 ;
V_2 = F_62 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = V_475 . V_115 ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_476 , V_303 , V_2 ,
& V_475 ) ;
V_29 = F_47 ( V_5 ) ;
if ( ! V_29 ) {
V_474 = V_475 . V_115 + sizeof( struct V_20 ) ;
V_5 -> V_279 = V_474 -> V_477 . V_478 ;
}
V_183:
F_69 ( & V_5 -> V_159 ) ;
F_100 ( V_5 -> V_53 , V_475 . V_146 , V_475 . V_115 ,
V_475 . V_117 ) ;
return V_29 ;
}
int F_130 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_479 * V_163 ;
int V_29 ;
if ( F_68 ( & V_5 -> V_159 ) )
return - 1 ;
V_2 = F_62 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_480 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_481 = F_55 ( V_482 |
V_483 ) ;
V_163 -> V_261 = F_55 ( V_483 ) ;
V_29 = F_47 ( V_5 ) ;
if ( ! V_29 ) {
struct V_484 * V_44 = F_1 ( V_2 ) ;
V_5 -> V_485 = F_7 ( V_44 -> V_261 ) &
V_483 ;
}
V_183:
F_69 ( & V_5 -> V_159 ) ;
return V_29 ;
}
int F_131 ( struct V_4 * V_5 , T_1 V_189 ,
bool * V_486 , T_1 * V_179 , T_3 * V_187 )
{
struct V_1 * V_2 ;
struct V_487 * V_163 ;
int V_29 ;
int V_488 ;
struct V_111 V_489 ;
int V_100 ;
memset ( & V_489 , 0 , sizeof( struct V_111 ) ) ;
V_489 . V_146 = sizeof( struct V_490 ) ;
V_489 . V_115 = F_99 ( V_5 -> V_53 ,
V_489 . V_146 ,
& V_489 . V_117 ) ;
if ( ! V_489 . V_115 ) {
F_16 ( & V_5 -> V_53 -> V_54 ,
L_17 ) ;
return - V_304 ;
}
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_106;
}
V_163 = V_489 . V_115 ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_491 , sizeof( * V_163 ) ,
V_2 , & V_489 ) ;
V_163 -> V_166 . V_189 = V_189 ;
V_163 -> V_492 = V_493 ;
V_163 -> V_494 = 1 ;
V_29 = F_40 ( V_5 ) ;
if ( ! V_29 ) {
struct V_490 * V_44 =
V_489 . V_115 ;
V_488 = V_44 -> V_495 + V_44 -> V_496 ;
for ( V_100 = 0 ; V_100 < V_488 ; V_100 ++ ) {
struct V_497 * V_498 ;
T_2 V_499 ;
T_1 V_500 ;
V_498 = & V_44 -> V_501 [ V_100 ] ;
V_499 = F_22 ( V_498 -> V_499 ) ;
if ( V_499 == sizeof( T_1 ) ) {
* V_486 = true ;
V_500 = V_498 -> V_502 . V_503 . V_500 ;
* V_179 = F_7 ( V_500 ) ;
goto V_106;
}
}
* V_486 = false ;
memcpy ( V_187 , V_44 -> V_501 [ 0 ] . V_502 . V_504 ,
V_188 ) ;
}
V_106:
F_32 ( & V_5 -> V_181 ) ;
F_100 ( V_5 -> V_53 , V_489 . V_146 ,
V_489 . V_115 , V_489 . V_117 ) ;
return V_29 ;
}
int F_132 ( struct V_4 * V_5 , T_3 * V_505 ,
T_3 V_488 , T_1 V_189 )
{
struct V_1 * V_2 ;
struct V_506 * V_163 ;
int V_29 ;
struct V_111 V_392 ;
memset ( & V_392 , 0 , sizeof( struct V_111 ) ) ;
V_392 . V_146 = sizeof( struct V_506 ) ;
V_392 . V_115 = F_133 ( & V_5 -> V_53 -> V_54 , V_392 . V_146 ,
& V_392 . V_117 , V_507 ) ;
if ( ! V_392 . V_115 ) {
F_16 ( & V_5 -> V_53 -> V_54 , L_15 ) ;
return - V_304 ;
}
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = V_392 . V_115 ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_508 , sizeof( * V_163 ) ,
V_2 , & V_392 ) ;
V_163 -> V_166 . V_189 = V_189 ;
V_163 -> V_488 = V_488 ;
if ( V_488 )
memcpy ( V_163 -> V_187 , V_505 , V_188 * V_488 ) ;
V_29 = F_40 ( V_5 ) ;
V_183:
F_134 ( & V_5 -> V_53 -> V_54 , V_392 . V_146 ,
V_392 . V_115 , V_392 . V_117 ) ;
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_135 ( struct V_4 * V_5 , T_2 V_77 ,
T_1 V_189 , T_2 V_509 )
{
struct V_1 * V_2 ;
struct V_510 * V_163 ;
void * V_201 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
V_201 = & V_163 -> V_170 ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_511 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_166 . V_189 = V_189 ;
F_73 ( struct V_512 , V_243 , V_201 , V_509 ) ;
if ( V_77 ) {
F_73 ( struct V_512 , V_513 , V_201 , 1 ) ;
F_73 ( struct V_512 , V_77 , V_201 , V_77 ) ;
}
F_56 ( V_163 -> V_170 , sizeof( V_163 -> V_170 ) ) ;
V_29 = F_40 ( V_5 ) ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_136 ( struct V_4 * V_5 , T_2 * V_77 ,
T_1 V_189 , T_2 V_509 )
{
struct V_1 * V_2 ;
struct V_514 * V_163 ;
void * V_201 ;
int V_29 ;
T_2 V_515 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
V_201 = & V_163 -> V_170 ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_516 , sizeof( * V_163 ) , V_2 , NULL ) ;
V_163 -> V_166 . V_189 = V_189 ;
F_73 ( struct V_517 , V_243 , V_201 ,
V_509 ) ;
F_73 ( struct V_517 , V_513 , V_201 , 1 ) ;
F_56 ( V_163 -> V_170 , sizeof( V_163 -> V_170 ) ) ;
V_29 = F_40 ( V_5 ) ;
if ( ! V_29 ) {
struct V_518 * V_44 =
F_1 ( V_2 ) ;
F_12 ( & V_44 -> V_170 ,
sizeof( V_44 -> V_170 ) ) ;
V_515 = F_137 ( struct V_519 ,
V_77 , & V_44 -> V_170 ) ;
* V_77 = F_22 ( V_515 ) ;
}
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_138 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_520 * V_163 ;
int V_29 ;
int V_303 = sizeof( * V_163 ) ;
struct V_111 V_392 ;
memset ( & V_392 , 0 , sizeof( struct V_111 ) ) ;
V_392 . V_146 = sizeof( struct V_521 ) ;
V_392 . V_115 = F_99 ( V_5 -> V_53 , V_392 . V_146 ,
& V_392 . V_117 ) ;
if ( ! V_392 . V_115 ) {
F_16 ( & V_5 -> V_53 -> V_54 ,
L_16 ) ;
return - V_304 ;
}
if ( F_68 ( & V_5 -> V_159 ) )
return - 1 ;
V_2 = F_62 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = V_392 . V_115 ;
F_54 ( & V_163 -> V_166 , V_40 ,
V_429 ,
V_303 , V_2 , & V_392 ) ;
V_163 -> V_166 . V_139 = 1 ;
V_163 -> V_522 = V_523 ;
V_29 = F_47 ( V_5 ) ;
if ( ! V_29 ) {
struct V_521 * V_44 ;
V_44 = (struct V_521 * ) V_392 . V_115 ;
if ( V_44 -> V_166 . V_524 < V_303 ) {
V_29 = - 1 ;
goto V_183;
}
V_5 -> V_525 = V_44 -> V_526 ;
}
V_183:
F_69 ( & V_5 -> V_159 ) ;
F_100 ( V_5 -> V_53 , V_392 . V_146 , V_392 . V_115 , V_392 . V_117 ) ;
return V_29 ;
}
int F_139 ( struct V_4 * V_5 ,
struct V_111 * V_392 )
{
struct V_1 * V_2 ;
struct V_527 * V_163 ;
int V_29 ;
if ( F_68 ( & V_5 -> V_159 ) )
return - 1 ;
V_2 = F_62 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = V_392 -> V_115 ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_528 ,
V_392 -> V_146 , V_2 , V_392 ) ;
V_163 -> V_529 = F_55 ( 1 ) ;
V_29 = F_47 ( V_5 ) ;
V_183:
F_69 ( & V_5 -> V_159 ) ;
return V_29 ;
}
int F_140 ( struct V_4 * V_5 ,
struct V_111 * V_392 ,
struct V_530 * V_531 )
{
struct V_1 * V_2 ;
struct V_532 * V_163 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = V_392 -> V_115 ;
memcpy ( & V_163 -> V_533 , V_531 , sizeof( struct V_530 ) ) ;
F_54 ( & V_163 -> V_166 , V_34 ,
V_534 ,
V_392 -> V_146 , V_2 , V_392 ) ;
V_29 = F_40 ( V_5 ) ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
int F_141 ( void * V_535 , void * V_536 ,
int V_537 , T_2 * V_538 , T_2 * V_539 )
{
struct V_4 * V_5 = F_142 ( V_535 ) ;
struct V_1 * V_2 ;
struct V_132 * V_166 = (struct V_132 * ) V_536 ;
struct V_132 * V_163 ;
struct V_20 * V_44 ;
int V_29 ;
F_30 ( & V_5 -> V_181 ) ;
V_2 = F_63 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_182 ;
goto V_183;
}
V_163 = F_1 ( V_2 ) ;
V_44 = F_1 ( V_2 ) ;
F_54 ( V_163 , V_166 -> V_28 ,
V_166 -> V_27 , V_537 , V_2 , NULL ) ;
memcpy ( V_163 , V_536 , V_537 ) ;
F_56 ( V_163 , V_537 ) ;
V_29 = F_40 ( V_5 ) ;
if ( V_538 )
* V_538 = ( V_29 & 0xffff ) ;
if ( V_539 )
* V_539 = 0 ;
memcpy ( V_536 , V_44 , sizeof( * V_44 ) + V_44 -> V_524 ) ;
F_12 ( V_536 , sizeof( * V_44 ) + V_44 -> V_524 ) ;
V_183:
F_32 ( & V_5 -> V_181 ) ;
return V_29 ;
}
