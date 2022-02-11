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
static int F_33 ( struct V_34 * V_23 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
if ( ! F_34 ( V_23 ) )
return - V_37 ;
if ( ! V_2 -> V_38 )
return - V_39 ;
return F_35 ( V_2 -> V_38 , V_36 ) ;
}
static int F_36 ( struct V_34 * V_23 ,
const struct V_35 * V_36 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
if ( ! F_34 ( V_23 ) )
return - V_37 ;
if ( ! V_2 -> V_38 )
return - V_39 ;
return F_37 ( V_2 -> V_38 , V_36 ) ;
}
static int F_38 ( struct V_34 * V_23 ,
T_4 V_40 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_41 ;
bool V_42 ;
V_42 = ! ! ( V_40 & V_43 ) ;
V_41 = F_13 ( V_2 , V_44 ) ;
if ( V_42 )
V_41 |= V_45 ;
else
V_41 &= ~ V_45 ;
V_2 -> V_46 = V_42 ;
if ( V_42 && V_2 -> V_47 )
V_41 |= V_48 ;
else
V_41 &= ~ V_48 ;
F_16 ( V_2 , V_41 , V_44 ) ;
return 0 ;
}
static int F_39 ( struct V_34 * V_23 ,
T_4 V_40 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
bool V_49 ;
T_2 V_50 , V_51 ;
V_50 = F_18 ( V_2 ) ;
V_51 = F_13 ( V_2 , V_52 ) ;
V_49 = ! ! ( V_40 & ( V_53 | V_54 ) ) ;
if ( V_49 ) {
V_50 |= V_55 ;
V_51 |= V_55 ;
} else {
V_50 &= ~ V_55 ;
V_51 &= ~ V_55 ;
}
V_2 -> V_49 = V_49 ;
F_19 ( V_2 , V_50 ) ;
F_16 ( V_2 , V_51 , V_52 ) ;
return 0 ;
}
static int F_40 ( struct V_34 * V_23 ,
T_4 V_56 )
{
T_4 V_57 = V_56 ^ V_23 -> V_56 ;
T_4 V_40 = V_23 -> V_58 ;
int V_59 = 0 ;
if ( V_57 & ( V_53 | V_54 ) )
V_59 = F_39 ( V_23 , V_40 ) ;
if ( V_57 & ( V_43 ) )
V_59 = F_38 ( V_23 , V_40 ) ;
return V_59 ;
}
static T_2 F_41 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
return V_2 -> V_60 ;
}
static void F_42 ( struct V_34 * V_23 , T_2 V_61 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
V_2 -> V_60 = V_61 ;
}
static int F_43 ( struct V_34 * V_23 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
V_63 -> V_64 =
F_29 ( V_2 , V_65 ,
V_66 ) ;
V_63 -> V_67 =
F_31 ( V_2 , V_65 ,
V_66 ) ;
V_63 -> V_68 =
F_27 ( V_2 , V_69 ) * 8192 / 1000 ;
return 0 ;
}
static int F_44 ( struct V_34 * V_23 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned int V_70 ;
T_2 V_71 ;
if ( V_63 -> V_64 > V_72 ||
V_63 -> V_64 == 0 ||
V_63 -> V_67 > V_72 ||
V_63 -> V_68 > ( V_73 * 8 ) + 1 )
return - V_37 ;
if ( V_63 -> V_68 == 0 && V_63 -> V_67 == 0 )
return - V_37 ;
if ( V_63 -> V_74 || V_63 -> V_75 ||
V_63 -> V_76 || V_63 -> V_77 )
return - V_78 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_79 ; V_70 ++ )
F_30 ( V_2 , V_70 ,
V_63 -> V_64 ,
V_66 ) ;
F_30 ( V_2 , V_65 ,
V_63 -> V_64 ,
V_66 ) ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_80 ; V_70 ++ ) {
F_32 ( V_2 , V_70 ,
V_63 -> V_67 ,
V_66 ) ;
V_71 = F_27 ( V_2 , V_81 + V_70 ) ;
V_71 &= ~ V_73 ;
V_71 |= F_45 ( V_63 -> V_68 * 1000 , 8192 ) ;
F_28 ( V_2 , V_71 , V_81 + V_70 ) ;
}
F_32 ( V_2 , V_65 ,
V_63 -> V_67 ,
V_66 ) ;
V_71 = F_27 ( V_2 , V_69 ) ;
V_71 &= ~ V_73 ;
V_71 |= F_45 ( V_63 -> V_68 * 1000 , 8192 ) ;
F_28 ( V_2 , V_71 , V_69 ) ;
return 0 ;
}
static void F_46 ( struct V_34 * V_23 ,
struct V_82 * V_83 )
{
F_47 ( V_83 -> V_84 , L_1 , sizeof( V_83 -> V_84 ) ) ;
F_47 ( V_83 -> V_85 , L_2 , sizeof( V_83 -> V_85 ) ) ;
}
static int F_48 ( struct V_34 * V_23 , int V_86 )
{
switch ( V_86 ) {
case V_87 :
return V_88 ;
default:
return - V_78 ;
}
}
static void F_49 ( struct V_34 * V_23 , T_2 V_89 ,
T_5 * V_90 )
{
int V_70 ;
switch ( V_89 ) {
case V_87 :
for ( V_70 = 0 ; V_70 < V_88 ; V_70 ++ ) {
memcpy ( V_90 + V_70 * V_91 ,
V_92 [ V_70 ] . V_93 ,
V_91 ) ;
}
break;
}
}
static void F_50 ( struct V_1 * V_2 )
{
int V_70 , V_94 = 0 ;
for ( V_70 = 0 ; V_70 < V_88 ; V_70 ++ ) {
const struct V_95 * V_96 ;
T_5 V_97 = 0 ;
T_2 V_12 = 0 ;
char * V_98 ;
V_96 = & V_92 [ V_70 ] ;
switch ( V_96 -> type ) {
case V_99 :
case V_100 :
continue;
case V_101 :
case V_102 :
case V_103 :
if ( V_96 -> type != V_101 )
V_97 = V_104 ;
V_12 = F_51 ( V_2 ,
V_105 + V_94 + V_97 ) ;
break;
case V_106 :
V_12 = F_51 ( V_2 , V_96 -> V_107 ) ;
if ( V_12 == ~ 0 )
F_52 ( V_2 , 0 , V_96 -> V_107 ) ;
break;
}
V_94 += V_96 -> V_108 ;
V_98 = ( char * ) V_2 + V_96 -> V_109 ;
* ( T_2 * ) V_98 = V_12 ;
}
}
static void F_53 ( struct V_34 * V_23 ,
struct V_110 * V_111 ,
V_13 * V_90 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_70 ;
if ( F_34 ( V_23 ) )
F_50 ( V_2 ) ;
for ( V_70 = 0 ; V_70 < V_88 ; V_70 ++ ) {
const struct V_95 * V_96 ;
char * V_98 ;
V_96 = & V_92 [ V_70 ] ;
if ( V_96 -> type == V_99 )
V_98 = ( char * ) & V_23 -> V_111 ;
else
V_98 = ( char * ) V_2 ;
V_98 += V_96 -> V_109 ;
if (sizeof( unsigned long ) != sizeof( T_2 ) &&
V_96 -> V_108 == sizeof( unsigned long ) )
V_90 [ V_70 ] = * ( unsigned long * ) V_98 ;
else
V_90 [ V_70 ] = * ( T_2 * ) V_98 ;
}
}
static void F_54 ( struct V_34 * V_23 , bool V_112 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_113 = V_2 -> V_8 -> V_18 + V_114 ;
T_2 V_71 ;
if ( V_112 && ! V_2 -> V_115 ) {
F_55 ( V_2 -> V_116 ) ;
V_2 -> V_115 = true ;
}
V_71 = F_51 ( V_2 , V_117 ) ;
if ( V_112 )
V_71 |= V_118 ;
else
V_71 &= ~ V_118 ;
F_52 ( V_2 , V_71 , V_117 ) ;
V_71 = F_4 ( V_2 -> V_17 + V_113 ) ;
if ( V_112 )
V_71 |= V_119 | V_120 ;
else
V_71 &= ~ ( V_119 | V_120 ) ;
F_2 ( V_71 , V_2 -> V_17 + V_113 ) ;
V_71 = F_13 ( V_2 , V_121 ) ;
if ( V_112 )
V_71 |= V_122 | V_123 ;
else
V_71 &= ~ ( V_122 | V_123 ) ;
F_16 ( V_2 , V_71 , V_121 ) ;
if ( ! V_112 && V_2 -> V_115 ) {
F_56 ( V_2 -> V_116 ) ;
V_2 -> V_115 = false ;
}
V_2 -> V_124 . V_125 = V_112 ;
V_2 -> V_124 . V_126 = V_112 ;
}
static int F_57 ( struct V_34 * V_23 , struct V_127 * V_128 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_127 * V_98 = & V_2 -> V_124 ;
if ( F_12 ( V_2 ) )
return - V_78 ;
V_128 -> V_125 = V_98 -> V_125 ;
V_128 -> V_126 = V_98 -> V_126 ;
V_128 -> V_129 = F_51 ( V_2 , V_130 ) ;
return F_58 ( V_2 -> V_38 , V_128 ) ;
}
static int F_59 ( struct V_34 * V_23 , struct V_127 * V_128 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_127 * V_98 = & V_2 -> V_124 ;
int V_59 = 0 ;
if ( F_12 ( V_2 ) )
return - V_78 ;
V_98 -> V_125 = V_128 -> V_125 ;
if ( ! V_98 -> V_125 ) {
F_54 ( V_23 , false ) ;
} else {
V_59 = F_60 ( V_2 -> V_38 , 0 ) ;
if ( V_59 ) {
F_61 ( V_2 , V_131 , V_23 , L_3 ) ;
return V_59 ;
}
F_52 ( V_2 , V_128 -> V_129 , V_130 ) ;
F_54 ( V_23 , true ) ;
}
return F_62 ( V_2 -> V_38 , V_128 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
enum V_132 V_133 )
{
int V_59 = 0 ;
T_2 V_71 ;
switch ( V_133 ) {
case V_134 :
F_64 ( V_2 -> V_38 ) ;
break;
case V_135 :
V_59 = F_65 ( V_2 , V_133 ) ;
break;
case V_136 :
if ( V_2 -> V_8 -> V_9 & V_137 ) {
V_71 = F_66 ( V_2 , V_138 ) ;
V_71 |= ( V_139 |
V_140 | V_141 ) ;
F_67 ( V_2 , V_71 , V_138 ) ;
F_68 ( V_2 -> V_23 , false ) ;
}
break;
default:
break;
}
return 0 ;
}
static void F_69 ( struct V_1 * V_2 ,
enum V_132 V_133 )
{
T_2 V_71 ;
if ( ! ( V_2 -> V_8 -> V_9 & V_137 ) )
return;
V_71 = F_66 ( V_2 , V_138 ) ;
switch ( V_133 ) {
case V_136 :
V_71 &= ~ ( V_140 | V_139 |
V_141 ) ;
case V_134 :
V_71 |= V_142 ;
break;
case V_135 :
F_70 ( V_2 , V_133 ) ;
return;
default:
break;
}
F_67 ( V_2 , V_71 , V_138 ) ;
if ( V_133 == V_136 ) {
F_68 ( V_2 -> V_23 , true ) ;
F_71 ( V_2 -> V_23 ) ;
}
}
static int F_72 ( struct V_34 * V_23 , struct V_143 * V_144 , int V_36 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_12 = 0 ;
if ( ! F_34 ( V_23 ) )
return - V_37 ;
switch ( V_36 ) {
case V_145 :
case V_146 :
case V_147 :
if ( ! V_2 -> V_38 )
V_12 = - V_39 ;
else
V_12 = F_73 ( V_2 -> V_38 , V_144 , V_36 ) ;
break;
default:
V_12 = - V_37 ;
break;
}
return V_12 ;
}
static struct V_148 * F_74 ( struct V_1 * V_2 ,
struct V_149 * V_30 )
{
struct V_148 * V_150 ;
V_150 = V_30 -> V_151 ;
V_150 += V_30 -> V_152 - V_30 -> V_153 ;
if ( V_30 -> V_152 == V_30 -> V_154 )
V_30 -> V_152 = V_30 -> V_153 ;
else
V_30 -> V_152 ++ ;
return V_150 ;
}
static void F_75 ( struct V_148 * V_155 )
{
F_76 ( V_155 -> V_156 ) ;
V_155 -> V_156 = NULL ;
F_77 ( V_155 , V_157 , 0 ) ;
}
static inline void F_78 ( struct V_158 * V_30 )
{
F_79 ( V_30 -> V_2 , V_159 ,
V_160 ) ;
}
static inline void F_80 ( struct V_158 * V_30 )
{
F_79 ( V_30 -> V_2 , V_159 ,
V_161 ) ;
}
static inline void F_81 ( struct V_158 * V_30 )
{
F_82 ( V_30 -> V_2 ,
1 << ( V_162 + V_30 -> V_163 ) ,
V_160 ) ;
}
static inline void F_83 ( struct V_158 * V_30 )
{
F_82 ( V_30 -> V_2 ,
1 << ( V_162 + V_30 -> V_163 ) ,
V_161 ) ;
}
static inline void F_84 ( struct V_149 * V_30 )
{
F_79 ( V_30 -> V_2 , V_164 ,
V_160 ) ;
}
static inline void F_85 ( struct V_149 * V_30 )
{
F_79 ( V_30 -> V_2 , V_164 ,
V_161 ) ;
}
static inline void F_86 ( struct V_149 * V_30 )
{
F_82 ( V_30 -> V_2 , 1 << V_30 -> V_163 ,
V_161 ) ;
}
static inline void F_87 ( struct V_149 * V_30 )
{
F_82 ( V_30 -> V_2 , 1 << V_30 -> V_163 ,
V_160 ) ;
}
static unsigned int F_88 ( struct V_34 * V_23 ,
struct V_149 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_22 * V_165 = & V_2 -> V_166 -> V_23 ;
struct V_148 * V_150 ;
struct V_167 * V_168 ;
unsigned int V_169 = 0 ;
unsigned int V_170 = 0 ;
unsigned int V_171 ;
unsigned int V_172 ;
unsigned int V_173 = 0 ;
V_171 = F_29 ( V_2 , V_30 -> V_163 , V_174 ) ;
V_171 &= V_175 ;
if ( F_89 ( V_171 >= V_30 -> V_171 ) )
V_172 = V_171 - V_30 -> V_171 ;
else
V_172 = ( V_175 + 1 ) - V_30 -> V_171 + V_171 ;
F_90 ( V_2 , V_176 , V_23 ,
L_4 ,
V_177 , V_30 -> V_163 , V_30 -> V_171 , V_171 , V_172 ) ;
while ( V_173 < V_172 ) {
V_150 = & V_2 -> V_178 [ V_30 -> V_179 ] ;
if ( V_150 -> V_156 ) {
V_169 ++ ;
V_170 += F_91 ( V_150 -> V_156 ) -> V_180 ;
F_92 ( V_165 ,
F_93 ( V_150 , V_157 ) ,
F_94 ( V_150 , V_181 ) ,
V_182 ) ;
F_75 ( V_150 ) ;
} else if ( F_93 ( V_150 , V_157 ) ) {
F_95 ( V_165 ,
F_93 ( V_150 , V_157 ) ,
F_94 ( V_150 , V_181 ) ,
V_182 ) ;
F_77 ( V_150 , V_157 , 0 ) ;
}
V_173 ++ ;
if ( F_89 ( V_30 -> V_179 < V_30 -> V_154 ) )
V_30 -> V_179 ++ ;
else
V_30 -> V_179 = V_30 -> V_153 ;
}
V_30 -> V_183 += V_173 ;
V_30 -> V_171 = ( V_30 -> V_171 + V_173 ) & V_175 ;
V_23 -> V_111 . V_184 += V_169 ;
V_23 -> V_111 . V_185 += V_170 ;
V_168 = F_96 ( V_23 , V_30 -> V_186 ) ;
F_97 ( V_168 , V_169 , V_170 ) ;
if ( V_30 -> V_183 > ( V_187 + 1 ) ) {
if ( F_98 ( V_168 ) )
F_99 ( V_168 ) ;
}
return V_169 ;
}
static unsigned int F_100 ( struct V_34 * V_23 ,
struct V_149 * V_30 )
{
unsigned int V_188 ;
unsigned long V_9 ;
F_101 ( & V_30 -> V_189 , V_9 ) ;
V_188 = F_88 ( V_23 , V_30 ) ;
F_102 ( & V_30 -> V_189 , V_9 ) ;
return V_188 ;
}
static int F_103 ( struct V_190 * V_191 , int V_192 )
{
struct V_149 * V_30 =
F_104 ( V_191 , struct V_149 , V_191 ) ;
unsigned int V_193 = 0 ;
V_193 = F_100 ( V_30 -> V_2 -> V_23 , V_30 ) ;
if ( V_193 == 0 ) {
F_105 ( V_191 ) ;
V_30 -> V_194 ( V_30 ) ;
return 0 ;
}
return V_192 ;
}
static void F_106 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_70 ;
if ( F_107 ( V_23 ) ) {
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_79 ; V_70 ++ )
F_100 ( V_23 , & V_2 -> V_195 [ V_70 ] ) ;
}
F_100 ( V_23 , & V_2 -> V_195 [ V_65 ] ) ;
}
static int F_108 ( struct V_34 * V_23 ,
struct V_196 * V_156 ,
T_6 V_197 ,
struct V_149 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_22 * V_165 = & V_2 -> V_166 -> V_23 ;
struct V_148 * V_150 ;
unsigned int V_198 ;
T_3 V_199 ;
T_2 V_200 ;
int V_59 ;
V_150 = F_74 ( V_2 , V_30 ) ;
if ( F_109 ( ! V_150 ) )
F_110 () ;
V_150 -> V_156 = V_156 ;
V_198 = F_111 ( V_156 ) ;
V_199 = F_112 ( V_165 , V_156 -> V_90 , V_198 , V_182 ) ;
V_59 = F_113 ( V_165 , V_199 ) ;
if ( V_59 ) {
V_2 -> V_201 . V_202 ++ ;
F_61 ( V_2 , V_203 , V_23 , L_5 ) ;
F_114 ( V_156 ) ;
return V_59 ;
}
F_77 ( V_150 , V_157 , V_199 ) ;
F_115 ( V_150 , V_181 , V_198 ) ;
V_200 = ( V_198 << V_204 ) | V_197 |
( V_2 -> V_8 -> V_205 << V_206 ) |
V_207 ;
if ( V_156 -> V_208 == V_209 )
V_200 |= V_210 ;
F_9 ( V_2 , V_150 -> V_211 , V_199 , V_200 ) ;
return 0 ;
}
static int F_116 ( struct V_34 * V_23 ,
T_7 * V_212 ,
T_6 V_197 ,
struct V_149 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_22 * V_165 = & V_2 -> V_166 -> V_23 ;
struct V_148 * V_150 ;
unsigned int V_213 ;
T_3 V_199 ;
int V_59 ;
V_150 = F_74 ( V_2 , V_30 ) ;
if ( F_109 ( ! V_150 ) )
F_110 () ;
V_150 -> V_156 = NULL ;
V_213 = F_117 ( V_212 ) ;
V_199 = F_118 ( V_165 , V_212 , 0 , V_213 , V_182 ) ;
V_59 = F_113 ( V_165 , V_199 ) ;
if ( V_59 ) {
V_2 -> V_201 . V_202 ++ ;
F_61 ( V_2 , V_203 , V_23 , L_6 ,
V_177 ) ;
return V_59 ;
}
F_77 ( V_150 , V_157 , V_199 ) ;
F_115 ( V_150 , V_181 , V_213 ) ;
F_9 ( V_2 , V_150 -> V_211 , V_199 ,
( V_213 << V_204 ) | V_197 |
( V_2 -> V_8 -> V_205 << V_206 ) ) ;
return 0 ;
}
static struct V_196 * F_119 ( struct V_34 * V_23 ,
struct V_196 * V_156 )
{
struct V_214 * V_215 = NULL ;
struct V_196 * V_216 ;
T_6 V_97 ;
T_5 V_217 ;
T_6 V_218 ;
T_2 V_219 ;
if ( F_109 ( F_120 ( V_156 ) < sizeof( * V_215 ) ) ) {
V_216 = F_121 ( V_156 , sizeof( * V_215 ) ) ;
F_114 ( V_156 ) ;
if ( ! V_216 ) {
V_23 -> V_111 . V_220 ++ ;
return NULL ;
}
V_156 = V_216 ;
}
F_122 ( V_156 , sizeof( * V_215 ) ) ;
V_215 = (struct V_214 * ) V_156 -> V_90 ;
if ( V_156 -> V_208 == V_209 ) {
V_218 = F_123 ( V_156 -> V_221 ) ;
switch ( V_218 ) {
case V_222 :
V_217 = F_124 ( V_156 ) -> V_221 ;
break;
case V_223 :
V_217 = F_125 ( V_156 ) -> V_224 ;
break;
default:
return V_156 ;
}
V_97 = F_126 ( V_156 ) - sizeof( * V_215 ) ;
V_219 = ( V_97 << V_225 ) |
( V_97 + V_156 -> V_226 ) ;
if ( V_217 == V_227 || V_217 == V_228 ) {
V_219 |= V_229 ;
if ( V_217 == V_228 && V_218 == V_222 )
V_219 |= V_230 ;
} else {
V_219 = 0 ;
}
V_215 -> V_219 = V_219 ;
}
return V_156 ;
}
static T_8 F_127 ( struct V_196 * V_156 , struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_149 * V_30 = NULL ;
struct V_167 * V_168 ;
unsigned long V_9 = 0 ;
int V_231 , V_163 ;
T_6 V_197 ;
int V_59 ;
int V_70 ;
V_163 = F_128 ( V_156 ) ;
if ( V_163 == 0 )
V_163 = V_65 ;
else
V_163 -= 1 ;
V_30 = & V_2 -> V_195 [ V_163 ] ;
V_168 = F_96 ( V_23 , V_30 -> V_186 ) ;
V_231 = F_129 ( V_156 ) -> V_231 ;
F_101 ( & V_30 -> V_189 , V_9 ) ;
if ( V_30 -> V_183 <= ( V_231 + 1 ) ) {
if ( ! F_98 ( V_168 ) ) {
F_130 ( V_168 ) ;
F_131 ( V_23 ,
L_7 ,
V_177 , V_163 , V_30 -> V_186 ) ;
}
V_59 = V_232 ;
goto V_233;
}
if ( F_132 ( V_156 , V_234 ) ) {
V_59 = V_235 ;
goto V_233;
}
F_91 ( V_156 ) -> V_180 = V_156 -> V_236 ;
if ( V_2 -> V_49 ) {
V_156 = F_119 ( V_23 , V_156 ) ;
if ( ! V_156 ) {
V_59 = V_235 ;
goto V_233;
}
}
V_197 = V_237 ;
if ( V_231 == 0 )
V_197 |= V_238 ;
V_59 = F_108 ( V_23 , V_156 , V_197 , V_30 ) ;
if ( V_59 ) {
V_59 = V_235 ;
goto V_233;
}
for ( V_70 = 0 ; V_70 < V_231 ; V_70 ++ ) {
V_59 = F_116 ( V_23 ,
& F_129 ( V_156 ) -> V_239 [ V_70 ] ,
( V_70 == V_231 - 1 ) ? V_238 : 0 ,
V_30 ) ;
if ( V_59 ) {
V_59 = V_235 ;
goto V_233;
}
}
F_133 ( V_156 ) ;
V_30 -> V_183 -= V_231 + 1 ;
V_30 -> V_240 += V_231 + 1 ;
V_30 -> V_240 &= V_241 ;
F_134 ( V_168 , F_91 ( V_156 ) -> V_180 ) ;
if ( V_30 -> V_183 <= ( V_187 + 1 ) )
F_130 ( V_168 ) ;
if ( ! V_156 -> V_242 || F_135 ( V_168 ) )
F_30 ( V_2 , V_30 -> V_163 ,
V_30 -> V_240 , V_243 ) ;
V_233:
F_102 ( & V_30 -> V_189 , V_9 ) ;
return V_59 ;
}
static struct V_196 * F_136 ( struct V_1 * V_2 ,
struct V_148 * V_155 )
{
struct V_22 * V_165 = & V_2 -> V_166 -> V_23 ;
struct V_196 * V_156 ;
struct V_196 * V_244 ;
T_3 V_199 ;
V_156 = F_137 ( V_2 -> V_23 , V_2 -> V_245 + V_246 ) ;
if ( ! V_156 ) {
V_2 -> V_201 . V_247 ++ ;
F_61 ( V_2 , V_248 , V_2 -> V_23 ,
L_8 , V_177 ) ;
return NULL ;
}
V_199 = F_112 ( V_165 , V_156 -> V_90 , V_2 -> V_245 ,
V_249 ) ;
if ( F_113 ( V_165 , V_199 ) ) {
V_2 -> V_201 . V_250 ++ ;
F_76 ( V_156 ) ;
F_61 ( V_2 , V_248 , V_2 -> V_23 ,
L_9 , V_177 ) ;
return NULL ;
}
V_244 = V_155 -> V_156 ;
if ( F_89 ( V_244 ) )
F_92 ( V_165 , F_93 ( V_155 , V_157 ) ,
V_2 -> V_245 , V_249 ) ;
V_155 -> V_156 = V_156 ;
F_77 ( V_155 , V_157 , V_199 ) ;
F_5 ( V_2 , V_155 -> V_211 , V_199 ) ;
return V_244 ;
}
static unsigned int F_138 ( struct V_158 * V_30 ,
unsigned int V_192 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_34 * V_23 = V_2 -> V_23 ;
struct V_148 * V_155 ;
struct V_196 * V_156 ;
T_2 V_251 ;
unsigned long V_252 ;
int V_236 ;
unsigned int V_253 = 0 , V_254 ;
unsigned int V_255 ;
unsigned int V_256 ;
unsigned int V_257 = 0 ;
V_255 = F_31 ( V_2 , V_30 -> V_163 , V_258 ) ;
V_256 = ( V_255 >> V_259 ) &
V_260 ;
if ( V_256 > V_30 -> V_261 ) {
V_256 = V_256 - V_30 -> V_261 ;
V_23 -> V_111 . V_262 += V_256 ;
V_23 -> V_111 . V_263 += V_256 ;
V_30 -> V_261 += V_256 ;
if ( V_30 -> V_261 >= 0xC000 ) {
V_30 -> V_261 = 0 ;
F_32 ( V_2 , V_30 -> V_163 , 0 ,
V_258 ) ;
}
}
V_255 &= V_241 ;
if ( F_89 ( V_255 >= V_30 -> V_171 ) )
V_254 = V_255 - V_30 -> V_171 ;
else
V_254 = ( V_175 + 1 ) - V_30 -> V_171 +
V_255 ;
F_90 ( V_2 , V_264 , V_23 ,
L_10 , V_254 ) ;
while ( ( V_253 < V_254 ) &&
( V_253 < V_192 ) ) {
V_155 = & V_2 -> V_265 [ V_30 -> V_266 ] ;
V_156 = F_136 ( V_2 , V_155 ) ;
if ( F_109 ( ! V_156 ) ) {
V_23 -> V_111 . V_267 ++ ;
goto V_268;
}
if ( ! V_2 -> V_49 ) {
V_251 =
F_3 ( V_2 , V_155 -> V_211 ) ;
} else {
struct V_214 * V_215 ;
V_215 = (struct V_214 * ) V_156 -> V_90 ;
V_251 = V_215 -> V_200 ;
}
V_252 = V_251 & 0xffff ;
V_236 = V_251 >> V_204 ;
F_90 ( V_2 , V_264 , V_23 ,
L_11 ,
V_177 , V_255 , V_30 -> V_171 ,
V_30 -> V_266 , V_251 ) ;
if ( F_109 ( ! ( V_252 & V_238 ) || ! ( V_252 & V_237 ) ) ) {
F_61 ( V_2 , V_264 , V_23 ,
L_12 ) ;
V_23 -> V_111 . V_263 ++ ;
F_76 ( V_156 ) ;
goto V_268;
}
if ( F_109 ( V_252 & ( V_269 |
V_270 |
V_271 |
V_272 |
V_273 ) ) ) {
F_61 ( V_2 , V_264 , V_23 , L_13 ,
( unsigned int ) V_252 ) ;
if ( V_252 & V_269 )
V_23 -> V_111 . V_274 ++ ;
if ( V_252 & V_270 )
V_23 -> V_111 . V_275 ++ ;
if ( V_252 & V_271 )
V_23 -> V_111 . V_276 ++ ;
if ( V_252 & V_272 )
V_23 -> V_111 . V_277 ++ ;
V_23 -> V_111 . V_263 ++ ;
F_76 ( V_156 ) ;
goto V_268;
}
V_257 = ( V_252 & V_2 -> V_278 ) &&
V_2 -> V_46 ;
F_139 ( V_156 , V_236 ) ;
if ( V_2 -> V_49 ) {
F_140 ( V_156 , 64 ) ;
V_236 -= 64 ;
}
if ( F_89 ( V_257 ) )
V_156 -> V_208 = V_279 ;
F_140 ( V_156 , 2 ) ;
V_236 -= 2 ;
if ( V_2 -> V_47 ) {
F_141 ( V_156 , V_236 - V_280 ) ;
V_236 -= V_280 ;
}
V_156 -> V_221 = F_142 ( V_156 , V_2 -> V_23 ) ;
V_23 -> V_111 . V_281 ++ ;
V_23 -> V_111 . V_282 += V_236 ;
if ( V_252 & V_283 )
V_23 -> V_111 . V_284 ++ ;
F_143 ( & V_30 -> V_191 , V_156 ) ;
F_90 ( V_2 , V_264 , V_23 , L_14 ) ;
V_268:
V_253 ++ ;
if ( F_89 ( V_30 -> V_266 < V_30 -> V_154 ) )
V_30 -> V_266 ++ ;
else
V_30 -> V_266 = V_30 -> V_153 ;
V_30 -> V_171 = ( V_30 -> V_171 + 1 ) & V_175 ;
F_32 ( V_2 , V_30 -> V_163 , V_30 -> V_171 , V_285 ) ;
}
return V_253 ;
}
static int F_144 ( struct V_190 * V_191 , int V_192 )
{
struct V_158 * V_30 = F_104 ( V_191 ,
struct V_158 , V_191 ) ;
unsigned int V_193 ;
V_193 = F_138 ( V_30 , V_192 ) ;
if ( V_193 < V_192 ) {
F_145 ( V_191 , V_193 ) ;
V_30 -> V_194 ( V_30 ) ;
}
return V_193 ;
}
static int F_146 ( struct V_1 * V_2 ,
struct V_158 * V_30 )
{
struct V_148 * V_155 ;
struct V_196 * V_156 ;
int V_70 ;
F_90 ( V_2 , V_131 , V_2 -> V_23 , L_15 , V_177 ) ;
for ( V_70 = 0 ; V_70 < V_30 -> V_286 ; V_70 ++ ) {
V_155 = V_30 -> V_151 + V_70 ;
V_156 = F_136 ( V_2 , V_155 ) ;
if ( V_156 )
F_76 ( V_156 ) ;
if ( ! V_155 -> V_156 )
return - V_287 ;
}
return 0 ;
}
static void F_147 ( struct V_1 * V_2 )
{
struct V_22 * V_165 = & V_2 -> V_166 -> V_23 ;
struct V_148 * V_155 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_288 ; V_70 ++ ) {
V_155 = & V_2 -> V_265 [ V_70 ] ;
if ( F_93 ( V_155 , V_157 ) ) {
F_92 ( V_165 ,
F_93 ( V_155 , V_157 ) ,
V_2 -> V_245 , V_249 ) ;
F_77 ( V_155 , V_157 , 0 ) ;
}
if ( V_155 -> V_156 )
F_75 ( V_155 ) ;
}
}
static void F_148 ( struct V_1 * V_2 , T_2 V_289 , bool V_112 )
{
T_2 V_71 ;
V_71 = F_51 ( V_2 , V_290 ) ;
if ( V_112 )
V_71 |= V_289 ;
else
V_71 &= ~ V_289 ;
F_52 ( V_2 , V_71 , V_290 ) ;
if ( V_112 == 0 )
F_149 ( 1000 , 2000 ) ;
}
static int F_150 ( struct V_1 * V_2 )
{
struct V_22 * V_165 = & V_2 -> V_166 -> V_23 ;
unsigned int V_291 = 0 ;
T_2 V_71 ;
F_15 ( V_2 , 0 ) ;
F_151 ( 10 ) ;
F_52 ( V_2 , 0 , V_290 ) ;
F_52 ( V_2 , V_292 , V_290 ) ;
while ( V_291 ++ < 1000 ) {
V_71 = F_51 ( V_2 , V_290 ) ;
if ( ! ( V_71 & V_292 ) )
return 0 ;
F_151 ( 1 ) ;
}
if ( V_291 == 1000 ) {
F_152 ( V_165 ,
L_16 ) ;
return - V_293 ;
}
return 0 ;
}
static void F_153 ( struct V_1 * V_2 )
{
F_79 ( V_2 , 0xFFFFFFFF , V_160 ) ;
F_79 ( V_2 , 0xFFFFFFFF , V_294 ) ;
F_79 ( V_2 , 0 , V_161 ) ;
F_82 ( V_2 , 0xFFFFFFFF , V_160 ) ;
F_82 ( V_2 , 0xFFFFFFFF , V_294 ) ;
F_82 ( V_2 , 0 , V_161 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
T_2 V_295 = 0 ;
if ( V_2 -> V_296 ) {
V_295 |= V_297 ;
} else if ( V_2 -> V_298 ) {
V_295 |= V_297 ;
} else if ( V_2 -> V_299 == V_300 ) {
if ( V_2 -> V_8 -> V_9 & V_301 )
V_295 |= V_297 ;
}
F_79 ( V_2 , V_295 , V_161 ) ;
}
static int F_155 ( struct V_1 * V_2 )
{
struct V_22 * V_165 = & V_2 -> V_166 -> V_23 ;
int V_59 ;
T_2 V_71 ;
T_2 V_295 = 0 ;
T_2 V_302 = 0 ;
int V_70 ;
F_156 ( & V_2 -> V_166 -> V_23 , L_17 ) ;
V_59 = F_150 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_52 ( V_2 , 0 , V_290 ) ;
F_52 ( V_2 ,
V_303 | V_304 | V_305 ,
V_306 ) ;
F_52 ( V_2 , 0 , V_306 ) ;
F_52 ( V_2 , V_307 , V_308 ) ;
V_71 = F_13 ( V_2 , V_52 ) ;
V_71 |= V_309 ;
F_16 ( V_2 , V_71 , V_52 ) ;
if ( ! F_12 ( V_2 ) && ! F_157 ( V_2 ) )
F_16 ( V_2 , 1 , V_310 ) ;
F_153 ( V_2 ) ;
V_295 |= V_159 ;
V_295 |= V_164 ;
if ( V_2 -> V_299 == V_300 ) {
V_71 = F_20 ( V_2 ) ;
V_71 |= F_158 ( V_2 -> V_8 -> V_311 ) ;
if ( F_107 ( V_2 -> V_23 ) )
V_71 |= V_2 -> V_8 -> V_312 ;
else
V_71 &= ~ V_2 -> V_8 -> V_312 ;
F_21 ( V_2 , V_71 ) ;
}
if ( V_2 -> V_8 -> V_9 & V_313 )
V_295 |= ( V_314 | V_315 ) ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_80 ; ++ V_70 )
V_302 |= ( 1 << ( V_162 + V_70 ) ) ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_79 ; ++ V_70 )
V_302 |= ( 1 << V_70 ) ;
F_79 ( V_2 , V_295 , V_161 ) ;
F_82 ( V_2 , V_302 , V_161 ) ;
F_156 ( V_165 , L_18 ) ;
return 0 ;
}
static void F_159 ( struct V_1 * V_2 ,
unsigned int V_163 , unsigned int V_286 ,
unsigned int V_316 , unsigned int V_154 )
{
struct V_149 * V_30 = & V_2 -> V_195 [ V_163 ] ;
T_2 V_317 = F_160 ( V_2 ) ;
T_2 V_318 = 0 ;
F_161 ( & V_30 -> V_189 ) ;
V_30 -> V_2 = V_2 ;
V_30 -> V_163 = V_163 ;
if ( V_163 == V_65 ) {
V_30 -> V_186 = 0 ;
V_30 -> V_194 = F_85 ;
V_30 -> V_319 = F_84 ;
} else {
V_30 -> V_186 = V_163 + 1 ;
V_30 -> V_194 = F_86 ;
V_30 -> V_319 = F_87 ;
}
V_30 -> V_151 = V_2 -> V_178 + V_316 ;
V_30 -> V_286 = V_286 ;
V_30 -> V_179 = V_316 ;
V_30 -> V_171 = 0 ;
V_30 -> V_183 = V_286 ;
V_30 -> V_152 = V_316 ;
V_30 -> V_153 = V_316 ;
V_30 -> V_154 = V_154 - 1 ;
V_30 -> V_240 = 0 ;
if ( V_163 != V_65 )
V_318 = V_307 << 16 ;
F_30 ( V_2 , V_163 , 0 , V_243 ) ;
F_30 ( V_2 , V_163 , 0 , V_174 ) ;
F_30 ( V_2 , V_163 , 1 , V_66 ) ;
F_30 ( V_2 , V_163 , V_318 ,
V_320 ) ;
F_30 ( V_2 , V_163 ,
( ( V_286 << V_321 ) |
V_322 ) , V_323 ) ;
F_30 ( V_2 , V_163 , V_316 * V_317 ,
V_324 ) ;
F_30 ( V_2 , V_163 , V_316 * V_317 ,
V_325 ) ;
F_30 ( V_2 , V_163 , V_316 * V_317 ,
V_326 ) ;
F_30 ( V_2 , V_163 , V_154 * V_317 - 1 ,
V_327 ) ;
}
static int F_162 ( struct V_1 * V_2 ,
unsigned int V_163 , unsigned int V_286 ,
unsigned int V_316 , unsigned int V_154 )
{
struct V_158 * V_30 = & V_2 -> V_328 [ V_163 ] ;
T_2 V_317 = F_160 ( V_2 ) ;
int V_59 ;
V_30 -> V_2 = V_2 ;
V_30 -> V_163 = V_163 ;
if ( V_163 == V_65 ) {
V_30 -> V_194 = F_80 ;
V_30 -> V_319 = F_78 ;
} else {
V_30 -> V_194 = F_83 ;
V_30 -> V_319 = F_81 ;
}
V_30 -> V_151 = V_2 -> V_265 + V_316 ;
V_30 -> V_286 = V_286 ;
V_30 -> V_171 = 0 ;
V_30 -> V_266 = V_316 ;
V_30 -> V_153 = V_316 ;
V_30 -> V_154 = V_154 - 1 ;
V_59 = F_146 ( V_2 , V_30 ) ;
if ( V_59 )
return V_59 ;
F_32 ( V_2 , V_163 , 0 , V_258 ) ;
F_32 ( V_2 , V_163 , 0 , V_285 ) ;
F_32 ( V_2 , V_163 , 1 , V_66 ) ;
F_32 ( V_2 , V_163 ,
( ( V_286 << V_321 ) |
V_322 ) , V_323 ) ;
F_32 ( V_2 , V_163 ,
( V_329 <<
V_330 ) |
V_331 , V_332 ) ;
F_32 ( V_2 , V_163 , V_316 * V_317 ,
V_324 ) ;
F_32 ( V_2 , V_163 , V_316 * V_317 ,
V_333 ) ;
F_32 ( V_2 , V_163 , V_316 * V_317 ,
V_334 ) ;
F_32 ( V_2 , V_163 , V_154 * V_317 - 1 ,
V_327 ) ;
return V_59 ;
}
static void F_163 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
struct V_149 * V_30 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_79 ; ++ V_70 ) {
V_30 = & V_2 -> V_195 [ V_70 ] ;
F_164 ( V_2 -> V_23 , & V_30 -> V_191 , F_103 , 64 ) ;
}
V_30 = & V_2 -> V_195 [ V_65 ] ;
F_164 ( V_2 -> V_23 , & V_30 -> V_191 , F_103 , 64 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
struct V_149 * V_30 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_79 ; ++ V_70 ) {
V_30 = & V_2 -> V_195 [ V_70 ] ;
F_166 ( & V_30 -> V_191 ) ;
}
V_30 = & V_2 -> V_195 [ V_65 ] ;
F_166 ( & V_30 -> V_191 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
struct V_149 * V_30 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_79 ; ++ V_70 ) {
V_30 = & V_2 -> V_195 [ V_70 ] ;
F_168 ( & V_30 -> V_191 ) ;
}
V_30 = & V_2 -> V_195 [ V_65 ] ;
F_168 ( & V_30 -> V_191 ) ;
}
static void F_169 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
struct V_149 * V_30 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_79 ; ++ V_70 ) {
V_30 = & V_2 -> V_195 [ V_70 ] ;
F_170 ( & V_30 -> V_191 ) ;
}
V_30 = & V_2 -> V_195 [ V_65 ] ;
F_170 ( & V_30 -> V_191 ) ;
}
static void F_171 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_70 , V_335 ;
T_2 V_336 , V_337 ;
T_2 V_338 [ 3 ] = { 0 , 0 , 0 } ;
V_336 = F_25 ( V_2 , V_339 ) ;
V_335 = V_336 & V_340 ;
V_336 &= ~ V_340 ;
F_26 ( V_2 , V_336 , V_339 ) ;
V_336 = 0 ;
V_337 = 0 ;
F_26 ( V_2 , V_341 , V_342 ) ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_79 ; V_70 ++ ) {
F_159 ( V_2 , V_70 , V_2 -> V_8 -> V_343 ,
V_70 * V_2 -> V_8 -> V_343 ,
( V_70 + 1 ) * V_2 -> V_8 -> V_343 ) ;
V_337 |= ( 1 << V_70 ) ;
V_336 |= ( 1 << ( V_70 + V_344 ) ) ;
V_338 [ F_172 ( V_70 ) ] |=
( ( V_345 + V_70 ) << F_173 ( V_70 ) ) ;
}
F_159 ( V_2 , V_65 , V_346 ,
V_2 -> V_8 -> V_79 *
V_2 -> V_8 -> V_343 ,
V_347 ) ;
V_337 |= ( 1 << V_65 ) ;
V_336 |= ( 1 << ( V_65 + V_344 ) ) ;
V_338 [ F_172 ( V_65 ) ] |=
( ( V_345 + V_2 -> V_8 -> V_79 ) <<
F_173 ( V_65 ) ) ;
F_26 ( V_2 , V_338 [ 0 ] , V_348 ) ;
F_26 ( V_2 , V_338 [ 1 ] , V_349 ) ;
F_26 ( V_2 , V_338 [ 2 ] , V_350 ) ;
F_163 ( V_2 ) ;
F_26 ( V_2 , V_337 , V_351 ) ;
if ( V_335 )
V_336 |= V_340 ;
F_26 ( V_2 , V_336 , V_339 ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
struct V_158 * V_30 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_80 ; ++ V_70 ) {
V_30 = & V_2 -> V_328 [ V_70 ] ;
F_175 ( V_2 -> V_23 , & V_30 -> V_191 , F_144 , 64 ) ;
}
V_30 = & V_2 -> V_328 [ V_65 ] ;
F_175 ( V_2 -> V_23 , & V_30 -> V_191 , F_144 , 64 ) ;
}
static void F_176 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
struct V_158 * V_30 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_80 ; ++ V_70 ) {
V_30 = & V_2 -> V_328 [ V_70 ] ;
F_166 ( & V_30 -> V_191 ) ;
}
V_30 = & V_2 -> V_328 [ V_65 ] ;
F_166 ( & V_30 -> V_191 ) ;
}
static void F_177 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
struct V_158 * V_30 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_80 ; ++ V_70 ) {
V_30 = & V_2 -> V_328 [ V_70 ] ;
F_168 ( & V_30 -> V_191 ) ;
}
V_30 = & V_2 -> V_328 [ V_65 ] ;
F_168 ( & V_30 -> V_191 ) ;
}
static void F_178 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
struct V_158 * V_30 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_80 ; ++ V_70 ) {
V_30 = & V_2 -> V_328 [ V_70 ] ;
F_170 ( & V_30 -> V_191 ) ;
}
V_30 = & V_2 -> V_328 [ V_65 ] ;
F_170 ( & V_30 -> V_191 ) ;
}
static int F_179 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_70 ;
T_2 V_335 ;
T_2 V_336 ;
T_2 V_337 ;
int V_59 ;
V_336 = F_27 ( V_2 , V_339 ) ;
V_335 = V_336 & V_340 ;
V_336 &= ~ V_340 ;
F_28 ( V_2 , V_336 , V_339 ) ;
V_336 = 0 ;
V_337 = 0 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_80 ; V_70 ++ ) {
V_59 = F_162 ( V_2 , V_70 ,
V_2 -> V_8 -> V_352 ,
V_70 * V_2 -> V_8 -> V_352 ,
( V_70 + 1 ) *
V_2 -> V_8 -> V_352 ) ;
if ( V_59 )
return V_59 ;
V_337 |= ( 1 << V_70 ) ;
V_336 |= ( 1 << ( V_70 + V_344 ) ) ;
}
V_59 = F_162 ( V_2 , V_65 , V_353 ,
V_2 -> V_8 -> V_80 *
V_2 -> V_8 -> V_352 ,
V_347 ) ;
if ( V_59 )
return V_59 ;
V_337 |= ( 1 << V_65 ) ;
V_336 |= ( 1 << ( V_65 + V_344 ) ) ;
F_174 ( V_2 ) ;
F_28 ( V_2 , V_337 , V_351 ) ;
if ( V_335 )
V_336 |= V_340 ;
F_28 ( V_2 , V_336 , V_339 ) ;
return 0 ;
}
static int F_180 ( struct V_1 * V_2 )
{
int V_59 = 0 ;
int V_291 = 0 ;
T_2 V_71 ;
T_2 V_336 ;
int V_70 ;
V_71 = F_25 ( V_2 , V_339 ) ;
V_71 &= ~ V_340 ;
F_26 ( V_2 , V_71 , V_339 ) ;
while ( V_291 ++ < V_354 ) {
V_71 = F_25 ( V_2 , V_355 ) ;
if ( V_71 & V_356 )
break;
F_151 ( 1 ) ;
}
if ( V_291 == V_354 ) {
F_181 ( V_2 -> V_23 , L_19 ) ;
V_59 = - V_293 ;
}
F_149 ( 10000 , 20000 ) ;
V_71 = F_27 ( V_2 , V_339 ) ;
V_71 &= ~ V_340 ;
F_28 ( V_2 , V_71 , V_339 ) ;
V_291 = 0 ;
while ( V_291 ++ < V_354 ) {
V_71 = F_27 ( V_2 , V_355 ) ;
if ( V_71 & V_356 )
break;
F_151 ( 1 ) ;
}
if ( V_291 == V_354 ) {
F_181 ( V_2 -> V_23 , L_20 ) ;
V_59 = - V_293 ;
}
V_336 = 0 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_80 ; V_70 ++ )
V_336 |= ( 1 << ( V_70 + V_344 ) ) ;
V_71 = F_27 ( V_2 , V_339 ) ;
V_71 &= ~ V_336 ;
F_28 ( V_2 , V_71 , V_339 ) ;
V_336 = 0 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_79 ; V_70 ++ )
V_336 |= ( 1 << ( V_70 + V_344 ) ) ;
V_71 = F_25 ( V_2 , V_339 ) ;
V_71 &= ~ V_336 ;
F_26 ( V_2 , V_71 , V_339 ) ;
return V_59 ;
}
static void F_182 ( struct V_1 * V_2 )
{
int V_70 ;
struct V_167 * V_168 ;
F_178 ( V_2 ) ;
F_169 ( V_2 ) ;
F_180 ( V_2 ) ;
for ( V_70 = 0 ; V_70 < V_2 -> V_357 ; V_70 ++ ) {
if ( V_2 -> V_178 [ V_70 ] . V_156 != NULL ) {
F_114 ( V_2 -> V_178 [ V_70 ] . V_156 ) ;
V_2 -> V_178 [ V_70 ] . V_156 = NULL ;
}
}
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_79 ; V_70 ++ ) {
V_168 = F_96 ( V_2 -> V_23 , V_2 -> V_195 [ V_70 ] . V_186 ) ;
F_183 ( V_168 ) ;
}
V_168 = F_96 ( V_2 -> V_23 , V_2 -> V_195 [ V_65 ] . V_186 ) ;
F_183 ( V_168 ) ;
F_147 ( V_2 ) ;
F_184 ( V_2 -> V_265 ) ;
F_184 ( V_2 -> V_178 ) ;
}
static int F_185 ( struct V_1 * V_2 )
{
int V_59 ;
unsigned int V_70 ;
struct V_148 * V_155 ;
F_90 ( V_2 , V_131 , V_2 -> V_23 , L_15 , V_177 ) ;
V_2 -> V_358 = V_2 -> V_17 + V_2 -> V_8 -> V_359 ;
V_2 -> V_288 = V_347 ;
V_2 -> V_265 = F_186 ( V_2 -> V_288 , sizeof( struct V_148 ) ,
V_360 ) ;
if ( ! V_2 -> V_265 )
return - V_287 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_288 ; V_70 ++ ) {
V_155 = V_2 -> V_265 + V_70 ;
V_155 -> V_211 = V_2 -> V_358 + V_70 * V_361 ;
}
V_2 -> V_362 = V_2 -> V_17 + V_2 -> V_8 -> V_363 ;
V_2 -> V_357 = V_347 ;
V_2 -> V_178 = F_186 ( V_2 -> V_357 , sizeof( struct V_148 ) ,
V_360 ) ;
if ( ! V_2 -> V_178 ) {
F_184 ( V_2 -> V_265 ) ;
return - V_287 ;
}
for ( V_70 = 0 ; V_70 < V_2 -> V_357 ; V_70 ++ ) {
V_155 = V_2 -> V_178 + V_70 ;
V_155 -> V_211 = V_2 -> V_362 + V_70 * V_361 ;
}
F_28 ( V_2 , V_364 , V_365 ) ;
V_59 = F_179 ( V_2 -> V_23 ) ;
if ( V_59 ) {
F_131 ( V_2 -> V_23 , L_21 ) ;
F_147 ( V_2 ) ;
F_184 ( V_2 -> V_265 ) ;
F_184 ( V_2 -> V_178 ) ;
return V_59 ;
}
F_26 ( V_2 , V_364 , V_365 ) ;
F_171 ( V_2 -> V_23 ) ;
return 0 ;
}
static void F_187 ( struct V_366 * V_367 )
{
struct V_1 * V_2 = F_104 (
V_367 , struct V_1 , V_368 ) ;
F_90 ( V_2 , V_369 , V_2 -> V_23 , L_15 , V_177 ) ;
if ( V_2 -> V_370 & V_371 ) {
V_2 -> V_370 &= ~ V_371 ;
F_90 ( V_2 , V_372 , V_2 -> V_23 ,
L_22 ) ;
F_69 ( V_2 , V_135 ) ;
}
if ( V_2 -> V_370 & V_297 ) {
F_188 ( V_2 -> V_38 ,
! ! ( V_2 -> V_370 & V_373 ) ) ;
V_2 -> V_370 &= ~ V_297 ;
}
}
static T_9 F_189 ( int V_374 , void * V_375 )
{
struct V_1 * V_2 = V_375 ;
struct V_158 * V_376 ;
struct V_149 * V_377 ;
unsigned int V_163 ;
V_2 -> V_378 =
F_190 ( V_2 , V_379 ) &
~ F_190 ( V_2 , V_380 ) ;
F_82 ( V_2 , V_2 -> V_378 , V_294 ) ;
F_90 ( V_2 , V_369 , V_2 -> V_23 ,
L_23 , V_177 , V_2 -> V_378 ) ;
for ( V_163 = 0 ; V_163 < V_2 -> V_8 -> V_80 ; V_163 ++ ) {
if ( ! ( V_2 -> V_378 & F_158 ( V_162 + V_163 ) ) )
continue;
V_376 = & V_2 -> V_328 [ V_163 ] ;
if ( F_89 ( F_191 ( & V_376 -> V_191 ) ) ) {
V_376 -> V_319 ( V_376 ) ;
F_192 ( & V_376 -> V_191 ) ;
}
}
for ( V_163 = 0 ; V_163 < V_2 -> V_8 -> V_79 ; V_163 ++ ) {
if ( ! ( V_2 -> V_378 & F_158 ( V_163 ) ) )
continue;
V_377 = & V_2 -> V_195 [ V_163 ] ;
if ( F_89 ( F_191 ( & V_377 -> V_191 ) ) ) {
V_377 -> V_319 ( V_377 ) ;
F_192 ( & V_377 -> V_191 ) ;
}
}
return V_381 ;
}
static T_9 F_193 ( int V_374 , void * V_375 )
{
struct V_1 * V_2 = V_375 ;
struct V_158 * V_376 ;
struct V_149 * V_377 ;
V_2 -> V_370 =
F_194 ( V_2 , V_379 ) &
~ F_194 ( V_2 , V_380 ) ;
F_79 ( V_2 , V_2 -> V_370 , V_294 ) ;
F_90 ( V_2 , V_369 , V_2 -> V_23 ,
L_24 , V_2 -> V_370 ) ;
if ( V_2 -> V_370 & V_159 ) {
V_376 = & V_2 -> V_328 [ V_65 ] ;
if ( F_89 ( F_191 ( & V_376 -> V_191 ) ) ) {
V_376 -> V_319 ( V_376 ) ;
F_192 ( & V_376 -> V_191 ) ;
}
}
if ( V_2 -> V_370 & V_164 ) {
V_377 = & V_2 -> V_195 [ V_65 ] ;
if ( F_89 ( F_191 ( & V_377 -> V_191 ) ) ) {
V_377 -> V_319 ( V_377 ) ;
F_192 ( & V_377 -> V_191 ) ;
}
}
if ( V_2 -> V_370 & ( V_382 |
V_383 |
V_297 |
V_384 |
V_385 |
V_371 ) ) {
F_195 ( & V_2 -> V_368 ) ;
}
if ( ( V_2 -> V_8 -> V_9 & V_313 ) &&
V_2 -> V_370 & ( V_314 | V_315 ) ) {
V_2 -> V_370 &= ~ ( V_314 | V_315 ) ;
F_196 ( & V_2 -> V_386 ) ;
}
return V_381 ;
}
static T_9 F_197 ( int V_374 , void * V_375 )
{
struct V_1 * V_2 = V_375 ;
F_198 ( & V_2 -> V_166 -> V_23 , 0 ) ;
return V_381 ;
}
static void F_199 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_200 ( V_2 -> V_387 ) ;
F_193 ( V_2 -> V_387 , V_2 ) ;
F_201 ( V_2 -> V_387 ) ;
F_200 ( V_2 -> V_388 ) ;
F_189 ( V_2 -> V_388 , V_2 ) ;
F_201 ( V_2 -> V_388 ) ;
}
static void F_202 ( struct V_1 * V_2 )
{
T_2 V_71 ;
V_71 = F_11 ( V_2 ) ;
V_71 |= F_158 ( 1 ) ;
F_15 ( V_2 , V_71 ) ;
F_151 ( 10 ) ;
V_71 &= ~ F_158 ( 1 ) ;
F_15 ( V_2 , V_71 ) ;
F_151 ( 10 ) ;
}
static void F_203 ( struct V_1 * V_2 ,
unsigned char * V_6 )
{
F_52 ( V_2 , ( V_6 [ 0 ] << 24 ) | ( V_6 [ 1 ] << 16 ) |
( V_6 [ 2 ] << 8 ) | V_6 [ 3 ] , V_389 ) ;
F_52 ( V_2 , ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] , V_390 ) ;
}
static T_2 F_204 ( struct V_1 * V_2 )
{
T_2 V_71 ;
T_2 V_336 ;
V_336 = 1 << ( V_65 + V_344 ) | V_340 ;
V_71 = F_25 ( V_2 , V_339 ) ;
V_71 &= ~ V_336 ;
F_26 ( V_2 , V_71 , V_339 ) ;
V_71 = F_27 ( V_2 , V_339 ) ;
V_71 &= ~ V_336 ;
F_28 ( V_2 , V_71 , V_339 ) ;
F_52 ( V_2 , 1 , V_391 ) ;
F_151 ( 10 ) ;
F_52 ( V_2 , 0 , V_391 ) ;
return V_336 ;
}
static void F_205 ( struct V_1 * V_2 , T_2 V_336 )
{
T_2 V_71 ;
V_71 = F_27 ( V_2 , V_339 ) ;
V_71 |= V_336 ;
F_28 ( V_2 , V_71 , V_339 ) ;
V_71 = F_25 ( V_2 , V_339 ) ;
V_71 |= V_336 ;
F_26 ( V_2 , V_71 , V_339 ) ;
}
static void F_206 ( struct V_1 * V_2 )
{
T_2 V_70 ;
F_207 ( V_2 , 0x0 , V_392 ) ;
F_207 ( V_2 , 0x0 , V_393 ) ;
F_207 ( V_2 , 0x0 , V_393 + 4 ) ;
for ( V_70 = V_394 ; V_70 <= V_395 ; V_70 ++ )
F_28 ( V_2 , 0x0 , V_70 ) ;
for ( V_70 = 0 ; V_70 < ( V_2 -> V_8 -> V_396 / 4 ) ; V_70 ++ )
F_207 ( V_2 , 0x0 ,
V_397 + V_70 * sizeof( T_2 ) ) ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_396 *
V_2 -> V_8 -> V_398 ; V_70 ++ )
F_208 ( V_2 , 0x0 , V_70 * sizeof( T_2 ) ) ;
}
static void F_209 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) || F_157 ( V_2 ) )
return;
F_206 ( V_2 ) ;
}
static void F_210 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_176 ( V_2 ) ;
F_165 ( V_2 ) ;
F_148 ( V_2 , V_399 | V_400 , true ) ;
F_211 ( V_23 ) ;
F_154 ( V_2 ) ;
F_212 ( V_2 -> V_38 ) ;
}
static int F_213 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned long V_336 ;
T_2 V_71 ;
int V_59 ;
F_90 ( V_2 , V_401 , V_23 , L_25 ) ;
F_55 ( V_2 -> V_402 ) ;
if ( V_2 -> V_296 )
F_69 ( V_2 , V_136 ) ;
F_202 ( V_2 ) ;
V_59 = F_155 ( V_2 ) ;
if ( V_59 )
goto V_403;
F_148 ( V_2 , V_399 | V_400 , false ) ;
V_71 = F_51 ( V_2 , V_290 ) ;
V_2 -> V_47 = ! ! ( V_71 & V_404 ) ;
F_203 ( V_2 , V_23 -> V_405 ) ;
if ( V_2 -> V_296 ) {
V_71 = F_66 ( V_2 , V_138 ) ;
V_71 |= V_406 ;
F_67 ( V_2 , V_71 , V_138 ) ;
}
V_336 = F_204 ( V_2 ) ;
V_59 = F_185 ( V_2 ) ;
if ( V_59 ) {
F_131 ( V_23 , L_26 ) ;
goto V_403;
}
F_205 ( V_2 , V_336 ) ;
F_209 ( V_2 ) ;
V_59 = F_214 ( V_2 -> V_387 , F_193 , V_407 ,
V_23 -> V_408 , V_2 ) ;
if ( V_59 < 0 ) {
F_131 ( V_23 , L_27 , V_2 -> V_387 ) ;
goto V_409;
}
V_59 = F_214 ( V_2 -> V_388 , F_189 , V_407 ,
V_23 -> V_408 , V_2 ) ;
if ( V_59 < 0 ) {
F_131 ( V_23 , L_27 , V_2 -> V_388 ) ;
goto V_410;
}
V_59 = F_215 ( V_23 ) ;
if ( V_59 ) {
F_131 ( V_23 , L_28 ) ;
goto V_411;
}
F_210 ( V_23 ) ;
return 0 ;
V_411:
F_216 ( V_2 -> V_388 , V_2 ) ;
V_410:
F_216 ( V_2 -> V_387 , V_2 ) ;
V_409:
F_182 ( V_2 ) ;
V_403:
F_56 ( V_2 -> V_402 ) ;
return V_59 ;
}
static void F_217 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_218 ( V_23 ) ;
F_219 ( V_2 -> V_38 ) ;
F_153 ( V_2 ) ;
F_177 ( V_2 ) ;
F_167 ( V_2 ) ;
F_220 ( & V_2 -> V_368 ) ;
V_2 -> V_412 = - 1 ;
V_2 -> V_413 = - 1 ;
V_2 -> V_414 = - 1 ;
V_2 -> V_415 = - 1 ;
}
static int F_221 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_59 ;
F_90 ( V_2 , V_416 , V_23 , L_29 ) ;
F_217 ( V_23 ) ;
F_222 ( V_2 -> V_38 ) ;
F_148 ( V_2 , V_400 , false ) ;
V_59 = F_180 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_148 ( V_2 , V_399 , false ) ;
F_106 ( V_23 ) ;
F_182 ( V_2 ) ;
F_216 ( V_2 -> V_387 , V_2 ) ;
F_216 ( V_2 -> V_388 , V_2 ) ;
if ( V_2 -> V_296 )
V_59 = F_63 ( V_2 , V_136 ) ;
F_56 ( V_2 -> V_402 ) ;
return V_59 ;
}
static void F_223 ( struct V_149 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_2 V_255 , V_171 , V_417 , V_418 ;
struct V_167 * V_168 ;
unsigned int V_183 ;
unsigned long V_9 ;
bool V_419 ;
if ( ! F_224 ( V_2 ) )
return;
V_168 = F_96 ( V_2 -> V_23 , V_30 -> V_186 ) ;
F_101 ( & V_30 -> V_189 , V_9 ) ;
if ( V_30 -> V_163 == V_65 ) {
V_417 = ~ F_194 ( V_2 , V_380 ) ;
V_418 = V_164 | V_420 ;
} else {
V_417 = ~ F_190 ( V_2 , V_380 ) ;
V_418 = 1 << V_30 -> V_163 ;
}
V_171 = F_29 ( V_2 , V_30 -> V_163 , V_174 ) ;
V_255 = F_29 ( V_2 , V_30 -> V_163 , V_243 ) ;
V_419 = F_98 ( V_168 ) ;
V_183 = V_30 -> V_183 ;
F_102 ( & V_30 -> V_189 , V_9 ) ;
F_61 ( V_2 , V_203 , V_2 -> V_23 , L_30
L_31
L_32
L_33
L_34
L_35
L_36 ,
V_30 -> V_163 , V_30 -> V_186 ,
V_419 ? L_37 : L_38 ,
V_417 & V_418 ? L_39 : L_40 ,
V_183 , V_30 -> V_286 ,
V_30 -> V_240 , V_255 & V_241 ,
V_30 -> V_171 , V_171 & V_175 ,
V_30 -> V_179 , V_30 -> V_152 ,
V_30 -> V_153 , V_30 -> V_154 ) ;
}
static void F_225 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_295 = 0 ;
T_2 V_302 = 0 ;
unsigned int V_421 ;
F_90 ( V_2 , V_203 , V_23 , L_41 ) ;
for ( V_421 = 0 ; V_421 < V_2 -> V_8 -> V_79 ; V_421 ++ )
F_223 ( & V_2 -> V_195 [ V_421 ] ) ;
F_223 ( & V_2 -> V_195 [ V_65 ] ) ;
F_106 ( V_23 ) ;
for ( V_421 = 0 ; V_421 < V_2 -> V_8 -> V_79 ; V_421 ++ )
V_302 |= ( 1 << V_421 ) ;
V_295 = V_164 ;
F_79 ( V_2 , V_295 , V_161 ) ;
F_82 ( V_2 , V_302 , V_161 ) ;
F_226 ( V_23 ) ;
V_23 -> V_111 . V_422 ++ ;
F_227 ( V_23 ) ;
}
static inline void F_228 ( struct V_1 * V_2 ,
unsigned char * V_6 ,
int * V_70 ,
int * V_423 )
{
T_2 V_71 ;
F_52 ( V_2 , V_6 [ 0 ] << 8 | V_6 [ 1 ] ,
V_424 + ( * V_70 * 4 ) ) ;
F_52 ( V_2 , V_6 [ 2 ] << 24 | V_6 [ 3 ] << 16 |
V_6 [ 4 ] << 8 | V_6 [ 5 ] ,
V_424 + ( ( * V_70 + 1 ) * 4 ) ) ;
V_71 = F_51 ( V_2 , V_425 ) ;
V_71 |= ( 1 << ( V_426 - * V_423 ) ) ;
F_52 ( V_2 , V_71 , V_425 ) ;
* V_70 += 2 ;
( * V_423 ) ++ ;
}
static void F_229 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_427 * V_428 ;
int V_70 , V_423 ;
T_2 V_71 ;
F_90 ( V_2 , V_131 , V_23 , L_42 , V_177 , V_23 -> V_9 ) ;
V_71 = F_51 ( V_2 , V_290 ) ;
if ( V_23 -> V_9 & V_429 ) {
V_71 |= V_430 ;
F_52 ( V_2 , V_71 , V_290 ) ;
F_52 ( V_2 , 0 , V_425 ) ;
return;
} else {
V_71 &= ~ V_430 ;
F_52 ( V_2 , V_71 , V_290 ) ;
}
if ( V_23 -> V_9 & V_431 ) {
F_181 ( V_23 , L_43 ) ;
return;
}
V_70 = 0 ;
V_423 = 0 ;
F_228 ( V_2 , V_23 -> V_432 , & V_70 , & V_423 ) ;
F_228 ( V_2 , V_23 -> V_405 , & V_70 , & V_423 ) ;
if ( F_230 ( V_23 ) > ( V_426 - V_423 ) )
return;
if ( ! F_231 ( V_23 ) )
F_232 (ha, dev)
F_228 ( V_2 , V_428 -> V_6 , & V_70 , & V_423 ) ;
if ( F_233 ( V_23 ) || F_234 ( V_23 ) >= ( V_426 - V_423 ) )
return;
F_235 (ha, dev)
F_228 ( V_2 , V_428 -> V_6 , & V_70 , & V_423 ) ;
}
static int F_236 ( struct V_34 * V_23 , void * V_98 )
{
struct V_433 * V_6 = V_98 ;
if ( F_34 ( V_23 ) )
return - V_434 ;
F_237 ( V_23 -> V_405 , V_6 -> V_435 ) ;
return 0 ;
}
static void F_238 ( struct V_1 * V_2 )
{
struct V_436 * V_437 ;
T_2 V_71 ;
T_5 V_438 ;
T_6 V_439 ;
if ( F_239 ( V_2 ) ) {
V_28 = V_440 ;
V_33 = V_441 ;
V_2 -> V_278 = V_442 ;
V_2 -> V_85 = V_443 ;
} else if ( F_240 ( V_2 ) ) {
V_28 = V_440 ;
V_33 = V_444 ;
V_2 -> V_278 = V_442 ;
V_2 -> V_85 = V_445 ;
} else if ( F_157 ( V_2 ) ) {
V_28 = V_446 ;
V_33 = V_444 ;
V_2 -> V_278 = V_447 ;
V_2 -> V_85 = V_448 ;
} else if ( F_12 ( V_2 ) ) {
V_28 = V_449 ;
V_33 = V_444 ;
V_2 -> V_278 = V_447 ;
V_2 -> V_85 = V_450 ;
}
V_2 -> V_8 = & V_436 [ V_2 -> V_85 ] ;
V_437 = V_2 -> V_8 ;
V_71 = F_14 ( V_2 , V_451 ) ;
V_438 = ( V_71 >> 24 & 0x0f ) ;
if ( V_438 == 5 )
V_438 = 4 ;
else if ( V_438 == 0 )
V_438 = 1 ;
if ( V_438 != V_2 -> V_85 ) {
F_152 ( & V_2 -> V_166 -> V_23 ,
L_44 ,
V_438 , V_2 -> V_85 ) ;
}
F_241 ( & V_2 -> V_166 -> V_23 , L_45 V_452 ,
V_438 , ( V_71 >> 16 ) & 0x0f , V_71 & 0xffff ) ;
V_439 = V_71 & 0xffff ;
if ( ( V_439 & 0xf0 ) != 0 )
V_2 -> V_439 = V_439 << 8 ;
else if ( ( V_439 & 0xff00 ) != 0 )
V_2 -> V_439 = V_439 ;
else if ( V_439 == 0 || V_439 == 0x01ff ) {
F_242 ( L_46 , V_439 ) ;
return;
}
#ifdef F_7
if ( ! ( V_437 -> V_9 & V_10 ) )
F_242 ( L_47 ) ;
#endif
F_243 ( L_48
L_49
L_50
L_51
L_52
L_53
L_54 ,
V_2 -> V_85 ,
V_437 -> V_79 , V_437 -> V_343 ,
V_437 -> V_80 , V_437 -> V_352 ,
V_437 -> V_311 , V_437 -> V_312 ,
V_437 -> V_396 , V_437 -> V_205 ,
V_437 -> V_18 , V_437 -> V_453 ,
V_437 -> V_454 ,
V_437 -> V_359 , V_437 -> V_363 ,
V_437 -> V_317 ) ;
}
static int F_244 ( struct V_455 * V_166 )
{
struct V_456 * V_457 = V_166 -> V_23 . V_458 ;
struct V_459 * V_460 = V_166 -> V_23 . V_461 ;
const struct V_462 * V_463 = NULL ;
struct V_1 * V_2 ;
struct V_34 * V_23 ;
const void * V_464 ;
struct V_465 * V_25 ;
int V_466 = - V_467 ;
V_23 = F_245 ( sizeof( * V_2 ) , V_468 + 1 ,
V_468 + 1 ) ;
if ( ! V_23 ) {
F_152 ( & V_166 -> V_23 , L_55 ) ;
return - V_287 ;
}
if ( V_460 ) {
V_463 = F_246 ( V_469 , V_460 ) ;
if ( ! V_463 )
return - V_37 ;
}
V_2 = F_23 ( V_23 ) ;
V_2 -> V_387 = F_247 ( V_166 , 0 ) ;
V_2 -> V_388 = F_247 ( V_166 , 1 ) ;
V_2 -> V_470 = F_247 ( V_166 , 2 ) ;
if ( ! V_2 -> V_387 || ! V_2 -> V_388 ) {
F_152 ( & V_166 -> V_23 , L_56 ) ;
V_466 = - V_37 ;
goto V_466;
}
if ( V_460 ) {
V_464 = F_248 ( V_460 ) ;
if ( ! V_464 ) {
F_152 ( & V_166 -> V_23 , L_57 ) ;
V_466 = - V_37 ;
goto V_466;
}
} else {
V_464 = V_457 -> V_471 ;
}
V_25 = F_249 ( V_166 , V_472 , 0 ) ;
V_2 -> V_17 = F_250 ( & V_166 -> V_23 , V_25 ) ;
if ( F_251 ( V_2 -> V_17 ) ) {
V_466 = F_252 ( V_2 -> V_17 ) ;
goto V_466;
}
F_253 ( V_23 , & V_166 -> V_23 ) ;
F_254 ( & V_166 -> V_23 , V_23 ) ;
F_237 ( V_23 -> V_405 , V_464 ) ;
V_23 -> V_473 = 2 * V_474 ;
V_23 -> V_475 = & V_476 ;
V_23 -> V_477 = & V_478 ;
V_2 -> V_60 = F_255 ( - 1 , V_479 ) ;
V_23 -> V_480 |= V_481 | V_53 |
V_54 | V_43 ;
V_2 -> V_482 = true ;
V_466 = F_256 ( & V_166 -> V_23 , V_2 -> V_470 , F_197 , 0 ,
V_23 -> V_408 , V_2 ) ;
if ( ! V_466 )
F_257 ( & V_166 -> V_23 , 1 ) ;
V_23 -> V_483 += 64 ;
F_258 ( V_23 ) ;
V_2 -> V_23 = V_23 ;
V_2 -> V_166 = V_166 ;
if ( V_463 )
V_2 -> V_85 = (enum V_484 ) V_463 -> V_90 ;
else
V_2 -> V_85 = V_457 -> V_485 ;
V_2 -> V_402 = F_259 ( & V_2 -> V_166 -> V_23 , L_58 ) ;
if ( F_251 ( V_2 -> V_402 ) ) {
F_260 ( & V_2 -> V_166 -> V_23 , L_59 ) ;
V_2 -> V_402 = NULL ;
}
F_55 ( V_2 -> V_402 ) ;
F_238 ( V_2 ) ;
F_261 ( & V_2 -> V_386 ) ;
V_2 -> V_245 = V_322 ;
F_262 ( & V_2 -> V_368 , F_187 ) ;
V_2 -> V_486 = F_259 ( & V_2 -> V_166 -> V_23 , L_60 ) ;
if ( F_251 ( V_2 -> V_486 ) ) {
F_260 ( & V_2 -> V_166 -> V_23 , L_61 ) ;
V_2 -> V_486 = NULL ;
}
V_2 -> V_116 = F_259 ( & V_2 -> V_166 -> V_23 , L_62 ) ;
if ( F_251 ( V_2 -> V_116 ) ) {
F_260 ( & V_2 -> V_166 -> V_23 , L_63 ) ;
V_2 -> V_116 = NULL ;
}
V_466 = F_150 ( V_2 ) ;
if ( V_466 )
goto V_403;
V_466 = F_263 ( V_23 ) ;
if ( V_466 )
goto V_403;
F_264 ( V_2 -> V_23 , V_2 -> V_8 -> V_79 + 1 ) ;
F_265 ( V_2 -> V_23 , V_2 -> V_8 -> V_80 + 1 ) ;
F_266 ( V_23 ) ;
F_56 ( V_2 -> V_402 ) ;
V_466 = F_267 ( V_23 ) ;
if ( V_466 )
goto V_466;
return V_466 ;
V_403:
F_56 ( V_2 -> V_402 ) ;
V_466:
F_268 ( V_23 ) ;
return V_466 ;
}
static int F_269 ( struct V_455 * V_166 )
{
struct V_1 * V_2 = F_22 ( & V_166 -> V_23 ) ;
F_254 ( & V_166 -> V_23 , NULL ) ;
F_270 ( V_2 -> V_23 ) ;
F_271 ( V_2 -> V_23 ) ;
F_268 ( V_2 -> V_23 ) ;
return 0 ;
}
static int F_272 ( struct V_22 * V_3 )
{
struct V_34 * V_23 = F_24 ( V_3 ) ;
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_59 ;
if ( ! F_34 ( V_23 ) )
return 0 ;
F_217 ( V_23 ) ;
F_273 ( V_2 -> V_38 ) ;
F_274 ( V_23 ) ;
F_148 ( V_2 , V_400 , false ) ;
V_59 = F_180 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_148 ( V_2 , V_399 , false ) ;
F_106 ( V_23 ) ;
F_182 ( V_2 ) ;
if ( F_275 ( V_3 ) && V_2 -> V_487 ) {
V_59 = F_63 ( V_2 , V_135 ) ;
F_55 ( V_2 -> V_486 ) ;
} else if ( V_2 -> V_296 ) {
V_59 = F_63 ( V_2 , V_136 ) ;
}
F_56 ( V_2 -> V_402 ) ;
return V_59 ;
}
static int F_276 ( struct V_22 * V_3 )
{
struct V_34 * V_23 = F_24 ( V_3 ) ;
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned long V_336 ;
int V_59 ;
T_2 V_71 ;
if ( ! F_34 ( V_23 ) )
return 0 ;
V_59 = F_55 ( V_2 -> V_402 ) ;
if ( V_59 )
return V_59 ;
if ( V_2 -> V_296 )
F_69 ( V_2 , V_136 ) ;
F_202 ( V_2 ) ;
V_59 = F_155 ( V_2 ) ;
if ( V_59 )
goto V_488;
if ( V_2 -> V_487 )
F_56 ( V_2 -> V_486 ) ;
F_277 ( V_2 -> V_38 ) ;
F_278 ( V_2 -> V_23 ) ;
F_148 ( V_2 , V_399 | V_400 , false ) ;
F_203 ( V_2 , V_23 -> V_405 ) ;
if ( V_2 -> V_296 ) {
V_71 = F_66 ( V_2 , V_138 ) ;
V_71 |= V_406 ;
F_67 ( V_2 , V_71 , V_138 ) ;
}
if ( V_2 -> V_487 )
F_69 ( V_2 , V_135 ) ;
V_336 = F_204 ( V_2 ) ;
V_59 = F_185 ( V_2 ) ;
if ( V_59 ) {
F_131 ( V_23 , L_26 ) ;
goto V_488;
}
F_205 ( V_2 , V_336 ) ;
F_279 ( V_23 ) ;
F_280 ( V_2 -> V_38 ) ;
if ( V_2 -> V_124 . V_125 )
F_54 ( V_23 , true ) ;
F_210 ( V_23 ) ;
return 0 ;
V_488:
F_56 ( V_2 -> V_402 ) ;
return V_59 ;
}
