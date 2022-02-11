static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 . V_5 . V_6 ) ;
}
static void F_3 ( struct V_7 * V_8 )
{
if ( V_8 )
F_4 ( & V_8 ) ;
}
static void F_5 ( const struct V_9 * V_10 ,
struct V_2 * V_11 ,
union V_12 * V_13 )
{
}
static int F_6 ( const struct V_9 * V_10 , struct V_1 * V_14 ,
struct V_2 * V_11 , struct V_7 * V_8 ,
const struct V_15 * V_16 ,
union V_12 * V_13 )
{
return 0 ;
}
static void F_7 ( const struct V_9 * V_10 ,
struct V_2 * V_11 ,
union V_12 * V_13 )
{
}
static struct V_17 * F_8 ( const struct V_9 * V_10 ,
struct V_18 * V_14 ,
const struct V_19 * V_20 ,
const struct V_15 * V_16 )
{
struct V_21 * V_22 ;
V_22 = F_9 ( V_10 , F_10 ( V_14 ) , V_20 , & V_16 -> V_23 ) ;
F_11 ( F_12 ( ! F_13 ( V_22 ) , V_22 -> V_6 -> V_24 == & V_25 ) ) ;
return F_14 ( V_22 ) ;
}
static int F_15 ( const struct V_9 * V_10 , struct V_2 * V_11 ,
struct V_17 * V_26 , struct V_27 * V_28 ,
int V_29 )
{
struct V_30 * V_31 ;
struct V_30 * V_32 ;
struct V_30 * V_33 ;
struct V_34 * V_35 ;
int V_36 ;
if ( F_16 ( V_37 ) ) {
F_17 ( V_10 , V_26 ) ;
F_18 ( V_10 , V_26 ) ;
return - V_38 ;
}
V_31 = V_30 ( F_19 ( V_11 ) ) ;
V_32 = V_30 ( V_26 ) ;
V_35 = V_11 -> V_39 -> V_40 [ V_29 ] ;
F_20 ( V_41 , V_42 L_1 V_42 L_2 V_43
L_3 ,
F_21 ( & V_32 -> V_44 . V_45 ) , V_32 , V_29 ,
F_21 ( & V_31 -> V_44 . V_45 ) , V_31 , F_22 ( & V_35 -> V_46 ) ,
V_35 -> V_47 , V_35 -> V_48 ) ;
F_23 ( & V_32 -> V_49 ) ;
V_33 = V_32 -> V_50 ;
if ( ! V_33 ) {
V_32 -> V_50 = V_31 ;
F_24 ( & V_32 -> V_49 ) ;
V_32 -> V_51 = V_31 -> V_51 + 1 ;
F_25 ( & V_26 -> V_5 , L_4 , V_11 ) ;
V_28 -> V_52 [ V_29 ] = F_26 ( V_26 ) ;
V_28 -> V_52 [ V_29 ] -> V_53 = V_11 ;
V_28 -> V_52 [ V_29 ] -> V_54 = V_29 ;
V_36 = 0 ;
} else {
struct V_21 * V_55 ;
struct V_2 * V_56 ;
unsigned int V_57 = V_41 ;
F_24 ( & V_32 -> V_49 ) ;
V_55 = F_27 ( & V_33 -> V_44 , & V_58 ) ;
F_11 ( V_55 ) ;
V_56 = F_28 ( F_14 ( V_55 ) ) ;
if ( V_56 -> V_59 ) {
F_29 ( V_10 , & V_26 -> V_5 ) ;
V_36 = - V_60 ;
} else {
V_57 = V_61 ;
V_36 = - V_38 ;
}
F_30 ( V_57 , V_10 , & V_26 -> V_5 ,
L_5 , V_29 ) ;
F_30 ( V_57 , V_10 , V_55 , L_6 ) ;
F_31 ( V_57 , V_10 , F_32 ( V_11 ) , L_7 ) ;
F_18 ( V_10 , V_26 ) ;
}
return V_36 ;
}
static int F_33 ( struct V_2 * V_11 ,
struct V_17 * V_26 )
{
struct V_30 * V_31 = V_30 ( & V_11 -> V_4 ) ;
struct V_17 * V_22 ;
if ( ! V_26 )
return V_31 -> V_62 - V_11 -> V_4 . V_63 -
F_34 ( sizeof( struct V_64 ) ) ;
F_35 (o, stripe)
V_22 -> V_63 += V_31 -> V_62 ;
return V_30 ( V_26 ) -> V_62 ;
}
static int F_36 ( const struct V_9 * V_10 , struct V_1 * V_14 ,
struct V_2 * V_11 , struct V_7 * V_8 ,
const struct V_15 * V_16 ,
union V_12 * V_13 )
{
int V_36 ;
int V_65 ;
struct V_17 * V_26 ;
struct V_66 * V_67 = F_37 ( V_10 ) ;
struct V_15 * V_68 = & V_67 -> V_69 ;
struct V_19 * V_70 = & V_67 -> V_71 ;
struct V_27 * V_28 = & V_13 -> V_72 ;
if ( V_8 -> V_73 != V_74 && V_8 -> V_73 != V_75 ) {
F_38 ( V_61 , V_8 ) ;
F_39 ( 0 , L_8 ,
V_74 , V_75 , V_8 -> V_73 ) ;
}
F_11 ( ! V_11 -> V_39 ) ;
V_11 -> V_39 = F_40 ( V_8 ) ;
V_11 -> V_59 = true ;
V_28 -> V_76 = V_8 -> V_77 ;
F_11 ( V_28 -> V_76 <= F_41 ( V_14 ) ) ;
V_28 -> V_52 = F_42 ( V_28 -> V_76 * sizeof( V_28 -> V_52 [ 0 ] ) ,
V_78 ) ;
if ( V_28 -> V_52 ) {
int V_79 = 0 ;
V_36 = 0 ;
V_68 -> V_80 = V_16 -> V_80 ;
F_43 ( & V_28 -> V_81 ) ;
for ( V_65 = 0 ; V_65 < V_28 -> V_76 && V_36 == 0 ; ++ V_65 ) {
struct V_18 * V_82 ;
struct V_34 * V_35 = V_8 -> V_40 [ V_65 ] ;
int V_83 = V_35 -> V_47 ;
if ( F_44 ( V_35 ) )
continue;
V_36 = F_45 ( V_70 , & V_35 -> V_46 ,
V_35 -> V_47 ) ;
if ( V_36 != 0 )
goto V_84;
V_82 = F_46 ( V_14 -> V_85 [ V_83 ] ) ;
V_68 -> V_86 . V_87 = V_35 ;
F_39 ( V_82 , L_9 , V_83 ) ;
V_26 = F_8 ( V_10 , V_82 , V_70 , V_68 ) ;
if ( ! F_13 ( V_26 ) ) {
V_36 = F_15 ( V_10 , V_11 , V_26 , V_28 , V_65 ) ;
if ( V_36 == - V_60 ) {
-- V_65 ;
V_36 = 0 ;
continue;
}
} else {
V_36 = F_47 ( V_26 ) ;
}
if ( V_36 == 0 ) {
int V_88 = F_33 ( V_11 , V_26 ) ;
F_11 ( F_12 ( V_79 > 0 , V_79 == V_88 ) ) ;
V_79 = V_88 ;
}
}
if ( V_36 == 0 )
V_30 ( & V_11 -> V_4 ) -> V_62 += V_79 ;
} else {
V_36 = - V_89 ;
}
V_84:
return V_36 ;
}
static int F_48 ( const struct V_9 * V_10 , struct V_1 * V_14 ,
struct V_2 * V_11 , struct V_7 * V_8 ,
const struct V_15 * V_16 ,
union V_12 * V_13 )
{
F_11 ( V_8 ) ;
F_11 ( F_49 ( V_8 ) ) ;
F_11 ( ! V_11 -> V_39 ) ;
V_11 -> V_39 = F_40 ( V_8 ) ;
return 0 ;
}
static struct V_17 * F_50 ( const struct V_9 * V_10 ,
struct V_2 * V_11 ,
struct V_7 * V_8 ,
int V_90 )
{
struct V_1 * V_14 = F_2 ( F_32 ( V_11 ) -> V_6 ) ;
struct V_34 * V_35 = V_8 -> V_40 [ V_90 ] ;
struct V_66 * V_67 = F_37 ( V_10 ) ;
struct V_19 * V_70 = & V_67 -> V_71 ;
struct V_18 * V_82 ;
struct V_17 * V_36 ;
int V_83 ;
int V_91 ;
if ( V_11 -> V_92 != V_93 ) {
V_36 = NULL ;
goto V_84;
}
V_83 = V_35 -> V_47 ;
V_91 = F_45 ( V_70 , & V_35 -> V_46 , V_83 ) ;
if ( V_91 ) {
V_36 = NULL ;
goto V_84;
}
V_82 = F_46 ( V_14 -> V_85 [ V_83 ] ) ;
V_36 = F_8 ( V_10 , V_82 , V_70 , NULL ) ;
V_84:
if ( ! V_36 )
V_36 = F_51 ( - V_94 ) ;
return V_36 ;
}
static int F_52 ( const struct V_9 * V_10 , struct V_2 * V_11 ,
union V_12 * V_13 )
{
F_11 ( V_11 -> V_92 == V_95 || V_11 -> V_92 == V_96 ) ;
F_53 ( V_10 , V_11 ) ;
return 0 ;
}
static void F_54 ( const struct V_9 * V_10 , struct V_2 * V_11 ,
struct V_97 * V_98 , int V_29 )
{
struct V_17 * V_99 ;
struct V_27 * V_28 ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
T_1 * V_104 ;
V_28 = & V_11 -> V_86 . V_72 ;
F_11 ( V_28 -> V_52 [ V_29 ] == V_98 ) ;
V_99 = F_55 ( V_98 ) ;
V_101 = V_99 -> V_5 . V_6 -> V_105 ;
V_103 = F_56 ( V_101 , & V_99 -> V_5 . V_106 -> V_45 ) ;
F_17 ( V_10 , V_99 ) ;
F_57 ( & V_99 -> V_5 , L_4 , V_11 ) ;
F_18 ( V_10 , V_99 ) ;
if ( V_28 -> V_52 [ V_29 ] == V_98 ) {
V_104 = & F_37 ( V_10 ) -> V_107 ;
F_58 ( V_104 , V_108 ) ;
F_59 ( & V_103 -> V_109 , V_104 ) ;
F_60 ( V_110 ) ;
while ( 1 ) {
F_60 ( V_110 ) ;
F_23 ( & V_28 -> V_81 ) ;
if ( V_28 -> V_52 [ V_29 ] == V_98 ) {
F_24 ( & V_28 -> V_81 ) ;
F_61 () ;
} else {
F_24 ( & V_28 -> V_81 ) ;
F_60 ( V_111 ) ;
break;
}
}
F_62 ( & V_103 -> V_109 , V_104 ) ;
}
F_11 ( ! V_28 -> V_52 [ V_29 ] ) ;
}
static int F_63 ( const struct V_9 * V_10 , struct V_2 * V_11 ,
union V_12 * V_13 )
{
struct V_27 * V_28 = & V_13 -> V_72 ;
struct V_7 * V_8 = V_11 -> V_39 ;
int V_65 ;
F_38 ( V_41 , V_8 ) ;
F_53 ( V_10 , V_11 ) ;
if ( V_28 -> V_52 ) {
for ( V_65 = 0 ; V_65 < V_28 -> V_76 ; ++ V_65 ) {
struct V_97 * V_98 = V_28 -> V_52 [ V_65 ] ;
if ( V_98 ) {
F_64 ( V_10 , & V_98 -> V_112 ) ;
F_54 ( V_10 , V_11 , V_98 , V_65 ) ;
}
}
}
return 0 ;
}
static void F_65 ( const struct V_9 * V_10 , struct V_2 * V_11 ,
union V_12 * V_13 )
{
F_11 ( V_11 -> V_92 == V_95 || V_11 -> V_92 == V_96 ) ;
}
static void F_66 ( const struct V_9 * V_10 , struct V_2 * V_11 ,
union V_12 * V_13 )
{
struct V_27 * V_28 = & V_13 -> V_72 ;
if ( V_28 -> V_52 ) {
F_67 ( V_28 -> V_52 ) ;
V_28 -> V_52 = NULL ;
}
F_38 ( V_41 , V_11 -> V_39 ) ;
F_4 ( & V_11 -> V_39 ) ;
}
static void F_68 ( const struct V_9 * V_10 , struct V_2 * V_11 ,
union V_12 * V_13 )
{
F_38 ( V_41 , V_11 -> V_39 ) ;
F_4 ( & V_11 -> V_39 ) ;
}
static int F_69 ( const struct V_9 * V_10 , void * V_113 ,
T_2 V_114 , const struct V_21 * V_22 )
{
(* V_114)( V_10 , V_113 , L_10 , F_70 ( V_22 ) -> V_59 ) ;
return 0 ;
}
static int F_71 ( const struct V_9 * V_10 , void * V_113 ,
T_2 V_114 , const struct V_21 * V_22 )
{
struct V_2 * V_11 = F_70 ( V_22 ) ;
struct V_27 * V_28 = F_72 ( V_11 ) ;
struct V_7 * V_8 = V_11 -> V_39 ;
int V_65 ;
(* V_114)( V_10 , V_113 , L_11 ,
V_28 -> V_76 , V_11 -> V_59 ? L_12 : L_13 , V_8 ,
V_8 -> V_73 , F_73 ( & V_8 -> V_115 ) ,
V_8 -> V_77 , V_8 -> V_116 ) ;
for ( V_65 = 0 ; V_65 < V_28 -> V_76 ; ++ V_65 ) {
struct V_21 * V_99 ;
if ( V_28 -> V_52 [ V_65 ] ) {
V_99 = F_74 ( V_28 -> V_52 [ V_65 ] ) ;
F_75 ( V_10 , V_113 , V_114 , V_99 ) ;
} else {
(* V_114)( V_10 , V_113 , L_14 , V_65 ) ;
}
}
return 0 ;
}
static int F_76 ( const struct V_9 * V_10 , void * V_113 ,
T_2 V_114 , const struct V_21 * V_22 )
{
struct V_2 * V_11 = F_70 ( V_22 ) ;
struct V_7 * V_8 = V_11 -> V_39 ;
(* V_114)( V_10 , V_113 ,
L_15 ,
V_11 -> V_59 ? L_12 : L_13 , V_8 ,
V_8 -> V_73 , F_73 ( & V_8 -> V_115 ) ,
V_8 -> V_77 , V_8 -> V_116 ) ;
return 0 ;
}
static int F_77 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
struct V_117 * V_118 )
{
V_118 -> V_119 = 0 ;
return 0 ;
}
static int F_78 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
struct V_117 * V_118 )
{
struct V_2 * V_11 = F_28 ( V_3 ) ;
struct V_27 * V_28 = F_72 ( V_11 ) ;
struct V_117 * V_120 = & V_28 -> V_121 ;
int V_36 = 0 ;
if ( ! V_28 -> V_122 ) {
struct V_7 * V_8 = V_11 -> V_39 ;
struct V_123 * V_124 = & F_37 ( V_10 ) -> V_125 ;
T_3 V_126 = 0 ;
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
V_124 -> V_127 = V_128 ;
V_124 -> V_129 = V_128 ;
V_124 -> V_130 = V_128 ;
F_79 ( V_8 ) ;
V_36 = F_80 ( V_8 , V_124 , & V_126 ) ;
F_81 ( V_8 ) ;
if ( V_36 == 0 ) {
F_82 ( V_120 , V_124 ) ;
V_120 -> V_131 = V_126 ;
V_28 -> V_122 = 1 ;
}
}
if ( V_36 == 0 ) {
V_118 -> V_119 = V_120 -> V_119 ;
V_118 -> V_132 = V_120 -> V_132 ;
V_118 -> V_131 = V_120 -> V_131 ;
if ( V_118 -> V_133 < V_120 -> V_133 )
V_118 -> V_133 = V_120 -> V_133 ;
if ( V_118 -> V_134 < V_120 -> V_134 )
V_118 -> V_134 = V_120 -> V_134 ;
if ( V_118 -> V_135 < V_120 -> V_135 )
V_118 -> V_135 = V_120 -> V_135 ;
}
return V_36 ;
}
static enum V_136 F_83 ( struct V_7 * V_8 )
{
if ( ! V_8 )
return V_95 ;
if ( F_49 ( V_8 ) )
return V_96 ;
return V_93 ;
}
static inline void F_84 ( struct V_2 * V_11 )
{
if ( V_11 -> V_137 != V_108 )
F_85 ( & V_11 -> V_138 ) ;
}
static inline void F_86 ( struct V_2 * V_11 )
{
if ( V_11 -> V_137 != V_108 )
F_87 ( & V_11 -> V_138 ) ;
}
static void F_88 ( struct V_2 * V_11 )
{
F_11 ( V_11 -> V_137 != V_108 ) ;
F_89 ( & V_11 -> V_138 ) ;
F_11 ( ! V_11 -> V_137 ) ;
V_11 -> V_137 = V_108 ;
}
static void F_90 ( struct V_2 * V_11 )
{
V_11 -> V_137 = NULL ;
F_91 ( & V_11 -> V_138 ) ;
}
static int F_53 ( const struct V_9 * V_10 , struct V_2 * V_11 )
{
struct V_139 V_140 = { 0 } ;
while ( F_73 ( & V_11 -> V_141 ) > 0 ) {
F_20 ( V_41 , L_16 V_42 L_17 ,
F_21 ( F_92 ( F_32 ( V_11 ) ) ) ,
F_73 ( & V_11 -> V_141 ) ) ;
F_93 ( V_11 -> V_142 ,
F_73 ( & V_11 -> V_141 ) == 0 , & V_140 ) ;
}
return 0 ;
}
static int F_94 ( const struct V_9 * V_143 ,
struct V_2 * V_11 , struct V_7 * V_8 ,
const struct V_15 * V_16 )
{
enum V_136 V_144 = F_83 ( V_8 ) ;
union V_12 * V_13 = & V_11 -> V_86 ;
const struct V_145 * V_146 ;
const struct V_145 * V_147 ;
struct V_9 * V_10 ;
int V_148 ;
int V_91 ;
F_11 ( 0 <= V_11 -> V_92 && V_11 -> V_92 < F_95 ( V_149 ) ) ;
V_10 = F_96 ( & V_148 ) ;
if ( F_13 ( V_10 ) )
return F_47 ( V_10 ) ;
F_11 ( 0 <= V_144 && V_144 < F_95 ( V_149 ) ) ;
F_20 ( V_41 , V_42 L_18 ,
F_21 ( F_92 ( F_32 ( V_11 ) ) ) ,
F_97 ( V_11 -> V_92 ) , F_97 ( V_144 ) ) ;
V_146 = & V_149 [ V_11 -> V_92 ] ;
V_147 = & V_149 [ V_144 ] ;
V_91 = F_64 ( V_10 , & V_11 -> V_4 ) ;
if ( V_91 )
goto V_84;
V_91 = V_146 -> V_150 ( V_10 , V_11 , & V_11 -> V_86 ) ;
if ( V_91 )
goto V_84;
V_146 -> V_151 ( V_10 , V_11 , & V_11 -> V_86 ) ;
F_11 ( ! F_73 ( & V_11 -> V_141 ) ) ;
V_11 -> V_92 = V_95 ;
V_30 ( & V_11 -> V_4 ) -> V_62 -=
F_33 ( V_11 , NULL ) ;
V_91 = V_147 -> V_152 ( V_10 , F_1 ( V_11 ) , V_11 , V_8 , V_16 , V_13 ) ;
if ( V_91 ) {
V_147 -> V_150 ( V_10 , V_11 , V_13 ) ;
V_147 -> V_151 ( V_10 , V_11 , V_13 ) ;
goto V_84;
}
V_147 -> V_153 ( V_10 , V_11 , V_13 ) ;
V_11 -> V_92 = V_144 ;
V_84:
F_98 ( V_10 , & V_148 ) ;
return V_91 ;
}
int F_99 ( const struct V_9 * V_10 , struct V_21 * V_3 ,
const struct V_154 * V_16 )
{
struct V_2 * V_11 = F_70 ( V_3 ) ;
struct V_1 * V_14 = F_1 ( V_11 ) ;
const struct V_15 * V_155 = F_100 ( V_16 ) ;
union V_12 * V_156 = & V_11 -> V_86 ;
const struct V_145 * V_157 ;
struct V_7 * V_8 = NULL ;
int V_91 ;
F_101 ( & V_11 -> V_138 ) ;
F_102 ( & V_11 -> V_141 , 0 ) ;
F_103 ( & V_11 -> V_142 ) ;
F_104 ( F_14 ( V_3 ) , sizeof( struct V_64 ) ) ;
V_11 -> V_92 = V_95 ;
if ( V_155 -> V_86 . V_158 . V_159 ) {
V_8 = F_105 ( V_14 -> V_160 ,
V_155 -> V_86 . V_158 . V_159 ,
V_155 -> V_86 . V_158 . V_161 ) ;
if ( F_13 ( V_8 ) )
return F_47 ( V_8 ) ;
}
V_11 -> V_92 = F_83 ( V_8 ) ;
V_157 = & V_149 [ V_11 -> V_92 ] ;
V_91 = V_157 -> V_152 ( V_10 , V_14 , V_11 , V_8 , V_155 , V_156 ) ;
if ( ! V_91 )
V_157 -> V_153 ( V_10 , V_11 , V_156 ) ;
F_3 ( V_8 ) ;
return V_91 ;
}
static int F_106 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
const struct V_15 * V_16 )
{
struct V_7 * V_8 = NULL ;
struct V_2 * V_11 = F_28 ( V_3 ) ;
int V_36 = 0 ;
if ( V_16 -> V_162 == V_163 &&
V_16 -> V_86 . V_158 . V_159 ) {
V_8 = F_105 ( F_1 ( V_11 ) -> V_160 ,
V_16 -> V_86 . V_158 . V_159 ,
V_16 -> V_86 . V_158 . V_161 ) ;
if ( F_13 ( V_8 ) )
return F_47 ( V_8 ) ;
}
F_88 ( V_11 ) ;
if ( V_16 -> V_162 == V_164 ) {
V_11 -> V_59 = true ;
V_36 = 0 ;
goto V_84;
}
if ( V_16 -> V_162 == V_165 ) {
if ( V_11 -> V_59 &&
F_73 ( & V_11 -> V_141 ) > 0 ) {
F_90 ( V_11 ) ;
V_36 = F_53 ( V_10 , V_11 ) ;
F_88 ( V_11 ) ;
}
goto V_84;
}
F_11 ( V_16 -> V_162 == V_163 ) ;
if ( ( ! V_8 && ! V_11 -> V_39 ) ||
( ( V_8 && V_11 -> V_39 ) &&
( V_11 -> V_39 -> V_116 == V_8 -> V_116 ) &&
( V_11 -> V_39 -> V_166 == V_8 -> V_166 ) ) ) {
V_11 -> V_59 = false ;
V_36 = 0 ;
goto V_84;
}
if ( F_73 ( & V_11 -> V_141 ) > 0 ) {
V_11 -> V_59 = true ;
V_36 = - V_167 ;
goto V_84;
}
V_36 = F_94 ( V_10 , V_11 , V_8 , V_16 ) ;
V_11 -> V_59 = V_36 != 0 ;
V_84:
F_90 ( V_11 ) ;
F_3 ( V_8 ) ;
F_20 ( V_41 , V_42 L_19 ,
F_21 ( F_92 ( F_32 ( V_11 ) ) ) , V_11 -> V_59 ) ;
return V_36 ;
}
static void F_107 ( const struct V_9 * V_10 , struct V_21 * V_3 )
{
struct V_2 * V_11 = F_70 ( V_3 ) ;
F_108 ( V_11 , V_150 , V_10 , V_11 , & V_11 -> V_86 ) ;
}
static void F_109 ( const struct V_9 * V_10 , struct V_21 * V_3 )
{
struct V_2 * V_11 = F_70 ( V_3 ) ;
F_108 ( V_11 , V_151 , V_10 , V_11 , & V_11 -> V_86 ) ;
F_110 ( V_3 ) ;
F_111 ( V_168 , V_11 ) ;
}
static int F_112 ( const struct V_9 * V_10 , void * V_113 ,
T_2 V_114 , const struct V_21 * V_22 )
{
return F_113 ( F_70 ( V_22 ) , V_169 , V_10 , V_113 , V_114 , V_22 ) ;
}
int F_114 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
struct V_170 * V_171 , T_4 V_172 )
{
return F_113 ( F_28 ( V_3 ) , V_173 , V_10 , V_3 , V_171 ,
V_172 ) ;
}
int F_115 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
struct V_174 * V_175 )
{
F_116 ( F_117 ( V_10 ) , V_176 ) ;
return F_118 ( F_28 ( V_3 ) , V_177 ,
! V_175 -> V_178 , V_10 , V_3 , V_175 ) ;
}
static int F_119 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
struct V_117 * V_118 )
{
return F_113 ( F_28 ( V_3 ) , V_179 , V_10 , V_3 , V_118 ) ;
}
static int F_120 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
const struct V_117 * V_118 , unsigned int V_180 )
{
return 0 ;
}
int F_121 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
struct V_181 * V_182 , const struct V_174 * V_175 )
{
return F_113 ( F_28 ( V_3 ) , V_183 , V_10 , V_3 , V_182 ,
V_175 ) ;
}
static int F_122 ( struct V_7 * V_8 ,
T_5 V_184 , T_5 V_185 ,
int V_186 , int * V_187 )
{
int V_188 ;
T_5 V_189 ;
T_5 V_190 ;
int V_65 , V_191 ;
if ( V_185 - V_184 > V_8 -> V_192 * V_8 -> V_77 ) {
V_188 = ( V_186 < 1 ? V_8 -> V_77 - 1 :
V_186 - 1 ) ;
* V_187 = V_8 -> V_77 ;
} else {
for ( V_191 = 0 , V_65 = V_186 ; V_191 < V_8 -> V_77 ;
V_65 = ( V_65 + 1 ) % V_8 -> V_77 , V_191 ++ ) {
if ( ! ( F_123 ( V_8 , V_65 , V_184 , V_185 ,
& V_189 , & V_190 ) ) )
break;
}
* V_187 = V_191 ;
V_188 = ( V_186 + V_191 - 1 ) % V_8 -> V_77 ;
}
return V_188 ;
}
static void F_124 ( struct V_193 * V_193 ,
struct V_194 * V_195 ,
int V_196 , unsigned int V_197 ,
int V_198 )
{
unsigned int V_199 ;
char * V_200 ;
for ( V_199 = 0 ; V_199 < V_197 ; V_199 ++ ) {
V_195 [ V_199 ] . V_201 = V_196 ;
V_195 [ V_199 ] . V_202 |= V_203 ;
}
V_200 = ( char * ) V_193 + F_125 ( V_198 ) ;
memcpy ( V_200 , V_195 , V_197 * sizeof( struct V_194 ) ) ;
}
static T_5 F_126 ( struct V_193 * V_193 ,
struct V_7 * V_8 ,
T_5 V_184 , T_5 V_185 ,
int * V_186 )
{
T_5 V_204 = V_193 -> V_205 [ 0 ] . V_206 ;
T_5 V_207 , V_208 ;
T_5 V_209 ;
int V_210 = - 1 ;
int V_65 ;
if ( ! V_193 -> V_211 || ! V_193 -> V_205 [ 0 ] . V_206 )
return 0 ;
for ( V_65 = 0 ; V_65 < V_8 -> V_77 ; V_65 ++ ) {
struct V_34 * V_35 = V_8 -> V_40 [ V_65 ] ;
if ( F_44 ( V_35 ) )
continue;
if ( V_35 -> V_47 == V_193 -> V_205 [ 0 ] . V_201 ) {
V_210 = V_65 ;
break;
}
}
if ( V_210 == - 1 )
return - V_94 ;
if ( F_123 ( V_8 , V_210 , V_184 , V_185 ,
& V_207 , & V_208 ) &&
V_204 < V_208 ) {
V_209 = V_204 ;
* V_186 = V_210 ;
} else {
V_209 = 0 ;
* V_186 = ( V_210 + 1 ) % V_8 -> V_77 ;
}
return V_209 ;
}
static int F_127 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
struct V_212 * V_213 ,
struct V_193 * V_193 , T_6 * V_214 )
{
struct V_215 * V_11 = F_2 ( V_3 -> V_5 . V_6 ) -> V_160 ;
unsigned int V_216 = V_217 ;
struct V_194 * V_195 ;
struct V_17 * V_218 = NULL ;
struct V_193 * V_219 = NULL ;
struct V_7 * V_8 ;
T_5 V_184 ;
T_5 V_185 ;
T_5 V_220 ;
T_5 V_209 ;
int V_221 ;
int V_196 = 0 ;
int V_186 ;
int V_198 = 0 ;
int V_91 = 0 ;
int V_188 ;
int V_222 = 0 ;
int V_223 = 0 ;
int V_187 ;
bool V_224 = false ;
bool V_225 = false ;
bool V_226 = false ;
V_8 = F_128 ( F_28 ( V_3 ) ) ;
if ( ! V_8 )
return - V_227 ;
if ( V_8 -> V_77 > 1 &&
! ( V_193 -> V_228 & V_229 ) ) {
V_91 = - V_230 ;
goto V_84;
}
if ( F_49 ( V_8 ) ) {
if ( V_193 -> V_184 < V_213 -> V_231 . V_232 ) {
V_193 -> V_233 = 1 ;
V_193 -> V_205 [ 0 ] . V_206 = V_193 -> V_184 ;
if ( V_193 -> V_184 + V_193 -> V_220 <
V_213 -> V_231 . V_232 )
V_193 -> V_205 [ 0 ] . V_234 =
V_193 -> V_220 ;
else
V_193 -> V_205 [ 0 ] . V_234 =
V_213 -> V_231 . V_232 -
V_193 -> V_184 ;
V_193 -> V_205 [ 0 ] . V_202 |=
V_235 | V_236 ;
}
V_91 = 0 ;
goto V_84;
}
if ( F_125 ( V_193 -> V_211 ) < V_216 )
V_216 = F_125 ( V_193 -> V_211 ) ;
V_219 = F_42 ( V_216 , V_78 ) ;
if ( ! V_219 ) {
V_91 = - V_89 ;
goto V_84;
}
V_195 = & V_219 -> V_205 [ 0 ] ;
V_221 = F_129 ( V_216 ) ;
V_184 = V_193 -> V_184 ;
V_220 = V_193 -> V_220 ;
V_186 = F_130 ( V_8 , V_184 ) ;
V_185 = ( V_220 == ~ 0ULL ) ? V_213 -> V_231 . V_232 :
V_184 + V_220 - 1 ;
if ( V_185 > V_213 -> V_231 . V_232 )
V_185 = V_213 -> V_231 . V_232 ;
V_188 = F_122 ( V_8 , V_184 , V_185 ,
V_186 , & V_187 ) ;
V_209 = F_126 ( V_193 , V_8 , V_184 , V_185 ,
& V_186 ) ;
if ( V_209 == - V_94 ) {
V_91 = - V_94 ;
goto V_84;
}
if ( F_125 ( V_193 -> V_211 ) > * V_214 )
V_193 -> V_211 = F_129 ( * V_214 ) ;
if ( ! V_193 -> V_211 )
V_221 = 0 ;
for ( V_222 = V_186 ; V_187 > 0 ;
-- V_187 ,
V_222 = ( V_222 + 1 ) % V_8 -> V_77 ) {
T_5 V_237 ;
T_5 V_238 ;
T_5 V_207 ;
T_5 V_208 ;
T_5 V_239 ;
unsigned int V_197 ;
V_223 = V_222 ;
if ( ! ( F_123 ( V_8 , V_222 , V_184 , V_185 ,
& V_207 , & V_239 ) ) )
continue;
if ( F_44 ( V_8 -> V_40 [ V_222 ] ) ) {
V_91 = - V_38 ;
goto V_84;
}
if ( V_209 && V_222 == V_186 )
V_207 = V_209 ;
if ( V_220 != ~ 0ULL ) {
if ( V_184 + V_220 < V_184 )
V_220 = ~ 0ULL - V_184 ;
V_208 = F_131 ( V_8 , V_184 + V_220 ,
V_222 ) ;
} else {
V_208 = ~ 0ULL ;
}
if ( V_207 == V_208 )
continue;
V_237 = V_239 - V_207 ;
V_219 -> V_220 = 0 ;
V_238 = 0 ;
V_218 = F_50 ( V_10 , F_28 ( V_3 ) , V_8 ,
V_222 ) ;
if ( F_13 ( V_218 ) ) {
V_91 = F_47 ( V_218 ) ;
goto V_84;
}
V_225 = false ;
V_226 = false ;
do {
if ( V_193 -> V_211 > 0 ) {
if ( V_198 + V_221 >
V_193 -> V_211 )
V_221 = V_193 -> V_211 -
V_198 ;
}
V_207 += V_238 ;
V_219 -> V_220 = V_237 -
V_238 ;
V_237 = V_219 -> V_220 ;
V_219 -> V_211 = V_224 ? 1 : V_221 ;
V_219 -> V_233 = 0 ;
V_219 -> V_228 = V_193 -> V_228 ;
V_196 = V_8 -> V_40 [ V_222 ] -> V_47 ;
if ( V_196 < 0 ||
V_196 >= V_11 -> V_240 . V_241 ) {
V_91 = - V_94 ;
goto V_242;
}
if ( ! V_11 -> V_243 [ V_196 ] -> V_244 ) {
V_219 -> V_228 |= V_236 ;
V_219 -> V_233 = 1 ;
V_195 [ 0 ] . V_206 = V_207 ;
V_195 [ 0 ] . V_234 = V_239 -
V_207 ;
V_195 [ 0 ] . V_202 |= V_235 ;
goto V_245;
}
V_219 -> V_184 = V_207 ;
V_219 -> V_228 &= ~ V_229 ;
memcpy ( & V_213 -> V_246 , V_219 , sizeof( * V_219 ) ) ;
* V_214 = F_125 ( V_219 -> V_211 ) ;
V_91 = F_132 ( V_10 , V_218 , V_213 , V_219 ,
V_214 ) ;
if ( V_91 )
goto V_242;
V_245:
V_197 = V_219 -> V_233 ;
if ( ! V_197 ) {
V_226 = true ;
if ( V_223 == V_188 ) {
V_193 -> V_233 = 0 ;
goto V_247;
}
break;
} else if ( V_224 ) {
goto V_247;
}
if ( ! V_193 -> V_211 ) {
V_198 += V_197 ;
break;
}
V_238 =
V_195 [ V_197 - 1 ] . V_206 -
V_207 + V_195 [ V_197 - 1 ] . V_234 ;
if ( V_237 <= V_238 )
V_226 = true ;
if ( V_195 [ V_197 - 1 ] . V_202 &
V_236 )
V_195 [ V_197 - 1 ] . V_202 &=
~ V_236 ;
if ( F_133 ( V_8 ,
V_195 [ V_197 - 1 ] . V_206 +
V_195 [ V_197 - 1 ] . V_234 ,
V_222 ) >= V_213 -> V_231 . V_232 )
V_225 = true ;
F_124 ( V_193 , V_195 ,
V_196 , V_197 ,
V_198 ) ;
V_198 += V_197 ;
if ( V_198 >= V_193 -> V_211 )
V_224 = true ;
} while ( ! V_226 && ! V_225 );
F_18 ( V_10 , V_218 ) ;
V_218 = NULL ;
if ( V_223 == V_188 )
goto V_247;
}
V_247:
if ( V_8 -> V_77 > 1 )
V_193 -> V_228 |= V_229 ;
if ( ! V_193 -> V_211 )
goto V_248;
if ( ( V_223 == V_188 ) && ( V_226 || V_225 ) )
V_193 -> V_205 [ V_198 - 1 ] . V_202 |=
V_236 ;
V_248:
V_193 -> V_233 = V_198 ;
V_242:
if ( V_218 )
F_18 ( V_10 , V_218 ) ;
V_84:
F_67 ( V_219 ) ;
F_3 ( V_8 ) ;
return V_91 ;
}
static int F_134 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
struct V_249 T_7 * V_250 )
{
struct V_2 * V_11 = F_28 ( V_3 ) ;
struct V_7 * V_8 ;
int V_91 = 0 ;
V_8 = F_128 ( V_11 ) ;
if ( ! V_8 )
return - V_227 ;
V_91 = F_135 ( F_28 ( V_3 ) , V_8 , V_250 ) ;
F_3 ( V_8 ) ;
return V_91 ;
}
static int F_136 ( const struct V_9 * V_10 ,
struct V_17 * V_3 ,
struct V_251 * V_252 )
{
struct V_2 * V_11 = F_28 ( V_3 ) ;
struct V_7 * V_8 = F_128 ( V_11 ) ;
struct V_253 * V_254 = & V_252 -> V_255 ;
T_8 V_91 ;
if ( ! V_8 ) {
V_252 -> V_256 = 0 ;
V_252 -> V_257 = V_258 ;
V_252 -> V_259 = false ;
return 0 ;
}
V_252 -> V_256 = F_137 ( V_8 -> V_77 , V_8 -> V_73 ) ;
V_252 -> V_257 = V_8 -> V_116 ;
V_252 -> V_259 = F_49 ( V_8 ) ;
V_91 = F_138 ( V_8 , V_254 -> V_159 , V_254 -> V_161 ) ;
F_3 ( V_8 ) ;
return V_91 < 0 ? V_91 : 0 ;
}
static T_5 F_139 ( struct V_17 * V_3 )
{
struct V_2 * V_11 = F_28 ( V_3 ) ;
struct V_7 * V_8 = F_128 ( V_11 ) ;
T_5 V_260 ;
if ( ! V_8 )
return V_261 ;
V_260 = V_8 -> V_262 ;
F_3 ( V_8 ) ;
return V_260 ;
}
struct V_21 * F_140 ( const struct V_9 * V_10 ,
const struct V_263 * V_143 ,
struct V_264 * V_14 )
{
struct V_2 * V_11 ;
struct V_21 * V_3 ;
V_11 = F_141 ( V_168 , V_78 ) ;
if ( V_11 ) {
V_3 = F_32 ( V_11 ) ;
F_142 ( V_3 , NULL , V_14 ) ;
V_11 -> V_4 . V_265 = & V_266 ;
V_11 -> V_92 = - 1 ;
V_3 -> V_267 = & V_268 ;
} else {
V_3 = NULL ;
}
return V_3 ;
}
struct V_7 * F_128 ( struct V_2 * V_11 )
{
struct V_7 * V_8 = NULL ;
F_84 ( V_11 ) ;
if ( V_11 -> V_39 ) {
V_8 = F_40 ( V_11 -> V_39 ) ;
F_20 ( V_41 , L_20 ,
V_8 , F_73 ( & V_8 -> V_115 ) ,
V_11 -> V_59 , V_108 ) ;
}
F_86 ( V_11 ) ;
return V_8 ;
}
int F_143 ( struct V_17 * V_269 )
{
struct V_21 * V_270 ;
int V_91 = 0 ;
V_270 = F_27 ( & V_30 ( V_269 ) -> V_44 ,
& V_58 ) ;
if ( V_270 ) {
struct V_2 * V_11 = F_70 ( V_270 ) ;
F_84 ( V_11 ) ;
switch ( V_11 -> V_92 ) {
case V_93 : {
struct V_7 * V_8 ;
int V_65 ;
V_8 = V_11 -> V_39 ;
for ( V_65 = 0 ; V_65 < V_8 -> V_77 ; V_65 ++ ) {
struct V_34 * V_271 = V_8 -> V_40 [ V_65 ] ;
if ( F_44 ( V_271 ) )
continue;
if ( V_271 -> V_272 . V_273 && ! V_91 )
V_91 = V_271 -> V_272 . V_273 ;
V_271 -> V_272 . V_273 = 0 ;
}
}
case V_96 :
case V_95 :
break;
default:
F_144 () ;
}
F_86 ( V_11 ) ;
}
return V_91 ;
}
