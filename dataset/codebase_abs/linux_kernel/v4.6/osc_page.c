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
F_5 ( ! V_4 -> V_11 ) ;
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
F_22 ( F_1 ( V_2 , V_4 , V_34 , 0 ) ) ;
F_6 ( V_4 , L_3 ) ;
V_33 = F_23 ( V_2 , V_30 , V_4 ) ;
if ( V_33 != 0 )
F_10 ( V_2 , V_4 ) ;
else
F_13 ( V_2 , V_4 , V_35 ) ;
if ( F_24 ( V_30 ) || F_25 ( V_30 ) ) {
if ( V_32 -> V_36 ) {
F_26 ( V_2 , V_32 -> V_36 ) ;
V_32 -> V_36 = NULL ;
}
}
return V_33 ;
}
void F_27 ( T_1 * V_37 , const struct V_38 * V_22 ,
T_2 V_39 , T_2 V_40 )
{
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_41 . V_39 = F_28 ( V_22 , V_39 ) ;
V_37 -> V_41 . V_40 = F_28 ( V_22 , V_40 + 1 ) - 1 ;
}
static int F_29 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 ;
int V_46 ;
F_5 ( ! V_4 -> V_11 ) ;
V_45 = F_30 ( V_43 ) ;
if ( F_31 ( & V_45 -> V_47 ) <= 0 ) {
F_32 ( & V_45 -> V_47 ) ;
V_46 = - V_48 ;
} else {
F_33 ( V_43 ) ;
V_4 -> V_11 = V_43 ;
V_46 = 0 ;
}
return V_46 ;
}
static void F_34 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_42 * V_43 = V_4 -> V_11 ;
struct V_44 * V_45 ;
F_5 ( V_43 ) ;
V_45 = F_30 ( V_43 ) ;
F_32 ( & V_45 -> V_47 ) ;
V_4 -> V_11 = NULL ;
F_35 ( V_2 , V_43 ) ;
}
static int F_36 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 ,
struct V_29 * V_49 )
{
struct V_42 * V_43 ;
int V_33 = - V_48 ;
V_43 = F_37 ( V_2 , V_9 -> V_23 , V_9 -> V_16 ,
NULL , 1 , 0 ) ;
if ( V_43 ) {
if ( F_29 ( V_2 , F_3 ( V_9 ) , V_43 ) == 0 )
V_33 = - V_50 ;
F_35 ( V_2 , V_43 ) ;
}
return V_33 ;
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
int V_51 )
{
struct V_3 * V_4 = F_3 ( V_9 ) ;
struct V_21 * V_22 = F_14 ( V_4 -> V_15 . V_23 ) ;
if ( F_41 ( V_4 -> V_11 ) )
F_34 ( V_2 , V_4 ) ;
F_42 ( F_16 ( V_22 ) , V_4 ) ;
}
static void F_43 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 ,
int V_51 )
{
struct V_3 * V_4 = F_3 ( V_9 ) ;
struct V_21 * V_22 = F_14 ( V_9 -> V_23 ) ;
F_42 ( F_16 ( V_22 ) , V_4 ) ;
}
static int F_44 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 ,
struct V_29 * V_49 )
{
F_45 () ;
return 0 ;
}
static const char * F_46 ( struct V_52 * V_53 )
{
return F_47 ( V_53 ) ? L_4 : L_5 ;
}
static inline unsigned long F_48 ( struct V_3 * V_4 )
{
if ( V_4 -> V_54 == 0 )
return 0 ;
return ( F_49 () - V_4 -> V_54 ) ;
}
static int F_50 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 ,
void * V_55 , T_3 V_56 )
{
struct V_3 * V_4 = F_3 ( V_9 ) ;
struct V_57 * V_58 = & V_4 -> V_59 ;
struct V_21 * V_22 = F_14 ( V_9 -> V_23 ) ;
struct V_60 * V_61 = & F_51 ( V_22 ) -> V_62 -> V_63 . V_61 ;
return (* V_56)( V_2 , V_55 , V_64 L_6 ,
V_4 ,
V_58 -> V_65 , V_58 -> V_66 ,
V_58 -> V_67 ,
F_46 ( & V_58 -> V_68 ) ,
F_46 ( & V_58 -> V_69 ) ,
V_58 -> V_70 , V_58 -> V_71 , V_58 -> V_72 ,
V_58 -> V_73 , V_58 -> V_74 ,
V_58 -> V_75 , V_58 -> V_76 , V_22 ,
F_46 ( & V_4 -> V_25 ) ,
V_4 -> V_27 , V_4 -> V_17 ,
F_48 ( V_4 ) , V_4 -> V_77 ,
V_61 -> V_78 , V_61 -> V_79 ,
V_61 -> V_80 ,
V_61 -> V_81 ,
F_46 ( & V_61 -> V_82 ) ,
F_46 ( & V_61 -> V_83 ) ,
F_46 ( & V_61 -> V_84 ) ,
F_46 ( & V_61 -> V_85 ) ,
F_46 ( & V_61 -> V_86 ) ,
F_46 ( & V_22 -> V_87 ) ,
F_46 ( & V_22 -> V_88 ) ,
F_46 ( & V_22 -> V_89 ) ,
F_46 ( & V_22 -> V_90 ) ,
F_52 ( & V_22 -> V_91 ) ,
F_46 ( & V_22 -> V_92 ) ,
F_52 ( & V_22 -> V_93 ) ,
F_46 ( & V_22 -> V_94 ) ,
F_46 ( & V_22 -> V_95 ) ) ;
}
static void F_53 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 )
{
struct V_3 * V_4 = F_3 ( V_9 ) ;
struct V_21 * V_22 = F_14 ( V_4 -> V_15 . V_23 ) ;
int V_46 ;
F_22 ( V_4 -> V_96 || F_1 ( V_2 , V_4 , V_97 , 1 ) ) ;
F_4 ( V_10 , L_1 , V_4 ) ;
F_10 ( V_2 , V_4 ) ;
V_46 = F_54 ( V_2 , V_22 , V_4 ) ;
if ( V_46 ) {
F_55 ( V_98 , V_2 , F_7 ( V_9 -> V_16 ) ,
L_7 , V_46 ) ;
F_5 ( 0 ) ;
}
F_17 ( & V_22 -> V_24 ) ;
if ( V_4 -> V_27 ) {
F_5 ( ! F_47 ( & V_4 -> V_25 ) ) ;
F_56 ( & V_4 -> V_25 ) ;
V_4 -> V_27 = NULL ;
}
F_19 ( & V_22 -> V_24 ) ;
F_15 ( F_16 ( V_22 ) , V_4 , true ) ;
}
static void F_57 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 , int V_99 , int V_100 )
{
struct V_3 * V_4 = F_3 ( V_9 ) ;
struct V_57 * V_58 = & V_4 -> V_59 ;
F_22 ( F_1 ( V_2 , V_4 , V_97 , 0 ) ) ;
V_4 -> V_101 = V_99 ;
V_4 -> V_102 = V_100 ;
F_17 ( & V_58 -> V_103 ) ;
V_58 -> V_73 |= V_104 ;
F_19 ( & V_58 -> V_103 ) ;
}
static int F_58 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 )
{
struct V_3 * V_4 = F_3 ( V_9 ) ;
int V_46 = 0 ;
F_22 ( F_1 ( V_2 , V_4 , V_97 , 0 ) ) ;
if ( V_4 -> V_17 )
V_46 = F_59 ( V_2 , V_4 ) ;
F_5 ( F_60 ( V_46 == 0 , V_4 -> V_17 == 0 ) ) ;
return V_46 ;
}
static int F_61 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 ,
struct V_29 * V_30 )
{
struct V_3 * V_4 = F_3 ( V_9 ) ;
int V_46 ;
V_46 = F_62 ( V_2 , V_30 , V_4 ) ;
return V_46 ;
}
int F_63 ( const struct V_1 * V_2 , struct V_38 * V_22 ,
struct V_13 * V_14 , struct V_14 * V_105 )
{
struct V_21 * V_106 = F_14 ( V_22 ) ;
struct V_3 * V_4 = F_64 ( V_22 , V_14 ) ;
int V_33 ;
V_4 -> V_101 = 0 ;
V_4 -> V_102 = V_107 ;
V_33 = F_65 ( V_106 , V_4 , V_105 ,
F_28 ( V_22 , V_14 -> V_108 ) ) ;
if ( V_33 == 0 ) {
struct V_31 * V_32 = F_21 ( V_2 ) ;
V_4 -> V_77 = F_66 ( V_32 ) ;
F_67 ( V_14 , & V_4 -> V_15 , V_22 , & V_109 ) ;
}
F_68 ( & V_4 -> V_25 ) ;
F_68 ( & V_4 -> V_110 ) ;
if ( V_14 -> V_111 == V_112 && V_33 == 0 )
V_33 = F_69 ( V_2 , V_106 , V_4 ) ;
return V_33 ;
}
void F_70 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_19 V_20 , int V_113 )
{
struct V_57 * V_58 = & V_4 -> V_59 ;
struct V_21 * V_22 = V_58 -> V_114 ;
F_22 ( F_1 ( V_2 , V_4 ,
V_20 == V_35 ? V_34 : V_97 , 1 ) ) ;
F_71 ( V_58 -> V_65 == V_115 , L_8 ,
V_58 , V_58 -> V_65 ) ;
F_5 ( V_58 -> V_73 & V_116 ) ;
F_5 ( V_58 -> V_73 & V_104 ) ;
V_58 -> V_66 = V_20 == V_35 ? V_117 : V_118 ;
V_58 -> V_71 = V_4 -> V_101 ;
V_58 -> V_72 = V_4 -> V_102 - V_4 -> V_101 ;
V_58 -> V_74 = V_113 | V_119 ;
if ( ! F_72 ( F_51 ( V_22 ) ) &&
F_73 ( V_120 ) ) {
V_58 -> V_74 |= V_121 ;
V_58 -> V_66 |= V_121 ;
}
V_4 -> V_54 = F_49 () ;
F_6 ( V_4 , L_9 ) ;
F_13 ( V_2 , V_4 , V_20 ) ;
}
static int F_74 ( struct V_60 * V_61 )
{
struct V_122 * V_123 = V_61 -> V_124 ;
int V_125 = F_52 ( & V_61 -> V_126 ) >> 1 ;
if ( F_52 ( & V_127 ) > 0 &&
F_52 ( V_61 -> V_128 ) < V_129 )
return F_75 ( V_125 , V_129 ) ;
if ( F_52 ( V_61 -> V_128 ) < V_123 -> V_130 >> 4 ) {
unsigned long V_131 ;
V_131 = V_123 -> V_130 / F_52 ( & V_123 -> V_132 ) ;
if ( V_125 > V_131 )
return F_75 ( V_125 , V_129 ) ;
return V_125 > V_133 ? V_133 : 0 ;
}
return 0 ;
}
static int F_76 ( const struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_13 * * V_134 , int V_135 )
{
int V_136 ;
int V_137 ;
for ( V_136 = 0 , V_137 = 0 ; V_137 < V_135 ; V_137 ++ ) {
struct V_13 * V_14 = V_134 [ V_137 ] ;
if ( F_77 ( V_2 , V_30 , V_14 ) == 0 ) {
if ( ! F_78 ( V_14 ) ) {
F_79 ( V_2 , V_30 , V_14 ) ;
F_80 ( V_2 , V_30 , V_14 ) ;
++ V_136 ;
}
F_81 ( V_2 , V_30 , V_14 ) ;
}
F_12 ( V_2 , V_14 ) ;
V_134 [ V_137 ] = NULL ;
}
return V_135 - V_136 ;
}
int F_82 ( struct V_60 * V_61 , int V_138 )
{
struct V_139 V_140 ;
struct V_1 * V_2 ;
struct V_29 * V_30 ;
struct V_38 * V_141 = NULL ;
struct V_13 * * V_134 ;
struct V_3 * V_4 ;
struct V_3 * V_142 ;
int V_143 = 0 ;
int V_136 = 0 ;
int V_144 = 0 ;
int V_46 = 0 ;
F_5 ( F_52 ( & V_61 -> V_126 ) >= 0 ) ;
if ( F_52 ( & V_61 -> V_126 ) == 0 || V_138 <= 0 )
return 0 ;
V_2 = F_83 ( & V_140 ) ;
if ( F_84 ( V_2 ) )
return F_85 ( V_2 ) ;
V_134 = F_86 ( V_2 ) -> V_145 ;
V_30 = & F_86 ( V_2 ) -> V_146 ;
F_87 ( & V_61 -> V_147 ) ;
F_88 ( & V_61 -> V_148 ) ;
V_143 = F_75 ( V_138 << 1 , F_52 ( & V_61 -> V_126 ) ) ;
F_89 (opg, temp, &cli->cl_lru_list, ops_lru) {
struct V_13 * V_14 ;
if ( -- V_143 < 0 )
break;
V_14 = F_7 ( V_4 -> V_15 . V_16 ) ;
if ( F_90 ( V_14 ) ) {
F_91 ( & V_4 -> V_110 , & V_61 -> V_149 ) ;
continue;
}
F_5 ( V_14 -> V_150 ) ;
if ( V_141 != V_14 -> V_150 ) {
struct V_38 * V_131 = V_14 -> V_150 ;
F_92 ( V_131 ) ;
F_93 ( & V_61 -> V_147 ) ;
if ( V_141 ) {
V_136 -= F_76 ( V_2 , V_30 , V_134 , V_144 ) ;
V_144 = 0 ;
F_94 ( V_2 , V_30 ) ;
F_95 ( V_2 , V_141 ) ;
V_141 = NULL ;
}
V_141 = V_131 ;
V_30 -> V_151 = V_141 ;
V_30 -> V_152 = 1 ;
V_46 = F_96 ( V_2 , V_30 , V_153 , V_141 ) ;
F_87 ( & V_61 -> V_147 ) ;
if ( V_46 != 0 )
break;
++ V_143 ;
continue;
}
F_91 ( & V_4 -> V_110 , & V_61 -> V_149 ) ;
F_8 ( V_14 ) ;
V_134 [ V_144 ++ ] = V_14 ;
if ( ++ V_136 >= V_138 )
break;
if ( F_39 ( V_144 == V_154 ) ) {
F_93 ( & V_61 -> V_147 ) ;
V_136 -= F_76 ( V_2 , V_30 , V_134 , V_144 ) ;
V_144 = 0 ;
F_87 ( & V_61 -> V_147 ) ;
}
}
F_93 ( & V_61 -> V_147 ) ;
if ( V_141 ) {
V_136 -= F_76 ( V_2 , V_30 , V_134 , V_144 ) ;
F_94 ( V_2 , V_30 ) ;
F_95 ( V_2 , V_141 ) ;
}
F_97 ( & V_140 , V_2 ) ;
F_32 ( & V_61 -> V_148 ) ;
return V_136 > 0 ? V_136 : V_46 ;
}
static void F_42 ( struct V_60 * V_61 , struct V_3 * V_4 )
{
bool V_155 = false ;
if ( ! V_4 -> V_156 )
return;
F_32 ( & V_61 -> V_157 ) ;
F_87 ( & V_61 -> V_147 ) ;
if ( F_47 ( & V_4 -> V_110 ) ) {
F_91 ( & V_4 -> V_110 , & V_61 -> V_149 ) ;
F_31 ( & V_61 -> V_126 ) ;
V_155 = F_52 ( & V_127 ) > 0 ;
}
F_93 ( & V_61 -> V_147 ) ;
if ( V_155 ) {
F_82 ( V_61 , F_74 ( V_61 ) ) ;
F_98 ( & V_158 ) ;
}
}
static void F_15 ( struct V_60 * V_61 , struct V_3 * V_4 , bool V_159 )
{
if ( V_4 -> V_156 ) {
F_87 ( & V_61 -> V_147 ) ;
if ( ! F_47 ( & V_4 -> V_110 ) ) {
F_5 ( F_52 ( & V_61 -> V_126 ) > 0 ) ;
F_56 ( & V_4 -> V_110 ) ;
F_32 ( & V_61 -> V_126 ) ;
if ( ! V_159 )
F_88 ( & V_61 -> V_157 ) ;
} else if ( V_159 ) {
F_5 ( F_52 ( & V_61 -> V_157 ) > 0 ) ;
F_32 ( & V_61 -> V_157 ) ;
}
F_93 ( & V_61 -> V_147 ) ;
if ( V_159 ) {
F_88 ( V_61 -> V_128 ) ;
if ( F_52 ( & V_61 -> V_148 ) == 0 &&
! F_99 () )
F_82 ( V_61 , F_74 ( V_61 ) ) ;
F_100 ( & V_158 ) ;
}
} else {
F_5 ( F_47 ( & V_4 -> V_110 ) ) ;
}
}
static inline int F_101 ( struct V_60 * V_61 )
{
return F_75 ( F_52 ( & V_61 -> V_126 ) >> 1 , V_129 ) ;
}
static int F_102 ( struct V_60 * V_61 )
{
struct V_122 * V_123 = V_61 -> V_124 ;
int V_160 ;
int V_46 ;
F_5 ( V_123 ) ;
V_46 = F_82 ( V_61 , V_133 ) ;
if ( V_46 != 0 ) {
F_4 ( V_161 , L_10 ,
V_61 -> V_162 -> V_163 -> V_164 , V_46 , V_61 ) ;
return V_46 ;
}
F_4 ( V_161 , L_11 ,
V_61 -> V_162 -> V_163 -> V_164 , V_61 ,
F_52 ( & V_61 -> V_126 ) ,
F_52 ( & V_61 -> V_157 ) ) ;
F_17 ( & V_123 -> V_165 ) ;
F_5 ( ! F_47 ( & V_123 -> V_166 ) ) ;
V_123 -> V_167 ++ ;
F_91 ( & V_61 -> V_168 , & V_123 -> V_166 ) ;
V_160 = F_52 ( & V_123 -> V_132 ) ;
while ( -- V_160 > 0 && ! F_47 ( & V_123 -> V_166 ) ) {
V_61 = F_103 ( V_123 -> V_166 . V_169 , struct V_60 ,
V_168 ) ;
F_4 ( V_161 , L_12 ,
V_61 -> V_162 -> V_163 -> V_164 , V_61 ,
F_52 ( & V_61 -> V_126 ) ,
F_52 ( & V_61 -> V_157 ) ) ;
F_91 ( & V_61 -> V_168 , & V_123 -> V_166 ) ;
if ( F_52 ( & V_61 -> V_126 ) > 0 ) {
F_19 ( & V_123 -> V_165 ) ;
V_46 = F_82 ( V_61 , F_101 ( V_61 ) ) ;
F_17 ( & V_123 -> V_165 ) ;
if ( V_46 != 0 )
break;
}
}
F_19 ( & V_123 -> V_165 ) ;
F_4 ( V_161 , L_13 ,
V_61 -> V_162 -> V_163 -> V_164 , V_61 , V_46 ) ;
return V_46 ;
}
static int F_69 ( const struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_3 * V_4 )
{
struct V_170 V_171 = F_104 ( V_172 , NULL ) ;
struct V_60 * V_61 = F_16 ( V_22 ) ;
int V_46 = 0 ;
if ( ! V_61 -> V_124 )
return 0 ;
F_5 ( F_52 ( V_61 -> V_128 ) >= 0 ) ;
while ( ! F_105 ( V_61 -> V_128 , - 1 , 0 ) ) {
int V_173 ;
V_46 = F_102 ( V_61 ) ;
if ( V_46 < 0 )
break;
if ( V_46 > 0 )
continue;
F_106 () ;
F_88 ( & V_127 ) ;
V_173 = F_52 ( & V_61 -> V_126 ) ;
V_46 = F_107 ( V_158 ,
F_52 ( V_61 -> V_128 ) > 0 ||
( F_52 ( & V_61 -> V_126 ) > 0 &&
V_173 != F_52 ( & V_61 -> V_126 ) ) ,
& V_171 ) ;
F_32 ( & V_127 ) ;
if ( V_46 < 0 )
break;
}
if ( V_46 >= 0 ) {
F_88 ( & V_61 -> V_157 ) ;
V_4 -> V_156 = 1 ;
V_46 = 0 ;
}
return V_46 ;
}
