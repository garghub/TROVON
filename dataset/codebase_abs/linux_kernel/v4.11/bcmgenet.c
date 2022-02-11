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
V_72 |= ( V_147 |
V_148 | V_149 ) ;
F_71 ( V_2 , V_72 , V_146 ) ;
F_72 ( V_2 -> V_23 , false ) ;
}
break;
default:
break;
}
return 0 ;
}
static void F_73 ( struct V_1 * V_2 ,
enum V_140 V_141 )
{
T_2 V_72 ;
if ( ! ( V_2 -> V_8 -> V_9 & V_145 ) )
return;
V_72 = F_70 ( V_2 , V_146 ) ;
switch ( V_141 ) {
case V_144 :
V_72 &= ~ ( V_148 | V_147 |
V_149 ) ;
case V_142 :
V_72 |= V_150 ;
break;
case V_143 :
F_74 ( V_2 , V_141 ) ;
return;
default:
break;
}
F_71 ( V_2 , V_72 , V_146 ) ;
if ( V_141 == V_144 ) {
F_72 ( V_2 -> V_23 , true ) ;
F_75 ( V_2 -> V_23 ) ;
}
}
static int F_76 ( struct V_34 * V_23 , struct V_151 * V_152 , int V_37 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_12 = 0 ;
if ( ! F_38 ( V_23 ) )
return - V_38 ;
switch ( V_37 ) {
case V_153 :
case V_154 :
case V_155 :
if ( ! V_2 -> V_39 )
V_12 = - V_40 ;
else
V_12 = F_77 ( V_2 -> V_39 , V_152 , V_37 ) ;
break;
default:
V_12 = - V_38 ;
break;
}
return V_12 ;
}
static struct V_156 * F_78 ( struct V_1 * V_2 ,
struct V_157 * V_30 )
{
struct V_156 * V_158 ;
V_158 = V_30 -> V_159 ;
V_158 += V_30 -> V_160 - V_30 -> V_161 ;
if ( V_30 -> V_160 == V_30 -> V_162 )
V_30 -> V_160 = V_30 -> V_161 ;
else
V_30 -> V_160 ++ ;
return V_158 ;
}
static void F_79 ( struct V_156 * V_163 )
{
F_80 ( V_163 -> V_164 ) ;
V_163 -> V_164 = NULL ;
F_81 ( V_163 , V_165 , 0 ) ;
}
static inline void F_82 ( struct V_166 * V_30 )
{
F_83 ( V_30 -> V_2 , V_167 ,
V_168 ) ;
}
static inline void F_84 ( struct V_166 * V_30 )
{
F_83 ( V_30 -> V_2 , V_167 ,
V_169 ) ;
}
static inline void F_85 ( struct V_166 * V_30 )
{
F_86 ( V_30 -> V_2 ,
1 << ( V_170 + V_30 -> V_171 ) ,
V_168 ) ;
}
static inline void F_87 ( struct V_166 * V_30 )
{
F_86 ( V_30 -> V_2 ,
1 << ( V_170 + V_30 -> V_171 ) ,
V_169 ) ;
}
static inline void F_88 ( struct V_157 * V_30 )
{
F_83 ( V_30 -> V_2 , V_172 ,
V_168 ) ;
}
static inline void F_89 ( struct V_157 * V_30 )
{
F_83 ( V_30 -> V_2 , V_172 ,
V_169 ) ;
}
static inline void F_90 ( struct V_157 * V_30 )
{
F_86 ( V_30 -> V_2 , 1 << V_30 -> V_171 ,
V_169 ) ;
}
static inline void F_91 ( struct V_157 * V_30 )
{
F_86 ( V_30 -> V_2 , 1 << V_30 -> V_171 ,
V_168 ) ;
}
static unsigned int F_92 ( struct V_34 * V_23 ,
struct V_157 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_22 * V_173 = & V_2 -> V_174 -> V_23 ;
struct V_156 * V_158 ;
unsigned int V_175 = 0 ;
unsigned int V_176 = 0 ;
unsigned int V_177 ;
unsigned int V_178 ;
unsigned int V_179 = 0 ;
V_177 = F_29 ( V_2 , V_30 -> V_171 , V_180 ) ;
V_177 &= V_181 ;
if ( F_93 ( V_177 >= V_30 -> V_177 ) )
V_178 = V_177 - V_30 -> V_177 ;
else
V_178 = ( V_181 + 1 ) - V_30 -> V_177 + V_177 ;
F_94 ( V_2 , V_182 , V_23 ,
L_4 ,
V_183 , V_30 -> V_171 , V_30 -> V_177 , V_177 , V_178 ) ;
while ( V_179 < V_178 ) {
V_158 = & V_2 -> V_184 [ V_30 -> V_185 ] ;
if ( V_158 -> V_164 ) {
V_175 ++ ;
V_176 += F_95 ( V_158 -> V_164 ) -> V_186 ;
F_96 ( V_173 ,
F_97 ( V_158 , V_165 ) ,
F_98 ( V_158 , V_187 ) ,
V_188 ) ;
F_79 ( V_158 ) ;
} else if ( F_97 ( V_158 , V_165 ) ) {
F_99 ( V_173 ,
F_97 ( V_158 , V_165 ) ,
F_98 ( V_158 , V_187 ) ,
V_188 ) ;
F_81 ( V_158 , V_165 , 0 ) ;
}
V_179 ++ ;
if ( F_93 ( V_30 -> V_185 < V_30 -> V_162 ) )
V_30 -> V_185 ++ ;
else
V_30 -> V_185 = V_30 -> V_161 ;
}
V_30 -> V_189 += V_179 ;
V_30 -> V_177 = ( V_30 -> V_177 + V_179 ) & V_181 ;
V_23 -> V_119 . V_190 += V_175 ;
V_23 -> V_119 . V_191 += V_176 ;
F_100 ( F_101 ( V_23 , V_30 -> V_192 ) ,
V_175 , V_176 ) ;
return V_175 ;
}
static unsigned int F_102 ( struct V_34 * V_23 ,
struct V_157 * V_30 )
{
unsigned int V_193 ;
unsigned long V_9 ;
F_103 ( & V_30 -> V_194 , V_9 ) ;
V_193 = F_92 ( V_23 , V_30 ) ;
F_104 ( & V_30 -> V_194 , V_9 ) ;
return V_193 ;
}
static int F_105 ( struct V_195 * V_196 , int V_197 )
{
struct V_157 * V_30 =
F_106 ( V_196 , struct V_157 , V_196 ) ;
unsigned int V_198 = 0 ;
struct V_199 * V_200 ;
unsigned long V_9 ;
F_103 ( & V_30 -> V_194 , V_9 ) ;
V_198 = F_92 ( V_30 -> V_2 -> V_23 , V_30 ) ;
if ( V_30 -> V_189 > ( V_201 + 1 ) ) {
V_200 = F_101 ( V_30 -> V_2 -> V_23 , V_30 -> V_192 ) ;
F_107 ( V_200 ) ;
}
F_104 ( & V_30 -> V_194 , V_9 ) ;
if ( V_198 == 0 ) {
F_108 ( V_196 ) ;
V_30 -> V_202 ( V_30 ) ;
return 0 ;
}
return V_197 ;
}
static void F_109 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_71 ;
if ( F_110 ( V_23 ) ) {
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; V_71 ++ )
F_102 ( V_23 , & V_2 -> V_203 [ V_71 ] ) ;
}
F_102 ( V_23 , & V_2 -> V_203 [ V_66 ] ) ;
}
static int F_111 ( struct V_34 * V_23 ,
struct V_204 * V_164 ,
T_6 V_205 ,
struct V_157 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_22 * V_173 = & V_2 -> V_174 -> V_23 ;
struct V_156 * V_158 ;
unsigned int V_206 ;
T_3 V_207 ;
T_2 V_208 ;
int V_60 ;
V_158 = F_78 ( V_2 , V_30 ) ;
if ( F_112 ( ! V_158 ) )
F_113 () ;
V_158 -> V_164 = V_164 ;
V_206 = F_114 ( V_164 ) ;
V_207 = F_115 ( V_173 , V_164 -> V_91 , V_206 , V_188 ) ;
V_60 = F_116 ( V_173 , V_207 ) ;
if ( V_60 ) {
V_2 -> V_209 . V_210 ++ ;
F_65 ( V_2 , V_211 , V_23 , L_5 ) ;
F_117 ( V_164 ) ;
return V_60 ;
}
F_81 ( V_158 , V_165 , V_207 ) ;
F_118 ( V_158 , V_187 , V_206 ) ;
V_208 = ( V_206 << V_212 ) | V_205 |
( V_2 -> V_8 -> V_213 << V_214 ) |
V_215 ;
if ( V_164 -> V_216 == V_217 )
V_208 |= V_218 ;
F_9 ( V_2 , V_158 -> V_219 , V_207 , V_208 ) ;
return 0 ;
}
static int F_119 ( struct V_34 * V_23 ,
T_7 * V_220 ,
T_6 V_205 ,
struct V_157 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_22 * V_173 = & V_2 -> V_174 -> V_23 ;
struct V_156 * V_158 ;
unsigned int V_221 ;
T_3 V_207 ;
int V_60 ;
V_158 = F_78 ( V_2 , V_30 ) ;
if ( F_112 ( ! V_158 ) )
F_113 () ;
V_158 -> V_164 = NULL ;
V_221 = F_120 ( V_220 ) ;
V_207 = F_121 ( V_173 , V_220 , 0 , V_221 , V_188 ) ;
V_60 = F_116 ( V_173 , V_207 ) ;
if ( V_60 ) {
V_2 -> V_209 . V_210 ++ ;
F_65 ( V_2 , V_211 , V_23 , L_6 ,
V_183 ) ;
return V_60 ;
}
F_81 ( V_158 , V_165 , V_207 ) ;
F_118 ( V_158 , V_187 , V_221 ) ;
F_9 ( V_2 , V_158 -> V_219 , V_207 ,
( V_221 << V_212 ) | V_205 |
( V_2 -> V_8 -> V_213 << V_214 ) ) ;
return 0 ;
}
static struct V_204 * F_122 ( struct V_34 * V_23 ,
struct V_204 * V_164 )
{
struct V_222 * V_223 = NULL ;
struct V_204 * V_224 ;
T_6 V_95 ;
T_5 V_225 ;
T_6 V_226 ;
T_2 V_227 ;
if ( F_112 ( F_123 ( V_164 ) < sizeof( * V_223 ) ) ) {
V_224 = F_124 ( V_164 , sizeof( * V_223 ) ) ;
F_117 ( V_164 ) ;
if ( ! V_224 ) {
V_23 -> V_119 . V_228 ++ ;
return NULL ;
}
V_164 = V_224 ;
}
F_125 ( V_164 , sizeof( * V_223 ) ) ;
V_223 = (struct V_222 * ) V_164 -> V_91 ;
if ( V_164 -> V_216 == V_217 ) {
V_226 = F_126 ( V_164 -> V_229 ) ;
switch ( V_226 ) {
case V_230 :
V_225 = F_127 ( V_164 ) -> V_229 ;
break;
case V_231 :
V_225 = F_128 ( V_164 ) -> V_232 ;
break;
default:
return V_164 ;
}
V_95 = F_129 ( V_164 ) - sizeof( * V_223 ) ;
V_227 = ( V_95 << V_233 ) |
( V_95 + V_164 -> V_234 ) ;
if ( V_225 == V_235 || V_225 == V_236 ) {
V_227 |= V_237 ;
if ( V_225 == V_236 && V_226 == V_230 )
V_227 |= V_238 ;
} else {
V_227 = 0 ;
}
V_223 -> V_227 = V_227 ;
}
return V_164 ;
}
static T_8 F_130 ( struct V_204 * V_164 , struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_157 * V_30 = NULL ;
struct V_199 * V_200 ;
unsigned long V_9 = 0 ;
int V_239 , V_171 ;
T_6 V_205 ;
int V_60 ;
int V_71 ;
V_171 = F_131 ( V_164 ) ;
if ( V_171 == 0 )
V_171 = V_66 ;
else
V_171 -= 1 ;
V_30 = & V_2 -> V_203 [ V_171 ] ;
V_200 = F_101 ( V_23 , V_30 -> V_192 ) ;
V_239 = F_132 ( V_164 ) -> V_239 ;
F_103 ( & V_30 -> V_194 , V_9 ) ;
if ( V_30 -> V_189 <= ( V_239 + 1 ) ) {
if ( ! F_133 ( V_200 ) ) {
F_134 ( V_200 ) ;
F_135 ( V_23 ,
L_7 ,
V_183 , V_171 , V_30 -> V_192 ) ;
}
V_60 = V_240 ;
goto V_241;
}
if ( F_136 ( V_164 , V_242 ) ) {
V_60 = V_243 ;
goto V_241;
}
F_95 ( V_164 ) -> V_186 = V_164 -> V_244 ;
if ( V_2 -> V_50 ) {
V_164 = F_122 ( V_23 , V_164 ) ;
if ( ! V_164 ) {
V_60 = V_243 ;
goto V_241;
}
}
V_205 = V_245 ;
if ( V_239 == 0 )
V_205 |= V_246 ;
V_60 = F_111 ( V_23 , V_164 , V_205 , V_30 ) ;
if ( V_60 ) {
V_60 = V_243 ;
goto V_241;
}
for ( V_71 = 0 ; V_71 < V_239 ; V_71 ++ ) {
V_60 = F_119 ( V_23 ,
& F_132 ( V_164 ) -> V_247 [ V_71 ] ,
( V_71 == V_239 - 1 ) ? V_246 : 0 ,
V_30 ) ;
if ( V_60 ) {
V_60 = V_243 ;
goto V_241;
}
}
F_137 ( V_164 ) ;
V_30 -> V_189 -= V_239 + 1 ;
V_30 -> V_248 += V_239 + 1 ;
V_30 -> V_248 &= V_249 ;
F_138 ( V_200 , F_95 ( V_164 ) -> V_186 ) ;
if ( V_30 -> V_189 <= ( V_201 + 1 ) )
F_134 ( V_200 ) ;
if ( ! V_164 -> V_250 || F_139 ( V_200 ) )
F_30 ( V_2 , V_30 -> V_171 ,
V_30 -> V_248 , V_251 ) ;
V_241:
F_104 ( & V_30 -> V_194 , V_9 ) ;
return V_60 ;
}
static struct V_204 * F_140 ( struct V_1 * V_2 ,
struct V_156 * V_163 )
{
struct V_22 * V_173 = & V_2 -> V_174 -> V_23 ;
struct V_204 * V_164 ;
struct V_204 * V_252 ;
T_3 V_207 ;
V_164 = F_141 ( V_2 -> V_23 , V_2 -> V_253 + V_254 ) ;
if ( ! V_164 ) {
V_2 -> V_209 . V_255 ++ ;
F_65 ( V_2 , V_256 , V_2 -> V_23 ,
L_8 , V_183 ) ;
return NULL ;
}
V_207 = F_115 ( V_173 , V_164 -> V_91 , V_2 -> V_253 ,
V_257 ) ;
if ( F_116 ( V_173 , V_207 ) ) {
V_2 -> V_209 . V_258 ++ ;
F_80 ( V_164 ) ;
F_65 ( V_2 , V_256 , V_2 -> V_23 ,
L_9 , V_183 ) ;
return NULL ;
}
V_252 = V_163 -> V_164 ;
if ( F_93 ( V_252 ) )
F_96 ( V_173 , F_97 ( V_163 , V_165 ) ,
V_2 -> V_253 , V_257 ) ;
V_163 -> V_164 = V_164 ;
F_81 ( V_163 , V_165 , V_207 ) ;
F_5 ( V_2 , V_163 -> V_219 , V_207 ) ;
return V_252 ;
}
static unsigned int F_142 ( struct V_166 * V_30 ,
unsigned int V_197 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_34 * V_23 = V_2 -> V_23 ;
struct V_156 * V_163 ;
struct V_204 * V_164 ;
T_2 V_259 ;
unsigned long V_260 ;
int V_244 ;
unsigned int V_261 = 0 , V_262 ;
unsigned int V_263 ;
unsigned int V_264 ;
unsigned int V_265 = 0 ;
V_263 = F_31 ( V_2 , V_30 -> V_171 , V_266 ) ;
V_264 = ( V_263 >> V_267 ) &
V_268 ;
if ( V_264 > V_30 -> V_269 ) {
V_264 = V_264 - V_30 -> V_269 ;
V_23 -> V_119 . V_270 += V_264 ;
V_23 -> V_119 . V_271 += V_264 ;
V_30 -> V_269 += V_264 ;
if ( V_30 -> V_269 >= 0xC000 ) {
V_30 -> V_269 = 0 ;
F_32 ( V_2 , V_30 -> V_171 , 0 ,
V_266 ) ;
}
}
V_263 &= V_249 ;
if ( F_93 ( V_263 >= V_30 -> V_177 ) )
V_262 = V_263 - V_30 -> V_177 ;
else
V_262 = ( V_181 + 1 ) - V_30 -> V_177 +
V_263 ;
F_94 ( V_2 , V_272 , V_23 ,
L_10 , V_262 ) ;
while ( ( V_261 < V_262 ) &&
( V_261 < V_197 ) ) {
V_163 = & V_2 -> V_273 [ V_30 -> V_274 ] ;
V_164 = F_140 ( V_2 , V_163 ) ;
if ( F_112 ( ! V_164 ) ) {
V_23 -> V_119 . V_275 ++ ;
goto V_276;
}
if ( ! V_2 -> V_50 ) {
V_259 =
F_3 ( V_2 , V_163 -> V_219 ) ;
} else {
struct V_222 * V_223 ;
V_223 = (struct V_222 * ) V_164 -> V_91 ;
V_259 = V_223 -> V_208 ;
}
V_260 = V_259 & 0xffff ;
V_244 = V_259 >> V_212 ;
F_94 ( V_2 , V_272 , V_23 ,
L_11 ,
V_183 , V_263 , V_30 -> V_177 ,
V_30 -> V_274 , V_259 ) ;
if ( F_112 ( ! ( V_260 & V_246 ) || ! ( V_260 & V_245 ) ) ) {
F_65 ( V_2 , V_272 , V_23 ,
L_12 ) ;
V_23 -> V_119 . V_271 ++ ;
F_80 ( V_164 ) ;
goto V_276;
}
if ( F_112 ( V_260 & ( V_277 |
V_278 |
V_279 |
V_280 |
V_281 ) ) ) {
F_65 ( V_2 , V_272 , V_23 , L_13 ,
( unsigned int ) V_260 ) ;
if ( V_260 & V_277 )
V_23 -> V_119 . V_282 ++ ;
if ( V_260 & V_278 )
V_23 -> V_119 . V_283 ++ ;
if ( V_260 & V_279 )
V_23 -> V_119 . V_284 ++ ;
if ( V_260 & V_280 )
V_23 -> V_119 . V_285 ++ ;
V_23 -> V_119 . V_271 ++ ;
F_80 ( V_164 ) ;
goto V_276;
}
V_265 = ( V_260 & V_2 -> V_286 ) &&
V_2 -> V_47 ;
F_143 ( V_164 , V_244 ) ;
if ( V_2 -> V_50 ) {
F_144 ( V_164 , 64 ) ;
V_244 -= 64 ;
}
if ( F_93 ( V_265 ) )
V_164 -> V_216 = V_287 ;
F_144 ( V_164 , 2 ) ;
V_244 -= 2 ;
if ( V_2 -> V_48 ) {
F_145 ( V_164 , V_244 - V_288 ) ;
V_244 -= V_288 ;
}
V_164 -> V_229 = F_146 ( V_164 , V_2 -> V_23 ) ;
V_23 -> V_119 . V_289 ++ ;
V_23 -> V_119 . V_290 += V_244 ;
if ( V_260 & V_291 )
V_23 -> V_119 . V_292 ++ ;
F_147 ( & V_30 -> V_196 , V_164 ) ;
F_94 ( V_2 , V_272 , V_23 , L_14 ) ;
V_276:
V_261 ++ ;
if ( F_93 ( V_30 -> V_274 < V_30 -> V_162 ) )
V_30 -> V_274 ++ ;
else
V_30 -> V_274 = V_30 -> V_161 ;
V_30 -> V_177 = ( V_30 -> V_177 + 1 ) & V_181 ;
F_32 ( V_2 , V_30 -> V_171 , V_30 -> V_177 , V_293 ) ;
}
return V_261 ;
}
static int F_148 ( struct V_195 * V_196 , int V_197 )
{
struct V_166 * V_30 = F_106 ( V_196 ,
struct V_166 , V_196 ) ;
unsigned int V_198 ;
V_198 = F_142 ( V_30 , V_197 ) ;
if ( V_198 < V_197 ) {
F_149 ( V_196 , V_198 ) ;
V_30 -> V_202 ( V_30 ) ;
}
return V_198 ;
}
static int F_150 ( struct V_1 * V_2 ,
struct V_166 * V_30 )
{
struct V_156 * V_163 ;
struct V_204 * V_164 ;
int V_71 ;
F_94 ( V_2 , V_139 , V_2 -> V_23 , L_15 , V_183 ) ;
for ( V_71 = 0 ; V_71 < V_30 -> V_294 ; V_71 ++ ) {
V_163 = V_30 -> V_159 + V_71 ;
V_164 = F_140 ( V_2 , V_163 ) ;
if ( V_164 )
F_80 ( V_164 ) ;
if ( ! V_163 -> V_164 )
return - V_295 ;
}
return 0 ;
}
static void F_151 ( struct V_1 * V_2 )
{
struct V_22 * V_173 = & V_2 -> V_174 -> V_23 ;
struct V_156 * V_163 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_296 ; V_71 ++ ) {
V_163 = & V_2 -> V_273 [ V_71 ] ;
if ( F_97 ( V_163 , V_165 ) ) {
F_96 ( V_173 ,
F_97 ( V_163 , V_165 ) ,
V_2 -> V_253 , V_257 ) ;
F_81 ( V_163 , V_165 , 0 ) ;
}
if ( V_163 -> V_164 )
F_79 ( V_163 ) ;
}
}
static void F_152 ( struct V_1 * V_2 , T_2 V_297 , bool V_120 )
{
T_2 V_72 ;
V_72 = F_56 ( V_2 , V_298 ) ;
if ( V_120 )
V_72 |= V_297 ;
else
V_72 &= ~ V_297 ;
F_57 ( V_2 , V_72 , V_298 ) ;
if ( V_120 == 0 )
F_153 ( 1000 , 2000 ) ;
}
static int F_154 ( struct V_1 * V_2 )
{
struct V_22 * V_173 = & V_2 -> V_174 -> V_23 ;
unsigned int V_299 = 0 ;
T_2 V_72 ;
F_15 ( V_2 , 0 ) ;
F_155 ( 10 ) ;
F_57 ( V_2 , 0 , V_298 ) ;
F_57 ( V_2 , V_300 , V_298 ) ;
while ( V_299 ++ < 1000 ) {
V_72 = F_56 ( V_2 , V_298 ) ;
if ( ! ( V_72 & V_300 ) )
return 0 ;
F_155 ( 1 ) ;
}
if ( V_299 == 1000 ) {
F_156 ( V_173 ,
L_16 ) ;
return - V_301 ;
}
return 0 ;
}
static void F_157 ( struct V_1 * V_2 )
{
F_83 ( V_2 , 0xFFFFFFFF , V_168 ) ;
F_83 ( V_2 , 0xFFFFFFFF , V_302 ) ;
F_83 ( V_2 , 0 , V_169 ) ;
F_86 ( V_2 , 0xFFFFFFFF , V_168 ) ;
F_86 ( V_2 , 0xFFFFFFFF , V_302 ) ;
F_86 ( V_2 , 0 , V_169 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
T_2 V_303 = 0 ;
if ( V_2 -> V_304 ) {
V_303 |= V_305 ;
} else if ( V_2 -> V_306 ) {
V_303 |= V_305 ;
} else if ( V_2 -> V_307 == V_308 ) {
if ( V_2 -> V_8 -> V_9 & V_309 )
V_303 |= V_305 ;
}
F_83 ( V_2 , V_303 , V_169 ) ;
}
static int F_159 ( struct V_1 * V_2 )
{
struct V_22 * V_173 = & V_2 -> V_174 -> V_23 ;
int V_60 ;
T_2 V_72 ;
T_2 V_303 = 0 ;
T_2 V_310 = 0 ;
int V_71 ;
F_160 ( & V_2 -> V_174 -> V_23 , L_17 ) ;
V_60 = F_154 ( V_2 ) ;
if ( V_60 )
return V_60 ;
F_57 ( V_2 , 0 , V_298 ) ;
F_57 ( V_2 ,
V_311 | V_312 | V_313 ,
V_314 ) ;
F_57 ( V_2 , 0 , V_314 ) ;
F_57 ( V_2 , V_315 , V_316 ) ;
V_72 = F_13 ( V_2 , V_53 ) ;
V_72 |= V_317 ;
F_16 ( V_2 , V_72 , V_53 ) ;
if ( ! F_12 ( V_2 ) && ! F_55 ( V_2 ) )
F_16 ( V_2 , 1 , V_318 ) ;
F_157 ( V_2 ) ;
V_303 |= V_167 ;
V_303 |= V_172 ;
if ( V_2 -> V_307 == V_308 ) {
V_72 = F_20 ( V_2 ) ;
V_72 |= F_161 ( V_2 -> V_8 -> V_319 ) ;
if ( F_110 ( V_2 -> V_23 ) )
V_72 |= V_2 -> V_8 -> V_320 ;
else
V_72 &= ~ V_2 -> V_8 -> V_320 ;
F_21 ( V_2 , V_72 ) ;
}
if ( V_2 -> V_8 -> V_9 & V_321 )
V_303 |= ( V_322 | V_323 ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; ++ V_71 )
V_310 |= ( 1 << ( V_170 + V_71 ) ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; ++ V_71 )
V_310 |= ( 1 << V_71 ) ;
F_83 ( V_2 , V_303 , V_169 ) ;
F_86 ( V_2 , V_310 , V_169 ) ;
F_160 ( V_173 , L_18 ) ;
return 0 ;
}
static void F_162 ( struct V_1 * V_2 ,
unsigned int V_171 , unsigned int V_294 ,
unsigned int V_324 , unsigned int V_162 )
{
struct V_157 * V_30 = & V_2 -> V_203 [ V_171 ] ;
T_2 V_325 = F_163 ( V_2 ) ;
T_2 V_326 = 0 ;
F_164 ( & V_30 -> V_194 ) ;
V_30 -> V_2 = V_2 ;
V_30 -> V_171 = V_171 ;
if ( V_171 == V_66 ) {
V_30 -> V_192 = 0 ;
V_30 -> V_202 = F_89 ;
V_30 -> V_327 = F_88 ;
} else {
V_30 -> V_192 = V_171 + 1 ;
V_30 -> V_202 = F_90 ;
V_30 -> V_327 = F_91 ;
}
V_30 -> V_159 = V_2 -> V_184 + V_324 ;
V_30 -> V_294 = V_294 ;
V_30 -> V_185 = V_324 ;
V_30 -> V_177 = 0 ;
V_30 -> V_189 = V_294 ;
V_30 -> V_160 = V_324 ;
V_30 -> V_161 = V_324 ;
V_30 -> V_162 = V_162 - 1 ;
V_30 -> V_248 = 0 ;
if ( V_171 != V_66 )
V_326 = V_315 << 16 ;
F_30 ( V_2 , V_171 , 0 , V_251 ) ;
F_30 ( V_2 , V_171 , 0 , V_180 ) ;
F_30 ( V_2 , V_171 , 1 , V_67 ) ;
F_30 ( V_2 , V_171 , V_326 ,
V_328 ) ;
F_30 ( V_2 , V_171 ,
( ( V_294 << V_329 ) |
V_330 ) , V_331 ) ;
F_30 ( V_2 , V_171 , V_324 * V_325 ,
V_332 ) ;
F_30 ( V_2 , V_171 , V_324 * V_325 ,
V_333 ) ;
F_30 ( V_2 , V_171 , V_324 * V_325 ,
V_334 ) ;
F_30 ( V_2 , V_171 , V_162 * V_325 - 1 ,
V_335 ) ;
}
static int F_165 ( struct V_1 * V_2 ,
unsigned int V_171 , unsigned int V_294 ,
unsigned int V_324 , unsigned int V_162 )
{
struct V_166 * V_30 = & V_2 -> V_336 [ V_171 ] ;
T_2 V_325 = F_163 ( V_2 ) ;
int V_60 ;
V_30 -> V_2 = V_2 ;
V_30 -> V_171 = V_171 ;
if ( V_171 == V_66 ) {
V_30 -> V_202 = F_84 ;
V_30 -> V_327 = F_82 ;
} else {
V_30 -> V_202 = F_87 ;
V_30 -> V_327 = F_85 ;
}
V_30 -> V_159 = V_2 -> V_273 + V_324 ;
V_30 -> V_294 = V_294 ;
V_30 -> V_177 = 0 ;
V_30 -> V_274 = V_324 ;
V_30 -> V_161 = V_324 ;
V_30 -> V_162 = V_162 - 1 ;
V_60 = F_150 ( V_2 , V_30 ) ;
if ( V_60 )
return V_60 ;
F_32 ( V_2 , V_171 , 0 , V_266 ) ;
F_32 ( V_2 , V_171 , 0 , V_293 ) ;
F_32 ( V_2 , V_171 , 1 , V_67 ) ;
F_32 ( V_2 , V_171 ,
( ( V_294 << V_329 ) |
V_330 ) , V_331 ) ;
F_32 ( V_2 , V_171 ,
( V_337 <<
V_338 ) |
V_339 , V_340 ) ;
F_32 ( V_2 , V_171 , V_324 * V_325 ,
V_332 ) ;
F_32 ( V_2 , V_171 , V_324 * V_325 ,
V_341 ) ;
F_32 ( V_2 , V_171 , V_324 * V_325 ,
V_342 ) ;
F_32 ( V_2 , V_171 , V_162 * V_325 - 1 ,
V_335 ) ;
return V_60 ;
}
static void F_166 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
struct V_157 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; ++ V_71 ) {
V_30 = & V_2 -> V_203 [ V_71 ] ;
F_167 ( V_2 -> V_23 , & V_30 -> V_196 , F_105 , 64 ) ;
}
V_30 = & V_2 -> V_203 [ V_66 ] ;
F_167 ( V_2 -> V_23 , & V_30 -> V_196 , F_105 , 64 ) ;
}
static void F_168 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
struct V_157 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; ++ V_71 ) {
V_30 = & V_2 -> V_203 [ V_71 ] ;
F_169 ( & V_30 -> V_196 ) ;
}
V_30 = & V_2 -> V_203 [ V_66 ] ;
F_169 ( & V_30 -> V_196 ) ;
}
static void F_170 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
struct V_157 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; ++ V_71 ) {
V_30 = & V_2 -> V_203 [ V_71 ] ;
F_171 ( & V_30 -> V_196 ) ;
}
V_30 = & V_2 -> V_203 [ V_66 ] ;
F_171 ( & V_30 -> V_196 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
struct V_157 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; ++ V_71 ) {
V_30 = & V_2 -> V_203 [ V_71 ] ;
F_173 ( & V_30 -> V_196 ) ;
}
V_30 = & V_2 -> V_203 [ V_66 ] ;
F_173 ( & V_30 -> V_196 ) ;
}
static void F_174 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_71 , V_343 ;
T_2 V_344 , V_345 ;
T_2 V_346 [ 3 ] = { 0 , 0 , 0 } ;
V_344 = F_25 ( V_2 , V_347 ) ;
V_343 = V_344 & V_348 ;
V_344 &= ~ V_348 ;
F_26 ( V_2 , V_344 , V_347 ) ;
V_344 = 0 ;
V_345 = 0 ;
F_26 ( V_2 , V_349 , V_350 ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; V_71 ++ ) {
F_162 ( V_2 , V_71 , V_2 -> V_8 -> V_351 ,
V_71 * V_2 -> V_8 -> V_351 ,
( V_71 + 1 ) * V_2 -> V_8 -> V_351 ) ;
V_345 |= ( 1 << V_71 ) ;
V_344 |= ( 1 << ( V_71 + V_352 ) ) ;
V_346 [ F_175 ( V_71 ) ] |=
( ( V_353 + V_71 ) << F_176 ( V_71 ) ) ;
}
F_162 ( V_2 , V_66 , V_354 ,
V_2 -> V_8 -> V_80 *
V_2 -> V_8 -> V_351 ,
V_355 ) ;
V_345 |= ( 1 << V_66 ) ;
V_344 |= ( 1 << ( V_66 + V_352 ) ) ;
V_346 [ F_175 ( V_66 ) ] |=
( ( V_353 + V_2 -> V_8 -> V_80 ) <<
F_176 ( V_66 ) ) ;
F_26 ( V_2 , V_346 [ 0 ] , V_356 ) ;
F_26 ( V_2 , V_346 [ 1 ] , V_357 ) ;
F_26 ( V_2 , V_346 [ 2 ] , V_358 ) ;
F_166 ( V_2 ) ;
F_26 ( V_2 , V_345 , V_359 ) ;
if ( V_343 )
V_344 |= V_348 ;
F_26 ( V_2 , V_344 , V_347 ) ;
}
static void F_177 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
struct V_166 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; ++ V_71 ) {
V_30 = & V_2 -> V_336 [ V_71 ] ;
F_178 ( V_2 -> V_23 , & V_30 -> V_196 , F_148 , 64 ) ;
}
V_30 = & V_2 -> V_336 [ V_66 ] ;
F_178 ( V_2 -> V_23 , & V_30 -> V_196 , F_148 , 64 ) ;
}
static void F_179 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
struct V_166 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; ++ V_71 ) {
V_30 = & V_2 -> V_336 [ V_71 ] ;
F_169 ( & V_30 -> V_196 ) ;
}
V_30 = & V_2 -> V_336 [ V_66 ] ;
F_169 ( & V_30 -> V_196 ) ;
}
static void F_180 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
struct V_166 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; ++ V_71 ) {
V_30 = & V_2 -> V_336 [ V_71 ] ;
F_171 ( & V_30 -> V_196 ) ;
}
V_30 = & V_2 -> V_336 [ V_66 ] ;
F_171 ( & V_30 -> V_196 ) ;
}
static void F_181 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
struct V_166 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; ++ V_71 ) {
V_30 = & V_2 -> V_336 [ V_71 ] ;
F_173 ( & V_30 -> V_196 ) ;
}
V_30 = & V_2 -> V_336 [ V_66 ] ;
F_173 ( & V_30 -> V_196 ) ;
}
static int F_182 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_71 ;
T_2 V_343 ;
T_2 V_344 ;
T_2 V_345 ;
int V_60 ;
V_344 = F_27 ( V_2 , V_347 ) ;
V_343 = V_344 & V_348 ;
V_344 &= ~ V_348 ;
F_28 ( V_2 , V_344 , V_347 ) ;
V_344 = 0 ;
V_345 = 0 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; V_71 ++ ) {
V_60 = F_165 ( V_2 , V_71 ,
V_2 -> V_8 -> V_360 ,
V_71 * V_2 -> V_8 -> V_360 ,
( V_71 + 1 ) *
V_2 -> V_8 -> V_360 ) ;
if ( V_60 )
return V_60 ;
V_345 |= ( 1 << V_71 ) ;
V_344 |= ( 1 << ( V_71 + V_352 ) ) ;
}
V_60 = F_165 ( V_2 , V_66 , V_361 ,
V_2 -> V_8 -> V_81 *
V_2 -> V_8 -> V_360 ,
V_355 ) ;
if ( V_60 )
return V_60 ;
V_345 |= ( 1 << V_66 ) ;
V_344 |= ( 1 << ( V_66 + V_352 ) ) ;
F_177 ( V_2 ) ;
F_28 ( V_2 , V_345 , V_359 ) ;
if ( V_343 )
V_344 |= V_348 ;
F_28 ( V_2 , V_344 , V_347 ) ;
return 0 ;
}
static int F_183 ( struct V_1 * V_2 )
{
int V_60 = 0 ;
int V_299 = 0 ;
T_2 V_72 ;
T_2 V_344 ;
int V_71 ;
V_72 = F_25 ( V_2 , V_347 ) ;
V_72 &= ~ V_348 ;
F_26 ( V_2 , V_72 , V_347 ) ;
while ( V_299 ++ < V_362 ) {
V_72 = F_25 ( V_2 , V_363 ) ;
if ( V_72 & V_364 )
break;
F_155 ( 1 ) ;
}
if ( V_299 == V_362 ) {
F_184 ( V_2 -> V_23 , L_19 ) ;
V_60 = - V_301 ;
}
F_153 ( 10000 , 20000 ) ;
V_72 = F_27 ( V_2 , V_347 ) ;
V_72 &= ~ V_348 ;
F_28 ( V_2 , V_72 , V_347 ) ;
V_299 = 0 ;
while ( V_299 ++ < V_362 ) {
V_72 = F_27 ( V_2 , V_363 ) ;
if ( V_72 & V_364 )
break;
F_155 ( 1 ) ;
}
if ( V_299 == V_362 ) {
F_184 ( V_2 -> V_23 , L_20 ) ;
V_60 = - V_301 ;
}
V_344 = 0 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; V_71 ++ )
V_344 |= ( 1 << ( V_71 + V_352 ) ) ;
V_72 = F_27 ( V_2 , V_347 ) ;
V_72 &= ~ V_344 ;
F_28 ( V_2 , V_72 , V_347 ) ;
V_344 = 0 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; V_71 ++ )
V_344 |= ( 1 << ( V_71 + V_352 ) ) ;
V_72 = F_25 ( V_2 , V_347 ) ;
V_72 &= ~ V_344 ;
F_26 ( V_2 , V_72 , V_347 ) ;
return V_60 ;
}
static void F_185 ( struct V_1 * V_2 )
{
int V_71 ;
struct V_199 * V_200 ;
F_181 ( V_2 ) ;
F_172 ( V_2 ) ;
F_183 ( V_2 ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_365 ; V_71 ++ ) {
if ( V_2 -> V_184 [ V_71 ] . V_164 != NULL ) {
F_117 ( V_2 -> V_184 [ V_71 ] . V_164 ) ;
V_2 -> V_184 [ V_71 ] . V_164 = NULL ;
}
}
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; V_71 ++ ) {
V_200 = F_101 ( V_2 -> V_23 , V_2 -> V_203 [ V_71 ] . V_192 ) ;
F_186 ( V_200 ) ;
}
V_200 = F_101 ( V_2 -> V_23 , V_2 -> V_203 [ V_66 ] . V_192 ) ;
F_186 ( V_200 ) ;
F_151 ( V_2 ) ;
F_187 ( V_2 -> V_273 ) ;
F_187 ( V_2 -> V_184 ) ;
}
static int F_188 ( struct V_1 * V_2 )
{
int V_60 ;
unsigned int V_71 ;
struct V_156 * V_163 ;
F_94 ( V_2 , V_139 , V_2 -> V_23 , L_15 , V_183 ) ;
V_2 -> V_366 = V_2 -> V_17 + V_2 -> V_8 -> V_367 ;
V_2 -> V_296 = V_355 ;
V_2 -> V_273 = F_189 ( V_2 -> V_296 , sizeof( struct V_156 ) ,
V_368 ) ;
if ( ! V_2 -> V_273 )
return - V_295 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_296 ; V_71 ++ ) {
V_163 = V_2 -> V_273 + V_71 ;
V_163 -> V_219 = V_2 -> V_366 + V_71 * V_369 ;
}
V_2 -> V_370 = V_2 -> V_17 + V_2 -> V_8 -> V_371 ;
V_2 -> V_365 = V_355 ;
V_2 -> V_184 = F_189 ( V_2 -> V_365 , sizeof( struct V_156 ) ,
V_368 ) ;
if ( ! V_2 -> V_184 ) {
F_187 ( V_2 -> V_273 ) ;
return - V_295 ;
}
for ( V_71 = 0 ; V_71 < V_2 -> V_365 ; V_71 ++ ) {
V_163 = V_2 -> V_184 + V_71 ;
V_163 -> V_219 = V_2 -> V_370 + V_71 * V_369 ;
}
F_28 ( V_2 , V_372 , V_373 ) ;
V_60 = F_182 ( V_2 -> V_23 ) ;
if ( V_60 ) {
F_135 ( V_2 -> V_23 , L_21 ) ;
F_151 ( V_2 ) ;
F_187 ( V_2 -> V_273 ) ;
F_187 ( V_2 -> V_184 ) ;
return V_60 ;
}
F_26 ( V_2 , V_372 , V_373 ) ;
F_174 ( V_2 -> V_23 ) ;
return 0 ;
}
static void F_190 ( struct V_374 * V_375 )
{
unsigned long V_9 ;
unsigned int V_223 ;
struct V_1 * V_2 = F_106 (
V_375 , struct V_1 , V_376 ) ;
F_94 ( V_2 , V_377 , V_2 -> V_23 , L_15 , V_183 ) ;
F_103 ( & V_2 -> V_194 , V_9 ) ;
V_223 = V_2 -> V_378 ;
V_2 -> V_378 = 0 ;
F_104 ( & V_2 -> V_194 , V_9 ) ;
if ( V_223 & V_379 ) {
F_94 ( V_2 , V_380 , V_2 -> V_23 ,
L_22 ) ;
F_73 ( V_2 , V_143 ) ;
}
if ( V_223 & V_305 )
F_191 ( V_2 -> V_39 ,
! ! ( V_223 & V_381 ) ) ;
}
static T_9 F_192 ( int V_382 , void * V_383 )
{
struct V_1 * V_2 = V_383 ;
struct V_166 * V_384 ;
struct V_157 * V_385 ;
unsigned int V_171 , V_223 ;
V_223 = F_193 ( V_2 , V_386 ) &
~ F_193 ( V_2 , V_387 ) ;
F_86 ( V_2 , V_223 , V_302 ) ;
F_94 ( V_2 , V_377 , V_2 -> V_23 ,
L_23 , V_183 , V_223 ) ;
for ( V_171 = 0 ; V_171 < V_2 -> V_8 -> V_81 ; V_171 ++ ) {
if ( ! ( V_223 & F_161 ( V_170 + V_171 ) ) )
continue;
V_384 = & V_2 -> V_336 [ V_171 ] ;
if ( F_93 ( F_194 ( & V_384 -> V_196 ) ) ) {
V_384 -> V_327 ( V_384 ) ;
F_195 ( & V_384 -> V_196 ) ;
}
}
for ( V_171 = 0 ; V_171 < V_2 -> V_8 -> V_80 ; V_171 ++ ) {
if ( ! ( V_223 & F_161 ( V_171 ) ) )
continue;
V_385 = & V_2 -> V_203 [ V_171 ] ;
if ( F_93 ( F_194 ( & V_385 -> V_196 ) ) ) {
V_385 -> V_327 ( V_385 ) ;
F_195 ( & V_385 -> V_196 ) ;
}
}
return V_388 ;
}
static T_9 F_196 ( int V_382 , void * V_383 )
{
struct V_1 * V_2 = V_383 ;
struct V_166 * V_384 ;
struct V_157 * V_385 ;
unsigned int V_223 ;
unsigned long V_9 ;
V_223 = F_197 ( V_2 , V_386 ) &
~ F_197 ( V_2 , V_387 ) ;
F_83 ( V_2 , V_223 , V_302 ) ;
F_94 ( V_2 , V_377 , V_2 -> V_23 ,
L_24 , V_223 ) ;
if ( V_223 & V_167 ) {
V_384 = & V_2 -> V_336 [ V_66 ] ;
if ( F_93 ( F_194 ( & V_384 -> V_196 ) ) ) {
V_384 -> V_327 ( V_384 ) ;
F_195 ( & V_384 -> V_196 ) ;
}
}
if ( V_223 & V_172 ) {
V_385 = & V_2 -> V_203 [ V_66 ] ;
if ( F_93 ( F_194 ( & V_385 -> V_196 ) ) ) {
V_385 -> V_327 ( V_385 ) ;
F_195 ( & V_385 -> V_196 ) ;
}
}
if ( ( V_2 -> V_8 -> V_9 & V_321 ) &&
V_223 & ( V_322 | V_323 ) ) {
F_198 ( & V_2 -> V_389 ) ;
}
V_223 &= ( V_305 |
V_379 ) ;
if ( V_223 ) {
F_103 ( & V_2 -> V_194 , V_9 ) ;
V_2 -> V_378 |= V_223 ;
F_104 ( & V_2 -> V_194 , V_9 ) ;
F_199 ( & V_2 -> V_376 ) ;
}
return V_388 ;
}
static T_9 F_200 ( int V_382 , void * V_383 )
{
struct V_1 * V_2 = V_383 ;
F_201 ( & V_2 -> V_174 -> V_23 , 0 ) ;
return V_388 ;
}
static void F_202 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_203 ( V_2 -> V_390 ) ;
F_196 ( V_2 -> V_390 , V_2 ) ;
F_204 ( V_2 -> V_390 ) ;
F_203 ( V_2 -> V_391 ) ;
F_192 ( V_2 -> V_391 , V_2 ) ;
F_204 ( V_2 -> V_391 ) ;
}
static void F_205 ( struct V_1 * V_2 )
{
T_2 V_72 ;
V_72 = F_11 ( V_2 ) ;
V_72 |= F_161 ( 1 ) ;
F_15 ( V_2 , V_72 ) ;
F_155 ( 10 ) ;
V_72 &= ~ F_161 ( 1 ) ;
F_15 ( V_2 , V_72 ) ;
F_155 ( 10 ) ;
}
static void F_206 ( struct V_1 * V_2 ,
unsigned char * V_6 )
{
F_57 ( V_2 , ( V_6 [ 0 ] << 24 ) | ( V_6 [ 1 ] << 16 ) |
( V_6 [ 2 ] << 8 ) | V_6 [ 3 ] , V_392 ) ;
F_57 ( V_2 , ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] , V_393 ) ;
}
static T_2 F_207 ( struct V_1 * V_2 )
{
T_2 V_72 ;
T_2 V_344 ;
V_344 = 1 << ( V_66 + V_352 ) | V_348 ;
V_72 = F_25 ( V_2 , V_347 ) ;
V_72 &= ~ V_344 ;
F_26 ( V_2 , V_72 , V_347 ) ;
V_72 = F_27 ( V_2 , V_347 ) ;
V_72 &= ~ V_344 ;
F_28 ( V_2 , V_72 , V_347 ) ;
F_57 ( V_2 , 1 , V_394 ) ;
F_155 ( 10 ) ;
F_57 ( V_2 , 0 , V_394 ) ;
return V_344 ;
}
static void F_208 ( struct V_1 * V_2 , T_2 V_344 )
{
T_2 V_72 ;
V_72 = F_27 ( V_2 , V_347 ) ;
V_72 |= V_344 ;
F_28 ( V_2 , V_72 , V_347 ) ;
V_72 = F_25 ( V_2 , V_347 ) ;
V_72 |= V_344 ;
F_26 ( V_2 , V_72 , V_347 ) ;
}
static void F_209 ( struct V_1 * V_2 )
{
T_2 V_71 ;
F_210 ( V_2 , 0x0 , V_395 ) ;
F_210 ( V_2 , 0x0 , V_396 ) ;
F_210 ( V_2 , 0x0 , V_396 + 4 ) ;
for ( V_71 = V_397 ; V_71 <= V_398 ; V_71 ++ )
F_28 ( V_2 , 0x0 , V_71 ) ;
for ( V_71 = 0 ; V_71 < ( V_2 -> V_8 -> V_399 / 4 ) ; V_71 ++ )
F_210 ( V_2 , 0x0 ,
V_400 + V_71 * sizeof( T_2 ) ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_399 *
V_2 -> V_8 -> V_401 ; V_71 ++ )
F_211 ( V_2 , 0x0 , V_71 * sizeof( T_2 ) ) ;
}
static void F_212 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) || F_55 ( V_2 ) )
return;
F_209 ( V_2 ) ;
}
static void F_213 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_179 ( V_2 ) ;
F_168 ( V_2 ) ;
F_152 ( V_2 , V_402 | V_403 , true ) ;
F_214 ( V_23 ) ;
F_158 ( V_2 ) ;
F_215 ( V_2 -> V_39 ) ;
}
static int F_216 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned long V_344 ;
T_2 V_72 ;
int V_60 ;
F_94 ( V_2 , V_404 , V_23 , L_25 ) ;
F_34 ( V_2 -> V_35 ) ;
if ( V_2 -> V_304 )
F_73 ( V_2 , V_144 ) ;
F_205 ( V_2 ) ;
V_60 = F_159 ( V_2 ) ;
if ( V_60 )
goto V_405;
F_152 ( V_2 , V_402 | V_403 , false ) ;
V_72 = F_56 ( V_2 , V_298 ) ;
V_2 -> V_48 = ! ! ( V_72 & V_406 ) ;
F_206 ( V_2 , V_23 -> V_407 ) ;
if ( V_2 -> V_304 ) {
V_72 = F_70 ( V_2 , V_146 ) ;
V_72 |= V_408 ;
F_71 ( V_2 , V_72 , V_146 ) ;
}
V_344 = F_207 ( V_2 ) ;
V_60 = F_188 ( V_2 ) ;
if ( V_60 ) {
F_135 ( V_23 , L_26 ) ;
goto V_405;
}
F_208 ( V_2 , V_344 ) ;
F_212 ( V_2 ) ;
V_60 = F_217 ( V_2 -> V_390 , F_196 , V_409 ,
V_23 -> V_410 , V_2 ) ;
if ( V_60 < 0 ) {
F_135 ( V_23 , L_27 , V_2 -> V_390 ) ;
goto V_411;
}
V_60 = F_217 ( V_2 -> V_391 , F_192 , V_409 ,
V_23 -> V_410 , V_2 ) ;
if ( V_60 < 0 ) {
F_135 ( V_23 , L_27 , V_2 -> V_391 ) ;
goto V_412;
}
V_60 = F_218 ( V_23 ) ;
if ( V_60 ) {
F_135 ( V_23 , L_28 ) ;
goto V_413;
}
F_213 ( V_23 ) ;
return 0 ;
V_413:
F_219 ( V_2 -> V_391 , V_2 ) ;
V_412:
F_219 ( V_2 -> V_390 , V_2 ) ;
V_411:
F_185 ( V_2 ) ;
V_405:
if ( V_2 -> V_304 )
F_67 ( V_2 , V_144 ) ;
F_36 ( V_2 -> V_35 ) ;
return V_60 ;
}
static void F_220 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_221 ( V_23 ) ;
F_222 ( V_2 -> V_39 ) ;
F_157 ( V_2 ) ;
F_180 ( V_2 ) ;
F_170 ( V_2 ) ;
F_223 ( & V_2 -> V_376 ) ;
V_2 -> V_414 = - 1 ;
V_2 -> V_415 = - 1 ;
V_2 -> V_416 = - 1 ;
V_2 -> V_417 = - 1 ;
}
static int F_224 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_60 ;
F_94 ( V_2 , V_418 , V_23 , L_29 ) ;
F_220 ( V_23 ) ;
F_225 ( V_2 -> V_39 ) ;
F_152 ( V_2 , V_403 , false ) ;
V_60 = F_183 ( V_2 ) ;
if ( V_60 )
return V_60 ;
F_152 ( V_2 , V_402 , false ) ;
F_109 ( V_23 ) ;
F_185 ( V_2 ) ;
F_219 ( V_2 -> V_390 , V_2 ) ;
F_219 ( V_2 -> V_391 , V_2 ) ;
if ( V_2 -> V_304 )
V_60 = F_67 ( V_2 , V_144 ) ;
F_36 ( V_2 -> V_35 ) ;
return V_60 ;
}
static void F_226 ( struct V_157 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_2 V_263 , V_177 , V_419 , V_420 ;
struct V_199 * V_200 ;
unsigned int V_189 ;
unsigned long V_9 ;
bool V_421 ;
if ( ! F_227 ( V_2 ) )
return;
V_200 = F_101 ( V_2 -> V_23 , V_30 -> V_192 ) ;
F_103 ( & V_30 -> V_194 , V_9 ) ;
if ( V_30 -> V_171 == V_66 ) {
V_419 = ~ F_197 ( V_2 , V_387 ) ;
V_420 = V_172 | V_422 ;
} else {
V_419 = ~ F_193 ( V_2 , V_387 ) ;
V_420 = 1 << V_30 -> V_171 ;
}
V_177 = F_29 ( V_2 , V_30 -> V_171 , V_180 ) ;
V_263 = F_29 ( V_2 , V_30 -> V_171 , V_251 ) ;
V_421 = F_133 ( V_200 ) ;
V_189 = V_30 -> V_189 ;
F_104 ( & V_30 -> V_194 , V_9 ) ;
F_65 ( V_2 , V_211 , V_2 -> V_23 , L_30
L_31
L_32
L_33
L_34
L_35
L_36 ,
V_30 -> V_171 , V_30 -> V_192 ,
V_421 ? L_37 : L_38 ,
V_419 & V_420 ? L_39 : L_40 ,
V_189 , V_30 -> V_294 ,
V_30 -> V_248 , V_263 & V_249 ,
V_30 -> V_177 , V_177 & V_181 ,
V_30 -> V_185 , V_30 -> V_160 ,
V_30 -> V_161 , V_30 -> V_162 ) ;
}
static void F_228 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_303 = 0 ;
T_2 V_310 = 0 ;
unsigned int V_423 ;
F_94 ( V_2 , V_211 , V_23 , L_41 ) ;
for ( V_423 = 0 ; V_423 < V_2 -> V_8 -> V_80 ; V_423 ++ )
F_226 ( & V_2 -> V_203 [ V_423 ] ) ;
F_226 ( & V_2 -> V_203 [ V_66 ] ) ;
F_109 ( V_23 ) ;
for ( V_423 = 0 ; V_423 < V_2 -> V_8 -> V_80 ; V_423 ++ )
V_310 |= ( 1 << V_423 ) ;
V_303 = V_172 ;
F_83 ( V_2 , V_303 , V_169 ) ;
F_86 ( V_2 , V_310 , V_169 ) ;
F_229 ( V_23 ) ;
V_23 -> V_119 . V_424 ++ ;
F_230 ( V_23 ) ;
}
static inline void F_231 ( struct V_1 * V_2 ,
unsigned char * V_6 ,
int * V_71 ,
int * V_425 )
{
T_2 V_72 ;
F_57 ( V_2 , V_6 [ 0 ] << 8 | V_6 [ 1 ] ,
V_426 + ( * V_71 * 4 ) ) ;
F_57 ( V_2 , V_6 [ 2 ] << 24 | V_6 [ 3 ] << 16 |
V_6 [ 4 ] << 8 | V_6 [ 5 ] ,
V_426 + ( ( * V_71 + 1 ) * 4 ) ) ;
V_72 = F_56 ( V_2 , V_427 ) ;
V_72 |= ( 1 << ( V_428 - * V_425 ) ) ;
F_57 ( V_2 , V_72 , V_427 ) ;
* V_71 += 2 ;
( * V_425 ) ++ ;
}
static void F_232 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_429 * V_430 ;
int V_71 , V_425 ;
T_2 V_72 ;
F_94 ( V_2 , V_139 , V_23 , L_42 , V_183 , V_23 -> V_9 ) ;
V_72 = F_56 ( V_2 , V_298 ) ;
if ( V_23 -> V_9 & V_431 ) {
V_72 |= V_432 ;
F_57 ( V_2 , V_72 , V_298 ) ;
F_57 ( V_2 , 0 , V_427 ) ;
return;
} else {
V_72 &= ~ V_432 ;
F_57 ( V_2 , V_72 , V_298 ) ;
}
if ( V_23 -> V_9 & V_433 ) {
F_184 ( V_23 , L_43 ) ;
return;
}
V_71 = 0 ;
V_425 = 0 ;
F_231 ( V_2 , V_23 -> V_434 , & V_71 , & V_425 ) ;
F_231 ( V_2 , V_23 -> V_407 , & V_71 , & V_425 ) ;
if ( F_233 ( V_23 ) > ( V_428 - V_425 ) )
return;
if ( ! F_234 ( V_23 ) )
F_235 (ha, dev)
F_231 ( V_2 , V_430 -> V_6 , & V_71 , & V_425 ) ;
if ( F_236 ( V_23 ) || F_237 ( V_23 ) >= ( V_428 - V_425 ) )
return;
F_238 (ha, dev)
F_231 ( V_2 , V_430 -> V_6 , & V_71 , & V_425 ) ;
}
static int F_239 ( struct V_34 * V_23 , void * V_106 )
{
struct V_435 * V_6 = V_106 ;
if ( F_38 ( V_23 ) )
return - V_436 ;
F_240 ( V_23 -> V_407 , V_6 -> V_437 ) ;
return 0 ;
}
static void F_241 ( struct V_1 * V_2 )
{
struct V_438 * V_439 ;
T_2 V_72 ;
T_5 V_440 ;
T_6 V_441 ;
if ( F_242 ( V_2 ) ) {
V_28 = V_442 ;
V_33 = V_443 ;
V_2 -> V_286 = V_444 ;
V_2 -> V_86 = V_445 ;
} else if ( F_243 ( V_2 ) ) {
V_28 = V_442 ;
V_33 = V_446 ;
V_2 -> V_286 = V_444 ;
V_2 -> V_86 = V_447 ;
} else if ( F_55 ( V_2 ) ) {
V_28 = V_448 ;
V_33 = V_446 ;
V_2 -> V_286 = V_449 ;
V_2 -> V_86 = V_450 ;
} else if ( F_12 ( V_2 ) ) {
V_28 = V_451 ;
V_33 = V_446 ;
V_2 -> V_286 = V_449 ;
V_2 -> V_86 = V_452 ;
}
V_2 -> V_8 = & V_438 [ V_2 -> V_86 ] ;
V_439 = V_2 -> V_8 ;
V_72 = F_14 ( V_2 , V_453 ) ;
V_440 = ( V_72 >> 24 & 0x0f ) ;
if ( V_440 == 5 )
V_440 = 4 ;
else if ( V_440 == 0 )
V_440 = 1 ;
if ( V_440 != V_2 -> V_86 ) {
F_156 ( & V_2 -> V_174 -> V_23 ,
L_44 ,
V_440 , V_2 -> V_86 ) ;
}
F_244 ( & V_2 -> V_174 -> V_23 , L_45 V_454 ,
V_440 , ( V_72 >> 16 ) & 0x0f , V_72 & 0xffff ) ;
V_441 = V_72 & 0xffff ;
if ( V_441 == 0 || V_441 == 0x01ff ) {
F_245 ( L_46 , V_441 ) ;
return;
}
if ( ( V_441 & 0xf0 ) != 0 )
V_2 -> V_441 = V_441 << 8 ;
else if ( ( V_441 & 0xff00 ) != 0 )
V_2 -> V_441 = V_441 ;
#ifdef F_7
if ( ! ( V_439 -> V_9 & V_10 ) )
F_245 ( L_47 ) ;
#endif
F_246 ( L_48
L_49
L_50
L_51
L_52
L_53
L_54 ,
V_2 -> V_86 ,
V_439 -> V_80 , V_439 -> V_351 ,
V_439 -> V_81 , V_439 -> V_360 ,
V_439 -> V_319 , V_439 -> V_320 ,
V_439 -> V_399 , V_439 -> V_213 ,
V_439 -> V_18 , V_439 -> V_455 ,
V_439 -> V_456 ,
V_439 -> V_367 , V_439 -> V_371 ,
V_439 -> V_325 ) ;
}
static int F_247 ( struct V_457 * V_174 )
{
struct V_458 * V_459 = V_174 -> V_23 . V_460 ;
struct V_461 * V_462 = V_174 -> V_23 . V_463 ;
const struct V_464 * V_465 = NULL ;
struct V_1 * V_2 ;
struct V_34 * V_23 ;
const void * V_466 ;
struct V_467 * V_25 ;
int V_468 = - V_469 ;
const char * V_470 ;
V_23 = F_248 ( sizeof( * V_2 ) , V_471 + 1 ,
V_471 + 1 ) ;
if ( ! V_23 ) {
F_156 ( & V_174 -> V_23 , L_55 ) ;
return - V_295 ;
}
if ( V_462 ) {
V_465 = F_249 ( V_472 , V_462 ) ;
if ( ! V_465 )
return - V_38 ;
}
V_2 = F_23 ( V_23 ) ;
V_2 -> V_390 = F_250 ( V_174 , 0 ) ;
V_2 -> V_391 = F_250 ( V_174 , 1 ) ;
V_2 -> V_473 = F_250 ( V_174 , 2 ) ;
if ( ! V_2 -> V_390 || ! V_2 -> V_391 ) {
F_156 ( & V_174 -> V_23 , L_56 ) ;
V_468 = - V_38 ;
goto V_468;
}
if ( V_462 ) {
V_466 = F_251 ( V_462 ) ;
if ( ! V_466 ) {
F_156 ( & V_174 -> V_23 , L_57 ) ;
V_468 = - V_38 ;
goto V_468;
}
} else {
V_466 = V_459 -> V_474 ;
}
V_25 = F_252 ( V_174 , V_475 , 0 ) ;
V_2 -> V_17 = F_253 ( & V_174 -> V_23 , V_25 ) ;
if ( F_254 ( V_2 -> V_17 ) ) {
V_468 = F_255 ( V_2 -> V_17 ) ;
goto V_468;
}
F_164 ( & V_2 -> V_194 ) ;
F_256 ( V_23 , & V_174 -> V_23 ) ;
F_257 ( & V_174 -> V_23 , V_23 ) ;
F_240 ( V_23 -> V_407 , V_466 ) ;
V_23 -> V_476 = 2 * V_477 ;
V_23 -> V_478 = & V_479 ;
V_23 -> V_480 = & V_481 ;
V_2 -> V_61 = F_258 ( - 1 , V_482 ) ;
V_23 -> V_483 |= V_484 | V_54 |
V_55 | V_44 ;
V_2 -> V_485 = true ;
V_468 = F_259 ( & V_174 -> V_23 , V_2 -> V_473 , F_200 , 0 ,
V_23 -> V_410 , V_2 ) ;
if ( ! V_468 )
F_260 ( & V_174 -> V_23 , 1 ) ;
V_23 -> V_486 += 64 ;
F_261 ( V_23 ) ;
V_2 -> V_23 = V_23 ;
V_2 -> V_174 = V_174 ;
if ( V_465 )
V_2 -> V_86 = (enum V_487 ) V_465 -> V_91 ;
else
V_2 -> V_86 = V_459 -> V_488 ;
V_2 -> V_35 = F_262 ( & V_2 -> V_174 -> V_23 , L_58 ) ;
if ( F_254 ( V_2 -> V_35 ) ) {
F_263 ( & V_2 -> V_174 -> V_23 , L_59 ) ;
V_2 -> V_35 = NULL ;
}
F_34 ( V_2 -> V_35 ) ;
F_241 ( V_2 ) ;
F_264 ( & V_2 -> V_389 ) ;
V_2 -> V_253 = V_330 ;
F_265 ( & V_2 -> V_376 , F_190 ) ;
V_2 -> V_489 = F_262 ( & V_2 -> V_174 -> V_23 , L_60 ) ;
if ( F_254 ( V_2 -> V_489 ) ) {
F_263 ( & V_2 -> V_174 -> V_23 , L_61 ) ;
V_2 -> V_489 = NULL ;
}
V_2 -> V_124 = F_262 ( & V_2 -> V_174 -> V_23 , L_62 ) ;
if ( F_254 ( V_2 -> V_124 ) ) {
F_263 ( & V_2 -> V_174 -> V_23 , L_63 ) ;
V_2 -> V_124 = NULL ;
}
if ( V_462 && ! F_266 ( V_462 , L_64 , & V_470 ) &&
! strcasecmp ( V_470 , L_65 ) )
F_73 ( V_2 , V_144 ) ;
V_468 = F_154 ( V_2 ) ;
if ( V_468 )
goto V_405;
V_468 = F_267 ( V_23 ) ;
if ( V_468 )
goto V_405;
F_268 ( V_2 -> V_23 , V_2 -> V_8 -> V_80 + 1 ) ;
F_269 ( V_2 -> V_23 , V_2 -> V_8 -> V_81 + 1 ) ;
F_270 ( V_23 ) ;
F_36 ( V_2 -> V_35 ) ;
V_468 = F_271 ( V_23 ) ;
if ( V_468 )
goto V_468;
return V_468 ;
V_405:
F_36 ( V_2 -> V_35 ) ;
V_468:
F_272 ( V_23 ) ;
return V_468 ;
}
static int F_273 ( struct V_457 * V_174 )
{
struct V_1 * V_2 = F_22 ( & V_174 -> V_23 ) ;
F_257 ( & V_174 -> V_23 , NULL ) ;
F_274 ( V_2 -> V_23 ) ;
F_275 ( V_2 -> V_23 ) ;
F_272 ( V_2 -> V_23 ) ;
return 0 ;
}
static int F_276 ( struct V_22 * V_3 )
{
struct V_34 * V_23 = F_24 ( V_3 ) ;
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_60 ;
if ( ! F_38 ( V_23 ) )
return 0 ;
F_220 ( V_23 ) ;
if ( ! F_277 ( V_3 ) )
F_278 ( V_2 -> V_39 ) ;
F_279 ( V_23 ) ;
F_152 ( V_2 , V_403 , false ) ;
V_60 = F_183 ( V_2 ) ;
if ( V_60 )
return V_60 ;
F_152 ( V_2 , V_402 , false ) ;
F_109 ( V_23 ) ;
F_185 ( V_2 ) ;
if ( F_277 ( V_3 ) && V_2 -> V_490 ) {
V_60 = F_67 ( V_2 , V_143 ) ;
F_34 ( V_2 -> V_489 ) ;
} else if ( V_2 -> V_304 ) {
V_60 = F_67 ( V_2 , V_144 ) ;
}
F_36 ( V_2 -> V_35 ) ;
return V_60 ;
}
static int F_280 ( struct V_22 * V_3 )
{
struct V_34 * V_23 = F_24 ( V_3 ) ;
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned long V_344 ;
int V_60 ;
T_2 V_72 ;
if ( ! F_38 ( V_23 ) )
return 0 ;
V_60 = F_34 ( V_2 -> V_35 ) ;
if ( V_60 )
return V_60 ;
if ( V_2 -> V_304 )
F_73 ( V_2 , V_144 ) ;
F_205 ( V_2 ) ;
V_60 = F_159 ( V_2 ) ;
if ( V_60 )
goto V_491;
if ( V_2 -> V_490 )
F_36 ( V_2 -> V_489 ) ;
F_281 ( V_2 -> V_39 ) ;
F_282 ( V_2 -> V_23 ) ;
F_152 ( V_2 , V_402 | V_403 , false ) ;
F_206 ( V_2 , V_23 -> V_407 ) ;
if ( V_2 -> V_304 ) {
V_72 = F_70 ( V_2 , V_146 ) ;
V_72 |= V_408 ;
F_71 ( V_2 , V_72 , V_146 ) ;
}
if ( V_2 -> V_490 )
F_73 ( V_2 , V_143 ) ;
V_344 = F_207 ( V_2 ) ;
V_60 = F_188 ( V_2 ) ;
if ( V_60 ) {
F_135 ( V_23 , L_26 ) ;
goto V_491;
}
F_208 ( V_2 , V_344 ) ;
F_283 ( V_23 ) ;
if ( ! F_277 ( V_3 ) )
F_284 ( V_2 -> V_39 ) ;
if ( V_2 -> V_132 . V_133 )
F_60 ( V_23 , true ) ;
F_213 ( V_23 ) ;
return 0 ;
V_491:
if ( V_2 -> V_304 )
F_67 ( V_2 , V_144 ) ;
F_36 ( V_2 -> V_35 ) ;
return V_60 ;
}
