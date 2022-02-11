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
static void F_3 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 . V_17 ;
T_2 V_18 = 0 ;
if ( F_4 ( V_2 , V_19 ) )
return;
V_18 |= V_15 -> V_20 & V_21 ;
V_18 |= 1 << V_22 ;
F_5 () ;
F_6 ( V_18 , V_2 -> V_23 + V_24 ) ;
}
static inline bool F_7 ( struct V_25 * V_26 )
{
T_2 V_27 ;
if ( V_26 -> V_27 != 0 ) {
V_27 = F_8 ( V_26 -> V_27 ) ;
if ( V_27 & V_28 ) {
V_26 -> V_27 = V_27 ;
return true ;
}
}
return false ;
}
static inline void F_9 ( struct V_25 * V_26 )
{
V_26 -> V_27 = 0 ;
}
static struct V_29 * F_10 ( T_2 V_30 , T_2 V_31 )
{
unsigned long V_32 ;
V_32 = V_31 ;
V_32 = ( ( V_32 << 16 ) << 16 ) | V_30 ;
return ( void * ) V_32 ;
}
static bool F_11 ( T_1 V_3 , T_3 V_33 , T_3 V_34 )
{
if ( V_33 == V_35 ||
V_33 == V_36 ||
V_34 == V_37 ||
V_34 == V_38 ||
( V_3 == V_39 &&
( V_33 == V_40 ||
V_34 == V_41 ) ) )
return true ;
else
return false ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_29 * V_42 )
{
enum V_43 V_33 = V_33 ( V_26 -> V_44 ) ;
T_1 V_3 = 0 , V_4 = 0 ;
if ( V_42 ) {
V_3 = V_42 -> V_3 ;
V_4 = V_42 -> V_4 ;
}
if ( V_3 == V_45 &&
V_4 == V_46 ) {
F_13 ( & V_2 -> V_47 ) ;
return;
}
if ( ( V_3 == V_39 ||
V_3 == V_48 ) &&
V_4 == V_49 ) {
V_2 -> V_50 = V_26 -> V_44 ;
F_13 ( & V_2 -> V_47 ) ;
return;
}
if ( ( V_3 == V_51 ||
V_3 == V_52 ) &&
V_4 == V_53 &&
V_33 == V_54 ) {
F_14 ( V_2 ) ;
V_2 -> V_55 = false ;
return;
}
if ( V_3 == V_56 &&
V_4 == V_49 ) {
if ( V_33 == V_54 ) {
struct V_57 * V_58 =
( void * ) V_42 ;
V_2 -> V_59 . V_60 =
V_58 -> V_61 ;
} else {
V_2 -> V_62 = 0 ;
V_2 -> V_59 . V_60 =
V_63 ;
}
return;
}
}
static int F_15 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
enum V_43 V_33 ;
enum V_64 V_34 ;
struct V_29 * V_42 ;
T_1 V_3 = 0 , V_4 = 0 ;
F_16 ( V_26 , 4 ) ;
V_33 = V_33 ( V_26 -> V_44 ) ;
V_34 = V_34 ( V_26 -> V_44 ) ;
V_42 = F_10 ( V_26 -> V_30 , V_26 -> V_31 ) ;
if ( V_42 ) {
V_3 = V_42 -> V_3 ;
V_4 = V_42 -> V_4 ;
}
F_12 ( V_2 , V_26 , V_42 ) ;
if ( V_33 != V_54 &&
! F_11 ( V_3 , V_33 , V_34 ) ) {
if ( V_33 == V_65 ) {
F_17 ( & V_2 -> V_66 -> V_67 ,
L_1 ,
V_3 , V_4 ) ;
} else {
F_18 ( & V_2 -> V_66 -> V_67 ,
L_2 ,
V_3 , V_4 , V_33 , V_34 ) ;
}
}
return V_26 -> V_44 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_68 * V_69 =
(struct V_68 * ) V_26 ;
V_2 -> V_70 . V_71 = - 1 ;
if ( ! F_20 ( V_2 ) &&
! ( V_69 -> V_72 & V_73 ) )
return;
if ( V_2 -> V_27 & V_74 )
F_21 ( V_2 ,
V_69 -> V_72 & V_75 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_76 * V_69 =
(struct V_76 * ) V_26 ;
T_2 V_77 = F_8 ( V_69 -> V_78 ) ;
struct V_79 * V_67 = & V_2 -> V_66 -> V_67 ;
T_1 V_80 ;
V_80 =
( ( V_77 >> ( V_2 -> V_81 * 8 ) ) & 0xff ) ;
F_23 ( V_67 , L_3 , V_2 -> V_82 ,
V_83 [ V_80 ] ,
V_84 [ V_80 ] ) ;
if ( V_80 == V_85 )
V_2 -> V_27 |= V_86 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_87 * V_69 =
(struct V_87 * ) V_26 ;
if ( V_69 -> V_88 ) {
V_2 -> V_89 = V_69 -> V_90 ;
V_2 -> V_91 &= ~ V_92 ;
V_2 -> V_91 =
V_69 -> V_93 << V_94 ;
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_95 * V_69 =
(struct V_95 * ) V_26 ;
if ( V_2 -> V_70 . V_71 >= 0 &&
V_69 -> V_96 == V_2 -> V_97 )
V_2 -> V_70 . V_71 = F_26 ( V_69 -> V_98 ) * 10 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_99 * V_69 =
(struct V_99 * ) V_26 ;
if ( V_69 -> V_100 ) {
V_2 -> V_101 = F_26 ( V_69 -> V_102 ) & V_103 ;
F_23 ( & V_2 -> V_66 -> V_67 , L_4 , V_2 -> V_101 ) ;
} else {
V_2 -> V_101 = 0 ;
}
}
static void F_28 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_104 * V_69 = (struct V_104 * ) V_26 ;
T_2 V_105 = F_8 ( V_69 -> V_78 ) ;
if ( V_105 & V_106 ) {
V_2 -> V_27 |= V_107 ;
V_2 -> V_108 = F_8 ( V_69 -> V_109 ) ;
} else {
V_2 -> V_27 &= ~ V_107 ;
}
}
static void F_29 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
T_1 V_110 = ( V_26 -> V_27 >> V_111 ) &
V_112 ;
switch ( V_110 ) {
case V_113 :
F_24 ( V_2 , V_26 ) ;
break;
case V_114 :
F_25 ( V_2 , V_26 ) ;
break;
case V_115 :
F_27 ( V_2 , V_26 ) ;
break;
case V_116 :
F_28 ( V_2 , V_26 ) ;
break;
default:
break;
}
}
static void F_30 ( struct V_1 * V_2 ,
struct V_25 * V_117 )
{
T_1 V_110 = 0 ;
struct V_118 * V_69 = (struct V_118 * ) V_117 ;
V_110 = ( V_117 -> V_27 >> V_111 ) &
V_112 ;
switch ( V_110 ) {
case V_119 :
if ( V_69 -> V_88 )
V_2 -> V_120 = F_26 ( V_69 -> V_121 ) ;
V_2 -> V_27 |= V_122 ;
break;
default:
F_17 ( & V_2 -> V_66 -> V_67 , L_5 ,
V_110 ) ;
break;
}
}
static void F_31 ( struct V_1 * V_2 ,
struct V_25 * V_117 )
{
T_1 V_110 = ( V_117 -> V_27 >> V_111 ) &
V_112 ;
if ( V_110 == V_123 )
F_22 ( V_2 , V_117 ) ;
}
static inline bool F_32 ( T_2 V_27 )
{
return ( ( V_27 >> V_124 ) & V_125 ) ==
V_126 ;
}
static inline bool F_33 ( T_2 V_27 )
{
return ( ( V_27 >> V_124 ) & V_125 ) ==
V_127 ;
}
static inline bool F_34 ( T_2 V_27 )
{
return ( ( V_27 >> V_124 ) & V_125 ) ==
V_128 ;
}
static inline bool F_35 ( T_2 V_27 )
{
return ( ( V_27 >> V_124 ) & V_125 ) ==
V_129 ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
if ( F_32 ( V_26 -> V_27 ) )
F_19 ( V_2 , V_26 ) ;
else if ( F_33 ( V_26 -> V_27 ) )
F_29 ( V_2 , V_26 ) ;
else if ( F_34 ( V_26 -> V_27 ) )
F_30 ( V_2 , V_26 ) ;
else if ( F_35 ( V_26 -> V_27 ) )
F_31 ( V_2 , V_26 ) ;
}
static struct V_25 * F_37 ( struct V_1 * V_2 )
{
struct V_14 * V_130 = & V_2 -> V_16 . V_131 ;
struct V_25 * V_26 = F_38 ( V_130 ) ;
if ( F_7 ( V_26 ) ) {
F_39 ( V_130 ) ;
return V_26 ;
}
return NULL ;
}
void F_40 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_132 ) ;
F_42 ( V_2 , V_2 -> V_16 . V_131 . V_20 , true , 0 ) ;
V_2 -> V_16 . V_133 = true ;
F_43 ( & V_2 -> V_132 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_132 ) ;
V_2 -> V_16 . V_133 = false ;
F_42 ( V_2 , V_2 -> V_16 . V_131 . V_20 , false , 0 ) ;
F_43 ( & V_2 -> V_132 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
int V_134 = 0 , V_44 = 0 ;
struct V_135 * V_16 = & V_2 -> V_16 ;
F_46 ( & V_2 -> V_132 ) ;
while ( ( V_26 = F_37 ( V_2 ) ) ) {
if ( V_26 -> V_27 & V_136 ) {
F_36 ( V_2 , V_26 ) ;
} else if ( V_26 -> V_27 & V_137 ) {
V_44 = F_15 ( V_2 , V_26 ) ;
F_47 ( & V_16 -> V_17 . V_138 ) ;
}
F_9 ( V_26 ) ;
V_134 ++ ;
}
if ( V_134 )
F_42 ( V_2 , V_16 -> V_131 . V_20 , V_16 -> V_133 , V_134 ) ;
F_48 ( & V_2 -> V_132 ) ;
return V_44 ;
}
static int F_49 ( struct V_1 * V_2 )
{
#define F_50 120000
int V_5 , V_44 = 0 ;
struct V_135 * V_16 = & V_2 -> V_16 ;
for ( V_5 = 0 ; V_5 < F_50 ; V_5 ++ ) {
if ( F_4 ( V_2 , V_19 ) )
return - V_139 ;
F_51 () ;
V_44 = F_45 ( V_2 ) ;
F_52 () ;
if ( F_53 ( & V_16 -> V_17 . V_138 ) == 0 )
break;
F_54 ( 100 ) ;
}
if ( V_5 == F_50 ) {
F_18 ( & V_2 -> V_66 -> V_67 , L_6 ) ;
F_55 ( V_2 , V_140 ) ;
return - V_139 ;
}
return V_44 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_44 ;
struct V_11 * V_12 ;
struct V_135 * V_16 = & V_2 -> V_16 ;
T_3 V_141 = V_16 -> V_17 . V_142 ;
struct V_29 * V_58 ;
F_57 ( & V_141 , V_16 -> V_17 . V_143 ) ;
V_12 = F_58 ( & V_16 -> V_17 , V_141 ) ;
V_58 = F_10 ( V_12 -> V_30 , V_12 -> V_31 ) ;
F_3 ( V_2 ) ;
V_44 = F_49 ( V_2 ) ;
if ( V_44 == - V_139 )
goto V_144;
V_44 = ( V_58 -> V_33 |
( ( V_58 -> V_34 & V_145 ) <<
V_146 ) ) ;
V_144:
return V_44 ;
}
static int F_59 ( struct V_1 * V_2 , void T_4 * V_23 )
{
int V_147 = 0 ;
T_2 V_148 ;
do {
if ( F_4 ( V_2 , V_19 ) )
return - V_139 ;
V_148 = F_60 ( V_23 ) ;
if ( V_148 == 0xffffffff )
return - 1 ;
V_148 &= V_149 ;
if ( V_148 )
break;
if ( V_147 > 4000 ) {
F_18 ( & V_2 -> V_66 -> V_67 , L_6 ) ;
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
int V_44 ;
T_2 V_18 = 0 ;
void T_4 * V_23 = V_2 -> V_23 + V_150 ;
struct V_151 * V_152 = & V_2 -> V_152 ;
struct V_153 * V_154 = V_152 -> V_155 ;
struct V_25 * V_26 = & V_154 -> V_26 ;
V_44 = F_59 ( V_2 , V_23 ) ;
if ( V_44 != 0 )
return V_44 ;
V_18 |= V_156 ;
V_18 |= ( F_64 ( V_152 -> V_157 ) >> 2 ) << 2 ;
F_6 ( V_18 , V_23 ) ;
V_44 = F_59 ( V_2 , V_23 ) ;
if ( V_44 != 0 )
return V_44 ;
V_18 = 0 ;
V_18 |= ( T_2 ) ( V_152 -> V_157 >> 4 ) << 2 ;
F_6 ( V_18 , V_23 ) ;
V_44 = F_59 ( V_2 , V_23 ) ;
if ( V_44 != 0 )
return V_44 ;
if ( F_7 ( V_26 ) ) {
V_44 = F_15 ( V_2 , & V_154 -> V_26 ) ;
F_9 ( V_26 ) ;
if ( V_44 )
return V_44 ;
} else {
F_18 ( & V_2 -> V_66 -> V_67 , L_7 ) ;
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
F_66 ( V_2 -> V_66 ,
V_161 , & V_158 ) ;
return V_158 & V_162 ;
}
static int F_67 ( struct V_1 * V_2 )
{
#define F_68 30
T_2 V_163 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_68 ; V_5 ++ ) {
V_163 = F_60 ( V_2 -> V_23 + V_164 ) ;
if ( V_163 & V_165 )
return 0 ;
if ( V_163 & V_166 &&
! ( V_163 & V_167 ) )
return - V_139 ;
F_62 ( 1000 ) ;
}
return V_163 ? : - 1 ;
}
int F_69 ( struct V_1 * V_2 )
{
T_3 V_168 ;
int V_44 , V_169 = 0 ;
struct V_79 * V_67 = & V_2 -> V_66 -> V_67 ;
if ( F_70 ( V_2 ) ) {
V_44 = F_67 ( V_2 ) ;
if ( V_44 ) {
V_168 = V_44 ;
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
F_23 ( V_67 , L_8 , V_169 ) ;
if ( F_72 ( 2000 ) ) {
F_18 ( V_67 , L_9 ) ;
return - V_172 ;
}
V_169 += 2 ;
} while ( V_169 < 60 );
V_170:
F_18 ( V_67 , L_10 , V_168 ) ;
return - V_173 ;
}
static inline struct V_174 * F_73 ( struct V_11 * V_12 )
{
return & V_12 -> V_13 . V_175 [ 0 ] ;
}
static inline void F_74 ( struct V_11 * V_12 , unsigned long V_32 )
{
V_12 -> V_30 = V_32 & 0xFFFFFFFF ;
V_12 -> V_31 = F_64 ( V_32 ) ;
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
if ( F_53 ( & V_15 -> V_138 ) >= V_15 -> V_143 )
return NULL ;
V_12 = F_83 ( V_15 ) ;
F_84 ( V_15 ) ;
F_85 ( & V_15 -> V_138 ) ;
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
int V_44 ;
V_44 = F_87 ( V_2 ) ;
if ( V_44 )
return V_44 ;
V_202 = F_91 ( V_2 , V_12 ) ;
if ( ! V_202 )
return - V_203 ;
if ( F_86 ( V_2 ) )
V_44 = F_56 ( V_2 ) ;
else
V_44 = F_63 ( V_2 ) ;
if ( ! V_44 )
memcpy ( V_12 , V_202 , sizeof( * V_12 ) ) ;
F_89 ( V_2 ) ;
return V_44 ;
}
int F_93 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_44 ;
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
V_44 = F_63 ( V_2 ) ;
F_90 ( & V_2 -> V_201 ) ;
return V_44 ;
}
int F_94 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_44 ;
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
V_44 = F_63 ( V_2 ) ;
F_90 ( & V_2 -> V_201 ) ;
return V_44 ;
}
int F_95 ( struct V_1 * V_2 , struct V_204 * V_205 )
{
struct V_11 * V_12 ;
struct V_206 * V_207 ;
struct V_151 * V_208 = & V_205 -> V_17 . V_209 ;
int V_44 , V_210 = 0 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_212 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
if ( ! ( F_20 ( V_2 ) || F_70 ( V_2 ) ) )
V_210 = 2 ;
V_207 -> V_211 . V_182 = V_210 ;
V_207 -> V_213 = F_96 ( F_80 ( V_208 -> V_155 , V_208 -> V_190 ) ) ;
F_97 ( struct V_214 , V_88 , V_207 -> V_215 , 1 ) ;
F_97 ( struct V_214 , V_190 , V_207 -> V_215 , 0 ) ;
F_97 ( struct V_214 , V_216 , V_207 -> V_215 ,
F_98 ( V_205 -> V_17 . V_143 / 256 ) ) ;
F_77 ( V_207 -> V_215 , sizeof( V_207 -> V_215 ) ) ;
F_78 ( V_207 -> V_193 , F_99 ( V_207 -> V_193 ) , V_208 ) ;
V_44 = F_63 ( V_2 ) ;
if ( ! V_44 ) {
struct V_217 * V_58 = F_2 ( V_12 ) ;
V_205 -> V_17 . V_20 = F_26 ( V_58 -> V_218 ) ;
V_205 -> V_219 =
( V_210 == 2 ) ? F_26 ( V_58 -> V_219 ) : V_205 -> V_220 ;
V_205 -> V_17 . V_199 = true ;
}
F_90 ( & V_2 -> V_201 ) ;
return V_44 ;
}
int F_100 ( struct V_1 * V_2 , T_1 * V_221 ,
bool V_222 , T_2 V_223 , T_2 V_224 )
{
struct V_11 * V_12 ;
struct V_225 * V_207 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_226 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> type = V_227 ;
if ( V_222 ) {
V_207 -> V_222 = 1 ;
} else {
V_207 -> V_228 = F_96 ( ( T_3 ) V_223 ) ;
V_207 -> V_224 = F_76 ( V_224 ) ;
V_207 -> V_222 = 0 ;
}
V_44 = F_56 ( V_2 ) ;
if ( ! V_44 ) {
struct V_229 * V_58 = F_2 ( V_12 ) ;
memcpy ( V_221 , V_58 -> V_230 . V_32 , V_231 ) ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_101 ( struct V_1 * V_2 , T_1 * V_221 ,
T_2 V_228 , T_2 * V_224 , T_2 V_232 )
{
struct V_11 * V_12 ;
struct V_233 * V_207 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_234 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
V_207 -> V_228 = F_76 ( V_228 ) ;
memcpy ( V_207 -> V_235 , V_221 , V_231 ) ;
V_44 = F_56 ( V_2 ) ;
if ( ! V_44 ) {
struct V_236 * V_58 = F_2 ( V_12 ) ;
* V_224 = F_8 ( V_58 -> V_224 ) ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
if ( V_44 == V_65 )
V_44 = - V_237 ;
return V_44 ;
}
int F_102 ( struct V_1 * V_2 , T_2 V_228 , int V_224 , T_2 V_238 )
{
struct V_11 * V_12 ;
struct V_239 * V_207 ;
int V_44 ;
if ( V_224 == - 1 )
return 0 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_240 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_211 . V_232 = V_238 ;
V_207 -> V_228 = F_76 ( V_228 ) ;
V_207 -> V_224 = F_76 ( V_224 ) ;
V_44 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_103 ( struct V_1 * V_2 , struct V_14 * V_131 ,
struct V_14 * V_241 , bool V_242 , int V_243 )
{
struct V_11 * V_12 ;
struct V_244 * V_207 ;
struct V_151 * V_208 = & V_131 -> V_209 ;
void * V_245 ;
int V_44 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_207 = F_2 ( V_12 ) ;
V_245 = & V_207 -> V_215 ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_246 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_213 = F_96 ( F_80 ( V_208 -> V_155 , V_208 -> V_190 ) ) ;
if ( F_20 ( V_2 ) ) {
F_97 ( struct V_247 , V_248 , V_245 ,
V_243 ) ;
F_97 ( struct V_247 , V_249 ,
V_245 , V_242 ) ;
F_97 ( struct V_247 , V_216 , V_245 ,
F_98 ( V_131 -> V_143 / 256 ) ) ;
F_97 ( struct V_247 , V_88 , V_245 , 1 ) ;
F_97 ( struct V_247 , V_250 , V_245 , 1 ) ;
F_97 ( struct V_247 , V_251 , V_245 , V_241 -> V_20 ) ;
} else {
V_207 -> V_211 . V_182 = 2 ;
V_207 -> V_252 = 1 ;
if ( ! F_70 ( V_2 ) )
F_97 ( struct V_253 , V_248 ,
V_245 , V_243 ) ;
F_97 ( struct V_253 , V_249 , V_245 ,
V_242 ) ;
F_97 ( struct V_253 , V_216 , V_245 ,
F_98 ( V_131 -> V_143 / 256 ) ) ;
F_97 ( struct V_253 , V_88 , V_245 , 1 ) ;
F_97 ( struct V_253 , V_250 , V_245 , 1 ) ;
F_97 ( struct V_253 , V_251 , V_245 , V_241 -> V_20 ) ;
}
F_77 ( V_245 , sizeof( V_207 -> V_215 ) ) ;
F_78 ( V_207 -> V_193 , F_99 ( V_207 -> V_193 ) , V_208 ) ;
V_44 = F_63 ( V_2 ) ;
if ( ! V_44 ) {
struct V_254 * V_58 = F_2 ( V_12 ) ;
V_131 -> V_20 = F_26 ( V_58 -> V_255 ) ;
V_131 -> V_199 = true ;
}
F_90 ( & V_2 -> V_201 ) ;
return V_44 ;
}
static T_2 F_104 ( int V_256 )
{
T_2 V_257 = F_105 ( V_256 ) ;
if ( V_257 == 16 )
V_257 = 0 ;
return V_257 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_131 )
{
struct V_11 * V_12 ;
struct V_258 * V_207 ;
struct V_151 * V_208 = & V_15 -> V_209 ;
void * V_245 ;
int V_44 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_207 = F_2 ( V_12 ) ;
V_245 = & V_207 -> V_215 ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_259 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_213 = F_96 ( F_80 ( V_208 -> V_155 , V_208 -> V_190 ) ) ;
if ( F_20 ( V_2 ) ) {
F_97 ( struct V_260 , V_88 , V_245 , 1 ) ;
F_97 ( struct V_260 , V_261 , V_245 ,
F_104 ( V_15 -> V_143 ) ) ;
F_97 ( struct V_260 , V_255 , V_245 , V_131 -> V_20 ) ;
} else {
V_207 -> V_211 . V_182 = 1 ;
V_207 -> V_255 = F_96 ( V_131 -> V_20 ) ;
F_97 ( struct V_262 , V_261 , V_245 ,
F_104 ( V_15 -> V_143 ) ) ;
F_97 ( struct V_262 , V_88 , V_245 , 1 ) ;
F_97 ( struct V_262 , V_263 ,
V_245 , V_131 -> V_20 ) ;
F_97 ( struct V_262 , V_264 ,
V_245 , 1 ) ;
}
V_207 -> V_265 [ 0 ] =
F_76 ( F_107 ( V_126 ) |
F_107 ( V_127 ) |
F_107 ( V_128 ) |
F_107 ( V_129 ) ) ;
F_77 ( V_245 , sizeof( V_207 -> V_215 ) ) ;
F_78 ( V_207 -> V_193 , F_99 ( V_207 -> V_193 ) , V_208 ) ;
V_44 = F_63 ( V_2 ) ;
if ( ! V_44 ) {
struct V_266 * V_58 = F_2 ( V_12 ) ;
V_15 -> V_20 = F_26 ( V_58 -> V_20 ) ;
V_15 -> V_199 = true ;
}
F_90 ( & V_2 -> V_201 ) ;
return V_44 ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_131 )
{
struct V_11 * V_12 ;
struct V_267 * V_207 ;
struct V_151 * V_208 = & V_15 -> V_209 ;
void * V_245 ;
int V_44 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_207 = F_2 ( V_12 ) ;
V_245 = & V_207 -> V_215 ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_268 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_213 = F_96 ( F_80 ( V_208 -> V_155 , V_208 -> V_190 ) ) ;
F_97 ( struct V_260 , V_88 , V_245 , 1 ) ;
F_97 ( struct V_260 , V_261 , V_245 ,
F_104 ( V_15 -> V_143 ) ) ;
F_97 ( struct V_260 , V_255 , V_245 , V_131 -> V_20 ) ;
F_77 ( V_245 , sizeof( V_207 -> V_215 ) ) ;
F_78 ( V_207 -> V_193 , F_99 ( V_207 -> V_193 ) , V_208 ) ;
V_44 = F_63 ( V_2 ) ;
if ( ! V_44 ) {
struct V_266 * V_58 = F_2 ( V_12 ) ;
V_15 -> V_20 = F_26 ( V_58 -> V_20 ) ;
V_15 -> V_199 = true ;
}
F_90 ( & V_2 -> V_201 ) ;
return V_44 ;
}
int F_109 ( struct V_1 * V_2 ,
struct V_14 * V_15 , struct V_14 * V_131 )
{
int V_44 ;
V_44 = F_106 ( V_2 , V_15 , V_131 ) ;
if ( V_44 && F_20 ( V_2 ) ) {
F_17 ( & V_2 -> V_66 -> V_67 , L_11
L_12
L_13 ) ;
V_44 = F_108 ( V_2 , V_15 , V_131 ) ;
}
return V_44 ;
}
int F_110 ( struct V_1 * V_2 , struct V_269 * V_270 )
{
struct V_11 V_12 = { 0 } ;
struct V_271 * V_207 ;
struct V_14 * V_272 = & V_270 -> V_17 ;
struct V_14 * V_131 = & V_270 -> V_131 ;
struct V_151 * V_208 = & V_272 -> V_209 ;
int V_44 , V_210 = 0 ;
V_207 = F_2 ( & V_12 ) ;
F_75 ( & V_207 -> V_211 , V_53 ,
V_273 , sizeof( * V_207 ) , & V_12 , NULL ) ;
if ( F_70 ( V_2 ) ) {
V_207 -> V_211 . V_182 = 1 ;
} else if ( F_20 ( V_2 ) ) {
if ( V_2 -> V_274 & V_275 )
V_207 -> V_211 . V_182 = 2 ;
} else {
V_207 -> V_211 . V_182 = 2 ;
}
if ( V_207 -> V_211 . V_182 > 0 )
V_207 -> V_228 = F_96 ( V_2 -> V_223 ) ;
V_207 -> V_213 = F_80 ( V_208 -> V_155 , V_208 -> V_190 ) ;
V_207 -> V_276 = V_277 ;
V_207 -> type = V_278 ;
V_207 -> V_255 = F_96 ( V_131 -> V_20 ) ;
V_207 -> V_279 = F_104 ( V_272 -> V_143 ) ;
F_78 ( V_207 -> V_193 , F_99 ( V_207 -> V_193 ) , V_208 ) ;
V_210 = V_207 -> V_211 . V_182 ;
V_44 = F_92 ( V_2 , & V_12 ) ;
if ( ! V_44 ) {
struct V_280 * V_58 = F_2 ( & V_12 ) ;
V_272 -> V_20 = F_26 ( V_58 -> V_281 ) ;
if ( V_210 == 2 )
V_270 -> V_282 = F_8 ( V_58 -> V_282 ) ;
else
V_270 -> V_282 = V_283 ;
V_272 -> V_199 = true ;
}
return V_44 ;
}
int F_111 ( struct V_1 * V_2 ,
struct V_14 * V_284 , T_3 V_255 , T_3 V_285 ,
T_2 V_228 , T_2 V_286 , T_1 * V_287 )
{
struct V_11 * V_12 ;
struct V_288 * V_207 ;
struct V_151 * V_208 = & V_284 -> V_209 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_53 ,
V_289 , sizeof( * V_207 ) , V_12 , NULL ) ;
V_207 -> V_255 = F_96 ( V_255 ) ;
V_207 -> V_285 = F_105 ( V_285 ) - 1 ;
V_207 -> V_213 = 2 ;
F_78 ( V_207 -> V_193 , F_99 ( V_207 -> V_193 ) , V_208 ) ;
V_207 -> V_290 = F_76 ( V_228 ) ;
V_207 -> V_291 = F_96 ( V_292 ) ;
V_207 -> V_293 = F_76 ( V_286 ) ;
V_44 = F_56 ( V_2 ) ;
if ( ! V_44 ) {
struct V_294 * V_58 = F_2 ( V_12 ) ;
V_284 -> V_20 = F_26 ( V_58 -> V_20 ) ;
V_284 -> V_199 = true ;
* V_287 = V_58 -> V_287 ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_112 ( struct V_1 * V_2 , struct V_14 * V_17 ,
int V_295 )
{
struct V_11 * V_12 ;
struct V_296 * V_207 ;
T_1 V_297 = 0 , V_3 = 0 ;
int V_44 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_207 = F_2 ( V_12 ) ;
switch ( V_295 ) {
case V_298 :
V_297 = V_49 ;
V_3 = V_299 ;
break;
case V_300 :
V_297 = V_49 ;
V_3 = V_301 ;
break;
case V_302 :
V_297 = V_53 ;
V_3 = V_303 ;
break;
case V_304 :
V_297 = V_53 ;
V_3 = V_305 ;
break;
case V_306 :
V_297 = V_49 ;
V_3 = V_307 ;
break;
default:
F_113 () ;
}
F_75 ( & V_207 -> V_211 , V_297 , V_3 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_20 = F_96 ( V_17 -> V_20 ) ;
V_44 = F_63 ( V_2 ) ;
V_17 -> V_199 = false ;
F_90 ( & V_2 -> V_201 ) ;
return V_44 ;
}
int F_114 ( struct V_1 * V_2 , struct V_14 * V_17 )
{
struct V_11 * V_12 ;
struct V_296 * V_207 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_53 ,
V_305 , sizeof( * V_207 ) , V_12 , NULL ) ;
V_207 -> V_20 = F_96 ( V_17 -> V_20 ) ;
V_44 = F_56 ( V_2 ) ;
V_17 -> V_199 = false ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_115 ( struct V_1 * V_2 , T_2 V_308 , T_2 V_309 ,
T_2 * V_223 , T_2 V_232 )
{
struct V_11 V_12 = { 0 } ;
struct V_310 * V_207 ;
int V_44 ;
V_207 = F_2 ( & V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_311 ,
sizeof( * V_207 ) , & V_12 , NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
V_207 -> V_312 = F_76 ( V_308 ) ;
V_207 -> V_313 = F_76 ( V_309 ) ;
V_207 -> V_314 = true ;
V_44 = F_92 ( V_2 , & V_12 ) ;
if ( ! V_44 ) {
struct V_315 * V_58 = F_2 ( & V_12 ) ;
* V_223 = F_8 ( V_58 -> V_290 ) ;
if ( F_116 ( V_2 ) && F_71 ( V_2 ) )
V_2 -> V_224 [ 0 ] = F_8 ( V_58 -> V_224 ) ;
}
return V_44 ;
}
int F_117 ( struct V_1 * V_2 , int V_290 , T_2 V_232 )
{
struct V_11 * V_12 ;
struct V_316 * V_207 ;
int V_44 ;
if ( V_290 == - 1 )
return 0 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_317 ,
sizeof( * V_207 ) , V_12 , NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
V_207 -> V_290 = F_76 ( V_290 ) ;
V_44 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_118 ( struct V_1 * V_2 , struct V_151 * V_318 )
{
struct V_11 * V_12 ;
struct V_176 * V_211 ;
int V_44 = 0 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_211 = V_318 -> V_155 ;
F_75 ( V_211 , V_53 ,
V_51 , V_318 -> V_190 , V_12 ,
V_318 ) ;
if ( F_119 ( V_2 ) )
V_211 -> V_182 = 0 ;
if ( F_116 ( V_2 ) || F_70 ( V_2 ) )
V_211 -> V_182 = 1 ;
else
V_211 -> V_182 = 2 ;
F_3 ( V_2 ) ;
V_2 -> V_55 = true ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_120 ( struct V_1 * V_2 ,
struct V_151 * V_318 )
{
struct V_11 * V_12 ;
struct V_319 * V_207 ;
int V_44 = 0 ;
if ( ! F_1 ( V_2 , V_52 ,
V_53 ) )
return - V_237 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = V_318 -> V_155 ;
F_75 ( & V_207 -> V_211 , V_53 ,
V_52 , V_318 -> V_190 ,
V_12 , V_318 ) ;
V_207 -> V_320 . V_321 . V_322 = F_96 ( V_2 -> V_81 ) ;
V_207 -> V_320 . V_321 . V_323 = 0 ;
F_3 ( V_2 ) ;
V_2 -> V_55 = true ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
static int F_121 ( int V_324 )
{
switch ( V_324 ) {
case V_325 :
return 0 ;
case V_326 :
return 10 ;
case V_327 :
return 100 ;
case V_328 :
return 1000 ;
case V_329 :
return 10000 ;
case V_330 :
return 20000 ;
case V_331 :
return 25000 ;
case V_332 :
return 40000 ;
}
return 0 ;
}
int F_122 ( struct V_1 * V_2 , T_3 * V_71 ,
T_1 * V_333 , T_2 V_238 )
{
struct V_11 * V_12 ;
struct V_334 * V_207 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
if ( V_333 )
* V_333 = V_335 ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_336 ,
sizeof( * V_207 ) , V_12 , NULL ) ;
if ( ! F_119 ( V_2 ) )
V_207 -> V_211 . V_182 = 1 ;
V_207 -> V_211 . V_232 = V_238 ;
V_44 = F_56 ( V_2 ) ;
if ( ! V_44 ) {
struct V_337 * V_58 = F_2 ( V_12 ) ;
if ( V_71 ) {
* V_71 = V_58 -> V_71 ?
F_26 ( V_58 -> V_71 ) * 10 :
F_121 ( V_58 -> V_324 ) ;
if ( ! V_58 -> V_338 )
* V_71 = 0 ;
}
if ( V_333 )
* V_333 = V_58 -> V_338 ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_123 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_339 * V_207 ;
int V_44 = 0 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_56 ,
sizeof( * V_207 ) , V_12 , NULL ) ;
F_3 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_124 ( struct V_1 * V_2 , T_2 * V_340 )
{
struct V_11 * V_12 ;
struct V_341 * V_207 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_342 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_343 = F_76 ( V_344 ) ;
V_44 = F_56 ( V_2 ) ;
if ( ! V_44 ) {
struct V_345 * V_58 = F_2 ( V_12 ) ;
if ( V_340 && V_58 -> V_340 )
* V_340 = F_8 ( V_58 -> V_340 ) -
sizeof( T_2 ) ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_125 ( struct V_1 * V_2 , T_2 V_346 , void * V_347 )
{
struct V_151 V_348 ;
struct V_11 * V_12 ;
struct V_341 * V_207 ;
T_2 V_349 = 0 , V_350 , V_351 ,
V_352 = sizeof( T_2 ) , V_353 ;
int V_44 = 0 ;
if ( V_346 == 0 )
return - V_139 ;
V_350 = V_346 ;
V_348 . V_190 = sizeof( struct V_341 ) + 60 * 1024 ;
V_348 . V_155 = F_126 ( & V_2 -> V_66 -> V_67 ,
V_348 . V_190 ,
& V_348 . V_157 , V_354 ) ;
if ( ! V_348 . V_155 ) {
F_18 ( & V_2 -> V_66 -> V_67 ,
L_14 ) ;
return - V_355 ;
}
F_41 ( & V_2 -> V_200 ) ;
while ( V_350 ) {
V_351 = F_79 ( V_350 , ( T_2 ) 60 * 1024 ) ;
V_350 -= V_351 ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = V_348 . V_155 ;
V_353 = sizeof( struct V_341 ) + V_351 ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_342 , V_353 ,
V_12 , & V_348 ) ;
V_207 -> V_343 = F_76 ( V_356 ) ;
V_207 -> V_357 = F_76 ( V_352 ) ;
V_207 -> V_358 = F_76 ( V_351 ) ;
V_207 -> V_359 = F_76 ( V_351 ) ;
V_44 = F_56 ( V_2 ) ;
if ( ! V_44 ) {
struct V_345 * V_58 = V_348 . V_155 ;
memcpy ( V_347 + V_349 ,
V_58 -> V_360 ,
F_8 ( V_58 -> V_358 ) ) ;
} else {
F_18 ( & V_2 -> V_66 -> V_67 , L_15 ) ;
goto V_170;
}
V_349 += V_351 ;
V_352 += V_351 ;
}
V_170:
F_127 ( & V_2 -> V_66 -> V_67 , V_348 . V_190 ,
V_348 . V_155 , V_348 . V_157 ) ;
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_128 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_361 * V_207 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_362 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_44 = F_56 ( V_2 ) ;
if ( ! V_44 ) {
struct V_363 * V_58 = F_2 ( V_12 ) ;
F_129 ( V_2 -> V_364 , V_58 -> V_365 ,
sizeof( V_2 -> V_364 ) ) ;
F_129 ( V_2 -> V_366 , V_58 -> V_367 ,
sizeof( V_2 -> V_366 ) ) ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
static int F_130 ( struct V_1 * V_2 ,
struct V_368 * V_369 , int V_134 )
{
struct V_11 * V_12 ;
struct V_370 * V_207 ;
int V_44 = 0 , V_5 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_371 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_372 = F_76 ( V_134 ) ;
for ( V_5 = 0 ; V_5 < V_134 ; V_5 ++ ) {
V_207 -> V_369 [ V_5 ] . V_218 = F_76 ( V_369 [ V_5 ] . V_218 ) ;
V_207 -> V_369 [ V_5 ] . V_373 = 0 ;
V_207 -> V_369 [ V_5 ] . V_374 =
F_76 ( V_369 [ V_5 ] . V_374 ) ;
}
F_3 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_131 ( struct V_1 * V_2 , struct V_368 * V_369 ,
int V_134 )
{
int V_375 , V_5 = 0 ;
while ( V_134 ) {
V_375 = F_79 ( V_134 , 8 ) ;
F_130 ( V_2 , & V_369 [ V_5 ] , V_375 ) ;
V_5 += V_375 ;
V_134 -= V_375 ;
}
return 0 ;
}
int F_132 ( struct V_1 * V_2 , T_2 V_228 , T_3 * V_376 ,
T_2 V_134 , T_2 V_232 )
{
struct V_11 * V_12 ;
struct V_377 * V_207 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_378 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
V_207 -> V_290 = V_228 ;
V_207 -> V_379 = V_380 & F_133 ( V_2 ) ? 1 : 0 ;
V_207 -> V_381 = V_134 ;
memcpy ( V_207 -> V_382 , V_376 ,
V_207 -> V_381 * sizeof( V_376 [ 0 ] ) ) ;
V_44 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
static int F_134 ( struct V_1 * V_2 , T_2 V_27 , T_2 V_383 )
{
struct V_11 * V_12 ;
struct V_151 * V_179 = & V_2 -> V_384 ;
struct V_385 * V_207 = V_179 -> V_155 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
memset ( V_207 , 0 , sizeof( * V_207 ) ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_386 , sizeof( * V_207 ) ,
V_12 , V_179 ) ;
V_207 -> V_228 = F_76 ( V_2 -> V_223 ) ;
V_207 -> V_387 = F_76 ( V_27 ) ;
V_207 -> V_388 = ( V_383 == V_389 ) ? V_207 -> V_387 : 0 ;
if ( V_27 & V_390 ) {
struct V_391 * V_392 ;
int V_5 = 0 ;
V_207 -> V_387 |=
F_76 ( V_393 &
F_133 ( V_2 ) ) ;
V_207 -> V_394 = F_76 ( F_135 ( V_2 -> V_395 ) ) ;
F_136 (ha, adapter->netdev)
memcpy ( V_207 -> V_396 [ V_5 ++ ] . V_397 , V_392 -> V_32 , V_231 ) ;
}
V_44 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_137 ( struct V_1 * V_2 , T_2 V_27 , T_2 V_383 )
{
struct V_79 * V_67 = & V_2 -> V_66 -> V_67 ;
if ( ( V_27 & F_133 ( V_2 ) ) != V_27 ) {
F_17 ( V_67 , L_16 , V_27 ) ;
F_17 ( V_67 , L_17 ,
F_133 ( V_2 ) ) ;
}
V_27 &= F_133 ( V_2 ) ;
return F_134 ( V_2 , V_27 , V_383 ) ;
}
int F_138 ( struct V_1 * V_2 , T_2 V_398 , T_2 V_399 )
{
struct V_11 * V_12 ;
struct V_400 * V_207 ;
int V_44 ;
if ( ! F_1 ( V_2 , V_401 ,
V_49 ) )
return - V_237 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_401 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_211 . V_182 = 1 ;
V_207 -> V_402 = F_96 ( ( T_3 ) V_398 ) ;
V_207 -> V_403 = F_96 ( ( T_3 ) V_399 ) ;
V_44 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
if ( V_33 ( V_44 ) == V_404 )
return - V_405 ;
return V_44 ;
}
int F_139 ( struct V_1 * V_2 , T_2 * V_398 , T_2 * V_399 )
{
struct V_11 * V_12 ;
struct V_406 * V_207 ;
int V_44 ;
if ( ! F_1 ( V_2 , V_407 ,
V_49 ) )
return - V_237 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_407 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_44 = F_56 ( V_2 ) ;
if ( ! V_44 ) {
struct V_408 * V_58 =
F_2 ( V_12 ) ;
* V_398 = F_26 ( V_58 -> V_402 ) ;
* V_399 = F_26 ( V_58 -> V_403 ) ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_140 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_409 * V_207 ;
int V_44 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_410 ,
sizeof( * V_207 ) , V_12 , NULL ) ;
V_44 = F_63 ( V_2 ) ;
if ( ! V_44 ) {
struct V_411 * V_58 = F_2 ( V_12 ) ;
V_2 -> V_97 = F_8 ( V_58 -> V_412 ) ;
V_2 -> V_413 = F_8 ( V_58 -> V_413 ) ;
V_2 -> V_274 = F_8 ( V_58 -> V_274 ) ;
V_2 -> V_414 = F_8 ( V_58 -> V_415 ) & 0xFF ;
F_23 ( & V_2 -> V_66 -> V_67 ,
L_18 ,
V_2 -> V_413 , V_2 -> V_274 ) ;
}
F_90 ( & V_2 -> V_201 ) ;
return V_44 ;
}
int F_141 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_176 * V_207 ;
int V_44 ;
if ( F_70 ( V_2 ) ) {
F_6 ( V_416 ,
V_2 -> V_23 + V_417 ) ;
V_44 = F_67 ( V_2 ) ;
if ( V_44 )
F_18 ( & V_2 -> V_66 -> V_67 ,
L_19 ) ;
return V_44 ;
}
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_207 = F_2 ( V_12 ) ;
F_75 ( V_207 , V_49 ,
V_418 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_44 = F_63 ( V_2 ) ;
F_90 ( & V_2 -> V_201 ) ;
return V_44 ;
}
int F_142 ( struct V_1 * V_2 , T_1 * V_419 ,
T_2 V_420 , T_3 V_421 , const T_1 * V_422 )
{
struct V_11 * V_12 ;
struct V_423 * V_207 ;
int V_44 ;
if ( ! ( F_133 ( V_2 ) & V_424 ) )
return 0 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_53 ,
V_425 , sizeof( * V_207 ) , V_12 , NULL ) ;
V_207 -> V_228 = F_76 ( V_2 -> V_223 ) ;
V_207 -> V_426 = F_96 ( V_420 ) ;
V_207 -> V_427 = F_96 ( F_105 ( V_421 ) - 1 ) ;
if ( ! F_20 ( V_2 ) )
V_207 -> V_211 . V_182 = 1 ;
memcpy ( V_207 -> V_428 , V_419 , V_421 ) ;
memcpy ( V_207 -> V_429 , V_422 , V_430 ) ;
F_77 ( V_207 -> V_429 , sizeof( V_207 -> V_429 ) ) ;
V_44 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_143 ( struct V_1 * V_2 , T_1 V_97 ,
T_1 V_431 , T_1 V_432 , T_1 V_433 )
{
struct V_11 * V_12 ;
struct V_434 * V_207 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_435 ,
sizeof( * V_207 ) , V_12 , NULL ) ;
V_207 -> V_97 = V_97 ;
V_207 -> V_436 = V_433 ;
V_207 -> V_437 = V_431 ;
V_207 -> V_438 = V_432 ;
V_44 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_144 ( struct V_1 * V_2 , T_1 V_97 , T_2 * V_433 )
{
struct V_11 * V_12 ;
struct V_439 * V_207 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_440 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_97 = V_97 ;
V_44 = F_56 ( V_2 ) ;
if ( ! V_44 ) {
struct V_441 * V_58 =
F_2 ( V_12 ) ;
* V_433 = V_58 -> V_436 ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_145 ( struct V_1 * V_2 ,
T_1 V_442 , T_1 * V_443 )
{
struct V_151 V_444 ;
struct V_11 * V_12 ;
struct V_445 * V_207 ;
int V_44 ;
if ( V_442 > V_446 )
return - V_447 ;
V_444 . V_190 = sizeof( struct V_448 ) ;
V_444 . V_155 = F_126 ( & V_2 -> V_66 -> V_67 , V_444 . V_190 , & V_444 . V_157 ,
V_354 ) ;
if ( ! V_444 . V_155 ) {
F_18 ( & V_2 -> V_66 -> V_67 , L_20 ) ;
return - V_355 ;
}
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = V_444 . V_155 ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_449 ,
V_444 . V_190 , V_12 , & V_444 ) ;
V_207 -> V_450 = F_76 ( V_2 -> V_81 ) ;
V_207 -> V_442 = F_76 ( V_442 ) ;
V_44 = F_56 ( V_2 ) ;
if ( ! V_44 ) {
struct V_448 * V_58 = V_444 . V_155 ;
memcpy ( V_443 , V_58 -> V_451 , V_452 ) ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
F_127 ( & V_2 -> V_66 -> V_67 , V_444 . V_190 , V_444 . V_155 , V_444 . V_157 ) ;
return V_44 ;
}
int F_146 ( struct V_1 * V_2 , struct V_151 * V_444 ,
T_2 V_453 , T_2 V_454 ,
const char * V_455 , T_2 * V_456 ,
T_1 * V_457 , T_1 * V_458 )
{
struct V_11 * V_12 ;
struct V_459 * V_207 ;
struct V_460 * V_58 ;
void * V_245 = NULL ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_2 -> V_50 = 0 ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_461;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_48 ,
sizeof( struct V_459 ) , V_12 ,
NULL ) ;
V_245 = & V_207 -> V_215 ;
F_97 ( struct V_462 ,
V_463 , V_245 , V_453 ) ;
if ( V_453 == 0 )
F_97 ( struct V_462 ,
V_464 , V_245 , 1 ) ;
else
F_97 ( struct V_462 ,
V_464 , V_245 , 0 ) ;
F_77 ( V_245 , sizeof( V_207 -> V_215 ) ) ;
V_207 -> V_465 = F_76 ( V_454 ) ;
F_129 ( V_207 -> V_466 , V_455 , sizeof( V_207 -> V_466 ) ) ;
V_207 -> V_467 = F_76 ( 1 ) ;
V_207 -> V_346 = F_76 ( V_453 ) ;
V_207 -> V_468 = F_76 ( ( V_444 -> V_157 +
sizeof( struct V_459 ) )
& 0xFFFFFFFF ) ;
V_207 -> V_469 = F_76 ( F_64 ( V_444 -> V_157 +
sizeof( struct V_459 ) ) ) ;
F_3 ( V_2 ) ;
F_43 ( & V_2 -> V_200 ) ;
if ( ! F_147 ( & V_2 -> V_47 ,
F_148 ( 60000 ) ) )
V_44 = - V_173 ;
else
V_44 = V_2 -> V_50 ;
V_58 = F_2 ( V_12 ) ;
if ( ! V_44 ) {
* V_456 = F_8 ( V_58 -> V_470 ) ;
* V_457 = V_58 -> V_457 ;
} else {
* V_458 = V_58 -> V_471 ;
}
return V_44 ;
V_461:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_149 ( struct V_1 * V_2 )
{
T_1 V_451 [ V_452 ] ;
int V_44 ;
V_44 = F_145 ( V_2 , V_472 ,
V_451 ) ;
if ( ! V_44 ) {
switch ( V_2 -> V_70 . V_473 ) {
case V_474 :
V_2 -> V_70 . V_475 =
V_451 [ V_476 ] ;
break;
case V_477 :
V_2 -> V_70 . V_475 =
V_451 [ V_478 ] ;
break;
default:
V_2 -> V_70 . V_475 = 0 ;
break;
}
}
return V_44 ;
}
int F_150 ( struct V_1 * V_2 )
{
T_1 V_451 [ V_452 ] ;
int V_44 ;
V_44 = F_145 ( V_2 , V_472 ,
V_451 ) ;
if ( ! V_44 ) {
F_129 ( V_2 -> V_70 . V_479 , V_451 +
V_480 , V_481 - 1 ) ;
F_129 ( V_2 -> V_70 . V_482 ,
V_451 + V_483 ,
V_481 - 1 ) ;
}
return V_44 ;
}
int F_151 ( struct V_1 * V_2 , const char * V_455 )
{
struct V_484 * V_207 ;
struct V_11 * V_12 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_485 ,
sizeof( * V_207 ) , V_12 , NULL ) ;
F_129 ( V_207 -> V_466 , V_455 , sizeof( V_207 -> V_466 ) ) ;
V_44 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_152 ( struct V_1 * V_2 , struct V_151 * V_444 ,
T_2 V_453 , T_2 V_454 , const char * V_455 ,
T_2 * V_486 , T_2 * V_464 , T_1 * V_458 )
{
struct V_11 * V_12 ;
struct V_487 * V_207 ;
struct V_488 * V_58 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_461;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_489 ,
sizeof( struct V_487 ) , V_12 ,
NULL ) ;
V_207 -> V_490 = F_76 ( V_453 ) ;
V_207 -> V_491 = F_76 ( V_454 ) ;
strcpy ( V_207 -> V_466 , V_455 ) ;
V_207 -> V_467 = F_76 ( 1 ) ;
V_207 -> V_346 = F_76 ( V_453 ) ;
V_207 -> V_468 = F_76 ( ( V_444 -> V_157 & 0xFFFFFFFF ) ) ;
V_207 -> V_469 = F_76 ( F_64 ( V_444 -> V_157 ) ) ;
V_44 = F_56 ( V_2 ) ;
V_58 = F_2 ( V_12 ) ;
if ( ! V_44 ) {
* V_486 = F_8 ( V_58 -> V_492 ) ;
* V_464 = F_8 ( V_58 -> V_464 ) ;
} else {
* V_458 = V_58 -> V_471 ;
}
V_461:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_153 ( struct V_1 * V_2 , struct V_151 * V_444 ,
T_2 V_493 , T_2 V_494 , T_2 V_495 ,
T_2 V_351 )
{
struct V_11 * V_12 ;
struct F_153 * V_207 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_2 -> V_50 = 0 ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_461;
}
V_207 = V_444 -> V_155 ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_39 , V_444 -> V_190 , V_12 ,
V_444 ) ;
V_207 -> V_321 . V_496 = F_76 ( V_493 ) ;
if ( V_493 == V_497 )
V_207 -> V_321 . V_349 = F_76 ( V_495 ) ;
V_207 -> V_321 . V_498 = F_76 ( V_494 ) ;
V_207 -> V_321 . V_499 = F_76 ( V_351 ) ;
F_3 ( V_2 ) ;
F_43 ( & V_2 -> V_200 ) ;
if ( ! F_147 ( & V_2 -> V_47 ,
F_148 ( 40000 ) ) )
V_44 = - V_173 ;
else
V_44 = V_2 -> V_50 ;
return V_44 ;
V_461:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_154 ( struct V_1 * V_2 , T_1 * V_500 ,
T_3 V_501 , T_2 V_495 , T_2 V_502 )
{
struct V_503 * V_207 ;
struct V_11 * V_12 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_504 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_321 . V_496 = F_76 ( V_501 ) ;
if ( V_501 == V_497 )
V_207 -> V_321 . V_349 = F_76 ( V_495 + V_502 ) ;
else
V_207 -> V_321 . V_349 = F_76 ( V_502 ) ;
V_207 -> V_321 . V_498 = F_76 ( V_505 ) ;
V_207 -> V_321 . V_499 = F_76 ( 0x4 ) ;
V_44 = F_56 ( V_2 ) ;
if ( ! V_44 )
memcpy ( V_500 , V_207 -> V_506 , 4 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_155 ( struct V_1 * V_2 , T_1 * V_230 ,
struct V_151 * V_318 )
{
struct V_11 * V_12 ;
struct V_507 * V_207 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = V_318 -> V_155 ;
F_75 ( & V_207 -> V_211 , V_53 ,
V_508 , sizeof( * V_207 ) ,
V_12 , V_318 ) ;
memcpy ( V_207 -> V_509 , V_230 , V_231 ) ;
V_44 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_156 ( struct V_1 * V_2 , T_1 V_97 ,
T_1 V_510 , T_1 V_511 )
{
struct V_11 * V_12 ;
struct V_512 * V_207 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_46 ,
V_513 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_514 = V_97 ;
V_207 -> V_515 = V_97 ;
V_207 -> V_510 = V_510 ;
V_207 -> V_516 = V_511 ;
V_44 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_157 ( struct V_1 * V_2 , T_2 V_97 ,
T_2 V_510 , T_2 V_517 , T_2 V_518 ,
T_5 V_519 )
{
struct V_11 * V_12 ;
struct V_520 * V_207 ;
struct V_521 * V_58 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_46 ,
V_45 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_211 . V_169 = F_76 ( 15 ) ;
V_207 -> V_519 = F_158 ( V_519 ) ;
V_207 -> V_514 = F_76 ( V_97 ) ;
V_207 -> V_515 = F_76 ( V_97 ) ;
V_207 -> V_517 = F_76 ( V_517 ) ;
V_207 -> V_518 = F_76 ( V_518 ) ;
V_207 -> V_510 = F_76 ( V_510 ) ;
F_3 ( V_2 ) ;
F_43 ( & V_2 -> V_200 ) ;
F_159 ( & V_2 -> V_47 ) ;
V_58 = F_2 ( V_12 ) ;
V_44 = F_8 ( V_58 -> V_44 ) ;
return V_44 ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_160 ( struct V_1 * V_2 , T_5 V_519 ,
T_2 V_522 , struct V_151 * V_444 )
{
struct V_11 * V_12 ;
struct V_523 * V_207 ;
int V_44 ;
int V_5 , V_524 = 0 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = V_444 -> V_155 ;
F_75 ( & V_207 -> V_211 , V_46 ,
V_525 , V_444 -> V_190 , V_12 ,
V_444 ) ;
V_207 -> V_519 = F_158 ( V_519 ) ;
V_207 -> V_526 = F_76 ( V_522 ) ;
for ( V_5 = 0 ; V_5 < V_522 ; V_5 ++ ) {
V_207 -> V_527 [ V_5 ] = ( T_1 ) ( V_519 >> ( V_524 * 8 ) ) ;
V_524 ++ ;
if ( V_524 > 7 )
V_524 = 0 ;
}
V_44 = F_56 ( V_2 ) ;
if ( ! V_44 ) {
struct V_528 * V_58 ;
V_58 = V_444 -> V_155 ;
if ( ( memcmp ( V_58 -> V_529 , V_207 -> V_527 , V_522 ) != 0 ) ||
V_58 -> V_530 ) {
V_44 = - 1 ;
}
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_161 ( struct V_1 * V_2 ,
struct V_151 * V_318 )
{
struct V_11 * V_12 ;
struct V_531 * V_207 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = V_318 -> V_155 ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_532 , sizeof( * V_207 ) , V_12 ,
V_318 ) ;
V_44 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_162 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_533 * V_207 ;
struct V_151 V_444 ;
int V_44 ;
if ( ! F_1 ( V_2 , V_534 ,
V_49 ) )
return - V_237 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_444 . V_190 = sizeof( struct V_533 ) ;
V_444 . V_155 = F_126 ( & V_2 -> V_66 -> V_67 , V_444 . V_190 , & V_444 . V_157 ,
V_354 ) ;
if ( ! V_444 . V_155 ) {
F_18 ( & V_2 -> V_66 -> V_67 , L_21 ) ;
V_44 = - V_355 ;
goto V_170;
}
V_207 = V_444 . V_155 ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_534 , sizeof( * V_207 ) ,
V_12 , & V_444 ) ;
V_44 = F_56 ( V_2 ) ;
if ( ! V_44 ) {
struct V_535 * V_536 =
V_444 . V_155 + sizeof( struct V_176 ) ;
V_2 -> V_70 . V_537 = F_26 ( V_536 -> V_537 ) ;
V_2 -> V_70 . V_473 =
F_26 ( V_536 -> V_473 ) ;
V_2 -> V_70 . V_538 =
F_26 ( V_536 -> V_538 ) ;
V_2 -> V_70 . V_539 =
F_26 ( V_536 -> V_539 ) ;
V_2 -> V_70 . V_540 =
F_8 ( V_536 -> V_540 ) ;
if ( F_119 ( V_2 ) ) {
V_2 -> V_70 . V_539 =
V_541 |
V_542 ;
}
}
F_127 ( & V_2 -> V_66 -> V_67 , V_444 . V_190 , V_444 . V_155 , V_444 . V_157 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
static int F_163 ( struct V_1 * V_2 , T_2 V_543 , T_2 V_232 )
{
struct V_11 * V_12 ;
struct V_544 * V_207 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_545 , sizeof( * V_207 ) , V_12 , NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
V_207 -> V_546 = F_76 ( V_547 ) ;
V_207 -> V_548 = F_76 ( V_543 ) ;
V_44 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_164 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_549 * V_207 ;
struct V_550 * V_58 ;
int V_44 ;
int V_353 = F_165 ( sizeof( * V_207 ) , sizeof( * V_58 ) ) ;
struct V_551 * V_552 ;
struct V_151 V_553 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
memset ( & V_553 , 0 , sizeof( struct V_151 ) ) ;
V_553 . V_190 = sizeof( struct V_550 ) ;
V_553 . V_155 = F_126 ( & V_2 -> V_66 -> V_67 ,
V_553 . V_190 ,
& V_553 . V_157 , V_354 ) ;
if ( ! V_553 . V_155 ) {
F_18 ( & V_2 -> V_66 -> V_67 , L_22 ) ;
V_44 = - V_355 ;
goto V_170;
}
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = V_553 . V_155 ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_554 , V_353 ,
V_12 , & V_553 ) ;
V_44 = F_63 ( V_2 ) ;
if ( ! V_44 ) {
V_552 = V_553 . V_155 + sizeof( struct V_29 ) ;
V_2 -> V_81 = V_552 -> V_555 . V_556 ;
}
V_170:
F_90 ( & V_2 -> V_201 ) ;
if ( V_553 . V_155 )
F_127 ( & V_2 -> V_66 -> V_67 , V_553 . V_190 ,
V_553 . V_155 , V_553 . V_157 ) ;
return V_44 ;
}
int F_166 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_557 * V_207 ;
int V_44 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_558 ,
sizeof( * V_207 ) , V_12 , NULL ) ;
V_207 -> V_559 = F_76 ( V_560 |
V_561 ) ;
V_207 -> V_308 = F_76 ( V_561 ) ;
V_44 = F_63 ( V_2 ) ;
if ( ! V_44 ) {
struct V_562 * V_58 = F_2 ( V_12 ) ;
V_2 -> V_563 = F_8 ( V_58 -> V_308 ) &
V_561 ;
if ( ! V_2 -> V_563 )
F_17 ( & V_2 -> V_66 -> V_67 ,
L_23 ) ;
}
V_170:
F_90 ( & V_2 -> V_201 ) ;
return V_44 ;
}
int F_167 ( struct V_1 * V_2 , T_2 * V_564 ,
T_2 V_232 )
{
struct V_11 * V_12 ;
struct V_565 * V_207 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_566 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
V_44 = F_56 ( V_2 ) ;
if ( ! V_44 ) {
struct V_567 * V_58 =
F_2 ( V_12 ) ;
* V_564 = F_8 ( V_58 -> V_568 ) ;
if ( F_20 ( V_2 ) && F_168 ( V_2 ) &&
F_169 ( V_2 ) )
* V_564 = V_569 ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_170 ( struct V_1 * V_2 , T_2 V_570 ,
T_2 V_232 )
{
struct V_11 * V_12 ;
struct V_571 * V_207 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_572 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
if ( F_70 ( V_2 ) )
V_207 -> V_573 = F_76 ( V_570 ) ;
else
V_207 -> V_570 = F_76 ( V_570 ) ;
V_44 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_171 ( struct V_1 * V_2 , T_1 * V_230 ,
bool * V_574 , T_2 * V_224 , T_2 V_223 ,
T_1 V_232 )
{
struct V_11 * V_12 ;
struct V_575 * V_207 ;
int V_44 ;
int V_576 ;
struct V_151 V_577 ;
int V_5 ;
memset ( & V_577 , 0 , sizeof( struct V_151 ) ) ;
V_577 . V_190 = sizeof( struct V_578 ) ;
V_577 . V_155 = F_126 ( & V_2 -> V_66 -> V_67 ,
V_577 . V_190 ,
& V_577 . V_157 ,
V_354 ) ;
if ( ! V_577 . V_155 ) {
F_18 ( & V_2 -> V_66 -> V_67 ,
L_24 ) ;
return - V_355 ;
}
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_144;
}
V_207 = V_577 . V_155 ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_579 ,
V_577 . V_190 , V_12 , & V_577 ) ;
V_207 -> V_211 . V_232 = V_232 ;
V_207 -> V_580 = V_227 ;
if ( * V_574 ) {
V_207 -> V_581 = F_76 ( * V_224 ) ;
V_207 -> V_582 = F_96 ( V_223 ) ;
V_207 -> V_583 = 0 ;
} else {
V_207 -> V_583 = 1 ;
}
V_44 = F_56 ( V_2 ) ;
if ( ! V_44 ) {
struct V_578 * V_58 =
V_577 . V_155 ;
if ( * V_574 ) {
memcpy ( V_230 , V_58 -> V_584 . V_585 . V_586 ,
V_231 ) ;
goto V_144;
}
V_576 = V_58 -> V_587 + V_58 -> V_588 ;
for ( V_5 = 0 ; V_5 < V_576 ; V_5 ++ ) {
struct V_589 * V_590 ;
T_3 V_591 ;
T_2 V_581 ;
V_590 = & V_58 -> V_592 [ V_5 ] ;
V_591 = F_26 ( V_590 -> V_591 ) ;
if ( V_591 == sizeof( T_2 ) ) {
* V_574 = true ;
V_581 = V_590 -> V_585 . V_593 . V_581 ;
* V_224 = F_8 ( V_581 ) ;
goto V_144;
}
}
* V_574 = false ;
memcpy ( V_230 , V_58 -> V_592 [ 0 ] . V_585 . V_586 ,
V_231 ) ;
}
V_144:
F_43 ( & V_2 -> V_200 ) ;
F_127 ( & V_2 -> V_66 -> V_67 , V_577 . V_190 ,
V_577 . V_155 , V_577 . V_157 ) ;
return V_44 ;
}
int F_172 ( struct V_1 * V_2 , T_2 V_594 ,
T_1 * V_230 , T_2 V_223 , bool V_595 , T_2 V_232 )
{
if ( ! V_595 )
F_171 ( V_2 , V_230 , & V_595 , & V_594 ,
V_223 , V_232 ) ;
if ( F_20 ( V_2 ) )
return F_100 ( V_2 , V_230 , false ,
V_223 , V_594 ) ;
else
return F_171 ( V_2 , V_230 , & V_595 ,
& V_594 ,
V_223 , V_232 ) ;
}
int F_173 ( struct V_1 * V_2 , T_1 * V_230 )
{
int V_44 ;
bool V_596 = false ;
F_174 ( V_230 ) ;
if ( F_20 ( V_2 ) ) {
if ( F_169 ( V_2 ) )
V_44 = F_100 ( V_2 , V_230 , true , 0 ,
0 ) ;
else
V_44 = F_100 ( V_2 , V_230 , false ,
V_2 -> V_223 , 0 ) ;
} else {
V_44 = F_171 ( V_2 , V_230 , & V_596 ,
NULL , V_2 -> V_223 , 0 ) ;
}
return V_44 ;
}
int F_175 ( struct V_1 * V_2 , T_1 * V_597 ,
T_1 V_576 , T_2 V_232 )
{
struct V_11 * V_12 ;
struct V_598 * V_207 ;
int V_44 ;
struct V_151 V_444 ;
memset ( & V_444 , 0 , sizeof( struct V_151 ) ) ;
V_444 . V_190 = sizeof( struct V_598 ) ;
V_444 . V_155 = F_126 ( & V_2 -> V_66 -> V_67 , V_444 . V_190 , & V_444 . V_157 ,
V_599 ) ;
if ( ! V_444 . V_155 )
return - V_355 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = V_444 . V_155 ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_600 , sizeof( * V_207 ) ,
V_12 , & V_444 ) ;
V_207 -> V_211 . V_232 = V_232 ;
V_207 -> V_576 = V_576 ;
if ( V_576 )
memcpy ( V_207 -> V_230 , V_597 , V_231 * V_576 ) ;
V_44 = F_56 ( V_2 ) ;
V_170:
F_127 ( & V_2 -> V_66 -> V_67 , V_444 . V_190 , V_444 . V_155 , V_444 . V_157 ) ;
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_176 ( struct V_1 * V_2 , T_1 * V_230 , int V_228 , T_2 V_238 )
{
bool V_601 = false ;
T_1 V_602 [ V_231 ] ;
T_2 V_224 ;
int V_44 ;
V_44 = F_171 ( V_2 , V_602 , & V_601 ,
& V_224 , V_228 , V_238 ) ;
if ( ! V_44 && V_601 )
F_102 ( V_2 , V_228 , V_224 , V_238 ) ;
return F_175 ( V_2 , V_230 , V_230 ? 1 : 0 , V_238 ) ;
}
int F_177 ( struct V_1 * V_2 , T_3 V_101 ,
T_2 V_232 , T_3 V_603 , T_3 V_604 , T_1 V_605 )
{
struct V_11 * V_12 ;
struct V_606 * V_207 ;
void * V_245 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
V_245 = & V_207 -> V_215 ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_607 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
F_97 ( struct V_608 , V_290 , V_245 , V_603 ) ;
if ( V_101 ) {
F_97 ( struct V_608 , V_609 , V_245 , 1 ) ;
F_97 ( struct V_608 , V_101 , V_245 , V_101 ) ;
}
if ( ! F_20 ( V_2 ) && V_604 ) {
F_97 ( struct V_608 , V_290 ,
V_245 , V_2 -> V_81 ) ;
F_97 ( struct V_608 , V_610 , V_245 , 1 ) ;
F_97 ( struct V_608 , V_611 ,
V_245 , V_604 ) ;
}
if ( ! F_20 ( V_2 ) && V_605 ) {
F_97 ( struct V_608 , V_612 ,
V_245 , V_605 ) ;
F_97 ( struct V_608 , V_613 ,
V_245 , V_605 ) ;
}
F_77 ( V_207 -> V_215 , sizeof( V_207 -> V_215 ) ) ;
V_44 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_178 ( struct V_1 * V_2 , T_3 * V_101 ,
T_2 V_232 , T_3 V_603 , T_1 * V_614 , bool * V_605 )
{
struct V_11 * V_12 ;
struct V_615 * V_207 ;
void * V_245 ;
int V_44 ;
T_3 V_616 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
V_245 = & V_207 -> V_215 ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_617 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
F_97 ( struct V_618 , V_290 ,
V_245 , V_603 ) ;
F_97 ( struct V_618 , V_609 , V_245 , 1 ) ;
if ( ! F_20 ( V_2 ) && V_614 ) {
F_97 ( struct V_618 , V_290 ,
V_245 , V_2 -> V_81 ) ;
F_97 ( struct V_618 , V_610 , V_245 , 1 ) ;
}
F_77 ( V_207 -> V_215 , sizeof( V_207 -> V_215 ) ) ;
V_44 = F_56 ( V_2 ) ;
if ( ! V_44 ) {
struct V_619 * V_58 =
F_2 ( V_12 ) ;
F_16 ( & V_58 -> V_215 , sizeof( V_58 -> V_215 ) ) ;
V_616 = F_179 ( struct V_620 ,
V_101 , & V_58 -> V_215 ) ;
if ( V_101 )
* V_101 = F_26 ( V_616 ) ;
if ( V_614 )
* V_614 = F_179 ( struct V_620 ,
V_611 , & V_58 -> V_215 ) ;
if ( V_605 )
* V_605 =
F_179 ( struct V_620 ,
V_605 , & V_58 -> V_215 ) ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
static bool F_180 ( struct V_1 * V_2 )
{
struct V_621 * V_66 = V_2 -> V_66 ;
if ( F_71 ( V_2 ) )
return true ;
switch ( V_66 -> V_622 ) {
case V_623 :
case V_624 :
case V_625 :
case V_626 :
return true ;
default:
return false ;
}
}
int F_181 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_627 * V_207 ;
int V_44 = 0 ;
struct V_151 V_444 ;
if ( ! F_1 ( V_2 , V_508 ,
V_53 ) )
return - V_237 ;
if ( F_180 ( V_2 ) )
return V_44 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
memset ( & V_444 , 0 , sizeof( struct V_151 ) ) ;
V_444 . V_190 = sizeof( struct V_628 ) ;
V_444 . V_155 = F_126 ( & V_2 -> V_66 -> V_67 , V_444 . V_190 , & V_444 . V_157 ,
V_354 ) ;
if ( ! V_444 . V_155 ) {
F_18 ( & V_2 -> V_66 -> V_67 , L_22 ) ;
V_44 = - V_355 ;
goto V_170;
}
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = V_444 . V_155 ;
F_75 ( & V_207 -> V_211 , V_53 ,
V_508 ,
sizeof( * V_207 ) , V_12 , & V_444 ) ;
V_207 -> V_211 . V_182 = 1 ;
V_207 -> V_629 = V_630 ;
V_44 = F_63 ( V_2 ) ;
if ( ! V_44 ) {
struct V_628 * V_58 ;
V_58 = (struct V_628 * ) V_444 . V_155 ;
V_2 -> V_631 = V_58 -> V_632 ;
if ( V_2 -> V_631 & V_633 )
V_2 -> V_634 = true ;
}
V_170:
F_90 ( & V_2 -> V_201 ) ;
if ( V_444 . V_155 )
F_127 ( & V_2 -> V_66 -> V_67 , V_444 . V_190 , V_444 . V_155 ,
V_444 . V_157 ) ;
return V_44 ;
}
int F_182 ( struct V_1 * V_2 , T_2 V_635 )
{
struct V_151 V_636 ;
struct V_637 * V_638 ;
int V_44 ;
int V_5 , V_524 ;
memset ( & V_636 , 0 , sizeof( struct V_151 ) ) ;
V_636 . V_190 = sizeof( struct V_639 ) ;
V_636 . V_155 = F_126 ( & V_2 -> V_66 -> V_67 ,
V_636 . V_190 , & V_636 . V_157 ,
V_354 ) ;
if ( ! V_636 . V_155 )
return - V_355 ;
V_44 = F_183 ( V_2 , & V_636 ) ;
if ( V_44 )
goto V_170;
V_638 = (struct V_637 * )
( V_636 . V_155 + sizeof( struct V_29 ) ) ;
for ( V_5 = 0 ; V_5 < F_8 ( V_638 -> V_640 ) ; V_5 ++ ) {
T_2 V_641 = F_8 ( V_638 -> V_642 [ V_5 ] . V_641 ) ;
for ( V_524 = 0 ; V_524 < V_641 ; V_524 ++ ) {
if ( V_638 -> V_642 [ V_5 ] . V_643 [ V_524 ] . V_614 == V_644 )
V_638 -> V_642 [ V_5 ] . V_643 [ V_524 ] . V_645 =
F_76 ( V_635 ) ;
}
}
V_44 = F_184 ( V_2 , & V_636 , V_638 ) ;
V_170:
F_127 ( & V_2 -> V_66 -> V_67 , V_636 . V_190 , V_636 . V_155 ,
V_636 . V_157 ) ;
return V_44 ;
}
int F_185 ( struct V_1 * V_2 )
{
struct V_151 V_636 ;
struct V_637 * V_638 ;
int V_44 , V_524 ;
int V_635 = 0 ;
memset ( & V_636 , 0 , sizeof( struct V_151 ) ) ;
V_636 . V_190 = sizeof( struct V_639 ) ;
V_636 . V_155 = F_126 ( & V_2 -> V_66 -> V_67 ,
V_636 . V_190 , & V_636 . V_157 ,
V_354 ) ;
if ( ! V_636 . V_155 ) {
F_18 ( & V_2 -> V_66 -> V_67 , L_25 ,
V_646 ) ;
goto V_170;
}
V_44 = F_183 ( V_2 , & V_636 ) ;
if ( ! V_44 ) {
V_638 = (struct V_637 * ) ( V_636 . V_155 +
sizeof( struct V_29 ) ) ;
for ( V_524 = 0 ; V_524 < F_8 ( V_638 -> V_642 [ 0 ] . V_641 ) ; V_524 ++ ) {
if ( V_638 -> V_642 [ 0 ] . V_643 [ V_524 ] . V_614 == V_644 )
V_635 = V_638 -> V_642 [ 0 ] . V_643 [ V_524 ] . V_645 ;
}
}
F_127 ( & V_2 -> V_66 -> V_67 , V_636 . V_190 , V_636 . V_155 ,
V_636 . V_157 ) ;
V_170:
return V_635 ;
}
int F_183 ( struct V_1 * V_2 ,
struct V_151 * V_444 )
{
struct V_11 * V_12 ;
struct V_647 * V_207 ;
int V_44 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = V_444 -> V_155 ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_648 ,
V_444 -> V_190 , V_12 , V_444 ) ;
V_207 -> V_649 = F_76 ( 1 ) ;
V_44 = F_63 ( V_2 ) ;
V_170:
F_90 ( & V_2 -> V_201 ) ;
return V_44 ;
}
int F_184 ( struct V_1 * V_2 ,
struct V_151 * V_444 ,
struct V_637 * V_650 )
{
struct V_11 * V_12 ;
struct V_651 * V_207 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = V_444 -> V_155 ;
memcpy ( & V_207 -> V_652 , V_650 , sizeof( struct V_637 ) ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_653 ,
V_444 -> V_190 , V_12 , V_444 ) ;
V_44 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_186 ( struct V_1 * V_2 )
{
struct V_654 * V_207 ;
struct V_11 * V_12 ;
int V_44 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_655 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
if ( ! F_20 ( V_2 ) )
V_207 -> V_211 . V_182 = 1 ;
V_44 = F_63 ( V_2 ) ;
if ( ! V_44 ) {
struct V_656 * V_58 = F_2 ( V_12 ) ;
V_2 -> V_82 = V_58 -> V_82 [ V_2 -> V_81 ] ;
} else {
V_2 -> V_82 = V_2 -> V_81 + '0' ;
}
F_90 ( & V_2 -> V_201 ) ;
return V_44 ;
}
static struct V_657 * F_187 ( T_1 * V_347 , T_2 V_658 ,
int V_659 )
{
struct V_660 * V_211 = (struct V_660 * ) V_347 ;
struct V_657 * V_661 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_658 ; V_5 ++ ) {
if ( V_211 -> V_659 == V_662 ||
V_211 -> V_659 == V_663 ) {
V_661 = (struct V_657 * ) V_211 ;
if ( V_659 == V_664 ||
( V_659 == V_665 &&
V_661 -> V_27 & ( 1 << V_666 ) ) )
return V_661 ;
}
V_211 -> V_667 = V_211 -> V_667 ? : V_668 ;
V_211 = ( void * ) V_211 + V_211 -> V_667 ;
}
return NULL ;
}
static struct V_657 * F_188 ( T_1 * V_347 , T_2 V_658 )
{
return F_187 ( V_347 , V_658 , V_665 ) ;
}
static struct V_657 * F_189 ( T_1 * V_347 , T_2 V_658 )
{
return F_187 ( V_347 , V_658 , V_664 ) ;
}
static struct V_669 * F_190 ( T_1 V_670 , T_1 * V_347 ,
T_2 V_658 )
{
struct V_660 * V_211 = (struct V_660 * ) V_347 ;
struct V_669 * V_671 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_658 ; V_5 ++ ) {
if ( ( V_211 -> V_659 == V_672 ||
V_211 -> V_659 == V_673 ) ) {
V_671 = (struct V_669 * ) V_211 ;
if ( V_671 -> V_674 == V_670 )
return V_671 ;
}
V_211 -> V_667 = V_211 -> V_667 ? : V_668 ;
V_211 = ( void * ) V_211 + V_211 -> V_667 ;
}
return NULL ;
}
static struct V_675 * F_191 ( T_1 * V_347 , T_2 V_658 )
{
struct V_660 * V_211 = (struct V_660 * ) V_347 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_658 ; V_5 ++ ) {
if ( V_211 -> V_659 == V_676 )
return (struct V_675 * ) V_211 ;
V_211 -> V_667 = V_211 -> V_667 ? : V_668 ;
V_211 = ( void * ) V_211 + V_211 -> V_667 ;
}
return NULL ;
}
static void F_192 ( struct V_677 * V_678 ,
struct V_657 * V_679 )
{
V_678 -> V_680 = F_26 ( V_679 -> V_681 ) ;
V_678 -> V_682 = F_26 ( V_679 -> V_683 ) ;
V_678 -> V_684 = F_26 ( V_679 -> V_685 ) ;
V_678 -> V_686 = F_26 ( V_679 -> V_687 ) ;
V_678 -> V_688 = F_26 ( V_679 -> V_689 ) ;
V_678 -> V_690 = F_26 ( V_679 -> V_691 ) ;
V_678 -> V_692 = F_26 ( V_679 -> V_693 ) ;
V_678 -> V_694 = F_26 ( V_679 -> V_695 ) ;
V_678 -> V_696 = F_26 ( V_679 -> V_697 ) ;
V_678 -> V_698 = F_26 ( V_679 -> V_699 ) ;
V_678 -> V_700 = F_8 ( V_679 -> V_308 ) &
V_701 ;
}
int F_193 ( struct V_1 * V_2 , struct V_677 * V_678 )
{
struct V_11 * V_12 ;
struct V_702 * V_207 ;
int V_44 ;
struct V_151 V_444 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
memset ( & V_444 , 0 , sizeof( struct V_151 ) ) ;
V_444 . V_190 = sizeof( struct V_703 ) ;
V_444 . V_155 = F_126 ( & V_2 -> V_66 -> V_67 , V_444 . V_190 , & V_444 . V_157 ,
V_354 ) ;
if ( ! V_444 . V_155 ) {
F_18 ( & V_2 -> V_66 -> V_67 , L_21 ) ;
V_44 = - V_355 ;
goto V_170;
}
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = V_444 . V_155 ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_704 ,
V_444 . V_190 , V_12 , & V_444 ) ;
if ( F_194 ( V_2 ) )
V_207 -> V_211 . V_182 = 1 ;
V_44 = F_63 ( V_2 ) ;
if ( ! V_44 ) {
struct V_703 * V_58 = V_444 . V_155 ;
T_2 V_658 = F_8 ( V_58 -> V_658 ) ;
struct V_657 * V_679 ;
V_679 = F_189 ( V_58 -> V_705 , V_658 ) ;
if ( ! V_679 ) {
V_44 = - V_447 ;
goto V_170;
}
V_2 -> V_706 = V_679 -> V_674 ;
F_192 ( V_678 , V_679 ) ;
}
V_170:
F_90 ( & V_2 -> V_201 ) ;
if ( V_444 . V_155 )
F_127 ( & V_2 -> V_66 -> V_67 , V_444 . V_190 , V_444 . V_155 ,
V_444 . V_157 ) ;
return V_44 ;
}
int F_195 ( struct V_1 * V_2 ,
struct V_677 * V_678 , T_1 V_707 , T_1 V_232 )
{
struct V_708 * V_58 ;
struct V_709 * V_207 ;
struct V_657 * V_710 ;
struct V_669 * V_671 ;
struct V_675 * V_450 ;
struct V_657 * V_661 ;
struct V_11 V_12 = { 0 } ;
struct V_151 V_444 ;
T_3 V_658 ;
int V_44 ;
memset ( & V_444 , 0 , sizeof( struct V_151 ) ) ;
V_444 . V_190 = sizeof( struct V_708 ) ;
V_444 . V_155 = F_126 ( & V_2 -> V_66 -> V_67 , V_444 . V_190 , & V_444 . V_157 ,
V_354 ) ;
if ( ! V_444 . V_155 )
return - V_355 ;
V_207 = V_444 . V_155 ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_711 ,
V_444 . V_190 , & V_12 , & V_444 ) ;
V_207 -> V_211 . V_232 = V_232 ;
if ( ! F_70 ( V_2 ) )
V_207 -> V_211 . V_182 = 1 ;
V_207 -> type = V_712 ;
if ( V_707 == V_713 )
V_207 -> type |= V_714 ;
V_44 = F_92 ( V_2 , & V_12 ) ;
if ( V_44 )
goto V_170;
V_58 = V_444 . V_155 ;
V_658 = F_26 ( V_58 -> V_658 ) ;
V_671 = F_190 ( V_2 -> V_66 -> V_670 , V_58 -> V_705 ,
V_658 ) ;
if ( V_671 )
V_678 -> V_715 = F_26 ( V_671 -> V_716 ) ;
V_450 = F_191 ( V_58 -> V_705 , V_658 ) ;
if ( V_450 )
V_2 -> V_717 = V_450 -> V_717 ;
V_661 = F_189 ( V_58 -> V_705 , V_658 ) ;
if ( V_661 )
F_192 ( V_678 , V_661 ) ;
V_710 = F_188 ( V_58 -> V_705 , V_658 ) ;
if ( V_710 )
V_678 -> V_718 = V_710 -> V_308 ;
V_170:
if ( V_444 . V_155 )
F_127 ( & V_2 -> V_66 -> V_67 , V_444 . V_190 , V_444 . V_155 ,
V_444 . V_157 ) ;
return V_44 ;
}
static int F_196 ( struct V_1 * V_2 , void * V_679 ,
int V_190 , int V_216 , T_1 V_182 , T_1 V_232 )
{
struct V_719 * V_207 ;
struct V_11 V_12 = { 0 } ;
struct V_151 V_444 ;
int V_44 ;
memset ( & V_444 , 0 , sizeof( struct V_151 ) ) ;
V_444 . V_190 = sizeof( struct V_719 ) ;
V_444 . V_155 = F_126 ( & V_2 -> V_66 -> V_67 , V_444 . V_190 , & V_444 . V_157 ,
V_354 ) ;
if ( ! V_444 . V_155 )
return - V_355 ;
V_207 = V_444 . V_155 ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_720 , V_444 . V_190 ,
& V_12 , & V_444 ) ;
V_207 -> V_211 . V_182 = V_182 ;
V_207 -> V_211 . V_232 = V_232 ;
V_207 -> V_658 = F_76 ( V_216 ) ;
memcpy ( V_207 -> V_679 , V_679 , V_190 ) ;
V_44 = F_92 ( V_2 , & V_12 ) ;
if ( V_444 . V_155 )
F_127 ( & V_2 -> V_66 -> V_67 , V_444 . V_190 , V_444 . V_155 ,
V_444 . V_157 ) ;
return V_44 ;
}
static void F_197 ( struct V_657 * V_661 )
{
memset ( V_661 , 0 , sizeof( * V_661 ) ) ;
V_661 -> V_681 = 0xFFFF ;
V_661 -> V_699 = 0xFFFF ;
V_661 -> V_683 = 0xFFFF ;
V_661 -> V_685 = 0xFFFF ;
V_661 -> V_687 = 0xFFFF ;
V_661 -> V_691 = 0xFFFF ;
V_661 -> V_689 = 0xFFFF ;
V_661 -> V_721 = 0xFFFF ;
V_661 -> V_695 = 0xFFFF ;
V_661 -> V_722 = 0xFFFF ;
V_661 -> V_693 = 0xFFFF ;
V_661 -> V_697 = 0xFFFF ;
V_661 -> V_723 = 0xFF ;
V_661 -> V_724 = F_96 ( 0xF000 ) ;
V_661 -> V_725 = 0xFF ;
V_661 -> V_726 = 0x0F ;
V_661 -> V_727 = 0xFFFF ;
V_661 -> V_728 = 0xFFFF ;
V_661 -> V_729 = 0xFFFFFFFF ;
V_661 -> V_730 = 0xFFFFFFFF ;
}
static void F_198 ( struct V_669 * V_671 )
{
memset ( V_671 , 0 , sizeof( * V_671 ) ) ;
V_671 -> V_731 = 0xFF ;
V_671 -> V_732 = 0xFF ;
V_671 -> V_733 = 0xFF ;
V_671 -> V_716 = 0xFFFF ;
}
int F_199 ( struct V_1 * V_2 , T_2 V_734 , T_3 V_71 ,
T_1 V_232 )
{
struct V_657 V_735 ;
T_2 V_736 ;
T_3 V_182 = 0 ;
if ( F_116 ( V_2 ) )
return F_163 ( V_2 , V_734 / 10 , V_232 ) ;
F_197 ( & V_735 ) ;
V_735 . V_674 = V_2 -> V_706 ;
V_735 . V_737 = V_232 ;
V_735 . V_729 = 0 ;
if ( F_70 ( V_2 ) ) {
V_735 . V_211 . V_659 = V_662 ;
V_735 . V_211 . V_667 = V_668 ;
V_735 . V_27 = ( 1 << V_738 ) | ( 1 << V_739 ) |
( 1 << V_740 ) ;
V_735 . V_730 = F_76 ( V_734 / 10 ) ;
} else {
V_182 = 1 ;
V_735 . V_211 . V_659 = V_663 ;
V_735 . V_211 . V_667 = V_741 ;
V_735 . V_27 = ( 1 << V_739 ) | ( 1 << V_740 ) ;
V_736 = V_734 ? ( V_734 * 100 ) / V_71 : 100 ;
V_735 . V_730 = F_76 ( V_736 ) ;
}
return F_196 ( V_2 , & V_735 ,
V_735 . V_211 . V_667 ,
1 , V_182 , V_232 ) ;
}
static void F_200 ( struct V_1 * V_2 ,
struct V_677 V_742 ,
T_3 V_716 , T_3 V_743 ,
struct V_657 * V_744 )
{
T_2 V_718 = V_742 . V_718 ;
struct V_677 V_745 = { 0 } ;
F_195 ( V_2 , & V_745 , V_713 , 0 ) ;
if ( V_745 . V_718 & V_424 ) {
V_744 -> V_27 |= F_107 ( V_746 ) ;
if ( V_743 > 1 ) {
V_718 |= V_424 ;
if ( V_742 . V_700 & V_747 )
V_718 |= V_747 ;
} else {
V_718 &= ~ ( V_424 |
V_747 ) ;
}
V_744 -> V_308 = F_76 ( V_718 ) ;
} else {
V_743 = 1 ;
}
V_744 -> V_691 = F_96 ( V_743 ) ;
V_744 -> V_687 = F_96 ( V_743 ) ;
V_744 -> V_689 = F_96 ( V_743 ) ;
V_744 -> V_695 = F_96 ( V_742 . V_694 /
( V_716 + 1 ) ) ;
if ( V_745 . V_680 == V_748 )
V_744 -> V_681 = F_96 ( V_742 . V_680 /
( V_716 + 1 ) ) ;
if ( V_745 . V_682 == V_748 )
V_744 -> V_683 = F_96 ( V_742 . V_682 /
( V_716 + 1 ) ) ;
if ( V_745 . V_696 == V_748 )
V_744 -> V_697 = F_96 ( V_742 . V_696 /
( V_716 + 1 ) ) ;
if ( V_745 . V_698 == V_748 )
V_744 -> V_699 = F_96 ( V_742 . V_698 /
( V_716 + 1 ) ) ;
}
int F_201 ( struct V_1 * V_2 ,
struct V_677 V_742 , T_3 V_716 ,
T_3 V_743 )
{
struct {
struct V_669 V_671 ;
struct V_657 V_744 ;
} V_749 V_679 ;
F_198 ( & V_679 . V_671 ) ;
V_679 . V_671 . V_211 . V_659 = V_673 ;
V_679 . V_671 . V_211 . V_667 = V_741 ;
V_679 . V_671 . V_27 = F_107 ( V_739 ) | F_107 ( V_740 ) ;
V_679 . V_671 . V_674 = V_2 -> V_66 -> V_670 ;
V_679 . V_671 . V_731 = V_716 ? 1 : 0 ;
V_679 . V_671 . V_716 = F_96 ( V_716 ) ;
F_197 ( & V_679 . V_744 ) ;
V_679 . V_744 . V_211 . V_659 = V_663 ;
V_679 . V_744 . V_211 . V_667 = V_741 ;
V_679 . V_744 . V_27 = F_107 ( V_666 ) | F_107 ( V_739 ) | F_107 ( V_740 ) ;
V_679 . V_744 . V_674 = V_2 -> V_66 -> V_670 ;
V_679 . V_744 . V_737 = 0 ;
F_200 ( V_2 , V_742 , V_716 , V_743 ,
& V_679 . V_744 ) ;
return F_196 ( V_2 , & V_679 ,
2 * V_741 , 2 , 1 , 0 ) ;
}
int F_202 ( struct V_1 * V_2 , T_2 V_750 , T_1 V_751 )
{
struct V_11 * V_12 ;
struct V_752 * V_207 ;
int V_44 ;
if ( V_750 == 0xFFFFFFFF )
return - 1 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_753 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_751 = V_751 ;
V_207 -> V_754 = F_76 ( V_750 ) ;
V_44 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_203 ( struct V_1 * V_2 , T_6 V_450 )
{
struct V_675 V_755 ;
memset ( & V_755 , 0 , sizeof( V_755 ) ) ;
V_755 . V_211 . V_659 = V_676 ;
V_755 . V_211 . V_667 = V_741 ;
V_755 . V_27 = ( 1 << V_739 ) | ( 1 << V_740 ) ;
V_755 . V_756 = V_2 -> V_81 ;
if ( V_450 ) {
V_755 . V_757 = V_758 | ( 1 << V_759 ) |
( 1 << V_760 ) ;
V_755 . V_761 = F_204 ( V_450 ) ;
} else {
V_755 . V_757 = V_762 ;
V_755 . V_761 = 0 ;
}
return F_196 ( V_2 , & V_755 ,
V_741 , 1 , 1 , 0 ) ;
}
int F_205 ( struct V_1 * V_2 , struct V_763 * V_764 ,
int V_737 )
{
struct V_11 * V_12 ;
struct V_765 * V_207 ;
struct V_766 * V_58 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_767 , sizeof( * V_58 ) ,
V_12 , NULL ) ;
V_207 -> V_211 . V_232 = V_737 + 1 ;
V_44 = F_56 ( V_2 ) ;
if ( ! V_44 ) {
V_58 = (struct V_766 * ) V_207 ;
V_764 -> V_223 = F_8 ( V_58 -> V_768 . V_228 ) ;
}
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
static int F_206 ( struct V_1 * V_2 )
{
#define F_207 30
T_2 V_769 ;
int V_44 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < F_207 ; V_5 ++ ) {
V_769 = F_60 ( V_2 -> V_23 + V_770 ) ;
if ( ( V_769 & V_771 ) == 0 )
break;
F_208 ( 1 ) ;
}
if ( V_5 == F_207 )
V_44 = - 1 ;
return V_44 ;
}
int F_209 ( struct V_1 * V_2 , T_2 V_772 )
{
int V_44 = 0 ;
V_44 = F_206 ( V_2 ) ;
if ( V_44 )
return V_44 ;
F_6 ( V_772 , V_2 -> V_23 + V_770 ) ;
return V_44 ;
}
bool F_210 ( struct V_1 * V_2 )
{
T_2 V_163 = 0 ;
V_163 = F_60 ( V_2 -> V_23 + V_164 ) ;
return ! ! ( V_163 & V_773 ) ;
}
int F_211 ( struct V_1 * V_2 )
{
struct V_79 * V_67 = & V_2 -> V_66 -> V_67 ;
int V_44 ;
if ( F_210 ( V_2 ) ) {
F_23 ( V_67 , L_26 ) ;
return - V_774 ;
}
V_44 = F_209 ( V_2 , V_775 |
V_776 ) ;
if ( V_44 < 0 ) {
F_18 ( V_67 , L_27 ) ;
return V_44 ;
}
V_44 = F_206 ( V_2 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_210 ( V_2 ) ) {
F_18 ( V_67 , L_28 ) ;
return - V_139 ;
}
return 0 ;
}
int F_212 ( struct V_1 * V_2 )
{
int V_44 ;
V_44 = F_151 ( V_2 , V_777 ) ;
return F_213 ( V_44 ) ;
}
int F_214 ( struct V_1 * V_2 , T_1 V_232 )
{
struct V_11 * V_12 ;
struct V_778 * V_207 ;
int V_44 ;
if ( F_20 ( V_2 ) )
return 0 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_779 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
V_207 -> V_511 = 1 ;
V_44 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_215 ( struct V_1 * V_2 , bool V_780 )
{
struct V_11 * V_12 ;
struct V_781 * V_207 ;
int V_44 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_782 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_783 = V_780 ;
V_44 = F_63 ( V_2 ) ;
F_90 ( & V_2 -> V_201 ) ;
return V_44 ;
}
int F_216 ( struct V_1 * V_2 , T_3 * V_784 )
{
struct V_785 * V_207 ;
struct V_11 * V_12 ;
int V_44 ;
if ( F_88 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_786 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_44 = F_63 ( V_2 ) ;
if ( ! V_44 ) {
struct V_787 * V_58 =
F_2 ( V_12 ) ;
* V_784 = F_26 ( V_58 -> V_788 ) ;
}
V_170:
F_90 ( & V_2 -> V_201 ) ;
return V_44 ;
}
int F_217 ( struct V_1 * V_2 ,
int V_789 , T_1 V_232 )
{
struct V_11 * V_12 ;
struct V_790 * V_207 ;
int V_44 ;
if ( F_20 ( V_2 ) || F_70 ( V_2 ) )
return - V_405 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
F_75 ( & V_207 -> V_211 , V_49 ,
V_791 ,
sizeof( * V_207 ) , V_12 , NULL ) ;
V_207 -> V_211 . V_182 = 1 ;
V_207 -> V_211 . V_232 = V_232 ;
if ( V_789 == V_792 )
V_207 -> V_793 |= 1 ;
if ( V_789 == V_794 )
V_207 -> V_793 |= 1 << V_795 ;
V_44 = F_56 ( V_2 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
int F_218 ( void * V_796 , void * V_797 ,
int V_798 , T_3 * V_799 , T_3 * V_800 )
{
struct V_1 * V_2 = F_219 ( V_796 ) ;
struct V_11 * V_12 ;
struct V_176 * V_211 = (struct V_176 * ) V_797 ;
struct V_176 * V_207 ;
struct V_29 * V_58 ;
int V_44 ;
F_41 ( & V_2 -> V_200 ) ;
V_12 = F_82 ( V_2 ) ;
if ( ! V_12 ) {
V_44 = - V_203 ;
goto V_170;
}
V_207 = F_2 ( V_12 ) ;
V_58 = F_2 ( V_12 ) ;
F_75 ( V_207 , V_211 -> V_4 ,
V_211 -> V_3 , V_798 , V_12 , NULL ) ;
memcpy ( V_207 , V_797 , V_798 ) ;
F_77 ( V_207 , V_798 ) ;
V_44 = F_56 ( V_2 ) ;
if ( V_799 )
* V_799 = ( V_44 & 0xffff ) ;
if ( V_800 )
* V_800 = 0 ;
memcpy ( V_797 , V_58 , sizeof( * V_58 ) + V_58 -> V_801 ) ;
F_16 ( V_797 , sizeof( * V_58 ) + V_58 -> V_801 ) ;
V_170:
F_43 ( & V_2 -> V_200 ) ;
return V_44 ;
}
