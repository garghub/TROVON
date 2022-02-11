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
} else if ( ( V_20 != V_47 ) &&
( V_17 -> V_25 != V_48 ) ) {
V_21 = ( V_17 -> V_22 >> V_49 ) &
V_50 ;
F_15 ( & V_2 -> V_9 -> V_10 ,
L_2 ,
V_17 -> V_25 , V_20 , V_21 ) ;
}
return V_20 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
F_17 ( V_2 ,
V_52 -> V_53 == V_54 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_55 * V_52 )
{
if ( V_52 -> V_56 ) {
V_2 -> V_57 = V_52 -> V_58 ;
V_2 -> V_59 &= ~ V_60 ;
V_2 -> V_59 =
V_52 -> V_61 << V_62 ;
}
}
static void F_19 ( struct V_1 * V_2 ,
struct V_63 * V_52 )
{
if ( V_52 -> V_64 == V_2 -> V_65 ) {
V_2 -> V_66 = V_52 -> V_67 * 10 ;
}
}
static void F_20 ( struct V_1 * V_2 ,
struct V_68 * V_52 )
{
if ( V_52 -> V_69 )
V_2 -> V_70 = F_21 ( V_52 -> V_71 ) ;
else
V_2 -> V_70 = 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
T_1 V_72 , struct V_16 * V_52 )
{
T_3 V_73 = 0 ;
V_73 = ( V_72 >> V_74 ) &
V_75 ;
switch ( V_73 ) {
case V_76 :
F_18 ( V_2 ,
(struct V_55 * ) V_52 ) ;
break;
case V_77 :
F_19 ( V_2 ,
(struct V_63 * ) V_52 ) ;
break;
case V_78 :
F_20 ( V_2 ,
(struct V_68 * ) V_52 ) ;
break;
default:
F_15 ( & V_2 -> V_9 -> V_10 , L_3 ) ;
break;
}
}
static inline bool F_23 ( T_1 V_72 )
{
return ( ( V_72 >> V_79 ) &
V_80 ) ==
V_81 ;
}
static inline bool F_24 ( T_1 V_72 )
{
return ( ( ( V_72 >> V_79 ) &
V_80 ) ==
V_82 ) ;
}
static struct V_16 * F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_83 = & V_2 -> V_5 . V_84 ;
struct V_16 * V_17 = F_26 ( V_83 ) ;
if ( F_5 ( V_17 ) ) {
F_27 ( V_83 ) ;
return V_17 ;
}
return NULL ;
}
void F_28 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_85 ) ;
F_30 ( V_2 , V_2 -> V_5 . V_84 . V_11 , true , 0 ) ;
V_2 -> V_5 . V_86 = true ;
F_31 ( & V_2 -> V_85 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_86 = false ;
}
int F_33 ( struct V_1 * V_2 , int * V_22 )
{
struct V_16 * V_17 ;
int V_87 = 0 ;
struct V_88 * V_5 = & V_2 -> V_5 ;
F_29 ( & V_2 -> V_85 ) ;
while ( ( V_17 = F_25 ( V_2 ) ) ) {
if ( V_17 -> V_18 & V_89 ) {
if ( F_23 ( V_17 -> V_18 ) )
F_16 ( V_2 ,
(struct V_51 * ) V_17 ) ;
else if ( F_24 ( V_17 -> V_18 ) )
F_22 ( V_2 ,
V_17 -> V_18 , V_17 ) ;
} else if ( V_17 -> V_18 & V_90 ) {
* V_22 = F_9 ( V_2 , V_17 ) ;
F_34 ( & V_5 -> V_6 . V_91 ) ;
}
F_8 ( V_17 ) ;
V_87 ++ ;
}
F_31 ( & V_2 -> V_85 ) ;
return V_87 ;
}
static int F_35 ( struct V_1 * V_2 )
{
#define F_36 120000
int V_92 , V_87 , V_22 = 0 ;
struct V_88 * V_5 = & V_2 -> V_5 ;
if ( V_2 -> V_8 )
return - V_93 ;
for ( V_92 = 0 ; V_92 < F_36 ; V_92 ++ ) {
V_87 = F_33 ( V_2 , & V_22 ) ;
if ( V_87 )
F_30 ( V_2 , V_5 -> V_84 . V_11 ,
V_5 -> V_86 , V_87 ) ;
if ( F_37 ( & V_5 -> V_6 . V_91 ) == 0 )
break;
F_38 ( 100 ) ;
}
if ( V_92 == F_36 ) {
F_39 ( & V_2 -> V_9 -> V_10 , L_4 ) ;
return - 1 ;
}
return V_22 ;
}
static int F_40 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return F_35 ( V_2 ) ;
}
static int F_41 ( struct V_1 * V_2 , void T_4 * V_14 )
{
int V_94 = 0 ;
T_1 V_95 ;
if ( V_2 -> V_8 ) {
F_39 ( & V_2 -> V_9 -> V_10 ,
L_5 ) ;
return - V_93 ;
}
do {
V_95 = F_42 ( V_14 ) ;
if ( V_95 == 0xffffffff ) {
F_39 ( & V_2 -> V_9 -> V_10 ,
L_6 ) ;
return - 1 ;
}
V_95 &= V_96 ;
if ( V_95 )
break;
if ( V_94 > 4000 ) {
F_39 ( & V_2 -> V_9 -> V_10 , L_7 ) ;
if ( ! F_12 ( V_2 ) )
F_43 ( V_2 ) ;
return - 1 ;
}
F_44 ( 1 ) ;
V_94 ++ ;
} while ( true );
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_22 ;
T_1 V_7 = 0 ;
void T_4 * V_14 = V_2 -> V_14 + V_97 ;
struct V_98 * V_99 = & V_2 -> V_99 ;
struct V_100 * V_101 = V_99 -> V_41 ;
struct V_16 * V_17 = & V_101 -> V_17 ;
V_22 = F_41 ( V_2 , V_14 ) ;
if ( V_22 != 0 )
return V_22 ;
V_7 |= V_102 ;
V_7 |= ( F_46 ( V_99 -> V_103 ) >> 2 ) << 2 ;
F_4 ( V_7 , V_14 ) ;
V_22 = F_41 ( V_2 , V_14 ) ;
if ( V_22 != 0 )
return V_22 ;
V_7 = 0 ;
V_7 |= ( T_1 ) ( V_99 -> V_103 >> 4 ) << 2 ;
F_4 ( V_7 , V_14 ) ;
V_22 = F_41 ( V_2 , V_14 ) ;
if ( V_22 != 0 )
return V_22 ;
if ( F_5 ( V_17 ) ) {
V_22 = F_9 ( V_2 , & V_101 -> V_17 ) ;
F_8 ( V_17 ) ;
if ( V_22 )
return V_22 ;
} else {
F_39 ( & V_2 -> V_9 -> V_10 , L_8 ) ;
return - 1 ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , T_2 * V_104 )
{
T_1 V_105 ;
if ( F_12 ( V_2 ) )
V_105 = F_42 ( V_2 -> V_14 + V_106 ) ;
else
V_105 = F_42 ( V_2 -> V_107 + V_108 ) ;
* V_104 = V_105 & V_109 ;
if ( ( V_105 >> V_110 ) & V_111 )
return - 1 ;
else
return 0 ;
}
int F_48 ( struct V_1 * V_2 )
{
T_2 V_104 ;
int V_22 , V_112 = 0 ;
struct V_113 * V_10 = & V_2 -> V_9 -> V_10 ;
do {
V_22 = F_47 ( V_2 , & V_104 ) ;
if ( V_22 ) {
F_39 ( V_10 , L_9 , V_104 ) ;
return - 1 ;
} else if ( V_104 != V_114 ) {
if ( F_49 ( 2000 ) ) {
F_39 ( V_10 , L_10 ) ;
return - V_115 ;
}
V_112 += 2 ;
} else {
return 0 ;
}
} while ( V_112 < 40 );
F_39 ( V_10 , L_11 , V_104 ) ;
return - 1 ;
}
static inline void * F_50 ( struct V_116 * V_117 )
{
return V_117 -> V_118 . F_50 ;
}
static inline struct V_119 * F_51 ( struct V_116 * V_117 )
{
return & V_117 -> V_118 . V_120 [ 0 ] ;
}
static void F_52 ( struct V_116 * V_117 , int V_121 ,
bool V_122 , T_3 V_123 , T_1 V_124 )
{
if ( V_122 )
V_117 -> V_122 |= V_125 ;
else
V_117 -> V_122 |= ( V_123 & V_126 ) <<
V_127 ;
V_117 -> V_128 = V_121 ;
V_117 -> V_25 = V_124 ;
F_53 ( V_117 , 8 ) ;
}
static void F_54 ( struct V_129 * V_130 ,
T_3 V_131 , T_3 V_124 , int V_132 )
{
V_130 -> V_124 = V_124 ;
V_130 -> V_131 = V_131 ;
V_130 -> V_133 = F_55 ( V_132 - sizeof( * V_130 ) ) ;
V_130 -> V_134 = 0 ;
}
static void F_56 ( struct V_135 * V_136 , T_1 V_137 ,
struct V_98 * V_138 )
{
int V_92 , V_139 = F_57 ( F_58 ( V_138 -> V_41 , V_138 -> V_140 ) , V_137 ) ;
T_5 V_103 = ( T_5 ) V_138 -> V_103 ;
for ( V_92 = 0 ; V_92 < V_139 ; V_92 ++ ) {
V_136 [ V_92 ] . V_141 = F_55 ( V_103 & 0xFFFFFFFF ) ;
V_136 [ V_92 ] . V_142 = F_55 ( F_46 ( V_103 ) ) ;
V_103 += V_143 ;
}
}
static T_1 F_59 ( T_1 V_144 )
{
#define F_60 651042
const T_1 V_145 = 10 ;
T_1 V_146 ;
if ( V_144 == 0 )
V_146 = 0 ;
else {
T_1 V_147 = 1000000 / V_144 ;
if ( V_147 == 0 )
V_146 = 1023 ;
else {
V_146 = ( F_60 - V_147 ) * V_145 ;
V_146 /= V_147 ;
V_146 = ( V_146 + V_145 / 2 ) / V_145 ;
V_146 = F_57 ( V_146 , ( T_1 ) 1023 ) ;
}
}
return V_146 ;
}
static inline struct V_116 * F_61 ( struct V_1 * V_2 )
{
struct V_98 * V_99 = & V_2 -> V_99 ;
struct V_116 * V_117
= & ( (struct V_100 * ) ( V_99 -> V_41 ) ) -> V_117 ;
memset ( V_117 , 0 , sizeof( * V_117 ) ) ;
return V_117 ;
}
static struct V_116 * F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 ;
struct V_116 * V_117 ;
if ( F_37 ( & V_4 -> V_91 ) >= V_4 -> V_148 ) {
F_39 ( & V_2 -> V_9 -> V_10 , L_12 ) ;
return NULL ;
}
V_117 = F_63 ( V_4 ) ;
F_64 ( V_4 ) ;
F_65 ( & V_4 -> V_91 ) ;
memset ( V_117 , 0 , sizeof( * V_117 ) ) ;
return V_117 ;
}
int F_66 ( struct V_1 * V_2 )
{
T_3 * V_117 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_149 ) )
return - 1 ;
V_117 = ( T_3 * ) F_61 ( V_2 ) ;
* V_117 ++ = 0xFF ;
* V_117 ++ = 0x12 ;
* V_117 ++ = 0x34 ;
* V_117 ++ = 0xFF ;
* V_117 ++ = 0xFF ;
* V_117 ++ = 0x56 ;
* V_117 ++ = 0x78 ;
* V_117 = 0xFF ;
V_22 = F_45 ( V_2 ) ;
F_68 ( & V_2 -> V_149 ) ;
return V_22 ;
}
int F_69 ( struct V_1 * V_2 )
{
T_3 * V_117 ;
int V_22 ;
if ( V_2 -> V_8 )
return - V_93 ;
if ( F_67 ( & V_2 -> V_149 ) )
return - 1 ;
V_117 = ( T_3 * ) F_61 ( V_2 ) ;
* V_117 ++ = 0xFF ;
* V_117 ++ = 0xAA ;
* V_117 ++ = 0xBB ;
* V_117 ++ = 0xFF ;
* V_117 ++ = 0xFF ;
* V_117 ++ = 0xCC ;
* V_117 ++ = 0xDD ;
* V_117 = 0xFF ;
V_22 = F_45 ( V_2 ) ;
F_68 ( & V_2 -> V_149 ) ;
return V_22 ;
}
int F_70 ( struct V_1 * V_2 ,
struct V_3 * V_150 , int V_151 )
{
struct V_116 * V_117 ;
struct V_152 * V_153 ;
struct V_98 * V_154 = & V_150 -> V_155 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_149 ) )
return - 1 ;
V_117 = F_61 ( V_2 ) ;
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 , V_156 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_156 , sizeof( * V_153 ) ) ;
V_153 -> V_158 = F_71 ( F_58 ( V_154 -> V_41 , V_154 -> V_140 ) ) ;
F_72 ( struct V_159 , V_56 , V_153 -> V_160 , 1 ) ;
F_72 ( struct V_159 , V_140 , V_153 -> V_160 , 0 ) ;
F_72 ( struct V_159 , V_161 , V_153 -> V_160 ,
F_73 ( V_150 -> V_148 / 256 ) ) ;
F_72 ( struct V_159 , V_162 , V_153 -> V_160 ,
F_59 ( V_151 ) ) ;
F_53 ( V_153 -> V_160 , sizeof( V_153 -> V_160 ) ) ;
F_56 ( V_153 -> V_136 , F_74 ( V_153 -> V_136 ) , V_154 ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_163 * V_39 = F_50 ( V_117 ) ;
V_150 -> V_11 = F_21 ( V_39 -> V_164 ) ;
V_150 -> V_165 = true ;
}
F_68 ( & V_2 -> V_149 ) ;
return V_22 ;
}
int F_75 ( struct V_1 * V_2 , T_3 * V_166 ,
T_3 type , bool V_167 , T_1 V_168 )
{
struct V_116 * V_117 ;
struct V_169 * V_153 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_149 ) )
return - 1 ;
V_117 = F_61 ( V_2 ) ;
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_48 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_48 , sizeof( * V_153 ) ) ;
V_153 -> type = type ;
if ( V_167 ) {
V_153 -> V_167 = 1 ;
} else {
V_153 -> V_170 = F_71 ( ( T_2 ) V_168 ) ;
V_153 -> V_167 = 0 ;
}
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_171 * V_39 = F_50 ( V_117 ) ;
memcpy ( V_166 , V_39 -> V_172 . V_173 , V_174 ) ;
}
F_68 ( & V_2 -> V_149 ) ;
return V_22 ;
}
int F_76 ( struct V_1 * V_2 , T_3 * V_166 ,
T_1 V_170 , T_1 * V_175 , T_1 V_176 )
{
struct V_116 * V_117 ;
struct V_177 * V_153 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_181 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_181 , sizeof( * V_153 ) ) ;
V_153 -> V_157 . V_176 = V_176 ;
V_153 -> V_170 = F_55 ( V_170 ) ;
memcpy ( V_153 -> V_182 , V_166 , V_174 ) ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_183 * V_39 = F_50 ( V_117 ) ;
* V_175 = F_6 ( V_39 -> V_175 ) ;
}
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_77 ( struct V_1 * V_2 , T_1 V_170 , T_1 V_175 , T_1 V_184 )
{
struct V_116 * V_117 ;
struct V_185 * V_153 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_186 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_186 , sizeof( * V_153 ) ) ;
V_153 -> V_157 . V_176 = V_184 ;
V_153 -> V_170 = F_55 ( V_170 ) ;
V_153 -> V_175 = F_55 ( V_175 ) ;
V_22 = F_40 ( V_2 ) ;
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_78 ( struct V_1 * V_2 ,
struct V_3 * V_84 , struct V_3 * V_150 ,
bool V_187 , bool V_188 , int V_189 )
{
struct V_116 * V_117 ;
struct V_190 * V_153 ;
struct V_98 * V_154 = & V_84 -> V_155 ;
void * V_191 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_149 ) )
return - 1 ;
V_117 = F_61 ( V_2 ) ;
V_153 = F_50 ( V_117 ) ;
V_191 = & V_153 -> V_160 ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_192 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_192 , sizeof( * V_153 ) ) ;
V_153 -> V_158 = F_71 ( F_58 ( V_154 -> V_41 , V_154 -> V_140 ) ) ;
if ( F_12 ( V_2 ) ) {
V_153 -> V_157 . V_134 = 2 ;
V_153 -> V_193 = 1 ;
F_72 ( struct V_194 , V_195 , V_191 ,
V_188 ) ;
F_72 ( struct V_194 , V_161 , V_191 ,
F_73 ( V_84 -> V_148 / 256 ) ) ;
F_72 ( struct V_194 , V_56 , V_191 , 1 ) ;
F_72 ( struct V_194 , V_196 ,
V_191 , 1 ) ;
F_72 ( struct V_194 , V_197 ,
V_191 , V_150 -> V_11 ) ;
F_72 ( struct V_194 , V_198 , V_191 , 1 ) ;
} else {
F_72 ( struct V_199 , V_200 , V_191 ,
V_189 ) ;
F_72 ( struct V_199 , V_195 ,
V_191 , V_188 ) ;
F_72 ( struct V_199 , V_161 , V_191 ,
F_73 ( V_84 -> V_148 / 256 ) ) ;
F_72 ( struct V_199 , V_56 , V_191 , 1 ) ;
F_72 ( struct V_199 , V_201 ,
V_191 , V_187 ) ;
F_72 ( struct V_199 , V_196 , V_191 , 1 ) ;
F_72 ( struct V_199 , V_197 , V_191 , V_150 -> V_11 ) ;
F_72 ( struct V_199 , V_198 , V_191 , 1 ) ;
}
F_53 ( V_191 , sizeof( V_153 -> V_160 ) ) ;
F_56 ( V_153 -> V_136 , F_74 ( V_153 -> V_136 ) , V_154 ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_202 * V_39 = F_50 ( V_117 ) ;
V_84 -> V_11 = F_21 ( V_39 -> V_203 ) ;
V_84 -> V_165 = true ;
}
F_68 ( & V_2 -> V_149 ) ;
return V_22 ;
}
static T_1 F_79 ( int V_204 )
{
T_1 V_205 = F_80 ( V_204 ) ;
if ( V_205 == 16 )
V_205 = 0 ;
return V_205 ;
}
int F_81 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_84 )
{
struct V_116 * V_117 ;
struct V_206 * V_153 ;
struct V_98 * V_154 = & V_4 -> V_155 ;
void * V_191 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_149 ) )
return - 1 ;
V_117 = F_61 ( V_2 ) ;
V_153 = F_50 ( V_117 ) ;
V_191 = & V_153 -> V_160 ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_207 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_207 , sizeof( * V_153 ) ) ;
V_153 -> V_158 = F_71 ( F_58 ( V_154 -> V_41 , V_154 -> V_140 ) ) ;
if ( F_12 ( V_2 ) ) {
V_153 -> V_157 . V_134 = 1 ;
V_153 -> V_203 = F_71 ( V_84 -> V_11 ) ;
F_72 ( struct V_208 , V_209 , V_191 ,
F_79 ( V_4 -> V_148 ) ) ;
F_72 ( struct V_208 , V_56 , V_191 , 1 ) ;
F_72 ( struct V_208 , V_210 ,
V_191 , V_84 -> V_11 ) ;
F_72 ( struct V_208 , V_211 ,
V_191 , 1 ) ;
} else {
F_72 ( struct V_212 , V_56 , V_191 , 1 ) ;
F_72 ( struct V_212 , V_209 , V_191 ,
F_79 ( V_4 -> V_148 ) ) ;
F_72 ( struct V_212 , V_203 , V_191 , V_84 -> V_11 ) ;
}
V_153 -> V_213 [ 0 ] = F_55 ( 0x00000022 ) ;
F_53 ( V_191 , sizeof( V_153 -> V_160 ) ) ;
F_56 ( V_153 -> V_136 , F_74 ( V_153 -> V_136 ) , V_154 ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_214 * V_39 = F_50 ( V_117 ) ;
V_4 -> V_11 = F_21 ( V_39 -> V_11 ) ;
V_4 -> V_165 = true ;
}
F_68 ( & V_2 -> V_149 ) ;
return V_22 ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_3 * V_215 ,
struct V_3 * V_84 )
{
struct V_116 * V_117 ;
struct V_216 * V_153 ;
struct V_98 * V_154 = & V_215 -> V_155 ;
void * V_191 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_149 ) )
return - 1 ;
V_117 = F_61 ( V_2 ) ;
V_153 = F_50 ( V_117 ) ;
V_191 = & V_153 -> V_160 ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_217 ) ;
F_54 ( & V_153 -> V_157 , V_35 , V_217 ,
sizeof( * V_153 ) ) ;
if ( F_12 ( V_2 ) ) {
V_153 -> V_157 . V_134 = 1 ;
F_72 ( struct V_218 , V_170 , V_191 ,
V_2 -> V_168 ) ;
}
V_153 -> V_158 = F_58 ( V_154 -> V_41 , V_154 -> V_140 ) ;
V_153 -> V_219 = V_220 ;
V_153 -> type = V_221 ;
F_72 ( struct V_218 , V_222 , V_191 ,
F_79 ( V_215 -> V_148 ) ) ;
F_72 ( struct V_218 , V_223 , V_191 , 1 ) ;
F_72 ( struct V_218 , V_224 , V_191 , V_84 -> V_11 ) ;
F_53 ( V_191 , sizeof( V_153 -> V_160 ) ) ;
F_56 ( V_153 -> V_136 , F_74 ( V_153 -> V_136 ) , V_154 ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_225 * V_39 = F_50 ( V_117 ) ;
V_215 -> V_11 = F_21 ( V_39 -> V_226 ) ;
V_215 -> V_165 = true ;
}
F_68 ( & V_2 -> V_149 ) ;
return V_22 ;
}
int F_83 ( struct V_1 * V_2 ,
struct V_3 * V_227 , T_2 V_203 , T_2 V_228 ,
T_2 V_229 , T_1 V_170 , T_1 V_230 , T_3 * V_231 )
{
struct V_116 * V_117 ;
struct V_232 * V_153 ;
struct V_98 * V_154 = & V_227 -> V_155 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_149 ) )
return - 1 ;
V_117 = F_61 ( V_2 ) ;
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_233 ) ;
F_54 ( & V_153 -> V_157 , V_35 , V_233 ,
sizeof( * V_153 ) ) ;
V_153 -> V_203 = F_71 ( V_203 ) ;
V_153 -> V_228 = F_80 ( V_228 ) - 1 ;
V_153 -> V_158 = 2 ;
F_56 ( V_153 -> V_136 , F_74 ( V_153 -> V_136 ) , V_154 ) ;
V_153 -> V_234 = F_55 ( V_170 ) ;
V_153 -> V_229 = F_71 ( V_229 ) ;
V_153 -> V_235 = F_55 ( V_230 ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_236 * V_39 = F_50 ( V_117 ) ;
V_227 -> V_11 = F_21 ( V_39 -> V_11 ) ;
V_227 -> V_165 = true ;
* V_231 = V_39 -> V_231 ;
}
F_68 ( & V_2 -> V_149 ) ;
return V_22 ;
}
int F_84 ( struct V_1 * V_2 , struct V_3 * V_6 ,
int V_237 )
{
struct V_116 * V_117 ;
struct V_238 * V_153 ;
T_3 V_239 = 0 , V_124 = 0 ;
int V_22 ;
if ( V_2 -> V_8 )
return - V_93 ;
if ( F_67 ( & V_2 -> V_149 ) )
return - 1 ;
V_117 = F_61 ( V_2 ) ;
V_153 = F_50 ( V_117 ) ;
switch ( V_237 ) {
case V_240 :
V_239 = V_29 ;
V_124 = V_241 ;
break;
case V_242 :
V_239 = V_29 ;
V_124 = V_243 ;
break;
case V_244 :
V_239 = V_35 ;
V_124 = V_245 ;
break;
case V_246 :
V_239 = V_35 ;
V_124 = V_247 ;
break;
case V_248 :
V_239 = V_29 ;
V_124 = V_249 ;
break;
default:
F_85 () ;
}
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 , V_124 ) ;
F_54 ( & V_153 -> V_157 , V_239 , V_124 , sizeof( * V_153 ) ) ;
V_153 -> V_11 = F_71 ( V_6 -> V_11 ) ;
V_22 = F_45 ( V_2 ) ;
F_68 ( & V_2 -> V_149 ) ;
return V_22 ;
}
int F_86 ( struct V_1 * V_2 , T_1 V_250 , T_1 V_251 ,
T_3 * V_172 , bool V_252 , T_1 * V_168 , T_1 * V_175 ,
T_1 V_176 )
{
struct V_116 * V_117 ;
struct V_253 * V_153 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_149 ) )
return - 1 ;
V_117 = F_61 ( V_2 ) ;
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_254 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_254 , sizeof( * V_153 ) ) ;
V_153 -> V_157 . V_176 = V_176 ;
V_153 -> V_255 = F_55 ( V_250 ) ;
V_153 -> V_256 = F_55 ( V_251 ) ;
V_153 -> V_252 = V_252 ;
if ( ! V_252 )
memcpy ( V_153 -> V_166 , V_172 , V_174 ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_257 * V_39 = F_50 ( V_117 ) ;
* V_168 = F_6 ( V_39 -> V_234 ) ;
if ( ! V_252 )
* V_175 = F_6 ( V_39 -> V_175 ) ;
}
F_68 ( & V_2 -> V_149 ) ;
return V_22 ;
}
int F_87 ( struct V_1 * V_2 , T_1 V_234 , T_1 V_176 )
{
struct V_116 * V_117 ;
struct V_258 * V_153 ;
int V_22 ;
if ( V_2 -> V_8 )
return - V_93 ;
if ( F_67 ( & V_2 -> V_149 ) )
return - 1 ;
V_117 = F_61 ( V_2 ) ;
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_259 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_259 , sizeof( * V_153 ) ) ;
V_153 -> V_157 . V_176 = V_176 ;
V_153 -> V_234 = F_55 ( V_234 ) ;
V_22 = F_45 ( V_2 ) ;
F_68 ( & V_2 -> V_149 ) ;
return V_22 ;
}
int F_88 ( struct V_1 * V_2 , struct V_98 * V_260 )
{
struct V_116 * V_117 ;
struct V_129 * V_157 ;
struct V_119 * V_261 ;
int V_22 = 0 ;
if ( F_89 ( V_2 -> V_262 , V_263 ) == 0 )
F_90 ( V_2 ) ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_157 = V_260 -> V_41 ;
V_261 = F_51 ( V_117 ) ;
F_52 ( V_117 , V_260 -> V_140 , false , 1 ,
V_33 ) ;
F_54 ( V_157 , V_35 ,
V_33 , V_260 -> V_140 ) ;
if ( V_2 -> V_36 == V_37 )
V_157 -> V_134 = 1 ;
V_117 -> V_28 = V_35 ;
V_261 -> V_264 = F_55 ( F_46 ( V_260 -> V_103 ) ) ;
V_261 -> V_265 = F_55 ( V_260 -> V_103 & 0xFFFFFFFF ) ;
V_261 -> V_148 = F_55 ( V_260 -> V_140 ) ;
F_1 ( V_2 ) ;
V_2 -> V_46 = true ;
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_91 ( struct V_1 * V_2 ,
struct V_98 * V_260 )
{
struct V_116 * V_117 ;
struct V_266 * V_153 ;
struct V_119 * V_261 ;
int V_22 = 0 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = V_260 -> V_41 ;
V_261 = F_51 ( V_117 ) ;
F_52 ( V_117 , V_260 -> V_140 , false , 1 ,
V_34 ) ;
F_54 ( & V_153 -> V_157 , V_35 ,
V_34 , V_260 -> V_140 ) ;
V_153 -> V_267 . V_268 . V_269 = F_71 ( V_2 -> V_65 ) ;
V_153 -> V_267 . V_268 . V_270 = 0 ;
V_117 -> V_28 = V_35 ;
V_261 -> V_264 = F_55 ( F_46 ( V_260 -> V_103 ) ) ;
V_261 -> V_265 = F_55 ( V_260 -> V_103 & 0xFFFFFFFF ) ;
V_261 -> V_148 = F_55 ( V_260 -> V_140 ) ;
F_1 ( V_2 ) ;
V_2 -> V_46 = true ;
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_92 ( struct V_1 * V_2 ,
bool * V_271 , T_3 * V_272 , T_2 * V_66 , T_1 V_184 )
{
struct V_116 * V_117 ;
struct V_273 * V_153 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = F_50 ( V_117 ) ;
* V_271 = false ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_274 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_274 , sizeof( * V_153 ) ) ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_275 * V_39 = F_50 ( V_117 ) ;
if ( V_39 -> V_272 != V_276 ) {
* V_271 = true ;
* V_66 = F_21 ( V_39 -> V_66 ) ;
* V_272 = V_39 -> V_272 ;
}
}
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_90 ( struct V_1 * V_2 )
{
struct V_116 * V_117 ;
struct V_277 * V_153 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_278 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_278 , sizeof( * V_153 ) ) ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_279 * V_39 =
F_50 ( V_117 ) ;
V_2 -> V_280 . V_281 =
V_39 -> V_282 ;
}
else
V_263 = 0 ;
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_93 ( struct V_1 * V_2 , T_1 * V_283 )
{
struct V_116 * V_117 ;
struct V_284 * V_153 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_285 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_285 , sizeof( * V_153 ) ) ;
V_153 -> V_286 = F_55 ( V_287 ) ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_288 * V_39 = F_50 ( V_117 ) ;
if ( V_283 && V_39 -> V_283 )
* V_283 = F_6 ( V_39 -> V_283 ) -
sizeof( T_1 ) ;
}
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
void F_94 ( struct V_1 * V_2 , T_1 V_289 , void * V_290 )
{
struct V_98 V_291 ;
struct V_116 * V_117 ;
struct V_284 * V_153 ;
struct V_119 * V_261 ;
T_1 V_292 = 0 , V_293 , V_294 ,
V_295 = sizeof( T_1 ) , V_121 ;
int V_22 ;
if ( V_289 == 0 )
return;
V_293 = V_289 ;
V_291 . V_140 = sizeof( struct V_284 ) + 60 * 1024 ;
V_291 . V_41 = F_95 ( V_2 -> V_9 ,
V_291 . V_140 ,
& V_291 . V_103 ) ;
if ( ! V_291 . V_41 ) {
V_22 = - V_296 ;
F_39 ( & V_2 -> V_9 -> V_10 ,
L_13 ) ;
return;
}
F_29 ( & V_2 -> V_178 ) ;
while ( V_293 ) {
V_294 = F_57 ( V_293 , ( T_1 ) 60 * 1024 ) ;
V_293 -= V_294 ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = V_291 . V_41 ;
V_261 = F_51 ( V_117 ) ;
V_121 = sizeof( struct V_284 ) + V_294 ;
F_52 ( V_117 , V_121 , false , 1 ,
V_285 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_285 , V_121 ) ;
V_261 -> V_264 = F_55 ( F_46 ( V_291 . V_103 ) ) ;
V_261 -> V_265 = F_55 ( V_291 . V_103 & 0xFFFFFFFF ) ;
V_261 -> V_148 = F_55 ( V_291 . V_140 ) ;
V_153 -> V_286 = F_55 ( V_297 ) ;
V_153 -> V_298 = F_55 ( V_295 ) ;
V_153 -> V_299 = F_55 ( V_294 ) ;
V_153 -> V_300 = F_55 ( V_294 ) ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_288 * V_39 = V_291 . V_41 ;
memcpy ( V_290 + V_292 ,
V_39 -> V_301 ,
V_39 -> V_299 ) ;
} else {
F_39 ( & V_2 -> V_9 -> V_10 , L_14 ) ;
goto V_180;
}
V_292 += V_294 ;
V_295 += V_294 ;
}
V_180:
F_96 ( V_2 -> V_9 , V_291 . V_140 ,
V_291 . V_41 ,
V_291 . V_103 ) ;
F_31 ( & V_2 -> V_178 ) ;
}
int F_97 ( struct V_1 * V_2 , char * V_302 )
{
struct V_116 * V_117 ;
struct V_303 * V_153 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_149 ) )
return - 1 ;
V_117 = F_61 ( V_2 ) ;
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_304 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_304 , sizeof( * V_153 ) ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_305 * V_39 = F_50 ( V_117 ) ;
strncpy ( V_302 , V_39 -> V_306 , V_307 ) ;
}
F_68 ( & V_2 -> V_149 ) ;
return V_22 ;
}
int F_98 ( struct V_1 * V_2 , T_1 V_164 , T_1 V_308 )
{
struct V_116 * V_117 ;
struct V_309 * V_153 ;
int V_22 = 0 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_310 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_310 , sizeof( * V_153 ) ) ;
V_153 -> V_311 = F_55 ( 1 ) ;
V_153 -> V_312 [ 0 ] . V_164 = F_55 ( V_164 ) ;
V_153 -> V_312 [ 0 ] . V_313 = 0 ;
V_153 -> V_312 [ 0 ] . V_314 = F_55 ( V_308 ) ;
F_1 ( V_2 ) ;
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_99 ( struct V_1 * V_2 , T_1 V_170 , T_2 * V_315 ,
T_1 V_87 , bool V_316 , bool V_317 )
{
struct V_116 * V_117 ;
struct V_318 * V_153 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_319 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_319 , sizeof( * V_153 ) ) ;
V_153 -> V_234 = V_170 ;
V_153 -> V_317 = V_317 ;
V_153 -> V_316 = V_316 ;
V_153 -> V_320 = V_87 ;
if ( ! V_317 ) {
memcpy ( V_153 -> V_321 , V_315 ,
V_153 -> V_320 * sizeof( V_315 [ 0 ] ) ) ;
}
V_22 = F_40 ( V_2 ) ;
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_100 ( struct V_1 * V_2 , bool V_322 )
{
struct V_116 * V_117 ;
struct V_323 * V_153 ;
struct V_98 V_324 ;
struct V_119 * V_261 ;
int V_22 ;
memset ( & V_324 , 0 , sizeof( struct V_98 ) ) ;
V_324 . V_140 = sizeof( struct V_323 ) ;
V_324 . V_41 = F_95 ( V_2 -> V_9 ,
V_324 . V_140 , & V_324 . V_103 ) ;
if ( ! V_324 . V_41 ) {
F_39 ( & V_2 -> V_9 -> V_10 ,
L_15 ) ;
return - V_296 ;
}
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = V_324 . V_41 ;
V_261 = F_51 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , false , 1 ,
V_325 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_325 , sizeof( * V_153 ) ) ;
V_153 -> V_170 = F_55 ( V_2 -> V_168 ) ;
V_153 -> V_326 = F_55 ( V_327 ) ;
if ( V_322 )
V_153 -> V_328 = F_55 ( V_327 ) ;
V_261 -> V_264 = F_55 ( F_46 ( V_324 . V_103 ) ) ;
V_261 -> V_265 = F_55 ( V_324 . V_103 & 0xFFFFFFFF ) ;
V_261 -> V_148 = F_55 ( V_324 . V_140 ) ;
V_22 = F_40 ( V_2 ) ;
V_180:
F_31 ( & V_2 -> V_178 ) ;
F_96 ( V_2 -> V_9 , V_324 . V_140 ,
V_324 . V_41 , V_324 . V_103 ) ;
return V_22 ;
}
int F_101 ( struct V_1 * V_2 , T_1 V_170 ,
struct V_329 * V_330 , struct V_98 * V_138 )
{
struct V_116 * V_117 ;
struct V_331 * V_153 = V_138 -> V_41 ;
struct V_119 * V_261 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_261 = F_51 ( V_117 ) ;
memset ( V_153 , 0 , sizeof( * V_153 ) ) ;
F_52 ( V_117 , sizeof( * V_153 ) , false , 1 ,
V_332 ) ;
V_261 -> V_264 = F_55 ( F_46 ( V_138 -> V_103 ) ) ;
V_261 -> V_265 = F_55 ( V_138 -> V_103 & 0xFFFFFFFF ) ;
V_261 -> V_148 = F_55 ( V_138 -> V_140 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_332 , sizeof( * V_153 ) ) ;
V_153 -> V_234 = V_170 ;
if ( V_330 ) {
int V_92 ;
struct V_333 * V_334 ;
V_153 -> V_335 = F_71 ( F_102 ( V_330 ) ) ;
V_92 = 0 ;
F_103 (ha, netdev)
memcpy ( V_153 -> V_172 [ V_92 ++ ] . V_336 , V_334 -> V_173 , V_174 ) ;
} else {
V_153 -> V_317 = 1 ;
}
V_22 = F_40 ( V_2 ) ;
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_104 ( struct V_1 * V_2 , T_1 V_337 , T_1 V_338 )
{
struct V_116 * V_117 ;
struct V_339 * V_153 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_340 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_340 , sizeof( * V_153 ) ) ;
V_153 -> V_341 = F_71 ( ( T_2 ) V_337 ) ;
V_153 -> V_342 = F_71 ( ( T_2 ) V_338 ) ;
V_22 = F_40 ( V_2 ) ;
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_105 ( struct V_1 * V_2 , T_1 * V_337 , T_1 * V_338 )
{
struct V_116 * V_117 ;
struct V_343 * V_153 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_344 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_344 , sizeof( * V_153 ) ) ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_345 * V_39 =
F_50 ( V_117 ) ;
* V_337 = F_21 ( V_39 -> V_341 ) ;
* V_338 = F_21 ( V_39 -> V_342 ) ;
}
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_106 ( struct V_1 * V_2 , T_1 * V_65 ,
T_1 * V_346 , T_1 * V_347 )
{
struct V_116 * V_117 ;
struct V_348 * V_153 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_149 ) )
return - 1 ;
V_117 = F_61 ( V_2 ) ;
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_349 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_349 , sizeof( * V_153 ) ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_350 * V_39 = F_50 ( V_117 ) ;
* V_65 = F_6 ( V_39 -> V_351 ) ;
* V_346 = F_6 ( V_39 -> V_352 ) ;
* V_347 = F_6 ( V_39 -> V_353 ) ;
}
F_68 ( & V_2 -> V_149 ) ;
return V_22 ;
}
int F_107 ( struct V_1 * V_2 )
{
struct V_116 * V_117 ;
struct V_129 * V_153 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_149 ) )
return - 1 ;
V_117 = F_61 ( V_2 ) ;
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_354 ) ;
F_54 ( V_153 , V_29 ,
V_354 , sizeof( * V_153 ) ) ;
V_22 = F_45 ( V_2 ) ;
F_68 ( & V_2 -> V_149 ) ;
return V_22 ;
}
int F_108 ( struct V_1 * V_2 , T_3 * V_355 , T_2 V_356 )
{
struct V_116 * V_117 ;
struct V_357 * V_153 ;
T_1 V_358 [ 10 ] = { 0x0123 , 0x4567 , 0x89AB , 0xCDEF , 0x01EF ,
0x0123 , 0x4567 , 0x89AB , 0xCDEF , 0x01EF } ;
int V_22 ;
if ( F_67 ( & V_2 -> V_149 ) )
return - 1 ;
V_117 = F_61 ( V_2 ) ;
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_359 ) ;
F_54 ( & V_153 -> V_157 , V_35 ,
V_359 , sizeof( * V_153 ) ) ;
V_153 -> V_170 = F_55 ( V_2 -> V_168 ) ;
V_153 -> V_360 = F_71 ( V_361 | V_362 ) ;
V_153 -> V_363 = F_71 ( F_80 ( V_356 ) - 1 ) ;
memcpy ( V_153 -> V_364 , V_355 , V_356 ) ;
memcpy ( V_153 -> V_365 , V_358 , sizeof( V_358 ) ) ;
F_53 ( V_153 -> V_365 , sizeof( V_153 -> V_365 ) ) ;
V_22 = F_45 ( V_2 ) ;
F_68 ( & V_2 -> V_149 ) ;
return V_22 ;
}
int F_109 ( struct V_1 * V_2 , T_3 V_65 ,
T_3 V_366 , T_3 V_367 , T_3 V_368 )
{
struct V_116 * V_117 ;
struct V_369 * V_153 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_370 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_370 , sizeof( * V_153 ) ) ;
V_153 -> V_65 = V_65 ;
V_153 -> V_371 = V_368 ;
V_153 -> V_372 = V_366 ;
V_153 -> V_373 = V_367 ;
V_22 = F_40 ( V_2 ) ;
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_110 ( struct V_1 * V_2 , T_3 V_65 , T_1 * V_368 )
{
struct V_116 * V_117 ;
struct V_374 * V_153 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_375 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_375 , sizeof( * V_153 ) ) ;
V_153 -> V_65 = V_65 ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_376 * V_39 =
F_50 ( V_117 ) ;
* V_368 = V_39 -> V_371 ;
}
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_111 ( struct V_1 * V_2 , struct V_98 * V_377 ,
T_1 V_378 , T_1 V_379 , const char * V_380 ,
T_1 * V_381 , T_3 * V_382 )
{
struct V_116 * V_117 ;
struct V_383 * V_153 ;
struct V_384 * V_39 ;
void * V_191 = NULL ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_2 -> V_30 = 0 ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_385;
}
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( struct V_383 ) ,
true , 1 , V_27 ) ;
V_117 -> V_28 = V_29 ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_27 ,
sizeof( struct V_383 ) ) ;
V_191 = & V_153 -> V_160 ;
F_72 ( struct V_386 ,
V_387 , V_191 , V_378 ) ;
if ( V_378 == 0 )
F_72 ( struct V_386 ,
V_388 , V_191 , 1 ) ;
else
F_72 ( struct V_386 ,
V_388 , V_191 , 0 ) ;
F_53 ( V_191 , sizeof( V_153 -> V_160 ) ) ;
V_153 -> V_389 = F_55 ( V_379 ) ;
strcpy ( V_153 -> V_390 , V_380 ) ;
V_153 -> V_391 = F_55 ( 1 ) ;
V_153 -> V_289 = F_55 ( V_378 ) ;
V_153 -> V_392 = F_55 ( ( V_377 -> V_103 +
sizeof( struct V_383 ) )
& 0xFFFFFFFF ) ;
V_153 -> V_393 = F_55 ( F_46 ( V_377 -> V_103 +
sizeof( struct V_383 ) ) ) ;
F_1 ( V_2 ) ;
F_31 ( & V_2 -> V_178 ) ;
if ( ! F_112 ( & V_2 -> V_31 ,
F_113 ( 12000 ) ) )
V_22 = - 1 ;
else
V_22 = V_2 -> V_30 ;
V_39 = F_50 ( V_117 ) ;
if ( ! V_22 ) {
* V_381 = F_6 ( V_39 -> V_394 ) ;
} else {
* V_382 = V_39 -> V_395 ;
V_22 = V_39 -> V_22 ;
}
return V_22 ;
V_385:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_114 ( struct V_1 * V_2 , struct V_98 * V_377 ,
T_1 V_396 , T_1 V_397 , T_1 V_294 )
{
struct V_116 * V_117 ;
struct F_114 * V_153 ;
struct V_119 * V_261 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_2 -> V_30 = 0 ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_385;
}
V_153 = V_377 -> V_41 ;
V_261 = F_51 ( V_117 ) ;
F_52 ( V_117 , V_377 -> V_140 , false , 1 ,
V_26 ) ;
V_117 -> V_28 = V_29 ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_26 , V_377 -> V_140 ) ;
V_261 -> V_264 = F_55 ( F_46 ( V_377 -> V_103 ) ) ;
V_261 -> V_265 = F_55 ( V_377 -> V_103 & 0xFFFFFFFF ) ;
V_261 -> V_148 = F_55 ( V_377 -> V_140 ) ;
V_153 -> V_268 . V_398 = F_55 ( V_396 ) ;
V_153 -> V_268 . V_399 = F_55 ( V_397 ) ;
V_153 -> V_268 . V_400 = F_55 ( V_294 ) ;
F_1 ( V_2 ) ;
F_31 ( & V_2 -> V_178 ) ;
if ( ! F_112 ( & V_2 -> V_31 ,
F_113 ( 12000 ) ) )
V_22 = - 1 ;
else
V_22 = V_2 -> V_30 ;
return V_22 ;
V_385:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_115 ( struct V_1 * V_2 , T_3 * V_401 ,
int V_292 )
{
struct V_116 * V_117 ;
struct F_114 * V_153 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) + 4 , true , 0 ,
V_402 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_402 , sizeof( * V_153 ) + 4 ) ;
V_153 -> V_268 . V_398 = F_55 ( V_403 ) ;
V_153 -> V_268 . V_399 = F_55 ( V_404 ) ;
V_153 -> V_268 . V_292 = F_55 ( V_292 ) ;
V_153 -> V_268 . V_400 = F_55 ( 0x4 ) ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 )
memcpy ( V_401 , V_153 -> V_268 . V_405 , 4 ) ;
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_116 ( struct V_1 * V_2 , T_3 * V_172 ,
struct V_98 * V_260 )
{
struct V_116 * V_117 ;
struct V_406 * V_153 ;
struct V_119 * V_261 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = V_260 -> V_41 ;
V_261 = F_51 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , false , 1 ,
V_407 ) ;
F_54 ( & V_153 -> V_157 , V_35 ,
V_407 , sizeof( * V_153 ) ) ;
memcpy ( V_153 -> V_408 , V_172 , V_174 ) ;
V_261 -> V_264 = F_55 ( F_46 ( V_260 -> V_103 ) ) ;
V_261 -> V_265 = F_55 ( V_260 -> V_103 & 0xFFFFFFFF ) ;
V_261 -> V_148 = F_55 ( V_260 -> V_140 ) ;
V_22 = F_40 ( V_2 ) ;
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_117 ( struct V_1 * V_2 , T_3 V_65 ,
T_3 V_409 , T_3 V_410 )
{
struct V_116 * V_117 ;
struct V_411 * V_153 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_412 ) ;
F_54 ( & V_153 -> V_157 , V_413 ,
V_412 ,
sizeof( * V_153 ) ) ;
V_153 -> V_414 = V_65 ;
V_153 -> V_415 = V_65 ;
V_153 -> V_409 = V_409 ;
V_153 -> V_416 = V_410 ;
V_22 = F_40 ( V_2 ) ;
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_118 ( struct V_1 * V_2 , T_1 V_65 ,
T_1 V_409 , T_1 V_417 , T_1 V_418 , T_5 V_419 )
{
struct V_116 * V_117 ;
struct V_420 * V_153 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_421 ) ;
F_54 ( & V_153 -> V_157 , V_413 ,
V_421 , sizeof( * V_153 ) ) ;
V_153 -> V_157 . V_112 = F_55 ( 4 ) ;
V_153 -> V_419 = F_119 ( V_419 ) ;
V_153 -> V_414 = F_55 ( V_65 ) ;
V_153 -> V_415 = F_55 ( V_65 ) ;
V_153 -> V_417 = F_55 ( V_417 ) ;
V_153 -> V_418 = F_55 ( V_418 ) ;
V_153 -> V_409 = F_55 ( V_409 ) ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_422 * V_39 = F_50 ( V_117 ) ;
V_22 = F_6 ( V_39 -> V_22 ) ;
}
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_120 ( struct V_1 * V_2 , T_5 V_419 ,
T_1 V_423 , struct V_98 * V_377 )
{
struct V_116 * V_117 ;
struct V_424 * V_153 ;
struct V_119 * V_261 ;
int V_22 ;
int V_92 , V_425 = 0 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = V_377 -> V_41 ;
V_261 = F_51 ( V_117 ) ;
F_52 ( V_117 , V_377 -> V_140 , false , 1 ,
V_426 ) ;
F_54 ( & V_153 -> V_157 , V_413 ,
V_426 , V_377 -> V_140 ) ;
V_261 -> V_264 = F_55 ( F_46 ( V_377 -> V_103 ) ) ;
V_261 -> V_265 = F_55 ( V_377 -> V_103 & 0xFFFFFFFF ) ;
V_261 -> V_148 = F_55 ( V_377 -> V_140 ) ;
V_153 -> V_419 = F_119 ( V_419 ) ;
V_153 -> V_427 = F_55 ( V_423 ) ;
for ( V_92 = 0 ; V_92 < V_423 ; V_92 ++ ) {
V_153 -> V_428 [ V_92 ] = ( T_3 ) ( V_419 >> ( V_425 * 8 ) ) ;
V_425 ++ ;
if ( V_425 > 7 )
V_425 = 0 ;
}
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 ) {
struct V_429 * V_39 ;
V_39 = V_377 -> V_41 ;
if ( ( memcmp ( V_39 -> V_430 , V_153 -> V_428 , V_423 ) != 0 ) ||
V_39 -> V_431 ) {
V_22 = - 1 ;
}
}
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_121 ( struct V_1 * V_2 ,
struct V_98 * V_260 )
{
struct V_116 * V_117 ;
struct V_432 * V_153 ;
struct V_119 * V_261 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = V_260 -> V_41 ;
V_261 = F_51 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , false , 1 ,
V_433 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_433 , sizeof( * V_153 ) ) ;
V_261 -> V_264 = F_55 ( F_46 ( V_260 -> V_103 ) ) ;
V_261 -> V_265 = F_55 ( V_260 -> V_103 & 0xFFFFFFFF ) ;
V_261 -> V_148 = F_55 ( V_260 -> V_140 ) ;
V_22 = F_40 ( V_2 ) ;
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_122 ( struct V_1 * V_2 , struct V_98 * V_377 )
{
struct V_116 * V_117 ;
struct V_434 * V_153 ;
struct V_119 * V_261 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = V_377 -> V_41 ;
V_261 = F_51 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , false , 1 ,
V_435 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_435 ,
sizeof( * V_153 ) ) ;
V_261 -> V_264 = F_55 ( F_46 ( V_377 -> V_103 ) ) ;
V_261 -> V_265 = F_55 ( V_377 -> V_103 & 0xFFFFFFFF ) ;
V_261 -> V_148 = F_55 ( V_377 -> V_140 ) ;
V_22 = F_40 ( V_2 ) ;
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_123 ( struct V_1 * V_2 , T_1 V_436 , T_1 V_176 )
{
struct V_116 * V_117 ;
struct V_437 * V_153 ;
int V_22 ;
F_29 ( & V_2 -> V_178 ) ;
V_117 = F_62 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_438 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_438 , sizeof( * V_153 ) ) ;
V_153 -> V_157 . V_176 = V_176 ;
V_153 -> V_439 = F_55 ( V_440 ) ;
V_153 -> V_441 = F_55 ( V_436 ) ;
V_22 = F_40 ( V_2 ) ;
V_180:
F_31 ( & V_2 -> V_178 ) ;
return V_22 ;
}
int F_124 ( struct V_1 * V_2 )
{
struct V_116 * V_117 ;
struct V_442 * V_153 ;
struct V_443 * V_39 ;
struct V_119 * V_261 ;
int V_22 ;
int V_121 = F_125 ( sizeof( * V_153 ) , sizeof( * V_39 ) ) ;
struct V_444 * V_445 ;
struct V_98 V_446 ;
memset ( & V_446 , 0 , sizeof( struct V_98 ) ) ;
V_446 . V_140 = sizeof( struct V_443 ) ;
V_446 . V_41 = F_95 ( V_2 -> V_9 , V_446 . V_140 ,
& V_446 . V_103 ) ;
if ( ! V_446 . V_41 ) {
F_39 ( & V_2 -> V_9 -> V_10 ,
L_15 ) ;
return - V_296 ;
}
if ( F_67 ( & V_2 -> V_149 ) )
return - 1 ;
V_117 = F_61 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = V_446 . V_41 ;
V_261 = F_51 ( V_117 ) ;
F_52 ( V_117 , V_121 , false , 1 ,
V_447 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_447 , V_121 ) ;
V_261 -> V_264 = F_55 ( F_46 ( V_446 . V_103 ) ) ;
V_261 -> V_265 = F_55 ( V_446 . V_103 & 0xFFFFFFFF ) ;
V_261 -> V_148 = F_55 ( V_446 . V_140 ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
V_445 = (struct V_444 * ) ( V_446 . V_41 +
sizeof( struct V_448 ) ) ;
V_2 -> V_449 = V_445 -> V_450 . V_451 ;
}
V_180:
F_68 ( & V_2 -> V_149 ) ;
F_96 ( V_2 -> V_9 , V_446 . V_140 , V_446 . V_41 ,
V_446 . V_103 ) ;
return V_22 ;
}
int F_126 ( struct V_1 * V_2 )
{
struct V_116 * V_117 ;
struct V_452 * V_153 ;
int V_22 ;
if ( F_67 ( & V_2 -> V_149 ) )
return - 1 ;
V_117 = F_61 ( V_2 ) ;
if ( ! V_117 ) {
V_22 = - V_179 ;
goto V_180;
}
V_153 = F_50 ( V_117 ) ;
F_52 ( V_117 , sizeof( * V_153 ) , true , 0 ,
V_453 ) ;
F_54 ( & V_153 -> V_157 , V_29 ,
V_453 , sizeof( * V_153 ) ) ;
V_153 -> V_454 = F_55 ( V_455 |
V_456 ) ;
V_153 -> V_250 = F_55 ( V_456 ) ;
V_22 = F_45 ( V_2 ) ;
if ( ! V_22 ) {
struct V_457 * V_39 = F_50 ( V_117 ) ;
V_2 -> V_458 = F_6 ( V_39 -> V_250 ) &
V_456 ;
}
V_180:
F_68 ( & V_2 -> V_149 ) ;
return V_22 ;
}
