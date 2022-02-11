void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 )
F_2 ( & V_4 ) ;
}
static void F_3 ( const struct V_5 * V_6 ,
struct V_7 * V_8 ,
union V_9 * V_10 )
{
}
static int F_4 ( const struct V_5 * V_6 ,
struct V_11 * V_12 , struct V_7 * V_8 ,
const struct V_13 * V_14 ,
union V_9 * V_10 )
{
return 0 ;
}
static void F_5 ( const struct V_5 * V_6 ,
struct V_7 * V_8 ,
union V_9 * V_10 )
{
}
static struct V_1 * F_6 ( const struct V_5 * V_6 ,
struct V_15 * V_12 ,
const struct V_16 * V_17 ,
const struct V_13 * V_14 )
{
struct V_18 * V_19 ;
V_19 = F_7 ( V_6 , F_8 ( V_12 ) , V_17 , & V_14 -> V_20 ) ;
F_9 ( F_10 ( ! F_11 ( V_19 ) , V_19 -> V_21 -> V_22 == & V_23 ) ) ;
return F_12 ( V_19 ) ;
}
static int F_13 ( const struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_1 * V_24 , struct V_25 * V_26 ,
int V_27 )
{
struct V_28 * V_29 ;
struct V_28 * V_30 ;
struct V_28 * V_31 ;
struct V_32 * V_33 ;
int V_34 ;
if ( F_14 ( V_35 ) ) {
F_15 ( V_6 , V_24 ) ;
F_16 ( V_6 , V_24 ) ;
return - V_36 ;
}
V_29 = V_28 ( F_17 ( V_8 ) ) ;
V_30 = V_28 ( V_24 ) ;
V_33 = V_8 -> V_37 -> V_38 [ V_27 ] ;
F_18 ( V_39 , V_40 L_1 V_40 L_2 V_41
L_3 ,
F_19 ( & V_30 -> V_42 . V_43 ) , V_30 , V_27 ,
F_19 ( & V_29 -> V_42 . V_43 ) , V_29 , F_20 ( & V_33 -> V_44 ) ,
V_33 -> V_45 , V_33 -> V_46 ) ;
F_21 ( & V_30 -> V_47 ) ;
V_31 = V_30 -> V_48 ;
if ( ! V_31 ) {
V_30 -> V_48 = V_29 ;
F_22 ( & V_30 -> V_47 ) ;
V_30 -> V_49 = V_29 -> V_49 + 1 ;
F_23 ( & V_24 -> V_50 , L_4 , V_8 ) ;
V_26 -> V_51 [ V_27 ] = F_24 ( V_24 ) ;
V_26 -> V_51 [ V_27 ] -> V_52 = V_8 ;
V_26 -> V_51 [ V_27 ] -> V_53 = V_27 ;
V_34 = 0 ;
} else {
struct V_18 * V_54 ;
struct V_7 * V_55 ;
unsigned int V_56 = V_39 ;
F_22 ( & V_30 -> V_47 ) ;
V_54 = F_25 ( & V_31 -> V_42 , & V_57 ) ;
F_9 ( V_54 ) ;
V_55 = F_26 ( F_12 ( V_54 ) ) ;
if ( V_55 -> V_58 ) {
F_27 ( V_6 , & V_24 -> V_50 ) ;
V_34 = - V_59 ;
} else {
V_56 = V_60 ;
V_34 = - V_36 ;
}
F_28 ( V_56 , V_6 , & V_24 -> V_50 ,
L_5 , V_27 ) ;
F_28 ( V_56 , V_6 , V_54 , L_6 ) ;
F_29 ( V_56 , V_6 , F_30 ( V_8 ) , L_7 ) ;
F_16 ( V_6 , V_24 ) ;
}
return V_34 ;
}
static int F_31 ( struct V_7 * V_8 ,
struct V_1 * V_24 )
{
struct V_28 * V_29 = V_28 ( & V_8 -> V_61 ) ;
struct V_1 * V_19 ;
if ( ! V_24 )
return V_29 -> V_62 - V_8 -> V_61 . V_63 -
F_32 ( sizeof( struct V_64 ) ) ;
F_33 (o, stripe)
V_19 -> V_63 += V_29 -> V_62 ;
return V_28 ( V_24 ) -> V_62 ;
}
static int F_34 ( const struct V_5 * V_6 ,
struct V_11 * V_12 , struct V_7 * V_8 ,
const struct V_13 * V_14 ,
union V_9 * V_10 )
{
int V_34 ;
int V_65 ;
struct V_1 * V_24 ;
struct V_66 * V_67 = F_35 ( V_6 ) ;
struct V_13 * V_68 = & V_67 -> V_69 ;
struct V_3 * V_4 = V_14 -> V_70 . V_71 -> V_4 ;
struct V_16 * V_72 = & V_67 -> V_73 ;
struct V_25 * V_26 = & V_10 -> V_74 ;
if ( V_4 -> V_75 != V_76 && V_4 -> V_75 != V_77 ) {
F_36 ( V_60 , V_4 ) ;
F_37 ( 0 , L_8 ,
V_76 , V_77 , V_4 -> V_75 ) ;
}
F_9 ( ! V_8 -> V_37 ) ;
V_8 -> V_37 = F_38 ( V_4 ) ;
V_8 -> V_58 = true ;
V_26 -> V_78 = V_4 -> V_79 ;
F_9 ( V_26 -> V_78 <= F_39 ( V_12 ) ) ;
V_26 -> V_51 = F_40 ( V_26 -> V_78 * sizeof( V_26 -> V_51 [ 0 ] ) ,
V_80 ) ;
if ( V_26 -> V_51 ) {
int V_81 = 0 ;
V_34 = 0 ;
V_68 -> V_82 = V_14 -> V_82 ;
F_41 ( & V_26 -> V_83 ) ;
for ( V_65 = 0 ; V_65 < V_26 -> V_78 && V_34 == 0 ; ++ V_65 ) {
struct V_15 * V_84 ;
struct V_32 * V_33 = V_4 -> V_38 [ V_65 ] ;
int V_85 = V_33 -> V_45 ;
if ( F_42 ( V_33 ) )
continue;
V_34 = F_43 ( V_72 , & V_33 -> V_44 ,
V_33 -> V_45 ) ;
if ( V_34 != 0 )
goto V_86;
V_84 = F_44 ( V_12 -> V_87 [ V_85 ] ) ;
V_68 -> V_70 . V_88 = V_33 ;
F_37 ( V_84 , L_9 , V_85 ) ;
V_24 = F_6 ( V_6 , V_84 , V_72 , V_68 ) ;
if ( ! F_11 ( V_24 ) ) {
V_34 = F_13 ( V_6 , V_8 , V_24 , V_26 , V_65 ) ;
if ( V_34 == - V_59 ) {
-- V_65 ;
V_34 = 0 ;
continue;
}
} else {
V_34 = F_45 ( V_24 ) ;
}
if ( V_34 == 0 ) {
int V_89 = F_31 ( V_8 , V_24 ) ;
F_9 ( F_10 ( V_81 > 0 , V_81 == V_89 ) ) ;
V_81 = V_89 ;
}
}
if ( V_34 == 0 )
V_28 ( & V_8 -> V_61 ) -> V_62 += V_81 ;
} else {
V_34 = - V_90 ;
}
V_86:
return V_34 ;
}
static int F_46 ( const struct V_5 * V_6 ,
struct V_11 * V_12 , struct V_7 * V_8 ,
const struct V_13 * V_14 ,
union V_9 * V_10 )
{
struct V_3 * V_4 = V_14 -> V_70 . V_71 -> V_4 ;
F_9 ( V_4 ) ;
F_9 ( F_47 ( V_4 ) ) ;
F_9 ( ! V_8 -> V_37 ) ;
V_8 -> V_37 = F_38 ( V_4 ) ;
return 0 ;
}
static int F_48 ( const struct V_5 * V_6 , struct V_7 * V_8 ,
union V_9 * V_10 )
{
F_9 ( V_8 -> V_91 == V_92 || V_8 -> V_91 == V_93 ) ;
F_49 ( V_6 , V_8 ) ;
return 0 ;
}
static void F_50 ( const struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_94 * V_95 , int V_27 )
{
struct V_1 * V_96 ;
struct V_25 * V_26 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
T_1 * V_101 ;
V_26 = & V_8 -> V_70 . V_74 ;
F_9 ( V_26 -> V_51 [ V_27 ] == V_95 ) ;
V_96 = F_51 ( V_95 ) ;
V_98 = V_96 -> V_50 . V_21 -> V_102 ;
V_100 = F_52 ( V_98 , & V_96 -> V_50 . V_103 -> V_43 ) ;
F_15 ( V_6 , V_96 ) ;
F_53 ( & V_96 -> V_50 , L_4 , V_8 ) ;
F_16 ( V_6 , V_96 ) ;
if ( V_26 -> V_51 [ V_27 ] == V_95 ) {
V_101 = & F_35 ( V_6 ) -> V_104 ;
F_54 ( V_101 , V_105 ) ;
F_55 ( & V_100 -> V_106 , V_101 ) ;
F_56 ( V_107 ) ;
while ( 1 ) {
F_56 ( V_107 ) ;
F_21 ( & V_26 -> V_83 ) ;
if ( V_26 -> V_51 [ V_27 ] == V_95 ) {
F_22 ( & V_26 -> V_83 ) ;
F_57 () ;
} else {
F_22 ( & V_26 -> V_83 ) ;
F_56 ( V_108 ) ;
break;
}
}
F_58 ( & V_100 -> V_106 , V_101 ) ;
}
F_9 ( ! V_26 -> V_51 [ V_27 ] ) ;
}
static int F_59 ( const struct V_5 * V_6 , struct V_7 * V_8 ,
union V_9 * V_10 )
{
struct V_25 * V_26 = & V_10 -> V_74 ;
struct V_3 * V_4 = V_8 -> V_37 ;
int V_65 ;
F_36 ( V_39 , V_4 ) ;
F_49 ( V_6 , V_8 ) ;
if ( V_26 -> V_51 ) {
for ( V_65 = 0 ; V_65 < V_26 -> V_78 ; ++ V_65 ) {
struct V_94 * V_95 = V_26 -> V_51 [ V_65 ] ;
if ( V_95 ) {
F_60 ( V_6 , & V_95 -> V_109 ) ;
F_50 ( V_6 , V_8 , V_95 , V_65 ) ;
}
}
}
return 0 ;
}
static void F_61 ( const struct V_5 * V_6 , struct V_7 * V_8 ,
union V_9 * V_10 )
{
F_9 ( V_8 -> V_91 == V_92 || V_8 -> V_91 == V_93 ) ;
}
static void F_62 ( const struct V_5 * V_6 , struct V_7 * V_8 ,
union V_9 * V_10 )
{
struct V_25 * V_26 = & V_10 -> V_74 ;
if ( V_26 -> V_51 ) {
F_63 ( V_26 -> V_51 ) ;
V_26 -> V_51 = NULL ;
}
F_36 ( V_39 , V_8 -> V_37 ) ;
F_2 ( & V_8 -> V_37 ) ;
}
static void F_64 ( const struct V_5 * V_6 , struct V_7 * V_8 ,
union V_9 * V_10 )
{
F_36 ( V_39 , V_8 -> V_37 ) ;
F_2 ( & V_8 -> V_37 ) ;
}
static int F_65 ( const struct V_5 * V_6 , void * V_110 ,
T_2 V_111 , const struct V_18 * V_19 )
{
(* V_111)( V_6 , V_110 , L_10 , F_66 ( V_19 ) -> V_58 ) ;
return 0 ;
}
static int F_67 ( const struct V_5 * V_6 , void * V_110 ,
T_2 V_111 , const struct V_18 * V_19 )
{
struct V_7 * V_8 = F_66 ( V_19 ) ;
struct V_25 * V_26 = F_68 ( V_8 ) ;
struct V_3 * V_4 = V_8 -> V_37 ;
int V_65 ;
(* V_111)( V_6 , V_110 , L_11 ,
V_26 -> V_78 , V_8 -> V_58 ? L_12 : L_13 , V_4 ,
V_4 -> V_75 , F_69 ( & V_4 -> V_112 ) ,
V_4 -> V_79 , V_4 -> V_113 ) ;
for ( V_65 = 0 ; V_65 < V_26 -> V_78 ; ++ V_65 ) {
struct V_18 * V_96 ;
if ( V_26 -> V_51 [ V_65 ] ) {
V_96 = F_70 ( V_26 -> V_51 [ V_65 ] ) ;
F_71 ( V_6 , V_110 , V_111 , V_96 ) ;
} else {
(* V_111)( V_6 , V_110 , L_14 , V_65 ) ;
}
}
return 0 ;
}
static int F_72 ( const struct V_5 * V_6 , void * V_110 ,
T_2 V_111 , const struct V_18 * V_19 )
{
struct V_7 * V_8 = F_66 ( V_19 ) ;
struct V_3 * V_4 = V_8 -> V_37 ;
(* V_111)( V_6 , V_110 ,
L_15 ,
V_8 -> V_58 ? L_12 : L_13 , V_4 ,
V_4 -> V_75 , F_69 ( & V_4 -> V_112 ) ,
V_4 -> V_79 , V_4 -> V_113 ) ;
return 0 ;
}
static int F_73 ( const struct V_5 * V_6 , struct V_1 * V_114 ,
struct V_115 * V_116 )
{
V_116 -> V_117 = 0 ;
return 0 ;
}
static int F_74 ( const struct V_5 * V_6 , struct V_1 * V_114 ,
struct V_115 * V_116 )
{
struct V_7 * V_8 = F_26 ( V_114 ) ;
struct V_25 * V_26 = F_68 ( V_8 ) ;
struct V_115 * V_118 = & V_26 -> V_119 ;
int V_34 = 0 ;
if ( ! V_26 -> V_120 ) {
struct V_3 * V_4 = V_8 -> V_37 ;
struct V_121 * V_122 = & F_35 ( V_6 ) -> V_123 ;
T_3 V_124 = 0 ;
memset ( V_122 , 0 , sizeof( * V_122 ) ) ;
V_122 -> V_125 = V_126 ;
V_122 -> V_127 = V_126 ;
V_122 -> V_128 = V_126 ;
F_75 ( V_4 ) ;
V_34 = F_76 ( V_4 , V_122 , & V_124 ) ;
F_77 ( V_4 ) ;
if ( V_34 == 0 ) {
F_78 ( V_118 , V_122 ) ;
V_118 -> V_129 = V_124 ;
V_26 -> V_120 = 1 ;
}
}
if ( V_34 == 0 ) {
V_116 -> V_117 = V_118 -> V_117 ;
V_116 -> V_130 = V_118 -> V_130 ;
V_116 -> V_129 = V_118 -> V_129 ;
if ( V_116 -> V_131 < V_118 -> V_131 )
V_116 -> V_131 = V_118 -> V_131 ;
if ( V_116 -> V_132 < V_118 -> V_132 )
V_116 -> V_132 = V_118 -> V_132 ;
if ( V_116 -> V_133 < V_118 -> V_133 )
V_116 -> V_133 = V_118 -> V_133 ;
}
return V_34 ;
}
static enum V_134 F_79 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return V_92 ;
if ( F_47 ( V_4 ) )
return V_93 ;
return V_135 ;
}
static inline void F_80 ( struct V_7 * V_8 )
{
if ( V_8 -> V_136 != V_105 )
F_81 ( & V_8 -> V_137 ) ;
}
static inline void F_82 ( struct V_7 * V_8 )
{
if ( V_8 -> V_136 != V_105 )
F_83 ( & V_8 -> V_137 ) ;
}
static void F_84 ( struct V_7 * V_8 )
{
F_9 ( V_8 -> V_136 != V_105 ) ;
F_85 ( & V_8 -> V_137 ) ;
F_9 ( ! V_8 -> V_136 ) ;
V_8 -> V_136 = V_105 ;
}
static void F_86 ( struct V_7 * V_8 )
{
V_8 -> V_136 = NULL ;
F_87 ( & V_8 -> V_137 ) ;
}
static int F_49 ( const struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_138 V_139 = { 0 } ;
while ( F_69 ( & V_8 -> V_140 ) > 0 ) {
F_18 ( V_39 , L_16 V_40 L_17 ,
F_19 ( F_88 ( F_30 ( V_8 ) ) ) ,
F_69 ( & V_8 -> V_140 ) ) ;
F_89 ( V_8 -> V_141 ,
F_69 ( & V_8 -> V_140 ) == 0 , & V_139 ) ;
}
return 0 ;
}
static int F_90 ( const struct V_5 * V_2 ,
struct V_7 * V_8 ,
const struct V_13 * V_14 )
{
int V_34 ;
enum V_134 V_142 = V_92 ;
union V_9 * V_10 = & V_8 -> V_70 ;
const struct V_143 * V_144 ;
const struct V_143 * V_145 ;
void * V_110 ;
struct V_5 * V_6 ;
int V_146 ;
F_9 ( 0 <= V_8 -> V_91 && V_8 -> V_91 < F_91 ( V_147 ) ) ;
if ( V_14 -> V_70 . V_71 )
V_142 = F_79 ( V_14 -> V_70 . V_71 -> V_4 ) ;
F_9 ( 0 <= V_142 && V_142 < F_91 ( V_147 ) ) ;
V_110 = F_92 () ;
V_6 = F_93 ( & V_146 ) ;
if ( F_11 ( V_6 ) ) {
F_94 ( V_110 ) ;
return F_45 ( V_6 ) ;
}
F_18 ( V_39 , V_40 L_18 ,
F_19 ( F_88 ( F_30 ( V_8 ) ) ) ,
F_95 ( V_8 -> V_91 ) , F_95 ( V_142 ) ) ;
V_144 = & V_147 [ V_8 -> V_91 ] ;
V_145 = & V_147 [ V_142 ] ;
V_34 = F_60 ( V_6 , & V_8 -> V_61 ) ;
if ( V_34 != 0 )
goto V_86;
V_34 = V_144 -> V_148 ( V_6 , V_8 , & V_8 -> V_70 ) ;
if ( V_34 == 0 ) {
V_144 -> V_149 ( V_6 , V_8 , & V_8 -> V_70 ) ;
F_9 ( F_69 ( & V_8 -> V_140 ) == 0 ) ;
V_8 -> V_91 = V_92 ;
V_28 ( & V_8 -> V_61 ) -> V_62 -=
F_31 ( V_8 , NULL ) ;
V_34 = V_145 -> V_150 ( V_6 ,
F_96 ( V_8 -> V_61 . V_50 . V_21 ) ,
V_8 , V_14 , V_10 ) ;
if ( V_34 == 0 ) {
V_145 -> V_151 ( V_6 , V_8 , V_10 ) ;
V_8 -> V_91 = V_142 ;
} else {
V_145 -> V_148 ( V_6 , V_8 , V_10 ) ;
V_145 -> V_149 ( V_6 , V_8 , V_10 ) ;
}
}
V_86:
F_97 ( V_6 , & V_146 ) ;
F_94 ( V_110 ) ;
return V_34 ;
}
int F_98 ( const struct V_5 * V_6 , struct V_18 * V_114 ,
const struct V_152 * V_14 )
{
struct V_11 * V_12 = F_96 ( V_114 -> V_21 ) ;
struct V_7 * V_8 = F_66 ( V_114 ) ;
const struct V_13 * V_153 = F_99 ( V_14 ) ;
union V_9 * V_154 = & V_8 -> V_70 ;
const struct V_143 * V_155 ;
int V_34 ;
F_100 ( & V_8 -> V_137 ) ;
F_101 ( & V_8 -> V_140 , 0 ) ;
F_102 ( & V_8 -> V_141 ) ;
F_103 ( F_12 ( V_114 ) , sizeof( struct V_64 ) ) ;
V_8 -> V_91 = F_79 ( V_153 -> V_70 . V_71 -> V_4 ) ;
V_155 = & V_147 [ V_8 -> V_91 ] ;
V_34 = V_155 -> V_150 ( V_6 , V_12 , V_8 , V_153 , V_154 ) ;
if ( V_34 == 0 )
V_155 -> V_151 ( V_6 , V_8 , V_154 ) ;
return V_34 ;
}
static int F_104 ( const struct V_5 * V_6 , struct V_1 * V_114 ,
const struct V_13 * V_14 )
{
struct V_3 * V_4 = NULL ;
struct V_7 * V_8 = F_26 ( V_114 ) ;
int V_34 = 0 ;
F_84 ( V_8 ) ;
if ( V_14 -> V_156 == V_157 ) {
V_8 -> V_58 = true ;
V_34 = 0 ;
goto V_86;
}
if ( V_14 -> V_156 == V_158 ) {
if ( V_8 -> V_58 &&
F_69 ( & V_8 -> V_140 ) > 0 ) {
F_86 ( V_8 ) ;
V_34 = F_49 ( V_6 , V_8 ) ;
F_84 ( V_8 ) ;
}
goto V_86;
}
F_9 ( V_14 -> V_156 == V_159 ) ;
if ( V_14 -> V_70 . V_71 )
V_4 = V_14 -> V_70 . V_71 -> V_4 ;
if ( ( ! V_4 && ! V_8 -> V_37 ) ||
( ( V_4 && V_8 -> V_37 ) &&
( V_8 -> V_37 -> V_113 == V_4 -> V_113 ) &&
( V_8 -> V_37 -> V_160 == V_4 -> V_160 ) ) ) {
V_8 -> V_58 = false ;
V_34 = 0 ;
goto V_86;
}
if ( F_69 ( & V_8 -> V_140 ) > 0 ) {
V_8 -> V_58 = true ;
V_34 = - V_161 ;
goto V_86;
}
V_34 = F_90 ( V_6 , V_8 , V_14 ) ;
V_8 -> V_58 = V_34 != 0 ;
V_86:
F_86 ( V_8 ) ;
F_18 ( V_39 , V_40 L_19 ,
F_19 ( F_88 ( F_30 ( V_8 ) ) ) , V_8 -> V_58 ) ;
return V_34 ;
}
static void F_105 ( const struct V_5 * V_6 , struct V_18 * V_114 )
{
struct V_7 * V_8 = F_66 ( V_114 ) ;
F_106 ( V_8 , V_148 , V_6 , V_8 , & V_8 -> V_70 ) ;
}
static void F_107 ( const struct V_5 * V_6 , struct V_18 * V_114 )
{
struct V_7 * V_8 = F_66 ( V_114 ) ;
F_106 ( V_8 , V_149 , V_6 , V_8 , & V_8 -> V_70 ) ;
F_108 ( V_114 ) ;
F_109 ( V_162 , V_8 ) ;
}
static int F_110 ( const struct V_5 * V_6 , void * V_110 ,
T_2 V_111 , const struct V_18 * V_19 )
{
return F_111 ( F_66 ( V_19 ) , V_163 , V_6 , V_110 , V_111 , V_19 ) ;
}
int F_112 ( const struct V_5 * V_6 , struct V_1 * V_114 ,
struct V_164 * V_165 , T_4 V_166 )
{
return F_111 ( F_26 ( V_114 ) , V_167 , V_6 , V_114 , V_165 ,
V_166 ) ;
}
int F_113 ( const struct V_5 * V_6 , struct V_1 * V_114 ,
struct V_168 * V_169 )
{
F_114 ( F_115 ( V_6 ) , V_170 ) ;
return F_116 ( F_26 ( V_114 ) , V_171 ,
! V_169 -> V_172 , V_6 , V_114 , V_169 ) ;
}
static int F_117 ( const struct V_5 * V_6 , struct V_1 * V_114 ,
struct V_115 * V_116 )
{
return F_111 ( F_26 ( V_114 ) , V_173 , V_6 , V_114 , V_116 ) ;
}
static int F_118 ( const struct V_5 * V_6 , struct V_1 * V_114 ,
const struct V_115 * V_116 , unsigned int V_174 )
{
return 0 ;
}
int F_119 ( const struct V_5 * V_6 , struct V_1 * V_114 ,
struct V_175 * V_176 , const struct V_168 * V_169 )
{
return F_111 ( F_26 ( V_114 ) , V_177 , V_6 , V_114 , V_176 ,
V_169 ) ;
}
static int F_120 ( const struct V_5 * V_6 , struct V_1 * V_114 ,
struct V_178 T_5 * V_179 )
{
struct V_7 * V_8 = F_26 ( V_114 ) ;
struct V_3 * V_4 ;
int V_180 = 0 ;
V_4 = F_121 ( V_8 ) ;
if ( ! V_4 )
return - V_181 ;
V_180 = F_122 ( F_26 ( V_114 ) , V_4 , V_179 ) ;
F_1 ( V_114 , V_4 ) ;
return V_180 ;
}
struct V_18 * F_123 ( const struct V_5 * V_6 ,
const struct V_182 * V_2 ,
struct V_183 * V_12 )
{
struct V_7 * V_8 ;
struct V_18 * V_114 ;
V_8 = F_124 ( V_162 , V_80 ) ;
if ( V_8 ) {
V_114 = F_30 ( V_8 ) ;
F_125 ( V_114 , NULL , V_12 ) ;
V_8 -> V_61 . V_184 = & V_185 ;
V_8 -> V_91 = - 1 ;
V_114 -> V_186 = & V_187 ;
} else {
V_114 = NULL ;
}
return V_114 ;
}
struct V_3 * F_121 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = NULL ;
F_80 ( V_8 ) ;
if ( V_8 -> V_37 ) {
V_4 = F_38 ( V_8 -> V_37 ) ;
F_18 ( V_39 , L_20 ,
V_4 , F_69 ( & V_4 -> V_112 ) ,
V_8 -> V_58 , V_105 ) ;
}
F_82 ( V_8 ) ;
return V_4 ;
}
struct V_3 * F_126 ( struct V_1 * V_188 )
{
struct V_18 * V_189 ;
struct V_3 * V_4 = NULL ;
if ( ! V_188 )
return NULL ;
V_189 = F_25 ( & V_28 ( V_188 ) -> V_42 ,
& V_57 ) ;
if ( V_189 )
V_4 = F_121 ( F_66 ( V_189 ) ) ;
return V_4 ;
}
int F_127 ( struct V_1 * V_190 )
{
struct V_18 * V_189 ;
int V_180 = 0 ;
V_189 = F_25 ( & V_28 ( V_190 ) -> V_42 ,
& V_57 ) ;
if ( V_189 ) {
struct V_7 * V_8 = F_66 ( V_189 ) ;
F_80 ( V_8 ) ;
switch ( V_8 -> V_91 ) {
case V_135 : {
struct V_3 * V_4 ;
int V_65 ;
V_4 = V_8 -> V_37 ;
for ( V_65 = 0 ; V_65 < V_4 -> V_79 ; V_65 ++ ) {
struct V_32 * V_191 = V_4 -> V_38 [ V_65 ] ;
if ( F_42 ( V_191 ) )
continue;
if ( V_191 -> V_192 . V_193 && ! V_180 )
V_180 = V_191 -> V_192 . V_193 ;
V_191 -> V_192 . V_193 = 0 ;
}
}
case V_93 :
case V_92 :
break;
default:
F_128 () ;
}
F_82 ( V_8 ) ;
}
return V_180 ;
}
