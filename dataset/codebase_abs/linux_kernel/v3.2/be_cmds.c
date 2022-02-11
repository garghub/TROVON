static inline void * F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . F_1 ;
}
static void F_2 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 . V_9 ;
T_1 V_10 = 0 ;
if ( V_5 -> V_11 ) {
F_3 ( & V_5 -> V_12 -> V_13 ,
L_1 ) ;
return;
}
V_10 |= V_7 -> V_14 & V_15 ;
V_10 |= 1 << V_16 ;
F_4 () ;
F_5 ( V_10 , V_5 -> V_17 + V_18 ) ;
}
static inline bool F_6 ( struct V_19 * V_20 )
{
if ( V_20 -> V_21 != 0 ) {
V_20 -> V_21 = F_7 ( V_20 -> V_21 ) ;
F_8 ( ( V_20 -> V_21 & V_22 ) == 0 ) ;
return true ;
} else {
return false ;
}
}
static inline void F_9 ( struct V_19 * V_20 )
{
V_20 -> V_21 = 0 ;
}
static int F_10 ( struct V_4 * V_5 ,
struct V_19 * V_20 )
{
T_2 V_23 , V_24 ;
F_11 ( V_20 , 4 ) ;
V_23 = ( V_20 -> V_25 >> V_26 ) &
V_27 ;
if ( ( ( V_20 -> V_28 == V_29 ) ||
( V_20 -> V_28 == V_30 ) ) &&
( V_20 -> V_31 == V_32 ) ) {
V_5 -> V_33 = V_23 ;
F_12 ( & V_5 -> V_34 ) ;
}
if ( V_23 == V_35 ) {
if ( ( ( V_20 -> V_28 == V_36 ) ||
( V_20 -> V_28 == V_37 ) ) &&
( V_20 -> V_31 == V_38 ) ) {
F_13 ( V_5 ) ;
V_5 -> V_39 = false ;
}
if ( V_20 -> V_28 ==
V_40 ) {
struct V_1 * V_41 =
F_14 ( & V_5 -> V_8 . V_9 ,
V_20 -> V_31 ) ;
struct V_42 * V_43 =
F_1 ( V_41 ) ;
V_5 -> V_44 . V_45 =
V_43 -> V_46 ;
}
} else {
if ( V_20 -> V_28 == V_40 )
V_47 = 0 ;
if ( V_23 == V_48 ||
V_23 == V_49 )
goto V_50;
if ( V_23 == V_51 ) {
F_15 ( & V_5 -> V_12 -> V_13 , L_2
L_3 ,
V_20 -> V_28 ) ;
} else {
V_24 = ( V_20 -> V_25 >> V_52 ) &
V_53 ;
F_16 ( & V_5 -> V_12 -> V_13 , L_4
L_5 ,
V_20 -> V_28 , V_23 , V_24 ) ;
}
}
V_50:
return V_23 ;
}
static void F_17 ( struct V_4 * V_5 ,
struct V_54 * V_55 )
{
F_18 ( V_5 , V_55 -> V_56 ) ;
}
static void F_19 ( struct V_4 * V_5 ,
struct V_57 * V_55 )
{
if ( V_55 -> V_58 ) {
V_5 -> V_59 = V_55 -> V_60 ;
V_5 -> V_61 &= ~ V_62 ;
V_5 -> V_61 =
V_55 -> V_63 << V_64 ;
}
}
static void F_20 ( struct V_4 * V_5 ,
struct V_65 * V_55 )
{
if ( V_55 -> V_66 == V_5 -> V_67 ) {
V_5 -> V_68 = V_55 -> V_69 * 10 ;
}
}
static void F_21 ( struct V_4 * V_5 ,
struct V_70 * V_55 )
{
if ( V_55 -> V_71 )
V_5 -> V_72 = F_22 ( V_55 -> V_73 ) & V_74 ;
else
V_5 -> V_72 = 0 ;
}
static void F_23 ( struct V_4 * V_5 ,
T_1 V_75 , struct V_19 * V_55 )
{
T_3 V_76 = 0 ;
V_76 = ( V_75 >> V_77 ) &
V_78 ;
switch ( V_76 ) {
case V_79 :
F_19 ( V_5 ,
(struct V_57 * ) V_55 ) ;
break;
case V_80 :
F_20 ( V_5 ,
(struct V_65 * ) V_55 ) ;
break;
case V_81 :
F_21 ( V_5 ,
(struct V_70 * ) V_55 ) ;
break;
default:
F_15 ( & V_5 -> V_12 -> V_13 , L_6 ) ;
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
static struct V_19 * F_26 ( struct V_4 * V_5 )
{
struct V_6 * V_86 = & V_5 -> V_8 . V_87 ;
struct V_19 * V_20 = F_27 ( V_86 ) ;
if ( F_6 ( V_20 ) ) {
F_28 ( V_86 ) ;
return V_20 ;
}
return NULL ;
}
void F_29 ( struct V_4 * V_5 )
{
F_30 ( & V_5 -> V_88 ) ;
F_31 ( V_5 , V_5 -> V_8 . V_87 . V_14 , true , 0 ) ;
V_5 -> V_8 . V_89 = true ;
F_32 ( & V_5 -> V_88 ) ;
}
void F_33 ( struct V_4 * V_5 )
{
V_5 -> V_8 . V_89 = false ;
}
int F_34 ( struct V_4 * V_5 , int * V_25 )
{
struct V_19 * V_20 ;
int V_90 = 0 ;
struct V_91 * V_8 = & V_5 -> V_8 ;
F_30 ( & V_5 -> V_88 ) ;
while ( ( V_20 = F_26 ( V_5 ) ) ) {
if ( V_20 -> V_21 & V_92 ) {
if ( F_24 ( V_20 -> V_21 ) )
F_17 ( V_5 ,
(struct V_54 * ) V_20 ) ;
else if ( F_25 ( V_20 -> V_21 ) )
F_23 ( V_5 ,
V_20 -> V_21 , V_20 ) ;
} else if ( V_20 -> V_21 & V_93 ) {
* V_25 = F_10 ( V_5 , V_20 ) ;
F_35 ( & V_8 -> V_9 . V_94 ) ;
}
F_9 ( V_20 ) ;
V_90 ++ ;
}
F_32 ( & V_5 -> V_88 ) ;
return V_90 ;
}
static int F_36 ( struct V_4 * V_5 )
{
#define F_37 120000
int V_95 , V_90 , V_25 = 0 ;
struct V_91 * V_8 = & V_5 -> V_8 ;
if ( V_5 -> V_11 )
return - V_96 ;
for ( V_95 = 0 ; V_95 < F_37 ; V_95 ++ ) {
V_90 = F_34 ( V_5 , & V_25 ) ;
if ( V_90 )
F_31 ( V_5 , V_8 -> V_87 . V_14 ,
V_8 -> V_89 , V_90 ) ;
if ( F_38 ( & V_8 -> V_9 . V_94 ) == 0 )
break;
F_39 ( 100 ) ;
}
if ( V_95 == F_37 ) {
F_16 ( & V_5 -> V_12 -> V_13 , L_7 ) ;
return - 1 ;
}
return V_25 ;
}
static int F_40 ( struct V_4 * V_5 )
{
F_2 ( V_5 ) ;
return F_36 ( V_5 ) ;
}
static int F_41 ( struct V_4 * V_5 , void T_4 * V_17 )
{
int V_97 = 0 ;
T_1 V_98 ;
if ( V_5 -> V_11 ) {
F_16 ( & V_5 -> V_12 -> V_13 ,
L_8 ) ;
return - V_96 ;
}
do {
V_98 = F_42 ( V_17 ) ;
if ( V_98 == 0xffffffff ) {
F_16 ( & V_5 -> V_12 -> V_13 ,
L_9 ) ;
return - 1 ;
}
V_98 &= V_99 ;
if ( V_98 )
break;
if ( V_97 > 4000 ) {
F_16 ( & V_5 -> V_12 -> V_13 , L_10 ) ;
F_43 ( V_5 ) ;
return - 1 ;
}
F_44 ( 1 ) ;
V_97 ++ ;
} while ( true );
return 0 ;
}
static int F_45 ( struct V_4 * V_5 )
{
int V_25 ;
T_1 V_10 = 0 ;
void T_4 * V_17 = V_5 -> V_17 + V_100 ;
struct V_101 * V_102 = & V_5 -> V_102 ;
struct V_103 * V_104 = V_102 -> V_105 ;
struct V_19 * V_20 = & V_104 -> V_20 ;
V_25 = F_41 ( V_5 , V_17 ) ;
if ( V_25 != 0 )
return V_25 ;
V_10 |= V_106 ;
V_10 |= ( F_46 ( V_102 -> V_107 ) >> 2 ) << 2 ;
F_5 ( V_10 , V_17 ) ;
V_25 = F_41 ( V_5 , V_17 ) ;
if ( V_25 != 0 )
return V_25 ;
V_10 = 0 ;
V_10 |= ( T_1 ) ( V_102 -> V_107 >> 4 ) << 2 ;
F_5 ( V_10 , V_17 ) ;
V_25 = F_41 ( V_5 , V_17 ) ;
if ( V_25 != 0 )
return V_25 ;
if ( F_6 ( V_20 ) ) {
V_25 = F_10 ( V_5 , & V_104 -> V_20 ) ;
F_9 ( V_20 ) ;
if ( V_25 )
return V_25 ;
} else {
F_16 ( & V_5 -> V_12 -> V_13 , L_11 ) ;
return - 1 ;
}
return 0 ;
}
static int F_47 ( struct V_4 * V_5 , T_2 * V_108 )
{
T_1 V_109 ;
if ( F_48 ( V_5 ) )
V_109 = F_42 ( V_5 -> V_17 + V_110 ) ;
else
V_109 = F_42 ( V_5 -> V_111 + V_112 ) ;
* V_108 = V_109 & V_113 ;
if ( ( V_109 >> V_114 ) & V_115 )
return - 1 ;
else
return 0 ;
}
int F_49 ( struct V_4 * V_5 )
{
T_2 V_108 ;
int V_25 , V_116 = 0 ;
struct V_117 * V_13 = & V_5 -> V_12 -> V_13 ;
do {
V_25 = F_47 ( V_5 , & V_108 ) ;
if ( V_25 ) {
F_16 ( V_13 , L_12 , V_108 ) ;
return - 1 ;
} else if ( V_108 != V_118 ) {
if ( F_50 ( 2000 ) ) {
F_16 ( V_13 , L_13 ) ;
return - V_119 ;
}
V_116 += 2 ;
} else {
return 0 ;
}
} while ( V_116 < 60 );
F_16 ( V_13 , L_14 , V_108 ) ;
return - 1 ;
}
static inline struct V_120 * F_51 ( struct V_1 * V_2 )
{
return & V_2 -> V_3 . V_121 [ 0 ] ;
}
static void F_52 ( struct V_122 * V_123 ,
T_3 V_124 , T_3 V_125 , int V_126 ,
struct V_1 * V_2 , struct V_101 * V_127 )
{
struct V_120 * V_128 ;
V_123 -> V_125 = V_125 ;
V_123 -> V_124 = V_124 ;
V_123 -> V_129 = F_53 ( V_126 - sizeof( * V_123 ) ) ;
V_123 -> V_130 = 0 ;
V_2 -> V_28 = V_125 ;
V_2 -> V_31 = V_124 ;
V_2 -> V_131 = V_126 ;
if ( V_127 ) {
V_2 -> V_132 |= ( 1 & V_133 ) <<
V_134 ;
V_128 = F_51 ( V_2 ) ;
V_128 -> V_135 = F_53 ( F_46 ( V_127 -> V_107 ) ) ;
V_128 -> V_136 = F_53 ( V_127 -> V_107 & 0xFFFFFFFF ) ;
V_128 -> V_137 = F_53 ( V_127 -> V_138 ) ;
} else
V_2 -> V_132 |= V_139 ;
F_54 ( V_2 , 8 ) ;
}
static void F_55 ( struct V_140 * V_141 , T_1 V_142 ,
struct V_101 * V_127 )
{
int V_95 , V_143 = F_56 ( F_57 ( V_127 -> V_105 , V_127 -> V_138 ) , V_142 ) ;
T_5 V_107 = ( T_5 ) V_127 -> V_107 ;
for ( V_95 = 0 ; V_95 < V_143 ; V_95 ++ ) {
V_141 [ V_95 ] . V_144 = F_53 ( V_107 & 0xFFFFFFFF ) ;
V_141 [ V_95 ] . V_145 = F_53 ( F_46 ( V_107 ) ) ;
V_107 += V_146 ;
}
}
static T_1 F_58 ( T_1 V_147 )
{
#define F_59 651042
const T_1 V_148 = 10 ;
T_1 V_149 ;
if ( V_147 == 0 )
V_149 = 0 ;
else {
T_1 V_150 = 1000000 / V_147 ;
if ( V_150 == 0 )
V_149 = 1023 ;
else {
V_149 = ( F_59 - V_150 ) * V_148 ;
V_149 /= V_150 ;
V_149 = ( V_149 + V_148 / 2 ) / V_148 ;
V_149 = F_56 ( V_149 , ( T_1 ) 1023 ) ;
}
}
return V_149 ;
}
static inline struct V_1 * F_60 ( struct V_4 * V_5 )
{
struct V_101 * V_102 = & V_5 -> V_102 ;
struct V_1 * V_2
= & ( (struct V_103 * ) ( V_102 -> V_105 ) ) -> V_2 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
return V_2 ;
}
static struct V_1 * F_61 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 . V_9 ;
struct V_1 * V_2 ;
if ( F_38 ( & V_7 -> V_94 ) >= V_7 -> V_137 ) {
F_16 ( & V_5 -> V_12 -> V_13 , L_15 ) ;
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
int V_25 ;
if ( F_66 ( & V_5 -> V_151 ) )
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
V_25 = F_45 ( V_5 ) ;
F_67 ( & V_5 -> V_151 ) ;
return V_25 ;
}
int F_68 ( struct V_4 * V_5 )
{
T_3 * V_2 ;
int V_25 ;
if ( V_5 -> V_11 )
return - V_96 ;
if ( F_66 ( & V_5 -> V_151 ) )
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
V_25 = F_45 ( V_5 ) ;
F_67 ( & V_5 -> V_151 ) ;
return V_25 ;
}
int F_69 ( struct V_4 * V_5 ,
struct V_6 * V_152 , int V_153 )
{
struct V_1 * V_2 ;
struct V_154 * V_155 ;
struct V_101 * V_156 = & V_152 -> V_157 ;
int V_25 ;
if ( F_66 ( & V_5 -> V_151 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_159 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_160 = F_70 ( F_57 ( V_156 -> V_105 , V_156 -> V_138 ) ) ;
F_71 ( struct V_161 , V_58 , V_155 -> V_162 , 1 ) ;
F_71 ( struct V_161 , V_138 , V_155 -> V_162 , 0 ) ;
F_71 ( struct V_161 , V_163 , V_155 -> V_162 ,
F_72 ( V_152 -> V_137 / 256 ) ) ;
F_71 ( struct V_161 , V_164 , V_155 -> V_162 ,
F_58 ( V_153 ) ) ;
F_54 ( V_155 -> V_162 , sizeof( V_155 -> V_162 ) ) ;
F_55 ( V_155 -> V_141 , F_73 ( V_155 -> V_141 ) , V_156 ) ;
V_25 = F_45 ( V_5 ) ;
if ( ! V_25 ) {
struct V_165 * V_43 = F_1 ( V_2 ) ;
V_152 -> V_14 = F_22 ( V_43 -> V_166 ) ;
V_152 -> V_167 = true ;
}
F_67 ( & V_5 -> V_151 ) ;
return V_25 ;
}
int F_74 ( struct V_4 * V_5 , T_3 * V_168 ,
T_3 type , bool V_169 , T_1 V_170 )
{
struct V_1 * V_2 ;
struct V_171 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_175 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> type = type ;
if ( V_169 ) {
V_155 -> V_169 = 1 ;
} else {
V_155 -> V_176 = F_70 ( ( T_2 ) V_170 ) ;
V_155 -> V_169 = 0 ;
}
V_25 = F_40 ( V_5 ) ;
if ( ! V_25 ) {
struct V_177 * V_43 = F_1 ( V_2 ) ;
memcpy ( V_168 , V_43 -> V_178 . V_179 , V_180 ) ;
}
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_75 ( struct V_4 * V_5 , T_3 * V_168 ,
T_1 V_176 , T_1 * V_181 , T_1 V_182 )
{
struct V_1 * V_2 ;
struct V_183 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_184 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_158 . V_182 = V_182 ;
V_155 -> V_176 = F_53 ( V_176 ) ;
memcpy ( V_155 -> V_185 , V_168 , V_180 ) ;
V_25 = F_40 ( V_5 ) ;
if ( ! V_25 ) {
struct V_186 * V_43 = F_1 ( V_2 ) ;
* V_181 = F_7 ( V_43 -> V_181 ) ;
}
V_174:
F_32 ( & V_5 -> V_172 ) ;
if ( V_25 == V_51 )
V_25 = - V_187 ;
return V_25 ;
}
int F_76 ( struct V_4 * V_5 , T_1 V_176 , T_1 V_181 , T_1 V_188 )
{
struct V_1 * V_2 ;
struct V_189 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_190 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_158 . V_182 = V_188 ;
V_155 -> V_176 = F_53 ( V_176 ) ;
V_155 -> V_181 = F_53 ( V_181 ) ;
V_25 = F_40 ( V_5 ) ;
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_77 ( struct V_4 * V_5 ,
struct V_6 * V_87 , struct V_6 * V_152 ,
bool V_191 , bool V_192 , int V_193 )
{
struct V_1 * V_2 ;
struct V_194 * V_155 ;
struct V_101 * V_156 = & V_87 -> V_157 ;
void * V_195 ;
int V_25 ;
if ( F_66 ( & V_5 -> V_151 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
V_155 = F_1 ( V_2 ) ;
V_195 = & V_155 -> V_162 ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_196 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_160 = F_70 ( F_57 ( V_156 -> V_105 , V_156 -> V_138 ) ) ;
if ( F_48 ( V_5 ) ) {
V_155 -> V_158 . V_130 = 2 ;
V_155 -> V_197 = 1 ;
F_71 ( struct V_198 , V_199 , V_195 ,
V_192 ) ;
F_71 ( struct V_198 , V_163 , V_195 ,
F_72 ( V_87 -> V_137 / 256 ) ) ;
F_71 ( struct V_198 , V_58 , V_195 , 1 ) ;
F_71 ( struct V_198 , V_200 ,
V_195 , 1 ) ;
F_71 ( struct V_198 , V_201 ,
V_195 , V_152 -> V_14 ) ;
F_71 ( struct V_198 , V_202 , V_195 , 1 ) ;
} else {
F_71 ( struct V_203 , V_204 , V_195 ,
V_193 ) ;
F_71 ( struct V_203 , V_199 ,
V_195 , V_192 ) ;
F_71 ( struct V_203 , V_163 , V_195 ,
F_72 ( V_87 -> V_137 / 256 ) ) ;
F_71 ( struct V_203 , V_58 , V_195 , 1 ) ;
F_71 ( struct V_203 , V_205 ,
V_195 , V_191 ) ;
F_71 ( struct V_203 , V_200 , V_195 , 1 ) ;
F_71 ( struct V_203 , V_201 , V_195 , V_152 -> V_14 ) ;
F_71 ( struct V_203 , V_202 , V_195 , 1 ) ;
}
F_54 ( V_195 , sizeof( V_155 -> V_162 ) ) ;
F_55 ( V_155 -> V_141 , F_73 ( V_155 -> V_141 ) , V_156 ) ;
V_25 = F_45 ( V_5 ) ;
if ( ! V_25 ) {
struct V_206 * V_43 = F_1 ( V_2 ) ;
V_87 -> V_14 = F_22 ( V_43 -> V_207 ) ;
V_87 -> V_167 = true ;
}
F_67 ( & V_5 -> V_151 ) ;
return V_25 ;
}
static T_1 F_78 ( int V_208 )
{
T_1 V_209 = F_79 ( V_208 ) ;
if ( V_209 == 16 )
V_209 = 0 ;
return V_209 ;
}
int F_80 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_87 )
{
struct V_1 * V_2 ;
struct V_210 * V_155 ;
struct V_101 * V_156 = & V_7 -> V_157 ;
void * V_195 ;
int V_25 ;
if ( F_66 ( & V_5 -> V_151 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
V_155 = F_1 ( V_2 ) ;
V_195 = & V_155 -> V_162 ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_211 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_160 = F_70 ( F_57 ( V_156 -> V_105 , V_156 -> V_138 ) ) ;
if ( F_48 ( V_5 ) ) {
V_155 -> V_158 . V_130 = 1 ;
V_155 -> V_207 = F_70 ( V_87 -> V_14 ) ;
F_71 ( struct V_212 , V_213 , V_195 ,
F_78 ( V_7 -> V_137 ) ) ;
F_71 ( struct V_212 , V_58 , V_195 , 1 ) ;
F_71 ( struct V_212 , V_214 ,
V_195 , V_87 -> V_14 ) ;
F_71 ( struct V_212 , V_215 ,
V_195 , 1 ) ;
} else {
F_71 ( struct V_216 , V_58 , V_195 , 1 ) ;
F_71 ( struct V_216 , V_213 , V_195 ,
F_78 ( V_7 -> V_137 ) ) ;
F_71 ( struct V_216 , V_207 , V_195 , V_87 -> V_14 ) ;
}
V_155 -> V_217 [ 0 ] = F_53 ( 0x00000022 ) ;
F_54 ( V_195 , sizeof( V_155 -> V_162 ) ) ;
F_55 ( V_155 -> V_141 , F_73 ( V_155 -> V_141 ) , V_156 ) ;
V_25 = F_45 ( V_5 ) ;
if ( ! V_25 ) {
struct V_218 * V_43 = F_1 ( V_2 ) ;
V_7 -> V_14 = F_22 ( V_43 -> V_14 ) ;
V_7 -> V_167 = true ;
}
F_67 ( & V_5 -> V_151 ) ;
return V_25 ;
}
int F_81 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_87 )
{
struct V_1 * V_2 ;
struct V_219 * V_155 ;
struct V_101 * V_156 = & V_7 -> V_157 ;
void * V_195 ;
int V_25 ;
if ( F_66 ( & V_5 -> V_151 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
V_155 = F_1 ( V_2 ) ;
V_195 = & V_155 -> V_162 ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_220 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_160 = F_70 ( F_57 ( V_156 -> V_105 , V_156 -> V_138 ) ) ;
F_71 ( struct V_216 , V_58 , V_195 , 1 ) ;
F_71 ( struct V_216 , V_213 , V_195 ,
F_78 ( V_7 -> V_137 ) ) ;
F_71 ( struct V_216 , V_207 , V_195 , V_87 -> V_14 ) ;
F_54 ( V_195 , sizeof( V_155 -> V_162 ) ) ;
F_55 ( V_155 -> V_141 , F_73 ( V_155 -> V_141 ) , V_156 ) ;
V_25 = F_45 ( V_5 ) ;
if ( ! V_25 ) {
struct V_218 * V_43 = F_1 ( V_2 ) ;
V_7 -> V_14 = F_22 ( V_43 -> V_14 ) ;
V_7 -> V_167 = true ;
}
F_67 ( & V_5 -> V_151 ) ;
return V_25 ;
}
int F_82 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_87 )
{
int V_25 ;
V_25 = F_80 ( V_5 , V_7 , V_87 ) ;
if ( V_25 && ! F_48 ( V_5 ) ) {
F_15 ( & V_5 -> V_12 -> V_13 , L_16
L_17
L_18 ) ;
V_25 = F_81 ( V_5 , V_7 , V_87 ) ;
}
return V_25 ;
}
int F_83 ( struct V_4 * V_5 ,
struct V_6 * V_221 ,
struct V_6 * V_87 )
{
struct V_1 * V_2 ;
struct V_222 * V_155 ;
struct V_101 * V_156 = & V_221 -> V_157 ;
void * V_195 ;
int V_25 ;
if ( F_66 ( & V_5 -> V_151 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
V_155 = F_1 ( V_2 ) ;
V_195 = & V_155 -> V_162 ;
F_52 ( & V_155 -> V_158 , V_38 ,
V_223 , sizeof( * V_155 ) , V_2 , NULL ) ;
if ( F_48 ( V_5 ) ) {
V_155 -> V_158 . V_130 = 1 ;
F_71 ( struct V_224 , V_176 , V_195 ,
V_5 -> V_170 ) ;
}
V_155 -> V_160 = F_57 ( V_156 -> V_105 , V_156 -> V_138 ) ;
V_155 -> V_225 = V_226 ;
V_155 -> type = V_227 ;
F_71 ( struct V_224 , V_228 , V_195 ,
F_78 ( V_221 -> V_137 ) ) ;
F_71 ( struct V_224 , V_229 , V_195 , 1 ) ;
F_71 ( struct V_224 , V_230 , V_195 , V_87 -> V_14 ) ;
F_54 ( V_195 , sizeof( V_155 -> V_162 ) ) ;
F_55 ( V_155 -> V_141 , F_73 ( V_155 -> V_141 ) , V_156 ) ;
V_25 = F_45 ( V_5 ) ;
if ( ! V_25 ) {
struct V_231 * V_43 = F_1 ( V_2 ) ;
V_221 -> V_14 = F_22 ( V_43 -> V_232 ) ;
V_221 -> V_167 = true ;
}
F_67 ( & V_5 -> V_151 ) ;
return V_25 ;
}
int F_84 ( struct V_4 * V_5 ,
struct V_6 * V_233 , T_2 V_207 , T_2 V_234 ,
T_2 V_235 , T_1 V_176 , T_1 V_236 , T_3 * V_237 )
{
struct V_1 * V_2 ;
struct V_238 * V_155 ;
struct V_101 * V_156 = & V_233 -> V_157 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_38 ,
V_239 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_207 = F_70 ( V_207 ) ;
V_155 -> V_234 = F_79 ( V_234 ) - 1 ;
V_155 -> V_160 = 2 ;
F_55 ( V_155 -> V_141 , F_73 ( V_155 -> V_141 ) , V_156 ) ;
V_155 -> V_240 = F_53 ( V_176 ) ;
V_155 -> V_235 = F_70 ( V_235 ) ;
V_155 -> V_241 = F_53 ( V_236 ) ;
V_25 = F_40 ( V_5 ) ;
if ( ! V_25 ) {
struct V_242 * V_43 = F_1 ( V_2 ) ;
V_233 -> V_14 = F_22 ( V_43 -> V_14 ) ;
V_233 -> V_167 = true ;
* V_237 = V_43 -> V_237 ;
}
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_85 ( struct V_4 * V_5 , struct V_6 * V_9 ,
int V_243 )
{
struct V_1 * V_2 ;
struct V_244 * V_155 ;
T_3 V_245 = 0 , V_125 = 0 ;
int V_25 ;
if ( V_5 -> V_11 )
return - V_96 ;
if ( F_66 ( & V_5 -> V_151 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
V_155 = F_1 ( V_2 ) ;
switch ( V_243 ) {
case V_246 :
V_245 = V_32 ;
V_125 = V_247 ;
break;
case V_248 :
V_245 = V_32 ;
V_125 = V_249 ;
break;
case V_250 :
V_245 = V_38 ;
V_125 = V_251 ;
break;
case V_252 :
V_245 = V_38 ;
V_125 = V_253 ;
break;
case V_254 :
V_245 = V_32 ;
V_125 = V_255 ;
break;
default:
F_86 () ;
}
F_52 ( & V_155 -> V_158 , V_245 , V_125 , sizeof( * V_155 ) , V_2 ,
NULL ) ;
V_155 -> V_14 = F_70 ( V_9 -> V_14 ) ;
V_25 = F_45 ( V_5 ) ;
if ( ! V_25 )
V_9 -> V_167 = false ;
F_67 ( & V_5 -> V_151 ) ;
return V_25 ;
}
int F_87 ( struct V_4 * V_5 , struct V_6 * V_9 )
{
struct V_1 * V_2 ;
struct V_244 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_38 ,
V_253 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_14 = F_70 ( V_9 -> V_14 ) ;
V_25 = F_40 ( V_5 ) ;
if ( ! V_25 )
V_9 -> V_167 = false ;
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_88 ( struct V_4 * V_5 , T_1 V_256 , T_1 V_257 ,
T_3 * V_178 , T_1 * V_170 , T_1 * V_181 , T_1 V_182 )
{
struct V_1 * V_2 ;
struct V_258 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_259 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_158 . V_182 = V_182 ;
V_155 -> V_260 = F_53 ( V_256 ) ;
V_155 -> V_261 = F_53 ( V_257 ) ;
if ( V_178 )
memcpy ( V_155 -> V_168 , V_178 , V_180 ) ;
else
V_155 -> V_262 = true ;
V_25 = F_40 ( V_5 ) ;
if ( ! V_25 ) {
struct V_263 * V_43 = F_1 ( V_2 ) ;
* V_170 = F_7 ( V_43 -> V_240 ) ;
if ( V_178 )
* V_181 = F_7 ( V_43 -> V_181 ) ;
}
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_89 ( struct V_4 * V_5 , T_1 V_240 , T_1 V_182 )
{
struct V_1 * V_2 ;
struct V_264 * V_155 ;
int V_25 ;
if ( V_5 -> V_11 )
return - V_96 ;
if ( ! V_240 )
return 0 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_265 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_158 . V_182 = V_182 ;
V_155 -> V_240 = F_53 ( V_240 ) ;
V_25 = F_40 ( V_5 ) ;
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_90 ( struct V_4 * V_5 , struct V_101 * V_266 )
{
struct V_1 * V_2 ;
struct V_122 * V_158 ;
int V_25 = 0 ;
if ( F_91 ( V_5 -> V_267 , V_47 ) == 0 )
F_92 ( V_5 ) ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_158 = V_266 -> V_105 ;
F_52 ( V_158 , V_38 ,
V_36 , V_266 -> V_138 , V_2 , V_266 ) ;
if ( V_5 -> V_268 == V_269 )
V_158 -> V_130 = 1 ;
F_2 ( V_5 ) ;
V_5 -> V_39 = true ;
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_93 ( struct V_4 * V_5 ,
struct V_101 * V_266 )
{
struct V_1 * V_2 ;
struct V_270 * V_155 ;
int V_25 = 0 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = V_266 -> V_105 ;
F_52 ( & V_155 -> V_158 , V_38 ,
V_37 , V_266 -> V_138 , V_2 ,
V_266 ) ;
V_155 -> V_271 . V_272 . V_273 = F_70 ( V_5 -> V_67 ) ;
V_155 -> V_271 . V_272 . V_274 = 0 ;
F_2 ( V_5 ) ;
V_5 -> V_39 = true ;
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_94 ( struct V_4 * V_5 , T_3 * V_275 ,
T_2 * V_68 , T_1 V_188 )
{
struct V_1 * V_2 ;
struct V_276 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_277 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_25 = F_40 ( V_5 ) ;
if ( ! V_25 ) {
struct V_278 * V_43 = F_1 ( V_2 ) ;
if ( V_43 -> V_275 != V_279 ) {
* V_68 = F_22 ( V_43 -> V_68 ) ;
if ( V_275 )
* V_275 = V_43 -> V_275 ;
}
}
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_92 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_280 * V_155 ;
T_2 V_281 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_281 = V_5 -> V_8 . V_9 . V_282 ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_40 , sizeof( * V_155 ) ,
V_2 , NULL ) ;
V_2 -> V_31 = V_281 ;
F_2 ( V_5 ) ;
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_95 ( struct V_4 * V_5 , T_1 * V_283 )
{
struct V_1 * V_2 ;
struct V_284 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_285 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_286 = F_53 ( V_287 ) ;
V_25 = F_40 ( V_5 ) ;
if ( ! V_25 ) {
struct V_288 * V_43 = F_1 ( V_2 ) ;
if ( V_283 && V_43 -> V_283 )
* V_283 = F_7 ( V_43 -> V_283 ) -
sizeof( T_1 ) ;
}
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
void F_96 ( struct V_4 * V_5 , T_1 V_289 , void * V_290 )
{
struct V_101 V_291 ;
struct V_1 * V_2 ;
struct V_284 * V_155 ;
T_1 V_292 = 0 , V_293 , V_294 ,
V_295 = sizeof( T_1 ) , V_296 ;
int V_25 ;
if ( V_289 == 0 )
return;
V_293 = V_289 ;
V_291 . V_138 = sizeof( struct V_284 ) + 60 * 1024 ;
V_291 . V_105 = F_97 ( V_5 -> V_12 ,
V_291 . V_138 ,
& V_291 . V_107 ) ;
if ( ! V_291 . V_105 ) {
V_25 = - V_297 ;
F_16 ( & V_5 -> V_12 -> V_13 ,
L_19 ) ;
return;
}
F_30 ( & V_5 -> V_172 ) ;
while ( V_293 ) {
V_294 = F_56 ( V_293 , ( T_1 ) 60 * 1024 ) ;
V_293 -= V_294 ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = V_291 . V_105 ;
V_296 = sizeof( struct V_284 ) + V_294 ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_285 , V_296 , V_2 ,
& V_291 ) ;
V_155 -> V_286 = F_53 ( V_298 ) ;
V_155 -> V_299 = F_53 ( V_295 ) ;
V_155 -> V_300 = F_53 ( V_294 ) ;
V_155 -> V_301 = F_53 ( V_294 ) ;
V_25 = F_40 ( V_5 ) ;
if ( ! V_25 ) {
struct V_288 * V_43 = V_291 . V_105 ;
memcpy ( V_290 + V_292 ,
V_43 -> V_302 ,
F_7 ( V_43 -> V_300 ) ) ;
} else {
F_16 ( & V_5 -> V_12 -> V_13 , L_20 ) ;
goto V_174;
}
V_292 += V_294 ;
V_295 += V_294 ;
}
V_174:
F_98 ( V_5 -> V_12 , V_291 . V_138 ,
V_291 . V_105 ,
V_291 . V_107 ) ;
F_32 ( & V_5 -> V_172 ) ;
}
int F_99 ( struct V_4 * V_5 , char * V_303 ,
char * V_304 )
{
struct V_1 * V_2 ;
struct V_305 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_306 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_25 = F_40 ( V_5 ) ;
if ( ! V_25 ) {
struct V_307 * V_43 = F_1 ( V_2 ) ;
strcpy ( V_303 , V_43 -> V_308 ) ;
if ( V_304 )
strcpy ( V_304 , V_43 -> V_309 ) ;
}
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_100 ( struct V_4 * V_5 , T_1 V_166 , T_1 V_310 )
{
struct V_1 * V_2 ;
struct V_311 * V_155 ;
int V_25 = 0 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_312 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_313 = F_53 ( 1 ) ;
V_155 -> V_314 [ 0 ] . V_166 = F_53 ( V_166 ) ;
V_155 -> V_314 [ 0 ] . V_315 = 0 ;
V_155 -> V_314 [ 0 ] . V_316 = F_53 ( V_310 ) ;
F_2 ( V_5 ) ;
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_101 ( struct V_4 * V_5 , T_1 V_176 , T_2 * V_317 ,
T_1 V_90 , bool V_318 , bool V_319 )
{
struct V_1 * V_2 ;
struct V_320 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_321 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_240 = V_176 ;
V_155 -> V_319 = V_319 ;
V_155 -> V_318 = V_318 ;
V_155 -> V_322 = V_90 ;
if ( ! V_319 ) {
memcpy ( V_155 -> V_323 , V_317 ,
V_155 -> V_322 * sizeof( V_317 [ 0 ] ) ) ;
}
V_25 = F_40 ( V_5 ) ;
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_102 ( struct V_4 * V_5 , T_1 V_21 , T_1 V_324 )
{
struct V_1 * V_2 ;
struct V_101 * V_127 = & V_5 -> V_325 ;
struct V_326 * V_155 = V_127 -> V_105 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
memset ( V_155 , 0 , sizeof( * V_155 ) ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_327 , sizeof( * V_155 ) ,
V_2 , V_127 ) ;
V_155 -> V_176 = F_53 ( V_5 -> V_170 ) ;
if ( V_21 & V_328 ) {
V_155 -> V_329 = F_53 ( V_330 |
V_331 ) ;
if ( V_324 == V_332 )
V_155 -> V_333 = F_53 ( V_330 |
V_331 ) ;
} else if ( V_21 & V_334 ) {
V_155 -> V_329 = V_155 -> V_333 =
F_53 ( V_335 ) ;
} else {
struct V_336 * V_337 ;
int V_95 = 0 ;
V_155 -> V_329 = V_155 -> V_333 =
F_53 ( V_338 ) ;
V_155 -> V_329 |=
F_53 ( V_335 ) ;
V_155 -> V_339 = F_53 ( F_103 ( V_5 -> V_340 ) ) ;
F_104 (ha, adapter->netdev)
memcpy ( V_155 -> V_341 [ V_95 ++ ] . V_342 , V_337 -> V_179 , V_180 ) ;
}
V_25 = F_40 ( V_5 ) ;
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_105 ( struct V_4 * V_5 , T_1 V_343 , T_1 V_344 )
{
struct V_1 * V_2 ;
struct V_345 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_346 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_347 = F_70 ( ( T_2 ) V_343 ) ;
V_155 -> V_348 = F_70 ( ( T_2 ) V_344 ) ;
V_25 = F_40 ( V_5 ) ;
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_106 ( struct V_4 * V_5 , T_1 * V_343 , T_1 * V_344 )
{
struct V_1 * V_2 ;
struct V_349 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_350 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_25 = F_40 ( V_5 ) ;
if ( ! V_25 ) {
struct V_351 * V_43 =
F_1 ( V_2 ) ;
* V_343 = F_22 ( V_43 -> V_347 ) ;
* V_344 = F_22 ( V_43 -> V_348 ) ;
}
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_107 ( struct V_4 * V_5 , T_1 * V_67 ,
T_1 * V_352 , T_1 * V_353 )
{
struct V_1 * V_2 ;
struct V_354 * V_155 ;
int V_25 ;
if ( F_66 ( & V_5 -> V_151 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_355 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_25 = F_45 ( V_5 ) ;
if ( ! V_25 ) {
struct V_356 * V_43 = F_1 ( V_2 ) ;
* V_67 = F_7 ( V_43 -> V_357 ) ;
* V_352 = F_7 ( V_43 -> V_358 ) ;
* V_353 = F_7 ( V_43 -> V_359 ) ;
}
F_67 ( & V_5 -> V_151 ) ;
return V_25 ;
}
int F_108 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_122 * V_155 ;
int V_25 ;
if ( F_66 ( & V_5 -> V_151 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
V_155 = F_1 ( V_2 ) ;
F_52 ( V_155 , V_32 ,
V_360 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_25 = F_45 ( V_5 ) ;
F_67 ( & V_5 -> V_151 ) ;
return V_25 ;
}
int F_109 ( struct V_4 * V_5 , T_3 * V_361 , T_2 V_362 )
{
struct V_1 * V_2 ;
struct V_363 * V_155 ;
T_1 V_364 [ 10 ] = { 0x0123 , 0x4567 , 0x89AB , 0xCDEF , 0x01EF ,
0x0123 , 0x4567 , 0x89AB , 0xCDEF , 0x01EF } ;
int V_25 ;
if ( F_66 ( & V_5 -> V_151 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_38 ,
V_365 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_176 = F_53 ( V_5 -> V_170 ) ;
V_155 -> V_366 = F_70 ( V_367 | V_368 ) ;
V_155 -> V_369 = F_70 ( F_79 ( V_362 ) - 1 ) ;
memcpy ( V_155 -> V_370 , V_361 , V_362 ) ;
memcpy ( V_155 -> V_371 , V_364 , sizeof( V_364 ) ) ;
F_54 ( V_155 -> V_371 , sizeof( V_155 -> V_371 ) ) ;
V_25 = F_45 ( V_5 ) ;
F_67 ( & V_5 -> V_151 ) ;
return V_25 ;
}
int F_110 ( struct V_4 * V_5 , T_3 V_67 ,
T_3 V_372 , T_3 V_373 , T_3 V_374 )
{
struct V_1 * V_2 ;
struct V_375 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_376 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_67 = V_67 ;
V_155 -> V_377 = V_374 ;
V_155 -> V_378 = V_372 ;
V_155 -> V_379 = V_373 ;
V_25 = F_40 ( V_5 ) ;
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_111 ( struct V_4 * V_5 , T_3 V_67 , T_1 * V_374 )
{
struct V_1 * V_2 ;
struct V_380 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_381 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_67 = V_67 ;
V_25 = F_40 ( V_5 ) ;
if ( ! V_25 ) {
struct V_382 * V_43 =
F_1 ( V_2 ) ;
* V_374 = V_43 -> V_377 ;
}
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_112 ( struct V_4 * V_5 , struct V_101 * V_383 ,
T_1 V_384 , T_1 V_385 , const char * V_386 ,
T_1 * V_387 , T_3 * V_388 )
{
struct V_1 * V_2 ;
struct V_389 * V_155 ;
struct V_390 * V_43 ;
void * V_195 = NULL ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_5 -> V_33 = 0 ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_391;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_30 ,
sizeof( struct V_389 ) , V_2 ,
NULL ) ;
V_195 = & V_155 -> V_162 ;
F_71 ( struct V_392 ,
V_393 , V_195 , V_384 ) ;
if ( V_384 == 0 )
F_71 ( struct V_392 ,
V_394 , V_195 , 1 ) ;
else
F_71 ( struct V_392 ,
V_394 , V_195 , 0 ) ;
F_54 ( V_195 , sizeof( V_155 -> V_162 ) ) ;
V_155 -> V_395 = F_53 ( V_385 ) ;
strcpy ( V_155 -> V_396 , V_386 ) ;
V_155 -> V_397 = F_53 ( 1 ) ;
V_155 -> V_289 = F_53 ( V_384 ) ;
V_155 -> V_398 = F_53 ( ( V_383 -> V_107 +
sizeof( struct V_389 ) )
& 0xFFFFFFFF ) ;
V_155 -> V_399 = F_53 ( F_46 ( V_383 -> V_107 +
sizeof( struct V_389 ) ) ) ;
F_2 ( V_5 ) ;
F_32 ( & V_5 -> V_172 ) ;
if ( ! F_113 ( & V_5 -> V_34 ,
F_114 ( 12000 ) ) )
V_25 = - 1 ;
else
V_25 = V_5 -> V_33 ;
V_43 = F_1 ( V_2 ) ;
if ( ! V_25 ) {
* V_387 = F_7 ( V_43 -> V_400 ) ;
} else {
* V_388 = V_43 -> V_401 ;
V_25 = V_43 -> V_25 ;
}
return V_25 ;
V_391:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_115 ( struct V_4 * V_5 , struct V_101 * V_383 ,
T_1 V_402 , T_1 V_403 , T_1 V_294 )
{
struct V_1 * V_2 ;
struct F_115 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_5 -> V_33 = 0 ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_391;
}
V_155 = V_383 -> V_105 ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_29 , V_383 -> V_138 , V_2 , V_383 ) ;
V_155 -> V_272 . V_404 = F_53 ( V_402 ) ;
V_155 -> V_272 . V_405 = F_53 ( V_403 ) ;
V_155 -> V_272 . V_406 = F_53 ( V_294 ) ;
F_2 ( V_5 ) ;
F_32 ( & V_5 -> V_172 ) ;
if ( ! F_113 ( & V_5 -> V_34 ,
F_114 ( 40000 ) ) )
V_25 = - 1 ;
else
V_25 = V_5 -> V_33 ;
return V_25 ;
V_391:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_116 ( struct V_4 * V_5 , T_3 * V_407 ,
int V_292 )
{
struct V_1 * V_2 ;
struct F_115 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_408 , sizeof( * V_155 ) + 4 , V_2 , NULL ) ;
V_155 -> V_272 . V_404 = F_53 ( V_409 ) ;
V_155 -> V_272 . V_405 = F_53 ( V_410 ) ;
V_155 -> V_272 . V_292 = F_53 ( V_292 ) ;
V_155 -> V_272 . V_406 = F_53 ( 0x4 ) ;
V_25 = F_40 ( V_5 ) ;
if ( ! V_25 )
memcpy ( V_407 , V_155 -> V_272 . V_411 , 4 ) ;
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_117 ( struct V_4 * V_5 , T_3 * V_178 ,
struct V_101 * V_266 )
{
struct V_1 * V_2 ;
struct V_412 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = V_266 -> V_105 ;
F_52 ( & V_155 -> V_158 , V_38 ,
V_413 , sizeof( * V_155 ) , V_2 ,
V_266 ) ;
memcpy ( V_155 -> V_414 , V_178 , V_180 ) ;
V_25 = F_40 ( V_5 ) ;
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_118 ( struct V_4 * V_5 , T_3 V_67 ,
T_3 V_415 , T_3 V_416 )
{
struct V_1 * V_2 ;
struct V_417 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_418 ,
V_419 , sizeof( * V_155 ) , V_2 ,
NULL ) ;
V_155 -> V_420 = V_67 ;
V_155 -> V_421 = V_67 ;
V_155 -> V_415 = V_415 ;
V_155 -> V_422 = V_416 ;
V_25 = F_40 ( V_5 ) ;
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_119 ( struct V_4 * V_5 , T_1 V_67 ,
T_1 V_415 , T_1 V_423 , T_1 V_424 , T_5 V_425 )
{
struct V_1 * V_2 ;
struct V_426 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_418 ,
V_427 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_158 . V_116 = F_53 ( 4 ) ;
V_155 -> V_425 = F_120 ( V_425 ) ;
V_155 -> V_420 = F_53 ( V_67 ) ;
V_155 -> V_421 = F_53 ( V_67 ) ;
V_155 -> V_423 = F_53 ( V_423 ) ;
V_155 -> V_424 = F_53 ( V_424 ) ;
V_155 -> V_415 = F_53 ( V_415 ) ;
V_25 = F_40 ( V_5 ) ;
if ( ! V_25 ) {
struct V_428 * V_43 = F_1 ( V_2 ) ;
V_25 = F_7 ( V_43 -> V_25 ) ;
}
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_121 ( struct V_4 * V_5 , T_5 V_425 ,
T_1 V_429 , struct V_101 * V_383 )
{
struct V_1 * V_2 ;
struct V_430 * V_155 ;
int V_25 ;
int V_95 , V_431 = 0 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = V_383 -> V_105 ;
F_52 ( & V_155 -> V_158 , V_418 ,
V_432 , V_383 -> V_138 , V_2 , V_383 ) ;
V_155 -> V_425 = F_120 ( V_425 ) ;
V_155 -> V_433 = F_53 ( V_429 ) ;
for ( V_95 = 0 ; V_95 < V_429 ; V_95 ++ ) {
V_155 -> V_434 [ V_95 ] = ( T_3 ) ( V_425 >> ( V_431 * 8 ) ) ;
V_431 ++ ;
if ( V_431 > 7 )
V_431 = 0 ;
}
V_25 = F_40 ( V_5 ) ;
if ( ! V_25 ) {
struct V_435 * V_43 ;
V_43 = V_383 -> V_105 ;
if ( ( memcmp ( V_43 -> V_436 , V_155 -> V_434 , V_429 ) != 0 ) ||
V_43 -> V_437 ) {
V_25 = - 1 ;
}
}
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_122 ( struct V_4 * V_5 ,
struct V_101 * V_266 )
{
struct V_1 * V_2 ;
struct V_438 * V_155 ;
struct V_120 * V_128 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = V_266 -> V_105 ;
V_128 = F_51 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_439 , sizeof( * V_155 ) , V_2 ,
V_266 ) ;
V_25 = F_40 ( V_5 ) ;
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_123 ( struct V_4 * V_5 ,
struct V_440 * V_441 )
{
struct V_1 * V_2 ;
struct V_442 * V_155 ;
struct V_101 V_383 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_383 . V_138 = sizeof( struct V_442 ) ;
V_383 . V_105 = F_97 ( V_5 -> V_12 , V_383 . V_138 ,
& V_383 . V_107 ) ;
if ( ! V_383 . V_105 ) {
F_16 ( & V_5 -> V_12 -> V_13 , L_21 ) ;
V_25 = - V_297 ;
goto V_174;
}
V_155 = V_383 . V_105 ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_443 , sizeof( * V_155 ) ,
V_2 , & V_383 ) ;
V_25 = F_40 ( V_5 ) ;
if ( ! V_25 ) {
struct V_440 * V_444 =
V_383 . V_105 + sizeof( struct V_122 ) ;
V_441 -> V_445 = F_22 ( V_444 -> V_445 ) ;
V_441 -> V_446 =
F_22 ( V_444 -> V_446 ) ;
}
F_98 ( V_5 -> V_12 , V_383 . V_138 ,
V_383 . V_105 , V_383 . V_107 ) ;
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_124 ( struct V_4 * V_5 , T_1 V_447 , T_1 V_182 )
{
struct V_1 * V_2 ;
struct V_448 * V_155 ;
int V_25 ;
F_30 ( & V_5 -> V_172 ) ;
V_2 = F_61 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_449 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_158 . V_182 = V_182 ;
V_155 -> V_450 = F_53 ( V_451 ) ;
V_155 -> V_452 = F_53 ( V_447 ) ;
V_25 = F_40 ( V_5 ) ;
V_174:
F_32 ( & V_5 -> V_172 ) ;
return V_25 ;
}
int F_125 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_453 * V_155 ;
struct V_454 * V_43 ;
int V_25 ;
int V_296 = F_126 ( sizeof( * V_155 ) , sizeof( * V_43 ) ) ;
struct V_455 * V_456 ;
struct V_101 V_457 ;
memset ( & V_457 , 0 , sizeof( struct V_101 ) ) ;
V_457 . V_138 = sizeof( struct V_454 ) ;
V_457 . V_105 = F_97 ( V_5 -> V_12 , V_457 . V_138 ,
& V_457 . V_107 ) ;
if ( ! V_457 . V_105 ) {
F_16 ( & V_5 -> V_12 -> V_13 ,
L_22 ) ;
return - V_297 ;
}
if ( F_66 ( & V_5 -> V_151 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = V_457 . V_105 ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_458 , V_296 , V_2 ,
& V_457 ) ;
V_25 = F_45 ( V_5 ) ;
if ( ! V_25 ) {
V_456 = V_457 . V_105 + sizeof( struct V_459 ) ;
V_5 -> V_460 = V_456 -> V_461 . V_462 ;
}
V_174:
F_67 ( & V_5 -> V_151 ) ;
F_98 ( V_5 -> V_12 , V_457 . V_138 , V_457 . V_105 ,
V_457 . V_107 ) ;
return V_25 ;
}
int F_127 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_463 * V_155 ;
int V_25 ;
if ( F_66 ( & V_5 -> V_151 ) )
return - 1 ;
V_2 = F_60 ( V_5 ) ;
if ( ! V_2 ) {
V_25 = - V_173 ;
goto V_174;
}
V_155 = F_1 ( V_2 ) ;
F_52 ( & V_155 -> V_158 , V_32 ,
V_464 , sizeof( * V_155 ) , V_2 , NULL ) ;
V_155 -> V_465 = F_53 ( V_466 |
V_467 ) ;
V_155 -> V_256 = F_53 ( V_467 ) ;
V_25 = F_45 ( V_5 ) ;
if ( ! V_25 ) {
struct V_468 * V_43 = F_1 ( V_2 ) ;
V_5 -> V_469 = F_7 ( V_43 -> V_256 ) &
V_467 ;
}
V_174:
F_67 ( & V_5 -> V_151 ) ;
return V_25 ;
}
