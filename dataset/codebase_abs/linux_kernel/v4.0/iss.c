static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , L_1 ) ;
F_3 ( V_2 , V_4 ) ;
F_3 ( V_2 , V_5 ) ;
F_3 ( V_2 , F_4 ( 5 ) ) ;
F_3 ( V_2 , F_5 ( 5 ) ) ;
F_3 ( V_2 , F_6 ( 5 ) ) ;
F_3 ( V_2 , V_6 ) ;
F_3 ( V_2 , V_7 ) ;
F_3 ( V_2 , V_8 ) ;
F_2 ( V_2 -> V_3 , L_2 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_9 , V_10 , 0 ) ;
F_9 ( V_2 , V_9 , V_10 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
static const T_1 V_11 = V_12 |
V_13 |
V_14 |
V_15 |
F_11 ( 0 ) ;
F_8 ( V_2 , V_16 , F_12 ( 0 ) , V_11 ) ;
F_8 ( V_2 , V_16 , F_13 ( 0 ) ,
V_11 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_16 , F_15 ( 0 ) , ~ 0 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
static const T_1 V_17 = V_18 | V_19
| F_17 ( 0 ) ;
F_8 ( V_2 , V_9 , F_18 ( 5 ) , V_17 ) ;
F_8 ( V_2 , V_9 , F_19 ( 5 ) , V_17 ) ;
if ( V_2 -> V_20 [ V_16 ] )
F_10 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_20 [ V_16 ] )
F_14 ( V_2 ) ;
F_8 ( V_2 , V_9 , F_21 ( 5 ) , ~ 0 ) ;
}
int F_22 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 =
F_23 ( V_22 , struct V_25 , V_22 ) -> V_2 ;
struct V_26 V_27 ;
struct V_28 * V_29 ;
int V_30 ;
if ( ! V_22 -> V_31 )
return 0 ;
if ( V_22 -> V_32 )
return 0 ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_33 = V_24 -> V_34 -> V_35 ;
V_27 . V_36 = V_37 ;
V_30 = F_24 ( F_25 ( V_24 -> V_38 -> V_39 ) ,
V_33 , V_40 , NULL , & V_27 ) ;
if ( V_30 < 0 )
return - V_41 ;
V_22 -> V_42 = F_26 ( V_27 . V_43 . V_44 ) -> V_45 ;
V_29 = F_27 ( V_22 -> V_31 -> V_46 ,
V_47 ) ;
if ( V_29 == NULL ) {
F_28 ( V_2 -> V_3 , L_3 ,
V_22 -> V_31 -> V_48 ) ;
return - V_41 ;
}
V_22 -> V_32 = F_29 ( V_29 ) ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 ,
enum V_49 V_50 )
{
T_1 V_51 ;
T_1 V_52 ;
V_51 = F_9 ( V_2 , V_9 , V_53 ) ;
V_51 &= ~ V_54 ;
V_51 &= ~ V_55 ;
V_52 = F_9 ( V_2 , V_16 , V_56 ) ;
switch ( V_50 ) {
case V_57 :
V_51 |= V_58 ;
break;
case V_59 :
V_51 |= V_60 ;
break;
default:
return;
}
V_51 |= V_61 ;
V_52 |= V_62 | V_63 |
V_64 ;
F_8 ( V_2 , V_9 , V_53 , V_51 ) ;
F_8 ( V_2 , V_16 , V_56 , V_52 ) ;
}
static void F_31 ( struct V_1 * V_2 , T_1 V_65 )
{
static const char * const V_48 [] = {
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 ,
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 ,
L_22 ,
L_23 ,
L_24 ,
L_25 ,
L_26 ,
L_27 ,
L_28 ,
L_29 ,
L_30 ,
L_31 ,
L_32 ,
L_33 ,
L_34 ,
L_35 ,
} ;
unsigned int V_66 ;
F_2 ( V_2 -> V_3 , L_36 ) ;
for ( V_66 = 0 ; V_66 < F_32 ( V_48 ) ; V_66 ++ ) {
if ( ( 1 << V_66 ) & V_65 )
F_33 ( L_37 , V_48 [ V_66 ] ) ;
}
F_33 ( L_38 ) ;
}
static void F_34 ( struct V_1 * V_2 , T_1 V_65 )
{
static const char * const V_48 [] = {
L_39 ,
L_40 ,
L_41 ,
L_42 ,
L_43 ,
L_44 ,
L_45 ,
L_46 ,
L_47 ,
L_48 ,
L_49 ,
L_50 ,
L_51 ,
L_52 ,
L_53 ,
L_54 ,
L_55 ,
L_56 ,
L_57 ,
L_58 ,
L_24 ,
L_25 ,
L_59 ,
L_60 ,
L_61 ,
L_62 ,
L_30 ,
L_63 ,
L_64 ,
L_65 ,
L_34 ,
L_66 ,
} ;
unsigned int V_66 ;
F_2 ( V_2 -> V_3 , L_67 ) ;
for ( V_66 = 0 ; V_66 < F_32 ( V_48 ) ; V_66 ++ ) {
if ( ( 1 << V_66 ) & V_65 )
F_33 ( L_37 , V_48 [ V_66 ] ) ;
}
F_33 ( L_38 ) ;
}
static T_2 F_35 ( int V_67 , void * V_68 )
{
static const T_1 V_69 = V_70 |
F_11 ( 0 ) ;
static const T_1 V_71 = V_13 |
V_14 |
V_15 ;
struct V_1 * V_2 = V_68 ;
T_1 V_65 ;
V_65 = F_9 ( V_2 , V_9 , F_18 ( 5 ) ) ;
F_8 ( V_2 , V_9 , F_18 ( 5 ) , V_65 ) ;
if ( V_65 & V_18 )
F_36 ( & V_2 -> V_72 ) ;
if ( V_65 & V_19 )
F_36 ( & V_2 -> V_73 ) ;
if ( V_65 & F_17 ( 0 ) ) {
T_1 V_74 = F_9 ( V_2 , V_16 ,
F_12 ( 0 ) ) ;
F_8 ( V_2 , V_16 , F_12 ( 0 ) ,
V_74 ) ;
if ( V_74 & V_12 )
F_2 ( V_2 -> V_3 , L_68 ) ;
if ( V_74 & V_69 ) {
F_37 ( & V_2 -> V_75 ,
V_74 & V_69 ) ;
}
if ( V_74 & V_71 )
F_38 ( & V_2 -> V_76 ,
V_74 & V_71 ) ;
#ifdef F_39
F_34 ( V_2 , V_74 ) ;
#endif
}
F_7 ( V_2 ) ;
#ifdef F_39
F_31 ( V_2 , V_65 ) ;
#endif
return V_77 ;
}
static int F_40 ( struct V_78 * V_39 )
{
struct V_79 V_80 ;
int V_81 = 0 ;
F_41 ( & V_80 , V_39 ) ;
while ( ( V_39 = F_42 ( & V_80 ) ) ) {
if ( F_43 ( V_39 ) == V_82 )
V_81 += V_39 -> V_83 ;
}
return V_81 ;
}
static int F_44 ( struct V_78 * V_39 , int V_84 )
{
struct V_85 * V_86 ;
V_86 = F_43 ( V_39 ) == V_87
? F_25 ( V_39 ) : NULL ;
if ( V_39 -> V_83 == 0 && V_84 > 0 && V_86 != NULL ) {
int V_30 ;
V_30 = F_24 ( V_86 , V_88 , V_89 , 1 ) ;
if ( V_30 < 0 && V_30 != - V_90 )
return V_30 ;
}
V_39 -> V_83 += V_84 ;
F_45 ( V_39 -> V_83 < 0 ) ;
if ( V_39 -> V_83 == 0 && V_84 < 0 && V_86 != NULL )
F_24 ( V_86 , V_88 , V_89 , 0 ) ;
return 0 ;
}
static int F_46 ( struct V_78 * V_39 , int V_84 )
{
struct V_79 V_80 ;
struct V_78 * V_91 = V_39 ;
int V_30 = 0 ;
if ( ! V_84 )
return 0 ;
F_41 ( & V_80 , V_39 ) ;
while ( ! V_30 && ( V_39 = F_42 ( & V_80 ) ) )
if ( F_43 ( V_39 ) != V_82 )
V_30 = F_44 ( V_39 , V_84 ) ;
if ( ! V_30 )
return 0 ;
F_41 ( & V_80 , V_91 ) ;
while ( ( V_91 = F_42 ( & V_80 ) )
&& V_91 != V_39 )
if ( F_43 ( V_91 ) != V_82 )
F_44 ( V_91 , - V_84 ) ;
return V_30 ;
}
int F_47 ( struct V_78 * V_39 , int V_81 )
{
int V_84 = V_81 ? 1 : - 1 ;
int V_30 ;
F_48 ( & V_39 -> V_92 -> V_93 ) ;
V_39 -> V_83 += V_84 ;
F_45 ( V_39 -> V_83 < 0 ) ;
V_30 = F_46 ( V_39 , V_84 ) ;
if ( V_30 < 0 )
V_39 -> V_83 -= V_84 ;
F_49 ( & V_39 -> V_92 -> V_93 ) ;
return V_30 ;
}
static int F_50 ( struct V_23 * V_24 , T_1 V_94 ,
unsigned int V_95 )
{
struct V_78 * V_34 = V_24 -> V_34 -> V_39 ;
struct V_78 * V_38 = V_24 -> V_38 -> V_39 ;
int V_96 = F_40 ( V_34 ) ;
int V_97 = F_40 ( V_38 ) ;
int V_30 ;
if ( V_95 == V_98 &&
! ( V_24 -> V_94 & V_99 ) ) {
F_46 ( V_34 , - V_97 ) ;
F_46 ( V_38 , - V_96 ) ;
return 0 ;
}
if ( V_95 == V_98 &&
( V_94 & V_99 ) ) {
V_30 = F_46 ( V_34 , V_97 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_46 ( V_38 , V_96 ) ;
if ( V_30 < 0 )
F_46 ( V_34 , - V_97 ) ;
return V_30 ;
}
return 0 ;
}
static int F_51 ( struct V_21 * V_22 ,
struct V_78 * V_100 )
{
struct V_1 * V_2 = V_22 -> V_101 -> V_2 ;
struct V_78 * V_39 ;
struct V_102 * V_33 ;
struct V_85 * V_86 ;
int V_103 = 0 ;
int V_30 ;
V_39 = & V_22 -> V_101 -> V_104 . V_39 ;
while ( 1 ) {
V_33 = & V_39 -> V_105 [ 0 ] ;
if ( ! ( V_33 -> V_94 & V_106 ) )
break;
V_33 = F_52 ( V_33 ) ;
if ( V_33 == NULL ||
F_43 ( V_33 -> V_39 ) != V_87 )
break;
V_39 = V_33 -> V_39 ;
if ( V_39 == V_100 )
break;
V_86 = F_25 ( V_39 ) ;
V_30 = F_24 ( V_86 , V_104 , V_107 , 0 ) ;
if ( V_30 < 0 ) {
F_2 ( V_2 -> V_3 , L_69 ,
V_86 -> V_48 ) ;
V_2 -> V_108 |= 1U << V_86 -> V_39 . V_109 ;
V_103 = - V_110 ;
}
}
return V_103 ;
}
static int F_53 ( struct V_21 * V_22 ,
enum V_111 V_112 )
{
struct V_1 * V_2 = V_22 -> V_101 -> V_2 ;
struct V_78 * V_39 ;
struct V_102 * V_33 ;
struct V_85 * V_86 ;
unsigned long V_94 ;
int V_30 ;
if ( V_22 -> V_113 & V_2 -> V_108 )
return - V_114 ;
F_54 ( & V_22 -> V_115 , V_94 ) ;
V_22 -> V_116 &= ~ ( V_117 | V_118 ) ;
F_55 ( & V_22 -> V_115 , V_94 ) ;
V_22 -> V_119 = false ;
V_39 = & V_22 -> V_101 -> V_104 . V_39 ;
while ( 1 ) {
V_33 = & V_39 -> V_105 [ 0 ] ;
if ( ! ( V_33 -> V_94 & V_106 ) )
break;
V_33 = F_52 ( V_33 ) ;
if ( V_33 == NULL ||
F_43 ( V_33 -> V_39 ) != V_87 )
break;
V_39 = V_33 -> V_39 ;
V_86 = F_25 ( V_39 ) ;
V_30 = F_24 ( V_86 , V_104 , V_107 , V_112 ) ;
if ( V_30 < 0 && V_30 != - V_90 ) {
F_51 ( V_22 , V_39 ) ;
return V_30 ;
}
if ( V_86 == & V_2 -> V_72 . V_86 ||
V_86 == & V_2 -> V_73 . V_86 )
V_22 -> V_119 = true ;
}
F_1 ( V_22 -> V_101 -> V_2 ) ;
return 0 ;
}
int F_56 ( struct V_21 * V_22 ,
enum V_111 V_116 )
{
int V_30 ;
if ( V_116 == V_120 )
V_30 = F_51 ( V_22 , NULL ) ;
else
V_30 = F_53 ( V_22 , V_116 ) ;
if ( V_30 == 0 || V_116 == V_120 )
V_22 -> V_121 = V_116 ;
return V_30 ;
}
void F_57 ( struct V_21 * V_22 )
{
if ( V_22 -> V_50 )
F_58 ( V_22 -> V_50 ) ;
if ( V_22 -> V_101 )
F_58 ( V_22 -> V_101 ) ;
}
static int F_59 ( struct V_78 * V_122 )
{
struct V_21 * V_22 ;
struct V_102 * V_33 ;
if ( ! V_122 -> V_22 )
return 0 ;
V_22 = F_60 ( V_122 ) ;
if ( V_22 -> V_121 == V_120 )
return 0 ;
V_33 = F_52 ( & V_22 -> V_101 -> V_33 ) ;
return V_33 -> V_39 == V_122 ;
}
static int F_61 ( struct V_1 * V_2 )
{
unsigned int V_123 ;
F_62 ( V_2 , V_9 , V_124 ,
V_125 ) ;
V_123 = F_63 (
! ( F_9 ( V_2 , V_9 , V_124 ) &
V_125 ) , 1000 , 10 , 100 ) ;
if ( V_123 ) {
F_64 ( V_2 -> V_3 , L_70 ) ;
return - V_110 ;
}
V_2 -> V_108 = 0 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
unsigned int V_123 ;
F_66 ( V_2 , V_16 , V_126 ,
V_127 ,
V_128 ) ;
F_62 ( V_2 , V_16 , V_56 , V_129 ) ;
V_123 = F_63 (
F_9 ( V_2 , V_16 , V_56 ) &
V_130 , 1000000 , 1000 , 1500 ) ;
if ( V_123 ) {
F_64 ( V_2 -> V_3 , L_71 ) ;
return - V_110 ;
}
F_62 ( V_2 , V_16 , V_126 ,
V_131 ) ;
V_123 = F_63 (
! ( F_9 ( V_2 , V_16 , V_126 ) &
V_131 ) , 1000000 , 1000 , 1500 ) ;
if ( V_123 ) {
F_64 ( V_2 -> V_3 , L_72 ) ;
return - V_110 ;
}
return 0 ;
}
int F_67 ( struct V_78 * V_122 , T_3 * V_132 ,
T_4 * V_133 )
{
struct V_21 * V_22 = F_60 ( V_122 ) ;
struct V_25 * V_104 = V_22 -> V_101 ;
unsigned long V_94 ;
if ( V_22 -> V_121 == V_120 ||
( V_22 -> V_121 == V_134 &&
! F_68 ( V_22 ) ) )
return 0 ;
F_69 ( V_133 , 1 ) ;
F_70 () ;
if ( ! F_59 ( V_122 ) )
return 0 ;
F_54 ( & V_104 -> V_135 , V_94 ) ;
if ( V_104 -> V_136 & V_137 ) {
F_55 ( & V_104 -> V_135 , V_94 ) ;
F_69 ( V_133 , 0 ) ;
F_70 () ;
return 0 ;
}
F_55 ( & V_104 -> V_135 , V_94 ) ;
if ( ! F_71 ( * V_132 , ! F_72 ( V_133 ) ,
F_73 ( 1000 ) ) ) {
F_69 ( V_133 , 0 ) ;
F_70 () ;
return - V_110 ;
}
return 0 ;
}
int F_74 ( T_3 * V_132 ,
T_4 * V_133 )
{
if ( F_75 ( V_133 , 1 , 0 ) ) {
F_76 ( V_132 ) ;
return 1 ;
}
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
T_1 V_138 = 0 ;
int V_30 = 0 , V_123 = 1000 ;
if ( V_2 -> V_139 & V_140 )
V_138 |= V_141 ;
if ( V_2 -> V_139 & V_142 )
V_138 |= V_143 ;
if ( V_2 -> V_139 & V_144 )
V_138 |= V_145 ;
F_66 ( V_2 , V_9 , V_146 ,
V_147 , V_138 ) ;
while ( -- V_123 > 0 ) {
F_78 ( 1 ) ;
if ( ( F_9 ( V_2 , V_9 , V_148 ) &
V_147 ) == V_138 )
break;
}
if ( ! V_123 )
V_30 = - V_149 ;
return V_30 ;
}
int F_79 ( struct V_1 * V_2 ,
enum V_150 V_151 )
{
V_2 -> V_139 |= V_151 ;
return F_77 ( V_2 ) ;
}
int F_80 ( struct V_1 * V_2 ,
enum V_150 V_151 )
{
V_2 -> V_139 &= ~ V_151 ;
return F_77 ( V_2 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
T_1 V_138 = 0 ;
if ( V_2 -> V_152 & V_153 )
V_138 |= V_154 ;
if ( V_2 -> V_152 & V_155 )
V_138 |= V_156 ;
if ( V_2 -> V_152 & V_157 )
V_138 |= V_158 ;
if ( V_2 -> V_152 & V_159 )
V_138 |= V_160 ;
if ( V_2 -> V_152 & V_161 )
V_138 |= V_162 ;
if ( V_138 )
V_138 |= V_163 ;
F_66 ( V_2 , V_16 , V_56 ,
V_164 , V_138 ) ;
}
void F_82 ( struct V_1 * V_2 ,
enum V_165 V_151 )
{
V_2 -> V_152 |= V_151 ;
F_81 ( V_2 ) ;
}
void F_83 ( struct V_1 * V_2 ,
enum V_165 V_151 )
{
V_2 -> V_152 &= ~ V_151 ;
F_81 ( V_2 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_30 ;
V_30 = F_85 ( V_2 -> V_166 ) ;
if ( V_30 ) {
F_64 ( V_2 -> V_3 , L_73 ) ;
return V_30 ;
}
V_30 = F_85 ( V_2 -> V_167 ) ;
if ( V_30 ) {
F_64 ( V_2 -> V_3 , L_74 ) ;
F_86 ( V_2 -> V_166 ) ;
return V_30 ;
}
return 0 ;
}
static void F_87 ( struct V_1 * V_2 )
{
F_86 ( V_2 -> V_167 ) ;
F_86 ( V_2 -> V_166 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
V_2 -> V_166 = F_89 ( V_2 -> V_3 , L_75 ) ;
if ( F_90 ( V_2 -> V_166 ) ) {
F_64 ( V_2 -> V_3 , L_76 ) ;
return F_91 ( V_2 -> V_166 ) ;
}
V_2 -> V_167 = F_89 ( V_2 -> V_3 , L_77 ) ;
if ( F_90 ( V_2 -> V_167 ) ) {
F_64 ( V_2 -> V_3 , L_78 ) ;
return F_91 ( V_2 -> V_167 ) ;
}
return 0 ;
}
struct V_1 * F_92 ( struct V_1 * V_2 )
{
struct V_1 * V_168 = V_2 ;
if ( V_2 == NULL )
return NULL ;
F_48 ( & V_2 -> V_169 ) ;
if ( V_2 -> V_170 > 0 )
goto V_171;
if ( F_84 ( V_2 ) < 0 ) {
V_168 = NULL ;
goto V_171;
}
F_16 ( V_2 ) ;
V_171:
if ( V_168 != NULL )
V_2 -> V_170 ++ ;
F_49 ( & V_2 -> V_169 ) ;
return V_168 ;
}
void F_93 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_48 ( & V_2 -> V_169 ) ;
F_94 ( V_2 -> V_170 == 0 ) ;
if ( -- V_2 -> V_170 == 0 ) {
F_20 ( V_2 ) ;
if ( V_2 -> V_108 )
F_61 ( V_2 ) ;
F_87 ( V_2 ) ;
}
F_49 ( & V_2 -> V_169 ) ;
}
static int F_95 ( struct V_172 * V_173 ,
struct V_1 * V_2 ,
enum V_174 V_151 )
{
struct V_175 * V_176 ;
V_176 = F_96 ( V_173 , V_177 , V_151 ) ;
V_2 -> V_20 [ V_151 ] = F_97 ( V_2 -> V_3 , V_176 ) ;
return F_98 ( V_2 -> V_20 [ V_151 ] ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
F_100 ( & V_2 -> V_76 ) ;
F_101 ( & V_2 -> V_178 ) ;
F_102 ( & V_2 -> V_75 ) ;
F_103 ( & V_2 -> V_72 ) ;
F_103 ( & V_2 -> V_73 ) ;
F_104 ( & V_2 -> V_179 ) ;
F_105 ( & V_2 -> V_180 ) ;
}
static struct V_85 *
F_106 ( struct V_1 * V_2 ,
struct V_181 * V_182 )
{
struct V_85 * V_183 = NULL ;
unsigned int V_91 ;
if ( V_182 -> V_182 == NULL )
return NULL ;
for ( V_91 = 1 ; V_182 -> V_182 ; ++ V_182 , V_91 = 0 ) {
struct V_85 * V_86 ;
struct V_184 * V_185 ;
V_185 = F_107 ( V_182 -> V_186 ) ;
if ( V_185 == NULL ) {
F_64 ( V_2 -> V_3 ,
L_79 ,
V_187 , V_182 -> V_186 ,
V_182 -> V_182 -> type ) ;
continue;
}
V_86 = F_108 ( & V_2 -> V_179 , V_185 ,
V_182 -> V_182 , NULL ) ;
if ( V_86 == NULL ) {
F_64 ( V_2 -> V_3 , L_80 ,
V_187 , V_182 -> V_182 -> type ) ;
continue;
}
if ( V_91 )
V_183 = V_86 ;
}
return V_183 ;
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_188 * V_189 = V_2 -> V_189 ;
struct V_190 * V_191 ;
int V_30 ;
V_2 -> V_180 . V_3 = V_2 -> V_3 ;
F_110 ( V_2 -> V_180 . V_192 , L_81 ,
sizeof( V_2 -> V_180 . V_192 ) ) ;
V_2 -> V_180 . V_193 = V_2 -> V_194 ;
V_2 -> V_180 . V_195 = F_50 ;
V_30 = F_111 ( & V_2 -> V_180 ) ;
if ( V_30 < 0 ) {
F_64 ( V_2 -> V_3 , L_82 ,
V_187 , V_30 ) ;
return V_30 ;
}
V_2 -> V_179 . V_196 = & V_2 -> V_180 ;
V_30 = F_112 ( V_2 -> V_3 , & V_2 -> V_179 ) ;
if ( V_30 < 0 ) {
F_64 ( V_2 -> V_3 , L_83 ,
V_187 , V_30 ) ;
goto V_197;
}
V_30 = F_113 ( & V_2 -> V_72 , & V_2 -> V_179 ) ;
if ( V_30 < 0 )
goto V_197;
V_30 = F_113 ( & V_2 -> V_73 , & V_2 -> V_179 ) ;
if ( V_30 < 0 )
goto V_197;
V_30 = F_114 ( & V_2 -> V_75 , & V_2 -> V_179 ) ;
if ( V_30 < 0 )
goto V_197;
V_30 = F_115 ( & V_2 -> V_178 , & V_2 -> V_179 ) ;
if ( V_30 < 0 )
goto V_197;
V_30 = F_116 ( & V_2 -> V_76 , & V_2 -> V_179 ) ;
if ( V_30 < 0 )
goto V_197;
for ( V_191 = V_189 -> V_191 ; V_191 && V_191 -> V_191 ; ++ V_191 ) {
struct V_85 * V_183 ;
struct V_78 * V_50 ;
unsigned int V_94 ;
unsigned int V_33 ;
V_183 = F_106 ( V_2 , V_191 -> V_191 ) ;
if ( V_183 == NULL )
continue;
V_183 -> V_198 = V_191 ;
switch ( V_191 -> V_199 ) {
case V_200 :
V_50 = & V_2 -> V_72 . V_86 . V_39 ;
V_33 = V_201 ;
V_94 = V_202
| V_99 ;
break;
case V_203 :
V_50 = & V_2 -> V_73 . V_86 . V_39 ;
V_33 = V_201 ;
V_94 = V_202
| V_99 ;
break;
default:
F_64 ( V_2 -> V_3 , L_84 ,
V_187 , V_191 -> V_199 ) ;
V_30 = - V_204 ;
goto V_197;
}
V_30 = F_117 ( & V_183 -> V_39 , 0 , V_50 , V_33 ,
V_94 ) ;
if ( V_30 < 0 )
goto V_197;
}
V_30 = F_118 ( & V_2 -> V_179 ) ;
V_197:
if ( V_30 < 0 )
F_99 ( V_2 ) ;
return V_30 ;
}
static void F_119 ( struct V_1 * V_2 )
{
F_120 ( V_2 ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
}
static int F_124 ( struct V_1 * V_2 )
{
int V_30 ;
V_30 = F_125 ( V_2 ) ;
if ( V_30 < 0 ) {
F_64 ( V_2 -> V_3 , L_85 ) ;
goto V_205;
}
V_30 = F_126 ( V_2 ) ;
if ( V_30 < 0 ) {
F_64 ( V_2 -> V_3 , L_86 ) ;
goto V_206;
}
V_30 = F_127 ( V_2 ) ;
if ( V_30 < 0 ) {
F_64 ( V_2 -> V_3 , L_87 ) ;
goto V_207;
}
V_30 = F_128 ( V_2 ) ;
if ( V_30 < 0 ) {
F_64 ( V_2 -> V_3 , L_88 ) ;
goto V_208;
}
V_30 = F_129 ( V_2 ) ;
if ( V_30 < 0 ) {
F_64 ( V_2 -> V_3 , L_89 ) ;
goto V_209;
}
V_30 = F_117 (
& V_2 -> V_72 . V_86 . V_39 , V_210 ,
& V_2 -> V_75 . V_86 . V_39 , V_211 , 0 ) ;
if ( V_30 < 0 )
goto V_212;
V_30 = F_117 (
& V_2 -> V_73 . V_86 . V_39 , V_210 ,
& V_2 -> V_75 . V_86 . V_39 , V_211 , 0 ) ;
if ( V_30 < 0 )
goto V_212;
V_30 = F_117 (
& V_2 -> V_75 . V_86 . V_39 , V_213 ,
& V_2 -> V_76 . V_86 . V_39 , V_214 , 0 ) ;
if ( V_30 < 0 )
goto V_212;
V_30 = F_117 (
& V_2 -> V_75 . V_86 . V_39 , V_213 ,
& V_2 -> V_178 . V_86 . V_39 , V_215 , 0 ) ;
if ( V_30 < 0 )
goto V_212;
V_30 = F_117 (
& V_2 -> V_178 . V_86 . V_39 , V_216 ,
& V_2 -> V_76 . V_86 . V_39 , V_214 , 0 ) ;
if ( V_30 < 0 )
goto V_212;
return 0 ;
V_212:
F_123 ( V_2 ) ;
V_209:
F_122 ( V_2 ) ;
V_208:
F_121 ( V_2 ) ;
V_207:
F_120 ( V_2 ) ;
V_206:
V_205:
return V_30 ;
}
static int F_130 ( struct V_172 * V_173 )
{
struct V_188 * V_189 = V_173 -> V_3 . V_217 ;
struct V_1 * V_2 ;
unsigned int V_66 ;
int V_30 ;
if ( V_189 == NULL )
return - V_204 ;
V_2 = F_131 ( & V_173 -> V_3 , sizeof( * V_2 ) , V_218 ) ;
if ( ! V_2 )
return - V_219 ;
F_132 ( & V_2 -> V_169 ) ;
V_2 -> V_3 = & V_173 -> V_3 ;
V_2 -> V_189 = V_189 ;
V_2 -> V_220 = F_133 ( 32 ) ;
V_2 -> V_3 -> V_221 = & V_2 -> V_220 ;
V_2 -> V_3 -> V_222 = F_133 ( 32 ) ;
F_134 ( V_173 , V_2 ) ;
V_30 = F_95 ( V_173 , V_2 , V_9 ) ;
if ( V_30 < 0 )
goto error;
V_30 = F_88 ( V_2 ) ;
if ( V_30 < 0 )
goto error;
if ( F_92 ( V_2 ) == NULL )
goto error;
V_30 = F_61 ( V_2 ) ;
if ( V_30 < 0 )
goto V_223;
V_2 -> V_194 = F_9 ( V_2 , V_9 , V_10 ) ;
F_135 ( V_2 -> V_3 , L_90 , V_2 -> V_194 ) ;
for ( V_66 = 1 ; V_66 < V_224 ; V_66 ++ ) {
V_30 = F_95 ( V_173 , V_2 , V_66 ) ;
if ( V_30 )
goto V_223;
}
F_66 ( V_2 , V_225 , V_226 ,
V_227 ,
18 << V_228 ) ;
V_30 = F_79 ( V_2 , V_144 ) ;
if ( V_30 < 0 )
goto V_223;
V_30 = F_65 ( V_2 ) ;
if ( V_30 < 0 )
goto V_223;
F_135 ( V_2 -> V_3 , L_91 ,
F_9 ( V_2 , V_16 , V_229 ) ) ;
V_2 -> V_230 = F_136 ( V_173 , 0 ) ;
if ( V_2 -> V_230 <= 0 ) {
F_64 ( V_2 -> V_3 , L_92 ) ;
V_30 = - V_231 ;
goto V_223;
}
if ( F_137 ( V_2 -> V_3 , V_2 -> V_230 , F_35 , V_232 ,
L_93 , V_2 ) ) {
F_64 ( V_2 -> V_3 , L_94 ) ;
V_30 = - V_204 ;
goto V_223;
}
V_30 = F_124 ( V_2 ) ;
if ( V_30 < 0 )
goto V_223;
V_30 = F_109 ( V_2 ) ;
if ( V_30 < 0 )
goto V_233;
F_93 ( V_2 ) ;
return 0 ;
V_233:
F_119 ( V_2 ) ;
V_223:
F_93 ( V_2 ) ;
error:
F_134 ( V_173 , NULL ) ;
F_138 ( & V_2 -> V_169 ) ;
return V_30 ;
}
static int F_139 ( struct V_172 * V_173 )
{
struct V_1 * V_2 = F_140 ( V_173 ) ;
F_99 ( V_2 ) ;
F_119 ( V_2 ) ;
return 0 ;
}
