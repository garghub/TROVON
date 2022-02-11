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
for ( V_37 = 0 ; V_37 < V_35 -> V_38 ; V_37 ++ ) {
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
if ( ! V_17 )
goto V_109;
V_52 -> V_84 = F_16 ( V_17 ) ;
V_17 = F_10 ( & V_89 , 4 ) ;
if ( ! V_17 )
goto V_109;
for ( V_36 = 0 ; V_36 < V_52 -> V_54 ; V_36 ++ )
V_52 -> V_53 [ V_36 ] -> V_110 = F_16 ( V_17 ) ;
V_109:
F_48 ( V_52 ) ;
V_95 = F_38 ( V_56 ) ;
if ( V_95 )
goto V_101;
F_50 ( V_52 ) ;
V_57 = & V_52 -> V_8 ;
F_12 ( L_10 , V_20 ) ;
V_111:
F_63 ( V_93 ) ;
return V_57 ;
V_101:
F_39 ( V_52 ) ;
V_57 = F_54 ( V_95 ) ;
F_12 ( L_11 , V_20 , V_95 ) ;
goto V_111;
}
static bool F_64 ( struct V_1 * V_48 )
{
struct V_69 * V_78 ;
F_24 (lseg, &layout->plh_segs, pls_list)
if ( V_78 -> V_74 . V_67 == V_112 )
return true ;
return false ;
}
static void
F_65 ( struct V_69 * V_78 )
{
struct V_51 * V_52 = F_66 ( V_78 ) ;
F_12 ( L_5 , V_20 ) ;
if ( V_78 -> V_74 . V_67 == V_112 ) {
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_5 = F_8 ( V_78 -> V_113 ) ;
V_2 = V_5 -> V_8 . V_44 ;
F_23 ( & V_2 -> V_45 ) ;
if ( ! F_64 ( V_78 -> V_113 ) ) {
V_5 -> V_114 . V_115 = 0 ;
F_7 ( V_5 -> V_114 . V_116 ) ;
V_5 -> V_114 . V_116 = NULL ;
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
F_68 ( struct V_117 * V_118 , T_6 V_119 )
{
if ( F_69 ( & V_118 -> V_120 ) == 1 ) {
V_118 -> V_121 = V_119 ;
}
}
static T_6
F_70 ( struct V_117 * V_118 , T_6 V_119 )
{
T_6 V_122 ;
if ( F_71 ( & V_118 -> V_120 ) < 0 )
F_72 ( 1 ) ;
V_122 = V_118 -> V_121 ;
V_118 -> V_121 = V_119 ;
return F_73 ( V_119 , V_122 ) ;
}
static bool
F_74 ( struct V_33 * V_41 ,
struct V_123 * V_124 ,
T_6 V_119 )
{
static const T_6 V_125 = { 0 } ;
T_7 V_110 = V_126 ;
F_68 ( & V_124 -> V_127 , V_119 ) ;
if ( F_75 ( V_41 -> V_121 , V_125 ) )
V_41 -> V_121 = V_119 ;
if ( F_75 ( V_41 -> V_128 , V_125 ) )
V_41 -> V_128 = V_119 ;
if ( V_41 -> V_110 != 0 )
V_110 = ( T_7 ) V_41 -> V_110 * 1000LL ;
else if ( V_129 != 0 )
V_110 = ( T_7 ) V_129 * 1000LL ;
if ( F_76 ( F_73 ( V_119 , V_41 -> V_128 ) ) >=
V_110 ) {
V_41 -> V_128 = V_119 ;
return true ;
}
return false ;
}
static void
F_77 ( struct V_123 * V_124 ,
T_8 V_130 )
{
struct V_131 * V_132 = & V_124 -> V_133 ;
V_132 -> V_134 ++ ;
V_132 -> V_135 += V_130 ;
}
static void
F_78 ( struct V_123 * V_124 ,
T_8 V_130 ,
T_8 V_136 ,
T_6 V_137 ,
T_6 V_138 )
{
struct V_131 * V_132 = & V_124 -> V_133 ;
T_6 V_139 = F_73 ( V_137 , V_138 ) ;
T_6 V_118 ;
V_132 -> V_140 ++ ;
V_132 -> V_141 += V_136 ;
V_132 -> V_142 += V_130 - V_136 ;
V_118 = F_70 ( & V_124 -> V_127 , V_137 ) ;
V_132 -> V_143 =
F_79 ( V_132 -> V_143 , V_118 ) ;
V_132 -> V_144 =
F_79 ( V_132 -> V_144 ,
V_139 ) ;
}
static void
F_80 ( struct V_2 * V_2 ,
struct V_33 * V_41 ,
T_8 V_130 , T_6 V_119 )
{
bool V_145 ;
F_23 ( & V_41 -> V_49 ) ;
V_145 = F_74 ( V_41 , & V_41 -> V_146 , V_119 ) ;
F_77 ( & V_41 -> V_146 , V_130 ) ;
F_26 ( & V_41 -> V_49 ) ;
if ( V_145 )
F_81 ( V_2 , V_147 ) ;
}
static void
F_82 ( struct V_148 * V_149 ,
struct V_33 * V_41 ,
T_8 V_130 ,
T_8 V_136 )
{
F_23 ( & V_41 -> V_49 ) ;
F_78 ( & V_41 -> V_146 ,
V_130 , V_136 ,
F_83 () , V_149 -> V_150 ) ;
F_26 ( & V_41 -> V_49 ) ;
}
static void
F_84 ( struct V_2 * V_2 ,
struct V_33 * V_41 ,
T_8 V_130 , T_6 V_119 )
{
bool V_145 ;
F_23 ( & V_41 -> V_49 ) ;
V_145 = F_74 ( V_41 , & V_41 -> V_151 , V_119 ) ;
F_77 ( & V_41 -> V_151 , V_130 ) ;
F_26 ( & V_41 -> V_49 ) ;
if ( V_145 )
F_81 ( V_2 , V_152 ) ;
}
static void
F_85 ( struct V_148 * V_149 ,
struct V_33 * V_41 ,
T_8 V_130 ,
T_8 V_136 ,
enum V_153 V_154 )
{
if ( V_154 == V_155 )
V_130 = V_136 = 0 ;
F_23 ( & V_41 -> V_49 ) ;
F_78 ( & V_41 -> V_151 ,
V_130 , V_136 , F_83 () , V_149 -> V_150 ) ;
F_26 ( & V_41 -> V_49 ) ;
}
static int
F_86 ( struct V_69 * V_78 ,
struct V_156 * V_157 ,
T_1 V_3 )
{
struct V_51 * V_52 = F_66 ( V_78 ) ;
struct V_158 * V_116 ;
int V_26 ;
if ( V_157 -> V_159 -> V_115 != 0 ) {
return 0 ;
}
V_26 = F_67 ( V_52 ) * F_87 ( V_78 ) ;
V_116 = F_59 ( V_26 , sizeof( struct V_158 ) ,
V_3 ) ;
if ( ! V_116 )
return - V_96 ;
else {
int V_36 ;
F_23 ( V_157 -> V_49 ) ;
if ( V_157 -> V_159 -> V_115 != 0 )
F_7 ( V_116 ) ;
else {
V_157 -> V_159 -> V_116 = V_116 ;
V_157 -> V_159 -> V_115 = V_26 ;
for ( V_36 = 0 ; V_36 < V_26 ; V_36 ++ ) {
F_3 ( & V_116 [ V_36 ] . V_160 ) ;
F_3 ( & V_116 [ V_36 ] . V_161 ) ;
V_116 [ V_36 ] . V_162 . V_154 =
V_163 ;
}
}
F_26 ( V_157 -> V_49 ) ;
return 0 ;
}
}
static struct V_164 *
F_88 ( struct V_69 * V_78 ,
int V_165 ,
int * V_166 )
{
struct V_51 * V_52 = F_66 ( V_78 ) ;
struct V_164 * V_159 ;
int V_167 ;
for ( V_167 = V_165 ; V_167 < V_52 -> V_54 ; V_167 ++ ) {
V_159 = F_89 ( V_78 , V_167 , false ) ;
if ( V_159 ) {
* V_166 = V_167 ;
return V_159 ;
}
}
return NULL ;
}
static void
F_90 ( struct V_168 * V_169 ,
struct V_170 * V_171 )
{
struct V_172 * V_173 ;
struct V_33 * V_41 ;
struct V_164 * V_159 ;
int V_174 ;
if ( ! V_169 -> V_175 ) {
V_169 -> V_175 = F_91 ( V_169 -> V_176 ,
V_171 -> V_177 ,
0 ,
V_61 ,
V_68 ,
V_147 ) ;
if ( F_92 ( V_169 -> V_175 ) ) {
V_169 -> V_178 = F_93 ( V_169 -> V_175 ) ;
V_169 -> V_175 = NULL ;
return;
}
}
if ( V_169 -> V_175 == NULL )
goto V_179;
V_159 = F_88 ( V_169 -> V_175 , 0 , & V_174 ) ;
if ( ! V_159 )
goto V_179;
V_41 = F_94 ( V_169 -> V_175 , V_174 ) ;
V_169 -> V_180 = V_174 ;
V_173 = & V_169 -> V_181 [ 0 ] ;
V_173 -> V_182 = V_41 -> V_46 -> V_183 [ 0 ] . V_184 ;
return;
V_179:
F_95 ( V_169 -> V_175 ) ;
V_169 -> V_175 = NULL ;
F_96 ( V_169 ) ;
}
static void
F_97 ( struct V_168 * V_169 ,
struct V_170 * V_171 )
{
struct V_33 * V_41 ;
struct V_172 * V_173 ;
struct V_156 V_157 ;
struct V_164 * V_159 ;
int V_36 ;
int V_185 ;
if ( ! V_169 -> V_175 ) {
V_169 -> V_175 = F_91 ( V_169 -> V_176 ,
V_171 -> V_177 ,
0 ,
V_61 ,
V_112 ,
V_186 ) ;
if ( F_92 ( V_169 -> V_175 ) ) {
V_169 -> V_178 = F_93 ( V_169 -> V_175 ) ;
V_169 -> V_175 = NULL ;
return;
}
}
if ( V_169 -> V_175 == NULL )
goto V_179;
F_98 ( & V_157 , V_169 -> V_176 , V_169 -> V_187 ) ;
V_185 = F_86 ( V_169 -> V_175 , & V_157 , V_186 ) ;
if ( V_185 < 0 )
goto V_179;
if ( F_72 ( V_169 -> V_188 !=
F_87 ( V_169 -> V_175 ) ) )
goto V_179;
for ( V_36 = 0 ; V_36 < V_169 -> V_188 ; V_36 ++ ) {
V_159 = F_89 ( V_169 -> V_175 , V_36 , true ) ;
if ( ! V_159 )
goto V_179;
V_173 = & V_169 -> V_181 [ V_36 ] ;
V_41 = F_94 ( V_169 -> V_175 , V_36 ) ;
V_173 -> V_182 = V_41 -> V_46 -> V_183 [ 0 ] . V_189 ;
}
return;
V_179:
F_95 ( V_169 -> V_175 ) ;
V_169 -> V_175 = NULL ;
F_99 ( V_169 ) ;
}
static unsigned int
F_100 ( struct V_168 * V_169 ,
struct V_170 * V_171 )
{
if ( ! V_169 -> V_175 ) {
V_169 -> V_175 = F_91 ( V_169 -> V_176 ,
V_171 -> V_177 ,
0 ,
V_61 ,
V_112 ,
V_186 ) ;
if ( F_92 ( V_169 -> V_175 ) ) {
V_169 -> V_178 = F_93 ( V_169 -> V_175 ) ;
V_169 -> V_175 = NULL ;
goto V_190;
}
}
if ( V_169 -> V_175 )
return F_87 ( V_169 -> V_175 ) ;
F_99 ( V_169 ) ;
V_190:
return 1 ;
}
static void F_101 ( struct V_191 * V_192 , bool V_193 )
{
struct V_148 * V_149 = & V_192 -> V_149 ;
F_102 ( V_192 -> V_2 , false ) ;
if ( V_193 ) {
F_12 ( L_12
L_13 , V_20 ,
V_192 -> V_149 . V_194 ,
V_192 -> V_2 -> V_195 -> V_196 ,
( unsigned long long ) F_103 ( V_192 -> V_2 ) ,
V_192 -> args . V_197 ,
( unsigned long long ) V_192 -> args . V_59 ) ;
V_192 -> V_198 -> V_199 ( V_192 ) ;
return;
}
if ( ! F_104 ( V_200 , & V_192 -> V_84 ) ) {
F_12 ( L_14
L_13 , V_20 ,
V_192 -> V_149 . V_194 ,
V_192 -> V_2 -> V_195 -> V_196 ,
( unsigned long long ) F_103 ( V_192 -> V_2 ) ,
V_192 -> args . V_197 ,
( unsigned long long ) V_192 -> args . V_59 ) ;
V_149 -> V_201 = F_105 ( V_192 ) ;
}
}
static void F_106 ( struct V_191 * V_192 )
{
struct V_148 * V_149 = & V_192 -> V_149 ;
F_102 ( V_192 -> V_2 , false ) ;
if ( ! F_104 ( V_200 , & V_192 -> V_84 ) ) {
F_12 ( L_14
L_13 , V_20 ,
V_192 -> V_149 . V_194 ,
V_192 -> V_2 -> V_195 -> V_196 ,
( unsigned long long ) F_103 ( V_192 -> V_2 ) ,
V_192 -> args . V_197 ,
( unsigned long long ) V_192 -> args . V_59 ) ;
V_149 -> V_201 = F_107 ( V_192 ) ;
}
}
static int F_108 ( struct V_148 * V_149 ,
struct V_202 * V_203 ,
struct V_204 * V_205 ,
struct V_69 * V_78 ,
int V_167 )
{
struct V_1 * V_9 = V_78 -> V_113 ;
struct V_2 * V_2 = V_9 -> V_44 ;
struct V_206 * V_207 = F_61 ( V_2 ) ;
struct V_82 * V_22 = F_109 ( V_78 , V_167 ) ;
struct V_204 * V_208 = V_207 -> V_204 ;
struct V_209 * V_210 = & V_205 -> V_211 -> V_212 ;
if ( V_149 -> V_201 >= 0 )
return 0 ;
switch ( V_149 -> V_201 ) {
case - V_213 :
case - V_214 :
case - V_215 :
if ( V_203 == NULL )
break;
F_110 ( V_203 -> V_2 ) ;
case - V_216 :
if ( V_203 == NULL )
break;
if ( F_111 ( V_207 , V_203 ) < 0 )
goto V_217;
goto V_218;
case - V_219 :
if ( V_203 != NULL ) {
if ( F_111 ( V_207 , V_203 ) < 0 )
goto V_217;
}
F_112 ( V_208 ) ;
goto V_218;
case - V_220 :
case - V_221 :
case - V_222 :
case - V_223 :
case - V_224 :
case - V_225 :
case - V_226 :
F_12 ( L_15
L_16 , V_20 , V_149 -> V_201 ,
V_205 -> V_227 ) ;
F_113 ( V_205 -> V_211 , V_149 -> V_201 ) ;
break;
case - V_228 :
case - V_229 :
F_114 ( V_149 , V_230 ) ;
break;
case - V_231 :
break;
case - V_232 :
case - V_233 :
case - V_234 :
case - V_235 :
case - V_236 :
case - V_237 :
F_12 ( L_17 , V_20 ,
V_149 -> V_201 ) ;
F_115 ( F_116 ( V_2 ) ) ;
F_117 ( & V_210 -> V_238 ) ;
goto V_239;
case - V_240 :
case - V_241 :
case - V_242 :
case - V_243 :
case - V_100 :
case - V_244 :
case - V_245 :
F_12 ( L_18 , V_20 ,
V_149 -> V_201 ) ;
F_118 ( V_22 ) ;
F_117 ( & V_210 -> V_238 ) ;
default:
if ( F_119 ( V_78 ) ||
F_120 ( V_78 ) )
return - V_246 ;
V_239:
F_12 ( L_19 , V_20 ,
V_149 -> V_201 ) ;
return - V_247 ;
}
V_190:
V_149 -> V_201 = 0 ;
return - V_248 ;
V_217:
V_149 -> V_201 = - V_100 ;
return 0 ;
V_218:
F_121 ( & V_208 -> V_249 , V_149 , NULL ) ;
if ( F_44 ( V_250 , & V_208 -> V_251 ) == 0 )
F_122 ( & V_208 -> V_249 , V_149 ) ;
goto V_190;
}
static int F_123 ( struct V_148 * V_149 ,
struct V_69 * V_78 ,
int V_167 )
{
struct V_82 * V_22 = F_109 ( V_78 , V_167 ) ;
if ( V_149 -> V_201 >= 0 )
return 0 ;
switch ( V_149 -> V_201 ) {
case - V_252 :
case - V_233 :
case - V_235 :
case - V_234 :
case - V_253 :
case - V_254 :
break;
case - V_255 :
F_124 ( V_78 -> V_113 -> V_44 , V_256 ) ;
goto V_257;
default:
F_12 ( L_18 , V_20 ,
V_149 -> V_201 ) ;
F_118 ( V_22 ) ;
}
return - V_246 ;
V_257:
V_149 -> V_201 = 0 ;
F_125 ( V_149 ) ;
F_114 ( V_149 , V_258 ) ;
return - V_248 ;
}
static int F_126 ( struct V_148 * V_149 ,
struct V_202 * V_203 ,
struct V_204 * V_205 ,
struct V_69 * V_78 ,
int V_167 )
{
int V_259 = V_205 -> V_260 -> V_261 -> V_262 ;
switch ( V_259 ) {
case 3 :
return F_123 ( V_149 , V_78 , V_167 ) ;
case 4 :
return F_108 ( V_149 , V_203 , V_205 ,
V_78 , V_167 ) ;
default:
F_72 ( 1 ) ;
return 0 ;
}
}
static void F_127 ( struct V_69 * V_78 ,
int V_167 , T_5 V_59 , T_5 V_60 ,
T_4 V_185 , int V_263 , int error )
{
struct V_33 * V_41 ;
int V_11 ;
if ( V_185 == 0 ) {
switch ( error ) {
case - V_244 :
case - V_264 :
case - V_265 :
case - V_266 :
case - V_240 :
case - V_267 :
case - V_241 :
case - V_242 :
case - V_243 :
case - V_268 :
case - V_19 :
case - V_245 :
case - V_269 :
V_185 = V_270 ;
break;
case - V_252 :
V_185 = V_271 ;
break;
default:
return;
}
}
switch ( V_185 ) {
case V_228 :
case V_229 :
return;
default:
break;
}
V_41 = F_94 ( V_78 , V_167 ) ;
V_11 = F_128 ( F_8 ( V_78 -> V_113 ) ,
V_41 , V_59 , V_60 , V_185 , V_263 ,
V_152 ) ;
F_129 ( V_78 -> V_113 -> V_44 , V_78 ) ;
F_12 ( L_20 , V_20 , V_11 , V_263 , V_185 ) ;
}
static int F_130 ( struct V_148 * V_149 ,
struct V_191 * V_192 )
{
int V_11 ;
F_131 ( V_192 , V_149 -> V_201 ) ;
if ( V_149 -> V_201 < 0 )
F_127 ( V_192 -> V_78 , V_192 -> V_272 ,
V_192 -> args . V_59 , V_192 -> args . V_197 ,
V_192 -> V_273 . V_274 , V_275 ,
V_149 -> V_201 ) ;
V_11 = F_126 ( V_149 , V_192 -> args . V_276 -> V_203 ,
V_192 -> V_277 , V_192 -> V_78 ,
V_192 -> V_272 ) ;
switch ( V_11 ) {
case - V_246 :
if ( F_88 ( V_192 -> V_78 ,
V_192 -> V_272 + 1 ,
& V_192 -> V_272 ) )
goto V_278;
F_45 ( V_279 ,
& V_192 -> V_78 -> V_113 -> V_280 ) ;
F_132 ( V_192 ) ;
return V_149 -> V_201 ;
case - V_247 :
F_106 ( V_192 ) ;
return V_149 -> V_201 ;
case - V_248 :
goto V_278;
}
return 0 ;
V_278:
F_125 ( V_149 ) ;
return - V_248 ;
}
static bool
F_133 ( struct V_69 * V_78 )
{
return ! ( F_66 ( V_78 ) -> V_84 & V_281 ) ;
}
static void
F_134 ( struct V_191 * V_192 )
{
if ( ! F_133 ( V_192 -> V_78 ) )
return;
F_135 ( V_192 -> V_2 , V_192 -> V_78 ,
V_192 -> V_282 + V_192 -> V_273 . V_197 ) ;
F_12 ( L_21 , V_20 , V_192 -> V_2 -> V_283 ,
( unsigned long ) F_116 ( V_192 -> V_2 ) -> V_48 -> V_284 ) ;
}
static bool
F_136 ( struct V_69 * V_78 , int V_167 )
{
struct V_82 * V_83 = F_109 ( V_78 , V_167 ) ;
return F_137 ( V_83 ) ;
}
static void F_138 ( struct V_148 * V_149 ,
struct V_191 * V_192 )
{
if ( F_104 ( V_285 , & V_192 -> V_84 ) )
return;
F_80 ( V_192 -> V_2 ,
F_94 ( V_192 -> V_78 , V_192 -> V_272 ) ,
V_192 -> args . V_197 ,
V_149 -> V_150 ) ;
}
static void F_139 ( struct V_148 * V_149 ,
struct V_191 * V_192 )
{
if ( ! F_140 ( V_285 , & V_192 -> V_84 ) )
return;
F_82 ( V_149 ,
F_94 ( V_192 -> V_78 , V_192 -> V_272 ) ,
V_192 -> args . V_197 ,
V_192 -> V_273 . V_197 ) ;
}
static int F_141 ( struct V_148 * V_149 ,
struct V_191 * V_192 )
{
if ( F_11 ( F_44 ( V_286 , & V_192 -> args . V_276 -> V_84 ) ) ) {
F_142 ( V_149 , - V_100 ) ;
return - V_100 ;
}
if ( F_136 ( V_192 -> V_78 , V_192 -> V_272 ) ) {
F_12 ( L_22 , V_20 , V_149 -> V_194 ) ;
if ( F_120 ( V_192 -> V_78 ) )
F_132 ( V_192 ) ;
else
F_106 ( V_192 ) ;
F_142 ( V_149 , 0 ) ;
return - V_248 ;
}
V_192 -> V_287 = F_130 ;
F_138 ( V_149 , V_192 ) ;
return 0 ;
}
static void F_143 ( struct V_148 * V_149 , void * V_29 )
{
struct V_191 * V_192 = V_29 ;
if ( F_141 ( V_149 , V_192 ) )
return;
F_144 ( V_149 ) ;
}
static int F_145 ( struct V_204 * V_277 ,
struct V_288 * args ,
struct V_289 * V_273 ,
struct V_148 * V_149 )
{
if ( V_277 -> V_211 )
return F_146 ( V_277 -> V_211 ,
args ,
V_273 ,
V_149 ) ;
return F_147 ( V_277 -> V_290 ,
args ,
V_273 ,
V_149 ) ;
}
static void F_148 ( struct V_148 * V_149 , void * V_29 )
{
struct V_191 * V_192 = V_29 ;
if ( F_145 ( V_192 -> V_277 ,
& V_192 -> args . V_291 ,
& V_192 -> V_273 . V_292 ,
V_149 ) )
return;
if ( F_141 ( V_149 , V_192 ) )
return;
if ( F_149 ( & V_192 -> args . V_16 , V_192 -> args . V_276 ,
V_192 -> args . V_293 , V_294 ) == - V_100 )
F_142 ( V_149 , - V_100 ) ;
}
static void F_150 ( struct V_148 * V_149 , void * V_29 )
{
struct V_191 * V_192 = V_29 ;
F_12 ( L_23 , V_20 , V_149 -> V_201 ) ;
if ( F_44 ( V_200 , & V_192 -> V_84 ) &&
V_149 -> V_201 == 0 ) {
F_151 ( V_149 , & V_192 -> V_273 . V_292 ) ;
return;
}
V_192 -> V_295 -> V_296 ( V_149 , V_192 ) ;
}
static void F_152 ( struct V_148 * V_149 , void * V_29 )
{
struct V_191 * V_192 = V_29 ;
F_139 ( V_149 , V_192 ) ;
F_153 ( V_149 ,
& F_154 ( V_192 -> V_2 ) -> V_297 [ V_298 ] ) ;
}
static void F_155 ( void * V_29 )
{
struct V_191 * V_192 = V_29 ;
F_139 ( & V_192 -> V_149 , V_192 ) ;
F_156 ( V_29 ) ;
}
static int F_157 ( struct V_148 * V_149 ,
struct V_191 * V_192 )
{
int V_11 ;
F_158 ( V_192 , V_149 -> V_201 ) ;
if ( V_149 -> V_201 < 0 )
F_127 ( V_192 -> V_78 , V_192 -> V_272 ,
V_192 -> args . V_59 , V_192 -> args . V_197 ,
V_192 -> V_273 . V_274 , V_299 ,
V_149 -> V_201 ) ;
V_11 = F_126 ( V_149 , V_192 -> args . V_276 -> V_203 ,
V_192 -> V_277 , V_192 -> V_78 ,
V_192 -> V_272 ) ;
switch ( V_11 ) {
case - V_246 :
F_101 ( V_192 , true ) ;
return V_149 -> V_201 ;
case - V_247 :
F_101 ( V_192 , false ) ;
return V_149 -> V_201 ;
case - V_248 :
return - V_248 ;
}
if ( V_192 -> V_273 . V_300 -> V_154 == V_301 ||
V_192 -> V_273 . V_300 -> V_154 == V_302 )
F_134 ( V_192 ) ;
V_192 -> V_303 . V_304 = 0 ;
if ( V_149 -> V_201 >= 0 )
F_159 ( V_192 ) ;
return 0 ;
}
static int F_160 ( struct V_148 * V_149 ,
struct V_305 * V_29 )
{
int V_11 ;
F_161 ( V_29 , V_149 -> V_201 ) ;
if ( V_149 -> V_201 < 0 )
F_127 ( V_29 -> V_78 , V_29 -> V_306 ,
V_29 -> args . V_59 , V_29 -> args . V_197 ,
V_29 -> V_273 . V_274 , V_307 ,
V_149 -> V_201 ) ;
V_11 = F_126 ( V_149 , NULL , V_29 -> V_277 ,
V_29 -> V_78 , V_29 -> V_306 ) ;
switch ( V_11 ) {
case - V_246 :
F_162 ( V_29 ) ;
return - V_248 ;
case - V_247 :
F_162 ( V_29 ) ;
return - V_248 ;
case - V_248 :
F_125 ( V_149 ) ;
return - V_248 ;
}
if ( V_29 -> V_300 . V_154 == V_155
&& F_133 ( V_29 -> V_78 ) )
F_135 ( V_29 -> V_2 , V_29 -> V_78 , V_29 -> V_308 ) ;
return 0 ;
}
static void F_163 ( struct V_148 * V_149 ,
struct V_191 * V_192 )
{
if ( F_104 ( V_285 , & V_192 -> V_84 ) )
return;
F_84 ( V_192 -> V_2 ,
F_94 ( V_192 -> V_78 , V_192 -> V_272 ) ,
V_192 -> args . V_197 ,
V_149 -> V_150 ) ;
}
static void F_164 ( struct V_148 * V_149 ,
struct V_191 * V_192 )
{
if ( ! F_140 ( V_285 , & V_192 -> V_84 ) )
return;
F_85 ( V_149 ,
F_94 ( V_192 -> V_78 , V_192 -> V_272 ) ,
V_192 -> args . V_197 , V_192 -> V_273 . V_197 ,
V_192 -> V_273 . V_300 -> V_154 ) ;
}
static int F_165 ( struct V_148 * V_149 ,
struct V_191 * V_192 )
{
if ( F_11 ( F_44 ( V_286 , & V_192 -> args . V_276 -> V_84 ) ) ) {
F_142 ( V_149 , - V_100 ) ;
return - V_100 ;
}
if ( F_136 ( V_192 -> V_78 , V_192 -> V_272 ) ) {
bool V_193 ;
V_193 = F_120 ( V_192 -> V_78 ) ;
F_12 ( L_24 , V_20 ,
V_149 -> V_194 , V_193 ? L_25 : L_26 ) ;
F_101 ( V_192 , V_193 ) ;
F_142 ( V_149 , 0 ) ;
return - V_248 ;
}
F_163 ( V_149 , V_192 ) ;
return 0 ;
}
static void F_166 ( struct V_148 * V_149 , void * V_29 )
{
struct V_191 * V_192 = V_29 ;
if ( F_165 ( V_149 , V_192 ) )
return;
F_144 ( V_149 ) ;
}
static void F_167 ( struct V_148 * V_149 , void * V_29 )
{
struct V_191 * V_192 = V_29 ;
if ( F_145 ( V_192 -> V_277 ,
& V_192 -> args . V_291 ,
& V_192 -> V_273 . V_292 ,
V_149 ) )
return;
if ( F_165 ( V_149 , V_192 ) )
return;
if ( F_149 ( & V_192 -> args . V_16 , V_192 -> args . V_276 ,
V_192 -> args . V_293 , V_309 ) == - V_100 )
F_142 ( V_149 , - V_100 ) ;
}
static void F_168 ( struct V_148 * V_149 , void * V_29 )
{
struct V_191 * V_192 = V_29 ;
if ( F_44 ( V_200 , & V_192 -> V_84 ) &&
V_149 -> V_201 == 0 ) {
F_151 ( V_149 , & V_192 -> V_273 . V_292 ) ;
return;
}
V_192 -> V_295 -> V_296 ( V_149 , V_192 ) ;
}
static void F_169 ( struct V_148 * V_149 , void * V_29 )
{
struct V_191 * V_192 = V_29 ;
F_164 ( V_149 , V_192 ) ;
F_153 ( V_149 ,
& F_154 ( V_192 -> V_2 ) -> V_297 [ V_310 ] ) ;
}
static void F_170 ( void * V_29 )
{
struct V_191 * V_192 = V_29 ;
F_164 ( & V_192 -> V_149 , V_192 ) ;
F_156 ( V_29 ) ;
}
static void F_171 ( struct V_148 * V_149 ,
struct V_305 * V_311 )
{
if ( F_104 ( V_285 , & V_311 -> V_84 ) )
return;
F_84 ( V_311 -> V_2 ,
F_94 ( V_311 -> V_78 , V_311 -> V_306 ) ,
0 , V_149 -> V_150 ) ;
}
static void F_172 ( struct V_148 * V_149 ,
struct V_305 * V_311 )
{
struct V_170 * V_171 ;
T_8 V_197 = 0 ;
if ( ! F_140 ( V_285 , & V_311 -> V_84 ) )
return;
if ( V_149 -> V_201 == 0 ) {
F_24 (req, &cdata->pages, wb_list)
V_197 += V_171 -> V_312 ;
}
F_85 ( V_149 ,
F_94 ( V_311 -> V_78 , V_311 -> V_306 ) ,
V_197 , V_197 , V_301 ) ;
}
static void F_173 ( struct V_148 * V_149 ,
struct V_305 * V_311 )
{
F_171 ( V_149 , V_311 ) ;
}
static void F_174 ( struct V_148 * V_149 , void * V_29 )
{
F_173 ( V_149 , V_29 ) ;
F_144 ( V_149 ) ;
}
static void F_175 ( struct V_148 * V_149 , void * V_29 )
{
struct V_305 * V_313 = V_29 ;
if ( F_145 ( V_313 -> V_277 ,
& V_313 -> args . V_291 ,
& V_313 -> V_273 . V_292 ,
V_149 ) )
return;
F_173 ( V_149 , V_29 ) ;
}
static void F_176 ( struct V_148 * V_149 , void * V_29 )
{
F_177 ( V_149 , V_29 ) ;
}
static void F_178 ( struct V_148 * V_149 , void * V_29 )
{
struct V_305 * V_311 = V_29 ;
F_172 ( V_149 , V_311 ) ;
F_153 ( V_149 ,
& F_154 ( V_311 -> V_2 ) -> V_297 [ V_314 ] ) ;
}
static void F_179 ( void * V_29 )
{
struct V_305 * V_311 = V_29 ;
F_172 ( & V_311 -> V_149 , V_311 ) ;
F_180 ( V_29 ) ;
}
static enum V_315
F_181 ( struct V_191 * V_192 )
{
struct V_69 * V_78 = V_192 -> V_78 ;
struct V_164 * V_159 ;
struct V_316 * V_317 ;
struct V_318 * V_319 ;
T_9 V_59 = V_192 -> args . V_59 ;
T_4 V_167 = V_192 -> V_272 ;
int V_259 ;
struct V_24 * V_25 ;
F_12 ( L_27 ,
V_20 , V_192 -> V_2 -> V_283 ,
V_192 -> args . V_320 , ( V_321 ) V_192 -> args . V_197 , V_59 ) ;
V_159 = F_89 ( V_78 , V_167 , false ) ;
if ( ! V_159 )
goto V_322;
V_317 = F_182 ( V_78 , V_167 , V_159 -> V_277 ,
V_192 -> V_2 ) ;
if ( F_92 ( V_317 ) )
goto V_322;
V_319 = F_183 ( V_78 , V_167 , V_192 -> V_50 ) ;
if ( F_92 ( V_319 ) )
goto V_322;
V_259 = F_184 ( V_78 , V_167 ) ;
F_12 ( L_28 , V_20 ,
V_159 -> V_323 , F_185 ( & V_159 -> V_277 -> V_324 ) , V_259 ) ;
F_186 ( & V_159 -> V_277 -> V_324 ) ;
V_192 -> V_277 = V_159 -> V_277 ;
V_25 = F_187 ( V_78 , V_167 ) ;
if ( V_25 )
V_192 -> args . V_25 = V_25 ;
V_192 -> args . V_59 = V_59 ;
V_192 -> V_282 = V_59 ;
F_188 ( V_317 , V_192 , V_319 , V_159 -> V_277 -> V_325 ,
V_259 == 3 ? & V_326 :
& V_327 ,
0 , V_328 ) ;
return V_329 ;
V_322:
if ( F_120 ( V_78 ) )
return V_330 ;
return V_331 ;
}
static enum V_315
F_189 ( struct V_191 * V_192 , int V_332 )
{
struct V_69 * V_78 = V_192 -> V_78 ;
struct V_164 * V_159 ;
struct V_316 * V_317 ;
struct V_318 * V_319 ;
T_9 V_59 = V_192 -> args . V_59 ;
int V_259 ;
struct V_24 * V_25 ;
int V_167 = V_192 -> V_272 ;
V_159 = F_89 ( V_78 , V_167 , true ) ;
if ( ! V_159 )
return V_331 ;
V_317 = F_182 ( V_78 , V_167 , V_159 -> V_277 ,
V_192 -> V_2 ) ;
if ( F_92 ( V_317 ) )
return V_331 ;
V_319 = F_183 ( V_78 , V_167 , V_192 -> V_50 ) ;
if ( F_92 ( V_319 ) )
return V_331 ;
V_259 = F_184 ( V_78 , V_167 ) ;
F_12 ( L_29 ,
V_20 , V_192 -> V_2 -> V_283 , V_332 , ( V_321 ) V_192 -> args . V_197 ,
V_59 , V_159 -> V_323 , F_185 ( & V_159 -> V_277 -> V_324 ) ,
V_259 ) ;
V_192 -> V_287 = F_157 ;
F_186 ( & V_159 -> V_277 -> V_324 ) ;
V_192 -> V_277 = V_159 -> V_277 ;
V_192 -> V_333 = V_167 ;
V_25 = F_187 ( V_78 , V_167 ) ;
if ( V_25 )
V_192 -> args . V_25 = V_25 ;
V_192 -> args . V_59 = V_59 ;
F_188 ( V_317 , V_192 , V_319 , V_159 -> V_277 -> V_325 ,
V_259 == 3 ? & V_334 :
& V_335 ,
V_332 , V_328 ) ;
return V_329 ;
}
static T_4 F_190 ( struct V_69 * V_78 , T_4 V_36 )
{
return V_36 ;
}
static struct V_24 *
F_191 ( struct V_69 * V_78 , T_4 V_36 )
{
struct V_51 * V_336 = F_66 ( V_78 ) ;
return & V_336 -> V_53 [ V_36 ] -> V_40 [ 0 ] ;
}
static int F_192 ( struct V_305 * V_29 , int V_337 )
{
struct V_69 * V_78 = V_29 -> V_78 ;
struct V_164 * V_159 ;
struct V_316 * V_317 ;
struct V_318 * V_319 ;
T_4 V_167 ;
int V_259 ;
struct V_24 * V_25 ;
V_167 = F_190 ( V_78 , V_29 -> V_306 ) ;
V_159 = F_89 ( V_78 , V_167 , true ) ;
if ( ! V_159 )
goto V_338;
V_317 = F_182 ( V_78 , V_167 , V_159 -> V_277 ,
V_29 -> V_2 ) ;
if ( F_92 ( V_317 ) )
goto V_338;
V_319 = F_183 ( V_78 , V_167 , V_29 -> V_50 ) ;
if ( F_92 ( V_319 ) )
goto V_338;
V_259 = F_184 ( V_78 , V_167 ) ;
F_12 ( L_30 , V_20 ,
V_29 -> V_2 -> V_283 , V_337 , F_185 ( & V_159 -> V_277 -> V_324 ) ,
V_259 ) ;
V_29 -> V_339 = F_160 ;
V_29 -> V_50 = V_319 ;
F_186 ( & V_159 -> V_277 -> V_324 ) ;
V_29 -> V_277 = V_159 -> V_277 ;
V_25 = F_191 ( V_78 , V_29 -> V_306 ) ;
if ( V_25 )
V_29 -> args . V_25 = V_25 ;
return F_193 ( V_317 , V_29 , V_159 -> V_277 -> V_325 ,
V_259 == 3 ? & V_340 :
& V_341 ,
V_337 , V_328 ) ;
V_338:
F_162 ( V_29 ) ;
F_180 ( V_29 ) ;
return - V_248 ;
}
static int
F_194 ( struct V_2 * V_2 , struct V_79 * V_342 ,
int V_337 , struct V_156 * V_157 )
{
return F_195 ( V_2 , V_342 , V_337 , V_157 ,
F_192 ) ;
}
static struct V_343 *
F_196 ( struct V_2 * V_2 )
{
struct V_1 * V_48 = F_116 ( V_2 ) -> V_48 ;
if ( V_48 == NULL )
return NULL ;
return & F_8 ( V_48 ) -> V_114 ;
}
static void
F_197 ( struct V_82 * V_344 )
{
F_198 ( F_199 ( V_344 , struct V_345 ,
V_86 ) ) ;
}
static int F_200 ( struct V_4 * V_346 ,
struct V_14 * V_15 ,
const struct V_347 * args )
{
struct V_1 * V_192 = & V_346 -> V_8 ;
T_3 * V_122 ;
int V_197 = 0 , V_57 = 0 ;
V_122 = F_201 ( V_15 , 4 ) ;
if ( F_11 ( ! V_122 ) )
return - V_348 ;
F_23 ( & V_192 -> V_44 -> V_45 ) ;
V_57 = F_202 ( V_346 , V_15 , & V_197 , & args -> V_58 ) ;
F_26 ( & V_192 -> V_44 -> V_45 ) ;
* V_122 = F_203 ( V_197 ) ;
return V_57 ;
}
static void F_204 ( struct V_4 * V_346 ,
struct V_14 * V_15 ,
const struct V_347 * args )
{
T_3 * V_17 ;
V_17 = F_201 ( V_15 , 4 ) ;
if ( F_205 ( V_17 ) )
* V_17 = F_203 ( 0 ) ;
}
static struct V_82 *
F_206 ( struct V_206 * V_349 ,
struct V_350 * V_351 , T_1 V_3 )
{
struct V_345 * V_352 ;
V_352 = F_207 ( V_349 , V_351 , V_3 ) ;
if ( ! V_352 )
return NULL ;
return & V_352 -> V_86 ;
}
static void
F_208 ( struct V_1 * V_9 ,
struct V_14 * V_15 ,
const struct V_347 * args )
{
struct V_4 * V_346 = F_8 ( V_9 ) ;
T_3 * V_122 ;
F_12 ( L_31 , V_20 ) ;
V_122 = F_201 ( V_15 , 4 ) ;
F_209 ( ! V_122 ) ;
F_200 ( V_346 , V_15 , args ) ;
F_204 ( V_346 , V_15 , args ) ;
* V_122 = F_203 ( ( V_15 -> V_17 - V_122 - 1 ) * 4 ) ;
F_12 ( L_32 , V_20 ) ;
}
static int
F_210 ( const struct V_353 * V_354 , char * V_91 , const V_321 V_355 )
{
const struct V_356 * sin = (struct V_356 * ) V_354 ;
return snprintf ( V_91 , V_355 , L_33 , & sin -> V_357 ) ;
}
static V_321
F_211 ( const struct V_353 * V_354 , char * V_91 ,
const int V_355 )
{
const struct V_358 * V_359 = (struct V_358 * ) V_354 ;
const struct V_360 * V_361 = & V_359 -> V_362 ;
if ( F_212 ( V_361 ) )
return snprintf ( V_91 , V_355 , L_34 ) ;
if ( F_213 ( V_361 ) )
return snprintf ( V_91 , V_355 , L_35 ) ;
if ( F_214 ( V_361 ) )
return snprintf ( V_91 , V_355 , L_36 ,
& V_361 -> V_363 [ 3 ] ) ;
return snprintf ( V_91 , V_355 , L_37 , V_361 ) ;
}
static void
F_215 ( struct V_14 * V_15 , struct V_364 * V_365 )
{
struct V_353 * V_354 = (struct V_353 * ) & V_365 -> V_366 ;
char V_367 [ V_368 ] ;
char V_369 [ V_370 ] ;
char * V_371 ;
unsigned short V_372 ;
int V_31 , V_373 ;
T_3 * V_17 ;
switch ( V_354 -> V_374 ) {
case V_375 :
if ( F_210 ( V_354 , V_369 , sizeof( V_369 ) ) == 0 )
return;
V_372 = F_216 ( ( (struct V_356 * ) V_354 ) -> V_376 ) ;
V_371 = L_38 ;
V_373 = 3 ;
break;
case V_377 :
if ( F_211 ( V_354 , V_369 , sizeof( V_369 ) ) == 0 )
return;
V_372 = F_216 ( ( (struct V_358 * ) V_354 ) -> V_378 ) ;
V_371 = L_39 ;
V_373 = 4 ;
break;
default:
F_72 ( 1 ) ;
return;
}
snprintf ( V_367 , sizeof( V_367 ) , L_40 , V_372 >> 8 , V_372 & 0xff ) ;
V_31 = F_217 ( V_369 , V_367 , sizeof( V_369 ) ) ;
V_17 = F_201 ( V_15 , 4 + V_373 ) ;
F_218 ( V_17 , V_371 , V_373 ) ;
V_17 = F_201 ( V_15 , 4 + V_31 ) ;
F_218 ( V_17 , V_369 , V_31 ) ;
}
static void
F_219 ( struct V_14 * V_15 ,
T_6 V_379 )
{
struct V_380 V_381 ;
T_3 * V_17 ;
V_17 = F_201 ( V_15 , 12 ) ;
V_381 = F_220 ( V_379 ) ;
V_17 = F_221 ( V_17 , V_381 . V_382 ) ;
* V_17 ++ = F_203 ( V_381 . V_383 ) ;
}
static void
F_222 ( struct V_14 * V_15 ,
struct V_131 * V_384 )
{
T_3 * V_17 ;
V_17 = F_201 ( V_15 , 5 * 8 ) ;
V_17 = F_221 ( V_17 , V_384 -> V_134 ) ;
V_17 = F_221 ( V_17 , V_384 -> V_135 ) ;
V_17 = F_221 ( V_17 , V_384 -> V_140 ) ;
V_17 = F_221 ( V_17 , V_384 -> V_141 ) ;
V_17 = F_221 ( V_17 , V_384 -> V_142 ) ;
F_219 ( V_15 , V_384 -> V_143 ) ;
F_219 ( V_15 , V_384 -> V_144 ) ;
}
static void
F_223 ( struct V_14 * V_15 ,
struct V_385 * args ,
struct V_386 * V_387 )
{
struct V_33 * V_41 = V_387 -> V_388 ;
struct V_364 * V_365 ;
struct V_164 * V_159 = V_41 -> V_46 -> V_159 ;
struct V_24 * V_25 = & V_41 -> V_40 [ 0 ] ;
T_3 * V_17 , * V_122 ;
V_365 = F_224 ( & V_159 -> V_389 , struct V_364 , V_390 ) ;
F_12 ( L_41 ,
V_20 , V_159 -> V_323 , V_365 -> V_391 ) ;
V_122 = F_201 ( V_15 , 4 ) ;
F_215 ( V_15 , V_365 ) ;
V_17 = F_201 ( V_15 , 4 + V_25 -> V_26 ) ;
F_218 ( V_17 , V_25 -> V_29 , V_25 -> V_26 ) ;
F_23 ( & V_41 -> V_49 ) ;
F_222 ( V_15 , & V_41 -> V_146 . V_133 ) ;
F_222 ( V_15 , & V_41 -> V_151 . V_133 ) ;
F_26 ( & V_41 -> V_49 ) ;
F_219 ( V_15 , F_73 ( F_83 () , V_41 -> V_121 ) ) ;
V_17 = F_201 ( V_15 , 4 ) ;
* V_17 = F_203 ( false ) ;
* V_122 = F_203 ( ( V_15 -> V_17 - V_122 - 1 ) * 4 ) ;
}
static int
F_225 ( struct V_385 * args ,
struct V_1 * V_9 ,
int V_392 )
{
struct V_4 * V_42 = F_8 ( V_9 ) ;
struct V_33 * V_41 ;
struct V_82 * V_393 ;
struct V_386 * V_387 ;
int V_36 = 0 ;
F_24 (mirror, &ff_layout->mirrors, mirrors) {
if ( V_36 >= V_392 )
break;
if ( ! V_41 -> V_46 )
continue;
if ( ! F_25 ( & V_41 -> V_47 ) )
continue;
V_393 = & V_41 -> V_46 -> V_86 ;
V_387 = & args -> V_387 [ V_36 ] ;
memcpy ( & V_387 -> V_394 , & V_393 -> V_395 , V_23 ) ;
V_387 -> V_59 = 0 ;
V_387 -> V_60 = V_61 ;
V_387 -> V_396 = V_41 -> V_146 . V_133 . V_140 ;
V_387 -> V_397 = V_41 -> V_146 . V_133 . V_141 ;
V_387 -> V_398 = V_41 -> V_151 . V_133 . V_140 ;
V_387 -> V_399 = V_41 -> V_151 . V_133 . V_141 ;
V_387 -> V_400 = V_401 ;
V_387 -> V_402 = F_223 ;
V_387 -> V_388 = V_41 ;
V_36 ++ ;
}
return V_36 ;
}
static int
F_226 ( struct V_385 * args )
{
struct V_4 * V_42 ;
struct V_33 * V_41 ;
int V_403 = 0 ;
F_23 ( & args -> V_2 -> V_45 ) ;
V_42 = F_8 ( F_116 ( args -> V_2 ) -> V_48 ) ;
F_24 (mirror, &ff_layout->mirrors, mirrors) {
if ( F_185 ( & V_41 -> V_47 ) != 0 )
V_403 ++ ;
}
F_26 ( & args -> V_2 -> V_45 ) ;
if ( V_403 > V_404 ) {
F_12 ( L_42 ,
V_20 , V_403 , V_404 ) ;
V_403 = V_404 ;
}
args -> V_387 = F_227 ( V_403 , sizeof( * args -> V_387 ) , V_152 ) ;
if ( ! args -> V_387 )
return - V_96 ;
F_23 ( & args -> V_2 -> V_45 ) ;
args -> V_405 = F_225 ( args ,
& V_42 -> V_8 , V_403 ) ;
F_26 ( & args -> V_2 -> V_45 ) ;
return 0 ;
}
static void
F_228 ( struct V_406 * V_29 )
{
struct V_33 * V_41 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_29 -> args . V_405 ; V_36 ++ ) {
V_41 = V_29 -> args . V_387 [ V_36 ] . V_388 ;
V_29 -> args . V_387 [ V_36 ] . V_388 = NULL ;
F_35 ( V_41 ) ;
}
}
static int T_10 F_229 ( void )
{
F_17 ( V_407 L_43 ,
V_20 ) ;
return F_230 ( & V_408 ) ;
}
static void T_11 F_231 ( void )
{
F_17 ( V_407 L_44 ,
V_20 ) ;
F_232 ( & V_408 ) ;
}
