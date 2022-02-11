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
if ( V_34 == V_67 ) {
F_17 ( & V_2 -> V_68 -> V_69 ,
L_1 ,
V_3 , V_4 ) ;
} else {
F_18 ( & V_2 -> V_68 -> V_69 ,
L_2 ,
V_3 , V_4 , V_34 , V_35 ) ;
}
}
return V_27 -> V_45 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_70 * V_71 =
(struct V_70 * ) V_27 ;
V_2 -> V_72 . V_73 = - 1 ;
if ( ! F_20 ( V_2 ) &&
! ( V_71 -> V_74 & V_75 ) )
return;
if ( V_2 -> V_28 & V_76 )
F_21 ( V_2 ,
V_71 -> V_74 & V_77 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_78 * V_71 =
(struct V_78 * ) V_27 ;
T_2 V_79 = F_8 ( V_71 -> V_80 ) ;
struct V_81 * V_69 = & V_2 -> V_68 -> V_69 ;
T_1 V_82 ;
V_82 =
( ( V_79 >> ( V_2 -> V_83 * 8 ) ) & 0xff ) ;
F_23 ( V_69 , L_3 , V_2 -> V_84 ,
V_85 [ V_82 ] ,
V_86 [ V_82 ] ) ;
if ( V_82 == V_87 )
V_2 -> V_28 |= V_88 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_89 * V_71 =
(struct V_89 * ) V_27 ;
if ( V_71 -> V_90 ) {
V_2 -> V_91 = V_71 -> V_92 ;
V_2 -> V_93 &= ~ V_94 ;
V_2 -> V_93 =
V_71 -> V_95 << V_96 ;
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_97 * V_71 =
(struct V_97 * ) V_27 ;
if ( V_2 -> V_72 . V_73 >= 0 &&
V_71 -> V_98 == V_2 -> V_99 )
V_2 -> V_72 . V_73 = F_26 ( V_71 -> V_100 ) * 10 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_101 * V_71 =
(struct V_101 * ) V_27 ;
if ( V_71 -> V_102 ) {
V_2 -> V_103 = F_26 ( V_71 -> V_104 ) & V_105 ;
F_23 ( & V_2 -> V_68 -> V_69 , L_4 , V_2 -> V_103 ) ;
} else {
V_2 -> V_103 = 0 ;
}
}
static void F_28 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_106 * V_71 = (struct V_106 * ) V_27 ;
T_2 V_107 = F_8 ( V_71 -> V_80 ) ;
if ( V_107 & V_108 ) {
V_2 -> V_28 |= V_109 ;
V_2 -> V_110 = F_8 ( V_71 -> V_111 ) ;
} else {
V_2 -> V_28 &= ~ V_109 ;
}
}
static void F_29 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
T_1 V_112 = ( V_27 -> V_28 >> V_113 ) &
V_114 ;
switch ( V_112 ) {
case V_115 :
F_24 ( V_2 , V_27 ) ;
break;
case V_116 :
F_25 ( V_2 , V_27 ) ;
break;
case V_117 :
F_27 ( V_2 , V_27 ) ;
break;
case V_118 :
F_28 ( V_2 , V_27 ) ;
break;
default:
break;
}
}
static void F_30 ( struct V_1 * V_2 ,
struct V_26 * V_119 )
{
T_1 V_112 = 0 ;
struct V_120 * V_71 = (struct V_120 * ) V_119 ;
V_112 = ( V_119 -> V_28 >> V_113 ) &
V_114 ;
switch ( V_112 ) {
case V_121 :
if ( V_71 -> V_90 )
V_2 -> V_122 = F_26 ( V_71 -> V_123 ) ;
V_2 -> V_28 |= V_124 ;
break;
default:
F_17 ( & V_2 -> V_68 -> V_69 , L_5 ,
V_112 ) ;
break;
}
}
static void F_31 ( struct V_1 * V_2 ,
struct V_26 * V_119 )
{
T_1 V_112 = ( V_119 -> V_28 >> V_113 ) &
V_114 ;
if ( V_112 == V_125 )
F_22 ( V_2 , V_119 ) ;
}
static inline bool F_32 ( T_2 V_28 )
{
return ( ( V_28 >> V_126 ) & V_127 ) ==
V_128 ;
}
static inline bool F_33 ( T_2 V_28 )
{
return ( ( V_28 >> V_126 ) & V_127 ) ==
V_129 ;
}
static inline bool F_34 ( T_2 V_28 )
{
return ( ( V_28 >> V_126 ) & V_127 ) ==
V_130 ;
}
static inline bool F_35 ( T_2 V_28 )
{
return ( ( V_28 >> V_126 ) & V_127 ) ==
V_131 ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
if ( F_32 ( V_27 -> V_28 ) )
F_19 ( V_2 , V_27 ) ;
else if ( F_33 ( V_27 -> V_28 ) )
F_29 ( V_2 , V_27 ) ;
else if ( F_34 ( V_27 -> V_28 ) )
F_30 ( V_2 , V_27 ) ;
else if ( F_35 ( V_27 -> V_28 ) )
F_31 ( V_2 , V_27 ) ;
}
static struct V_26 * F_37 ( struct V_1 * V_2 )
{
struct V_14 * V_132 = & V_2 -> V_16 . V_133 ;
struct V_26 * V_27 = F_38 ( V_132 ) ;
if ( F_7 ( V_27 ) ) {
F_39 ( V_132 ) ;
return V_27 ;
}
return NULL ;
}
void F_40 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_134 ) ;
F_42 ( V_2 , V_2 -> V_16 . V_133 . V_21 , true , 0 ) ;
V_2 -> V_16 . V_135 = true ;
F_43 ( & V_2 -> V_134 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_134 ) ;
V_2 -> V_16 . V_135 = false ;
F_42 ( V_2 , V_2 -> V_16 . V_133 . V_21 , false , 0 ) ;
F_43 ( & V_2 -> V_134 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
int V_136 = 0 , V_45 = 0 ;
struct V_137 * V_16 = & V_2 -> V_16 ;
F_46 ( & V_2 -> V_134 ) ;
while ( ( V_27 = F_37 ( V_2 ) ) ) {
if ( V_27 -> V_28 & V_138 ) {
F_36 ( V_2 , V_27 ) ;
} else if ( V_27 -> V_28 & V_139 ) {
V_45 = F_15 ( V_2 , V_27 ) ;
F_47 ( & V_16 -> V_17 . V_140 ) ;
}
F_9 ( V_27 ) ;
V_136 ++ ;
}
if ( V_136 )
F_42 ( V_2 , V_16 -> V_133 . V_21 , V_16 -> V_135 , V_136 ) ;
F_48 ( & V_2 -> V_134 ) ;
return V_45 ;
}
static int F_49 ( struct V_1 * V_2 )
{
#define F_50 120000
int V_5 , V_45 = 0 ;
struct V_137 * V_16 = & V_2 -> V_16 ;
for ( V_5 = 0 ; V_5 < F_50 ; V_5 ++ ) {
if ( F_4 ( V_2 , V_19 ) )
return - V_20 ;
F_51 () ;
V_45 = F_45 ( V_2 ) ;
F_52 () ;
if ( F_53 ( & V_16 -> V_17 . V_140 ) == 0 )
break;
F_54 ( 100 ) ;
}
if ( V_5 == F_50 ) {
F_18 ( & V_2 -> V_68 -> V_69 , L_6 ) ;
F_55 ( V_2 , V_141 ) ;
return - V_20 ;
}
return V_45 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_45 ;
struct V_11 * V_12 ;
struct V_137 * V_16 = & V_2 -> V_16 ;
T_3 V_142 = V_16 -> V_17 . V_143 ;
struct V_30 * V_60 ;
F_57 ( & V_142 , V_16 -> V_17 . V_144 ) ;
V_12 = F_58 ( & V_16 -> V_17 , V_142 ) ;
V_60 = F_10 ( V_12 -> V_31 , V_12 -> V_32 ) ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_145;
V_45 = F_49 ( V_2 ) ;
if ( V_45 == - V_20 )
goto V_145;
V_45 = ( V_60 -> V_34 |
( ( V_60 -> V_35 & V_146 ) <<
V_147 ) ) ;
V_145:
return V_45 ;
}
static int F_59 ( struct V_1 * V_2 , void T_4 * V_24 )
{
int V_148 = 0 ;
T_2 V_149 ;
do {
if ( F_4 ( V_2 , V_19 ) )
return - V_20 ;
V_149 = F_60 ( V_24 ) ;
if ( V_149 == 0xffffffff )
return - 1 ;
V_149 &= V_150 ;
if ( V_149 )
break;
if ( V_148 > 4000 ) {
F_18 ( & V_2 -> V_68 -> V_69 , L_6 ) ;
F_55 ( V_2 , V_141 ) ;
F_61 ( V_2 ) ;
return - 1 ;
}
F_62 ( 1 ) ;
V_148 ++ ;
} while ( true );
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
int V_45 ;
T_2 V_18 = 0 ;
void T_4 * V_24 = V_2 -> V_24 + V_151 ;
struct V_152 * V_153 = & V_2 -> V_153 ;
struct V_154 * V_155 = V_153 -> V_156 ;
struct V_26 * V_27 = & V_155 -> V_27 ;
V_45 = F_59 ( V_2 , V_24 ) ;
if ( V_45 != 0 )
return V_45 ;
V_18 |= V_157 ;
V_18 |= ( F_64 ( V_153 -> V_158 ) >> 2 ) << 2 ;
F_6 ( V_18 , V_24 ) ;
V_45 = F_59 ( V_2 , V_24 ) ;
if ( V_45 != 0 )
return V_45 ;
V_18 = 0 ;
V_18 |= ( T_2 ) ( V_153 -> V_158 >> 4 ) << 2 ;
F_6 ( V_18 , V_24 ) ;
V_45 = F_59 ( V_2 , V_24 ) ;
if ( V_45 != 0 )
return V_45 ;
if ( F_7 ( V_27 ) ) {
V_45 = F_15 ( V_2 , & V_155 -> V_27 ) ;
F_9 ( V_27 ) ;
if ( V_45 )
return V_45 ;
} else {
F_18 ( & V_2 -> V_68 -> V_69 , L_7 ) ;
return - 1 ;
}
return 0 ;
}
static T_3 F_65 ( struct V_1 * V_2 )
{
T_2 V_159 ;
if ( F_20 ( V_2 ) )
V_159 = F_60 ( V_2 -> V_160 + V_161 ) ;
else
F_66 ( V_2 -> V_68 ,
V_162 , & V_159 ) ;
return V_159 & V_163 ;
}
static int F_67 ( struct V_1 * V_2 )
{
#define F_68 30
T_2 V_164 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_68 ; V_5 ++ ) {
V_164 = F_60 ( V_2 -> V_24 + V_165 ) ;
if ( V_164 & V_166 )
return 0 ;
if ( V_164 & V_167 &&
! ( V_164 & V_168 ) )
return - V_20 ;
F_62 ( 1000 ) ;
}
return V_164 ? : - 1 ;
}
int F_69 ( struct V_1 * V_2 )
{
T_3 V_169 ;
int V_45 , V_170 = 0 ;
struct V_81 * V_69 = & V_2 -> V_68 -> V_69 ;
if ( F_70 ( V_2 ) ) {
V_45 = F_67 ( V_2 ) ;
if ( V_45 ) {
V_169 = V_45 ;
goto V_171;
}
return 0 ;
}
do {
if ( F_20 ( V_2 ) && F_71 ( V_2 ) )
return 0 ;
V_169 = F_65 ( V_2 ) ;
if ( V_169 == V_172 )
return 0 ;
F_23 ( V_69 , L_8 , V_170 ) ;
if ( F_72 ( 2000 ) ) {
F_18 ( V_69 , L_9 ) ;
return - V_173 ;
}
V_170 += 2 ;
} while ( V_170 < 60 );
V_171:
F_18 ( V_69 , L_10 , V_169 ) ;
return - V_174 ;
}
static inline struct V_175 * F_73 ( struct V_11 * V_12 )
{
return & V_12 -> V_13 . V_176 [ 0 ] ;
}
static inline void F_74 ( struct V_11 * V_12 , unsigned long V_33 )
{
V_12 -> V_31 = V_33 & 0xFFFFFFFF ;
V_12 -> V_32 = F_64 ( V_33 ) ;
}
static void F_75 ( struct V_177 * V_178 ,
T_1 V_4 , T_1 V_3 , int V_179 ,
struct V_11 * V_12 ,
struct V_152 * V_180 )
{
struct V_175 * V_181 ;
V_178 -> V_3 = V_3 ;
V_178 -> V_4 = V_4 ;
V_178 -> V_182 = F_76 ( V_179 - sizeof( * V_178 ) ) ;
V_178 -> V_183 = 0 ;
F_74 ( V_12 , ( V_184 ) V_178 ) ;
V_12 -> V_185 = V_179 ;
if ( V_180 ) {
V_12 -> V_186 |= ( 1 & V_187 ) <<
V_188 ;
V_181 = F_73 ( V_12 ) ;
V_181 -> V_189 = F_76 ( F_64 ( V_180 -> V_158 ) ) ;
V_181 -> V_190 = F_76 ( V_180 -> V_158 & 0xFFFFFFFF ) ;
V_181 -> V_144 = F_76 ( V_180 -> V_191 ) ;
} else
V_12 -> V_186 |= V_192 ;
F_77 ( V_12 , 8 ) ;
}
static void F_78 ( struct V_193 * V_194 , T_2 V_195 ,
struct V_152 * V_180 )
{
int V_5 , V_196 = F_79 ( F_80 ( V_180 -> V_156 , V_180 -> V_191 ) , V_195 ) ;
T_5 V_158 = ( T_5 ) V_180 -> V_158 ;
for ( V_5 = 0 ; V_5 < V_196 ; V_5 ++ ) {
V_194 [ V_5 ] . V_197 = F_76 ( V_158 & 0xFFFFFFFF ) ;
V_194 [ V_5 ] . V_198 = F_76 ( F_64 ( V_158 ) ) ;
V_158 += V_199 ;
}
}
static inline struct V_11 * F_81 ( struct V_1 * V_2 )
{
struct V_152 * V_153 = & V_2 -> V_153 ;
struct V_11 * V_12
= & ( (struct V_154 * ) ( V_153 -> V_156 ) ) -> V_12 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
static struct V_11 * F_82 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 . V_17 ;
struct V_11 * V_12 ;
if ( ! V_15 -> V_200 )
return NULL ;
if ( F_53 ( & V_15 -> V_140 ) >= V_15 -> V_144 )
return NULL ;
V_12 = F_83 ( V_15 ) ;
F_84 ( V_15 ) ;
F_85 ( & V_15 -> V_140 ) ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
static bool F_86 ( struct V_1 * V_2 )
{
return V_2 -> V_16 . V_17 . V_200 ;
}
static int F_87 ( struct V_1 * V_2 )
{
if ( F_86 ( V_2 ) ) {
F_41 ( & V_2 -> V_201 ) ;
return 0 ;
} else {
return F_88 ( & V_2 -> V_202 ) ;
}
}
static void F_89 ( struct V_1 * V_2 )
{
if ( F_86 ( V_2 ) )
F_43 ( & V_2 -> V_201 ) ;
else
return F_90 ( & V_2 -> V_202 ) ;
}
static struct V_11 * F_91 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_203 ;
if ( F_86 ( V_2 ) ) {
V_203 = F_82 ( V_2 ) ;
if ( ! V_203 )
return NULL ;
} else {
V_203 = F_81 ( V_2 ) ;
}
memcpy ( V_203 , V_12 , sizeof( * V_12 ) ) ;
if ( V_12 -> V_186 & F_76 ( V_192 ) )
F_74 ( V_203 , ( V_184 ) F_2 ( V_12 ) ) ;
return V_203 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_203 ;
int V_45 ;
V_45 = F_87 ( V_2 ) ;
if ( V_45 )
return V_45 ;
V_203 = F_91 ( V_2 , V_12 ) ;
if ( ! V_203 ) {
V_45 = - V_204 ;
goto V_205;
}
if ( F_86 ( V_2 ) )
V_45 = F_56 ( V_2 ) ;
else
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 )
memcpy ( V_12 , V_203 , sizeof( * V_12 ) ) ;
V_205:
F_89 ( V_2 ) ;
return V_45 ;
}
int F_93 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_45 ;
if ( F_70 ( V_2 ) )
return 0 ;
if ( F_88 ( & V_2 -> V_202 ) )
return - 1 ;
V_12 = ( T_1 * ) F_81 ( V_2 ) ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0x12 ;
* V_12 ++ = 0x34 ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0x56 ;
* V_12 ++ = 0x78 ;
* V_12 = 0xFF ;
V_45 = F_63 ( V_2 ) ;
F_90 ( & V_2 -> V_202 ) ;
return V_45 ;
}
int F_94 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_45 ;
if ( F_70 ( V_2 ) )
return 0 ;
if ( F_88 ( & V_2 -> V_202 ) )
return - 1 ;
V_12 = ( T_1 * ) F_81 ( V_2 ) ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xAA ;
* V_12 ++ = 0xBB ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xCC ;
* V_12 ++ = 0xDD ;
* V_12 = 0xFF ;
V_45 = F_63 ( V_2 ) ;
F_90 ( & V_2 -> V_202 ) ;
return V_45 ;
}
int F_95 ( struct V_1 * V_2 , struct V_206 * V_207 )
{
struct V_11 * V_12 ;
struct V_208 * V_209 ;
struct V_152 * V_210 = & V_207 -> V_17 . V_211 ;
int V_45 , V_212 = 0 ;
if ( F_88 ( & V_2 -> V_202 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_214 , sizeof( * V_209 ) , V_12 ,
NULL ) ;
if ( ! ( F_20 ( V_2 ) || F_70 ( V_2 ) ) )
V_212 = 2 ;
V_209 -> V_213 . V_183 = V_212 ;
V_209 -> V_215 = F_96 ( F_80 ( V_210 -> V_156 , V_210 -> V_191 ) ) ;
F_97 ( struct V_216 , V_90 , V_209 -> V_217 , 1 ) ;
F_97 ( struct V_216 , V_191 , V_209 -> V_217 , 0 ) ;
F_97 ( struct V_216 , V_218 , V_209 -> V_217 ,
F_98 ( V_207 -> V_17 . V_144 / 256 ) ) ;
F_77 ( V_209 -> V_217 , sizeof( V_209 -> V_217 ) ) ;
F_78 ( V_209 -> V_194 , F_99 ( V_209 -> V_194 ) , V_210 ) ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_219 * V_60 = F_2 ( V_12 ) ;
V_207 -> V_17 . V_21 = F_26 ( V_60 -> V_220 ) ;
V_207 -> V_221 =
( V_212 == 2 ) ? F_26 ( V_60 -> V_221 ) : V_207 -> V_222 ;
V_207 -> V_17 . V_200 = true ;
}
F_90 ( & V_2 -> V_202 ) ;
return V_45 ;
}
int F_100 ( struct V_1 * V_2 , T_1 * V_223 ,
bool V_224 , T_2 V_225 , T_2 V_226 )
{
struct V_11 * V_12 ;
struct V_227 * V_209 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_228 , sizeof( * V_209 ) , V_12 ,
NULL ) ;
V_209 -> type = V_229 ;
if ( V_224 ) {
V_209 -> V_224 = 1 ;
} else {
V_209 -> V_230 = F_96 ( ( T_3 ) V_225 ) ;
V_209 -> V_226 = F_76 ( V_226 ) ;
V_209 -> V_224 = 0 ;
}
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_231 * V_60 = F_2 ( V_12 ) ;
memcpy ( V_223 , V_60 -> V_232 . V_33 , V_233 ) ;
}
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_101 ( struct V_1 * V_2 , T_1 * V_223 ,
T_2 V_230 , T_2 * V_226 , T_2 V_234 )
{
struct V_11 * V_12 ;
struct V_235 * V_209 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_236 , sizeof( * V_209 ) , V_12 ,
NULL ) ;
V_209 -> V_213 . V_234 = V_234 ;
V_209 -> V_230 = F_76 ( V_230 ) ;
memcpy ( V_209 -> V_237 , V_223 , V_233 ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_238 * V_60 = F_2 ( V_12 ) ;
* V_226 = F_8 ( V_60 -> V_226 ) ;
}
V_171:
F_43 ( & V_2 -> V_201 ) ;
if ( V_45 == V_67 )
V_45 = - V_239 ;
return V_45 ;
}
int F_102 ( struct V_1 * V_2 , T_2 V_230 , int V_226 , T_2 V_240 )
{
struct V_11 * V_12 ;
struct V_241 * V_209 ;
int V_45 ;
if ( V_226 == - 1 )
return 0 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_242 , sizeof( * V_209 ) ,
V_12 , NULL ) ;
V_209 -> V_213 . V_234 = V_240 ;
V_209 -> V_230 = F_76 ( V_230 ) ;
V_209 -> V_226 = F_76 ( V_226 ) ;
V_45 = F_56 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_103 ( struct V_1 * V_2 , struct V_14 * V_133 ,
struct V_14 * V_243 , bool V_244 , int V_245 )
{
struct V_11 * V_12 ;
struct V_246 * V_209 ;
struct V_152 * V_210 = & V_133 -> V_211 ;
void * V_247 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_202 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_209 = F_2 ( V_12 ) ;
V_247 = & V_209 -> V_217 ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_248 , sizeof( * V_209 ) , V_12 ,
NULL ) ;
V_209 -> V_215 = F_96 ( F_80 ( V_210 -> V_156 , V_210 -> V_191 ) ) ;
if ( F_20 ( V_2 ) ) {
F_97 ( struct V_249 , V_250 , V_247 ,
V_245 ) ;
F_97 ( struct V_249 , V_251 ,
V_247 , V_244 ) ;
F_97 ( struct V_249 , V_218 , V_247 ,
F_98 ( V_133 -> V_144 / 256 ) ) ;
F_97 ( struct V_249 , V_90 , V_247 , 1 ) ;
F_97 ( struct V_249 , V_252 , V_247 , 1 ) ;
F_97 ( struct V_249 , V_253 , V_247 , V_243 -> V_21 ) ;
} else {
V_209 -> V_213 . V_183 = 2 ;
V_209 -> V_254 = 1 ;
if ( ! F_70 ( V_2 ) )
F_97 ( struct V_255 , V_250 ,
V_247 , V_245 ) ;
F_97 ( struct V_255 , V_251 , V_247 ,
V_244 ) ;
F_97 ( struct V_255 , V_218 , V_247 ,
F_98 ( V_133 -> V_144 / 256 ) ) ;
F_97 ( struct V_255 , V_90 , V_247 , 1 ) ;
F_97 ( struct V_255 , V_252 , V_247 , 1 ) ;
F_97 ( struct V_255 , V_253 , V_247 , V_243 -> V_21 ) ;
}
F_77 ( V_247 , sizeof( V_209 -> V_217 ) ) ;
F_78 ( V_209 -> V_194 , F_99 ( V_209 -> V_194 ) , V_210 ) ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_256 * V_60 = F_2 ( V_12 ) ;
V_133 -> V_21 = F_26 ( V_60 -> V_257 ) ;
V_133 -> V_200 = true ;
}
F_90 ( & V_2 -> V_202 ) ;
return V_45 ;
}
static T_2 F_104 ( int V_258 )
{
T_2 V_259 = F_105 ( V_258 ) ;
if ( V_259 == 16 )
V_259 = 0 ;
return V_259 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_133 )
{
struct V_11 * V_12 ;
struct V_260 * V_209 ;
struct V_152 * V_210 = & V_15 -> V_211 ;
void * V_247 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_202 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_209 = F_2 ( V_12 ) ;
V_247 = & V_209 -> V_217 ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_261 , sizeof( * V_209 ) , V_12 ,
NULL ) ;
V_209 -> V_215 = F_96 ( F_80 ( V_210 -> V_156 , V_210 -> V_191 ) ) ;
if ( F_20 ( V_2 ) ) {
F_97 ( struct V_262 , V_90 , V_247 , 1 ) ;
F_97 ( struct V_262 , V_263 , V_247 ,
F_104 ( V_15 -> V_144 ) ) ;
F_97 ( struct V_262 , V_257 , V_247 , V_133 -> V_21 ) ;
} else {
V_209 -> V_213 . V_183 = 1 ;
V_209 -> V_257 = F_96 ( V_133 -> V_21 ) ;
F_97 ( struct V_264 , V_263 , V_247 ,
F_104 ( V_15 -> V_144 ) ) ;
F_97 ( struct V_264 , V_90 , V_247 , 1 ) ;
F_97 ( struct V_264 , V_265 ,
V_247 , V_133 -> V_21 ) ;
F_97 ( struct V_264 , V_266 ,
V_247 , 1 ) ;
}
V_209 -> V_267 [ 0 ] =
F_76 ( F_107 ( V_128 ) |
F_107 ( V_129 ) |
F_107 ( V_130 ) |
F_107 ( V_131 ) ) ;
F_77 ( V_247 , sizeof( V_209 -> V_217 ) ) ;
F_78 ( V_209 -> V_194 , F_99 ( V_209 -> V_194 ) , V_210 ) ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_268 * V_60 = F_2 ( V_12 ) ;
V_15 -> V_21 = F_26 ( V_60 -> V_21 ) ;
V_15 -> V_200 = true ;
}
F_90 ( & V_2 -> V_202 ) ;
return V_45 ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_133 )
{
struct V_11 * V_12 ;
struct V_269 * V_209 ;
struct V_152 * V_210 = & V_15 -> V_211 ;
void * V_247 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_202 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_209 = F_2 ( V_12 ) ;
V_247 = & V_209 -> V_217 ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_270 , sizeof( * V_209 ) , V_12 ,
NULL ) ;
V_209 -> V_215 = F_96 ( F_80 ( V_210 -> V_156 , V_210 -> V_191 ) ) ;
F_97 ( struct V_262 , V_90 , V_247 , 1 ) ;
F_97 ( struct V_262 , V_263 , V_247 ,
F_104 ( V_15 -> V_144 ) ) ;
F_97 ( struct V_262 , V_257 , V_247 , V_133 -> V_21 ) ;
F_77 ( V_247 , sizeof( V_209 -> V_217 ) ) ;
F_78 ( V_209 -> V_194 , F_99 ( V_209 -> V_194 ) , V_210 ) ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_268 * V_60 = F_2 ( V_12 ) ;
V_15 -> V_21 = F_26 ( V_60 -> V_21 ) ;
V_15 -> V_200 = true ;
}
F_90 ( & V_2 -> V_202 ) ;
return V_45 ;
}
int F_109 ( struct V_1 * V_2 ,
struct V_14 * V_15 , struct V_14 * V_133 )
{
int V_45 ;
V_45 = F_106 ( V_2 , V_15 , V_133 ) ;
if ( V_45 && F_20 ( V_2 ) ) {
F_17 ( & V_2 -> V_68 -> V_69 , L_11
L_12
L_13 ) ;
V_45 = F_108 ( V_2 , V_15 , V_133 ) ;
}
return V_45 ;
}
int F_110 ( struct V_1 * V_2 , struct V_271 * V_272 )
{
struct V_11 V_12 = { 0 } ;
struct V_273 * V_209 ;
struct V_14 * V_274 = & V_272 -> V_17 ;
struct V_14 * V_133 = & V_272 -> V_133 ;
struct V_152 * V_210 = & V_274 -> V_211 ;
int V_45 , V_212 = 0 ;
V_209 = F_2 ( & V_12 ) ;
F_75 ( & V_209 -> V_213 , V_55 ,
V_275 , sizeof( * V_209 ) , & V_12 , NULL ) ;
if ( F_70 ( V_2 ) ) {
V_209 -> V_213 . V_183 = 1 ;
} else if ( F_20 ( V_2 ) ) {
if ( V_2 -> V_276 & V_277 )
V_209 -> V_213 . V_183 = 2 ;
} else {
V_209 -> V_213 . V_183 = 2 ;
}
if ( V_209 -> V_213 . V_183 > 0 )
V_209 -> V_230 = F_96 ( V_2 -> V_225 ) ;
V_209 -> V_215 = F_80 ( V_210 -> V_156 , V_210 -> V_191 ) ;
V_209 -> V_278 = V_279 ;
V_209 -> type = V_280 ;
V_209 -> V_257 = F_96 ( V_133 -> V_21 ) ;
V_209 -> V_281 = F_104 ( V_274 -> V_144 ) ;
F_78 ( V_209 -> V_194 , F_99 ( V_209 -> V_194 ) , V_210 ) ;
V_212 = V_209 -> V_213 . V_183 ;
V_45 = F_92 ( V_2 , & V_12 ) ;
if ( ! V_45 ) {
struct V_282 * V_60 = F_2 ( & V_12 ) ;
V_274 -> V_21 = F_26 ( V_60 -> V_283 ) ;
if ( V_212 == 2 )
V_272 -> V_284 = F_8 ( V_60 -> V_284 ) ;
else
V_272 -> V_284 = V_285 ;
V_274 -> V_200 = true ;
}
return V_45 ;
}
int F_111 ( struct V_1 * V_2 ,
struct V_14 * V_286 , T_3 V_257 , T_3 V_287 ,
T_2 V_230 , T_2 V_288 , T_1 * V_289 )
{
struct V_11 * V_12 ;
struct V_290 * V_209 ;
struct V_152 * V_210 = & V_286 -> V_211 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_55 ,
V_291 , sizeof( * V_209 ) , V_12 , NULL ) ;
V_209 -> V_257 = F_96 ( V_257 ) ;
V_209 -> V_287 = F_105 ( V_287 ) - 1 ;
V_209 -> V_215 = 2 ;
F_78 ( V_209 -> V_194 , F_99 ( V_209 -> V_194 ) , V_210 ) ;
V_209 -> V_292 = F_76 ( V_230 ) ;
V_209 -> V_293 = F_96 ( V_294 ) ;
V_209 -> V_295 = F_76 ( V_288 ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_296 * V_60 = F_2 ( V_12 ) ;
V_286 -> V_21 = F_26 ( V_60 -> V_21 ) ;
V_286 -> V_200 = true ;
* V_289 = V_60 -> V_289 ;
}
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_112 ( struct V_1 * V_2 , struct V_14 * V_17 ,
int V_297 )
{
struct V_11 * V_12 ;
struct V_298 * V_209 ;
T_1 V_299 = 0 , V_3 = 0 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_202 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_209 = F_2 ( V_12 ) ;
switch ( V_297 ) {
case V_300 :
V_299 = V_51 ;
V_3 = V_301 ;
break;
case V_302 :
V_299 = V_51 ;
V_3 = V_303 ;
break;
case V_304 :
V_299 = V_55 ;
V_3 = V_305 ;
break;
case V_306 :
V_299 = V_55 ;
V_3 = V_307 ;
break;
case V_308 :
V_299 = V_51 ;
V_3 = V_309 ;
break;
default:
F_113 () ;
}
F_75 ( & V_209 -> V_213 , V_299 , V_3 , sizeof( * V_209 ) , V_12 ,
NULL ) ;
V_209 -> V_21 = F_96 ( V_17 -> V_21 ) ;
V_45 = F_63 ( V_2 ) ;
V_17 -> V_200 = false ;
F_90 ( & V_2 -> V_202 ) ;
return V_45 ;
}
int F_114 ( struct V_1 * V_2 , struct V_14 * V_17 )
{
struct V_11 * V_12 ;
struct V_298 * V_209 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_55 ,
V_307 , sizeof( * V_209 ) , V_12 , NULL ) ;
V_209 -> V_21 = F_96 ( V_17 -> V_21 ) ;
V_45 = F_56 ( V_2 ) ;
V_17 -> V_200 = false ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_115 ( struct V_1 * V_2 , T_2 V_310 , T_2 V_311 ,
T_2 * V_225 , T_2 V_234 )
{
struct V_11 V_12 = { 0 } ;
struct V_312 * V_209 ;
int V_45 ;
V_209 = F_2 ( & V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_313 ,
sizeof( * V_209 ) , & V_12 , NULL ) ;
V_209 -> V_213 . V_234 = V_234 ;
V_209 -> V_314 = F_76 ( V_310 ) ;
V_209 -> V_315 = F_76 ( V_311 ) ;
V_209 -> V_316 = true ;
V_45 = F_92 ( V_2 , & V_12 ) ;
if ( ! V_45 ) {
struct V_317 * V_60 = F_2 ( & V_12 ) ;
* V_225 = F_8 ( V_60 -> V_292 ) ;
if ( F_116 ( V_2 ) && F_71 ( V_2 ) )
V_2 -> V_226 [ 0 ] = F_8 ( V_60 -> V_226 ) ;
}
return V_45 ;
}
int F_117 ( struct V_1 * V_2 , int V_292 , T_2 V_234 )
{
struct V_11 * V_12 ;
struct V_318 * V_209 ;
int V_45 ;
if ( V_292 == - 1 )
return 0 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_319 ,
sizeof( * V_209 ) , V_12 , NULL ) ;
V_209 -> V_213 . V_234 = V_234 ;
V_209 -> V_292 = F_76 ( V_292 ) ;
V_45 = F_56 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_118 ( struct V_1 * V_2 , struct V_152 * V_320 )
{
struct V_11 * V_12 ;
struct V_177 * V_213 ;
int V_45 = 0 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_213 = V_320 -> V_156 ;
F_75 ( V_213 , V_55 ,
V_53 , V_320 -> V_191 , V_12 ,
V_320 ) ;
if ( F_119 ( V_2 ) )
V_213 -> V_183 = 0 ;
if ( F_116 ( V_2 ) || F_70 ( V_2 ) )
V_213 -> V_183 = 1 ;
else
V_213 -> V_183 = 2 ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_171;
V_2 -> V_57 = true ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_120 ( struct V_1 * V_2 ,
struct V_152 * V_320 )
{
struct V_11 * V_12 ;
struct V_321 * V_209 ;
int V_45 = 0 ;
if ( ! F_1 ( V_2 , V_54 ,
V_55 ) )
return - V_239 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = V_320 -> V_156 ;
F_75 ( & V_209 -> V_213 , V_55 ,
V_54 , V_320 -> V_191 ,
V_12 , V_320 ) ;
V_209 -> V_322 . V_323 . V_324 = F_96 ( V_2 -> V_83 ) ;
V_209 -> V_322 . V_323 . V_325 = 0 ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_171;
V_2 -> V_57 = true ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
static int F_121 ( int V_326 )
{
switch ( V_326 ) {
case V_327 :
return 0 ;
case V_328 :
return 10 ;
case V_329 :
return 100 ;
case V_330 :
return 1000 ;
case V_331 :
return 10000 ;
case V_332 :
return 20000 ;
case V_333 :
return 25000 ;
case V_334 :
return 40000 ;
}
return 0 ;
}
int F_122 ( struct V_1 * V_2 , T_3 * V_73 ,
T_1 * V_335 , T_2 V_240 )
{
struct V_11 * V_12 ;
struct V_336 * V_209 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
if ( V_335 )
* V_335 = V_337 ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_338 ,
sizeof( * V_209 ) , V_12 , NULL ) ;
if ( ! F_119 ( V_2 ) )
V_209 -> V_213 . V_183 = 1 ;
V_209 -> V_213 . V_234 = V_240 ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_339 * V_60 = F_2 ( V_12 ) ;
if ( V_73 ) {
* V_73 = V_60 -> V_73 ?
F_26 ( V_60 -> V_73 ) * 10 :
F_121 ( V_60 -> V_326 ) ;
if ( ! V_60 -> V_340 )
* V_73 = 0 ;
}
if ( V_335 )
* V_335 = V_60 -> V_340 ;
}
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_123 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_341 * V_209 ;
int V_45 = 0 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_58 ,
sizeof( * V_209 ) , V_12 , NULL ) ;
V_45 = F_3 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_124 ( struct V_1 * V_2 , T_2 * V_342 )
{
struct V_11 * V_12 ;
struct V_343 * V_209 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_344 , sizeof( * V_209 ) , V_12 ,
NULL ) ;
V_209 -> V_345 = F_76 ( V_346 ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_347 * V_60 = F_2 ( V_12 ) ;
if ( V_342 && V_60 -> V_342 )
* V_342 = F_8 ( V_60 -> V_342 ) -
sizeof( T_2 ) ;
}
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_125 ( struct V_1 * V_2 , T_2 V_348 , void * V_349 )
{
struct V_152 V_350 ;
struct V_11 * V_12 ;
struct V_343 * V_209 ;
T_2 V_351 = 0 , V_352 , V_353 ,
V_354 = sizeof( T_2 ) , V_355 ;
int V_45 = 0 ;
if ( V_348 == 0 )
return - V_20 ;
V_352 = V_348 ;
V_350 . V_191 = sizeof( struct V_343 ) + 60 * 1024 ;
V_350 . V_156 = F_126 ( & V_2 -> V_68 -> V_69 ,
V_350 . V_191 ,
& V_350 . V_158 , V_356 ) ;
if ( ! V_350 . V_156 ) {
F_18 ( & V_2 -> V_68 -> V_69 ,
L_14 ) ;
return - V_357 ;
}
F_41 ( & V_2 -> V_201 ) ;
while ( V_352 ) {
V_353 = F_79 ( V_352 , ( T_2 ) 60 * 1024 ) ;
V_352 -= V_353 ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = V_350 . V_156 ;
V_355 = sizeof( struct V_343 ) + V_353 ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_344 , V_355 ,
V_12 , & V_350 ) ;
V_209 -> V_345 = F_76 ( V_358 ) ;
V_209 -> V_359 = F_76 ( V_354 ) ;
V_209 -> V_360 = F_76 ( V_353 ) ;
V_209 -> V_361 = F_76 ( V_353 ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_347 * V_60 = V_350 . V_156 ;
memcpy ( V_349 + V_351 ,
V_60 -> V_362 ,
F_8 ( V_60 -> V_360 ) ) ;
} else {
F_18 ( & V_2 -> V_68 -> V_69 , L_15 ) ;
goto V_171;
}
V_351 += V_353 ;
V_354 += V_353 ;
}
V_171:
F_127 ( & V_2 -> V_68 -> V_69 , V_350 . V_191 ,
V_350 . V_156 , V_350 . V_158 ) ;
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_128 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_363 * V_209 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_364 , sizeof( * V_209 ) , V_12 ,
NULL ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_365 * V_60 = F_2 ( V_12 ) ;
F_129 ( V_2 -> V_366 , V_60 -> V_367 ,
sizeof( V_2 -> V_366 ) ) ;
F_129 ( V_2 -> V_368 , V_60 -> V_369 ,
sizeof( V_2 -> V_368 ) ) ;
}
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
static int F_130 ( struct V_1 * V_2 ,
struct V_370 * V_371 , int V_136 )
{
struct V_11 * V_12 ;
struct V_372 * V_209 ;
int V_45 = 0 , V_5 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_373 , sizeof( * V_209 ) , V_12 ,
NULL ) ;
V_209 -> V_374 = F_76 ( V_136 ) ;
for ( V_5 = 0 ; V_5 < V_136 ; V_5 ++ ) {
V_209 -> V_371 [ V_5 ] . V_220 = F_76 ( V_371 [ V_5 ] . V_220 ) ;
V_209 -> V_371 [ V_5 ] . V_375 = 0 ;
V_209 -> V_371 [ V_5 ] . V_376 =
F_76 ( V_371 [ V_5 ] . V_376 ) ;
}
V_45 = F_3 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_131 ( struct V_1 * V_2 , struct V_370 * V_371 ,
int V_136 )
{
int V_377 , V_5 = 0 ;
while ( V_136 ) {
V_377 = F_79 ( V_136 , 8 ) ;
F_130 ( V_2 , & V_371 [ V_5 ] , V_377 ) ;
V_5 += V_377 ;
V_136 -= V_377 ;
}
return 0 ;
}
int F_132 ( struct V_1 * V_2 , T_2 V_230 , T_3 * V_378 ,
T_2 V_136 , T_2 V_234 )
{
struct V_11 * V_12 ;
struct V_379 * V_209 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_380 , sizeof( * V_209 ) ,
V_12 , NULL ) ;
V_209 -> V_213 . V_234 = V_234 ;
V_209 -> V_292 = V_230 ;
V_209 -> V_381 = V_382 & F_133 ( V_2 ) ? 1 : 0 ;
V_209 -> V_383 = V_136 ;
memcpy ( V_209 -> V_384 , V_378 ,
V_209 -> V_383 * sizeof( V_378 [ 0 ] ) ) ;
V_45 = F_56 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
static int F_134 ( struct V_1 * V_2 , T_2 V_28 , T_2 V_385 )
{
struct V_11 * V_12 ;
struct V_152 * V_180 = & V_2 -> V_386 ;
struct V_387 * V_209 = V_180 -> V_156 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
memset ( V_209 , 0 , sizeof( * V_209 ) ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_388 , sizeof( * V_209 ) ,
V_12 , V_180 ) ;
V_209 -> V_230 = F_76 ( V_2 -> V_225 ) ;
V_209 -> V_389 = F_76 ( V_28 ) ;
V_209 -> V_390 = ( V_385 == V_391 ) ? V_209 -> V_389 : 0 ;
if ( V_28 & V_392 ) {
struct V_393 * V_394 ;
int V_5 = 0 ;
V_209 -> V_389 |=
F_76 ( V_395 &
F_133 ( V_2 ) ) ;
V_209 -> V_396 = F_76 ( F_135 ( V_2 -> V_397 ) ) ;
F_136 (ha, adapter->netdev)
memcpy ( V_209 -> V_398 [ V_5 ++ ] . V_399 , V_394 -> V_33 , V_233 ) ;
}
V_45 = F_56 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_137 ( struct V_1 * V_2 , T_2 V_28 , T_2 V_385 )
{
struct V_81 * V_69 = & V_2 -> V_68 -> V_69 ;
if ( ( V_28 & F_133 ( V_2 ) ) != V_28 ) {
F_17 ( V_69 , L_16 , V_28 ) ;
F_17 ( V_69 , L_17 ,
F_133 ( V_2 ) ) ;
}
V_28 &= F_133 ( V_2 ) ;
if ( ! V_28 )
return - V_400 ;
return F_134 ( V_2 , V_28 , V_385 ) ;
}
int F_138 ( struct V_1 * V_2 , T_2 V_401 , T_2 V_402 )
{
struct V_11 * V_12 ;
struct V_403 * V_209 ;
int V_45 ;
if ( ! F_1 ( V_2 , V_404 ,
V_51 ) )
return - V_239 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_404 , sizeof( * V_209 ) ,
V_12 , NULL ) ;
V_209 -> V_213 . V_183 = 1 ;
V_209 -> V_405 = F_96 ( ( T_3 ) V_401 ) ;
V_209 -> V_406 = F_96 ( ( T_3 ) V_402 ) ;
V_45 = F_56 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
if ( V_34 ( V_45 ) == V_407 )
return - V_408 ;
return V_45 ;
}
int F_139 ( struct V_1 * V_2 , T_2 * V_401 , T_2 * V_402 )
{
struct V_11 * V_12 ;
struct V_409 * V_209 ;
int V_45 ;
if ( ! F_1 ( V_2 , V_410 ,
V_51 ) )
return - V_239 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_410 , sizeof( * V_209 ) ,
V_12 , NULL ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_411 * V_60 =
F_2 ( V_12 ) ;
* V_401 = F_26 ( V_60 -> V_405 ) ;
* V_402 = F_26 ( V_60 -> V_406 ) ;
}
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_140 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_412 * V_209 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_202 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_413 ,
sizeof( * V_209 ) , V_12 , NULL ) ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_414 * V_60 = F_2 ( V_12 ) ;
V_2 -> V_99 = F_8 ( V_60 -> V_415 ) ;
V_2 -> V_416 = F_8 ( V_60 -> V_416 ) ;
V_2 -> V_276 = F_8 ( V_60 -> V_276 ) ;
V_2 -> V_417 = F_8 ( V_60 -> V_418 ) & 0xFF ;
F_23 ( & V_2 -> V_68 -> V_69 ,
L_18 ,
V_2 -> V_416 , V_2 -> V_276 ) ;
}
F_90 ( & V_2 -> V_202 ) ;
return V_45 ;
}
int F_141 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_177 * V_209 ;
int V_45 ;
if ( F_70 ( V_2 ) ) {
F_6 ( V_419 ,
V_2 -> V_24 + V_420 ) ;
V_45 = F_67 ( V_2 ) ;
if ( V_45 )
F_18 ( & V_2 -> V_68 -> V_69 ,
L_19 ) ;
return V_45 ;
}
if ( F_88 ( & V_2 -> V_202 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_209 = F_2 ( V_12 ) ;
F_75 ( V_209 , V_51 ,
V_421 , sizeof( * V_209 ) , V_12 ,
NULL ) ;
V_45 = F_63 ( V_2 ) ;
F_90 ( & V_2 -> V_202 ) ;
return V_45 ;
}
int F_142 ( struct V_1 * V_2 , T_1 * V_422 ,
T_2 V_423 , T_3 V_424 , const T_1 * V_425 )
{
struct V_11 * V_12 ;
struct V_426 * V_209 ;
int V_45 ;
if ( ! ( F_133 ( V_2 ) & V_427 ) )
return 0 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_55 ,
V_428 , sizeof( * V_209 ) , V_12 , NULL ) ;
V_209 -> V_230 = F_76 ( V_2 -> V_225 ) ;
V_209 -> V_429 = F_96 ( V_423 ) ;
V_209 -> V_430 = F_96 ( F_105 ( V_424 ) - 1 ) ;
if ( ! F_20 ( V_2 ) )
V_209 -> V_213 . V_183 = 1 ;
memcpy ( V_209 -> V_431 , V_422 , V_424 ) ;
memcpy ( V_209 -> V_432 , V_425 , V_433 ) ;
F_77 ( V_209 -> V_432 , sizeof( V_209 -> V_432 ) ) ;
V_45 = F_56 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_143 ( struct V_1 * V_2 , T_1 V_99 ,
T_1 V_434 , T_1 V_435 , T_1 V_436 )
{
struct V_11 * V_12 ;
struct V_437 * V_209 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_438 ,
sizeof( * V_209 ) , V_12 , NULL ) ;
V_209 -> V_99 = V_99 ;
V_209 -> V_439 = V_436 ;
V_209 -> V_440 = V_434 ;
V_209 -> V_441 = V_435 ;
V_45 = F_56 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_144 ( struct V_1 * V_2 , T_1 V_99 , T_2 * V_436 )
{
struct V_11 * V_12 ;
struct V_442 * V_209 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_443 , sizeof( * V_209 ) ,
V_12 , NULL ) ;
V_209 -> V_99 = V_99 ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_444 * V_60 =
F_2 ( V_12 ) ;
* V_436 = V_60 -> V_439 ;
}
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_145 ( struct V_1 * V_2 ,
T_1 V_445 , T_1 * V_446 )
{
struct V_152 V_447 ;
struct V_11 * V_12 ;
struct V_448 * V_209 ;
int V_45 ;
if ( V_445 > V_449 )
return - V_450 ;
V_447 . V_191 = sizeof( struct V_451 ) ;
V_447 . V_156 = F_126 ( & V_2 -> V_68 -> V_69 , V_447 . V_191 , & V_447 . V_158 ,
V_356 ) ;
if ( ! V_447 . V_156 ) {
F_18 ( & V_2 -> V_68 -> V_69 , L_20 ) ;
return - V_357 ;
}
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = V_447 . V_156 ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_452 ,
V_447 . V_191 , V_12 , & V_447 ) ;
V_209 -> V_453 = F_76 ( V_2 -> V_83 ) ;
V_209 -> V_445 = F_76 ( V_445 ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_451 * V_60 = V_447 . V_156 ;
memcpy ( V_446 , V_60 -> V_454 , V_455 ) ;
}
V_171:
F_43 ( & V_2 -> V_201 ) ;
F_127 ( & V_2 -> V_68 -> V_69 , V_447 . V_191 , V_447 . V_156 , V_447 . V_158 ) ;
return V_45 ;
}
int F_146 ( struct V_1 * V_2 , struct V_152 * V_447 ,
T_2 V_456 , T_2 V_457 ,
const char * V_458 , T_2 * V_459 ,
T_1 * V_460 , T_1 * V_461 )
{
struct V_11 * V_12 ;
struct V_462 * V_209 ;
struct V_463 * V_60 ;
void * V_247 = NULL ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_2 -> V_52 = 0 ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_464;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_50 ,
sizeof( struct V_462 ) , V_12 ,
NULL ) ;
V_247 = & V_209 -> V_217 ;
F_97 ( struct V_465 ,
V_466 , V_247 , V_456 ) ;
if ( V_456 == 0 )
F_97 ( struct V_465 ,
V_467 , V_247 , 1 ) ;
else
F_97 ( struct V_465 ,
V_467 , V_247 , 0 ) ;
F_77 ( V_247 , sizeof( V_209 -> V_217 ) ) ;
V_209 -> V_468 = F_76 ( V_457 ) ;
F_129 ( V_209 -> V_469 , V_458 , sizeof( V_209 -> V_469 ) ) ;
V_209 -> V_470 = F_76 ( 1 ) ;
V_209 -> V_348 = F_76 ( V_456 ) ;
V_209 -> V_471 = F_76 ( ( V_447 -> V_158 +
sizeof( struct V_462 ) )
& 0xFFFFFFFF ) ;
V_209 -> V_472 = F_76 ( F_64 ( V_447 -> V_158 +
sizeof( struct V_462 ) ) ) ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_464;
F_43 ( & V_2 -> V_201 ) ;
if ( ! F_147 ( & V_2 -> V_48 ,
F_148 ( 60000 ) ) )
V_45 = - V_174 ;
else
V_45 = V_2 -> V_52 ;
V_60 = F_2 ( V_12 ) ;
if ( ! V_45 ) {
* V_459 = F_8 ( V_60 -> V_473 ) ;
* V_460 = V_60 -> V_460 ;
} else {
* V_461 = V_60 -> V_474 ;
}
return V_45 ;
V_464:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_149 ( struct V_1 * V_2 )
{
T_1 V_454 [ V_455 ] ;
int V_45 ;
V_45 = F_145 ( V_2 , V_475 ,
V_454 ) ;
if ( ! V_45 ) {
switch ( V_2 -> V_72 . V_476 ) {
case V_477 :
V_2 -> V_72 . V_478 =
V_454 [ V_479 ] ;
break;
case V_480 :
V_2 -> V_72 . V_478 =
V_454 [ V_481 ] ;
break;
default:
V_2 -> V_72 . V_478 = 0 ;
break;
}
}
return V_45 ;
}
int F_150 ( struct V_1 * V_2 )
{
T_1 V_454 [ V_455 ] ;
int V_45 ;
V_45 = F_145 ( V_2 , V_475 ,
V_454 ) ;
if ( ! V_45 ) {
F_129 ( V_2 -> V_72 . V_482 , V_454 +
V_483 , V_484 - 1 ) ;
F_129 ( V_2 -> V_72 . V_485 ,
V_454 + V_486 ,
V_484 - 1 ) ;
}
return V_45 ;
}
int F_151 ( struct V_1 * V_2 , const char * V_458 )
{
struct V_487 * V_209 ;
struct V_11 * V_12 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_488 ,
sizeof( * V_209 ) , V_12 , NULL ) ;
F_129 ( V_209 -> V_469 , V_458 , sizeof( V_209 -> V_469 ) ) ;
V_45 = F_56 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_152 ( struct V_1 * V_2 , struct V_152 * V_447 ,
T_2 V_456 , T_2 V_457 , const char * V_458 ,
T_2 * V_489 , T_2 * V_467 , T_1 * V_461 )
{
struct V_11 * V_12 ;
struct V_490 * V_209 ;
struct V_491 * V_60 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_464;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_492 ,
sizeof( struct V_490 ) , V_12 ,
NULL ) ;
V_209 -> V_493 = F_76 ( V_456 ) ;
V_209 -> V_494 = F_76 ( V_457 ) ;
strcpy ( V_209 -> V_469 , V_458 ) ;
V_209 -> V_470 = F_76 ( 1 ) ;
V_209 -> V_348 = F_76 ( V_456 ) ;
V_209 -> V_471 = F_76 ( ( V_447 -> V_158 & 0xFFFFFFFF ) ) ;
V_209 -> V_472 = F_76 ( F_64 ( V_447 -> V_158 ) ) ;
V_45 = F_56 ( V_2 ) ;
V_60 = F_2 ( V_12 ) ;
if ( ! V_45 ) {
* V_489 = F_8 ( V_60 -> V_495 ) ;
* V_467 = F_8 ( V_60 -> V_467 ) ;
} else {
* V_461 = V_60 -> V_474 ;
}
V_464:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_153 ( struct V_1 * V_2 , struct V_152 * V_447 ,
T_2 V_496 , T_2 V_497 , T_2 V_498 ,
T_2 V_353 )
{
struct V_11 * V_12 ;
struct F_153 * V_209 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_2 -> V_52 = 0 ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_464;
}
V_209 = V_447 -> V_156 ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_40 , V_447 -> V_191 , V_12 ,
V_447 ) ;
V_209 -> V_323 . V_499 = F_76 ( V_496 ) ;
if ( V_496 == V_500 )
V_209 -> V_323 . V_351 = F_76 ( V_498 ) ;
V_209 -> V_323 . V_501 = F_76 ( V_497 ) ;
V_209 -> V_323 . V_502 = F_76 ( V_353 ) ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_464;
F_43 ( & V_2 -> V_201 ) ;
if ( ! F_147 ( & V_2 -> V_48 ,
F_148 ( 40000 ) ) )
V_45 = - V_174 ;
else
V_45 = V_2 -> V_52 ;
return V_45 ;
V_464:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_154 ( struct V_1 * V_2 , T_1 * V_503 ,
T_3 V_504 , T_2 V_498 , T_2 V_505 )
{
struct V_506 * V_209 ;
struct V_11 * V_12 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_507 , sizeof( * V_209 ) ,
V_12 , NULL ) ;
V_209 -> V_323 . V_499 = F_76 ( V_504 ) ;
if ( V_504 == V_500 )
V_209 -> V_323 . V_351 = F_76 ( V_498 + V_505 ) ;
else
V_209 -> V_323 . V_351 = F_76 ( V_505 ) ;
V_209 -> V_323 . V_501 = F_76 ( V_508 ) ;
V_209 -> V_323 . V_502 = F_76 ( 0x4 ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 )
memcpy ( V_503 , V_209 -> V_509 , 4 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_155 ( struct V_1 * V_2 , T_1 * V_232 ,
struct V_152 * V_320 )
{
struct V_11 * V_12 ;
struct V_510 * V_209 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = V_320 -> V_156 ;
F_75 ( & V_209 -> V_213 , V_55 ,
V_511 , sizeof( * V_209 ) ,
V_12 , V_320 ) ;
memcpy ( V_209 -> V_512 , V_232 , V_233 ) ;
V_45 = F_56 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_156 ( struct V_1 * V_2 , T_1 V_99 ,
T_1 V_513 , T_1 V_514 )
{
struct V_11 * V_12 ;
struct V_515 * V_209 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_464;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_47 ,
V_49 , sizeof( * V_209 ) ,
V_12 , NULL ) ;
V_209 -> V_516 = V_99 ;
V_209 -> V_517 = V_99 ;
V_209 -> V_513 = V_513 ;
V_209 -> V_518 = V_514 ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_464;
F_43 ( & V_2 -> V_201 ) ;
if ( ! F_147 ( & V_2 -> V_48 ,
F_148 ( V_519 ) ) )
V_45 = - V_174 ;
return V_45 ;
V_464:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_157 ( struct V_1 * V_2 , T_2 V_99 ,
T_2 V_513 , T_2 V_520 , T_2 V_521 ,
T_5 V_522 )
{
struct V_11 * V_12 ;
struct V_523 * V_209 ;
struct V_524 * V_60 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_47 ,
V_46 , sizeof( * V_209 ) , V_12 ,
NULL ) ;
V_209 -> V_213 . V_170 = F_76 ( 15 ) ;
V_209 -> V_522 = F_158 ( V_522 ) ;
V_209 -> V_516 = F_76 ( V_99 ) ;
V_209 -> V_517 = F_76 ( V_99 ) ;
V_209 -> V_520 = F_76 ( V_520 ) ;
V_209 -> V_521 = F_76 ( V_521 ) ;
V_209 -> V_513 = F_76 ( V_513 ) ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_171;
F_43 ( & V_2 -> V_201 ) ;
F_159 ( & V_2 -> V_48 ) ;
V_60 = F_2 ( V_12 ) ;
V_45 = F_8 ( V_60 -> V_45 ) ;
return V_45 ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_160 ( struct V_1 * V_2 , T_5 V_522 ,
T_2 V_525 , struct V_152 * V_447 )
{
struct V_11 * V_12 ;
struct V_526 * V_209 ;
int V_45 ;
int V_5 , V_527 = 0 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = V_447 -> V_156 ;
F_75 ( & V_209 -> V_213 , V_47 ,
V_528 , V_447 -> V_191 , V_12 ,
V_447 ) ;
V_209 -> V_522 = F_158 ( V_522 ) ;
V_209 -> V_529 = F_76 ( V_525 ) ;
for ( V_5 = 0 ; V_5 < V_525 ; V_5 ++ ) {
V_209 -> V_530 [ V_5 ] = ( T_1 ) ( V_522 >> ( V_527 * 8 ) ) ;
V_527 ++ ;
if ( V_527 > 7 )
V_527 = 0 ;
}
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_531 * V_60 ;
V_60 = V_447 -> V_156 ;
if ( ( memcmp ( V_60 -> V_532 , V_209 -> V_530 , V_525 ) != 0 ) ||
V_60 -> V_533 ) {
V_45 = - 1 ;
}
}
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_161 ( struct V_1 * V_2 ,
struct V_152 * V_320 )
{
struct V_11 * V_12 ;
struct V_534 * V_209 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = V_320 -> V_156 ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_535 , sizeof( * V_209 ) , V_12 ,
V_320 ) ;
V_45 = F_56 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_162 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_536 * V_209 ;
struct V_152 V_447 ;
int V_45 ;
if ( ! F_1 ( V_2 , V_537 ,
V_51 ) )
return - V_239 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_447 . V_191 = sizeof( struct V_536 ) ;
V_447 . V_156 = F_126 ( & V_2 -> V_68 -> V_69 , V_447 . V_191 , & V_447 . V_158 ,
V_356 ) ;
if ( ! V_447 . V_156 ) {
F_18 ( & V_2 -> V_68 -> V_69 , L_21 ) ;
V_45 = - V_357 ;
goto V_171;
}
V_209 = V_447 . V_156 ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_537 , sizeof( * V_209 ) ,
V_12 , & V_447 ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_538 * V_539 =
V_447 . V_156 + sizeof( struct V_177 ) ;
V_2 -> V_72 . V_540 = F_26 ( V_539 -> V_540 ) ;
V_2 -> V_72 . V_476 =
F_26 ( V_539 -> V_476 ) ;
V_2 -> V_72 . V_541 =
F_26 ( V_539 -> V_541 ) ;
V_2 -> V_72 . V_542 =
F_26 ( V_539 -> V_542 ) ;
V_2 -> V_72 . V_543 =
F_8 ( V_539 -> V_543 ) ;
if ( F_119 ( V_2 ) ) {
V_2 -> V_72 . V_542 =
V_544 |
V_545 ;
}
}
F_127 ( & V_2 -> V_68 -> V_69 , V_447 . V_191 , V_447 . V_156 , V_447 . V_158 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
static int F_163 ( struct V_1 * V_2 , T_2 V_546 , T_2 V_234 )
{
struct V_11 * V_12 ;
struct V_547 * V_209 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_548 , sizeof( * V_209 ) , V_12 , NULL ) ;
V_209 -> V_213 . V_234 = V_234 ;
V_209 -> V_549 = F_76 ( V_550 ) ;
V_209 -> V_551 = F_76 ( V_546 ) ;
V_45 = F_56 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_164 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_552 * V_209 ;
struct V_553 * V_60 ;
int V_45 , V_5 ;
int V_355 = F_165 ( sizeof( * V_209 ) , sizeof( * V_60 ) ) ;
struct V_554 * V_555 ;
struct V_152 V_556 ;
T_2 * V_557 ;
if ( F_88 ( & V_2 -> V_202 ) )
return - 1 ;
memset ( & V_556 , 0 , sizeof( struct V_152 ) ) ;
V_556 . V_191 = sizeof( struct V_553 ) ;
V_556 . V_156 = F_126 ( & V_2 -> V_68 -> V_69 ,
V_556 . V_191 ,
& V_556 . V_158 , V_356 ) ;
if ( ! V_556 . V_156 ) {
F_18 ( & V_2 -> V_68 -> V_69 , L_22 ) ;
V_45 = - V_357 ;
goto V_171;
}
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = V_556 . V_156 ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_558 , V_355 ,
V_12 , & V_556 ) ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
V_555 = V_556 . V_156 + sizeof( struct V_30 ) ;
V_2 -> V_83 = V_555 -> V_559 . V_560 ;
V_2 -> V_561 = V_555 -> V_561 ;
V_557 = V_555 -> V_559 . V_562 ;
for ( V_5 = 0 ; V_5 < V_563 ; V_5 ++ )
V_2 -> V_557 [ V_5 ] = F_8 ( V_557 [ V_5 ] ) &
( F_166 ( 16 ) - 1 ) ;
}
V_171:
F_90 ( & V_2 -> V_202 ) ;
if ( V_556 . V_156 )
F_127 ( & V_2 -> V_68 -> V_69 , V_556 . V_191 ,
V_556 . V_156 , V_556 . V_158 ) ;
return V_45 ;
}
int F_167 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_564 * V_209 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_202 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_565 ,
sizeof( * V_209 ) , V_12 , NULL ) ;
V_209 -> V_566 = F_76 ( V_567 |
V_568 ) ;
V_209 -> V_310 = F_76 ( V_568 ) ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_569 * V_60 = F_2 ( V_12 ) ;
V_2 -> V_570 = F_8 ( V_60 -> V_310 ) &
V_568 ;
if ( ! V_2 -> V_570 )
F_17 ( & V_2 -> V_68 -> V_69 ,
L_23 ) ;
}
V_171:
F_90 ( & V_2 -> V_202 ) ;
return V_45 ;
}
int F_168 ( struct V_1 * V_2 , T_2 * V_571 ,
T_2 V_234 )
{
struct V_11 * V_12 ;
struct V_572 * V_209 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_573 , sizeof( * V_209 ) ,
V_12 , NULL ) ;
V_209 -> V_213 . V_234 = V_234 ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_574 * V_60 =
F_2 ( V_12 ) ;
* V_571 = F_8 ( V_60 -> V_575 ) ;
if ( F_20 ( V_2 ) && F_169 ( V_2 ) &&
F_170 ( V_2 ) )
* V_571 = V_576 ;
}
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_171 ( struct V_1 * V_2 , T_2 V_577 ,
T_2 V_234 )
{
struct V_11 * V_12 ;
struct V_578 * V_209 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_579 , sizeof( * V_209 ) ,
V_12 , NULL ) ;
V_209 -> V_213 . V_234 = V_234 ;
if ( F_70 ( V_2 ) )
V_209 -> V_580 = F_76 ( V_577 ) ;
else
V_209 -> V_577 = F_76 ( V_577 ) ;
V_45 = F_56 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_172 ( struct V_1 * V_2 , T_1 * V_232 ,
bool * V_581 , T_2 * V_226 , T_2 V_225 ,
T_1 V_234 )
{
struct V_11 * V_12 ;
struct V_582 * V_209 ;
int V_45 ;
int V_583 ;
struct V_152 V_584 ;
int V_5 ;
memset ( & V_584 , 0 , sizeof( struct V_152 ) ) ;
V_584 . V_191 = sizeof( struct V_585 ) ;
V_584 . V_156 = F_126 ( & V_2 -> V_68 -> V_69 ,
V_584 . V_191 ,
& V_584 . V_158 ,
V_356 ) ;
if ( ! V_584 . V_156 ) {
F_18 ( & V_2 -> V_68 -> V_69 ,
L_24 ) ;
return - V_357 ;
}
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_145;
}
V_209 = V_584 . V_156 ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_586 ,
V_584 . V_191 , V_12 , & V_584 ) ;
V_209 -> V_213 . V_234 = V_234 ;
V_209 -> V_587 = V_229 ;
if ( * V_581 ) {
V_209 -> V_588 = F_76 ( * V_226 ) ;
V_209 -> V_589 = F_96 ( V_225 ) ;
V_209 -> V_590 = 0 ;
} else {
V_209 -> V_590 = 1 ;
}
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_585 * V_60 =
V_584 . V_156 ;
if ( * V_581 ) {
memcpy ( V_232 , V_60 -> V_591 . V_592 . V_593 ,
V_233 ) ;
goto V_145;
}
V_583 = V_60 -> V_594 + V_60 -> V_595 ;
for ( V_5 = 0 ; V_5 < V_583 ; V_5 ++ ) {
struct V_596 * V_597 ;
T_3 V_598 ;
T_2 V_588 ;
V_597 = & V_60 -> V_599 [ V_5 ] ;
V_598 = F_26 ( V_597 -> V_598 ) ;
if ( V_598 == sizeof( T_2 ) ) {
* V_581 = true ;
V_588 = V_597 -> V_592 . V_600 . V_588 ;
* V_226 = F_8 ( V_588 ) ;
goto V_145;
}
}
* V_581 = false ;
memcpy ( V_232 , V_60 -> V_599 [ 0 ] . V_592 . V_593 ,
V_233 ) ;
}
V_145:
F_43 ( & V_2 -> V_201 ) ;
F_127 ( & V_2 -> V_68 -> V_69 , V_584 . V_191 ,
V_584 . V_156 , V_584 . V_158 ) ;
return V_45 ;
}
int F_173 ( struct V_1 * V_2 , T_2 V_601 ,
T_1 * V_232 , T_2 V_225 , bool V_602 , T_2 V_234 )
{
if ( ! V_602 )
F_172 ( V_2 , V_232 , & V_602 , & V_601 ,
V_225 , V_234 ) ;
if ( F_20 ( V_2 ) )
return F_100 ( V_2 , V_232 , false ,
V_225 , V_601 ) ;
else
return F_172 ( V_2 , V_232 , & V_602 ,
& V_601 ,
V_225 , V_234 ) ;
}
int F_174 ( struct V_1 * V_2 , T_1 * V_232 )
{
int V_45 ;
bool V_603 = false ;
F_175 ( V_232 ) ;
if ( F_20 ( V_2 ) ) {
if ( F_170 ( V_2 ) )
V_45 = F_100 ( V_2 , V_232 , true , 0 ,
0 ) ;
else
V_45 = F_100 ( V_2 , V_232 , false ,
V_2 -> V_225 , 0 ) ;
} else {
V_45 = F_172 ( V_2 , V_232 , & V_603 ,
NULL , V_2 -> V_225 , 0 ) ;
}
return V_45 ;
}
int F_176 ( struct V_1 * V_2 , T_1 * V_604 ,
T_1 V_583 , T_2 V_234 )
{
struct V_11 * V_12 ;
struct V_605 * V_209 ;
int V_45 ;
struct V_152 V_447 ;
memset ( & V_447 , 0 , sizeof( struct V_152 ) ) ;
V_447 . V_191 = sizeof( struct V_605 ) ;
V_447 . V_156 = F_126 ( & V_2 -> V_68 -> V_69 , V_447 . V_191 , & V_447 . V_158 ,
V_606 ) ;
if ( ! V_447 . V_156 )
return - V_357 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = V_447 . V_156 ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_607 , sizeof( * V_209 ) ,
V_12 , & V_447 ) ;
V_209 -> V_213 . V_234 = V_234 ;
V_209 -> V_583 = V_583 ;
if ( V_583 )
memcpy ( V_209 -> V_232 , V_604 , V_233 * V_583 ) ;
V_45 = F_56 ( V_2 ) ;
V_171:
F_127 ( & V_2 -> V_68 -> V_69 , V_447 . V_191 , V_447 . V_156 , V_447 . V_158 ) ;
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_177 ( struct V_1 * V_2 , T_1 * V_232 , int V_230 , T_2 V_240 )
{
bool V_608 = false ;
T_1 V_609 [ V_233 ] ;
T_2 V_226 ;
int V_45 ;
V_45 = F_172 ( V_2 , V_609 , & V_608 ,
& V_226 , V_230 , V_240 ) ;
if ( ! V_45 && V_608 )
F_102 ( V_2 , V_230 , V_226 , V_240 ) ;
return F_176 ( V_2 , V_232 , V_232 ? 1 : 0 , V_240 ) ;
}
int F_178 ( struct V_1 * V_2 , T_3 V_103 ,
T_2 V_234 , T_3 V_610 , T_3 V_611 , T_1 V_612 )
{
struct V_11 * V_12 ;
struct V_613 * V_209 ;
void * V_247 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
V_247 = & V_209 -> V_217 ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_614 , sizeof( * V_209 ) , V_12 ,
NULL ) ;
V_209 -> V_213 . V_234 = V_234 ;
F_97 ( struct V_615 , V_292 , V_247 , V_610 ) ;
if ( V_103 ) {
F_97 ( struct V_615 , V_616 , V_247 , 1 ) ;
F_97 ( struct V_615 , V_103 , V_247 , V_103 ) ;
}
if ( ! F_20 ( V_2 ) && V_611 ) {
F_97 ( struct V_615 , V_292 ,
V_247 , V_2 -> V_83 ) ;
F_97 ( struct V_615 , V_617 , V_247 , 1 ) ;
F_97 ( struct V_615 , V_618 ,
V_247 , V_611 ) ;
}
if ( ! F_20 ( V_2 ) && V_612 ) {
F_97 ( struct V_615 , V_619 ,
V_247 , V_612 ) ;
F_97 ( struct V_615 , V_620 ,
V_247 , V_612 ) ;
}
F_77 ( V_209 -> V_217 , sizeof( V_209 -> V_217 ) ) ;
V_45 = F_56 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_179 ( struct V_1 * V_2 , T_3 * V_103 ,
T_2 V_234 , T_3 V_610 , T_1 * V_621 , bool * V_612 )
{
struct V_11 * V_12 ;
struct V_622 * V_209 ;
void * V_247 ;
int V_45 ;
T_3 V_623 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
V_247 = & V_209 -> V_217 ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_624 , sizeof( * V_209 ) , V_12 ,
NULL ) ;
V_209 -> V_213 . V_234 = V_234 ;
F_97 ( struct V_625 , V_292 ,
V_247 , V_610 ) ;
F_97 ( struct V_625 , V_616 , V_247 , 1 ) ;
if ( ! F_20 ( V_2 ) && V_621 ) {
F_97 ( struct V_625 , V_292 ,
V_247 , V_2 -> V_83 ) ;
F_97 ( struct V_625 , V_617 , V_247 , 1 ) ;
}
F_77 ( V_209 -> V_217 , sizeof( V_209 -> V_217 ) ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_626 * V_60 =
F_2 ( V_12 ) ;
F_16 ( & V_60 -> V_217 , sizeof( V_60 -> V_217 ) ) ;
V_623 = F_180 ( struct V_627 ,
V_103 , & V_60 -> V_217 ) ;
if ( V_103 )
* V_103 = F_26 ( V_623 ) ;
if ( V_621 )
* V_621 = F_180 ( struct V_627 ,
V_618 , & V_60 -> V_217 ) ;
if ( V_612 )
* V_612 =
F_180 ( struct V_627 ,
V_612 , & V_60 -> V_217 ) ;
}
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
static bool F_181 ( struct V_1 * V_2 )
{
struct V_628 * V_68 = V_2 -> V_68 ;
if ( F_71 ( V_2 ) )
return true ;
switch ( V_68 -> V_629 ) {
case V_630 :
case V_631 :
case V_632 :
case V_633 :
return true ;
default:
return false ;
}
}
int F_182 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_634 * V_209 ;
int V_45 = 0 ;
struct V_152 V_447 ;
if ( ! F_1 ( V_2 , V_511 ,
V_55 ) )
return - V_239 ;
if ( F_181 ( V_2 ) )
return V_45 ;
if ( F_88 ( & V_2 -> V_202 ) )
return - 1 ;
memset ( & V_447 , 0 , sizeof( struct V_152 ) ) ;
V_447 . V_191 = sizeof( struct V_635 ) ;
V_447 . V_156 = F_126 ( & V_2 -> V_68 -> V_69 , V_447 . V_191 , & V_447 . V_158 ,
V_356 ) ;
if ( ! V_447 . V_156 ) {
F_18 ( & V_2 -> V_68 -> V_69 , L_22 ) ;
V_45 = - V_357 ;
goto V_171;
}
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = V_447 . V_156 ;
F_75 ( & V_209 -> V_213 , V_55 ,
V_511 ,
sizeof( * V_209 ) , V_12 , & V_447 ) ;
V_209 -> V_213 . V_183 = 1 ;
V_209 -> V_636 = V_637 ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_635 * V_60 ;
V_60 = (struct V_635 * ) V_447 . V_156 ;
V_2 -> V_638 = V_60 -> V_639 ;
if ( V_2 -> V_638 & V_640 )
V_2 -> V_641 = true ;
}
V_171:
F_90 ( & V_2 -> V_202 ) ;
if ( V_447 . V_156 )
F_127 ( & V_2 -> V_68 -> V_69 , V_447 . V_191 , V_447 . V_156 ,
V_447 . V_158 ) ;
return V_45 ;
}
int F_183 ( struct V_1 * V_2 , T_2 V_642 )
{
struct V_152 V_643 ;
struct V_644 * V_645 ;
int V_45 ;
int V_5 , V_527 ;
memset ( & V_643 , 0 , sizeof( struct V_152 ) ) ;
V_643 . V_191 = sizeof( struct V_646 ) ;
V_643 . V_156 = F_126 ( & V_2 -> V_68 -> V_69 ,
V_643 . V_191 , & V_643 . V_158 ,
V_356 ) ;
if ( ! V_643 . V_156 )
return - V_357 ;
V_45 = F_184 ( V_2 , & V_643 ) ;
if ( V_45 )
goto V_171;
V_645 = (struct V_644 * )
( V_643 . V_156 + sizeof( struct V_30 ) ) ;
for ( V_5 = 0 ; V_5 < F_8 ( V_645 -> V_647 ) ; V_5 ++ ) {
T_2 V_648 = F_8 ( V_645 -> V_649 [ V_5 ] . V_648 ) ;
for ( V_527 = 0 ; V_527 < V_648 ; V_527 ++ ) {
if ( V_645 -> V_649 [ V_5 ] . V_650 [ V_527 ] . V_621 == V_651 )
V_645 -> V_649 [ V_5 ] . V_650 [ V_527 ] . V_652 =
F_76 ( V_642 ) ;
}
}
V_45 = F_185 ( V_2 , & V_643 , V_645 ) ;
V_171:
F_127 ( & V_2 -> V_68 -> V_69 , V_643 . V_191 , V_643 . V_156 ,
V_643 . V_158 ) ;
return V_45 ;
}
int F_186 ( struct V_1 * V_2 )
{
struct V_152 V_643 ;
struct V_644 * V_645 ;
int V_45 , V_527 ;
int V_642 = 0 ;
memset ( & V_643 , 0 , sizeof( struct V_152 ) ) ;
V_643 . V_191 = sizeof( struct V_646 ) ;
V_643 . V_156 = F_126 ( & V_2 -> V_68 -> V_69 ,
V_643 . V_191 , & V_643 . V_158 ,
V_356 ) ;
if ( ! V_643 . V_156 ) {
F_18 ( & V_2 -> V_68 -> V_69 , L_25 ,
V_653 ) ;
goto V_171;
}
V_45 = F_184 ( V_2 , & V_643 ) ;
if ( ! V_45 ) {
V_645 = (struct V_644 * ) ( V_643 . V_156 +
sizeof( struct V_30 ) ) ;
for ( V_527 = 0 ; V_527 < F_8 ( V_645 -> V_649 [ 0 ] . V_648 ) ; V_527 ++ ) {
if ( V_645 -> V_649 [ 0 ] . V_650 [ V_527 ] . V_621 == V_651 )
V_642 = V_645 -> V_649 [ 0 ] . V_650 [ V_527 ] . V_652 ;
}
}
F_127 ( & V_2 -> V_68 -> V_69 , V_643 . V_191 , V_643 . V_156 ,
V_643 . V_158 ) ;
V_171:
return V_642 ;
}
int F_184 ( struct V_1 * V_2 ,
struct V_152 * V_447 )
{
struct V_11 * V_12 ;
struct V_654 * V_209 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_202 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = V_447 -> V_156 ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_655 ,
V_447 -> V_191 , V_12 , V_447 ) ;
V_209 -> V_656 = F_76 ( 1 ) ;
V_45 = F_63 ( V_2 ) ;
V_171:
F_90 ( & V_2 -> V_202 ) ;
return V_45 ;
}
int F_185 ( struct V_1 * V_2 ,
struct V_152 * V_447 ,
struct V_644 * V_657 )
{
struct V_11 * V_12 ;
struct V_658 * V_209 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = V_447 -> V_156 ;
memcpy ( & V_209 -> V_659 , V_657 , sizeof( struct V_644 ) ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_660 ,
V_447 -> V_191 , V_12 , V_447 ) ;
V_45 = F_56 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_187 ( struct V_1 * V_2 )
{
struct V_661 * V_209 ;
struct V_11 * V_12 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_202 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_662 , sizeof( * V_209 ) , V_12 ,
NULL ) ;
if ( ! F_20 ( V_2 ) )
V_209 -> V_213 . V_183 = 1 ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_663 * V_60 = F_2 ( V_12 ) ;
V_2 -> V_84 = V_60 -> V_84 [ V_2 -> V_83 ] ;
} else {
V_2 -> V_84 = V_2 -> V_83 + '0' ;
}
F_90 ( & V_2 -> V_202 ) ;
return V_45 ;
}
static struct V_664 * F_188 ( T_1 * V_349 , T_2 V_665 ,
int V_666 )
{
struct V_667 * V_213 = (struct V_667 * ) V_349 ;
struct V_664 * V_668 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_665 ; V_5 ++ ) {
if ( V_213 -> V_666 == V_669 ||
V_213 -> V_666 == V_670 ) {
V_668 = (struct V_664 * ) V_213 ;
if ( V_666 == V_671 ||
( V_666 == V_672 &&
V_668 -> V_28 & ( 1 << V_673 ) ) )
return V_668 ;
}
V_213 -> V_674 = V_213 -> V_674 ? : V_675 ;
V_213 = ( void * ) V_213 + V_213 -> V_674 ;
}
return NULL ;
}
static struct V_664 * F_189 ( T_1 * V_349 , T_2 V_665 )
{
return F_188 ( V_349 , V_665 , V_672 ) ;
}
static struct V_664 * F_190 ( T_1 * V_349 , T_2 V_665 )
{
return F_188 ( V_349 , V_665 , V_671 ) ;
}
static struct V_676 * F_191 ( T_1 V_677 , T_1 * V_349 ,
T_2 V_665 )
{
struct V_667 * V_213 = (struct V_667 * ) V_349 ;
struct V_676 * V_678 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_665 ; V_5 ++ ) {
if ( ( V_213 -> V_666 == V_679 ||
V_213 -> V_666 == V_680 ) ) {
V_678 = (struct V_676 * ) V_213 ;
if ( V_678 -> V_681 == V_677 )
return V_678 ;
}
V_213 -> V_674 = V_213 -> V_674 ? : V_675 ;
V_213 = ( void * ) V_213 + V_213 -> V_674 ;
}
return NULL ;
}
static struct V_682 * F_192 ( T_1 * V_349 , T_2 V_665 )
{
struct V_667 * V_213 = (struct V_667 * ) V_349 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_665 ; V_5 ++ ) {
if ( V_213 -> V_666 == V_683 )
return (struct V_682 * ) V_213 ;
V_213 -> V_674 = V_213 -> V_674 ? : V_675 ;
V_213 = ( void * ) V_213 + V_213 -> V_674 ;
}
return NULL ;
}
static void F_193 ( struct V_684 * V_685 ,
struct V_664 * V_686 )
{
V_685 -> V_687 = F_26 ( V_686 -> V_688 ) ;
V_685 -> V_689 = F_26 ( V_686 -> V_690 ) ;
V_685 -> V_691 = F_26 ( V_686 -> V_692 ) ;
V_685 -> V_693 = F_26 ( V_686 -> V_694 ) ;
V_685 -> V_695 = F_26 ( V_686 -> V_696 ) ;
V_685 -> V_697 = F_26 ( V_686 -> V_698 ) ;
V_685 -> V_699 = F_26 ( V_686 -> V_700 ) ;
V_685 -> V_701 = F_26 ( V_686 -> V_702 ) ;
V_685 -> V_703 = F_26 ( V_686 -> V_704 ) ;
V_685 -> V_705 = F_26 ( V_686 -> V_706 ) ;
V_685 -> V_707 = F_8 ( V_686 -> V_310 ) &
V_708 ;
}
int F_194 ( struct V_1 * V_2 , struct V_684 * V_685 )
{
struct V_11 * V_12 ;
struct V_709 * V_209 ;
int V_45 ;
struct V_152 V_447 ;
if ( F_88 ( & V_2 -> V_202 ) )
return - 1 ;
memset ( & V_447 , 0 , sizeof( struct V_152 ) ) ;
V_447 . V_191 = sizeof( struct V_710 ) ;
V_447 . V_156 = F_126 ( & V_2 -> V_68 -> V_69 , V_447 . V_191 , & V_447 . V_158 ,
V_356 ) ;
if ( ! V_447 . V_156 ) {
F_18 ( & V_2 -> V_68 -> V_69 , L_21 ) ;
V_45 = - V_357 ;
goto V_171;
}
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = V_447 . V_156 ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_711 ,
V_447 . V_191 , V_12 , & V_447 ) ;
if ( F_195 ( V_2 ) )
V_209 -> V_213 . V_183 = 1 ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_710 * V_60 = V_447 . V_156 ;
T_2 V_665 = F_8 ( V_60 -> V_665 ) ;
struct V_664 * V_686 ;
V_686 = F_190 ( V_60 -> V_712 , V_665 ) ;
if ( ! V_686 ) {
V_45 = - V_450 ;
goto V_171;
}
V_2 -> V_713 = V_686 -> V_681 ;
F_193 ( V_685 , V_686 ) ;
}
V_171:
F_90 ( & V_2 -> V_202 ) ;
if ( V_447 . V_156 )
F_127 ( & V_2 -> V_68 -> V_69 , V_447 . V_191 , V_447 . V_156 ,
V_447 . V_158 ) ;
return V_45 ;
}
int F_196 ( struct V_1 * V_2 ,
struct V_684 * V_685 , T_1 V_714 , T_1 V_234 )
{
struct V_715 * V_60 ;
struct V_716 * V_209 ;
struct V_664 * V_717 ;
struct V_676 * V_678 ;
struct V_682 * V_453 ;
struct V_664 * V_668 ;
struct V_11 V_12 = { 0 } ;
struct V_152 V_447 ;
T_3 V_665 ;
int V_45 ;
memset ( & V_447 , 0 , sizeof( struct V_152 ) ) ;
V_447 . V_191 = sizeof( struct V_715 ) ;
V_447 . V_156 = F_126 ( & V_2 -> V_68 -> V_69 , V_447 . V_191 , & V_447 . V_158 ,
V_356 ) ;
if ( ! V_447 . V_156 )
return - V_357 ;
V_209 = V_447 . V_156 ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_718 ,
V_447 . V_191 , & V_12 , & V_447 ) ;
if ( ! F_70 ( V_2 ) )
V_209 -> V_213 . V_183 = 1 ;
V_209 -> type = V_719 ;
V_209 -> V_213 . V_234 = V_234 ;
if ( V_234 == 0 )
V_209 -> V_213 . V_681 = V_2 -> V_561 + 1 ;
if ( V_714 == V_720 )
V_209 -> type |= V_721 ;
V_45 = F_92 ( V_2 , & V_12 ) ;
if ( V_45 )
goto V_171;
V_60 = V_447 . V_156 ;
V_665 = F_26 ( V_60 -> V_665 ) ;
V_678 = F_191 ( V_2 -> V_68 -> V_677 , V_60 -> V_712 ,
V_665 ) ;
if ( V_678 )
V_685 -> V_722 = F_26 ( V_678 -> V_723 ) ;
V_453 = F_192 ( V_60 -> V_712 , V_665 ) ;
if ( V_453 )
V_2 -> V_724 = V_453 -> V_724 ;
V_668 = F_190 ( V_60 -> V_712 , V_665 ) ;
if ( V_668 )
F_193 ( V_685 , V_668 ) ;
V_717 = F_189 ( V_60 -> V_712 , V_665 ) ;
if ( V_717 )
V_685 -> V_725 = V_717 -> V_310 ;
V_171:
if ( V_447 . V_156 )
F_127 ( & V_2 -> V_68 -> V_69 , V_447 . V_191 , V_447 . V_156 ,
V_447 . V_158 ) ;
return V_45 ;
}
static int F_197 ( struct V_1 * V_2 , void * V_686 ,
int V_191 , int V_218 , T_1 V_183 , T_1 V_234 )
{
struct V_726 * V_209 ;
struct V_11 V_12 = { 0 } ;
struct V_152 V_447 ;
int V_45 ;
memset ( & V_447 , 0 , sizeof( struct V_152 ) ) ;
V_447 . V_191 = sizeof( struct V_726 ) ;
V_447 . V_156 = F_126 ( & V_2 -> V_68 -> V_69 , V_447 . V_191 , & V_447 . V_158 ,
V_356 ) ;
if ( ! V_447 . V_156 )
return - V_357 ;
V_209 = V_447 . V_156 ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_727 , V_447 . V_191 ,
& V_12 , & V_447 ) ;
V_209 -> V_213 . V_183 = V_183 ;
V_209 -> V_213 . V_234 = V_234 ;
V_209 -> V_665 = F_76 ( V_218 ) ;
memcpy ( V_209 -> V_686 , V_686 , V_191 ) ;
V_45 = F_92 ( V_2 , & V_12 ) ;
if ( V_447 . V_156 )
F_127 ( & V_2 -> V_68 -> V_69 , V_447 . V_191 , V_447 . V_156 ,
V_447 . V_158 ) ;
return V_45 ;
}
static void F_198 ( struct V_664 * V_668 )
{
memset ( V_668 , 0 , sizeof( * V_668 ) ) ;
V_668 -> V_688 = 0xFFFF ;
V_668 -> V_706 = 0xFFFF ;
V_668 -> V_690 = 0xFFFF ;
V_668 -> V_692 = 0xFFFF ;
V_668 -> V_694 = 0xFFFF ;
V_668 -> V_698 = 0xFFFF ;
V_668 -> V_696 = 0xFFFF ;
V_668 -> V_728 = 0xFFFF ;
V_668 -> V_702 = 0xFFFF ;
V_668 -> V_729 = 0xFFFF ;
V_668 -> V_700 = 0xFFFF ;
V_668 -> V_704 = 0xFFFF ;
V_668 -> V_730 = 0xFF ;
V_668 -> V_731 = F_96 ( 0xF000 ) ;
V_668 -> V_732 = 0xFF ;
V_668 -> V_733 = 0x0F ;
V_668 -> V_734 = 0xFFFF ;
V_668 -> V_735 = 0xFFFF ;
V_668 -> V_736 = 0xFFFFFFFF ;
V_668 -> V_737 = 0xFFFFFFFF ;
}
static void F_199 ( struct V_676 * V_678 )
{
memset ( V_678 , 0 , sizeof( * V_678 ) ) ;
V_678 -> V_738 = 0xFF ;
V_678 -> V_739 = 0xFF ;
V_678 -> V_740 = 0xFF ;
V_678 -> V_723 = 0xFFFF ;
}
int F_200 ( struct V_1 * V_2 , T_2 V_741 , T_3 V_73 ,
T_1 V_234 )
{
struct V_664 V_742 ;
T_2 V_743 ;
T_3 V_183 = 0 ;
if ( F_116 ( V_2 ) )
return F_163 ( V_2 , V_741 / 10 , V_234 ) ;
F_198 ( & V_742 ) ;
V_742 . V_681 = V_2 -> V_713 ;
V_742 . V_744 = V_234 ;
V_742 . V_736 = 0 ;
if ( F_70 ( V_2 ) ) {
V_742 . V_213 . V_666 = V_669 ;
V_742 . V_213 . V_674 = V_675 ;
V_742 . V_28 = ( 1 << V_745 ) | ( 1 << V_746 ) |
( 1 << V_747 ) ;
V_742 . V_737 = F_76 ( V_741 / 10 ) ;
} else {
V_183 = 1 ;
V_742 . V_213 . V_666 = V_670 ;
V_742 . V_213 . V_674 = V_748 ;
V_742 . V_28 = ( 1 << V_746 ) | ( 1 << V_747 ) ;
V_743 = V_741 ? ( V_741 * 100 ) / V_73 : 100 ;
V_742 . V_737 = F_76 ( V_743 ) ;
}
return F_197 ( V_2 , & V_742 ,
V_742 . V_213 . V_674 ,
1 , V_183 , V_234 ) ;
}
static void F_201 ( struct V_1 * V_2 ,
struct V_684 V_749 ,
T_3 V_723 , T_3 V_750 ,
struct V_664 * V_751 )
{
T_2 V_725 = V_749 . V_725 ;
struct V_684 V_752 = { 0 } ;
F_196 ( V_2 , & V_752 , V_720 , 0 ) ;
if ( V_752 . V_725 & V_427 ) {
V_751 -> V_28 |= F_107 ( V_753 ) ;
if ( V_750 > 1 ) {
V_725 |= V_427 ;
if ( V_749 . V_707 & V_754 )
V_725 |= V_754 ;
} else {
V_725 &= ~ ( V_427 |
V_754 ) ;
}
} else {
V_750 = 1 ;
}
if ( V_752 . V_725 & V_755 ) {
V_751 -> V_28 |= F_107 ( V_753 ) ;
V_725 &= ~ V_755 ;
}
V_751 -> V_310 = F_76 ( V_725 ) ;
V_751 -> V_698 = F_96 ( V_750 ) ;
V_751 -> V_694 = F_96 ( V_750 ) ;
V_751 -> V_696 = F_96 ( V_750 ) ;
V_751 -> V_702 = F_96 ( V_749 . V_701 /
( V_723 + 1 ) ) ;
if ( V_752 . V_687 == V_756 )
V_751 -> V_688 = F_96 ( V_749 . V_687 /
( V_723 + 1 ) ) ;
if ( V_752 . V_689 == V_756 )
V_751 -> V_690 = F_96 ( V_749 . V_689 /
( V_723 + 1 ) ) ;
if ( V_752 . V_703 == V_756 )
V_751 -> V_704 = F_96 ( V_749 . V_703 /
( V_723 + 1 ) ) ;
if ( V_752 . V_705 == V_756 )
V_751 -> V_706 = F_96 ( V_749 . V_705 /
( V_723 + 1 ) ) ;
}
int F_202 ( struct V_1 * V_2 ,
struct V_684 V_749 , T_3 V_723 ,
T_3 V_750 )
{
struct {
struct V_676 V_678 ;
struct V_664 V_751 ;
} V_757 V_686 ;
F_199 ( & V_686 . V_678 ) ;
V_686 . V_678 . V_213 . V_666 = V_680 ;
V_686 . V_678 . V_213 . V_674 = V_748 ;
V_686 . V_678 . V_28 = F_107 ( V_746 ) | F_107 ( V_747 ) ;
V_686 . V_678 . V_681 = V_2 -> V_68 -> V_677 ;
V_686 . V_678 . V_738 = V_723 ? 1 : 0 ;
V_686 . V_678 . V_723 = F_96 ( V_723 ) ;
F_198 ( & V_686 . V_751 ) ;
V_686 . V_751 . V_213 . V_666 = V_670 ;
V_686 . V_751 . V_213 . V_674 = V_748 ;
V_686 . V_751 . V_28 = F_107 ( V_673 ) | F_107 ( V_746 ) | F_107 ( V_747 ) ;
V_686 . V_751 . V_681 = V_2 -> V_68 -> V_677 ;
V_686 . V_751 . V_744 = 0 ;
F_201 ( V_2 , V_749 , V_723 , V_750 ,
& V_686 . V_751 ) ;
return F_197 ( V_2 , & V_686 ,
2 * V_748 , 2 , 1 , 0 ) ;
}
int F_203 ( struct V_1 * V_2 , T_2 V_758 , T_1 V_759 )
{
struct V_11 * V_12 ;
struct V_760 * V_209 ;
int V_45 ;
if ( V_758 == 0xFFFFFFFF )
return - 1 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_761 , sizeof( * V_209 ) ,
V_12 , NULL ) ;
V_209 -> V_759 = V_759 ;
V_209 -> V_762 = F_76 ( V_758 ) ;
V_45 = F_56 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_204 ( struct V_1 * V_2 , T_6 V_453 )
{
struct V_682 V_763 ;
memset ( & V_763 , 0 , sizeof( V_763 ) ) ;
V_763 . V_213 . V_666 = V_683 ;
V_763 . V_213 . V_674 = V_748 ;
V_763 . V_28 = ( 1 << V_746 ) | ( 1 << V_747 ) ;
V_763 . V_764 = V_2 -> V_83 ;
if ( V_453 ) {
V_763 . V_765 = V_766 | ( 1 << V_767 ) |
( 1 << V_768 ) ;
V_763 . V_769 = F_205 ( V_453 ) ;
} else {
V_763 . V_765 = V_770 ;
V_763 . V_769 = 0 ;
}
return F_197 ( V_2 , & V_763 ,
V_748 , 1 , 1 , 0 ) ;
}
int F_206 ( struct V_1 * V_2 , struct V_771 * V_772 ,
int V_744 )
{
struct V_11 * V_12 ;
struct V_773 * V_209 ;
struct V_774 * V_60 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_775 , sizeof( * V_60 ) ,
V_12 , NULL ) ;
V_209 -> V_213 . V_234 = V_744 + 1 ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
V_60 = (struct V_774 * ) V_209 ;
V_772 -> V_225 = F_8 ( V_60 -> V_776 . V_230 ) ;
}
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
static int F_207 ( struct V_1 * V_2 )
{
#define F_208 30
T_2 V_777 ;
int V_45 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < F_208 ; V_5 ++ ) {
V_777 = F_60 ( V_2 -> V_24 + V_778 ) ;
if ( ( V_777 & V_779 ) == 0 )
break;
F_209 ( 1 ) ;
}
if ( V_5 == F_208 )
V_45 = - 1 ;
return V_45 ;
}
int F_210 ( struct V_1 * V_2 , T_2 V_780 )
{
int V_45 = 0 ;
V_45 = F_207 ( V_2 ) ;
if ( V_45 )
return V_45 ;
F_6 ( V_780 , V_2 -> V_24 + V_778 ) ;
return V_45 ;
}
bool F_211 ( struct V_1 * V_2 )
{
T_2 V_164 = 0 ;
V_164 = F_60 ( V_2 -> V_24 + V_165 ) ;
return ! ! ( V_164 & V_781 ) ;
}
int F_212 ( struct V_1 * V_2 )
{
struct V_81 * V_69 = & V_2 -> V_68 -> V_69 ;
int V_45 ;
if ( F_211 ( V_2 ) ) {
F_23 ( V_69 , L_26 ) ;
return - V_782 ;
}
V_45 = F_210 ( V_2 , V_783 |
V_784 ) ;
if ( V_45 < 0 ) {
F_18 ( V_69 , L_27 ) ;
return V_45 ;
}
V_45 = F_207 ( V_2 ) ;
if ( V_45 )
return V_45 ;
if ( ! F_211 ( V_2 ) ) {
F_18 ( V_69 , L_28 ) ;
return - V_20 ;
}
return 0 ;
}
int F_213 ( struct V_1 * V_2 )
{
int V_45 ;
V_45 = F_151 ( V_2 , V_785 ) ;
return F_214 ( V_45 ) ;
}
int F_215 ( struct V_1 * V_2 , T_1 V_234 )
{
struct V_11 * V_12 ;
struct V_786 * V_209 ;
int V_45 ;
if ( F_20 ( V_2 ) )
return 0 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_787 , sizeof( * V_209 ) ,
V_12 , NULL ) ;
V_209 -> V_213 . V_234 = V_234 ;
V_209 -> V_514 = 1 ;
V_45 = F_56 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_216 ( struct V_1 * V_2 , bool V_788 )
{
struct V_11 * V_12 ;
struct V_789 * V_209 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_202 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_790 , sizeof( * V_209 ) ,
V_12 , NULL ) ;
V_209 -> V_791 = V_788 ;
V_45 = F_63 ( V_2 ) ;
F_90 ( & V_2 -> V_202 ) ;
return V_45 ;
}
int F_217 ( struct V_1 * V_2 , T_3 * V_792 )
{
struct V_793 * V_209 ;
struct V_11 * V_12 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_202 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_794 , sizeof( * V_209 ) ,
V_12 , NULL ) ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_795 * V_60 =
F_2 ( V_12 ) ;
* V_792 = F_26 ( V_60 -> V_796 ) ;
}
V_171:
F_90 ( & V_2 -> V_202 ) ;
return V_45 ;
}
int F_218 ( struct V_1 * V_2 ,
int V_797 , T_1 V_234 )
{
struct V_11 * V_12 ;
struct V_798 * V_209 ;
int V_45 ;
if ( F_20 ( V_2 ) || F_70 ( V_2 ) )
return - V_408 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
F_75 ( & V_209 -> V_213 , V_51 ,
V_799 ,
sizeof( * V_209 ) , V_12 , NULL ) ;
V_209 -> V_213 . V_183 = 1 ;
V_209 -> V_213 . V_234 = V_234 ;
if ( V_797 == V_800 )
V_209 -> V_801 |= 1 ;
if ( V_797 == V_802 )
V_209 -> V_801 |= 1 << V_803 ;
V_45 = F_56 ( V_2 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_219 ( void * V_804 , void * V_805 ,
int V_806 , T_3 * V_807 , T_3 * V_808 )
{
struct V_1 * V_2 = F_220 ( V_804 ) ;
struct V_11 * V_12 ;
struct V_177 * V_213 = (struct V_177 * ) V_805 ;
struct V_177 * V_209 ;
struct V_30 * V_60 ;
int V_45 ;
F_41 ( & V_2 -> V_201 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_204 ;
goto V_171;
}
V_209 = F_2 ( V_12 ) ;
V_60 = F_2 ( V_12 ) ;
F_75 ( V_209 , V_213 -> V_4 ,
V_213 -> V_3 , V_806 , V_12 , NULL ) ;
memcpy ( V_209 , V_805 , V_806 ) ;
F_77 ( V_209 , V_806 ) ;
V_45 = F_56 ( V_2 ) ;
if ( V_807 )
* V_807 = ( V_45 & 0xffff ) ;
if ( V_808 )
* V_808 = 0 ;
memcpy ( V_805 , V_60 , sizeof( * V_60 ) + V_60 -> V_809 ) ;
F_16 ( V_805 , sizeof( * V_60 ) + V_60 -> V_809 ) ;
V_171:
F_43 ( & V_2 -> V_201 ) ;
return V_45 ;
}
