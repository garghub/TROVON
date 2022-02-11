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
F_39 ( V_2 -> V_39 , V_37 ) ;
return 0 ;
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
static struct V_160 * F_81 ( struct V_1 * V_2 ,
struct V_161 * V_30 )
{
struct V_160 * V_162 ;
V_162 = V_30 -> V_163 ;
V_162 += V_30 -> V_164 - V_30 -> V_165 ;
if ( V_30 -> V_164 == V_30 -> V_165 )
V_30 -> V_164 = V_30 -> V_166 ;
else
V_30 -> V_164 -- ;
return V_162 ;
}
static inline void F_82 ( struct V_167 * V_30 )
{
F_83 ( V_30 -> V_2 , V_168 ,
V_169 ) ;
}
static inline void F_84 ( struct V_167 * V_30 )
{
F_83 ( V_30 -> V_2 , V_168 ,
V_170 ) ;
}
static inline void F_85 ( struct V_167 * V_30 )
{
F_86 ( V_30 -> V_2 ,
1 << ( V_171 + V_30 -> V_172 ) ,
V_169 ) ;
}
static inline void F_87 ( struct V_167 * V_30 )
{
F_86 ( V_30 -> V_2 ,
1 << ( V_171 + V_30 -> V_172 ) ,
V_170 ) ;
}
static inline void F_88 ( struct V_161 * V_30 )
{
F_83 ( V_30 -> V_2 , V_173 ,
V_169 ) ;
}
static inline void F_89 ( struct V_161 * V_30 )
{
F_83 ( V_30 -> V_2 , V_173 ,
V_170 ) ;
}
static inline void F_90 ( struct V_161 * V_30 )
{
F_86 ( V_30 -> V_2 , 1 << V_30 -> V_172 ,
V_170 ) ;
}
static inline void F_91 ( struct V_161 * V_30 )
{
F_86 ( V_30 -> V_2 , 1 << V_30 -> V_172 ,
V_169 ) ;
}
static struct V_174 * F_92 ( struct V_22 * V_23 ,
struct V_160 * V_175 )
{
struct V_174 * V_176 ;
V_176 = V_175 -> V_176 ;
if ( V_176 ) {
V_175 -> V_176 = NULL ;
if ( V_175 == F_93 ( V_176 ) -> V_177 )
F_94 ( V_23 , F_95 ( V_175 , V_178 ) ,
F_96 ( V_175 , V_179 ) ,
V_180 ) ;
else
F_97 ( V_23 , F_95 ( V_175 , V_178 ) ,
F_96 ( V_175 , V_179 ) ,
V_180 ) ;
F_98 ( V_175 , V_178 , 0 ) ;
if ( V_175 == F_93 ( V_176 ) -> V_181 )
return V_176 ;
} else if ( F_95 ( V_175 , V_178 ) ) {
F_97 ( V_23 ,
F_95 ( V_175 , V_178 ) ,
F_96 ( V_175 , V_179 ) ,
V_180 ) ;
F_98 ( V_175 , V_178 , 0 ) ;
}
return 0 ;
}
static struct V_174 * F_99 ( struct V_22 * V_23 ,
struct V_160 * V_175 )
{
struct V_174 * V_176 ;
V_176 = V_175 -> V_176 ;
V_175 -> V_176 = NULL ;
if ( F_95 ( V_175 , V_178 ) ) {
F_94 ( V_23 , F_95 ( V_175 , V_178 ) ,
F_96 ( V_175 , V_179 ) , V_182 ) ;
F_98 ( V_175 , V_178 , 0 ) ;
}
return V_176 ;
}
static unsigned int F_100 ( struct V_34 * V_23 ,
struct V_161 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned int V_183 = 0 ;
unsigned int V_184 = 0 ;
unsigned int V_185 = 0 ;
unsigned int V_186 ;
unsigned int V_187 ;
struct V_174 * V_176 ;
if ( V_30 -> V_172 == V_66 )
F_83 ( V_2 , V_173 ,
V_188 ) ;
else
F_86 ( V_2 , ( 1 << V_30 -> V_172 ) ,
V_188 ) ;
V_187 = F_29 ( V_2 , V_30 -> V_172 , V_189 )
& V_190 ;
V_186 = ( V_187 - V_30 -> V_187 ) & V_190 ;
F_101 ( V_2 , V_191 , V_23 ,
L_4 ,
V_192 , V_30 -> V_172 , V_30 -> V_187 , V_187 , V_186 ) ;
while ( V_183 < V_186 ) {
V_176 = F_92 ( & V_2 -> V_193 -> V_23 ,
& V_2 -> V_194 [ V_30 -> V_195 ] ) ;
if ( V_176 ) {
V_185 ++ ;
V_184 += F_93 ( V_176 ) -> V_196 ;
F_102 ( V_176 ) ;
}
V_183 ++ ;
if ( F_103 ( V_30 -> V_195 < V_30 -> V_166 ) )
V_30 -> V_195 ++ ;
else
V_30 -> V_195 = V_30 -> V_165 ;
}
V_30 -> V_197 += V_183 ;
V_30 -> V_187 = V_187 ;
V_30 -> V_198 += V_185 ;
V_30 -> V_199 += V_184 ;
F_104 ( F_105 ( V_23 , V_30 -> V_200 ) ,
V_185 , V_184 ) ;
return V_183 ;
}
static unsigned int F_106 ( struct V_34 * V_23 ,
struct V_161 * V_30 )
{
unsigned int V_201 ;
unsigned long V_9 ;
F_107 ( & V_30 -> V_202 , V_9 ) ;
V_201 = F_100 ( V_23 , V_30 ) ;
F_108 ( & V_30 -> V_202 , V_9 ) ;
return V_201 ;
}
static int F_109 ( struct V_203 * V_204 , int V_205 )
{
struct V_161 * V_30 =
F_110 ( V_204 , struct V_161 , V_204 ) ;
unsigned int V_206 = 0 ;
struct V_207 * V_208 ;
unsigned long V_9 ;
F_107 ( & V_30 -> V_202 , V_9 ) ;
V_206 = F_100 ( V_30 -> V_2 -> V_23 , V_30 ) ;
if ( V_30 -> V_197 > ( V_209 + 1 ) ) {
V_208 = F_105 ( V_30 -> V_2 -> V_23 , V_30 -> V_200 ) ;
F_111 ( V_208 ) ;
}
F_108 ( & V_30 -> V_202 , V_9 ) ;
if ( V_206 == 0 ) {
F_112 ( V_204 ) ;
V_30 -> V_210 ( V_30 ) ;
return 0 ;
}
return V_205 ;
}
static void F_113 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_71 ;
if ( F_114 ( V_23 ) ) {
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; V_71 ++ )
F_106 ( V_23 , & V_2 -> V_211 [ V_71 ] ) ;
}
F_106 ( V_23 , & V_2 -> V_211 [ V_66 ] ) ;
}
static struct V_174 * F_115 ( struct V_34 * V_23 ,
struct V_174 * V_176 )
{
struct V_212 * V_213 = NULL ;
struct V_174 * V_214 ;
T_6 V_95 ;
T_5 V_215 ;
T_6 V_216 ;
T_2 V_217 ;
if ( F_116 ( F_117 ( V_176 ) < sizeof( * V_213 ) ) ) {
V_214 = F_118 ( V_176 , sizeof( * V_213 ) ) ;
F_119 ( V_176 ) ;
if ( ! V_214 ) {
V_23 -> V_119 . V_218 ++ ;
return NULL ;
}
V_176 = V_214 ;
}
F_120 ( V_176 , sizeof( * V_213 ) ) ;
V_213 = (struct V_212 * ) V_176 -> V_91 ;
if ( V_176 -> V_219 == V_220 ) {
V_216 = F_121 ( V_176 -> V_221 ) ;
switch ( V_216 ) {
case V_222 :
V_215 = F_122 ( V_176 ) -> V_221 ;
break;
case V_223 :
V_215 = F_123 ( V_176 ) -> V_224 ;
break;
default:
return V_176 ;
}
V_95 = F_124 ( V_176 ) - sizeof( * V_213 ) ;
V_217 = ( V_95 << V_225 ) |
( V_95 + V_176 -> V_226 ) ;
if ( V_215 == V_227 || V_215 == V_228 ) {
V_217 |= V_229 ;
if ( V_215 == V_228 && V_216 == V_222 )
V_217 |= V_230 ;
} else {
V_217 = 0 ;
}
V_213 -> V_217 = V_217 ;
}
return V_176 ;
}
static T_7 F_125 ( struct V_174 * V_176 , struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_22 * V_231 = & V_2 -> V_193 -> V_23 ;
struct V_161 * V_30 = NULL ;
struct V_160 * V_162 ;
struct V_207 * V_208 ;
unsigned long V_9 = 0 ;
int V_232 , V_172 ;
T_3 V_233 ;
unsigned int V_234 ;
T_8 * V_235 ;
T_2 V_236 ;
int V_60 ;
int V_71 ;
V_172 = F_126 ( V_176 ) ;
if ( V_172 == 0 )
V_172 = V_66 ;
else
V_172 -= 1 ;
V_30 = & V_2 -> V_211 [ V_172 ] ;
V_208 = F_105 ( V_23 , V_30 -> V_200 ) ;
V_232 = F_127 ( V_176 ) -> V_232 ;
F_107 ( & V_30 -> V_202 , V_9 ) ;
if ( V_30 -> V_197 <= ( V_232 + 1 ) ) {
if ( ! F_128 ( V_208 ) ) {
F_129 ( V_208 ) ;
F_130 ( V_23 ,
L_5 ,
V_192 , V_172 , V_30 -> V_200 ) ;
}
V_60 = V_237 ;
goto V_238;
}
if ( F_131 ( V_176 , V_239 ) ) {
V_60 = V_240 ;
goto V_238;
}
F_93 ( V_176 ) -> V_196 = V_176 -> V_241 ;
if ( V_2 -> V_50 ) {
V_176 = F_115 ( V_23 , V_176 ) ;
if ( ! V_176 ) {
V_60 = V_240 ;
goto V_238;
}
}
for ( V_71 = 0 ; V_71 <= V_232 ; V_71 ++ ) {
V_162 = F_80 ( V_2 , V_30 ) ;
if ( F_116 ( ! V_162 ) )
F_132 () ;
if ( ! V_71 ) {
F_93 ( V_176 ) -> V_177 = V_162 ;
V_234 = F_133 ( V_176 ) ;
V_233 = F_134 ( V_231 , V_176 -> V_91 , V_234 ,
V_180 ) ;
} else {
V_235 = & F_127 ( V_176 ) -> V_242 [ V_71 - 1 ] ;
V_234 = F_135 ( V_235 ) ;
V_233 = F_136 ( V_231 , V_235 , 0 , V_234 ,
V_180 ) ;
}
V_60 = F_137 ( V_231 , V_233 ) ;
if ( V_60 ) {
V_2 -> V_243 . V_244 ++ ;
F_65 ( V_2 , V_245 , V_23 , L_6 ) ;
V_60 = V_240 ;
goto V_246;
}
F_98 ( V_162 , V_178 , V_233 ) ;
F_138 ( V_162 , V_179 , V_234 ) ;
V_162 -> V_176 = V_176 ;
V_236 = ( V_234 << V_247 ) |
( V_2 -> V_8 -> V_248 << V_249 ) ;
if ( ! V_71 ) {
V_236 |= V_250 | V_251 ;
if ( V_176 -> V_219 == V_220 )
V_236 |= V_252 ;
}
if ( V_71 == V_232 )
V_236 |= V_253 ;
F_9 ( V_2 , V_162 -> V_254 , V_233 , V_236 ) ;
}
F_93 ( V_176 ) -> V_181 = V_162 ;
F_139 ( V_176 ) ;
V_30 -> V_197 -= V_232 + 1 ;
V_30 -> V_255 += V_232 + 1 ;
V_30 -> V_255 &= V_256 ;
F_140 ( V_208 , F_93 ( V_176 ) -> V_196 ) ;
if ( V_30 -> V_197 <= ( V_209 + 1 ) )
F_129 ( V_208 ) ;
if ( ! V_176 -> V_257 || F_141 ( V_208 ) )
F_30 ( V_2 , V_30 -> V_172 ,
V_30 -> V_255 , V_258 ) ;
V_238:
F_108 ( & V_30 -> V_202 , V_9 ) ;
return V_60 ;
V_246:
F_81 ( V_2 , V_30 ) ;
while ( V_71 -- > 0 ) {
V_162 = F_81 ( V_2 , V_30 ) ;
F_92 ( V_231 , V_162 ) ;
}
F_119 ( V_176 ) ;
goto V_238;
}
static struct V_174 * F_142 ( struct V_1 * V_2 ,
struct V_160 * V_175 )
{
struct V_22 * V_231 = & V_2 -> V_193 -> V_23 ;
struct V_174 * V_176 ;
struct V_174 * V_259 ;
T_3 V_233 ;
V_176 = F_143 ( V_2 -> V_23 , V_2 -> V_260 + V_261 ) ;
if ( ! V_176 ) {
V_2 -> V_243 . V_262 ++ ;
F_65 ( V_2 , V_263 , V_2 -> V_23 ,
L_7 , V_192 ) ;
return NULL ;
}
V_233 = F_134 ( V_231 , V_176 -> V_91 , V_2 -> V_260 ,
V_182 ) ;
if ( F_137 ( V_231 , V_233 ) ) {
V_2 -> V_243 . V_264 ++ ;
F_144 ( V_176 ) ;
F_65 ( V_2 , V_263 , V_2 -> V_23 ,
L_8 , V_192 ) ;
return NULL ;
}
V_259 = F_99 ( V_231 , V_175 ) ;
V_175 -> V_176 = V_176 ;
F_98 ( V_175 , V_178 , V_233 ) ;
F_138 ( V_175 , V_179 , V_2 -> V_260 ) ;
F_5 ( V_2 , V_175 -> V_254 , V_233 ) ;
return V_259 ;
}
static unsigned int F_145 ( struct V_167 * V_30 ,
unsigned int V_205 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_34 * V_23 = V_2 -> V_23 ;
struct V_160 * V_175 ;
struct V_174 * V_176 ;
T_2 V_265 ;
unsigned long V_266 ;
int V_241 ;
unsigned int V_267 = 0 , V_268 ;
unsigned int V_269 , V_270 ;
unsigned int V_271 ;
unsigned int V_272 = 0 ;
if ( V_30 -> V_172 == V_66 ) {
F_83 ( V_2 , V_168 ,
V_188 ) ;
} else {
V_270 = 1 << ( V_171 + V_30 -> V_172 ) ;
F_86 ( V_2 ,
V_270 ,
V_188 ) ;
}
V_269 = F_31 ( V_2 , V_30 -> V_172 , V_273 ) ;
V_271 = ( V_269 >> V_274 ) &
V_275 ;
if ( V_271 > V_30 -> V_276 ) {
V_271 = V_271 - V_30 -> V_276 ;
V_30 -> V_277 += V_271 ;
V_30 -> V_276 += V_271 ;
if ( V_30 -> V_276 >= 0xC000 ) {
V_30 -> V_276 = 0 ;
F_32 ( V_2 , V_30 -> V_172 , 0 ,
V_273 ) ;
}
}
V_269 &= V_256 ;
V_268 = ( V_269 - V_30 -> V_187 ) & V_190 ;
F_101 ( V_2 , V_278 , V_23 ,
L_9 , V_268 ) ;
while ( ( V_267 < V_268 ) &&
( V_267 < V_205 ) ) {
V_175 = & V_2 -> V_279 [ V_30 -> V_280 ] ;
V_176 = F_142 ( V_2 , V_175 ) ;
if ( F_116 ( ! V_176 ) ) {
V_30 -> V_281 ++ ;
goto V_282;
}
if ( ! V_2 -> V_50 ) {
V_265 =
F_3 ( V_2 , V_175 -> V_254 ) ;
} else {
struct V_212 * V_213 ;
V_213 = (struct V_212 * ) V_176 -> V_91 ;
V_265 = V_213 -> V_283 ;
}
V_266 = V_265 & 0xffff ;
V_241 = V_265 >> V_247 ;
F_101 ( V_2 , V_278 , V_23 ,
L_10 ,
V_192 , V_269 , V_30 -> V_187 ,
V_30 -> V_280 , V_265 ) ;
if ( F_116 ( ! ( V_266 & V_253 ) || ! ( V_266 & V_251 ) ) ) {
F_65 ( V_2 , V_278 , V_23 ,
L_11 ) ;
V_30 -> V_277 ++ ;
F_144 ( V_176 ) ;
goto V_282;
}
if ( F_116 ( V_266 & ( V_284 |
V_285 |
V_286 |
V_287 |
V_288 ) ) ) {
F_65 ( V_2 , V_278 , V_23 , L_12 ,
( unsigned int ) V_266 ) ;
if ( V_266 & V_284 )
V_23 -> V_119 . V_289 ++ ;
if ( V_266 & V_285 )
V_23 -> V_119 . V_290 ++ ;
if ( V_266 & V_286 )
V_23 -> V_119 . V_291 ++ ;
if ( V_266 & V_287 )
V_23 -> V_119 . V_292 ++ ;
V_23 -> V_119 . V_293 ++ ;
F_144 ( V_176 ) ;
goto V_282;
}
V_272 = ( V_266 & V_2 -> V_294 ) &&
V_2 -> V_47 ;
F_146 ( V_176 , V_241 ) ;
if ( V_2 -> V_50 ) {
F_147 ( V_176 , 64 ) ;
V_241 -= 64 ;
}
if ( F_103 ( V_272 ) )
V_176 -> V_219 = V_295 ;
F_147 ( V_176 , 2 ) ;
V_241 -= 2 ;
if ( V_2 -> V_48 ) {
F_148 ( V_176 , V_241 - V_296 ) ;
V_241 -= V_296 ;
}
V_176 -> V_221 = F_149 ( V_176 , V_2 -> V_23 ) ;
V_30 -> V_198 ++ ;
V_30 -> V_199 += V_241 ;
if ( V_266 & V_297 )
V_23 -> V_119 . V_298 ++ ;
F_150 ( & V_30 -> V_204 , V_176 ) ;
F_101 ( V_2 , V_278 , V_23 , L_13 ) ;
V_282:
V_267 ++ ;
if ( F_103 ( V_30 -> V_280 < V_30 -> V_166 ) )
V_30 -> V_280 ++ ;
else
V_30 -> V_280 = V_30 -> V_165 ;
V_30 -> V_187 = ( V_30 -> V_187 + 1 ) & V_190 ;
F_32 ( V_2 , V_30 -> V_172 , V_30 -> V_187 , V_299 ) ;
}
return V_267 ;
}
static int F_151 ( struct V_203 * V_204 , int V_205 )
{
struct V_167 * V_30 = F_110 ( V_204 ,
struct V_167 , V_204 ) ;
unsigned int V_206 ;
V_206 = F_145 ( V_30 , V_205 ) ;
if ( V_206 < V_205 ) {
F_152 ( V_204 , V_206 ) ;
V_30 -> V_210 ( V_30 ) ;
}
return V_206 ;
}
static int F_153 ( struct V_1 * V_2 ,
struct V_167 * V_30 )
{
struct V_160 * V_175 ;
struct V_174 * V_176 ;
int V_71 ;
F_101 ( V_2 , V_139 , V_2 -> V_23 , L_14 , V_192 ) ;
for ( V_71 = 0 ; V_71 < V_30 -> V_234 ; V_71 ++ ) {
V_175 = V_30 -> V_163 + V_71 ;
V_176 = F_142 ( V_2 , V_175 ) ;
if ( V_176 )
F_102 ( V_176 ) ;
if ( ! V_175 -> V_176 )
return - V_300 ;
}
return 0 ;
}
static void F_154 ( struct V_1 * V_2 )
{
struct V_174 * V_176 ;
struct V_160 * V_175 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_301 ; V_71 ++ ) {
V_175 = & V_2 -> V_279 [ V_71 ] ;
V_176 = F_99 ( & V_2 -> V_193 -> V_23 , V_175 ) ;
if ( V_176 )
F_102 ( V_176 ) ;
}
}
static void F_155 ( struct V_1 * V_2 , T_2 V_270 , bool V_120 )
{
T_2 V_72 ;
V_72 = F_56 ( V_2 , V_302 ) ;
if ( V_120 )
V_72 |= V_270 ;
else
V_72 &= ~ V_270 ;
F_57 ( V_2 , V_72 , V_302 ) ;
if ( V_120 == 0 )
F_156 ( 1000 , 2000 ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
struct V_22 * V_231 = & V_2 -> V_193 -> V_23 ;
unsigned int V_303 = 0 ;
T_2 V_72 ;
F_15 ( V_2 , 0 ) ;
F_158 ( 10 ) ;
F_57 ( V_2 , 0 , V_302 ) ;
F_57 ( V_2 , V_304 , V_302 ) ;
while ( V_303 ++ < 1000 ) {
V_72 = F_56 ( V_2 , V_302 ) ;
if ( ! ( V_72 & V_304 ) )
return 0 ;
F_158 ( 1 ) ;
}
if ( V_303 == 1000 ) {
F_159 ( V_231 ,
L_15 ) ;
return - V_305 ;
}
return 0 ;
}
static void F_160 ( struct V_1 * V_2 )
{
F_83 ( V_2 , 0xFFFFFFFF , V_169 ) ;
F_83 ( V_2 , 0xFFFFFFFF , V_188 ) ;
F_86 ( V_2 , 0xFFFFFFFF , V_169 ) ;
F_86 ( V_2 , 0xFFFFFFFF , V_188 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
T_2 V_306 = 0 ;
if ( V_2 -> V_307 ) {
V_306 |= V_308 ;
} else if ( V_2 -> V_309 ) {
V_306 |= V_308 ;
} else if ( V_2 -> V_310 == V_311 ) {
if ( V_2 -> V_8 -> V_9 & V_312 )
V_306 |= V_308 ;
}
F_83 ( V_2 , V_306 , V_170 ) ;
}
static int F_162 ( struct V_1 * V_2 )
{
struct V_22 * V_231 = & V_2 -> V_193 -> V_23 ;
int V_60 ;
T_2 V_72 ;
T_2 V_306 = 0 ;
F_163 ( & V_2 -> V_193 -> V_23 , L_16 ) ;
V_60 = F_157 ( V_2 ) ;
if ( V_60 )
return V_60 ;
F_57 ( V_2 , 0 , V_302 ) ;
F_57 ( V_2 ,
V_313 | V_314 | V_315 ,
V_316 ) ;
F_57 ( V_2 , 0 , V_316 ) ;
F_57 ( V_2 , V_317 , V_318 ) ;
V_72 = F_13 ( V_2 , V_53 ) ;
V_72 |= V_319 ;
F_16 ( V_2 , V_72 , V_53 ) ;
if ( ! F_12 ( V_2 ) && ! F_55 ( V_2 ) )
F_16 ( V_2 , 1 , V_320 ) ;
F_160 ( V_2 ) ;
if ( V_2 -> V_310 == V_311 ) {
V_72 = F_20 ( V_2 ) ;
V_72 |= F_164 ( V_2 -> V_8 -> V_321 ) ;
if ( F_114 ( V_2 -> V_23 ) )
V_72 |= V_2 -> V_8 -> V_322 ;
else
V_72 &= ~ V_2 -> V_8 -> V_322 ;
F_21 ( V_2 , V_72 ) ;
}
if ( V_2 -> V_8 -> V_9 & V_323 )
V_306 |= ( V_324 | V_325 ) ;
F_83 ( V_2 , V_306 , V_170 ) ;
F_163 ( V_231 , L_17 ) ;
return 0 ;
}
static void F_165 ( struct V_1 * V_2 ,
unsigned int V_172 , unsigned int V_234 ,
unsigned int V_326 , unsigned int V_166 )
{
struct V_161 * V_30 = & V_2 -> V_211 [ V_172 ] ;
T_2 V_327 = F_166 ( V_2 ) ;
T_2 V_328 = 0 ;
F_167 ( & V_30 -> V_202 ) ;
V_30 -> V_2 = V_2 ;
V_30 -> V_172 = V_172 ;
if ( V_172 == V_66 ) {
V_30 -> V_200 = 0 ;
V_30 -> V_210 = F_89 ;
V_30 -> V_329 = F_88 ;
} else {
V_30 -> V_200 = V_172 + 1 ;
V_30 -> V_210 = F_90 ;
V_30 -> V_329 = F_91 ;
}
V_30 -> V_163 = V_2 -> V_194 + V_326 ;
V_30 -> V_234 = V_234 ;
V_30 -> V_195 = V_326 ;
V_30 -> V_187 = 0 ;
V_30 -> V_197 = V_234 ;
V_30 -> V_164 = V_326 ;
V_30 -> V_165 = V_326 ;
V_30 -> V_166 = V_166 - 1 ;
V_30 -> V_255 = 0 ;
if ( V_172 != V_66 )
V_328 = V_317 << 16 ;
F_30 ( V_2 , V_172 , 0 , V_258 ) ;
F_30 ( V_2 , V_172 , 0 , V_189 ) ;
F_30 ( V_2 , V_172 , 1 , V_67 ) ;
F_30 ( V_2 , V_172 , V_328 ,
V_330 ) ;
F_30 ( V_2 , V_172 ,
( ( V_234 << V_331 ) |
V_332 ) , V_333 ) ;
F_30 ( V_2 , V_172 , V_326 * V_327 ,
V_334 ) ;
F_30 ( V_2 , V_172 , V_326 * V_327 ,
V_335 ) ;
F_30 ( V_2 , V_172 , V_326 * V_327 ,
V_336 ) ;
F_30 ( V_2 , V_172 , V_166 * V_327 - 1 ,
V_337 ) ;
}
static int F_168 ( struct V_1 * V_2 ,
unsigned int V_172 , unsigned int V_234 ,
unsigned int V_326 , unsigned int V_166 )
{
struct V_167 * V_30 = & V_2 -> V_338 [ V_172 ] ;
T_2 V_327 = F_166 ( V_2 ) ;
int V_60 ;
V_30 -> V_2 = V_2 ;
V_30 -> V_172 = V_172 ;
if ( V_172 == V_66 ) {
V_30 -> V_210 = F_84 ;
V_30 -> V_329 = F_82 ;
} else {
V_30 -> V_210 = F_87 ;
V_30 -> V_329 = F_85 ;
}
V_30 -> V_163 = V_2 -> V_279 + V_326 ;
V_30 -> V_234 = V_234 ;
V_30 -> V_187 = 0 ;
V_30 -> V_280 = V_326 ;
V_30 -> V_165 = V_326 ;
V_30 -> V_166 = V_166 - 1 ;
V_60 = F_153 ( V_2 , V_30 ) ;
if ( V_60 )
return V_60 ;
F_32 ( V_2 , V_172 , 0 , V_273 ) ;
F_32 ( V_2 , V_172 , 0 , V_299 ) ;
F_32 ( V_2 , V_172 , 1 , V_67 ) ;
F_32 ( V_2 , V_172 ,
( ( V_234 << V_331 ) |
V_332 ) , V_333 ) ;
F_32 ( V_2 , V_172 ,
( V_339 <<
V_340 ) |
V_341 , V_342 ) ;
F_32 ( V_2 , V_172 , V_326 * V_327 ,
V_334 ) ;
F_32 ( V_2 , V_172 , V_326 * V_327 ,
V_343 ) ;
F_32 ( V_2 , V_172 , V_326 * V_327 ,
V_344 ) ;
F_32 ( V_2 , V_172 , V_166 * V_327 - 1 ,
V_337 ) ;
return V_60 ;
}
static void F_169 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
struct V_161 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; ++ V_71 ) {
V_30 = & V_2 -> V_211 [ V_71 ] ;
F_170 ( V_2 -> V_23 , & V_30 -> V_204 , F_109 , 64 ) ;
}
V_30 = & V_2 -> V_211 [ V_66 ] ;
F_170 ( V_2 -> V_23 , & V_30 -> V_204 , F_109 , 64 ) ;
}
static void F_171 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
T_2 V_306 = V_173 ;
T_2 V_345 = 0 ;
struct V_161 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; ++ V_71 ) {
V_30 = & V_2 -> V_211 [ V_71 ] ;
F_172 ( & V_30 -> V_204 ) ;
V_345 |= ( 1 << V_71 ) ;
}
V_30 = & V_2 -> V_211 [ V_66 ] ;
F_172 ( & V_30 -> V_204 ) ;
F_83 ( V_2 , V_306 , V_170 ) ;
F_86 ( V_2 , V_345 , V_170 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
T_2 V_346 = V_173 ;
T_2 V_347 = 0xffff ;
struct V_161 * V_30 ;
F_83 ( V_2 , V_346 , V_169 ) ;
F_86 ( V_2 , V_347 , V_169 ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; ++ V_71 ) {
V_30 = & V_2 -> V_211 [ V_71 ] ;
F_174 ( & V_30 -> V_204 ) ;
}
V_30 = & V_2 -> V_211 [ V_66 ] ;
F_174 ( & V_30 -> V_204 ) ;
}
static void F_175 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
struct V_161 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; ++ V_71 ) {
V_30 = & V_2 -> V_211 [ V_71 ] ;
F_176 ( & V_30 -> V_204 ) ;
}
V_30 = & V_2 -> V_211 [ V_66 ] ;
F_176 ( & V_30 -> V_204 ) ;
}
static void F_177 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_71 , V_348 ;
T_2 V_349 , V_350 ;
T_2 V_351 [ 3 ] = { 0 , 0 , 0 } ;
V_349 = F_25 ( V_2 , V_352 ) ;
V_348 = V_349 & V_353 ;
V_349 &= ~ V_353 ;
F_26 ( V_2 , V_349 , V_352 ) ;
V_349 = 0 ;
V_350 = 0 ;
F_26 ( V_2 , V_354 , V_355 ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; V_71 ++ ) {
F_165 ( V_2 , V_71 , V_2 -> V_8 -> V_356 ,
V_71 * V_2 -> V_8 -> V_356 ,
( V_71 + 1 ) * V_2 -> V_8 -> V_356 ) ;
V_350 |= ( 1 << V_71 ) ;
V_349 |= ( 1 << ( V_71 + V_357 ) ) ;
V_351 [ F_178 ( V_71 ) ] |=
( ( V_358 + V_71 ) << F_179 ( V_71 ) ) ;
}
F_165 ( V_2 , V_66 , V_359 ,
V_2 -> V_8 -> V_80 *
V_2 -> V_8 -> V_356 ,
V_360 ) ;
V_350 |= ( 1 << V_66 ) ;
V_349 |= ( 1 << ( V_66 + V_357 ) ) ;
V_351 [ F_178 ( V_66 ) ] |=
( ( V_358 + V_2 -> V_8 -> V_80 ) <<
F_179 ( V_66 ) ) ;
F_26 ( V_2 , V_351 [ 0 ] , V_361 ) ;
F_26 ( V_2 , V_351 [ 1 ] , V_362 ) ;
F_26 ( V_2 , V_351 [ 2 ] , V_363 ) ;
F_169 ( V_2 ) ;
F_26 ( V_2 , V_350 , V_364 ) ;
if ( V_348 )
V_349 |= V_353 ;
F_26 ( V_2 , V_349 , V_352 ) ;
}
static void F_180 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
struct V_167 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; ++ V_71 ) {
V_30 = & V_2 -> V_338 [ V_71 ] ;
F_181 ( V_2 -> V_23 , & V_30 -> V_204 , F_151 , 64 ) ;
}
V_30 = & V_2 -> V_338 [ V_66 ] ;
F_181 ( V_2 -> V_23 , & V_30 -> V_204 , F_151 , 64 ) ;
}
static void F_182 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
T_2 V_306 = V_168 ;
T_2 V_345 = 0 ;
struct V_167 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; ++ V_71 ) {
V_30 = & V_2 -> V_338 [ V_71 ] ;
F_172 ( & V_30 -> V_204 ) ;
V_345 |= ( 1 << ( V_171 + V_71 ) ) ;
}
V_30 = & V_2 -> V_338 [ V_66 ] ;
F_172 ( & V_30 -> V_204 ) ;
F_83 ( V_2 , V_306 , V_170 ) ;
F_86 ( V_2 , V_345 , V_170 ) ;
}
static void F_183 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
T_2 V_346 = V_168 ;
T_2 V_347 = 0xffff << V_171 ;
struct V_167 * V_30 ;
F_83 ( V_2 , V_346 , V_169 ) ;
F_86 ( V_2 , V_347 , V_169 ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; ++ V_71 ) {
V_30 = & V_2 -> V_338 [ V_71 ] ;
F_174 ( & V_30 -> V_204 ) ;
}
V_30 = & V_2 -> V_338 [ V_66 ] ;
F_174 ( & V_30 -> V_204 ) ;
}
static void F_184 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
struct V_167 * V_30 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; ++ V_71 ) {
V_30 = & V_2 -> V_338 [ V_71 ] ;
F_176 ( & V_30 -> V_204 ) ;
}
V_30 = & V_2 -> V_338 [ V_66 ] ;
F_176 ( & V_30 -> V_204 ) ;
}
static int F_185 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_71 ;
T_2 V_348 ;
T_2 V_349 ;
T_2 V_350 ;
int V_60 ;
V_349 = F_27 ( V_2 , V_352 ) ;
V_348 = V_349 & V_353 ;
V_349 &= ~ V_353 ;
F_28 ( V_2 , V_349 , V_352 ) ;
V_349 = 0 ;
V_350 = 0 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; V_71 ++ ) {
V_60 = F_168 ( V_2 , V_71 ,
V_2 -> V_8 -> V_365 ,
V_71 * V_2 -> V_8 -> V_365 ,
( V_71 + 1 ) *
V_2 -> V_8 -> V_365 ) ;
if ( V_60 )
return V_60 ;
V_350 |= ( 1 << V_71 ) ;
V_349 |= ( 1 << ( V_71 + V_357 ) ) ;
}
V_60 = F_168 ( V_2 , V_66 , V_366 ,
V_2 -> V_8 -> V_81 *
V_2 -> V_8 -> V_365 ,
V_360 ) ;
if ( V_60 )
return V_60 ;
V_350 |= ( 1 << V_66 ) ;
V_349 |= ( 1 << ( V_66 + V_357 ) ) ;
F_180 ( V_2 ) ;
F_28 ( V_2 , V_350 , V_364 ) ;
if ( V_348 )
V_349 |= V_353 ;
F_28 ( V_2 , V_349 , V_352 ) ;
return 0 ;
}
static int F_186 ( struct V_1 * V_2 )
{
int V_60 = 0 ;
int V_303 = 0 ;
T_2 V_72 ;
T_2 V_349 ;
int V_71 ;
V_72 = F_25 ( V_2 , V_352 ) ;
V_72 &= ~ V_353 ;
F_26 ( V_2 , V_72 , V_352 ) ;
while ( V_303 ++ < V_367 ) {
V_72 = F_25 ( V_2 , V_368 ) ;
if ( V_72 & V_369 )
break;
F_158 ( 1 ) ;
}
if ( V_303 == V_367 ) {
F_187 ( V_2 -> V_23 , L_18 ) ;
V_60 = - V_305 ;
}
F_156 ( 10000 , 20000 ) ;
V_72 = F_27 ( V_2 , V_352 ) ;
V_72 &= ~ V_353 ;
F_28 ( V_2 , V_72 , V_352 ) ;
V_303 = 0 ;
while ( V_303 ++ < V_367 ) {
V_72 = F_27 ( V_2 , V_368 ) ;
if ( V_72 & V_369 )
break;
F_158 ( 1 ) ;
}
if ( V_303 == V_367 ) {
F_187 ( V_2 -> V_23 , L_19 ) ;
V_60 = - V_305 ;
}
V_349 = 0 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_81 ; V_71 ++ )
V_349 |= ( 1 << ( V_71 + V_357 ) ) ;
V_72 = F_27 ( V_2 , V_352 ) ;
V_72 &= ~ V_349 ;
F_28 ( V_2 , V_72 , V_352 ) ;
V_349 = 0 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; V_71 ++ )
V_349 |= ( 1 << ( V_71 + V_357 ) ) ;
V_72 = F_25 ( V_2 , V_352 ) ;
V_72 &= ~ V_349 ;
F_26 ( V_2 , V_72 , V_352 ) ;
return V_60 ;
}
static void F_188 ( struct V_1 * V_2 )
{
struct V_207 * V_208 ;
struct V_174 * V_176 ;
struct V_160 * V_175 ;
int V_71 ;
F_184 ( V_2 ) ;
F_175 ( V_2 ) ;
F_186 ( V_2 ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_370 ; V_71 ++ ) {
V_175 = V_2 -> V_194 + V_71 ;
V_176 = F_92 ( & V_2 -> V_193 -> V_23 , V_175 ) ;
if ( V_176 )
F_119 ( V_176 ) ;
}
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_80 ; V_71 ++ ) {
V_208 = F_105 ( V_2 -> V_23 , V_2 -> V_211 [ V_71 ] . V_200 ) ;
F_189 ( V_208 ) ;
}
V_208 = F_105 ( V_2 -> V_23 , V_2 -> V_211 [ V_66 ] . V_200 ) ;
F_189 ( V_208 ) ;
F_154 ( V_2 ) ;
F_190 ( V_2 -> V_279 ) ;
F_190 ( V_2 -> V_194 ) ;
}
static int F_191 ( struct V_1 * V_2 )
{
int V_60 ;
unsigned int V_71 ;
struct V_160 * V_175 ;
F_101 ( V_2 , V_139 , V_2 -> V_23 , L_14 , V_192 ) ;
V_2 -> V_371 = V_2 -> V_17 + V_2 -> V_8 -> V_372 ;
V_2 -> V_301 = V_360 ;
V_2 -> V_279 = F_192 ( V_2 -> V_301 , sizeof( struct V_160 ) ,
V_373 ) ;
if ( ! V_2 -> V_279 )
return - V_300 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_301 ; V_71 ++ ) {
V_175 = V_2 -> V_279 + V_71 ;
V_175 -> V_254 = V_2 -> V_371 + V_71 * V_374 ;
}
V_2 -> V_375 = V_2 -> V_17 + V_2 -> V_8 -> V_376 ;
V_2 -> V_370 = V_360 ;
V_2 -> V_194 = F_192 ( V_2 -> V_370 , sizeof( struct V_160 ) ,
V_373 ) ;
if ( ! V_2 -> V_194 ) {
F_190 ( V_2 -> V_279 ) ;
return - V_300 ;
}
for ( V_71 = 0 ; V_71 < V_2 -> V_370 ; V_71 ++ ) {
V_175 = V_2 -> V_194 + V_71 ;
V_175 -> V_254 = V_2 -> V_375 + V_71 * V_374 ;
}
F_28 ( V_2 , V_377 , V_378 ) ;
V_60 = F_185 ( V_2 -> V_23 ) ;
if ( V_60 ) {
F_130 ( V_2 -> V_23 , L_20 ) ;
F_154 ( V_2 ) ;
F_190 ( V_2 -> V_279 ) ;
F_190 ( V_2 -> V_194 ) ;
return V_60 ;
}
F_26 ( V_2 , V_377 , V_378 ) ;
F_177 ( V_2 -> V_23 ) ;
return 0 ;
}
static void F_193 ( struct V_379 * V_380 )
{
unsigned long V_9 ;
unsigned int V_213 ;
struct V_1 * V_2 = F_110 (
V_380 , struct V_1 , V_381 ) ;
F_101 ( V_2 , V_382 , V_2 -> V_23 , L_14 , V_192 ) ;
F_107 ( & V_2 -> V_202 , V_9 ) ;
V_213 = V_2 -> V_383 ;
V_2 -> V_383 = 0 ;
F_108 ( & V_2 -> V_202 , V_9 ) ;
if ( V_213 & V_384 ) {
F_101 ( V_2 , V_385 , V_2 -> V_23 ,
L_21 ) ;
F_74 ( V_2 , V_143 ) ;
}
if ( V_213 & V_308 )
F_194 ( V_2 -> V_39 ,
! ! ( V_213 & V_386 ) ) ;
}
static T_9 F_195 ( int V_387 , void * V_388 )
{
struct V_1 * V_2 = V_388 ;
struct V_167 * V_389 ;
struct V_161 * V_390 ;
unsigned int V_172 , V_213 ;
V_213 = F_196 ( V_2 , V_391 ) &
~ F_196 ( V_2 , V_392 ) ;
F_86 ( V_2 , V_213 , V_188 ) ;
F_101 ( V_2 , V_382 , V_2 -> V_23 ,
L_22 , V_192 , V_213 ) ;
for ( V_172 = 0 ; V_172 < V_2 -> V_8 -> V_81 ; V_172 ++ ) {
if ( ! ( V_213 & F_164 ( V_171 + V_172 ) ) )
continue;
V_389 = & V_2 -> V_338 [ V_172 ] ;
if ( F_103 ( F_197 ( & V_389 -> V_204 ) ) ) {
V_389 -> V_329 ( V_389 ) ;
F_198 ( & V_389 -> V_204 ) ;
}
}
for ( V_172 = 0 ; V_172 < V_2 -> V_8 -> V_80 ; V_172 ++ ) {
if ( ! ( V_213 & F_164 ( V_172 ) ) )
continue;
V_390 = & V_2 -> V_211 [ V_172 ] ;
if ( F_103 ( F_197 ( & V_390 -> V_204 ) ) ) {
V_390 -> V_329 ( V_390 ) ;
F_198 ( & V_390 -> V_204 ) ;
}
}
return V_393 ;
}
static T_9 F_199 ( int V_387 , void * V_388 )
{
struct V_1 * V_2 = V_388 ;
struct V_167 * V_389 ;
struct V_161 * V_390 ;
unsigned int V_213 ;
unsigned long V_9 ;
V_213 = F_200 ( V_2 , V_391 ) &
~ F_200 ( V_2 , V_392 ) ;
F_83 ( V_2 , V_213 , V_188 ) ;
F_101 ( V_2 , V_382 , V_2 -> V_23 ,
L_23 , V_213 ) ;
if ( V_213 & V_168 ) {
V_389 = & V_2 -> V_338 [ V_66 ] ;
if ( F_103 ( F_197 ( & V_389 -> V_204 ) ) ) {
V_389 -> V_329 ( V_389 ) ;
F_198 ( & V_389 -> V_204 ) ;
}
}
if ( V_213 & V_173 ) {
V_390 = & V_2 -> V_211 [ V_66 ] ;
if ( F_103 ( F_197 ( & V_390 -> V_204 ) ) ) {
V_390 -> V_329 ( V_390 ) ;
F_198 ( & V_390 -> V_204 ) ;
}
}
if ( V_2 -> V_383 & ( V_394 |
V_395 |
V_308 |
V_396 |
V_397 ) ) {
F_201 ( & V_2 -> V_381 ) ;
}
if ( ( V_2 -> V_8 -> V_9 & V_323 ) &&
V_213 & ( V_324 | V_325 ) ) {
F_202 ( & V_2 -> V_398 ) ;
}
V_213 &= ( V_308 |
V_384 ) ;
if ( V_213 ) {
F_107 ( & V_2 -> V_202 , V_9 ) ;
V_2 -> V_383 |= V_213 ;
F_108 ( & V_2 -> V_202 , V_9 ) ;
F_201 ( & V_2 -> V_381 ) ;
}
return V_393 ;
}
static T_9 F_203 ( int V_387 , void * V_388 )
{
struct V_1 * V_2 = V_388 ;
F_204 ( & V_2 -> V_193 -> V_23 , 0 ) ;
return V_393 ;
}
static void F_205 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_206 ( V_2 -> V_399 ) ;
F_199 ( V_2 -> V_399 , V_2 ) ;
F_207 ( V_2 -> V_399 ) ;
F_206 ( V_2 -> V_400 ) ;
F_195 ( V_2 -> V_400 , V_2 ) ;
F_207 ( V_2 -> V_400 ) ;
}
static void F_208 ( struct V_1 * V_2 )
{
T_2 V_72 ;
V_72 = F_11 ( V_2 ) ;
V_72 |= F_164 ( 1 ) ;
F_15 ( V_2 , V_72 ) ;
F_158 ( 10 ) ;
V_72 &= ~ F_164 ( 1 ) ;
F_15 ( V_2 , V_72 ) ;
F_158 ( 10 ) ;
}
static void F_209 ( struct V_1 * V_2 ,
unsigned char * V_6 )
{
F_57 ( V_2 , ( V_6 [ 0 ] << 24 ) | ( V_6 [ 1 ] << 16 ) |
( V_6 [ 2 ] << 8 ) | V_6 [ 3 ] , V_401 ) ;
F_57 ( V_2 , ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] , V_402 ) ;
}
static T_2 F_210 ( struct V_1 * V_2 )
{
T_2 V_72 ;
T_2 V_349 ;
V_349 = 1 << ( V_66 + V_357 ) | V_353 ;
V_72 = F_25 ( V_2 , V_352 ) ;
V_72 &= ~ V_349 ;
F_26 ( V_2 , V_72 , V_352 ) ;
V_72 = F_27 ( V_2 , V_352 ) ;
V_72 &= ~ V_349 ;
F_28 ( V_2 , V_72 , V_352 ) ;
F_57 ( V_2 , 1 , V_403 ) ;
F_158 ( 10 ) ;
F_57 ( V_2 , 0 , V_403 ) ;
return V_349 ;
}
static void F_211 ( struct V_1 * V_2 , T_2 V_349 )
{
T_2 V_72 ;
V_72 = F_27 ( V_2 , V_352 ) ;
V_72 |= V_349 ;
F_28 ( V_2 , V_72 , V_352 ) ;
V_72 = F_25 ( V_2 , V_352 ) ;
V_72 |= V_349 ;
F_26 ( V_2 , V_72 , V_352 ) ;
}
static void F_212 ( struct V_1 * V_2 )
{
T_2 V_71 ;
F_213 ( V_2 , 0x0 , V_404 ) ;
F_213 ( V_2 , 0x0 , V_405 ) ;
F_213 ( V_2 , 0x0 , V_405 + 4 ) ;
for ( V_71 = V_406 ; V_71 <= V_407 ; V_71 ++ )
F_28 ( V_2 , 0x0 , V_71 ) ;
for ( V_71 = 0 ; V_71 < ( V_2 -> V_8 -> V_408 / 4 ) ; V_71 ++ )
F_213 ( V_2 , 0x0 ,
V_409 + V_71 * sizeof( T_2 ) ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_8 -> V_408 *
V_2 -> V_8 -> V_410 ; V_71 ++ )
F_214 ( V_2 , 0x0 , V_71 * sizeof( T_2 ) ) ;
}
static void F_215 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) || F_55 ( V_2 ) )
return;
F_212 ( V_2 ) ;
}
static void F_216 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_182 ( V_2 ) ;
F_171 ( V_2 ) ;
F_155 ( V_2 , V_411 | V_412 , true ) ;
F_217 ( V_23 ) ;
F_161 ( V_2 ) ;
F_218 ( V_2 -> V_39 ) ;
}
static int F_219 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned long V_349 ;
T_2 V_72 ;
int V_60 ;
F_101 ( V_2 , V_413 , V_23 , L_24 ) ;
F_34 ( V_2 -> V_35 ) ;
if ( V_2 -> V_307 )
F_74 ( V_2 , V_144 ) ;
F_208 ( V_2 ) ;
V_60 = F_162 ( V_2 ) ;
if ( V_60 )
goto V_414;
F_155 ( V_2 , V_411 | V_412 , false ) ;
V_72 = F_56 ( V_2 , V_302 ) ;
V_2 -> V_48 = ! ! ( V_72 & V_415 ) ;
F_209 ( V_2 , V_23 -> V_416 ) ;
if ( V_2 -> V_307 ) {
V_72 = F_70 ( V_2 , V_146 ) ;
V_72 |= V_417 ;
F_72 ( V_2 , V_72 , V_146 ) ;
}
V_349 = F_210 ( V_2 ) ;
V_60 = F_191 ( V_2 ) ;
if ( V_60 ) {
F_130 ( V_23 , L_25 ) ;
goto V_414;
}
F_211 ( V_2 , V_349 ) ;
F_215 ( V_2 ) ;
V_60 = F_220 ( V_2 -> V_399 , F_199 , V_418 ,
V_23 -> V_419 , V_2 ) ;
if ( V_60 < 0 ) {
F_130 ( V_23 , L_26 , V_2 -> V_399 ) ;
goto V_420;
}
V_60 = F_220 ( V_2 -> V_400 , F_195 , V_418 ,
V_23 -> V_419 , V_2 ) ;
if ( V_60 < 0 ) {
F_130 ( V_23 , L_26 , V_2 -> V_400 ) ;
goto V_421;
}
V_60 = F_221 ( V_23 ) ;
if ( V_60 ) {
F_130 ( V_23 , L_27 ) ;
goto V_422;
}
F_216 ( V_23 ) ;
return 0 ;
V_422:
F_222 ( V_2 -> V_400 , V_2 ) ;
V_421:
F_222 ( V_2 -> V_399 , V_2 ) ;
V_420:
F_188 ( V_2 ) ;
V_414:
if ( V_2 -> V_307 )
F_67 ( V_2 , V_144 ) ;
F_36 ( V_2 -> V_35 ) ;
return V_60 ;
}
static void F_223 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_224 ( V_23 ) ;
F_225 ( V_2 -> V_39 ) ;
F_160 ( V_2 ) ;
F_183 ( V_2 ) ;
F_173 ( V_2 ) ;
F_226 ( & V_2 -> V_381 ) ;
V_2 -> V_423 = - 1 ;
V_2 -> V_424 = - 1 ;
V_2 -> V_425 = - 1 ;
V_2 -> V_426 = - 1 ;
}
static int F_227 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_60 ;
F_101 ( V_2 , V_427 , V_23 , L_28 ) ;
F_223 ( V_23 ) ;
F_228 ( V_2 -> V_39 ) ;
F_155 ( V_2 , V_412 , false ) ;
V_60 = F_186 ( V_2 ) ;
if ( V_60 )
return V_60 ;
F_155 ( V_2 , V_411 , false ) ;
F_113 ( V_23 ) ;
F_188 ( V_2 ) ;
F_222 ( V_2 -> V_399 , V_2 ) ;
F_222 ( V_2 -> V_400 , V_2 ) ;
if ( V_2 -> V_307 )
V_60 = F_67 ( V_2 , V_144 ) ;
F_36 ( V_2 -> V_35 ) ;
return V_60 ;
}
static void F_229 ( struct V_161 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_2 V_269 , V_187 , V_428 , V_429 ;
struct V_207 * V_208 ;
unsigned int V_197 ;
unsigned long V_9 ;
bool V_430 ;
if ( ! F_230 ( V_2 ) )
return;
V_208 = F_105 ( V_2 -> V_23 , V_30 -> V_200 ) ;
F_107 ( & V_30 -> V_202 , V_9 ) ;
if ( V_30 -> V_172 == V_66 ) {
V_428 = ~ F_200 ( V_2 , V_392 ) ;
V_429 = V_173 | V_431 ;
} else {
V_428 = ~ F_196 ( V_2 , V_392 ) ;
V_429 = 1 << V_30 -> V_172 ;
}
V_187 = F_29 ( V_2 , V_30 -> V_172 , V_189 ) ;
V_269 = F_29 ( V_2 , V_30 -> V_172 , V_258 ) ;
V_430 = F_128 ( V_208 ) ;
V_197 = V_30 -> V_197 ;
F_108 ( & V_30 -> V_202 , V_9 ) ;
F_65 ( V_2 , V_245 , V_2 -> V_23 , L_29
L_30
L_31
L_32
L_33
L_34
L_35 ,
V_30 -> V_172 , V_30 -> V_200 ,
V_430 ? L_36 : L_37 ,
V_428 & V_429 ? L_38 : L_39 ,
V_197 , V_30 -> V_234 ,
V_30 -> V_255 , V_269 & V_256 ,
V_30 -> V_187 , V_187 & V_190 ,
V_30 -> V_195 , V_30 -> V_164 ,
V_30 -> V_165 , V_30 -> V_166 ) ;
}
static void F_231 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_306 = 0 ;
T_2 V_345 = 0 ;
unsigned int V_432 ;
F_101 ( V_2 , V_245 , V_23 , L_40 ) ;
for ( V_432 = 0 ; V_432 < V_2 -> V_8 -> V_80 ; V_432 ++ )
F_229 ( & V_2 -> V_211 [ V_432 ] ) ;
F_229 ( & V_2 -> V_211 [ V_66 ] ) ;
F_113 ( V_23 ) ;
for ( V_432 = 0 ; V_432 < V_2 -> V_8 -> V_80 ; V_432 ++ )
V_345 |= ( 1 << V_432 ) ;
V_306 = V_173 ;
F_83 ( V_2 , V_306 , V_170 ) ;
F_86 ( V_2 , V_345 , V_170 ) ;
F_232 ( V_23 ) ;
V_23 -> V_119 . V_433 ++ ;
F_233 ( V_23 ) ;
}
static inline void F_234 ( struct V_1 * V_2 ,
unsigned char * V_6 ,
int * V_71 ,
int * V_434 )
{
T_2 V_72 ;
F_57 ( V_2 , V_6 [ 0 ] << 8 | V_6 [ 1 ] ,
V_435 + ( * V_71 * 4 ) ) ;
F_57 ( V_2 , V_6 [ 2 ] << 24 | V_6 [ 3 ] << 16 |
V_6 [ 4 ] << 8 | V_6 [ 5 ] ,
V_435 + ( ( * V_71 + 1 ) * 4 ) ) ;
V_72 = F_56 ( V_2 , V_436 ) ;
V_72 |= ( 1 << ( V_437 - * V_434 ) ) ;
F_57 ( V_2 , V_72 , V_436 ) ;
* V_71 += 2 ;
( * V_434 ) ++ ;
}
static void F_235 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_438 * V_439 ;
int V_71 , V_434 ;
T_2 V_72 ;
F_101 ( V_2 , V_139 , V_23 , L_41 , V_192 , V_23 -> V_9 ) ;
V_72 = F_56 ( V_2 , V_302 ) ;
if ( V_23 -> V_9 & V_440 ) {
V_72 |= V_441 ;
F_57 ( V_2 , V_72 , V_302 ) ;
F_57 ( V_2 , 0 , V_436 ) ;
return;
} else {
V_72 &= ~ V_441 ;
F_57 ( V_2 , V_72 , V_302 ) ;
}
if ( V_23 -> V_9 & V_442 ) {
F_187 ( V_23 , L_42 ) ;
return;
}
V_71 = 0 ;
V_434 = 0 ;
F_234 ( V_2 , V_23 -> V_443 , & V_71 , & V_434 ) ;
F_234 ( V_2 , V_23 -> V_416 , & V_71 , & V_434 ) ;
if ( F_236 ( V_23 ) > ( V_437 - V_434 ) )
return;
if ( ! F_237 ( V_23 ) )
F_238 (ha, dev)
F_234 ( V_2 , V_439 -> V_6 , & V_71 , & V_434 ) ;
if ( F_239 ( V_23 ) || F_240 ( V_23 ) >= ( V_437 - V_434 ) )
return;
F_241 (ha, dev)
F_234 ( V_2 , V_439 -> V_6 , & V_71 , & V_434 ) ;
}
static int F_242 ( struct V_34 * V_23 , void * V_106 )
{
struct V_444 * V_6 = V_106 ;
if ( F_38 ( V_23 ) )
return - V_445 ;
F_243 ( V_23 -> V_416 , V_6 -> V_446 ) ;
return 0 ;
}
static struct V_447 * F_244 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned long V_448 = 0 , V_449 = 0 ;
unsigned long V_450 = 0 , V_451 = 0 ;
unsigned long V_293 = 0 , V_452 = 0 ;
struct V_161 * V_390 ;
struct V_167 * V_389 ;
unsigned int V_432 ;
for ( V_432 = 0 ; V_432 < V_2 -> V_8 -> V_80 ; V_432 ++ ) {
V_390 = & V_2 -> V_211 [ V_432 ] ;
V_448 += V_390 -> V_199 ;
V_449 += V_390 -> V_198 ;
}
V_390 = & V_2 -> V_211 [ V_66 ] ;
V_448 += V_390 -> V_199 ;
V_449 += V_390 -> V_198 ;
for ( V_432 = 0 ; V_432 < V_2 -> V_8 -> V_81 ; V_432 ++ ) {
V_389 = & V_2 -> V_338 [ V_432 ] ;
V_450 += V_389 -> V_199 ;
V_451 += V_389 -> V_198 ;
V_293 += V_389 -> V_277 ;
V_452 += V_389 -> V_281 ;
}
V_389 = & V_2 -> V_338 [ V_66 ] ;
V_450 += V_389 -> V_199 ;
V_451 += V_389 -> V_198 ;
V_293 += V_389 -> V_277 ;
V_452 += V_389 -> V_281 ;
V_23 -> V_119 . V_448 = V_448 ;
V_23 -> V_119 . V_449 = V_449 ;
V_23 -> V_119 . V_450 = V_450 ;
V_23 -> V_119 . V_451 = V_451 ;
V_23 -> V_119 . V_293 = V_293 ;
V_23 -> V_119 . V_453 = V_293 ;
return & V_23 -> V_119 ;
}
static void F_245 ( struct V_1 * V_2 )
{
struct V_454 * V_455 ;
T_2 V_72 ;
T_5 V_456 ;
T_6 V_457 ;
if ( F_71 ( V_2 ) || F_246 ( V_2 ) ) {
V_28 = V_458 ;
V_33 = V_459 ;
V_2 -> V_294 = V_460 ;
} else if ( F_247 ( V_2 ) ) {
V_28 = V_458 ;
V_33 = V_461 ;
V_2 -> V_294 = V_460 ;
} else if ( F_55 ( V_2 ) ) {
V_28 = V_462 ;
V_33 = V_461 ;
V_2 -> V_294 = V_463 ;
} else if ( F_12 ( V_2 ) ) {
V_28 = V_464 ;
V_33 = V_461 ;
V_2 -> V_294 = V_463 ;
}
V_2 -> V_8 = & V_454 [ V_2 -> V_86 ] ;
V_455 = V_2 -> V_8 ;
V_72 = F_14 ( V_2 , V_465 ) ;
V_456 = ( V_72 >> 24 & 0x0f ) ;
if ( V_456 == 6 )
V_456 = 5 ;
else if ( V_456 == 5 )
V_456 = 4 ;
else if ( V_456 == 0 )
V_456 = 1 ;
if ( V_456 != V_2 -> V_86 ) {
F_159 ( & V_2 -> V_193 -> V_23 ,
L_43 ,
V_456 , V_2 -> V_86 ) ;
}
F_248 ( & V_2 -> V_193 -> V_23 , L_44 V_466 ,
V_456 , ( V_72 >> 16 ) & 0x0f , V_72 & 0xffff ) ;
V_457 = V_72 & 0xffff ;
if ( F_71 ( V_2 ) ) {
if ( V_457 != 0 ) {
F_249 ( L_45 ,
V_457 ) ;
}
} else if ( V_457 == 0 || V_457 == 0x01ff ) {
F_249 ( L_46 , V_457 ) ;
return;
} else if ( ( V_457 & 0xf0 ) != 0 ) {
V_2 -> V_457 = V_457 << 8 ;
} else if ( ( V_457 & 0xff00 ) != 0 ) {
V_2 -> V_457 = V_457 ;
}
#ifdef F_7
if ( ! ( V_455 -> V_9 & V_10 ) )
F_249 ( L_47 ) ;
#endif
F_250 ( L_48
L_49
L_50
L_51
L_52
L_53
L_54 ,
V_2 -> V_86 ,
V_455 -> V_80 , V_455 -> V_356 ,
V_455 -> V_81 , V_455 -> V_365 ,
V_455 -> V_321 , V_455 -> V_322 ,
V_455 -> V_408 , V_455 -> V_248 ,
V_455 -> V_18 , V_455 -> V_467 ,
V_455 -> V_468 ,
V_455 -> V_372 , V_455 -> V_376 ,
V_455 -> V_327 ) ;
}
static int F_251 ( struct V_469 * V_193 )
{
struct V_470 * V_471 = V_193 -> V_23 . V_472 ;
struct V_473 * V_474 = V_193 -> V_23 . V_475 ;
const struct V_476 * V_477 = NULL ;
struct V_1 * V_2 ;
struct V_34 * V_23 ;
const void * V_478 ;
struct V_479 * V_25 ;
int V_480 = - V_481 ;
const char * V_482 ;
V_23 = F_252 ( sizeof( * V_2 ) , V_483 + 1 ,
V_483 + 1 ) ;
if ( ! V_23 ) {
F_159 ( & V_193 -> V_23 , L_55 ) ;
return - V_300 ;
}
if ( V_474 ) {
V_477 = F_253 ( V_484 , V_474 ) ;
if ( ! V_477 )
return - V_38 ;
}
V_2 = F_23 ( V_23 ) ;
V_2 -> V_399 = F_254 ( V_193 , 0 ) ;
V_2 -> V_400 = F_254 ( V_193 , 1 ) ;
V_2 -> V_485 = F_254 ( V_193 , 2 ) ;
if ( ! V_2 -> V_399 || ! V_2 -> V_400 ) {
F_159 ( & V_193 -> V_23 , L_56 ) ;
V_480 = - V_38 ;
goto V_480;
}
if ( V_474 ) {
V_478 = F_255 ( V_474 ) ;
if ( ! V_478 ) {
F_159 ( & V_193 -> V_23 , L_57 ) ;
V_480 = - V_38 ;
goto V_480;
}
} else {
V_478 = V_471 -> V_486 ;
}
V_25 = F_256 ( V_193 , V_487 , 0 ) ;
V_2 -> V_17 = F_257 ( & V_193 -> V_23 , V_25 ) ;
if ( F_258 ( V_2 -> V_17 ) ) {
V_480 = F_259 ( V_2 -> V_17 ) ;
goto V_480;
}
F_167 ( & V_2 -> V_202 ) ;
F_260 ( V_23 , & V_193 -> V_23 ) ;
F_261 ( & V_193 -> V_23 , V_23 ) ;
F_243 ( V_23 -> V_416 , V_478 ) ;
V_23 -> V_488 = 2 * V_489 ;
V_23 -> V_490 = & V_491 ;
V_23 -> V_492 = & V_493 ;
V_2 -> V_61 = F_262 ( - 1 , V_494 ) ;
V_23 -> V_495 |= V_496 | V_54 |
V_55 | V_44 ;
V_2 -> V_497 = true ;
V_480 = F_263 ( & V_193 -> V_23 , V_2 -> V_485 , F_203 , 0 ,
V_23 -> V_419 , V_2 ) ;
if ( ! V_480 )
F_264 ( & V_193 -> V_23 , 1 ) ;
V_23 -> V_498 += 64 ;
F_265 ( V_23 ) ;
V_2 -> V_23 = V_23 ;
V_2 -> V_193 = V_193 ;
if ( V_477 )
V_2 -> V_86 = (enum V_499 ) V_477 -> V_91 ;
else
V_2 -> V_86 = V_471 -> V_500 ;
V_2 -> V_35 = F_266 ( & V_2 -> V_193 -> V_23 , L_58 ) ;
if ( F_258 ( V_2 -> V_35 ) ) {
F_267 ( & V_2 -> V_193 -> V_23 , L_59 ) ;
V_2 -> V_35 = NULL ;
}
F_34 ( V_2 -> V_35 ) ;
F_245 ( V_2 ) ;
F_268 ( & V_2 -> V_398 ) ;
V_2 -> V_260 = V_332 ;
F_269 ( & V_2 -> V_381 , F_193 ) ;
V_2 -> V_501 = F_266 ( & V_2 -> V_193 -> V_23 , L_60 ) ;
if ( F_258 ( V_2 -> V_501 ) ) {
F_267 ( & V_2 -> V_193 -> V_23 , L_61 ) ;
V_2 -> V_501 = NULL ;
}
V_2 -> V_124 = F_266 ( & V_2 -> V_193 -> V_23 , L_62 ) ;
if ( F_258 ( V_2 -> V_124 ) ) {
F_267 ( & V_2 -> V_193 -> V_23 , L_63 ) ;
V_2 -> V_124 = NULL ;
}
if ( V_474 && ! F_270 ( V_474 , L_64 , & V_482 ) &&
! strcasecmp ( V_482 , L_65 ) )
F_74 ( V_2 , V_144 ) ;
V_480 = F_157 ( V_2 ) ;
if ( V_480 )
goto V_414;
V_480 = F_271 ( V_23 ) ;
if ( V_480 )
goto V_414;
F_272 ( V_2 -> V_23 , V_2 -> V_8 -> V_80 + 1 ) ;
F_273 ( V_2 -> V_23 , V_2 -> V_8 -> V_81 + 1 ) ;
F_274 ( V_23 ) ;
F_36 ( V_2 -> V_35 ) ;
V_480 = F_275 ( V_23 ) ;
if ( V_480 )
goto V_480;
return V_480 ;
V_414:
F_36 ( V_2 -> V_35 ) ;
V_480:
F_276 ( V_23 ) ;
return V_480 ;
}
static int F_277 ( struct V_469 * V_193 )
{
struct V_1 * V_2 = F_22 ( & V_193 -> V_23 ) ;
F_261 ( & V_193 -> V_23 , NULL ) ;
F_278 ( V_2 -> V_23 ) ;
F_279 ( V_2 -> V_23 ) ;
F_276 ( V_2 -> V_23 ) ;
return 0 ;
}
static int F_280 ( struct V_22 * V_3 )
{
struct V_34 * V_23 = F_24 ( V_3 ) ;
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_60 ;
if ( ! F_38 ( V_23 ) )
return 0 ;
F_223 ( V_23 ) ;
if ( ! F_281 ( V_3 ) )
F_282 ( V_2 -> V_39 ) ;
F_283 ( V_23 ) ;
F_155 ( V_2 , V_412 , false ) ;
V_60 = F_186 ( V_2 ) ;
if ( V_60 )
return V_60 ;
F_155 ( V_2 , V_411 , false ) ;
F_113 ( V_23 ) ;
F_188 ( V_2 ) ;
if ( F_281 ( V_3 ) && V_2 -> V_502 ) {
V_60 = F_67 ( V_2 , V_143 ) ;
F_34 ( V_2 -> V_501 ) ;
} else if ( V_2 -> V_307 ) {
V_60 = F_67 ( V_2 , V_144 ) ;
}
F_36 ( V_2 -> V_35 ) ;
return V_60 ;
}
static int F_284 ( struct V_22 * V_3 )
{
struct V_34 * V_23 = F_24 ( V_3 ) ;
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned long V_349 ;
int V_60 ;
T_2 V_72 ;
if ( ! F_38 ( V_23 ) )
return 0 ;
V_60 = F_34 ( V_2 -> V_35 ) ;
if ( V_60 )
return V_60 ;
if ( V_2 -> V_307 )
F_74 ( V_2 , V_144 ) ;
F_208 ( V_2 ) ;
V_60 = F_162 ( V_2 ) ;
if ( V_60 )
goto V_503;
if ( V_2 -> V_502 )
F_36 ( V_2 -> V_501 ) ;
F_285 ( V_2 -> V_39 ) ;
F_286 ( V_2 -> V_23 , false ) ;
F_155 ( V_2 , V_411 | V_412 , false ) ;
F_209 ( V_2 , V_23 -> V_416 ) ;
if ( V_2 -> V_307 ) {
V_72 = F_70 ( V_2 , V_146 ) ;
V_72 |= V_417 ;
F_72 ( V_2 , V_72 , V_146 ) ;
}
if ( V_2 -> V_502 )
F_74 ( V_2 , V_143 ) ;
V_349 = F_210 ( V_2 ) ;
V_60 = F_191 ( V_2 ) ;
if ( V_60 ) {
F_130 ( V_23 , L_25 ) ;
goto V_503;
}
F_211 ( V_2 , V_349 ) ;
F_287 ( V_23 ) ;
if ( ! F_281 ( V_3 ) )
F_288 ( V_2 -> V_39 ) ;
if ( V_2 -> V_132 . V_133 )
F_60 ( V_23 , true ) ;
F_216 ( V_23 ) ;
return 0 ;
V_503:
if ( V_2 -> V_307 )
F_67 ( V_2 , V_144 ) ;
F_36 ( V_2 -> V_35 ) ;
return V_60 ;
}
