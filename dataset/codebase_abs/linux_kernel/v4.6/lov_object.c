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
struct V_11 * V_21 , struct V_22 * V_23 ,
int V_24 )
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
V_30 = V_4 -> V_34 -> V_35 [ V_24 ] ;
F_16 ( V_36 , V_37 L_1 V_37 L_2 V_38
L_3 ,
F_17 ( & V_27 -> V_39 . V_40 ) , V_27 , V_24 ,
F_17 ( & V_26 -> V_39 . V_40 ) , V_26 , F_18 ( & V_30 -> V_41 ) ,
V_30 -> V_42 , V_30 -> V_43 ) ;
F_19 ( & V_27 -> V_44 ) ;
V_28 = V_27 -> V_45 ;
if ( ! V_28 ) {
V_27 -> V_45 = V_26 ;
F_20 ( & V_27 -> V_44 ) ;
V_27 -> V_46 = V_26 -> V_46 + 1 ;
F_21 ( & V_21 -> V_47 , L_4 , V_4 ) ;
V_23 -> V_48 [ V_24 ] = F_22 ( V_21 ) ;
V_23 -> V_48 [ V_24 ] -> V_49 = V_4 ;
V_23 -> V_48 [ V_24 ] -> V_50 = V_24 ;
V_31 = 0 ;
} else {
struct V_15 * V_51 ;
struct V_3 * V_52 ;
unsigned int V_53 = V_36 ;
F_20 ( & V_27 -> V_44 ) ;
V_51 = F_23 ( & V_28 -> V_39 , & V_54 ) ;
F_7 ( V_51 ) ;
V_52 = F_24 ( F_10 ( V_51 ) ) ;
if ( V_52 -> V_55 ) {
F_25 ( V_2 , & V_21 -> V_47 ) ;
V_31 = - V_56 ;
} else {
V_53 = V_57 ;
V_31 = - V_33 ;
}
F_26 ( V_53 , V_2 , & V_21 -> V_47 ,
L_5 , V_24 ) ;
F_26 ( V_53 , V_2 , V_51 , L_6 ) ;
F_27 ( V_53 , V_2 , F_28 ( V_4 ) , L_7 ) ;
F_14 ( V_2 , V_21 ) ;
}
return V_31 ;
}
static int F_29 ( const struct V_1 * V_2 ,
struct V_7 * V_8 , struct V_3 * V_4 ,
const struct V_9 * V_10 ,
union V_5 * V_6 )
{
int V_31 ;
int V_58 ;
struct V_11 * V_21 ;
struct V_59 * V_60 = F_30 ( V_2 ) ;
struct V_9 * V_61 = & V_60 -> V_62 ;
struct V_63 * V_64 = V_10 -> V_65 . V_66 -> V_64 ;
struct V_13 * V_67 = & V_60 -> V_68 ;
struct V_22 * V_23 = & V_6 -> V_69 ;
if ( V_64 -> V_70 != V_71 && V_64 -> V_70 != V_72 ) {
F_31 ( V_57 , V_64 ) ;
F_32 ( 0 , L_8 ,
V_71 , V_72 , V_64 -> V_70 ) ;
}
F_7 ( ! V_4 -> V_34 ) ;
V_4 -> V_34 = F_33 ( V_64 ) ;
V_23 -> V_73 = V_64 -> V_74 ;
F_7 ( V_23 -> V_73 <= F_34 ( V_8 ) ) ;
V_23 -> V_48 = F_35 ( V_23 -> V_73 * sizeof( V_23 -> V_48 [ 0 ] ) ,
V_75 ) ;
if ( V_23 -> V_48 ) {
V_31 = 0 ;
V_61 -> V_76 = V_10 -> V_76 ;
F_36 ( & V_23 -> V_77 ) ;
for ( V_58 = 0 ; V_58 < V_23 -> V_73 && V_31 == 0 ; ++ V_58 ) {
struct V_12 * V_78 ;
struct V_29 * V_30 = V_64 -> V_35 [ V_58 ] ;
int V_79 = V_30 -> V_42 ;
if ( F_37 ( V_30 ) )
continue;
V_31 = F_38 ( V_67 , & V_30 -> V_41 ,
V_30 -> V_42 ) ;
if ( V_31 != 0 )
goto V_80;
V_78 = F_39 ( V_8 -> V_81 [ V_79 ] ) ;
V_61 -> V_65 . V_82 = V_30 ;
F_32 ( V_78 , L_9 , V_79 ) ;
V_21 = F_4 ( V_2 , V_78 , V_67 , V_61 ) ;
if ( ! F_9 ( V_21 ) ) {
V_31 = F_11 ( V_2 , V_4 , V_21 , V_23 , V_58 ) ;
if ( V_31 == - V_56 ) {
-- V_58 ;
V_31 = 0 ;
}
} else {
V_31 = F_40 ( V_21 ) ;
}
}
} else
V_31 = - V_83 ;
V_80:
return V_31 ;
}
static int F_41 ( const struct V_1 * V_2 ,
struct V_7 * V_8 , struct V_3 * V_4 ,
const struct V_9 * V_10 ,
union V_5 * V_6 )
{
struct V_63 * V_64 = V_10 -> V_65 . V_66 -> V_64 ;
F_7 ( V_64 ) ;
F_7 ( F_42 ( V_64 ) ) ;
F_7 ( ! V_4 -> V_34 ) ;
V_4 -> V_34 = F_33 ( V_64 ) ;
return 0 ;
}
static int F_43 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 )
{
F_7 ( V_4 -> V_84 == V_85 || V_4 -> V_84 == V_86 ) ;
F_44 ( V_2 , V_4 ) ;
F_45 ( V_2 , & V_4 -> V_87 ) ;
return 0 ;
}
static void F_46 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_88 * V_89 , int V_24 )
{
struct V_11 * V_90 ;
struct V_22 * V_23 ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
T_1 * V_95 ;
V_23 = & V_4 -> V_65 . V_69 ;
F_7 ( V_23 -> V_48 [ V_24 ] == V_89 ) ;
V_90 = F_47 ( V_89 ) ;
V_92 = V_90 -> V_47 . V_18 -> V_96 ;
V_94 = F_48 ( V_92 , & V_90 -> V_47 . V_97 -> V_40 ) ;
F_13 ( V_2 , V_90 ) ;
F_49 ( & V_90 -> V_47 , L_4 , V_4 ) ;
F_14 ( V_2 , V_90 ) ;
if ( V_23 -> V_48 [ V_24 ] == V_89 ) {
V_95 = & F_30 ( V_2 ) -> V_98 ;
F_50 ( V_95 , V_99 ) ;
F_51 ( & V_94 -> V_100 , V_95 ) ;
F_52 ( V_101 ) ;
while ( 1 ) {
F_52 ( V_101 ) ;
F_19 ( & V_23 -> V_77 ) ;
if ( V_23 -> V_48 [ V_24 ] == V_89 ) {
F_20 ( & V_23 -> V_77 ) ;
F_53 () ;
} else {
F_20 ( & V_23 -> V_77 ) ;
F_52 ( V_102 ) ;
break;
}
}
F_54 ( & V_94 -> V_100 , V_95 ) ;
}
F_7 ( ! V_23 -> V_48 [ V_24 ] ) ;
}
static int F_55 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 )
{
struct V_22 * V_23 = & V_6 -> V_69 ;
struct V_63 * V_64 = V_4 -> V_34 ;
int V_58 ;
F_31 ( V_36 , V_64 ) ;
F_44 ( V_2 , V_4 ) ;
if ( V_23 -> V_48 ) {
for ( V_58 = 0 ; V_58 < V_23 -> V_73 ; ++ V_58 ) {
struct V_88 * V_89 = V_23 -> V_48 [ V_58 ] ;
if ( V_89 ) {
F_56 ( V_2 , & V_89 -> V_103 , 1 ) ;
F_46 ( V_2 , V_4 , V_89 , V_58 ) ;
}
}
}
F_45 ( V_2 , & V_4 -> V_87 ) ;
return 0 ;
}
static void F_57 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 )
{
F_7 ( V_4 -> V_84 == V_85 || V_4 -> V_84 == V_86 ) ;
}
static void F_58 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 )
{
struct V_22 * V_23 = & V_6 -> V_69 ;
if ( V_23 -> V_48 ) {
F_59 ( V_23 -> V_48 ) ;
V_23 -> V_48 = NULL ;
}
F_31 ( V_36 , V_4 -> V_34 ) ;
F_60 ( & V_4 -> V_34 ) ;
}
static void F_61 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 )
{
F_31 ( V_36 , V_4 -> V_34 ) ;
F_60 ( & V_4 -> V_34 ) ;
}
static int F_62 ( const struct V_1 * V_2 , void * V_104 ,
T_2 V_105 , const struct V_15 * V_16 )
{
(* V_105)( V_2 , V_104 , L_10 , F_63 ( V_16 ) -> V_55 ) ;
return 0 ;
}
static int F_64 ( const struct V_1 * V_2 , void * V_104 ,
T_2 V_105 , const struct V_15 * V_16 )
{
struct V_3 * V_4 = F_63 ( V_16 ) ;
struct V_22 * V_23 = F_65 ( V_4 ) ;
struct V_63 * V_64 = V_4 -> V_34 ;
int V_58 ;
(* V_105)( V_2 , V_104 , L_11 ,
V_23 -> V_73 , V_4 -> V_55 ? L_12 : L_13 , V_64 ,
V_64 -> V_70 , F_66 ( & V_64 -> V_106 ) ,
V_64 -> V_74 , V_64 -> V_107 ) ;
for ( V_58 = 0 ; V_58 < V_23 -> V_73 ; ++ V_58 ) {
struct V_15 * V_90 ;
if ( V_23 -> V_48 [ V_58 ] ) {
V_90 = F_67 ( V_23 -> V_48 [ V_58 ] ) ;
F_68 ( V_2 , V_104 , V_105 , V_90 ) ;
} else {
(* V_105)( V_2 , V_104 , L_14 , V_58 ) ;
}
}
return 0 ;
}
static int F_69 ( const struct V_1 * V_2 , void * V_104 ,
T_2 V_105 , const struct V_15 * V_16 )
{
struct V_3 * V_4 = F_63 ( V_16 ) ;
struct V_63 * V_64 = V_4 -> V_34 ;
(* V_105)( V_2 , V_104 ,
L_15 ,
V_4 -> V_55 ? L_12 : L_13 , V_64 ,
V_64 -> V_70 , F_66 ( & V_64 -> V_106 ) ,
V_64 -> V_74 , V_64 -> V_107 ) ;
return 0 ;
}
static int F_70 ( const struct V_1 * V_2 , struct V_11 * V_108 ,
struct V_109 * V_110 )
{
V_110 -> V_111 = 0 ;
return 0 ;
}
static int F_71 ( const struct V_1 * V_2 , struct V_11 * V_108 ,
struct V_109 * V_110 )
{
struct V_3 * V_4 = F_24 ( V_108 ) ;
struct V_22 * V_23 = F_65 ( V_4 ) ;
struct V_109 * V_112 = & V_23 -> V_113 ;
int V_31 = 0 ;
if ( ! V_23 -> V_114 ) {
struct V_63 * V_64 = V_4 -> V_34 ;
struct V_115 * V_116 = & F_30 ( V_2 ) -> V_117 ;
T_3 V_118 = 0 ;
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
V_116 -> V_119 = V_120 ;
V_116 -> V_121 = V_120 ;
V_116 -> V_122 = V_120 ;
F_72 ( V_64 ) ;
V_31 = F_73 ( V_64 , V_116 , & V_118 ) ;
F_74 ( V_64 ) ;
if ( V_31 == 0 ) {
F_75 ( V_112 , V_116 ) ;
V_112 -> V_123 = V_118 ;
V_23 -> V_114 = 1 ;
}
}
if ( V_31 == 0 ) {
V_110 -> V_111 = V_112 -> V_111 ;
V_110 -> V_124 = V_112 -> V_124 ;
V_110 -> V_123 = V_112 -> V_123 ;
if ( V_110 -> V_125 < V_112 -> V_125 )
V_110 -> V_125 = V_112 -> V_125 ;
if ( V_110 -> V_126 < V_112 -> V_126 )
V_110 -> V_126 = V_112 -> V_126 ;
if ( V_110 -> V_127 < V_112 -> V_127 )
V_110 -> V_127 = V_112 -> V_127 ;
}
return V_31 ;
}
static enum V_128 F_76 ( struct V_63 * V_64 )
{
if ( ! V_64 )
return V_85 ;
if ( F_42 ( V_64 ) )
return V_86 ;
return V_129 ;
}
static inline void F_77 ( struct V_3 * V_4 )
{
if ( V_4 -> V_130 != V_99 )
F_78 ( & V_4 -> V_131 ) ;
}
static inline void F_79 ( struct V_3 * V_4 )
{
if ( V_4 -> V_130 != V_99 )
F_80 ( & V_4 -> V_131 ) ;
}
static void F_81 ( struct V_3 * V_4 )
{
F_7 ( V_4 -> V_130 != V_99 ) ;
F_82 ( & V_4 -> V_131 ) ;
F_7 ( ! V_4 -> V_130 ) ;
V_4 -> V_130 = V_99 ;
}
static void F_83 ( struct V_3 * V_4 )
{
V_4 -> V_130 = NULL ;
F_84 ( & V_4 -> V_131 ) ;
}
static int F_44 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_132 V_133 = { 0 } ;
while ( F_66 ( & V_4 -> V_134 ) > 0 ) {
F_16 ( V_36 , L_16 V_37 L_17 ,
F_17 ( F_85 ( F_28 ( V_4 ) ) ) ,
F_66 ( & V_4 -> V_134 ) ) ;
F_86 ( V_4 -> V_135 ,
F_66 ( & V_4 -> V_134 ) == 0 , & V_133 ) ;
}
return 0 ;
}
static int F_87 ( const struct V_1 * V_136 ,
struct V_3 * V_4 ,
const struct V_9 * V_10 )
{
int V_31 ;
enum V_128 V_137 = V_85 ;
union V_5 * V_6 = & V_4 -> V_65 ;
const struct V_138 * V_139 ;
const struct V_138 * V_140 ;
struct V_25 * V_26 = V_25 ( & V_4 -> V_87 ) ;
void * V_104 ;
struct V_1 * V_2 ;
int V_141 ;
F_7 ( 0 <= V_4 -> V_84 && V_4 -> V_84 < F_88 ( V_142 ) ) ;
if ( V_10 -> V_65 . V_66 )
V_137 = F_76 ( V_10 -> V_65 . V_66 -> V_64 ) ;
F_7 ( 0 <= V_137 && V_137 < F_88 ( V_142 ) ) ;
V_104 = F_89 () ;
V_2 = F_90 ( & V_141 ) ;
if ( F_9 ( V_2 ) ) {
F_91 ( V_104 ) ;
return F_40 ( V_2 ) ;
}
F_16 ( V_36 , V_37 L_18 ,
F_17 ( F_85 ( F_28 ( V_4 ) ) ) ,
F_92 ( V_4 -> V_84 ) , F_92 ( V_137 ) ) ;
V_139 = & V_142 [ V_4 -> V_84 ] ;
V_140 = & V_142 [ V_137 ] ;
V_31 = V_139 -> V_143 ( V_2 , V_4 , & V_4 -> V_65 ) ;
if ( V_31 == 0 ) {
V_139 -> V_144 ( V_2 , V_4 , & V_4 -> V_65 ) ;
F_7 ( F_66 ( & V_4 -> V_134 ) == 0 ) ;
F_7 ( ! V_26 -> V_145 . V_146 ) ;
F_7 ( V_26 -> V_147 == 0 ) ;
V_4 -> V_84 = V_85 ;
V_31 = V_140 -> V_148 ( V_2 ,
F_93 ( V_4 -> V_87 . V_47 . V_18 ) ,
V_4 , V_10 , V_6 ) ;
if ( V_31 == 0 ) {
V_140 -> V_149 ( V_2 , V_4 , V_6 ) ;
V_4 -> V_84 = V_137 ;
} else {
V_140 -> V_143 ( V_2 , V_4 , V_6 ) ;
V_140 -> V_144 ( V_2 , V_4 , V_6 ) ;
}
}
F_94 ( V_2 , & V_141 ) ;
F_91 ( V_104 ) ;
return V_31 ;
}
int F_95 ( const struct V_1 * V_2 , struct V_15 * V_108 ,
const struct V_150 * V_10 )
{
struct V_7 * V_8 = F_93 ( V_108 -> V_18 ) ;
struct V_3 * V_4 = F_63 ( V_108 ) ;
const struct V_9 * V_151 = F_96 ( V_10 ) ;
union V_5 * V_152 = & V_4 -> V_65 ;
const struct V_138 * V_153 ;
int V_31 ;
F_97 ( & V_4 -> V_131 ) ;
F_98 ( & V_4 -> V_134 , 0 ) ;
F_99 ( & V_4 -> V_135 ) ;
F_100 ( F_10 ( V_108 ) , sizeof( struct V_154 ) ) ;
V_4 -> V_84 = F_76 ( V_151 -> V_65 . V_66 -> V_64 ) ;
V_153 = & V_142 [ V_4 -> V_84 ] ;
V_31 = V_153 -> V_148 ( V_2 , V_8 , V_4 , V_151 , V_152 ) ;
if ( V_31 == 0 )
V_153 -> V_149 ( V_2 , V_4 , V_152 ) ;
return V_31 ;
}
static int F_101 ( const struct V_1 * V_2 , struct V_11 * V_108 ,
const struct V_9 * V_10 )
{
struct V_63 * V_64 = NULL ;
struct V_3 * V_4 = F_24 ( V_108 ) ;
int V_31 = 0 ;
F_81 ( V_4 ) ;
if ( V_10 -> V_155 == V_156 ) {
V_4 -> V_55 = true ;
V_31 = 0 ;
goto V_80;
}
if ( V_10 -> V_155 == V_157 ) {
if ( V_4 -> V_55 &&
F_66 ( & V_4 -> V_134 ) > 0 ) {
F_83 ( V_4 ) ;
V_31 = F_44 ( V_2 , V_4 ) ;
F_81 ( V_4 ) ;
}
goto V_80;
}
F_7 ( V_10 -> V_155 == V_158 ) ;
if ( V_10 -> V_65 . V_66 )
V_64 = V_10 -> V_65 . V_66 -> V_64 ;
if ( ( ! V_64 && ! V_4 -> V_34 ) ||
( ( V_64 && V_4 -> V_34 ) &&
( V_4 -> V_34 -> V_107 == V_64 -> V_107 ) &&
( V_4 -> V_34 -> V_159 == V_64 -> V_159 ) ) ) {
V_4 -> V_55 = false ;
V_31 = 0 ;
goto V_80;
}
if ( F_66 ( & V_4 -> V_134 ) > 0 ) {
V_4 -> V_55 = true ;
V_31 = - V_160 ;
goto V_80;
}
V_4 -> V_55 = F_87 ( V_2 , V_4 , V_10 ) ;
V_80:
F_83 ( V_4 ) ;
F_16 ( V_36 , V_37 L_19 ,
F_17 ( F_85 ( F_28 ( V_4 ) ) ) , V_4 -> V_55 ) ;
return V_31 ;
}
static void F_102 ( const struct V_1 * V_2 , struct V_15 * V_108 )
{
struct V_3 * V_4 = F_63 ( V_108 ) ;
F_103 ( V_4 , V_143 , V_2 , V_4 , & V_4 -> V_65 ) ;
}
static void F_104 ( const struct V_1 * V_2 , struct V_15 * V_108 )
{
struct V_3 * V_4 = F_63 ( V_108 ) ;
F_103 ( V_4 , V_144 , V_2 , V_4 , & V_4 -> V_65 ) ;
F_105 ( V_108 ) ;
F_106 ( V_161 , V_4 ) ;
}
static int F_107 ( const struct V_1 * V_2 , void * V_104 ,
T_2 V_105 , const struct V_15 * V_16 )
{
return F_108 ( F_63 ( V_16 ) , V_162 , V_2 , V_104 , V_105 , V_16 ) ;
}
int F_109 ( const struct V_1 * V_2 , struct V_11 * V_108 ,
struct V_163 * V_164 , struct V_164 * V_165 )
{
return F_108 ( F_24 ( V_108 ) ,
V_166 , V_2 , V_108 , V_164 , V_165 ) ;
}
int F_110 ( const struct V_1 * V_2 , struct V_11 * V_108 ,
struct V_167 * V_168 )
{
F_111 ( F_112 ( V_2 ) , V_169 ) ;
return F_113 ( F_24 ( V_108 ) , V_170 ,
! V_168 -> V_171 , V_2 , V_108 , V_168 ) ;
}
static int F_114 ( const struct V_1 * V_2 , struct V_11 * V_108 ,
struct V_109 * V_110 )
{
return F_108 ( F_24 ( V_108 ) , V_172 , V_2 , V_108 , V_110 ) ;
}
static int F_115 ( const struct V_1 * V_2 , struct V_11 * V_108 ,
const struct V_109 * V_110 , unsigned V_173 )
{
return 0 ;
}
int F_116 ( const struct V_1 * V_2 , struct V_11 * V_108 ,
struct V_174 * V_175 , const struct V_167 * V_168 )
{
return F_108 ( F_24 ( V_108 ) , V_176 , V_2 , V_108 , V_175 ,
V_168 ) ;
}
struct V_15 * F_117 ( const struct V_1 * V_2 ,
const struct V_177 * V_136 ,
struct V_178 * V_8 )
{
struct V_3 * V_4 ;
struct V_15 * V_108 ;
V_4 = F_118 ( V_161 , V_75 ) ;
if ( V_4 ) {
V_108 = F_28 ( V_4 ) ;
F_119 ( V_108 , NULL , V_8 ) ;
V_4 -> V_87 . V_179 = & V_180 ;
V_4 -> V_84 = - 1 ;
V_108 -> V_181 = & V_182 ;
} else
V_108 = NULL ;
return V_108 ;
}
static struct V_63 * F_120 ( struct V_3 * V_4 )
{
struct V_63 * V_64 = NULL ;
F_77 ( V_4 ) ;
if ( V_4 -> V_34 ) {
V_64 = F_33 ( V_4 -> V_34 ) ;
F_16 ( V_36 , L_20 ,
V_64 , F_66 ( & V_64 -> V_106 ) ,
V_4 -> V_55 , V_99 ) ;
}
F_79 ( V_4 ) ;
return V_64 ;
}
struct V_63 * F_121 ( struct V_11 * V_183 )
{
struct V_15 * V_184 ;
struct V_63 * V_64 = NULL ;
if ( ! V_183 )
return NULL ;
V_184 = F_23 ( & V_25 ( V_183 ) -> V_39 ,
& V_54 ) ;
if ( V_184 )
V_64 = F_120 ( F_63 ( V_184 ) ) ;
return V_64 ;
}
void F_122 ( struct V_11 * V_136 , struct V_63 * V_64 )
{
if ( V_64 )
F_60 ( & V_64 ) ;
}
int F_123 ( struct V_11 * V_185 )
{
struct V_15 * V_184 ;
int V_186 = 0 ;
V_184 = F_23 ( & V_25 ( V_185 ) -> V_39 ,
& V_54 ) ;
if ( V_184 ) {
struct V_3 * V_4 = F_63 ( V_184 ) ;
F_77 ( V_4 ) ;
switch ( V_4 -> V_84 ) {
case V_129 : {
struct V_63 * V_64 ;
int V_58 ;
V_64 = V_4 -> V_34 ;
for ( V_58 = 0 ; V_58 < V_64 -> V_74 ; V_58 ++ ) {
struct V_29 * V_187 = V_64 -> V_35 [ V_58 ] ;
if ( F_37 ( V_187 ) )
continue;
if ( V_187 -> V_188 . V_189 && ! V_186 )
V_186 = V_187 -> V_188 . V_189 ;
V_187 -> V_188 . V_189 = 0 ;
}
}
case V_86 :
case V_85 :
break;
default:
F_124 () ;
}
F_79 ( V_4 ) ;
}
return V_186 ;
}
