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
V_5 -> V_48 = 0 ;
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
if ( F_18 ( V_5 ) &&
! ( V_58 -> V_61 & V_62 ) )
return;
if ( V_5 -> V_18 & V_63 )
F_19 ( V_5 , V_58 -> V_61 ) ;
}
static void F_20 ( struct V_4 * V_5 ,
struct V_64 * V_58 )
{
if ( V_58 -> V_65 ) {
V_5 -> V_66 = V_58 -> V_67 ;
V_5 -> V_68 &= ~ V_69 ;
V_5 -> V_68 =
V_58 -> V_70 << V_71 ;
}
}
static void F_21 ( struct V_4 * V_5 ,
struct V_72 * V_58 )
{
if ( V_5 -> V_59 . V_60 >= 0 &&
V_58 -> V_73 == V_5 -> V_74 )
V_5 -> V_59 . V_60 = F_22 ( V_58 -> V_75 ) * 10 ;
}
static void F_23 ( struct V_4 * V_5 ,
struct V_76 * V_58 )
{
if ( V_58 -> V_77 )
V_5 -> V_78 = F_22 ( V_58 -> V_79 ) & V_80 ;
else
V_5 -> V_78 = 0 ;
}
static void F_24 ( struct V_4 * V_5 ,
T_1 V_81 , struct V_16 * V_58 )
{
T_3 V_82 = 0 ;
V_82 = ( V_81 >> V_83 ) &
V_84 ;
switch ( V_82 ) {
case V_85 :
F_20 ( V_5 ,
(struct V_64 * ) V_58 ) ;
break;
case V_86 :
F_21 ( V_5 ,
(struct V_72 * ) V_58 ) ;
break;
case V_87 :
F_23 ( V_5 ,
(struct V_76 * ) V_58 ) ;
break;
default:
F_15 ( & V_5 -> V_53 -> V_54 , L_3 ) ;
break;
}
}
static inline bool F_25 ( T_1 V_81 )
{
return ( ( V_81 >> V_88 ) &
V_89 ) ==
V_90 ;
}
static inline bool F_26 ( T_1 V_81 )
{
return ( ( ( V_81 >> V_88 ) &
V_89 ) ==
V_91 ) ;
}
static struct V_16 * F_27 ( struct V_4 * V_5 )
{
struct V_6 * V_92 = & V_5 -> V_8 . V_93 ;
struct V_16 * V_17 = F_28 ( V_92 ) ;
if ( F_6 ( V_17 ) ) {
F_29 ( V_92 ) ;
return V_17 ;
}
return NULL ;
}
void F_30 ( struct V_4 * V_5 )
{
F_31 ( & V_5 -> V_94 ) ;
F_32 ( V_5 , V_5 -> V_8 . V_93 . V_11 , true , 0 ) ;
V_5 -> V_8 . V_95 = true ;
F_33 ( & V_5 -> V_94 ) ;
}
void F_34 ( struct V_4 * V_5 )
{
V_5 -> V_8 . V_95 = false ;
}
int F_35 ( struct V_4 * V_5 )
{
struct V_16 * V_17 ;
int V_96 = 0 , V_29 = 0 ;
struct V_97 * V_8 = & V_5 -> V_8 ;
F_36 ( & V_5 -> V_94 ) ;
while ( ( V_17 = F_27 ( V_5 ) ) ) {
if ( V_17 -> V_18 & V_98 ) {
if ( F_25 ( V_17 -> V_18 ) )
F_17 ( V_5 ,
(struct V_57 * ) V_17 ) ;
else if ( F_26 ( V_17 -> V_18 ) )
F_24 ( V_5 ,
V_17 -> V_18 , V_17 ) ;
} else if ( V_17 -> V_18 & V_99 ) {
V_29 = F_11 ( V_5 , V_17 ) ;
F_37 ( & V_8 -> V_9 . V_100 ) ;
}
F_9 ( V_17 ) ;
V_96 ++ ;
}
if ( V_96 )
F_32 ( V_5 , V_8 -> V_93 . V_11 , V_8 -> V_95 , V_96 ) ;
F_38 ( & V_5 -> V_94 ) ;
return V_29 ;
}
static int F_39 ( struct V_4 * V_5 )
{
#define F_40 120000
int V_101 , V_29 = 0 ;
struct V_97 * V_8 = & V_5 -> V_8 ;
for ( V_101 = 0 ; V_101 < F_40 ; V_101 ++ ) {
if ( F_3 ( V_5 ) )
return - V_102 ;
F_41 () ;
V_29 = F_35 ( V_5 ) ;
F_42 () ;
if ( F_43 ( & V_8 -> V_9 . V_100 ) == 0 )
break;
F_44 ( 100 ) ;
}
if ( V_101 == F_40 ) {
F_16 ( & V_5 -> V_53 -> V_54 , L_4 ) ;
V_5 -> V_103 = true ;
return - V_102 ;
}
return V_29 ;
}
static int F_45 ( struct V_4 * V_5 )
{
int V_29 ;
struct V_1 * V_2 ;
struct V_97 * V_8 = & V_5 -> V_8 ;
T_2 V_104 = V_8 -> V_9 . V_105 ;
struct V_20 * V_44 ;
F_46 ( & V_104 , V_8 -> V_9 . V_106 ) ;
V_2 = F_47 ( & V_8 -> V_9 , V_104 ) ;
V_44 = F_10 ( V_2 -> V_21 , V_2 -> V_22 ) ;
F_2 ( V_5 ) ;
V_29 = F_39 ( V_5 ) ;
if ( V_29 == - V_102 )
goto V_107;
V_29 = V_44 -> V_29 ;
V_107:
return V_29 ;
}
static int F_48 ( struct V_4 * V_5 , void T_4 * V_14 )
{
int V_108 = 0 ;
T_1 V_109 ;
do {
if ( F_3 ( V_5 ) )
return - V_102 ;
V_109 = F_49 ( V_14 ) ;
if ( V_109 == 0xffffffff )
return - 1 ;
V_109 &= V_110 ;
if ( V_109 )
break;
if ( V_108 > 4000 ) {
F_16 ( & V_5 -> V_53 -> V_54 , L_4 ) ;
V_5 -> V_103 = true ;
F_50 ( V_5 ) ;
return - 1 ;
}
F_51 ( 1 ) ;
V_108 ++ ;
} while ( true );
return 0 ;
}
static int F_52 ( struct V_4 * V_5 )
{
int V_29 ;
T_1 V_10 = 0 ;
void T_4 * V_14 = V_5 -> V_14 + V_111 ;
struct V_112 * V_113 = & V_5 -> V_113 ;
struct V_114 * V_115 = V_113 -> V_116 ;
struct V_16 * V_17 = & V_115 -> V_17 ;
V_29 = F_48 ( V_5 , V_14 ) ;
if ( V_29 != 0 )
return V_29 ;
V_10 |= V_117 ;
V_10 |= ( F_53 ( V_113 -> V_118 ) >> 2 ) << 2 ;
F_5 ( V_10 , V_14 ) ;
V_29 = F_48 ( V_5 , V_14 ) ;
if ( V_29 != 0 )
return V_29 ;
V_10 = 0 ;
V_10 |= ( T_1 ) ( V_113 -> V_118 >> 4 ) << 2 ;
F_5 ( V_10 , V_14 ) ;
V_29 = F_48 ( V_5 , V_14 ) ;
if ( V_29 != 0 )
return V_29 ;
if ( F_6 ( V_17 ) ) {
V_29 = F_11 ( V_5 , & V_115 -> V_17 ) ;
F_9 ( V_17 ) ;
if ( V_29 )
return V_29 ;
} else {
F_16 ( & V_5 -> V_53 -> V_54 , L_5 ) ;
return - 1 ;
}
return 0 ;
}
static int F_54 ( struct V_4 * V_5 , T_2 * V_119 )
{
T_1 V_120 ;
if ( F_18 ( V_5 ) )
V_120 = F_49 ( V_5 -> V_14 + V_121 ) ;
else
V_120 = F_49 ( V_5 -> V_122 + V_123 ) ;
* V_119 = V_120 & V_124 ;
if ( ( V_120 >> V_125 ) & V_126 )
return - 1 ;
else
return 0 ;
}
int F_55 ( struct V_4 * V_5 )
{
#define F_56 30
T_1 V_127 ;
int V_29 = 0 , V_101 ;
for ( V_101 = 0 ; V_101 < F_56 ; V_101 ++ ) {
V_127 = F_49 ( V_5 -> V_14 + V_128 ) ;
if ( V_127 & V_129 )
break;
F_51 ( 1000 ) ;
}
if ( V_101 == F_56 )
V_29 = - 1 ;
return V_29 ;
}
int F_57 ( struct V_4 * V_5 )
{
int V_29 ;
T_1 V_127 , V_130 , V_131 ;
V_29 = F_55 ( V_5 ) ;
if ( ! V_29 ) {
V_127 = F_49 ( V_5 -> V_14 + V_128 ) ;
V_130 = V_127 & V_132 ;
V_131 = V_127 & V_133 ;
if ( V_130 && V_131 ) {
F_5 ( V_134 ,
V_5 -> V_14 + V_135 ) ;
V_29 = F_55 ( V_5 ) ;
V_127 = F_49 ( V_5 -> V_14 +
V_128 ) ;
V_127 &= ( V_132 |
V_133 ) ;
if ( V_29 || V_127 )
V_29 = - 1 ;
} else if ( V_130 || V_131 ) {
V_29 = - 1 ;
}
}
return V_29 ;
}
int F_58 ( struct V_4 * V_5 )
{
T_2 V_119 ;
int V_29 , V_136 = 0 ;
struct V_137 * V_54 = & V_5 -> V_53 -> V_54 ;
if ( F_18 ( V_5 ) ) {
V_29 = F_55 ( V_5 ) ;
return V_29 ;
}
do {
V_29 = F_54 ( V_5 , & V_119 ) ;
if ( V_29 ) {
F_16 ( V_54 , L_6 , V_119 ) ;
return - 1 ;
} else if ( V_119 != V_138 ) {
if ( F_59 ( 2000 ) ) {
F_16 ( V_54 , L_7 ) ;
return - V_139 ;
}
V_136 += 2 ;
} else {
return 0 ;
}
} while ( V_136 < 60 );
F_16 ( V_54 , L_8 , V_119 ) ;
return - 1 ;
}
static inline struct V_140 * F_60 ( struct V_1 * V_2 )
{
return & V_2 -> V_3 . V_141 [ 0 ] ;
}
static void F_61 ( struct V_142 * V_143 ,
T_3 V_28 , T_3 V_27 , int V_144 ,
struct V_1 * V_2 , struct V_112 * V_145 )
{
struct V_140 * V_146 ;
unsigned long V_23 = ( unsigned long ) V_143 ;
T_5 V_147 = V_23 ;
V_143 -> V_27 = V_27 ;
V_143 -> V_28 = V_28 ;
V_143 -> V_148 = F_62 ( V_144 - sizeof( * V_143 ) ) ;
V_143 -> V_149 = 0 ;
V_2 -> V_21 = V_147 & 0xFFFFFFFF ;
V_2 -> V_22 = F_53 ( V_147 ) ;
V_2 -> V_150 = V_144 ;
if ( V_145 ) {
V_2 -> V_151 |= ( 1 & V_152 ) <<
V_153 ;
V_146 = F_60 ( V_2 ) ;
V_146 -> V_154 = F_62 ( F_53 ( V_145 -> V_118 ) ) ;
V_146 -> V_155 = F_62 ( V_145 -> V_118 & 0xFFFFFFFF ) ;
V_146 -> V_106 = F_62 ( V_145 -> V_156 ) ;
} else
V_2 -> V_151 |= V_157 ;
F_63 ( V_2 , 8 ) ;
}
static void F_64 ( struct V_158 * V_159 , T_1 V_160 ,
struct V_112 * V_145 )
{
int V_101 , V_161 = F_65 ( F_66 ( V_145 -> V_116 , V_145 -> V_156 ) , V_160 ) ;
T_5 V_118 = ( T_5 ) V_145 -> V_118 ;
for ( V_101 = 0 ; V_101 < V_161 ; V_101 ++ ) {
V_159 [ V_101 ] . V_162 = F_62 ( V_118 & 0xFFFFFFFF ) ;
V_159 [ V_101 ] . V_163 = F_62 ( F_53 ( V_118 ) ) ;
V_118 += V_164 ;
}
}
static T_1 F_67 ( T_1 V_165 )
{
#define F_68 651042
const T_1 V_166 = 10 ;
T_1 V_167 ;
if ( V_165 == 0 )
V_167 = 0 ;
else {
T_1 V_168 = 1000000 / V_165 ;
if ( V_168 == 0 )
V_167 = 1023 ;
else {
V_167 = ( F_68 - V_168 ) * V_166 ;
V_167 /= V_168 ;
V_167 = ( V_167 + V_166 / 2 ) / V_166 ;
V_167 = F_65 ( V_167 , ( T_1 ) 1023 ) ;
}
}
return V_167 ;
}
static inline struct V_1 * F_69 ( struct V_4 * V_5 )
{
struct V_112 * V_113 = & V_5 -> V_113 ;
struct V_1 * V_2
= & ( (struct V_114 * ) ( V_113 -> V_116 ) ) -> V_2 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
return V_2 ;
}
static struct V_1 * F_70 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 . V_9 ;
struct V_1 * V_2 ;
if ( F_43 ( & V_7 -> V_100 ) >= V_7 -> V_106 ) {
F_16 ( & V_5 -> V_53 -> V_54 , L_9 ) ;
return NULL ;
}
V_2 = F_71 ( V_7 ) ;
F_72 ( V_7 ) ;
F_73 ( & V_7 -> V_100 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
return V_2 ;
}
int F_74 ( struct V_4 * V_5 )
{
T_3 * V_2 ;
int V_29 ;
if ( F_18 ( V_5 ) )
return 0 ;
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = ( T_3 * ) F_69 ( V_5 ) ;
* V_2 ++ = 0xFF ;
* V_2 ++ = 0x12 ;
* V_2 ++ = 0x34 ;
* V_2 ++ = 0xFF ;
* V_2 ++ = 0xFF ;
* V_2 ++ = 0x56 ;
* V_2 ++ = 0x78 ;
* V_2 = 0xFF ;
V_29 = F_52 ( V_5 ) ;
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
int F_77 ( struct V_4 * V_5 )
{
T_3 * V_2 ;
int V_29 ;
if ( F_18 ( V_5 ) )
return 0 ;
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = ( T_3 * ) F_69 ( V_5 ) ;
* V_2 ++ = 0xFF ;
* V_2 ++ = 0xAA ;
* V_2 ++ = 0xBB ;
* V_2 ++ = 0xFF ;
* V_2 ++ = 0xFF ;
* V_2 ++ = 0xCC ;
* V_2 ++ = 0xDD ;
* V_2 = 0xFF ;
V_29 = F_52 ( V_5 ) ;
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
int F_78 ( struct V_4 * V_5 ,
struct V_6 * V_170 , int V_171 )
{
struct V_1 * V_2 ;
struct V_172 * V_173 ;
struct V_112 * V_174 = & V_170 -> V_175 ;
int V_29 ;
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_177 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_178 = F_79 ( F_66 ( V_174 -> V_116 , V_174 -> V_156 ) ) ;
F_80 ( struct V_179 , V_65 , V_173 -> V_180 , 1 ) ;
F_80 ( struct V_179 , V_156 , V_173 -> V_180 , 0 ) ;
F_80 ( struct V_179 , V_181 , V_173 -> V_180 ,
F_81 ( V_170 -> V_106 / 256 ) ) ;
F_80 ( struct V_179 , V_182 , V_173 -> V_180 ,
F_67 ( V_171 ) ) ;
F_63 ( V_173 -> V_180 , sizeof( V_173 -> V_180 ) ) ;
F_64 ( V_173 -> V_159 , F_82 ( V_173 -> V_159 ) , V_174 ) ;
V_29 = F_52 ( V_5 ) ;
if ( ! V_29 ) {
struct V_183 * V_44 = F_1 ( V_2 ) ;
V_170 -> V_11 = F_22 ( V_44 -> V_184 ) ;
V_170 -> V_185 = true ;
}
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
int F_83 ( struct V_4 * V_5 , T_3 * V_186 ,
bool V_187 , T_1 V_188 , T_1 V_189 )
{
struct V_1 * V_2 ;
struct V_190 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_193 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> type = V_194 ;
if ( V_187 ) {
V_173 -> V_187 = 1 ;
} else {
V_173 -> V_195 = F_79 ( ( T_2 ) V_188 ) ;
V_173 -> V_189 = F_62 ( V_189 ) ;
V_173 -> V_187 = 0 ;
}
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_196 * V_44 = F_1 ( V_2 ) ;
memcpy ( V_186 , V_44 -> V_197 . V_23 , V_198 ) ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_84 ( struct V_4 * V_5 , T_3 * V_186 ,
T_1 V_195 , T_1 * V_189 , T_1 V_199 )
{
struct V_1 * V_2 ;
struct V_200 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_201 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_176 . V_199 = V_199 ;
V_173 -> V_195 = F_62 ( V_195 ) ;
memcpy ( V_173 -> V_202 , V_186 , V_198 ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_203 * V_44 = F_1 ( V_2 ) ;
* V_189 = F_7 ( V_44 -> V_189 ) ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
if ( V_29 == V_52 )
V_29 = - V_204 ;
return V_29 ;
}
int F_85 ( struct V_4 * V_5 , T_1 V_195 , int V_189 , T_1 V_205 )
{
struct V_1 * V_2 ;
struct V_206 * V_173 ;
int V_29 ;
if ( V_189 == - 1 )
return 0 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_207 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_176 . V_199 = V_205 ;
V_173 -> V_195 = F_62 ( V_195 ) ;
V_173 -> V_189 = F_62 ( V_189 ) ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_86 ( struct V_4 * V_5 , struct V_6 * V_93 ,
struct V_6 * V_170 , bool V_208 , int V_209 )
{
struct V_1 * V_2 ;
struct V_210 * V_173 ;
struct V_112 * V_174 = & V_93 -> V_175 ;
void * V_211 ;
int V_29 ;
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
V_173 = F_1 ( V_2 ) ;
V_211 = & V_173 -> V_180 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_212 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_178 = F_79 ( F_66 ( V_174 -> V_116 , V_174 -> V_156 ) ) ;
if ( F_18 ( V_5 ) ) {
V_173 -> V_176 . V_149 = 2 ;
V_173 -> V_213 = 1 ;
F_80 ( struct V_214 , V_215 , V_211 ,
V_208 ) ;
F_80 ( struct V_214 , V_181 , V_211 ,
F_81 ( V_93 -> V_106 / 256 ) ) ;
F_80 ( struct V_214 , V_65 , V_211 , 1 ) ;
F_80 ( struct V_214 , V_216 ,
V_211 , 1 ) ;
F_80 ( struct V_214 , V_217 ,
V_211 , V_170 -> V_11 ) ;
} else {
F_80 ( struct V_218 , V_219 , V_211 ,
V_209 ) ;
F_80 ( struct V_218 , V_215 ,
V_211 , V_208 ) ;
F_80 ( struct V_218 , V_181 , V_211 ,
F_81 ( V_93 -> V_106 / 256 ) ) ;
F_80 ( struct V_218 , V_65 , V_211 , 1 ) ;
F_80 ( struct V_218 , V_216 , V_211 , 1 ) ;
F_80 ( struct V_218 , V_217 , V_211 , V_170 -> V_11 ) ;
}
F_63 ( V_211 , sizeof( V_173 -> V_180 ) ) ;
F_64 ( V_173 -> V_159 , F_82 ( V_173 -> V_159 ) , V_174 ) ;
V_29 = F_52 ( V_5 ) ;
if ( ! V_29 ) {
struct V_220 * V_44 = F_1 ( V_2 ) ;
V_93 -> V_11 = F_22 ( V_44 -> V_221 ) ;
V_93 -> V_185 = true ;
}
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
static T_1 F_87 ( int V_222 )
{
T_1 V_223 = F_88 ( V_222 ) ;
if ( V_223 == 16 )
V_223 = 0 ;
return V_223 ;
}
int F_89 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_93 )
{
struct V_1 * V_2 ;
struct V_224 * V_173 ;
struct V_112 * V_174 = & V_7 -> V_175 ;
void * V_211 ;
int V_29 ;
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
V_173 = F_1 ( V_2 ) ;
V_211 = & V_173 -> V_180 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_225 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_178 = F_79 ( F_66 ( V_174 -> V_116 , V_174 -> V_156 ) ) ;
if ( F_18 ( V_5 ) ) {
V_173 -> V_176 . V_149 = 1 ;
V_173 -> V_221 = F_79 ( V_93 -> V_11 ) ;
F_80 ( struct V_226 , V_227 , V_211 ,
F_87 ( V_7 -> V_106 ) ) ;
F_80 ( struct V_226 , V_65 , V_211 , 1 ) ;
F_80 ( struct V_226 , V_228 ,
V_211 , V_93 -> V_11 ) ;
F_80 ( struct V_226 , V_229 ,
V_211 , 1 ) ;
} else {
F_80 ( struct V_230 , V_65 , V_211 , 1 ) ;
F_80 ( struct V_230 , V_227 , V_211 ,
F_87 ( V_7 -> V_106 ) ) ;
F_80 ( struct V_230 , V_221 , V_211 , V_93 -> V_11 ) ;
}
V_173 -> V_231 [ 0 ] = F_62 ( 0x00000022 ) ;
F_63 ( V_211 , sizeof( V_173 -> V_180 ) ) ;
F_64 ( V_173 -> V_159 , F_82 ( V_173 -> V_159 ) , V_174 ) ;
V_29 = F_52 ( V_5 ) ;
if ( ! V_29 ) {
struct V_232 * V_44 = F_1 ( V_2 ) ;
V_7 -> V_11 = F_22 ( V_44 -> V_11 ) ;
V_7 -> V_185 = true ;
}
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
int F_90 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_93 )
{
struct V_1 * V_2 ;
struct V_233 * V_173 ;
struct V_112 * V_174 = & V_7 -> V_175 ;
void * V_211 ;
int V_29 ;
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
V_173 = F_1 ( V_2 ) ;
V_211 = & V_173 -> V_180 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_234 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_178 = F_79 ( F_66 ( V_174 -> V_116 , V_174 -> V_156 ) ) ;
F_80 ( struct V_230 , V_65 , V_211 , 1 ) ;
F_80 ( struct V_230 , V_227 , V_211 ,
F_87 ( V_7 -> V_106 ) ) ;
F_80 ( struct V_230 , V_221 , V_211 , V_93 -> V_11 ) ;
F_63 ( V_211 , sizeof( V_173 -> V_180 ) ) ;
F_64 ( V_173 -> V_159 , F_82 ( V_173 -> V_159 ) , V_174 ) ;
V_29 = F_52 ( V_5 ) ;
if ( ! V_29 ) {
struct V_232 * V_44 = F_1 ( V_2 ) ;
V_7 -> V_11 = F_22 ( V_44 -> V_11 ) ;
V_7 -> V_185 = true ;
}
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
int F_91 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_93 )
{
int V_29 ;
V_29 = F_89 ( V_5 , V_7 , V_93 ) ;
if ( V_29 && ! F_18 ( V_5 ) ) {
F_15 ( & V_5 -> V_53 -> V_54 , L_10
L_11
L_12 ) ;
V_29 = F_90 ( V_5 , V_7 , V_93 ) ;
}
return V_29 ;
}
int F_92 ( struct V_4 * V_5 ,
struct V_6 * V_235 ,
struct V_6 * V_93 )
{
struct V_1 * V_2 ;
struct V_236 * V_173 ;
struct V_112 * V_174 = & V_235 -> V_175 ;
void * V_211 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
V_211 = & V_173 -> V_180 ;
F_61 ( & V_173 -> V_176 , V_40 ,
V_237 , sizeof( * V_173 ) , V_2 , NULL ) ;
if ( F_18 ( V_5 ) ) {
V_173 -> V_176 . V_149 = 1 ;
F_80 ( struct V_238 , V_195 , V_211 ,
V_5 -> V_188 ) ;
}
V_173 -> V_178 = F_66 ( V_174 -> V_116 , V_174 -> V_156 ) ;
V_173 -> V_239 = V_240 ;
V_173 -> type = V_241 ;
F_80 ( struct V_238 , V_242 , V_211 ,
F_87 ( V_235 -> V_106 ) ) ;
F_80 ( struct V_238 , V_243 , V_211 , 1 ) ;
F_80 ( struct V_238 , V_244 , V_211 , V_93 -> V_11 ) ;
F_63 ( V_211 , sizeof( V_173 -> V_180 ) ) ;
F_64 ( V_173 -> V_159 , F_82 ( V_173 -> V_159 ) , V_174 ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_245 * V_44 = F_1 ( V_2 ) ;
V_235 -> V_11 = F_22 ( V_44 -> V_246 ) ;
V_235 -> V_185 = true ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_93 ( struct V_4 * V_5 ,
struct V_6 * V_247 , T_2 V_221 , T_2 V_248 ,
T_1 V_195 , T_1 V_249 , T_3 * V_250 )
{
struct V_1 * V_2 ;
struct V_251 * V_173 ;
struct V_112 * V_174 = & V_247 -> V_175 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_40 ,
V_252 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_221 = F_79 ( V_221 ) ;
V_173 -> V_248 = F_88 ( V_248 ) - 1 ;
V_173 -> V_178 = 2 ;
F_64 ( V_173 -> V_159 , F_82 ( V_173 -> V_159 ) , V_174 ) ;
V_173 -> V_253 = F_62 ( V_195 ) ;
V_173 -> V_254 = F_79 ( V_255 ) ;
V_173 -> V_256 = F_62 ( V_249 ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_257 * V_44 = F_1 ( V_2 ) ;
V_247 -> V_11 = F_22 ( V_44 -> V_11 ) ;
V_247 -> V_185 = true ;
* V_250 = V_44 -> V_250 ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_94 ( struct V_4 * V_5 , struct V_6 * V_9 ,
int V_258 )
{
struct V_1 * V_2 ;
struct V_259 * V_173 ;
T_3 V_260 = 0 , V_27 = 0 ;
int V_29 ;
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
V_173 = F_1 ( V_2 ) ;
switch ( V_258 ) {
case V_261 :
V_260 = V_34 ;
V_27 = V_262 ;
break;
case V_263 :
V_260 = V_34 ;
V_27 = V_264 ;
break;
case V_265 :
V_260 = V_40 ;
V_27 = V_266 ;
break;
case V_267 :
V_260 = V_40 ;
V_27 = V_268 ;
break;
case V_269 :
V_260 = V_34 ;
V_27 = V_270 ;
break;
default:
F_95 () ;
}
F_61 ( & V_173 -> V_176 , V_260 , V_27 , sizeof( * V_173 ) , V_2 ,
NULL ) ;
V_173 -> V_11 = F_79 ( V_9 -> V_11 ) ;
V_29 = F_52 ( V_5 ) ;
if ( ! V_29 )
V_9 -> V_185 = false ;
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
int F_96 ( struct V_4 * V_5 , struct V_6 * V_9 )
{
struct V_1 * V_2 ;
struct V_259 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_40 ,
V_268 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_11 = F_79 ( V_9 -> V_11 ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 )
V_9 -> V_185 = false ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_97 ( struct V_4 * V_5 , T_1 V_271 , T_1 V_272 ,
T_1 * V_188 , T_1 V_199 )
{
struct V_1 * V_2 ;
struct V_273 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_274 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_176 . V_199 = V_199 ;
V_173 -> V_275 = F_62 ( V_271 ) ;
V_173 -> V_276 = F_62 ( V_272 ) ;
V_173 -> V_277 = true ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_278 * V_44 = F_1 ( V_2 ) ;
* V_188 = F_7 ( V_44 -> V_253 ) ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_98 ( struct V_4 * V_5 , int V_253 , T_1 V_199 )
{
struct V_1 * V_2 ;
struct V_279 * V_173 ;
int V_29 ;
if ( V_253 == - 1 )
return 0 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_280 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_176 . V_199 = V_199 ;
V_173 -> V_253 = F_62 ( V_253 ) ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_99 ( struct V_4 * V_5 , struct V_112 * V_281 )
{
struct V_1 * V_2 ;
struct V_142 * V_176 ;
int V_29 = 0 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_176 = V_281 -> V_116 ;
F_61 ( V_176 , V_40 ,
V_38 , V_281 -> V_156 , V_2 , V_281 ) ;
if ( V_5 -> V_282 == V_283 )
V_176 -> V_149 = 1 ;
F_2 ( V_5 ) ;
V_5 -> V_41 = true ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_100 ( struct V_4 * V_5 ,
struct V_112 * V_281 )
{
struct V_1 * V_2 ;
struct V_284 * V_173 ;
int V_29 = 0 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_281 -> V_116 ;
F_61 ( & V_173 -> V_176 , V_40 ,
V_39 , V_281 -> V_156 , V_2 ,
V_281 ) ;
V_173 -> V_285 . V_286 . V_287 = F_79 ( V_5 -> V_288 ) ;
V_173 -> V_285 . V_286 . V_289 = 0 ;
F_2 ( V_5 ) ;
V_5 -> V_41 = true ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
static int F_101 ( int V_290 )
{
switch ( V_290 ) {
case V_291 :
return 0 ;
case V_292 :
return 10 ;
case V_293 :
return 100 ;
case V_294 :
return 1000 ;
case V_295 :
return 10000 ;
}
return 0 ;
}
int F_102 ( struct V_4 * V_5 , T_2 * V_60 ,
T_3 * V_296 , T_1 V_205 )
{
struct V_1 * V_2 ;
struct V_297 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
if ( V_296 )
* V_296 = V_298 ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_299 , sizeof( * V_173 ) , V_2 , NULL ) ;
if ( V_5 -> V_282 == V_283 || F_18 ( V_5 ) )
V_173 -> V_176 . V_149 = 1 ;
V_173 -> V_176 . V_199 = V_205 ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_300 * V_44 = F_1 ( V_2 ) ;
if ( V_60 ) {
* V_60 = V_44 -> V_60 ?
F_22 ( V_44 -> V_60 ) * 10 :
F_101 ( V_44 -> V_290 ) ;
if ( ! V_44 -> V_301 )
* V_60 = 0 ;
}
if ( V_296 )
* V_296 = V_44 -> V_301 ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_103 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_302 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_42 , sizeof( * V_173 ) ,
V_2 , NULL ) ;
F_2 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_104 ( struct V_4 * V_5 , T_1 * V_303 )
{
struct V_1 * V_2 ;
struct V_304 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_305 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_306 = F_62 ( V_307 ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_308 * V_44 = F_1 ( V_2 ) ;
if ( V_303 && V_44 -> V_303 )
* V_303 = F_7 ( V_44 -> V_303 ) -
sizeof( T_1 ) ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
void F_105 ( struct V_4 * V_5 , T_1 V_309 , void * V_310 )
{
struct V_112 V_311 ;
struct V_1 * V_2 ;
struct V_304 * V_173 ;
T_1 V_312 = 0 , V_313 , V_314 ,
V_315 = sizeof( T_1 ) , V_316 ;
int V_29 ;
if ( V_309 == 0 )
return;
V_313 = V_309 ;
V_311 . V_156 = sizeof( struct V_304 ) + 60 * 1024 ;
V_311 . V_116 = F_106 ( V_5 -> V_53 ,
V_311 . V_156 ,
& V_311 . V_118 ) ;
if ( ! V_311 . V_116 ) {
V_29 = - V_317 ;
F_16 ( & V_5 -> V_53 -> V_54 ,
L_13 ) ;
return;
}
F_31 ( & V_5 -> V_191 ) ;
while ( V_313 ) {
V_314 = F_65 ( V_313 , ( T_1 ) 60 * 1024 ) ;
V_313 -= V_314 ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_311 . V_116 ;
V_316 = sizeof( struct V_304 ) + V_314 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_305 , V_316 , V_2 ,
& V_311 ) ;
V_173 -> V_306 = F_62 ( V_318 ) ;
V_173 -> V_319 = F_62 ( V_315 ) ;
V_173 -> V_320 = F_62 ( V_314 ) ;
V_173 -> V_321 = F_62 ( V_314 ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_308 * V_44 = V_311 . V_116 ;
memcpy ( V_310 + V_312 ,
V_44 -> V_322 ,
F_7 ( V_44 -> V_320 ) ) ;
} else {
F_16 ( & V_5 -> V_53 -> V_54 , L_14 ) ;
goto V_130;
}
V_312 += V_314 ;
V_315 += V_314 ;
}
V_130:
F_107 ( V_5 -> V_53 , V_311 . V_156 ,
V_311 . V_116 ,
V_311 . V_118 ) ;
F_33 ( & V_5 -> V_191 ) ;
}
int F_108 ( struct V_4 * V_5 , char * V_323 ,
char * V_324 )
{
struct V_1 * V_2 ;
struct V_325 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_326 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_327 * V_44 = F_1 ( V_2 ) ;
strcpy ( V_323 , V_44 -> V_328 ) ;
if ( V_324 )
strcpy ( V_324 , V_44 -> V_329 ) ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_109 ( struct V_4 * V_5 , T_1 V_184 , T_1 V_330 )
{
struct V_1 * V_2 ;
struct V_331 * V_173 ;
int V_29 = 0 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_332 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_333 = F_62 ( 1 ) ;
V_173 -> V_334 [ 0 ] . V_184 = F_62 ( V_184 ) ;
V_173 -> V_334 [ 0 ] . V_335 = 0 ;
V_173 -> V_334 [ 0 ] . V_336 = F_62 ( V_330 ) ;
F_2 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_110 ( struct V_4 * V_5 , T_1 V_195 , T_2 * V_337 ,
T_1 V_96 , bool V_338 , bool V_339 )
{
struct V_1 * V_2 ;
struct V_340 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_341 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_253 = V_195 ;
V_173 -> V_339 = V_339 ;
V_173 -> V_338 = V_338 ;
V_173 -> V_342 = V_96 ;
if ( ! V_339 ) {
memcpy ( V_173 -> V_343 , V_337 ,
V_173 -> V_342 * sizeof( V_337 [ 0 ] ) ) ;
}
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_111 ( struct V_4 * V_5 , T_1 V_18 , T_1 V_344 )
{
struct V_1 * V_2 ;
struct V_112 * V_145 = & V_5 -> V_345 ;
struct V_346 * V_173 = V_145 -> V_116 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
memset ( V_173 , 0 , sizeof( * V_173 ) ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_347 , sizeof( * V_173 ) ,
V_2 , V_145 ) ;
V_173 -> V_195 = F_62 ( V_5 -> V_188 ) ;
if ( V_18 & V_348 ) {
V_173 -> V_349 = F_62 ( V_350 |
V_351 ) ;
if ( V_344 == V_352 )
V_173 -> V_353 = F_62 ( V_350 |
V_351 ) ;
} else if ( V_18 & V_354 ) {
V_173 -> V_349 = V_173 -> V_353 =
F_62 ( V_355 ) ;
} else {
struct V_356 * V_357 ;
int V_101 = 0 ;
V_173 -> V_349 = V_173 -> V_353 =
F_62 ( V_358 ) ;
if ( ! F_18 ( V_5 ) || F_112 ( V_5 ) )
V_173 -> V_349 |=
F_62 ( V_355 ) ;
V_173 -> V_359 = F_62 ( F_113 ( V_5 -> V_360 ) ) ;
F_114 (ha, adapter->netdev)
memcpy ( V_173 -> V_361 [ V_101 ++ ] . V_362 , V_357 -> V_23 , V_198 ) ;
}
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_115 ( struct V_4 * V_5 , T_1 V_363 , T_1 V_364 )
{
struct V_1 * V_2 ;
struct V_365 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_366 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_367 = F_79 ( ( T_2 ) V_363 ) ;
V_173 -> V_368 = F_79 ( ( T_2 ) V_364 ) ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_116 ( struct V_4 * V_5 , T_1 * V_363 , T_1 * V_364 )
{
struct V_1 * V_2 ;
struct V_369 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_370 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_371 * V_44 =
F_1 ( V_2 ) ;
* V_363 = F_22 ( V_44 -> V_367 ) ;
* V_364 = F_22 ( V_44 -> V_368 ) ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_117 ( struct V_4 * V_5 , T_1 * V_74 ,
T_1 * V_372 , T_1 * V_373 )
{
struct V_1 * V_2 ;
struct V_374 * V_173 ;
int V_29 ;
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_375 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_29 = F_52 ( V_5 ) ;
if ( ! V_29 ) {
struct V_376 * V_44 = F_1 ( V_2 ) ;
* V_74 = F_7 ( V_44 -> V_377 ) ;
* V_372 = F_7 ( V_44 -> V_378 ) ;
* V_373 = F_7 ( V_44 -> V_379 ) ;
}
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
int F_118 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_142 * V_173 ;
int V_29 ;
if ( F_18 ( V_5 ) ) {
V_29 = F_55 ( V_5 ) ;
if ( ! V_29 ) {
F_5 ( V_134 ,
V_5 -> V_14 + V_135 ) ;
V_29 = F_57 ( V_5 ) ;
}
if ( V_29 ) {
F_16 ( & V_5 -> V_53 -> V_54 ,
L_15 ) ;
}
return V_29 ;
}
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
V_173 = F_1 ( V_2 ) ;
F_61 ( V_173 , V_34 ,
V_380 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_29 = F_52 ( V_5 ) ;
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
int F_119 ( struct V_4 * V_5 , T_3 * V_381 , T_2 V_382 )
{
struct V_1 * V_2 ;
struct V_383 * V_173 ;
T_1 V_384 [ 10 ] = { 0x15d43fa5 , 0x2534685a , 0x5f87693a , 0x5668494e ,
0x33cf6a53 , 0x383334c6 , 0x76ac4257 , 0x59b242b2 ,
0x3ea83c02 , 0x4a110304 } ;
int V_29 ;
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_40 ,
V_385 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_195 = F_62 ( V_5 -> V_188 ) ;
V_173 -> V_386 = F_79 ( V_387 | V_388 |
V_389 | V_390 ) ;
if ( F_18 ( V_5 ) || F_120 ( V_5 ) ) {
V_173 -> V_176 . V_149 = 1 ;
V_173 -> V_386 |= F_79 ( V_391 |
V_392 ) ;
}
V_173 -> V_393 = F_79 ( F_88 ( V_382 ) - 1 ) ;
memcpy ( V_173 -> V_394 , V_381 , V_382 ) ;
memcpy ( V_173 -> V_395 , V_384 , sizeof( V_384 ) ) ;
F_63 ( V_173 -> V_395 , sizeof( V_173 -> V_395 ) ) ;
V_29 = F_52 ( V_5 ) ;
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
int F_121 ( struct V_4 * V_5 , T_3 V_74 ,
T_3 V_396 , T_3 V_397 , T_3 V_398 )
{
struct V_1 * V_2 ;
struct V_399 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_400 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_74 = V_74 ;
V_173 -> V_401 = V_398 ;
V_173 -> V_402 = V_396 ;
V_173 -> V_403 = V_397 ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_122 ( struct V_4 * V_5 , T_3 V_74 , T_1 * V_398 )
{
struct V_1 * V_2 ;
struct V_404 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_405 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_74 = V_74 ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_406 * V_44 =
F_1 ( V_2 ) ;
* V_398 = V_44 -> V_401 ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_123 ( struct V_4 * V_5 , struct V_112 * V_407 ,
T_1 V_408 , T_1 V_409 ,
const char * V_410 , T_1 * V_411 ,
T_3 * V_412 , T_3 * V_413 )
{
struct V_1 * V_2 ;
struct V_414 * V_173 ;
struct V_415 * V_44 ;
void * V_211 = NULL ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_5 -> V_35 = 0 ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_416;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_33 ,
sizeof( struct V_414 ) , V_2 ,
NULL ) ;
V_211 = & V_173 -> V_180 ;
F_80 ( struct V_417 ,
V_418 , V_211 , V_408 ) ;
if ( V_408 == 0 )
F_80 ( struct V_417 ,
V_419 , V_211 , 1 ) ;
else
F_80 ( struct V_417 ,
V_419 , V_211 , 0 ) ;
F_63 ( V_211 , sizeof( V_173 -> V_180 ) ) ;
V_173 -> V_420 = F_62 ( V_409 ) ;
strcpy ( V_173 -> V_421 , V_410 ) ;
V_173 -> V_422 = F_62 ( 1 ) ;
V_173 -> V_309 = F_62 ( V_408 ) ;
V_173 -> V_423 = F_62 ( ( V_407 -> V_118 +
sizeof( struct V_414 ) )
& 0xFFFFFFFF ) ;
V_173 -> V_424 = F_62 ( F_53 ( V_407 -> V_118 +
sizeof( struct V_414 ) ) ) ;
F_2 ( V_5 ) ;
F_33 ( & V_5 -> V_191 ) ;
if ( ! F_124 ( & V_5 -> V_36 ,
F_125 ( 30000 ) ) )
V_29 = - 1 ;
else
V_29 = V_5 -> V_35 ;
V_44 = F_1 ( V_2 ) ;
if ( ! V_29 ) {
* V_411 = F_7 ( V_44 -> V_425 ) ;
* V_412 = V_44 -> V_412 ;
} else {
* V_413 = V_44 -> V_426 ;
}
return V_29 ;
V_416:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_126 ( struct V_4 * V_5 , struct V_112 * V_407 ,
T_1 V_408 , T_1 V_409 , const char * V_410 ,
T_1 * V_427 , T_1 * V_419 , T_3 * V_413 )
{
struct V_1 * V_2 ;
struct V_428 * V_173 ;
struct V_429 * V_44 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_416;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_430 ,
sizeof( struct V_428 ) , V_2 ,
NULL ) ;
V_173 -> V_431 = F_62 ( V_408 ) ;
V_173 -> V_432 = F_62 ( V_409 ) ;
strcpy ( V_173 -> V_421 , V_410 ) ;
V_173 -> V_422 = F_62 ( 1 ) ;
V_173 -> V_309 = F_62 ( V_408 ) ;
V_173 -> V_423 = F_62 ( ( V_407 -> V_118 & 0xFFFFFFFF ) ) ;
V_173 -> V_424 = F_62 ( F_53 ( V_407 -> V_118 ) ) ;
V_29 = F_45 ( V_5 ) ;
V_44 = F_1 ( V_2 ) ;
if ( ! V_29 ) {
* V_427 = F_7 ( V_44 -> V_433 ) ;
* V_419 = F_7 ( V_44 -> V_419 ) ;
} else {
* V_413 = V_44 -> V_426 ;
}
V_416:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_127 ( struct V_4 * V_5 , struct V_112 * V_407 ,
T_1 V_434 , T_1 V_435 , T_1 V_314 )
{
struct V_1 * V_2 ;
struct F_127 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_5 -> V_35 = 0 ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_416;
}
V_173 = V_407 -> V_116 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_32 , V_407 -> V_156 , V_2 , V_407 ) ;
V_173 -> V_286 . V_436 = F_62 ( V_434 ) ;
V_173 -> V_286 . V_437 = F_62 ( V_435 ) ;
V_173 -> V_286 . V_438 = F_62 ( V_314 ) ;
F_2 ( V_5 ) ;
F_33 ( & V_5 -> V_191 ) ;
if ( ! F_124 ( & V_5 -> V_36 ,
F_125 ( 40000 ) ) )
V_29 = - 1 ;
else
V_29 = V_5 -> V_35 ;
return V_29 ;
V_416:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_128 ( struct V_4 * V_5 , T_3 * V_439 ,
int V_312 )
{
struct V_1 * V_2 ;
struct F_127 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_440 , sizeof( * V_173 ) + 4 , V_2 , NULL ) ;
V_173 -> V_286 . V_436 = F_62 ( V_441 ) ;
V_173 -> V_286 . V_437 = F_62 ( V_442 ) ;
V_173 -> V_286 . V_312 = F_62 ( V_312 ) ;
V_173 -> V_286 . V_438 = F_62 ( 0x4 ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 )
memcpy ( V_439 , V_173 -> V_286 . V_443 , 4 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_129 ( struct V_4 * V_5 , T_3 * V_197 ,
struct V_112 * V_281 )
{
struct V_1 * V_2 ;
struct V_444 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_281 -> V_116 ;
F_61 ( & V_173 -> V_176 , V_40 ,
V_445 , sizeof( * V_173 ) , V_2 ,
V_281 ) ;
memcpy ( V_173 -> V_446 , V_197 , V_198 ) ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_130 ( struct V_4 * V_5 , T_3 V_74 ,
T_3 V_447 , T_3 V_448 )
{
struct V_1 * V_2 ;
struct V_449 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_450 ,
V_451 , sizeof( * V_173 ) , V_2 ,
NULL ) ;
V_173 -> V_452 = V_74 ;
V_173 -> V_453 = V_74 ;
V_173 -> V_447 = V_447 ;
V_173 -> V_454 = V_448 ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_131 ( struct V_4 * V_5 , T_1 V_74 ,
T_1 V_447 , T_1 V_455 , T_1 V_456 , T_5 V_457 )
{
struct V_1 * V_2 ;
struct V_458 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_450 ,
V_459 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_176 . V_136 = F_62 ( 4 ) ;
V_173 -> V_457 = F_132 ( V_457 ) ;
V_173 -> V_452 = F_62 ( V_74 ) ;
V_173 -> V_453 = F_62 ( V_74 ) ;
V_173 -> V_455 = F_62 ( V_455 ) ;
V_173 -> V_456 = F_62 ( V_456 ) ;
V_173 -> V_447 = F_62 ( V_447 ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_460 * V_44 = F_1 ( V_2 ) ;
V_29 = F_7 ( V_44 -> V_29 ) ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_133 ( struct V_4 * V_5 , T_5 V_457 ,
T_1 V_461 , struct V_112 * V_407 )
{
struct V_1 * V_2 ;
struct V_462 * V_173 ;
int V_29 ;
int V_101 , V_463 = 0 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_407 -> V_116 ;
F_61 ( & V_173 -> V_176 , V_450 ,
V_464 , V_407 -> V_156 , V_2 , V_407 ) ;
V_173 -> V_457 = F_132 ( V_457 ) ;
V_173 -> V_465 = F_62 ( V_461 ) ;
for ( V_101 = 0 ; V_101 < V_461 ; V_101 ++ ) {
V_173 -> V_466 [ V_101 ] = ( T_3 ) ( V_457 >> ( V_463 * 8 ) ) ;
V_463 ++ ;
if ( V_463 > 7 )
V_463 = 0 ;
}
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_467 * V_44 ;
V_44 = V_407 -> V_116 ;
if ( ( memcmp ( V_44 -> V_468 , V_173 -> V_466 , V_461 ) != 0 ) ||
V_44 -> V_469 ) {
V_29 = - 1 ;
}
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_134 ( struct V_4 * V_5 ,
struct V_112 * V_281 )
{
struct V_1 * V_2 ;
struct V_470 * V_173 ;
struct V_140 * V_146 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_281 -> V_116 ;
V_146 = F_60 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_471 , sizeof( * V_173 ) , V_2 ,
V_281 ) ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_135 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_472 * V_173 ;
struct V_112 V_407 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_407 . V_156 = sizeof( struct V_472 ) ;
V_407 . V_116 = F_106 ( V_5 -> V_53 , V_407 . V_156 ,
& V_407 . V_118 ) ;
if ( ! V_407 . V_116 ) {
F_16 ( & V_5 -> V_53 -> V_54 , L_16 ) ;
V_29 = - V_317 ;
goto V_130;
}
V_173 = V_407 . V_116 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_473 , sizeof( * V_173 ) ,
V_2 , & V_407 ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_474 * V_475 =
V_407 . V_116 + sizeof( struct V_142 ) ;
V_5 -> V_59 . V_476 = F_22 ( V_475 -> V_476 ) ;
V_5 -> V_59 . V_477 =
F_22 ( V_475 -> V_477 ) ;
V_5 -> V_59 . V_478 =
F_22 ( V_475 -> V_478 ) ;
V_5 -> V_59 . V_479 =
F_22 ( V_475 -> V_479 ) ;
V_5 -> V_59 . V_480 =
F_7 ( V_475 -> V_480 ) ;
}
F_107 ( V_5 -> V_53 , V_407 . V_156 ,
V_407 . V_116 , V_407 . V_118 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_136 ( struct V_4 * V_5 , T_1 V_481 , T_1 V_199 )
{
struct V_1 * V_2 ;
struct V_482 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_483 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_176 . V_199 = V_199 ;
V_173 -> V_484 = F_62 ( V_485 ) ;
V_173 -> V_486 = F_62 ( V_481 ) ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_137 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_487 * V_173 ;
struct V_488 * V_44 ;
int V_29 ;
int V_316 = F_138 ( sizeof( * V_173 ) , sizeof( * V_44 ) ) ;
struct V_489 * V_490 ;
struct V_112 V_491 ;
memset ( & V_491 , 0 , sizeof( struct V_112 ) ) ;
V_491 . V_156 = sizeof( struct V_488 ) ;
V_491 . V_116 = F_106 ( V_5 -> V_53 , V_491 . V_156 ,
& V_491 . V_118 ) ;
if ( ! V_491 . V_116 ) {
F_16 ( & V_5 -> V_53 -> V_54 ,
L_17 ) ;
return - V_317 ;
}
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_491 . V_116 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_492 , V_316 , V_2 ,
& V_491 ) ;
V_29 = F_52 ( V_5 ) ;
if ( ! V_29 ) {
V_490 = V_491 . V_116 + sizeof( struct V_20 ) ;
V_5 -> V_288 = V_490 -> V_493 . V_494 ;
}
V_130:
F_76 ( & V_5 -> V_169 ) ;
F_107 ( V_5 -> V_53 , V_491 . V_156 , V_491 . V_116 ,
V_491 . V_118 ) ;
return V_29 ;
}
int F_139 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_495 * V_173 ;
int V_29 ;
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_496 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_497 = F_62 ( V_498 |
V_499 ) ;
V_173 -> V_271 = F_62 ( V_499 ) ;
V_29 = F_52 ( V_5 ) ;
if ( ! V_29 ) {
struct V_500 * V_44 = F_1 ( V_2 ) ;
V_5 -> V_501 = F_7 ( V_44 -> V_271 ) &
V_499 ;
if ( ! V_5 -> V_501 )
F_15 ( & V_5 -> V_53 -> V_54 ,
L_18 ) ;
}
V_130:
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
int F_140 ( struct V_4 * V_5 , T_3 * V_197 ,
bool * V_502 , T_1 * V_189 , T_3 V_199 )
{
struct V_1 * V_2 ;
struct V_503 * V_173 ;
int V_29 ;
int V_504 ;
struct V_112 V_505 ;
int V_101 ;
memset ( & V_505 , 0 , sizeof( struct V_112 ) ) ;
V_505 . V_156 = sizeof( struct V_506 ) ;
V_505 . V_116 = F_106 ( V_5 -> V_53 ,
V_505 . V_156 ,
& V_505 . V_118 ) ;
if ( ! V_505 . V_116 ) {
F_16 ( & V_5 -> V_53 -> V_54 ,
L_19 ) ;
return - V_317 ;
}
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_107;
}
V_173 = V_505 . V_116 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_507 , sizeof( * V_173 ) ,
V_2 , & V_505 ) ;
V_173 -> V_176 . V_199 = V_199 ;
V_173 -> V_508 = V_194 ;
V_173 -> V_509 = 1 ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_506 * V_44 =
V_505 . V_116 ;
V_504 = V_44 -> V_510 + V_44 -> V_511 ;
for ( V_101 = 0 ; V_101 < V_504 ; V_101 ++ ) {
struct V_512 * V_513 ;
T_2 V_514 ;
T_1 V_515 ;
V_513 = & V_44 -> V_516 [ V_101 ] ;
V_514 = F_22 ( V_513 -> V_514 ) ;
if ( V_514 == sizeof( T_1 ) ) {
* V_502 = true ;
V_515 = V_513 -> V_517 . V_518 . V_515 ;
* V_189 = F_7 ( V_515 ) ;
goto V_107;
}
}
* V_502 = false ;
memcpy ( V_197 , V_44 -> V_516 [ 0 ] . V_517 . V_519 ,
V_198 ) ;
}
V_107:
F_33 ( & V_5 -> V_191 ) ;
F_107 ( V_5 -> V_53 , V_505 . V_156 ,
V_505 . V_116 , V_505 . V_118 ) ;
return V_29 ;
}
int F_141 ( struct V_4 * V_5 , T_3 * V_520 ,
T_3 V_504 , T_1 V_199 )
{
struct V_1 * V_2 ;
struct V_521 * V_173 ;
int V_29 ;
struct V_112 V_407 ;
memset ( & V_407 , 0 , sizeof( struct V_112 ) ) ;
V_407 . V_156 = sizeof( struct V_521 ) ;
V_407 . V_116 = F_142 ( & V_5 -> V_53 -> V_54 , V_407 . V_156 ,
& V_407 . V_118 , V_522 ) ;
if ( ! V_407 . V_116 ) {
F_16 ( & V_5 -> V_53 -> V_54 , L_16 ) ;
return - V_317 ;
}
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_407 . V_116 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_523 , sizeof( * V_173 ) ,
V_2 , & V_407 ) ;
V_173 -> V_176 . V_199 = V_199 ;
V_173 -> V_504 = V_504 ;
if ( V_504 )
memcpy ( V_173 -> V_197 , V_520 , V_198 * V_504 ) ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_143 ( & V_5 -> V_53 -> V_54 , V_407 . V_156 ,
V_407 . V_116 , V_407 . V_118 ) ;
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_144 ( struct V_4 * V_5 , T_2 V_78 ,
T_1 V_199 , T_2 V_524 )
{
struct V_1 * V_2 ;
struct V_525 * V_173 ;
void * V_211 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
V_211 = & V_173 -> V_180 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_526 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_176 . V_199 = V_199 ;
F_80 ( struct V_527 , V_253 , V_211 , V_524 ) ;
if ( V_78 ) {
F_80 ( struct V_527 , V_528 , V_211 , 1 ) ;
F_80 ( struct V_527 , V_78 , V_211 , V_78 ) ;
}
F_63 ( V_173 -> V_180 , sizeof( V_173 -> V_180 ) ) ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_145 ( struct V_4 * V_5 , T_2 * V_78 ,
T_1 V_199 , T_2 V_524 )
{
struct V_1 * V_2 ;
struct V_529 * V_173 ;
void * V_211 ;
int V_29 ;
T_2 V_530 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
V_211 = & V_173 -> V_180 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_531 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_176 . V_199 = V_199 ;
F_80 ( struct V_532 , V_253 , V_211 ,
V_524 ) ;
F_80 ( struct V_532 , V_528 , V_211 , 1 ) ;
F_63 ( V_173 -> V_180 , sizeof( V_173 -> V_180 ) ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_533 * V_44 =
F_1 ( V_2 ) ;
F_12 ( & V_44 -> V_180 ,
sizeof( V_44 -> V_180 ) ) ;
V_530 = F_146 ( struct V_534 ,
V_78 , & V_44 -> V_180 ) ;
* V_78 = F_22 ( V_530 ) ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_147 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_535 * V_173 ;
int V_29 ;
int V_316 = sizeof( * V_173 ) ;
struct V_112 V_407 ;
memset ( & V_407 , 0 , sizeof( struct V_112 ) ) ;
V_407 . V_156 = sizeof( struct V_536 ) ;
V_407 . V_116 = F_106 ( V_5 -> V_53 , V_407 . V_156 ,
& V_407 . V_118 ) ;
if ( ! V_407 . V_116 ) {
F_16 ( & V_5 -> V_53 -> V_54 ,
L_17 ) ;
return - V_317 ;
}
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_407 . V_116 ;
F_61 ( & V_173 -> V_176 , V_40 ,
V_445 ,
V_316 , V_2 , & V_407 ) ;
V_173 -> V_176 . V_149 = 1 ;
V_173 -> V_537 = V_538 ;
V_29 = F_52 ( V_5 ) ;
if ( ! V_29 ) {
struct V_536 * V_44 ;
V_44 = (struct V_536 * ) V_407 . V_116 ;
if ( V_44 -> V_176 . V_539 < V_316 ) {
V_29 = - 1 ;
goto V_130;
}
V_5 -> V_540 = V_44 -> V_541 ;
}
V_130:
F_76 ( & V_5 -> V_169 ) ;
F_107 ( V_5 -> V_53 , V_407 . V_156 , V_407 . V_116 , V_407 . V_118 ) ;
return V_29 ;
}
int F_148 ( struct V_4 * V_5 ,
struct V_112 * V_407 )
{
struct V_1 * V_2 ;
struct V_542 * V_173 ;
int V_29 ;
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_407 -> V_116 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_543 ,
V_407 -> V_156 , V_2 , V_407 ) ;
V_173 -> V_544 = F_62 ( 1 ) ;
V_29 = F_52 ( V_5 ) ;
V_130:
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
int F_149 ( struct V_4 * V_5 ,
struct V_112 * V_407 ,
struct V_545 * V_546 )
{
struct V_1 * V_2 ;
struct V_547 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_407 -> V_116 ;
memcpy ( & V_173 -> V_548 , V_546 , sizeof( struct V_545 ) ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_549 ,
V_407 -> V_156 , V_2 , V_407 ) ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_150 ( struct V_4 * V_5 , T_3 * V_550 )
{
struct V_1 * V_2 ;
struct V_551 * V_173 ;
int V_29 ;
if ( ! F_18 ( V_5 ) ) {
* V_550 = V_5 -> V_288 + '0' ;
return 0 ;
}
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_552 , sizeof( * V_173 ) , V_2 ,
NULL ) ;
V_173 -> V_176 . V_149 = 1 ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_553 * V_44 = F_1 ( V_2 ) ;
* V_550 = V_44 -> V_550 [ V_5 -> V_288 ] ;
} else {
* V_550 = V_5 -> V_288 + '0' ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_151 ( void * V_554 , void * V_555 ,
int V_556 , T_2 * V_557 , T_2 * V_558 )
{
struct V_4 * V_5 = F_152 ( V_554 ) ;
struct V_1 * V_2 ;
struct V_142 * V_176 = (struct V_142 * ) V_555 ;
struct V_142 * V_173 ;
struct V_20 * V_44 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
V_44 = F_1 ( V_2 ) ;
F_61 ( V_173 , V_176 -> V_28 ,
V_176 -> V_27 , V_556 , V_2 , NULL ) ;
memcpy ( V_173 , V_555 , V_556 ) ;
F_63 ( V_173 , V_556 ) ;
V_29 = F_45 ( V_5 ) ;
if ( V_557 )
* V_557 = ( V_29 & 0xffff ) ;
if ( V_558 )
* V_558 = 0 ;
memcpy ( V_555 , V_44 , sizeof( * V_44 ) + V_44 -> V_539 ) ;
F_12 ( V_555 , sizeof( * V_44 ) + V_44 -> V_539 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
