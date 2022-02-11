static struct V_1 *
F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_3 ) ;
if ( V_5 ) {
F_3 ( & V_5 -> V_6 ) ;
F_3 ( & V_5 -> V_7 ) ;
V_5 -> V_8 = F_4 () ;
return & V_5 -> V_9 ;
} else
return NULL ;
}
static void
F_5 ( struct V_1 * V_10 )
{
struct V_11 * V_12 , * V_13 ;
F_6 (err, n, &FF_LAYOUT_FROM_HDR(lo)->error_list,
list) {
F_7 ( & V_12 -> V_14 ) ;
F_8 ( V_12 ) ;
}
F_8 ( F_9 ( V_10 ) ) ;
}
static int F_10 ( struct V_15 * V_16 , T_2 * V_17 )
{
T_3 * V_18 ;
V_18 = F_11 ( V_16 , V_19 ) ;
if ( F_12 ( V_18 == NULL ) )
return - V_20 ;
V_17 -> type = V_21 ;
memcpy ( V_17 -> V_22 , V_18 , V_19 ) ;
F_13 ( L_1 , V_23 ,
V_18 [ 0 ] , V_18 [ 1 ] , V_18 [ 2 ] , V_18 [ 3 ] ) ;
return 0 ;
}
static int F_14 ( struct V_15 * V_16 , struct V_24 * V_25 )
{
T_3 * V_18 ;
V_18 = F_11 ( V_16 , V_26 ) ;
if ( F_12 ( ! V_18 ) )
return - V_20 ;
memcpy ( V_25 , V_18 , V_26 ) ;
F_15 ( V_25 ) ;
return 0 ;
}
static int F_16 ( struct V_15 * V_16 , struct V_27 * V_28 )
{
T_3 * V_18 ;
V_18 = F_11 ( V_16 , 4 ) ;
if ( F_12 ( ! V_18 ) )
return - V_20 ;
V_28 -> V_29 = F_17 ( V_18 ++ ) ;
if ( V_28 -> V_29 > sizeof( struct V_27 ) ) {
F_18 ( V_30 L_2 ,
V_28 -> V_29 ) ;
return - V_31 ;
}
V_18 = F_11 ( V_16 , V_28 -> V_29 ) ;
if ( F_12 ( ! V_18 ) )
return - V_20 ;
memcpy ( & V_28 -> V_22 , V_18 , V_28 -> V_29 ) ;
F_13 ( L_3 , V_23 , V_28 -> V_29 ) ;
return 0 ;
}
static int
F_19 ( struct V_15 * V_16 , T_4 * V_32 )
{
T_3 * V_18 ;
int V_33 ;
V_18 = F_11 ( V_16 , 4 ) ;
if ( F_12 ( ! V_18 ) )
return - V_20 ;
V_33 = F_17 ( V_18 ++ ) ;
if ( V_33 < 0 )
return - V_34 ;
F_13 ( L_4 , V_23 , V_33 ) ;
V_18 = F_11 ( V_16 , V_33 ) ;
if ( F_12 ( ! V_18 ) )
return - V_20 ;
if ( ! F_20 ( ( char * ) V_18 , V_33 , V_32 ) )
return - V_34 ;
return 0 ;
}
static bool F_21 ( const struct V_35 * V_36 ,
const struct V_35 * V_37 )
{
int V_38 , V_39 ;
if ( V_36 -> V_40 != V_37 -> V_40 )
return false ;
for ( V_38 = 0 ; V_38 < V_36 -> V_40 ; V_38 ++ ) {
bool V_41 = false ;
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ ) {
if ( F_22 ( & V_36 -> V_42 [ V_38 ] ,
& V_37 -> V_42 [ V_39 ] ) == 0 ) {
V_41 = true ;
break;
}
}
if ( ! V_41 )
return false ;
}
return true ;
}
static struct V_35 *
F_23 ( struct V_1 * V_10 ,
struct V_35 * V_43 )
{
struct V_4 * V_44 = F_9 ( V_10 ) ;
struct V_35 * V_45 ;
struct V_2 * V_2 = V_10 -> V_46 ;
F_24 ( & V_2 -> V_47 ) ;
F_25 (pos, &ff_layout->mirrors, mirrors) {
if ( V_43 -> V_48 != V_45 -> V_48 )
continue;
if ( ! F_21 ( V_43 , V_45 ) )
continue;
if ( F_26 ( & V_45 -> V_49 ) ) {
F_27 ( & V_2 -> V_47 ) ;
return V_45 ;
}
}
F_28 ( & V_43 -> V_7 , & V_44 -> V_7 ) ;
V_43 -> V_50 = V_10 ;
F_27 ( & V_2 -> V_47 ) ;
return V_43 ;
}
static void
F_29 ( struct V_35 * V_43 )
{
struct V_2 * V_2 ;
if ( V_43 -> V_50 == NULL )
return;
V_2 = V_43 -> V_50 -> V_46 ;
F_24 ( & V_2 -> V_47 ) ;
F_7 ( & V_43 -> V_7 ) ;
F_27 ( & V_2 -> V_47 ) ;
V_43 -> V_50 = NULL ;
}
static struct V_35 * F_30 ( T_1 V_3 )
{
struct V_35 * V_43 ;
V_43 = F_2 ( sizeof( * V_43 ) , V_3 ) ;
if ( V_43 != NULL ) {
F_31 ( & V_43 -> V_51 ) ;
F_32 ( & V_43 -> V_49 , 1 ) ;
F_3 ( & V_43 -> V_7 ) ;
}
return V_43 ;
}
static void F_33 ( struct V_35 * V_43 )
{
struct V_52 * V_53 ;
F_29 ( V_43 ) ;
F_8 ( V_43 -> V_42 ) ;
V_53 = F_34 ( V_43 -> V_54 ) ;
if ( V_53 )
F_35 ( V_53 ) ;
V_53 = F_34 ( V_43 -> V_55 ) ;
if ( V_53 )
F_35 ( V_53 ) ;
F_36 ( V_43 -> V_48 ) ;
F_8 ( V_43 ) ;
}
static void F_37 ( struct V_35 * V_43 )
{
if ( V_43 != NULL && F_38 ( & V_43 -> V_49 ) )
F_33 ( V_43 ) ;
}
static void F_39 ( struct V_56 * V_57 )
{
int V_38 ;
if ( V_57 -> V_58 ) {
for ( V_38 = 0 ; V_38 < V_57 -> V_59 ; V_38 ++ ) {
F_37 ( V_57 -> V_58 [ V_38 ] ) ;
}
F_8 ( V_57 -> V_58 ) ;
V_57 -> V_58 = NULL ;
}
}
static int F_40 ( struct V_60 * V_61 )
{
int V_62 = 0 ;
F_13 ( L_5 , V_23 ) ;
if ( V_61 -> V_63 . V_64 != 0 ||
V_61 -> V_63 . V_65 != V_66 ) {
F_13 ( L_6 ,
V_23 ) ;
V_62 = - V_34 ;
}
F_13 ( L_7 , V_23 , V_62 ) ;
return V_62 ;
}
static void F_41 ( struct V_56 * V_57 )
{
if ( V_57 ) {
F_39 ( V_57 ) ;
F_8 ( V_57 ) ;
}
}
static bool
F_42 ( const struct V_67 * V_68 ,
const struct V_67 * V_69 )
{
T_5 V_70 , V_71 ;
if ( V_68 -> V_72 != V_69 -> V_72 )
return V_68 -> V_72 != V_73 ;
V_70 = F_43 ( V_68 -> V_64 , V_68 -> V_65 ) ;
V_71 = F_43 ( V_69 -> V_64 , V_69 -> V_65 ) ;
if ( V_70 < V_69 -> V_64 )
return false ;
if ( V_71 < V_68 -> V_64 )
return true ;
return V_69 -> V_64 <= V_68 -> V_64 ;
}
static bool
F_44 ( struct V_74 * V_75 ,
struct V_74 * V_76 )
{
T_5 V_77 , V_78 ;
if ( F_45 ( V_79 , & V_76 -> V_80 ) )
return false ;
if ( V_75 -> V_81 . V_72 != V_76 -> V_81 . V_72 )
return false ;
V_78 = F_43 ( V_76 -> V_81 . V_64 ,
V_76 -> V_81 . V_65 ) ;
if ( V_78 < V_75 -> V_81 . V_64 )
return false ;
V_77 = F_43 ( V_75 -> V_81 . V_64 ,
V_75 -> V_81 . V_65 ) ;
if ( V_77 < V_76 -> V_81 . V_64 )
return false ;
if ( V_77 < V_78 )
V_77 = V_78 ;
if ( V_75 -> V_81 . V_64 < V_76 -> V_81 . V_64 )
V_75 -> V_81 . V_64 = V_76 -> V_81 . V_64 ;
V_75 -> V_81 . V_65 = F_46 ( V_75 -> V_81 . V_64 ,
V_77 ) ;
if ( F_45 ( V_82 , & V_76 -> V_80 ) )
F_47 ( V_82 , & V_75 -> V_80 ) ;
return true ;
}
static void
F_48 ( struct V_1 * V_10 ,
struct V_74 * V_83 ,
struct V_84 * V_85 )
{
F_49 ( V_10 , V_83 ,
F_42 ,
F_44 ,
V_85 ) ;
}
static void F_50 ( struct V_56 * V_57 )
{
int V_38 , V_39 ;
for ( V_38 = 0 ; V_38 < V_57 -> V_59 - 1 ; V_38 ++ ) {
for ( V_39 = V_38 + 1 ; V_39 < V_57 -> V_59 ; V_39 ++ )
if ( V_57 -> V_58 [ V_38 ] -> V_86 <
V_57 -> V_58 [ V_39 ] -> V_86 )
F_51 ( V_57 -> V_58 [ V_38 ] ,
V_57 -> V_58 [ V_39 ] ) ;
}
}
static void F_52 ( struct V_56 * V_57 )
{
struct V_87 * V_88 ;
int V_38 ;
if ( ! ( V_57 -> V_89 & V_90 ) )
return;
for ( V_38 = 0 ; V_38 < V_57 -> V_59 ; V_38 ++ ) {
V_88 = & V_57 -> V_58 [ V_38 ] -> V_48 -> V_91 ;
F_53 ( V_92 , & V_88 -> V_89 ) ;
}
}
static struct V_74 *
F_54 ( struct V_1 * V_93 ,
struct V_60 * V_61 ,
T_1 V_3 )
{
struct V_74 * V_62 ;
struct V_56 * V_57 = NULL ;
struct V_15 V_94 ;
struct V_95 V_96 ;
struct V_97 * V_98 ;
T_5 V_99 ;
T_4 V_59 ;
T_3 * V_18 ;
int V_38 , V_100 ;
F_13 ( L_5 , V_23 ) ;
V_98 = F_55 ( V_3 ) ;
if ( ! V_98 )
return F_56 ( - V_101 ) ;
F_57 ( & V_94 , & V_96 , V_61 -> V_102 -> V_103 ,
V_61 -> V_102 -> V_33 ) ;
F_58 ( & V_94 , F_59 ( V_98 ) , V_104 ) ;
V_100 = - V_105 ;
V_18 = F_11 ( & V_94 , 8 + 4 ) ;
if ( ! V_18 )
goto V_106;
V_18 = F_60 ( V_18 , & V_99 ) ;
V_59 = F_17 ( V_18 ++ ) ;
F_13 ( L_8 , V_23 ,
V_99 , V_59 ) ;
if ( V_59 > V_107 ||
V_59 == 0 )
goto V_106;
V_100 = - V_101 ;
V_57 = F_2 ( sizeof( * V_57 ) , V_3 ) ;
if ( ! V_57 )
goto V_106;
V_57 -> V_59 = V_59 ;
V_57 -> V_99 = V_99 ;
V_57 -> V_58 = F_61 ( V_57 -> V_59 ,
sizeof( V_57 -> V_58 [ 0 ] ) , V_3 ) ;
if ( V_57 -> V_58 == NULL )
goto V_106;
for ( V_38 = 0 ; V_38 < V_57 -> V_59 ; V_38 ++ ) {
struct V_35 * V_43 ;
struct V_24 V_25 ;
struct V_87 * V_108 ;
struct V_109 V_110 = { . V_111 = V_112 } ;
struct V_52 T_6 * V_53 ;
T_4 V_113 , V_114 , V_32 ;
int V_39 ;
V_100 = - V_105 ;
V_18 = F_11 ( & V_94 , 4 ) ;
if ( ! V_18 )
goto V_106;
V_113 = F_17 ( V_18 ) ;
if ( V_113 != 1 )
goto V_106;
V_57 -> V_58 [ V_38 ] = F_30 ( V_3 ) ;
if ( V_57 -> V_58 [ V_38 ] == NULL ) {
V_100 = - V_101 ;
goto V_106;
}
V_57 -> V_58 [ V_38 ] -> V_113 = V_113 ;
V_100 = F_14 ( & V_94 , & V_25 ) ;
if ( V_100 )
goto V_106;
V_108 = F_62 ( F_63 ( V_93 -> V_46 ) ,
& V_25 , V_93 -> V_115 ,
V_3 ) ;
if ( V_108 )
V_57 -> V_58 [ V_38 ] -> V_48 =
F_64 ( V_108 ) ;
else
goto V_106;
V_100 = - V_105 ;
V_18 = F_11 ( & V_94 , 4 ) ;
if ( ! V_18 )
goto V_106;
V_57 -> V_58 [ V_38 ] -> V_86 = F_17 ( V_18 ) ;
V_100 = F_10 ( & V_94 , & V_57 -> V_58 [ V_38 ] -> V_17 ) ;
if ( V_100 )
goto V_106;
V_18 = F_11 ( & V_94 , 4 ) ;
if ( ! V_18 )
goto V_106;
V_114 = F_17 ( V_18 ) ;
V_57 -> V_58 [ V_38 ] -> V_42 =
F_2 ( V_114 * sizeof( struct V_27 ) ,
V_3 ) ;
if ( V_57 -> V_58 [ V_38 ] -> V_42 == NULL ) {
V_100 = - V_101 ;
goto V_106;
}
for ( V_39 = 0 ; V_39 < V_114 ; V_39 ++ ) {
V_100 = F_16 ( & V_94 ,
& V_57 -> V_58 [ V_38 ] -> V_42 [ V_39 ] ) ;
if ( V_100 )
goto V_106;
}
V_57 -> V_58 [ V_38 ] -> V_40 = V_114 ;
V_100 = F_19 ( & V_94 , & V_32 ) ;
if ( V_100 )
goto V_106;
V_110 . V_116 = F_65 ( & V_117 , V_32 ) ;
V_100 = F_19 ( & V_94 , & V_32 ) ;
if ( V_100 )
goto V_106;
V_110 . V_118 = F_66 ( & V_117 , V_32 ) ;
F_67 ( V_53 , F_68 ( & V_110 , 0 , V_3 ) ) ;
if ( F_69 ( V_53 ) ) {
V_100 = F_70 ( V_53 ) ;
goto V_106;
}
if ( V_61 -> V_63 . V_72 == V_73 )
F_67 ( V_57 -> V_58 [ V_38 ] -> V_54 , V_53 ) ;
else
F_67 ( V_57 -> V_58 [ V_38 ] -> V_55 , V_53 ) ;
V_43 = F_23 ( V_93 , V_57 -> V_58 [ V_38 ] ) ;
if ( V_43 != V_57 -> V_58 [ V_38 ] ) {
if ( V_61 -> V_63 . V_72 == V_73 ) {
V_53 = F_71 ( & V_43 -> V_54 , V_53 ) ;
F_67 ( V_57 -> V_58 [ V_38 ] -> V_54 , V_53 ) ;
} else {
V_53 = F_71 ( & V_43 -> V_55 , V_53 ) ;
F_67 ( V_57 -> V_58 [ V_38 ] -> V_55 , V_53 ) ;
}
F_33 ( V_57 -> V_58 [ V_38 ] ) ;
V_57 -> V_58 [ V_38 ] = V_43 ;
}
F_13 ( L_9 , V_23 ,
V_61 -> V_63 . V_72 == V_73 ? L_10 : L_11 ,
F_72 ( & V_117 , V_110 . V_116 ) ,
F_73 ( & V_117 , V_110 . V_118 ) ) ;
}
V_18 = F_11 ( & V_94 , 4 ) ;
if ( ! V_18 )
goto V_119;
V_57 -> V_89 = F_17 ( V_18 ) ;
V_18 = F_11 ( & V_94 , 4 ) ;
if ( ! V_18 )
goto V_119;
for ( V_38 = 0 ; V_38 < V_57 -> V_59 ; V_38 ++ )
V_57 -> V_58 [ V_38 ] -> V_120 = F_17 ( V_18 ) ;
V_119:
F_50 ( V_57 ) ;
V_100 = F_40 ( V_61 ) ;
if ( V_100 )
goto V_106;
F_52 ( V_57 ) ;
V_62 = & V_57 -> V_9 ;
F_13 ( L_12 , V_23 ) ;
V_121:
F_74 ( V_98 ) ;
return V_62 ;
V_106:
F_41 ( V_57 ) ;
V_62 = F_56 ( V_100 ) ;
F_13 ( L_13 , V_23 , V_100 ) ;
goto V_121;
}
static bool F_75 ( struct V_1 * V_50 )
{
struct V_74 * V_83 ;
F_25 (lseg, &layout->plh_segs, pls_list)
if ( V_83 -> V_81 . V_72 == V_122 )
return true ;
return false ;
}
static void
F_76 ( struct V_74 * V_83 )
{
struct V_56 * V_57 = F_77 ( V_83 ) ;
F_13 ( L_5 , V_23 ) ;
if ( V_83 -> V_81 . V_72 == V_122 ) {
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_5 = F_9 ( V_83 -> V_123 ) ;
V_2 = V_5 -> V_9 . V_46 ;
F_24 ( & V_2 -> V_47 ) ;
if ( ! F_75 ( V_83 -> V_123 ) ) {
V_5 -> V_124 . V_125 = 0 ;
F_8 ( V_5 -> V_124 . V_126 ) ;
V_5 -> V_124 . V_126 = NULL ;
}
F_27 ( & V_2 -> V_47 ) ;
}
F_41 ( V_57 ) ;
}
static int
F_78 ( struct V_56 * V_57 )
{
return 1 ;
}
static void
F_79 ( struct V_127 * V_128 , T_7 V_129 )
{
if ( F_80 ( & V_128 -> V_130 ) == 1 ) {
V_128 -> V_131 = V_129 ;
}
}
static T_7
F_81 ( struct V_127 * V_128 , T_7 V_129 )
{
T_7 V_132 ;
if ( F_82 ( & V_128 -> V_130 ) < 0 )
F_83 ( 1 ) ;
V_132 = V_128 -> V_131 ;
V_128 -> V_131 = V_129 ;
return F_84 ( V_129 , V_132 ) ;
}
static bool
F_85 ( struct V_35 * V_43 ,
struct V_133 * V_134 ,
T_7 V_129 )
{
static const T_7 V_135 = { 0 } ;
T_8 V_120 = V_136 ;
struct V_4 * V_5 = F_9 ( V_43 -> V_50 ) ;
F_79 ( & V_134 -> V_137 , V_129 ) ;
if ( F_86 ( V_43 -> V_131 , V_135 ) )
V_43 -> V_131 = V_129 ;
if ( V_43 -> V_120 != 0 )
V_120 = ( T_8 ) V_43 -> V_120 * 1000LL ;
else if ( V_138 != 0 )
V_120 = ( T_8 ) V_138 * 1000LL ;
if ( F_87 ( F_84 ( V_129 , V_5 -> V_8 ) ) >=
V_120 ) {
V_5 -> V_8 = V_129 ;
return true ;
}
return false ;
}
static void
F_88 ( struct V_133 * V_134 ,
T_9 V_139 )
{
struct V_140 * V_141 = & V_134 -> V_142 ;
V_141 -> V_143 ++ ;
V_141 -> V_144 += V_139 ;
}
static void
F_89 ( struct V_133 * V_134 ,
T_9 V_139 ,
T_9 V_145 ,
T_7 V_146 ,
T_7 V_147 )
{
struct V_140 * V_141 = & V_134 -> V_142 ;
T_7 V_148 = F_84 ( V_146 , V_147 ) ;
T_7 V_128 ;
V_141 -> V_149 ++ ;
V_141 -> V_150 += V_145 ;
V_141 -> V_151 += V_139 - V_145 ;
V_128 = F_81 ( & V_134 -> V_137 , V_146 ) ;
V_141 -> V_152 =
F_90 ( V_141 -> V_152 , V_128 ) ;
V_141 -> V_153 =
F_90 ( V_141 -> V_153 ,
V_148 ) ;
}
static void
F_91 ( struct V_2 * V_2 ,
struct V_35 * V_43 ,
T_9 V_139 , T_7 V_129 )
{
bool V_154 ;
F_24 ( & V_43 -> V_51 ) ;
V_154 = F_85 ( V_43 , & V_43 -> V_155 , V_129 ) ;
F_88 ( & V_43 -> V_155 , V_139 ) ;
F_27 ( & V_43 -> V_51 ) ;
if ( V_154 )
F_92 ( V_2 , V_156 ) ;
}
static void
F_93 ( struct V_157 * V_158 ,
struct V_35 * V_43 ,
T_9 V_139 ,
T_9 V_145 )
{
F_24 ( & V_43 -> V_51 ) ;
F_89 ( & V_43 -> V_155 ,
V_139 , V_145 ,
F_4 () , V_158 -> V_159 ) ;
F_27 ( & V_43 -> V_51 ) ;
}
static void
F_94 ( struct V_2 * V_2 ,
struct V_35 * V_43 ,
T_9 V_139 , T_7 V_129 )
{
bool V_154 ;
F_24 ( & V_43 -> V_51 ) ;
V_154 = F_85 ( V_43 , & V_43 -> V_160 , V_129 ) ;
F_88 ( & V_43 -> V_160 , V_139 ) ;
F_27 ( & V_43 -> V_51 ) ;
if ( V_154 )
F_92 ( V_2 , V_161 ) ;
}
static void
F_95 ( struct V_157 * V_158 ,
struct V_35 * V_43 ,
T_9 V_139 ,
T_9 V_145 ,
enum V_162 V_163 )
{
if ( V_163 == V_164 )
V_139 = V_145 = 0 ;
F_24 ( & V_43 -> V_51 ) ;
F_89 ( & V_43 -> V_160 ,
V_139 , V_145 , F_4 () , V_158 -> V_159 ) ;
F_27 ( & V_43 -> V_51 ) ;
}
static int
F_96 ( struct V_74 * V_83 ,
struct V_165 * V_166 ,
T_1 V_3 )
{
struct V_56 * V_57 = F_77 ( V_83 ) ;
struct V_167 * V_126 ;
int V_29 ;
if ( V_166 -> V_168 -> V_125 != 0 ) {
return 0 ;
}
V_29 = F_78 ( V_57 ) * F_97 ( V_83 ) ;
V_126 = F_61 ( V_29 , sizeof( struct V_167 ) ,
V_3 ) ;
if ( ! V_126 )
return - V_101 ;
else {
int V_38 ;
F_24 ( & V_166 -> V_2 -> V_47 ) ;
if ( V_166 -> V_168 -> V_125 != 0 )
F_8 ( V_126 ) ;
else {
V_166 -> V_168 -> V_126 = V_126 ;
V_166 -> V_168 -> V_125 = V_29 ;
for ( V_38 = 0 ; V_38 < V_29 ; V_38 ++ ) {
F_3 ( & V_126 [ V_38 ] . V_169 ) ;
F_3 ( & V_126 [ V_38 ] . V_170 ) ;
V_126 [ V_38 ] . V_171 . V_163 =
V_172 ;
}
}
F_27 ( & V_166 -> V_2 -> V_47 ) ;
return 0 ;
}
}
static struct V_173 *
F_98 ( struct V_74 * V_83 ,
int V_174 ,
int * V_175 )
{
struct V_56 * V_57 = F_77 ( V_83 ) ;
struct V_173 * V_168 ;
bool V_176 = false ;
int V_177 ;
for ( V_177 = V_174 ; V_177 < V_57 -> V_59 ; V_177 ++ ) {
if ( V_177 + 1 == V_57 -> V_59 )
V_176 = true ;
V_168 = F_99 ( V_83 , V_177 , V_176 ) ;
if ( V_168 ) {
* V_175 = V_177 ;
return V_168 ;
}
}
return NULL ;
}
static void
F_100 ( struct V_178 * V_179 ,
struct V_180 * V_181 ,
bool V_182 )
{
V_183:
F_101 ( V_179 -> V_184 ) ;
V_179 -> V_184 = F_102 ( V_179 -> V_185 ,
V_181 -> V_186 ,
0 ,
V_66 ,
V_73 ,
V_182 ,
V_156 ) ;
if ( F_69 ( V_179 -> V_184 ) ) {
V_179 -> V_187 = F_70 ( V_179 -> V_184 ) ;
V_179 -> V_184 = NULL ;
}
if ( V_179 -> V_184 && ! V_182 &&
F_103 ( V_179 -> V_184 ) ) {
V_182 = true ;
goto V_183;
}
}
static void
F_104 ( struct V_178 * V_179 ,
struct V_180 * V_181 )
{
struct V_188 * V_189 ;
struct V_35 * V_43 ;
struct V_173 * V_168 ;
int V_190 ;
V_191:
if ( ! V_179 -> V_184 )
F_100 ( V_179 , V_181 , false ) ;
else if ( F_103 ( V_179 -> V_184 ) )
F_100 ( V_179 , V_181 , true ) ;
if ( V_179 -> V_184 == NULL )
goto V_192;
V_168 = F_98 ( V_179 -> V_184 , 0 , & V_190 ) ;
if ( ! V_168 ) {
if ( ! F_105 ( V_179 -> V_184 ) )
goto V_192;
F_101 ( V_179 -> V_184 ) ;
V_179 -> V_184 = NULL ;
F_106 ( 1 ) ;
goto V_191;
}
V_43 = F_107 ( V_179 -> V_184 , V_190 ) ;
V_179 -> V_193 = V_190 ;
V_189 = & V_179 -> V_194 [ 0 ] ;
V_189 -> V_195 = V_43 -> V_48 -> V_196 [ 0 ] . V_197 ;
return;
V_192:
F_101 ( V_179 -> V_184 ) ;
V_179 -> V_184 = NULL ;
F_108 ( V_179 ) ;
}
static void
F_109 ( struct V_178 * V_179 ,
struct V_180 * V_181 )
{
struct V_35 * V_43 ;
struct V_188 * V_189 ;
struct V_165 V_166 ;
struct V_173 * V_168 ;
int V_38 ;
int V_198 ;
V_191:
if ( ! V_179 -> V_184 ) {
V_179 -> V_184 = F_102 ( V_179 -> V_185 ,
V_181 -> V_186 ,
0 ,
V_66 ,
V_122 ,
false ,
V_199 ) ;
if ( F_69 ( V_179 -> V_184 ) ) {
V_179 -> V_187 = F_70 ( V_179 -> V_184 ) ;
V_179 -> V_184 = NULL ;
return;
}
}
if ( V_179 -> V_184 == NULL )
goto V_192;
F_110 ( & V_166 , V_179 -> V_185 , V_179 -> V_200 ) ;
V_198 = F_96 ( V_179 -> V_184 , & V_166 , V_199 ) ;
if ( V_198 < 0 )
goto V_192;
if ( F_83 ( V_179 -> V_201 !=
F_97 ( V_179 -> V_184 ) ) )
goto V_192;
for ( V_38 = 0 ; V_38 < V_179 -> V_201 ; V_38 ++ ) {
V_168 = F_99 ( V_179 -> V_184 , V_38 , true ) ;
if ( ! V_168 ) {
if ( ! F_105 ( V_179 -> V_184 ) )
goto V_192;
F_101 ( V_179 -> V_184 ) ;
V_179 -> V_184 = NULL ;
F_106 ( 1 ) ;
goto V_191;
}
V_189 = & V_179 -> V_194 [ V_38 ] ;
V_43 = F_107 ( V_179 -> V_184 , V_38 ) ;
V_189 -> V_195 = V_43 -> V_48 -> V_196 [ 0 ] . V_202 ;
}
return;
V_192:
F_101 ( V_179 -> V_184 ) ;
V_179 -> V_184 = NULL ;
F_111 ( V_179 ) ;
}
static unsigned int
F_112 ( struct V_178 * V_179 ,
struct V_180 * V_181 )
{
if ( ! V_179 -> V_184 ) {
V_179 -> V_184 = F_102 ( V_179 -> V_185 ,
V_181 -> V_186 ,
0 ,
V_66 ,
V_122 ,
false ,
V_199 ) ;
if ( F_69 ( V_179 -> V_184 ) ) {
V_179 -> V_187 = F_70 ( V_179 -> V_184 ) ;
V_179 -> V_184 = NULL ;
goto V_203;
}
}
if ( V_179 -> V_184 )
return F_97 ( V_179 -> V_184 ) ;
F_111 ( V_179 ) ;
V_203:
return 1 ;
}
static void F_113 ( struct V_204 * V_205 , bool V_206 )
{
struct V_157 * V_158 = & V_205 -> V_158 ;
F_114 ( V_205 -> V_2 , false ) ;
if ( V_206 ) {
F_13 ( L_14
L_15 , V_23 ,
V_205 -> V_158 . V_207 ,
V_205 -> V_2 -> V_208 -> V_209 ,
( unsigned long long ) F_115 ( V_205 -> V_2 ) ,
V_205 -> args . V_210 ,
( unsigned long long ) V_205 -> args . V_64 ) ;
V_205 -> V_211 -> V_212 ( V_205 ) ;
return;
}
if ( ! F_116 ( V_213 , & V_205 -> V_89 ) ) {
F_13 ( L_16
L_15 , V_23 ,
V_205 -> V_158 . V_207 ,
V_205 -> V_2 -> V_208 -> V_209 ,
( unsigned long long ) F_115 ( V_205 -> V_2 ) ,
V_205 -> args . V_210 ,
( unsigned long long ) V_205 -> args . V_64 ) ;
V_158 -> V_214 = F_117 ( V_205 ) ;
}
}
static void F_118 ( struct V_204 * V_205 )
{
struct V_157 * V_158 = & V_205 -> V_158 ;
F_114 ( V_205 -> V_2 , false ) ;
if ( ! F_116 ( V_213 , & V_205 -> V_89 ) ) {
F_13 ( L_16
L_15 , V_23 ,
V_205 -> V_158 . V_207 ,
V_205 -> V_2 -> V_208 -> V_209 ,
( unsigned long long ) F_115 ( V_205 -> V_2 ) ,
V_205 -> args . V_210 ,
( unsigned long long ) V_205 -> args . V_64 ) ;
V_158 -> V_214 = F_119 ( V_205 ) ;
}
}
static int F_120 ( struct V_157 * V_158 ,
struct V_215 * V_216 ,
struct V_217 * V_218 ,
struct V_74 * V_83 ,
int V_177 )
{
struct V_1 * V_10 = V_83 -> V_123 ;
struct V_2 * V_2 = V_10 -> V_46 ;
struct V_219 * V_220 = F_63 ( V_2 ) ;
struct V_87 * V_25 = F_121 ( V_83 , V_177 ) ;
struct V_217 * V_221 = V_220 -> V_217 ;
struct V_222 * V_223 = & V_218 -> V_224 -> V_225 ;
if ( V_158 -> V_214 >= 0 )
return 0 ;
switch ( V_158 -> V_214 ) {
case - V_226 :
case - V_227 :
case - V_228 :
if ( V_216 == NULL )
break;
F_122 ( V_216 -> V_2 ) ;
case - V_229 :
if ( V_216 == NULL )
break;
if ( F_123 ( V_220 , V_216 ) < 0 )
goto V_230;
goto V_231;
case - V_232 :
if ( V_216 != NULL ) {
if ( F_123 ( V_220 , V_216 ) < 0 )
goto V_230;
}
F_124 ( V_221 ) ;
goto V_231;
case - V_233 :
case - V_234 :
case - V_235 :
case - V_236 :
case - V_237 :
case - V_238 :
case - V_239 :
F_13 ( L_17
L_18 , V_23 , V_158 -> V_214 ,
V_218 -> V_240 ) ;
F_125 ( V_218 -> V_224 , V_158 -> V_214 ) ;
break;
case - V_241 :
case - V_242 :
F_126 ( V_158 , V_243 ) ;
break;
case - V_244 :
break;
case - V_245 :
case - V_246 :
case - V_247 :
case - V_248 :
case - V_249 :
case - V_250 :
F_13 ( L_19 , V_23 ,
V_158 -> V_214 ) ;
F_127 ( F_128 ( V_2 ) ) ;
F_129 ( & V_223 -> V_251 ) ;
goto V_252;
case - V_253 :
case - V_254 :
case - V_255 :
case - V_256 :
case - V_105 :
case - V_257 :
case - V_258 :
F_13 ( L_20 , V_23 ,
V_158 -> V_214 ) ;
F_130 ( V_25 ) ;
F_129 ( & V_223 -> V_251 ) ;
default:
if ( F_131 ( V_83 ) )
return - V_259 ;
V_252:
F_13 ( L_21 , V_23 ,
V_158 -> V_214 ) ;
return - V_260 ;
}
V_203:
V_158 -> V_214 = 0 ;
return - V_261 ;
V_230:
V_158 -> V_214 = - V_105 ;
return 0 ;
V_231:
F_132 ( & V_221 -> V_262 , V_158 , NULL ) ;
if ( F_45 ( V_263 , & V_221 -> V_264 ) == 0 )
F_133 ( & V_221 -> V_262 , V_158 ) ;
goto V_203;
}
static int F_134 ( struct V_157 * V_158 ,
struct V_74 * V_83 ,
int V_177 )
{
struct V_87 * V_25 = F_121 ( V_83 , V_177 ) ;
if ( V_158 -> V_214 >= 0 )
return 0 ;
switch ( V_158 -> V_214 ) {
case - V_265 :
case - V_246 :
case - V_248 :
case - V_247 :
case - V_266 :
case - V_267 :
break;
case - V_268 :
F_135 ( V_83 -> V_123 -> V_46 , V_269 ) ;
goto V_270;
default:
F_13 ( L_20 , V_23 ,
V_158 -> V_214 ) ;
F_130 ( V_25 ) ;
}
return - V_259 ;
V_270:
V_158 -> V_214 = 0 ;
F_136 ( V_158 ) ;
F_126 ( V_158 , V_271 ) ;
return - V_261 ;
}
static int F_137 ( struct V_157 * V_158 ,
struct V_215 * V_216 ,
struct V_217 * V_218 ,
struct V_74 * V_83 ,
int V_177 )
{
int V_272 = V_218 -> V_273 -> V_274 -> V_275 ;
switch ( V_272 ) {
case 3 :
return F_134 ( V_158 , V_83 , V_177 ) ;
case 4 :
return F_120 ( V_158 , V_216 , V_218 ,
V_83 , V_177 ) ;
default:
F_83 ( 1 ) ;
return 0 ;
}
}
static void F_138 ( struct V_74 * V_83 ,
int V_177 , T_5 V_64 , T_5 V_65 ,
T_4 V_198 , int V_276 , int error )
{
struct V_35 * V_43 ;
int V_12 ;
if ( V_198 == 0 ) {
switch ( error ) {
case - V_257 :
case - V_277 :
case - V_278 :
case - V_279 :
case - V_253 :
case - V_280 :
case - V_254 :
case - V_255 :
case - V_256 :
case - V_281 :
case - V_20 :
case - V_258 :
case - V_282 :
V_198 = V_283 ;
break;
case - V_265 :
V_198 = V_284 ;
break;
default:
return;
}
}
switch ( V_198 ) {
case V_241 :
case V_242 :
return;
default:
break;
}
V_43 = F_107 ( V_83 , V_177 ) ;
V_12 = F_139 ( F_9 ( V_83 -> V_123 ) ,
V_43 , V_64 , V_65 , V_198 , V_276 ,
V_161 ) ;
F_140 ( V_83 -> V_123 -> V_46 , V_83 ) ;
F_13 ( L_22 , V_23 , V_12 , V_276 , V_198 ) ;
}
static int F_141 ( struct V_157 * V_158 ,
struct V_204 * V_205 )
{
int V_12 ;
F_142 ( V_205 , V_158 -> V_214 ) ;
if ( V_158 -> V_214 < 0 )
F_138 ( V_205 -> V_83 , V_205 -> V_285 ,
V_205 -> args . V_64 , V_205 -> args . V_210 ,
V_205 -> V_286 . V_287 , V_288 ,
V_158 -> V_214 ) ;
V_12 = F_137 ( V_158 , V_205 -> args . V_289 -> V_216 ,
V_205 -> V_290 , V_205 -> V_83 ,
V_205 -> V_285 ) ;
switch ( V_12 ) {
case - V_259 :
if ( F_98 ( V_205 -> V_83 ,
V_205 -> V_285 + 1 ,
& V_205 -> V_285 ) )
goto V_291;
F_143 ( V_205 ) ;
return V_158 -> V_214 ;
case - V_260 :
F_118 ( V_205 ) ;
return V_158 -> V_214 ;
case - V_261 :
goto V_291;
}
return 0 ;
V_291:
F_136 ( V_158 ) ;
return - V_261 ;
}
static bool
F_144 ( struct V_74 * V_83 )
{
return ! ( F_77 ( V_83 ) -> V_89 & V_292 ) ;
}
static void
F_145 ( struct V_2 * V_2 ,
struct V_74 * V_83 ,
T_10 V_293 )
{
if ( ! F_144 ( V_83 ) )
return;
F_146 ( V_2 , V_83 , V_293 ) ;
F_13 ( L_23 , V_23 , V_2 -> V_294 ,
( unsigned long long ) F_128 ( V_2 ) -> V_50 -> V_295 ) ;
}
static bool
F_147 ( struct V_74 * V_83 , int V_177 )
{
struct V_87 * V_88 = F_121 ( V_83 , V_177 ) ;
return F_148 ( V_88 ) ;
}
static void F_149 ( struct V_157 * V_158 ,
struct V_204 * V_205 )
{
if ( F_116 ( V_296 , & V_205 -> V_89 ) )
return;
F_91 ( V_205 -> V_2 ,
F_107 ( V_205 -> V_83 , V_205 -> V_285 ) ,
V_205 -> args . V_210 ,
V_158 -> V_159 ) ;
}
static void F_150 ( struct V_157 * V_158 ,
struct V_204 * V_205 )
{
if ( ! F_151 ( V_296 , & V_205 -> V_89 ) )
return;
F_93 ( V_158 ,
F_107 ( V_205 -> V_83 , V_205 -> V_285 ) ,
V_205 -> args . V_210 ,
V_205 -> V_286 . V_210 ) ;
}
static int F_152 ( struct V_157 * V_158 ,
struct V_204 * V_205 )
{
if ( F_12 ( F_45 ( V_297 , & V_205 -> args . V_289 -> V_89 ) ) ) {
F_153 ( V_158 , - V_105 ) ;
return - V_105 ;
}
if ( F_147 ( V_205 -> V_83 , V_205 -> V_285 ) ) {
F_153 ( V_158 , - V_254 ) ;
return - V_261 ;
}
F_149 ( V_158 , V_205 ) ;
return 0 ;
}
static void F_154 ( struct V_157 * V_158 , void * V_22 )
{
struct V_204 * V_205 = V_22 ;
if ( F_152 ( V_158 , V_205 ) )
return;
F_155 ( V_158 ) ;
}
static int F_156 ( struct V_217 * V_290 ,
struct V_298 * args ,
struct V_299 * V_286 ,
struct V_157 * V_158 )
{
if ( V_290 -> V_224 )
return F_157 ( V_290 -> V_224 ,
args ,
V_286 ,
V_158 ) ;
return F_158 ( V_290 -> V_300 ,
args ,
V_286 ,
V_158 ) ;
}
static void F_159 ( struct V_157 * V_158 , void * V_22 )
{
struct V_204 * V_205 = V_22 ;
if ( F_156 ( V_205 -> V_290 ,
& V_205 -> args . V_301 ,
& V_205 -> V_286 . V_302 ,
V_158 ) )
return;
if ( F_152 ( V_158 , V_205 ) )
return;
if ( F_160 ( & V_205 -> args . V_17 , V_205 -> args . V_289 ,
V_205 -> args . V_303 , V_304 ) == - V_105 )
F_153 ( V_158 , - V_105 ) ;
}
static void F_161 ( struct V_157 * V_158 , void * V_22 )
{
struct V_204 * V_205 = V_22 ;
F_13 ( L_24 , V_23 , V_158 -> V_214 ) ;
if ( F_45 ( V_213 , & V_205 -> V_89 ) &&
V_158 -> V_214 == 0 ) {
F_162 ( V_158 , & V_205 -> V_286 . V_302 ) ;
return;
}
V_205 -> V_305 -> V_306 ( V_158 , V_205 ) ;
}
static void F_163 ( struct V_157 * V_158 , void * V_22 )
{
struct V_204 * V_205 = V_22 ;
F_150 ( V_158 , V_205 ) ;
F_164 ( V_158 ,
& F_165 ( V_205 -> V_2 ) -> V_307 [ V_308 ] ) ;
}
static void F_166 ( void * V_22 )
{
struct V_204 * V_205 = V_22 ;
F_150 ( & V_205 -> V_158 , V_205 ) ;
F_167 ( V_22 ) ;
}
static int F_168 ( struct V_157 * V_158 ,
struct V_204 * V_205 )
{
T_10 V_309 = 0 ;
int V_12 ;
F_169 ( V_205 , V_158 -> V_214 ) ;
if ( V_158 -> V_214 < 0 )
F_138 ( V_205 -> V_83 , V_205 -> V_285 ,
V_205 -> args . V_64 , V_205 -> args . V_210 ,
V_205 -> V_286 . V_287 , V_310 ,
V_158 -> V_214 ) ;
V_12 = F_137 ( V_158 , V_205 -> args . V_289 -> V_216 ,
V_205 -> V_290 , V_205 -> V_83 ,
V_205 -> V_285 ) ;
switch ( V_12 ) {
case - V_259 :
F_113 ( V_205 , true ) ;
return V_158 -> V_214 ;
case - V_260 :
F_113 ( V_205 , false ) ;
return V_158 -> V_214 ;
case - V_261 :
return - V_261 ;
}
if ( V_205 -> V_286 . V_311 -> V_163 == V_312 ||
V_205 -> V_286 . V_311 -> V_163 == V_313 )
V_309 = V_205 -> V_314 + ( T_10 ) V_205 -> V_286 . V_210 ;
F_145 ( V_205 -> V_2 , V_205 -> V_83 , V_309 ) ;
V_205 -> V_315 . V_316 = 0 ;
if ( V_158 -> V_214 >= 0 )
F_170 ( V_205 ) ;
return 0 ;
}
static int F_171 ( struct V_157 * V_158 ,
struct V_317 * V_22 )
{
int V_12 ;
F_172 ( V_22 , V_158 -> V_214 ) ;
if ( V_158 -> V_214 < 0 )
F_138 ( V_22 -> V_83 , V_22 -> V_318 ,
V_22 -> args . V_64 , V_22 -> args . V_210 ,
V_22 -> V_286 . V_287 , V_319 ,
V_158 -> V_214 ) ;
V_12 = F_137 ( V_158 , NULL , V_22 -> V_290 ,
V_22 -> V_83 , V_22 -> V_318 ) ;
switch ( V_12 ) {
case - V_259 :
F_173 ( V_22 ) ;
return - V_261 ;
case - V_260 :
F_173 ( V_22 ) ;
return - V_261 ;
case - V_261 :
F_136 ( V_158 ) ;
return - V_261 ;
}
F_145 ( V_22 -> V_2 , V_22 -> V_83 , V_22 -> V_320 ) ;
return 0 ;
}
static void F_174 ( struct V_157 * V_158 ,
struct V_204 * V_205 )
{
if ( F_116 ( V_296 , & V_205 -> V_89 ) )
return;
F_94 ( V_205 -> V_2 ,
F_107 ( V_205 -> V_83 , V_205 -> V_285 ) ,
V_205 -> args . V_210 ,
V_158 -> V_159 ) ;
}
static void F_175 ( struct V_157 * V_158 ,
struct V_204 * V_205 )
{
if ( ! F_151 ( V_296 , & V_205 -> V_89 ) )
return;
F_95 ( V_158 ,
F_107 ( V_205 -> V_83 , V_205 -> V_285 ) ,
V_205 -> args . V_210 , V_205 -> V_286 . V_210 ,
V_205 -> V_286 . V_311 -> V_163 ) ;
}
static int F_176 ( struct V_157 * V_158 ,
struct V_204 * V_205 )
{
if ( F_12 ( F_45 ( V_297 , & V_205 -> args . V_289 -> V_89 ) ) ) {
F_153 ( V_158 , - V_105 ) ;
return - V_105 ;
}
if ( F_147 ( V_205 -> V_83 , V_205 -> V_285 ) ) {
F_153 ( V_158 , - V_254 ) ;
return - V_261 ;
}
F_174 ( V_158 , V_205 ) ;
return 0 ;
}
static void F_177 ( struct V_157 * V_158 , void * V_22 )
{
struct V_204 * V_205 = V_22 ;
if ( F_176 ( V_158 , V_205 ) )
return;
F_155 ( V_158 ) ;
}
static void F_178 ( struct V_157 * V_158 , void * V_22 )
{
struct V_204 * V_205 = V_22 ;
if ( F_156 ( V_205 -> V_290 ,
& V_205 -> args . V_301 ,
& V_205 -> V_286 . V_302 ,
V_158 ) )
return;
if ( F_176 ( V_158 , V_205 ) )
return;
if ( F_160 ( & V_205 -> args . V_17 , V_205 -> args . V_289 ,
V_205 -> args . V_303 , V_321 ) == - V_105 )
F_153 ( V_158 , - V_105 ) ;
}
static void F_179 ( struct V_157 * V_158 , void * V_22 )
{
struct V_204 * V_205 = V_22 ;
if ( F_45 ( V_213 , & V_205 -> V_89 ) &&
V_158 -> V_214 == 0 ) {
F_162 ( V_158 , & V_205 -> V_286 . V_302 ) ;
return;
}
V_205 -> V_305 -> V_306 ( V_158 , V_205 ) ;
}
static void F_180 ( struct V_157 * V_158 , void * V_22 )
{
struct V_204 * V_205 = V_22 ;
F_175 ( V_158 , V_205 ) ;
F_164 ( V_158 ,
& F_165 ( V_205 -> V_2 ) -> V_307 [ V_322 ] ) ;
}
static void F_181 ( void * V_22 )
{
struct V_204 * V_205 = V_22 ;
F_175 ( & V_205 -> V_158 , V_205 ) ;
F_167 ( V_22 ) ;
}
static void F_182 ( struct V_157 * V_158 ,
struct V_317 * V_323 )
{
if ( F_116 ( V_296 , & V_323 -> V_89 ) )
return;
F_94 ( V_323 -> V_2 ,
F_107 ( V_323 -> V_83 , V_323 -> V_318 ) ,
0 , V_158 -> V_159 ) ;
}
static void F_183 ( struct V_157 * V_158 ,
struct V_317 * V_323 )
{
struct V_180 * V_181 ;
T_9 V_210 = 0 ;
if ( ! F_151 ( V_296 , & V_323 -> V_89 ) )
return;
if ( V_158 -> V_214 == 0 ) {
F_25 (req, &cdata->pages, wb_list)
V_210 += V_181 -> V_324 ;
}
F_95 ( V_158 ,
F_107 ( V_323 -> V_83 , V_323 -> V_318 ) ,
V_210 , V_210 , V_312 ) ;
}
static void F_184 ( struct V_157 * V_158 ,
struct V_317 * V_323 )
{
F_182 ( V_158 , V_323 ) ;
}
static void F_185 ( struct V_157 * V_158 , void * V_22 )
{
F_184 ( V_158 , V_22 ) ;
F_155 ( V_158 ) ;
}
static void F_186 ( struct V_157 * V_158 , void * V_22 )
{
struct V_317 * V_325 = V_22 ;
if ( F_156 ( V_325 -> V_290 ,
& V_325 -> args . V_301 ,
& V_325 -> V_286 . V_302 ,
V_158 ) )
return;
F_184 ( V_158 , V_22 ) ;
}
static void F_187 ( struct V_157 * V_158 , void * V_22 )
{
F_188 ( V_158 , V_22 ) ;
}
static void F_189 ( struct V_157 * V_158 , void * V_22 )
{
struct V_317 * V_323 = V_22 ;
F_183 ( V_158 , V_323 ) ;
F_164 ( V_158 ,
& F_165 ( V_323 -> V_2 ) -> V_307 [ V_326 ] ) ;
}
static void F_190 ( void * V_22 )
{
struct V_317 * V_323 = V_22 ;
F_183 ( & V_323 -> V_158 , V_323 ) ;
F_191 ( V_22 ) ;
}
static enum V_327
F_192 ( struct V_204 * V_205 )
{
struct V_74 * V_83 = V_205 -> V_83 ;
struct V_173 * V_168 ;
struct V_328 * V_329 ;
struct V_52 * V_330 ;
T_10 V_64 = V_205 -> args . V_64 ;
T_4 V_177 = V_205 -> V_285 ;
int V_272 ;
struct V_27 * V_28 ;
F_13 ( L_25 ,
V_23 , V_205 -> V_2 -> V_294 ,
V_205 -> args . V_331 , ( V_332 ) V_205 -> args . V_210 , V_64 ) ;
V_168 = F_99 ( V_83 , V_177 , false ) ;
if ( ! V_168 )
goto V_333;
V_329 = F_193 ( V_83 , V_177 , V_168 -> V_290 ,
V_205 -> V_2 ) ;
if ( F_69 ( V_329 ) )
goto V_333;
V_330 = F_194 ( V_83 , V_177 , V_205 -> V_53 ) ;
if ( ! V_330 )
goto V_333;
V_272 = F_195 ( V_83 , V_177 ) ;
F_13 ( L_26 , V_23 ,
V_168 -> V_334 , F_196 ( & V_168 -> V_290 -> V_335 ) , V_272 ) ;
V_205 -> V_336 = F_141 ;
F_197 ( & V_168 -> V_290 -> V_335 ) ;
V_205 -> V_290 = V_168 -> V_290 ;
V_28 = F_198 ( V_83 , V_177 ) ;
if ( V_28 )
V_205 -> args . V_28 = V_28 ;
V_205 -> args . V_64 = V_64 ;
V_205 -> V_314 = V_64 ;
F_199 ( V_329 , V_205 , V_330 , V_168 -> V_290 -> V_337 ,
V_272 == 3 ? & V_338 :
& V_339 ,
0 , V_340 ) ;
F_35 ( V_330 ) ;
return V_341 ;
V_333:
if ( F_131 ( V_83 ) )
return V_342 ;
return V_343 ;
}
static enum V_327
F_200 ( struct V_204 * V_205 , int V_344 )
{
struct V_74 * V_83 = V_205 -> V_83 ;
struct V_173 * V_168 ;
struct V_328 * V_329 ;
struct V_52 * V_330 ;
T_10 V_64 = V_205 -> args . V_64 ;
int V_272 ;
struct V_27 * V_28 ;
int V_177 = V_205 -> V_285 ;
V_168 = F_99 ( V_83 , V_177 , true ) ;
if ( ! V_168 )
return V_343 ;
V_329 = F_193 ( V_83 , V_177 , V_168 -> V_290 ,
V_205 -> V_2 ) ;
if ( F_69 ( V_329 ) )
return V_343 ;
V_330 = F_194 ( V_83 , V_177 , V_205 -> V_53 ) ;
if ( ! V_330 )
return V_343 ;
V_272 = F_195 ( V_83 , V_177 ) ;
F_13 ( L_27 ,
V_23 , V_205 -> V_2 -> V_294 , V_344 , ( V_332 ) V_205 -> args . V_210 ,
V_64 , V_168 -> V_334 , F_196 ( & V_168 -> V_290 -> V_335 ) ,
V_272 ) ;
V_205 -> V_336 = F_168 ;
F_197 ( & V_168 -> V_290 -> V_335 ) ;
V_205 -> V_290 = V_168 -> V_290 ;
V_205 -> V_345 = V_177 ;
V_28 = F_198 ( V_83 , V_177 ) ;
if ( V_28 )
V_205 -> args . V_28 = V_28 ;
V_205 -> args . V_64 = V_64 ;
F_199 ( V_329 , V_205 , V_330 , V_168 -> V_290 -> V_337 ,
V_272 == 3 ? & V_346 :
& V_347 ,
V_344 , V_340 ) ;
F_35 ( V_330 ) ;
return V_341 ;
}
static T_4 F_201 ( struct V_74 * V_83 , T_4 V_38 )
{
return V_38 ;
}
static struct V_27 *
F_202 ( struct V_74 * V_83 , T_4 V_38 )
{
struct V_56 * V_348 = F_77 ( V_83 ) ;
return & V_348 -> V_58 [ V_38 ] -> V_42 [ 0 ] ;
}
static int F_203 ( struct V_317 * V_22 , int V_349 )
{
struct V_74 * V_83 = V_22 -> V_83 ;
struct V_173 * V_168 ;
struct V_328 * V_329 ;
struct V_52 * V_330 ;
T_4 V_177 ;
int V_272 , V_62 ;
struct V_27 * V_28 ;
V_177 = F_201 ( V_83 , V_22 -> V_318 ) ;
V_168 = F_99 ( V_83 , V_177 , true ) ;
if ( ! V_168 )
goto V_350;
V_329 = F_193 ( V_83 , V_177 , V_168 -> V_290 ,
V_22 -> V_2 ) ;
if ( F_69 ( V_329 ) )
goto V_350;
V_330 = F_194 ( V_83 , V_177 , V_22 -> V_53 ) ;
if ( ! V_330 )
goto V_350;
V_272 = F_195 ( V_83 , V_177 ) ;
F_13 ( L_28 , V_23 ,
V_22 -> V_2 -> V_294 , V_349 , F_196 ( & V_168 -> V_290 -> V_335 ) ,
V_272 ) ;
V_22 -> V_351 = F_171 ;
V_22 -> V_53 = V_330 ;
F_197 ( & V_168 -> V_290 -> V_335 ) ;
V_22 -> V_290 = V_168 -> V_290 ;
V_28 = F_202 ( V_83 , V_22 -> V_318 ) ;
if ( V_28 )
V_22 -> args . V_28 = V_28 ;
V_62 = F_204 ( V_329 , V_22 , V_168 -> V_290 -> V_337 ,
V_272 == 3 ? & V_352 :
& V_353 ,
V_349 , V_340 ) ;
F_35 ( V_330 ) ;
return V_62 ;
V_350:
F_173 ( V_22 ) ;
F_191 ( V_22 ) ;
return - V_261 ;
}
static int
F_205 ( struct V_2 * V_2 , struct V_84 * V_354 ,
int V_349 , struct V_165 * V_166 )
{
return F_206 ( V_2 , V_354 , V_349 , V_166 ,
F_203 ) ;
}
static struct V_355 *
F_207 ( struct V_2 * V_2 )
{
struct V_1 * V_50 = F_128 ( V_2 ) -> V_50 ;
if ( V_50 == NULL )
return NULL ;
return & F_9 ( V_50 ) -> V_124 ;
}
static void
F_208 ( struct V_87 * V_356 )
{
F_209 ( F_210 ( V_356 , struct V_357 ,
V_91 ) ) ;
}
static int F_211 ( struct V_4 * V_358 ,
struct V_15 * V_16 ,
const struct V_359 * args )
{
struct V_1 * V_205 = & V_358 -> V_9 ;
T_3 * V_132 ;
int V_210 = 0 , V_62 = 0 ;
V_132 = F_212 ( V_16 , 4 ) ;
if ( F_12 ( ! V_132 ) )
return - V_360 ;
F_24 ( & V_205 -> V_46 -> V_47 ) ;
V_62 = F_213 ( V_358 , V_16 , & V_210 , & args -> V_63 ) ;
F_27 ( & V_205 -> V_46 -> V_47 ) ;
* V_132 = F_214 ( V_210 ) ;
return V_62 ;
}
static void F_215 ( struct V_4 * V_358 ,
struct V_15 * V_16 ,
const struct V_359 * args )
{
T_3 * V_18 ;
V_18 = F_212 ( V_16 , 4 ) ;
if ( F_216 ( V_18 ) )
* V_18 = F_214 ( 0 ) ;
}
static struct V_87 *
F_217 ( struct V_219 * V_361 ,
struct V_362 * V_363 , T_1 V_3 )
{
struct V_357 * V_364 ;
V_364 = F_218 ( V_361 , V_363 , V_3 ) ;
if ( ! V_364 )
return NULL ;
return & V_364 -> V_91 ;
}
static void
F_219 ( struct V_1 * V_10 ,
struct V_15 * V_16 ,
const struct V_359 * args )
{
struct V_4 * V_358 = F_9 ( V_10 ) ;
T_3 * V_132 ;
F_13 ( L_29 , V_23 ) ;
V_132 = F_212 ( V_16 , 4 ) ;
F_220 ( ! V_132 ) ;
F_211 ( V_358 , V_16 , args ) ;
F_215 ( V_358 , V_16 , args ) ;
* V_132 = F_214 ( ( V_16 -> V_18 - V_132 - 1 ) * 4 ) ;
F_13 ( L_30 , V_23 ) ;
}
static int
F_221 ( const struct V_365 * V_366 , char * V_96 , const V_332 V_367 )
{
const struct V_368 * sin = (struct V_368 * ) V_366 ;
return snprintf ( V_96 , V_367 , L_31 , & sin -> V_369 ) ;
}
static V_332
F_222 ( const struct V_365 * V_366 , char * V_96 ,
const int V_367 )
{
const struct V_370 * V_371 = (struct V_370 * ) V_366 ;
const struct V_372 * V_373 = & V_371 -> V_374 ;
if ( F_223 ( V_373 ) )
return snprintf ( V_96 , V_367 , L_32 ) ;
if ( F_224 ( V_373 ) )
return snprintf ( V_96 , V_367 , L_33 ) ;
if ( F_225 ( V_373 ) )
return snprintf ( V_96 , V_367 , L_34 ,
& V_373 -> V_375 [ 3 ] ) ;
return snprintf ( V_96 , V_367 , L_35 , V_373 ) ;
}
static void
F_226 ( struct V_15 * V_16 , struct V_376 * V_377 )
{
struct V_365 * V_366 = (struct V_365 * ) & V_377 -> V_378 ;
char V_379 [ V_380 ] ;
char V_381 [ V_382 ] ;
char * V_383 ;
unsigned short V_384 ;
int V_33 , V_385 ;
T_3 * V_18 ;
switch ( V_366 -> V_386 ) {
case V_387 :
if ( F_221 ( V_366 , V_381 , sizeof( V_381 ) ) == 0 )
return;
V_384 = F_227 ( ( (struct V_368 * ) V_366 ) -> V_388 ) ;
V_383 = L_36 ;
V_385 = 3 ;
break;
case V_389 :
if ( F_222 ( V_366 , V_381 , sizeof( V_381 ) ) == 0 )
return;
V_384 = F_227 ( ( (struct V_370 * ) V_366 ) -> V_390 ) ;
V_383 = L_37 ;
V_385 = 4 ;
break;
default:
F_83 ( 1 ) ;
return;
}
snprintf ( V_379 , sizeof( V_379 ) , L_38 , V_384 >> 8 , V_384 & 0xff ) ;
V_33 = F_228 ( V_381 , V_379 , sizeof( V_381 ) ) ;
V_18 = F_212 ( V_16 , 4 + V_385 ) ;
F_229 ( V_18 , V_383 , V_385 ) ;
V_18 = F_212 ( V_16 , 4 + V_33 ) ;
F_229 ( V_18 , V_381 , V_33 ) ;
}
static void
F_230 ( struct V_15 * V_16 ,
T_7 V_391 )
{
struct V_392 V_393 ;
T_3 * V_18 ;
V_18 = F_212 ( V_16 , 12 ) ;
V_393 = F_231 ( V_391 ) ;
V_18 = F_232 ( V_18 , V_393 . V_394 ) ;
* V_18 ++ = F_214 ( V_393 . V_395 ) ;
}
static void
F_233 ( struct V_15 * V_16 ,
struct V_140 * V_396 )
{
T_3 * V_18 ;
V_18 = F_212 ( V_16 , 5 * 8 ) ;
V_18 = F_232 ( V_18 , V_396 -> V_143 ) ;
V_18 = F_232 ( V_18 , V_396 -> V_144 ) ;
V_18 = F_232 ( V_18 , V_396 -> V_149 ) ;
V_18 = F_232 ( V_18 , V_396 -> V_150 ) ;
V_18 = F_232 ( V_18 , V_396 -> V_151 ) ;
F_230 ( V_16 , V_396 -> V_152 ) ;
F_230 ( V_16 , V_396 -> V_153 ) ;
}
static void
F_234 ( struct V_15 * V_16 ,
struct V_397 * args ,
struct V_398 * V_399 )
{
struct V_35 * V_43 = V_399 -> V_400 ;
struct V_376 * V_377 ;
struct V_173 * V_168 = V_43 -> V_48 -> V_168 ;
struct V_27 * V_28 = & V_43 -> V_42 [ 0 ] ;
T_3 * V_18 , * V_132 ;
V_377 = F_235 ( & V_168 -> V_401 , struct V_376 , V_402 ) ;
F_13 ( L_39 ,
V_23 , V_168 -> V_334 , V_377 -> V_403 ) ;
V_132 = F_212 ( V_16 , 4 ) ;
F_226 ( V_16 , V_377 ) ;
V_18 = F_212 ( V_16 , 4 + V_28 -> V_29 ) ;
F_229 ( V_18 , V_28 -> V_22 , V_28 -> V_29 ) ;
F_24 ( & V_43 -> V_51 ) ;
F_233 ( V_16 , & V_43 -> V_155 . V_142 ) ;
F_233 ( V_16 , & V_43 -> V_160 . V_142 ) ;
F_27 ( & V_43 -> V_51 ) ;
F_230 ( V_16 , F_84 ( F_4 () , V_43 -> V_131 ) ) ;
V_18 = F_212 ( V_16 , 4 ) ;
* V_18 = F_214 ( false ) ;
* V_132 = F_214 ( ( V_16 -> V_18 - V_132 - 1 ) * 4 ) ;
}
static int
F_236 ( struct V_397 * args ,
struct V_1 * V_10 ,
int V_404 )
{
struct V_4 * V_44 = F_9 ( V_10 ) ;
struct V_35 * V_43 ;
struct V_87 * V_405 ;
struct V_398 * V_399 ;
int V_38 = 0 ;
F_25 (mirror, &ff_layout->mirrors, mirrors) {
if ( V_38 >= V_404 )
break;
if ( ! V_43 -> V_48 )
continue;
if ( ! F_26 ( & V_43 -> V_49 ) )
continue;
V_405 = & V_43 -> V_48 -> V_91 ;
V_399 = & args -> V_399 [ V_38 ] ;
memcpy ( & V_399 -> V_406 , & V_405 -> V_407 , V_26 ) ;
V_399 -> V_64 = 0 ;
V_399 -> V_65 = V_66 ;
V_399 -> V_408 = V_43 -> V_155 . V_142 . V_149 ;
V_399 -> V_409 = V_43 -> V_155 . V_142 . V_150 ;
V_399 -> V_410 = V_43 -> V_160 . V_142 . V_149 ;
V_399 -> V_411 = V_43 -> V_160 . V_142 . V_150 ;
V_399 -> V_412 = V_413 ;
V_399 -> V_414 = F_234 ;
V_399 -> V_400 = V_43 ;
V_38 ++ ;
}
return V_38 ;
}
static int
F_237 ( struct V_397 * args )
{
struct V_4 * V_44 ;
struct V_35 * V_43 ;
int V_415 = 0 ;
F_24 ( & args -> V_2 -> V_47 ) ;
V_44 = F_9 ( F_128 ( args -> V_2 ) -> V_50 ) ;
F_25 (mirror, &ff_layout->mirrors, mirrors) {
if ( F_196 ( & V_43 -> V_49 ) != 0 )
V_415 ++ ;
}
F_27 ( & args -> V_2 -> V_47 ) ;
if ( V_415 > V_416 ) {
F_13 ( L_40 ,
V_23 , V_415 , V_416 ) ;
V_415 = V_416 ;
}
args -> V_399 = F_238 ( V_415 , sizeof( * args -> V_399 ) , V_161 ) ;
if ( ! args -> V_399 )
return - V_101 ;
F_24 ( & args -> V_2 -> V_47 ) ;
args -> V_417 = F_236 ( args ,
& V_44 -> V_9 , V_415 ) ;
F_27 ( & args -> V_2 -> V_47 ) ;
return 0 ;
}
static void
F_239 ( struct V_418 * V_22 )
{
struct V_35 * V_43 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_22 -> args . V_417 ; V_38 ++ ) {
V_43 = V_22 -> args . V_399 [ V_38 ] . V_400 ;
V_22 -> args . V_399 [ V_38 ] . V_400 = NULL ;
F_37 ( V_43 ) ;
}
}
static int T_11 F_240 ( void )
{
F_18 ( V_419 L_41 ,
V_23 ) ;
if ( ! V_112 ) {
V_112 = F_241 ( 0 ) ;
if ( ! V_112 )
return - V_101 ;
}
return F_242 ( & V_420 ) ;
}
static void T_12 F_243 ( void )
{
F_18 ( V_419 L_42 ,
V_23 ) ;
F_244 ( & V_420 ) ;
if ( V_112 ) {
F_245 ( V_112 ) ;
V_112 = NULL ;
}
}
