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
#define F_54 12000
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
F_58 ( 500 , 1000 ) ;
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
T_3 F_69 ( struct V_1 * V_2 )
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
F_92 ( & V_2 -> V_212 ) ;
return 0 ;
} else {
return F_93 ( & V_2 -> V_213 ) ;
}
}
static void F_94 ( struct V_1 * V_2 )
{
if ( F_90 ( V_2 ) )
return F_95 ( & V_2 -> V_212 ) ;
else
return F_95 ( & V_2 -> V_213 ) ;
}
static struct V_11 * F_96 ( struct V_1 * V_2 ,
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
static int F_97 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_214 ;
int V_45 ;
V_45 = F_91 ( V_2 ) ;
if ( V_45 )
return V_45 ;
V_214 = F_96 ( V_2 , V_12 ) ;
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
F_94 ( V_2 ) ;
return V_45 ;
}
int F_98 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_45 ;
if ( F_74 ( V_2 ) )
return 0 ;
if ( F_93 ( & V_2 -> V_213 ) )
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
F_95 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_99 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_45 ;
if ( F_74 ( V_2 ) )
return 0 ;
if ( F_93 ( & V_2 -> V_213 ) )
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
F_95 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_100 ( struct V_1 * V_2 , struct V_217 * V_218 )
{
struct V_11 * V_12 ;
struct V_219 * V_220 ;
struct V_163 * V_221 = & V_218 -> V_17 . V_222 ;
int V_45 , V_223 = 0 ;
if ( F_93 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_225 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
if ( ! ( F_20 ( V_2 ) || F_74 ( V_2 ) ) )
V_223 = 2 ;
V_220 -> V_224 . V_194 = V_223 ;
V_220 -> V_226 = F_101 ( F_84 ( V_221 -> V_167 , V_221 -> V_202 ) ) ;
F_102 ( struct V_227 , V_103 , V_220 -> V_228 , 1 ) ;
F_102 ( struct V_227 , V_202 , V_220 -> V_228 , 0 ) ;
F_102 ( struct V_227 , V_229 , V_220 -> V_228 ,
F_103 ( V_218 -> V_17 . V_155 / 256 ) ) ;
F_81 ( V_220 -> V_228 , sizeof( V_220 -> V_228 ) ) ;
F_82 ( V_220 -> V_205 , F_104 ( V_220 -> V_205 ) , V_221 ) ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_230 * V_60 = F_2 ( V_12 ) ;
V_218 -> V_17 . V_21 = F_29 ( V_60 -> V_231 ) ;
V_218 -> V_232 =
( V_223 == 2 ) ? F_29 ( V_60 -> V_232 ) : V_218 -> V_233 ;
V_218 -> V_17 . V_211 = true ;
}
F_95 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_105 ( struct V_1 * V_2 , T_1 * V_234 ,
bool V_235 , T_2 V_236 , T_2 V_237 )
{
struct V_11 * V_12 ;
struct V_238 * V_220 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
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
V_220 -> V_241 = F_101 ( ( T_3 ) V_236 ) ;
V_220 -> V_237 = F_80 ( V_237 ) ;
V_220 -> V_235 = 0 ;
}
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_242 * V_60 = F_2 ( V_12 ) ;
memcpy ( V_234 , V_60 -> V_243 . V_33 , V_244 ) ;
}
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_106 ( struct V_1 * V_2 , T_1 * V_234 ,
T_2 V_241 , T_2 * V_237 , T_2 V_245 )
{
struct V_11 * V_12 ;
struct V_246 * V_220 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
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
F_95 ( & V_2 -> V_212 ) ;
if ( V_45 == V_67 )
V_45 = - V_250 ;
return V_45 ;
}
int F_107 ( struct V_1 * V_2 , T_2 V_241 , int V_237 , T_2 V_251 )
{
struct V_11 * V_12 ;
struct V_252 * V_220 ;
int V_45 ;
if ( V_237 == - 1 )
return 0 ;
F_92 ( & V_2 -> V_212 ) ;
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
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_108 ( struct V_1 * V_2 , struct V_14 * V_144 ,
struct V_14 * V_254 , bool V_255 , int V_256 )
{
struct V_11 * V_12 ;
struct V_257 * V_220 ;
struct V_163 * V_221 = & V_144 -> V_222 ;
void * V_258 ;
int V_45 ;
if ( F_93 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
V_220 = F_2 ( V_12 ) ;
V_258 = & V_220 -> V_228 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_259 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_220 -> V_226 = F_101 ( F_84 ( V_221 -> V_167 , V_221 -> V_202 ) ) ;
if ( F_20 ( V_2 ) ) {
F_102 ( struct V_260 , V_261 , V_258 ,
V_256 ) ;
F_102 ( struct V_260 , V_262 ,
V_258 , V_255 ) ;
F_102 ( struct V_260 , V_229 , V_258 ,
F_103 ( V_144 -> V_155 / 256 ) ) ;
F_102 ( struct V_260 , V_103 , V_258 , 1 ) ;
F_102 ( struct V_260 , V_263 , V_258 , 1 ) ;
F_102 ( struct V_260 , V_264 , V_258 , V_254 -> V_21 ) ;
} else {
V_220 -> V_224 . V_194 = 2 ;
V_220 -> V_265 = 1 ;
if ( ! F_74 ( V_2 ) )
F_102 ( struct V_266 , V_261 ,
V_258 , V_256 ) ;
F_102 ( struct V_266 , V_262 , V_258 ,
V_255 ) ;
F_102 ( struct V_266 , V_229 , V_258 ,
F_103 ( V_144 -> V_155 / 256 ) ) ;
F_102 ( struct V_266 , V_103 , V_258 , 1 ) ;
F_102 ( struct V_266 , V_263 , V_258 , 1 ) ;
F_102 ( struct V_266 , V_264 , V_258 , V_254 -> V_21 ) ;
}
F_81 ( V_258 , sizeof( V_220 -> V_228 ) ) ;
F_82 ( V_220 -> V_205 , F_104 ( V_220 -> V_205 ) , V_221 ) ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_267 * V_60 = F_2 ( V_12 ) ;
V_144 -> V_21 = F_29 ( V_60 -> V_268 ) ;
V_144 -> V_211 = true ;
}
F_95 ( & V_2 -> V_213 ) ;
return V_45 ;
}
static T_2 F_109 ( int V_269 )
{
T_2 V_270 = F_110 ( V_269 ) ;
if ( V_270 == 16 )
V_270 = 0 ;
return V_270 ;
}
static int F_111 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_144 )
{
struct V_11 * V_12 ;
struct V_271 * V_220 ;
struct V_163 * V_221 = & V_15 -> V_222 ;
void * V_258 ;
int V_45 ;
if ( F_93 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
V_220 = F_2 ( V_12 ) ;
V_258 = & V_220 -> V_228 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_272 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_220 -> V_226 = F_101 ( F_84 ( V_221 -> V_167 , V_221 -> V_202 ) ) ;
if ( F_20 ( V_2 ) ) {
F_102 ( struct V_273 , V_103 , V_258 , 1 ) ;
F_102 ( struct V_273 , V_274 , V_258 ,
F_109 ( V_15 -> V_155 ) ) ;
F_102 ( struct V_273 , V_268 , V_258 , V_144 -> V_21 ) ;
} else {
V_220 -> V_224 . V_194 = 1 ;
V_220 -> V_268 = F_101 ( V_144 -> V_21 ) ;
F_102 ( struct V_275 , V_274 , V_258 ,
F_109 ( V_15 -> V_155 ) ) ;
F_102 ( struct V_275 , V_103 , V_258 , 1 ) ;
F_102 ( struct V_275 , V_276 ,
V_258 , V_144 -> V_21 ) ;
F_102 ( struct V_275 , V_277 ,
V_258 , 1 ) ;
}
V_220 -> V_278 [ 0 ] =
F_80 ( F_112 ( V_139 ) |
F_112 ( V_140 ) |
F_112 ( V_141 ) |
F_112 ( V_142 ) ) ;
F_81 ( V_258 , sizeof( V_220 -> V_228 ) ) ;
F_82 ( V_220 -> V_205 , F_104 ( V_220 -> V_205 ) , V_221 ) ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_279 * V_60 = F_2 ( V_12 ) ;
V_15 -> V_21 = F_29 ( V_60 -> V_21 ) ;
V_15 -> V_211 = true ;
}
F_95 ( & V_2 -> V_213 ) ;
return V_45 ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_144 )
{
struct V_11 * V_12 ;
struct V_280 * V_220 ;
struct V_163 * V_221 = & V_15 -> V_222 ;
void * V_258 ;
int V_45 ;
if ( F_93 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
V_220 = F_2 ( V_12 ) ;
V_258 = & V_220 -> V_228 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_281 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_220 -> V_226 = F_101 ( F_84 ( V_221 -> V_167 , V_221 -> V_202 ) ) ;
F_102 ( struct V_273 , V_103 , V_258 , 1 ) ;
F_102 ( struct V_273 , V_274 , V_258 ,
F_109 ( V_15 -> V_155 ) ) ;
F_102 ( struct V_273 , V_268 , V_258 , V_144 -> V_21 ) ;
F_81 ( V_258 , sizeof( V_220 -> V_228 ) ) ;
F_82 ( V_220 -> V_205 , F_104 ( V_220 -> V_205 ) , V_221 ) ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_279 * V_60 = F_2 ( V_12 ) ;
V_15 -> V_21 = F_29 ( V_60 -> V_21 ) ;
V_15 -> V_211 = true ;
}
F_95 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_114 ( struct V_1 * V_2 ,
struct V_14 * V_15 , struct V_14 * V_144 )
{
int V_45 ;
V_45 = F_111 ( V_2 , V_15 , V_144 ) ;
if ( V_45 && F_20 ( V_2 ) ) {
F_17 ( & V_2 -> V_69 -> V_70 , L_12
L_13
L_14 ) ;
V_45 = F_113 ( V_2 , V_15 , V_144 ) ;
}
return V_45 ;
}
int F_115 ( struct V_1 * V_2 , struct V_282 * V_283 )
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
V_220 -> V_241 = F_101 ( V_2 -> V_236 ) ;
V_220 -> V_226 = F_84 ( V_221 -> V_167 , V_221 -> V_202 ) ;
V_220 -> V_289 = V_290 ;
V_220 -> type = V_291 ;
V_220 -> V_268 = F_101 ( V_144 -> V_21 ) ;
V_220 -> V_292 = F_109 ( V_285 -> V_155 ) ;
F_82 ( V_220 -> V_205 , F_104 ( V_220 -> V_205 ) , V_221 ) ;
V_223 = V_220 -> V_224 . V_194 ;
V_45 = F_97 ( V_2 , & V_12 ) ;
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
int F_116 ( struct V_1 * V_2 ,
struct V_14 * V_297 , T_3 V_268 , T_3 V_298 ,
T_2 V_241 , T_2 V_299 , T_1 * V_300 )
{
struct V_11 * V_12 ;
struct V_301 * V_220 ;
struct V_163 * V_221 = & V_297 -> V_222 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_55 ,
V_302 , sizeof( * V_220 ) , V_12 , NULL ) ;
V_220 -> V_268 = F_101 ( V_268 ) ;
V_220 -> V_298 = F_110 ( V_298 ) - 1 ;
V_220 -> V_226 = 2 ;
F_82 ( V_220 -> V_205 , F_104 ( V_220 -> V_205 ) , V_221 ) ;
V_220 -> V_303 = F_80 ( V_241 ) ;
V_220 -> V_304 = F_101 ( V_305 ) ;
V_220 -> V_306 = F_80 ( V_299 ) ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_307 * V_60 = F_2 ( V_12 ) ;
V_297 -> V_21 = F_29 ( V_60 -> V_21 ) ;
V_297 -> V_211 = true ;
* V_300 = V_60 -> V_300 ;
}
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_117 ( struct V_1 * V_2 , struct V_14 * V_17 ,
int V_308 )
{
struct V_11 * V_12 ;
struct V_309 * V_220 ;
T_1 V_310 = 0 , V_3 = 0 ;
int V_45 ;
if ( F_93 ( & V_2 -> V_213 ) )
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
F_118 () ;
}
F_79 ( & V_220 -> V_224 , V_310 , V_3 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_220 -> V_21 = F_101 ( V_17 -> V_21 ) ;
V_45 = F_67 ( V_2 ) ;
V_17 -> V_211 = false ;
F_95 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_119 ( struct V_1 * V_2 , struct V_14 * V_17 )
{
struct V_11 * V_12 ;
struct V_309 * V_220 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_55 ,
V_318 , sizeof( * V_220 ) , V_12 , NULL ) ;
V_220 -> V_21 = F_101 ( V_17 -> V_21 ) ;
V_45 = F_60 ( V_2 ) ;
V_17 -> V_211 = false ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_120 ( struct V_1 * V_2 , T_2 V_321 , T_2 V_322 ,
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
V_45 = F_97 ( V_2 , & V_12 ) ;
if ( ! V_45 ) {
struct V_328 * V_60 = F_2 ( & V_12 ) ;
* V_236 = F_8 ( V_60 -> V_303 ) ;
if ( F_121 ( V_2 ) && F_75 ( V_2 ) )
V_2 -> V_237 [ 0 ] = F_8 ( V_60 -> V_237 ) ;
}
return V_45 ;
}
int F_122 ( struct V_1 * V_2 , int V_303 , T_2 V_245 )
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
V_45 = F_97 ( V_2 , & V_12 ) ;
return V_45 ;
}
int F_123 ( struct V_1 * V_2 , struct V_163 * V_331 )
{
struct V_11 * V_12 ;
struct V_188 * V_224 ;
int V_45 = 0 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_224 = V_331 -> V_167 ;
F_79 ( V_224 , V_55 ,
V_53 , V_331 -> V_202 , V_12 ,
V_331 ) ;
if ( F_124 ( V_2 ) )
V_224 -> V_194 = 0 ;
if ( F_121 ( V_2 ) || F_74 ( V_2 ) )
V_224 -> V_194 = 1 ;
else
V_224 -> V_194 = 2 ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_182;
V_2 -> V_57 = true ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_125 ( struct V_1 * V_2 ,
struct V_163 * V_331 )
{
struct V_11 * V_12 ;
struct V_332 * V_220 ;
int V_45 = 0 ;
if ( ! F_1 ( V_2 , V_54 ,
V_55 ) )
return - V_250 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_331 -> V_167 ;
F_79 ( & V_220 -> V_224 , V_55 ,
V_54 , V_331 -> V_202 ,
V_12 , V_331 ) ;
V_220 -> V_333 . V_334 . V_335 = F_101 ( V_2 -> V_91 ) ;
V_220 -> V_333 . V_334 . V_336 = 0 ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_182;
V_2 -> V_57 = true ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
static int F_126 ( int V_337 )
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
int F_127 ( struct V_1 * V_2 , T_3 * V_74 ,
T_1 * V_346 , T_2 V_251 )
{
struct V_11 * V_12 ;
struct V_347 * V_220 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
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
if ( ! F_124 ( V_2 ) )
V_220 -> V_224 . V_194 = 1 ;
V_220 -> V_224 . V_245 = V_251 ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_350 * V_60 = F_2 ( V_12 ) ;
if ( V_74 ) {
* V_74 = V_60 -> V_74 ?
F_29 ( V_60 -> V_74 ) * 10 :
F_126 ( V_60 -> V_337 ) ;
if ( ! V_60 -> V_351 )
* V_74 = 0 ;
}
if ( V_346 )
* V_346 = V_60 -> V_351 ;
}
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_128 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_352 * V_220 ;
int V_45 = 0 ;
F_92 ( & V_2 -> V_212 ) ;
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
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_129 ( struct V_1 * V_2 , T_2 * V_353 )
{
struct V_11 V_12 = { 0 } ;
struct V_354 * V_220 ;
int V_45 ;
V_220 = F_2 ( & V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_355 , sizeof( * V_220 ) ,
& V_12 , NULL ) ;
V_220 -> V_356 = F_80 ( V_357 ) ;
V_45 = F_97 ( V_2 , & V_12 ) ;
if ( ! V_45 ) {
struct V_358 * V_60 = F_2 ( & V_12 ) ;
if ( V_353 && V_60 -> V_359 )
* V_353 = F_8 ( V_60 -> V_359 ) -
sizeof( T_2 ) ;
}
return V_45 ;
}
int F_130 ( struct V_1 * V_2 , T_2 V_360 , void * V_361 )
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
V_362 . V_167 = F_131 ( & V_2 -> V_69 -> V_70 ,
V_362 . V_202 ,
& V_362 . V_169 , V_368 ) ;
if ( ! V_362 . V_167 )
return - V_369 ;
F_92 ( & V_2 -> V_212 ) ;
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
F_132 ( & V_2 -> V_69 -> V_70 , V_362 . V_202 ,
V_362 . V_167 , V_362 . V_169 ) ;
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_133 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_375 * V_220 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
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
F_134 ( V_2 -> V_378 , V_60 -> V_379 ,
sizeof( V_2 -> V_378 ) ) ;
F_134 ( V_2 -> V_380 , V_60 -> V_381 ,
sizeof( V_2 -> V_380 ) ) ;
}
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
static int F_135 ( struct V_1 * V_2 ,
struct V_382 * V_383 , int V_147 )
{
struct V_11 * V_12 ;
struct V_384 * V_220 ;
int V_45 = 0 , V_5 ;
F_92 ( & V_2 -> V_212 ) ;
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
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_136 ( struct V_1 * V_2 , struct V_382 * V_383 ,
int V_147 )
{
int V_389 , V_5 = 0 ;
while ( V_147 ) {
V_389 = F_83 ( V_147 , 8 ) ;
F_135 ( V_2 , & V_383 [ V_5 ] , V_389 ) ;
V_5 += V_389 ;
V_147 -= V_389 ;
}
return 0 ;
}
int F_137 ( struct V_1 * V_2 , T_2 V_241 , T_3 * V_390 ,
T_2 V_147 , T_2 V_245 )
{
struct V_11 * V_12 ;
struct V_391 * V_220 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
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
V_220 -> V_393 = V_394 & F_138 ( V_2 ) ? 1 : 0 ;
V_220 -> V_395 = V_147 ;
memcpy ( V_220 -> V_396 , V_390 ,
V_220 -> V_395 * sizeof( V_390 [ 0 ] ) ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
static int F_139 ( struct V_1 * V_2 , T_2 V_28 , T_2 V_397 )
{
struct V_11 * V_12 ;
struct V_163 * V_191 = & V_2 -> V_398 ;
struct V_399 * V_220 = V_191 -> V_167 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
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
int V_5 ;
V_220 -> V_401 |=
F_80 ( V_405 &
F_138 ( V_2 ) ) ;
V_220 -> V_406 = F_80 ( V_2 -> V_407 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_407 ; V_5 ++ )
F_140 ( V_220 -> V_408 [ V_5 ] . V_409 ,
V_2 -> V_410 [ V_5 ] . V_243 ) ;
}
V_45 = F_60 ( V_2 ) ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_141 ( struct V_1 * V_2 , T_2 V_28 , T_2 V_397 )
{
struct V_86 * V_70 = & V_2 -> V_69 -> V_70 ;
if ( ( V_28 & F_138 ( V_2 ) ) != V_28 ) {
F_17 ( V_70 , L_16 , V_28 ) ;
F_17 ( V_70 , L_17 ,
F_138 ( V_2 ) ) ;
}
V_28 &= F_138 ( V_2 ) ;
if ( ! V_28 )
return - V_411 ;
return F_139 ( V_2 , V_28 , V_397 ) ;
}
int F_142 ( struct V_1 * V_2 , T_2 V_412 , T_2 V_413 )
{
struct V_11 * V_12 ;
struct V_414 * V_220 ;
int V_45 ;
if ( ! F_1 ( V_2 , V_415 ,
V_51 ) )
return - V_250 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_415 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_224 . V_194 = 1 ;
V_220 -> V_416 = F_101 ( ( T_3 ) V_412 ) ;
V_220 -> V_417 = F_101 ( ( T_3 ) V_413 ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
if ( V_34 ( V_45 ) == V_418 )
return - V_419 ;
return V_45 ;
}
int F_143 ( struct V_1 * V_2 , T_2 * V_412 , T_2 * V_413 )
{
struct V_11 * V_12 ;
struct V_420 * V_220 ;
int V_45 ;
if ( ! F_1 ( V_2 , V_421 ,
V_51 ) )
return - V_250 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_421 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_422 * V_60 =
F_2 ( V_12 ) ;
* V_412 = F_29 ( V_60 -> V_416 ) ;
* V_413 = F_29 ( V_60 -> V_417 ) ;
}
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_144 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_423 * V_220 ;
int V_45 ;
if ( F_93 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_424 ,
sizeof( * V_220 ) , V_12 , NULL ) ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_425 * V_60 = F_2 ( V_12 ) ;
V_2 -> V_111 = F_8 ( V_60 -> V_426 ) ;
V_2 -> V_427 = F_8 ( V_60 -> V_427 ) ;
V_2 -> V_287 = F_8 ( V_60 -> V_287 ) ;
V_2 -> V_428 = F_8 ( V_60 -> V_429 ) & 0xFF ;
F_31 ( & V_2 -> V_69 -> V_70 ,
L_18 ,
V_2 -> V_427 , V_2 -> V_287 ) ;
}
F_95 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_145 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_188 * V_220 ;
int V_45 ;
if ( F_74 ( V_2 ) ) {
F_6 ( V_430 ,
V_2 -> V_24 + V_431 ) ;
V_45 = F_71 ( V_2 ) ;
if ( V_45 )
F_18 ( & V_2 -> V_69 -> V_70 ,
L_19 ) ;
return V_45 ;
}
if ( F_93 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
V_220 = F_2 ( V_12 ) ;
F_79 ( V_220 , V_51 ,
V_432 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_45 = F_67 ( V_2 ) ;
F_95 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_146 ( struct V_1 * V_2 , T_1 * V_433 ,
T_2 V_434 , T_3 V_435 , const T_1 * V_436 )
{
struct V_11 * V_12 ;
struct V_437 * V_220 ;
int V_45 ;
if ( ! ( F_138 ( V_2 ) & V_438 ) )
return 0 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_55 ,
V_439 , sizeof( * V_220 ) , V_12 , NULL ) ;
V_220 -> V_241 = F_80 ( V_2 -> V_236 ) ;
V_220 -> V_440 = F_101 ( V_434 ) ;
V_220 -> V_441 = F_101 ( F_110 ( V_435 ) - 1 ) ;
if ( ! F_20 ( V_2 ) )
V_220 -> V_224 . V_194 = 1 ;
memcpy ( V_220 -> V_442 , V_433 , V_435 ) ;
memcpy ( V_220 -> V_443 , V_436 , V_444 ) ;
F_81 ( V_220 -> V_443 , sizeof( V_220 -> V_443 ) ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_147 ( struct V_1 * V_2 , T_1 V_111 ,
T_1 V_445 , T_1 V_446 , T_1 V_447 )
{
struct V_11 * V_12 ;
struct V_448 * V_220 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_449 ,
sizeof( * V_220 ) , V_12 , NULL ) ;
V_220 -> V_111 = V_111 ;
V_220 -> V_450 = V_447 ;
V_220 -> V_451 = V_445 ;
V_220 -> V_452 = V_446 ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_148 ( struct V_1 * V_2 , T_1 V_111 , T_2 * V_447 )
{
struct V_11 * V_12 ;
struct V_453 * V_220 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_454 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_111 = V_111 ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_455 * V_60 =
F_2 ( V_12 ) ;
* V_447 = V_60 -> V_450 ;
}
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_149 ( struct V_1 * V_2 ,
T_1 V_456 , T_1 * V_457 )
{
struct V_163 V_458 ;
struct V_11 * V_12 ;
struct V_459 * V_220 ;
int V_45 ;
if ( V_456 > V_460 )
return - V_461 ;
V_458 . V_202 = sizeof( struct V_462 ) ;
V_458 . V_167 = F_131 ( & V_2 -> V_69 -> V_70 , V_458 . V_202 , & V_458 . V_169 ,
V_368 ) ;
if ( ! V_458 . V_167 ) {
F_18 ( & V_2 -> V_69 -> V_70 , L_20 ) ;
return - V_369 ;
}
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_458 . V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_463 ,
V_458 . V_202 , V_12 , & V_458 ) ;
V_220 -> V_464 = F_80 ( V_2 -> V_91 ) ;
V_220 -> V_456 = F_80 ( V_456 ) ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_462 * V_60 = V_458 . V_167 ;
memcpy ( V_457 , V_60 -> V_465 , V_466 ) ;
}
V_182:
F_95 ( & V_2 -> V_212 ) ;
F_132 ( & V_2 -> V_69 -> V_70 , V_458 . V_202 , V_458 . V_167 , V_458 . V_169 ) ;
return V_45 ;
}
static int F_150 ( struct V_1 * V_2 ,
struct V_163 * V_458 , T_2 V_467 ,
T_2 V_468 , const char * V_469 ,
T_2 * V_470 , T_1 * V_471 ,
T_1 * V_472 )
{
struct V_11 * V_12 ;
struct V_473 * V_220 ;
struct V_474 * V_60 ;
void * V_258 = NULL ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
V_2 -> V_52 = 0 ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_475;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_50 ,
sizeof( struct V_473 ) , V_12 ,
NULL ) ;
V_258 = & V_220 -> V_228 ;
F_102 ( struct V_476 ,
V_477 , V_258 , V_467 ) ;
if ( V_467 == 0 )
F_102 ( struct V_476 ,
V_478 , V_258 , 1 ) ;
else
F_102 ( struct V_476 ,
V_478 , V_258 , 0 ) ;
F_81 ( V_258 , sizeof( V_220 -> V_228 ) ) ;
V_220 -> V_479 = F_80 ( V_468 ) ;
F_134 ( V_220 -> V_480 , V_469 , sizeof( V_220 -> V_480 ) ) ;
V_220 -> V_481 = F_80 ( 1 ) ;
V_220 -> V_360 = F_80 ( V_467 ) ;
V_220 -> V_482 = F_80 ( ( V_458 -> V_169 +
sizeof( struct V_473 ) )
& 0xFFFFFFFF ) ;
V_220 -> V_483 = F_80 ( F_68 ( V_458 -> V_169 +
sizeof( struct V_473 ) ) ) ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_475;
F_95 ( & V_2 -> V_212 ) ;
if ( ! F_151 ( & V_2 -> V_48 ,
F_152 ( 60000 ) ) )
V_45 = - V_185 ;
else
V_45 = V_2 -> V_52 ;
V_60 = F_2 ( V_12 ) ;
if ( ! V_45 ) {
* V_470 = F_8 ( V_60 -> V_484 ) ;
* V_471 = V_60 -> V_471 ;
} else {
* V_472 = V_60 -> V_485 ;
}
return V_45 ;
V_475:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_153 ( struct V_1 * V_2 )
{
T_1 V_465 [ V_466 ] ;
int V_45 ;
V_45 = F_149 ( V_2 , V_486 ,
V_465 ) ;
if ( ! V_45 ) {
switch ( V_2 -> V_73 . V_487 ) {
case V_488 :
V_2 -> V_73 . V_489 =
V_465 [ V_490 ] ;
break;
case V_491 :
V_2 -> V_73 . V_489 =
V_465 [ V_492 ] ;
break;
default:
V_2 -> V_73 . V_489 = 0 ;
break;
}
}
return V_45 ;
}
int F_154 ( struct V_1 * V_2 )
{
T_1 V_465 [ V_466 ] ;
int V_45 ;
V_45 = F_149 ( V_2 , V_486 ,
V_465 ) ;
if ( ! V_45 ) {
F_134 ( V_2 -> V_73 . V_493 , V_465 +
V_494 , V_495 - 1 ) ;
F_134 ( V_2 -> V_73 . V_496 ,
V_465 + V_497 ,
V_495 - 1 ) ;
}
return V_45 ;
}
static int F_155 ( struct V_1 * V_2 ,
const char * V_469 )
{
struct V_498 * V_220 ;
struct V_11 * V_12 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_499 ,
sizeof( * V_220 ) , V_12 , NULL ) ;
F_134 ( V_220 -> V_480 , V_469 , sizeof( V_220 -> V_480 ) ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_156 ( struct V_1 * V_2 , struct V_163 * V_458 ,
T_2 V_467 , T_2 V_468 , const char * V_469 ,
T_2 * V_500 , T_2 * V_478 , T_1 * V_472 )
{
struct V_11 * V_12 ;
struct V_501 * V_220 ;
struct V_502 * V_60 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_475;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_503 ,
sizeof( struct V_501 ) , V_12 ,
NULL ) ;
V_220 -> V_504 = F_80 ( V_467 ) ;
V_220 -> V_505 = F_80 ( V_468 ) ;
strcpy ( V_220 -> V_480 , V_469 ) ;
V_220 -> V_481 = F_80 ( 1 ) ;
V_220 -> V_360 = F_80 ( V_467 ) ;
V_220 -> V_482 = F_80 ( ( V_458 -> V_169 & 0xFFFFFFFF ) ) ;
V_220 -> V_483 = F_80 ( F_68 ( V_458 -> V_169 ) ) ;
V_45 = F_60 ( V_2 ) ;
V_60 = F_2 ( V_12 ) ;
if ( ! V_45 ) {
* V_500 = F_8 ( V_60 -> V_506 ) ;
* V_478 = F_8 ( V_60 -> V_478 ) ;
} else {
* V_472 = V_60 -> V_485 ;
}
V_475:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
static int F_157 ( struct V_1 * V_2 ,
struct V_163 * V_458 , T_2 V_507 ,
T_2 V_508 , T_2 V_509 , T_2 V_365 )
{
struct V_11 * V_12 ;
struct F_157 * V_220 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
V_2 -> V_52 = 0 ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_475;
}
V_220 = V_458 -> V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_40 , V_458 -> V_202 , V_12 ,
V_458 ) ;
V_220 -> V_334 . V_510 = F_80 ( V_507 ) ;
if ( V_507 == V_511 )
V_220 -> V_334 . V_363 = F_80 ( V_509 ) ;
V_220 -> V_334 . V_512 = F_80 ( V_508 ) ;
V_220 -> V_334 . V_513 = F_80 ( V_365 ) ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_475;
F_95 ( & V_2 -> V_212 ) ;
if ( ! F_151 ( & V_2 -> V_48 ,
F_152 ( 40000 ) ) )
V_45 = - V_185 ;
else
V_45 = V_2 -> V_52 ;
return V_45 ;
V_475:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
static int F_158 ( struct V_1 * V_2 , T_1 * V_514 ,
T_3 V_515 , T_2 V_509 , T_2 V_516 )
{
struct V_517 * V_220 ;
struct V_11 * V_12 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_518 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_334 . V_510 = F_80 ( V_515 ) ;
if ( V_515 == V_511 )
V_220 -> V_334 . V_363 = F_80 ( V_509 + V_516 ) ;
else
V_220 -> V_334 . V_363 = F_80 ( V_516 ) ;
V_220 -> V_334 . V_512 = F_80 ( V_519 ) ;
V_220 -> V_334 . V_513 = F_80 ( 0x4 ) ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 )
memcpy ( V_514 , V_220 -> V_520 , 4 ) ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
static bool F_159 ( struct V_1 * V_2 )
{
return ( V_2 -> V_73 . V_521 == V_522 &&
V_2 -> V_73 . V_487 == V_523 ) ;
}
static bool F_160 ( struct V_1 * V_2 ,
struct V_524 * V_525 , int type )
{
int V_5 = 0 , V_526 = 0 ;
struct V_527 * V_528 = NULL ;
if ( F_124 ( V_2 ) )
V_528 = (struct V_527 * ) V_525 ;
for ( V_5 = 0 ; V_5 < V_529 ; V_5 ++ ) {
if ( V_528 )
V_526 = F_8 ( V_528 -> V_530 [ V_5 ] . type ) ;
else
V_526 = F_8 ( V_525 -> V_530 [ V_5 ] . type ) ;
if ( V_526 == type )
return true ;
}
return false ;
}
static struct V_524 * F_161 ( struct V_1 * V_2 ,
int V_531 ,
const struct V_532 * V_533 )
{
struct V_524 * V_525 = NULL ;
const T_1 * V_534 = V_533 -> V_457 ;
V_534 += V_531 ;
while ( V_534 < ( V_533 -> V_457 + V_533 -> V_202 ) ) {
V_525 = (struct V_524 * ) V_534 ;
if ( ! memcmp ( V_535 , V_525 -> V_536 , sizeof( V_535 ) ) )
return V_525 ;
V_534 += 32 ;
}
return NULL ;
}
static int F_162 ( struct V_1 * V_2 , const T_1 * V_534 ,
T_2 V_509 , T_2 V_537 , int V_538 ,
T_3 V_515 , bool * V_539 )
{
T_2 V_516 ;
int V_45 ;
T_1 V_520 [ 4 ] ;
V_45 = F_158 ( V_2 , V_520 , V_515 , V_509 ,
V_537 - 4 ) ;
if ( V_45 )
return V_45 ;
V_516 = V_538 + V_509 + V_537 - 4 ;
if ( ! memcmp ( V_520 , V_534 + V_516 , 4 ) )
* V_539 = true ;
else
* V_539 = false ;
return V_45 ;
}
static int F_163 ( struct V_1 * V_2 , const T_1 * V_540 ,
struct V_163 * V_541 , int V_542 , int V_537 ,
T_2 V_509 )
{
T_2 V_543 , V_544 , V_545 = V_537 , V_546 = 0 ;
struct F_157 * V_220 = V_541 -> V_167 ;
int V_45 ;
while ( V_545 ) {
V_544 = F_164 ( T_2 , 32 * 1024 , V_545 ) ;
V_545 -= V_544 ;
if ( ! V_545 ) {
if ( V_542 == V_547 )
V_543 = V_548 ;
else
V_543 = V_549 ;
} else {
if ( V_542 == V_547 )
V_543 = V_550 ;
else
V_543 = V_551 ;
}
memcpy ( V_220 -> V_552 , V_540 , V_544 ) ;
V_540 += V_544 ;
V_45 = F_157 ( V_2 , V_541 , V_542 ,
V_543 , V_509 +
V_546 , V_544 ) ;
if ( V_34 ( V_45 ) == V_37 &&
V_542 == V_547 )
break;
else if ( V_45 )
return V_45 ;
V_546 += V_544 ;
}
return 0 ;
}
static bool F_165 ( char * V_223 )
{
int V_553 [ 4 ] = { 3 , 102 , 148 , 0 } ;
int V_554 [ 4 ] ;
int V_5 ;
if ( sscanf ( V_223 , L_21 , & V_554 [ 0 ] , & V_554 [ 1 ] , & V_554 [ 2 ] , & V_554 [ 3 ] ) != 4 )
return false ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
if ( V_553 [ V_5 ] < V_554 [ V_5 ] )
return true ;
else if ( V_553 [ V_5 ] > V_554 [ V_5 ] )
return false ;
}
return true ;
}
static int F_166 ( struct V_1 * V_2 ,
const struct V_532 * V_533 ,
struct V_163 * V_541 , int V_555 )
{
int V_556 = ( V_555 * sizeof( struct V_557 ) ) ;
struct V_86 * V_70 = & V_2 -> V_69 -> V_70 ;
struct V_524 * V_525 = NULL ;
int V_45 , V_5 , V_558 , V_559 ;
const struct V_560 * V_561 ;
bool V_539 ;
const T_1 * V_534 ;
struct V_560 V_562 [] = {
{ V_563 , V_564 ,
V_565 , V_566 } ,
{ V_567 , V_568 ,
V_569 , V_570 } ,
{ V_571 , V_572 ,
V_573 , V_574 } ,
{ V_575 , V_576 ,
V_573 , V_577 } ,
{ V_578 , V_579 ,
V_573 , V_580 } ,
{ V_581 , V_582 ,
V_565 , V_583 } ,
{ V_584 , V_585 ,
V_565 , V_586 } ,
{ V_587 , V_588 ,
V_565 , V_589 } ,
{ V_590 , V_591 ,
V_592 , V_593 } ,
{ V_594 , V_547 ,
V_595 , V_596 }
} ;
struct V_560 V_597 [] = {
{ V_598 , V_564 ,
V_599 , V_566 } ,
{ V_600 , V_568 ,
V_601 , V_570 } ,
{ V_602 , V_572 ,
V_603 , V_574 } ,
{ V_604 , V_576 ,
V_603 , V_577 } ,
{ V_605 , V_579 ,
V_603 , V_580 } ,
{ V_606 , V_582 ,
V_599 , V_583 } ,
{ V_607 , V_585 ,
V_599 , V_586 } ,
{ V_608 , V_588 ,
V_599 , V_589 }
} ;
if ( F_121 ( V_2 ) ) {
V_561 = V_562 ;
V_558 = sizeof( struct V_609 ) ;
V_559 = F_104 ( V_562 ) ;
} else {
V_561 = V_597 ;
V_558 = sizeof( struct V_610 ) ;
V_559 = F_104 ( V_597 ) ;
V_556 = 0 ;
}
V_525 = F_161 ( V_2 , V_558 + V_556 , V_533 ) ;
if ( ! V_525 ) {
F_18 ( V_70 , L_22 ) ;
return - 1 ;
}
for ( V_5 = 0 ; V_5 < V_559 ; V_5 ++ ) {
if ( ! F_160 ( V_2 , V_525 , V_561 [ V_5 ] . V_526 ) )
continue;
if ( ( V_561 [ V_5 ] . V_542 == V_591 ) &&
! F_165 ( V_2 -> V_378 ) ) {
F_31 ( V_70 , V_611 , V_2 -> V_378 ) ;
continue;
}
if ( V_561 [ V_5 ] . V_542 == V_547 &&
! F_159 ( V_2 ) )
continue;
if ( V_561 [ V_5 ] . V_542 == V_568 ) {
V_45 = F_162 ( V_2 , V_533 -> V_457 ,
V_561 [ V_5 ] . V_363 ,
V_561 [ V_5 ] . V_202 ,
V_558 +
V_556 ,
V_568 , & V_539 ) ;
if ( V_45 ) {
F_18 ( V_70 ,
L_23 ,
V_561 [ V_5 ] . V_542 ) ;
continue;
}
if ( V_539 )
continue;
}
V_534 = V_533 -> V_457 + V_558 + V_561 [ V_5 ] . V_363 +
V_556 ;
if ( V_534 + V_561 [ V_5 ] . V_202 > V_533 -> V_457 + V_533 -> V_202 )
return - 1 ;
V_45 = F_163 ( V_2 , V_534 , V_541 , V_561 [ V_5 ] . V_542 ,
V_561 [ V_5 ] . V_202 , 0 ) ;
if ( V_45 ) {
F_18 ( V_70 , L_24 ,
V_561 [ V_5 ] . V_526 ) ;
return V_45 ;
}
}
return 0 ;
}
static T_3 F_167 ( struct V_612 V_530 )
{
T_2 V_526 = F_8 ( V_530 . type ) ;
T_3 V_515 = F_29 ( V_530 . V_542 ) ;
if ( V_515 != 0xFFFF )
return V_515 ;
switch ( V_526 ) {
case V_566 :
V_515 = V_564 ;
break;
case V_570 :
V_515 = V_568 ;
break;
case V_574 :
V_515 = V_572 ;
break;
case V_577 :
V_515 = V_576 ;
break;
case V_580 :
V_515 = V_579 ;
break;
case V_583 :
V_515 = V_582 ;
break;
case V_593 :
V_515 = V_591 ;
break;
case V_613 :
V_515 = V_614 ;
break;
case V_596 :
V_515 = V_615 ;
break;
case V_616 :
V_515 = V_617 ;
break;
case V_618 :
V_515 = V_619 ;
break;
case V_620 :
V_515 = V_621 ;
break;
default:
break;
}
return V_515 ;
}
static int F_168 ( struct V_1 * V_2 ,
const struct V_532 * V_533 ,
struct V_163 * V_541 , int V_555 )
{
int V_556 = V_555 * sizeof( struct V_557 ) ;
bool V_539 , V_622 , V_623 = true ;
struct V_86 * V_70 = & V_2 -> V_69 -> V_70 ;
struct V_524 * V_525 = NULL ;
T_2 V_509 , V_537 , V_526 ;
T_3 V_515 , V_624 ;
int V_45 , V_5 , V_558 ;
const T_1 * V_534 ;
V_558 = sizeof( struct V_609 ) ;
V_525 = F_161 ( V_2 , V_558 + V_556 , V_533 ) ;
if ( ! V_525 ) {
F_18 ( V_70 , L_22 ) ;
return - V_461 ;
}
V_625:
for ( V_5 = 0 ; V_5 < F_8 ( V_525 -> V_626 . V_627 ) ; V_5 ++ ) {
V_509 = F_8 ( V_525 -> V_530 [ V_5 ] . V_363 ) ;
V_537 = F_8 ( V_525 -> V_530 [ V_5 ] . V_628 ) ;
V_526 = F_8 ( V_525 -> V_530 [ V_5 ] . type ) ;
V_515 = F_167 ( V_525 -> V_530 [ V_5 ] ) ;
V_622 = V_525 -> V_530 [ V_5 ] . V_542 == 0xFFFF ;
if ( V_515 == 0xFFFF )
continue;
if ( V_623 )
V_624 = V_511 ;
else
V_624 = V_515 ;
if ( V_622 )
goto V_629;
V_45 = F_162 ( V_2 , V_533 -> V_457 , V_509 ,
V_537 , V_558 +
V_556 , V_624 ,
& V_539 ) ;
if ( V_34 ( V_45 ) == V_37 ||
V_34 ( V_45 ) == V_41 ) {
if ( V_624 == V_511 ) {
V_623 = false ;
goto V_625;
}
F_18 ( V_70 , L_25 ) ;
F_18 ( V_70 , L_26 ) ;
return - V_630 ;
} else if ( V_45 ) {
F_18 ( V_70 , L_23 ,
V_515 ) ;
return - V_631 ;
}
if ( V_539 )
continue;
V_629:
V_534 = V_533 -> V_457 + V_558 + V_509 + V_556 ;
if ( V_534 + V_537 > V_533 -> V_457 + V_533 -> V_202 )
return - 1 ;
V_45 = F_163 ( V_2 , V_534 , V_541 , V_624 , V_537 ,
V_509 ) ;
if ( V_34 ( V_45 ) == V_41 &&
V_624 == V_511 ) {
V_623 = false ;
goto V_625;
}
if ( V_622 &&
( V_34 ( V_45 ) == V_41 ||
( V_515 == V_621 &&
V_34 ( V_45 ) == V_632 ) ) ) {
continue;
} else if ( V_45 ) {
F_18 ( V_70 , L_24 ,
V_526 ) ;
switch ( V_35 ( V_45 ) ) {
case V_633 :
F_18 ( V_70 ,
L_27 ) ;
return - V_461 ;
case V_634 :
F_18 ( V_70 ,
L_28 ) ;
return - V_461 ;
default:
return - V_631 ;
}
}
}
return 0 ;
}
int F_169 ( struct V_1 * V_2 ,
const struct V_532 * V_533 )
{
struct V_86 * V_70 = & V_2 -> V_69 -> V_70 ;
struct V_163 V_541 ;
const T_1 * V_635 = NULL ;
T_1 * V_636 = NULL ;
T_6 V_637 = 0 ;
T_2 V_638 = 0 ;
T_2 V_470 = 0 ;
T_2 V_363 = 0 ;
int V_45 = 0 ;
T_1 V_639 = 0 ;
T_1 V_471 ;
if ( ! F_170 ( V_533 -> V_202 , sizeof( T_2 ) ) ) {
F_18 ( V_70 , L_29 ) ;
return - V_461 ;
}
V_541 . V_202 = sizeof( struct V_473 )
+ V_640 ;
V_541 . V_167 = F_131 ( V_70 , V_541 . V_202 ,
& V_541 . V_169 , V_641 ) ;
if ( ! V_541 . V_167 )
return - V_369 ;
V_636 = V_541 . V_167 +
sizeof( struct V_473 ) ;
V_637 = V_533 -> V_202 ;
V_635 = V_533 -> V_457 ;
while ( V_637 ) {
V_638 = F_164 ( T_2 , V_637 , V_640 ) ;
memcpy ( V_636 , V_635 , V_638 ) ;
V_45 = F_150 ( V_2 , & V_541 ,
V_638 , V_363 ,
V_642 ,
& V_470 , & V_471 ,
& V_639 ) ;
if ( V_45 )
break;
V_363 += V_470 ;
V_635 += V_470 ;
V_637 -= V_470 ;
}
if ( ! V_45 ) {
V_45 = F_150 ( V_2 , & V_541 ,
0 , V_363 ,
V_642 ,
& V_470 , & V_471 ,
& V_639 ) ;
}
F_132 ( V_70 , V_541 . V_202 , V_541 . V_167 , V_541 . V_169 ) ;
if ( V_45 ) {
F_18 ( V_70 , L_30 ) ;
return F_171 ( V_45 ) ;
}
F_31 ( V_70 , L_31 ) ;
if ( V_471 == V_643 ) {
F_31 ( V_70 , L_32 ) ;
V_45 = F_172 ( V_2 ,
V_644 ) ;
if ( V_45 ) {
F_18 ( V_70 , L_33 ) ;
F_18 ( V_70 , L_34 ) ;
}
} else if ( V_471 != V_645 ) {
F_31 ( V_70 , L_34 ) ;
}
return 0 ;
}
static bool F_173 ( struct V_1 * V_2 ,
struct V_609 * V_646 )
{
if ( ! V_646 ) {
F_18 ( & V_2 -> V_69 -> V_70 , L_35 ) ;
return false ;
}
switch ( V_646 -> V_647 [ 0 ] ) {
case V_648 :
if ( ! F_174 ( V_2 ) )
return false ;
break;
case V_649 :
if ( ! F_121 ( V_2 ) )
return false ;
break;
case V_650 :
if ( ! F_124 ( V_2 ) )
return false ;
break;
default:
return false ;
}
if ( F_20 ( V_2 ) && V_646 -> V_651 == 0 )
return V_2 -> V_428 < 0x10 ;
else
return ( V_646 -> V_651 >= V_2 -> V_428 ) ;
}
int F_175 ( struct V_1 * V_2 , const struct V_532 * V_533 )
{
struct V_86 * V_70 = & V_2 -> V_69 -> V_70 ;
struct V_609 * V_652 ;
struct V_557 * V_653 ;
int V_45 = 0 , V_5 , V_654 ;
struct V_163 V_541 ;
V_652 = (struct V_609 * ) V_533 -> V_457 ;
if ( ! F_173 ( V_2 , V_652 ) ) {
F_18 ( V_70 , L_36 ) ;
return - V_461 ;
}
V_541 . V_202 = sizeof( struct F_157 ) ;
V_541 . V_167 = F_131 ( V_70 , V_541 . V_202 , & V_541 . V_169 ,
V_641 ) ;
if ( ! V_541 . V_167 )
return - V_369 ;
V_654 = F_8 ( V_652 -> V_654 ) ;
for ( V_5 = 0 ; V_5 < V_654 ; V_5 ++ ) {
V_653 = (struct V_557 * ) ( V_533 -> V_457 +
( sizeof( struct V_609 ) +
V_5 * sizeof( struct V_557 ) ) ) ;
if ( ! F_124 ( V_2 ) &&
F_8 ( V_653 -> V_655 ) != 1 )
continue;
if ( F_174 ( V_2 ) )
V_45 = F_168 ( V_2 , V_533 , & V_541 ,
V_654 ) ;
else
V_45 = F_166 ( V_2 , V_533 , & V_541 ,
V_654 ) ;
}
F_132 ( V_70 , V_541 . V_202 , V_541 . V_167 , V_541 . V_169 ) ;
if ( ! V_45 )
F_31 ( V_70 , L_31 ) ;
return V_45 ;
}
int F_176 ( struct V_1 * V_2 , T_1 * V_243 ,
struct V_163 * V_331 )
{
struct V_11 * V_12 ;
struct V_656 * V_220 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_331 -> V_167 ;
F_79 ( & V_220 -> V_224 , V_55 ,
V_657 , sizeof( * V_220 ) ,
V_12 , V_331 ) ;
memcpy ( V_220 -> V_658 , V_243 , V_244 ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_177 ( struct V_1 * V_2 , T_1 V_111 ,
T_1 V_659 , T_1 V_660 )
{
struct V_11 * V_12 ;
struct V_661 * V_220 ;
int V_45 ;
if ( ! F_1 ( V_2 , V_49 ,
V_47 ) )
return - V_250 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_475;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_47 ,
V_49 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_662 = V_111 ;
V_220 -> V_663 = V_111 ;
V_220 -> V_659 = V_659 ;
V_220 -> V_664 = V_660 ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_475;
F_95 ( & V_2 -> V_212 ) ;
if ( ! F_151 ( & V_2 -> V_48 ,
F_152 ( V_665 ) ) )
V_45 = - V_185 ;
return V_45 ;
V_475:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_178 ( struct V_1 * V_2 , T_2 V_111 ,
T_2 V_659 , T_2 V_666 , T_2 V_667 ,
T_5 V_668 )
{
struct V_11 * V_12 ;
struct V_669 * V_220 ;
struct V_670 * V_60 ;
int V_45 ;
if ( ! F_1 ( V_2 , V_46 ,
V_47 ) )
return - V_250 ;
F_92 ( & V_2 -> V_212 ) ;
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
V_220 -> V_668 = F_179 ( V_668 ) ;
V_220 -> V_662 = F_80 ( V_111 ) ;
V_220 -> V_663 = F_80 ( V_111 ) ;
V_220 -> V_666 = F_80 ( V_666 ) ;
V_220 -> V_667 = F_80 ( V_667 ) ;
V_220 -> V_659 = F_80 ( V_659 ) ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_182;
F_95 ( & V_2 -> V_212 ) ;
F_180 ( & V_2 -> V_48 ) ;
V_60 = F_2 ( V_12 ) ;
V_45 = F_8 ( V_60 -> V_45 ) ;
return V_45 ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_181 ( struct V_1 * V_2 , T_5 V_668 ,
T_2 V_671 , struct V_163 * V_458 )
{
struct V_11 * V_12 ;
struct V_672 * V_220 ;
int V_45 ;
int V_5 , V_673 = 0 ;
if ( ! F_1 ( V_2 , V_674 ,
V_47 ) )
return - V_250 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_458 -> V_167 ;
F_79 ( & V_220 -> V_224 , V_47 ,
V_674 , V_458 -> V_202 , V_12 ,
V_458 ) ;
V_220 -> V_668 = F_179 ( V_668 ) ;
V_220 -> V_675 = F_80 ( V_671 ) ;
for ( V_5 = 0 ; V_5 < V_671 ; V_5 ++ ) {
V_220 -> V_676 [ V_5 ] = ( T_1 ) ( V_668 >> ( V_673 * 8 ) ) ;
V_673 ++ ;
if ( V_673 > 7 )
V_673 = 0 ;
}
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_677 * V_60 ;
V_60 = V_458 -> V_167 ;
if ( ( memcmp ( V_60 -> V_678 , V_220 -> V_676 , V_671 ) != 0 ) ||
V_60 -> V_679 ) {
V_45 = - 1 ;
}
}
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_182 ( struct V_1 * V_2 ,
struct V_163 * V_331 )
{
struct V_11 * V_12 ;
struct V_680 * V_220 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_331 -> V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_681 , sizeof( * V_220 ) , V_12 ,
V_331 ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_183 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_682 * V_220 ;
struct V_163 V_458 ;
int V_45 ;
if ( ! F_1 ( V_2 , V_683 ,
V_51 ) )
return - V_250 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_458 . V_202 = sizeof( struct V_682 ) ;
V_458 . V_167 = F_131 ( & V_2 -> V_69 -> V_70 , V_458 . V_202 , & V_458 . V_169 ,
V_368 ) ;
if ( ! V_458 . V_167 ) {
F_18 ( & V_2 -> V_69 -> V_70 , L_37 ) ;
V_45 = - V_369 ;
goto V_182;
}
V_220 = V_458 . V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_683 , sizeof( * V_220 ) ,
V_12 , & V_458 ) ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_684 * V_685 =
V_458 . V_167 + sizeof( struct V_188 ) ;
V_2 -> V_73 . V_521 = F_29 ( V_685 -> V_521 ) ;
V_2 -> V_73 . V_487 =
F_29 ( V_685 -> V_487 ) ;
V_2 -> V_73 . V_686 =
F_29 ( V_685 -> V_686 ) ;
V_2 -> V_73 . V_687 =
F_29 ( V_685 -> V_687 ) ;
V_2 -> V_73 . V_688 =
F_8 ( V_685 -> V_688 ) ;
if ( F_124 ( V_2 ) ) {
V_2 -> V_73 . V_687 =
V_689 |
V_690 ;
}
}
F_132 ( & V_2 -> V_69 -> V_70 , V_458 . V_202 , V_458 . V_167 , V_458 . V_169 ) ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
static int F_184 ( struct V_1 * V_2 , T_2 V_691 , T_2 V_245 )
{
struct V_11 * V_12 ;
struct V_692 * V_220 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_693 , sizeof( * V_220 ) , V_12 , NULL ) ;
V_220 -> V_224 . V_245 = V_245 ;
V_220 -> V_694 = F_80 ( V_695 ) ;
V_220 -> V_696 = F_80 ( V_691 ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_185 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_697 * V_220 ;
struct V_698 * V_60 ;
int V_45 , V_5 ;
int V_367 = F_186 ( sizeof( * V_220 ) , sizeof( * V_60 ) ) ;
struct V_699 * V_700 ;
struct V_163 V_701 ;
T_2 * V_702 ;
if ( F_93 ( & V_2 -> V_213 ) )
return - 1 ;
memset ( & V_701 , 0 , sizeof( struct V_163 ) ) ;
V_701 . V_202 = sizeof( struct V_698 ) ;
V_701 . V_167 = F_131 ( & V_2 -> V_69 -> V_70 ,
V_701 . V_202 ,
& V_701 . V_169 , V_368 ) ;
if ( ! V_701 . V_167 ) {
F_18 ( & V_2 -> V_69 -> V_70 , L_38 ) ;
V_45 = - V_369 ;
goto V_182;
}
V_12 = F_85 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_701 . V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_703 , V_367 ,
V_12 , & V_701 ) ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
V_700 = V_701 . V_167 + sizeof( struct V_30 ) ;
V_2 -> V_91 = V_700 -> V_704 . V_705 ;
V_702 = V_700 -> V_704 . V_706 ;
for ( V_5 = 0 ; V_5 < V_707 ; V_5 ++ )
V_2 -> V_702 [ V_5 ] = F_8 ( V_702 [ V_5 ] ) &
( F_187 ( 16 ) - 1 ) ;
if ( F_20 ( V_2 ) )
V_2 -> V_708 = V_700 -> V_704 . V_709 ;
}
V_182:
F_95 ( & V_2 -> V_213 ) ;
if ( V_701 . V_167 )
F_132 ( & V_2 -> V_69 -> V_70 , V_701 . V_202 ,
V_701 . V_167 , V_701 . V_169 ) ;
return V_45 ;
}
int F_188 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_710 * V_220 ;
int V_45 ;
if ( F_93 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_711 ,
sizeof( * V_220 ) , V_12 , NULL ) ;
V_220 -> V_712 = F_80 ( V_713 |
V_714 ) ;
V_220 -> V_321 = F_80 ( V_714 ) ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_715 * V_60 = F_2 ( V_12 ) ;
V_2 -> V_716 = F_8 ( V_60 -> V_321 ) &
V_714 ;
if ( ! V_2 -> V_716 )
F_17 ( & V_2 -> V_69 -> V_70 ,
L_39 ) ;
}
V_182:
F_95 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_189 ( struct V_1 * V_2 , T_2 * V_717 ,
T_2 V_245 )
{
struct V_11 * V_12 ;
struct V_718 * V_220 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_719 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_224 . V_245 = V_245 ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_720 * V_60 =
F_2 ( V_12 ) ;
* V_717 = F_8 ( V_60 -> V_721 ) ;
if ( F_20 ( V_2 ) && F_190 ( V_2 ) &&
F_191 ( V_2 ) )
* V_717 = V_722 ;
}
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_192 ( struct V_1 * V_2 , T_2 V_723 ,
T_2 V_245 )
{
struct V_11 * V_12 ;
struct V_724 * V_220 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_725 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_224 . V_245 = V_245 ;
if ( F_74 ( V_2 ) )
V_220 -> V_726 = F_80 ( V_723 ) ;
else
V_220 -> V_723 = F_80 ( V_723 ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_193 ( struct V_1 * V_2 , T_1 * V_243 ,
bool * V_727 , T_2 * V_237 , T_2 V_236 ,
T_1 V_245 )
{
struct V_11 * V_12 ;
struct V_728 * V_220 ;
int V_45 ;
int V_729 ;
struct V_163 V_730 ;
int V_5 ;
memset ( & V_730 , 0 , sizeof( struct V_163 ) ) ;
V_730 . V_202 = sizeof( struct V_731 ) ;
V_730 . V_167 = F_131 ( & V_2 -> V_69 -> V_70 ,
V_730 . V_202 ,
& V_730 . V_169 ,
V_368 ) ;
if ( ! V_730 . V_167 ) {
F_18 ( & V_2 -> V_69 -> V_70 ,
L_40 ) ;
return - V_369 ;
}
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_156;
}
V_220 = V_730 . V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_732 ,
V_730 . V_202 , V_12 , & V_730 ) ;
V_220 -> V_224 . V_245 = V_245 ;
V_220 -> V_733 = V_240 ;
if ( * V_727 ) {
V_220 -> V_734 = F_80 ( * V_237 ) ;
V_220 -> V_735 = F_101 ( V_236 ) ;
V_220 -> V_736 = 0 ;
} else {
V_220 -> V_736 = 1 ;
}
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_731 * V_60 =
V_730 . V_167 ;
if ( * V_727 ) {
memcpy ( V_243 , V_60 -> V_737 . V_738 . V_739 ,
V_244 ) ;
goto V_156;
}
V_729 = V_60 -> V_740 + V_60 -> V_741 ;
for ( V_5 = 0 ; V_5 < V_729 ; V_5 ++ ) {
struct V_742 * V_743 ;
T_3 V_744 ;
T_2 V_734 ;
V_743 = & V_60 -> V_745 [ V_5 ] ;
V_744 = F_29 ( V_743 -> V_744 ) ;
if ( V_744 == sizeof( T_2 ) ) {
* V_727 = true ;
V_734 = V_743 -> V_738 . V_746 . V_734 ;
* V_237 = F_8 ( V_734 ) ;
goto V_156;
}
}
* V_727 = false ;
memcpy ( V_243 , V_60 -> V_745 [ 0 ] . V_738 . V_739 ,
V_244 ) ;
}
V_156:
F_95 ( & V_2 -> V_212 ) ;
F_132 ( & V_2 -> V_69 -> V_70 , V_730 . V_202 ,
V_730 . V_167 , V_730 . V_169 ) ;
return V_45 ;
}
int F_194 ( struct V_1 * V_2 , T_2 V_747 ,
T_1 * V_243 , T_2 V_236 , bool V_748 , T_2 V_245 )
{
if ( ! V_748 )
F_193 ( V_2 , V_243 , & V_748 , & V_747 ,
V_236 , V_245 ) ;
if ( F_20 ( V_2 ) )
return F_105 ( V_2 , V_243 , false ,
V_236 , V_747 ) ;
else
return F_193 ( V_2 , V_243 , & V_748 ,
& V_747 ,
V_236 , V_245 ) ;
}
int F_195 ( struct V_1 * V_2 , T_1 * V_243 )
{
int V_45 ;
bool V_749 = false ;
F_196 ( V_243 ) ;
if ( F_20 ( V_2 ) ) {
if ( F_191 ( V_2 ) )
V_45 = F_105 ( V_2 , V_243 , true , 0 ,
0 ) ;
else
V_45 = F_105 ( V_2 , V_243 , false ,
V_2 -> V_236 , 0 ) ;
} else {
V_45 = F_193 ( V_2 , V_243 , & V_749 ,
NULL , V_2 -> V_236 , 0 ) ;
}
return V_45 ;
}
int F_197 ( struct V_1 * V_2 , T_1 * V_750 ,
T_1 V_729 , T_2 V_245 )
{
struct V_11 * V_12 ;
struct V_751 * V_220 ;
int V_45 ;
struct V_163 V_458 ;
memset ( & V_458 , 0 , sizeof( struct V_163 ) ) ;
V_458 . V_202 = sizeof( struct V_751 ) ;
V_458 . V_167 = F_131 ( & V_2 -> V_69 -> V_70 , V_458 . V_202 , & V_458 . V_169 ,
V_641 ) ;
if ( ! V_458 . V_167 )
return - V_369 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_458 . V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_752 , sizeof( * V_220 ) ,
V_12 , & V_458 ) ;
V_220 -> V_224 . V_245 = V_245 ;
V_220 -> V_729 = V_729 ;
if ( V_729 )
memcpy ( V_220 -> V_243 , V_750 , V_244 * V_729 ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_132 ( & V_2 -> V_69 -> V_70 , V_458 . V_202 , V_458 . V_167 , V_458 . V_169 ) ;
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_198 ( struct V_1 * V_2 , T_1 * V_243 , int V_241 , T_2 V_251 )
{
bool V_753 = false ;
T_1 V_754 [ V_244 ] ;
T_2 V_237 ;
int V_45 ;
V_45 = F_193 ( V_2 , V_754 , & V_753 ,
& V_237 , V_241 , V_251 ) ;
if ( ! V_45 && V_753 )
F_107 ( V_2 , V_241 , V_237 , V_251 ) ;
return F_197 ( V_2 , V_243 , V_243 ? 1 : 0 , V_251 ) ;
}
int F_199 ( struct V_1 * V_2 , T_3 V_115 ,
T_2 V_245 , T_3 V_755 , T_3 V_756 , T_1 V_757 )
{
struct V_11 * V_12 ;
struct V_758 * V_220 ;
void * V_258 ;
int V_45 ;
if ( ! F_1 ( V_2 , V_759 ,
V_51 ) )
return - V_250 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
V_258 = & V_220 -> V_228 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_759 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_220 -> V_224 . V_245 = V_245 ;
F_102 ( struct V_760 , V_303 , V_258 , V_755 ) ;
if ( V_115 ) {
F_102 ( struct V_760 , V_761 , V_258 , 1 ) ;
F_102 ( struct V_760 , V_115 , V_258 , V_115 ) ;
}
if ( V_756 ) {
F_102 ( struct V_760 , V_303 ,
V_258 , V_2 -> V_91 ) ;
F_102 ( struct V_760 , V_762 , V_258 , 1 ) ;
F_102 ( struct V_760 , V_763 ,
V_258 , V_756 ) ;
}
if ( ! F_20 ( V_2 ) && V_757 ) {
F_102 ( struct V_760 , V_764 ,
V_258 , V_757 ) ;
F_102 ( struct V_760 , V_765 ,
V_258 , V_757 ) ;
}
F_81 ( V_220 -> V_228 , sizeof( V_220 -> V_228 ) ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_200 ( struct V_1 * V_2 , T_3 * V_115 ,
T_2 V_245 , T_3 V_755 , T_1 * V_766 , bool * V_757 )
{
struct V_11 * V_12 ;
struct V_767 * V_220 ;
void * V_258 ;
int V_45 ;
T_3 V_768 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
V_258 = & V_220 -> V_228 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_769 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
V_220 -> V_224 . V_245 = V_245 ;
F_102 ( struct V_770 , V_303 ,
V_258 , V_755 ) ;
F_102 ( struct V_770 , V_761 , V_258 , 1 ) ;
if ( ! F_20 ( V_2 ) && V_766 ) {
F_102 ( struct V_770 , V_303 ,
V_258 , V_2 -> V_91 ) ;
F_102 ( struct V_770 , V_762 , V_258 , 1 ) ;
}
F_81 ( V_220 -> V_228 , sizeof( V_220 -> V_228 ) ) ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
struct V_771 * V_60 =
F_2 ( V_12 ) ;
F_16 ( & V_60 -> V_228 , sizeof( V_60 -> V_228 ) ) ;
V_768 = F_201 ( struct V_772 ,
V_115 , & V_60 -> V_228 ) ;
if ( V_115 )
* V_115 = F_29 ( V_768 ) ;
if ( V_766 )
* V_766 = F_201 ( struct V_772 ,
V_763 , & V_60 -> V_228 ) ;
if ( V_757 )
* V_757 =
F_201 ( struct V_772 ,
V_757 , & V_60 -> V_228 ) ;
}
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
static bool F_202 ( struct V_1 * V_2 )
{
struct V_773 * V_69 = V_2 -> V_69 ;
if ( F_75 ( V_2 ) )
return true ;
switch ( V_69 -> V_774 ) {
case V_775 :
case V_776 :
case V_777 :
case V_778 :
return true ;
default:
return false ;
}
}
int F_203 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_779 * V_220 ;
int V_45 = 0 ;
struct V_163 V_458 ;
if ( ! F_1 ( V_2 , V_657 ,
V_55 ) )
return - V_250 ;
if ( F_202 ( V_2 ) )
return V_45 ;
if ( F_93 ( & V_2 -> V_213 ) )
return - 1 ;
memset ( & V_458 , 0 , sizeof( struct V_163 ) ) ;
V_458 . V_202 = sizeof( struct V_780 ) ;
V_458 . V_167 = F_131 ( & V_2 -> V_69 -> V_70 , V_458 . V_202 , & V_458 . V_169 ,
V_368 ) ;
if ( ! V_458 . V_167 ) {
F_18 ( & V_2 -> V_69 -> V_70 , L_38 ) ;
V_45 = - V_369 ;
goto V_182;
}
V_12 = F_85 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_458 . V_167 ;
F_79 ( & V_220 -> V_224 , V_55 ,
V_657 ,
sizeof( * V_220 ) , V_12 , & V_458 ) ;
V_220 -> V_224 . V_194 = 1 ;
V_220 -> V_781 = V_782 ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_780 * V_60 ;
V_60 = (struct V_780 * ) V_458 . V_167 ;
V_2 -> V_783 = V_60 -> V_784 ;
if ( V_2 -> V_783 & V_785 &&
! F_204 ( V_60 -> V_658 ) )
V_2 -> V_786 = true ;
}
V_182:
F_95 ( & V_2 -> V_213 ) ;
if ( V_458 . V_167 )
F_132 ( & V_2 -> V_69 -> V_70 , V_458 . V_202 , V_458 . V_167 ,
V_458 . V_169 ) ;
return V_45 ;
}
int F_205 ( struct V_1 * V_2 , T_2 V_787 )
{
struct V_163 V_788 ;
struct V_789 * V_790 ;
int V_45 ;
int V_5 , V_673 ;
memset ( & V_788 , 0 , sizeof( struct V_163 ) ) ;
V_788 . V_202 = sizeof( struct V_791 ) ;
V_788 . V_167 = F_131 ( & V_2 -> V_69 -> V_70 ,
V_788 . V_202 , & V_788 . V_169 ,
V_368 ) ;
if ( ! V_788 . V_167 )
return - V_369 ;
V_45 = F_206 ( V_2 , & V_788 ) ;
if ( V_45 )
goto V_182;
V_790 = (struct V_789 * )
( V_788 . V_167 + sizeof( struct V_30 ) ) ;
for ( V_5 = 0 ; V_5 < F_8 ( V_790 -> V_792 ) ; V_5 ++ ) {
T_2 V_793 = F_8 ( V_790 -> V_794 [ V_5 ] . V_793 ) ;
for ( V_673 = 0 ; V_673 < V_793 ; V_673 ++ ) {
if ( V_790 -> V_794 [ V_5 ] . V_795 [ V_673 ] . V_766 == V_796 )
V_790 -> V_794 [ V_5 ] . V_795 [ V_673 ] . V_797 =
F_80 ( V_787 ) ;
}
}
V_45 = F_207 ( V_2 , & V_788 , V_790 ) ;
V_182:
F_132 ( & V_2 -> V_69 -> V_70 , V_788 . V_202 , V_788 . V_167 ,
V_788 . V_169 ) ;
return V_45 ;
}
int F_208 ( struct V_1 * V_2 )
{
struct V_163 V_788 ;
struct V_789 * V_790 ;
int V_45 , V_673 ;
int V_787 = 0 ;
memset ( & V_788 , 0 , sizeof( struct V_163 ) ) ;
V_788 . V_202 = sizeof( struct V_791 ) ;
V_788 . V_167 = F_131 ( & V_2 -> V_69 -> V_70 ,
V_788 . V_202 , & V_788 . V_169 ,
V_368 ) ;
if ( ! V_788 . V_167 ) {
F_18 ( & V_2 -> V_69 -> V_70 , L_41 ,
V_798 ) ;
goto V_182;
}
V_45 = F_206 ( V_2 , & V_788 ) ;
if ( ! V_45 ) {
V_790 = (struct V_789 * ) ( V_788 . V_167 +
sizeof( struct V_30 ) ) ;
for ( V_673 = 0 ; V_673 < F_8 ( V_790 -> V_794 [ 0 ] . V_793 ) ; V_673 ++ ) {
if ( V_790 -> V_794 [ 0 ] . V_795 [ V_673 ] . V_766 == V_796 )
V_787 = V_790 -> V_794 [ 0 ] . V_795 [ V_673 ] . V_797 ;
}
}
F_132 ( & V_2 -> V_69 -> V_70 , V_788 . V_202 , V_788 . V_167 ,
V_788 . V_169 ) ;
V_182:
return V_787 ;
}
int F_206 ( struct V_1 * V_2 ,
struct V_163 * V_458 )
{
struct V_11 * V_12 ;
struct V_799 * V_220 ;
int V_45 ;
if ( ! F_1 ( V_2 , V_800 ,
V_51 ) )
return - V_250 ;
if ( F_93 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_458 -> V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_800 ,
V_458 -> V_202 , V_12 , V_458 ) ;
V_220 -> V_801 = F_80 ( 1 ) ;
V_45 = F_67 ( V_2 ) ;
V_182:
F_95 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_207 ( struct V_1 * V_2 ,
struct V_163 * V_458 ,
struct V_789 * V_802 )
{
struct V_11 * V_12 ;
struct V_803 * V_220 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_458 -> V_167 ;
memcpy ( & V_220 -> V_804 , V_802 , sizeof( struct V_789 ) ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_805 ,
V_458 -> V_202 , V_12 , V_458 ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_209 ( struct V_1 * V_2 )
{
struct V_806 * V_220 ;
struct V_11 * V_12 ;
int V_45 ;
if ( F_93 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_807 , sizeof( * V_220 ) , V_12 ,
NULL ) ;
if ( ! F_20 ( V_2 ) )
V_220 -> V_224 . V_194 = 1 ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_808 * V_60 = F_2 ( V_12 ) ;
V_2 -> V_98 = V_60 -> V_98 [ V_2 -> V_91 ] ;
} else {
V_2 -> V_98 = V_2 -> V_91 + '0' ;
}
F_95 ( & V_2 -> V_213 ) ;
return V_45 ;
}
static struct V_809 * F_210 ( T_1 * V_361 , T_2 V_810 ,
bool V_811 , T_1 V_708 )
{
struct V_812 * V_224 = (struct V_812 * ) V_361 ;
struct V_809 * V_813 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_810 ; V_5 ++ ) {
if ( V_224 -> V_814 == V_815 ||
V_224 -> V_814 == V_816 ) {
V_813 = (struct V_809 * ) V_224 ;
if ( ( V_708 == V_817 ||
V_813 -> V_708 == V_708 ) &&
( ! V_811 || V_813 -> V_28 & F_112 ( V_818 ) ) )
return V_813 ;
}
V_224 -> V_819 = V_224 -> V_819 ? : V_820 ;
V_224 = ( void * ) V_224 + V_224 -> V_819 ;
}
return NULL ;
}
static struct V_809 * F_211 ( T_1 * V_361 , T_2 V_810 ,
T_1 V_708 )
{
return F_210 ( V_361 , V_810 , true , V_708 ) ;
}
static struct V_809 * F_212 ( T_1 * V_361 , T_2 V_810 ,
T_1 V_708 )
{
return F_210 ( V_361 , V_810 , false , V_708 ) ;
}
static struct V_821 * F_213 ( T_1 * V_361 , T_2 V_810 ,
T_1 V_708 )
{
struct V_812 * V_224 = (struct V_812 * ) V_361 ;
struct V_821 * V_822 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_810 ; V_5 ++ ) {
if ( V_224 -> V_814 == V_823 ||
V_224 -> V_814 == V_824 ) {
V_822 = (struct V_821 * ) V_224 ;
if ( V_822 -> V_708 == V_708 )
return V_822 ;
}
V_224 -> V_819 = V_224 -> V_819 ? : V_820 ;
V_224 = ( void * ) V_224 + V_224 -> V_819 ;
}
return NULL ;
}
static struct V_825 * F_214 ( T_1 * V_361 , T_2 V_810 )
{
struct V_812 * V_224 = (struct V_812 * ) V_361 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_810 ; V_5 ++ ) {
if ( V_224 -> V_814 == V_826 )
return (struct V_825 * ) V_224 ;
V_224 -> V_819 = V_224 -> V_819 ? : V_820 ;
V_224 = ( void * ) V_224 + V_224 -> V_819 ;
}
return NULL ;
}
static void F_215 ( struct V_827 * V_828 ,
struct V_809 * V_829 )
{
V_828 -> V_830 = F_29 ( V_829 -> V_831 ) ;
V_828 -> V_832 = F_29 ( V_829 -> V_833 ) ;
V_828 -> V_834 = F_29 ( V_829 -> V_835 ) ;
V_828 -> V_836 = F_29 ( V_829 -> V_837 ) ;
V_828 -> V_838 = F_29 ( V_829 -> V_839 ) ;
V_828 -> V_840 = F_29 ( V_829 -> V_841 ) ;
V_828 -> V_842 = F_29 ( V_829 -> V_843 ) ;
V_828 -> V_844 = F_29 ( V_829 -> V_845 ) ;
V_828 -> V_846 = F_29 ( V_829 -> V_847 ) ;
V_828 -> V_848 = F_29 ( V_829 -> V_849 ) ;
V_828 -> V_850 = F_8 ( V_829 -> V_321 ) &
V_851 ;
}
int F_216 ( struct V_1 * V_2 , struct V_827 * V_828 )
{
struct V_11 * V_12 ;
struct V_852 * V_220 ;
int V_45 ;
struct V_163 V_458 ;
if ( F_93 ( & V_2 -> V_213 ) )
return - 1 ;
memset ( & V_458 , 0 , sizeof( struct V_163 ) ) ;
V_458 . V_202 = sizeof( struct V_853 ) ;
V_458 . V_167 = F_131 ( & V_2 -> V_69 -> V_70 , V_458 . V_202 , & V_458 . V_169 ,
V_368 ) ;
if ( ! V_458 . V_167 ) {
F_18 ( & V_2 -> V_69 -> V_70 , L_37 ) ;
V_45 = - V_369 ;
goto V_182;
}
V_12 = F_85 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = V_458 . V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_854 ,
V_458 . V_202 , V_12 , & V_458 ) ;
if ( F_174 ( V_2 ) )
V_220 -> V_224 . V_194 = 1 ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_853 * V_60 = V_458 . V_167 ;
T_2 V_810 = F_8 ( V_60 -> V_810 ) ;
struct V_809 * V_829 ;
V_829 = F_212 ( V_60 -> V_855 , V_810 ,
V_817 ) ;
if ( ! V_829 ) {
V_45 = - V_461 ;
goto V_182;
}
V_2 -> V_708 = V_829 -> V_708 ;
V_2 -> V_856 = V_829 -> V_856 ;
if ( V_828 )
F_215 ( V_828 , V_829 ) ;
}
V_182:
F_95 ( & V_2 -> V_213 ) ;
if ( V_458 . V_167 )
F_132 ( & V_2 -> V_69 -> V_70 , V_458 . V_202 , V_458 . V_167 ,
V_458 . V_169 ) ;
return V_45 ;
}
static T_3 F_217 ( T_1 * V_361 , T_2 V_810 , T_3 * V_857 )
{
struct V_812 * V_224 = (struct V_812 * ) V_361 ;
struct V_821 * V_822 = NULL ;
int V_5 ;
T_3 V_858 = 0 ;
for ( V_5 = 0 ; V_5 < V_810 ; V_5 ++ ) {
if ( V_224 -> V_814 == V_823 ||
V_224 -> V_814 == V_824 ) {
V_822 = (struct V_821 * ) V_224 ;
if ( V_822 -> V_859 && ( V_822 -> V_860 == V_861 ||
V_822 -> V_860 == V_862 ) ) {
V_857 [ V_858 ++ ] = V_822 -> V_708 ;
}
}
V_224 -> V_819 = V_224 -> V_819 ? : V_820 ;
V_224 = ( void * ) V_224 + V_224 -> V_819 ;
}
return V_858 ;
}
int F_218 ( struct V_1 * V_2 ,
struct V_827 * V_828 ,
struct V_863 * V_864 ,
T_1 V_865 , T_1 V_866 , T_1 V_245 )
{
struct V_867 * V_60 ;
struct V_868 * V_220 ;
struct V_809 * V_869 ;
struct V_821 * V_822 ;
struct V_825 * V_464 ;
struct V_809 * V_813 ;
struct V_11 V_12 = { 0 } ;
struct V_163 V_458 ;
T_3 V_810 ;
int V_45 ;
memset ( & V_458 , 0 , sizeof( struct V_163 ) ) ;
V_458 . V_202 = sizeof( struct V_867 ) ;
V_458 . V_167 = F_131 ( & V_2 -> V_69 -> V_70 , V_458 . V_202 , & V_458 . V_169 ,
V_368 ) ;
if ( ! V_458 . V_167 )
return - V_369 ;
V_220 = V_458 . V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_870 ,
V_458 . V_202 , & V_12 , & V_458 ) ;
if ( ! F_74 ( V_2 ) )
V_220 -> V_224 . V_194 = 1 ;
V_220 -> type = V_865 ;
V_220 -> V_224 . V_245 = V_245 ;
if ( V_866 == V_871 )
V_220 -> type |= V_872 ;
V_45 = F_97 ( V_2 , & V_12 ) ;
if ( V_45 )
goto V_182;
V_60 = V_458 . V_167 ;
V_810 = F_29 ( V_60 -> V_810 ) ;
if ( V_864 ) {
T_3 V_873 = 0 , V_5 ;
T_3 V_874 [ V_875 ] ;
V_873 = F_217 ( V_60 -> V_855 ,
V_810 ,
V_874 ) ;
for ( V_5 = 0 ; V_5 < V_873 ; V_5 ++ ) {
V_813 = F_212 ( V_60 -> V_855 , V_810 ,
V_874 [ V_5 ] ) ;
if ( V_813 -> V_876 == V_2 -> V_111 ) {
V_864 -> V_877 ++ ;
V_822 = F_213 ( V_60 -> V_855 ,
V_810 ,
V_874 [ V_5 ] ) ;
V_864 -> V_878 += F_29 ( V_822 -> V_879 ) ;
}
}
return V_45 ;
}
V_822 = F_213 ( V_60 -> V_855 , V_810 ,
V_2 -> V_708 ) ;
if ( V_822 )
V_828 -> V_878 = F_29 ( V_822 -> V_879 ) ;
V_464 = F_214 ( V_60 -> V_855 , V_810 ) ;
if ( V_464 )
V_2 -> V_880 = V_464 -> V_880 ;
V_813 = F_212 ( V_60 -> V_855 , V_810 ,
V_2 -> V_708 ) ;
if ( V_813 )
F_215 ( V_828 , V_813 ) ;
V_869 = F_211 ( V_60 -> V_855 , V_810 ,
V_2 -> V_708 ) ;
if ( V_869 )
V_828 -> V_881 = V_869 -> V_321 ;
V_182:
if ( V_458 . V_167 )
F_132 ( & V_2 -> V_69 -> V_70 , V_458 . V_202 , V_458 . V_167 ,
V_458 . V_169 ) ;
return V_45 ;
}
static int F_219 ( struct V_1 * V_2 , void * V_829 ,
int V_202 , int V_229 , T_1 V_194 , T_1 V_245 )
{
struct V_882 * V_220 ;
struct V_11 V_12 = { 0 } ;
struct V_163 V_458 ;
int V_45 ;
memset ( & V_458 , 0 , sizeof( struct V_163 ) ) ;
V_458 . V_202 = sizeof( struct V_882 ) ;
V_458 . V_167 = F_131 ( & V_2 -> V_69 -> V_70 , V_458 . V_202 , & V_458 . V_169 ,
V_368 ) ;
if ( ! V_458 . V_167 )
return - V_369 ;
V_220 = V_458 . V_167 ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_883 , V_458 . V_202 ,
& V_12 , & V_458 ) ;
V_220 -> V_224 . V_194 = V_194 ;
V_220 -> V_224 . V_245 = V_245 ;
V_220 -> V_810 = F_80 ( V_229 ) ;
memcpy ( V_220 -> V_829 , V_829 , V_202 ) ;
V_45 = F_97 ( V_2 , & V_12 ) ;
if ( V_458 . V_167 )
F_132 ( & V_2 -> V_69 -> V_70 , V_458 . V_202 , V_458 . V_167 ,
V_458 . V_169 ) ;
return V_45 ;
}
static void F_220 ( struct V_809 * V_813 )
{
memset ( V_813 , 0 , sizeof( * V_813 ) ) ;
V_813 -> V_831 = 0xFFFF ;
V_813 -> V_849 = 0xFFFF ;
V_813 -> V_833 = 0xFFFF ;
V_813 -> V_835 = 0xFFFF ;
V_813 -> V_837 = 0xFFFF ;
V_813 -> V_841 = 0xFFFF ;
V_813 -> V_839 = 0xFFFF ;
V_813 -> V_884 = 0xFFFF ;
V_813 -> V_845 = 0xFFFF ;
V_813 -> V_885 = 0xFFFF ;
V_813 -> V_843 = 0xFFFF ;
V_813 -> V_847 = 0xFFFF ;
V_813 -> V_876 = 0xFF ;
V_813 -> V_886 = F_101 ( 0xF000 ) ;
V_813 -> V_887 = 0xFF ;
V_813 -> V_888 = 0x0F ;
V_813 -> V_889 = 0xFFFF ;
V_813 -> V_890 = 0xFFFF ;
V_813 -> V_891 = 0xFFFFFFFF ;
V_813 -> V_892 = 0xFFFFFFFF ;
}
static void F_221 ( struct V_821 * V_822 )
{
memset ( V_822 , 0 , sizeof( * V_822 ) ) ;
V_822 -> V_893 = 0xFF ;
V_822 -> V_859 = 0xFF ;
V_822 -> V_860 = 0xFF ;
V_822 -> V_879 = 0xFFFF ;
}
int F_222 ( struct V_1 * V_2 , T_2 V_894 , T_3 V_74 ,
T_1 V_245 )
{
struct V_809 V_895 ;
T_2 V_896 ;
T_3 V_194 = 0 ;
if ( F_121 ( V_2 ) )
return F_184 ( V_2 , V_894 / 10 , V_245 ) ;
F_220 ( & V_895 ) ;
V_895 . V_708 = V_2 -> V_708 ;
V_895 . V_856 = V_245 ;
V_895 . V_891 = 0 ;
if ( F_74 ( V_2 ) ) {
V_895 . V_224 . V_814 = V_815 ;
V_895 . V_224 . V_819 = V_820 ;
V_895 . V_28 = ( 1 << V_897 ) | ( 1 << V_898 ) |
( 1 << V_899 ) ;
V_895 . V_892 = F_80 ( V_894 / 10 ) ;
} else {
V_194 = 1 ;
V_895 . V_224 . V_814 = V_816 ;
V_895 . V_224 . V_819 = V_900 ;
V_895 . V_28 = ( 1 << V_898 ) | ( 1 << V_899 ) ;
V_896 = V_894 ? ( V_894 * 100 ) / V_74 : 100 ;
V_895 . V_892 = F_80 ( V_896 ) ;
}
return F_219 ( V_2 , & V_895 ,
V_895 . V_224 . V_819 ,
1 , V_194 , V_245 ) ;
}
int F_223 ( struct V_1 * V_2 ,
struct V_827 V_901 , T_3 V_879 ,
struct V_827 * V_902 )
{
struct {
struct V_821 V_822 ;
struct V_809 V_903 ;
} V_904 V_829 ;
F_221 ( & V_829 . V_822 ) ;
V_829 . V_822 . V_224 . V_814 = V_824 ;
V_829 . V_822 . V_224 . V_819 = V_900 ;
V_829 . V_822 . V_28 = F_112 ( V_898 ) | F_112 ( V_899 ) ;
V_829 . V_822 . V_708 = V_2 -> V_69 -> V_905 ;
V_829 . V_822 . V_893 = V_879 ? 1 : 0 ;
V_829 . V_822 . V_879 = F_101 ( V_879 ) ;
F_220 ( & V_829 . V_903 ) ;
V_829 . V_903 . V_224 . V_814 = V_816 ;
V_829 . V_903 . V_224 . V_819 = V_900 ;
V_829 . V_903 . V_28 = V_902 -> V_28 | F_112 ( V_818 ) |
F_112 ( V_898 ) | F_112 ( V_899 ) ;
V_829 . V_903 . V_708 = V_2 -> V_69 -> V_905 ;
V_829 . V_903 . V_856 = 0 ;
V_829 . V_903 . V_321 = F_80 ( V_902 -> V_881 ) ;
V_829 . V_903 . V_841 = F_101 ( V_902 -> V_840 ) ;
V_829 . V_903 . V_837 = F_101 ( V_902 -> V_836 ) ;
V_829 . V_903 . V_839 = F_101 ( V_902 -> V_838 ) ;
V_829 . V_903 . V_845 = F_101 ( V_902 -> V_844 ) ;
if ( V_902 -> V_830 )
V_829 . V_903 . V_831 =
F_101 ( V_902 -> V_830 ) ;
if ( V_902 -> V_832 )
V_829 . V_903 . V_833 = F_101 ( V_902 -> V_832 ) ;
if ( V_902 -> V_846 )
V_829 . V_903 . V_847 =
F_101 ( V_902 -> V_846 ) ;
if ( V_902 -> V_848 )
V_829 . V_903 . V_849 = F_101 ( V_902 -> V_848 ) ;
return F_219 ( V_2 , & V_829 ,
2 * V_900 , 2 , 1 , 0 ) ;
}
int F_224 ( struct V_1 * V_2 , T_2 V_906 , T_1 V_907 )
{
struct V_11 * V_12 ;
struct V_908 * V_220 ;
int V_45 ;
if ( V_906 == 0xFFFFFFFF )
return - 1 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_909 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_907 = V_907 ;
V_220 -> V_910 = F_80 ( V_906 ) ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_225 ( struct V_1 * V_2 , T_7 V_464 )
{
struct V_825 V_911 ;
memset ( & V_911 , 0 , sizeof( V_911 ) ) ;
V_911 . V_224 . V_814 = V_826 ;
V_911 . V_224 . V_819 = V_900 ;
V_911 . V_28 = ( 1 << V_898 ) | ( 1 << V_899 ) ;
V_911 . V_912 = V_2 -> V_91 ;
if ( V_464 ) {
V_911 . V_913 = V_914 | ( 1 << V_915 ) |
( 1 << V_916 ) ;
V_911 . V_917 = F_226 ( V_464 ) ;
} else {
V_911 . V_913 = V_918 ;
V_911 . V_917 = 0 ;
}
return F_219 ( V_2 , & V_911 ,
V_900 , 1 , 1 , 0 ) ;
}
int F_227 ( struct V_1 * V_2 , struct V_919 * V_920 ,
int V_856 )
{
struct V_11 * V_12 ;
struct V_921 * V_220 ;
struct V_922 * V_60 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_923 , sizeof( * V_60 ) ,
V_12 , NULL ) ;
V_220 -> V_224 . V_245 = V_856 + 1 ;
V_45 = F_60 ( V_2 ) ;
if ( ! V_45 ) {
V_60 = (struct V_922 * ) V_220 ;
V_920 -> V_236 = F_8 ( V_60 -> V_924 . V_241 ) ;
}
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
static int F_228 ( struct V_1 * V_2 )
{
#define F_229 30
T_2 V_925 ;
int V_45 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < F_229 ; V_5 ++ ) {
V_925 = F_64 ( V_2 -> V_24 + V_926 ) ;
if ( ( V_925 & V_927 ) == 0 )
break;
F_230 ( 1 ) ;
}
if ( V_5 == F_229 )
V_45 = - 1 ;
return V_45 ;
}
int F_172 ( struct V_1 * V_2 , T_2 V_928 )
{
int V_45 = 0 ;
V_45 = F_228 ( V_2 ) ;
if ( V_45 )
return V_45 ;
F_6 ( V_928 , V_2 -> V_24 + V_926 ) ;
return V_45 ;
}
bool F_231 ( struct V_1 * V_2 )
{
T_2 V_175 = 0 ;
V_175 = F_64 ( V_2 -> V_24 + V_176 ) ;
return ! ! ( V_175 & V_929 ) ;
}
int F_232 ( struct V_1 * V_2 )
{
struct V_86 * V_70 = & V_2 -> V_69 -> V_70 ;
int V_45 ;
if ( F_231 ( V_2 ) ) {
F_31 ( V_70 , L_42 ) ;
return - V_930 ;
}
V_45 = F_172 ( V_2 , V_644 |
V_931 ) ;
if ( V_45 < 0 ) {
F_18 ( V_70 , L_43 ) ;
return V_45 ;
}
V_45 = F_228 ( V_2 ) ;
if ( V_45 )
return V_45 ;
if ( ! F_231 ( V_2 ) ) {
F_18 ( V_70 , L_44 ) ;
return - V_20 ;
}
return 0 ;
}
int F_233 ( struct V_1 * V_2 )
{
int V_45 ;
V_45 = F_155 ( V_2 , V_932 ) ;
return F_171 ( V_45 ) ;
}
int F_234 ( struct V_1 * V_2 , T_1 V_245 )
{
struct V_11 * V_12 ;
struct V_933 * V_220 ;
int V_45 ;
if ( F_20 ( V_2 ) )
return 0 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_934 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_224 . V_245 = V_245 ;
V_220 -> V_660 = 1 ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_235 ( struct V_1 * V_2 , bool V_935 )
{
struct V_11 * V_12 ;
struct V_936 * V_220 ;
int V_45 ;
if ( F_93 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_937 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_220 -> V_938 = V_935 ;
V_45 = F_67 ( V_2 ) ;
F_95 ( & V_2 -> V_213 ) ;
return V_45 ;
}
int F_236 ( struct V_1 * V_2 , T_3 * V_939 )
{
struct V_940 * V_220 ;
struct V_11 * V_12 ;
int V_45 ;
if ( F_93 ( & V_2 -> V_213 ) )
return - 1 ;
V_12 = F_85 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_941 , sizeof( * V_220 ) ,
V_12 , NULL ) ;
V_45 = F_67 ( V_2 ) ;
if ( ! V_45 ) {
struct V_942 * V_60 =
F_2 ( V_12 ) ;
* V_939 = F_29 ( V_60 -> V_943 ) ;
}
V_182:
F_95 ( & V_2 -> V_213 ) ;
return V_45 ;
}
static int
F_237 ( struct V_1 * V_2 ,
int V_944 , int V_194 , T_1 V_245 )
{
struct V_11 * V_12 ;
struct V_945 * V_220 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_946 ,
sizeof( * V_220 ) , V_12 , NULL ) ;
V_220 -> V_224 . V_194 = V_194 ;
V_220 -> V_224 . V_245 = V_245 ;
if ( V_944 == V_947 ||
V_944 == V_948 )
V_220 -> V_949 |= V_950 ;
if ( V_944 == V_948 )
V_220 -> V_949 |= V_951 ;
V_45 = F_60 ( V_2 ) ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_238 ( struct V_1 * V_2 ,
int V_944 , T_1 V_245 )
{
int V_45 ;
if ( F_124 ( V_2 ) )
return - V_419 ;
V_45 = F_237 ( V_2 , V_944 ,
2 , V_245 ) ;
if ( V_34 ( V_45 ) == V_37 )
V_45 = F_237 ( V_2 , V_944 ,
1 , V_245 ) ;
return V_45 ;
}
int F_239 ( struct V_1 * V_2 )
{
struct V_952 * V_60 ;
struct V_953 * V_220 ;
struct V_11 * V_12 ;
int V_45 ;
if ( F_93 ( & V_2 -> V_212 ) )
return - 1 ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
F_79 ( & V_220 -> V_224 , V_51 ,
V_954 ,
sizeof( * V_220 ) , V_12 , NULL ) ;
V_220 -> V_955 = F_80 ( V_956 ) ;
V_220 -> V_957 = F_80 ( sizeof( struct V_958 ) ) ;
V_220 -> V_959 . V_220 . V_960 = F_80 ( V_961 ) ;
V_45 = F_60 ( V_2 ) ;
if ( V_45 )
goto V_182;
V_60 = F_2 ( V_12 ) ;
V_2 -> V_962 . V_963 =
F_29 ( V_60 -> V_959 . V_60 . V_964 ) ;
V_2 -> V_962 . V_965 =
F_29 ( V_60 -> V_959 . V_60 . V_966 ) ;
V_2 -> V_962 . V_967 = true ;
V_182:
if ( V_34 ( V_45 ) == V_37 ||
V_34 ( V_45 ) == V_968 )
F_31 ( & V_2 -> V_69 -> V_70 ,
L_45 ) ;
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
int F_240 ( void * V_969 , void * V_970 ,
int V_971 , T_3 * V_972 , T_3 * V_973 )
{
struct V_1 * V_2 = F_241 ( V_969 ) ;
struct V_11 * V_12 ;
struct V_188 * V_224 = (struct V_188 * ) V_970 ;
struct V_188 * V_220 ;
struct V_30 * V_60 ;
int V_45 ;
F_92 ( & V_2 -> V_212 ) ;
V_12 = F_86 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_215 ;
goto V_182;
}
V_220 = F_2 ( V_12 ) ;
V_60 = F_2 ( V_12 ) ;
F_79 ( V_220 , V_224 -> V_4 ,
V_224 -> V_3 , V_971 , V_12 , NULL ) ;
memcpy ( V_220 , V_970 , V_971 ) ;
F_81 ( V_220 , V_971 ) ;
V_45 = F_60 ( V_2 ) ;
if ( V_972 )
* V_972 = ( V_45 & 0xffff ) ;
if ( V_973 )
* V_973 = 0 ;
memcpy ( V_970 , V_60 , sizeof( * V_60 ) + V_60 -> V_974 ) ;
F_16 ( V_970 , sizeof( * V_60 ) + V_60 -> V_974 ) ;
V_182:
F_95 ( & V_2 -> V_212 ) ;
return V_45 ;
}
