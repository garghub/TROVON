static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 ;
T_1 V_7 = 0 ;
if ( V_2 -> V_8 ) {
F_2 ( & V_2 -> V_9 -> V_10 ,
L_1 ) ;
return;
}
V_7 |= V_4 -> V_11 & V_12 ;
V_7 |= 1 << V_13 ;
F_3 () ;
F_4 ( V_7 , V_2 -> V_14 + V_15 ) ;
}
static inline bool F_5 ( struct V_16 * V_17 )
{
if ( V_17 -> V_18 != 0 ) {
V_17 -> V_18 = F_6 ( V_17 -> V_18 ) ;
F_7 ( ( V_17 -> V_18 & V_19 ) == 0 ) ;
return true ;
} else {
return false ;
}
}
static inline void F_8 ( struct V_16 * V_17 )
{
V_17 -> V_18 = 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
T_2 V_20 , V_21 ;
F_10 ( V_17 , 4 ) ;
V_20 = ( V_17 -> V_22 >> V_23 ) &
V_24 ;
if ( ( ( V_17 -> V_25 == V_26 ) ||
( V_17 -> V_25 == V_27 ) ) &&
( V_17 -> V_28 == V_29 ) ) {
V_2 -> V_30 = V_20 ;
F_11 ( & V_2 -> V_31 ) ;
}
if ( V_20 == V_32 ) {
if ( ( ( V_17 -> V_25 == V_33 ) ||
( V_17 -> V_25 == V_34 ) ) &&
( V_17 -> V_28 == V_35 ) ) {
if ( V_2 -> V_36 == V_37 ) {
if ( F_12 ( V_2 ) ) {
struct V_38
* V_39 = V_2 -> V_40 . V_41 ;
F_10 ( & V_39 -> V_42 ,
sizeof( V_39 -> V_42 ) ) ;
} else {
struct V_43 * V_39 =
V_2 -> V_40 . V_41 ;
F_10 ( & V_39 -> V_44 ,
sizeof( V_39 -> V_44 ) ) ;
}
} else {
struct V_45 * V_39 =
V_2 -> V_40 . V_41 ;
F_10 ( & V_39 -> V_44 ,
sizeof( V_39 -> V_44 ) ) ;
}
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
V_2 -> V_46 = false ;
}
} else {
if ( V_20 == V_47 ||
V_20 == V_48 )
goto V_49;
if ( V_20 == V_50 ) {
F_15 ( & V_2 -> V_9 -> V_10 , L_2
L_3 ,
V_17 -> V_25 ) ;
} else {
V_21 = ( V_17 -> V_22 >> V_51 ) &
V_52 ;
F_16 ( & V_2 -> V_9 -> V_10 , L_4
L_5 ,
V_17 -> V_25 , V_20 , V_21 ) ;
}
}
V_49:
return V_20 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
F_18 ( V_2 ,
V_54 -> V_55 == V_56 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_57 * V_54 )
{
if ( V_54 -> V_58 ) {
V_2 -> V_59 = V_54 -> V_60 ;
V_2 -> V_61 &= ~ V_62 ;
V_2 -> V_61 =
V_54 -> V_63 << V_64 ;
}
}
static void F_20 ( struct V_1 * V_2 ,
struct V_65 * V_54 )
{
if ( V_54 -> V_66 == V_2 -> V_67 ) {
V_2 -> V_68 = V_54 -> V_69 * 10 ;
}
}
static void F_21 ( struct V_1 * V_2 ,
struct V_70 * V_54 )
{
if ( V_54 -> V_71 )
V_2 -> V_72 = F_22 ( V_54 -> V_73 ) ;
else
V_2 -> V_72 = 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
T_1 V_74 , struct V_16 * V_54 )
{
T_3 V_75 = 0 ;
V_75 = ( V_74 >> V_76 ) &
V_77 ;
switch ( V_75 ) {
case V_78 :
F_19 ( V_2 ,
(struct V_57 * ) V_54 ) ;
break;
case V_79 :
F_20 ( V_2 ,
(struct V_65 * ) V_54 ) ;
break;
case V_80 :
F_21 ( V_2 ,
(struct V_70 * ) V_54 ) ;
break;
default:
F_15 ( & V_2 -> V_9 -> V_10 , L_6 ) ;
break;
}
}
static inline bool F_24 ( T_1 V_74 )
{
return ( ( V_74 >> V_81 ) &
V_82 ) ==
V_83 ;
}
static inline bool F_25 ( T_1 V_74 )
{
return ( ( ( V_74 >> V_81 ) &
V_82 ) ==
V_84 ) ;
}
static struct V_16 * F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_85 = & V_2 -> V_5 . V_86 ;
struct V_16 * V_17 = F_27 ( V_85 ) ;
if ( F_5 ( V_17 ) ) {
F_28 ( V_85 ) ;
return V_17 ;
}
return NULL ;
}
void F_29 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_87 ) ;
F_31 ( V_2 , V_2 -> V_5 . V_86 . V_11 , true , 0 ) ;
V_2 -> V_5 . V_88 = true ;
F_32 ( & V_2 -> V_87 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_88 = false ;
}
int F_34 ( struct V_1 * V_2 , int * V_22 )
{
struct V_16 * V_17 ;
int V_89 = 0 ;
struct V_90 * V_5 = & V_2 -> V_5 ;
F_30 ( & V_2 -> V_87 ) ;
while ( ( V_17 = F_26 ( V_2 ) ) ) {
if ( V_17 -> V_18 & V_91 ) {
if ( F_24 ( V_17 -> V_18 ) )
F_17 ( V_2 ,
(struct V_53 * ) V_17 ) ;
else if ( F_25 ( V_17 -> V_18 ) )
F_23 ( V_2 ,
V_17 -> V_18 , V_17 ) ;
} else if ( V_17 -> V_18 & V_92 ) {
* V_22 = F_9 ( V_2 , V_17 ) ;
F_35 ( & V_5 -> V_6 . V_93 ) ;
}
F_8 ( V_17 ) ;
V_89 ++ ;
}
F_32 ( & V_2 -> V_87 ) ;
return V_89 ;
}
static int F_36 ( struct V_1 * V_2 )
{
#define F_37 120000
int V_94 , V_89 , V_22 = 0 ;
struct V_90 * V_5 = & V_2 -> V_5 ;
if ( V_2 -> V_8 )
return - V_95 ;
for ( V_94 = 0 ; V_94 < F_37 ; V_94 ++ ) {
V_89 = F_34 ( V_2 , & V_22 ) ;
if ( V_89 )
F_31 ( V_2 , V_5 -> V_86 . V_11 ,
V_5 -> V_88 , V_89 ) ;
if ( F_38 ( & V_5 -> V_6 . V_93 ) == 0 )
break;
F_39 ( 100 ) ;
}
if ( V_94 == F_37 ) {
F_16 ( & V_2 -> V_9 -> V_10 , L_7 ) ;
return - 1 ;
}
return V_22 ;
}
static int F_40 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return F_36 ( V_2 ) ;
}
static int F_41 ( struct V_1 * V_2 , void T_4 * V_14 )
{
int V_96 = 0 ;
T_1 V_97 ;
if ( V_2 -> V_8 ) {
F_16 ( & V_2 -> V_9 -> V_10 ,
L_8 ) ;
return - V_95 ;
}
do {
V_97 = F_42 ( V_14 ) ;
if ( V_97 == 0xffffffff ) {
F_16 ( & V_2 -> V_9 -> V_10 ,
L_9 ) ;
return - 1 ;
}
V_97 &= V_98 ;
if ( V_97 )
break;
if ( V_96 > 4000 ) {
F_16 ( & V_2 -> V_9 -> V_10 , L_10 ) ;
if ( ! F_12 ( V_2 ) )
F_43 ( V_2 ) ;
return - 1 ;
}
F_44 ( 1 ) ;
V_96 ++ ;
} while ( true );
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_22 ;
T_1 V_7 = 0 ;
void T_4 * V_14 = V_2 -> V_14 + V_99 ;
struct V_100 * V_101 = & V_2 -> V_101 ;
struct V_102 * V_103 = V_101 -> V_41 ;
struct V_16 * V_17 = & V_103 -> V_17 ;
V_22 = F_41 ( V_2 , V_14 ) ;
if ( V_22 != 0 )
return V_22 ;
V_7 |= V_104 ;
V_7 |= ( F_46 ( V_101 -> V_105 ) >> 2 ) << 2 ;
F_4 ( V_7 , V_14 ) ;
V_22 = F_41 ( V_2 , V_14 ) ;
if ( V_22 != 0 )
return V_22 ;
V_7 = 0 ;
V_7 |= ( T_1 ) ( V_101 -> V_105 >> 4 ) << 2 ;
F_4 ( V_7 , V_14 ) ;
V_22 = F_41 ( V_2 , V_14 ) ;
if ( V_22 != 0 )
return V_22 ;
if ( F_5 ( V_17 ) ) {
V_22 = F_9 ( V_2 , & V_103 -> V_17 ) ;
F_8 ( V_17 ) ;
if ( V_22 )
return V_22 ;
} else {
F_16 ( & V_2 -> V_9 -> V_10 , L_11 ) ;
return - 1 ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , T_2 * V_106 )
{
T_1 V_107 ;
if ( F_12 ( V_2 ) )
V_107 = F_42 ( V_2 -> V_14 + V_108 ) ;
else
V_107 = F_42 ( V_2 -> V_109 + V_110 ) ;
* V_106 = V_107 & V_111 ;
if ( ( V_107 >> V_112 ) & V_113 )
return - 1 ;
else
return 0 ;
}
int F_48 ( struct V_1 * V_2 )
{
T_2 V_106 ;
int V_22 , V_114 = 0 ;
struct V_115 * V_10 = & V_2 -> V_9 -> V_10 ;
do {
V_22 = F_47 ( V_2 , & V_106 ) ;
if ( V_22 ) {
F_16 ( V_10 , L_12 , V_106 ) ;
return - 1 ;
} else if ( V_106 != V_116 ) {
if ( F_49 ( 2000 ) ) {
F_16 ( V_10 , L_13 ) ;
return - V_117 ;
}
V_114 += 2 ;
} else {
return 0 ;
}
} while ( V_114 < 40 );
F_16 ( V_10 , L_14 , V_106 ) ;
return - 1 ;
}
static inline void * F_50 ( struct V_118 * V_119 )
{
return V_119 -> V_120 . F_50 ;
}
static inline struct V_121 * F_51 ( struct V_118 * V_119 )
{
return & V_119 -> V_120 . V_122 [ 0 ] ;
}
static void F_52 ( struct V_118 * V_119 , int V_123 ,
bool V_124 , T_3 V_125 , T_1 V_126 )
{
if ( V_124 )
V_119 -> V_124 |= V_127 ;
else
V_119 -> V_124 |= ( V_125 & V_128 ) <<
V_129 ;
V_119 -> V_130 = V_123 ;
V_119 -> V_25 = V_126 ;
F_53 ( V_119 , 8 ) ;
}
static void F_54 ( struct V_131 * V_132 ,
T_3 V_133 , T_3 V_126 , int V_134 )
{
V_132 -> V_126 = V_126 ;
V_132 -> V_133 = V_133 ;
V_132 -> V_135 = F_55 ( V_134 - sizeof( * V_132 ) ) ;
V_132 -> V_136 = 0 ;
}
static void F_56 ( struct V_137 * V_138 , T_1 V_139 ,
struct V_100 * V_140 )
{
int V_94 , V_141 = F_57 ( F_58 ( V_140 -> V_41 , V_140 -> V_142 ) , V_139 ) ;
T_5 V_105 = ( T_5 ) V_140 -> V_105 ;
for ( V_94 = 0 ; V_94 < V_141 ; V_94 ++ ) {
V_138 [ V_94 ] . V_143 = F_55 ( V_105 & 0xFFFFFFFF ) ;
V_138 [ V_94 ] . V_144 = F_55 ( F_46 ( V_105 ) ) ;
V_105 += V_145 ;
}
}
static T_1 F_59 ( T_1 V_146 )
{
#define F_60 651042
const T_1 V_147 = 10 ;
T_1 V_148 ;
if ( V_146 == 0 )
V_148 = 0 ;
else {
T_1 V_149 = 1000000 / V_146 ;
if ( V_149 == 0 )
V_148 = 1023 ;
else {
V_148 = ( F_60 - V_149 ) * V_147 ;
V_148 /= V_149 ;
V_148 = ( V_148 + V_147 / 2 ) / V_147 ;
V_148 = F_57 ( V_148 , ( T_1 ) 1023 ) ;
}
}
return V_148 ;
}
static inline struct V_118 * F_61 ( struct V_1 * V_2 )
{
struct V_100 * V_101 = & V_2 -> V_101 ;
struct V_118 * V_119
= & ( (struct V_102 * ) ( V_101 -> V_41 ) ) -> V_119 ;
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
return V_119 ;
}
static struct V_118 * F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 ;
struct V_118 * V_119 ;
if ( F_38 ( & V_4 -> V_93 ) >= V_4 -> V_150 ) {
F_16 ( & V_2 -> V_9 -> V_10 , L_15 ) ;
return NULL ;
}
V_119 = F_63 ( V_4 ) ;
F_64 ( V_4 ) ;
F_65 ( & V_4 -> V_93 ) ;
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
return V_119 ;
}
int F_66 ( struct V_1 * V_2 )
{
T_3 * V_119 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_151 ) )
return - 1 ;
V_119 = ( T_3 * ) F_61 ( V_2 ) ;
* V_119 ++ = 0xFF ;
* V_119 ++ = 0x12 ;
* V_119 ++ = 0x34 ;
* V_119 ++ = 0xFF ;
* V_119 ++ = 0xFF ;
* V_119 ++ = 0x56 ;
* V_119 ++ = 0x78 ;
* V_119 = 0xFF ;
V_22 = F_45 ( V_2 ) ;
F_68 ( & V_2 -> V_151 ) ;
return V_22 ;
}
int F_69 ( struct V_1 * V_2 )
{
T_3 * V_119 ;
int V_22 ;
if ( V_2 -> V_8 )
return - V_95 ;
if ( F_67 ( & V_2 -> V_151 ) )
return - 1 ;
V_119 = ( T_3 * ) F_61 ( V_2 ) ;
* V_119 ++ = 0xFF ;
* V_119 ++ = 0xAA ;
* V_119 ++ = 0xBB ;
* V_119 ++ = 0xFF ;
* V_119 ++ = 0xFF ;
* V_119 ++ = 0xCC ;
* V_119 ++ = 0xDD ;
* V_119 = 0xFF ;
V_22 = F_45 ( V_2 ) ;
F_68 ( & V_2 -> V_151 ) ;
return V_22 ;
}
int F_70 ( struct V_1 * V_2 ,
struct V_3 * V_152 , int V_153 )
{
struct V_118 * V_119 ;
struct V_154 * V_155 ;
struct V_100 * V_156 = & V_152 -> V_157 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_151 ) )
return - 1 ;
V_119 = F_61 ( V_2 ) ;
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 , V_158 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_158 , sizeof( * V_155 ) ) ;
V_155 -> V_160 = F_71 ( F_58 ( V_156 -> V_41 , V_156 -> V_142 ) ) ;
F_72 ( struct V_161 , V_58 , V_155 -> V_162 , 1 ) ;
F_72 ( struct V_161 , V_142 , V_155 -> V_162 , 0 ) ;
F_72 ( struct V_161 , V_163 , V_155 -> V_162 ,
F_73 ( V_152 -> V_150 / 256 ) ) ;
F_72 ( struct V_161 , V_164 , V_155 -> V_162 ,
F_59 ( V_153 ) ) ;
F_53 ( V_155 -> V_162 , sizeof( V_155 -> V_162 ) ) ;
F_56 ( V_155 -> V_138 , F_74 ( V_155 -> V_138 ) , V_156 ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_165 * V_39 = F_50 ( V_119 ) ;
V_152 -> V_11 = F_22 ( V_39 -> V_166 ) ;
V_152 -> V_167 = true ;
}
F_68 ( & V_2 -> V_151 ) ;
return V_22 ;
}
int F_75 ( struct V_1 * V_2 , T_3 * V_168 ,
T_3 type , bool V_169 , T_1 V_170 )
{
struct V_118 * V_119 ;
struct V_171 * V_155 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_151 ) )
return - 1 ;
V_119 = F_61 ( V_2 ) ;
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_172 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_172 , sizeof( * V_155 ) ) ;
V_155 -> type = type ;
if ( V_169 ) {
V_155 -> V_169 = 1 ;
} else {
V_155 -> V_173 = F_71 ( ( T_2 ) V_170 ) ;
V_155 -> V_169 = 0 ;
}
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_174 * V_39 = F_50 ( V_119 ) ;
memcpy ( V_168 , V_39 -> V_175 . V_176 , V_177 ) ;
}
F_68 ( & V_2 -> V_151 ) ;
return V_22 ;
}
int F_76 ( struct V_1 * V_2 , T_3 * V_168 ,
T_1 V_173 , T_1 * V_178 , T_1 V_179 )
{
struct V_118 * V_119 ;
struct V_180 * V_155 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_184 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_184 , sizeof( * V_155 ) ) ;
V_155 -> V_159 . V_179 = V_179 ;
V_155 -> V_173 = F_55 ( V_173 ) ;
memcpy ( V_155 -> V_185 , V_168 , V_177 ) ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_186 * V_39 = F_50 ( V_119 ) ;
* V_178 = F_6 ( V_39 -> V_178 ) ;
}
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_77 ( struct V_1 * V_2 , T_1 V_173 , T_1 V_178 , T_1 V_187 )
{
struct V_118 * V_119 ;
struct V_188 * V_155 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_189 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_189 , sizeof( * V_155 ) ) ;
V_155 -> V_159 . V_179 = V_187 ;
V_155 -> V_173 = F_55 ( V_173 ) ;
V_155 -> V_178 = F_55 ( V_178 ) ;
V_22 = F_40 ( V_2 ) ;
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_78 ( struct V_1 * V_2 ,
struct V_3 * V_86 , struct V_3 * V_152 ,
bool V_190 , bool V_191 , int V_192 )
{
struct V_118 * V_119 ;
struct V_193 * V_155 ;
struct V_100 * V_156 = & V_86 -> V_157 ;
void * V_194 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_151 ) )
return - 1 ;
V_119 = F_61 ( V_2 ) ;
V_155 = F_50 ( V_119 ) ;
V_194 = & V_155 -> V_162 ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_195 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_195 , sizeof( * V_155 ) ) ;
V_155 -> V_160 = F_71 ( F_58 ( V_156 -> V_41 , V_156 -> V_142 ) ) ;
if ( F_12 ( V_2 ) ) {
V_155 -> V_159 . V_136 = 2 ;
V_155 -> V_196 = 1 ;
F_72 ( struct V_197 , V_198 , V_194 ,
V_191 ) ;
F_72 ( struct V_197 , V_163 , V_194 ,
F_73 ( V_86 -> V_150 / 256 ) ) ;
F_72 ( struct V_197 , V_58 , V_194 , 1 ) ;
F_72 ( struct V_197 , V_199 ,
V_194 , 1 ) ;
F_72 ( struct V_197 , V_200 ,
V_194 , V_152 -> V_11 ) ;
F_72 ( struct V_197 , V_201 , V_194 , 1 ) ;
} else {
F_72 ( struct V_202 , V_203 , V_194 ,
V_192 ) ;
F_72 ( struct V_202 , V_198 ,
V_194 , V_191 ) ;
F_72 ( struct V_202 , V_163 , V_194 ,
F_73 ( V_86 -> V_150 / 256 ) ) ;
F_72 ( struct V_202 , V_58 , V_194 , 1 ) ;
F_72 ( struct V_202 , V_204 ,
V_194 , V_190 ) ;
F_72 ( struct V_202 , V_199 , V_194 , 1 ) ;
F_72 ( struct V_202 , V_200 , V_194 , V_152 -> V_11 ) ;
F_72 ( struct V_202 , V_201 , V_194 , 1 ) ;
}
F_53 ( V_194 , sizeof( V_155 -> V_162 ) ) ;
F_56 ( V_155 -> V_138 , F_74 ( V_155 -> V_138 ) , V_156 ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_205 * V_39 = F_50 ( V_119 ) ;
V_86 -> V_11 = F_22 ( V_39 -> V_206 ) ;
V_86 -> V_167 = true ;
}
F_68 ( & V_2 -> V_151 ) ;
return V_22 ;
}
static T_1 F_79 ( int V_207 )
{
T_1 V_208 = F_80 ( V_207 ) ;
if ( V_208 == 16 )
V_208 = 0 ;
return V_208 ;
}
int F_81 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_86 )
{
struct V_118 * V_119 ;
struct V_209 * V_155 ;
struct V_100 * V_156 = & V_4 -> V_157 ;
void * V_194 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_151 ) )
return - 1 ;
V_119 = F_61 ( V_2 ) ;
V_155 = F_50 ( V_119 ) ;
V_194 = & V_155 -> V_162 ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_210 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_210 , sizeof( * V_155 ) ) ;
V_155 -> V_160 = F_71 ( F_58 ( V_156 -> V_41 , V_156 -> V_142 ) ) ;
if ( F_12 ( V_2 ) ) {
V_155 -> V_159 . V_136 = 1 ;
V_155 -> V_206 = F_71 ( V_86 -> V_11 ) ;
F_72 ( struct V_211 , V_212 , V_194 ,
F_79 ( V_4 -> V_150 ) ) ;
F_72 ( struct V_211 , V_58 , V_194 , 1 ) ;
F_72 ( struct V_211 , V_213 ,
V_194 , V_86 -> V_11 ) ;
F_72 ( struct V_211 , V_214 ,
V_194 , 1 ) ;
} else {
F_72 ( struct V_215 , V_58 , V_194 , 1 ) ;
F_72 ( struct V_215 , V_212 , V_194 ,
F_79 ( V_4 -> V_150 ) ) ;
F_72 ( struct V_215 , V_206 , V_194 , V_86 -> V_11 ) ;
}
V_155 -> V_216 [ 0 ] = F_55 ( 0x00000022 ) ;
F_53 ( V_194 , sizeof( V_155 -> V_162 ) ) ;
F_56 ( V_155 -> V_138 , F_74 ( V_155 -> V_138 ) , V_156 ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_217 * V_39 = F_50 ( V_119 ) ;
V_4 -> V_11 = F_22 ( V_39 -> V_11 ) ;
V_4 -> V_167 = true ;
}
F_68 ( & V_2 -> V_151 ) ;
return V_22 ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_86 )
{
struct V_118 * V_119 ;
struct V_218 * V_155 ;
struct V_100 * V_156 = & V_4 -> V_157 ;
void * V_194 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_151 ) )
return - 1 ;
V_119 = F_61 ( V_2 ) ;
V_155 = F_50 ( V_119 ) ;
V_194 = & V_155 -> V_162 ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_219 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_219 , sizeof( * V_155 ) ) ;
V_155 -> V_160 = F_71 ( F_58 ( V_156 -> V_41 , V_156 -> V_142 ) ) ;
F_72 ( struct V_215 , V_58 , V_194 , 1 ) ;
F_72 ( struct V_215 , V_212 , V_194 ,
F_79 ( V_4 -> V_150 ) ) ;
F_72 ( struct V_215 , V_206 , V_194 , V_86 -> V_11 ) ;
F_53 ( V_194 , sizeof( V_155 -> V_162 ) ) ;
F_56 ( V_155 -> V_138 , F_74 ( V_155 -> V_138 ) , V_156 ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_217 * V_39 = F_50 ( V_119 ) ;
V_4 -> V_11 = F_22 ( V_39 -> V_11 ) ;
V_4 -> V_167 = true ;
}
F_68 ( & V_2 -> V_151 ) ;
return V_22 ;
}
int F_83 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_86 )
{
int V_22 ;
V_22 = F_81 ( V_2 , V_4 , V_86 ) ;
if ( V_22 && ! F_12 ( V_2 ) ) {
F_15 ( & V_2 -> V_9 -> V_10 , L_16
L_17
L_18 ) ;
V_22 = F_82 ( V_2 , V_4 , V_86 ) ;
}
return V_22 ;
}
int F_84 ( struct V_1 * V_2 ,
struct V_3 * V_220 ,
struct V_3 * V_86 )
{
struct V_118 * V_119 ;
struct V_221 * V_155 ;
struct V_100 * V_156 = & V_220 -> V_157 ;
void * V_194 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_151 ) )
return - 1 ;
V_119 = F_61 ( V_2 ) ;
V_155 = F_50 ( V_119 ) ;
V_194 = & V_155 -> V_162 ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_222 ) ;
F_54 ( & V_155 -> V_159 , V_35 , V_222 ,
sizeof( * V_155 ) ) ;
if ( F_12 ( V_2 ) ) {
V_155 -> V_159 . V_136 = 1 ;
F_72 ( struct V_223 , V_173 , V_194 ,
V_2 -> V_170 ) ;
}
V_155 -> V_160 = F_58 ( V_156 -> V_41 , V_156 -> V_142 ) ;
V_155 -> V_224 = V_225 ;
V_155 -> type = V_226 ;
F_72 ( struct V_223 , V_227 , V_194 ,
F_79 ( V_220 -> V_150 ) ) ;
F_72 ( struct V_223 , V_228 , V_194 , 1 ) ;
F_72 ( struct V_223 , V_229 , V_194 , V_86 -> V_11 ) ;
F_53 ( V_194 , sizeof( V_155 -> V_162 ) ) ;
F_56 ( V_155 -> V_138 , F_74 ( V_155 -> V_138 ) , V_156 ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_230 * V_39 = F_50 ( V_119 ) ;
V_220 -> V_11 = F_22 ( V_39 -> V_231 ) ;
V_220 -> V_167 = true ;
}
F_68 ( & V_2 -> V_151 ) ;
return V_22 ;
}
int F_85 ( struct V_1 * V_2 ,
struct V_3 * V_232 , T_2 V_206 , T_2 V_233 ,
T_2 V_234 , T_1 V_173 , T_1 V_235 , T_3 * V_236 )
{
struct V_118 * V_119 ;
struct V_237 * V_155 ;
struct V_100 * V_156 = & V_232 -> V_157 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_238 ) ;
F_54 ( & V_155 -> V_159 , V_35 , V_238 ,
sizeof( * V_155 ) ) ;
V_155 -> V_206 = F_71 ( V_206 ) ;
V_155 -> V_233 = F_80 ( V_233 ) - 1 ;
V_155 -> V_160 = 2 ;
F_56 ( V_155 -> V_138 , F_74 ( V_155 -> V_138 ) , V_156 ) ;
V_155 -> V_239 = F_55 ( V_173 ) ;
V_155 -> V_234 = F_71 ( V_234 ) ;
V_155 -> V_240 = F_55 ( V_235 ) ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_241 * V_39 = F_50 ( V_119 ) ;
V_232 -> V_11 = F_22 ( V_39 -> V_11 ) ;
V_232 -> V_167 = true ;
* V_236 = V_39 -> V_236 ;
}
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_86 ( struct V_1 * V_2 , struct V_3 * V_6 ,
int V_242 )
{
struct V_118 * V_119 ;
struct V_243 * V_155 ;
T_3 V_244 = 0 , V_126 = 0 ;
int V_22 ;
if ( V_2 -> V_8 )
return - V_95 ;
if ( F_67 ( & V_2 -> V_151 ) )
return - 1 ;
V_119 = F_61 ( V_2 ) ;
V_155 = F_50 ( V_119 ) ;
switch ( V_242 ) {
case V_245 :
V_244 = V_29 ;
V_126 = V_246 ;
break;
case V_247 :
V_244 = V_29 ;
V_126 = V_248 ;
break;
case V_249 :
V_244 = V_35 ;
V_126 = V_250 ;
break;
case V_251 :
V_244 = V_35 ;
V_126 = V_252 ;
break;
case V_253 :
V_244 = V_29 ;
V_126 = V_254 ;
break;
default:
F_87 () ;
}
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 , V_126 ) ;
F_54 ( & V_155 -> V_159 , V_244 , V_126 , sizeof( * V_155 ) ) ;
V_155 -> V_11 = F_71 ( V_6 -> V_11 ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 )
V_6 -> V_167 = false ;
F_68 ( & V_2 -> V_151 ) ;
return V_22 ;
}
int F_88 ( struct V_1 * V_2 , struct V_3 * V_6 )
{
struct V_118 * V_119 ;
struct V_243 * V_155 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 , V_252 ) ;
F_54 ( & V_155 -> V_159 , V_35 , V_252 ,
sizeof( * V_155 ) ) ;
V_155 -> V_11 = F_71 ( V_6 -> V_11 ) ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 )
V_6 -> V_167 = false ;
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_89 ( struct V_1 * V_2 , T_1 V_255 , T_1 V_256 ,
T_3 * V_175 , bool V_257 , T_1 * V_170 , T_1 * V_178 ,
T_1 V_179 )
{
struct V_118 * V_119 ;
struct V_258 * V_155 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_151 ) )
return - 1 ;
V_119 = F_61 ( V_2 ) ;
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_259 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_259 , sizeof( * V_155 ) ) ;
V_155 -> V_159 . V_179 = V_179 ;
V_155 -> V_260 = F_55 ( V_255 ) ;
V_155 -> V_261 = F_55 ( V_256 ) ;
V_155 -> V_257 = V_257 ;
if ( ! V_257 )
memcpy ( V_155 -> V_168 , V_175 , V_177 ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_262 * V_39 = F_50 ( V_119 ) ;
* V_170 = F_6 ( V_39 -> V_239 ) ;
if ( ! V_257 )
* V_178 = F_6 ( V_39 -> V_178 ) ;
}
F_68 ( & V_2 -> V_151 ) ;
return V_22 ;
}
int F_90 ( struct V_1 * V_2 , T_1 V_239 , T_1 V_179 )
{
struct V_118 * V_119 ;
struct V_263 * V_155 ;
int V_22 ;
if ( V_2 -> V_8 )
return - V_95 ;
if ( F_67 ( & V_2 -> V_151 ) )
return - 1 ;
V_119 = F_61 ( V_2 ) ;
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_264 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_264 , sizeof( * V_155 ) ) ;
V_155 -> V_159 . V_179 = V_179 ;
V_155 -> V_239 = F_55 ( V_239 ) ;
V_22 = F_45 ( V_2 ) ;
F_68 ( & V_2 -> V_151 ) ;
return V_22 ;
}
int F_91 ( struct V_1 * V_2 , struct V_100 * V_265 )
{
struct V_118 * V_119 ;
struct V_131 * V_159 ;
struct V_121 * V_266 ;
int V_22 = 0 ;
if ( F_92 ( V_2 -> V_267 , V_268 ) == 0 )
F_93 ( V_2 ) ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_159 = V_265 -> V_41 ;
V_266 = F_51 ( V_119 ) ;
F_52 ( V_119 , V_265 -> V_142 , false , 1 ,
V_33 ) ;
F_54 ( V_159 , V_35 ,
V_33 , V_265 -> V_142 ) ;
if ( V_2 -> V_36 == V_37 )
V_159 -> V_136 = 1 ;
V_119 -> V_28 = V_35 ;
V_266 -> V_269 = F_55 ( F_46 ( V_265 -> V_105 ) ) ;
V_266 -> V_270 = F_55 ( V_265 -> V_105 & 0xFFFFFFFF ) ;
V_266 -> V_150 = F_55 ( V_265 -> V_142 ) ;
F_1 ( V_2 ) ;
V_2 -> V_46 = true ;
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_94 ( struct V_1 * V_2 ,
struct V_100 * V_265 )
{
struct V_118 * V_119 ;
struct V_271 * V_155 ;
struct V_121 * V_266 ;
int V_22 = 0 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = V_265 -> V_41 ;
V_266 = F_51 ( V_119 ) ;
F_52 ( V_119 , V_265 -> V_142 , false , 1 ,
V_34 ) ;
F_54 ( & V_155 -> V_159 , V_35 ,
V_34 , V_265 -> V_142 ) ;
V_155 -> V_272 . V_273 . V_274 = F_71 ( V_2 -> V_67 ) ;
V_155 -> V_272 . V_273 . V_275 = 0 ;
V_119 -> V_28 = V_35 ;
V_266 -> V_269 = F_55 ( F_46 ( V_265 -> V_105 ) ) ;
V_266 -> V_270 = F_55 ( V_265 -> V_105 & 0xFFFFFFFF ) ;
V_266 -> V_150 = F_55 ( V_265 -> V_142 ) ;
F_1 ( V_2 ) ;
V_2 -> V_46 = true ;
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_95 ( struct V_1 * V_2 ,
bool * V_276 , T_3 * V_277 , T_2 * V_68 , T_1 V_187 )
{
struct V_118 * V_119 ;
struct V_278 * V_155 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = F_50 ( V_119 ) ;
* V_276 = false ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_279 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_279 , sizeof( * V_155 ) ) ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_280 * V_39 = F_50 ( V_119 ) ;
if ( V_39 -> V_277 != V_281 ) {
* V_276 = true ;
* V_68 = F_22 ( V_39 -> V_68 ) ;
* V_277 = V_39 -> V_277 ;
}
}
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_93 ( struct V_1 * V_2 )
{
struct V_118 * V_119 ;
struct V_282 * V_155 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_283 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_283 , sizeof( * V_155 ) ) ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_284 * V_39 =
F_50 ( V_119 ) ;
V_2 -> V_285 . V_286 =
V_39 -> V_287 ;
}
else
V_268 = 0 ;
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_96 ( struct V_1 * V_2 , T_1 * V_288 )
{
struct V_118 * V_119 ;
struct V_289 * V_155 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_290 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_290 , sizeof( * V_155 ) ) ;
V_155 -> V_291 = F_55 ( V_292 ) ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_293 * V_39 = F_50 ( V_119 ) ;
if ( V_288 && V_39 -> V_288 )
* V_288 = F_6 ( V_39 -> V_288 ) -
sizeof( T_1 ) ;
}
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
void F_97 ( struct V_1 * V_2 , T_1 V_294 , void * V_295 )
{
struct V_100 V_296 ;
struct V_118 * V_119 ;
struct V_289 * V_155 ;
struct V_121 * V_266 ;
T_1 V_297 = 0 , V_298 , V_299 ,
V_300 = sizeof( T_1 ) , V_123 ;
int V_22 ;
if ( V_294 == 0 )
return;
V_298 = V_294 ;
V_296 . V_142 = sizeof( struct V_289 ) + 60 * 1024 ;
V_296 . V_41 = F_98 ( V_2 -> V_9 ,
V_296 . V_142 ,
& V_296 . V_105 ) ;
if ( ! V_296 . V_41 ) {
V_22 = - V_301 ;
F_16 ( & V_2 -> V_9 -> V_10 ,
L_19 ) ;
return;
}
F_30 ( & V_2 -> V_181 ) ;
while ( V_298 ) {
V_299 = F_57 ( V_298 , ( T_1 ) 60 * 1024 ) ;
V_298 -= V_299 ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = V_296 . V_41 ;
V_266 = F_51 ( V_119 ) ;
V_123 = sizeof( struct V_289 ) + V_299 ;
F_52 ( V_119 , V_123 , false , 1 ,
V_290 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_290 , V_123 ) ;
V_266 -> V_269 = F_55 ( F_46 ( V_296 . V_105 ) ) ;
V_266 -> V_270 = F_55 ( V_296 . V_105 & 0xFFFFFFFF ) ;
V_266 -> V_150 = F_55 ( V_296 . V_142 ) ;
V_155 -> V_291 = F_55 ( V_302 ) ;
V_155 -> V_303 = F_55 ( V_300 ) ;
V_155 -> V_304 = F_55 ( V_299 ) ;
V_155 -> V_305 = F_55 ( V_299 ) ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_293 * V_39 = V_296 . V_41 ;
memcpy ( V_295 + V_297 ,
V_39 -> V_306 ,
V_39 -> V_304 ) ;
} else {
F_16 ( & V_2 -> V_9 -> V_10 , L_20 ) ;
goto V_183;
}
V_297 += V_299 ;
V_300 += V_299 ;
}
V_183:
F_99 ( V_2 -> V_9 , V_296 . V_142 ,
V_296 . V_41 ,
V_296 . V_105 ) ;
F_32 ( & V_2 -> V_181 ) ;
}
int F_100 ( struct V_1 * V_2 , char * V_307 )
{
struct V_118 * V_119 ;
struct V_308 * V_155 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_151 ) )
return - 1 ;
V_119 = F_61 ( V_2 ) ;
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_309 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_309 , sizeof( * V_155 ) ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_310 * V_39 = F_50 ( V_119 ) ;
strncpy ( V_307 , V_39 -> V_311 , V_312 ) ;
}
F_68 ( & V_2 -> V_151 ) ;
return V_22 ;
}
int F_101 ( struct V_1 * V_2 , T_1 V_166 , T_1 V_313 )
{
struct V_118 * V_119 ;
struct V_314 * V_155 ;
int V_22 = 0 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_315 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_315 , sizeof( * V_155 ) ) ;
V_155 -> V_316 = F_55 ( 1 ) ;
V_155 -> V_317 [ 0 ] . V_166 = F_55 ( V_166 ) ;
V_155 -> V_317 [ 0 ] . V_318 = 0 ;
V_155 -> V_317 [ 0 ] . V_319 = F_55 ( V_313 ) ;
F_1 ( V_2 ) ;
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_102 ( struct V_1 * V_2 , T_1 V_173 , T_2 * V_320 ,
T_1 V_89 , bool V_321 , bool V_322 )
{
struct V_118 * V_119 ;
struct V_323 * V_155 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_324 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_324 , sizeof( * V_155 ) ) ;
V_155 -> V_239 = V_173 ;
V_155 -> V_322 = V_322 ;
V_155 -> V_321 = V_321 ;
V_155 -> V_325 = V_89 ;
if ( ! V_322 ) {
memcpy ( V_155 -> V_326 , V_320 ,
V_155 -> V_325 * sizeof( V_320 [ 0 ] ) ) ;
}
V_22 = F_40 ( V_2 ) ;
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_103 ( struct V_1 * V_2 , bool V_327 )
{
struct V_118 * V_119 ;
struct V_328 * V_155 ;
struct V_100 V_329 ;
struct V_121 * V_266 ;
int V_22 ;
memset ( & V_329 , 0 , sizeof( struct V_100 ) ) ;
V_329 . V_142 = sizeof( struct V_328 ) ;
V_329 . V_41 = F_98 ( V_2 -> V_9 ,
V_329 . V_142 , & V_329 . V_105 ) ;
if ( ! V_329 . V_41 ) {
F_16 ( & V_2 -> V_9 -> V_10 ,
L_21 ) ;
return - V_301 ;
}
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = V_329 . V_41 ;
V_266 = F_51 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , false , 1 ,
V_330 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_330 , sizeof( * V_155 ) ) ;
V_155 -> V_173 = F_55 ( V_2 -> V_170 ) ;
V_155 -> V_331 = F_55 ( V_332 ) ;
if ( V_327 )
V_155 -> V_333 = F_55 ( V_332 ) ;
V_266 -> V_269 = F_55 ( F_46 ( V_329 . V_105 ) ) ;
V_266 -> V_270 = F_55 ( V_329 . V_105 & 0xFFFFFFFF ) ;
V_266 -> V_150 = F_55 ( V_329 . V_142 ) ;
V_22 = F_40 ( V_2 ) ;
V_183:
F_32 ( & V_2 -> V_181 ) ;
F_99 ( V_2 -> V_9 , V_329 . V_142 ,
V_329 . V_41 , V_329 . V_105 ) ;
return V_22 ;
}
int F_104 ( struct V_1 * V_2 , T_1 V_173 ,
struct V_334 * V_335 , struct V_100 * V_140 )
{
struct V_118 * V_119 ;
struct V_336 * V_155 = V_140 -> V_41 ;
struct V_121 * V_266 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_266 = F_51 ( V_119 ) ;
memset ( V_155 , 0 , sizeof( * V_155 ) ) ;
F_52 ( V_119 , sizeof( * V_155 ) , false , 1 ,
V_337 ) ;
V_266 -> V_269 = F_55 ( F_46 ( V_140 -> V_105 ) ) ;
V_266 -> V_270 = F_55 ( V_140 -> V_105 & 0xFFFFFFFF ) ;
V_266 -> V_150 = F_55 ( V_140 -> V_142 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_337 , sizeof( * V_155 ) ) ;
V_155 -> V_239 = V_173 ;
if ( V_335 ) {
int V_94 ;
struct V_338 * V_339 ;
V_155 -> V_340 = F_71 ( F_105 ( V_335 ) ) ;
V_94 = 0 ;
F_106 (ha, netdev)
memcpy ( V_155 -> V_175 [ V_94 ++ ] . V_341 , V_339 -> V_176 , V_177 ) ;
} else {
V_155 -> V_322 = 1 ;
}
V_22 = F_40 ( V_2 ) ;
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_107 ( struct V_1 * V_2 , T_1 V_342 , T_1 V_343 )
{
struct V_118 * V_119 ;
struct V_344 * V_155 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_345 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_345 , sizeof( * V_155 ) ) ;
V_155 -> V_346 = F_71 ( ( T_2 ) V_342 ) ;
V_155 -> V_347 = F_71 ( ( T_2 ) V_343 ) ;
V_22 = F_40 ( V_2 ) ;
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_108 ( struct V_1 * V_2 , T_1 * V_342 , T_1 * V_343 )
{
struct V_118 * V_119 ;
struct V_348 * V_155 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_349 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_349 , sizeof( * V_155 ) ) ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_350 * V_39 =
F_50 ( V_119 ) ;
* V_342 = F_22 ( V_39 -> V_346 ) ;
* V_343 = F_22 ( V_39 -> V_347 ) ;
}
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_109 ( struct V_1 * V_2 , T_1 * V_67 ,
T_1 * V_351 , T_1 * V_352 )
{
struct V_118 * V_119 ;
struct V_353 * V_155 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_151 ) )
return - 1 ;
V_119 = F_61 ( V_2 ) ;
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_354 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_354 , sizeof( * V_155 ) ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_355 * V_39 = F_50 ( V_119 ) ;
* V_67 = F_6 ( V_39 -> V_356 ) ;
* V_351 = F_6 ( V_39 -> V_357 ) ;
* V_352 = F_6 ( V_39 -> V_358 ) ;
}
F_68 ( & V_2 -> V_151 ) ;
return V_22 ;
}
int F_110 ( struct V_1 * V_2 )
{
struct V_118 * V_119 ;
struct V_131 * V_155 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_151 ) )
return - 1 ;
V_119 = F_61 ( V_2 ) ;
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_359 ) ;
F_54 ( V_155 , V_29 ,
V_359 , sizeof( * V_155 ) ) ;
V_22 = F_45 ( V_2 ) ;
F_68 ( & V_2 -> V_151 ) ;
return V_22 ;
}
int F_111 ( struct V_1 * V_2 , T_3 * V_360 , T_2 V_361 )
{
struct V_118 * V_119 ;
struct V_362 * V_155 ;
T_1 V_363 [ 10 ] = { 0x0123 , 0x4567 , 0x89AB , 0xCDEF , 0x01EF ,
0x0123 , 0x4567 , 0x89AB , 0xCDEF , 0x01EF } ;
int V_22 ;
if ( F_67 ( & V_2 -> V_151 ) )
return - 1 ;
V_119 = F_61 ( V_2 ) ;
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_364 ) ;
F_54 ( & V_155 -> V_159 , V_35 ,
V_364 , sizeof( * V_155 ) ) ;
V_155 -> V_173 = F_55 ( V_2 -> V_170 ) ;
V_155 -> V_365 = F_71 ( V_366 | V_367 ) ;
V_155 -> V_368 = F_71 ( F_80 ( V_361 ) - 1 ) ;
memcpy ( V_155 -> V_369 , V_360 , V_361 ) ;
memcpy ( V_155 -> V_370 , V_363 , sizeof( V_363 ) ) ;
F_53 ( V_155 -> V_370 , sizeof( V_155 -> V_370 ) ) ;
V_22 = F_45 ( V_2 ) ;
F_68 ( & V_2 -> V_151 ) ;
return V_22 ;
}
int F_112 ( struct V_1 * V_2 , T_3 V_67 ,
T_3 V_371 , T_3 V_372 , T_3 V_373 )
{
struct V_118 * V_119 ;
struct V_374 * V_155 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_375 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_375 , sizeof( * V_155 ) ) ;
V_155 -> V_67 = V_67 ;
V_155 -> V_376 = V_373 ;
V_155 -> V_377 = V_371 ;
V_155 -> V_378 = V_372 ;
V_22 = F_40 ( V_2 ) ;
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_113 ( struct V_1 * V_2 , T_3 V_67 , T_1 * V_373 )
{
struct V_118 * V_119 ;
struct V_379 * V_155 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_380 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_380 , sizeof( * V_155 ) ) ;
V_155 -> V_67 = V_67 ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_381 * V_39 =
F_50 ( V_119 ) ;
* V_373 = V_39 -> V_376 ;
}
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_114 ( struct V_1 * V_2 , struct V_100 * V_382 ,
T_1 V_383 , T_1 V_384 , const char * V_385 ,
T_1 * V_386 , T_3 * V_387 )
{
struct V_118 * V_119 ;
struct V_388 * V_155 ;
struct V_389 * V_39 ;
void * V_194 = NULL ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_2 -> V_30 = 0 ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_390;
}
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( struct V_388 ) ,
true , 1 , V_27 ) ;
V_119 -> V_28 = V_29 ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_27 ,
sizeof( struct V_388 ) ) ;
V_194 = & V_155 -> V_162 ;
F_72 ( struct V_391 ,
V_392 , V_194 , V_383 ) ;
if ( V_383 == 0 )
F_72 ( struct V_391 ,
V_393 , V_194 , 1 ) ;
else
F_72 ( struct V_391 ,
V_393 , V_194 , 0 ) ;
F_53 ( V_194 , sizeof( V_155 -> V_162 ) ) ;
V_155 -> V_394 = F_55 ( V_384 ) ;
strcpy ( V_155 -> V_395 , V_385 ) ;
V_155 -> V_396 = F_55 ( 1 ) ;
V_155 -> V_294 = F_55 ( V_383 ) ;
V_155 -> V_397 = F_55 ( ( V_382 -> V_105 +
sizeof( struct V_388 ) )
& 0xFFFFFFFF ) ;
V_155 -> V_398 = F_55 ( F_46 ( V_382 -> V_105 +
sizeof( struct V_388 ) ) ) ;
F_1 ( V_2 ) ;
F_32 ( & V_2 -> V_181 ) ;
if ( ! F_115 ( & V_2 -> V_31 ,
F_116 ( 12000 ) ) )
V_22 = - 1 ;
else
V_22 = V_2 -> V_30 ;
V_39 = F_50 ( V_119 ) ;
if ( ! V_22 ) {
* V_386 = F_6 ( V_39 -> V_399 ) ;
} else {
* V_387 = V_39 -> V_400 ;
V_22 = V_39 -> V_22 ;
}
return V_22 ;
V_390:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_117 ( struct V_1 * V_2 , struct V_100 * V_382 ,
T_1 V_401 , T_1 V_402 , T_1 V_299 )
{
struct V_118 * V_119 ;
struct F_117 * V_155 ;
struct V_121 * V_266 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_2 -> V_30 = 0 ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_390;
}
V_155 = V_382 -> V_41 ;
V_266 = F_51 ( V_119 ) ;
F_52 ( V_119 , V_382 -> V_142 , false , 1 ,
V_26 ) ;
V_119 -> V_28 = V_29 ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_26 , V_382 -> V_142 ) ;
V_266 -> V_269 = F_55 ( F_46 ( V_382 -> V_105 ) ) ;
V_266 -> V_270 = F_55 ( V_382 -> V_105 & 0xFFFFFFFF ) ;
V_266 -> V_150 = F_55 ( V_382 -> V_142 ) ;
V_155 -> V_273 . V_403 = F_55 ( V_401 ) ;
V_155 -> V_273 . V_404 = F_55 ( V_402 ) ;
V_155 -> V_273 . V_405 = F_55 ( V_299 ) ;
F_1 ( V_2 ) ;
F_32 ( & V_2 -> V_181 ) ;
if ( ! F_115 ( & V_2 -> V_31 ,
F_116 ( 12000 ) ) )
V_22 = - 1 ;
else
V_22 = V_2 -> V_30 ;
return V_22 ;
V_390:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_118 ( struct V_1 * V_2 , T_3 * V_406 ,
int V_297 )
{
struct V_118 * V_119 ;
struct F_117 * V_155 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) + 4 , true , 0 ,
V_407 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_407 , sizeof( * V_155 ) + 4 ) ;
V_155 -> V_273 . V_403 = F_55 ( V_408 ) ;
V_155 -> V_273 . V_404 = F_55 ( V_409 ) ;
V_155 -> V_273 . V_297 = F_55 ( V_297 ) ;
V_155 -> V_273 . V_405 = F_55 ( 0x4 ) ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 )
memcpy ( V_406 , V_155 -> V_273 . V_410 , 4 ) ;
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_119 ( struct V_1 * V_2 , T_3 * V_175 ,
struct V_100 * V_265 )
{
struct V_118 * V_119 ;
struct V_411 * V_155 ;
struct V_121 * V_266 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = V_265 -> V_41 ;
V_266 = F_51 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , false , 1 ,
V_412 ) ;
F_54 ( & V_155 -> V_159 , V_35 ,
V_412 , sizeof( * V_155 ) ) ;
memcpy ( V_155 -> V_413 , V_175 , V_177 ) ;
V_266 -> V_269 = F_55 ( F_46 ( V_265 -> V_105 ) ) ;
V_266 -> V_270 = F_55 ( V_265 -> V_105 & 0xFFFFFFFF ) ;
V_266 -> V_150 = F_55 ( V_265 -> V_142 ) ;
V_22 = F_40 ( V_2 ) ;
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_120 ( struct V_1 * V_2 , T_3 V_67 ,
T_3 V_414 , T_3 V_415 )
{
struct V_118 * V_119 ;
struct V_416 * V_155 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_417 ) ;
F_54 ( & V_155 -> V_159 , V_418 ,
V_417 ,
sizeof( * V_155 ) ) ;
V_155 -> V_419 = V_67 ;
V_155 -> V_420 = V_67 ;
V_155 -> V_414 = V_414 ;
V_155 -> V_421 = V_415 ;
V_22 = F_40 ( V_2 ) ;
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_121 ( struct V_1 * V_2 , T_1 V_67 ,
T_1 V_414 , T_1 V_422 , T_1 V_423 , T_5 V_424 )
{
struct V_118 * V_119 ;
struct V_425 * V_155 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_426 ) ;
F_54 ( & V_155 -> V_159 , V_418 ,
V_426 , sizeof( * V_155 ) ) ;
V_155 -> V_159 . V_114 = F_55 ( 4 ) ;
V_155 -> V_424 = F_122 ( V_424 ) ;
V_155 -> V_419 = F_55 ( V_67 ) ;
V_155 -> V_420 = F_55 ( V_67 ) ;
V_155 -> V_422 = F_55 ( V_422 ) ;
V_155 -> V_423 = F_55 ( V_423 ) ;
V_155 -> V_414 = F_55 ( V_414 ) ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_427 * V_39 = F_50 ( V_119 ) ;
V_22 = F_6 ( V_39 -> V_22 ) ;
}
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_123 ( struct V_1 * V_2 , T_5 V_424 ,
T_1 V_428 , struct V_100 * V_382 )
{
struct V_118 * V_119 ;
struct V_429 * V_155 ;
struct V_121 * V_266 ;
int V_22 ;
int V_94 , V_430 = 0 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = V_382 -> V_41 ;
V_266 = F_51 ( V_119 ) ;
F_52 ( V_119 , V_382 -> V_142 , false , 1 ,
V_431 ) ;
F_54 ( & V_155 -> V_159 , V_418 ,
V_431 , V_382 -> V_142 ) ;
V_266 -> V_269 = F_55 ( F_46 ( V_382 -> V_105 ) ) ;
V_266 -> V_270 = F_55 ( V_382 -> V_105 & 0xFFFFFFFF ) ;
V_266 -> V_150 = F_55 ( V_382 -> V_142 ) ;
V_155 -> V_424 = F_122 ( V_424 ) ;
V_155 -> V_432 = F_55 ( V_428 ) ;
for ( V_94 = 0 ; V_94 < V_428 ; V_94 ++ ) {
V_155 -> V_433 [ V_94 ] = ( T_3 ) ( V_424 >> ( V_430 * 8 ) ) ;
V_430 ++ ;
if ( V_430 > 7 )
V_430 = 0 ;
}
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_434 * V_39 ;
V_39 = V_382 -> V_41 ;
if ( ( memcmp ( V_39 -> V_435 , V_155 -> V_433 , V_428 ) != 0 ) ||
V_39 -> V_436 ) {
V_22 = - 1 ;
}
}
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_124 ( struct V_1 * V_2 ,
struct V_100 * V_265 )
{
struct V_118 * V_119 ;
struct V_437 * V_155 ;
struct V_121 * V_266 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = V_265 -> V_41 ;
V_266 = F_51 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , false , 1 ,
V_438 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_438 , sizeof( * V_155 ) ) ;
V_266 -> V_269 = F_55 ( F_46 ( V_265 -> V_105 ) ) ;
V_266 -> V_270 = F_55 ( V_265 -> V_105 & 0xFFFFFFFF ) ;
V_266 -> V_150 = F_55 ( V_265 -> V_142 ) ;
V_22 = F_40 ( V_2 ) ;
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_125 ( struct V_1 * V_2 , struct V_100 * V_382 )
{
struct V_118 * V_119 ;
struct V_439 * V_155 ;
struct V_121 * V_266 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = V_382 -> V_41 ;
V_266 = F_51 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , false , 1 ,
V_440 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_440 ,
sizeof( * V_155 ) ) ;
V_266 -> V_269 = F_55 ( F_46 ( V_382 -> V_105 ) ) ;
V_266 -> V_270 = F_55 ( V_382 -> V_105 & 0xFFFFFFFF ) ;
V_266 -> V_150 = F_55 ( V_382 -> V_142 ) ;
V_22 = F_40 ( V_2 ) ;
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_126 ( struct V_1 * V_2 , T_1 V_441 , T_1 V_179 )
{
struct V_118 * V_119 ;
struct V_442 * V_155 ;
int V_22 ;
F_30 ( & V_2 -> V_181 ) ;
V_119 = F_62 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_443 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_443 , sizeof( * V_155 ) ) ;
V_155 -> V_159 . V_179 = V_179 ;
V_155 -> V_444 = F_55 ( V_445 ) ;
V_155 -> V_446 = F_55 ( V_441 ) ;
V_22 = F_40 ( V_2 ) ;
V_183:
F_32 ( & V_2 -> V_181 ) ;
return V_22 ;
}
int F_127 ( struct V_1 * V_2 )
{
struct V_118 * V_119 ;
struct V_447 * V_155 ;
struct V_448 * V_39 ;
struct V_121 * V_266 ;
int V_22 ;
int V_123 = F_128 ( sizeof( * V_155 ) , sizeof( * V_39 ) ) ;
struct V_449 * V_450 ;
struct V_100 V_451 ;
memset ( & V_451 , 0 , sizeof( struct V_100 ) ) ;
V_451 . V_142 = sizeof( struct V_448 ) ;
V_451 . V_41 = F_98 ( V_2 -> V_9 , V_451 . V_142 ,
& V_451 . V_105 ) ;
if ( ! V_451 . V_41 ) {
F_16 ( & V_2 -> V_9 -> V_10 ,
L_21 ) ;
return - V_301 ;
}
if ( F_67 ( & V_2 -> V_151 ) )
return - 1 ;
V_119 = F_61 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = V_451 . V_41 ;
V_266 = F_51 ( V_119 ) ;
F_52 ( V_119 , V_123 , false , 1 ,
V_452 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_452 , V_123 ) ;
V_266 -> V_269 = F_55 ( F_46 ( V_451 . V_105 ) ) ;
V_266 -> V_270 = F_55 ( V_451 . V_105 & 0xFFFFFFFF ) ;
V_266 -> V_150 = F_55 ( V_451 . V_142 ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
V_450 = V_451 . V_41 + sizeof( struct V_453 ) ;
V_2 -> V_454 = V_450 -> V_455 . V_456 ;
}
V_183:
F_68 ( & V_2 -> V_151 ) ;
F_99 ( V_2 -> V_9 , V_451 . V_142 , V_451 . V_41 ,
V_451 . V_105 ) ;
return V_22 ;
}
int F_129 ( struct V_1 * V_2 )
{
struct V_118 * V_119 ;
struct V_457 * V_155 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_151 ) )
return - 1 ;
V_119 = F_61 ( V_2 ) ;
if ( ! V_119 ) {
V_22 = - V_182 ;
goto V_183;
}
V_155 = F_50 ( V_119 ) ;
F_52 ( V_119 , sizeof( * V_155 ) , true , 0 ,
V_458 ) ;
F_54 ( & V_155 -> V_159 , V_29 ,
V_458 , sizeof( * V_155 ) ) ;
V_155 -> V_459 = F_55 ( V_460 |
V_461 ) ;
V_155 -> V_255 = F_55 ( V_461 ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_462 * V_39 = F_50 ( V_119 ) ;
V_2 -> V_463 = F_6 ( V_39 -> V_255 ) &
V_461 ;
}
V_183:
F_68 ( & V_2 -> V_151 ) ;
return V_22 ;
}
