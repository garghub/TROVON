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
if ( V_3 == V_38 &&
V_4 == V_39 ) {
F_13 ( & V_2 -> V_40 ) ;
return 0 ;
}
if ( ( ( V_3 == V_41 ) ||
( V_3 == V_42 ) ) &&
( V_4 == V_43 ) ) {
V_2 -> V_44 = V_32 ;
F_13 ( & V_2 -> V_40 ) ;
}
if ( V_32 == V_45 ) {
if ( ( ( V_3 == V_46 ) ||
( V_3 == V_47 ) ) &&
( V_4 == V_48 ) ) {
F_14 ( V_2 ) ;
V_2 -> V_49 = false ;
}
if ( V_3 == V_50 &&
V_4 == V_43 ) {
struct V_51 * V_52 =
( void * ) V_34 ;
V_2 -> V_53 . V_54 =
V_52 -> V_55 ;
}
} else {
if ( V_3 == V_50 )
V_2 -> V_56 = 0 ;
if ( V_32 == V_57 ||
V_32 == V_58 )
goto V_59;
if ( V_32 == V_60 ) {
F_15 ( & V_2 -> V_61 -> V_62 ,
L_1 ,
V_3 , V_4 ) ;
} else {
V_33 = ( V_25 -> V_35 >> V_63 ) &
V_64 ;
F_16 ( & V_2 -> V_61 -> V_62 ,
L_2 ,
V_3 , V_4 , V_32 , V_33 ) ;
if ( V_33 == V_65 )
return V_33 ;
}
}
V_59:
return V_32 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
V_2 -> V_68 . V_69 = - 1 ;
if ( F_18 ( V_2 ) &&
! ( V_67 -> V_70 & V_71 ) )
return;
if ( V_2 -> V_26 & V_72 )
F_19 ( V_2 , V_67 -> V_70 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_73 * V_67 )
{
if ( V_67 -> V_74 ) {
V_2 -> V_75 = V_67 -> V_76 ;
V_2 -> V_77 &= ~ V_78 ;
V_2 -> V_77 =
V_67 -> V_79 << V_80 ;
}
}
static void F_21 ( struct V_1 * V_2 ,
struct V_81 * V_67 )
{
if ( V_2 -> V_68 . V_69 >= 0 &&
V_67 -> V_82 == V_2 -> V_83 )
V_2 -> V_68 . V_69 = F_22 ( V_67 -> V_84 ) * 10 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_85 * V_67 )
{
if ( V_67 -> V_86 )
V_2 -> V_87 = F_22 ( V_67 -> V_88 ) & V_89 ;
else
V_2 -> V_87 = 0 ;
}
static void F_24 ( struct V_1 * V_2 ,
T_2 V_90 , struct V_24 * V_67 )
{
T_1 V_91 = 0 ;
V_91 = ( V_90 >> V_92 ) &
V_93 ;
switch ( V_91 ) {
case V_94 :
F_20 ( V_2 ,
(struct V_73 * ) V_67 ) ;
break;
case V_95 :
F_21 ( V_2 ,
(struct V_81 * ) V_67 ) ;
break;
case V_96 :
F_23 ( V_2 ,
(struct V_85 * ) V_67 ) ;
break;
default:
F_15 ( & V_2 -> V_61 -> V_62 , L_3 ,
V_91 ) ;
break;
}
}
static void F_25 ( struct V_1 * V_2 ,
T_2 V_90 , struct V_24 * V_97 )
{
T_1 V_91 = 0 ;
struct V_98 * V_67 = (struct V_98 * ) V_97 ;
V_91 = ( V_90 >> V_92 ) &
V_93 ;
switch ( V_91 ) {
case V_99 :
if ( V_67 -> V_74 )
V_2 -> V_100 = F_22 ( V_67 -> V_101 ) ;
V_2 -> V_26 |= V_102 ;
break;
default:
F_15 ( & V_2 -> V_61 -> V_62 , L_4 ,
V_91 ) ;
break;
}
}
static inline bool F_26 ( T_2 V_90 )
{
return ( ( V_90 >> V_103 ) &
V_104 ) ==
V_105 ;
}
static inline bool F_27 ( T_2 V_90 )
{
return ( ( ( V_90 >> V_103 ) &
V_104 ) ==
V_106 ) ;
}
static inline bool F_28 ( T_2 V_90 )
{
return ( ( ( V_90 >> V_103 ) &
V_104 ) ==
V_107 ) ;
}
static struct V_24 * F_29 ( struct V_1 * V_2 )
{
struct V_14 * V_108 = & V_2 -> V_16 . V_109 ;
struct V_24 * V_25 = F_30 ( V_108 ) ;
if ( F_7 ( V_25 ) ) {
F_31 ( V_108 ) ;
return V_25 ;
}
return NULL ;
}
void F_32 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_110 ) ;
F_34 ( V_2 , V_2 -> V_16 . V_109 . V_19 , true , 0 ) ;
V_2 -> V_16 . V_111 = true ;
F_35 ( & V_2 -> V_110 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_110 ) ;
V_2 -> V_16 . V_111 = false ;
F_34 ( V_2 , V_2 -> V_16 . V_109 . V_19 , false , 0 ) ;
F_35 ( & V_2 -> V_110 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
int V_112 = 0 , V_35 = 0 ;
struct V_113 * V_16 = & V_2 -> V_16 ;
F_38 ( & V_2 -> V_110 ) ;
while ( ( V_25 = F_29 ( V_2 ) ) ) {
if ( V_25 -> V_26 & V_114 ) {
if ( F_26 ( V_25 -> V_26 ) )
F_17 ( V_2 ,
(struct V_66 * ) V_25 ) ;
else if ( F_27 ( V_25 -> V_26 ) )
F_24 ( V_2 ,
V_25 -> V_26 , V_25 ) ;
else if ( F_28 ( V_25 -> V_26 ) )
F_25 ( V_2 ,
V_25 -> V_26 , V_25 ) ;
} else if ( V_25 -> V_26 & V_115 ) {
V_35 = F_11 ( V_2 , V_25 ) ;
F_39 ( & V_16 -> V_17 . V_116 ) ;
}
F_9 ( V_25 ) ;
V_112 ++ ;
}
if ( V_112 )
F_34 ( V_2 , V_16 -> V_109 . V_19 , V_16 -> V_111 , V_112 ) ;
F_40 ( & V_2 -> V_110 ) ;
return V_35 ;
}
static int F_41 ( struct V_1 * V_2 )
{
#define F_42 120000
int V_5 , V_35 = 0 ;
struct V_113 * V_16 = & V_2 -> V_16 ;
for ( V_5 = 0 ; V_5 < F_42 ; V_5 ++ ) {
if ( F_4 ( V_2 ) )
return - V_117 ;
F_43 () ;
V_35 = F_37 ( V_2 ) ;
F_44 () ;
if ( F_45 ( & V_16 -> V_17 . V_116 ) == 0 )
break;
F_46 ( 100 ) ;
}
if ( V_5 == F_42 ) {
F_16 ( & V_2 -> V_61 -> V_62 , L_5 ) ;
V_2 -> V_118 = true ;
return - V_117 ;
}
return V_35 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_35 ;
struct V_11 * V_12 ;
struct V_113 * V_16 = & V_2 -> V_16 ;
T_3 V_119 = V_16 -> V_17 . V_120 ;
struct V_28 * V_52 ;
F_48 ( & V_119 , V_16 -> V_17 . V_121 ) ;
V_12 = F_49 ( & V_16 -> V_17 , V_119 ) ;
V_52 = F_10 ( V_12 -> V_29 , V_12 -> V_30 ) ;
F_3 ( V_2 ) ;
V_35 = F_41 ( V_2 ) ;
if ( V_35 == - V_117 )
goto V_122;
V_35 = V_52 -> V_35 ;
V_122:
return V_35 ;
}
static int F_50 ( struct V_1 * V_2 , void T_4 * V_22 )
{
int V_123 = 0 ;
T_2 V_124 ;
do {
if ( F_4 ( V_2 ) )
return - V_117 ;
V_124 = F_51 ( V_22 ) ;
if ( V_124 == 0xffffffff )
return - 1 ;
V_124 &= V_125 ;
if ( V_124 )
break;
if ( V_123 > 4000 ) {
F_16 ( & V_2 -> V_61 -> V_62 , L_5 ) ;
V_2 -> V_118 = true ;
F_52 ( V_2 ) ;
return - 1 ;
}
F_53 ( 1 ) ;
V_123 ++ ;
} while ( true );
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_35 ;
T_2 V_18 = 0 ;
void T_4 * V_22 = V_2 -> V_22 + V_126 ;
struct V_127 * V_128 = & V_2 -> V_128 ;
struct V_129 * V_130 = V_128 -> V_131 ;
struct V_24 * V_25 = & V_130 -> V_25 ;
V_35 = F_50 ( V_2 , V_22 ) ;
if ( V_35 != 0 )
return V_35 ;
V_18 |= V_132 ;
V_18 |= ( F_55 ( V_128 -> V_133 ) >> 2 ) << 2 ;
F_6 ( V_18 , V_22 ) ;
V_35 = F_50 ( V_2 , V_22 ) ;
if ( V_35 != 0 )
return V_35 ;
V_18 = 0 ;
V_18 |= ( T_2 ) ( V_128 -> V_133 >> 4 ) << 2 ;
F_6 ( V_18 , V_22 ) ;
V_35 = F_50 ( V_2 , V_22 ) ;
if ( V_35 != 0 )
return V_35 ;
if ( F_7 ( V_25 ) ) {
V_35 = F_11 ( V_2 , & V_130 -> V_25 ) ;
F_9 ( V_25 ) ;
if ( V_35 )
return V_35 ;
} else {
F_16 ( & V_2 -> V_61 -> V_62 , L_6 ) ;
return - 1 ;
}
return 0 ;
}
static T_3 F_56 ( struct V_1 * V_2 )
{
T_2 V_134 ;
if ( F_57 ( V_2 ) )
V_134 = F_51 ( V_2 -> V_135 + V_136 ) ;
else
F_58 ( V_2 -> V_61 ,
V_137 , & V_134 ) ;
return V_134 & V_138 ;
}
static int F_59 ( struct V_1 * V_2 )
{
#define F_60 30
T_2 V_139 ;
int V_35 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < F_60 ; V_5 ++ ) {
V_139 = F_51 ( V_2 -> V_22 + V_140 ) ;
if ( V_139 & V_141 )
break;
F_53 ( 1000 ) ;
}
if ( V_5 == F_60 )
V_35 = - 1 ;
return V_35 ;
}
static bool F_61 ( struct V_1 * V_2 )
{
T_2 V_139 = 0 , V_142 = 0 , V_143 = 0 ;
V_139 = F_51 ( V_2 -> V_22 + V_140 ) ;
if ( V_139 & V_144 ) {
V_142 = F_51 ( V_2 -> V_22 +
V_145 ) ;
V_143 = F_51 ( V_2 -> V_22 +
V_146 ) ;
if ( V_142 == V_147 &&
V_143 == V_148 )
return true ;
}
return false ;
}
int F_62 ( struct V_1 * V_2 )
{
int V_35 ;
T_2 V_139 , V_149 , V_150 ;
bool V_151 ;
V_151 = F_61 ( V_2 ) ;
if ( V_151 )
return - V_152 ;
V_35 = F_59 ( V_2 ) ;
if ( ! V_35 ) {
V_139 = F_51 ( V_2 -> V_22 + V_140 ) ;
V_149 = V_139 & V_144 ;
V_150 = V_139 & V_153 ;
if ( V_149 && V_150 ) {
F_6 ( V_154 ,
V_2 -> V_22 + V_155 ) ;
V_35 = F_59 ( V_2 ) ;
V_139 = F_51 ( V_2 -> V_22 +
V_140 ) ;
V_139 &= ( V_144 |
V_153 ) ;
if ( V_35 || V_139 )
V_35 = - 1 ;
} else if ( V_149 || V_150 ) {
V_35 = - 1 ;
}
}
V_151 = F_61 ( V_2 ) ;
if ( V_151 )
V_35 = - V_152 ;
return V_35 ;
}
int F_63 ( struct V_1 * V_2 )
{
T_3 V_156 ;
int V_35 , V_157 = 0 ;
struct V_158 * V_62 = & V_2 -> V_61 -> V_62 ;
if ( F_18 ( V_2 ) ) {
V_35 = F_59 ( V_2 ) ;
return V_35 ;
}
do {
V_156 = F_56 ( V_2 ) ;
if ( V_156 == V_159 )
return 0 ;
F_64 ( V_62 , L_7 ,
V_157 ) ;
if ( F_65 ( 2000 ) ) {
F_16 ( V_62 , L_8 ) ;
return - V_160 ;
}
V_157 += 2 ;
} while ( V_157 < 60 );
F_16 ( V_62 , L_9 , V_156 ) ;
return - 1 ;
}
static inline struct V_161 * F_66 ( struct V_11 * V_12 )
{
return & V_12 -> V_13 . V_162 [ 0 ] ;
}
static inline void F_67 ( struct V_11 * V_12 ,
unsigned long V_31 )
{
V_12 -> V_29 = V_31 & 0xFFFFFFFF ;
V_12 -> V_30 = F_55 ( V_31 ) ;
}
static void F_68 ( struct V_163 * V_164 ,
T_1 V_4 , T_1 V_3 , int V_165 ,
struct V_11 * V_12 , struct V_127 * V_166 )
{
struct V_161 * V_167 ;
V_164 -> V_3 = V_3 ;
V_164 -> V_4 = V_4 ;
V_164 -> V_168 = F_69 ( V_165 - sizeof( * V_164 ) ) ;
V_164 -> V_169 = 0 ;
F_67 ( V_12 , ( V_170 ) V_164 ) ;
V_12 -> V_171 = V_165 ;
if ( V_166 ) {
V_12 -> V_172 |= ( 1 & V_173 ) <<
V_174 ;
V_167 = F_66 ( V_12 ) ;
V_167 -> V_175 = F_69 ( F_55 ( V_166 -> V_133 ) ) ;
V_167 -> V_176 = F_69 ( V_166 -> V_133 & 0xFFFFFFFF ) ;
V_167 -> V_121 = F_69 ( V_166 -> V_177 ) ;
} else
V_12 -> V_172 |= V_178 ;
F_70 ( V_12 , 8 ) ;
}
static void F_71 ( struct V_179 * V_180 , T_2 V_181 ,
struct V_127 * V_166 )
{
int V_5 , V_182 = F_72 ( F_73 ( V_166 -> V_131 , V_166 -> V_177 ) , V_181 ) ;
T_5 V_133 = ( T_5 ) V_166 -> V_133 ;
for ( V_5 = 0 ; V_5 < V_182 ; V_5 ++ ) {
V_180 [ V_5 ] . V_183 = F_69 ( V_133 & 0xFFFFFFFF ) ;
V_180 [ V_5 ] . V_184 = F_69 ( F_55 ( V_133 ) ) ;
V_133 += V_185 ;
}
}
static inline struct V_11 * F_74 ( struct V_1 * V_2 )
{
struct V_127 * V_128 = & V_2 -> V_128 ;
struct V_11 * V_12
= & ( (struct V_129 * ) ( V_128 -> V_131 ) ) -> V_12 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
static struct V_11 * F_75 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 . V_17 ;
struct V_11 * V_12 ;
if ( ! V_15 -> V_186 )
return NULL ;
if ( F_45 ( & V_15 -> V_116 ) >= V_15 -> V_121 )
return NULL ;
V_12 = F_76 ( V_15 ) ;
F_77 ( V_15 ) ;
F_78 ( & V_15 -> V_116 ) ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
static bool F_79 ( struct V_1 * V_2 )
{
return V_2 -> V_16 . V_17 . V_186 ;
}
static int F_80 ( struct V_1 * V_2 )
{
if ( F_79 ( V_2 ) ) {
F_33 ( & V_2 -> V_187 ) ;
return 0 ;
} else {
return F_81 ( & V_2 -> V_188 ) ;
}
}
static void F_82 ( struct V_1 * V_2 )
{
if ( F_79 ( V_2 ) )
F_35 ( & V_2 -> V_187 ) ;
else
return F_83 ( & V_2 -> V_188 ) ;
}
static struct V_11 * F_84 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_189 ;
if ( F_79 ( V_2 ) ) {
V_189 = F_75 ( V_2 ) ;
if ( ! V_189 )
return NULL ;
} else {
V_189 = F_74 ( V_2 ) ;
}
memcpy ( V_189 , V_12 , sizeof( * V_12 ) ) ;
if ( V_12 -> V_172 & F_69 ( V_178 ) )
F_67 ( V_189 , ( V_170 ) F_2 ( V_12 ) ) ;
return V_189 ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_189 ;
int V_35 ;
V_35 = F_80 ( V_2 ) ;
if ( V_35 )
return V_35 ;
V_189 = F_84 ( V_2 , V_12 ) ;
if ( ! V_189 )
return - V_190 ;
if ( F_79 ( V_2 ) )
V_35 = F_47 ( V_2 ) ;
else
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 )
memcpy ( V_12 , V_189 , sizeof( * V_12 ) ) ;
F_82 ( V_2 ) ;
return V_35 ;
}
int F_86 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_35 ;
if ( F_18 ( V_2 ) )
return 0 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = ( T_1 * ) F_74 ( V_2 ) ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0x12 ;
* V_12 ++ = 0x34 ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0x56 ;
* V_12 ++ = 0x78 ;
* V_12 = 0xFF ;
V_35 = F_54 ( V_2 ) ;
F_83 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_87 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_35 ;
if ( F_18 ( V_2 ) )
return 0 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = ( T_1 * ) F_74 ( V_2 ) ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xAA ;
* V_12 ++ = 0xBB ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xCC ;
* V_12 ++ = 0xDD ;
* V_12 = 0xFF ;
V_35 = F_54 ( V_2 ) ;
F_83 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_88 ( struct V_1 * V_2 , struct V_191 * V_192 )
{
struct V_11 * V_12 ;
struct V_193 * V_194 ;
struct V_127 * V_195 = & V_192 -> V_17 . V_196 ;
int V_35 , V_197 = 0 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_199 , sizeof( * V_194 ) , V_12 , NULL ) ;
if ( ! ( F_57 ( V_2 ) || F_18 ( V_2 ) ) )
V_197 = 2 ;
V_194 -> V_198 . V_169 = V_197 ;
V_194 -> V_200 = F_89 ( F_73 ( V_195 -> V_131 , V_195 -> V_177 ) ) ;
F_90 ( struct V_201 , V_74 , V_194 -> V_202 , 1 ) ;
F_90 ( struct V_201 , V_177 , V_194 -> V_202 , 0 ) ;
F_90 ( struct V_201 , V_203 , V_194 -> V_202 ,
F_91 ( V_192 -> V_17 . V_121 / 256 ) ) ;
F_70 ( V_194 -> V_202 , sizeof( V_194 -> V_202 ) ) ;
F_71 ( V_194 -> V_180 , F_92 ( V_194 -> V_180 ) , V_195 ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_204 * V_52 = F_2 ( V_12 ) ;
V_192 -> V_17 . V_19 = F_22 ( V_52 -> V_205 ) ;
V_192 -> V_206 =
( V_197 == 2 ) ? F_22 ( V_52 -> V_206 ) : V_192 -> V_207 ;
V_192 -> V_17 . V_186 = true ;
}
F_83 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_93 ( struct V_1 * V_2 , T_1 * V_208 ,
bool V_209 , T_2 V_210 , T_2 V_211 )
{
struct V_11 * V_12 ;
struct V_212 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_213 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> type = V_214 ;
if ( V_209 ) {
V_194 -> V_209 = 1 ;
} else {
V_194 -> V_215 = F_89 ( ( T_3 ) V_210 ) ;
V_194 -> V_211 = F_69 ( V_211 ) ;
V_194 -> V_209 = 0 ;
}
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_216 * V_52 = F_2 ( V_12 ) ;
memcpy ( V_208 , V_52 -> V_217 . V_31 , V_218 ) ;
}
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_94 ( struct V_1 * V_2 , T_1 * V_208 ,
T_2 V_215 , T_2 * V_211 , T_2 V_219 )
{
struct V_11 * V_12 ;
struct V_220 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_221 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_198 . V_219 = V_219 ;
V_194 -> V_215 = F_69 ( V_215 ) ;
memcpy ( V_194 -> V_222 , V_208 , V_218 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_223 * V_52 = F_2 ( V_12 ) ;
* V_211 = F_8 ( V_52 -> V_211 ) ;
}
V_149:
F_35 ( & V_2 -> V_187 ) ;
if ( V_35 == V_60 )
V_35 = - V_224 ;
return V_35 ;
}
int F_95 ( struct V_1 * V_2 , T_2 V_215 , int V_211 , T_2 V_225 )
{
struct V_11 * V_12 ;
struct V_226 * V_194 ;
int V_35 ;
if ( V_211 == - 1 )
return 0 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_227 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_198 . V_219 = V_225 ;
V_194 -> V_215 = F_69 ( V_215 ) ;
V_194 -> V_211 = F_69 ( V_211 ) ;
V_35 = F_47 ( V_2 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_96 ( struct V_1 * V_2 , struct V_14 * V_109 ,
struct V_14 * V_228 , bool V_229 , int V_230 )
{
struct V_11 * V_12 ;
struct V_231 * V_194 ;
struct V_127 * V_195 = & V_109 -> V_196 ;
void * V_232 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_194 = F_2 ( V_12 ) ;
V_232 = & V_194 -> V_202 ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_233 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_200 = F_89 ( F_73 ( V_195 -> V_131 , V_195 -> V_177 ) ) ;
if ( F_57 ( V_2 ) ) {
F_90 ( struct V_234 , V_235 , V_232 ,
V_230 ) ;
F_90 ( struct V_234 , V_236 ,
V_232 , V_229 ) ;
F_90 ( struct V_234 , V_203 , V_232 ,
F_91 ( V_109 -> V_121 / 256 ) ) ;
F_90 ( struct V_234 , V_74 , V_232 , 1 ) ;
F_90 ( struct V_234 , V_237 , V_232 , 1 ) ;
F_90 ( struct V_234 , V_238 , V_232 , V_228 -> V_19 ) ;
} else {
V_194 -> V_198 . V_169 = 2 ;
V_194 -> V_239 = 1 ;
if ( ! F_18 ( V_2 ) )
F_90 ( struct V_240 , V_235 ,
V_232 , V_230 ) ;
F_90 ( struct V_240 , V_236 , V_232 ,
V_229 ) ;
F_90 ( struct V_240 , V_203 , V_232 ,
F_91 ( V_109 -> V_121 / 256 ) ) ;
F_90 ( struct V_240 , V_74 , V_232 , 1 ) ;
F_90 ( struct V_240 , V_237 ,
V_232 , 1 ) ;
F_90 ( struct V_240 , V_238 ,
V_232 , V_228 -> V_19 ) ;
}
F_70 ( V_232 , sizeof( V_194 -> V_202 ) ) ;
F_71 ( V_194 -> V_180 , F_92 ( V_194 -> V_180 ) , V_195 ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_241 * V_52 = F_2 ( V_12 ) ;
V_109 -> V_19 = F_22 ( V_52 -> V_242 ) ;
V_109 -> V_186 = true ;
}
F_83 ( & V_2 -> V_188 ) ;
return V_35 ;
}
static T_2 F_97 ( int V_243 )
{
T_2 V_244 = F_98 ( V_243 ) ;
if ( V_244 == 16 )
V_244 = 0 ;
return V_244 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_109 )
{
struct V_11 * V_12 ;
struct V_245 * V_194 ;
struct V_127 * V_195 = & V_15 -> V_196 ;
void * V_232 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_194 = F_2 ( V_12 ) ;
V_232 = & V_194 -> V_202 ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_246 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_200 = F_89 ( F_73 ( V_195 -> V_131 , V_195 -> V_177 ) ) ;
if ( F_18 ( V_2 ) ) {
V_194 -> V_198 . V_169 = 1 ;
V_194 -> V_242 = F_89 ( V_109 -> V_19 ) ;
F_90 ( struct V_247 , V_248 , V_232 ,
F_97 ( V_15 -> V_121 ) ) ;
F_90 ( struct V_247 , V_74 , V_232 , 1 ) ;
F_90 ( struct V_247 , V_249 ,
V_232 , V_109 -> V_19 ) ;
F_90 ( struct V_247 , V_250 ,
V_232 , 1 ) ;
} else {
F_90 ( struct V_251 , V_74 , V_232 , 1 ) ;
F_90 ( struct V_251 , V_248 , V_232 ,
F_97 ( V_15 -> V_121 ) ) ;
F_90 ( struct V_251 , V_242 , V_232 , V_109 -> V_19 ) ;
}
V_194 -> V_252 [ 0 ] = F_69 ( 0x00000022 ) ;
V_194 -> V_252 [ 0 ] |= F_69 ( 1 << V_107 ) ;
F_70 ( V_232 , sizeof( V_194 -> V_202 ) ) ;
F_71 ( V_194 -> V_180 , F_92 ( V_194 -> V_180 ) , V_195 ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_253 * V_52 = F_2 ( V_12 ) ;
V_15 -> V_19 = F_22 ( V_52 -> V_19 ) ;
V_15 -> V_186 = true ;
}
F_83 ( & V_2 -> V_188 ) ;
return V_35 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_109 )
{
struct V_11 * V_12 ;
struct V_254 * V_194 ;
struct V_127 * V_195 = & V_15 -> V_196 ;
void * V_232 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_194 = F_2 ( V_12 ) ;
V_232 = & V_194 -> V_202 ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_255 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_200 = F_89 ( F_73 ( V_195 -> V_131 , V_195 -> V_177 ) ) ;
F_90 ( struct V_251 , V_74 , V_232 , 1 ) ;
F_90 ( struct V_251 , V_248 , V_232 ,
F_97 ( V_15 -> V_121 ) ) ;
F_90 ( struct V_251 , V_242 , V_232 , V_109 -> V_19 ) ;
F_70 ( V_232 , sizeof( V_194 -> V_202 ) ) ;
F_71 ( V_194 -> V_180 , F_92 ( V_194 -> V_180 ) , V_195 ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_253 * V_52 = F_2 ( V_12 ) ;
V_15 -> V_19 = F_22 ( V_52 -> V_19 ) ;
V_15 -> V_186 = true ;
}
F_83 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_101 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_109 )
{
int V_35 ;
V_35 = F_99 ( V_2 , V_15 , V_109 ) ;
if ( V_35 && ! F_18 ( V_2 ) ) {
F_15 ( & V_2 -> V_61 -> V_62 , L_10
L_11
L_12 ) ;
V_35 = F_100 ( V_2 , V_15 , V_109 ) ;
}
return V_35 ;
}
int F_102 ( struct V_1 * V_2 , struct V_256 * V_257 )
{
struct V_11 V_12 = { 0 } ;
struct V_258 * V_194 ;
struct V_14 * V_259 = & V_257 -> V_17 ;
struct V_14 * V_109 = & V_257 -> V_109 ;
struct V_127 * V_195 = & V_259 -> V_196 ;
int V_35 , V_197 = 0 ;
V_194 = F_2 ( & V_12 ) ;
F_68 ( & V_194 -> V_198 , V_48 ,
V_260 , sizeof( * V_194 ) , & V_12 , NULL ) ;
if ( F_18 ( V_2 ) ) {
V_194 -> V_198 . V_169 = 1 ;
} else if ( F_57 ( V_2 ) ) {
if ( V_2 -> V_261 & V_262 )
V_194 -> V_198 . V_169 = 2 ;
} else {
V_194 -> V_198 . V_169 = 2 ;
}
if ( V_194 -> V_198 . V_169 > 0 )
V_194 -> V_215 = F_89 ( V_2 -> V_210 ) ;
V_194 -> V_200 = F_73 ( V_195 -> V_131 , V_195 -> V_177 ) ;
V_194 -> V_263 = V_264 ;
V_194 -> type = V_265 ;
V_194 -> V_242 = F_89 ( V_109 -> V_19 ) ;
V_194 -> V_266 = F_97 ( V_259 -> V_121 ) ;
F_71 ( V_194 -> V_180 , F_92 ( V_194 -> V_180 ) , V_195 ) ;
V_197 = V_194 -> V_198 . V_169 ;
V_35 = F_85 ( V_2 , & V_12 ) ;
if ( ! V_35 ) {
struct V_267 * V_52 = F_2 ( & V_12 ) ;
V_259 -> V_19 = F_22 ( V_52 -> V_268 ) ;
if ( V_197 == 2 )
V_257 -> V_269 = F_8 ( V_52 -> V_269 ) ;
else
V_257 -> V_269 = V_270 ;
V_259 -> V_186 = true ;
}
return V_35 ;
}
int F_103 ( struct V_1 * V_2 ,
struct V_14 * V_271 , T_3 V_242 , T_3 V_272 ,
T_2 V_215 , T_2 V_273 , T_1 * V_274 )
{
struct V_11 * V_12 ;
struct V_275 * V_194 ;
struct V_127 * V_195 = & V_271 -> V_196 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_48 ,
V_276 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_242 = F_89 ( V_242 ) ;
V_194 -> V_272 = F_98 ( V_272 ) - 1 ;
V_194 -> V_200 = 2 ;
F_71 ( V_194 -> V_180 , F_92 ( V_194 -> V_180 ) , V_195 ) ;
V_194 -> V_277 = F_69 ( V_215 ) ;
V_194 -> V_278 = F_89 ( V_279 ) ;
V_194 -> V_280 = F_69 ( V_273 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_281 * V_52 = F_2 ( V_12 ) ;
V_271 -> V_19 = F_22 ( V_52 -> V_19 ) ;
V_271 -> V_186 = true ;
* V_274 = V_52 -> V_274 ;
}
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_104 ( struct V_1 * V_2 , struct V_14 * V_17 ,
int V_282 )
{
struct V_11 * V_12 ;
struct V_283 * V_194 ;
T_1 V_284 = 0 , V_3 = 0 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_194 = F_2 ( V_12 ) ;
switch ( V_282 ) {
case V_285 :
V_284 = V_43 ;
V_3 = V_286 ;
break;
case V_287 :
V_284 = V_43 ;
V_3 = V_288 ;
break;
case V_289 :
V_284 = V_48 ;
V_3 = V_290 ;
break;
case V_291 :
V_284 = V_48 ;
V_3 = V_292 ;
break;
case V_293 :
V_284 = V_43 ;
V_3 = V_294 ;
break;
default:
F_105 () ;
}
F_68 ( & V_194 -> V_198 , V_284 , V_3 , sizeof( * V_194 ) , V_12 ,
NULL ) ;
V_194 -> V_19 = F_89 ( V_17 -> V_19 ) ;
V_35 = F_54 ( V_2 ) ;
V_17 -> V_186 = false ;
F_83 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_106 ( struct V_1 * V_2 , struct V_14 * V_17 )
{
struct V_11 * V_12 ;
struct V_283 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_48 ,
V_292 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_19 = F_89 ( V_17 -> V_19 ) ;
V_35 = F_47 ( V_2 ) ;
V_17 -> V_186 = false ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_107 ( struct V_1 * V_2 , T_2 V_295 , T_2 V_296 ,
T_2 * V_210 , T_2 V_219 )
{
struct V_11 V_12 = { 0 } ;
struct V_297 * V_194 ;
int V_35 ;
V_194 = F_2 ( & V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_298 , sizeof( * V_194 ) , & V_12 , NULL ) ;
V_194 -> V_198 . V_219 = V_219 ;
V_194 -> V_299 = F_69 ( V_295 ) ;
V_194 -> V_300 = F_69 ( V_296 ) ;
V_194 -> V_301 = true ;
V_35 = F_85 ( V_2 , & V_12 ) ;
if ( ! V_35 ) {
struct V_302 * V_52 = F_2 ( & V_12 ) ;
* V_210 = F_8 ( V_52 -> V_277 ) ;
if ( F_108 ( V_2 ) && ! F_109 ( V_2 ) )
V_2 -> V_211 [ 0 ] = F_8 ( V_52 -> V_211 ) ;
}
return V_35 ;
}
int F_110 ( struct V_1 * V_2 , int V_277 , T_2 V_219 )
{
struct V_11 * V_12 ;
struct V_303 * V_194 ;
int V_35 ;
if ( V_277 == - 1 )
return 0 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_304 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_198 . V_219 = V_219 ;
V_194 -> V_277 = F_69 ( V_277 ) ;
V_35 = F_47 ( V_2 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_111 ( struct V_1 * V_2 , struct V_127 * V_305 )
{
struct V_11 * V_12 ;
struct V_163 * V_198 ;
int V_35 = 0 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_198 = V_305 -> V_131 ;
F_68 ( V_198 , V_48 ,
V_46 , V_305 -> V_177 , V_12 , V_305 ) ;
if ( F_112 ( V_2 ) )
V_198 -> V_169 = 0 ;
if ( F_108 ( V_2 ) || F_18 ( V_2 ) )
V_198 -> V_169 = 1 ;
else
V_198 -> V_169 = 2 ;
F_3 ( V_2 ) ;
V_2 -> V_49 = true ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_113 ( struct V_1 * V_2 ,
struct V_127 * V_305 )
{
struct V_11 * V_12 ;
struct V_306 * V_194 ;
int V_35 = 0 ;
if ( ! F_1 ( V_2 , V_47 ,
V_48 ) )
return - V_224 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = V_305 -> V_131 ;
F_68 ( & V_194 -> V_198 , V_48 ,
V_47 , V_305 -> V_177 , V_12 ,
V_305 ) ;
V_194 -> V_307 . V_308 . V_309 = F_89 ( V_2 -> V_310 ) ;
V_194 -> V_307 . V_308 . V_311 = 0 ;
F_3 ( V_2 ) ;
V_2 -> V_49 = true ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
static int F_114 ( int V_312 )
{
switch ( V_312 ) {
case V_313 :
return 0 ;
case V_314 :
return 10 ;
case V_315 :
return 100 ;
case V_316 :
return 1000 ;
case V_317 :
return 10000 ;
case V_318 :
return 20000 ;
case V_319 :
return 25000 ;
case V_320 :
return 40000 ;
}
return 0 ;
}
int F_115 ( struct V_1 * V_2 , T_3 * V_69 ,
T_1 * V_321 , T_2 V_225 )
{
struct V_11 * V_12 ;
struct V_322 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
if ( V_321 )
* V_321 = V_323 ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_324 , sizeof( * V_194 ) , V_12 , NULL ) ;
if ( ! F_112 ( V_2 ) )
V_194 -> V_198 . V_169 = 1 ;
V_194 -> V_198 . V_219 = V_225 ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_325 * V_52 = F_2 ( V_12 ) ;
if ( V_69 ) {
* V_69 = V_52 -> V_69 ?
F_22 ( V_52 -> V_69 ) * 10 :
F_114 ( V_52 -> V_312 ) ;
if ( ! V_52 -> V_326 )
* V_69 = 0 ;
}
if ( V_321 )
* V_321 = V_52 -> V_326 ;
}
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_116 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_327 * V_194 ;
int V_35 = 0 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_50 , sizeof( * V_194 ) ,
V_12 , NULL ) ;
F_3 ( V_2 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_117 ( struct V_1 * V_2 , T_2 * V_328 )
{
struct V_11 * V_12 ;
struct V_329 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_330 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_331 = F_69 ( V_332 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_333 * V_52 = F_2 ( V_12 ) ;
if ( V_328 && V_52 -> V_328 )
* V_328 = F_8 ( V_52 -> V_328 ) -
sizeof( T_2 ) ;
}
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
void F_118 ( struct V_1 * V_2 , T_2 V_334 , void * V_335 )
{
struct V_127 V_336 ;
struct V_11 * V_12 ;
struct V_329 * V_194 ;
T_2 V_337 = 0 , V_338 , V_339 ,
V_340 = sizeof( T_2 ) , V_341 ;
int V_35 ;
if ( V_334 == 0 )
return;
V_338 = V_334 ;
V_336 . V_177 = sizeof( struct V_329 ) + 60 * 1024 ;
V_336 . V_131 = F_119 ( V_2 -> V_61 ,
V_336 . V_177 ,
& V_336 . V_133 ) ;
if ( ! V_336 . V_131 ) {
V_35 = - V_342 ;
F_16 ( & V_2 -> V_61 -> V_62 ,
L_13 ) ;
return;
}
F_33 ( & V_2 -> V_187 ) ;
while ( V_338 ) {
V_339 = F_72 ( V_338 , ( T_2 ) 60 * 1024 ) ;
V_338 -= V_339 ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = V_336 . V_131 ;
V_341 = sizeof( struct V_329 ) + V_339 ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_330 , V_341 , V_12 ,
& V_336 ) ;
V_194 -> V_331 = F_69 ( V_343 ) ;
V_194 -> V_344 = F_69 ( V_340 ) ;
V_194 -> V_345 = F_69 ( V_339 ) ;
V_194 -> V_346 = F_69 ( V_339 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_333 * V_52 = V_336 . V_131 ;
memcpy ( V_335 + V_337 ,
V_52 -> V_347 ,
F_8 ( V_52 -> V_345 ) ) ;
} else {
F_16 ( & V_2 -> V_61 -> V_62 , L_14 ) ;
goto V_149;
}
V_337 += V_339 ;
V_340 += V_339 ;
}
V_149:
F_120 ( V_2 -> V_61 , V_336 . V_177 ,
V_336 . V_131 ,
V_336 . V_133 ) ;
F_35 ( & V_2 -> V_187 ) ;
}
int F_121 ( struct V_1 * V_2 , char * V_348 ,
char * V_349 )
{
struct V_11 * V_12 ;
struct V_350 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_351 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_352 * V_52 = F_2 ( V_12 ) ;
strcpy ( V_348 , V_52 -> V_353 ) ;
if ( V_349 )
strcpy ( V_349 , V_52 -> V_354 ) ;
}
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_122 ( struct V_1 * V_2 , struct V_355 * V_356 ,
int V_112 )
{
struct V_11 * V_12 ;
struct V_357 * V_194 ;
int V_35 = 0 , V_5 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_358 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_359 = F_69 ( V_112 ) ;
for ( V_5 = 0 ; V_5 < V_112 ; V_5 ++ ) {
V_194 -> V_356 [ V_5 ] . V_205 = F_69 ( V_356 [ V_5 ] . V_205 ) ;
V_194 -> V_356 [ V_5 ] . V_360 = 0 ;
V_194 -> V_356 [ V_5 ] . V_361 =
F_69 ( V_356 [ V_5 ] . V_361 ) ;
}
F_3 ( V_2 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_123 ( struct V_1 * V_2 , T_2 V_215 , T_3 * V_362 ,
T_2 V_112 , bool V_363 )
{
struct V_11 * V_12 ;
struct V_364 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_365 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_277 = V_215 ;
V_194 -> V_363 = V_363 ;
V_194 -> V_366 = V_367 & F_124 ( V_2 ) ? 1 : 0 ;
V_194 -> V_368 = V_112 ;
if ( ! V_363 ) {
memcpy ( V_194 -> V_369 , V_362 ,
V_194 -> V_368 * sizeof( V_362 [ 0 ] ) ) ;
}
V_35 = F_47 ( V_2 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_125 ( struct V_1 * V_2 , T_2 V_26 , T_2 V_370 )
{
struct V_11 * V_12 ;
struct V_127 * V_166 = & V_2 -> V_371 ;
struct V_372 * V_194 = V_166 -> V_131 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
memset ( V_194 , 0 , sizeof( * V_194 ) ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_373 , sizeof( * V_194 ) ,
V_12 , V_166 ) ;
V_194 -> V_215 = F_69 ( V_2 -> V_210 ) ;
if ( V_26 & V_374 ) {
V_194 -> V_375 = F_69 ( V_376 |
V_377 |
V_378 ) ;
if ( V_370 == V_379 )
V_194 -> V_380 = F_69 ( V_376 |
V_377 |
V_378 ) ;
} else if ( V_26 & V_381 ) {
V_194 -> V_375 = V_194 -> V_380 =
F_69 ( V_378 ) ;
} else if ( V_26 & V_382 ) {
V_194 -> V_375 = F_69 ( V_377 ) ;
if ( V_370 == V_379 )
V_194 -> V_380 =
F_69 ( V_377 ) ;
} else {
struct V_383 * V_384 ;
int V_5 = 0 ;
V_194 -> V_375 = V_194 -> V_380 =
F_69 ( V_385 ) ;
V_194 -> V_375 |=
F_69 ( V_378 &
F_124 ( V_2 ) ) ;
V_194 -> V_386 = F_69 ( F_126 ( V_2 -> V_387 ) ) ;
F_127 (ha, adapter->netdev)
memcpy ( V_194 -> V_388 [ V_5 ++ ] . V_389 , V_384 -> V_31 , V_218 ) ;
}
if ( ( V_194 -> V_375 & F_69 ( F_124 ( V_2 ) ) ) !=
V_194 -> V_375 ) {
F_15 ( & V_2 -> V_61 -> V_62 ,
L_15 ,
V_194 -> V_375 ) ;
F_15 ( & V_2 -> V_61 -> V_62 ,
L_16 ,
F_124 ( V_2 ) ) ;
}
V_194 -> V_375 &= F_69 ( F_124 ( V_2 ) ) ;
V_35 = F_47 ( V_2 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_128 ( struct V_1 * V_2 , T_2 V_390 , T_2 V_391 )
{
struct V_11 * V_12 ;
struct V_392 * V_194 ;
int V_35 ;
if ( ! F_1 ( V_2 , V_393 ,
V_43 ) )
return - V_224 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_393 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_394 = F_89 ( ( T_3 ) V_390 ) ;
V_194 -> V_395 = F_89 ( ( T_3 ) V_391 ) ;
V_35 = F_47 ( V_2 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_129 ( struct V_1 * V_2 , T_2 * V_390 , T_2 * V_391 )
{
struct V_11 * V_12 ;
struct V_396 * V_194 ;
int V_35 ;
if ( ! F_1 ( V_2 , V_397 ,
V_43 ) )
return - V_224 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_397 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_398 * V_52 =
F_2 ( V_12 ) ;
* V_390 = F_22 ( V_52 -> V_394 ) ;
* V_391 = F_22 ( V_52 -> V_395 ) ;
}
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_130 ( struct V_1 * V_2 , T_2 * V_83 ,
T_2 * V_399 , T_2 * V_400 , T_3 * V_401 )
{
struct V_11 * V_12 ;
struct V_402 * V_194 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_403 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_404 * V_52 = F_2 ( V_12 ) ;
* V_83 = F_8 ( V_52 -> V_405 ) ;
* V_399 = F_8 ( V_52 -> V_406 ) ;
* V_400 = F_8 ( V_52 -> V_261 ) ;
* V_401 = F_8 ( V_52 -> V_407 ) & 0xFF ;
}
F_83 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_131 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_163 * V_194 ;
int V_35 ;
if ( F_18 ( V_2 ) ) {
V_35 = F_59 ( V_2 ) ;
if ( ! V_35 ) {
F_6 ( V_154 ,
V_2 -> V_22 + V_155 ) ;
V_35 = F_62 ( V_2 ) ;
}
if ( V_35 ) {
F_16 ( & V_2 -> V_61 -> V_62 ,
L_17 ) ;
}
return V_35 ;
}
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_194 = F_2 ( V_12 ) ;
F_68 ( V_194 , V_43 ,
V_408 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_35 = F_54 ( V_2 ) ;
F_83 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_132 ( struct V_1 * V_2 , T_1 * V_409 ,
T_2 V_410 , T_3 V_411 )
{
struct V_11 * V_12 ;
struct V_412 * V_194 ;
T_2 V_413 [ 10 ] = { 0x15d43fa5 , 0x2534685a , 0x5f87693a , 0x5668494e ,
0x33cf6a53 , 0x383334c6 , 0x76ac4257 , 0x59b242b2 ,
0x3ea83c02 , 0x4a110304 } ;
int V_35 ;
if ( ! ( F_124 ( V_2 ) & V_414 ) )
return 0 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_48 ,
V_415 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_215 = F_69 ( V_2 -> V_210 ) ;
V_194 -> V_416 = F_89 ( V_410 ) ;
V_194 -> V_417 = F_89 ( F_98 ( V_411 ) - 1 ) ;
if ( F_18 ( V_2 ) || F_133 ( V_2 ) )
V_194 -> V_198 . V_169 = 1 ;
memcpy ( V_194 -> V_418 , V_409 , V_411 ) ;
memcpy ( V_194 -> V_419 , V_413 , sizeof( V_413 ) ) ;
F_70 ( V_194 -> V_419 , sizeof( V_194 -> V_419 ) ) ;
V_35 = F_54 ( V_2 ) ;
F_83 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_134 ( struct V_1 * V_2 , T_1 V_83 ,
T_1 V_420 , T_1 V_421 , T_1 V_422 )
{
struct V_11 * V_12 ;
struct V_423 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_424 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_83 = V_83 ;
V_194 -> V_425 = V_422 ;
V_194 -> V_426 = V_420 ;
V_194 -> V_427 = V_421 ;
V_35 = F_47 ( V_2 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_135 ( struct V_1 * V_2 , T_1 V_83 , T_2 * V_422 )
{
struct V_11 * V_12 ;
struct V_428 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_429 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_83 = V_83 ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_430 * V_52 =
F_2 ( V_12 ) ;
* V_422 = V_52 -> V_425 ;
}
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_136 ( struct V_1 * V_2 , struct V_127 * V_431 ,
T_2 V_432 , T_2 V_433 ,
const char * V_434 , T_2 * V_435 ,
T_1 * V_436 , T_1 * V_437 )
{
struct V_11 * V_12 ;
struct V_438 * V_194 ;
struct V_439 * V_52 ;
void * V_232 = NULL ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_2 -> V_44 = 0 ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_440;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_42 ,
sizeof( struct V_438 ) , V_12 ,
NULL ) ;
V_232 = & V_194 -> V_202 ;
F_90 ( struct V_441 ,
V_442 , V_232 , V_432 ) ;
if ( V_432 == 0 )
F_90 ( struct V_441 ,
V_443 , V_232 , 1 ) ;
else
F_90 ( struct V_441 ,
V_443 , V_232 , 0 ) ;
F_70 ( V_232 , sizeof( V_194 -> V_202 ) ) ;
V_194 -> V_444 = F_69 ( V_433 ) ;
strcpy ( V_194 -> V_445 , V_434 ) ;
V_194 -> V_446 = F_69 ( 1 ) ;
V_194 -> V_334 = F_69 ( V_432 ) ;
V_194 -> V_447 = F_69 ( ( V_431 -> V_133 +
sizeof( struct V_438 ) )
& 0xFFFFFFFF ) ;
V_194 -> V_448 = F_69 ( F_55 ( V_431 -> V_133 +
sizeof( struct V_438 ) ) ) ;
F_3 ( V_2 ) ;
F_35 ( & V_2 -> V_187 ) ;
if ( ! F_137 ( & V_2 -> V_40 ,
F_138 ( 60000 ) ) )
V_35 = - 1 ;
else
V_35 = V_2 -> V_44 ;
V_52 = F_2 ( V_12 ) ;
if ( ! V_35 ) {
* V_435 = F_8 ( V_52 -> V_449 ) ;
* V_436 = V_52 -> V_436 ;
} else {
* V_437 = V_52 -> V_450 ;
}
return V_35 ;
V_440:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_139 ( struct V_1 * V_2 , struct V_127 * V_431 ,
T_2 V_432 , T_2 V_433 , const char * V_434 ,
T_2 * V_451 , T_2 * V_443 , T_1 * V_437 )
{
struct V_11 * V_12 ;
struct V_452 * V_194 ;
struct V_453 * V_52 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_440;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_454 ,
sizeof( struct V_452 ) , V_12 ,
NULL ) ;
V_194 -> V_455 = F_69 ( V_432 ) ;
V_194 -> V_456 = F_69 ( V_433 ) ;
strcpy ( V_194 -> V_445 , V_434 ) ;
V_194 -> V_446 = F_69 ( 1 ) ;
V_194 -> V_334 = F_69 ( V_432 ) ;
V_194 -> V_447 = F_69 ( ( V_431 -> V_133 & 0xFFFFFFFF ) ) ;
V_194 -> V_448 = F_69 ( F_55 ( V_431 -> V_133 ) ) ;
V_35 = F_47 ( V_2 ) ;
V_52 = F_2 ( V_12 ) ;
if ( ! V_35 ) {
* V_451 = F_8 ( V_52 -> V_457 ) ;
* V_443 = F_8 ( V_52 -> V_443 ) ;
} else {
* V_437 = V_52 -> V_450 ;
}
V_440:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_140 ( struct V_1 * V_2 , struct V_127 * V_431 ,
T_2 V_458 , T_2 V_459 , T_2 V_339 )
{
struct V_11 * V_12 ;
struct F_140 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_2 -> V_44 = 0 ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_440;
}
V_194 = V_431 -> V_131 ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_41 , V_431 -> V_177 , V_12 , V_431 ) ;
V_194 -> V_308 . V_460 = F_69 ( V_458 ) ;
V_194 -> V_308 . V_461 = F_69 ( V_459 ) ;
V_194 -> V_308 . V_462 = F_69 ( V_339 ) ;
F_3 ( V_2 ) ;
F_35 ( & V_2 -> V_187 ) ;
if ( ! F_137 ( & V_2 -> V_40 ,
F_138 ( 40000 ) ) )
V_35 = - 1 ;
else
V_35 = V_2 -> V_44 ;
return V_35 ;
V_440:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_141 ( struct V_1 * V_2 , T_1 * V_463 ,
int V_337 )
{
struct V_11 * V_12 ;
struct V_464 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_465 , sizeof( * V_194 ) ,
V_12 , NULL ) ;
V_194 -> V_308 . V_460 = F_69 ( V_466 ) ;
V_194 -> V_308 . V_461 = F_69 ( V_467 ) ;
V_194 -> V_308 . V_337 = F_69 ( V_337 ) ;
V_194 -> V_308 . V_462 = F_69 ( 0x4 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 )
memcpy ( V_463 , V_194 -> V_468 , 4 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_142 ( struct V_1 * V_2 , T_1 * V_217 ,
struct V_127 * V_305 )
{
struct V_11 * V_12 ;
struct V_469 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = V_305 -> V_131 ;
F_68 ( & V_194 -> V_198 , V_48 ,
V_470 , sizeof( * V_194 ) , V_12 ,
V_305 ) ;
memcpy ( V_194 -> V_471 , V_217 , V_218 ) ;
V_35 = F_47 ( V_2 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_143 ( struct V_1 * V_2 , T_1 V_83 ,
T_1 V_472 , T_1 V_473 )
{
struct V_11 * V_12 ;
struct V_474 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_39 ,
V_475 , sizeof( * V_194 ) , V_12 ,
NULL ) ;
V_194 -> V_476 = V_83 ;
V_194 -> V_477 = V_83 ;
V_194 -> V_472 = V_472 ;
V_194 -> V_478 = V_473 ;
V_35 = F_47 ( V_2 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_144 ( struct V_1 * V_2 , T_2 V_83 ,
T_2 V_472 , T_2 V_479 , T_2 V_480 , T_5 V_481 )
{
struct V_11 * V_12 ;
struct V_482 * V_194 ;
struct V_483 * V_52 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_39 ,
V_38 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_198 . V_157 = F_69 ( 15 ) ;
V_194 -> V_481 = F_145 ( V_481 ) ;
V_194 -> V_476 = F_69 ( V_83 ) ;
V_194 -> V_477 = F_69 ( V_83 ) ;
V_194 -> V_479 = F_69 ( V_479 ) ;
V_194 -> V_480 = F_69 ( V_480 ) ;
V_194 -> V_472 = F_69 ( V_472 ) ;
F_3 ( V_2 ) ;
F_35 ( & V_2 -> V_187 ) ;
F_146 ( & V_2 -> V_40 ) ;
V_52 = F_2 ( V_12 ) ;
V_35 = F_8 ( V_52 -> V_35 ) ;
return V_35 ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_147 ( struct V_1 * V_2 , T_5 V_481 ,
T_2 V_484 , struct V_127 * V_431 )
{
struct V_11 * V_12 ;
struct V_485 * V_194 ;
int V_35 ;
int V_5 , V_486 = 0 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = V_431 -> V_131 ;
F_68 ( & V_194 -> V_198 , V_39 ,
V_487 , V_431 -> V_177 , V_12 , V_431 ) ;
V_194 -> V_481 = F_145 ( V_481 ) ;
V_194 -> V_488 = F_69 ( V_484 ) ;
for ( V_5 = 0 ; V_5 < V_484 ; V_5 ++ ) {
V_194 -> V_489 [ V_5 ] = ( T_1 ) ( V_481 >> ( V_486 * 8 ) ) ;
V_486 ++ ;
if ( V_486 > 7 )
V_486 = 0 ;
}
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_490 * V_52 ;
V_52 = V_431 -> V_131 ;
if ( ( memcmp ( V_52 -> V_491 , V_194 -> V_489 , V_484 ) != 0 ) ||
V_52 -> V_492 ) {
V_35 = - 1 ;
}
}
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_148 ( struct V_1 * V_2 ,
struct V_127 * V_305 )
{
struct V_11 * V_12 ;
struct V_493 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = V_305 -> V_131 ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_494 , sizeof( * V_194 ) , V_12 ,
V_305 ) ;
V_35 = F_47 ( V_2 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_149 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_495 * V_194 ;
struct V_127 V_431 ;
int V_35 ;
if ( ! F_1 ( V_2 , V_496 ,
V_43 ) )
return - V_224 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_431 . V_177 = sizeof( struct V_495 ) ;
V_431 . V_131 = F_119 ( V_2 -> V_61 , V_431 . V_177 ,
& V_431 . V_133 ) ;
if ( ! V_431 . V_131 ) {
F_16 ( & V_2 -> V_61 -> V_62 , L_18 ) ;
V_35 = - V_342 ;
goto V_149;
}
V_194 = V_431 . V_131 ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_496 , sizeof( * V_194 ) ,
V_12 , & V_431 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_497 * V_498 =
V_431 . V_131 + sizeof( struct V_163 ) ;
V_2 -> V_68 . V_499 = F_22 ( V_498 -> V_499 ) ;
V_2 -> V_68 . V_500 =
F_22 ( V_498 -> V_500 ) ;
V_2 -> V_68 . V_501 =
F_22 ( V_498 -> V_501 ) ;
V_2 -> V_68 . V_502 =
F_22 ( V_498 -> V_502 ) ;
V_2 -> V_68 . V_503 =
F_8 ( V_498 -> V_503 ) ;
if ( F_112 ( V_2 ) ) {
V_2 -> V_68 . V_502 =
V_504 |
V_505 ;
}
}
F_120 ( V_2 -> V_61 , V_431 . V_177 ,
V_431 . V_131 , V_431 . V_133 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_150 ( struct V_1 * V_2 , T_2 V_506 , T_2 V_219 )
{
struct V_11 * V_12 ;
struct V_507 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_508 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_198 . V_219 = V_219 ;
V_194 -> V_509 = F_69 ( V_510 ) ;
V_194 -> V_511 = F_69 ( V_506 ) ;
V_35 = F_47 ( V_2 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_151 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_512 * V_194 ;
struct V_513 * V_52 ;
int V_35 ;
int V_341 = F_152 ( sizeof( * V_194 ) , sizeof( * V_52 ) ) ;
struct V_514 * V_515 ;
struct V_127 V_516 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
memset ( & V_516 , 0 , sizeof( struct V_127 ) ) ;
V_516 . V_177 = sizeof( struct V_513 ) ;
V_516 . V_131 = F_119 ( V_2 -> V_61 , V_516 . V_177 ,
& V_516 . V_133 ) ;
if ( ! V_516 . V_131 ) {
F_16 ( & V_2 -> V_61 -> V_62 ,
L_19 ) ;
V_35 = - V_342 ;
goto V_149;
}
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = V_516 . V_131 ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_517 , V_341 , V_12 ,
& V_516 ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
V_515 = V_516 . V_131 + sizeof( struct V_28 ) ;
V_2 -> V_310 = V_515 -> V_518 . V_519 ;
}
V_149:
F_83 ( & V_2 -> V_188 ) ;
if ( V_516 . V_131 )
F_120 ( V_2 -> V_61 , V_516 . V_177 ,
V_516 . V_131 , V_516 . V_133 ) ;
return V_35 ;
}
int F_153 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_520 * V_194 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_521 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_522 = F_69 ( V_523 |
V_524 ) ;
V_194 -> V_295 = F_69 ( V_524 ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_525 * V_52 = F_2 ( V_12 ) ;
V_2 -> V_526 = F_8 ( V_52 -> V_295 ) &
V_524 ;
if ( ! V_2 -> V_526 )
F_15 ( & V_2 -> V_61 -> V_62 ,
L_20 ) ;
}
V_149:
F_83 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_154 ( struct V_1 * V_2 , T_2 * V_527 ,
T_2 V_219 )
{
struct V_11 * V_12 ;
struct V_528 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_529 , sizeof( * V_194 ) ,
V_12 , NULL ) ;
V_194 -> V_198 . V_219 = V_219 ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_530 * V_52 =
F_2 ( V_12 ) ;
* V_527 = F_8 ( V_52 -> V_531 ) ;
}
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_155 ( struct V_1 * V_2 , T_2 V_532 ,
T_2 V_219 )
{
struct V_11 * V_12 ;
struct V_533 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_534 , sizeof( * V_194 ) ,
V_12 , NULL ) ;
V_194 -> V_198 . V_219 = V_219 ;
if ( F_18 ( V_2 ) )
V_194 -> V_535 = F_69 ( V_532 ) ;
else
V_194 -> V_532 = F_69 ( V_532 ) ;
V_35 = F_47 ( V_2 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_156 ( struct V_1 * V_2 , T_1 * V_217 ,
bool * V_536 , T_2 * V_211 , T_1 V_219 )
{
struct V_11 * V_12 ;
struct V_537 * V_194 ;
int V_35 ;
int V_538 ;
struct V_127 V_539 ;
int V_5 ;
memset ( & V_539 , 0 , sizeof( struct V_127 ) ) ;
V_539 . V_177 = sizeof( struct V_540 ) ;
V_539 . V_131 = F_119 ( V_2 -> V_61 ,
V_539 . V_177 ,
& V_539 . V_133 ) ;
if ( ! V_539 . V_131 ) {
F_16 ( & V_2 -> V_61 -> V_62 ,
L_21 ) ;
return - V_342 ;
}
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_122;
}
V_194 = V_539 . V_131 ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_541 ,
V_539 . V_177 , V_12 , & V_539 ) ;
V_194 -> V_198 . V_219 = V_219 ;
V_194 -> V_542 = V_214 ;
if ( * V_536 ) {
V_194 -> V_543 = F_69 ( * V_211 ) ;
V_194 -> V_544 = F_89 ( V_2 -> V_210 ) ;
V_194 -> V_545 = 0 ;
} else {
V_194 -> V_545 = 1 ;
}
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_540 * V_52 =
V_539 . V_131 ;
if ( * V_536 ) {
memcpy ( V_217 , V_52 -> V_546 . V_547 . V_548 ,
V_218 ) ;
goto V_122;
}
V_538 = V_52 -> V_549 + V_52 -> V_550 ;
for ( V_5 = 0 ; V_5 < V_538 ; V_5 ++ ) {
struct V_551 * V_552 ;
T_3 V_553 ;
T_2 V_543 ;
V_552 = & V_52 -> V_554 [ V_5 ] ;
V_553 = F_22 ( V_552 -> V_553 ) ;
if ( V_553 == sizeof( T_2 ) ) {
* V_536 = true ;
V_543 = V_552 -> V_547 . V_555 . V_543 ;
* V_211 = F_8 ( V_543 ) ;
goto V_122;
}
}
* V_536 = false ;
memcpy ( V_217 , V_52 -> V_554 [ 0 ] . V_547 . V_548 ,
V_218 ) ;
}
V_122:
F_35 ( & V_2 -> V_187 ) ;
F_120 ( V_2 -> V_61 , V_539 . V_177 ,
V_539 . V_131 , V_539 . V_133 ) ;
return V_35 ;
}
int F_157 ( struct V_1 * V_2 , T_2 V_556 , T_1 * V_217 )
{
bool V_557 = true ;
if ( F_57 ( V_2 ) )
return F_93 ( V_2 , V_217 , false ,
V_2 -> V_210 , V_556 ) ;
else
return F_156 ( V_2 , V_217 , & V_557 ,
& V_556 , 0 ) ;
}
int F_158 ( struct V_1 * V_2 , T_1 * V_217 )
{
int V_35 ;
bool V_558 = false ;
memset ( V_217 , 0 , V_218 ) ;
if ( F_57 ( V_2 ) ) {
if ( F_109 ( V_2 ) )
V_35 = F_93 ( V_2 , V_217 , true , 0 ,
0 ) ;
else
V_35 = F_93 ( V_2 , V_217 , false ,
V_2 -> V_210 , 0 ) ;
} else {
V_35 = F_156 ( V_2 , V_217 , & V_558 ,
NULL , 0 ) ;
}
return V_35 ;
}
int F_159 ( struct V_1 * V_2 , T_1 * V_559 ,
T_1 V_538 , T_2 V_219 )
{
struct V_11 * V_12 ;
struct V_560 * V_194 ;
int V_35 ;
struct V_127 V_431 ;
memset ( & V_431 , 0 , sizeof( struct V_127 ) ) ;
V_431 . V_177 = sizeof( struct V_560 ) ;
V_431 . V_131 = F_160 ( & V_2 -> V_61 -> V_62 , V_431 . V_177 ,
& V_431 . V_133 , V_561 ) ;
if ( ! V_431 . V_131 )
return - V_342 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = V_431 . V_131 ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_562 , sizeof( * V_194 ) ,
V_12 , & V_431 ) ;
V_194 -> V_198 . V_219 = V_219 ;
V_194 -> V_538 = V_538 ;
if ( V_538 )
memcpy ( V_194 -> V_217 , V_559 , V_218 * V_538 ) ;
V_35 = F_47 ( V_2 ) ;
V_149:
F_161 ( & V_2 -> V_61 -> V_62 , V_431 . V_177 ,
V_431 . V_131 , V_431 . V_133 ) ;
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_162 ( struct V_1 * V_2 , T_1 * V_217 , int V_215 , T_2 V_225 )
{
bool V_563 = false ;
T_1 V_564 [ V_218 ] ;
T_2 V_211 ;
int V_35 ;
V_35 = F_156 ( V_2 , V_564 , & V_563 ,
& V_211 , V_225 ) ;
if ( ! V_35 && V_563 )
F_95 ( V_2 , V_215 , V_211 , V_225 ) ;
return F_159 ( V_2 , V_217 , V_217 ? 1 : 0 , V_225 ) ;
}
int F_163 ( struct V_1 * V_2 , T_3 V_87 ,
T_2 V_219 , T_3 V_565 , T_3 V_566 )
{
struct V_11 * V_12 ;
struct V_567 * V_194 ;
void * V_232 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
V_232 = & V_194 -> V_202 ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_568 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_198 . V_219 = V_219 ;
F_90 ( struct V_569 , V_277 , V_232 , V_565 ) ;
if ( V_87 ) {
F_90 ( struct V_569 , V_570 , V_232 , 1 ) ;
F_90 ( struct V_569 , V_87 , V_232 , V_87 ) ;
}
if ( ! F_57 ( V_2 ) && V_566 ) {
F_90 ( struct V_569 , V_277 ,
V_232 , V_2 -> V_310 ) ;
F_90 ( struct V_569 , V_571 , V_232 , 1 ) ;
F_90 ( struct V_569 , V_572 ,
V_232 , V_566 ) ;
}
F_70 ( V_194 -> V_202 , sizeof( V_194 -> V_202 ) ) ;
V_35 = F_47 ( V_2 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_164 ( struct V_1 * V_2 , T_3 * V_87 ,
T_2 V_219 , T_3 V_565 , T_1 * V_399 )
{
struct V_11 * V_12 ;
struct V_573 * V_194 ;
void * V_232 ;
int V_35 ;
T_3 V_574 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
V_232 = & V_194 -> V_202 ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_575 , sizeof( * V_194 ) , V_12 , NULL ) ;
V_194 -> V_198 . V_219 = V_219 ;
F_90 ( struct V_576 , V_277 ,
V_232 , V_565 ) ;
F_90 ( struct V_576 , V_570 , V_232 , 1 ) ;
if ( ! F_57 ( V_2 ) ) {
F_90 ( struct V_576 , V_277 ,
V_232 , V_2 -> V_310 ) ;
F_90 ( struct V_576 , V_571 , V_232 , 1 ) ;
}
F_70 ( V_194 -> V_202 , sizeof( V_194 -> V_202 ) ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_577 * V_52 =
F_2 ( V_12 ) ;
F_12 ( & V_52 -> V_202 ,
sizeof( V_52 -> V_202 ) ) ;
V_574 = F_165 ( struct V_578 ,
V_87 , & V_52 -> V_202 ) ;
if ( V_87 )
* V_87 = F_22 ( V_574 ) ;
if ( V_399 )
* V_399 = F_165 ( struct V_578 ,
V_572 , & V_52 -> V_202 ) ;
}
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_166 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_579 * V_194 ;
int V_35 ;
int V_341 = sizeof( * V_194 ) ;
struct V_127 V_431 ;
if ( ! F_1 ( V_2 , V_470 ,
V_48 ) )
return - V_224 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
memset ( & V_431 , 0 , sizeof( struct V_127 ) ) ;
V_431 . V_177 = sizeof( struct V_580 ) ;
V_431 . V_131 = F_119 ( V_2 -> V_61 , V_431 . V_177 ,
& V_431 . V_133 ) ;
if ( ! V_431 . V_131 ) {
F_16 ( & V_2 -> V_61 -> V_62 ,
L_19 ) ;
V_35 = - V_342 ;
goto V_149;
}
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = V_431 . V_131 ;
F_68 ( & V_194 -> V_198 , V_48 ,
V_470 ,
V_341 , V_12 , & V_431 ) ;
V_194 -> V_198 . V_169 = 1 ;
V_194 -> V_581 = V_582 ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_580 * V_52 ;
V_52 = (struct V_580 * ) V_431 . V_131 ;
if ( V_52 -> V_198 . V_583 < V_341 ) {
V_35 = - 1 ;
goto V_149;
}
V_2 -> V_584 = V_52 -> V_585 ;
}
V_149:
F_83 ( & V_2 -> V_188 ) ;
if ( V_431 . V_131 )
F_120 ( V_2 -> V_61 , V_431 . V_177 , V_431 . V_131 , V_431 . V_133 ) ;
return V_35 ;
}
int F_167 ( struct V_1 * V_2 ,
struct V_127 * V_431 )
{
struct V_11 * V_12 ;
struct V_586 * V_194 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = V_431 -> V_131 ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_587 ,
V_431 -> V_177 , V_12 , V_431 ) ;
V_194 -> V_588 = F_69 ( 1 ) ;
V_35 = F_54 ( V_2 ) ;
V_149:
F_83 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_168 ( struct V_1 * V_2 ,
struct V_127 * V_431 ,
struct V_589 * V_590 )
{
struct V_11 * V_12 ;
struct V_591 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = V_431 -> V_131 ;
memcpy ( & V_194 -> V_592 , V_590 , sizeof( struct V_589 ) ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_593 ,
V_431 -> V_177 , V_12 , V_431 ) ;
V_35 = F_47 ( V_2 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_169 ( struct V_1 * V_2 , T_1 * V_594 )
{
struct V_11 * V_12 ;
struct V_595 * V_194 ;
int V_35 ;
if ( ! F_18 ( V_2 ) ) {
* V_594 = V_2 -> V_310 + '0' ;
return 0 ;
}
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_596 , sizeof( * V_194 ) , V_12 ,
NULL ) ;
V_194 -> V_198 . V_169 = 1 ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_597 * V_52 = F_2 ( V_12 ) ;
* V_594 = V_52 -> V_594 [ V_2 -> V_310 ] ;
} else {
* V_594 = V_2 -> V_310 + '0' ;
}
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
static struct V_598 * F_170 ( T_1 * V_335 , T_2 V_599 )
{
struct V_600 * V_198 = (struct V_600 * ) V_335 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_599 ; V_5 ++ ) {
if ( V_198 -> V_601 == V_602 ||
V_198 -> V_601 == V_603 )
return (struct V_598 * ) V_198 ;
V_198 -> V_604 = V_198 -> V_604 ? : V_605 ;
V_198 = ( void * ) V_198 + V_198 -> V_604 ;
}
return NULL ;
}
static struct V_606 * F_171 ( T_1 V_607 , T_1 * V_335 ,
T_2 V_599 )
{
struct V_600 * V_198 = (struct V_600 * ) V_335 ;
struct V_606 * V_608 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_599 ; V_5 ++ ) {
if ( ( V_198 -> V_601 == V_609 ||
V_198 -> V_601 == V_610 ) ) {
V_608 = (struct V_606 * ) V_198 ;
if ( V_608 -> V_611 == V_607 )
return V_608 ;
}
V_198 -> V_604 = V_198 -> V_604 ? : V_605 ;
V_198 = ( void * ) V_198 + V_198 -> V_604 ;
}
return NULL ;
}
static void F_172 ( struct V_612 * V_613 ,
struct V_598 * V_614 )
{
V_613 -> V_615 = F_22 ( V_614 -> V_616 ) ;
V_613 -> V_617 = F_22 ( V_614 -> V_618 ) ;
V_613 -> V_619 = F_22 ( V_614 -> V_620 ) ;
V_613 -> V_621 = F_22 ( V_614 -> V_622 ) ;
V_613 -> V_623 = F_22 ( V_614 -> V_624 ) ;
V_613 -> V_625 = F_22 ( V_614 -> V_626 ) ;
V_613 -> V_627 = F_22 ( V_614 -> V_628 ) ;
V_613 -> V_629 = F_8 ( V_614 -> V_295 ) &
V_630 ;
if ( V_613 -> V_623 && V_613 -> V_623 == V_613 -> V_625 )
V_613 -> V_623 -= 1 ;
}
int F_173 ( struct V_1 * V_2 , struct V_612 * V_613 )
{
struct V_11 * V_12 ;
struct V_631 * V_194 ;
int V_35 ;
struct V_127 V_431 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
memset ( & V_431 , 0 , sizeof( struct V_127 ) ) ;
V_431 . V_177 = sizeof( struct V_632 ) ;
V_431 . V_131 = F_119 ( V_2 -> V_61 , V_431 . V_177 ,
& V_431 . V_133 ) ;
if ( ! V_431 . V_131 ) {
F_16 ( & V_2 -> V_61 -> V_62 , L_18 ) ;
V_35 = - V_342 ;
goto V_149;
}
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = V_431 . V_131 ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_633 ,
V_431 . V_177 , V_12 , & V_431 ) ;
if ( F_133 ( V_2 ) )
V_194 -> V_198 . V_169 = 1 ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_632 * V_52 = V_431 . V_131 ;
T_2 V_599 = F_8 ( V_52 -> V_599 ) ;
struct V_598 * V_614 ;
V_614 = F_170 ( V_52 -> V_634 , V_599 ) ;
if ( ! V_614 ) {
V_35 = - V_635 ;
goto V_149;
}
V_2 -> V_636 = V_614 -> V_611 ;
F_172 ( V_613 , V_614 ) ;
}
V_149:
F_83 ( & V_2 -> V_188 ) ;
if ( V_431 . V_131 )
F_120 ( V_2 -> V_61 , V_431 . V_177 , V_431 . V_131 , V_431 . V_133 ) ;
return V_35 ;
}
static int F_174 ( struct V_1 * V_2 ,
T_1 V_219 , struct V_127 * V_431 )
{
struct V_11 * V_12 ;
struct V_637 * V_194 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_194 = V_431 -> V_131 ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_638 ,
V_431 -> V_177 , V_12 , V_431 ) ;
V_194 -> type = V_639 ;
V_194 -> V_198 . V_219 = V_219 ;
if ( ! F_18 ( V_2 ) )
V_194 -> V_198 . V_169 = 1 ;
V_35 = F_54 ( V_2 ) ;
F_83 ( & V_2 -> V_188 ) ;
return V_35 ;
}
static int F_175 ( struct V_1 * V_2 ,
T_1 V_219 , struct V_127 * V_431 )
{
struct V_11 * V_12 ;
struct V_637 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = V_431 -> V_131 ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_638 ,
V_431 -> V_177 , V_12 , V_431 ) ;
V_194 -> type = V_639 ;
V_194 -> V_198 . V_219 = V_219 ;
if ( ! F_18 ( V_2 ) )
V_194 -> V_198 . V_169 = 1 ;
V_35 = F_47 ( V_2 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_176 ( struct V_1 * V_2 ,
struct V_612 * V_613 , T_1 V_219 )
{
struct V_640 * V_52 ;
struct V_606 * V_608 ;
struct V_598 * V_641 ;
struct V_14 * V_15 = & V_2 -> V_16 . V_17 ;
struct V_127 V_431 ;
T_2 V_599 ;
int V_35 ;
memset ( & V_431 , 0 , sizeof( struct V_127 ) ) ;
V_431 . V_177 = sizeof( struct V_640 ) ;
V_431 . V_131 = F_119 ( V_2 -> V_61 , V_431 . V_177 , & V_431 . V_133 ) ;
if ( ! V_431 . V_131 )
return - V_342 ;
if ( ! V_15 -> V_186 )
V_35 = F_174 ( V_2 , V_219 , & V_431 ) ;
else
V_35 = F_175 ( V_2 , V_219 , & V_431 ) ;
if ( V_35 )
goto V_149;
V_52 = V_431 . V_131 ;
V_599 = F_8 ( V_52 -> V_599 ) ;
V_608 = F_171 ( V_2 -> V_61 -> V_607 , V_52 -> V_634 ,
V_599 ) ;
if ( V_608 )
V_613 -> V_642 = F_22 ( V_608 -> V_643 ) ;
V_641 = F_170 ( V_52 -> V_634 , V_599 ) ;
if ( V_641 )
F_172 ( V_613 , V_641 ) ;
V_149:
if ( V_431 . V_131 )
F_120 ( V_2 -> V_61 , V_431 . V_177 , V_431 . V_131 , V_431 . V_133 ) ;
return V_35 ;
}
int F_177 ( struct V_1 * V_2 , T_2 V_506 ,
T_1 V_219 )
{
struct V_11 * V_12 ;
struct V_644 * V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_645 , sizeof( * V_194 ) ,
V_12 , NULL ) ;
V_194 -> V_198 . V_219 = V_219 ;
V_194 -> V_599 = F_69 ( 1 ) ;
V_194 -> V_646 . V_198 . V_601 = V_602 ;
V_194 -> V_646 . V_198 . V_604 = V_605 ;
V_194 -> V_646 . V_26 = ( 1 << V_647 ) | ( 1 << V_648 ) | ( 1 << V_649 ) ;
V_194 -> V_646 . V_611 = V_2 -> V_636 ;
V_194 -> V_646 . V_650 = V_219 ;
V_194 -> V_646 . V_616 = 0xFFFF ;
V_194 -> V_646 . V_651 = 0xFFFF ;
V_194 -> V_646 . V_618 = 0xFFFF ;
V_194 -> V_646 . V_620 = 0xFFFF ;
V_194 -> V_646 . V_622 = 0xFFFF ;
V_194 -> V_646 . V_626 = 0xFFFF ;
V_194 -> V_646 . V_624 = 0xFFFF ;
V_194 -> V_646 . V_652 = 0xFFFF ;
V_194 -> V_646 . V_653 = 0xFFFF ;
V_194 -> V_646 . V_654 = 0xFFFF ;
V_194 -> V_646 . V_628 = 0xFFFF ;
V_194 -> V_646 . V_655 = 0xFF ;
V_194 -> V_646 . V_656 = 0xFFFFFFFF ;
V_194 -> V_646 . V_657 = 0xFF ;
V_194 -> V_646 . V_658 = 0x0F ;
V_194 -> V_646 . V_656 = F_69 ( V_506 ) ;
V_194 -> V_646 . V_659 = F_69 ( V_506 ) ;
V_35 = F_47 ( V_2 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_178 ( struct V_1 * V_2 , struct V_660 * V_661 ,
int V_650 )
{
struct V_11 * V_12 ;
struct V_662 * V_194 ;
struct V_663 * V_52 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_664 , sizeof( * V_52 ) ,
V_12 , NULL ) ;
V_194 -> V_198 . V_219 = V_650 + 1 ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
V_52 = (struct V_663 * ) V_194 ;
V_661 -> V_210 = F_8 ( V_52 -> V_665 . V_215 ) ;
}
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
static int F_179 ( struct V_1 * V_2 )
{
#define F_180 30
T_2 V_666 ;
int V_35 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < F_180 ; V_5 ++ ) {
V_666 = F_51 ( V_2 -> V_22 + V_667 ) ;
if ( ( V_666 & V_668 ) == 0 )
break;
F_181 ( 1 ) ;
}
if ( V_5 == F_180 )
V_35 = - 1 ;
return V_35 ;
}
int F_182 ( struct V_1 * V_2 , T_2 V_669 )
{
int V_35 = 0 ;
V_35 = F_179 ( V_2 ) ;
if ( V_35 )
return V_35 ;
F_6 ( V_669 , V_2 -> V_22 + V_667 ) ;
return V_35 ;
}
bool F_183 ( struct V_1 * V_2 )
{
T_2 V_139 = 0 ;
V_139 = F_51 ( V_2 -> V_22 + V_140 ) ;
return ! ! ( V_139 & V_670 ) ;
}
int F_184 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_182 ( V_2 , V_671 |
V_672 ) ;
if ( V_35 < 0 ) {
F_16 ( & V_2 -> V_61 -> V_62 , L_22 ) ;
return V_35 ;
}
V_35 = F_179 ( V_2 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_183 ( V_2 ) ) {
F_16 ( & V_2 -> V_61 -> V_62 , L_23 ) ;
return - 1 ;
}
return 0 ;
}
int F_185 ( struct V_1 * V_2 , T_1 V_219 )
{
struct V_11 * V_12 ;
struct V_673 * V_194 ;
int V_35 ;
if ( F_57 ( V_2 ) )
return 0 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_674 , sizeof( * V_194 ) ,
V_12 , NULL ) ;
V_194 -> V_198 . V_219 = V_219 ;
V_194 -> V_473 = 1 ;
V_35 = F_47 ( V_2 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
int F_186 ( struct V_1 * V_2 , bool V_675 )
{
struct V_11 * V_12 ;
struct V_676 * V_194 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_188 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_194 = F_2 ( V_12 ) ;
F_68 ( & V_194 -> V_198 , V_43 ,
V_677 , sizeof( * V_194 ) ,
V_12 , NULL ) ;
V_194 -> V_678 = V_675 ;
V_35 = F_54 ( V_2 ) ;
F_83 ( & V_2 -> V_188 ) ;
return V_35 ;
}
int F_187 ( void * V_679 , void * V_680 ,
int V_681 , T_3 * V_682 , T_3 * V_683 )
{
struct V_1 * V_2 = F_188 ( V_679 ) ;
struct V_11 * V_12 ;
struct V_163 * V_198 = (struct V_163 * ) V_680 ;
struct V_163 * V_194 ;
struct V_28 * V_52 ;
int V_35 ;
F_33 ( & V_2 -> V_187 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_190 ;
goto V_149;
}
V_194 = F_2 ( V_12 ) ;
V_52 = F_2 ( V_12 ) ;
F_68 ( V_194 , V_198 -> V_4 ,
V_198 -> V_3 , V_681 , V_12 , NULL ) ;
memcpy ( V_194 , V_680 , V_681 ) ;
F_70 ( V_194 , V_681 ) ;
V_35 = F_47 ( V_2 ) ;
if ( V_682 )
* V_682 = ( V_35 & 0xffff ) ;
if ( V_683 )
* V_683 = 0 ;
memcpy ( V_680 , V_52 , sizeof( * V_52 ) + V_52 -> V_583 ) ;
F_12 ( V_680 , sizeof( * V_52 ) + V_52 -> V_583 ) ;
V_149:
F_35 ( & V_2 -> V_187 ) ;
return V_35 ;
}
