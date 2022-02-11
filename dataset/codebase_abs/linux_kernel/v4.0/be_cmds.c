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
static bool F_11 ( T_1 V_3 , T_3 V_32 , T_3 V_33 )
{
if ( V_32 == V_34 ||
V_32 == V_35 ||
V_33 == V_36 ||
( V_3 == V_37 &&
( V_32 == V_38 ||
V_33 == V_39 ) ) )
return true ;
else
return false ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_28 * V_40 )
{
enum V_41 V_32 = V_32 ( V_25 -> V_42 ) ;
T_1 V_3 = 0 , V_4 = 0 ;
if ( V_40 ) {
V_3 = V_40 -> V_3 ;
V_4 = V_40 -> V_4 ;
}
if ( V_3 == V_43 &&
V_4 == V_44 ) {
F_13 ( & V_2 -> V_45 ) ;
return;
}
if ( ( V_3 == V_37 ||
V_3 == V_46 ) &&
V_4 == V_47 ) {
V_2 -> V_48 = V_25 -> V_42 ;
F_13 ( & V_2 -> V_45 ) ;
return;
}
if ( ( V_3 == V_49 ||
V_3 == V_50 ) &&
V_4 == V_51 &&
V_32 == V_52 ) {
F_14 ( V_2 ) ;
V_2 -> V_53 = false ;
return;
}
if ( V_3 == V_54 &&
V_4 == V_47 ) {
if ( V_32 == V_52 ) {
struct V_55 * V_56 =
( void * ) V_40 ;
V_2 -> V_57 . V_58 =
V_56 -> V_59 ;
} else {
V_2 -> V_60 = 0 ;
}
return;
}
}
static int F_15 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
enum V_41 V_32 ;
enum V_61 V_33 ;
struct V_28 * V_40 ;
T_1 V_3 = 0 , V_4 = 0 ;
F_16 ( V_25 , 4 ) ;
V_32 = V_32 ( V_25 -> V_42 ) ;
V_33 = V_33 ( V_25 -> V_42 ) ;
V_40 = F_10 ( V_25 -> V_29 , V_25 -> V_30 ) ;
if ( V_40 ) {
V_3 = V_40 -> V_3 ;
V_4 = V_40 -> V_4 ;
}
F_12 ( V_2 , V_25 , V_40 ) ;
if ( V_32 != V_52 &&
! F_11 ( V_3 , V_32 , V_33 ) ) {
if ( V_32 == V_62 ) {
F_17 ( & V_2 -> V_63 -> V_64 ,
L_1 ,
V_3 , V_4 ) ;
} else {
F_18 ( & V_2 -> V_63 -> V_64 ,
L_2 ,
V_3 , V_4 , V_32 , V_33 ) ;
}
}
return V_25 -> V_42 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_65 * V_66 =
(struct V_65 * ) V_25 ;
V_2 -> V_67 . V_68 = - 1 ;
if ( ! F_20 ( V_2 ) &&
! ( V_66 -> V_69 & V_70 ) )
return;
if ( V_2 -> V_26 & V_71 )
F_21 ( V_2 ,
V_66 -> V_69 & V_72 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_73 * V_66 =
(struct V_73 * ) V_25 ;
T_2 V_74 = F_8 ( V_66 -> V_75 ) ;
struct V_76 * V_64 = & V_2 -> V_63 -> V_64 ;
T_1 V_77 ;
V_77 =
( ( V_74 >> ( V_2 -> V_78 * 8 ) ) & 0xff ) ;
F_23 ( V_64 , L_3 , V_2 -> V_79 ,
V_80 [ V_77 ] ,
V_81 [ V_77 ] ) ;
if ( V_77 == V_82 )
V_2 -> V_26 |= V_83 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_84 * V_66 =
(struct V_84 * ) V_25 ;
if ( V_66 -> V_85 ) {
V_2 -> V_86 = V_66 -> V_87 ;
V_2 -> V_88 &= ~ V_89 ;
V_2 -> V_88 =
V_66 -> V_90 << V_91 ;
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_92 * V_66 =
(struct V_92 * ) V_25 ;
if ( V_2 -> V_67 . V_68 >= 0 &&
V_66 -> V_93 == V_2 -> V_94 )
V_2 -> V_67 . V_68 = F_26 ( V_66 -> V_95 ) * 10 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_96 * V_66 =
(struct V_96 * ) V_25 ;
if ( V_66 -> V_97 ) {
V_2 -> V_98 = F_26 ( V_66 -> V_99 ) & V_100 ;
F_23 ( & V_2 -> V_63 -> V_64 , L_4 , V_2 -> V_98 ) ;
} else {
V_2 -> V_98 = 0 ;
}
}
static void F_28 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
T_1 V_101 = ( V_25 -> V_26 >> V_102 ) &
V_103 ;
switch ( V_101 ) {
case V_104 :
F_24 ( V_2 , V_25 ) ;
break;
case V_105 :
F_25 ( V_2 , V_25 ) ;
break;
case V_106 :
F_27 ( V_2 , V_25 ) ;
break;
default:
break;
}
}
static void F_29 ( struct V_1 * V_2 ,
struct V_24 * V_107 )
{
T_1 V_101 = 0 ;
struct V_108 * V_66 = (struct V_108 * ) V_107 ;
V_101 = ( V_107 -> V_26 >> V_102 ) &
V_103 ;
switch ( V_101 ) {
case V_109 :
if ( V_66 -> V_85 )
V_2 -> V_110 = F_26 ( V_66 -> V_111 ) ;
V_2 -> V_26 |= V_112 ;
break;
default:
F_17 ( & V_2 -> V_63 -> V_64 , L_5 ,
V_101 ) ;
break;
}
}
static void F_30 ( struct V_1 * V_2 ,
struct V_24 * V_107 )
{
T_1 V_101 = ( V_107 -> V_26 >> V_102 ) &
V_103 ;
if ( V_101 == V_113 )
F_22 ( V_2 , V_107 ) ;
}
static inline bool F_31 ( T_2 V_26 )
{
return ( ( V_26 >> V_114 ) & V_115 ) ==
V_116 ;
}
static inline bool F_32 ( T_2 V_26 )
{
return ( ( V_26 >> V_114 ) & V_115 ) ==
V_117 ;
}
static inline bool F_33 ( T_2 V_26 )
{
return ( ( V_26 >> V_114 ) & V_115 ) ==
V_118 ;
}
static inline bool F_34 ( T_2 V_26 )
{
return ( ( V_26 >> V_114 ) & V_115 ) ==
V_119 ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
if ( F_31 ( V_25 -> V_26 ) )
F_19 ( V_2 , V_25 ) ;
else if ( F_32 ( V_25 -> V_26 ) )
F_28 ( V_2 , V_25 ) ;
else if ( F_33 ( V_25 -> V_26 ) )
F_29 ( V_2 , V_25 ) ;
else if ( F_34 ( V_25 -> V_26 ) )
F_30 ( V_2 , V_25 ) ;
}
static struct V_24 * F_36 ( struct V_1 * V_2 )
{
struct V_14 * V_120 = & V_2 -> V_16 . V_121 ;
struct V_24 * V_25 = F_37 ( V_120 ) ;
if ( F_7 ( V_25 ) ) {
F_38 ( V_120 ) ;
return V_25 ;
}
return NULL ;
}
void F_39 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_122 ) ;
F_41 ( V_2 , V_2 -> V_16 . V_121 . V_19 , true , 0 ) ;
V_2 -> V_16 . V_123 = true ;
F_42 ( & V_2 -> V_122 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_122 ) ;
V_2 -> V_16 . V_123 = false ;
F_41 ( V_2 , V_2 -> V_16 . V_121 . V_19 , false , 0 ) ;
F_42 ( & V_2 -> V_122 ) ;
}
int F_44 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
int V_124 = 0 , V_42 = 0 ;
struct V_125 * V_16 = & V_2 -> V_16 ;
F_45 ( & V_2 -> V_122 ) ;
while ( ( V_25 = F_36 ( V_2 ) ) ) {
if ( V_25 -> V_26 & V_126 ) {
F_35 ( V_2 , V_25 ) ;
} else if ( V_25 -> V_26 & V_127 ) {
V_42 = F_15 ( V_2 , V_25 ) ;
F_46 ( & V_16 -> V_17 . V_128 ) ;
}
F_9 ( V_25 ) ;
V_124 ++ ;
}
if ( V_124 )
F_41 ( V_2 , V_16 -> V_121 . V_19 , V_16 -> V_123 , V_124 ) ;
F_47 ( & V_2 -> V_122 ) ;
return V_42 ;
}
static int F_48 ( struct V_1 * V_2 )
{
#define F_49 120000
int V_5 , V_42 = 0 ;
struct V_125 * V_16 = & V_2 -> V_16 ;
for ( V_5 = 0 ; V_5 < F_49 ; V_5 ++ ) {
if ( F_4 ( V_2 ) )
return - V_129 ;
F_50 () ;
V_42 = F_44 ( V_2 ) ;
F_51 () ;
if ( F_52 ( & V_16 -> V_17 . V_128 ) == 0 )
break;
F_53 ( 100 ) ;
}
if ( V_5 == F_49 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_6 ) ;
V_2 -> V_130 = true ;
return - V_129 ;
}
return V_42 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_42 ;
struct V_11 * V_12 ;
struct V_125 * V_16 = & V_2 -> V_16 ;
T_3 V_131 = V_16 -> V_17 . V_132 ;
struct V_28 * V_56 ;
F_55 ( & V_131 , V_16 -> V_17 . V_133 ) ;
V_12 = F_56 ( & V_16 -> V_17 , V_131 ) ;
V_56 = F_10 ( V_12 -> V_29 , V_12 -> V_30 ) ;
F_3 ( V_2 ) ;
V_42 = F_48 ( V_2 ) ;
if ( V_42 == - V_129 )
goto V_134;
V_42 = ( V_56 -> V_32 |
( ( V_56 -> V_33 & V_135 ) <<
V_136 ) ) ;
V_134:
return V_42 ;
}
static int F_57 ( struct V_1 * V_2 , void T_4 * V_22 )
{
int V_137 = 0 ;
T_2 V_138 ;
do {
if ( F_4 ( V_2 ) )
return - V_129 ;
V_138 = F_58 ( V_22 ) ;
if ( V_138 == 0xffffffff )
return - 1 ;
V_138 &= V_139 ;
if ( V_138 )
break;
if ( V_137 > 4000 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_6 ) ;
V_2 -> V_130 = true ;
F_59 ( V_2 ) ;
return - 1 ;
}
F_60 ( 1 ) ;
V_137 ++ ;
} while ( true );
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_42 ;
T_2 V_18 = 0 ;
void T_4 * V_22 = V_2 -> V_22 + V_140 ;
struct V_141 * V_142 = & V_2 -> V_142 ;
struct V_143 * V_144 = V_142 -> V_145 ;
struct V_24 * V_25 = & V_144 -> V_25 ;
V_42 = F_57 ( V_2 , V_22 ) ;
if ( V_42 != 0 )
return V_42 ;
V_18 |= V_146 ;
V_18 |= ( F_62 ( V_142 -> V_147 ) >> 2 ) << 2 ;
F_6 ( V_18 , V_22 ) ;
V_42 = F_57 ( V_2 , V_22 ) ;
if ( V_42 != 0 )
return V_42 ;
V_18 = 0 ;
V_18 |= ( T_2 ) ( V_142 -> V_147 >> 4 ) << 2 ;
F_6 ( V_18 , V_22 ) ;
V_42 = F_57 ( V_2 , V_22 ) ;
if ( V_42 != 0 )
return V_42 ;
if ( F_7 ( V_25 ) ) {
V_42 = F_15 ( V_2 , & V_144 -> V_25 ) ;
F_9 ( V_25 ) ;
if ( V_42 )
return V_42 ;
} else {
F_18 ( & V_2 -> V_63 -> V_64 , L_7 ) ;
return - 1 ;
}
return 0 ;
}
static T_3 F_63 ( struct V_1 * V_2 )
{
T_2 V_148 ;
if ( F_20 ( V_2 ) )
V_148 = F_58 ( V_2 -> V_149 + V_150 ) ;
else
F_64 ( V_2 -> V_63 ,
V_151 , & V_148 ) ;
return V_148 & V_152 ;
}
static int F_65 ( struct V_1 * V_2 )
{
#define F_66 30
T_2 V_153 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_66 ; V_5 ++ ) {
V_153 = F_58 ( V_2 -> V_22 + V_154 ) ;
if ( V_153 & V_155 )
break;
F_60 ( 1000 ) ;
}
if ( V_5 == F_66 )
return V_153 ? : - 1 ;
return 0 ;
}
static bool F_67 ( struct V_1 * V_2 )
{
T_2 V_153 = 0 , V_156 = 0 , V_157 = 0 ;
V_153 = F_58 ( V_2 -> V_22 + V_154 ) ;
if ( V_153 & V_158 ) {
V_156 = F_58 ( V_2 -> V_22 + V_159 ) ;
V_157 = F_58 ( V_2 -> V_22 + V_160 ) ;
if ( V_156 == V_161 &&
V_157 == V_162 )
return true ;
}
return false ;
}
int F_68 ( struct V_1 * V_2 )
{
int V_42 ;
T_2 V_153 , V_163 , V_164 ;
bool V_165 ;
V_165 = F_67 ( V_2 ) ;
if ( V_165 )
return - V_166 ;
V_42 = F_65 ( V_2 ) ;
if ( ! V_42 ) {
V_153 = F_58 ( V_2 -> V_22 + V_154 ) ;
V_163 = V_153 & V_158 ;
V_164 = V_153 & V_167 ;
if ( V_163 && V_164 ) {
F_6 ( V_168 ,
V_2 -> V_22 + V_169 ) ;
V_42 = F_65 ( V_2 ) ;
V_153 = F_58 ( V_2 -> V_22 +
V_154 ) ;
V_153 &= ( V_158 |
V_167 ) ;
if ( V_42 || V_153 )
V_42 = - 1 ;
} else if ( V_163 || V_164 ) {
V_42 = - 1 ;
}
}
V_165 = F_67 ( V_2 ) ;
if ( V_165 )
V_42 = - V_166 ;
return V_42 ;
}
int F_69 ( struct V_1 * V_2 )
{
T_3 V_170 ;
int V_42 , V_171 = 0 ;
struct V_76 * V_64 = & V_2 -> V_63 -> V_64 ;
if ( F_70 ( V_2 ) ) {
V_42 = F_65 ( V_2 ) ;
if ( V_42 ) {
V_170 = V_42 ;
goto V_163;
}
return 0 ;
}
do {
V_170 = F_63 ( V_2 ) ;
if ( V_170 == V_172 )
return 0 ;
F_23 ( V_64 , L_8 , V_171 ) ;
if ( F_71 ( 2000 ) ) {
F_18 ( V_64 , L_9 ) ;
return - V_173 ;
}
V_171 += 2 ;
} while ( V_171 < 60 );
V_163:
F_18 ( V_64 , L_10 , V_170 ) ;
return - 1 ;
}
static inline struct V_174 * F_72 ( struct V_11 * V_12 )
{
return & V_12 -> V_13 . V_175 [ 0 ] ;
}
static inline void F_73 ( struct V_11 * V_12 , unsigned long V_31 )
{
V_12 -> V_29 = V_31 & 0xFFFFFFFF ;
V_12 -> V_30 = F_62 ( V_31 ) ;
}
static void F_74 ( struct V_176 * V_177 ,
T_1 V_4 , T_1 V_3 , int V_178 ,
struct V_11 * V_12 ,
struct V_141 * V_179 )
{
struct V_174 * V_180 ;
V_177 -> V_3 = V_3 ;
V_177 -> V_4 = V_4 ;
V_177 -> V_181 = F_75 ( V_178 - sizeof( * V_177 ) ) ;
V_177 -> V_182 = 0 ;
F_73 ( V_12 , ( V_183 ) V_177 ) ;
V_12 -> V_184 = V_178 ;
if ( V_179 ) {
V_12 -> V_185 |= ( 1 & V_186 ) <<
V_187 ;
V_180 = F_72 ( V_12 ) ;
V_180 -> V_188 = F_75 ( F_62 ( V_179 -> V_147 ) ) ;
V_180 -> V_189 = F_75 ( V_179 -> V_147 & 0xFFFFFFFF ) ;
V_180 -> V_133 = F_75 ( V_179 -> V_190 ) ;
} else
V_12 -> V_185 |= V_191 ;
F_76 ( V_12 , 8 ) ;
}
static void F_77 ( struct V_192 * V_193 , T_2 V_194 ,
struct V_141 * V_179 )
{
int V_5 , V_195 = F_78 ( F_79 ( V_179 -> V_145 , V_179 -> V_190 ) , V_194 ) ;
T_5 V_147 = ( T_5 ) V_179 -> V_147 ;
for ( V_5 = 0 ; V_5 < V_195 ; V_5 ++ ) {
V_193 [ V_5 ] . V_196 = F_75 ( V_147 & 0xFFFFFFFF ) ;
V_193 [ V_5 ] . V_197 = F_75 ( F_62 ( V_147 ) ) ;
V_147 += V_198 ;
}
}
static inline struct V_11 * F_80 ( struct V_1 * V_2 )
{
struct V_141 * V_142 = & V_2 -> V_142 ;
struct V_11 * V_12
= & ( (struct V_143 * ) ( V_142 -> V_145 ) ) -> V_12 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
static struct V_11 * F_81 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 . V_17 ;
struct V_11 * V_12 ;
if ( ! V_15 -> V_199 )
return NULL ;
if ( F_52 ( & V_15 -> V_128 ) >= V_15 -> V_133 )
return NULL ;
V_12 = F_82 ( V_15 ) ;
F_83 ( V_15 ) ;
F_84 ( & V_15 -> V_128 ) ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
static bool F_85 ( struct V_1 * V_2 )
{
return V_2 -> V_16 . V_17 . V_199 ;
}
static int F_86 ( struct V_1 * V_2 )
{
if ( F_85 ( V_2 ) ) {
F_40 ( & V_2 -> V_200 ) ;
return 0 ;
} else {
return F_87 ( & V_2 -> V_201 ) ;
}
}
static void F_88 ( struct V_1 * V_2 )
{
if ( F_85 ( V_2 ) )
F_42 ( & V_2 -> V_200 ) ;
else
return F_89 ( & V_2 -> V_201 ) ;
}
static struct V_11 * F_90 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_202 ;
if ( F_85 ( V_2 ) ) {
V_202 = F_81 ( V_2 ) ;
if ( ! V_202 )
return NULL ;
} else {
V_202 = F_80 ( V_2 ) ;
}
memcpy ( V_202 , V_12 , sizeof( * V_12 ) ) ;
if ( V_12 -> V_185 & F_75 ( V_191 ) )
F_73 ( V_202 , ( V_183 ) F_2 ( V_12 ) ) ;
return V_202 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_202 ;
int V_42 ;
V_42 = F_86 ( V_2 ) ;
if ( V_42 )
return V_42 ;
V_202 = F_90 ( V_2 , V_12 ) ;
if ( ! V_202 )
return - V_203 ;
if ( F_85 ( V_2 ) )
V_42 = F_54 ( V_2 ) ;
else
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 )
memcpy ( V_12 , V_202 , sizeof( * V_12 ) ) ;
F_88 ( V_2 ) ;
return V_42 ;
}
int F_92 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_42 ;
if ( F_70 ( V_2 ) )
return 0 ;
if ( F_87 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = ( T_1 * ) F_80 ( V_2 ) ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0x12 ;
* V_12 ++ = 0x34 ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0x56 ;
* V_12 ++ = 0x78 ;
* V_12 = 0xFF ;
V_42 = F_61 ( V_2 ) ;
F_89 ( & V_2 -> V_201 ) ;
return V_42 ;
}
int F_93 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_42 ;
if ( F_70 ( V_2 ) )
return 0 ;
if ( F_87 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = ( T_1 * ) F_80 ( V_2 ) ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xAA ;
* V_12 ++ = 0xBB ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xCC ;
* V_12 ++ = 0xDD ;
* V_12 = 0xFF ;
V_42 = F_61 ( V_2 ) ;
F_89 ( & V_2 -> V_201 ) ;
return V_42 ;
}
int F_94 ( struct V_1 * V_2 , struct V_204 * V_205 )
{
struct V_11 * V_12 ;
struct V_206 * V_207 ;
struct V_141 * V_208 = & V_205 -> V_17 . V_209 ;
int V_42 , V_210 = 0 ;
if ( F_87 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_80 ( V_2 ) ;
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_212 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
if ( ! ( F_20 ( V_2 ) || F_70 ( V_2 ) ) )
V_210 = 2 ;
V_207 -> V_211 . V_182 = V_210 ;
V_207 -> V_213 = F_95 ( F_79 ( V_208 -> V_145 , V_208 -> V_190 ) ) ;
F_96 ( struct V_214 , V_85 , V_207 -> V_215 , 1 ) ;
F_96 ( struct V_214 , V_190 , V_207 -> V_215 , 0 ) ;
F_96 ( struct V_214 , V_216 , V_207 -> V_215 ,
F_97 ( V_205 -> V_17 . V_133 / 256 ) ) ;
F_76 ( V_207 -> V_215 , sizeof( V_207 -> V_215 ) ) ;
F_77 ( V_207 -> V_193 , F_98 ( V_207 -> V_193 ) , V_208 ) ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_217 * V_56 = F_2 ( V_12 ) ;
V_205 -> V_17 . V_19 = F_26 ( V_56 -> V_218 ) ;
V_205 -> V_219 =
( V_210 == 2 ) ? F_26 ( V_56 -> V_219 ) : V_205 -> V_220 ;
V_205 -> V_17 . V_199 = true ;
}
F_89 ( & V_2 -> V_201 ) ;
return V_42 ;
}
int F_99 ( struct V_1 * V_2 , T_1 * V_221 ,
bool V_222 , T_2 V_223 , T_2 V_224 )
{
struct V_11 * V_12 ;
struct V_225 * V_207 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_226 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> type = V_227 ;
if ( V_222 ) {
V_207 -> V_222 = 1 ;
} else {
V_207 -> V_228 = F_95 ( ( T_3 ) V_223 ) ;
V_207 -> V_224 = F_75 ( V_224 ) ;
V_207 -> V_222 = 0 ;
}
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_229 * V_56 = F_2 ( V_12 ) ;
memcpy ( V_221 , V_56 -> V_230 . V_31 , V_231 ) ;
}
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_100 ( struct V_1 * V_2 , T_1 * V_221 ,
T_2 V_228 , T_2 * V_224 , T_2 V_232 )
{
struct V_11 * V_12 ;
struct V_233 * V_207 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_234 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
V_207 -> V_228 = F_75 ( V_228 ) ;
memcpy ( V_207 -> V_235 , V_221 , V_231 ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_236 * V_56 = F_2 ( V_12 ) ;
* V_224 = F_8 ( V_56 -> V_224 ) ;
}
V_163:
F_42 ( & V_2 -> V_200 ) ;
if ( V_42 == V_62 )
V_42 = - V_237 ;
return V_42 ;
}
int F_101 ( struct V_1 * V_2 , T_2 V_228 , int V_224 , T_2 V_238 )
{
struct V_11 * V_12 ;
struct V_239 * V_207 ;
int V_42 ;
if ( V_224 == - 1 )
return 0 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_240 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_211 . V_232 = V_238 ;
V_207 -> V_228 = F_75 ( V_228 ) ;
V_207 -> V_224 = F_75 ( V_224 ) ;
V_42 = F_54 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_102 ( struct V_1 * V_2 , struct V_14 * V_121 ,
struct V_14 * V_241 , bool V_242 , int V_243 )
{
struct V_11 * V_12 ;
struct V_244 * V_207 ;
struct V_141 * V_208 = & V_121 -> V_209 ;
void * V_245 ;
int V_42 ;
if ( F_87 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_80 ( V_2 ) ;
V_207 = F_2 ( V_12 ) ;
V_245 = & V_207 -> V_215 ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_246 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_213 = F_95 ( F_79 ( V_208 -> V_145 , V_208 -> V_190 ) ) ;
if ( F_20 ( V_2 ) ) {
F_96 ( struct V_247 , V_248 , V_245 ,
V_243 ) ;
F_96 ( struct V_247 , V_249 ,
V_245 , V_242 ) ;
F_96 ( struct V_247 , V_216 , V_245 ,
F_97 ( V_121 -> V_133 / 256 ) ) ;
F_96 ( struct V_247 , V_85 , V_245 , 1 ) ;
F_96 ( struct V_247 , V_250 , V_245 , 1 ) ;
F_96 ( struct V_247 , V_251 , V_245 , V_241 -> V_19 ) ;
} else {
V_207 -> V_211 . V_182 = 2 ;
V_207 -> V_252 = 1 ;
if ( ! F_70 ( V_2 ) )
F_96 ( struct V_253 , V_248 ,
V_245 , V_243 ) ;
F_96 ( struct V_253 , V_249 , V_245 ,
V_242 ) ;
F_96 ( struct V_253 , V_216 , V_245 ,
F_97 ( V_121 -> V_133 / 256 ) ) ;
F_96 ( struct V_253 , V_85 , V_245 , 1 ) ;
F_96 ( struct V_253 , V_250 , V_245 , 1 ) ;
F_96 ( struct V_253 , V_251 , V_245 , V_241 -> V_19 ) ;
}
F_76 ( V_245 , sizeof( V_207 -> V_215 ) ) ;
F_77 ( V_207 -> V_193 , F_98 ( V_207 -> V_193 ) , V_208 ) ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_254 * V_56 = F_2 ( V_12 ) ;
V_121 -> V_19 = F_26 ( V_56 -> V_255 ) ;
V_121 -> V_199 = true ;
}
F_89 ( & V_2 -> V_201 ) ;
return V_42 ;
}
static T_2 F_103 ( int V_256 )
{
T_2 V_257 = F_104 ( V_256 ) ;
if ( V_257 == 16 )
V_257 = 0 ;
return V_257 ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_121 )
{
struct V_11 * V_12 ;
struct V_258 * V_207 ;
struct V_141 * V_208 = & V_15 -> V_209 ;
void * V_245 ;
int V_42 ;
if ( F_87 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_80 ( V_2 ) ;
V_207 = F_2 ( V_12 ) ;
V_245 = & V_207 -> V_215 ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_259 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_213 = F_95 ( F_79 ( V_208 -> V_145 , V_208 -> V_190 ) ) ;
if ( F_20 ( V_2 ) ) {
F_96 ( struct V_260 , V_85 , V_245 , 1 ) ;
F_96 ( struct V_260 , V_261 , V_245 ,
F_103 ( V_15 -> V_133 ) ) ;
F_96 ( struct V_260 , V_255 , V_245 , V_121 -> V_19 ) ;
} else {
V_207 -> V_211 . V_182 = 1 ;
V_207 -> V_255 = F_95 ( V_121 -> V_19 ) ;
F_96 ( struct V_262 , V_261 , V_245 ,
F_103 ( V_15 -> V_133 ) ) ;
F_96 ( struct V_262 , V_85 , V_245 , 1 ) ;
F_96 ( struct V_262 , V_263 ,
V_245 , V_121 -> V_19 ) ;
F_96 ( struct V_262 , V_264 ,
V_245 , 1 ) ;
}
V_207 -> V_265 [ 0 ] =
F_75 ( F_106 ( V_116 ) |
F_106 ( V_117 ) |
F_106 ( V_118 ) |
F_106 ( V_119 ) ) ;
F_76 ( V_245 , sizeof( V_207 -> V_215 ) ) ;
F_77 ( V_207 -> V_193 , F_98 ( V_207 -> V_193 ) , V_208 ) ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_266 * V_56 = F_2 ( V_12 ) ;
V_15 -> V_19 = F_26 ( V_56 -> V_19 ) ;
V_15 -> V_199 = true ;
}
F_89 ( & V_2 -> V_201 ) ;
return V_42 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_121 )
{
struct V_11 * V_12 ;
struct V_267 * V_207 ;
struct V_141 * V_208 = & V_15 -> V_209 ;
void * V_245 ;
int V_42 ;
if ( F_87 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_80 ( V_2 ) ;
V_207 = F_2 ( V_12 ) ;
V_245 = & V_207 -> V_215 ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_268 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_213 = F_95 ( F_79 ( V_208 -> V_145 , V_208 -> V_190 ) ) ;
F_96 ( struct V_260 , V_85 , V_245 , 1 ) ;
F_96 ( struct V_260 , V_261 , V_245 ,
F_103 ( V_15 -> V_133 ) ) ;
F_96 ( struct V_260 , V_255 , V_245 , V_121 -> V_19 ) ;
F_76 ( V_245 , sizeof( V_207 -> V_215 ) ) ;
F_77 ( V_207 -> V_193 , F_98 ( V_207 -> V_193 ) , V_208 ) ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_266 * V_56 = F_2 ( V_12 ) ;
V_15 -> V_19 = F_26 ( V_56 -> V_19 ) ;
V_15 -> V_199 = true ;
}
F_89 ( & V_2 -> V_201 ) ;
return V_42 ;
}
int F_108 ( struct V_1 * V_2 ,
struct V_14 * V_15 , struct V_14 * V_121 )
{
int V_42 ;
V_42 = F_105 ( V_2 , V_15 , V_121 ) ;
if ( V_42 && F_20 ( V_2 ) ) {
F_17 ( & V_2 -> V_63 -> V_64 , L_11
L_12
L_13 ) ;
V_42 = F_107 ( V_2 , V_15 , V_121 ) ;
}
return V_42 ;
}
int F_109 ( struct V_1 * V_2 , struct V_269 * V_270 )
{
struct V_11 V_12 = { 0 } ;
struct V_271 * V_207 ;
struct V_14 * V_272 = & V_270 -> V_17 ;
struct V_14 * V_121 = & V_270 -> V_121 ;
struct V_141 * V_208 = & V_272 -> V_209 ;
int V_42 , V_210 = 0 ;
V_207 = F_2 ( & V_12 ) ;
F_74 ( & V_207 -> V_211 , V_51 ,
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
V_207 -> V_228 = F_95 ( V_2 -> V_223 ) ;
V_207 -> V_213 = F_79 ( V_208 -> V_145 , V_208 -> V_190 ) ;
V_207 -> V_276 = V_277 ;
V_207 -> type = V_278 ;
V_207 -> V_255 = F_95 ( V_121 -> V_19 ) ;
V_207 -> V_279 = F_103 ( V_272 -> V_133 ) ;
F_77 ( V_207 -> V_193 , F_98 ( V_207 -> V_193 ) , V_208 ) ;
V_210 = V_207 -> V_211 . V_182 ;
V_42 = F_91 ( V_2 , & V_12 ) ;
if ( ! V_42 ) {
struct V_280 * V_56 = F_2 ( & V_12 ) ;
V_272 -> V_19 = F_26 ( V_56 -> V_281 ) ;
if ( V_210 == 2 )
V_270 -> V_282 = F_8 ( V_56 -> V_282 ) ;
else
V_270 -> V_282 = V_283 ;
V_272 -> V_199 = true ;
}
return V_42 ;
}
int F_110 ( struct V_1 * V_2 ,
struct V_14 * V_284 , T_3 V_255 , T_3 V_285 ,
T_2 V_228 , T_2 V_286 , T_1 * V_287 )
{
struct V_11 * V_12 ;
struct V_288 * V_207 ;
struct V_141 * V_208 = & V_284 -> V_209 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_51 ,
V_289 , sizeof( * V_207 ) , V_12 , NULL ) ;
V_207 -> V_255 = F_95 ( V_255 ) ;
V_207 -> V_285 = F_104 ( V_285 ) - 1 ;
V_207 -> V_213 = 2 ;
F_77 ( V_207 -> V_193 , F_98 ( V_207 -> V_193 ) , V_208 ) ;
V_207 -> V_290 = F_75 ( V_228 ) ;
V_207 -> V_291 = F_95 ( V_292 ) ;
V_207 -> V_293 = F_75 ( V_286 ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_294 * V_56 = F_2 ( V_12 ) ;
V_284 -> V_19 = F_26 ( V_56 -> V_19 ) ;
V_284 -> V_199 = true ;
* V_287 = V_56 -> V_287 ;
}
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_111 ( struct V_1 * V_2 , struct V_14 * V_17 ,
int V_295 )
{
struct V_11 * V_12 ;
struct V_296 * V_207 ;
T_1 V_297 = 0 , V_3 = 0 ;
int V_42 ;
if ( F_87 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_80 ( V_2 ) ;
V_207 = F_2 ( V_12 ) ;
switch ( V_295 ) {
case V_298 :
V_297 = V_47 ;
V_3 = V_299 ;
break;
case V_300 :
V_297 = V_47 ;
V_3 = V_301 ;
break;
case V_302 :
V_297 = V_51 ;
V_3 = V_303 ;
break;
case V_304 :
V_297 = V_51 ;
V_3 = V_305 ;
break;
case V_306 :
V_297 = V_47 ;
V_3 = V_307 ;
break;
default:
F_112 () ;
}
F_74 ( & V_207 -> V_211 , V_297 , V_3 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_19 = F_95 ( V_17 -> V_19 ) ;
V_42 = F_61 ( V_2 ) ;
V_17 -> V_199 = false ;
F_89 ( & V_2 -> V_201 ) ;
return V_42 ;
}
int F_113 ( struct V_1 * V_2 , struct V_14 * V_17 )
{
struct V_11 * V_12 ;
struct V_296 * V_207 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_51 ,
V_305 , sizeof( * V_207 ) , V_12 , NULL ) ;
V_207 -> V_19 = F_95 ( V_17 -> V_19 ) ;
V_42 = F_54 ( V_2 ) ;
V_17 -> V_199 = false ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_114 ( struct V_1 * V_2 , T_2 V_308 , T_2 V_309 ,
T_2 * V_223 , T_2 V_232 )
{
struct V_11 V_12 = { 0 } ;
struct V_310 * V_207 ;
int V_42 ;
V_207 = F_2 ( & V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_311 ,
sizeof( * V_207 ) , & V_12 , NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
V_207 -> V_312 = F_75 ( V_308 ) ;
V_207 -> V_313 = F_75 ( V_309 ) ;
V_207 -> V_314 = true ;
V_42 = F_91 ( V_2 , & V_12 ) ;
if ( ! V_42 ) {
struct V_315 * V_56 = F_2 ( & V_12 ) ;
* V_223 = F_8 ( V_56 -> V_290 ) ;
if ( F_115 ( V_2 ) && ! F_116 ( V_2 ) )
V_2 -> V_224 [ 0 ] = F_8 ( V_56 -> V_224 ) ;
}
return V_42 ;
}
int F_117 ( struct V_1 * V_2 , int V_290 , T_2 V_232 )
{
struct V_11 * V_12 ;
struct V_316 * V_207 ;
int V_42 ;
if ( V_290 == - 1 )
return 0 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_317 ,
sizeof( * V_207 ) , V_12 , NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
V_207 -> V_290 = F_75 ( V_290 ) ;
V_42 = F_54 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_118 ( struct V_1 * V_2 , struct V_141 * V_318 )
{
struct V_11 * V_12 ;
struct V_176 * V_211 ;
int V_42 = 0 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_211 = V_318 -> V_145 ;
F_74 ( V_211 , V_51 ,
V_49 , V_318 -> V_190 , V_12 ,
V_318 ) ;
if ( F_119 ( V_2 ) )
V_211 -> V_182 = 0 ;
if ( F_115 ( V_2 ) || F_70 ( V_2 ) )
V_211 -> V_182 = 1 ;
else
V_211 -> V_182 = 2 ;
F_3 ( V_2 ) ;
V_2 -> V_53 = true ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_120 ( struct V_1 * V_2 ,
struct V_141 * V_318 )
{
struct V_11 * V_12 ;
struct V_319 * V_207 ;
int V_42 = 0 ;
if ( ! F_1 ( V_2 , V_50 ,
V_51 ) )
return - V_237 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = V_318 -> V_145 ;
F_74 ( & V_207 -> V_211 , V_51 ,
V_50 , V_318 -> V_190 ,
V_12 , V_318 ) ;
V_207 -> V_320 . V_321 . V_322 = F_95 ( V_2 -> V_78 ) ;
V_207 -> V_320 . V_321 . V_323 = 0 ;
F_3 ( V_2 ) ;
V_2 -> V_53 = true ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
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
int F_122 ( struct V_1 * V_2 , T_3 * V_68 ,
T_1 * V_333 , T_2 V_238 )
{
struct V_11 * V_12 ;
struct V_334 * V_207 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
if ( V_333 )
* V_333 = V_335 ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_336 ,
sizeof( * V_207 ) , V_12 , NULL ) ;
if ( ! F_119 ( V_2 ) )
V_207 -> V_211 . V_182 = 1 ;
V_207 -> V_211 . V_232 = V_238 ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_337 * V_56 = F_2 ( V_12 ) ;
if ( V_68 ) {
* V_68 = V_56 -> V_68 ?
F_26 ( V_56 -> V_68 ) * 10 :
F_121 ( V_56 -> V_324 ) ;
if ( ! V_56 -> V_338 )
* V_68 = 0 ;
}
if ( V_333 )
* V_333 = V_56 -> V_338 ;
}
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_123 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_339 * V_207 ;
int V_42 = 0 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_54 ,
sizeof( * V_207 ) , V_12 , NULL ) ;
F_3 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_124 ( struct V_1 * V_2 , T_2 * V_340 )
{
struct V_11 * V_12 ;
struct V_341 * V_207 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_342 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_343 = F_75 ( V_344 ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_345 * V_56 = F_2 ( V_12 ) ;
if ( V_340 && V_56 -> V_340 )
* V_340 = F_8 ( V_56 -> V_340 ) -
sizeof( T_2 ) ;
}
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_125 ( struct V_1 * V_2 , T_2 V_346 , void * V_347 )
{
struct V_141 V_348 ;
struct V_11 * V_12 ;
struct V_341 * V_207 ;
T_2 V_349 = 0 , V_350 , V_351 ,
V_352 = sizeof( T_2 ) , V_353 ;
int V_42 = 0 ;
if ( V_346 == 0 )
return - V_129 ;
V_350 = V_346 ;
V_348 . V_190 = sizeof( struct V_341 ) + 60 * 1024 ;
V_348 . V_145 = F_126 ( V_2 -> V_63 ,
V_348 . V_190 ,
& V_348 . V_147 ) ;
if ( ! V_348 . V_145 ) {
F_18 ( & V_2 -> V_63 -> V_64 ,
L_14 ) ;
return - V_354 ;
}
F_40 ( & V_2 -> V_200 ) ;
while ( V_350 ) {
V_351 = F_78 ( V_350 , ( T_2 ) 60 * 1024 ) ;
V_350 -= V_351 ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = V_348 . V_145 ;
V_353 = sizeof( struct V_341 ) + V_351 ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_342 , V_353 ,
V_12 , & V_348 ) ;
V_207 -> V_343 = F_75 ( V_355 ) ;
V_207 -> V_356 = F_75 ( V_352 ) ;
V_207 -> V_357 = F_75 ( V_351 ) ;
V_207 -> V_358 = F_75 ( V_351 ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_345 * V_56 = V_348 . V_145 ;
memcpy ( V_347 + V_349 ,
V_56 -> V_359 ,
F_8 ( V_56 -> V_357 ) ) ;
} else {
F_18 ( & V_2 -> V_63 -> V_64 , L_15 ) ;
goto V_163;
}
V_349 += V_351 ;
V_352 += V_351 ;
}
V_163:
F_127 ( V_2 -> V_63 , V_348 . V_190 ,
V_348 . V_145 , V_348 . V_147 ) ;
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_128 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_360 * V_207 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_361 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_362 * V_56 = F_2 ( V_12 ) ;
F_129 ( V_2 -> V_363 , V_56 -> V_364 ,
sizeof( V_2 -> V_363 ) ) ;
F_129 ( V_2 -> V_365 , V_56 -> V_366 ,
sizeof( V_2 -> V_365 ) ) ;
}
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
static int F_130 ( struct V_1 * V_2 ,
struct V_367 * V_368 , int V_124 )
{
struct V_11 * V_12 ;
struct V_369 * V_207 ;
int V_42 = 0 , V_5 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_370 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_371 = F_75 ( V_124 ) ;
for ( V_5 = 0 ; V_5 < V_124 ; V_5 ++ ) {
V_207 -> V_368 [ V_5 ] . V_218 = F_75 ( V_368 [ V_5 ] . V_218 ) ;
V_207 -> V_368 [ V_5 ] . V_372 = 0 ;
V_207 -> V_368 [ V_5 ] . V_373 =
F_75 ( V_368 [ V_5 ] . V_373 ) ;
}
F_3 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_131 ( struct V_1 * V_2 , struct V_367 * V_368 ,
int V_124 )
{
int V_374 , V_5 = 0 ;
while ( V_124 ) {
V_374 = F_78 ( V_124 , 8 ) ;
F_130 ( V_2 , & V_368 [ V_5 ] , V_374 ) ;
V_5 += V_374 ;
V_124 -= V_374 ;
}
return 0 ;
}
int F_132 ( struct V_1 * V_2 , T_2 V_228 , T_3 * V_375 ,
T_2 V_124 , T_2 V_232 )
{
struct V_11 * V_12 ;
struct V_376 * V_207 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_377 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
V_207 -> V_290 = V_228 ;
V_207 -> V_378 = V_379 & F_133 ( V_2 ) ? 1 : 0 ;
V_207 -> V_380 = V_124 ;
memcpy ( V_207 -> V_381 , V_375 ,
V_207 -> V_380 * sizeof( V_375 [ 0 ] ) ) ;
V_42 = F_54 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
static int F_134 ( struct V_1 * V_2 , T_2 V_26 , T_2 V_382 )
{
struct V_11 * V_12 ;
struct V_141 * V_179 = & V_2 -> V_383 ;
struct V_384 * V_207 = V_179 -> V_145 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
memset ( V_207 , 0 , sizeof( * V_207 ) ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_385 , sizeof( * V_207 ) ,
V_12 , V_179 ) ;
V_207 -> V_228 = F_75 ( V_2 -> V_223 ) ;
V_207 -> V_386 = F_75 ( V_26 ) ;
V_207 -> V_387 = ( V_382 == V_388 ) ? V_207 -> V_386 : 0 ;
if ( V_26 & V_389 ) {
struct V_390 * V_391 ;
int V_5 = 0 ;
V_207 -> V_386 |=
F_75 ( V_392 &
F_133 ( V_2 ) ) ;
V_207 -> V_393 = F_75 ( F_135 ( V_2 -> V_394 ) ) ;
F_136 (ha, adapter->netdev)
memcpy ( V_207 -> V_395 [ V_5 ++ ] . V_396 , V_391 -> V_31 , V_231 ) ;
}
V_42 = F_54 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_137 ( struct V_1 * V_2 , T_2 V_26 , T_2 V_382 )
{
struct V_76 * V_64 = & V_2 -> V_63 -> V_64 ;
if ( ( V_26 & F_133 ( V_2 ) ) != V_26 ) {
F_17 ( V_64 , L_16 , V_26 ) ;
F_17 ( V_64 , L_17 ,
F_133 ( V_2 ) ) ;
}
V_26 &= F_133 ( V_2 ) ;
return F_134 ( V_2 , V_26 , V_382 ) ;
}
int F_138 ( struct V_1 * V_2 , T_2 V_397 , T_2 V_398 )
{
struct V_11 * V_12 ;
struct V_399 * V_207 ;
int V_42 ;
if ( ! F_1 ( V_2 , V_400 ,
V_47 ) )
return - V_237 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_400 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_211 . V_182 = 1 ;
V_207 -> V_401 = F_95 ( ( T_3 ) V_397 ) ;
V_207 -> V_402 = F_95 ( ( T_3 ) V_398 ) ;
V_42 = F_54 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
if ( V_32 ( V_42 ) == V_403 )
return - V_404 ;
return V_42 ;
}
int F_139 ( struct V_1 * V_2 , T_2 * V_397 , T_2 * V_398 )
{
struct V_11 * V_12 ;
struct V_405 * V_207 ;
int V_42 ;
if ( ! F_1 ( V_2 , V_406 ,
V_47 ) )
return - V_237 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_406 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_407 * V_56 =
F_2 ( V_12 ) ;
* V_397 = F_26 ( V_56 -> V_401 ) ;
* V_398 = F_26 ( V_56 -> V_402 ) ;
}
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_140 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_408 * V_207 ;
int V_42 ;
if ( F_87 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_80 ( V_2 ) ;
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_409 ,
sizeof( * V_207 ) , V_12 , NULL ) ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_410 * V_56 = F_2 ( V_12 ) ;
V_2 -> V_94 = F_8 ( V_56 -> V_411 ) ;
V_2 -> V_412 = F_8 ( V_56 -> V_412 ) ;
V_2 -> V_274 = F_8 ( V_56 -> V_274 ) ;
V_2 -> V_413 = F_8 ( V_56 -> V_414 ) & 0xFF ;
F_23 ( & V_2 -> V_63 -> V_64 ,
L_18 ,
V_2 -> V_412 , V_2 -> V_274 ) ;
}
F_89 ( & V_2 -> V_201 ) ;
return V_42 ;
}
int F_141 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_176 * V_207 ;
int V_42 ;
if ( F_70 ( V_2 ) ) {
V_42 = F_65 ( V_2 ) ;
if ( ! V_42 ) {
F_6 ( V_168 ,
V_2 -> V_22 + V_169 ) ;
V_42 = F_68 ( V_2 ) ;
}
if ( V_42 ) {
F_18 ( & V_2 -> V_63 -> V_64 ,
L_19 ) ;
}
return V_42 ;
}
if ( F_87 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_80 ( V_2 ) ;
V_207 = F_2 ( V_12 ) ;
F_74 ( V_207 , V_47 ,
V_415 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_42 = F_61 ( V_2 ) ;
F_89 ( & V_2 -> V_201 ) ;
return V_42 ;
}
int F_142 ( struct V_1 * V_2 , T_1 * V_416 ,
T_2 V_417 , T_3 V_418 , const T_1 * V_419 )
{
struct V_11 * V_12 ;
struct V_420 * V_207 ;
int V_42 ;
if ( ! ( F_133 ( V_2 ) & V_421 ) )
return 0 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_51 ,
V_422 , sizeof( * V_207 ) , V_12 , NULL ) ;
V_207 -> V_228 = F_75 ( V_2 -> V_223 ) ;
V_207 -> V_423 = F_95 ( V_417 ) ;
V_207 -> V_424 = F_95 ( F_104 ( V_418 ) - 1 ) ;
if ( ! F_20 ( V_2 ) )
V_207 -> V_211 . V_182 = 1 ;
memcpy ( V_207 -> V_425 , V_416 , V_418 ) ;
memcpy ( V_207 -> V_426 , V_419 , V_427 ) ;
F_76 ( V_207 -> V_426 , sizeof( V_207 -> V_426 ) ) ;
V_42 = F_54 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_143 ( struct V_1 * V_2 , T_1 V_94 ,
T_1 V_428 , T_1 V_429 , T_1 V_430 )
{
struct V_11 * V_12 ;
struct V_431 * V_207 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_432 ,
sizeof( * V_207 ) , V_12 , NULL ) ;
V_207 -> V_94 = V_94 ;
V_207 -> V_433 = V_430 ;
V_207 -> V_434 = V_428 ;
V_207 -> V_435 = V_429 ;
V_42 = F_54 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_144 ( struct V_1 * V_2 , T_1 V_94 , T_2 * V_430 )
{
struct V_11 * V_12 ;
struct V_436 * V_207 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_437 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_94 = V_94 ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_438 * V_56 =
F_2 ( V_12 ) ;
* V_430 = V_56 -> V_433 ;
}
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_145 ( struct V_1 * V_2 ,
T_1 V_439 , T_1 * V_440 )
{
struct V_141 V_441 ;
struct V_11 * V_12 ;
struct V_442 * V_207 ;
int V_42 ;
if ( V_439 > V_443 )
return - V_444 ;
V_441 . V_190 = sizeof( struct V_445 ) ;
V_441 . V_145 = F_126 ( V_2 -> V_63 , V_441 . V_190 , & V_441 . V_147 ) ;
if ( ! V_441 . V_145 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_20 ) ;
return - V_354 ;
}
memset ( V_441 . V_145 , 0 , V_441 . V_190 ) ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = V_441 . V_145 ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_446 ,
V_441 . V_190 , V_12 , & V_441 ) ;
V_207 -> V_447 = F_75 ( V_2 -> V_78 ) ;
V_207 -> V_439 = F_75 ( V_439 ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_445 * V_56 = V_441 . V_145 ;
memcpy ( V_440 , V_56 -> V_448 , V_449 ) ;
}
V_163:
F_42 ( & V_2 -> V_200 ) ;
F_127 ( V_2 -> V_63 , V_441 . V_190 , V_441 . V_145 , V_441 . V_147 ) ;
return V_42 ;
}
int F_146 ( struct V_1 * V_2 , struct V_141 * V_441 ,
T_2 V_450 , T_2 V_451 ,
const char * V_452 , T_2 * V_453 ,
T_1 * V_454 , T_1 * V_455 )
{
struct V_11 * V_12 ;
struct V_456 * V_207 ;
struct V_457 * V_56 ;
void * V_245 = NULL ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_2 -> V_48 = 0 ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_458;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_46 ,
sizeof( struct V_456 ) , V_12 ,
NULL ) ;
V_245 = & V_207 -> V_215 ;
F_96 ( struct V_459 ,
V_460 , V_245 , V_450 ) ;
if ( V_450 == 0 )
F_96 ( struct V_459 ,
V_461 , V_245 , 1 ) ;
else
F_96 ( struct V_459 ,
V_461 , V_245 , 0 ) ;
F_76 ( V_245 , sizeof( V_207 -> V_215 ) ) ;
V_207 -> V_462 = F_75 ( V_451 ) ;
F_129 ( V_207 -> V_463 , V_452 , sizeof( V_207 -> V_463 ) ) ;
V_207 -> V_464 = F_75 ( 1 ) ;
V_207 -> V_346 = F_75 ( V_450 ) ;
V_207 -> V_465 = F_75 ( ( V_441 -> V_147 +
sizeof( struct V_456 ) )
& 0xFFFFFFFF ) ;
V_207 -> V_466 = F_75 ( F_62 ( V_441 -> V_147 +
sizeof( struct V_456 ) ) ) ;
F_3 ( V_2 ) ;
F_42 ( & V_2 -> V_200 ) ;
if ( ! F_147 ( & V_2 -> V_45 ,
F_148 ( 60000 ) ) )
V_42 = - V_467 ;
else
V_42 = V_2 -> V_48 ;
V_56 = F_2 ( V_12 ) ;
if ( ! V_42 ) {
* V_453 = F_8 ( V_56 -> V_468 ) ;
* V_454 = V_56 -> V_454 ;
} else {
* V_455 = V_56 -> V_469 ;
}
return V_42 ;
V_458:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_149 ( struct V_1 * V_2 )
{
T_1 V_448 [ V_449 ] ;
int V_42 ;
V_42 = F_145 ( V_2 , V_470 ,
V_448 ) ;
if ( ! V_42 ) {
switch ( V_2 -> V_67 . V_471 ) {
case V_472 :
V_2 -> V_67 . V_473 =
V_448 [ V_474 ] ;
break;
case V_475 :
V_2 -> V_67 . V_473 =
V_448 [ V_476 ] ;
break;
default:
V_2 -> V_67 . V_473 = 0 ;
break;
}
}
return V_42 ;
}
int F_150 ( struct V_1 * V_2 )
{
T_1 V_448 [ V_449 ] ;
int V_42 ;
V_42 = F_145 ( V_2 , V_470 ,
V_448 ) ;
if ( ! V_42 ) {
F_129 ( V_2 -> V_67 . V_477 , V_448 +
V_478 , V_479 - 1 ) ;
F_129 ( V_2 -> V_67 . V_480 ,
V_448 + V_481 ,
V_479 - 1 ) ;
}
return V_42 ;
}
int F_151 ( struct V_1 * V_2 , const char * V_452 )
{
struct V_482 * V_207 ;
struct V_11 * V_12 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_483 ,
sizeof( * V_207 ) , V_12 , NULL ) ;
F_129 ( V_207 -> V_463 , V_452 , sizeof( V_207 -> V_463 ) ) ;
V_42 = F_54 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_152 ( struct V_1 * V_2 , struct V_141 * V_441 ,
T_2 V_450 , T_2 V_451 , const char * V_452 ,
T_2 * V_484 , T_2 * V_461 , T_1 * V_455 )
{
struct V_11 * V_12 ;
struct V_485 * V_207 ;
struct V_486 * V_56 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_458;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_487 ,
sizeof( struct V_485 ) , V_12 ,
NULL ) ;
V_207 -> V_488 = F_75 ( V_450 ) ;
V_207 -> V_489 = F_75 ( V_451 ) ;
strcpy ( V_207 -> V_463 , V_452 ) ;
V_207 -> V_464 = F_75 ( 1 ) ;
V_207 -> V_346 = F_75 ( V_450 ) ;
V_207 -> V_465 = F_75 ( ( V_441 -> V_147 & 0xFFFFFFFF ) ) ;
V_207 -> V_466 = F_75 ( F_62 ( V_441 -> V_147 ) ) ;
V_42 = F_54 ( V_2 ) ;
V_56 = F_2 ( V_12 ) ;
if ( ! V_42 ) {
* V_484 = F_8 ( V_56 -> V_490 ) ;
* V_461 = F_8 ( V_56 -> V_461 ) ;
} else {
* V_455 = V_56 -> V_469 ;
}
V_458:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_153 ( struct V_1 * V_2 , struct V_141 * V_441 ,
T_2 V_491 , T_2 V_492 , T_2 V_493 ,
T_2 V_351 )
{
struct V_11 * V_12 ;
struct F_153 * V_207 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_2 -> V_48 = 0 ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_458;
}
V_207 = V_441 -> V_145 ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_37 , V_441 -> V_190 , V_12 ,
V_441 ) ;
V_207 -> V_321 . V_494 = F_75 ( V_491 ) ;
if ( V_491 == V_495 )
V_207 -> V_321 . V_349 = F_75 ( V_493 ) ;
V_207 -> V_321 . V_496 = F_75 ( V_492 ) ;
V_207 -> V_321 . V_497 = F_75 ( V_351 ) ;
F_3 ( V_2 ) ;
F_42 ( & V_2 -> V_200 ) ;
if ( ! F_147 ( & V_2 -> V_45 ,
F_148 ( 40000 ) ) )
V_42 = - V_467 ;
else
V_42 = V_2 -> V_48 ;
return V_42 ;
V_458:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_154 ( struct V_1 * V_2 , T_1 * V_498 ,
T_3 V_499 , T_2 V_493 , T_2 V_500 )
{
struct V_501 * V_207 ;
struct V_11 * V_12 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_502 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_321 . V_494 = F_75 ( V_499 ) ;
if ( V_499 == V_495 )
V_207 -> V_321 . V_349 = F_75 ( V_493 + V_500 ) ;
else
V_207 -> V_321 . V_349 = F_75 ( V_500 ) ;
V_207 -> V_321 . V_496 = F_75 ( V_503 ) ;
V_207 -> V_321 . V_497 = F_75 ( 0x4 ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 )
memcpy ( V_498 , V_207 -> V_504 , 4 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_155 ( struct V_1 * V_2 , T_1 * V_230 ,
struct V_141 * V_318 )
{
struct V_11 * V_12 ;
struct V_505 * V_207 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = V_318 -> V_145 ;
F_74 ( & V_207 -> V_211 , V_51 ,
V_506 , sizeof( * V_207 ) ,
V_12 , V_318 ) ;
memcpy ( V_207 -> V_507 , V_230 , V_231 ) ;
V_42 = F_54 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_156 ( struct V_1 * V_2 , T_1 V_94 ,
T_1 V_508 , T_1 V_509 )
{
struct V_11 * V_12 ;
struct V_510 * V_207 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_44 ,
V_511 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_512 = V_94 ;
V_207 -> V_513 = V_94 ;
V_207 -> V_508 = V_508 ;
V_207 -> V_514 = V_509 ;
V_42 = F_54 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_157 ( struct V_1 * V_2 , T_2 V_94 ,
T_2 V_508 , T_2 V_515 , T_2 V_516 ,
T_5 V_517 )
{
struct V_11 * V_12 ;
struct V_518 * V_207 ;
struct V_519 * V_56 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_44 ,
V_43 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_211 . V_171 = F_75 ( 15 ) ;
V_207 -> V_517 = F_158 ( V_517 ) ;
V_207 -> V_512 = F_75 ( V_94 ) ;
V_207 -> V_513 = F_75 ( V_94 ) ;
V_207 -> V_515 = F_75 ( V_515 ) ;
V_207 -> V_516 = F_75 ( V_516 ) ;
V_207 -> V_508 = F_75 ( V_508 ) ;
F_3 ( V_2 ) ;
F_42 ( & V_2 -> V_200 ) ;
F_159 ( & V_2 -> V_45 ) ;
V_56 = F_2 ( V_12 ) ;
V_42 = F_8 ( V_56 -> V_42 ) ;
return V_42 ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_160 ( struct V_1 * V_2 , T_5 V_517 ,
T_2 V_520 , struct V_141 * V_441 )
{
struct V_11 * V_12 ;
struct V_521 * V_207 ;
int V_42 ;
int V_5 , V_522 = 0 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = V_441 -> V_145 ;
F_74 ( & V_207 -> V_211 , V_44 ,
V_523 , V_441 -> V_190 , V_12 ,
V_441 ) ;
V_207 -> V_517 = F_158 ( V_517 ) ;
V_207 -> V_524 = F_75 ( V_520 ) ;
for ( V_5 = 0 ; V_5 < V_520 ; V_5 ++ ) {
V_207 -> V_525 [ V_5 ] = ( T_1 ) ( V_517 >> ( V_522 * 8 ) ) ;
V_522 ++ ;
if ( V_522 > 7 )
V_522 = 0 ;
}
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_526 * V_56 ;
V_56 = V_441 -> V_145 ;
if ( ( memcmp ( V_56 -> V_527 , V_207 -> V_525 , V_520 ) != 0 ) ||
V_56 -> V_528 ) {
V_42 = - 1 ;
}
}
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_161 ( struct V_1 * V_2 ,
struct V_141 * V_318 )
{
struct V_11 * V_12 ;
struct V_529 * V_207 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = V_318 -> V_145 ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_530 , sizeof( * V_207 ) , V_12 ,
V_318 ) ;
V_42 = F_54 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_162 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_531 * V_207 ;
struct V_141 V_441 ;
int V_42 ;
if ( ! F_1 ( V_2 , V_532 ,
V_47 ) )
return - V_237 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_441 . V_190 = sizeof( struct V_531 ) ;
V_441 . V_145 = F_126 ( V_2 -> V_63 , V_441 . V_190 , & V_441 . V_147 ) ;
if ( ! V_441 . V_145 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_21 ) ;
V_42 = - V_354 ;
goto V_163;
}
V_207 = V_441 . V_145 ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_532 , sizeof( * V_207 ) ,
V_12 , & V_441 ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_533 * V_534 =
V_441 . V_145 + sizeof( struct V_176 ) ;
V_2 -> V_67 . V_535 = F_26 ( V_534 -> V_535 ) ;
V_2 -> V_67 . V_471 =
F_26 ( V_534 -> V_471 ) ;
V_2 -> V_67 . V_536 =
F_26 ( V_534 -> V_536 ) ;
V_2 -> V_67 . V_537 =
F_26 ( V_534 -> V_537 ) ;
V_2 -> V_67 . V_538 =
F_8 ( V_534 -> V_538 ) ;
if ( F_119 ( V_2 ) ) {
V_2 -> V_67 . V_537 =
V_539 |
V_540 ;
}
}
F_127 ( V_2 -> V_63 , V_441 . V_190 , V_441 . V_145 , V_441 . V_147 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
static int F_163 ( struct V_1 * V_2 , T_2 V_541 , T_2 V_232 )
{
struct V_11 * V_12 ;
struct V_542 * V_207 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_543 , sizeof( * V_207 ) , V_12 , NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
V_207 -> V_544 = F_75 ( V_545 ) ;
V_207 -> V_546 = F_75 ( V_541 ) ;
V_42 = F_54 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_164 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_547 * V_207 ;
struct V_548 * V_56 ;
int V_42 ;
int V_353 = F_165 ( sizeof( * V_207 ) , sizeof( * V_56 ) ) ;
struct V_549 * V_550 ;
struct V_141 V_551 ;
if ( F_87 ( & V_2 -> V_201 ) )
return - 1 ;
memset ( & V_551 , 0 , sizeof( struct V_141 ) ) ;
V_551 . V_190 = sizeof( struct V_548 ) ;
V_551 . V_145 = F_126 ( V_2 -> V_63 , V_551 . V_190 ,
& V_551 . V_147 ) ;
if ( ! V_551 . V_145 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_22 ) ;
V_42 = - V_354 ;
goto V_163;
}
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = V_551 . V_145 ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_552 , V_353 ,
V_12 , & V_551 ) ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
V_550 = V_551 . V_145 + sizeof( struct V_28 ) ;
V_2 -> V_78 = V_550 -> V_553 . V_554 ;
}
V_163:
F_89 ( & V_2 -> V_201 ) ;
if ( V_551 . V_145 )
F_127 ( V_2 -> V_63 , V_551 . V_190 ,
V_551 . V_145 , V_551 . V_147 ) ;
return V_42 ;
}
int F_166 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_555 * V_207 ;
int V_42 ;
if ( F_87 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_556 ,
sizeof( * V_207 ) , V_12 , NULL ) ;
V_207 -> V_557 = F_75 ( V_558 |
V_559 ) ;
V_207 -> V_308 = F_75 ( V_559 ) ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_560 * V_56 = F_2 ( V_12 ) ;
V_2 -> V_561 = F_8 ( V_56 -> V_308 ) &
V_559 ;
if ( ! V_2 -> V_561 )
F_17 ( & V_2 -> V_63 -> V_64 ,
L_23 ) ;
}
V_163:
F_89 ( & V_2 -> V_201 ) ;
return V_42 ;
}
int F_167 ( struct V_1 * V_2 , T_2 * V_562 ,
T_2 V_232 )
{
struct V_11 * V_12 ;
struct V_563 * V_207 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_564 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_565 * V_56 =
F_2 ( V_12 ) ;
* V_562 = F_8 ( V_56 -> V_566 ) ;
if ( F_20 ( V_2 ) && F_168 ( V_2 ) &&
F_116 ( V_2 ) )
* V_562 = V_567 ;
}
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_169 ( struct V_1 * V_2 , T_2 V_568 ,
T_2 V_232 )
{
struct V_11 * V_12 ;
struct V_569 * V_207 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_570 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
if ( F_70 ( V_2 ) )
V_207 -> V_571 = F_75 ( V_568 ) ;
else
V_207 -> V_568 = F_75 ( V_568 ) ;
V_42 = F_54 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_170 ( struct V_1 * V_2 , T_1 * V_230 ,
bool * V_572 , T_2 * V_224 , T_2 V_223 ,
T_1 V_232 )
{
struct V_11 * V_12 ;
struct V_573 * V_207 ;
int V_42 ;
int V_574 ;
struct V_141 V_575 ;
int V_5 ;
memset ( & V_575 , 0 , sizeof( struct V_141 ) ) ;
V_575 . V_190 = sizeof( struct V_576 ) ;
V_575 . V_145 = F_126 ( V_2 -> V_63 ,
V_575 . V_190 ,
& V_575 . V_147 ) ;
if ( ! V_575 . V_145 ) {
F_18 ( & V_2 -> V_63 -> V_64 ,
L_24 ) ;
return - V_354 ;
}
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_134;
}
V_207 = V_575 . V_145 ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_577 ,
V_575 . V_190 , V_12 , & V_575 ) ;
V_207 -> V_211 . V_232 = V_232 ;
V_207 -> V_578 = V_227 ;
if ( * V_572 ) {
V_207 -> V_579 = F_75 ( * V_224 ) ;
V_207 -> V_580 = F_95 ( V_223 ) ;
V_207 -> V_581 = 0 ;
} else {
V_207 -> V_581 = 1 ;
}
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_576 * V_56 =
V_575 . V_145 ;
if ( * V_572 ) {
memcpy ( V_230 , V_56 -> V_582 . V_583 . V_584 ,
V_231 ) ;
goto V_134;
}
V_574 = V_56 -> V_585 + V_56 -> V_586 ;
for ( V_5 = 0 ; V_5 < V_574 ; V_5 ++ ) {
struct V_587 * V_588 ;
T_3 V_589 ;
T_2 V_579 ;
V_588 = & V_56 -> V_590 [ V_5 ] ;
V_589 = F_26 ( V_588 -> V_589 ) ;
if ( V_589 == sizeof( T_2 ) ) {
* V_572 = true ;
V_579 = V_588 -> V_583 . V_591 . V_579 ;
* V_224 = F_8 ( V_579 ) ;
goto V_134;
}
}
* V_572 = false ;
memcpy ( V_230 , V_56 -> V_590 [ 0 ] . V_583 . V_584 ,
V_231 ) ;
}
V_134:
F_42 ( & V_2 -> V_200 ) ;
F_127 ( V_2 -> V_63 , V_575 . V_190 ,
V_575 . V_145 , V_575 . V_147 ) ;
return V_42 ;
}
int F_171 ( struct V_1 * V_2 , T_2 V_592 ,
T_1 * V_230 , T_2 V_223 , bool V_593 , T_2 V_232 )
{
if ( ! V_593 )
F_170 ( V_2 , V_230 , & V_593 , & V_592 ,
V_223 , V_232 ) ;
if ( F_20 ( V_2 ) )
return F_99 ( V_2 , V_230 , false ,
V_223 , V_592 ) ;
else
return F_170 ( V_2 , V_230 , & V_593 ,
& V_592 ,
V_223 , V_232 ) ;
}
int F_172 ( struct V_1 * V_2 , T_1 * V_230 )
{
int V_42 ;
bool V_594 = false ;
memset ( V_230 , 0 , V_231 ) ;
if ( F_20 ( V_2 ) ) {
if ( F_116 ( V_2 ) )
V_42 = F_99 ( V_2 , V_230 , true , 0 ,
0 ) ;
else
V_42 = F_99 ( V_2 , V_230 , false ,
V_2 -> V_223 , 0 ) ;
} else {
V_42 = F_170 ( V_2 , V_230 , & V_594 ,
NULL , V_2 -> V_223 , 0 ) ;
}
return V_42 ;
}
int F_173 ( struct V_1 * V_2 , T_1 * V_595 ,
T_1 V_574 , T_2 V_232 )
{
struct V_11 * V_12 ;
struct V_596 * V_207 ;
int V_42 ;
struct V_141 V_441 ;
memset ( & V_441 , 0 , sizeof( struct V_141 ) ) ;
V_441 . V_190 = sizeof( struct V_596 ) ;
V_441 . V_145 = F_174 ( & V_2 -> V_63 -> V_64 , V_441 . V_190 ,
& V_441 . V_147 , V_597 ) ;
if ( ! V_441 . V_145 )
return - V_354 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = V_441 . V_145 ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_598 , sizeof( * V_207 ) ,
V_12 , & V_441 ) ;
V_207 -> V_211 . V_232 = V_232 ;
V_207 -> V_574 = V_574 ;
if ( V_574 )
memcpy ( V_207 -> V_230 , V_595 , V_231 * V_574 ) ;
V_42 = F_54 ( V_2 ) ;
V_163:
F_175 ( & V_2 -> V_63 -> V_64 , V_441 . V_190 , V_441 . V_145 , V_441 . V_147 ) ;
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_176 ( struct V_1 * V_2 , T_1 * V_230 , int V_228 , T_2 V_238 )
{
bool V_599 = false ;
T_1 V_600 [ V_231 ] ;
T_2 V_224 ;
int V_42 ;
V_42 = F_170 ( V_2 , V_600 , & V_599 ,
& V_224 , V_228 , V_238 ) ;
if ( ! V_42 && V_599 )
F_101 ( V_2 , V_228 , V_224 , V_238 ) ;
return F_173 ( V_2 , V_230 , V_230 ? 1 : 0 , V_238 ) ;
}
int F_177 ( struct V_1 * V_2 , T_3 V_98 ,
T_2 V_232 , T_3 V_601 , T_3 V_602 )
{
struct V_11 * V_12 ;
struct V_603 * V_207 ;
void * V_245 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
V_245 = & V_207 -> V_215 ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_604 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
F_96 ( struct V_605 , V_290 , V_245 , V_601 ) ;
if ( V_98 ) {
F_96 ( struct V_605 , V_606 , V_245 , 1 ) ;
F_96 ( struct V_605 , V_98 , V_245 , V_98 ) ;
}
if ( ! F_20 ( V_2 ) && V_602 ) {
F_96 ( struct V_605 , V_290 ,
V_245 , V_2 -> V_78 ) ;
F_96 ( struct V_605 , V_607 , V_245 , 1 ) ;
F_96 ( struct V_605 , V_608 ,
V_245 , V_602 ) ;
}
F_76 ( V_207 -> V_215 , sizeof( V_207 -> V_215 ) ) ;
V_42 = F_54 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_178 ( struct V_1 * V_2 , T_3 * V_98 ,
T_2 V_232 , T_3 V_601 , T_1 * V_609 )
{
struct V_11 * V_12 ;
struct V_610 * V_207 ;
void * V_245 ;
int V_42 ;
T_3 V_611 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
V_245 = & V_207 -> V_215 ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_612 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
F_96 ( struct V_613 , V_290 ,
V_245 , V_601 ) ;
F_96 ( struct V_613 , V_606 , V_245 , 1 ) ;
if ( ! F_20 ( V_2 ) && V_609 ) {
F_96 ( struct V_613 , V_290 ,
V_245 , V_2 -> V_78 ) ;
F_96 ( struct V_613 , V_607 , V_245 , 1 ) ;
}
F_76 ( V_207 -> V_215 , sizeof( V_207 -> V_215 ) ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_614 * V_56 =
F_2 ( V_12 ) ;
F_16 ( & V_56 -> V_215 , sizeof( V_56 -> V_215 ) ) ;
V_611 = F_179 ( struct V_615 ,
V_98 , & V_56 -> V_215 ) ;
if ( V_98 )
* V_98 = F_26 ( V_611 ) ;
if ( V_609 )
* V_609 = F_179 ( struct V_615 ,
V_608 , & V_56 -> V_215 ) ;
}
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
static bool F_180 ( struct V_1 * V_2 )
{
struct V_616 * V_63 = V_2 -> V_63 ;
if ( ! F_116 ( V_2 ) )
return true ;
switch ( V_63 -> V_617 ) {
case V_618 :
case V_619 :
case V_620 :
case V_621 :
return true ;
default:
return false ;
}
}
int F_181 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_622 * V_207 ;
int V_42 = 0 ;
struct V_141 V_441 ;
if ( ! F_1 ( V_2 , V_506 ,
V_51 ) )
return - V_237 ;
if ( F_180 ( V_2 ) )
return V_42 ;
if ( F_87 ( & V_2 -> V_201 ) )
return - 1 ;
memset ( & V_441 , 0 , sizeof( struct V_141 ) ) ;
V_441 . V_190 = sizeof( struct V_623 ) ;
V_441 . V_145 = F_126 ( V_2 -> V_63 , V_441 . V_190 , & V_441 . V_147 ) ;
if ( ! V_441 . V_145 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_22 ) ;
V_42 = - V_354 ;
goto V_163;
}
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = V_441 . V_145 ;
F_74 ( & V_207 -> V_211 , V_51 ,
V_506 ,
sizeof( * V_207 ) , V_12 , & V_441 ) ;
V_207 -> V_211 . V_182 = 1 ;
V_207 -> V_624 = V_625 ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_623 * V_56 ;
V_56 = (struct V_623 * ) V_441 . V_145 ;
V_2 -> V_626 = V_56 -> V_627 ;
if ( V_2 -> V_626 & V_628 )
V_2 -> V_629 = true ;
}
V_163:
F_89 ( & V_2 -> V_201 ) ;
if ( V_441 . V_145 )
F_127 ( V_2 -> V_63 , V_441 . V_190 , V_441 . V_145 , V_441 . V_147 ) ;
return V_42 ;
}
int F_182 ( struct V_1 * V_2 , T_2 V_630 )
{
struct V_141 V_631 ;
struct V_632 * V_633 ;
int V_42 ;
int V_5 , V_522 ;
memset ( & V_631 , 0 , sizeof( struct V_141 ) ) ;
V_631 . V_190 = sizeof( struct V_634 ) ;
V_631 . V_145 = F_126 ( V_2 -> V_63 , V_631 . V_190 ,
& V_631 . V_147 ) ;
if ( ! V_631 . V_145 )
return - V_354 ;
V_42 = F_183 ( V_2 , & V_631 ) ;
if ( V_42 )
goto V_163;
V_633 = (struct V_632 * )
( V_631 . V_145 + sizeof( struct V_28 ) ) ;
for ( V_5 = 0 ; V_5 < F_8 ( V_633 -> V_635 ) ; V_5 ++ ) {
T_2 V_636 = F_8 ( V_633 -> V_637 [ V_5 ] . V_636 ) ;
for ( V_522 = 0 ; V_522 < V_636 ; V_522 ++ ) {
if ( V_633 -> V_637 [ V_5 ] . V_638 [ V_522 ] . V_609 == V_639 )
V_633 -> V_637 [ V_5 ] . V_638 [ V_522 ] . V_640 =
F_75 ( V_630 ) ;
}
}
V_42 = F_184 ( V_2 , & V_631 , V_633 ) ;
V_163:
F_127 ( V_2 -> V_63 , V_631 . V_190 , V_631 . V_145 ,
V_631 . V_147 ) ;
return V_42 ;
}
int F_185 ( struct V_1 * V_2 )
{
struct V_141 V_631 ;
struct V_632 * V_633 ;
int V_42 , V_522 ;
int V_630 = 0 ;
memset ( & V_631 , 0 , sizeof( struct V_141 ) ) ;
V_631 . V_190 = sizeof( struct V_634 ) ;
V_631 . V_145 = F_126 ( V_2 -> V_63 , V_631 . V_190 ,
& V_631 . V_147 ) ;
if ( ! V_631 . V_145 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_25 ,
V_641 ) ;
goto V_163;
}
V_42 = F_183 ( V_2 , & V_631 ) ;
if ( ! V_42 ) {
V_633 = (struct V_632 * ) ( V_631 . V_145 +
sizeof( struct V_28 ) ) ;
for ( V_522 = 0 ; V_522 < F_8 ( V_633 -> V_637 [ 0 ] . V_636 ) ; V_522 ++ ) {
if ( V_633 -> V_637 [ 0 ] . V_638 [ V_522 ] . V_609 == V_639 )
V_630 = V_633 -> V_637 [ 0 ] . V_638 [ V_522 ] . V_640 ;
}
}
F_127 ( V_2 -> V_63 , V_631 . V_190 , V_631 . V_145 ,
V_631 . V_147 ) ;
V_163:
return V_630 ;
}
int F_183 ( struct V_1 * V_2 ,
struct V_141 * V_441 )
{
struct V_11 * V_12 ;
struct V_642 * V_207 ;
int V_42 ;
if ( F_87 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = V_441 -> V_145 ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_643 ,
V_441 -> V_190 , V_12 , V_441 ) ;
V_207 -> V_644 = F_75 ( 1 ) ;
V_42 = F_61 ( V_2 ) ;
V_163:
F_89 ( & V_2 -> V_201 ) ;
return V_42 ;
}
int F_184 ( struct V_1 * V_2 ,
struct V_141 * V_441 ,
struct V_632 * V_645 )
{
struct V_11 * V_12 ;
struct V_646 * V_207 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = V_441 -> V_145 ;
memcpy ( & V_207 -> V_647 , V_645 , sizeof( struct V_632 ) ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_648 ,
V_441 -> V_190 , V_12 , V_441 ) ;
V_42 = F_54 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_186 ( struct V_1 * V_2 )
{
struct V_649 * V_207 ;
struct V_11 * V_12 ;
int V_42 ;
if ( F_87 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_80 ( V_2 ) ;
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_650 , sizeof( * V_207 ) , V_12 ,
NULL ) ;
if ( ! F_20 ( V_2 ) )
V_207 -> V_211 . V_182 = 1 ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_651 * V_56 = F_2 ( V_12 ) ;
V_2 -> V_79 = V_56 -> V_79 [ V_2 -> V_78 ] ;
} else {
V_2 -> V_79 = V_2 -> V_78 + '0' ;
}
F_89 ( & V_2 -> V_201 ) ;
return V_42 ;
}
static struct V_652 * F_187 ( T_1 * V_347 , T_2 V_653 ,
int V_654 )
{
struct V_655 * V_211 = (struct V_655 * ) V_347 ;
struct V_652 * V_656 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_653 ; V_5 ++ ) {
if ( V_211 -> V_654 == V_657 ||
V_211 -> V_654 == V_658 ) {
V_656 = (struct V_652 * ) V_211 ;
if ( V_654 == V_659 ||
( V_654 == V_660 &&
V_656 -> V_26 & ( 1 << V_661 ) ) )
return V_656 ;
}
V_211 -> V_662 = V_211 -> V_662 ? : V_663 ;
V_211 = ( void * ) V_211 + V_211 -> V_662 ;
}
return NULL ;
}
static struct V_652 * F_188 ( T_1 * V_347 , T_2 V_653 )
{
return F_187 ( V_347 , V_653 , V_660 ) ;
}
static struct V_652 * F_189 ( T_1 * V_347 , T_2 V_653 )
{
return F_187 ( V_347 , V_653 , V_659 ) ;
}
static struct V_664 * F_190 ( T_1 V_665 , T_1 * V_347 ,
T_2 V_653 )
{
struct V_655 * V_211 = (struct V_655 * ) V_347 ;
struct V_664 * V_666 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_653 ; V_5 ++ ) {
if ( ( V_211 -> V_654 == V_667 ||
V_211 -> V_654 == V_668 ) ) {
V_666 = (struct V_664 * ) V_211 ;
if ( V_666 -> V_669 == V_665 )
return V_666 ;
}
V_211 -> V_662 = V_211 -> V_662 ? : V_663 ;
V_211 = ( void * ) V_211 + V_211 -> V_662 ;
}
return NULL ;
}
static struct V_670 * F_191 ( T_1 * V_347 , T_2 V_653 )
{
struct V_655 * V_211 = (struct V_655 * ) V_347 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_653 ; V_5 ++ ) {
if ( V_211 -> V_654 == V_671 )
return (struct V_670 * ) V_211 ;
V_211 -> V_662 = V_211 -> V_662 ? : V_663 ;
V_211 = ( void * ) V_211 + V_211 -> V_662 ;
}
return NULL ;
}
static void F_192 ( struct V_672 * V_673 ,
struct V_652 * V_674 )
{
V_673 -> V_675 = F_26 ( V_674 -> V_676 ) ;
V_673 -> V_677 = F_26 ( V_674 -> V_678 ) ;
V_673 -> V_679 = F_26 ( V_674 -> V_680 ) ;
V_673 -> V_681 = F_26 ( V_674 -> V_682 ) ;
V_673 -> V_683 = F_26 ( V_674 -> V_684 ) ;
V_673 -> V_685 = F_26 ( V_674 -> V_686 ) ;
V_673 -> V_687 = F_26 ( V_674 -> V_688 ) ;
V_673 -> V_689 = F_8 ( V_674 -> V_308 ) &
V_690 ;
if ( V_673 -> V_683 && V_673 -> V_683 == V_673 -> V_685 )
V_673 -> V_683 -= 1 ;
}
int F_193 ( struct V_1 * V_2 , struct V_672 * V_673 )
{
struct V_11 * V_12 ;
struct V_691 * V_207 ;
int V_42 ;
struct V_141 V_441 ;
if ( F_87 ( & V_2 -> V_201 ) )
return - 1 ;
memset ( & V_441 , 0 , sizeof( struct V_141 ) ) ;
V_441 . V_190 = sizeof( struct V_692 ) ;
V_441 . V_145 = F_126 ( V_2 -> V_63 , V_441 . V_190 , & V_441 . V_147 ) ;
if ( ! V_441 . V_145 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_21 ) ;
V_42 = - V_354 ;
goto V_163;
}
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = V_441 . V_145 ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_693 ,
V_441 . V_190 , V_12 , & V_441 ) ;
if ( F_194 ( V_2 ) )
V_207 -> V_211 . V_182 = 1 ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_692 * V_56 = V_441 . V_145 ;
T_2 V_653 = F_8 ( V_56 -> V_653 ) ;
struct V_652 * V_674 ;
V_674 = F_189 ( V_56 -> V_694 , V_653 ) ;
if ( ! V_674 ) {
V_42 = - V_444 ;
goto V_163;
}
V_2 -> V_695 = V_674 -> V_669 ;
F_192 ( V_673 , V_674 ) ;
}
V_163:
F_89 ( & V_2 -> V_201 ) ;
if ( V_441 . V_145 )
F_127 ( V_2 -> V_63 , V_441 . V_190 , V_441 . V_145 , V_441 . V_147 ) ;
return V_42 ;
}
int F_195 ( struct V_1 * V_2 ,
struct V_672 * V_673 , T_1 V_232 )
{
struct V_696 * V_56 ;
struct V_697 * V_207 ;
struct V_652 * V_698 ;
struct V_664 * V_666 ;
struct V_670 * V_447 ;
struct V_652 * V_656 ;
struct V_11 V_12 = { 0 } ;
struct V_141 V_441 ;
T_2 V_653 ;
int V_42 ;
memset ( & V_441 , 0 , sizeof( struct V_141 ) ) ;
V_441 . V_190 = sizeof( struct V_696 ) ;
V_441 . V_145 = F_126 ( V_2 -> V_63 , V_441 . V_190 , & V_441 . V_147 ) ;
if ( ! V_441 . V_145 )
return - V_354 ;
V_207 = V_441 . V_145 ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_699 ,
V_441 . V_190 , & V_12 , & V_441 ) ;
V_207 -> V_211 . V_232 = V_232 ;
if ( ! F_70 ( V_2 ) )
V_207 -> V_211 . V_182 = 1 ;
V_207 -> type = V_700 ;
V_42 = F_91 ( V_2 , & V_12 ) ;
if ( V_42 )
goto V_163;
V_56 = V_441 . V_145 ;
V_653 = F_8 ( V_56 -> V_653 ) ;
V_666 = F_190 ( V_2 -> V_63 -> V_665 , V_56 -> V_694 ,
V_653 ) ;
if ( V_666 )
V_673 -> V_701 = F_26 ( V_666 -> V_702 ) ;
V_447 = F_191 ( V_56 -> V_694 , V_653 ) ;
if ( V_447 )
V_2 -> V_703 = V_447 -> V_703 ;
V_656 = F_189 ( V_56 -> V_694 , V_653 ) ;
if ( V_656 )
F_192 ( V_673 , V_656 ) ;
V_698 = F_188 ( V_56 -> V_694 , V_653 ) ;
if ( V_698 )
V_673 -> V_704 = V_698 -> V_308 ;
V_163:
if ( V_441 . V_145 )
F_127 ( V_2 -> V_63 , V_441 . V_190 , V_441 . V_145 , V_441 . V_147 ) ;
return V_42 ;
}
static int F_196 ( struct V_1 * V_2 , void * V_674 ,
int V_190 , int V_216 , T_1 V_182 , T_1 V_232 )
{
struct V_705 * V_207 ;
struct V_11 V_12 = { 0 } ;
struct V_141 V_441 ;
int V_42 ;
memset ( & V_441 , 0 , sizeof( struct V_141 ) ) ;
V_441 . V_190 = sizeof( struct V_705 ) ;
V_441 . V_145 = F_126 ( V_2 -> V_63 , V_441 . V_190 , & V_441 . V_147 ) ;
if ( ! V_441 . V_145 )
return - V_354 ;
V_207 = V_441 . V_145 ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_706 , V_441 . V_190 ,
& V_12 , & V_441 ) ;
V_207 -> V_211 . V_182 = V_182 ;
V_207 -> V_211 . V_232 = V_232 ;
V_207 -> V_653 = F_75 ( V_216 ) ;
memcpy ( V_207 -> V_674 , V_674 , V_190 ) ;
V_42 = F_91 ( V_2 , & V_12 ) ;
if ( V_441 . V_145 )
F_127 ( V_2 -> V_63 , V_441 . V_190 , V_441 . V_145 , V_441 . V_147 ) ;
return V_42 ;
}
static void F_197 ( struct V_652 * V_656 )
{
memset ( V_656 , 0 , sizeof( * V_656 ) ) ;
V_656 -> V_676 = 0xFFFF ;
V_656 -> V_707 = 0xFFFF ;
V_656 -> V_678 = 0xFFFF ;
V_656 -> V_680 = 0xFFFF ;
V_656 -> V_682 = 0xFFFF ;
V_656 -> V_686 = 0xFFFF ;
V_656 -> V_684 = 0xFFFF ;
V_656 -> V_708 = 0xFFFF ;
V_656 -> V_709 = 0xFFFF ;
V_656 -> V_710 = 0xFFFF ;
V_656 -> V_688 = 0xFFFF ;
V_656 -> V_711 = 0xFFFF ;
V_656 -> V_712 = 0xFF ;
V_656 -> V_713 = F_95 ( 0xF000 ) ;
V_656 -> V_714 = 0xFF ;
V_656 -> V_715 = 0x0F ;
V_656 -> V_716 = 0xFFFF ;
V_656 -> V_717 = 0xFFFF ;
V_656 -> V_718 = 0xFFFFFFFF ;
V_656 -> V_719 = 0xFFFFFFFF ;
}
static void F_198 ( struct V_664 * V_666 )
{
memset ( V_666 , 0 , sizeof( * V_666 ) ) ;
V_666 -> V_720 = 0xFF ;
V_666 -> V_721 = 0xFF ;
V_666 -> V_722 = 0xFF ;
V_666 -> V_702 = 0xFFFF ;
}
int F_199 ( struct V_1 * V_2 , T_2 V_723 , T_3 V_68 ,
T_1 V_232 )
{
struct V_652 V_724 ;
T_2 V_725 ;
T_3 V_182 = 0 ;
if ( F_115 ( V_2 ) )
return F_163 ( V_2 , V_723 / 10 , V_232 ) ;
F_197 ( & V_724 ) ;
V_724 . V_669 = V_2 -> V_695 ;
V_724 . V_726 = V_232 ;
V_724 . V_718 = 0 ;
if ( F_70 ( V_2 ) ) {
V_724 . V_211 . V_654 = V_657 ;
V_724 . V_211 . V_662 = V_663 ;
V_724 . V_26 = ( 1 << V_727 ) | ( 1 << V_728 ) |
( 1 << V_729 ) ;
V_724 . V_719 = F_75 ( V_723 / 10 ) ;
} else {
V_182 = 1 ;
V_724 . V_211 . V_654 = V_658 ;
V_724 . V_211 . V_662 = V_730 ;
V_724 . V_26 = ( 1 << V_728 ) | ( 1 << V_729 ) ;
V_725 = V_723 ? ( V_723 * 100 ) / V_68 : 100 ;
V_724 . V_719 = F_75 ( V_725 ) ;
}
return F_196 ( V_2 , & V_724 ,
V_724 . V_211 . V_662 ,
1 , V_182 , V_232 ) ;
}
int F_200 ( struct V_1 * V_2 ,
struct V_672 V_673 , T_3 V_702 )
{
struct {
struct V_664 V_666 ;
struct V_652 V_731 ;
} V_732 V_674 ;
T_3 V_733 ;
if ( F_20 ( V_2 ) || F_70 ( V_2 ) )
return 0 ;
F_198 ( & V_674 . V_666 ) ;
V_674 . V_666 . V_211 . V_654 = V_668 ;
V_674 . V_666 . V_211 . V_662 = V_730 ;
V_674 . V_666 . V_26 = ( 1 << V_728 ) | ( 1 << V_729 ) ;
V_674 . V_666 . V_669 = V_2 -> V_63 -> V_665 ;
V_674 . V_666 . V_720 = V_702 ? 1 : 0 ;
V_674 . V_666 . V_702 = F_95 ( V_702 ) ;
F_197 ( & V_674 . V_731 ) ;
V_674 . V_731 . V_211 . V_654 = V_658 ;
V_674 . V_731 . V_211 . V_662 = V_730 ;
V_674 . V_731 . V_26 = ( 1 << V_661 ) | ( 1 << V_728 ) |
( 1 << V_729 ) ;
V_674 . V_731 . V_669 = V_2 -> V_63 -> V_665 ;
V_674 . V_731 . V_726 = 0 ;
if ( V_702 && V_673 . V_704 & V_421 ) {
if ( V_702 < ( F_201 ( V_2 ) - 8 ) )
V_733 = ( V_673 . V_683 - 8 ) / V_702 ;
else
V_733 = V_673 . V_683 / V_702 ;
V_674 . V_731 . V_686 = F_95 ( V_733 ) ;
V_674 . V_731 . V_682 = F_95 ( V_733 ) ;
V_674 . V_731 . V_684 = F_95 ( V_733 - 1 ) ;
V_674 . V_731 . V_709 = F_95 ( 3 * V_733 ) ;
} else {
V_674 . V_731 . V_682 = F_95 ( 1 ) ;
V_674 . V_731 . V_686 = F_95 ( 1 ) ;
V_674 . V_731 . V_684 = F_95 ( 0 ) ;
V_674 . V_731 . V_709 = F_95 ( 3 ) ;
}
return F_196 ( V_2 , & V_674 ,
2 * V_730 , 2 , 1 , 0 ) ;
}
int F_202 ( struct V_1 * V_2 , T_2 V_734 , T_1 V_735 )
{
struct V_11 * V_12 ;
struct V_736 * V_207 ;
int V_42 ;
if ( V_734 == 0xFFFFFFFF )
return - 1 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_737 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_735 = V_735 ;
V_207 -> V_738 = F_75 ( V_734 ) ;
V_42 = F_54 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_203 ( struct V_1 * V_2 , T_6 V_447 )
{
struct V_670 V_739 ;
memset ( & V_739 , 0 , sizeof( V_739 ) ) ;
V_739 . V_211 . V_654 = V_671 ;
V_739 . V_211 . V_662 = V_730 ;
V_739 . V_26 = ( 1 << V_728 ) | ( 1 << V_729 ) ;
V_739 . V_740 = V_2 -> V_78 ;
if ( V_447 ) {
V_739 . V_741 = V_742 | ( 1 << V_743 ) |
( 1 << V_744 ) ;
V_739 . V_745 = F_204 ( V_447 ) ;
} else {
V_739 . V_741 = V_746 ;
V_739 . V_745 = 0 ;
}
return F_196 ( V_2 , & V_739 ,
V_730 , 1 , 1 , 0 ) ;
}
int F_205 ( struct V_1 * V_2 , struct V_747 * V_748 ,
int V_726 )
{
struct V_11 * V_12 ;
struct V_749 * V_207 ;
struct V_750 * V_56 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_751 , sizeof( * V_56 ) ,
V_12 , NULL ) ;
V_207 -> V_211 . V_232 = V_726 + 1 ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
V_56 = (struct V_750 * ) V_207 ;
V_748 -> V_223 = F_8 ( V_56 -> V_752 . V_228 ) ;
}
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
static int F_206 ( struct V_1 * V_2 )
{
#define F_207 30
T_2 V_753 ;
int V_42 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < F_207 ; V_5 ++ ) {
V_753 = F_58 ( V_2 -> V_22 + V_754 ) ;
if ( ( V_753 & V_755 ) == 0 )
break;
F_208 ( 1 ) ;
}
if ( V_5 == F_207 )
V_42 = - 1 ;
return V_42 ;
}
int F_209 ( struct V_1 * V_2 , T_2 V_756 )
{
int V_42 = 0 ;
V_42 = F_206 ( V_2 ) ;
if ( V_42 )
return V_42 ;
F_6 ( V_756 , V_2 -> V_22 + V_754 ) ;
return V_42 ;
}
bool F_210 ( struct V_1 * V_2 )
{
T_2 V_153 = 0 ;
V_153 = F_58 ( V_2 -> V_22 + V_154 ) ;
return ! ! ( V_153 & V_757 ) ;
}
int F_211 ( struct V_1 * V_2 )
{
struct V_76 * V_64 = & V_2 -> V_63 -> V_64 ;
int V_42 ;
if ( F_210 ( V_2 ) ) {
F_23 ( V_64 , L_26 ) ;
return - V_758 ;
}
V_42 = F_209 ( V_2 , V_759 |
V_760 ) ;
if ( V_42 < 0 ) {
F_18 ( V_64 , L_27 ) ;
return V_42 ;
}
V_42 = F_206 ( V_2 ) ;
if ( V_42 )
return V_42 ;
if ( ! F_210 ( V_2 ) ) {
F_18 ( V_64 , L_28 ) ;
return - V_129 ;
}
return 0 ;
}
int F_212 ( struct V_1 * V_2 )
{
int V_42 ;
V_42 = F_151 ( V_2 , V_761 ) ;
return F_213 ( V_42 ) ;
}
int F_214 ( struct V_1 * V_2 , T_1 V_232 )
{
struct V_11 * V_12 ;
struct V_762 * V_207 ;
int V_42 ;
if ( F_20 ( V_2 ) )
return 0 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_763 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_211 . V_232 = V_232 ;
V_207 -> V_509 = 1 ;
V_42 = F_54 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_215 ( struct V_1 * V_2 , bool V_764 )
{
struct V_11 * V_12 ;
struct V_765 * V_207 ;
int V_42 ;
if ( F_87 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_80 ( V_2 ) ;
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_766 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_207 -> V_767 = V_764 ;
V_42 = F_61 ( V_2 ) ;
F_89 ( & V_2 -> V_201 ) ;
return V_42 ;
}
int F_216 ( struct V_1 * V_2 , T_3 * V_768 )
{
struct V_769 * V_207 ;
struct V_11 * V_12 ;
int V_42 ;
if ( F_87 ( & V_2 -> V_201 ) )
return - 1 ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_770 , sizeof( * V_207 ) ,
V_12 , NULL ) ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_771 * V_56 =
F_2 ( V_12 ) ;
* V_768 = F_26 ( V_56 -> V_772 ) ;
}
V_163:
F_89 ( & V_2 -> V_201 ) ;
return V_42 ;
}
int F_217 ( struct V_1 * V_2 ,
int V_773 , T_1 V_232 )
{
struct V_11 * V_12 ;
struct V_774 * V_207 ;
int V_42 ;
if ( F_20 ( V_2 ) || F_70 ( V_2 ) )
return - V_404 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
F_74 ( & V_207 -> V_211 , V_47 ,
V_775 ,
sizeof( * V_207 ) , V_12 , NULL ) ;
V_207 -> V_211 . V_182 = 1 ;
V_207 -> V_211 . V_232 = V_232 ;
if ( V_773 == V_776 )
V_207 -> V_777 |= 1 ;
if ( V_773 == V_778 )
V_207 -> V_777 |= 1 << V_779 ;
V_42 = F_54 ( V_2 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
int F_218 ( void * V_780 , void * V_781 ,
int V_782 , T_3 * V_783 , T_3 * V_784 )
{
struct V_1 * V_2 = F_219 ( V_780 ) ;
struct V_11 * V_12 ;
struct V_176 * V_211 = (struct V_176 * ) V_781 ;
struct V_176 * V_207 ;
struct V_28 * V_56 ;
int V_42 ;
F_40 ( & V_2 -> V_200 ) ;
V_12 = F_81 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_203 ;
goto V_163;
}
V_207 = F_2 ( V_12 ) ;
V_56 = F_2 ( V_12 ) ;
F_74 ( V_207 , V_211 -> V_4 ,
V_211 -> V_3 , V_782 , V_12 , NULL ) ;
memcpy ( V_207 , V_781 , V_782 ) ;
F_76 ( V_207 , V_782 ) ;
V_42 = F_54 ( V_2 ) ;
if ( V_783 )
* V_783 = ( V_42 & 0xffff ) ;
if ( V_784 )
* V_784 = 0 ;
memcpy ( V_781 , V_56 , sizeof( * V_56 ) + V_56 -> V_785 ) ;
F_16 ( V_781 , sizeof( * V_56 ) + V_56 -> V_785 ) ;
V_163:
F_42 ( & V_2 -> V_200 ) ;
return V_42 ;
}
