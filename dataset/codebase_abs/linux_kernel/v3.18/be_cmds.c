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
if ( V_66 -> V_74 ) {
V_2 -> V_75 = V_66 -> V_76 ;
V_2 -> V_77 &= ~ V_78 ;
V_2 -> V_77 =
V_66 -> V_79 << V_80 ;
}
}
static void F_23 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_81 * V_66 =
(struct V_81 * ) V_25 ;
if ( V_2 -> V_67 . V_68 >= 0 &&
V_66 -> V_82 == V_2 -> V_83 )
V_2 -> V_67 . V_68 = F_24 ( V_66 -> V_84 ) * 10 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_85 * V_66 =
(struct V_85 * ) V_25 ;
if ( V_66 -> V_86 ) {
V_2 -> V_87 = F_24 ( V_66 -> V_88 ) & V_89 ;
F_26 ( & V_2 -> V_63 -> V_64 , L_3 , V_2 -> V_87 ) ;
} else {
V_2 -> V_87 = 0 ;
}
}
static void F_27 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
T_1 V_90 = ( V_25 -> V_26 >> V_91 ) &
V_92 ;
switch ( V_90 ) {
case V_93 :
F_22 ( V_2 , V_25 ) ;
break;
case V_94 :
F_23 ( V_2 , V_25 ) ;
break;
case V_95 :
F_25 ( V_2 , V_25 ) ;
break;
default:
break;
}
}
static void F_28 ( struct V_1 * V_2 ,
struct V_24 * V_96 )
{
T_1 V_90 = 0 ;
struct V_97 * V_66 = (struct V_97 * ) V_96 ;
V_90 = ( V_96 -> V_26 >> V_91 ) &
V_92 ;
switch ( V_90 ) {
case V_98 :
if ( V_66 -> V_74 )
V_2 -> V_99 = F_24 ( V_66 -> V_100 ) ;
V_2 -> V_26 |= V_101 ;
break;
default:
F_17 ( & V_2 -> V_63 -> V_64 , L_4 ,
V_90 ) ;
break;
}
}
static inline bool F_29 ( T_2 V_26 )
{
return ( ( V_26 >> V_102 ) & V_103 ) ==
V_104 ;
}
static inline bool F_30 ( T_2 V_26 )
{
return ( ( V_26 >> V_102 ) & V_103 ) ==
V_105 ;
}
static inline bool F_31 ( T_2 V_26 )
{
return ( ( V_26 >> V_102 ) & V_103 ) ==
V_106 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
if ( F_29 ( V_25 -> V_26 ) )
F_19 ( V_2 , V_25 ) ;
else if ( F_30 ( V_25 -> V_26 ) )
F_27 ( V_2 , V_25 ) ;
else if ( F_31 ( V_25 -> V_26 ) )
F_28 ( V_2 , V_25 ) ;
}
static struct V_24 * F_33 ( struct V_1 * V_2 )
{
struct V_14 * V_107 = & V_2 -> V_16 . V_108 ;
struct V_24 * V_25 = F_34 ( V_107 ) ;
if ( F_7 ( V_25 ) ) {
F_35 ( V_107 ) ;
return V_25 ;
}
return NULL ;
}
void F_36 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_109 ) ;
F_38 ( V_2 , V_2 -> V_16 . V_108 . V_19 , true , 0 ) ;
V_2 -> V_16 . V_110 = true ;
F_39 ( & V_2 -> V_109 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_109 ) ;
V_2 -> V_16 . V_110 = false ;
F_38 ( V_2 , V_2 -> V_16 . V_108 . V_19 , false , 0 ) ;
F_39 ( & V_2 -> V_109 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
int V_111 = 0 , V_42 = 0 ;
struct V_112 * V_16 = & V_2 -> V_16 ;
F_42 ( & V_2 -> V_109 ) ;
while ( ( V_25 = F_33 ( V_2 ) ) ) {
if ( V_25 -> V_26 & V_113 ) {
F_32 ( V_2 , V_25 ) ;
} else if ( V_25 -> V_26 & V_114 ) {
V_42 = F_15 ( V_2 , V_25 ) ;
F_43 ( & V_16 -> V_17 . V_115 ) ;
}
F_9 ( V_25 ) ;
V_111 ++ ;
}
if ( V_111 )
F_38 ( V_2 , V_16 -> V_108 . V_19 , V_16 -> V_110 , V_111 ) ;
F_44 ( & V_2 -> V_109 ) ;
return V_42 ;
}
static int F_45 ( struct V_1 * V_2 )
{
#define F_46 120000
int V_5 , V_42 = 0 ;
struct V_112 * V_16 = & V_2 -> V_16 ;
for ( V_5 = 0 ; V_5 < F_46 ; V_5 ++ ) {
if ( F_4 ( V_2 ) )
return - V_116 ;
F_47 () ;
V_42 = F_41 ( V_2 ) ;
F_48 () ;
if ( F_49 ( & V_16 -> V_17 . V_115 ) == 0 )
break;
F_50 ( 100 ) ;
}
if ( V_5 == F_46 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_5 ) ;
V_2 -> V_117 = true ;
return - V_116 ;
}
return V_42 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_42 ;
struct V_11 * V_12 ;
struct V_112 * V_16 = & V_2 -> V_16 ;
T_3 V_118 = V_16 -> V_17 . V_119 ;
struct V_28 * V_56 ;
F_52 ( & V_118 , V_16 -> V_17 . V_120 ) ;
V_12 = F_53 ( & V_16 -> V_17 , V_118 ) ;
V_56 = F_10 ( V_12 -> V_29 , V_12 -> V_30 ) ;
F_3 ( V_2 ) ;
V_42 = F_45 ( V_2 ) ;
if ( V_42 == - V_116 )
goto V_121;
V_42 = ( V_56 -> V_32 |
( ( V_56 -> V_33 & V_122 ) <<
V_123 ) ) ;
V_121:
return V_42 ;
}
static int F_54 ( struct V_1 * V_2 , void T_4 * V_22 )
{
int V_124 = 0 ;
T_2 V_125 ;
do {
if ( F_4 ( V_2 ) )
return - V_116 ;
V_125 = F_55 ( V_22 ) ;
if ( V_125 == 0xffffffff )
return - 1 ;
V_125 &= V_126 ;
if ( V_125 )
break;
if ( V_124 > 4000 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_5 ) ;
V_2 -> V_117 = true ;
F_56 ( V_2 ) ;
return - 1 ;
}
F_57 ( 1 ) ;
V_124 ++ ;
} while ( true );
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_42 ;
T_2 V_18 = 0 ;
void T_4 * V_22 = V_2 -> V_22 + V_127 ;
struct V_128 * V_129 = & V_2 -> V_129 ;
struct V_130 * V_131 = V_129 -> V_132 ;
struct V_24 * V_25 = & V_131 -> V_25 ;
V_42 = F_54 ( V_2 , V_22 ) ;
if ( V_42 != 0 )
return V_42 ;
V_18 |= V_133 ;
V_18 |= ( F_59 ( V_129 -> V_134 ) >> 2 ) << 2 ;
F_6 ( V_18 , V_22 ) ;
V_42 = F_54 ( V_2 , V_22 ) ;
if ( V_42 != 0 )
return V_42 ;
V_18 = 0 ;
V_18 |= ( T_2 ) ( V_129 -> V_134 >> 4 ) << 2 ;
F_6 ( V_18 , V_22 ) ;
V_42 = F_54 ( V_2 , V_22 ) ;
if ( V_42 != 0 )
return V_42 ;
if ( F_7 ( V_25 ) ) {
V_42 = F_15 ( V_2 , & V_131 -> V_25 ) ;
F_9 ( V_25 ) ;
if ( V_42 )
return V_42 ;
} else {
F_18 ( & V_2 -> V_63 -> V_64 , L_6 ) ;
return - 1 ;
}
return 0 ;
}
static T_3 F_60 ( struct V_1 * V_2 )
{
T_2 V_135 ;
if ( F_20 ( V_2 ) )
V_135 = F_55 ( V_2 -> V_136 + V_137 ) ;
else
F_61 ( V_2 -> V_63 ,
V_138 , & V_135 ) ;
return V_135 & V_139 ;
}
static int F_62 ( struct V_1 * V_2 )
{
#define F_63 30
T_2 V_140 ;
int V_42 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < F_63 ; V_5 ++ ) {
V_140 = F_55 ( V_2 -> V_22 + V_141 ) ;
if ( V_140 & V_142 )
break;
F_57 ( 1000 ) ;
}
if ( V_5 == F_63 )
V_42 = - 1 ;
return V_42 ;
}
static bool F_64 ( struct V_1 * V_2 )
{
T_2 V_140 = 0 , V_143 = 0 , V_144 = 0 ;
V_140 = F_55 ( V_2 -> V_22 + V_141 ) ;
if ( V_140 & V_145 ) {
V_143 = F_55 ( V_2 -> V_22 + V_146 ) ;
V_144 = F_55 ( V_2 -> V_22 + V_147 ) ;
if ( V_143 == V_148 &&
V_144 == V_149 )
return true ;
}
return false ;
}
int F_65 ( struct V_1 * V_2 )
{
int V_42 ;
T_2 V_140 , V_150 , V_151 ;
bool V_152 ;
V_152 = F_64 ( V_2 ) ;
if ( V_152 )
return - V_153 ;
V_42 = F_62 ( V_2 ) ;
if ( ! V_42 ) {
V_140 = F_55 ( V_2 -> V_22 + V_141 ) ;
V_150 = V_140 & V_145 ;
V_151 = V_140 & V_154 ;
if ( V_150 && V_151 ) {
F_6 ( V_155 ,
V_2 -> V_22 + V_156 ) ;
V_42 = F_62 ( V_2 ) ;
V_140 = F_55 ( V_2 -> V_22 +
V_141 ) ;
V_140 &= ( V_145 |
V_154 ) ;
if ( V_42 || V_140 )
V_42 = - 1 ;
} else if ( V_150 || V_151 ) {
V_42 = - 1 ;
}
}
V_152 = F_64 ( V_2 ) ;
if ( V_152 )
V_42 = - V_153 ;
return V_42 ;
}
int F_66 ( struct V_1 * V_2 )
{
T_3 V_157 ;
int V_42 , V_158 = 0 ;
struct V_159 * V_64 = & V_2 -> V_63 -> V_64 ;
if ( F_67 ( V_2 ) ) {
V_42 = F_62 ( V_2 ) ;
return V_42 ;
}
do {
V_157 = F_60 ( V_2 ) ;
if ( V_157 == V_160 )
return 0 ;
F_26 ( V_64 , L_7 , V_158 ) ;
if ( F_68 ( 2000 ) ) {
F_18 ( V_64 , L_8 ) ;
return - V_161 ;
}
V_158 += 2 ;
} while ( V_158 < 60 );
F_18 ( V_64 , L_9 , V_157 ) ;
return - 1 ;
}
static inline struct V_162 * F_69 ( struct V_11 * V_12 )
{
return & V_12 -> V_13 . V_163 [ 0 ] ;
}
static inline void F_70 ( struct V_11 * V_12 , unsigned long V_31 )
{
V_12 -> V_29 = V_31 & 0xFFFFFFFF ;
V_12 -> V_30 = F_59 ( V_31 ) ;
}
static void F_71 ( struct V_164 * V_165 ,
T_1 V_4 , T_1 V_3 , int V_166 ,
struct V_11 * V_12 ,
struct V_128 * V_167 )
{
struct V_162 * V_168 ;
V_165 -> V_3 = V_3 ;
V_165 -> V_4 = V_4 ;
V_165 -> V_169 = F_72 ( V_166 - sizeof( * V_165 ) ) ;
V_165 -> V_170 = 0 ;
F_70 ( V_12 , ( V_171 ) V_165 ) ;
V_12 -> V_172 = V_166 ;
if ( V_167 ) {
V_12 -> V_173 |= ( 1 & V_174 ) <<
V_175 ;
V_168 = F_69 ( V_12 ) ;
V_168 -> V_176 = F_72 ( F_59 ( V_167 -> V_134 ) ) ;
V_168 -> V_177 = F_72 ( V_167 -> V_134 & 0xFFFFFFFF ) ;
V_168 -> V_120 = F_72 ( V_167 -> V_178 ) ;
} else
V_12 -> V_173 |= V_179 ;
F_73 ( V_12 , 8 ) ;
}
static void F_74 ( struct V_180 * V_181 , T_2 V_182 ,
struct V_128 * V_167 )
{
int V_5 , V_183 = F_75 ( F_76 ( V_167 -> V_132 , V_167 -> V_178 ) , V_182 ) ;
T_5 V_134 = ( T_5 ) V_167 -> V_134 ;
for ( V_5 = 0 ; V_5 < V_183 ; V_5 ++ ) {
V_181 [ V_5 ] . V_184 = F_72 ( V_134 & 0xFFFFFFFF ) ;
V_181 [ V_5 ] . V_185 = F_72 ( F_59 ( V_134 ) ) ;
V_134 += V_186 ;
}
}
static inline struct V_11 * F_77 ( struct V_1 * V_2 )
{
struct V_128 * V_129 = & V_2 -> V_129 ;
struct V_11 * V_12
= & ( (struct V_130 * ) ( V_129 -> V_132 ) ) -> V_12 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
static struct V_11 * F_78 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 . V_17 ;
struct V_11 * V_12 ;
if ( ! V_15 -> V_187 )
return NULL ;
if ( F_49 ( & V_15 -> V_115 ) >= V_15 -> V_120 )
return NULL ;
V_12 = F_79 ( V_15 ) ;
F_80 ( V_15 ) ;
F_81 ( & V_15 -> V_115 ) ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
static bool F_82 ( struct V_1 * V_2 )
{
return V_2 -> V_16 . V_17 . V_187 ;
}
static int F_83 ( struct V_1 * V_2 )
{
if ( F_82 ( V_2 ) ) {
F_37 ( & V_2 -> V_188 ) ;
return 0 ;
} else {
return F_84 ( & V_2 -> V_189 ) ;
}
}
static void F_85 ( struct V_1 * V_2 )
{
if ( F_82 ( V_2 ) )
F_39 ( & V_2 -> V_188 ) ;
else
return F_86 ( & V_2 -> V_189 ) ;
}
static struct V_11 * F_87 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_190 ;
if ( F_82 ( V_2 ) ) {
V_190 = F_78 ( V_2 ) ;
if ( ! V_190 )
return NULL ;
} else {
V_190 = F_77 ( V_2 ) ;
}
memcpy ( V_190 , V_12 , sizeof( * V_12 ) ) ;
if ( V_12 -> V_173 & F_72 ( V_179 ) )
F_70 ( V_190 , ( V_171 ) F_2 ( V_12 ) ) ;
return V_190 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_190 ;
int V_42 ;
V_42 = F_83 ( V_2 ) ;
if ( V_42 )
return V_42 ;
V_190 = F_87 ( V_2 , V_12 ) ;
if ( ! V_190 )
return - V_191 ;
if ( F_82 ( V_2 ) )
V_42 = F_51 ( V_2 ) ;
else
V_42 = F_58 ( V_2 ) ;
if ( ! V_42 )
memcpy ( V_12 , V_190 , sizeof( * V_12 ) ) ;
F_85 ( V_2 ) ;
return V_42 ;
}
int F_89 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_42 ;
if ( F_67 ( V_2 ) )
return 0 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
V_12 = ( T_1 * ) F_77 ( V_2 ) ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0x12 ;
* V_12 ++ = 0x34 ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0x56 ;
* V_12 ++ = 0x78 ;
* V_12 = 0xFF ;
V_42 = F_58 ( V_2 ) ;
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
int F_90 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_42 ;
if ( F_67 ( V_2 ) )
return 0 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
V_12 = ( T_1 * ) F_77 ( V_2 ) ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xAA ;
* V_12 ++ = 0xBB ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xCC ;
* V_12 ++ = 0xDD ;
* V_12 = 0xFF ;
V_42 = F_58 ( V_2 ) ;
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
int F_91 ( struct V_1 * V_2 , struct V_192 * V_193 )
{
struct V_11 * V_12 ;
struct V_194 * V_195 ;
struct V_128 * V_196 = & V_193 -> V_17 . V_197 ;
int V_42 , V_198 = 0 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
V_12 = F_77 ( V_2 ) ;
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_200 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
if ( ! ( F_20 ( V_2 ) || F_67 ( V_2 ) ) )
V_198 = 2 ;
V_195 -> V_199 . V_170 = V_198 ;
V_195 -> V_201 = F_92 ( F_76 ( V_196 -> V_132 , V_196 -> V_178 ) ) ;
F_93 ( struct V_202 , V_74 , V_195 -> V_203 , 1 ) ;
F_93 ( struct V_202 , V_178 , V_195 -> V_203 , 0 ) ;
F_93 ( struct V_202 , V_204 , V_195 -> V_203 ,
F_94 ( V_193 -> V_17 . V_120 / 256 ) ) ;
F_73 ( V_195 -> V_203 , sizeof( V_195 -> V_203 ) ) ;
F_74 ( V_195 -> V_181 , F_95 ( V_195 -> V_181 ) , V_196 ) ;
V_42 = F_58 ( V_2 ) ;
if ( ! V_42 ) {
struct V_205 * V_56 = F_2 ( V_12 ) ;
V_193 -> V_17 . V_19 = F_24 ( V_56 -> V_206 ) ;
V_193 -> V_207 =
( V_198 == 2 ) ? F_24 ( V_56 -> V_207 ) : V_193 -> V_208 ;
V_193 -> V_17 . V_187 = true ;
}
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
int F_96 ( struct V_1 * V_2 , T_1 * V_209 ,
bool V_210 , T_2 V_211 , T_2 V_212 )
{
struct V_11 * V_12 ;
struct V_213 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_214 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_195 -> type = V_215 ;
if ( V_210 ) {
V_195 -> V_210 = 1 ;
} else {
V_195 -> V_216 = F_92 ( ( T_3 ) V_211 ) ;
V_195 -> V_212 = F_72 ( V_212 ) ;
V_195 -> V_210 = 0 ;
}
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_217 * V_56 = F_2 ( V_12 ) ;
memcpy ( V_209 , V_56 -> V_218 . V_31 , V_219 ) ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_97 ( struct V_1 * V_2 , T_1 * V_209 ,
T_2 V_216 , T_2 * V_212 , T_2 V_220 )
{
struct V_11 * V_12 ;
struct V_221 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_222 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_195 -> V_199 . V_220 = V_220 ;
V_195 -> V_216 = F_72 ( V_216 ) ;
memcpy ( V_195 -> V_223 , V_209 , V_219 ) ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_224 * V_56 = F_2 ( V_12 ) ;
* V_212 = F_8 ( V_56 -> V_212 ) ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
if ( V_42 == V_62 )
V_42 = - V_225 ;
return V_42 ;
}
int F_98 ( struct V_1 * V_2 , T_2 V_216 , int V_212 , T_2 V_226 )
{
struct V_11 * V_12 ;
struct V_227 * V_195 ;
int V_42 ;
if ( V_212 == - 1 )
return 0 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_228 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_199 . V_220 = V_226 ;
V_195 -> V_216 = F_72 ( V_216 ) ;
V_195 -> V_212 = F_72 ( V_212 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_99 ( struct V_1 * V_2 , struct V_14 * V_108 ,
struct V_14 * V_229 , bool V_230 , int V_231 )
{
struct V_11 * V_12 ;
struct V_232 * V_195 ;
struct V_128 * V_196 = & V_108 -> V_197 ;
void * V_233 ;
int V_42 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
V_12 = F_77 ( V_2 ) ;
V_195 = F_2 ( V_12 ) ;
V_233 = & V_195 -> V_203 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_234 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_195 -> V_201 = F_92 ( F_76 ( V_196 -> V_132 , V_196 -> V_178 ) ) ;
if ( F_20 ( V_2 ) ) {
F_93 ( struct V_235 , V_236 , V_233 ,
V_231 ) ;
F_93 ( struct V_235 , V_237 ,
V_233 , V_230 ) ;
F_93 ( struct V_235 , V_204 , V_233 ,
F_94 ( V_108 -> V_120 / 256 ) ) ;
F_93 ( struct V_235 , V_74 , V_233 , 1 ) ;
F_93 ( struct V_235 , V_238 , V_233 , 1 ) ;
F_93 ( struct V_235 , V_239 , V_233 , V_229 -> V_19 ) ;
} else {
V_195 -> V_199 . V_170 = 2 ;
V_195 -> V_240 = 1 ;
if ( ! F_67 ( V_2 ) )
F_93 ( struct V_241 , V_236 ,
V_233 , V_231 ) ;
F_93 ( struct V_241 , V_237 , V_233 ,
V_230 ) ;
F_93 ( struct V_241 , V_204 , V_233 ,
F_94 ( V_108 -> V_120 / 256 ) ) ;
F_93 ( struct V_241 , V_74 , V_233 , 1 ) ;
F_93 ( struct V_241 , V_238 , V_233 , 1 ) ;
F_93 ( struct V_241 , V_239 , V_233 , V_229 -> V_19 ) ;
}
F_73 ( V_233 , sizeof( V_195 -> V_203 ) ) ;
F_74 ( V_195 -> V_181 , F_95 ( V_195 -> V_181 ) , V_196 ) ;
V_42 = F_58 ( V_2 ) ;
if ( ! V_42 ) {
struct V_242 * V_56 = F_2 ( V_12 ) ;
V_108 -> V_19 = F_24 ( V_56 -> V_243 ) ;
V_108 -> V_187 = true ;
}
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
static T_2 F_100 ( int V_244 )
{
T_2 V_245 = F_101 ( V_244 ) ;
if ( V_245 == 16 )
V_245 = 0 ;
return V_245 ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_108 )
{
struct V_11 * V_12 ;
struct V_246 * V_195 ;
struct V_128 * V_196 = & V_15 -> V_197 ;
void * V_233 ;
int V_42 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
V_12 = F_77 ( V_2 ) ;
V_195 = F_2 ( V_12 ) ;
V_233 = & V_195 -> V_203 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_247 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_195 -> V_201 = F_92 ( F_76 ( V_196 -> V_132 , V_196 -> V_178 ) ) ;
if ( F_20 ( V_2 ) ) {
F_93 ( struct V_248 , V_74 , V_233 , 1 ) ;
F_93 ( struct V_248 , V_249 , V_233 ,
F_100 ( V_15 -> V_120 ) ) ;
F_93 ( struct V_248 , V_243 , V_233 , V_108 -> V_19 ) ;
} else {
V_195 -> V_199 . V_170 = 1 ;
V_195 -> V_243 = F_92 ( V_108 -> V_19 ) ;
F_93 ( struct V_250 , V_249 , V_233 ,
F_100 ( V_15 -> V_120 ) ) ;
F_93 ( struct V_250 , V_74 , V_233 , 1 ) ;
F_93 ( struct V_250 , V_251 ,
V_233 , V_108 -> V_19 ) ;
F_93 ( struct V_250 , V_252 ,
V_233 , 1 ) ;
}
V_195 -> V_253 [ 0 ] = F_72 ( 0x00000022 ) ;
V_195 -> V_253 [ 0 ] |= F_72 ( 1 << V_106 ) ;
F_73 ( V_233 , sizeof( V_195 -> V_203 ) ) ;
F_74 ( V_195 -> V_181 , F_95 ( V_195 -> V_181 ) , V_196 ) ;
V_42 = F_58 ( V_2 ) ;
if ( ! V_42 ) {
struct V_254 * V_56 = F_2 ( V_12 ) ;
V_15 -> V_19 = F_24 ( V_56 -> V_19 ) ;
V_15 -> V_187 = true ;
}
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_108 )
{
struct V_11 * V_12 ;
struct V_255 * V_195 ;
struct V_128 * V_196 = & V_15 -> V_197 ;
void * V_233 ;
int V_42 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
V_12 = F_77 ( V_2 ) ;
V_195 = F_2 ( V_12 ) ;
V_233 = & V_195 -> V_203 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_256 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_195 -> V_201 = F_92 ( F_76 ( V_196 -> V_132 , V_196 -> V_178 ) ) ;
F_93 ( struct V_248 , V_74 , V_233 , 1 ) ;
F_93 ( struct V_248 , V_249 , V_233 ,
F_100 ( V_15 -> V_120 ) ) ;
F_93 ( struct V_248 , V_243 , V_233 , V_108 -> V_19 ) ;
F_73 ( V_233 , sizeof( V_195 -> V_203 ) ) ;
F_74 ( V_195 -> V_181 , F_95 ( V_195 -> V_181 ) , V_196 ) ;
V_42 = F_58 ( V_2 ) ;
if ( ! V_42 ) {
struct V_254 * V_56 = F_2 ( V_12 ) ;
V_15 -> V_19 = F_24 ( V_56 -> V_19 ) ;
V_15 -> V_187 = true ;
}
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
int F_104 ( struct V_1 * V_2 ,
struct V_14 * V_15 , struct V_14 * V_108 )
{
int V_42 ;
V_42 = F_102 ( V_2 , V_15 , V_108 ) ;
if ( V_42 && F_20 ( V_2 ) ) {
F_17 ( & V_2 -> V_63 -> V_64 , L_10
L_11
L_12 ) ;
V_42 = F_103 ( V_2 , V_15 , V_108 ) ;
}
return V_42 ;
}
int F_105 ( struct V_1 * V_2 , struct V_257 * V_258 )
{
struct V_11 V_12 = { 0 } ;
struct V_259 * V_195 ;
struct V_14 * V_260 = & V_258 -> V_17 ;
struct V_14 * V_108 = & V_258 -> V_108 ;
struct V_128 * V_196 = & V_260 -> V_197 ;
int V_42 , V_198 = 0 ;
V_195 = F_2 ( & V_12 ) ;
F_71 ( & V_195 -> V_199 , V_51 ,
V_261 , sizeof( * V_195 ) , & V_12 , NULL ) ;
if ( F_67 ( V_2 ) ) {
V_195 -> V_199 . V_170 = 1 ;
} else if ( F_20 ( V_2 ) ) {
if ( V_2 -> V_262 & V_263 )
V_195 -> V_199 . V_170 = 2 ;
} else {
V_195 -> V_199 . V_170 = 2 ;
}
if ( V_195 -> V_199 . V_170 > 0 )
V_195 -> V_216 = F_92 ( V_2 -> V_211 ) ;
V_195 -> V_201 = F_76 ( V_196 -> V_132 , V_196 -> V_178 ) ;
V_195 -> V_264 = V_265 ;
V_195 -> type = V_266 ;
V_195 -> V_243 = F_92 ( V_108 -> V_19 ) ;
V_195 -> V_267 = F_100 ( V_260 -> V_120 ) ;
F_74 ( V_195 -> V_181 , F_95 ( V_195 -> V_181 ) , V_196 ) ;
V_198 = V_195 -> V_199 . V_170 ;
V_42 = F_88 ( V_2 , & V_12 ) ;
if ( ! V_42 ) {
struct V_268 * V_56 = F_2 ( & V_12 ) ;
V_260 -> V_19 = F_24 ( V_56 -> V_269 ) ;
if ( V_198 == 2 )
V_258 -> V_270 = F_8 ( V_56 -> V_270 ) ;
else
V_258 -> V_270 = V_271 ;
V_260 -> V_187 = true ;
}
return V_42 ;
}
int F_106 ( struct V_1 * V_2 ,
struct V_14 * V_272 , T_3 V_243 , T_3 V_273 ,
T_2 V_216 , T_2 V_274 , T_1 * V_275 )
{
struct V_11 * V_12 ;
struct V_276 * V_195 ;
struct V_128 * V_196 = & V_272 -> V_197 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_51 ,
V_277 , sizeof( * V_195 ) , V_12 , NULL ) ;
V_195 -> V_243 = F_92 ( V_243 ) ;
V_195 -> V_273 = F_101 ( V_273 ) - 1 ;
V_195 -> V_201 = 2 ;
F_74 ( V_195 -> V_181 , F_95 ( V_195 -> V_181 ) , V_196 ) ;
V_195 -> V_278 = F_72 ( V_216 ) ;
V_195 -> V_279 = F_92 ( V_280 ) ;
V_195 -> V_281 = F_72 ( V_274 ) ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_282 * V_56 = F_2 ( V_12 ) ;
V_272 -> V_19 = F_24 ( V_56 -> V_19 ) ;
V_272 -> V_187 = true ;
* V_275 = V_56 -> V_275 ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_107 ( struct V_1 * V_2 , struct V_14 * V_17 ,
int V_283 )
{
struct V_11 * V_12 ;
struct V_284 * V_195 ;
T_1 V_285 = 0 , V_3 = 0 ;
int V_42 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
V_12 = F_77 ( V_2 ) ;
V_195 = F_2 ( V_12 ) ;
switch ( V_283 ) {
case V_286 :
V_285 = V_47 ;
V_3 = V_287 ;
break;
case V_288 :
V_285 = V_47 ;
V_3 = V_289 ;
break;
case V_290 :
V_285 = V_51 ;
V_3 = V_291 ;
break;
case V_292 :
V_285 = V_51 ;
V_3 = V_293 ;
break;
case V_294 :
V_285 = V_47 ;
V_3 = V_295 ;
break;
default:
F_108 () ;
}
F_71 ( & V_195 -> V_199 , V_285 , V_3 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_195 -> V_19 = F_92 ( V_17 -> V_19 ) ;
V_42 = F_58 ( V_2 ) ;
V_17 -> V_187 = false ;
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
int F_109 ( struct V_1 * V_2 , struct V_14 * V_17 )
{
struct V_11 * V_12 ;
struct V_284 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_51 ,
V_293 , sizeof( * V_195 ) , V_12 , NULL ) ;
V_195 -> V_19 = F_92 ( V_17 -> V_19 ) ;
V_42 = F_51 ( V_2 ) ;
V_17 -> V_187 = false ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_110 ( struct V_1 * V_2 , T_2 V_296 , T_2 V_297 ,
T_2 * V_211 , T_2 V_220 )
{
struct V_11 V_12 = { 0 } ;
struct V_298 * V_195 ;
int V_42 ;
V_195 = F_2 ( & V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_299 ,
sizeof( * V_195 ) , & V_12 , NULL ) ;
V_195 -> V_199 . V_220 = V_220 ;
V_195 -> V_300 = F_72 ( V_296 ) ;
V_195 -> V_301 = F_72 ( V_297 ) ;
V_195 -> V_302 = true ;
V_42 = F_88 ( V_2 , & V_12 ) ;
if ( ! V_42 ) {
struct V_303 * V_56 = F_2 ( & V_12 ) ;
* V_211 = F_8 ( V_56 -> V_278 ) ;
if ( F_111 ( V_2 ) && ! F_112 ( V_2 ) )
V_2 -> V_212 [ 0 ] = F_8 ( V_56 -> V_212 ) ;
}
return V_42 ;
}
int F_113 ( struct V_1 * V_2 , int V_278 , T_2 V_220 )
{
struct V_11 * V_12 ;
struct V_304 * V_195 ;
int V_42 ;
if ( V_278 == - 1 )
return 0 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_305 ,
sizeof( * V_195 ) , V_12 , NULL ) ;
V_195 -> V_199 . V_220 = V_220 ;
V_195 -> V_278 = F_72 ( V_278 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_114 ( struct V_1 * V_2 , struct V_128 * V_306 )
{
struct V_11 * V_12 ;
struct V_164 * V_199 ;
int V_42 = 0 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_199 = V_306 -> V_132 ;
F_71 ( V_199 , V_51 ,
V_49 , V_306 -> V_178 , V_12 ,
V_306 ) ;
if ( F_115 ( V_2 ) )
V_199 -> V_170 = 0 ;
if ( F_111 ( V_2 ) || F_67 ( V_2 ) )
V_199 -> V_170 = 1 ;
else
V_199 -> V_170 = 2 ;
F_3 ( V_2 ) ;
V_2 -> V_53 = true ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_116 ( struct V_1 * V_2 ,
struct V_128 * V_306 )
{
struct V_11 * V_12 ;
struct V_307 * V_195 ;
int V_42 = 0 ;
if ( ! F_1 ( V_2 , V_50 ,
V_51 ) )
return - V_225 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_306 -> V_132 ;
F_71 ( & V_195 -> V_199 , V_51 ,
V_50 , V_306 -> V_178 ,
V_12 , V_306 ) ;
V_195 -> V_308 . V_309 . V_310 = F_92 ( V_2 -> V_311 ) ;
V_195 -> V_308 . V_309 . V_312 = 0 ;
F_3 ( V_2 ) ;
V_2 -> V_53 = true ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
static int F_117 ( int V_313 )
{
switch ( V_313 ) {
case V_314 :
return 0 ;
case V_315 :
return 10 ;
case V_316 :
return 100 ;
case V_317 :
return 1000 ;
case V_318 :
return 10000 ;
case V_319 :
return 20000 ;
case V_320 :
return 25000 ;
case V_321 :
return 40000 ;
}
return 0 ;
}
int F_118 ( struct V_1 * V_2 , T_3 * V_68 ,
T_1 * V_322 , T_2 V_226 )
{
struct V_11 * V_12 ;
struct V_323 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
if ( V_322 )
* V_322 = V_324 ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_325 ,
sizeof( * V_195 ) , V_12 , NULL ) ;
if ( ! F_115 ( V_2 ) )
V_195 -> V_199 . V_170 = 1 ;
V_195 -> V_199 . V_220 = V_226 ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_326 * V_56 = F_2 ( V_12 ) ;
if ( V_68 ) {
* V_68 = V_56 -> V_68 ?
F_24 ( V_56 -> V_68 ) * 10 :
F_117 ( V_56 -> V_313 ) ;
if ( ! V_56 -> V_327 )
* V_68 = 0 ;
}
if ( V_322 )
* V_322 = V_56 -> V_327 ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_119 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_328 * V_195 ;
int V_42 = 0 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_54 ,
sizeof( * V_195 ) , V_12 , NULL ) ;
F_3 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_120 ( struct V_1 * V_2 , T_2 * V_329 )
{
struct V_11 * V_12 ;
struct V_330 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_331 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_195 -> V_332 = F_72 ( V_333 ) ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_334 * V_56 = F_2 ( V_12 ) ;
if ( V_329 && V_56 -> V_329 )
* V_329 = F_8 ( V_56 -> V_329 ) -
sizeof( T_2 ) ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_121 ( struct V_1 * V_2 , T_2 V_335 , void * V_336 )
{
struct V_128 V_337 ;
struct V_11 * V_12 ;
struct V_330 * V_195 ;
T_2 V_338 = 0 , V_339 , V_340 ,
V_341 = sizeof( T_2 ) , V_342 ;
int V_42 = 0 ;
if ( V_335 == 0 )
return - V_116 ;
V_339 = V_335 ;
V_337 . V_178 = sizeof( struct V_330 ) + 60 * 1024 ;
V_337 . V_132 = F_122 ( V_2 -> V_63 ,
V_337 . V_178 ,
& V_337 . V_134 ) ;
if ( ! V_337 . V_132 ) {
F_18 ( & V_2 -> V_63 -> V_64 ,
L_13 ) ;
return - V_343 ;
}
F_37 ( & V_2 -> V_188 ) ;
while ( V_339 ) {
V_340 = F_75 ( V_339 , ( T_2 ) 60 * 1024 ) ;
V_339 -= V_340 ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_337 . V_132 ;
V_342 = sizeof( struct V_330 ) + V_340 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_331 , V_342 ,
V_12 , & V_337 ) ;
V_195 -> V_332 = F_72 ( V_344 ) ;
V_195 -> V_345 = F_72 ( V_341 ) ;
V_195 -> V_346 = F_72 ( V_340 ) ;
V_195 -> V_347 = F_72 ( V_340 ) ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_334 * V_56 = V_337 . V_132 ;
memcpy ( V_336 + V_338 ,
V_56 -> V_348 ,
F_8 ( V_56 -> V_346 ) ) ;
} else {
F_18 ( & V_2 -> V_63 -> V_64 , L_14 ) ;
goto V_150;
}
V_338 += V_340 ;
V_341 += V_340 ;
}
V_150:
F_123 ( V_2 -> V_63 , V_337 . V_178 ,
V_337 . V_132 , V_337 . V_134 ) ;
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_124 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_349 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_350 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_351 * V_56 = F_2 ( V_12 ) ;
F_125 ( V_2 -> V_352 , V_56 -> V_353 ,
sizeof( V_2 -> V_352 ) ) ;
F_125 ( V_2 -> V_354 , V_56 -> V_355 ,
sizeof( V_2 -> V_354 ) ) ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_356 * V_357 , int V_111 )
{
struct V_11 * V_12 ;
struct V_358 * V_195 ;
int V_42 = 0 , V_5 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_359 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_195 -> V_360 = F_72 ( V_111 ) ;
for ( V_5 = 0 ; V_5 < V_111 ; V_5 ++ ) {
V_195 -> V_357 [ V_5 ] . V_206 = F_72 ( V_357 [ V_5 ] . V_206 ) ;
V_195 -> V_357 [ V_5 ] . V_361 = 0 ;
V_195 -> V_357 [ V_5 ] . V_362 =
F_72 ( V_357 [ V_5 ] . V_362 ) ;
}
F_3 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_127 ( struct V_1 * V_2 , struct V_356 * V_357 ,
int V_111 )
{
int V_363 , V_5 = 0 ;
if ( F_67 ( V_2 ) && V_111 > 8 ) {
while ( V_111 ) {
V_363 = F_75 ( V_111 , 8 ) ;
F_126 ( V_2 , & V_357 [ V_5 ] , V_363 ) ;
V_5 += V_363 ;
V_111 -= V_363 ;
}
} else {
F_126 ( V_2 , V_357 , V_111 ) ;
}
return 0 ;
}
int F_128 ( struct V_1 * V_2 , T_2 V_216 , T_3 * V_364 ,
T_2 V_111 )
{
struct V_11 * V_12 ;
struct V_365 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_366 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_278 = V_216 ;
V_195 -> V_367 = V_368 & F_129 ( V_2 ) ? 1 : 0 ;
V_195 -> V_369 = V_111 ;
memcpy ( V_195 -> V_370 , V_364 ,
V_195 -> V_369 * sizeof( V_364 [ 0 ] ) ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_130 ( struct V_1 * V_2 , T_2 V_26 , T_2 V_371 )
{
struct V_11 * V_12 ;
struct V_128 * V_167 = & V_2 -> V_372 ;
struct V_373 * V_195 = V_167 -> V_132 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
memset ( V_195 , 0 , sizeof( * V_195 ) ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_374 , sizeof( * V_195 ) ,
V_12 , V_167 ) ;
V_195 -> V_216 = F_72 ( V_2 -> V_211 ) ;
if ( V_26 & V_375 ) {
V_195 -> V_376 = F_72 ( V_377 |
V_378 |
V_379 ) ;
if ( V_371 == V_380 )
V_195 -> V_381 =
F_72 ( V_377 |
V_378 |
V_379 ) ;
} else if ( V_26 & V_382 ) {
V_195 -> V_376 = F_72 ( V_379 ) ;
V_195 -> V_381 = F_72 ( V_379 ) ;
} else if ( V_26 & V_383 ) {
V_195 -> V_376 = F_72 ( V_378 ) ;
if ( V_371 == V_380 )
V_195 -> V_381 =
F_72 ( V_378 ) ;
} else {
struct V_384 * V_385 ;
int V_5 = 0 ;
V_195 -> V_376 = F_72 ( V_386 ) ;
V_195 -> V_381 = F_72 ( V_386 ) ;
V_195 -> V_376 |=
F_72 ( V_379 &
F_129 ( V_2 ) ) ;
V_195 -> V_387 = F_72 ( F_131 ( V_2 -> V_388 ) ) ;
F_132 (ha, adapter->netdev)
memcpy ( V_195 -> V_389 [ V_5 ++ ] . V_390 , V_385 -> V_31 , V_219 ) ;
}
if ( ( V_195 -> V_376 & F_72 ( F_129 ( V_2 ) ) ) !=
V_195 -> V_376 ) {
F_17 ( & V_2 -> V_63 -> V_64 ,
L_15 ,
V_195 -> V_376 ) ;
F_17 ( & V_2 -> V_63 -> V_64 ,
L_16 ,
F_129 ( V_2 ) ) ;
}
V_195 -> V_376 &= F_72 ( F_129 ( V_2 ) ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_133 ( struct V_1 * V_2 , T_2 V_391 , T_2 V_392 )
{
struct V_11 * V_12 ;
struct V_393 * V_195 ;
int V_42 ;
if ( ! F_1 ( V_2 , V_394 ,
V_47 ) )
return - V_225 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_394 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_199 . V_170 = 1 ;
V_195 -> V_395 = F_92 ( ( T_3 ) V_391 ) ;
V_195 -> V_396 = F_92 ( ( T_3 ) V_392 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
if ( V_32 ( V_42 ) == V_397 )
return - V_398 ;
return V_42 ;
}
int F_134 ( struct V_1 * V_2 , T_2 * V_391 , T_2 * V_392 )
{
struct V_11 * V_12 ;
struct V_399 * V_195 ;
int V_42 ;
if ( ! F_1 ( V_2 , V_400 ,
V_47 ) )
return - V_225 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_400 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_401 * V_56 =
F_2 ( V_12 ) ;
* V_391 = F_24 ( V_56 -> V_395 ) ;
* V_392 = F_24 ( V_56 -> V_396 ) ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_135 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_402 * V_195 ;
int V_42 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
V_12 = F_77 ( V_2 ) ;
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_403 ,
sizeof( * V_195 ) , V_12 , NULL ) ;
V_42 = F_58 ( V_2 ) ;
if ( ! V_42 ) {
struct V_404 * V_56 = F_2 ( V_12 ) ;
V_2 -> V_83 = F_8 ( V_56 -> V_405 ) ;
V_2 -> V_406 = F_8 ( V_56 -> V_406 ) ;
V_2 -> V_262 = F_8 ( V_56 -> V_262 ) ;
V_2 -> V_407 = F_8 ( V_56 -> V_408 ) & 0xFF ;
F_26 ( & V_2 -> V_63 -> V_64 ,
L_17 ,
V_2 -> V_406 , V_2 -> V_262 ) ;
}
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
int F_136 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_164 * V_195 ;
int V_42 ;
if ( F_67 ( V_2 ) ) {
V_42 = F_62 ( V_2 ) ;
if ( ! V_42 ) {
F_6 ( V_155 ,
V_2 -> V_22 + V_156 ) ;
V_42 = F_65 ( V_2 ) ;
}
if ( V_42 ) {
F_18 ( & V_2 -> V_63 -> V_64 ,
L_18 ) ;
}
return V_42 ;
}
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
V_12 = F_77 ( V_2 ) ;
V_195 = F_2 ( V_12 ) ;
F_71 ( V_195 , V_47 ,
V_409 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_42 = F_58 ( V_2 ) ;
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
int F_137 ( struct V_1 * V_2 , T_1 * V_410 ,
T_2 V_411 , T_3 V_412 , const T_1 * V_413 )
{
struct V_11 * V_12 ;
struct V_414 * V_195 ;
int V_42 ;
if ( ! ( F_129 ( V_2 ) & V_415 ) )
return 0 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_51 ,
V_416 , sizeof( * V_195 ) , V_12 , NULL ) ;
V_195 -> V_216 = F_72 ( V_2 -> V_211 ) ;
V_195 -> V_417 = F_92 ( V_411 ) ;
V_195 -> V_418 = F_92 ( F_101 ( V_412 ) - 1 ) ;
if ( ! F_20 ( V_2 ) )
V_195 -> V_199 . V_170 = 1 ;
memcpy ( V_195 -> V_419 , V_410 , V_412 ) ;
memcpy ( V_195 -> V_420 , V_413 , V_421 ) ;
F_73 ( V_195 -> V_420 , sizeof( V_195 -> V_420 ) ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_138 ( struct V_1 * V_2 , T_1 V_83 ,
T_1 V_422 , T_1 V_423 , T_1 V_424 )
{
struct V_11 * V_12 ;
struct V_425 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_426 ,
sizeof( * V_195 ) , V_12 , NULL ) ;
V_195 -> V_83 = V_83 ;
V_195 -> V_427 = V_424 ;
V_195 -> V_428 = V_422 ;
V_195 -> V_429 = V_423 ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_139 ( struct V_1 * V_2 , T_1 V_83 , T_2 * V_424 )
{
struct V_11 * V_12 ;
struct V_430 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_431 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_83 = V_83 ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_432 * V_56 =
F_2 ( V_12 ) ;
* V_424 = V_56 -> V_427 ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_140 ( struct V_1 * V_2 ,
T_1 V_433 , T_1 * V_434 )
{
struct V_128 V_435 ;
struct V_11 * V_12 ;
struct V_436 * V_195 ;
int V_42 ;
if ( V_433 > V_437 )
return - V_438 ;
V_435 . V_178 = sizeof( struct V_439 ) ;
V_435 . V_132 = F_122 ( V_2 -> V_63 , V_435 . V_178 , & V_435 . V_134 ) ;
if ( ! V_435 . V_132 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_19 ) ;
return - V_343 ;
}
memset ( V_435 . V_132 , 0 , V_435 . V_178 ) ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_435 . V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_440 ,
V_435 . V_178 , V_12 , & V_435 ) ;
V_195 -> V_441 = F_72 ( V_2 -> V_311 ) ;
V_195 -> V_433 = F_72 ( V_433 ) ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_439 * V_56 = V_435 . V_132 ;
memcpy ( V_434 , V_56 -> V_442 , V_443 ) ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
F_123 ( V_2 -> V_63 , V_435 . V_178 , V_435 . V_132 , V_435 . V_134 ) ;
return V_42 ;
}
int F_141 ( struct V_1 * V_2 , struct V_128 * V_435 ,
T_2 V_444 , T_2 V_445 ,
const char * V_446 , T_2 * V_447 ,
T_1 * V_448 , T_1 * V_449 )
{
struct V_11 * V_12 ;
struct V_450 * V_195 ;
struct V_451 * V_56 ;
void * V_233 = NULL ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_2 -> V_48 = 0 ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_452;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_46 ,
sizeof( struct V_450 ) , V_12 ,
NULL ) ;
V_233 = & V_195 -> V_203 ;
F_93 ( struct V_453 ,
V_454 , V_233 , V_444 ) ;
if ( V_444 == 0 )
F_93 ( struct V_453 ,
V_455 , V_233 , 1 ) ;
else
F_93 ( struct V_453 ,
V_455 , V_233 , 0 ) ;
F_73 ( V_233 , sizeof( V_195 -> V_203 ) ) ;
V_195 -> V_456 = F_72 ( V_445 ) ;
F_125 ( V_195 -> V_457 , V_446 , sizeof( V_195 -> V_457 ) ) ;
V_195 -> V_458 = F_72 ( 1 ) ;
V_195 -> V_335 = F_72 ( V_444 ) ;
V_195 -> V_459 = F_72 ( ( V_435 -> V_134 +
sizeof( struct V_450 ) )
& 0xFFFFFFFF ) ;
V_195 -> V_460 = F_72 ( F_59 ( V_435 -> V_134 +
sizeof( struct V_450 ) ) ) ;
F_3 ( V_2 ) ;
F_39 ( & V_2 -> V_188 ) ;
if ( ! F_142 ( & V_2 -> V_45 ,
F_143 ( 60000 ) ) )
V_42 = - V_461 ;
else
V_42 = V_2 -> V_48 ;
V_56 = F_2 ( V_12 ) ;
if ( ! V_42 ) {
* V_447 = F_8 ( V_56 -> V_462 ) ;
* V_448 = V_56 -> V_448 ;
} else {
* V_449 = V_56 -> V_463 ;
}
return V_42 ;
V_452:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_144 ( struct V_1 * V_2 )
{
T_1 V_442 [ V_443 ] ;
int V_42 ;
V_42 = F_140 ( V_2 , V_464 ,
V_442 ) ;
if ( ! V_42 ) {
switch ( V_2 -> V_67 . V_465 ) {
case V_466 :
V_2 -> V_67 . V_467 =
V_442 [ V_468 ] ;
break;
case V_469 :
V_2 -> V_67 . V_467 =
V_442 [ V_470 ] ;
break;
default:
V_2 -> V_67 . V_467 = 0 ;
break;
}
}
return V_42 ;
}
int F_145 ( struct V_1 * V_2 , const char * V_446 )
{
struct V_471 * V_195 ;
struct V_11 * V_12 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_472 ,
sizeof( * V_195 ) , V_12 , NULL ) ;
F_125 ( V_195 -> V_457 , V_446 , sizeof( V_195 -> V_457 ) ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_146 ( struct V_1 * V_2 , struct V_128 * V_435 ,
T_2 V_444 , T_2 V_445 , const char * V_446 ,
T_2 * V_473 , T_2 * V_455 , T_1 * V_449 )
{
struct V_11 * V_12 ;
struct V_474 * V_195 ;
struct V_475 * V_56 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_452;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_476 ,
sizeof( struct V_474 ) , V_12 ,
NULL ) ;
V_195 -> V_477 = F_72 ( V_444 ) ;
V_195 -> V_478 = F_72 ( V_445 ) ;
strcpy ( V_195 -> V_457 , V_446 ) ;
V_195 -> V_458 = F_72 ( 1 ) ;
V_195 -> V_335 = F_72 ( V_444 ) ;
V_195 -> V_459 = F_72 ( ( V_435 -> V_134 & 0xFFFFFFFF ) ) ;
V_195 -> V_460 = F_72 ( F_59 ( V_435 -> V_134 ) ) ;
V_42 = F_51 ( V_2 ) ;
V_56 = F_2 ( V_12 ) ;
if ( ! V_42 ) {
* V_473 = F_8 ( V_56 -> V_479 ) ;
* V_455 = F_8 ( V_56 -> V_455 ) ;
} else {
* V_449 = V_56 -> V_463 ;
}
V_452:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_147 ( struct V_1 * V_2 , struct V_128 * V_435 ,
T_2 V_480 , T_2 V_481 , T_2 V_340 )
{
struct V_11 * V_12 ;
struct F_147 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_2 -> V_48 = 0 ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_452;
}
V_195 = V_435 -> V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_37 , V_435 -> V_178 , V_12 ,
V_435 ) ;
V_195 -> V_309 . V_482 = F_72 ( V_480 ) ;
V_195 -> V_309 . V_483 = F_72 ( V_481 ) ;
V_195 -> V_309 . V_484 = F_72 ( V_340 ) ;
F_3 ( V_2 ) ;
F_39 ( & V_2 -> V_188 ) ;
if ( ! F_142 ( & V_2 -> V_45 ,
F_143 ( 40000 ) ) )
V_42 = - V_461 ;
else
V_42 = V_2 -> V_48 ;
return V_42 ;
V_452:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_148 ( struct V_1 * V_2 , T_1 * V_485 ,
T_3 V_486 , int V_338 )
{
struct V_11 * V_12 ;
struct V_487 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_488 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_309 . V_482 = F_72 ( V_486 ) ;
V_195 -> V_309 . V_483 = F_72 ( V_489 ) ;
V_195 -> V_309 . V_338 = F_72 ( V_338 ) ;
V_195 -> V_309 . V_484 = F_72 ( 0x4 ) ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 )
memcpy ( V_485 , V_195 -> V_490 , 4 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_149 ( struct V_1 * V_2 , T_1 * V_218 ,
struct V_128 * V_306 )
{
struct V_11 * V_12 ;
struct V_491 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_306 -> V_132 ;
F_71 ( & V_195 -> V_199 , V_51 ,
V_492 , sizeof( * V_195 ) ,
V_12 , V_306 ) ;
memcpy ( V_195 -> V_493 , V_218 , V_219 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_150 ( struct V_1 * V_2 , T_1 V_83 ,
T_1 V_494 , T_1 V_495 )
{
struct V_11 * V_12 ;
struct V_496 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_44 ,
V_497 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_498 = V_83 ;
V_195 -> V_499 = V_83 ;
V_195 -> V_494 = V_494 ;
V_195 -> V_500 = V_495 ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_151 ( struct V_1 * V_2 , T_2 V_83 ,
T_2 V_494 , T_2 V_501 , T_2 V_502 ,
T_5 V_503 )
{
struct V_11 * V_12 ;
struct V_504 * V_195 ;
struct V_505 * V_56 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_44 ,
V_43 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_195 -> V_199 . V_158 = F_72 ( 15 ) ;
V_195 -> V_503 = F_152 ( V_503 ) ;
V_195 -> V_498 = F_72 ( V_83 ) ;
V_195 -> V_499 = F_72 ( V_83 ) ;
V_195 -> V_501 = F_72 ( V_501 ) ;
V_195 -> V_502 = F_72 ( V_502 ) ;
V_195 -> V_494 = F_72 ( V_494 ) ;
F_3 ( V_2 ) ;
F_39 ( & V_2 -> V_188 ) ;
F_153 ( & V_2 -> V_45 ) ;
V_56 = F_2 ( V_12 ) ;
V_42 = F_8 ( V_56 -> V_42 ) ;
return V_42 ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_154 ( struct V_1 * V_2 , T_5 V_503 ,
T_2 V_506 , struct V_128 * V_435 )
{
struct V_11 * V_12 ;
struct V_507 * V_195 ;
int V_42 ;
int V_5 , V_508 = 0 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_435 -> V_132 ;
F_71 ( & V_195 -> V_199 , V_44 ,
V_509 , V_435 -> V_178 , V_12 ,
V_435 ) ;
V_195 -> V_503 = F_152 ( V_503 ) ;
V_195 -> V_510 = F_72 ( V_506 ) ;
for ( V_5 = 0 ; V_5 < V_506 ; V_5 ++ ) {
V_195 -> V_511 [ V_5 ] = ( T_1 ) ( V_503 >> ( V_508 * 8 ) ) ;
V_508 ++ ;
if ( V_508 > 7 )
V_508 = 0 ;
}
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_512 * V_56 ;
V_56 = V_435 -> V_132 ;
if ( ( memcmp ( V_56 -> V_513 , V_195 -> V_511 , V_506 ) != 0 ) ||
V_56 -> V_514 ) {
V_42 = - 1 ;
}
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_155 ( struct V_1 * V_2 ,
struct V_128 * V_306 )
{
struct V_11 * V_12 ;
struct V_515 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_306 -> V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_516 , sizeof( * V_195 ) , V_12 ,
V_306 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_156 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_517 * V_195 ;
struct V_128 V_435 ;
int V_42 ;
if ( ! F_1 ( V_2 , V_518 ,
V_47 ) )
return - V_225 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_435 . V_178 = sizeof( struct V_517 ) ;
V_435 . V_132 = F_122 ( V_2 -> V_63 , V_435 . V_178 , & V_435 . V_134 ) ;
if ( ! V_435 . V_132 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_20 ) ;
V_42 = - V_343 ;
goto V_150;
}
V_195 = V_435 . V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_518 , sizeof( * V_195 ) ,
V_12 , & V_435 ) ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_519 * V_520 =
V_435 . V_132 + sizeof( struct V_164 ) ;
V_2 -> V_67 . V_521 = F_24 ( V_520 -> V_521 ) ;
V_2 -> V_67 . V_465 =
F_24 ( V_520 -> V_465 ) ;
V_2 -> V_67 . V_522 =
F_24 ( V_520 -> V_522 ) ;
V_2 -> V_67 . V_523 =
F_24 ( V_520 -> V_523 ) ;
V_2 -> V_67 . V_524 =
F_8 ( V_520 -> V_524 ) ;
if ( F_115 ( V_2 ) ) {
V_2 -> V_67 . V_523 =
V_525 |
V_526 ;
}
}
F_123 ( V_2 -> V_63 , V_435 . V_178 , V_435 . V_132 , V_435 . V_134 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_157 ( struct V_1 * V_2 , T_2 V_527 , T_2 V_220 )
{
struct V_11 * V_12 ;
struct V_528 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_529 , sizeof( * V_195 ) , V_12 , NULL ) ;
V_195 -> V_199 . V_220 = V_220 ;
V_195 -> V_530 = F_72 ( V_531 ) ;
V_195 -> V_532 = F_72 ( V_527 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_158 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_533 * V_195 ;
struct V_534 * V_56 ;
int V_42 ;
int V_342 = F_159 ( sizeof( * V_195 ) , sizeof( * V_56 ) ) ;
struct V_535 * V_536 ;
struct V_128 V_537 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
memset ( & V_537 , 0 , sizeof( struct V_128 ) ) ;
V_537 . V_178 = sizeof( struct V_534 ) ;
V_537 . V_132 = F_122 ( V_2 -> V_63 , V_537 . V_178 ,
& V_537 . V_134 ) ;
if ( ! V_537 . V_132 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_21 ) ;
V_42 = - V_343 ;
goto V_150;
}
V_12 = F_77 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_537 . V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_538 , V_342 ,
V_12 , & V_537 ) ;
V_42 = F_58 ( V_2 ) ;
if ( ! V_42 ) {
V_536 = V_537 . V_132 + sizeof( struct V_28 ) ;
V_2 -> V_311 = V_536 -> V_539 . V_540 ;
}
V_150:
F_86 ( & V_2 -> V_189 ) ;
if ( V_537 . V_132 )
F_123 ( V_2 -> V_63 , V_537 . V_178 ,
V_537 . V_132 , V_537 . V_134 ) ;
return V_42 ;
}
int F_160 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_541 * V_195 ;
int V_42 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
V_12 = F_77 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_542 ,
sizeof( * V_195 ) , V_12 , NULL ) ;
V_195 -> V_543 = F_72 ( V_544 |
V_545 ) ;
V_195 -> V_296 = F_72 ( V_545 ) ;
V_42 = F_58 ( V_2 ) ;
if ( ! V_42 ) {
struct V_546 * V_56 = F_2 ( V_12 ) ;
V_2 -> V_547 = F_8 ( V_56 -> V_296 ) &
V_545 ;
if ( ! V_2 -> V_547 )
F_17 ( & V_2 -> V_63 -> V_64 ,
L_22 ) ;
}
V_150:
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
int F_161 ( struct V_1 * V_2 , T_2 * V_548 ,
T_2 V_220 )
{
struct V_11 * V_12 ;
struct V_549 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_550 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_199 . V_220 = V_220 ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_551 * V_56 =
F_2 ( V_12 ) ;
* V_548 = F_8 ( V_56 -> V_552 ) ;
if ( F_20 ( V_2 ) && F_162 ( V_2 ) &&
F_112 ( V_2 ) )
* V_548 = V_553 ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_163 ( struct V_1 * V_2 , T_2 V_554 ,
T_2 V_220 )
{
struct V_11 * V_12 ;
struct V_555 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_556 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_199 . V_220 = V_220 ;
if ( F_67 ( V_2 ) )
V_195 -> V_557 = F_72 ( V_554 ) ;
else
V_195 -> V_554 = F_72 ( V_554 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_164 ( struct V_1 * V_2 , T_1 * V_218 ,
bool * V_558 , T_2 * V_212 , T_2 V_211 ,
T_1 V_220 )
{
struct V_11 * V_12 ;
struct V_559 * V_195 ;
int V_42 ;
int V_560 ;
struct V_128 V_561 ;
int V_5 ;
memset ( & V_561 , 0 , sizeof( struct V_128 ) ) ;
V_561 . V_178 = sizeof( struct V_562 ) ;
V_561 . V_132 = F_122 ( V_2 -> V_63 ,
V_561 . V_178 ,
& V_561 . V_134 ) ;
if ( ! V_561 . V_132 ) {
F_18 ( & V_2 -> V_63 -> V_64 ,
L_23 ) ;
return - V_343 ;
}
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_121;
}
V_195 = V_561 . V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_563 ,
V_561 . V_178 , V_12 , & V_561 ) ;
V_195 -> V_199 . V_220 = V_220 ;
V_195 -> V_564 = V_215 ;
if ( * V_558 ) {
V_195 -> V_565 = F_72 ( * V_212 ) ;
V_195 -> V_566 = F_92 ( V_211 ) ;
V_195 -> V_567 = 0 ;
} else {
V_195 -> V_567 = 1 ;
}
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_562 * V_56 =
V_561 . V_132 ;
if ( * V_558 ) {
memcpy ( V_218 , V_56 -> V_568 . V_569 . V_570 ,
V_219 ) ;
goto V_121;
}
V_560 = V_56 -> V_571 + V_56 -> V_572 ;
for ( V_5 = 0 ; V_5 < V_560 ; V_5 ++ ) {
struct V_573 * V_574 ;
T_3 V_575 ;
T_2 V_565 ;
V_574 = & V_56 -> V_576 [ V_5 ] ;
V_575 = F_24 ( V_574 -> V_575 ) ;
if ( V_575 == sizeof( T_2 ) ) {
* V_558 = true ;
V_565 = V_574 -> V_569 . V_577 . V_565 ;
* V_212 = F_8 ( V_565 ) ;
goto V_121;
}
}
* V_558 = false ;
memcpy ( V_218 , V_56 -> V_576 [ 0 ] . V_569 . V_570 ,
V_219 ) ;
}
V_121:
F_39 ( & V_2 -> V_188 ) ;
F_123 ( V_2 -> V_63 , V_561 . V_178 ,
V_561 . V_132 , V_561 . V_134 ) ;
return V_42 ;
}
int F_165 ( struct V_1 * V_2 , T_2 V_578 ,
T_1 * V_218 , T_2 V_211 , bool V_579 , T_2 V_220 )
{
if ( ! V_579 )
F_164 ( V_2 , V_218 , & V_579 , & V_578 ,
V_211 , V_220 ) ;
if ( F_20 ( V_2 ) )
return F_96 ( V_2 , V_218 , false ,
V_211 , V_578 ) ;
else
return F_164 ( V_2 , V_218 , & V_579 ,
& V_578 ,
V_211 , V_220 ) ;
}
int F_166 ( struct V_1 * V_2 , T_1 * V_218 )
{
int V_42 ;
bool V_580 = false ;
memset ( V_218 , 0 , V_219 ) ;
if ( F_20 ( V_2 ) ) {
if ( F_112 ( V_2 ) )
V_42 = F_96 ( V_2 , V_218 , true , 0 ,
0 ) ;
else
V_42 = F_96 ( V_2 , V_218 , false ,
V_2 -> V_211 , 0 ) ;
} else {
V_42 = F_164 ( V_2 , V_218 , & V_580 ,
NULL , V_2 -> V_211 , 0 ) ;
}
return V_42 ;
}
int F_167 ( struct V_1 * V_2 , T_1 * V_581 ,
T_1 V_560 , T_2 V_220 )
{
struct V_11 * V_12 ;
struct V_582 * V_195 ;
int V_42 ;
struct V_128 V_435 ;
memset ( & V_435 , 0 , sizeof( struct V_128 ) ) ;
V_435 . V_178 = sizeof( struct V_582 ) ;
V_435 . V_132 = F_168 ( & V_2 -> V_63 -> V_64 , V_435 . V_178 ,
& V_435 . V_134 , V_583 ) ;
if ( ! V_435 . V_132 )
return - V_343 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_435 . V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_584 , sizeof( * V_195 ) ,
V_12 , & V_435 ) ;
V_195 -> V_199 . V_220 = V_220 ;
V_195 -> V_560 = V_560 ;
if ( V_560 )
memcpy ( V_195 -> V_218 , V_581 , V_219 * V_560 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_169 ( & V_2 -> V_63 -> V_64 , V_435 . V_178 , V_435 . V_132 , V_435 . V_134 ) ;
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_170 ( struct V_1 * V_2 , T_1 * V_218 , int V_216 , T_2 V_226 )
{
bool V_585 = false ;
T_1 V_586 [ V_219 ] ;
T_2 V_212 ;
int V_42 ;
V_42 = F_164 ( V_2 , V_586 , & V_585 ,
& V_212 , V_216 , V_226 ) ;
if ( ! V_42 && V_585 )
F_98 ( V_2 , V_216 , V_212 , V_226 ) ;
return F_167 ( V_2 , V_218 , V_218 ? 1 : 0 , V_226 ) ;
}
int F_171 ( struct V_1 * V_2 , T_3 V_87 ,
T_2 V_220 , T_3 V_587 , T_3 V_588 )
{
struct V_11 * V_12 ;
struct V_589 * V_195 ;
void * V_233 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
V_233 = & V_195 -> V_203 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_590 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_195 -> V_199 . V_220 = V_220 ;
F_93 ( struct V_591 , V_278 , V_233 , V_587 ) ;
if ( V_87 ) {
F_93 ( struct V_591 , V_592 , V_233 , 1 ) ;
F_93 ( struct V_591 , V_87 , V_233 , V_87 ) ;
}
if ( ! F_20 ( V_2 ) && V_588 ) {
F_93 ( struct V_591 , V_278 ,
V_233 , V_2 -> V_311 ) ;
F_93 ( struct V_591 , V_593 , V_233 , 1 ) ;
F_93 ( struct V_591 , V_594 ,
V_233 , V_588 ) ;
}
F_73 ( V_195 -> V_203 , sizeof( V_195 -> V_203 ) ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_172 ( struct V_1 * V_2 , T_3 * V_87 ,
T_2 V_220 , T_3 V_587 , T_1 * V_595 )
{
struct V_11 * V_12 ;
struct V_596 * V_195 ;
void * V_233 ;
int V_42 ;
T_3 V_597 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
V_233 = & V_195 -> V_203 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_598 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_195 -> V_199 . V_220 = V_220 ;
F_93 ( struct V_599 , V_278 ,
V_233 , V_587 ) ;
F_93 ( struct V_599 , V_592 , V_233 , 1 ) ;
if ( ! F_20 ( V_2 ) && V_595 ) {
F_93 ( struct V_599 , V_278 ,
V_233 , V_2 -> V_311 ) ;
F_93 ( struct V_599 , V_593 , V_233 , 1 ) ;
}
F_73 ( V_195 -> V_203 , sizeof( V_195 -> V_203 ) ) ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_600 * V_56 =
F_2 ( V_12 ) ;
F_16 ( & V_56 -> V_203 , sizeof( V_56 -> V_203 ) ) ;
V_597 = F_173 ( struct V_601 ,
V_87 , & V_56 -> V_203 ) ;
if ( V_87 )
* V_87 = F_24 ( V_597 ) ;
if ( V_595 )
* V_595 = F_173 ( struct V_601 ,
V_594 , & V_56 -> V_203 ) ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_174 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_602 * V_195 ;
int V_42 = 0 ;
struct V_128 V_435 ;
if ( ! F_1 ( V_2 , V_492 ,
V_51 ) )
return - V_225 ;
if ( F_175 ( V_2 ) )
return V_42 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
memset ( & V_435 , 0 , sizeof( struct V_128 ) ) ;
V_435 . V_178 = sizeof( struct V_603 ) ;
V_435 . V_132 = F_122 ( V_2 -> V_63 , V_435 . V_178 , & V_435 . V_134 ) ;
if ( ! V_435 . V_132 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_21 ) ;
V_42 = - V_343 ;
goto V_150;
}
V_12 = F_77 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_435 . V_132 ;
F_71 ( & V_195 -> V_199 , V_51 ,
V_492 ,
sizeof( * V_195 ) , V_12 , & V_435 ) ;
V_195 -> V_199 . V_170 = 1 ;
V_195 -> V_604 = V_605 ;
V_42 = F_58 ( V_2 ) ;
if ( ! V_42 ) {
struct V_603 * V_56 ;
V_56 = (struct V_603 * ) V_435 . V_132 ;
V_2 -> V_606 = V_56 -> V_607 ;
if ( V_2 -> V_606 & V_608 )
V_2 -> V_609 = true ;
}
V_150:
F_86 ( & V_2 -> V_189 ) ;
if ( V_435 . V_132 )
F_123 ( V_2 -> V_63 , V_435 . V_178 , V_435 . V_132 , V_435 . V_134 ) ;
return V_42 ;
}
int F_176 ( struct V_1 * V_2 , T_2 V_610 )
{
struct V_128 V_611 ;
struct V_612 * V_613 ;
int V_42 ;
int V_5 , V_508 ;
memset ( & V_611 , 0 , sizeof( struct V_128 ) ) ;
V_611 . V_178 = sizeof( struct V_614 ) ;
V_611 . V_132 = F_122 ( V_2 -> V_63 , V_611 . V_178 ,
& V_611 . V_134 ) ;
if ( ! V_611 . V_132 )
return - V_343 ;
V_42 = F_177 ( V_2 , & V_611 ) ;
if ( V_42 )
goto V_150;
V_613 = (struct V_612 * )
( V_611 . V_132 + sizeof( struct V_28 ) ) ;
for ( V_5 = 0 ; V_5 < F_8 ( V_613 -> V_615 ) ; V_5 ++ ) {
T_2 V_616 = F_8 ( V_613 -> V_617 [ V_5 ] . V_616 ) ;
for ( V_508 = 0 ; V_508 < V_616 ; V_508 ++ ) {
if ( V_613 -> V_617 [ V_5 ] . V_618 [ V_508 ] . V_595 == V_619 )
V_613 -> V_617 [ V_5 ] . V_618 [ V_508 ] . V_620 =
F_72 ( V_610 ) ;
}
}
V_42 = F_178 ( V_2 , & V_611 , V_613 ) ;
V_150:
F_123 ( V_2 -> V_63 , V_611 . V_178 , V_611 . V_132 ,
V_611 . V_134 ) ;
return V_42 ;
}
int F_179 ( struct V_1 * V_2 )
{
struct V_128 V_611 ;
struct V_612 * V_613 ;
int V_42 , V_508 ;
int V_610 = 0 ;
memset ( & V_611 , 0 , sizeof( struct V_128 ) ) ;
V_611 . V_178 = sizeof( struct V_614 ) ;
V_611 . V_132 = F_122 ( V_2 -> V_63 , V_611 . V_178 ,
& V_611 . V_134 ) ;
if ( ! V_611 . V_132 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_24 ,
V_621 ) ;
goto V_150;
}
V_42 = F_177 ( V_2 , & V_611 ) ;
if ( ! V_42 ) {
V_613 = (struct V_612 * ) ( V_611 . V_132 +
sizeof( struct V_28 ) ) ;
for ( V_508 = 0 ; V_508 < F_8 ( V_613 -> V_617 [ 0 ] . V_616 ) ; V_508 ++ ) {
if ( V_613 -> V_617 [ 0 ] . V_618 [ V_508 ] . V_595 == V_619 )
V_610 = V_613 -> V_617 [ 0 ] . V_618 [ V_508 ] . V_620 ;
}
}
F_123 ( V_2 -> V_63 , V_611 . V_178 , V_611 . V_132 ,
V_611 . V_134 ) ;
V_150:
return V_610 ;
}
int F_177 ( struct V_1 * V_2 ,
struct V_128 * V_435 )
{
struct V_11 * V_12 ;
struct V_622 * V_195 ;
int V_42 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
V_12 = F_77 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_435 -> V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_623 ,
V_435 -> V_178 , V_12 , V_435 ) ;
V_195 -> V_624 = F_72 ( 1 ) ;
V_42 = F_58 ( V_2 ) ;
V_150:
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
int F_178 ( struct V_1 * V_2 ,
struct V_128 * V_435 ,
struct V_612 * V_625 )
{
struct V_11 * V_12 ;
struct V_626 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_435 -> V_132 ;
memcpy ( & V_195 -> V_627 , V_625 , sizeof( struct V_612 ) ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_628 ,
V_435 -> V_178 , V_12 , V_435 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_180 ( struct V_1 * V_2 , T_1 * V_629 )
{
struct V_11 * V_12 ;
struct V_630 * V_195 ;
int V_42 ;
if ( ! F_67 ( V_2 ) ) {
* V_629 = V_2 -> V_311 + '0' ;
return 0 ;
}
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_631 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_195 -> V_199 . V_170 = 1 ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_632 * V_56 = F_2 ( V_12 ) ;
* V_629 = V_56 -> V_629 [ V_2 -> V_311 ] ;
} else {
* V_629 = V_2 -> V_311 + '0' ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
static struct V_633 * F_181 ( T_1 * V_336 , T_2 V_634 ,
int V_635 )
{
struct V_636 * V_199 = (struct V_636 * ) V_336 ;
struct V_633 * V_637 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_634 ; V_5 ++ ) {
if ( V_199 -> V_635 == V_638 ||
V_199 -> V_635 == V_639 ) {
V_637 = (struct V_633 * ) V_199 ;
if ( V_635 == V_640 ||
( V_635 == V_641 &&
V_637 -> V_26 & ( 1 << V_642 ) ) )
return V_637 ;
}
V_199 -> V_643 = V_199 -> V_643 ? : V_644 ;
V_199 = ( void * ) V_199 + V_199 -> V_643 ;
}
return NULL ;
}
static struct V_633 * F_182 ( T_1 * V_336 , T_2 V_634 )
{
return F_181 ( V_336 , V_634 , V_641 ) ;
}
static struct V_633 * F_183 ( T_1 * V_336 , T_2 V_634 )
{
return F_181 ( V_336 , V_634 , V_640 ) ;
}
static struct V_645 * F_184 ( T_1 V_646 , T_1 * V_336 ,
T_2 V_634 )
{
struct V_636 * V_199 = (struct V_636 * ) V_336 ;
struct V_645 * V_647 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_634 ; V_5 ++ ) {
if ( ( V_199 -> V_635 == V_648 ||
V_199 -> V_635 == V_649 ) ) {
V_647 = (struct V_645 * ) V_199 ;
if ( V_647 -> V_650 == V_646 )
return V_647 ;
}
V_199 -> V_643 = V_199 -> V_643 ? : V_644 ;
V_199 = ( void * ) V_199 + V_199 -> V_643 ;
}
return NULL ;
}
static struct V_651 * F_185 ( T_1 * V_336 , T_2 V_634 )
{
struct V_636 * V_199 = (struct V_636 * ) V_336 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_634 ; V_5 ++ ) {
if ( V_199 -> V_635 == V_652 )
return (struct V_651 * ) V_199 ;
V_199 -> V_643 = V_199 -> V_643 ? : V_644 ;
V_199 = ( void * ) V_199 + V_199 -> V_643 ;
}
return NULL ;
}
static void F_186 ( struct V_653 * V_654 ,
struct V_633 * V_655 )
{
V_654 -> V_656 = F_24 ( V_655 -> V_657 ) ;
V_654 -> V_658 = F_24 ( V_655 -> V_659 ) ;
V_654 -> V_660 = F_24 ( V_655 -> V_661 ) ;
V_654 -> V_662 = F_24 ( V_655 -> V_663 ) ;
V_654 -> V_664 = F_24 ( V_655 -> V_665 ) ;
V_654 -> V_666 = F_24 ( V_655 -> V_667 ) ;
V_654 -> V_668 = F_24 ( V_655 -> V_669 ) ;
V_654 -> V_670 = F_8 ( V_655 -> V_296 ) &
V_671 ;
if ( V_654 -> V_664 && V_654 -> V_664 == V_654 -> V_666 )
V_654 -> V_664 -= 1 ;
}
int F_187 ( struct V_1 * V_2 , struct V_653 * V_654 )
{
struct V_11 * V_12 ;
struct V_672 * V_195 ;
int V_42 ;
struct V_128 V_435 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
memset ( & V_435 , 0 , sizeof( struct V_128 ) ) ;
V_435 . V_178 = sizeof( struct V_673 ) ;
V_435 . V_132 = F_122 ( V_2 -> V_63 , V_435 . V_178 , & V_435 . V_134 ) ;
if ( ! V_435 . V_132 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_20 ) ;
V_42 = - V_343 ;
goto V_150;
}
V_12 = F_77 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_435 . V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_674 ,
V_435 . V_178 , V_12 , & V_435 ) ;
if ( F_188 ( V_2 ) )
V_195 -> V_199 . V_170 = 1 ;
V_42 = F_58 ( V_2 ) ;
if ( ! V_42 ) {
struct V_673 * V_56 = V_435 . V_132 ;
T_2 V_634 = F_8 ( V_56 -> V_634 ) ;
struct V_633 * V_655 ;
V_655 = F_183 ( V_56 -> V_675 , V_634 ) ;
if ( ! V_655 ) {
V_42 = - V_438 ;
goto V_150;
}
V_2 -> V_676 = V_655 -> V_650 ;
F_186 ( V_654 , V_655 ) ;
}
V_150:
F_86 ( & V_2 -> V_189 ) ;
if ( V_435 . V_132 )
F_123 ( V_2 -> V_63 , V_435 . V_178 , V_435 . V_132 , V_435 . V_134 ) ;
return V_42 ;
}
int F_189 ( struct V_1 * V_2 ,
struct V_653 * V_654 , T_1 V_220 )
{
struct V_677 * V_56 ;
struct V_678 * V_195 ;
struct V_633 * V_679 ;
struct V_645 * V_647 ;
struct V_651 * V_441 ;
struct V_633 * V_637 ;
struct V_11 V_12 = { 0 } ;
struct V_128 V_435 ;
T_2 V_634 ;
int V_42 ;
memset ( & V_435 , 0 , sizeof( struct V_128 ) ) ;
V_435 . V_178 = sizeof( struct V_677 ) ;
V_435 . V_132 = F_122 ( V_2 -> V_63 , V_435 . V_178 , & V_435 . V_134 ) ;
if ( ! V_435 . V_132 )
return - V_343 ;
V_195 = V_435 . V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_680 ,
V_435 . V_178 , & V_12 , & V_435 ) ;
V_195 -> V_199 . V_220 = V_220 ;
if ( ! F_67 ( V_2 ) )
V_195 -> V_199 . V_170 = 1 ;
V_195 -> type = V_681 ;
V_42 = F_88 ( V_2 , & V_12 ) ;
if ( V_42 )
goto V_150;
V_56 = V_435 . V_132 ;
V_634 = F_8 ( V_56 -> V_634 ) ;
V_647 = F_184 ( V_2 -> V_63 -> V_646 , V_56 -> V_675 ,
V_634 ) ;
if ( V_647 )
V_654 -> V_682 = F_24 ( V_647 -> V_683 ) ;
V_441 = F_185 ( V_56 -> V_675 , V_634 ) ;
if ( V_441 )
V_2 -> V_684 = V_441 -> V_684 ;
V_637 = F_183 ( V_56 -> V_675 , V_634 ) ;
if ( V_637 )
F_186 ( V_654 , V_637 ) ;
V_679 = F_182 ( V_56 -> V_675 , V_634 ) ;
if ( V_679 )
V_654 -> V_685 = V_679 -> V_296 ;
V_150:
if ( V_435 . V_132 )
F_123 ( V_2 -> V_63 , V_435 . V_178 , V_435 . V_132 , V_435 . V_134 ) ;
return V_42 ;
}
static int F_190 ( struct V_1 * V_2 , void * V_655 ,
int V_178 , int V_204 , T_1 V_170 , T_1 V_220 )
{
struct V_686 * V_195 ;
struct V_11 V_12 = { 0 } ;
struct V_128 V_435 ;
int V_42 ;
memset ( & V_435 , 0 , sizeof( struct V_128 ) ) ;
V_435 . V_178 = sizeof( struct V_686 ) ;
V_435 . V_132 = F_122 ( V_2 -> V_63 , V_435 . V_178 , & V_435 . V_134 ) ;
if ( ! V_435 . V_132 )
return - V_343 ;
V_195 = V_435 . V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_687 , V_435 . V_178 ,
& V_12 , & V_435 ) ;
V_195 -> V_199 . V_170 = V_170 ;
V_195 -> V_199 . V_220 = V_220 ;
V_195 -> V_634 = F_72 ( V_204 ) ;
memcpy ( V_195 -> V_655 , V_655 , V_178 ) ;
V_42 = F_88 ( V_2 , & V_12 ) ;
if ( V_435 . V_132 )
F_123 ( V_2 -> V_63 , V_435 . V_178 , V_435 . V_132 , V_435 . V_134 ) ;
return V_42 ;
}
static void F_191 ( struct V_633 * V_637 )
{
memset ( V_637 , 0 , sizeof( * V_637 ) ) ;
V_637 -> V_657 = 0xFFFF ;
V_637 -> V_688 = 0xFFFF ;
V_637 -> V_659 = 0xFFFF ;
V_637 -> V_661 = 0xFFFF ;
V_637 -> V_663 = 0xFFFF ;
V_637 -> V_667 = 0xFFFF ;
V_637 -> V_665 = 0xFFFF ;
V_637 -> V_689 = 0xFFFF ;
V_637 -> V_690 = 0xFFFF ;
V_637 -> V_691 = 0xFFFF ;
V_637 -> V_669 = 0xFFFF ;
V_637 -> V_692 = 0xFFFF ;
V_637 -> V_693 = 0xFF ;
V_637 -> V_694 = F_92 ( 0xF000 ) ;
V_637 -> V_695 = 0xFF ;
V_637 -> V_696 = 0x0F ;
V_637 -> V_697 = 0xFFFF ;
V_637 -> V_698 = 0xFFFF ;
V_637 -> V_699 = 0xFFFFFFFF ;
V_637 -> V_700 = 0xFFFFFFFF ;
}
static void F_192 ( struct V_645 * V_647 )
{
memset ( V_647 , 0 , sizeof( * V_647 ) ) ;
V_647 -> V_701 = 0xFF ;
V_647 -> V_702 = 0xFF ;
V_647 -> V_703 = 0xFF ;
V_647 -> V_683 = 0xFFFF ;
}
int F_193 ( struct V_1 * V_2 , T_2 V_704 , T_3 V_68 ,
T_1 V_220 )
{
struct V_633 V_705 ;
T_2 V_706 ;
T_3 V_170 = 0 ;
if ( F_111 ( V_2 ) )
return F_157 ( V_2 , V_704 / 10 , V_220 ) ;
F_191 ( & V_705 ) ;
V_705 . V_650 = V_2 -> V_676 ;
V_705 . V_707 = V_220 ;
if ( F_67 ( V_2 ) ) {
V_705 . V_199 . V_635 = V_638 ;
V_705 . V_199 . V_643 = V_644 ;
V_705 . V_26 = ( 1 << V_708 ) | ( 1 << V_709 ) |
( 1 << V_710 ) ;
V_705 . V_700 = F_72 ( V_704 / 10 ) ;
} else {
V_170 = 1 ;
V_705 . V_199 . V_635 = V_639 ;
V_705 . V_199 . V_643 = V_711 ;
V_705 . V_26 = ( 1 << V_709 ) | ( 1 << V_710 ) ;
V_706 = V_704 ? ( V_704 * 100 ) / V_68 : 100 ;
V_705 . V_700 = F_72 ( V_706 ) ;
}
return F_190 ( V_2 , & V_705 ,
V_705 . V_199 . V_643 ,
1 , V_170 , V_220 ) ;
}
int F_194 ( struct V_1 * V_2 ,
struct V_653 V_654 , T_3 V_683 )
{
struct {
struct V_645 V_647 ;
struct V_633 V_712 ;
} V_713 V_655 ;
T_3 V_714 ;
if ( F_20 ( V_2 ) || F_67 ( V_2 ) )
return 0 ;
F_192 ( & V_655 . V_647 ) ;
V_655 . V_647 . V_199 . V_635 = V_649 ;
V_655 . V_647 . V_199 . V_643 = V_711 ;
V_655 . V_647 . V_26 = ( 1 << V_709 ) | ( 1 << V_710 ) ;
V_655 . V_647 . V_650 = V_2 -> V_63 -> V_646 ;
V_655 . V_647 . V_701 = V_683 ? 1 : 0 ;
V_655 . V_647 . V_683 = F_92 ( V_683 ) ;
F_191 ( & V_655 . V_712 ) ;
V_655 . V_712 . V_199 . V_635 = V_639 ;
V_655 . V_712 . V_199 . V_643 = V_711 ;
V_655 . V_712 . V_26 = ( 1 << V_642 ) | ( 1 << V_709 ) |
( 1 << V_710 ) ;
V_655 . V_712 . V_650 = V_2 -> V_63 -> V_646 ;
V_655 . V_712 . V_707 = 0 ;
if ( V_683 && V_654 . V_685 & V_415 ) {
if ( V_683 < ( F_195 ( V_2 ) - 8 ) )
V_714 = ( V_654 . V_664 - 8 ) / V_683 ;
else
V_714 = V_654 . V_664 / V_683 ;
V_655 . V_712 . V_667 = F_92 ( V_714 ) ;
V_655 . V_712 . V_663 = F_92 ( V_714 ) ;
V_655 . V_712 . V_665 = F_92 ( V_714 - 1 ) ;
V_655 . V_712 . V_690 = F_92 ( 3 * V_714 ) ;
} else {
V_655 . V_712 . V_663 = F_92 ( 1 ) ;
V_655 . V_712 . V_667 = F_92 ( 1 ) ;
V_655 . V_712 . V_665 = F_92 ( 0 ) ;
V_655 . V_712 . V_690 = F_92 ( 3 ) ;
}
return F_190 ( V_2 , & V_655 ,
2 * V_711 , 2 , 1 , 0 ) ;
}
int F_196 ( struct V_1 * V_2 , T_2 V_715 , T_1 V_716 )
{
struct V_11 * V_12 ;
struct V_717 * V_195 ;
int V_42 ;
if ( V_715 == 0xFFFFFFFF )
return - 1 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_718 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_716 = V_716 ;
V_195 -> V_719 = F_72 ( V_715 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_197 ( struct V_1 * V_2 , T_6 V_441 )
{
struct V_651 V_720 ;
memset ( & V_720 , 0 , sizeof( V_720 ) ) ;
V_720 . V_199 . V_635 = V_652 ;
V_720 . V_199 . V_643 = V_711 ;
V_720 . V_26 = ( 1 << V_709 ) | ( 1 << V_710 ) ;
V_720 . V_721 = V_2 -> V_311 ;
if ( V_441 ) {
V_720 . V_722 = V_723 | ( 1 << V_724 ) |
( 1 << V_725 ) ;
V_720 . V_726 = F_198 ( V_441 ) ;
} else {
V_720 . V_722 = V_727 ;
V_720 . V_726 = 0 ;
}
return F_190 ( V_2 , & V_720 ,
V_711 , 1 , 1 , 0 ) ;
}
int F_199 ( struct V_1 * V_2 , struct V_728 * V_729 ,
int V_707 )
{
struct V_11 * V_12 ;
struct V_730 * V_195 ;
struct V_731 * V_56 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_732 , sizeof( * V_56 ) ,
V_12 , NULL ) ;
V_195 -> V_199 . V_220 = V_707 + 1 ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
V_56 = (struct V_731 * ) V_195 ;
V_729 -> V_211 = F_8 ( V_56 -> V_733 . V_216 ) ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
static int F_200 ( struct V_1 * V_2 )
{
#define F_201 30
T_2 V_734 ;
int V_42 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < F_201 ; V_5 ++ ) {
V_734 = F_55 ( V_2 -> V_22 + V_735 ) ;
if ( ( V_734 & V_736 ) == 0 )
break;
F_202 ( 1 ) ;
}
if ( V_5 == F_201 )
V_42 = - 1 ;
return V_42 ;
}
int F_203 ( struct V_1 * V_2 , T_2 V_737 )
{
int V_42 = 0 ;
V_42 = F_200 ( V_2 ) ;
if ( V_42 )
return V_42 ;
F_6 ( V_737 , V_2 -> V_22 + V_735 ) ;
return V_42 ;
}
bool F_204 ( struct V_1 * V_2 )
{
T_2 V_140 = 0 ;
V_140 = F_55 ( V_2 -> V_22 + V_141 ) ;
return ! ! ( V_140 & V_738 ) ;
}
int F_205 ( struct V_1 * V_2 )
{
struct V_159 * V_64 = & V_2 -> V_63 -> V_64 ;
int V_42 ;
if ( F_204 ( V_2 ) ) {
F_26 ( V_64 , L_25 ) ;
return - V_739 ;
}
V_42 = F_203 ( V_2 , V_740 |
V_741 ) ;
if ( V_42 < 0 ) {
F_18 ( V_64 , L_26 ) ;
return V_42 ;
}
V_42 = F_200 ( V_2 ) ;
if ( V_42 )
return V_42 ;
if ( ! F_204 ( V_2 ) ) {
F_18 ( V_64 , L_27 ) ;
return - V_116 ;
}
return 0 ;
}
int F_206 ( struct V_1 * V_2 )
{
int V_42 ;
V_42 = F_145 ( V_2 , V_742 ) ;
return F_207 ( V_42 ) ;
}
int F_208 ( struct V_1 * V_2 , T_1 V_220 )
{
struct V_11 * V_12 ;
struct V_743 * V_195 ;
int V_42 ;
if ( F_20 ( V_2 ) )
return 0 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_744 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_199 . V_220 = V_220 ;
V_195 -> V_495 = 1 ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_209 ( struct V_1 * V_2 , bool V_745 )
{
struct V_11 * V_12 ;
struct V_746 * V_195 ;
int V_42 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
V_12 = F_77 ( V_2 ) ;
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_747 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_748 = V_745 ;
V_42 = F_58 ( V_2 ) ;
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
int F_210 ( struct V_1 * V_2 , T_3 * V_749 )
{
struct V_750 * V_195 ;
struct V_11 * V_12 ;
int V_42 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
V_12 = F_77 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_751 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_42 = F_58 ( V_2 ) ;
if ( ! V_42 ) {
struct V_752 * V_56 =
F_2 ( V_12 ) ;
* V_749 = F_24 ( V_56 -> V_753 ) ;
}
V_150:
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
int F_211 ( struct V_1 * V_2 ,
int V_754 , T_1 V_220 )
{
struct V_11 * V_12 ;
struct V_755 * V_195 ;
int V_42 ;
if ( F_20 ( V_2 ) || F_67 ( V_2 ) )
return 0 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_756 ,
sizeof( * V_195 ) , V_12 , NULL ) ;
V_195 -> V_199 . V_170 = 1 ;
V_195 -> V_199 . V_220 = V_220 ;
if ( V_754 == V_757 )
V_195 -> V_758 |= 1 ;
if ( V_754 == V_759 )
V_195 -> V_758 |= 1 << V_760 ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_212 ( void * V_761 , void * V_762 ,
int V_763 , T_3 * V_764 , T_3 * V_765 )
{
struct V_1 * V_2 = F_213 ( V_761 ) ;
struct V_11 * V_12 ;
struct V_164 * V_199 = (struct V_164 * ) V_762 ;
struct V_164 * V_195 ;
struct V_28 * V_56 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
V_56 = F_2 ( V_12 ) ;
F_71 ( V_195 , V_199 -> V_4 ,
V_199 -> V_3 , V_763 , V_12 , NULL ) ;
memcpy ( V_195 , V_762 , V_763 ) ;
F_73 ( V_195 , V_763 ) ;
V_42 = F_51 ( V_2 ) ;
if ( V_764 )
* V_764 = ( V_42 & 0xffff ) ;
if ( V_765 )
* V_765 = 0 ;
memcpy ( V_762 , V_56 , sizeof( * V_56 ) + V_56 -> V_766 ) ;
F_16 ( V_762 , sizeof( * V_56 ) + V_56 -> V_766 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
