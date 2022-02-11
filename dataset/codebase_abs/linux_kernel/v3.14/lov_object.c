static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 )
{
}
static int F_2 ( const struct V_1 * V_2 ,
struct V_7 * V_8 , struct V_3 * V_4 ,
const struct V_9 * V_10 ,
union V_5 * V_6 )
{
return 0 ;
}
static void F_3 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 )
{
}
static struct V_11 * F_4 ( const struct V_1 * V_2 ,
struct V_12 * V_8 ,
const struct V_13 * V_14 ,
const struct V_9 * V_10 )
{
struct V_15 * V_16 ;
V_16 = F_5 ( V_2 , F_6 ( V_8 ) , V_14 , & V_10 -> V_17 ) ;
F_7 ( F_8 ( ! F_9 ( V_16 ) , V_16 -> V_18 -> V_19 == & V_20 ) ) ;
return F_10 ( V_16 ) ;
}
static int F_11 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_11 * V_21 ,
struct V_22 * V_23 , int V_24 )
{
struct V_25 * V_26 ;
struct V_25 * V_27 ;
struct V_25 * V_28 ;
struct V_29 * V_30 ;
int V_31 ;
if ( F_12 ( V_32 ) ) {
F_13 ( V_2 , V_21 ) ;
F_14 ( V_2 , V_21 ) ;
return - V_33 ;
}
V_26 = V_25 ( F_15 ( V_4 ) ) ;
V_27 = V_25 ( V_21 ) ;
V_28 = V_27 -> V_34 ;
V_30 = V_4 -> V_35 -> V_36 [ V_24 ] ;
F_16 ( V_37 , V_38 L_1 V_38 L_2 V_39
L_3 ,
F_17 ( & V_27 -> V_40 . V_41 ) , V_27 , V_24 ,
F_17 ( & V_26 -> V_40 . V_41 ) , V_26 , F_18 ( & V_30 -> V_42 ) ,
V_30 -> V_43 , V_30 -> V_44 ) ;
if ( V_28 == NULL ) {
V_27 -> V_34 = V_26 ;
V_27 -> V_45 = V_26 -> V_45 + 1 ;
F_19 ( & V_21 -> V_46 , L_4 , V_4 ) ;
V_23 -> V_47 [ V_24 ] = F_20 ( V_21 ) ;
V_23 -> V_47 [ V_24 ] -> V_48 = V_4 ;
V_23 -> V_47 [ V_24 ] -> V_49 = V_24 ;
V_31 = 0 ;
} else {
struct V_15 * V_50 ;
struct V_3 * V_51 ;
unsigned int V_52 = V_37 ;
V_50 = F_21 ( & V_28 -> V_40 , & V_53 ) ;
F_7 ( V_50 != NULL ) ;
V_51 = F_22 ( F_10 ( V_50 ) ) ;
if ( V_51 -> V_54 ) {
F_23 ( V_2 , & V_21 -> V_46 ) ;
V_31 = - V_55 ;
} else {
V_52 = V_56 ;
V_31 = - V_33 ;
}
F_24 ( V_52 , V_2 , & V_21 -> V_46 ,
L_5 , V_24 ) ;
F_24 ( V_52 , V_2 , V_50 , L_6 ) ;
F_25 ( V_52 , V_2 , F_26 ( V_4 ) , L_7 ) ;
F_14 ( V_2 , V_21 ) ;
}
return V_31 ;
}
static int F_27 ( const struct V_1 * V_2 ,
struct V_7 * V_8 , struct V_3 * V_4 ,
const struct V_9 * V_10 ,
union V_5 * V_6 )
{
int V_31 ;
int V_57 ;
struct V_11 * V_21 ;
struct V_58 * V_59 = F_28 ( V_2 ) ;
struct V_9 * V_60 = & V_59 -> V_61 ;
struct V_62 * V_63 = V_10 -> V_64 . V_65 -> V_63 ;
struct V_13 * V_66 = & V_59 -> V_67 ;
struct V_22 * V_23 = & V_6 -> V_68 ;
if ( V_63 -> V_69 != V_70 && V_63 -> V_69 != V_71 ) {
F_29 ( V_56 , V_63 ) ;
F_30 ( 0 , L_8 ,
V_70 , V_71 , V_63 -> V_69 ) ;
}
F_7 ( V_4 -> V_35 == NULL ) ;
V_4 -> V_35 = F_31 ( V_63 ) ;
V_23 -> V_72 = V_63 -> V_73 ;
F_7 ( V_23 -> V_72 <= F_32 ( V_8 ) ) ;
F_33 ( V_23 -> V_47 , V_23 -> V_72 * sizeof( V_23 -> V_47 [ 0 ] ) ) ;
if ( V_23 -> V_47 != NULL ) {
V_31 = 0 ;
V_60 -> V_74 = V_10 -> V_74 ;
F_34 ( & V_23 -> V_75 ) ;
for ( V_57 = 0 ; V_57 < V_23 -> V_72 && V_31 == 0 ; ++ V_57 ) {
struct V_12 * V_76 ;
struct V_29 * V_30 = V_63 -> V_36 [ V_57 ] ;
int V_77 = V_30 -> V_43 ;
V_31 = F_35 ( V_66 , & V_30 -> V_42 ,
V_30 -> V_43 ) ;
if ( V_31 != 0 )
GOTO ( V_78 , V_31 ) ;
V_76 = F_36 ( V_8 -> V_79 [ V_77 ] ) ;
V_60 -> V_64 . V_80 = V_30 ;
F_30 ( V_76 != NULL , L_9 , V_77 ) ;
V_21 = F_4 ( V_2 , V_76 , V_66 , V_60 ) ;
if ( ! F_9 ( V_21 ) ) {
V_31 = F_11 ( V_2 , V_4 , V_21 , V_23 , V_57 ) ;
if ( V_31 == - V_55 ) {
-- V_57 ;
V_31 = 0 ;
}
} else {
V_31 = F_37 ( V_21 ) ;
}
}
} else
V_31 = - V_81 ;
V_78:
return V_31 ;
}
static int F_38 ( const struct V_1 * V_2 ,
struct V_7 * V_8 , struct V_3 * V_4 ,
const struct V_9 * V_10 ,
union V_5 * V_6 )
{
struct V_62 * V_63 = V_10 -> V_64 . V_65 -> V_63 ;
F_7 ( V_63 != NULL ) ;
F_7 ( F_39 ( V_63 ) ) ;
F_7 ( V_4 -> V_35 == NULL ) ;
V_4 -> V_35 = F_31 ( V_63 ) ;
return 0 ;
}
static int F_40 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 )
{
F_7 ( V_4 -> V_82 == V_83 || V_4 -> V_82 == V_84 ) ;
F_41 ( V_2 , V_4 ) ;
F_42 ( V_2 , & V_4 -> V_85 ) ;
return 0 ;
}
static void F_43 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_86 * V_87 , int V_24 )
{
struct V_11 * V_88 ;
struct V_22 * V_23 ;
struct V_89 * V_90 ;
struct V_91 * V_92 ;
T_1 * V_93 ;
V_23 = & V_4 -> V_64 . V_68 ;
F_7 ( V_23 -> V_47 [ V_24 ] == V_87 ) ;
V_88 = F_44 ( V_87 ) ;
V_90 = V_88 -> V_46 . V_18 -> V_94 ;
V_92 = F_45 ( V_90 , & V_88 -> V_46 . V_95 -> V_41 ) ;
F_13 ( V_2 , V_88 ) ;
F_46 ( & V_88 -> V_46 , L_4 , V_4 ) ;
F_14 ( V_2 , V_88 ) ;
if ( V_23 -> V_47 [ V_24 ] == V_87 ) {
V_93 = & F_28 ( V_2 ) -> V_96 ;
F_47 ( V_93 ) ;
F_48 ( & V_92 -> V_97 , V_93 ) ;
F_49 ( V_98 ) ;
while ( 1 ) {
F_49 ( V_98 ) ;
F_50 ( & V_23 -> V_75 ) ;
if ( V_23 -> V_47 [ V_24 ] == V_87 ) {
F_51 ( & V_23 -> V_75 ) ;
F_52 ( V_93 , V_98 ) ;
} else {
F_51 ( & V_23 -> V_75 ) ;
F_49 ( V_99 ) ;
break;
}
}
F_53 ( & V_92 -> V_97 , V_93 ) ;
}
F_7 ( V_23 -> V_47 [ V_24 ] == NULL ) ;
}
static int F_54 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 )
{
struct V_22 * V_23 = & V_6 -> V_68 ;
struct V_62 * V_63 = V_4 -> V_35 ;
int V_57 ;
F_29 ( V_37 , V_63 ) ;
F_41 ( V_2 , V_4 ) ;
if ( V_23 -> V_47 != NULL ) {
for ( V_57 = 0 ; V_57 < V_23 -> V_72 ; ++ V_57 ) {
struct V_86 * V_87 = V_23 -> V_47 [ V_57 ] ;
if ( V_87 != NULL ) {
F_55 ( V_2 , & V_87 -> V_100 , 1 ) ;
F_43 ( V_2 , V_4 , V_87 , V_57 ) ;
}
}
}
F_42 ( V_2 , & V_4 -> V_85 ) ;
return 0 ;
}
static void F_56 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 )
{
F_7 ( V_4 -> V_82 == V_83 || V_4 -> V_82 == V_84 ) ;
}
static void F_57 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 )
{
struct V_22 * V_23 = & V_6 -> V_68 ;
if ( V_23 -> V_47 != NULL ) {
F_58 ( V_23 -> V_47 , V_23 -> V_72 * sizeof( V_23 -> V_47 [ 0 ] ) ) ;
V_23 -> V_47 = NULL ;
}
F_29 ( V_37 , V_4 -> V_35 ) ;
F_59 ( & V_4 -> V_35 ) ;
}
static void F_60 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 )
{
F_29 ( V_37 , V_4 -> V_35 ) ;
F_59 ( & V_4 -> V_35 ) ;
}
static int F_61 ( const struct V_1 * V_2 , void * V_101 ,
T_2 V_102 , const struct V_15 * V_16 )
{
(* V_102)( V_2 , V_101 , L_10 , F_62 ( V_16 ) -> V_54 ) ;
return 0 ;
}
static int F_63 ( const struct V_1 * V_2 , void * V_101 ,
T_2 V_102 , const struct V_15 * V_16 )
{
struct V_3 * V_4 = F_62 ( V_16 ) ;
struct V_22 * V_23 = F_64 ( V_4 ) ;
struct V_62 * V_63 = V_4 -> V_35 ;
int V_57 ;
(* V_102)( V_2 , V_101 , L_11 ,
V_23 -> V_72 , V_4 -> V_54 ? L_12 : L_13 , V_63 ,
V_63 -> V_69 , F_65 ( & V_63 -> V_103 ) ,
V_63 -> V_73 , V_63 -> V_104 ) ;
for ( V_57 = 0 ; V_57 < V_23 -> V_72 ; ++ V_57 ) {
struct V_15 * V_88 ;
if ( V_23 -> V_47 [ V_57 ] != NULL ) {
V_88 = F_66 ( V_23 -> V_47 [ V_57 ] ) ;
F_67 ( V_2 , V_101 , V_102 , V_88 ) ;
} else {
(* V_102)( V_2 , V_101 , L_14 , V_57 ) ;
}
}
return 0 ;
}
static int F_68 ( const struct V_1 * V_2 , void * V_101 ,
T_2 V_102 , const struct V_15 * V_16 )
{
struct V_3 * V_4 = F_62 ( V_16 ) ;
struct V_62 * V_63 = V_4 -> V_35 ;
(* V_102)( V_2 , V_101 ,
L_15 ,
V_4 -> V_54 ? L_12 : L_13 , V_63 ,
V_63 -> V_69 , F_65 ( & V_63 -> V_103 ) ,
V_63 -> V_73 , V_63 -> V_104 ) ;
return 0 ;
}
static int F_69 ( const struct V_1 * V_2 , struct V_11 * V_105 ,
struct V_106 * V_107 )
{
V_107 -> V_108 = 0 ;
return 0 ;
}
static int F_70 ( const struct V_1 * V_2 , struct V_11 * V_105 ,
struct V_106 * V_107 )
{
struct V_3 * V_4 = F_22 ( V_105 ) ;
struct V_22 * V_23 = F_64 ( V_4 ) ;
struct V_106 * V_109 = & V_23 -> V_110 ;
int V_31 = 0 ;
if ( ! V_23 -> V_111 ) {
struct V_62 * V_63 = V_4 -> V_35 ;
struct V_112 * V_113 = & F_28 ( V_2 ) -> V_114 ;
T_3 V_115 = 0 ;
memset ( V_113 , 0 , sizeof( * V_113 ) ) ;
V_113 -> V_116 = V_117 ;
V_113 -> V_118 = V_117 ;
V_113 -> V_119 = V_117 ;
F_71 ( V_63 ) ;
V_31 = F_72 ( V_63 , V_113 , & V_115 ) ;
F_73 ( V_63 ) ;
if ( V_31 == 0 ) {
F_74 ( V_109 , V_113 ) ;
V_109 -> V_120 = V_115 ;
V_23 -> V_111 = 1 ;
}
}
if ( V_31 == 0 ) {
V_107 -> V_108 = V_109 -> V_108 ;
V_107 -> V_121 = V_109 -> V_121 ;
V_107 -> V_120 = V_109 -> V_120 ;
if ( V_107 -> V_122 < V_109 -> V_122 )
V_107 -> V_122 = V_109 -> V_122 ;
if ( V_107 -> V_123 < V_109 -> V_123 )
V_107 -> V_123 = V_109 -> V_123 ;
if ( V_107 -> V_124 < V_109 -> V_124 )
V_107 -> V_124 = V_109 -> V_124 ;
}
return V_31 ;
}
enum V_125 F_75 ( struct V_62 * V_63 )
{
if ( V_63 == NULL )
return V_83 ;
if ( F_39 ( V_63 ) )
return V_84 ;
return V_126 ;
}
static inline void F_76 ( struct V_3 * V_4 )
{
if ( V_4 -> V_127 != V_128 )
F_77 ( & V_4 -> V_129 ) ;
}
static inline void F_78 ( struct V_3 * V_4 )
{
if ( V_4 -> V_127 != V_128 )
F_79 ( & V_4 -> V_129 ) ;
}
static void F_80 ( struct V_3 * V_4 )
{
F_7 ( V_4 -> V_127 != V_128 ) ;
F_81 ( & V_4 -> V_129 ) ;
F_7 ( V_4 -> V_127 == NULL ) ;
V_4 -> V_127 = V_128 ;
}
static void F_82 ( struct V_3 * V_4 )
{
V_4 -> V_127 = NULL ;
F_83 ( & V_4 -> V_129 ) ;
}
static int F_41 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_130 V_131 = { 0 } ;
while ( F_65 ( & V_4 -> V_132 ) > 0 ) {
F_16 ( V_37 , L_16 V_38 L_17 ,
F_17 ( F_84 ( F_26 ( V_4 ) ) ) ,
F_65 ( & V_4 -> V_132 ) ) ;
F_85 ( V_4 -> V_133 ,
F_65 ( & V_4 -> V_132 ) == 0 , & V_131 ) ;
}
return 0 ;
}
static int F_86 ( const struct V_1 * V_134 ,
struct V_3 * V_4 ,
const struct V_9 * V_10 )
{
int V_31 ;
enum V_125 V_135 = V_83 ;
union V_5 * V_6 = & V_4 -> V_64 ;
const struct V_136 * V_137 ;
const struct V_136 * V_138 ;
struct V_25 * V_26 = V_25 ( & V_4 -> V_85 ) ;
void * V_101 ;
struct V_1 * V_2 ;
int V_139 ;
F_7 ( 0 <= V_4 -> V_82 && V_4 -> V_82 < F_87 ( V_140 ) ) ;
if ( V_10 -> V_64 . V_65 != NULL )
V_135 = F_75 ( V_10 -> V_64 . V_65 -> V_63 ) ;
F_7 ( 0 <= V_135 && V_135 < F_87 ( V_140 ) ) ;
V_101 = F_88 () ;
V_2 = F_89 ( & V_139 ) ;
if ( F_9 ( V_2 ) ) {
F_90 ( V_101 ) ;
return F_37 ( V_2 ) ;
}
F_16 ( V_37 , V_38 L_18 ,
F_17 ( F_84 ( F_26 ( V_4 ) ) ) ,
F_91 ( V_4 -> V_82 ) , F_91 ( V_135 ) ) ;
V_137 = & V_140 [ V_4 -> V_82 ] ;
V_138 = & V_140 [ V_135 ] ;
V_31 = V_137 -> V_141 ( V_2 , V_4 , & V_4 -> V_64 ) ;
if ( V_31 == 0 ) {
V_137 -> V_142 ( V_2 , V_4 , & V_4 -> V_64 ) ;
F_7 ( F_65 ( & V_4 -> V_132 ) == 0 ) ;
F_7 ( V_26 -> V_143 . V_144 == NULL ) ;
F_7 ( V_26 -> V_145 == 0 ) ;
V_4 -> V_82 = V_83 ;
V_31 = V_138 -> V_146 ( V_2 ,
F_92 ( V_4 -> V_85 . V_46 . V_18 ) ,
V_4 , V_10 , V_6 ) ;
if ( V_31 == 0 ) {
V_138 -> V_147 ( V_2 , V_4 , V_6 ) ;
V_4 -> V_82 = V_135 ;
} else {
V_138 -> V_141 ( V_2 , V_4 , V_6 ) ;
V_138 -> V_142 ( V_2 , V_4 , V_6 ) ;
}
}
F_93 ( V_2 , & V_139 ) ;
F_90 ( V_101 ) ;
return V_31 ;
}
int F_94 ( const struct V_1 * V_2 , struct V_15 * V_105 ,
const struct V_148 * V_10 )
{
struct V_7 * V_8 = F_92 ( V_105 -> V_18 ) ;
struct V_3 * V_4 = F_62 ( V_105 ) ;
const struct V_9 * V_149 = F_95 ( V_10 ) ;
union V_5 * V_150 = & V_4 -> V_64 ;
const struct V_136 * V_151 ;
int V_31 ;
F_96 ( & V_4 -> V_129 ) ;
F_97 ( & V_4 -> V_132 , 0 ) ;
F_98 ( & V_4 -> V_133 ) ;
F_99 ( F_10 ( V_105 ) , sizeof( struct V_152 ) ) ;
V_4 -> V_82 = F_75 ( V_149 -> V_64 . V_65 -> V_63 ) ;
V_151 = & V_140 [ V_4 -> V_82 ] ;
V_31 = V_151 -> V_146 ( V_2 , V_8 , V_4 , V_149 , V_150 ) ;
if ( V_31 == 0 )
V_151 -> V_147 ( V_2 , V_4 , V_150 ) ;
return V_31 ;
}
static int F_100 ( const struct V_1 * V_2 , struct V_11 * V_105 ,
const struct V_9 * V_10 )
{
struct V_62 * V_63 = NULL ;
struct V_3 * V_4 = F_22 ( V_105 ) ;
int V_31 = 0 ;
F_80 ( V_4 ) ;
if ( V_10 -> V_153 == V_154 ) {
V_4 -> V_54 = true ;
GOTO ( V_78 , V_31 = 0 ) ;
}
if ( V_10 -> V_153 == V_155 ) {
if ( V_4 -> V_54 &&
F_65 ( & V_4 -> V_132 ) > 0 ) {
F_82 ( V_4 ) ;
V_31 = F_41 ( V_2 , V_4 ) ;
F_80 ( V_4 ) ;
}
GOTO ( V_78 , V_31 ) ;
}
F_7 ( V_10 -> V_153 == V_156 ) ;
if ( V_10 -> V_64 . V_65 != NULL )
V_63 = V_10 -> V_64 . V_65 -> V_63 ;
if ( ( V_63 == NULL && V_4 -> V_35 == NULL ) ||
( ( V_63 != NULL && V_4 -> V_35 != NULL ) &&
( V_4 -> V_35 -> V_104 == V_63 -> V_104 ) &&
( V_4 -> V_35 -> V_157 == V_63 -> V_157 ) ) ) {
V_4 -> V_54 = false ;
GOTO ( V_78 , V_31 = 0 ) ;
}
if ( F_65 ( & V_4 -> V_132 ) > 0 ) {
V_4 -> V_54 = true ;
GOTO ( V_78 , V_31 = - V_158 ) ;
}
V_4 -> V_54 = F_86 ( V_2 , V_4 , V_10 ) ;
V_78:
F_82 ( V_4 ) ;
F_16 ( V_37 , V_38 L_19 ,
F_17 ( F_84 ( F_26 ( V_4 ) ) ) , V_4 -> V_54 ) ;
return V_31 ;
}
static void F_101 ( const struct V_1 * V_2 , struct V_15 * V_105 )
{
struct V_3 * V_4 = F_62 ( V_105 ) ;
F_102 ( V_4 , V_141 , V_2 , V_4 , & V_4 -> V_64 ) ;
}
static void F_103 ( const struct V_1 * V_2 , struct V_15 * V_105 )
{
struct V_3 * V_4 = F_62 ( V_105 ) ;
F_102 ( V_4 , V_142 , V_2 , V_4 , & V_4 -> V_64 ) ;
F_104 ( V_105 ) ;
F_105 ( V_4 , V_159 ) ;
}
static int F_106 ( const struct V_1 * V_2 , void * V_101 ,
T_2 V_102 , const struct V_15 * V_16 )
{
return F_107 ( F_62 ( V_16 ) , V_160 , V_2 , V_101 , V_102 , V_16 ) ;
}
int F_108 ( const struct V_1 * V_2 , struct V_11 * V_105 ,
struct V_161 * V_162 , struct V_162 * V_163 )
{
return F_107 ( F_22 ( V_105 ) ,
V_164 , V_2 , V_105 , V_162 , V_163 ) ;
}
int F_109 ( const struct V_1 * V_2 , struct V_11 * V_105 ,
struct V_165 * V_166 )
{
F_110 ( F_111 ( V_2 ) , V_167 ) ;
return F_112 ( F_22 ( V_105 ) , V_168 ,
! V_166 -> V_169 , V_2 , V_105 , V_166 ) ;
}
static int F_113 ( const struct V_1 * V_2 , struct V_11 * V_105 ,
struct V_106 * V_107 )
{
return F_107 ( F_22 ( V_105 ) , V_170 , V_2 , V_105 , V_107 ) ;
}
static int F_114 ( const struct V_1 * V_2 , struct V_11 * V_105 ,
const struct V_106 * V_107 , unsigned V_171 )
{
return 0 ;
}
int F_115 ( const struct V_1 * V_2 , struct V_11 * V_105 ,
struct V_172 * V_173 , const struct V_165 * V_166 )
{
return F_107 ( F_22 ( V_105 ) , V_174 , V_2 , V_105 , V_173 ,
V_166 ) ;
}
struct V_15 * F_116 ( const struct V_1 * V_2 ,
const struct V_175 * V_134 ,
struct V_176 * V_8 )
{
struct V_3 * V_4 ;
struct V_15 * V_105 ;
F_117 ( V_4 , V_159 , V_177 ) ;
if ( V_4 != NULL ) {
V_105 = F_26 ( V_4 ) ;
F_118 ( V_105 , NULL , V_8 ) ;
V_4 -> V_85 . V_178 = & V_179 ;
V_4 -> V_82 = - 1 ;
V_105 -> V_180 = & V_181 ;
} else
V_105 = NULL ;
return V_105 ;
}
struct V_62 * F_119 ( struct V_3 * V_4 )
{
struct V_62 * V_63 = NULL ;
F_76 ( V_4 ) ;
if ( V_4 -> V_35 != NULL ) {
V_63 = F_31 ( V_4 -> V_35 ) ;
F_16 ( V_37 , L_20 ,
V_63 , F_65 ( & V_63 -> V_103 ) ,
V_4 -> V_54 , V_128 ) ;
}
F_78 ( V_4 ) ;
return V_63 ;
}
void F_120 ( struct V_3 * V_4 , struct V_62 * V_63 )
{
if ( V_63 == NULL )
return;
F_16 ( V_37 , L_21 ,
V_63 , F_65 ( & V_63 -> V_103 ) , V_128 ) ;
F_59 ( & V_63 ) ;
}
struct V_62 * F_121 ( struct V_11 * V_182 )
{
struct V_15 * V_183 ;
struct V_62 * V_63 = NULL ;
if ( V_182 == NULL )
return NULL ;
V_183 = F_21 ( & V_25 ( V_182 ) -> V_40 ,
& V_53 ) ;
if ( V_183 != NULL )
V_63 = F_119 ( F_62 ( V_183 ) ) ;
return V_63 ;
}
void F_122 ( struct V_11 * V_134 , struct V_62 * V_63 )
{
if ( V_63 != NULL )
F_59 ( & V_63 ) ;
}
int F_123 ( struct V_11 * V_184 )
{
struct V_15 * V_183 ;
int V_185 = 0 ;
V_183 = F_21 ( & V_25 ( V_184 ) -> V_40 ,
& V_53 ) ;
if ( V_183 != NULL ) {
struct V_3 * V_4 = F_62 ( V_183 ) ;
F_76 ( V_4 ) ;
switch ( V_4 -> V_82 ) {
case V_126 : {
struct V_62 * V_63 ;
int V_57 ;
V_63 = V_4 -> V_35 ;
F_7 ( V_63 != NULL ) ;
for ( V_57 = 0 ; V_57 < V_63 -> V_73 ; V_57 ++ ) {
struct V_29 * V_186 = V_63 -> V_36 [ V_57 ] ;
if ( V_186 -> V_187 . V_188 && ! V_185 )
V_185 = V_186 -> V_187 . V_188 ;
V_186 -> V_187 . V_188 = 0 ;
}
}
case V_84 :
case V_83 :
break;
default:
F_124 () ;
}
F_78 ( V_4 ) ;
}
return V_185 ;
}
