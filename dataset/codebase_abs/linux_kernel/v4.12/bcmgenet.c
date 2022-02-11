static inline void F_1 ( struct V_1 * V_2 ,
void T_1 * V_3 , T_2 V_4 )
{
F_2 ( V_4 , V_3 + V_5 ) ;
}
static inline T_2 F_3 ( struct V_1 * V_2 ,
void T_1 * V_3 )
{
return F_4 ( V_3 + V_5 ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
void T_1 * V_3 ,
T_3 V_6 )
{
F_2 ( F_6 ( V_6 ) , V_3 + V_7 ) ;
#ifdef F_7
if ( V_2 -> V_8 -> V_9 & V_10 )
F_2 ( F_8 ( V_6 ) , V_3 + V_11 ) ;
#endif
}
static inline void F_9 ( struct V_1 * V_2 ,
void T_1 * V_3 , T_3 V_6 , T_2 V_12 )
{
F_5 ( V_2 , V_3 , V_6 ) ;
F_1 ( V_2 , V_3 , V_12 ) ;
}
static inline T_3 F_10 ( struct V_1 * V_2 ,
void T_1 * V_3 )
{
T_3 V_6 ;
V_6 = F_4 ( V_3 + V_7 ) ;
#ifdef F_7
if ( V_2 -> V_8 -> V_9 & V_10 )
V_6 |= ( V_13 ) F_4 ( V_3 + V_11 ) << 32 ;
#endif
return V_6 ;
}
static inline T_2 F_11 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) )
return F_13 ( V_2 , V_14 ) ;
else
return F_14 ( V_2 , V_15 ) ;
}
static inline void F_15 ( struct V_1 * V_2 , T_2 V_12 )
{
if ( F_12 ( V_2 ) )
F_16 ( V_2 , V_12 , V_14 ) ;
else
F_17 ( V_2 , V_12 , V_15 ) ;
}
static inline T_2 F_18 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) )
return F_13 ( V_2 , V_16 ) ;
else
return F_4 ( V_2 -> V_17 +
V_2 -> V_8 -> V_18 + V_19 ) ;
}
static inline void F_19 ( struct V_1 * V_2 , T_2 V_12 )
{
if ( F_12 ( V_2 ) )
F_16 ( V_2 , V_12 , V_16 ) ;
else
F_2 ( V_12 , V_2 -> V_17 +
V_2 -> V_8 -> V_18 + V_19 ) ;
}
static inline T_2 F_20 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) )
return F_13 ( V_2 , V_20 ) ;
else
return F_4 ( V_2 -> V_17 +
V_2 -> V_8 -> V_18 + V_21 ) ;
}
static inline void F_21 ( struct V_1 * V_2 , T_2 V_12 )
{
if ( F_12 ( V_2 ) )
F_16 ( V_2 , V_12 , V_20 ) ;
else
F_2 ( V_12 , V_2 -> V_17 +
V_2 -> V_8 -> V_18 + V_21 ) ;
}
static inline struct V_1 * F_22 ( struct V_22 * V_23 )
{
return F_23 ( F_24 ( V_23 ) ) ;
}
static inline T_2 F_25 ( struct V_1 * V_2 ,
enum V_24 V_25 )
{
return F_4 ( V_2 -> V_17 + V_26 +
V_27 + V_28 [ V_25 ] ) ;
}
static inline void F_26 ( struct V_1 * V_2 ,
T_2 V_12 , enum V_24 V_25 )
{
F_2 ( V_12 , V_2 -> V_17 + V_26 +
V_27 + V_28 [ V_25 ] ) ;
}
static inline T_2 F_27 ( struct V_1 * V_2 ,
enum V_24 V_25 )
{
return F_4 ( V_2 -> V_17 + V_29 +
V_27 + V_28 [ V_25 ] ) ;
}
static inline void F_28 ( struct V_1 * V_2 ,
T_2 V_12 , enum V_24 V_25 )
{
F_2 ( V_12 , V_2 -> V_17 + V_29 +
V_27 + V_28 [ V_25 ] ) ;
}
static inline T_2 F_29 ( struct V_1 * V_2 ,
unsigned int V_30 ,
enum V_31 V_25 )
{
return F_4 ( V_2 -> V_17 + V_26 +
( V_32 * V_30 ) +
V_33 [ V_25 ] ) ;
}
static inline void F_30 ( struct V_1 * V_2 ,
unsigned int V_30 , T_2 V_12 ,
enum V_31 V_25 )
{
F_2 ( V_12 , V_2 -> V_17 + V_26 +
( V_32 * V_30 ) +
V_33 [ V_25 ] ) ;
}
static inline T_2 F_31 ( struct V_1 * V_2 ,
unsigned int V_30 ,
enum V_31 V_25 )
{
return F_4 ( V_2 -> V_17 + V_29 +
( V_32 * V_30 ) +
V_33 [ V_25 ] ) ;
}
static inline void F_32 ( struct V_1 * V_2 ,
unsigned int V_30 , T_2 V_12 ,
enum V_31 V_25 )
{
F_2 ( V_12 , V_2 -> V_17 + V_29 +
( V_32 * V_30 ) +
V_33 [ V_25 ] ) ;
}
static int F_33 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
return F_34 ( V_2 -> V_35 ) ;
}
static void F_35 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_36 ( V_2 -> V_35 ) ;
}
static int F_37 ( struct V_34 * V_23 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
if ( ! F_38 ( V_23 ) )
return - V_38 ;
if ( ! V_2 -> V_39 )
return - V_40 ;
return F_39 ( V_2 -> V_39 , V_37 ) ;
}
static int F_40 ( struct V_34 * V_23 ,
const struct V_36 * V_37 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
if ( ! F_38 ( V_23 ) )
return - V_38 ;
if ( ! V_2 -> V_39 )
return - V_40 ;
return F_41 ( V_2 -> V_39 , V_37 ) ;
}
static int F_42 ( struct V_34 * V_23 ,
T_4 V_41 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_42 ;
bool V_43 ;
V_43 = ! ! ( V_41 & V_44 ) ;
V_42 = F_13 ( V_2 , V_45 ) ;
if ( V_43 )
V_42 |= V_46 ;
else
V_42 &= ~ V_46 ;
V_2 -> V_47 = V_43 ;
if ( V_43 && V_2 -> V_48 )
V_42 |= V_49 ;
else
V_42 &= ~ V_49 ;
F_16 ( V_2 , V_42 , V_45 ) ;
return 0 ;
}
static int F_43 ( struct V_34 * V_23 ,
T_4 V_41 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
bool V_50 ;
T_2 V_51 , V_52 ;
V_51 = F_18 ( V_2 ) ;
V_52 = F_13 ( V_2 , V_53 ) ;
V_50 = ! ! ( V_41 & ( V_54 | V_55 ) ) ;
if ( V_50 ) {
V_51 |= V_56 ;
V_52 |= V_56 ;
} else {
V_51 &= ~ V_56 ;
V_52 &= ~ V_56 ;
}
V_2 -> V_50 = V_50 ;
F_19 ( V_2 , V_51 ) ;
F_16 ( V_2 , V_52 , V_53 ) ;
return 0 ;
}
static int F_44 ( struct V_34 * V_23 ,
T_4 V_57 )
{
T_4 V_58 = V_57 ^ V_23 -> V_57 ;
T_4 V_41 = V_23 -> V_59 ;
int V_60 = 0 ;
if ( V_58 & ( V_54 | V_55 ) )
V_60 = F_43 ( V_23 , V_41 ) ;
if ( V_58 & ( V_44 ) )
V_60 = F_42 ( V_23 , V_41 ) ;
return V_60 ;
}
static T_2 F_45 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
return V_2 -> V_61 ;
}
static void F_46 ( struct V_34 * V_23 , T_2 V_62 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
V_2 -> V_61 = V_62 ;
}
static int F_47 ( struct V_34 * V_23 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
V_64 -> V_65 =
F_29 ( V_2 , V_66 ,
V_67 ) ;
V_64 -> V_68 =
F_31 ( V_2 , V_66 ,
V_67 ) ;
V_64 -> V_69 =
F_27 ( V_2 , V_70 ) * 8192 / 1000 ;
return 0 ;
}
static int F_48 ( struct V_34 * V_23 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned int V_71 ;
T_2 V_72 ;
if ( V_64 -> V_65 > V_73 ||
V_64 -> V_65 == 0 ||
V_64 -> V_68 > V_73 ||
V_64 -> V_69 > ( V_74 * 8 ) + 1 )
return - V_38 ;
if ( V_64 -> V_69 == 0 && V_64 -> V_68 == 0 )
return - V_38 ;
if ( V_64 -> V_75 || V_64 -> V_76 ||
V_64 -> V_77 || V_64 -> V_78 )
return - V_79 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; V_71 ++ )
F_30 ( V_2 , V_71 ,
V_64 -> V_65 ,
V_67 ) ;
F_30 ( V_2 , V_66 ,
V_64 -> V_65 ,
V_67 ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; V_71 ++ ) {
F_32 ( V_2 , V_71 ,
V_64 -> V_68 ,
V_67 ) ;
V_72 = F_27 ( V_2 , V_82 + V_71 ) ;
V_72 &= ~ V_74 ;
V_72 |= F_49 ( V_64 -> V_69 * 1000 , 8192 ) ;
F_28 ( V_2 , V_72 , V_82 + V_71 ) ;
}
F_32 ( V_2 , V_66 ,
V_64 -> V_68 ,
V_67 ) ;
V_72 = F_27 ( V_2 , V_70 ) ;
V_72 &= ~ V_74 ;
V_72 |= F_49 ( V_64 -> V_69 * 1000 , 8192 ) ;
F_28 ( V_2 , V_72 , V_70 ) ;
return 0 ;
}
static void F_50 ( struct V_34 * V_23 ,
struct V_83 * V_84 )
{
F_51 ( V_84 -> V_85 , L_1 , sizeof( V_84 -> V_85 ) ) ;
F_51 ( V_84 -> V_86 , L_2 , sizeof( V_84 -> V_86 ) ) ;
}
static int F_52 ( struct V_34 * V_23 , int V_87 )
{
switch ( V_87 ) {
case V_88 :
return V_89 ;
default:
return - V_79 ;
}
}
static void F_53 ( struct V_34 * V_23 , T_2 V_90 ,
T_5 * V_91 )
{
int V_71 ;
switch ( V_90 ) {
case V_88 :
for ( V_71 = 0 ; V_71 < V_89 ; V_71 ++ ) {
memcpy ( V_91 + V_71 * V_92 ,
V_93 [ V_71 ] . V_94 ,
V_92 ) ;
}
break;
}
}
static T_2 F_54 ( struct V_1 * V_2 , T_6 V_95 )
{
T_6 V_96 ;
T_2 V_12 ;
switch ( V_95 ) {
case V_97 :
if ( F_55 ( V_2 ) )
V_96 = V_98 ;
else
V_96 = V_99 ;
V_12 = F_13 ( V_2 , V_96 ) ;
if ( V_12 == ~ 0 )
F_16 ( V_2 , 0 , V_96 ) ;
break;
case V_100 :
if ( F_55 ( V_2 ) )
V_96 = V_101 ;
else
V_96 = V_102 ;
V_12 = F_13 ( V_2 , V_96 ) ;
if ( V_12 == ~ 0 )
F_16 ( V_2 , 0 , V_96 ) ;
break;
default:
V_12 = F_56 ( V_2 , V_95 ) ;
if ( V_12 == ~ 0 )
F_57 ( V_2 , 0 , V_95 ) ;
break;
}
return V_12 ;
}
static void F_58 ( struct V_1 * V_2 )
{
int V_71 , V_103 = 0 ;
for ( V_71 = 0 ; V_71 < V_89 ; V_71 ++ ) {
const struct V_104 * V_105 ;
T_5 V_95 = 0 ;
T_2 V_12 = 0 ;
char * V_106 ;
V_105 = & V_93 [ V_71 ] ;
switch ( V_105 -> type ) {
case V_107 :
case V_108 :
continue;
case V_109 :
V_95 += V_110 ;
case V_111 :
V_95 += V_110 ;
case V_112 :
V_12 = F_56 ( V_2 ,
V_113 + V_103 + V_95 ) ;
V_95 = 0 ;
break;
case V_114 :
if ( F_12 ( V_2 ) ) {
V_12 = F_56 ( V_2 , V_105 -> V_115 ) ;
if ( V_12 == ~ 0 )
F_57 ( V_2 , 0 ,
V_105 -> V_115 ) ;
} else {
V_12 = F_54 ( V_2 ,
V_105 -> V_115 ) ;
}
break;
}
V_103 += V_105 -> V_116 ;
V_106 = ( char * ) V_2 + V_105 -> V_117 ;
* ( T_2 * ) V_106 = V_12 ;
}
}
static void F_59 ( struct V_34 * V_23 ,
struct V_118 * V_119 ,
V_13 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_71 ;
if ( F_38 ( V_23 ) )
F_58 ( V_2 ) ;
for ( V_71 = 0 ; V_71 < V_89 ; V_71 ++ ) {
const struct V_104 * V_105 ;
char * V_106 ;
V_105 = & V_93 [ V_71 ] ;
if ( V_105 -> type == V_107 )
V_106 = ( char * ) & V_23 -> V_119 ;
else
V_106 = ( char * ) V_2 ;
V_106 += V_105 -> V_117 ;
if (sizeof( unsigned long ) != sizeof( T_2 ) &&
V_105 -> V_116 == sizeof( unsigned long ) )
V_91 [ V_71 ] = * ( unsigned long * ) V_106 ;
else
V_91 [ V_71 ] = * ( T_2 * ) V_106 ;
}
}
static void F_60 ( struct V_34 * V_23 , bool V_120 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_121 = V_2 -> V_8 -> V_18 + V_122 ;
T_2 V_72 ;
if ( V_120 && ! V_2 -> V_123 ) {
F_34 ( V_2 -> V_124 ) ;
V_2 -> V_123 = true ;
}
V_72 = F_56 ( V_2 , V_125 ) ;
if ( V_120 )
V_72 |= V_126 ;
else
V_72 &= ~ V_126 ;
F_57 ( V_2 , V_72 , V_125 ) ;
V_72 = F_4 ( V_2 -> V_17 + V_121 ) ;
if ( V_120 )
V_72 |= V_127 | V_128 ;
else
V_72 &= ~ ( V_127 | V_128 ) ;
F_2 ( V_72 , V_2 -> V_17 + V_121 ) ;
V_72 = F_13 ( V_2 , V_129 ) ;
if ( V_120 )
V_72 |= V_130 | V_131 ;
else
V_72 &= ~ ( V_130 | V_131 ) ;
F_16 ( V_2 , V_72 , V_129 ) ;
if ( ! V_120 && V_2 -> V_123 ) {
F_36 ( V_2 -> V_124 ) ;
V_2 -> V_123 = false ;
}
V_2 -> V_132 . V_133 = V_120 ;
V_2 -> V_132 . V_134 = V_120 ;
}
static int F_61 ( struct V_34 * V_23 , struct V_135 * V_136 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_135 * V_106 = & V_2 -> V_132 ;
if ( F_12 ( V_2 ) )
return - V_79 ;
V_136 -> V_133 = V_106 -> V_133 ;
V_136 -> V_134 = V_106 -> V_134 ;
V_136 -> V_137 = F_56 ( V_2 , V_138 ) ;
return F_62 ( V_2 -> V_39 , V_136 ) ;
}
static int F_63 ( struct V_34 * V_23 , struct V_135 * V_136 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_135 * V_106 = & V_2 -> V_132 ;
int V_60 = 0 ;
if ( F_12 ( V_2 ) )
return - V_79 ;
V_106 -> V_133 = V_136 -> V_133 ;
if ( ! V_106 -> V_133 ) {
F_60 ( V_23 , false ) ;
} else {
V_60 = F_64 ( V_2 -> V_39 , 0 ) ;
if ( V_60 ) {
F_65 ( V_2 , V_139 , V_23 , L_3 ) ;
return V_60 ;
}
F_57 ( V_2 , V_136 -> V_137 , V_138 ) ;
F_60 ( V_23 , true ) ;
}
return F_66 ( V_2 -> V_39 , V_136 ) ;
}
static int F_67 ( struct V_1 * V_2 ,
enum V_140 V_141 )
{
int V_60 = 0 ;
T_2 V_72 ;
switch ( V_141 ) {
case V_142 :
F_68 ( V_2 -> V_39 ) ;
break;
case V_143 :
V_60 = F_69 ( V_2 , V_141 ) ;
break;
case V_144 :
if ( V_2 -> V_8 -> V_9 & V_145 ) {
V_72 = F_70 ( V_2 , V_146 ) ;
if ( F_71 ( V_2 ) )
V_72 |= V_147 |
V_148 |
V_149 |
V_150 |
V_151 |
V_152 ;
else
V_72 |= V_153 ;
V_72 |= ( V_154 | V_155 ) ;
F_72 ( V_2 , V_72 , V_146 ) ;
F_73 ( V_2 -> V_23 , false ) ;
}
break;
default:
break;
}
return 0 ;
}
static void F_74 ( struct V_1 * V_2 ,
enum V_140 V_141 )
{
T_2 V_72 ;
if ( ! ( V_2 -> V_8 -> V_9 & V_145 ) )
return;
V_72 = F_70 ( V_2 , V_146 ) ;
switch ( V_141 ) {
case V_144 :
V_72 &= ~ ( V_154 | V_155 ) ;
if ( F_71 ( V_2 ) ) {
V_72 &= ~ ( V_147 |
V_148 |
V_149 |
V_150 |
V_151 |
V_152 ) ;
V_72 |= V_156 ;
F_72 ( V_2 , V_72 , V_146 ) ;
F_75 ( 1 ) ;
V_72 &= ~ V_156 ;
} else {
V_72 &= ~ V_153 ;
V_72 |= V_157 ;
}
F_72 ( V_2 , V_72 , V_146 ) ;
F_73 ( V_2 -> V_23 , true ) ;
F_76 ( V_2 -> V_23 ) ;
break;
case V_142 :
if ( ! F_71 ( V_2 ) ) {
V_72 |= V_157 ;
F_72 ( V_2 , V_72 , V_146 ) ;
}
break;
case V_143 :
F_77 ( V_2 , V_141 ) ;
return;
default:
break;
}
}
static int F_78 ( struct V_34 * V_23 , struct V_158 * V_159 , int V_37 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
if ( ! F_38 ( V_23 ) )
return - V_38 ;
if ( ! V_2 -> V_39 )
return - V_40 ;
return F_79 ( V_2 -> V_39 , V_159 , V_37 ) ;
}
static struct V_160 * F_80 ( struct V_1 * V_2 ,
struct V_161 * V_30 )
{
struct V_160 * V_162 ;
V_162 = V_30 -> V_163 ;
V_162 += V_30 -> V_164 - V_30 -> V_165 ;
if ( V_30 -> V_164 == V_30 -> V_166 )
V_30 -> V_164 = V_30 -> V_165 ;
else
V_30 -> V_164 ++ ;
return V_162 ;
}
static void F_81 ( struct V_160 * V_167 )
{
F_82 ( V_167 -> V_168 ) ;
V_167 -> V_168 = NULL ;
F_83 ( V_167 , V_169 , 0 ) ;
}
static inline void F_84 ( struct V_170 * V_30 )
{
F_85 ( V_30 -> V_2 , V_171 ,
V_172 ) ;
}
static inline void F_86 ( struct V_170 * V_30 )
{
F_85 ( V_30 -> V_2 , V_171 ,
V_173 ) ;
}
static inline void F_87 ( struct V_170 * V_30 )
{
F_88 ( V_30 -> V_2 ,
1 << ( V_174 + V_30 -> V_175 ) ,
V_172 ) ;
}
static inline void F_89 ( struct V_170 * V_30 )
{
F_88 ( V_30 -> V_2 ,
1 << ( V_174 + V_30 -> V_175 ) ,
V_173 ) ;
}
static inline void F_90 ( struct V_161 * V_30 )
{
F_85 ( V_30 -> V_2 , V_176 ,
V_172 ) ;
}
static inline void F_91 ( struct V_161 * V_30 )
{
F_85 ( V_30 -> V_2 , V_176 ,
V_173 ) ;
}
static inline void F_92 ( struct V_161 * V_30 )
{
F_88 ( V_30 -> V_2 , 1 << V_30 -> V_175 ,
V_173 ) ;
}
static inline void F_93 ( struct V_161 * V_30 )
{
F_88 ( V_30 -> V_2 , 1 << V_30 -> V_175 ,
V_172 ) ;
}
static unsigned int F_94 ( struct V_34 * V_23 ,
struct V_161 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_22 * V_177 = & V_2 -> V_178 -> V_23 ;
struct V_160 * V_162 ;
unsigned int V_179 = 0 ;
unsigned int V_180 = 0 ;
unsigned int V_181 ;
unsigned int V_182 ;
unsigned int V_183 = 0 ;
if ( V_30 -> V_175 == V_66 )
F_85 ( V_2 , V_176 ,
V_184 ) ;
else
F_88 ( V_2 , ( 1 << V_30 -> V_175 ) ,
V_184 ) ;
V_181 = F_29 ( V_2 , V_30 -> V_175 , V_185 )
& V_186 ;
V_182 = ( V_181 - V_30 -> V_181 ) & V_186 ;
F_95 ( V_2 , V_187 , V_23 ,
L_4 ,
V_188 , V_30 -> V_175 , V_30 -> V_181 , V_181 , V_182 ) ;
while ( V_183 < V_182 ) {
V_162 = & V_2 -> V_189 [ V_30 -> V_190 ] ;
if ( V_162 -> V_168 ) {
V_179 ++ ;
V_180 += F_96 ( V_162 -> V_168 ) -> V_191 ;
F_97 ( V_177 ,
F_98 ( V_162 , V_169 ) ,
F_99 ( V_162 , V_192 ) ,
V_193 ) ;
F_81 ( V_162 ) ;
} else if ( F_98 ( V_162 , V_169 ) ) {
F_100 ( V_177 ,
F_98 ( V_162 , V_169 ) ,
F_99 ( V_162 , V_192 ) ,
V_193 ) ;
F_83 ( V_162 , V_169 , 0 ) ;
}
V_183 ++ ;
if ( F_101 ( V_30 -> V_190 < V_30 -> V_166 ) )
V_30 -> V_190 ++ ;
else
V_30 -> V_190 = V_30 -> V_165 ;
}
V_30 -> V_194 += V_183 ;
V_30 -> V_181 = V_181 ;
V_30 -> V_195 += V_179 ;
V_30 -> V_196 += V_180 ;
F_102 ( F_103 ( V_23 , V_30 -> V_197 ) ,
V_179 , V_180 ) ;
return V_183 ;
}
static unsigned int F_104 ( struct V_34 * V_23 ,
struct V_161 * V_30 )
{
unsigned int V_198 ;
unsigned long V_9 ;
F_105 ( & V_30 -> V_199 , V_9 ) ;
V_198 = F_94 ( V_23 , V_30 ) ;
F_106 ( & V_30 -> V_199 , V_9 ) ;
return V_198 ;
}
static int F_107 ( struct V_200 * V_201 , int V_202 )
{
struct V_161 * V_30 =
F_108 ( V_201 , struct V_161 , V_201 ) ;
unsigned int V_203 = 0 ;
struct V_204 * V_205 ;
unsigned long V_9 ;
F_105 ( & V_30 -> V_199 , V_9 ) ;
V_203 = F_94 ( V_30 -> V_2 -> V_23 , V_30 ) ;
if ( V_30 -> V_194 > ( V_206 + 1 ) ) {
V_205 = F_103 ( V_30 -> V_2 -> V_23 , V_30 -> V_197 ) ;
F_109 ( V_205 ) ;
}
F_106 ( & V_30 -> V_199 , V_9 ) ;
if ( V_203 == 0 ) {
F_110 ( V_201 ) ;
V_30 -> V_207 ( V_30 ) ;
return 0 ;
}
return V_202 ;
}
static void F_111 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_71 ;
if ( F_112 ( V_23 ) ) {
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; V_71 ++ )
F_104 ( V_23 , & V_2 -> V_208 [ V_71 ] ) ;
}
F_104 ( V_23 , & V_2 -> V_208 [ V_66 ] ) ;
}
static int F_113 ( struct V_34 * V_23 ,
struct V_209 * V_168 ,
T_6 V_210 ,
struct V_161 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_22 * V_177 = & V_2 -> V_178 -> V_23 ;
struct V_160 * V_162 ;
unsigned int V_211 ;
T_3 V_212 ;
T_2 V_213 ;
int V_60 ;
V_162 = F_80 ( V_2 , V_30 ) ;
if ( F_114 ( ! V_162 ) )
F_115 () ;
V_162 -> V_168 = V_168 ;
V_211 = F_116 ( V_168 ) ;
V_212 = F_117 ( V_177 , V_168 -> V_91 , V_211 , V_193 ) ;
V_60 = F_118 ( V_177 , V_212 ) ;
if ( V_60 ) {
V_2 -> V_214 . V_215 ++ ;
F_65 ( V_2 , V_216 , V_23 , L_5 ) ;
F_119 ( V_168 ) ;
return V_60 ;
}
F_83 ( V_162 , V_169 , V_212 ) ;
F_120 ( V_162 , V_192 , V_211 ) ;
V_213 = ( V_211 << V_217 ) | V_210 |
( V_2 -> V_8 -> V_218 << V_219 ) |
V_220 ;
if ( V_168 -> V_221 == V_222 )
V_213 |= V_223 ;
F_9 ( V_2 , V_162 -> V_224 , V_212 , V_213 ) ;
return 0 ;
}
static int F_121 ( struct V_34 * V_23 ,
T_7 * V_225 ,
T_6 V_210 ,
struct V_161 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_22 * V_177 = & V_2 -> V_178 -> V_23 ;
struct V_160 * V_162 ;
unsigned int V_226 ;
T_3 V_212 ;
int V_60 ;
V_162 = F_80 ( V_2 , V_30 ) ;
if ( F_114 ( ! V_162 ) )
F_115 () ;
V_162 -> V_168 = NULL ;
V_226 = F_122 ( V_225 ) ;
V_212 = F_123 ( V_177 , V_225 , 0 , V_226 , V_193 ) ;
V_60 = F_118 ( V_177 , V_212 ) ;
if ( V_60 ) {
V_2 -> V_214 . V_215 ++ ;
F_65 ( V_2 , V_216 , V_23 , L_6 ,
V_188 ) ;
return V_60 ;
}
F_83 ( V_162 , V_169 , V_212 ) ;
F_120 ( V_162 , V_192 , V_226 ) ;
F_9 ( V_2 , V_162 -> V_224 , V_212 ,
( V_226 << V_217 ) | V_210 |
( V_2 -> V_8 -> V_218 << V_219 ) ) ;
return 0 ;
}
static struct V_209 * F_124 ( struct V_34 * V_23 ,
struct V_209 * V_168 )
{
struct V_227 * V_228 = NULL ;
struct V_209 * V_229 ;
T_6 V_95 ;
T_5 V_230 ;
T_6 V_231 ;
T_2 V_232 ;
if ( F_114 ( F_125 ( V_168 ) < sizeof( * V_228 ) ) ) {
V_229 = F_126 ( V_168 , sizeof( * V_228 ) ) ;
F_119 ( V_168 ) ;
if ( ! V_229 ) {
V_23 -> V_119 . V_233 ++ ;
return NULL ;
}
V_168 = V_229 ;
}
F_127 ( V_168 , sizeof( * V_228 ) ) ;
V_228 = (struct V_227 * ) V_168 -> V_91 ;
if ( V_168 -> V_221 == V_222 ) {
V_231 = F_128 ( V_168 -> V_234 ) ;
switch ( V_231 ) {
case V_235 :
V_230 = F_129 ( V_168 ) -> V_234 ;
break;
case V_236 :
V_230 = F_130 ( V_168 ) -> V_237 ;
break;
default:
return V_168 ;
}
V_95 = F_131 ( V_168 ) - sizeof( * V_228 ) ;
V_232 = ( V_95 << V_238 ) |
( V_95 + V_168 -> V_239 ) ;
if ( V_230 == V_240 || V_230 == V_241 ) {
V_232 |= V_242 ;
if ( V_230 == V_241 && V_231 == V_235 )
V_232 |= V_243 ;
} else {
V_232 = 0 ;
}
V_228 -> V_232 = V_232 ;
}
return V_168 ;
}
static T_8 F_132 ( struct V_209 * V_168 , struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_161 * V_30 = NULL ;
struct V_204 * V_205 ;
unsigned long V_9 = 0 ;
int V_244 , V_175 ;
T_6 V_210 ;
int V_60 ;
int V_71 ;
V_175 = F_133 ( V_168 ) ;
if ( V_175 == 0 )
V_175 = V_66 ;
else
V_175 -= 1 ;
V_30 = & V_2 -> V_208 [ V_175 ] ;
V_205 = F_103 ( V_23 , V_30 -> V_197 ) ;
V_244 = F_134 ( V_168 ) -> V_244 ;
F_105 ( & V_30 -> V_199 , V_9 ) ;
if ( V_30 -> V_194 <= ( V_244 + 1 ) ) {
if ( ! F_135 ( V_205 ) ) {
F_136 ( V_205 ) ;
F_137 ( V_23 ,
L_7 ,
V_188 , V_175 , V_30 -> V_197 ) ;
}
V_60 = V_245 ;
goto V_246;
}
if ( F_138 ( V_168 , V_247 ) ) {
V_60 = V_248 ;
goto V_246;
}
F_96 ( V_168 ) -> V_191 = V_168 -> V_249 ;
if ( V_2 -> V_50 ) {
V_168 = F_124 ( V_23 , V_168 ) ;
if ( ! V_168 ) {
V_60 = V_248 ;
goto V_246;
}
}
V_210 = V_250 ;
if ( V_244 == 0 )
V_210 |= V_251 ;
V_60 = F_113 ( V_23 , V_168 , V_210 , V_30 ) ;
if ( V_60 ) {
V_60 = V_248 ;
goto V_246;
}
for ( V_71 = 0 ; V_71 < V_244 ; V_71 ++ ) {
V_60 = F_121 ( V_23 ,
& F_134 ( V_168 ) -> V_252 [ V_71 ] ,
( V_71 == V_244 - 1 ) ? V_251 : 0 ,
V_30 ) ;
if ( V_60 ) {
V_60 = V_248 ;
goto V_246;
}
}
F_139 ( V_168 ) ;
V_30 -> V_194 -= V_244 + 1 ;
V_30 -> V_253 += V_244 + 1 ;
V_30 -> V_253 &= V_254 ;
F_140 ( V_205 , F_96 ( V_168 ) -> V_191 ) ;
if ( V_30 -> V_194 <= ( V_206 + 1 ) )
F_136 ( V_205 ) ;
if ( ! V_168 -> V_255 || F_141 ( V_205 ) )
F_30 ( V_2 , V_30 -> V_175 ,
V_30 -> V_253 , V_256 ) ;
V_246:
F_106 ( & V_30 -> V_199 , V_9 ) ;
return V_60 ;
}
static struct V_209 * F_142 ( struct V_1 * V_2 ,
struct V_160 * V_167 )
{
struct V_22 * V_177 = & V_2 -> V_178 -> V_23 ;
struct V_209 * V_168 ;
struct V_209 * V_257 ;
T_3 V_212 ;
V_168 = F_143 ( V_2 -> V_23 , V_2 -> V_258 + V_259 ) ;
if ( ! V_168 ) {
V_2 -> V_214 . V_260 ++ ;
F_65 ( V_2 , V_261 , V_2 -> V_23 ,
L_8 , V_188 ) ;
return NULL ;
}
V_212 = F_117 ( V_177 , V_168 -> V_91 , V_2 -> V_258 ,
V_262 ) ;
if ( F_118 ( V_177 , V_212 ) ) {
V_2 -> V_214 . V_263 ++ ;
F_82 ( V_168 ) ;
F_65 ( V_2 , V_261 , V_2 -> V_23 ,
L_9 , V_188 ) ;
return NULL ;
}
V_257 = V_167 -> V_168 ;
if ( F_101 ( V_257 ) )
F_97 ( V_177 , F_98 ( V_167 , V_169 ) ,
V_2 -> V_258 , V_262 ) ;
V_167 -> V_168 = V_168 ;
F_83 ( V_167 , V_169 , V_212 ) ;
F_5 ( V_2 , V_167 -> V_224 , V_212 ) ;
return V_257 ;
}
static unsigned int F_144 ( struct V_170 * V_30 ,
unsigned int V_202 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_34 * V_23 = V_2 -> V_23 ;
struct V_160 * V_167 ;
struct V_209 * V_168 ;
T_2 V_264 ;
unsigned long V_265 ;
int V_249 ;
unsigned int V_266 = 0 , V_267 ;
unsigned int V_268 , V_269 ;
unsigned int V_270 ;
unsigned int V_271 = 0 ;
if ( V_30 -> V_175 == V_66 ) {
F_85 ( V_2 , V_171 ,
V_184 ) ;
} else {
V_269 = 1 << ( V_174 + V_30 -> V_175 ) ;
F_88 ( V_2 ,
V_269 ,
V_184 ) ;
}
V_268 = F_31 ( V_2 , V_30 -> V_175 , V_272 ) ;
V_270 = ( V_268 >> V_273 ) &
V_274 ;
if ( V_270 > V_30 -> V_275 ) {
V_270 = V_270 - V_30 -> V_275 ;
V_30 -> V_276 += V_270 ;
V_30 -> V_275 += V_270 ;
if ( V_30 -> V_275 >= 0xC000 ) {
V_30 -> V_275 = 0 ;
F_32 ( V_2 , V_30 -> V_175 , 0 ,
V_272 ) ;
}
}
V_268 &= V_254 ;
V_267 = ( V_268 - V_30 -> V_181 ) & V_186 ;
F_95 ( V_2 , V_277 , V_23 ,
L_10 , V_267 ) ;
while ( ( V_266 < V_267 ) &&
( V_266 < V_202 ) ) {
V_167 = & V_2 -> V_278 [ V_30 -> V_279 ] ;
V_168 = F_142 ( V_2 , V_167 ) ;
if ( F_114 ( ! V_168 ) ) {
V_30 -> V_280 ++ ;
goto V_281;
}
if ( ! V_2 -> V_50 ) {
V_264 =
F_3 ( V_2 , V_167 -> V_224 ) ;
} else {
struct V_227 * V_228 ;
V_228 = (struct V_227 * ) V_168 -> V_91 ;
V_264 = V_228 -> V_213 ;
}
V_265 = V_264 & 0xffff ;
V_249 = V_264 >> V_217 ;
F_95 ( V_2 , V_277 , V_23 ,
L_11 ,
V_188 , V_268 , V_30 -> V_181 ,
V_30 -> V_279 , V_264 ) ;
if ( F_114 ( ! ( V_265 & V_251 ) || ! ( V_265 & V_250 ) ) ) {
F_65 ( V_2 , V_277 , V_23 ,
L_12 ) ;
V_30 -> V_276 ++ ;
F_82 ( V_168 ) ;
goto V_281;
}
if ( F_114 ( V_265 & ( V_282 |
V_283 |
V_284 |
V_285 |
V_286 ) ) ) {
F_65 ( V_2 , V_277 , V_23 , L_13 ,
( unsigned int ) V_265 ) ;
if ( V_265 & V_282 )
V_23 -> V_119 . V_287 ++ ;
if ( V_265 & V_283 )
V_23 -> V_119 . V_288 ++ ;
if ( V_265 & V_284 )
V_23 -> V_119 . V_289 ++ ;
if ( V_265 & V_285 )
V_23 -> V_119 . V_290 ++ ;
V_23 -> V_119 . V_291 ++ ;
F_82 ( V_168 ) ;
goto V_281;
}
V_271 = ( V_265 & V_2 -> V_292 ) &&
V_2 -> V_47 ;
F_145 ( V_168 , V_249 ) ;
if ( V_2 -> V_50 ) {
F_146 ( V_168 , 64 ) ;
V_249 -= 64 ;
}
if ( F_101 ( V_271 ) )
V_168 -> V_221 = V_293 ;
F_146 ( V_168 , 2 ) ;
V_249 -= 2 ;
if ( V_2 -> V_48 ) {
F_147 ( V_168 , V_249 - V_294 ) ;
V_249 -= V_294 ;
}
V_168 -> V_234 = F_148 ( V_168 , V_2 -> V_23 ) ;
V_30 -> V_195 ++ ;
V_30 -> V_196 += V_249 ;
if ( V_265 & V_295 )
V_23 -> V_119 . V_296 ++ ;
F_149 ( & V_30 -> V_201 , V_168 ) ;
F_95 ( V_2 , V_277 , V_23 , L_14 ) ;
V_281:
V_266 ++ ;
if ( F_101 ( V_30 -> V_279 < V_30 -> V_166 ) )
V_30 -> V_279 ++ ;
else
V_30 -> V_279 = V_30 -> V_165 ;
V_30 -> V_181 = ( V_30 -> V_181 + 1 ) & V_186 ;
F_32 ( V_2 , V_30 -> V_175 , V_30 -> V_181 , V_297 ) ;
}
return V_266 ;
}
static int F_150 ( struct V_200 * V_201 , int V_202 )
{
struct V_170 * V_30 = F_108 ( V_201 ,
struct V_170 , V_201 ) ;
unsigned int V_203 ;
V_203 = F_144 ( V_30 , V_202 ) ;
if ( V_203 < V_202 ) {
F_151 ( V_201 , V_203 ) ;
V_30 -> V_207 ( V_30 ) ;
}
return V_203 ;
}
static int F_152 ( struct V_1 * V_2 ,
struct V_170 * V_30 )
{
struct V_160 * V_167 ;
struct V_209 * V_168 ;
int V_71 ;
F_95 ( V_2 , V_139 , V_2 -> V_23 , L_15 , V_188 ) ;
for ( V_71 = 0 ; V_71 < V_30 -> V_298 ; V_71 ++ ) {
V_167 = V_30 -> V_163 + V_71 ;
V_168 = F_142 ( V_2 , V_167 ) ;
if ( V_168 )
F_82 ( V_168 ) ;
if ( ! V_167 -> V_168 )
return - V_299 ;
}
return 0 ;
}
static void F_153 ( struct V_1 * V_2 )
{
struct V_22 * V_177 = & V_2 -> V_178 -> V_23 ;
struct V_160 * V_167 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_300 ; V_71 ++ ) {
V_167 = & V_2 -> V_278 [ V_71 ] ;
if ( F_98 ( V_167 , V_169 ) ) {
F_97 ( V_177 ,
F_98 ( V_167 , V_169 ) ,
V_2 -> V_258 , V_262 ) ;
F_83 ( V_167 , V_169 , 0 ) ;
}
if ( V_167 -> V_168 )
F_81 ( V_167 ) ;
}
}
static void F_154 ( struct V_1 * V_2 , T_2 V_269 , bool V_120 )
{
T_2 V_72 ;
V_72 = F_56 ( V_2 , V_301 ) ;
if ( V_120 )
V_72 |= V_269 ;
else
V_72 &= ~ V_269 ;
F_57 ( V_2 , V_72 , V_301 ) ;
if ( V_120 == 0 )
F_155 ( 1000 , 2000 ) ;
}
static int F_156 ( struct V_1 * V_2 )
{
struct V_22 * V_177 = & V_2 -> V_178 -> V_23 ;
unsigned int V_302 = 0 ;
T_2 V_72 ;
F_15 ( V_2 , 0 ) ;
F_157 ( 10 ) ;
F_57 ( V_2 , 0 , V_301 ) ;
F_57 ( V_2 , V_303 , V_301 ) ;
while ( V_302 ++ < 1000 ) {
V_72 = F_56 ( V_2 , V_301 ) ;
if ( ! ( V_72 & V_303 ) )
return 0 ;
F_157 ( 1 ) ;
}
if ( V_302 == 1000 ) {
F_158 ( V_177 ,
L_16 ) ;
return - V_304 ;
}
return 0 ;
}
static void F_159 ( struct V_1 * V_2 )
{
F_85 ( V_2 , 0xFFFFFFFF , V_172 ) ;
F_85 ( V_2 , 0xFFFFFFFF , V_184 ) ;
F_88 ( V_2 , 0xFFFFFFFF , V_172 ) ;
F_88 ( V_2 , 0xFFFFFFFF , V_184 ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
T_2 V_305 = 0 ;
if ( V_2 -> V_306 ) {
V_305 |= V_307 ;
} else if ( V_2 -> V_308 ) {
V_305 |= V_307 ;
} else if ( V_2 -> V_309 == V_310 ) {
if ( V_2 -> V_8 -> V_9 & V_311 )
V_305 |= V_307 ;
}
F_85 ( V_2 , V_305 , V_173 ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
struct V_22 * V_177 = & V_2 -> V_178 -> V_23 ;
int V_60 ;
T_2 V_72 ;
T_2 V_305 = 0 ;
F_162 ( & V_2 -> V_178 -> V_23 , L_17 ) ;
V_60 = F_156 ( V_2 ) ;
if ( V_60 )
return V_60 ;
F_57 ( V_2 , 0 , V_301 ) ;
F_57 ( V_2 ,
V_312 | V_313 | V_314 ,
V_315 ) ;
F_57 ( V_2 , 0 , V_315 ) ;
F_57 ( V_2 , V_316 , V_317 ) ;
V_72 = F_13 ( V_2 , V_53 ) ;
V_72 |= V_318 ;
F_16 ( V_2 , V_72 , V_53 ) ;
if ( ! F_12 ( V_2 ) && ! F_55 ( V_2 ) )
F_16 ( V_2 , 1 , V_319 ) ;
F_159 ( V_2 ) ;
if ( V_2 -> V_309 == V_310 ) {
V_72 = F_20 ( V_2 ) ;
V_72 |= F_163 ( V_2 -> V_8 -> V_320 ) ;
if ( F_112 ( V_2 -> V_23 ) )
V_72 |= V_2 -> V_8 -> V_321 ;
else
V_72 &= ~ V_2 -> V_8 -> V_321 ;
F_21 ( V_2 , V_72 ) ;
}
if ( V_2 -> V_8 -> V_9 & V_322 )
V_305 |= ( V_323 | V_324 ) ;
F_85 ( V_2 , V_305 , V_173 ) ;
F_162 ( V_177 , L_18 ) ;
return 0 ;
}
static void F_164 ( struct V_1 * V_2 ,
unsigned int V_175 , unsigned int V_298 ,
unsigned int V_325 , unsigned int V_166 )
{
struct V_161 * V_30 = & V_2 -> V_208 [ V_175 ] ;
T_2 V_326 = F_165 ( V_2 ) ;
T_2 V_327 = 0 ;
F_166 ( & V_30 -> V_199 ) ;
V_30 -> V_2 = V_2 ;
V_30 -> V_175 = V_175 ;
if ( V_175 == V_66 ) {
V_30 -> V_197 = 0 ;
V_30 -> V_207 = F_91 ;
V_30 -> V_328 = F_90 ;
} else {
V_30 -> V_197 = V_175 + 1 ;
V_30 -> V_207 = F_92 ;
V_30 -> V_328 = F_93 ;
}
V_30 -> V_163 = V_2 -> V_189 + V_325 ;
V_30 -> V_298 = V_298 ;
V_30 -> V_190 = V_325 ;
V_30 -> V_181 = 0 ;
V_30 -> V_194 = V_298 ;
V_30 -> V_164 = V_325 ;
V_30 -> V_165 = V_325 ;
V_30 -> V_166 = V_166 - 1 ;
V_30 -> V_253 = 0 ;
if ( V_175 != V_66 )
V_327 = V_316 << 16 ;
F_30 ( V_2 , V_175 , 0 , V_256 ) ;
F_30 ( V_2 , V_175 , 0 , V_185 ) ;
F_30 ( V_2 , V_175 , 1 , V_67 ) ;
F_30 ( V_2 , V_175 , V_327 ,
V_329 ) ;
F_30 ( V_2 , V_175 ,
( ( V_298 << V_330 ) |
V_331 ) , V_332 ) ;
F_30 ( V_2 , V_175 , V_325 * V_326 ,
V_333 ) ;
F_30 ( V_2 , V_175 , V_325 * V_326 ,
V_334 ) ;
F_30 ( V_2 , V_175 , V_325 * V_326 ,
V_335 ) ;
F_30 ( V_2 , V_175 , V_166 * V_326 - 1 ,
V_336 ) ;
}
static int F_167 ( struct V_1 * V_2 ,
unsigned int V_175 , unsigned int V_298 ,
unsigned int V_325 , unsigned int V_166 )
{
struct V_170 * V_30 = & V_2 -> V_337 [ V_175 ] ;
T_2 V_326 = F_165 ( V_2 ) ;
int V_60 ;
V_30 -> V_2 = V_2 ;
V_30 -> V_175 = V_175 ;
if ( V_175 == V_66 ) {
V_30 -> V_207 = F_86 ;
V_30 -> V_328 = F_84 ;
} else {
V_30 -> V_207 = F_89 ;
V_30 -> V_328 = F_87 ;
}
V_30 -> V_163 = V_2 -> V_278 + V_325 ;
V_30 -> V_298 = V_298 ;
V_30 -> V_181 = 0 ;
V_30 -> V_279 = V_325 ;
V_30 -> V_165 = V_325 ;
V_30 -> V_166 = V_166 - 1 ;
V_60 = F_152 ( V_2 , V_30 ) ;
if ( V_60 )
return V_60 ;
F_32 ( V_2 , V_175 , 0 , V_272 ) ;
F_32 ( V_2 , V_175 , 0 , V_297 ) ;
F_32 ( V_2 , V_175 , 1 , V_67 ) ;
F_32 ( V_2 , V_175 ,
( ( V_298 << V_330 ) |
V_331 ) , V_332 ) ;
F_32 ( V_2 , V_175 ,
( V_338 <<
V_339 ) |
V_340 , V_341 ) ;
F_32 ( V_2 , V_175 , V_325 * V_326 ,
V_333 ) ;
F_32 ( V_2 , V_175 , V_325 * V_326 ,
V_342 ) ;
F_32 ( V_2 , V_175 , V_325 * V_326 ,
V_343 ) ;
F_32 ( V_2 , V_175 , V_166 * V_326 - 1 ,
V_336 ) ;
return V_60 ;
}
static void F_168 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
struct V_161 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; ++ V_71 ) {
V_30 = & V_2 -> V_208 [ V_71 ] ;
F_169 ( V_2 -> V_23 , & V_30 -> V_201 , F_107 , 64 ) ;
}
V_30 = & V_2 -> V_208 [ V_66 ] ;
F_169 ( V_2 -> V_23 , & V_30 -> V_201 , F_107 , 64 ) ;
}
static void F_170 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
T_2 V_305 = V_176 ;
T_2 V_344 = 0 ;
struct V_161 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; ++ V_71 ) {
V_30 = & V_2 -> V_208 [ V_71 ] ;
F_171 ( & V_30 -> V_201 ) ;
V_344 |= ( 1 << V_71 ) ;
}
V_30 = & V_2 -> V_208 [ V_66 ] ;
F_171 ( & V_30 -> V_201 ) ;
F_85 ( V_2 , V_305 , V_173 ) ;
F_88 ( V_2 , V_344 , V_173 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
T_2 V_345 = V_176 ;
T_2 V_346 = 0xffff ;
struct V_161 * V_30 ;
F_85 ( V_2 , V_345 , V_172 ) ;
F_88 ( V_2 , V_346 , V_172 ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; ++ V_71 ) {
V_30 = & V_2 -> V_208 [ V_71 ] ;
F_173 ( & V_30 -> V_201 ) ;
}
V_30 = & V_2 -> V_208 [ V_66 ] ;
F_173 ( & V_30 -> V_201 ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
struct V_161 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; ++ V_71 ) {
V_30 = & V_2 -> V_208 [ V_71 ] ;
F_175 ( & V_30 -> V_201 ) ;
}
V_30 = & V_2 -> V_208 [ V_66 ] ;
F_175 ( & V_30 -> V_201 ) ;
}
static void F_176 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_71 , V_347 ;
T_2 V_348 , V_349 ;
T_2 V_350 [ 3 ] = { 0 , 0 , 0 } ;
V_348 = F_25 ( V_2 , V_351 ) ;
V_347 = V_348 & V_352 ;
V_348 &= ~ V_352 ;
F_26 ( V_2 , V_348 , V_351 ) ;
V_348 = 0 ;
V_349 = 0 ;
F_26 ( V_2 , V_353 , V_354 ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; V_71 ++ ) {
F_164 ( V_2 , V_71 , V_2 -> V_8 -> V_355 ,
V_71 * V_2 -> V_8 -> V_355 ,
( V_71 + 1 ) * V_2 -> V_8 -> V_355 ) ;
V_349 |= ( 1 << V_71 ) ;
V_348 |= ( 1 << ( V_71 + V_356 ) ) ;
V_350 [ F_177 ( V_71 ) ] |=
( ( V_357 + V_71 ) << F_178 ( V_71 ) ) ;
}
F_164 ( V_2 , V_66 , V_358 ,
V_2 -> V_8 -> V_80 *
V_2 -> V_8 -> V_355 ,
V_359 ) ;
V_349 |= ( 1 << V_66 ) ;
V_348 |= ( 1 << ( V_66 + V_356 ) ) ;
V_350 [ F_177 ( V_66 ) ] |=
( ( V_357 + V_2 -> V_8 -> V_80 ) <<
F_178 ( V_66 ) ) ;
F_26 ( V_2 , V_350 [ 0 ] , V_360 ) ;
F_26 ( V_2 , V_350 [ 1 ] , V_361 ) ;
F_26 ( V_2 , V_350 [ 2 ] , V_362 ) ;
F_168 ( V_2 ) ;
F_26 ( V_2 , V_349 , V_363 ) ;
if ( V_347 )
V_348 |= V_352 ;
F_26 ( V_2 , V_348 , V_351 ) ;
}
static void F_179 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
struct V_170 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; ++ V_71 ) {
V_30 = & V_2 -> V_337 [ V_71 ] ;
F_180 ( V_2 -> V_23 , & V_30 -> V_201 , F_150 , 64 ) ;
}
V_30 = & V_2 -> V_337 [ V_66 ] ;
F_180 ( V_2 -> V_23 , & V_30 -> V_201 , F_150 , 64 ) ;
}
static void F_181 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
T_2 V_305 = V_171 ;
T_2 V_344 = 0 ;
struct V_170 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; ++ V_71 ) {
V_30 = & V_2 -> V_337 [ V_71 ] ;
F_171 ( & V_30 -> V_201 ) ;
V_344 |= ( 1 << ( V_174 + V_71 ) ) ;
}
V_30 = & V_2 -> V_337 [ V_66 ] ;
F_171 ( & V_30 -> V_201 ) ;
F_85 ( V_2 , V_305 , V_173 ) ;
F_88 ( V_2 , V_344 , V_173 ) ;
}
static void F_182 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
T_2 V_345 = V_171 ;
T_2 V_346 = 0xffff << V_174 ;
struct V_170 * V_30 ;
F_85 ( V_2 , V_345 , V_172 ) ;
F_88 ( V_2 , V_346 , V_172 ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; ++ V_71 ) {
V_30 = & V_2 -> V_337 [ V_71 ] ;
F_173 ( & V_30 -> V_201 ) ;
}
V_30 = & V_2 -> V_337 [ V_66 ] ;
F_173 ( & V_30 -> V_201 ) ;
}
static void F_183 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
struct V_170 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; ++ V_71 ) {
V_30 = & V_2 -> V_337 [ V_71 ] ;
F_175 ( & V_30 -> V_201 ) ;
}
V_30 = & V_2 -> V_337 [ V_66 ] ;
F_175 ( & V_30 -> V_201 ) ;
}
static int F_184 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_71 ;
T_2 V_347 ;
T_2 V_348 ;
T_2 V_349 ;
int V_60 ;
V_348 = F_27 ( V_2 , V_351 ) ;
V_347 = V_348 & V_352 ;
V_348 &= ~ V_352 ;
F_28 ( V_2 , V_348 , V_351 ) ;
V_348 = 0 ;
V_349 = 0 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; V_71 ++ ) {
V_60 = F_167 ( V_2 , V_71 ,
V_2 -> V_8 -> V_364 ,
V_71 * V_2 -> V_8 -> V_364 ,
( V_71 + 1 ) *
V_2 -> V_8 -> V_364 ) ;
if ( V_60 )
return V_60 ;
V_349 |= ( 1 << V_71 ) ;
V_348 |= ( 1 << ( V_71 + V_356 ) ) ;
}
V_60 = F_167 ( V_2 , V_66 , V_365 ,
V_2 -> V_8 -> V_81 *
V_2 -> V_8 -> V_364 ,
V_359 ) ;
if ( V_60 )
return V_60 ;
V_349 |= ( 1 << V_66 ) ;
V_348 |= ( 1 << ( V_66 + V_356 ) ) ;
F_179 ( V_2 ) ;
F_28 ( V_2 , V_349 , V_363 ) ;
if ( V_347 )
V_348 |= V_352 ;
F_28 ( V_2 , V_348 , V_351 ) ;
return 0 ;
}
static int F_185 ( struct V_1 * V_2 )
{
int V_60 = 0 ;
int V_302 = 0 ;
T_2 V_72 ;
T_2 V_348 ;
int V_71 ;
V_72 = F_25 ( V_2 , V_351 ) ;
V_72 &= ~ V_352 ;
F_26 ( V_2 , V_72 , V_351 ) ;
while ( V_302 ++ < V_366 ) {
V_72 = F_25 ( V_2 , V_367 ) ;
if ( V_72 & V_368 )
break;
F_157 ( 1 ) ;
}
if ( V_302 == V_366 ) {
F_186 ( V_2 -> V_23 , L_19 ) ;
V_60 = - V_304 ;
}
F_155 ( 10000 , 20000 ) ;
V_72 = F_27 ( V_2 , V_351 ) ;
V_72 &= ~ V_352 ;
F_28 ( V_2 , V_72 , V_351 ) ;
V_302 = 0 ;
while ( V_302 ++ < V_366 ) {
V_72 = F_27 ( V_2 , V_367 ) ;
if ( V_72 & V_368 )
break;
F_157 ( 1 ) ;
}
if ( V_302 == V_366 ) {
F_186 ( V_2 -> V_23 , L_20 ) ;
V_60 = - V_304 ;
}
V_348 = 0 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; V_71 ++ )
V_348 |= ( 1 << ( V_71 + V_356 ) ) ;
V_72 = F_27 ( V_2 , V_351 ) ;
V_72 &= ~ V_348 ;
F_28 ( V_2 , V_72 , V_351 ) ;
V_348 = 0 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; V_71 ++ )
V_348 |= ( 1 << ( V_71 + V_356 ) ) ;
V_72 = F_25 ( V_2 , V_351 ) ;
V_72 &= ~ V_348 ;
F_26 ( V_2 , V_72 , V_351 ) ;
return V_60 ;
}
static void F_187 ( struct V_1 * V_2 )
{
int V_71 ;
struct V_204 * V_205 ;
F_183 ( V_2 ) ;
F_174 ( V_2 ) ;
F_185 ( V_2 ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_369 ; V_71 ++ ) {
if ( V_2 -> V_189 [ V_71 ] . V_168 != NULL ) {
F_119 ( V_2 -> V_189 [ V_71 ] . V_168 ) ;
V_2 -> V_189 [ V_71 ] . V_168 = NULL ;
}
}
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; V_71 ++ ) {
V_205 = F_103 ( V_2 -> V_23 , V_2 -> V_208 [ V_71 ] . V_197 ) ;
F_188 ( V_205 ) ;
}
V_205 = F_103 ( V_2 -> V_23 , V_2 -> V_208 [ V_66 ] . V_197 ) ;
F_188 ( V_205 ) ;
F_153 ( V_2 ) ;
F_189 ( V_2 -> V_278 ) ;
F_189 ( V_2 -> V_189 ) ;
}
static int F_190 ( struct V_1 * V_2 )
{
int V_60 ;
unsigned int V_71 ;
struct V_160 * V_167 ;
F_95 ( V_2 , V_139 , V_2 -> V_23 , L_15 , V_188 ) ;
V_2 -> V_370 = V_2 -> V_17 + V_2 -> V_8 -> V_371 ;
V_2 -> V_300 = V_359 ;
V_2 -> V_278 = F_191 ( V_2 -> V_300 , sizeof( struct V_160 ) ,
V_372 ) ;
if ( ! V_2 -> V_278 )
return - V_299 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_300 ; V_71 ++ ) {
V_167 = V_2 -> V_278 + V_71 ;
V_167 -> V_224 = V_2 -> V_370 + V_71 * V_373 ;
}
V_2 -> V_374 = V_2 -> V_17 + V_2 -> V_8 -> V_375 ;
V_2 -> V_369 = V_359 ;
V_2 -> V_189 = F_191 ( V_2 -> V_369 , sizeof( struct V_160 ) ,
V_372 ) ;
if ( ! V_2 -> V_189 ) {
F_189 ( V_2 -> V_278 ) ;
return - V_299 ;
}
for ( V_71 = 0 ; V_71 < V_2 -> V_369 ; V_71 ++ ) {
V_167 = V_2 -> V_189 + V_71 ;
V_167 -> V_224 = V_2 -> V_374 + V_71 * V_373 ;
}
F_28 ( V_2 , V_376 , V_377 ) ;
V_60 = F_184 ( V_2 -> V_23 ) ;
if ( V_60 ) {
F_137 ( V_2 -> V_23 , L_21 ) ;
F_153 ( V_2 ) ;
F_189 ( V_2 -> V_278 ) ;
F_189 ( V_2 -> V_189 ) ;
return V_60 ;
}
F_26 ( V_2 , V_376 , V_377 ) ;
F_176 ( V_2 -> V_23 ) ;
return 0 ;
}
static void F_192 ( struct V_378 * V_379 )
{
unsigned long V_9 ;
unsigned int V_228 ;
struct V_1 * V_2 = F_108 (
V_379 , struct V_1 , V_380 ) ;
F_95 ( V_2 , V_381 , V_2 -> V_23 , L_15 , V_188 ) ;
F_105 ( & V_2 -> V_199 , V_9 ) ;
V_228 = V_2 -> V_382 ;
V_2 -> V_382 = 0 ;
F_106 ( & V_2 -> V_199 , V_9 ) ;
if ( V_228 & V_383 ) {
F_95 ( V_2 , V_384 , V_2 -> V_23 ,
L_22 ) ;
F_74 ( V_2 , V_143 ) ;
}
if ( V_228 & V_307 )
F_193 ( V_2 -> V_39 ,
! ! ( V_228 & V_385 ) ) ;
}
static T_9 F_194 ( int V_386 , void * V_387 )
{
struct V_1 * V_2 = V_387 ;
struct V_170 * V_388 ;
struct V_161 * V_389 ;
unsigned int V_175 , V_228 ;
V_228 = F_195 ( V_2 , V_390 ) &
~ F_195 ( V_2 , V_391 ) ;
F_88 ( V_2 , V_228 , V_184 ) ;
F_95 ( V_2 , V_381 , V_2 -> V_23 ,
L_23 , V_188 , V_228 ) ;
for ( V_175 = 0 ; V_175 < V_2 -> V_8 -> V_81 ; V_175 ++ ) {
if ( ! ( V_228 & F_163 ( V_174 + V_175 ) ) )
continue;
V_388 = & V_2 -> V_337 [ V_175 ] ;
if ( F_101 ( F_196 ( & V_388 -> V_201 ) ) ) {
V_388 -> V_328 ( V_388 ) ;
F_197 ( & V_388 -> V_201 ) ;
}
}
for ( V_175 = 0 ; V_175 < V_2 -> V_8 -> V_80 ; V_175 ++ ) {
if ( ! ( V_228 & F_163 ( V_175 ) ) )
continue;
V_389 = & V_2 -> V_208 [ V_175 ] ;
if ( F_101 ( F_196 ( & V_389 -> V_201 ) ) ) {
V_389 -> V_328 ( V_389 ) ;
F_197 ( & V_389 -> V_201 ) ;
}
}
return V_392 ;
}
static T_9 F_198 ( int V_386 , void * V_387 )
{
struct V_1 * V_2 = V_387 ;
struct V_170 * V_388 ;
struct V_161 * V_389 ;
unsigned int V_228 ;
unsigned long V_9 ;
V_228 = F_199 ( V_2 , V_390 ) &
~ F_199 ( V_2 , V_391 ) ;
F_85 ( V_2 , V_228 , V_184 ) ;
F_95 ( V_2 , V_381 , V_2 -> V_23 ,
L_24 , V_228 ) ;
if ( V_228 & V_171 ) {
V_388 = & V_2 -> V_337 [ V_66 ] ;
if ( F_101 ( F_196 ( & V_388 -> V_201 ) ) ) {
V_388 -> V_328 ( V_388 ) ;
F_197 ( & V_388 -> V_201 ) ;
}
}
if ( V_228 & V_176 ) {
V_389 = & V_2 -> V_208 [ V_66 ] ;
if ( F_101 ( F_196 ( & V_389 -> V_201 ) ) ) {
V_389 -> V_328 ( V_389 ) ;
F_197 ( & V_389 -> V_201 ) ;
}
}
if ( V_2 -> V_382 & ( V_393 |
V_394 |
V_307 |
V_395 |
V_396 ) ) {
F_200 ( & V_2 -> V_380 ) ;
}
if ( ( V_2 -> V_8 -> V_9 & V_322 ) &&
V_228 & ( V_323 | V_324 ) ) {
F_201 ( & V_2 -> V_397 ) ;
}
V_228 &= ( V_307 |
V_383 ) ;
if ( V_228 ) {
F_105 ( & V_2 -> V_199 , V_9 ) ;
V_2 -> V_382 |= V_228 ;
F_106 ( & V_2 -> V_199 , V_9 ) ;
F_200 ( & V_2 -> V_380 ) ;
}
return V_392 ;
}
static T_9 F_202 ( int V_386 , void * V_387 )
{
struct V_1 * V_2 = V_387 ;
F_203 ( & V_2 -> V_178 -> V_23 , 0 ) ;
return V_392 ;
}
static void F_204 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_205 ( V_2 -> V_398 ) ;
F_198 ( V_2 -> V_398 , V_2 ) ;
F_206 ( V_2 -> V_398 ) ;
F_205 ( V_2 -> V_399 ) ;
F_194 ( V_2 -> V_399 , V_2 ) ;
F_206 ( V_2 -> V_399 ) ;
}
static void F_207 ( struct V_1 * V_2 )
{
T_2 V_72 ;
V_72 = F_11 ( V_2 ) ;
V_72 |= F_163 ( 1 ) ;
F_15 ( V_2 , V_72 ) ;
F_157 ( 10 ) ;
V_72 &= ~ F_163 ( 1 ) ;
F_15 ( V_2 , V_72 ) ;
F_157 ( 10 ) ;
}
static void F_208 ( struct V_1 * V_2 ,
unsigned char * V_6 )
{
F_57 ( V_2 , ( V_6 [ 0 ] << 24 ) | ( V_6 [ 1 ] << 16 ) |
( V_6 [ 2 ] << 8 ) | V_6 [ 3 ] , V_400 ) ;
F_57 ( V_2 , ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] , V_401 ) ;
}
static T_2 F_209 ( struct V_1 * V_2 )
{
T_2 V_72 ;
T_2 V_348 ;
V_348 = 1 << ( V_66 + V_356 ) | V_352 ;
V_72 = F_25 ( V_2 , V_351 ) ;
V_72 &= ~ V_348 ;
F_26 ( V_2 , V_72 , V_351 ) ;
V_72 = F_27 ( V_2 , V_351 ) ;
V_72 &= ~ V_348 ;
F_28 ( V_2 , V_72 , V_351 ) ;
F_57 ( V_2 , 1 , V_402 ) ;
F_157 ( 10 ) ;
F_57 ( V_2 , 0 , V_402 ) ;
return V_348 ;
}
static void F_210 ( struct V_1 * V_2 , T_2 V_348 )
{
T_2 V_72 ;
V_72 = F_27 ( V_2 , V_351 ) ;
V_72 |= V_348 ;
F_28 ( V_2 , V_72 , V_351 ) ;
V_72 = F_25 ( V_2 , V_351 ) ;
V_72 |= V_348 ;
F_26 ( V_2 , V_72 , V_351 ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
T_2 V_71 ;
F_212 ( V_2 , 0x0 , V_403 ) ;
F_212 ( V_2 , 0x0 , V_404 ) ;
F_212 ( V_2 , 0x0 , V_404 + 4 ) ;
for ( V_71 = V_405 ; V_71 <= V_406 ; V_71 ++ )
F_28 ( V_2 , 0x0 , V_71 ) ;
for ( V_71 = 0 ; V_71 < ( V_2 -> V_8 -> V_407 / 4 ) ; V_71 ++ )
F_212 ( V_2 , 0x0 ,
V_408 + V_71 * sizeof( T_2 ) ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_407 *
V_2 -> V_8 -> V_409 ; V_71 ++ )
F_213 ( V_2 , 0x0 , V_71 * sizeof( T_2 ) ) ;
}
static void F_214 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) || F_55 ( V_2 ) )
return;
F_211 ( V_2 ) ;
}
static void F_215 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_181 ( V_2 ) ;
F_170 ( V_2 ) ;
F_154 ( V_2 , V_410 | V_411 , true ) ;
F_216 ( V_23 ) ;
F_160 ( V_2 ) ;
F_217 ( V_2 -> V_39 ) ;
}
static int F_218 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned long V_348 ;
T_2 V_72 ;
int V_60 ;
F_95 ( V_2 , V_412 , V_23 , L_25 ) ;
F_34 ( V_2 -> V_35 ) ;
if ( V_2 -> V_306 )
F_74 ( V_2 , V_144 ) ;
F_207 ( V_2 ) ;
V_60 = F_161 ( V_2 ) ;
if ( V_60 )
goto V_413;
F_154 ( V_2 , V_410 | V_411 , false ) ;
V_72 = F_56 ( V_2 , V_301 ) ;
V_2 -> V_48 = ! ! ( V_72 & V_414 ) ;
F_208 ( V_2 , V_23 -> V_415 ) ;
if ( V_2 -> V_306 ) {
V_72 = F_70 ( V_2 , V_146 ) ;
V_72 |= V_416 ;
F_72 ( V_2 , V_72 , V_146 ) ;
}
V_348 = F_209 ( V_2 ) ;
V_60 = F_190 ( V_2 ) ;
if ( V_60 ) {
F_137 ( V_23 , L_26 ) ;
goto V_413;
}
F_210 ( V_2 , V_348 ) ;
F_214 ( V_2 ) ;
V_60 = F_219 ( V_2 -> V_398 , F_198 , V_417 ,
V_23 -> V_418 , V_2 ) ;
if ( V_60 < 0 ) {
F_137 ( V_23 , L_27 , V_2 -> V_398 ) ;
goto V_419;
}
V_60 = F_219 ( V_2 -> V_399 , F_194 , V_417 ,
V_23 -> V_418 , V_2 ) ;
if ( V_60 < 0 ) {
F_137 ( V_23 , L_27 , V_2 -> V_399 ) ;
goto V_420;
}
V_60 = F_220 ( V_23 ) ;
if ( V_60 ) {
F_137 ( V_23 , L_28 ) ;
goto V_421;
}
F_215 ( V_23 ) ;
return 0 ;
V_421:
F_221 ( V_2 -> V_399 , V_2 ) ;
V_420:
F_221 ( V_2 -> V_398 , V_2 ) ;
V_419:
F_187 ( V_2 ) ;
V_413:
if ( V_2 -> V_306 )
F_67 ( V_2 , V_144 ) ;
F_36 ( V_2 -> V_35 ) ;
return V_60 ;
}
static void F_222 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_223 ( V_23 ) ;
F_224 ( V_2 -> V_39 ) ;
F_159 ( V_2 ) ;
F_182 ( V_2 ) ;
F_172 ( V_2 ) ;
F_225 ( & V_2 -> V_380 ) ;
V_2 -> V_422 = - 1 ;
V_2 -> V_423 = - 1 ;
V_2 -> V_424 = - 1 ;
V_2 -> V_425 = - 1 ;
}
static int F_226 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_60 ;
F_95 ( V_2 , V_426 , V_23 , L_29 ) ;
F_222 ( V_23 ) ;
F_227 ( V_2 -> V_39 ) ;
F_154 ( V_2 , V_411 , false ) ;
V_60 = F_185 ( V_2 ) ;
if ( V_60 )
return V_60 ;
F_154 ( V_2 , V_410 , false ) ;
F_111 ( V_23 ) ;
F_187 ( V_2 ) ;
F_221 ( V_2 -> V_398 , V_2 ) ;
F_221 ( V_2 -> V_399 , V_2 ) ;
if ( V_2 -> V_306 )
V_60 = F_67 ( V_2 , V_144 ) ;
F_36 ( V_2 -> V_35 ) ;
return V_60 ;
}
static void F_228 ( struct V_161 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_2 V_268 , V_181 , V_427 , V_428 ;
struct V_204 * V_205 ;
unsigned int V_194 ;
unsigned long V_9 ;
bool V_429 ;
if ( ! F_229 ( V_2 ) )
return;
V_205 = F_103 ( V_2 -> V_23 , V_30 -> V_197 ) ;
F_105 ( & V_30 -> V_199 , V_9 ) ;
if ( V_30 -> V_175 == V_66 ) {
V_427 = ~ F_199 ( V_2 , V_391 ) ;
V_428 = V_176 | V_430 ;
} else {
V_427 = ~ F_195 ( V_2 , V_391 ) ;
V_428 = 1 << V_30 -> V_175 ;
}
V_181 = F_29 ( V_2 , V_30 -> V_175 , V_185 ) ;
V_268 = F_29 ( V_2 , V_30 -> V_175 , V_256 ) ;
V_429 = F_135 ( V_205 ) ;
V_194 = V_30 -> V_194 ;
F_106 ( & V_30 -> V_199 , V_9 ) ;
F_65 ( V_2 , V_216 , V_2 -> V_23 , L_30
L_31
L_32
L_33
L_34
L_35
L_36 ,
V_30 -> V_175 , V_30 -> V_197 ,
V_429 ? L_37 : L_38 ,
V_427 & V_428 ? L_39 : L_40 ,
V_194 , V_30 -> V_298 ,
V_30 -> V_253 , V_268 & V_254 ,
V_30 -> V_181 , V_181 & V_186 ,
V_30 -> V_190 , V_30 -> V_164 ,
V_30 -> V_165 , V_30 -> V_166 ) ;
}
static void F_230 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_305 = 0 ;
T_2 V_344 = 0 ;
unsigned int V_431 ;
F_95 ( V_2 , V_216 , V_23 , L_41 ) ;
for ( V_431 = 0 ; V_431 < V_2 -> V_8 -> V_80 ; V_431 ++ )
F_228 ( & V_2 -> V_208 [ V_431 ] ) ;
F_228 ( & V_2 -> V_208 [ V_66 ] ) ;
F_111 ( V_23 ) ;
for ( V_431 = 0 ; V_431 < V_2 -> V_8 -> V_80 ; V_431 ++ )
V_344 |= ( 1 << V_431 ) ;
V_305 = V_176 ;
F_85 ( V_2 , V_305 , V_173 ) ;
F_88 ( V_2 , V_344 , V_173 ) ;
F_231 ( V_23 ) ;
V_23 -> V_119 . V_432 ++ ;
F_232 ( V_23 ) ;
}
static inline void F_233 ( struct V_1 * V_2 ,
unsigned char * V_6 ,
int * V_71 ,
int * V_433 )
{
T_2 V_72 ;
F_57 ( V_2 , V_6 [ 0 ] << 8 | V_6 [ 1 ] ,
V_434 + ( * V_71 * 4 ) ) ;
F_57 ( V_2 , V_6 [ 2 ] << 24 | V_6 [ 3 ] << 16 |
V_6 [ 4 ] << 8 | V_6 [ 5 ] ,
V_434 + ( ( * V_71 + 1 ) * 4 ) ) ;
V_72 = F_56 ( V_2 , V_435 ) ;
V_72 |= ( 1 << ( V_436 - * V_433 ) ) ;
F_57 ( V_2 , V_72 , V_435 ) ;
* V_71 += 2 ;
( * V_433 ) ++ ;
}
static void F_234 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_437 * V_438 ;
int V_71 , V_433 ;
T_2 V_72 ;
F_95 ( V_2 , V_139 , V_23 , L_42 , V_188 , V_23 -> V_9 ) ;
V_72 = F_56 ( V_2 , V_301 ) ;
if ( V_23 -> V_9 & V_439 ) {
V_72 |= V_440 ;
F_57 ( V_2 , V_72 , V_301 ) ;
F_57 ( V_2 , 0 , V_435 ) ;
return;
} else {
V_72 &= ~ V_440 ;
F_57 ( V_2 , V_72 , V_301 ) ;
}
if ( V_23 -> V_9 & V_441 ) {
F_186 ( V_23 , L_43 ) ;
return;
}
V_71 = 0 ;
V_433 = 0 ;
F_233 ( V_2 , V_23 -> V_442 , & V_71 , & V_433 ) ;
F_233 ( V_2 , V_23 -> V_415 , & V_71 , & V_433 ) ;
if ( F_235 ( V_23 ) > ( V_436 - V_433 ) )
return;
if ( ! F_236 ( V_23 ) )
F_237 (ha, dev)
F_233 ( V_2 , V_438 -> V_6 , & V_71 , & V_433 ) ;
if ( F_238 ( V_23 ) || F_239 ( V_23 ) >= ( V_436 - V_433 ) )
return;
F_240 (ha, dev)
F_233 ( V_2 , V_438 -> V_6 , & V_71 , & V_433 ) ;
}
static int F_241 ( struct V_34 * V_23 , void * V_106 )
{
struct V_443 * V_6 = V_106 ;
if ( F_38 ( V_23 ) )
return - V_444 ;
F_242 ( V_23 -> V_415 , V_6 -> V_445 ) ;
return 0 ;
}
static struct V_446 * F_243 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned long V_447 = 0 , V_448 = 0 ;
unsigned long V_449 = 0 , V_450 = 0 ;
unsigned long V_291 = 0 , V_451 = 0 ;
struct V_161 * V_389 ;
struct V_170 * V_388 ;
unsigned int V_431 ;
for ( V_431 = 0 ; V_431 < V_2 -> V_8 -> V_80 ; V_431 ++ ) {
V_389 = & V_2 -> V_208 [ V_431 ] ;
V_447 += V_389 -> V_196 ;
V_448 += V_389 -> V_195 ;
}
V_389 = & V_2 -> V_208 [ V_66 ] ;
V_447 += V_389 -> V_196 ;
V_448 += V_389 -> V_195 ;
for ( V_431 = 0 ; V_431 < V_2 -> V_8 -> V_81 ; V_431 ++ ) {
V_388 = & V_2 -> V_337 [ V_431 ] ;
V_449 += V_388 -> V_196 ;
V_450 += V_388 -> V_195 ;
V_291 += V_388 -> V_276 ;
V_451 += V_388 -> V_280 ;
}
V_388 = & V_2 -> V_337 [ V_66 ] ;
V_449 += V_388 -> V_196 ;
V_450 += V_388 -> V_195 ;
V_291 += V_388 -> V_276 ;
V_451 += V_388 -> V_280 ;
V_23 -> V_119 . V_447 = V_447 ;
V_23 -> V_119 . V_448 = V_448 ;
V_23 -> V_119 . V_449 = V_449 ;
V_23 -> V_119 . V_450 = V_450 ;
V_23 -> V_119 . V_291 = V_291 ;
V_23 -> V_119 . V_452 = V_291 ;
return & V_23 -> V_119 ;
}
static void F_244 ( struct V_1 * V_2 )
{
struct V_453 * V_454 ;
T_2 V_72 ;
T_5 V_455 ;
T_6 V_456 ;
if ( F_71 ( V_2 ) || F_245 ( V_2 ) ) {
V_28 = V_457 ;
V_33 = V_458 ;
V_2 -> V_292 = V_459 ;
} else if ( F_246 ( V_2 ) ) {
V_28 = V_457 ;
V_33 = V_460 ;
V_2 -> V_292 = V_459 ;
} else if ( F_55 ( V_2 ) ) {
V_28 = V_461 ;
V_33 = V_460 ;
V_2 -> V_292 = V_462 ;
} else if ( F_12 ( V_2 ) ) {
V_28 = V_463 ;
V_33 = V_460 ;
V_2 -> V_292 = V_462 ;
}
V_2 -> V_8 = & V_453 [ V_2 -> V_86 ] ;
V_454 = V_2 -> V_8 ;
V_72 = F_14 ( V_2 , V_464 ) ;
V_455 = ( V_72 >> 24 & 0x0f ) ;
if ( V_455 == 6 )
V_455 = 5 ;
else if ( V_455 == 5 )
V_455 = 4 ;
else if ( V_455 == 0 )
V_455 = 1 ;
if ( V_455 != V_2 -> V_86 ) {
F_158 ( & V_2 -> V_178 -> V_23 ,
L_44 ,
V_455 , V_2 -> V_86 ) ;
}
F_247 ( & V_2 -> V_178 -> V_23 , L_45 V_465 ,
V_455 , ( V_72 >> 16 ) & 0x0f , V_72 & 0xffff ) ;
V_456 = V_72 & 0xffff ;
if ( F_71 ( V_2 ) ) {
if ( V_456 != 0 ) {
F_248 ( L_46 ,
V_456 ) ;
}
} else if ( V_456 == 0 || V_456 == 0x01ff ) {
F_248 ( L_47 , V_456 ) ;
return;
} else if ( ( V_456 & 0xf0 ) != 0 ) {
V_2 -> V_456 = V_456 << 8 ;
} else if ( ( V_456 & 0xff00 ) != 0 ) {
V_2 -> V_456 = V_456 ;
}
#ifdef F_7
if ( ! ( V_454 -> V_9 & V_10 ) )
F_248 ( L_48 ) ;
#endif
F_249 ( L_49
L_50
L_51
L_52
L_53
L_54
L_55 ,
V_2 -> V_86 ,
V_454 -> V_80 , V_454 -> V_355 ,
V_454 -> V_81 , V_454 -> V_364 ,
V_454 -> V_320 , V_454 -> V_321 ,
V_454 -> V_407 , V_454 -> V_218 ,
V_454 -> V_18 , V_454 -> V_466 ,
V_454 -> V_467 ,
V_454 -> V_371 , V_454 -> V_375 ,
V_454 -> V_326 ) ;
}
static int F_250 ( struct V_468 * V_178 )
{
struct V_469 * V_470 = V_178 -> V_23 . V_471 ;
struct V_472 * V_473 = V_178 -> V_23 . V_474 ;
const struct V_475 * V_476 = NULL ;
struct V_1 * V_2 ;
struct V_34 * V_23 ;
const void * V_477 ;
struct V_478 * V_25 ;
int V_479 = - V_480 ;
const char * V_481 ;
V_23 = F_251 ( sizeof( * V_2 ) , V_482 + 1 ,
V_482 + 1 ) ;
if ( ! V_23 ) {
F_158 ( & V_178 -> V_23 , L_56 ) ;
return - V_299 ;
}
if ( V_473 ) {
V_476 = F_252 ( V_483 , V_473 ) ;
if ( ! V_476 )
return - V_38 ;
}
V_2 = F_23 ( V_23 ) ;
V_2 -> V_398 = F_253 ( V_178 , 0 ) ;
V_2 -> V_399 = F_253 ( V_178 , 1 ) ;
V_2 -> V_484 = F_253 ( V_178 , 2 ) ;
if ( ! V_2 -> V_398 || ! V_2 -> V_399 ) {
F_158 ( & V_178 -> V_23 , L_57 ) ;
V_479 = - V_38 ;
goto V_479;
}
if ( V_473 ) {
V_477 = F_254 ( V_473 ) ;
if ( ! V_477 ) {
F_158 ( & V_178 -> V_23 , L_58 ) ;
V_479 = - V_38 ;
goto V_479;
}
} else {
V_477 = V_470 -> V_485 ;
}
V_25 = F_255 ( V_178 , V_486 , 0 ) ;
V_2 -> V_17 = F_256 ( & V_178 -> V_23 , V_25 ) ;
if ( F_257 ( V_2 -> V_17 ) ) {
V_479 = F_258 ( V_2 -> V_17 ) ;
goto V_479;
}
F_166 ( & V_2 -> V_199 ) ;
F_259 ( V_23 , & V_178 -> V_23 ) ;
F_260 ( & V_178 -> V_23 , V_23 ) ;
F_242 ( V_23 -> V_415 , V_477 ) ;
V_23 -> V_487 = 2 * V_488 ;
V_23 -> V_489 = & V_490 ;
V_23 -> V_491 = & V_492 ;
V_2 -> V_61 = F_261 ( - 1 , V_493 ) ;
V_23 -> V_494 |= V_495 | V_54 |
V_55 | V_44 ;
V_2 -> V_496 = true ;
V_479 = F_262 ( & V_178 -> V_23 , V_2 -> V_484 , F_202 , 0 ,
V_23 -> V_418 , V_2 ) ;
if ( ! V_479 )
F_263 ( & V_178 -> V_23 , 1 ) ;
V_23 -> V_497 += 64 ;
F_264 ( V_23 ) ;
V_2 -> V_23 = V_23 ;
V_2 -> V_178 = V_178 ;
if ( V_476 )
V_2 -> V_86 = (enum V_498 ) V_476 -> V_91 ;
else
V_2 -> V_86 = V_470 -> V_499 ;
V_2 -> V_35 = F_265 ( & V_2 -> V_178 -> V_23 , L_59 ) ;
if ( F_257 ( V_2 -> V_35 ) ) {
F_266 ( & V_2 -> V_178 -> V_23 , L_60 ) ;
V_2 -> V_35 = NULL ;
}
F_34 ( V_2 -> V_35 ) ;
F_244 ( V_2 ) ;
F_267 ( & V_2 -> V_397 ) ;
V_2 -> V_258 = V_331 ;
F_268 ( & V_2 -> V_380 , F_192 ) ;
V_2 -> V_500 = F_265 ( & V_2 -> V_178 -> V_23 , L_61 ) ;
if ( F_257 ( V_2 -> V_500 ) ) {
F_266 ( & V_2 -> V_178 -> V_23 , L_62 ) ;
V_2 -> V_500 = NULL ;
}
V_2 -> V_124 = F_265 ( & V_2 -> V_178 -> V_23 , L_63 ) ;
if ( F_257 ( V_2 -> V_124 ) ) {
F_266 ( & V_2 -> V_178 -> V_23 , L_64 ) ;
V_2 -> V_124 = NULL ;
}
if ( V_473 && ! F_269 ( V_473 , L_65 , & V_481 ) &&
! strcasecmp ( V_481 , L_66 ) )
F_74 ( V_2 , V_144 ) ;
V_479 = F_156 ( V_2 ) ;
if ( V_479 )
goto V_413;
V_479 = F_270 ( V_23 ) ;
if ( V_479 )
goto V_413;
F_271 ( V_2 -> V_23 , V_2 -> V_8 -> V_80 + 1 ) ;
F_272 ( V_2 -> V_23 , V_2 -> V_8 -> V_81 + 1 ) ;
F_273 ( V_23 ) ;
F_36 ( V_2 -> V_35 ) ;
V_479 = F_274 ( V_23 ) ;
if ( V_479 )
goto V_479;
return V_479 ;
V_413:
F_36 ( V_2 -> V_35 ) ;
V_479:
F_275 ( V_23 ) ;
return V_479 ;
}
static int F_276 ( struct V_468 * V_178 )
{
struct V_1 * V_2 = F_22 ( & V_178 -> V_23 ) ;
F_260 ( & V_178 -> V_23 , NULL ) ;
F_277 ( V_2 -> V_23 ) ;
F_278 ( V_2 -> V_23 ) ;
F_275 ( V_2 -> V_23 ) ;
return 0 ;
}
static int F_279 ( struct V_22 * V_3 )
{
struct V_34 * V_23 = F_24 ( V_3 ) ;
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_60 ;
if ( ! F_38 ( V_23 ) )
return 0 ;
F_222 ( V_23 ) ;
if ( ! F_280 ( V_3 ) )
F_281 ( V_2 -> V_39 ) ;
F_282 ( V_23 ) ;
F_154 ( V_2 , V_411 , false ) ;
V_60 = F_185 ( V_2 ) ;
if ( V_60 )
return V_60 ;
F_154 ( V_2 , V_410 , false ) ;
F_111 ( V_23 ) ;
F_187 ( V_2 ) ;
if ( F_280 ( V_3 ) && V_2 -> V_501 ) {
V_60 = F_67 ( V_2 , V_143 ) ;
F_34 ( V_2 -> V_500 ) ;
} else if ( V_2 -> V_306 ) {
V_60 = F_67 ( V_2 , V_144 ) ;
}
F_36 ( V_2 -> V_35 ) ;
return V_60 ;
}
static int F_283 ( struct V_22 * V_3 )
{
struct V_34 * V_23 = F_24 ( V_3 ) ;
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned long V_348 ;
int V_60 ;
T_2 V_72 ;
if ( ! F_38 ( V_23 ) )
return 0 ;
V_60 = F_34 ( V_2 -> V_35 ) ;
if ( V_60 )
return V_60 ;
if ( V_2 -> V_306 )
F_74 ( V_2 , V_144 ) ;
F_207 ( V_2 ) ;
V_60 = F_161 ( V_2 ) ;
if ( V_60 )
goto V_502;
if ( V_2 -> V_501 )
F_36 ( V_2 -> V_500 ) ;
F_284 ( V_2 -> V_39 ) ;
F_285 ( V_2 -> V_23 ) ;
F_154 ( V_2 , V_410 | V_411 , false ) ;
F_208 ( V_2 , V_23 -> V_415 ) ;
if ( V_2 -> V_306 ) {
V_72 = F_70 ( V_2 , V_146 ) ;
V_72 |= V_416 ;
F_72 ( V_2 , V_72 , V_146 ) ;
}
if ( V_2 -> V_501 )
F_74 ( V_2 , V_143 ) ;
V_348 = F_209 ( V_2 ) ;
V_60 = F_190 ( V_2 ) ;
if ( V_60 ) {
F_137 ( V_23 , L_26 ) ;
goto V_502;
}
F_210 ( V_2 , V_348 ) ;
F_286 ( V_23 ) ;
if ( ! F_280 ( V_3 ) )
F_287 ( V_2 -> V_39 ) ;
if ( V_2 -> V_132 . V_133 )
F_60 ( V_23 , true ) ;
F_215 ( V_23 ) ;
return 0 ;
V_502:
if ( V_2 -> V_306 )
F_67 ( V_2 , V_144 ) ;
F_36 ( V_2 -> V_35 ) ;
return V_60 ;
}
