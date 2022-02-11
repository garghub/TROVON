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
if ( ! V_14 -> V_85 [ V_83 ] ) {
F_46 ( L_9 ,
F_47 ( V_14 -> V_86 ) -> V_87 , V_83 ) ;
V_36 = - V_38 ;
goto V_84;
}
V_82 = F_48 ( V_14 -> V_85 [ V_83 ] ) ;
V_68 -> V_88 . V_89 = V_35 ;
F_39 ( V_82 , L_10 , V_83 ) ;
V_26 = F_8 ( V_10 , V_82 , V_70 , V_68 ) ;
if ( ! F_13 ( V_26 ) ) {
V_36 = F_15 ( V_10 , V_11 , V_26 , V_28 , V_65 ) ;
if ( V_36 == - V_60 ) {
-- V_65 ;
V_36 = 0 ;
continue;
}
} else {
V_36 = F_49 ( V_26 ) ;
}
if ( V_36 == 0 ) {
int V_90 = F_33 ( V_11 , V_26 ) ;
F_11 ( F_12 ( V_79 > 0 , V_79 == V_90 ) ) ;
V_79 = V_90 ;
}
}
if ( V_36 == 0 )
V_30 ( & V_11 -> V_4 ) -> V_62 += V_79 ;
} else {
V_36 = - V_91 ;
}
V_84:
return V_36 ;
}
static int F_50 ( const struct V_9 * V_10 , struct V_1 * V_14 ,
struct V_2 * V_11 , struct V_7 * V_8 ,
const struct V_15 * V_16 ,
union V_12 * V_13 )
{
F_11 ( V_8 ) ;
F_11 ( F_51 ( V_8 ) ) ;
F_11 ( ! V_11 -> V_39 ) ;
V_11 -> V_39 = F_40 ( V_8 ) ;
return 0 ;
}
static struct V_17 * F_52 ( const struct V_9 * V_10 ,
struct V_2 * V_11 ,
struct V_7 * V_8 ,
int V_92 )
{
struct V_1 * V_14 = F_2 ( F_32 ( V_11 ) -> V_6 ) ;
struct V_34 * V_35 = V_8 -> V_40 [ V_92 ] ;
struct V_66 * V_67 = F_37 ( V_10 ) ;
struct V_19 * V_70 = & V_67 -> V_71 ;
struct V_18 * V_82 ;
struct V_17 * V_36 ;
int V_83 ;
int V_93 ;
if ( V_11 -> V_94 != V_95 ) {
V_36 = NULL ;
goto V_84;
}
V_83 = V_35 -> V_47 ;
V_93 = F_45 ( V_70 , & V_35 -> V_46 , V_83 ) ;
if ( V_93 ) {
V_36 = NULL ;
goto V_84;
}
V_82 = F_48 ( V_14 -> V_85 [ V_83 ] ) ;
V_36 = F_8 ( V_10 , V_82 , V_70 , NULL ) ;
V_84:
if ( ! V_36 )
V_36 = F_53 ( - V_96 ) ;
return V_36 ;
}
static int F_54 ( const struct V_9 * V_10 , struct V_2 * V_11 ,
union V_12 * V_13 )
{
F_11 ( V_11 -> V_94 == V_97 || V_11 -> V_94 == V_98 ) ;
F_55 ( V_10 , V_11 ) ;
return 0 ;
}
static void F_56 ( const struct V_9 * V_10 , struct V_2 * V_11 ,
struct V_99 * V_100 , int V_29 )
{
struct V_17 * V_101 ;
struct V_27 * V_28 ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
T_1 * V_106 ;
V_28 = & V_11 -> V_88 . V_72 ;
F_11 ( V_28 -> V_52 [ V_29 ] == V_100 ) ;
V_101 = F_57 ( V_100 ) ;
V_103 = V_101 -> V_5 . V_6 -> V_107 ;
V_105 = F_58 ( V_103 , & V_101 -> V_5 . V_108 -> V_45 ) ;
F_17 ( V_10 , V_101 ) ;
F_59 ( & V_101 -> V_5 , L_4 , V_11 ) ;
F_18 ( V_10 , V_101 ) ;
if ( V_28 -> V_52 [ V_29 ] == V_100 ) {
V_106 = & F_37 ( V_10 ) -> V_109 ;
F_60 ( V_106 , V_110 ) ;
F_61 ( & V_105 -> V_111 , V_106 ) ;
F_62 ( V_112 ) ;
while ( 1 ) {
F_62 ( V_112 ) ;
F_23 ( & V_28 -> V_81 ) ;
if ( V_28 -> V_52 [ V_29 ] == V_100 ) {
F_24 ( & V_28 -> V_81 ) ;
F_63 () ;
} else {
F_24 ( & V_28 -> V_81 ) ;
F_62 ( V_113 ) ;
break;
}
}
F_64 ( & V_105 -> V_111 , V_106 ) ;
}
F_11 ( ! V_28 -> V_52 [ V_29 ] ) ;
}
static int F_65 ( const struct V_9 * V_10 , struct V_2 * V_11 ,
union V_12 * V_13 )
{
struct V_27 * V_28 = & V_13 -> V_72 ;
struct V_7 * V_8 = V_11 -> V_39 ;
int V_65 ;
F_38 ( V_41 , V_8 ) ;
F_55 ( V_10 , V_11 ) ;
if ( V_28 -> V_52 ) {
for ( V_65 = 0 ; V_65 < V_28 -> V_76 ; ++ V_65 ) {
struct V_99 * V_100 = V_28 -> V_52 [ V_65 ] ;
if ( V_100 ) {
F_66 ( V_10 , & V_100 -> V_114 ) ;
F_56 ( V_10 , V_11 , V_100 , V_65 ) ;
}
}
}
return 0 ;
}
static void F_67 ( const struct V_9 * V_10 , struct V_2 * V_11 ,
union V_12 * V_13 )
{
F_11 ( V_11 -> V_94 == V_97 || V_11 -> V_94 == V_98 ) ;
}
static void F_68 ( const struct V_9 * V_10 , struct V_2 * V_11 ,
union V_12 * V_13 )
{
struct V_27 * V_28 = & V_13 -> V_72 ;
if ( V_28 -> V_52 ) {
F_69 ( V_28 -> V_52 ) ;
V_28 -> V_52 = NULL ;
}
F_38 ( V_41 , V_11 -> V_39 ) ;
F_4 ( & V_11 -> V_39 ) ;
}
static void F_70 ( const struct V_9 * V_10 , struct V_2 * V_11 ,
union V_12 * V_13 )
{
F_38 ( V_41 , V_11 -> V_39 ) ;
F_4 ( & V_11 -> V_39 ) ;
}
static int F_71 ( const struct V_9 * V_10 , void * V_115 ,
T_2 V_116 , const struct V_21 * V_22 )
{
(* V_116)( V_10 , V_115 , L_11 , F_72 ( V_22 ) -> V_59 ) ;
return 0 ;
}
static int F_73 ( const struct V_9 * V_10 , void * V_115 ,
T_2 V_116 , const struct V_21 * V_22 )
{
struct V_2 * V_11 = F_72 ( V_22 ) ;
struct V_27 * V_28 = F_74 ( V_11 ) ;
struct V_7 * V_8 = V_11 -> V_39 ;
int V_65 ;
(* V_116)( V_10 , V_115 , L_12 ,
V_28 -> V_76 , V_11 -> V_59 ? L_13 : L_14 , V_8 ,
V_8 -> V_73 , F_75 ( & V_8 -> V_117 ) ,
V_8 -> V_77 , V_8 -> V_118 ) ;
for ( V_65 = 0 ; V_65 < V_28 -> V_76 ; ++ V_65 ) {
struct V_21 * V_101 ;
if ( V_28 -> V_52 [ V_65 ] ) {
V_101 = F_76 ( V_28 -> V_52 [ V_65 ] ) ;
F_77 ( V_10 , V_115 , V_116 , V_101 ) ;
} else {
(* V_116)( V_10 , V_115 , L_15 , V_65 ) ;
}
}
return 0 ;
}
static int F_78 ( const struct V_9 * V_10 , void * V_115 ,
T_2 V_116 , const struct V_21 * V_22 )
{
struct V_2 * V_11 = F_72 ( V_22 ) ;
struct V_7 * V_8 = V_11 -> V_39 ;
(* V_116)( V_10 , V_115 ,
L_16 ,
V_11 -> V_59 ? L_13 : L_14 , V_8 ,
V_8 -> V_73 , F_75 ( & V_8 -> V_117 ) ,
V_8 -> V_77 , V_8 -> V_118 ) ;
return 0 ;
}
static int F_79 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
struct V_119 * V_120 )
{
V_120 -> V_121 = 0 ;
return 0 ;
}
static int F_80 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
struct V_119 * V_120 )
{
struct V_2 * V_11 = F_28 ( V_3 ) ;
struct V_27 * V_28 = F_74 ( V_11 ) ;
struct V_119 * V_122 = & V_28 -> V_123 ;
int V_36 = 0 ;
if ( ! V_28 -> V_124 ) {
struct V_7 * V_8 = V_11 -> V_39 ;
struct V_125 * V_126 = & F_37 ( V_10 ) -> V_127 ;
T_3 V_128 = 0 ;
memset ( V_126 , 0 , sizeof( * V_126 ) ) ;
V_126 -> V_129 = V_130 ;
V_126 -> V_131 = V_130 ;
V_126 -> V_132 = V_130 ;
F_81 ( V_8 ) ;
V_36 = F_82 ( V_8 , V_126 , & V_128 ) ;
F_83 ( V_8 ) ;
if ( V_36 == 0 ) {
F_84 ( V_122 , V_126 ) ;
V_122 -> V_133 = V_128 ;
V_28 -> V_124 = 1 ;
}
}
if ( V_36 == 0 ) {
V_120 -> V_121 = V_122 -> V_121 ;
V_120 -> V_134 = V_122 -> V_134 ;
V_120 -> V_133 = V_122 -> V_133 ;
if ( V_120 -> V_135 < V_122 -> V_135 )
V_120 -> V_135 = V_122 -> V_135 ;
if ( V_120 -> V_136 < V_122 -> V_136 )
V_120 -> V_136 = V_122 -> V_136 ;
if ( V_120 -> V_137 < V_122 -> V_137 )
V_120 -> V_137 = V_122 -> V_137 ;
}
return V_36 ;
}
static enum V_138 F_85 ( struct V_7 * V_8 )
{
if ( ! V_8 )
return V_97 ;
if ( F_51 ( V_8 ) )
return V_98 ;
return V_95 ;
}
static inline void F_86 ( struct V_2 * V_11 )
{
F_20 ( V_41 , L_17 ,
V_11 , V_11 -> V_139 , V_110 ) ;
if ( V_11 -> V_139 != V_110 )
F_87 ( & V_11 -> V_140 ) ;
}
static inline void F_88 ( struct V_2 * V_11 )
{
F_20 ( V_41 , L_18 ,
V_11 , V_11 -> V_139 , V_110 ) ;
if ( V_11 -> V_139 != V_110 )
F_89 ( & V_11 -> V_140 ) ;
}
static void F_90 ( struct V_2 * V_11 )
{
F_11 ( V_11 -> V_139 != V_110 ) ;
F_91 ( & V_11 -> V_140 ) ;
F_11 ( ! V_11 -> V_139 ) ;
V_11 -> V_139 = V_110 ;
F_20 ( V_41 , L_19 ,
V_11 , V_11 -> V_139 ) ;
}
static void F_92 ( struct V_2 * V_11 )
{
F_20 ( V_41 , L_20 ,
V_11 , V_11 -> V_139 ) ;
V_11 -> V_139 = NULL ;
F_93 ( & V_11 -> V_140 ) ;
}
static int F_55 ( const struct V_9 * V_10 , struct V_2 * V_11 )
{
struct V_141 V_142 = { 0 } ;
while ( F_75 ( & V_11 -> V_143 ) > 0 ) {
F_20 ( V_41 , L_21 V_42 L_22 ,
F_21 ( F_94 ( F_32 ( V_11 ) ) ) ,
F_75 ( & V_11 -> V_143 ) ) ;
F_95 ( V_11 -> V_144 ,
F_75 ( & V_11 -> V_143 ) == 0 , & V_142 ) ;
}
return 0 ;
}
static int F_96 ( const struct V_9 * V_145 ,
struct V_2 * V_11 , struct V_7 * V_8 ,
const struct V_15 * V_16 )
{
struct V_1 * V_146 = F_1 ( V_11 ) ;
enum V_138 V_147 = F_85 ( V_8 ) ;
union V_12 * V_13 = & V_11 -> V_88 ;
const struct V_148 * V_149 ;
const struct V_148 * V_150 ;
struct V_9 * V_10 ;
int V_151 ;
int V_93 ;
F_11 ( 0 <= V_11 -> V_94 && V_11 -> V_94 < F_97 ( V_152 ) ) ;
V_10 = F_98 ( & V_151 ) ;
if ( F_13 ( V_10 ) )
return F_49 ( V_10 ) ;
F_11 ( 0 <= V_147 && V_147 < F_97 ( V_152 ) ) ;
F_20 ( V_41 , V_42 L_23 ,
F_21 ( F_94 ( F_32 ( V_11 ) ) ) ,
F_99 ( V_11 -> V_94 ) , F_99 ( V_147 ) ) ;
V_149 = & V_152 [ V_11 -> V_94 ] ;
V_150 = & V_152 [ V_147 ] ;
V_93 = F_66 ( V_10 , & V_11 -> V_4 ) ;
if ( V_93 )
goto V_84;
V_93 = V_149 -> V_153 ( V_10 , V_11 , & V_11 -> V_88 ) ;
if ( V_93 )
goto V_84;
V_149 -> V_154 ( V_10 , V_11 , & V_11 -> V_88 ) ;
F_11 ( ! F_75 ( & V_11 -> V_143 ) ) ;
F_20 ( V_41 , V_42 L_24 ,
F_21 ( F_94 ( F_32 ( V_11 ) ) ) , V_11 , V_147 ) ;
V_11 -> V_94 = V_97 ;
V_30 ( & V_11 -> V_4 ) -> V_62 -=
F_33 ( V_11 , NULL ) ;
V_93 = V_150 -> V_155 ( V_10 , V_146 , V_11 , V_8 , V_16 , V_13 ) ;
if ( V_93 ) {
struct V_156 * V_157 = F_47 ( V_146 -> V_86 ) ;
F_46 ( L_25 V_42 L_26 ,
V_157 -> V_87 , F_21 ( F_94 ( F_32 ( V_11 ) ) ) , V_93 ) ;
V_150 -> V_153 ( V_10 , V_11 , V_13 ) ;
V_150 -> V_154 ( V_10 , V_11 , V_13 ) ;
goto V_84;
}
V_150 -> V_158 ( V_10 , V_11 , V_13 ) ;
V_11 -> V_94 = V_147 ;
V_84:
F_100 ( V_10 , & V_151 ) ;
return V_93 ;
}
int F_101 ( const struct V_9 * V_10 , struct V_21 * V_3 ,
const struct V_159 * V_16 )
{
struct V_2 * V_11 = F_72 ( V_3 ) ;
struct V_1 * V_14 = F_1 ( V_11 ) ;
const struct V_15 * V_160 = F_102 ( V_16 ) ;
union V_12 * V_161 = & V_11 -> V_88 ;
const struct V_148 * V_162 ;
struct V_7 * V_8 = NULL ;
int V_93 ;
F_103 ( & V_11 -> V_140 ) ;
F_104 ( & V_11 -> V_143 , 0 ) ;
F_105 ( & V_11 -> V_144 ) ;
F_106 ( F_14 ( V_3 ) , sizeof( struct V_64 ) ) ;
V_11 -> V_94 = V_97 ;
if ( V_160 -> V_88 . V_163 . V_164 ) {
V_8 = F_107 ( V_14 -> V_86 ,
V_160 -> V_88 . V_163 . V_164 ,
V_160 -> V_88 . V_163 . V_165 ) ;
if ( F_13 ( V_8 ) )
return F_49 ( V_8 ) ;
}
V_11 -> V_94 = F_85 ( V_8 ) ;
V_162 = & V_152 [ V_11 -> V_94 ] ;
V_93 = V_162 -> V_155 ( V_10 , V_14 , V_11 , V_8 , V_160 , V_161 ) ;
if ( ! V_93 )
V_162 -> V_158 ( V_10 , V_11 , V_161 ) ;
F_3 ( V_8 ) ;
return V_93 ;
}
static int F_108 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
const struct V_15 * V_16 )
{
struct V_7 * V_8 = NULL ;
struct V_2 * V_11 = F_28 ( V_3 ) ;
int V_36 = 0 ;
if ( V_16 -> V_166 == V_167 &&
V_16 -> V_88 . V_163 . V_164 ) {
V_8 = F_107 ( F_1 ( V_11 ) -> V_86 ,
V_16 -> V_88 . V_163 . V_164 ,
V_16 -> V_88 . V_163 . V_165 ) ;
if ( F_13 ( V_8 ) )
return F_49 ( V_8 ) ;
}
F_90 ( V_11 ) ;
if ( V_16 -> V_166 == V_168 ) {
V_11 -> V_59 = true ;
V_36 = 0 ;
goto V_84;
}
if ( V_16 -> V_166 == V_169 ) {
if ( V_11 -> V_59 &&
F_75 ( & V_11 -> V_143 ) > 0 ) {
F_92 ( V_11 ) ;
V_36 = F_55 ( V_10 , V_11 ) ;
F_90 ( V_11 ) ;
}
goto V_84;
}
F_11 ( V_16 -> V_166 == V_167 ) ;
if ( ( ! V_8 && ! V_11 -> V_39 ) ||
( ( V_8 && V_11 -> V_39 ) &&
( V_11 -> V_39 -> V_118 == V_8 -> V_118 ) &&
( V_11 -> V_39 -> V_170 == V_8 -> V_170 ) ) ) {
V_11 -> V_59 = false ;
V_36 = 0 ;
goto V_84;
}
if ( F_75 ( & V_11 -> V_143 ) > 0 ) {
V_11 -> V_59 = true ;
V_36 = - V_171 ;
goto V_84;
}
V_36 = F_96 ( V_10 , V_11 , V_8 , V_16 ) ;
V_11 -> V_59 = V_36 != 0 ;
V_84:
F_92 ( V_11 ) ;
F_3 ( V_8 ) ;
F_20 ( V_41 , V_42 L_27 ,
F_21 ( F_94 ( F_32 ( V_11 ) ) ) , V_11 -> V_59 ) ;
return V_36 ;
}
static void F_109 ( const struct V_9 * V_10 , struct V_21 * V_3 )
{
struct V_2 * V_11 = F_72 ( V_3 ) ;
F_110 ( V_11 , V_153 , V_10 , V_11 , & V_11 -> V_88 ) ;
}
static void F_111 ( const struct V_9 * V_10 , struct V_21 * V_3 )
{
struct V_2 * V_11 = F_72 ( V_3 ) ;
F_110 ( V_11 , V_154 , V_10 , V_11 , & V_11 -> V_88 ) ;
F_112 ( V_3 ) ;
F_113 ( V_172 , V_11 ) ;
}
static int F_114 ( const struct V_9 * V_10 , void * V_115 ,
T_2 V_116 , const struct V_21 * V_22 )
{
return F_115 ( F_72 ( V_22 ) , V_173 , V_10 , V_115 , V_116 , V_22 ) ;
}
int F_116 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
struct V_174 * V_175 , T_4 V_176 )
{
return F_115 ( F_28 ( V_3 ) , V_177 , V_10 , V_3 , V_175 ,
V_176 ) ;
}
int F_117 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
struct V_178 * V_179 )
{
F_118 ( F_119 ( V_10 ) , V_180 ) ;
F_20 ( V_41 , V_42 L_28 ,
F_21 ( F_94 ( & V_3 -> V_5 ) ) , V_179 , V_179 -> V_181 ,
V_179 -> V_182 , V_179 -> V_183 ) ;
return F_120 ( F_28 ( V_3 ) , V_184 ,
! V_179 -> V_182 , V_10 , V_3 , V_179 ) ;
}
static int F_121 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
struct V_119 * V_120 )
{
return F_115 ( F_28 ( V_3 ) , V_185 , V_10 , V_3 , V_120 ) ;
}
static int F_122 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
const struct V_119 * V_120 , unsigned int V_186 )
{
return 0 ;
}
int F_123 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
struct V_187 * V_188 , const struct V_178 * V_179 )
{
return F_115 ( F_28 ( V_3 ) , V_189 , V_10 , V_3 , V_188 ,
V_179 ) ;
}
static int F_124 ( struct V_7 * V_8 ,
T_5 V_190 , T_5 V_191 ,
int V_192 , int * V_193 )
{
int V_194 ;
T_5 V_195 ;
T_5 V_196 ;
int V_65 , V_197 ;
if ( V_191 - V_190 > V_8 -> V_198 * V_8 -> V_77 ) {
V_194 = ( V_192 < 1 ? V_8 -> V_77 - 1 :
V_192 - 1 ) ;
* V_193 = V_8 -> V_77 ;
} else {
for ( V_197 = 0 , V_65 = V_192 ; V_197 < V_8 -> V_77 ;
V_65 = ( V_65 + 1 ) % V_8 -> V_77 , V_197 ++ ) {
if ( ! ( F_125 ( V_8 , V_65 , V_190 , V_191 ,
& V_195 , & V_196 ) ) )
break;
}
* V_193 = V_197 ;
V_194 = ( V_192 + V_197 - 1 ) % V_8 -> V_77 ;
}
return V_194 ;
}
static void F_126 ( struct V_199 * V_199 ,
struct V_200 * V_201 ,
int V_202 , unsigned int V_203 ,
int V_204 )
{
unsigned int V_205 ;
char * V_206 ;
for ( V_205 = 0 ; V_205 < V_203 ; V_205 ++ ) {
V_201 [ V_205 ] . V_207 = V_202 ;
V_201 [ V_205 ] . V_208 |= V_209 ;
}
V_206 = ( char * ) V_199 + F_127 ( V_204 ) ;
memcpy ( V_206 , V_201 , V_203 * sizeof( struct V_200 ) ) ;
}
static T_5 F_128 ( struct V_199 * V_199 ,
struct V_7 * V_8 ,
T_5 V_190 , T_5 V_191 ,
int * V_192 )
{
T_5 V_210 = V_199 -> V_211 [ 0 ] . V_212 ;
T_5 V_213 , V_214 ;
T_5 V_215 ;
int V_216 = - 1 ;
int V_65 ;
if ( ! V_199 -> V_217 || ! V_199 -> V_211 [ 0 ] . V_212 )
return 0 ;
for ( V_65 = 0 ; V_65 < V_8 -> V_77 ; V_65 ++ ) {
struct V_34 * V_35 = V_8 -> V_40 [ V_65 ] ;
if ( F_44 ( V_35 ) )
continue;
if ( V_35 -> V_47 == V_199 -> V_211 [ 0 ] . V_207 ) {
V_216 = V_65 ;
break;
}
}
if ( V_216 == - 1 )
return - V_96 ;
if ( F_125 ( V_8 , V_216 , V_190 , V_191 ,
& V_213 , & V_214 ) &&
V_210 < V_214 ) {
V_215 = V_210 ;
* V_192 = V_216 ;
} else {
V_215 = 0 ;
* V_192 = ( V_216 + 1 ) % V_8 -> V_77 ;
}
return V_215 ;
}
static int F_129 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
struct V_218 * V_219 ,
struct V_199 * V_199 , T_6 * V_220 )
{
struct V_221 * V_11 = F_2 ( V_3 -> V_5 . V_6 ) -> V_86 ;
unsigned int V_222 = V_223 ;
struct V_200 * V_201 ;
struct V_17 * V_224 = NULL ;
struct V_199 * V_225 = NULL ;
struct V_7 * V_8 ;
T_5 V_190 ;
T_5 V_191 ;
T_5 V_226 ;
T_5 V_215 ;
int V_227 ;
int V_202 = 0 ;
int V_192 ;
int V_204 = 0 ;
int V_93 = 0 ;
int V_194 ;
int V_228 = 0 ;
int V_229 = 0 ;
int V_193 ;
bool V_230 = false ;
bool V_231 = false ;
bool V_232 = false ;
V_8 = F_130 ( F_28 ( V_3 ) ) ;
if ( ! V_8 )
return - V_233 ;
if ( V_8 -> V_77 > 1 &&
! ( V_199 -> V_234 & V_235 ) ) {
V_93 = - V_236 ;
goto V_84;
}
if ( F_51 ( V_8 ) ) {
if ( V_199 -> V_190 < V_219 -> V_237 . V_238 ) {
V_199 -> V_239 = 1 ;
V_199 -> V_211 [ 0 ] . V_212 = V_199 -> V_190 ;
if ( V_199 -> V_190 + V_199 -> V_226 <
V_219 -> V_237 . V_238 )
V_199 -> V_211 [ 0 ] . V_240 =
V_199 -> V_226 ;
else
V_199 -> V_211 [ 0 ] . V_240 =
V_219 -> V_237 . V_238 -
V_199 -> V_190 ;
V_199 -> V_211 [ 0 ] . V_208 |=
V_241 | V_242 ;
}
V_93 = 0 ;
goto V_84;
}
if ( F_127 ( V_199 -> V_217 ) < V_222 )
V_222 = F_127 ( V_199 -> V_217 ) ;
V_225 = F_42 ( V_222 , V_78 ) ;
if ( ! V_225 ) {
V_93 = - V_91 ;
goto V_84;
}
V_201 = & V_225 -> V_211 [ 0 ] ;
V_227 = F_131 ( V_222 ) ;
V_190 = V_199 -> V_190 ;
V_226 = V_199 -> V_226 ;
V_192 = F_132 ( V_8 , V_190 ) ;
V_191 = ( V_226 == ~ 0ULL ) ? V_219 -> V_237 . V_238 :
V_190 + V_226 - 1 ;
if ( V_191 > V_219 -> V_237 . V_238 )
V_191 = V_219 -> V_237 . V_238 ;
V_194 = F_124 ( V_8 , V_190 , V_191 ,
V_192 , & V_193 ) ;
V_215 = F_128 ( V_199 , V_8 , V_190 , V_191 ,
& V_192 ) ;
if ( V_215 == - V_96 ) {
V_93 = - V_96 ;
goto V_84;
}
if ( F_127 ( V_199 -> V_217 ) > * V_220 )
V_199 -> V_217 = F_131 ( * V_220 ) ;
if ( ! V_199 -> V_217 )
V_227 = 0 ;
for ( V_228 = V_192 ; V_193 > 0 ;
-- V_193 ,
V_228 = ( V_228 + 1 ) % V_8 -> V_77 ) {
T_5 V_243 ;
T_5 V_244 ;
T_5 V_213 ;
T_5 V_214 ;
T_5 V_245 ;
unsigned int V_203 ;
V_229 = V_228 ;
if ( ! ( F_125 ( V_8 , V_228 , V_190 , V_191 ,
& V_213 , & V_245 ) ) )
continue;
if ( F_44 ( V_8 -> V_40 [ V_228 ] ) ) {
V_93 = - V_38 ;
goto V_84;
}
if ( V_215 && V_228 == V_192 )
V_213 = V_215 ;
if ( V_226 != ~ 0ULL ) {
if ( V_190 + V_226 < V_190 )
V_226 = ~ 0ULL - V_190 ;
V_214 = F_133 ( V_8 , V_190 + V_226 ,
V_228 ) ;
} else {
V_214 = ~ 0ULL ;
}
if ( V_213 == V_214 )
continue;
V_243 = V_245 - V_213 ;
V_225 -> V_226 = 0 ;
V_244 = 0 ;
V_224 = F_52 ( V_10 , F_28 ( V_3 ) , V_8 ,
V_228 ) ;
if ( F_13 ( V_224 ) ) {
V_93 = F_49 ( V_224 ) ;
goto V_84;
}
V_231 = false ;
V_232 = false ;
do {
if ( V_199 -> V_217 > 0 ) {
if ( V_204 + V_227 >
V_199 -> V_217 )
V_227 = V_199 -> V_217 -
V_204 ;
}
V_213 += V_244 ;
V_225 -> V_226 = V_243 -
V_244 ;
V_243 = V_225 -> V_226 ;
V_225 -> V_217 = V_230 ? 1 : V_227 ;
V_225 -> V_239 = 0 ;
V_225 -> V_234 = V_199 -> V_234 ;
V_202 = V_8 -> V_40 [ V_228 ] -> V_47 ;
if ( V_202 < 0 ||
V_202 >= V_11 -> V_246 . V_247 ) {
V_93 = - V_96 ;
goto V_248;
}
if ( ! V_11 -> V_249 [ V_202 ] -> V_250 ) {
V_225 -> V_234 |= V_242 ;
V_225 -> V_239 = 1 ;
V_201 [ 0 ] . V_212 = V_213 ;
V_201 [ 0 ] . V_240 = V_245 -
V_213 ;
V_201 [ 0 ] . V_208 |= V_241 ;
goto V_251;
}
V_225 -> V_190 = V_213 ;
V_225 -> V_234 &= ~ V_235 ;
memcpy ( & V_219 -> V_252 , V_225 , sizeof( * V_225 ) ) ;
* V_220 = F_127 ( V_225 -> V_217 ) ;
V_93 = F_134 ( V_10 , V_224 , V_219 , V_225 ,
V_220 ) ;
if ( V_93 )
goto V_248;
V_251:
V_203 = V_225 -> V_239 ;
if ( ! V_203 ) {
V_232 = true ;
if ( V_229 == V_194 ) {
V_199 -> V_239 = 0 ;
goto V_253;
}
break;
} else if ( V_230 ) {
goto V_253;
}
if ( ! V_199 -> V_217 ) {
V_204 += V_203 ;
break;
}
V_244 =
V_201 [ V_203 - 1 ] . V_212 -
V_213 + V_201 [ V_203 - 1 ] . V_240 ;
if ( V_243 <= V_244 )
V_232 = true ;
if ( V_201 [ V_203 - 1 ] . V_208 &
V_242 )
V_201 [ V_203 - 1 ] . V_208 &=
~ V_242 ;
if ( F_135 ( V_8 ,
V_201 [ V_203 - 1 ] . V_212 +
V_201 [ V_203 - 1 ] . V_240 ,
V_228 ) >= V_219 -> V_237 . V_238 )
V_231 = true ;
F_126 ( V_199 , V_201 ,
V_202 , V_203 ,
V_204 ) ;
V_204 += V_203 ;
if ( V_204 >= V_199 -> V_217 )
V_230 = true ;
} while ( ! V_232 && ! V_231 );
F_18 ( V_10 , V_224 ) ;
V_224 = NULL ;
if ( V_229 == V_194 )
goto V_253;
}
V_253:
if ( V_8 -> V_77 > 1 )
V_199 -> V_234 |= V_235 ;
if ( ! V_199 -> V_217 )
goto V_254;
if ( ( V_229 == V_194 ) && ( V_232 || V_231 ) )
V_199 -> V_211 [ V_204 - 1 ] . V_208 |=
V_242 ;
V_254:
V_199 -> V_239 = V_204 ;
V_248:
if ( V_224 )
F_18 ( V_10 , V_224 ) ;
V_84:
F_69 ( V_225 ) ;
F_3 ( V_8 ) ;
return V_93 ;
}
static int F_136 ( const struct V_9 * V_10 , struct V_17 * V_3 ,
struct V_255 T_7 * V_256 )
{
struct V_2 * V_11 = F_28 ( V_3 ) ;
struct V_7 * V_8 ;
int V_93 = 0 ;
V_8 = F_130 ( V_11 ) ;
if ( ! V_8 )
return - V_233 ;
V_93 = F_137 ( F_28 ( V_3 ) , V_8 , V_256 ) ;
F_3 ( V_8 ) ;
return V_93 ;
}
static int F_138 ( const struct V_9 * V_10 ,
struct V_17 * V_3 ,
struct V_257 * V_258 )
{
struct V_2 * V_11 = F_28 ( V_3 ) ;
struct V_7 * V_8 = F_130 ( V_11 ) ;
struct V_259 * V_260 = & V_258 -> V_261 ;
T_8 V_93 ;
if ( ! V_8 ) {
V_258 -> V_262 = 0 ;
V_258 -> V_263 = V_264 ;
return 0 ;
}
V_258 -> V_262 = F_139 ( V_8 -> V_77 , V_8 -> V_73 ) ;
V_258 -> V_263 = V_8 -> V_118 ;
V_93 = F_140 ( V_8 , V_260 -> V_164 , V_260 -> V_165 ) ;
F_3 ( V_8 ) ;
return V_93 < 0 ? V_93 : 0 ;
}
static T_5 F_141 ( struct V_17 * V_3 )
{
struct V_2 * V_11 = F_28 ( V_3 ) ;
struct V_7 * V_8 = F_130 ( V_11 ) ;
T_5 V_265 ;
if ( ! V_8 )
return V_266 ;
V_265 = V_8 -> V_267 ;
F_3 ( V_8 ) ;
return V_265 ;
}
struct V_21 * F_142 ( const struct V_9 * V_10 ,
const struct V_268 * V_145 ,
struct V_269 * V_14 )
{
struct V_2 * V_11 ;
struct V_21 * V_3 ;
V_11 = F_143 ( V_172 , V_78 ) ;
if ( V_11 ) {
V_3 = F_32 ( V_11 ) ;
F_144 ( V_3 , NULL , V_14 ) ;
V_11 -> V_4 . V_270 = & V_271 ;
V_11 -> V_94 = - 1 ;
V_3 -> V_272 = & V_273 ;
} else {
V_3 = NULL ;
}
return V_3 ;
}
struct V_7 * F_130 ( struct V_2 * V_11 )
{
struct V_7 * V_8 = NULL ;
F_86 ( V_11 ) ;
if ( V_11 -> V_39 ) {
V_8 = F_40 ( V_11 -> V_39 ) ;
F_20 ( V_41 , L_29 ,
V_8 , F_75 ( & V_8 -> V_117 ) ,
V_11 -> V_59 , V_110 ) ;
}
F_88 ( V_11 ) ;
return V_8 ;
}
int F_145 ( struct V_17 * V_274 )
{
struct V_21 * V_275 ;
int V_93 = 0 ;
V_275 = F_27 ( & V_30 ( V_274 ) -> V_44 ,
& V_58 ) ;
if ( V_275 ) {
struct V_2 * V_11 = F_72 ( V_275 ) ;
F_86 ( V_11 ) ;
switch ( V_11 -> V_94 ) {
case V_95 : {
struct V_7 * V_8 ;
int V_65 ;
V_8 = V_11 -> V_39 ;
for ( V_65 = 0 ; V_65 < V_8 -> V_77 ; V_65 ++ ) {
struct V_34 * V_276 = V_8 -> V_40 [ V_65 ] ;
if ( F_44 ( V_276 ) )
continue;
if ( V_276 -> V_277 . V_278 && ! V_93 )
V_93 = V_276 -> V_277 . V_278 ;
V_276 -> V_277 . V_278 = 0 ;
}
}
case V_98 :
case V_97 :
break;
default:
F_146 () ;
}
F_88 ( V_11 ) ;
}
return V_93 ;
}
