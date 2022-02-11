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
if ( memcmp ( & V_43 -> V_25 , & V_45 -> V_25 , sizeof( V_45 -> V_25 ) ) != 0 )
continue;
if ( ! F_21 ( V_43 , V_45 ) )
continue;
if ( F_26 ( & V_45 -> V_48 ) ) {
F_27 ( & V_2 -> V_47 ) ;
return V_45 ;
}
}
F_28 ( & V_43 -> V_7 , & V_44 -> V_7 ) ;
V_43 -> V_49 = V_10 ;
F_27 ( & V_2 -> V_47 ) ;
return V_43 ;
}
static void
F_29 ( struct V_35 * V_43 )
{
struct V_2 * V_2 ;
if ( V_43 -> V_49 == NULL )
return;
V_2 = V_43 -> V_49 -> V_46 ;
F_24 ( & V_2 -> V_47 ) ;
F_7 ( & V_43 -> V_7 ) ;
F_27 ( & V_2 -> V_47 ) ;
V_43 -> V_49 = NULL ;
}
static struct V_35 * F_30 ( T_1 V_3 )
{
struct V_35 * V_43 ;
V_43 = F_2 ( sizeof( * V_43 ) , V_3 ) ;
if ( V_43 != NULL ) {
F_31 ( & V_43 -> V_50 ) ;
F_32 ( & V_43 -> V_48 , 1 ) ;
F_3 ( & V_43 -> V_7 ) ;
}
return V_43 ;
}
static void F_33 ( struct V_35 * V_43 )
{
struct V_51 * V_52 ;
F_29 ( V_43 ) ;
F_8 ( V_43 -> V_42 ) ;
V_52 = F_34 ( V_43 -> V_53 ) ;
if ( V_52 )
F_35 ( V_52 ) ;
V_52 = F_34 ( V_43 -> V_54 ) ;
if ( V_52 )
F_35 ( V_52 ) ;
F_36 ( V_43 -> V_55 ) ;
F_8 ( V_43 ) ;
}
static void F_37 ( struct V_35 * V_43 )
{
if ( V_43 != NULL && F_38 ( & V_43 -> V_48 ) )
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
static struct V_74 *
F_52 ( struct V_1 * V_87 ,
struct V_60 * V_61 ,
T_1 V_3 )
{
struct V_74 * V_62 ;
struct V_56 * V_57 = NULL ;
struct V_15 V_88 ;
struct V_89 V_90 ;
struct V_91 * V_92 ;
T_5 V_93 ;
T_4 V_59 ;
T_3 * V_18 ;
int V_38 , V_94 ;
F_13 ( L_5 , V_23 ) ;
V_92 = F_53 ( V_3 ) ;
if ( ! V_92 )
return F_54 ( - V_95 ) ;
F_55 ( & V_88 , & V_90 , V_61 -> V_96 -> V_97 ,
V_61 -> V_96 -> V_33 ) ;
F_56 ( & V_88 , F_57 ( V_92 ) , V_98 ) ;
V_94 = - V_99 ;
V_18 = F_11 ( & V_88 , 8 + 4 ) ;
if ( ! V_18 )
goto V_100;
V_18 = F_58 ( V_18 , & V_93 ) ;
V_59 = F_17 ( V_18 ++ ) ;
F_13 ( L_8 , V_23 ,
V_93 , V_59 ) ;
if ( V_59 > V_101 ||
V_59 == 0 )
goto V_100;
V_94 = - V_95 ;
V_57 = F_2 ( sizeof( * V_57 ) , V_3 ) ;
if ( ! V_57 )
goto V_100;
V_57 -> V_59 = V_59 ;
V_57 -> V_93 = V_93 ;
V_57 -> V_58 = F_59 ( V_57 -> V_59 ,
sizeof( V_57 -> V_58 [ 0 ] ) , V_3 ) ;
if ( V_57 -> V_58 == NULL )
goto V_100;
for ( V_38 = 0 ; V_38 < V_57 -> V_59 ; V_38 ++ ) {
struct V_35 * V_43 ;
struct V_102 V_103 = { . V_104 = V_105 } ;
struct V_51 T_6 * V_52 ;
T_4 V_106 , V_107 , V_32 ;
int V_39 ;
V_94 = - V_99 ;
V_18 = F_11 ( & V_88 , 4 ) ;
if ( ! V_18 )
goto V_100;
V_106 = F_17 ( V_18 ) ;
if ( V_106 != 1 )
goto V_100;
V_57 -> V_58 [ V_38 ] = F_30 ( V_3 ) ;
if ( V_57 -> V_58 [ V_38 ] == NULL ) {
V_94 = - V_95 ;
goto V_100;
}
V_57 -> V_58 [ V_38 ] -> V_106 = V_106 ;
V_94 = F_14 ( & V_88 , & V_57 -> V_58 [ V_38 ] -> V_25 ) ;
if ( V_94 )
goto V_100;
V_94 = - V_99 ;
V_18 = F_11 ( & V_88 , 4 ) ;
if ( ! V_18 )
goto V_100;
V_57 -> V_58 [ V_38 ] -> V_86 = F_17 ( V_18 ) ;
V_94 = F_10 ( & V_88 , & V_57 -> V_58 [ V_38 ] -> V_17 ) ;
if ( V_94 )
goto V_100;
V_94 = - V_99 ;
V_18 = F_11 ( & V_88 , 4 ) ;
if ( ! V_18 )
goto V_100;
V_107 = F_17 ( V_18 ) ;
V_57 -> V_58 [ V_38 ] -> V_42 =
F_2 ( V_107 * sizeof( struct V_27 ) ,
V_3 ) ;
if ( V_57 -> V_58 [ V_38 ] -> V_42 == NULL ) {
V_94 = - V_95 ;
goto V_100;
}
for ( V_39 = 0 ; V_39 < V_107 ; V_39 ++ ) {
V_94 = F_16 ( & V_88 ,
& V_57 -> V_58 [ V_38 ] -> V_42 [ V_39 ] ) ;
if ( V_94 )
goto V_100;
}
V_57 -> V_58 [ V_38 ] -> V_40 = V_107 ;
V_94 = F_19 ( & V_88 , & V_32 ) ;
if ( V_94 )
goto V_100;
V_103 . V_108 = F_60 ( & V_109 , V_32 ) ;
V_94 = F_19 ( & V_88 , & V_32 ) ;
if ( V_94 )
goto V_100;
V_103 . V_110 = F_61 ( & V_109 , V_32 ) ;
F_62 ( V_52 , F_63 ( & V_103 , 0 , V_3 ) ) ;
if ( F_64 ( V_52 ) ) {
V_94 = F_65 ( V_52 ) ;
goto V_100;
}
if ( V_61 -> V_63 . V_72 == V_73 )
F_62 ( V_57 -> V_58 [ V_38 ] -> V_53 , V_52 ) ;
else
F_62 ( V_57 -> V_58 [ V_38 ] -> V_54 , V_52 ) ;
V_43 = F_23 ( V_87 , V_57 -> V_58 [ V_38 ] ) ;
if ( V_43 != V_57 -> V_58 [ V_38 ] ) {
if ( V_61 -> V_63 . V_72 == V_73 ) {
V_52 = F_66 ( & V_43 -> V_53 , V_52 ) ;
F_62 ( V_57 -> V_58 [ V_38 ] -> V_53 , V_52 ) ;
} else {
V_52 = F_66 ( & V_43 -> V_54 , V_52 ) ;
F_62 ( V_57 -> V_58 [ V_38 ] -> V_54 , V_52 ) ;
}
F_33 ( V_57 -> V_58 [ V_38 ] ) ;
V_57 -> V_58 [ V_38 ] = V_43 ;
}
F_13 ( L_9 , V_23 ,
V_61 -> V_63 . V_72 == V_73 ? L_10 : L_11 ,
F_67 ( & V_109 , V_103 . V_108 ) ,
F_68 ( & V_109 , V_103 . V_110 ) ) ;
}
V_18 = F_11 ( & V_88 , 4 ) ;
if ( ! V_18 )
goto V_111;
V_57 -> V_112 = F_17 ( V_18 ) ;
V_18 = F_11 ( & V_88 , 4 ) ;
if ( ! V_18 )
goto V_111;
for ( V_38 = 0 ; V_38 < V_57 -> V_59 ; V_38 ++ )
V_57 -> V_58 [ V_38 ] -> V_113 = F_17 ( V_18 ) ;
V_111:
F_50 ( V_57 ) ;
V_94 = F_40 ( V_61 ) ;
if ( V_94 )
goto V_100;
V_62 = & V_57 -> V_9 ;
F_13 ( L_12 , V_23 ) ;
V_114:
F_69 ( V_92 ) ;
return V_62 ;
V_100:
F_41 ( V_57 ) ;
V_62 = F_54 ( V_94 ) ;
F_13 ( L_13 , V_23 , V_94 ) ;
goto V_114;
}
static bool F_70 ( struct V_1 * V_49 )
{
struct V_74 * V_83 ;
F_25 (lseg, &layout->plh_segs, pls_list)
if ( V_83 -> V_81 . V_72 == V_115 )
return true ;
return false ;
}
static void
F_71 ( struct V_74 * V_83 )
{
struct V_56 * V_57 = F_72 ( V_83 ) ;
F_13 ( L_5 , V_23 ) ;
if ( V_83 -> V_81 . V_72 == V_115 ) {
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_5 = F_9 ( V_83 -> V_116 ) ;
V_2 = V_5 -> V_9 . V_46 ;
F_24 ( & V_2 -> V_47 ) ;
if ( ! F_70 ( V_83 -> V_116 ) ) {
V_5 -> V_117 . V_118 = 0 ;
F_8 ( V_5 -> V_117 . V_119 ) ;
V_5 -> V_117 . V_119 = NULL ;
}
F_27 ( & V_2 -> V_47 ) ;
}
F_41 ( V_57 ) ;
}
static int
F_73 ( struct V_56 * V_57 )
{
return 1 ;
}
static void
F_74 ( struct V_120 * V_121 , T_7 V_122 )
{
if ( F_75 ( & V_121 -> V_123 ) == 1 ) {
V_121 -> V_124 = V_122 ;
}
}
static T_7
F_76 ( struct V_120 * V_121 , T_7 V_122 )
{
T_7 V_125 ;
if ( F_77 ( & V_121 -> V_123 ) < 0 )
F_78 ( 1 ) ;
V_125 = V_121 -> V_124 ;
V_121 -> V_124 = V_122 ;
return F_79 ( V_122 , V_125 ) ;
}
static bool
F_80 ( struct V_35 * V_43 ,
struct V_126 * V_127 ,
T_7 V_122 )
{
T_8 V_113 = V_128 ;
struct V_4 * V_5 = F_9 ( V_43 -> V_49 ) ;
F_74 ( & V_127 -> V_129 , V_122 ) ;
if ( ! V_43 -> V_124 )
V_43 -> V_124 = V_122 ;
if ( V_43 -> V_113 != 0 )
V_113 = ( T_8 ) V_43 -> V_113 * 1000LL ;
else if ( V_130 != 0 )
V_113 = ( T_8 ) V_130 * 1000LL ;
if ( F_81 ( F_79 ( V_122 , V_5 -> V_8 ) ) >=
V_113 ) {
V_5 -> V_8 = V_122 ;
return true ;
}
return false ;
}
static void
F_82 ( struct V_126 * V_127 ,
T_9 V_131 )
{
struct V_132 * V_133 = & V_127 -> V_134 ;
V_133 -> V_135 ++ ;
V_133 -> V_136 += V_131 ;
}
static void
F_83 ( struct V_126 * V_127 ,
T_9 V_131 ,
T_9 V_137 ,
T_7 V_138 ,
T_7 V_139 )
{
struct V_132 * V_133 = & V_127 -> V_134 ;
T_7 V_140 = F_79 ( V_138 , V_139 ) ;
T_7 V_121 ;
V_133 -> V_141 ++ ;
V_133 -> V_142 += V_137 ;
V_133 -> V_143 += V_131 - V_137 ;
V_121 = F_76 ( & V_127 -> V_129 , V_138 ) ;
V_133 -> V_144 =
F_84 ( V_133 -> V_144 , V_121 ) ;
V_133 -> V_145 =
F_84 ( V_133 -> V_145 ,
V_140 ) ;
}
static void
F_85 ( struct V_2 * V_2 ,
struct V_35 * V_43 ,
T_9 V_131 , T_7 V_122 )
{
bool V_146 ;
F_24 ( & V_43 -> V_50 ) ;
V_146 = F_80 ( V_43 , & V_43 -> V_147 , V_122 ) ;
F_82 ( & V_43 -> V_147 , V_131 ) ;
F_47 ( V_148 , & V_43 -> V_112 ) ;
F_27 ( & V_43 -> V_50 ) ;
if ( V_146 )
F_86 ( V_2 , V_149 ) ;
}
static void
F_87 ( struct V_150 * V_151 ,
struct V_35 * V_43 ,
T_9 V_131 ,
T_9 V_137 )
{
F_24 ( & V_43 -> V_50 ) ;
F_83 ( & V_43 -> V_147 ,
V_131 , V_137 ,
F_4 () , V_151 -> V_152 ) ;
F_47 ( V_148 , & V_43 -> V_112 ) ;
F_27 ( & V_43 -> V_50 ) ;
}
static void
F_88 ( struct V_2 * V_2 ,
struct V_35 * V_43 ,
T_9 V_131 , T_7 V_122 )
{
bool V_146 ;
F_24 ( & V_43 -> V_50 ) ;
V_146 = F_80 ( V_43 , & V_43 -> V_153 , V_122 ) ;
F_82 ( & V_43 -> V_153 , V_131 ) ;
F_47 ( V_148 , & V_43 -> V_112 ) ;
F_27 ( & V_43 -> V_50 ) ;
if ( V_146 )
F_86 ( V_2 , V_154 ) ;
}
static void
F_89 ( struct V_150 * V_151 ,
struct V_35 * V_43 ,
T_9 V_131 ,
T_9 V_137 ,
enum V_155 V_156 )
{
if ( V_156 == V_157 )
V_131 = V_137 = 0 ;
F_24 ( & V_43 -> V_50 ) ;
F_83 ( & V_43 -> V_153 ,
V_131 , V_137 , F_4 () , V_151 -> V_152 ) ;
F_47 ( V_148 , & V_43 -> V_112 ) ;
F_27 ( & V_43 -> V_50 ) ;
}
static int
F_90 ( struct V_74 * V_83 ,
struct V_158 * V_159 ,
T_1 V_3 )
{
struct V_56 * V_57 = F_72 ( V_83 ) ;
struct V_160 * V_119 ;
int V_29 ;
if ( V_159 -> V_161 -> V_118 != 0 ) {
return 0 ;
}
V_29 = F_73 ( V_57 ) * F_91 ( V_83 ) ;
V_119 = F_59 ( V_29 , sizeof( struct V_160 ) ,
V_3 ) ;
if ( ! V_119 )
return - V_95 ;
else {
int V_38 ;
F_24 ( & V_159 -> V_2 -> V_47 ) ;
if ( V_159 -> V_161 -> V_118 != 0 )
F_8 ( V_119 ) ;
else {
V_159 -> V_161 -> V_119 = V_119 ;
V_159 -> V_161 -> V_118 = V_29 ;
for ( V_38 = 0 ; V_38 < V_29 ; V_38 ++ ) {
F_3 ( & V_119 [ V_38 ] . V_162 ) ;
F_3 ( & V_119 [ V_38 ] . V_163 ) ;
V_119 [ V_38 ] . V_164 . V_156 =
V_165 ;
}
}
F_27 ( & V_159 -> V_2 -> V_47 ) ;
return 0 ;
}
}
static struct V_166 *
F_92 ( struct V_74 * V_83 ,
int V_167 ,
int * V_168 )
{
struct V_56 * V_57 = F_72 ( V_83 ) ;
struct V_166 * V_161 ;
bool V_169 = false ;
int V_170 ;
for ( V_170 = V_167 ; V_170 < V_57 -> V_59 ; V_170 ++ ) {
if ( V_170 + 1 == V_57 -> V_59 )
V_169 = true ;
V_161 = F_93 ( V_83 , V_170 , V_169 ) ;
if ( V_161 ) {
* V_168 = V_170 ;
return V_161 ;
}
}
return NULL ;
}
static void
F_94 ( struct V_171 * V_172 ,
struct V_173 * V_174 ,
bool V_175 )
{
V_176:
F_95 ( V_172 -> V_177 ) ;
V_172 -> V_177 = F_96 ( V_172 -> V_178 ,
V_174 -> V_179 ,
0 ,
V_66 ,
V_73 ,
V_175 ,
V_149 ) ;
if ( F_64 ( V_172 -> V_177 ) ) {
V_172 -> V_180 = F_65 ( V_172 -> V_177 ) ;
V_172 -> V_177 = NULL ;
}
if ( V_172 -> V_177 && ! V_175 &&
F_97 ( V_172 -> V_177 ) ) {
V_175 = true ;
goto V_176;
}
}
static void
F_98 ( struct V_171 * V_172 ,
struct V_173 * V_174 )
{
struct V_181 * V_182 ;
struct V_35 * V_43 ;
struct V_166 * V_161 ;
int V_183 ;
V_184:
F_99 ( V_172 ) ;
if ( ! V_172 -> V_177 )
F_94 ( V_172 , V_174 , false ) ;
else if ( F_97 ( V_172 -> V_177 ) )
F_94 ( V_172 , V_174 , true ) ;
if ( V_172 -> V_177 == NULL )
goto V_185;
V_161 = F_92 ( V_172 -> V_177 , 0 , & V_183 ) ;
if ( ! V_161 ) {
if ( ! F_100 ( V_172 -> V_177 ) )
goto V_185;
F_95 ( V_172 -> V_177 ) ;
V_172 -> V_177 = NULL ;
F_101 ( 1 ) ;
goto V_184;
}
V_43 = F_102 ( V_172 -> V_177 , V_183 ) ;
V_172 -> V_186 = V_183 ;
V_182 = & V_172 -> V_187 [ 0 ] ;
V_182 -> V_188 = V_43 -> V_55 -> V_189 [ 0 ] . V_190 ;
return;
V_185:
F_95 ( V_172 -> V_177 ) ;
V_172 -> V_177 = NULL ;
F_103 ( V_172 ) ;
}
static void
F_104 ( struct V_171 * V_172 ,
struct V_173 * V_174 )
{
struct V_35 * V_43 ;
struct V_181 * V_182 ;
struct V_158 V_159 ;
struct V_166 * V_161 ;
int V_38 ;
int V_191 ;
V_184:
F_99 ( V_172 ) ;
if ( ! V_172 -> V_177 ) {
V_172 -> V_177 = F_96 ( V_172 -> V_178 ,
V_174 -> V_179 ,
0 ,
V_66 ,
V_115 ,
false ,
V_192 ) ;
if ( F_64 ( V_172 -> V_177 ) ) {
V_172 -> V_180 = F_65 ( V_172 -> V_177 ) ;
V_172 -> V_177 = NULL ;
return;
}
}
if ( V_172 -> V_177 == NULL )
goto V_185;
F_105 ( & V_159 , V_172 -> V_178 , V_172 -> V_193 ) ;
V_191 = F_90 ( V_172 -> V_177 , & V_159 , V_192 ) ;
if ( V_191 < 0 )
goto V_185;
if ( F_78 ( V_172 -> V_194 !=
F_91 ( V_172 -> V_177 ) ) )
goto V_185;
for ( V_38 = 0 ; V_38 < V_172 -> V_194 ; V_38 ++ ) {
V_161 = F_93 ( V_172 -> V_177 , V_38 , true ) ;
if ( ! V_161 ) {
if ( ! F_100 ( V_172 -> V_177 ) )
goto V_185;
F_95 ( V_172 -> V_177 ) ;
V_172 -> V_177 = NULL ;
F_101 ( 1 ) ;
goto V_184;
}
V_182 = & V_172 -> V_187 [ V_38 ] ;
V_43 = F_102 ( V_172 -> V_177 , V_38 ) ;
V_182 -> V_188 = V_43 -> V_55 -> V_189 [ 0 ] . V_195 ;
}
return;
V_185:
F_95 ( V_172 -> V_177 ) ;
V_172 -> V_177 = NULL ;
F_106 ( V_172 ) ;
}
static unsigned int
F_107 ( struct V_171 * V_172 ,
struct V_173 * V_174 )
{
if ( ! V_172 -> V_177 ) {
V_172 -> V_177 = F_96 ( V_172 -> V_178 ,
V_174 -> V_179 ,
0 ,
V_66 ,
V_115 ,
false ,
V_192 ) ;
if ( F_64 ( V_172 -> V_177 ) ) {
V_172 -> V_180 = F_65 ( V_172 -> V_177 ) ;
V_172 -> V_177 = NULL ;
goto V_196;
}
}
if ( V_172 -> V_177 )
return F_91 ( V_172 -> V_177 ) ;
F_106 ( V_172 ) ;
V_196:
return 1 ;
}
static void F_108 ( struct V_197 * V_198 , bool V_199 )
{
struct V_150 * V_151 = & V_198 -> V_151 ;
F_109 ( V_198 -> V_2 , false ) ;
if ( V_199 ) {
F_13 ( L_14
L_15 , V_23 ,
V_198 -> V_151 . V_200 ,
V_198 -> V_2 -> V_201 -> V_202 ,
( unsigned long long ) F_110 ( V_198 -> V_2 ) ,
V_198 -> args . V_203 ,
( unsigned long long ) V_198 -> args . V_64 ) ;
V_198 -> V_204 -> V_205 ( V_198 ) ;
return;
}
if ( ! F_111 ( V_206 , & V_198 -> V_112 ) ) {
F_13 ( L_16
L_15 , V_23 ,
V_198 -> V_151 . V_200 ,
V_198 -> V_2 -> V_201 -> V_202 ,
( unsigned long long ) F_110 ( V_198 -> V_2 ) ,
V_198 -> args . V_203 ,
( unsigned long long ) V_198 -> args . V_64 ) ;
V_151 -> V_207 = F_112 ( V_198 ) ;
}
}
static void F_113 ( struct V_197 * V_198 )
{
struct V_150 * V_151 = & V_198 -> V_151 ;
F_109 ( V_198 -> V_2 , false ) ;
if ( ! F_111 ( V_206 , & V_198 -> V_112 ) ) {
F_13 ( L_16
L_15 , V_23 ,
V_198 -> V_151 . V_200 ,
V_198 -> V_2 -> V_201 -> V_202 ,
( unsigned long long ) F_110 ( V_198 -> V_2 ) ,
V_198 -> args . V_203 ,
( unsigned long long ) V_198 -> args . V_64 ) ;
V_151 -> V_207 = F_114 ( V_198 ) ;
}
}
static int F_115 ( struct V_150 * V_151 ,
struct V_208 * V_209 ,
struct V_210 * V_211 ,
struct V_74 * V_83 ,
int V_170 )
{
struct V_1 * V_10 = V_83 -> V_116 ;
struct V_2 * V_2 = V_10 -> V_46 ;
struct V_212 * V_213 = F_116 ( V_2 ) ;
struct V_214 * V_25 = F_117 ( V_83 , V_170 ) ;
struct V_210 * V_215 = V_213 -> V_210 ;
struct V_216 * V_217 = & V_211 -> V_218 -> V_219 ;
switch ( V_151 -> V_207 ) {
case - V_220 :
case - V_221 :
case - V_222 :
if ( V_209 == NULL )
break;
F_118 ( V_209 -> V_2 , NULL ) ;
case - V_223 :
if ( V_209 == NULL )
break;
if ( F_119 ( V_213 , V_209 ) < 0 )
goto V_224;
goto V_225;
case - V_226 :
if ( V_209 != NULL ) {
if ( F_119 ( V_213 , V_209 ) < 0 )
goto V_224;
}
F_120 ( V_215 ) ;
goto V_225;
case - V_227 :
case - V_228 :
case - V_229 :
case - V_230 :
case - V_231 :
case - V_232 :
case - V_233 :
F_13 ( L_17
L_18 , V_23 , V_151 -> V_207 ,
V_211 -> V_234 ) ;
F_121 ( V_211 -> V_218 , V_151 -> V_207 ) ;
break;
case - V_235 :
case - V_236 :
F_122 ( V_151 , V_237 ) ;
break;
case - V_238 :
break;
case - V_239 :
case - V_240 :
case - V_241 :
case - V_242 :
case - V_243 :
case - V_244 :
F_13 ( L_19 , V_23 ,
V_151 -> V_207 ) ;
F_123 ( F_124 ( V_2 ) ) ;
F_125 ( & V_217 -> V_245 ) ;
goto V_246;
case - V_247 :
case - V_248 :
case - V_249 :
case - V_250 :
case - V_99 :
case - V_251 :
case - V_252 :
F_13 ( L_20 , V_23 ,
V_151 -> V_207 ) ;
F_126 ( V_25 -> V_253 , V_25 -> V_210 ,
& V_25 -> V_254 ) ;
F_125 ( & V_217 -> V_245 ) ;
default:
if ( F_127 ( V_83 ) )
return - V_255 ;
V_246:
F_13 ( L_21 , V_23 ,
V_151 -> V_207 ) ;
return - V_256 ;
}
V_196:
V_151 -> V_207 = 0 ;
return - V_257 ;
V_224:
V_151 -> V_207 = - V_99 ;
return 0 ;
V_225:
F_128 ( & V_215 -> V_258 , V_151 , NULL ) ;
if ( F_45 ( V_259 , & V_215 -> V_260 ) == 0 )
F_129 ( & V_215 -> V_258 , V_151 ) ;
goto V_196;
}
static int F_130 ( struct V_150 * V_151 ,
struct V_74 * V_83 ,
int V_170 )
{
struct V_214 * V_25 = F_117 ( V_83 , V_170 ) ;
switch ( V_151 -> V_207 ) {
case - V_261 :
case - V_240 :
case - V_242 :
case - V_241 :
case - V_262 :
case - V_263 :
break;
case - V_264 :
F_131 ( V_83 -> V_116 -> V_46 , V_265 ) ;
goto V_266;
default:
F_13 ( L_20 , V_23 ,
V_151 -> V_207 ) ;
F_126 ( V_25 -> V_253 , V_25 -> V_210 ,
& V_25 -> V_254 ) ;
}
return - V_255 ;
V_266:
V_151 -> V_207 = 0 ;
F_132 ( V_151 ) ;
F_122 ( V_151 , V_267 ) ;
return - V_257 ;
}
static int F_133 ( struct V_150 * V_151 ,
struct V_208 * V_209 ,
struct V_210 * V_211 ,
struct V_74 * V_83 ,
int V_170 )
{
int V_268 = V_211 -> V_269 -> V_270 -> V_271 ;
if ( V_151 -> V_207 >= 0 )
return 0 ;
if ( ! F_134 ( V_83 ) )
return - V_255 ;
switch ( V_268 ) {
case 3 :
return F_130 ( V_151 , V_83 , V_170 ) ;
case 4 :
return F_115 ( V_151 , V_209 , V_211 ,
V_83 , V_170 ) ;
default:
F_78 ( 1 ) ;
return 0 ;
}
}
static void F_135 ( struct V_74 * V_83 ,
int V_170 , T_5 V_64 , T_5 V_65 ,
T_4 V_191 , int V_272 , int error )
{
struct V_35 * V_43 ;
int V_12 ;
if ( V_191 == 0 ) {
switch ( error ) {
case - V_251 :
case - V_273 :
case - V_274 :
case - V_275 :
case - V_247 :
case - V_276 :
case - V_248 :
case - V_249 :
case - V_250 :
case - V_277 :
case - V_20 :
case - V_252 :
case - V_278 :
V_191 = V_279 ;
break;
case - V_261 :
V_191 = V_280 ;
break;
default:
return;
}
}
switch ( V_191 ) {
case V_235 :
case V_236 :
return;
default:
break;
}
V_43 = F_102 ( V_83 , V_170 ) ;
V_12 = F_136 ( F_9 ( V_83 -> V_116 ) ,
V_43 , V_64 , V_65 , V_191 , V_272 ,
V_154 ) ;
F_137 ( V_83 -> V_116 -> V_46 , V_83 ) ;
F_13 ( L_22 , V_23 , V_12 , V_272 , V_191 ) ;
}
static int F_138 ( struct V_150 * V_151 ,
struct V_197 * V_198 )
{
int V_12 ;
F_139 ( V_198 , V_151 -> V_207 ) ;
if ( V_151 -> V_207 < 0 )
F_135 ( V_198 -> V_83 , V_198 -> V_281 ,
V_198 -> args . V_64 , V_198 -> args . V_203 ,
V_198 -> V_282 . V_283 , V_284 ,
V_151 -> V_207 ) ;
V_12 = F_133 ( V_151 , V_198 -> args . V_285 -> V_209 ,
V_198 -> V_286 , V_198 -> V_83 ,
V_198 -> V_281 ) ;
switch ( V_12 ) {
case - V_255 :
if ( F_92 ( V_198 -> V_83 ,
V_198 -> V_281 + 1 ,
& V_198 -> V_281 ) )
goto V_287;
F_140 ( V_151 , V_198 ) ;
F_141 ( V_198 ) ;
return V_151 -> V_207 ;
case - V_256 :
F_113 ( V_198 ) ;
return V_151 -> V_207 ;
case - V_257 :
goto V_287;
}
return 0 ;
V_287:
F_132 ( V_151 ) ;
return - V_257 ;
}
static bool
F_142 ( struct V_74 * V_83 )
{
return ! ( F_72 ( V_83 ) -> V_112 & V_288 ) ;
}
static void
F_143 ( struct V_2 * V_2 ,
struct V_74 * V_83 ,
T_10 V_289 )
{
if ( ! F_142 ( V_83 ) )
return;
F_144 ( V_2 , V_83 , V_289 ) ;
F_13 ( L_23 , V_23 , V_2 -> V_290 ,
( unsigned long long ) F_124 ( V_2 ) -> V_49 -> V_291 ) ;
}
static bool
F_145 ( struct V_74 * V_83 , int V_170 )
{
struct V_214 * V_292 = F_117 ( V_83 , V_170 ) ;
return F_146 ( V_292 ) ;
}
static void F_147 ( struct V_150 * V_151 ,
struct V_197 * V_198 )
{
if ( F_111 ( V_293 , & V_198 -> V_112 ) )
return;
F_85 ( V_198 -> V_2 ,
F_102 ( V_198 -> V_83 , V_198 -> V_281 ) ,
V_198 -> args . V_203 ,
V_151 -> V_152 ) ;
}
static void F_140 ( struct V_150 * V_151 ,
struct V_197 * V_198 )
{
if ( ! F_148 ( V_293 , & V_198 -> V_112 ) )
return;
F_87 ( V_151 ,
F_102 ( V_198 -> V_83 , V_198 -> V_281 ) ,
V_198 -> args . V_203 ,
V_198 -> V_282 . V_203 ) ;
}
static int F_149 ( struct V_150 * V_151 ,
struct V_197 * V_198 )
{
if ( F_12 ( F_45 ( V_294 , & V_198 -> args . V_285 -> V_112 ) ) ) {
F_150 ( V_151 , - V_99 ) ;
return - V_99 ;
}
if ( F_145 ( V_198 -> V_83 , V_198 -> V_281 ) ) {
F_150 ( V_151 , - V_248 ) ;
return - V_257 ;
}
F_147 ( V_151 , V_198 ) ;
return 0 ;
}
static void F_151 ( struct V_150 * V_151 , void * V_22 )
{
struct V_197 * V_198 = V_22 ;
if ( F_149 ( V_151 , V_198 ) )
return;
F_152 ( V_151 ) ;
}
static void F_153 ( struct V_150 * V_151 , void * V_22 )
{
struct V_197 * V_198 = V_22 ;
if ( F_154 ( V_198 -> V_286 ,
& V_198 -> args . V_295 ,
& V_198 -> V_282 . V_296 ,
V_151 ) )
return;
if ( F_149 ( V_151 , V_198 ) )
return;
if ( F_155 ( & V_198 -> args . V_17 , V_198 -> args . V_285 ,
V_198 -> args . V_297 , V_298 ) == - V_99 )
F_150 ( V_151 , - V_99 ) ;
}
static void F_156 ( struct V_150 * V_151 , void * V_22 )
{
struct V_197 * V_198 = V_22 ;
F_13 ( L_24 , V_23 , V_151 -> V_207 ) ;
if ( F_45 ( V_206 , & V_198 -> V_112 ) &&
V_151 -> V_207 == 0 ) {
F_157 ( V_151 , & V_198 -> V_282 . V_296 ) ;
return;
}
V_198 -> V_299 -> V_300 ( V_151 , V_198 ) ;
}
static void F_158 ( struct V_150 * V_151 , void * V_22 )
{
struct V_197 * V_198 = V_22 ;
F_140 ( V_151 , V_198 ) ;
F_159 ( V_151 ,
& F_160 ( V_198 -> V_2 ) -> V_301 [ V_302 ] ) ;
}
static void F_161 ( void * V_22 )
{
struct V_197 * V_198 = V_22 ;
F_140 ( & V_198 -> V_151 , V_198 ) ;
F_162 ( V_22 ) ;
}
static int F_163 ( struct V_150 * V_151 ,
struct V_197 * V_198 )
{
T_10 V_303 = 0 ;
int V_12 ;
F_164 ( V_198 , V_151 -> V_207 ) ;
if ( V_151 -> V_207 < 0 )
F_135 ( V_198 -> V_83 , V_198 -> V_281 ,
V_198 -> args . V_64 , V_198 -> args . V_203 ,
V_198 -> V_282 . V_283 , V_304 ,
V_151 -> V_207 ) ;
V_12 = F_133 ( V_151 , V_198 -> args . V_285 -> V_209 ,
V_198 -> V_286 , V_198 -> V_83 ,
V_198 -> V_281 ) ;
switch ( V_12 ) {
case - V_255 :
F_108 ( V_198 , true ) ;
return V_151 -> V_207 ;
case - V_256 :
F_108 ( V_198 , false ) ;
return V_151 -> V_207 ;
case - V_257 :
return - V_257 ;
}
if ( V_198 -> V_282 . V_305 -> V_156 == V_306 ||
V_198 -> V_282 . V_305 -> V_156 == V_307 )
V_303 = V_198 -> V_308 + ( T_10 ) V_198 -> V_282 . V_203 ;
F_143 ( V_198 -> V_2 , V_198 -> V_83 , V_303 ) ;
V_198 -> V_309 . V_310 = 0 ;
if ( V_151 -> V_207 >= 0 )
F_165 ( V_198 ) ;
return 0 ;
}
static int F_166 ( struct V_150 * V_151 ,
struct V_311 * V_22 )
{
int V_12 ;
F_167 ( V_22 , V_151 -> V_207 ) ;
if ( V_151 -> V_207 < 0 )
F_135 ( V_22 -> V_83 , V_22 -> V_312 ,
V_22 -> args . V_64 , V_22 -> args . V_203 ,
V_22 -> V_282 . V_283 , V_313 ,
V_151 -> V_207 ) ;
V_12 = F_133 ( V_151 , NULL , V_22 -> V_286 ,
V_22 -> V_83 , V_22 -> V_312 ) ;
switch ( V_12 ) {
case - V_255 :
F_168 ( V_22 ) ;
return - V_257 ;
case - V_256 :
F_168 ( V_22 ) ;
return - V_257 ;
case - V_257 :
F_132 ( V_151 ) ;
return - V_257 ;
}
F_143 ( V_22 -> V_2 , V_22 -> V_83 , V_22 -> V_314 ) ;
return 0 ;
}
static void F_169 ( struct V_150 * V_151 ,
struct V_197 * V_198 )
{
if ( F_111 ( V_293 , & V_198 -> V_112 ) )
return;
F_88 ( V_198 -> V_2 ,
F_102 ( V_198 -> V_83 , V_198 -> V_281 ) ,
V_198 -> args . V_203 ,
V_151 -> V_152 ) ;
}
static void F_170 ( struct V_150 * V_151 ,
struct V_197 * V_198 )
{
if ( ! F_148 ( V_293 , & V_198 -> V_112 ) )
return;
F_89 ( V_151 ,
F_102 ( V_198 -> V_83 , V_198 -> V_281 ) ,
V_198 -> args . V_203 , V_198 -> V_282 . V_203 ,
V_198 -> V_282 . V_305 -> V_156 ) ;
}
static int F_171 ( struct V_150 * V_151 ,
struct V_197 * V_198 )
{
if ( F_12 ( F_45 ( V_294 , & V_198 -> args . V_285 -> V_112 ) ) ) {
F_150 ( V_151 , - V_99 ) ;
return - V_99 ;
}
if ( F_145 ( V_198 -> V_83 , V_198 -> V_281 ) ) {
F_150 ( V_151 , - V_248 ) ;
return - V_257 ;
}
F_169 ( V_151 , V_198 ) ;
return 0 ;
}
static void F_172 ( struct V_150 * V_151 , void * V_22 )
{
struct V_197 * V_198 = V_22 ;
if ( F_171 ( V_151 , V_198 ) )
return;
F_152 ( V_151 ) ;
}
static void F_173 ( struct V_150 * V_151 , void * V_22 )
{
struct V_197 * V_198 = V_22 ;
if ( F_154 ( V_198 -> V_286 ,
& V_198 -> args . V_295 ,
& V_198 -> V_282 . V_296 ,
V_151 ) )
return;
if ( F_171 ( V_151 , V_198 ) )
return;
if ( F_155 ( & V_198 -> args . V_17 , V_198 -> args . V_285 ,
V_198 -> args . V_297 , V_315 ) == - V_99 )
F_150 ( V_151 , - V_99 ) ;
}
static void F_174 ( struct V_150 * V_151 , void * V_22 )
{
struct V_197 * V_198 = V_22 ;
if ( F_45 ( V_206 , & V_198 -> V_112 ) &&
V_151 -> V_207 == 0 ) {
F_157 ( V_151 , & V_198 -> V_282 . V_296 ) ;
return;
}
V_198 -> V_299 -> V_300 ( V_151 , V_198 ) ;
}
static void F_175 ( struct V_150 * V_151 , void * V_22 )
{
struct V_197 * V_198 = V_22 ;
F_170 ( V_151 , V_198 ) ;
F_159 ( V_151 ,
& F_160 ( V_198 -> V_2 ) -> V_301 [ V_316 ] ) ;
}
static void F_176 ( void * V_22 )
{
struct V_197 * V_198 = V_22 ;
F_170 ( & V_198 -> V_151 , V_198 ) ;
F_162 ( V_22 ) ;
}
static void F_177 ( struct V_150 * V_151 ,
struct V_311 * V_317 )
{
if ( F_111 ( V_293 , & V_317 -> V_112 ) )
return;
F_88 ( V_317 -> V_2 ,
F_102 ( V_317 -> V_83 , V_317 -> V_312 ) ,
0 , V_151 -> V_152 ) ;
}
static void F_178 ( struct V_150 * V_151 ,
struct V_311 * V_317 )
{
struct V_173 * V_174 ;
T_9 V_203 = 0 ;
if ( ! F_148 ( V_293 , & V_317 -> V_112 ) )
return;
if ( V_151 -> V_207 == 0 ) {
F_25 (req, &cdata->pages, wb_list)
V_203 += V_174 -> V_318 ;
}
F_89 ( V_151 ,
F_102 ( V_317 -> V_83 , V_317 -> V_312 ) ,
V_203 , V_203 , V_306 ) ;
}
static void F_179 ( struct V_150 * V_151 ,
struct V_311 * V_317 )
{
F_177 ( V_151 , V_317 ) ;
}
static void F_180 ( struct V_150 * V_151 , void * V_22 )
{
F_179 ( V_151 , V_22 ) ;
F_152 ( V_151 ) ;
}
static void F_181 ( struct V_150 * V_151 , void * V_22 )
{
struct V_311 * V_319 = V_22 ;
if ( F_154 ( V_319 -> V_286 ,
& V_319 -> args . V_295 ,
& V_319 -> V_282 . V_296 ,
V_151 ) )
return;
F_179 ( V_151 , V_22 ) ;
}
static void F_182 ( struct V_150 * V_151 , void * V_22 )
{
F_183 ( V_151 , V_22 ) ;
}
static void F_184 ( struct V_150 * V_151 , void * V_22 )
{
struct V_311 * V_317 = V_22 ;
F_178 ( V_151 , V_317 ) ;
F_159 ( V_151 ,
& F_160 ( V_317 -> V_2 ) -> V_301 [ V_320 ] ) ;
}
static void F_185 ( void * V_22 )
{
struct V_311 * V_317 = V_22 ;
F_178 ( & V_317 -> V_151 , V_317 ) ;
F_186 ( V_22 ) ;
}
static enum V_321
F_187 ( struct V_197 * V_198 )
{
struct V_74 * V_83 = V_198 -> V_83 ;
struct V_166 * V_161 ;
struct V_322 * V_323 ;
struct V_51 * V_324 ;
T_10 V_64 = V_198 -> args . V_64 ;
T_4 V_170 = V_198 -> V_281 ;
int V_268 ;
struct V_27 * V_28 ;
F_13 ( L_25 ,
V_23 , V_198 -> V_2 -> V_290 ,
V_198 -> args . V_325 , ( V_326 ) V_198 -> args . V_203 , V_64 ) ;
V_161 = F_93 ( V_83 , V_170 , false ) ;
if ( ! V_161 )
goto V_327;
V_323 = F_188 ( V_83 , V_170 , V_161 -> V_286 ,
V_198 -> V_2 ) ;
if ( F_64 ( V_323 ) )
goto V_327;
V_324 = F_189 ( V_83 , V_170 , V_198 -> V_52 ) ;
if ( ! V_324 )
goto V_327;
V_268 = F_190 ( V_83 , V_170 ) ;
F_13 ( L_26 , V_23 ,
V_161 -> V_328 , F_191 ( & V_161 -> V_286 -> V_329 ) , V_268 ) ;
V_198 -> V_330 = F_138 ;
F_192 ( & V_161 -> V_286 -> V_329 ) ;
V_198 -> V_286 = V_161 -> V_286 ;
V_28 = F_193 ( V_83 , V_170 ) ;
if ( V_28 )
V_198 -> args . V_28 = V_28 ;
V_198 -> args . V_64 = V_64 ;
V_198 -> V_308 = V_64 ;
F_194 ( V_323 , V_198 , V_324 , V_161 -> V_286 -> V_331 ,
V_268 == 3 ? & V_332 :
& V_333 ,
0 , V_334 ) ;
F_35 ( V_324 ) ;
return V_335 ;
V_327:
if ( F_127 ( V_83 ) )
return V_336 ;
return V_337 ;
}
static enum V_321
F_195 ( struct V_197 * V_198 , int V_338 )
{
struct V_74 * V_83 = V_198 -> V_83 ;
struct V_166 * V_161 ;
struct V_322 * V_323 ;
struct V_51 * V_324 ;
T_10 V_64 = V_198 -> args . V_64 ;
int V_268 ;
struct V_27 * V_28 ;
int V_170 = V_198 -> V_281 ;
V_161 = F_93 ( V_83 , V_170 , true ) ;
if ( ! V_161 )
goto V_327;
V_323 = F_188 ( V_83 , V_170 , V_161 -> V_286 ,
V_198 -> V_2 ) ;
if ( F_64 ( V_323 ) )
goto V_327;
V_324 = F_189 ( V_83 , V_170 , V_198 -> V_52 ) ;
if ( ! V_324 )
goto V_327;
V_268 = F_190 ( V_83 , V_170 ) ;
F_13 ( L_27 ,
V_23 , V_198 -> V_2 -> V_290 , V_338 , ( V_326 ) V_198 -> args . V_203 ,
V_64 , V_161 -> V_328 , F_191 ( & V_161 -> V_286 -> V_329 ) ,
V_268 ) ;
V_198 -> V_330 = F_163 ;
F_192 ( & V_161 -> V_286 -> V_329 ) ;
V_198 -> V_286 = V_161 -> V_286 ;
V_198 -> V_339 = V_170 ;
V_28 = F_193 ( V_83 , V_170 ) ;
if ( V_28 )
V_198 -> args . V_28 = V_28 ;
V_198 -> args . V_64 = V_64 ;
F_194 ( V_323 , V_198 , V_324 , V_161 -> V_286 -> V_331 ,
V_268 == 3 ? & V_340 :
& V_341 ,
V_338 , V_334 ) ;
F_35 ( V_324 ) ;
return V_335 ;
V_327:
if ( F_127 ( V_83 ) )
return V_336 ;
return V_337 ;
}
static T_4 F_196 ( struct V_74 * V_83 , T_4 V_38 )
{
return V_38 ;
}
static struct V_27 *
F_197 ( struct V_74 * V_83 , T_4 V_38 )
{
struct V_56 * V_342 = F_72 ( V_83 ) ;
return & V_342 -> V_58 [ V_38 ] -> V_42 [ 0 ] ;
}
static int F_198 ( struct V_311 * V_22 , int V_343 )
{
struct V_74 * V_83 = V_22 -> V_83 ;
struct V_166 * V_161 ;
struct V_322 * V_323 ;
struct V_51 * V_324 ;
T_4 V_170 ;
int V_268 , V_62 ;
struct V_27 * V_28 ;
V_170 = F_196 ( V_83 , V_22 -> V_312 ) ;
V_161 = F_93 ( V_83 , V_170 , true ) ;
if ( ! V_161 )
goto V_344;
V_323 = F_188 ( V_83 , V_170 , V_161 -> V_286 ,
V_22 -> V_2 ) ;
if ( F_64 ( V_323 ) )
goto V_344;
V_324 = F_189 ( V_83 , V_170 , V_22 -> V_52 ) ;
if ( ! V_324 )
goto V_344;
V_268 = F_190 ( V_83 , V_170 ) ;
F_13 ( L_28 , V_23 ,
V_22 -> V_2 -> V_290 , V_343 , F_191 ( & V_161 -> V_286 -> V_329 ) ,
V_268 ) ;
V_22 -> V_345 = F_166 ;
V_22 -> V_52 = V_324 ;
F_192 ( & V_161 -> V_286 -> V_329 ) ;
V_22 -> V_286 = V_161 -> V_286 ;
V_28 = F_197 ( V_83 , V_22 -> V_312 ) ;
if ( V_28 )
V_22 -> args . V_28 = V_28 ;
V_62 = F_199 ( V_323 , V_22 , V_161 -> V_286 -> V_331 ,
V_268 == 3 ? & V_346 :
& V_347 ,
V_343 , V_334 ) ;
F_35 ( V_324 ) ;
return V_62 ;
V_344:
F_168 ( V_22 ) ;
F_186 ( V_22 ) ;
return - V_257 ;
}
static int
F_200 ( struct V_2 * V_2 , struct V_84 * V_348 ,
int V_343 , struct V_158 * V_159 )
{
return F_201 ( V_2 , V_348 , V_343 , V_159 ,
F_198 ) ;
}
static struct V_349 *
F_202 ( struct V_2 * V_2 )
{
struct V_1 * V_49 = F_124 ( V_2 ) -> V_49 ;
if ( V_49 == NULL )
return NULL ;
return & F_9 ( V_49 ) -> V_117 ;
}
static void
F_203 ( struct V_214 * V_350 )
{
F_204 ( F_205 ( V_350 , struct V_351 ,
V_352 ) ) ;
}
static int F_206 ( struct V_15 * V_16 ,
const struct V_353 * args ,
const struct V_354 * V_355 )
{
T_3 * V_125 ;
V_125 = F_207 ( V_16 , 4 ) ;
if ( F_12 ( ! V_125 ) )
return - V_356 ;
* V_125 = F_208 ( V_355 -> V_357 ) ;
return F_209 ( V_16 , & V_355 -> V_358 ) ;
}
static void
F_210 ( struct V_15 * V_16 , const void * V_90 , V_326 V_33 )
{
F_78 ( F_211 ( V_16 , V_90 , V_33 ) < 0 ) ;
}
static void
F_212 ( struct V_15 * V_16 ,
const T_2 * V_17 ,
const struct V_359 * V_360 )
{
T_3 * V_18 ;
V_18 = F_207 ( V_16 , 8 + 8 ) ;
V_18 = F_213 ( V_18 , V_360 -> V_64 ) ;
V_18 = F_213 ( V_18 , V_360 -> V_65 ) ;
F_210 ( V_16 , V_17 -> V_22 , V_19 ) ;
V_18 = F_207 ( V_16 , 4 * 8 ) ;
V_18 = F_213 ( V_18 , V_360 -> V_361 ) ;
V_18 = F_213 ( V_18 , V_360 -> V_362 ) ;
V_18 = F_213 ( V_18 , V_360 -> V_363 ) ;
V_18 = F_213 ( V_18 , V_360 -> V_364 ) ;
F_210 ( V_16 , V_360 -> V_365 . V_22 , V_26 ) ;
}
static void
F_214 ( struct V_15 * V_16 ,
const T_2 * V_17 ,
const struct V_359 * V_360 )
{
F_212 ( V_16 , V_17 , V_360 ) ;
F_215 ( V_16 , V_360 ,
V_360 -> V_366 . V_22 ) ;
}
static void F_216 ( struct V_15 * V_16 ,
const struct V_353 * args ,
struct V_354 * V_355 )
{
T_3 * V_18 ;
int V_38 ;
V_18 = F_207 ( V_16 , 4 ) ;
* V_18 = F_208 ( V_355 -> V_367 ) ;
for ( V_38 = 0 ; V_38 < V_355 -> V_367 ; V_38 ++ )
F_214 ( V_16 ,
& args -> V_49 -> V_368 ,
& V_355 -> V_360 [ V_38 ] ) ;
}
static void
F_217 ( struct V_359 * V_360 ,
unsigned int V_369 )
{
unsigned int V_38 ;
for ( V_38 = 0 ; V_38 < V_369 ; V_38 ++ ) {
if ( ! V_360 [ V_38 ] . V_366 . V_370 )
continue;
if ( ! V_360 [ V_38 ] . V_366 . V_370 -> free )
continue;
V_360 [ V_38 ] . V_366 . V_370 -> free ( & V_360 [ V_38 ] . V_366 ) ;
}
}
static struct V_214 *
F_218 ( struct V_212 * V_371 ,
struct V_372 * V_373 , T_1 V_3 )
{
struct V_351 * V_374 ;
V_374 = F_219 ( V_371 , V_373 , V_3 ) ;
if ( ! V_374 )
return NULL ;
return & V_374 -> V_352 ;
}
static void
F_220 ( struct V_15 * V_16 ,
const void * V_375 ,
const struct V_376 * V_377 )
{
const struct V_353 * args = V_375 ;
struct V_354 * V_355 = V_377 -> V_22 ;
struct V_89 V_378 = {
. V_379 = {
[ 0 ] = {
. V_380 = F_57 ( V_355 -> V_97 [ 0 ] ) ,
} ,
} ,
. V_381 = V_98 ,
} ;
struct V_15 V_382 ;
T_3 * V_125 ;
F_13 ( L_29 , V_23 ) ;
F_221 ( & V_382 , & V_378 , NULL ) ;
F_206 ( & V_382 , args , V_355 ) ;
F_216 ( & V_382 , args , V_355 ) ;
V_125 = F_207 ( V_16 , 4 ) ;
* V_125 = F_208 ( V_378 . V_33 ) ;
F_222 ( V_16 , V_355 -> V_97 , 0 , V_378 . V_33 ) ;
F_13 ( L_30 , V_23 ) ;
}
static void
F_223 ( struct V_376 * args )
{
struct V_354 * V_355 ;
if ( ! args -> V_22 )
return;
V_355 = args -> V_22 ;
args -> V_22 = NULL ;
F_224 ( & V_355 -> V_358 ) ;
F_217 ( V_355 -> V_360 , V_355 -> V_367 ) ;
F_225 ( V_355 -> V_97 [ 0 ] ) ;
F_8 ( V_355 ) ;
}
static int
F_226 ( struct V_353 * args )
{
struct V_354 * V_355 ;
struct V_4 * V_44 = F_9 ( args -> V_49 ) ;
V_355 = F_227 ( sizeof( * V_355 ) , V_149 ) ;
if ( ! V_355 )
goto V_383;
V_355 -> V_97 [ 0 ] = F_53 ( V_149 ) ;
if ( ! V_355 -> V_97 [ 0 ] )
goto V_384;
F_3 ( & V_355 -> V_358 ) ;
V_355 -> V_357 = F_228 ( args -> V_49 ,
& args -> V_63 , & V_355 -> V_358 ,
V_385 ) ;
F_24 ( & args -> V_2 -> V_47 ) ;
V_355 -> V_367 = F_229 ( & V_44 -> V_9 ,
& V_355 -> V_360 [ 0 ] , F_230 ( V_355 -> V_360 ) ) ;
F_27 ( & args -> V_2 -> V_47 ) ;
args -> V_366 -> V_370 = & V_386 ;
args -> V_366 -> V_22 = V_355 ;
return 0 ;
V_384:
F_8 ( V_355 ) ;
V_383:
return - V_95 ;
}
static int
F_231 ( const struct V_387 * V_388 , char * V_90 , const V_326 V_381 )
{
const struct V_389 * sin = (struct V_389 * ) V_388 ;
return snprintf ( V_90 , V_381 , L_31 , & sin -> V_390 ) ;
}
static V_326
F_232 ( const struct V_387 * V_388 , char * V_90 ,
const int V_381 )
{
const struct V_391 * V_392 = (struct V_391 * ) V_388 ;
const struct V_393 * V_394 = & V_392 -> V_395 ;
if ( F_233 ( V_394 ) )
return snprintf ( V_90 , V_381 , L_32 ) ;
if ( F_234 ( V_394 ) )
return snprintf ( V_90 , V_381 , L_33 ) ;
if ( F_235 ( V_394 ) )
return snprintf ( V_90 , V_381 , L_34 ,
& V_394 -> V_396 [ 3 ] ) ;
return snprintf ( V_90 , V_381 , L_35 , V_394 ) ;
}
static void
F_236 ( struct V_15 * V_16 , struct V_397 * V_398 )
{
struct V_387 * V_388 = (struct V_387 * ) & V_398 -> V_399 ;
char V_400 [ V_401 ] ;
char V_402 [ V_403 ] ;
char * V_404 ;
unsigned short V_405 ;
int V_33 , V_406 ;
T_3 * V_18 ;
switch ( V_388 -> V_407 ) {
case V_408 :
if ( F_231 ( V_388 , V_402 , sizeof( V_402 ) ) == 0 )
return;
V_405 = F_237 ( ( (struct V_389 * ) V_388 ) -> V_409 ) ;
V_404 = L_36 ;
V_406 = 3 ;
break;
case V_410 :
if ( F_232 ( V_388 , V_402 , sizeof( V_402 ) ) == 0 )
return;
V_405 = F_237 ( ( (struct V_391 * ) V_388 ) -> V_411 ) ;
V_404 = L_37 ;
V_406 = 4 ;
break;
default:
F_78 ( 1 ) ;
return;
}
snprintf ( V_400 , sizeof( V_400 ) , L_38 , V_405 >> 8 , V_405 & 0xff ) ;
V_33 = F_238 ( V_402 , V_400 , sizeof( V_402 ) ) ;
V_18 = F_207 ( V_16 , 4 + V_406 ) ;
F_239 ( V_18 , V_404 , V_406 ) ;
V_18 = F_207 ( V_16 , 4 + V_33 ) ;
F_239 ( V_18 , V_402 , V_33 ) ;
}
static void
F_240 ( struct V_15 * V_16 ,
T_7 V_412 )
{
struct V_413 V_414 ;
T_3 * V_18 ;
V_18 = F_207 ( V_16 , 12 ) ;
V_414 = F_241 ( V_412 ) ;
V_18 = F_213 ( V_18 , V_414 . V_415 ) ;
* V_18 ++ = F_208 ( V_414 . V_416 ) ;
}
static void
F_242 ( struct V_15 * V_16 ,
struct V_132 * V_417 )
{
T_3 * V_18 ;
V_18 = F_207 ( V_16 , 5 * 8 ) ;
V_18 = F_213 ( V_18 , V_417 -> V_135 ) ;
V_18 = F_213 ( V_18 , V_417 -> V_136 ) ;
V_18 = F_213 ( V_18 , V_417 -> V_141 ) ;
V_18 = F_213 ( V_18 , V_417 -> V_142 ) ;
V_18 = F_213 ( V_18 , V_417 -> V_143 ) ;
F_240 ( V_16 , V_417 -> V_144 ) ;
F_240 ( V_16 , V_417 -> V_145 ) ;
}
static void
F_215 ( struct V_15 * V_16 ,
const struct V_359 * V_360 ,
struct V_35 * V_43 )
{
struct V_397 * V_398 ;
struct V_166 * V_161 = V_43 -> V_55 -> V_161 ;
struct V_27 * V_28 = & V_43 -> V_42 [ 0 ] ;
T_3 * V_18 ;
V_398 = F_243 ( & V_161 -> V_418 , struct V_397 , V_419 ) ;
F_13 ( L_39 ,
V_23 , V_161 -> V_328 , V_398 -> V_420 ) ;
F_236 ( V_16 , V_398 ) ;
V_18 = F_207 ( V_16 , 4 + V_28 -> V_29 ) ;
F_239 ( V_18 , V_28 -> V_22 , V_28 -> V_29 ) ;
F_24 ( & V_43 -> V_50 ) ;
F_242 ( V_16 , & V_43 -> V_147 . V_134 ) ;
F_242 ( V_16 , & V_43 -> V_153 . V_134 ) ;
F_27 ( & V_43 -> V_50 ) ;
F_240 ( V_16 , F_79 ( F_4 () , V_43 -> V_124 ) ) ;
V_18 = F_207 ( V_16 , 4 ) ;
* V_18 = F_208 ( false ) ;
}
static void
F_244 ( struct V_15 * V_16 , const void * args ,
const struct V_376 * V_421 )
{
struct V_359 * V_360 = F_205 ( V_421 ,
struct V_359 , V_366 ) ;
T_3 * V_125 ;
V_125 = F_207 ( V_16 , 4 ) ;
F_215 ( V_16 , V_360 , V_421 -> V_22 ) ;
* V_125 = F_208 ( ( V_16 -> V_18 - V_125 - 1 ) * 4 ) ;
}
static void
F_245 ( struct V_376 * V_421 )
{
struct V_35 * V_43 = V_421 -> V_22 ;
F_37 ( V_43 ) ;
}
static int
F_229 ( struct V_1 * V_10 ,
struct V_359 * V_360 ,
int V_422 )
{
struct V_4 * V_44 = F_9 ( V_10 ) ;
struct V_35 * V_43 ;
struct V_214 * V_423 ;
int V_38 = 0 ;
F_25 (mirror, &ff_layout->mirrors, mirrors) {
if ( V_38 >= V_422 )
break;
if ( F_246 ( V_43 -> V_55 ) )
continue;
if ( ! F_148 ( V_148 , & V_43 -> V_112 ) )
continue;
if ( ! F_26 ( & V_43 -> V_48 ) )
continue;
V_423 = & V_43 -> V_55 -> V_352 ;
memcpy ( & V_360 -> V_365 , & V_423 -> V_254 , V_26 ) ;
V_360 -> V_64 = 0 ;
V_360 -> V_65 = V_66 ;
F_24 ( & V_43 -> V_50 ) ;
V_360 -> V_361 = V_43 -> V_147 . V_134 . V_141 ;
V_360 -> V_362 = V_43 -> V_147 . V_134 . V_142 ;
V_360 -> V_363 = V_43 -> V_153 . V_134 . V_141 ;
V_360 -> V_364 = V_43 -> V_153 . V_134 . V_142 ;
F_27 ( & V_43 -> V_50 ) ;
V_360 -> V_424 = V_425 ;
V_360 -> V_366 . V_370 = & V_426 ;
V_360 -> V_366 . V_22 = V_43 ;
V_360 ++ ;
V_38 ++ ;
}
return V_38 ;
}
static int
F_247 ( struct V_427 * args )
{
struct V_4 * V_44 ;
const int V_428 = V_429 ;
args -> V_360 = F_248 ( V_428 , sizeof( * args -> V_360 ) , V_154 ) ;
if ( ! args -> V_360 )
return - V_95 ;
F_24 ( & args -> V_2 -> V_47 ) ;
V_44 = F_9 ( F_124 ( args -> V_2 ) -> V_49 ) ;
args -> V_367 = F_229 ( & V_44 -> V_9 ,
& args -> V_360 [ 0 ] , V_428 ) ;
F_27 ( & args -> V_2 -> V_47 ) ;
if ( ! args -> V_367 ) {
F_8 ( args -> V_360 ) ;
args -> V_360 = NULL ;
return - V_430 ;
}
return 0 ;
}
static int
F_249 ( struct V_212 * V_371 ,
const struct V_27 * V_431 )
{
#if F_250 ( V_432 )
V_371 -> V_433 |= V_434 ;
#endif
return 0 ;
}
static int T_11 F_251 ( void )
{
F_18 ( V_435 L_40 ,
V_23 ) ;
if ( ! V_105 ) {
V_105 = F_252 ( 0 ) ;
if ( ! V_105 )
return - V_95 ;
}
return F_253 ( & V_436 ) ;
}
static void T_12 F_254 ( void )
{
F_18 ( V_435 L_41 ,
V_23 ) ;
F_255 ( & V_436 ) ;
if ( V_105 ) {
F_256 ( V_105 ) ;
V_105 = NULL ;
}
}
