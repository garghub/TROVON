static bool F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
int V_5 ;
int V_6 = sizeof( V_7 ) / sizeof( struct V_8 ) ;
T_2 V_9 = V_2 -> V_9 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
if ( V_3 == V_7 [ V_5 ] . V_3 &&
V_4 == V_7 [ V_5 ] . V_4 )
if ( ! ( V_9 & V_7 [ V_5 ] . V_10 ) )
return false ;
return true ;
}
static inline void * F_2 ( struct V_11 * V_12 )
{
return V_12 -> V_13 . F_2 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 . V_17 ;
T_2 V_18 = 0 ;
if ( F_4 ( V_2 ) )
return;
V_18 |= V_15 -> V_19 & V_20 ;
V_18 |= 1 << V_21 ;
F_5 () ;
F_6 ( V_18 , V_2 -> V_22 + V_23 ) ;
}
static inline bool F_7 ( struct V_24 * V_25 )
{
T_2 V_26 ;
if ( V_25 -> V_26 != 0 ) {
V_26 = F_8 ( V_25 -> V_26 ) ;
if ( V_26 & V_27 ) {
V_25 -> V_26 = V_26 ;
return true ;
}
}
return false ;
}
static inline void F_9 ( struct V_24 * V_25 )
{
V_25 -> V_26 = 0 ;
}
static struct V_28 * F_10 ( T_2 V_29 , T_2 V_30 )
{
unsigned long V_31 ;
V_31 = V_30 ;
V_31 = ( ( V_31 << 16 ) << 16 ) | V_29 ;
return ( void * ) V_31 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
T_3 V_32 , V_33 ;
struct V_28 * V_34 ;
T_1 V_3 = 0 , V_4 = 0 ;
F_12 ( V_25 , 4 ) ;
V_32 = ( V_25 -> V_35 >> V_36 ) &
V_37 ;
V_34 = F_10 ( V_25 -> V_29 , V_25 -> V_30 ) ;
if ( V_34 ) {
V_3 = V_34 -> V_3 ;
V_4 = V_34 -> V_4 ;
}
if ( ( ( V_3 == V_38 ) ||
( V_3 == V_39 ) ) &&
( V_4 == V_40 ) ) {
V_2 -> V_41 = V_32 ;
F_13 ( & V_2 -> V_42 ) ;
}
if ( V_32 == V_43 ) {
if ( ( ( V_3 == V_44 ) ||
( V_3 == V_45 ) ) &&
( V_4 == V_46 ) ) {
F_14 ( V_2 ) ;
V_2 -> V_47 = false ;
}
if ( V_3 == V_48 &&
V_4 == V_40 ) {
struct V_49 * V_50 =
( void * ) V_34 ;
V_2 -> V_51 . V_52 =
V_50 -> V_53 ;
}
} else {
if ( V_3 == V_48 )
V_2 -> V_54 = 0 ;
if ( V_32 == V_55 ||
V_32 == V_56 )
goto V_57;
if ( V_32 == V_58 ) {
F_15 ( & V_2 -> V_59 -> V_60 ,
L_1 ,
V_3 , V_4 ) ;
} else {
V_33 = ( V_25 -> V_35 >> V_61 ) &
V_62 ;
F_16 ( & V_2 -> V_59 -> V_60 ,
L_2 ,
V_3 , V_4 , V_32 , V_33 ) ;
}
}
V_57:
return V_32 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
V_2 -> V_65 . V_66 = - 1 ;
if ( F_18 ( V_2 ) &&
! ( V_64 -> V_67 & V_68 ) )
return;
if ( V_2 -> V_26 & V_69 )
F_19 ( V_2 , V_64 -> V_67 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_70 * V_64 )
{
if ( V_64 -> V_71 ) {
V_2 -> V_72 = V_64 -> V_73 ;
V_2 -> V_74 &= ~ V_75 ;
V_2 -> V_74 =
V_64 -> V_76 << V_77 ;
}
}
static void F_21 ( struct V_1 * V_2 ,
struct V_78 * V_64 )
{
if ( V_2 -> V_65 . V_66 >= 0 &&
V_64 -> V_79 == V_2 -> V_80 )
V_2 -> V_65 . V_66 = F_22 ( V_64 -> V_81 ) * 10 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_82 * V_64 )
{
if ( V_64 -> V_83 )
V_2 -> V_84 = F_22 ( V_64 -> V_85 ) & V_86 ;
else
V_2 -> V_84 = 0 ;
}
static void F_24 ( struct V_1 * V_2 ,
T_2 V_87 , struct V_24 * V_64 )
{
T_1 V_88 = 0 ;
V_88 = ( V_87 >> V_89 ) &
V_90 ;
switch ( V_88 ) {
case V_91 :
F_20 ( V_2 ,
(struct V_70 * ) V_64 ) ;
break;
case V_92 :
F_21 ( V_2 ,
(struct V_78 * ) V_64 ) ;
break;
case V_93 :
F_23 ( V_2 ,
(struct V_82 * ) V_64 ) ;
break;
default:
F_15 ( & V_2 -> V_59 -> V_60 , L_3 ) ;
break;
}
}
static inline bool F_25 ( T_2 V_87 )
{
return ( ( V_87 >> V_94 ) &
V_95 ) ==
V_96 ;
}
static inline bool F_26 ( T_2 V_87 )
{
return ( ( ( V_87 >> V_94 ) &
V_95 ) ==
V_97 ) ;
}
static struct V_24 * F_27 ( struct V_1 * V_2 )
{
struct V_14 * V_98 = & V_2 -> V_16 . V_99 ;
struct V_24 * V_25 = F_28 ( V_98 ) ;
if ( F_7 ( V_25 ) ) {
F_29 ( V_98 ) ;
return V_25 ;
}
return NULL ;
}
void F_30 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_100 ) ;
F_32 ( V_2 , V_2 -> V_16 . V_99 . V_19 , true , 0 ) ;
V_2 -> V_16 . V_101 = true ;
F_33 ( & V_2 -> V_100 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_100 ) ;
V_2 -> V_16 . V_101 = false ;
F_32 ( V_2 , V_2 -> V_16 . V_99 . V_19 , false , 0 ) ;
F_33 ( & V_2 -> V_100 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
int V_102 = 0 , V_35 = 0 ;
struct V_103 * V_16 = & V_2 -> V_16 ;
F_36 ( & V_2 -> V_100 ) ;
while ( ( V_25 = F_27 ( V_2 ) ) ) {
if ( V_25 -> V_26 & V_104 ) {
if ( F_25 ( V_25 -> V_26 ) )
F_17 ( V_2 ,
(struct V_63 * ) V_25 ) ;
else if ( F_26 ( V_25 -> V_26 ) )
F_24 ( V_2 ,
V_25 -> V_26 , V_25 ) ;
} else if ( V_25 -> V_26 & V_105 ) {
V_35 = F_11 ( V_2 , V_25 ) ;
F_37 ( & V_16 -> V_17 . V_106 ) ;
}
F_9 ( V_25 ) ;
V_102 ++ ;
}
if ( V_102 )
F_32 ( V_2 , V_16 -> V_99 . V_19 , V_16 -> V_101 , V_102 ) ;
F_38 ( & V_2 -> V_100 ) ;
return V_35 ;
}
static int F_39 ( struct V_1 * V_2 )
{
#define F_40 120000
int V_5 , V_35 = 0 ;
struct V_103 * V_16 = & V_2 -> V_16 ;
for ( V_5 = 0 ; V_5 < F_40 ; V_5 ++ ) {
if ( F_4 ( V_2 ) )
return - V_107 ;
F_41 () ;
V_35 = F_35 ( V_2 ) ;
F_42 () ;
if ( F_43 ( & V_16 -> V_17 . V_106 ) == 0 )
break;
F_44 ( 100 ) ;
}
if ( V_5 == F_40 ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_4 ) ;
V_2 -> V_108 = true ;
return - V_107 ;
}
return V_35 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_35 ;
struct V_11 * V_12 ;
struct V_103 * V_16 = & V_2 -> V_16 ;
T_3 V_109 = V_16 -> V_17 . V_110 ;
struct V_28 * V_50 ;
F_46 ( & V_109 , V_16 -> V_17 . V_111 ) ;
V_12 = F_47 ( & V_16 -> V_17 , V_109 ) ;
V_50 = F_10 ( V_12 -> V_29 , V_12 -> V_30 ) ;
F_3 ( V_2 ) ;
V_35 = F_39 ( V_2 ) ;
if ( V_35 == - V_107 )
goto V_112;
V_35 = V_50 -> V_35 ;
V_112:
return V_35 ;
}
static int F_48 ( struct V_1 * V_2 , void T_4 * V_22 )
{
int V_113 = 0 ;
T_2 V_114 ;
do {
if ( F_4 ( V_2 ) )
return - V_107 ;
V_114 = F_49 ( V_22 ) ;
if ( V_114 == 0xffffffff )
return - 1 ;
V_114 &= V_115 ;
if ( V_114 )
break;
if ( V_113 > 4000 ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_4 ) ;
V_2 -> V_108 = true ;
F_50 ( V_2 ) ;
return - 1 ;
}
F_51 ( 1 ) ;
V_113 ++ ;
} while ( true );
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_35 ;
T_2 V_18 = 0 ;
void T_4 * V_22 = V_2 -> V_22 + V_116 ;
struct V_117 * V_118 = & V_2 -> V_118 ;
struct V_119 * V_120 = V_118 -> V_121 ;
struct V_24 * V_25 = & V_120 -> V_25 ;
V_35 = F_48 ( V_2 , V_22 ) ;
if ( V_35 != 0 )
return V_35 ;
V_18 |= V_122 ;
V_18 |= ( F_53 ( V_118 -> V_123 ) >> 2 ) << 2 ;
F_6 ( V_18 , V_22 ) ;
V_35 = F_48 ( V_2 , V_22 ) ;
if ( V_35 != 0 )
return V_35 ;
V_18 = 0 ;
V_18 |= ( T_2 ) ( V_118 -> V_123 >> 4 ) << 2 ;
F_6 ( V_18 , V_22 ) ;
V_35 = F_48 ( V_2 , V_22 ) ;
if ( V_35 != 0 )
return V_35 ;
if ( F_7 ( V_25 ) ) {
V_35 = F_11 ( V_2 , & V_120 -> V_25 ) ;
F_9 ( V_25 ) ;
if ( V_35 )
return V_35 ;
} else {
F_16 ( & V_2 -> V_59 -> V_60 , L_5 ) ;
return - 1 ;
}
return 0 ;
}
static T_3 F_54 ( struct V_1 * V_2 )
{
T_2 V_124 ;
if ( F_55 ( V_2 ) )
V_124 = F_49 ( V_2 -> V_125 + V_126 ) ;
else
F_56 ( V_2 -> V_59 ,
V_127 , & V_124 ) ;
return V_124 & V_128 ;
}
int F_57 ( struct V_1 * V_2 )
{
#define F_58 30
T_2 V_129 ;
int V_35 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < F_58 ; V_5 ++ ) {
V_129 = F_49 ( V_2 -> V_22 + V_130 ) ;
if ( V_129 & V_131 )
break;
F_51 ( 1000 ) ;
}
if ( V_5 == F_58 )
V_35 = - 1 ;
return V_35 ;
}
static bool F_59 ( struct V_1 * V_2 )
{
T_2 V_129 = 0 , V_132 = 0 , V_133 = 0 ;
V_129 = F_49 ( V_2 -> V_22 + V_130 ) ;
if ( V_129 & V_134 ) {
V_132 = F_49 ( V_2 -> V_22 +
V_135 ) ;
V_133 = F_49 ( V_2 -> V_22 +
V_136 ) ;
if ( V_132 == V_137 &&
V_133 == V_138 )
return true ;
}
return false ;
}
int F_60 ( struct V_1 * V_2 )
{
int V_35 ;
T_2 V_129 , V_139 , V_140 ;
bool V_141 ;
V_141 = F_59 ( V_2 ) ;
if ( V_141 )
return - 1 ;
V_35 = F_57 ( V_2 ) ;
if ( ! V_35 ) {
V_129 = F_49 ( V_2 -> V_22 + V_130 ) ;
V_139 = V_129 & V_134 ;
V_140 = V_129 & V_142 ;
if ( V_139 && V_140 ) {
F_6 ( V_143 ,
V_2 -> V_22 + V_144 ) ;
V_35 = F_57 ( V_2 ) ;
V_129 = F_49 ( V_2 -> V_22 +
V_130 ) ;
V_129 &= ( V_134 |
V_142 ) ;
if ( V_35 || V_129 )
V_35 = - 1 ;
} else if ( V_139 || V_140 ) {
V_35 = - 1 ;
}
}
V_141 = F_59 ( V_2 ) ;
if ( V_35 == - 1 && ! V_141 )
V_2 -> V_145 = true ;
return V_35 ;
}
int F_61 ( struct V_1 * V_2 )
{
T_3 V_146 ;
int V_35 , V_147 = 0 ;
struct V_148 * V_60 = & V_2 -> V_59 -> V_60 ;
if ( F_18 ( V_2 ) ) {
V_35 = F_57 ( V_2 ) ;
return V_35 ;
}
do {
V_146 = F_54 ( V_2 ) ;
if ( V_146 == V_149 )
return 0 ;
F_62 ( V_60 , L_6 ,
V_147 ) ;
if ( F_63 ( 2000 ) ) {
F_16 ( V_60 , L_7 ) ;
return - V_150 ;
}
V_147 += 2 ;
} while ( V_147 < 60 );
F_16 ( V_60 , L_8 , V_146 ) ;
return - 1 ;
}
static inline struct V_151 * F_64 ( struct V_11 * V_12 )
{
return & V_12 -> V_13 . V_152 [ 0 ] ;
}
static void F_65 ( struct V_153 * V_154 ,
T_1 V_4 , T_1 V_3 , int V_155 ,
struct V_11 * V_12 , struct V_117 * V_156 )
{
struct V_151 * V_157 ;
unsigned long V_31 = ( unsigned long ) V_154 ;
T_5 V_158 = V_31 ;
V_154 -> V_3 = V_3 ;
V_154 -> V_4 = V_4 ;
V_154 -> V_159 = F_66 ( V_155 - sizeof( * V_154 ) ) ;
V_154 -> V_160 = 0 ;
V_12 -> V_29 = V_158 & 0xFFFFFFFF ;
V_12 -> V_30 = F_53 ( V_158 ) ;
V_12 -> V_161 = V_155 ;
if ( V_156 ) {
V_12 -> V_162 |= ( 1 & V_163 ) <<
V_164 ;
V_157 = F_64 ( V_12 ) ;
V_157 -> V_165 = F_66 ( F_53 ( V_156 -> V_123 ) ) ;
V_157 -> V_166 = F_66 ( V_156 -> V_123 & 0xFFFFFFFF ) ;
V_157 -> V_111 = F_66 ( V_156 -> V_167 ) ;
} else
V_12 -> V_162 |= V_168 ;
F_67 ( V_12 , 8 ) ;
}
static void F_68 ( struct V_169 * V_170 , T_2 V_171 ,
struct V_117 * V_156 )
{
int V_5 , V_172 = F_69 ( F_70 ( V_156 -> V_121 , V_156 -> V_167 ) , V_171 ) ;
T_5 V_123 = ( T_5 ) V_156 -> V_123 ;
for ( V_5 = 0 ; V_5 < V_172 ; V_5 ++ ) {
V_170 [ V_5 ] . V_173 = F_66 ( V_123 & 0xFFFFFFFF ) ;
V_170 [ V_5 ] . V_174 = F_66 ( F_53 ( V_123 ) ) ;
V_123 += V_175 ;
}
}
static T_2 F_71 ( T_2 V_176 )
{
#define F_72 651042
const T_2 V_177 = 10 ;
T_2 V_178 ;
if ( V_176 == 0 )
V_178 = 0 ;
else {
T_2 V_179 = 1000000 / V_176 ;
if ( V_179 == 0 )
V_178 = 1023 ;
else {
V_178 = ( F_72 - V_179 ) * V_177 ;
V_178 /= V_179 ;
V_178 = ( V_178 + V_177 / 2 ) / V_177 ;
V_178 = F_69 ( V_178 , ( T_2 ) 1023 ) ;
}
}
return V_178 ;
}
static inline struct V_11 * F_73 ( struct V_1 * V_2 )
{
struct V_117 * V_118 = & V_2 -> V_118 ;
struct V_11 * V_12
= & ( (struct V_119 * ) ( V_118 -> V_121 ) ) -> V_12 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
static struct V_11 * F_74 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 . V_17 ;
struct V_11 * V_12 ;
if ( ! V_15 -> V_180 )
return NULL ;
if ( F_43 ( & V_15 -> V_106 ) >= V_15 -> V_111 ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_9 ) ;
return NULL ;
}
V_12 = F_75 ( V_15 ) ;
F_76 ( V_15 ) ;
F_77 ( & V_15 -> V_106 ) ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
int F_78 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_35 ;
if ( F_18 ( V_2 ) )
return 0 ;
if ( F_79 ( & V_2 -> V_181 ) )
return - 1 ;
V_12 = ( T_1 * ) F_73 ( V_2 ) ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0x12 ;
* V_12 ++ = 0x34 ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0x56 ;
* V_12 ++ = 0x78 ;
* V_12 = 0xFF ;
V_35 = F_52 ( V_2 ) ;
F_80 ( & V_2 -> V_181 ) ;
return V_35 ;
}
int F_81 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_35 ;
if ( F_18 ( V_2 ) )
return 0 ;
if ( F_79 ( & V_2 -> V_181 ) )
return - 1 ;
V_12 = ( T_1 * ) F_73 ( V_2 ) ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xAA ;
* V_12 ++ = 0xBB ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xCC ;
* V_12 ++ = 0xDD ;
* V_12 = 0xFF ;
V_35 = F_52 ( V_2 ) ;
F_80 ( & V_2 -> V_181 ) ;
return V_35 ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_14 * V_182 , int V_183 )
{
struct V_11 * V_12 ;
struct V_184 * V_185 ;
struct V_117 * V_186 = & V_182 -> V_187 ;
int V_35 ;
if ( F_79 ( & V_2 -> V_181 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_189 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_190 = F_83 ( F_70 ( V_186 -> V_121 , V_186 -> V_167 ) ) ;
F_84 ( struct V_191 , V_71 , V_185 -> V_192 , 1 ) ;
F_84 ( struct V_191 , V_167 , V_185 -> V_192 , 0 ) ;
F_84 ( struct V_191 , V_193 , V_185 -> V_192 ,
F_85 ( V_182 -> V_111 / 256 ) ) ;
F_84 ( struct V_191 , V_194 , V_185 -> V_192 ,
F_71 ( V_183 ) ) ;
F_67 ( V_185 -> V_192 , sizeof( V_185 -> V_192 ) ) ;
F_68 ( V_185 -> V_170 , F_86 ( V_185 -> V_170 ) , V_186 ) ;
V_35 = F_52 ( V_2 ) ;
if ( ! V_35 ) {
struct V_195 * V_50 = F_2 ( V_12 ) ;
V_182 -> V_19 = F_22 ( V_50 -> V_196 ) ;
V_182 -> V_180 = true ;
}
F_80 ( & V_2 -> V_181 ) ;
return V_35 ;
}
int F_87 ( struct V_1 * V_2 , T_1 * V_197 ,
bool V_198 , T_2 V_199 , T_2 V_200 )
{
struct V_11 * V_12 ;
struct V_201 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_204 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> type = V_205 ;
if ( V_198 ) {
V_185 -> V_198 = 1 ;
} else {
V_185 -> V_206 = F_83 ( ( T_3 ) V_199 ) ;
V_185 -> V_200 = F_66 ( V_200 ) ;
V_185 -> V_198 = 0 ;
}
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_207 * V_50 = F_2 ( V_12 ) ;
memcpy ( V_197 , V_50 -> V_208 . V_31 , V_209 ) ;
}
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_88 ( struct V_1 * V_2 , T_1 * V_197 ,
T_2 V_206 , T_2 * V_200 , T_2 V_210 )
{
struct V_11 * V_12 ;
struct V_211 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_212 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_188 . V_210 = V_210 ;
V_185 -> V_206 = F_66 ( V_206 ) ;
memcpy ( V_185 -> V_213 , V_197 , V_209 ) ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_214 * V_50 = F_2 ( V_12 ) ;
* V_200 = F_8 ( V_50 -> V_200 ) ;
}
V_139:
F_33 ( & V_2 -> V_202 ) ;
if ( V_35 == V_58 )
V_35 = - V_215 ;
return V_35 ;
}
int F_89 ( struct V_1 * V_2 , T_2 V_206 , int V_200 , T_2 V_216 )
{
struct V_11 * V_12 ;
struct V_217 * V_185 ;
int V_35 ;
if ( V_200 == - 1 )
return 0 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_218 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_188 . V_210 = V_216 ;
V_185 -> V_206 = F_66 ( V_206 ) ;
V_185 -> V_200 = F_66 ( V_200 ) ;
V_35 = F_45 ( V_2 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_90 ( struct V_1 * V_2 , struct V_14 * V_99 ,
struct V_14 * V_182 , bool V_219 , int V_220 )
{
struct V_11 * V_12 ;
struct V_221 * V_185 ;
struct V_117 * V_186 = & V_99 -> V_187 ;
void * V_222 ;
int V_35 ;
if ( F_79 ( & V_2 -> V_181 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
V_185 = F_2 ( V_12 ) ;
V_222 = & V_185 -> V_192 ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_223 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_190 = F_83 ( F_70 ( V_186 -> V_121 , V_186 -> V_167 ) ) ;
if ( F_18 ( V_2 ) ) {
V_185 -> V_188 . V_160 = 2 ;
V_185 -> V_224 = 1 ;
F_84 ( struct V_225 , V_226 , V_222 ,
V_219 ) ;
F_84 ( struct V_225 , V_193 , V_222 ,
F_85 ( V_99 -> V_111 / 256 ) ) ;
F_84 ( struct V_225 , V_71 , V_222 , 1 ) ;
F_84 ( struct V_225 , V_227 ,
V_222 , 1 ) ;
F_84 ( struct V_225 , V_228 ,
V_222 , V_182 -> V_19 ) ;
} else {
F_84 ( struct V_229 , V_230 , V_222 ,
V_220 ) ;
F_84 ( struct V_229 , V_226 ,
V_222 , V_219 ) ;
F_84 ( struct V_229 , V_193 , V_222 ,
F_85 ( V_99 -> V_111 / 256 ) ) ;
F_84 ( struct V_229 , V_71 , V_222 , 1 ) ;
F_84 ( struct V_229 , V_227 , V_222 , 1 ) ;
F_84 ( struct V_229 , V_228 , V_222 , V_182 -> V_19 ) ;
}
F_67 ( V_222 , sizeof( V_185 -> V_192 ) ) ;
F_68 ( V_185 -> V_170 , F_86 ( V_185 -> V_170 ) , V_186 ) ;
V_35 = F_52 ( V_2 ) ;
if ( ! V_35 ) {
struct V_231 * V_50 = F_2 ( V_12 ) ;
V_99 -> V_19 = F_22 ( V_50 -> V_232 ) ;
V_99 -> V_180 = true ;
}
F_80 ( & V_2 -> V_181 ) ;
return V_35 ;
}
static T_2 F_91 ( int V_233 )
{
T_2 V_234 = F_92 ( V_233 ) ;
if ( V_234 == 16 )
V_234 = 0 ;
return V_234 ;
}
int F_93 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_99 )
{
struct V_11 * V_12 ;
struct V_235 * V_185 ;
struct V_117 * V_186 = & V_15 -> V_187 ;
void * V_222 ;
int V_35 ;
if ( F_79 ( & V_2 -> V_181 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
V_185 = F_2 ( V_12 ) ;
V_222 = & V_185 -> V_192 ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_236 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_190 = F_83 ( F_70 ( V_186 -> V_121 , V_186 -> V_167 ) ) ;
if ( F_18 ( V_2 ) ) {
V_185 -> V_188 . V_160 = 1 ;
V_185 -> V_232 = F_83 ( V_99 -> V_19 ) ;
F_84 ( struct V_237 , V_238 , V_222 ,
F_91 ( V_15 -> V_111 ) ) ;
F_84 ( struct V_237 , V_71 , V_222 , 1 ) ;
F_84 ( struct V_237 , V_239 ,
V_222 , V_99 -> V_19 ) ;
F_84 ( struct V_237 , V_240 ,
V_222 , 1 ) ;
} else {
F_84 ( struct V_241 , V_71 , V_222 , 1 ) ;
F_84 ( struct V_241 , V_238 , V_222 ,
F_91 ( V_15 -> V_111 ) ) ;
F_84 ( struct V_241 , V_232 , V_222 , V_99 -> V_19 ) ;
}
V_185 -> V_242 [ 0 ] = F_66 ( 0x00000022 ) ;
F_67 ( V_222 , sizeof( V_185 -> V_192 ) ) ;
F_68 ( V_185 -> V_170 , F_86 ( V_185 -> V_170 ) , V_186 ) ;
V_35 = F_52 ( V_2 ) ;
if ( ! V_35 ) {
struct V_243 * V_50 = F_2 ( V_12 ) ;
V_15 -> V_19 = F_22 ( V_50 -> V_19 ) ;
V_15 -> V_180 = true ;
}
F_80 ( & V_2 -> V_181 ) ;
return V_35 ;
}
int F_94 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_99 )
{
struct V_11 * V_12 ;
struct V_244 * V_185 ;
struct V_117 * V_186 = & V_15 -> V_187 ;
void * V_222 ;
int V_35 ;
if ( F_79 ( & V_2 -> V_181 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
V_185 = F_2 ( V_12 ) ;
V_222 = & V_185 -> V_192 ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_245 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_190 = F_83 ( F_70 ( V_186 -> V_121 , V_186 -> V_167 ) ) ;
F_84 ( struct V_241 , V_71 , V_222 , 1 ) ;
F_84 ( struct V_241 , V_238 , V_222 ,
F_91 ( V_15 -> V_111 ) ) ;
F_84 ( struct V_241 , V_232 , V_222 , V_99 -> V_19 ) ;
F_67 ( V_222 , sizeof( V_185 -> V_192 ) ) ;
F_68 ( V_185 -> V_170 , F_86 ( V_185 -> V_170 ) , V_186 ) ;
V_35 = F_52 ( V_2 ) ;
if ( ! V_35 ) {
struct V_243 * V_50 = F_2 ( V_12 ) ;
V_15 -> V_19 = F_22 ( V_50 -> V_19 ) ;
V_15 -> V_180 = true ;
}
F_80 ( & V_2 -> V_181 ) ;
return V_35 ;
}
int F_95 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_99 )
{
int V_35 ;
V_35 = F_93 ( V_2 , V_15 , V_99 ) ;
if ( V_35 && ! F_18 ( V_2 ) ) {
F_15 ( & V_2 -> V_59 -> V_60 , L_10
L_11
L_12 ) ;
V_35 = F_94 ( V_2 , V_15 , V_99 ) ;
}
return V_35 ;
}
int F_96 ( struct V_1 * V_2 ,
struct V_14 * V_246 ,
struct V_14 * V_99 )
{
struct V_11 * V_12 ;
struct V_247 * V_185 ;
struct V_117 * V_186 = & V_246 -> V_187 ;
void * V_222 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
V_222 = & V_185 -> V_192 ;
F_65 ( & V_185 -> V_188 , V_46 ,
V_248 , sizeof( * V_185 ) , V_12 , NULL ) ;
if ( F_18 ( V_2 ) ) {
V_185 -> V_188 . V_160 = 1 ;
F_84 ( struct V_249 , V_206 , V_222 ,
V_2 -> V_199 ) ;
}
V_185 -> V_190 = F_70 ( V_186 -> V_121 , V_186 -> V_167 ) ;
V_185 -> V_250 = V_251 ;
V_185 -> type = V_252 ;
F_84 ( struct V_249 , V_253 , V_222 ,
F_91 ( V_246 -> V_111 ) ) ;
F_84 ( struct V_249 , V_254 , V_222 , 1 ) ;
F_84 ( struct V_249 , V_255 , V_222 , V_99 -> V_19 ) ;
F_67 ( V_222 , sizeof( V_185 -> V_192 ) ) ;
F_68 ( V_185 -> V_170 , F_86 ( V_185 -> V_170 ) , V_186 ) ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_256 * V_50 = F_2 ( V_12 ) ;
V_246 -> V_19 = F_22 ( V_50 -> V_257 ) ;
V_246 -> V_180 = true ;
}
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_97 ( struct V_1 * V_2 ,
struct V_14 * V_258 , T_3 V_232 , T_3 V_259 ,
T_2 V_206 , T_2 V_260 , T_1 * V_261 )
{
struct V_11 * V_12 ;
struct V_262 * V_185 ;
struct V_117 * V_186 = & V_258 -> V_187 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_46 ,
V_263 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_232 = F_83 ( V_232 ) ;
V_185 -> V_259 = F_92 ( V_259 ) - 1 ;
V_185 -> V_190 = 2 ;
F_68 ( V_185 -> V_170 , F_86 ( V_185 -> V_170 ) , V_186 ) ;
V_185 -> V_264 = F_66 ( V_206 ) ;
V_185 -> V_265 = F_83 ( V_266 ) ;
V_185 -> V_267 = F_66 ( V_260 ) ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_268 * V_50 = F_2 ( V_12 ) ;
V_258 -> V_19 = F_22 ( V_50 -> V_19 ) ;
V_258 -> V_180 = true ;
* V_261 = V_50 -> V_261 ;
}
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_98 ( struct V_1 * V_2 , struct V_14 * V_17 ,
int V_269 )
{
struct V_11 * V_12 ;
struct V_270 * V_185 ;
T_1 V_271 = 0 , V_3 = 0 ;
int V_35 ;
if ( F_79 ( & V_2 -> V_181 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
V_185 = F_2 ( V_12 ) ;
switch ( V_269 ) {
case V_272 :
V_271 = V_40 ;
V_3 = V_273 ;
break;
case V_274 :
V_271 = V_40 ;
V_3 = V_275 ;
break;
case V_276 :
V_271 = V_46 ;
V_3 = V_277 ;
break;
case V_278 :
V_271 = V_46 ;
V_3 = V_279 ;
break;
case V_280 :
V_271 = V_40 ;
V_3 = V_281 ;
break;
default:
F_99 () ;
}
F_65 ( & V_185 -> V_188 , V_271 , V_3 , sizeof( * V_185 ) , V_12 ,
NULL ) ;
V_185 -> V_19 = F_83 ( V_17 -> V_19 ) ;
V_35 = F_52 ( V_2 ) ;
V_17 -> V_180 = false ;
F_80 ( & V_2 -> V_181 ) ;
return V_35 ;
}
int F_100 ( struct V_1 * V_2 , struct V_14 * V_17 )
{
struct V_11 * V_12 ;
struct V_270 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_46 ,
V_279 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_19 = F_83 ( V_17 -> V_19 ) ;
V_35 = F_45 ( V_2 ) ;
V_17 -> V_180 = false ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_101 ( struct V_1 * V_2 , T_2 V_282 , T_2 V_283 ,
T_2 * V_199 , T_2 V_210 )
{
struct V_11 * V_12 ;
struct V_284 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_285 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_188 . V_210 = V_210 ;
V_185 -> V_286 = F_66 ( V_282 ) ;
V_185 -> V_287 = F_66 ( V_283 ) ;
V_185 -> V_288 = true ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_289 * V_50 = F_2 ( V_12 ) ;
* V_199 = F_8 ( V_50 -> V_264 ) ;
}
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_102 ( struct V_1 * V_2 , int V_264 , T_2 V_210 )
{
struct V_11 * V_12 ;
struct V_290 * V_185 ;
int V_35 ;
if ( V_264 == - 1 )
return 0 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_291 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_188 . V_210 = V_210 ;
V_185 -> V_264 = F_66 ( V_264 ) ;
V_35 = F_45 ( V_2 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_103 ( struct V_1 * V_2 , struct V_117 * V_292 )
{
struct V_11 * V_12 ;
struct V_153 * V_188 ;
int V_35 = 0 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_188 = V_292 -> V_121 ;
F_65 ( V_188 , V_46 ,
V_44 , V_292 -> V_167 , V_12 , V_292 ) ;
if ( ! F_104 ( V_2 ) )
V_188 -> V_160 = 1 ;
F_3 ( V_2 ) ;
V_2 -> V_47 = true ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_105 ( struct V_1 * V_2 ,
struct V_117 * V_292 )
{
struct V_11 * V_12 ;
struct V_293 * V_185 ;
int V_35 = 0 ;
if ( ! F_1 ( V_2 , V_45 ,
V_46 ) )
return - V_215 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = V_292 -> V_121 ;
F_65 ( & V_185 -> V_188 , V_46 ,
V_45 , V_292 -> V_167 , V_12 ,
V_292 ) ;
V_185 -> V_294 . V_295 . V_296 = F_83 ( V_2 -> V_297 ) ;
V_185 -> V_294 . V_295 . V_298 = 0 ;
F_3 ( V_2 ) ;
V_2 -> V_47 = true ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
static int F_106 ( int V_299 )
{
switch ( V_299 ) {
case V_300 :
return 0 ;
case V_301 :
return 10 ;
case V_302 :
return 100 ;
case V_303 :
return 1000 ;
case V_304 :
return 10000 ;
}
return 0 ;
}
int F_107 ( struct V_1 * V_2 , T_3 * V_66 ,
T_1 * V_305 , T_2 V_216 )
{
struct V_11 * V_12 ;
struct V_306 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
if ( V_305 )
* V_305 = V_307 ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_308 , sizeof( * V_185 ) , V_12 , NULL ) ;
if ( ! F_104 ( V_2 ) )
V_185 -> V_188 . V_160 = 1 ;
V_185 -> V_188 . V_210 = V_216 ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_309 * V_50 = F_2 ( V_12 ) ;
if ( V_66 ) {
* V_66 = V_50 -> V_66 ?
F_22 ( V_50 -> V_66 ) * 10 :
F_106 ( V_50 -> V_299 ) ;
if ( ! V_50 -> V_310 )
* V_66 = 0 ;
}
if ( V_305 )
* V_305 = V_50 -> V_310 ;
}
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_108 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_311 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_48 , sizeof( * V_185 ) ,
V_12 , NULL ) ;
F_3 ( V_2 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_109 ( struct V_1 * V_2 , T_2 * V_312 )
{
struct V_11 * V_12 ;
struct V_313 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_314 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_315 = F_66 ( V_316 ) ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_317 * V_50 = F_2 ( V_12 ) ;
if ( V_312 && V_50 -> V_312 )
* V_312 = F_8 ( V_50 -> V_312 ) -
sizeof( T_2 ) ;
}
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
void F_110 ( struct V_1 * V_2 , T_2 V_318 , void * V_319 )
{
struct V_117 V_320 ;
struct V_11 * V_12 ;
struct V_313 * V_185 ;
T_2 V_321 = 0 , V_322 , V_323 ,
V_324 = sizeof( T_2 ) , V_325 ;
int V_35 ;
if ( V_318 == 0 )
return;
V_322 = V_318 ;
V_320 . V_167 = sizeof( struct V_313 ) + 60 * 1024 ;
V_320 . V_121 = F_111 ( V_2 -> V_59 ,
V_320 . V_167 ,
& V_320 . V_123 ) ;
if ( ! V_320 . V_121 ) {
V_35 = - V_326 ;
F_16 ( & V_2 -> V_59 -> V_60 ,
L_13 ) ;
return;
}
F_31 ( & V_2 -> V_202 ) ;
while ( V_322 ) {
V_323 = F_69 ( V_322 , ( T_2 ) 60 * 1024 ) ;
V_322 -= V_323 ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = V_320 . V_121 ;
V_325 = sizeof( struct V_313 ) + V_323 ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_314 , V_325 , V_12 ,
& V_320 ) ;
V_185 -> V_315 = F_66 ( V_327 ) ;
V_185 -> V_328 = F_66 ( V_324 ) ;
V_185 -> V_329 = F_66 ( V_323 ) ;
V_185 -> V_330 = F_66 ( V_323 ) ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_317 * V_50 = V_320 . V_121 ;
memcpy ( V_319 + V_321 ,
V_50 -> V_331 ,
F_8 ( V_50 -> V_329 ) ) ;
} else {
F_16 ( & V_2 -> V_59 -> V_60 , L_14 ) ;
goto V_139;
}
V_321 += V_323 ;
V_324 += V_323 ;
}
V_139:
F_112 ( V_2 -> V_59 , V_320 . V_167 ,
V_320 . V_121 ,
V_320 . V_123 ) ;
F_33 ( & V_2 -> V_202 ) ;
}
int F_113 ( struct V_1 * V_2 , char * V_332 ,
char * V_333 )
{
struct V_11 * V_12 ;
struct V_334 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_335 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_336 * V_50 = F_2 ( V_12 ) ;
strcpy ( V_332 , V_50 -> V_337 ) ;
if ( V_333 )
strcpy ( V_333 , V_50 -> V_338 ) ;
}
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_114 ( struct V_1 * V_2 , T_2 V_196 , T_2 V_339 )
{
struct V_11 * V_12 ;
struct V_340 * V_185 ;
int V_35 = 0 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_341 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_342 = F_66 ( 1 ) ;
V_185 -> V_343 [ 0 ] . V_196 = F_66 ( V_196 ) ;
V_185 -> V_343 [ 0 ] . V_344 = 0 ;
V_185 -> V_343 [ 0 ] . V_345 = F_66 ( V_339 ) ;
F_3 ( V_2 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_115 ( struct V_1 * V_2 , T_2 V_206 , T_3 * V_346 ,
T_2 V_102 , bool V_347 , bool V_348 )
{
struct V_11 * V_12 ;
struct V_349 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_350 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_264 = V_206 ;
V_185 -> V_348 = V_348 ;
V_185 -> V_347 = V_347 ;
V_185 -> V_351 = V_102 ;
if ( ! V_348 ) {
memcpy ( V_185 -> V_352 , V_346 ,
V_185 -> V_351 * sizeof( V_346 [ 0 ] ) ) ;
}
V_35 = F_45 ( V_2 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_116 ( struct V_1 * V_2 , T_2 V_26 , T_2 V_353 )
{
struct V_11 * V_12 ;
struct V_117 * V_156 = & V_2 -> V_354 ;
struct V_355 * V_185 = V_156 -> V_121 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
memset ( V_185 , 0 , sizeof( * V_185 ) ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_356 , sizeof( * V_185 ) ,
V_12 , V_156 ) ;
V_185 -> V_206 = F_66 ( V_2 -> V_199 ) ;
if ( V_26 & V_357 ) {
V_185 -> V_358 = F_66 ( V_359 |
V_360 ) ;
if ( V_353 == V_361 )
V_185 -> V_362 = F_66 ( V_359 |
V_360 ) ;
} else if ( V_26 & V_363 ) {
V_185 -> V_358 = V_185 -> V_362 =
F_66 ( V_364 ) ;
} else {
struct V_365 * V_366 ;
int V_5 = 0 ;
V_185 -> V_358 = V_185 -> V_362 =
F_66 ( V_367 ) ;
V_185 -> V_358 |=
F_66 ( V_364 &
V_2 -> V_368 ) ;
V_185 -> V_369 = F_66 ( F_117 ( V_2 -> V_370 ) ) ;
F_118 (ha, adapter->netdev)
memcpy ( V_185 -> V_371 [ V_5 ++ ] . V_372 , V_366 -> V_31 , V_209 ) ;
}
V_35 = F_45 ( V_2 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_119 ( struct V_1 * V_2 , T_2 V_373 , T_2 V_374 )
{
struct V_11 * V_12 ;
struct V_375 * V_185 ;
int V_35 ;
if ( ! F_1 ( V_2 , V_376 ,
V_40 ) )
return - V_215 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_376 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_377 = F_83 ( ( T_3 ) V_373 ) ;
V_185 -> V_378 = F_83 ( ( T_3 ) V_374 ) ;
V_35 = F_45 ( V_2 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_120 ( struct V_1 * V_2 , T_2 * V_373 , T_2 * V_374 )
{
struct V_11 * V_12 ;
struct V_379 * V_185 ;
int V_35 ;
if ( ! F_1 ( V_2 , V_380 ,
V_40 ) )
return - V_215 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_380 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_381 * V_50 =
F_2 ( V_12 ) ;
* V_373 = F_22 ( V_50 -> V_377 ) ;
* V_374 = F_22 ( V_50 -> V_378 ) ;
}
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_121 ( struct V_1 * V_2 , T_2 * V_80 ,
T_2 * V_382 , T_2 * V_383 )
{
struct V_11 * V_12 ;
struct V_384 * V_185 ;
int V_35 ;
if ( F_79 ( & V_2 -> V_181 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_385 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_35 = F_52 ( V_2 ) ;
if ( ! V_35 ) {
struct V_386 * V_50 = F_2 ( V_12 ) ;
* V_80 = F_8 ( V_50 -> V_387 ) ;
* V_382 = F_8 ( V_50 -> V_388 ) ;
* V_383 = F_8 ( V_50 -> V_389 ) ;
}
F_80 ( & V_2 -> V_181 ) ;
return V_35 ;
}
int F_122 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_153 * V_185 ;
int V_35 ;
if ( F_18 ( V_2 ) ) {
V_35 = F_57 ( V_2 ) ;
if ( ! V_35 ) {
F_6 ( V_143 ,
V_2 -> V_22 + V_144 ) ;
V_35 = F_60 ( V_2 ) ;
}
if ( V_35 ) {
F_16 ( & V_2 -> V_59 -> V_60 ,
L_15 ) ;
}
return V_35 ;
}
if ( F_79 ( & V_2 -> V_181 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
V_185 = F_2 ( V_12 ) ;
F_65 ( V_185 , V_40 ,
V_390 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_35 = F_52 ( V_2 ) ;
F_80 ( & V_2 -> V_181 ) ;
return V_35 ;
}
int F_123 ( struct V_1 * V_2 , T_1 * V_391 , T_3 V_392 )
{
struct V_11 * V_12 ;
struct V_393 * V_185 ;
T_2 V_394 [ 10 ] = { 0x15d43fa5 , 0x2534685a , 0x5f87693a , 0x5668494e ,
0x33cf6a53 , 0x383334c6 , 0x76ac4257 , 0x59b242b2 ,
0x3ea83c02 , 0x4a110304 } ;
int V_35 ;
if ( F_79 ( & V_2 -> V_181 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_46 ,
V_395 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_206 = F_66 ( V_2 -> V_199 ) ;
V_185 -> V_396 = F_83 ( V_397 | V_398 |
V_399 | V_400 ) ;
if ( F_18 ( V_2 ) || F_124 ( V_2 ) ) {
V_185 -> V_188 . V_160 = 1 ;
V_185 -> V_396 |= F_83 ( V_401 |
V_402 ) ;
}
V_185 -> V_403 = F_83 ( F_92 ( V_392 ) - 1 ) ;
memcpy ( V_185 -> V_404 , V_391 , V_392 ) ;
memcpy ( V_185 -> V_405 , V_394 , sizeof( V_394 ) ) ;
F_67 ( V_185 -> V_405 , sizeof( V_185 -> V_405 ) ) ;
V_35 = F_52 ( V_2 ) ;
F_80 ( & V_2 -> V_181 ) ;
return V_35 ;
}
int F_125 ( struct V_1 * V_2 , T_1 V_80 ,
T_1 V_406 , T_1 V_407 , T_1 V_408 )
{
struct V_11 * V_12 ;
struct V_409 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_410 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_80 = V_80 ;
V_185 -> V_411 = V_408 ;
V_185 -> V_412 = V_406 ;
V_185 -> V_413 = V_407 ;
V_35 = F_45 ( V_2 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_126 ( struct V_1 * V_2 , T_1 V_80 , T_2 * V_408 )
{
struct V_11 * V_12 ;
struct V_414 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_415 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_80 = V_80 ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_416 * V_50 =
F_2 ( V_12 ) ;
* V_408 = V_50 -> V_411 ;
}
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_127 ( struct V_1 * V_2 , struct V_117 * V_417 ,
T_2 V_418 , T_2 V_419 ,
const char * V_420 , T_2 * V_421 ,
T_1 * V_422 , T_1 * V_423 )
{
struct V_11 * V_12 ;
struct V_424 * V_185 ;
struct V_425 * V_50 ;
void * V_222 = NULL ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_2 -> V_41 = 0 ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_426;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_39 ,
sizeof( struct V_424 ) , V_12 ,
NULL ) ;
V_222 = & V_185 -> V_192 ;
F_84 ( struct V_427 ,
V_428 , V_222 , V_418 ) ;
if ( V_418 == 0 )
F_84 ( struct V_427 ,
V_429 , V_222 , 1 ) ;
else
F_84 ( struct V_427 ,
V_429 , V_222 , 0 ) ;
F_67 ( V_222 , sizeof( V_185 -> V_192 ) ) ;
V_185 -> V_430 = F_66 ( V_419 ) ;
strcpy ( V_185 -> V_431 , V_420 ) ;
V_185 -> V_432 = F_66 ( 1 ) ;
V_185 -> V_318 = F_66 ( V_418 ) ;
V_185 -> V_433 = F_66 ( ( V_417 -> V_123 +
sizeof( struct V_424 ) )
& 0xFFFFFFFF ) ;
V_185 -> V_434 = F_66 ( F_53 ( V_417 -> V_123 +
sizeof( struct V_424 ) ) ) ;
F_3 ( V_2 ) ;
F_33 ( & V_2 -> V_202 ) ;
if ( ! F_128 ( & V_2 -> V_42 ,
F_129 ( 30000 ) ) )
V_35 = - 1 ;
else
V_35 = V_2 -> V_41 ;
V_50 = F_2 ( V_12 ) ;
if ( ! V_35 ) {
* V_421 = F_8 ( V_50 -> V_435 ) ;
* V_422 = V_50 -> V_422 ;
} else {
* V_423 = V_50 -> V_436 ;
}
return V_35 ;
V_426:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_130 ( struct V_1 * V_2 , struct V_117 * V_417 ,
T_2 V_418 , T_2 V_419 , const char * V_420 ,
T_2 * V_437 , T_2 * V_429 , T_1 * V_423 )
{
struct V_11 * V_12 ;
struct V_438 * V_185 ;
struct V_439 * V_50 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_426;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_440 ,
sizeof( struct V_438 ) , V_12 ,
NULL ) ;
V_185 -> V_441 = F_66 ( V_418 ) ;
V_185 -> V_442 = F_66 ( V_419 ) ;
strcpy ( V_185 -> V_431 , V_420 ) ;
V_185 -> V_432 = F_66 ( 1 ) ;
V_185 -> V_318 = F_66 ( V_418 ) ;
V_185 -> V_433 = F_66 ( ( V_417 -> V_123 & 0xFFFFFFFF ) ) ;
V_185 -> V_434 = F_66 ( F_53 ( V_417 -> V_123 ) ) ;
V_35 = F_45 ( V_2 ) ;
V_50 = F_2 ( V_12 ) ;
if ( ! V_35 ) {
* V_437 = F_8 ( V_50 -> V_443 ) ;
* V_429 = F_8 ( V_50 -> V_429 ) ;
} else {
* V_423 = V_50 -> V_436 ;
}
V_426:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_131 ( struct V_1 * V_2 , struct V_117 * V_417 ,
T_2 V_444 , T_2 V_445 , T_2 V_323 )
{
struct V_11 * V_12 ;
struct F_131 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_2 -> V_41 = 0 ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_426;
}
V_185 = V_417 -> V_121 ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_38 , V_417 -> V_167 , V_12 , V_417 ) ;
V_185 -> V_295 . V_446 = F_66 ( V_444 ) ;
V_185 -> V_295 . V_447 = F_66 ( V_445 ) ;
V_185 -> V_295 . V_448 = F_66 ( V_323 ) ;
F_3 ( V_2 ) ;
F_33 ( & V_2 -> V_202 ) ;
if ( ! F_128 ( & V_2 -> V_42 ,
F_129 ( 40000 ) ) )
V_35 = - 1 ;
else
V_35 = V_2 -> V_41 ;
return V_35 ;
V_426:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_132 ( struct V_1 * V_2 , T_1 * V_449 ,
int V_321 )
{
struct V_11 * V_12 ;
struct V_450 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_451 , sizeof( * V_185 ) ,
V_12 , NULL ) ;
V_185 -> V_295 . V_446 = F_66 ( V_452 ) ;
V_185 -> V_295 . V_447 = F_66 ( V_453 ) ;
V_185 -> V_295 . V_321 = F_66 ( V_321 ) ;
V_185 -> V_295 . V_448 = F_66 ( 0x4 ) ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 )
memcpy ( V_449 , V_185 -> V_454 , 4 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_133 ( struct V_1 * V_2 , T_1 * V_208 ,
struct V_117 * V_292 )
{
struct V_11 * V_12 ;
struct V_455 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = V_292 -> V_121 ;
F_65 ( & V_185 -> V_188 , V_46 ,
V_456 , sizeof( * V_185 ) , V_12 ,
V_292 ) ;
memcpy ( V_185 -> V_457 , V_208 , V_209 ) ;
V_35 = F_45 ( V_2 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_134 ( struct V_1 * V_2 , T_1 V_80 ,
T_1 V_458 , T_1 V_459 )
{
struct V_11 * V_12 ;
struct V_460 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_461 ,
V_462 , sizeof( * V_185 ) , V_12 ,
NULL ) ;
V_185 -> V_463 = V_80 ;
V_185 -> V_464 = V_80 ;
V_185 -> V_458 = V_458 ;
V_185 -> V_465 = V_459 ;
V_35 = F_45 ( V_2 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_135 ( struct V_1 * V_2 , T_2 V_80 ,
T_2 V_458 , T_2 V_466 , T_2 V_467 , T_5 V_468 )
{
struct V_11 * V_12 ;
struct V_469 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_461 ,
V_470 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_188 . V_147 = F_66 ( 4 ) ;
V_185 -> V_468 = F_136 ( V_468 ) ;
V_185 -> V_463 = F_66 ( V_80 ) ;
V_185 -> V_464 = F_66 ( V_80 ) ;
V_185 -> V_466 = F_66 ( V_466 ) ;
V_185 -> V_467 = F_66 ( V_467 ) ;
V_185 -> V_458 = F_66 ( V_458 ) ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_471 * V_50 = F_2 ( V_12 ) ;
V_35 = F_8 ( V_50 -> V_35 ) ;
}
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_137 ( struct V_1 * V_2 , T_5 V_468 ,
T_2 V_472 , struct V_117 * V_417 )
{
struct V_11 * V_12 ;
struct V_473 * V_185 ;
int V_35 ;
int V_5 , V_474 = 0 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = V_417 -> V_121 ;
F_65 ( & V_185 -> V_188 , V_461 ,
V_475 , V_417 -> V_167 , V_12 , V_417 ) ;
V_185 -> V_468 = F_136 ( V_468 ) ;
V_185 -> V_476 = F_66 ( V_472 ) ;
for ( V_5 = 0 ; V_5 < V_472 ; V_5 ++ ) {
V_185 -> V_477 [ V_5 ] = ( T_1 ) ( V_468 >> ( V_474 * 8 ) ) ;
V_474 ++ ;
if ( V_474 > 7 )
V_474 = 0 ;
}
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_478 * V_50 ;
V_50 = V_417 -> V_121 ;
if ( ( memcmp ( V_50 -> V_479 , V_185 -> V_477 , V_472 ) != 0 ) ||
V_50 -> V_480 ) {
V_35 = - 1 ;
}
}
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_138 ( struct V_1 * V_2 ,
struct V_117 * V_292 )
{
struct V_11 * V_12 ;
struct V_481 * V_185 ;
struct V_151 * V_157 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = V_292 -> V_121 ;
V_157 = F_64 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_482 , sizeof( * V_185 ) , V_12 ,
V_292 ) ;
V_35 = F_45 ( V_2 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_139 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_483 * V_185 ;
struct V_117 V_417 ;
int V_35 ;
if ( ! F_1 ( V_2 , V_484 ,
V_40 ) )
return - V_215 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_417 . V_167 = sizeof( struct V_483 ) ;
V_417 . V_121 = F_111 ( V_2 -> V_59 , V_417 . V_167 ,
& V_417 . V_123 ) ;
if ( ! V_417 . V_121 ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_16 ) ;
V_35 = - V_326 ;
goto V_139;
}
V_185 = V_417 . V_121 ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_484 , sizeof( * V_185 ) ,
V_12 , & V_417 ) ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_485 * V_486 =
V_417 . V_121 + sizeof( struct V_153 ) ;
V_2 -> V_65 . V_487 = F_22 ( V_486 -> V_487 ) ;
V_2 -> V_65 . V_488 =
F_22 ( V_486 -> V_488 ) ;
V_2 -> V_65 . V_489 =
F_22 ( V_486 -> V_489 ) ;
V_2 -> V_65 . V_490 =
F_22 ( V_486 -> V_490 ) ;
V_2 -> V_65 . V_491 =
F_8 ( V_486 -> V_491 ) ;
}
F_112 ( V_2 -> V_59 , V_417 . V_167 ,
V_417 . V_121 , V_417 . V_123 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_140 ( struct V_1 * V_2 , T_2 V_492 , T_2 V_210 )
{
struct V_11 * V_12 ;
struct V_493 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_494 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_188 . V_210 = V_210 ;
V_185 -> V_495 = F_66 ( V_496 ) ;
V_185 -> V_497 = F_66 ( V_492 ) ;
V_35 = F_45 ( V_2 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_141 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_498 * V_185 ;
struct V_499 * V_50 ;
int V_35 ;
int V_325 = F_142 ( sizeof( * V_185 ) , sizeof( * V_50 ) ) ;
struct V_500 * V_501 ;
struct V_117 V_502 ;
memset ( & V_502 , 0 , sizeof( struct V_117 ) ) ;
V_502 . V_167 = sizeof( struct V_499 ) ;
V_502 . V_121 = F_111 ( V_2 -> V_59 , V_502 . V_167 ,
& V_502 . V_123 ) ;
if ( ! V_502 . V_121 ) {
F_16 ( & V_2 -> V_59 -> V_60 ,
L_17 ) ;
return - V_326 ;
}
if ( F_79 ( & V_2 -> V_181 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = V_502 . V_121 ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_503 , V_325 , V_12 ,
& V_502 ) ;
V_35 = F_52 ( V_2 ) ;
if ( ! V_35 ) {
V_501 = V_502 . V_121 + sizeof( struct V_28 ) ;
V_2 -> V_297 = V_501 -> V_504 . V_505 ;
}
V_139:
F_80 ( & V_2 -> V_181 ) ;
F_112 ( V_2 -> V_59 , V_502 . V_167 , V_502 . V_121 ,
V_502 . V_123 ) ;
return V_35 ;
}
int F_143 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_506 * V_185 ;
int V_35 ;
if ( F_79 ( & V_2 -> V_181 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_507 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_508 = F_66 ( V_509 |
V_510 ) ;
V_185 -> V_282 = F_66 ( V_510 ) ;
V_35 = F_52 ( V_2 ) ;
if ( ! V_35 ) {
struct V_511 * V_50 = F_2 ( V_12 ) ;
V_2 -> V_512 = F_8 ( V_50 -> V_282 ) &
V_510 ;
if ( ! V_2 -> V_512 )
F_15 ( & V_2 -> V_59 -> V_60 ,
L_18 ) ;
}
V_139:
F_80 ( & V_2 -> V_181 ) ;
return V_35 ;
}
int F_144 ( struct V_1 * V_2 , T_2 * V_513 ,
T_2 V_210 )
{
struct V_11 * V_12 ;
struct V_514 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_515 , sizeof( * V_185 ) ,
V_12 , NULL ) ;
V_185 -> V_188 . V_210 = V_210 ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_516 * V_50 =
F_2 ( V_12 ) ;
* V_513 = F_8 ( V_50 -> V_517 ) ;
}
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_145 ( struct V_1 * V_2 , T_1 * V_208 ,
bool * V_518 , T_2 * V_200 , T_1 V_210 )
{
struct V_11 * V_12 ;
struct V_519 * V_185 ;
int V_35 ;
int V_520 ;
struct V_117 V_521 ;
int V_5 ;
memset ( & V_521 , 0 , sizeof( struct V_117 ) ) ;
V_521 . V_167 = sizeof( struct V_522 ) ;
V_521 . V_121 = F_111 ( V_2 -> V_59 ,
V_521 . V_167 ,
& V_521 . V_123 ) ;
if ( ! V_521 . V_121 ) {
F_16 ( & V_2 -> V_59 -> V_60 ,
L_19 ) ;
return - V_326 ;
}
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_112;
}
V_185 = V_521 . V_121 ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_523 , sizeof( * V_185 ) ,
V_12 , & V_521 ) ;
V_185 -> V_188 . V_210 = V_210 ;
V_185 -> V_524 = V_205 ;
V_185 -> V_525 = 1 ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_522 * V_50 =
V_521 . V_121 ;
V_520 = V_50 -> V_526 + V_50 -> V_527 ;
for ( V_5 = 0 ; V_5 < V_520 ; V_5 ++ ) {
struct V_528 * V_529 ;
T_3 V_530 ;
T_2 V_531 ;
V_529 = & V_50 -> V_532 [ V_5 ] ;
V_530 = F_22 ( V_529 -> V_530 ) ;
if ( V_530 == sizeof( T_2 ) ) {
* V_518 = true ;
V_531 = V_529 -> V_533 . V_534 . V_531 ;
* V_200 = F_8 ( V_531 ) ;
goto V_112;
}
}
* V_518 = false ;
memcpy ( V_208 , V_50 -> V_532 [ 0 ] . V_533 . V_535 ,
V_209 ) ;
}
V_112:
F_33 ( & V_2 -> V_202 ) ;
F_112 ( V_2 -> V_59 , V_521 . V_167 ,
V_521 . V_121 , V_521 . V_123 ) ;
return V_35 ;
}
int F_146 ( struct V_1 * V_2 , T_1 * V_536 ,
T_1 V_520 , T_2 V_210 )
{
struct V_11 * V_12 ;
struct V_537 * V_185 ;
int V_35 ;
struct V_117 V_417 ;
memset ( & V_417 , 0 , sizeof( struct V_117 ) ) ;
V_417 . V_167 = sizeof( struct V_537 ) ;
V_417 . V_121 = F_147 ( & V_2 -> V_59 -> V_60 , V_417 . V_167 ,
& V_417 . V_123 , V_538 ) ;
if ( ! V_417 . V_121 ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_16 ) ;
return - V_326 ;
}
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = V_417 . V_121 ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_539 , sizeof( * V_185 ) ,
V_12 , & V_417 ) ;
V_185 -> V_188 . V_210 = V_210 ;
V_185 -> V_520 = V_520 ;
if ( V_520 )
memcpy ( V_185 -> V_208 , V_536 , V_209 * V_520 ) ;
V_35 = F_45 ( V_2 ) ;
V_139:
F_148 ( & V_2 -> V_59 -> V_60 , V_417 . V_167 ,
V_417 . V_121 , V_417 . V_123 ) ;
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_149 ( struct V_1 * V_2 , T_3 V_84 ,
T_2 V_210 , T_3 V_540 )
{
struct V_11 * V_12 ;
struct V_541 * V_185 ;
void * V_222 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
V_222 = & V_185 -> V_192 ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_542 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_188 . V_210 = V_210 ;
F_84 ( struct V_543 , V_264 , V_222 , V_540 ) ;
if ( V_84 ) {
F_84 ( struct V_543 , V_544 , V_222 , 1 ) ;
F_84 ( struct V_543 , V_84 , V_222 , V_84 ) ;
}
F_67 ( V_185 -> V_192 , sizeof( V_185 -> V_192 ) ) ;
V_35 = F_45 ( V_2 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_150 ( struct V_1 * V_2 , T_3 * V_84 ,
T_2 V_210 , T_3 V_540 )
{
struct V_11 * V_12 ;
struct V_545 * V_185 ;
void * V_222 ;
int V_35 ;
T_3 V_546 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
V_222 = & V_185 -> V_192 ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_547 , sizeof( * V_185 ) , V_12 , NULL ) ;
V_185 -> V_188 . V_210 = V_210 ;
F_84 ( struct V_548 , V_264 , V_222 ,
V_540 ) ;
F_84 ( struct V_548 , V_544 , V_222 , 1 ) ;
F_67 ( V_185 -> V_192 , sizeof( V_185 -> V_192 ) ) ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_549 * V_50 =
F_2 ( V_12 ) ;
F_12 ( & V_50 -> V_192 ,
sizeof( V_50 -> V_192 ) ) ;
V_546 = F_151 ( struct V_550 ,
V_84 , & V_50 -> V_192 ) ;
* V_84 = F_22 ( V_546 ) ;
}
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_152 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_551 * V_185 ;
int V_35 ;
int V_325 = sizeof( * V_185 ) ;
struct V_117 V_417 ;
if ( ! F_1 ( V_2 , V_456 ,
V_46 ) )
return - V_215 ;
memset ( & V_417 , 0 , sizeof( struct V_117 ) ) ;
V_417 . V_167 = sizeof( struct V_552 ) ;
V_417 . V_121 = F_111 ( V_2 -> V_59 , V_417 . V_167 ,
& V_417 . V_123 ) ;
if ( ! V_417 . V_121 ) {
F_16 ( & V_2 -> V_59 -> V_60 ,
L_17 ) ;
return - V_326 ;
}
if ( F_79 ( & V_2 -> V_181 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = V_417 . V_121 ;
F_65 ( & V_185 -> V_188 , V_46 ,
V_456 ,
V_325 , V_12 , & V_417 ) ;
V_185 -> V_188 . V_160 = 1 ;
V_185 -> V_553 = V_554 ;
V_35 = F_52 ( V_2 ) ;
if ( ! V_35 ) {
struct V_552 * V_50 ;
V_50 = (struct V_552 * ) V_417 . V_121 ;
if ( V_50 -> V_188 . V_555 < V_325 ) {
V_35 = - 1 ;
goto V_139;
}
V_2 -> V_556 = V_50 -> V_557 ;
}
V_139:
F_80 ( & V_2 -> V_181 ) ;
F_112 ( V_2 -> V_59 , V_417 . V_167 , V_417 . V_121 , V_417 . V_123 ) ;
return V_35 ;
}
int F_153 ( struct V_1 * V_2 ,
struct V_117 * V_417 )
{
struct V_11 * V_12 ;
struct V_558 * V_185 ;
int V_35 ;
if ( F_79 ( & V_2 -> V_181 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = V_417 -> V_121 ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_559 ,
V_417 -> V_167 , V_12 , V_417 ) ;
V_185 -> V_560 = F_66 ( 1 ) ;
V_35 = F_52 ( V_2 ) ;
V_139:
F_80 ( & V_2 -> V_181 ) ;
return V_35 ;
}
int F_154 ( struct V_1 * V_2 ,
struct V_117 * V_417 ,
struct V_561 * V_562 )
{
struct V_11 * V_12 ;
struct V_563 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = V_417 -> V_121 ;
memcpy ( & V_185 -> V_564 , V_562 , sizeof( struct V_561 ) ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_565 ,
V_417 -> V_167 , V_12 , V_417 ) ;
V_35 = F_45 ( V_2 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_155 ( struct V_1 * V_2 , T_1 * V_566 )
{
struct V_11 * V_12 ;
struct V_567 * V_185 ;
int V_35 ;
if ( ! F_18 ( V_2 ) ) {
* V_566 = V_2 -> V_297 + '0' ;
return 0 ;
}
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_568 , sizeof( * V_185 ) , V_12 ,
NULL ) ;
V_185 -> V_188 . V_160 = 1 ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_569 * V_50 = F_2 ( V_12 ) ;
* V_566 = V_50 -> V_566 [ V_2 -> V_297 ] ;
} else {
* V_566 = V_2 -> V_297 + '0' ;
}
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
static struct V_570 * F_156 ( T_1 * V_319 , T_2 V_571 ,
T_2 V_572 )
{
struct V_570 * V_573 = (struct V_570 * ) V_319 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_571 ; V_5 ++ ) {
V_573 -> V_574 = V_575 ;
if ( ( ( void * ) V_573 + V_573 -> V_574 ) >
( void * ) ( V_319 + V_572 ) ) {
V_573 = NULL ;
break;
}
if ( V_573 -> V_576 == V_577 )
break;
V_573 = ( void * ) V_573 + V_573 -> V_574 ;
}
if ( ! V_573 || V_5 == V_578 )
return NULL ;
return V_573 ;
}
int F_157 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_579 * V_185 ;
int V_35 ;
struct V_117 V_417 ;
memset ( & V_417 , 0 , sizeof( struct V_117 ) ) ;
V_417 . V_167 = sizeof( struct V_580 ) ;
V_417 . V_121 = F_111 ( V_2 -> V_59 , V_417 . V_167 ,
& V_417 . V_123 ) ;
if ( ! V_417 . V_121 ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_16 ) ;
return - V_326 ;
}
if ( F_79 ( & V_2 -> V_181 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = V_417 . V_121 ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_581 ,
V_417 . V_167 , V_12 , & V_417 ) ;
V_35 = F_52 ( V_2 ) ;
if ( ! V_35 ) {
struct V_580 * V_50 = V_417 . V_121 ;
T_2 V_571 = F_8 ( V_50 -> V_571 ) ;
struct V_570 * V_573 ;
V_573 = F_156 ( V_50 -> V_582 , V_571 ,
sizeof( V_50 -> V_582 ) ) ;
if ( ! V_573 ) {
V_35 = - V_583 ;
goto V_139;
}
V_2 -> V_584 = V_573 -> V_585 ;
V_2 -> V_586 = F_22 ( V_573 -> V_587 ) ;
V_2 -> V_588 = F_22 ( V_573 -> V_589 ) ;
V_2 -> V_590 = F_22 ( V_573 -> V_591 ) ;
V_2 -> V_592 = F_22 ( V_573 -> V_593 ) ;
V_2 -> V_594 = F_22 ( V_573 -> V_595 ) ;
V_2 -> V_596 = F_22 ( V_573 -> V_597 ) ;
V_2 -> V_598 = F_22 ( V_573 -> V_599 ) ;
V_2 -> V_368 = F_8 ( V_573 -> V_282 ) ;
}
V_139:
F_80 ( & V_2 -> V_181 ) ;
F_112 ( V_2 -> V_59 , V_417 . V_167 ,
V_417 . V_121 , V_417 . V_123 ) ;
return V_35 ;
}
int F_158 ( struct V_1 * V_2 , T_2 * V_282 ,
T_1 V_210 )
{
struct V_11 * V_12 ;
struct V_600 * V_185 ;
int V_35 ;
struct V_117 V_417 ;
memset ( & V_417 , 0 , sizeof( struct V_117 ) ) ;
V_417 . V_167 = sizeof( struct V_601 ) ;
V_417 . V_121 = F_111 ( V_2 -> V_59 , V_417 . V_167 ,
& V_417 . V_123 ) ;
if ( ! V_417 . V_121 ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_16 ) ;
return - V_326 ;
}
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = V_417 . V_121 ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_602 ,
V_417 . V_167 , V_12 , & V_417 ) ;
V_185 -> type = V_603 ;
V_185 -> V_188 . V_210 = V_210 ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
struct V_601 * V_50 = V_417 . V_121 ;
T_2 V_571 = F_8 ( V_50 -> V_571 ) ;
struct V_570 * V_573 ;
V_573 = F_156 ( V_50 -> V_582 , V_571 ,
sizeof( V_50 -> V_582 ) ) ;
if ( ! V_573 ) {
V_35 = - V_583 ;
goto V_139;
}
* V_282 = F_8 ( V_573 -> V_282 ) ;
}
V_139:
F_33 ( & V_2 -> V_202 ) ;
F_112 ( V_2 -> V_59 , V_417 . V_167 ,
V_417 . V_121 , V_417 . V_123 ) ;
return V_35 ;
}
int F_159 ( struct V_1 * V_2 , T_2 V_492 ,
T_1 V_210 )
{
struct V_11 * V_12 ;
struct V_604 * V_185 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_605 , sizeof( * V_185 ) ,
V_12 , NULL ) ;
V_185 -> V_188 . V_210 = V_210 ;
V_185 -> V_571 = F_66 ( 1 ) ;
V_185 -> V_606 . V_576 = V_577 ;
V_185 -> V_606 . V_574 = V_575 ;
V_185 -> V_606 . V_26 = ( 1 << V_607 ) | ( 1 << V_608 ) | ( 1 << V_609 ) ;
V_185 -> V_606 . V_585 = V_2 -> V_584 ;
V_185 -> V_606 . V_610 = V_210 ;
V_185 -> V_606 . V_587 = 0xFFFF ;
V_185 -> V_606 . V_611 = 0xFFFF ;
V_185 -> V_606 . V_589 = 0xFFFF ;
V_185 -> V_606 . V_591 = 0xFFFF ;
V_185 -> V_606 . V_593 = 0xFFFF ;
V_185 -> V_606 . V_597 = 0xFFFF ;
V_185 -> V_606 . V_595 = 0xFFFF ;
V_185 -> V_606 . V_612 = 0xFFFF ;
V_185 -> V_606 . V_613 = 0xFFFF ;
V_185 -> V_606 . V_614 = 0xFFFF ;
V_185 -> V_606 . V_599 = 0xFFFF ;
V_185 -> V_606 . V_615 = 0xFF ;
V_185 -> V_606 . V_616 = 0xFFFFFFFF ;
V_185 -> V_606 . V_617 = 0xFF ;
V_185 -> V_606 . V_618 = 0x0F ;
V_185 -> V_606 . V_616 = F_66 ( V_492 ) ;
V_185 -> V_606 . V_619 = F_66 ( V_492 ) ;
V_35 = F_45 ( V_2 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_160 ( struct V_1 * V_2 , struct V_620 * V_621 ,
int V_610 )
{
struct V_11 * V_12 ;
struct V_622 * V_185 ;
struct V_623 * V_50 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_624 , sizeof( * V_50 ) ,
V_12 , NULL ) ;
V_185 -> V_188 . V_210 = V_610 + 1 ;
V_35 = F_45 ( V_2 ) ;
if ( ! V_35 ) {
V_50 = (struct V_623 * ) V_185 ;
V_621 -> V_199 = F_8 ( V_50 -> V_625 . V_206 ) ;
}
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_161 ( struct V_1 * V_2 , T_1 V_210 )
{
struct V_11 * V_12 ;
struct V_626 * V_185 ;
int V_35 ;
if ( ! F_18 ( V_2 ) )
return 0 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
F_65 ( & V_185 -> V_188 , V_40 ,
V_627 , sizeof( * V_185 ) ,
V_12 , NULL ) ;
V_185 -> V_188 . V_210 = V_210 ;
V_185 -> V_459 = 1 ;
V_35 = F_45 ( V_2 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
int F_162 ( void * V_628 , void * V_629 ,
int V_630 , T_3 * V_631 , T_3 * V_632 )
{
struct V_1 * V_2 = F_163 ( V_628 ) ;
struct V_11 * V_12 ;
struct V_153 * V_188 = (struct V_153 * ) V_629 ;
struct V_153 * V_185 ;
struct V_28 * V_50 ;
int V_35 ;
F_31 ( & V_2 -> V_202 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_203 ;
goto V_139;
}
V_185 = F_2 ( V_12 ) ;
V_50 = F_2 ( V_12 ) ;
F_65 ( V_185 , V_188 -> V_4 ,
V_188 -> V_3 , V_630 , V_12 , NULL ) ;
memcpy ( V_185 , V_629 , V_630 ) ;
F_67 ( V_185 , V_630 ) ;
V_35 = F_45 ( V_2 ) ;
if ( V_631 )
* V_631 = ( V_35 & 0xffff ) ;
if ( V_632 )
* V_632 = 0 ;
memcpy ( V_629 , V_50 , sizeof( * V_50 ) + V_50 -> V_555 ) ;
F_12 ( V_629 , sizeof( * V_50 ) + V_50 -> V_555 ) ;
V_139:
F_33 ( & V_2 -> V_202 ) ;
return V_35 ;
}
