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
static struct V_69 *
F_50 ( struct V_1 * V_82 ,
struct V_55 * V_56 ,
T_1 V_3 )
{
struct V_69 * V_57 ;
struct V_51 * V_52 = NULL ;
struct V_14 V_83 ;
struct V_84 V_85 ;
struct V_86 * V_87 ;
T_5 V_88 ;
T_4 V_54 ;
T_3 * V_17 ;
int V_36 , V_89 ;
F_12 ( L_5 , V_20 ) ;
V_87 = F_51 ( V_3 ) ;
if ( ! V_87 )
return F_52 ( - V_90 ) ;
F_53 ( & V_83 , & V_85 , V_56 -> V_91 -> V_92 ,
V_56 -> V_91 -> V_31 ) ;
F_54 ( & V_83 , F_55 ( V_87 ) , V_93 ) ;
V_89 = - V_94 ;
V_17 = F_10 ( & V_83 , 8 + 4 ) ;
if ( ! V_17 )
goto V_95;
V_17 = F_56 ( V_17 , & V_88 ) ;
V_54 = F_16 ( V_17 ++ ) ;
F_12 ( L_8 , V_20 ,
V_88 , V_54 ) ;
if ( V_54 > V_96 ||
V_54 == 0 )
goto V_95;
V_89 = - V_90 ;
V_52 = F_2 ( sizeof( * V_52 ) , V_3 ) ;
if ( ! V_52 )
goto V_95;
V_52 -> V_54 = V_54 ;
V_52 -> V_88 = V_88 ;
V_52 -> V_53 = F_57 ( V_52 -> V_54 ,
sizeof( V_52 -> V_53 [ 0 ] ) , V_3 ) ;
if ( V_52 -> V_53 == NULL )
goto V_95;
for ( V_36 = 0 ; V_36 < V_52 -> V_54 ; V_36 ++ ) {
struct V_33 * V_41 ;
struct V_21 V_22 ;
struct V_97 * V_98 ;
T_4 V_99 ;
T_4 V_100 ;
int V_37 ;
V_89 = - V_94 ;
V_17 = F_10 ( & V_83 , 4 ) ;
if ( ! V_17 )
goto V_95;
V_99 = F_16 ( V_17 ) ;
if ( V_99 != 1 )
goto V_95;
V_52 -> V_53 [ V_36 ] = F_29 ( V_3 ) ;
if ( V_52 -> V_53 [ V_36 ] == NULL ) {
V_89 = - V_90 ;
goto V_95;
}
V_52 -> V_53 [ V_36 ] -> V_99 = V_99 ;
V_89 = F_13 ( & V_83 , & V_22 ) ;
if ( V_89 )
goto V_95;
V_98 = F_58 ( F_59 ( V_82 -> V_44 ) ,
& V_22 , V_82 -> V_101 ,
V_3 ) ;
if ( V_98 )
V_52 -> V_53 [ V_36 ] -> V_46 =
F_60 ( V_98 ) ;
else
goto V_95;
V_89 = - V_94 ;
V_17 = F_10 ( & V_83 , 4 ) ;
if ( ! V_17 )
goto V_95;
V_52 -> V_53 [ V_36 ] -> V_81 = F_16 ( V_17 ) ;
V_89 = F_9 ( & V_83 , & V_52 -> V_53 [ V_36 ] -> V_16 ) ;
if ( V_89 )
goto V_95;
V_17 = F_10 ( & V_83 , 4 ) ;
if ( ! V_17 )
goto V_95;
V_100 = F_16 ( V_17 ) ;
V_52 -> V_53 [ V_36 ] -> V_40 =
F_2 ( V_100 * sizeof( struct V_24 ) ,
V_3 ) ;
if ( V_52 -> V_53 [ V_36 ] -> V_40 == NULL ) {
V_89 = - V_90 ;
goto V_95;
}
for ( V_37 = 0 ; V_37 < V_100 ; V_37 ++ ) {
V_89 = F_15 ( & V_83 ,
& V_52 -> V_53 [ V_36 ] -> V_40 [ V_37 ] ) ;
if ( V_89 )
goto V_95;
}
V_52 -> V_53 [ V_36 ] -> V_38 = V_100 ;
V_89 = F_18 ( & V_83 , & V_52 -> V_53 [ V_36 ] -> V_102 ) ;
if ( V_89 )
goto V_95;
V_89 = F_18 ( & V_83 , & V_52 -> V_53 [ V_36 ] -> V_103 ) ;
if ( V_89 )
goto V_95;
V_41 = F_22 ( V_82 , V_52 -> V_53 [ V_36 ] ) ;
if ( V_41 != V_52 -> V_53 [ V_36 ] ) {
F_32 ( V_52 -> V_53 [ V_36 ] ) ;
V_52 -> V_53 [ V_36 ] = V_41 ;
}
F_12 ( L_9 , V_20 ,
V_52 -> V_53 [ V_36 ] -> V_102 ,
V_52 -> V_53 [ V_36 ] -> V_103 ) ;
}
V_17 = F_10 ( & V_83 , 4 ) ;
if ( V_17 )
V_52 -> V_104 = F_16 ( V_17 ) ;
F_48 ( V_52 ) ;
V_89 = F_38 ( V_56 ) ;
if ( V_89 )
goto V_95;
V_57 = & V_52 -> V_8 ;
F_12 ( L_10 , V_20 ) ;
V_105:
F_61 ( V_87 ) ;
return V_57 ;
V_95:
F_39 ( V_52 ) ;
V_57 = F_52 ( V_89 ) ;
F_12 ( L_11 , V_20 , V_89 ) ;
goto V_105;
}
static bool F_62 ( struct V_1 * V_48 )
{
struct V_69 * V_78 ;
F_24 (lseg, &layout->plh_segs, pls_list)
if ( V_78 -> V_74 . V_67 == V_106 )
return true ;
return false ;
}
static void
F_63 ( struct V_69 * V_78 )
{
struct V_51 * V_52 = F_64 ( V_78 ) ;
F_12 ( L_5 , V_20 ) ;
if ( V_78 -> V_74 . V_67 == V_106 ) {
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_5 = F_8 ( V_78 -> V_107 ) ;
V_2 = V_5 -> V_8 . V_44 ;
F_23 ( & V_2 -> V_45 ) ;
if ( ! F_62 ( V_78 -> V_107 ) ) {
V_5 -> V_108 . V_109 = 0 ;
F_7 ( V_5 -> V_108 . V_110 ) ;
V_5 -> V_108 . V_110 = NULL ;
}
F_26 ( & V_2 -> V_45 ) ;
}
F_39 ( V_52 ) ;
}
static int
F_65 ( struct V_51 * V_52 )
{
return 1 ;
}
static void
F_66 ( struct V_111 * V_112 , T_6 V_113 )
{
if ( F_67 ( & V_112 -> V_114 ) == 1 ) {
V_112 -> V_115 = V_113 ;
}
}
static T_6
F_68 ( struct V_111 * V_112 , T_6 V_113 )
{
T_6 V_116 ;
if ( F_69 ( & V_112 -> V_114 ) < 0 )
F_70 ( 1 ) ;
V_116 = V_112 -> V_115 ;
V_112 -> V_115 = V_113 ;
return F_71 ( V_113 , V_116 ) ;
}
static bool
F_72 ( struct V_33 * V_41 ,
struct V_117 * V_118 ,
T_6 V_113 )
{
static const T_6 V_119 = { 0 } ;
T_7 V_120 = V_121 ;
F_66 ( & V_118 -> V_122 , V_113 ) ;
if ( F_73 ( V_41 -> V_115 , V_119 ) )
V_41 -> V_115 = V_113 ;
if ( F_73 ( V_41 -> V_123 , V_119 ) )
V_41 -> V_123 = V_113 ;
if ( V_124 != 0 )
V_120 = ( T_7 ) V_124 * 1000LL ;
if ( F_74 ( F_71 ( V_113 , V_41 -> V_123 ) ) >=
V_120 ) {
V_41 -> V_123 = V_113 ;
return true ;
}
return false ;
}
static void
F_75 ( struct V_117 * V_118 ,
T_8 V_125 )
{
struct V_126 * V_127 = & V_118 -> V_128 ;
V_127 -> V_129 ++ ;
V_127 -> V_130 += V_125 ;
}
static void
F_76 ( struct V_117 * V_118 ,
T_8 V_125 ,
T_8 V_131 ,
T_6 V_132 ,
T_6 V_133 )
{
struct V_126 * V_127 = & V_118 -> V_128 ;
T_6 V_134 = F_71 ( V_132 , V_133 ) ;
T_6 V_112 ;
V_127 -> V_135 ++ ;
V_127 -> V_136 += V_131 ;
V_127 -> V_137 += V_125 - V_131 ;
V_112 = F_68 ( & V_118 -> V_122 , V_132 ) ;
V_127 -> V_138 =
F_77 ( V_127 -> V_138 , V_112 ) ;
V_127 -> V_139 =
F_77 ( V_127 -> V_139 ,
V_134 ) ;
}
static void
F_78 ( struct V_2 * V_2 ,
struct V_33 * V_41 ,
T_8 V_125 , T_6 V_113 )
{
bool V_140 ;
F_23 ( & V_41 -> V_49 ) ;
V_140 = F_72 ( V_41 , & V_41 -> V_141 , V_113 ) ;
F_75 ( & V_41 -> V_141 , V_125 ) ;
F_26 ( & V_41 -> V_49 ) ;
if ( V_140 )
F_79 ( V_2 , V_142 ) ;
}
static void
F_80 ( struct V_143 * V_144 ,
struct V_33 * V_41 ,
T_8 V_125 ,
T_8 V_131 )
{
F_23 ( & V_41 -> V_49 ) ;
F_76 ( & V_41 -> V_141 ,
V_125 , V_131 ,
F_81 () , V_144 -> V_145 ) ;
F_26 ( & V_41 -> V_49 ) ;
}
static void
F_82 ( struct V_2 * V_2 ,
struct V_33 * V_41 ,
T_8 V_125 , T_6 V_113 )
{
bool V_140 ;
F_23 ( & V_41 -> V_49 ) ;
V_140 = F_72 ( V_41 , & V_41 -> V_146 , V_113 ) ;
F_75 ( & V_41 -> V_146 , V_125 ) ;
F_26 ( & V_41 -> V_49 ) ;
if ( V_140 )
F_79 ( V_2 , V_147 ) ;
}
static void
F_83 ( struct V_143 * V_144 ,
struct V_33 * V_41 ,
T_8 V_125 ,
T_8 V_131 ,
enum V_148 V_149 )
{
if ( V_149 == V_150 )
V_125 = V_131 = 0 ;
F_23 ( & V_41 -> V_49 ) ;
F_76 ( & V_41 -> V_146 ,
V_125 , V_131 , F_81 () , V_144 -> V_145 ) ;
F_26 ( & V_41 -> V_49 ) ;
}
static int
F_84 ( struct V_69 * V_78 ,
struct V_151 * V_152 ,
T_1 V_3 )
{
struct V_51 * V_52 = F_64 ( V_78 ) ;
struct V_153 * V_110 ;
int V_26 ;
if ( V_152 -> V_154 -> V_109 != 0 ) {
return 0 ;
}
V_26 = F_65 ( V_52 ) * F_85 ( V_78 ) ;
V_110 = F_57 ( V_26 , sizeof( struct V_153 ) ,
V_3 ) ;
if ( ! V_110 )
return - V_90 ;
else {
int V_36 ;
F_23 ( V_152 -> V_49 ) ;
if ( V_152 -> V_154 -> V_109 != 0 )
F_7 ( V_110 ) ;
else {
V_152 -> V_154 -> V_110 = V_110 ;
V_152 -> V_154 -> V_109 = V_26 ;
for ( V_36 = 0 ; V_36 < V_26 ; V_36 ++ ) {
F_3 ( & V_110 [ V_36 ] . V_155 ) ;
F_3 ( & V_110 [ V_36 ] . V_156 ) ;
V_110 [ V_36 ] . V_157 . V_149 =
V_158 ;
}
}
F_26 ( V_152 -> V_49 ) ;
return 0 ;
}
}
static struct V_159 *
F_86 ( struct V_160 * V_161 ,
int * V_162 )
{
struct V_51 * V_52 ;
struct V_159 * V_154 ;
int V_163 ;
V_52 = F_64 ( V_161 -> V_164 ) ;
for ( V_163 = 0 ; V_163 < V_52 -> V_54 ; V_163 ++ ) {
V_154 = F_87 ( V_161 -> V_164 , V_163 , false ) ;
if ( V_154 ) {
* V_162 = V_163 ;
return V_154 ;
}
}
return NULL ;
}
static void
F_88 ( struct V_160 * V_161 ,
struct V_165 * V_166 )
{
struct V_167 * V_168 ;
struct V_33 * V_41 ;
struct V_159 * V_154 ;
int V_169 ;
if ( ! V_161 -> V_164 )
V_161 -> V_164 = F_89 ( V_161 -> V_170 ,
V_166 -> V_171 ,
0 ,
V_61 ,
V_68 ,
V_142 ) ;
if ( V_161 -> V_164 == NULL )
goto V_172;
V_154 = F_86 ( V_161 , & V_169 ) ;
if ( ! V_154 )
goto V_172;
V_41 = F_90 ( V_161 -> V_164 , V_169 ) ;
V_161 -> V_173 = V_169 ;
V_168 = & V_161 -> V_174 [ 0 ] ;
V_168 -> V_175 = V_41 -> V_46 -> V_176 [ 0 ] . V_177 ;
return;
V_172:
F_91 ( V_161 -> V_164 ) ;
V_161 -> V_164 = NULL ;
F_92 ( V_161 ) ;
}
static void
F_93 ( struct V_160 * V_161 ,
struct V_165 * V_166 )
{
struct V_33 * V_41 ;
struct V_167 * V_168 ;
struct V_151 V_152 ;
struct V_159 * V_154 ;
int V_36 ;
int V_178 ;
if ( ! V_161 -> V_164 )
V_161 -> V_164 = F_89 ( V_161 -> V_170 ,
V_166 -> V_171 ,
0 ,
V_61 ,
V_106 ,
V_179 ) ;
if ( V_161 -> V_164 == NULL )
goto V_172;
F_94 ( & V_152 , V_161 -> V_170 , V_161 -> V_180 ) ;
V_178 = F_84 ( V_161 -> V_164 , & V_152 , V_179 ) ;
if ( V_178 < 0 )
goto V_172;
if ( F_70 ( V_161 -> V_181 !=
F_85 ( V_161 -> V_164 ) ) )
goto V_172;
for ( V_36 = 0 ; V_36 < V_161 -> V_181 ; V_36 ++ ) {
V_154 = F_87 ( V_161 -> V_164 , V_36 , true ) ;
if ( ! V_154 )
goto V_172;
V_168 = & V_161 -> V_174 [ V_36 ] ;
V_41 = F_90 ( V_161 -> V_164 , V_36 ) ;
V_168 -> V_175 = V_41 -> V_46 -> V_176 [ 0 ] . V_182 ;
}
return;
V_172:
F_91 ( V_161 -> V_164 ) ;
V_161 -> V_164 = NULL ;
F_95 ( V_161 ) ;
}
static unsigned int
F_96 ( struct V_160 * V_161 ,
struct V_165 * V_166 )
{
if ( ! V_161 -> V_164 )
V_161 -> V_164 = F_89 ( V_161 -> V_170 ,
V_166 -> V_171 ,
0 ,
V_61 ,
V_106 ,
V_179 ) ;
if ( V_161 -> V_164 )
return F_85 ( V_161 -> V_164 ) ;
F_95 ( V_161 ) ;
return 1 ;
}
static void F_97 ( struct V_183 * V_184 , bool V_185 )
{
struct V_143 * V_144 = & V_184 -> V_144 ;
F_98 ( V_184 -> V_2 , false ) ;
if ( V_185 ) {
F_12 ( L_12
L_13 , V_20 ,
V_184 -> V_144 . V_186 ,
V_184 -> V_2 -> V_187 -> V_188 ,
( unsigned long long ) F_99 ( V_184 -> V_2 ) ,
V_184 -> args . V_189 ,
( unsigned long long ) V_184 -> args . V_59 ) ;
if ( ! V_184 -> V_190 ) {
struct V_191 * V_192 ;
V_192 = F_100 ( V_184 -> V_92 . V_193 ) -> V_171 ;
F_45 ( V_194 , & V_192 -> V_104 ) ;
V_184 -> V_195 -> V_196 ( & V_184 -> V_92 ) ;
} else {
F_101 ( V_184 -> V_190 ) ;
V_184 -> V_197 . V_149 = V_150 ;
V_184 -> V_198 = V_184 -> args . V_189 ;
}
return;
}
if ( ! F_102 ( V_199 , & V_184 -> V_104 ) ) {
F_12 ( L_14
L_13 , V_20 ,
V_184 -> V_144 . V_186 ,
V_184 -> V_2 -> V_187 -> V_188 ,
( unsigned long long ) F_99 ( V_184 -> V_2 ) ,
V_184 -> args . V_189 ,
( unsigned long long ) V_184 -> args . V_59 ) ;
V_144 -> V_200 = F_103 ( V_184 ) ;
}
}
static void F_104 ( struct V_183 * V_184 )
{
struct V_143 * V_144 = & V_184 -> V_144 ;
F_98 ( V_184 -> V_2 , false ) ;
if ( ! F_102 ( V_199 , & V_184 -> V_104 ) ) {
F_12 ( L_14
L_13 , V_20 ,
V_184 -> V_144 . V_186 ,
V_184 -> V_2 -> V_187 -> V_188 ,
( unsigned long long ) F_99 ( V_184 -> V_2 ) ,
V_184 -> args . V_189 ,
( unsigned long long ) V_184 -> args . V_59 ) ;
V_144 -> V_200 = F_105 ( V_184 ) ;
}
}
static int F_106 ( struct V_143 * V_144 ,
struct V_201 * V_202 ,
struct V_203 * V_204 ,
struct V_69 * V_78 ,
int V_163 )
{
struct V_1 * V_9 = V_78 -> V_107 ;
struct V_2 * V_2 = V_9 -> V_44 ;
struct V_205 * V_206 = F_59 ( V_2 ) ;
struct V_97 * V_22 = F_107 ( V_78 , V_163 ) ;
struct V_203 * V_207 = V_206 -> V_203 ;
struct V_208 * V_209 = & V_204 -> V_210 -> V_211 ;
if ( V_144 -> V_200 >= 0 )
return 0 ;
switch ( V_144 -> V_200 ) {
case - V_212 :
case - V_213 :
case - V_214 :
if ( V_202 == NULL )
break;
F_108 ( V_202 -> V_2 ) ;
case - V_215 :
if ( V_202 == NULL )
break;
if ( F_109 ( V_206 , V_202 ) < 0 )
goto V_216;
goto V_217;
case - V_218 :
if ( V_202 != NULL ) {
if ( F_109 ( V_206 , V_202 ) < 0 )
goto V_216;
}
F_110 ( V_207 ) ;
goto V_217;
case - V_219 :
case - V_220 :
case - V_221 :
case - V_222 :
case - V_223 :
case - V_224 :
case - V_225 :
F_12 ( L_15
L_16 , V_20 , V_144 -> V_200 ,
V_204 -> V_226 ) ;
F_111 ( V_204 -> V_210 , V_144 -> V_200 ) ;
break;
case - V_227 :
case - V_228 :
F_112 ( V_144 , V_229 ) ;
break;
case - V_230 :
break;
case - V_231 :
case - V_232 :
case - V_233 :
case - V_234 :
case - V_235 :
case - V_236 :
F_12 ( L_17 , V_20 ,
V_144 -> V_200 ) ;
F_113 ( F_114 ( V_2 ) ) ;
F_115 ( & V_209 -> V_237 ) ;
goto V_238;
case - V_239 :
case - V_240 :
case - V_241 :
case - V_242 :
case - V_94 :
case - V_243 :
case - V_244 :
F_12 ( L_18 , V_20 ,
V_144 -> V_200 ) ;
F_116 ( V_22 ) ;
F_115 ( & V_209 -> V_237 ) ;
default:
if ( F_117 ( V_78 ) )
return - V_245 ;
V_238:
F_12 ( L_19 , V_20 ,
V_144 -> V_200 ) ;
return - V_246 ;
}
V_247:
V_144 -> V_200 = 0 ;
return - V_248 ;
V_216:
V_144 -> V_200 = - V_94 ;
return 0 ;
V_217:
F_118 ( & V_207 -> V_249 , V_144 , NULL ) ;
if ( F_44 ( V_250 , & V_207 -> V_251 ) == 0 )
F_119 ( & V_207 -> V_249 , V_144 ) ;
goto V_247;
}
static int F_120 ( struct V_143 * V_144 ,
struct V_69 * V_78 ,
int V_163 )
{
struct V_97 * V_22 = F_107 ( V_78 , V_163 ) ;
if ( V_144 -> V_200 >= 0 )
return 0 ;
switch ( V_144 -> V_200 ) {
case - V_252 :
case - V_232 :
case - V_234 :
case - V_233 :
case - V_253 :
case - V_254 :
break;
case - V_255 :
F_121 ( V_78 -> V_107 -> V_44 , V_256 ) ;
goto V_257;
default:
F_12 ( L_18 , V_20 ,
V_144 -> V_200 ) ;
F_116 ( V_22 ) ;
}
return - V_245 ;
V_257:
V_144 -> V_200 = 0 ;
F_122 ( V_144 ) ;
F_112 ( V_144 , V_258 ) ;
return - V_248 ;
}
static int F_123 ( struct V_143 * V_144 ,
struct V_201 * V_202 ,
struct V_203 * V_204 ,
struct V_69 * V_78 ,
int V_163 )
{
int V_259 = V_204 -> V_260 -> V_261 -> V_262 ;
switch ( V_259 ) {
case 3 :
return F_120 ( V_144 , V_78 , V_163 ) ;
case 4 :
return F_106 ( V_144 , V_202 , V_204 ,
V_78 , V_163 ) ;
default:
F_70 ( 1 ) ;
return 0 ;
}
}
static void F_124 ( struct V_69 * V_78 ,
int V_163 , T_5 V_59 , T_5 V_60 ,
T_4 V_178 , int V_263 , int error )
{
struct V_33 * V_41 ;
int V_11 ;
if ( V_178 == 0 ) {
switch ( error ) {
case - V_243 :
case - V_264 :
case - V_265 :
case - V_266 :
case - V_239 :
case - V_267 :
case - V_240 :
case - V_241 :
case - V_242 :
case - V_268 :
case - V_19 :
case - V_244 :
case - V_269 :
V_178 = V_270 ;
break;
case - V_252 :
V_178 = V_271 ;
break;
default:
return;
}
}
V_41 = F_90 ( V_78 , V_163 ) ;
V_11 = F_125 ( F_8 ( V_78 -> V_107 ) ,
V_41 , V_59 , V_60 , V_178 , V_263 ,
V_147 ) ;
F_126 ( V_78 -> V_107 -> V_44 , V_78 ) ;
F_12 ( L_20 , V_20 , V_11 , V_263 , V_178 ) ;
}
static int F_127 ( struct V_143 * V_144 ,
struct V_183 * V_184 )
{
int V_11 ;
F_128 ( V_184 , V_144 -> V_200 ) ;
if ( V_144 -> V_200 < 0 )
F_124 ( V_184 -> V_78 , V_184 -> V_272 ,
V_184 -> args . V_59 , V_184 -> args . V_189 ,
V_184 -> V_273 . V_274 , V_275 ,
V_144 -> V_200 ) ;
V_11 = F_123 ( V_144 , V_184 -> args . V_276 -> V_202 ,
V_184 -> V_277 , V_184 -> V_78 ,
V_184 -> V_272 ) ;
switch ( V_11 ) {
case - V_245 :
F_45 ( V_278 ,
& V_184 -> V_78 -> V_107 -> V_279 ) ;
F_129 ( V_184 ) ;
return V_144 -> V_200 ;
case - V_246 :
F_104 ( V_184 ) ;
return V_144 -> V_200 ;
case - V_248 :
F_130 ( V_144 ) ;
return - V_248 ;
}
return 0 ;
}
static bool
F_131 ( struct V_69 * V_78 )
{
return ! ( F_64 ( V_78 ) -> V_104 & V_280 ) ;
}
static void
F_132 ( struct V_183 * V_184 )
{
if ( ! F_131 ( V_184 -> V_78 ) )
return;
F_133 ( V_184 -> V_2 , V_184 -> V_78 ,
V_184 -> V_281 + V_184 -> V_273 . V_189 ) ;
F_12 ( L_21 , V_20 , V_184 -> V_2 -> V_282 ,
( unsigned long ) F_114 ( V_184 -> V_2 ) -> V_48 -> V_283 ) ;
}
static bool
F_134 ( struct V_69 * V_78 , int V_163 )
{
struct V_97 * V_284 = F_107 ( V_78 , V_163 ) ;
return F_135 ( V_284 ) ;
}
static int F_136 ( struct V_143 * V_144 ,
struct V_183 * V_184 )
{
F_78 ( V_184 -> V_2 ,
F_90 ( V_184 -> V_78 , V_184 -> V_272 ) ,
V_184 -> args . V_189 ,
V_144 -> V_145 ) ;
if ( F_11 ( F_44 ( V_285 , & V_184 -> args . V_276 -> V_104 ) ) ) {
F_137 ( V_144 , - V_94 ) ;
return - V_94 ;
}
if ( F_134 ( V_184 -> V_78 , V_184 -> V_272 ) ) {
F_12 ( L_22 , V_20 , V_144 -> V_186 ) ;
if ( F_117 ( V_184 -> V_78 ) )
F_129 ( V_184 ) ;
else
F_104 ( V_184 ) ;
F_137 ( V_144 , 0 ) ;
return - V_248 ;
}
V_184 -> V_286 = F_127 ;
return 0 ;
}
static void F_138 ( struct V_143 * V_144 , void * V_29 )
{
struct V_183 * V_184 = V_29 ;
if ( F_136 ( V_144 , V_184 ) )
return;
F_139 ( V_144 ) ;
}
static int F_140 ( struct V_203 * V_277 ,
struct V_287 * args ,
struct V_288 * V_273 ,
struct V_143 * V_144 )
{
if ( V_277 -> V_210 )
return F_141 ( V_277 -> V_210 ,
args ,
V_273 ,
V_144 ) ;
return F_142 ( V_277 -> V_289 ,
args ,
V_273 ,
V_144 ) ;
}
static void F_143 ( struct V_143 * V_144 , void * V_29 )
{
struct V_183 * V_184 = V_29 ;
if ( F_140 ( V_184 -> V_277 ,
& V_184 -> args . V_290 ,
& V_184 -> V_273 . V_291 ,
V_144 ) )
return;
if ( F_136 ( V_144 , V_184 ) )
return;
if ( F_144 ( & V_184 -> args . V_16 , V_184 -> args . V_276 ,
V_184 -> args . V_292 , V_293 ) == - V_94 )
F_137 ( V_144 , - V_94 ) ;
}
static void F_145 ( struct V_143 * V_144 , void * V_29 )
{
struct V_183 * V_184 = V_29 ;
F_12 ( L_23 , V_20 , V_144 -> V_200 ) ;
F_80 ( V_144 ,
F_90 ( V_184 -> V_78 , V_184 -> V_272 ) ,
V_184 -> args . V_189 , V_184 -> V_273 . V_189 ) ;
if ( F_44 ( V_199 , & V_184 -> V_104 ) &&
V_144 -> V_200 == 0 ) {
F_146 ( V_144 , & V_184 -> V_273 . V_291 ) ;
return;
}
V_184 -> V_294 -> V_295 ( V_144 , V_184 ) ;
}
static void F_147 ( struct V_143 * V_144 , void * V_29 )
{
struct V_183 * V_184 = V_29 ;
F_148 ( V_144 ,
& F_149 ( V_184 -> V_2 ) -> V_296 [ V_297 ] ) ;
}
static int F_150 ( struct V_143 * V_144 ,
struct V_183 * V_184 )
{
int V_11 ;
F_151 ( V_184 , V_144 -> V_200 ) ;
if ( V_144 -> V_200 < 0 )
F_124 ( V_184 -> V_78 , V_184 -> V_272 ,
V_184 -> args . V_59 , V_184 -> args . V_189 ,
V_184 -> V_273 . V_274 , V_298 ,
V_144 -> V_200 ) ;
V_11 = F_123 ( V_144 , V_184 -> args . V_276 -> V_202 ,
V_184 -> V_277 , V_184 -> V_78 ,
V_184 -> V_272 ) ;
switch ( V_11 ) {
case - V_245 :
F_152 ( V_184 -> V_78 -> V_107 ) ;
F_97 ( V_184 , true ) ;
return V_144 -> V_200 ;
case - V_246 :
F_153 ( V_184 -> V_78 -> V_107 ) ;
F_97 ( V_184 , false ) ;
return V_144 -> V_200 ;
case - V_248 :
F_130 ( V_144 ) ;
return - V_248 ;
}
if ( V_184 -> V_273 . V_197 -> V_149 == V_299 ||
V_184 -> V_273 . V_197 -> V_149 == V_300 )
F_132 ( V_184 ) ;
V_184 -> V_301 . V_302 = 0 ;
if ( V_144 -> V_200 >= 0 )
F_154 ( V_184 ) ;
return 0 ;
}
static int F_155 ( struct V_143 * V_144 ,
struct V_303 * V_29 )
{
int V_11 ;
F_156 ( V_29 , V_144 -> V_200 ) ;
if ( V_144 -> V_200 < 0 )
F_124 ( V_29 -> V_78 , V_29 -> V_304 ,
V_29 -> args . V_59 , V_29 -> args . V_189 ,
V_29 -> V_273 . V_274 , V_305 ,
V_144 -> V_200 ) ;
V_11 = F_123 ( V_144 , NULL , V_29 -> V_277 ,
V_29 -> V_78 , V_29 -> V_304 ) ;
switch ( V_11 ) {
case - V_245 :
F_152 ( V_29 -> V_78 -> V_107 ) ;
F_157 ( V_29 ) ;
return - V_248 ;
case - V_246 :
F_153 ( V_29 -> V_78 -> V_107 ) ;
F_157 ( V_29 ) ;
return - V_248 ;
case - V_248 :
F_130 ( V_144 ) ;
return - V_248 ;
}
if ( V_29 -> V_197 . V_149 == V_150
&& F_131 ( V_29 -> V_78 ) )
F_133 ( V_29 -> V_2 , V_29 -> V_78 , V_29 -> V_306 ) ;
return 0 ;
}
static int F_158 ( struct V_143 * V_144 ,
struct V_183 * V_184 )
{
F_82 ( V_184 -> V_2 ,
F_90 ( V_184 -> V_78 , V_184 -> V_272 ) ,
V_184 -> args . V_189 ,
V_144 -> V_145 ) ;
if ( F_11 ( F_44 ( V_285 , & V_184 -> args . V_276 -> V_104 ) ) ) {
F_137 ( V_144 , - V_94 ) ;
return - V_94 ;
}
if ( F_134 ( V_184 -> V_78 , V_184 -> V_272 ) ) {
bool V_185 ;
V_185 = F_117 ( V_184 -> V_78 ) ;
F_12 ( L_24 , V_20 ,
V_144 -> V_186 , V_185 ? L_25 : L_26 ) ;
F_97 ( V_184 , V_185 ) ;
F_137 ( V_144 , 0 ) ;
return - V_248 ;
}
return 0 ;
}
static void F_159 ( struct V_143 * V_144 , void * V_29 )
{
struct V_183 * V_184 = V_29 ;
if ( F_158 ( V_144 , V_184 ) )
return;
F_139 ( V_144 ) ;
}
static void F_160 ( struct V_143 * V_144 , void * V_29 )
{
struct V_183 * V_184 = V_29 ;
if ( F_140 ( V_184 -> V_277 ,
& V_184 -> args . V_290 ,
& V_184 -> V_273 . V_291 ,
V_144 ) )
return;
if ( F_158 ( V_144 , V_184 ) )
return;
if ( F_144 ( & V_184 -> args . V_16 , V_184 -> args . V_276 ,
V_184 -> args . V_292 , V_307 ) == - V_94 )
F_137 ( V_144 , - V_94 ) ;
}
static void F_161 ( struct V_143 * V_144 , void * V_29 )
{
struct V_183 * V_184 = V_29 ;
F_83 ( V_144 ,
F_90 ( V_184 -> V_78 , V_184 -> V_272 ) ,
V_184 -> args . V_189 , V_184 -> V_273 . V_189 ,
V_184 -> V_273 . V_197 -> V_149 ) ;
if ( F_44 ( V_199 , & V_184 -> V_104 ) &&
V_144 -> V_200 == 0 ) {
F_146 ( V_144 , & V_184 -> V_273 . V_291 ) ;
return;
}
V_184 -> V_294 -> V_295 ( V_144 , V_184 ) ;
}
static void F_162 ( struct V_143 * V_144 , void * V_29 )
{
struct V_183 * V_184 = V_29 ;
F_148 ( V_144 ,
& F_149 ( V_184 -> V_2 ) -> V_296 [ V_308 ] ) ;
}
static void F_163 ( struct V_143 * V_144 ,
struct V_303 * V_309 )
{
F_82 ( V_309 -> V_2 ,
F_90 ( V_309 -> V_78 , V_309 -> V_304 ) ,
0 , V_144 -> V_145 ) ;
}
static void F_164 ( struct V_143 * V_144 , void * V_29 )
{
F_163 ( V_144 , V_29 ) ;
F_139 ( V_144 ) ;
}
static void F_165 ( struct V_143 * V_144 , void * V_29 )
{
struct V_303 * V_310 = V_29 ;
if ( F_140 ( V_310 -> V_277 ,
& V_310 -> args . V_290 ,
& V_310 -> V_273 . V_291 ,
V_144 ) )
return;
F_163 ( V_144 , V_29 ) ;
}
static void F_166 ( struct V_143 * V_144 , void * V_29 )
{
struct V_303 * V_309 = V_29 ;
struct V_165 * V_166 ;
T_8 V_189 = 0 ;
if ( V_144 -> V_200 == 0 ) {
F_24 (req, &cdata->pages, wb_list)
V_189 += V_166 -> V_311 ;
}
F_83 ( V_144 ,
F_90 ( V_309 -> V_78 , V_309 -> V_304 ) ,
V_189 , V_189 , V_299 ) ;
F_167 ( V_144 , V_29 ) ;
}
static void F_168 ( struct V_143 * V_144 , void * V_29 )
{
struct V_303 * V_309 = V_29 ;
F_148 ( V_144 ,
& F_149 ( V_309 -> V_2 ) -> V_296 [ V_312 ] ) ;
}
static enum V_313
F_169 ( struct V_183 * V_184 )
{
struct V_69 * V_78 = V_184 -> V_78 ;
struct V_159 * V_154 ;
struct V_314 * V_315 ;
struct V_316 * V_317 ;
T_9 V_59 = V_184 -> args . V_59 ;
T_4 V_163 = V_184 -> V_272 ;
int V_259 ;
struct V_24 * V_25 ;
F_12 ( L_27 ,
V_20 , V_184 -> V_2 -> V_282 ,
V_184 -> args . V_318 , ( V_319 ) V_184 -> args . V_189 , V_59 ) ;
V_154 = F_87 ( V_78 , V_163 , false ) ;
if ( ! V_154 )
goto V_320;
V_315 = F_170 ( V_78 , V_163 , V_154 -> V_277 ,
V_184 -> V_2 ) ;
if ( F_171 ( V_315 ) )
goto V_320;
V_317 = F_172 ( V_78 , V_163 , V_184 -> V_50 ) ;
if ( F_171 ( V_317 ) )
goto V_320;
V_259 = F_173 ( V_78 , V_163 ) ;
F_12 ( L_28 , V_20 ,
V_154 -> V_321 , F_174 ( & V_154 -> V_277 -> V_322 ) , V_259 ) ;
F_175 ( & V_154 -> V_277 -> V_322 ) ;
V_184 -> V_277 = V_154 -> V_277 ;
V_25 = F_176 ( V_78 , V_163 ) ;
if ( V_25 )
V_184 -> args . V_25 = V_25 ;
V_184 -> args . V_59 = V_59 ;
V_184 -> V_281 = V_59 ;
F_177 ( V_315 , V_184 , V_317 , V_154 -> V_277 -> V_323 ,
V_259 == 3 ? & V_324 :
& V_325 ,
0 , V_326 ) ;
return V_327 ;
V_320:
if ( F_117 ( V_78 ) )
return V_328 ;
return V_329 ;
}
static enum V_313
F_178 ( struct V_183 * V_184 , int V_330 )
{
struct V_69 * V_78 = V_184 -> V_78 ;
struct V_159 * V_154 ;
struct V_314 * V_315 ;
struct V_316 * V_317 ;
T_9 V_59 = V_184 -> args . V_59 ;
int V_259 ;
struct V_24 * V_25 ;
int V_163 = V_184 -> V_272 ;
V_154 = F_87 ( V_78 , V_163 , true ) ;
if ( ! V_154 )
return V_329 ;
V_315 = F_170 ( V_78 , V_163 , V_154 -> V_277 ,
V_184 -> V_2 ) ;
if ( F_171 ( V_315 ) )
return V_329 ;
V_317 = F_172 ( V_78 , V_163 , V_184 -> V_50 ) ;
if ( F_171 ( V_317 ) )
return V_329 ;
V_259 = F_173 ( V_78 , V_163 ) ;
F_12 ( L_29 ,
V_20 , V_184 -> V_2 -> V_282 , V_330 , ( V_319 ) V_184 -> args . V_189 ,
V_59 , V_154 -> V_321 , F_174 ( & V_154 -> V_277 -> V_322 ) ,
V_259 ) ;
V_184 -> V_286 = F_150 ;
F_175 ( & V_154 -> V_277 -> V_322 ) ;
V_184 -> V_277 = V_154 -> V_277 ;
V_184 -> V_331 = V_163 ;
V_25 = F_176 ( V_78 , V_163 ) ;
if ( V_25 )
V_184 -> args . V_25 = V_25 ;
V_184 -> args . V_59 = V_59 ;
F_177 ( V_315 , V_184 , V_317 , V_154 -> V_277 -> V_323 ,
V_259 == 3 ? & V_332 :
& V_333 ,
V_330 , V_326 ) ;
return V_327 ;
}
static T_4 F_179 ( struct V_69 * V_78 , T_4 V_36 )
{
return V_36 ;
}
static struct V_24 *
F_180 ( struct V_69 * V_78 , T_4 V_36 )
{
struct V_51 * V_334 = F_64 ( V_78 ) ;
return & V_334 -> V_53 [ V_36 ] -> V_40 [ 0 ] ;
}
static int F_181 ( struct V_303 * V_29 , int V_335 )
{
struct V_69 * V_78 = V_29 -> V_78 ;
struct V_159 * V_154 ;
struct V_314 * V_315 ;
struct V_316 * V_317 ;
T_4 V_163 ;
int V_259 ;
struct V_24 * V_25 ;
V_163 = F_179 ( V_78 , V_29 -> V_304 ) ;
V_154 = F_87 ( V_78 , V_163 , true ) ;
if ( ! V_154 )
goto V_336;
V_315 = F_170 ( V_78 , V_163 , V_154 -> V_277 ,
V_29 -> V_2 ) ;
if ( F_171 ( V_315 ) )
goto V_336;
V_317 = F_172 ( V_78 , V_163 , V_29 -> V_50 ) ;
if ( F_171 ( V_317 ) )
goto V_336;
V_259 = F_173 ( V_78 , V_163 ) ;
F_12 ( L_30 , V_20 ,
V_29 -> V_2 -> V_282 , V_335 , F_174 ( & V_154 -> V_277 -> V_322 ) ,
V_259 ) ;
V_29 -> V_337 = F_155 ;
V_29 -> V_50 = V_317 ;
F_175 ( & V_154 -> V_277 -> V_322 ) ;
V_29 -> V_277 = V_154 -> V_277 ;
V_25 = F_180 ( V_78 , V_29 -> V_304 ) ;
if ( V_25 )
V_29 -> args . V_25 = V_25 ;
return F_182 ( V_315 , V_29 , V_154 -> V_277 -> V_323 ,
V_259 == 3 ? & V_338 :
& V_339 ,
V_335 , V_326 ) ;
V_336:
F_157 ( V_29 ) ;
F_183 ( V_29 ) ;
return - V_248 ;
}
static int
F_184 ( struct V_2 * V_2 , struct V_79 * V_340 ,
int V_335 , struct V_151 * V_152 )
{
return F_185 ( V_2 , V_340 , V_335 , V_152 ,
F_181 ) ;
}
static struct V_341 *
F_186 ( struct V_2 * V_2 )
{
struct V_1 * V_48 = F_114 ( V_2 ) -> V_48 ;
if ( V_48 == NULL )
return NULL ;
return & F_8 ( V_48 ) -> V_108 ;
}
static void
F_187 ( struct V_97 * V_342 )
{
F_188 ( F_189 ( V_342 , struct V_343 ,
V_344 ) ) ;
}
static int F_190 ( struct V_4 * V_345 ,
struct V_14 * V_15 ,
const struct V_346 * args )
{
struct V_1 * V_184 = & V_345 -> V_8 ;
T_3 * V_116 ;
int V_189 = 0 , V_57 = 0 ;
V_116 = F_191 ( V_15 , 4 ) ;
if ( F_11 ( ! V_116 ) )
return - V_347 ;
F_23 ( & V_184 -> V_44 -> V_45 ) ;
V_57 = F_192 ( V_345 , V_15 , & V_189 , & args -> V_58 ) ;
F_26 ( & V_184 -> V_44 -> V_45 ) ;
* V_116 = F_193 ( V_189 ) ;
return V_57 ;
}
static void F_194 ( struct V_4 * V_345 ,
struct V_14 * V_15 ,
const struct V_346 * args )
{
T_3 * V_17 ;
V_17 = F_191 ( V_15 , 4 ) ;
if ( F_195 ( V_17 ) )
* V_17 = F_193 ( 0 ) ;
}
static struct V_97 *
F_196 ( struct V_205 * V_348 ,
struct V_349 * V_350 , T_1 V_3 )
{
struct V_343 * V_351 ;
V_351 = F_197 ( V_348 , V_350 , V_3 ) ;
if ( ! V_351 )
return NULL ;
return & V_351 -> V_344 ;
}
static void
F_198 ( struct V_1 * V_9 ,
struct V_14 * V_15 ,
const struct V_346 * args )
{
struct V_4 * V_345 = F_8 ( V_9 ) ;
T_3 * V_116 ;
F_12 ( L_31 , V_20 ) ;
V_116 = F_191 ( V_15 , 4 ) ;
F_199 ( ! V_116 ) ;
if ( F_190 ( V_345 , V_15 , args ) )
goto V_247;
F_194 ( V_345 , V_15 , args ) ;
V_247:
* V_116 = F_193 ( ( V_15 -> V_17 - V_116 - 1 ) * 4 ) ;
F_12 ( L_32 , V_20 ) ;
}
static int
F_200 ( const struct V_352 * V_353 , char * V_85 , const V_319 V_354 )
{
const struct V_355 * sin = (struct V_355 * ) V_353 ;
return snprintf ( V_85 , V_354 , L_33 , & sin -> V_356 ) ;
}
static V_319
F_201 ( const struct V_352 * V_353 , char * V_85 ,
const int V_354 )
{
const struct V_357 * V_358 = (struct V_357 * ) V_353 ;
const struct V_359 * V_360 = & V_358 -> V_361 ;
if ( F_202 ( V_360 ) )
return snprintf ( V_85 , V_354 , L_34 ) ;
if ( F_203 ( V_360 ) )
return snprintf ( V_85 , V_354 , L_35 ) ;
if ( F_204 ( V_360 ) )
return snprintf ( V_85 , V_354 , L_36 ,
& V_360 -> V_362 [ 3 ] ) ;
return snprintf ( V_85 , V_354 , L_37 , V_360 ) ;
}
static void
F_205 ( struct V_14 * V_15 , struct V_363 * V_364 )
{
struct V_352 * V_353 = (struct V_352 * ) & V_364 -> V_365 ;
char V_366 [ V_367 ] ;
char V_368 [ V_369 ] ;
char * V_370 ;
unsigned short V_371 ;
int V_31 , V_372 ;
T_3 * V_17 ;
switch ( V_353 -> V_373 ) {
case V_374 :
if ( F_200 ( V_353 , V_368 , sizeof( V_368 ) ) == 0 )
return;
V_371 = F_206 ( ( (struct V_355 * ) V_353 ) -> V_375 ) ;
V_370 = L_38 ;
V_372 = 3 ;
break;
case V_376 :
if ( F_201 ( V_353 , V_368 , sizeof( V_368 ) ) == 0 )
return;
V_371 = F_206 ( ( (struct V_357 * ) V_353 ) -> V_377 ) ;
V_370 = L_39 ;
V_372 = 4 ;
break;
default:
F_70 ( 1 ) ;
return;
}
snprintf ( V_366 , sizeof( V_366 ) , L_40 , V_371 >> 8 , V_371 & 0xff ) ;
V_31 = F_207 ( V_368 , V_366 , sizeof( V_368 ) ) ;
V_17 = F_191 ( V_15 , 4 + V_372 ) ;
F_208 ( V_17 , V_370 , V_372 ) ;
V_17 = F_191 ( V_15 , 4 + V_31 ) ;
F_208 ( V_17 , V_368 , V_31 ) ;
}
static void
F_209 ( struct V_14 * V_15 ,
T_6 V_378 )
{
struct V_379 V_380 ;
T_3 * V_17 ;
V_17 = F_191 ( V_15 , 12 ) ;
V_380 = F_210 ( V_378 ) ;
V_17 = F_211 ( V_17 , V_380 . V_381 ) ;
* V_17 ++ = F_193 ( V_380 . V_382 ) ;
}
static void
F_212 ( struct V_14 * V_15 ,
struct V_126 * V_383 )
{
T_3 * V_17 ;
V_17 = F_191 ( V_15 , 5 * 8 ) ;
V_17 = F_211 ( V_17 , V_383 -> V_129 ) ;
V_17 = F_211 ( V_17 , V_383 -> V_130 ) ;
V_17 = F_211 ( V_17 , V_383 -> V_135 ) ;
V_17 = F_211 ( V_17 , V_383 -> V_136 ) ;
V_17 = F_211 ( V_17 , V_383 -> V_137 ) ;
F_209 ( V_15 , V_383 -> V_138 ) ;
F_209 ( V_15 , V_383 -> V_139 ) ;
}
static void
F_213 ( struct V_14 * V_15 ,
struct V_384 * args ,
struct V_385 * V_386 )
{
struct V_33 * V_41 = V_386 -> V_387 ;
struct V_363 * V_364 ;
struct V_159 * V_154 = V_41 -> V_46 -> V_154 ;
struct V_24 * V_25 = & V_41 -> V_40 [ 0 ] ;
T_3 * V_17 , * V_116 ;
V_364 = F_214 ( & V_154 -> V_388 , struct V_363 , V_389 ) ;
F_12 ( L_41 ,
V_20 , V_154 -> V_321 , V_364 -> V_390 ) ;
V_116 = F_191 ( V_15 , 4 ) ;
F_205 ( V_15 , V_364 ) ;
V_17 = F_191 ( V_15 , 4 + V_25 -> V_26 ) ;
F_208 ( V_17 , V_25 -> V_29 , V_25 -> V_26 ) ;
F_23 ( & V_41 -> V_49 ) ;
F_212 ( V_15 , & V_41 -> V_141 . V_128 ) ;
F_212 ( V_15 , & V_41 -> V_146 . V_128 ) ;
F_26 ( & V_41 -> V_49 ) ;
F_209 ( V_15 , F_71 ( F_81 () , V_41 -> V_115 ) ) ;
V_17 = F_191 ( V_15 , 4 ) ;
* V_17 = F_193 ( false ) ;
* V_116 = F_193 ( ( V_15 -> V_17 - V_116 - 1 ) * 4 ) ;
}
static int
F_215 ( struct V_384 * args ,
struct V_1 * V_9 ,
int V_391 )
{
struct V_4 * V_42 = F_8 ( V_9 ) ;
struct V_33 * V_41 ;
struct V_97 * V_392 ;
struct V_385 * V_386 ;
int V_36 = 0 ;
F_24 (mirror, &ff_layout->mirrors, mirrors) {
if ( V_36 >= V_391 )
break;
if ( ! V_41 -> V_46 )
continue;
if ( ! F_25 ( & V_41 -> V_47 ) )
continue;
V_392 = & V_41 -> V_46 -> V_344 ;
V_386 = & args -> V_386 [ V_36 ] ;
memcpy ( & V_386 -> V_393 , & V_392 -> V_394 , V_23 ) ;
V_386 -> V_59 = 0 ;
V_386 -> V_60 = V_61 ;
V_386 -> V_395 = V_41 -> V_141 . V_128 . V_135 ;
V_386 -> V_396 = V_41 -> V_141 . V_128 . V_136 ;
V_386 -> V_397 = V_41 -> V_146 . V_128 . V_135 ;
V_386 -> V_398 = V_41 -> V_146 . V_128 . V_136 ;
V_386 -> V_399 = V_400 ;
V_386 -> V_401 = F_213 ;
V_386 -> V_387 = V_41 ;
V_36 ++ ;
}
return V_36 ;
}
static int
F_216 ( struct V_384 * args )
{
struct V_4 * V_42 ;
struct V_33 * V_41 ;
int V_402 = 0 ;
F_23 ( & args -> V_2 -> V_45 ) ;
V_42 = F_8 ( F_114 ( args -> V_2 ) -> V_48 ) ;
F_24 (mirror, &ff_layout->mirrors, mirrors) {
if ( F_174 ( & V_41 -> V_47 ) != 0 )
V_402 ++ ;
}
F_26 ( & args -> V_2 -> V_45 ) ;
if ( V_402 > V_403 ) {
F_12 ( L_42 ,
V_20 , V_402 , V_403 ) ;
V_402 = V_403 ;
}
args -> V_386 = F_217 ( V_402 , sizeof( * args -> V_386 ) , V_147 ) ;
if ( ! args -> V_386 )
return - V_90 ;
F_23 ( & args -> V_2 -> V_45 ) ;
args -> V_404 = F_215 ( args ,
& V_42 -> V_8 , V_402 ) ;
F_26 ( & args -> V_2 -> V_45 ) ;
return 0 ;
}
static void
F_218 ( struct V_405 * V_29 )
{
struct V_33 * V_41 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_29 -> args . V_404 ; V_36 ++ ) {
V_41 = V_29 -> args . V_386 [ V_36 ] . V_387 ;
V_29 -> args . V_386 [ V_36 ] . V_387 = NULL ;
F_35 ( V_41 ) ;
}
}
static int T_10 F_219 ( void )
{
F_17 ( V_406 L_43 ,
V_20 ) ;
return F_220 ( & V_407 ) ;
}
static void T_11 F_221 ( void )
{
F_17 ( V_406 L_44 ,
V_20 ) ;
F_222 ( & V_407 ) ;
}
