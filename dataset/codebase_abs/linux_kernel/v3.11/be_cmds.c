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
static void F_25 ( struct V_1 * V_2 ,
T_2 V_87 , struct V_24 * V_94 )
{
T_1 V_88 = 0 ;
struct V_95 * V_64 = (struct V_95 * ) V_94 ;
V_88 = ( V_87 >> V_89 ) &
V_90 ;
switch ( V_88 ) {
case V_96 :
if ( V_64 -> V_71 )
V_2 -> V_97 = F_22 ( V_64 -> V_98 ) ;
V_2 -> V_26 |= V_99 ;
break;
default:
F_15 ( & V_2 -> V_59 -> V_60 , L_4 ) ;
break;
}
}
static inline bool F_26 ( T_2 V_87 )
{
return ( ( V_87 >> V_100 ) &
V_101 ) ==
V_102 ;
}
static inline bool F_27 ( T_2 V_87 )
{
return ( ( ( V_87 >> V_100 ) &
V_101 ) ==
V_103 ) ;
}
static inline bool F_28 ( T_2 V_87 )
{
return ( ( ( V_87 >> V_100 ) &
V_101 ) ==
V_104 ) ;
}
static struct V_24 * F_29 ( struct V_1 * V_2 )
{
struct V_14 * V_105 = & V_2 -> V_16 . V_106 ;
struct V_24 * V_25 = F_30 ( V_105 ) ;
if ( F_7 ( V_25 ) ) {
F_31 ( V_105 ) ;
return V_25 ;
}
return NULL ;
}
void F_32 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_107 ) ;
F_34 ( V_2 , V_2 -> V_16 . V_106 . V_19 , true , 0 ) ;
V_2 -> V_16 . V_108 = true ;
F_35 ( & V_2 -> V_107 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_107 ) ;
V_2 -> V_16 . V_108 = false ;
F_34 ( V_2 , V_2 -> V_16 . V_106 . V_19 , false , 0 ) ;
F_35 ( & V_2 -> V_107 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
int V_109 = 0 , V_35 = 0 ;
struct V_110 * V_16 = & V_2 -> V_16 ;
F_38 ( & V_2 -> V_107 ) ;
while ( ( V_25 = F_29 ( V_2 ) ) ) {
if ( V_25 -> V_26 & V_111 ) {
if ( F_26 ( V_25 -> V_26 ) )
F_17 ( V_2 ,
(struct V_63 * ) V_25 ) ;
else if ( F_27 ( V_25 -> V_26 ) )
F_24 ( V_2 ,
V_25 -> V_26 , V_25 ) ;
else if ( F_28 ( V_25 -> V_26 ) )
F_25 ( V_2 ,
V_25 -> V_26 , V_25 ) ;
} else if ( V_25 -> V_26 & V_112 ) {
V_35 = F_11 ( V_2 , V_25 ) ;
F_39 ( & V_16 -> V_17 . V_113 ) ;
}
F_9 ( V_25 ) ;
V_109 ++ ;
}
if ( V_109 )
F_34 ( V_2 , V_16 -> V_106 . V_19 , V_16 -> V_108 , V_109 ) ;
F_40 ( & V_2 -> V_107 ) ;
return V_35 ;
}
static int F_41 ( struct V_1 * V_2 )
{
#define F_42 120000
int V_5 , V_35 = 0 ;
struct V_110 * V_16 = & V_2 -> V_16 ;
for ( V_5 = 0 ; V_5 < F_42 ; V_5 ++ ) {
if ( F_4 ( V_2 ) )
return - V_114 ;
F_43 () ;
V_35 = F_37 ( V_2 ) ;
F_44 () ;
if ( F_45 ( & V_16 -> V_17 . V_113 ) == 0 )
break;
F_46 ( 100 ) ;
}
if ( V_5 == F_42 ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_5 ) ;
V_2 -> V_115 = true ;
return - V_114 ;
}
return V_35 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_35 ;
struct V_11 * V_12 ;
struct V_110 * V_16 = & V_2 -> V_16 ;
T_3 V_116 = V_16 -> V_17 . V_117 ;
struct V_28 * V_50 ;
F_48 ( & V_116 , V_16 -> V_17 . V_118 ) ;
V_12 = F_49 ( & V_16 -> V_17 , V_116 ) ;
V_50 = F_10 ( V_12 -> V_29 , V_12 -> V_30 ) ;
F_3 ( V_2 ) ;
V_35 = F_41 ( V_2 ) ;
if ( V_35 == - V_114 )
goto V_119;
V_35 = V_50 -> V_35 ;
V_119:
return V_35 ;
}
static int F_50 ( struct V_1 * V_2 , void T_4 * V_22 )
{
int V_120 = 0 ;
T_2 V_121 ;
do {
if ( F_4 ( V_2 ) )
return - V_114 ;
V_121 = F_51 ( V_22 ) ;
if ( V_121 == 0xffffffff )
return - 1 ;
V_121 &= V_122 ;
if ( V_121 )
break;
if ( V_120 > 4000 ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_5 ) ;
V_2 -> V_115 = true ;
F_52 ( V_2 ) ;
return - 1 ;
}
F_53 ( 1 ) ;
V_120 ++ ;
} while ( true );
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_35 ;
T_2 V_18 = 0 ;
void T_4 * V_22 = V_2 -> V_22 + V_123 ;
struct V_124 * V_125 = & V_2 -> V_125 ;
struct V_126 * V_127 = V_125 -> V_128 ;
struct V_24 * V_25 = & V_127 -> V_25 ;
V_35 = F_50 ( V_2 , V_22 ) ;
if ( V_35 != 0 )
return V_35 ;
V_18 |= V_129 ;
V_18 |= ( F_55 ( V_125 -> V_130 ) >> 2 ) << 2 ;
F_6 ( V_18 , V_22 ) ;
V_35 = F_50 ( V_2 , V_22 ) ;
if ( V_35 != 0 )
return V_35 ;
V_18 = 0 ;
V_18 |= ( T_2 ) ( V_125 -> V_130 >> 4 ) << 2 ;
F_6 ( V_18 , V_22 ) ;
V_35 = F_50 ( V_2 , V_22 ) ;
if ( V_35 != 0 )
return V_35 ;
if ( F_7 ( V_25 ) ) {
V_35 = F_11 ( V_2 , & V_127 -> V_25 ) ;
F_9 ( V_25 ) ;
if ( V_35 )
return V_35 ;
} else {
F_16 ( & V_2 -> V_59 -> V_60 , L_6 ) ;
return - 1 ;
}
return 0 ;
}
static T_3 F_56 ( struct V_1 * V_2 )
{
T_2 V_131 ;
if ( F_57 ( V_2 ) )
V_131 = F_51 ( V_2 -> V_132 + V_133 ) ;
else
F_58 ( V_2 -> V_59 ,
V_134 , & V_131 ) ;
return V_131 & V_135 ;
}
int F_59 ( struct V_1 * V_2 )
{
#define F_60 30
T_2 V_136 ;
int V_35 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < F_60 ; V_5 ++ ) {
V_136 = F_51 ( V_2 -> V_22 + V_137 ) ;
if ( V_136 & V_138 )
break;
F_53 ( 1000 ) ;
}
if ( V_5 == F_60 )
V_35 = - 1 ;
return V_35 ;
}
static bool F_61 ( struct V_1 * V_2 )
{
T_2 V_136 = 0 , V_139 = 0 , V_140 = 0 ;
V_136 = F_51 ( V_2 -> V_22 + V_137 ) ;
if ( V_136 & V_141 ) {
V_139 = F_51 ( V_2 -> V_22 +
V_142 ) ;
V_140 = F_51 ( V_2 -> V_22 +
V_143 ) ;
if ( V_139 == V_144 &&
V_140 == V_145 )
return true ;
}
return false ;
}
int F_62 ( struct V_1 * V_2 )
{
int V_35 ;
T_2 V_136 , V_146 , V_147 ;
bool V_148 ;
V_148 = F_61 ( V_2 ) ;
if ( V_148 )
return - V_149 ;
V_35 = F_59 ( V_2 ) ;
if ( ! V_35 ) {
V_136 = F_51 ( V_2 -> V_22 + V_137 ) ;
V_146 = V_136 & V_141 ;
V_147 = V_136 & V_150 ;
if ( V_146 && V_147 ) {
F_6 ( V_151 ,
V_2 -> V_22 + V_152 ) ;
V_35 = F_59 ( V_2 ) ;
V_136 = F_51 ( V_2 -> V_22 +
V_137 ) ;
V_136 &= ( V_141 |
V_150 ) ;
if ( V_35 || V_136 )
V_35 = - 1 ;
} else if ( V_146 || V_147 ) {
V_35 = - 1 ;
}
}
V_148 = F_61 ( V_2 ) ;
if ( V_148 )
V_35 = - V_149 ;
return V_35 ;
}
int F_63 ( struct V_1 * V_2 )
{
T_3 V_153 ;
int V_35 , V_154 = 0 ;
struct V_155 * V_60 = & V_2 -> V_59 -> V_60 ;
if ( F_18 ( V_2 ) ) {
V_35 = F_59 ( V_2 ) ;
return V_35 ;
}
do {
V_153 = F_56 ( V_2 ) ;
if ( V_153 == V_156 )
return 0 ;
F_64 ( V_60 , L_7 ,
V_154 ) ;
if ( F_65 ( 2000 ) ) {
F_16 ( V_60 , L_8 ) ;
return - V_157 ;
}
V_154 += 2 ;
} while ( V_154 < 60 );
F_16 ( V_60 , L_9 , V_153 ) ;
return - 1 ;
}
static inline struct V_158 * F_66 ( struct V_11 * V_12 )
{
return & V_12 -> V_13 . V_159 [ 0 ] ;
}
static void F_67 ( struct V_160 * V_161 ,
T_1 V_4 , T_1 V_3 , int V_162 ,
struct V_11 * V_12 , struct V_124 * V_163 )
{
struct V_158 * V_164 ;
unsigned long V_31 = ( unsigned long ) V_161 ;
T_5 V_165 = V_31 ;
V_161 -> V_3 = V_3 ;
V_161 -> V_4 = V_4 ;
V_161 -> V_166 = F_68 ( V_162 - sizeof( * V_161 ) ) ;
V_161 -> V_167 = 0 ;
V_12 -> V_29 = V_165 & 0xFFFFFFFF ;
V_12 -> V_30 = F_55 ( V_165 ) ;
V_12 -> V_168 = V_162 ;
if ( V_163 ) {
V_12 -> V_169 |= ( 1 & V_170 ) <<
V_171 ;
V_164 = F_66 ( V_12 ) ;
V_164 -> V_172 = F_68 ( F_55 ( V_163 -> V_130 ) ) ;
V_164 -> V_173 = F_68 ( V_163 -> V_130 & 0xFFFFFFFF ) ;
V_164 -> V_118 = F_68 ( V_163 -> V_174 ) ;
} else
V_12 -> V_169 |= V_175 ;
F_69 ( V_12 , 8 ) ;
}
static void F_70 ( struct V_176 * V_177 , T_2 V_178 ,
struct V_124 * V_163 )
{
int V_5 , V_179 = F_71 ( F_72 ( V_163 -> V_128 , V_163 -> V_174 ) , V_178 ) ;
T_5 V_130 = ( T_5 ) V_163 -> V_130 ;
for ( V_5 = 0 ; V_5 < V_179 ; V_5 ++ ) {
V_177 [ V_5 ] . V_180 = F_68 ( V_130 & 0xFFFFFFFF ) ;
V_177 [ V_5 ] . V_181 = F_68 ( F_55 ( V_130 ) ) ;
V_130 += V_182 ;
}
}
static T_2 F_73 ( T_2 V_183 )
{
#define F_74 651042
const T_2 V_184 = 10 ;
T_2 V_185 ;
if ( V_183 == 0 )
V_185 = 0 ;
else {
T_2 V_186 = 1000000 / V_183 ;
if ( V_186 == 0 )
V_185 = 1023 ;
else {
V_185 = ( F_74 - V_186 ) * V_184 ;
V_185 /= V_186 ;
V_185 = ( V_185 + V_184 / 2 ) / V_184 ;
V_185 = F_71 ( V_185 , ( T_2 ) 1023 ) ;
}
}
return V_185 ;
}
static inline struct V_11 * F_75 ( struct V_1 * V_2 )
{
struct V_124 * V_125 = & V_2 -> V_125 ;
struct V_11 * V_12
= & ( (struct V_126 * ) ( V_125 -> V_128 ) ) -> V_12 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
static struct V_11 * F_76 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 . V_17 ;
struct V_11 * V_12 ;
if ( ! V_15 -> V_187 )
return NULL ;
if ( F_45 ( & V_15 -> V_113 ) >= V_15 -> V_118 )
return NULL ;
V_12 = F_77 ( V_15 ) ;
F_78 ( V_15 ) ;
F_79 ( & V_15 -> V_113 ) ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
int F_80 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_35 ;
if ( F_18 ( V_2 ) )
return 0 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = ( T_1 * ) F_75 ( V_2 ) ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0x12 ;
* V_12 ++ = 0x34 ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0x56 ;
* V_12 ++ = 0x78 ;
* V_12 = 0xFF ;
V_35 = F_54 ( V_2 ) ;
F_82 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_83 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_35 ;
if ( F_18 ( V_2 ) )
return 0 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = ( T_1 * ) F_75 ( V_2 ) ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xAA ;
* V_12 ++ = 0xBB ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xCC ;
* V_12 ++ = 0xDD ;
* V_12 = 0xFF ;
V_35 = F_54 ( V_2 ) ;
F_82 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_84 ( struct V_1 * V_2 ,
struct V_14 * V_189 , int V_190 )
{
struct V_11 * V_12 ;
struct V_191 * V_192 ;
struct V_124 * V_193 = & V_189 -> V_194 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_75 ( V_2 ) ;
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_196 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_197 = F_85 ( F_72 ( V_193 -> V_128 , V_193 -> V_174 ) ) ;
F_86 ( struct V_198 , V_71 , V_192 -> V_199 , 1 ) ;
F_86 ( struct V_198 , V_174 , V_192 -> V_199 , 0 ) ;
F_86 ( struct V_198 , V_200 , V_192 -> V_199 ,
F_87 ( V_189 -> V_118 / 256 ) ) ;
F_86 ( struct V_198 , V_201 , V_192 -> V_199 ,
F_73 ( V_190 ) ) ;
F_69 ( V_192 -> V_199 , sizeof( V_192 -> V_199 ) ) ;
F_70 ( V_192 -> V_177 , F_88 ( V_192 -> V_177 ) , V_193 ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_202 * V_50 = F_2 ( V_12 ) ;
V_189 -> V_19 = F_22 ( V_50 -> V_203 ) ;
V_189 -> V_187 = true ;
}
F_82 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_89 ( struct V_1 * V_2 , T_1 * V_204 ,
bool V_205 , T_2 V_206 , T_2 V_207 )
{
struct V_11 * V_12 ;
struct V_208 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_211 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> type = V_212 ;
if ( V_205 ) {
V_192 -> V_205 = 1 ;
} else {
V_192 -> V_213 = F_85 ( ( T_3 ) V_206 ) ;
V_192 -> V_207 = F_68 ( V_207 ) ;
V_192 -> V_205 = 0 ;
}
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_214 * V_50 = F_2 ( V_12 ) ;
memcpy ( V_204 , V_50 -> V_215 . V_31 , V_216 ) ;
}
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_90 ( struct V_1 * V_2 , T_1 * V_204 ,
T_2 V_213 , T_2 * V_207 , T_2 V_217 )
{
struct V_11 * V_12 ;
struct V_218 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_219 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_195 . V_217 = V_217 ;
V_192 -> V_213 = F_68 ( V_213 ) ;
memcpy ( V_192 -> V_220 , V_204 , V_216 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_221 * V_50 = F_2 ( V_12 ) ;
* V_207 = F_8 ( V_50 -> V_207 ) ;
}
V_146:
F_35 ( & V_2 -> V_209 ) ;
if ( V_35 == V_58 )
V_35 = - V_222 ;
return V_35 ;
}
int F_91 ( struct V_1 * V_2 , T_2 V_213 , int V_207 , T_2 V_223 )
{
struct V_11 * V_12 ;
struct V_224 * V_192 ;
int V_35 ;
if ( V_207 == - 1 )
return 0 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_225 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_195 . V_217 = V_223 ;
V_192 -> V_213 = F_68 ( V_213 ) ;
V_192 -> V_207 = F_68 ( V_207 ) ;
V_35 = F_47 ( V_2 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_92 ( struct V_1 * V_2 , struct V_14 * V_106 ,
struct V_14 * V_189 , bool V_226 , int V_227 )
{
struct V_11 * V_12 ;
struct V_228 * V_192 ;
struct V_124 * V_193 = & V_106 -> V_194 ;
void * V_229 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_75 ( V_2 ) ;
V_192 = F_2 ( V_12 ) ;
V_229 = & V_192 -> V_199 ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_230 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_197 = F_85 ( F_72 ( V_193 -> V_128 , V_193 -> V_174 ) ) ;
if ( F_57 ( V_2 ) ) {
F_86 ( struct V_231 , V_232 , V_229 ,
V_227 ) ;
F_86 ( struct V_231 , V_233 ,
V_229 , V_226 ) ;
F_86 ( struct V_231 , V_200 , V_229 ,
F_87 ( V_106 -> V_118 / 256 ) ) ;
F_86 ( struct V_231 , V_71 , V_229 , 1 ) ;
F_86 ( struct V_231 , V_234 , V_229 , 1 ) ;
F_86 ( struct V_231 , V_235 , V_229 , V_189 -> V_19 ) ;
} else {
V_192 -> V_195 . V_167 = 2 ;
V_192 -> V_236 = 1 ;
F_86 ( struct V_237 , V_233 , V_229 ,
V_226 ) ;
F_86 ( struct V_237 , V_200 , V_229 ,
F_87 ( V_106 -> V_118 / 256 ) ) ;
F_86 ( struct V_237 , V_71 , V_229 , 1 ) ;
F_86 ( struct V_237 , V_234 ,
V_229 , 1 ) ;
F_86 ( struct V_237 , V_235 ,
V_229 , V_189 -> V_19 ) ;
}
F_69 ( V_229 , sizeof( V_192 -> V_199 ) ) ;
F_70 ( V_192 -> V_177 , F_88 ( V_192 -> V_177 ) , V_193 ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_238 * V_50 = F_2 ( V_12 ) ;
V_106 -> V_19 = F_22 ( V_50 -> V_239 ) ;
V_106 -> V_187 = true ;
}
F_82 ( & V_2 -> V_188 ) ;
return V_35 ;
}
static T_2 F_93 ( int V_240 )
{
T_2 V_241 = F_94 ( V_240 ) ;
if ( V_241 == 16 )
V_241 = 0 ;
return V_241 ;
}
int F_95 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_106 )
{
struct V_11 * V_12 ;
struct V_242 * V_192 ;
struct V_124 * V_193 = & V_15 -> V_194 ;
void * V_229 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_75 ( V_2 ) ;
V_192 = F_2 ( V_12 ) ;
V_229 = & V_192 -> V_199 ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_243 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_197 = F_85 ( F_72 ( V_193 -> V_128 , V_193 -> V_174 ) ) ;
if ( F_18 ( V_2 ) ) {
V_192 -> V_195 . V_167 = 1 ;
V_192 -> V_239 = F_85 ( V_106 -> V_19 ) ;
F_86 ( struct V_244 , V_245 , V_229 ,
F_93 ( V_15 -> V_118 ) ) ;
F_86 ( struct V_244 , V_71 , V_229 , 1 ) ;
F_86 ( struct V_244 , V_246 ,
V_229 , V_106 -> V_19 ) ;
F_86 ( struct V_244 , V_247 ,
V_229 , 1 ) ;
} else {
F_86 ( struct V_248 , V_71 , V_229 , 1 ) ;
F_86 ( struct V_248 , V_245 , V_229 ,
F_93 ( V_15 -> V_118 ) ) ;
F_86 ( struct V_248 , V_239 , V_229 , V_106 -> V_19 ) ;
}
V_192 -> V_249 [ 0 ] = F_68 ( 0x00000022 ) ;
V_192 -> V_249 [ 0 ] |= F_68 ( 1 << V_104 ) ;
F_69 ( V_229 , sizeof( V_192 -> V_199 ) ) ;
F_70 ( V_192 -> V_177 , F_88 ( V_192 -> V_177 ) , V_193 ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_250 * V_50 = F_2 ( V_12 ) ;
V_15 -> V_19 = F_22 ( V_50 -> V_19 ) ;
V_15 -> V_187 = true ;
}
F_82 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_96 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_106 )
{
struct V_11 * V_12 ;
struct V_251 * V_192 ;
struct V_124 * V_193 = & V_15 -> V_194 ;
void * V_229 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_75 ( V_2 ) ;
V_192 = F_2 ( V_12 ) ;
V_229 = & V_192 -> V_199 ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_252 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_197 = F_85 ( F_72 ( V_193 -> V_128 , V_193 -> V_174 ) ) ;
F_86 ( struct V_248 , V_71 , V_229 , 1 ) ;
F_86 ( struct V_248 , V_245 , V_229 ,
F_93 ( V_15 -> V_118 ) ) ;
F_86 ( struct V_248 , V_239 , V_229 , V_106 -> V_19 ) ;
F_69 ( V_229 , sizeof( V_192 -> V_199 ) ) ;
F_70 ( V_192 -> V_177 , F_88 ( V_192 -> V_177 ) , V_193 ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_250 * V_50 = F_2 ( V_12 ) ;
V_15 -> V_19 = F_22 ( V_50 -> V_19 ) ;
V_15 -> V_187 = true ;
}
F_82 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_97 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_106 )
{
int V_35 ;
V_35 = F_95 ( V_2 , V_15 , V_106 ) ;
if ( V_35 && ! F_18 ( V_2 ) ) {
F_15 ( & V_2 -> V_59 -> V_60 , L_10
L_11
L_12 ) ;
V_35 = F_96 ( V_2 , V_15 , V_106 ) ;
}
return V_35 ;
}
int F_98 ( struct V_1 * V_2 , struct V_253 * V_254 )
{
struct V_11 * V_12 ;
struct V_255 * V_192 ;
struct V_14 * V_256 = & V_254 -> V_17 ;
struct V_14 * V_106 = & V_254 -> V_106 ;
struct V_124 * V_193 = & V_256 -> V_194 ;
int V_35 , V_257 = 0 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_46 ,
V_258 , sizeof( * V_192 ) , V_12 , NULL ) ;
if ( F_18 ( V_2 ) ) {
V_192 -> V_195 . V_167 = 1 ;
V_192 -> V_213 = F_85 ( V_2 -> V_206 ) ;
} else if ( F_57 ( V_2 ) ) {
if ( V_2 -> V_259 & V_260 )
V_192 -> V_195 . V_167 = 2 ;
} else {
V_192 -> V_195 . V_167 = 2 ;
}
V_192 -> V_197 = F_72 ( V_193 -> V_128 , V_193 -> V_174 ) ;
V_192 -> V_261 = V_262 ;
V_192 -> type = V_263 ;
V_192 -> V_239 = F_85 ( V_106 -> V_19 ) ;
V_192 -> V_264 = F_93 ( V_256 -> V_118 ) ;
F_70 ( V_192 -> V_177 , F_88 ( V_192 -> V_177 ) , V_193 ) ;
V_257 = V_192 -> V_195 . V_167 ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_265 * V_50 = F_2 ( V_12 ) ;
V_256 -> V_19 = F_22 ( V_50 -> V_266 ) ;
if ( V_257 == 2 )
V_254 -> V_267 = F_8 ( V_50 -> V_267 ) ;
else
V_254 -> V_267 = V_268 ;
V_256 -> V_187 = true ;
}
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_99 ( struct V_1 * V_2 ,
struct V_14 * V_269 , T_3 V_239 , T_3 V_270 ,
T_2 V_213 , T_2 V_271 , T_1 * V_272 )
{
struct V_11 * V_12 ;
struct V_273 * V_192 ;
struct V_124 * V_193 = & V_269 -> V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_46 ,
V_274 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_239 = F_85 ( V_239 ) ;
V_192 -> V_270 = F_94 ( V_270 ) - 1 ;
V_192 -> V_197 = 2 ;
F_70 ( V_192 -> V_177 , F_88 ( V_192 -> V_177 ) , V_193 ) ;
V_192 -> V_275 = F_68 ( V_213 ) ;
V_192 -> V_276 = F_85 ( V_277 ) ;
V_192 -> V_278 = F_68 ( V_271 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_279 * V_50 = F_2 ( V_12 ) ;
V_269 -> V_19 = F_22 ( V_50 -> V_19 ) ;
V_269 -> V_187 = true ;
* V_272 = V_50 -> V_272 ;
}
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_100 ( struct V_1 * V_2 , struct V_14 * V_17 ,
int V_280 )
{
struct V_11 * V_12 ;
struct V_281 * V_192 ;
T_1 V_282 = 0 , V_3 = 0 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_75 ( V_2 ) ;
V_192 = F_2 ( V_12 ) ;
switch ( V_280 ) {
case V_283 :
V_282 = V_40 ;
V_3 = V_284 ;
break;
case V_285 :
V_282 = V_40 ;
V_3 = V_286 ;
break;
case V_287 :
V_282 = V_46 ;
V_3 = V_288 ;
break;
case V_289 :
V_282 = V_46 ;
V_3 = V_290 ;
break;
case V_291 :
V_282 = V_40 ;
V_3 = V_292 ;
break;
default:
F_101 () ;
}
F_67 ( & V_192 -> V_195 , V_282 , V_3 , sizeof( * V_192 ) , V_12 ,
NULL ) ;
V_192 -> V_19 = F_85 ( V_17 -> V_19 ) ;
V_35 = F_54 ( V_2 ) ;
V_17 -> V_187 = false ;
F_82 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_102 ( struct V_1 * V_2 , struct V_14 * V_17 )
{
struct V_11 * V_12 ;
struct V_281 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_46 ,
V_290 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_19 = F_85 ( V_17 -> V_19 ) ;
V_35 = F_47 ( V_2 ) ;
V_17 -> V_187 = false ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_103 ( struct V_1 * V_2 , T_2 V_293 , T_2 V_294 ,
T_2 * V_206 , T_2 V_217 )
{
struct V_11 * V_12 ;
struct V_295 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_296 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_195 . V_217 = V_217 ;
V_192 -> V_297 = F_68 ( V_293 ) ;
V_192 -> V_298 = F_68 ( V_294 ) ;
V_192 -> V_299 = true ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_300 * V_50 = F_2 ( V_12 ) ;
* V_206 = F_8 ( V_50 -> V_275 ) ;
}
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_104 ( struct V_1 * V_2 , int V_275 , T_2 V_217 )
{
struct V_11 * V_12 ;
struct V_301 * V_192 ;
int V_35 ;
if ( V_275 == - 1 )
return 0 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_302 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_195 . V_217 = V_217 ;
V_192 -> V_275 = F_68 ( V_275 ) ;
V_35 = F_47 ( V_2 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_105 ( struct V_1 * V_2 , struct V_124 * V_303 )
{
struct V_11 * V_12 ;
struct V_160 * V_195 ;
int V_35 = 0 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_195 = V_303 -> V_128 ;
F_67 ( V_195 , V_46 ,
V_44 , V_303 -> V_174 , V_12 , V_303 ) ;
if ( ! F_106 ( V_2 ) )
V_195 -> V_167 = 1 ;
F_3 ( V_2 ) ;
V_2 -> V_47 = true ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_107 ( struct V_1 * V_2 ,
struct V_124 * V_303 )
{
struct V_11 * V_12 ;
struct V_304 * V_192 ;
int V_35 = 0 ;
if ( ! F_1 ( V_2 , V_45 ,
V_46 ) )
return - V_222 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = V_303 -> V_128 ;
F_67 ( & V_192 -> V_195 , V_46 ,
V_45 , V_303 -> V_174 , V_12 ,
V_303 ) ;
V_192 -> V_305 . V_306 . V_307 = F_85 ( V_2 -> V_308 ) ;
V_192 -> V_305 . V_306 . V_309 = 0 ;
F_3 ( V_2 ) ;
V_2 -> V_47 = true ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
static int F_108 ( int V_310 )
{
switch ( V_310 ) {
case V_311 :
return 0 ;
case V_312 :
return 10 ;
case V_313 :
return 100 ;
case V_314 :
return 1000 ;
case V_315 :
return 10000 ;
}
return 0 ;
}
int F_109 ( struct V_1 * V_2 , T_3 * V_66 ,
T_1 * V_316 , T_2 V_223 )
{
struct V_11 * V_12 ;
struct V_317 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
if ( V_316 )
* V_316 = V_318 ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_319 , sizeof( * V_192 ) , V_12 , NULL ) ;
if ( ! F_106 ( V_2 ) )
V_192 -> V_195 . V_167 = 1 ;
V_192 -> V_195 . V_217 = V_223 ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_320 * V_50 = F_2 ( V_12 ) ;
if ( V_66 ) {
* V_66 = V_50 -> V_66 ?
F_22 ( V_50 -> V_66 ) * 10 :
F_108 ( V_50 -> V_310 ) ;
if ( ! V_50 -> V_321 )
* V_66 = 0 ;
}
if ( V_316 )
* V_316 = V_50 -> V_321 ;
}
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_110 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_322 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_48 , sizeof( * V_192 ) ,
V_12 , NULL ) ;
F_3 ( V_2 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_111 ( struct V_1 * V_2 , T_2 * V_323 )
{
struct V_11 * V_12 ;
struct V_324 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_325 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_326 = F_68 ( V_327 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_328 * V_50 = F_2 ( V_12 ) ;
if ( V_323 && V_50 -> V_323 )
* V_323 = F_8 ( V_50 -> V_323 ) -
sizeof( T_2 ) ;
}
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
void F_112 ( struct V_1 * V_2 , T_2 V_329 , void * V_330 )
{
struct V_124 V_331 ;
struct V_11 * V_12 ;
struct V_324 * V_192 ;
T_2 V_332 = 0 , V_333 , V_334 ,
V_335 = sizeof( T_2 ) , V_336 ;
int V_35 ;
if ( V_329 == 0 )
return;
V_333 = V_329 ;
V_331 . V_174 = sizeof( struct V_324 ) + 60 * 1024 ;
V_331 . V_128 = F_113 ( V_2 -> V_59 ,
V_331 . V_174 ,
& V_331 . V_130 ) ;
if ( ! V_331 . V_128 ) {
V_35 = - V_337 ;
F_16 ( & V_2 -> V_59 -> V_60 ,
L_13 ) ;
return;
}
F_33 ( & V_2 -> V_209 ) ;
while ( V_333 ) {
V_334 = F_71 ( V_333 , ( T_2 ) 60 * 1024 ) ;
V_333 -= V_334 ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = V_331 . V_128 ;
V_336 = sizeof( struct V_324 ) + V_334 ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_325 , V_336 , V_12 ,
& V_331 ) ;
V_192 -> V_326 = F_68 ( V_338 ) ;
V_192 -> V_339 = F_68 ( V_335 ) ;
V_192 -> V_340 = F_68 ( V_334 ) ;
V_192 -> V_341 = F_68 ( V_334 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_328 * V_50 = V_331 . V_128 ;
memcpy ( V_330 + V_332 ,
V_50 -> V_342 ,
F_8 ( V_50 -> V_340 ) ) ;
} else {
F_16 ( & V_2 -> V_59 -> V_60 , L_14 ) ;
goto V_146;
}
V_332 += V_334 ;
V_335 += V_334 ;
}
V_146:
F_114 ( V_2 -> V_59 , V_331 . V_174 ,
V_331 . V_128 ,
V_331 . V_130 ) ;
F_35 ( & V_2 -> V_209 ) ;
}
int F_115 ( struct V_1 * V_2 , char * V_343 ,
char * V_344 )
{
struct V_11 * V_12 ;
struct V_345 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_346 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_347 * V_50 = F_2 ( V_12 ) ;
strcpy ( V_343 , V_50 -> V_348 ) ;
if ( V_344 )
strcpy ( V_344 , V_50 -> V_349 ) ;
}
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_116 ( struct V_1 * V_2 , T_2 V_203 , T_2 V_350 )
{
struct V_11 * V_12 ;
struct V_351 * V_192 ;
int V_35 = 0 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_352 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_353 = F_68 ( 1 ) ;
V_192 -> V_354 [ 0 ] . V_203 = F_68 ( V_203 ) ;
V_192 -> V_354 [ 0 ] . V_355 = 0 ;
V_192 -> V_354 [ 0 ] . V_356 = F_68 ( V_350 ) ;
F_3 ( V_2 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_117 ( struct V_1 * V_2 , T_2 V_213 , T_3 * V_357 ,
T_2 V_109 , bool V_358 , bool V_359 )
{
struct V_11 * V_12 ;
struct V_360 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_361 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_275 = V_213 ;
V_192 -> V_359 = V_359 ;
V_192 -> V_358 = V_358 ;
V_192 -> V_362 = V_109 ;
if ( ! V_359 ) {
memcpy ( V_192 -> V_363 , V_357 ,
V_192 -> V_362 * sizeof( V_357 [ 0 ] ) ) ;
}
V_35 = F_47 ( V_2 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_118 ( struct V_1 * V_2 , T_2 V_26 , T_2 V_364 )
{
struct V_11 * V_12 ;
struct V_124 * V_163 = & V_2 -> V_365 ;
struct V_366 * V_192 = V_163 -> V_128 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
memset ( V_192 , 0 , sizeof( * V_192 ) ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_367 , sizeof( * V_192 ) ,
V_12 , V_163 ) ;
V_192 -> V_213 = F_68 ( V_2 -> V_206 ) ;
if ( V_26 & V_368 ) {
V_192 -> V_369 = F_68 ( V_370 |
V_371 |
V_372 ) ;
if ( V_364 == V_373 )
V_192 -> V_374 = F_68 ( V_370 |
V_371 |
V_372 ) ;
} else if ( V_26 & V_375 ) {
V_192 -> V_369 = V_192 -> V_374 =
F_68 ( V_372 ) ;
} else {
struct V_376 * V_377 ;
int V_5 = 0 ;
V_192 -> V_369 = V_192 -> V_374 =
F_68 ( V_378 ) ;
V_192 -> V_369 |=
F_68 ( V_372 &
V_2 -> V_379 ) ;
V_192 -> V_380 = F_68 ( F_119 ( V_2 -> V_381 ) ) ;
F_120 (ha, adapter->netdev)
memcpy ( V_192 -> V_382 [ V_5 ++ ] . V_383 , V_377 -> V_31 , V_216 ) ;
}
V_35 = F_47 ( V_2 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_121 ( struct V_1 * V_2 , T_2 V_384 , T_2 V_385 )
{
struct V_11 * V_12 ;
struct V_386 * V_192 ;
int V_35 ;
if ( ! F_1 ( V_2 , V_387 ,
V_40 ) )
return - V_222 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_387 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_388 = F_85 ( ( T_3 ) V_384 ) ;
V_192 -> V_389 = F_85 ( ( T_3 ) V_385 ) ;
V_35 = F_47 ( V_2 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_122 ( struct V_1 * V_2 , T_2 * V_384 , T_2 * V_385 )
{
struct V_11 * V_12 ;
struct V_390 * V_192 ;
int V_35 ;
if ( ! F_1 ( V_2 , V_391 ,
V_40 ) )
return - V_222 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_391 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_392 * V_50 =
F_2 ( V_12 ) ;
* V_384 = F_22 ( V_50 -> V_388 ) ;
* V_385 = F_22 ( V_50 -> V_389 ) ;
}
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_123 ( struct V_1 * V_2 , T_2 * V_80 ,
T_2 * V_393 , T_2 * V_394 , T_3 * V_395 )
{
struct V_11 * V_12 ;
struct V_396 * V_192 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_75 ( V_2 ) ;
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_397 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_398 * V_50 = F_2 ( V_12 ) ;
* V_80 = F_8 ( V_50 -> V_399 ) ;
* V_393 = F_8 ( V_50 -> V_400 ) ;
* V_394 = F_8 ( V_50 -> V_259 ) ;
* V_395 = F_8 ( V_50 -> V_401 ) & 0xFF ;
}
F_82 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_124 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_160 * V_192 ;
int V_35 ;
if ( F_18 ( V_2 ) ) {
V_35 = F_59 ( V_2 ) ;
if ( ! V_35 ) {
F_6 ( V_151 ,
V_2 -> V_22 + V_152 ) ;
V_35 = F_62 ( V_2 ) ;
}
if ( V_35 ) {
F_16 ( & V_2 -> V_59 -> V_60 ,
L_15 ) ;
}
return V_35 ;
}
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_75 ( V_2 ) ;
V_192 = F_2 ( V_12 ) ;
F_67 ( V_192 , V_40 ,
V_402 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_35 = F_54 ( V_2 ) ;
F_82 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_125 ( struct V_1 * V_2 , T_1 * V_403 ,
T_2 V_404 , T_3 V_405 )
{
struct V_11 * V_12 ;
struct V_406 * V_192 ;
T_2 V_407 [ 10 ] = { 0x15d43fa5 , 0x2534685a , 0x5f87693a , 0x5668494e ,
0x33cf6a53 , 0x383334c6 , 0x76ac4257 , 0x59b242b2 ,
0x3ea83c02 , 0x4a110304 } ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_75 ( V_2 ) ;
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_46 ,
V_408 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_213 = F_68 ( V_2 -> V_206 ) ;
V_192 -> V_409 = F_85 ( V_404 ) ;
V_192 -> V_410 = F_85 ( F_94 ( V_405 ) - 1 ) ;
if ( F_18 ( V_2 ) || F_126 ( V_2 ) )
V_192 -> V_195 . V_167 = 1 ;
memcpy ( V_192 -> V_411 , V_403 , V_405 ) ;
memcpy ( V_192 -> V_412 , V_407 , sizeof( V_407 ) ) ;
F_69 ( V_192 -> V_412 , sizeof( V_192 -> V_412 ) ) ;
V_35 = F_54 ( V_2 ) ;
F_82 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_127 ( struct V_1 * V_2 , T_1 V_80 ,
T_1 V_413 , T_1 V_414 , T_1 V_415 )
{
struct V_11 * V_12 ;
struct V_416 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_417 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_80 = V_80 ;
V_192 -> V_418 = V_415 ;
V_192 -> V_419 = V_413 ;
V_192 -> V_420 = V_414 ;
V_35 = F_47 ( V_2 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_128 ( struct V_1 * V_2 , T_1 V_80 , T_2 * V_415 )
{
struct V_11 * V_12 ;
struct V_421 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_422 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_80 = V_80 ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_423 * V_50 =
F_2 ( V_12 ) ;
* V_415 = V_50 -> V_418 ;
}
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_129 ( struct V_1 * V_2 , struct V_124 * V_424 ,
T_2 V_425 , T_2 V_426 ,
const char * V_427 , T_2 * V_428 ,
T_1 * V_429 , T_1 * V_430 )
{
struct V_11 * V_12 ;
struct V_431 * V_192 ;
struct V_432 * V_50 ;
void * V_229 = NULL ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_2 -> V_41 = 0 ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_433;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_39 ,
sizeof( struct V_431 ) , V_12 ,
NULL ) ;
V_229 = & V_192 -> V_199 ;
F_86 ( struct V_434 ,
V_435 , V_229 , V_425 ) ;
if ( V_425 == 0 )
F_86 ( struct V_434 ,
V_436 , V_229 , 1 ) ;
else
F_86 ( struct V_434 ,
V_436 , V_229 , 0 ) ;
F_69 ( V_229 , sizeof( V_192 -> V_199 ) ) ;
V_192 -> V_437 = F_68 ( V_426 ) ;
strcpy ( V_192 -> V_438 , V_427 ) ;
V_192 -> V_439 = F_68 ( 1 ) ;
V_192 -> V_329 = F_68 ( V_425 ) ;
V_192 -> V_440 = F_68 ( ( V_424 -> V_130 +
sizeof( struct V_431 ) )
& 0xFFFFFFFF ) ;
V_192 -> V_441 = F_68 ( F_55 ( V_424 -> V_130 +
sizeof( struct V_431 ) ) ) ;
F_3 ( V_2 ) ;
F_35 ( & V_2 -> V_209 ) ;
if ( ! F_130 ( & V_2 -> V_42 ,
F_131 ( 60000 ) ) )
V_35 = - 1 ;
else
V_35 = V_2 -> V_41 ;
V_50 = F_2 ( V_12 ) ;
if ( ! V_35 ) {
* V_428 = F_8 ( V_50 -> V_442 ) ;
* V_429 = V_50 -> V_429 ;
} else {
* V_430 = V_50 -> V_443 ;
}
return V_35 ;
V_433:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_132 ( struct V_1 * V_2 , struct V_124 * V_424 ,
T_2 V_425 , T_2 V_426 , const char * V_427 ,
T_2 * V_444 , T_2 * V_436 , T_1 * V_430 )
{
struct V_11 * V_12 ;
struct V_445 * V_192 ;
struct V_446 * V_50 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_433;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_447 ,
sizeof( struct V_445 ) , V_12 ,
NULL ) ;
V_192 -> V_448 = F_68 ( V_425 ) ;
V_192 -> V_449 = F_68 ( V_426 ) ;
strcpy ( V_192 -> V_438 , V_427 ) ;
V_192 -> V_439 = F_68 ( 1 ) ;
V_192 -> V_329 = F_68 ( V_425 ) ;
V_192 -> V_440 = F_68 ( ( V_424 -> V_130 & 0xFFFFFFFF ) ) ;
V_192 -> V_441 = F_68 ( F_55 ( V_424 -> V_130 ) ) ;
V_35 = F_47 ( V_2 ) ;
V_50 = F_2 ( V_12 ) ;
if ( ! V_35 ) {
* V_444 = F_8 ( V_50 -> V_450 ) ;
* V_436 = F_8 ( V_50 -> V_436 ) ;
} else {
* V_430 = V_50 -> V_443 ;
}
V_433:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_133 ( struct V_1 * V_2 , struct V_124 * V_424 ,
T_2 V_451 , T_2 V_452 , T_2 V_334 )
{
struct V_11 * V_12 ;
struct F_133 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_2 -> V_41 = 0 ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_433;
}
V_192 = V_424 -> V_128 ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_38 , V_424 -> V_174 , V_12 , V_424 ) ;
V_192 -> V_306 . V_453 = F_68 ( V_451 ) ;
V_192 -> V_306 . V_454 = F_68 ( V_452 ) ;
V_192 -> V_306 . V_455 = F_68 ( V_334 ) ;
F_3 ( V_2 ) ;
F_35 ( & V_2 -> V_209 ) ;
if ( ! F_130 ( & V_2 -> V_42 ,
F_131 ( 40000 ) ) )
V_35 = - 1 ;
else
V_35 = V_2 -> V_41 ;
return V_35 ;
V_433:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_134 ( struct V_1 * V_2 , T_1 * V_456 ,
int V_332 )
{
struct V_11 * V_12 ;
struct V_457 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_458 , sizeof( * V_192 ) ,
V_12 , NULL ) ;
V_192 -> V_306 . V_453 = F_68 ( V_459 ) ;
V_192 -> V_306 . V_454 = F_68 ( V_460 ) ;
V_192 -> V_306 . V_332 = F_68 ( V_332 ) ;
V_192 -> V_306 . V_455 = F_68 ( 0x4 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 )
memcpy ( V_456 , V_192 -> V_461 , 4 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_135 ( struct V_1 * V_2 , T_1 * V_215 ,
struct V_124 * V_303 )
{
struct V_11 * V_12 ;
struct V_462 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = V_303 -> V_128 ;
F_67 ( & V_192 -> V_195 , V_46 ,
V_463 , sizeof( * V_192 ) , V_12 ,
V_303 ) ;
memcpy ( V_192 -> V_464 , V_215 , V_216 ) ;
V_35 = F_47 ( V_2 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_136 ( struct V_1 * V_2 , T_1 V_80 ,
T_1 V_465 , T_1 V_466 )
{
struct V_11 * V_12 ;
struct V_467 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_468 ,
V_469 , sizeof( * V_192 ) , V_12 ,
NULL ) ;
V_192 -> V_470 = V_80 ;
V_192 -> V_471 = V_80 ;
V_192 -> V_465 = V_465 ;
V_192 -> V_472 = V_466 ;
V_35 = F_47 ( V_2 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_137 ( struct V_1 * V_2 , T_2 V_80 ,
T_2 V_465 , T_2 V_473 , T_2 V_474 , T_5 V_475 )
{
struct V_11 * V_12 ;
struct V_476 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_468 ,
V_477 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_195 . V_154 = F_68 ( 4 ) ;
V_192 -> V_475 = F_138 ( V_475 ) ;
V_192 -> V_470 = F_68 ( V_80 ) ;
V_192 -> V_471 = F_68 ( V_80 ) ;
V_192 -> V_473 = F_68 ( V_473 ) ;
V_192 -> V_474 = F_68 ( V_474 ) ;
V_192 -> V_465 = F_68 ( V_465 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_478 * V_50 = F_2 ( V_12 ) ;
V_35 = F_8 ( V_50 -> V_35 ) ;
}
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_139 ( struct V_1 * V_2 , T_5 V_475 ,
T_2 V_479 , struct V_124 * V_424 )
{
struct V_11 * V_12 ;
struct V_480 * V_192 ;
int V_35 ;
int V_5 , V_481 = 0 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = V_424 -> V_128 ;
F_67 ( & V_192 -> V_195 , V_468 ,
V_482 , V_424 -> V_174 , V_12 , V_424 ) ;
V_192 -> V_475 = F_138 ( V_475 ) ;
V_192 -> V_483 = F_68 ( V_479 ) ;
for ( V_5 = 0 ; V_5 < V_479 ; V_5 ++ ) {
V_192 -> V_484 [ V_5 ] = ( T_1 ) ( V_475 >> ( V_481 * 8 ) ) ;
V_481 ++ ;
if ( V_481 > 7 )
V_481 = 0 ;
}
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_485 * V_50 ;
V_50 = V_424 -> V_128 ;
if ( ( memcmp ( V_50 -> V_486 , V_192 -> V_484 , V_479 ) != 0 ) ||
V_50 -> V_487 ) {
V_35 = - 1 ;
}
}
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_140 ( struct V_1 * V_2 ,
struct V_124 * V_303 )
{
struct V_11 * V_12 ;
struct V_488 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = V_303 -> V_128 ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_489 , sizeof( * V_192 ) , V_12 ,
V_303 ) ;
V_35 = F_47 ( V_2 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_141 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_490 * V_192 ;
struct V_124 V_424 ;
int V_35 ;
if ( ! F_1 ( V_2 , V_491 ,
V_40 ) )
return - V_222 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_424 . V_174 = sizeof( struct V_490 ) ;
V_424 . V_128 = F_113 ( V_2 -> V_59 , V_424 . V_174 ,
& V_424 . V_130 ) ;
if ( ! V_424 . V_128 ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_16 ) ;
V_35 = - V_337 ;
goto V_146;
}
V_192 = V_424 . V_128 ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_491 , sizeof( * V_192 ) ,
V_12 , & V_424 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_492 * V_493 =
V_424 . V_128 + sizeof( struct V_160 ) ;
V_2 -> V_65 . V_494 = F_22 ( V_493 -> V_494 ) ;
V_2 -> V_65 . V_495 =
F_22 ( V_493 -> V_495 ) ;
V_2 -> V_65 . V_496 =
F_22 ( V_493 -> V_496 ) ;
V_2 -> V_65 . V_497 =
F_22 ( V_493 -> V_497 ) ;
V_2 -> V_65 . V_498 =
F_8 ( V_493 -> V_498 ) ;
}
F_114 ( V_2 -> V_59 , V_424 . V_174 ,
V_424 . V_128 , V_424 . V_130 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_142 ( struct V_1 * V_2 , T_2 V_499 , T_2 V_217 )
{
struct V_11 * V_12 ;
struct V_500 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_501 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_195 . V_217 = V_217 ;
V_192 -> V_502 = F_68 ( V_503 ) ;
V_192 -> V_504 = F_68 ( V_499 ) ;
V_35 = F_47 ( V_2 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_143 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_505 * V_192 ;
struct V_506 * V_50 ;
int V_35 ;
int V_336 = F_144 ( sizeof( * V_192 ) , sizeof( * V_50 ) ) ;
struct V_507 * V_508 ;
struct V_124 V_509 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
memset ( & V_509 , 0 , sizeof( struct V_124 ) ) ;
V_509 . V_174 = sizeof( struct V_506 ) ;
V_509 . V_128 = F_113 ( V_2 -> V_59 , V_509 . V_174 ,
& V_509 . V_130 ) ;
if ( ! V_509 . V_128 ) {
F_16 ( & V_2 -> V_59 -> V_60 ,
L_17 ) ;
V_35 = - V_337 ;
goto V_146;
}
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = V_509 . V_128 ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_510 , V_336 , V_12 ,
& V_509 ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
V_508 = V_509 . V_128 + sizeof( struct V_28 ) ;
V_2 -> V_308 = V_508 -> V_511 . V_512 ;
}
V_146:
F_82 ( & V_2 -> V_188 ) ;
if ( V_509 . V_128 )
F_114 ( V_2 -> V_59 , V_509 . V_174 ,
V_509 . V_128 , V_509 . V_130 ) ;
return V_35 ;
}
int F_145 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_513 * V_192 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_514 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_515 = F_68 ( V_516 |
V_517 ) ;
V_192 -> V_293 = F_68 ( V_517 ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_518 * V_50 = F_2 ( V_12 ) ;
V_2 -> V_519 = F_8 ( V_50 -> V_293 ) &
V_517 ;
if ( ! V_2 -> V_519 )
F_15 ( & V_2 -> V_59 -> V_60 ,
L_18 ) ;
}
V_146:
F_82 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_146 ( struct V_1 * V_2 , T_2 * V_520 ,
T_2 V_217 )
{
struct V_11 * V_12 ;
struct V_521 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_522 , sizeof( * V_192 ) ,
V_12 , NULL ) ;
V_192 -> V_195 . V_217 = V_217 ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_523 * V_50 =
F_2 ( V_12 ) ;
* V_520 = F_8 ( V_50 -> V_524 ) ;
}
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_147 ( struct V_1 * V_2 , T_1 * V_215 ,
bool * V_525 , T_2 * V_207 , T_1 V_217 )
{
struct V_11 * V_12 ;
struct V_526 * V_192 ;
int V_35 ;
int V_527 ;
struct V_124 V_528 ;
int V_5 ;
memset ( & V_528 , 0 , sizeof( struct V_124 ) ) ;
V_528 . V_174 = sizeof( struct V_529 ) ;
V_528 . V_128 = F_113 ( V_2 -> V_59 ,
V_528 . V_174 ,
& V_528 . V_130 ) ;
if ( ! V_528 . V_128 ) {
F_16 ( & V_2 -> V_59 -> V_60 ,
L_19 ) ;
return - V_337 ;
}
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_119;
}
V_192 = V_528 . V_128 ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_530 ,
V_528 . V_174 , V_12 , & V_528 ) ;
V_192 -> V_195 . V_217 = V_217 ;
V_192 -> V_531 = V_212 ;
V_192 -> V_532 = 1 ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_529 * V_50 =
V_528 . V_128 ;
V_527 = V_50 -> V_533 + V_50 -> V_534 ;
for ( V_5 = 0 ; V_5 < V_527 ; V_5 ++ ) {
struct V_535 * V_536 ;
T_3 V_537 ;
T_2 V_538 ;
V_536 = & V_50 -> V_539 [ V_5 ] ;
V_537 = F_22 ( V_536 -> V_537 ) ;
if ( V_537 == sizeof( T_2 ) ) {
* V_525 = true ;
V_538 = V_536 -> V_540 . V_541 . V_538 ;
* V_207 = F_8 ( V_538 ) ;
goto V_119;
}
}
* V_525 = false ;
memcpy ( V_215 , V_50 -> V_539 [ 0 ] . V_540 . V_542 ,
V_216 ) ;
}
V_119:
F_35 ( & V_2 -> V_209 ) ;
F_114 ( V_2 -> V_59 , V_528 . V_174 ,
V_528 . V_128 , V_528 . V_130 ) ;
return V_35 ;
}
int F_148 ( struct V_1 * V_2 , T_1 * V_543 ,
T_1 V_527 , T_2 V_217 )
{
struct V_11 * V_12 ;
struct V_544 * V_192 ;
int V_35 ;
struct V_124 V_424 ;
memset ( & V_424 , 0 , sizeof( struct V_124 ) ) ;
V_424 . V_174 = sizeof( struct V_544 ) ;
V_424 . V_128 = F_149 ( & V_2 -> V_59 -> V_60 , V_424 . V_174 ,
& V_424 . V_130 , V_545 ) ;
if ( ! V_424 . V_128 )
return - V_337 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = V_424 . V_128 ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_546 , sizeof( * V_192 ) ,
V_12 , & V_424 ) ;
V_192 -> V_195 . V_217 = V_217 ;
V_192 -> V_527 = V_527 ;
if ( V_527 )
memcpy ( V_192 -> V_215 , V_543 , V_216 * V_527 ) ;
V_35 = F_47 ( V_2 ) ;
V_146:
F_150 ( & V_2 -> V_59 -> V_60 , V_424 . V_174 ,
V_424 . V_128 , V_424 . V_130 ) ;
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_151 ( struct V_1 * V_2 , T_3 V_84 ,
T_2 V_217 , T_3 V_547 )
{
struct V_11 * V_12 ;
struct V_548 * V_192 ;
void * V_229 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
V_229 = & V_192 -> V_199 ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_549 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_195 . V_217 = V_217 ;
F_86 ( struct V_550 , V_275 , V_229 , V_547 ) ;
if ( V_84 ) {
F_86 ( struct V_550 , V_551 , V_229 , 1 ) ;
F_86 ( struct V_550 , V_84 , V_229 , V_84 ) ;
}
F_69 ( V_192 -> V_199 , sizeof( V_192 -> V_199 ) ) ;
V_35 = F_47 ( V_2 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_152 ( struct V_1 * V_2 , T_3 * V_84 ,
T_2 V_217 , T_3 V_547 )
{
struct V_11 * V_12 ;
struct V_552 * V_192 ;
void * V_229 ;
int V_35 ;
T_3 V_553 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
V_229 = & V_192 -> V_199 ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_554 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_195 . V_217 = V_217 ;
F_86 ( struct V_555 , V_275 , V_229 ,
V_547 ) ;
F_86 ( struct V_555 , V_551 , V_229 , 1 ) ;
F_69 ( V_192 -> V_199 , sizeof( V_192 -> V_199 ) ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_556 * V_50 =
F_2 ( V_12 ) ;
F_12 ( & V_50 -> V_199 ,
sizeof( V_50 -> V_199 ) ) ;
V_553 = F_153 ( struct V_557 ,
V_84 , & V_50 -> V_199 ) ;
* V_84 = F_22 ( V_553 ) ;
}
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_154 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_558 * V_192 ;
int V_35 ;
int V_336 = sizeof( * V_192 ) ;
struct V_124 V_424 ;
if ( ! F_1 ( V_2 , V_463 ,
V_46 ) )
return - V_222 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
memset ( & V_424 , 0 , sizeof( struct V_124 ) ) ;
V_424 . V_174 = sizeof( struct V_559 ) ;
V_424 . V_128 = F_113 ( V_2 -> V_59 , V_424 . V_174 ,
& V_424 . V_130 ) ;
if ( ! V_424 . V_128 ) {
F_16 ( & V_2 -> V_59 -> V_60 ,
L_17 ) ;
V_35 = - V_337 ;
goto V_146;
}
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = V_424 . V_128 ;
F_67 ( & V_192 -> V_195 , V_46 ,
V_463 ,
V_336 , V_12 , & V_424 ) ;
V_192 -> V_195 . V_167 = 1 ;
V_192 -> V_560 = V_561 ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_559 * V_50 ;
V_50 = (struct V_559 * ) V_424 . V_128 ;
if ( V_50 -> V_195 . V_562 < V_336 ) {
V_35 = - 1 ;
goto V_146;
}
V_2 -> V_563 = V_50 -> V_564 ;
}
V_146:
F_82 ( & V_2 -> V_188 ) ;
if ( V_424 . V_128 )
F_114 ( V_2 -> V_59 , V_424 . V_174 , V_424 . V_128 , V_424 . V_130 ) ;
return V_35 ;
}
int F_155 ( struct V_1 * V_2 ,
struct V_124 * V_424 )
{
struct V_11 * V_12 ;
struct V_565 * V_192 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = V_424 -> V_128 ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_566 ,
V_424 -> V_174 , V_12 , V_424 ) ;
V_192 -> V_567 = F_68 ( 1 ) ;
V_35 = F_54 ( V_2 ) ;
V_146:
F_82 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_156 ( struct V_1 * V_2 ,
struct V_124 * V_424 ,
struct V_568 * V_569 )
{
struct V_11 * V_12 ;
struct V_570 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = V_424 -> V_128 ;
memcpy ( & V_192 -> V_571 , V_569 , sizeof( struct V_568 ) ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_572 ,
V_424 -> V_174 , V_12 , V_424 ) ;
V_35 = F_47 ( V_2 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_157 ( struct V_1 * V_2 , T_1 * V_573 )
{
struct V_11 * V_12 ;
struct V_574 * V_192 ;
int V_35 ;
if ( ! F_18 ( V_2 ) ) {
* V_573 = V_2 -> V_308 + '0' ;
return 0 ;
}
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_575 , sizeof( * V_192 ) , V_12 ,
NULL ) ;
V_192 -> V_195 . V_167 = 1 ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_576 * V_50 = F_2 ( V_12 ) ;
* V_573 = V_50 -> V_573 [ V_2 -> V_308 ] ;
} else {
* V_573 = V_2 -> V_308 + '0' ;
}
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
static struct V_577 * F_158 ( T_1 * V_330 , T_2 V_578 ,
T_2 V_579 )
{
struct V_577 * V_580 = (struct V_577 * ) V_330 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_578 ; V_5 ++ ) {
V_580 -> V_581 = V_580 -> V_581 ? : V_582 ;
if ( ( ( void * ) V_580 + V_580 -> V_581 ) >
( void * ) ( V_330 + V_579 ) )
return NULL ;
if ( V_580 -> V_583 == V_584 ||
V_580 -> V_583 == V_585 )
return V_580 ;
V_580 = ( void * ) V_580 + V_580 -> V_581 ;
}
return NULL ;
}
int F_159 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_586 * V_192 ;
int V_35 ;
struct V_124 V_424 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
memset ( & V_424 , 0 , sizeof( struct V_124 ) ) ;
V_424 . V_174 = sizeof( struct V_587 ) ;
V_424 . V_128 = F_113 ( V_2 -> V_59 , V_424 . V_174 ,
& V_424 . V_130 ) ;
if ( ! V_424 . V_128 ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_16 ) ;
V_35 = - V_337 ;
goto V_146;
}
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = V_424 . V_128 ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_588 ,
V_424 . V_174 , V_12 , & V_424 ) ;
if ( F_126 ( V_2 ) )
V_192 -> V_195 . V_167 = 1 ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_587 * V_50 = V_424 . V_128 ;
T_2 V_578 = F_8 ( V_50 -> V_578 ) ;
struct V_577 * V_580 ;
V_580 = F_158 ( V_50 -> V_589 , V_578 ,
sizeof( V_50 -> V_589 ) ) ;
if ( ! V_580 ) {
V_35 = - V_590 ;
goto V_146;
}
V_2 -> V_591 = V_580 -> V_592 ;
V_2 -> V_593 = F_22 ( V_580 -> V_594 ) ;
V_2 -> V_595 = F_22 ( V_580 -> V_596 ) ;
V_2 -> V_597 = F_22 ( V_580 -> V_598 ) ;
V_2 -> V_599 = F_22 ( V_580 -> V_600 ) ;
V_2 -> V_601 = F_22 ( V_580 -> V_602 ) ;
V_2 -> V_603 = F_22 ( V_580 -> V_604 ) ;
V_2 -> V_605 = F_22 ( V_580 -> V_606 ) ;
V_2 -> V_379 = F_8 ( V_580 -> V_293 ) ;
V_2 -> V_379 &= V_607 ;
}
V_146:
F_82 ( & V_2 -> V_188 ) ;
if ( V_424 . V_128 )
F_114 ( V_2 -> V_59 , V_424 . V_174 , V_424 . V_128 , V_424 . V_130 ) ;
return V_35 ;
}
int F_160 ( struct V_1 * V_2 ,
T_1 V_217 , struct V_124 * V_424 )
{
struct V_11 * V_12 ;
struct V_608 * V_192 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_75 ( V_2 ) ;
V_192 = V_424 -> V_128 ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_609 ,
V_424 -> V_174 , V_12 , V_424 ) ;
V_192 -> type = V_610 ;
V_192 -> V_195 . V_217 = V_217 ;
if ( ! F_18 ( V_2 ) )
V_192 -> V_195 . V_167 = 1 ;
V_35 = F_54 ( V_2 ) ;
F_82 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_161 ( struct V_1 * V_2 ,
T_1 V_217 , struct V_124 * V_424 )
{
struct V_11 * V_12 ;
struct V_608 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = V_424 -> V_128 ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_609 ,
V_424 -> V_174 , V_12 , V_424 ) ;
V_192 -> type = V_610 ;
V_192 -> V_195 . V_217 = V_217 ;
if ( ! F_18 ( V_2 ) )
V_192 -> V_195 . V_167 = 1 ;
V_35 = F_47 ( V_2 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_162 ( struct V_1 * V_2 , T_2 * V_293 ,
T_3 * V_600 , T_1 V_217 )
{
struct V_14 * V_15 = & V_2 -> V_16 . V_17 ;
struct V_124 V_424 ;
int V_35 ;
memset ( & V_424 , 0 , sizeof( struct V_124 ) ) ;
if ( ! F_18 ( V_2 ) )
V_424 . V_174 = sizeof( struct V_611 ) ;
else
V_424 . V_174 = sizeof( struct V_612 ) ;
V_424 . V_128 = F_113 ( V_2 -> V_59 , V_424 . V_174 ,
& V_424 . V_130 ) ;
if ( ! V_424 . V_128 ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_16 ) ;
return - V_337 ;
}
if ( ! V_15 -> V_187 )
V_35 = F_160 ( V_2 , V_217 , & V_424 ) ;
else
V_35 = F_161 ( V_2 , V_217 , & V_424 ) ;
if ( ! V_35 ) {
struct V_612 * V_50 = V_424 . V_128 ;
T_2 V_578 = F_8 ( V_50 -> V_578 ) ;
struct V_577 * V_580 ;
V_580 = F_158 ( V_50 -> V_589 , V_578 ,
sizeof( V_50 -> V_589 ) ) ;
if ( ! V_580 ) {
V_35 = - V_590 ;
goto V_146;
}
if ( V_293 )
* V_293 = F_8 ( V_580 -> V_293 ) ;
if ( V_600 )
* V_600 = F_8 ( V_580 -> V_600 ) ;
}
V_146:
if ( V_424 . V_128 )
F_114 ( V_2 -> V_59 , V_424 . V_174 ,
V_424 . V_128 , V_424 . V_130 ) ;
return V_35 ;
}
int F_163 ( struct V_1 * V_2 , T_2 V_499 ,
T_1 V_217 )
{
struct V_11 * V_12 ;
struct V_613 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_614 , sizeof( * V_192 ) ,
V_12 , NULL ) ;
V_192 -> V_195 . V_217 = V_217 ;
V_192 -> V_578 = F_68 ( 1 ) ;
V_192 -> V_615 . V_583 = V_584 ;
V_192 -> V_615 . V_581 = V_582 ;
V_192 -> V_615 . V_26 = ( 1 << V_616 ) | ( 1 << V_617 ) | ( 1 << V_618 ) ;
V_192 -> V_615 . V_592 = V_2 -> V_591 ;
V_192 -> V_615 . V_619 = V_217 ;
V_192 -> V_615 . V_594 = 0xFFFF ;
V_192 -> V_615 . V_620 = 0xFFFF ;
V_192 -> V_615 . V_596 = 0xFFFF ;
V_192 -> V_615 . V_598 = 0xFFFF ;
V_192 -> V_615 . V_600 = 0xFFFF ;
V_192 -> V_615 . V_604 = 0xFFFF ;
V_192 -> V_615 . V_602 = 0xFFFF ;
V_192 -> V_615 . V_621 = 0xFFFF ;
V_192 -> V_615 . V_622 = 0xFFFF ;
V_192 -> V_615 . V_623 = 0xFFFF ;
V_192 -> V_615 . V_606 = 0xFFFF ;
V_192 -> V_615 . V_624 = 0xFF ;
V_192 -> V_615 . V_625 = 0xFFFFFFFF ;
V_192 -> V_615 . V_626 = 0xFF ;
V_192 -> V_615 . V_627 = 0x0F ;
V_192 -> V_615 . V_625 = F_68 ( V_499 ) ;
V_192 -> V_615 . V_628 = F_68 ( V_499 ) ;
V_35 = F_47 ( V_2 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_164 ( struct V_1 * V_2 , struct V_629 * V_630 ,
int V_619 )
{
struct V_11 * V_12 ;
struct V_631 * V_192 ;
struct V_632 * V_50 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_633 , sizeof( * V_50 ) ,
V_12 , NULL ) ;
V_192 -> V_195 . V_217 = V_619 + 1 ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
V_50 = (struct V_632 * ) V_192 ;
V_630 -> V_206 = F_8 ( V_50 -> V_634 . V_213 ) ;
}
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
static int F_165 ( struct V_1 * V_2 )
{
#define F_166 30
T_2 V_635 ;
int V_35 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < F_166 ; V_5 ++ ) {
V_635 = F_51 ( V_2 -> V_22 + V_636 ) ;
if ( ( V_635 & V_637 ) == 0 )
break;
F_167 ( 1 ) ;
}
if ( V_5 == F_166 )
V_35 = - 1 ;
return V_35 ;
}
int F_168 ( struct V_1 * V_2 , T_2 V_638 )
{
int V_35 = 0 ;
V_35 = F_165 ( V_2 ) ;
if ( V_35 )
return V_35 ;
F_6 ( V_638 , V_2 -> V_22 + V_636 ) ;
return V_35 ;
}
bool F_169 ( struct V_1 * V_2 )
{
T_2 V_136 = 0 ;
V_136 = F_51 ( V_2 -> V_22 + V_137 ) ;
return ! ! ( V_136 & V_639 ) ;
}
int F_170 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_168 ( V_2 , V_640 |
V_641 ) ;
if ( V_35 < 0 ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_20 ) ;
return V_35 ;
}
V_35 = F_165 ( V_2 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_169 ( V_2 ) ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_21 ) ;
return - 1 ;
}
return 0 ;
}
int F_171 ( struct V_1 * V_2 , T_1 V_217 )
{
struct V_11 * V_12 ;
struct V_642 * V_192 ;
int V_35 ;
if ( ! F_18 ( V_2 ) )
return 0 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_643 , sizeof( * V_192 ) ,
V_12 , NULL ) ;
V_192 -> V_195 . V_217 = V_217 ;
V_192 -> V_466 = 1 ;
V_35 = F_47 ( V_2 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
int F_172 ( struct V_1 * V_2 , bool V_644 )
{
struct V_11 * V_12 ;
struct V_645 * V_192 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_75 ( V_2 ) ;
V_192 = F_2 ( V_12 ) ;
F_67 ( & V_192 -> V_195 , V_40 ,
V_646 , sizeof( * V_192 ) ,
V_12 , NULL ) ;
V_192 -> V_647 = V_644 ;
V_35 = F_54 ( V_2 ) ;
F_82 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_173 ( void * V_648 , void * V_649 ,
int V_650 , T_3 * V_651 , T_3 * V_652 )
{
struct V_1 * V_2 = F_174 ( V_648 ) ;
struct V_11 * V_12 ;
struct V_160 * V_195 = (struct V_160 * ) V_649 ;
struct V_160 * V_192 ;
struct V_28 * V_50 ;
int V_35 ;
F_33 ( & V_2 -> V_209 ) ;
V_12 = F_76 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_210 ;
goto V_146;
}
V_192 = F_2 ( V_12 ) ;
V_50 = F_2 ( V_12 ) ;
F_67 ( V_192 , V_195 -> V_4 ,
V_195 -> V_3 , V_650 , V_12 , NULL ) ;
memcpy ( V_192 , V_649 , V_650 ) ;
F_69 ( V_192 , V_650 ) ;
V_35 = F_47 ( V_2 ) ;
if ( V_651 )
* V_651 = ( V_35 & 0xffff ) ;
if ( V_652 )
* V_652 = 0 ;
memcpy ( V_649 , V_50 , sizeof( * V_50 ) + V_50 -> V_562 ) ;
F_12 ( V_649 , sizeof( * V_50 ) + V_50 -> V_562 ) ;
V_146:
F_35 ( & V_2 -> V_209 ) ;
return V_35 ;
}
