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
return 0 ;
if ( V_153 & V_156 &&
! ( V_153 & V_157 ) )
return - V_129 ;
F_60 ( 1000 ) ;
}
return V_153 ? : - 1 ;
}
int F_67 ( struct V_1 * V_2 )
{
T_3 V_158 ;
int V_42 , V_159 = 0 ;
struct V_76 * V_64 = & V_2 -> V_63 -> V_64 ;
if ( F_68 ( V_2 ) ) {
V_42 = F_65 ( V_2 ) ;
if ( V_42 ) {
V_158 = V_42 ;
goto V_160;
}
return 0 ;
}
do {
if ( F_20 ( V_2 ) && F_69 ( V_2 ) )
return 0 ;
V_158 = F_63 ( V_2 ) ;
if ( V_158 == V_161 )
return 0 ;
F_23 ( V_64 , L_8 , V_159 ) ;
if ( F_70 ( 2000 ) ) {
F_18 ( V_64 , L_9 ) ;
return - V_162 ;
}
V_159 += 2 ;
} while ( V_159 < 60 );
V_160:
F_18 ( V_64 , L_10 , V_158 ) ;
return - V_163 ;
}
static inline struct V_164 * F_71 ( struct V_11 * V_12 )
{
return & V_12 -> V_13 . V_165 [ 0 ] ;
}
static inline void F_72 ( struct V_11 * V_12 , unsigned long V_31 )
{
V_12 -> V_29 = V_31 & 0xFFFFFFFF ;
V_12 -> V_30 = F_62 ( V_31 ) ;
}
static void F_73 ( struct V_166 * V_167 ,
T_1 V_4 , T_1 V_3 , int V_168 ,
struct V_11 * V_12 ,
struct V_141 * V_169 )
{
struct V_164 * V_170 ;
V_167 -> V_3 = V_3 ;
V_167 -> V_4 = V_4 ;
V_167 -> V_171 = F_74 ( V_168 - sizeof( * V_167 ) ) ;
V_167 -> V_172 = 0 ;
F_72 ( V_12 , ( V_173 ) V_167 ) ;
V_12 -> V_174 = V_168 ;
if ( V_169 ) {
V_12 -> V_175 |= ( 1 & V_176 ) <<
V_177 ;
V_170 = F_71 ( V_12 ) ;
V_170 -> V_178 = F_74 ( F_62 ( V_169 -> V_147 ) ) ;
V_170 -> V_179 = F_74 ( V_169 -> V_147 & 0xFFFFFFFF ) ;
V_170 -> V_133 = F_74 ( V_169 -> V_180 ) ;
} else
V_12 -> V_175 |= V_181 ;
F_75 ( V_12 , 8 ) ;
}
static void F_76 ( struct V_182 * V_183 , T_2 V_184 ,
struct V_141 * V_169 )
{
int V_5 , V_185 = F_77 ( F_78 ( V_169 -> V_145 , V_169 -> V_180 ) , V_184 ) ;
T_5 V_147 = ( T_5 ) V_169 -> V_147 ;
for ( V_5 = 0 ; V_5 < V_185 ; V_5 ++ ) {
V_183 [ V_5 ] . V_186 = F_74 ( V_147 & 0xFFFFFFFF ) ;
V_183 [ V_5 ] . V_187 = F_74 ( F_62 ( V_147 ) ) ;
V_147 += V_188 ;
}
}
static inline struct V_11 * F_79 ( struct V_1 * V_2 )
{
struct V_141 * V_142 = & V_2 -> V_142 ;
struct V_11 * V_12
= & ( (struct V_143 * ) ( V_142 -> V_145 ) ) -> V_12 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
static struct V_11 * F_80 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 . V_17 ;
struct V_11 * V_12 ;
if ( ! V_15 -> V_189 )
return NULL ;
if ( F_52 ( & V_15 -> V_128 ) >= V_15 -> V_133 )
return NULL ;
V_12 = F_81 ( V_15 ) ;
F_82 ( V_15 ) ;
F_83 ( & V_15 -> V_128 ) ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return V_12 ;
}
static bool F_84 ( struct V_1 * V_2 )
{
return V_2 -> V_16 . V_17 . V_189 ;
}
static int F_85 ( struct V_1 * V_2 )
{
if ( F_84 ( V_2 ) ) {
F_40 ( & V_2 -> V_190 ) ;
return 0 ;
} else {
return F_86 ( & V_2 -> V_191 ) ;
}
}
static void F_87 ( struct V_1 * V_2 )
{
if ( F_84 ( V_2 ) )
F_42 ( & V_2 -> V_190 ) ;
else
return F_88 ( & V_2 -> V_191 ) ;
}
static struct V_11 * F_89 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_192 ;
if ( F_84 ( V_2 ) ) {
V_192 = F_80 ( V_2 ) ;
if ( ! V_192 )
return NULL ;
} else {
V_192 = F_79 ( V_2 ) ;
}
memcpy ( V_192 , V_12 , sizeof( * V_12 ) ) ;
if ( V_12 -> V_175 & F_74 ( V_181 ) )
F_72 ( V_192 , ( V_173 ) F_2 ( V_12 ) ) ;
return V_192 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_192 ;
int V_42 ;
V_42 = F_85 ( V_2 ) ;
if ( V_42 )
return V_42 ;
V_192 = F_89 ( V_2 , V_12 ) ;
if ( ! V_192 )
return - V_193 ;
if ( F_84 ( V_2 ) )
V_42 = F_54 ( V_2 ) ;
else
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 )
memcpy ( V_12 , V_192 , sizeof( * V_12 ) ) ;
F_87 ( V_2 ) ;
return V_42 ;
}
int F_91 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_42 ;
if ( F_68 ( V_2 ) )
return 0 ;
if ( F_86 ( & V_2 -> V_191 ) )
return - 1 ;
V_12 = ( T_1 * ) F_79 ( V_2 ) ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0x12 ;
* V_12 ++ = 0x34 ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0x56 ;
* V_12 ++ = 0x78 ;
* V_12 = 0xFF ;
V_42 = F_61 ( V_2 ) ;
F_88 ( & V_2 -> V_191 ) ;
return V_42 ;
}
int F_92 ( struct V_1 * V_2 )
{
T_1 * V_12 ;
int V_42 ;
if ( F_68 ( V_2 ) )
return 0 ;
if ( F_86 ( & V_2 -> V_191 ) )
return - 1 ;
V_12 = ( T_1 * ) F_79 ( V_2 ) ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xAA ;
* V_12 ++ = 0xBB ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xFF ;
* V_12 ++ = 0xCC ;
* V_12 ++ = 0xDD ;
* V_12 = 0xFF ;
V_42 = F_61 ( V_2 ) ;
F_88 ( & V_2 -> V_191 ) ;
return V_42 ;
}
int F_93 ( struct V_1 * V_2 , struct V_194 * V_195 )
{
struct V_11 * V_12 ;
struct V_196 * V_197 ;
struct V_141 * V_198 = & V_195 -> V_17 . V_199 ;
int V_42 , V_200 = 0 ;
if ( F_86 ( & V_2 -> V_191 ) )
return - 1 ;
V_12 = F_79 ( V_2 ) ;
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_202 , sizeof( * V_197 ) , V_12 ,
NULL ) ;
if ( ! ( F_20 ( V_2 ) || F_68 ( V_2 ) ) )
V_200 = 2 ;
V_197 -> V_201 . V_172 = V_200 ;
V_197 -> V_203 = F_94 ( F_78 ( V_198 -> V_145 , V_198 -> V_180 ) ) ;
F_95 ( struct V_204 , V_85 , V_197 -> V_205 , 1 ) ;
F_95 ( struct V_204 , V_180 , V_197 -> V_205 , 0 ) ;
F_95 ( struct V_204 , V_206 , V_197 -> V_205 ,
F_96 ( V_195 -> V_17 . V_133 / 256 ) ) ;
F_75 ( V_197 -> V_205 , sizeof( V_197 -> V_205 ) ) ;
F_76 ( V_197 -> V_183 , F_97 ( V_197 -> V_183 ) , V_198 ) ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_207 * V_56 = F_2 ( V_12 ) ;
V_195 -> V_17 . V_19 = F_26 ( V_56 -> V_208 ) ;
V_195 -> V_209 =
( V_200 == 2 ) ? F_26 ( V_56 -> V_209 ) : V_195 -> V_210 ;
V_195 -> V_17 . V_189 = true ;
}
F_88 ( & V_2 -> V_191 ) ;
return V_42 ;
}
int F_98 ( struct V_1 * V_2 , T_1 * V_211 ,
bool V_212 , T_2 V_213 , T_2 V_214 )
{
struct V_11 * V_12 ;
struct V_215 * V_197 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_216 , sizeof( * V_197 ) , V_12 ,
NULL ) ;
V_197 -> type = V_217 ;
if ( V_212 ) {
V_197 -> V_212 = 1 ;
} else {
V_197 -> V_218 = F_94 ( ( T_3 ) V_213 ) ;
V_197 -> V_214 = F_74 ( V_214 ) ;
V_197 -> V_212 = 0 ;
}
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_219 * V_56 = F_2 ( V_12 ) ;
memcpy ( V_211 , V_56 -> V_220 . V_31 , V_221 ) ;
}
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_99 ( struct V_1 * V_2 , T_1 * V_211 ,
T_2 V_218 , T_2 * V_214 , T_2 V_222 )
{
struct V_11 * V_12 ;
struct V_223 * V_197 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_224 , sizeof( * V_197 ) , V_12 ,
NULL ) ;
V_197 -> V_201 . V_222 = V_222 ;
V_197 -> V_218 = F_74 ( V_218 ) ;
memcpy ( V_197 -> V_225 , V_211 , V_221 ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_226 * V_56 = F_2 ( V_12 ) ;
* V_214 = F_8 ( V_56 -> V_214 ) ;
}
V_160:
F_42 ( & V_2 -> V_190 ) ;
if ( V_42 == V_62 )
V_42 = - V_227 ;
return V_42 ;
}
int F_100 ( struct V_1 * V_2 , T_2 V_218 , int V_214 , T_2 V_228 )
{
struct V_11 * V_12 ;
struct V_229 * V_197 ;
int V_42 ;
if ( V_214 == - 1 )
return 0 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_230 , sizeof( * V_197 ) ,
V_12 , NULL ) ;
V_197 -> V_201 . V_222 = V_228 ;
V_197 -> V_218 = F_74 ( V_218 ) ;
V_197 -> V_214 = F_74 ( V_214 ) ;
V_42 = F_54 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_101 ( struct V_1 * V_2 , struct V_14 * V_121 ,
struct V_14 * V_231 , bool V_232 , int V_233 )
{
struct V_11 * V_12 ;
struct V_234 * V_197 ;
struct V_141 * V_198 = & V_121 -> V_199 ;
void * V_235 ;
int V_42 ;
if ( F_86 ( & V_2 -> V_191 ) )
return - 1 ;
V_12 = F_79 ( V_2 ) ;
V_197 = F_2 ( V_12 ) ;
V_235 = & V_197 -> V_205 ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_236 , sizeof( * V_197 ) , V_12 ,
NULL ) ;
V_197 -> V_203 = F_94 ( F_78 ( V_198 -> V_145 , V_198 -> V_180 ) ) ;
if ( F_20 ( V_2 ) ) {
F_95 ( struct V_237 , V_238 , V_235 ,
V_233 ) ;
F_95 ( struct V_237 , V_239 ,
V_235 , V_232 ) ;
F_95 ( struct V_237 , V_206 , V_235 ,
F_96 ( V_121 -> V_133 / 256 ) ) ;
F_95 ( struct V_237 , V_85 , V_235 , 1 ) ;
F_95 ( struct V_237 , V_240 , V_235 , 1 ) ;
F_95 ( struct V_237 , V_241 , V_235 , V_231 -> V_19 ) ;
} else {
V_197 -> V_201 . V_172 = 2 ;
V_197 -> V_242 = 1 ;
if ( ! F_68 ( V_2 ) )
F_95 ( struct V_243 , V_238 ,
V_235 , V_233 ) ;
F_95 ( struct V_243 , V_239 , V_235 ,
V_232 ) ;
F_95 ( struct V_243 , V_206 , V_235 ,
F_96 ( V_121 -> V_133 / 256 ) ) ;
F_95 ( struct V_243 , V_85 , V_235 , 1 ) ;
F_95 ( struct V_243 , V_240 , V_235 , 1 ) ;
F_95 ( struct V_243 , V_241 , V_235 , V_231 -> V_19 ) ;
}
F_75 ( V_235 , sizeof( V_197 -> V_205 ) ) ;
F_76 ( V_197 -> V_183 , F_97 ( V_197 -> V_183 ) , V_198 ) ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_244 * V_56 = F_2 ( V_12 ) ;
V_121 -> V_19 = F_26 ( V_56 -> V_245 ) ;
V_121 -> V_189 = true ;
}
F_88 ( & V_2 -> V_191 ) ;
return V_42 ;
}
static T_2 F_102 ( int V_246 )
{
T_2 V_247 = F_103 ( V_246 ) ;
if ( V_247 == 16 )
V_247 = 0 ;
return V_247 ;
}
static int F_104 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_121 )
{
struct V_11 * V_12 ;
struct V_248 * V_197 ;
struct V_141 * V_198 = & V_15 -> V_199 ;
void * V_235 ;
int V_42 ;
if ( F_86 ( & V_2 -> V_191 ) )
return - 1 ;
V_12 = F_79 ( V_2 ) ;
V_197 = F_2 ( V_12 ) ;
V_235 = & V_197 -> V_205 ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_249 , sizeof( * V_197 ) , V_12 ,
NULL ) ;
V_197 -> V_203 = F_94 ( F_78 ( V_198 -> V_145 , V_198 -> V_180 ) ) ;
if ( F_20 ( V_2 ) ) {
F_95 ( struct V_250 , V_85 , V_235 , 1 ) ;
F_95 ( struct V_250 , V_251 , V_235 ,
F_102 ( V_15 -> V_133 ) ) ;
F_95 ( struct V_250 , V_245 , V_235 , V_121 -> V_19 ) ;
} else {
V_197 -> V_201 . V_172 = 1 ;
V_197 -> V_245 = F_94 ( V_121 -> V_19 ) ;
F_95 ( struct V_252 , V_251 , V_235 ,
F_102 ( V_15 -> V_133 ) ) ;
F_95 ( struct V_252 , V_85 , V_235 , 1 ) ;
F_95 ( struct V_252 , V_253 ,
V_235 , V_121 -> V_19 ) ;
F_95 ( struct V_252 , V_254 ,
V_235 , 1 ) ;
}
V_197 -> V_255 [ 0 ] =
F_74 ( F_105 ( V_116 ) |
F_105 ( V_117 ) |
F_105 ( V_118 ) |
F_105 ( V_119 ) ) ;
F_75 ( V_235 , sizeof( V_197 -> V_205 ) ) ;
F_76 ( V_197 -> V_183 , F_97 ( V_197 -> V_183 ) , V_198 ) ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_256 * V_56 = F_2 ( V_12 ) ;
V_15 -> V_19 = F_26 ( V_56 -> V_19 ) ;
V_15 -> V_189 = true ;
}
F_88 ( & V_2 -> V_191 ) ;
return V_42 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_14 * V_121 )
{
struct V_11 * V_12 ;
struct V_257 * V_197 ;
struct V_141 * V_198 = & V_15 -> V_199 ;
void * V_235 ;
int V_42 ;
if ( F_86 ( & V_2 -> V_191 ) )
return - 1 ;
V_12 = F_79 ( V_2 ) ;
V_197 = F_2 ( V_12 ) ;
V_235 = & V_197 -> V_205 ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_258 , sizeof( * V_197 ) , V_12 ,
NULL ) ;
V_197 -> V_203 = F_94 ( F_78 ( V_198 -> V_145 , V_198 -> V_180 ) ) ;
F_95 ( struct V_250 , V_85 , V_235 , 1 ) ;
F_95 ( struct V_250 , V_251 , V_235 ,
F_102 ( V_15 -> V_133 ) ) ;
F_95 ( struct V_250 , V_245 , V_235 , V_121 -> V_19 ) ;
F_75 ( V_235 , sizeof( V_197 -> V_205 ) ) ;
F_76 ( V_197 -> V_183 , F_97 ( V_197 -> V_183 ) , V_198 ) ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_256 * V_56 = F_2 ( V_12 ) ;
V_15 -> V_19 = F_26 ( V_56 -> V_19 ) ;
V_15 -> V_189 = true ;
}
F_88 ( & V_2 -> V_191 ) ;
return V_42 ;
}
int F_107 ( struct V_1 * V_2 ,
struct V_14 * V_15 , struct V_14 * V_121 )
{
int V_42 ;
V_42 = F_104 ( V_2 , V_15 , V_121 ) ;
if ( V_42 && F_20 ( V_2 ) ) {
F_17 ( & V_2 -> V_63 -> V_64 , L_11
L_12
L_13 ) ;
V_42 = F_106 ( V_2 , V_15 , V_121 ) ;
}
return V_42 ;
}
int F_108 ( struct V_1 * V_2 , struct V_259 * V_260 )
{
struct V_11 V_12 = { 0 } ;
struct V_261 * V_197 ;
struct V_14 * V_262 = & V_260 -> V_17 ;
struct V_14 * V_121 = & V_260 -> V_121 ;
struct V_141 * V_198 = & V_262 -> V_199 ;
int V_42 , V_200 = 0 ;
V_197 = F_2 ( & V_12 ) ;
F_73 ( & V_197 -> V_201 , V_51 ,
V_263 , sizeof( * V_197 ) , & V_12 , NULL ) ;
if ( F_68 ( V_2 ) ) {
V_197 -> V_201 . V_172 = 1 ;
} else if ( F_20 ( V_2 ) ) {
if ( V_2 -> V_264 & V_265 )
V_197 -> V_201 . V_172 = 2 ;
} else {
V_197 -> V_201 . V_172 = 2 ;
}
if ( V_197 -> V_201 . V_172 > 0 )
V_197 -> V_218 = F_94 ( V_2 -> V_213 ) ;
V_197 -> V_203 = F_78 ( V_198 -> V_145 , V_198 -> V_180 ) ;
V_197 -> V_266 = V_267 ;
V_197 -> type = V_268 ;
V_197 -> V_245 = F_94 ( V_121 -> V_19 ) ;
V_197 -> V_269 = F_102 ( V_262 -> V_133 ) ;
F_76 ( V_197 -> V_183 , F_97 ( V_197 -> V_183 ) , V_198 ) ;
V_200 = V_197 -> V_201 . V_172 ;
V_42 = F_90 ( V_2 , & V_12 ) ;
if ( ! V_42 ) {
struct V_270 * V_56 = F_2 ( & V_12 ) ;
V_262 -> V_19 = F_26 ( V_56 -> V_271 ) ;
if ( V_200 == 2 )
V_260 -> V_272 = F_8 ( V_56 -> V_272 ) ;
else
V_260 -> V_272 = V_273 ;
V_262 -> V_189 = true ;
}
return V_42 ;
}
int F_109 ( struct V_1 * V_2 ,
struct V_14 * V_274 , T_3 V_245 , T_3 V_275 ,
T_2 V_218 , T_2 V_276 , T_1 * V_277 )
{
struct V_11 * V_12 ;
struct V_278 * V_197 ;
struct V_141 * V_198 = & V_274 -> V_199 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_51 ,
V_279 , sizeof( * V_197 ) , V_12 , NULL ) ;
V_197 -> V_245 = F_94 ( V_245 ) ;
V_197 -> V_275 = F_103 ( V_275 ) - 1 ;
V_197 -> V_203 = 2 ;
F_76 ( V_197 -> V_183 , F_97 ( V_197 -> V_183 ) , V_198 ) ;
V_197 -> V_280 = F_74 ( V_218 ) ;
V_197 -> V_281 = F_94 ( V_282 ) ;
V_197 -> V_283 = F_74 ( V_276 ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_284 * V_56 = F_2 ( V_12 ) ;
V_274 -> V_19 = F_26 ( V_56 -> V_19 ) ;
V_274 -> V_189 = true ;
* V_277 = V_56 -> V_277 ;
}
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_110 ( struct V_1 * V_2 , struct V_14 * V_17 ,
int V_285 )
{
struct V_11 * V_12 ;
struct V_286 * V_197 ;
T_1 V_287 = 0 , V_3 = 0 ;
int V_42 ;
if ( F_86 ( & V_2 -> V_191 ) )
return - 1 ;
V_12 = F_79 ( V_2 ) ;
V_197 = F_2 ( V_12 ) ;
switch ( V_285 ) {
case V_288 :
V_287 = V_47 ;
V_3 = V_289 ;
break;
case V_290 :
V_287 = V_47 ;
V_3 = V_291 ;
break;
case V_292 :
V_287 = V_51 ;
V_3 = V_293 ;
break;
case V_294 :
V_287 = V_51 ;
V_3 = V_295 ;
break;
case V_296 :
V_287 = V_47 ;
V_3 = V_297 ;
break;
default:
F_111 () ;
}
F_73 ( & V_197 -> V_201 , V_287 , V_3 , sizeof( * V_197 ) , V_12 ,
NULL ) ;
V_197 -> V_19 = F_94 ( V_17 -> V_19 ) ;
V_42 = F_61 ( V_2 ) ;
V_17 -> V_189 = false ;
F_88 ( & V_2 -> V_191 ) ;
return V_42 ;
}
int F_112 ( struct V_1 * V_2 , struct V_14 * V_17 )
{
struct V_11 * V_12 ;
struct V_286 * V_197 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_51 ,
V_295 , sizeof( * V_197 ) , V_12 , NULL ) ;
V_197 -> V_19 = F_94 ( V_17 -> V_19 ) ;
V_42 = F_54 ( V_2 ) ;
V_17 -> V_189 = false ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_113 ( struct V_1 * V_2 , T_2 V_298 , T_2 V_299 ,
T_2 * V_213 , T_2 V_222 )
{
struct V_11 V_12 = { 0 } ;
struct V_300 * V_197 ;
int V_42 ;
V_197 = F_2 ( & V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_301 ,
sizeof( * V_197 ) , & V_12 , NULL ) ;
V_197 -> V_201 . V_222 = V_222 ;
V_197 -> V_302 = F_74 ( V_298 ) ;
V_197 -> V_303 = F_74 ( V_299 ) ;
V_197 -> V_304 = true ;
V_42 = F_90 ( V_2 , & V_12 ) ;
if ( ! V_42 ) {
struct V_305 * V_56 = F_2 ( & V_12 ) ;
* V_213 = F_8 ( V_56 -> V_280 ) ;
if ( F_114 ( V_2 ) && ! F_115 ( V_2 ) )
V_2 -> V_214 [ 0 ] = F_8 ( V_56 -> V_214 ) ;
}
return V_42 ;
}
int F_116 ( struct V_1 * V_2 , int V_280 , T_2 V_222 )
{
struct V_11 * V_12 ;
struct V_306 * V_197 ;
int V_42 ;
if ( V_280 == - 1 )
return 0 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_307 ,
sizeof( * V_197 ) , V_12 , NULL ) ;
V_197 -> V_201 . V_222 = V_222 ;
V_197 -> V_280 = F_74 ( V_280 ) ;
V_42 = F_54 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_117 ( struct V_1 * V_2 , struct V_141 * V_308 )
{
struct V_11 * V_12 ;
struct V_166 * V_201 ;
int V_42 = 0 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_201 = V_308 -> V_145 ;
F_73 ( V_201 , V_51 ,
V_49 , V_308 -> V_180 , V_12 ,
V_308 ) ;
if ( F_118 ( V_2 ) )
V_201 -> V_172 = 0 ;
if ( F_114 ( V_2 ) || F_68 ( V_2 ) )
V_201 -> V_172 = 1 ;
else
V_201 -> V_172 = 2 ;
F_3 ( V_2 ) ;
V_2 -> V_53 = true ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_119 ( struct V_1 * V_2 ,
struct V_141 * V_308 )
{
struct V_11 * V_12 ;
struct V_309 * V_197 ;
int V_42 = 0 ;
if ( ! F_1 ( V_2 , V_50 ,
V_51 ) )
return - V_227 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = V_308 -> V_145 ;
F_73 ( & V_197 -> V_201 , V_51 ,
V_50 , V_308 -> V_180 ,
V_12 , V_308 ) ;
V_197 -> V_310 . V_311 . V_312 = F_94 ( V_2 -> V_78 ) ;
V_197 -> V_310 . V_311 . V_313 = 0 ;
F_3 ( V_2 ) ;
V_2 -> V_53 = true ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
static int F_120 ( int V_314 )
{
switch ( V_314 ) {
case V_315 :
return 0 ;
case V_316 :
return 10 ;
case V_317 :
return 100 ;
case V_318 :
return 1000 ;
case V_319 :
return 10000 ;
case V_320 :
return 20000 ;
case V_321 :
return 25000 ;
case V_322 :
return 40000 ;
}
return 0 ;
}
int F_121 ( struct V_1 * V_2 , T_3 * V_68 ,
T_1 * V_323 , T_2 V_228 )
{
struct V_11 * V_12 ;
struct V_324 * V_197 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
if ( V_323 )
* V_323 = V_325 ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_326 ,
sizeof( * V_197 ) , V_12 , NULL ) ;
if ( ! F_118 ( V_2 ) )
V_197 -> V_201 . V_172 = 1 ;
V_197 -> V_201 . V_222 = V_228 ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_327 * V_56 = F_2 ( V_12 ) ;
if ( V_68 ) {
* V_68 = V_56 -> V_68 ?
F_26 ( V_56 -> V_68 ) * 10 :
F_120 ( V_56 -> V_314 ) ;
if ( ! V_56 -> V_328 )
* V_68 = 0 ;
}
if ( V_323 )
* V_323 = V_56 -> V_328 ;
}
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_122 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_329 * V_197 ;
int V_42 = 0 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_54 ,
sizeof( * V_197 ) , V_12 , NULL ) ;
F_3 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_123 ( struct V_1 * V_2 , T_2 * V_330 )
{
struct V_11 * V_12 ;
struct V_331 * V_197 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_332 , sizeof( * V_197 ) , V_12 ,
NULL ) ;
V_197 -> V_333 = F_74 ( V_334 ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_335 * V_56 = F_2 ( V_12 ) ;
if ( V_330 && V_56 -> V_330 )
* V_330 = F_8 ( V_56 -> V_330 ) -
sizeof( T_2 ) ;
}
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_124 ( struct V_1 * V_2 , T_2 V_336 , void * V_337 )
{
struct V_141 V_338 ;
struct V_11 * V_12 ;
struct V_331 * V_197 ;
T_2 V_339 = 0 , V_340 , V_341 ,
V_342 = sizeof( T_2 ) , V_343 ;
int V_42 = 0 ;
if ( V_336 == 0 )
return - V_129 ;
V_340 = V_336 ;
V_338 . V_180 = sizeof( struct V_331 ) + 60 * 1024 ;
V_338 . V_145 = F_125 ( & V_2 -> V_63 -> V_64 ,
V_338 . V_180 ,
& V_338 . V_147 , V_344 ) ;
if ( ! V_338 . V_145 ) {
F_18 ( & V_2 -> V_63 -> V_64 ,
L_14 ) ;
return - V_345 ;
}
F_40 ( & V_2 -> V_190 ) ;
while ( V_340 ) {
V_341 = F_77 ( V_340 , ( T_2 ) 60 * 1024 ) ;
V_340 -= V_341 ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = V_338 . V_145 ;
V_343 = sizeof( struct V_331 ) + V_341 ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_332 , V_343 ,
V_12 , & V_338 ) ;
V_197 -> V_333 = F_74 ( V_346 ) ;
V_197 -> V_347 = F_74 ( V_342 ) ;
V_197 -> V_348 = F_74 ( V_341 ) ;
V_197 -> V_349 = F_74 ( V_341 ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_335 * V_56 = V_338 . V_145 ;
memcpy ( V_337 + V_339 ,
V_56 -> V_350 ,
F_8 ( V_56 -> V_348 ) ) ;
} else {
F_18 ( & V_2 -> V_63 -> V_64 , L_15 ) ;
goto V_160;
}
V_339 += V_341 ;
V_342 += V_341 ;
}
V_160:
F_126 ( & V_2 -> V_63 -> V_64 , V_338 . V_180 ,
V_338 . V_145 , V_338 . V_147 ) ;
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_127 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_351 * V_197 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_352 , sizeof( * V_197 ) , V_12 ,
NULL ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_353 * V_56 = F_2 ( V_12 ) ;
F_128 ( V_2 -> V_354 , V_56 -> V_355 ,
sizeof( V_2 -> V_354 ) ) ;
F_128 ( V_2 -> V_356 , V_56 -> V_357 ,
sizeof( V_2 -> V_356 ) ) ;
}
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
static int F_129 ( struct V_1 * V_2 ,
struct V_358 * V_359 , int V_124 )
{
struct V_11 * V_12 ;
struct V_360 * V_197 ;
int V_42 = 0 , V_5 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_361 , sizeof( * V_197 ) , V_12 ,
NULL ) ;
V_197 -> V_362 = F_74 ( V_124 ) ;
for ( V_5 = 0 ; V_5 < V_124 ; V_5 ++ ) {
V_197 -> V_359 [ V_5 ] . V_208 = F_74 ( V_359 [ V_5 ] . V_208 ) ;
V_197 -> V_359 [ V_5 ] . V_363 = 0 ;
V_197 -> V_359 [ V_5 ] . V_364 =
F_74 ( V_359 [ V_5 ] . V_364 ) ;
}
F_3 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_130 ( struct V_1 * V_2 , struct V_358 * V_359 ,
int V_124 )
{
int V_365 , V_5 = 0 ;
while ( V_124 ) {
V_365 = F_77 ( V_124 , 8 ) ;
F_129 ( V_2 , & V_359 [ V_5 ] , V_365 ) ;
V_5 += V_365 ;
V_124 -= V_365 ;
}
return 0 ;
}
int F_131 ( struct V_1 * V_2 , T_2 V_218 , T_3 * V_366 ,
T_2 V_124 , T_2 V_222 )
{
struct V_11 * V_12 ;
struct V_367 * V_197 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_368 , sizeof( * V_197 ) ,
V_12 , NULL ) ;
V_197 -> V_201 . V_222 = V_222 ;
V_197 -> V_280 = V_218 ;
V_197 -> V_369 = V_370 & F_132 ( V_2 ) ? 1 : 0 ;
V_197 -> V_371 = V_124 ;
memcpy ( V_197 -> V_372 , V_366 ,
V_197 -> V_371 * sizeof( V_366 [ 0 ] ) ) ;
V_42 = F_54 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
static int F_133 ( struct V_1 * V_2 , T_2 V_26 , T_2 V_373 )
{
struct V_11 * V_12 ;
struct V_141 * V_169 = & V_2 -> V_374 ;
struct V_375 * V_197 = V_169 -> V_145 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
memset ( V_197 , 0 , sizeof( * V_197 ) ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_376 , sizeof( * V_197 ) ,
V_12 , V_169 ) ;
V_197 -> V_218 = F_74 ( V_2 -> V_213 ) ;
V_197 -> V_377 = F_74 ( V_26 ) ;
V_197 -> V_378 = ( V_373 == V_379 ) ? V_197 -> V_377 : 0 ;
if ( V_26 & V_380 ) {
struct V_381 * V_382 ;
int V_5 = 0 ;
V_197 -> V_377 |=
F_74 ( V_383 &
F_132 ( V_2 ) ) ;
V_197 -> V_384 = F_74 ( F_134 ( V_2 -> V_385 ) ) ;
F_135 (ha, adapter->netdev)
memcpy ( V_197 -> V_386 [ V_5 ++ ] . V_387 , V_382 -> V_31 , V_221 ) ;
}
V_42 = F_54 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_136 ( struct V_1 * V_2 , T_2 V_26 , T_2 V_373 )
{
struct V_76 * V_64 = & V_2 -> V_63 -> V_64 ;
if ( ( V_26 & F_132 ( V_2 ) ) != V_26 ) {
F_17 ( V_64 , L_16 , V_26 ) ;
F_17 ( V_64 , L_17 ,
F_132 ( V_2 ) ) ;
}
V_26 &= F_132 ( V_2 ) ;
return F_133 ( V_2 , V_26 , V_373 ) ;
}
int F_137 ( struct V_1 * V_2 , T_2 V_388 , T_2 V_389 )
{
struct V_11 * V_12 ;
struct V_390 * V_197 ;
int V_42 ;
if ( ! F_1 ( V_2 , V_391 ,
V_47 ) )
return - V_227 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_391 , sizeof( * V_197 ) ,
V_12 , NULL ) ;
V_197 -> V_201 . V_172 = 1 ;
V_197 -> V_392 = F_94 ( ( T_3 ) V_388 ) ;
V_197 -> V_393 = F_94 ( ( T_3 ) V_389 ) ;
V_42 = F_54 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
if ( V_32 ( V_42 ) == V_394 )
return - V_395 ;
return V_42 ;
}
int F_138 ( struct V_1 * V_2 , T_2 * V_388 , T_2 * V_389 )
{
struct V_11 * V_12 ;
struct V_396 * V_197 ;
int V_42 ;
if ( ! F_1 ( V_2 , V_397 ,
V_47 ) )
return - V_227 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_397 , sizeof( * V_197 ) ,
V_12 , NULL ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_398 * V_56 =
F_2 ( V_12 ) ;
* V_388 = F_26 ( V_56 -> V_392 ) ;
* V_389 = F_26 ( V_56 -> V_393 ) ;
}
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_139 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_399 * V_197 ;
int V_42 ;
if ( F_86 ( & V_2 -> V_191 ) )
return - 1 ;
V_12 = F_79 ( V_2 ) ;
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_400 ,
sizeof( * V_197 ) , V_12 , NULL ) ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_401 * V_56 = F_2 ( V_12 ) ;
V_2 -> V_94 = F_8 ( V_56 -> V_402 ) ;
V_2 -> V_403 = F_8 ( V_56 -> V_403 ) ;
V_2 -> V_264 = F_8 ( V_56 -> V_264 ) ;
V_2 -> V_404 = F_8 ( V_56 -> V_405 ) & 0xFF ;
F_23 ( & V_2 -> V_63 -> V_64 ,
L_18 ,
V_2 -> V_403 , V_2 -> V_264 ) ;
}
F_88 ( & V_2 -> V_191 ) ;
return V_42 ;
}
int F_140 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_166 * V_197 ;
int V_42 ;
if ( F_68 ( V_2 ) ) {
F_6 ( V_406 ,
V_2 -> V_22 + V_407 ) ;
V_42 = F_65 ( V_2 ) ;
if ( V_42 )
F_18 ( & V_2 -> V_63 -> V_64 ,
L_19 ) ;
return V_42 ;
}
if ( F_86 ( & V_2 -> V_191 ) )
return - 1 ;
V_12 = F_79 ( V_2 ) ;
V_197 = F_2 ( V_12 ) ;
F_73 ( V_197 , V_47 ,
V_408 , sizeof( * V_197 ) , V_12 ,
NULL ) ;
V_42 = F_61 ( V_2 ) ;
F_88 ( & V_2 -> V_191 ) ;
return V_42 ;
}
int F_141 ( struct V_1 * V_2 , T_1 * V_409 ,
T_2 V_410 , T_3 V_411 , const T_1 * V_412 )
{
struct V_11 * V_12 ;
struct V_413 * V_197 ;
int V_42 ;
if ( ! ( F_132 ( V_2 ) & V_414 ) )
return 0 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_51 ,
V_415 , sizeof( * V_197 ) , V_12 , NULL ) ;
V_197 -> V_218 = F_74 ( V_2 -> V_213 ) ;
V_197 -> V_416 = F_94 ( V_410 ) ;
V_197 -> V_417 = F_94 ( F_103 ( V_411 ) - 1 ) ;
if ( ! F_20 ( V_2 ) )
V_197 -> V_201 . V_172 = 1 ;
memcpy ( V_197 -> V_418 , V_409 , V_411 ) ;
memcpy ( V_197 -> V_419 , V_412 , V_420 ) ;
F_75 ( V_197 -> V_419 , sizeof( V_197 -> V_419 ) ) ;
V_42 = F_54 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_142 ( struct V_1 * V_2 , T_1 V_94 ,
T_1 V_421 , T_1 V_422 , T_1 V_423 )
{
struct V_11 * V_12 ;
struct V_424 * V_197 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_425 ,
sizeof( * V_197 ) , V_12 , NULL ) ;
V_197 -> V_94 = V_94 ;
V_197 -> V_426 = V_423 ;
V_197 -> V_427 = V_421 ;
V_197 -> V_428 = V_422 ;
V_42 = F_54 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_143 ( struct V_1 * V_2 , T_1 V_94 , T_2 * V_423 )
{
struct V_11 * V_12 ;
struct V_429 * V_197 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_430 , sizeof( * V_197 ) ,
V_12 , NULL ) ;
V_197 -> V_94 = V_94 ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_431 * V_56 =
F_2 ( V_12 ) ;
* V_423 = V_56 -> V_426 ;
}
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_144 ( struct V_1 * V_2 ,
T_1 V_432 , T_1 * V_433 )
{
struct V_141 V_434 ;
struct V_11 * V_12 ;
struct V_435 * V_197 ;
int V_42 ;
if ( V_432 > V_436 )
return - V_437 ;
V_434 . V_180 = sizeof( struct V_438 ) ;
V_434 . V_145 = F_125 ( & V_2 -> V_63 -> V_64 , V_434 . V_180 , & V_434 . V_147 ,
V_344 ) ;
if ( ! V_434 . V_145 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_20 ) ;
return - V_345 ;
}
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = V_434 . V_145 ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_439 ,
V_434 . V_180 , V_12 , & V_434 ) ;
V_197 -> V_440 = F_74 ( V_2 -> V_78 ) ;
V_197 -> V_432 = F_74 ( V_432 ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_438 * V_56 = V_434 . V_145 ;
memcpy ( V_433 , V_56 -> V_441 , V_442 ) ;
}
V_160:
F_42 ( & V_2 -> V_190 ) ;
F_126 ( & V_2 -> V_63 -> V_64 , V_434 . V_180 , V_434 . V_145 , V_434 . V_147 ) ;
return V_42 ;
}
int F_145 ( struct V_1 * V_2 , struct V_141 * V_434 ,
T_2 V_443 , T_2 V_444 ,
const char * V_445 , T_2 * V_446 ,
T_1 * V_447 , T_1 * V_448 )
{
struct V_11 * V_12 ;
struct V_449 * V_197 ;
struct V_450 * V_56 ;
void * V_235 = NULL ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_2 -> V_48 = 0 ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_451;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_46 ,
sizeof( struct V_449 ) , V_12 ,
NULL ) ;
V_235 = & V_197 -> V_205 ;
F_95 ( struct V_452 ,
V_453 , V_235 , V_443 ) ;
if ( V_443 == 0 )
F_95 ( struct V_452 ,
V_454 , V_235 , 1 ) ;
else
F_95 ( struct V_452 ,
V_454 , V_235 , 0 ) ;
F_75 ( V_235 , sizeof( V_197 -> V_205 ) ) ;
V_197 -> V_455 = F_74 ( V_444 ) ;
F_128 ( V_197 -> V_456 , V_445 , sizeof( V_197 -> V_456 ) ) ;
V_197 -> V_457 = F_74 ( 1 ) ;
V_197 -> V_336 = F_74 ( V_443 ) ;
V_197 -> V_458 = F_74 ( ( V_434 -> V_147 +
sizeof( struct V_449 ) )
& 0xFFFFFFFF ) ;
V_197 -> V_459 = F_74 ( F_62 ( V_434 -> V_147 +
sizeof( struct V_449 ) ) ) ;
F_3 ( V_2 ) ;
F_42 ( & V_2 -> V_190 ) ;
if ( ! F_146 ( & V_2 -> V_45 ,
F_147 ( 60000 ) ) )
V_42 = - V_163 ;
else
V_42 = V_2 -> V_48 ;
V_56 = F_2 ( V_12 ) ;
if ( ! V_42 ) {
* V_446 = F_8 ( V_56 -> V_460 ) ;
* V_447 = V_56 -> V_447 ;
} else {
* V_448 = V_56 -> V_461 ;
}
return V_42 ;
V_451:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_148 ( struct V_1 * V_2 )
{
T_1 V_441 [ V_442 ] ;
int V_42 ;
V_42 = F_144 ( V_2 , V_462 ,
V_441 ) ;
if ( ! V_42 ) {
switch ( V_2 -> V_67 . V_463 ) {
case V_464 :
V_2 -> V_67 . V_465 =
V_441 [ V_466 ] ;
break;
case V_467 :
V_2 -> V_67 . V_465 =
V_441 [ V_468 ] ;
break;
default:
V_2 -> V_67 . V_465 = 0 ;
break;
}
}
return V_42 ;
}
int F_149 ( struct V_1 * V_2 )
{
T_1 V_441 [ V_442 ] ;
int V_42 ;
V_42 = F_144 ( V_2 , V_462 ,
V_441 ) ;
if ( ! V_42 ) {
F_128 ( V_2 -> V_67 . V_469 , V_441 +
V_470 , V_471 - 1 ) ;
F_128 ( V_2 -> V_67 . V_472 ,
V_441 + V_473 ,
V_471 - 1 ) ;
}
return V_42 ;
}
int F_150 ( struct V_1 * V_2 , const char * V_445 )
{
struct V_474 * V_197 ;
struct V_11 * V_12 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_475 ,
sizeof( * V_197 ) , V_12 , NULL ) ;
F_128 ( V_197 -> V_456 , V_445 , sizeof( V_197 -> V_456 ) ) ;
V_42 = F_54 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_151 ( struct V_1 * V_2 , struct V_141 * V_434 ,
T_2 V_443 , T_2 V_444 , const char * V_445 ,
T_2 * V_476 , T_2 * V_454 , T_1 * V_448 )
{
struct V_11 * V_12 ;
struct V_477 * V_197 ;
struct V_478 * V_56 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_451;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_479 ,
sizeof( struct V_477 ) , V_12 ,
NULL ) ;
V_197 -> V_480 = F_74 ( V_443 ) ;
V_197 -> V_481 = F_74 ( V_444 ) ;
strcpy ( V_197 -> V_456 , V_445 ) ;
V_197 -> V_457 = F_74 ( 1 ) ;
V_197 -> V_336 = F_74 ( V_443 ) ;
V_197 -> V_458 = F_74 ( ( V_434 -> V_147 & 0xFFFFFFFF ) ) ;
V_197 -> V_459 = F_74 ( F_62 ( V_434 -> V_147 ) ) ;
V_42 = F_54 ( V_2 ) ;
V_56 = F_2 ( V_12 ) ;
if ( ! V_42 ) {
* V_476 = F_8 ( V_56 -> V_482 ) ;
* V_454 = F_8 ( V_56 -> V_454 ) ;
} else {
* V_448 = V_56 -> V_461 ;
}
V_451:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_152 ( struct V_1 * V_2 , struct V_141 * V_434 ,
T_2 V_483 , T_2 V_484 , T_2 V_485 ,
T_2 V_341 )
{
struct V_11 * V_12 ;
struct F_152 * V_197 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_2 -> V_48 = 0 ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_451;
}
V_197 = V_434 -> V_145 ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_37 , V_434 -> V_180 , V_12 ,
V_434 ) ;
V_197 -> V_311 . V_486 = F_74 ( V_483 ) ;
if ( V_483 == V_487 )
V_197 -> V_311 . V_339 = F_74 ( V_485 ) ;
V_197 -> V_311 . V_488 = F_74 ( V_484 ) ;
V_197 -> V_311 . V_489 = F_74 ( V_341 ) ;
F_3 ( V_2 ) ;
F_42 ( & V_2 -> V_190 ) ;
if ( ! F_146 ( & V_2 -> V_45 ,
F_147 ( 40000 ) ) )
V_42 = - V_163 ;
else
V_42 = V_2 -> V_48 ;
return V_42 ;
V_451:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_153 ( struct V_1 * V_2 , T_1 * V_490 ,
T_3 V_491 , T_2 V_485 , T_2 V_492 )
{
struct V_493 * V_197 ;
struct V_11 * V_12 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_494 , sizeof( * V_197 ) ,
V_12 , NULL ) ;
V_197 -> V_311 . V_486 = F_74 ( V_491 ) ;
if ( V_491 == V_487 )
V_197 -> V_311 . V_339 = F_74 ( V_485 + V_492 ) ;
else
V_197 -> V_311 . V_339 = F_74 ( V_492 ) ;
V_197 -> V_311 . V_488 = F_74 ( V_495 ) ;
V_197 -> V_311 . V_489 = F_74 ( 0x4 ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 )
memcpy ( V_490 , V_197 -> V_496 , 4 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_154 ( struct V_1 * V_2 , T_1 * V_220 ,
struct V_141 * V_308 )
{
struct V_11 * V_12 ;
struct V_497 * V_197 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = V_308 -> V_145 ;
F_73 ( & V_197 -> V_201 , V_51 ,
V_498 , sizeof( * V_197 ) ,
V_12 , V_308 ) ;
memcpy ( V_197 -> V_499 , V_220 , V_221 ) ;
V_42 = F_54 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_155 ( struct V_1 * V_2 , T_1 V_94 ,
T_1 V_500 , T_1 V_501 )
{
struct V_11 * V_12 ;
struct V_502 * V_197 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_44 ,
V_503 , sizeof( * V_197 ) ,
V_12 , NULL ) ;
V_197 -> V_504 = V_94 ;
V_197 -> V_505 = V_94 ;
V_197 -> V_500 = V_500 ;
V_197 -> V_506 = V_501 ;
V_42 = F_54 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_156 ( struct V_1 * V_2 , T_2 V_94 ,
T_2 V_500 , T_2 V_507 , T_2 V_508 ,
T_5 V_509 )
{
struct V_11 * V_12 ;
struct V_510 * V_197 ;
struct V_511 * V_56 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_44 ,
V_43 , sizeof( * V_197 ) , V_12 ,
NULL ) ;
V_197 -> V_201 . V_159 = F_74 ( 15 ) ;
V_197 -> V_509 = F_157 ( V_509 ) ;
V_197 -> V_504 = F_74 ( V_94 ) ;
V_197 -> V_505 = F_74 ( V_94 ) ;
V_197 -> V_507 = F_74 ( V_507 ) ;
V_197 -> V_508 = F_74 ( V_508 ) ;
V_197 -> V_500 = F_74 ( V_500 ) ;
F_3 ( V_2 ) ;
F_42 ( & V_2 -> V_190 ) ;
F_158 ( & V_2 -> V_45 ) ;
V_56 = F_2 ( V_12 ) ;
V_42 = F_8 ( V_56 -> V_42 ) ;
return V_42 ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_159 ( struct V_1 * V_2 , T_5 V_509 ,
T_2 V_512 , struct V_141 * V_434 )
{
struct V_11 * V_12 ;
struct V_513 * V_197 ;
int V_42 ;
int V_5 , V_514 = 0 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = V_434 -> V_145 ;
F_73 ( & V_197 -> V_201 , V_44 ,
V_515 , V_434 -> V_180 , V_12 ,
V_434 ) ;
V_197 -> V_509 = F_157 ( V_509 ) ;
V_197 -> V_516 = F_74 ( V_512 ) ;
for ( V_5 = 0 ; V_5 < V_512 ; V_5 ++ ) {
V_197 -> V_517 [ V_5 ] = ( T_1 ) ( V_509 >> ( V_514 * 8 ) ) ;
V_514 ++ ;
if ( V_514 > 7 )
V_514 = 0 ;
}
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_518 * V_56 ;
V_56 = V_434 -> V_145 ;
if ( ( memcmp ( V_56 -> V_519 , V_197 -> V_517 , V_512 ) != 0 ) ||
V_56 -> V_520 ) {
V_42 = - 1 ;
}
}
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_160 ( struct V_1 * V_2 ,
struct V_141 * V_308 )
{
struct V_11 * V_12 ;
struct V_521 * V_197 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = V_308 -> V_145 ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_522 , sizeof( * V_197 ) , V_12 ,
V_308 ) ;
V_42 = F_54 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_161 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_523 * V_197 ;
struct V_141 V_434 ;
int V_42 ;
if ( ! F_1 ( V_2 , V_524 ,
V_47 ) )
return - V_227 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_434 . V_180 = sizeof( struct V_523 ) ;
V_434 . V_145 = F_125 ( & V_2 -> V_63 -> V_64 , V_434 . V_180 , & V_434 . V_147 ,
V_344 ) ;
if ( ! V_434 . V_145 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_21 ) ;
V_42 = - V_345 ;
goto V_160;
}
V_197 = V_434 . V_145 ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_524 , sizeof( * V_197 ) ,
V_12 , & V_434 ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_525 * V_526 =
V_434 . V_145 + sizeof( struct V_166 ) ;
V_2 -> V_67 . V_527 = F_26 ( V_526 -> V_527 ) ;
V_2 -> V_67 . V_463 =
F_26 ( V_526 -> V_463 ) ;
V_2 -> V_67 . V_528 =
F_26 ( V_526 -> V_528 ) ;
V_2 -> V_67 . V_529 =
F_26 ( V_526 -> V_529 ) ;
V_2 -> V_67 . V_530 =
F_8 ( V_526 -> V_530 ) ;
if ( F_118 ( V_2 ) ) {
V_2 -> V_67 . V_529 =
V_531 |
V_532 ;
}
}
F_126 ( & V_2 -> V_63 -> V_64 , V_434 . V_180 , V_434 . V_145 , V_434 . V_147 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
static int F_162 ( struct V_1 * V_2 , T_2 V_533 , T_2 V_222 )
{
struct V_11 * V_12 ;
struct V_534 * V_197 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_535 , sizeof( * V_197 ) , V_12 , NULL ) ;
V_197 -> V_201 . V_222 = V_222 ;
V_197 -> V_536 = F_74 ( V_537 ) ;
V_197 -> V_538 = F_74 ( V_533 ) ;
V_42 = F_54 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_163 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_539 * V_197 ;
struct V_540 * V_56 ;
int V_42 ;
int V_343 = F_164 ( sizeof( * V_197 ) , sizeof( * V_56 ) ) ;
struct V_541 * V_542 ;
struct V_141 V_543 ;
if ( F_86 ( & V_2 -> V_191 ) )
return - 1 ;
memset ( & V_543 , 0 , sizeof( struct V_141 ) ) ;
V_543 . V_180 = sizeof( struct V_540 ) ;
V_543 . V_145 = F_125 ( & V_2 -> V_63 -> V_64 ,
V_543 . V_180 ,
& V_543 . V_147 , V_344 ) ;
if ( ! V_543 . V_145 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_22 ) ;
V_42 = - V_345 ;
goto V_160;
}
V_12 = F_79 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = V_543 . V_145 ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_544 , V_343 ,
V_12 , & V_543 ) ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
V_542 = V_543 . V_145 + sizeof( struct V_28 ) ;
V_2 -> V_78 = V_542 -> V_545 . V_546 ;
}
V_160:
F_88 ( & V_2 -> V_191 ) ;
if ( V_543 . V_145 )
F_126 ( & V_2 -> V_63 -> V_64 , V_543 . V_180 ,
V_543 . V_145 , V_543 . V_147 ) ;
return V_42 ;
}
int F_165 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_547 * V_197 ;
int V_42 ;
if ( F_86 ( & V_2 -> V_191 ) )
return - 1 ;
V_12 = F_79 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_548 ,
sizeof( * V_197 ) , V_12 , NULL ) ;
V_197 -> V_549 = F_74 ( V_550 |
V_551 ) ;
V_197 -> V_298 = F_74 ( V_551 ) ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_552 * V_56 = F_2 ( V_12 ) ;
V_2 -> V_553 = F_8 ( V_56 -> V_298 ) &
V_551 ;
if ( ! V_2 -> V_553 )
F_17 ( & V_2 -> V_63 -> V_64 ,
L_23 ) ;
}
V_160:
F_88 ( & V_2 -> V_191 ) ;
return V_42 ;
}
int F_166 ( struct V_1 * V_2 , T_2 * V_554 ,
T_2 V_222 )
{
struct V_11 * V_12 ;
struct V_555 * V_197 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_556 , sizeof( * V_197 ) ,
V_12 , NULL ) ;
V_197 -> V_201 . V_222 = V_222 ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_557 * V_56 =
F_2 ( V_12 ) ;
* V_554 = F_8 ( V_56 -> V_558 ) ;
if ( F_20 ( V_2 ) && F_167 ( V_2 ) &&
F_115 ( V_2 ) )
* V_554 = V_559 ;
}
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_168 ( struct V_1 * V_2 , T_2 V_560 ,
T_2 V_222 )
{
struct V_11 * V_12 ;
struct V_561 * V_197 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_562 , sizeof( * V_197 ) ,
V_12 , NULL ) ;
V_197 -> V_201 . V_222 = V_222 ;
if ( F_68 ( V_2 ) )
V_197 -> V_563 = F_74 ( V_560 ) ;
else
V_197 -> V_560 = F_74 ( V_560 ) ;
V_42 = F_54 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_169 ( struct V_1 * V_2 , T_1 * V_220 ,
bool * V_564 , T_2 * V_214 , T_2 V_213 ,
T_1 V_222 )
{
struct V_11 * V_12 ;
struct V_565 * V_197 ;
int V_42 ;
int V_566 ;
struct V_141 V_567 ;
int V_5 ;
memset ( & V_567 , 0 , sizeof( struct V_141 ) ) ;
V_567 . V_180 = sizeof( struct V_568 ) ;
V_567 . V_145 = F_125 ( & V_2 -> V_63 -> V_64 ,
V_567 . V_180 ,
& V_567 . V_147 ,
V_344 ) ;
if ( ! V_567 . V_145 ) {
F_18 ( & V_2 -> V_63 -> V_64 ,
L_24 ) ;
return - V_345 ;
}
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_134;
}
V_197 = V_567 . V_145 ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_569 ,
V_567 . V_180 , V_12 , & V_567 ) ;
V_197 -> V_201 . V_222 = V_222 ;
V_197 -> V_570 = V_217 ;
if ( * V_564 ) {
V_197 -> V_571 = F_74 ( * V_214 ) ;
V_197 -> V_572 = F_94 ( V_213 ) ;
V_197 -> V_573 = 0 ;
} else {
V_197 -> V_573 = 1 ;
}
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_568 * V_56 =
V_567 . V_145 ;
if ( * V_564 ) {
memcpy ( V_220 , V_56 -> V_574 . V_575 . V_576 ,
V_221 ) ;
goto V_134;
}
V_566 = V_56 -> V_577 + V_56 -> V_578 ;
for ( V_5 = 0 ; V_5 < V_566 ; V_5 ++ ) {
struct V_579 * V_580 ;
T_3 V_581 ;
T_2 V_571 ;
V_580 = & V_56 -> V_582 [ V_5 ] ;
V_581 = F_26 ( V_580 -> V_581 ) ;
if ( V_581 == sizeof( T_2 ) ) {
* V_564 = true ;
V_571 = V_580 -> V_575 . V_583 . V_571 ;
* V_214 = F_8 ( V_571 ) ;
goto V_134;
}
}
* V_564 = false ;
memcpy ( V_220 , V_56 -> V_582 [ 0 ] . V_575 . V_576 ,
V_221 ) ;
}
V_134:
F_42 ( & V_2 -> V_190 ) ;
F_126 ( & V_2 -> V_63 -> V_64 , V_567 . V_180 ,
V_567 . V_145 , V_567 . V_147 ) ;
return V_42 ;
}
int F_170 ( struct V_1 * V_2 , T_2 V_584 ,
T_1 * V_220 , T_2 V_213 , bool V_585 , T_2 V_222 )
{
if ( ! V_585 )
F_169 ( V_2 , V_220 , & V_585 , & V_584 ,
V_213 , V_222 ) ;
if ( F_20 ( V_2 ) )
return F_98 ( V_2 , V_220 , false ,
V_213 , V_584 ) ;
else
return F_169 ( V_2 , V_220 , & V_585 ,
& V_584 ,
V_213 , V_222 ) ;
}
int F_171 ( struct V_1 * V_2 , T_1 * V_220 )
{
int V_42 ;
bool V_586 = false ;
F_172 ( V_220 ) ;
if ( F_20 ( V_2 ) ) {
if ( F_115 ( V_2 ) )
V_42 = F_98 ( V_2 , V_220 , true , 0 ,
0 ) ;
else
V_42 = F_98 ( V_2 , V_220 , false ,
V_2 -> V_213 , 0 ) ;
} else {
V_42 = F_169 ( V_2 , V_220 , & V_586 ,
NULL , V_2 -> V_213 , 0 ) ;
}
return V_42 ;
}
int F_173 ( struct V_1 * V_2 , T_1 * V_587 ,
T_1 V_566 , T_2 V_222 )
{
struct V_11 * V_12 ;
struct V_588 * V_197 ;
int V_42 ;
struct V_141 V_434 ;
memset ( & V_434 , 0 , sizeof( struct V_141 ) ) ;
V_434 . V_180 = sizeof( struct V_588 ) ;
V_434 . V_145 = F_125 ( & V_2 -> V_63 -> V_64 , V_434 . V_180 , & V_434 . V_147 ,
V_589 ) ;
if ( ! V_434 . V_145 )
return - V_345 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = V_434 . V_145 ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_590 , sizeof( * V_197 ) ,
V_12 , & V_434 ) ;
V_197 -> V_201 . V_222 = V_222 ;
V_197 -> V_566 = V_566 ;
if ( V_566 )
memcpy ( V_197 -> V_220 , V_587 , V_221 * V_566 ) ;
V_42 = F_54 ( V_2 ) ;
V_160:
F_126 ( & V_2 -> V_63 -> V_64 , V_434 . V_180 , V_434 . V_145 , V_434 . V_147 ) ;
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_174 ( struct V_1 * V_2 , T_1 * V_220 , int V_218 , T_2 V_228 )
{
bool V_591 = false ;
T_1 V_592 [ V_221 ] ;
T_2 V_214 ;
int V_42 ;
V_42 = F_169 ( V_2 , V_592 , & V_591 ,
& V_214 , V_218 , V_228 ) ;
if ( ! V_42 && V_591 )
F_100 ( V_2 , V_218 , V_214 , V_228 ) ;
return F_173 ( V_2 , V_220 , V_220 ? 1 : 0 , V_228 ) ;
}
int F_175 ( struct V_1 * V_2 , T_3 V_98 ,
T_2 V_222 , T_3 V_593 , T_3 V_594 )
{
struct V_11 * V_12 ;
struct V_595 * V_197 ;
void * V_235 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
V_235 = & V_197 -> V_205 ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_596 , sizeof( * V_197 ) , V_12 ,
NULL ) ;
V_197 -> V_201 . V_222 = V_222 ;
F_95 ( struct V_597 , V_280 , V_235 , V_593 ) ;
if ( V_98 ) {
F_95 ( struct V_597 , V_598 , V_235 , 1 ) ;
F_95 ( struct V_597 , V_98 , V_235 , V_98 ) ;
}
if ( ! F_20 ( V_2 ) && V_594 ) {
F_95 ( struct V_597 , V_280 ,
V_235 , V_2 -> V_78 ) ;
F_95 ( struct V_597 , V_599 , V_235 , 1 ) ;
F_95 ( struct V_597 , V_600 ,
V_235 , V_594 ) ;
}
F_75 ( V_197 -> V_205 , sizeof( V_197 -> V_205 ) ) ;
V_42 = F_54 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_176 ( struct V_1 * V_2 , T_3 * V_98 ,
T_2 V_222 , T_3 V_593 , T_1 * V_601 )
{
struct V_11 * V_12 ;
struct V_602 * V_197 ;
void * V_235 ;
int V_42 ;
T_3 V_603 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
V_235 = & V_197 -> V_205 ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_604 , sizeof( * V_197 ) , V_12 ,
NULL ) ;
V_197 -> V_201 . V_222 = V_222 ;
F_95 ( struct V_605 , V_280 ,
V_235 , V_593 ) ;
F_95 ( struct V_605 , V_598 , V_235 , 1 ) ;
if ( ! F_20 ( V_2 ) && V_601 ) {
F_95 ( struct V_605 , V_280 ,
V_235 , V_2 -> V_78 ) ;
F_95 ( struct V_605 , V_599 , V_235 , 1 ) ;
}
F_75 ( V_197 -> V_205 , sizeof( V_197 -> V_205 ) ) ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
struct V_606 * V_56 =
F_2 ( V_12 ) ;
F_16 ( & V_56 -> V_205 , sizeof( V_56 -> V_205 ) ) ;
V_603 = F_177 ( struct V_607 ,
V_98 , & V_56 -> V_205 ) ;
if ( V_98 )
* V_98 = F_26 ( V_603 ) ;
if ( V_601 )
* V_601 = F_177 ( struct V_607 ,
V_600 , & V_56 -> V_205 ) ;
}
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
static bool F_178 ( struct V_1 * V_2 )
{
struct V_608 * V_63 = V_2 -> V_63 ;
if ( ! F_115 ( V_2 ) )
return true ;
switch ( V_63 -> V_609 ) {
case V_610 :
case V_611 :
case V_612 :
case V_613 :
return true ;
default:
return false ;
}
}
int F_179 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_614 * V_197 ;
int V_42 = 0 ;
struct V_141 V_434 ;
if ( ! F_1 ( V_2 , V_498 ,
V_51 ) )
return - V_227 ;
if ( F_178 ( V_2 ) )
return V_42 ;
if ( F_86 ( & V_2 -> V_191 ) )
return - 1 ;
memset ( & V_434 , 0 , sizeof( struct V_141 ) ) ;
V_434 . V_180 = sizeof( struct V_615 ) ;
V_434 . V_145 = F_125 ( & V_2 -> V_63 -> V_64 , V_434 . V_180 , & V_434 . V_147 ,
V_344 ) ;
if ( ! V_434 . V_145 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_22 ) ;
V_42 = - V_345 ;
goto V_160;
}
V_12 = F_79 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = V_434 . V_145 ;
F_73 ( & V_197 -> V_201 , V_51 ,
V_498 ,
sizeof( * V_197 ) , V_12 , & V_434 ) ;
V_197 -> V_201 . V_172 = 1 ;
V_197 -> V_616 = V_617 ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_615 * V_56 ;
V_56 = (struct V_615 * ) V_434 . V_145 ;
V_2 -> V_618 = V_56 -> V_619 ;
if ( V_2 -> V_618 & V_620 )
V_2 -> V_621 = true ;
}
V_160:
F_88 ( & V_2 -> V_191 ) ;
if ( V_434 . V_145 )
F_126 ( & V_2 -> V_63 -> V_64 , V_434 . V_180 , V_434 . V_145 ,
V_434 . V_147 ) ;
return V_42 ;
}
int F_180 ( struct V_1 * V_2 , T_2 V_622 )
{
struct V_141 V_623 ;
struct V_624 * V_625 ;
int V_42 ;
int V_5 , V_514 ;
memset ( & V_623 , 0 , sizeof( struct V_141 ) ) ;
V_623 . V_180 = sizeof( struct V_626 ) ;
V_623 . V_145 = F_125 ( & V_2 -> V_63 -> V_64 ,
V_623 . V_180 , & V_623 . V_147 ,
V_344 ) ;
if ( ! V_623 . V_145 )
return - V_345 ;
V_42 = F_181 ( V_2 , & V_623 ) ;
if ( V_42 )
goto V_160;
V_625 = (struct V_624 * )
( V_623 . V_145 + sizeof( struct V_28 ) ) ;
for ( V_5 = 0 ; V_5 < F_8 ( V_625 -> V_627 ) ; V_5 ++ ) {
T_2 V_628 = F_8 ( V_625 -> V_629 [ V_5 ] . V_628 ) ;
for ( V_514 = 0 ; V_514 < V_628 ; V_514 ++ ) {
if ( V_625 -> V_629 [ V_5 ] . V_630 [ V_514 ] . V_601 == V_631 )
V_625 -> V_629 [ V_5 ] . V_630 [ V_514 ] . V_632 =
F_74 ( V_622 ) ;
}
}
V_42 = F_182 ( V_2 , & V_623 , V_625 ) ;
V_160:
F_126 ( & V_2 -> V_63 -> V_64 , V_623 . V_180 , V_623 . V_145 ,
V_623 . V_147 ) ;
return V_42 ;
}
int F_183 ( struct V_1 * V_2 )
{
struct V_141 V_623 ;
struct V_624 * V_625 ;
int V_42 , V_514 ;
int V_622 = 0 ;
memset ( & V_623 , 0 , sizeof( struct V_141 ) ) ;
V_623 . V_180 = sizeof( struct V_626 ) ;
V_623 . V_145 = F_125 ( & V_2 -> V_63 -> V_64 ,
V_623 . V_180 , & V_623 . V_147 ,
V_344 ) ;
if ( ! V_623 . V_145 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_25 ,
V_633 ) ;
goto V_160;
}
V_42 = F_181 ( V_2 , & V_623 ) ;
if ( ! V_42 ) {
V_625 = (struct V_624 * ) ( V_623 . V_145 +
sizeof( struct V_28 ) ) ;
for ( V_514 = 0 ; V_514 < F_8 ( V_625 -> V_629 [ 0 ] . V_628 ) ; V_514 ++ ) {
if ( V_625 -> V_629 [ 0 ] . V_630 [ V_514 ] . V_601 == V_631 )
V_622 = V_625 -> V_629 [ 0 ] . V_630 [ V_514 ] . V_632 ;
}
}
F_126 ( & V_2 -> V_63 -> V_64 , V_623 . V_180 , V_623 . V_145 ,
V_623 . V_147 ) ;
V_160:
return V_622 ;
}
int F_181 ( struct V_1 * V_2 ,
struct V_141 * V_434 )
{
struct V_11 * V_12 ;
struct V_634 * V_197 ;
int V_42 ;
if ( F_86 ( & V_2 -> V_191 ) )
return - 1 ;
V_12 = F_79 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = V_434 -> V_145 ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_635 ,
V_434 -> V_180 , V_12 , V_434 ) ;
V_197 -> V_636 = F_74 ( 1 ) ;
V_42 = F_61 ( V_2 ) ;
V_160:
F_88 ( & V_2 -> V_191 ) ;
return V_42 ;
}
int F_182 ( struct V_1 * V_2 ,
struct V_141 * V_434 ,
struct V_624 * V_637 )
{
struct V_11 * V_12 ;
struct V_638 * V_197 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = V_434 -> V_145 ;
memcpy ( & V_197 -> V_639 , V_637 , sizeof( struct V_624 ) ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_640 ,
V_434 -> V_180 , V_12 , V_434 ) ;
V_42 = F_54 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_184 ( struct V_1 * V_2 )
{
struct V_641 * V_197 ;
struct V_11 * V_12 ;
int V_42 ;
if ( F_86 ( & V_2 -> V_191 ) )
return - 1 ;
V_12 = F_79 ( V_2 ) ;
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_642 , sizeof( * V_197 ) , V_12 ,
NULL ) ;
if ( ! F_20 ( V_2 ) )
V_197 -> V_201 . V_172 = 1 ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_643 * V_56 = F_2 ( V_12 ) ;
V_2 -> V_79 = V_56 -> V_79 [ V_2 -> V_78 ] ;
} else {
V_2 -> V_79 = V_2 -> V_78 + '0' ;
}
F_88 ( & V_2 -> V_191 ) ;
return V_42 ;
}
static struct V_644 * F_185 ( T_1 * V_337 , T_2 V_645 ,
int V_646 )
{
struct V_647 * V_201 = (struct V_647 * ) V_337 ;
struct V_644 * V_648 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_645 ; V_5 ++ ) {
if ( V_201 -> V_646 == V_649 ||
V_201 -> V_646 == V_650 ) {
V_648 = (struct V_644 * ) V_201 ;
if ( V_646 == V_651 ||
( V_646 == V_652 &&
V_648 -> V_26 & ( 1 << V_653 ) ) )
return V_648 ;
}
V_201 -> V_654 = V_201 -> V_654 ? : V_655 ;
V_201 = ( void * ) V_201 + V_201 -> V_654 ;
}
return NULL ;
}
static struct V_644 * F_186 ( T_1 * V_337 , T_2 V_645 )
{
return F_185 ( V_337 , V_645 , V_652 ) ;
}
static struct V_644 * F_187 ( T_1 * V_337 , T_2 V_645 )
{
return F_185 ( V_337 , V_645 , V_651 ) ;
}
static struct V_656 * F_188 ( T_1 V_657 , T_1 * V_337 ,
T_2 V_645 )
{
struct V_647 * V_201 = (struct V_647 * ) V_337 ;
struct V_656 * V_658 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_645 ; V_5 ++ ) {
if ( ( V_201 -> V_646 == V_659 ||
V_201 -> V_646 == V_660 ) ) {
V_658 = (struct V_656 * ) V_201 ;
if ( V_658 -> V_661 == V_657 )
return V_658 ;
}
V_201 -> V_654 = V_201 -> V_654 ? : V_655 ;
V_201 = ( void * ) V_201 + V_201 -> V_654 ;
}
return NULL ;
}
static struct V_662 * F_189 ( T_1 * V_337 , T_2 V_645 )
{
struct V_647 * V_201 = (struct V_647 * ) V_337 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_645 ; V_5 ++ ) {
if ( V_201 -> V_646 == V_663 )
return (struct V_662 * ) V_201 ;
V_201 -> V_654 = V_201 -> V_654 ? : V_655 ;
V_201 = ( void * ) V_201 + V_201 -> V_654 ;
}
return NULL ;
}
static void F_190 ( struct V_664 * V_665 ,
struct V_644 * V_666 )
{
V_665 -> V_667 = F_26 ( V_666 -> V_668 ) ;
V_665 -> V_669 = F_26 ( V_666 -> V_670 ) ;
V_665 -> V_671 = F_26 ( V_666 -> V_672 ) ;
V_665 -> V_673 = F_26 ( V_666 -> V_674 ) ;
V_665 -> V_675 = F_26 ( V_666 -> V_676 ) ;
V_665 -> V_677 = F_26 ( V_666 -> V_678 ) ;
V_665 -> V_679 = F_26 ( V_666 -> V_680 ) ;
V_665 -> V_681 = F_26 ( V_666 -> V_682 ) ;
V_665 -> V_683 = F_26 ( V_666 -> V_684 ) ;
V_665 -> V_685 = F_26 ( V_666 -> V_686 ) ;
V_665 -> V_687 = F_8 ( V_666 -> V_298 ) &
V_688 ;
}
int F_191 ( struct V_1 * V_2 , struct V_664 * V_665 )
{
struct V_11 * V_12 ;
struct V_689 * V_197 ;
int V_42 ;
struct V_141 V_434 ;
if ( F_86 ( & V_2 -> V_191 ) )
return - 1 ;
memset ( & V_434 , 0 , sizeof( struct V_141 ) ) ;
V_434 . V_180 = sizeof( struct V_690 ) ;
V_434 . V_145 = F_125 ( & V_2 -> V_63 -> V_64 , V_434 . V_180 , & V_434 . V_147 ,
V_344 ) ;
if ( ! V_434 . V_145 ) {
F_18 ( & V_2 -> V_63 -> V_64 , L_21 ) ;
V_42 = - V_345 ;
goto V_160;
}
V_12 = F_79 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = V_434 . V_145 ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_691 ,
V_434 . V_180 , V_12 , & V_434 ) ;
if ( F_192 ( V_2 ) )
V_197 -> V_201 . V_172 = 1 ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_690 * V_56 = V_434 . V_145 ;
T_2 V_645 = F_8 ( V_56 -> V_645 ) ;
struct V_644 * V_666 ;
V_666 = F_187 ( V_56 -> V_692 , V_645 ) ;
if ( ! V_666 ) {
V_42 = - V_437 ;
goto V_160;
}
V_2 -> V_693 = V_666 -> V_661 ;
F_190 ( V_665 , V_666 ) ;
}
V_160:
F_88 ( & V_2 -> V_191 ) ;
if ( V_434 . V_145 )
F_126 ( & V_2 -> V_63 -> V_64 , V_434 . V_180 , V_434 . V_145 ,
V_434 . V_147 ) ;
return V_42 ;
}
int F_193 ( struct V_1 * V_2 ,
struct V_664 * V_665 , T_1 V_694 , T_1 V_222 )
{
struct V_695 * V_56 ;
struct V_696 * V_197 ;
struct V_644 * V_697 ;
struct V_656 * V_658 ;
struct V_662 * V_440 ;
struct V_644 * V_648 ;
struct V_11 V_12 = { 0 } ;
struct V_141 V_434 ;
T_3 V_645 ;
int V_42 ;
memset ( & V_434 , 0 , sizeof( struct V_141 ) ) ;
V_434 . V_180 = sizeof( struct V_695 ) ;
V_434 . V_145 = F_125 ( & V_2 -> V_63 -> V_64 , V_434 . V_180 , & V_434 . V_147 ,
V_344 ) ;
if ( ! V_434 . V_145 )
return - V_345 ;
V_197 = V_434 . V_145 ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_698 ,
V_434 . V_180 , & V_12 , & V_434 ) ;
V_197 -> V_201 . V_222 = V_222 ;
if ( ! F_68 ( V_2 ) )
V_197 -> V_201 . V_172 = 1 ;
V_197 -> type = V_699 ;
if ( V_694 == V_700 )
V_197 -> type |= V_701 ;
V_42 = F_90 ( V_2 , & V_12 ) ;
if ( V_42 )
goto V_160;
V_56 = V_434 . V_145 ;
V_645 = F_26 ( V_56 -> V_645 ) ;
V_658 = F_188 ( V_2 -> V_63 -> V_657 , V_56 -> V_692 ,
V_645 ) ;
if ( V_658 )
V_665 -> V_702 = F_26 ( V_658 -> V_703 ) ;
V_440 = F_189 ( V_56 -> V_692 , V_645 ) ;
if ( V_440 )
V_2 -> V_704 = V_440 -> V_704 ;
V_648 = F_187 ( V_56 -> V_692 , V_645 ) ;
if ( V_648 )
F_190 ( V_665 , V_648 ) ;
V_697 = F_186 ( V_56 -> V_692 , V_645 ) ;
if ( V_697 )
V_665 -> V_705 = V_697 -> V_298 ;
V_160:
if ( V_434 . V_145 )
F_126 ( & V_2 -> V_63 -> V_64 , V_434 . V_180 , V_434 . V_145 ,
V_434 . V_147 ) ;
return V_42 ;
}
static int F_194 ( struct V_1 * V_2 , void * V_666 ,
int V_180 , int V_206 , T_1 V_172 , T_1 V_222 )
{
struct V_706 * V_197 ;
struct V_11 V_12 = { 0 } ;
struct V_141 V_434 ;
int V_42 ;
memset ( & V_434 , 0 , sizeof( struct V_141 ) ) ;
V_434 . V_180 = sizeof( struct V_706 ) ;
V_434 . V_145 = F_125 ( & V_2 -> V_63 -> V_64 , V_434 . V_180 , & V_434 . V_147 ,
V_344 ) ;
if ( ! V_434 . V_145 )
return - V_345 ;
V_197 = V_434 . V_145 ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_707 , V_434 . V_180 ,
& V_12 , & V_434 ) ;
V_197 -> V_201 . V_172 = V_172 ;
V_197 -> V_201 . V_222 = V_222 ;
V_197 -> V_645 = F_74 ( V_206 ) ;
memcpy ( V_197 -> V_666 , V_666 , V_180 ) ;
V_42 = F_90 ( V_2 , & V_12 ) ;
if ( V_434 . V_145 )
F_126 ( & V_2 -> V_63 -> V_64 , V_434 . V_180 , V_434 . V_145 ,
V_434 . V_147 ) ;
return V_42 ;
}
static void F_195 ( struct V_644 * V_648 )
{
memset ( V_648 , 0 , sizeof( * V_648 ) ) ;
V_648 -> V_668 = 0xFFFF ;
V_648 -> V_686 = 0xFFFF ;
V_648 -> V_670 = 0xFFFF ;
V_648 -> V_672 = 0xFFFF ;
V_648 -> V_674 = 0xFFFF ;
V_648 -> V_678 = 0xFFFF ;
V_648 -> V_676 = 0xFFFF ;
V_648 -> V_708 = 0xFFFF ;
V_648 -> V_682 = 0xFFFF ;
V_648 -> V_709 = 0xFFFF ;
V_648 -> V_680 = 0xFFFF ;
V_648 -> V_684 = 0xFFFF ;
V_648 -> V_710 = 0xFF ;
V_648 -> V_711 = F_94 ( 0xF000 ) ;
V_648 -> V_712 = 0xFF ;
V_648 -> V_713 = 0x0F ;
V_648 -> V_714 = 0xFFFF ;
V_648 -> V_715 = 0xFFFF ;
V_648 -> V_716 = 0xFFFFFFFF ;
V_648 -> V_717 = 0xFFFFFFFF ;
}
static void F_196 ( struct V_656 * V_658 )
{
memset ( V_658 , 0 , sizeof( * V_658 ) ) ;
V_658 -> V_718 = 0xFF ;
V_658 -> V_719 = 0xFF ;
V_658 -> V_720 = 0xFF ;
V_658 -> V_703 = 0xFFFF ;
}
int F_197 ( struct V_1 * V_2 , T_2 V_721 , T_3 V_68 ,
T_1 V_222 )
{
struct V_644 V_722 ;
T_2 V_723 ;
T_3 V_172 = 0 ;
if ( F_114 ( V_2 ) )
return F_162 ( V_2 , V_721 / 10 , V_222 ) ;
F_195 ( & V_722 ) ;
V_722 . V_661 = V_2 -> V_693 ;
V_722 . V_724 = V_222 ;
V_722 . V_716 = 0 ;
if ( F_68 ( V_2 ) ) {
V_722 . V_201 . V_646 = V_649 ;
V_722 . V_201 . V_654 = V_655 ;
V_722 . V_26 = ( 1 << V_725 ) | ( 1 << V_726 ) |
( 1 << V_727 ) ;
V_722 . V_717 = F_74 ( V_721 / 10 ) ;
} else {
V_172 = 1 ;
V_722 . V_201 . V_646 = V_650 ;
V_722 . V_201 . V_654 = V_728 ;
V_722 . V_26 = ( 1 << V_726 ) | ( 1 << V_727 ) ;
V_723 = V_721 ? ( V_721 * 100 ) / V_68 : 100 ;
V_722 . V_717 = F_74 ( V_723 ) ;
}
return F_194 ( V_2 , & V_722 ,
V_722 . V_201 . V_654 ,
1 , V_172 , V_222 ) ;
}
static void F_198 ( struct V_1 * V_2 ,
struct V_664 V_729 ,
T_3 V_703 , T_3 V_730 ,
struct V_644 * V_731 )
{
T_2 V_705 = V_729 . V_705 ;
struct V_664 V_732 = { 0 } ;
F_193 ( V_2 , & V_732 , V_700 , 0 ) ;
if ( V_732 . V_705 & V_414 ) {
V_731 -> V_26 |= F_105 ( V_733 ) ;
if ( V_730 > 1 ) {
V_705 |= V_414 ;
if ( V_729 . V_687 & V_734 )
V_705 |= V_734 ;
} else {
V_705 &= ~ ( V_414 |
V_734 ) ;
}
V_731 -> V_298 = F_74 ( V_705 ) ;
} else {
V_730 = 1 ;
}
V_731 -> V_678 = F_94 ( V_730 ) ;
V_731 -> V_674 = F_94 ( V_730 ) ;
V_731 -> V_676 = F_94 ( V_730 ) ;
V_731 -> V_682 = F_94 ( V_729 . V_681 /
( V_703 + 1 ) ) ;
if ( V_732 . V_667 == V_735 )
V_731 -> V_668 = F_94 ( V_729 . V_667 /
( V_703 + 1 ) ) ;
if ( V_732 . V_669 == V_735 )
V_731 -> V_670 = F_94 ( V_729 . V_669 /
( V_703 + 1 ) ) ;
if ( V_732 . V_683 == V_735 )
V_731 -> V_684 = F_94 ( V_729 . V_683 /
( V_703 + 1 ) ) ;
if ( V_732 . V_685 == V_735 )
V_731 -> V_686 = F_94 ( V_729 . V_685 /
( V_703 + 1 ) ) ;
}
int F_199 ( struct V_1 * V_2 ,
struct V_664 V_729 , T_3 V_703 ,
T_3 V_730 )
{
struct {
struct V_656 V_658 ;
struct V_644 V_731 ;
} V_736 V_666 ;
F_196 ( & V_666 . V_658 ) ;
V_666 . V_658 . V_201 . V_646 = V_660 ;
V_666 . V_658 . V_201 . V_654 = V_728 ;
V_666 . V_658 . V_26 = F_105 ( V_726 ) | F_105 ( V_727 ) ;
V_666 . V_658 . V_661 = V_2 -> V_63 -> V_657 ;
V_666 . V_658 . V_718 = V_703 ? 1 : 0 ;
V_666 . V_658 . V_703 = F_94 ( V_703 ) ;
F_195 ( & V_666 . V_731 ) ;
V_666 . V_731 . V_201 . V_646 = V_650 ;
V_666 . V_731 . V_201 . V_654 = V_728 ;
V_666 . V_731 . V_26 = F_105 ( V_653 ) | F_105 ( V_726 ) | F_105 ( V_727 ) ;
V_666 . V_731 . V_661 = V_2 -> V_63 -> V_657 ;
V_666 . V_731 . V_724 = 0 ;
F_198 ( V_2 , V_729 , V_703 , V_730 ,
& V_666 . V_731 ) ;
return F_194 ( V_2 , & V_666 ,
2 * V_728 , 2 , 1 , 0 ) ;
}
int F_200 ( struct V_1 * V_2 , T_2 V_737 , T_1 V_738 )
{
struct V_11 * V_12 ;
struct V_739 * V_197 ;
int V_42 ;
if ( V_737 == 0xFFFFFFFF )
return - 1 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_740 , sizeof( * V_197 ) ,
V_12 , NULL ) ;
V_197 -> V_738 = V_738 ;
V_197 -> V_741 = F_74 ( V_737 ) ;
V_42 = F_54 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_201 ( struct V_1 * V_2 , T_6 V_440 )
{
struct V_662 V_742 ;
memset ( & V_742 , 0 , sizeof( V_742 ) ) ;
V_742 . V_201 . V_646 = V_663 ;
V_742 . V_201 . V_654 = V_728 ;
V_742 . V_26 = ( 1 << V_726 ) | ( 1 << V_727 ) ;
V_742 . V_743 = V_2 -> V_78 ;
if ( V_440 ) {
V_742 . V_744 = V_745 | ( 1 << V_746 ) |
( 1 << V_747 ) ;
V_742 . V_748 = F_202 ( V_440 ) ;
} else {
V_742 . V_744 = V_749 ;
V_742 . V_748 = 0 ;
}
return F_194 ( V_2 , & V_742 ,
V_728 , 1 , 1 , 0 ) ;
}
int F_203 ( struct V_1 * V_2 , struct V_750 * V_751 ,
int V_724 )
{
struct V_11 * V_12 ;
struct V_752 * V_197 ;
struct V_753 * V_56 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_754 , sizeof( * V_56 ) ,
V_12 , NULL ) ;
V_197 -> V_201 . V_222 = V_724 + 1 ;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 ) {
V_56 = (struct V_753 * ) V_197 ;
V_751 -> V_213 = F_8 ( V_56 -> V_755 . V_218 ) ;
}
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
static int F_204 ( struct V_1 * V_2 )
{
#define F_205 30
T_2 V_756 ;
int V_42 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < F_205 ; V_5 ++ ) {
V_756 = F_58 ( V_2 -> V_22 + V_757 ) ;
if ( ( V_756 & V_758 ) == 0 )
break;
F_206 ( 1 ) ;
}
if ( V_5 == F_205 )
V_42 = - 1 ;
return V_42 ;
}
int F_207 ( struct V_1 * V_2 , T_2 V_759 )
{
int V_42 = 0 ;
V_42 = F_204 ( V_2 ) ;
if ( V_42 )
return V_42 ;
F_6 ( V_759 , V_2 -> V_22 + V_757 ) ;
return V_42 ;
}
bool F_208 ( struct V_1 * V_2 )
{
T_2 V_153 = 0 ;
V_153 = F_58 ( V_2 -> V_22 + V_154 ) ;
return ! ! ( V_153 & V_760 ) ;
}
int F_209 ( struct V_1 * V_2 )
{
struct V_76 * V_64 = & V_2 -> V_63 -> V_64 ;
int V_42 ;
if ( F_208 ( V_2 ) ) {
F_23 ( V_64 , L_26 ) ;
return - V_761 ;
}
V_42 = F_207 ( V_2 , V_762 |
V_763 ) ;
if ( V_42 < 0 ) {
F_18 ( V_64 , L_27 ) ;
return V_42 ;
}
V_42 = F_204 ( V_2 ) ;
if ( V_42 )
return V_42 ;
if ( ! F_208 ( V_2 ) ) {
F_18 ( V_64 , L_28 ) ;
return - V_129 ;
}
return 0 ;
}
int F_210 ( struct V_1 * V_2 )
{
int V_42 ;
V_42 = F_150 ( V_2 , V_764 ) ;
return F_211 ( V_42 ) ;
}
int F_212 ( struct V_1 * V_2 , T_1 V_222 )
{
struct V_11 * V_12 ;
struct V_765 * V_197 ;
int V_42 ;
if ( F_20 ( V_2 ) )
return 0 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_766 , sizeof( * V_197 ) ,
V_12 , NULL ) ;
V_197 -> V_201 . V_222 = V_222 ;
V_197 -> V_501 = 1 ;
V_42 = F_54 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_213 ( struct V_1 * V_2 , bool V_767 )
{
struct V_11 * V_12 ;
struct V_768 * V_197 ;
int V_42 ;
if ( F_86 ( & V_2 -> V_191 ) )
return - 1 ;
V_12 = F_79 ( V_2 ) ;
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_769 , sizeof( * V_197 ) ,
V_12 , NULL ) ;
V_197 -> V_770 = V_767 ;
V_42 = F_61 ( V_2 ) ;
F_88 ( & V_2 -> V_191 ) ;
return V_42 ;
}
int F_214 ( struct V_1 * V_2 , T_3 * V_771 )
{
struct V_772 * V_197 ;
struct V_11 * V_12 ;
int V_42 ;
if ( F_86 ( & V_2 -> V_191 ) )
return - 1 ;
V_12 = F_79 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_773 , sizeof( * V_197 ) ,
V_12 , NULL ) ;
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 ) {
struct V_774 * V_56 =
F_2 ( V_12 ) ;
* V_771 = F_26 ( V_56 -> V_775 ) ;
}
V_160:
F_88 ( & V_2 -> V_191 ) ;
return V_42 ;
}
int F_215 ( struct V_1 * V_2 ,
int V_776 , T_1 V_222 )
{
struct V_11 * V_12 ;
struct V_777 * V_197 ;
int V_42 ;
if ( F_20 ( V_2 ) || F_68 ( V_2 ) )
return - V_395 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
F_73 ( & V_197 -> V_201 , V_47 ,
V_778 ,
sizeof( * V_197 ) , V_12 , NULL ) ;
V_197 -> V_201 . V_172 = 1 ;
V_197 -> V_201 . V_222 = V_222 ;
if ( V_776 == V_779 )
V_197 -> V_780 |= 1 ;
if ( V_776 == V_781 )
V_197 -> V_780 |= 1 << V_782 ;
V_42 = F_54 ( V_2 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
int F_216 ( void * V_783 , void * V_784 ,
int V_785 , T_3 * V_786 , T_3 * V_787 )
{
struct V_1 * V_2 = F_217 ( V_783 ) ;
struct V_11 * V_12 ;
struct V_166 * V_201 = (struct V_166 * ) V_784 ;
struct V_166 * V_197 ;
struct V_28 * V_56 ;
int V_42 ;
F_40 ( & V_2 -> V_190 ) ;
V_12 = F_80 ( V_2 ) ;
if ( ! V_12 ) {
V_42 = - V_193 ;
goto V_160;
}
V_197 = F_2 ( V_12 ) ;
V_56 = F_2 ( V_12 ) ;
F_73 ( V_197 , V_201 -> V_4 ,
V_201 -> V_3 , V_785 , V_12 , NULL ) ;
memcpy ( V_197 , V_784 , V_785 ) ;
F_75 ( V_197 , V_785 ) ;
V_42 = F_54 ( V_2 ) ;
if ( V_786 )
* V_786 = ( V_42 & 0xffff ) ;
if ( V_787 )
* V_787 = 0 ;
memcpy ( V_784 , V_56 , sizeof( * V_56 ) + V_56 -> V_788 ) ;
F_16 ( V_784 , sizeof( * V_56 ) + V_56 -> V_788 ) ;
V_160:
F_42 ( & V_2 -> V_190 ) ;
return V_42 ;
}
