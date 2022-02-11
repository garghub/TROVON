static struct V_1 *
F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_3 ) ;
if ( V_5 ) {
F_3 ( & V_5 -> V_6 ) ;
return & V_5 -> V_7 ;
} else
return NULL ;
}
static void
F_4 ( struct V_1 * V_8 )
{
struct V_9 * V_10 , * V_11 ;
F_5 (err, n, &FF_LAYOUT_FROM_HDR(lo)->error_list,
list) {
F_6 ( & V_10 -> V_12 ) ;
F_7 ( V_10 ) ;
}
F_7 ( F_8 ( V_8 ) ) ;
}
static int F_9 ( struct V_13 * V_14 , T_2 * V_15 )
{
T_3 * V_16 ;
V_16 = F_10 ( V_14 , V_17 ) ;
if ( F_11 ( V_16 == NULL ) )
return - V_18 ;
memcpy ( V_15 , V_16 , V_17 ) ;
F_12 ( L_1 , V_19 ,
V_16 [ 0 ] , V_16 [ 1 ] , V_16 [ 2 ] , V_16 [ 3 ] ) ;
return 0 ;
}
static int F_13 ( struct V_13 * V_14 , struct V_20 * V_21 )
{
T_3 * V_16 ;
V_16 = F_10 ( V_14 , V_22 ) ;
if ( F_11 ( ! V_16 ) )
return - V_18 ;
memcpy ( V_21 , V_16 , V_22 ) ;
F_14 ( V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 , struct V_23 * V_24 )
{
T_3 * V_16 ;
V_16 = F_10 ( V_14 , 4 ) ;
if ( F_11 ( ! V_16 ) )
return - V_18 ;
V_24 -> V_25 = F_16 ( V_16 ++ ) ;
if ( V_24 -> V_25 > sizeof( struct V_23 ) ) {
F_17 ( V_26 L_2 ,
V_24 -> V_25 ) ;
return - V_27 ;
}
V_16 = F_10 ( V_14 , V_24 -> V_25 ) ;
if ( F_11 ( ! V_16 ) )
return - V_18 ;
memcpy ( & V_24 -> V_28 , V_16 , V_24 -> V_25 ) ;
F_12 ( L_3 , V_19 , V_24 -> V_25 ) ;
return 0 ;
}
static int
F_18 ( struct V_13 * V_14 , T_4 * V_29 )
{
T_3 * V_16 ;
int V_30 ;
V_16 = F_10 ( V_14 , 4 ) ;
if ( F_11 ( ! V_16 ) )
return - V_18 ;
V_30 = F_16 ( V_16 ++ ) ;
if ( V_30 < 0 )
return - V_31 ;
F_12 ( L_4 , V_19 , V_30 ) ;
V_16 = F_10 ( V_14 , V_30 ) ;
if ( F_11 ( ! V_16 ) )
return - V_18 ;
if ( ! F_19 ( ( char * ) V_16 , V_30 , V_29 ) )
return - V_31 ;
return 0 ;
}
static void F_20 ( struct V_32 * V_33 )
{
int V_34 ;
if ( V_33 -> V_35 ) {
for ( V_34 = 0 ; V_34 < V_33 -> V_36 ; V_34 ++ ) {
if ( V_33 -> V_35 [ V_34 ] ) {
F_7 ( V_33 -> V_35 [ V_34 ] -> V_37 ) ;
F_21 ( V_33 -> V_35 [ V_34 ] -> V_38 ) ;
F_7 ( V_33 -> V_35 [ V_34 ] ) ;
}
}
F_7 ( V_33 -> V_35 ) ;
V_33 -> V_35 = NULL ;
}
}
static int F_22 ( struct V_39 * V_40 )
{
int V_41 = 0 ;
F_12 ( L_5 , V_19 ) ;
if ( V_40 -> V_42 . V_43 != 0 ||
V_40 -> V_42 . V_44 != V_45 ) {
F_12 ( L_6 ,
V_19 ) ;
V_41 = - V_31 ;
}
F_12 ( L_7 , V_19 , V_41 ) ;
return V_41 ;
}
static void F_23 ( struct V_32 * V_33 )
{
if ( V_33 ) {
F_20 ( V_33 ) ;
F_7 ( V_33 ) ;
}
}
static void F_24 ( struct V_32 * V_33 )
{
int V_34 , V_46 ;
for ( V_34 = 0 ; V_34 < V_33 -> V_36 - 1 ; V_34 ++ ) {
for ( V_46 = V_34 + 1 ; V_46 < V_33 -> V_36 ; V_46 ++ )
if ( V_33 -> V_35 [ V_34 ] -> V_47 <
V_33 -> V_35 [ V_46 ] -> V_47 )
F_25 ( V_33 -> V_35 [ V_34 ] ,
V_33 -> V_35 [ V_46 ] ) ;
}
}
static struct V_48 *
F_26 ( struct V_1 * V_49 ,
struct V_39 * V_40 ,
T_1 V_3 )
{
struct V_48 * V_41 ;
struct V_32 * V_33 = NULL ;
struct V_13 V_50 ;
struct V_51 V_52 ;
struct V_53 * V_54 ;
T_5 V_55 ;
T_4 V_36 ;
T_3 * V_16 ;
int V_34 , V_56 ;
F_12 ( L_5 , V_19 ) ;
V_54 = F_27 ( V_3 ) ;
if ( ! V_54 )
return F_28 ( - V_57 ) ;
F_29 ( & V_50 , & V_52 , V_40 -> V_58 -> V_59 ,
V_40 -> V_58 -> V_30 ) ;
F_30 ( & V_50 , F_31 ( V_54 ) , V_60 ) ;
V_56 = - V_61 ;
V_16 = F_10 ( & V_50 , 8 + 4 ) ;
if ( ! V_16 )
goto V_62;
V_16 = F_32 ( V_16 , & V_55 ) ;
V_36 = F_16 ( V_16 ++ ) ;
F_12 ( L_8 , V_19 ,
V_55 , V_36 ) ;
if ( V_36 > V_63 ||
V_36 == 0 )
goto V_62;
V_56 = - V_57 ;
V_33 = F_2 ( sizeof( * V_33 ) , V_3 ) ;
if ( ! V_33 )
goto V_62;
V_33 -> V_36 = V_36 ;
V_33 -> V_55 = V_55 ;
V_33 -> V_35 = F_33 ( V_33 -> V_36 ,
sizeof( V_33 -> V_35 [ 0 ] ) , V_3 ) ;
if ( V_33 -> V_35 == NULL )
goto V_62;
for ( V_34 = 0 ; V_34 < V_33 -> V_36 ; V_34 ++ ) {
struct V_20 V_21 ;
struct V_64 * V_65 ;
T_4 V_66 ;
T_4 V_67 ;
int V_46 ;
V_56 = - V_61 ;
V_16 = F_10 ( & V_50 , 4 ) ;
if ( ! V_16 )
goto V_62;
V_66 = F_16 ( V_16 ) ;
if ( V_66 != 1 )
goto V_62;
V_33 -> V_35 [ V_34 ] =
F_2 ( sizeof( struct V_68 ) ,
V_3 ) ;
if ( V_33 -> V_35 [ V_34 ] == NULL ) {
V_56 = - V_57 ;
goto V_62;
}
F_34 ( & V_33 -> V_35 [ V_34 ] -> V_69 ) ;
V_33 -> V_35 [ V_34 ] -> V_66 = V_66 ;
V_33 -> V_35 [ V_34 ] -> V_70 = & V_33 -> V_7 ;
V_56 = F_13 ( & V_50 , & V_21 ) ;
if ( V_56 )
goto V_62;
V_65 = F_35 ( F_36 ( V_49 -> V_71 ) ,
& V_21 , V_49 -> V_72 ,
V_3 ) ;
if ( V_65 )
V_33 -> V_35 [ V_34 ] -> V_38 =
F_37 ( V_65 ) ;
else
goto V_62;
V_56 = - V_61 ;
V_16 = F_10 ( & V_50 , 4 ) ;
if ( ! V_16 )
goto V_62;
V_33 -> V_35 [ V_34 ] -> V_47 = F_16 ( V_16 ) ;
V_56 = F_9 ( & V_50 , & V_33 -> V_35 [ V_34 ] -> V_15 ) ;
if ( V_56 )
goto V_62;
V_16 = F_10 ( & V_50 , 4 ) ;
if ( ! V_16 )
goto V_62;
V_67 = F_16 ( V_16 ) ;
V_33 -> V_35 [ V_34 ] -> V_37 =
F_2 ( V_67 * sizeof( struct V_23 ) ,
V_3 ) ;
if ( V_33 -> V_35 [ V_34 ] -> V_37 == NULL ) {
V_56 = - V_57 ;
goto V_62;
}
for ( V_46 = 0 ; V_46 < V_67 ; V_46 ++ ) {
V_56 = F_15 ( & V_50 ,
& V_33 -> V_35 [ V_34 ] -> V_37 [ V_46 ] ) ;
if ( V_56 )
goto V_62;
}
V_33 -> V_35 [ V_34 ] -> V_73 = V_67 ;
V_56 = F_18 ( & V_50 , & V_33 -> V_35 [ V_34 ] -> V_74 ) ;
if ( V_56 )
goto V_62;
V_56 = F_18 ( & V_50 , & V_33 -> V_35 [ V_34 ] -> V_75 ) ;
if ( V_56 )
goto V_62;
F_12 ( L_9 , V_19 ,
V_33 -> V_35 [ V_34 ] -> V_74 ,
V_33 -> V_35 [ V_34 ] -> V_75 ) ;
}
V_16 = F_10 ( & V_50 , 4 ) ;
if ( V_16 )
V_33 -> V_76 = F_16 ( V_16 ) ;
F_24 ( V_33 ) ;
V_56 = F_22 ( V_40 ) ;
if ( V_56 )
goto V_62;
V_41 = & V_33 -> V_7 ;
F_12 ( L_10 , V_19 ) ;
V_77:
F_38 ( V_54 ) ;
return V_41 ;
V_62:
F_23 ( V_33 ) ;
V_41 = F_28 ( V_56 ) ;
F_12 ( L_11 , V_19 , V_56 ) ;
goto V_77;
}
static bool F_39 ( struct V_1 * V_78 )
{
struct V_48 * V_70 ;
F_40 (lseg, &layout->plh_segs, pls_list)
if ( V_70 -> V_79 . V_80 == V_81 )
return true ;
return false ;
}
static void
F_41 ( struct V_48 * V_70 )
{
struct V_32 * V_33 = F_42 ( V_70 ) ;
int V_34 ;
F_12 ( L_5 , V_19 ) ;
for ( V_34 = 0 ; V_34 < V_33 -> V_36 ; V_34 ++ ) {
if ( V_33 -> V_35 [ V_34 ] ) {
F_21 ( V_33 -> V_35 [ V_34 ] -> V_38 ) ;
V_33 -> V_35 [ V_34 ] -> V_38 = NULL ;
if ( V_33 -> V_35 [ V_34 ] -> V_82 ) {
F_43 ( V_33 -> V_35 [ V_34 ] -> V_82 ) ;
V_33 -> V_35 [ V_34 ] -> V_82 = NULL ;
}
}
}
if ( V_70 -> V_79 . V_80 == V_81 ) {
struct V_4 * V_5 ;
struct V_2 * V_2 ;
V_5 = F_8 ( V_70 -> V_83 ) ;
V_2 = V_5 -> V_7 . V_71 ;
F_44 ( & V_2 -> V_84 ) ;
if ( ! F_39 ( V_70 -> V_83 ) ) {
V_5 -> V_85 . V_86 = 0 ;
F_7 ( V_5 -> V_85 . V_87 ) ;
V_5 -> V_85 . V_87 = NULL ;
}
F_45 ( & V_2 -> V_84 ) ;
}
F_23 ( V_33 ) ;
}
static int
F_46 ( struct V_32 * V_33 )
{
return 1 ;
}
static void
F_47 ( struct V_88 * V_89 )
{
if ( F_48 ( & V_89 -> V_90 ) == 1 ) {
V_89 -> V_91 = F_49 () ;
}
}
static T_6
F_50 ( struct V_88 * V_89 )
{
T_6 V_92 , V_93 ;
if ( F_51 ( & V_89 -> V_90 ) < 0 )
F_52 ( 1 ) ;
V_93 = F_49 () ;
V_92 = V_89 -> V_91 ;
V_89 -> V_91 = V_93 ;
return F_53 ( V_93 , V_92 ) ;
}
static T_6
F_54 ( struct V_94 * V_95 )
{
return F_53 ( F_49 () , V_95 -> V_96 ) ;
}
static bool
F_55 ( struct V_68 * V_97 ,
struct V_98 * V_99 )
{
static const T_6 V_100 = { 0 } ;
T_6 V_93 = F_49 () ;
F_47 ( & V_99 -> V_101 ) ;
if ( F_56 ( V_97 -> V_91 , V_100 ) )
V_97 -> V_91 = V_93 ;
if ( F_56 ( V_97 -> V_102 , V_100 ) )
V_97 -> V_102 = V_93 ;
if ( F_57 ( F_53 ( V_93 , V_97 -> V_102 ) ) >=
V_103 ) {
V_97 -> V_102 = V_93 ;
return true ;
}
return false ;
}
static void
F_58 ( struct V_98 * V_99 ,
T_7 V_104 )
{
struct V_105 * V_106 = & V_99 -> V_107 ;
V_106 -> V_108 ++ ;
V_106 -> V_109 += V_104 ;
}
static void
F_59 ( struct V_98 * V_99 ,
T_7 V_104 ,
T_7 V_110 ,
T_6 V_111 )
{
struct V_105 * V_106 = & V_99 -> V_107 ;
T_6 V_89 ;
V_106 -> V_112 ++ ;
V_106 -> V_113 += V_110 ;
V_106 -> V_114 += V_104 - V_110 ;
V_89 = F_50 ( & V_99 -> V_101 ) ;
V_106 -> V_115 =
F_60 ( V_106 -> V_115 , V_89 ) ;
V_106 -> V_116 =
F_60 ( V_106 -> V_116 , V_111 ) ;
}
static void
F_61 ( struct V_68 * V_97 ,
T_7 V_104 )
{
bool V_117 ;
F_44 ( & V_97 -> V_69 ) ;
V_117 = F_55 ( V_97 , & V_97 -> V_118 ) ;
F_58 ( & V_97 -> V_118 , V_104 ) ;
F_45 ( & V_97 -> V_69 ) ;
if ( V_117 )
F_62 ( V_97 -> V_70 -> V_83 -> V_71 ) ;
}
static void
F_63 ( struct V_94 * V_95 ,
struct V_68 * V_97 ,
T_7 V_104 ,
T_7 V_110 )
{
F_44 ( & V_97 -> V_69 ) ;
F_59 ( & V_97 -> V_118 ,
V_104 , V_110 ,
F_54 ( V_95 ) ) ;
F_45 ( & V_97 -> V_69 ) ;
}
static void
F_64 ( struct V_68 * V_97 ,
T_7 V_104 )
{
bool V_117 ;
F_44 ( & V_97 -> V_69 ) ;
V_117 = F_55 ( V_97 , & V_97 -> V_119 ) ;
F_58 ( & V_97 -> V_119 , V_104 ) ;
F_45 ( & V_97 -> V_69 ) ;
if ( V_117 )
F_62 ( V_97 -> V_70 -> V_83 -> V_71 ) ;
}
static void
F_65 ( struct V_94 * V_95 ,
struct V_68 * V_97 ,
T_7 V_104 ,
T_7 V_110 ,
enum V_120 V_121 )
{
if ( V_121 == V_122 )
V_104 = V_110 = 0 ;
F_44 ( & V_97 -> V_69 ) ;
F_59 ( & V_97 -> V_119 ,
V_104 , V_110 ,
F_54 ( V_95 ) ) ;
F_45 ( & V_97 -> V_69 ) ;
}
static int
F_66 ( struct V_48 * V_70 ,
struct V_123 * V_124 ,
T_1 V_3 )
{
struct V_32 * V_33 = F_42 ( V_70 ) ;
struct V_125 * V_87 ;
int V_25 ;
if ( V_124 -> V_126 -> V_86 != 0 ) {
return 0 ;
}
V_25 = F_46 ( V_33 ) * F_67 ( V_70 ) ;
V_87 = F_33 ( V_25 , sizeof( struct V_125 ) ,
V_3 ) ;
if ( ! V_87 )
return - V_57 ;
else {
int V_34 ;
F_44 ( V_124 -> V_69 ) ;
if ( V_124 -> V_126 -> V_86 != 0 )
F_7 ( V_87 ) ;
else {
V_124 -> V_126 -> V_87 = V_87 ;
V_124 -> V_126 -> V_86 = V_25 ;
for ( V_34 = 0 ; V_34 < V_25 ; V_34 ++ ) {
F_3 ( & V_87 [ V_34 ] . V_127 ) ;
F_3 ( & V_87 [ V_34 ] . V_128 ) ;
V_87 [ V_34 ] . V_129 . V_121 =
V_130 ;
}
}
F_45 ( V_124 -> V_69 ) ;
return 0 ;
}
}
static struct V_131 *
F_68 ( struct V_132 * V_133 ,
int * V_134 )
{
struct V_32 * V_33 ;
struct V_131 * V_126 ;
int V_135 ;
V_33 = F_42 ( V_133 -> V_136 ) ;
for ( V_135 = 0 ; V_135 < V_33 -> V_36 ; V_135 ++ ) {
V_126 = F_69 ( V_133 -> V_136 , V_135 , false ) ;
if ( V_126 ) {
* V_134 = V_135 ;
return V_126 ;
}
}
return NULL ;
}
static void
F_70 ( struct V_132 * V_133 ,
struct V_137 * V_138 )
{
struct V_139 * V_140 ;
struct V_68 * V_97 ;
struct V_131 * V_126 ;
int V_141 ;
if ( ! V_133 -> V_136 )
V_133 -> V_136 = F_71 ( V_133 -> V_142 ,
V_138 -> V_143 ,
0 ,
V_45 ,
V_144 ,
V_145 ) ;
if ( V_133 -> V_136 == NULL )
goto V_146;
V_126 = F_68 ( V_133 , & V_141 ) ;
if ( ! V_126 )
goto V_146;
V_97 = F_72 ( V_133 -> V_136 , V_141 ) ;
V_133 -> V_147 = V_141 ;
V_140 = & V_133 -> V_148 [ 0 ] ;
V_140 -> V_149 = V_97 -> V_38 -> V_150 [ 0 ] . V_151 ;
return;
V_146:
F_73 ( V_133 -> V_136 ) ;
V_133 -> V_136 = NULL ;
F_74 ( V_133 ) ;
}
static void
F_75 ( struct V_132 * V_133 ,
struct V_137 * V_138 )
{
struct V_68 * V_97 ;
struct V_139 * V_140 ;
struct V_123 V_124 ;
struct V_131 * V_126 ;
int V_34 ;
int V_152 ;
if ( ! V_133 -> V_136 )
V_133 -> V_136 = F_71 ( V_133 -> V_142 ,
V_138 -> V_143 ,
0 ,
V_45 ,
V_81 ,
V_153 ) ;
if ( V_133 -> V_136 == NULL )
goto V_146;
F_76 ( & V_124 , V_133 -> V_142 , V_133 -> V_154 ) ;
V_152 = F_66 ( V_133 -> V_136 , & V_124 , V_153 ) ;
if ( V_152 < 0 )
goto V_146;
if ( F_52 ( V_133 -> V_155 !=
F_67 ( V_133 -> V_136 ) ) )
goto V_146;
for ( V_34 = 0 ; V_34 < V_133 -> V_155 ; V_34 ++ ) {
V_126 = F_69 ( V_133 -> V_136 , V_34 , true ) ;
if ( ! V_126 )
goto V_146;
V_140 = & V_133 -> V_148 [ V_34 ] ;
V_97 = F_72 ( V_133 -> V_136 , V_34 ) ;
V_140 -> V_149 = V_97 -> V_38 -> V_150 [ 0 ] . V_156 ;
}
return;
V_146:
F_73 ( V_133 -> V_136 ) ;
V_133 -> V_136 = NULL ;
F_77 ( V_133 ) ;
}
static unsigned int
F_78 ( struct V_132 * V_133 ,
struct V_137 * V_138 )
{
if ( ! V_133 -> V_136 )
V_133 -> V_136 = F_71 ( V_133 -> V_142 ,
V_138 -> V_143 ,
0 ,
V_45 ,
V_81 ,
V_153 ) ;
if ( V_133 -> V_136 )
return F_67 ( V_133 -> V_136 ) ;
F_73 ( V_133 -> V_136 ) ;
V_133 -> V_136 = NULL ;
F_77 ( V_133 ) ;
return 1 ;
}
static void F_79 ( struct V_157 * V_158 , bool V_159 )
{
struct V_94 * V_95 = & V_158 -> V_95 ;
F_80 ( V_158 -> V_2 , false ) ;
if ( V_159 ) {
F_12 ( L_12
L_13 , V_19 ,
V_158 -> V_95 . V_160 ,
V_158 -> V_2 -> V_161 -> V_162 ,
( unsigned long long ) F_81 ( V_158 -> V_2 ) ,
V_158 -> args . V_163 ,
( unsigned long long ) V_158 -> args . V_43 ) ;
if ( ! V_158 -> V_164 ) {
struct V_165 * V_166 ;
V_166 = F_82 ( V_158 -> V_59 . V_167 ) -> V_143 ;
F_83 ( V_168 , & V_166 -> V_76 ) ;
V_158 -> V_169 -> V_170 ( & V_158 -> V_59 ) ;
} else {
F_84 ( V_158 -> V_164 ) ;
V_158 -> V_171 . V_121 = V_122 ;
V_158 -> V_172 = V_158 -> args . V_163 ;
}
return;
}
if ( ! F_85 ( V_173 , & V_158 -> V_76 ) ) {
F_12 ( L_14
L_13 , V_19 ,
V_158 -> V_95 . V_160 ,
V_158 -> V_2 -> V_161 -> V_162 ,
( unsigned long long ) F_81 ( V_158 -> V_2 ) ,
V_158 -> args . V_163 ,
( unsigned long long ) V_158 -> args . V_43 ) ;
V_95 -> V_174 = F_86 ( V_158 ) ;
}
}
static void F_87 ( struct V_157 * V_158 )
{
struct V_94 * V_95 = & V_158 -> V_95 ;
F_80 ( V_158 -> V_2 , false ) ;
if ( ! F_85 ( V_173 , & V_158 -> V_76 ) ) {
F_12 ( L_14
L_13 , V_19 ,
V_158 -> V_95 . V_160 ,
V_158 -> V_2 -> V_161 -> V_162 ,
( unsigned long long ) F_81 ( V_158 -> V_2 ) ,
V_158 -> args . V_163 ,
( unsigned long long ) V_158 -> args . V_43 ) ;
V_95 -> V_174 = F_88 ( V_158 ) ;
}
}
static int F_89 ( struct V_94 * V_95 ,
struct V_175 * V_176 ,
struct V_177 * V_178 ,
struct V_48 * V_70 ,
int V_135 )
{
struct V_1 * V_8 = V_70 -> V_83 ;
struct V_2 * V_2 = V_8 -> V_71 ;
struct V_179 * V_180 = F_36 ( V_2 ) ;
struct V_64 * V_21 = F_90 ( V_70 , V_135 ) ;
struct V_177 * V_181 = V_180 -> V_177 ;
struct V_182 * V_183 = & V_178 -> V_184 -> V_185 ;
if ( V_95 -> V_174 >= 0 )
return 0 ;
switch ( V_95 -> V_174 ) {
case - V_186 :
case - V_187 :
case - V_188 :
if ( V_176 == NULL )
break;
F_91 ( V_176 -> V_2 ) ;
case - V_189 :
if ( V_176 == NULL )
break;
if ( F_92 ( V_180 , V_176 ) < 0 )
goto V_190;
goto V_191;
case - V_192 :
if ( V_176 != NULL ) {
if ( F_92 ( V_180 , V_176 ) < 0 )
goto V_190;
}
F_93 ( V_181 ) ;
goto V_191;
case - V_193 :
case - V_194 :
case - V_195 :
case - V_196 :
case - V_197 :
case - V_198 :
case - V_199 :
F_12 ( L_15
L_16 , V_19 , V_95 -> V_174 ,
V_178 -> V_200 ) ;
F_94 ( V_178 -> V_184 , V_95 -> V_174 ) ;
break;
case - V_201 :
case - V_202 :
F_95 ( V_95 , V_203 ) ;
break;
case - V_204 :
break;
case - V_205 :
case - V_206 :
case - V_207 :
case - V_208 :
case - V_209 :
case - V_210 :
F_12 ( L_17 , V_19 ,
V_95 -> V_174 ) ;
F_96 ( F_97 ( V_2 ) ) ;
F_98 ( & V_183 -> V_211 ) ;
goto V_212;
case - V_213 :
case - V_214 :
case - V_215 :
case - V_216 :
case - V_61 :
case - V_217 :
case - V_218 :
F_12 ( L_18 , V_19 ,
V_95 -> V_174 ) ;
F_99 ( V_21 ) ;
F_98 ( & V_183 -> V_211 ) ;
default:
if ( F_100 ( V_70 ) )
return - V_219 ;
V_212:
F_12 ( L_19 , V_19 ,
V_95 -> V_174 ) ;
return - V_220 ;
}
V_221:
V_95 -> V_174 = 0 ;
return - V_222 ;
V_190:
V_95 -> V_174 = - V_61 ;
return 0 ;
V_191:
F_101 ( & V_181 -> V_223 , V_95 , NULL ) ;
if ( F_102 ( V_224 , & V_181 -> V_225 ) == 0 )
F_103 ( & V_181 -> V_223 , V_95 ) ;
goto V_221;
}
static int F_104 ( struct V_94 * V_95 ,
struct V_48 * V_70 ,
int V_135 )
{
struct V_64 * V_21 = F_90 ( V_70 , V_135 ) ;
if ( V_95 -> V_174 >= 0 )
return 0 ;
if ( V_95 -> V_174 != - V_226 ) {
F_12 ( L_18 , V_19 ,
V_95 -> V_174 ) ;
F_99 ( V_21 ) ;
if ( F_100 ( V_70 ) )
return - V_219 ;
else
return - V_220 ;
}
if ( V_95 -> V_174 == - V_226 )
F_105 ( V_70 -> V_83 -> V_71 , V_227 ) ;
V_95 -> V_174 = 0 ;
F_106 ( V_95 ) ;
F_95 ( V_95 , V_228 ) ;
return - V_222 ;
}
static int F_107 ( struct V_94 * V_95 ,
struct V_175 * V_176 ,
struct V_177 * V_178 ,
struct V_48 * V_70 ,
int V_135 )
{
int V_229 = V_178 -> V_230 -> V_231 -> V_232 ;
switch ( V_229 ) {
case 3 :
return F_104 ( V_95 , V_70 , V_135 ) ;
case 4 :
return F_89 ( V_95 , V_176 , V_178 ,
V_70 , V_135 ) ;
default:
F_52 ( 1 ) ;
return 0 ;
}
}
static void F_108 ( struct V_48 * V_70 ,
int V_135 , T_5 V_43 , T_5 V_44 ,
T_4 V_152 , int V_233 )
{
struct V_68 * V_97 ;
int V_10 ;
V_97 = F_72 ( V_70 , V_135 ) ;
V_10 = F_109 ( F_8 ( V_70 -> V_83 ) ,
V_97 , V_43 , V_44 , V_152 , V_233 ,
V_234 ) ;
F_12 ( L_20 , V_19 , V_10 , V_233 , V_152 ) ;
}
static int F_110 ( struct V_94 * V_95 ,
struct V_157 * V_158 )
{
struct V_2 * V_2 ;
int V_10 ;
F_111 ( V_158 , V_95 -> V_174 ) ;
if ( V_95 -> V_174 == - V_217 && ! V_158 -> V_235 . V_236 )
V_158 -> V_235 . V_236 = V_237 ;
if ( V_95 -> V_174 < 0 && V_158 -> V_235 . V_236 )
F_108 ( V_158 -> V_70 , V_158 -> V_238 ,
V_158 -> args . V_43 , V_158 -> args . V_163 ,
V_158 -> V_235 . V_236 , V_239 ) ;
V_10 = F_107 ( V_95 , V_158 -> args . V_240 -> V_176 ,
V_158 -> V_241 , V_158 -> V_70 ,
V_158 -> V_238 ) ;
switch ( V_10 ) {
case - V_219 :
F_83 ( V_242 ,
& V_158 -> V_70 -> V_83 -> V_243 ) ;
F_112 ( V_158 ) ;
return V_95 -> V_174 ;
case - V_220 :
V_2 = V_158 -> V_70 -> V_83 -> V_71 ;
F_113 ( V_2 , V_158 -> V_70 ) ;
F_87 ( V_158 ) ;
return V_95 -> V_174 ;
case - V_222 :
F_114 ( V_95 ) ;
return - V_222 ;
}
return 0 ;
}
static bool
F_115 ( struct V_48 * V_70 )
{
return ! ( F_42 ( V_70 ) -> V_76 & V_244 ) ;
}
static void
F_116 ( struct V_157 * V_158 )
{
if ( ! F_115 ( V_158 -> V_70 ) )
return;
F_117 ( V_158 -> V_2 , V_158 -> V_70 ,
V_158 -> V_245 + V_158 -> V_235 . V_163 ) ;
F_12 ( L_21 , V_19 , V_158 -> V_2 -> V_246 ,
( unsigned long ) F_97 ( V_158 -> V_2 ) -> V_78 -> V_247 ) ;
}
static bool
F_118 ( struct V_48 * V_70 , int V_135 )
{
struct V_64 * V_248 = F_90 ( V_70 , V_135 ) ;
return F_119 ( V_248 ) ;
}
static int F_120 ( struct V_94 * V_95 ,
struct V_157 * V_158 )
{
F_61 (
F_72 ( V_158 -> V_70 , V_158 -> V_238 ) ,
V_158 -> args . V_163 ) ;
if ( F_11 ( F_102 ( V_249 , & V_158 -> args . V_240 -> V_76 ) ) ) {
F_121 ( V_95 , - V_61 ) ;
return - V_61 ;
}
if ( F_118 ( V_158 -> V_70 , V_158 -> V_238 ) ) {
F_12 ( L_22 , V_19 , V_95 -> V_160 ) ;
if ( F_100 ( V_158 -> V_70 ) )
F_112 ( V_158 ) ;
else
F_87 ( V_158 ) ;
F_121 ( V_95 , 0 ) ;
return - V_222 ;
}
V_158 -> V_250 = F_110 ;
return 0 ;
}
static void F_122 ( struct V_94 * V_95 , void * V_28 )
{
struct V_157 * V_158 = V_28 ;
if ( F_120 ( V_95 , V_158 ) )
return;
F_123 ( V_95 ) ;
}
static int F_124 ( struct V_177 * V_241 ,
struct V_251 * args ,
struct V_252 * V_235 ,
struct V_94 * V_95 )
{
if ( V_241 -> V_184 )
return F_125 ( V_241 -> V_184 ,
args ,
V_235 ,
V_95 ) ;
return F_126 ( V_241 -> V_253 ,
args ,
V_235 ,
V_95 ) ;
}
static void F_127 ( struct V_94 * V_95 , void * V_28 )
{
struct V_157 * V_158 = V_28 ;
if ( F_124 ( V_158 -> V_241 ,
& V_158 -> args . V_254 ,
& V_158 -> V_235 . V_255 ,
V_95 ) )
return;
if ( F_120 ( V_95 , V_158 ) )
return;
if ( F_128 ( & V_158 -> args . V_15 , V_158 -> args . V_240 ,
V_158 -> args . V_256 , V_257 ) == - V_61 )
F_121 ( V_95 , - V_61 ) ;
}
static void F_129 ( struct V_94 * V_95 , void * V_28 )
{
struct V_157 * V_158 = V_28 ;
F_12 ( L_23 , V_19 , V_95 -> V_174 ) ;
F_63 ( V_95 ,
F_72 ( V_158 -> V_70 , V_158 -> V_238 ) ,
V_158 -> args . V_163 , V_158 -> V_235 . V_163 ) ;
if ( F_102 ( V_173 , & V_158 -> V_76 ) &&
V_95 -> V_174 == 0 ) {
F_130 ( V_95 , & V_158 -> V_235 . V_255 ) ;
return;
}
V_158 -> V_258 -> V_259 ( V_95 , V_158 ) ;
}
static void F_131 ( struct V_94 * V_95 , void * V_28 )
{
struct V_157 * V_158 = V_28 ;
F_132 ( V_95 ,
& F_133 ( V_158 -> V_2 ) -> V_260 [ V_261 ] ) ;
}
static int F_134 ( struct V_94 * V_95 ,
struct V_157 * V_158 )
{
struct V_2 * V_2 ;
int V_10 ;
F_135 ( V_158 , V_95 -> V_174 ) ;
if ( V_95 -> V_174 == - V_217 && ! V_158 -> V_235 . V_236 )
V_158 -> V_235 . V_236 = V_237 ;
if ( V_95 -> V_174 < 0 && V_158 -> V_235 . V_236 )
F_108 ( V_158 -> V_70 , V_158 -> V_238 ,
V_158 -> args . V_43 , V_158 -> args . V_163 ,
V_158 -> V_235 . V_236 , V_262 ) ;
V_10 = F_107 ( V_95 , V_158 -> args . V_240 -> V_176 ,
V_158 -> V_241 , V_158 -> V_70 ,
V_158 -> V_238 ) ;
switch ( V_10 ) {
case - V_219 :
case - V_220 :
V_2 = V_158 -> V_70 -> V_83 -> V_71 ;
F_113 ( V_2 , V_158 -> V_70 ) ;
if ( V_10 == - V_219 ) {
F_136 ( V_158 -> V_70 -> V_83 ) ;
F_79 ( V_158 , true ) ;
} else {
F_137 ( V_158 -> V_70 -> V_83 ) ;
F_79 ( V_158 , false ) ;
}
return V_95 -> V_174 ;
case - V_222 :
F_114 ( V_95 ) ;
return - V_222 ;
}
if ( V_158 -> V_235 . V_171 -> V_121 == V_263 ||
V_158 -> V_235 . V_171 -> V_121 == V_264 )
F_116 ( V_158 ) ;
return 0 ;
}
static int F_138 ( struct V_94 * V_95 ,
struct V_265 * V_28 )
{
struct V_2 * V_2 ;
int V_10 ;
F_139 ( V_28 , V_95 -> V_174 ) ;
if ( V_95 -> V_174 == - V_217 && ! V_28 -> V_235 . V_236 )
V_28 -> V_235 . V_236 = V_237 ;
if ( V_95 -> V_174 < 0 && V_28 -> V_235 . V_236 )
F_108 ( V_28 -> V_70 , V_28 -> V_266 ,
V_28 -> args . V_43 , V_28 -> args . V_163 ,
V_28 -> V_235 . V_236 , V_267 ) ;
V_10 = F_107 ( V_95 , NULL , V_28 -> V_241 ,
V_28 -> V_70 , V_28 -> V_266 ) ;
switch ( V_10 ) {
case - V_219 :
case - V_220 :
V_2 = V_28 -> V_70 -> V_83 -> V_71 ;
F_113 ( V_2 , V_28 -> V_70 ) ;
if ( V_10 == - V_219 )
F_136 ( V_28 -> V_70 -> V_83 ) ;
else
F_137 ( V_28 -> V_70 -> V_83 ) ;
F_140 ( V_28 ) ;
return - V_222 ;
case - V_222 :
F_114 ( V_95 ) ;
return - V_222 ;
}
if ( V_28 -> V_171 . V_121 == V_122
&& F_115 ( V_28 -> V_70 ) )
F_117 ( V_28 -> V_2 , V_28 -> V_70 , V_28 -> V_268 ) ;
return 0 ;
}
static int F_141 ( struct V_94 * V_95 ,
struct V_157 * V_158 )
{
F_64 (
F_72 ( V_158 -> V_70 , V_158 -> V_238 ) ,
V_158 -> args . V_163 ) ;
if ( F_11 ( F_102 ( V_249 , & V_158 -> args . V_240 -> V_76 ) ) ) {
F_121 ( V_95 , - V_61 ) ;
return - V_61 ;
}
if ( F_118 ( V_158 -> V_70 , V_158 -> V_238 ) ) {
bool V_159 ;
V_159 = F_100 ( V_158 -> V_70 ) ;
F_12 ( L_24 , V_19 ,
V_95 -> V_160 , V_159 ? L_25 : L_26 ) ;
F_79 ( V_158 , V_159 ) ;
F_121 ( V_95 , 0 ) ;
return - V_222 ;
}
return 0 ;
}
static void F_142 ( struct V_94 * V_95 , void * V_28 )
{
struct V_157 * V_158 = V_28 ;
if ( F_141 ( V_95 , V_158 ) )
return;
F_123 ( V_95 ) ;
}
static void F_143 ( struct V_94 * V_95 , void * V_28 )
{
struct V_157 * V_158 = V_28 ;
if ( F_124 ( V_158 -> V_241 ,
& V_158 -> args . V_254 ,
& V_158 -> V_235 . V_255 ,
V_95 ) )
return;
if ( F_141 ( V_95 , V_158 ) )
return;
if ( F_128 ( & V_158 -> args . V_15 , V_158 -> args . V_240 ,
V_158 -> args . V_256 , V_269 ) == - V_61 )
F_121 ( V_95 , - V_61 ) ;
}
static void F_144 ( struct V_94 * V_95 , void * V_28 )
{
struct V_157 * V_158 = V_28 ;
F_65 ( V_95 ,
F_72 ( V_158 -> V_70 , V_158 -> V_238 ) ,
V_158 -> args . V_163 , V_158 -> V_235 . V_163 ,
V_158 -> V_235 . V_171 -> V_121 ) ;
if ( F_102 ( V_173 , & V_158 -> V_76 ) &&
V_95 -> V_174 == 0 ) {
F_130 ( V_95 , & V_158 -> V_235 . V_255 ) ;
return;
}
V_158 -> V_258 -> V_259 ( V_95 , V_158 ) ;
}
static void F_145 ( struct V_94 * V_95 , void * V_28 )
{
struct V_157 * V_158 = V_28 ;
F_132 ( V_95 ,
& F_133 ( V_158 -> V_2 ) -> V_260 [ V_270 ] ) ;
}
static void F_146 ( struct V_94 * V_95 ,
struct V_265 * V_271 )
{
F_64 (
F_72 ( V_271 -> V_70 , V_271 -> V_266 ) ,
0 ) ;
}
static void F_147 ( struct V_94 * V_95 , void * V_28 )
{
F_146 ( V_95 , V_28 ) ;
F_123 ( V_95 ) ;
}
static void F_148 ( struct V_94 * V_95 , void * V_28 )
{
struct V_265 * V_272 = V_28 ;
if ( F_124 ( V_272 -> V_241 ,
& V_272 -> args . V_254 ,
& V_272 -> V_235 . V_255 ,
V_95 ) )
return;
F_146 ( V_95 , V_28 ) ;
}
static void F_149 ( struct V_94 * V_95 , void * V_28 )
{
struct V_265 * V_271 = V_28 ;
struct V_137 * V_138 ;
T_7 V_163 = 0 ;
if ( V_95 -> V_174 == 0 ) {
F_40 (req, &cdata->pages, wb_list)
V_163 += V_138 -> V_273 ;
}
F_65 ( V_95 ,
F_72 ( V_271 -> V_70 , V_271 -> V_266 ) ,
V_163 , V_163 , V_263 ) ;
F_150 ( V_95 , V_28 ) ;
}
static void F_151 ( struct V_94 * V_95 , void * V_28 )
{
struct V_265 * V_271 = V_28 ;
F_132 ( V_95 ,
& F_133 ( V_271 -> V_2 ) -> V_260 [ V_274 ] ) ;
}
static enum V_275
F_152 ( struct V_157 * V_158 )
{
struct V_48 * V_70 = V_158 -> V_70 ;
struct V_131 * V_126 ;
struct V_276 * V_277 ;
struct V_278 * V_279 ;
T_8 V_43 = V_158 -> args . V_43 ;
T_4 V_135 = V_158 -> V_238 ;
int V_229 ;
struct V_23 * V_24 ;
F_12 ( L_27 ,
V_19 , V_158 -> V_2 -> V_246 ,
V_158 -> args . V_280 , ( V_281 ) V_158 -> args . V_163 , V_43 ) ;
V_126 = F_69 ( V_70 , V_135 , false ) ;
if ( ! V_126 )
goto V_282;
V_277 = F_153 ( V_70 , V_135 , V_126 -> V_241 ,
V_158 -> V_2 ) ;
if ( F_154 ( V_277 ) )
goto V_282;
V_279 = F_155 ( V_70 , V_135 , V_158 -> V_82 ) ;
if ( F_154 ( V_279 ) )
goto V_282;
V_229 = F_156 ( V_70 , V_135 ) ;
F_12 ( L_28 , V_19 ,
V_126 -> V_283 , F_157 ( & V_126 -> V_241 -> V_284 ) , V_229 ) ;
F_158 ( & V_126 -> V_241 -> V_284 ) ;
V_158 -> V_241 = V_126 -> V_241 ;
V_24 = F_159 ( V_70 , V_135 ) ;
if ( V_24 )
V_158 -> args . V_24 = V_24 ;
V_158 -> args . V_43 = V_43 ;
V_158 -> V_245 = V_43 ;
F_160 ( V_277 , V_158 , V_279 , V_126 -> V_241 -> V_285 ,
V_229 == 3 ? & V_286 :
& V_287 ,
0 , V_288 ) ;
return V_289 ;
V_282:
if ( F_100 ( V_70 ) )
return V_290 ;
return V_291 ;
}
static enum V_275
F_161 ( struct V_157 * V_158 , int V_292 )
{
struct V_48 * V_70 = V_158 -> V_70 ;
struct V_131 * V_126 ;
struct V_276 * V_277 ;
struct V_278 * V_279 ;
T_8 V_43 = V_158 -> args . V_43 ;
int V_229 ;
struct V_23 * V_24 ;
int V_135 = V_158 -> V_238 ;
V_126 = F_69 ( V_70 , V_135 , true ) ;
if ( ! V_126 )
return V_291 ;
V_277 = F_153 ( V_70 , V_135 , V_126 -> V_241 ,
V_158 -> V_2 ) ;
if ( F_154 ( V_277 ) )
return V_291 ;
V_279 = F_155 ( V_70 , V_135 , V_158 -> V_82 ) ;
if ( F_154 ( V_279 ) )
return V_291 ;
V_229 = F_156 ( V_70 , V_135 ) ;
F_12 ( L_29 ,
V_19 , V_158 -> V_2 -> V_246 , V_292 , ( V_281 ) V_158 -> args . V_163 ,
V_43 , V_126 -> V_283 , F_157 ( & V_126 -> V_241 -> V_284 ) ,
V_229 ) ;
V_158 -> V_250 = F_134 ;
F_158 ( & V_126 -> V_241 -> V_284 ) ;
V_158 -> V_241 = V_126 -> V_241 ;
V_158 -> V_293 = V_135 ;
V_24 = F_159 ( V_70 , V_135 ) ;
if ( V_24 )
V_158 -> args . V_24 = V_24 ;
V_158 -> args . V_43 = V_43 ;
F_160 ( V_277 , V_158 , V_279 , V_126 -> V_241 -> V_285 ,
V_229 == 3 ? & V_294 :
& V_295 ,
V_292 , V_288 ) ;
return V_289 ;
}
static T_4 F_162 ( struct V_48 * V_70 , T_4 V_34 )
{
return V_34 ;
}
static struct V_23 *
F_163 ( struct V_48 * V_70 , T_4 V_34 )
{
struct V_32 * V_296 = F_42 ( V_70 ) ;
return & V_296 -> V_35 [ V_34 ] -> V_37 [ 0 ] ;
}
static int F_164 ( struct V_265 * V_28 , int V_297 )
{
struct V_48 * V_70 = V_28 -> V_70 ;
struct V_131 * V_126 ;
struct V_276 * V_277 ;
struct V_278 * V_279 ;
T_4 V_135 ;
int V_229 ;
struct V_23 * V_24 ;
V_135 = F_162 ( V_70 , V_28 -> V_266 ) ;
V_126 = F_69 ( V_70 , V_135 , true ) ;
if ( ! V_126 )
goto V_298;
V_277 = F_153 ( V_70 , V_135 , V_126 -> V_241 ,
V_28 -> V_2 ) ;
if ( F_154 ( V_277 ) )
goto V_298;
V_279 = F_155 ( V_70 , V_135 , V_28 -> V_82 ) ;
if ( F_154 ( V_279 ) )
goto V_298;
V_229 = F_156 ( V_70 , V_135 ) ;
F_12 ( L_30 , V_19 ,
V_28 -> V_2 -> V_246 , V_297 , F_157 ( & V_126 -> V_241 -> V_284 ) ,
V_229 ) ;
V_28 -> V_299 = F_138 ;
V_28 -> V_82 = V_279 ;
F_158 ( & V_126 -> V_241 -> V_284 ) ;
V_28 -> V_241 = V_126 -> V_241 ;
V_24 = F_163 ( V_70 , V_28 -> V_266 ) ;
if ( V_24 )
V_28 -> args . V_24 = V_24 ;
return F_165 ( V_277 , V_28 , V_126 -> V_241 -> V_285 ,
V_229 == 3 ? & V_300 :
& V_301 ,
V_297 , V_288 ) ;
V_298:
F_140 ( V_28 ) ;
F_166 ( V_28 ) ;
return - V_222 ;
}
static int
F_167 ( struct V_2 * V_2 , struct V_302 * V_303 ,
int V_297 , struct V_123 * V_124 )
{
return F_168 ( V_2 , V_303 , V_297 , V_124 ,
F_164 ) ;
}
static struct V_304 *
F_169 ( struct V_2 * V_2 )
{
struct V_1 * V_78 = F_97 ( V_2 ) -> V_78 ;
if ( V_78 == NULL )
return NULL ;
return & F_8 ( V_78 ) -> V_85 ;
}
static void
F_170 ( struct V_64 * V_305 )
{
F_171 ( F_172 ( V_305 , struct V_306 ,
V_307 ) ) ;
}
static int F_173 ( struct V_4 * V_308 ,
struct V_13 * V_14 ,
const struct V_309 * args )
{
struct V_1 * V_158 = & V_308 -> V_7 ;
T_3 * V_92 ;
int V_163 = 0 , V_41 = 0 ;
V_92 = F_174 ( V_14 , 4 ) ;
if ( F_11 ( ! V_92 ) )
return - V_310 ;
F_44 ( & V_158 -> V_71 -> V_84 ) ;
V_41 = F_175 ( V_308 , V_14 , & V_163 , & args -> V_42 ) ;
F_45 ( & V_158 -> V_71 -> V_84 ) ;
* V_92 = F_176 ( V_163 ) ;
return V_41 ;
}
static void F_177 ( struct V_4 * V_308 ,
struct V_13 * V_14 ,
const struct V_309 * args )
{
T_3 * V_16 ;
V_16 = F_174 ( V_14 , 4 ) ;
if ( F_178 ( V_16 ) )
* V_16 = F_176 ( 0 ) ;
}
static struct V_64 *
F_179 ( struct V_179 * V_311 ,
struct V_312 * V_313 , T_1 V_3 )
{
struct V_306 * V_314 ;
V_314 = F_180 ( V_311 , V_313 , V_3 ) ;
if ( ! V_314 )
return NULL ;
return & V_314 -> V_307 ;
}
static void
F_181 ( struct V_1 * V_8 ,
struct V_13 * V_14 ,
const struct V_309 * args )
{
struct V_4 * V_308 = F_8 ( V_8 ) ;
T_3 * V_92 ;
F_12 ( L_31 , V_19 ) ;
V_92 = F_174 ( V_14 , 4 ) ;
F_182 ( ! V_92 ) ;
if ( F_173 ( V_308 , V_14 , args ) )
goto V_221;
F_177 ( V_308 , V_14 , args ) ;
V_221:
* V_92 = F_176 ( ( V_14 -> V_16 - V_92 - 1 ) * 4 ) ;
F_12 ( L_32 , V_19 ) ;
}
static int
F_183 ( const struct V_315 * V_316 , char * V_52 , const V_281 V_317 )
{
const struct V_318 * sin = (struct V_318 * ) V_316 ;
return snprintf ( V_52 , V_317 , L_33 , & sin -> V_319 ) ;
}
static V_281
F_184 ( const struct V_315 * V_316 , char * V_52 ,
const int V_317 )
{
const struct V_320 * V_321 = (struct V_320 * ) V_316 ;
const struct V_322 * V_323 = & V_321 -> V_324 ;
if ( F_185 ( V_323 ) )
return snprintf ( V_52 , V_317 , L_34 ) ;
if ( F_186 ( V_323 ) )
return snprintf ( V_52 , V_317 , L_35 ) ;
if ( F_187 ( V_323 ) )
return snprintf ( V_52 , V_317 , L_36 ,
& V_323 -> V_325 [ 3 ] ) ;
return snprintf ( V_52 , V_317 , L_37 , V_323 ) ;
}
static void
F_188 ( struct V_13 * V_14 , struct V_326 * V_327 )
{
struct V_315 * V_316 = (struct V_315 * ) & V_327 -> V_328 ;
char V_329 [ V_330 ] ;
char V_331 [ V_332 ] ;
char * V_333 ;
unsigned short V_334 ;
int V_30 , V_335 ;
T_3 * V_16 ;
switch ( V_316 -> V_336 ) {
case V_337 :
if ( F_183 ( V_316 , V_331 , sizeof( V_331 ) ) == 0 )
return;
V_334 = F_189 ( ( (struct V_318 * ) V_316 ) -> V_338 ) ;
V_333 = L_38 ;
V_335 = 3 ;
break;
case V_339 :
if ( F_184 ( V_316 , V_331 , sizeof( V_331 ) ) == 0 )
return;
V_334 = F_189 ( ( (struct V_320 * ) V_316 ) -> V_340 ) ;
V_333 = L_39 ;
V_335 = 4 ;
break;
default:
F_52 ( 1 ) ;
return;
}
snprintf ( V_329 , sizeof( V_329 ) , L_40 , V_334 >> 8 , V_334 & 0xff ) ;
V_30 = F_190 ( V_331 , V_329 , sizeof( V_331 ) ) ;
V_16 = F_174 ( V_14 , 4 + V_335 ) ;
F_191 ( V_16 , V_333 , V_335 ) ;
V_16 = F_174 ( V_14 , 4 + V_30 ) ;
F_191 ( V_16 , V_331 , V_30 ) ;
}
static void
F_192 ( struct V_13 * V_14 ,
T_6 V_341 )
{
struct V_342 V_343 ;
T_3 * V_16 ;
V_16 = F_174 ( V_14 , 12 ) ;
V_343 = F_193 ( V_341 ) ;
V_16 = F_194 ( V_16 , V_343 . V_344 ) ;
* V_16 ++ = F_176 ( V_343 . V_345 ) ;
}
static void
F_195 ( struct V_13 * V_14 ,
struct V_105 * V_346 )
{
T_3 * V_16 ;
V_16 = F_174 ( V_14 , 5 * 8 ) ;
V_16 = F_194 ( V_16 , V_346 -> V_108 ) ;
V_16 = F_194 ( V_16 , V_346 -> V_109 ) ;
V_16 = F_194 ( V_16 , V_346 -> V_112 ) ;
V_16 = F_194 ( V_16 , V_346 -> V_113 ) ;
V_16 = F_194 ( V_16 , V_346 -> V_114 ) ;
F_192 ( V_14 , V_346 -> V_115 ) ;
F_192 ( V_14 , V_346 -> V_116 ) ;
}
static void
F_196 ( struct V_13 * V_14 ,
struct V_347 * args ,
struct V_348 * V_349 )
{
struct V_68 * V_97 = V_349 -> V_350 ;
struct V_326 * V_327 ;
struct V_131 * V_126 = V_97 -> V_38 -> V_126 ;
struct V_23 * V_24 = & V_97 -> V_37 [ 0 ] ;
T_3 * V_16 , * V_92 ;
V_327 = F_197 ( & V_126 -> V_351 , struct V_326 , V_352 ) ;
F_12 ( L_41 ,
V_19 , V_126 -> V_283 , V_327 -> V_353 ) ;
V_92 = F_174 ( V_14 , 4 ) ;
F_188 ( V_14 , V_327 ) ;
V_16 = F_174 ( V_14 , 4 + V_24 -> V_25 ) ;
F_191 ( V_16 , V_24 -> V_28 , V_24 -> V_25 ) ;
F_44 ( & V_97 -> V_69 ) ;
F_195 ( V_14 , & V_97 -> V_118 . V_107 ) ;
F_195 ( V_14 , & V_97 -> V_119 . V_107 ) ;
F_45 ( & V_97 -> V_69 ) ;
F_192 ( V_14 , F_53 ( F_49 () , V_97 -> V_91 ) ) ;
V_16 = F_174 ( V_14 , 4 ) ;
* V_16 = F_176 ( false ) ;
* V_92 = F_176 ( ( V_14 -> V_16 - V_92 - 1 ) * 4 ) ;
}
static bool
F_198 ( struct V_347 * args ,
struct V_48 * V_354 ,
int * V_355 , int V_356 )
{
struct V_68 * V_97 ;
struct V_64 * V_357 ;
struct V_348 * V_349 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < F_67 ( V_354 ) ; V_34 ++ ) {
if ( * V_355 >= V_356 )
break;
V_97 = F_72 ( V_354 , V_34 ) ;
if ( ! V_97 || ! V_97 -> V_38 )
continue;
V_357 = F_90 ( V_354 , V_34 ) ;
V_349 = & args -> V_349 [ * V_355 ] ;
memcpy ( & V_349 -> V_358 , & V_357 -> V_359 , V_22 ) ;
V_349 -> V_43 = V_354 -> V_79 . V_43 ;
V_349 -> V_44 = V_354 -> V_79 . V_44 ;
V_349 -> V_360 = V_97 -> V_118 . V_107 . V_113 ;
V_349 -> V_361 = V_97 -> V_118 . V_107 . V_113 ;
V_349 -> V_362 = V_97 -> V_119 . V_107 . V_113 ;
V_349 -> V_363 = V_97 -> V_119 . V_107 . V_113 ;
V_349 -> V_364 = V_365 ;
V_349 -> V_366 = F_196 ;
V_349 -> V_350 = V_97 ;
F_199 ( V_354 ) ;
++ ( * V_355 ) ;
}
return * V_355 < V_356 ;
}
static int
F_200 ( struct V_347 * args )
{
struct V_48 * V_354 ;
int V_355 = 0 ;
F_44 ( & args -> V_2 -> V_84 ) ;
F_40 (pls, &NFS_I(args->inode)->layout->plh_segs, pls_list) {
V_355 += F_67 ( V_354 ) ;
}
F_45 ( & args -> V_2 -> V_84 ) ;
if ( V_355 > V_367 ) {
F_12 ( L_42 ,
V_19 , V_355 , V_367 ) ;
V_355 = V_367 ;
}
args -> V_349 = F_201 ( V_355 * sizeof( * args -> V_349 ) , V_145 ) ;
if ( ! args -> V_349 )
return - V_57 ;
V_355 = 0 ;
F_44 ( & args -> V_2 -> V_84 ) ;
F_40 (pls, &NFS_I(args->inode)->layout->plh_segs, pls_list) {
if ( ! F_198 ( args , V_354 , & V_355 ,
V_367 ) ) {
break;
}
}
F_45 ( & args -> V_2 -> V_84 ) ;
args -> V_368 = V_355 ;
return 0 ;
}
static void
F_202 ( struct V_369 * V_28 )
{
struct V_68 * V_97 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_28 -> args . V_368 ; V_34 ++ ) {
V_97 = V_28 -> args . V_349 [ V_34 ] . V_350 ;
V_28 -> args . V_349 [ V_34 ] . V_350 = NULL ;
F_73 ( V_97 -> V_70 ) ;
}
}
static int T_9 F_203 ( void )
{
F_17 ( V_370 L_43 ,
V_19 ) ;
return F_204 ( & V_371 ) ;
}
static void T_10 F_205 ( void )
{
F_17 ( V_370 L_44 ,
V_19 ) ;
F_206 ( & V_371 ) ;
}
