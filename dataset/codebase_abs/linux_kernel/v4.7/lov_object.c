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
static int F_29 ( struct V_3 * V_4 ,
struct V_11 * V_21 )
{
struct V_25 * V_26 = V_25 ( & V_4 -> V_58 ) ;
struct V_11 * V_16 ;
F_30 (o, stripe)
V_16 -> V_59 += V_26 -> V_60 ;
return V_25 ( V_21 ) -> V_60 ;
}
static int F_31 ( const struct V_1 * V_2 ,
struct V_7 * V_8 , struct V_3 * V_4 ,
const struct V_9 * V_10 ,
union V_5 * V_6 )
{
int V_31 ;
int V_61 ;
struct V_11 * V_21 ;
struct V_62 * V_63 = F_32 ( V_2 ) ;
struct V_9 * V_64 = & V_63 -> V_65 ;
struct V_66 * V_67 = V_10 -> V_68 . V_69 -> V_67 ;
struct V_13 * V_70 = & V_63 -> V_71 ;
struct V_22 * V_23 = & V_6 -> V_72 ;
if ( V_67 -> V_73 != V_74 && V_67 -> V_73 != V_75 ) {
F_33 ( V_57 , V_67 ) ;
F_34 ( 0 , L_8 ,
V_74 , V_75 , V_67 -> V_73 ) ;
}
F_7 ( ! V_4 -> V_34 ) ;
V_4 -> V_34 = F_35 ( V_67 ) ;
V_23 -> V_76 = V_67 -> V_77 ;
F_7 ( V_23 -> V_76 <= F_36 ( V_8 ) ) ;
V_23 -> V_48 = F_37 ( V_23 -> V_76 * sizeof( V_23 -> V_48 [ 0 ] ) ,
V_78 ) ;
if ( V_23 -> V_48 ) {
int V_79 = 0 ;
V_31 = 0 ;
V_64 -> V_80 = V_10 -> V_80 ;
F_38 ( & V_23 -> V_81 ) ;
for ( V_61 = 0 ; V_61 < V_23 -> V_76 && V_31 == 0 ; ++ V_61 ) {
struct V_12 * V_82 ;
struct V_29 * V_30 = V_67 -> V_35 [ V_61 ] ;
int V_83 = V_30 -> V_42 ;
if ( F_39 ( V_30 ) )
continue;
V_31 = F_40 ( V_70 , & V_30 -> V_41 ,
V_30 -> V_42 ) ;
if ( V_31 != 0 )
goto V_84;
V_82 = F_41 ( V_8 -> V_85 [ V_83 ] ) ;
V_64 -> V_68 . V_86 = V_30 ;
F_34 ( V_82 , L_9 , V_83 ) ;
V_21 = F_4 ( V_2 , V_82 , V_70 , V_64 ) ;
if ( ! F_9 ( V_21 ) ) {
V_31 = F_11 ( V_2 , V_4 , V_21 , V_23 , V_61 ) ;
if ( V_31 == - V_56 ) {
-- V_61 ;
V_31 = 0 ;
continue;
}
} else {
V_31 = F_42 ( V_21 ) ;
}
if ( V_31 == 0 ) {
int V_87 = F_29 ( V_4 , V_21 ) ;
F_7 ( F_8 ( V_79 > 0 , V_79 == V_87 ) ) ;
V_79 = V_87 ;
}
}
if ( V_31 == 0 )
V_25 ( & V_4 -> V_58 ) -> V_60 += V_79 ;
} else {
V_31 = - V_88 ;
}
V_84:
return V_31 ;
}
static int F_43 ( const struct V_1 * V_2 ,
struct V_7 * V_8 , struct V_3 * V_4 ,
const struct V_9 * V_10 ,
union V_5 * V_6 )
{
struct V_66 * V_67 = V_10 -> V_68 . V_69 -> V_67 ;
F_7 ( V_67 ) ;
F_7 ( F_44 ( V_67 ) ) ;
F_7 ( ! V_4 -> V_34 ) ;
V_4 -> V_34 = F_35 ( V_67 ) ;
return 0 ;
}
static int F_45 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 )
{
F_7 ( V_4 -> V_89 == V_90 || V_4 -> V_89 == V_91 ) ;
F_46 ( V_2 , V_4 ) ;
return 0 ;
}
static void F_47 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_92 * V_93 , int V_24 )
{
struct V_11 * V_94 ;
struct V_22 * V_23 ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
T_1 * V_99 ;
V_23 = & V_4 -> V_68 . V_72 ;
F_7 ( V_23 -> V_48 [ V_24 ] == V_93 ) ;
V_94 = F_48 ( V_93 ) ;
V_96 = V_94 -> V_47 . V_18 -> V_100 ;
V_98 = F_49 ( V_96 , & V_94 -> V_47 . V_101 -> V_40 ) ;
F_13 ( V_2 , V_94 ) ;
F_50 ( & V_94 -> V_47 , L_4 , V_4 ) ;
F_14 ( V_2 , V_94 ) ;
if ( V_23 -> V_48 [ V_24 ] == V_93 ) {
V_99 = & F_32 ( V_2 ) -> V_102 ;
F_51 ( V_99 , V_103 ) ;
F_52 ( & V_98 -> V_104 , V_99 ) ;
F_53 ( V_105 ) ;
while ( 1 ) {
F_53 ( V_105 ) ;
F_19 ( & V_23 -> V_81 ) ;
if ( V_23 -> V_48 [ V_24 ] == V_93 ) {
F_20 ( & V_23 -> V_81 ) ;
F_54 () ;
} else {
F_20 ( & V_23 -> V_81 ) ;
F_53 ( V_106 ) ;
break;
}
}
F_55 ( & V_98 -> V_104 , V_99 ) ;
}
F_7 ( ! V_23 -> V_48 [ V_24 ] ) ;
}
static int F_56 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 )
{
struct V_22 * V_23 = & V_6 -> V_72 ;
struct V_66 * V_67 = V_4 -> V_34 ;
int V_61 ;
F_33 ( V_36 , V_67 ) ;
F_46 ( V_2 , V_4 ) ;
if ( V_23 -> V_48 ) {
for ( V_61 = 0 ; V_61 < V_23 -> V_76 ; ++ V_61 ) {
struct V_92 * V_93 = V_23 -> V_48 [ V_61 ] ;
if ( V_93 ) {
F_57 ( V_2 , & V_93 -> V_107 ) ;
F_47 ( V_2 , V_4 , V_93 , V_61 ) ;
}
}
}
return 0 ;
}
static void F_58 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 )
{
F_7 ( V_4 -> V_89 == V_90 || V_4 -> V_89 == V_91 ) ;
}
static void F_59 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 )
{
struct V_22 * V_23 = & V_6 -> V_72 ;
if ( V_23 -> V_48 ) {
F_60 ( V_23 -> V_48 ) ;
V_23 -> V_48 = NULL ;
}
F_33 ( V_36 , V_4 -> V_34 ) ;
F_61 ( & V_4 -> V_34 ) ;
}
static void F_62 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 )
{
F_33 ( V_36 , V_4 -> V_34 ) ;
F_61 ( & V_4 -> V_34 ) ;
}
static int F_63 ( const struct V_1 * V_2 , void * V_108 ,
T_2 V_109 , const struct V_15 * V_16 )
{
(* V_109)( V_2 , V_108 , L_10 , F_64 ( V_16 ) -> V_55 ) ;
return 0 ;
}
static int F_65 ( const struct V_1 * V_2 , void * V_108 ,
T_2 V_109 , const struct V_15 * V_16 )
{
struct V_3 * V_4 = F_64 ( V_16 ) ;
struct V_22 * V_23 = F_66 ( V_4 ) ;
struct V_66 * V_67 = V_4 -> V_34 ;
int V_61 ;
(* V_109)( V_2 , V_108 , L_11 ,
V_23 -> V_76 , V_4 -> V_55 ? L_12 : L_13 , V_67 ,
V_67 -> V_73 , F_67 ( & V_67 -> V_110 ) ,
V_67 -> V_77 , V_67 -> V_111 ) ;
for ( V_61 = 0 ; V_61 < V_23 -> V_76 ; ++ V_61 ) {
struct V_15 * V_94 ;
if ( V_23 -> V_48 [ V_61 ] ) {
V_94 = F_68 ( V_23 -> V_48 [ V_61 ] ) ;
F_69 ( V_2 , V_108 , V_109 , V_94 ) ;
} else {
(* V_109)( V_2 , V_108 , L_14 , V_61 ) ;
}
}
return 0 ;
}
static int F_70 ( const struct V_1 * V_2 , void * V_108 ,
T_2 V_109 , const struct V_15 * V_16 )
{
struct V_3 * V_4 = F_64 ( V_16 ) ;
struct V_66 * V_67 = V_4 -> V_34 ;
(* V_109)( V_2 , V_108 ,
L_15 ,
V_4 -> V_55 ? L_12 : L_13 , V_67 ,
V_67 -> V_73 , F_67 ( & V_67 -> V_110 ) ,
V_67 -> V_77 , V_67 -> V_111 ) ;
return 0 ;
}
static int F_71 ( const struct V_1 * V_2 , struct V_11 * V_112 ,
struct V_113 * V_114 )
{
V_114 -> V_115 = 0 ;
return 0 ;
}
static int F_72 ( const struct V_1 * V_2 , struct V_11 * V_112 ,
struct V_113 * V_114 )
{
struct V_3 * V_4 = F_24 ( V_112 ) ;
struct V_22 * V_23 = F_66 ( V_4 ) ;
struct V_113 * V_116 = & V_23 -> V_117 ;
int V_31 = 0 ;
if ( ! V_23 -> V_118 ) {
struct V_66 * V_67 = V_4 -> V_34 ;
struct V_119 * V_120 = & F_32 ( V_2 ) -> V_121 ;
T_3 V_122 = 0 ;
memset ( V_120 , 0 , sizeof( * V_120 ) ) ;
V_120 -> V_123 = V_124 ;
V_120 -> V_125 = V_124 ;
V_120 -> V_126 = V_124 ;
F_73 ( V_67 ) ;
V_31 = F_74 ( V_67 , V_120 , & V_122 ) ;
F_75 ( V_67 ) ;
if ( V_31 == 0 ) {
F_76 ( V_116 , V_120 ) ;
V_116 -> V_127 = V_122 ;
V_23 -> V_118 = 1 ;
}
}
if ( V_31 == 0 ) {
V_114 -> V_115 = V_116 -> V_115 ;
V_114 -> V_128 = V_116 -> V_128 ;
V_114 -> V_127 = V_116 -> V_127 ;
if ( V_114 -> V_129 < V_116 -> V_129 )
V_114 -> V_129 = V_116 -> V_129 ;
if ( V_114 -> V_130 < V_116 -> V_130 )
V_114 -> V_130 = V_116 -> V_130 ;
if ( V_114 -> V_131 < V_116 -> V_131 )
V_114 -> V_131 = V_116 -> V_131 ;
}
return V_31 ;
}
static enum V_132 F_77 ( struct V_66 * V_67 )
{
if ( ! V_67 )
return V_90 ;
if ( F_44 ( V_67 ) )
return V_91 ;
return V_133 ;
}
static inline void F_78 ( struct V_3 * V_4 )
{
if ( V_4 -> V_134 != V_103 )
F_79 ( & V_4 -> V_135 ) ;
}
static inline void F_80 ( struct V_3 * V_4 )
{
if ( V_4 -> V_134 != V_103 )
F_81 ( & V_4 -> V_135 ) ;
}
static void F_82 ( struct V_3 * V_4 )
{
F_7 ( V_4 -> V_134 != V_103 ) ;
F_83 ( & V_4 -> V_135 ) ;
F_7 ( ! V_4 -> V_134 ) ;
V_4 -> V_134 = V_103 ;
}
static void F_84 ( struct V_3 * V_4 )
{
V_4 -> V_134 = NULL ;
F_85 ( & V_4 -> V_135 ) ;
}
static int F_46 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_136 V_137 = { 0 } ;
while ( F_67 ( & V_4 -> V_138 ) > 0 ) {
F_16 ( V_36 , L_16 V_37 L_17 ,
F_17 ( F_86 ( F_28 ( V_4 ) ) ) ,
F_67 ( & V_4 -> V_138 ) ) ;
F_87 ( V_4 -> V_139 ,
F_67 ( & V_4 -> V_138 ) == 0 , & V_137 ) ;
}
return 0 ;
}
static int F_88 ( const struct V_1 * V_140 ,
struct V_3 * V_4 ,
const struct V_9 * V_10 )
{
int V_31 ;
enum V_132 V_141 = V_90 ;
union V_5 * V_6 = & V_4 -> V_68 ;
const struct V_142 * V_143 ;
const struct V_142 * V_144 ;
void * V_108 ;
struct V_1 * V_2 ;
int V_145 ;
F_7 ( 0 <= V_4 -> V_89 && V_4 -> V_89 < F_89 ( V_146 ) ) ;
if ( V_10 -> V_68 . V_69 )
V_141 = F_77 ( V_10 -> V_68 . V_69 -> V_67 ) ;
F_7 ( 0 <= V_141 && V_141 < F_89 ( V_146 ) ) ;
V_108 = F_90 () ;
V_2 = F_91 ( & V_145 ) ;
if ( F_9 ( V_2 ) ) {
F_92 ( V_108 ) ;
return F_42 ( V_2 ) ;
}
F_16 ( V_36 , V_37 L_18 ,
F_17 ( F_86 ( F_28 ( V_4 ) ) ) ,
F_93 ( V_4 -> V_89 ) , F_93 ( V_141 ) ) ;
V_143 = & V_146 [ V_4 -> V_89 ] ;
V_144 = & V_146 [ V_141 ] ;
V_31 = F_57 ( V_2 , & V_4 -> V_58 ) ;
if ( V_31 != 0 )
goto V_84;
V_31 = V_143 -> V_147 ( V_2 , V_4 , & V_4 -> V_68 ) ;
if ( V_31 == 0 ) {
V_143 -> V_148 ( V_2 , V_4 , & V_4 -> V_68 ) ;
F_7 ( F_67 ( & V_4 -> V_138 ) == 0 ) ;
V_4 -> V_89 = V_90 ;
V_31 = V_144 -> V_149 ( V_2 ,
F_94 ( V_4 -> V_58 . V_47 . V_18 ) ,
V_4 , V_10 , V_6 ) ;
if ( V_31 == 0 ) {
V_144 -> V_150 ( V_2 , V_4 , V_6 ) ;
V_4 -> V_89 = V_141 ;
} else {
V_144 -> V_147 ( V_2 , V_4 , V_6 ) ;
V_144 -> V_148 ( V_2 , V_4 , V_6 ) ;
}
}
V_84:
F_95 ( V_2 , & V_145 ) ;
F_92 ( V_108 ) ;
return V_31 ;
}
int F_96 ( const struct V_1 * V_2 , struct V_15 * V_112 ,
const struct V_151 * V_10 )
{
struct V_7 * V_8 = F_94 ( V_112 -> V_18 ) ;
struct V_3 * V_4 = F_64 ( V_112 ) ;
const struct V_9 * V_152 = F_97 ( V_10 ) ;
union V_5 * V_153 = & V_4 -> V_68 ;
const struct V_142 * V_154 ;
int V_31 ;
F_98 ( & V_4 -> V_135 ) ;
F_99 ( & V_4 -> V_138 , 0 ) ;
F_100 ( & V_4 -> V_139 ) ;
F_101 ( F_10 ( V_112 ) , sizeof( struct V_155 ) ) ;
V_4 -> V_89 = F_77 ( V_152 -> V_68 . V_69 -> V_67 ) ;
V_154 = & V_146 [ V_4 -> V_89 ] ;
V_31 = V_154 -> V_149 ( V_2 , V_8 , V_4 , V_152 , V_153 ) ;
if ( V_31 == 0 )
V_154 -> V_150 ( V_2 , V_4 , V_153 ) ;
return V_31 ;
}
static int F_102 ( const struct V_1 * V_2 , struct V_11 * V_112 ,
const struct V_9 * V_10 )
{
struct V_66 * V_67 = NULL ;
struct V_3 * V_4 = F_24 ( V_112 ) ;
int V_31 = 0 ;
F_82 ( V_4 ) ;
if ( V_10 -> V_156 == V_157 ) {
V_4 -> V_55 = true ;
V_31 = 0 ;
goto V_84;
}
if ( V_10 -> V_156 == V_158 ) {
if ( V_4 -> V_55 &&
F_67 ( & V_4 -> V_138 ) > 0 ) {
F_84 ( V_4 ) ;
V_31 = F_46 ( V_2 , V_4 ) ;
F_82 ( V_4 ) ;
}
goto V_84;
}
F_7 ( V_10 -> V_156 == V_159 ) ;
if ( V_10 -> V_68 . V_69 )
V_67 = V_10 -> V_68 . V_69 -> V_67 ;
if ( ( ! V_67 && ! V_4 -> V_34 ) ||
( ( V_67 && V_4 -> V_34 ) &&
( V_4 -> V_34 -> V_111 == V_67 -> V_111 ) &&
( V_4 -> V_34 -> V_160 == V_67 -> V_160 ) ) ) {
V_4 -> V_55 = false ;
V_31 = 0 ;
goto V_84;
}
if ( F_67 ( & V_4 -> V_138 ) > 0 ) {
V_4 -> V_55 = true ;
V_31 = - V_161 ;
goto V_84;
}
V_31 = F_88 ( V_2 , V_4 , V_10 ) ;
V_4 -> V_55 = V_31 != 0 ;
V_84:
F_84 ( V_4 ) ;
F_16 ( V_36 , V_37 L_19 ,
F_17 ( F_86 ( F_28 ( V_4 ) ) ) , V_4 -> V_55 ) ;
return V_31 ;
}
static void F_103 ( const struct V_1 * V_2 , struct V_15 * V_112 )
{
struct V_3 * V_4 = F_64 ( V_112 ) ;
F_104 ( V_4 , V_147 , V_2 , V_4 , & V_4 -> V_68 ) ;
}
static void F_105 ( const struct V_1 * V_2 , struct V_15 * V_112 )
{
struct V_3 * V_4 = F_64 ( V_112 ) ;
F_104 ( V_4 , V_148 , V_2 , V_4 , & V_4 -> V_68 ) ;
F_106 ( V_112 ) ;
F_107 ( V_162 , V_4 ) ;
}
static int F_108 ( const struct V_1 * V_2 , void * V_108 ,
T_2 V_109 , const struct V_15 * V_16 )
{
return F_109 ( F_64 ( V_16 ) , V_163 , V_2 , V_108 , V_109 , V_16 ) ;
}
int F_110 ( const struct V_1 * V_2 , struct V_11 * V_112 ,
struct V_164 * V_165 , T_4 V_166 )
{
return F_109 ( F_24 ( V_112 ) , V_167 , V_2 , V_112 , V_165 ,
V_166 ) ;
}
int F_111 ( const struct V_1 * V_2 , struct V_11 * V_112 ,
struct V_168 * V_169 )
{
F_112 ( F_113 ( V_2 ) , V_170 ) ;
return F_114 ( F_24 ( V_112 ) , V_171 ,
! V_169 -> V_172 , V_2 , V_112 , V_169 ) ;
}
static int F_115 ( const struct V_1 * V_2 , struct V_11 * V_112 ,
struct V_113 * V_114 )
{
return F_109 ( F_24 ( V_112 ) , V_173 , V_2 , V_112 , V_114 ) ;
}
static int F_116 ( const struct V_1 * V_2 , struct V_11 * V_112 ,
const struct V_113 * V_114 , unsigned V_174 )
{
return 0 ;
}
int F_117 ( const struct V_1 * V_2 , struct V_11 * V_112 ,
struct V_175 * V_176 , const struct V_168 * V_169 )
{
return F_109 ( F_24 ( V_112 ) , V_177 , V_2 , V_112 , V_176 ,
V_169 ) ;
}
struct V_15 * F_118 ( const struct V_1 * V_2 ,
const struct V_178 * V_140 ,
struct V_179 * V_8 )
{
struct V_3 * V_4 ;
struct V_15 * V_112 ;
V_4 = F_119 ( V_162 , V_78 ) ;
if ( V_4 ) {
V_112 = F_28 ( V_4 ) ;
F_120 ( V_112 , NULL , V_8 ) ;
V_4 -> V_58 . V_180 = & V_181 ;
V_4 -> V_89 = - 1 ;
V_112 -> V_182 = & V_183 ;
} else {
V_112 = NULL ;
}
return V_112 ;
}
static struct V_66 * F_121 ( struct V_3 * V_4 )
{
struct V_66 * V_67 = NULL ;
F_78 ( V_4 ) ;
if ( V_4 -> V_34 ) {
V_67 = F_35 ( V_4 -> V_34 ) ;
F_16 ( V_36 , L_20 ,
V_67 , F_67 ( & V_67 -> V_110 ) ,
V_4 -> V_55 , V_103 ) ;
}
F_80 ( V_4 ) ;
return V_67 ;
}
struct V_66 * F_122 ( struct V_11 * V_184 )
{
struct V_15 * V_185 ;
struct V_66 * V_67 = NULL ;
if ( ! V_184 )
return NULL ;
V_185 = F_23 ( & V_25 ( V_184 ) -> V_39 ,
& V_54 ) ;
if ( V_185 )
V_67 = F_121 ( F_64 ( V_185 ) ) ;
return V_67 ;
}
void F_123 ( struct V_11 * V_140 , struct V_66 * V_67 )
{
if ( V_67 )
F_61 ( & V_67 ) ;
}
int F_124 ( struct V_11 * V_186 )
{
struct V_15 * V_185 ;
int V_187 = 0 ;
V_185 = F_23 ( & V_25 ( V_186 ) -> V_39 ,
& V_54 ) ;
if ( V_185 ) {
struct V_3 * V_4 = F_64 ( V_185 ) ;
F_78 ( V_4 ) ;
switch ( V_4 -> V_89 ) {
case V_133 : {
struct V_66 * V_67 ;
int V_61 ;
V_67 = V_4 -> V_34 ;
for ( V_61 = 0 ; V_61 < V_67 -> V_77 ; V_61 ++ ) {
struct V_29 * V_188 = V_67 -> V_35 [ V_61 ] ;
if ( F_39 ( V_188 ) )
continue;
if ( V_188 -> V_189 . V_190 && ! V_187 )
V_187 = V_188 -> V_189 . V_190 ;
V_188 -> V_189 . V_190 = 0 ;
}
}
case V_91 :
case V_90 :
break;
default:
F_125 () ;
}
F_80 ( V_4 ) ;
}
return V_187 ;
}
