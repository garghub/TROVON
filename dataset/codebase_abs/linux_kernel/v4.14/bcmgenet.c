static inline void F_1 ( T_1 V_1 , void T_2 * V_2 )
{
if ( F_2 ( V_3 ) && F_2 ( V_4 ) )
F_3 ( V_1 , V_2 ) ;
else
F_4 ( V_1 , V_2 ) ;
}
static inline T_1 F_5 ( void T_2 * V_2 )
{
if ( F_2 ( V_3 ) && F_2 ( V_4 ) )
return F_6 ( V_2 ) ;
else
return F_7 ( V_2 ) ;
}
static inline void F_8 ( struct V_5 * V_6 ,
void T_2 * V_7 , T_1 V_1 )
{
F_1 ( V_1 , V_7 + V_8 ) ;
}
static inline T_1 F_9 ( struct V_5 * V_6 ,
void T_2 * V_7 )
{
return F_5 ( V_7 + V_8 ) ;
}
static inline void F_10 ( struct V_5 * V_6 ,
void T_2 * V_7 ,
T_3 V_9 )
{
F_1 ( F_11 ( V_9 ) , V_7 + V_10 ) ;
#ifdef F_12
if ( V_6 -> V_11 -> V_12 & V_13 )
F_1 ( F_13 ( V_9 ) , V_7 + V_14 ) ;
#endif
}
static inline void F_14 ( struct V_5 * V_6 ,
void T_2 * V_7 , T_3 V_9 , T_1 V_15 )
{
F_10 ( V_6 , V_7 , V_9 ) ;
F_8 ( V_6 , V_7 , V_15 ) ;
}
static inline T_3 F_15 ( struct V_5 * V_6 ,
void T_2 * V_7 )
{
T_3 V_9 ;
V_9 = F_5 ( V_7 + V_10 ) ;
#ifdef F_12
if ( V_6 -> V_11 -> V_12 & V_13 )
V_9 |= ( V_16 ) F_5 ( V_7 + V_14 ) << 32 ;
#endif
return V_9 ;
}
static inline T_1 F_16 ( struct V_5 * V_6 )
{
if ( F_17 ( V_6 ) )
return F_18 ( V_6 , V_17 ) ;
else
return F_19 ( V_6 , V_18 ) ;
}
static inline void F_20 ( struct V_5 * V_6 , T_1 V_15 )
{
if ( F_17 ( V_6 ) )
F_21 ( V_6 , V_15 , V_17 ) ;
else
F_22 ( V_6 , V_15 , V_18 ) ;
}
static inline T_1 F_23 ( struct V_5 * V_6 )
{
if ( F_17 ( V_6 ) )
return F_18 ( V_6 , V_19 ) ;
else
return F_5 ( V_6 -> V_20 +
V_6 -> V_11 -> V_21 + V_22 ) ;
}
static inline void F_24 ( struct V_5 * V_6 , T_1 V_15 )
{
if ( F_17 ( V_6 ) )
F_21 ( V_6 , V_15 , V_19 ) ;
else
F_1 ( V_15 , V_6 -> V_20 +
V_6 -> V_11 -> V_21 + V_22 ) ;
}
static inline T_1 F_25 ( struct V_5 * V_6 )
{
if ( F_17 ( V_6 ) )
return F_18 ( V_6 , V_23 ) ;
else
return F_5 ( V_6 -> V_20 +
V_6 -> V_11 -> V_21 + V_24 ) ;
}
static inline void F_26 ( struct V_5 * V_6 , T_1 V_15 )
{
if ( F_17 ( V_6 ) )
F_21 ( V_6 , V_15 , V_23 ) ;
else
F_1 ( V_15 , V_6 -> V_20 +
V_6 -> V_11 -> V_21 + V_24 ) ;
}
static inline struct V_5 * F_27 ( struct V_25 * V_26 )
{
return F_28 ( F_29 ( V_26 ) ) ;
}
static inline T_1 F_30 ( struct V_5 * V_6 ,
enum V_27 V_28 )
{
return F_5 ( V_6 -> V_20 + V_29 +
V_30 + V_31 [ V_28 ] ) ;
}
static inline void F_31 ( struct V_5 * V_6 ,
T_1 V_15 , enum V_27 V_28 )
{
F_1 ( V_15 , V_6 -> V_20 + V_29 +
V_30 + V_31 [ V_28 ] ) ;
}
static inline T_1 F_32 ( struct V_5 * V_6 ,
enum V_27 V_28 )
{
return F_5 ( V_6 -> V_20 + V_32 +
V_30 + V_31 [ V_28 ] ) ;
}
static inline void F_33 ( struct V_5 * V_6 ,
T_1 V_15 , enum V_27 V_28 )
{
F_1 ( V_15 , V_6 -> V_20 + V_32 +
V_30 + V_31 [ V_28 ] ) ;
}
static inline T_1 F_34 ( struct V_5 * V_6 ,
unsigned int V_33 ,
enum V_34 V_28 )
{
return F_5 ( V_6 -> V_20 + V_29 +
( V_35 * V_33 ) +
V_36 [ V_28 ] ) ;
}
static inline void F_35 ( struct V_5 * V_6 ,
unsigned int V_33 , T_1 V_15 ,
enum V_34 V_28 )
{
F_1 ( V_15 , V_6 -> V_20 + V_29 +
( V_35 * V_33 ) +
V_36 [ V_28 ] ) ;
}
static inline T_1 F_36 ( struct V_5 * V_6 ,
unsigned int V_33 ,
enum V_34 V_28 )
{
return F_5 ( V_6 -> V_20 + V_32 +
( V_35 * V_33 ) +
V_36 [ V_28 ] ) ;
}
static inline void F_37 ( struct V_5 * V_6 ,
unsigned int V_33 , T_1 V_15 ,
enum V_34 V_28 )
{
F_1 ( V_15 , V_6 -> V_20 + V_32 +
( V_35 * V_33 ) +
V_36 [ V_28 ] ) ;
}
static int F_38 ( struct V_37 * V_26 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
return F_39 ( V_6 -> V_38 ) ;
}
static void F_40 ( struct V_37 * V_26 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
F_41 ( V_6 -> V_38 ) ;
}
static int F_42 ( struct V_37 * V_26 ,
struct V_39 * V_40 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
if ( ! F_43 ( V_26 ) )
return - V_41 ;
if ( ! V_6 -> V_42 )
return - V_43 ;
F_44 ( V_6 -> V_42 , V_40 ) ;
return 0 ;
}
static int F_45 ( struct V_37 * V_26 ,
const struct V_39 * V_40 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
if ( ! F_43 ( V_26 ) )
return - V_41 ;
if ( ! V_6 -> V_42 )
return - V_43 ;
return F_46 ( V_6 -> V_42 , V_40 ) ;
}
static int F_47 ( struct V_37 * V_26 ,
T_4 V_44 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
T_1 V_45 ;
bool V_46 ;
V_46 = ! ! ( V_44 & V_47 ) ;
V_45 = F_18 ( V_6 , V_48 ) ;
if ( V_46 )
V_45 |= V_49 ;
else
V_45 &= ~ V_49 ;
V_6 -> V_50 = V_46 ;
if ( V_46 && V_6 -> V_51 )
V_45 |= V_52 ;
else
V_45 &= ~ V_52 ;
F_21 ( V_6 , V_45 , V_48 ) ;
return 0 ;
}
static int F_48 ( struct V_37 * V_26 ,
T_4 V_44 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
bool V_53 ;
T_1 V_54 , V_55 ;
V_54 = F_23 ( V_6 ) ;
V_55 = F_18 ( V_6 , V_56 ) ;
V_53 = ! ! ( V_44 & ( V_57 | V_58 ) ) ;
if ( V_53 ) {
V_54 |= V_59 ;
V_55 |= V_59 ;
} else {
V_54 &= ~ V_59 ;
V_55 &= ~ V_59 ;
}
V_6 -> V_53 = V_53 ;
F_24 ( V_6 , V_54 ) ;
F_21 ( V_6 , V_55 , V_56 ) ;
return 0 ;
}
static int F_49 ( struct V_37 * V_26 ,
T_4 V_60 )
{
T_4 V_61 = V_60 ^ V_26 -> V_60 ;
T_4 V_44 = V_26 -> V_62 ;
int V_63 = 0 ;
if ( V_61 & ( V_57 | V_58 ) )
V_63 = F_48 ( V_26 , V_44 ) ;
if ( V_61 & ( V_47 ) )
V_63 = F_47 ( V_26 , V_44 ) ;
return V_63 ;
}
static T_1 F_50 ( struct V_37 * V_26 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
return V_6 -> V_64 ;
}
static void F_51 ( struct V_37 * V_26 , T_1 V_65 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
V_6 -> V_64 = V_65 ;
}
static int F_52 ( struct V_37 * V_26 ,
struct V_66 * V_67 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
V_67 -> V_68 =
F_34 ( V_6 , V_69 ,
V_70 ) ;
V_67 -> V_71 =
F_36 ( V_6 , V_69 ,
V_70 ) ;
V_67 -> V_72 =
F_32 ( V_6 , V_73 ) * 8192 / 1000 ;
return 0 ;
}
static int F_53 ( struct V_37 * V_26 ,
struct V_66 * V_67 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
unsigned int V_74 ;
T_1 V_75 ;
if ( V_67 -> V_68 > V_76 ||
V_67 -> V_68 == 0 ||
V_67 -> V_71 > V_76 ||
V_67 -> V_72 > ( V_77 * 8 ) + 1 )
return - V_41 ;
if ( V_67 -> V_72 == 0 && V_67 -> V_71 == 0 )
return - V_41 ;
if ( V_67 -> V_78 || V_67 -> V_79 ||
V_67 -> V_80 || V_67 -> V_81 )
return - V_82 ;
for ( V_74 = 0 ; V_74 < V_6 -> V_11 -> V_83 ; V_74 ++ )
F_35 ( V_6 , V_74 ,
V_67 -> V_68 ,
V_70 ) ;
F_35 ( V_6 , V_69 ,
V_67 -> V_68 ,
V_70 ) ;
for ( V_74 = 0 ; V_74 < V_6 -> V_11 -> V_84 ; V_74 ++ ) {
F_37 ( V_6 , V_74 ,
V_67 -> V_71 ,
V_70 ) ;
V_75 = F_32 ( V_6 , V_85 + V_74 ) ;
V_75 &= ~ V_77 ;
V_75 |= F_54 ( V_67 -> V_72 * 1000 , 8192 ) ;
F_33 ( V_6 , V_75 , V_85 + V_74 ) ;
}
F_37 ( V_6 , V_69 ,
V_67 -> V_71 ,
V_70 ) ;
V_75 = F_32 ( V_6 , V_73 ) ;
V_75 &= ~ V_77 ;
V_75 |= F_54 ( V_67 -> V_72 * 1000 , 8192 ) ;
F_33 ( V_6 , V_75 , V_73 ) ;
return 0 ;
}
static void F_55 ( struct V_37 * V_26 ,
struct V_86 * V_87 )
{
F_56 ( V_87 -> V_88 , L_1 , sizeof( V_87 -> V_88 ) ) ;
F_56 ( V_87 -> V_89 , L_2 , sizeof( V_87 -> V_89 ) ) ;
}
static int F_57 ( struct V_37 * V_26 , int V_90 )
{
switch ( V_90 ) {
case V_91 :
return V_92 ;
default:
return - V_82 ;
}
}
static void F_58 ( struct V_37 * V_26 , T_1 V_93 ,
T_5 * V_94 )
{
int V_74 ;
switch ( V_93 ) {
case V_91 :
for ( V_74 = 0 ; V_74 < V_92 ; V_74 ++ ) {
memcpy ( V_94 + V_74 * V_95 ,
V_96 [ V_74 ] . V_97 ,
V_95 ) ;
}
break;
}
}
static T_1 F_59 ( struct V_5 * V_6 , T_6 V_2 )
{
T_6 V_98 ;
T_1 V_15 ;
switch ( V_2 ) {
case V_99 :
if ( F_60 ( V_6 ) )
V_98 = V_100 ;
else
V_98 = V_101 ;
V_15 = F_18 ( V_6 , V_98 ) ;
if ( V_15 == ~ 0 )
F_21 ( V_6 , 0 , V_98 ) ;
break;
case V_102 :
if ( F_60 ( V_6 ) )
V_98 = V_103 ;
else
V_98 = V_104 ;
V_15 = F_18 ( V_6 , V_98 ) ;
if ( V_15 == ~ 0 )
F_21 ( V_6 , 0 , V_98 ) ;
break;
default:
V_15 = F_61 ( V_6 , V_2 ) ;
if ( V_15 == ~ 0 )
F_62 ( V_6 , 0 , V_2 ) ;
break;
}
return V_15 ;
}
static void F_63 ( struct V_5 * V_6 )
{
int V_74 , V_105 = 0 ;
for ( V_74 = 0 ; V_74 < V_92 ; V_74 ++ ) {
const struct V_106 * V_107 ;
T_5 V_2 = 0 ;
T_1 V_15 = 0 ;
char * V_108 ;
V_107 = & V_96 [ V_74 ] ;
switch ( V_107 -> type ) {
case V_109 :
case V_110 :
continue;
case V_111 :
V_2 += V_112 ;
case V_113 :
V_2 += V_112 ;
case V_114 :
V_15 = F_61 ( V_6 ,
V_115 + V_105 + V_2 ) ;
V_2 = 0 ;
break;
case V_116 :
if ( F_17 ( V_6 ) ) {
V_15 = F_61 ( V_6 , V_107 -> V_117 ) ;
if ( V_15 == ~ 0 )
F_62 ( V_6 , 0 ,
V_107 -> V_117 ) ;
} else {
V_15 = F_59 ( V_6 ,
V_107 -> V_117 ) ;
}
break;
}
V_105 += V_107 -> V_118 ;
V_108 = ( char * ) V_6 + V_107 -> V_119 ;
* ( T_1 * ) V_108 = V_15 ;
}
}
static void F_64 ( struct V_37 * V_26 ,
struct V_120 * V_121 ,
V_16 * V_94 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
int V_74 ;
if ( F_43 ( V_26 ) )
F_63 ( V_6 ) ;
for ( V_74 = 0 ; V_74 < V_92 ; V_74 ++ ) {
const struct V_106 * V_107 ;
char * V_108 ;
V_107 = & V_96 [ V_74 ] ;
if ( V_107 -> type == V_109 )
V_108 = ( char * ) & V_26 -> V_121 ;
else
V_108 = ( char * ) V_6 ;
V_108 += V_107 -> V_119 ;
if (sizeof( unsigned long ) != sizeof( T_1 ) &&
V_107 -> V_118 == sizeof( unsigned long ) )
V_94 [ V_74 ] = * ( unsigned long * ) V_108 ;
else
V_94 [ V_74 ] = * ( T_1 * ) V_108 ;
}
}
static void F_65 ( struct V_37 * V_26 , bool V_122 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
T_1 V_123 = V_6 -> V_11 -> V_21 + V_124 ;
T_1 V_75 ;
if ( V_122 && ! V_6 -> V_125 ) {
F_39 ( V_6 -> V_126 ) ;
V_6 -> V_125 = true ;
}
V_75 = F_61 ( V_6 , V_127 ) ;
if ( V_122 )
V_75 |= V_128 ;
else
V_75 &= ~ V_128 ;
F_62 ( V_6 , V_75 , V_127 ) ;
V_75 = F_5 ( V_6 -> V_20 + V_123 ) ;
if ( V_122 )
V_75 |= V_129 | V_130 ;
else
V_75 &= ~ ( V_129 | V_130 ) ;
F_1 ( V_75 , V_6 -> V_20 + V_123 ) ;
V_75 = F_18 ( V_6 , V_131 ) ;
if ( V_122 )
V_75 |= V_132 | V_133 ;
else
V_75 &= ~ ( V_132 | V_133 ) ;
F_21 ( V_6 , V_75 , V_131 ) ;
if ( ! V_122 && V_6 -> V_125 ) {
F_41 ( V_6 -> V_126 ) ;
V_6 -> V_125 = false ;
}
V_6 -> V_134 . V_135 = V_122 ;
V_6 -> V_134 . V_136 = V_122 ;
}
static int F_66 ( struct V_37 * V_26 , struct V_137 * V_138 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
struct V_137 * V_108 = & V_6 -> V_134 ;
if ( F_17 ( V_6 ) )
return - V_82 ;
V_138 -> V_135 = V_108 -> V_135 ;
V_138 -> V_136 = V_108 -> V_136 ;
V_138 -> V_139 = F_61 ( V_6 , V_140 ) ;
return F_67 ( V_6 -> V_42 , V_138 ) ;
}
static int F_68 ( struct V_37 * V_26 , struct V_137 * V_138 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
struct V_137 * V_108 = & V_6 -> V_134 ;
int V_63 = 0 ;
if ( F_17 ( V_6 ) )
return - V_82 ;
V_108 -> V_135 = V_138 -> V_135 ;
if ( ! V_108 -> V_135 ) {
F_65 ( V_26 , false ) ;
} else {
V_63 = F_69 ( V_6 -> V_42 , 0 ) ;
if ( V_63 ) {
F_70 ( V_6 , V_141 , V_26 , L_3 ) ;
return V_63 ;
}
F_62 ( V_6 , V_138 -> V_139 , V_140 ) ;
F_65 ( V_26 , true ) ;
}
return F_71 ( V_6 -> V_42 , V_138 ) ;
}
static int F_72 ( struct V_5 * V_6 ,
enum V_142 V_143 )
{
int V_63 = 0 ;
T_1 V_75 ;
switch ( V_143 ) {
case V_144 :
F_73 ( V_6 -> V_42 ) ;
break;
case V_145 :
V_63 = F_74 ( V_6 , V_143 ) ;
break;
case V_146 :
if ( V_6 -> V_11 -> V_12 & V_147 ) {
V_75 = F_75 ( V_6 , V_148 ) ;
if ( F_76 ( V_6 ) )
V_75 |= V_149 |
V_150 |
V_151 |
V_152 |
V_153 |
V_154 ;
else
V_75 |= V_155 ;
V_75 |= ( V_156 | V_157 ) ;
F_77 ( V_6 , V_75 , V_148 ) ;
F_78 ( V_6 -> V_26 , false ) ;
}
break;
default:
break;
}
return 0 ;
}
static void F_79 ( struct V_5 * V_6 ,
enum V_142 V_143 )
{
T_1 V_75 ;
if ( ! ( V_6 -> V_11 -> V_12 & V_147 ) )
return;
V_75 = F_75 ( V_6 , V_148 ) ;
switch ( V_143 ) {
case V_146 :
V_75 &= ~ ( V_156 | V_157 ) ;
if ( F_76 ( V_6 ) ) {
V_75 &= ~ ( V_149 |
V_150 |
V_151 |
V_152 |
V_153 |
V_154 ) ;
V_75 |= V_158 ;
F_77 ( V_6 , V_75 , V_148 ) ;
F_80 ( 1 ) ;
V_75 &= ~ V_158 ;
} else {
V_75 &= ~ V_155 ;
V_75 |= V_159 ;
}
F_77 ( V_6 , V_75 , V_148 ) ;
F_78 ( V_6 -> V_26 , true ) ;
F_81 ( V_6 -> V_26 ) ;
break;
case V_144 :
if ( ! F_76 ( V_6 ) ) {
V_75 |= V_159 ;
F_77 ( V_6 , V_75 , V_148 ) ;
}
break;
case V_145 :
F_82 ( V_6 , V_143 ) ;
return;
default:
break;
}
}
static int F_83 ( struct V_37 * V_26 , struct V_160 * V_161 , int V_40 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
if ( ! F_43 ( V_26 ) )
return - V_41 ;
if ( ! V_6 -> V_42 )
return - V_43 ;
return F_84 ( V_6 -> V_42 , V_161 , V_40 ) ;
}
static struct V_162 * F_85 ( struct V_5 * V_6 ,
struct V_163 * V_33 )
{
struct V_162 * V_164 ;
V_164 = V_33 -> V_165 ;
V_164 += V_33 -> V_166 - V_33 -> V_167 ;
if ( V_33 -> V_166 == V_33 -> V_168 )
V_33 -> V_166 = V_33 -> V_167 ;
else
V_33 -> V_166 ++ ;
return V_164 ;
}
static struct V_162 * F_86 ( struct V_5 * V_6 ,
struct V_163 * V_33 )
{
struct V_162 * V_164 ;
V_164 = V_33 -> V_165 ;
V_164 += V_33 -> V_166 - V_33 -> V_167 ;
if ( V_33 -> V_166 == V_33 -> V_167 )
V_33 -> V_166 = V_33 -> V_168 ;
else
V_33 -> V_166 -- ;
return V_164 ;
}
static inline void F_87 ( struct V_169 * V_33 )
{
F_88 ( V_33 -> V_6 , V_170 ,
V_171 ) ;
}
static inline void F_89 ( struct V_169 * V_33 )
{
F_88 ( V_33 -> V_6 , V_170 ,
V_172 ) ;
}
static inline void F_90 ( struct V_169 * V_33 )
{
F_91 ( V_33 -> V_6 ,
1 << ( V_173 + V_33 -> V_174 ) ,
V_171 ) ;
}
static inline void F_92 ( struct V_169 * V_33 )
{
F_91 ( V_33 -> V_6 ,
1 << ( V_173 + V_33 -> V_174 ) ,
V_172 ) ;
}
static inline void F_93 ( struct V_163 * V_33 )
{
F_88 ( V_33 -> V_6 , V_175 ,
V_171 ) ;
}
static inline void F_94 ( struct V_163 * V_33 )
{
F_88 ( V_33 -> V_6 , V_175 ,
V_172 ) ;
}
static inline void F_95 ( struct V_163 * V_33 )
{
F_91 ( V_33 -> V_6 , 1 << V_33 -> V_174 ,
V_172 ) ;
}
static inline void F_96 ( struct V_163 * V_33 )
{
F_91 ( V_33 -> V_6 , 1 << V_33 -> V_174 ,
V_171 ) ;
}
static struct V_176 * F_97 ( struct V_25 * V_26 ,
struct V_162 * V_177 )
{
struct V_176 * V_178 ;
V_178 = V_177 -> V_178 ;
if ( V_178 ) {
V_177 -> V_178 = NULL ;
if ( V_177 == F_98 ( V_178 ) -> V_179 )
F_99 ( V_26 , F_100 ( V_177 , V_180 ) ,
F_101 ( V_177 , V_181 ) ,
V_182 ) ;
else
F_102 ( V_26 , F_100 ( V_177 , V_180 ) ,
F_101 ( V_177 , V_181 ) ,
V_182 ) ;
F_103 ( V_177 , V_180 , 0 ) ;
if ( V_177 == F_98 ( V_178 ) -> V_183 )
return V_178 ;
} else if ( F_100 ( V_177 , V_180 ) ) {
F_102 ( V_26 ,
F_100 ( V_177 , V_180 ) ,
F_101 ( V_177 , V_181 ) ,
V_182 ) ;
F_103 ( V_177 , V_180 , 0 ) ;
}
return 0 ;
}
static struct V_176 * F_104 ( struct V_25 * V_26 ,
struct V_162 * V_177 )
{
struct V_176 * V_178 ;
V_178 = V_177 -> V_178 ;
V_177 -> V_178 = NULL ;
if ( F_100 ( V_177 , V_180 ) ) {
F_99 ( V_26 , F_100 ( V_177 , V_180 ) ,
F_101 ( V_177 , V_181 ) , V_184 ) ;
F_103 ( V_177 , V_180 , 0 ) ;
}
return V_178 ;
}
static unsigned int F_105 ( struct V_37 * V_26 ,
struct V_163 * V_33 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
unsigned int V_185 = 0 ;
unsigned int V_186 = 0 ;
unsigned int V_187 = 0 ;
unsigned int V_188 ;
unsigned int V_189 ;
struct V_176 * V_178 ;
if ( V_33 -> V_174 == V_69 )
F_88 ( V_6 , V_175 ,
V_190 ) ;
else
F_91 ( V_6 , ( 1 << V_33 -> V_174 ) ,
V_190 ) ;
V_189 = F_34 ( V_6 , V_33 -> V_174 , V_191 )
& V_192 ;
V_188 = ( V_189 - V_33 -> V_189 ) & V_192 ;
F_106 ( V_6 , V_193 , V_26 ,
L_4 ,
V_194 , V_33 -> V_174 , V_33 -> V_189 , V_189 , V_188 ) ;
while ( V_185 < V_188 ) {
V_178 = F_97 ( & V_6 -> V_195 -> V_26 ,
& V_6 -> V_196 [ V_33 -> V_197 ] ) ;
if ( V_178 ) {
V_187 ++ ;
V_186 += F_98 ( V_178 ) -> V_198 ;
F_107 ( V_178 ) ;
}
V_185 ++ ;
if ( F_108 ( V_33 -> V_197 < V_33 -> V_168 ) )
V_33 -> V_197 ++ ;
else
V_33 -> V_197 = V_33 -> V_167 ;
}
V_33 -> V_199 += V_185 ;
V_33 -> V_189 = V_189 ;
V_33 -> V_200 += V_187 ;
V_33 -> V_201 += V_186 ;
F_109 ( F_110 ( V_26 , V_33 -> V_202 ) ,
V_187 , V_186 ) ;
return V_185 ;
}
static unsigned int F_111 ( struct V_37 * V_26 ,
struct V_163 * V_33 )
{
unsigned int V_203 ;
unsigned long V_12 ;
F_112 ( & V_33 -> V_204 , V_12 ) ;
V_203 = F_105 ( V_26 , V_33 ) ;
F_113 ( & V_33 -> V_204 , V_12 ) ;
return V_203 ;
}
static int F_114 ( struct V_205 * V_206 , int V_207 )
{
struct V_163 * V_33 =
F_115 ( V_206 , struct V_163 , V_206 ) ;
unsigned int V_208 = 0 ;
struct V_209 * V_210 ;
unsigned long V_12 ;
F_112 ( & V_33 -> V_204 , V_12 ) ;
V_208 = F_105 ( V_33 -> V_6 -> V_26 , V_33 ) ;
if ( V_33 -> V_199 > ( V_211 + 1 ) ) {
V_210 = F_110 ( V_33 -> V_6 -> V_26 , V_33 -> V_202 ) ;
F_116 ( V_210 ) ;
}
F_113 ( & V_33 -> V_204 , V_12 ) ;
if ( V_208 == 0 ) {
F_117 ( V_206 ) ;
V_33 -> V_212 ( V_33 ) ;
return 0 ;
}
return V_207 ;
}
static void F_118 ( struct V_37 * V_26 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
int V_74 ;
if ( F_119 ( V_26 ) ) {
for ( V_74 = 0 ; V_74 < V_6 -> V_11 -> V_83 ; V_74 ++ )
F_111 ( V_26 , & V_6 -> V_213 [ V_74 ] ) ;
}
F_111 ( V_26 , & V_6 -> V_213 [ V_69 ] ) ;
}
static struct V_176 * F_120 ( struct V_37 * V_26 ,
struct V_176 * V_178 )
{
struct V_214 * V_215 = NULL ;
struct V_176 * V_216 ;
T_6 V_2 ;
T_5 V_217 ;
T_6 V_218 ;
T_1 V_219 ;
if ( F_121 ( F_122 ( V_178 ) < sizeof( * V_215 ) ) ) {
V_216 = F_123 ( V_178 , sizeof( * V_215 ) ) ;
F_124 ( V_178 ) ;
if ( ! V_216 ) {
V_26 -> V_121 . V_220 ++ ;
return NULL ;
}
V_178 = V_216 ;
}
F_125 ( V_178 , sizeof( * V_215 ) ) ;
V_215 = (struct V_214 * ) V_178 -> V_94 ;
if ( V_178 -> V_221 == V_222 ) {
V_218 = F_126 ( V_178 -> V_223 ) ;
switch ( V_218 ) {
case V_224 :
V_217 = F_127 ( V_178 ) -> V_223 ;
break;
case V_225 :
V_217 = F_128 ( V_178 ) -> V_226 ;
break;
default:
return V_178 ;
}
V_2 = F_129 ( V_178 ) - sizeof( * V_215 ) ;
V_219 = ( V_2 << V_227 ) |
( V_2 + V_178 -> V_228 ) ;
if ( V_217 == V_229 || V_217 == V_230 ) {
V_219 |= V_231 ;
if ( V_217 == V_230 && V_218 == V_224 )
V_219 |= V_232 ;
} else {
V_219 = 0 ;
}
V_215 -> V_219 = V_219 ;
}
return V_178 ;
}
static T_7 F_130 ( struct V_176 * V_178 , struct V_37 * V_26 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
struct V_25 * V_233 = & V_6 -> V_195 -> V_26 ;
struct V_163 * V_33 = NULL ;
struct V_162 * V_164 ;
struct V_209 * V_210 ;
unsigned long V_12 = 0 ;
int V_234 , V_174 ;
T_3 V_235 ;
unsigned int V_236 ;
T_8 * V_237 ;
T_1 V_238 ;
int V_63 ;
int V_74 ;
V_174 = F_131 ( V_178 ) ;
if ( V_174 == 0 )
V_174 = V_69 ;
else
V_174 -= 1 ;
V_33 = & V_6 -> V_213 [ V_174 ] ;
V_210 = F_110 ( V_26 , V_33 -> V_202 ) ;
V_234 = F_132 ( V_178 ) -> V_234 ;
F_112 ( & V_33 -> V_204 , V_12 ) ;
if ( V_33 -> V_199 <= ( V_234 + 1 ) ) {
if ( ! F_133 ( V_210 ) ) {
F_134 ( V_210 ) ;
F_135 ( V_26 ,
L_5 ,
V_194 , V_174 , V_33 -> V_202 ) ;
}
V_63 = V_239 ;
goto V_240;
}
if ( F_136 ( V_178 , V_241 ) ) {
V_63 = V_242 ;
goto V_240;
}
F_98 ( V_178 ) -> V_198 = V_178 -> V_243 ;
if ( V_6 -> V_53 ) {
V_178 = F_120 ( V_26 , V_178 ) ;
if ( ! V_178 ) {
V_63 = V_242 ;
goto V_240;
}
}
for ( V_74 = 0 ; V_74 <= V_234 ; V_74 ++ ) {
V_164 = F_85 ( V_6 , V_33 ) ;
if ( F_121 ( ! V_164 ) )
F_137 () ;
if ( ! V_74 ) {
F_98 ( V_178 ) -> V_179 = V_164 ;
V_236 = F_138 ( V_178 ) ;
V_235 = F_139 ( V_233 , V_178 -> V_94 , V_236 ,
V_182 ) ;
} else {
V_237 = & F_132 ( V_178 ) -> V_244 [ V_74 - 1 ] ;
V_236 = F_140 ( V_237 ) ;
V_235 = F_141 ( V_233 , V_237 , 0 , V_236 ,
V_182 ) ;
}
V_63 = F_142 ( V_233 , V_235 ) ;
if ( V_63 ) {
V_6 -> V_245 . V_246 ++ ;
F_70 ( V_6 , V_247 , V_26 , L_6 ) ;
V_63 = V_242 ;
goto V_248;
}
F_103 ( V_164 , V_180 , V_235 ) ;
F_143 ( V_164 , V_181 , V_236 ) ;
V_164 -> V_178 = V_178 ;
V_238 = ( V_236 << V_249 ) |
( V_6 -> V_11 -> V_250 << V_251 ) ;
if ( ! V_74 ) {
V_238 |= V_252 | V_253 ;
if ( V_178 -> V_221 == V_222 )
V_238 |= V_254 ;
}
if ( V_74 == V_234 )
V_238 |= V_255 ;
F_14 ( V_6 , V_164 -> V_256 , V_235 , V_238 ) ;
}
F_98 ( V_178 ) -> V_183 = V_164 ;
F_144 ( V_178 ) ;
V_33 -> V_199 -= V_234 + 1 ;
V_33 -> V_257 += V_234 + 1 ;
V_33 -> V_257 &= V_258 ;
F_145 ( V_210 , F_98 ( V_178 ) -> V_198 ) ;
if ( V_33 -> V_199 <= ( V_211 + 1 ) )
F_134 ( V_210 ) ;
if ( ! V_178 -> V_259 || F_146 ( V_210 ) )
F_35 ( V_6 , V_33 -> V_174 ,
V_33 -> V_257 , V_260 ) ;
V_240:
F_113 ( & V_33 -> V_204 , V_12 ) ;
return V_63 ;
V_248:
F_86 ( V_6 , V_33 ) ;
while ( V_74 -- > 0 ) {
V_164 = F_86 ( V_6 , V_33 ) ;
F_97 ( V_233 , V_164 ) ;
}
F_124 ( V_178 ) ;
goto V_240;
}
static struct V_176 * F_147 ( struct V_5 * V_6 ,
struct V_162 * V_177 )
{
struct V_25 * V_233 = & V_6 -> V_195 -> V_26 ;
struct V_176 * V_178 ;
struct V_176 * V_261 ;
T_3 V_235 ;
V_178 = F_148 ( V_6 -> V_26 , V_6 -> V_262 + V_263 ) ;
if ( ! V_178 ) {
V_6 -> V_245 . V_264 ++ ;
F_70 ( V_6 , V_265 , V_6 -> V_26 ,
L_7 , V_194 ) ;
return NULL ;
}
V_235 = F_139 ( V_233 , V_178 -> V_94 , V_6 -> V_262 ,
V_184 ) ;
if ( F_142 ( V_233 , V_235 ) ) {
V_6 -> V_245 . V_266 ++ ;
F_149 ( V_178 ) ;
F_70 ( V_6 , V_265 , V_6 -> V_26 ,
L_8 , V_194 ) ;
return NULL ;
}
V_261 = F_104 ( V_233 , V_177 ) ;
V_177 -> V_178 = V_178 ;
F_103 ( V_177 , V_180 , V_235 ) ;
F_143 ( V_177 , V_181 , V_6 -> V_262 ) ;
F_10 ( V_6 , V_177 -> V_256 , V_235 ) ;
return V_261 ;
}
static unsigned int F_150 ( struct V_169 * V_33 ,
unsigned int V_207 )
{
struct V_5 * V_6 = V_33 -> V_6 ;
struct V_37 * V_26 = V_6 -> V_26 ;
struct V_162 * V_177 ;
struct V_176 * V_178 ;
T_1 V_267 ;
unsigned long V_268 ;
int V_243 ;
unsigned int V_269 = 0 , V_270 ;
unsigned int V_271 , V_272 ;
unsigned int V_273 ;
unsigned int V_274 = 0 ;
if ( V_33 -> V_174 == V_69 ) {
F_88 ( V_6 , V_170 ,
V_190 ) ;
} else {
V_272 = 1 << ( V_173 + V_33 -> V_174 ) ;
F_91 ( V_6 ,
V_272 ,
V_190 ) ;
}
V_271 = F_36 ( V_6 , V_33 -> V_174 , V_275 ) ;
V_273 = ( V_271 >> V_276 ) &
V_277 ;
if ( V_273 > V_33 -> V_278 ) {
V_273 = V_273 - V_33 -> V_278 ;
V_33 -> V_279 += V_273 ;
V_33 -> V_278 += V_273 ;
if ( V_33 -> V_278 >= 0xC000 ) {
V_33 -> V_278 = 0 ;
F_37 ( V_6 , V_33 -> V_174 , 0 ,
V_275 ) ;
}
}
V_271 &= V_258 ;
V_270 = ( V_271 - V_33 -> V_189 ) & V_192 ;
F_106 ( V_6 , V_280 , V_26 ,
L_9 , V_270 ) ;
while ( ( V_269 < V_270 ) &&
( V_269 < V_207 ) ) {
V_177 = & V_6 -> V_281 [ V_33 -> V_282 ] ;
V_178 = F_147 ( V_6 , V_177 ) ;
if ( F_121 ( ! V_178 ) ) {
V_33 -> V_283 ++ ;
goto V_284;
}
if ( ! V_6 -> V_53 ) {
V_267 =
F_9 ( V_6 , V_177 -> V_256 ) ;
} else {
struct V_214 * V_215 ;
V_215 = (struct V_214 * ) V_178 -> V_94 ;
V_267 = V_215 -> V_285 ;
}
V_268 = V_267 & 0xffff ;
V_243 = V_267 >> V_249 ;
F_106 ( V_6 , V_280 , V_26 ,
L_10 ,
V_194 , V_271 , V_33 -> V_189 ,
V_33 -> V_282 , V_267 ) ;
if ( F_121 ( ! ( V_268 & V_255 ) || ! ( V_268 & V_253 ) ) ) {
F_70 ( V_6 , V_280 , V_26 ,
L_11 ) ;
V_33 -> V_279 ++ ;
F_149 ( V_178 ) ;
goto V_284;
}
if ( F_121 ( V_268 & ( V_286 |
V_287 |
V_288 |
V_289 |
V_290 ) ) ) {
F_70 ( V_6 , V_280 , V_26 , L_12 ,
( unsigned int ) V_268 ) ;
if ( V_268 & V_286 )
V_26 -> V_121 . V_291 ++ ;
if ( V_268 & V_287 )
V_26 -> V_121 . V_292 ++ ;
if ( V_268 & V_288 )
V_26 -> V_121 . V_293 ++ ;
if ( V_268 & V_289 )
V_26 -> V_121 . V_294 ++ ;
V_26 -> V_121 . V_295 ++ ;
F_149 ( V_178 ) ;
goto V_284;
}
V_274 = ( V_268 & V_6 -> V_296 ) &&
V_6 -> V_50 ;
F_151 ( V_178 , V_243 ) ;
if ( V_6 -> V_53 ) {
F_152 ( V_178 , 64 ) ;
V_243 -= 64 ;
}
if ( F_108 ( V_274 ) )
V_178 -> V_221 = V_297 ;
F_152 ( V_178 , 2 ) ;
V_243 -= 2 ;
if ( V_6 -> V_51 ) {
F_153 ( V_178 , V_243 - V_298 ) ;
V_243 -= V_298 ;
}
V_178 -> V_223 = F_154 ( V_178 , V_6 -> V_26 ) ;
V_33 -> V_200 ++ ;
V_33 -> V_201 += V_243 ;
if ( V_268 & V_299 )
V_26 -> V_121 . V_300 ++ ;
F_155 ( & V_33 -> V_206 , V_178 ) ;
F_106 ( V_6 , V_280 , V_26 , L_13 ) ;
V_284:
V_269 ++ ;
if ( F_108 ( V_33 -> V_282 < V_33 -> V_168 ) )
V_33 -> V_282 ++ ;
else
V_33 -> V_282 = V_33 -> V_167 ;
V_33 -> V_189 = ( V_33 -> V_189 + 1 ) & V_192 ;
F_37 ( V_6 , V_33 -> V_174 , V_33 -> V_189 , V_301 ) ;
}
return V_269 ;
}
static int F_156 ( struct V_205 * V_206 , int V_207 )
{
struct V_169 * V_33 = F_115 ( V_206 ,
struct V_169 , V_206 ) ;
unsigned int V_208 ;
V_208 = F_150 ( V_33 , V_207 ) ;
if ( V_208 < V_207 ) {
F_157 ( V_206 , V_208 ) ;
V_33 -> V_212 ( V_33 ) ;
}
return V_208 ;
}
static int F_158 ( struct V_5 * V_6 ,
struct V_169 * V_33 )
{
struct V_162 * V_177 ;
struct V_176 * V_178 ;
int V_74 ;
F_106 ( V_6 , V_141 , V_6 -> V_26 , L_14 , V_194 ) ;
for ( V_74 = 0 ; V_74 < V_33 -> V_236 ; V_74 ++ ) {
V_177 = V_33 -> V_165 + V_74 ;
V_178 = F_147 ( V_6 , V_177 ) ;
if ( V_178 )
F_107 ( V_178 ) ;
if ( ! V_177 -> V_178 )
return - V_302 ;
}
return 0 ;
}
static void F_159 ( struct V_5 * V_6 )
{
struct V_176 * V_178 ;
struct V_162 * V_177 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_6 -> V_303 ; V_74 ++ ) {
V_177 = & V_6 -> V_281 [ V_74 ] ;
V_178 = F_104 ( & V_6 -> V_195 -> V_26 , V_177 ) ;
if ( V_178 )
F_107 ( V_178 ) ;
}
}
static void F_160 ( struct V_5 * V_6 , T_1 V_272 , bool V_122 )
{
T_1 V_75 ;
V_75 = F_61 ( V_6 , V_304 ) ;
if ( V_122 )
V_75 |= V_272 ;
else
V_75 &= ~ V_272 ;
F_62 ( V_6 , V_75 , V_304 ) ;
if ( V_122 == 0 )
F_161 ( 1000 , 2000 ) ;
}
static int F_162 ( struct V_5 * V_6 )
{
struct V_25 * V_233 = & V_6 -> V_195 -> V_26 ;
unsigned int V_305 = 0 ;
T_1 V_75 ;
F_20 ( V_6 , 0 ) ;
F_163 ( 10 ) ;
F_62 ( V_6 , 0 , V_304 ) ;
F_62 ( V_6 , V_306 , V_304 ) ;
while ( V_305 ++ < 1000 ) {
V_75 = F_61 ( V_6 , V_304 ) ;
if ( ! ( V_75 & V_306 ) )
return 0 ;
F_163 ( 1 ) ;
}
if ( V_305 == 1000 ) {
F_164 ( V_233 ,
L_15 ) ;
return - V_307 ;
}
return 0 ;
}
static void F_165 ( struct V_5 * V_6 )
{
F_88 ( V_6 , 0xFFFFFFFF , V_171 ) ;
F_88 ( V_6 , 0xFFFFFFFF , V_190 ) ;
F_91 ( V_6 , 0xFFFFFFFF , V_171 ) ;
F_91 ( V_6 , 0xFFFFFFFF , V_190 ) ;
}
static void F_166 ( struct V_5 * V_6 )
{
T_1 V_308 = 0 ;
if ( V_6 -> V_309 ) {
V_308 |= V_310 ;
} else if ( V_6 -> V_311 ) {
V_308 |= V_310 ;
} else if ( V_6 -> V_312 == V_313 ) {
if ( V_6 -> V_11 -> V_12 & V_314 )
V_308 |= V_310 ;
}
F_88 ( V_6 , V_308 , V_172 ) ;
}
static int F_167 ( struct V_5 * V_6 )
{
struct V_25 * V_233 = & V_6 -> V_195 -> V_26 ;
int V_63 ;
T_1 V_75 ;
T_1 V_308 = 0 ;
F_168 ( & V_6 -> V_195 -> V_26 , L_16 ) ;
V_63 = F_162 ( V_6 ) ;
if ( V_63 )
return V_63 ;
F_62 ( V_6 , 0 , V_304 ) ;
F_62 ( V_6 ,
V_315 | V_316 | V_317 ,
V_318 ) ;
F_62 ( V_6 , 0 , V_318 ) ;
F_62 ( V_6 , V_319 , V_320 ) ;
V_75 = F_18 ( V_6 , V_56 ) ;
V_75 |= V_321 ;
F_21 ( V_6 , V_75 , V_56 ) ;
if ( ! F_17 ( V_6 ) && ! F_60 ( V_6 ) )
F_21 ( V_6 , 1 , V_322 ) ;
F_165 ( V_6 ) ;
if ( V_6 -> V_312 == V_313 ) {
V_75 = F_25 ( V_6 ) ;
V_75 |= F_169 ( V_6 -> V_11 -> V_323 ) ;
if ( F_119 ( V_6 -> V_26 ) )
V_75 |= V_6 -> V_11 -> V_324 ;
else
V_75 &= ~ V_6 -> V_11 -> V_324 ;
F_26 ( V_6 , V_75 ) ;
}
if ( V_6 -> V_11 -> V_12 & V_325 )
V_308 |= ( V_326 | V_327 ) ;
F_88 ( V_6 , V_308 , V_172 ) ;
F_168 ( V_233 , L_17 ) ;
return 0 ;
}
static void F_170 ( struct V_5 * V_6 ,
unsigned int V_174 , unsigned int V_236 ,
unsigned int V_328 , unsigned int V_168 )
{
struct V_163 * V_33 = & V_6 -> V_213 [ V_174 ] ;
T_1 V_329 = F_171 ( V_6 ) ;
T_1 V_330 = 0 ;
F_172 ( & V_33 -> V_204 ) ;
V_33 -> V_6 = V_6 ;
V_33 -> V_174 = V_174 ;
if ( V_174 == V_69 ) {
V_33 -> V_202 = 0 ;
V_33 -> V_212 = F_94 ;
V_33 -> V_331 = F_93 ;
} else {
V_33 -> V_202 = V_174 + 1 ;
V_33 -> V_212 = F_95 ;
V_33 -> V_331 = F_96 ;
}
V_33 -> V_165 = V_6 -> V_196 + V_328 ;
V_33 -> V_236 = V_236 ;
V_33 -> V_197 = V_328 ;
V_33 -> V_189 = 0 ;
V_33 -> V_199 = V_236 ;
V_33 -> V_166 = V_328 ;
V_33 -> V_167 = V_328 ;
V_33 -> V_168 = V_168 - 1 ;
V_33 -> V_257 = 0 ;
if ( V_174 != V_69 )
V_330 = V_319 << 16 ;
F_35 ( V_6 , V_174 , 0 , V_260 ) ;
F_35 ( V_6 , V_174 , 0 , V_191 ) ;
F_35 ( V_6 , V_174 , 1 , V_70 ) ;
F_35 ( V_6 , V_174 , V_330 ,
V_332 ) ;
F_35 ( V_6 , V_174 ,
( ( V_236 << V_333 ) |
V_334 ) , V_335 ) ;
F_35 ( V_6 , V_174 , V_328 * V_329 ,
V_336 ) ;
F_35 ( V_6 , V_174 , V_328 * V_329 ,
V_337 ) ;
F_35 ( V_6 , V_174 , V_328 * V_329 ,
V_338 ) ;
F_35 ( V_6 , V_174 , V_168 * V_329 - 1 ,
V_339 ) ;
}
static int F_173 ( struct V_5 * V_6 ,
unsigned int V_174 , unsigned int V_236 ,
unsigned int V_328 , unsigned int V_168 )
{
struct V_169 * V_33 = & V_6 -> V_340 [ V_174 ] ;
T_1 V_329 = F_171 ( V_6 ) ;
int V_63 ;
V_33 -> V_6 = V_6 ;
V_33 -> V_174 = V_174 ;
if ( V_174 == V_69 ) {
V_33 -> V_212 = F_89 ;
V_33 -> V_331 = F_87 ;
} else {
V_33 -> V_212 = F_92 ;
V_33 -> V_331 = F_90 ;
}
V_33 -> V_165 = V_6 -> V_281 + V_328 ;
V_33 -> V_236 = V_236 ;
V_33 -> V_189 = 0 ;
V_33 -> V_282 = V_328 ;
V_33 -> V_167 = V_328 ;
V_33 -> V_168 = V_168 - 1 ;
V_63 = F_158 ( V_6 , V_33 ) ;
if ( V_63 )
return V_63 ;
F_37 ( V_6 , V_174 , 0 , V_275 ) ;
F_37 ( V_6 , V_174 , 0 , V_301 ) ;
F_37 ( V_6 , V_174 , 1 , V_70 ) ;
F_37 ( V_6 , V_174 ,
( ( V_236 << V_333 ) |
V_334 ) , V_335 ) ;
F_37 ( V_6 , V_174 ,
( V_341 <<
V_342 ) |
V_343 , V_344 ) ;
F_37 ( V_6 , V_174 , V_328 * V_329 ,
V_336 ) ;
F_37 ( V_6 , V_174 , V_328 * V_329 ,
V_345 ) ;
F_37 ( V_6 , V_174 , V_328 * V_329 ,
V_346 ) ;
F_37 ( V_6 , V_174 , V_168 * V_329 - 1 ,
V_339 ) ;
return V_63 ;
}
static void F_174 ( struct V_5 * V_6 )
{
unsigned int V_74 ;
struct V_163 * V_33 ;
for ( V_74 = 0 ; V_74 < V_6 -> V_11 -> V_83 ; ++ V_74 ) {
V_33 = & V_6 -> V_213 [ V_74 ] ;
F_175 ( V_6 -> V_26 , & V_33 -> V_206 , F_114 , 64 ) ;
}
V_33 = & V_6 -> V_213 [ V_69 ] ;
F_175 ( V_6 -> V_26 , & V_33 -> V_206 , F_114 , 64 ) ;
}
static void F_176 ( struct V_5 * V_6 )
{
unsigned int V_74 ;
T_1 V_308 = V_175 ;
T_1 V_347 = 0 ;
struct V_163 * V_33 ;
for ( V_74 = 0 ; V_74 < V_6 -> V_11 -> V_83 ; ++ V_74 ) {
V_33 = & V_6 -> V_213 [ V_74 ] ;
F_177 ( & V_33 -> V_206 ) ;
V_347 |= ( 1 << V_74 ) ;
}
V_33 = & V_6 -> V_213 [ V_69 ] ;
F_177 ( & V_33 -> V_206 ) ;
F_88 ( V_6 , V_308 , V_172 ) ;
F_91 ( V_6 , V_347 , V_172 ) ;
}
static void F_178 ( struct V_5 * V_6 )
{
unsigned int V_74 ;
T_1 V_348 = V_175 ;
T_1 V_349 = 0xffff ;
struct V_163 * V_33 ;
F_88 ( V_6 , V_348 , V_171 ) ;
F_91 ( V_6 , V_349 , V_171 ) ;
for ( V_74 = 0 ; V_74 < V_6 -> V_11 -> V_83 ; ++ V_74 ) {
V_33 = & V_6 -> V_213 [ V_74 ] ;
F_179 ( & V_33 -> V_206 ) ;
}
V_33 = & V_6 -> V_213 [ V_69 ] ;
F_179 ( & V_33 -> V_206 ) ;
}
static void F_180 ( struct V_5 * V_6 )
{
unsigned int V_74 ;
struct V_163 * V_33 ;
for ( V_74 = 0 ; V_74 < V_6 -> V_11 -> V_83 ; ++ V_74 ) {
V_33 = & V_6 -> V_213 [ V_74 ] ;
F_181 ( & V_33 -> V_206 ) ;
}
V_33 = & V_6 -> V_213 [ V_69 ] ;
F_181 ( & V_33 -> V_206 ) ;
}
static void F_182 ( struct V_37 * V_26 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
T_1 V_74 , V_350 ;
T_1 V_351 , V_352 ;
T_1 V_353 [ 3 ] = { 0 , 0 , 0 } ;
V_351 = F_30 ( V_6 , V_354 ) ;
V_350 = V_351 & V_355 ;
V_351 &= ~ V_355 ;
F_31 ( V_6 , V_351 , V_354 ) ;
V_351 = 0 ;
V_352 = 0 ;
F_31 ( V_6 , V_356 , V_357 ) ;
for ( V_74 = 0 ; V_74 < V_6 -> V_11 -> V_83 ; V_74 ++ ) {
F_170 ( V_6 , V_74 , V_6 -> V_11 -> V_358 ,
V_74 * V_6 -> V_11 -> V_358 ,
( V_74 + 1 ) * V_6 -> V_11 -> V_358 ) ;
V_352 |= ( 1 << V_74 ) ;
V_351 |= ( 1 << ( V_74 + V_359 ) ) ;
V_353 [ F_183 ( V_74 ) ] |=
( ( V_360 + V_74 ) << F_184 ( V_74 ) ) ;
}
F_170 ( V_6 , V_69 , V_361 ,
V_6 -> V_11 -> V_83 *
V_6 -> V_11 -> V_358 ,
V_362 ) ;
V_352 |= ( 1 << V_69 ) ;
V_351 |= ( 1 << ( V_69 + V_359 ) ) ;
V_353 [ F_183 ( V_69 ) ] |=
( ( V_360 + V_6 -> V_11 -> V_83 ) <<
F_184 ( V_69 ) ) ;
F_31 ( V_6 , V_353 [ 0 ] , V_363 ) ;
F_31 ( V_6 , V_353 [ 1 ] , V_364 ) ;
F_31 ( V_6 , V_353 [ 2 ] , V_365 ) ;
F_174 ( V_6 ) ;
F_31 ( V_6 , V_352 , V_366 ) ;
if ( V_350 )
V_351 |= V_355 ;
F_31 ( V_6 , V_351 , V_354 ) ;
}
static void F_185 ( struct V_5 * V_6 )
{
unsigned int V_74 ;
struct V_169 * V_33 ;
for ( V_74 = 0 ; V_74 < V_6 -> V_11 -> V_84 ; ++ V_74 ) {
V_33 = & V_6 -> V_340 [ V_74 ] ;
F_186 ( V_6 -> V_26 , & V_33 -> V_206 , F_156 , 64 ) ;
}
V_33 = & V_6 -> V_340 [ V_69 ] ;
F_186 ( V_6 -> V_26 , & V_33 -> V_206 , F_156 , 64 ) ;
}
static void F_187 ( struct V_5 * V_6 )
{
unsigned int V_74 ;
T_1 V_308 = V_170 ;
T_1 V_347 = 0 ;
struct V_169 * V_33 ;
for ( V_74 = 0 ; V_74 < V_6 -> V_11 -> V_84 ; ++ V_74 ) {
V_33 = & V_6 -> V_340 [ V_74 ] ;
F_177 ( & V_33 -> V_206 ) ;
V_347 |= ( 1 << ( V_173 + V_74 ) ) ;
}
V_33 = & V_6 -> V_340 [ V_69 ] ;
F_177 ( & V_33 -> V_206 ) ;
F_88 ( V_6 , V_308 , V_172 ) ;
F_91 ( V_6 , V_347 , V_172 ) ;
}
static void F_188 ( struct V_5 * V_6 )
{
unsigned int V_74 ;
T_1 V_348 = V_170 ;
T_1 V_349 = 0xffff << V_173 ;
struct V_169 * V_33 ;
F_88 ( V_6 , V_348 , V_171 ) ;
F_91 ( V_6 , V_349 , V_171 ) ;
for ( V_74 = 0 ; V_74 < V_6 -> V_11 -> V_84 ; ++ V_74 ) {
V_33 = & V_6 -> V_340 [ V_74 ] ;
F_179 ( & V_33 -> V_206 ) ;
}
V_33 = & V_6 -> V_340 [ V_69 ] ;
F_179 ( & V_33 -> V_206 ) ;
}
static void F_189 ( struct V_5 * V_6 )
{
unsigned int V_74 ;
struct V_169 * V_33 ;
for ( V_74 = 0 ; V_74 < V_6 -> V_11 -> V_84 ; ++ V_74 ) {
V_33 = & V_6 -> V_340 [ V_74 ] ;
F_181 ( & V_33 -> V_206 ) ;
}
V_33 = & V_6 -> V_340 [ V_69 ] ;
F_181 ( & V_33 -> V_206 ) ;
}
static int F_190 ( struct V_37 * V_26 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
T_1 V_74 ;
T_1 V_350 ;
T_1 V_351 ;
T_1 V_352 ;
int V_63 ;
V_351 = F_32 ( V_6 , V_354 ) ;
V_350 = V_351 & V_355 ;
V_351 &= ~ V_355 ;
F_33 ( V_6 , V_351 , V_354 ) ;
V_351 = 0 ;
V_352 = 0 ;
for ( V_74 = 0 ; V_74 < V_6 -> V_11 -> V_84 ; V_74 ++ ) {
V_63 = F_173 ( V_6 , V_74 ,
V_6 -> V_11 -> V_367 ,
V_74 * V_6 -> V_11 -> V_367 ,
( V_74 + 1 ) *
V_6 -> V_11 -> V_367 ) ;
if ( V_63 )
return V_63 ;
V_352 |= ( 1 << V_74 ) ;
V_351 |= ( 1 << ( V_74 + V_359 ) ) ;
}
V_63 = F_173 ( V_6 , V_69 , V_368 ,
V_6 -> V_11 -> V_84 *
V_6 -> V_11 -> V_367 ,
V_362 ) ;
if ( V_63 )
return V_63 ;
V_352 |= ( 1 << V_69 ) ;
V_351 |= ( 1 << ( V_69 + V_359 ) ) ;
F_185 ( V_6 ) ;
F_33 ( V_6 , V_352 , V_366 ) ;
if ( V_350 )
V_351 |= V_355 ;
F_33 ( V_6 , V_351 , V_354 ) ;
return 0 ;
}
static int F_191 ( struct V_5 * V_6 )
{
int V_63 = 0 ;
int V_305 = 0 ;
T_1 V_75 ;
T_1 V_351 ;
int V_74 ;
V_75 = F_30 ( V_6 , V_354 ) ;
V_75 &= ~ V_355 ;
F_31 ( V_6 , V_75 , V_354 ) ;
while ( V_305 ++ < V_369 ) {
V_75 = F_30 ( V_6 , V_370 ) ;
if ( V_75 & V_371 )
break;
F_163 ( 1 ) ;
}
if ( V_305 == V_369 ) {
F_192 ( V_6 -> V_26 , L_18 ) ;
V_63 = - V_307 ;
}
F_161 ( 10000 , 20000 ) ;
V_75 = F_32 ( V_6 , V_354 ) ;
V_75 &= ~ V_355 ;
F_33 ( V_6 , V_75 , V_354 ) ;
V_305 = 0 ;
while ( V_305 ++ < V_369 ) {
V_75 = F_32 ( V_6 , V_370 ) ;
if ( V_75 & V_371 )
break;
F_163 ( 1 ) ;
}
if ( V_305 == V_369 ) {
F_192 ( V_6 -> V_26 , L_19 ) ;
V_63 = - V_307 ;
}
V_351 = 0 ;
for ( V_74 = 0 ; V_74 < V_6 -> V_11 -> V_84 ; V_74 ++ )
V_351 |= ( 1 << ( V_74 + V_359 ) ) ;
V_75 = F_32 ( V_6 , V_354 ) ;
V_75 &= ~ V_351 ;
F_33 ( V_6 , V_75 , V_354 ) ;
V_351 = 0 ;
for ( V_74 = 0 ; V_74 < V_6 -> V_11 -> V_83 ; V_74 ++ )
V_351 |= ( 1 << ( V_74 + V_359 ) ) ;
V_75 = F_30 ( V_6 , V_354 ) ;
V_75 &= ~ V_351 ;
F_31 ( V_6 , V_75 , V_354 ) ;
return V_63 ;
}
static void F_193 ( struct V_5 * V_6 )
{
struct V_209 * V_210 ;
struct V_176 * V_178 ;
struct V_162 * V_177 ;
int V_74 ;
F_189 ( V_6 ) ;
F_180 ( V_6 ) ;
F_191 ( V_6 ) ;
for ( V_74 = 0 ; V_74 < V_6 -> V_372 ; V_74 ++ ) {
V_177 = V_6 -> V_196 + V_74 ;
V_178 = F_97 ( & V_6 -> V_195 -> V_26 , V_177 ) ;
if ( V_178 )
F_124 ( V_178 ) ;
}
for ( V_74 = 0 ; V_74 < V_6 -> V_11 -> V_83 ; V_74 ++ ) {
V_210 = F_110 ( V_6 -> V_26 , V_6 -> V_213 [ V_74 ] . V_202 ) ;
F_194 ( V_210 ) ;
}
V_210 = F_110 ( V_6 -> V_26 , V_6 -> V_213 [ V_69 ] . V_202 ) ;
F_194 ( V_210 ) ;
F_159 ( V_6 ) ;
F_195 ( V_6 -> V_281 ) ;
F_195 ( V_6 -> V_196 ) ;
}
static int F_196 ( struct V_5 * V_6 )
{
int V_63 ;
unsigned int V_74 ;
struct V_162 * V_177 ;
F_106 ( V_6 , V_141 , V_6 -> V_26 , L_14 , V_194 ) ;
V_6 -> V_373 = V_6 -> V_20 + V_6 -> V_11 -> V_374 ;
V_6 -> V_303 = V_362 ;
V_6 -> V_281 = F_197 ( V_6 -> V_303 , sizeof( struct V_162 ) ,
V_375 ) ;
if ( ! V_6 -> V_281 )
return - V_302 ;
for ( V_74 = 0 ; V_74 < V_6 -> V_303 ; V_74 ++ ) {
V_177 = V_6 -> V_281 + V_74 ;
V_177 -> V_256 = V_6 -> V_373 + V_74 * V_376 ;
}
V_6 -> V_377 = V_6 -> V_20 + V_6 -> V_11 -> V_378 ;
V_6 -> V_372 = V_362 ;
V_6 -> V_196 = F_197 ( V_6 -> V_372 , sizeof( struct V_162 ) ,
V_375 ) ;
if ( ! V_6 -> V_196 ) {
F_195 ( V_6 -> V_281 ) ;
return - V_302 ;
}
for ( V_74 = 0 ; V_74 < V_6 -> V_372 ; V_74 ++ ) {
V_177 = V_6 -> V_196 + V_74 ;
V_177 -> V_256 = V_6 -> V_377 + V_74 * V_376 ;
}
F_33 ( V_6 , V_379 , V_380 ) ;
V_63 = F_190 ( V_6 -> V_26 ) ;
if ( V_63 ) {
F_135 ( V_6 -> V_26 , L_20 ) ;
F_159 ( V_6 ) ;
F_195 ( V_6 -> V_281 ) ;
F_195 ( V_6 -> V_196 ) ;
return V_63 ;
}
F_31 ( V_6 , V_379 , V_380 ) ;
F_182 ( V_6 -> V_26 ) ;
return 0 ;
}
static void F_198 ( struct V_381 * V_382 )
{
unsigned long V_12 ;
unsigned int V_215 ;
struct V_5 * V_6 = F_115 (
V_382 , struct V_5 , V_383 ) ;
F_106 ( V_6 , V_384 , V_6 -> V_26 , L_14 , V_194 ) ;
F_112 ( & V_6 -> V_204 , V_12 ) ;
V_215 = V_6 -> V_385 ;
V_6 -> V_385 = 0 ;
F_113 ( & V_6 -> V_204 , V_12 ) ;
if ( V_215 & V_386 ) {
F_106 ( V_6 , V_387 , V_6 -> V_26 ,
L_21 ) ;
F_79 ( V_6 , V_145 ) ;
}
if ( V_215 & V_310 )
F_199 ( V_6 -> V_42 ,
! ! ( V_215 & V_388 ) ) ;
}
static T_9 F_200 ( int V_389 , void * V_390 )
{
struct V_5 * V_6 = V_390 ;
struct V_169 * V_391 ;
struct V_163 * V_392 ;
unsigned int V_174 , V_215 ;
V_215 = F_201 ( V_6 , V_393 ) &
~ F_201 ( V_6 , V_394 ) ;
F_91 ( V_6 , V_215 , V_190 ) ;
F_106 ( V_6 , V_384 , V_6 -> V_26 ,
L_22 , V_194 , V_215 ) ;
for ( V_174 = 0 ; V_174 < V_6 -> V_11 -> V_84 ; V_174 ++ ) {
if ( ! ( V_215 & F_169 ( V_173 + V_174 ) ) )
continue;
V_391 = & V_6 -> V_340 [ V_174 ] ;
if ( F_108 ( F_202 ( & V_391 -> V_206 ) ) ) {
V_391 -> V_331 ( V_391 ) ;
F_203 ( & V_391 -> V_206 ) ;
}
}
for ( V_174 = 0 ; V_174 < V_6 -> V_11 -> V_83 ; V_174 ++ ) {
if ( ! ( V_215 & F_169 ( V_174 ) ) )
continue;
V_392 = & V_6 -> V_213 [ V_174 ] ;
if ( F_108 ( F_202 ( & V_392 -> V_206 ) ) ) {
V_392 -> V_331 ( V_392 ) ;
F_203 ( & V_392 -> V_206 ) ;
}
}
return V_395 ;
}
static T_9 F_204 ( int V_389 , void * V_390 )
{
struct V_5 * V_6 = V_390 ;
struct V_169 * V_391 ;
struct V_163 * V_392 ;
unsigned int V_215 ;
unsigned long V_12 ;
V_215 = F_205 ( V_6 , V_393 ) &
~ F_205 ( V_6 , V_394 ) ;
F_88 ( V_6 , V_215 , V_190 ) ;
F_106 ( V_6 , V_384 , V_6 -> V_26 ,
L_23 , V_215 ) ;
if ( V_215 & V_170 ) {
V_391 = & V_6 -> V_340 [ V_69 ] ;
if ( F_108 ( F_202 ( & V_391 -> V_206 ) ) ) {
V_391 -> V_331 ( V_391 ) ;
F_203 ( & V_391 -> V_206 ) ;
}
}
if ( V_215 & V_175 ) {
V_392 = & V_6 -> V_213 [ V_69 ] ;
if ( F_108 ( F_202 ( & V_392 -> V_206 ) ) ) {
V_392 -> V_331 ( V_392 ) ;
F_203 ( & V_392 -> V_206 ) ;
}
}
if ( V_6 -> V_385 & ( V_396 |
V_397 |
V_310 |
V_398 |
V_399 ) ) {
F_206 ( & V_6 -> V_383 ) ;
}
if ( ( V_6 -> V_11 -> V_12 & V_325 ) &&
V_215 & ( V_326 | V_327 ) ) {
F_207 ( & V_6 -> V_400 ) ;
}
V_215 &= ( V_310 |
V_386 ) ;
if ( V_215 ) {
F_112 ( & V_6 -> V_204 , V_12 ) ;
V_6 -> V_385 |= V_215 ;
F_113 ( & V_6 -> V_204 , V_12 ) ;
F_206 ( & V_6 -> V_383 ) ;
}
return V_395 ;
}
static T_9 F_208 ( int V_389 , void * V_390 )
{
struct V_5 * V_6 = V_390 ;
F_209 ( & V_6 -> V_195 -> V_26 , 0 ) ;
return V_395 ;
}
static void F_210 ( struct V_37 * V_26 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
F_211 ( V_6 -> V_401 ) ;
F_204 ( V_6 -> V_401 , V_6 ) ;
F_212 ( V_6 -> V_401 ) ;
F_211 ( V_6 -> V_402 ) ;
F_200 ( V_6 -> V_402 , V_6 ) ;
F_212 ( V_6 -> V_402 ) ;
}
static void F_213 ( struct V_5 * V_6 )
{
T_1 V_75 ;
V_75 = F_16 ( V_6 ) ;
V_75 |= F_169 ( 1 ) ;
F_20 ( V_6 , V_75 ) ;
F_163 ( 10 ) ;
V_75 &= ~ F_169 ( 1 ) ;
F_20 ( V_6 , V_75 ) ;
F_163 ( 10 ) ;
}
static void F_214 ( struct V_5 * V_6 ,
unsigned char * V_9 )
{
F_62 ( V_6 , ( V_9 [ 0 ] << 24 ) | ( V_9 [ 1 ] << 16 ) |
( V_9 [ 2 ] << 8 ) | V_9 [ 3 ] , V_403 ) ;
F_62 ( V_6 , ( V_9 [ 4 ] << 8 ) | V_9 [ 5 ] , V_404 ) ;
}
static T_1 F_215 ( struct V_5 * V_6 )
{
T_1 V_75 ;
T_1 V_351 ;
V_351 = 1 << ( V_69 + V_359 ) | V_355 ;
V_75 = F_30 ( V_6 , V_354 ) ;
V_75 &= ~ V_351 ;
F_31 ( V_6 , V_75 , V_354 ) ;
V_75 = F_32 ( V_6 , V_354 ) ;
V_75 &= ~ V_351 ;
F_33 ( V_6 , V_75 , V_354 ) ;
F_62 ( V_6 , 1 , V_405 ) ;
F_163 ( 10 ) ;
F_62 ( V_6 , 0 , V_405 ) ;
return V_351 ;
}
static void F_216 ( struct V_5 * V_6 , T_1 V_351 )
{
T_1 V_75 ;
V_75 = F_32 ( V_6 , V_354 ) ;
V_75 |= V_351 ;
F_33 ( V_6 , V_75 , V_354 ) ;
V_75 = F_30 ( V_6 , V_354 ) ;
V_75 |= V_351 ;
F_31 ( V_6 , V_75 , V_354 ) ;
}
static void F_217 ( struct V_5 * V_6 )
{
T_1 V_74 ;
F_218 ( V_6 , 0x0 , V_406 ) ;
F_218 ( V_6 , 0x0 , V_407 ) ;
F_218 ( V_6 , 0x0 , V_407 + 4 ) ;
for ( V_74 = V_408 ; V_74 <= V_409 ; V_74 ++ )
F_33 ( V_6 , 0x0 , V_74 ) ;
for ( V_74 = 0 ; V_74 < ( V_6 -> V_11 -> V_410 / 4 ) ; V_74 ++ )
F_218 ( V_6 , 0x0 ,
V_411 + V_74 * sizeof( T_1 ) ) ;
for ( V_74 = 0 ; V_74 < V_6 -> V_11 -> V_410 *
V_6 -> V_11 -> V_412 ; V_74 ++ )
F_219 ( V_6 , 0x0 , V_74 * sizeof( T_1 ) ) ;
}
static void F_220 ( struct V_5 * V_6 )
{
if ( F_17 ( V_6 ) || F_60 ( V_6 ) )
return;
F_217 ( V_6 ) ;
}
static void F_221 ( struct V_37 * V_26 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
F_187 ( V_6 ) ;
F_176 ( V_6 ) ;
F_160 ( V_6 , V_413 | V_414 , true ) ;
F_222 ( V_26 ) ;
F_166 ( V_6 ) ;
F_223 ( V_6 -> V_42 ) ;
}
static int F_224 ( struct V_37 * V_26 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
unsigned long V_351 ;
T_1 V_75 ;
int V_63 ;
F_106 ( V_6 , V_415 , V_26 , L_24 ) ;
F_39 ( V_6 -> V_38 ) ;
if ( V_6 -> V_309 )
F_79 ( V_6 , V_146 ) ;
F_213 ( V_6 ) ;
V_63 = F_167 ( V_6 ) ;
if ( V_63 )
goto V_416;
F_160 ( V_6 , V_413 | V_414 , false ) ;
V_75 = F_61 ( V_6 , V_304 ) ;
V_6 -> V_51 = ! ! ( V_75 & V_417 ) ;
F_214 ( V_6 , V_26 -> V_418 ) ;
if ( V_6 -> V_309 ) {
V_75 = F_75 ( V_6 , V_148 ) ;
V_75 |= V_419 ;
F_77 ( V_6 , V_75 , V_148 ) ;
}
V_351 = F_215 ( V_6 ) ;
V_63 = F_196 ( V_6 ) ;
if ( V_63 ) {
F_135 ( V_26 , L_25 ) ;
goto V_416;
}
F_216 ( V_6 , V_351 ) ;
F_220 ( V_6 ) ;
V_63 = F_225 ( V_6 -> V_401 , F_204 , V_420 ,
V_26 -> V_421 , V_6 ) ;
if ( V_63 < 0 ) {
F_135 ( V_26 , L_26 , V_6 -> V_401 ) ;
goto V_422;
}
V_63 = F_225 ( V_6 -> V_402 , F_200 , V_420 ,
V_26 -> V_421 , V_6 ) ;
if ( V_63 < 0 ) {
F_135 ( V_26 , L_26 , V_6 -> V_402 ) ;
goto V_423;
}
V_63 = F_226 ( V_26 ) ;
if ( V_63 ) {
F_135 ( V_26 , L_27 ) ;
goto V_424;
}
F_221 ( V_26 ) ;
return 0 ;
V_424:
F_227 ( V_6 -> V_402 , V_6 ) ;
V_423:
F_227 ( V_6 -> V_401 , V_6 ) ;
V_422:
F_193 ( V_6 ) ;
V_416:
if ( V_6 -> V_309 )
F_72 ( V_6 , V_146 ) ;
F_41 ( V_6 -> V_38 ) ;
return V_63 ;
}
static void F_228 ( struct V_37 * V_26 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
F_229 ( V_26 ) ;
F_230 ( V_6 -> V_42 ) ;
F_165 ( V_6 ) ;
F_188 ( V_6 ) ;
F_178 ( V_6 ) ;
F_231 ( & V_6 -> V_383 ) ;
V_6 -> V_425 = - 1 ;
V_6 -> V_426 = - 1 ;
V_6 -> V_427 = - 1 ;
V_6 -> V_428 = - 1 ;
}
static int F_232 ( struct V_37 * V_26 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
int V_63 ;
F_106 ( V_6 , V_429 , V_26 , L_28 ) ;
F_228 ( V_26 ) ;
F_233 ( V_6 -> V_42 ) ;
F_160 ( V_6 , V_414 , false ) ;
V_63 = F_191 ( V_6 ) ;
if ( V_63 )
return V_63 ;
F_160 ( V_6 , V_413 , false ) ;
F_118 ( V_26 ) ;
F_193 ( V_6 ) ;
F_227 ( V_6 -> V_401 , V_6 ) ;
F_227 ( V_6 -> V_402 , V_6 ) ;
if ( V_6 -> V_309 )
V_63 = F_72 ( V_6 , V_146 ) ;
F_41 ( V_6 -> V_38 ) ;
return V_63 ;
}
static void F_234 ( struct V_163 * V_33 )
{
struct V_5 * V_6 = V_33 -> V_6 ;
T_1 V_271 , V_189 , V_430 , V_431 ;
struct V_209 * V_210 ;
unsigned int V_199 ;
unsigned long V_12 ;
bool V_432 ;
if ( ! F_235 ( V_6 ) )
return;
V_210 = F_110 ( V_6 -> V_26 , V_33 -> V_202 ) ;
F_112 ( & V_33 -> V_204 , V_12 ) ;
if ( V_33 -> V_174 == V_69 ) {
V_430 = ~ F_205 ( V_6 , V_394 ) ;
V_431 = V_175 | V_433 ;
} else {
V_430 = ~ F_201 ( V_6 , V_394 ) ;
V_431 = 1 << V_33 -> V_174 ;
}
V_189 = F_34 ( V_6 , V_33 -> V_174 , V_191 ) ;
V_271 = F_34 ( V_6 , V_33 -> V_174 , V_260 ) ;
V_432 = F_133 ( V_210 ) ;
V_199 = V_33 -> V_199 ;
F_113 ( & V_33 -> V_204 , V_12 ) ;
F_70 ( V_6 , V_247 , V_6 -> V_26 , L_29
L_30
L_31
L_32
L_33
L_34
L_35 ,
V_33 -> V_174 , V_33 -> V_202 ,
V_432 ? L_36 : L_37 ,
V_430 & V_431 ? L_38 : L_39 ,
V_199 , V_33 -> V_236 ,
V_33 -> V_257 , V_271 & V_258 ,
V_33 -> V_189 , V_189 & V_192 ,
V_33 -> V_197 , V_33 -> V_166 ,
V_33 -> V_167 , V_33 -> V_168 ) ;
}
static void F_236 ( struct V_37 * V_26 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
T_1 V_308 = 0 ;
T_1 V_347 = 0 ;
unsigned int V_434 ;
F_106 ( V_6 , V_247 , V_26 , L_40 ) ;
for ( V_434 = 0 ; V_434 < V_6 -> V_11 -> V_83 ; V_434 ++ )
F_234 ( & V_6 -> V_213 [ V_434 ] ) ;
F_234 ( & V_6 -> V_213 [ V_69 ] ) ;
F_118 ( V_26 ) ;
for ( V_434 = 0 ; V_434 < V_6 -> V_11 -> V_83 ; V_434 ++ )
V_347 |= ( 1 << V_434 ) ;
V_308 = V_175 ;
F_88 ( V_6 , V_308 , V_172 ) ;
F_91 ( V_6 , V_347 , V_172 ) ;
F_237 ( V_26 ) ;
V_26 -> V_121 . V_435 ++ ;
F_238 ( V_26 ) ;
}
static inline void F_239 ( struct V_5 * V_6 ,
unsigned char * V_9 ,
int * V_74 ,
int * V_436 )
{
T_1 V_75 ;
F_62 ( V_6 , V_9 [ 0 ] << 8 | V_9 [ 1 ] ,
V_437 + ( * V_74 * 4 ) ) ;
F_62 ( V_6 , V_9 [ 2 ] << 24 | V_9 [ 3 ] << 16 |
V_9 [ 4 ] << 8 | V_9 [ 5 ] ,
V_437 + ( ( * V_74 + 1 ) * 4 ) ) ;
V_75 = F_61 ( V_6 , V_438 ) ;
V_75 |= ( 1 << ( V_439 - * V_436 ) ) ;
F_62 ( V_6 , V_75 , V_438 ) ;
* V_74 += 2 ;
( * V_436 ) ++ ;
}
static void F_240 ( struct V_37 * V_26 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
struct V_440 * V_441 ;
int V_74 , V_436 ;
T_1 V_75 ;
F_106 ( V_6 , V_141 , V_26 , L_41 , V_194 , V_26 -> V_12 ) ;
V_75 = F_61 ( V_6 , V_304 ) ;
if ( V_26 -> V_12 & V_442 ) {
V_75 |= V_443 ;
F_62 ( V_6 , V_75 , V_304 ) ;
F_62 ( V_6 , 0 , V_438 ) ;
return;
} else {
V_75 &= ~ V_443 ;
F_62 ( V_6 , V_75 , V_304 ) ;
}
if ( V_26 -> V_12 & V_444 ) {
F_192 ( V_26 , L_42 ) ;
return;
}
V_74 = 0 ;
V_436 = 0 ;
F_239 ( V_6 , V_26 -> V_445 , & V_74 , & V_436 ) ;
F_239 ( V_6 , V_26 -> V_418 , & V_74 , & V_436 ) ;
if ( F_241 ( V_26 ) > ( V_439 - V_436 ) )
return;
if ( ! F_242 ( V_26 ) )
F_243 (ha, dev)
F_239 ( V_6 , V_441 -> V_9 , & V_74 , & V_436 ) ;
if ( F_244 ( V_26 ) || F_245 ( V_26 ) >= ( V_439 - V_436 ) )
return;
F_246 (ha, dev)
F_239 ( V_6 , V_441 -> V_9 , & V_74 , & V_436 ) ;
}
static int F_247 ( struct V_37 * V_26 , void * V_108 )
{
struct V_446 * V_9 = V_108 ;
if ( F_43 ( V_26 ) )
return - V_447 ;
F_248 ( V_26 -> V_418 , V_9 -> V_448 ) ;
return 0 ;
}
static struct V_449 * F_249 ( struct V_37 * V_26 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
unsigned long V_450 = 0 , V_451 = 0 ;
unsigned long V_452 = 0 , V_453 = 0 ;
unsigned long V_295 = 0 , V_454 = 0 ;
struct V_163 * V_392 ;
struct V_169 * V_391 ;
unsigned int V_434 ;
for ( V_434 = 0 ; V_434 < V_6 -> V_11 -> V_83 ; V_434 ++ ) {
V_392 = & V_6 -> V_213 [ V_434 ] ;
V_450 += V_392 -> V_201 ;
V_451 += V_392 -> V_200 ;
}
V_392 = & V_6 -> V_213 [ V_69 ] ;
V_450 += V_392 -> V_201 ;
V_451 += V_392 -> V_200 ;
for ( V_434 = 0 ; V_434 < V_6 -> V_11 -> V_84 ; V_434 ++ ) {
V_391 = & V_6 -> V_340 [ V_434 ] ;
V_452 += V_391 -> V_201 ;
V_453 += V_391 -> V_200 ;
V_295 += V_391 -> V_279 ;
V_454 += V_391 -> V_283 ;
}
V_391 = & V_6 -> V_340 [ V_69 ] ;
V_452 += V_391 -> V_201 ;
V_453 += V_391 -> V_200 ;
V_295 += V_391 -> V_279 ;
V_454 += V_391 -> V_283 ;
V_26 -> V_121 . V_450 = V_450 ;
V_26 -> V_121 . V_451 = V_451 ;
V_26 -> V_121 . V_452 = V_452 ;
V_26 -> V_121 . V_453 = V_453 ;
V_26 -> V_121 . V_295 = V_295 ;
V_26 -> V_121 . V_455 = V_295 ;
return & V_26 -> V_121 ;
}
static void F_250 ( struct V_5 * V_6 )
{
struct V_456 * V_457 ;
T_1 V_75 ;
T_5 V_458 ;
T_6 V_459 ;
if ( F_76 ( V_6 ) || F_251 ( V_6 ) ) {
V_31 = V_460 ;
V_36 = V_461 ;
V_6 -> V_296 = V_462 ;
} else if ( F_252 ( V_6 ) ) {
V_31 = V_460 ;
V_36 = V_463 ;
V_6 -> V_296 = V_462 ;
} else if ( F_60 ( V_6 ) ) {
V_31 = V_464 ;
V_36 = V_463 ;
V_6 -> V_296 = V_465 ;
} else if ( F_17 ( V_6 ) ) {
V_31 = V_466 ;
V_36 = V_463 ;
V_6 -> V_296 = V_465 ;
}
V_6 -> V_11 = & V_456 [ V_6 -> V_89 ] ;
V_457 = V_6 -> V_11 ;
V_75 = F_19 ( V_6 , V_467 ) ;
V_458 = ( V_75 >> 24 & 0x0f ) ;
if ( V_458 == 6 )
V_458 = 5 ;
else if ( V_458 == 5 )
V_458 = 4 ;
else if ( V_458 == 0 )
V_458 = 1 ;
if ( V_458 != V_6 -> V_89 ) {
F_164 ( & V_6 -> V_195 -> V_26 ,
L_43 ,
V_458 , V_6 -> V_89 ) ;
}
F_253 ( & V_6 -> V_195 -> V_26 , L_44 V_468 ,
V_458 , ( V_75 >> 16 ) & 0x0f , V_75 & 0xffff ) ;
V_459 = V_75 & 0xffff ;
if ( F_76 ( V_6 ) ) {
if ( V_459 != 0 ) {
F_254 ( L_45 ,
V_459 ) ;
}
} else if ( V_459 == 0 || V_459 == 0x01ff ) {
F_254 ( L_46 , V_459 ) ;
return;
} else if ( ( V_459 & 0xf0 ) != 0 ) {
V_6 -> V_459 = V_459 << 8 ;
} else if ( ( V_459 & 0xff00 ) != 0 ) {
V_6 -> V_459 = V_459 ;
}
#ifdef F_12
if ( ! ( V_457 -> V_12 & V_13 ) )
F_254 ( L_47 ) ;
#endif
F_255 ( L_48
L_49
L_50
L_51
L_52
L_53
L_54 ,
V_6 -> V_89 ,
V_457 -> V_83 , V_457 -> V_358 ,
V_457 -> V_84 , V_457 -> V_367 ,
V_457 -> V_323 , V_457 -> V_324 ,
V_457 -> V_410 , V_457 -> V_250 ,
V_457 -> V_21 , V_457 -> V_469 ,
V_457 -> V_470 ,
V_457 -> V_374 , V_457 -> V_378 ,
V_457 -> V_329 ) ;
}
static int F_256 ( struct V_471 * V_195 )
{
struct V_472 * V_473 = V_195 -> V_26 . V_474 ;
struct V_475 * V_476 = V_195 -> V_26 . V_477 ;
const struct V_478 * V_479 = NULL ;
struct V_5 * V_6 ;
struct V_37 * V_26 ;
const void * V_480 ;
struct V_481 * V_28 ;
int V_482 = - V_483 ;
const char * V_484 ;
V_26 = F_257 ( sizeof( * V_6 ) , V_485 + 1 ,
V_485 + 1 ) ;
if ( ! V_26 ) {
F_164 ( & V_195 -> V_26 , L_55 ) ;
return - V_302 ;
}
if ( V_476 ) {
V_479 = F_258 ( V_486 , V_476 ) ;
if ( ! V_479 )
return - V_41 ;
}
V_6 = F_28 ( V_26 ) ;
V_6 -> V_401 = F_259 ( V_195 , 0 ) ;
V_6 -> V_402 = F_259 ( V_195 , 1 ) ;
V_6 -> V_487 = F_259 ( V_195 , 2 ) ;
if ( ! V_6 -> V_401 || ! V_6 -> V_402 ) {
F_164 ( & V_195 -> V_26 , L_56 ) ;
V_482 = - V_41 ;
goto V_482;
}
if ( V_476 ) {
V_480 = F_260 ( V_476 ) ;
if ( ! V_480 ) {
F_164 ( & V_195 -> V_26 , L_57 ) ;
V_482 = - V_41 ;
goto V_482;
}
} else {
V_480 = V_473 -> V_488 ;
}
V_28 = F_261 ( V_195 , V_489 , 0 ) ;
V_6 -> V_20 = F_262 ( & V_195 -> V_26 , V_28 ) ;
if ( F_263 ( V_6 -> V_20 ) ) {
V_482 = F_264 ( V_6 -> V_20 ) ;
goto V_482;
}
F_172 ( & V_6 -> V_204 ) ;
F_265 ( V_26 , & V_195 -> V_26 ) ;
F_266 ( & V_195 -> V_26 , V_26 ) ;
F_248 ( V_26 -> V_418 , V_480 ) ;
V_26 -> V_490 = 2 * V_491 ;
V_26 -> V_492 = & V_493 ;
V_26 -> V_494 = & V_495 ;
V_6 -> V_64 = F_267 ( - 1 , V_496 ) ;
V_26 -> V_497 |= V_498 | V_57 |
V_58 | V_47 ;
V_6 -> V_499 = true ;
V_482 = F_268 ( & V_195 -> V_26 , V_6 -> V_487 , F_208 , 0 ,
V_26 -> V_421 , V_6 ) ;
if ( ! V_482 )
F_269 ( & V_195 -> V_26 , 1 ) ;
V_26 -> V_500 += 64 ;
F_270 ( V_26 ) ;
V_6 -> V_26 = V_26 ;
V_6 -> V_195 = V_195 ;
if ( V_479 )
V_6 -> V_89 = (enum V_501 ) V_479 -> V_94 ;
else
V_6 -> V_89 = V_473 -> V_502 ;
V_6 -> V_38 = F_271 ( & V_6 -> V_195 -> V_26 , L_58 ) ;
if ( F_263 ( V_6 -> V_38 ) ) {
F_272 ( & V_6 -> V_195 -> V_26 , L_59 ) ;
V_6 -> V_38 = NULL ;
}
F_39 ( V_6 -> V_38 ) ;
F_250 ( V_6 ) ;
F_273 ( & V_6 -> V_400 ) ;
V_6 -> V_262 = V_334 ;
F_274 ( & V_6 -> V_383 , F_198 ) ;
V_6 -> V_503 = F_271 ( & V_6 -> V_195 -> V_26 , L_60 ) ;
if ( F_263 ( V_6 -> V_503 ) ) {
F_272 ( & V_6 -> V_195 -> V_26 , L_61 ) ;
V_6 -> V_503 = NULL ;
}
V_6 -> V_126 = F_271 ( & V_6 -> V_195 -> V_26 , L_62 ) ;
if ( F_263 ( V_6 -> V_126 ) ) {
F_272 ( & V_6 -> V_195 -> V_26 , L_63 ) ;
V_6 -> V_126 = NULL ;
}
if ( V_476 && ! F_275 ( V_476 , L_64 , & V_484 ) &&
! strcasecmp ( V_484 , L_65 ) )
F_79 ( V_6 , V_146 ) ;
V_482 = F_162 ( V_6 ) ;
if ( V_482 )
goto V_416;
V_482 = F_276 ( V_26 ) ;
if ( V_482 )
goto V_416;
F_277 ( V_6 -> V_26 , V_6 -> V_11 -> V_83 + 1 ) ;
F_278 ( V_6 -> V_26 , V_6 -> V_11 -> V_84 + 1 ) ;
F_279 ( V_26 ) ;
F_41 ( V_6 -> V_38 ) ;
V_482 = F_280 ( V_26 ) ;
if ( V_482 )
goto V_482;
return V_482 ;
V_416:
F_41 ( V_6 -> V_38 ) ;
V_482:
F_281 ( V_26 ) ;
return V_482 ;
}
static int F_282 ( struct V_471 * V_195 )
{
struct V_5 * V_6 = F_27 ( & V_195 -> V_26 ) ;
F_266 ( & V_195 -> V_26 , NULL ) ;
F_283 ( V_6 -> V_26 ) ;
F_284 ( V_6 -> V_26 ) ;
F_281 ( V_6 -> V_26 ) ;
return 0 ;
}
static int F_285 ( struct V_25 * V_7 )
{
struct V_37 * V_26 = F_29 ( V_7 ) ;
struct V_5 * V_6 = F_28 ( V_26 ) ;
int V_63 ;
if ( ! F_43 ( V_26 ) )
return 0 ;
F_228 ( V_26 ) ;
if ( ! F_286 ( V_7 ) )
F_287 ( V_6 -> V_42 ) ;
F_288 ( V_26 ) ;
F_160 ( V_6 , V_414 , false ) ;
V_63 = F_191 ( V_6 ) ;
if ( V_63 )
return V_63 ;
F_160 ( V_6 , V_413 , false ) ;
F_118 ( V_26 ) ;
F_193 ( V_6 ) ;
if ( F_286 ( V_7 ) && V_6 -> V_504 ) {
V_63 = F_72 ( V_6 , V_145 ) ;
F_39 ( V_6 -> V_503 ) ;
} else if ( V_6 -> V_309 ) {
V_63 = F_72 ( V_6 , V_146 ) ;
}
F_41 ( V_6 -> V_38 ) ;
return V_63 ;
}
static int F_289 ( struct V_25 * V_7 )
{
struct V_37 * V_26 = F_29 ( V_7 ) ;
struct V_5 * V_6 = F_28 ( V_26 ) ;
unsigned long V_351 ;
int V_63 ;
T_1 V_75 ;
if ( ! F_43 ( V_26 ) )
return 0 ;
V_63 = F_39 ( V_6 -> V_38 ) ;
if ( V_63 )
return V_63 ;
if ( V_6 -> V_309 )
F_79 ( V_6 , V_146 ) ;
F_213 ( V_6 ) ;
V_63 = F_167 ( V_6 ) ;
if ( V_63 )
goto V_505;
if ( V_6 -> V_504 )
F_41 ( V_6 -> V_503 ) ;
F_290 ( V_6 -> V_42 ) ;
F_291 ( V_6 -> V_26 , false ) ;
F_160 ( V_6 , V_413 | V_414 , false ) ;
F_214 ( V_6 , V_26 -> V_418 ) ;
if ( V_6 -> V_309 ) {
V_75 = F_75 ( V_6 , V_148 ) ;
V_75 |= V_419 ;
F_77 ( V_6 , V_75 , V_148 ) ;
}
if ( V_6 -> V_504 )
F_79 ( V_6 , V_145 ) ;
V_351 = F_215 ( V_6 ) ;
V_63 = F_196 ( V_6 ) ;
if ( V_63 ) {
F_135 ( V_26 , L_25 ) ;
goto V_505;
}
F_216 ( V_6 , V_351 ) ;
F_292 ( V_26 ) ;
if ( ! F_286 ( V_7 ) )
F_293 ( V_6 -> V_42 ) ;
if ( V_6 -> V_134 . V_135 )
F_65 ( V_26 , true ) ;
F_221 ( V_26 ) ;
return 0 ;
V_505:
if ( V_6 -> V_309 )
F_72 ( V_6 , V_146 ) ;
F_41 ( V_6 -> V_38 ) ;
return V_63 ;
}
