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
F_17 ( & V_2 -> V_63 -> V_64 , L_4 ,
V_90 ) ;
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
F_17 ( & V_2 -> V_63 -> V_64 , L_5 ,
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
F_18 ( & V_2 -> V_63 -> V_64 , L_6 ) ;
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
F_18 ( & V_2 -> V_63 -> V_64 , L_6 ) ;
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
F_18 ( & V_2 -> V_63 -> V_64 , L_7 ) ;
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
F_26 ( V_64 , L_8 , V_158 ) ;
if ( F_68 ( 2000 ) ) {
F_18 ( V_64 , L_9 ) ;
return - V_161 ;
}
V_158 += 2 ;
} while ( V_158 < 60 );
F_18 ( V_64 , L_10 , V_157 ) ;
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
V_228 , sizeof( * V_195 ) , V_12 , NULL ) ;
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
F_17 ( & V_2 -> V_63 -> V_64 , L_11
L_12
L_13 ) ;
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
void F_121 ( struct V_1 * V_2 , T_2 V_335 , void * V_336 )
{
struct V_128 V_337 ;
struct V_11 * V_12 ;
struct V_330 * V_195 ;
T_2 V_338 = 0 , V_339 , V_340 ,
V_341 = sizeof( T_2 ) , V_342 ;
int V_42 ;
if ( V_335 == 0 )
return;
V_339 = V_335 ;
V_337 . V_178 = sizeof( struct V_330 ) + 60 * 1024 ;
V_337 . V_132 = F_122 ( V_2 -> V_63 ,
V_337 . V_178 ,
& V_337 . V_134 ) ;
if ( ! V_337 . V_132 ) {
V_42 = - V_343 ;
F_18 ( & V_2 -> V_63 -> V_64 ,
L_14 ) ;
return;
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
F_18 ( & V_2 -> V_63 -> V_64 , L_15 ) ;
goto V_150;
}
V_338 += V_340 ;
V_341 += V_340 ;
}
V_150:
F_123 ( V_2 -> V_63 , V_337 . V_178 ,
V_337 . V_132 , V_337 . V_134 ) ;
F_39 ( & V_2 -> V_188 ) ;
}
int F_124 ( struct V_1 * V_2 , char * V_349 ,
char * V_350 )
{
struct V_11 * V_12 ;
struct V_351 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_352 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_353 * V_56 = F_2 ( V_12 ) ;
strcpy ( V_349 , V_56 -> V_354 ) ;
if ( V_350 )
strcpy ( V_350 , V_56 -> V_355 ) ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_125 ( struct V_1 * V_2 , struct V_356 * V_357 ,
int V_111 )
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
int F_126 ( struct V_1 * V_2 , T_2 V_216 , T_3 * V_363 ,
T_2 V_111 )
{
struct V_11 * V_12 ;
struct V_364 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_365 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_278 = V_216 ;
V_195 -> V_366 = V_367 & F_127 ( V_2 ) ? 1 : 0 ;
V_195 -> V_368 = V_111 ;
memcpy ( V_195 -> V_369 , V_363 ,
V_195 -> V_368 * sizeof( V_363 [ 0 ] ) ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_128 ( struct V_1 * V_2 , T_2 V_26 , T_2 V_370 )
{
struct V_11 * V_12 ;
struct V_128 * V_167 = & V_2 -> V_371 ;
struct V_372 * V_195 = V_167 -> V_132 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
memset ( V_195 , 0 , sizeof( * V_195 ) ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_373 , sizeof( * V_195 ) ,
V_12 , V_167 ) ;
V_195 -> V_216 = F_72 ( V_2 -> V_211 ) ;
if ( V_26 & V_374 ) {
V_195 -> V_375 = F_72 ( V_376 |
V_377 |
V_378 ) ;
if ( V_370 == V_379 )
V_195 -> V_380 =
F_72 ( V_376 |
V_377 |
V_378 ) ;
} else if ( V_26 & V_381 ) {
V_195 -> V_375 = V_195 -> V_380 =
F_72 ( V_378 ) ;
} else if ( V_26 & V_382 ) {
V_195 -> V_375 = F_72 ( V_377 ) ;
if ( V_370 == V_379 )
V_195 -> V_380 =
F_72 ( V_377 ) ;
} else {
struct V_383 * V_384 ;
int V_5 = 0 ;
V_195 -> V_375 = V_195 -> V_380 =
F_72 ( V_385 ) ;
V_195 -> V_375 |=
F_72 ( V_378 &
F_127 ( V_2 ) ) ;
V_195 -> V_386 = F_72 ( F_129 ( V_2 -> V_387 ) ) ;
F_130 (ha, adapter->netdev)
memcpy ( V_195 -> V_388 [ V_5 ++ ] . V_389 , V_384 -> V_31 , V_219 ) ;
}
if ( ( V_195 -> V_375 & F_72 ( F_127 ( V_2 ) ) ) !=
V_195 -> V_375 ) {
F_17 ( & V_2 -> V_63 -> V_64 ,
L_16 ,
V_195 -> V_375 ) ;
F_17 ( & V_2 -> V_63 -> V_64 ,
L_17 ,
F_127 ( V_2 ) ) ;
}
V_195 -> V_375 &= F_72 ( F_127 ( V_2 ) ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_131 ( struct V_1 * V_2 , T_2 V_390 , T_2 V_391 )
{
struct V_11 * V_12 ;
struct V_392 * V_195 ;
int V_42 ;
if ( ! F_1 ( V_2 , V_393 ,
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
V_393 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_394 = F_92 ( ( T_3 ) V_390 ) ;
V_195 -> V_395 = F_92 ( ( T_3 ) V_391 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_132 ( struct V_1 * V_2 , T_2 * V_390 , T_2 * V_391 )
{
struct V_11 * V_12 ;
struct V_396 * V_195 ;
int V_42 ;
if ( ! F_1 ( V_2 , V_397 ,
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
V_397 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_398 * V_56 =
F_2 ( V_12 ) ;
* V_390 = F_24 ( V_56 -> V_394 ) ;
* V_391 = F_24 ( V_56 -> V_395 ) ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_133 ( struct V_1 * V_2 , T_2 * V_83 ,
T_2 * V_399 , T_2 * V_400 , T_3 * V_401 )
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
* V_83 = F_8 ( V_56 -> V_405 ) ;
* V_399 = F_8 ( V_56 -> V_406 ) ;
* V_400 = F_8 ( V_56 -> V_262 ) ;
* V_401 = F_8 ( V_56 -> V_407 ) & 0xFF ;
}
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
int F_134 ( struct V_1 * V_2 )
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
V_408 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_42 = F_58 ( V_2 ) ;
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
int F_135 ( struct V_1 * V_2 , T_1 * V_409 ,
T_2 V_410 , T_3 V_411 , const T_1 * V_412 )
{
struct V_11 * V_12 ;
struct V_413 * V_195 ;
int V_42 ;
if ( ! ( F_127 ( V_2 ) & V_414 ) )
return 0 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_51 ,
V_415 , sizeof( * V_195 ) , V_12 , NULL ) ;
V_195 -> V_216 = F_72 ( V_2 -> V_211 ) ;
V_195 -> V_416 = F_92 ( V_410 ) ;
V_195 -> V_417 = F_92 ( F_101 ( V_411 ) - 1 ) ;
if ( ! F_20 ( V_2 ) )
V_195 -> V_199 . V_170 = 1 ;
memcpy ( V_195 -> V_418 , V_409 , V_411 ) ;
memcpy ( V_195 -> V_419 , V_412 , V_420 ) ;
F_73 ( V_195 -> V_419 , sizeof( V_195 -> V_419 ) ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_136 ( struct V_1 * V_2 , T_1 V_83 ,
T_1 V_421 , T_1 V_422 , T_1 V_423 )
{
struct V_11 * V_12 ;
struct V_424 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_425 ,
sizeof( * V_195 ) , V_12 , NULL ) ;
V_195 -> V_83 = V_83 ;
V_195 -> V_426 = V_423 ;
V_195 -> V_427 = V_421 ;
V_195 -> V_428 = V_422 ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_137 ( struct V_1 * V_2 , T_1 V_83 , T_2 * V_423 )
{
struct V_11 * V_12 ;
struct V_429 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_430 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_83 = V_83 ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_431 * V_56 =
F_2 ( V_12 ) ;
* V_423 = V_56 -> V_426 ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_138 ( struct V_1 * V_2 , struct V_128 * V_432 ,
T_2 V_433 , T_2 V_434 ,
const char * V_435 , T_2 * V_436 ,
T_1 * V_437 , T_1 * V_438 )
{
struct V_11 * V_12 ;
struct V_439 * V_195 ;
struct V_440 * V_56 ;
void * V_233 = NULL ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_2 -> V_48 = 0 ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_441;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_46 ,
sizeof( struct V_439 ) , V_12 ,
NULL ) ;
V_233 = & V_195 -> V_203 ;
F_93 ( struct V_442 ,
V_443 , V_233 , V_433 ) ;
if ( V_433 == 0 )
F_93 ( struct V_442 ,
V_444 , V_233 , 1 ) ;
else
F_93 ( struct V_442 ,
V_444 , V_233 , 0 ) ;
F_73 ( V_233 , sizeof( V_195 -> V_203 ) ) ;
V_195 -> V_445 = F_72 ( V_434 ) ;
strcpy ( V_195 -> V_446 , V_435 ) ;
V_195 -> V_447 = F_72 ( 1 ) ;
V_195 -> V_335 = F_72 ( V_433 ) ;
V_195 -> V_448 = F_72 ( ( V_432 -> V_134 +
sizeof( struct V_439 ) )
& 0xFFFFFFFF ) ;
V_195 -> V_449 = F_72 ( F_59 ( V_432 -> V_134 +
sizeof( struct V_439 ) ) ) ;
F_3 ( V_2 ) ;
F_39 ( & V_2 -> V_188 ) ;
if ( ! F_139 ( & V_2 -> V_45 ,
F_140 ( 60000 ) ) )
V_42 = - 1 ;
else
V_42 = V_2 -> V_48 ;
V_56 = F_2 ( V_12 ) ;
if ( ! V_42 ) {
* V_436 = F_8 ( V_56 -> V_450 ) ;
* V_437 = V_56 -> V_437 ;
} else {
* V_438 = V_56 -> V_451 ;
}
return V_42 ;
V_441:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_141 ( struct V_1 * V_2 , struct V_128 * V_432 ,
T_2 V_433 , T_2 V_434 , const char * V_435 ,
T_2 * V_452 , T_2 * V_444 , T_1 * V_438 )
{
struct V_11 * V_12 ;
struct V_453 * V_195 ;
struct V_454 * V_56 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_441;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_455 ,
sizeof( struct V_453 ) , V_12 ,
NULL ) ;
V_195 -> V_456 = F_72 ( V_433 ) ;
V_195 -> V_457 = F_72 ( V_434 ) ;
strcpy ( V_195 -> V_446 , V_435 ) ;
V_195 -> V_447 = F_72 ( 1 ) ;
V_195 -> V_335 = F_72 ( V_433 ) ;
V_195 -> V_448 = F_72 ( ( V_432 -> V_134 & 0xFFFFFFFF ) ) ;
V_195 -> V_449 = F_72 ( F_59 ( V_432 -> V_134 ) ) ;
V_42 = F_51 ( V_2 ) ;
V_56 = F_2 ( V_12 ) ;
if ( ! V_42 ) {
* V_452 = F_8 ( V_56 -> V_458 ) ;
* V_444 = F_8 ( V_56 -> V_444 ) ;
} else {
* V_438 = V_56 -> V_451 ;
}
V_441:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_142 ( struct V_1 * V_2 , struct V_128 * V_432 ,
T_2 V_459 , T_2 V_460 , T_2 V_340 )
{
struct V_11 * V_12 ;
struct F_142 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_2 -> V_48 = 0 ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_441;
}
V_195 = V_432 -> V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_37 , V_432 -> V_178 , V_12 ,
V_432 ) ;
V_195 -> V_309 . V_461 = F_72 ( V_459 ) ;
V_195 -> V_309 . V_462 = F_72 ( V_460 ) ;
V_195 -> V_309 . V_463 = F_72 ( V_340 ) ;
F_3 ( V_2 ) ;
F_39 ( & V_2 -> V_188 ) ;
if ( ! F_139 ( & V_2 -> V_45 ,
F_140 ( 40000 ) ) )
V_42 = - 1 ;
else
V_42 = V_2 -> V_48 ;
return V_42 ;
V_441:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_143 ( struct V_1 * V_2 , T_1 * V_464 ,
T_3 V_465 , int V_338 )
{
struct V_11 * V_12 ;
struct V_466 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_467 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_309 . V_461 = F_72 ( V_465 ) ;
V_195 -> V_309 . V_462 = F_72 ( V_468 ) ;
V_195 -> V_309 . V_338 = F_72 ( V_338 ) ;
V_195 -> V_309 . V_463 = F_72 ( 0x4 ) ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 )
memcpy ( V_464 , V_195 -> V_469 , 4 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_144 ( struct V_1 * V_2 , T_1 * V_218 ,
struct V_128 * V_306 )
{
struct V_11 * V_12 ;
struct V_470 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_306 -> V_132 ;
F_71 ( & V_195 -> V_199 , V_51 ,
V_471 , sizeof( * V_195 ) ,
V_12 , V_306 ) ;
memcpy ( V_195 -> V_472 , V_218 , V_219 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_145 ( struct V_1 * V_2 , T_1 V_83 ,
T_1 V_473 , T_1 V_474 )
{
struct V_11 * V_12 ;
struct V_475 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_44 ,
V_476 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_477 = V_83 ;
V_195 -> V_478 = V_83 ;
V_195 -> V_473 = V_473 ;
V_195 -> V_479 = V_474 ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_146 ( struct V_1 * V_2 , T_2 V_83 ,
T_2 V_473 , T_2 V_480 , T_2 V_481 ,
T_5 V_482 )
{
struct V_11 * V_12 ;
struct V_483 * V_195 ;
struct V_484 * V_56 ;
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
V_195 -> V_482 = F_147 ( V_482 ) ;
V_195 -> V_477 = F_72 ( V_83 ) ;
V_195 -> V_478 = F_72 ( V_83 ) ;
V_195 -> V_480 = F_72 ( V_480 ) ;
V_195 -> V_481 = F_72 ( V_481 ) ;
V_195 -> V_473 = F_72 ( V_473 ) ;
F_3 ( V_2 ) ;
F_39 ( & V_2 -> V_188 ) ;
F_148 ( & V_2 -> V_45 ) ;
V_56 = F_2 ( V_12 ) ;
V_42 = F_8 ( V_56 -> V_42 ) ;
return V_42 ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_149 ( struct V_1 * V_2 , T_5 V_482 ,
T_2 V_485 , struct V_128 * V_432 )
{
struct V_11 * V_12 ;
struct V_486 * V_195 ;
int V_42 ;
int V_5 , V_487 = 0 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_432 -> V_132 ;
F_71 ( & V_195 -> V_199 , V_44 ,
V_488 , V_432 -> V_178 , V_12 ,
V_432 ) ;
V_195 -> V_482 = F_147 ( V_482 ) ;
V_195 -> V_489 = F_72 ( V_485 ) ;
for ( V_5 = 0 ; V_5 < V_485 ; V_5 ++ ) {
V_195 -> V_490 [ V_5 ] = ( T_1 ) ( V_482 >> ( V_487 * 8 ) ) ;
V_487 ++ ;
if ( V_487 > 7 )
V_487 = 0 ;
}
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_491 * V_56 ;
V_56 = V_432 -> V_132 ;
if ( ( memcmp ( V_56 -> V_492 , V_195 -> V_490 , V_485 ) != 0 ) ||
V_56 -> V_493 ) {
V_42 = - 1 ;
}
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_150 ( struct V_1 * V_2 ,
struct V_128 * V_306 )
{
struct V_11 * V_12 ;
struct V_494 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_306 -> V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_495 , sizeof( * V_195 ) , V_12 ,
V_306 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_151 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_496 * V_195 ;
struct V_128 V_432 ;
int V_42 ;
if ( ! F_1 ( V_2 , V_497 ,
V_47 ) )
return - V_225 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_432 . V_178 = sizeof( struct V_496 ) ;
V_432 . V_132 = F_122 ( V_2 -> V_63 , V_432 . V_178 , & V_432 . V_134 ) ;
if ( ! V_432 . V_132 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_19 ) ;
V_42 = - V_343 ;
goto V_150;
}
V_195 = V_432 . V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_497 , sizeof( * V_195 ) ,
V_12 , & V_432 ) ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_498 * V_499 =
V_432 . V_132 + sizeof( struct V_164 ) ;
V_2 -> V_67 . V_500 = F_24 ( V_499 -> V_500 ) ;
V_2 -> V_67 . V_501 =
F_24 ( V_499 -> V_501 ) ;
V_2 -> V_67 . V_502 =
F_24 ( V_499 -> V_502 ) ;
V_2 -> V_67 . V_503 =
F_24 ( V_499 -> V_503 ) ;
V_2 -> V_67 . V_504 =
F_8 ( V_499 -> V_504 ) ;
if ( F_115 ( V_2 ) ) {
V_2 -> V_67 . V_503 =
V_505 |
V_506 ;
}
}
F_123 ( V_2 -> V_63 , V_432 . V_178 , V_432 . V_132 , V_432 . V_134 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_152 ( struct V_1 * V_2 , T_2 V_507 , T_2 V_220 )
{
struct V_11 * V_12 ;
struct V_508 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_509 , sizeof( * V_195 ) , V_12 , NULL ) ;
V_195 -> V_199 . V_220 = V_220 ;
V_195 -> V_510 = F_72 ( V_511 ) ;
V_195 -> V_512 = F_72 ( V_507 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_153 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_513 * V_195 ;
struct V_514 * V_56 ;
int V_42 ;
int V_342 = F_154 ( sizeof( * V_195 ) , sizeof( * V_56 ) ) ;
struct V_515 * V_516 ;
struct V_128 V_517 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
memset ( & V_517 , 0 , sizeof( struct V_128 ) ) ;
V_517 . V_178 = sizeof( struct V_514 ) ;
V_517 . V_132 = F_122 ( V_2 -> V_63 , V_517 . V_178 ,
& V_517 . V_134 ) ;
if ( ! V_517 . V_132 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_20 ) ;
V_42 = - V_343 ;
goto V_150;
}
V_12 = F_77 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_517 . V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_518 , V_342 ,
V_12 , & V_517 ) ;
V_42 = F_58 ( V_2 ) ;
if ( ! V_42 ) {
V_516 = V_517 . V_132 + sizeof( struct V_28 ) ;
V_2 -> V_311 = V_516 -> V_519 . V_520 ;
}
V_150:
F_86 ( & V_2 -> V_189 ) ;
if ( V_517 . V_132 )
F_123 ( V_2 -> V_63 , V_517 . V_178 ,
V_517 . V_132 , V_517 . V_134 ) ;
return V_42 ;
}
int F_155 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_521 * V_195 ;
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
V_522 ,
sizeof( * V_195 ) , V_12 , NULL ) ;
V_195 -> V_523 = F_72 ( V_524 |
V_525 ) ;
V_195 -> V_296 = F_72 ( V_525 ) ;
V_42 = F_58 ( V_2 ) ;
if ( ! V_42 ) {
struct V_526 * V_56 = F_2 ( V_12 ) ;
V_2 -> V_527 = F_8 ( V_56 -> V_296 ) &
V_525 ;
if ( ! V_2 -> V_527 )
F_17 ( & V_2 -> V_63 -> V_64 ,
L_21 ) ;
}
V_150:
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
int F_156 ( struct V_1 * V_2 , T_2 * V_528 ,
T_2 V_220 )
{
struct V_11 * V_12 ;
struct V_529 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_530 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_199 . V_220 = V_220 ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_531 * V_56 =
F_2 ( V_12 ) ;
* V_528 = F_8 ( V_56 -> V_532 ) ;
if ( F_20 ( V_2 ) && F_157 ( V_2 ) &&
F_112 ( V_2 ) )
* V_528 = V_533 ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_158 ( struct V_1 * V_2 , T_2 V_534 ,
T_2 V_220 )
{
struct V_11 * V_12 ;
struct V_535 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_536 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_199 . V_220 = V_220 ;
if ( F_67 ( V_2 ) )
V_195 -> V_537 = F_72 ( V_534 ) ;
else
V_195 -> V_534 = F_72 ( V_534 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_159 ( struct V_1 * V_2 , T_1 * V_218 ,
bool * V_538 , T_2 * V_212 , T_2 V_211 ,
T_1 V_220 )
{
struct V_11 * V_12 ;
struct V_539 * V_195 ;
int V_42 ;
int V_540 ;
struct V_128 V_541 ;
int V_5 ;
memset ( & V_541 , 0 , sizeof( struct V_128 ) ) ;
V_541 . V_178 = sizeof( struct V_542 ) ;
V_541 . V_132 = F_122 ( V_2 -> V_63 ,
V_541 . V_178 ,
& V_541 . V_134 ) ;
if ( ! V_541 . V_132 ) {
F_18 ( & V_2 -> V_63 -> V_64 ,
L_22 ) ;
return - V_343 ;
}
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_121;
}
V_195 = V_541 . V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_543 ,
V_541 . V_178 , V_12 , & V_541 ) ;
V_195 -> V_199 . V_220 = V_220 ;
V_195 -> V_544 = V_215 ;
if ( * V_538 ) {
V_195 -> V_545 = F_72 ( * V_212 ) ;
V_195 -> V_546 = F_92 ( V_211 ) ;
V_195 -> V_547 = 0 ;
} else {
V_195 -> V_547 = 1 ;
}
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_542 * V_56 =
V_541 . V_132 ;
if ( * V_538 ) {
memcpy ( V_218 , V_56 -> V_548 . V_549 . V_550 ,
V_219 ) ;
goto V_121;
}
V_540 = V_56 -> V_551 + V_56 -> V_552 ;
for ( V_5 = 0 ; V_5 < V_540 ; V_5 ++ ) {
struct V_553 * V_554 ;
T_3 V_555 ;
T_2 V_545 ;
V_554 = & V_56 -> V_556 [ V_5 ] ;
V_555 = F_24 ( V_554 -> V_555 ) ;
if ( V_555 == sizeof( T_2 ) ) {
* V_538 = true ;
V_545 = V_554 -> V_549 . V_557 . V_545 ;
* V_212 = F_8 ( V_545 ) ;
goto V_121;
}
}
* V_538 = false ;
memcpy ( V_218 , V_56 -> V_556 [ 0 ] . V_549 . V_550 ,
V_219 ) ;
}
V_121:
F_39 ( & V_2 -> V_188 ) ;
F_123 ( V_2 -> V_63 , V_541 . V_178 ,
V_541 . V_132 , V_541 . V_134 ) ;
return V_42 ;
}
int F_160 ( struct V_1 * V_2 , T_2 V_558 ,
T_1 * V_218 , T_2 V_211 , bool V_559 , T_2 V_220 )
{
if ( ! V_559 )
F_159 ( V_2 , V_218 , & V_559 , & V_558 ,
V_211 , V_220 ) ;
if ( F_20 ( V_2 ) )
return F_96 ( V_2 , V_218 , false ,
V_211 , V_558 ) ;
else
return F_159 ( V_2 , V_218 , & V_559 ,
& V_558 ,
V_211 , V_220 ) ;
}
int F_161 ( struct V_1 * V_2 , T_1 * V_218 )
{
int V_42 ;
bool V_560 = false ;
memset ( V_218 , 0 , V_219 ) ;
if ( F_20 ( V_2 ) ) {
if ( F_112 ( V_2 ) )
V_42 = F_96 ( V_2 , V_218 , true , 0 ,
0 ) ;
else
V_42 = F_96 ( V_2 , V_218 , false ,
V_2 -> V_211 , 0 ) ;
} else {
V_42 = F_159 ( V_2 , V_218 , & V_560 ,
NULL , V_2 -> V_211 , 0 ) ;
}
return V_42 ;
}
int F_162 ( struct V_1 * V_2 , T_1 * V_561 ,
T_1 V_540 , T_2 V_220 )
{
struct V_11 * V_12 ;
struct V_562 * V_195 ;
int V_42 ;
struct V_128 V_432 ;
memset ( & V_432 , 0 , sizeof( struct V_128 ) ) ;
V_432 . V_178 = sizeof( struct V_562 ) ;
V_432 . V_132 = F_163 ( & V_2 -> V_63 -> V_64 , V_432 . V_178 ,
& V_432 . V_134 , V_563 ) ;
if ( ! V_432 . V_132 )
return - V_343 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_432 . V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_564 , sizeof( * V_195 ) ,
V_12 , & V_432 ) ;
V_195 -> V_199 . V_220 = V_220 ;
V_195 -> V_540 = V_540 ;
if ( V_540 )
memcpy ( V_195 -> V_218 , V_561 , V_219 * V_540 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_164 ( & V_2 -> V_63 -> V_64 , V_432 . V_178 , V_432 . V_132 , V_432 . V_134 ) ;
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_165 ( struct V_1 * V_2 , T_1 * V_218 , int V_216 , T_2 V_226 )
{
bool V_565 = false ;
T_1 V_566 [ V_219 ] ;
T_2 V_212 ;
int V_42 ;
V_42 = F_159 ( V_2 , V_566 , & V_565 ,
& V_212 , V_216 , V_226 ) ;
if ( ! V_42 && V_565 )
F_98 ( V_2 , V_216 , V_212 , V_226 ) ;
return F_162 ( V_2 , V_218 , V_218 ? 1 : 0 , V_226 ) ;
}
int F_166 ( struct V_1 * V_2 , T_3 V_87 ,
T_2 V_220 , T_3 V_567 , T_3 V_568 )
{
struct V_11 * V_12 ;
struct V_569 * V_195 ;
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
V_570 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_195 -> V_199 . V_220 = V_220 ;
F_93 ( struct V_571 , V_278 , V_233 , V_567 ) ;
if ( V_87 ) {
F_93 ( struct V_571 , V_572 , V_233 , 1 ) ;
F_93 ( struct V_571 , V_87 , V_233 , V_87 ) ;
}
if ( ! F_20 ( V_2 ) && V_568 ) {
F_93 ( struct V_571 , V_278 ,
V_233 , V_2 -> V_311 ) ;
F_93 ( struct V_571 , V_573 , V_233 , 1 ) ;
F_93 ( struct V_571 , V_574 ,
V_233 , V_568 ) ;
}
F_73 ( V_195 -> V_203 , sizeof( V_195 -> V_203 ) ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_167 ( struct V_1 * V_2 , T_3 * V_87 ,
T_2 V_220 , T_3 V_567 , T_1 * V_399 )
{
struct V_11 * V_12 ;
struct V_575 * V_195 ;
void * V_233 ;
int V_42 ;
T_3 V_576 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
V_233 = & V_195 -> V_203 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_577 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_195 -> V_199 . V_220 = V_220 ;
F_93 ( struct V_578 , V_278 ,
V_233 , V_567 ) ;
F_93 ( struct V_578 , V_572 , V_233 , 1 ) ;
if ( ! F_20 ( V_2 ) && V_399 ) {
F_93 ( struct V_578 , V_278 ,
V_233 , V_2 -> V_311 ) ;
F_93 ( struct V_578 , V_573 , V_233 , 1 ) ;
}
F_73 ( V_195 -> V_203 , sizeof( V_195 -> V_203 ) ) ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_579 * V_56 =
F_2 ( V_12 ) ;
F_16 ( & V_56 -> V_203 , sizeof( V_56 -> V_203 ) ) ;
V_576 = F_168 ( struct V_580 ,
V_87 , & V_56 -> V_203 ) ;
if ( V_87 )
* V_87 = F_24 ( V_576 ) ;
if ( V_399 )
* V_399 = F_168 ( struct V_580 ,
V_574 , & V_56 -> V_203 ) ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_169 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_581 * V_195 ;
int V_42 = 0 ;
struct V_128 V_432 ;
if ( ! F_1 ( V_2 , V_471 ,
V_51 ) )
return - V_225 ;
if ( F_170 ( V_2 ) )
return V_42 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
memset ( & V_432 , 0 , sizeof( struct V_128 ) ) ;
V_432 . V_178 = sizeof( struct V_582 ) ;
V_432 . V_132 = F_122 ( V_2 -> V_63 , V_432 . V_178 , & V_432 . V_134 ) ;
if ( ! V_432 . V_132 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_20 ) ;
V_42 = - V_343 ;
goto V_150;
}
V_12 = F_77 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_432 . V_132 ;
F_71 ( & V_195 -> V_199 , V_51 ,
V_471 ,
sizeof( * V_195 ) , V_12 , & V_432 ) ;
V_195 -> V_199 . V_170 = 1 ;
V_195 -> V_583 = V_584 ;
V_42 = F_58 ( V_2 ) ;
if ( ! V_42 ) {
struct V_582 * V_56 ;
V_56 = (struct V_582 * ) V_432 . V_132 ;
V_2 -> V_585 = V_56 -> V_586 ;
if ( V_2 -> V_585 & V_587 )
V_2 -> V_588 = true ;
}
V_150:
F_86 ( & V_2 -> V_189 ) ;
if ( V_432 . V_132 )
F_123 ( V_2 -> V_63 , V_432 . V_178 , V_432 . V_132 , V_432 . V_134 ) ;
return V_42 ;
}
int F_171 ( struct V_1 * V_2 , T_2 V_589 )
{
struct V_128 V_590 ;
struct V_591 * V_592 ;
int V_42 ;
int V_5 , V_487 ;
memset ( & V_590 , 0 , sizeof( struct V_128 ) ) ;
V_590 . V_178 = sizeof( struct V_593 ) ;
V_590 . V_132 = F_122 ( V_2 -> V_63 , V_590 . V_178 ,
& V_590 . V_134 ) ;
if ( ! V_590 . V_132 )
return - V_343 ;
V_42 = F_172 ( V_2 , & V_590 ) ;
if ( V_42 )
goto V_150;
V_592 = (struct V_591 * )
( V_590 . V_132 + sizeof( struct V_28 ) ) ;
for ( V_5 = 0 ; V_5 < F_8 ( V_592 -> V_594 ) ; V_5 ++ ) {
T_2 V_595 = F_8 ( V_592 -> V_596 [ V_5 ] . V_595 ) ;
for ( V_487 = 0 ; V_487 < V_595 ; V_487 ++ ) {
if ( V_592 -> V_596 [ V_5 ] . V_597 [ V_487 ] . V_399 == V_598 )
V_592 -> V_596 [ V_5 ] . V_597 [ V_487 ] . V_599 =
F_72 ( V_589 ) ;
}
}
V_42 = F_173 ( V_2 , & V_590 , V_592 ) ;
V_150:
F_123 ( V_2 -> V_63 , V_590 . V_178 , V_590 . V_132 ,
V_590 . V_134 ) ;
return V_42 ;
}
int F_174 ( struct V_1 * V_2 )
{
struct V_128 V_590 ;
struct V_591 * V_592 ;
int V_42 , V_487 ;
int V_589 = 0 ;
memset ( & V_590 , 0 , sizeof( struct V_128 ) ) ;
V_590 . V_178 = sizeof( struct V_593 ) ;
V_590 . V_132 = F_122 ( V_2 -> V_63 , V_590 . V_178 ,
& V_590 . V_134 ) ;
if ( ! V_590 . V_132 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_23 ,
V_600 ) ;
goto V_150;
}
V_42 = F_172 ( V_2 , & V_590 ) ;
if ( ! V_42 ) {
V_592 = (struct V_591 * ) ( V_590 . V_132 +
sizeof( struct V_28 ) ) ;
for ( V_487 = 0 ; V_487 < F_8 ( V_592 -> V_596 [ 0 ] . V_595 ) ; V_487 ++ ) {
if ( V_592 -> V_596 [ 0 ] . V_597 [ V_487 ] . V_399 == V_598 )
V_589 = V_592 -> V_596 [ 0 ] . V_597 [ V_487 ] . V_599 ;
}
}
F_123 ( V_2 -> V_63 , V_590 . V_178 , V_590 . V_132 ,
V_590 . V_134 ) ;
V_150:
return V_589 ;
}
int F_172 ( struct V_1 * V_2 ,
struct V_128 * V_432 )
{
struct V_11 * V_12 ;
struct V_601 * V_195 ;
int V_42 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
V_12 = F_77 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_432 -> V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_602 ,
V_432 -> V_178 , V_12 , V_432 ) ;
V_195 -> V_603 = F_72 ( 1 ) ;
V_42 = F_58 ( V_2 ) ;
V_150:
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
int F_173 ( struct V_1 * V_2 ,
struct V_128 * V_432 ,
struct V_591 * V_604 )
{
struct V_11 * V_12 ;
struct V_605 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_432 -> V_132 ;
memcpy ( & V_195 -> V_606 , V_604 , sizeof( struct V_591 ) ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_607 ,
V_432 -> V_178 , V_12 , V_432 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_175 ( struct V_1 * V_2 , T_1 * V_608 )
{
struct V_11 * V_12 ;
struct V_609 * V_195 ;
int V_42 ;
if ( ! F_67 ( V_2 ) ) {
* V_608 = V_2 -> V_311 + '0' ;
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
V_610 , sizeof( * V_195 ) , V_12 ,
NULL ) ;
V_195 -> V_199 . V_170 = 1 ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
struct V_611 * V_56 = F_2 ( V_12 ) ;
* V_608 = V_56 -> V_608 [ V_2 -> V_311 ] ;
} else {
* V_608 = V_2 -> V_311 + '0' ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
static struct V_612 * F_176 ( T_1 * V_336 , T_2 V_613 )
{
struct V_614 * V_199 = (struct V_614 * ) V_336 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_613 ; V_5 ++ ) {
if ( V_199 -> V_615 == V_616 ||
V_199 -> V_615 == V_617 )
return (struct V_612 * ) V_199 ;
V_199 -> V_618 = V_199 -> V_618 ? : V_619 ;
V_199 = ( void * ) V_199 + V_199 -> V_618 ;
}
return NULL ;
}
static struct V_620 * F_177 ( T_1 V_621 , T_1 * V_336 ,
T_2 V_613 )
{
struct V_614 * V_199 = (struct V_614 * ) V_336 ;
struct V_620 * V_622 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_613 ; V_5 ++ ) {
if ( ( V_199 -> V_615 == V_623 ||
V_199 -> V_615 == V_624 ) ) {
V_622 = (struct V_620 * ) V_199 ;
if ( V_622 -> V_625 == V_621 )
return V_622 ;
}
V_199 -> V_618 = V_199 -> V_618 ? : V_619 ;
V_199 = ( void * ) V_199 + V_199 -> V_618 ;
}
return NULL ;
}
static struct V_626 * F_178 ( T_1 * V_336 , T_2 V_613 )
{
struct V_614 * V_199 = (struct V_614 * ) V_336 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_613 ; V_5 ++ ) {
if ( V_199 -> V_615 == V_627 )
return (struct V_626 * ) V_199 ;
V_199 -> V_618 = V_199 -> V_618 ? : V_619 ;
V_199 = ( void * ) V_199 + V_199 -> V_618 ;
}
return NULL ;
}
static void F_179 ( struct V_628 * V_629 ,
struct V_612 * V_630 )
{
V_629 -> V_631 = F_24 ( V_630 -> V_632 ) ;
V_629 -> V_633 = F_24 ( V_630 -> V_634 ) ;
V_629 -> V_635 = F_24 ( V_630 -> V_636 ) ;
V_629 -> V_637 = F_24 ( V_630 -> V_638 ) ;
V_629 -> V_639 = F_24 ( V_630 -> V_640 ) ;
V_629 -> V_641 = F_24 ( V_630 -> V_642 ) ;
V_629 -> V_643 = F_24 ( V_630 -> V_644 ) ;
V_629 -> V_645 = F_8 ( V_630 -> V_296 ) &
V_646 ;
if ( V_629 -> V_639 && V_629 -> V_639 == V_629 -> V_641 )
V_629 -> V_639 -= 1 ;
}
int F_180 ( struct V_1 * V_2 , struct V_628 * V_629 )
{
struct V_11 * V_12 ;
struct V_647 * V_195 ;
int V_42 ;
struct V_128 V_432 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
memset ( & V_432 , 0 , sizeof( struct V_128 ) ) ;
V_432 . V_178 = sizeof( struct V_648 ) ;
V_432 . V_132 = F_122 ( V_2 -> V_63 , V_432 . V_178 , & V_432 . V_134 ) ;
if ( ! V_432 . V_132 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_19 ) ;
V_42 = - V_343 ;
goto V_150;
}
V_12 = F_77 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_432 . V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_649 ,
V_432 . V_178 , V_12 , & V_432 ) ;
if ( F_181 ( V_2 ) )
V_195 -> V_199 . V_170 = 1 ;
V_42 = F_58 ( V_2 ) ;
if ( ! V_42 ) {
struct V_648 * V_56 = V_432 . V_132 ;
T_2 V_613 = F_8 ( V_56 -> V_613 ) ;
struct V_612 * V_630 ;
V_630 = F_176 ( V_56 -> V_650 , V_613 ) ;
if ( ! V_630 ) {
V_42 = - V_651 ;
goto V_150;
}
V_2 -> V_652 = V_630 -> V_625 ;
F_179 ( V_629 , V_630 ) ;
}
V_150:
F_86 ( & V_2 -> V_189 ) ;
if ( V_432 . V_132 )
F_123 ( V_2 -> V_63 , V_432 . V_178 , V_432 . V_132 , V_432 . V_134 ) ;
return V_42 ;
}
static int F_182 ( struct V_1 * V_2 ,
T_1 V_220 , struct V_128 * V_432 )
{
struct V_11 * V_12 ;
struct V_653 * V_195 ;
int V_42 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
V_12 = F_77 ( V_2 ) ;
V_195 = V_432 -> V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_654 ,
V_432 -> V_178 , V_12 , V_432 ) ;
V_195 -> type = V_655 ;
V_195 -> V_199 . V_220 = V_220 ;
if ( ! F_67 ( V_2 ) )
V_195 -> V_199 . V_170 = 1 ;
V_42 = F_58 ( V_2 ) ;
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
static int F_183 ( struct V_1 * V_2 ,
T_1 V_220 , struct V_128 * V_432 )
{
struct V_11 * V_12 ;
struct V_653 * V_195 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = V_432 -> V_132 ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_654 ,
V_432 -> V_178 , V_12 , V_432 ) ;
V_195 -> type = V_655 ;
V_195 -> V_199 . V_220 = V_220 ;
if ( ! F_67 ( V_2 ) )
V_195 -> V_199 . V_170 = 1 ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_184 ( struct V_1 * V_2 ,
struct V_628 * V_629 , T_1 V_220 )
{
struct V_656 * V_56 ;
struct V_620 * V_622 ;
struct V_626 * V_657 ;
struct V_612 * V_658 ;
struct V_14 * V_15 = & V_2 -> V_16 . V_17 ;
struct V_128 V_432 ;
T_2 V_613 ;
int V_42 ;
memset ( & V_432 , 0 , sizeof( struct V_128 ) ) ;
V_432 . V_178 = sizeof( struct V_656 ) ;
V_432 . V_132 = F_122 ( V_2 -> V_63 , V_432 . V_178 , & V_432 . V_134 ) ;
if ( ! V_432 . V_132 )
return - V_343 ;
if ( ! V_15 -> V_187 )
V_42 = F_182 ( V_2 , V_220 , & V_432 ) ;
else
V_42 = F_183 ( V_2 , V_220 , & V_432 ) ;
if ( V_42 )
goto V_150;
V_56 = V_432 . V_132 ;
V_613 = F_8 ( V_56 -> V_613 ) ;
V_622 = F_177 ( V_2 -> V_63 -> V_621 , V_56 -> V_650 ,
V_613 ) ;
if ( V_622 )
V_629 -> V_659 = F_24 ( V_622 -> V_660 ) ;
V_657 = F_178 ( V_56 -> V_650 , V_613 ) ;
if ( V_657 )
V_2 -> V_661 = V_657 -> V_661 ;
V_658 = F_176 ( V_56 -> V_650 , V_613 ) ;
if ( V_658 )
F_179 ( V_629 , V_658 ) ;
V_150:
if ( V_432 . V_132 )
F_123 ( V_2 -> V_63 , V_432 . V_178 , V_432 . V_132 , V_432 . V_134 ) ;
return V_42 ;
}
int F_185 ( struct V_1 * V_2 , void * V_630 ,
int V_178 , T_1 V_170 , T_1 V_220 )
{
struct V_662 * V_195 ;
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
V_663 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_199 . V_170 = V_170 ;
V_195 -> V_199 . V_220 = V_220 ;
V_195 -> V_613 = F_72 ( 1 ) ;
memcpy ( V_195 -> V_630 , V_630 , V_178 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
void F_186 ( struct V_612 * V_658 )
{
memset ( V_658 , 0 , sizeof( * V_658 ) ) ;
V_658 -> V_632 = 0xFFFF ;
V_658 -> V_664 = 0xFFFF ;
V_658 -> V_634 = 0xFFFF ;
V_658 -> V_636 = 0xFFFF ;
V_658 -> V_638 = 0xFFFF ;
V_658 -> V_642 = 0xFFFF ;
V_658 -> V_640 = 0xFFFF ;
V_658 -> V_665 = 0xFFFF ;
V_658 -> V_666 = 0xFFFF ;
V_658 -> V_667 = 0xFFFF ;
V_658 -> V_644 = 0xFFFF ;
V_658 -> V_668 = 0xFFFF ;
V_658 -> V_669 = 0xFF ;
V_658 -> V_670 = F_92 ( 0xF000 ) ;
V_658 -> V_671 = 0xFF ;
V_658 -> V_672 = 0x0F ;
V_658 -> V_673 = 0xFFFF ;
V_658 -> V_674 = 0xFFFF ;
V_658 -> V_675 = 0xFFFFFFFF ;
}
int F_187 ( struct V_1 * V_2 , T_2 V_676 , T_3 V_68 ,
T_1 V_220 )
{
struct V_612 V_677 ;
T_2 V_678 ;
T_3 V_170 = 0 ;
if ( F_111 ( V_2 ) )
return F_152 ( V_2 , V_676 / 10 , V_220 ) ;
F_186 ( & V_677 ) ;
V_677 . V_625 = V_2 -> V_652 ;
V_677 . V_679 = V_220 ;
if ( F_67 ( V_2 ) ) {
V_677 . V_199 . V_615 = V_616 ;
V_677 . V_199 . V_618 = V_619 ;
V_677 . V_26 = ( 1 << V_680 ) | ( 1 << V_681 ) |
( 1 << V_682 ) ;
V_677 . V_675 = F_72 ( V_676 / 10 ) ;
} else {
V_170 = 1 ;
V_677 . V_199 . V_615 = V_617 ;
V_677 . V_199 . V_618 = V_683 ;
V_677 . V_26 = ( 1 << V_681 ) | ( 1 << V_682 ) ;
V_678 = V_676 ? ( V_676 * 100 ) / V_68 : 100 ;
V_677 . V_675 = F_72 ( V_678 ) ;
}
return F_185 ( V_2 , & V_677 ,
V_677 . V_199 . V_618 ,
V_170 , V_220 ) ;
}
int F_188 ( struct V_1 * V_2 , T_2 V_684 , T_1 V_685 )
{
struct V_11 * V_12 ;
struct V_686 * V_195 ;
int V_42 ;
if ( V_684 == 0xFFFFFFFF )
return - 1 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_687 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_685 = V_685 ;
V_195 -> V_688 = F_72 ( V_684 ) ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_189 ( struct V_1 * V_2 , T_6 V_657 )
{
struct V_626 V_689 ;
memset ( & V_689 , 0 , sizeof( V_689 ) ) ;
V_689 . V_199 . V_615 = V_627 ;
V_689 . V_199 . V_618 = V_683 ;
V_689 . V_26 = ( 1 << V_681 ) | ( 1 << V_682 ) ;
V_689 . V_690 = V_2 -> V_311 ;
if ( V_657 ) {
V_689 . V_691 = V_692 | ( 1 << V_693 ) |
( 1 << V_694 ) ;
V_689 . V_695 = F_190 ( V_657 ) ;
} else {
V_689 . V_691 = V_696 ;
V_689 . V_695 = 0 ;
}
return F_185 ( V_2 , & V_689 ,
V_683 , 1 , 0 ) ;
}
int F_191 ( struct V_1 * V_2 , struct V_697 * V_698 ,
int V_679 )
{
struct V_11 * V_12 ;
struct V_699 * V_195 ;
struct V_700 * V_56 ;
int V_42 ;
F_37 ( & V_2 -> V_188 ) ;
V_12 = F_78 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_191 ;
goto V_150;
}
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_701 , sizeof( * V_56 ) ,
V_12 , NULL ) ;
V_195 -> V_199 . V_220 = V_679 + 1 ;
V_42 = F_51 ( V_2 ) ;
if ( ! V_42 ) {
V_56 = (struct V_700 * ) V_195 ;
V_698 -> V_211 = F_8 ( V_56 -> V_702 . V_216 ) ;
}
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
static int F_192 ( struct V_1 * V_2 )
{
#define F_193 30
T_2 V_703 ;
int V_42 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < F_193 ; V_5 ++ ) {
V_703 = F_55 ( V_2 -> V_22 + V_704 ) ;
if ( ( V_703 & V_705 ) == 0 )
break;
F_194 ( 1 ) ;
}
if ( V_5 == F_193 )
V_42 = - 1 ;
return V_42 ;
}
int F_195 ( struct V_1 * V_2 , T_2 V_706 )
{
int V_42 = 0 ;
V_42 = F_192 ( V_2 ) ;
if ( V_42 )
return V_42 ;
F_6 ( V_706 , V_2 -> V_22 + V_704 ) ;
return V_42 ;
}
bool F_196 ( struct V_1 * V_2 )
{
T_2 V_140 = 0 ;
V_140 = F_55 ( V_2 -> V_22 + V_141 ) ;
return ! ! ( V_140 & V_707 ) ;
}
int F_197 ( struct V_1 * V_2 )
{
int V_42 ;
V_42 = F_195 ( V_2 , V_708 |
V_709 ) ;
if ( V_42 < 0 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_24 ) ;
return V_42 ;
}
V_42 = F_192 ( V_2 ) ;
if ( V_42 )
return V_42 ;
if ( ! F_196 ( V_2 ) ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_25 ) ;
return - 1 ;
}
return 0 ;
}
int F_198 ( struct V_1 * V_2 , T_1 V_220 )
{
struct V_11 * V_12 ;
struct V_710 * V_195 ;
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
V_711 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_199 . V_220 = V_220 ;
V_195 -> V_474 = 1 ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_199 ( struct V_1 * V_2 , bool V_712 )
{
struct V_11 * V_12 ;
struct V_713 * V_195 ;
int V_42 ;
if ( F_84 ( & V_2 -> V_189 ) )
return - 1 ;
V_12 = F_77 ( V_2 ) ;
V_195 = F_2 ( V_12 ) ;
F_71 ( & V_195 -> V_199 , V_47 ,
V_714 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_195 -> V_715 = V_712 ;
V_42 = F_58 ( V_2 ) ;
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
int F_200 ( struct V_1 * V_2 , T_3 * V_716 )
{
struct V_717 * V_195 ;
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
V_718 , sizeof( * V_195 ) ,
V_12 , NULL ) ;
V_42 = F_58 ( V_2 ) ;
if ( ! V_42 ) {
struct V_719 * V_56 =
F_2 ( V_12 ) ;
* V_716 = F_24 ( V_56 -> V_720 ) ;
}
V_150:
F_86 ( & V_2 -> V_189 ) ;
return V_42 ;
}
int F_201 ( struct V_1 * V_2 ,
int V_721 , T_1 V_220 )
{
struct V_11 * V_12 ;
struct V_722 * V_195 ;
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
V_723 ,
sizeof( * V_195 ) , V_12 , NULL ) ;
V_195 -> V_199 . V_170 = 1 ;
V_195 -> V_199 . V_220 = V_220 ;
if ( V_721 == V_724 )
V_195 -> V_725 |= 1 ;
if ( V_721 == V_726 )
V_195 -> V_725 |= 1 << V_727 ;
V_42 = F_51 ( V_2 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
int F_202 ( void * V_728 , void * V_729 ,
int V_730 , T_3 * V_731 , T_3 * V_732 )
{
struct V_1 * V_2 = F_203 ( V_728 ) ;
struct V_11 * V_12 ;
struct V_164 * V_199 = (struct V_164 * ) V_729 ;
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
V_199 -> V_3 , V_730 , V_12 , NULL ) ;
memcpy ( V_195 , V_729 , V_730 ) ;
F_73 ( V_195 , V_730 ) ;
V_42 = F_51 ( V_2 ) ;
if ( V_731 )
* V_731 = ( V_42 & 0xffff ) ;
if ( V_732 )
* V_732 = 0 ;
memcpy ( V_729 , V_56 , sizeof( * V_56 ) + V_56 -> V_733 ) ;
F_16 ( V_729 , sizeof( * V_56 ) + V_56 -> V_733 ) ;
V_150:
F_39 ( & V_2 -> V_188 ) ;
return V_42 ;
}
