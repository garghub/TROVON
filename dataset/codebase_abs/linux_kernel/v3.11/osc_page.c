static int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_5 V_6 , int V_7 )
{
return 1 ;
}
static void F_2 ( const struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = F_3 ( V_9 ) ;
F_4 ( V_10 , L_1 , V_4 ) ;
F_5 ( V_4 -> V_11 == NULL ) ;
}
static void F_6 ( struct V_3 * V_4 , const char * V_12 )
{
struct V_13 * V_14 = F_7 ( V_4 -> V_15 . V_16 ) ;
F_5 ( ! V_4 -> V_17 ) ;
F_8 ( V_14 ) ;
F_9 ( & V_14 -> V_18 , V_12 , V_14 ) ;
V_4 -> V_17 = 1 ;
}
static void F_10 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_13 * V_14 = F_7 ( V_4 -> V_15 . V_16 ) ;
if ( V_4 -> V_17 ) {
F_11 ( & V_14 -> V_18 , L_2 , V_14 ) ;
V_4 -> V_17 = 0 ;
F_12 ( V_2 , V_14 ) ;
}
}
static void F_13 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , enum V_19 V_20 )
{
struct V_21 * V_22 = F_14 ( V_4 -> V_15 . V_23 ) ;
F_15 ( F_16 ( V_22 ) , V_4 , false ) ;
F_17 ( & V_22 -> V_24 ) ;
F_18 ( & V_4 -> V_25 , & V_22 -> V_26 [ V_20 ] ) ;
V_4 -> V_27 = V_28 ;
F_19 ( & V_22 -> V_24 ) ;
}
static int F_20 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 ,
struct V_29 * V_30 )
{
struct V_31 * V_32 = F_21 ( V_2 ) ;
struct V_3 * V_4 = F_3 ( V_9 ) ;
int V_33 ;
V_34 ;
F_22 ( F_1 ( V_2 , V_4 , V_35 , 0 ) ) ;
F_6 ( V_4 , L_3 ) ;
V_33 = F_23 ( V_2 , V_30 , V_4 ) ;
if ( V_33 != 0 )
F_10 ( V_2 , V_4 ) ;
else
F_13 ( V_2 , V_4 , V_36 ) ;
if ( F_24 ( V_30 ) || F_25 ( V_30 ) ) {
if ( V_32 -> V_37 != NULL ) {
F_26 ( V_2 , V_32 -> V_37 ) ;
V_32 -> V_37 = NULL ;
}
}
RETURN ( V_33 ) ;
}
void F_27 ( T_1 * V_38 , const struct V_39 * V_22 ,
T_2 V_40 , T_2 V_41 )
{
memset ( V_38 , 0 , sizeof *V_38 ) ;
V_38 -> V_42 . V_40 = F_28 ( V_22 , V_40 ) ;
V_38 -> V_42 . V_41 = F_28 ( V_22 , V_41 + 1 ) - 1 ;
}
static int F_29 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_43 * V_44 )
{
struct V_45 * V_46 ;
int V_47 ;
F_5 ( V_4 -> V_11 == NULL ) ;
V_46 = F_30 ( V_44 ) ;
if ( F_31 ( & V_46 -> V_48 ) <= 0 ) {
F_32 ( & V_46 -> V_48 ) ;
V_47 = - V_49 ;
} else {
F_33 ( V_44 ) ;
V_4 -> V_11 = V_44 ;
V_47 = 0 ;
}
return V_47 ;
}
static void F_34 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_43 * V_44 = V_4 -> V_11 ;
struct V_45 * V_46 ;
F_5 ( V_44 != NULL ) ;
V_46 = F_30 ( V_44 ) ;
F_32 ( & V_46 -> V_48 ) ;
V_4 -> V_11 = NULL ;
F_35 ( V_2 , V_44 ) ;
}
static int F_36 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 ,
struct V_29 * V_50 )
{
struct V_43 * V_44 ;
int V_33 = - V_49 ;
V_34 ;
V_44 = F_37 ( V_2 , V_9 -> V_23 , V_9 -> V_16 ,
NULL , 1 , 0 ) ;
if ( V_44 != NULL ) {
if ( F_29 ( V_2 , F_3 ( V_9 ) , V_44 ) == 0 )
V_33 = - V_51 ;
F_35 ( V_2 , V_44 ) ;
}
RETURN ( V_33 ) ;
}
static void F_38 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 ,
struct V_29 * V_30 )
{
struct V_3 * V_4 = F_3 ( V_9 ) ;
if ( F_39 ( V_4 -> V_11 ) )
F_34 ( V_2 , V_4 ) ;
}
static void F_40 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 ,
int V_52 )
{
struct V_3 * V_4 = F_3 ( V_9 ) ;
struct V_21 * V_22 = F_14 ( V_4 -> V_15 . V_23 ) ;
if ( F_41 ( V_4 -> V_11 ) )
F_34 ( V_2 , V_4 ) ;
F_42 ( F_16 ( V_22 ) , V_4 ) ;
}
static void F_43 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 ,
int V_52 )
{
struct V_3 * V_4 = F_3 ( V_9 ) ;
struct V_21 * V_22 = F_14 ( V_9 -> V_23 ) ;
F_42 ( F_16 ( V_22 ) , V_4 ) ;
}
static int F_44 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 ,
struct V_29 * V_50 )
{
F_45 () ;
return 0 ;
}
static const char * F_46 ( struct V_53 * V_54 )
{
return F_47 ( V_54 ) ? L_4 : L_5 ;
}
static inline T_3 F_48 ( struct V_3 * V_4 )
{
if ( V_4 -> V_55 == 0 )
return 0 ;
return ( F_49 () - V_4 -> V_55 ) ;
}
static int F_50 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 ,
void * V_56 , T_4 V_57 )
{
struct V_3 * V_4 = F_3 ( V_9 ) ;
struct V_58 * V_59 = & V_4 -> V_60 ;
struct V_21 * V_22 = F_14 ( V_9 -> V_23 ) ;
struct V_61 * V_62 = & F_51 ( V_22 ) -> V_63 -> V_64 . V_62 ;
return (* V_57)( V_2 , V_56 , V_65 L_6
L_7
L_8 V_66 L_9
L_10
L_11
L_12 ,
V_4 ,
V_59 -> V_67 , V_59 -> V_68 ,
V_59 -> V_69 ,
F_46 ( & V_59 -> V_70 ) ,
F_46 ( & V_59 -> V_71 ) ,
V_59 -> V_72 , V_59 -> V_73 , V_59 -> V_74 ,
V_59 -> V_75 , V_59 -> V_76 ,
V_59 -> V_77 , V_59 -> V_78 , V_22 ,
F_46 ( & V_4 -> V_25 ) ,
V_4 -> V_27 , V_4 -> V_17 ,
F_48 ( V_4 ) , V_4 -> V_79 ,
V_62 -> V_80 , V_62 -> V_81 ,
V_62 -> V_82 ,
V_62 -> V_83 ,
F_46 ( & V_62 -> V_84 ) ,
F_46 ( & V_62 -> V_85 ) ,
F_46 ( & V_62 -> V_86 ) ,
F_46 ( & V_62 -> V_87 ) ,
F_46 ( & V_62 -> V_88 ) ,
F_46 ( & V_22 -> V_89 ) ,
F_46 ( & V_22 -> V_90 ) ,
F_46 ( & V_22 -> V_91 ) ,
F_46 ( & V_22 -> V_92 ) ,
F_52 ( & V_22 -> V_93 ) ,
F_46 ( & V_22 -> V_94 ) ,
F_52 ( & V_22 -> V_95 ) ,
F_46 ( & V_22 -> V_96 ) ,
F_46 ( & V_22 -> V_97 ) ) ;
}
static void F_53 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 )
{
struct V_3 * V_4 = F_3 ( V_9 ) ;
struct V_21 * V_22 = F_14 ( V_4 -> V_15 . V_23 ) ;
int V_47 ;
F_22 ( V_4 -> V_98 || F_1 ( V_2 , V_4 , V_99 , 1 ) ) ;
V_34 ;
F_4 ( V_10 , L_1 , V_4 ) ;
F_10 ( V_2 , V_4 ) ;
V_47 = F_54 ( V_2 , V_22 , V_4 ) ;
if ( V_47 ) {
F_55 ( V_100 , V_2 , F_7 ( V_9 -> V_16 ) ,
L_13 , V_47 ) ;
F_5 ( 0 ) ;
}
F_17 ( & V_22 -> V_24 ) ;
if ( V_4 -> V_27 != NULL ) {
F_5 ( ! F_47 ( & V_4 -> V_25 ) ) ;
F_56 ( & V_4 -> V_25 ) ;
V_4 -> V_27 = NULL ;
}
F_19 ( & V_22 -> V_24 ) ;
F_15 ( F_16 ( V_22 ) , V_4 , true ) ;
EXIT ;
}
void F_57 ( const struct V_1 * V_2 , const struct V_8 * V_9 ,
int V_101 , int V_102 )
{
struct V_3 * V_4 = F_3 ( V_9 ) ;
struct V_58 * V_59 = & V_4 -> V_60 ;
F_22 ( F_1 ( V_2 , V_4 , V_99 , 0 ) ) ;
V_4 -> V_103 = V_101 ;
V_4 -> V_104 = V_102 ;
F_17 ( & V_59 -> V_105 ) ;
V_59 -> V_75 |= V_106 ;
F_19 ( & V_59 -> V_105 ) ;
}
static int F_58 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 )
{
struct V_3 * V_4 = F_3 ( V_9 ) ;
int V_47 = 0 ;
F_22 ( F_1 ( V_2 , V_4 , V_99 , 0 ) ) ;
if ( V_4 -> V_17 )
V_47 = F_59 ( V_2 , V_4 ) ;
F_5 ( F_60 ( V_47 == 0 , V_4 -> V_17 == 0 ) ) ;
return V_47 ;
}
static int F_61 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 ,
struct V_29 * V_30 )
{
struct V_3 * V_4 = F_3 ( V_9 ) ;
int V_47 = 0 ;
V_34 ;
V_47 = F_62 ( V_2 , V_30 , V_4 ) ;
RETURN ( V_47 ) ;
}
int F_63 ( const struct V_1 * V_2 , struct V_39 * V_22 ,
struct V_13 * V_14 , struct V_14 * V_107 )
{
struct V_21 * V_108 = F_14 ( V_22 ) ;
struct V_3 * V_4 = F_64 ( V_22 , V_14 ) ;
int V_33 ;
V_4 -> V_103 = 0 ;
V_4 -> V_104 = V_109 ;
V_33 = F_65 ( V_108 , V_4 , V_107 ,
F_28 ( V_22 , V_14 -> V_110 ) ) ;
if ( V_33 == 0 ) {
struct V_31 * V_32 = F_21 ( V_2 ) ;
V_4 -> V_79 = F_66 ( V_32 ) ;
F_67 ( V_14 , & V_4 -> V_15 , V_22 ,
& V_111 ) ;
}
F_68 ( & V_4 -> V_25 ) ;
F_68 ( & V_4 -> V_112 ) ;
if ( V_14 -> V_113 == V_114 && V_33 == 0 )
V_33 = F_69 ( V_2 , V_108 , V_4 ) ;
return V_33 ;
}
void F_70 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_19 V_20 , int V_115 )
{
struct V_58 * V_59 = & V_4 -> V_60 ;
struct V_21 * V_22 = V_59 -> V_116 ;
F_22 ( F_1 ( V_2 , V_4 ,
V_20 == V_36 ? V_35 : V_99 , 1 ) ) ;
F_71 ( V_59 -> V_67 == V_117 , L_14
L_15 , V_59 , V_59 -> V_67 ) ;
F_5 ( V_59 -> V_75 & V_118 ) ;
F_5 ( V_59 -> V_75 & V_106 ) ;
V_59 -> V_68 = V_20 == V_36 ? V_119 : V_120 ;
V_59 -> V_73 = V_4 -> V_103 ;
V_59 -> V_74 = V_4 -> V_104 - V_4 -> V_103 ;
V_59 -> V_76 = V_121 | V_115 ;
if ( ! F_72 ( F_51 ( V_22 ) ) &&
F_73 ( V_122 ) ) {
V_59 -> V_76 |= V_123 ;
V_59 -> V_68 |= V_123 ;
}
V_4 -> V_55 = F_49 () ;
F_6 ( V_4 , L_16 ) ;
F_13 ( V_2 , V_4 , V_20 ) ;
}
static int F_74 ( struct V_61 * V_62 )
{
struct V_124 * V_125 = V_62 -> V_126 ;
int V_127 = F_52 ( & V_62 -> V_128 ) >> 1 ;
if ( F_52 ( & V_129 ) > 0 &&
F_52 ( V_62 -> V_130 ) < V_131 )
return F_75 ( V_127 , V_131 ) ;
if ( F_52 ( V_62 -> V_130 ) < V_125 -> V_132 >> 4 ) {
unsigned long V_133 ;
V_133 = V_125 -> V_132 / F_52 ( & V_125 -> V_134 ) ;
if ( V_127 > V_133 )
return F_75 ( V_127 , V_131 ) ;
return V_127 > V_135 ? V_135 : 0 ;
}
return 0 ;
}
static int F_76 ( const struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_13 * * V_136 , int V_137 )
{
int V_138 ;
int V_139 ;
for ( V_138 = 0 , V_139 = 0 ; V_139 < V_137 ; V_139 ++ ) {
struct V_13 * V_14 = V_136 [ V_139 ] ;
if ( F_77 ( V_2 , V_30 , V_14 ) == 0 ) {
if ( ! F_78 ( V_14 ) ) {
F_79 ( V_2 , V_30 , V_14 ) ;
F_80 ( V_2 , V_30 , V_14 ) ;
++ V_138 ;
}
F_81 ( V_2 , V_30 , V_14 ) ;
}
F_12 ( V_2 , V_14 ) ;
V_136 [ V_139 ] = NULL ;
}
return V_137 - V_138 ;
}
int F_82 ( struct V_61 * V_62 , int V_140 )
{
struct V_141 V_142 ;
struct V_1 * V_2 ;
struct V_29 * V_30 ;
struct V_39 * V_143 = NULL ;
struct V_13 * * V_136 ;
struct V_3 * V_4 ;
int V_144 = 0 ;
int V_138 = 0 ;
int V_145 = 0 ;
int V_47 = 0 ;
V_34 ;
F_5 ( F_52 ( & V_62 -> V_128 ) >= 0 ) ;
if ( F_52 ( & V_62 -> V_128 ) == 0 || V_140 <= 0 )
RETURN ( 0 ) ;
V_2 = F_83 ( & V_142 ) ;
if ( F_84 ( V_2 ) )
RETURN ( F_85 ( V_2 ) ) ;
V_136 = F_86 ( V_2 ) -> V_146 ;
V_30 = & F_86 ( V_2 ) -> V_147 ;
F_87 ( & V_62 -> V_148 ) ;
F_88 ( & V_62 -> V_149 ) ;
V_144 = F_75 ( V_140 << 1 , F_52 ( & V_62 -> V_128 ) ) ;
while ( ! F_47 ( & V_62 -> V_150 ) ) {
struct V_13 * V_14 ;
if ( -- V_144 < 0 )
break;
V_4 = F_89 ( V_62 -> V_150 . V_151 , struct V_3 ,
V_112 ) ;
V_14 = F_7 ( V_4 -> V_15 . V_16 ) ;
if ( F_90 ( V_14 ) ) {
F_91 ( & V_4 -> V_112 , & V_62 -> V_150 ) ;
continue;
}
F_5 ( V_14 -> V_152 != NULL ) ;
if ( V_143 != V_14 -> V_152 ) {
struct V_39 * V_133 = V_14 -> V_152 ;
F_92 ( V_133 ) ;
F_93 ( & V_62 -> V_148 ) ;
if ( V_143 != NULL ) {
V_138 -= F_76 ( V_2 , V_30 , V_136 , V_145 ) ;
V_145 = 0 ;
F_94 ( V_2 , V_30 ) ;
F_95 ( V_2 , V_143 ) ;
V_143 = NULL ;
}
V_143 = V_133 ;
V_30 -> V_153 = V_143 ;
V_30 -> V_154 = 1 ;
V_47 = F_96 ( V_2 , V_30 , V_155 , V_143 ) ;
F_87 ( & V_62 -> V_148 ) ;
if ( V_47 != 0 )
break;
++ V_144 ;
continue;
}
F_91 ( & V_4 -> V_112 , & V_62 -> V_150 ) ;
F_8 ( V_14 ) ;
V_136 [ V_145 ++ ] = V_14 ;
if ( ++ V_138 >= V_140 )
break;
if ( F_39 ( V_145 == V_156 ) ) {
F_93 ( & V_62 -> V_148 ) ;
V_138 -= F_76 ( V_2 , V_30 , V_136 , V_145 ) ;
V_145 = 0 ;
F_87 ( & V_62 -> V_148 ) ;
}
}
F_93 ( & V_62 -> V_148 ) ;
if ( V_143 != NULL ) {
V_138 -= F_76 ( V_2 , V_30 , V_136 , V_145 ) ;
F_94 ( V_2 , V_30 ) ;
F_95 ( V_2 , V_143 ) ;
}
F_97 ( & V_142 , V_2 ) ;
F_32 ( & V_62 -> V_149 ) ;
RETURN ( V_138 > 0 ? V_138 : V_47 ) ;
}
static void F_42 ( struct V_61 * V_62 , struct V_3 * V_4 )
{
bool V_157 = false ;
if ( ! V_4 -> V_158 )
return;
F_32 ( & V_62 -> V_159 ) ;
F_87 ( & V_62 -> V_148 ) ;
if ( F_47 ( & V_4 -> V_112 ) ) {
F_91 ( & V_4 -> V_112 , & V_62 -> V_150 ) ;
F_31 ( & V_62 -> V_128 ) ;
V_157 = F_52 ( & V_129 ) > 0 ;
}
F_93 ( & V_62 -> V_148 ) ;
if ( V_157 ) {
F_82 ( V_62 , F_74 ( V_62 ) ) ;
F_98 ( & V_160 ) ;
}
}
static void F_15 ( struct V_61 * V_62 , struct V_3 * V_4 , bool V_161 )
{
if ( V_4 -> V_158 ) {
F_87 ( & V_62 -> V_148 ) ;
if ( ! F_47 ( & V_4 -> V_112 ) ) {
F_5 ( F_52 ( & V_62 -> V_128 ) > 0 ) ;
F_56 ( & V_4 -> V_112 ) ;
F_32 ( & V_62 -> V_128 ) ;
if ( ! V_161 )
F_88 ( & V_62 -> V_159 ) ;
} else if ( V_161 ) {
F_5 ( F_52 ( & V_62 -> V_159 ) > 0 ) ;
F_32 ( & V_62 -> V_159 ) ;
}
F_93 ( & V_62 -> V_148 ) ;
if ( V_161 ) {
F_88 ( V_62 -> V_130 ) ;
if ( F_52 ( & V_62 -> V_149 ) == 0 &&
! F_99 () )
F_82 ( V_62 , F_74 ( V_62 ) ) ;
F_100 ( & V_160 ) ;
}
} else {
F_5 ( F_47 ( & V_4 -> V_112 ) ) ;
}
}
static inline int F_101 ( struct V_61 * V_62 )
{
return F_75 ( F_52 ( & V_62 -> V_128 ) >> 1 , V_131 ) ;
}
static int F_102 ( struct V_61 * V_62 )
{
struct V_124 * V_125 = V_62 -> V_126 ;
int V_162 ;
int V_47 ;
F_5 ( V_125 != NULL ) ;
F_5 ( ! F_47 ( & V_125 -> V_163 ) ) ;
V_47 = F_82 ( V_62 , V_135 ) ;
if ( V_47 != 0 ) {
F_4 ( V_164 , L_17 ,
V_62 -> V_165 -> V_166 -> V_167 , V_47 , V_62 ) ;
return V_47 ;
}
F_4 ( V_164 , L_18 ,
V_62 -> V_165 -> V_166 -> V_167 , V_62 ,
F_52 ( & V_62 -> V_128 ) ,
F_52 ( & V_62 -> V_159 ) ) ;
F_17 ( & V_125 -> V_168 ) ;
V_125 -> V_169 ++ ;
F_91 ( & V_62 -> V_170 , & V_125 -> V_163 ) ;
V_162 = F_52 ( & V_125 -> V_134 ) ;
while ( -- V_162 > 0 && ! F_47 ( & V_125 -> V_163 ) ) {
V_62 = F_89 ( V_125 -> V_163 . V_151 , struct V_61 ,
V_170 ) ;
F_4 ( V_164 , L_19 ,
V_62 -> V_165 -> V_166 -> V_167 , V_62 ,
F_52 ( & V_62 -> V_128 ) ,
F_52 ( & V_62 -> V_159 ) ) ;
F_91 ( & V_62 -> V_170 , & V_125 -> V_163 ) ;
if ( F_52 ( & V_62 -> V_128 ) > 0 ) {
F_19 ( & V_125 -> V_168 ) ;
V_47 = F_82 ( V_62 , F_101 ( V_62 ) ) ;
F_17 ( & V_125 -> V_168 ) ;
if ( V_47 != 0 )
break;
}
}
F_19 ( & V_125 -> V_168 ) ;
F_4 ( V_164 , L_20 ,
V_62 -> V_165 -> V_166 -> V_167 , V_62 , V_47 ) ;
return V_47 ;
}
static int F_69 ( const struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_3 * V_4 )
{
struct V_171 V_172 = F_103 ( V_173 , NULL ) ;
struct V_61 * V_62 = F_16 ( V_22 ) ;
int V_47 = 0 ;
V_34 ;
if ( V_62 -> V_126 == NULL )
RETURN ( 0 ) ;
F_5 ( F_52 ( V_62 -> V_130 ) >= 0 ) ;
while ( ! F_104 ( V_62 -> V_130 , - 1 , 0 ) ) {
int V_174 ;
V_47 = F_102 ( V_62 ) ;
if ( V_47 < 0 )
break;
if ( V_47 > 0 )
continue;
F_105 () ;
F_88 ( & V_129 ) ;
V_174 = F_52 ( & V_62 -> V_128 ) ;
V_47 = F_106 ( V_160 ,
F_52 ( V_62 -> V_130 ) > 0 ||
( F_52 ( & V_62 -> V_128 ) > 0 &&
V_174 != F_52 ( & V_62 -> V_128 ) ) ,
& V_172 ) ;
F_32 ( & V_129 ) ;
if ( V_47 < 0 )
break;
}
if ( V_47 >= 0 ) {
F_88 ( & V_62 -> V_159 ) ;
V_4 -> V_158 = 1 ;
V_47 = 0 ;
}
RETURN ( V_47 ) ;
}
