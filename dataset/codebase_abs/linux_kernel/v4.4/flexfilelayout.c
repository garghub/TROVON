static struct V_1 *
F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_3 ) ;
if ( V_5 ) {
F_3 ( & V_5 -> V_6 ) ;
F_3 ( & V_5 -> V_7 ) ;
return & V_5 -> V_8 ;
} else
return NULL ;
}
static void
F_4 ( struct V_1 * V_9 )
{
struct V_10 * V_11 , * V_12 ;
F_5 (err, n, &FF_LAYOUT_FROM_HDR(lo)->error_list,
list) {
F_6 ( & V_11 -> V_13 ) ;
F_7 ( V_11 ) ;
}
F_7 ( F_8 ( V_9 ) ) ;
}
static int F_9 ( struct V_14 * V_15 , T_2 * V_16 )
{
T_3 * V_17 ;
V_17 = F_10 ( V_15 , V_18 ) ;
if ( F_11 ( V_17 == NULL ) )
return - V_19 ;
memcpy ( V_16 , V_17 , V_18 ) ;
F_12 ( L_1 , V_20 ,
V_17 [ 0 ] , V_17 [ 1 ] , V_17 [ 2 ] , V_17 [ 3 ] ) ;
return 0 ;
}
static int F_13 ( struct V_14 * V_15 , struct V_21 * V_22 )
{
T_3 * V_17 ;
V_17 = F_10 ( V_15 , V_23 ) ;
if ( F_11 ( ! V_17 ) )
return - V_19 ;
memcpy ( V_22 , V_17 , V_23 ) ;
F_14 ( V_22 ) ;
return 0 ;
}
static int F_15 ( struct V_14 * V_15 , struct V_24 * V_25 )
{
T_3 * V_17 ;
V_17 = F_10 ( V_15 , 4 ) ;
if ( F_11 ( ! V_17 ) )
return - V_19 ;
V_25 -> V_26 = F_16 ( V_17 ++ ) ;
if ( V_25 -> V_26 > sizeof( struct V_24 ) ) {
F_17 ( V_27 L_2 ,
V_25 -> V_26 ) ;
return - V_28 ;
}
V_17 = F_10 ( V_15 , V_25 -> V_26 ) ;
if ( F_11 ( ! V_17 ) )
return - V_19 ;
memcpy ( & V_25 -> V_29 , V_17 , V_25 -> V_26 ) ;
F_12 ( L_3 , V_20 , V_25 -> V_26 ) ;
return 0 ;
}
static int
F_18 ( struct V_14 * V_15 , T_4 * V_30 )
{
T_3 * V_17 ;
int V_31 ;
V_17 = F_10 ( V_15 , 4 ) ;
if ( F_11 ( ! V_17 ) )
return - V_19 ;
V_31 = F_16 ( V_17 ++ ) ;
if ( V_31 < 0 )
return - V_32 ;
F_12 ( L_4 , V_20 , V_31 ) ;
V_17 = F_10 ( V_15 , V_31 ) ;
if ( F_11 ( ! V_17 ) )
return - V_19 ;
if ( ! F_19 ( ( char * ) V_17 , V_31 , V_30 ) )
return - V_32 ;
return 0 ;
}
static bool F_20 ( const struct V_33 * V_34 ,
const struct V_33 * V_35 )
{
int V_36 , V_37 ;
if ( V_34 -> V_38 != V_35 -> V_38 )
return false ;
for ( V_36 = 0 ; V_36 < V_34 -> V_38 ; V_36 ++ ) {
bool V_39 = false ;
for ( V_37 = 0 ; V_37 < V_35 -> V_38 ; V_36 ++ ) {
if ( F_21 ( & V_34 -> V_40 [ V_36 ] ,
& V_35 -> V_40 [ V_37 ] ) == 0 ) {
V_39 = true ;
break;
}
}
if ( ! V_39 )
return false ;
}
return true ;
}
static struct V_33 *
F_22 ( struct V_1 * V_9 ,
struct V_33 * V_41 )
{
struct V_4 * V_42 = F_8 ( V_9 ) ;
struct V_33 * V_43 ;
struct V_2 * V_2 = V_9 -> V_44 ;
F_23 ( & V_2 -> V_45 ) ;
F_24 (pos, &ff_layout->mirrors, mirrors) {
if ( V_41 -> V_46 != V_43 -> V_46 )
continue;
if ( ! F_20 ( V_41 , V_43 ) )
continue;
if ( F_25 ( & V_43 -> V_47 ) ) {
F_26 ( & V_2 -> V_45 ) ;
return V_43 ;
}
}
F_27 ( & V_41 -> V_7 , & V_42 -> V_7 ) ;
V_41 -> V_48 = V_9 ;
F_26 ( & V_2 -> V_45 ) ;
return V_41 ;
}
static void
F_28 ( struct V_33 * V_41 )
{
struct V_2 * V_2 ;
if ( V_41 -> V_48 == NULL )
return;
V_2 = V_41 -> V_48 -> V_44 ;
F_23 ( & V_2 -> V_45 ) ;
F_6 ( & V_41 -> V_7 ) ;
F_26 ( & V_2 -> V_45 ) ;
V_41 -> V_48 = NULL ;
}
static struct V_33 * F_29 ( T_1 V_3 )
{
struct V_33 * V_41 ;
V_41 = F_2 ( sizeof( * V_41 ) , V_3 ) ;
if ( V_41 != NULL ) {
F_30 ( & V_41 -> V_49 ) ;
F_31 ( & V_41 -> V_47 , 1 ) ;
F_3 ( & V_41 -> V_7 ) ;
}
return V_41 ;
}
static void F_32 ( struct V_33 * V_41 )
{
F_28 ( V_41 ) ;
F_7 ( V_41 -> V_40 ) ;
if ( V_41 -> V_50 )
F_33 ( V_41 -> V_50 ) ;
F_34 ( V_41 -> V_46 ) ;
F_7 ( V_41 ) ;
}
static void F_35 ( struct V_33 * V_41 )
{
if ( V_41 != NULL && F_36 ( & V_41 -> V_47 ) )
F_32 ( V_41 ) ;
}
static void F_37 ( struct V_51 * V_52 )
{
int V_36 ;
if ( V_52 -> V_53 ) {
for ( V_36 = 0 ; V_36 < V_52 -> V_54 ; V_36 ++ ) {
F_35 ( V_52 -> V_53 [ V_36 ] ) ;
}
F_7 ( V_52 -> V_53 ) ;
V_52 -> V_53 = NULL ;
}
}
static int F_38 ( struct V_55 * V_56 )
{
int V_57 = 0 ;
F_12 ( L_5 , V_20 ) ;
if ( V_56 -> V_58 . V_59 != 0 ||
V_56 -> V_58 . V_60 != V_61 ) {
F_12 ( L_6 ,
V_20 ) ;
V_57 = - V_32 ;
}
F_12 ( L_7 , V_20 , V_57 ) ;
return V_57 ;
}
static void F_39 ( struct V_51 * V_52 )
{
if ( V_52 ) {
F_37 ( V_52 ) ;
F_7 ( V_52 ) ;
}
}
static bool
F_40 ( const struct V_62 * V_63 ,
const struct V_62 * V_64 )
{
T_5 V_65 , V_66 ;
if ( V_63 -> V_67 != V_64 -> V_67 )
return V_63 -> V_67 != V_68 ;
V_65 = F_41 ( V_63 -> V_59 , V_63 -> V_60 ) ;
V_66 = F_41 ( V_64 -> V_59 , V_64 -> V_60 ) ;
if ( V_65 < V_64 -> V_59 )
return false ;
if ( V_66 < V_63 -> V_59 )
return true ;
return V_64 -> V_59 <= V_63 -> V_59 ;
}
static bool
F_42 ( struct V_69 * V_70 ,
struct V_69 * V_71 )
{
T_5 V_72 , V_73 ;
if ( V_70 -> V_74 . V_67 != V_71 -> V_74 . V_67 )
return false ;
V_73 = F_41 ( V_71 -> V_74 . V_59 ,
V_71 -> V_74 . V_60 ) ;
if ( V_73 < V_70 -> V_74 . V_59 )
return false ;
V_72 = F_41 ( V_70 -> V_74 . V_59 ,
V_70 -> V_74 . V_60 ) ;
if ( V_72 < V_71 -> V_74 . V_59 )
return false ;
if ( V_72 < V_73 )
V_72 = V_73 ;
if ( V_70 -> V_74 . V_59 < V_71 -> V_74 . V_59 )
V_70 -> V_74 . V_59 = V_71 -> V_74 . V_59 ;
V_70 -> V_74 . V_60 = F_43 ( V_70 -> V_74 . V_59 ,
V_72 ) ;
if ( F_44 ( V_75 , & V_71 -> V_76 ) )
F_45 ( V_75 , & V_70 -> V_76 ) ;
if ( F_44 ( V_77 , & V_71 -> V_76 ) )
F_45 ( V_77 , & V_70 -> V_76 ) ;
return true ;
}
static void
F_46 ( struct V_1 * V_9 ,
struct V_69 * V_78 ,
struct V_79 * V_80 )
{
F_47 ( V_9 , V_78 ,
F_40 ,
F_42 ,
V_80 ) ;
}
static void F_48 ( struct V_51 * V_52 )
{
int V_36 , V_37 ;
for ( V_36 = 0 ; V_36 < V_52 -> V_54 - 1 ; V_36 ++ ) {
for ( V_37 = V_36 + 1 ; V_37 < V_52 -> V_54 ; V_37 ++ )
if ( V_52 -> V_53 [ V_36 ] -> V_81 <
V_52 -> V_53 [ V_37 ] -> V_81 )
F_49 ( V_52 -> V_53 [ V_36 ] ,
V_52 -> V_53 [ V_37 ] ) ;
}
}
static void F_50 ( struct V_51 * V_52 )
{
struct V_82 * V_83 ;
int V_36 ;
if ( ! ( V_52 -> V_84 & V_85 ) )
return;
for ( V_36 = 0 ; V_36 < V_52 -> V_54 ; V_36 ++ ) {
V_83 = & V_52 -> V_53 [ V_36 ] -> V_46 -> V_86 ;
F_51 ( V_87 , & V_83 -> V_84 ) ;
}
}
static struct V_69 *
F_52 ( struct V_1 * V_88 ,
struct V_55 * V_56 ,
T_1 V_3 )
{
struct V_69 * V_57 ;
struct V_51 * V_52 = NULL ;
struct V_14 V_89 ;
struct V_90 V_91 ;
struct V_92 * V_93 ;
T_5 V_94 ;
T_4 V_54 ;
T_3 * V_17 ;
int V_36 , V_95 ;
F_12 ( L_5 , V_20 ) ;
V_93 = F_53 ( V_3 ) ;
if ( ! V_93 )
return F_54 ( - V_96 ) ;
F_55 ( & V_89 , & V_91 , V_56 -> V_97 -> V_98 ,
V_56 -> V_97 -> V_31 ) ;
F_56 ( & V_89 , F_57 ( V_93 ) , V_99 ) ;
V_95 = - V_100 ;
V_17 = F_10 ( & V_89 , 8 + 4 ) ;
if ( ! V_17 )
goto V_101;
V_17 = F_58 ( V_17 , & V_94 ) ;
V_54 = F_16 ( V_17 ++ ) ;
F_12 ( L_8 , V_20 ,
V_94 , V_54 ) ;
if ( V_54 > V_102 ||
V_54 == 0 )
goto V_101;
V_95 = - V_96 ;
V_52 = F_2 ( sizeof( * V_52 ) , V_3 ) ;
if ( ! V_52 )
goto V_101;
V_52 -> V_54 = V_54 ;
V_52 -> V_94 = V_94 ;
V_52 -> V_53 = F_59 ( V_52 -> V_54 ,
sizeof( V_52 -> V_53 [ 0 ] ) , V_3 ) ;
if ( V_52 -> V_53 == NULL )
goto V_101;
for ( V_36 = 0 ; V_36 < V_52 -> V_54 ; V_36 ++ ) {
struct V_33 * V_41 ;
struct V_21 V_22 ;
struct V_82 * V_103 ;
T_4 V_104 ;
T_4 V_105 ;
int V_37 ;
V_95 = - V_100 ;
V_17 = F_10 ( & V_89 , 4 ) ;
if ( ! V_17 )
goto V_101;
V_104 = F_16 ( V_17 ) ;
if ( V_104 != 1 )
goto V_101;
V_52 -> V_53 [ V_36 ] = F_29 ( V_3 ) ;
if ( V_52 -> V_53 [ V_36 ] == NULL ) {
V_95 = - V_96 ;
goto V_101;
}
V_52 -> V_53 [ V_36 ] -> V_104 = V_104 ;
V_95 = F_13 ( & V_89 , & V_22 ) ;
if ( V_95 )
goto V_101;
V_103 = F_60 ( F_61 ( V_88 -> V_44 ) ,
& V_22 , V_88 -> V_106 ,
V_3 ) ;
if ( V_103 )
V_52 -> V_53 [ V_36 ] -> V_46 =
F_62 ( V_103 ) ;
else
goto V_101;
V_95 = - V_100 ;
V_17 = F_10 ( & V_89 , 4 ) ;
if ( ! V_17 )
goto V_101;
V_52 -> V_53 [ V_36 ] -> V_81 = F_16 ( V_17 ) ;
V_95 = F_9 ( & V_89 , & V_52 -> V_53 [ V_36 ] -> V_16 ) ;
if ( V_95 )
goto V_101;
V_17 = F_10 ( & V_89 , 4 ) ;
if ( ! V_17 )
goto V_101;
V_105 = F_16 ( V_17 ) ;
V_52 -> V_53 [ V_36 ] -> V_40 =
F_2 ( V_105 * sizeof( struct V_24 ) ,
V_3 ) ;
if ( V_52 -> V_53 [ V_36 ] -> V_40 == NULL ) {
V_95 = - V_96 ;
goto V_101;
}
for ( V_37 = 0 ; V_37 < V_105 ; V_37 ++ ) {
V_95 = F_15 ( & V_89 ,
& V_52 -> V_53 [ V_36 ] -> V_40 [ V_37 ] ) ;
if ( V_95 )
goto V_101;
}
V_52 -> V_53 [ V_36 ] -> V_38 = V_105 ;
V_95 = F_18 ( & V_89 , & V_52 -> V_53 [ V_36 ] -> V_107 ) ;
if ( V_95 )
goto V_101;
V_95 = F_18 ( & V_89 , & V_52 -> V_53 [ V_36 ] -> V_108 ) ;
if ( V_95 )
goto V_101;
V_41 = F_22 ( V_88 , V_52 -> V_53 [ V_36 ] ) ;
if ( V_41 != V_52 -> V_53 [ V_36 ] ) {
F_32 ( V_52 -> V_53 [ V_36 ] ) ;
V_52 -> V_53 [ V_36 ] = V_41 ;
}
F_12 ( L_9 , V_20 ,
V_52 -> V_53 [ V_36 ] -> V_107 ,
V_52 -> V_53 [ V_36 ] -> V_108 ) ;
}
V_17 = F_10 ( & V_89 , 4 ) ;
if ( V_17 )
V_52 -> V_84 = F_16 ( V_17 ) ;
F_48 ( V_52 ) ;
V_95 = F_38 ( V_56 ) ;
if ( V_95 )
goto V_101;
F_50 ( V_52 ) ;
V_57 = & V_52 -> V_8 ;
F_12 ( L_10 , V_20 ) ;
V_109:
F_63 ( V_93 ) ;
return V_57 ;
V_101:
F_39 ( V_52 ) ;
V_57 = F_54 ( V_95 ) ;
F_12 ( L_11 , V_20 , V_95 ) ;
goto V_109;
}
static bool F_64 ( struct V_1 * V_48 )
{
struct V_69 * V_78 ;
F_24 (lseg, &layout->plh_segs, pls_list)
if ( V_78 -> V_74 . V_67 == V_110 )
return true ;
return false ;
}
static void
F_65 ( struct V_69 * V_78 )
{
struct V_51 * V_52 = F_66 ( V_78 ) ;
F_12 ( L_5 , V_20 ) ;
if ( V_78 -> V_74 . V_67 == V_110 ) {
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_5 = F_8 ( V_78 -> V_111 ) ;
V_2 = V_5 -> V_8 . V_44 ;
F_23 ( & V_2 -> V_45 ) ;
if ( ! F_64 ( V_78 -> V_111 ) ) {
V_5 -> V_112 . V_113 = 0 ;
F_7 ( V_5 -> V_112 . V_114 ) ;
V_5 -> V_112 . V_114 = NULL ;
}
F_26 ( & V_2 -> V_45 ) ;
}
F_39 ( V_52 ) ;
}
static int
F_67 ( struct V_51 * V_52 )
{
return 1 ;
}
static void
F_68 ( struct V_115 * V_116 , T_6 V_117 )
{
if ( F_69 ( & V_116 -> V_118 ) == 1 ) {
V_116 -> V_119 = V_117 ;
}
}
static T_6
F_70 ( struct V_115 * V_116 , T_6 V_117 )
{
T_6 V_120 ;
if ( F_71 ( & V_116 -> V_118 ) < 0 )
F_72 ( 1 ) ;
V_120 = V_116 -> V_119 ;
V_116 -> V_119 = V_117 ;
return F_73 ( V_117 , V_120 ) ;
}
static bool
F_74 ( struct V_33 * V_41 ,
struct V_121 * V_122 ,
T_6 V_117 )
{
static const T_6 V_123 = { 0 } ;
T_7 V_124 = V_125 ;
F_68 ( & V_122 -> V_126 , V_117 ) ;
if ( F_75 ( V_41 -> V_119 , V_123 ) )
V_41 -> V_119 = V_117 ;
if ( F_75 ( V_41 -> V_127 , V_123 ) )
V_41 -> V_127 = V_117 ;
if ( V_128 != 0 )
V_124 = ( T_7 ) V_128 * 1000LL ;
if ( F_76 ( F_73 ( V_117 , V_41 -> V_127 ) ) >=
V_124 ) {
V_41 -> V_127 = V_117 ;
return true ;
}
return false ;
}
static void
F_77 ( struct V_121 * V_122 ,
T_8 V_129 )
{
struct V_130 * V_131 = & V_122 -> V_132 ;
V_131 -> V_133 ++ ;
V_131 -> V_134 += V_129 ;
}
static void
F_78 ( struct V_121 * V_122 ,
T_8 V_129 ,
T_8 V_135 ,
T_6 V_136 ,
T_6 V_137 )
{
struct V_130 * V_131 = & V_122 -> V_132 ;
T_6 V_138 = F_73 ( V_136 , V_137 ) ;
T_6 V_116 ;
V_131 -> V_139 ++ ;
V_131 -> V_140 += V_135 ;
V_131 -> V_141 += V_129 - V_135 ;
V_116 = F_70 ( & V_122 -> V_126 , V_136 ) ;
V_131 -> V_142 =
F_79 ( V_131 -> V_142 , V_116 ) ;
V_131 -> V_143 =
F_79 ( V_131 -> V_143 ,
V_138 ) ;
}
static void
F_80 ( struct V_2 * V_2 ,
struct V_33 * V_41 ,
T_8 V_129 , T_6 V_117 )
{
bool V_144 ;
F_23 ( & V_41 -> V_49 ) ;
V_144 = F_74 ( V_41 , & V_41 -> V_145 , V_117 ) ;
F_77 ( & V_41 -> V_145 , V_129 ) ;
F_26 ( & V_41 -> V_49 ) ;
if ( V_144 )
F_81 ( V_2 , V_146 ) ;
}
static void
F_82 ( struct V_147 * V_148 ,
struct V_33 * V_41 ,
T_8 V_129 ,
T_8 V_135 )
{
F_23 ( & V_41 -> V_49 ) ;
F_78 ( & V_41 -> V_145 ,
V_129 , V_135 ,
F_83 () , V_148 -> V_149 ) ;
F_26 ( & V_41 -> V_49 ) ;
}
static void
F_84 ( struct V_2 * V_2 ,
struct V_33 * V_41 ,
T_8 V_129 , T_6 V_117 )
{
bool V_144 ;
F_23 ( & V_41 -> V_49 ) ;
V_144 = F_74 ( V_41 , & V_41 -> V_150 , V_117 ) ;
F_77 ( & V_41 -> V_150 , V_129 ) ;
F_26 ( & V_41 -> V_49 ) ;
if ( V_144 )
F_81 ( V_2 , V_151 ) ;
}
static void
F_85 ( struct V_147 * V_148 ,
struct V_33 * V_41 ,
T_8 V_129 ,
T_8 V_135 ,
enum V_152 V_153 )
{
if ( V_153 == V_154 )
V_129 = V_135 = 0 ;
F_23 ( & V_41 -> V_49 ) ;
F_78 ( & V_41 -> V_150 ,
V_129 , V_135 , F_83 () , V_148 -> V_149 ) ;
F_26 ( & V_41 -> V_49 ) ;
}
static int
F_86 ( struct V_69 * V_78 ,
struct V_155 * V_156 ,
T_1 V_3 )
{
struct V_51 * V_52 = F_66 ( V_78 ) ;
struct V_157 * V_114 ;
int V_26 ;
if ( V_156 -> V_158 -> V_113 != 0 ) {
return 0 ;
}
V_26 = F_67 ( V_52 ) * F_87 ( V_78 ) ;
V_114 = F_59 ( V_26 , sizeof( struct V_157 ) ,
V_3 ) ;
if ( ! V_114 )
return - V_96 ;
else {
int V_36 ;
F_23 ( V_156 -> V_49 ) ;
if ( V_156 -> V_158 -> V_113 != 0 )
F_7 ( V_114 ) ;
else {
V_156 -> V_158 -> V_114 = V_114 ;
V_156 -> V_158 -> V_113 = V_26 ;
for ( V_36 = 0 ; V_36 < V_26 ; V_36 ++ ) {
F_3 ( & V_114 [ V_36 ] . V_159 ) ;
F_3 ( & V_114 [ V_36 ] . V_160 ) ;
V_114 [ V_36 ] . V_161 . V_153 =
V_162 ;
}
}
F_26 ( V_156 -> V_49 ) ;
return 0 ;
}
}
static struct V_163 *
F_88 ( struct V_69 * V_78 ,
int V_164 ,
int * V_165 )
{
struct V_51 * V_52 = F_66 ( V_78 ) ;
struct V_163 * V_158 ;
int V_166 ;
for ( V_166 = V_164 ; V_166 < V_52 -> V_54 ; V_166 ++ ) {
V_158 = F_89 ( V_78 , V_166 , false ) ;
if ( V_158 ) {
* V_165 = V_166 ;
return V_158 ;
}
}
return NULL ;
}
static void
F_90 ( struct V_167 * V_168 ,
struct V_169 * V_170 )
{
struct V_171 * V_172 ;
struct V_33 * V_41 ;
struct V_163 * V_158 ;
int V_173 ;
if ( ! V_168 -> V_174 )
V_168 -> V_174 = F_91 ( V_168 -> V_175 ,
V_170 -> V_176 ,
0 ,
V_61 ,
V_68 ,
V_146 ) ;
if ( V_168 -> V_174 == NULL )
goto V_177;
V_158 = F_88 ( V_168 -> V_174 , 0 , & V_173 ) ;
if ( ! V_158 )
goto V_177;
V_41 = F_92 ( V_168 -> V_174 , V_173 ) ;
V_168 -> V_178 = V_173 ;
V_172 = & V_168 -> V_179 [ 0 ] ;
V_172 -> V_180 = V_41 -> V_46 -> V_181 [ 0 ] . V_182 ;
return;
V_177:
F_93 ( V_168 -> V_174 ) ;
V_168 -> V_174 = NULL ;
F_94 ( V_168 ) ;
}
static void
F_95 ( struct V_167 * V_168 ,
struct V_169 * V_170 )
{
struct V_33 * V_41 ;
struct V_171 * V_172 ;
struct V_155 V_156 ;
struct V_163 * V_158 ;
int V_36 ;
int V_183 ;
if ( ! V_168 -> V_174 )
V_168 -> V_174 = F_91 ( V_168 -> V_175 ,
V_170 -> V_176 ,
0 ,
V_61 ,
V_110 ,
V_184 ) ;
if ( V_168 -> V_174 == NULL )
goto V_177;
F_96 ( & V_156 , V_168 -> V_175 , V_168 -> V_185 ) ;
V_183 = F_86 ( V_168 -> V_174 , & V_156 , V_184 ) ;
if ( V_183 < 0 )
goto V_177;
if ( F_72 ( V_168 -> V_186 !=
F_87 ( V_168 -> V_174 ) ) )
goto V_177;
for ( V_36 = 0 ; V_36 < V_168 -> V_186 ; V_36 ++ ) {
V_158 = F_89 ( V_168 -> V_174 , V_36 , true ) ;
if ( ! V_158 )
goto V_177;
V_172 = & V_168 -> V_179 [ V_36 ] ;
V_41 = F_92 ( V_168 -> V_174 , V_36 ) ;
V_172 -> V_180 = V_41 -> V_46 -> V_181 [ 0 ] . V_187 ;
}
return;
V_177:
F_93 ( V_168 -> V_174 ) ;
V_168 -> V_174 = NULL ;
F_97 ( V_168 ) ;
}
static unsigned int
F_98 ( struct V_167 * V_168 ,
struct V_169 * V_170 )
{
if ( ! V_168 -> V_174 )
V_168 -> V_174 = F_91 ( V_168 -> V_175 ,
V_170 -> V_176 ,
0 ,
V_61 ,
V_110 ,
V_184 ) ;
if ( V_168 -> V_174 )
return F_87 ( V_168 -> V_174 ) ;
F_97 ( V_168 ) ;
return 1 ;
}
static void F_99 ( struct V_188 * V_189 , bool V_190 )
{
struct V_147 * V_148 = & V_189 -> V_148 ;
F_100 ( V_189 -> V_2 , false ) ;
if ( V_190 ) {
F_12 ( L_12
L_13 , V_20 ,
V_189 -> V_148 . V_191 ,
V_189 -> V_2 -> V_192 -> V_193 ,
( unsigned long long ) F_101 ( V_189 -> V_2 ) ,
V_189 -> args . V_194 ,
( unsigned long long ) V_189 -> args . V_59 ) ;
if ( ! V_189 -> V_195 ) {
struct V_196 * V_197 ;
V_197 = F_102 ( V_189 -> V_98 . V_198 ) -> V_176 ;
F_45 ( V_199 , & V_197 -> V_84 ) ;
V_189 -> V_200 -> V_201 ( & V_189 -> V_98 ) ;
} else {
F_103 ( V_189 -> V_195 ) ;
V_189 -> V_202 . V_153 = V_154 ;
V_189 -> V_203 = V_189 -> args . V_194 ;
}
return;
}
if ( ! F_104 ( V_204 , & V_189 -> V_84 ) ) {
F_12 ( L_14
L_13 , V_20 ,
V_189 -> V_148 . V_191 ,
V_189 -> V_2 -> V_192 -> V_193 ,
( unsigned long long ) F_101 ( V_189 -> V_2 ) ,
V_189 -> args . V_194 ,
( unsigned long long ) V_189 -> args . V_59 ) ;
V_148 -> V_205 = F_105 ( V_189 ) ;
}
}
static void F_106 ( struct V_188 * V_189 )
{
struct V_147 * V_148 = & V_189 -> V_148 ;
F_100 ( V_189 -> V_2 , false ) ;
if ( ! F_104 ( V_204 , & V_189 -> V_84 ) ) {
F_12 ( L_14
L_13 , V_20 ,
V_189 -> V_148 . V_191 ,
V_189 -> V_2 -> V_192 -> V_193 ,
( unsigned long long ) F_101 ( V_189 -> V_2 ) ,
V_189 -> args . V_194 ,
( unsigned long long ) V_189 -> args . V_59 ) ;
V_148 -> V_205 = F_107 ( V_189 ) ;
}
}
static int F_108 ( struct V_147 * V_148 ,
struct V_206 * V_207 ,
struct V_208 * V_209 ,
struct V_69 * V_78 ,
int V_166 )
{
struct V_1 * V_9 = V_78 -> V_111 ;
struct V_2 * V_2 = V_9 -> V_44 ;
struct V_210 * V_211 = F_61 ( V_2 ) ;
struct V_82 * V_22 = F_109 ( V_78 , V_166 ) ;
struct V_208 * V_212 = V_211 -> V_208 ;
struct V_213 * V_214 = & V_209 -> V_215 -> V_216 ;
if ( V_148 -> V_205 >= 0 )
return 0 ;
switch ( V_148 -> V_205 ) {
case - V_217 :
case - V_218 :
case - V_219 :
if ( V_207 == NULL )
break;
F_110 ( V_207 -> V_2 ) ;
case - V_220 :
if ( V_207 == NULL )
break;
if ( F_111 ( V_211 , V_207 ) < 0 )
goto V_221;
goto V_222;
case - V_223 :
if ( V_207 != NULL ) {
if ( F_111 ( V_211 , V_207 ) < 0 )
goto V_221;
}
F_112 ( V_212 ) ;
goto V_222;
case - V_224 :
case - V_225 :
case - V_226 :
case - V_227 :
case - V_228 :
case - V_229 :
case - V_230 :
F_12 ( L_15
L_16 , V_20 , V_148 -> V_205 ,
V_209 -> V_231 ) ;
F_113 ( V_209 -> V_215 , V_148 -> V_205 ) ;
break;
case - V_232 :
case - V_233 :
F_114 ( V_148 , V_234 ) ;
break;
case - V_235 :
break;
case - V_236 :
case - V_237 :
case - V_238 :
case - V_239 :
case - V_240 :
case - V_241 :
F_12 ( L_17 , V_20 ,
V_148 -> V_205 ) ;
F_115 ( F_116 ( V_2 ) ) ;
F_117 ( & V_214 -> V_242 ) ;
goto V_243;
case - V_244 :
case - V_245 :
case - V_246 :
case - V_247 :
case - V_100 :
case - V_248 :
case - V_249 :
F_12 ( L_18 , V_20 ,
V_148 -> V_205 ) ;
F_118 ( V_22 ) ;
F_117 ( & V_214 -> V_242 ) ;
default:
if ( F_119 ( V_78 ) ||
F_120 ( V_78 ) )
return - V_250 ;
V_243:
F_12 ( L_19 , V_20 ,
V_148 -> V_205 ) ;
return - V_251 ;
}
V_252:
V_148 -> V_205 = 0 ;
return - V_253 ;
V_221:
V_148 -> V_205 = - V_100 ;
return 0 ;
V_222:
F_121 ( & V_212 -> V_254 , V_148 , NULL ) ;
if ( F_44 ( V_255 , & V_212 -> V_256 ) == 0 )
F_122 ( & V_212 -> V_254 , V_148 ) ;
goto V_252;
}
static int F_123 ( struct V_147 * V_148 ,
struct V_69 * V_78 ,
int V_166 )
{
struct V_82 * V_22 = F_109 ( V_78 , V_166 ) ;
if ( V_148 -> V_205 >= 0 )
return 0 ;
switch ( V_148 -> V_205 ) {
case - V_257 :
case - V_237 :
case - V_239 :
case - V_238 :
case - V_258 :
case - V_259 :
break;
case - V_260 :
F_124 ( V_78 -> V_111 -> V_44 , V_261 ) ;
goto V_262;
default:
F_12 ( L_18 , V_20 ,
V_148 -> V_205 ) ;
F_118 ( V_22 ) ;
}
return - V_250 ;
V_262:
V_148 -> V_205 = 0 ;
F_125 ( V_148 ) ;
F_114 ( V_148 , V_263 ) ;
return - V_253 ;
}
static int F_126 ( struct V_147 * V_148 ,
struct V_206 * V_207 ,
struct V_208 * V_209 ,
struct V_69 * V_78 ,
int V_166 )
{
int V_264 = V_209 -> V_265 -> V_266 -> V_267 ;
switch ( V_264 ) {
case 3 :
return F_123 ( V_148 , V_78 , V_166 ) ;
case 4 :
return F_108 ( V_148 , V_207 , V_209 ,
V_78 , V_166 ) ;
default:
F_72 ( 1 ) ;
return 0 ;
}
}
static void F_127 ( struct V_69 * V_78 ,
int V_166 , T_5 V_59 , T_5 V_60 ,
T_4 V_183 , int V_268 , int error )
{
struct V_33 * V_41 ;
int V_11 ;
if ( V_183 == 0 ) {
switch ( error ) {
case - V_248 :
case - V_269 :
case - V_270 :
case - V_271 :
case - V_244 :
case - V_272 :
case - V_245 :
case - V_246 :
case - V_247 :
case - V_273 :
case - V_19 :
case - V_249 :
case - V_274 :
V_183 = V_275 ;
break;
case - V_257 :
V_183 = V_276 ;
break;
default:
return;
}
}
V_41 = F_92 ( V_78 , V_166 ) ;
V_11 = F_128 ( F_8 ( V_78 -> V_111 ) ,
V_41 , V_59 , V_60 , V_183 , V_268 ,
V_151 ) ;
F_129 ( V_78 -> V_111 -> V_44 , V_78 ) ;
F_12 ( L_20 , V_20 , V_11 , V_268 , V_183 ) ;
}
static int F_130 ( struct V_147 * V_148 ,
struct V_188 * V_189 )
{
int V_11 ;
F_131 ( V_189 , V_148 -> V_205 ) ;
if ( V_148 -> V_205 < 0 )
F_127 ( V_189 -> V_78 , V_189 -> V_277 ,
V_189 -> args . V_59 , V_189 -> args . V_194 ,
V_189 -> V_278 . V_279 , V_280 ,
V_148 -> V_205 ) ;
V_11 = F_126 ( V_148 , V_189 -> args . V_281 -> V_207 ,
V_189 -> V_282 , V_189 -> V_78 ,
V_189 -> V_277 ) ;
switch ( V_11 ) {
case - V_250 :
if ( F_88 ( V_189 -> V_78 ,
V_189 -> V_277 + 1 ,
& V_189 -> V_277 ) )
goto V_283;
F_45 ( V_284 ,
& V_189 -> V_78 -> V_111 -> V_285 ) ;
F_132 ( V_189 ) ;
return V_148 -> V_205 ;
case - V_251 :
F_106 ( V_189 ) ;
return V_148 -> V_205 ;
case - V_253 :
goto V_283;
}
return 0 ;
V_283:
F_133 ( V_148 ) ;
return - V_253 ;
}
static bool
F_134 ( struct V_69 * V_78 )
{
return ! ( F_66 ( V_78 ) -> V_84 & V_286 ) ;
}
static void
F_135 ( struct V_188 * V_189 )
{
if ( ! F_134 ( V_189 -> V_78 ) )
return;
F_136 ( V_189 -> V_2 , V_189 -> V_78 ,
V_189 -> V_287 + V_189 -> V_278 . V_194 ) ;
F_12 ( L_21 , V_20 , V_189 -> V_2 -> V_288 ,
( unsigned long ) F_116 ( V_189 -> V_2 ) -> V_48 -> V_289 ) ;
}
static bool
F_137 ( struct V_69 * V_78 , int V_166 )
{
struct V_82 * V_83 = F_109 ( V_78 , V_166 ) ;
return F_138 ( V_83 ) ;
}
static int F_139 ( struct V_147 * V_148 ,
struct V_188 * V_189 )
{
F_80 ( V_189 -> V_2 ,
F_92 ( V_189 -> V_78 , V_189 -> V_277 ) ,
V_189 -> args . V_194 ,
V_148 -> V_149 ) ;
if ( F_11 ( F_44 ( V_290 , & V_189 -> args . V_281 -> V_84 ) ) ) {
F_140 ( V_148 , - V_100 ) ;
return - V_100 ;
}
if ( F_137 ( V_189 -> V_78 , V_189 -> V_277 ) ) {
F_12 ( L_22 , V_20 , V_148 -> V_191 ) ;
if ( F_120 ( V_189 -> V_78 ) )
F_132 ( V_189 ) ;
else
F_106 ( V_189 ) ;
F_140 ( V_148 , 0 ) ;
return - V_253 ;
}
V_189 -> V_291 = F_130 ;
return 0 ;
}
static void F_141 ( struct V_147 * V_148 , void * V_29 )
{
struct V_188 * V_189 = V_29 ;
if ( F_139 ( V_148 , V_189 ) )
return;
F_142 ( V_148 ) ;
}
static int F_143 ( struct V_208 * V_282 ,
struct V_292 * args ,
struct V_293 * V_278 ,
struct V_147 * V_148 )
{
if ( V_282 -> V_215 )
return F_144 ( V_282 -> V_215 ,
args ,
V_278 ,
V_148 ) ;
return F_145 ( V_282 -> V_294 ,
args ,
V_278 ,
V_148 ) ;
}
static void F_146 ( struct V_147 * V_148 , void * V_29 )
{
struct V_188 * V_189 = V_29 ;
if ( F_143 ( V_189 -> V_282 ,
& V_189 -> args . V_295 ,
& V_189 -> V_278 . V_296 ,
V_148 ) )
return;
if ( F_139 ( V_148 , V_189 ) )
return;
if ( F_147 ( & V_189 -> args . V_16 , V_189 -> args . V_281 ,
V_189 -> args . V_297 , V_298 ) == - V_100 )
F_140 ( V_148 , - V_100 ) ;
}
static void F_148 ( struct V_147 * V_148 , void * V_29 )
{
struct V_188 * V_189 = V_29 ;
F_12 ( L_23 , V_20 , V_148 -> V_205 ) ;
F_82 ( V_148 ,
F_92 ( V_189 -> V_78 , V_189 -> V_277 ) ,
V_189 -> args . V_194 , V_189 -> V_278 . V_194 ) ;
if ( F_44 ( V_204 , & V_189 -> V_84 ) &&
V_148 -> V_205 == 0 ) {
F_149 ( V_148 , & V_189 -> V_278 . V_296 ) ;
return;
}
V_189 -> V_299 -> V_300 ( V_148 , V_189 ) ;
}
static void F_150 ( struct V_147 * V_148 , void * V_29 )
{
struct V_188 * V_189 = V_29 ;
F_151 ( V_148 ,
& F_152 ( V_189 -> V_2 ) -> V_301 [ V_302 ] ) ;
}
static int F_153 ( struct V_147 * V_148 ,
struct V_188 * V_189 )
{
int V_11 ;
F_154 ( V_189 , V_148 -> V_205 ) ;
if ( V_148 -> V_205 < 0 )
F_127 ( V_189 -> V_78 , V_189 -> V_277 ,
V_189 -> args . V_59 , V_189 -> args . V_194 ,
V_189 -> V_278 . V_279 , V_303 ,
V_148 -> V_205 ) ;
V_11 = F_126 ( V_148 , V_189 -> args . V_281 -> V_207 ,
V_189 -> V_282 , V_189 -> V_78 ,
V_189 -> V_277 ) ;
switch ( V_11 ) {
case - V_250 :
F_155 ( V_189 -> V_78 -> V_111 ) ;
F_99 ( V_189 , true ) ;
return V_148 -> V_205 ;
case - V_251 :
F_156 ( V_189 -> V_78 -> V_111 ) ;
F_99 ( V_189 , false ) ;
return V_148 -> V_205 ;
case - V_253 :
F_133 ( V_148 ) ;
return - V_253 ;
}
if ( V_189 -> V_278 . V_202 -> V_153 == V_304 ||
V_189 -> V_278 . V_202 -> V_153 == V_305 )
F_135 ( V_189 ) ;
V_189 -> V_306 . V_307 = 0 ;
if ( V_148 -> V_205 >= 0 )
F_157 ( V_189 ) ;
return 0 ;
}
static int F_158 ( struct V_147 * V_148 ,
struct V_308 * V_29 )
{
int V_11 ;
F_159 ( V_29 , V_148 -> V_205 ) ;
if ( V_148 -> V_205 < 0 )
F_127 ( V_29 -> V_78 , V_29 -> V_309 ,
V_29 -> args . V_59 , V_29 -> args . V_194 ,
V_29 -> V_278 . V_279 , V_310 ,
V_148 -> V_205 ) ;
V_11 = F_126 ( V_148 , NULL , V_29 -> V_282 ,
V_29 -> V_78 , V_29 -> V_309 ) ;
switch ( V_11 ) {
case - V_250 :
F_155 ( V_29 -> V_78 -> V_111 ) ;
F_160 ( V_29 ) ;
return - V_253 ;
case - V_251 :
F_156 ( V_29 -> V_78 -> V_111 ) ;
F_160 ( V_29 ) ;
return - V_253 ;
case - V_253 :
F_133 ( V_148 ) ;
return - V_253 ;
}
if ( V_29 -> V_202 . V_153 == V_154
&& F_134 ( V_29 -> V_78 ) )
F_136 ( V_29 -> V_2 , V_29 -> V_78 , V_29 -> V_311 ) ;
return 0 ;
}
static int F_161 ( struct V_147 * V_148 ,
struct V_188 * V_189 )
{
F_84 ( V_189 -> V_2 ,
F_92 ( V_189 -> V_78 , V_189 -> V_277 ) ,
V_189 -> args . V_194 ,
V_148 -> V_149 ) ;
if ( F_11 ( F_44 ( V_290 , & V_189 -> args . V_281 -> V_84 ) ) ) {
F_140 ( V_148 , - V_100 ) ;
return - V_100 ;
}
if ( F_137 ( V_189 -> V_78 , V_189 -> V_277 ) ) {
bool V_190 ;
V_190 = F_120 ( V_189 -> V_78 ) ;
F_12 ( L_24 , V_20 ,
V_148 -> V_191 , V_190 ? L_25 : L_26 ) ;
F_99 ( V_189 , V_190 ) ;
F_140 ( V_148 , 0 ) ;
return - V_253 ;
}
return 0 ;
}
static void F_162 ( struct V_147 * V_148 , void * V_29 )
{
struct V_188 * V_189 = V_29 ;
if ( F_161 ( V_148 , V_189 ) )
return;
F_142 ( V_148 ) ;
}
static void F_163 ( struct V_147 * V_148 , void * V_29 )
{
struct V_188 * V_189 = V_29 ;
if ( F_143 ( V_189 -> V_282 ,
& V_189 -> args . V_295 ,
& V_189 -> V_278 . V_296 ,
V_148 ) )
return;
if ( F_161 ( V_148 , V_189 ) )
return;
if ( F_147 ( & V_189 -> args . V_16 , V_189 -> args . V_281 ,
V_189 -> args . V_297 , V_312 ) == - V_100 )
F_140 ( V_148 , - V_100 ) ;
}
static void F_164 ( struct V_147 * V_148 , void * V_29 )
{
struct V_188 * V_189 = V_29 ;
F_85 ( V_148 ,
F_92 ( V_189 -> V_78 , V_189 -> V_277 ) ,
V_189 -> args . V_194 , V_189 -> V_278 . V_194 ,
V_189 -> V_278 . V_202 -> V_153 ) ;
if ( F_44 ( V_204 , & V_189 -> V_84 ) &&
V_148 -> V_205 == 0 ) {
F_149 ( V_148 , & V_189 -> V_278 . V_296 ) ;
return;
}
V_189 -> V_299 -> V_300 ( V_148 , V_189 ) ;
}
static void F_165 ( struct V_147 * V_148 , void * V_29 )
{
struct V_188 * V_189 = V_29 ;
F_151 ( V_148 ,
& F_152 ( V_189 -> V_2 ) -> V_301 [ V_313 ] ) ;
}
static void F_166 ( struct V_147 * V_148 ,
struct V_308 * V_314 )
{
F_84 ( V_314 -> V_2 ,
F_92 ( V_314 -> V_78 , V_314 -> V_309 ) ,
0 , V_148 -> V_149 ) ;
}
static void F_167 ( struct V_147 * V_148 , void * V_29 )
{
F_166 ( V_148 , V_29 ) ;
F_142 ( V_148 ) ;
}
static void F_168 ( struct V_147 * V_148 , void * V_29 )
{
struct V_308 * V_315 = V_29 ;
if ( F_143 ( V_315 -> V_282 ,
& V_315 -> args . V_295 ,
& V_315 -> V_278 . V_296 ,
V_148 ) )
return;
F_166 ( V_148 , V_29 ) ;
}
static void F_169 ( struct V_147 * V_148 , void * V_29 )
{
struct V_308 * V_314 = V_29 ;
struct V_169 * V_170 ;
T_8 V_194 = 0 ;
if ( V_148 -> V_205 == 0 ) {
F_24 (req, &cdata->pages, wb_list)
V_194 += V_170 -> V_316 ;
}
F_85 ( V_148 ,
F_92 ( V_314 -> V_78 , V_314 -> V_309 ) ,
V_194 , V_194 , V_304 ) ;
F_170 ( V_148 , V_29 ) ;
}
static void F_171 ( struct V_147 * V_148 , void * V_29 )
{
struct V_308 * V_314 = V_29 ;
F_151 ( V_148 ,
& F_152 ( V_314 -> V_2 ) -> V_301 [ V_317 ] ) ;
}
static enum V_318
F_172 ( struct V_188 * V_189 )
{
struct V_69 * V_78 = V_189 -> V_78 ;
struct V_163 * V_158 ;
struct V_319 * V_320 ;
struct V_321 * V_322 ;
T_9 V_59 = V_189 -> args . V_59 ;
T_4 V_166 = V_189 -> V_277 ;
int V_264 ;
struct V_24 * V_25 ;
F_12 ( L_27 ,
V_20 , V_189 -> V_2 -> V_288 ,
V_189 -> args . V_323 , ( V_324 ) V_189 -> args . V_194 , V_59 ) ;
V_158 = F_89 ( V_78 , V_166 , false ) ;
if ( ! V_158 )
goto V_325;
V_320 = F_173 ( V_78 , V_166 , V_158 -> V_282 ,
V_189 -> V_2 ) ;
if ( F_174 ( V_320 ) )
goto V_325;
V_322 = F_175 ( V_78 , V_166 , V_189 -> V_50 ) ;
if ( F_174 ( V_322 ) )
goto V_325;
V_264 = F_176 ( V_78 , V_166 ) ;
F_12 ( L_28 , V_20 ,
V_158 -> V_326 , F_177 ( & V_158 -> V_282 -> V_327 ) , V_264 ) ;
F_178 ( & V_158 -> V_282 -> V_327 ) ;
V_189 -> V_282 = V_158 -> V_282 ;
V_25 = F_179 ( V_78 , V_166 ) ;
if ( V_25 )
V_189 -> args . V_25 = V_25 ;
V_189 -> args . V_59 = V_59 ;
V_189 -> V_287 = V_59 ;
F_180 ( V_320 , V_189 , V_322 , V_158 -> V_282 -> V_328 ,
V_264 == 3 ? & V_329 :
& V_330 ,
0 , V_331 ) ;
return V_332 ;
V_325:
if ( F_120 ( V_78 ) )
return V_333 ;
return V_334 ;
}
static enum V_318
F_181 ( struct V_188 * V_189 , int V_335 )
{
struct V_69 * V_78 = V_189 -> V_78 ;
struct V_163 * V_158 ;
struct V_319 * V_320 ;
struct V_321 * V_322 ;
T_9 V_59 = V_189 -> args . V_59 ;
int V_264 ;
struct V_24 * V_25 ;
int V_166 = V_189 -> V_277 ;
V_158 = F_89 ( V_78 , V_166 , true ) ;
if ( ! V_158 )
return V_334 ;
V_320 = F_173 ( V_78 , V_166 , V_158 -> V_282 ,
V_189 -> V_2 ) ;
if ( F_174 ( V_320 ) )
return V_334 ;
V_322 = F_175 ( V_78 , V_166 , V_189 -> V_50 ) ;
if ( F_174 ( V_322 ) )
return V_334 ;
V_264 = F_176 ( V_78 , V_166 ) ;
F_12 ( L_29 ,
V_20 , V_189 -> V_2 -> V_288 , V_335 , ( V_324 ) V_189 -> args . V_194 ,
V_59 , V_158 -> V_326 , F_177 ( & V_158 -> V_282 -> V_327 ) ,
V_264 ) ;
V_189 -> V_291 = F_153 ;
F_178 ( & V_158 -> V_282 -> V_327 ) ;
V_189 -> V_282 = V_158 -> V_282 ;
V_189 -> V_336 = V_166 ;
V_25 = F_179 ( V_78 , V_166 ) ;
if ( V_25 )
V_189 -> args . V_25 = V_25 ;
V_189 -> args . V_59 = V_59 ;
F_180 ( V_320 , V_189 , V_322 , V_158 -> V_282 -> V_328 ,
V_264 == 3 ? & V_337 :
& V_338 ,
V_335 , V_331 ) ;
return V_332 ;
}
static T_4 F_182 ( struct V_69 * V_78 , T_4 V_36 )
{
return V_36 ;
}
static struct V_24 *
F_183 ( struct V_69 * V_78 , T_4 V_36 )
{
struct V_51 * V_339 = F_66 ( V_78 ) ;
return & V_339 -> V_53 [ V_36 ] -> V_40 [ 0 ] ;
}
static int F_184 ( struct V_308 * V_29 , int V_340 )
{
struct V_69 * V_78 = V_29 -> V_78 ;
struct V_163 * V_158 ;
struct V_319 * V_320 ;
struct V_321 * V_322 ;
T_4 V_166 ;
int V_264 ;
struct V_24 * V_25 ;
V_166 = F_182 ( V_78 , V_29 -> V_309 ) ;
V_158 = F_89 ( V_78 , V_166 , true ) ;
if ( ! V_158 )
goto V_341;
V_320 = F_173 ( V_78 , V_166 , V_158 -> V_282 ,
V_29 -> V_2 ) ;
if ( F_174 ( V_320 ) )
goto V_341;
V_322 = F_175 ( V_78 , V_166 , V_29 -> V_50 ) ;
if ( F_174 ( V_322 ) )
goto V_341;
V_264 = F_176 ( V_78 , V_166 ) ;
F_12 ( L_30 , V_20 ,
V_29 -> V_2 -> V_288 , V_340 , F_177 ( & V_158 -> V_282 -> V_327 ) ,
V_264 ) ;
V_29 -> V_342 = F_158 ;
V_29 -> V_50 = V_322 ;
F_178 ( & V_158 -> V_282 -> V_327 ) ;
V_29 -> V_282 = V_158 -> V_282 ;
V_25 = F_183 ( V_78 , V_29 -> V_309 ) ;
if ( V_25 )
V_29 -> args . V_25 = V_25 ;
return F_185 ( V_320 , V_29 , V_158 -> V_282 -> V_328 ,
V_264 == 3 ? & V_343 :
& V_344 ,
V_340 , V_331 ) ;
V_341:
F_160 ( V_29 ) ;
F_186 ( V_29 ) ;
return - V_253 ;
}
static int
F_187 ( struct V_2 * V_2 , struct V_79 * V_345 ,
int V_340 , struct V_155 * V_156 )
{
return F_188 ( V_2 , V_345 , V_340 , V_156 ,
F_184 ) ;
}
static struct V_346 *
F_189 ( struct V_2 * V_2 )
{
struct V_1 * V_48 = F_116 ( V_2 ) -> V_48 ;
if ( V_48 == NULL )
return NULL ;
return & F_8 ( V_48 ) -> V_112 ;
}
static void
F_190 ( struct V_82 * V_347 )
{
F_191 ( F_192 ( V_347 , struct V_348 ,
V_86 ) ) ;
}
static int F_193 ( struct V_4 * V_349 ,
struct V_14 * V_15 ,
const struct V_350 * args )
{
struct V_1 * V_189 = & V_349 -> V_8 ;
T_3 * V_120 ;
int V_194 = 0 , V_57 = 0 ;
V_120 = F_194 ( V_15 , 4 ) ;
if ( F_11 ( ! V_120 ) )
return - V_351 ;
F_23 ( & V_189 -> V_44 -> V_45 ) ;
V_57 = F_195 ( V_349 , V_15 , & V_194 , & args -> V_58 ) ;
F_26 ( & V_189 -> V_44 -> V_45 ) ;
* V_120 = F_196 ( V_194 ) ;
return V_57 ;
}
static void F_197 ( struct V_4 * V_349 ,
struct V_14 * V_15 ,
const struct V_350 * args )
{
T_3 * V_17 ;
V_17 = F_194 ( V_15 , 4 ) ;
if ( F_198 ( V_17 ) )
* V_17 = F_196 ( 0 ) ;
}
static struct V_82 *
F_199 ( struct V_210 * V_352 ,
struct V_353 * V_354 , T_1 V_3 )
{
struct V_348 * V_355 ;
V_355 = F_200 ( V_352 , V_354 , V_3 ) ;
if ( ! V_355 )
return NULL ;
return & V_355 -> V_86 ;
}
static void
F_201 ( struct V_1 * V_9 ,
struct V_14 * V_15 ,
const struct V_350 * args )
{
struct V_4 * V_349 = F_8 ( V_9 ) ;
T_3 * V_120 ;
F_12 ( L_31 , V_20 ) ;
V_120 = F_194 ( V_15 , 4 ) ;
F_202 ( ! V_120 ) ;
if ( F_193 ( V_349 , V_15 , args ) )
goto V_252;
F_197 ( V_349 , V_15 , args ) ;
V_252:
* V_120 = F_196 ( ( V_15 -> V_17 - V_120 - 1 ) * 4 ) ;
F_12 ( L_32 , V_20 ) ;
}
static int
F_203 ( const struct V_356 * V_357 , char * V_91 , const V_324 V_358 )
{
const struct V_359 * sin = (struct V_359 * ) V_357 ;
return snprintf ( V_91 , V_358 , L_33 , & sin -> V_360 ) ;
}
static V_324
F_204 ( const struct V_356 * V_357 , char * V_91 ,
const int V_358 )
{
const struct V_361 * V_362 = (struct V_361 * ) V_357 ;
const struct V_363 * V_364 = & V_362 -> V_365 ;
if ( F_205 ( V_364 ) )
return snprintf ( V_91 , V_358 , L_34 ) ;
if ( F_206 ( V_364 ) )
return snprintf ( V_91 , V_358 , L_35 ) ;
if ( F_207 ( V_364 ) )
return snprintf ( V_91 , V_358 , L_36 ,
& V_364 -> V_366 [ 3 ] ) ;
return snprintf ( V_91 , V_358 , L_37 , V_364 ) ;
}
static void
F_208 ( struct V_14 * V_15 , struct V_367 * V_368 )
{
struct V_356 * V_357 = (struct V_356 * ) & V_368 -> V_369 ;
char V_370 [ V_371 ] ;
char V_372 [ V_373 ] ;
char * V_374 ;
unsigned short V_375 ;
int V_31 , V_376 ;
T_3 * V_17 ;
switch ( V_357 -> V_377 ) {
case V_378 :
if ( F_203 ( V_357 , V_372 , sizeof( V_372 ) ) == 0 )
return;
V_375 = F_209 ( ( (struct V_359 * ) V_357 ) -> V_379 ) ;
V_374 = L_38 ;
V_376 = 3 ;
break;
case V_380 :
if ( F_204 ( V_357 , V_372 , sizeof( V_372 ) ) == 0 )
return;
V_375 = F_209 ( ( (struct V_361 * ) V_357 ) -> V_381 ) ;
V_374 = L_39 ;
V_376 = 4 ;
break;
default:
F_72 ( 1 ) ;
return;
}
snprintf ( V_370 , sizeof( V_370 ) , L_40 , V_375 >> 8 , V_375 & 0xff ) ;
V_31 = F_210 ( V_372 , V_370 , sizeof( V_372 ) ) ;
V_17 = F_194 ( V_15 , 4 + V_376 ) ;
F_211 ( V_17 , V_374 , V_376 ) ;
V_17 = F_194 ( V_15 , 4 + V_31 ) ;
F_211 ( V_17 , V_372 , V_31 ) ;
}
static void
F_212 ( struct V_14 * V_15 ,
T_6 V_382 )
{
struct V_383 V_384 ;
T_3 * V_17 ;
V_17 = F_194 ( V_15 , 12 ) ;
V_384 = F_213 ( V_382 ) ;
V_17 = F_214 ( V_17 , V_384 . V_385 ) ;
* V_17 ++ = F_196 ( V_384 . V_386 ) ;
}
static void
F_215 ( struct V_14 * V_15 ,
struct V_130 * V_387 )
{
T_3 * V_17 ;
V_17 = F_194 ( V_15 , 5 * 8 ) ;
V_17 = F_214 ( V_17 , V_387 -> V_133 ) ;
V_17 = F_214 ( V_17 , V_387 -> V_134 ) ;
V_17 = F_214 ( V_17 , V_387 -> V_139 ) ;
V_17 = F_214 ( V_17 , V_387 -> V_140 ) ;
V_17 = F_214 ( V_17 , V_387 -> V_141 ) ;
F_212 ( V_15 , V_387 -> V_142 ) ;
F_212 ( V_15 , V_387 -> V_143 ) ;
}
static void
F_216 ( struct V_14 * V_15 ,
struct V_388 * args ,
struct V_389 * V_390 )
{
struct V_33 * V_41 = V_390 -> V_391 ;
struct V_367 * V_368 ;
struct V_163 * V_158 = V_41 -> V_46 -> V_158 ;
struct V_24 * V_25 = & V_41 -> V_40 [ 0 ] ;
T_3 * V_17 , * V_120 ;
V_368 = F_217 ( & V_158 -> V_392 , struct V_367 , V_393 ) ;
F_12 ( L_41 ,
V_20 , V_158 -> V_326 , V_368 -> V_394 ) ;
V_120 = F_194 ( V_15 , 4 ) ;
F_208 ( V_15 , V_368 ) ;
V_17 = F_194 ( V_15 , 4 + V_25 -> V_26 ) ;
F_211 ( V_17 , V_25 -> V_29 , V_25 -> V_26 ) ;
F_23 ( & V_41 -> V_49 ) ;
F_215 ( V_15 , & V_41 -> V_145 . V_132 ) ;
F_215 ( V_15 , & V_41 -> V_150 . V_132 ) ;
F_26 ( & V_41 -> V_49 ) ;
F_212 ( V_15 , F_73 ( F_83 () , V_41 -> V_119 ) ) ;
V_17 = F_194 ( V_15 , 4 ) ;
* V_17 = F_196 ( false ) ;
* V_120 = F_196 ( ( V_15 -> V_17 - V_120 - 1 ) * 4 ) ;
}
static int
F_218 ( struct V_388 * args ,
struct V_1 * V_9 ,
int V_395 )
{
struct V_4 * V_42 = F_8 ( V_9 ) ;
struct V_33 * V_41 ;
struct V_82 * V_396 ;
struct V_389 * V_390 ;
int V_36 = 0 ;
F_24 (mirror, &ff_layout->mirrors, mirrors) {
if ( V_36 >= V_395 )
break;
if ( ! V_41 -> V_46 )
continue;
if ( ! F_25 ( & V_41 -> V_47 ) )
continue;
V_396 = & V_41 -> V_46 -> V_86 ;
V_390 = & args -> V_390 [ V_36 ] ;
memcpy ( & V_390 -> V_397 , & V_396 -> V_398 , V_23 ) ;
V_390 -> V_59 = 0 ;
V_390 -> V_60 = V_61 ;
V_390 -> V_399 = V_41 -> V_145 . V_132 . V_139 ;
V_390 -> V_400 = V_41 -> V_145 . V_132 . V_140 ;
V_390 -> V_401 = V_41 -> V_150 . V_132 . V_139 ;
V_390 -> V_402 = V_41 -> V_150 . V_132 . V_140 ;
V_390 -> V_403 = V_404 ;
V_390 -> V_405 = F_216 ;
V_390 -> V_391 = V_41 ;
V_36 ++ ;
}
return V_36 ;
}
static int
F_219 ( struct V_388 * args )
{
struct V_4 * V_42 ;
struct V_33 * V_41 ;
int V_406 = 0 ;
F_23 ( & args -> V_2 -> V_45 ) ;
V_42 = F_8 ( F_116 ( args -> V_2 ) -> V_48 ) ;
F_24 (mirror, &ff_layout->mirrors, mirrors) {
if ( F_177 ( & V_41 -> V_47 ) != 0 )
V_406 ++ ;
}
F_26 ( & args -> V_2 -> V_45 ) ;
if ( V_406 > V_407 ) {
F_12 ( L_42 ,
V_20 , V_406 , V_407 ) ;
V_406 = V_407 ;
}
args -> V_390 = F_220 ( V_406 , sizeof( * args -> V_390 ) , V_151 ) ;
if ( ! args -> V_390 )
return - V_96 ;
F_23 ( & args -> V_2 -> V_45 ) ;
args -> V_408 = F_218 ( args ,
& V_42 -> V_8 , V_406 ) ;
F_26 ( & args -> V_2 -> V_45 ) ;
return 0 ;
}
static void
F_221 ( struct V_409 * V_29 )
{
struct V_33 * V_41 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_29 -> args . V_408 ; V_36 ++ ) {
V_41 = V_29 -> args . V_390 [ V_36 ] . V_391 ;
V_29 -> args . V_390 [ V_36 ] . V_391 = NULL ;
F_35 ( V_41 ) ;
}
}
static int T_10 F_222 ( void )
{
F_17 ( V_410 L_43 ,
V_20 ) ;
return F_223 ( & V_411 ) ;
}
static void T_11 F_224 ( void )
{
F_17 ( V_410 L_44 ,
V_20 ) ;
F_225 ( & V_411 ) ;
}
