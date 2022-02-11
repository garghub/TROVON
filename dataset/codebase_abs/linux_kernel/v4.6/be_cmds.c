static bool F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
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
static int F_3 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 . V_17 ;
T_2 V_18 = 0 ;
if ( F_4 ( V_2 , V_19 ) )
return - V_20 ;
V_18 |= V_15 -> V_21 & V_22 ;
V_18 |= 1 << V_23 ;
F_5 () ;
F_6 ( V_18 , V_2 -> V_24 + V_25 ) ;
return 0 ;
}
static inline bool F_7 ( struct V_26 * V_27 )
{
T_2 V_28 ;
if ( V_27 -> V_28 != 0 ) {
V_28 = F_8 ( V_27 -> V_28 ) ;
if ( V_28 & V_29 ) {
V_27 -> V_28 = V_28 ;
return true ;
}
}
return false ;
}
static inline void F_9 ( struct V_26 * V_27 )
{
V_27 -> V_28 = 0 ;
}
static struct V_30 * F_10 ( T_2 V_31 , T_2 V_32 )
{
unsigned long V_33 ;
V_33 = V_32 ;
V_33 = ( ( V_33 << 16 ) << 16 ) | V_31 ;
return ( void * ) V_33 ;
}
static bool F_11 ( T_1 V_3 , T_3 V_34 , T_3 V_35 )
{
if ( V_34 == V_36 ||
V_34 == V_37 ||
V_35 == V_38 ||
V_35 == V_39 ||
( V_3 == V_40 &&
( V_34 == V_41 ||
V_35 == V_42 ) ) )
return true ;
else
return false ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
struct V_30 * V_43 )
{
enum V_44 V_34 = V_34 ( V_27 -> V_45 ) ;
T_1 V_3 = 0 , V_4 = 0 ;
if ( V_43 ) {
V_3 = V_43 -> V_3 ;
V_4 = V_43 -> V_4 ;
}
if ( V_3 == V_46 &&
V_4 == V_47 ) {
F_13 ( & V_2 -> V_48 ) ;
return;
}
if ( V_3 == V_49 &&
V_4 == V_47 ) {
F_13 ( & V_2 -> V_48 ) ;
return;
}
if ( ( V_3 == V_40 ||
V_3 == V_50 ) &&
V_4 == V_51 ) {
V_2 -> V_52 = V_27 -> V_45 ;
F_13 ( & V_2 -> V_48 ) ;
return;
}
if ( ( V_3 == V_53 ||
V_3 == V_54 ) &&
V_4 == V_55 &&
V_34 == V_56 ) {
F_14 ( V_2 ) ;
V_2 -> V_57 = false ;
return;
}
if ( V_3 == V_58 &&
V_4 == V_51 ) {
if ( V_34 == V_56 ) {
struct V_59 * V_60 =
( void * ) V_43 ;
V_2 -> V_61 . V_62 =
V_60 -> V_63 ;
} else {
V_2 -> V_64 = 0 ;
V_2 -> V_61 . V_62 =
V_65 ;
}
return;
}
}
static int F_15 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
enum V_44 V_34 ;
enum V_66 V_35 ;
struct V_30 * V_43 ;
T_1 V_3 = 0 , V_4 = 0 ;
F_16 ( V_27 , 4 ) ;
V_34 = V_34 ( V_27 -> V_45 ) ;
V_35 = V_35 ( V_27 -> V_45 ) ;
V_43 = F_10 ( V_27 -> V_31 , V_27 -> V_32 ) ;
if ( V_43 ) {
V_3 = V_43 -> V_3 ;
V_4 = V_43 -> V_4 ;
}
F_12 ( V_2 , V_27 , V_43 ) ;
if ( V_34 != V_56 &&
! F_11 ( V_3 , V_34 , V_35 ) ) {
if ( V_34 == V_67 ||
V_35 == V_68 ) {
F_17 ( & V_2 -> V_69 -> V_70 ,
L_1 ,
V_3 , V_4 ) ;
} else {
F_18 ( & V_2 -> V_69 -> V_70 ,
L_2 ,
V_3 , V_4 , V_34 , V_35 ) ;
}
}
return V_27 -> V_45 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_71 * V_72 =
(struct V_71 * ) V_27 ;
V_2 -> V_73 . V_74 = - 1 ;
if ( ! F_20 ( V_2 ) &&
! ( V_72 -> V_75 & V_76 ) )
return;
if ( V_2 -> V_28 & V_77 )
F_21 ( V_2 ,
V_72 -> V_75 & V_78 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_79 * V_72 =
(struct V_79 * ) V_27 ;
T_2 V_80 = F_8 ( V_72 -> V_81 ) ;
T_2 V_82 = F_8 ( V_72 -> V_83 ) ;
T_1 V_84 = V_85 ;
struct V_86 * V_70 = & V_2 -> V_69 -> V_70 ;
T_1 V_87 = V_88 ;
T_1 V_89 ;
T_1 V_90 ;
V_90 =
( V_80 >> ( V_2 -> V_91 * 8 ) ) & 0xff ;
if ( V_90 == V_2 -> V_92 )
return;
V_2 -> V_92 = V_90 ;
if ( ! V_82 )
goto V_93;
V_89 =
( V_82 >> ( V_2 -> V_91 * 8 ) ) & 0xff ;
if ( V_89 & V_94 ) {
V_87 = ( V_89 & V_95 ) >> 1 ;
if ( F_23 ( V_90 ) )
V_84 = ( V_89 & V_96 ) ;
}
V_93:
if ( F_24 ( V_90 ) )
F_25 ( V_97 [ V_87 ] , V_70 ,
L_3 ,
V_2 -> V_98 ,
V_90 ,
V_99 [ V_84 ] ) ;
else
F_25 ( V_97 [ V_87 ] , V_70 ,
L_4 ,
V_2 -> V_98 ,
V_100 [ V_90 ] ,
V_99 [ V_84 ] ) ;
if ( F_26 ( V_90 ) )
V_2 -> V_28 |= V_101 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_102 * V_72 =
(struct V_102 * ) V_27 ;
if ( V_72 -> V_103 ) {
V_2 -> V_104 = V_72 -> V_105 ;
V_2 -> V_106 =
V_72 -> V_107 << V_108 ;
}
}
static void F_28 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_109 * V_72 =
(struct V_109 * ) V_27 ;
if ( V_2 -> V_73 . V_74 >= 0 &&
V_72 -> V_110 == V_2 -> V_111 )
V_2 -> V_73 . V_74 = F_29 ( V_72 -> V_112 ) * 10 ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_113 * V_72 =
(struct V_113 * ) V_27 ;
if ( V_72 -> V_114 ) {
V_2 -> V_115 = F_29 ( V_72 -> V_116 ) & V_117 ;
F_31 ( & V_2 -> V_69 -> V_70 , L_5 , V_2 -> V_115 ) ;
} else {
V_2 -> V_115 = 0 ;
}
}
static void F_32 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_118 * V_72 = (struct V_118 * ) V_27 ;
T_2 V_119 = F_8 ( V_72 -> V_81 ) ;
if ( V_119 & V_120 ) {
V_2 -> V_28 |= V_121 ;
V_2 -> V_122 = F_8 ( V_72 -> V_83 ) ;
} else {
V_2 -> V_28 &= ~ V_121 ;
}
}
static void F_33 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
T_1 V_123 = ( V_27 -> V_28 >> V_124 ) &
V_125 ;
switch ( V_123 ) {
case V_126 :
F_27 ( V_2 , V_27 ) ;
break;
case V_127 :
F_28 ( V_2 , V_27 ) ;
break;
case V_128 :
F_30 ( V_2 , V_27 ) ;
break;
case V_129 :
F_32 ( V_2 , V_27 ) ;
break;
default:
break;
}
}
static void F_34 ( struct V_1 * V_2 ,
struct V_26 * V_130 )
{
T_1 V_123 = 0 ;
struct V_131 * V_72 = (struct V_131 * ) V_130 ;
V_123 = ( V_130 -> V_28 >> V_124 ) &
V_125 ;
switch ( V_123 ) {
case V_132 :
if ( V_72 -> V_103 )
V_2 -> V_133 = F_29 ( V_72 -> V_134 ) ;
V_2 -> V_28 |= V_135 ;
break;
default:
F_17 ( & V_2 -> V_69 -> V_70 , L_6 ,
V_123 ) ;
break;
}
}
static void F_35 ( struct V_1 * V_2 ,
struct V_26 * V_130 )
{
T_1 V_123 = ( V_130 -> V_28 >> V_124 ) &
V_125 ;
if ( V_123 == V_136 )
F_22 ( V_2 , V_130 ) ;
}
static inline bool F_36 ( T_2 V_28 )
{
return ( ( V_28 >> V_137 ) & V_138 ) ==
V_139 ;
}
static inline bool F_37 ( T_2 V_28 )
{
return ( ( V_28 >> V_137 ) & V_138 ) ==
V_140 ;
}
static inline bool F_38 ( T_2 V_28 )
{
return ( ( V_28 >> V_137 ) & V_138 ) ==
V_141 ;
}
static inline bool F_39 ( T_2 V_28 )
{
return ( ( V_28 >> V_137 ) & V_138 ) ==
V_142 ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
if ( F_36 ( V_27 -> V_28 ) )
F_19 ( V_2 , V_27 ) ;
else if ( F_37 ( V_27 -> V_28 ) )
F_33 ( V_2 , V_27 ) ;
else if ( F_38 ( V_27 -> V_28 ) )
F_34 ( V_2 , V_27 ) ;
else if ( F_39 ( V_27 -> V_28 ) )
F_35 ( V_2 , V_27 ) ;
}
static struct V_26 * F_41 ( struct V_1 * V_2 )
{
struct V_14 * V_143 = & V_2 -> V_16 . V_144 ;
struct V_26 * V_27 = F_42 ( V_143 ) ;
if ( F_7 ( V_27 ) ) {
F_43 ( V_143 ) ;
return V_27 ;
}
return NULL ;
}
void F_44 ( struct V_1 * V_2 )
{
F_45 ( & V_2 -> V_145 ) ;
F_46 ( V_2 , V_2 -> V_16 . V_144 . V_21 , true , 0 ) ;
V_2 -> V_16 . V_146 = true ;
F_47 ( & V_2 -> V_145 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
F_45 ( & V_2 -> V_145 ) ;
V_2 -> V_16 . V_146 = false ;
F_46 ( V_2 , V_2 -> V_16 . V_144 . V_21 , false , 0 ) ;
F_47 ( & V_2 -> V_145 ) ;
}
int F_49 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
int V_147 = 0 , V_45 = 0 ;
struct V_148 * V_16 = & V_2 -> V_16 ;
F_50 ( & V_2 -> V_145 ) ;
while ( ( V_27 = F_41 ( V_2 ) ) ) {
if ( V_27 -> V_28 & V_149 ) {
F_40 ( V_2 , V_27 ) ;
} else if ( V_27 -> V_28 & V_150 ) {
V_45 = F_15 ( V_2 , V_27 ) ;
F_51 ( & V_16 -> V_17 . V_151 ) ;
}
F_9 ( V_27 ) ;
V_147 ++ ;
}
if ( V_147 )
F_46 ( V_2 , V_16 -> V_144 . V_21 , V_16 -> V_146 , V_147 ) ;
F_52 ( & V_2 -> V_145 ) ;
return V_45 ;
}
static int F_53 ( struct V_1 * V_2 )
{
#define F_54 120000
int V_5 , V_45 = 0 ;
struct V_148 * V_16 = & V_2 -> V_16 ;
for ( V_5 = 0 ; V_5 < F_54 ; V_5 ++ ) {
if ( F_4 ( V_2 , V_19 ) )
return - V_20 ;
F_55 () ;
V_45 = F_49 ( V_2 ) ;
F_56 () ;
if ( F_57 ( & V_16 -> V_17 . V_151 ) == 0 )
break;
F_58 ( 100 ) ;
}
if ( V_5 == F_54 ) {
F_18 ( & V_2 -> V_69 -> V_70 , L_7 ) ;
F_59 ( V_2 , V_152 ) ;
return - V_20 ;
}
return V_45 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_45 ;
struct V_11 * V_12 ;
struct V_148 * V_16 = & V_2 -> V_16 ;
T_2 V_153 = V_16 -> V_17 . V_154 ;
struct V_30 * V_60 ;
F_61 ( & V_153 , V_16 -> V_17 . V_155 ) ;
V_12 = F_62 ( & V_16 -> V_17 , V_153 ) ;
V_60 = F_10 ( V_12 -> V_31 , V_12 -> V_32 ) ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_156;
V_45 = F_53 ( V_2 ) ;
if ( V_45 == - V_20 )
goto V_156;
V_45 = ( V_60 -> V_34 |
( ( V_60 -> V_35 & V_157 ) <<
V_158 ) ) ;
V_156:
return V_45 ;
}
static int F_63 ( struct V_1 * V_2 , void T_4 * V_24 )
{
int V_159 = 0 ;
T_2 V_160 ;
do {
if ( F_4 ( V_2 , V_19 ) )
return - V_20 ;
V_160 = F_64 ( V_24 ) ;
if ( V_160 == 0xffffffff )
return - 1 ;
V_160 &= V_161 ;
if ( V_160 )
break;
if ( V_159 > 4000 ) {
F_18 ( & V_2 -> V_69 -> V_70 , L_7 ) ;
F_59 ( V_2 , V_152 ) ;
F_65 ( V_2 ) ;
return - 1 ;
}
F_66 ( 1 ) ;
V_159 ++ ;
} while ( true );
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_45 ;
T_2 V_18 = 0 ;
void T_4 * V_24 = V_2 -> V_24 + V_162 ;
struct V_163 * V_164 = & V_2 -> V_164 ;
struct V_165 * V_166 = V_164 -> V_167 ;
struct V_26 * V_27 = & V_166 -> V_27 ;
V_45 = F_63 ( V_2 , V_24 ) ;
if ( V_45 != 0 )
return V_45 ;
V_18 |= V_168 ;
V_18 |= ( F_68 ( V_164 -> V_169 ) >> 2 ) << 2 ;
F_6 ( V_18 , V_24 ) ;
V_45 = F_63 ( V_2 , V_24 ) ;
if ( V_45 != 0 )
return V_45 ;
V_18 = 0 ;
V_18 |= ( T_2 ) ( V_164 -> V_169 >> 4 ) << 2 ;
F_6 ( V_18 , V_24 ) ;
V_45 = F_63 ( V_2 , V_24 ) ;
if ( V_45 != 0 )
return V_45 ;
if ( F_7 ( V_27 ) ) {
V_45 = F_15 ( V_2 , & V_166 -> V_27 ) ;
F_9 ( V_27 ) ;
if ( V_45 )
return V_45 ;
} else {
F_18 ( & V_2 -> V_69 -> V_70 , L_8 ) ;
return - 1 ;
}
return 0 ;
}
static T_3 F_69 ( struct V_1 * V_2 )
{
T_2 V_170 ;
if ( F_20 ( V_2 ) )
V_170 = F_64 ( V_2 -> V_171 + V_172 ) ;
else
F_70 ( V_2 -> V_69 ,
V_173 , & V_170 ) ;
return V_170 & V_174 ;
}
static int F_71 ( struct V_1 * V_2 )
{
#define F_72 30
T_2 V_175 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_72 ; V_5 ++ ) {
V_175 = F_64 ( V_2 -> V_24 + V_176 ) ;
if ( V_175 & V_177 )
return 0 ;
if ( V_175 & V_178 &&
! ( V_175 & V_179 ) )
return - V_20 ;
F_66 ( 1000 ) ;
}
return V_175 ? : - 1 ;
}
int F_73 ( struct V_1 * V_2 )
{
T_3 V_180 ;
int V_45 , V_181 = 0 ;
struct V_86 * V_70 = & V_2 -> V_69 -> V_70 ;
if ( F_74 ( V_2 ) ) {
V_45 = F_71 ( V_2 ) ;
if ( V_45 ) {
V_180 = V_45 ;
goto V_182;
}
return 0 ;
}
do {
if ( F_20 ( V_2 ) && F_75 ( V_2 ) )
return 0 ;
V_180 = F_69 ( V_2 ) ;
if ( V_180 == V_183 )
return 0 ;
F_31 ( V_70 , L_9 , V_181 ) ;
if ( F_76 ( 2000 ) ) {
F_18 ( V_70 , L_10 ) ;
return - V_184 ;
}
V_181 += 2 ;
} while ( V_181 < 60 );
V_182:
F_18 ( V_70 , L_11 , V_180 ) ;
return - V_185 ;
}
static inline struct V_186 * F_77 ( struct V_11 * V_12 )
{
return & V_12 -> V_13 . V_187 [ 0 ] ;
}
static inline void F_78 ( struct V_11 * V_12 , unsigned long V_33 )
{
V_12 -> V_31 = V_33 & 0xFFFFFFFF ;
V_12 -> V_32 = F_68 ( V_33 ) ;
}
static void F_79 ( struct V_188 * V_189 ,
T_1 V_4 , T_1 V_3 , int V_190 ,
struct V_11 * V_12 ,
struct V_163 * V_191 )
{
struct V_186 * V_192 ;
V_189 -> V_3 = V_3 ;
V_189 -> V_4 = V_4 ;
V_189 -> V_193 = F_80 ( V_190 - sizeof( * V_189 ) ) ;
V_189 -> V_194 = 0 ;
F_78 ( V_12 , ( V_195 ) V_189 ) ;
V_12 -> V_196 = V_190 ;
if ( V_191 ) {
V_12 -> V_197 |= ( 1 & V_198 ) <<
V_199 ;
V_192 = F_77 ( V_12 ) ;
V_192 -> V_200 = F_80 ( F_68 ( V_191 -> V_169 ) ) ;
V_192 -> V_201 = F_80 ( V_191 -> V_169 & 0xFFFFFFFF ) ;
V_192 -> V_155 = F_80 ( V_191 -> V_202 ) ;
} else
V_12 -> V_197 |= V_203 ;
F_81 ( V_12 , 8 ) ;
}
static void F_82 ( struct V_204 * V_205 , T_2 V_206 ,
struct V_163 * V_191 )
{
int V_5 , V_207 = F_83 ( F_84 ( V_191 -> V_167 , V_191 -> V_202 ) , V_206 ) ;
T_5 V_169 = ( T_5 ) V_191 -> V_169 ;
for ( V_5 = 0 ; V_5 < V_207 ; V_5 ++ ) {
V_205 [ V_5 ] . V_208 = F_80 ( V_169 & 0xFFFFFFFF ) ;
V_205 [ V_5 ] . V_209 = F_80 ( F_68 ( V_169 ) ) ;
V_169 += V_210 ;
}
}
static inline struct V_11 * F_85 ( struct V_1 * V_2 )
{
struct V_163 * V_164 = & V_2 -> V_164 ;
struct V_11 * V_12
= & ( (struct V_165 * ) ( V_164 -> V_167 ) ) -> V_12 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
static struct V_11 * F_86 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 . V_17 ;
struct V_11 * V_12 ;
if ( ! V_15 -> V_211 )
return NULL ;
if ( F_57 ( & V_15 -> V_151 ) >= V_15 -> V_155 )
return NULL ;
V_12 = F_87 ( V_15 ) ;
F_88 ( V_15 ) ;
F_89 ( & V_15 -> V_151 ) ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
static bool F_90 ( struct V_1 * V_2 )
{
return V_2 -> V_16 . V_17 . V_211 ;
}
static int F_91 ( struct V_1 * V_2 )
{
if ( F_90 ( V_2 ) ) {
F_45 ( & V_2 -> V_212 ) ;
return 0 ;
} else {
return F_92 ( & V_2 -> V_213 ) ;
}
}
static void F_93 ( struct V_1 * V_2 )
{
if ( F_90 ( V_2 ) )
F_47 ( & V_2 -> V_212 ) ;
else
return F_94 ( & V_2 -> V_213 ) ;
}
static struct V_11 * F_95 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_214 ;
if ( F_90 ( V_2 ) ) {
V_214 = F_86 ( V_2 ) ;
if ( ! V_214 )
return NULL ;
} else {
V_214 = F_85 ( V_2 ) ;
}
memcpy ( V_214 , V_12 , sizeof( * V_12 ) ) ;
if ( V_12 -> V_197 & F_80 ( V_203 ) )
F_78 ( V_214 , ( V_195 ) F_2 ( V_12 ) ) ;
return V_214 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_214 ;
int V_45 ;
V_45 = F_91 ( V_2 ) ;
if ( V_45 )
return V_45 ;
V_214 = F_95 ( V_2 , V_12 ) ;
if ( ! V_214 ) {
V_45 = - V_215 ;
goto V_216;
}
if ( F_90 ( V_2 ) )
V_45 = F_60 ( V_2 ) ;
else
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 )
memcpy ( V_12 , V_214 , sizeof( * V_12 ) ) ;
V_216:
F_93 ( V_2 ) ;
return V_45 ;
}
int F_97 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_45 ;
if ( F_74 ( V_2 ) )
return 0 ;
if ( F_92 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = ( T_1 * ) F_85 ( V_2 ) ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0x12 ;
* V_12 ++ = 0x34 ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0x56 ;
* V_12 ++ = 0x78 ;
* V_12 = 0xFF ;
V_45 = F_67 ( V_2 ) ;
F_94 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_98 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_45 ;
if ( F_74 ( V_2 ) )
return 0 ;
if ( F_92 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = ( T_1 * ) F_85 ( V_2 ) ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xAA ;
* V_12 ++ = 0xBB ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xCC ;
* V_12 ++ = 0xDD ;
* V_12 = 0xFF ;
V_45 = F_67 ( V_2 ) ;
F_94 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_99 ( struct V_1 * V_2 , struct V_217 * V_218 )
{
struct V_11 * V_12 ;
struct V_219 * V_220 ;
struct V_163 * V_221 = & V_218 -> V_17 . V_222 ;
int V_45 , V_223 = 0 ;
if ( F_92 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_225 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
if ( ! ( F_20 ( V_2 ) || F_74 ( V_2 ) ) )
V_223 = 2 ;
V_220 -> V_224 . V_194 = V_223 ;
V_220 -> V_226 = F_100 ( F_84 ( V_221 -> V_167 , V_221 -> V_202 ) ) ;
F_101 ( struct V_227 , V_103 , V_220 -> V_228 , 1 ) ;
F_101 ( struct V_227 , V_202 , V_220 -> V_228 , 0 ) ;
F_101 ( struct V_227 , V_229 , V_220 -> V_228 ,
F_102 ( V_218 -> V_17 . V_155 / 256 ) ) ;
F_81 ( V_220 -> V_228 , sizeof( V_220 -> V_228 ) ) ;
F_82 ( V_220 -> V_205 , F_103 ( V_220 -> V_205 ) , V_221 ) ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_230 * V_60 = F_2 ( V_12 ) ;
V_218 -> V_17 . V_21 = F_29 ( V_60 -> V_231 ) ;
V_218 -> V_232 =
( V_223 == 2 ) ? F_29 ( V_60 -> V_232 ) : V_218 -> V_233 ;
V_218 -> V_17 . V_211 = true ;
}
F_94 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_104 ( struct V_1 * V_2 , T_1 * V_234 ,
bool V_235 , T_2 V_236 , T_2 V_237 )
{
struct V_11 * V_12 ;
struct V_238 * V_220 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_239 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_220 -> type = V_240 ;
if ( V_235 ) {
V_220 -> V_235 = 1 ;
} else {
V_220 -> V_241 = F_100 ( ( T_3 ) V_236 ) ;
V_220 -> V_237 = F_80 ( V_237 ) ;
V_220 -> V_235 = 0 ;
}
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_242 * V_60 = F_2 ( V_12 ) ;
memcpy ( V_234 , V_60 -> V_243 . V_33 , V_244 ) ;
}
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_105 ( struct V_1 * V_2 , T_1 * V_234 ,
T_2 V_241 , T_2 * V_237 , T_2 V_245 )
{
struct V_11 * V_12 ;
struct V_246 * V_220 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_247 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_220 -> V_224 . V_245 = V_245 ;
V_220 -> V_241 = F_80 ( V_241 ) ;
memcpy ( V_220 -> V_248 , V_234 , V_244 ) ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_249 * V_60 = F_2 ( V_12 ) ;
* V_237 = F_8 ( V_60 -> V_237 ) ;
}
V_182:
F_47 ( & V_2 -> V_212 ) ;
if ( V_45 == V_67 )
V_45 = - V_250 ;
return V_45 ;
}
int F_106 ( struct V_1 * V_2 , T_2 V_241 , int V_237 , T_2 V_251 )
{
struct V_11 * V_12 ;
struct V_252 * V_220 ;
int V_45 ;
if ( V_237 == - 1 )
return 0 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_253 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_224 . V_245 = V_251 ;
V_220 -> V_241 = F_80 ( V_241 ) ;
V_220 -> V_237 = F_80 ( V_237 ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_107 ( struct V_1 * V_2 , struct V_14 * V_144 ,
struct V_14 * V_254 , bool V_255 , int V_256 )
{
struct V_11 * V_12 ;
struct V_257 * V_220 ;
struct V_163 * V_221 = & V_144 -> V_222 ;
void * V_258 ;
int V_45 ;
if ( F_92 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
V_220 = F_2 ( V_12 ) ;
V_258 = & V_220 -> V_228 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_259 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_220 -> V_226 = F_100 ( F_84 ( V_221 -> V_167 , V_221 -> V_202 ) ) ;
if ( F_20 ( V_2 ) ) {
F_101 ( struct V_260 , V_261 , V_258 ,
V_256 ) ;
F_101 ( struct V_260 , V_262 ,
V_258 , V_255 ) ;
F_101 ( struct V_260 , V_229 , V_258 ,
F_102 ( V_144 -> V_155 / 256 ) ) ;
F_101 ( struct V_260 , V_103 , V_258 , 1 ) ;
F_101 ( struct V_260 , V_263 , V_258 , 1 ) ;
F_101 ( struct V_260 , V_264 , V_258 , V_254 -> V_21 ) ;
} else {
V_220 -> V_224 . V_194 = 2 ;
V_220 -> V_265 = 1 ;
if ( ! F_74 ( V_2 ) )
F_101 ( struct V_266 , V_261 ,
V_258 , V_256 ) ;
F_101 ( struct V_266 , V_262 , V_258 ,
V_255 ) ;
F_101 ( struct V_266 , V_229 , V_258 ,
F_102 ( V_144 -> V_155 / 256 ) ) ;
F_101 ( struct V_266 , V_103 , V_258 , 1 ) ;
F_101 ( struct V_266 , V_263 , V_258 , 1 ) ;
F_101 ( struct V_266 , V_264 , V_258 , V_254 -> V_21 ) ;
}
F_81 ( V_258 , sizeof( V_220 -> V_228 ) ) ;
F_82 ( V_220 -> V_205 , F_103 ( V_220 -> V_205 ) , V_221 ) ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_267 * V_60 = F_2 ( V_12 ) ;
V_144 -> V_21 = F_29 ( V_60 -> V_268 ) ;
V_144 -> V_211 = true ;
}
F_94 ( & V_2 -> V_213 ) ;
return V_45 ;
}
static T_2 F_108 ( int V_269 )
{
T_2 V_270 = F_109 ( V_269 ) ;
if ( V_270 == 16 )
V_270 = 0 ;
return V_270 ;
}
static int F_110 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_144 )
{
struct V_11 * V_12 ;
struct V_271 * V_220 ;
struct V_163 * V_221 = & V_15 -> V_222 ;
void * V_258 ;
int V_45 ;
if ( F_92 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
V_220 = F_2 ( V_12 ) ;
V_258 = & V_220 -> V_228 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_272 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_220 -> V_226 = F_100 ( F_84 ( V_221 -> V_167 , V_221 -> V_202 ) ) ;
if ( F_20 ( V_2 ) ) {
F_101 ( struct V_273 , V_103 , V_258 , 1 ) ;
F_101 ( struct V_273 , V_274 , V_258 ,
F_108 ( V_15 -> V_155 ) ) ;
F_101 ( struct V_273 , V_268 , V_258 , V_144 -> V_21 ) ;
} else {
V_220 -> V_224 . V_194 = 1 ;
V_220 -> V_268 = F_100 ( V_144 -> V_21 ) ;
F_101 ( struct V_275 , V_274 , V_258 ,
F_108 ( V_15 -> V_155 ) ) ;
F_101 ( struct V_275 , V_103 , V_258 , 1 ) ;
F_101 ( struct V_275 , V_276 ,
V_258 , V_144 -> V_21 ) ;
F_101 ( struct V_275 , V_277 ,
V_258 , 1 ) ;
}
V_220 -> V_278 [ 0 ] =
F_80 ( F_111 ( V_139 ) |
F_111 ( V_140 ) |
F_111 ( V_141 ) |
F_111 ( V_142 ) ) ;
F_81 ( V_258 , sizeof( V_220 -> V_228 ) ) ;
F_82 ( V_220 -> V_205 , F_103 ( V_220 -> V_205 ) , V_221 ) ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_279 * V_60 = F_2 ( V_12 ) ;
V_15 -> V_21 = F_29 ( V_60 -> V_21 ) ;
V_15 -> V_211 = true ;
}
F_94 ( & V_2 -> V_213 ) ;
return V_45 ;
}
static int F_112 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_144 )
{
struct V_11 * V_12 ;
struct V_280 * V_220 ;
struct V_163 * V_221 = & V_15 -> V_222 ;
void * V_258 ;
int V_45 ;
if ( F_92 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
V_220 = F_2 ( V_12 ) ;
V_258 = & V_220 -> V_228 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_281 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_220 -> V_226 = F_100 ( F_84 ( V_221 -> V_167 , V_221 -> V_202 ) ) ;
F_101 ( struct V_273 , V_103 , V_258 , 1 ) ;
F_101 ( struct V_273 , V_274 , V_258 ,
F_108 ( V_15 -> V_155 ) ) ;
F_101 ( struct V_273 , V_268 , V_258 , V_144 -> V_21 ) ;
F_81 ( V_258 , sizeof( V_220 -> V_228 ) ) ;
F_82 ( V_220 -> V_205 , F_103 ( V_220 -> V_205 ) , V_221 ) ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_279 * V_60 = F_2 ( V_12 ) ;
V_15 -> V_21 = F_29 ( V_60 -> V_21 ) ;
V_15 -> V_211 = true ;
}
F_94 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_113 ( struct V_1 * V_2 ,
struct V_14 * V_15 , struct V_14 * V_144 )
{
int V_45 ;
V_45 = F_110 ( V_2 , V_15 , V_144 ) ;
if ( V_45 && F_20 ( V_2 ) ) {
F_17 ( & V_2 -> V_69 -> V_70 , L_12
L_13
L_14 ) ;
V_45 = F_112 ( V_2 , V_15 , V_144 ) ;
}
return V_45 ;
}
int F_114 ( struct V_1 * V_2 , struct V_282 * V_283 )
{
struct V_11 V_12 = { 0 } ;
struct V_284 * V_220 ;
struct V_14 * V_285 = & V_283 -> V_17 ;
struct V_14 * V_144 = & V_283 -> V_144 ;
struct V_163 * V_221 = & V_285 -> V_222 ;
int V_45 , V_223 = 0 ;
V_220 = F_2 ( & V_12 ) ;
F_79 ( & V_220 -> V_224 , V_55 ,
V_286 , sizeof( * V_220 ) , & V_12 , NULL ) ;
if ( F_74 ( V_2 ) ) {
V_220 -> V_224 . V_194 = 1 ;
} else if ( F_20 ( V_2 ) ) {
if ( V_2 -> V_287 & V_288 )
V_220 -> V_224 . V_194 = 2 ;
} else {
V_220 -> V_224 . V_194 = 2 ;
}
if ( V_220 -> V_224 . V_194 > 0 )
V_220 -> V_241 = F_100 ( V_2 -> V_236 ) ;
V_220 -> V_226 = F_84 ( V_221 -> V_167 , V_221 -> V_202 ) ;
V_220 -> V_289 = V_290 ;
V_220 -> type = V_291 ;
V_220 -> V_268 = F_100 ( V_144 -> V_21 ) ;
V_220 -> V_292 = F_108 ( V_285 -> V_155 ) ;
F_82 ( V_220 -> V_205 , F_103 ( V_220 -> V_205 ) , V_221 ) ;
V_223 = V_220 -> V_224 . V_194 ;
V_45 = F_96 ( V_2 , & V_12 ) ;
if ( ! V_45 ) {
struct V_293 * V_60 = F_2 ( & V_12 ) ;
V_285 -> V_21 = F_29 ( V_60 -> V_294 ) ;
if ( V_223 == 2 )
V_283 -> V_295 = F_8 ( V_60 -> V_295 ) ;
else
V_283 -> V_295 = V_296 ;
V_285 -> V_211 = true ;
}
return V_45 ;
}
int F_115 ( struct V_1 * V_2 ,
struct V_14 * V_297 , T_3 V_268 , T_3 V_298 ,
T_2 V_241 , T_2 V_299 , T_1 * V_300 )
{
struct V_11 * V_12 ;
struct V_301 * V_220 ;
struct V_163 * V_221 = & V_297 -> V_222 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_55 ,
V_302 , sizeof( * V_220 ) , V_12 , NULL ) ;
V_220 -> V_268 = F_100 ( V_268 ) ;
V_220 -> V_298 = F_109 ( V_298 ) - 1 ;
V_220 -> V_226 = 2 ;
F_82 ( V_220 -> V_205 , F_103 ( V_220 -> V_205 ) , V_221 ) ;
V_220 -> V_303 = F_80 ( V_241 ) ;
V_220 -> V_304 = F_100 ( V_305 ) ;
V_220 -> V_306 = F_80 ( V_299 ) ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_307 * V_60 = F_2 ( V_12 ) ;
V_297 -> V_21 = F_29 ( V_60 -> V_21 ) ;
V_297 -> V_211 = true ;
* V_300 = V_60 -> V_300 ;
}
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_116 ( struct V_1 * V_2 , struct V_14 * V_17 ,
int V_308 )
{
struct V_11 * V_12 ;
struct V_309 * V_220 ;
T_1 V_310 = 0 , V_3 = 0 ;
int V_45 ;
if ( F_92 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
V_220 = F_2 ( V_12 ) ;
switch ( V_308 ) {
case V_311 :
V_310 = V_51 ;
V_3 = V_312 ;
break;
case V_313 :
V_310 = V_51 ;
V_3 = V_314 ;
break;
case V_315 :
V_310 = V_55 ;
V_3 = V_316 ;
break;
case V_317 :
V_310 = V_55 ;
V_3 = V_318 ;
break;
case V_319 :
V_310 = V_51 ;
V_3 = V_320 ;
break;
default:
F_117 () ;
}
F_79 ( & V_220 -> V_224 , V_310 , V_3 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_220 -> V_21 = F_100 ( V_17 -> V_21 ) ;
V_45 = F_67 ( V_2 ) ;
V_17 -> V_211 = false ;
F_94 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_118 ( struct V_1 * V_2 , struct V_14 * V_17 )
{
struct V_11 * V_12 ;
struct V_309 * V_220 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_55 ,
V_318 , sizeof( * V_220 ) , V_12 , NULL ) ;
V_220 -> V_21 = F_100 ( V_17 -> V_21 ) ;
V_45 = F_60 ( V_2 ) ;
V_17 -> V_211 = false ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_119 ( struct V_1 * V_2 , T_2 V_321 , T_2 V_322 ,
T_2 * V_236 , T_2 V_245 )
{
struct V_11 V_12 = { 0 } ;
struct V_323 * V_220 ;
int V_45 ;
V_220 = F_2 ( & V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_324 ,
sizeof( * V_220 ) , & V_12 , NULL ) ;
V_220 -> V_224 . V_245 = V_245 ;
V_220 -> V_325 = F_80 ( V_321 ) ;
V_220 -> V_326 = F_80 ( V_322 ) ;
V_220 -> V_327 = true ;
V_45 = F_96 ( V_2 , & V_12 ) ;
if ( ! V_45 ) {
struct V_328 * V_60 = F_2 ( & V_12 ) ;
* V_236 = F_8 ( V_60 -> V_303 ) ;
if ( F_120 ( V_2 ) && F_75 ( V_2 ) )
V_2 -> V_237 [ 0 ] = F_8 ( V_60 -> V_237 ) ;
}
return V_45 ;
}
int F_121 ( struct V_1 * V_2 , int V_303 , T_2 V_245 )
{
struct V_11 V_12 = { 0 } ;
struct V_329 * V_220 ;
int V_45 ;
if ( V_303 == - 1 )
return 0 ;
V_220 = F_2 ( & V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_330 ,
sizeof( * V_220 ) , & V_12 , NULL ) ;
V_220 -> V_224 . V_245 = V_245 ;
V_220 -> V_303 = F_80 ( V_303 ) ;
V_45 = F_96 ( V_2 , & V_12 ) ;
return V_45 ;
}
int F_122 ( struct V_1 * V_2 , struct V_163 * V_331 )
{
struct V_11 * V_12 ;
struct V_188 * V_224 ;
int V_45 = 0 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_224 = V_331 -> V_167 ;
F_79 ( V_224 , V_55 ,
V_53 , V_331 -> V_202 , V_12 ,
V_331 ) ;
if ( F_123 ( V_2 ) )
V_224 -> V_194 = 0 ;
if ( F_120 ( V_2 ) || F_74 ( V_2 ) )
V_224 -> V_194 = 1 ;
else
V_224 -> V_194 = 2 ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_182;
V_2 -> V_57 = true ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_124 ( struct V_1 * V_2 ,
struct V_163 * V_331 )
{
struct V_11 * V_12 ;
struct V_332 * V_220 ;
int V_45 = 0 ;
if ( ! F_1 ( V_2 , V_54 ,
V_55 ) )
return - V_250 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_331 -> V_167 ;
F_79 ( & V_220 -> V_224 , V_55 ,
V_54 , V_331 -> V_202 ,
V_12 , V_331 ) ;
V_220 -> V_333 . V_334 . V_335 = F_100 ( V_2 -> V_91 ) ;
V_220 -> V_333 . V_334 . V_336 = 0 ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_182;
V_2 -> V_57 = true ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
static int F_125 ( int V_337 )
{
switch ( V_337 ) {
case V_338 :
return 0 ;
case V_339 :
return 10 ;
case V_340 :
return 100 ;
case V_341 :
return 1000 ;
case V_342 :
return 10000 ;
case V_343 :
return 20000 ;
case V_344 :
return 25000 ;
case V_345 :
return 40000 ;
}
return 0 ;
}
int F_126 ( struct V_1 * V_2 , T_3 * V_74 ,
T_1 * V_346 , T_2 V_251 )
{
struct V_11 * V_12 ;
struct V_347 * V_220 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
if ( V_346 )
* V_346 = V_348 ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_349 ,
sizeof( * V_220 ) , V_12 , NULL ) ;
if ( ! F_123 ( V_2 ) )
V_220 -> V_224 . V_194 = 1 ;
V_220 -> V_224 . V_245 = V_251 ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_350 * V_60 = F_2 ( V_12 ) ;
if ( V_74 ) {
* V_74 = V_60 -> V_74 ?
F_29 ( V_60 -> V_74 ) * 10 :
F_125 ( V_60 -> V_337 ) ;
if ( ! V_60 -> V_351 )
* V_74 = 0 ;
}
if ( V_346 )
* V_346 = V_60 -> V_351 ;
}
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_127 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_352 * V_220 ;
int V_45 = 0 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_58 ,
sizeof( * V_220 ) , V_12 , NULL ) ;
V_45 = F_3 ( V_2 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_128 ( struct V_1 * V_2 , T_2 * V_353 )
{
struct V_11 V_12 = { 0 } ;
struct V_354 * V_220 ;
int V_45 ;
V_220 = F_2 ( & V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_355 , sizeof( * V_220 ) ,
& V_12 , NULL ) ;
V_220 -> V_356 = F_80 ( V_357 ) ;
V_45 = F_96 ( V_2 , & V_12 ) ;
if ( ! V_45 ) {
struct V_358 * V_60 = F_2 ( & V_12 ) ;
if ( V_353 && V_60 -> V_359 )
* V_353 = F_8 ( V_60 -> V_359 ) -
sizeof( T_2 ) ;
}
return V_45 ;
}
int F_129 ( struct V_1 * V_2 , T_2 V_360 , void * V_361 )
{
struct V_163 V_362 ;
struct V_11 * V_12 ;
struct V_354 * V_220 ;
T_2 V_363 = 0 , V_364 , V_365 ,
V_366 = sizeof( T_2 ) , V_367 ;
int V_45 ;
if ( V_360 == 0 )
return 0 ;
V_364 = V_360 ;
V_362 . V_202 = sizeof( struct V_354 ) + 60 * 1024 ;
V_362 . V_167 = F_130 ( & V_2 -> V_69 -> V_70 ,
V_362 . V_202 ,
& V_362 . V_169 , V_368 ) ;
if ( ! V_362 . V_167 )
return - V_369 ;
F_45 ( & V_2 -> V_212 ) ;
while ( V_364 ) {
V_365 = F_83 ( V_364 , ( T_2 ) 60 * 1024 ) ;
V_364 -= V_365 ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_362 . V_167 ;
V_367 = sizeof( struct V_354 ) + V_365 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_355 , V_367 ,
V_12 , & V_362 ) ;
V_220 -> V_356 = F_80 ( V_370 ) ;
V_220 -> V_371 = F_80 ( V_366 ) ;
V_220 -> V_372 = F_80 ( V_365 ) ;
V_220 -> V_373 = F_80 ( V_365 ) ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_358 * V_60 = V_362 . V_167 ;
memcpy ( V_361 + V_363 ,
V_60 -> V_374 ,
F_8 ( V_60 -> V_372 ) ) ;
} else {
F_18 ( & V_2 -> V_69 -> V_70 , L_15 ) ;
goto V_182;
}
V_363 += V_365 ;
V_366 += V_365 ;
}
V_182:
F_131 ( & V_2 -> V_69 -> V_70 , V_362 . V_202 ,
V_362 . V_167 , V_362 . V_169 ) ;
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_132 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_375 * V_220 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_376 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_377 * V_60 = F_2 ( V_12 ) ;
F_133 ( V_2 -> V_378 , V_60 -> V_379 ,
sizeof( V_2 -> V_378 ) ) ;
F_133 ( V_2 -> V_380 , V_60 -> V_381 ,
sizeof( V_2 -> V_380 ) ) ;
}
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
static int F_134 ( struct V_1 * V_2 ,
struct V_382 * V_383 , int V_147 )
{
struct V_11 * V_12 ;
struct V_384 * V_220 ;
int V_45 = 0 , V_5 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_385 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_220 -> V_386 = F_80 ( V_147 ) ;
for ( V_5 = 0 ; V_5 < V_147 ; V_5 ++ ) {
V_220 -> V_383 [ V_5 ] . V_231 = F_80 ( V_383 [ V_5 ] . V_231 ) ;
V_220 -> V_383 [ V_5 ] . V_387 = 0 ;
V_220 -> V_383 [ V_5 ] . V_388 =
F_80 ( V_383 [ V_5 ] . V_388 ) ;
}
V_45 = F_3 ( V_2 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_135 ( struct V_1 * V_2 , struct V_382 * V_383 ,
int V_147 )
{
int V_389 , V_5 = 0 ;
while ( V_147 ) {
V_389 = F_83 ( V_147 , 8 ) ;
F_134 ( V_2 , & V_383 [ V_5 ] , V_389 ) ;
V_5 += V_389 ;
V_147 -= V_389 ;
}
return 0 ;
}
int F_136 ( struct V_1 * V_2 , T_2 V_241 , T_3 * V_390 ,
T_2 V_147 , T_2 V_245 )
{
struct V_11 * V_12 ;
struct V_391 * V_220 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_392 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_224 . V_245 = V_245 ;
V_220 -> V_303 = V_241 ;
V_220 -> V_393 = V_394 & F_137 ( V_2 ) ? 1 : 0 ;
V_220 -> V_395 = V_147 ;
memcpy ( V_220 -> V_396 , V_390 ,
V_220 -> V_395 * sizeof( V_390 [ 0 ] ) ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
static int F_138 ( struct V_1 * V_2 , T_2 V_28 , T_2 V_397 )
{
struct V_11 * V_12 ;
struct V_163 * V_191 = & V_2 -> V_398 ;
struct V_399 * V_220 = V_191 -> V_167 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
memset ( V_220 , 0 , sizeof( * V_220 ) ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_400 , sizeof( * V_220 ) ,
V_12 , V_191 ) ;
V_220 -> V_241 = F_80 ( V_2 -> V_236 ) ;
V_220 -> V_401 = F_80 ( V_28 ) ;
V_220 -> V_402 = ( V_397 == V_403 ) ? V_220 -> V_401 : 0 ;
if ( V_28 & V_404 ) {
struct V_405 * V_406 ;
int V_5 = 0 ;
V_220 -> V_401 |=
F_80 ( V_407 &
F_137 ( V_2 ) ) ;
V_220 -> V_408 = F_80 ( F_139 ( V_2 -> V_409 ) ) ;
F_140 (ha, adapter->netdev)
memcpy ( V_220 -> V_410 [ V_5 ++ ] . V_411 , V_406 -> V_33 , V_244 ) ;
}
V_45 = F_60 ( V_2 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_141 ( struct V_1 * V_2 , T_2 V_28 , T_2 V_397 )
{
struct V_86 * V_70 = & V_2 -> V_69 -> V_70 ;
if ( ( V_28 & F_137 ( V_2 ) ) != V_28 ) {
F_17 ( V_70 , L_16 , V_28 ) ;
F_17 ( V_70 , L_17 ,
F_137 ( V_2 ) ) ;
}
V_28 &= F_137 ( V_2 ) ;
if ( ! V_28 )
return - V_412 ;
return F_138 ( V_2 , V_28 , V_397 ) ;
}
int F_142 ( struct V_1 * V_2 , T_2 V_413 , T_2 V_414 )
{
struct V_11 * V_12 ;
struct V_415 * V_220 ;
int V_45 ;
if ( ! F_1 ( V_2 , V_416 ,
V_51 ) )
return - V_250 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_416 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_224 . V_194 = 1 ;
V_220 -> V_417 = F_100 ( ( T_3 ) V_413 ) ;
V_220 -> V_418 = F_100 ( ( T_3 ) V_414 ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
if ( V_34 ( V_45 ) == V_419 )
return - V_420 ;
return V_45 ;
}
int F_143 ( struct V_1 * V_2 , T_2 * V_413 , T_2 * V_414 )
{
struct V_11 * V_12 ;
struct V_421 * V_220 ;
int V_45 ;
if ( ! F_1 ( V_2 , V_422 ,
V_51 ) )
return - V_250 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_422 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_423 * V_60 =
F_2 ( V_12 ) ;
* V_413 = F_29 ( V_60 -> V_417 ) ;
* V_414 = F_29 ( V_60 -> V_418 ) ;
}
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_144 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_424 * V_220 ;
int V_45 ;
if ( F_92 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_425 ,
sizeof( * V_220 ) , V_12 , NULL ) ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_426 * V_60 = F_2 ( V_12 ) ;
V_2 -> V_111 = F_8 ( V_60 -> V_427 ) ;
V_2 -> V_428 = F_8 ( V_60 -> V_428 ) ;
V_2 -> V_287 = F_8 ( V_60 -> V_287 ) ;
V_2 -> V_429 = F_8 ( V_60 -> V_430 ) & 0xFF ;
F_31 ( & V_2 -> V_69 -> V_70 ,
L_18 ,
V_2 -> V_428 , V_2 -> V_287 ) ;
}
F_94 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_145 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_188 * V_220 ;
int V_45 ;
if ( F_74 ( V_2 ) ) {
F_6 ( V_431 ,
V_2 -> V_24 + V_432 ) ;
V_45 = F_71 ( V_2 ) ;
if ( V_45 )
F_18 ( & V_2 -> V_69 -> V_70 ,
L_19 ) ;
return V_45 ;
}
if ( F_92 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
V_220 = F_2 ( V_12 ) ;
F_79 ( V_220 , V_51 ,
V_433 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_45 = F_67 ( V_2 ) ;
F_94 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_146 ( struct V_1 * V_2 , T_1 * V_434 ,
T_2 V_435 , T_3 V_436 , const T_1 * V_437 )
{
struct V_11 * V_12 ;
struct V_438 * V_220 ;
int V_45 ;
if ( ! ( F_137 ( V_2 ) & V_439 ) )
return 0 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_55 ,
V_440 , sizeof( * V_220 ) , V_12 , NULL ) ;
V_220 -> V_241 = F_80 ( V_2 -> V_236 ) ;
V_220 -> V_441 = F_100 ( V_435 ) ;
V_220 -> V_442 = F_100 ( F_109 ( V_436 ) - 1 ) ;
if ( ! F_20 ( V_2 ) )
V_220 -> V_224 . V_194 = 1 ;
memcpy ( V_220 -> V_443 , V_434 , V_436 ) ;
memcpy ( V_220 -> V_444 , V_437 , V_445 ) ;
F_81 ( V_220 -> V_444 , sizeof( V_220 -> V_444 ) ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_147 ( struct V_1 * V_2 , T_1 V_111 ,
T_1 V_446 , T_1 V_447 , T_1 V_448 )
{
struct V_11 * V_12 ;
struct V_449 * V_220 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_450 ,
sizeof( * V_220 ) , V_12 , NULL ) ;
V_220 -> V_111 = V_111 ;
V_220 -> V_451 = V_448 ;
V_220 -> V_452 = V_446 ;
V_220 -> V_453 = V_447 ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_148 ( struct V_1 * V_2 , T_1 V_111 , T_2 * V_448 )
{
struct V_11 * V_12 ;
struct V_454 * V_220 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_455 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_111 = V_111 ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_456 * V_60 =
F_2 ( V_12 ) ;
* V_448 = V_60 -> V_451 ;
}
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_149 ( struct V_1 * V_2 ,
T_1 V_457 , T_1 * V_458 )
{
struct V_163 V_459 ;
struct V_11 * V_12 ;
struct V_460 * V_220 ;
int V_45 ;
if ( V_457 > V_461 )
return - V_462 ;
V_459 . V_202 = sizeof( struct V_463 ) ;
V_459 . V_167 = F_130 ( & V_2 -> V_69 -> V_70 , V_459 . V_202 , & V_459 . V_169 ,
V_368 ) ;
if ( ! V_459 . V_167 ) {
F_18 ( & V_2 -> V_69 -> V_70 , L_20 ) ;
return - V_369 ;
}
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_459 . V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_464 ,
V_459 . V_202 , V_12 , & V_459 ) ;
V_220 -> V_465 = F_80 ( V_2 -> V_91 ) ;
V_220 -> V_457 = F_80 ( V_457 ) ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_463 * V_60 = V_459 . V_167 ;
memcpy ( V_458 , V_60 -> V_466 , V_467 ) ;
}
V_182:
F_47 ( & V_2 -> V_212 ) ;
F_131 ( & V_2 -> V_69 -> V_70 , V_459 . V_202 , V_459 . V_167 , V_459 . V_169 ) ;
return V_45 ;
}
static int F_150 ( struct V_1 * V_2 ,
struct V_163 * V_459 , T_2 V_468 ,
T_2 V_469 , const char * V_470 ,
T_2 * V_471 , T_1 * V_472 ,
T_1 * V_473 )
{
struct V_11 * V_12 ;
struct V_474 * V_220 ;
struct V_475 * V_60 ;
void * V_258 = NULL ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_2 -> V_52 = 0 ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_476;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_50 ,
sizeof( struct V_474 ) , V_12 ,
NULL ) ;
V_258 = & V_220 -> V_228 ;
F_101 ( struct V_477 ,
V_478 , V_258 , V_468 ) ;
if ( V_468 == 0 )
F_101 ( struct V_477 ,
V_479 , V_258 , 1 ) ;
else
F_101 ( struct V_477 ,
V_479 , V_258 , 0 ) ;
F_81 ( V_258 , sizeof( V_220 -> V_228 ) ) ;
V_220 -> V_480 = F_80 ( V_469 ) ;
F_133 ( V_220 -> V_481 , V_470 , sizeof( V_220 -> V_481 ) ) ;
V_220 -> V_482 = F_80 ( 1 ) ;
V_220 -> V_360 = F_80 ( V_468 ) ;
V_220 -> V_483 = F_80 ( ( V_459 -> V_169 +
sizeof( struct V_474 ) )
& 0xFFFFFFFF ) ;
V_220 -> V_484 = F_80 ( F_68 ( V_459 -> V_169 +
sizeof( struct V_474 ) ) ) ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_476;
F_47 ( & V_2 -> V_212 ) ;
if ( ! F_151 ( & V_2 -> V_48 ,
F_152 ( 60000 ) ) )
V_45 = - V_185 ;
else
V_45 = V_2 -> V_52 ;
V_60 = F_2 ( V_12 ) ;
if ( ! V_45 ) {
* V_471 = F_8 ( V_60 -> V_485 ) ;
* V_472 = V_60 -> V_472 ;
} else {
* V_473 = V_60 -> V_486 ;
}
return V_45 ;
V_476:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_153 ( struct V_1 * V_2 )
{
T_1 V_466 [ V_467 ] ;
int V_45 ;
V_45 = F_149 ( V_2 , V_487 ,
V_466 ) ;
if ( ! V_45 ) {
switch ( V_2 -> V_73 . V_488 ) {
case V_489 :
V_2 -> V_73 . V_490 =
V_466 [ V_491 ] ;
break;
case V_492 :
V_2 -> V_73 . V_490 =
V_466 [ V_493 ] ;
break;
default:
V_2 -> V_73 . V_490 = 0 ;
break;
}
}
return V_45 ;
}
int F_154 ( struct V_1 * V_2 )
{
T_1 V_466 [ V_467 ] ;
int V_45 ;
V_45 = F_149 ( V_2 , V_487 ,
V_466 ) ;
if ( ! V_45 ) {
F_133 ( V_2 -> V_73 . V_494 , V_466 +
V_495 , V_496 - 1 ) ;
F_133 ( V_2 -> V_73 . V_497 ,
V_466 + V_498 ,
V_496 - 1 ) ;
}
return V_45 ;
}
static int F_155 ( struct V_1 * V_2 ,
const char * V_470 )
{
struct V_499 * V_220 ;
struct V_11 * V_12 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_500 ,
sizeof( * V_220 ) , V_12 , NULL ) ;
F_133 ( V_220 -> V_481 , V_470 , sizeof( V_220 -> V_481 ) ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_156 ( struct V_1 * V_2 , struct V_163 * V_459 ,
T_2 V_468 , T_2 V_469 , const char * V_470 ,
T_2 * V_501 , T_2 * V_479 , T_1 * V_473 )
{
struct V_11 * V_12 ;
struct V_502 * V_220 ;
struct V_503 * V_60 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_476;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_504 ,
sizeof( struct V_502 ) , V_12 ,
NULL ) ;
V_220 -> V_505 = F_80 ( V_468 ) ;
V_220 -> V_506 = F_80 ( V_469 ) ;
strcpy ( V_220 -> V_481 , V_470 ) ;
V_220 -> V_482 = F_80 ( 1 ) ;
V_220 -> V_360 = F_80 ( V_468 ) ;
V_220 -> V_483 = F_80 ( ( V_459 -> V_169 & 0xFFFFFFFF ) ) ;
V_220 -> V_484 = F_80 ( F_68 ( V_459 -> V_169 ) ) ;
V_45 = F_60 ( V_2 ) ;
V_60 = F_2 ( V_12 ) ;
if ( ! V_45 ) {
* V_501 = F_8 ( V_60 -> V_507 ) ;
* V_479 = F_8 ( V_60 -> V_479 ) ;
} else {
* V_473 = V_60 -> V_486 ;
}
V_476:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
static int F_157 ( struct V_1 * V_2 ,
struct V_163 * V_459 , T_2 V_508 ,
T_2 V_509 , T_2 V_510 , T_2 V_365 )
{
struct V_11 * V_12 ;
struct F_157 * V_220 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_2 -> V_52 = 0 ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_476;
}
V_220 = V_459 -> V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_40 , V_459 -> V_202 , V_12 ,
V_459 ) ;
V_220 -> V_334 . V_511 = F_80 ( V_508 ) ;
if ( V_508 == V_512 )
V_220 -> V_334 . V_363 = F_80 ( V_510 ) ;
V_220 -> V_334 . V_513 = F_80 ( V_509 ) ;
V_220 -> V_334 . V_514 = F_80 ( V_365 ) ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_476;
F_47 ( & V_2 -> V_212 ) ;
if ( ! F_151 ( & V_2 -> V_48 ,
F_152 ( 40000 ) ) )
V_45 = - V_185 ;
else
V_45 = V_2 -> V_52 ;
return V_45 ;
V_476:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
static int F_158 ( struct V_1 * V_2 , T_1 * V_515 ,
T_3 V_516 , T_2 V_510 , T_2 V_517 )
{
struct V_518 * V_220 ;
struct V_11 * V_12 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_519 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_334 . V_511 = F_80 ( V_516 ) ;
if ( V_516 == V_512 )
V_220 -> V_334 . V_363 = F_80 ( V_510 + V_517 ) ;
else
V_220 -> V_334 . V_363 = F_80 ( V_517 ) ;
V_220 -> V_334 . V_513 = F_80 ( V_520 ) ;
V_220 -> V_334 . V_514 = F_80 ( 0x4 ) ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 )
memcpy ( V_515 , V_220 -> V_521 , 4 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
static bool F_159 ( struct V_1 * V_2 )
{
return ( V_2 -> V_73 . V_522 == V_523 &&
V_2 -> V_73 . V_488 == V_524 ) ;
}
static bool F_160 ( struct V_1 * V_2 ,
struct V_525 * V_526 , int type )
{
int V_5 = 0 , V_527 = 0 ;
struct V_528 * V_529 = NULL ;
if ( F_123 ( V_2 ) )
V_529 = (struct V_528 * ) V_526 ;
for ( V_5 = 0 ; V_5 < V_530 ; V_5 ++ ) {
if ( V_529 )
V_527 = F_8 ( V_529 -> V_531 [ V_5 ] . type ) ;
else
V_527 = F_8 ( V_526 -> V_531 [ V_5 ] . type ) ;
if ( V_527 == type )
return true ;
}
return false ;
}
static struct V_525 * F_161 ( struct V_1 * V_2 ,
int V_532 ,
const struct V_533 * V_534 )
{
struct V_525 * V_526 = NULL ;
const T_1 * V_535 = V_534 -> V_458 ;
V_535 += V_532 ;
while ( V_535 < ( V_534 -> V_458 + V_534 -> V_202 ) ) {
V_526 = (struct V_525 * ) V_535 ;
if ( ! memcmp ( V_536 , V_526 -> V_537 , sizeof( V_536 ) ) )
return V_526 ;
V_535 += 32 ;
}
return NULL ;
}
static int F_162 ( struct V_1 * V_2 , const T_1 * V_535 ,
T_2 V_510 , T_2 V_538 , int V_539 ,
T_3 V_516 , bool * V_540 )
{
T_2 V_517 ;
int V_45 ;
T_1 V_521 [ 4 ] ;
V_45 = F_158 ( V_2 , V_521 , V_516 , V_510 ,
V_538 - 4 ) ;
if ( V_45 )
return V_45 ;
V_517 = V_539 + V_510 + V_538 - 4 ;
if ( ! memcmp ( V_521 , V_535 + V_517 , 4 ) )
* V_540 = true ;
else
* V_540 = false ;
return V_45 ;
}
static int F_163 ( struct V_1 * V_2 , const T_1 * V_541 ,
struct V_163 * V_542 , int V_543 , int V_538 ,
T_2 V_510 )
{
T_2 V_544 , V_545 , V_546 = V_538 , V_547 = 0 ;
struct F_157 * V_220 = V_542 -> V_167 ;
int V_45 ;
while ( V_546 ) {
V_545 = F_164 ( T_2 , 32 * 1024 , V_546 ) ;
V_546 -= V_545 ;
if ( ! V_546 ) {
if ( V_543 == V_548 )
V_544 = V_549 ;
else
V_544 = V_550 ;
} else {
if ( V_543 == V_548 )
V_544 = V_551 ;
else
V_544 = V_552 ;
}
memcpy ( V_220 -> V_553 , V_541 , V_545 ) ;
V_541 += V_545 ;
V_45 = F_157 ( V_2 , V_542 , V_543 ,
V_544 , V_510 +
V_547 , V_545 ) ;
if ( V_34 ( V_45 ) == V_37 &&
V_543 == V_548 )
break;
else if ( V_45 )
return V_45 ;
V_547 += V_545 ;
}
return 0 ;
}
static int F_165 ( struct V_1 * V_2 ,
const struct V_533 * V_534 ,
struct V_163 * V_542 , int V_554 )
{
int V_555 = ( V_554 * sizeof( struct V_556 ) ) ;
struct V_86 * V_70 = & V_2 -> V_69 -> V_70 ;
struct V_525 * V_526 = NULL ;
int V_45 , V_5 , V_557 , V_558 ;
const struct V_559 * V_560 ;
bool V_540 ;
const T_1 * V_535 ;
struct V_559 V_561 [] = {
{ V_562 , V_563 ,
V_564 , V_565 } ,
{ V_566 , V_567 ,
V_568 , V_569 } ,
{ V_570 , V_571 ,
V_572 , V_573 } ,
{ V_574 , V_575 ,
V_572 , V_576 } ,
{ V_577 , V_578 ,
V_572 , V_579 } ,
{ V_580 , V_581 ,
V_564 , V_582 } ,
{ V_583 , V_584 ,
V_564 , V_585 } ,
{ V_586 , V_587 ,
V_564 , V_588 } ,
{ V_589 , V_590 ,
V_591 , V_592 } ,
{ V_593 , V_548 ,
V_594 , V_595 }
} ;
struct V_559 V_596 [] = {
{ V_597 , V_563 ,
V_598 , V_565 } ,
{ V_599 , V_567 ,
V_600 , V_569 } ,
{ V_601 , V_571 ,
V_602 , V_573 } ,
{ V_603 , V_575 ,
V_602 , V_576 } ,
{ V_604 , V_578 ,
V_602 , V_579 } ,
{ V_605 , V_581 ,
V_598 , V_582 } ,
{ V_606 , V_584 ,
V_598 , V_585 } ,
{ V_607 , V_587 ,
V_598 , V_588 }
} ;
if ( F_120 ( V_2 ) ) {
V_560 = V_561 ;
V_557 = sizeof( struct V_608 ) ;
V_558 = F_103 ( V_561 ) ;
} else {
V_560 = V_596 ;
V_557 = sizeof( struct V_609 ) ;
V_558 = F_103 ( V_596 ) ;
V_555 = 0 ;
}
V_526 = F_161 ( V_2 , V_557 + V_555 , V_534 ) ;
if ( ! V_526 ) {
F_18 ( V_70 , L_21 ) ;
return - 1 ;
}
for ( V_5 = 0 ; V_5 < V_558 ; V_5 ++ ) {
if ( ! F_160 ( V_2 , V_526 , V_560 [ V_5 ] . V_527 ) )
continue;
if ( ( V_560 [ V_5 ] . V_543 == V_590 ) &&
memcmp ( V_2 -> V_378 , L_22 , 11 ) < 0 )
continue;
if ( V_560 [ V_5 ] . V_543 == V_548 &&
! F_159 ( V_2 ) )
continue;
if ( V_560 [ V_5 ] . V_543 == V_567 ) {
V_45 = F_162 ( V_2 , V_534 -> V_458 ,
V_560 [ V_5 ] . V_363 ,
V_560 [ V_5 ] . V_202 ,
V_557 +
V_555 ,
V_567 , & V_540 ) ;
if ( V_45 ) {
F_18 ( V_70 ,
L_23 ,
V_560 [ V_5 ] . V_543 ) ;
continue;
}
if ( V_540 )
continue;
}
V_535 = V_534 -> V_458 + V_557 + V_560 [ V_5 ] . V_363 +
V_555 ;
if ( V_535 + V_560 [ V_5 ] . V_202 > V_534 -> V_458 + V_534 -> V_202 )
return - 1 ;
V_45 = F_163 ( V_2 , V_535 , V_542 , V_560 [ V_5 ] . V_543 ,
V_560 [ V_5 ] . V_202 , 0 ) ;
if ( V_45 ) {
F_18 ( V_70 , L_24 ,
V_560 [ V_5 ] . V_527 ) ;
return V_45 ;
}
}
return 0 ;
}
static T_3 F_166 ( struct V_610 V_531 )
{
T_2 V_527 = F_8 ( V_531 . type ) ;
T_3 V_516 = F_29 ( V_531 . V_543 ) ;
if ( V_516 != 0xFFFF )
return V_516 ;
switch ( V_527 ) {
case V_565 :
V_516 = V_563 ;
break;
case V_569 :
V_516 = V_567 ;
break;
case V_573 :
V_516 = V_571 ;
break;
case V_576 :
V_516 = V_575 ;
break;
case V_579 :
V_516 = V_578 ;
break;
case V_582 :
V_516 = V_581 ;
break;
case V_592 :
V_516 = V_590 ;
break;
case V_611 :
V_516 = V_612 ;
break;
case V_595 :
V_516 = V_613 ;
break;
case V_614 :
V_516 = V_615 ;
break;
case V_616 :
V_516 = V_617 ;
break;
case V_618 :
V_516 = V_619 ;
break;
default:
break;
}
return V_516 ;
}
static int F_167 ( struct V_1 * V_2 ,
const struct V_533 * V_534 ,
struct V_163 * V_542 , int V_554 )
{
int V_555 = V_554 * sizeof( struct V_556 ) ;
bool V_540 , V_620 , V_621 = true ;
struct V_86 * V_70 = & V_2 -> V_69 -> V_70 ;
struct V_525 * V_526 = NULL ;
T_2 V_510 , V_538 , V_527 ;
T_3 V_516 , V_622 ;
int V_45 , V_5 , V_557 ;
const T_1 * V_535 ;
V_557 = sizeof( struct V_608 ) ;
V_526 = F_161 ( V_2 , V_557 + V_555 , V_534 ) ;
if ( ! V_526 ) {
F_18 ( V_70 , L_21 ) ;
return - V_462 ;
}
V_623:
for ( V_5 = 0 ; V_5 < F_8 ( V_526 -> V_624 . V_625 ) ; V_5 ++ ) {
V_510 = F_8 ( V_526 -> V_531 [ V_5 ] . V_363 ) ;
V_538 = F_8 ( V_526 -> V_531 [ V_5 ] . V_626 ) ;
V_527 = F_8 ( V_526 -> V_531 [ V_5 ] . type ) ;
V_516 = F_166 ( V_526 -> V_531 [ V_5 ] ) ;
V_620 = V_526 -> V_531 [ V_5 ] . V_543 == 0xFFFF ;
if ( V_516 == 0xFFFF )
continue;
if ( V_621 )
V_622 = V_512 ;
else
V_622 = V_516 ;
if ( V_620 )
goto V_627;
V_45 = F_162 ( V_2 , V_534 -> V_458 , V_510 ,
V_538 , V_557 +
V_555 , V_622 ,
& V_540 ) ;
if ( V_34 ( V_45 ) == V_37 ||
V_34 ( V_45 ) == V_41 ) {
if ( V_622 == V_512 ) {
V_621 = false ;
goto V_623;
}
F_18 ( V_70 , L_25 ) ;
F_18 ( V_70 , L_26 ) ;
return - V_628 ;
} else if ( V_45 ) {
F_18 ( V_70 , L_23 ,
V_516 ) ;
return - V_629 ;
}
if ( V_540 )
continue;
V_627:
V_535 = V_534 -> V_458 + V_557 + V_510 + V_555 ;
if ( V_535 + V_538 > V_534 -> V_458 + V_534 -> V_202 )
return - 1 ;
V_45 = F_163 ( V_2 , V_535 , V_542 , V_622 , V_538 ,
V_510 ) ;
if ( V_34 ( V_45 ) == V_41 &&
V_622 == V_512 ) {
V_621 = false ;
goto V_623;
}
if ( V_620 &&
( V_34 ( V_45 ) == V_41 ||
( V_516 == V_619 &&
V_34 ( V_45 ) == V_630 ) ) ) {
continue;
} else if ( V_45 ) {
F_18 ( V_70 , L_24 ,
V_527 ) ;
switch ( V_35 ( V_45 ) ) {
case V_631 :
F_18 ( V_70 ,
L_27 ) ;
return - V_462 ;
case V_632 :
F_18 ( V_70 ,
L_28 ) ;
return - V_462 ;
default:
return - V_629 ;
}
}
}
return 0 ;
}
int F_168 ( struct V_1 * V_2 ,
const struct V_533 * V_534 )
{
struct V_86 * V_70 = & V_2 -> V_69 -> V_70 ;
struct V_163 V_542 ;
const T_1 * V_633 = NULL ;
T_1 * V_634 = NULL ;
T_6 V_635 = 0 ;
T_2 V_636 = 0 ;
T_2 V_471 = 0 ;
T_2 V_363 = 0 ;
int V_45 = 0 ;
T_1 V_637 = 0 ;
T_1 V_472 ;
if ( ! F_169 ( V_534 -> V_202 , sizeof( T_2 ) ) ) {
F_18 ( V_70 , L_29 ) ;
return - V_462 ;
}
V_542 . V_202 = sizeof( struct V_474 )
+ V_638 ;
V_542 . V_167 = F_130 ( V_70 , V_542 . V_202 ,
& V_542 . V_169 , V_639 ) ;
if ( ! V_542 . V_167 )
return - V_369 ;
V_634 = V_542 . V_167 +
sizeof( struct V_474 ) ;
V_635 = V_534 -> V_202 ;
V_633 = V_534 -> V_458 ;
while ( V_635 ) {
V_636 = F_164 ( T_2 , V_635 , V_638 ) ;
memcpy ( V_634 , V_633 , V_636 ) ;
V_45 = F_150 ( V_2 , & V_542 ,
V_636 , V_363 ,
V_640 ,
& V_471 , & V_472 ,
& V_637 ) ;
if ( V_45 )
break;
V_363 += V_471 ;
V_633 += V_471 ;
V_635 -= V_471 ;
}
if ( ! V_45 ) {
V_45 = F_150 ( V_2 , & V_542 ,
0 , V_363 ,
V_640 ,
& V_471 , & V_472 ,
& V_637 ) ;
}
F_131 ( V_70 , V_542 . V_202 , V_542 . V_167 , V_542 . V_169 ) ;
if ( V_45 ) {
F_18 ( V_70 , L_30 ) ;
return F_170 ( V_45 ) ;
}
F_31 ( V_70 , L_31 ) ;
if ( V_472 == V_641 ) {
F_31 ( V_70 , L_32 ) ;
V_45 = F_171 ( V_2 ,
V_642 ) ;
if ( V_45 ) {
F_18 ( V_70 , L_33 ) ;
F_18 ( V_70 , L_34 ) ;
}
} else if ( V_472 != V_643 ) {
F_31 ( V_70 , L_34 ) ;
}
return 0 ;
}
static bool F_172 ( struct V_1 * V_2 ,
struct V_608 * V_644 )
{
if ( ! V_644 ) {
F_18 ( & V_2 -> V_69 -> V_70 , L_35 ) ;
return false ;
}
switch ( V_644 -> V_645 [ 0 ] ) {
case V_646 :
if ( ! F_173 ( V_2 ) )
return false ;
break;
case V_647 :
if ( ! F_120 ( V_2 ) )
return false ;
break;
case V_648 :
if ( ! F_123 ( V_2 ) )
return false ;
break;
default:
return false ;
}
if ( F_20 ( V_2 ) && V_644 -> V_649 == 0 )
return V_2 -> V_429 < 0x10 ;
else
return ( V_644 -> V_649 >= V_2 -> V_429 ) ;
}
int F_174 ( struct V_1 * V_2 , const struct V_533 * V_534 )
{
struct V_86 * V_70 = & V_2 -> V_69 -> V_70 ;
struct V_608 * V_650 ;
struct V_556 * V_651 ;
int V_45 = 0 , V_5 , V_652 ;
struct V_163 V_542 ;
V_650 = (struct V_608 * ) V_534 -> V_458 ;
if ( ! F_172 ( V_2 , V_650 ) ) {
F_18 ( V_70 , L_36 ) ;
return - V_462 ;
}
V_542 . V_202 = sizeof( struct F_157 ) ;
V_542 . V_167 = F_130 ( V_70 , V_542 . V_202 , & V_542 . V_169 ,
V_639 ) ;
if ( ! V_542 . V_167 )
return - V_369 ;
V_652 = F_8 ( V_650 -> V_652 ) ;
for ( V_5 = 0 ; V_5 < V_652 ; V_5 ++ ) {
V_651 = (struct V_556 * ) ( V_534 -> V_458 +
( sizeof( struct V_608 ) +
V_5 * sizeof( struct V_556 ) ) ) ;
if ( ! F_123 ( V_2 ) &&
F_8 ( V_651 -> V_653 ) != 1 )
continue;
if ( F_173 ( V_2 ) )
V_45 = F_167 ( V_2 , V_534 , & V_542 ,
V_652 ) ;
else
V_45 = F_165 ( V_2 , V_534 , & V_542 ,
V_652 ) ;
}
F_131 ( V_70 , V_542 . V_202 , V_542 . V_167 , V_542 . V_169 ) ;
if ( ! V_45 )
F_31 ( V_70 , L_31 ) ;
return V_45 ;
}
int F_175 ( struct V_1 * V_2 , T_1 * V_243 ,
struct V_163 * V_331 )
{
struct V_11 * V_12 ;
struct V_654 * V_220 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_331 -> V_167 ;
F_79 ( & V_220 -> V_224 , V_55 ,
V_655 , sizeof( * V_220 ) ,
V_12 , V_331 ) ;
memcpy ( V_220 -> V_656 , V_243 , V_244 ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_176 ( struct V_1 * V_2 , T_1 V_111 ,
T_1 V_657 , T_1 V_658 )
{
struct V_11 * V_12 ;
struct V_659 * V_220 ;
int V_45 ;
if ( ! F_1 ( V_2 , V_49 ,
V_47 ) )
return - V_250 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_476;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_47 ,
V_49 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_660 = V_111 ;
V_220 -> V_661 = V_111 ;
V_220 -> V_657 = V_657 ;
V_220 -> V_662 = V_658 ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_476;
F_47 ( & V_2 -> V_212 ) ;
if ( ! F_151 ( & V_2 -> V_48 ,
F_152 ( V_663 ) ) )
V_45 = - V_185 ;
return V_45 ;
V_476:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_177 ( struct V_1 * V_2 , T_2 V_111 ,
T_2 V_657 , T_2 V_664 , T_2 V_665 ,
T_5 V_666 )
{
struct V_11 * V_12 ;
struct V_667 * V_220 ;
struct V_668 * V_60 ;
int V_45 ;
if ( ! F_1 ( V_2 , V_46 ,
V_47 ) )
return - V_250 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_47 ,
V_46 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_220 -> V_224 . V_181 = F_80 ( 15 ) ;
V_220 -> V_666 = F_178 ( V_666 ) ;
V_220 -> V_660 = F_80 ( V_111 ) ;
V_220 -> V_661 = F_80 ( V_111 ) ;
V_220 -> V_664 = F_80 ( V_664 ) ;
V_220 -> V_665 = F_80 ( V_665 ) ;
V_220 -> V_657 = F_80 ( V_657 ) ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_182;
F_47 ( & V_2 -> V_212 ) ;
F_179 ( & V_2 -> V_48 ) ;
V_60 = F_2 ( V_12 ) ;
V_45 = F_8 ( V_60 -> V_45 ) ;
return V_45 ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_180 ( struct V_1 * V_2 , T_5 V_666 ,
T_2 V_669 , struct V_163 * V_459 )
{
struct V_11 * V_12 ;
struct V_670 * V_220 ;
int V_45 ;
int V_5 , V_671 = 0 ;
if ( ! F_1 ( V_2 , V_672 ,
V_47 ) )
return - V_250 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_459 -> V_167 ;
F_79 ( & V_220 -> V_224 , V_47 ,
V_672 , V_459 -> V_202 , V_12 ,
V_459 ) ;
V_220 -> V_666 = F_178 ( V_666 ) ;
V_220 -> V_673 = F_80 ( V_669 ) ;
for ( V_5 = 0 ; V_5 < V_669 ; V_5 ++ ) {
V_220 -> V_674 [ V_5 ] = ( T_1 ) ( V_666 >> ( V_671 * 8 ) ) ;
V_671 ++ ;
if ( V_671 > 7 )
V_671 = 0 ;
}
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_675 * V_60 ;
V_60 = V_459 -> V_167 ;
if ( ( memcmp ( V_60 -> V_676 , V_220 -> V_674 , V_669 ) != 0 ) ||
V_60 -> V_677 ) {
V_45 = - 1 ;
}
}
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_181 ( struct V_1 * V_2 ,
struct V_163 * V_331 )
{
struct V_11 * V_12 ;
struct V_678 * V_220 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_331 -> V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_679 , sizeof( * V_220 ) , V_12 ,
V_331 ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_182 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_680 * V_220 ;
struct V_163 V_459 ;
int V_45 ;
if ( ! F_1 ( V_2 , V_681 ,
V_51 ) )
return - V_250 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_459 . V_202 = sizeof( struct V_680 ) ;
V_459 . V_167 = F_130 ( & V_2 -> V_69 -> V_70 , V_459 . V_202 , & V_459 . V_169 ,
V_368 ) ;
if ( ! V_459 . V_167 ) {
F_18 ( & V_2 -> V_69 -> V_70 , L_37 ) ;
V_45 = - V_369 ;
goto V_182;
}
V_220 = V_459 . V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_681 , sizeof( * V_220 ) ,
V_12 , & V_459 ) ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_682 * V_683 =
V_459 . V_167 + sizeof( struct V_188 ) ;
V_2 -> V_73 . V_522 = F_29 ( V_683 -> V_522 ) ;
V_2 -> V_73 . V_488 =
F_29 ( V_683 -> V_488 ) ;
V_2 -> V_73 . V_684 =
F_29 ( V_683 -> V_684 ) ;
V_2 -> V_73 . V_685 =
F_29 ( V_683 -> V_685 ) ;
V_2 -> V_73 . V_686 =
F_8 ( V_683 -> V_686 ) ;
if ( F_123 ( V_2 ) ) {
V_2 -> V_73 . V_685 =
V_687 |
V_688 ;
}
}
F_131 ( & V_2 -> V_69 -> V_70 , V_459 . V_202 , V_459 . V_167 , V_459 . V_169 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
static int F_183 ( struct V_1 * V_2 , T_2 V_689 , T_2 V_245 )
{
struct V_11 * V_12 ;
struct V_690 * V_220 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_691 , sizeof( * V_220 ) , V_12 , NULL ) ;
V_220 -> V_224 . V_245 = V_245 ;
V_220 -> V_692 = F_80 ( V_693 ) ;
V_220 -> V_694 = F_80 ( V_689 ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_184 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_695 * V_220 ;
struct V_696 * V_60 ;
int V_45 , V_5 ;
int V_367 = F_185 ( sizeof( * V_220 ) , sizeof( * V_60 ) ) ;
struct V_697 * V_698 ;
struct V_163 V_699 ;
T_2 * V_700 ;
if ( F_92 ( & V_2 -> V_213 ) )
return - 1 ;
memset ( & V_699 , 0 , sizeof( struct V_163 ) ) ;
V_699 . V_202 = sizeof( struct V_696 ) ;
V_699 . V_167 = F_130 ( & V_2 -> V_69 -> V_70 ,
V_699 . V_202 ,
& V_699 . V_169 , V_368 ) ;
if ( ! V_699 . V_167 ) {
F_18 ( & V_2 -> V_69 -> V_70 , L_38 ) ;
V_45 = - V_369 ;
goto V_182;
}
V_12 = F_85 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_699 . V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_701 , V_367 ,
V_12 , & V_699 ) ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
V_698 = V_699 . V_167 + sizeof( struct V_30 ) ;
V_2 -> V_91 = V_698 -> V_702 . V_703 ;
V_700 = V_698 -> V_702 . V_704 ;
for ( V_5 = 0 ; V_5 < V_705 ; V_5 ++ )
V_2 -> V_700 [ V_5 ] = F_8 ( V_700 [ V_5 ] ) &
( F_186 ( 16 ) - 1 ) ;
}
V_182:
F_94 ( & V_2 -> V_213 ) ;
if ( V_699 . V_167 )
F_131 ( & V_2 -> V_69 -> V_70 , V_699 . V_202 ,
V_699 . V_167 , V_699 . V_169 ) ;
return V_45 ;
}
int F_187 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_706 * V_220 ;
int V_45 ;
if ( F_92 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_707 ,
sizeof( * V_220 ) , V_12 , NULL ) ;
V_220 -> V_708 = F_80 ( V_709 |
V_710 ) ;
V_220 -> V_321 = F_80 ( V_710 ) ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_711 * V_60 = F_2 ( V_12 ) ;
V_2 -> V_712 = F_8 ( V_60 -> V_321 ) &
V_710 ;
if ( ! V_2 -> V_712 )
F_17 ( & V_2 -> V_69 -> V_70 ,
L_39 ) ;
}
V_182:
F_94 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_188 ( struct V_1 * V_2 , T_2 * V_713 ,
T_2 V_245 )
{
struct V_11 * V_12 ;
struct V_714 * V_220 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_715 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_224 . V_245 = V_245 ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_716 * V_60 =
F_2 ( V_12 ) ;
* V_713 = F_8 ( V_60 -> V_717 ) ;
if ( F_20 ( V_2 ) && F_189 ( V_2 ) &&
F_190 ( V_2 ) )
* V_713 = V_718 ;
}
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_191 ( struct V_1 * V_2 , T_2 V_719 ,
T_2 V_245 )
{
struct V_11 * V_12 ;
struct V_720 * V_220 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_721 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_224 . V_245 = V_245 ;
if ( F_74 ( V_2 ) )
V_220 -> V_722 = F_80 ( V_719 ) ;
else
V_220 -> V_719 = F_80 ( V_719 ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_192 ( struct V_1 * V_2 , T_1 * V_243 ,
bool * V_723 , T_2 * V_237 , T_2 V_236 ,
T_1 V_245 )
{
struct V_11 * V_12 ;
struct V_724 * V_220 ;
int V_45 ;
int V_725 ;
struct V_163 V_726 ;
int V_5 ;
memset ( & V_726 , 0 , sizeof( struct V_163 ) ) ;
V_726 . V_202 = sizeof( struct V_727 ) ;
V_726 . V_167 = F_130 ( & V_2 -> V_69 -> V_70 ,
V_726 . V_202 ,
& V_726 . V_169 ,
V_368 ) ;
if ( ! V_726 . V_167 ) {
F_18 ( & V_2 -> V_69 -> V_70 ,
L_40 ) ;
return - V_369 ;
}
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_156;
}
V_220 = V_726 . V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_728 ,
V_726 . V_202 , V_12 , & V_726 ) ;
V_220 -> V_224 . V_245 = V_245 ;
V_220 -> V_729 = V_240 ;
if ( * V_723 ) {
V_220 -> V_730 = F_80 ( * V_237 ) ;
V_220 -> V_731 = F_100 ( V_236 ) ;
V_220 -> V_732 = 0 ;
} else {
V_220 -> V_732 = 1 ;
}
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_727 * V_60 =
V_726 . V_167 ;
if ( * V_723 ) {
memcpy ( V_243 , V_60 -> V_733 . V_734 . V_735 ,
V_244 ) ;
goto V_156;
}
V_725 = V_60 -> V_736 + V_60 -> V_737 ;
for ( V_5 = 0 ; V_5 < V_725 ; V_5 ++ ) {
struct V_738 * V_739 ;
T_3 V_740 ;
T_2 V_730 ;
V_739 = & V_60 -> V_741 [ V_5 ] ;
V_740 = F_29 ( V_739 -> V_740 ) ;
if ( V_740 == sizeof( T_2 ) ) {
* V_723 = true ;
V_730 = V_739 -> V_734 . V_742 . V_730 ;
* V_237 = F_8 ( V_730 ) ;
goto V_156;
}
}
* V_723 = false ;
memcpy ( V_243 , V_60 -> V_741 [ 0 ] . V_734 . V_735 ,
V_244 ) ;
}
V_156:
F_47 ( & V_2 -> V_212 ) ;
F_131 ( & V_2 -> V_69 -> V_70 , V_726 . V_202 ,
V_726 . V_167 , V_726 . V_169 ) ;
return V_45 ;
}
int F_193 ( struct V_1 * V_2 , T_2 V_743 ,
T_1 * V_243 , T_2 V_236 , bool V_744 , T_2 V_245 )
{
if ( ! V_744 )
F_192 ( V_2 , V_243 , & V_744 , & V_743 ,
V_236 , V_245 ) ;
if ( F_20 ( V_2 ) )
return F_104 ( V_2 , V_243 , false ,
V_236 , V_743 ) ;
else
return F_192 ( V_2 , V_243 , & V_744 ,
& V_743 ,
V_236 , V_245 ) ;
}
int F_194 ( struct V_1 * V_2 , T_1 * V_243 )
{
int V_45 ;
bool V_745 = false ;
F_195 ( V_243 ) ;
if ( F_20 ( V_2 ) ) {
if ( F_190 ( V_2 ) )
V_45 = F_104 ( V_2 , V_243 , true , 0 ,
0 ) ;
else
V_45 = F_104 ( V_2 , V_243 , false ,
V_2 -> V_236 , 0 ) ;
} else {
V_45 = F_192 ( V_2 , V_243 , & V_745 ,
NULL , V_2 -> V_236 , 0 ) ;
}
return V_45 ;
}
int F_196 ( struct V_1 * V_2 , T_1 * V_746 ,
T_1 V_725 , T_2 V_245 )
{
struct V_11 * V_12 ;
struct V_747 * V_220 ;
int V_45 ;
struct V_163 V_459 ;
memset ( & V_459 , 0 , sizeof( struct V_163 ) ) ;
V_459 . V_202 = sizeof( struct V_747 ) ;
V_459 . V_167 = F_130 ( & V_2 -> V_69 -> V_70 , V_459 . V_202 , & V_459 . V_169 ,
V_639 ) ;
if ( ! V_459 . V_167 )
return - V_369 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_459 . V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_748 , sizeof( * V_220 ) ,
V_12 , & V_459 ) ;
V_220 -> V_224 . V_245 = V_245 ;
V_220 -> V_725 = V_725 ;
if ( V_725 )
memcpy ( V_220 -> V_243 , V_746 , V_244 * V_725 ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_131 ( & V_2 -> V_69 -> V_70 , V_459 . V_202 , V_459 . V_167 , V_459 . V_169 ) ;
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_197 ( struct V_1 * V_2 , T_1 * V_243 , int V_241 , T_2 V_251 )
{
bool V_749 = false ;
T_1 V_750 [ V_244 ] ;
T_2 V_237 ;
int V_45 ;
V_45 = F_192 ( V_2 , V_750 , & V_749 ,
& V_237 , V_241 , V_251 ) ;
if ( ! V_45 && V_749 )
F_106 ( V_2 , V_241 , V_237 , V_251 ) ;
return F_196 ( V_2 , V_243 , V_243 ? 1 : 0 , V_251 ) ;
}
int F_198 ( struct V_1 * V_2 , T_3 V_115 ,
T_2 V_245 , T_3 V_751 , T_3 V_752 , T_1 V_753 )
{
struct V_11 * V_12 ;
struct V_754 * V_220 ;
void * V_258 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
V_258 = & V_220 -> V_228 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_755 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_220 -> V_224 . V_245 = V_245 ;
F_101 ( struct V_756 , V_303 , V_258 , V_751 ) ;
if ( V_115 ) {
F_101 ( struct V_756 , V_757 , V_258 , 1 ) ;
F_101 ( struct V_756 , V_115 , V_258 , V_115 ) ;
}
if ( ! F_20 ( V_2 ) && V_752 ) {
F_101 ( struct V_756 , V_303 ,
V_258 , V_2 -> V_91 ) ;
F_101 ( struct V_756 , V_758 , V_258 , 1 ) ;
F_101 ( struct V_756 , V_759 ,
V_258 , V_752 ) ;
}
if ( ! F_20 ( V_2 ) && V_753 ) {
F_101 ( struct V_756 , V_760 ,
V_258 , V_753 ) ;
F_101 ( struct V_756 , V_761 ,
V_258 , V_753 ) ;
}
F_81 ( V_220 -> V_228 , sizeof( V_220 -> V_228 ) ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_199 ( struct V_1 * V_2 , T_3 * V_115 ,
T_2 V_245 , T_3 V_751 , T_1 * V_762 , bool * V_753 )
{
struct V_11 * V_12 ;
struct V_763 * V_220 ;
void * V_258 ;
int V_45 ;
T_3 V_764 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
V_258 = & V_220 -> V_228 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_765 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_220 -> V_224 . V_245 = V_245 ;
F_101 ( struct V_766 , V_303 ,
V_258 , V_751 ) ;
F_101 ( struct V_766 , V_757 , V_258 , 1 ) ;
if ( ! F_20 ( V_2 ) && V_762 ) {
F_101 ( struct V_766 , V_303 ,
V_258 , V_2 -> V_91 ) ;
F_101 ( struct V_766 , V_758 , V_258 , 1 ) ;
}
F_81 ( V_220 -> V_228 , sizeof( V_220 -> V_228 ) ) ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_767 * V_60 =
F_2 ( V_12 ) ;
F_16 ( & V_60 -> V_228 , sizeof( V_60 -> V_228 ) ) ;
V_764 = F_200 ( struct V_768 ,
V_115 , & V_60 -> V_228 ) ;
if ( V_115 )
* V_115 = F_29 ( V_764 ) ;
if ( V_762 )
* V_762 = F_200 ( struct V_768 ,
V_759 , & V_60 -> V_228 ) ;
if ( V_753 )
* V_753 =
F_200 ( struct V_768 ,
V_753 , & V_60 -> V_228 ) ;
}
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
static bool F_201 ( struct V_1 * V_2 )
{
struct V_769 * V_69 = V_2 -> V_69 ;
if ( F_75 ( V_2 ) )
return true ;
switch ( V_69 -> V_770 ) {
case V_771 :
case V_772 :
case V_773 :
case V_774 :
return true ;
default:
return false ;
}
}
int F_202 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_775 * V_220 ;
int V_45 = 0 ;
struct V_163 V_459 ;
if ( ! F_1 ( V_2 , V_655 ,
V_55 ) )
return - V_250 ;
if ( F_201 ( V_2 ) )
return V_45 ;
if ( F_92 ( & V_2 -> V_213 ) )
return - 1 ;
memset ( & V_459 , 0 , sizeof( struct V_163 ) ) ;
V_459 . V_202 = sizeof( struct V_776 ) ;
V_459 . V_167 = F_130 ( & V_2 -> V_69 -> V_70 , V_459 . V_202 , & V_459 . V_169 ,
V_368 ) ;
if ( ! V_459 . V_167 ) {
F_18 ( & V_2 -> V_69 -> V_70 , L_38 ) ;
V_45 = - V_369 ;
goto V_182;
}
V_12 = F_85 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_459 . V_167 ;
F_79 ( & V_220 -> V_224 , V_55 ,
V_655 ,
sizeof( * V_220 ) , V_12 , & V_459 ) ;
V_220 -> V_224 . V_194 = 1 ;
V_220 -> V_777 = V_778 ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_776 * V_60 ;
V_60 = (struct V_776 * ) V_459 . V_167 ;
V_2 -> V_779 = V_60 -> V_780 ;
if ( V_2 -> V_779 & V_781 )
V_2 -> V_782 = true ;
}
V_182:
F_94 ( & V_2 -> V_213 ) ;
if ( V_459 . V_167 )
F_131 ( & V_2 -> V_69 -> V_70 , V_459 . V_202 , V_459 . V_167 ,
V_459 . V_169 ) ;
return V_45 ;
}
int F_203 ( struct V_1 * V_2 , T_2 V_783 )
{
struct V_163 V_784 ;
struct V_785 * V_786 ;
int V_45 ;
int V_5 , V_671 ;
memset ( & V_784 , 0 , sizeof( struct V_163 ) ) ;
V_784 . V_202 = sizeof( struct V_787 ) ;
V_784 . V_167 = F_130 ( & V_2 -> V_69 -> V_70 ,
V_784 . V_202 , & V_784 . V_169 ,
V_368 ) ;
if ( ! V_784 . V_167 )
return - V_369 ;
V_45 = F_204 ( V_2 , & V_784 ) ;
if ( V_45 )
goto V_182;
V_786 = (struct V_785 * )
( V_784 . V_167 + sizeof( struct V_30 ) ) ;
for ( V_5 = 0 ; V_5 < F_8 ( V_786 -> V_788 ) ; V_5 ++ ) {
T_2 V_789 = F_8 ( V_786 -> V_790 [ V_5 ] . V_789 ) ;
for ( V_671 = 0 ; V_671 < V_789 ; V_671 ++ ) {
if ( V_786 -> V_790 [ V_5 ] . V_791 [ V_671 ] . V_762 == V_792 )
V_786 -> V_790 [ V_5 ] . V_791 [ V_671 ] . V_793 =
F_80 ( V_783 ) ;
}
}
V_45 = F_205 ( V_2 , & V_784 , V_786 ) ;
V_182:
F_131 ( & V_2 -> V_69 -> V_70 , V_784 . V_202 , V_784 . V_167 ,
V_784 . V_169 ) ;
return V_45 ;
}
int F_206 ( struct V_1 * V_2 )
{
struct V_163 V_784 ;
struct V_785 * V_786 ;
int V_45 , V_671 ;
int V_783 = 0 ;
memset ( & V_784 , 0 , sizeof( struct V_163 ) ) ;
V_784 . V_202 = sizeof( struct V_787 ) ;
V_784 . V_167 = F_130 ( & V_2 -> V_69 -> V_70 ,
V_784 . V_202 , & V_784 . V_169 ,
V_368 ) ;
if ( ! V_784 . V_167 ) {
F_18 ( & V_2 -> V_69 -> V_70 , L_41 ,
V_794 ) ;
goto V_182;
}
V_45 = F_204 ( V_2 , & V_784 ) ;
if ( ! V_45 ) {
V_786 = (struct V_785 * ) ( V_784 . V_167 +
sizeof( struct V_30 ) ) ;
for ( V_671 = 0 ; V_671 < F_8 ( V_786 -> V_790 [ 0 ] . V_789 ) ; V_671 ++ ) {
if ( V_786 -> V_790 [ 0 ] . V_791 [ V_671 ] . V_762 == V_792 )
V_783 = V_786 -> V_790 [ 0 ] . V_791 [ V_671 ] . V_793 ;
}
}
F_131 ( & V_2 -> V_69 -> V_70 , V_784 . V_202 , V_784 . V_167 ,
V_784 . V_169 ) ;
V_182:
return V_783 ;
}
int F_204 ( struct V_1 * V_2 ,
struct V_163 * V_459 )
{
struct V_11 * V_12 ;
struct V_795 * V_220 ;
int V_45 ;
if ( F_92 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_459 -> V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_796 ,
V_459 -> V_202 , V_12 , V_459 ) ;
V_220 -> V_797 = F_80 ( 1 ) ;
V_45 = F_67 ( V_2 ) ;
V_182:
F_94 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_205 ( struct V_1 * V_2 ,
struct V_163 * V_459 ,
struct V_785 * V_798 )
{
struct V_11 * V_12 ;
struct V_799 * V_220 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_459 -> V_167 ;
memcpy ( & V_220 -> V_800 , V_798 , sizeof( struct V_785 ) ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_801 ,
V_459 -> V_202 , V_12 , V_459 ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_207 ( struct V_1 * V_2 )
{
struct V_802 * V_220 ;
struct V_11 * V_12 ;
int V_45 ;
if ( F_92 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_803 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
if ( ! F_20 ( V_2 ) )
V_220 -> V_224 . V_194 = 1 ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_804 * V_60 = F_2 ( V_12 ) ;
V_2 -> V_98 = V_60 -> V_98 [ V_2 -> V_91 ] ;
} else {
V_2 -> V_98 = V_2 -> V_91 + '0' ;
}
F_94 ( & V_2 -> V_213 ) ;
return V_45 ;
}
static struct V_805 * F_208 ( T_1 * V_361 , T_2 V_806 ,
bool V_807 , T_1 V_808 )
{
struct V_809 * V_224 = (struct V_809 * ) V_361 ;
struct V_805 * V_810 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_806 ; V_5 ++ ) {
if ( V_224 -> V_811 == V_812 ||
V_224 -> V_811 == V_813 ) {
V_810 = (struct V_805 * ) V_224 ;
if ( ( V_808 == V_814 ||
V_810 -> V_808 == V_808 ) &&
( ! V_807 || V_810 -> V_28 & F_111 ( V_815 ) ) )
return V_810 ;
}
V_224 -> V_816 = V_224 -> V_816 ? : V_817 ;
V_224 = ( void * ) V_224 + V_224 -> V_816 ;
}
return NULL ;
}
static struct V_805 * F_209 ( T_1 * V_361 , T_2 V_806 ,
T_1 V_808 )
{
return F_208 ( V_361 , V_806 , true , V_808 ) ;
}
static struct V_805 * F_210 ( T_1 * V_361 , T_2 V_806 ,
T_1 V_808 )
{
return F_208 ( V_361 , V_806 , false , V_808 ) ;
}
static struct V_818 * F_211 ( T_1 * V_361 , T_2 V_806 ,
T_1 V_808 )
{
struct V_809 * V_224 = (struct V_809 * ) V_361 ;
struct V_818 * V_819 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_806 ; V_5 ++ ) {
if ( V_224 -> V_811 == V_820 ||
V_224 -> V_811 == V_821 ) {
V_819 = (struct V_818 * ) V_224 ;
if ( V_819 -> V_808 == V_808 )
return V_819 ;
}
V_224 -> V_816 = V_224 -> V_816 ? : V_817 ;
V_224 = ( void * ) V_224 + V_224 -> V_816 ;
}
return NULL ;
}
static struct V_822 * F_212 ( T_1 * V_361 , T_2 V_806 )
{
struct V_809 * V_224 = (struct V_809 * ) V_361 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_806 ; V_5 ++ ) {
if ( V_224 -> V_811 == V_823 )
return (struct V_822 * ) V_224 ;
V_224 -> V_816 = V_224 -> V_816 ? : V_817 ;
V_224 = ( void * ) V_224 + V_224 -> V_816 ;
}
return NULL ;
}
static void F_213 ( struct V_824 * V_825 ,
struct V_805 * V_826 )
{
V_825 -> V_827 = F_29 ( V_826 -> V_828 ) ;
V_825 -> V_829 = F_29 ( V_826 -> V_830 ) ;
V_825 -> V_831 = F_29 ( V_826 -> V_832 ) ;
V_825 -> V_833 = F_29 ( V_826 -> V_834 ) ;
V_825 -> V_835 = F_29 ( V_826 -> V_836 ) ;
V_825 -> V_837 = F_29 ( V_826 -> V_838 ) ;
V_825 -> V_839 = F_29 ( V_826 -> V_840 ) ;
V_825 -> V_841 = F_29 ( V_826 -> V_842 ) ;
V_825 -> V_843 = F_29 ( V_826 -> V_844 ) ;
V_825 -> V_845 = F_29 ( V_826 -> V_846 ) ;
V_825 -> V_847 = F_8 ( V_826 -> V_321 ) &
V_848 ;
}
int F_214 ( struct V_1 * V_2 , struct V_824 * V_825 )
{
struct V_11 * V_12 ;
struct V_849 * V_220 ;
int V_45 ;
struct V_163 V_459 ;
if ( F_92 ( & V_2 -> V_213 ) )
return - 1 ;
memset ( & V_459 , 0 , sizeof( struct V_163 ) ) ;
V_459 . V_202 = sizeof( struct V_850 ) ;
V_459 . V_167 = F_130 ( & V_2 -> V_69 -> V_70 , V_459 . V_202 , & V_459 . V_169 ,
V_368 ) ;
if ( ! V_459 . V_167 ) {
F_18 ( & V_2 -> V_69 -> V_70 , L_37 ) ;
V_45 = - V_369 ;
goto V_182;
}
V_12 = F_85 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_459 . V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_851 ,
V_459 . V_202 , V_12 , & V_459 ) ;
if ( F_173 ( V_2 ) )
V_220 -> V_224 . V_194 = 1 ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_850 * V_60 = V_459 . V_167 ;
T_2 V_806 = F_8 ( V_60 -> V_806 ) ;
struct V_805 * V_826 ;
V_826 = F_210 ( V_60 -> V_852 , V_806 ,
V_814 ) ;
if ( ! V_826 ) {
V_45 = - V_462 ;
goto V_182;
}
V_2 -> V_808 = V_826 -> V_808 ;
V_2 -> V_853 = V_826 -> V_853 ;
if ( V_825 )
F_213 ( V_825 , V_826 ) ;
}
V_182:
F_94 ( & V_2 -> V_213 ) ;
if ( V_459 . V_167 )
F_131 ( & V_2 -> V_69 -> V_70 , V_459 . V_202 , V_459 . V_167 ,
V_459 . V_169 ) ;
return V_45 ;
}
int F_215 ( struct V_1 * V_2 ,
struct V_824 * V_825 , T_1 V_854 , T_1 V_245 )
{
struct V_855 * V_60 ;
struct V_856 * V_220 ;
struct V_805 * V_857 ;
struct V_818 * V_819 ;
struct V_822 * V_465 ;
struct V_805 * V_810 ;
struct V_11 V_12 = { 0 } ;
struct V_163 V_459 ;
T_3 V_806 ;
int V_45 ;
memset ( & V_459 , 0 , sizeof( struct V_163 ) ) ;
V_459 . V_202 = sizeof( struct V_855 ) ;
V_459 . V_167 = F_130 ( & V_2 -> V_69 -> V_70 , V_459 . V_202 , & V_459 . V_169 ,
V_368 ) ;
if ( ! V_459 . V_167 )
return - V_369 ;
V_220 = V_459 . V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_858 ,
V_459 . V_202 , & V_12 , & V_459 ) ;
if ( ! F_74 ( V_2 ) )
V_220 -> V_224 . V_194 = 1 ;
V_220 -> type = V_859 ;
V_220 -> V_224 . V_245 = V_245 ;
if ( V_854 == V_860 )
V_220 -> type |= V_861 ;
V_45 = F_96 ( V_2 , & V_12 ) ;
if ( V_45 )
goto V_182;
V_60 = V_459 . V_167 ;
V_806 = F_29 ( V_60 -> V_806 ) ;
V_819 = F_211 ( V_60 -> V_852 , V_806 ,
V_2 -> V_808 ) ;
if ( V_819 )
V_825 -> V_862 = F_29 ( V_819 -> V_863 ) ;
V_465 = F_212 ( V_60 -> V_852 , V_806 ) ;
if ( V_465 )
V_2 -> V_864 = V_465 -> V_864 ;
V_810 = F_210 ( V_60 -> V_852 , V_806 ,
V_2 -> V_808 ) ;
if ( V_810 )
F_213 ( V_825 , V_810 ) ;
V_857 = F_209 ( V_60 -> V_852 , V_806 ,
V_2 -> V_808 ) ;
if ( V_857 )
V_825 -> V_865 = V_857 -> V_321 ;
V_182:
if ( V_459 . V_167 )
F_131 ( & V_2 -> V_69 -> V_70 , V_459 . V_202 , V_459 . V_167 ,
V_459 . V_169 ) ;
return V_45 ;
}
static int F_216 ( struct V_1 * V_2 , void * V_826 ,
int V_202 , int V_229 , T_1 V_194 , T_1 V_245 )
{
struct V_866 * V_220 ;
struct V_11 V_12 = { 0 } ;
struct V_163 V_459 ;
int V_45 ;
memset ( & V_459 , 0 , sizeof( struct V_163 ) ) ;
V_459 . V_202 = sizeof( struct V_866 ) ;
V_459 . V_167 = F_130 ( & V_2 -> V_69 -> V_70 , V_459 . V_202 , & V_459 . V_169 ,
V_368 ) ;
if ( ! V_459 . V_167 )
return - V_369 ;
V_220 = V_459 . V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_867 , V_459 . V_202 ,
& V_12 , & V_459 ) ;
V_220 -> V_224 . V_194 = V_194 ;
V_220 -> V_224 . V_245 = V_245 ;
V_220 -> V_806 = F_80 ( V_229 ) ;
memcpy ( V_220 -> V_826 , V_826 , V_202 ) ;
V_45 = F_96 ( V_2 , & V_12 ) ;
if ( V_459 . V_167 )
F_131 ( & V_2 -> V_69 -> V_70 , V_459 . V_202 , V_459 . V_167 ,
V_459 . V_169 ) ;
return V_45 ;
}
static void F_217 ( struct V_805 * V_810 )
{
memset ( V_810 , 0 , sizeof( * V_810 ) ) ;
V_810 -> V_828 = 0xFFFF ;
V_810 -> V_846 = 0xFFFF ;
V_810 -> V_830 = 0xFFFF ;
V_810 -> V_832 = 0xFFFF ;
V_810 -> V_834 = 0xFFFF ;
V_810 -> V_838 = 0xFFFF ;
V_810 -> V_836 = 0xFFFF ;
V_810 -> V_868 = 0xFFFF ;
V_810 -> V_842 = 0xFFFF ;
V_810 -> V_869 = 0xFFFF ;
V_810 -> V_840 = 0xFFFF ;
V_810 -> V_844 = 0xFFFF ;
V_810 -> V_870 = 0xFF ;
V_810 -> V_871 = F_100 ( 0xF000 ) ;
V_810 -> V_872 = 0xFF ;
V_810 -> V_873 = 0x0F ;
V_810 -> V_874 = 0xFFFF ;
V_810 -> V_875 = 0xFFFF ;
V_810 -> V_876 = 0xFFFFFFFF ;
V_810 -> V_877 = 0xFFFFFFFF ;
}
static void F_218 ( struct V_818 * V_819 )
{
memset ( V_819 , 0 , sizeof( * V_819 ) ) ;
V_819 -> V_878 = 0xFF ;
V_819 -> V_879 = 0xFF ;
V_819 -> V_880 = 0xFF ;
V_819 -> V_863 = 0xFFFF ;
}
int F_219 ( struct V_1 * V_2 , T_2 V_881 , T_3 V_74 ,
T_1 V_245 )
{
struct V_805 V_882 ;
T_2 V_883 ;
T_3 V_194 = 0 ;
if ( F_120 ( V_2 ) )
return F_183 ( V_2 , V_881 / 10 , V_245 ) ;
F_217 ( & V_882 ) ;
V_882 . V_808 = V_2 -> V_808 ;
V_882 . V_853 = V_245 ;
V_882 . V_876 = 0 ;
if ( F_74 ( V_2 ) ) {
V_882 . V_224 . V_811 = V_812 ;
V_882 . V_224 . V_816 = V_817 ;
V_882 . V_28 = ( 1 << V_884 ) | ( 1 << V_885 ) |
( 1 << V_886 ) ;
V_882 . V_877 = F_80 ( V_881 / 10 ) ;
} else {
V_194 = 1 ;
V_882 . V_224 . V_811 = V_813 ;
V_882 . V_224 . V_816 = V_887 ;
V_882 . V_28 = ( 1 << V_885 ) | ( 1 << V_886 ) ;
V_883 = V_881 ? ( V_881 * 100 ) / V_74 : 100 ;
V_882 . V_877 = F_80 ( V_883 ) ;
}
return F_216 ( V_2 , & V_882 ,
V_882 . V_224 . V_816 ,
1 , V_194 , V_245 ) ;
}
static void F_220 ( struct V_1 * V_2 ,
struct V_824 V_888 ,
T_3 V_863 , T_3 V_889 ,
struct V_805 * V_890 )
{
T_2 V_865 = V_888 . V_865 ;
struct V_824 V_891 = { 0 } ;
F_215 ( V_2 , & V_891 , V_860 , 0 ) ;
if ( V_891 . V_865 & V_439 ) {
V_890 -> V_28 |= F_111 ( V_892 ) ;
if ( V_889 > 1 ) {
V_865 |= V_439 ;
if ( V_888 . V_847 & V_893 )
V_865 |= V_893 ;
} else {
V_865 &= ~ ( V_439 |
V_893 ) ;
}
} else {
V_889 = 1 ;
}
if ( V_891 . V_865 & V_894 ) {
V_890 -> V_28 |= F_111 ( V_892 ) ;
V_865 &= ~ V_894 ;
}
V_890 -> V_321 = F_80 ( V_865 ) ;
V_890 -> V_838 = F_100 ( V_889 ) ;
V_890 -> V_834 = F_100 ( V_889 ) ;
V_890 -> V_836 = F_100 ( V_889 ) ;
V_890 -> V_842 = F_100 ( V_888 . V_841 /
( V_863 + 1 ) ) ;
if ( V_891 . V_827 == V_895 )
V_890 -> V_828 = F_100 ( V_888 . V_827 /
( V_863 + 1 ) ) ;
if ( V_891 . V_829 == V_895 )
V_890 -> V_830 = F_100 ( V_888 . V_829 /
( V_863 + 1 ) ) ;
if ( V_891 . V_843 == V_895 )
V_890 -> V_844 = F_100 ( V_888 . V_843 /
( V_863 + 1 ) ) ;
if ( V_891 . V_845 == V_895 )
V_890 -> V_846 = F_100 ( V_888 . V_845 /
( V_863 + 1 ) ) ;
}
int F_221 ( struct V_1 * V_2 ,
struct V_824 V_888 , T_3 V_863 ,
T_3 V_889 )
{
struct {
struct V_818 V_819 ;
struct V_805 V_890 ;
} V_896 V_826 ;
F_218 ( & V_826 . V_819 ) ;
V_826 . V_819 . V_224 . V_811 = V_821 ;
V_826 . V_819 . V_224 . V_816 = V_887 ;
V_826 . V_819 . V_28 = F_111 ( V_885 ) | F_111 ( V_886 ) ;
V_826 . V_819 . V_808 = V_2 -> V_69 -> V_897 ;
V_826 . V_819 . V_878 = V_863 ? 1 : 0 ;
V_826 . V_819 . V_863 = F_100 ( V_863 ) ;
F_217 ( & V_826 . V_890 ) ;
V_826 . V_890 . V_224 . V_811 = V_813 ;
V_826 . V_890 . V_224 . V_816 = V_887 ;
V_826 . V_890 . V_28 = F_111 ( V_815 ) | F_111 ( V_885 ) | F_111 ( V_886 ) ;
V_826 . V_890 . V_808 = V_2 -> V_69 -> V_897 ;
V_826 . V_890 . V_853 = 0 ;
F_220 ( V_2 , V_888 , V_863 , V_889 ,
& V_826 . V_890 ) ;
return F_216 ( V_2 , & V_826 ,
2 * V_887 , 2 , 1 , 0 ) ;
}
int F_222 ( struct V_1 * V_2 , T_2 V_898 , T_1 V_899 )
{
struct V_11 * V_12 ;
struct V_900 * V_220 ;
int V_45 ;
if ( V_898 == 0xFFFFFFFF )
return - 1 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_901 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_899 = V_899 ;
V_220 -> V_902 = F_80 ( V_898 ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_223 ( struct V_1 * V_2 , T_7 V_465 )
{
struct V_822 V_903 ;
memset ( & V_903 , 0 , sizeof( V_903 ) ) ;
V_903 . V_224 . V_811 = V_823 ;
V_903 . V_224 . V_816 = V_887 ;
V_903 . V_28 = ( 1 << V_885 ) | ( 1 << V_886 ) ;
V_903 . V_904 = V_2 -> V_91 ;
if ( V_465 ) {
V_903 . V_905 = V_906 | ( 1 << V_907 ) |
( 1 << V_908 ) ;
V_903 . V_909 = F_224 ( V_465 ) ;
} else {
V_903 . V_905 = V_910 ;
V_903 . V_909 = 0 ;
}
return F_216 ( V_2 , & V_903 ,
V_887 , 1 , 1 , 0 ) ;
}
int F_225 ( struct V_1 * V_2 , struct V_911 * V_912 ,
int V_853 )
{
struct V_11 * V_12 ;
struct V_913 * V_220 ;
struct V_914 * V_60 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_915 , sizeof( * V_60 ) ,
V_12 , NULL ) ;
V_220 -> V_224 . V_245 = V_853 + 1 ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
V_60 = (struct V_914 * ) V_220 ;
V_912 -> V_236 = F_8 ( V_60 -> V_916 . V_241 ) ;
}
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
static int F_226 ( struct V_1 * V_2 )
{
#define F_227 30
T_2 V_917 ;
int V_45 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < F_227 ; V_5 ++ ) {
V_917 = F_64 ( V_2 -> V_24 + V_918 ) ;
if ( ( V_917 & V_919 ) == 0 )
break;
F_228 ( 1 ) ;
}
if ( V_5 == F_227 )
V_45 = - 1 ;
return V_45 ;
}
int F_171 ( struct V_1 * V_2 , T_2 V_920 )
{
int V_45 = 0 ;
V_45 = F_226 ( V_2 ) ;
if ( V_45 )
return V_45 ;
F_6 ( V_920 , V_2 -> V_24 + V_918 ) ;
return V_45 ;
}
bool F_229 ( struct V_1 * V_2 )
{
T_2 V_175 = 0 ;
V_175 = F_64 ( V_2 -> V_24 + V_176 ) ;
return ! ! ( V_175 & V_921 ) ;
}
int F_230 ( struct V_1 * V_2 )
{
struct V_86 * V_70 = & V_2 -> V_69 -> V_70 ;
int V_45 ;
if ( F_229 ( V_2 ) ) {
F_31 ( V_70 , L_42 ) ;
return - V_922 ;
}
V_45 = F_171 ( V_2 , V_642 |
V_923 ) ;
if ( V_45 < 0 ) {
F_18 ( V_70 , L_43 ) ;
return V_45 ;
}
V_45 = F_226 ( V_2 ) ;
if ( V_45 )
return V_45 ;
if ( ! F_229 ( V_2 ) ) {
F_18 ( V_70 , L_44 ) ;
return - V_20 ;
}
return 0 ;
}
int F_231 ( struct V_1 * V_2 )
{
int V_45 ;
V_45 = F_155 ( V_2 , V_924 ) ;
return F_170 ( V_45 ) ;
}
int F_232 ( struct V_1 * V_2 , T_1 V_245 )
{
struct V_11 * V_12 ;
struct V_925 * V_220 ;
int V_45 ;
if ( F_20 ( V_2 ) )
return 0 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_926 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_224 . V_245 = V_245 ;
V_220 -> V_658 = 1 ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_233 ( struct V_1 * V_2 , bool V_927 )
{
struct V_11 * V_12 ;
struct V_928 * V_220 ;
int V_45 ;
if ( F_92 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_929 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_930 = V_927 ;
V_45 = F_67 ( V_2 ) ;
F_94 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_234 ( struct V_1 * V_2 , T_3 * V_931 )
{
struct V_932 * V_220 ;
struct V_11 * V_12 ;
int V_45 ;
if ( F_92 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_933 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_934 * V_60 =
F_2 ( V_12 ) ;
* V_931 = F_29 ( V_60 -> V_935 ) ;
}
V_182:
F_94 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_235 ( struct V_1 * V_2 ,
int V_936 , int V_194 , T_1 V_245 )
{
struct V_11 * V_12 ;
struct V_937 * V_220 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_938 ,
sizeof( * V_220 ) , V_12 , NULL ) ;
V_220 -> V_224 . V_194 = V_194 ;
V_220 -> V_224 . V_245 = V_245 ;
if ( V_936 == V_939 ||
V_936 == V_940 )
V_220 -> V_941 |= V_942 ;
if ( V_936 == V_940 )
V_220 -> V_941 |= V_943 ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_236 ( struct V_1 * V_2 ,
int V_936 , T_1 V_245 )
{
int V_45 ;
if ( F_20 ( V_2 ) )
return - V_420 ;
V_45 = F_235 ( V_2 , V_936 ,
2 , V_245 ) ;
if ( V_34 ( V_45 ) == V_37 )
V_45 = F_235 ( V_2 , V_936 ,
1 , V_245 ) ;
return V_45 ;
}
int F_237 ( void * V_944 , void * V_945 ,
int V_946 , T_3 * V_947 , T_3 * V_948 )
{
struct V_1 * V_2 = F_238 ( V_944 ) ;
struct V_11 * V_12 ;
struct V_188 * V_224 = (struct V_188 * ) V_945 ;
struct V_188 * V_220 ;
struct V_30 * V_60 ;
int V_45 ;
F_45 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
V_60 = F_2 ( V_12 ) ;
F_79 ( V_220 , V_224 -> V_4 ,
V_224 -> V_3 , V_946 , V_12 , NULL ) ;
memcpy ( V_220 , V_945 , V_946 ) ;
F_81 ( V_220 , V_946 ) ;
V_45 = F_60 ( V_2 ) ;
if ( V_947 )
* V_947 = ( V_45 & 0xffff ) ;
if ( V_948 )
* V_948 = 0 ;
memcpy ( V_945 , V_60 , sizeof( * V_60 ) + V_60 -> V_949 ) ;
F_16 ( V_945 , sizeof( * V_60 ) + V_60 -> V_949 ) ;
V_182:
F_47 ( & V_2 -> V_212 ) ;
return V_45 ;
}
