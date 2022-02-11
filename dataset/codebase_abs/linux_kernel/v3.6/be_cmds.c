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
if ( V_58 -> V_73 == V_5 -> V_74 ) {
V_5 -> V_59 . V_60 = V_58 -> V_75 * 10 ;
}
}
static void F_22 ( struct V_4 * V_5 ,
struct V_76 * V_58 )
{
if ( V_58 -> V_77 )
V_5 -> V_78 = F_23 ( V_58 -> V_79 ) & V_80 ;
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
F_22 ( V_5 ,
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
V_170 -> V_11 = F_23 ( V_44 -> V_184 ) ;
V_170 -> V_185 = true ;
}
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
int F_83 ( struct V_4 * V_5 , T_3 * V_186 ,
T_3 type , bool V_187 , T_1 V_188 , T_1 V_189 )
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
V_173 -> type = type ;
if ( V_187 ) {
V_173 -> V_187 = 1 ;
} else {
V_173 -> V_194 = F_79 ( ( T_2 ) V_188 ) ;
V_173 -> V_189 = F_62 ( V_189 ) ;
V_173 -> V_187 = 0 ;
}
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_195 * V_44 = F_1 ( V_2 ) ;
memcpy ( V_186 , V_44 -> V_196 . V_23 , V_197 ) ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_84 ( struct V_4 * V_5 , T_3 * V_186 ,
T_1 V_194 , T_1 * V_189 , T_1 V_198 )
{
struct V_1 * V_2 ;
struct V_199 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_200 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_176 . V_198 = V_198 ;
V_173 -> V_194 = F_62 ( V_194 ) ;
memcpy ( V_173 -> V_201 , V_186 , V_197 ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_202 * V_44 = F_1 ( V_2 ) ;
* V_189 = F_7 ( V_44 -> V_189 ) ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
if ( V_29 == V_52 )
V_29 = - V_203 ;
return V_29 ;
}
int F_85 ( struct V_4 * V_5 , T_1 V_194 , int V_189 , T_1 V_204 )
{
struct V_1 * V_2 ;
struct V_205 * V_173 ;
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
V_206 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_176 . V_198 = V_204 ;
V_173 -> V_194 = F_62 ( V_194 ) ;
V_173 -> V_189 = F_62 ( V_189 ) ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_86 ( struct V_4 * V_5 , struct V_6 * V_93 ,
struct V_6 * V_170 , bool V_207 , int V_208 )
{
struct V_1 * V_2 ;
struct V_209 * V_173 ;
struct V_112 * V_174 = & V_93 -> V_175 ;
void * V_210 ;
int V_29 ;
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
V_173 = F_1 ( V_2 ) ;
V_210 = & V_173 -> V_180 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_211 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_178 = F_79 ( F_66 ( V_174 -> V_116 , V_174 -> V_156 ) ) ;
if ( F_18 ( V_5 ) ) {
V_173 -> V_176 . V_149 = 2 ;
V_173 -> V_212 = 1 ;
F_80 ( struct V_213 , V_214 , V_210 ,
V_207 ) ;
F_80 ( struct V_213 , V_181 , V_210 ,
F_81 ( V_93 -> V_106 / 256 ) ) ;
F_80 ( struct V_213 , V_65 , V_210 , 1 ) ;
F_80 ( struct V_213 , V_215 ,
V_210 , 1 ) ;
F_80 ( struct V_213 , V_216 ,
V_210 , V_170 -> V_11 ) ;
} else {
F_80 ( struct V_217 , V_218 , V_210 ,
V_208 ) ;
F_80 ( struct V_217 , V_214 ,
V_210 , V_207 ) ;
F_80 ( struct V_217 , V_181 , V_210 ,
F_81 ( V_93 -> V_106 / 256 ) ) ;
F_80 ( struct V_217 , V_65 , V_210 , 1 ) ;
F_80 ( struct V_217 , V_215 , V_210 , 1 ) ;
F_80 ( struct V_217 , V_216 , V_210 , V_170 -> V_11 ) ;
}
F_63 ( V_210 , sizeof( V_173 -> V_180 ) ) ;
F_64 ( V_173 -> V_159 , F_82 ( V_173 -> V_159 ) , V_174 ) ;
V_29 = F_52 ( V_5 ) ;
if ( ! V_29 ) {
struct V_219 * V_44 = F_1 ( V_2 ) ;
V_93 -> V_11 = F_23 ( V_44 -> V_220 ) ;
V_93 -> V_185 = true ;
}
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
static T_1 F_87 ( int V_221 )
{
T_1 V_222 = F_88 ( V_221 ) ;
if ( V_222 == 16 )
V_222 = 0 ;
return V_222 ;
}
int F_89 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_6 * V_93 )
{
struct V_1 * V_2 ;
struct V_223 * V_173 ;
struct V_112 * V_174 = & V_7 -> V_175 ;
void * V_210 ;
int V_29 ;
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
V_173 = F_1 ( V_2 ) ;
V_210 = & V_173 -> V_180 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_224 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_178 = F_79 ( F_66 ( V_174 -> V_116 , V_174 -> V_156 ) ) ;
if ( F_18 ( V_5 ) ) {
V_173 -> V_176 . V_149 = 1 ;
V_173 -> V_220 = F_79 ( V_93 -> V_11 ) ;
F_80 ( struct V_225 , V_226 , V_210 ,
F_87 ( V_7 -> V_106 ) ) ;
F_80 ( struct V_225 , V_65 , V_210 , 1 ) ;
F_80 ( struct V_225 , V_227 ,
V_210 , V_93 -> V_11 ) ;
F_80 ( struct V_225 , V_228 ,
V_210 , 1 ) ;
} else {
F_80 ( struct V_229 , V_65 , V_210 , 1 ) ;
F_80 ( struct V_229 , V_226 , V_210 ,
F_87 ( V_7 -> V_106 ) ) ;
F_80 ( struct V_229 , V_220 , V_210 , V_93 -> V_11 ) ;
}
V_173 -> V_230 [ 0 ] = F_62 ( 0x00000022 ) ;
F_63 ( V_210 , sizeof( V_173 -> V_180 ) ) ;
F_64 ( V_173 -> V_159 , F_82 ( V_173 -> V_159 ) , V_174 ) ;
V_29 = F_52 ( V_5 ) ;
if ( ! V_29 ) {
struct V_231 * V_44 = F_1 ( V_2 ) ;
V_7 -> V_11 = F_23 ( V_44 -> V_11 ) ;
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
struct V_232 * V_173 ;
struct V_112 * V_174 = & V_7 -> V_175 ;
void * V_210 ;
int V_29 ;
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
V_173 = F_1 ( V_2 ) ;
V_210 = & V_173 -> V_180 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_233 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_178 = F_79 ( F_66 ( V_174 -> V_116 , V_174 -> V_156 ) ) ;
F_80 ( struct V_229 , V_65 , V_210 , 1 ) ;
F_80 ( struct V_229 , V_226 , V_210 ,
F_87 ( V_7 -> V_106 ) ) ;
F_80 ( struct V_229 , V_220 , V_210 , V_93 -> V_11 ) ;
F_63 ( V_210 , sizeof( V_173 -> V_180 ) ) ;
F_64 ( V_173 -> V_159 , F_82 ( V_173 -> V_159 ) , V_174 ) ;
V_29 = F_52 ( V_5 ) ;
if ( ! V_29 ) {
struct V_231 * V_44 = F_1 ( V_2 ) ;
V_7 -> V_11 = F_23 ( V_44 -> V_11 ) ;
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
struct V_6 * V_234 ,
struct V_6 * V_93 )
{
struct V_1 * V_2 ;
struct V_235 * V_173 ;
struct V_112 * V_174 = & V_234 -> V_175 ;
void * V_210 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
V_210 = & V_173 -> V_180 ;
F_61 ( & V_173 -> V_176 , V_40 ,
V_236 , sizeof( * V_173 ) , V_2 , NULL ) ;
if ( F_18 ( V_5 ) ) {
V_173 -> V_176 . V_149 = 1 ;
F_80 ( struct V_237 , V_194 , V_210 ,
V_5 -> V_188 ) ;
}
V_173 -> V_178 = F_66 ( V_174 -> V_116 , V_174 -> V_156 ) ;
V_173 -> V_238 = V_239 ;
V_173 -> type = V_240 ;
F_80 ( struct V_237 , V_241 , V_210 ,
F_87 ( V_234 -> V_106 ) ) ;
F_80 ( struct V_237 , V_242 , V_210 , 1 ) ;
F_80 ( struct V_237 , V_243 , V_210 , V_93 -> V_11 ) ;
F_63 ( V_210 , sizeof( V_173 -> V_180 ) ) ;
F_64 ( V_173 -> V_159 , F_82 ( V_173 -> V_159 ) , V_174 ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_244 * V_44 = F_1 ( V_2 ) ;
V_234 -> V_11 = F_23 ( V_44 -> V_245 ) ;
V_234 -> V_185 = true ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_93 ( struct V_4 * V_5 ,
struct V_6 * V_246 , T_2 V_220 , T_2 V_247 ,
T_1 V_194 , T_1 V_248 , T_3 * V_249 )
{
struct V_1 * V_2 ;
struct V_250 * V_173 ;
struct V_112 * V_174 = & V_246 -> V_175 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_40 ,
V_251 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_220 = F_79 ( V_220 ) ;
V_173 -> V_247 = F_88 ( V_247 ) - 1 ;
V_173 -> V_178 = 2 ;
F_64 ( V_173 -> V_159 , F_82 ( V_173 -> V_159 ) , V_174 ) ;
V_173 -> V_252 = F_62 ( V_194 ) ;
V_173 -> V_253 = F_79 ( V_254 ) ;
V_173 -> V_255 = F_62 ( V_248 ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_256 * V_44 = F_1 ( V_2 ) ;
V_246 -> V_11 = F_23 ( V_44 -> V_11 ) ;
V_246 -> V_185 = true ;
* V_249 = V_44 -> V_249 ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_94 ( struct V_4 * V_5 , struct V_6 * V_9 ,
int V_257 )
{
struct V_1 * V_2 ;
struct V_258 * V_173 ;
T_3 V_259 = 0 , V_27 = 0 ;
int V_29 ;
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
V_173 = F_1 ( V_2 ) ;
switch ( V_257 ) {
case V_260 :
V_259 = V_34 ;
V_27 = V_261 ;
break;
case V_262 :
V_259 = V_34 ;
V_27 = V_263 ;
break;
case V_264 :
V_259 = V_40 ;
V_27 = V_265 ;
break;
case V_266 :
V_259 = V_40 ;
V_27 = V_267 ;
break;
case V_268 :
V_259 = V_34 ;
V_27 = V_269 ;
break;
default:
F_95 () ;
}
F_61 ( & V_173 -> V_176 , V_259 , V_27 , sizeof( * V_173 ) , V_2 ,
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
struct V_258 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_40 ,
V_267 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_11 = F_79 ( V_9 -> V_11 ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 )
V_9 -> V_185 = false ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_97 ( struct V_4 * V_5 , T_1 V_270 , T_1 V_271 ,
T_1 * V_188 , T_1 V_198 )
{
struct V_1 * V_2 ;
struct V_272 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_273 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_176 . V_198 = V_198 ;
V_173 -> V_274 = F_62 ( V_270 ) ;
V_173 -> V_275 = F_62 ( V_271 ) ;
V_173 -> V_276 = true ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_277 * V_44 = F_1 ( V_2 ) ;
* V_188 = F_7 ( V_44 -> V_252 ) ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_98 ( struct V_4 * V_5 , int V_252 , T_1 V_198 )
{
struct V_1 * V_2 ;
struct V_278 * V_173 ;
int V_29 ;
if ( V_252 == - 1 )
return 0 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_279 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_176 . V_198 = V_198 ;
V_173 -> V_252 = F_62 ( V_252 ) ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_99 ( struct V_4 * V_5 , struct V_112 * V_280 )
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
V_176 = V_280 -> V_116 ;
F_61 ( V_176 , V_40 ,
V_38 , V_280 -> V_156 , V_2 , V_280 ) ;
if ( V_5 -> V_281 == V_282 )
V_176 -> V_149 = 1 ;
F_2 ( V_5 ) ;
V_5 -> V_41 = true ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_100 ( struct V_4 * V_5 ,
struct V_112 * V_280 )
{
struct V_1 * V_2 ;
struct V_283 * V_173 ;
int V_29 = 0 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_280 -> V_116 ;
F_61 ( & V_173 -> V_176 , V_40 ,
V_39 , V_280 -> V_156 , V_2 ,
V_280 ) ;
V_173 -> V_284 . V_285 . V_286 = F_79 ( V_5 -> V_287 ) ;
V_173 -> V_284 . V_285 . V_288 = 0 ;
F_2 ( V_5 ) ;
V_5 -> V_41 = true ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_101 ( struct V_4 * V_5 , T_3 * V_289 ,
T_2 * V_60 , T_3 * V_290 , T_1 V_204 )
{
struct V_1 * V_2 ;
struct V_291 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
if ( V_290 )
* V_290 = V_292 ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_293 , sizeof( * V_173 ) , V_2 , NULL ) ;
if ( V_5 -> V_281 == V_282 || F_18 ( V_5 ) )
V_173 -> V_176 . V_149 = 1 ;
V_173 -> V_176 . V_198 = V_204 ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_294 * V_44 = F_1 ( V_2 ) ;
if ( V_44 -> V_289 != V_295 ) {
if ( V_60 )
* V_60 = F_23 ( V_44 -> V_60 ) ;
if ( V_289 )
* V_289 = V_44 -> V_289 ;
}
if ( V_290 )
* V_290 = V_44 -> V_296 ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_102 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_297 * V_173 ;
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
int F_103 ( struct V_4 * V_5 , T_1 * V_298 )
{
struct V_1 * V_2 ;
struct V_299 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_300 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_301 = F_62 ( V_302 ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_303 * V_44 = F_1 ( V_2 ) ;
if ( V_298 && V_44 -> V_298 )
* V_298 = F_7 ( V_44 -> V_298 ) -
sizeof( T_1 ) ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
void F_104 ( struct V_4 * V_5 , T_1 V_304 , void * V_305 )
{
struct V_112 V_306 ;
struct V_1 * V_2 ;
struct V_299 * V_173 ;
T_1 V_307 = 0 , V_308 , V_309 ,
V_310 = sizeof( T_1 ) , V_311 ;
int V_29 ;
if ( V_304 == 0 )
return;
V_308 = V_304 ;
V_306 . V_156 = sizeof( struct V_299 ) + 60 * 1024 ;
V_306 . V_116 = F_105 ( V_5 -> V_53 ,
V_306 . V_156 ,
& V_306 . V_118 ) ;
if ( ! V_306 . V_116 ) {
V_29 = - V_312 ;
F_16 ( & V_5 -> V_53 -> V_54 ,
L_13 ) ;
return;
}
F_31 ( & V_5 -> V_191 ) ;
while ( V_308 ) {
V_309 = F_65 ( V_308 , ( T_1 ) 60 * 1024 ) ;
V_308 -= V_309 ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_306 . V_116 ;
V_311 = sizeof( struct V_299 ) + V_309 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_300 , V_311 , V_2 ,
& V_306 ) ;
V_173 -> V_301 = F_62 ( V_313 ) ;
V_173 -> V_314 = F_62 ( V_310 ) ;
V_173 -> V_315 = F_62 ( V_309 ) ;
V_173 -> V_316 = F_62 ( V_309 ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_303 * V_44 = V_306 . V_116 ;
memcpy ( V_305 + V_307 ,
V_44 -> V_317 ,
F_7 ( V_44 -> V_315 ) ) ;
} else {
F_16 ( & V_5 -> V_53 -> V_54 , L_14 ) ;
goto V_130;
}
V_307 += V_309 ;
V_310 += V_309 ;
}
V_130:
F_106 ( V_5 -> V_53 , V_306 . V_156 ,
V_306 . V_116 ,
V_306 . V_118 ) ;
F_33 ( & V_5 -> V_191 ) ;
}
int F_107 ( struct V_4 * V_5 , char * V_318 ,
char * V_319 )
{
struct V_1 * V_2 ;
struct V_320 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_321 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_322 * V_44 = F_1 ( V_2 ) ;
strcpy ( V_318 , V_44 -> V_323 ) ;
if ( V_319 )
strcpy ( V_319 , V_44 -> V_324 ) ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_108 ( struct V_4 * V_5 , T_1 V_184 , T_1 V_325 )
{
struct V_1 * V_2 ;
struct V_326 * V_173 ;
int V_29 = 0 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_327 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_328 = F_62 ( 1 ) ;
V_173 -> V_329 [ 0 ] . V_184 = F_62 ( V_184 ) ;
V_173 -> V_329 [ 0 ] . V_330 = 0 ;
V_173 -> V_329 [ 0 ] . V_331 = F_62 ( V_325 ) ;
F_2 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_109 ( struct V_4 * V_5 , T_1 V_194 , T_2 * V_332 ,
T_1 V_96 , bool V_333 , bool V_334 )
{
struct V_1 * V_2 ;
struct V_335 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_336 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_252 = V_194 ;
V_173 -> V_334 = V_334 ;
V_173 -> V_333 = V_333 ;
V_173 -> V_337 = V_96 ;
if ( ! V_334 ) {
memcpy ( V_173 -> V_338 , V_332 ,
V_173 -> V_337 * sizeof( V_332 [ 0 ] ) ) ;
}
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_110 ( struct V_4 * V_5 , T_1 V_18 , T_1 V_339 )
{
struct V_1 * V_2 ;
struct V_112 * V_145 = & V_5 -> V_340 ;
struct V_341 * V_173 = V_145 -> V_116 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
memset ( V_173 , 0 , sizeof( * V_173 ) ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_342 , sizeof( * V_173 ) ,
V_2 , V_145 ) ;
V_173 -> V_194 = F_62 ( V_5 -> V_188 ) ;
if ( V_18 & V_343 ) {
V_173 -> V_344 = F_62 ( V_345 |
V_346 ) ;
if ( V_339 == V_347 )
V_173 -> V_348 = F_62 ( V_345 |
V_346 ) ;
} else if ( V_18 & V_349 ) {
V_173 -> V_344 = V_173 -> V_348 =
F_62 ( V_350 ) ;
} else {
struct V_351 * V_352 ;
int V_101 = 0 ;
V_173 -> V_344 = V_173 -> V_348 =
F_62 ( V_353 ) ;
if ( ! F_18 ( V_5 ) || F_111 ( V_5 ) )
V_173 -> V_344 |=
F_62 ( V_350 ) ;
V_173 -> V_354 = F_62 ( F_112 ( V_5 -> V_355 ) ) ;
F_113 (ha, adapter->netdev)
memcpy ( V_173 -> V_356 [ V_101 ++ ] . V_357 , V_352 -> V_23 , V_197 ) ;
}
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_114 ( struct V_4 * V_5 , T_1 V_358 , T_1 V_359 )
{
struct V_1 * V_2 ;
struct V_360 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_361 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_362 = F_79 ( ( T_2 ) V_358 ) ;
V_173 -> V_363 = F_79 ( ( T_2 ) V_359 ) ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_115 ( struct V_4 * V_5 , T_1 * V_358 , T_1 * V_359 )
{
struct V_1 * V_2 ;
struct V_364 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_365 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_366 * V_44 =
F_1 ( V_2 ) ;
* V_358 = F_23 ( V_44 -> V_362 ) ;
* V_359 = F_23 ( V_44 -> V_363 ) ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_116 ( struct V_4 * V_5 , T_1 * V_74 ,
T_1 * V_367 , T_1 * V_368 )
{
struct V_1 * V_2 ;
struct V_369 * V_173 ;
int V_29 ;
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_370 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_29 = F_52 ( V_5 ) ;
if ( ! V_29 ) {
struct V_371 * V_44 = F_1 ( V_2 ) ;
* V_74 = F_7 ( V_44 -> V_372 ) ;
* V_367 = F_7 ( V_44 -> V_373 ) ;
* V_368 = F_7 ( V_44 -> V_374 ) ;
}
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
int F_117 ( struct V_4 * V_5 )
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
V_375 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_29 = F_52 ( V_5 ) ;
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
int F_118 ( struct V_4 * V_5 , T_3 * V_376 , T_2 V_377 )
{
struct V_1 * V_2 ;
struct V_378 * V_173 ;
T_1 V_379 [ 10 ] = { 0x15d43fa5 , 0x2534685a , 0x5f87693a , 0x5668494e ,
0x33cf6a53 , 0x383334c6 , 0x76ac4257 , 0x59b242b2 ,
0x3ea83c02 , 0x4a110304 } ;
int V_29 ;
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_40 ,
V_380 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_194 = F_62 ( V_5 -> V_188 ) ;
V_173 -> V_381 = F_79 ( V_382 | V_383 |
V_384 | V_385 ) ;
if ( F_18 ( V_5 ) || F_119 ( V_5 ) ) {
V_173 -> V_176 . V_149 = 1 ;
V_173 -> V_381 |= F_79 ( V_386 |
V_387 ) ;
}
V_173 -> V_388 = F_79 ( F_88 ( V_377 ) - 1 ) ;
memcpy ( V_173 -> V_389 , V_376 , V_377 ) ;
memcpy ( V_173 -> V_390 , V_379 , sizeof( V_379 ) ) ;
F_63 ( V_173 -> V_390 , sizeof( V_173 -> V_390 ) ) ;
V_29 = F_52 ( V_5 ) ;
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
int F_120 ( struct V_4 * V_5 , T_3 V_74 ,
T_3 V_391 , T_3 V_392 , T_3 V_393 )
{
struct V_1 * V_2 ;
struct V_394 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_395 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_74 = V_74 ;
V_173 -> V_396 = V_393 ;
V_173 -> V_397 = V_391 ;
V_173 -> V_398 = V_392 ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_121 ( struct V_4 * V_5 , T_3 V_74 , T_1 * V_393 )
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
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_401 * V_44 =
F_1 ( V_2 ) ;
* V_393 = V_44 -> V_396 ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_122 ( struct V_4 * V_5 , struct V_112 * V_402 ,
T_1 V_403 , T_1 V_404 ,
const char * V_405 , T_1 * V_406 ,
T_3 * V_407 , T_3 * V_408 )
{
struct V_1 * V_2 ;
struct V_409 * V_173 ;
struct V_410 * V_44 ;
void * V_210 = NULL ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_5 -> V_35 = 0 ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_411;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_33 ,
sizeof( struct V_409 ) , V_2 ,
NULL ) ;
V_210 = & V_173 -> V_180 ;
F_80 ( struct V_412 ,
V_413 , V_210 , V_403 ) ;
if ( V_403 == 0 )
F_80 ( struct V_412 ,
V_414 , V_210 , 1 ) ;
else
F_80 ( struct V_412 ,
V_414 , V_210 , 0 ) ;
F_63 ( V_210 , sizeof( V_173 -> V_180 ) ) ;
V_173 -> V_415 = F_62 ( V_404 ) ;
strcpy ( V_173 -> V_416 , V_405 ) ;
V_173 -> V_417 = F_62 ( 1 ) ;
V_173 -> V_304 = F_62 ( V_403 ) ;
V_173 -> V_418 = F_62 ( ( V_402 -> V_118 +
sizeof( struct V_409 ) )
& 0xFFFFFFFF ) ;
V_173 -> V_419 = F_62 ( F_53 ( V_402 -> V_118 +
sizeof( struct V_409 ) ) ) ;
F_2 ( V_5 ) ;
F_33 ( & V_5 -> V_191 ) ;
if ( ! F_123 ( & V_5 -> V_36 ,
F_124 ( 30000 ) ) )
V_29 = - 1 ;
else
V_29 = V_5 -> V_35 ;
V_44 = F_1 ( V_2 ) ;
if ( ! V_29 ) {
* V_406 = F_7 ( V_44 -> V_420 ) ;
* V_407 = V_44 -> V_407 ;
} else {
* V_408 = V_44 -> V_421 ;
}
return V_29 ;
V_411:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_125 ( struct V_4 * V_5 , struct V_112 * V_402 ,
T_1 V_403 , T_1 V_404 , const char * V_405 ,
T_1 * V_422 , T_1 * V_414 , T_3 * V_408 )
{
struct V_1 * V_2 ;
struct V_423 * V_173 ;
struct V_424 * V_44 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_411;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_425 ,
sizeof( struct V_423 ) , V_2 ,
NULL ) ;
V_173 -> V_426 = F_62 ( V_403 ) ;
V_173 -> V_427 = F_62 ( V_404 ) ;
strcpy ( V_173 -> V_416 , V_405 ) ;
V_173 -> V_417 = F_62 ( 1 ) ;
V_173 -> V_304 = F_62 ( V_403 ) ;
V_173 -> V_418 = F_62 ( ( V_402 -> V_118 & 0xFFFFFFFF ) ) ;
V_173 -> V_419 = F_62 ( F_53 ( V_402 -> V_118 ) ) ;
V_29 = F_45 ( V_5 ) ;
V_44 = F_1 ( V_2 ) ;
if ( ! V_29 ) {
* V_422 = F_7 ( V_44 -> V_428 ) ;
* V_414 = F_7 ( V_44 -> V_414 ) ;
} else {
* V_408 = V_44 -> V_421 ;
}
V_411:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_126 ( struct V_4 * V_5 , struct V_112 * V_402 ,
T_1 V_429 , T_1 V_430 , T_1 V_309 )
{
struct V_1 * V_2 ;
struct F_126 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_5 -> V_35 = 0 ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_411;
}
V_173 = V_402 -> V_116 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_32 , V_402 -> V_156 , V_2 , V_402 ) ;
V_173 -> V_285 . V_431 = F_62 ( V_429 ) ;
V_173 -> V_285 . V_432 = F_62 ( V_430 ) ;
V_173 -> V_285 . V_433 = F_62 ( V_309 ) ;
F_2 ( V_5 ) ;
F_33 ( & V_5 -> V_191 ) ;
if ( ! F_123 ( & V_5 -> V_36 ,
F_124 ( 40000 ) ) )
V_29 = - 1 ;
else
V_29 = V_5 -> V_35 ;
return V_29 ;
V_411:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_127 ( struct V_4 * V_5 , T_3 * V_434 ,
int V_307 )
{
struct V_1 * V_2 ;
struct F_126 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_435 , sizeof( * V_173 ) + 4 , V_2 , NULL ) ;
V_173 -> V_285 . V_431 = F_62 ( V_436 ) ;
V_173 -> V_285 . V_432 = F_62 ( V_437 ) ;
V_173 -> V_285 . V_307 = F_62 ( V_307 ) ;
V_173 -> V_285 . V_433 = F_62 ( 0x4 ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 )
memcpy ( V_434 , V_173 -> V_285 . V_438 , 4 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_128 ( struct V_4 * V_5 , T_3 * V_196 ,
struct V_112 * V_280 )
{
struct V_1 * V_2 ;
struct V_439 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_280 -> V_116 ;
F_61 ( & V_173 -> V_176 , V_40 ,
V_440 , sizeof( * V_173 ) , V_2 ,
V_280 ) ;
memcpy ( V_173 -> V_441 , V_196 , V_197 ) ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_129 ( struct V_4 * V_5 , T_3 V_74 ,
T_3 V_442 , T_3 V_443 )
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
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_445 ,
V_446 , sizeof( * V_173 ) , V_2 ,
NULL ) ;
V_173 -> V_447 = V_74 ;
V_173 -> V_448 = V_74 ;
V_173 -> V_442 = V_442 ;
V_173 -> V_449 = V_443 ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_130 ( struct V_4 * V_5 , T_1 V_74 ,
T_1 V_442 , T_1 V_450 , T_1 V_451 , T_5 V_452 )
{
struct V_1 * V_2 ;
struct V_453 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_445 ,
V_454 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_176 . V_136 = F_62 ( 4 ) ;
V_173 -> V_452 = F_131 ( V_452 ) ;
V_173 -> V_447 = F_62 ( V_74 ) ;
V_173 -> V_448 = F_62 ( V_74 ) ;
V_173 -> V_450 = F_62 ( V_450 ) ;
V_173 -> V_451 = F_62 ( V_451 ) ;
V_173 -> V_442 = F_62 ( V_442 ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_455 * V_44 = F_1 ( V_2 ) ;
V_29 = F_7 ( V_44 -> V_29 ) ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_132 ( struct V_4 * V_5 , T_5 V_452 ,
T_1 V_456 , struct V_112 * V_402 )
{
struct V_1 * V_2 ;
struct V_457 * V_173 ;
int V_29 ;
int V_101 , V_458 = 0 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_402 -> V_116 ;
F_61 ( & V_173 -> V_176 , V_445 ,
V_459 , V_402 -> V_156 , V_2 , V_402 ) ;
V_173 -> V_452 = F_131 ( V_452 ) ;
V_173 -> V_460 = F_62 ( V_456 ) ;
for ( V_101 = 0 ; V_101 < V_456 ; V_101 ++ ) {
V_173 -> V_461 [ V_101 ] = ( T_3 ) ( V_452 >> ( V_458 * 8 ) ) ;
V_458 ++ ;
if ( V_458 > 7 )
V_458 = 0 ;
}
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_462 * V_44 ;
V_44 = V_402 -> V_116 ;
if ( ( memcmp ( V_44 -> V_463 , V_173 -> V_461 , V_456 ) != 0 ) ||
V_44 -> V_464 ) {
V_29 = - 1 ;
}
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_133 ( struct V_4 * V_5 ,
struct V_112 * V_280 )
{
struct V_1 * V_2 ;
struct V_465 * V_173 ;
struct V_140 * V_146 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_280 -> V_116 ;
V_146 = F_60 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_466 , sizeof( * V_173 ) , V_2 ,
V_280 ) ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_134 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_467 * V_173 ;
struct V_112 V_402 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_402 . V_156 = sizeof( struct V_467 ) ;
V_402 . V_116 = F_105 ( V_5 -> V_53 , V_402 . V_156 ,
& V_402 . V_118 ) ;
if ( ! V_402 . V_116 ) {
F_16 ( & V_5 -> V_53 -> V_54 , L_16 ) ;
V_29 = - V_312 ;
goto V_130;
}
V_173 = V_402 . V_116 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_468 , sizeof( * V_173 ) ,
V_2 , & V_402 ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_469 * V_470 =
V_402 . V_116 + sizeof( struct V_142 ) ;
V_5 -> V_59 . V_471 = F_23 ( V_470 -> V_471 ) ;
V_5 -> V_59 . V_472 =
F_23 ( V_470 -> V_472 ) ;
V_5 -> V_59 . V_473 =
F_23 ( V_470 -> V_473 ) ;
V_5 -> V_59 . V_474 =
F_23 ( V_470 -> V_474 ) ;
V_5 -> V_59 . V_475 =
F_7 ( V_470 -> V_475 ) ;
}
F_106 ( V_5 -> V_53 , V_402 . V_156 ,
V_402 . V_116 , V_402 . V_118 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_135 ( struct V_4 * V_5 , T_1 V_476 , T_1 V_198 )
{
struct V_1 * V_2 ;
struct V_477 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_478 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_176 . V_198 = V_198 ;
V_173 -> V_479 = F_62 ( V_480 ) ;
V_173 -> V_481 = F_62 ( V_476 ) ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_136 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_482 * V_173 ;
struct V_483 * V_44 ;
int V_29 ;
int V_311 = F_137 ( sizeof( * V_173 ) , sizeof( * V_44 ) ) ;
struct V_484 * V_485 ;
struct V_112 V_486 ;
memset ( & V_486 , 0 , sizeof( struct V_112 ) ) ;
V_486 . V_156 = sizeof( struct V_483 ) ;
V_486 . V_116 = F_105 ( V_5 -> V_53 , V_486 . V_156 ,
& V_486 . V_118 ) ;
if ( ! V_486 . V_116 ) {
F_16 ( & V_5 -> V_53 -> V_54 ,
L_17 ) ;
return - V_312 ;
}
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_486 . V_116 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_487 , V_311 , V_2 ,
& V_486 ) ;
V_29 = F_52 ( V_5 ) ;
if ( ! V_29 ) {
V_485 = V_486 . V_116 + sizeof( struct V_20 ) ;
V_5 -> V_287 = V_485 -> V_488 . V_489 ;
}
V_130:
F_76 ( & V_5 -> V_169 ) ;
F_106 ( V_5 -> V_53 , V_486 . V_156 , V_486 . V_116 ,
V_486 . V_118 ) ;
return V_29 ;
}
int F_138 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_490 * V_173 ;
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
V_491 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_492 = F_62 ( V_493 |
V_494 ) ;
V_173 -> V_270 = F_62 ( V_494 ) ;
V_29 = F_52 ( V_5 ) ;
if ( ! V_29 ) {
struct V_495 * V_44 = F_1 ( V_2 ) ;
V_5 -> V_496 = F_7 ( V_44 -> V_270 ) &
V_494 ;
}
V_130:
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
int F_139 ( struct V_4 * V_5 , T_3 * V_196 ,
bool * V_497 , T_1 * V_189 , T_3 V_198 )
{
struct V_1 * V_2 ;
struct V_498 * V_173 ;
int V_29 ;
int V_499 ;
struct V_112 V_500 ;
int V_101 ;
memset ( & V_500 , 0 , sizeof( struct V_112 ) ) ;
V_500 . V_156 = sizeof( struct V_501 ) ;
V_500 . V_116 = F_105 ( V_5 -> V_53 ,
V_500 . V_156 ,
& V_500 . V_118 ) ;
if ( ! V_500 . V_116 ) {
F_16 ( & V_5 -> V_53 -> V_54 ,
L_18 ) ;
return - V_312 ;
}
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_107;
}
V_173 = V_500 . V_116 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_502 , sizeof( * V_173 ) ,
V_2 , & V_500 ) ;
V_173 -> V_176 . V_198 = V_198 ;
V_173 -> V_503 = V_504 ;
V_173 -> V_505 = 1 ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_501 * V_44 =
V_500 . V_116 ;
V_499 = V_44 -> V_506 + V_44 -> V_507 ;
for ( V_101 = 0 ; V_101 < V_499 ; V_101 ++ ) {
struct V_508 * V_509 ;
T_2 V_510 ;
T_1 V_511 ;
V_509 = & V_44 -> V_512 [ V_101 ] ;
V_510 = F_23 ( V_509 -> V_510 ) ;
if ( V_510 == sizeof( T_1 ) ) {
* V_497 = true ;
V_511 = V_509 -> V_513 . V_514 . V_511 ;
* V_189 = F_7 ( V_511 ) ;
goto V_107;
}
}
* V_497 = false ;
memcpy ( V_196 , V_44 -> V_512 [ 0 ] . V_513 . V_515 ,
V_197 ) ;
}
V_107:
F_33 ( & V_5 -> V_191 ) ;
F_106 ( V_5 -> V_53 , V_500 . V_156 ,
V_500 . V_116 , V_500 . V_118 ) ;
return V_29 ;
}
int F_140 ( struct V_4 * V_5 , T_3 * V_516 ,
T_3 V_499 , T_1 V_198 )
{
struct V_1 * V_2 ;
struct V_517 * V_173 ;
int V_29 ;
struct V_112 V_402 ;
memset ( & V_402 , 0 , sizeof( struct V_112 ) ) ;
V_402 . V_156 = sizeof( struct V_517 ) ;
V_402 . V_116 = F_141 ( & V_5 -> V_53 -> V_54 , V_402 . V_156 ,
& V_402 . V_118 , V_518 ) ;
if ( ! V_402 . V_116 ) {
F_16 ( & V_5 -> V_53 -> V_54 , L_16 ) ;
return - V_312 ;
}
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_402 . V_116 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_519 , sizeof( * V_173 ) ,
V_2 , & V_402 ) ;
V_173 -> V_176 . V_198 = V_198 ;
V_173 -> V_499 = V_499 ;
if ( V_499 )
memcpy ( V_173 -> V_196 , V_516 , V_197 * V_499 ) ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_142 ( & V_5 -> V_53 -> V_54 , V_402 . V_156 ,
V_402 . V_116 , V_402 . V_118 ) ;
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_143 ( struct V_4 * V_5 , T_2 V_78 ,
T_1 V_198 , T_2 V_520 )
{
struct V_1 * V_2 ;
struct V_521 * V_173 ;
void * V_210 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
V_210 = & V_173 -> V_180 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_522 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_176 . V_198 = V_198 ;
F_80 ( struct V_523 , V_252 , V_210 , V_520 ) ;
if ( V_78 ) {
F_80 ( struct V_523 , V_524 , V_210 , 1 ) ;
F_80 ( struct V_523 , V_78 , V_210 , V_78 ) ;
}
F_63 ( V_173 -> V_180 , sizeof( V_173 -> V_180 ) ) ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_144 ( struct V_4 * V_5 , T_2 * V_78 ,
T_1 V_198 , T_2 V_520 )
{
struct V_1 * V_2 ;
struct V_525 * V_173 ;
void * V_210 ;
int V_29 ;
T_2 V_526 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = F_1 ( V_2 ) ;
V_210 = & V_173 -> V_180 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_527 , sizeof( * V_173 ) , V_2 , NULL ) ;
V_173 -> V_176 . V_198 = V_198 ;
F_80 ( struct V_528 , V_252 , V_210 ,
V_520 ) ;
F_80 ( struct V_528 , V_524 , V_210 , 1 ) ;
F_63 ( V_173 -> V_180 , sizeof( V_173 -> V_180 ) ) ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_529 * V_44 =
F_1 ( V_2 ) ;
F_12 ( & V_44 -> V_180 ,
sizeof( V_44 -> V_180 ) ) ;
V_526 = F_145 ( struct V_530 ,
V_78 , & V_44 -> V_180 ) ;
* V_78 = F_23 ( V_526 ) ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_146 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_531 * V_173 ;
int V_29 ;
int V_311 = sizeof( * V_173 ) ;
struct V_112 V_402 ;
memset ( & V_402 , 0 , sizeof( struct V_112 ) ) ;
V_402 . V_156 = sizeof( struct V_532 ) ;
V_402 . V_116 = F_105 ( V_5 -> V_53 , V_402 . V_156 ,
& V_402 . V_118 ) ;
if ( ! V_402 . V_116 ) {
F_16 ( & V_5 -> V_53 -> V_54 ,
L_17 ) ;
return - V_312 ;
}
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_402 . V_116 ;
F_61 ( & V_173 -> V_176 , V_40 ,
V_440 ,
V_311 , V_2 , & V_402 ) ;
V_173 -> V_176 . V_149 = 1 ;
V_173 -> V_533 = V_534 ;
V_29 = F_52 ( V_5 ) ;
if ( ! V_29 ) {
struct V_532 * V_44 ;
V_44 = (struct V_532 * ) V_402 . V_116 ;
if ( V_44 -> V_176 . V_535 < V_311 ) {
V_29 = - 1 ;
goto V_130;
}
V_5 -> V_536 = V_44 -> V_537 ;
}
V_130:
F_76 ( & V_5 -> V_169 ) ;
F_106 ( V_5 -> V_53 , V_402 . V_156 , V_402 . V_116 , V_402 . V_118 ) ;
return V_29 ;
}
int F_147 ( struct V_4 * V_5 ,
struct V_112 * V_402 )
{
struct V_1 * V_2 ;
struct V_538 * V_173 ;
int V_29 ;
if ( F_75 ( & V_5 -> V_169 ) )
return - 1 ;
V_2 = F_69 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_402 -> V_116 ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_539 ,
V_402 -> V_156 , V_2 , V_402 ) ;
V_173 -> V_540 = F_62 ( 1 ) ;
V_29 = F_52 ( V_5 ) ;
V_130:
F_76 ( & V_5 -> V_169 ) ;
return V_29 ;
}
int F_148 ( struct V_4 * V_5 ,
struct V_112 * V_402 ,
struct V_541 * V_542 )
{
struct V_1 * V_2 ;
struct V_543 * V_173 ;
int V_29 ;
F_31 ( & V_5 -> V_191 ) ;
V_2 = F_70 ( V_5 ) ;
if ( ! V_2 ) {
V_29 = - V_192 ;
goto V_130;
}
V_173 = V_402 -> V_116 ;
memcpy ( & V_173 -> V_544 , V_542 , sizeof( struct V_541 ) ) ;
F_61 ( & V_173 -> V_176 , V_34 ,
V_545 ,
V_402 -> V_156 , V_2 , V_402 ) ;
V_29 = F_45 ( V_5 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_149 ( struct V_4 * V_5 , T_3 * V_546 )
{
struct V_1 * V_2 ;
struct V_547 * V_173 ;
int V_29 ;
if ( ! F_18 ( V_5 ) ) {
* V_546 = V_5 -> V_287 + '0' ;
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
V_548 , sizeof( * V_173 ) , V_2 ,
NULL ) ;
V_173 -> V_176 . V_149 = 1 ;
V_29 = F_45 ( V_5 ) ;
if ( ! V_29 ) {
struct V_549 * V_44 = F_1 ( V_2 ) ;
* V_546 = V_44 -> V_546 [ V_5 -> V_287 ] ;
} else {
* V_546 = V_5 -> V_287 + '0' ;
}
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
int F_150 ( void * V_550 , void * V_551 ,
int V_552 , T_2 * V_553 , T_2 * V_554 )
{
struct V_4 * V_5 = F_151 ( V_550 ) ;
struct V_1 * V_2 ;
struct V_142 * V_176 = (struct V_142 * ) V_551 ;
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
V_176 -> V_27 , V_552 , V_2 , NULL ) ;
memcpy ( V_173 , V_551 , V_552 ) ;
F_63 ( V_173 , V_552 ) ;
V_29 = F_45 ( V_5 ) ;
if ( V_553 )
* V_553 = ( V_29 & 0xffff ) ;
if ( V_554 )
* V_554 = 0 ;
memcpy ( V_551 , V_44 , sizeof( * V_44 ) + V_44 -> V_535 ) ;
F_12 ( V_551 , sizeof( * V_44 ) + V_44 -> V_535 ) ;
V_130:
F_33 ( & V_5 -> V_191 ) ;
return V_29 ;
}
