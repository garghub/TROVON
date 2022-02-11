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
V_16 -> type = V_20 ;
memcpy ( V_16 -> V_21 , V_17 , V_18 ) ;
F_12 ( L_1 , V_22 ,
V_17 [ 0 ] , V_17 [ 1 ] , V_17 [ 2 ] , V_17 [ 3 ] ) ;
return 0 ;
}
static int F_13 ( struct V_14 * V_15 , struct V_23 * V_24 )
{
T_3 * V_17 ;
V_17 = F_10 ( V_15 , V_25 ) ;
if ( F_11 ( ! V_17 ) )
return - V_19 ;
memcpy ( V_24 , V_17 , V_25 ) ;
F_14 ( V_24 ) ;
return 0 ;
}
static int F_15 ( struct V_14 * V_15 , struct V_26 * V_27 )
{
T_3 * V_17 ;
V_17 = F_10 ( V_15 , 4 ) ;
if ( F_11 ( ! V_17 ) )
return - V_19 ;
V_27 -> V_28 = F_16 ( V_17 ++ ) ;
if ( V_27 -> V_28 > sizeof( struct V_26 ) ) {
F_17 ( V_29 L_2 ,
V_27 -> V_28 ) ;
return - V_30 ;
}
V_17 = F_10 ( V_15 , V_27 -> V_28 ) ;
if ( F_11 ( ! V_17 ) )
return - V_19 ;
memcpy ( & V_27 -> V_21 , V_17 , V_27 -> V_28 ) ;
F_12 ( L_3 , V_22 , V_27 -> V_28 ) ;
return 0 ;
}
static int
F_18 ( struct V_14 * V_15 , T_4 * V_31 )
{
T_3 * V_17 ;
int V_32 ;
V_17 = F_10 ( V_15 , 4 ) ;
if ( F_11 ( ! V_17 ) )
return - V_19 ;
V_32 = F_16 ( V_17 ++ ) ;
if ( V_32 < 0 )
return - V_33 ;
F_12 ( L_4 , V_22 , V_32 ) ;
V_17 = F_10 ( V_15 , V_32 ) ;
if ( F_11 ( ! V_17 ) )
return - V_19 ;
if ( ! F_19 ( ( char * ) V_17 , V_32 , V_31 ) )
return - V_33 ;
return 0 ;
}
static bool F_20 ( const struct V_34 * V_35 ,
const struct V_34 * V_36 )
{
int V_37 , V_38 ;
if ( V_35 -> V_39 != V_36 -> V_39 )
return false ;
for ( V_37 = 0 ; V_37 < V_35 -> V_39 ; V_37 ++ ) {
bool V_40 = false ;
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ ) {
if ( F_21 ( & V_35 -> V_41 [ V_37 ] ,
& V_36 -> V_41 [ V_38 ] ) == 0 ) {
V_40 = true ;
break;
}
}
if ( ! V_40 )
return false ;
}
return true ;
}
static struct V_34 *
F_22 ( struct V_1 * V_9 ,
struct V_34 * V_42 )
{
struct V_4 * V_43 = F_8 ( V_9 ) ;
struct V_34 * V_44 ;
struct V_2 * V_2 = V_9 -> V_45 ;
F_23 ( & V_2 -> V_46 ) ;
F_24 (pos, &ff_layout->mirrors, mirrors) {
if ( V_42 -> V_47 != V_44 -> V_47 )
continue;
if ( ! F_20 ( V_42 , V_44 ) )
continue;
if ( F_25 ( & V_44 -> V_48 ) ) {
F_26 ( & V_2 -> V_46 ) ;
return V_44 ;
}
}
F_27 ( & V_42 -> V_7 , & V_43 -> V_7 ) ;
V_42 -> V_49 = V_9 ;
F_26 ( & V_2 -> V_46 ) ;
return V_42 ;
}
static void
F_28 ( struct V_34 * V_42 )
{
struct V_2 * V_2 ;
if ( V_42 -> V_49 == NULL )
return;
V_2 = V_42 -> V_49 -> V_45 ;
F_23 ( & V_2 -> V_46 ) ;
F_6 ( & V_42 -> V_7 ) ;
F_26 ( & V_2 -> V_46 ) ;
V_42 -> V_49 = NULL ;
}
static struct V_34 * F_29 ( T_1 V_3 )
{
struct V_34 * V_42 ;
V_42 = F_2 ( sizeof( * V_42 ) , V_3 ) ;
if ( V_42 != NULL ) {
F_30 ( & V_42 -> V_50 ) ;
F_31 ( & V_42 -> V_48 , 1 ) ;
F_3 ( & V_42 -> V_7 ) ;
}
return V_42 ;
}
static void F_32 ( struct V_34 * V_42 )
{
struct V_51 * V_52 ;
F_28 ( V_42 ) ;
F_7 ( V_42 -> V_41 ) ;
V_52 = F_33 ( V_42 -> V_53 ) ;
if ( V_52 )
F_34 ( V_52 ) ;
V_52 = F_33 ( V_42 -> V_54 ) ;
if ( V_52 )
F_34 ( V_52 ) ;
F_35 ( V_42 -> V_47 ) ;
F_7 ( V_42 ) ;
}
static void F_36 ( struct V_34 * V_42 )
{
if ( V_42 != NULL && F_37 ( & V_42 -> V_48 ) )
F_32 ( V_42 ) ;
}
static void F_38 ( struct V_55 * V_56 )
{
int V_37 ;
if ( V_56 -> V_57 ) {
for ( V_37 = 0 ; V_37 < V_56 -> V_58 ; V_37 ++ ) {
F_36 ( V_56 -> V_57 [ V_37 ] ) ;
}
F_7 ( V_56 -> V_57 ) ;
V_56 -> V_57 = NULL ;
}
}
static int F_39 ( struct V_59 * V_60 )
{
int V_61 = 0 ;
F_12 ( L_5 , V_22 ) ;
if ( V_60 -> V_62 . V_63 != 0 ||
V_60 -> V_62 . V_64 != V_65 ) {
F_12 ( L_6 ,
V_22 ) ;
V_61 = - V_33 ;
}
F_12 ( L_7 , V_22 , V_61 ) ;
return V_61 ;
}
static void F_40 ( struct V_55 * V_56 )
{
if ( V_56 ) {
F_38 ( V_56 ) ;
F_7 ( V_56 ) ;
}
}
static bool
F_41 ( const struct V_66 * V_67 ,
const struct V_66 * V_68 )
{
T_5 V_69 , V_70 ;
if ( V_67 -> V_71 != V_68 -> V_71 )
return V_67 -> V_71 != V_72 ;
V_69 = F_42 ( V_67 -> V_63 , V_67 -> V_64 ) ;
V_70 = F_42 ( V_68 -> V_63 , V_68 -> V_64 ) ;
if ( V_69 < V_68 -> V_63 )
return false ;
if ( V_70 < V_67 -> V_63 )
return true ;
return V_68 -> V_63 <= V_67 -> V_63 ;
}
static bool
F_43 ( struct V_73 * V_74 ,
struct V_73 * V_75 )
{
T_5 V_76 , V_77 ;
if ( F_44 ( V_78 , & V_75 -> V_79 ) )
return false ;
if ( V_74 -> V_80 . V_71 != V_75 -> V_80 . V_71 )
return false ;
V_77 = F_42 ( V_75 -> V_80 . V_63 ,
V_75 -> V_80 . V_64 ) ;
if ( V_77 < V_74 -> V_80 . V_63 )
return false ;
V_76 = F_42 ( V_74 -> V_80 . V_63 ,
V_74 -> V_80 . V_64 ) ;
if ( V_76 < V_75 -> V_80 . V_63 )
return false ;
if ( V_76 < V_77 )
V_76 = V_77 ;
if ( V_74 -> V_80 . V_63 < V_75 -> V_80 . V_63 )
V_74 -> V_80 . V_63 = V_75 -> V_80 . V_63 ;
V_74 -> V_80 . V_64 = F_45 ( V_74 -> V_80 . V_63 ,
V_76 ) ;
if ( F_44 ( V_81 , & V_75 -> V_79 ) )
F_46 ( V_81 , & V_74 -> V_79 ) ;
return true ;
}
static void
F_47 ( struct V_1 * V_9 ,
struct V_73 * V_82 ,
struct V_83 * V_84 )
{
F_48 ( V_9 , V_82 ,
F_41 ,
F_43 ,
V_84 ) ;
}
static void F_49 ( struct V_55 * V_56 )
{
int V_37 , V_38 ;
for ( V_37 = 0 ; V_37 < V_56 -> V_58 - 1 ; V_37 ++ ) {
for ( V_38 = V_37 + 1 ; V_38 < V_56 -> V_58 ; V_38 ++ )
if ( V_56 -> V_57 [ V_37 ] -> V_85 <
V_56 -> V_57 [ V_38 ] -> V_85 )
F_50 ( V_56 -> V_57 [ V_37 ] ,
V_56 -> V_57 [ V_38 ] ) ;
}
}
static void F_51 ( struct V_55 * V_56 )
{
struct V_86 * V_87 ;
int V_37 ;
if ( ! ( V_56 -> V_88 & V_89 ) )
return;
for ( V_37 = 0 ; V_37 < V_56 -> V_58 ; V_37 ++ ) {
V_87 = & V_56 -> V_57 [ V_37 ] -> V_47 -> V_90 ;
F_52 ( V_91 , & V_87 -> V_88 ) ;
}
}
static struct V_73 *
F_53 ( struct V_1 * V_92 ,
struct V_59 * V_60 ,
T_1 V_3 )
{
struct V_73 * V_61 ;
struct V_55 * V_56 = NULL ;
struct V_14 V_93 ;
struct V_94 V_95 ;
struct V_96 * V_97 ;
T_5 V_98 ;
T_4 V_58 ;
T_3 * V_17 ;
int V_37 , V_99 ;
F_12 ( L_5 , V_22 ) ;
V_97 = F_54 ( V_3 ) ;
if ( ! V_97 )
return F_55 ( - V_100 ) ;
F_56 ( & V_93 , & V_95 , V_60 -> V_101 -> V_102 ,
V_60 -> V_101 -> V_32 ) ;
F_57 ( & V_93 , F_58 ( V_97 ) , V_103 ) ;
V_99 = - V_104 ;
V_17 = F_10 ( & V_93 , 8 + 4 ) ;
if ( ! V_17 )
goto V_105;
V_17 = F_59 ( V_17 , & V_98 ) ;
V_58 = F_16 ( V_17 ++ ) ;
F_12 ( L_8 , V_22 ,
V_98 , V_58 ) ;
if ( V_58 > V_106 ||
V_58 == 0 )
goto V_105;
V_99 = - V_100 ;
V_56 = F_2 ( sizeof( * V_56 ) , V_3 ) ;
if ( ! V_56 )
goto V_105;
V_56 -> V_58 = V_58 ;
V_56 -> V_98 = V_98 ;
V_56 -> V_57 = F_60 ( V_56 -> V_58 ,
sizeof( V_56 -> V_57 [ 0 ] ) , V_3 ) ;
if ( V_56 -> V_57 == NULL )
goto V_105;
for ( V_37 = 0 ; V_37 < V_56 -> V_58 ; V_37 ++ ) {
struct V_34 * V_42 ;
struct V_23 V_24 ;
struct V_86 * V_107 ;
struct V_108 V_109 = { . V_110 = V_111 } ;
struct V_51 T_6 * V_52 ;
T_4 V_112 , V_113 , V_31 ;
int V_38 ;
V_99 = - V_104 ;
V_17 = F_10 ( & V_93 , 4 ) ;
if ( ! V_17 )
goto V_105;
V_112 = F_16 ( V_17 ) ;
if ( V_112 != 1 )
goto V_105;
V_56 -> V_57 [ V_37 ] = F_29 ( V_3 ) ;
if ( V_56 -> V_57 [ V_37 ] == NULL ) {
V_99 = - V_100 ;
goto V_105;
}
V_56 -> V_57 [ V_37 ] -> V_112 = V_112 ;
V_99 = F_13 ( & V_93 , & V_24 ) ;
if ( V_99 )
goto V_105;
V_107 = F_61 ( F_62 ( V_92 -> V_45 ) ,
& V_24 , V_92 -> V_114 ,
V_3 ) ;
if ( V_107 )
V_56 -> V_57 [ V_37 ] -> V_47 =
F_63 ( V_107 ) ;
else
goto V_105;
V_99 = - V_104 ;
V_17 = F_10 ( & V_93 , 4 ) ;
if ( ! V_17 )
goto V_105;
V_56 -> V_57 [ V_37 ] -> V_85 = F_16 ( V_17 ) ;
V_99 = F_9 ( & V_93 , & V_56 -> V_57 [ V_37 ] -> V_16 ) ;
if ( V_99 )
goto V_105;
V_17 = F_10 ( & V_93 , 4 ) ;
if ( ! V_17 )
goto V_105;
V_113 = F_16 ( V_17 ) ;
V_56 -> V_57 [ V_37 ] -> V_41 =
F_2 ( V_113 * sizeof( struct V_26 ) ,
V_3 ) ;
if ( V_56 -> V_57 [ V_37 ] -> V_41 == NULL ) {
V_99 = - V_100 ;
goto V_105;
}
for ( V_38 = 0 ; V_38 < V_113 ; V_38 ++ ) {
V_99 = F_15 ( & V_93 ,
& V_56 -> V_57 [ V_37 ] -> V_41 [ V_38 ] ) ;
if ( V_99 )
goto V_105;
}
V_56 -> V_57 [ V_37 ] -> V_39 = V_113 ;
V_99 = F_18 ( & V_93 , & V_31 ) ;
if ( V_99 )
goto V_105;
V_109 . V_115 = F_64 ( & V_116 , V_31 ) ;
V_99 = F_18 ( & V_93 , & V_31 ) ;
if ( V_99 )
goto V_105;
V_109 . V_117 = F_65 ( & V_116 , V_31 ) ;
F_66 ( V_52 , F_67 ( & V_109 , 0 , V_3 ) ) ;
if ( F_68 ( V_52 ) ) {
V_99 = F_69 ( V_52 ) ;
goto V_105;
}
if ( V_60 -> V_62 . V_71 == V_72 )
F_66 ( V_56 -> V_57 [ V_37 ] -> V_53 , V_52 ) ;
else
F_66 ( V_56 -> V_57 [ V_37 ] -> V_54 , V_52 ) ;
V_42 = F_22 ( V_92 , V_56 -> V_57 [ V_37 ] ) ;
if ( V_42 != V_56 -> V_57 [ V_37 ] ) {
if ( V_60 -> V_62 . V_71 == V_72 ) {
V_52 = F_70 ( & V_42 -> V_53 , V_52 ) ;
F_66 ( V_56 -> V_57 [ V_37 ] -> V_53 , V_52 ) ;
} else {
V_52 = F_70 ( & V_42 -> V_54 , V_52 ) ;
F_66 ( V_56 -> V_57 [ V_37 ] -> V_54 , V_52 ) ;
}
F_32 ( V_56 -> V_57 [ V_37 ] ) ;
V_56 -> V_57 [ V_37 ] = V_42 ;
}
F_12 ( L_9 , V_22 ,
V_60 -> V_62 . V_71 == V_72 ? L_10 : L_11 ,
F_71 ( & V_116 , V_109 . V_115 ) ,
F_72 ( & V_116 , V_109 . V_117 ) ) ;
}
V_17 = F_10 ( & V_93 , 4 ) ;
if ( ! V_17 )
goto V_118;
V_56 -> V_88 = F_16 ( V_17 ) ;
V_17 = F_10 ( & V_93 , 4 ) ;
if ( ! V_17 )
goto V_118;
for ( V_37 = 0 ; V_37 < V_56 -> V_58 ; V_37 ++ )
V_56 -> V_57 [ V_37 ] -> V_119 = F_16 ( V_17 ) ;
V_118:
F_49 ( V_56 ) ;
V_99 = F_39 ( V_60 ) ;
if ( V_99 )
goto V_105;
F_51 ( V_56 ) ;
V_61 = & V_56 -> V_8 ;
F_12 ( L_12 , V_22 ) ;
V_120:
F_73 ( V_97 ) ;
return V_61 ;
V_105:
F_40 ( V_56 ) ;
V_61 = F_55 ( V_99 ) ;
F_12 ( L_13 , V_22 , V_99 ) ;
goto V_120;
}
static bool F_74 ( struct V_1 * V_49 )
{
struct V_73 * V_82 ;
F_24 (lseg, &layout->plh_segs, pls_list)
if ( V_82 -> V_80 . V_71 == V_121 )
return true ;
return false ;
}
static void
F_75 ( struct V_73 * V_82 )
{
struct V_55 * V_56 = F_76 ( V_82 ) ;
F_12 ( L_5 , V_22 ) ;
if ( V_82 -> V_80 . V_71 == V_121 ) {
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_5 = F_8 ( V_82 -> V_122 ) ;
V_2 = V_5 -> V_8 . V_45 ;
F_23 ( & V_2 -> V_46 ) ;
if ( ! F_74 ( V_82 -> V_122 ) ) {
V_5 -> V_123 . V_124 = 0 ;
F_7 ( V_5 -> V_123 . V_125 ) ;
V_5 -> V_123 . V_125 = NULL ;
}
F_26 ( & V_2 -> V_46 ) ;
}
F_40 ( V_56 ) ;
}
static int
F_77 ( struct V_55 * V_56 )
{
return 1 ;
}
static void
F_78 ( struct V_126 * V_127 , T_7 V_128 )
{
if ( F_79 ( & V_127 -> V_129 ) == 1 ) {
V_127 -> V_130 = V_128 ;
}
}
static T_7
F_80 ( struct V_126 * V_127 , T_7 V_128 )
{
T_7 V_131 ;
if ( F_81 ( & V_127 -> V_129 ) < 0 )
F_82 ( 1 ) ;
V_131 = V_127 -> V_130 ;
V_127 -> V_130 = V_128 ;
return F_83 ( V_128 , V_131 ) ;
}
static bool
F_84 ( struct V_34 * V_42 ,
struct V_132 * V_133 ,
T_7 V_128 )
{
static const T_7 V_134 = { 0 } ;
T_8 V_119 = V_135 ;
F_78 ( & V_133 -> V_136 , V_128 ) ;
if ( F_85 ( V_42 -> V_130 , V_134 ) )
V_42 -> V_130 = V_128 ;
if ( F_85 ( V_42 -> V_137 , V_134 ) )
V_42 -> V_137 = V_128 ;
if ( V_42 -> V_119 != 0 )
V_119 = ( T_8 ) V_42 -> V_119 * 1000LL ;
else if ( V_138 != 0 )
V_119 = ( T_8 ) V_138 * 1000LL ;
if ( F_86 ( F_83 ( V_128 , V_42 -> V_137 ) ) >=
V_119 ) {
V_42 -> V_137 = V_128 ;
return true ;
}
return false ;
}
static void
F_87 ( struct V_132 * V_133 ,
T_9 V_139 )
{
struct V_140 * V_141 = & V_133 -> V_142 ;
V_141 -> V_143 ++ ;
V_141 -> V_144 += V_139 ;
}
static void
F_88 ( struct V_132 * V_133 ,
T_9 V_139 ,
T_9 V_145 ,
T_7 V_146 ,
T_7 V_147 )
{
struct V_140 * V_141 = & V_133 -> V_142 ;
T_7 V_148 = F_83 ( V_146 , V_147 ) ;
T_7 V_127 ;
V_141 -> V_149 ++ ;
V_141 -> V_150 += V_145 ;
V_141 -> V_151 += V_139 - V_145 ;
V_127 = F_80 ( & V_133 -> V_136 , V_146 ) ;
V_141 -> V_152 =
F_89 ( V_141 -> V_152 , V_127 ) ;
V_141 -> V_153 =
F_89 ( V_141 -> V_153 ,
V_148 ) ;
}
static void
F_90 ( struct V_2 * V_2 ,
struct V_34 * V_42 ,
T_9 V_139 , T_7 V_128 )
{
bool V_154 ;
F_23 ( & V_42 -> V_50 ) ;
V_154 = F_84 ( V_42 , & V_42 -> V_155 , V_128 ) ;
F_87 ( & V_42 -> V_155 , V_139 ) ;
F_26 ( & V_42 -> V_50 ) ;
if ( V_154 )
F_91 ( V_2 , V_156 ) ;
}
static void
F_92 ( struct V_157 * V_158 ,
struct V_34 * V_42 ,
T_9 V_139 ,
T_9 V_145 )
{
F_23 ( & V_42 -> V_50 ) ;
F_88 ( & V_42 -> V_155 ,
V_139 , V_145 ,
F_93 () , V_158 -> V_159 ) ;
F_26 ( & V_42 -> V_50 ) ;
}
static void
F_94 ( struct V_2 * V_2 ,
struct V_34 * V_42 ,
T_9 V_139 , T_7 V_128 )
{
bool V_154 ;
F_23 ( & V_42 -> V_50 ) ;
V_154 = F_84 ( V_42 , & V_42 -> V_160 , V_128 ) ;
F_87 ( & V_42 -> V_160 , V_139 ) ;
F_26 ( & V_42 -> V_50 ) ;
if ( V_154 )
F_91 ( V_2 , V_161 ) ;
}
static void
F_95 ( struct V_157 * V_158 ,
struct V_34 * V_42 ,
T_9 V_139 ,
T_9 V_145 ,
enum V_162 V_163 )
{
if ( V_163 == V_164 )
V_139 = V_145 = 0 ;
F_23 ( & V_42 -> V_50 ) ;
F_88 ( & V_42 -> V_160 ,
V_139 , V_145 , F_93 () , V_158 -> V_159 ) ;
F_26 ( & V_42 -> V_50 ) ;
}
static int
F_96 ( struct V_73 * V_82 ,
struct V_165 * V_166 ,
T_1 V_3 )
{
struct V_55 * V_56 = F_76 ( V_82 ) ;
struct V_167 * V_125 ;
int V_28 ;
if ( V_166 -> V_168 -> V_124 != 0 ) {
return 0 ;
}
V_28 = F_77 ( V_56 ) * F_97 ( V_82 ) ;
V_125 = F_60 ( V_28 , sizeof( struct V_167 ) ,
V_3 ) ;
if ( ! V_125 )
return - V_100 ;
else {
int V_37 ;
F_23 ( & V_166 -> V_2 -> V_46 ) ;
if ( V_166 -> V_168 -> V_124 != 0 )
F_7 ( V_125 ) ;
else {
V_166 -> V_168 -> V_125 = V_125 ;
V_166 -> V_168 -> V_124 = V_28 ;
for ( V_37 = 0 ; V_37 < V_28 ; V_37 ++ ) {
F_3 ( & V_125 [ V_37 ] . V_169 ) ;
F_3 ( & V_125 [ V_37 ] . V_170 ) ;
V_125 [ V_37 ] . V_171 . V_163 =
V_172 ;
}
}
F_26 ( & V_166 -> V_2 -> V_46 ) ;
return 0 ;
}
}
static struct V_173 *
F_98 ( struct V_73 * V_82 ,
int V_174 ,
int * V_175 )
{
struct V_55 * V_56 = F_76 ( V_82 ) ;
struct V_173 * V_168 ;
int V_176 ;
for ( V_176 = V_174 ; V_176 < V_56 -> V_58 ; V_176 ++ ) {
V_168 = F_99 ( V_82 , V_176 , false ) ;
if ( V_168 ) {
* V_175 = V_176 ;
return V_168 ;
}
}
return NULL ;
}
static void
F_100 ( struct V_177 * V_178 ,
struct V_179 * V_180 ,
bool V_181 )
{
V_182:
F_101 ( V_178 -> V_183 ) ;
V_178 -> V_183 = F_102 ( V_178 -> V_184 ,
V_180 -> V_185 ,
0 ,
V_65 ,
V_72 ,
V_181 ,
V_156 ) ;
if ( F_68 ( V_178 -> V_183 ) ) {
V_178 -> V_186 = F_69 ( V_178 -> V_183 ) ;
V_178 -> V_183 = NULL ;
}
if ( V_178 -> V_183 && ! V_181 &&
F_103 ( V_178 -> V_183 ) ) {
V_181 = true ;
goto V_182;
}
}
static void
F_104 ( struct V_177 * V_178 ,
struct V_179 * V_180 )
{
struct V_187 * V_188 ;
struct V_34 * V_42 ;
struct V_173 * V_168 ;
int V_189 ;
if ( ! V_178 -> V_183 )
F_100 ( V_178 , V_180 , false ) ;
else if ( F_103 ( V_178 -> V_183 ) )
F_100 ( V_178 , V_180 , true ) ;
if ( V_178 -> V_183 == NULL )
goto V_190;
V_168 = F_98 ( V_178 -> V_183 , 0 , & V_189 ) ;
if ( ! V_168 ) {
if ( F_105 ( V_178 -> V_183 ) )
goto V_191;
else
goto V_190;
}
V_42 = F_106 ( V_178 -> V_183 , V_189 ) ;
V_178 -> V_192 = V_189 ;
V_188 = & V_178 -> V_193 [ 0 ] ;
V_188 -> V_194 = V_42 -> V_47 -> V_195 [ 0 ] . V_196 ;
return;
V_190:
F_101 ( V_178 -> V_183 ) ;
V_178 -> V_183 = NULL ;
F_107 ( V_178 ) ;
return;
V_191:
F_108 ( V_178 -> V_183 ) ;
F_101 ( V_178 -> V_183 ) ;
V_178 -> V_183 = NULL ;
}
static void
F_109 ( struct V_177 * V_178 ,
struct V_179 * V_180 )
{
struct V_34 * V_42 ;
struct V_187 * V_188 ;
struct V_165 V_166 ;
struct V_173 * V_168 ;
int V_37 ;
int V_197 ;
if ( ! V_178 -> V_183 ) {
V_178 -> V_183 = F_102 ( V_178 -> V_184 ,
V_180 -> V_185 ,
0 ,
V_65 ,
V_121 ,
false ,
V_198 ) ;
if ( F_68 ( V_178 -> V_183 ) ) {
V_178 -> V_186 = F_69 ( V_178 -> V_183 ) ;
V_178 -> V_183 = NULL ;
return;
}
}
if ( V_178 -> V_183 == NULL )
goto V_190;
F_110 ( & V_166 , V_178 -> V_184 , V_178 -> V_199 ) ;
V_197 = F_96 ( V_178 -> V_183 , & V_166 , V_198 ) ;
if ( V_197 < 0 )
goto V_190;
if ( F_82 ( V_178 -> V_200 !=
F_97 ( V_178 -> V_183 ) ) )
goto V_190;
for ( V_37 = 0 ; V_37 < V_178 -> V_200 ; V_37 ++ ) {
V_168 = F_99 ( V_178 -> V_183 , V_37 , true ) ;
if ( ! V_168 ) {
if ( F_105 ( V_178 -> V_183 ) )
goto V_191;
else
goto V_190;
}
V_188 = & V_178 -> V_193 [ V_37 ] ;
V_42 = F_106 ( V_178 -> V_183 , V_37 ) ;
V_188 -> V_194 = V_42 -> V_47 -> V_195 [ 0 ] . V_201 ;
}
return;
V_190:
F_101 ( V_178 -> V_183 ) ;
V_178 -> V_183 = NULL ;
F_111 ( V_178 ) ;
return;
V_191:
F_108 ( V_178 -> V_183 ) ;
F_101 ( V_178 -> V_183 ) ;
V_178 -> V_183 = NULL ;
}
static unsigned int
F_112 ( struct V_177 * V_178 ,
struct V_179 * V_180 )
{
if ( ! V_178 -> V_183 ) {
V_178 -> V_183 = F_102 ( V_178 -> V_184 ,
V_180 -> V_185 ,
0 ,
V_65 ,
V_121 ,
false ,
V_198 ) ;
if ( F_68 ( V_178 -> V_183 ) ) {
V_178 -> V_186 = F_69 ( V_178 -> V_183 ) ;
V_178 -> V_183 = NULL ;
goto V_202;
}
}
if ( V_178 -> V_183 )
return F_97 ( V_178 -> V_183 ) ;
F_111 ( V_178 ) ;
V_202:
return 1 ;
}
static void F_113 ( struct V_203 * V_204 , bool V_205 )
{
struct V_157 * V_158 = & V_204 -> V_158 ;
F_114 ( V_204 -> V_2 , false ) ;
if ( V_205 ) {
F_12 ( L_14
L_15 , V_22 ,
V_204 -> V_158 . V_206 ,
V_204 -> V_2 -> V_207 -> V_208 ,
( unsigned long long ) F_115 ( V_204 -> V_2 ) ,
V_204 -> args . V_209 ,
( unsigned long long ) V_204 -> args . V_63 ) ;
V_204 -> V_210 -> V_211 ( V_204 ) ;
return;
}
if ( ! F_116 ( V_212 , & V_204 -> V_88 ) ) {
F_12 ( L_16
L_15 , V_22 ,
V_204 -> V_158 . V_206 ,
V_204 -> V_2 -> V_207 -> V_208 ,
( unsigned long long ) F_115 ( V_204 -> V_2 ) ,
V_204 -> args . V_209 ,
( unsigned long long ) V_204 -> args . V_63 ) ;
V_158 -> V_213 = F_117 ( V_204 ) ;
}
}
static void F_118 ( struct V_203 * V_204 )
{
struct V_157 * V_158 = & V_204 -> V_158 ;
F_114 ( V_204 -> V_2 , false ) ;
if ( ! F_116 ( V_212 , & V_204 -> V_88 ) ) {
F_12 ( L_16
L_15 , V_22 ,
V_204 -> V_158 . V_206 ,
V_204 -> V_2 -> V_207 -> V_208 ,
( unsigned long long ) F_115 ( V_204 -> V_2 ) ,
V_204 -> args . V_209 ,
( unsigned long long ) V_204 -> args . V_63 ) ;
V_158 -> V_213 = F_119 ( V_204 ) ;
}
}
static int F_120 ( struct V_157 * V_158 ,
struct V_214 * V_215 ,
struct V_216 * V_217 ,
struct V_73 * V_82 ,
int V_176 )
{
struct V_1 * V_9 = V_82 -> V_122 ;
struct V_2 * V_2 = V_9 -> V_45 ;
struct V_218 * V_219 = F_62 ( V_2 ) ;
struct V_86 * V_24 = F_121 ( V_82 , V_176 ) ;
struct V_216 * V_220 = V_219 -> V_216 ;
struct V_221 * V_222 = & V_217 -> V_223 -> V_224 ;
if ( V_158 -> V_213 >= 0 )
return 0 ;
switch ( V_158 -> V_213 ) {
case - V_225 :
case - V_226 :
case - V_227 :
if ( V_215 == NULL )
break;
F_122 ( V_215 -> V_2 ) ;
case - V_228 :
if ( V_215 == NULL )
break;
if ( F_123 ( V_219 , V_215 ) < 0 )
goto V_229;
goto V_230;
case - V_231 :
if ( V_215 != NULL ) {
if ( F_123 ( V_219 , V_215 ) < 0 )
goto V_229;
}
F_124 ( V_220 ) ;
goto V_230;
case - V_232 :
case - V_233 :
case - V_234 :
case - V_235 :
case - V_236 :
case - V_237 :
case - V_238 :
F_12 ( L_17
L_18 , V_22 , V_158 -> V_213 ,
V_217 -> V_239 ) ;
F_125 ( V_217 -> V_223 , V_158 -> V_213 ) ;
break;
case - V_240 :
case - V_241 :
F_126 ( V_158 , V_242 ) ;
break;
case - V_243 :
break;
case - V_244 :
case - V_245 :
case - V_246 :
case - V_247 :
case - V_248 :
case - V_249 :
F_12 ( L_19 , V_22 ,
V_158 -> V_213 ) ;
F_127 ( F_128 ( V_2 ) ) ;
F_129 ( & V_222 -> V_250 ) ;
goto V_251;
case - V_252 :
case - V_253 :
case - V_254 :
case - V_255 :
case - V_104 :
case - V_256 :
case - V_257 :
F_12 ( L_20 , V_22 ,
V_158 -> V_213 ) ;
F_130 ( V_24 ) ;
F_129 ( & V_222 -> V_250 ) ;
default:
if ( F_131 ( V_82 ) )
return - V_258 ;
V_251:
F_12 ( L_21 , V_22 ,
V_158 -> V_213 ) ;
return - V_259 ;
}
V_202:
V_158 -> V_213 = 0 ;
return - V_260 ;
V_229:
V_158 -> V_213 = - V_104 ;
return 0 ;
V_230:
F_132 ( & V_220 -> V_261 , V_158 , NULL ) ;
if ( F_44 ( V_262 , & V_220 -> V_263 ) == 0 )
F_133 ( & V_220 -> V_261 , V_158 ) ;
goto V_202;
}
static int F_134 ( struct V_157 * V_158 ,
struct V_73 * V_82 ,
int V_176 )
{
struct V_86 * V_24 = F_121 ( V_82 , V_176 ) ;
if ( V_158 -> V_213 >= 0 )
return 0 ;
switch ( V_158 -> V_213 ) {
case - V_264 :
case - V_245 :
case - V_247 :
case - V_246 :
case - V_265 :
case - V_266 :
break;
case - V_267 :
F_135 ( V_82 -> V_122 -> V_45 , V_268 ) ;
goto V_269;
default:
F_12 ( L_20 , V_22 ,
V_158 -> V_213 ) ;
F_130 ( V_24 ) ;
}
return - V_258 ;
V_269:
V_158 -> V_213 = 0 ;
F_136 ( V_158 ) ;
F_126 ( V_158 , V_270 ) ;
return - V_260 ;
}
static int F_137 ( struct V_157 * V_158 ,
struct V_214 * V_215 ,
struct V_216 * V_217 ,
struct V_73 * V_82 ,
int V_176 )
{
int V_271 = V_217 -> V_272 -> V_273 -> V_274 ;
switch ( V_271 ) {
case 3 :
return F_134 ( V_158 , V_82 , V_176 ) ;
case 4 :
return F_120 ( V_158 , V_215 , V_217 ,
V_82 , V_176 ) ;
default:
F_82 ( 1 ) ;
return 0 ;
}
}
static void F_138 ( struct V_73 * V_82 ,
int V_176 , T_5 V_63 , T_5 V_64 ,
T_4 V_197 , int V_275 , int error )
{
struct V_34 * V_42 ;
int V_11 ;
if ( V_197 == 0 ) {
switch ( error ) {
case - V_256 :
case - V_276 :
case - V_277 :
case - V_278 :
case - V_252 :
case - V_279 :
case - V_253 :
case - V_254 :
case - V_255 :
case - V_280 :
case - V_19 :
case - V_257 :
case - V_281 :
V_197 = V_282 ;
break;
case - V_264 :
V_197 = V_283 ;
break;
default:
return;
}
}
switch ( V_197 ) {
case V_240 :
case V_241 :
return;
default:
break;
}
V_42 = F_106 ( V_82 , V_176 ) ;
V_11 = F_139 ( F_8 ( V_82 -> V_122 ) ,
V_42 , V_63 , V_64 , V_197 , V_275 ,
V_161 ) ;
F_140 ( V_82 -> V_122 -> V_45 , V_82 ) ;
F_12 ( L_22 , V_22 , V_11 , V_275 , V_197 ) ;
}
static int F_141 ( struct V_157 * V_158 ,
struct V_203 * V_204 )
{
int V_11 ;
F_142 ( V_204 , V_158 -> V_213 ) ;
if ( V_158 -> V_213 < 0 )
F_138 ( V_204 -> V_82 , V_204 -> V_284 ,
V_204 -> args . V_63 , V_204 -> args . V_209 ,
V_204 -> V_285 . V_286 , V_287 ,
V_158 -> V_213 ) ;
V_11 = F_137 ( V_158 , V_204 -> args . V_288 -> V_215 ,
V_204 -> V_289 , V_204 -> V_82 ,
V_204 -> V_284 ) ;
switch ( V_11 ) {
case - V_258 :
if ( F_98 ( V_204 -> V_82 ,
V_204 -> V_284 + 1 ,
& V_204 -> V_284 ) )
goto V_290;
F_143 ( V_204 ) ;
return V_158 -> V_213 ;
case - V_259 :
F_118 ( V_204 ) ;
return V_158 -> V_213 ;
case - V_260 :
goto V_290;
}
return 0 ;
V_290:
F_136 ( V_158 ) ;
return - V_260 ;
}
static bool
F_144 ( struct V_73 * V_82 )
{
return ! ( F_76 ( V_82 ) -> V_88 & V_291 ) ;
}
static void
F_145 ( struct V_203 * V_204 )
{
if ( ! F_144 ( V_204 -> V_82 ) )
return;
F_146 ( V_204 -> V_2 , V_204 -> V_82 ,
V_204 -> V_292 + V_204 -> V_285 . V_209 ) ;
F_12 ( L_23 , V_22 , V_204 -> V_2 -> V_293 ,
( unsigned long ) F_128 ( V_204 -> V_2 ) -> V_49 -> V_294 ) ;
}
static bool
F_147 ( struct V_73 * V_82 , int V_176 )
{
struct V_86 * V_87 = F_121 ( V_82 , V_176 ) ;
return F_148 ( V_87 ) ;
}
static void F_149 ( struct V_157 * V_158 ,
struct V_203 * V_204 )
{
if ( F_116 ( V_295 , & V_204 -> V_88 ) )
return;
F_90 ( V_204 -> V_2 ,
F_106 ( V_204 -> V_82 , V_204 -> V_284 ) ,
V_204 -> args . V_209 ,
V_158 -> V_159 ) ;
}
static void F_150 ( struct V_157 * V_158 ,
struct V_203 * V_204 )
{
if ( ! F_151 ( V_295 , & V_204 -> V_88 ) )
return;
F_92 ( V_158 ,
F_106 ( V_204 -> V_82 , V_204 -> V_284 ) ,
V_204 -> args . V_209 ,
V_204 -> V_285 . V_209 ) ;
}
static int F_152 ( struct V_157 * V_158 ,
struct V_203 * V_204 )
{
if ( F_11 ( F_44 ( V_296 , & V_204 -> args . V_288 -> V_88 ) ) ) {
F_153 ( V_158 , - V_104 ) ;
return - V_104 ;
}
if ( F_147 ( V_204 -> V_82 , V_204 -> V_284 ) ) {
F_153 ( V_158 , - V_253 ) ;
return - V_260 ;
}
F_149 ( V_158 , V_204 ) ;
return 0 ;
}
static void F_154 ( struct V_157 * V_158 , void * V_21 )
{
struct V_203 * V_204 = V_21 ;
if ( F_152 ( V_158 , V_204 ) )
return;
F_155 ( V_158 ) ;
}
static int F_156 ( struct V_216 * V_289 ,
struct V_297 * args ,
struct V_298 * V_285 ,
struct V_157 * V_158 )
{
if ( V_289 -> V_223 )
return F_157 ( V_289 -> V_223 ,
args ,
V_285 ,
V_158 ) ;
return F_158 ( V_289 -> V_299 ,
args ,
V_285 ,
V_158 ) ;
}
static void F_159 ( struct V_157 * V_158 , void * V_21 )
{
struct V_203 * V_204 = V_21 ;
if ( F_156 ( V_204 -> V_289 ,
& V_204 -> args . V_300 ,
& V_204 -> V_285 . V_301 ,
V_158 ) )
return;
if ( F_152 ( V_158 , V_204 ) )
return;
if ( F_160 ( & V_204 -> args . V_16 , V_204 -> args . V_288 ,
V_204 -> args . V_302 , V_303 ) == - V_104 )
F_153 ( V_158 , - V_104 ) ;
}
static void F_161 ( struct V_157 * V_158 , void * V_21 )
{
struct V_203 * V_204 = V_21 ;
F_12 ( L_24 , V_22 , V_158 -> V_213 ) ;
if ( F_44 ( V_212 , & V_204 -> V_88 ) &&
V_158 -> V_213 == 0 ) {
F_162 ( V_158 , & V_204 -> V_285 . V_301 ) ;
return;
}
V_204 -> V_304 -> V_305 ( V_158 , V_204 ) ;
}
static void F_163 ( struct V_157 * V_158 , void * V_21 )
{
struct V_203 * V_204 = V_21 ;
F_150 ( V_158 , V_204 ) ;
F_164 ( V_158 ,
& F_165 ( V_204 -> V_2 ) -> V_306 [ V_307 ] ) ;
}
static void F_166 ( void * V_21 )
{
struct V_203 * V_204 = V_21 ;
F_150 ( & V_204 -> V_158 , V_204 ) ;
F_167 ( V_21 ) ;
}
static int F_168 ( struct V_157 * V_158 ,
struct V_203 * V_204 )
{
int V_11 ;
F_169 ( V_204 , V_158 -> V_213 ) ;
if ( V_158 -> V_213 < 0 )
F_138 ( V_204 -> V_82 , V_204 -> V_284 ,
V_204 -> args . V_63 , V_204 -> args . V_209 ,
V_204 -> V_285 . V_286 , V_308 ,
V_158 -> V_213 ) ;
V_11 = F_137 ( V_158 , V_204 -> args . V_288 -> V_215 ,
V_204 -> V_289 , V_204 -> V_82 ,
V_204 -> V_284 ) ;
switch ( V_11 ) {
case - V_258 :
F_113 ( V_204 , true ) ;
return V_158 -> V_213 ;
case - V_259 :
F_113 ( V_204 , false ) ;
return V_158 -> V_213 ;
case - V_260 :
return - V_260 ;
}
if ( V_204 -> V_285 . V_309 -> V_163 == V_310 ||
V_204 -> V_285 . V_309 -> V_163 == V_311 )
F_145 ( V_204 ) ;
V_204 -> V_312 . V_313 = 0 ;
if ( V_158 -> V_213 >= 0 )
F_170 ( V_204 ) ;
return 0 ;
}
static int F_171 ( struct V_157 * V_158 ,
struct V_314 * V_21 )
{
int V_11 ;
F_172 ( V_21 , V_158 -> V_213 ) ;
if ( V_158 -> V_213 < 0 )
F_138 ( V_21 -> V_82 , V_21 -> V_315 ,
V_21 -> args . V_63 , V_21 -> args . V_209 ,
V_21 -> V_285 . V_286 , V_316 ,
V_158 -> V_213 ) ;
V_11 = F_137 ( V_158 , NULL , V_21 -> V_289 ,
V_21 -> V_82 , V_21 -> V_315 ) ;
switch ( V_11 ) {
case - V_258 :
F_173 ( V_21 ) ;
return - V_260 ;
case - V_259 :
F_173 ( V_21 ) ;
return - V_260 ;
case - V_260 :
F_136 ( V_158 ) ;
return - V_260 ;
}
if ( V_21 -> V_309 . V_163 == V_164
&& F_144 ( V_21 -> V_82 ) )
F_146 ( V_21 -> V_2 , V_21 -> V_82 , V_21 -> V_317 ) ;
return 0 ;
}
static void F_174 ( struct V_157 * V_158 ,
struct V_203 * V_204 )
{
if ( F_116 ( V_295 , & V_204 -> V_88 ) )
return;
F_94 ( V_204 -> V_2 ,
F_106 ( V_204 -> V_82 , V_204 -> V_284 ) ,
V_204 -> args . V_209 ,
V_158 -> V_159 ) ;
}
static void F_175 ( struct V_157 * V_158 ,
struct V_203 * V_204 )
{
if ( ! F_151 ( V_295 , & V_204 -> V_88 ) )
return;
F_95 ( V_158 ,
F_106 ( V_204 -> V_82 , V_204 -> V_284 ) ,
V_204 -> args . V_209 , V_204 -> V_285 . V_209 ,
V_204 -> V_285 . V_309 -> V_163 ) ;
}
static int F_176 ( struct V_157 * V_158 ,
struct V_203 * V_204 )
{
if ( F_11 ( F_44 ( V_296 , & V_204 -> args . V_288 -> V_88 ) ) ) {
F_153 ( V_158 , - V_104 ) ;
return - V_104 ;
}
if ( F_147 ( V_204 -> V_82 , V_204 -> V_284 ) ) {
F_153 ( V_158 , - V_253 ) ;
return - V_260 ;
}
F_174 ( V_158 , V_204 ) ;
return 0 ;
}
static void F_177 ( struct V_157 * V_158 , void * V_21 )
{
struct V_203 * V_204 = V_21 ;
if ( F_176 ( V_158 , V_204 ) )
return;
F_155 ( V_158 ) ;
}
static void F_178 ( struct V_157 * V_158 , void * V_21 )
{
struct V_203 * V_204 = V_21 ;
if ( F_156 ( V_204 -> V_289 ,
& V_204 -> args . V_300 ,
& V_204 -> V_285 . V_301 ,
V_158 ) )
return;
if ( F_176 ( V_158 , V_204 ) )
return;
if ( F_160 ( & V_204 -> args . V_16 , V_204 -> args . V_288 ,
V_204 -> args . V_302 , V_318 ) == - V_104 )
F_153 ( V_158 , - V_104 ) ;
}
static void F_179 ( struct V_157 * V_158 , void * V_21 )
{
struct V_203 * V_204 = V_21 ;
if ( F_44 ( V_212 , & V_204 -> V_88 ) &&
V_158 -> V_213 == 0 ) {
F_162 ( V_158 , & V_204 -> V_285 . V_301 ) ;
return;
}
V_204 -> V_304 -> V_305 ( V_158 , V_204 ) ;
}
static void F_180 ( struct V_157 * V_158 , void * V_21 )
{
struct V_203 * V_204 = V_21 ;
F_175 ( V_158 , V_204 ) ;
F_164 ( V_158 ,
& F_165 ( V_204 -> V_2 ) -> V_306 [ V_319 ] ) ;
}
static void F_181 ( void * V_21 )
{
struct V_203 * V_204 = V_21 ;
F_175 ( & V_204 -> V_158 , V_204 ) ;
F_167 ( V_21 ) ;
}
static void F_182 ( struct V_157 * V_158 ,
struct V_314 * V_320 )
{
if ( F_116 ( V_295 , & V_320 -> V_88 ) )
return;
F_94 ( V_320 -> V_2 ,
F_106 ( V_320 -> V_82 , V_320 -> V_315 ) ,
0 , V_158 -> V_159 ) ;
}
static void F_183 ( struct V_157 * V_158 ,
struct V_314 * V_320 )
{
struct V_179 * V_180 ;
T_9 V_209 = 0 ;
if ( ! F_151 ( V_295 , & V_320 -> V_88 ) )
return;
if ( V_158 -> V_213 == 0 ) {
F_24 (req, &cdata->pages, wb_list)
V_209 += V_180 -> V_321 ;
}
F_95 ( V_158 ,
F_106 ( V_320 -> V_82 , V_320 -> V_315 ) ,
V_209 , V_209 , V_310 ) ;
}
static void F_184 ( struct V_157 * V_158 ,
struct V_314 * V_320 )
{
F_182 ( V_158 , V_320 ) ;
}
static void F_185 ( struct V_157 * V_158 , void * V_21 )
{
F_184 ( V_158 , V_21 ) ;
F_155 ( V_158 ) ;
}
static void F_186 ( struct V_157 * V_158 , void * V_21 )
{
struct V_314 * V_322 = V_21 ;
if ( F_156 ( V_322 -> V_289 ,
& V_322 -> args . V_300 ,
& V_322 -> V_285 . V_301 ,
V_158 ) )
return;
F_184 ( V_158 , V_21 ) ;
}
static void F_187 ( struct V_157 * V_158 , void * V_21 )
{
F_188 ( V_158 , V_21 ) ;
}
static void F_189 ( struct V_157 * V_158 , void * V_21 )
{
struct V_314 * V_320 = V_21 ;
F_183 ( V_158 , V_320 ) ;
F_164 ( V_158 ,
& F_165 ( V_320 -> V_2 ) -> V_306 [ V_323 ] ) ;
}
static void F_190 ( void * V_21 )
{
struct V_314 * V_320 = V_21 ;
F_183 ( & V_320 -> V_158 , V_320 ) ;
F_191 ( V_21 ) ;
}
static enum V_324
F_192 ( struct V_203 * V_204 )
{
struct V_73 * V_82 = V_204 -> V_82 ;
struct V_173 * V_168 ;
struct V_325 * V_326 ;
struct V_51 * V_327 ;
T_10 V_63 = V_204 -> args . V_63 ;
T_4 V_176 = V_204 -> V_284 ;
int V_271 ;
struct V_26 * V_27 ;
F_12 ( L_25 ,
V_22 , V_204 -> V_2 -> V_293 ,
V_204 -> args . V_328 , ( V_329 ) V_204 -> args . V_209 , V_63 ) ;
V_168 = F_99 ( V_82 , V_176 , false ) ;
if ( ! V_168 )
goto V_330;
V_326 = F_193 ( V_82 , V_176 , V_168 -> V_289 ,
V_204 -> V_2 ) ;
if ( F_68 ( V_326 ) )
goto V_330;
V_327 = F_194 ( V_82 , V_176 , V_204 -> V_52 ) ;
if ( ! V_327 )
goto V_330;
V_271 = F_195 ( V_82 , V_176 ) ;
F_12 ( L_26 , V_22 ,
V_168 -> V_331 , F_196 ( & V_168 -> V_289 -> V_332 ) , V_271 ) ;
V_204 -> V_333 = F_141 ;
F_197 ( & V_168 -> V_289 -> V_332 ) ;
V_204 -> V_289 = V_168 -> V_289 ;
V_27 = F_198 ( V_82 , V_176 ) ;
if ( V_27 )
V_204 -> args . V_27 = V_27 ;
V_204 -> args . V_63 = V_63 ;
V_204 -> V_292 = V_63 ;
F_199 ( V_326 , V_204 , V_327 , V_168 -> V_289 -> V_334 ,
V_271 == 3 ? & V_335 :
& V_336 ,
0 , V_337 ) ;
F_34 ( V_327 ) ;
return V_338 ;
V_330:
if ( F_131 ( V_82 ) )
return V_339 ;
return V_340 ;
}
static enum V_324
F_200 ( struct V_203 * V_204 , int V_341 )
{
struct V_73 * V_82 = V_204 -> V_82 ;
struct V_173 * V_168 ;
struct V_325 * V_326 ;
struct V_51 * V_327 ;
T_10 V_63 = V_204 -> args . V_63 ;
int V_271 ;
struct V_26 * V_27 ;
int V_176 = V_204 -> V_284 ;
V_168 = F_99 ( V_82 , V_176 , true ) ;
if ( ! V_168 )
return V_340 ;
V_326 = F_193 ( V_82 , V_176 , V_168 -> V_289 ,
V_204 -> V_2 ) ;
if ( F_68 ( V_326 ) )
return V_340 ;
V_327 = F_194 ( V_82 , V_176 , V_204 -> V_52 ) ;
if ( ! V_327 )
return V_340 ;
V_271 = F_195 ( V_82 , V_176 ) ;
F_12 ( L_27 ,
V_22 , V_204 -> V_2 -> V_293 , V_341 , ( V_329 ) V_204 -> args . V_209 ,
V_63 , V_168 -> V_331 , F_196 ( & V_168 -> V_289 -> V_332 ) ,
V_271 ) ;
V_204 -> V_333 = F_168 ;
F_197 ( & V_168 -> V_289 -> V_332 ) ;
V_204 -> V_289 = V_168 -> V_289 ;
V_204 -> V_342 = V_176 ;
V_27 = F_198 ( V_82 , V_176 ) ;
if ( V_27 )
V_204 -> args . V_27 = V_27 ;
V_204 -> args . V_63 = V_63 ;
F_199 ( V_326 , V_204 , V_327 , V_168 -> V_289 -> V_334 ,
V_271 == 3 ? & V_343 :
& V_344 ,
V_341 , V_337 ) ;
F_34 ( V_327 ) ;
return V_338 ;
}
static T_4 F_201 ( struct V_73 * V_82 , T_4 V_37 )
{
return V_37 ;
}
static struct V_26 *
F_202 ( struct V_73 * V_82 , T_4 V_37 )
{
struct V_55 * V_345 = F_76 ( V_82 ) ;
return & V_345 -> V_57 [ V_37 ] -> V_41 [ 0 ] ;
}
static int F_203 ( struct V_314 * V_21 , int V_346 )
{
struct V_73 * V_82 = V_21 -> V_82 ;
struct V_173 * V_168 ;
struct V_325 * V_326 ;
struct V_51 * V_327 ;
T_4 V_176 ;
int V_271 , V_61 ;
struct V_26 * V_27 ;
V_176 = F_201 ( V_82 , V_21 -> V_315 ) ;
V_168 = F_99 ( V_82 , V_176 , true ) ;
if ( ! V_168 )
goto V_347;
V_326 = F_193 ( V_82 , V_176 , V_168 -> V_289 ,
V_21 -> V_2 ) ;
if ( F_68 ( V_326 ) )
goto V_347;
V_327 = F_194 ( V_82 , V_176 , V_21 -> V_52 ) ;
if ( ! V_327 )
goto V_347;
V_271 = F_195 ( V_82 , V_176 ) ;
F_12 ( L_28 , V_22 ,
V_21 -> V_2 -> V_293 , V_346 , F_196 ( & V_168 -> V_289 -> V_332 ) ,
V_271 ) ;
V_21 -> V_348 = F_171 ;
V_21 -> V_52 = V_327 ;
F_197 ( & V_168 -> V_289 -> V_332 ) ;
V_21 -> V_289 = V_168 -> V_289 ;
V_27 = F_202 ( V_82 , V_21 -> V_315 ) ;
if ( V_27 )
V_21 -> args . V_27 = V_27 ;
V_61 = F_204 ( V_326 , V_21 , V_168 -> V_289 -> V_334 ,
V_271 == 3 ? & V_349 :
& V_350 ,
V_346 , V_337 ) ;
F_34 ( V_327 ) ;
return V_61 ;
V_347:
F_173 ( V_21 ) ;
F_191 ( V_21 ) ;
return - V_260 ;
}
static int
F_205 ( struct V_2 * V_2 , struct V_83 * V_351 ,
int V_346 , struct V_165 * V_166 )
{
return F_206 ( V_2 , V_351 , V_346 , V_166 ,
F_203 ) ;
}
static struct V_352 *
F_207 ( struct V_2 * V_2 )
{
struct V_1 * V_49 = F_128 ( V_2 ) -> V_49 ;
if ( V_49 == NULL )
return NULL ;
return & F_8 ( V_49 ) -> V_123 ;
}
static void
F_208 ( struct V_86 * V_353 )
{
F_209 ( F_210 ( V_353 , struct V_354 ,
V_90 ) ) ;
}
static int F_211 ( struct V_4 * V_355 ,
struct V_14 * V_15 ,
const struct V_356 * args )
{
struct V_1 * V_204 = & V_355 -> V_8 ;
T_3 * V_131 ;
int V_209 = 0 , V_61 = 0 ;
V_131 = F_212 ( V_15 , 4 ) ;
if ( F_11 ( ! V_131 ) )
return - V_357 ;
F_23 ( & V_204 -> V_45 -> V_46 ) ;
V_61 = F_213 ( V_355 , V_15 , & V_209 , & args -> V_62 ) ;
F_26 ( & V_204 -> V_45 -> V_46 ) ;
* V_131 = F_214 ( V_209 ) ;
return V_61 ;
}
static void F_215 ( struct V_4 * V_355 ,
struct V_14 * V_15 ,
const struct V_356 * args )
{
T_3 * V_17 ;
V_17 = F_212 ( V_15 , 4 ) ;
if ( F_216 ( V_17 ) )
* V_17 = F_214 ( 0 ) ;
}
static struct V_86 *
F_217 ( struct V_218 * V_358 ,
struct V_359 * V_360 , T_1 V_3 )
{
struct V_354 * V_361 ;
V_361 = F_218 ( V_358 , V_360 , V_3 ) ;
if ( ! V_361 )
return NULL ;
return & V_361 -> V_90 ;
}
static void
F_219 ( struct V_1 * V_9 ,
struct V_14 * V_15 ,
const struct V_356 * args )
{
struct V_4 * V_355 = F_8 ( V_9 ) ;
T_3 * V_131 ;
F_12 ( L_29 , V_22 ) ;
V_131 = F_212 ( V_15 , 4 ) ;
F_220 ( ! V_131 ) ;
F_211 ( V_355 , V_15 , args ) ;
F_215 ( V_355 , V_15 , args ) ;
* V_131 = F_214 ( ( V_15 -> V_17 - V_131 - 1 ) * 4 ) ;
F_12 ( L_30 , V_22 ) ;
}
static int
F_221 ( const struct V_362 * V_363 , char * V_95 , const V_329 V_364 )
{
const struct V_365 * sin = (struct V_365 * ) V_363 ;
return snprintf ( V_95 , V_364 , L_31 , & sin -> V_366 ) ;
}
static V_329
F_222 ( const struct V_362 * V_363 , char * V_95 ,
const int V_364 )
{
const struct V_367 * V_368 = (struct V_367 * ) V_363 ;
const struct V_369 * V_370 = & V_368 -> V_371 ;
if ( F_223 ( V_370 ) )
return snprintf ( V_95 , V_364 , L_32 ) ;
if ( F_224 ( V_370 ) )
return snprintf ( V_95 , V_364 , L_33 ) ;
if ( F_225 ( V_370 ) )
return snprintf ( V_95 , V_364 , L_34 ,
& V_370 -> V_372 [ 3 ] ) ;
return snprintf ( V_95 , V_364 , L_35 , V_370 ) ;
}
static void
F_226 ( struct V_14 * V_15 , struct V_373 * V_374 )
{
struct V_362 * V_363 = (struct V_362 * ) & V_374 -> V_375 ;
char V_376 [ V_377 ] ;
char V_378 [ V_379 ] ;
char * V_380 ;
unsigned short V_381 ;
int V_32 , V_382 ;
T_3 * V_17 ;
switch ( V_363 -> V_383 ) {
case V_384 :
if ( F_221 ( V_363 , V_378 , sizeof( V_378 ) ) == 0 )
return;
V_381 = F_227 ( ( (struct V_365 * ) V_363 ) -> V_385 ) ;
V_380 = L_36 ;
V_382 = 3 ;
break;
case V_386 :
if ( F_222 ( V_363 , V_378 , sizeof( V_378 ) ) == 0 )
return;
V_381 = F_227 ( ( (struct V_367 * ) V_363 ) -> V_387 ) ;
V_380 = L_37 ;
V_382 = 4 ;
break;
default:
F_82 ( 1 ) ;
return;
}
snprintf ( V_376 , sizeof( V_376 ) , L_38 , V_381 >> 8 , V_381 & 0xff ) ;
V_32 = F_228 ( V_378 , V_376 , sizeof( V_378 ) ) ;
V_17 = F_212 ( V_15 , 4 + V_382 ) ;
F_229 ( V_17 , V_380 , V_382 ) ;
V_17 = F_212 ( V_15 , 4 + V_32 ) ;
F_229 ( V_17 , V_378 , V_32 ) ;
}
static void
F_230 ( struct V_14 * V_15 ,
T_7 V_388 )
{
struct V_389 V_390 ;
T_3 * V_17 ;
V_17 = F_212 ( V_15 , 12 ) ;
V_390 = F_231 ( V_388 ) ;
V_17 = F_232 ( V_17 , V_390 . V_391 ) ;
* V_17 ++ = F_214 ( V_390 . V_392 ) ;
}
static void
F_233 ( struct V_14 * V_15 ,
struct V_140 * V_393 )
{
T_3 * V_17 ;
V_17 = F_212 ( V_15 , 5 * 8 ) ;
V_17 = F_232 ( V_17 , V_393 -> V_143 ) ;
V_17 = F_232 ( V_17 , V_393 -> V_144 ) ;
V_17 = F_232 ( V_17 , V_393 -> V_149 ) ;
V_17 = F_232 ( V_17 , V_393 -> V_150 ) ;
V_17 = F_232 ( V_17 , V_393 -> V_151 ) ;
F_230 ( V_15 , V_393 -> V_152 ) ;
F_230 ( V_15 , V_393 -> V_153 ) ;
}
static void
F_234 ( struct V_14 * V_15 ,
struct V_394 * args ,
struct V_395 * V_396 )
{
struct V_34 * V_42 = V_396 -> V_397 ;
struct V_373 * V_374 ;
struct V_173 * V_168 = V_42 -> V_47 -> V_168 ;
struct V_26 * V_27 = & V_42 -> V_41 [ 0 ] ;
T_3 * V_17 , * V_131 ;
V_374 = F_235 ( & V_168 -> V_398 , struct V_373 , V_399 ) ;
F_12 ( L_39 ,
V_22 , V_168 -> V_331 , V_374 -> V_400 ) ;
V_131 = F_212 ( V_15 , 4 ) ;
F_226 ( V_15 , V_374 ) ;
V_17 = F_212 ( V_15 , 4 + V_27 -> V_28 ) ;
F_229 ( V_17 , V_27 -> V_21 , V_27 -> V_28 ) ;
F_23 ( & V_42 -> V_50 ) ;
F_233 ( V_15 , & V_42 -> V_155 . V_142 ) ;
F_233 ( V_15 , & V_42 -> V_160 . V_142 ) ;
F_26 ( & V_42 -> V_50 ) ;
F_230 ( V_15 , F_83 ( F_93 () , V_42 -> V_130 ) ) ;
V_17 = F_212 ( V_15 , 4 ) ;
* V_17 = F_214 ( false ) ;
* V_131 = F_214 ( ( V_15 -> V_17 - V_131 - 1 ) * 4 ) ;
}
static int
F_236 ( struct V_394 * args ,
struct V_1 * V_9 ,
int V_401 )
{
struct V_4 * V_43 = F_8 ( V_9 ) ;
struct V_34 * V_42 ;
struct V_86 * V_402 ;
struct V_395 * V_396 ;
int V_37 = 0 ;
F_24 (mirror, &ff_layout->mirrors, mirrors) {
if ( V_37 >= V_401 )
break;
if ( ! V_42 -> V_47 )
continue;
if ( ! F_25 ( & V_42 -> V_48 ) )
continue;
V_402 = & V_42 -> V_47 -> V_90 ;
V_396 = & args -> V_396 [ V_37 ] ;
memcpy ( & V_396 -> V_403 , & V_402 -> V_404 , V_25 ) ;
V_396 -> V_63 = 0 ;
V_396 -> V_64 = V_65 ;
V_396 -> V_405 = V_42 -> V_155 . V_142 . V_149 ;
V_396 -> V_406 = V_42 -> V_155 . V_142 . V_150 ;
V_396 -> V_407 = V_42 -> V_160 . V_142 . V_149 ;
V_396 -> V_408 = V_42 -> V_160 . V_142 . V_150 ;
V_396 -> V_409 = V_410 ;
V_396 -> V_411 = F_234 ;
V_396 -> V_397 = V_42 ;
V_37 ++ ;
}
return V_37 ;
}
static int
F_237 ( struct V_394 * args )
{
struct V_4 * V_43 ;
struct V_34 * V_42 ;
int V_412 = 0 ;
F_23 ( & args -> V_2 -> V_46 ) ;
V_43 = F_8 ( F_128 ( args -> V_2 ) -> V_49 ) ;
F_24 (mirror, &ff_layout->mirrors, mirrors) {
if ( F_196 ( & V_42 -> V_48 ) != 0 )
V_412 ++ ;
}
F_26 ( & args -> V_2 -> V_46 ) ;
if ( V_412 > V_413 ) {
F_12 ( L_40 ,
V_22 , V_412 , V_413 ) ;
V_412 = V_413 ;
}
args -> V_396 = F_238 ( V_412 , sizeof( * args -> V_396 ) , V_161 ) ;
if ( ! args -> V_396 )
return - V_100 ;
F_23 ( & args -> V_2 -> V_46 ) ;
args -> V_414 = F_236 ( args ,
& V_43 -> V_8 , V_412 ) ;
F_26 ( & args -> V_2 -> V_46 ) ;
return 0 ;
}
static void
F_239 ( struct V_415 * V_21 )
{
struct V_34 * V_42 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_21 -> args . V_414 ; V_37 ++ ) {
V_42 = V_21 -> args . V_396 [ V_37 ] . V_397 ;
V_21 -> args . V_396 [ V_37 ] . V_397 = NULL ;
F_36 ( V_42 ) ;
}
}
static int T_11 F_240 ( void )
{
F_17 ( V_416 L_41 ,
V_22 ) ;
if ( ! V_111 ) {
V_111 = F_241 ( 0 ) ;
if ( ! V_111 )
return - V_100 ;
}
return F_242 ( & V_417 ) ;
}
static void T_12 F_243 ( void )
{
F_17 ( V_416 L_42 ,
V_22 ) ;
F_244 ( & V_417 ) ;
if ( V_111 ) {
F_245 ( V_111 ) ;
V_111 = NULL ;
}
}
