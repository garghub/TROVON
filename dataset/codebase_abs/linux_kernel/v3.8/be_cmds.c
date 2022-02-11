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
if ( V_25 -> V_26 != 0 ) {
V_25 -> V_26 = F_8 ( V_25 -> V_26 ) ;
F_9 ( ( V_25 -> V_26 & V_27 ) == 0 ) ;
return true ;
} else {
return false ;
}
}
static inline void F_10 ( struct V_24 * V_25 )
{
V_25 -> V_26 = 0 ;
}
static struct V_28 * F_11 ( T_2 V_29 , T_2 V_30 )
{
unsigned long V_31 ;
V_31 = V_30 ;
V_31 = ( ( V_31 << 16 ) << 16 ) | V_29 ;
return ( void * ) V_31 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
T_3 V_32 , V_33 ;
struct V_28 * V_34 ;
T_1 V_3 = 0 , V_4 = 0 ;
F_13 ( V_25 , 4 ) ;
V_32 = ( V_25 -> V_35 >> V_36 ) &
V_37 ;
V_34 = F_11 ( V_25 -> V_29 , V_25 -> V_30 ) ;
if ( V_34 ) {
V_3 = V_34 -> V_3 ;
V_4 = V_34 -> V_4 ;
}
if ( ( ( V_3 == V_38 ) ||
( V_3 == V_39 ) ) &&
( V_4 == V_40 ) ) {
V_2 -> V_41 = V_32 ;
F_14 ( & V_2 -> V_42 ) ;
}
if ( V_32 == V_43 ) {
if ( ( ( V_3 == V_44 ) ||
( V_3 == V_45 ) ) &&
( V_4 == V_46 ) ) {
F_15 ( V_2 ) ;
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
F_16 ( & V_2 -> V_59 -> V_60 ,
L_1 ,
V_3 , V_4 ) ;
} else {
V_33 = ( V_25 -> V_35 >> V_61 ) &
V_62 ;
F_17 ( & V_2 -> V_59 -> V_60 ,
L_2 ,
V_3 , V_4 , V_32 , V_33 ) ;
}
}
V_57:
return V_32 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
V_2 -> V_65 . V_66 = - 1 ;
if ( F_19 ( V_2 ) &&
! ( V_64 -> V_67 & V_68 ) )
return;
if ( V_2 -> V_26 & V_69 )
F_20 ( V_2 , V_64 -> V_67 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_70 * V_64 )
{
if ( V_64 -> V_71 ) {
V_2 -> V_72 = V_64 -> V_73 ;
V_2 -> V_74 &= ~ V_75 ;
V_2 -> V_74 =
V_64 -> V_76 << V_77 ;
}
}
static void F_22 ( struct V_1 * V_2 ,
struct V_78 * V_64 )
{
if ( V_2 -> V_65 . V_66 >= 0 &&
V_64 -> V_79 == V_2 -> V_80 )
V_2 -> V_65 . V_66 = F_23 ( V_64 -> V_81 ) * 10 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_82 * V_64 )
{
if ( V_64 -> V_83 )
V_2 -> V_84 = F_23 ( V_64 -> V_85 ) & V_86 ;
else
V_2 -> V_84 = 0 ;
}
static void F_25 ( struct V_1 * V_2 ,
T_2 V_87 , struct V_24 * V_64 )
{
T_1 V_88 = 0 ;
V_88 = ( V_87 >> V_89 ) &
V_90 ;
switch ( V_88 ) {
case V_91 :
F_21 ( V_2 ,
(struct V_70 * ) V_64 ) ;
break;
case V_92 :
F_22 ( V_2 ,
(struct V_78 * ) V_64 ) ;
break;
case V_93 :
F_24 ( V_2 ,
(struct V_82 * ) V_64 ) ;
break;
default:
F_16 ( & V_2 -> V_59 -> V_60 , L_3 ) ;
break;
}
}
static inline bool F_26 ( T_2 V_87 )
{
return ( ( V_87 >> V_94 ) &
V_95 ) ==
V_96 ;
}
static inline bool F_27 ( T_2 V_87 )
{
return ( ( ( V_87 >> V_94 ) &
V_95 ) ==
V_97 ) ;
}
static struct V_24 * F_28 ( struct V_1 * V_2 )
{
struct V_14 * V_98 = & V_2 -> V_16 . V_99 ;
struct V_24 * V_25 = F_29 ( V_98 ) ;
if ( F_7 ( V_25 ) ) {
F_30 ( V_98 ) ;
return V_25 ;
}
return NULL ;
}
void F_31 ( struct V_1 * V_2 )
{
F_32 ( & V_2 -> V_100 ) ;
F_33 ( V_2 , V_2 -> V_16 . V_99 . V_19 , true , 0 ) ;
V_2 -> V_16 . V_101 = true ;
F_34 ( & V_2 -> V_100 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
F_32 ( & V_2 -> V_100 ) ;
V_2 -> V_16 . V_101 = false ;
F_33 ( V_2 , V_2 -> V_16 . V_99 . V_19 , false , 0 ) ;
F_34 ( & V_2 -> V_100 ) ;
}
int F_36 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
int V_102 = 0 , V_35 = 0 ;
struct V_103 * V_16 = & V_2 -> V_16 ;
F_37 ( & V_2 -> V_100 ) ;
while ( ( V_25 = F_28 ( V_2 ) ) ) {
if ( V_25 -> V_26 & V_104 ) {
if ( F_26 ( V_25 -> V_26 ) )
F_18 ( V_2 ,
(struct V_63 * ) V_25 ) ;
else if ( F_27 ( V_25 -> V_26 ) )
F_25 ( V_2 ,
V_25 -> V_26 , V_25 ) ;
} else if ( V_25 -> V_26 & V_105 ) {
V_35 = F_12 ( V_2 , V_25 ) ;
F_38 ( & V_16 -> V_17 . V_106 ) ;
}
F_10 ( V_25 ) ;
V_102 ++ ;
}
if ( V_102 )
F_33 ( V_2 , V_16 -> V_99 . V_19 , V_16 -> V_101 , V_102 ) ;
F_39 ( & V_2 -> V_100 ) ;
return V_35 ;
}
static int F_40 ( struct V_1 * V_2 )
{
#define F_41 120000
int V_5 , V_35 = 0 ;
struct V_103 * V_16 = & V_2 -> V_16 ;
for ( V_5 = 0 ; V_5 < F_41 ; V_5 ++ ) {
if ( F_4 ( V_2 ) )
return - V_107 ;
F_42 () ;
V_35 = F_36 ( V_2 ) ;
F_43 () ;
if ( F_44 ( & V_16 -> V_17 . V_106 ) == 0 )
break;
F_45 ( 100 ) ;
}
if ( V_5 == F_41 ) {
F_17 ( & V_2 -> V_59 -> V_60 , L_4 ) ;
V_2 -> V_108 = true ;
return - V_107 ;
}
return V_35 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_35 ;
struct V_11 * V_12 ;
struct V_103 * V_16 = & V_2 -> V_16 ;
T_3 V_109 = V_16 -> V_17 . V_110 ;
struct V_28 * V_50 ;
F_47 ( & V_109 , V_16 -> V_17 . V_111 ) ;
V_12 = F_48 ( & V_16 -> V_17 , V_109 ) ;
V_50 = F_11 ( V_12 -> V_29 , V_12 -> V_30 ) ;
F_3 ( V_2 ) ;
V_35 = F_40 ( V_2 ) ;
if ( V_35 == - V_107 )
goto V_112;
V_35 = V_50 -> V_35 ;
V_112:
return V_35 ;
}
static int F_49 ( struct V_1 * V_2 , void T_4 * V_22 )
{
int V_113 = 0 ;
T_2 V_114 ;
do {
if ( F_4 ( V_2 ) )
return - V_107 ;
V_114 = F_50 ( V_22 ) ;
if ( V_114 == 0xffffffff )
return - 1 ;
V_114 &= V_115 ;
if ( V_114 )
break;
if ( V_113 > 4000 ) {
F_17 ( & V_2 -> V_59 -> V_60 , L_4 ) ;
V_2 -> V_108 = true ;
F_51 ( V_2 ) ;
return - 1 ;
}
F_52 ( 1 ) ;
V_113 ++ ;
} while ( true );
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_35 ;
T_2 V_18 = 0 ;
void T_4 * V_22 = V_2 -> V_22 + V_116 ;
struct V_117 * V_118 = & V_2 -> V_118 ;
struct V_119 * V_120 = V_118 -> V_121 ;
struct V_24 * V_25 = & V_120 -> V_25 ;
V_35 = F_49 ( V_2 , V_22 ) ;
if ( V_35 != 0 )
return V_35 ;
V_18 |= V_122 ;
V_18 |= ( F_54 ( V_118 -> V_123 ) >> 2 ) << 2 ;
F_6 ( V_18 , V_22 ) ;
V_35 = F_49 ( V_2 , V_22 ) ;
if ( V_35 != 0 )
return V_35 ;
V_18 = 0 ;
V_18 |= ( T_2 ) ( V_118 -> V_123 >> 4 ) << 2 ;
F_6 ( V_18 , V_22 ) ;
V_35 = F_49 ( V_2 , V_22 ) ;
if ( V_35 != 0 )
return V_35 ;
if ( F_7 ( V_25 ) ) {
V_35 = F_12 ( V_2 , & V_120 -> V_25 ) ;
F_10 ( V_25 ) ;
if ( V_35 )
return V_35 ;
} else {
F_17 ( & V_2 -> V_59 -> V_60 , L_5 ) ;
return - 1 ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , T_3 * V_124 )
{
T_2 V_125 ;
T_2 V_126 = F_56 ( V_2 ) ? V_127 :
V_128 ;
F_57 ( V_2 -> V_59 , V_126 , & V_125 ) ;
* V_124 = V_125 & V_129 ;
if ( ( V_125 >> V_130 ) & V_131 )
return - 1 ;
else
return 0 ;
}
int F_58 ( struct V_1 * V_2 )
{
#define F_59 30
T_2 V_132 ;
int V_35 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < F_59 ; V_5 ++ ) {
V_132 = F_50 ( V_2 -> V_22 + V_133 ) ;
if ( V_132 & V_134 )
break;
F_52 ( 1000 ) ;
}
if ( V_5 == F_59 )
V_35 = - 1 ;
return V_35 ;
}
static bool F_60 ( struct V_1 * V_2 )
{
T_2 V_132 = 0 , V_135 = 0 , V_136 = 0 ;
V_132 = F_50 ( V_2 -> V_22 + V_133 ) ;
if ( V_132 & V_137 ) {
V_135 = F_50 ( V_2 -> V_22 +
V_138 ) ;
V_136 = F_50 ( V_2 -> V_22 +
V_139 ) ;
if ( V_135 == V_140 &&
V_136 == V_141 )
return true ;
}
return false ;
}
int F_61 ( struct V_1 * V_2 )
{
int V_35 ;
T_2 V_132 , V_142 , V_143 ;
bool V_144 ;
V_144 = F_60 ( V_2 ) ;
if ( V_144 )
return - 1 ;
V_35 = F_58 ( V_2 ) ;
if ( ! V_35 ) {
V_132 = F_50 ( V_2 -> V_22 + V_133 ) ;
V_142 = V_132 & V_137 ;
V_143 = V_132 & V_145 ;
if ( V_142 && V_143 ) {
F_6 ( V_146 ,
V_2 -> V_22 + V_147 ) ;
V_35 = F_58 ( V_2 ) ;
V_132 = F_50 ( V_2 -> V_22 +
V_133 ) ;
V_132 &= ( V_137 |
V_145 ) ;
if ( V_35 || V_132 )
V_35 = - 1 ;
} else if ( V_142 || V_143 ) {
V_35 = - 1 ;
}
}
V_144 = F_60 ( V_2 ) ;
if ( V_35 == - 1 && ! V_144 )
V_2 -> V_148 = true ;
return V_35 ;
}
int F_62 ( struct V_1 * V_2 )
{
T_3 V_124 ;
int V_35 , V_149 = 0 ;
struct V_150 * V_60 = & V_2 -> V_59 -> V_60 ;
if ( F_19 ( V_2 ) ) {
V_35 = F_58 ( V_2 ) ;
return V_35 ;
}
do {
V_35 = F_55 ( V_2 , & V_124 ) ;
if ( V_35 ) {
F_17 ( V_60 , L_6 , V_124 ) ;
return - 1 ;
} else if ( V_124 != V_151 ) {
if ( F_63 ( 2000 ) ) {
F_17 ( V_60 , L_7 ) ;
return - V_152 ;
}
V_149 += 2 ;
} else {
return 0 ;
}
} while ( V_149 < 60 );
F_17 ( V_60 , L_8 , V_124 ) ;
return - 1 ;
}
static inline struct V_153 * F_64 ( struct V_11 * V_12 )
{
return & V_12 -> V_13 . V_154 [ 0 ] ;
}
static void F_65 ( struct V_155 * V_156 ,
T_1 V_4 , T_1 V_3 , int V_157 ,
struct V_11 * V_12 , struct V_117 * V_158 )
{
struct V_153 * V_159 ;
unsigned long V_31 = ( unsigned long ) V_156 ;
T_5 V_160 = V_31 ;
V_156 -> V_3 = V_3 ;
V_156 -> V_4 = V_4 ;
V_156 -> V_161 = F_66 ( V_157 - sizeof( * V_156 ) ) ;
V_156 -> V_162 = 0 ;
V_12 -> V_29 = V_160 & 0xFFFFFFFF ;
V_12 -> V_30 = F_54 ( V_160 ) ;
V_12 -> V_163 = V_157 ;
if ( V_158 ) {
V_12 -> V_164 |= ( 1 & V_165 ) <<
V_166 ;
V_159 = F_64 ( V_12 ) ;
V_159 -> V_167 = F_66 ( F_54 ( V_158 -> V_123 ) ) ;
V_159 -> V_168 = F_66 ( V_158 -> V_123 & 0xFFFFFFFF ) ;
V_159 -> V_111 = F_66 ( V_158 -> V_169 ) ;
} else
V_12 -> V_164 |= V_170 ;
F_67 ( V_12 , 8 ) ;
}
static void F_68 ( struct V_171 * V_172 , T_2 V_173 ,
struct V_117 * V_158 )
{
int V_5 , V_174 = F_69 ( F_70 ( V_158 -> V_121 , V_158 -> V_169 ) , V_173 ) ;
T_5 V_123 = ( T_5 ) V_158 -> V_123 ;
for ( V_5 = 0 ; V_5 < V_174 ; V_5 ++ ) {
V_172 [ V_5 ] . V_175 = F_66 ( V_123 & 0xFFFFFFFF ) ;
V_172 [ V_5 ] . V_176 = F_66 ( F_54 ( V_123 ) ) ;
V_123 += V_177 ;
}
}
static T_2 F_71 ( T_2 V_178 )
{
#define F_72 651042
const T_2 V_179 = 10 ;
T_2 V_180 ;
if ( V_178 == 0 )
V_180 = 0 ;
else {
T_2 V_181 = 1000000 / V_178 ;
if ( V_181 == 0 )
V_180 = 1023 ;
else {
V_180 = ( F_72 - V_181 ) * V_179 ;
V_180 /= V_181 ;
V_180 = ( V_180 + V_179 / 2 ) / V_179 ;
V_180 = F_69 ( V_180 , ( T_2 ) 1023 ) ;
}
}
return V_180 ;
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
if ( ! V_15 -> V_182 )
return NULL ;
if ( F_44 ( & V_15 -> V_106 ) >= V_15 -> V_111 ) {
F_17 ( & V_2 -> V_59 -> V_60 , L_9 ) ;
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
if ( F_19 ( V_2 ) )
return 0 ;
if ( F_79 ( & V_2 -> V_183 ) )
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
V_35 = F_53 ( V_2 ) ;
F_80 ( & V_2 -> V_183 ) ;
return V_35 ;
}
int F_81 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_35 ;
if ( F_19 ( V_2 ) )
return 0 ;
if ( F_79 ( & V_2 -> V_183 ) )
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
V_35 = F_53 ( V_2 ) ;
F_80 ( & V_2 -> V_183 ) ;
return V_35 ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_14 * V_184 , int V_185 )
{
struct V_11 * V_12 ;
struct V_186 * V_187 ;
struct V_117 * V_188 = & V_184 -> V_189 ;
int V_35 ;
if ( F_79 ( & V_2 -> V_183 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_191 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_192 = F_83 ( F_70 ( V_188 -> V_121 , V_188 -> V_169 ) ) ;
F_84 ( struct V_193 , V_71 , V_187 -> V_194 , 1 ) ;
F_84 ( struct V_193 , V_169 , V_187 -> V_194 , 0 ) ;
F_84 ( struct V_193 , V_195 , V_187 -> V_194 ,
F_85 ( V_184 -> V_111 / 256 ) ) ;
F_84 ( struct V_193 , V_196 , V_187 -> V_194 ,
F_71 ( V_185 ) ) ;
F_67 ( V_187 -> V_194 , sizeof( V_187 -> V_194 ) ) ;
F_68 ( V_187 -> V_172 , F_86 ( V_187 -> V_172 ) , V_188 ) ;
V_35 = F_53 ( V_2 ) ;
if ( ! V_35 ) {
struct V_197 * V_50 = F_2 ( V_12 ) ;
V_184 -> V_19 = F_23 ( V_50 -> V_198 ) ;
V_184 -> V_182 = true ;
}
F_80 ( & V_2 -> V_183 ) ;
return V_35 ;
}
int F_87 ( struct V_1 * V_2 , T_1 * V_199 ,
bool V_200 , T_2 V_201 , T_2 V_202 )
{
struct V_11 * V_12 ;
struct V_203 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_206 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> type = V_207 ;
if ( V_200 ) {
V_187 -> V_200 = 1 ;
} else {
V_187 -> V_208 = F_83 ( ( T_3 ) V_201 ) ;
V_187 -> V_202 = F_66 ( V_202 ) ;
V_187 -> V_200 = 0 ;
}
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_209 * V_50 = F_2 ( V_12 ) ;
memcpy ( V_199 , V_50 -> V_210 . V_31 , V_211 ) ;
}
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_88 ( struct V_1 * V_2 , T_1 * V_199 ,
T_2 V_208 , T_2 * V_202 , T_2 V_212 )
{
struct V_11 * V_12 ;
struct V_213 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_214 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_190 . V_212 = V_212 ;
V_187 -> V_208 = F_66 ( V_208 ) ;
memcpy ( V_187 -> V_215 , V_199 , V_211 ) ;
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_216 * V_50 = F_2 ( V_12 ) ;
* V_202 = F_8 ( V_50 -> V_202 ) ;
}
V_142:
F_34 ( & V_2 -> V_204 ) ;
if ( V_35 == V_58 )
V_35 = - V_217 ;
return V_35 ;
}
int F_89 ( struct V_1 * V_2 , T_2 V_208 , int V_202 , T_2 V_218 )
{
struct V_11 * V_12 ;
struct V_219 * V_187 ;
int V_35 ;
if ( V_202 == - 1 )
return 0 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_220 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_190 . V_212 = V_218 ;
V_187 -> V_208 = F_66 ( V_208 ) ;
V_187 -> V_202 = F_66 ( V_202 ) ;
V_35 = F_46 ( V_2 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_90 ( struct V_1 * V_2 , struct V_14 * V_99 ,
struct V_14 * V_184 , bool V_221 , int V_222 )
{
struct V_11 * V_12 ;
struct V_223 * V_187 ;
struct V_117 * V_188 = & V_99 -> V_189 ;
void * V_224 ;
int V_35 ;
if ( F_79 ( & V_2 -> V_183 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
V_187 = F_2 ( V_12 ) ;
V_224 = & V_187 -> V_194 ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_225 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_192 = F_83 ( F_70 ( V_188 -> V_121 , V_188 -> V_169 ) ) ;
if ( F_19 ( V_2 ) ) {
V_187 -> V_190 . V_162 = 2 ;
V_187 -> V_226 = 1 ;
F_84 ( struct V_227 , V_228 , V_224 ,
V_221 ) ;
F_84 ( struct V_227 , V_195 , V_224 ,
F_85 ( V_99 -> V_111 / 256 ) ) ;
F_84 ( struct V_227 , V_71 , V_224 , 1 ) ;
F_84 ( struct V_227 , V_229 ,
V_224 , 1 ) ;
F_84 ( struct V_227 , V_230 ,
V_224 , V_184 -> V_19 ) ;
} else {
F_84 ( struct V_231 , V_232 , V_224 ,
V_222 ) ;
F_84 ( struct V_231 , V_228 ,
V_224 , V_221 ) ;
F_84 ( struct V_231 , V_195 , V_224 ,
F_85 ( V_99 -> V_111 / 256 ) ) ;
F_84 ( struct V_231 , V_71 , V_224 , 1 ) ;
F_84 ( struct V_231 , V_229 , V_224 , 1 ) ;
F_84 ( struct V_231 , V_230 , V_224 , V_184 -> V_19 ) ;
}
F_67 ( V_224 , sizeof( V_187 -> V_194 ) ) ;
F_68 ( V_187 -> V_172 , F_86 ( V_187 -> V_172 ) , V_188 ) ;
V_35 = F_53 ( V_2 ) ;
if ( ! V_35 ) {
struct V_233 * V_50 = F_2 ( V_12 ) ;
V_99 -> V_19 = F_23 ( V_50 -> V_234 ) ;
V_99 -> V_182 = true ;
}
F_80 ( & V_2 -> V_183 ) ;
return V_35 ;
}
static T_2 F_91 ( int V_235 )
{
T_2 V_236 = F_92 ( V_235 ) ;
if ( V_236 == 16 )
V_236 = 0 ;
return V_236 ;
}
int F_93 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_99 )
{
struct V_11 * V_12 ;
struct V_237 * V_187 ;
struct V_117 * V_188 = & V_15 -> V_189 ;
void * V_224 ;
int V_35 ;
if ( F_79 ( & V_2 -> V_183 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
V_187 = F_2 ( V_12 ) ;
V_224 = & V_187 -> V_194 ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_238 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_192 = F_83 ( F_70 ( V_188 -> V_121 , V_188 -> V_169 ) ) ;
if ( F_19 ( V_2 ) ) {
V_187 -> V_190 . V_162 = 1 ;
V_187 -> V_234 = F_83 ( V_99 -> V_19 ) ;
F_84 ( struct V_239 , V_240 , V_224 ,
F_91 ( V_15 -> V_111 ) ) ;
F_84 ( struct V_239 , V_71 , V_224 , 1 ) ;
F_84 ( struct V_239 , V_241 ,
V_224 , V_99 -> V_19 ) ;
F_84 ( struct V_239 , V_242 ,
V_224 , 1 ) ;
} else {
F_84 ( struct V_243 , V_71 , V_224 , 1 ) ;
F_84 ( struct V_243 , V_240 , V_224 ,
F_91 ( V_15 -> V_111 ) ) ;
F_84 ( struct V_243 , V_234 , V_224 , V_99 -> V_19 ) ;
}
V_187 -> V_244 [ 0 ] = F_66 ( 0x00000022 ) ;
F_67 ( V_224 , sizeof( V_187 -> V_194 ) ) ;
F_68 ( V_187 -> V_172 , F_86 ( V_187 -> V_172 ) , V_188 ) ;
V_35 = F_53 ( V_2 ) ;
if ( ! V_35 ) {
struct V_245 * V_50 = F_2 ( V_12 ) ;
V_15 -> V_19 = F_23 ( V_50 -> V_19 ) ;
V_15 -> V_182 = true ;
}
F_80 ( & V_2 -> V_183 ) ;
return V_35 ;
}
int F_94 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_99 )
{
struct V_11 * V_12 ;
struct V_246 * V_187 ;
struct V_117 * V_188 = & V_15 -> V_189 ;
void * V_224 ;
int V_35 ;
if ( F_79 ( & V_2 -> V_183 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
V_187 = F_2 ( V_12 ) ;
V_224 = & V_187 -> V_194 ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_247 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_192 = F_83 ( F_70 ( V_188 -> V_121 , V_188 -> V_169 ) ) ;
F_84 ( struct V_243 , V_71 , V_224 , 1 ) ;
F_84 ( struct V_243 , V_240 , V_224 ,
F_91 ( V_15 -> V_111 ) ) ;
F_84 ( struct V_243 , V_234 , V_224 , V_99 -> V_19 ) ;
F_67 ( V_224 , sizeof( V_187 -> V_194 ) ) ;
F_68 ( V_187 -> V_172 , F_86 ( V_187 -> V_172 ) , V_188 ) ;
V_35 = F_53 ( V_2 ) ;
if ( ! V_35 ) {
struct V_245 * V_50 = F_2 ( V_12 ) ;
V_15 -> V_19 = F_23 ( V_50 -> V_19 ) ;
V_15 -> V_182 = true ;
}
F_80 ( & V_2 -> V_183 ) ;
return V_35 ;
}
int F_95 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_99 )
{
int V_35 ;
V_35 = F_93 ( V_2 , V_15 , V_99 ) ;
if ( V_35 && ! F_19 ( V_2 ) ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_10
L_11
L_12 ) ;
V_35 = F_94 ( V_2 , V_15 , V_99 ) ;
}
return V_35 ;
}
int F_96 ( struct V_1 * V_2 ,
struct V_14 * V_248 ,
struct V_14 * V_99 )
{
struct V_11 * V_12 ;
struct V_249 * V_187 ;
struct V_117 * V_188 = & V_248 -> V_189 ;
void * V_224 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
V_224 = & V_187 -> V_194 ;
F_65 ( & V_187 -> V_190 , V_46 ,
V_250 , sizeof( * V_187 ) , V_12 , NULL ) ;
if ( F_19 ( V_2 ) ) {
V_187 -> V_190 . V_162 = 1 ;
F_84 ( struct V_251 , V_208 , V_224 ,
V_2 -> V_201 ) ;
}
V_187 -> V_192 = F_70 ( V_188 -> V_121 , V_188 -> V_169 ) ;
V_187 -> V_252 = V_253 ;
V_187 -> type = V_254 ;
F_84 ( struct V_251 , V_255 , V_224 ,
F_91 ( V_248 -> V_111 ) ) ;
F_84 ( struct V_251 , V_256 , V_224 , 1 ) ;
F_84 ( struct V_251 , V_257 , V_224 , V_99 -> V_19 ) ;
F_67 ( V_224 , sizeof( V_187 -> V_194 ) ) ;
F_68 ( V_187 -> V_172 , F_86 ( V_187 -> V_172 ) , V_188 ) ;
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_258 * V_50 = F_2 ( V_12 ) ;
V_248 -> V_19 = F_23 ( V_50 -> V_259 ) ;
V_248 -> V_182 = true ;
}
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_97 ( struct V_1 * V_2 ,
struct V_14 * V_260 , T_3 V_234 , T_3 V_261 ,
T_2 V_208 , T_2 V_262 , T_1 * V_263 )
{
struct V_11 * V_12 ;
struct V_264 * V_187 ;
struct V_117 * V_188 = & V_260 -> V_189 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_46 ,
V_265 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_234 = F_83 ( V_234 ) ;
V_187 -> V_261 = F_92 ( V_261 ) - 1 ;
V_187 -> V_192 = 2 ;
F_68 ( V_187 -> V_172 , F_86 ( V_187 -> V_172 ) , V_188 ) ;
V_187 -> V_266 = F_66 ( V_208 ) ;
V_187 -> V_267 = F_83 ( V_268 ) ;
V_187 -> V_269 = F_66 ( V_262 ) ;
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_270 * V_50 = F_2 ( V_12 ) ;
V_260 -> V_19 = F_23 ( V_50 -> V_19 ) ;
V_260 -> V_182 = true ;
* V_263 = V_50 -> V_263 ;
}
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_98 ( struct V_1 * V_2 , struct V_14 * V_17 ,
int V_271 )
{
struct V_11 * V_12 ;
struct V_272 * V_187 ;
T_1 V_273 = 0 , V_3 = 0 ;
int V_35 ;
if ( F_79 ( & V_2 -> V_183 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
V_187 = F_2 ( V_12 ) ;
switch ( V_271 ) {
case V_274 :
V_273 = V_40 ;
V_3 = V_275 ;
break;
case V_276 :
V_273 = V_40 ;
V_3 = V_277 ;
break;
case V_278 :
V_273 = V_46 ;
V_3 = V_279 ;
break;
case V_280 :
V_273 = V_46 ;
V_3 = V_281 ;
break;
case V_282 :
V_273 = V_40 ;
V_3 = V_283 ;
break;
default:
F_99 () ;
}
F_65 ( & V_187 -> V_190 , V_273 , V_3 , sizeof( * V_187 ) , V_12 ,
NULL ) ;
V_187 -> V_19 = F_83 ( V_17 -> V_19 ) ;
V_35 = F_53 ( V_2 ) ;
V_17 -> V_182 = false ;
F_80 ( & V_2 -> V_183 ) ;
return V_35 ;
}
int F_100 ( struct V_1 * V_2 , struct V_14 * V_17 )
{
struct V_11 * V_12 ;
struct V_272 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_46 ,
V_281 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_19 = F_83 ( V_17 -> V_19 ) ;
V_35 = F_46 ( V_2 ) ;
V_17 -> V_182 = false ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_101 ( struct V_1 * V_2 , T_2 V_284 , T_2 V_285 ,
T_2 * V_201 , T_2 V_212 )
{
struct V_11 * V_12 ;
struct V_286 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_287 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_190 . V_212 = V_212 ;
V_187 -> V_288 = F_66 ( V_284 ) ;
V_187 -> V_289 = F_66 ( V_285 ) ;
V_187 -> V_290 = true ;
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_291 * V_50 = F_2 ( V_12 ) ;
* V_201 = F_8 ( V_50 -> V_266 ) ;
}
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_102 ( struct V_1 * V_2 , int V_266 , T_2 V_212 )
{
struct V_11 * V_12 ;
struct V_292 * V_187 ;
int V_35 ;
if ( V_266 == - 1 )
return 0 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_293 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_190 . V_212 = V_212 ;
V_187 -> V_266 = F_66 ( V_266 ) ;
V_35 = F_46 ( V_2 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_103 ( struct V_1 * V_2 , struct V_117 * V_294 )
{
struct V_11 * V_12 ;
struct V_155 * V_190 ;
int V_35 = 0 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_190 = V_294 -> V_121 ;
F_65 ( V_190 , V_46 ,
V_44 , V_294 -> V_169 , V_12 , V_294 ) ;
if ( ! F_104 ( V_2 ) )
V_190 -> V_162 = 1 ;
F_3 ( V_2 ) ;
V_2 -> V_47 = true ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_105 ( struct V_1 * V_2 ,
struct V_117 * V_294 )
{
struct V_11 * V_12 ;
struct V_295 * V_187 ;
int V_35 = 0 ;
if ( ! F_1 ( V_2 , V_45 ,
V_46 ) )
return - V_217 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = V_294 -> V_121 ;
F_65 ( & V_187 -> V_190 , V_46 ,
V_45 , V_294 -> V_169 , V_12 ,
V_294 ) ;
V_187 -> V_296 . V_297 . V_298 = F_83 ( V_2 -> V_299 ) ;
V_187 -> V_296 . V_297 . V_300 = 0 ;
F_3 ( V_2 ) ;
V_2 -> V_47 = true ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
static int F_106 ( int V_301 )
{
switch ( V_301 ) {
case V_302 :
return 0 ;
case V_303 :
return 10 ;
case V_304 :
return 100 ;
case V_305 :
return 1000 ;
case V_306 :
return 10000 ;
}
return 0 ;
}
int F_107 ( struct V_1 * V_2 , T_3 * V_66 ,
T_1 * V_307 , T_2 V_218 )
{
struct V_11 * V_12 ;
struct V_308 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
if ( V_307 )
* V_307 = V_309 ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_310 , sizeof( * V_187 ) , V_12 , NULL ) ;
if ( ! F_104 ( V_2 ) )
V_187 -> V_190 . V_162 = 1 ;
V_187 -> V_190 . V_212 = V_218 ;
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_311 * V_50 = F_2 ( V_12 ) ;
if ( V_66 ) {
* V_66 = V_50 -> V_66 ?
F_23 ( V_50 -> V_66 ) * 10 :
F_106 ( V_50 -> V_301 ) ;
if ( ! V_50 -> V_312 )
* V_66 = 0 ;
}
if ( V_307 )
* V_307 = V_50 -> V_312 ;
}
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_108 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_313 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_48 , sizeof( * V_187 ) ,
V_12 , NULL ) ;
F_3 ( V_2 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_109 ( struct V_1 * V_2 , T_2 * V_314 )
{
struct V_11 * V_12 ;
struct V_315 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_316 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_317 = F_66 ( V_318 ) ;
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_319 * V_50 = F_2 ( V_12 ) ;
if ( V_314 && V_50 -> V_314 )
* V_314 = F_8 ( V_50 -> V_314 ) -
sizeof( T_2 ) ;
}
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
void F_110 ( struct V_1 * V_2 , T_2 V_320 , void * V_321 )
{
struct V_117 V_322 ;
struct V_11 * V_12 ;
struct V_315 * V_187 ;
T_2 V_323 = 0 , V_324 , V_325 ,
V_326 = sizeof( T_2 ) , V_327 ;
int V_35 ;
if ( V_320 == 0 )
return;
V_324 = V_320 ;
V_322 . V_169 = sizeof( struct V_315 ) + 60 * 1024 ;
V_322 . V_121 = F_111 ( V_2 -> V_59 ,
V_322 . V_169 ,
& V_322 . V_123 ) ;
if ( ! V_322 . V_121 ) {
V_35 = - V_328 ;
F_17 ( & V_2 -> V_59 -> V_60 ,
L_13 ) ;
return;
}
F_32 ( & V_2 -> V_204 ) ;
while ( V_324 ) {
V_325 = F_69 ( V_324 , ( T_2 ) 60 * 1024 ) ;
V_324 -= V_325 ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = V_322 . V_121 ;
V_327 = sizeof( struct V_315 ) + V_325 ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_316 , V_327 , V_12 ,
& V_322 ) ;
V_187 -> V_317 = F_66 ( V_329 ) ;
V_187 -> V_330 = F_66 ( V_326 ) ;
V_187 -> V_331 = F_66 ( V_325 ) ;
V_187 -> V_332 = F_66 ( V_325 ) ;
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_319 * V_50 = V_322 . V_121 ;
memcpy ( V_321 + V_323 ,
V_50 -> V_333 ,
F_8 ( V_50 -> V_331 ) ) ;
} else {
F_17 ( & V_2 -> V_59 -> V_60 , L_14 ) ;
goto V_142;
}
V_323 += V_325 ;
V_326 += V_325 ;
}
V_142:
F_112 ( V_2 -> V_59 , V_322 . V_169 ,
V_322 . V_121 ,
V_322 . V_123 ) ;
F_34 ( & V_2 -> V_204 ) ;
}
int F_113 ( struct V_1 * V_2 , char * V_334 ,
char * V_335 )
{
struct V_11 * V_12 ;
struct V_336 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_337 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_338 * V_50 = F_2 ( V_12 ) ;
strcpy ( V_334 , V_50 -> V_339 ) ;
if ( V_335 )
strcpy ( V_335 , V_50 -> V_340 ) ;
}
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_114 ( struct V_1 * V_2 , T_2 V_198 , T_2 V_341 )
{
struct V_11 * V_12 ;
struct V_342 * V_187 ;
int V_35 = 0 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_343 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_344 = F_66 ( 1 ) ;
V_187 -> V_345 [ 0 ] . V_198 = F_66 ( V_198 ) ;
V_187 -> V_345 [ 0 ] . V_346 = 0 ;
V_187 -> V_345 [ 0 ] . V_347 = F_66 ( V_341 ) ;
F_3 ( V_2 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_115 ( struct V_1 * V_2 , T_2 V_208 , T_3 * V_348 ,
T_2 V_102 , bool V_349 , bool V_350 )
{
struct V_11 * V_12 ;
struct V_351 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_352 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_266 = V_208 ;
V_187 -> V_350 = V_350 ;
V_187 -> V_349 = V_349 ;
V_187 -> V_353 = V_102 ;
if ( ! V_350 ) {
memcpy ( V_187 -> V_354 , V_348 ,
V_187 -> V_353 * sizeof( V_348 [ 0 ] ) ) ;
}
V_35 = F_46 ( V_2 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_116 ( struct V_1 * V_2 , T_2 V_26 , T_2 V_355 )
{
struct V_11 * V_12 ;
struct V_117 * V_158 = & V_2 -> V_356 ;
struct V_357 * V_187 = V_158 -> V_121 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
memset ( V_187 , 0 , sizeof( * V_187 ) ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_358 , sizeof( * V_187 ) ,
V_12 , V_158 ) ;
V_187 -> V_208 = F_66 ( V_2 -> V_201 ) ;
if ( V_26 & V_359 ) {
V_187 -> V_360 = F_66 ( V_361 |
V_362 ) ;
if ( V_355 == V_363 )
V_187 -> V_364 = F_66 ( V_361 |
V_362 ) ;
} else if ( V_26 & V_365 ) {
V_187 -> V_360 = V_187 -> V_364 =
F_66 ( V_366 ) ;
} else {
struct V_367 * V_368 ;
int V_5 = 0 ;
V_187 -> V_360 = V_187 -> V_364 =
F_66 ( V_369 ) ;
V_187 -> V_360 |=
F_66 ( V_366 &
V_2 -> V_370 ) ;
V_187 -> V_371 = F_66 ( F_117 ( V_2 -> V_372 ) ) ;
F_118 (ha, adapter->netdev)
memcpy ( V_187 -> V_373 [ V_5 ++ ] . V_374 , V_368 -> V_31 , V_211 ) ;
}
V_35 = F_46 ( V_2 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_119 ( struct V_1 * V_2 , T_2 V_375 , T_2 V_376 )
{
struct V_11 * V_12 ;
struct V_377 * V_187 ;
int V_35 ;
if ( ! F_1 ( V_2 , V_378 ,
V_40 ) )
return - V_217 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_378 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_379 = F_83 ( ( T_3 ) V_375 ) ;
V_187 -> V_380 = F_83 ( ( T_3 ) V_376 ) ;
V_35 = F_46 ( V_2 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_120 ( struct V_1 * V_2 , T_2 * V_375 , T_2 * V_376 )
{
struct V_11 * V_12 ;
struct V_381 * V_187 ;
int V_35 ;
if ( ! F_1 ( V_2 , V_382 ,
V_40 ) )
return - V_217 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_382 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_383 * V_50 =
F_2 ( V_12 ) ;
* V_375 = F_23 ( V_50 -> V_379 ) ;
* V_376 = F_23 ( V_50 -> V_380 ) ;
}
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_121 ( struct V_1 * V_2 , T_2 * V_80 ,
T_2 * V_384 , T_2 * V_385 )
{
struct V_11 * V_12 ;
struct V_386 * V_187 ;
int V_35 ;
if ( F_79 ( & V_2 -> V_183 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_387 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_35 = F_53 ( V_2 ) ;
if ( ! V_35 ) {
struct V_388 * V_50 = F_2 ( V_12 ) ;
* V_80 = F_8 ( V_50 -> V_389 ) ;
* V_384 = F_8 ( V_50 -> V_390 ) ;
* V_385 = F_8 ( V_50 -> V_391 ) ;
}
F_80 ( & V_2 -> V_183 ) ;
return V_35 ;
}
int F_122 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_155 * V_187 ;
int V_35 ;
if ( F_19 ( V_2 ) ) {
V_35 = F_58 ( V_2 ) ;
if ( ! V_35 ) {
F_6 ( V_146 ,
V_2 -> V_22 + V_147 ) ;
V_35 = F_61 ( V_2 ) ;
}
if ( V_35 ) {
F_17 ( & V_2 -> V_59 -> V_60 ,
L_15 ) ;
}
return V_35 ;
}
if ( F_79 ( & V_2 -> V_183 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
V_187 = F_2 ( V_12 ) ;
F_65 ( V_187 , V_40 ,
V_392 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_35 = F_53 ( V_2 ) ;
F_80 ( & V_2 -> V_183 ) ;
return V_35 ;
}
int F_123 ( struct V_1 * V_2 , T_1 * V_393 , T_3 V_394 )
{
struct V_11 * V_12 ;
struct V_395 * V_187 ;
T_2 V_396 [ 10 ] = { 0x15d43fa5 , 0x2534685a , 0x5f87693a , 0x5668494e ,
0x33cf6a53 , 0x383334c6 , 0x76ac4257 , 0x59b242b2 ,
0x3ea83c02 , 0x4a110304 } ;
int V_35 ;
if ( F_79 ( & V_2 -> V_183 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_46 ,
V_397 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_208 = F_66 ( V_2 -> V_201 ) ;
V_187 -> V_398 = F_83 ( V_399 | V_400 |
V_401 | V_402 ) ;
if ( F_19 ( V_2 ) || F_56 ( V_2 ) ) {
V_187 -> V_190 . V_162 = 1 ;
V_187 -> V_398 |= F_83 ( V_403 |
V_404 ) ;
}
V_187 -> V_405 = F_83 ( F_92 ( V_394 ) - 1 ) ;
memcpy ( V_187 -> V_406 , V_393 , V_394 ) ;
memcpy ( V_187 -> V_407 , V_396 , sizeof( V_396 ) ) ;
F_67 ( V_187 -> V_407 , sizeof( V_187 -> V_407 ) ) ;
V_35 = F_53 ( V_2 ) ;
F_80 ( & V_2 -> V_183 ) ;
return V_35 ;
}
int F_124 ( struct V_1 * V_2 , T_1 V_80 ,
T_1 V_408 , T_1 V_409 , T_1 V_410 )
{
struct V_11 * V_12 ;
struct V_411 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_412 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_80 = V_80 ;
V_187 -> V_413 = V_410 ;
V_187 -> V_414 = V_408 ;
V_187 -> V_415 = V_409 ;
V_35 = F_46 ( V_2 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_125 ( struct V_1 * V_2 , T_1 V_80 , T_2 * V_410 )
{
struct V_11 * V_12 ;
struct V_416 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_417 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_80 = V_80 ;
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_418 * V_50 =
F_2 ( V_12 ) ;
* V_410 = V_50 -> V_413 ;
}
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_126 ( struct V_1 * V_2 , struct V_117 * V_419 ,
T_2 V_420 , T_2 V_421 ,
const char * V_422 , T_2 * V_423 ,
T_1 * V_424 , T_1 * V_425 )
{
struct V_11 * V_12 ;
struct V_426 * V_187 ;
struct V_427 * V_50 ;
void * V_224 = NULL ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_2 -> V_41 = 0 ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_428;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_39 ,
sizeof( struct V_426 ) , V_12 ,
NULL ) ;
V_224 = & V_187 -> V_194 ;
F_84 ( struct V_429 ,
V_430 , V_224 , V_420 ) ;
if ( V_420 == 0 )
F_84 ( struct V_429 ,
V_431 , V_224 , 1 ) ;
else
F_84 ( struct V_429 ,
V_431 , V_224 , 0 ) ;
F_67 ( V_224 , sizeof( V_187 -> V_194 ) ) ;
V_187 -> V_432 = F_66 ( V_421 ) ;
strcpy ( V_187 -> V_433 , V_422 ) ;
V_187 -> V_434 = F_66 ( 1 ) ;
V_187 -> V_320 = F_66 ( V_420 ) ;
V_187 -> V_435 = F_66 ( ( V_419 -> V_123 +
sizeof( struct V_426 ) )
& 0xFFFFFFFF ) ;
V_187 -> V_436 = F_66 ( F_54 ( V_419 -> V_123 +
sizeof( struct V_426 ) ) ) ;
F_3 ( V_2 ) ;
F_34 ( & V_2 -> V_204 ) ;
if ( ! F_127 ( & V_2 -> V_42 ,
F_128 ( 30000 ) ) )
V_35 = - 1 ;
else
V_35 = V_2 -> V_41 ;
V_50 = F_2 ( V_12 ) ;
if ( ! V_35 ) {
* V_423 = F_8 ( V_50 -> V_437 ) ;
* V_424 = V_50 -> V_424 ;
} else {
* V_425 = V_50 -> V_438 ;
}
return V_35 ;
V_428:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_129 ( struct V_1 * V_2 , struct V_117 * V_419 ,
T_2 V_420 , T_2 V_421 , const char * V_422 ,
T_2 * V_439 , T_2 * V_431 , T_1 * V_425 )
{
struct V_11 * V_12 ;
struct V_440 * V_187 ;
struct V_441 * V_50 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_428;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_442 ,
sizeof( struct V_440 ) , V_12 ,
NULL ) ;
V_187 -> V_443 = F_66 ( V_420 ) ;
V_187 -> V_444 = F_66 ( V_421 ) ;
strcpy ( V_187 -> V_433 , V_422 ) ;
V_187 -> V_434 = F_66 ( 1 ) ;
V_187 -> V_320 = F_66 ( V_420 ) ;
V_187 -> V_435 = F_66 ( ( V_419 -> V_123 & 0xFFFFFFFF ) ) ;
V_187 -> V_436 = F_66 ( F_54 ( V_419 -> V_123 ) ) ;
V_35 = F_46 ( V_2 ) ;
V_50 = F_2 ( V_12 ) ;
if ( ! V_35 ) {
* V_439 = F_8 ( V_50 -> V_445 ) ;
* V_431 = F_8 ( V_50 -> V_431 ) ;
} else {
* V_425 = V_50 -> V_438 ;
}
V_428:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_130 ( struct V_1 * V_2 , struct V_117 * V_419 ,
T_2 V_446 , T_2 V_447 , T_2 V_325 )
{
struct V_11 * V_12 ;
struct F_130 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_2 -> V_41 = 0 ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_428;
}
V_187 = V_419 -> V_121 ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_38 , V_419 -> V_169 , V_12 , V_419 ) ;
V_187 -> V_297 . V_448 = F_66 ( V_446 ) ;
V_187 -> V_297 . V_449 = F_66 ( V_447 ) ;
V_187 -> V_297 . V_450 = F_66 ( V_325 ) ;
F_3 ( V_2 ) ;
F_34 ( & V_2 -> V_204 ) ;
if ( ! F_127 ( & V_2 -> V_42 ,
F_128 ( 40000 ) ) )
V_35 = - 1 ;
else
V_35 = V_2 -> V_41 ;
return V_35 ;
V_428:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_131 ( struct V_1 * V_2 , T_1 * V_451 ,
int V_323 )
{
struct V_11 * V_12 ;
struct V_452 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_453 , sizeof( * V_187 ) ,
V_12 , NULL ) ;
V_187 -> V_297 . V_448 = F_66 ( V_454 ) ;
V_187 -> V_297 . V_449 = F_66 ( V_455 ) ;
V_187 -> V_297 . V_323 = F_66 ( V_323 ) ;
V_187 -> V_297 . V_450 = F_66 ( 0x4 ) ;
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 )
memcpy ( V_451 , V_187 -> V_456 , 4 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_132 ( struct V_1 * V_2 , T_1 * V_210 ,
struct V_117 * V_294 )
{
struct V_11 * V_12 ;
struct V_457 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = V_294 -> V_121 ;
F_65 ( & V_187 -> V_190 , V_46 ,
V_458 , sizeof( * V_187 ) , V_12 ,
V_294 ) ;
memcpy ( V_187 -> V_459 , V_210 , V_211 ) ;
V_35 = F_46 ( V_2 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_133 ( struct V_1 * V_2 , T_1 V_80 ,
T_1 V_460 , T_1 V_461 )
{
struct V_11 * V_12 ;
struct V_462 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_463 ,
V_464 , sizeof( * V_187 ) , V_12 ,
NULL ) ;
V_187 -> V_465 = V_80 ;
V_187 -> V_466 = V_80 ;
V_187 -> V_460 = V_460 ;
V_187 -> V_467 = V_461 ;
V_35 = F_46 ( V_2 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_134 ( struct V_1 * V_2 , T_2 V_80 ,
T_2 V_460 , T_2 V_468 , T_2 V_469 , T_5 V_470 )
{
struct V_11 * V_12 ;
struct V_471 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_463 ,
V_472 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_190 . V_149 = F_66 ( 4 ) ;
V_187 -> V_470 = F_135 ( V_470 ) ;
V_187 -> V_465 = F_66 ( V_80 ) ;
V_187 -> V_466 = F_66 ( V_80 ) ;
V_187 -> V_468 = F_66 ( V_468 ) ;
V_187 -> V_469 = F_66 ( V_469 ) ;
V_187 -> V_460 = F_66 ( V_460 ) ;
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_473 * V_50 = F_2 ( V_12 ) ;
V_35 = F_8 ( V_50 -> V_35 ) ;
}
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_136 ( struct V_1 * V_2 , T_5 V_470 ,
T_2 V_474 , struct V_117 * V_419 )
{
struct V_11 * V_12 ;
struct V_475 * V_187 ;
int V_35 ;
int V_5 , V_476 = 0 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = V_419 -> V_121 ;
F_65 ( & V_187 -> V_190 , V_463 ,
V_477 , V_419 -> V_169 , V_12 , V_419 ) ;
V_187 -> V_470 = F_135 ( V_470 ) ;
V_187 -> V_478 = F_66 ( V_474 ) ;
for ( V_5 = 0 ; V_5 < V_474 ; V_5 ++ ) {
V_187 -> V_479 [ V_5 ] = ( T_1 ) ( V_470 >> ( V_476 * 8 ) ) ;
V_476 ++ ;
if ( V_476 > 7 )
V_476 = 0 ;
}
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_480 * V_50 ;
V_50 = V_419 -> V_121 ;
if ( ( memcmp ( V_50 -> V_481 , V_187 -> V_479 , V_474 ) != 0 ) ||
V_50 -> V_482 ) {
V_35 = - 1 ;
}
}
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_137 ( struct V_1 * V_2 ,
struct V_117 * V_294 )
{
struct V_11 * V_12 ;
struct V_483 * V_187 ;
struct V_153 * V_159 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = V_294 -> V_121 ;
V_159 = F_64 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_484 , sizeof( * V_187 ) , V_12 ,
V_294 ) ;
V_35 = F_46 ( V_2 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_138 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_485 * V_187 ;
struct V_117 V_419 ;
int V_35 ;
if ( ! F_1 ( V_2 , V_486 ,
V_40 ) )
return - V_217 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_419 . V_169 = sizeof( struct V_485 ) ;
V_419 . V_121 = F_111 ( V_2 -> V_59 , V_419 . V_169 ,
& V_419 . V_123 ) ;
if ( ! V_419 . V_121 ) {
F_17 ( & V_2 -> V_59 -> V_60 , L_16 ) ;
V_35 = - V_328 ;
goto V_142;
}
V_187 = V_419 . V_121 ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_486 , sizeof( * V_187 ) ,
V_12 , & V_419 ) ;
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_487 * V_488 =
V_419 . V_121 + sizeof( struct V_155 ) ;
V_2 -> V_65 . V_489 = F_23 ( V_488 -> V_489 ) ;
V_2 -> V_65 . V_490 =
F_23 ( V_488 -> V_490 ) ;
V_2 -> V_65 . V_491 =
F_23 ( V_488 -> V_491 ) ;
V_2 -> V_65 . V_492 =
F_23 ( V_488 -> V_492 ) ;
V_2 -> V_65 . V_493 =
F_8 ( V_488 -> V_493 ) ;
}
F_112 ( V_2 -> V_59 , V_419 . V_169 ,
V_419 . V_121 , V_419 . V_123 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_139 ( struct V_1 * V_2 , T_2 V_494 , T_2 V_212 )
{
struct V_11 * V_12 ;
struct V_495 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_496 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_190 . V_212 = V_212 ;
V_187 -> V_497 = F_66 ( V_498 ) ;
V_187 -> V_499 = F_66 ( V_494 ) ;
V_35 = F_46 ( V_2 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_140 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_500 * V_187 ;
struct V_501 * V_50 ;
int V_35 ;
int V_327 = F_141 ( sizeof( * V_187 ) , sizeof( * V_50 ) ) ;
struct V_502 * V_503 ;
struct V_117 V_504 ;
memset ( & V_504 , 0 , sizeof( struct V_117 ) ) ;
V_504 . V_169 = sizeof( struct V_501 ) ;
V_504 . V_121 = F_111 ( V_2 -> V_59 , V_504 . V_169 ,
& V_504 . V_123 ) ;
if ( ! V_504 . V_121 ) {
F_17 ( & V_2 -> V_59 -> V_60 ,
L_17 ) ;
return - V_328 ;
}
if ( F_79 ( & V_2 -> V_183 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = V_504 . V_121 ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_505 , V_327 , V_12 ,
& V_504 ) ;
V_35 = F_53 ( V_2 ) ;
if ( ! V_35 ) {
V_503 = V_504 . V_121 + sizeof( struct V_28 ) ;
V_2 -> V_299 = V_503 -> V_506 . V_507 ;
}
V_142:
F_80 ( & V_2 -> V_183 ) ;
F_112 ( V_2 -> V_59 , V_504 . V_169 , V_504 . V_121 ,
V_504 . V_123 ) ;
return V_35 ;
}
int F_142 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_508 * V_187 ;
int V_35 ;
if ( F_79 ( & V_2 -> V_183 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_509 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_510 = F_66 ( V_511 |
V_512 ) ;
V_187 -> V_284 = F_66 ( V_512 ) ;
V_35 = F_53 ( V_2 ) ;
if ( ! V_35 ) {
struct V_513 * V_50 = F_2 ( V_12 ) ;
V_2 -> V_514 = F_8 ( V_50 -> V_284 ) &
V_512 ;
if ( ! V_2 -> V_514 )
F_16 ( & V_2 -> V_59 -> V_60 ,
L_18 ) ;
}
V_142:
F_80 ( & V_2 -> V_183 ) ;
return V_35 ;
}
int F_143 ( struct V_1 * V_2 , T_2 * V_515 ,
T_2 V_212 )
{
struct V_11 * V_12 ;
struct V_516 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_517 , sizeof( * V_187 ) ,
V_12 , NULL ) ;
V_187 -> V_190 . V_212 = V_212 ;
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_518 * V_50 =
F_2 ( V_12 ) ;
* V_515 = F_8 ( V_50 -> V_519 ) ;
}
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_144 ( struct V_1 * V_2 , T_1 * V_210 ,
bool * V_520 , T_2 * V_202 , T_1 V_212 )
{
struct V_11 * V_12 ;
struct V_521 * V_187 ;
int V_35 ;
int V_522 ;
struct V_117 V_523 ;
int V_5 ;
memset ( & V_523 , 0 , sizeof( struct V_117 ) ) ;
V_523 . V_169 = sizeof( struct V_524 ) ;
V_523 . V_121 = F_111 ( V_2 -> V_59 ,
V_523 . V_169 ,
& V_523 . V_123 ) ;
if ( ! V_523 . V_121 ) {
F_17 ( & V_2 -> V_59 -> V_60 ,
L_19 ) ;
return - V_328 ;
}
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_112;
}
V_187 = V_523 . V_121 ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_525 , sizeof( * V_187 ) ,
V_12 , & V_523 ) ;
V_187 -> V_190 . V_212 = V_212 ;
V_187 -> V_526 = V_207 ;
V_187 -> V_527 = 1 ;
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_524 * V_50 =
V_523 . V_121 ;
V_522 = V_50 -> V_528 + V_50 -> V_529 ;
for ( V_5 = 0 ; V_5 < V_522 ; V_5 ++ ) {
struct V_530 * V_531 ;
T_3 V_532 ;
T_2 V_533 ;
V_531 = & V_50 -> V_534 [ V_5 ] ;
V_532 = F_23 ( V_531 -> V_532 ) ;
if ( V_532 == sizeof( T_2 ) ) {
* V_520 = true ;
V_533 = V_531 -> V_535 . V_536 . V_533 ;
* V_202 = F_8 ( V_533 ) ;
goto V_112;
}
}
* V_520 = false ;
memcpy ( V_210 , V_50 -> V_534 [ 0 ] . V_535 . V_537 ,
V_211 ) ;
}
V_112:
F_34 ( & V_2 -> V_204 ) ;
F_112 ( V_2 -> V_59 , V_523 . V_169 ,
V_523 . V_121 , V_523 . V_123 ) ;
return V_35 ;
}
int F_145 ( struct V_1 * V_2 , T_1 * V_538 ,
T_1 V_522 , T_2 V_212 )
{
struct V_11 * V_12 ;
struct V_539 * V_187 ;
int V_35 ;
struct V_117 V_419 ;
memset ( & V_419 , 0 , sizeof( struct V_117 ) ) ;
V_419 . V_169 = sizeof( struct V_539 ) ;
V_419 . V_121 = F_146 ( & V_2 -> V_59 -> V_60 , V_419 . V_169 ,
& V_419 . V_123 , V_540 ) ;
if ( ! V_419 . V_121 ) {
F_17 ( & V_2 -> V_59 -> V_60 , L_16 ) ;
return - V_328 ;
}
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = V_419 . V_121 ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_541 , sizeof( * V_187 ) ,
V_12 , & V_419 ) ;
V_187 -> V_190 . V_212 = V_212 ;
V_187 -> V_522 = V_522 ;
if ( V_522 )
memcpy ( V_187 -> V_210 , V_538 , V_211 * V_522 ) ;
V_35 = F_46 ( V_2 ) ;
V_142:
F_147 ( & V_2 -> V_59 -> V_60 , V_419 . V_169 ,
V_419 . V_121 , V_419 . V_123 ) ;
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_148 ( struct V_1 * V_2 , T_3 V_84 ,
T_2 V_212 , T_3 V_542 )
{
struct V_11 * V_12 ;
struct V_543 * V_187 ;
void * V_224 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
V_224 = & V_187 -> V_194 ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_544 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_190 . V_212 = V_212 ;
F_84 ( struct V_545 , V_266 , V_224 , V_542 ) ;
if ( V_84 ) {
F_84 ( struct V_545 , V_546 , V_224 , 1 ) ;
F_84 ( struct V_545 , V_84 , V_224 , V_84 ) ;
}
F_67 ( V_187 -> V_194 , sizeof( V_187 -> V_194 ) ) ;
V_35 = F_46 ( V_2 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_149 ( struct V_1 * V_2 , T_3 * V_84 ,
T_2 V_212 , T_3 V_542 )
{
struct V_11 * V_12 ;
struct V_547 * V_187 ;
void * V_224 ;
int V_35 ;
T_3 V_548 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
V_224 = & V_187 -> V_194 ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_549 , sizeof( * V_187 ) , V_12 , NULL ) ;
V_187 -> V_190 . V_212 = V_212 ;
F_84 ( struct V_550 , V_266 , V_224 ,
V_542 ) ;
F_84 ( struct V_550 , V_546 , V_224 , 1 ) ;
F_67 ( V_187 -> V_194 , sizeof( V_187 -> V_194 ) ) ;
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_551 * V_50 =
F_2 ( V_12 ) ;
F_13 ( & V_50 -> V_194 ,
sizeof( V_50 -> V_194 ) ) ;
V_548 = F_150 ( struct V_552 ,
V_84 , & V_50 -> V_194 ) ;
* V_84 = F_23 ( V_548 ) ;
}
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_151 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_553 * V_187 ;
int V_35 ;
int V_327 = sizeof( * V_187 ) ;
struct V_117 V_419 ;
if ( ! F_1 ( V_2 , V_458 ,
V_46 ) )
return - V_217 ;
memset ( & V_419 , 0 , sizeof( struct V_117 ) ) ;
V_419 . V_169 = sizeof( struct V_554 ) ;
V_419 . V_121 = F_111 ( V_2 -> V_59 , V_419 . V_169 ,
& V_419 . V_123 ) ;
if ( ! V_419 . V_121 ) {
F_17 ( & V_2 -> V_59 -> V_60 ,
L_17 ) ;
return - V_328 ;
}
if ( F_79 ( & V_2 -> V_183 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = V_419 . V_121 ;
F_65 ( & V_187 -> V_190 , V_46 ,
V_458 ,
V_327 , V_12 , & V_419 ) ;
V_187 -> V_190 . V_162 = 1 ;
V_187 -> V_555 = V_556 ;
V_35 = F_53 ( V_2 ) ;
if ( ! V_35 ) {
struct V_554 * V_50 ;
V_50 = (struct V_554 * ) V_419 . V_121 ;
if ( V_50 -> V_190 . V_557 < V_327 ) {
V_35 = - 1 ;
goto V_142;
}
V_2 -> V_558 = V_50 -> V_559 ;
}
V_142:
F_80 ( & V_2 -> V_183 ) ;
F_112 ( V_2 -> V_59 , V_419 . V_169 , V_419 . V_121 , V_419 . V_123 ) ;
return V_35 ;
}
int F_152 ( struct V_1 * V_2 ,
struct V_117 * V_419 )
{
struct V_11 * V_12 ;
struct V_560 * V_187 ;
int V_35 ;
if ( F_79 ( & V_2 -> V_183 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = V_419 -> V_121 ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_561 ,
V_419 -> V_169 , V_12 , V_419 ) ;
V_187 -> V_562 = F_66 ( 1 ) ;
V_35 = F_53 ( V_2 ) ;
V_142:
F_80 ( & V_2 -> V_183 ) ;
return V_35 ;
}
int F_153 ( struct V_1 * V_2 ,
struct V_117 * V_419 ,
struct V_563 * V_564 )
{
struct V_11 * V_12 ;
struct V_565 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = V_419 -> V_121 ;
memcpy ( & V_187 -> V_566 , V_564 , sizeof( struct V_563 ) ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_567 ,
V_419 -> V_169 , V_12 , V_419 ) ;
V_35 = F_46 ( V_2 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_154 ( struct V_1 * V_2 , T_1 * V_568 )
{
struct V_11 * V_12 ;
struct V_569 * V_187 ;
int V_35 ;
if ( ! F_19 ( V_2 ) ) {
* V_568 = V_2 -> V_299 + '0' ;
return 0 ;
}
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_570 , sizeof( * V_187 ) , V_12 ,
NULL ) ;
V_187 -> V_190 . V_162 = 1 ;
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_571 * V_50 = F_2 ( V_12 ) ;
* V_568 = V_50 -> V_568 [ V_2 -> V_299 ] ;
} else {
* V_568 = V_2 -> V_299 + '0' ;
}
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
static struct V_572 * F_155 ( T_1 * V_321 , T_2 V_573 ,
T_2 V_574 )
{
struct V_572 * V_575 = (struct V_572 * ) V_321 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_573 ; V_5 ++ ) {
V_575 -> V_576 = V_577 ;
if ( ( ( void * ) V_575 + V_575 -> V_576 ) >
( void * ) ( V_321 + V_574 ) ) {
V_575 = NULL ;
break;
}
if ( V_575 -> V_578 == V_579 )
break;
V_575 = ( void * ) V_575 + V_575 -> V_576 ;
}
if ( ! V_575 || V_5 == V_580 )
return NULL ;
return V_575 ;
}
int F_156 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_581 * V_187 ;
int V_35 ;
struct V_117 V_419 ;
memset ( & V_419 , 0 , sizeof( struct V_117 ) ) ;
V_419 . V_169 = sizeof( struct V_582 ) ;
V_419 . V_121 = F_111 ( V_2 -> V_59 , V_419 . V_169 ,
& V_419 . V_123 ) ;
if ( ! V_419 . V_121 ) {
F_17 ( & V_2 -> V_59 -> V_60 , L_16 ) ;
return - V_328 ;
}
if ( F_79 ( & V_2 -> V_183 ) )
return - 1 ;
V_12 = F_73 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = V_419 . V_121 ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_583 ,
V_419 . V_169 , V_12 , & V_419 ) ;
V_35 = F_53 ( V_2 ) ;
if ( ! V_35 ) {
struct V_582 * V_50 = V_419 . V_121 ;
T_2 V_573 = F_8 ( V_50 -> V_573 ) ;
struct V_572 * V_575 ;
V_575 = F_155 ( V_50 -> V_584 , V_573 ,
sizeof( V_50 -> V_584 ) ) ;
if ( ! V_575 ) {
V_35 = - V_585 ;
goto V_142;
}
V_2 -> V_586 = V_575 -> V_587 ;
V_2 -> V_588 = F_23 ( V_575 -> V_589 ) ;
V_2 -> V_590 = F_23 ( V_575 -> V_591 ) ;
V_2 -> V_592 = F_23 ( V_575 -> V_593 ) ;
V_2 -> V_594 = F_23 ( V_575 -> V_595 ) ;
V_2 -> V_596 = F_23 ( V_575 -> V_597 ) ;
V_2 -> V_598 = F_23 ( V_575 -> V_599 ) ;
V_2 -> V_600 = F_23 ( V_575 -> V_601 ) ;
V_2 -> V_370 = F_8 ( V_575 -> V_284 ) ;
}
V_142:
F_80 ( & V_2 -> V_183 ) ;
F_112 ( V_2 -> V_59 , V_419 . V_169 ,
V_419 . V_121 , V_419 . V_123 ) ;
return V_35 ;
}
int F_157 ( struct V_1 * V_2 , T_2 * V_284 ,
T_1 V_212 )
{
struct V_11 * V_12 ;
struct V_602 * V_187 ;
int V_35 ;
struct V_117 V_419 ;
memset ( & V_419 , 0 , sizeof( struct V_117 ) ) ;
V_419 . V_169 = sizeof( struct V_603 ) ;
V_419 . V_121 = F_111 ( V_2 -> V_59 , V_419 . V_169 ,
& V_419 . V_123 ) ;
if ( ! V_419 . V_121 ) {
F_17 ( & V_2 -> V_59 -> V_60 , L_16 ) ;
return - V_328 ;
}
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = V_419 . V_121 ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_604 ,
V_419 . V_169 , V_12 , & V_419 ) ;
V_187 -> type = V_605 ;
V_187 -> V_190 . V_212 = V_212 ;
V_35 = F_46 ( V_2 ) ;
if ( ! V_35 ) {
struct V_603 * V_50 = V_419 . V_121 ;
T_2 V_573 = F_8 ( V_50 -> V_573 ) ;
struct V_572 * V_575 ;
V_575 = F_155 ( V_50 -> V_584 , V_573 ,
sizeof( V_50 -> V_584 ) ) ;
if ( ! V_575 ) {
V_35 = - V_585 ;
goto V_142;
}
* V_284 = F_8 ( V_575 -> V_284 ) ;
}
V_142:
F_34 ( & V_2 -> V_204 ) ;
F_112 ( V_2 -> V_59 , V_419 . V_169 ,
V_419 . V_121 , V_419 . V_123 ) ;
return V_35 ;
}
int F_158 ( struct V_1 * V_2 , T_2 V_494 ,
T_1 V_212 )
{
struct V_11 * V_12 ;
struct V_606 * V_187 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_607 , sizeof( * V_187 ) ,
V_12 , NULL ) ;
V_187 -> V_190 . V_212 = V_212 ;
V_187 -> V_573 = F_66 ( 1 ) ;
V_187 -> V_608 . V_578 = V_579 ;
V_187 -> V_608 . V_576 = V_577 ;
V_187 -> V_608 . V_26 = ( 1 << V_609 ) | ( 1 << V_610 ) | ( 1 << V_611 ) ;
V_187 -> V_608 . V_587 = V_2 -> V_586 ;
V_187 -> V_608 . V_612 = V_212 ;
V_187 -> V_608 . V_589 = 0xFFFF ;
V_187 -> V_608 . V_613 = 0xFFFF ;
V_187 -> V_608 . V_591 = 0xFFFF ;
V_187 -> V_608 . V_593 = 0xFFFF ;
V_187 -> V_608 . V_595 = 0xFFFF ;
V_187 -> V_608 . V_599 = 0xFFFF ;
V_187 -> V_608 . V_597 = 0xFFFF ;
V_187 -> V_608 . V_614 = 0xFFFF ;
V_187 -> V_608 . V_615 = 0xFFFF ;
V_187 -> V_608 . V_616 = 0xFFFF ;
V_187 -> V_608 . V_601 = 0xFFFF ;
V_187 -> V_608 . V_617 = 0xFF ;
V_187 -> V_608 . V_618 = 0xFFFFFFFF ;
V_187 -> V_608 . V_619 = 0xFF ;
V_187 -> V_608 . V_620 = 0x0F ;
V_187 -> V_608 . V_618 = F_66 ( V_494 ) ;
V_187 -> V_608 . V_621 = F_66 ( V_494 ) ;
V_35 = F_46 ( V_2 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_159 ( struct V_1 * V_2 , T_1 V_212 )
{
struct V_11 * V_12 ;
struct V_622 * V_187 ;
int V_35 ;
if ( ! F_19 ( V_2 ) )
return 0 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
F_65 ( & V_187 -> V_190 , V_40 ,
V_623 , sizeof( * V_187 ) ,
V_12 , NULL ) ;
V_187 -> V_190 . V_212 = V_212 ;
V_187 -> V_461 = 1 ;
V_35 = F_46 ( V_2 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
int F_160 ( void * V_624 , void * V_625 ,
int V_626 , T_3 * V_627 , T_3 * V_628 )
{
struct V_1 * V_2 = F_161 ( V_624 ) ;
struct V_11 * V_12 ;
struct V_155 * V_190 = (struct V_155 * ) V_625 ;
struct V_155 * V_187 ;
struct V_28 * V_50 ;
int V_35 ;
F_32 ( & V_2 -> V_204 ) ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_205 ;
goto V_142;
}
V_187 = F_2 ( V_12 ) ;
V_50 = F_2 ( V_12 ) ;
F_65 ( V_187 , V_190 -> V_4 ,
V_190 -> V_3 , V_626 , V_12 , NULL ) ;
memcpy ( V_187 , V_625 , V_626 ) ;
F_67 ( V_187 , V_626 ) ;
V_35 = F_46 ( V_2 ) ;
if ( V_627 )
* V_627 = ( V_35 & 0xffff ) ;
if ( V_628 )
* V_628 = 0 ;
memcpy ( V_625 , V_50 , sizeof( * V_50 ) + V_50 -> V_557 ) ;
F_13 ( V_625 , sizeof( * V_50 ) + V_50 -> V_557 ) ;
V_142:
F_34 ( & V_2 -> V_204 ) ;
return V_35 ;
}
