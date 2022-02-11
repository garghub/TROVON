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
static int F_10 ( struct V_4 * V_5 ,
struct V_16 * V_17 )
{
T_2 V_20 , V_21 ;
F_11 ( V_17 , 4 ) ;
V_20 = ( V_17 -> V_22 >> V_23 ) &
V_24 ;
if ( ( ( V_17 -> V_25 == V_26 ) ||
( V_17 -> V_25 == V_27 ) ) &&
( V_17 -> V_28 == V_29 ) ) {
V_5 -> V_30 = V_20 ;
F_12 ( & V_5 -> V_31 ) ;
}
if ( V_20 == V_32 ) {
if ( ( ( V_17 -> V_25 == V_33 ) ||
( V_17 -> V_25 == V_34 ) ) &&
( V_17 -> V_28 == V_35 ) ) {
F_13 ( V_5 ) ;
V_5 -> V_36 = false ;
}
if ( V_17 -> V_25 ==
V_37 ) {
struct V_1 * V_38 =
F_14 ( & V_5 -> V_8 . V_9 ,
V_17 -> V_28 ) ;
struct V_39 * V_40 =
F_1 ( V_38 ) ;
V_5 -> V_41 . V_42 =
V_40 -> V_43 ;
}
} else {
if ( V_17 -> V_25 == V_37 )
V_44 = 0 ;
if ( V_20 == V_45 ||
V_20 == V_46 )
goto V_47;
if ( V_20 == V_48 ) {
F_15 ( & V_5 -> V_49 -> V_50 , L_1
L_2 ,
V_17 -> V_25 ) ;
} else {
V_21 = ( V_17 -> V_22 >> V_51 ) &
V_52 ;
F_16 ( & V_5 -> V_49 -> V_50 , L_3
L_4 ,
V_17 -> V_25 , V_20 , V_21 ) ;
}
}
V_47:
return V_20 ;
}
static void F_17 ( struct V_4 * V_5 ,
struct V_53 * V_54 )
{
V_5 -> V_55 = - 1 ;
if ( V_5 -> V_18 & V_56 )
F_18 ( V_5 , V_54 -> V_57 ) ;
}
static void F_19 ( struct V_4 * V_5 ,
struct V_58 * V_54 )
{
if ( V_54 -> V_59 ) {
V_5 -> V_60 = V_54 -> V_61 ;
V_5 -> V_62 &= ~ V_63 ;
V_5 -> V_62 =
V_54 -> V_64 << V_65 ;
}
}
static void F_20 ( struct V_4 * V_5 ,
struct V_66 * V_54 )
{
if ( V_54 -> V_67 == V_5 -> V_68 ) {
V_5 -> V_55 = V_54 -> V_69 * 10 ;
}
}
static void F_21 ( struct V_4 * V_5 ,
struct V_70 * V_54 )
{
if ( V_54 -> V_71 )
V_5 -> V_72 = F_22 ( V_54 -> V_73 ) & V_74 ;
else
V_5 -> V_72 = 0 ;
}
static void F_23 ( struct V_4 * V_5 ,
T_1 V_75 , struct V_16 * V_54 )
{
T_3 V_76 = 0 ;
V_76 = ( V_75 >> V_77 ) &
V_78 ;
switch ( V_76 ) {
case V_79 :
F_19 ( V_5 ,
(struct V_58 * ) V_54 ) ;
break;
case V_80 :
F_20 ( V_5 ,
(struct V_66 * ) V_54 ) ;
break;
case V_81 :
F_21 ( V_5 ,
(struct V_70 * ) V_54 ) ;
break;
default:
F_15 ( & V_5 -> V_49 -> V_50 , L_5 ) ;
break;
}
}
static inline bool F_24 ( T_1 V_75 )
{
return ( ( V_75 >> V_82 ) &
V_83 ) ==
V_84 ;
}
static inline bool F_25 ( T_1 V_75 )
{
return ( ( ( V_75 >> V_82 ) &
V_83 ) ==
V_85 ) ;
}
static struct V_16 * F_26 ( struct V_4 * V_5 )
{
struct V_6 * V_86 = & V_5 -> V_8 . V_87 ;
struct V_16 * V_17 = F_27 ( V_86 ) ;
if ( F_6 ( V_17 ) ) {
F_28 ( V_86 ) ;
return V_17 ;
}
return NULL ;
}
void F_29 ( struct V_4 * V_5 )
{
F_30 ( & V_5 -> V_88 ) ;
F_31 ( V_5 , V_5 -> V_8 . V_87 . V_11 , true , 0 ) ;
V_5 -> V_8 . V_89 = true ;
F_32 ( & V_5 -> V_88 ) ;
}
void F_33 ( struct V_4 * V_5 )
{
V_5 -> V_8 . V_89 = false ;
}
int F_34 ( struct V_4 * V_5 , int * V_22 )
{
struct V_16 * V_17 ;
int V_90 = 0 ;
struct V_91 * V_8 = & V_5 -> V_8 ;
F_30 ( & V_5 -> V_88 ) ;
while ( ( V_17 = F_26 ( V_5 ) ) ) {
if ( V_17 -> V_18 & V_92 ) {
if ( F_24 ( V_17 -> V_18 ) )
F_17 ( V_5 ,
(struct V_53 * ) V_17 ) ;
else if ( F_25 ( V_17 -> V_18 ) )
F_23 ( V_5 ,
V_17 -> V_18 , V_17 ) ;
} else if ( V_17 -> V_18 & V_93 ) {
* V_22 = F_10 ( V_5 , V_17 ) ;
F_35 ( & V_8 -> V_9 . V_94 ) ;
}
F_9 ( V_17 ) ;
V_90 ++ ;
}
F_32 ( & V_5 -> V_88 ) ;
return V_90 ;
}
static int F_36 ( struct V_4 * V_5 )
{
#define F_37 120000
int V_95 , V_90 , V_22 = 0 ;
struct V_91 * V_8 = & V_5 -> V_8 ;
for ( V_95 = 0 ; V_95 < F_37 ; V_95 ++ ) {
if ( F_3 ( V_5 ) )
return - V_96 ;
V_90 = F_34 ( V_5 , & V_22 ) ;
if ( V_90 )
F_31 ( V_5 , V_8 -> V_87 . V_11 ,
V_8 -> V_89 , V_90 ) ;
if ( F_38 ( & V_8 -> V_9 . V_94 ) == 0 )
break;
F_39 ( 100 ) ;
}
if ( V_95 == F_37 ) {
F_16 ( & V_5 -> V_49 -> V_50 , L_6 ) ;
V_5 -> V_97 = true ;
return - 1 ;
}
return V_22 ;
}
static int F_40 ( struct V_4 * V_5 )
{
F_2 ( V_5 ) ;
return F_36 ( V_5 ) ;
}
static int F_41 ( struct V_4 * V_5 , void T_4 * V_14 )
{
int V_98 = 0 ;
T_1 V_99 ;
do {
if ( F_3 ( V_5 ) )
return - V_96 ;
V_99 = F_42 ( V_14 ) ;
if ( V_99 == 0xffffffff )
return - 1 ;
V_99 &= V_100 ;
if ( V_99 )
break;
if ( V_98 > 4000 ) {
F_16 ( & V_5 -> V_49 -> V_50 , L_6 ) ;
V_5 -> V_97 = true ;
F_43 ( V_5 ) ;
return - 1 ;
}
F_44 ( 1 ) ;
V_98 ++ ;
} while ( true );
return 0 ;
}
static int F_45 ( struct V_4 * V_5 )
{
int V_22 ;
T_1 V_10 = 0 ;
void T_4 * V_14 = V_5 -> V_14 + V_101 ;
struct V_102 * V_103 = & V_5 -> V_103 ;
struct V_104 * V_105 = V_103 -> V_106 ;
struct V_16 * V_17 = & V_105 -> V_17 ;
V_22 = F_41 ( V_5 , V_14 ) ;
if ( V_22 != 0 )
return V_22 ;
V_10 |= V_107 ;
V_10 |= ( F_46 ( V_103 -> V_108 ) >> 2 ) << 2 ;
F_5 ( V_10 , V_14 ) ;
V_22 = F_41 ( V_5 , V_14 ) ;
if ( V_22 != 0 )
return V_22 ;
V_10 = 0 ;
V_10 |= ( T_1 ) ( V_103 -> V_108 >> 4 ) << 2 ;
F_5 ( V_10 , V_14 ) ;
V_22 = F_41 ( V_5 , V_14 ) ;
if ( V_22 != 0 )
return V_22 ;
if ( F_6 ( V_17 ) ) {
V_22 = F_10 ( V_5 , & V_105 -> V_17 ) ;
F_9 ( V_17 ) ;
if ( V_22 )
return V_22 ;
} else {
F_16 ( & V_5 -> V_49 -> V_50 , L_7 ) ;
return - 1 ;
}
return 0 ;
}
static int F_47 ( struct V_4 * V_5 , T_2 * V_109 )
{
T_1 V_110 ;
if ( F_48 ( V_5 ) )
V_110 = F_42 ( V_5 -> V_14 + V_111 ) ;
else
V_110 = F_42 ( V_5 -> V_112 + V_113 ) ;
* V_109 = V_110 & V_114 ;
if ( ( V_110 >> V_115 ) & V_116 )
return - 1 ;
else
return 0 ;
}
int F_49 ( struct V_4 * V_5 )
{
T_2 V_109 ;
int V_22 , V_117 = 0 ;
struct V_118 * V_50 = & V_5 -> V_49 -> V_50 ;
do {
V_22 = F_47 ( V_5 , & V_109 ) ;
if ( V_22 ) {
F_16 ( V_50 , L_8 , V_109 ) ;
return - 1 ;
} else if ( V_109 != V_119 ) {
if ( F_50 ( 2000 ) ) {
F_16 ( V_50 , L_9 ) ;
return - V_120 ;
}
V_117 += 2 ;
} else {
return 0 ;
}
} while ( V_117 < 60 );
F_16 ( V_50 , L_10 , V_109 ) ;
return - 1 ;
}
static inline struct V_121 * F_51 ( struct V_1 * V_2 )
{
return & V_2 -> V_3 . V_122 [ 0 ] ;
}
static void F_52 ( struct V_123 * V_124 ,
T_3 V_125 , T_3 V_126 , int V_127 ,
struct V_1 * V_2 , struct V_102 * V_128 )
{
struct V_121 * V_129 ;
V_124 -> V_126 = V_126 ;
V_124 -> V_125 = V_125 ;
V_124 -> V_130 = F_53 ( V_127 - sizeof( * V_124 ) ) ;
V_124 -> V_131 = 0 ;
V_2 -> V_25 = V_126 ;
V_2 -> V_28 = V_125 ;
V_2 -> V_132 = V_127 ;
if ( V_128 ) {
V_2 -> V_133 |= ( 1 & V_134 ) <<
V_135 ;
V_129 = F_51 ( V_2 ) ;
V_129 -> V_136 = F_53 ( F_46 ( V_128 -> V_108 ) ) ;
V_129 -> V_137 = F_53 ( V_128 -> V_108 & 0xFFFFFFFF ) ;
V_129 -> V_138 = F_53 ( V_128 -> V_139 ) ;
} else
V_2 -> V_133 |= V_140 ;
F_54 ( V_2 , 8 ) ;
}
static void F_55 ( struct V_141 * V_142 , T_1 V_143 ,
struct V_102 * V_128 )
{
int V_95 , V_144 = F_56 ( F_57 ( V_128 -> V_106 , V_128 -> V_139 ) , V_143 ) ;
T_5 V_108 = ( T_5 ) V_128 -> V_108 ;
for ( V_95 = 0 ; V_95 < V_144 ; V_95 ++ ) {
V_142 [ V_95 ] . V_145 = F_53 ( V_108 & 0xFFFFFFFF ) ;
V_142 [ V_95 ] . V_146 = F_53 ( F_46 ( V_108 ) ) ;
V_108 += V_147 ;
}
}
static T_1 F_58 ( T_1 V_148 )
{
#define F_59 651042
const T_1 V_149 = 10 ;
T_1 V_150 ;
if ( V_148 == 0 )
V_150 = 0 ;
else {
T_1 V_151 = 1000000 / V_148 ;
if ( V_151 == 0 )
V_150 = 1023 ;
else {
V_150 = ( F_59 - V_151 ) * V_149 ;
V_150 /= V_151 ;
V_150 = ( V_150 + V_149 / 2 ) / V_149 ;
V_150 = F_56 ( V_150 , ( T_1 ) 1023 ) ;
}
}
return V_150 ;
}
static inline struct V_1 * F_60 ( struct V_4 * V_5 )
{
struct V_102 * V_103 = & V_5 -> V_103 ;
struct V_1 * V_2
= & ( (struct V_104 * ) ( V_103 -> V_106 ) ) -> V_2 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
return V_2 ;
}
static struct V_1 * F_61 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 . V_9 ;
struct V_1 * V_2 ;
if ( F_38 ( & V_7 -> V_94 ) >= V_7 -> V_138 ) {
F_16 ( & V_5 -> V_49 -> V_50 , L_11 ) ;
return NULL ;
}
V_2 = F_62 ( V_7 ) ;
F_63 ( V_7 ) ;
F_64 ( & V_7 -> V_94 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
return V_2 ;
}
int F_65 ( struct V_4 * V_5 )
{
T_3 * V_2 ;
int V_22 ;
if ( F_66 ( & V_5 -> V_152 ) )
return - 1 ;
V_2 = ( T_3 * ) F_60 ( V_5 ) ;
* V_2 ++ = 0xFF ;
* V_2 ++ = 0x12 ;
* V_2 ++ = 0x34 ;
* V_2 ++ = 0xFF ;
* V_2 ++ = 0xFF ;
* V_2 ++ = 0x56 ;
* V_2 ++ = 0x78 ;
* V_2 = 0xFF ;
V_22 = F_45 ( V_5 ) ;
F_67 ( & V_5 -> V_152 ) ;
return V_22 ;
}
int F_68 ( struct V_4 * V_5 )
{
T_3 * V_2 ;
int V_22 ;
if ( F_66 ( & V_5 -> V_152 ) )
return - 1 ;
V_2 = ( T_3 * ) F_60 ( V_5 ) ;
* V_2 ++ = 0xFF ;
* V_2 ++ = 0xAA ;
* V_2 ++ = 0xBB ;
* V_2 ++ = 0xFF ;
* V_2 ++ = 0xFF ;
* V_2 ++ = 0xCC ;
* V_2 ++ = 0xDD ;
* V_2 = 0xFF ;
V_22 = F_45 ( V_5 ) ;
F_67 ( & V_5 -> V_152 ) ;
return V_22 ;
}
int F_69 ( struct V_4 * V_5 ,
struct V_6 * V_153 , int V_154 )
{
struct V_1 * V_2 ;
struct V_155 * V_156 ;
struct V_102 * V_157 = & V_153 -> V_158 ;
int V_22 ;
if ( F_66 ( & V_5 -> V_152 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_160 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_161 = F_70 ( F_57 ( V_157 -> V_106 , V_157 -> V_139 ) ) ;
F_71 ( struct V_162 , V_59 , V_156 -> V_163 , 1 ) ;
F_71 ( struct V_162 , V_139 , V_156 -> V_163 , 0 ) ;
F_71 ( struct V_162 , V_164 , V_156 -> V_163 ,
F_72 ( V_153 -> V_138 / 256 ) ) ;
F_71 ( struct V_162 , V_165 , V_156 -> V_163 ,
F_58 ( V_154 ) ) ;
F_54 ( V_156 -> V_163 , sizeof( V_156 -> V_163 ) ) ;
F_55 ( V_156 -> V_142 , F_73 ( V_156 -> V_142 ) , V_157 ) ;
V_22 = F_45 ( V_5 ) ;
if ( ! V_22 ) {
struct V_166 * V_40 = F_1 ( V_2 ) ;
V_153 -> V_11 = F_22 ( V_40 -> V_167 ) ;
V_153 -> V_168 = true ;
}
F_67 ( & V_5 -> V_152 ) ;
return V_22 ;
}
int F_74 ( struct V_4 * V_5 , T_3 * V_169 ,
T_3 type , bool V_170 , T_1 V_171 , T_1 V_172 )
{
struct V_1 * V_2 ;
struct V_173 * V_156 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_177 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> type = type ;
if ( V_170 ) {
V_156 -> V_170 = 1 ;
} else {
V_156 -> V_178 = F_70 ( ( T_2 ) V_171 ) ;
V_156 -> V_172 = F_53 ( V_172 ) ;
V_156 -> V_170 = 0 ;
}
V_22 = F_40 ( V_5 ) ;
if ( ! V_22 ) {
struct V_179 * V_40 = F_1 ( V_2 ) ;
memcpy ( V_169 , V_40 -> V_180 . V_181 , V_182 ) ;
}
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_75 ( struct V_4 * V_5 , T_3 * V_169 ,
T_1 V_178 , T_1 * V_172 , T_1 V_183 )
{
struct V_1 * V_2 ;
struct V_184 * V_156 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_185 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_159 . V_183 = V_183 ;
V_156 -> V_178 = F_53 ( V_178 ) ;
memcpy ( V_156 -> V_186 , V_169 , V_182 ) ;
V_22 = F_40 ( V_5 ) ;
if ( ! V_22 ) {
struct V_187 * V_40 = F_1 ( V_2 ) ;
* V_172 = F_7 ( V_40 -> V_172 ) ;
}
V_176:
F_32 ( & V_5 -> V_174 ) ;
if ( V_22 == V_48 )
V_22 = - V_188 ;
return V_22 ;
}
int F_76 ( struct V_4 * V_5 , T_1 V_178 , int V_172 , T_1 V_189 )
{
struct V_1 * V_2 ;
struct V_190 * V_156 ;
int V_22 ;
if ( V_172 == - 1 )
return 0 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_191 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_159 . V_183 = V_189 ;
V_156 -> V_178 = F_53 ( V_178 ) ;
V_156 -> V_172 = F_53 ( V_172 ) ;
V_22 = F_40 ( V_5 ) ;
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_77 ( struct V_4 * V_5 ,
struct V_6 * V_87 , struct V_6 * V_153 ,
bool V_192 , bool V_193 , int V_194 )
{
struct V_1 * V_2 ;
struct V_195 * V_156 ;
struct V_102 * V_157 = & V_87 -> V_158 ;
void * V_196 ;
int V_22 ;
if ( F_66 ( & V_5 -> V_152 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
V_156 = F_1 ( V_2 ) ;
V_196 = & V_156 -> V_163 ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_197 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_161 = F_70 ( F_57 ( V_157 -> V_106 , V_157 -> V_139 ) ) ;
if ( F_48 ( V_5 ) ) {
V_156 -> V_159 . V_131 = 2 ;
V_156 -> V_198 = 1 ;
F_71 ( struct V_199 , V_200 , V_196 ,
V_193 ) ;
F_71 ( struct V_199 , V_164 , V_196 ,
F_72 ( V_87 -> V_138 / 256 ) ) ;
F_71 ( struct V_199 , V_59 , V_196 , 1 ) ;
F_71 ( struct V_199 , V_201 ,
V_196 , 1 ) ;
F_71 ( struct V_199 , V_202 ,
V_196 , V_153 -> V_11 ) ;
F_71 ( struct V_199 , V_203 , V_196 , 1 ) ;
} else {
F_71 ( struct V_204 , V_205 , V_196 ,
V_194 ) ;
F_71 ( struct V_204 , V_200 ,
V_196 , V_193 ) ;
F_71 ( struct V_204 , V_164 , V_196 ,
F_72 ( V_87 -> V_138 / 256 ) ) ;
F_71 ( struct V_204 , V_59 , V_196 , 1 ) ;
F_71 ( struct V_204 , V_206 ,
V_196 , V_192 ) ;
F_71 ( struct V_204 , V_201 , V_196 , 1 ) ;
F_71 ( struct V_204 , V_202 , V_196 , V_153 -> V_11 ) ;
F_71 ( struct V_204 , V_203 , V_196 , 1 ) ;
}
F_54 ( V_196 , sizeof( V_156 -> V_163 ) ) ;
F_55 ( V_156 -> V_142 , F_73 ( V_156 -> V_142 ) , V_157 ) ;
V_22 = F_45 ( V_5 ) ;
if ( ! V_22 ) {
struct V_207 * V_40 = F_1 ( V_2 ) ;
V_87 -> V_11 = F_22 ( V_40 -> V_208 ) ;
V_87 -> V_168 = true ;
}
F_67 ( & V_5 -> V_152 ) ;
return V_22 ;
}
static T_1 F_78 ( int V_209 )
{
T_1 V_210 = F_79 ( V_209 ) ;
if ( V_210 == 16 )
V_210 = 0 ;
return V_210 ;
}
int F_80 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_87 )
{
struct V_1 * V_2 ;
struct V_211 * V_156 ;
struct V_102 * V_157 = & V_7 -> V_158 ;
void * V_196 ;
int V_22 ;
if ( F_66 ( & V_5 -> V_152 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
V_156 = F_1 ( V_2 ) ;
V_196 = & V_156 -> V_163 ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_212 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_161 = F_70 ( F_57 ( V_157 -> V_106 , V_157 -> V_139 ) ) ;
if ( F_48 ( V_5 ) ) {
V_156 -> V_159 . V_131 = 1 ;
V_156 -> V_208 = F_70 ( V_87 -> V_11 ) ;
F_71 ( struct V_213 , V_214 , V_196 ,
F_78 ( V_7 -> V_138 ) ) ;
F_71 ( struct V_213 , V_59 , V_196 , 1 ) ;
F_71 ( struct V_213 , V_215 ,
V_196 , V_87 -> V_11 ) ;
F_71 ( struct V_213 , V_216 ,
V_196 , 1 ) ;
} else {
F_71 ( struct V_217 , V_59 , V_196 , 1 ) ;
F_71 ( struct V_217 , V_214 , V_196 ,
F_78 ( V_7 -> V_138 ) ) ;
F_71 ( struct V_217 , V_208 , V_196 , V_87 -> V_11 ) ;
}
V_156 -> V_218 [ 0 ] = F_53 ( 0x00000022 ) ;
F_54 ( V_196 , sizeof( V_156 -> V_163 ) ) ;
F_55 ( V_156 -> V_142 , F_73 ( V_156 -> V_142 ) , V_157 ) ;
V_22 = F_45 ( V_5 ) ;
if ( ! V_22 ) {
struct V_219 * V_40 = F_1 ( V_2 ) ;
V_7 -> V_11 = F_22 ( V_40 -> V_11 ) ;
V_7 -> V_168 = true ;
}
F_67 ( & V_5 -> V_152 ) ;
return V_22 ;
}
int F_81 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_87 )
{
struct V_1 * V_2 ;
struct V_220 * V_156 ;
struct V_102 * V_157 = & V_7 -> V_158 ;
void * V_196 ;
int V_22 ;
if ( F_66 ( & V_5 -> V_152 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
V_156 = F_1 ( V_2 ) ;
V_196 = & V_156 -> V_163 ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_221 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_161 = F_70 ( F_57 ( V_157 -> V_106 , V_157 -> V_139 ) ) ;
F_71 ( struct V_217 , V_59 , V_196 , 1 ) ;
F_71 ( struct V_217 , V_214 , V_196 ,
F_78 ( V_7 -> V_138 ) ) ;
F_71 ( struct V_217 , V_208 , V_196 , V_87 -> V_11 ) ;
F_54 ( V_196 , sizeof( V_156 -> V_163 ) ) ;
F_55 ( V_156 -> V_142 , F_73 ( V_156 -> V_142 ) , V_157 ) ;
V_22 = F_45 ( V_5 ) ;
if ( ! V_22 ) {
struct V_219 * V_40 = F_1 ( V_2 ) ;
V_7 -> V_11 = F_22 ( V_40 -> V_11 ) ;
V_7 -> V_168 = true ;
}
F_67 ( & V_5 -> V_152 ) ;
return V_22 ;
}
int F_82 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_87 )
{
int V_22 ;
V_22 = F_80 ( V_5 , V_7 , V_87 ) ;
if ( V_22 && ! F_48 ( V_5 ) ) {
F_15 ( & V_5 -> V_49 -> V_50 , L_12
L_13
L_14 ) ;
V_22 = F_81 ( V_5 , V_7 , V_87 ) ;
}
return V_22 ;
}
int F_83 ( struct V_4 * V_5 ,
struct V_6 * V_222 ,
struct V_6 * V_87 )
{
struct V_1 * V_2 ;
struct V_223 * V_156 ;
struct V_102 * V_157 = & V_222 -> V_158 ;
void * V_196 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
V_196 = & V_156 -> V_163 ;
F_52 ( & V_156 -> V_159 , V_35 ,
V_224 , sizeof( * V_156 ) , V_2 , NULL ) ;
if ( F_48 ( V_5 ) ) {
V_156 -> V_159 . V_131 = 1 ;
F_71 ( struct V_225 , V_178 , V_196 ,
V_5 -> V_171 ) ;
}
V_156 -> V_161 = F_57 ( V_157 -> V_106 , V_157 -> V_139 ) ;
V_156 -> V_226 = V_227 ;
V_156 -> type = V_228 ;
F_71 ( struct V_225 , V_229 , V_196 ,
F_78 ( V_222 -> V_138 ) ) ;
F_71 ( struct V_225 , V_230 , V_196 , 1 ) ;
F_71 ( struct V_225 , V_231 , V_196 , V_87 -> V_11 ) ;
F_54 ( V_196 , sizeof( V_156 -> V_163 ) ) ;
F_55 ( V_156 -> V_142 , F_73 ( V_156 -> V_142 ) , V_157 ) ;
V_22 = F_40 ( V_5 ) ;
if ( ! V_22 ) {
struct V_232 * V_40 = F_1 ( V_2 ) ;
V_222 -> V_11 = F_22 ( V_40 -> V_233 ) ;
V_222 -> V_168 = true ;
}
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_84 ( struct V_4 * V_5 ,
struct V_6 * V_234 , T_2 V_208 , T_2 V_235 ,
T_2 V_236 , T_1 V_178 , T_1 V_237 , T_3 * V_238 )
{
struct V_1 * V_2 ;
struct V_239 * V_156 ;
struct V_102 * V_157 = & V_234 -> V_158 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_35 ,
V_240 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_208 = F_70 ( V_208 ) ;
V_156 -> V_235 = F_79 ( V_235 ) - 1 ;
V_156 -> V_161 = 2 ;
F_55 ( V_156 -> V_142 , F_73 ( V_156 -> V_142 ) , V_157 ) ;
V_156 -> V_241 = F_53 ( V_178 ) ;
V_156 -> V_236 = F_70 ( V_236 ) ;
V_156 -> V_242 = F_53 ( V_237 ) ;
V_22 = F_40 ( V_5 ) ;
if ( ! V_22 ) {
struct V_243 * V_40 = F_1 ( V_2 ) ;
V_234 -> V_11 = F_22 ( V_40 -> V_11 ) ;
V_234 -> V_168 = true ;
* V_238 = V_40 -> V_238 ;
}
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_85 ( struct V_4 * V_5 , struct V_6 * V_9 ,
int V_244 )
{
struct V_1 * V_2 ;
struct V_245 * V_156 ;
T_3 V_246 = 0 , V_126 = 0 ;
int V_22 ;
if ( F_66 ( & V_5 -> V_152 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
V_156 = F_1 ( V_2 ) ;
switch ( V_244 ) {
case V_247 :
V_246 = V_29 ;
V_126 = V_248 ;
break;
case V_249 :
V_246 = V_29 ;
V_126 = V_250 ;
break;
case V_251 :
V_246 = V_35 ;
V_126 = V_252 ;
break;
case V_253 :
V_246 = V_35 ;
V_126 = V_254 ;
break;
case V_255 :
V_246 = V_29 ;
V_126 = V_256 ;
break;
default:
F_86 () ;
}
F_52 ( & V_156 -> V_159 , V_246 , V_126 , sizeof( * V_156 ) , V_2 ,
NULL ) ;
V_156 -> V_11 = F_70 ( V_9 -> V_11 ) ;
V_22 = F_45 ( V_5 ) ;
if ( ! V_22 )
V_9 -> V_168 = false ;
F_67 ( & V_5 -> V_152 ) ;
return V_22 ;
}
int F_87 ( struct V_4 * V_5 , struct V_6 * V_9 )
{
struct V_1 * V_2 ;
struct V_245 * V_156 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_35 ,
V_254 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_11 = F_70 ( V_9 -> V_11 ) ;
V_22 = F_40 ( V_5 ) ;
if ( ! V_22 )
V_9 -> V_168 = false ;
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_88 ( struct V_4 * V_5 , T_1 V_257 , T_1 V_258 ,
T_3 * V_180 , T_1 * V_171 , T_1 * V_172 , T_1 V_183 )
{
struct V_1 * V_2 ;
struct V_259 * V_156 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_260 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_159 . V_183 = V_183 ;
V_156 -> V_261 = F_53 ( V_257 ) ;
V_156 -> V_262 = F_53 ( V_258 ) ;
if ( V_180 )
memcpy ( V_156 -> V_169 , V_180 , V_182 ) ;
else
V_156 -> V_263 = true ;
V_22 = F_40 ( V_5 ) ;
if ( ! V_22 ) {
struct V_264 * V_40 = F_1 ( V_2 ) ;
* V_171 = F_7 ( V_40 -> V_241 ) ;
if ( V_180 )
* V_172 = F_7 ( V_40 -> V_172 ) ;
}
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_89 ( struct V_4 * V_5 , int V_241 , T_1 V_183 )
{
struct V_1 * V_2 ;
struct V_265 * V_156 ;
int V_22 ;
if ( V_241 == - 1 )
return 0 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_266 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_159 . V_183 = V_183 ;
V_156 -> V_241 = F_53 ( V_241 ) ;
V_22 = F_40 ( V_5 ) ;
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_90 ( struct V_4 * V_5 , struct V_102 * V_267 )
{
struct V_1 * V_2 ;
struct V_123 * V_159 ;
int V_22 = 0 ;
if ( F_91 ( V_5 -> V_268 , V_44 ) == 0 )
F_92 ( V_5 ) ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_159 = V_267 -> V_106 ;
F_52 ( V_159 , V_35 ,
V_33 , V_267 -> V_139 , V_2 , V_267 ) ;
if ( V_5 -> V_269 == V_270 )
V_159 -> V_131 = 1 ;
F_2 ( V_5 ) ;
V_5 -> V_36 = true ;
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_93 ( struct V_4 * V_5 ,
struct V_102 * V_267 )
{
struct V_1 * V_2 ;
struct V_271 * V_156 ;
int V_22 = 0 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = V_267 -> V_106 ;
F_52 ( & V_156 -> V_159 , V_35 ,
V_34 , V_267 -> V_139 , V_2 ,
V_267 ) ;
V_156 -> V_272 . V_273 . V_274 = F_70 ( V_5 -> V_68 ) ;
V_156 -> V_272 . V_273 . V_275 = 0 ;
F_2 ( V_5 ) ;
V_5 -> V_36 = true ;
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_94 ( struct V_4 * V_5 , T_3 * V_276 ,
T_2 * V_55 , T_3 * V_277 , T_1 V_189 )
{
struct V_1 * V_2 ;
struct V_278 * V_156 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
if ( V_277 )
* V_277 = V_279 ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
if ( V_5 -> V_269 == V_270 || F_48 ( V_5 ) )
V_156 -> V_159 . V_131 = 1 ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_280 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_22 = F_40 ( V_5 ) ;
if ( ! V_22 ) {
struct V_281 * V_40 = F_1 ( V_2 ) ;
if ( V_40 -> V_276 != V_282 ) {
if ( V_55 )
* V_55 = F_22 ( V_40 -> V_55 ) ;
if ( V_276 )
* V_276 = V_40 -> V_276 ;
}
if ( V_277 )
* V_277 = V_40 -> V_283 ;
}
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_92 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_284 * V_156 ;
T_2 V_285 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_285 = V_5 -> V_8 . V_9 . V_286 ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_37 , sizeof( * V_156 ) ,
V_2 , NULL ) ;
V_2 -> V_28 = V_285 ;
F_2 ( V_5 ) ;
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_95 ( struct V_4 * V_5 , T_1 * V_287 )
{
struct V_1 * V_2 ;
struct V_288 * V_156 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_289 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_290 = F_53 ( V_291 ) ;
V_22 = F_40 ( V_5 ) ;
if ( ! V_22 ) {
struct V_292 * V_40 = F_1 ( V_2 ) ;
if ( V_287 && V_40 -> V_287 )
* V_287 = F_7 ( V_40 -> V_287 ) -
sizeof( T_1 ) ;
}
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
void F_96 ( struct V_4 * V_5 , T_1 V_293 , void * V_294 )
{
struct V_102 V_295 ;
struct V_1 * V_2 ;
struct V_288 * V_156 ;
T_1 V_296 = 0 , V_297 , V_298 ,
V_299 = sizeof( T_1 ) , V_300 ;
int V_22 ;
if ( V_293 == 0 )
return;
V_297 = V_293 ;
V_295 . V_139 = sizeof( struct V_288 ) + 60 * 1024 ;
V_295 . V_106 = F_97 ( V_5 -> V_49 ,
V_295 . V_139 ,
& V_295 . V_108 ) ;
if ( ! V_295 . V_106 ) {
V_22 = - V_301 ;
F_16 ( & V_5 -> V_49 -> V_50 ,
L_15 ) ;
return;
}
F_30 ( & V_5 -> V_174 ) ;
while ( V_297 ) {
V_298 = F_56 ( V_297 , ( T_1 ) 60 * 1024 ) ;
V_297 -= V_298 ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = V_295 . V_106 ;
V_300 = sizeof( struct V_288 ) + V_298 ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_289 , V_300 , V_2 ,
& V_295 ) ;
V_156 -> V_290 = F_53 ( V_302 ) ;
V_156 -> V_303 = F_53 ( V_299 ) ;
V_156 -> V_304 = F_53 ( V_298 ) ;
V_156 -> V_305 = F_53 ( V_298 ) ;
V_22 = F_40 ( V_5 ) ;
if ( ! V_22 ) {
struct V_292 * V_40 = V_295 . V_106 ;
memcpy ( V_294 + V_296 ,
V_40 -> V_306 ,
F_7 ( V_40 -> V_304 ) ) ;
} else {
F_16 ( & V_5 -> V_49 -> V_50 , L_16 ) ;
goto V_176;
}
V_296 += V_298 ;
V_299 += V_298 ;
}
V_176:
F_98 ( V_5 -> V_49 , V_295 . V_139 ,
V_295 . V_106 ,
V_295 . V_108 ) ;
F_32 ( & V_5 -> V_174 ) ;
}
int F_99 ( struct V_4 * V_5 , char * V_307 ,
char * V_308 )
{
struct V_1 * V_2 ;
struct V_309 * V_156 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_310 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_22 = F_40 ( V_5 ) ;
if ( ! V_22 ) {
struct V_311 * V_40 = F_1 ( V_2 ) ;
strcpy ( V_307 , V_40 -> V_312 ) ;
if ( V_308 )
strcpy ( V_308 , V_40 -> V_313 ) ;
}
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_100 ( struct V_4 * V_5 , T_1 V_167 , T_1 V_314 )
{
struct V_1 * V_2 ;
struct V_315 * V_156 ;
int V_22 = 0 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_316 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_317 = F_53 ( 1 ) ;
V_156 -> V_318 [ 0 ] . V_167 = F_53 ( V_167 ) ;
V_156 -> V_318 [ 0 ] . V_319 = 0 ;
V_156 -> V_318 [ 0 ] . V_320 = F_53 ( V_314 ) ;
F_2 ( V_5 ) ;
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_101 ( struct V_4 * V_5 , T_1 V_178 , T_2 * V_321 ,
T_1 V_90 , bool V_322 , bool V_323 )
{
struct V_1 * V_2 ;
struct V_324 * V_156 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_325 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_241 = V_178 ;
V_156 -> V_323 = V_323 ;
V_156 -> V_322 = V_322 ;
V_156 -> V_326 = V_90 ;
if ( ! V_323 ) {
memcpy ( V_156 -> V_327 , V_321 ,
V_156 -> V_326 * sizeof( V_321 [ 0 ] ) ) ;
}
V_22 = F_40 ( V_5 ) ;
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_102 ( struct V_4 * V_5 , T_1 V_18 , T_1 V_328 )
{
struct V_1 * V_2 ;
struct V_102 * V_128 = & V_5 -> V_329 ;
struct V_330 * V_156 = V_128 -> V_106 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
memset ( V_156 , 0 , sizeof( * V_156 ) ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_331 , sizeof( * V_156 ) ,
V_2 , V_128 ) ;
V_156 -> V_178 = F_53 ( V_5 -> V_171 ) ;
if ( V_18 & V_332 ) {
V_156 -> V_333 = F_53 ( V_334 |
V_335 ) ;
if ( V_328 == V_336 )
V_156 -> V_337 = F_53 ( V_334 |
V_335 ) ;
} else if ( V_18 & V_338 ) {
V_156 -> V_333 = V_156 -> V_337 =
F_53 ( V_339 ) ;
} else {
struct V_340 * V_341 ;
int V_95 = 0 ;
V_156 -> V_333 = V_156 -> V_337 =
F_53 ( V_342 ) ;
V_156 -> V_333 |=
F_53 ( V_339 ) ;
V_156 -> V_343 = F_53 ( F_103 ( V_5 -> V_344 ) ) ;
F_104 (ha, adapter->netdev)
memcpy ( V_156 -> V_345 [ V_95 ++ ] . V_346 , V_341 -> V_181 , V_182 ) ;
}
V_22 = F_40 ( V_5 ) ;
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_105 ( struct V_4 * V_5 , T_1 V_347 , T_1 V_348 )
{
struct V_1 * V_2 ;
struct V_349 * V_156 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_350 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_351 = F_70 ( ( T_2 ) V_347 ) ;
V_156 -> V_352 = F_70 ( ( T_2 ) V_348 ) ;
V_22 = F_40 ( V_5 ) ;
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_106 ( struct V_4 * V_5 , T_1 * V_347 , T_1 * V_348 )
{
struct V_1 * V_2 ;
struct V_353 * V_156 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_354 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_22 = F_40 ( V_5 ) ;
if ( ! V_22 ) {
struct V_355 * V_40 =
F_1 ( V_2 ) ;
* V_347 = F_22 ( V_40 -> V_351 ) ;
* V_348 = F_22 ( V_40 -> V_352 ) ;
}
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_107 ( struct V_4 * V_5 , T_1 * V_68 ,
T_1 * V_356 , T_1 * V_357 )
{
struct V_1 * V_2 ;
struct V_358 * V_156 ;
int V_22 ;
if ( F_66 ( & V_5 -> V_152 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_359 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_22 = F_45 ( V_5 ) ;
if ( ! V_22 ) {
struct V_360 * V_40 = F_1 ( V_2 ) ;
* V_68 = F_7 ( V_40 -> V_361 ) ;
* V_356 = F_7 ( V_40 -> V_362 ) ;
* V_357 = F_7 ( V_40 -> V_363 ) ;
}
F_67 ( & V_5 -> V_152 ) ;
return V_22 ;
}
int F_108 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_123 * V_156 ;
int V_22 ;
if ( F_66 ( & V_5 -> V_152 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
V_156 = F_1 ( V_2 ) ;
F_52 ( V_156 , V_29 ,
V_364 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_22 = F_45 ( V_5 ) ;
F_67 ( & V_5 -> V_152 ) ;
return V_22 ;
}
int F_109 ( struct V_4 * V_5 , T_3 * V_365 , T_2 V_366 )
{
struct V_1 * V_2 ;
struct V_367 * V_156 ;
T_1 V_368 [ 10 ] = { 0x15d43fa5 , 0x2534685a , 0x5f87693a , 0x5668494e ,
0x33cf6a53 , 0x383334c6 , 0x76ac4257 , 0x59b242b2 ,
0x3ea83c02 , 0x4a110304 } ;
int V_22 ;
if ( F_66 ( & V_5 -> V_152 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_35 ,
V_369 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_178 = F_53 ( V_5 -> V_171 ) ;
V_156 -> V_370 = F_70 ( V_371 | V_372 ) ;
V_156 -> V_373 = F_70 ( F_79 ( V_366 ) - 1 ) ;
memcpy ( V_156 -> V_374 , V_365 , V_366 ) ;
memcpy ( V_156 -> V_375 , V_368 , sizeof( V_368 ) ) ;
F_54 ( V_156 -> V_375 , sizeof( V_156 -> V_375 ) ) ;
V_22 = F_45 ( V_5 ) ;
F_67 ( & V_5 -> V_152 ) ;
return V_22 ;
}
int F_110 ( struct V_4 * V_5 , T_3 V_68 ,
T_3 V_376 , T_3 V_377 , T_3 V_378 )
{
struct V_1 * V_2 ;
struct V_379 * V_156 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_380 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_68 = V_68 ;
V_156 -> V_381 = V_378 ;
V_156 -> V_382 = V_376 ;
V_156 -> V_383 = V_377 ;
V_22 = F_40 ( V_5 ) ;
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_111 ( struct V_4 * V_5 , T_3 V_68 , T_1 * V_378 )
{
struct V_1 * V_2 ;
struct V_384 * V_156 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_385 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_68 = V_68 ;
V_22 = F_40 ( V_5 ) ;
if ( ! V_22 ) {
struct V_386 * V_40 =
F_1 ( V_2 ) ;
* V_378 = V_40 -> V_381 ;
}
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_112 ( struct V_4 * V_5 , struct V_102 * V_387 ,
T_1 V_388 , T_1 V_389 , const char * V_390 ,
T_1 * V_391 , T_3 * V_392 )
{
struct V_1 * V_2 ;
struct V_393 * V_156 ;
struct V_394 * V_40 ;
void * V_196 = NULL ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_5 -> V_30 = 0 ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_395;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_27 ,
sizeof( struct V_393 ) , V_2 ,
NULL ) ;
V_196 = & V_156 -> V_163 ;
F_71 ( struct V_396 ,
V_397 , V_196 , V_388 ) ;
if ( V_388 == 0 )
F_71 ( struct V_396 ,
V_398 , V_196 , 1 ) ;
else
F_71 ( struct V_396 ,
V_398 , V_196 , 0 ) ;
F_54 ( V_196 , sizeof( V_156 -> V_163 ) ) ;
V_156 -> V_399 = F_53 ( V_389 ) ;
strcpy ( V_156 -> V_400 , V_390 ) ;
V_156 -> V_401 = F_53 ( 1 ) ;
V_156 -> V_293 = F_53 ( V_388 ) ;
V_156 -> V_402 = F_53 ( ( V_387 -> V_108 +
sizeof( struct V_393 ) )
& 0xFFFFFFFF ) ;
V_156 -> V_403 = F_53 ( F_46 ( V_387 -> V_108 +
sizeof( struct V_393 ) ) ) ;
F_2 ( V_5 ) ;
F_32 ( & V_5 -> V_174 ) ;
if ( ! F_113 ( & V_5 -> V_31 ,
F_114 ( 12000 ) ) )
V_22 = - 1 ;
else
V_22 = V_5 -> V_30 ;
V_40 = F_1 ( V_2 ) ;
if ( ! V_22 ) {
* V_391 = F_7 ( V_40 -> V_404 ) ;
} else {
* V_392 = V_40 -> V_405 ;
V_22 = V_40 -> V_22 ;
}
return V_22 ;
V_395:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_115 ( struct V_4 * V_5 , struct V_102 * V_387 ,
T_1 V_388 , T_1 V_389 , const char * V_390 ,
T_1 * V_406 , T_1 * V_398 , T_3 * V_392 )
{
struct V_1 * V_2 ;
struct V_407 * V_156 ;
struct V_408 * V_40 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_395;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_409 ,
sizeof( struct V_407 ) , V_2 ,
NULL ) ;
V_156 -> V_410 = F_53 ( V_388 ) ;
V_156 -> V_411 = F_53 ( V_389 ) ;
strcpy ( V_156 -> V_400 , V_390 ) ;
V_156 -> V_401 = F_53 ( 1 ) ;
V_156 -> V_293 = F_53 ( V_388 ) ;
V_156 -> V_402 = F_53 ( ( V_387 -> V_108 & 0xFFFFFFFF ) ) ;
V_156 -> V_403 = F_53 ( F_46 ( V_387 -> V_108 ) ) ;
V_22 = F_40 ( V_5 ) ;
V_40 = F_1 ( V_2 ) ;
if ( ! V_22 ) {
* V_406 = F_7 ( V_40 -> V_412 ) ;
* V_398 = F_7 ( V_40 -> V_398 ) ;
} else {
* V_392 = V_40 -> V_405 ;
}
V_395:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_116 ( struct V_4 * V_5 , struct V_102 * V_387 ,
T_1 V_413 , T_1 V_414 , T_1 V_298 )
{
struct V_1 * V_2 ;
struct F_116 * V_156 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_5 -> V_30 = 0 ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_395;
}
V_156 = V_387 -> V_106 ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_26 , V_387 -> V_139 , V_2 , V_387 ) ;
V_156 -> V_273 . V_415 = F_53 ( V_413 ) ;
V_156 -> V_273 . V_416 = F_53 ( V_414 ) ;
V_156 -> V_273 . V_417 = F_53 ( V_298 ) ;
F_2 ( V_5 ) ;
F_32 ( & V_5 -> V_174 ) ;
if ( ! F_113 ( & V_5 -> V_31 ,
F_114 ( 40000 ) ) )
V_22 = - 1 ;
else
V_22 = V_5 -> V_30 ;
return V_22 ;
V_395:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_117 ( struct V_4 * V_5 , T_3 * V_418 ,
int V_296 )
{
struct V_1 * V_2 ;
struct F_116 * V_156 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_419 , sizeof( * V_156 ) + 4 , V_2 , NULL ) ;
V_156 -> V_273 . V_415 = F_53 ( V_420 ) ;
V_156 -> V_273 . V_416 = F_53 ( V_421 ) ;
V_156 -> V_273 . V_296 = F_53 ( V_296 ) ;
V_156 -> V_273 . V_417 = F_53 ( 0x4 ) ;
V_22 = F_40 ( V_5 ) ;
if ( ! V_22 )
memcpy ( V_418 , V_156 -> V_273 . V_422 , 4 ) ;
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_118 ( struct V_4 * V_5 , T_3 * V_180 ,
struct V_102 * V_267 )
{
struct V_1 * V_2 ;
struct V_423 * V_156 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = V_267 -> V_106 ;
F_52 ( & V_156 -> V_159 , V_35 ,
V_424 , sizeof( * V_156 ) , V_2 ,
V_267 ) ;
memcpy ( V_156 -> V_425 , V_180 , V_182 ) ;
V_22 = F_40 ( V_5 ) ;
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_119 ( struct V_4 * V_5 , T_3 V_68 ,
T_3 V_426 , T_3 V_427 )
{
struct V_1 * V_2 ;
struct V_428 * V_156 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_429 ,
V_430 , sizeof( * V_156 ) , V_2 ,
NULL ) ;
V_156 -> V_431 = V_68 ;
V_156 -> V_432 = V_68 ;
V_156 -> V_426 = V_426 ;
V_156 -> V_433 = V_427 ;
V_22 = F_40 ( V_5 ) ;
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_120 ( struct V_4 * V_5 , T_1 V_68 ,
T_1 V_426 , T_1 V_434 , T_1 V_435 , T_5 V_436 )
{
struct V_1 * V_2 ;
struct V_437 * V_156 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_429 ,
V_438 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_159 . V_117 = F_53 ( 4 ) ;
V_156 -> V_436 = F_121 ( V_436 ) ;
V_156 -> V_431 = F_53 ( V_68 ) ;
V_156 -> V_432 = F_53 ( V_68 ) ;
V_156 -> V_434 = F_53 ( V_434 ) ;
V_156 -> V_435 = F_53 ( V_435 ) ;
V_156 -> V_426 = F_53 ( V_426 ) ;
V_22 = F_40 ( V_5 ) ;
if ( ! V_22 ) {
struct V_439 * V_40 = F_1 ( V_2 ) ;
V_22 = F_7 ( V_40 -> V_22 ) ;
}
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_122 ( struct V_4 * V_5 , T_5 V_436 ,
T_1 V_440 , struct V_102 * V_387 )
{
struct V_1 * V_2 ;
struct V_441 * V_156 ;
int V_22 ;
int V_95 , V_442 = 0 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = V_387 -> V_106 ;
F_52 ( & V_156 -> V_159 , V_429 ,
V_443 , V_387 -> V_139 , V_2 , V_387 ) ;
V_156 -> V_436 = F_121 ( V_436 ) ;
V_156 -> V_444 = F_53 ( V_440 ) ;
for ( V_95 = 0 ; V_95 < V_440 ; V_95 ++ ) {
V_156 -> V_445 [ V_95 ] = ( T_3 ) ( V_436 >> ( V_442 * 8 ) ) ;
V_442 ++ ;
if ( V_442 > 7 )
V_442 = 0 ;
}
V_22 = F_40 ( V_5 ) ;
if ( ! V_22 ) {
struct V_446 * V_40 ;
V_40 = V_387 -> V_106 ;
if ( ( memcmp ( V_40 -> V_447 , V_156 -> V_445 , V_440 ) != 0 ) ||
V_40 -> V_448 ) {
V_22 = - 1 ;
}
}
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_123 ( struct V_4 * V_5 ,
struct V_102 * V_267 )
{
struct V_1 * V_2 ;
struct V_449 * V_156 ;
struct V_121 * V_129 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = V_267 -> V_106 ;
V_129 = F_51 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_450 , sizeof( * V_156 ) , V_2 ,
V_267 ) ;
V_22 = F_40 ( V_5 ) ;
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_124 ( struct V_4 * V_5 ,
struct V_451 * V_452 )
{
struct V_1 * V_2 ;
struct V_453 * V_156 ;
struct V_102 V_387 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_387 . V_139 = sizeof( struct V_453 ) ;
V_387 . V_106 = F_97 ( V_5 -> V_49 , V_387 . V_139 ,
& V_387 . V_108 ) ;
if ( ! V_387 . V_106 ) {
F_16 ( & V_5 -> V_49 -> V_50 , L_17 ) ;
V_22 = - V_301 ;
goto V_176;
}
V_156 = V_387 . V_106 ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_454 , sizeof( * V_156 ) ,
V_2 , & V_387 ) ;
V_22 = F_40 ( V_5 ) ;
if ( ! V_22 ) {
struct V_451 * V_455 =
V_387 . V_106 + sizeof( struct V_123 ) ;
V_452 -> V_456 = F_22 ( V_455 -> V_456 ) ;
V_452 -> V_457 =
F_22 ( V_455 -> V_457 ) ;
}
F_98 ( V_5 -> V_49 , V_387 . V_139 ,
V_387 . V_106 , V_387 . V_108 ) ;
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_125 ( struct V_4 * V_5 , T_1 V_458 , T_1 V_183 )
{
struct V_1 * V_2 ;
struct V_459 * V_156 ;
int V_22 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_460 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_159 . V_183 = V_183 ;
V_156 -> V_461 = F_53 ( V_462 ) ;
V_156 -> V_463 = F_53 ( V_458 ) ;
V_22 = F_40 ( V_5 ) ;
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_126 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_464 * V_156 ;
struct V_465 * V_40 ;
int V_22 ;
int V_300 = F_127 ( sizeof( * V_156 ) , sizeof( * V_40 ) ) ;
struct V_466 * V_467 ;
struct V_102 V_468 ;
memset ( & V_468 , 0 , sizeof( struct V_102 ) ) ;
V_468 . V_139 = sizeof( struct V_465 ) ;
V_468 . V_106 = F_97 ( V_5 -> V_49 , V_468 . V_139 ,
& V_468 . V_108 ) ;
if ( ! V_468 . V_106 ) {
F_16 ( & V_5 -> V_49 -> V_50 ,
L_18 ) ;
return - V_301 ;
}
if ( F_66 ( & V_5 -> V_152 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = V_468 . V_106 ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_469 , V_300 , V_2 ,
& V_468 ) ;
V_22 = F_45 ( V_5 ) ;
if ( ! V_22 ) {
V_467 = V_468 . V_106 + sizeof( struct V_470 ) ;
V_5 -> V_471 = V_467 -> V_472 . V_473 ;
}
V_176:
F_67 ( & V_5 -> V_152 ) ;
F_98 ( V_5 -> V_49 , V_468 . V_139 , V_468 . V_106 ,
V_468 . V_108 ) ;
return V_22 ;
}
int F_128 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_474 * V_156 ;
int V_22 ;
if ( F_66 ( & V_5 -> V_152 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_475 , sizeof( * V_156 ) , V_2 , NULL ) ;
V_156 -> V_476 = F_53 ( V_477 |
V_478 ) ;
V_156 -> V_257 = F_53 ( V_478 ) ;
V_22 = F_45 ( V_5 ) ;
if ( ! V_22 ) {
struct V_479 * V_40 = F_1 ( V_2 ) ;
V_5 -> V_480 = F_7 ( V_40 -> V_257 ) &
V_478 ;
}
V_176:
F_67 ( & V_5 -> V_152 ) ;
return V_22 ;
}
int F_129 ( struct V_4 * V_5 , T_1 V_183 ,
T_1 * V_172 )
{
struct V_1 * V_2 ;
struct V_481 * V_156 ;
int V_22 ;
int V_482 ;
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = F_1 ( V_2 ) ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_483 , sizeof( * V_156 ) ,
V_2 , NULL ) ;
V_156 -> V_159 . V_183 = V_183 ;
V_22 = F_40 ( V_5 ) ;
if ( ! V_22 ) {
struct V_484 * V_40 =
F_1 ( V_2 ) ;
int V_95 ;
T_3 * V_196 = & V_40 -> V_163 [ 0 ] [ 0 ] ;
V_22 = - V_96 ;
V_482 = V_40 -> V_482 ;
F_11 ( & V_40 -> V_163 , sizeof( V_40 -> V_163 ) ) ;
for ( V_95 = 0 ; V_95 < V_482 ; V_95 ++ ) {
if ( ! F_130 ( struct V_485 ,
V_486 , V_196 ) ) {
* V_172 = F_130
( struct V_485 ,
V_487 , V_196 ) ;
V_22 = 0 ;
break;
}
V_196 += sizeof( struct V_485 ) / 8 ;
}
}
V_176:
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
int F_131 ( struct V_4 * V_5 , T_3 * V_488 ,
T_3 V_482 , T_1 V_183 )
{
struct V_1 * V_2 ;
struct V_489 * V_156 ;
int V_22 ;
struct V_102 V_387 ;
memset ( & V_387 , 0 , sizeof( struct V_102 ) ) ;
V_387 . V_139 = sizeof( struct V_489 ) ;
V_387 . V_106 = F_132 ( & V_5 -> V_49 -> V_50 , V_387 . V_139 ,
& V_387 . V_108 , V_490 ) ;
if ( ! V_387 . V_106 ) {
F_16 ( & V_5 -> V_49 -> V_50 , L_17 ) ;
return - V_301 ;
}
F_30 ( & V_5 -> V_174 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_22 = - V_175 ;
goto V_176;
}
V_156 = V_387 . V_106 ;
F_52 ( & V_156 -> V_159 , V_29 ,
V_491 , sizeof( * V_156 ) ,
V_2 , & V_387 ) ;
V_156 -> V_159 . V_183 = V_183 ;
V_156 -> V_482 = V_482 ;
if ( V_482 )
memcpy ( V_156 -> V_180 , V_488 , V_182 * V_482 ) ;
V_22 = F_40 ( V_5 ) ;
V_176:
F_133 ( & V_5 -> V_49 -> V_50 , V_387 . V_139 ,
V_387 . V_106 , V_387 . V_108 ) ;
F_32 ( & V_5 -> V_174 ) ;
return V_22 ;
}
