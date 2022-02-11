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
if ( ( ( V_3 == V_38 ) ||
( V_3 == V_39 ) ) &&
( V_4 == V_40 ) ) {
V_2 -> V_41 = V_32 ;
F_13 ( & V_2 -> V_42 ) ;
}
if ( V_32 == V_43 ) {
if ( ( ( V_3 == V_44 ) ||
( V_3 == V_45 ) ) &&
( V_4 == V_46 ) ) {
F_14 ( V_2 ) ;
V_2 -> V_47 = false ;
}
if ( V_3 == V_48 &&
V_4 == V_40 ) {
struct V_49 * V_50 =
( void * ) V_34 ;
V_2 -> V_51 . V_52 =
V_50 -> V_53 ;
}
} else {
if ( V_3 == V_48 )
V_2 -> V_54 = 0 ;
if ( V_32 == V_55 ||
V_32 == V_56 )
goto V_57;
if ( V_32 == V_58 ) {
F_15 ( & V_2 -> V_59 -> V_60 ,
L_1 ,
V_3 , V_4 ) ;
} else {
V_33 = ( V_25 -> V_35 >> V_61 ) &
V_62 ;
F_16 ( & V_2 -> V_59 -> V_60 ,
L_2 ,
V_3 , V_4 , V_32 , V_33 ) ;
if ( V_33 == V_63 )
return V_33 ;
}
}
V_57:
return V_32 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
V_2 -> V_66 . V_67 = - 1 ;
if ( F_18 ( V_2 ) &&
! ( V_65 -> V_68 & V_69 ) )
return;
if ( V_2 -> V_26 & V_70 )
F_19 ( V_2 , V_65 -> V_68 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_71 * V_65 )
{
if ( V_65 -> V_72 ) {
V_2 -> V_73 = V_65 -> V_74 ;
V_2 -> V_75 &= ~ V_76 ;
V_2 -> V_75 =
V_65 -> V_77 << V_78 ;
}
}
static void F_21 ( struct V_1 * V_2 ,
struct V_79 * V_65 )
{
if ( V_2 -> V_66 . V_67 >= 0 &&
V_65 -> V_80 == V_2 -> V_81 )
V_2 -> V_66 . V_67 = F_22 ( V_65 -> V_82 ) * 10 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_83 * V_65 )
{
if ( V_65 -> V_84 )
V_2 -> V_85 = F_22 ( V_65 -> V_86 ) & V_87 ;
else
V_2 -> V_85 = 0 ;
}
static void F_24 ( struct V_1 * V_2 ,
T_2 V_88 , struct V_24 * V_65 )
{
T_1 V_89 = 0 ;
V_89 = ( V_88 >> V_90 ) &
V_91 ;
switch ( V_89 ) {
case V_92 :
F_20 ( V_2 ,
(struct V_71 * ) V_65 ) ;
break;
case V_93 :
F_21 ( V_2 ,
(struct V_79 * ) V_65 ) ;
break;
case V_94 :
F_23 ( V_2 ,
(struct V_83 * ) V_65 ) ;
break;
default:
F_15 ( & V_2 -> V_59 -> V_60 , L_3 ,
V_89 ) ;
break;
}
}
static void F_25 ( struct V_1 * V_2 ,
T_2 V_88 , struct V_24 * V_95 )
{
T_1 V_89 = 0 ;
struct V_96 * V_65 = (struct V_96 * ) V_95 ;
V_89 = ( V_88 >> V_90 ) &
V_91 ;
switch ( V_89 ) {
case V_97 :
if ( V_65 -> V_72 )
V_2 -> V_98 = F_22 ( V_65 -> V_99 ) ;
V_2 -> V_26 |= V_100 ;
break;
default:
F_15 ( & V_2 -> V_59 -> V_60 , L_4 ,
V_89 ) ;
break;
}
}
static inline bool F_26 ( T_2 V_88 )
{
return ( ( V_88 >> V_101 ) &
V_102 ) ==
V_103 ;
}
static inline bool F_27 ( T_2 V_88 )
{
return ( ( ( V_88 >> V_101 ) &
V_102 ) ==
V_104 ) ;
}
static inline bool F_28 ( T_2 V_88 )
{
return ( ( ( V_88 >> V_101 ) &
V_102 ) ==
V_105 ) ;
}
static struct V_24 * F_29 ( struct V_1 * V_2 )
{
struct V_14 * V_106 = & V_2 -> V_16 . V_107 ;
struct V_24 * V_25 = F_30 ( V_106 ) ;
if ( F_7 ( V_25 ) ) {
F_31 ( V_106 ) ;
return V_25 ;
}
return NULL ;
}
void F_32 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_108 ) ;
F_34 ( V_2 , V_2 -> V_16 . V_107 . V_19 , true , 0 ) ;
V_2 -> V_16 . V_109 = true ;
F_35 ( & V_2 -> V_108 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_108 ) ;
V_2 -> V_16 . V_109 = false ;
F_34 ( V_2 , V_2 -> V_16 . V_107 . V_19 , false , 0 ) ;
F_35 ( & V_2 -> V_108 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
int V_110 = 0 , V_35 = 0 ;
struct V_111 * V_16 = & V_2 -> V_16 ;
F_38 ( & V_2 -> V_108 ) ;
while ( ( V_25 = F_29 ( V_2 ) ) ) {
if ( V_25 -> V_26 & V_112 ) {
if ( F_26 ( V_25 -> V_26 ) )
F_17 ( V_2 ,
(struct V_64 * ) V_25 ) ;
else if ( F_27 ( V_25 -> V_26 ) )
F_24 ( V_2 ,
V_25 -> V_26 , V_25 ) ;
else if ( F_28 ( V_25 -> V_26 ) )
F_25 ( V_2 ,
V_25 -> V_26 , V_25 ) ;
} else if ( V_25 -> V_26 & V_113 ) {
V_35 = F_11 ( V_2 , V_25 ) ;
F_39 ( & V_16 -> V_17 . V_114 ) ;
}
F_9 ( V_25 ) ;
V_110 ++ ;
}
if ( V_110 )
F_34 ( V_2 , V_16 -> V_107 . V_19 , V_16 -> V_109 , V_110 ) ;
F_40 ( & V_2 -> V_108 ) ;
return V_35 ;
}
static int F_41 ( struct V_1 * V_2 )
{
#define F_42 120000
int V_5 , V_35 = 0 ;
struct V_111 * V_16 = & V_2 -> V_16 ;
for ( V_5 = 0 ; V_5 < F_42 ; V_5 ++ ) {
if ( F_4 ( V_2 ) )
return - V_115 ;
F_43 () ;
V_35 = F_37 ( V_2 ) ;
F_44 () ;
if ( F_45 ( & V_16 -> V_17 . V_114 ) == 0 )
break;
F_46 ( 100 ) ;
}
if ( V_5 == F_42 ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_5 ) ;
V_2 -> V_116 = true ;
return - V_115 ;
}
return V_35 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_35 ;
struct V_11 * V_12 ;
struct V_111 * V_16 = & V_2 -> V_16 ;
T_3 V_117 = V_16 -> V_17 . V_118 ;
struct V_28 * V_50 ;
F_48 ( & V_117 , V_16 -> V_17 . V_119 ) ;
V_12 = F_49 ( & V_16 -> V_17 , V_117 ) ;
V_50 = F_10 ( V_12 -> V_29 , V_12 -> V_30 ) ;
F_3 ( V_2 ) ;
V_35 = F_41 ( V_2 ) ;
if ( V_35 == - V_115 )
goto V_120;
V_35 = V_50 -> V_35 ;
V_120:
return V_35 ;
}
static int F_50 ( struct V_1 * V_2 , void T_4 * V_22 )
{
int V_121 = 0 ;
T_2 V_122 ;
do {
if ( F_4 ( V_2 ) )
return - V_115 ;
V_122 = F_51 ( V_22 ) ;
if ( V_122 == 0xffffffff )
return - 1 ;
V_122 &= V_123 ;
if ( V_122 )
break;
if ( V_121 > 4000 ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_5 ) ;
V_2 -> V_116 = true ;
F_52 ( V_2 ) ;
return - 1 ;
}
F_53 ( 1 ) ;
V_121 ++ ;
} while ( true );
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_35 ;
T_2 V_18 = 0 ;
void T_4 * V_22 = V_2 -> V_22 + V_124 ;
struct V_125 * V_126 = & V_2 -> V_126 ;
struct V_127 * V_128 = V_126 -> V_129 ;
struct V_24 * V_25 = & V_128 -> V_25 ;
V_35 = F_50 ( V_2 , V_22 ) ;
if ( V_35 != 0 )
return V_35 ;
V_18 |= V_130 ;
V_18 |= ( F_55 ( V_126 -> V_131 ) >> 2 ) << 2 ;
F_6 ( V_18 , V_22 ) ;
V_35 = F_50 ( V_2 , V_22 ) ;
if ( V_35 != 0 )
return V_35 ;
V_18 = 0 ;
V_18 |= ( T_2 ) ( V_126 -> V_131 >> 4 ) << 2 ;
F_6 ( V_18 , V_22 ) ;
V_35 = F_50 ( V_2 , V_22 ) ;
if ( V_35 != 0 )
return V_35 ;
if ( F_7 ( V_25 ) ) {
V_35 = F_11 ( V_2 , & V_128 -> V_25 ) ;
F_9 ( V_25 ) ;
if ( V_35 )
return V_35 ;
} else {
F_16 ( & V_2 -> V_59 -> V_60 , L_6 ) ;
return - 1 ;
}
return 0 ;
}
static T_3 F_56 ( struct V_1 * V_2 )
{
T_2 V_132 ;
if ( F_57 ( V_2 ) )
V_132 = F_51 ( V_2 -> V_133 + V_134 ) ;
else
F_58 ( V_2 -> V_59 ,
V_135 , & V_132 ) ;
return V_132 & V_136 ;
}
int F_59 ( struct V_1 * V_2 )
{
#define F_60 30
T_2 V_137 ;
int V_35 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < F_60 ; V_5 ++ ) {
V_137 = F_51 ( V_2 -> V_22 + V_138 ) ;
if ( V_137 & V_139 )
break;
F_53 ( 1000 ) ;
}
if ( V_5 == F_60 )
V_35 = - 1 ;
return V_35 ;
}
static bool F_61 ( struct V_1 * V_2 )
{
T_2 V_137 = 0 , V_140 = 0 , V_141 = 0 ;
V_137 = F_51 ( V_2 -> V_22 + V_138 ) ;
if ( V_137 & V_142 ) {
V_140 = F_51 ( V_2 -> V_22 +
V_143 ) ;
V_141 = F_51 ( V_2 -> V_22 +
V_144 ) ;
if ( V_140 == V_145 &&
V_141 == V_146 )
return true ;
}
return false ;
}
int F_62 ( struct V_1 * V_2 )
{
int V_35 ;
T_2 V_137 , V_147 , V_148 ;
bool V_149 ;
V_149 = F_61 ( V_2 ) ;
if ( V_149 )
return - V_150 ;
V_35 = F_59 ( V_2 ) ;
if ( ! V_35 ) {
V_137 = F_51 ( V_2 -> V_22 + V_138 ) ;
V_147 = V_137 & V_142 ;
V_148 = V_137 & V_151 ;
if ( V_147 && V_148 ) {
F_6 ( V_152 ,
V_2 -> V_22 + V_153 ) ;
V_35 = F_59 ( V_2 ) ;
V_137 = F_51 ( V_2 -> V_22 +
V_138 ) ;
V_137 &= ( V_142 |
V_151 ) ;
if ( V_35 || V_137 )
V_35 = - 1 ;
} else if ( V_147 || V_148 ) {
V_35 = - 1 ;
}
}
V_149 = F_61 ( V_2 ) ;
if ( V_149 )
V_35 = - V_150 ;
return V_35 ;
}
int F_63 ( struct V_1 * V_2 )
{
T_3 V_154 ;
int V_35 , V_155 = 0 ;
struct V_156 * V_60 = & V_2 -> V_59 -> V_60 ;
if ( F_18 ( V_2 ) ) {
V_35 = F_59 ( V_2 ) ;
return V_35 ;
}
do {
V_154 = F_56 ( V_2 ) ;
if ( V_154 == V_157 )
return 0 ;
F_64 ( V_60 , L_7 ,
V_155 ) ;
if ( F_65 ( 2000 ) ) {
F_16 ( V_60 , L_8 ) ;
return - V_158 ;
}
V_155 += 2 ;
} while ( V_155 < 60 );
F_16 ( V_60 , L_9 , V_154 ) ;
return - 1 ;
}
static inline struct V_159 * F_66 ( struct V_11 * V_12 )
{
return & V_12 -> V_13 . V_160 [ 0 ] ;
}
static inline void F_67 ( struct V_11 * V_12 ,
unsigned long V_31 )
{
V_12 -> V_29 = V_31 & 0xFFFFFFFF ;
V_12 -> V_30 = F_55 ( V_31 ) ;
}
static void F_68 ( struct V_161 * V_162 ,
T_1 V_4 , T_1 V_3 , int V_163 ,
struct V_11 * V_12 , struct V_125 * V_164 )
{
struct V_159 * V_165 ;
V_162 -> V_3 = V_3 ;
V_162 -> V_4 = V_4 ;
V_162 -> V_166 = F_69 ( V_163 - sizeof( * V_162 ) ) ;
V_162 -> V_167 = 0 ;
F_67 ( V_12 , ( V_168 ) V_162 ) ;
V_12 -> V_169 = V_163 ;
if ( V_164 ) {
V_12 -> V_170 |= ( 1 & V_171 ) <<
V_172 ;
V_165 = F_66 ( V_12 ) ;
V_165 -> V_173 = F_69 ( F_55 ( V_164 -> V_131 ) ) ;
V_165 -> V_174 = F_69 ( V_164 -> V_131 & 0xFFFFFFFF ) ;
V_165 -> V_119 = F_69 ( V_164 -> V_175 ) ;
} else
V_12 -> V_170 |= V_176 ;
F_70 ( V_12 , 8 ) ;
}
static void F_71 ( struct V_177 * V_178 , T_2 V_179 ,
struct V_125 * V_164 )
{
int V_5 , V_180 = F_72 ( F_73 ( V_164 -> V_129 , V_164 -> V_175 ) , V_179 ) ;
T_5 V_131 = ( T_5 ) V_164 -> V_131 ;
for ( V_5 = 0 ; V_5 < V_180 ; V_5 ++ ) {
V_178 [ V_5 ] . V_181 = F_69 ( V_131 & 0xFFFFFFFF ) ;
V_178 [ V_5 ] . V_182 = F_69 ( F_55 ( V_131 ) ) ;
V_131 += V_183 ;
}
}
static inline struct V_11 * F_74 ( struct V_1 * V_2 )
{
struct V_125 * V_126 = & V_2 -> V_126 ;
struct V_11 * V_12
= & ( (struct V_127 * ) ( V_126 -> V_129 ) ) -> V_12 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
static struct V_11 * F_75 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 . V_17 ;
struct V_11 * V_12 ;
if ( ! V_15 -> V_184 )
return NULL ;
if ( F_45 ( & V_15 -> V_114 ) >= V_15 -> V_119 )
return NULL ;
V_12 = F_76 ( V_15 ) ;
F_77 ( V_15 ) ;
F_78 ( & V_15 -> V_114 ) ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
static bool F_79 ( struct V_1 * V_2 )
{
return V_2 -> V_16 . V_17 . V_184 ;
}
static int F_80 ( struct V_1 * V_2 )
{
if ( F_79 ( V_2 ) ) {
F_33 ( & V_2 -> V_185 ) ;
return 0 ;
} else {
return F_81 ( & V_2 -> V_186 ) ;
}
}
static void F_82 ( struct V_1 * V_2 )
{
if ( F_79 ( V_2 ) )
F_35 ( & V_2 -> V_185 ) ;
else
return F_83 ( & V_2 -> V_186 ) ;
}
static struct V_11 * F_84 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_187 ;
if ( F_79 ( V_2 ) ) {
V_187 = F_75 ( V_2 ) ;
if ( ! V_187 )
return NULL ;
} else {
V_187 = F_74 ( V_2 ) ;
}
memcpy ( V_187 , V_12 , sizeof( * V_12 ) ) ;
if ( V_12 -> V_170 & F_69 ( V_176 ) )
F_67 ( V_187 , ( V_168 ) F_2 ( V_12 ) ) ;
return V_187 ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_187 ;
int V_35 ;
V_35 = F_80 ( V_2 ) ;
if ( V_35 )
return V_35 ;
V_187 = F_84 ( V_2 , V_12 ) ;
if ( ! V_187 )
return - V_188 ;
if ( F_79 ( V_2 ) )
V_35 = F_47 ( V_2 ) ;
else
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 )
memcpy ( V_12 , V_187 , sizeof( * V_12 ) ) ;
F_82 ( V_2 ) ;
return V_35 ;
}
int F_86 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_35 ;
if ( F_18 ( V_2 ) )
return 0 ;
if ( F_81 ( & V_2 -> V_186 ) )
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
F_83 ( & V_2 -> V_186 ) ;
return V_35 ;
}
int F_87 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_35 ;
if ( F_18 ( V_2 ) )
return 0 ;
if ( F_81 ( & V_2 -> V_186 ) )
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
F_83 ( & V_2 -> V_186 ) ;
return V_35 ;
}
int F_88 ( struct V_1 * V_2 , struct V_189 * V_190 )
{
struct V_11 * V_12 ;
struct V_191 * V_192 ;
struct V_125 * V_193 = & V_190 -> V_17 . V_194 ;
int V_35 , V_195 = 0 ;
if ( F_81 ( & V_2 -> V_186 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_197 , sizeof( * V_192 ) , V_12 , NULL ) ;
if ( ! ( F_57 ( V_2 ) || F_18 ( V_2 ) ) )
V_195 = 2 ;
V_192 -> V_196 . V_167 = V_195 ;
V_192 -> V_198 = F_89 ( F_73 ( V_193 -> V_129 , V_193 -> V_175 ) ) ;
F_90 ( struct V_199 , V_72 , V_192 -> V_200 , 1 ) ;
F_90 ( struct V_199 , V_175 , V_192 -> V_200 , 0 ) ;
F_90 ( struct V_199 , V_201 , V_192 -> V_200 ,
F_91 ( V_190 -> V_17 . V_119 / 256 ) ) ;
F_70 ( V_192 -> V_200 , sizeof( V_192 -> V_200 ) ) ;
F_71 ( V_192 -> V_178 , F_92 ( V_192 -> V_178 ) , V_193 ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_202 * V_50 = F_2 ( V_12 ) ;
V_190 -> V_17 . V_19 = F_22 ( V_50 -> V_203 ) ;
V_190 -> V_204 =
( V_195 == 2 ) ? F_22 ( V_50 -> V_204 ) : V_190 -> V_205 ;
V_190 -> V_17 . V_184 = true ;
}
F_83 ( & V_2 -> V_186 ) ;
return V_35 ;
}
int F_93 ( struct V_1 * V_2 , T_1 * V_206 ,
bool V_207 , T_2 V_208 , T_2 V_209 )
{
struct V_11 * V_12 ;
struct V_210 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_211 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> type = V_212 ;
if ( V_207 ) {
V_192 -> V_207 = 1 ;
} else {
V_192 -> V_213 = F_89 ( ( T_3 ) V_208 ) ;
V_192 -> V_209 = F_69 ( V_209 ) ;
V_192 -> V_207 = 0 ;
}
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_214 * V_50 = F_2 ( V_12 ) ;
memcpy ( V_206 , V_50 -> V_215 . V_31 , V_216 ) ;
}
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_94 ( struct V_1 * V_2 , T_1 * V_206 ,
T_2 V_213 , T_2 * V_209 , T_2 V_217 )
{
struct V_11 * V_12 ;
struct V_218 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_219 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_196 . V_217 = V_217 ;
V_192 -> V_213 = F_69 ( V_213 ) ;
memcpy ( V_192 -> V_220 , V_206 , V_216 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_221 * V_50 = F_2 ( V_12 ) ;
* V_209 = F_8 ( V_50 -> V_209 ) ;
}
V_147:
F_35 ( & V_2 -> V_185 ) ;
if ( V_35 == V_58 )
V_35 = - V_222 ;
return V_35 ;
}
int F_95 ( struct V_1 * V_2 , T_2 V_213 , int V_209 , T_2 V_223 )
{
struct V_11 * V_12 ;
struct V_224 * V_192 ;
int V_35 ;
if ( V_209 == - 1 )
return 0 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_225 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_196 . V_217 = V_223 ;
V_192 -> V_213 = F_69 ( V_213 ) ;
V_192 -> V_209 = F_69 ( V_209 ) ;
V_35 = F_47 ( V_2 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_96 ( struct V_1 * V_2 , struct V_14 * V_107 ,
struct V_14 * V_226 , bool V_227 , int V_228 )
{
struct V_11 * V_12 ;
struct V_229 * V_192 ;
struct V_125 * V_193 = & V_107 -> V_194 ;
void * V_230 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_186 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_192 = F_2 ( V_12 ) ;
V_230 = & V_192 -> V_200 ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_231 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_198 = F_89 ( F_73 ( V_193 -> V_129 , V_193 -> V_175 ) ) ;
if ( F_57 ( V_2 ) ) {
F_90 ( struct V_232 , V_233 , V_230 ,
V_228 ) ;
F_90 ( struct V_232 , V_234 ,
V_230 , V_227 ) ;
F_90 ( struct V_232 , V_201 , V_230 ,
F_91 ( V_107 -> V_119 / 256 ) ) ;
F_90 ( struct V_232 , V_72 , V_230 , 1 ) ;
F_90 ( struct V_232 , V_235 , V_230 , 1 ) ;
F_90 ( struct V_232 , V_236 , V_230 , V_226 -> V_19 ) ;
} else {
V_192 -> V_196 . V_167 = 2 ;
V_192 -> V_237 = 1 ;
F_90 ( struct V_238 , V_234 , V_230 ,
V_227 ) ;
F_90 ( struct V_238 , V_201 , V_230 ,
F_91 ( V_107 -> V_119 / 256 ) ) ;
F_90 ( struct V_238 , V_72 , V_230 , 1 ) ;
F_90 ( struct V_238 , V_235 ,
V_230 , 1 ) ;
F_90 ( struct V_238 , V_236 ,
V_230 , V_226 -> V_19 ) ;
}
F_70 ( V_230 , sizeof( V_192 -> V_200 ) ) ;
F_71 ( V_192 -> V_178 , F_92 ( V_192 -> V_178 ) , V_193 ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_239 * V_50 = F_2 ( V_12 ) ;
V_107 -> V_19 = F_22 ( V_50 -> V_240 ) ;
V_107 -> V_184 = true ;
}
F_83 ( & V_2 -> V_186 ) ;
return V_35 ;
}
static T_2 F_97 ( int V_241 )
{
T_2 V_242 = F_98 ( V_241 ) ;
if ( V_242 == 16 )
V_242 = 0 ;
return V_242 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_107 )
{
struct V_11 * V_12 ;
struct V_243 * V_192 ;
struct V_125 * V_193 = & V_15 -> V_194 ;
void * V_230 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_186 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_192 = F_2 ( V_12 ) ;
V_230 = & V_192 -> V_200 ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_244 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_198 = F_89 ( F_73 ( V_193 -> V_129 , V_193 -> V_175 ) ) ;
if ( F_18 ( V_2 ) ) {
V_192 -> V_196 . V_167 = 1 ;
V_192 -> V_240 = F_89 ( V_107 -> V_19 ) ;
F_90 ( struct V_245 , V_246 , V_230 ,
F_97 ( V_15 -> V_119 ) ) ;
F_90 ( struct V_245 , V_72 , V_230 , 1 ) ;
F_90 ( struct V_245 , V_247 ,
V_230 , V_107 -> V_19 ) ;
F_90 ( struct V_245 , V_248 ,
V_230 , 1 ) ;
} else {
F_90 ( struct V_249 , V_72 , V_230 , 1 ) ;
F_90 ( struct V_249 , V_246 , V_230 ,
F_97 ( V_15 -> V_119 ) ) ;
F_90 ( struct V_249 , V_240 , V_230 , V_107 -> V_19 ) ;
}
V_192 -> V_250 [ 0 ] = F_69 ( 0x00000022 ) ;
V_192 -> V_250 [ 0 ] |= F_69 ( 1 << V_105 ) ;
F_70 ( V_230 , sizeof( V_192 -> V_200 ) ) ;
F_71 ( V_192 -> V_178 , F_92 ( V_192 -> V_178 ) , V_193 ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_251 * V_50 = F_2 ( V_12 ) ;
V_15 -> V_19 = F_22 ( V_50 -> V_19 ) ;
V_15 -> V_184 = true ;
}
F_83 ( & V_2 -> V_186 ) ;
return V_35 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_107 )
{
struct V_11 * V_12 ;
struct V_252 * V_192 ;
struct V_125 * V_193 = & V_15 -> V_194 ;
void * V_230 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_186 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_192 = F_2 ( V_12 ) ;
V_230 = & V_192 -> V_200 ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_253 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_198 = F_89 ( F_73 ( V_193 -> V_129 , V_193 -> V_175 ) ) ;
F_90 ( struct V_249 , V_72 , V_230 , 1 ) ;
F_90 ( struct V_249 , V_246 , V_230 ,
F_97 ( V_15 -> V_119 ) ) ;
F_90 ( struct V_249 , V_240 , V_230 , V_107 -> V_19 ) ;
F_70 ( V_230 , sizeof( V_192 -> V_200 ) ) ;
F_71 ( V_192 -> V_178 , F_92 ( V_192 -> V_178 ) , V_193 ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_251 * V_50 = F_2 ( V_12 ) ;
V_15 -> V_19 = F_22 ( V_50 -> V_19 ) ;
V_15 -> V_184 = true ;
}
F_83 ( & V_2 -> V_186 ) ;
return V_35 ;
}
int F_101 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_107 )
{
int V_35 ;
V_35 = F_99 ( V_2 , V_15 , V_107 ) ;
if ( V_35 && ! F_18 ( V_2 ) ) {
F_15 ( & V_2 -> V_59 -> V_60 , L_10
L_11
L_12 ) ;
V_35 = F_100 ( V_2 , V_15 , V_107 ) ;
}
return V_35 ;
}
int F_102 ( struct V_1 * V_2 , struct V_254 * V_255 )
{
struct V_11 V_12 = { 0 } ;
struct V_256 * V_192 ;
struct V_14 * V_257 = & V_255 -> V_17 ;
struct V_14 * V_107 = & V_255 -> V_107 ;
struct V_125 * V_193 = & V_257 -> V_194 ;
int V_35 , V_195 = 0 ;
V_192 = F_2 ( & V_12 ) ;
F_68 ( & V_192 -> V_196 , V_46 ,
V_258 , sizeof( * V_192 ) , & V_12 , NULL ) ;
if ( F_18 ( V_2 ) ) {
V_192 -> V_196 . V_167 = 1 ;
} else if ( F_57 ( V_2 ) ) {
if ( V_2 -> V_259 & V_260 )
V_192 -> V_196 . V_167 = 2 ;
} else {
V_192 -> V_196 . V_167 = 2 ;
}
if ( V_192 -> V_196 . V_167 > 0 )
V_192 -> V_213 = F_89 ( V_2 -> V_208 ) ;
V_192 -> V_198 = F_73 ( V_193 -> V_129 , V_193 -> V_175 ) ;
V_192 -> V_261 = V_262 ;
V_192 -> type = V_263 ;
V_192 -> V_240 = F_89 ( V_107 -> V_19 ) ;
V_192 -> V_264 = F_97 ( V_257 -> V_119 ) ;
F_71 ( V_192 -> V_178 , F_92 ( V_192 -> V_178 ) , V_193 ) ;
V_195 = V_192 -> V_196 . V_167 ;
V_35 = F_85 ( V_2 , & V_12 ) ;
if ( ! V_35 ) {
struct V_265 * V_50 = F_2 ( & V_12 ) ;
V_257 -> V_19 = F_22 ( V_50 -> V_266 ) ;
if ( V_195 == 2 )
V_255 -> V_267 = F_8 ( V_50 -> V_267 ) ;
else
V_255 -> V_267 = V_268 ;
V_257 -> V_184 = true ;
}
return V_35 ;
}
int F_103 ( struct V_1 * V_2 ,
struct V_14 * V_269 , T_3 V_240 , T_3 V_270 ,
T_2 V_213 , T_2 V_271 , T_1 * V_272 )
{
struct V_11 * V_12 ;
struct V_273 * V_192 ;
struct V_125 * V_193 = & V_269 -> V_194 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_46 ,
V_274 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_240 = F_89 ( V_240 ) ;
V_192 -> V_270 = F_98 ( V_270 ) - 1 ;
V_192 -> V_198 = 2 ;
F_71 ( V_192 -> V_178 , F_92 ( V_192 -> V_178 ) , V_193 ) ;
V_192 -> V_275 = F_69 ( V_213 ) ;
V_192 -> V_276 = F_89 ( V_277 ) ;
V_192 -> V_278 = F_69 ( V_271 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_279 * V_50 = F_2 ( V_12 ) ;
V_269 -> V_19 = F_22 ( V_50 -> V_19 ) ;
V_269 -> V_184 = true ;
* V_272 = V_50 -> V_272 ;
}
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_104 ( struct V_1 * V_2 , struct V_14 * V_17 ,
int V_280 )
{
struct V_11 * V_12 ;
struct V_281 * V_192 ;
T_1 V_282 = 0 , V_3 = 0 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_186 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_192 = F_2 ( V_12 ) ;
switch ( V_280 ) {
case V_283 :
V_282 = V_40 ;
V_3 = V_284 ;
break;
case V_285 :
V_282 = V_40 ;
V_3 = V_286 ;
break;
case V_287 :
V_282 = V_46 ;
V_3 = V_288 ;
break;
case V_289 :
V_282 = V_46 ;
V_3 = V_290 ;
break;
case V_291 :
V_282 = V_40 ;
V_3 = V_292 ;
break;
default:
F_105 () ;
}
F_68 ( & V_192 -> V_196 , V_282 , V_3 , sizeof( * V_192 ) , V_12 ,
NULL ) ;
V_192 -> V_19 = F_89 ( V_17 -> V_19 ) ;
V_35 = F_54 ( V_2 ) ;
V_17 -> V_184 = false ;
F_83 ( & V_2 -> V_186 ) ;
return V_35 ;
}
int F_106 ( struct V_1 * V_2 , struct V_14 * V_17 )
{
struct V_11 * V_12 ;
struct V_281 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_46 ,
V_290 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_19 = F_89 ( V_17 -> V_19 ) ;
V_35 = F_47 ( V_2 ) ;
V_17 -> V_184 = false ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_107 ( struct V_1 * V_2 , T_2 V_293 , T_2 V_294 ,
T_2 * V_208 , T_2 V_217 )
{
struct V_11 V_12 = { 0 } ;
struct V_295 * V_192 ;
int V_35 ;
V_192 = F_2 ( & V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_296 , sizeof( * V_192 ) , & V_12 , NULL ) ;
V_192 -> V_196 . V_217 = V_217 ;
V_192 -> V_297 = F_69 ( V_293 ) ;
V_192 -> V_298 = F_69 ( V_294 ) ;
V_192 -> V_299 = true ;
V_35 = F_85 ( V_2 , & V_12 ) ;
if ( ! V_35 ) {
struct V_300 * V_50 = F_2 ( & V_12 ) ;
* V_208 = F_8 ( V_50 -> V_275 ) ;
if ( F_108 ( V_2 ) && ! F_109 ( V_2 ) )
V_2 -> V_209 [ 0 ] = F_8 ( V_50 -> V_209 ) ;
}
return V_35 ;
}
int F_110 ( struct V_1 * V_2 , int V_275 , T_2 V_217 )
{
struct V_11 * V_12 ;
struct V_301 * V_192 ;
int V_35 ;
if ( V_275 == - 1 )
return 0 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_302 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_196 . V_217 = V_217 ;
V_192 -> V_275 = F_69 ( V_275 ) ;
V_35 = F_47 ( V_2 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_111 ( struct V_1 * V_2 , struct V_125 * V_303 )
{
struct V_11 * V_12 ;
struct V_161 * V_196 ;
int V_35 = 0 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_196 = V_303 -> V_129 ;
F_68 ( V_196 , V_46 ,
V_44 , V_303 -> V_175 , V_12 , V_303 ) ;
if ( ! F_112 ( V_2 ) )
V_196 -> V_167 = 1 ;
F_3 ( V_2 ) ;
V_2 -> V_47 = true ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_113 ( struct V_1 * V_2 ,
struct V_125 * V_303 )
{
struct V_11 * V_12 ;
struct V_304 * V_192 ;
int V_35 = 0 ;
if ( ! F_1 ( V_2 , V_45 ,
V_46 ) )
return - V_222 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = V_303 -> V_129 ;
F_68 ( & V_192 -> V_196 , V_46 ,
V_45 , V_303 -> V_175 , V_12 ,
V_303 ) ;
V_192 -> V_305 . V_306 . V_307 = F_89 ( V_2 -> V_308 ) ;
V_192 -> V_305 . V_306 . V_309 = 0 ;
F_3 ( V_2 ) ;
V_2 -> V_47 = true ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
static int F_114 ( int V_310 )
{
switch ( V_310 ) {
case V_311 :
return 0 ;
case V_312 :
return 10 ;
case V_313 :
return 100 ;
case V_314 :
return 1000 ;
case V_315 :
return 10000 ;
case V_316 :
return 20000 ;
case V_317 :
return 25000 ;
case V_318 :
return 40000 ;
}
return 0 ;
}
int F_115 ( struct V_1 * V_2 , T_3 * V_67 ,
T_1 * V_319 , T_2 V_223 )
{
struct V_11 * V_12 ;
struct V_320 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
if ( V_319 )
* V_319 = V_321 ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_322 , sizeof( * V_192 ) , V_12 , NULL ) ;
if ( ! F_112 ( V_2 ) )
V_192 -> V_196 . V_167 = 1 ;
V_192 -> V_196 . V_217 = V_223 ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_323 * V_50 = F_2 ( V_12 ) ;
if ( V_67 ) {
* V_67 = V_50 -> V_67 ?
F_22 ( V_50 -> V_67 ) * 10 :
F_114 ( V_50 -> V_310 ) ;
if ( ! V_50 -> V_324 )
* V_67 = 0 ;
}
if ( V_319 )
* V_319 = V_50 -> V_324 ;
}
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_116 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_325 * V_192 ;
int V_35 = 0 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_48 , sizeof( * V_192 ) ,
V_12 , NULL ) ;
F_3 ( V_2 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_117 ( struct V_1 * V_2 , T_2 * V_326 )
{
struct V_11 * V_12 ;
struct V_327 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_328 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_329 = F_69 ( V_330 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_331 * V_50 = F_2 ( V_12 ) ;
if ( V_326 && V_50 -> V_326 )
* V_326 = F_8 ( V_50 -> V_326 ) -
sizeof( T_2 ) ;
}
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
void F_118 ( struct V_1 * V_2 , T_2 V_332 , void * V_333 )
{
struct V_125 V_334 ;
struct V_11 * V_12 ;
struct V_327 * V_192 ;
T_2 V_335 = 0 , V_336 , V_337 ,
V_338 = sizeof( T_2 ) , V_339 ;
int V_35 ;
if ( V_332 == 0 )
return;
V_336 = V_332 ;
V_334 . V_175 = sizeof( struct V_327 ) + 60 * 1024 ;
V_334 . V_129 = F_119 ( V_2 -> V_59 ,
V_334 . V_175 ,
& V_334 . V_131 ) ;
if ( ! V_334 . V_129 ) {
V_35 = - V_340 ;
F_16 ( & V_2 -> V_59 -> V_60 ,
L_13 ) ;
return;
}
F_33 ( & V_2 -> V_185 ) ;
while ( V_336 ) {
V_337 = F_72 ( V_336 , ( T_2 ) 60 * 1024 ) ;
V_336 -= V_337 ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = V_334 . V_129 ;
V_339 = sizeof( struct V_327 ) + V_337 ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_328 , V_339 , V_12 ,
& V_334 ) ;
V_192 -> V_329 = F_69 ( V_341 ) ;
V_192 -> V_342 = F_69 ( V_338 ) ;
V_192 -> V_343 = F_69 ( V_337 ) ;
V_192 -> V_344 = F_69 ( V_337 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_331 * V_50 = V_334 . V_129 ;
memcpy ( V_333 + V_335 ,
V_50 -> V_345 ,
F_8 ( V_50 -> V_343 ) ) ;
} else {
F_16 ( & V_2 -> V_59 -> V_60 , L_14 ) ;
goto V_147;
}
V_335 += V_337 ;
V_338 += V_337 ;
}
V_147:
F_120 ( V_2 -> V_59 , V_334 . V_175 ,
V_334 . V_129 ,
V_334 . V_131 ) ;
F_35 ( & V_2 -> V_185 ) ;
}
int F_121 ( struct V_1 * V_2 , char * V_346 ,
char * V_347 )
{
struct V_11 * V_12 ;
struct V_348 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_349 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_350 * V_50 = F_2 ( V_12 ) ;
strcpy ( V_346 , V_50 -> V_351 ) ;
if ( V_347 )
strcpy ( V_347 , V_50 -> V_352 ) ;
}
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_122 ( struct V_1 * V_2 , T_2 V_203 , T_2 V_353 )
{
struct V_11 * V_12 ;
struct V_354 * V_192 ;
int V_35 = 0 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_355 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_356 = F_69 ( 1 ) ;
V_192 -> V_357 [ 0 ] . V_203 = F_69 ( V_203 ) ;
V_192 -> V_357 [ 0 ] . V_358 = 0 ;
V_192 -> V_357 [ 0 ] . V_359 = F_69 ( V_353 ) ;
F_3 ( V_2 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_123 ( struct V_1 * V_2 , T_2 V_213 , T_3 * V_360 ,
T_2 V_110 , bool V_361 , bool V_362 )
{
struct V_11 * V_12 ;
struct V_363 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_364 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_275 = V_213 ;
V_192 -> V_362 = V_362 ;
V_192 -> V_361 = V_361 ;
V_192 -> V_365 = V_110 ;
if ( ! V_362 ) {
memcpy ( V_192 -> V_366 , V_360 ,
V_192 -> V_365 * sizeof( V_360 [ 0 ] ) ) ;
}
V_35 = F_47 ( V_2 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_124 ( struct V_1 * V_2 , T_2 V_26 , T_2 V_367 )
{
struct V_11 * V_12 ;
struct V_125 * V_164 = & V_2 -> V_368 ;
struct V_369 * V_192 = V_164 -> V_129 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
memset ( V_192 , 0 , sizeof( * V_192 ) ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_370 , sizeof( * V_192 ) ,
V_12 , V_164 ) ;
V_192 -> V_213 = F_69 ( V_2 -> V_208 ) ;
if ( V_26 & V_371 ) {
V_192 -> V_372 = F_69 ( V_373 |
V_374 |
V_375 ) ;
if ( V_367 == V_376 )
V_192 -> V_377 = F_69 ( V_373 |
V_374 |
V_375 ) ;
} else if ( V_26 & V_378 ) {
V_192 -> V_372 = V_192 -> V_377 =
F_69 ( V_375 ) ;
} else if ( V_26 & V_379 ) {
V_192 -> V_372 = F_69 ( V_374 ) ;
if ( V_367 == V_376 )
V_192 -> V_377 =
F_69 ( V_374 ) ;
} else {
struct V_380 * V_381 ;
int V_5 = 0 ;
V_192 -> V_372 = V_192 -> V_377 =
F_69 ( V_382 ) ;
V_192 -> V_372 |=
F_69 ( V_375 &
F_125 ( V_2 ) ) ;
V_192 -> V_383 = F_69 ( F_126 ( V_2 -> V_384 ) ) ;
F_127 (ha, adapter->netdev)
memcpy ( V_192 -> V_385 [ V_5 ++ ] . V_386 , V_381 -> V_31 , V_216 ) ;
}
V_35 = F_47 ( V_2 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_128 ( struct V_1 * V_2 , T_2 V_387 , T_2 V_388 )
{
struct V_11 * V_12 ;
struct V_389 * V_192 ;
int V_35 ;
if ( ! F_1 ( V_2 , V_390 ,
V_40 ) )
return - V_222 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_390 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_391 = F_89 ( ( T_3 ) V_387 ) ;
V_192 -> V_392 = F_89 ( ( T_3 ) V_388 ) ;
V_35 = F_47 ( V_2 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_129 ( struct V_1 * V_2 , T_2 * V_387 , T_2 * V_388 )
{
struct V_11 * V_12 ;
struct V_393 * V_192 ;
int V_35 ;
if ( ! F_1 ( V_2 , V_394 ,
V_40 ) )
return - V_222 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_394 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_395 * V_50 =
F_2 ( V_12 ) ;
* V_387 = F_22 ( V_50 -> V_391 ) ;
* V_388 = F_22 ( V_50 -> V_392 ) ;
}
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_130 ( struct V_1 * V_2 , T_2 * V_81 ,
T_2 * V_396 , T_2 * V_397 , T_3 * V_398 )
{
struct V_11 * V_12 ;
struct V_399 * V_192 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_186 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_400 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_401 * V_50 = F_2 ( V_12 ) ;
* V_81 = F_8 ( V_50 -> V_402 ) ;
* V_396 = F_8 ( V_50 -> V_403 ) ;
* V_397 = F_8 ( V_50 -> V_259 ) ;
* V_398 = F_8 ( V_50 -> V_404 ) & 0xFF ;
}
F_83 ( & V_2 -> V_186 ) ;
return V_35 ;
}
int F_131 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_161 * V_192 ;
int V_35 ;
if ( F_18 ( V_2 ) ) {
V_35 = F_59 ( V_2 ) ;
if ( ! V_35 ) {
F_6 ( V_152 ,
V_2 -> V_22 + V_153 ) ;
V_35 = F_62 ( V_2 ) ;
}
if ( V_35 ) {
F_16 ( & V_2 -> V_59 -> V_60 ,
L_15 ) ;
}
return V_35 ;
}
if ( F_81 ( & V_2 -> V_186 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_192 = F_2 ( V_12 ) ;
F_68 ( V_192 , V_40 ,
V_405 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_35 = F_54 ( V_2 ) ;
F_83 ( & V_2 -> V_186 ) ;
return V_35 ;
}
int F_132 ( struct V_1 * V_2 , T_1 * V_406 ,
T_2 V_407 , T_3 V_408 )
{
struct V_11 * V_12 ;
struct V_409 * V_192 ;
T_2 V_410 [ 10 ] = { 0x15d43fa5 , 0x2534685a , 0x5f87693a , 0x5668494e ,
0x33cf6a53 , 0x383334c6 , 0x76ac4257 , 0x59b242b2 ,
0x3ea83c02 , 0x4a110304 } ;
int V_35 ;
if ( F_81 ( & V_2 -> V_186 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_46 ,
V_411 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_213 = F_69 ( V_2 -> V_208 ) ;
V_192 -> V_412 = F_89 ( V_407 ) ;
V_192 -> V_413 = F_89 ( F_98 ( V_408 ) - 1 ) ;
if ( F_18 ( V_2 ) || F_133 ( V_2 ) )
V_192 -> V_196 . V_167 = 1 ;
memcpy ( V_192 -> V_414 , V_406 , V_408 ) ;
memcpy ( V_192 -> V_415 , V_410 , sizeof( V_410 ) ) ;
F_70 ( V_192 -> V_415 , sizeof( V_192 -> V_415 ) ) ;
V_35 = F_54 ( V_2 ) ;
F_83 ( & V_2 -> V_186 ) ;
return V_35 ;
}
int F_134 ( struct V_1 * V_2 , T_1 V_81 ,
T_1 V_416 , T_1 V_417 , T_1 V_418 )
{
struct V_11 * V_12 ;
struct V_419 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_420 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_81 = V_81 ;
V_192 -> V_421 = V_418 ;
V_192 -> V_422 = V_416 ;
V_192 -> V_423 = V_417 ;
V_35 = F_47 ( V_2 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_135 ( struct V_1 * V_2 , T_1 V_81 , T_2 * V_418 )
{
struct V_11 * V_12 ;
struct V_424 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_425 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_81 = V_81 ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_426 * V_50 =
F_2 ( V_12 ) ;
* V_418 = V_50 -> V_421 ;
}
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_136 ( struct V_1 * V_2 , struct V_125 * V_427 ,
T_2 V_428 , T_2 V_429 ,
const char * V_430 , T_2 * V_431 ,
T_1 * V_432 , T_1 * V_433 )
{
struct V_11 * V_12 ;
struct V_434 * V_192 ;
struct V_435 * V_50 ;
void * V_230 = NULL ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_2 -> V_41 = 0 ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_436;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_39 ,
sizeof( struct V_434 ) , V_12 ,
NULL ) ;
V_230 = & V_192 -> V_200 ;
F_90 ( struct V_437 ,
V_438 , V_230 , V_428 ) ;
if ( V_428 == 0 )
F_90 ( struct V_437 ,
V_439 , V_230 , 1 ) ;
else
F_90 ( struct V_437 ,
V_439 , V_230 , 0 ) ;
F_70 ( V_230 , sizeof( V_192 -> V_200 ) ) ;
V_192 -> V_440 = F_69 ( V_429 ) ;
strcpy ( V_192 -> V_441 , V_430 ) ;
V_192 -> V_442 = F_69 ( 1 ) ;
V_192 -> V_332 = F_69 ( V_428 ) ;
V_192 -> V_443 = F_69 ( ( V_427 -> V_131 +
sizeof( struct V_434 ) )
& 0xFFFFFFFF ) ;
V_192 -> V_444 = F_69 ( F_55 ( V_427 -> V_131 +
sizeof( struct V_434 ) ) ) ;
F_3 ( V_2 ) ;
F_35 ( & V_2 -> V_185 ) ;
if ( ! F_137 ( & V_2 -> V_42 ,
F_138 ( 60000 ) ) )
V_35 = - 1 ;
else
V_35 = V_2 -> V_41 ;
V_50 = F_2 ( V_12 ) ;
if ( ! V_35 ) {
* V_431 = F_8 ( V_50 -> V_445 ) ;
* V_432 = V_50 -> V_432 ;
} else {
* V_433 = V_50 -> V_446 ;
}
return V_35 ;
V_436:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_139 ( struct V_1 * V_2 , struct V_125 * V_427 ,
T_2 V_428 , T_2 V_429 , const char * V_430 ,
T_2 * V_447 , T_2 * V_439 , T_1 * V_433 )
{
struct V_11 * V_12 ;
struct V_448 * V_192 ;
struct V_449 * V_50 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_436;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_450 ,
sizeof( struct V_448 ) , V_12 ,
NULL ) ;
V_192 -> V_451 = F_69 ( V_428 ) ;
V_192 -> V_452 = F_69 ( V_429 ) ;
strcpy ( V_192 -> V_441 , V_430 ) ;
V_192 -> V_442 = F_69 ( 1 ) ;
V_192 -> V_332 = F_69 ( V_428 ) ;
V_192 -> V_443 = F_69 ( ( V_427 -> V_131 & 0xFFFFFFFF ) ) ;
V_192 -> V_444 = F_69 ( F_55 ( V_427 -> V_131 ) ) ;
V_35 = F_47 ( V_2 ) ;
V_50 = F_2 ( V_12 ) ;
if ( ! V_35 ) {
* V_447 = F_8 ( V_50 -> V_453 ) ;
* V_439 = F_8 ( V_50 -> V_439 ) ;
} else {
* V_433 = V_50 -> V_446 ;
}
V_436:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_140 ( struct V_1 * V_2 , struct V_125 * V_427 ,
T_2 V_454 , T_2 V_455 , T_2 V_337 )
{
struct V_11 * V_12 ;
struct F_140 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_2 -> V_41 = 0 ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_436;
}
V_192 = V_427 -> V_129 ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_38 , V_427 -> V_175 , V_12 , V_427 ) ;
V_192 -> V_306 . V_456 = F_69 ( V_454 ) ;
V_192 -> V_306 . V_457 = F_69 ( V_455 ) ;
V_192 -> V_306 . V_458 = F_69 ( V_337 ) ;
F_3 ( V_2 ) ;
F_35 ( & V_2 -> V_185 ) ;
if ( ! F_137 ( & V_2 -> V_42 ,
F_138 ( 40000 ) ) )
V_35 = - 1 ;
else
V_35 = V_2 -> V_41 ;
return V_35 ;
V_436:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_141 ( struct V_1 * V_2 , T_1 * V_459 ,
int V_335 )
{
struct V_11 * V_12 ;
struct V_460 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_461 , sizeof( * V_192 ) ,
V_12 , NULL ) ;
V_192 -> V_306 . V_456 = F_69 ( V_462 ) ;
V_192 -> V_306 . V_457 = F_69 ( V_463 ) ;
V_192 -> V_306 . V_335 = F_69 ( V_335 ) ;
V_192 -> V_306 . V_458 = F_69 ( 0x4 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 )
memcpy ( V_459 , V_192 -> V_464 , 4 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_142 ( struct V_1 * V_2 , T_1 * V_215 ,
struct V_125 * V_303 )
{
struct V_11 * V_12 ;
struct V_465 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = V_303 -> V_129 ;
F_68 ( & V_192 -> V_196 , V_46 ,
V_466 , sizeof( * V_192 ) , V_12 ,
V_303 ) ;
memcpy ( V_192 -> V_467 , V_215 , V_216 ) ;
V_35 = F_47 ( V_2 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_143 ( struct V_1 * V_2 , T_1 V_81 ,
T_1 V_468 , T_1 V_469 )
{
struct V_11 * V_12 ;
struct V_470 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_471 ,
V_472 , sizeof( * V_192 ) , V_12 ,
NULL ) ;
V_192 -> V_473 = V_81 ;
V_192 -> V_474 = V_81 ;
V_192 -> V_468 = V_468 ;
V_192 -> V_475 = V_469 ;
V_35 = F_47 ( V_2 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_144 ( struct V_1 * V_2 , T_2 V_81 ,
T_2 V_468 , T_2 V_476 , T_2 V_477 , T_5 V_478 )
{
struct V_11 * V_12 ;
struct V_479 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_471 ,
V_480 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_196 . V_155 = F_69 ( 4 ) ;
V_192 -> V_478 = F_145 ( V_478 ) ;
V_192 -> V_473 = F_69 ( V_81 ) ;
V_192 -> V_474 = F_69 ( V_81 ) ;
V_192 -> V_476 = F_69 ( V_476 ) ;
V_192 -> V_477 = F_69 ( V_477 ) ;
V_192 -> V_468 = F_69 ( V_468 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_481 * V_50 = F_2 ( V_12 ) ;
V_35 = F_8 ( V_50 -> V_35 ) ;
}
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_146 ( struct V_1 * V_2 , T_5 V_478 ,
T_2 V_482 , struct V_125 * V_427 )
{
struct V_11 * V_12 ;
struct V_483 * V_192 ;
int V_35 ;
int V_5 , V_484 = 0 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = V_427 -> V_129 ;
F_68 ( & V_192 -> V_196 , V_471 ,
V_485 , V_427 -> V_175 , V_12 , V_427 ) ;
V_192 -> V_478 = F_145 ( V_478 ) ;
V_192 -> V_486 = F_69 ( V_482 ) ;
for ( V_5 = 0 ; V_5 < V_482 ; V_5 ++ ) {
V_192 -> V_487 [ V_5 ] = ( T_1 ) ( V_478 >> ( V_484 * 8 ) ) ;
V_484 ++ ;
if ( V_484 > 7 )
V_484 = 0 ;
}
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_488 * V_50 ;
V_50 = V_427 -> V_129 ;
if ( ( memcmp ( V_50 -> V_489 , V_192 -> V_487 , V_482 ) != 0 ) ||
V_50 -> V_490 ) {
V_35 = - 1 ;
}
}
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_147 ( struct V_1 * V_2 ,
struct V_125 * V_303 )
{
struct V_11 * V_12 ;
struct V_491 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = V_303 -> V_129 ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_492 , sizeof( * V_192 ) , V_12 ,
V_303 ) ;
V_35 = F_47 ( V_2 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_148 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_493 * V_192 ;
struct V_125 V_427 ;
int V_35 ;
if ( ! F_1 ( V_2 , V_494 ,
V_40 ) )
return - V_222 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_427 . V_175 = sizeof( struct V_493 ) ;
V_427 . V_129 = F_119 ( V_2 -> V_59 , V_427 . V_175 ,
& V_427 . V_131 ) ;
if ( ! V_427 . V_129 ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_16 ) ;
V_35 = - V_340 ;
goto V_147;
}
V_192 = V_427 . V_129 ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_494 , sizeof( * V_192 ) ,
V_12 , & V_427 ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_495 * V_496 =
V_427 . V_129 + sizeof( struct V_161 ) ;
V_2 -> V_66 . V_497 = F_22 ( V_496 -> V_497 ) ;
V_2 -> V_66 . V_498 =
F_22 ( V_496 -> V_498 ) ;
V_2 -> V_66 . V_499 =
F_22 ( V_496 -> V_499 ) ;
V_2 -> V_66 . V_500 =
F_22 ( V_496 -> V_500 ) ;
V_2 -> V_66 . V_501 =
F_8 ( V_496 -> V_501 ) ;
if ( F_112 ( V_2 ) ) {
V_2 -> V_66 . V_500 =
V_502 |
V_503 ;
}
}
F_120 ( V_2 -> V_59 , V_427 . V_175 ,
V_427 . V_129 , V_427 . V_131 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_149 ( struct V_1 * V_2 , T_2 V_504 , T_2 V_217 )
{
struct V_11 * V_12 ;
struct V_505 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_506 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_196 . V_217 = V_217 ;
V_192 -> V_507 = F_69 ( V_508 ) ;
V_192 -> V_509 = F_69 ( V_504 ) ;
V_35 = F_47 ( V_2 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_150 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_510 * V_192 ;
struct V_511 * V_50 ;
int V_35 ;
int V_339 = F_151 ( sizeof( * V_192 ) , sizeof( * V_50 ) ) ;
struct V_512 * V_513 ;
struct V_125 V_514 ;
if ( F_81 ( & V_2 -> V_186 ) )
return - 1 ;
memset ( & V_514 , 0 , sizeof( struct V_125 ) ) ;
V_514 . V_175 = sizeof( struct V_511 ) ;
V_514 . V_129 = F_119 ( V_2 -> V_59 , V_514 . V_175 ,
& V_514 . V_131 ) ;
if ( ! V_514 . V_129 ) {
F_16 ( & V_2 -> V_59 -> V_60 ,
L_17 ) ;
V_35 = - V_340 ;
goto V_147;
}
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = V_514 . V_129 ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_515 , V_339 , V_12 ,
& V_514 ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
V_513 = V_514 . V_129 + sizeof( struct V_28 ) ;
V_2 -> V_308 = V_513 -> V_516 . V_517 ;
}
V_147:
F_83 ( & V_2 -> V_186 ) ;
if ( V_514 . V_129 )
F_120 ( V_2 -> V_59 , V_514 . V_175 ,
V_514 . V_129 , V_514 . V_131 ) ;
return V_35 ;
}
int F_152 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_518 * V_192 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_186 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_519 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_520 = F_69 ( V_521 |
V_522 ) ;
V_192 -> V_293 = F_69 ( V_522 ) ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_523 * V_50 = F_2 ( V_12 ) ;
V_2 -> V_524 = F_8 ( V_50 -> V_293 ) &
V_522 ;
if ( ! V_2 -> V_524 )
F_15 ( & V_2 -> V_59 -> V_60 ,
L_18 ) ;
}
V_147:
F_83 ( & V_2 -> V_186 ) ;
return V_35 ;
}
int F_153 ( struct V_1 * V_2 , T_2 * V_525 ,
T_2 V_217 )
{
struct V_11 * V_12 ;
struct V_526 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_527 , sizeof( * V_192 ) ,
V_12 , NULL ) ;
V_192 -> V_196 . V_217 = V_217 ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_528 * V_50 =
F_2 ( V_12 ) ;
* V_525 = F_8 ( V_50 -> V_529 ) ;
}
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_154 ( struct V_1 * V_2 , T_2 V_530 ,
T_2 V_217 )
{
struct V_11 * V_12 ;
struct V_531 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_532 , sizeof( * V_192 ) ,
V_12 , NULL ) ;
V_192 -> V_196 . V_217 = V_217 ;
if ( F_18 ( V_2 ) )
V_192 -> V_533 = F_69 ( V_530 ) ;
else
V_192 -> V_530 = F_69 ( V_530 ) ;
V_35 = F_47 ( V_2 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_155 ( struct V_1 * V_2 , T_1 * V_215 ,
bool * V_534 , T_2 * V_209 , T_1 V_217 )
{
struct V_11 * V_12 ;
struct V_535 * V_192 ;
int V_35 ;
int V_536 ;
struct V_125 V_537 ;
int V_5 ;
memset ( & V_537 , 0 , sizeof( struct V_125 ) ) ;
V_537 . V_175 = sizeof( struct V_538 ) ;
V_537 . V_129 = F_119 ( V_2 -> V_59 ,
V_537 . V_175 ,
& V_537 . V_131 ) ;
if ( ! V_537 . V_129 ) {
F_16 ( & V_2 -> V_59 -> V_60 ,
L_19 ) ;
return - V_340 ;
}
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_120;
}
V_192 = V_537 . V_129 ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_539 ,
V_537 . V_175 , V_12 , & V_537 ) ;
V_192 -> V_196 . V_217 = V_217 ;
V_192 -> V_540 = V_212 ;
if ( * V_534 ) {
V_192 -> V_541 = F_69 ( * V_209 ) ;
V_192 -> V_542 = F_89 ( V_2 -> V_208 ) ;
V_192 -> V_543 = 0 ;
} else {
V_192 -> V_543 = 1 ;
}
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_538 * V_50 =
V_537 . V_129 ;
if ( * V_534 ) {
memcpy ( V_215 , V_50 -> V_544 . V_545 . V_546 ,
V_216 ) ;
goto V_120;
}
V_536 = V_50 -> V_547 + V_50 -> V_548 ;
for ( V_5 = 0 ; V_5 < V_536 ; V_5 ++ ) {
struct V_549 * V_550 ;
T_3 V_551 ;
T_2 V_541 ;
V_550 = & V_50 -> V_552 [ V_5 ] ;
V_551 = F_22 ( V_550 -> V_551 ) ;
if ( V_551 == sizeof( T_2 ) ) {
* V_534 = true ;
V_541 = V_550 -> V_545 . V_553 . V_541 ;
* V_209 = F_8 ( V_541 ) ;
goto V_120;
}
}
* V_534 = false ;
memcpy ( V_215 , V_50 -> V_552 [ 0 ] . V_545 . V_546 ,
V_216 ) ;
}
V_120:
F_35 ( & V_2 -> V_185 ) ;
F_120 ( V_2 -> V_59 , V_537 . V_175 ,
V_537 . V_129 , V_537 . V_131 ) ;
return V_35 ;
}
int F_156 ( struct V_1 * V_2 , T_2 V_554 , T_1 * V_215 )
{
bool V_555 = true ;
if ( F_57 ( V_2 ) )
return F_93 ( V_2 , V_215 , false ,
V_2 -> V_208 , V_554 ) ;
else
return F_155 ( V_2 , V_215 , & V_555 ,
& V_554 , 0 ) ;
}
int F_157 ( struct V_1 * V_2 , T_1 * V_215 )
{
int V_35 ;
bool V_556 = false ;
memset ( V_215 , 0 , V_216 ) ;
if ( F_57 ( V_2 ) ) {
if ( F_109 ( V_2 ) )
V_35 = F_93 ( V_2 , V_215 , true , 0 ,
0 ) ;
else
V_35 = F_93 ( V_2 , V_215 , false ,
V_2 -> V_208 , 0 ) ;
} else {
V_35 = F_155 ( V_2 , V_215 , & V_556 ,
NULL , 0 ) ;
}
return V_35 ;
}
int F_158 ( struct V_1 * V_2 , T_1 * V_557 ,
T_1 V_536 , T_2 V_217 )
{
struct V_11 * V_12 ;
struct V_558 * V_192 ;
int V_35 ;
struct V_125 V_427 ;
memset ( & V_427 , 0 , sizeof( struct V_125 ) ) ;
V_427 . V_175 = sizeof( struct V_558 ) ;
V_427 . V_129 = F_159 ( & V_2 -> V_59 -> V_60 , V_427 . V_175 ,
& V_427 . V_131 , V_559 ) ;
if ( ! V_427 . V_129 )
return - V_340 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = V_427 . V_129 ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_560 , sizeof( * V_192 ) ,
V_12 , & V_427 ) ;
V_192 -> V_196 . V_217 = V_217 ;
V_192 -> V_536 = V_536 ;
if ( V_536 )
memcpy ( V_192 -> V_215 , V_557 , V_216 * V_536 ) ;
V_35 = F_47 ( V_2 ) ;
V_147:
F_160 ( & V_2 -> V_59 -> V_60 , V_427 . V_175 ,
V_427 . V_129 , V_427 . V_131 ) ;
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_161 ( struct V_1 * V_2 , T_1 * V_215 , int V_213 , T_2 V_223 )
{
bool V_561 = false ;
T_1 V_562 [ V_216 ] ;
T_2 V_209 ;
int V_35 ;
V_35 = F_155 ( V_2 , V_562 , & V_561 ,
& V_209 , V_223 ) ;
if ( ! V_35 && V_561 )
F_95 ( V_2 , V_213 , V_209 , V_223 ) ;
return F_158 ( V_2 , V_215 , V_215 ? 1 : 0 , V_223 ) ;
}
int F_162 ( struct V_1 * V_2 , T_3 V_85 ,
T_2 V_217 , T_3 V_563 , T_3 V_564 )
{
struct V_11 * V_12 ;
struct V_565 * V_192 ;
void * V_230 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
V_230 = & V_192 -> V_200 ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_566 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_196 . V_217 = V_217 ;
F_90 ( struct V_567 , V_275 , V_230 , V_563 ) ;
if ( V_85 ) {
F_90 ( struct V_567 , V_568 , V_230 , 1 ) ;
F_90 ( struct V_567 , V_85 , V_230 , V_85 ) ;
}
if ( ! F_57 ( V_2 ) && V_564 ) {
F_90 ( struct V_567 , V_275 ,
V_230 , V_2 -> V_308 ) ;
F_90 ( struct V_567 , V_569 , V_230 , 1 ) ;
F_90 ( struct V_567 , V_570 ,
V_230 , V_564 ) ;
}
F_70 ( V_192 -> V_200 , sizeof( V_192 -> V_200 ) ) ;
V_35 = F_47 ( V_2 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_163 ( struct V_1 * V_2 , T_3 * V_85 ,
T_2 V_217 , T_3 V_563 , T_1 * V_396 )
{
struct V_11 * V_12 ;
struct V_571 * V_192 ;
void * V_230 ;
int V_35 ;
T_3 V_572 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
V_230 = & V_192 -> V_200 ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_573 , sizeof( * V_192 ) , V_12 , NULL ) ;
V_192 -> V_196 . V_217 = V_217 ;
F_90 ( struct V_574 , V_275 ,
V_230 , V_563 ) ;
F_90 ( struct V_574 , V_568 , V_230 , 1 ) ;
if ( ! F_57 ( V_2 ) ) {
F_90 ( struct V_574 , V_275 ,
V_230 , V_2 -> V_308 ) ;
F_90 ( struct V_574 , V_569 , V_230 , 1 ) ;
}
F_70 ( V_192 -> V_200 , sizeof( V_192 -> V_200 ) ) ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_575 * V_50 =
F_2 ( V_12 ) ;
F_12 ( & V_50 -> V_200 ,
sizeof( V_50 -> V_200 ) ) ;
V_572 = F_164 ( struct V_576 ,
V_85 , & V_50 -> V_200 ) ;
if ( V_85 )
* V_85 = F_22 ( V_572 ) ;
if ( V_396 )
* V_396 = F_164 ( struct V_576 ,
V_570 , & V_50 -> V_200 ) ;
}
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_165 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_577 * V_192 ;
int V_35 ;
int V_339 = sizeof( * V_192 ) ;
struct V_125 V_427 ;
if ( ! F_1 ( V_2 , V_466 ,
V_46 ) )
return - V_222 ;
if ( F_81 ( & V_2 -> V_186 ) )
return - 1 ;
memset ( & V_427 , 0 , sizeof( struct V_125 ) ) ;
V_427 . V_175 = sizeof( struct V_578 ) ;
V_427 . V_129 = F_119 ( V_2 -> V_59 , V_427 . V_175 ,
& V_427 . V_131 ) ;
if ( ! V_427 . V_129 ) {
F_16 ( & V_2 -> V_59 -> V_60 ,
L_17 ) ;
V_35 = - V_340 ;
goto V_147;
}
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = V_427 . V_129 ;
F_68 ( & V_192 -> V_196 , V_46 ,
V_466 ,
V_339 , V_12 , & V_427 ) ;
V_192 -> V_196 . V_167 = 1 ;
V_192 -> V_579 = V_580 ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_578 * V_50 ;
V_50 = (struct V_578 * ) V_427 . V_129 ;
if ( V_50 -> V_196 . V_581 < V_339 ) {
V_35 = - 1 ;
goto V_147;
}
V_2 -> V_582 = V_50 -> V_583 ;
}
V_147:
F_83 ( & V_2 -> V_186 ) ;
if ( V_427 . V_129 )
F_120 ( V_2 -> V_59 , V_427 . V_175 , V_427 . V_129 , V_427 . V_131 ) ;
return V_35 ;
}
int F_166 ( struct V_1 * V_2 ,
struct V_125 * V_427 )
{
struct V_11 * V_12 ;
struct V_584 * V_192 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_186 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = V_427 -> V_129 ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_585 ,
V_427 -> V_175 , V_12 , V_427 ) ;
V_192 -> V_586 = F_69 ( 1 ) ;
V_35 = F_54 ( V_2 ) ;
V_147:
F_83 ( & V_2 -> V_186 ) ;
return V_35 ;
}
int F_167 ( struct V_1 * V_2 ,
struct V_125 * V_427 ,
struct V_587 * V_588 )
{
struct V_11 * V_12 ;
struct V_589 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = V_427 -> V_129 ;
memcpy ( & V_192 -> V_590 , V_588 , sizeof( struct V_587 ) ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_591 ,
V_427 -> V_175 , V_12 , V_427 ) ;
V_35 = F_47 ( V_2 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_168 ( struct V_1 * V_2 , T_1 * V_592 )
{
struct V_11 * V_12 ;
struct V_593 * V_192 ;
int V_35 ;
if ( ! F_18 ( V_2 ) ) {
* V_592 = V_2 -> V_308 + '0' ;
return 0 ;
}
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_594 , sizeof( * V_192 ) , V_12 ,
NULL ) ;
V_192 -> V_196 . V_167 = 1 ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
struct V_595 * V_50 = F_2 ( V_12 ) ;
* V_592 = V_50 -> V_592 [ V_2 -> V_308 ] ;
} else {
* V_592 = V_2 -> V_308 + '0' ;
}
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
static struct V_596 * F_169 ( T_1 * V_333 , T_2 V_597 )
{
struct V_598 * V_196 = (struct V_598 * ) V_333 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_597 ; V_5 ++ ) {
if ( V_196 -> V_599 == V_600 ||
V_196 -> V_599 == V_601 )
return (struct V_596 * ) V_196 ;
V_196 -> V_602 = V_196 -> V_602 ? : V_603 ;
V_196 = ( void * ) V_196 + V_196 -> V_602 ;
}
return NULL ;
}
static struct V_604 * F_170 ( T_1 V_605 , T_1 * V_333 ,
T_2 V_597 )
{
struct V_598 * V_196 = (struct V_598 * ) V_333 ;
struct V_604 * V_606 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_597 ; V_5 ++ ) {
if ( ( V_196 -> V_599 == V_607 ||
V_196 -> V_599 == V_608 ) ) {
V_606 = (struct V_604 * ) V_196 ;
if ( V_606 -> V_609 == V_605 )
return V_606 ;
}
V_196 -> V_602 = V_196 -> V_602 ? : V_603 ;
V_196 = ( void * ) V_196 + V_196 -> V_602 ;
}
return NULL ;
}
static void F_171 ( struct V_610 * V_611 ,
struct V_596 * V_612 )
{
V_611 -> V_613 = F_22 ( V_612 -> V_614 ) ;
V_611 -> V_615 = F_22 ( V_612 -> V_616 ) ;
V_611 -> V_617 = F_22 ( V_612 -> V_618 ) ;
V_611 -> V_619 = F_22 ( V_612 -> V_620 ) ;
V_611 -> V_621 = F_22 ( V_612 -> V_622 ) ;
V_611 -> V_623 = F_22 ( V_612 -> V_624 ) ;
V_611 -> V_625 = F_22 ( V_612 -> V_626 ) ;
V_611 -> V_627 = F_8 ( V_612 -> V_293 ) &
V_628 ;
if ( V_611 -> V_621 && V_611 -> V_621 == V_611 -> V_623 )
V_611 -> V_621 -= 1 ;
}
int F_172 ( struct V_1 * V_2 , struct V_610 * V_611 )
{
struct V_11 * V_12 ;
struct V_629 * V_192 ;
int V_35 ;
struct V_125 V_427 ;
if ( F_81 ( & V_2 -> V_186 ) )
return - 1 ;
memset ( & V_427 , 0 , sizeof( struct V_125 ) ) ;
V_427 . V_175 = sizeof( struct V_630 ) ;
V_427 . V_129 = F_119 ( V_2 -> V_59 , V_427 . V_175 ,
& V_427 . V_131 ) ;
if ( ! V_427 . V_129 ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_16 ) ;
V_35 = - V_340 ;
goto V_147;
}
V_12 = F_74 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = V_427 . V_129 ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_631 ,
V_427 . V_175 , V_12 , & V_427 ) ;
if ( F_133 ( V_2 ) )
V_192 -> V_196 . V_167 = 1 ;
V_35 = F_54 ( V_2 ) ;
if ( ! V_35 ) {
struct V_630 * V_50 = V_427 . V_129 ;
T_2 V_597 = F_8 ( V_50 -> V_597 ) ;
struct V_596 * V_612 ;
V_612 = F_169 ( V_50 -> V_632 , V_597 ) ;
if ( ! V_612 ) {
V_35 = - V_633 ;
goto V_147;
}
V_2 -> V_634 = V_612 -> V_609 ;
F_171 ( V_611 , V_612 ) ;
}
V_147:
F_83 ( & V_2 -> V_186 ) ;
if ( V_427 . V_129 )
F_120 ( V_2 -> V_59 , V_427 . V_175 , V_427 . V_129 , V_427 . V_131 ) ;
return V_35 ;
}
static int F_173 ( struct V_1 * V_2 ,
T_1 V_217 , struct V_125 * V_427 )
{
struct V_11 * V_12 ;
struct V_635 * V_192 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_186 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_192 = V_427 -> V_129 ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_636 ,
V_427 -> V_175 , V_12 , V_427 ) ;
V_192 -> type = V_637 ;
V_192 -> V_196 . V_217 = V_217 ;
if ( ! F_18 ( V_2 ) )
V_192 -> V_196 . V_167 = 1 ;
V_35 = F_54 ( V_2 ) ;
F_83 ( & V_2 -> V_186 ) ;
return V_35 ;
}
static int F_174 ( struct V_1 * V_2 ,
T_1 V_217 , struct V_125 * V_427 )
{
struct V_11 * V_12 ;
struct V_635 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = V_427 -> V_129 ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_636 ,
V_427 -> V_175 , V_12 , V_427 ) ;
V_192 -> type = V_637 ;
V_192 -> V_196 . V_217 = V_217 ;
if ( ! F_18 ( V_2 ) )
V_192 -> V_196 . V_167 = 1 ;
V_35 = F_47 ( V_2 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_175 ( struct V_1 * V_2 ,
struct V_610 * V_611 , T_1 V_217 )
{
struct V_638 * V_50 ;
struct V_604 * V_606 ;
struct V_596 * V_639 ;
struct V_14 * V_15 = & V_2 -> V_16 . V_17 ;
struct V_125 V_427 ;
T_2 V_597 ;
int V_35 ;
memset ( & V_427 , 0 , sizeof( struct V_125 ) ) ;
V_427 . V_175 = sizeof( struct V_638 ) ;
V_427 . V_129 = F_119 ( V_2 -> V_59 , V_427 . V_175 , & V_427 . V_131 ) ;
if ( ! V_427 . V_129 )
return - V_340 ;
if ( ! V_15 -> V_184 )
V_35 = F_173 ( V_2 , V_217 , & V_427 ) ;
else
V_35 = F_174 ( V_2 , V_217 , & V_427 ) ;
if ( V_35 )
goto V_147;
V_50 = V_427 . V_129 ;
V_597 = F_8 ( V_50 -> V_597 ) ;
V_606 = F_170 ( V_2 -> V_59 -> V_605 , V_50 -> V_632 ,
V_597 ) ;
if ( V_606 )
V_611 -> V_640 = F_22 ( V_606 -> V_641 ) ;
V_639 = F_169 ( V_50 -> V_632 , V_597 ) ;
if ( V_639 )
F_171 ( V_611 , V_639 ) ;
V_147:
if ( V_427 . V_129 )
F_120 ( V_2 -> V_59 , V_427 . V_175 , V_427 . V_129 , V_427 . V_131 ) ;
return V_35 ;
}
int F_176 ( struct V_1 * V_2 , T_2 V_504 ,
T_1 V_217 )
{
struct V_11 * V_12 ;
struct V_642 * V_192 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_643 , sizeof( * V_192 ) ,
V_12 , NULL ) ;
V_192 -> V_196 . V_217 = V_217 ;
V_192 -> V_597 = F_69 ( 1 ) ;
V_192 -> V_644 . V_196 . V_599 = V_600 ;
V_192 -> V_644 . V_196 . V_602 = V_603 ;
V_192 -> V_644 . V_26 = ( 1 << V_645 ) | ( 1 << V_646 ) | ( 1 << V_647 ) ;
V_192 -> V_644 . V_609 = V_2 -> V_634 ;
V_192 -> V_644 . V_648 = V_217 ;
V_192 -> V_644 . V_614 = 0xFFFF ;
V_192 -> V_644 . V_649 = 0xFFFF ;
V_192 -> V_644 . V_616 = 0xFFFF ;
V_192 -> V_644 . V_618 = 0xFFFF ;
V_192 -> V_644 . V_620 = 0xFFFF ;
V_192 -> V_644 . V_624 = 0xFFFF ;
V_192 -> V_644 . V_622 = 0xFFFF ;
V_192 -> V_644 . V_650 = 0xFFFF ;
V_192 -> V_644 . V_651 = 0xFFFF ;
V_192 -> V_644 . V_652 = 0xFFFF ;
V_192 -> V_644 . V_626 = 0xFFFF ;
V_192 -> V_644 . V_653 = 0xFF ;
V_192 -> V_644 . V_654 = 0xFFFFFFFF ;
V_192 -> V_644 . V_655 = 0xFF ;
V_192 -> V_644 . V_656 = 0x0F ;
V_192 -> V_644 . V_654 = F_69 ( V_504 ) ;
V_192 -> V_644 . V_657 = F_69 ( V_504 ) ;
V_35 = F_47 ( V_2 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_177 ( struct V_1 * V_2 , struct V_658 * V_659 ,
int V_648 )
{
struct V_11 * V_12 ;
struct V_660 * V_192 ;
struct V_661 * V_50 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_662 , sizeof( * V_50 ) ,
V_12 , NULL ) ;
V_192 -> V_196 . V_217 = V_648 + 1 ;
V_35 = F_47 ( V_2 ) ;
if ( ! V_35 ) {
V_50 = (struct V_661 * ) V_192 ;
V_659 -> V_208 = F_8 ( V_50 -> V_663 . V_213 ) ;
}
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
static int F_178 ( struct V_1 * V_2 )
{
#define F_179 30
T_2 V_664 ;
int V_35 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < F_179 ; V_5 ++ ) {
V_664 = F_51 ( V_2 -> V_22 + V_665 ) ;
if ( ( V_664 & V_666 ) == 0 )
break;
F_180 ( 1 ) ;
}
if ( V_5 == F_179 )
V_35 = - 1 ;
return V_35 ;
}
int F_181 ( struct V_1 * V_2 , T_2 V_667 )
{
int V_35 = 0 ;
V_35 = F_178 ( V_2 ) ;
if ( V_35 )
return V_35 ;
F_6 ( V_667 , V_2 -> V_22 + V_665 ) ;
return V_35 ;
}
bool F_182 ( struct V_1 * V_2 )
{
T_2 V_137 = 0 ;
V_137 = F_51 ( V_2 -> V_22 + V_138 ) ;
return ! ! ( V_137 & V_668 ) ;
}
int F_183 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_181 ( V_2 , V_669 |
V_670 ) ;
if ( V_35 < 0 ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_20 ) ;
return V_35 ;
}
V_35 = F_178 ( V_2 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_182 ( V_2 ) ) {
F_16 ( & V_2 -> V_59 -> V_60 , L_21 ) ;
return - 1 ;
}
return 0 ;
}
int F_184 ( struct V_1 * V_2 , T_1 V_217 )
{
struct V_11 * V_12 ;
struct V_671 * V_192 ;
int V_35 ;
if ( ! F_18 ( V_2 ) )
return 0 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_672 , sizeof( * V_192 ) ,
V_12 , NULL ) ;
V_192 -> V_196 . V_217 = V_217 ;
V_192 -> V_469 = 1 ;
V_35 = F_47 ( V_2 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
int F_185 ( struct V_1 * V_2 , bool V_673 )
{
struct V_11 * V_12 ;
struct V_674 * V_192 ;
int V_35 ;
if ( F_81 ( & V_2 -> V_186 ) )
return - 1 ;
V_12 = F_74 ( V_2 ) ;
V_192 = F_2 ( V_12 ) ;
F_68 ( & V_192 -> V_196 , V_40 ,
V_675 , sizeof( * V_192 ) ,
V_12 , NULL ) ;
V_192 -> V_676 = V_673 ;
V_35 = F_54 ( V_2 ) ;
F_83 ( & V_2 -> V_186 ) ;
return V_35 ;
}
int F_186 ( void * V_677 , void * V_678 ,
int V_679 , T_3 * V_680 , T_3 * V_681 )
{
struct V_1 * V_2 = F_187 ( V_677 ) ;
struct V_11 * V_12 ;
struct V_161 * V_196 = (struct V_161 * ) V_678 ;
struct V_161 * V_192 ;
struct V_28 * V_50 ;
int V_35 ;
F_33 ( & V_2 -> V_185 ) ;
V_12 = F_75 ( V_2 ) ;
if ( ! V_12 ) {
V_35 = - V_188 ;
goto V_147;
}
V_192 = F_2 ( V_12 ) ;
V_50 = F_2 ( V_12 ) ;
F_68 ( V_192 , V_196 -> V_4 ,
V_196 -> V_3 , V_679 , V_12 , NULL ) ;
memcpy ( V_192 , V_678 , V_679 ) ;
F_70 ( V_192 , V_679 ) ;
V_35 = F_47 ( V_2 ) ;
if ( V_680 )
* V_680 = ( V_35 & 0xffff ) ;
if ( V_681 )
* V_681 = 0 ;
memcpy ( V_678 , V_50 , sizeof( * V_50 ) + V_50 -> V_581 ) ;
F_12 ( V_678 , sizeof( * V_50 ) + V_50 -> V_581 ) ;
V_147:
F_35 ( & V_2 -> V_185 ) ;
return V_35 ;
}
