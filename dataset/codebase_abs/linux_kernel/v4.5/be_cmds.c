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
V_2 -> V_93 =
V_71 -> V_94 << V_95 ;
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_96 * V_71 =
(struct V_96 * ) V_27 ;
if ( V_2 -> V_72 . V_73 >= 0 &&
V_71 -> V_97 == V_2 -> V_98 )
V_2 -> V_72 . V_73 = F_26 ( V_71 -> V_99 ) * 10 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_100 * V_71 =
(struct V_100 * ) V_27 ;
if ( V_71 -> V_101 ) {
V_2 -> V_102 = F_26 ( V_71 -> V_103 ) & V_104 ;
F_23 ( & V_2 -> V_68 -> V_69 , L_4 , V_2 -> V_102 ) ;
} else {
V_2 -> V_102 = 0 ;
}
}
static void F_28 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_105 * V_71 = (struct V_105 * ) V_27 ;
T_2 V_106 = F_8 ( V_71 -> V_80 ) ;
if ( V_106 & V_107 ) {
V_2 -> V_28 |= V_108 ;
V_2 -> V_109 = F_8 ( V_71 -> V_110 ) ;
} else {
V_2 -> V_28 &= ~ V_108 ;
}
}
static void F_29 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
T_1 V_111 = ( V_27 -> V_28 >> V_112 ) &
V_113 ;
switch ( V_111 ) {
case V_114 :
F_24 ( V_2 , V_27 ) ;
break;
case V_115 :
F_25 ( V_2 , V_27 ) ;
break;
case V_116 :
F_27 ( V_2 , V_27 ) ;
break;
case V_117 :
F_28 ( V_2 , V_27 ) ;
break;
default:
break;
}
}
static void F_30 ( struct V_1 * V_2 ,
struct V_26 * V_118 )
{
T_1 V_111 = 0 ;
struct V_119 * V_71 = (struct V_119 * ) V_118 ;
V_111 = ( V_118 -> V_28 >> V_112 ) &
V_113 ;
switch ( V_111 ) {
case V_120 :
if ( V_71 -> V_90 )
V_2 -> V_121 = F_26 ( V_71 -> V_122 ) ;
V_2 -> V_28 |= V_123 ;
break;
default:
F_17 ( & V_2 -> V_68 -> V_69 , L_5 ,
V_111 ) ;
break;
}
}
static void F_31 ( struct V_1 * V_2 ,
struct V_26 * V_118 )
{
T_1 V_111 = ( V_118 -> V_28 >> V_112 ) &
V_113 ;
if ( V_111 == V_124 )
F_22 ( V_2 , V_118 ) ;
}
static inline bool F_32 ( T_2 V_28 )
{
return ( ( V_28 >> V_125 ) & V_126 ) ==
V_127 ;
}
static inline bool F_33 ( T_2 V_28 )
{
return ( ( V_28 >> V_125 ) & V_126 ) ==
V_128 ;
}
static inline bool F_34 ( T_2 V_28 )
{
return ( ( V_28 >> V_125 ) & V_126 ) ==
V_129 ;
}
static inline bool F_35 ( T_2 V_28 )
{
return ( ( V_28 >> V_125 ) & V_126 ) ==
V_130 ;
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
struct V_14 * V_131 = & V_2 -> V_16 . V_132 ;
struct V_26 * V_27 = F_38 ( V_131 ) ;
if ( F_7 ( V_27 ) ) {
F_39 ( V_131 ) ;
return V_27 ;
}
return NULL ;
}
void F_40 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_133 ) ;
F_42 ( V_2 , V_2 -> V_16 . V_132 . V_21 , true , 0 ) ;
V_2 -> V_16 . V_134 = true ;
F_43 ( & V_2 -> V_133 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_133 ) ;
V_2 -> V_16 . V_134 = false ;
F_42 ( V_2 , V_2 -> V_16 . V_132 . V_21 , false , 0 ) ;
F_43 ( & V_2 -> V_133 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
int V_135 = 0 , V_45 = 0 ;
struct V_136 * V_16 = & V_2 -> V_16 ;
F_46 ( & V_2 -> V_133 ) ;
while ( ( V_27 = F_37 ( V_2 ) ) ) {
if ( V_27 -> V_28 & V_137 ) {
F_36 ( V_2 , V_27 ) ;
} else if ( V_27 -> V_28 & V_138 ) {
V_45 = F_15 ( V_2 , V_27 ) ;
F_47 ( & V_16 -> V_17 . V_139 ) ;
}
F_9 ( V_27 ) ;
V_135 ++ ;
}
if ( V_135 )
F_42 ( V_2 , V_16 -> V_132 . V_21 , V_16 -> V_134 , V_135 ) ;
F_48 ( & V_2 -> V_133 ) ;
return V_45 ;
}
static int F_49 ( struct V_1 * V_2 )
{
#define F_50 120000
int V_5 , V_45 = 0 ;
struct V_136 * V_16 = & V_2 -> V_16 ;
for ( V_5 = 0 ; V_5 < F_50 ; V_5 ++ ) {
if ( F_4 ( V_2 , V_19 ) )
return - V_20 ;
F_51 () ;
V_45 = F_45 ( V_2 ) ;
F_52 () ;
if ( F_53 ( & V_16 -> V_17 . V_139 ) == 0 )
break;
F_54 ( 100 ) ;
}
if ( V_5 == F_50 ) {
F_18 ( & V_2 -> V_68 -> V_69 , L_6 ) ;
F_55 ( V_2 , V_140 ) ;
return - V_20 ;
}
return V_45 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_45 ;
struct V_11 * V_12 ;
struct V_136 * V_16 = & V_2 -> V_16 ;
T_3 V_141 = V_16 -> V_17 . V_142 ;
struct V_30 * V_60 ;
F_57 ( & V_141 , V_16 -> V_17 . V_143 ) ;
V_12 = F_58 ( & V_16 -> V_17 , V_141 ) ;
V_60 = F_10 ( V_12 -> V_31 , V_12 -> V_32 ) ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_144;
V_45 = F_49 ( V_2 ) ;
if ( V_45 == - V_20 )
goto V_144;
V_45 = ( V_60 -> V_34 |
( ( V_60 -> V_35 & V_145 ) <<
V_146 ) ) ;
V_144:
return V_45 ;
}
static int F_59 ( struct V_1 * V_2 , void T_4 * V_24 )
{
int V_147 = 0 ;
T_2 V_148 ;
do {
if ( F_4 ( V_2 , V_19 ) )
return - V_20 ;
V_148 = F_60 ( V_24 ) ;
if ( V_148 == 0xffffffff )
return - 1 ;
V_148 &= V_149 ;
if ( V_148 )
break;
if ( V_147 > 4000 ) {
F_18 ( & V_2 -> V_68 -> V_69 , L_6 ) ;
F_55 ( V_2 , V_140 ) ;
F_61 ( V_2 ) ;
return - 1 ;
}
F_62 ( 1 ) ;
V_147 ++ ;
} while ( true );
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
int V_45 ;
T_2 V_18 = 0 ;
void T_4 * V_24 = V_2 -> V_24 + V_150 ;
struct V_151 * V_152 = & V_2 -> V_152 ;
struct V_153 * V_154 = V_152 -> V_155 ;
struct V_26 * V_27 = & V_154 -> V_27 ;
V_45 = F_59 ( V_2 , V_24 ) ;
if ( V_45 != 0 )
return V_45 ;
V_18 |= V_156 ;
V_18 |= ( F_64 ( V_152 -> V_157 ) >> 2 ) << 2 ;
F_6 ( V_18 , V_24 ) ;
V_45 = F_59 ( V_2 , V_24 ) ;
if ( V_45 != 0 )
return V_45 ;
V_18 = 0 ;
V_18 |= ( T_2 ) ( V_152 -> V_157 >> 4 ) << 2 ;
F_6 ( V_18 , V_24 ) ;
V_45 = F_59 ( V_2 , V_24 ) ;
if ( V_45 != 0 )
return V_45 ;
if ( F_7 ( V_27 ) ) {
V_45 = F_15 ( V_2 , & V_154 -> V_27 ) ;
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
T_2 V_158 ;
if ( F_20 ( V_2 ) )
V_158 = F_60 ( V_2 -> V_159 + V_160 ) ;
else
F_66 ( V_2 -> V_68 ,
V_161 , & V_158 ) ;
return V_158 & V_162 ;
}
static int F_67 ( struct V_1 * V_2 )
{
#define F_68 30
T_2 V_163 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_68 ; V_5 ++ ) {
V_163 = F_60 ( V_2 -> V_24 + V_164 ) ;
if ( V_163 & V_165 )
return 0 ;
if ( V_163 & V_166 &&
! ( V_163 & V_167 ) )
return - V_20 ;
F_62 ( 1000 ) ;
}
return V_163 ? : - 1 ;
}
int F_69 ( struct V_1 * V_2 )
{
T_3 V_168 ;
int V_45 , V_169 = 0 ;
struct V_81 * V_69 = & V_2 -> V_68 -> V_69 ;
if ( F_70 ( V_2 ) ) {
V_45 = F_67 ( V_2 ) ;
if ( V_45 ) {
V_168 = V_45 ;
goto V_170;
}
return 0 ;
}
do {
if ( F_20 ( V_2 ) && F_71 ( V_2 ) )
return 0 ;
V_168 = F_65 ( V_2 ) ;
if ( V_168 == V_171 )
return 0 ;
F_23 ( V_69 , L_8 , V_169 ) ;
if ( F_72 ( 2000 ) ) {
F_18 ( V_69 , L_9 ) ;
return - V_172 ;
}
V_169 += 2 ;
} while ( V_169 < 60 );
V_170:
F_18 ( V_69 , L_10 , V_168 ) ;
return - V_173 ;
}
static inline struct V_174 * F_73 ( struct V_11 * V_12 )
{
return & V_12 -> V_13 . V_175 [ 0 ] ;
}
static inline void F_74 ( struct V_11 * V_12 , unsigned long V_33 )
{
V_12 -> V_31 = V_33 & 0xFFFFFFFF ;
V_12 -> V_32 = F_64 ( V_33 ) ;
}
static void F_75 ( struct V_176 * V_177 ,
T_1 V_4 , T_1 V_3 , int V_178 ,
struct V_11 * V_12 ,
struct V_151 * V_179 )
{
struct V_174 * V_180 ;
V_177 -> V_3 = V_3 ;
V_177 -> V_4 = V_4 ;
V_177 -> V_181 = F_76 ( V_178 - sizeof( * V_177 ) ) ;
V_177 -> V_182 = 0 ;
F_74 ( V_12 , ( V_183 ) V_177 ) ;
V_12 -> V_184 = V_178 ;
if ( V_179 ) {
V_12 -> V_185 |= ( 1 & V_186 ) <<
V_187 ;
V_180 = F_73 ( V_12 ) ;
V_180 -> V_188 = F_76 ( F_64 ( V_179 -> V_157 ) ) ;
V_180 -> V_189 = F_76 ( V_179 -> V_157 & 0xFFFFFFFF ) ;
V_180 -> V_143 = F_76 ( V_179 -> V_190 ) ;
} else
V_12 -> V_185 |= V_191 ;
F_77 ( V_12 , 8 ) ;
}
static void F_78 ( struct V_192 * V_193 , T_2 V_194 ,
struct V_151 * V_179 )
{
int V_5 , V_195 = F_79 ( F_80 ( V_179 -> V_155 , V_179 -> V_190 ) , V_194 ) ;
T_5 V_157 = ( T_5 ) V_179 -> V_157 ;
for ( V_5 = 0 ; V_5 < V_195 ; V_5 ++ ) {
V_193 [ V_5 ] . V_196 = F_76 ( V_157 & 0xFFFFFFFF ) ;
V_193 [ V_5 ] . V_197 = F_76 ( F_64 ( V_157 ) ) ;
V_157 += V_198 ;
}
}
static inline struct V_11 * F_81 ( struct V_1 * V_2 )
{
struct V_151 * V_152 = & V_2 -> V_152 ;
struct V_11 * V_12
= & ( (struct V_153 * ) ( V_152 -> V_155 ) ) -> V_12 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
static struct V_11 * F_82 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 . V_17 ;
struct V_11 * V_12 ;
if ( ! V_15 -> V_199 )
return NULL ;
if ( F_53 ( & V_15 -> V_139 ) >= V_15 -> V_143 )
return NULL ;
V_12 = F_83 ( V_15 ) ;
F_84 ( V_15 ) ;
F_85 ( & V_15 -> V_139 ) ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
static bool F_86 ( struct V_1 * V_2 )
{
return V_2 -> V_16 . V_17 . V_199 ;
}
static int F_87 ( struct V_1 * V_2 )
{
if ( F_86 ( V_2 ) ) {
F_41 ( & V_2 -> V_200 ) ;
return 0 ;
} else {
return F_88 ( & V_2 -> V_201 ) ;
}
}
static void F_89 ( struct V_1 * V_2 )
{
if ( F_86 ( V_2 ) )
F_43 ( & V_2 -> V_200 ) ;
else
return F_90 ( & V_2 -> V_201 ) ;
}
static struct V_11 * F_91 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_202 ;
if ( F_86 ( V_2 ) ) {
V_202 = F_82 ( V_2 ) ;
if ( ! V_202 )
return NULL ;
} else {
V_202 = F_81 ( V_2 ) ;
}
memcpy ( V_202 , V_12 , sizeof( * V_12 ) ) ;
if ( V_12 -> V_185 & F_76 ( V_191 ) )
F_74 ( V_202 , ( V_183 ) F_2 ( V_12 ) ) ;
return V_202 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_202 ;
int V_45 ;
V_45 = F_87 ( V_2 ) ;
if ( V_45 )
return V_45 ;
V_202 = F_91 ( V_2 , V_12 ) ;
if ( ! V_202 ) {
V_45 = - V_203 ;
goto V_204;
}
if ( F_86 ( V_2 ) )
V_45 = F_56 ( V_2 ) ;
else
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 )
memcpy ( V_12 , V_202 , sizeof( * V_12 ) ) ;
V_204:
F_89 ( V_2 ) ;
return V_45 ;
}
int F_93 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_45 ;
if ( F_70 ( V_2 ) )
return 0 ;
if ( F_88 ( & V_2 -> V_201 ) )
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
F_90 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_94 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_45 ;
if ( F_70 ( V_2 ) )
return 0 ;
if ( F_88 ( & V_2 -> V_201 ) )
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
F_90 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_95 ( struct V_1 * V_2 , struct V_205 * V_206 )
{
struct V_11 * V_12 ;
struct V_207 * V_208 ;
struct V_151 * V_209 = & V_206 -> V_17 . V_210 ;
int V_45 , V_211 = 0 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_213 , sizeof( * V_208 ) , V_12 ,
NULL ) ;
if ( ! ( F_20 ( V_2 ) || F_70 ( V_2 ) ) )
V_211 = 2 ;
V_208 -> V_212 . V_182 = V_211 ;
V_208 -> V_214 = F_96 ( F_80 ( V_209 -> V_155 , V_209 -> V_190 ) ) ;
F_97 ( struct V_215 , V_90 , V_208 -> V_216 , 1 ) ;
F_97 ( struct V_215 , V_190 , V_208 -> V_216 , 0 ) ;
F_97 ( struct V_215 , V_217 , V_208 -> V_216 ,
F_98 ( V_206 -> V_17 . V_143 / 256 ) ) ;
F_77 ( V_208 -> V_216 , sizeof( V_208 -> V_216 ) ) ;
F_78 ( V_208 -> V_193 , F_99 ( V_208 -> V_193 ) , V_209 ) ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_218 * V_60 = F_2 ( V_12 ) ;
V_206 -> V_17 . V_21 = F_26 ( V_60 -> V_219 ) ;
V_206 -> V_220 =
( V_211 == 2 ) ? F_26 ( V_60 -> V_220 ) : V_206 -> V_221 ;
V_206 -> V_17 . V_199 = true ;
}
F_90 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_100 ( struct V_1 * V_2 , T_1 * V_222 ,
bool V_223 , T_2 V_224 , T_2 V_225 )
{
struct V_11 * V_12 ;
struct V_226 * V_208 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_227 , sizeof( * V_208 ) , V_12 ,
NULL ) ;
V_208 -> type = V_228 ;
if ( V_223 ) {
V_208 -> V_223 = 1 ;
} else {
V_208 -> V_229 = F_96 ( ( T_3 ) V_224 ) ;
V_208 -> V_225 = F_76 ( V_225 ) ;
V_208 -> V_223 = 0 ;
}
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_230 * V_60 = F_2 ( V_12 ) ;
memcpy ( V_222 , V_60 -> V_231 . V_33 , V_232 ) ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_101 ( struct V_1 * V_2 , T_1 * V_222 ,
T_2 V_229 , T_2 * V_225 , T_2 V_233 )
{
struct V_11 * V_12 ;
struct V_234 * V_208 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_235 , sizeof( * V_208 ) , V_12 ,
NULL ) ;
V_208 -> V_212 . V_233 = V_233 ;
V_208 -> V_229 = F_76 ( V_229 ) ;
memcpy ( V_208 -> V_236 , V_222 , V_232 ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_237 * V_60 = F_2 ( V_12 ) ;
* V_225 = F_8 ( V_60 -> V_225 ) ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
if ( V_45 == V_67 )
V_45 = - V_238 ;
return V_45 ;
}
int F_102 ( struct V_1 * V_2 , T_2 V_229 , int V_225 , T_2 V_239 )
{
struct V_11 * V_12 ;
struct V_240 * V_208 ;
int V_45 ;
if ( V_225 == - 1 )
return 0 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_241 , sizeof( * V_208 ) ,
V_12 , NULL ) ;
V_208 -> V_212 . V_233 = V_239 ;
V_208 -> V_229 = F_76 ( V_229 ) ;
V_208 -> V_225 = F_76 ( V_225 ) ;
V_45 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_103 ( struct V_1 * V_2 , struct V_14 * V_132 ,
struct V_14 * V_242 , bool V_243 , int V_244 )
{
struct V_11 * V_12 ;
struct V_245 * V_208 ;
struct V_151 * V_209 = & V_132 -> V_210 ;
void * V_246 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_208 = F_2 ( V_12 ) ;
V_246 = & V_208 -> V_216 ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_247 , sizeof( * V_208 ) , V_12 ,
NULL ) ;
V_208 -> V_214 = F_96 ( F_80 ( V_209 -> V_155 , V_209 -> V_190 ) ) ;
if ( F_20 ( V_2 ) ) {
F_97 ( struct V_248 , V_249 , V_246 ,
V_244 ) ;
F_97 ( struct V_248 , V_250 ,
V_246 , V_243 ) ;
F_97 ( struct V_248 , V_217 , V_246 ,
F_98 ( V_132 -> V_143 / 256 ) ) ;
F_97 ( struct V_248 , V_90 , V_246 , 1 ) ;
F_97 ( struct V_248 , V_251 , V_246 , 1 ) ;
F_97 ( struct V_248 , V_252 , V_246 , V_242 -> V_21 ) ;
} else {
V_208 -> V_212 . V_182 = 2 ;
V_208 -> V_253 = 1 ;
if ( ! F_70 ( V_2 ) )
F_97 ( struct V_254 , V_249 ,
V_246 , V_244 ) ;
F_97 ( struct V_254 , V_250 , V_246 ,
V_243 ) ;
F_97 ( struct V_254 , V_217 , V_246 ,
F_98 ( V_132 -> V_143 / 256 ) ) ;
F_97 ( struct V_254 , V_90 , V_246 , 1 ) ;
F_97 ( struct V_254 , V_251 , V_246 , 1 ) ;
F_97 ( struct V_254 , V_252 , V_246 , V_242 -> V_21 ) ;
}
F_77 ( V_246 , sizeof( V_208 -> V_216 ) ) ;
F_78 ( V_208 -> V_193 , F_99 ( V_208 -> V_193 ) , V_209 ) ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_255 * V_60 = F_2 ( V_12 ) ;
V_132 -> V_21 = F_26 ( V_60 -> V_256 ) ;
V_132 -> V_199 = true ;
}
F_90 ( & V_2 -> V_201 ) ;
return V_45 ;
}
static T_2 F_104 ( int V_257 )
{
T_2 V_258 = F_105 ( V_257 ) ;
if ( V_258 == 16 )
V_258 = 0 ;
return V_258 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_132 )
{
struct V_11 * V_12 ;
struct V_259 * V_208 ;
struct V_151 * V_209 = & V_15 -> V_210 ;
void * V_246 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_208 = F_2 ( V_12 ) ;
V_246 = & V_208 -> V_216 ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_260 , sizeof( * V_208 ) , V_12 ,
NULL ) ;
V_208 -> V_214 = F_96 ( F_80 ( V_209 -> V_155 , V_209 -> V_190 ) ) ;
if ( F_20 ( V_2 ) ) {
F_97 ( struct V_261 , V_90 , V_246 , 1 ) ;
F_97 ( struct V_261 , V_262 , V_246 ,
F_104 ( V_15 -> V_143 ) ) ;
F_97 ( struct V_261 , V_256 , V_246 , V_132 -> V_21 ) ;
} else {
V_208 -> V_212 . V_182 = 1 ;
V_208 -> V_256 = F_96 ( V_132 -> V_21 ) ;
F_97 ( struct V_263 , V_262 , V_246 ,
F_104 ( V_15 -> V_143 ) ) ;
F_97 ( struct V_263 , V_90 , V_246 , 1 ) ;
F_97 ( struct V_263 , V_264 ,
V_246 , V_132 -> V_21 ) ;
F_97 ( struct V_263 , V_265 ,
V_246 , 1 ) ;
}
V_208 -> V_266 [ 0 ] =
F_76 ( F_107 ( V_127 ) |
F_107 ( V_128 ) |
F_107 ( V_129 ) |
F_107 ( V_130 ) ) ;
F_77 ( V_246 , sizeof( V_208 -> V_216 ) ) ;
F_78 ( V_208 -> V_193 , F_99 ( V_208 -> V_193 ) , V_209 ) ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_267 * V_60 = F_2 ( V_12 ) ;
V_15 -> V_21 = F_26 ( V_60 -> V_21 ) ;
V_15 -> V_199 = true ;
}
F_90 ( & V_2 -> V_201 ) ;
return V_45 ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_132 )
{
struct V_11 * V_12 ;
struct V_268 * V_208 ;
struct V_151 * V_209 = & V_15 -> V_210 ;
void * V_246 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_208 = F_2 ( V_12 ) ;
V_246 = & V_208 -> V_216 ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_269 , sizeof( * V_208 ) , V_12 ,
NULL ) ;
V_208 -> V_214 = F_96 ( F_80 ( V_209 -> V_155 , V_209 -> V_190 ) ) ;
F_97 ( struct V_261 , V_90 , V_246 , 1 ) ;
F_97 ( struct V_261 , V_262 , V_246 ,
F_104 ( V_15 -> V_143 ) ) ;
F_97 ( struct V_261 , V_256 , V_246 , V_132 -> V_21 ) ;
F_77 ( V_246 , sizeof( V_208 -> V_216 ) ) ;
F_78 ( V_208 -> V_193 , F_99 ( V_208 -> V_193 ) , V_209 ) ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_267 * V_60 = F_2 ( V_12 ) ;
V_15 -> V_21 = F_26 ( V_60 -> V_21 ) ;
V_15 -> V_199 = true ;
}
F_90 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_109 ( struct V_1 * V_2 ,
struct V_14 * V_15 , struct V_14 * V_132 )
{
int V_45 ;
V_45 = F_106 ( V_2 , V_15 , V_132 ) ;
if ( V_45 && F_20 ( V_2 ) ) {
F_17 ( & V_2 -> V_68 -> V_69 , L_11
L_12
L_13 ) ;
V_45 = F_108 ( V_2 , V_15 , V_132 ) ;
}
return V_45 ;
}
int F_110 ( struct V_1 * V_2 , struct V_270 * V_271 )
{
struct V_11 V_12 = { 0 } ;
struct V_272 * V_208 ;
struct V_14 * V_273 = & V_271 -> V_17 ;
struct V_14 * V_132 = & V_271 -> V_132 ;
struct V_151 * V_209 = & V_273 -> V_210 ;
int V_45 , V_211 = 0 ;
V_208 = F_2 ( & V_12 ) ;
F_75 ( & V_208 -> V_212 , V_55 ,
V_274 , sizeof( * V_208 ) , & V_12 , NULL ) ;
if ( F_70 ( V_2 ) ) {
V_208 -> V_212 . V_182 = 1 ;
} else if ( F_20 ( V_2 ) ) {
if ( V_2 -> V_275 & V_276 )
V_208 -> V_212 . V_182 = 2 ;
} else {
V_208 -> V_212 . V_182 = 2 ;
}
if ( V_208 -> V_212 . V_182 > 0 )
V_208 -> V_229 = F_96 ( V_2 -> V_224 ) ;
V_208 -> V_214 = F_80 ( V_209 -> V_155 , V_209 -> V_190 ) ;
V_208 -> V_277 = V_278 ;
V_208 -> type = V_279 ;
V_208 -> V_256 = F_96 ( V_132 -> V_21 ) ;
V_208 -> V_280 = F_104 ( V_273 -> V_143 ) ;
F_78 ( V_208 -> V_193 , F_99 ( V_208 -> V_193 ) , V_209 ) ;
V_211 = V_208 -> V_212 . V_182 ;
V_45 = F_92 ( V_2 , & V_12 ) ;
if ( ! V_45 ) {
struct V_281 * V_60 = F_2 ( & V_12 ) ;
V_273 -> V_21 = F_26 ( V_60 -> V_282 ) ;
if ( V_211 == 2 )
V_271 -> V_283 = F_8 ( V_60 -> V_283 ) ;
else
V_271 -> V_283 = V_284 ;
V_273 -> V_199 = true ;
}
return V_45 ;
}
int F_111 ( struct V_1 * V_2 ,
struct V_14 * V_285 , T_3 V_256 , T_3 V_286 ,
T_2 V_229 , T_2 V_287 , T_1 * V_288 )
{
struct V_11 * V_12 ;
struct V_289 * V_208 ;
struct V_151 * V_209 = & V_285 -> V_210 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_55 ,
V_290 , sizeof( * V_208 ) , V_12 , NULL ) ;
V_208 -> V_256 = F_96 ( V_256 ) ;
V_208 -> V_286 = F_105 ( V_286 ) - 1 ;
V_208 -> V_214 = 2 ;
F_78 ( V_208 -> V_193 , F_99 ( V_208 -> V_193 ) , V_209 ) ;
V_208 -> V_291 = F_76 ( V_229 ) ;
V_208 -> V_292 = F_96 ( V_293 ) ;
V_208 -> V_294 = F_76 ( V_287 ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_295 * V_60 = F_2 ( V_12 ) ;
V_285 -> V_21 = F_26 ( V_60 -> V_21 ) ;
V_285 -> V_199 = true ;
* V_288 = V_60 -> V_288 ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_112 ( struct V_1 * V_2 , struct V_14 * V_17 ,
int V_296 )
{
struct V_11 * V_12 ;
struct V_297 * V_208 ;
T_1 V_298 = 0 , V_3 = 0 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_208 = F_2 ( V_12 ) ;
switch ( V_296 ) {
case V_299 :
V_298 = V_51 ;
V_3 = V_300 ;
break;
case V_301 :
V_298 = V_51 ;
V_3 = V_302 ;
break;
case V_303 :
V_298 = V_55 ;
V_3 = V_304 ;
break;
case V_305 :
V_298 = V_55 ;
V_3 = V_306 ;
break;
case V_307 :
V_298 = V_51 ;
V_3 = V_308 ;
break;
default:
F_113 () ;
}
F_75 ( & V_208 -> V_212 , V_298 , V_3 , sizeof( * V_208 ) , V_12 ,
NULL ) ;
V_208 -> V_21 = F_96 ( V_17 -> V_21 ) ;
V_45 = F_63 ( V_2 ) ;
V_17 -> V_199 = false ;
F_90 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_114 ( struct V_1 * V_2 , struct V_14 * V_17 )
{
struct V_11 * V_12 ;
struct V_297 * V_208 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_55 ,
V_306 , sizeof( * V_208 ) , V_12 , NULL ) ;
V_208 -> V_21 = F_96 ( V_17 -> V_21 ) ;
V_45 = F_56 ( V_2 ) ;
V_17 -> V_199 = false ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_115 ( struct V_1 * V_2 , T_2 V_309 , T_2 V_310 ,
T_2 * V_224 , T_2 V_233 )
{
struct V_11 V_12 = { 0 } ;
struct V_311 * V_208 ;
int V_45 ;
V_208 = F_2 ( & V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_312 ,
sizeof( * V_208 ) , & V_12 , NULL ) ;
V_208 -> V_212 . V_233 = V_233 ;
V_208 -> V_313 = F_76 ( V_309 ) ;
V_208 -> V_314 = F_76 ( V_310 ) ;
V_208 -> V_315 = true ;
V_45 = F_92 ( V_2 , & V_12 ) ;
if ( ! V_45 ) {
struct V_316 * V_60 = F_2 ( & V_12 ) ;
* V_224 = F_8 ( V_60 -> V_291 ) ;
if ( F_116 ( V_2 ) && F_71 ( V_2 ) )
V_2 -> V_225 [ 0 ] = F_8 ( V_60 -> V_225 ) ;
}
return V_45 ;
}
int F_117 ( struct V_1 * V_2 , int V_291 , T_2 V_233 )
{
struct V_11 * V_12 ;
struct V_317 * V_208 ;
int V_45 ;
if ( V_291 == - 1 )
return 0 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_318 ,
sizeof( * V_208 ) , V_12 , NULL ) ;
V_208 -> V_212 . V_233 = V_233 ;
V_208 -> V_291 = F_76 ( V_291 ) ;
V_45 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_118 ( struct V_1 * V_2 , struct V_151 * V_319 )
{
struct V_11 * V_12 ;
struct V_176 * V_212 ;
int V_45 = 0 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_212 = V_319 -> V_155 ;
F_75 ( V_212 , V_55 ,
V_53 , V_319 -> V_190 , V_12 ,
V_319 ) ;
if ( F_119 ( V_2 ) )
V_212 -> V_182 = 0 ;
if ( F_116 ( V_2 ) || F_70 ( V_2 ) )
V_212 -> V_182 = 1 ;
else
V_212 -> V_182 = 2 ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_170;
V_2 -> V_57 = true ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_120 ( struct V_1 * V_2 ,
struct V_151 * V_319 )
{
struct V_11 * V_12 ;
struct V_320 * V_208 ;
int V_45 = 0 ;
if ( ! F_1 ( V_2 , V_54 ,
V_55 ) )
return - V_238 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = V_319 -> V_155 ;
F_75 ( & V_208 -> V_212 , V_55 ,
V_54 , V_319 -> V_190 ,
V_12 , V_319 ) ;
V_208 -> V_321 . V_322 . V_323 = F_96 ( V_2 -> V_83 ) ;
V_208 -> V_321 . V_322 . V_324 = 0 ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_170;
V_2 -> V_57 = true ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
static int F_121 ( int V_325 )
{
switch ( V_325 ) {
case V_326 :
return 0 ;
case V_327 :
return 10 ;
case V_328 :
return 100 ;
case V_329 :
return 1000 ;
case V_330 :
return 10000 ;
case V_331 :
return 20000 ;
case V_332 :
return 25000 ;
case V_333 :
return 40000 ;
}
return 0 ;
}
int F_122 ( struct V_1 * V_2 , T_3 * V_73 ,
T_1 * V_334 , T_2 V_239 )
{
struct V_11 * V_12 ;
struct V_335 * V_208 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
if ( V_334 )
* V_334 = V_336 ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_337 ,
sizeof( * V_208 ) , V_12 , NULL ) ;
if ( ! F_119 ( V_2 ) )
V_208 -> V_212 . V_182 = 1 ;
V_208 -> V_212 . V_233 = V_239 ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_338 * V_60 = F_2 ( V_12 ) ;
if ( V_73 ) {
* V_73 = V_60 -> V_73 ?
F_26 ( V_60 -> V_73 ) * 10 :
F_121 ( V_60 -> V_325 ) ;
if ( ! V_60 -> V_339 )
* V_73 = 0 ;
}
if ( V_334 )
* V_334 = V_60 -> V_339 ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_123 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_340 * V_208 ;
int V_45 = 0 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_58 ,
sizeof( * V_208 ) , V_12 , NULL ) ;
V_45 = F_3 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_124 ( struct V_1 * V_2 , T_2 * V_341 )
{
struct V_11 V_12 = { 0 } ;
struct V_342 * V_208 ;
int V_45 ;
V_208 = F_2 ( & V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_343 , sizeof( * V_208 ) ,
& V_12 , NULL ) ;
V_208 -> V_344 = F_76 ( V_345 ) ;
V_45 = F_92 ( V_2 , & V_12 ) ;
if ( ! V_45 ) {
struct V_346 * V_60 = F_2 ( & V_12 ) ;
if ( V_341 && V_60 -> V_347 )
* V_341 = F_8 ( V_60 -> V_347 ) -
sizeof( T_2 ) ;
}
return V_45 ;
}
int F_125 ( struct V_1 * V_2 , T_2 V_348 , void * V_349 )
{
struct V_151 V_350 ;
struct V_11 * V_12 ;
struct V_342 * V_208 ;
T_2 V_351 = 0 , V_352 , V_353 ,
V_354 = sizeof( T_2 ) , V_355 ;
int V_45 ;
if ( V_348 == 0 )
return 0 ;
V_352 = V_348 ;
V_350 . V_190 = sizeof( struct V_342 ) + 60 * 1024 ;
V_350 . V_155 = F_126 ( & V_2 -> V_68 -> V_69 ,
V_350 . V_190 ,
& V_350 . V_157 , V_356 ) ;
if ( ! V_350 . V_155 )
return - V_357 ;
F_41 ( & V_2 -> V_200 ) ;
while ( V_352 ) {
V_353 = F_79 ( V_352 , ( T_2 ) 60 * 1024 ) ;
V_352 -= V_353 ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = V_350 . V_155 ;
V_355 = sizeof( struct V_342 ) + V_353 ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_343 , V_355 ,
V_12 , & V_350 ) ;
V_208 -> V_344 = F_76 ( V_358 ) ;
V_208 -> V_359 = F_76 ( V_354 ) ;
V_208 -> V_360 = F_76 ( V_353 ) ;
V_208 -> V_361 = F_76 ( V_353 ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_346 * V_60 = V_350 . V_155 ;
memcpy ( V_349 + V_351 ,
V_60 -> V_362 ,
F_8 ( V_60 -> V_360 ) ) ;
} else {
F_18 ( & V_2 -> V_68 -> V_69 , L_14 ) ;
goto V_170;
}
V_351 += V_353 ;
V_354 += V_353 ;
}
V_170:
F_127 ( & V_2 -> V_68 -> V_69 , V_350 . V_190 ,
V_350 . V_155 , V_350 . V_157 ) ;
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_128 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_363 * V_208 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_364 , sizeof( * V_208 ) , V_12 ,
NULL ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_365 * V_60 = F_2 ( V_12 ) ;
F_129 ( V_2 -> V_366 , V_60 -> V_367 ,
sizeof( V_2 -> V_366 ) ) ;
F_129 ( V_2 -> V_368 , V_60 -> V_369 ,
sizeof( V_2 -> V_368 ) ) ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
static int F_130 ( struct V_1 * V_2 ,
struct V_370 * V_371 , int V_135 )
{
struct V_11 * V_12 ;
struct V_372 * V_208 ;
int V_45 = 0 , V_5 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_373 , sizeof( * V_208 ) , V_12 ,
NULL ) ;
V_208 -> V_374 = F_76 ( V_135 ) ;
for ( V_5 = 0 ; V_5 < V_135 ; V_5 ++ ) {
V_208 -> V_371 [ V_5 ] . V_219 = F_76 ( V_371 [ V_5 ] . V_219 ) ;
V_208 -> V_371 [ V_5 ] . V_375 = 0 ;
V_208 -> V_371 [ V_5 ] . V_376 =
F_76 ( V_371 [ V_5 ] . V_376 ) ;
}
V_45 = F_3 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_131 ( struct V_1 * V_2 , struct V_370 * V_371 ,
int V_135 )
{
int V_377 , V_5 = 0 ;
while ( V_135 ) {
V_377 = F_79 ( V_135 , 8 ) ;
F_130 ( V_2 , & V_371 [ V_5 ] , V_377 ) ;
V_5 += V_377 ;
V_135 -= V_377 ;
}
return 0 ;
}
int F_132 ( struct V_1 * V_2 , T_2 V_229 , T_3 * V_378 ,
T_2 V_135 , T_2 V_233 )
{
struct V_11 * V_12 ;
struct V_379 * V_208 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_380 , sizeof( * V_208 ) ,
V_12 , NULL ) ;
V_208 -> V_212 . V_233 = V_233 ;
V_208 -> V_291 = V_229 ;
V_208 -> V_381 = V_382 & F_133 ( V_2 ) ? 1 : 0 ;
V_208 -> V_383 = V_135 ;
memcpy ( V_208 -> V_384 , V_378 ,
V_208 -> V_383 * sizeof( V_378 [ 0 ] ) ) ;
V_45 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
static int F_134 ( struct V_1 * V_2 , T_2 V_28 , T_2 V_385 )
{
struct V_11 * V_12 ;
struct V_151 * V_179 = & V_2 -> V_386 ;
struct V_387 * V_208 = V_179 -> V_155 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
memset ( V_208 , 0 , sizeof( * V_208 ) ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_388 , sizeof( * V_208 ) ,
V_12 , V_179 ) ;
V_208 -> V_229 = F_76 ( V_2 -> V_224 ) ;
V_208 -> V_389 = F_76 ( V_28 ) ;
V_208 -> V_390 = ( V_385 == V_391 ) ? V_208 -> V_389 : 0 ;
if ( V_28 & V_392 ) {
struct V_393 * V_394 ;
int V_5 = 0 ;
V_208 -> V_389 |=
F_76 ( V_395 &
F_133 ( V_2 ) ) ;
V_208 -> V_396 = F_76 ( F_135 ( V_2 -> V_397 ) ) ;
F_136 (ha, adapter->netdev)
memcpy ( V_208 -> V_398 [ V_5 ++ ] . V_399 , V_394 -> V_33 , V_232 ) ;
}
V_45 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_137 ( struct V_1 * V_2 , T_2 V_28 , T_2 V_385 )
{
struct V_81 * V_69 = & V_2 -> V_68 -> V_69 ;
if ( ( V_28 & F_133 ( V_2 ) ) != V_28 ) {
F_17 ( V_69 , L_15 , V_28 ) ;
F_17 ( V_69 , L_16 ,
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
struct V_403 * V_208 ;
int V_45 ;
if ( ! F_1 ( V_2 , V_404 ,
V_51 ) )
return - V_238 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_404 , sizeof( * V_208 ) ,
V_12 , NULL ) ;
V_208 -> V_212 . V_182 = 1 ;
V_208 -> V_405 = F_96 ( ( T_3 ) V_401 ) ;
V_208 -> V_406 = F_96 ( ( T_3 ) V_402 ) ;
V_45 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
if ( V_34 ( V_45 ) == V_407 )
return - V_408 ;
return V_45 ;
}
int F_139 ( struct V_1 * V_2 , T_2 * V_401 , T_2 * V_402 )
{
struct V_11 * V_12 ;
struct V_409 * V_208 ;
int V_45 ;
if ( ! F_1 ( V_2 , V_410 ,
V_51 ) )
return - V_238 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_410 , sizeof( * V_208 ) ,
V_12 , NULL ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_411 * V_60 =
F_2 ( V_12 ) ;
* V_401 = F_26 ( V_60 -> V_405 ) ;
* V_402 = F_26 ( V_60 -> V_406 ) ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_140 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_412 * V_208 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_413 ,
sizeof( * V_208 ) , V_12 , NULL ) ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_414 * V_60 = F_2 ( V_12 ) ;
V_2 -> V_98 = F_8 ( V_60 -> V_415 ) ;
V_2 -> V_416 = F_8 ( V_60 -> V_416 ) ;
V_2 -> V_275 = F_8 ( V_60 -> V_275 ) ;
V_2 -> V_417 = F_8 ( V_60 -> V_418 ) & 0xFF ;
F_23 ( & V_2 -> V_68 -> V_69 ,
L_17 ,
V_2 -> V_416 , V_2 -> V_275 ) ;
}
F_90 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_141 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_176 * V_208 ;
int V_45 ;
if ( F_70 ( V_2 ) ) {
F_6 ( V_419 ,
V_2 -> V_24 + V_420 ) ;
V_45 = F_67 ( V_2 ) ;
if ( V_45 )
F_18 ( & V_2 -> V_68 -> V_69 ,
L_18 ) ;
return V_45 ;
}
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_208 = F_2 ( V_12 ) ;
F_75 ( V_208 , V_51 ,
V_421 , sizeof( * V_208 ) , V_12 ,
NULL ) ;
V_45 = F_63 ( V_2 ) ;
F_90 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_142 ( struct V_1 * V_2 , T_1 * V_422 ,
T_2 V_423 , T_3 V_424 , const T_1 * V_425 )
{
struct V_11 * V_12 ;
struct V_426 * V_208 ;
int V_45 ;
if ( ! ( F_133 ( V_2 ) & V_427 ) )
return 0 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_55 ,
V_428 , sizeof( * V_208 ) , V_12 , NULL ) ;
V_208 -> V_229 = F_76 ( V_2 -> V_224 ) ;
V_208 -> V_429 = F_96 ( V_423 ) ;
V_208 -> V_430 = F_96 ( F_105 ( V_424 ) - 1 ) ;
if ( ! F_20 ( V_2 ) )
V_208 -> V_212 . V_182 = 1 ;
memcpy ( V_208 -> V_431 , V_422 , V_424 ) ;
memcpy ( V_208 -> V_432 , V_425 , V_433 ) ;
F_77 ( V_208 -> V_432 , sizeof( V_208 -> V_432 ) ) ;
V_45 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_143 ( struct V_1 * V_2 , T_1 V_98 ,
T_1 V_434 , T_1 V_435 , T_1 V_436 )
{
struct V_11 * V_12 ;
struct V_437 * V_208 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_438 ,
sizeof( * V_208 ) , V_12 , NULL ) ;
V_208 -> V_98 = V_98 ;
V_208 -> V_439 = V_436 ;
V_208 -> V_440 = V_434 ;
V_208 -> V_441 = V_435 ;
V_45 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_144 ( struct V_1 * V_2 , T_1 V_98 , T_2 * V_436 )
{
struct V_11 * V_12 ;
struct V_442 * V_208 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_443 , sizeof( * V_208 ) ,
V_12 , NULL ) ;
V_208 -> V_98 = V_98 ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_444 * V_60 =
F_2 ( V_12 ) ;
* V_436 = V_60 -> V_439 ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_145 ( struct V_1 * V_2 ,
T_1 V_445 , T_1 * V_446 )
{
struct V_151 V_447 ;
struct V_11 * V_12 ;
struct V_448 * V_208 ;
int V_45 ;
if ( V_445 > V_449 )
return - V_450 ;
V_447 . V_190 = sizeof( struct V_451 ) ;
V_447 . V_155 = F_126 ( & V_2 -> V_68 -> V_69 , V_447 . V_190 , & V_447 . V_157 ,
V_356 ) ;
if ( ! V_447 . V_155 ) {
F_18 ( & V_2 -> V_68 -> V_69 , L_19 ) ;
return - V_357 ;
}
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = V_447 . V_155 ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_452 ,
V_447 . V_190 , V_12 , & V_447 ) ;
V_208 -> V_453 = F_76 ( V_2 -> V_83 ) ;
V_208 -> V_445 = F_76 ( V_445 ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_451 * V_60 = V_447 . V_155 ;
memcpy ( V_446 , V_60 -> V_454 , V_455 ) ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
F_127 ( & V_2 -> V_68 -> V_69 , V_447 . V_190 , V_447 . V_155 , V_447 . V_157 ) ;
return V_45 ;
}
static int F_146 ( struct V_1 * V_2 ,
struct V_151 * V_447 , T_2 V_456 ,
T_2 V_457 , const char * V_458 ,
T_2 * V_459 , T_1 * V_460 ,
T_1 * V_461 )
{
struct V_11 * V_12 ;
struct V_462 * V_208 ;
struct V_463 * V_60 ;
void * V_246 = NULL ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_2 -> V_52 = 0 ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_464;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_50 ,
sizeof( struct V_462 ) , V_12 ,
NULL ) ;
V_246 = & V_208 -> V_216 ;
F_97 ( struct V_465 ,
V_466 , V_246 , V_456 ) ;
if ( V_456 == 0 )
F_97 ( struct V_465 ,
V_467 , V_246 , 1 ) ;
else
F_97 ( struct V_465 ,
V_467 , V_246 , 0 ) ;
F_77 ( V_246 , sizeof( V_208 -> V_216 ) ) ;
V_208 -> V_468 = F_76 ( V_457 ) ;
F_129 ( V_208 -> V_469 , V_458 , sizeof( V_208 -> V_469 ) ) ;
V_208 -> V_470 = F_76 ( 1 ) ;
V_208 -> V_348 = F_76 ( V_456 ) ;
V_208 -> V_471 = F_76 ( ( V_447 -> V_157 +
sizeof( struct V_462 ) )
& 0xFFFFFFFF ) ;
V_208 -> V_472 = F_76 ( F_64 ( V_447 -> V_157 +
sizeof( struct V_462 ) ) ) ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_464;
F_43 ( & V_2 -> V_200 ) ;
if ( ! F_147 ( & V_2 -> V_48 ,
F_148 ( 60000 ) ) )
V_45 = - V_173 ;
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
F_43 ( & V_2 -> V_200 ) ;
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
static int F_151 ( struct V_1 * V_2 ,
const char * V_458 )
{
struct V_487 * V_208 ;
struct V_11 * V_12 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_488 ,
sizeof( * V_208 ) , V_12 , NULL ) ;
F_129 ( V_208 -> V_469 , V_458 , sizeof( V_208 -> V_469 ) ) ;
V_45 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_152 ( struct V_1 * V_2 , struct V_151 * V_447 ,
T_2 V_456 , T_2 V_457 , const char * V_458 ,
T_2 * V_489 , T_2 * V_467 , T_1 * V_461 )
{
struct V_11 * V_12 ;
struct V_490 * V_208 ;
struct V_491 * V_60 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_464;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_492 ,
sizeof( struct V_490 ) , V_12 ,
NULL ) ;
V_208 -> V_493 = F_76 ( V_456 ) ;
V_208 -> V_494 = F_76 ( V_457 ) ;
strcpy ( V_208 -> V_469 , V_458 ) ;
V_208 -> V_470 = F_76 ( 1 ) ;
V_208 -> V_348 = F_76 ( V_456 ) ;
V_208 -> V_471 = F_76 ( ( V_447 -> V_157 & 0xFFFFFFFF ) ) ;
V_208 -> V_472 = F_76 ( F_64 ( V_447 -> V_157 ) ) ;
V_45 = F_56 ( V_2 ) ;
V_60 = F_2 ( V_12 ) ;
if ( ! V_45 ) {
* V_489 = F_8 ( V_60 -> V_495 ) ;
* V_467 = F_8 ( V_60 -> V_467 ) ;
} else {
* V_461 = V_60 -> V_474 ;
}
V_464:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
static int F_153 ( struct V_1 * V_2 ,
struct V_151 * V_447 , T_2 V_496 ,
T_2 V_497 , T_2 V_498 , T_2 V_353 )
{
struct V_11 * V_12 ;
struct F_153 * V_208 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_2 -> V_52 = 0 ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_464;
}
V_208 = V_447 -> V_155 ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_40 , V_447 -> V_190 , V_12 ,
V_447 ) ;
V_208 -> V_322 . V_499 = F_76 ( V_496 ) ;
if ( V_496 == V_500 )
V_208 -> V_322 . V_351 = F_76 ( V_498 ) ;
V_208 -> V_322 . V_501 = F_76 ( V_497 ) ;
V_208 -> V_322 . V_502 = F_76 ( V_353 ) ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_464;
F_43 ( & V_2 -> V_200 ) ;
if ( ! F_147 ( & V_2 -> V_48 ,
F_148 ( 40000 ) ) )
V_45 = - V_173 ;
else
V_45 = V_2 -> V_52 ;
return V_45 ;
V_464:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
static int F_154 ( struct V_1 * V_2 , T_1 * V_503 ,
T_3 V_504 , T_2 V_498 , T_2 V_505 )
{
struct V_506 * V_208 ;
struct V_11 * V_12 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_507 , sizeof( * V_208 ) ,
V_12 , NULL ) ;
V_208 -> V_322 . V_499 = F_76 ( V_504 ) ;
if ( V_504 == V_500 )
V_208 -> V_322 . V_351 = F_76 ( V_498 + V_505 ) ;
else
V_208 -> V_322 . V_351 = F_76 ( V_505 ) ;
V_208 -> V_322 . V_501 = F_76 ( V_508 ) ;
V_208 -> V_322 . V_502 = F_76 ( 0x4 ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 )
memcpy ( V_503 , V_208 -> V_509 , 4 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
static bool F_155 ( struct V_1 * V_2 )
{
return ( V_2 -> V_72 . V_510 == V_511 &&
V_2 -> V_72 . V_476 == V_512 ) ;
}
static bool F_156 ( struct V_1 * V_2 ,
struct V_513 * V_514 , int type )
{
int V_5 = 0 , V_515 = 0 ;
struct V_516 * V_517 = NULL ;
if ( F_119 ( V_2 ) )
V_517 = (struct V_516 * ) V_514 ;
for ( V_5 = 0 ; V_5 < V_518 ; V_5 ++ ) {
if ( V_517 )
V_515 = F_8 ( V_517 -> V_519 [ V_5 ] . type ) ;
else
V_515 = F_8 ( V_514 -> V_519 [ V_5 ] . type ) ;
if ( V_515 == type )
return true ;
}
return false ;
}
static struct V_513 * F_157 ( struct V_1 * V_2 ,
int V_520 ,
const struct V_521 * V_522 )
{
struct V_513 * V_514 = NULL ;
const T_1 * V_523 = V_522 -> V_446 ;
V_523 += V_520 ;
while ( V_523 < ( V_522 -> V_446 + V_522 -> V_190 ) ) {
V_514 = (struct V_513 * ) V_523 ;
if ( ! memcmp ( V_524 , V_514 -> V_525 , sizeof( V_524 ) ) )
return V_514 ;
V_523 += 32 ;
}
return NULL ;
}
static int F_158 ( struct V_1 * V_2 , const T_1 * V_523 ,
T_2 V_498 , T_2 V_526 , int V_527 ,
T_3 V_504 , bool * V_528 )
{
T_2 V_505 ;
int V_45 ;
T_1 V_509 [ 4 ] ;
V_45 = F_154 ( V_2 , V_509 , V_504 , V_498 ,
V_526 - 4 ) ;
if ( V_45 )
return V_45 ;
V_505 = V_527 + V_498 + V_526 - 4 ;
if ( ! memcmp ( V_509 , V_523 + V_505 , 4 ) )
* V_528 = true ;
else
* V_528 = false ;
return V_45 ;
}
static int F_159 ( struct V_1 * V_2 , const T_1 * V_529 ,
struct V_151 * V_530 , int V_531 , int V_526 ,
T_2 V_498 )
{
T_2 V_532 , V_533 , V_534 = V_526 , V_535 = 0 ;
struct F_153 * V_208 = V_530 -> V_155 ;
int V_45 ;
while ( V_534 ) {
V_533 = F_160 ( T_2 , 32 * 1024 , V_534 ) ;
V_534 -= V_533 ;
if ( ! V_534 ) {
if ( V_531 == V_536 )
V_532 = V_537 ;
else
V_532 = V_538 ;
} else {
if ( V_531 == V_536 )
V_532 = V_539 ;
else
V_532 = V_540 ;
}
memcpy ( V_208 -> V_541 , V_529 , V_533 ) ;
V_529 += V_533 ;
V_45 = F_153 ( V_2 , V_530 , V_531 ,
V_532 , V_498 +
V_535 , V_533 ) ;
if ( V_34 ( V_45 ) == V_37 &&
V_531 == V_536 )
break;
else if ( V_45 )
return V_45 ;
V_535 += V_533 ;
}
return 0 ;
}
static int F_161 ( struct V_1 * V_2 ,
const struct V_521 * V_522 ,
struct V_151 * V_530 , int V_542 )
{
int V_543 = ( V_542 * sizeof( struct V_544 ) ) ;
struct V_81 * V_69 = & V_2 -> V_68 -> V_69 ;
struct V_513 * V_514 = NULL ;
int V_45 , V_5 , V_545 , V_546 ;
const struct V_547 * V_548 ;
bool V_528 ;
const T_1 * V_523 ;
struct V_547 V_549 [] = {
{ V_550 , V_551 ,
V_552 , V_553 } ,
{ V_554 , V_555 ,
V_556 , V_557 } ,
{ V_558 , V_559 ,
V_560 , V_561 } ,
{ V_562 , V_563 ,
V_560 , V_564 } ,
{ V_565 , V_566 ,
V_560 , V_567 } ,
{ V_568 , V_569 ,
V_552 , V_570 } ,
{ V_571 , V_572 ,
V_552 , V_573 } ,
{ V_574 , V_575 ,
V_552 , V_576 } ,
{ V_577 , V_578 ,
V_579 , V_580 } ,
{ V_581 , V_536 ,
V_582 , V_583 }
} ;
struct V_547 V_584 [] = {
{ V_585 , V_551 ,
V_586 , V_553 } ,
{ V_587 , V_555 ,
V_588 , V_557 } ,
{ V_589 , V_559 ,
V_590 , V_561 } ,
{ V_591 , V_563 ,
V_590 , V_564 } ,
{ V_592 , V_566 ,
V_590 , V_567 } ,
{ V_593 , V_569 ,
V_586 , V_570 } ,
{ V_594 , V_572 ,
V_586 , V_573 } ,
{ V_595 , V_575 ,
V_586 , V_576 }
} ;
if ( F_116 ( V_2 ) ) {
V_548 = V_549 ;
V_545 = sizeof( struct V_596 ) ;
V_546 = F_99 ( V_549 ) ;
} else {
V_548 = V_584 ;
V_545 = sizeof( struct V_597 ) ;
V_546 = F_99 ( V_584 ) ;
V_543 = 0 ;
}
V_514 = F_157 ( V_2 , V_545 + V_543 , V_522 ) ;
if ( ! V_514 ) {
F_18 ( V_69 , L_20 ) ;
return - 1 ;
}
for ( V_5 = 0 ; V_5 < V_546 ; V_5 ++ ) {
if ( ! F_156 ( V_2 , V_514 , V_548 [ V_5 ] . V_515 ) )
continue;
if ( ( V_548 [ V_5 ] . V_531 == V_578 ) &&
memcmp ( V_2 -> V_366 , L_21 , 11 ) < 0 )
continue;
if ( V_548 [ V_5 ] . V_531 == V_536 &&
! F_155 ( V_2 ) )
continue;
if ( V_548 [ V_5 ] . V_531 == V_555 ) {
V_45 = F_158 ( V_2 , V_522 -> V_446 ,
V_548 [ V_5 ] . V_351 ,
V_548 [ V_5 ] . V_190 ,
V_545 +
V_543 ,
V_555 , & V_528 ) ;
if ( V_45 ) {
F_18 ( V_69 ,
L_22 ,
V_548 [ V_5 ] . V_531 ) ;
continue;
}
if ( V_528 )
continue;
}
V_523 = V_522 -> V_446 + V_545 + V_548 [ V_5 ] . V_351 +
V_543 ;
if ( V_523 + V_548 [ V_5 ] . V_190 > V_522 -> V_446 + V_522 -> V_190 )
return - 1 ;
V_45 = F_159 ( V_2 , V_523 , V_530 , V_548 [ V_5 ] . V_531 ,
V_548 [ V_5 ] . V_190 , 0 ) ;
if ( V_45 ) {
F_18 ( V_69 , L_23 ,
V_548 [ V_5 ] . V_515 ) ;
return V_45 ;
}
}
return 0 ;
}
static T_3 F_162 ( struct V_598 V_519 )
{
T_2 V_515 = F_8 ( V_519 . type ) ;
T_3 V_504 = F_26 ( V_519 . V_531 ) ;
if ( V_504 != 0xFFFF )
return V_504 ;
switch ( V_515 ) {
case V_553 :
V_504 = V_551 ;
break;
case V_557 :
V_504 = V_555 ;
break;
case V_561 :
V_504 = V_559 ;
break;
case V_564 :
V_504 = V_563 ;
break;
case V_567 :
V_504 = V_566 ;
break;
case V_570 :
V_504 = V_569 ;
break;
case V_580 :
V_504 = V_578 ;
break;
case V_599 :
V_504 = V_600 ;
break;
case V_583 :
V_504 = V_601 ;
break;
case V_602 :
V_504 = V_603 ;
break;
case V_604 :
V_504 = V_605 ;
break;
case V_606 :
V_504 = V_607 ;
break;
default:
break;
}
return V_504 ;
}
static int F_163 ( struct V_1 * V_2 ,
const struct V_521 * V_522 ,
struct V_151 * V_530 , int V_542 )
{
int V_543 = V_542 * sizeof( struct V_544 ) ;
bool V_528 , V_608 , V_609 = true ;
struct V_81 * V_69 = & V_2 -> V_68 -> V_69 ;
struct V_513 * V_514 = NULL ;
T_2 V_498 , V_526 , V_515 ;
T_3 V_504 , V_610 ;
int V_45 , V_5 , V_545 ;
const T_1 * V_523 ;
V_545 = sizeof( struct V_596 ) ;
V_514 = F_157 ( V_2 , V_545 + V_543 , V_522 ) ;
if ( ! V_514 ) {
F_18 ( V_69 , L_20 ) ;
return - V_450 ;
}
V_611:
for ( V_5 = 0 ; V_5 < F_8 ( V_514 -> V_612 . V_613 ) ; V_5 ++ ) {
V_498 = F_8 ( V_514 -> V_519 [ V_5 ] . V_351 ) ;
V_526 = F_8 ( V_514 -> V_519 [ V_5 ] . V_614 ) ;
V_515 = F_8 ( V_514 -> V_519 [ V_5 ] . type ) ;
V_504 = F_162 ( V_514 -> V_519 [ V_5 ] ) ;
V_608 = V_514 -> V_519 [ V_5 ] . V_531 == 0xFFFF ;
if ( V_504 == 0xFFFF )
continue;
if ( V_609 )
V_610 = V_500 ;
else
V_610 = V_504 ;
if ( V_608 )
goto V_615;
V_45 = F_158 ( V_2 , V_522 -> V_446 , V_498 ,
V_526 , V_545 +
V_543 , V_610 ,
& V_528 ) ;
if ( V_34 ( V_45 ) == V_37 ||
V_34 ( V_45 ) == V_41 ) {
if ( V_610 == V_500 ) {
V_609 = false ;
goto V_611;
}
F_18 ( V_69 , L_24 ) ;
F_18 ( V_69 , L_25 ) ;
return - V_616 ;
} else if ( V_45 ) {
F_18 ( V_69 , L_22 ,
V_504 ) ;
return - V_617 ;
}
if ( V_528 )
continue;
V_615:
V_523 = V_522 -> V_446 + V_545 + V_498 + V_543 ;
if ( V_523 + V_526 > V_522 -> V_446 + V_522 -> V_190 )
return - 1 ;
V_45 = F_159 ( V_2 , V_523 , V_530 , V_610 , V_526 ,
V_498 ) ;
if ( V_34 ( V_45 ) == V_41 &&
V_610 == V_500 ) {
V_609 = false ;
goto V_611;
}
if ( V_608 &&
( V_34 ( V_45 ) == V_41 ||
( V_504 == V_607 &&
V_34 ( V_45 ) == V_618 ) ) ) {
continue;
} else if ( V_45 ) {
F_18 ( V_69 , L_23 ,
V_515 ) ;
switch ( V_35 ( V_45 ) ) {
case V_619 :
F_18 ( V_69 ,
L_26 ) ;
return - V_450 ;
case V_620 :
F_18 ( V_69 ,
L_27 ) ;
return - V_450 ;
default:
return - V_617 ;
}
}
}
return 0 ;
}
int F_164 ( struct V_1 * V_2 ,
const struct V_521 * V_522 )
{
struct V_81 * V_69 = & V_2 -> V_68 -> V_69 ;
struct V_151 V_530 ;
const T_1 * V_621 = NULL ;
T_1 * V_622 = NULL ;
T_6 V_623 = 0 ;
T_2 V_624 = 0 ;
T_2 V_459 = 0 ;
T_2 V_351 = 0 ;
int V_45 = 0 ;
T_1 V_625 = 0 ;
T_1 V_460 ;
if ( ! F_165 ( V_522 -> V_190 , sizeof( T_2 ) ) ) {
F_18 ( V_69 , L_28 ) ;
return - V_450 ;
}
V_530 . V_190 = sizeof( struct V_462 )
+ V_626 ;
V_530 . V_155 = F_126 ( V_69 , V_530 . V_190 ,
& V_530 . V_157 , V_627 ) ;
if ( ! V_530 . V_155 )
return - V_357 ;
V_622 = V_530 . V_155 +
sizeof( struct V_462 ) ;
V_623 = V_522 -> V_190 ;
V_621 = V_522 -> V_446 ;
while ( V_623 ) {
V_624 = F_160 ( T_2 , V_623 , V_626 ) ;
memcpy ( V_622 , V_621 , V_624 ) ;
V_45 = F_146 ( V_2 , & V_530 ,
V_624 , V_351 ,
V_628 ,
& V_459 , & V_460 ,
& V_625 ) ;
if ( V_45 )
break;
V_351 += V_459 ;
V_621 += V_459 ;
V_623 -= V_459 ;
}
if ( ! V_45 ) {
V_45 = F_146 ( V_2 , & V_530 ,
0 , V_351 ,
V_628 ,
& V_459 , & V_460 ,
& V_625 ) ;
}
F_127 ( V_69 , V_530 . V_190 , V_530 . V_155 , V_530 . V_157 ) ;
if ( V_45 ) {
F_18 ( V_69 , L_29 ) ;
return F_166 ( V_45 ) ;
}
F_23 ( V_69 , L_30 ) ;
if ( V_460 == V_629 ) {
F_23 ( V_69 , L_31 ) ;
V_45 = F_167 ( V_2 ,
V_630 ) ;
if ( V_45 ) {
F_18 ( V_69 , L_32 ) ;
F_18 ( V_69 , L_33 ) ;
}
} else if ( V_460 != V_631 ) {
F_23 ( V_69 , L_33 ) ;
}
return 0 ;
}
static bool F_168 ( struct V_1 * V_2 ,
struct V_596 * V_632 )
{
if ( ! V_632 ) {
F_18 ( & V_2 -> V_68 -> V_69 , L_34 ) ;
return false ;
}
switch ( V_632 -> V_633 [ 0 ] ) {
case V_634 :
if ( ! F_169 ( V_2 ) )
return false ;
break;
case V_635 :
if ( ! F_116 ( V_2 ) )
return false ;
break;
case V_636 :
if ( ! F_119 ( V_2 ) )
return false ;
break;
default:
return false ;
}
if ( F_20 ( V_2 ) && V_632 -> V_637 == 0 )
return V_2 -> V_417 < 0x10 ;
else
return ( V_632 -> V_637 >= V_2 -> V_417 ) ;
}
int F_170 ( struct V_1 * V_2 , const struct V_521 * V_522 )
{
struct V_81 * V_69 = & V_2 -> V_68 -> V_69 ;
struct V_596 * V_638 ;
struct V_544 * V_639 ;
int V_45 = 0 , V_5 , V_640 ;
struct V_151 V_530 ;
V_638 = (struct V_596 * ) V_522 -> V_446 ;
if ( ! F_168 ( V_2 , V_638 ) ) {
F_18 ( V_69 , L_35 ) ;
return - V_450 ;
}
V_530 . V_190 = sizeof( struct F_153 ) ;
V_530 . V_155 = F_126 ( V_69 , V_530 . V_190 , & V_530 . V_157 ,
V_627 ) ;
if ( ! V_530 . V_155 )
return - V_357 ;
V_640 = F_8 ( V_638 -> V_640 ) ;
for ( V_5 = 0 ; V_5 < V_640 ; V_5 ++ ) {
V_639 = (struct V_544 * ) ( V_522 -> V_446 +
( sizeof( struct V_596 ) +
V_5 * sizeof( struct V_544 ) ) ) ;
if ( ! F_119 ( V_2 ) &&
F_8 ( V_639 -> V_641 ) != 1 )
continue;
if ( F_169 ( V_2 ) )
V_45 = F_163 ( V_2 , V_522 , & V_530 ,
V_640 ) ;
else
V_45 = F_161 ( V_2 , V_522 , & V_530 ,
V_640 ) ;
}
F_127 ( V_69 , V_530 . V_190 , V_530 . V_155 , V_530 . V_157 ) ;
if ( ! V_45 )
F_23 ( V_69 , L_30 ) ;
return V_45 ;
}
int F_171 ( struct V_1 * V_2 , T_1 * V_231 ,
struct V_151 * V_319 )
{
struct V_11 * V_12 ;
struct V_642 * V_208 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = V_319 -> V_155 ;
F_75 ( & V_208 -> V_212 , V_55 ,
V_643 , sizeof( * V_208 ) ,
V_12 , V_319 ) ;
memcpy ( V_208 -> V_644 , V_231 , V_232 ) ;
V_45 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_172 ( struct V_1 * V_2 , T_1 V_98 ,
T_1 V_645 , T_1 V_646 )
{
struct V_11 * V_12 ;
struct V_647 * V_208 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_464;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_47 ,
V_49 , sizeof( * V_208 ) ,
V_12 , NULL ) ;
V_208 -> V_648 = V_98 ;
V_208 -> V_649 = V_98 ;
V_208 -> V_645 = V_645 ;
V_208 -> V_650 = V_646 ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_464;
F_43 ( & V_2 -> V_200 ) ;
if ( ! F_147 ( & V_2 -> V_48 ,
F_148 ( V_651 ) ) )
V_45 = - V_173 ;
return V_45 ;
V_464:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_173 ( struct V_1 * V_2 , T_2 V_98 ,
T_2 V_645 , T_2 V_652 , T_2 V_653 ,
T_5 V_654 )
{
struct V_11 * V_12 ;
struct V_655 * V_208 ;
struct V_656 * V_60 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_47 ,
V_46 , sizeof( * V_208 ) , V_12 ,
NULL ) ;
V_208 -> V_212 . V_169 = F_76 ( 15 ) ;
V_208 -> V_654 = F_174 ( V_654 ) ;
V_208 -> V_648 = F_76 ( V_98 ) ;
V_208 -> V_649 = F_76 ( V_98 ) ;
V_208 -> V_652 = F_76 ( V_652 ) ;
V_208 -> V_653 = F_76 ( V_653 ) ;
V_208 -> V_645 = F_76 ( V_645 ) ;
V_45 = F_3 ( V_2 ) ;
if ( V_45 )
goto V_170;
F_43 ( & V_2 -> V_200 ) ;
F_175 ( & V_2 -> V_48 ) ;
V_60 = F_2 ( V_12 ) ;
V_45 = F_8 ( V_60 -> V_45 ) ;
return V_45 ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_176 ( struct V_1 * V_2 , T_5 V_654 ,
T_2 V_657 , struct V_151 * V_447 )
{
struct V_11 * V_12 ;
struct V_658 * V_208 ;
int V_45 ;
int V_5 , V_659 = 0 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = V_447 -> V_155 ;
F_75 ( & V_208 -> V_212 , V_47 ,
V_660 , V_447 -> V_190 , V_12 ,
V_447 ) ;
V_208 -> V_654 = F_174 ( V_654 ) ;
V_208 -> V_661 = F_76 ( V_657 ) ;
for ( V_5 = 0 ; V_5 < V_657 ; V_5 ++ ) {
V_208 -> V_662 [ V_5 ] = ( T_1 ) ( V_654 >> ( V_659 * 8 ) ) ;
V_659 ++ ;
if ( V_659 > 7 )
V_659 = 0 ;
}
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_663 * V_60 ;
V_60 = V_447 -> V_155 ;
if ( ( memcmp ( V_60 -> V_664 , V_208 -> V_662 , V_657 ) != 0 ) ||
V_60 -> V_665 ) {
V_45 = - 1 ;
}
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_177 ( struct V_1 * V_2 ,
struct V_151 * V_319 )
{
struct V_11 * V_12 ;
struct V_666 * V_208 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = V_319 -> V_155 ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_667 , sizeof( * V_208 ) , V_12 ,
V_319 ) ;
V_45 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_178 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_668 * V_208 ;
struct V_151 V_447 ;
int V_45 ;
if ( ! F_1 ( V_2 , V_669 ,
V_51 ) )
return - V_238 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_447 . V_190 = sizeof( struct V_668 ) ;
V_447 . V_155 = F_126 ( & V_2 -> V_68 -> V_69 , V_447 . V_190 , & V_447 . V_157 ,
V_356 ) ;
if ( ! V_447 . V_155 ) {
F_18 ( & V_2 -> V_68 -> V_69 , L_36 ) ;
V_45 = - V_357 ;
goto V_170;
}
V_208 = V_447 . V_155 ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_669 , sizeof( * V_208 ) ,
V_12 , & V_447 ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_670 * V_671 =
V_447 . V_155 + sizeof( struct V_176 ) ;
V_2 -> V_72 . V_510 = F_26 ( V_671 -> V_510 ) ;
V_2 -> V_72 . V_476 =
F_26 ( V_671 -> V_476 ) ;
V_2 -> V_72 . V_672 =
F_26 ( V_671 -> V_672 ) ;
V_2 -> V_72 . V_673 =
F_26 ( V_671 -> V_673 ) ;
V_2 -> V_72 . V_674 =
F_8 ( V_671 -> V_674 ) ;
if ( F_119 ( V_2 ) ) {
V_2 -> V_72 . V_673 =
V_675 |
V_676 ;
}
}
F_127 ( & V_2 -> V_68 -> V_69 , V_447 . V_190 , V_447 . V_155 , V_447 . V_157 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
static int F_179 ( struct V_1 * V_2 , T_2 V_677 , T_2 V_233 )
{
struct V_11 * V_12 ;
struct V_678 * V_208 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_679 , sizeof( * V_208 ) , V_12 , NULL ) ;
V_208 -> V_212 . V_233 = V_233 ;
V_208 -> V_680 = F_76 ( V_681 ) ;
V_208 -> V_682 = F_76 ( V_677 ) ;
V_45 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_180 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_683 * V_208 ;
struct V_684 * V_60 ;
int V_45 , V_5 ;
int V_355 = F_181 ( sizeof( * V_208 ) , sizeof( * V_60 ) ) ;
struct V_685 * V_686 ;
struct V_151 V_687 ;
T_2 * V_688 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
memset ( & V_687 , 0 , sizeof( struct V_151 ) ) ;
V_687 . V_190 = sizeof( struct V_684 ) ;
V_687 . V_155 = F_126 ( & V_2 -> V_68 -> V_69 ,
V_687 . V_190 ,
& V_687 . V_157 , V_356 ) ;
if ( ! V_687 . V_155 ) {
F_18 ( & V_2 -> V_68 -> V_69 , L_37 ) ;
V_45 = - V_357 ;
goto V_170;
}
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = V_687 . V_155 ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_689 , V_355 ,
V_12 , & V_687 ) ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
V_686 = V_687 . V_155 + sizeof( struct V_30 ) ;
V_2 -> V_83 = V_686 -> V_690 . V_691 ;
V_688 = V_686 -> V_690 . V_692 ;
for ( V_5 = 0 ; V_5 < V_693 ; V_5 ++ )
V_2 -> V_688 [ V_5 ] = F_8 ( V_688 [ V_5 ] ) &
( F_182 ( 16 ) - 1 ) ;
}
V_170:
F_90 ( & V_2 -> V_201 ) ;
if ( V_687 . V_155 )
F_127 ( & V_2 -> V_68 -> V_69 , V_687 . V_190 ,
V_687 . V_155 , V_687 . V_157 ) ;
return V_45 ;
}
int F_183 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_694 * V_208 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_695 ,
sizeof( * V_208 ) , V_12 , NULL ) ;
V_208 -> V_696 = F_76 ( V_697 |
V_698 ) ;
V_208 -> V_309 = F_76 ( V_698 ) ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_699 * V_60 = F_2 ( V_12 ) ;
V_2 -> V_700 = F_8 ( V_60 -> V_309 ) &
V_698 ;
if ( ! V_2 -> V_700 )
F_17 ( & V_2 -> V_68 -> V_69 ,
L_38 ) ;
}
V_170:
F_90 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_184 ( struct V_1 * V_2 , T_2 * V_701 ,
T_2 V_233 )
{
struct V_11 * V_12 ;
struct V_702 * V_208 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_703 , sizeof( * V_208 ) ,
V_12 , NULL ) ;
V_208 -> V_212 . V_233 = V_233 ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_704 * V_60 =
F_2 ( V_12 ) ;
* V_701 = F_8 ( V_60 -> V_705 ) ;
if ( F_20 ( V_2 ) && F_185 ( V_2 ) &&
F_186 ( V_2 ) )
* V_701 = V_706 ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_187 ( struct V_1 * V_2 , T_2 V_707 ,
T_2 V_233 )
{
struct V_11 * V_12 ;
struct V_708 * V_208 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_709 , sizeof( * V_208 ) ,
V_12 , NULL ) ;
V_208 -> V_212 . V_233 = V_233 ;
if ( F_70 ( V_2 ) )
V_208 -> V_710 = F_76 ( V_707 ) ;
else
V_208 -> V_707 = F_76 ( V_707 ) ;
V_45 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_188 ( struct V_1 * V_2 , T_1 * V_231 ,
bool * V_711 , T_2 * V_225 , T_2 V_224 ,
T_1 V_233 )
{
struct V_11 * V_12 ;
struct V_712 * V_208 ;
int V_45 ;
int V_713 ;
struct V_151 V_714 ;
int V_5 ;
memset ( & V_714 , 0 , sizeof( struct V_151 ) ) ;
V_714 . V_190 = sizeof( struct V_715 ) ;
V_714 . V_155 = F_126 ( & V_2 -> V_68 -> V_69 ,
V_714 . V_190 ,
& V_714 . V_157 ,
V_356 ) ;
if ( ! V_714 . V_155 ) {
F_18 ( & V_2 -> V_68 -> V_69 ,
L_39 ) ;
return - V_357 ;
}
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_144;
}
V_208 = V_714 . V_155 ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_716 ,
V_714 . V_190 , V_12 , & V_714 ) ;
V_208 -> V_212 . V_233 = V_233 ;
V_208 -> V_717 = V_228 ;
if ( * V_711 ) {
V_208 -> V_718 = F_76 ( * V_225 ) ;
V_208 -> V_719 = F_96 ( V_224 ) ;
V_208 -> V_720 = 0 ;
} else {
V_208 -> V_720 = 1 ;
}
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_715 * V_60 =
V_714 . V_155 ;
if ( * V_711 ) {
memcpy ( V_231 , V_60 -> V_721 . V_722 . V_723 ,
V_232 ) ;
goto V_144;
}
V_713 = V_60 -> V_724 + V_60 -> V_725 ;
for ( V_5 = 0 ; V_5 < V_713 ; V_5 ++ ) {
struct V_726 * V_727 ;
T_3 V_728 ;
T_2 V_718 ;
V_727 = & V_60 -> V_729 [ V_5 ] ;
V_728 = F_26 ( V_727 -> V_728 ) ;
if ( V_728 == sizeof( T_2 ) ) {
* V_711 = true ;
V_718 = V_727 -> V_722 . V_730 . V_718 ;
* V_225 = F_8 ( V_718 ) ;
goto V_144;
}
}
* V_711 = false ;
memcpy ( V_231 , V_60 -> V_729 [ 0 ] . V_722 . V_723 ,
V_232 ) ;
}
V_144:
F_43 ( & V_2 -> V_200 ) ;
F_127 ( & V_2 -> V_68 -> V_69 , V_714 . V_190 ,
V_714 . V_155 , V_714 . V_157 ) ;
return V_45 ;
}
int F_189 ( struct V_1 * V_2 , T_2 V_731 ,
T_1 * V_231 , T_2 V_224 , bool V_732 , T_2 V_233 )
{
if ( ! V_732 )
F_188 ( V_2 , V_231 , & V_732 , & V_731 ,
V_224 , V_233 ) ;
if ( F_20 ( V_2 ) )
return F_100 ( V_2 , V_231 , false ,
V_224 , V_731 ) ;
else
return F_188 ( V_2 , V_231 , & V_732 ,
& V_731 ,
V_224 , V_233 ) ;
}
int F_190 ( struct V_1 * V_2 , T_1 * V_231 )
{
int V_45 ;
bool V_733 = false ;
F_191 ( V_231 ) ;
if ( F_20 ( V_2 ) ) {
if ( F_186 ( V_2 ) )
V_45 = F_100 ( V_2 , V_231 , true , 0 ,
0 ) ;
else
V_45 = F_100 ( V_2 , V_231 , false ,
V_2 -> V_224 , 0 ) ;
} else {
V_45 = F_188 ( V_2 , V_231 , & V_733 ,
NULL , V_2 -> V_224 , 0 ) ;
}
return V_45 ;
}
int F_192 ( struct V_1 * V_2 , T_1 * V_734 ,
T_1 V_713 , T_2 V_233 )
{
struct V_11 * V_12 ;
struct V_735 * V_208 ;
int V_45 ;
struct V_151 V_447 ;
memset ( & V_447 , 0 , sizeof( struct V_151 ) ) ;
V_447 . V_190 = sizeof( struct V_735 ) ;
V_447 . V_155 = F_126 ( & V_2 -> V_68 -> V_69 , V_447 . V_190 , & V_447 . V_157 ,
V_627 ) ;
if ( ! V_447 . V_155 )
return - V_357 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = V_447 . V_155 ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_736 , sizeof( * V_208 ) ,
V_12 , & V_447 ) ;
V_208 -> V_212 . V_233 = V_233 ;
V_208 -> V_713 = V_713 ;
if ( V_713 )
memcpy ( V_208 -> V_231 , V_734 , V_232 * V_713 ) ;
V_45 = F_56 ( V_2 ) ;
V_170:
F_127 ( & V_2 -> V_68 -> V_69 , V_447 . V_190 , V_447 . V_155 , V_447 . V_157 ) ;
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_193 ( struct V_1 * V_2 , T_1 * V_231 , int V_229 , T_2 V_239 )
{
bool V_737 = false ;
T_1 V_738 [ V_232 ] ;
T_2 V_225 ;
int V_45 ;
V_45 = F_188 ( V_2 , V_738 , & V_737 ,
& V_225 , V_229 , V_239 ) ;
if ( ! V_45 && V_737 )
F_102 ( V_2 , V_229 , V_225 , V_239 ) ;
return F_192 ( V_2 , V_231 , V_231 ? 1 : 0 , V_239 ) ;
}
int F_194 ( struct V_1 * V_2 , T_3 V_102 ,
T_2 V_233 , T_3 V_739 , T_3 V_740 , T_1 V_741 )
{
struct V_11 * V_12 ;
struct V_742 * V_208 ;
void * V_246 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
V_246 = & V_208 -> V_216 ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_743 , sizeof( * V_208 ) , V_12 ,
NULL ) ;
V_208 -> V_212 . V_233 = V_233 ;
F_97 ( struct V_744 , V_291 , V_246 , V_739 ) ;
if ( V_102 ) {
F_97 ( struct V_744 , V_745 , V_246 , 1 ) ;
F_97 ( struct V_744 , V_102 , V_246 , V_102 ) ;
}
if ( ! F_20 ( V_2 ) && V_740 ) {
F_97 ( struct V_744 , V_291 ,
V_246 , V_2 -> V_83 ) ;
F_97 ( struct V_744 , V_746 , V_246 , 1 ) ;
F_97 ( struct V_744 , V_747 ,
V_246 , V_740 ) ;
}
if ( ! F_20 ( V_2 ) && V_741 ) {
F_97 ( struct V_744 , V_748 ,
V_246 , V_741 ) ;
F_97 ( struct V_744 , V_749 ,
V_246 , V_741 ) ;
}
F_77 ( V_208 -> V_216 , sizeof( V_208 -> V_216 ) ) ;
V_45 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_195 ( struct V_1 * V_2 , T_3 * V_102 ,
T_2 V_233 , T_3 V_739 , T_1 * V_750 , bool * V_741 )
{
struct V_11 * V_12 ;
struct V_751 * V_208 ;
void * V_246 ;
int V_45 ;
T_3 V_752 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
V_246 = & V_208 -> V_216 ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_753 , sizeof( * V_208 ) , V_12 ,
NULL ) ;
V_208 -> V_212 . V_233 = V_233 ;
F_97 ( struct V_754 , V_291 ,
V_246 , V_739 ) ;
F_97 ( struct V_754 , V_745 , V_246 , 1 ) ;
if ( ! F_20 ( V_2 ) && V_750 ) {
F_97 ( struct V_754 , V_291 ,
V_246 , V_2 -> V_83 ) ;
F_97 ( struct V_754 , V_746 , V_246 , 1 ) ;
}
F_77 ( V_208 -> V_216 , sizeof( V_208 -> V_216 ) ) ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
struct V_755 * V_60 =
F_2 ( V_12 ) ;
F_16 ( & V_60 -> V_216 , sizeof( V_60 -> V_216 ) ) ;
V_752 = F_196 ( struct V_756 ,
V_102 , & V_60 -> V_216 ) ;
if ( V_102 )
* V_102 = F_26 ( V_752 ) ;
if ( V_750 )
* V_750 = F_196 ( struct V_756 ,
V_747 , & V_60 -> V_216 ) ;
if ( V_741 )
* V_741 =
F_196 ( struct V_756 ,
V_741 , & V_60 -> V_216 ) ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
static bool F_197 ( struct V_1 * V_2 )
{
struct V_757 * V_68 = V_2 -> V_68 ;
if ( F_71 ( V_2 ) )
return true ;
switch ( V_68 -> V_758 ) {
case V_759 :
case V_760 :
case V_761 :
case V_762 :
return true ;
default:
return false ;
}
}
int F_198 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_763 * V_208 ;
int V_45 = 0 ;
struct V_151 V_447 ;
if ( ! F_1 ( V_2 , V_643 ,
V_55 ) )
return - V_238 ;
if ( F_197 ( V_2 ) )
return V_45 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
memset ( & V_447 , 0 , sizeof( struct V_151 ) ) ;
V_447 . V_190 = sizeof( struct V_764 ) ;
V_447 . V_155 = F_126 ( & V_2 -> V_68 -> V_69 , V_447 . V_190 , & V_447 . V_157 ,
V_356 ) ;
if ( ! V_447 . V_155 ) {
F_18 ( & V_2 -> V_68 -> V_69 , L_37 ) ;
V_45 = - V_357 ;
goto V_170;
}
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = V_447 . V_155 ;
F_75 ( & V_208 -> V_212 , V_55 ,
V_643 ,
sizeof( * V_208 ) , V_12 , & V_447 ) ;
V_208 -> V_212 . V_182 = 1 ;
V_208 -> V_765 = V_766 ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_764 * V_60 ;
V_60 = (struct V_764 * ) V_447 . V_155 ;
V_2 -> V_767 = V_60 -> V_768 ;
if ( V_2 -> V_767 & V_769 )
V_2 -> V_770 = true ;
}
V_170:
F_90 ( & V_2 -> V_201 ) ;
if ( V_447 . V_155 )
F_127 ( & V_2 -> V_68 -> V_69 , V_447 . V_190 , V_447 . V_155 ,
V_447 . V_157 ) ;
return V_45 ;
}
int F_199 ( struct V_1 * V_2 , T_2 V_771 )
{
struct V_151 V_772 ;
struct V_773 * V_774 ;
int V_45 ;
int V_5 , V_659 ;
memset ( & V_772 , 0 , sizeof( struct V_151 ) ) ;
V_772 . V_190 = sizeof( struct V_775 ) ;
V_772 . V_155 = F_126 ( & V_2 -> V_68 -> V_69 ,
V_772 . V_190 , & V_772 . V_157 ,
V_356 ) ;
if ( ! V_772 . V_155 )
return - V_357 ;
V_45 = F_200 ( V_2 , & V_772 ) ;
if ( V_45 )
goto V_170;
V_774 = (struct V_773 * )
( V_772 . V_155 + sizeof( struct V_30 ) ) ;
for ( V_5 = 0 ; V_5 < F_8 ( V_774 -> V_776 ) ; V_5 ++ ) {
T_2 V_777 = F_8 ( V_774 -> V_778 [ V_5 ] . V_777 ) ;
for ( V_659 = 0 ; V_659 < V_777 ; V_659 ++ ) {
if ( V_774 -> V_778 [ V_5 ] . V_779 [ V_659 ] . V_750 == V_780 )
V_774 -> V_778 [ V_5 ] . V_779 [ V_659 ] . V_781 =
F_76 ( V_771 ) ;
}
}
V_45 = F_201 ( V_2 , & V_772 , V_774 ) ;
V_170:
F_127 ( & V_2 -> V_68 -> V_69 , V_772 . V_190 , V_772 . V_155 ,
V_772 . V_157 ) ;
return V_45 ;
}
int F_202 ( struct V_1 * V_2 )
{
struct V_151 V_772 ;
struct V_773 * V_774 ;
int V_45 , V_659 ;
int V_771 = 0 ;
memset ( & V_772 , 0 , sizeof( struct V_151 ) ) ;
V_772 . V_190 = sizeof( struct V_775 ) ;
V_772 . V_155 = F_126 ( & V_2 -> V_68 -> V_69 ,
V_772 . V_190 , & V_772 . V_157 ,
V_356 ) ;
if ( ! V_772 . V_155 ) {
F_18 ( & V_2 -> V_68 -> V_69 , L_40 ,
V_782 ) ;
goto V_170;
}
V_45 = F_200 ( V_2 , & V_772 ) ;
if ( ! V_45 ) {
V_774 = (struct V_773 * ) ( V_772 . V_155 +
sizeof( struct V_30 ) ) ;
for ( V_659 = 0 ; V_659 < F_8 ( V_774 -> V_778 [ 0 ] . V_777 ) ; V_659 ++ ) {
if ( V_774 -> V_778 [ 0 ] . V_779 [ V_659 ] . V_750 == V_780 )
V_771 = V_774 -> V_778 [ 0 ] . V_779 [ V_659 ] . V_781 ;
}
}
F_127 ( & V_2 -> V_68 -> V_69 , V_772 . V_190 , V_772 . V_155 ,
V_772 . V_157 ) ;
V_170:
return V_771 ;
}
int F_200 ( struct V_1 * V_2 ,
struct V_151 * V_447 )
{
struct V_11 * V_12 ;
struct V_783 * V_208 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = V_447 -> V_155 ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_784 ,
V_447 -> V_190 , V_12 , V_447 ) ;
V_208 -> V_785 = F_76 ( 1 ) ;
V_45 = F_63 ( V_2 ) ;
V_170:
F_90 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_201 ( struct V_1 * V_2 ,
struct V_151 * V_447 ,
struct V_773 * V_786 )
{
struct V_11 * V_12 ;
struct V_787 * V_208 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = V_447 -> V_155 ;
memcpy ( & V_208 -> V_788 , V_786 , sizeof( struct V_773 ) ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_789 ,
V_447 -> V_190 , V_12 , V_447 ) ;
V_45 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_203 ( struct V_1 * V_2 )
{
struct V_790 * V_208 ;
struct V_11 * V_12 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_791 , sizeof( * V_208 ) , V_12 ,
NULL ) ;
if ( ! F_20 ( V_2 ) )
V_208 -> V_212 . V_182 = 1 ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_792 * V_60 = F_2 ( V_12 ) ;
V_2 -> V_84 = V_60 -> V_84 [ V_2 -> V_83 ] ;
} else {
V_2 -> V_84 = V_2 -> V_83 + '0' ;
}
F_90 ( & V_2 -> V_201 ) ;
return V_45 ;
}
static struct V_793 * F_204 ( T_1 * V_349 , T_2 V_794 ,
bool V_795 , T_1 V_796 )
{
struct V_797 * V_212 = (struct V_797 * ) V_349 ;
struct V_793 * V_798 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_794 ; V_5 ++ ) {
if ( V_212 -> V_799 == V_800 ||
V_212 -> V_799 == V_801 ) {
V_798 = (struct V_793 * ) V_212 ;
if ( ( V_796 == V_802 ||
V_798 -> V_796 == V_796 ) &&
( ! V_795 || V_798 -> V_28 & F_107 ( V_803 ) ) )
return V_798 ;
}
V_212 -> V_804 = V_212 -> V_804 ? : V_805 ;
V_212 = ( void * ) V_212 + V_212 -> V_804 ;
}
return NULL ;
}
static struct V_793 * F_205 ( T_1 * V_349 , T_2 V_794 ,
T_1 V_796 )
{
return F_204 ( V_349 , V_794 , true , V_796 ) ;
}
static struct V_793 * F_206 ( T_1 * V_349 , T_2 V_794 ,
T_1 V_796 )
{
return F_204 ( V_349 , V_794 , false , V_796 ) ;
}
static struct V_806 * F_207 ( T_1 * V_349 , T_2 V_794 ,
T_1 V_796 )
{
struct V_797 * V_212 = (struct V_797 * ) V_349 ;
struct V_806 * V_807 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_794 ; V_5 ++ ) {
if ( V_212 -> V_799 == V_808 ||
V_212 -> V_799 == V_809 ) {
V_807 = (struct V_806 * ) V_212 ;
if ( V_807 -> V_796 == V_796 )
return V_807 ;
}
V_212 -> V_804 = V_212 -> V_804 ? : V_805 ;
V_212 = ( void * ) V_212 + V_212 -> V_804 ;
}
return NULL ;
}
static struct V_810 * F_208 ( T_1 * V_349 , T_2 V_794 )
{
struct V_797 * V_212 = (struct V_797 * ) V_349 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_794 ; V_5 ++ ) {
if ( V_212 -> V_799 == V_811 )
return (struct V_810 * ) V_212 ;
V_212 -> V_804 = V_212 -> V_804 ? : V_805 ;
V_212 = ( void * ) V_212 + V_212 -> V_804 ;
}
return NULL ;
}
static void F_209 ( struct V_812 * V_813 ,
struct V_793 * V_814 )
{
V_813 -> V_815 = F_26 ( V_814 -> V_816 ) ;
V_813 -> V_817 = F_26 ( V_814 -> V_818 ) ;
V_813 -> V_819 = F_26 ( V_814 -> V_820 ) ;
V_813 -> V_821 = F_26 ( V_814 -> V_822 ) ;
V_813 -> V_823 = F_26 ( V_814 -> V_824 ) ;
V_813 -> V_825 = F_26 ( V_814 -> V_826 ) ;
V_813 -> V_827 = F_26 ( V_814 -> V_828 ) ;
V_813 -> V_829 = F_26 ( V_814 -> V_830 ) ;
V_813 -> V_831 = F_26 ( V_814 -> V_832 ) ;
V_813 -> V_833 = F_26 ( V_814 -> V_834 ) ;
V_813 -> V_835 = F_8 ( V_814 -> V_309 ) &
V_836 ;
}
int F_210 ( struct V_1 * V_2 , struct V_812 * V_813 )
{
struct V_11 * V_12 ;
struct V_837 * V_208 ;
int V_45 ;
struct V_151 V_447 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
memset ( & V_447 , 0 , sizeof( struct V_151 ) ) ;
V_447 . V_190 = sizeof( struct V_838 ) ;
V_447 . V_155 = F_126 ( & V_2 -> V_68 -> V_69 , V_447 . V_190 , & V_447 . V_157 ,
V_356 ) ;
if ( ! V_447 . V_155 ) {
F_18 ( & V_2 -> V_68 -> V_69 , L_36 ) ;
V_45 = - V_357 ;
goto V_170;
}
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = V_447 . V_155 ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_839 ,
V_447 . V_190 , V_12 , & V_447 ) ;
if ( F_169 ( V_2 ) )
V_208 -> V_212 . V_182 = 1 ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_838 * V_60 = V_447 . V_155 ;
T_2 V_794 = F_8 ( V_60 -> V_794 ) ;
struct V_793 * V_814 ;
V_814 = F_206 ( V_60 -> V_840 , V_794 ,
V_802 ) ;
if ( ! V_814 ) {
V_45 = - V_450 ;
goto V_170;
}
V_2 -> V_796 = V_814 -> V_796 ;
V_2 -> V_841 = V_814 -> V_841 ;
if ( V_813 )
F_209 ( V_813 , V_814 ) ;
}
V_170:
F_90 ( & V_2 -> V_201 ) ;
if ( V_447 . V_155 )
F_127 ( & V_2 -> V_68 -> V_69 , V_447 . V_190 , V_447 . V_155 ,
V_447 . V_157 ) ;
return V_45 ;
}
int F_211 ( struct V_1 * V_2 ,
struct V_812 * V_813 , T_1 V_842 , T_1 V_233 )
{
struct V_843 * V_60 ;
struct V_844 * V_208 ;
struct V_793 * V_845 ;
struct V_806 * V_807 ;
struct V_810 * V_453 ;
struct V_793 * V_798 ;
struct V_11 V_12 = { 0 } ;
struct V_151 V_447 ;
T_3 V_794 ;
int V_45 ;
memset ( & V_447 , 0 , sizeof( struct V_151 ) ) ;
V_447 . V_190 = sizeof( struct V_843 ) ;
V_447 . V_155 = F_126 ( & V_2 -> V_68 -> V_69 , V_447 . V_190 , & V_447 . V_157 ,
V_356 ) ;
if ( ! V_447 . V_155 )
return - V_357 ;
V_208 = V_447 . V_155 ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_846 ,
V_447 . V_190 , & V_12 , & V_447 ) ;
if ( ! F_70 ( V_2 ) )
V_208 -> V_212 . V_182 = 1 ;
V_208 -> type = V_847 ;
V_208 -> V_212 . V_233 = V_233 ;
if ( V_842 == V_848 )
V_208 -> type |= V_849 ;
V_45 = F_92 ( V_2 , & V_12 ) ;
if ( V_45 )
goto V_170;
V_60 = V_447 . V_155 ;
V_794 = F_26 ( V_60 -> V_794 ) ;
V_807 = F_207 ( V_60 -> V_840 , V_794 ,
V_2 -> V_796 ) ;
if ( V_807 )
V_813 -> V_850 = F_26 ( V_807 -> V_851 ) ;
V_453 = F_208 ( V_60 -> V_840 , V_794 ) ;
if ( V_453 )
V_2 -> V_852 = V_453 -> V_852 ;
V_798 = F_206 ( V_60 -> V_840 , V_794 ,
V_2 -> V_796 ) ;
if ( V_798 )
F_209 ( V_813 , V_798 ) ;
V_845 = F_205 ( V_60 -> V_840 , V_794 ,
V_2 -> V_796 ) ;
if ( V_845 )
V_813 -> V_853 = V_845 -> V_309 ;
V_170:
if ( V_447 . V_155 )
F_127 ( & V_2 -> V_68 -> V_69 , V_447 . V_190 , V_447 . V_155 ,
V_447 . V_157 ) ;
return V_45 ;
}
static int F_212 ( struct V_1 * V_2 , void * V_814 ,
int V_190 , int V_217 , T_1 V_182 , T_1 V_233 )
{
struct V_854 * V_208 ;
struct V_11 V_12 = { 0 } ;
struct V_151 V_447 ;
int V_45 ;
memset ( & V_447 , 0 , sizeof( struct V_151 ) ) ;
V_447 . V_190 = sizeof( struct V_854 ) ;
V_447 . V_155 = F_126 ( & V_2 -> V_68 -> V_69 , V_447 . V_190 , & V_447 . V_157 ,
V_356 ) ;
if ( ! V_447 . V_155 )
return - V_357 ;
V_208 = V_447 . V_155 ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_855 , V_447 . V_190 ,
& V_12 , & V_447 ) ;
V_208 -> V_212 . V_182 = V_182 ;
V_208 -> V_212 . V_233 = V_233 ;
V_208 -> V_794 = F_76 ( V_217 ) ;
memcpy ( V_208 -> V_814 , V_814 , V_190 ) ;
V_45 = F_92 ( V_2 , & V_12 ) ;
if ( V_447 . V_155 )
F_127 ( & V_2 -> V_68 -> V_69 , V_447 . V_190 , V_447 . V_155 ,
V_447 . V_157 ) ;
return V_45 ;
}
static void F_213 ( struct V_793 * V_798 )
{
memset ( V_798 , 0 , sizeof( * V_798 ) ) ;
V_798 -> V_816 = 0xFFFF ;
V_798 -> V_834 = 0xFFFF ;
V_798 -> V_818 = 0xFFFF ;
V_798 -> V_820 = 0xFFFF ;
V_798 -> V_822 = 0xFFFF ;
V_798 -> V_826 = 0xFFFF ;
V_798 -> V_824 = 0xFFFF ;
V_798 -> V_856 = 0xFFFF ;
V_798 -> V_830 = 0xFFFF ;
V_798 -> V_857 = 0xFFFF ;
V_798 -> V_828 = 0xFFFF ;
V_798 -> V_832 = 0xFFFF ;
V_798 -> V_858 = 0xFF ;
V_798 -> V_859 = F_96 ( 0xF000 ) ;
V_798 -> V_860 = 0xFF ;
V_798 -> V_861 = 0x0F ;
V_798 -> V_862 = 0xFFFF ;
V_798 -> V_863 = 0xFFFF ;
V_798 -> V_864 = 0xFFFFFFFF ;
V_798 -> V_865 = 0xFFFFFFFF ;
}
static void F_214 ( struct V_806 * V_807 )
{
memset ( V_807 , 0 , sizeof( * V_807 ) ) ;
V_807 -> V_866 = 0xFF ;
V_807 -> V_867 = 0xFF ;
V_807 -> V_868 = 0xFF ;
V_807 -> V_851 = 0xFFFF ;
}
int F_215 ( struct V_1 * V_2 , T_2 V_869 , T_3 V_73 ,
T_1 V_233 )
{
struct V_793 V_870 ;
T_2 V_871 ;
T_3 V_182 = 0 ;
if ( F_116 ( V_2 ) )
return F_179 ( V_2 , V_869 / 10 , V_233 ) ;
F_213 ( & V_870 ) ;
V_870 . V_796 = V_2 -> V_796 ;
V_870 . V_841 = V_233 ;
V_870 . V_864 = 0 ;
if ( F_70 ( V_2 ) ) {
V_870 . V_212 . V_799 = V_800 ;
V_870 . V_212 . V_804 = V_805 ;
V_870 . V_28 = ( 1 << V_872 ) | ( 1 << V_873 ) |
( 1 << V_874 ) ;
V_870 . V_865 = F_76 ( V_869 / 10 ) ;
} else {
V_182 = 1 ;
V_870 . V_212 . V_799 = V_801 ;
V_870 . V_212 . V_804 = V_875 ;
V_870 . V_28 = ( 1 << V_873 ) | ( 1 << V_874 ) ;
V_871 = V_869 ? ( V_869 * 100 ) / V_73 : 100 ;
V_870 . V_865 = F_76 ( V_871 ) ;
}
return F_212 ( V_2 , & V_870 ,
V_870 . V_212 . V_804 ,
1 , V_182 , V_233 ) ;
}
static void F_216 ( struct V_1 * V_2 ,
struct V_812 V_876 ,
T_3 V_851 , T_3 V_877 ,
struct V_793 * V_878 )
{
T_2 V_853 = V_876 . V_853 ;
struct V_812 V_879 = { 0 } ;
F_211 ( V_2 , & V_879 , V_848 , 0 ) ;
if ( V_879 . V_853 & V_427 ) {
V_878 -> V_28 |= F_107 ( V_880 ) ;
if ( V_877 > 1 ) {
V_853 |= V_427 ;
if ( V_876 . V_835 & V_881 )
V_853 |= V_881 ;
} else {
V_853 &= ~ ( V_427 |
V_881 ) ;
}
} else {
V_877 = 1 ;
}
if ( V_879 . V_853 & V_882 ) {
V_878 -> V_28 |= F_107 ( V_880 ) ;
V_853 &= ~ V_882 ;
}
V_878 -> V_309 = F_76 ( V_853 ) ;
V_878 -> V_826 = F_96 ( V_877 ) ;
V_878 -> V_822 = F_96 ( V_877 ) ;
V_878 -> V_824 = F_96 ( V_877 ) ;
V_878 -> V_830 = F_96 ( V_876 . V_829 /
( V_851 + 1 ) ) ;
if ( V_879 . V_815 == V_883 )
V_878 -> V_816 = F_96 ( V_876 . V_815 /
( V_851 + 1 ) ) ;
if ( V_879 . V_817 == V_883 )
V_878 -> V_818 = F_96 ( V_876 . V_817 /
( V_851 + 1 ) ) ;
if ( V_879 . V_831 == V_883 )
V_878 -> V_832 = F_96 ( V_876 . V_831 /
( V_851 + 1 ) ) ;
if ( V_879 . V_833 == V_883 )
V_878 -> V_834 = F_96 ( V_876 . V_833 /
( V_851 + 1 ) ) ;
}
int F_217 ( struct V_1 * V_2 ,
struct V_812 V_876 , T_3 V_851 ,
T_3 V_877 )
{
struct {
struct V_806 V_807 ;
struct V_793 V_878 ;
} V_884 V_814 ;
F_214 ( & V_814 . V_807 ) ;
V_814 . V_807 . V_212 . V_799 = V_809 ;
V_814 . V_807 . V_212 . V_804 = V_875 ;
V_814 . V_807 . V_28 = F_107 ( V_873 ) | F_107 ( V_874 ) ;
V_814 . V_807 . V_796 = V_2 -> V_68 -> V_885 ;
V_814 . V_807 . V_866 = V_851 ? 1 : 0 ;
V_814 . V_807 . V_851 = F_96 ( V_851 ) ;
F_213 ( & V_814 . V_878 ) ;
V_814 . V_878 . V_212 . V_799 = V_801 ;
V_814 . V_878 . V_212 . V_804 = V_875 ;
V_814 . V_878 . V_28 = F_107 ( V_803 ) | F_107 ( V_873 ) | F_107 ( V_874 ) ;
V_814 . V_878 . V_796 = V_2 -> V_68 -> V_885 ;
V_814 . V_878 . V_841 = 0 ;
F_216 ( V_2 , V_876 , V_851 , V_877 ,
& V_814 . V_878 ) ;
return F_212 ( V_2 , & V_814 ,
2 * V_875 , 2 , 1 , 0 ) ;
}
int F_218 ( struct V_1 * V_2 , T_2 V_886 , T_1 V_887 )
{
struct V_11 * V_12 ;
struct V_888 * V_208 ;
int V_45 ;
if ( V_886 == 0xFFFFFFFF )
return - 1 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_889 , sizeof( * V_208 ) ,
V_12 , NULL ) ;
V_208 -> V_887 = V_887 ;
V_208 -> V_890 = F_76 ( V_886 ) ;
V_45 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_219 ( struct V_1 * V_2 , T_7 V_453 )
{
struct V_810 V_891 ;
memset ( & V_891 , 0 , sizeof( V_891 ) ) ;
V_891 . V_212 . V_799 = V_811 ;
V_891 . V_212 . V_804 = V_875 ;
V_891 . V_28 = ( 1 << V_873 ) | ( 1 << V_874 ) ;
V_891 . V_892 = V_2 -> V_83 ;
if ( V_453 ) {
V_891 . V_893 = V_894 | ( 1 << V_895 ) |
( 1 << V_896 ) ;
V_891 . V_897 = F_220 ( V_453 ) ;
} else {
V_891 . V_893 = V_898 ;
V_891 . V_897 = 0 ;
}
return F_212 ( V_2 , & V_891 ,
V_875 , 1 , 1 , 0 ) ;
}
int F_221 ( struct V_1 * V_2 , struct V_899 * V_900 ,
int V_841 )
{
struct V_11 * V_12 ;
struct V_901 * V_208 ;
struct V_902 * V_60 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_903 , sizeof( * V_60 ) ,
V_12 , NULL ) ;
V_208 -> V_212 . V_233 = V_841 + 1 ;
V_45 = F_56 ( V_2 ) ;
if ( ! V_45 ) {
V_60 = (struct V_902 * ) V_208 ;
V_900 -> V_224 = F_8 ( V_60 -> V_904 . V_229 ) ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
static int F_222 ( struct V_1 * V_2 )
{
#define F_223 30
T_2 V_905 ;
int V_45 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < F_223 ; V_5 ++ ) {
V_905 = F_60 ( V_2 -> V_24 + V_906 ) ;
if ( ( V_905 & V_907 ) == 0 )
break;
F_224 ( 1 ) ;
}
if ( V_5 == F_223 )
V_45 = - 1 ;
return V_45 ;
}
int F_167 ( struct V_1 * V_2 , T_2 V_908 )
{
int V_45 = 0 ;
V_45 = F_222 ( V_2 ) ;
if ( V_45 )
return V_45 ;
F_6 ( V_908 , V_2 -> V_24 + V_906 ) ;
return V_45 ;
}
bool F_225 ( struct V_1 * V_2 )
{
T_2 V_163 = 0 ;
V_163 = F_60 ( V_2 -> V_24 + V_164 ) ;
return ! ! ( V_163 & V_909 ) ;
}
int F_226 ( struct V_1 * V_2 )
{
struct V_81 * V_69 = & V_2 -> V_68 -> V_69 ;
int V_45 ;
if ( F_225 ( V_2 ) ) {
F_23 ( V_69 , L_41 ) ;
return - V_910 ;
}
V_45 = F_167 ( V_2 , V_630 |
V_911 ) ;
if ( V_45 < 0 ) {
F_18 ( V_69 , L_42 ) ;
return V_45 ;
}
V_45 = F_222 ( V_2 ) ;
if ( V_45 )
return V_45 ;
if ( ! F_225 ( V_2 ) ) {
F_18 ( V_69 , L_43 ) ;
return - V_20 ;
}
return 0 ;
}
int F_227 ( struct V_1 * V_2 )
{
int V_45 ;
V_45 = F_151 ( V_2 , V_912 ) ;
return F_166 ( V_45 ) ;
}
int F_228 ( struct V_1 * V_2 , T_1 V_233 )
{
struct V_11 * V_12 ;
struct V_913 * V_208 ;
int V_45 ;
if ( F_20 ( V_2 ) )
return 0 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_914 , sizeof( * V_208 ) ,
V_12 , NULL ) ;
V_208 -> V_212 . V_233 = V_233 ;
V_208 -> V_646 = 1 ;
V_45 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_229 ( struct V_1 * V_2 , bool V_915 )
{
struct V_11 * V_12 ;
struct V_916 * V_208 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_917 , sizeof( * V_208 ) ,
V_12 , NULL ) ;
V_208 -> V_918 = V_915 ;
V_45 = F_63 ( V_2 ) ;
F_90 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_230 ( struct V_1 * V_2 , T_3 * V_919 )
{
struct V_920 * V_208 ;
struct V_11 * V_12 ;
int V_45 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_921 , sizeof( * V_208 ) ,
V_12 , NULL ) ;
V_45 = F_63 ( V_2 ) ;
if ( ! V_45 ) {
struct V_922 * V_60 =
F_2 ( V_12 ) ;
* V_919 = F_26 ( V_60 -> V_923 ) ;
}
V_170:
F_90 ( & V_2 -> V_201 ) ;
return V_45 ;
}
int F_231 ( struct V_1 * V_2 ,
int V_924 , int V_182 , T_1 V_233 )
{
struct V_11 * V_12 ;
struct V_925 * V_208 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
F_75 ( & V_208 -> V_212 , V_51 ,
V_926 ,
sizeof( * V_208 ) , V_12 , NULL ) ;
V_208 -> V_212 . V_182 = V_182 ;
V_208 -> V_212 . V_233 = V_233 ;
if ( V_924 == V_927 ||
V_924 == V_928 )
V_208 -> V_929 |= V_930 ;
if ( V_924 == V_928 )
V_208 -> V_929 |= V_931 ;
V_45 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
int F_232 ( struct V_1 * V_2 ,
int V_924 , T_1 V_233 )
{
int V_45 ;
if ( F_20 ( V_2 ) )
return - V_408 ;
V_45 = F_231 ( V_2 , V_924 ,
2 , V_233 ) ;
if ( V_34 ( V_45 ) == V_37 )
V_45 = F_231 ( V_2 , V_924 ,
1 , V_233 ) ;
return V_45 ;
}
int F_233 ( void * V_932 , void * V_933 ,
int V_934 , T_3 * V_935 , T_3 * V_936 )
{
struct V_1 * V_2 = F_234 ( V_932 ) ;
struct V_11 * V_12 ;
struct V_176 * V_212 = (struct V_176 * ) V_933 ;
struct V_176 * V_208 ;
struct V_30 * V_60 ;
int V_45 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_45 = - V_203 ;
goto V_170;
}
V_208 = F_2 ( V_12 ) ;
V_60 = F_2 ( V_12 ) ;
F_75 ( V_208 , V_212 -> V_4 ,
V_212 -> V_3 , V_934 , V_12 , NULL ) ;
memcpy ( V_208 , V_933 , V_934 ) ;
F_77 ( V_208 , V_934 ) ;
V_45 = F_56 ( V_2 ) ;
if ( V_935 )
* V_935 = ( V_45 & 0xffff ) ;
if ( V_936 )
* V_936 = 0 ;
memcpy ( V_933 , V_60 , sizeof( * V_60 ) + V_60 -> V_937 ) ;
F_16 ( V_933 , sizeof( * V_60 ) + V_60 -> V_937 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_45 ;
}
