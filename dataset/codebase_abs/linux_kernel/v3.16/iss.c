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
enum V_100 V_101 )
{
struct V_1 * V_2 = V_22 -> V_102 -> V_2 ;
struct V_78 * V_39 ;
struct V_103 * V_33 ;
struct V_85 * V_86 ;
unsigned long V_94 ;
int V_30 ;
if ( V_22 -> V_104 & V_2 -> V_105 )
return - V_106 ;
F_52 ( & V_22 -> V_107 , V_94 ) ;
V_22 -> V_108 &= ~ ( V_109 | V_110 ) ;
F_53 ( & V_22 -> V_107 , V_94 ) ;
V_22 -> V_111 = false ;
V_39 = & V_22 -> V_102 -> V_112 . V_39 ;
while ( 1 ) {
V_33 = & V_39 -> V_113 [ 0 ] ;
if ( ! ( V_33 -> V_94 & V_114 ) )
break;
V_33 = F_54 ( V_33 ) ;
if ( V_33 == NULL ||
F_43 ( V_33 -> V_39 ) != V_87 )
break;
V_39 = V_33 -> V_39 ;
V_86 = F_25 ( V_39 ) ;
V_30 = F_24 ( V_86 , V_112 , V_115 , V_101 ) ;
if ( V_30 < 0 && V_30 != - V_90 )
return V_30 ;
}
F_1 ( V_22 -> V_102 -> V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_102 -> V_2 ;
struct V_78 * V_39 ;
struct V_103 * V_33 ;
struct V_85 * V_86 ;
int V_116 = 0 ;
int V_30 ;
V_39 = & V_22 -> V_102 -> V_112 . V_39 ;
while ( 1 ) {
V_33 = & V_39 -> V_113 [ 0 ] ;
if ( ! ( V_33 -> V_94 & V_114 ) )
break;
V_33 = F_54 ( V_33 ) ;
if ( V_33 == NULL ||
F_43 ( V_33 -> V_39 ) != V_87 )
break;
V_39 = V_33 -> V_39 ;
V_86 = F_25 ( V_39 ) ;
V_30 = F_24 ( V_86 , V_112 , V_115 , 0 ) ;
if ( V_30 < 0 ) {
F_2 ( V_2 -> V_3 , L_69 ,
V_86 -> V_48 ) ;
V_2 -> V_105 |= 1U << V_86 -> V_39 . V_117 ;
V_116 = - V_118 ;
}
}
return V_116 ;
}
int F_56 ( struct V_21 * V_22 ,
enum V_100 V_108 )
{
int V_30 ;
if ( V_108 == V_119 )
V_30 = F_55 ( V_22 ) ;
else
V_30 = F_51 ( V_22 , V_108 ) ;
if ( V_30 == 0 || V_108 == V_119 )
V_22 -> V_120 = V_108 ;
return V_30 ;
}
void F_57 ( struct V_21 * V_22 )
{
if ( V_22 -> V_50 )
F_58 ( V_22 -> V_50 ) ;
if ( V_22 -> V_102 )
F_58 ( V_22 -> V_102 ) ;
}
static int F_59 ( struct V_78 * V_121 )
{
struct V_21 * V_22 ;
struct V_103 * V_33 ;
if ( ! V_121 -> V_22 )
return 0 ;
V_22 = F_60 ( V_121 ) ;
if ( V_22 -> V_120 == V_119 )
return 0 ;
V_33 = F_54 ( & V_22 -> V_102 -> V_33 ) ;
return V_33 -> V_39 == V_121 ;
}
static int F_61 ( struct V_1 * V_2 )
{
unsigned int V_122 ;
F_62 ( V_2 , V_9 , V_123 ,
V_124 ) ;
V_122 = F_63 (
! ( F_9 ( V_2 , V_9 , V_123 ) &
V_124 ) , 1000 , 10 , 100 ) ;
if ( V_122 ) {
F_64 ( V_2 -> V_3 , L_70 ) ;
return - V_118 ;
}
V_2 -> V_105 = 0 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
unsigned int V_122 ;
F_66 ( V_2 , V_16 , V_125 ,
V_126 ,
V_127 ) ;
F_62 ( V_2 , V_16 , V_56 , V_128 ) ;
V_122 = F_63 (
F_9 ( V_2 , V_16 , V_56 ) &
V_129 , 1000000 , 1000 , 1500 ) ;
if ( V_122 ) {
F_64 ( V_2 -> V_3 , L_71 ) ;
return - V_118 ;
}
F_62 ( V_2 , V_16 , V_125 ,
V_130 ) ;
V_122 = F_63 (
! ( F_9 ( V_2 , V_16 , V_125 ) &
V_130 ) , 1000000 , 1000 , 1500 ) ;
if ( V_122 ) {
F_64 ( V_2 -> V_3 , L_72 ) ;
return - V_118 ;
}
return 0 ;
}
int F_67 ( struct V_78 * V_121 , T_3 * V_131 ,
T_4 * V_132 )
{
struct V_21 * V_22 = F_60 ( V_121 ) ;
struct V_25 * V_112 = V_22 -> V_102 ;
unsigned long V_94 ;
if ( V_22 -> V_120 == V_119 ||
( V_22 -> V_120 == V_133 &&
! F_68 ( V_22 ) ) )
return 0 ;
F_69 ( V_132 , 1 ) ;
F_70 () ;
if ( ! F_59 ( V_121 ) )
return 0 ;
F_52 ( & V_112 -> V_134 , V_94 ) ;
if ( V_112 -> V_135 & V_136 ) {
F_53 ( & V_112 -> V_134 , V_94 ) ;
F_69 ( V_132 , 0 ) ;
F_70 () ;
return 0 ;
}
F_53 ( & V_112 -> V_134 , V_94 ) ;
if ( ! F_71 ( * V_131 , ! F_72 ( V_132 ) ,
F_73 ( 1000 ) ) ) {
F_69 ( V_132 , 0 ) ;
F_70 () ;
return - V_118 ;
}
return 0 ;
}
int F_74 ( T_3 * V_131 ,
T_4 * V_132 )
{
if ( F_75 ( V_132 , 1 , 0 ) ) {
F_76 ( V_131 ) ;
return 1 ;
}
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
T_1 V_137 = 0 ;
int V_30 = 0 , V_122 = 1000 ;
if ( V_2 -> V_138 & V_139 )
V_137 |= V_140 ;
if ( V_2 -> V_138 & V_141 )
V_137 |= V_142 ;
if ( V_2 -> V_138 & V_143 )
V_137 |= V_144 ;
F_66 ( V_2 , V_9 , V_145 ,
V_146 , V_137 ) ;
while ( -- V_122 > 0 ) {
F_78 ( 1 ) ;
if ( ( F_9 ( V_2 , V_9 , V_147 ) &
V_146 ) == V_137 )
break;
}
if ( ! V_122 )
V_30 = - V_148 ;
return V_30 ;
}
int F_79 ( struct V_1 * V_2 ,
enum V_149 V_150 )
{
V_2 -> V_138 |= V_150 ;
return F_77 ( V_2 ) ;
}
int F_80 ( struct V_1 * V_2 ,
enum V_149 V_150 )
{
V_2 -> V_138 &= ~ V_150 ;
return F_77 ( V_2 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
T_1 V_137 = 0 ;
if ( V_2 -> V_151 & V_152 )
V_137 |= V_153 ;
if ( V_2 -> V_151 & V_154 )
V_137 |= V_155 ;
if ( V_2 -> V_151 & V_156 )
V_137 |= V_157 ;
if ( V_2 -> V_151 & V_158 )
V_137 |= V_159 ;
if ( V_2 -> V_151 & V_160 )
V_137 |= V_161 ;
if ( V_137 )
V_137 |= V_162 ;
F_66 ( V_2 , V_16 , V_56 ,
V_163 , V_137 ) ;
}
void F_82 ( struct V_1 * V_2 ,
enum V_164 V_150 )
{
V_2 -> V_151 |= V_150 ;
F_81 ( V_2 ) ;
}
void F_83 ( struct V_1 * V_2 ,
enum V_164 V_150 )
{
V_2 -> V_151 &= ~ V_150 ;
F_81 ( V_2 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_30 ;
V_30 = F_85 ( V_2 -> V_165 ) ;
if ( V_30 ) {
F_64 ( V_2 -> V_3 , L_73 ) ;
return V_30 ;
}
V_30 = F_85 ( V_2 -> V_166 ) ;
if ( V_30 ) {
F_64 ( V_2 -> V_3 , L_74 ) ;
F_86 ( V_2 -> V_165 ) ;
return V_30 ;
}
return 0 ;
}
static void F_87 ( struct V_1 * V_2 )
{
F_86 ( V_2 -> V_166 ) ;
F_86 ( V_2 -> V_165 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
if ( V_2 -> V_165 ) {
F_89 ( V_2 -> V_165 ) ;
V_2 -> V_165 = NULL ;
}
if ( V_2 -> V_166 ) {
F_89 ( V_2 -> V_166 ) ;
V_2 -> V_166 = NULL ;
}
}
static int F_90 ( struct V_1 * V_2 )
{
V_2 -> V_165 = F_91 ( V_2 -> V_3 , L_75 ) ;
if ( F_92 ( V_2 -> V_165 ) ) {
F_64 ( V_2 -> V_3 , L_76 ) ;
F_88 ( V_2 ) ;
return F_93 ( V_2 -> V_165 ) ;
}
V_2 -> V_166 = F_91 ( V_2 -> V_3 , L_77 ) ;
if ( F_92 ( V_2 -> V_166 ) ) {
F_64 ( V_2 -> V_3 , L_78 ) ;
F_88 ( V_2 ) ;
return F_93 ( V_2 -> V_165 ) ;
}
return 0 ;
}
struct V_1 * F_94 ( struct V_1 * V_2 )
{
struct V_1 * V_167 = V_2 ;
if ( V_2 == NULL )
return NULL ;
F_48 ( & V_2 -> V_168 ) ;
if ( V_2 -> V_169 > 0 )
goto V_170;
if ( F_84 ( V_2 ) < 0 ) {
V_167 = NULL ;
goto V_170;
}
F_16 ( V_2 ) ;
V_170:
if ( V_167 != NULL )
V_2 -> V_169 ++ ;
F_49 ( & V_2 -> V_168 ) ;
return V_167 ;
}
void F_95 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_48 ( & V_2 -> V_168 ) ;
F_96 ( V_2 -> V_169 == 0 ) ;
if ( -- V_2 -> V_169 == 0 ) {
F_20 ( V_2 ) ;
if ( V_2 -> V_105 )
F_61 ( V_2 ) ;
F_87 ( V_2 ) ;
}
F_49 ( & V_2 -> V_168 ) ;
}
static int F_97 ( struct V_171 * V_172 ,
struct V_1 * V_2 ,
enum V_173 V_150 )
{
struct V_174 * V_175 ;
V_175 = F_98 ( V_172 , V_176 , V_150 ) ;
if ( ! V_175 ) {
F_64 ( V_2 -> V_3 , L_79 ) ;
return - V_177 ;
}
if ( ! F_99 ( V_175 -> V_178 , F_100 ( V_175 ) , V_172 -> V_48 ) ) {
F_64 ( V_2 -> V_3 ,
L_80 ) ;
return - V_177 ;
}
V_2 -> V_150 [ V_150 ] = V_175 ;
V_2 -> V_20 [ V_150 ] = F_101 ( V_175 -> V_178 , F_100 ( V_175 ) ) ;
if ( ! V_2 -> V_20 [ V_150 ] ) {
F_64 ( V_2 -> V_3 , L_81 ) ;
return - V_177 ;
}
return 0 ;
}
static void F_102 ( struct V_1 * V_2 )
{
F_103 ( & V_2 -> V_76 ) ;
F_104 ( & V_2 -> V_179 ) ;
F_105 ( & V_2 -> V_75 ) ;
F_106 ( & V_2 -> V_72 ) ;
F_106 ( & V_2 -> V_73 ) ;
F_107 ( & V_2 -> V_180 ) ;
F_108 ( & V_2 -> V_181 ) ;
}
static struct V_85 *
F_109 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
struct V_85 * V_184 = NULL ;
unsigned int V_91 ;
if ( V_183 -> V_183 == NULL )
return NULL ;
for ( V_91 = 1 ; V_183 -> V_183 ; ++ V_183 , V_91 = 0 ) {
struct V_85 * V_86 ;
struct V_185 * V_186 ;
V_186 = F_110 ( V_183 -> V_187 ) ;
if ( V_186 == NULL ) {
F_64 ( V_2 -> V_3 ,
L_82 ,
V_188 , V_183 -> V_187 ,
V_183 -> V_183 -> type ) ;
continue;
}
V_86 = F_111 ( & V_2 -> V_180 , V_186 ,
V_183 -> V_183 , NULL ) ;
if ( V_86 == NULL ) {
F_64 ( V_2 -> V_3 , L_83 ,
V_188 , V_183 -> V_183 -> type ) ;
continue;
}
if ( V_91 )
V_184 = V_86 ;
}
return V_184 ;
}
static int F_112 ( struct V_1 * V_2 )
{
struct V_189 * V_190 = V_2 -> V_190 ;
struct V_191 * V_192 ;
int V_30 ;
V_2 -> V_181 . V_3 = V_2 -> V_3 ;
F_113 ( V_2 -> V_181 . V_193 , L_84 ,
sizeof( V_2 -> V_181 . V_193 ) ) ;
V_2 -> V_181 . V_194 = V_2 -> V_195 ;
V_2 -> V_181 . V_196 = F_50 ;
V_30 = F_114 ( & V_2 -> V_181 ) ;
if ( V_30 < 0 ) {
F_64 ( V_2 -> V_3 , L_85 ,
V_188 , V_30 ) ;
return V_30 ;
}
V_2 -> V_180 . V_197 = & V_2 -> V_181 ;
V_30 = F_115 ( V_2 -> V_3 , & V_2 -> V_180 ) ;
if ( V_30 < 0 ) {
F_64 ( V_2 -> V_3 , L_86 ,
V_188 , V_30 ) ;
goto V_198;
}
V_30 = F_116 ( & V_2 -> V_72 , & V_2 -> V_180 ) ;
if ( V_30 < 0 )
goto V_198;
V_30 = F_116 ( & V_2 -> V_73 , & V_2 -> V_180 ) ;
if ( V_30 < 0 )
goto V_198;
V_30 = F_117 ( & V_2 -> V_75 , & V_2 -> V_180 ) ;
if ( V_30 < 0 )
goto V_198;
V_30 = F_118 ( & V_2 -> V_179 , & V_2 -> V_180 ) ;
if ( V_30 < 0 )
goto V_198;
V_30 = F_119 ( & V_2 -> V_76 , & V_2 -> V_180 ) ;
if ( V_30 < 0 )
goto V_198;
for ( V_192 = V_190 -> V_192 ; V_192 && V_192 -> V_192 ; ++ V_192 ) {
struct V_85 * V_184 ;
struct V_78 * V_50 ;
unsigned int V_94 ;
unsigned int V_33 ;
V_184 = F_109 ( V_2 , V_192 -> V_192 ) ;
if ( V_184 == NULL )
continue;
V_184 -> V_199 = V_192 ;
switch ( V_192 -> V_200 ) {
case V_201 :
V_50 = & V_2 -> V_72 . V_86 . V_39 ;
V_33 = V_202 ;
V_94 = V_203
| V_99 ;
break;
case V_204 :
V_50 = & V_2 -> V_73 . V_86 . V_39 ;
V_33 = V_202 ;
V_94 = V_203
| V_99 ;
break;
default:
F_64 ( V_2 -> V_3 , L_87 ,
V_188 , V_192 -> V_200 ) ;
V_30 = - V_205 ;
goto V_198;
}
V_30 = F_120 ( & V_184 -> V_39 , 0 , V_50 , V_33 ,
V_94 ) ;
if ( V_30 < 0 )
goto V_198;
}
V_30 = F_121 ( & V_2 -> V_180 ) ;
V_198:
if ( V_30 < 0 )
F_102 ( V_2 ) ;
return V_30 ;
}
static void F_122 ( struct V_1 * V_2 )
{
F_123 ( V_2 ) ;
F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
F_126 ( V_2 ) ;
}
static int F_127 ( struct V_1 * V_2 )
{
int V_30 ;
V_30 = F_128 ( V_2 ) ;
if ( V_30 < 0 ) {
F_64 ( V_2 -> V_3 , L_88 ) ;
goto V_206;
}
V_30 = F_129 ( V_2 ) ;
if ( V_30 < 0 ) {
F_64 ( V_2 -> V_3 , L_89 ) ;
goto V_207;
}
V_30 = F_130 ( V_2 ) ;
if ( V_30 < 0 ) {
F_64 ( V_2 -> V_3 , L_90 ) ;
goto V_208;
}
V_30 = F_131 ( V_2 ) ;
if ( V_30 < 0 ) {
F_64 ( V_2 -> V_3 , L_91 ) ;
goto V_209;
}
V_30 = F_132 ( V_2 ) ;
if ( V_30 < 0 ) {
F_64 ( V_2 -> V_3 , L_92 ) ;
goto V_210;
}
V_30 = F_120 (
& V_2 -> V_72 . V_86 . V_39 , V_211 ,
& V_2 -> V_75 . V_86 . V_39 , V_212 , 0 ) ;
if ( V_30 < 0 )
goto V_213;
V_30 = F_120 (
& V_2 -> V_73 . V_86 . V_39 , V_211 ,
& V_2 -> V_75 . V_86 . V_39 , V_212 , 0 ) ;
if ( V_30 < 0 )
goto V_213;
V_30 = F_120 (
& V_2 -> V_75 . V_86 . V_39 , V_214 ,
& V_2 -> V_76 . V_86 . V_39 , V_215 , 0 ) ;
if ( V_30 < 0 )
goto V_213;
V_30 = F_120 (
& V_2 -> V_75 . V_86 . V_39 , V_214 ,
& V_2 -> V_179 . V_86 . V_39 , V_216 , 0 ) ;
if ( V_30 < 0 )
goto V_213;
V_30 = F_120 (
& V_2 -> V_179 . V_86 . V_39 , V_217 ,
& V_2 -> V_76 . V_86 . V_39 , V_215 , 0 ) ;
if ( V_30 < 0 )
goto V_213;
return 0 ;
V_213:
F_126 ( V_2 ) ;
V_210:
F_125 ( V_2 ) ;
V_209:
F_124 ( V_2 ) ;
V_208:
F_123 ( V_2 ) ;
V_207:
V_206:
return V_30 ;
}
static int F_133 ( struct V_171 * V_172 )
{
struct V_189 * V_190 = V_172 -> V_3 . V_218 ;
struct V_1 * V_2 ;
unsigned int V_66 ;
int V_30 ;
if ( V_190 == NULL )
return - V_205 ;
V_2 = F_134 ( sizeof( * V_2 ) , V_219 ) ;
if ( ! V_2 ) {
F_64 ( & V_172 -> V_3 , L_93 ) ;
return - V_220 ;
}
F_135 ( & V_2 -> V_168 ) ;
V_2 -> V_3 = & V_172 -> V_3 ;
V_2 -> V_190 = V_190 ;
V_2 -> V_221 = F_136 ( 32 ) ;
V_2 -> V_3 -> V_222 = & V_2 -> V_221 ;
V_2 -> V_3 -> V_223 = F_136 ( 32 ) ;
F_137 ( V_172 , V_2 ) ;
V_30 = F_97 ( V_172 , V_2 , V_9 ) ;
if ( V_30 < 0 )
goto error;
V_30 = F_90 ( V_2 ) ;
if ( V_30 < 0 )
goto error;
if ( F_94 ( V_2 ) == NULL )
goto error;
V_30 = F_61 ( V_2 ) ;
if ( V_30 < 0 )
goto V_224;
V_2 -> V_195 = F_9 ( V_2 , V_9 , V_10 ) ;
F_138 ( V_2 -> V_3 , L_94 , V_2 -> V_195 ) ;
for ( V_66 = 1 ; V_66 < V_225 ; V_66 ++ ) {
V_30 = F_97 ( V_172 , V_2 , V_66 ) ;
if ( V_30 )
goto V_224;
}
F_66 ( V_2 , V_226 , V_227 ,
V_228 ,
18 << V_229 ) ;
V_30 = F_79 ( V_2 , V_143 ) ;
if ( V_30 < 0 )
goto V_224;
V_30 = F_65 ( V_2 ) ;
if ( V_30 < 0 )
goto V_224;
F_138 ( V_2 -> V_3 , L_95 ,
F_9 ( V_2 , V_16 , V_230 ) ) ;
V_2 -> V_231 = F_139 ( V_172 , 0 ) ;
if ( V_2 -> V_231 <= 0 ) {
F_64 ( V_2 -> V_3 , L_96 ) ;
V_30 = - V_177 ;
goto V_224;
}
if ( F_140 ( V_2 -> V_231 , F_35 , V_232 , L_97 , V_2 ) ) {
F_64 ( V_2 -> V_3 , L_98 ) ;
V_30 = - V_205 ;
goto V_224;
}
V_30 = F_127 ( V_2 ) ;
if ( V_30 < 0 )
goto V_233;
V_30 = F_112 ( V_2 ) ;
if ( V_30 < 0 )
goto V_234;
F_95 ( V_2 ) ;
return 0 ;
V_234:
F_122 ( V_2 ) ;
V_233:
F_141 ( V_2 -> V_231 , V_2 ) ;
V_224:
F_95 ( V_2 ) ;
error:
F_88 ( V_2 ) ;
for ( V_66 = 0 ; V_66 < V_225 ; V_66 ++ ) {
if ( V_2 -> V_20 [ V_66 ] ) {
F_142 ( V_2 -> V_20 [ V_66 ] ) ;
V_2 -> V_20 [ V_66 ] = NULL ;
}
if ( V_2 -> V_150 [ V_66 ] ) {
F_143 ( V_2 -> V_150 [ V_66 ] -> V_178 ,
F_100 ( V_2 -> V_150 [ V_66 ] ) ) ;
V_2 -> V_150 [ V_66 ] = NULL ;
}
}
F_137 ( V_172 , NULL ) ;
F_144 ( & V_2 -> V_168 ) ;
F_145 ( V_2 ) ;
return V_30 ;
}
static int F_146 ( struct V_171 * V_172 )
{
struct V_1 * V_2 = F_147 ( V_172 ) ;
unsigned int V_66 ;
F_102 ( V_2 ) ;
F_122 ( V_2 ) ;
F_141 ( V_2 -> V_231 , V_2 ) ;
F_88 ( V_2 ) ;
for ( V_66 = 0 ; V_66 < V_225 ; V_66 ++ ) {
if ( V_2 -> V_20 [ V_66 ] ) {
F_142 ( V_2 -> V_20 [ V_66 ] ) ;
V_2 -> V_20 [ V_66 ] = NULL ;
}
if ( V_2 -> V_150 [ V_66 ] ) {
F_143 ( V_2 -> V_150 [ V_66 ] -> V_178 ,
F_100 ( V_2 -> V_150 [ V_66 ] ) ) ;
V_2 -> V_150 [ V_66 ] = NULL ;
}
}
F_145 ( V_2 ) ;
return 0 ;
}
