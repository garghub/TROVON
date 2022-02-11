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
F_1 ( V_2 , V_3 , V_12 ) ;
F_5 ( V_2 , V_3 , V_6 ) ;
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
struct V_35 * V_36 )
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
static int F_63 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
return F_64 ( V_2 -> V_38 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
enum V_132 V_133 )
{
int V_59 = 0 ;
T_2 V_71 ;
switch ( V_133 ) {
case V_134 :
F_66 ( V_2 -> V_38 ) ;
break;
case V_135 :
V_59 = F_67 ( V_2 , V_133 ) ;
break;
case V_136 :
if ( V_2 -> V_8 -> V_9 & V_137 ) {
V_71 = F_68 ( V_2 , V_138 ) ;
V_71 |= ( V_139 |
V_140 | V_141 ) ;
F_69 ( V_2 , V_71 , V_138 ) ;
F_70 ( V_2 -> V_23 , false ) ;
}
break;
default:
break;
}
return 0 ;
}
static void F_71 ( struct V_1 * V_2 ,
enum V_132 V_133 )
{
T_2 V_71 ;
if ( ! ( V_2 -> V_8 -> V_9 & V_137 ) )
return;
V_71 = F_68 ( V_2 , V_138 ) ;
switch ( V_133 ) {
case V_136 :
V_71 &= ~ ( V_140 | V_139 |
V_141 ) ;
case V_134 :
V_71 |= V_142 ;
break;
case V_135 :
F_72 ( V_2 , V_133 ) ;
return;
default:
break;
}
F_69 ( V_2 , V_71 , V_138 ) ;
if ( V_133 == V_136 ) {
F_70 ( V_2 -> V_23 , true ) ;
F_73 ( V_2 -> V_23 ) ;
}
}
static int F_74 ( struct V_34 * V_23 , struct V_143 * V_144 , int V_36 )
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
V_12 = F_75 ( V_2 -> V_38 , V_144 , V_36 ) ;
break;
default:
V_12 = - V_37 ;
break;
}
return V_12 ;
}
static struct V_148 * F_76 ( struct V_1 * V_2 ,
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
static void F_77 ( struct V_148 * V_155 )
{
F_78 ( V_155 -> V_156 ) ;
V_155 -> V_156 = NULL ;
F_79 ( V_155 , V_157 , 0 ) ;
}
static inline void F_80 ( struct V_158 * V_30 )
{
F_81 ( V_30 -> V_2 , V_159 ,
V_160 ) ;
}
static inline void F_82 ( struct V_158 * V_30 )
{
F_81 ( V_30 -> V_2 , V_159 ,
V_161 ) ;
}
static inline void F_83 ( struct V_158 * V_30 )
{
F_84 ( V_30 -> V_2 ,
1 << ( V_162 + V_30 -> V_163 ) ,
V_160 ) ;
}
static inline void F_85 ( struct V_158 * V_30 )
{
F_84 ( V_30 -> V_2 ,
1 << ( V_162 + V_30 -> V_163 ) ,
V_161 ) ;
}
static inline void F_86 ( struct V_149 * V_30 )
{
F_81 ( V_30 -> V_2 , V_164 ,
V_160 ) ;
}
static inline void F_87 ( struct V_149 * V_30 )
{
F_81 ( V_30 -> V_2 , V_164 ,
V_161 ) ;
}
static inline void F_88 ( struct V_149 * V_30 )
{
F_84 ( V_30 -> V_2 , 1 << V_30 -> V_163 ,
V_161 ) ;
}
static inline void F_89 ( struct V_149 * V_30 )
{
F_84 ( V_30 -> V_2 , 1 << V_30 -> V_163 ,
V_160 ) ;
}
static unsigned int F_90 ( struct V_34 * V_23 ,
struct V_149 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_148 * V_150 ;
struct V_165 * V_166 ;
unsigned int V_167 = 0 ;
unsigned int V_168 ;
unsigned int V_169 ;
unsigned int V_170 = 0 ;
V_168 = F_29 ( V_2 , V_30 -> V_163 , V_171 ) ;
V_168 &= V_172 ;
if ( F_91 ( V_168 >= V_30 -> V_168 ) )
V_169 = V_168 - V_30 -> V_168 ;
else
V_169 = ( V_172 + 1 ) - V_30 -> V_168 + V_168 ;
F_92 ( V_2 , V_173 , V_23 ,
L_4 ,
V_174 , V_30 -> V_163 , V_30 -> V_168 , V_168 , V_169 ) ;
while ( V_170 < V_169 ) {
V_150 = & V_2 -> V_175 [ V_30 -> V_176 ] ;
if ( V_150 -> V_156 ) {
V_167 ++ ;
V_23 -> V_111 . V_177 ++ ;
V_23 -> V_111 . V_178 += V_150 -> V_156 -> V_179 ;
F_93 ( & V_23 -> V_23 ,
F_94 ( V_150 , V_157 ) ,
V_150 -> V_156 -> V_179 ,
V_180 ) ;
F_77 ( V_150 ) ;
} else if ( F_94 ( V_150 , V_157 ) ) {
V_23 -> V_111 . V_178 +=
F_95 ( V_150 , V_181 ) ;
F_96 ( & V_23 -> V_23 ,
F_94 ( V_150 , V_157 ) ,
F_95 ( V_150 , V_181 ) ,
V_180 ) ;
F_79 ( V_150 , V_157 , 0 ) ;
}
V_170 ++ ;
if ( F_91 ( V_30 -> V_176 < V_30 -> V_154 ) )
V_30 -> V_176 ++ ;
else
V_30 -> V_176 = V_30 -> V_153 ;
}
V_30 -> V_182 += V_170 ;
V_30 -> V_168 = ( V_30 -> V_168 + V_170 ) & V_172 ;
if ( V_30 -> V_182 > ( V_183 + 1 ) ) {
V_166 = F_97 ( V_23 , V_30 -> V_184 ) ;
if ( F_98 ( V_166 ) )
F_99 ( V_166 ) ;
}
return V_167 ;
}
static unsigned int F_100 ( struct V_34 * V_23 ,
struct V_149 * V_30 )
{
unsigned int V_185 ;
unsigned long V_9 ;
F_101 ( & V_30 -> V_186 , V_9 ) ;
V_185 = F_90 ( V_23 , V_30 ) ;
F_102 ( & V_30 -> V_186 , V_9 ) ;
return V_185 ;
}
static int F_103 ( struct V_187 * V_188 , int V_189 )
{
struct V_149 * V_30 =
F_104 ( V_188 , struct V_149 , V_188 ) ;
unsigned int V_190 = 0 ;
V_190 = F_100 ( V_30 -> V_2 -> V_23 , V_30 ) ;
if ( V_190 == 0 ) {
F_105 ( V_188 ) ;
V_30 -> V_191 ( V_30 ) ;
return 0 ;
}
return V_189 ;
}
static void F_106 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_70 ;
if ( F_107 ( V_23 ) ) {
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_79 ; V_70 ++ )
F_100 ( V_23 , & V_2 -> V_192 [ V_70 ] ) ;
}
F_100 ( V_23 , & V_2 -> V_192 [ V_65 ] ) ;
}
static int F_108 ( struct V_34 * V_23 ,
struct V_193 * V_156 ,
T_6 V_194 ,
struct V_149 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_22 * V_195 = & V_2 -> V_196 -> V_23 ;
struct V_148 * V_150 ;
unsigned int V_197 ;
T_3 V_198 ;
T_2 V_199 ;
int V_59 ;
V_150 = F_76 ( V_2 , V_30 ) ;
if ( F_109 ( ! V_150 ) )
F_110 () ;
V_150 -> V_156 = V_156 ;
V_197 = F_111 ( V_156 ) < V_200 ? V_200 : F_111 ( V_156 ) ;
V_198 = F_112 ( V_195 , V_156 -> V_90 , V_197 , V_180 ) ;
V_59 = F_113 ( V_195 , V_198 ) ;
if ( V_59 ) {
V_2 -> V_201 . V_202 ++ ;
F_61 ( V_2 , V_203 , V_23 , L_5 ) ;
F_114 ( V_156 ) ;
return V_59 ;
}
F_79 ( V_150 , V_157 , V_198 ) ;
F_115 ( V_150 , V_181 , V_156 -> V_179 ) ;
V_199 = ( V_197 << V_204 ) | V_194 |
( V_2 -> V_8 -> V_205 << V_206 ) |
V_207 ;
if ( V_156 -> V_208 == V_209 )
V_199 |= V_210 ;
F_9 ( V_2 , V_150 -> V_211 , V_198 , V_199 ) ;
return 0 ;
}
static int F_116 ( struct V_34 * V_23 ,
T_7 * V_212 ,
T_6 V_194 ,
struct V_149 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_22 * V_195 = & V_2 -> V_196 -> V_23 ;
struct V_148 * V_150 ;
T_3 V_198 ;
int V_59 ;
V_150 = F_76 ( V_2 , V_30 ) ;
if ( F_109 ( ! V_150 ) )
F_110 () ;
V_150 -> V_156 = NULL ;
V_198 = F_117 ( V_195 , V_212 , 0 ,
F_118 ( V_212 ) , V_180 ) ;
V_59 = F_113 ( V_195 , V_198 ) ;
if ( V_59 ) {
V_2 -> V_201 . V_202 ++ ;
F_61 ( V_2 , V_203 , V_23 , L_6 ,
V_174 ) ;
return V_59 ;
}
F_79 ( V_150 , V_157 , V_198 ) ;
F_115 ( V_150 , V_181 , V_212 -> V_213 ) ;
F_9 ( V_2 , V_150 -> V_211 , V_198 ,
( V_212 -> V_213 << V_204 ) | V_194 |
( V_2 -> V_8 -> V_205 << V_206 ) ) ;
return 0 ;
}
static struct V_193 * F_119 ( struct V_34 * V_23 ,
struct V_193 * V_156 )
{
struct V_214 * V_215 = NULL ;
struct V_193 * V_216 ;
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
static T_8 F_127 ( struct V_193 * V_156 , struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_149 * V_30 = NULL ;
struct V_165 * V_166 ;
unsigned long V_9 = 0 ;
int V_231 , V_163 ;
T_6 V_194 ;
int V_59 ;
int V_70 ;
V_163 = F_128 ( V_156 ) ;
if ( V_163 == 0 )
V_163 = V_65 ;
else
V_163 -= 1 ;
V_231 = F_129 ( V_156 ) -> V_231 ;
V_30 = & V_2 -> V_192 [ V_163 ] ;
V_166 = F_97 ( V_23 , V_30 -> V_184 ) ;
F_101 ( & V_30 -> V_186 , V_9 ) ;
if ( V_30 -> V_182 <= V_231 + 1 ) {
F_130 ( V_166 ) ;
F_131 ( V_23 , L_7 ,
V_174 , V_163 , V_30 -> V_184 ) ;
V_59 = V_232 ;
goto V_233;
}
if ( F_132 ( V_156 , V_200 ) ) {
V_59 = V_234 ;
goto V_233;
}
if ( V_2 -> V_49 ) {
V_156 = F_119 ( V_23 , V_156 ) ;
if ( ! V_156 ) {
V_59 = V_234 ;
goto V_233;
}
}
V_194 = V_235 ;
if ( V_231 == 0 )
V_194 |= V_236 ;
V_59 = F_108 ( V_23 , V_156 , V_194 , V_30 ) ;
if ( V_59 ) {
V_59 = V_234 ;
goto V_233;
}
for ( V_70 = 0 ; V_70 < V_231 ; V_70 ++ ) {
V_59 = F_116 ( V_23 ,
& F_129 ( V_156 ) -> V_237 [ V_70 ] ,
( V_70 == V_231 - 1 ) ? V_236 : 0 ,
V_30 ) ;
if ( V_59 ) {
V_59 = V_234 ;
goto V_233;
}
}
F_133 ( V_156 ) ;
V_30 -> V_182 -= V_231 + 1 ;
V_30 -> V_238 += V_231 + 1 ;
V_30 -> V_238 &= V_239 ;
if ( V_30 -> V_182 <= ( V_183 + 1 ) )
F_130 ( V_166 ) ;
if ( ! V_156 -> V_240 || F_134 ( V_166 ) )
F_30 ( V_2 , V_30 -> V_163 ,
V_30 -> V_238 , V_241 ) ;
V_233:
F_102 ( & V_30 -> V_186 , V_9 ) ;
return V_59 ;
}
static struct V_193 * F_135 ( struct V_1 * V_2 ,
struct V_148 * V_155 )
{
struct V_22 * V_195 = & V_2 -> V_196 -> V_23 ;
struct V_193 * V_156 ;
struct V_193 * V_242 ;
T_3 V_198 ;
V_156 = F_136 ( V_2 -> V_23 , V_2 -> V_243 + V_244 ) ;
if ( ! V_156 ) {
V_2 -> V_201 . V_245 ++ ;
F_61 ( V_2 , V_246 , V_2 -> V_23 ,
L_8 , V_174 ) ;
return NULL ;
}
V_198 = F_112 ( V_195 , V_156 -> V_90 , V_2 -> V_243 ,
V_247 ) ;
if ( F_113 ( V_195 , V_198 ) ) {
V_2 -> V_201 . V_248 ++ ;
F_78 ( V_156 ) ;
F_61 ( V_2 , V_246 , V_2 -> V_23 ,
L_9 , V_174 ) ;
return NULL ;
}
V_242 = V_155 -> V_156 ;
if ( F_91 ( V_242 ) )
F_93 ( V_195 , F_94 ( V_155 , V_157 ) ,
V_2 -> V_243 , V_247 ) ;
V_155 -> V_156 = V_156 ;
F_79 ( V_155 , V_157 , V_198 ) ;
F_5 ( V_2 , V_155 -> V_211 , V_198 ) ;
return V_242 ;
}
static unsigned int F_137 ( struct V_158 * V_30 ,
unsigned int V_189 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_34 * V_23 = V_2 -> V_23 ;
struct V_148 * V_155 ;
struct V_193 * V_156 ;
T_2 V_249 ;
unsigned long V_250 ;
int V_179 ;
unsigned int V_251 = 0 , V_252 ;
unsigned int V_253 ;
unsigned int V_254 ;
unsigned int V_255 = 0 ;
V_253 = F_31 ( V_2 , V_30 -> V_163 , V_256 ) ;
V_254 = ( V_253 >> V_257 ) &
V_258 ;
if ( V_254 > V_30 -> V_259 ) {
V_254 = V_254 - V_30 -> V_259 ;
V_23 -> V_111 . V_260 += V_254 ;
V_23 -> V_111 . V_261 += V_254 ;
V_30 -> V_259 += V_254 ;
if ( V_30 -> V_259 >= 0xC000 ) {
V_30 -> V_259 = 0 ;
F_32 ( V_2 , V_30 -> V_163 , 0 ,
V_256 ) ;
}
}
V_253 &= V_239 ;
if ( F_91 ( V_253 >= V_30 -> V_168 ) )
V_252 = V_253 - V_30 -> V_168 ;
else
V_252 = ( V_172 + 1 ) - V_30 -> V_168 +
V_253 ;
F_92 ( V_2 , V_262 , V_23 ,
L_10 , V_252 ) ;
while ( ( V_251 < V_252 ) &&
( V_251 < V_189 ) ) {
V_155 = & V_2 -> V_263 [ V_30 -> V_264 ] ;
V_156 = F_135 ( V_2 , V_155 ) ;
if ( F_109 ( ! V_156 ) ) {
V_23 -> V_111 . V_265 ++ ;
goto V_266;
}
if ( ! V_2 -> V_49 ) {
V_249 =
F_3 ( V_2 , V_155 -> V_211 ) ;
} else {
struct V_214 * V_215 ;
V_215 = (struct V_214 * ) V_156 -> V_90 ;
V_249 = V_215 -> V_199 ;
}
V_250 = V_249 & 0xffff ;
V_179 = V_249 >> V_204 ;
F_92 ( V_2 , V_262 , V_23 ,
L_11 ,
V_174 , V_253 , V_30 -> V_168 ,
V_30 -> V_264 , V_249 ) ;
if ( F_109 ( ! ( V_250 & V_236 ) || ! ( V_250 & V_235 ) ) ) {
F_61 ( V_2 , V_262 , V_23 ,
L_12 ) ;
V_23 -> V_111 . V_261 ++ ;
F_78 ( V_156 ) ;
goto V_266;
}
if ( F_109 ( V_250 & ( V_267 |
V_268 |
V_269 |
V_270 |
V_271 ) ) ) {
F_61 ( V_2 , V_262 , V_23 , L_13 ,
( unsigned int ) V_250 ) ;
if ( V_250 & V_267 )
V_23 -> V_111 . V_272 ++ ;
if ( V_250 & V_268 )
V_23 -> V_111 . V_273 ++ ;
if ( V_250 & V_269 )
V_23 -> V_111 . V_274 ++ ;
if ( V_250 & V_270 )
V_23 -> V_111 . V_275 ++ ;
V_23 -> V_111 . V_261 ++ ;
F_78 ( V_156 ) ;
goto V_266;
}
V_255 = ( V_250 & V_2 -> V_276 ) &&
V_2 -> V_46 ;
F_138 ( V_156 , V_179 ) ;
if ( V_2 -> V_49 ) {
F_139 ( V_156 , 64 ) ;
V_179 -= 64 ;
}
if ( F_91 ( V_255 ) )
V_156 -> V_208 = V_277 ;
F_139 ( V_156 , 2 ) ;
V_179 -= 2 ;
if ( V_2 -> V_47 ) {
F_140 ( V_156 , V_179 - V_278 ) ;
V_179 -= V_278 ;
}
V_156 -> V_221 = F_141 ( V_156 , V_2 -> V_23 ) ;
V_23 -> V_111 . V_279 ++ ;
V_23 -> V_111 . V_280 += V_179 ;
if ( V_250 & V_281 )
V_23 -> V_111 . V_282 ++ ;
F_142 ( & V_30 -> V_188 , V_156 ) ;
F_92 ( V_2 , V_262 , V_23 , L_14 ) ;
V_266:
V_251 ++ ;
if ( F_91 ( V_30 -> V_264 < V_30 -> V_154 ) )
V_30 -> V_264 ++ ;
else
V_30 -> V_264 = V_30 -> V_153 ;
V_30 -> V_168 = ( V_30 -> V_168 + 1 ) & V_172 ;
F_32 ( V_2 , V_30 -> V_163 , V_30 -> V_168 , V_283 ) ;
}
return V_251 ;
}
static int F_143 ( struct V_187 * V_188 , int V_189 )
{
struct V_158 * V_30 = F_104 ( V_188 ,
struct V_158 , V_188 ) ;
unsigned int V_190 ;
V_190 = F_137 ( V_30 , V_189 ) ;
if ( V_190 < V_189 ) {
F_105 ( V_188 ) ;
V_30 -> V_191 ( V_30 ) ;
}
return V_190 ;
}
static int F_144 ( struct V_1 * V_2 ,
struct V_158 * V_30 )
{
struct V_148 * V_155 ;
struct V_193 * V_156 ;
int V_70 ;
F_92 ( V_2 , V_131 , V_2 -> V_23 , L_15 , V_174 ) ;
for ( V_70 = 0 ; V_70 < V_30 -> V_213 ; V_70 ++ ) {
V_155 = V_30 -> V_151 + V_70 ;
V_156 = F_135 ( V_2 , V_155 ) ;
if ( V_156 )
F_78 ( V_156 ) ;
if ( ! V_155 -> V_156 )
return - V_284 ;
}
return 0 ;
}
static void F_145 ( struct V_1 * V_2 )
{
struct V_148 * V_155 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_285 ; V_70 ++ ) {
V_155 = & V_2 -> V_263 [ V_70 ] ;
if ( F_94 ( V_155 , V_157 ) ) {
F_93 ( & V_2 -> V_23 -> V_23 ,
F_94 ( V_155 , V_157 ) ,
V_2 -> V_243 , V_247 ) ;
F_79 ( V_155 , V_157 , 0 ) ;
}
if ( V_155 -> V_156 )
F_77 ( V_155 ) ;
}
}
static void F_146 ( struct V_1 * V_2 , T_2 V_286 , bool V_112 )
{
T_2 V_71 ;
V_71 = F_51 ( V_2 , V_287 ) ;
if ( V_112 )
V_71 |= V_286 ;
else
V_71 &= ~ V_286 ;
F_52 ( V_2 , V_71 , V_287 ) ;
if ( V_112 == 0 )
F_147 ( 1000 , 2000 ) ;
}
static int F_148 ( struct V_1 * V_2 )
{
struct V_22 * V_195 = & V_2 -> V_196 -> V_23 ;
unsigned int V_288 = 0 ;
T_2 V_71 ;
F_15 ( V_2 , 0 ) ;
F_149 ( 10 ) ;
F_52 ( V_2 , 0 , V_287 ) ;
F_52 ( V_2 , V_289 , V_287 ) ;
while ( V_288 ++ < 1000 ) {
V_71 = F_51 ( V_2 , V_287 ) ;
if ( ! ( V_71 & V_289 ) )
return 0 ;
F_149 ( 1 ) ;
}
if ( V_288 == 1000 ) {
F_150 ( V_195 ,
L_16 ) ;
return - V_290 ;
}
return 0 ;
}
static void F_151 ( struct V_1 * V_2 )
{
F_81 ( V_2 , 0xFFFFFFFF , V_160 ) ;
F_81 ( V_2 , 0xFFFFFFFF , V_291 ) ;
F_81 ( V_2 , 0 , V_161 ) ;
F_84 ( V_2 , 0xFFFFFFFF , V_160 ) ;
F_84 ( V_2 , 0xFFFFFFFF , V_291 ) ;
F_84 ( V_2 , 0 , V_161 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
T_2 V_292 = 0 ;
if ( V_2 -> V_293 ) {
V_292 |= V_294 ;
} else if ( V_2 -> V_295 ) {
V_292 |= V_294 ;
} else if ( V_2 -> V_296 == V_297 ) {
if ( V_2 -> V_8 -> V_9 & V_298 )
V_292 |= V_294 ;
}
F_81 ( V_2 , V_292 , V_161 ) ;
}
static int F_153 ( struct V_1 * V_2 )
{
struct V_22 * V_195 = & V_2 -> V_196 -> V_23 ;
int V_59 ;
T_2 V_71 ;
T_2 V_292 = 0 ;
T_2 V_299 = 0 ;
int V_70 ;
F_154 ( & V_2 -> V_196 -> V_23 , L_17 ) ;
V_59 = F_148 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_52 ( V_2 , 0 , V_287 ) ;
F_52 ( V_2 ,
V_300 | V_301 | V_302 ,
V_303 ) ;
F_52 ( V_2 , 0 , V_303 ) ;
F_52 ( V_2 , V_304 , V_305 ) ;
V_71 = F_13 ( V_2 , V_52 ) ;
V_71 |= V_306 ;
F_16 ( V_2 , V_71 , V_52 ) ;
if ( ! F_12 ( V_2 ) && ! F_155 ( V_2 ) )
F_16 ( V_2 , 1 , V_307 ) ;
F_151 ( V_2 ) ;
V_292 |= V_159 ;
V_292 |= V_164 ;
if ( V_2 -> V_296 == V_297 ) {
V_71 = F_20 ( V_2 ) ;
V_71 |= F_156 ( V_2 -> V_8 -> V_308 ) ;
if ( F_107 ( V_2 -> V_23 ) )
V_71 |= V_2 -> V_8 -> V_309 ;
else
V_71 &= ~ V_2 -> V_8 -> V_309 ;
F_21 ( V_2 , V_71 ) ;
}
if ( V_2 -> V_8 -> V_9 & V_310 )
V_292 |= ( V_311 | V_312 ) ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_80 ; ++ V_70 )
V_299 |= ( 1 << ( V_162 + V_70 ) ) ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_79 ; ++ V_70 )
V_299 |= ( 1 << V_70 ) ;
F_81 ( V_2 , V_292 , V_161 ) ;
F_84 ( V_2 , V_299 , V_161 ) ;
F_154 ( V_195 , L_18 ) ;
return 0 ;
}
static void F_157 ( struct V_1 * V_2 ,
unsigned int V_163 , unsigned int V_213 ,
unsigned int V_313 , unsigned int V_154 )
{
struct V_149 * V_30 = & V_2 -> V_192 [ V_163 ] ;
T_2 V_314 = F_158 ( V_2 ) ;
T_2 V_315 = 0 ;
F_159 ( & V_30 -> V_186 ) ;
V_30 -> V_2 = V_2 ;
V_30 -> V_163 = V_163 ;
if ( V_163 == V_65 ) {
V_30 -> V_184 = 0 ;
V_30 -> V_191 = F_87 ;
V_30 -> V_316 = F_86 ;
} else {
V_30 -> V_184 = V_163 + 1 ;
V_30 -> V_191 = F_88 ;
V_30 -> V_316 = F_89 ;
}
V_30 -> V_151 = V_2 -> V_175 + V_313 ;
V_30 -> V_213 = V_213 ;
V_30 -> V_176 = V_313 ;
V_30 -> V_168 = 0 ;
V_30 -> V_182 = V_213 ;
V_30 -> V_152 = V_313 ;
V_30 -> V_153 = V_313 ;
V_30 -> V_154 = V_154 - 1 ;
V_30 -> V_238 = 0 ;
if ( V_163 != V_65 )
V_315 = V_304 << 16 ;
F_30 ( V_2 , V_163 , 0 , V_241 ) ;
F_30 ( V_2 , V_163 , 0 , V_171 ) ;
F_30 ( V_2 , V_163 , 1 , V_66 ) ;
F_30 ( V_2 , V_163 , V_315 ,
V_317 ) ;
F_30 ( V_2 , V_163 ,
( ( V_213 << V_318 ) |
V_319 ) , V_320 ) ;
F_30 ( V_2 , V_163 , V_313 * V_314 ,
V_321 ) ;
F_30 ( V_2 , V_163 , V_313 * V_314 ,
V_322 ) ;
F_30 ( V_2 , V_163 , V_313 * V_314 ,
V_323 ) ;
F_30 ( V_2 , V_163 , V_154 * V_314 - 1 ,
V_324 ) ;
}
static int F_160 ( struct V_1 * V_2 ,
unsigned int V_163 , unsigned int V_213 ,
unsigned int V_313 , unsigned int V_154 )
{
struct V_158 * V_30 = & V_2 -> V_325 [ V_163 ] ;
T_2 V_314 = F_158 ( V_2 ) ;
int V_59 ;
V_30 -> V_2 = V_2 ;
V_30 -> V_163 = V_163 ;
if ( V_163 == V_65 ) {
V_30 -> V_191 = F_82 ;
V_30 -> V_316 = F_80 ;
} else {
V_30 -> V_191 = F_85 ;
V_30 -> V_316 = F_83 ;
}
V_30 -> V_151 = V_2 -> V_263 + V_313 ;
V_30 -> V_213 = V_213 ;
V_30 -> V_168 = 0 ;
V_30 -> V_264 = V_313 ;
V_30 -> V_153 = V_313 ;
V_30 -> V_154 = V_154 - 1 ;
V_59 = F_144 ( V_2 , V_30 ) ;
if ( V_59 )
return V_59 ;
F_32 ( V_2 , V_163 , 0 , V_256 ) ;
F_32 ( V_2 , V_163 , 0 , V_283 ) ;
F_32 ( V_2 , V_163 , 1 , V_66 ) ;
F_32 ( V_2 , V_163 ,
( ( V_213 << V_318 ) |
V_319 ) , V_320 ) ;
F_32 ( V_2 , V_163 ,
( V_326 <<
V_327 ) |
V_328 , V_329 ) ;
F_32 ( V_2 , V_163 , V_313 * V_314 ,
V_321 ) ;
F_32 ( V_2 , V_163 , V_313 * V_314 ,
V_330 ) ;
F_32 ( V_2 , V_163 , V_313 * V_314 ,
V_331 ) ;
F_32 ( V_2 , V_163 , V_154 * V_314 - 1 ,
V_324 ) ;
return V_59 ;
}
static void F_161 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
struct V_149 * V_30 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_79 ; ++ V_70 ) {
V_30 = & V_2 -> V_192 [ V_70 ] ;
F_162 ( V_2 -> V_23 , & V_30 -> V_188 , F_103 , 64 ) ;
}
V_30 = & V_2 -> V_192 [ V_65 ] ;
F_162 ( V_2 -> V_23 , & V_30 -> V_188 , F_103 , 64 ) ;
}
static void F_163 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
struct V_149 * V_30 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_79 ; ++ V_70 ) {
V_30 = & V_2 -> V_192 [ V_70 ] ;
F_164 ( & V_30 -> V_188 ) ;
}
V_30 = & V_2 -> V_192 [ V_65 ] ;
F_164 ( & V_30 -> V_188 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
struct V_149 * V_30 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_79 ; ++ V_70 ) {
V_30 = & V_2 -> V_192 [ V_70 ] ;
F_166 ( & V_30 -> V_188 ) ;
}
V_30 = & V_2 -> V_192 [ V_65 ] ;
F_166 ( & V_30 -> V_188 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
struct V_149 * V_30 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_79 ; ++ V_70 ) {
V_30 = & V_2 -> V_192 [ V_70 ] ;
F_168 ( & V_30 -> V_188 ) ;
}
V_30 = & V_2 -> V_192 [ V_65 ] ;
F_168 ( & V_30 -> V_188 ) ;
}
static void F_169 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_70 , V_332 ;
T_2 V_333 , V_334 ;
T_2 V_335 [ 3 ] = { 0 , 0 , 0 } ;
V_333 = F_25 ( V_2 , V_336 ) ;
V_332 = V_333 & V_337 ;
V_333 &= ~ V_337 ;
F_26 ( V_2 , V_333 , V_336 ) ;
V_333 = 0 ;
V_334 = 0 ;
F_26 ( V_2 , V_338 , V_339 ) ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_79 ; V_70 ++ ) {
F_157 ( V_2 , V_70 , V_2 -> V_8 -> V_340 ,
V_70 * V_2 -> V_8 -> V_340 ,
( V_70 + 1 ) * V_2 -> V_8 -> V_340 ) ;
V_334 |= ( 1 << V_70 ) ;
V_333 |= ( 1 << ( V_70 + V_341 ) ) ;
V_335 [ F_170 ( V_70 ) ] |=
( ( V_342 + V_70 ) << F_171 ( V_70 ) ) ;
}
F_157 ( V_2 , V_65 , V_343 ,
V_2 -> V_8 -> V_79 *
V_2 -> V_8 -> V_340 ,
V_344 ) ;
V_334 |= ( 1 << V_65 ) ;
V_333 |= ( 1 << ( V_65 + V_341 ) ) ;
V_335 [ F_170 ( V_65 ) ] |=
( ( V_342 + V_2 -> V_8 -> V_79 ) <<
F_171 ( V_65 ) ) ;
F_26 ( V_2 , V_335 [ 0 ] , V_345 ) ;
F_26 ( V_2 , V_335 [ 1 ] , V_346 ) ;
F_26 ( V_2 , V_335 [ 2 ] , V_347 ) ;
F_161 ( V_2 ) ;
F_26 ( V_2 , V_334 , V_348 ) ;
if ( V_332 )
V_333 |= V_337 ;
F_26 ( V_2 , V_333 , V_336 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
struct V_158 * V_30 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_80 ; ++ V_70 ) {
V_30 = & V_2 -> V_325 [ V_70 ] ;
F_173 ( V_2 -> V_23 , & V_30 -> V_188 , F_143 , 64 ) ;
}
V_30 = & V_2 -> V_325 [ V_65 ] ;
F_173 ( V_2 -> V_23 , & V_30 -> V_188 , F_143 , 64 ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
struct V_158 * V_30 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_80 ; ++ V_70 ) {
V_30 = & V_2 -> V_325 [ V_70 ] ;
F_164 ( & V_30 -> V_188 ) ;
}
V_30 = & V_2 -> V_325 [ V_65 ] ;
F_164 ( & V_30 -> V_188 ) ;
}
static void F_175 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
struct V_158 * V_30 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_80 ; ++ V_70 ) {
V_30 = & V_2 -> V_325 [ V_70 ] ;
F_166 ( & V_30 -> V_188 ) ;
}
V_30 = & V_2 -> V_325 [ V_65 ] ;
F_166 ( & V_30 -> V_188 ) ;
}
static void F_176 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
struct V_158 * V_30 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_80 ; ++ V_70 ) {
V_30 = & V_2 -> V_325 [ V_70 ] ;
F_168 ( & V_30 -> V_188 ) ;
}
V_30 = & V_2 -> V_325 [ V_65 ] ;
F_168 ( & V_30 -> V_188 ) ;
}
static int F_177 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_70 ;
T_2 V_332 ;
T_2 V_333 ;
T_2 V_334 ;
int V_59 ;
V_333 = F_27 ( V_2 , V_336 ) ;
V_332 = V_333 & V_337 ;
V_333 &= ~ V_337 ;
F_28 ( V_2 , V_333 , V_336 ) ;
V_333 = 0 ;
V_334 = 0 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_80 ; V_70 ++ ) {
V_59 = F_160 ( V_2 , V_70 ,
V_2 -> V_8 -> V_349 ,
V_70 * V_2 -> V_8 -> V_349 ,
( V_70 + 1 ) *
V_2 -> V_8 -> V_349 ) ;
if ( V_59 )
return V_59 ;
V_334 |= ( 1 << V_70 ) ;
V_333 |= ( 1 << ( V_70 + V_341 ) ) ;
}
V_59 = F_160 ( V_2 , V_65 , V_350 ,
V_2 -> V_8 -> V_80 *
V_2 -> V_8 -> V_349 ,
V_344 ) ;
if ( V_59 )
return V_59 ;
V_334 |= ( 1 << V_65 ) ;
V_333 |= ( 1 << ( V_65 + V_341 ) ) ;
F_172 ( V_2 ) ;
F_28 ( V_2 , V_334 , V_348 ) ;
if ( V_332 )
V_333 |= V_337 ;
F_28 ( V_2 , V_333 , V_336 ) ;
return 0 ;
}
static int F_178 ( struct V_1 * V_2 )
{
int V_59 = 0 ;
int V_288 = 0 ;
T_2 V_71 ;
T_2 V_333 ;
int V_70 ;
V_71 = F_25 ( V_2 , V_336 ) ;
V_71 &= ~ V_337 ;
F_26 ( V_2 , V_71 , V_336 ) ;
while ( V_288 ++ < V_351 ) {
V_71 = F_25 ( V_2 , V_352 ) ;
if ( V_71 & V_353 )
break;
F_149 ( 1 ) ;
}
if ( V_288 == V_351 ) {
F_179 ( V_2 -> V_23 , L_19 ) ;
V_59 = - V_290 ;
}
F_147 ( 10000 , 20000 ) ;
V_71 = F_27 ( V_2 , V_336 ) ;
V_71 &= ~ V_337 ;
F_28 ( V_2 , V_71 , V_336 ) ;
V_288 = 0 ;
while ( V_288 ++ < V_351 ) {
V_71 = F_27 ( V_2 , V_352 ) ;
if ( V_71 & V_353 )
break;
F_149 ( 1 ) ;
}
if ( V_288 == V_351 ) {
F_179 ( V_2 -> V_23 , L_20 ) ;
V_59 = - V_290 ;
}
V_333 = 0 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_80 ; V_70 ++ )
V_333 |= ( 1 << ( V_70 + V_341 ) ) ;
V_71 = F_27 ( V_2 , V_336 ) ;
V_71 &= ~ V_333 ;
F_28 ( V_2 , V_71 , V_336 ) ;
V_333 = 0 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_79 ; V_70 ++ )
V_333 |= ( 1 << ( V_70 + V_341 ) ) ;
V_71 = F_25 ( V_2 , V_336 ) ;
V_71 &= ~ V_333 ;
F_26 ( V_2 , V_71 , V_336 ) ;
return V_59 ;
}
static void F_180 ( struct V_1 * V_2 )
{
int V_70 ;
F_176 ( V_2 ) ;
F_167 ( V_2 ) ;
F_178 ( V_2 ) ;
for ( V_70 = 0 ; V_70 < V_2 -> V_354 ; V_70 ++ ) {
if ( V_2 -> V_175 [ V_70 ] . V_156 != NULL ) {
F_114 ( V_2 -> V_175 [ V_70 ] . V_156 ) ;
V_2 -> V_175 [ V_70 ] . V_156 = NULL ;
}
}
F_145 ( V_2 ) ;
F_181 ( V_2 -> V_263 ) ;
F_181 ( V_2 -> V_175 ) ;
}
static int F_182 ( struct V_1 * V_2 )
{
int V_59 ;
unsigned int V_70 ;
struct V_148 * V_155 ;
F_92 ( V_2 , V_131 , V_2 -> V_23 , L_15 , V_174 ) ;
V_2 -> V_355 = V_2 -> V_17 + V_2 -> V_8 -> V_356 ;
V_2 -> V_285 = V_344 ;
V_2 -> V_263 = F_183 ( V_2 -> V_285 , sizeof( struct V_148 ) ,
V_357 ) ;
if ( ! V_2 -> V_263 )
return - V_284 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_285 ; V_70 ++ ) {
V_155 = V_2 -> V_263 + V_70 ;
V_155 -> V_211 = V_2 -> V_355 + V_70 * V_358 ;
}
V_2 -> V_359 = V_2 -> V_17 + V_2 -> V_8 -> V_360 ;
V_2 -> V_354 = V_344 ;
V_2 -> V_175 = F_183 ( V_2 -> V_354 , sizeof( struct V_148 ) ,
V_357 ) ;
if ( ! V_2 -> V_175 ) {
F_181 ( V_2 -> V_263 ) ;
return - V_284 ;
}
for ( V_70 = 0 ; V_70 < V_2 -> V_354 ; V_70 ++ ) {
V_155 = V_2 -> V_175 + V_70 ;
V_155 -> V_211 = V_2 -> V_359 + V_70 * V_358 ;
}
F_28 ( V_2 , V_361 , V_362 ) ;
V_59 = F_177 ( V_2 -> V_23 ) ;
if ( V_59 ) {
F_131 ( V_2 -> V_23 , L_21 ) ;
F_145 ( V_2 ) ;
F_181 ( V_2 -> V_263 ) ;
F_181 ( V_2 -> V_175 ) ;
return V_59 ;
}
F_26 ( V_2 , V_361 , V_362 ) ;
F_169 ( V_2 -> V_23 ) ;
return 0 ;
}
static void F_184 ( struct V_363 * V_364 )
{
struct V_1 * V_2 = F_104 (
V_364 , struct V_1 , V_365 ) ;
F_92 ( V_2 , V_366 , V_2 -> V_23 , L_15 , V_174 ) ;
if ( V_2 -> V_367 & V_368 ) {
V_2 -> V_367 &= ~ V_368 ;
F_92 ( V_2 , V_369 , V_2 -> V_23 ,
L_22 ) ;
F_71 ( V_2 , V_135 ) ;
}
if ( V_2 -> V_367 & V_294 ) {
F_185 ( V_2 -> V_38 ,
! ! ( V_2 -> V_367 & V_370 ) ) ;
V_2 -> V_367 &= ~ V_294 ;
}
}
static T_9 F_186 ( int V_371 , void * V_372 )
{
struct V_1 * V_2 = V_372 ;
struct V_158 * V_373 ;
struct V_149 * V_374 ;
unsigned int V_163 ;
V_2 -> V_375 =
F_187 ( V_2 , V_376 ) &
~ F_187 ( V_2 , V_377 ) ;
F_84 ( V_2 , V_2 -> V_375 , V_291 ) ;
F_92 ( V_2 , V_366 , V_2 -> V_23 ,
L_23 , V_174 , V_2 -> V_375 ) ;
for ( V_163 = 0 ; V_163 < V_2 -> V_8 -> V_80 ; V_163 ++ ) {
if ( ! ( V_2 -> V_375 & F_156 ( V_162 + V_163 ) ) )
continue;
V_373 = & V_2 -> V_325 [ V_163 ] ;
if ( F_91 ( F_188 ( & V_373 -> V_188 ) ) ) {
V_373 -> V_316 ( V_373 ) ;
F_189 ( & V_373 -> V_188 ) ;
}
}
for ( V_163 = 0 ; V_163 < V_2 -> V_8 -> V_79 ; V_163 ++ ) {
if ( ! ( V_2 -> V_375 & F_156 ( V_163 ) ) )
continue;
V_374 = & V_2 -> V_192 [ V_163 ] ;
if ( F_91 ( F_188 ( & V_374 -> V_188 ) ) ) {
V_374 -> V_316 ( V_374 ) ;
F_189 ( & V_374 -> V_188 ) ;
}
}
return V_378 ;
}
static T_9 F_190 ( int V_371 , void * V_372 )
{
struct V_1 * V_2 = V_372 ;
struct V_158 * V_373 ;
struct V_149 * V_374 ;
V_2 -> V_367 =
F_191 ( V_2 , V_376 ) &
~ F_191 ( V_2 , V_377 ) ;
F_81 ( V_2 , V_2 -> V_367 , V_291 ) ;
F_92 ( V_2 , V_366 , V_2 -> V_23 ,
L_24 , V_2 -> V_367 ) ;
if ( V_2 -> V_367 & V_159 ) {
V_373 = & V_2 -> V_325 [ V_65 ] ;
if ( F_91 ( F_188 ( & V_373 -> V_188 ) ) ) {
V_373 -> V_316 ( V_373 ) ;
F_189 ( & V_373 -> V_188 ) ;
}
}
if ( V_2 -> V_367 & V_164 ) {
V_374 = & V_2 -> V_192 [ V_65 ] ;
if ( F_91 ( F_188 ( & V_374 -> V_188 ) ) ) {
V_374 -> V_316 ( V_374 ) ;
F_189 ( & V_374 -> V_188 ) ;
}
}
if ( V_2 -> V_367 & ( V_379 |
V_380 |
V_294 |
V_381 |
V_382 |
V_368 ) ) {
F_192 ( & V_2 -> V_365 ) ;
}
if ( ( V_2 -> V_8 -> V_9 & V_310 ) &&
V_2 -> V_367 & ( V_311 | V_312 ) ) {
V_2 -> V_367 &= ~ ( V_311 | V_312 ) ;
F_193 ( & V_2 -> V_383 ) ;
}
return V_378 ;
}
static T_9 F_194 ( int V_371 , void * V_372 )
{
struct V_1 * V_2 = V_372 ;
F_195 ( & V_2 -> V_196 -> V_23 , 0 ) ;
return V_378 ;
}
static void F_196 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_197 ( V_2 -> V_384 ) ;
F_190 ( V_2 -> V_384 , V_2 ) ;
F_198 ( V_2 -> V_384 ) ;
F_197 ( V_2 -> V_385 ) ;
F_186 ( V_2 -> V_385 , V_2 ) ;
F_198 ( V_2 -> V_385 ) ;
}
static void F_199 ( struct V_1 * V_2 )
{
T_2 V_71 ;
V_71 = F_11 ( V_2 ) ;
V_71 |= F_156 ( 1 ) ;
F_15 ( V_2 , V_71 ) ;
F_149 ( 10 ) ;
V_71 &= ~ F_156 ( 1 ) ;
F_15 ( V_2 , V_71 ) ;
F_149 ( 10 ) ;
}
static void F_200 ( struct V_1 * V_2 ,
unsigned char * V_6 )
{
F_52 ( V_2 , ( V_6 [ 0 ] << 24 ) | ( V_6 [ 1 ] << 16 ) |
( V_6 [ 2 ] << 8 ) | V_6 [ 3 ] , V_386 ) ;
F_52 ( V_2 , ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] , V_387 ) ;
}
static T_2 F_201 ( struct V_1 * V_2 )
{
T_2 V_71 ;
T_2 V_333 ;
V_333 = 1 << ( V_65 + V_341 ) | V_337 ;
V_71 = F_25 ( V_2 , V_336 ) ;
V_71 &= ~ V_333 ;
F_26 ( V_2 , V_71 , V_336 ) ;
V_71 = F_27 ( V_2 , V_336 ) ;
V_71 &= ~ V_333 ;
F_28 ( V_2 , V_71 , V_336 ) ;
F_52 ( V_2 , 1 , V_388 ) ;
F_149 ( 10 ) ;
F_52 ( V_2 , 0 , V_388 ) ;
return V_333 ;
}
static void F_202 ( struct V_1 * V_2 , T_2 V_333 )
{
T_2 V_71 ;
V_71 = F_27 ( V_2 , V_336 ) ;
V_71 |= V_333 ;
F_28 ( V_2 , V_71 , V_336 ) ;
V_71 = F_25 ( V_2 , V_336 ) ;
V_71 |= V_333 ;
F_26 ( V_2 , V_71 , V_336 ) ;
}
static bool F_203 ( struct V_1 * V_2 ,
T_2 V_389 )
{
T_2 V_97 ;
T_2 V_71 ;
V_97 = V_390 + ( V_389 < 32 ) * sizeof( T_2 ) ;
V_71 = F_204 ( V_2 , V_97 ) ;
return ! ! ( V_71 & ( 1 << ( V_389 % 32 ) ) ) ;
}
static void F_205 ( struct V_1 * V_2 , T_2 V_389 )
{
T_2 V_97 ;
T_2 V_71 ;
V_97 = V_390 + ( V_389 < 32 ) * sizeof( T_2 ) ;
V_71 = F_204 ( V_2 , V_97 ) ;
V_71 |= ( 1 << ( V_389 % 32 ) ) ;
F_206 ( V_2 , V_71 , V_97 ) ;
}
static void F_207 ( struct V_1 * V_2 ,
T_2 V_389 , T_2 V_391 )
{
T_2 V_97 ;
T_2 V_71 ;
V_97 = V_389 / 8 ;
V_71 = F_27 ( V_2 , V_392 + V_97 ) ;
V_71 &= ~ ( 0xF << ( 4 * ( V_389 % 8 ) ) ) ;
V_71 |= ( ( V_391 & 0xF ) << ( 4 * ( V_389 % 8 ) ) ) ;
F_28 ( V_2 , V_71 , V_392 + V_97 ) ;
}
static void F_208 ( struct V_1 * V_2 ,
T_2 V_389 , T_2 V_393 )
{
T_2 V_97 ;
T_2 V_71 ;
V_97 = V_394 +
( ( V_2 -> V_8 -> V_395 - 1 - V_389 ) / 4 ) *
sizeof( T_2 ) ;
V_71 = F_204 ( V_2 , V_97 ) ;
V_71 &= ~ ( 0xFF << ( 8 * ( V_389 % 4 ) ) ) ;
V_71 |= ( ( V_393 & 0xFF ) << ( 8 * ( V_389 % 4 ) ) ) ;
F_206 ( V_2 , V_71 , V_97 ) ;
}
static int F_209 ( struct V_1 * V_2 )
{
T_2 V_389 ;
for ( V_389 = 0 ; V_389 < V_2 -> V_8 -> V_395 ; V_389 ++ )
if ( ! F_203 ( V_2 , V_389 ) )
return V_389 ;
return - V_284 ;
}
int F_210 ( struct V_1 * V_2 , T_2 * V_396 ,
T_2 V_393 , T_2 V_391 )
{
int V_389 ;
T_2 V_70 ;
V_389 = F_209 ( V_2 ) ;
if ( V_389 < 0 )
return - V_284 ;
if ( V_393 > V_2 -> V_8 -> V_397 )
return - V_37 ;
for ( V_70 = 0 ; V_70 < V_393 ; V_70 ++ )
F_211 ( V_2 , V_396 [ V_70 ] ,
( V_389 * V_2 -> V_8 -> V_397 + V_70 ) *
sizeof( T_2 ) ) ;
F_208 ( V_2 , V_389 , 2 * V_393 ) ;
F_207 ( V_2 , V_389 , V_391 ) ;
F_205 ( V_2 , V_389 ) ;
F_206 ( V_2 , 0x1 , V_398 ) ;
return 0 ;
}
static void F_212 ( struct V_1 * V_2 )
{
T_2 V_70 ;
F_206 ( V_2 , 0x0 , V_398 ) ;
F_206 ( V_2 , 0x0 , V_390 ) ;
F_206 ( V_2 , 0x0 , V_390 + 4 ) ;
for ( V_70 = V_392 ; V_70 <= V_399 ; V_70 ++ )
F_28 ( V_2 , 0x0 , V_70 ) ;
for ( V_70 = 0 ; V_70 < ( V_2 -> V_8 -> V_395 / 4 ) ; V_70 ++ )
F_206 ( V_2 , 0x0 ,
V_394 + V_70 * sizeof( T_2 ) ) ;
for ( V_70 = 0 ; V_70 < V_2 -> V_8 -> V_395 *
V_2 -> V_8 -> V_397 ; V_70 ++ )
F_211 ( V_2 , 0x0 , V_70 * sizeof( T_2 ) ) ;
}
static void F_213 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) || F_155 ( V_2 ) )
return;
F_212 ( V_2 ) ;
}
static void F_214 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_174 ( V_2 ) ;
F_163 ( V_2 ) ;
F_146 ( V_2 , V_400 | V_401 , true ) ;
F_215 ( V_23 ) ;
F_152 ( V_2 ) ;
F_216 ( V_2 -> V_38 ) ;
}
static int F_217 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned long V_333 ;
T_2 V_71 ;
int V_59 ;
F_92 ( V_2 , V_402 , V_23 , L_25 ) ;
F_55 ( V_2 -> V_403 ) ;
if ( V_2 -> V_293 )
F_71 ( V_2 , V_136 ) ;
F_199 ( V_2 ) ;
V_59 = F_153 ( V_2 ) ;
if ( V_59 )
goto V_404;
F_146 ( V_2 , V_400 | V_401 , false ) ;
V_71 = F_51 ( V_2 , V_287 ) ;
V_2 -> V_47 = ! ! ( V_71 & V_405 ) ;
F_200 ( V_2 , V_23 -> V_406 ) ;
if ( V_2 -> V_293 ) {
V_71 = F_68 ( V_2 , V_138 ) ;
V_71 |= V_407 ;
F_69 ( V_2 , V_71 , V_138 ) ;
}
V_333 = F_201 ( V_2 ) ;
V_59 = F_182 ( V_2 ) ;
if ( V_59 ) {
F_131 ( V_23 , L_26 ) ;
goto V_404;
}
F_202 ( V_2 , V_333 ) ;
F_213 ( V_2 ) ;
V_59 = F_218 ( V_2 -> V_384 , F_190 , V_408 ,
V_23 -> V_409 , V_2 ) ;
if ( V_59 < 0 ) {
F_131 ( V_23 , L_27 , V_2 -> V_384 ) ;
goto V_410;
}
V_59 = F_218 ( V_2 -> V_385 , F_186 , V_408 ,
V_23 -> V_409 , V_2 ) ;
if ( V_59 < 0 ) {
F_131 ( V_23 , L_27 , V_2 -> V_385 ) ;
goto V_411;
}
V_59 = F_219 ( V_23 ) ;
if ( V_59 ) {
F_131 ( V_23 , L_28 ) ;
goto V_412;
}
F_214 ( V_23 ) ;
return 0 ;
V_412:
F_220 ( V_2 -> V_385 , V_2 ) ;
V_411:
F_220 ( V_2 -> V_384 , V_2 ) ;
V_410:
F_180 ( V_2 ) ;
V_404:
F_56 ( V_2 -> V_403 ) ;
return V_59 ;
}
static void F_221 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_222 ( V_23 ) ;
F_223 ( V_2 -> V_38 ) ;
F_151 ( V_2 ) ;
F_175 ( V_2 ) ;
F_165 ( V_2 ) ;
F_224 ( & V_2 -> V_365 ) ;
V_2 -> V_413 = - 1 ;
V_2 -> V_414 = - 1 ;
V_2 -> V_415 = - 1 ;
V_2 -> V_416 = - 1 ;
}
static int F_225 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_59 ;
F_92 ( V_2 , V_417 , V_23 , L_29 ) ;
F_221 ( V_23 ) ;
F_226 ( V_2 -> V_38 ) ;
F_146 ( V_2 , V_401 , false ) ;
V_59 = F_178 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_146 ( V_2 , V_400 , false ) ;
F_106 ( V_23 ) ;
F_180 ( V_2 ) ;
F_220 ( V_2 -> V_384 , V_2 ) ;
F_220 ( V_2 -> V_385 , V_2 ) ;
if ( V_2 -> V_293 )
V_59 = F_65 ( V_2 , V_136 ) ;
F_56 ( V_2 -> V_403 ) ;
return V_59 ;
}
static void F_227 ( struct V_149 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_2 V_253 , V_168 , V_418 , V_419 ;
struct V_165 * V_166 ;
unsigned int V_182 ;
unsigned long V_9 ;
bool V_420 ;
if ( ! F_228 ( V_2 ) )
return;
V_166 = F_97 ( V_2 -> V_23 , V_30 -> V_184 ) ;
F_101 ( & V_30 -> V_186 , V_9 ) ;
if ( V_30 -> V_163 == V_65 ) {
V_418 = ~ F_191 ( V_2 , V_377 ) ;
V_419 = V_164 | V_421 ;
} else {
V_418 = ~ F_187 ( V_2 , V_377 ) ;
V_419 = 1 << V_30 -> V_163 ;
}
V_168 = F_29 ( V_2 , V_30 -> V_163 , V_171 ) ;
V_253 = F_29 ( V_2 , V_30 -> V_163 , V_241 ) ;
V_420 = F_98 ( V_166 ) ;
V_182 = V_30 -> V_182 ;
F_102 ( & V_30 -> V_186 , V_9 ) ;
F_61 ( V_2 , V_203 , V_2 -> V_23 , L_30
L_31
L_32
L_33
L_34
L_35
L_36 ,
V_30 -> V_163 , V_30 -> V_184 ,
V_420 ? L_37 : L_38 ,
V_418 & V_419 ? L_39 : L_40 ,
V_182 , V_30 -> V_213 ,
V_30 -> V_238 , V_253 & V_239 ,
V_30 -> V_168 , V_168 & V_172 ,
V_30 -> V_176 , V_30 -> V_152 ,
V_30 -> V_153 , V_30 -> V_154 ) ;
}
static void F_229 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_292 = 0 ;
T_2 V_299 = 0 ;
unsigned int V_422 ;
F_92 ( V_2 , V_203 , V_23 , L_41 ) ;
for ( V_422 = 0 ; V_422 < V_2 -> V_8 -> V_79 ; V_422 ++ )
F_227 ( & V_2 -> V_192 [ V_422 ] ) ;
F_227 ( & V_2 -> V_192 [ V_65 ] ) ;
F_106 ( V_23 ) ;
for ( V_422 = 0 ; V_422 < V_2 -> V_8 -> V_79 ; V_422 ++ )
V_299 |= ( 1 << V_422 ) ;
V_292 = V_164 ;
F_81 ( V_2 , V_292 , V_161 ) ;
F_84 ( V_2 , V_299 , V_161 ) ;
V_23 -> V_423 = V_424 ;
V_23 -> V_111 . V_425 ++ ;
F_230 ( V_23 ) ;
}
static inline void F_231 ( struct V_1 * V_2 ,
unsigned char * V_6 ,
int * V_70 ,
int * V_426 )
{
T_2 V_71 ;
F_52 ( V_2 , V_6 [ 0 ] << 8 | V_6 [ 1 ] ,
V_427 + ( * V_70 * 4 ) ) ;
F_52 ( V_2 , V_6 [ 2 ] << 24 | V_6 [ 3 ] << 16 |
V_6 [ 4 ] << 8 | V_6 [ 5 ] ,
V_427 + ( ( * V_70 + 1 ) * 4 ) ) ;
V_71 = F_51 ( V_2 , V_428 ) ;
V_71 |= ( 1 << ( V_429 - * V_426 ) ) ;
F_52 ( V_2 , V_71 , V_428 ) ;
* V_70 += 2 ;
( * V_426 ) ++ ;
}
static void F_232 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_430 * V_431 ;
int V_70 , V_426 ;
T_2 V_71 ;
F_92 ( V_2 , V_131 , V_23 , L_42 , V_174 , V_23 -> V_9 ) ;
V_71 = F_51 ( V_2 , V_287 ) ;
if ( V_23 -> V_9 & V_432 ) {
V_71 |= V_433 ;
F_52 ( V_2 , V_71 , V_287 ) ;
F_52 ( V_2 , 0 , V_428 ) ;
return;
} else {
V_71 &= ~ V_433 ;
F_52 ( V_2 , V_71 , V_287 ) ;
}
if ( V_23 -> V_9 & V_434 ) {
F_179 ( V_23 , L_43 ) ;
return;
}
V_70 = 0 ;
V_426 = 0 ;
F_231 ( V_2 , V_23 -> V_435 , & V_70 , & V_426 ) ;
F_231 ( V_2 , V_23 -> V_406 , & V_70 , & V_426 ) ;
if ( F_233 ( V_23 ) > ( V_429 - V_426 ) )
return;
if ( ! F_234 ( V_23 ) )
F_235 (ha, dev)
F_231 ( V_2 , V_431 -> V_6 , & V_70 , & V_426 ) ;
if ( F_236 ( V_23 ) || F_237 ( V_23 ) >= ( V_429 - V_426 ) )
return;
F_238 (ha, dev)
F_231 ( V_2 , V_431 -> V_6 , & V_70 , & V_426 ) ;
}
static int F_239 ( struct V_34 * V_23 , void * V_98 )
{
struct V_436 * V_6 = V_98 ;
if ( F_34 ( V_23 ) )
return - V_437 ;
F_240 ( V_23 -> V_406 , V_6 -> V_438 ) ;
return 0 ;
}
static void F_241 ( struct V_1 * V_2 )
{
struct V_439 * V_440 ;
T_2 V_71 ;
T_5 V_441 ;
T_6 V_442 ;
if ( F_242 ( V_2 ) ) {
V_28 = V_443 ;
V_33 = V_444 ;
V_2 -> V_276 = V_445 ;
V_2 -> V_85 = V_446 ;
} else if ( F_243 ( V_2 ) ) {
V_28 = V_443 ;
V_33 = V_447 ;
V_2 -> V_276 = V_445 ;
V_2 -> V_85 = V_448 ;
} else if ( F_155 ( V_2 ) ) {
V_28 = V_449 ;
V_33 = V_447 ;
V_2 -> V_276 = V_450 ;
V_2 -> V_85 = V_451 ;
} else if ( F_12 ( V_2 ) ) {
V_28 = V_452 ;
V_33 = V_447 ;
V_2 -> V_276 = V_450 ;
V_2 -> V_85 = V_453 ;
}
V_2 -> V_8 = & V_439 [ V_2 -> V_85 ] ;
V_440 = V_2 -> V_8 ;
V_71 = F_14 ( V_2 , V_454 ) ;
V_441 = ( V_71 >> 24 & 0x0f ) ;
if ( V_441 == 5 )
V_441 = 4 ;
else if ( V_441 == 0 )
V_441 = 1 ;
if ( V_441 != V_2 -> V_85 ) {
F_150 ( & V_2 -> V_196 -> V_23 ,
L_44 ,
V_441 , V_2 -> V_85 ) ;
}
F_244 ( & V_2 -> V_196 -> V_23 , L_45 V_455 ,
V_441 , ( V_71 >> 16 ) & 0x0f , V_71 & 0xffff ) ;
V_442 = V_71 & 0xffff ;
if ( ( V_442 & 0xf0 ) != 0 )
V_2 -> V_442 = V_442 << 8 ;
else if ( ( V_442 & 0xff00 ) != 0 )
V_2 -> V_442 = V_442 ;
else if ( V_442 == 0 || V_442 == 0x01ff ) {
F_245 ( L_46 , V_442 ) ;
return;
}
#ifdef F_7
if ( ! ( V_440 -> V_9 & V_10 ) )
F_245 ( L_47 ) ;
#endif
F_246 ( L_48
L_49
L_50
L_51
L_52
L_53
L_54 ,
V_2 -> V_85 ,
V_440 -> V_79 , V_440 -> V_340 ,
V_440 -> V_80 , V_440 -> V_349 ,
V_440 -> V_308 , V_440 -> V_309 ,
V_440 -> V_395 , V_440 -> V_205 ,
V_440 -> V_18 , V_440 -> V_456 ,
V_440 -> V_457 ,
V_440 -> V_356 , V_440 -> V_360 ,
V_440 -> V_314 ) ;
}
static int F_247 ( struct V_458 * V_196 )
{
struct V_459 * V_460 = V_196 -> V_23 . V_461 ;
struct V_462 * V_463 = V_196 -> V_23 . V_464 ;
const struct V_465 * V_466 = NULL ;
struct V_1 * V_2 ;
struct V_34 * V_23 ;
const void * V_467 ;
struct V_468 * V_25 ;
int V_469 = - V_470 ;
V_23 = F_248 ( sizeof( * V_2 ) , V_471 + 1 ,
V_471 + 1 ) ;
if ( ! V_23 ) {
F_150 ( & V_196 -> V_23 , L_55 ) ;
return - V_284 ;
}
if ( V_463 ) {
V_466 = F_249 ( V_472 , V_463 ) ;
if ( ! V_466 )
return - V_37 ;
}
V_2 = F_23 ( V_23 ) ;
V_2 -> V_384 = F_250 ( V_196 , 0 ) ;
V_2 -> V_385 = F_250 ( V_196 , 1 ) ;
V_2 -> V_473 = F_250 ( V_196 , 2 ) ;
if ( ! V_2 -> V_384 || ! V_2 -> V_385 ) {
F_150 ( & V_196 -> V_23 , L_56 ) ;
V_469 = - V_37 ;
goto V_469;
}
if ( V_463 ) {
V_467 = F_251 ( V_463 ) ;
if ( ! V_467 ) {
F_150 ( & V_196 -> V_23 , L_57 ) ;
V_469 = - V_37 ;
goto V_469;
}
} else {
V_467 = V_460 -> V_474 ;
}
V_25 = F_252 ( V_196 , V_475 , 0 ) ;
V_2 -> V_17 = F_253 ( & V_196 -> V_23 , V_25 ) ;
if ( F_254 ( V_2 -> V_17 ) ) {
V_469 = F_255 ( V_2 -> V_17 ) ;
goto V_469;
}
F_256 ( V_23 , & V_196 -> V_23 ) ;
F_257 ( & V_196 -> V_23 , V_23 ) ;
F_240 ( V_23 -> V_406 , V_467 ) ;
V_23 -> V_476 = 2 * V_477 ;
V_23 -> V_478 = & V_479 ;
V_23 -> V_480 = & V_481 ;
V_2 -> V_60 = F_258 ( - 1 , V_482 ) ;
V_23 -> V_483 |= V_484 | V_53 |
V_54 | V_43 ;
V_2 -> V_485 = true ;
V_469 = F_259 ( & V_196 -> V_23 , V_2 -> V_473 , F_194 , 0 ,
V_23 -> V_409 , V_2 ) ;
if ( ! V_469 )
F_260 ( & V_196 -> V_23 , 1 ) ;
V_23 -> V_486 += 64 ;
F_261 ( V_23 ) ;
V_2 -> V_23 = V_23 ;
V_2 -> V_196 = V_196 ;
if ( V_466 )
V_2 -> V_85 = (enum V_487 ) V_466 -> V_90 ;
else
V_2 -> V_85 = V_460 -> V_488 ;
V_2 -> V_403 = F_262 ( & V_2 -> V_196 -> V_23 , L_58 ) ;
if ( F_254 ( V_2 -> V_403 ) ) {
F_263 ( & V_2 -> V_196 -> V_23 , L_59 ) ;
V_2 -> V_403 = NULL ;
}
F_55 ( V_2 -> V_403 ) ;
F_241 ( V_2 ) ;
F_264 ( & V_2 -> V_383 ) ;
V_2 -> V_243 = V_319 ;
F_265 ( & V_2 -> V_365 , F_184 ) ;
V_2 -> V_489 = F_262 ( & V_2 -> V_196 -> V_23 , L_60 ) ;
if ( F_254 ( V_2 -> V_489 ) ) {
F_263 ( & V_2 -> V_196 -> V_23 , L_61 ) ;
V_2 -> V_489 = NULL ;
}
V_2 -> V_116 = F_262 ( & V_2 -> V_196 -> V_23 , L_62 ) ;
if ( F_254 ( V_2 -> V_116 ) ) {
F_263 ( & V_2 -> V_196 -> V_23 , L_63 ) ;
V_2 -> V_116 = NULL ;
}
V_469 = F_148 ( V_2 ) ;
if ( V_469 )
goto V_404;
V_469 = F_266 ( V_23 ) ;
if ( V_469 )
goto V_404;
F_267 ( V_2 -> V_23 , V_2 -> V_8 -> V_79 + 1 ) ;
F_268 ( V_2 -> V_23 , V_2 -> V_8 -> V_80 + 1 ) ;
F_269 ( V_23 ) ;
F_56 ( V_2 -> V_403 ) ;
V_469 = F_270 ( V_23 ) ;
if ( V_469 )
goto V_469;
return V_469 ;
V_404:
F_56 ( V_2 -> V_403 ) ;
V_469:
F_271 ( V_23 ) ;
return V_469 ;
}
static int F_272 ( struct V_458 * V_196 )
{
struct V_1 * V_2 = F_22 ( & V_196 -> V_23 ) ;
F_257 ( & V_196 -> V_23 , NULL ) ;
F_273 ( V_2 -> V_23 ) ;
F_274 ( V_2 -> V_23 ) ;
F_271 ( V_2 -> V_23 ) ;
return 0 ;
}
static int F_275 ( struct V_22 * V_3 )
{
struct V_34 * V_23 = F_24 ( V_3 ) ;
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_59 ;
if ( ! F_34 ( V_23 ) )
return 0 ;
F_221 ( V_23 ) ;
F_276 ( V_2 -> V_38 ) ;
F_277 ( V_23 ) ;
F_146 ( V_2 , V_401 , false ) ;
V_59 = F_178 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_146 ( V_2 , V_400 , false ) ;
F_106 ( V_23 ) ;
F_180 ( V_2 ) ;
if ( F_278 ( V_3 ) && V_2 -> V_490 ) {
V_59 = F_65 ( V_2 , V_135 ) ;
F_55 ( V_2 -> V_489 ) ;
} else if ( V_2 -> V_293 ) {
V_59 = F_65 ( V_2 , V_136 ) ;
}
F_56 ( V_2 -> V_403 ) ;
return V_59 ;
}
static int F_279 ( struct V_22 * V_3 )
{
struct V_34 * V_23 = F_24 ( V_3 ) ;
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned long V_333 ;
int V_59 ;
T_2 V_71 ;
if ( ! F_34 ( V_23 ) )
return 0 ;
V_59 = F_55 ( V_2 -> V_403 ) ;
if ( V_59 )
return V_59 ;
if ( V_2 -> V_293 )
F_71 ( V_2 , V_136 ) ;
F_199 ( V_2 ) ;
V_59 = F_153 ( V_2 ) ;
if ( V_59 )
goto V_491;
if ( V_2 -> V_490 )
F_56 ( V_2 -> V_489 ) ;
F_280 ( V_2 -> V_38 ) ;
F_281 ( V_2 -> V_23 ) ;
F_146 ( V_2 , V_400 | V_401 , false ) ;
F_200 ( V_2 , V_23 -> V_406 ) ;
if ( V_2 -> V_293 ) {
V_71 = F_68 ( V_2 , V_138 ) ;
V_71 |= V_407 ;
F_69 ( V_2 , V_71 , V_138 ) ;
}
if ( V_2 -> V_490 )
F_71 ( V_2 , V_135 ) ;
V_333 = F_201 ( V_2 ) ;
V_59 = F_182 ( V_2 ) ;
if ( V_59 ) {
F_131 ( V_23 , L_26 ) ;
goto V_491;
}
F_202 ( V_2 , V_333 ) ;
F_282 ( V_23 ) ;
F_283 ( V_2 -> V_38 ) ;
if ( V_2 -> V_124 . V_125 )
F_54 ( V_23 , true ) ;
F_214 ( V_23 ) ;
return 0 ;
V_491:
F_56 ( V_2 -> V_403 ) ;
return V_59 ;
}
