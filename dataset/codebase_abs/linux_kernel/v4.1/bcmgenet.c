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
static void F_43 ( struct V_34 * V_23 ,
struct V_62 * V_63 )
{
F_44 ( V_63 -> V_64 , L_1 , sizeof( V_63 -> V_64 ) ) ;
F_44 ( V_63 -> V_65 , L_2 , sizeof( V_63 -> V_65 ) ) ;
V_63 -> V_66 = V_67 ;
}
static int F_45 ( struct V_34 * V_23 , int V_68 )
{
switch ( V_68 ) {
case V_69 :
return V_67 ;
default:
return - V_70 ;
}
}
static void F_46 ( struct V_34 * V_23 , T_2 V_71 ,
T_5 * V_72 )
{
int V_73 ;
switch ( V_71 ) {
case V_69 :
for ( V_73 = 0 ; V_73 < V_67 ; V_73 ++ ) {
memcpy ( V_72 + V_73 * V_74 ,
V_75 [ V_73 ] . V_76 ,
V_74 ) ;
}
break;
}
}
static void F_47 ( struct V_1 * V_2 )
{
int V_73 , V_77 = 0 ;
for ( V_73 = 0 ; V_73 < V_67 ; V_73 ++ ) {
const struct V_78 * V_79 ;
T_5 V_80 = 0 ;
T_2 V_12 = 0 ;
char * V_81 ;
V_79 = & V_75 [ V_73 ] ;
switch ( V_79 -> type ) {
case V_82 :
case V_83 :
continue;
case V_84 :
case V_85 :
case V_86 :
if ( V_79 -> type != V_84 )
V_80 = V_87 ;
V_12 = F_48 ( V_2 ,
V_88 + V_77 + V_80 ) ;
break;
case V_89 :
V_12 = F_48 ( V_2 , V_79 -> V_90 ) ;
if ( V_12 == ~ 0 )
F_49 ( V_2 , 0 , V_79 -> V_90 ) ;
break;
}
V_77 += V_79 -> V_91 ;
V_81 = ( char * ) V_2 + V_79 -> V_92 ;
* ( T_2 * ) V_81 = V_12 ;
}
}
static void F_50 ( struct V_34 * V_23 ,
struct V_93 * V_94 ,
V_13 * V_72 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_73 ;
if ( F_34 ( V_23 ) )
F_47 ( V_2 ) ;
for ( V_73 = 0 ; V_73 < V_67 ; V_73 ++ ) {
const struct V_78 * V_79 ;
char * V_81 ;
V_79 = & V_75 [ V_73 ] ;
if ( V_79 -> type == V_82 )
V_81 = ( char * ) & V_23 -> V_94 ;
else
V_81 = ( char * ) V_2 ;
V_81 += V_79 -> V_92 ;
V_72 [ V_73 ] = * ( T_2 * ) V_81 ;
}
}
static void F_51 ( struct V_34 * V_23 , bool V_95 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_96 = V_2 -> V_8 -> V_18 + V_97 ;
T_2 V_98 ;
if ( V_95 && ! V_2 -> V_99 ) {
F_52 ( V_2 -> V_100 ) ;
V_2 -> V_99 = true ;
}
V_98 = F_48 ( V_2 , V_101 ) ;
if ( V_95 )
V_98 |= V_102 ;
else
V_98 &= ~ V_102 ;
F_49 ( V_2 , V_98 , V_101 ) ;
V_98 = F_4 ( V_2 -> V_17 + V_96 ) ;
if ( V_95 )
V_98 |= V_103 | V_104 ;
else
V_98 &= ~ ( V_103 | V_104 ) ;
F_2 ( V_98 , V_2 -> V_17 + V_96 ) ;
V_98 = F_13 ( V_2 , V_105 ) ;
if ( V_95 )
V_98 |= V_106 | V_107 ;
else
V_98 &= ~ ( V_106 | V_107 ) ;
F_16 ( V_2 , V_98 , V_105 ) ;
if ( ! V_95 && V_2 -> V_99 ) {
F_53 ( V_2 -> V_100 ) ;
V_2 -> V_99 = false ;
}
V_2 -> V_108 . V_109 = V_95 ;
V_2 -> V_108 . V_110 = V_95 ;
}
static int F_54 ( struct V_34 * V_23 , struct V_111 * V_112 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_111 * V_81 = & V_2 -> V_108 ;
if ( F_12 ( V_2 ) )
return - V_70 ;
V_112 -> V_109 = V_81 -> V_109 ;
V_112 -> V_110 = V_81 -> V_110 ;
V_112 -> V_113 = F_48 ( V_2 , V_114 ) ;
return F_55 ( V_2 -> V_38 , V_112 ) ;
}
static int F_56 ( struct V_34 * V_23 , struct V_111 * V_112 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_111 * V_81 = & V_2 -> V_108 ;
int V_59 = 0 ;
if ( F_12 ( V_2 ) )
return - V_70 ;
V_81 -> V_109 = V_112 -> V_109 ;
if ( ! V_81 -> V_109 ) {
F_51 ( V_23 , false ) ;
} else {
V_59 = F_57 ( V_2 -> V_38 , 0 ) ;
if ( V_59 ) {
F_58 ( V_2 , V_115 , V_23 , L_3 ) ;
return V_59 ;
}
F_49 ( V_2 , V_112 -> V_113 , V_114 ) ;
F_51 ( V_23 , true ) ;
}
return F_59 ( V_2 -> V_38 , V_112 ) ;
}
static int F_60 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
return F_61 ( V_2 -> V_38 ) ;
}
static int F_62 ( struct V_1 * V_2 ,
enum V_116 V_117 )
{
int V_59 = 0 ;
T_2 V_98 ;
switch ( V_117 ) {
case V_118 :
F_63 ( V_2 -> V_38 ) ;
break;
case V_119 :
V_59 = F_64 ( V_2 , V_117 ) ;
break;
case V_120 :
if ( V_2 -> V_8 -> V_9 & V_121 ) {
V_98 = F_65 ( V_2 , V_122 ) ;
V_98 |= ( V_123 |
V_124 | V_125 ) ;
F_66 ( V_2 , V_98 , V_122 ) ;
F_67 ( V_2 -> V_23 , false ) ;
}
break;
default:
break;
}
return 0 ;
}
static void F_68 ( struct V_1 * V_2 ,
enum V_116 V_117 )
{
T_2 V_98 ;
if ( ! ( V_2 -> V_8 -> V_9 & V_121 ) )
return;
V_98 = F_65 ( V_2 , V_122 ) ;
switch ( V_117 ) {
case V_120 :
V_98 &= ~ ( V_124 | V_123 |
V_125 ) ;
case V_118 :
V_98 |= V_126 ;
break;
case V_119 :
F_69 ( V_2 , V_117 ) ;
return;
default:
break;
}
F_66 ( V_2 , V_98 , V_122 ) ;
if ( V_117 == V_120 )
F_70 ( V_2 -> V_23 ) ;
}
static int F_71 ( struct V_34 * V_23 , struct V_127 * V_128 , int V_36 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_12 = 0 ;
if ( ! F_34 ( V_23 ) )
return - V_37 ;
switch ( V_36 ) {
case V_129 :
case V_130 :
case V_131 :
if ( ! V_2 -> V_38 )
V_12 = - V_39 ;
else
V_12 = F_72 ( V_2 -> V_38 , V_128 , V_36 ) ;
break;
default:
V_12 = - V_37 ;
break;
}
return V_12 ;
}
static struct V_132 * F_73 ( struct V_1 * V_2 ,
struct V_133 * V_30 )
{
struct V_132 * V_134 ;
V_134 = V_30 -> V_135 ;
V_134 += V_30 -> V_136 - V_30 -> V_137 ;
if ( V_30 -> V_136 == V_30 -> V_138 )
V_30 -> V_136 = V_30 -> V_137 ;
else
V_30 -> V_136 ++ ;
return V_134 ;
}
static void F_74 ( struct V_132 * V_139 )
{
F_75 ( V_139 -> V_140 ) ;
V_139 -> V_140 = NULL ;
F_76 ( V_139 , V_141 , 0 ) ;
}
static inline void F_77 ( struct V_142 * V_30 )
{
F_78 ( V_30 -> V_2 , V_143 ,
V_144 ) ;
}
static inline void F_79 ( struct V_142 * V_30 )
{
F_78 ( V_30 -> V_2 , V_143 ,
V_145 ) ;
}
static inline void F_80 ( struct V_142 * V_30 )
{
F_81 ( V_30 -> V_2 ,
1 << ( V_146 + V_30 -> V_147 ) ,
V_144 ) ;
}
static inline void F_82 ( struct V_142 * V_30 )
{
F_81 ( V_30 -> V_2 ,
1 << ( V_146 + V_30 -> V_147 ) ,
V_145 ) ;
}
static inline void F_83 ( struct V_133 * V_30 )
{
F_78 ( V_30 -> V_2 , V_148 ,
V_144 ) ;
}
static inline void F_84 ( struct V_133 * V_30 )
{
F_78 ( V_30 -> V_2 , V_148 ,
V_145 ) ;
}
static inline void F_85 ( struct V_133 * V_30 )
{
F_81 ( V_30 -> V_2 , 1 << V_30 -> V_147 ,
V_145 ) ;
}
static inline void F_86 ( struct V_133 * V_30 )
{
F_81 ( V_30 -> V_2 , 1 << V_30 -> V_147 ,
V_144 ) ;
}
static unsigned int F_87 ( struct V_34 * V_23 ,
struct V_133 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_132 * V_134 ;
struct V_149 * V_150 ;
unsigned int V_151 = 0 ;
unsigned int V_152 ;
unsigned int V_153 ;
unsigned int V_154 = 0 ;
V_152 = F_29 ( V_2 , V_30 -> V_147 , V_155 ) ;
V_152 &= V_156 ;
if ( F_88 ( V_152 >= V_30 -> V_152 ) )
V_153 = V_152 - V_30 -> V_152 ;
else
V_153 = ( V_156 + 1 ) - V_30 -> V_152 + V_152 ;
F_89 ( V_2 , V_157 , V_23 ,
L_4 ,
V_158 , V_30 -> V_147 , V_30 -> V_152 , V_152 , V_153 ) ;
while ( V_154 < V_153 ) {
V_134 = & V_2 -> V_159 [ V_30 -> V_160 ] ;
if ( V_134 -> V_140 ) {
V_151 ++ ;
V_23 -> V_94 . V_161 ++ ;
V_23 -> V_94 . V_162 += V_134 -> V_140 -> V_163 ;
F_90 ( & V_23 -> V_23 ,
F_91 ( V_134 , V_141 ) ,
V_134 -> V_140 -> V_163 ,
V_164 ) ;
F_74 ( V_134 ) ;
} else if ( F_91 ( V_134 , V_141 ) ) {
V_23 -> V_94 . V_162 +=
F_92 ( V_134 , V_165 ) ;
F_93 ( & V_23 -> V_23 ,
F_91 ( V_134 , V_141 ) ,
F_92 ( V_134 , V_165 ) ,
V_164 ) ;
F_76 ( V_134 , V_141 , 0 ) ;
}
V_154 ++ ;
if ( F_88 ( V_30 -> V_160 < V_30 -> V_138 ) )
V_30 -> V_160 ++ ;
else
V_30 -> V_160 = V_30 -> V_137 ;
}
V_30 -> V_166 += V_154 ;
V_30 -> V_152 = ( V_30 -> V_152 + V_154 ) & V_156 ;
if ( V_30 -> V_166 > ( V_167 + 1 ) ) {
V_150 = F_94 ( V_23 , V_30 -> V_168 ) ;
if ( F_95 ( V_150 ) )
F_96 ( V_150 ) ;
}
return V_151 ;
}
static unsigned int F_97 ( struct V_34 * V_23 ,
struct V_133 * V_30 )
{
unsigned int V_169 ;
unsigned long V_9 ;
F_98 ( & V_30 -> V_170 , V_9 ) ;
V_169 = F_87 ( V_23 , V_30 ) ;
F_99 ( & V_30 -> V_170 , V_9 ) ;
return V_169 ;
}
static int F_100 ( struct V_171 * V_172 , int V_173 )
{
struct V_133 * V_30 =
F_101 ( V_172 , struct V_133 , V_172 ) ;
unsigned int V_174 = 0 ;
V_174 = F_97 ( V_30 -> V_2 -> V_23 , V_30 ) ;
if ( V_174 == 0 ) {
F_102 ( V_172 ) ;
V_30 -> V_175 ( V_30 ) ;
return 0 ;
}
return V_173 ;
}
static void F_103 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_73 ;
if ( F_104 ( V_23 ) ) {
for ( V_73 = 0 ; V_73 < V_2 -> V_8 -> V_176 ; V_73 ++ )
F_97 ( V_23 , & V_2 -> V_177 [ V_73 ] ) ;
}
F_97 ( V_23 , & V_2 -> V_177 [ V_178 ] ) ;
}
static int F_105 ( struct V_34 * V_23 ,
struct V_179 * V_140 ,
T_6 V_180 ,
struct V_133 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_22 * V_181 = & V_2 -> V_182 -> V_23 ;
struct V_132 * V_134 ;
unsigned int V_183 ;
T_3 V_184 ;
T_2 V_185 ;
int V_59 ;
V_134 = F_73 ( V_2 , V_30 ) ;
if ( F_106 ( ! V_134 ) )
F_107 () ;
V_134 -> V_140 = V_140 ;
V_183 = F_108 ( V_140 ) < V_186 ? V_186 : F_108 ( V_140 ) ;
V_184 = F_109 ( V_181 , V_140 -> V_72 , V_183 , V_164 ) ;
V_59 = F_110 ( V_181 , V_184 ) ;
if ( V_59 ) {
V_2 -> V_187 . V_188 ++ ;
F_58 ( V_2 , V_189 , V_23 , L_5 ) ;
F_111 ( V_140 ) ;
return V_59 ;
}
F_76 ( V_134 , V_141 , V_184 ) ;
F_112 ( V_134 , V_165 , V_140 -> V_163 ) ;
V_185 = ( V_183 << V_190 ) | V_180 |
( V_2 -> V_8 -> V_191 << V_192 ) |
V_193 ;
if ( V_140 -> V_194 == V_195 )
V_185 |= V_196 ;
F_9 ( V_2 , V_134 -> V_197 , V_184 , V_185 ) ;
return 0 ;
}
static int F_113 ( struct V_34 * V_23 ,
T_7 * V_198 ,
T_6 V_180 ,
struct V_133 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_22 * V_181 = & V_2 -> V_182 -> V_23 ;
struct V_132 * V_134 ;
T_3 V_184 ;
int V_59 ;
V_134 = F_73 ( V_2 , V_30 ) ;
if ( F_106 ( ! V_134 ) )
F_107 () ;
V_134 -> V_140 = NULL ;
V_184 = F_114 ( V_181 , V_198 , 0 ,
F_115 ( V_198 ) , V_164 ) ;
V_59 = F_110 ( V_181 , V_184 ) ;
if ( V_59 ) {
V_2 -> V_187 . V_188 ++ ;
F_58 ( V_2 , V_189 , V_23 , L_6 ,
V_158 ) ;
return V_59 ;
}
F_76 ( V_134 , V_141 , V_184 ) ;
F_112 ( V_134 , V_165 , V_198 -> V_199 ) ;
F_9 ( V_2 , V_134 -> V_197 , V_184 ,
( V_198 -> V_199 << V_190 ) | V_180 |
( V_2 -> V_8 -> V_191 << V_192 ) ) ;
return 0 ;
}
static struct V_179 * F_116 ( struct V_34 * V_23 ,
struct V_179 * V_140 )
{
struct V_200 * V_201 = NULL ;
struct V_179 * V_202 ;
T_6 V_80 ;
T_5 V_203 ;
T_6 V_204 ;
T_2 V_205 ;
if ( F_106 ( F_117 ( V_140 ) < sizeof( * V_201 ) ) ) {
V_202 = F_118 ( V_140 , sizeof( * V_201 ) ) ;
F_111 ( V_140 ) ;
if ( ! V_202 ) {
V_23 -> V_94 . V_206 ++ ;
V_23 -> V_94 . V_207 ++ ;
return NULL ;
}
V_140 = V_202 ;
}
F_119 ( V_140 , sizeof( * V_201 ) ) ;
V_201 = (struct V_200 * ) V_140 -> V_72 ;
if ( V_140 -> V_194 == V_195 ) {
V_204 = F_120 ( V_140 -> V_208 ) ;
switch ( V_204 ) {
case V_209 :
V_203 = F_121 ( V_140 ) -> V_208 ;
break;
case V_210 :
V_203 = F_122 ( V_140 ) -> V_211 ;
break;
default:
return V_140 ;
}
V_80 = F_123 ( V_140 ) - sizeof( * V_201 ) ;
V_205 = ( V_80 << V_212 ) |
( V_80 + V_140 -> V_213 ) ;
if ( V_203 == V_214 || V_203 == V_215 ) {
V_205 |= V_216 ;
if ( V_203 == V_215 && V_204 == V_209 )
V_205 |= V_217 ;
} else {
V_205 = 0 ;
}
V_201 -> V_205 = V_205 ;
}
return V_140 ;
}
static T_8 F_124 ( struct V_179 * V_140 , struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_133 * V_30 = NULL ;
struct V_149 * V_150 ;
unsigned long V_9 = 0 ;
int V_218 , V_147 ;
T_6 V_180 ;
int V_59 ;
int V_73 ;
V_147 = F_125 ( V_140 ) ;
if ( V_147 == 0 )
V_147 = V_178 ;
else
V_147 -= 1 ;
V_218 = F_126 ( V_140 ) -> V_218 ;
V_30 = & V_2 -> V_177 [ V_147 ] ;
V_150 = F_94 ( V_23 , V_30 -> V_168 ) ;
F_98 ( & V_30 -> V_170 , V_9 ) ;
if ( V_30 -> V_166 <= V_218 + 1 ) {
F_127 ( V_150 ) ;
F_128 ( V_23 , L_7 ,
V_158 , V_147 , V_30 -> V_168 ) ;
V_59 = V_219 ;
goto V_220;
}
if ( F_129 ( V_140 , V_186 ) ) {
V_59 = V_221 ;
goto V_220;
}
if ( V_2 -> V_49 ) {
V_140 = F_116 ( V_23 , V_140 ) ;
if ( ! V_140 ) {
V_59 = V_221 ;
goto V_220;
}
}
V_180 = V_222 ;
if ( V_218 == 0 )
V_180 |= V_223 ;
V_59 = F_105 ( V_23 , V_140 , V_180 , V_30 ) ;
if ( V_59 ) {
V_59 = V_221 ;
goto V_220;
}
for ( V_73 = 0 ; V_73 < V_218 ; V_73 ++ ) {
V_59 = F_113 ( V_23 ,
& F_126 ( V_140 ) -> V_224 [ V_73 ] ,
( V_73 == V_218 - 1 ) ? V_223 : 0 ,
V_30 ) ;
if ( V_59 ) {
V_59 = V_221 ;
goto V_220;
}
}
F_130 ( V_140 ) ;
V_30 -> V_166 -= V_218 + 1 ;
V_30 -> V_225 += V_218 + 1 ;
V_30 -> V_225 &= V_226 ;
if ( V_30 -> V_166 <= ( V_167 + 1 ) )
F_127 ( V_150 ) ;
if ( ! V_140 -> V_227 || F_131 ( V_150 ) )
F_30 ( V_2 , V_30 -> V_147 ,
V_30 -> V_225 , V_228 ) ;
V_220:
F_99 ( & V_30 -> V_170 , V_9 ) ;
return V_59 ;
}
static struct V_179 * F_132 ( struct V_1 * V_2 ,
struct V_132 * V_139 )
{
struct V_22 * V_181 = & V_2 -> V_182 -> V_23 ;
struct V_179 * V_140 ;
struct V_179 * V_229 ;
T_3 V_184 ;
V_140 = F_133 ( V_2 -> V_23 , V_2 -> V_230 + V_231 ) ;
if ( ! V_140 ) {
V_2 -> V_187 . V_232 ++ ;
F_58 ( V_2 , V_233 , V_2 -> V_23 ,
L_8 , V_158 ) ;
return NULL ;
}
V_184 = F_109 ( V_181 , V_140 -> V_72 , V_2 -> V_230 ,
V_234 ) ;
if ( F_110 ( V_181 , V_184 ) ) {
V_2 -> V_187 . V_235 ++ ;
F_75 ( V_140 ) ;
F_58 ( V_2 , V_233 , V_2 -> V_23 ,
L_9 , V_158 ) ;
return NULL ;
}
V_229 = V_139 -> V_140 ;
if ( F_88 ( V_229 ) )
F_90 ( V_181 , F_91 ( V_139 , V_141 ) ,
V_2 -> V_230 , V_234 ) ;
V_139 -> V_140 = V_140 ;
F_76 ( V_139 , V_141 , V_184 ) ;
F_5 ( V_2 , V_139 -> V_197 , V_184 ) ;
return V_229 ;
}
static unsigned int F_134 ( struct V_142 * V_30 ,
unsigned int V_173 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_34 * V_23 = V_2 -> V_23 ;
struct V_132 * V_139 ;
struct V_179 * V_140 ;
T_2 V_236 ;
unsigned long V_237 ;
int V_163 ;
unsigned int V_238 = 0 , V_239 ;
unsigned int V_240 ;
unsigned int V_241 ;
unsigned int V_242 = 0 ;
V_240 = F_31 ( V_2 , V_30 -> V_147 , V_243 ) ;
V_241 = ( V_240 >> V_244 ) &
V_245 ;
if ( V_241 > V_30 -> V_246 ) {
V_241 = V_241 - V_30 -> V_246 ;
V_23 -> V_94 . V_247 += V_241 ;
V_23 -> V_94 . V_248 += V_241 ;
V_30 -> V_246 += V_241 ;
if ( V_30 -> V_246 >= 0xC000 ) {
V_30 -> V_246 = 0 ;
F_32 ( V_2 , V_30 -> V_147 , 0 ,
V_243 ) ;
}
}
V_240 &= V_226 ;
if ( F_88 ( V_240 >= V_30 -> V_152 ) )
V_239 = V_240 - V_30 -> V_152 ;
else
V_239 = ( V_156 + 1 ) - V_30 -> V_152 +
V_240 ;
F_89 ( V_2 , V_249 , V_23 ,
L_10 , V_239 ) ;
while ( ( V_238 < V_239 ) &&
( V_238 < V_173 ) ) {
V_139 = & V_2 -> V_250 [ V_30 -> V_251 ] ;
V_140 = F_132 ( V_2 , V_139 ) ;
if ( F_106 ( ! V_140 ) ) {
V_23 -> V_94 . V_252 ++ ;
V_23 -> V_94 . V_248 ++ ;
goto V_253;
}
if ( ! V_2 -> V_49 ) {
V_236 =
F_3 ( V_2 , V_139 -> V_197 ) ;
} else {
struct V_200 * V_201 ;
V_201 = (struct V_200 * ) V_140 -> V_72 ;
V_236 = V_201 -> V_185 ;
}
V_237 = V_236 & 0xffff ;
V_163 = V_236 >> V_190 ;
F_89 ( V_2 , V_249 , V_23 ,
L_11 ,
V_158 , V_240 , V_30 -> V_152 ,
V_30 -> V_251 , V_236 ) ;
if ( F_106 ( ! ( V_237 & V_223 ) || ! ( V_237 & V_222 ) ) ) {
F_58 ( V_2 , V_249 , V_23 ,
L_12 ) ;
V_23 -> V_94 . V_252 ++ ;
V_23 -> V_94 . V_248 ++ ;
F_75 ( V_140 ) ;
goto V_253;
}
if ( F_106 ( V_237 & ( V_254 |
V_255 |
V_256 |
V_257 |
V_258 ) ) ) {
F_58 ( V_2 , V_249 , V_23 , L_13 ,
( unsigned int ) V_237 ) ;
if ( V_237 & V_254 )
V_23 -> V_94 . V_259 ++ ;
if ( V_237 & V_255 )
V_23 -> V_94 . V_260 ++ ;
if ( V_237 & V_256 )
V_23 -> V_94 . V_261 ++ ;
if ( V_237 & V_257 )
V_23 -> V_94 . V_262 ++ ;
V_23 -> V_94 . V_252 ++ ;
V_23 -> V_94 . V_248 ++ ;
F_75 ( V_140 ) ;
goto V_253;
}
V_242 = ( V_237 & V_2 -> V_263 ) &&
V_2 -> V_46 ;
F_135 ( V_140 , V_163 ) ;
if ( V_2 -> V_49 ) {
F_136 ( V_140 , 64 ) ;
V_163 -= 64 ;
}
if ( F_88 ( V_242 ) )
V_140 -> V_194 = V_264 ;
F_136 ( V_140 , 2 ) ;
V_163 -= 2 ;
if ( V_2 -> V_47 ) {
F_137 ( V_140 , V_163 - V_265 ) ;
V_163 -= V_265 ;
}
V_140 -> V_208 = F_138 ( V_140 , V_2 -> V_23 ) ;
V_23 -> V_94 . V_266 ++ ;
V_23 -> V_94 . V_267 += V_163 ;
if ( V_237 & V_268 )
V_23 -> V_94 . V_269 ++ ;
F_139 ( & V_30 -> V_172 , V_140 ) ;
F_89 ( V_2 , V_249 , V_23 , L_14 ) ;
V_253:
V_238 ++ ;
if ( F_88 ( V_30 -> V_251 < V_30 -> V_138 ) )
V_30 -> V_251 ++ ;
else
V_30 -> V_251 = V_30 -> V_137 ;
V_30 -> V_152 = ( V_30 -> V_152 + 1 ) & V_156 ;
F_32 ( V_2 , V_30 -> V_147 , V_30 -> V_152 , V_270 ) ;
}
return V_238 ;
}
static int F_140 ( struct V_171 * V_172 , int V_173 )
{
struct V_142 * V_30 = F_101 ( V_172 ,
struct V_142 , V_172 ) ;
unsigned int V_174 ;
V_174 = F_134 ( V_30 , V_173 ) ;
if ( V_174 < V_173 ) {
F_102 ( V_172 ) ;
V_30 -> V_175 ( V_30 ) ;
}
return V_174 ;
}
static int F_141 ( struct V_1 * V_2 ,
struct V_142 * V_30 )
{
struct V_132 * V_139 ;
struct V_179 * V_140 ;
int V_73 ;
F_89 ( V_2 , V_115 , V_2 -> V_23 , L_15 , V_158 ) ;
for ( V_73 = 0 ; V_73 < V_30 -> V_199 ; V_73 ++ ) {
V_139 = V_30 -> V_135 + V_73 ;
V_140 = F_132 ( V_2 , V_139 ) ;
if ( V_140 )
F_75 ( V_140 ) ;
if ( ! V_139 -> V_140 )
return - V_271 ;
}
return 0 ;
}
static void F_142 ( struct V_1 * V_2 )
{
struct V_132 * V_139 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_272 ; V_73 ++ ) {
V_139 = & V_2 -> V_250 [ V_73 ] ;
if ( F_91 ( V_139 , V_141 ) ) {
F_90 ( & V_2 -> V_23 -> V_23 ,
F_91 ( V_139 , V_141 ) ,
V_2 -> V_230 , V_234 ) ;
F_76 ( V_139 , V_141 , 0 ) ;
}
if ( V_139 -> V_140 )
F_74 ( V_139 ) ;
}
}
static void F_143 ( struct V_1 * V_2 , T_2 V_273 , bool V_95 )
{
T_2 V_98 ;
V_98 = F_48 ( V_2 , V_274 ) ;
if ( V_95 )
V_98 |= V_273 ;
else
V_98 &= ~ V_273 ;
F_49 ( V_2 , V_98 , V_274 ) ;
if ( V_95 == 0 )
F_144 ( 1000 , 2000 ) ;
}
static int F_145 ( struct V_1 * V_2 )
{
struct V_22 * V_181 = & V_2 -> V_182 -> V_23 ;
unsigned int V_275 = 0 ;
T_2 V_98 ;
F_15 ( V_2 , 0 ) ;
F_146 ( 10 ) ;
F_49 ( V_2 , 0 , V_274 ) ;
F_49 ( V_2 , V_276 , V_274 ) ;
while ( V_275 ++ < 1000 ) {
V_98 = F_48 ( V_2 , V_274 ) ;
if ( ! ( V_98 & V_276 ) )
return 0 ;
F_146 ( 1 ) ;
}
if ( V_275 == 1000 ) {
F_147 ( V_181 ,
L_16 ) ;
return - V_277 ;
}
return 0 ;
}
static void F_148 ( struct V_1 * V_2 )
{
F_78 ( V_2 , 0xFFFFFFFF , V_144 ) ;
F_78 ( V_2 , 0xFFFFFFFF , V_278 ) ;
F_78 ( V_2 , 0 , V_145 ) ;
F_81 ( V_2 , 0xFFFFFFFF , V_144 ) ;
F_81 ( V_2 , 0xFFFFFFFF , V_278 ) ;
F_81 ( V_2 , 0 , V_145 ) ;
}
static int F_149 ( struct V_1 * V_2 )
{
struct V_22 * V_181 = & V_2 -> V_182 -> V_23 ;
int V_59 ;
T_2 V_98 ;
T_2 V_279 = 0 ;
T_2 V_280 = 0 ;
int V_73 ;
F_150 ( & V_2 -> V_182 -> V_23 , L_17 ) ;
V_59 = F_145 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_49 ( V_2 , 0 , V_274 ) ;
F_49 ( V_2 ,
V_281 | V_282 | V_283 ,
V_284 ) ;
F_49 ( V_2 , 0 , V_284 ) ;
F_49 ( V_2 , V_285 , V_286 ) ;
V_98 = F_13 ( V_2 , V_52 ) ;
V_98 |= V_287 ;
F_16 ( V_2 , V_98 , V_52 ) ;
if ( ! F_12 ( V_2 ) && ! F_151 ( V_2 ) )
F_16 ( V_2 , 1 , V_288 ) ;
F_148 ( V_2 ) ;
V_279 |= V_143 ;
V_279 |= V_148 ;
if ( F_152 ( V_2 -> V_38 ) ) {
V_279 |= V_289 ;
} else if ( V_2 -> V_290 ) {
V_279 |= V_289 ;
} else if ( V_2 -> V_291 == V_292 ) {
if ( V_2 -> V_8 -> V_9 & V_293 )
V_279 |= V_289 ;
V_98 = F_20 ( V_2 ) ;
V_98 |= F_153 ( V_2 -> V_8 -> V_294 ) ;
if ( F_104 ( V_2 -> V_23 ) )
V_98 |= V_2 -> V_8 -> V_295 ;
else
V_98 &= ~ V_2 -> V_8 -> V_295 ;
F_21 ( V_2 , V_98 ) ;
}
if ( V_2 -> V_8 -> V_9 & V_296 )
V_279 |= ( V_297 | V_298 ) ;
for ( V_73 = 0 ; V_73 < V_2 -> V_8 -> V_299 ; ++ V_73 )
V_280 |= ( 1 << ( V_146 + V_73 ) ) ;
for ( V_73 = 0 ; V_73 < V_2 -> V_8 -> V_176 ; ++ V_73 )
V_280 |= ( 1 << V_73 ) ;
F_78 ( V_2 , V_279 , V_145 ) ;
F_81 ( V_2 , V_280 , V_145 ) ;
F_150 ( V_181 , L_18 ) ;
return 0 ;
}
static void F_154 ( struct V_1 * V_2 ,
unsigned int V_147 , unsigned int V_199 ,
unsigned int V_300 , unsigned int V_138 )
{
struct V_133 * V_30 = & V_2 -> V_177 [ V_147 ] ;
T_2 V_301 = F_155 ( V_2 ) ;
T_2 V_302 = 0 ;
F_156 ( & V_30 -> V_170 ) ;
V_30 -> V_2 = V_2 ;
V_30 -> V_147 = V_147 ;
if ( V_147 == V_178 ) {
V_30 -> V_168 = 0 ;
V_30 -> V_175 = F_84 ;
V_30 -> V_303 = F_83 ;
} else {
V_30 -> V_168 = V_147 + 1 ;
V_30 -> V_175 = F_85 ;
V_30 -> V_303 = F_86 ;
}
V_30 -> V_135 = V_2 -> V_159 + V_300 ;
V_30 -> V_199 = V_199 ;
V_30 -> V_160 = V_300 ;
V_30 -> V_152 = 0 ;
V_30 -> V_166 = V_199 ;
V_30 -> V_136 = V_300 ;
V_30 -> V_137 = V_300 ;
V_30 -> V_138 = V_138 - 1 ;
V_30 -> V_225 = 0 ;
if ( V_147 != V_178 )
V_302 = V_285 << 16 ;
F_30 ( V_2 , V_147 , 0 , V_228 ) ;
F_30 ( V_2 , V_147 , 0 , V_155 ) ;
F_30 ( V_2 , V_147 , 1 , V_304 ) ;
F_30 ( V_2 , V_147 , V_302 ,
V_305 ) ;
F_30 ( V_2 , V_147 ,
( ( V_199 << V_306 ) |
V_307 ) , V_308 ) ;
F_30 ( V_2 , V_147 , V_300 * V_301 ,
V_309 ) ;
F_30 ( V_2 , V_147 , V_300 * V_301 ,
V_310 ) ;
F_30 ( V_2 , V_147 , V_300 * V_301 ,
V_311 ) ;
F_30 ( V_2 , V_147 , V_138 * V_301 - 1 ,
V_312 ) ;
}
static int F_157 ( struct V_1 * V_2 ,
unsigned int V_147 , unsigned int V_199 ,
unsigned int V_300 , unsigned int V_138 )
{
struct V_142 * V_30 = & V_2 -> V_313 [ V_147 ] ;
T_2 V_301 = F_155 ( V_2 ) ;
int V_59 ;
V_30 -> V_2 = V_2 ;
V_30 -> V_147 = V_147 ;
if ( V_147 == V_178 ) {
V_30 -> V_175 = F_79 ;
V_30 -> V_303 = F_77 ;
} else {
V_30 -> V_175 = F_82 ;
V_30 -> V_303 = F_80 ;
}
V_30 -> V_135 = V_2 -> V_250 + V_300 ;
V_30 -> V_199 = V_199 ;
V_30 -> V_152 = 0 ;
V_30 -> V_251 = V_300 ;
V_30 -> V_137 = V_300 ;
V_30 -> V_138 = V_138 - 1 ;
V_59 = F_141 ( V_2 , V_30 ) ;
if ( V_59 )
return V_59 ;
F_32 ( V_2 , V_147 , 0 , V_243 ) ;
F_32 ( V_2 , V_147 , 0 , V_270 ) ;
F_32 ( V_2 , V_147 , 1 , V_304 ) ;
F_32 ( V_2 , V_147 ,
( ( V_199 << V_306 ) |
V_307 ) , V_308 ) ;
F_32 ( V_2 , V_147 ,
( V_314 <<
V_315 ) |
V_316 , V_317 ) ;
F_32 ( V_2 , V_147 , V_300 * V_301 ,
V_309 ) ;
F_32 ( V_2 , V_147 , V_300 * V_301 ,
V_318 ) ;
F_32 ( V_2 , V_147 , V_300 * V_301 ,
V_319 ) ;
F_32 ( V_2 , V_147 , V_138 * V_301 - 1 ,
V_312 ) ;
return V_59 ;
}
static void F_158 ( struct V_1 * V_2 )
{
unsigned int V_73 ;
struct V_133 * V_30 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_8 -> V_176 ; ++ V_73 ) {
V_30 = & V_2 -> V_177 [ V_73 ] ;
F_159 ( V_2 -> V_23 , & V_30 -> V_172 , F_100 , 64 ) ;
}
V_30 = & V_2 -> V_177 [ V_178 ] ;
F_159 ( V_2 -> V_23 , & V_30 -> V_172 , F_100 , 64 ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
unsigned int V_73 ;
struct V_133 * V_30 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_8 -> V_176 ; ++ V_73 ) {
V_30 = & V_2 -> V_177 [ V_73 ] ;
F_161 ( & V_30 -> V_172 ) ;
}
V_30 = & V_2 -> V_177 [ V_178 ] ;
F_161 ( & V_30 -> V_172 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
unsigned int V_73 ;
struct V_133 * V_30 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_8 -> V_176 ; ++ V_73 ) {
V_30 = & V_2 -> V_177 [ V_73 ] ;
F_163 ( & V_30 -> V_172 ) ;
}
V_30 = & V_2 -> V_177 [ V_178 ] ;
F_163 ( & V_30 -> V_172 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
unsigned int V_73 ;
struct V_133 * V_30 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_8 -> V_176 ; ++ V_73 ) {
V_30 = & V_2 -> V_177 [ V_73 ] ;
F_165 ( & V_30 -> V_172 ) ;
}
V_30 = & V_2 -> V_177 [ V_178 ] ;
F_165 ( & V_30 -> V_172 ) ;
}
static void F_166 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_73 , V_320 ;
T_2 V_321 , V_322 ;
T_2 V_323 [ 3 ] = { 0 , 0 , 0 } ;
V_321 = F_25 ( V_2 , V_324 ) ;
V_320 = V_321 & V_325 ;
V_321 &= ~ V_325 ;
F_26 ( V_2 , V_321 , V_324 ) ;
V_321 = 0 ;
V_322 = 0 ;
F_26 ( V_2 , V_326 , V_327 ) ;
for ( V_73 = 0 ; V_73 < V_2 -> V_8 -> V_176 ; V_73 ++ ) {
F_154 ( V_2 , V_73 , V_2 -> V_8 -> V_328 ,
V_73 * V_2 -> V_8 -> V_328 ,
( V_73 + 1 ) * V_2 -> V_8 -> V_328 ) ;
V_322 |= ( 1 << V_73 ) ;
V_321 |= ( 1 << ( V_73 + V_329 ) ) ;
V_323 [ F_167 ( V_73 ) ] |=
( ( V_330 + V_73 ) << F_168 ( V_73 ) ) ;
}
F_154 ( V_2 , V_178 , V_331 ,
V_2 -> V_8 -> V_176 *
V_2 -> V_8 -> V_328 ,
V_332 ) ;
V_322 |= ( 1 << V_178 ) ;
V_321 |= ( 1 << ( V_178 + V_329 ) ) ;
V_323 [ F_167 ( V_178 ) ] |=
( ( V_330 + V_2 -> V_8 -> V_176 ) <<
F_168 ( V_178 ) ) ;
F_26 ( V_2 , V_323 [ 0 ] , V_333 ) ;
F_26 ( V_2 , V_323 [ 1 ] , V_334 ) ;
F_26 ( V_2 , V_323 [ 2 ] , V_335 ) ;
F_158 ( V_2 ) ;
F_26 ( V_2 , V_322 , V_336 ) ;
if ( V_320 )
V_321 |= V_325 ;
F_26 ( V_2 , V_321 , V_324 ) ;
}
static void F_169 ( struct V_1 * V_2 )
{
unsigned int V_73 ;
struct V_142 * V_30 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_8 -> V_299 ; ++ V_73 ) {
V_30 = & V_2 -> V_313 [ V_73 ] ;
F_159 ( V_2 -> V_23 , & V_30 -> V_172 , F_140 , 64 ) ;
}
V_30 = & V_2 -> V_313 [ V_178 ] ;
F_159 ( V_2 -> V_23 , & V_30 -> V_172 , F_140 , 64 ) ;
}
static void F_170 ( struct V_1 * V_2 )
{
unsigned int V_73 ;
struct V_142 * V_30 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_8 -> V_299 ; ++ V_73 ) {
V_30 = & V_2 -> V_313 [ V_73 ] ;
F_161 ( & V_30 -> V_172 ) ;
}
V_30 = & V_2 -> V_313 [ V_178 ] ;
F_161 ( & V_30 -> V_172 ) ;
}
static void F_171 ( struct V_1 * V_2 )
{
unsigned int V_73 ;
struct V_142 * V_30 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_8 -> V_299 ; ++ V_73 ) {
V_30 = & V_2 -> V_313 [ V_73 ] ;
F_163 ( & V_30 -> V_172 ) ;
}
V_30 = & V_2 -> V_313 [ V_178 ] ;
F_163 ( & V_30 -> V_172 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
unsigned int V_73 ;
struct V_142 * V_30 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_8 -> V_299 ; ++ V_73 ) {
V_30 = & V_2 -> V_313 [ V_73 ] ;
F_165 ( & V_30 -> V_172 ) ;
}
V_30 = & V_2 -> V_313 [ V_178 ] ;
F_165 ( & V_30 -> V_172 ) ;
}
static int F_173 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_73 ;
T_2 V_320 ;
T_2 V_321 ;
T_2 V_322 ;
int V_59 ;
V_321 = F_27 ( V_2 , V_324 ) ;
V_320 = V_321 & V_325 ;
V_321 &= ~ V_325 ;
F_28 ( V_2 , V_321 , V_324 ) ;
V_321 = 0 ;
V_322 = 0 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_8 -> V_299 ; V_73 ++ ) {
V_59 = F_157 ( V_2 , V_73 ,
V_2 -> V_8 -> V_337 ,
V_73 * V_2 -> V_8 -> V_337 ,
( V_73 + 1 ) *
V_2 -> V_8 -> V_337 ) ;
if ( V_59 )
return V_59 ;
V_322 |= ( 1 << V_73 ) ;
V_321 |= ( 1 << ( V_73 + V_329 ) ) ;
}
V_59 = F_157 ( V_2 , V_178 , V_338 ,
V_2 -> V_8 -> V_299 *
V_2 -> V_8 -> V_337 ,
V_332 ) ;
if ( V_59 )
return V_59 ;
V_322 |= ( 1 << V_178 ) ;
V_321 |= ( 1 << ( V_178 + V_329 ) ) ;
F_169 ( V_2 ) ;
F_28 ( V_2 , V_322 , V_336 ) ;
if ( V_320 )
V_321 |= V_325 ;
F_28 ( V_2 , V_321 , V_324 ) ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 )
{
int V_59 = 0 ;
int V_275 = 0 ;
T_2 V_98 ;
V_98 = F_25 ( V_2 , V_324 ) ;
V_98 &= ~ V_325 ;
F_26 ( V_2 , V_98 , V_324 ) ;
while ( V_275 ++ < V_339 ) {
V_98 = F_25 ( V_2 , V_340 ) ;
if ( V_98 & V_341 )
break;
F_146 ( 1 ) ;
}
if ( V_275 == V_339 ) {
F_175 ( V_2 -> V_23 , L_19 ) ;
V_59 = - V_277 ;
}
F_144 ( 10000 , 20000 ) ;
V_98 = F_27 ( V_2 , V_324 ) ;
V_98 &= ~ V_325 ;
F_28 ( V_2 , V_98 , V_324 ) ;
V_275 = 0 ;
while ( V_275 ++ < V_339 ) {
V_98 = F_27 ( V_2 , V_340 ) ;
if ( V_98 & V_341 )
break;
F_146 ( 1 ) ;
}
if ( V_275 == V_339 ) {
F_175 ( V_2 -> V_23 , L_20 ) ;
V_59 = - V_277 ;
}
return V_59 ;
}
static void F_176 ( struct V_1 * V_2 )
{
int V_73 ;
F_172 ( V_2 ) ;
F_164 ( V_2 ) ;
F_174 ( V_2 ) ;
for ( V_73 = 0 ; V_73 < V_2 -> V_342 ; V_73 ++ ) {
if ( V_2 -> V_159 [ V_73 ] . V_140 != NULL ) {
F_111 ( V_2 -> V_159 [ V_73 ] . V_140 ) ;
V_2 -> V_159 [ V_73 ] . V_140 = NULL ;
}
}
F_142 ( V_2 ) ;
F_177 ( V_2 -> V_250 ) ;
F_177 ( V_2 -> V_159 ) ;
}
static int F_178 ( struct V_1 * V_2 )
{
int V_59 ;
unsigned int V_73 ;
struct V_132 * V_139 ;
F_89 ( V_2 , V_115 , V_2 -> V_23 , L_15 , V_158 ) ;
V_2 -> V_343 = V_2 -> V_17 + V_2 -> V_8 -> V_344 ;
V_2 -> V_272 = V_332 ;
V_2 -> V_250 = F_179 ( V_2 -> V_272 , sizeof( struct V_132 ) ,
V_345 ) ;
if ( ! V_2 -> V_250 )
return - V_271 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_272 ; V_73 ++ ) {
V_139 = V_2 -> V_250 + V_73 ;
V_139 -> V_197 = V_2 -> V_343 + V_73 * V_346 ;
}
V_2 -> V_347 = V_2 -> V_17 + V_2 -> V_8 -> V_348 ;
V_2 -> V_342 = V_332 ;
V_2 -> V_159 = F_179 ( V_2 -> V_342 , sizeof( struct V_132 ) ,
V_345 ) ;
if ( ! V_2 -> V_159 ) {
F_177 ( V_2 -> V_250 ) ;
return - V_271 ;
}
for ( V_73 = 0 ; V_73 < V_2 -> V_342 ; V_73 ++ ) {
V_139 = V_2 -> V_159 + V_73 ;
V_139 -> V_197 = V_2 -> V_347 + V_73 * V_346 ;
}
F_28 ( V_2 , V_349 , V_350 ) ;
V_59 = F_173 ( V_2 -> V_23 ) ;
if ( V_59 ) {
F_128 ( V_2 -> V_23 , L_21 ) ;
F_142 ( V_2 ) ;
F_177 ( V_2 -> V_250 ) ;
F_177 ( V_2 -> V_159 ) ;
return V_59 ;
}
F_26 ( V_2 , V_349 , V_350 ) ;
F_166 ( V_2 -> V_23 ) ;
return 0 ;
}
static void F_180 ( struct V_351 * V_352 )
{
struct V_1 * V_2 = F_101 (
V_352 , struct V_1 , V_353 ) ;
F_89 ( V_2 , V_354 , V_2 -> V_23 , L_15 , V_158 ) ;
if ( V_2 -> V_355 & V_356 ) {
V_2 -> V_355 &= ~ V_356 ;
F_89 ( V_2 , V_357 , V_2 -> V_23 ,
L_22 ) ;
F_68 ( V_2 , V_119 ) ;
}
if ( ( V_2 -> V_8 -> V_9 & V_296 ) &&
( V_2 -> V_355 & V_289 ) ) {
F_181 ( V_2 -> V_38 ,
! ! ( V_2 -> V_355 & V_358 ) ) ;
V_2 -> V_355 &= ~ V_289 ;
}
}
static T_9 F_182 ( int V_359 , void * V_360 )
{
struct V_1 * V_2 = V_360 ;
struct V_142 * V_361 ;
struct V_133 * V_362 ;
unsigned int V_147 ;
V_2 -> V_363 =
F_183 ( V_2 , V_364 ) &
~ F_183 ( V_2 , V_365 ) ;
F_81 ( V_2 , V_2 -> V_363 , V_278 ) ;
F_89 ( V_2 , V_354 , V_2 -> V_23 ,
L_23 , V_158 , V_2 -> V_363 ) ;
for ( V_147 = 0 ; V_147 < V_2 -> V_8 -> V_299 ; V_147 ++ ) {
if ( ! ( V_2 -> V_363 & F_153 ( V_146 + V_147 ) ) )
continue;
V_361 = & V_2 -> V_313 [ V_147 ] ;
if ( F_88 ( F_184 ( & V_361 -> V_172 ) ) ) {
V_361 -> V_303 ( V_361 ) ;
F_185 ( & V_361 -> V_172 ) ;
}
}
for ( V_147 = 0 ; V_147 < V_2 -> V_8 -> V_176 ; V_147 ++ ) {
if ( ! ( V_2 -> V_363 & F_153 ( V_147 ) ) )
continue;
V_362 = & V_2 -> V_177 [ V_147 ] ;
if ( F_88 ( F_184 ( & V_362 -> V_172 ) ) ) {
V_362 -> V_303 ( V_362 ) ;
F_185 ( & V_362 -> V_172 ) ;
}
}
return V_366 ;
}
static T_9 F_186 ( int V_359 , void * V_360 )
{
struct V_1 * V_2 = V_360 ;
struct V_142 * V_361 ;
struct V_133 * V_362 ;
V_2 -> V_355 =
F_187 ( V_2 , V_364 ) &
~ F_187 ( V_2 , V_365 ) ;
F_78 ( V_2 , V_2 -> V_355 , V_278 ) ;
F_89 ( V_2 , V_354 , V_2 -> V_23 ,
L_24 , V_2 -> V_355 ) ;
if ( V_2 -> V_355 & V_143 ) {
V_361 = & V_2 -> V_313 [ V_178 ] ;
if ( F_88 ( F_184 ( & V_361 -> V_172 ) ) ) {
V_361 -> V_303 ( V_361 ) ;
F_185 ( & V_361 -> V_172 ) ;
}
}
if ( V_2 -> V_355 & V_148 ) {
V_362 = & V_2 -> V_177 [ V_178 ] ;
if ( F_88 ( F_184 ( & V_362 -> V_172 ) ) ) {
V_362 -> V_303 ( V_362 ) ;
F_185 ( & V_362 -> V_172 ) ;
}
}
if ( V_2 -> V_355 & ( V_367 |
V_368 |
V_289 |
V_369 |
V_370 |
V_356 ) ) {
F_188 ( & V_2 -> V_353 ) ;
}
if ( ( V_2 -> V_8 -> V_9 & V_296 ) &&
V_2 -> V_355 & ( V_297 | V_298 ) ) {
V_2 -> V_355 &= ~ ( V_297 | V_298 ) ;
F_189 ( & V_2 -> V_371 ) ;
}
return V_366 ;
}
static T_9 F_190 ( int V_359 , void * V_360 )
{
struct V_1 * V_2 = V_360 ;
F_191 ( & V_2 -> V_182 -> V_23 , 0 ) ;
return V_366 ;
}
static void F_192 ( struct V_1 * V_2 )
{
T_2 V_98 ;
V_98 = F_11 ( V_2 ) ;
V_98 |= F_153 ( 1 ) ;
F_15 ( V_2 , V_98 ) ;
F_146 ( 10 ) ;
V_98 &= ~ F_153 ( 1 ) ;
F_15 ( V_2 , V_98 ) ;
F_146 ( 10 ) ;
}
static void F_193 ( struct V_1 * V_2 ,
unsigned char * V_6 )
{
F_49 ( V_2 , ( V_6 [ 0 ] << 24 ) | ( V_6 [ 1 ] << 16 ) |
( V_6 [ 2 ] << 8 ) | V_6 [ 3 ] , V_372 ) ;
F_49 ( V_2 , ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] , V_373 ) ;
}
static T_2 F_194 ( struct V_1 * V_2 )
{
T_2 V_98 ;
T_2 V_321 ;
V_321 = 1 << ( V_178 + V_329 ) | V_325 ;
V_98 = F_25 ( V_2 , V_324 ) ;
V_98 &= ~ V_321 ;
F_26 ( V_2 , V_98 , V_324 ) ;
V_98 = F_27 ( V_2 , V_324 ) ;
V_98 &= ~ V_321 ;
F_28 ( V_2 , V_98 , V_324 ) ;
F_49 ( V_2 , 1 , V_374 ) ;
F_146 ( 10 ) ;
F_49 ( V_2 , 0 , V_374 ) ;
return V_321 ;
}
static void F_195 ( struct V_1 * V_2 , T_2 V_321 )
{
T_2 V_98 ;
V_98 = F_27 ( V_2 , V_324 ) ;
V_98 |= V_321 ;
F_28 ( V_2 , V_98 , V_324 ) ;
V_98 = F_25 ( V_2 , V_324 ) ;
V_98 |= V_321 ;
F_26 ( V_2 , V_98 , V_324 ) ;
}
static bool F_196 ( struct V_1 * V_2 ,
T_2 V_375 )
{
T_2 V_80 ;
T_2 V_98 ;
V_80 = V_376 + ( V_375 < 32 ) * sizeof( T_2 ) ;
V_98 = F_197 ( V_2 , V_80 ) ;
return ! ! ( V_98 & ( 1 << ( V_375 % 32 ) ) ) ;
}
static void F_198 ( struct V_1 * V_2 , T_2 V_375 )
{
T_2 V_80 ;
T_2 V_98 ;
V_80 = V_376 + ( V_375 < 32 ) * sizeof( T_2 ) ;
V_98 = F_197 ( V_2 , V_80 ) ;
V_98 |= ( 1 << ( V_375 % 32 ) ) ;
F_199 ( V_2 , V_98 , V_80 ) ;
}
static void F_200 ( struct V_1 * V_2 ,
T_2 V_375 , T_2 V_377 )
{
T_2 V_80 ;
T_2 V_98 ;
V_80 = V_375 / 8 ;
V_98 = F_27 ( V_2 , V_378 + V_80 ) ;
V_98 &= ~ ( 0xF << ( 4 * ( V_375 % 8 ) ) ) ;
V_98 |= ( ( V_377 & 0xF ) << ( 4 * ( V_375 % 8 ) ) ) ;
F_28 ( V_2 , V_98 , V_378 + V_80 ) ;
}
static void F_201 ( struct V_1 * V_2 ,
T_2 V_375 , T_2 V_379 )
{
T_2 V_80 ;
T_2 V_98 ;
V_80 = V_380 +
( ( V_2 -> V_8 -> V_381 - 1 - V_375 ) / 4 ) *
sizeof( T_2 ) ;
V_98 = F_197 ( V_2 , V_80 ) ;
V_98 &= ~ ( 0xFF << ( 8 * ( V_375 % 4 ) ) ) ;
V_98 |= ( ( V_379 & 0xFF ) << ( 8 * ( V_375 % 4 ) ) ) ;
F_199 ( V_2 , V_98 , V_80 ) ;
}
static int F_202 ( struct V_1 * V_2 )
{
T_2 V_375 ;
for ( V_375 = 0 ; V_375 < V_2 -> V_8 -> V_381 ; V_375 ++ )
if ( ! F_196 ( V_2 , V_375 ) )
return V_375 ;
return - V_271 ;
}
int F_203 ( struct V_1 * V_2 , T_2 * V_382 ,
T_2 V_379 , T_2 V_377 )
{
int V_375 ;
T_2 V_73 ;
V_375 = F_202 ( V_2 ) ;
if ( V_375 < 0 )
return - V_271 ;
if ( V_379 > V_2 -> V_8 -> V_383 )
return - V_37 ;
for ( V_73 = 0 ; V_73 < V_379 ; V_73 ++ )
F_204 ( V_2 , V_382 [ V_73 ] ,
( V_375 * V_2 -> V_8 -> V_383 + V_73 ) *
sizeof( T_2 ) ) ;
F_201 ( V_2 , V_375 , 2 * V_379 ) ;
F_200 ( V_2 , V_375 , V_377 ) ;
F_198 ( V_2 , V_375 ) ;
F_199 ( V_2 , 0x1 , V_384 ) ;
return 0 ;
}
static void F_205 ( struct V_1 * V_2 )
{
T_2 V_73 ;
F_199 ( V_2 , 0x0 , V_384 ) ;
F_199 ( V_2 , 0x0 , V_376 ) ;
F_199 ( V_2 , 0x0 , V_376 + 4 ) ;
for ( V_73 = V_378 ; V_73 <= V_385 ; V_73 ++ )
F_28 ( V_2 , 0x0 , V_73 ) ;
for ( V_73 = 0 ; V_73 < ( V_2 -> V_8 -> V_381 / 4 ) ; V_73 ++ )
F_199 ( V_2 , 0x0 ,
V_380 + V_73 * sizeof( T_2 ) ) ;
for ( V_73 = 0 ; V_73 < V_2 -> V_8 -> V_381 *
V_2 -> V_8 -> V_383 ; V_73 ++ )
F_204 ( V_2 , 0x0 , V_73 * sizeof( T_2 ) ) ;
}
static void F_206 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) || F_151 ( V_2 ) )
return;
F_205 ( V_2 ) ;
}
static void F_207 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_170 ( V_2 ) ;
F_160 ( V_2 ) ;
F_143 ( V_2 , V_386 | V_387 , true ) ;
F_208 ( V_23 ) ;
F_209 ( V_2 -> V_38 ) ;
}
static int F_210 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned long V_321 ;
T_2 V_98 ;
int V_59 ;
F_89 ( V_2 , V_388 , V_23 , L_25 ) ;
if ( ! F_211 ( V_2 -> V_389 ) )
F_52 ( V_2 -> V_389 ) ;
if ( F_152 ( V_2 -> V_38 ) )
F_68 ( V_2 , V_120 ) ;
F_192 ( V_2 ) ;
V_59 = F_149 ( V_2 ) ;
if ( V_59 )
goto V_390;
F_143 ( V_2 , V_386 | V_387 , false ) ;
V_98 = F_48 ( V_2 , V_274 ) ;
V_2 -> V_47 = ! ! ( V_98 & V_391 ) ;
F_193 ( V_2 , V_23 -> V_392 ) ;
if ( F_152 ( V_2 -> V_38 ) ) {
V_98 = F_65 ( V_2 , V_122 ) ;
V_98 |= V_393 ;
F_66 ( V_2 , V_98 , V_122 ) ;
}
V_321 = F_194 ( V_2 ) ;
V_59 = F_178 ( V_2 ) ;
if ( V_59 ) {
F_128 ( V_23 , L_26 ) ;
goto V_390;
}
F_195 ( V_2 , V_321 ) ;
F_206 ( V_2 ) ;
V_59 = F_212 ( V_2 -> V_394 , F_186 , V_395 ,
V_23 -> V_396 , V_2 ) ;
if ( V_59 < 0 ) {
F_128 ( V_23 , L_27 , V_2 -> V_394 ) ;
goto V_397;
}
V_59 = F_212 ( V_2 -> V_398 , F_182 , V_395 ,
V_23 -> V_396 , V_2 ) ;
if ( V_59 < 0 ) {
F_128 ( V_23 , L_27 , V_2 -> V_398 ) ;
goto V_399;
}
F_213 ( V_2 -> V_23 , false ) ;
F_214 ( V_23 , V_2 -> V_38 , V_400 ,
V_2 -> V_291 ) ;
F_207 ( V_23 ) ;
return 0 ;
V_399:
F_215 ( V_2 -> V_394 , V_23 ) ;
V_397:
F_176 ( V_2 ) ;
V_390:
if ( ! F_211 ( V_2 -> V_389 ) )
F_53 ( V_2 -> V_389 ) ;
return V_59 ;
}
static void F_216 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_217 ( V_23 ) ;
F_218 ( V_2 -> V_38 ) ;
F_148 ( V_2 ) ;
F_171 ( V_2 ) ;
F_162 ( V_2 ) ;
F_219 ( & V_2 -> V_353 ) ;
V_2 -> V_401 = - 1 ;
V_2 -> V_402 = - 1 ;
V_2 -> V_403 = - 1 ;
V_2 -> V_404 = - 1 ;
}
static int F_220 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_59 ;
F_89 ( V_2 , V_405 , V_23 , L_28 ) ;
F_216 ( V_23 ) ;
F_221 ( V_2 -> V_38 ) ;
F_143 ( V_2 , V_387 , false ) ;
V_59 = F_174 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_143 ( V_2 , V_386 , false ) ;
F_103 ( V_23 ) ;
F_176 ( V_2 ) ;
F_215 ( V_2 -> V_394 , V_2 ) ;
F_215 ( V_2 -> V_398 , V_2 ) ;
if ( F_152 ( V_2 -> V_38 ) )
V_59 = F_62 ( V_2 , V_120 ) ;
if ( ! F_211 ( V_2 -> V_389 ) )
F_53 ( V_2 -> V_389 ) ;
return V_59 ;
}
static void F_222 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_89 ( V_2 , V_189 , V_23 , L_29 ) ;
V_23 -> V_406 = V_407 ;
V_23 -> V_94 . V_206 ++ ;
F_223 ( V_23 ) ;
}
static inline void F_224 ( struct V_1 * V_2 ,
unsigned char * V_6 ,
int * V_73 ,
int * V_408 )
{
T_2 V_98 ;
F_49 ( V_2 , V_6 [ 0 ] << 8 | V_6 [ 1 ] ,
V_409 + ( * V_73 * 4 ) ) ;
F_49 ( V_2 , V_6 [ 2 ] << 24 | V_6 [ 3 ] << 16 |
V_6 [ 4 ] << 8 | V_6 [ 5 ] ,
V_409 + ( ( * V_73 + 1 ) * 4 ) ) ;
V_98 = F_48 ( V_2 , V_410 ) ;
V_98 |= ( 1 << ( V_411 - * V_408 ) ) ;
F_49 ( V_2 , V_98 , V_410 ) ;
* V_73 += 2 ;
( * V_408 ) ++ ;
}
static void F_225 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_412 * V_413 ;
int V_73 , V_408 ;
T_2 V_98 ;
F_89 ( V_2 , V_115 , V_23 , L_30 , V_158 , V_23 -> V_9 ) ;
V_98 = F_48 ( V_2 , V_274 ) ;
if ( V_23 -> V_9 & V_414 ) {
V_98 |= V_415 ;
F_49 ( V_2 , V_98 , V_274 ) ;
F_49 ( V_2 , 0 , V_410 ) ;
return;
} else {
V_98 &= ~ V_415 ;
F_49 ( V_2 , V_98 , V_274 ) ;
}
if ( V_23 -> V_9 & V_416 ) {
F_175 ( V_23 , L_31 ) ;
return;
}
V_73 = 0 ;
V_408 = 0 ;
F_224 ( V_2 , V_23 -> V_417 , & V_73 , & V_408 ) ;
F_224 ( V_2 , V_23 -> V_392 , & V_73 , & V_408 ) ;
if ( F_226 ( V_23 ) > ( V_411 - V_408 ) )
return;
if ( ! F_227 ( V_23 ) )
F_228 (ha, dev)
F_224 ( V_2 , V_413 -> V_6 , & V_73 , & V_408 ) ;
if ( F_229 ( V_23 ) || F_230 ( V_23 ) >= ( V_411 - V_408 ) )
return;
F_231 (ha, dev)
F_224 ( V_2 , V_413 -> V_6 , & V_73 , & V_408 ) ;
}
static int F_232 ( struct V_34 * V_23 , void * V_81 )
{
struct V_418 * V_6 = V_81 ;
if ( F_34 ( V_23 ) )
return - V_419 ;
F_233 ( V_23 -> V_392 , V_6 -> V_420 ) ;
return 0 ;
}
static void F_234 ( struct V_1 * V_2 )
{
struct V_421 * V_422 ;
T_2 V_98 ;
T_5 V_423 ;
T_6 V_424 ;
if ( F_235 ( V_2 ) ) {
V_28 = V_425 ;
V_33 = V_426 ;
V_2 -> V_263 = V_427 ;
V_2 -> V_65 = V_428 ;
} else if ( F_236 ( V_2 ) ) {
V_28 = V_425 ;
V_33 = V_429 ;
V_2 -> V_263 = V_427 ;
V_2 -> V_65 = V_430 ;
} else if ( F_151 ( V_2 ) ) {
V_28 = V_431 ;
V_33 = V_429 ;
V_2 -> V_263 = V_432 ;
V_2 -> V_65 = V_433 ;
} else if ( F_12 ( V_2 ) ) {
V_28 = V_434 ;
V_33 = V_429 ;
V_2 -> V_263 = V_432 ;
V_2 -> V_65 = V_435 ;
}
V_2 -> V_8 = & V_421 [ V_2 -> V_65 ] ;
V_422 = V_2 -> V_8 ;
V_98 = F_14 ( V_2 , V_436 ) ;
V_423 = ( V_98 >> 24 & 0x0f ) ;
if ( V_423 == 5 )
V_423 = 4 ;
else if ( V_423 == 0 )
V_423 = 1 ;
if ( V_423 != V_2 -> V_65 ) {
F_147 ( & V_2 -> V_182 -> V_23 ,
L_32 ,
V_423 , V_2 -> V_65 ) ;
}
F_237 ( & V_2 -> V_182 -> V_23 , L_33 V_437 ,
V_423 , ( V_98 >> 16 ) & 0x0f , V_98 & 0xffff ) ;
V_424 = V_98 & 0xffff ;
if ( ( V_424 & 0xf0 ) != 0 )
V_2 -> V_424 = V_424 << 8 ;
else if ( ( V_424 & 0xff00 ) != 0 )
V_2 -> V_424 = V_424 ;
else if ( V_424 == 0 || V_424 == 0x01ff ) {
F_238 ( L_34 , V_424 ) ;
return;
}
#ifdef F_7
if ( ! ( V_422 -> V_9 & V_10 ) )
F_238 ( L_35 ) ;
#endif
F_239 ( L_36
L_37
L_38
L_39
L_40
L_41
L_42 ,
V_2 -> V_65 ,
V_422 -> V_176 , V_422 -> V_328 ,
V_422 -> V_299 , V_422 -> V_337 ,
V_422 -> V_294 , V_422 -> V_295 ,
V_422 -> V_381 , V_422 -> V_191 ,
V_422 -> V_18 , V_422 -> V_438 ,
V_422 -> V_439 ,
V_422 -> V_344 , V_422 -> V_348 ,
V_422 -> V_301 ) ;
}
static int F_240 ( struct V_440 * V_182 )
{
struct V_441 * V_442 = V_182 -> V_23 . V_443 ;
struct V_444 * V_445 = V_182 -> V_23 . V_446 ;
const struct V_447 * V_448 = NULL ;
struct V_1 * V_2 ;
struct V_34 * V_23 ;
const void * V_449 ;
struct V_450 * V_25 ;
int V_451 = - V_452 ;
V_23 = F_241 ( sizeof( * V_2 ) , V_453 + 1 ,
V_453 + 1 ) ;
if ( ! V_23 ) {
F_147 ( & V_182 -> V_23 , L_43 ) ;
return - V_271 ;
}
if ( V_445 ) {
V_448 = F_242 ( V_454 , V_445 ) ;
if ( ! V_448 )
return - V_37 ;
}
V_2 = F_23 ( V_23 ) ;
V_2 -> V_394 = F_243 ( V_182 , 0 ) ;
V_2 -> V_398 = F_243 ( V_182 , 1 ) ;
V_2 -> V_455 = F_243 ( V_182 , 2 ) ;
if ( ! V_2 -> V_394 || ! V_2 -> V_398 ) {
F_147 ( & V_182 -> V_23 , L_44 ) ;
V_451 = - V_37 ;
goto V_451;
}
if ( V_445 ) {
V_449 = F_244 ( V_445 ) ;
if ( ! V_449 ) {
F_147 ( & V_182 -> V_23 , L_45 ) ;
V_451 = - V_37 ;
goto V_451;
}
} else {
V_449 = V_442 -> V_456 ;
}
V_25 = F_245 ( V_182 , V_457 , 0 ) ;
V_2 -> V_17 = F_246 ( & V_182 -> V_23 , V_25 ) ;
if ( F_211 ( V_2 -> V_17 ) ) {
V_451 = F_247 ( V_2 -> V_17 ) ;
goto V_451;
}
F_248 ( V_23 , & V_182 -> V_23 ) ;
F_249 ( & V_182 -> V_23 , V_23 ) ;
F_233 ( V_23 -> V_392 , V_449 ) ;
V_23 -> V_458 = 2 * V_459 ;
V_23 -> V_460 = & V_461 ;
V_23 -> V_462 = & V_463 ;
V_2 -> V_60 = F_250 ( - 1 , V_464 ) ;
V_23 -> V_465 |= V_466 | V_53 |
V_54 | V_43 ;
V_2 -> V_467 = true ;
V_451 = F_251 ( & V_182 -> V_23 , V_2 -> V_455 , F_190 , 0 ,
V_23 -> V_396 , V_2 ) ;
if ( ! V_451 )
F_252 ( & V_182 -> V_23 , 1 ) ;
V_23 -> V_468 += 64 ;
F_253 ( V_23 ) ;
V_2 -> V_23 = V_23 ;
V_2 -> V_182 = V_182 ;
if ( V_448 )
V_2 -> V_65 = (enum V_469 ) V_448 -> V_72 ;
else
V_2 -> V_65 = V_442 -> V_470 ;
V_2 -> V_389 = F_254 ( & V_2 -> V_182 -> V_23 , L_46 ) ;
if ( F_211 ( V_2 -> V_389 ) )
F_255 ( & V_2 -> V_182 -> V_23 , L_47 ) ;
if ( ! F_211 ( V_2 -> V_389 ) )
F_52 ( V_2 -> V_389 ) ;
F_234 ( V_2 ) ;
F_256 ( & V_2 -> V_371 ) ;
V_2 -> V_230 = V_307 ;
F_257 ( & V_2 -> V_353 , F_180 ) ;
V_2 -> V_471 = F_254 ( & V_2 -> V_182 -> V_23 , L_48 ) ;
if ( F_211 ( V_2 -> V_471 ) )
F_255 ( & V_2 -> V_182 -> V_23 , L_49 ) ;
V_2 -> V_100 = F_254 ( & V_2 -> V_182 -> V_23 , L_50 ) ;
if ( F_211 ( V_2 -> V_100 ) ) {
F_255 ( & V_2 -> V_182 -> V_23 , L_51 ) ;
V_2 -> V_100 = NULL ;
}
V_451 = F_145 ( V_2 ) ;
if ( V_451 )
goto V_390;
V_451 = F_258 ( V_23 ) ;
if ( V_451 )
goto V_390;
F_259 ( V_2 -> V_23 , V_2 -> V_8 -> V_176 + 1 ) ;
F_260 ( V_2 -> V_23 , V_2 -> V_8 -> V_299 + 1 ) ;
F_261 ( V_23 ) ;
if ( ! F_211 ( V_2 -> V_389 ) )
F_53 ( V_2 -> V_389 ) ;
V_451 = F_262 ( V_23 ) ;
if ( V_451 )
goto V_451;
return V_451 ;
V_390:
if ( ! F_211 ( V_2 -> V_389 ) )
F_53 ( V_2 -> V_389 ) ;
V_451:
F_263 ( V_23 ) ;
return V_451 ;
}
static int F_264 ( struct V_440 * V_182 )
{
struct V_1 * V_2 = F_22 ( & V_182 -> V_23 ) ;
F_249 ( & V_182 -> V_23 , NULL ) ;
F_265 ( V_2 -> V_23 ) ;
F_266 ( V_2 -> V_23 ) ;
F_263 ( V_2 -> V_23 ) ;
return 0 ;
}
static int F_267 ( struct V_22 * V_3 )
{
struct V_34 * V_23 = F_24 ( V_3 ) ;
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_59 ;
if ( ! F_34 ( V_23 ) )
return 0 ;
F_216 ( V_23 ) ;
F_268 ( V_2 -> V_38 ) ;
F_269 ( V_23 ) ;
F_143 ( V_2 , V_387 , false ) ;
V_59 = F_174 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_143 ( V_2 , V_386 , false ) ;
F_103 ( V_23 ) ;
F_176 ( V_2 ) ;
if ( F_270 ( V_3 ) && V_2 -> V_472 ) {
V_59 = F_62 ( V_2 , V_119 ) ;
F_52 ( V_2 -> V_471 ) ;
} else if ( F_152 ( V_2 -> V_38 ) ) {
V_59 = F_62 ( V_2 , V_120 ) ;
}
F_53 ( V_2 -> V_389 ) ;
return V_59 ;
}
static int F_271 ( struct V_22 * V_3 )
{
struct V_34 * V_23 = F_24 ( V_3 ) ;
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned long V_321 ;
int V_59 ;
T_2 V_98 ;
if ( ! F_34 ( V_23 ) )
return 0 ;
V_59 = F_52 ( V_2 -> V_389 ) ;
if ( V_59 )
return V_59 ;
if ( F_152 ( V_2 -> V_38 ) )
F_68 ( V_2 , V_120 ) ;
F_192 ( V_2 ) ;
V_59 = F_149 ( V_2 ) ;
if ( V_59 )
goto V_473;
if ( V_2 -> V_472 )
F_53 ( V_2 -> V_471 ) ;
F_272 ( V_2 -> V_38 ) ;
F_213 ( V_2 -> V_23 , false ) ;
F_143 ( V_2 , V_386 | V_387 , false ) ;
F_193 ( V_2 , V_23 -> V_392 ) ;
if ( F_152 ( V_2 -> V_38 ) ) {
V_98 = F_65 ( V_2 , V_122 ) ;
V_98 |= V_393 ;
F_66 ( V_2 , V_98 , V_122 ) ;
}
if ( V_2 -> V_472 )
F_68 ( V_2 , V_119 ) ;
V_321 = F_194 ( V_2 ) ;
V_59 = F_178 ( V_2 ) ;
if ( V_59 ) {
F_128 ( V_23 , L_26 ) ;
goto V_473;
}
F_195 ( V_2 , V_321 ) ;
F_273 ( V_23 ) ;
F_274 ( V_2 -> V_38 ) ;
if ( V_2 -> V_108 . V_109 )
F_51 ( V_23 , true ) ;
F_207 ( V_23 ) ;
return 0 ;
V_473:
F_53 ( V_2 -> V_389 ) ;
return V_59 ;
}
