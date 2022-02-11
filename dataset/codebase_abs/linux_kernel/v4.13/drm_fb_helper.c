int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_5 * * V_7 ;
unsigned int V_8 ;
if ( ! V_9 )
return 0 ;
F_2 ( ! F_3 ( & V_2 -> V_10 -> V_11 . V_12 ) ) ;
V_8 = V_2 -> V_13 + 1 ;
if ( V_8 > V_2 -> V_14 ) {
T_1 V_15 = V_8 * sizeof( V_6 ) ;
V_7 = F_4 ( V_2 -> V_16 , V_15 , V_17 ) ;
if ( ! V_7 )
return - V_18 ;
V_2 -> V_14 = V_8 ;
V_2 -> V_16 = V_7 ;
}
V_6 = F_5 ( sizeof( * V_6 ) , V_17 ) ;
if ( ! V_6 )
return - V_18 ;
F_6 ( V_4 ) ;
V_6 -> V_4 = V_4 ;
V_2 -> V_16 [ V_2 -> V_13 ++ ] = V_6 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_19 * V_10 = V_2 -> V_10 ;
struct V_3 * V_4 ;
struct V_20 V_21 ;
int V_22 , V_23 = 0 ;
if ( ! V_9 )
return 0 ;
F_8 ( & V_10 -> V_11 . V_12 ) ;
F_9 ( V_10 , & V_21 ) ;
F_10 (connector, &conn_iter) {
V_23 = F_1 ( V_2 , V_4 ) ;
if ( V_23 )
goto V_24;
}
goto V_25;
V_24:
F_11 (fb_helper, i) {
struct V_5 * V_26 =
V_2 -> V_16 [ V_22 ] ;
F_12 ( V_26 -> V_4 ) ;
F_13 ( V_26 ) ;
V_2 -> V_16 [ V_22 ] = NULL ;
}
V_2 -> V_13 = 0 ;
V_25:
F_14 ( & V_21 ) ;
F_15 ( & V_10 -> V_11 . V_12 ) ;
return V_23 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_26 ;
int V_22 , V_27 ;
if ( ! V_9 )
return 0 ;
F_2 ( ! F_3 ( & V_2 -> V_10 -> V_11 . V_12 ) ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_13 ; V_22 ++ ) {
if ( V_2 -> V_16 [ V_22 ] -> V_4 == V_4 )
break;
}
if ( V_22 == V_2 -> V_13 )
return - V_28 ;
V_26 = V_2 -> V_16 [ V_22 ] ;
F_12 ( V_26 -> V_4 ) ;
for ( V_27 = V_22 + 1 ; V_27 < V_2 -> V_13 ; V_27 ++ )
V_2 -> V_16 [ V_27 - 1 ] = V_2 -> V_16 [ V_27 ] ;
V_2 -> V_13 -- ;
F_13 ( V_26 ) ;
return 0 ;
}
static void F_17 ( struct V_29 * V_30 , struct V_1 * V_31 )
{
T_2 * V_32 , * V_33 , * V_34 ;
int V_22 ;
if ( V_31 -> V_35 -> V_36 == NULL )
return;
V_32 = V_30 -> V_37 ;
V_33 = V_32 + V_30 -> V_38 ;
V_34 = V_33 + V_30 -> V_38 ;
for ( V_22 = 0 ; V_22 < V_30 -> V_38 ; V_22 ++ )
V_31 -> V_35 -> V_36 ( V_30 , & V_32 [ V_22 ] , & V_33 [ V_22 ] , & V_34 [ V_22 ] , V_22 ) ;
}
static void F_18 ( struct V_29 * V_30 )
{
T_2 * V_32 , * V_33 , * V_34 ;
if ( V_30 -> V_35 -> V_39 == NULL )
return;
V_32 = V_30 -> V_37 ;
V_33 = V_32 + V_30 -> V_38 ;
V_34 = V_33 + V_30 -> V_38 ;
V_30 -> V_35 -> V_39 ( V_30 , V_32 , V_33 , V_34 ,
V_30 -> V_38 , NULL ) ;
}
int F_19 ( struct V_40 * V_41 )
{
struct V_1 * V_31 = V_41 -> V_42 ;
const struct V_43 * V_35 ;
int V_22 ;
F_20 (helper, &kernel_fb_helper_list, kernel_fb_list) {
for ( V_22 = 0 ; V_22 < V_31 -> V_44 ; V_22 ++ ) {
struct V_45 * V_46 =
& V_31 -> V_47 [ V_22 ] . V_46 ;
if ( ! V_46 -> V_30 -> V_48 )
continue;
V_35 = V_46 -> V_30 -> V_49 ;
if ( V_35 -> V_50 == NULL )
continue;
if ( F_21 ( V_46 -> V_30 -> V_10 ) )
continue;
F_17 ( V_46 -> V_30 , V_31 ) ;
V_35 -> V_50 ( V_46 -> V_30 ,
V_46 -> V_51 ,
V_46 -> V_52 ,
V_46 -> V_53 ,
V_54 ) ;
}
}
return 0 ;
}
static struct V_55 * F_22 ( struct V_29 * V_30 )
{
struct V_19 * V_10 = V_30 -> V_10 ;
struct V_29 * V_56 ;
F_23 (c, dev) {
if ( V_30 -> V_57 . V_58 == V_56 -> V_57 . V_58 )
return V_56 -> V_59 -> V_51 ;
}
return NULL ;
}
int F_24 ( struct V_40 * V_41 )
{
struct V_1 * V_31 = V_41 -> V_42 ;
struct V_29 * V_30 ;
const struct V_43 * V_35 ;
struct V_55 * V_51 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_31 -> V_44 ; V_22 ++ ) {
struct V_45 * V_46 = & V_31 -> V_47 [ V_22 ] . V_46 ;
V_30 = V_46 -> V_30 ;
V_35 = V_30 -> V_49 ;
V_51 = F_22 ( V_30 ) ;
if ( ! V_30 -> V_48 )
continue;
if ( ! V_51 ) {
F_25 ( L_1 ) ;
continue;
}
if ( V_35 -> V_50 == NULL )
continue;
if ( F_21 ( V_30 -> V_10 ) )
continue;
F_18 ( V_46 -> V_30 ) ;
V_35 -> V_50 ( V_46 -> V_30 , V_51 , V_30 -> V_52 ,
V_30 -> V_53 , V_60 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_19 * V_10 = V_2 -> V_10 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
int V_22 , V_23 ;
unsigned int V_65 ;
V_64 = F_27 ( V_10 ) ;
if ( ! V_64 )
return - V_18 ;
V_64 -> V_66 = V_10 -> V_11 . V_66 ;
V_67:
V_65 = 0 ;
F_28 (plane, dev) {
struct V_68 * V_69 ;
V_69 = F_29 ( V_64 , V_62 ) ;
if ( F_30 ( V_69 ) ) {
V_23 = F_31 ( V_69 ) ;
goto V_24;
}
V_69 -> V_70 = V_71 ;
V_62 -> V_72 = V_62 -> V_51 ;
V_65 |= 1 << F_32 ( V_62 ) ;
if ( V_62 -> type == V_73 )
continue;
V_23 = F_33 ( V_62 , V_69 ) ;
if ( V_23 != 0 )
goto V_24;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_44 ; V_22 ++ ) {
struct V_45 * V_46 = & V_2 -> V_47 [ V_22 ] . V_46 ;
V_23 = F_34 ( V_46 , V_64 ) ;
if ( V_23 != 0 )
goto V_24;
}
V_23 = F_35 ( V_64 ) ;
V_24:
F_36 ( V_10 , V_65 , V_23 ) ;
if ( V_23 == - V_74 )
goto V_75;
F_37 ( V_64 ) ;
return V_23 ;
V_75:
F_38 ( V_64 ) ;
F_39 ( V_64 ) ;
goto V_67;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_19 * V_10 = V_2 -> V_10 ;
struct V_61 * V_62 ;
int V_22 ;
F_28 (plane, dev) {
if ( V_62 -> type != V_73 )
F_41 ( V_62 ) ;
if ( V_62 -> V_76 )
F_42 ( V_62 ,
V_62 -> V_76 ,
V_71 ) ;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_44 ; V_22 ++ ) {
struct V_45 * V_46 = & V_2 -> V_47 [ V_22 ] . V_46 ;
struct V_29 * V_30 = V_46 -> V_30 ;
int V_23 ;
if ( V_30 -> V_35 -> V_77 ) {
V_23 = V_30 -> V_35 -> V_77 ( V_30 , NULL , 0 , 0 , 0 , 0 , 0 ) ;
if ( V_23 )
return V_23 ;
} else if ( V_30 -> V_35 -> V_78 ) {
V_23 = V_30 -> V_35 -> V_78 ( V_30 , NULL , 0 , 0 , 0 ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_43 ( V_46 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_19 * V_10 = V_2 -> V_10 ;
F_45 ( V_10 ) ;
if ( F_21 ( V_10 ) )
return F_26 ( V_2 ) ;
else
return F_40 ( V_2 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_19 * V_10 = V_2 -> V_10 ;
bool V_79 ;
int V_23 ;
if ( ! V_9 )
return - V_80 ;
F_47 ( V_10 ) ;
V_23 = F_44 ( V_2 ) ;
V_79 = V_2 -> V_81 ;
if ( V_79 )
V_2 -> V_81 = false ;
F_48 ( V_10 ) ;
if ( V_79 )
F_49 ( V_2 ) ;
return V_23 ;
}
static bool F_50 ( struct V_1 * V_2 )
{
struct V_19 * V_10 = V_2 -> V_10 ;
struct V_29 * V_30 ;
int V_82 = 0 , V_83 = 0 ;
if ( F_51 ( V_10 -> V_84 ) )
return false ;
F_23 (crtc, dev) {
if ( V_30 -> V_59 -> V_51 )
V_83 ++ ;
if ( V_30 -> V_59 -> V_51 == V_2 -> V_51 )
V_82 ++ ;
}
if ( V_82 < V_83 )
return false ;
return true ;
}
static bool F_52 ( void )
{
bool V_23 , error = false ;
struct V_1 * V_31 ;
if ( F_53 ( & V_85 ) )
return false ;
F_20 (helper, &kernel_fb_helper_list, kernel_fb_list) {
struct V_19 * V_10 = V_31 -> V_10 ;
if ( V_10 -> V_86 == V_87 )
continue;
F_47 ( V_10 ) ;
V_23 = F_44 ( V_31 ) ;
if ( V_23 )
error = true ;
F_48 ( V_10 ) ;
}
return error ;
}
static void F_54 ( struct V_88 * V_89 )
{
bool V_23 ;
V_23 = F_52 () ;
if ( V_23 == true )
F_25 ( L_2 ) ;
}
static void F_55 ( int V_90 )
{
F_56 ( & V_91 ) ;
}
static void F_57 ( struct V_40 * V_41 , int V_92 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_19 * V_10 = V_2 -> V_10 ;
struct V_29 * V_30 ;
struct V_3 * V_4 ;
int V_22 , V_27 ;
F_47 ( V_10 ) ;
if ( ! F_50 ( V_2 ) ) {
F_48 ( V_10 ) ;
return;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_44 ; V_22 ++ ) {
V_30 = V_2 -> V_47 [ V_22 ] . V_46 . V_30 ;
if ( ! V_30 -> V_48 )
continue;
F_11 (fb_helper, j) {
V_4 = V_2 -> V_16 [ V_27 ] -> V_4 ;
V_4 -> V_35 -> V_93 ( V_4 , V_92 ) ;
F_58 ( & V_4 -> V_57 ,
V_10 -> V_11 . V_94 , V_92 ) ;
}
}
F_48 ( V_10 ) ;
}
int F_59 ( int V_95 , struct V_40 * V_41 )
{
if ( V_96 )
return - V_97 ;
switch ( V_95 ) {
case V_98 :
F_57 ( V_41 , V_99 ) ;
break;
case V_100 :
F_57 ( V_41 , V_101 ) ;
break;
case V_102 :
F_57 ( V_41 , V_101 ) ;
break;
case V_103 :
F_57 ( V_41 , V_104 ) ;
break;
case V_105 :
F_57 ( V_41 , V_106 ) ;
break;
}
return 0 ;
}
static void F_60 ( struct V_1 * V_31 ,
struct V_45 * V_107 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_107 -> V_108 ; V_22 ++ ) {
F_12 ( V_107 -> V_109 [ V_22 ] ) ;
V_107 -> V_109 [ V_22 ] = NULL ;
}
V_107 -> V_108 = 0 ;
F_61 ( V_31 -> V_10 , V_107 -> V_110 ) ;
V_107 -> V_110 = NULL ;
V_107 -> V_51 = NULL ;
}
static void F_62 ( struct V_1 * V_31 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_31 -> V_13 ; V_22 ++ ) {
F_12 ( V_31 -> V_16 [ V_22 ] -> V_4 ) ;
F_13 ( V_31 -> V_16 [ V_22 ] ) ;
}
F_13 ( V_31 -> V_16 ) ;
for ( V_22 = 0 ; V_22 < V_31 -> V_44 ; V_22 ++ ) {
struct V_45 * V_107 = & V_31 -> V_47 [ V_22 ] . V_46 ;
F_60 ( V_31 , V_107 ) ;
F_13 ( V_107 -> V_109 ) ;
}
F_13 ( V_31 -> V_47 ) ;
}
static void F_63 ( struct V_88 * V_111 )
{
struct V_1 * V_31 = F_64 ( V_111 , struct V_1 ,
V_112 ) ;
F_65 () ;
F_66 ( V_31 -> V_113 , 0 ) ;
F_67 () ;
}
static void F_68 ( struct V_88 * V_111 )
{
struct V_1 * V_31 = F_64 ( V_111 , struct V_1 ,
V_114 ) ;
struct V_115 * V_116 = & V_31 -> V_117 ;
struct V_115 V_118 ;
unsigned long V_119 ;
F_69 ( & V_31 -> V_120 , V_119 ) ;
V_118 = * V_116 ;
V_116 -> V_121 = V_116 -> y1 = ~ 0 ;
V_116 -> V_122 = V_116 -> V_123 = 0 ;
F_70 ( & V_31 -> V_120 , V_119 ) ;
if ( V_118 . V_121 < V_118 . V_122 && V_118 . y1 < V_118 . V_123 )
V_31 -> V_51 -> V_35 -> V_124 ( V_31 -> V_51 , NULL , 0 , 0 , & V_118 , 1 ) ;
}
void F_71 ( struct V_19 * V_10 , struct V_1 * V_31 ,
const struct V_125 * V_35 )
{
F_72 ( & V_31 -> V_126 ) ;
F_73 ( & V_31 -> V_120 ) ;
F_74 ( & V_31 -> V_112 , F_63 ) ;
F_74 ( & V_31 -> V_114 , F_68 ) ;
V_31 -> V_117 . V_121 = V_31 -> V_117 . y1 = ~ 0 ;
V_31 -> V_35 = V_35 ;
V_31 -> V_10 = V_10 ;
}
int F_75 ( struct V_19 * V_10 ,
struct V_1 * V_2 ,
int V_127 )
{
struct V_29 * V_30 ;
struct V_128 * V_129 = & V_10 -> V_11 ;
int V_22 ;
if ( ! V_9 )
return 0 ;
if ( ! V_127 )
return - V_28 ;
V_2 -> V_47 = F_76 ( V_129 -> V_130 , sizeof( struct V_131 ) , V_17 ) ;
if ( ! V_2 -> V_47 )
return - V_18 ;
V_2 -> V_44 = V_129 -> V_130 ;
V_2 -> V_16 = F_76 ( V_10 -> V_11 . V_132 , sizeof( struct V_5 * ) , V_17 ) ;
if ( ! V_2 -> V_16 ) {
F_13 ( V_2 -> V_47 ) ;
return - V_18 ;
}
V_2 -> V_14 = V_10 -> V_11 . V_132 ;
V_2 -> V_13 = 0 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_44 ; V_22 ++ ) {
V_2 -> V_47 [ V_22 ] . V_46 . V_109 =
F_76 ( V_127 ,
sizeof( struct V_3 * ) ,
V_17 ) ;
if ( ! V_2 -> V_47 [ V_22 ] . V_46 . V_109 )
goto V_133;
V_2 -> V_47 [ V_22 ] . V_46 . V_108 = 0 ;
}
V_22 = 0 ;
F_23 (crtc, dev) {
V_2 -> V_47 [ V_22 ] . V_46 . V_30 = V_30 ;
V_22 ++ ;
}
return 0 ;
V_133:
F_62 ( V_2 ) ;
return - V_18 ;
}
struct V_40 * F_77 ( struct V_1 * V_2 )
{
struct V_134 * V_10 = V_2 -> V_10 -> V_10 ;
struct V_40 * V_41 ;
int V_23 ;
V_41 = F_78 ( 0 , V_10 ) ;
if ( ! V_41 )
return F_79 ( - V_18 ) ;
V_23 = F_80 ( & V_41 -> V_135 , 256 , 0 ) ;
if ( V_23 )
goto V_136;
V_41 -> V_137 = F_81 ( 1 ) ;
if ( ! V_41 -> V_137 ) {
V_23 = - V_18 ;
goto V_138;
}
V_2 -> V_113 = V_41 ;
return V_41 ;
V_138:
F_82 ( & V_41 -> V_135 ) ;
V_136:
F_83 ( V_41 ) ;
return F_79 ( V_23 ) ;
}
void F_84 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_113 )
F_85 ( V_2 -> V_113 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
struct V_40 * V_41 ;
if ( ! V_9 || ! V_2 )
return;
V_41 = V_2 -> V_113 ;
if ( V_41 ) {
if ( V_41 -> V_135 . V_139 )
F_82 ( & V_41 -> V_135 ) ;
F_83 ( V_41 ) ;
}
V_2 -> V_113 = NULL ;
F_87 ( & V_2 -> V_112 ) ;
F_87 ( & V_2 -> V_114 ) ;
F_8 ( & V_140 ) ;
if ( ! F_53 ( & V_2 -> V_126 ) ) {
F_88 ( & V_2 -> V_126 ) ;
if ( F_53 ( & V_85 ) )
F_89 ( 'v' , & V_141 ) ;
}
F_15 ( & V_140 ) ;
F_62 ( V_2 ) ;
}
void F_90 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_113 )
F_91 ( V_2 -> V_113 ) ;
}
static void F_92 ( struct V_40 * V_41 , T_3 V_52 , T_3 V_53 ,
T_3 V_142 , T_3 V_143 )
{
struct V_1 * V_31 = V_41 -> V_42 ;
struct V_115 * V_116 = & V_31 -> V_117 ;
unsigned long V_119 ;
if ( ! V_31 -> V_51 -> V_35 -> V_124 )
return;
F_69 ( & V_31 -> V_120 , V_119 ) ;
V_116 -> V_121 = F_93 ( T_3 , V_116 -> V_121 , V_52 ) ;
V_116 -> y1 = F_93 ( T_3 , V_116 -> y1 , V_53 ) ;
V_116 -> V_122 = F_94 ( T_3 , V_116 -> V_122 , V_52 + V_142 ) ;
V_116 -> V_123 = F_94 ( T_3 , V_116 -> V_123 , V_53 + V_143 ) ;
F_70 ( & V_31 -> V_120 , V_119 ) ;
F_56 ( & V_31 -> V_114 ) ;
}
void F_95 ( struct V_40 * V_41 ,
struct V_144 * V_145 )
{
unsigned long V_146 , V_147 , V_148 , V_149 ;
struct V_150 * V_150 ;
T_3 y1 , V_123 ;
V_148 = V_151 ;
V_149 = 0 ;
F_20 (page, pagelist, lru) {
V_146 = V_150 -> V_152 << V_153 ;
V_147 = V_146 + V_154 - 1 ;
V_148 = V_148 ( V_148 , V_146 ) ;
V_149 = V_149 ( V_149 , V_147 ) ;
}
if ( V_148 < V_149 ) {
y1 = V_148 / V_41 -> V_155 . V_156 ;
V_123 = F_93 ( T_3 , F_96 ( V_149 , V_41 -> V_155 . V_156 ) ,
V_41 -> V_157 . V_158 ) ;
F_92 ( V_41 , 0 , y1 , V_41 -> V_157 . V_159 , V_123 - y1 ) ;
}
}
T_4 F_97 ( struct V_40 * V_41 , char T_5 * V_160 ,
T_1 V_8 , T_6 * V_161 )
{
return F_98 ( V_41 , V_160 , V_8 , V_161 ) ;
}
T_4 F_99 ( struct V_40 * V_41 , const char T_5 * V_160 ,
T_1 V_8 , T_6 * V_161 )
{
T_4 V_23 ;
V_23 = F_100 ( V_41 , V_160 , V_8 , V_161 ) ;
if ( V_23 > 0 )
F_92 ( V_41 , 0 , 0 , V_41 -> V_157 . V_159 ,
V_41 -> V_157 . V_158 ) ;
return V_23 ;
}
void F_101 ( struct V_40 * V_41 ,
const struct V_162 * V_163 )
{
F_102 ( V_41 , V_163 ) ;
F_92 ( V_41 , V_163 -> V_164 , V_163 -> V_165 ,
V_163 -> V_142 , V_163 -> V_143 ) ;
}
void F_103 ( struct V_40 * V_41 ,
const struct V_166 * V_167 )
{
F_104 ( V_41 , V_167 ) ;
F_92 ( V_41 , V_167 -> V_164 , V_167 -> V_165 ,
V_167 -> V_142 , V_167 -> V_143 ) ;
}
void F_105 ( struct V_40 * V_41 ,
const struct V_168 * V_169 )
{
F_106 ( V_41 , V_169 ) ;
F_92 ( V_41 , V_169 -> V_164 , V_169 -> V_165 ,
V_169 -> V_142 , V_169 -> V_143 ) ;
}
void F_107 ( struct V_40 * V_41 ,
const struct V_162 * V_163 )
{
F_108 ( V_41 , V_163 ) ;
F_92 ( V_41 , V_163 -> V_164 , V_163 -> V_165 ,
V_163 -> V_142 , V_163 -> V_143 ) ;
}
void F_109 ( struct V_40 * V_41 ,
const struct V_166 * V_167 )
{
F_110 ( V_41 , V_167 ) ;
F_92 ( V_41 , V_167 -> V_164 , V_167 -> V_165 ,
V_167 -> V_142 , V_167 -> V_143 ) ;
}
void F_111 ( struct V_40 * V_41 ,
const struct V_168 * V_169 )
{
F_112 ( V_41 , V_169 ) ;
F_92 ( V_41 , V_169 -> V_164 , V_169 -> V_165 ,
V_169 -> V_142 , V_169 -> V_143 ) ;
}
void F_113 ( struct V_1 * V_2 , bool V_170 )
{
if ( V_2 && V_2 -> V_113 )
F_66 ( V_2 -> V_113 , V_170 ) ;
}
void F_114 ( struct V_1 * V_2 ,
bool V_170 )
{
if ( ! V_2 || ! V_2 -> V_113 )
return;
F_115 ( & V_2 -> V_112 ) ;
if ( V_170 ) {
if ( V_2 -> V_113 -> V_64 != V_171 )
return;
F_65 () ;
} else {
if ( V_2 -> V_113 -> V_64 == V_171 )
return;
if ( ! F_116 () ) {
F_56 ( & V_2 -> V_112 ) ;
return;
}
}
F_66 ( V_2 -> V_113 , V_170 ) ;
F_67 () ;
}
static int F_117 ( struct V_29 * V_30 , T_7 V_172 , T_7 V_173 ,
T_7 V_174 , T_7 V_175 , struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_55 * V_51 = V_2 -> V_51 ;
if ( V_41 -> V_155 . V_176 == V_177 ) {
T_3 * V_178 ;
T_3 V_179 ;
if ( V_175 > 16 )
return - V_28 ;
V_178 = ( T_3 * ) V_41 -> V_180 ;
V_172 >>= ( 16 - V_41 -> V_157 . V_172 . V_181 ) ;
V_173 >>= ( 16 - V_41 -> V_157 . V_173 . V_181 ) ;
V_174 >>= ( 16 - V_41 -> V_157 . V_174 . V_181 ) ;
V_179 = ( V_172 << V_41 -> V_157 . V_172 . V_182 ) |
( V_173 << V_41 -> V_157 . V_173 . V_182 ) |
( V_174 << V_41 -> V_157 . V_174 . V_182 ) ;
if ( V_41 -> V_157 . V_183 . V_181 > 0 ) {
T_3 V_184 = ( 1 << V_41 -> V_157 . V_183 . V_181 ) - 1 ;
V_184 <<= V_41 -> V_157 . V_183 . V_182 ;
V_179 |= V_184 ;
}
V_178 [ V_175 ] = V_179 ;
return 0 ;
}
if ( F_2 ( ! V_2 -> V_35 -> V_39 ||
! V_2 -> V_35 -> V_36 ) )
return - V_28 ;
F_2 ( V_51 -> V_185 -> V_186 [ 0 ] != 1 ) ;
V_2 -> V_35 -> V_39 ( V_30 , V_172 , V_173 , V_174 , V_175 ) ;
return 0 ;
}
int F_118 ( struct V_187 * V_135 , struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_19 * V_10 = V_2 -> V_10 ;
const struct V_43 * V_188 ;
T_7 * V_172 , * V_173 , * V_174 , * V_183 ;
struct V_29 * V_30 ;
int V_22 , V_27 , V_189 = 0 ;
int V_146 ;
if ( V_96 )
return - V_97 ;
F_47 ( V_10 ) ;
if ( ! F_50 ( V_2 ) ) {
F_48 ( V_10 ) ;
return - V_97 ;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_44 ; V_22 ++ ) {
V_30 = V_2 -> V_47 [ V_22 ] . V_46 . V_30 ;
V_188 = V_30 -> V_49 ;
V_172 = V_135 -> V_172 ;
V_173 = V_135 -> V_173 ;
V_174 = V_135 -> V_174 ;
V_183 = V_135 -> V_183 ;
V_146 = V_135 -> V_146 ;
for ( V_27 = 0 ; V_27 < V_135 -> V_139 ; V_27 ++ ) {
T_7 V_190 , V_191 , V_192 , V_193 = 0xffff ;
V_190 = * V_172 ++ ;
V_191 = * V_173 ++ ;
V_192 = * V_174 ++ ;
if ( V_183 )
V_193 = * V_183 ++ ;
V_189 = F_117 ( V_30 , V_190 , V_191 , V_192 , V_146 ++ , V_41 ) ;
if ( V_189 )
goto V_25;
}
if ( V_188 -> V_194 )
V_188 -> V_194 ( V_30 ) ;
}
V_25:
F_48 ( V_10 ) ;
return V_189 ;
}
int F_119 ( struct V_40 * V_41 , unsigned int V_195 ,
unsigned long V_196 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_19 * V_10 = V_2 -> V_10 ;
struct V_45 * V_46 ;
struct V_29 * V_30 ;
int V_23 = 0 ;
F_8 ( & V_10 -> V_11 . V_12 ) ;
if ( ! F_50 ( V_2 ) ) {
V_23 = - V_97 ;
goto V_197;
}
switch ( V_195 ) {
case V_198 :
V_46 = & V_2 -> V_47 [ 0 ] . V_46 ;
V_30 = V_46 -> V_30 ;
V_23 = F_120 ( V_30 ) ;
if ( ! V_23 ) {
F_121 ( V_30 ) ;
F_122 ( V_30 ) ;
}
V_23 = 0 ;
goto V_197;
default:
V_23 = - V_199 ;
}
V_197:
F_15 ( & V_10 -> V_11 . V_12 ) ;
return V_23 ;
}
int F_123 ( struct V_200 * V_157 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_55 * V_51 = V_2 -> V_51 ;
int V_201 ;
if ( V_157 -> V_202 != 0 || F_124 () )
return - V_28 ;
if ( V_157 -> V_203 != V_51 -> V_185 -> V_186 [ 0 ] * 8 ||
V_157 -> V_159 > V_51 -> V_142 || V_157 -> V_158 > V_51 -> V_143 ||
V_157 -> V_204 > V_51 -> V_142 || V_157 -> V_205 > V_51 -> V_143 ) {
F_125 ( L_3
L_4 ,
V_157 -> V_159 , V_157 -> V_158 , V_157 -> V_203 ,
V_157 -> V_204 , V_157 -> V_205 ,
V_51 -> V_142 , V_51 -> V_143 , V_51 -> V_185 -> V_186 [ 0 ] * 8 ) ;
return - V_28 ;
}
switch ( V_157 -> V_203 ) {
case 16 :
V_201 = ( V_157 -> V_173 . V_181 == 6 ) ? 16 : 15 ;
break;
case 32 :
V_201 = ( V_157 -> V_183 . V_181 > 0 ) ? 32 : 24 ;
break;
default:
V_201 = V_157 -> V_203 ;
break;
}
switch ( V_201 ) {
case 8 :
V_157 -> V_172 . V_182 = 0 ;
V_157 -> V_173 . V_182 = 0 ;
V_157 -> V_174 . V_182 = 0 ;
V_157 -> V_172 . V_181 = 8 ;
V_157 -> V_173 . V_181 = 8 ;
V_157 -> V_174 . V_181 = 8 ;
V_157 -> V_183 . V_181 = 0 ;
V_157 -> V_183 . V_182 = 0 ;
break;
case 15 :
V_157 -> V_172 . V_182 = 10 ;
V_157 -> V_173 . V_182 = 5 ;
V_157 -> V_174 . V_182 = 0 ;
V_157 -> V_172 . V_181 = 5 ;
V_157 -> V_173 . V_181 = 5 ;
V_157 -> V_174 . V_181 = 5 ;
V_157 -> V_183 . V_181 = 1 ;
V_157 -> V_183 . V_182 = 15 ;
break;
case 16 :
V_157 -> V_172 . V_182 = 11 ;
V_157 -> V_173 . V_182 = 5 ;
V_157 -> V_174 . V_182 = 0 ;
V_157 -> V_172 . V_181 = 5 ;
V_157 -> V_173 . V_181 = 6 ;
V_157 -> V_174 . V_181 = 5 ;
V_157 -> V_183 . V_181 = 0 ;
V_157 -> V_183 . V_182 = 0 ;
break;
case 24 :
V_157 -> V_172 . V_182 = 16 ;
V_157 -> V_173 . V_182 = 8 ;
V_157 -> V_174 . V_182 = 0 ;
V_157 -> V_172 . V_181 = 8 ;
V_157 -> V_173 . V_181 = 8 ;
V_157 -> V_174 . V_181 = 8 ;
V_157 -> V_183 . V_181 = 0 ;
V_157 -> V_183 . V_182 = 0 ;
break;
case 32 :
V_157 -> V_172 . V_182 = 16 ;
V_157 -> V_173 . V_182 = 8 ;
V_157 -> V_174 . V_182 = 0 ;
V_157 -> V_172 . V_181 = 8 ;
V_157 -> V_173 . V_181 = 8 ;
V_157 -> V_174 . V_181 = 8 ;
V_157 -> V_183 . V_181 = 8 ;
V_157 -> V_183 . V_182 = 24 ;
break;
default:
return - V_28 ;
}
return 0 ;
}
int F_126 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_200 * V_157 = & V_41 -> V_157 ;
if ( V_96 )
return - V_97 ;
if ( V_157 -> V_202 != 0 ) {
F_25 ( L_5 ) ;
return - V_28 ;
}
F_46 ( V_2 ) ;
return 0 ;
}
static int F_127 ( struct V_200 * V_157 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_19 * V_10 = V_2 -> V_10 ;
struct V_63 * V_64 ;
struct V_61 * V_62 ;
int V_22 , V_23 ;
unsigned int V_65 ;
V_64 = F_27 ( V_10 ) ;
if ( ! V_64 )
return - V_18 ;
V_64 -> V_66 = V_10 -> V_11 . V_66 ;
V_67:
V_65 = 0 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_44 ; V_22 ++ ) {
struct V_45 * V_46 ;
V_46 = & V_2 -> V_47 [ V_22 ] . V_46 ;
V_46 -> V_52 = V_157 -> V_206 ;
V_46 -> V_53 = V_157 -> V_207 ;
V_23 = F_34 ( V_46 , V_64 ) ;
if ( V_23 != 0 )
goto V_24;
V_62 = V_46 -> V_30 -> V_59 ;
V_65 |= ( 1 << F_32 ( V_62 ) ) ;
V_62 -> V_72 = V_62 -> V_51 ;
}
V_23 = F_35 ( V_64 ) ;
if ( V_23 != 0 )
goto V_24;
V_41 -> V_157 . V_206 = V_157 -> V_206 ;
V_41 -> V_157 . V_207 = V_157 -> V_207 ;
V_24:
F_36 ( V_10 , V_65 , V_23 ) ;
if ( V_23 == - V_74 )
goto V_75;
F_37 ( V_64 ) ;
return V_23 ;
V_75:
F_38 ( V_64 ) ;
F_39 ( V_64 ) ;
goto V_67;
}
static int F_128 ( struct V_200 * V_157 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_45 * V_107 ;
int V_23 = 0 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_44 ; V_22 ++ ) {
V_107 = & V_2 -> V_47 [ V_22 ] . V_46 ;
V_107 -> V_52 = V_157 -> V_206 ;
V_107 -> V_53 = V_157 -> V_207 ;
if ( V_107 -> V_108 ) {
V_23 = F_43 ( V_107 ) ;
if ( ! V_23 ) {
V_41 -> V_157 . V_206 = V_157 -> V_206 ;
V_41 -> V_157 . V_207 = V_157 -> V_207 ;
}
}
}
return V_23 ;
}
int F_129 ( struct V_200 * V_157 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_19 * V_10 = V_2 -> V_10 ;
int V_23 ;
if ( V_96 )
return - V_97 ;
F_47 ( V_10 ) ;
if ( ! F_50 ( V_2 ) ) {
F_48 ( V_10 ) ;
return - V_97 ;
}
if ( F_21 ( V_10 ) )
V_23 = F_127 ( V_157 , V_41 ) ;
else
V_23 = F_128 ( V_157 , V_41 ) ;
F_48 ( V_10 ) ;
return V_23 ;
}
static int F_130 ( struct V_1 * V_2 ,
int V_208 )
{
int V_23 = 0 ;
int V_44 = 0 ;
int V_22 ;
struct V_209 V_210 ;
int V_38 = 0 ;
memset ( & V_210 , 0 , sizeof( struct V_209 ) ) ;
V_210 . V_211 = 24 ;
V_210 . V_212 = 32 ;
V_210 . V_213 = ( T_3 ) - 1 ;
V_210 . V_214 = ( T_3 ) - 1 ;
if ( V_208 != V_210 . V_212 )
V_210 . V_211 = V_210 . V_212 = V_208 ;
F_11 (fb_helper, i) {
struct V_5 * V_215 = V_2 -> V_16 [ V_22 ] ;
struct V_216 * V_217 ;
V_217 = & V_215 -> V_4 -> V_217 ;
if ( V_217 -> V_218 ) {
switch ( V_217 -> V_219 ) {
case 8 :
V_210 . V_211 = V_210 . V_212 = 8 ;
break;
case 15 :
V_210 . V_211 = 15 ;
V_210 . V_212 = 16 ;
break;
case 16 :
V_210 . V_211 = V_210 . V_212 = 16 ;
break;
case 24 :
V_210 . V_211 = V_210 . V_212 = 24 ;
break;
case 32 :
V_210 . V_211 = 24 ;
V_210 . V_212 = 32 ;
break;
}
break;
}
}
V_44 = 0 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_44 ; V_22 ++ ) {
struct V_220 * V_221 ;
struct V_45 * V_46 ;
int V_52 , V_53 , V_27 ;
bool V_222 = true , V_223 = true ;
V_221 = V_2 -> V_47 [ V_22 ] . V_221 ;
V_46 = & V_2 -> V_47 [ V_22 ] . V_46 ;
if ( ! V_221 )
continue;
V_44 ++ ;
V_52 = V_2 -> V_47 [ V_22 ] . V_52 ;
V_53 = V_2 -> V_47 [ V_22 ] . V_53 ;
if ( V_38 == 0 )
V_38 = V_2 -> V_47 [ V_22 ] . V_46 . V_30 -> V_38 ;
V_210 . V_224 = F_94 ( T_3 , V_221 -> V_225 + V_52 , V_210 . V_224 ) ;
V_210 . V_226 = F_94 ( T_3 , V_221 -> V_227 + V_53 , V_210 . V_226 ) ;
for ( V_27 = 0 ; V_27 < V_46 -> V_108 ; V_27 ++ ) {
struct V_3 * V_4 = V_46 -> V_109 [ V_27 ] ;
if ( V_4 -> V_228 ) {
V_223 = ( V_4 -> V_229 == ( V_4 -> V_230 - 1 ) ) ;
V_222 = ( V_4 -> V_231 == ( V_4 -> V_232 - 1 ) ) ;
break;
}
}
if ( V_223 )
V_210 . V_213 = F_93 ( T_3 , V_221 -> V_225 + V_52 , V_210 . V_213 ) ;
if ( V_222 )
V_210 . V_214 = F_93 ( T_3 , V_221 -> V_227 + V_53 , V_210 . V_214 ) ;
}
if ( V_44 == 0 || V_210 . V_213 == - 1 || V_210 . V_214 == - 1 ) {
F_131 ( L_6 ) ;
V_210 . V_213 = V_210 . V_224 = 1024 ;
V_210 . V_214 = V_210 . V_226 = 768 ;
}
V_210 . V_226 *= V_233 ;
V_210 . V_226 /= 100 ;
V_23 = (* V_2 -> V_35 -> V_234 )( V_2 , & V_210 ) ;
if ( V_23 < 0 )
return V_23 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_44 ; V_22 ++ )
if ( V_2 -> V_47 [ V_22 ] . V_46 . V_108 )
V_2 -> V_47 [ V_22 ] . V_46 . V_51 = V_2 -> V_51 ;
return 0 ;
}
void F_132 ( struct V_40 * V_41 , T_8 V_235 ,
T_8 V_201 )
{
V_41 -> V_155 . type = V_236 ;
V_41 -> V_155 . V_176 = V_201 == 8 ? V_237 :
V_177 ;
V_41 -> V_155 . V_238 = 0 ;
V_41 -> V_155 . V_239 = 0 ;
V_41 -> V_155 . V_240 = 0 ;
V_41 -> V_155 . V_241 = 1 ;
V_41 -> V_155 . V_242 = 1 ;
V_41 -> V_155 . V_243 = 0 ;
V_41 -> V_155 . V_244 = V_245 ;
V_41 -> V_155 . V_156 = V_235 ;
}
void F_133 ( struct V_40 * V_41 , struct V_1 * V_2 ,
T_8 V_213 , T_8 V_214 )
{
struct V_55 * V_51 = V_2 -> V_51 ;
V_41 -> V_180 = V_2 -> V_180 ;
V_41 -> V_157 . V_204 = V_51 -> V_142 ;
V_41 -> V_157 . V_205 = V_51 -> V_143 ;
V_41 -> V_157 . V_203 = V_51 -> V_185 -> V_186 [ 0 ] * 8 ;
V_41 -> V_157 . V_246 = V_247 ;
V_41 -> V_157 . V_206 = 0 ;
V_41 -> V_157 . V_207 = 0 ;
V_41 -> V_157 . V_248 = V_249 ;
V_41 -> V_157 . V_143 = - 1 ;
V_41 -> V_157 . V_142 = - 1 ;
switch ( V_51 -> V_185 -> V_201 ) {
case 8 :
V_41 -> V_157 . V_172 . V_182 = 0 ;
V_41 -> V_157 . V_173 . V_182 = 0 ;
V_41 -> V_157 . V_174 . V_182 = 0 ;
V_41 -> V_157 . V_172 . V_181 = 8 ;
V_41 -> V_157 . V_173 . V_181 = 8 ;
V_41 -> V_157 . V_174 . V_181 = 8 ;
V_41 -> V_157 . V_183 . V_182 = 0 ;
V_41 -> V_157 . V_183 . V_181 = 0 ;
break;
case 15 :
V_41 -> V_157 . V_172 . V_182 = 10 ;
V_41 -> V_157 . V_173 . V_182 = 5 ;
V_41 -> V_157 . V_174 . V_182 = 0 ;
V_41 -> V_157 . V_172 . V_181 = 5 ;
V_41 -> V_157 . V_173 . V_181 = 5 ;
V_41 -> V_157 . V_174 . V_181 = 5 ;
V_41 -> V_157 . V_183 . V_182 = 15 ;
V_41 -> V_157 . V_183 . V_181 = 1 ;
break;
case 16 :
V_41 -> V_157 . V_172 . V_182 = 11 ;
V_41 -> V_157 . V_173 . V_182 = 5 ;
V_41 -> V_157 . V_174 . V_182 = 0 ;
V_41 -> V_157 . V_172 . V_181 = 5 ;
V_41 -> V_157 . V_173 . V_181 = 6 ;
V_41 -> V_157 . V_174 . V_181 = 5 ;
V_41 -> V_157 . V_183 . V_182 = 0 ;
break;
case 24 :
V_41 -> V_157 . V_172 . V_182 = 16 ;
V_41 -> V_157 . V_173 . V_182 = 8 ;
V_41 -> V_157 . V_174 . V_182 = 0 ;
V_41 -> V_157 . V_172 . V_181 = 8 ;
V_41 -> V_157 . V_173 . V_181 = 8 ;
V_41 -> V_157 . V_174 . V_181 = 8 ;
V_41 -> V_157 . V_183 . V_182 = 0 ;
V_41 -> V_157 . V_183 . V_181 = 0 ;
break;
case 32 :
V_41 -> V_157 . V_172 . V_182 = 16 ;
V_41 -> V_157 . V_173 . V_182 = 8 ;
V_41 -> V_157 . V_174 . V_182 = 0 ;
V_41 -> V_157 . V_172 . V_181 = 8 ;
V_41 -> V_157 . V_173 . V_181 = 8 ;
V_41 -> V_157 . V_174 . V_181 = 8 ;
V_41 -> V_157 . V_183 . V_182 = 24 ;
V_41 -> V_157 . V_183 . V_181 = 8 ;
break;
default:
break;
}
V_41 -> V_157 . V_159 = V_213 ;
V_41 -> V_157 . V_158 = V_214 ;
}
static int F_134 ( struct V_1 * V_2 ,
T_8 V_250 ,
T_8 V_251 )
{
struct V_3 * V_4 ;
int V_8 = 0 ;
int V_22 ;
F_11 (fb_helper, i) {
V_4 = V_2 -> V_16 [ V_22 ] -> V_4 ;
V_8 += V_4 -> V_35 -> V_252 ( V_4 , V_250 , V_251 ) ;
}
return V_8 ;
}
struct V_220 * F_135 ( struct V_5 * V_253 , int V_142 , int V_143 )
{
struct V_220 * V_110 ;
F_20 (mode, &fb_connector->connector->modes, head) {
if ( V_110 -> V_225 > V_142 ||
V_110 -> V_227 > V_143 )
continue;
if ( V_110 -> type & V_254 )
return V_110 ;
}
return NULL ;
}
static bool F_136 ( struct V_5 * V_253 )
{
return V_253 -> V_4 -> V_217 . V_255 ;
}
struct V_220 * F_137 ( struct V_5 * V_215 )
{
struct V_216 * V_217 ;
struct V_220 * V_110 ;
bool V_256 ;
V_217 = & V_215 -> V_4 -> V_217 ;
if ( V_217 -> V_255 == false )
return NULL ;
if ( V_217 -> V_257 || V_217 -> V_258 )
goto V_259;
V_256 = ! V_217 -> V_260 ;
V_261:
F_20 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_110 -> V_225 != V_217 -> V_159 ||
V_110 -> V_227 != V_217 -> V_158 )
continue;
if ( V_217 -> V_262 ) {
if ( V_110 -> V_263 != V_217 -> V_264 )
continue;
}
if ( V_217 -> V_260 ) {
if ( ! ( V_110 -> V_119 & V_265 ) )
continue;
} else if ( V_256 ) {
if ( V_110 -> V_119 & V_265 )
continue;
}
return V_110 ;
}
if ( V_256 ) {
V_256 = false ;
goto V_261;
}
V_259:
V_110 = F_138 ( V_215 -> V_4 -> V_10 ,
V_217 ) ;
F_139 ( & V_110 -> V_266 , & V_215 -> V_4 -> V_267 ) ;
return V_110 ;
}
static bool F_140 ( struct V_3 * V_4 , bool V_268 )
{
bool V_269 ;
if ( V_268 )
V_269 = V_4 -> V_270 == V_271 ;
else
V_269 = V_4 -> V_270 != V_272 ;
return V_269 ;
}
static void F_141 ( struct V_1 * V_2 ,
bool * V_48 )
{
bool V_273 = false ;
struct V_3 * V_4 ;
int V_22 = 0 ;
F_11 (fb_helper, i) {
V_4 = V_2 -> V_16 [ V_22 ] -> V_4 ;
V_48 [ V_22 ] = F_140 ( V_4 , true ) ;
F_142 ( L_7 , V_4 -> V_57 . V_58 ,
V_48 [ V_22 ] ? L_8 : L_9 ) ;
V_273 |= V_48 [ V_22 ] ;
}
if ( V_273 )
return;
F_11 (fb_helper, i) {
V_4 = V_2 -> V_16 [ V_22 ] -> V_4 ;
V_48 [ V_22 ] = F_140 ( V_4 , false ) ;
}
}
static bool F_143 ( struct V_1 * V_2 ,
struct V_220 * * V_267 ,
struct V_274 * V_275 ,
bool * V_48 , int V_142 , int V_143 )
{
int V_8 , V_22 , V_27 ;
bool V_276 = false ;
struct V_5 * V_215 ;
struct V_220 * V_277 , * V_110 ;
if ( V_2 -> V_44 > 1 )
return false ;
V_8 = 0 ;
F_11 (fb_helper, i) {
if ( V_48 [ V_22 ] )
V_8 ++ ;
}
if ( V_8 <= 1 )
return false ;
V_276 = true ;
F_11 (fb_helper, i) {
if ( ! V_48 [ V_22 ] )
continue;
V_215 = V_2 -> V_16 [ V_22 ] ;
V_267 [ V_22 ] = F_137 ( V_215 ) ;
if ( ! V_267 [ V_22 ] ) {
V_276 = false ;
break;
}
for ( V_27 = 0 ; V_27 < V_22 ; V_27 ++ ) {
if ( ! V_48 [ V_27 ] )
continue;
if ( ! F_144 ( V_267 [ V_27 ] , V_267 [ V_22 ] ) )
V_276 = false ;
}
}
if ( V_276 ) {
F_142 ( L_10 ) ;
return true ;
}
V_276 = true ;
V_277 = F_145 ( V_2 -> V_10 , 1024 , 768 , 60 , false ) ;
F_11 (fb_helper, i) {
if ( ! V_48 [ V_22 ] )
continue;
V_215 = V_2 -> V_16 [ V_22 ] ;
F_20 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_144 ( V_110 , V_277 ) )
V_267 [ V_22 ] = V_110 ;
}
if ( ! V_267 [ V_22 ] )
V_276 = false ;
}
if ( V_276 ) {
F_142 ( L_11 ) ;
return true ;
}
F_131 ( L_12 ) ;
return false ;
}
static int F_146 ( struct V_1 * V_2 ,
struct V_220 * * V_267 ,
struct V_274 * V_275 ,
int V_278 ,
int V_279 , int V_280 )
{
struct V_5 * V_215 ;
int V_22 ;
int V_281 = 0 , V_282 = 0 ;
F_11 (fb_helper, i) {
V_215 = V_2 -> V_16 [ V_22 ] ;
if ( ! V_215 -> V_4 -> V_228 )
continue;
if ( ! V_267 [ V_22 ] && ( V_279 || V_280 ) ) {
F_142 ( L_13 , V_22 ,
V_215 -> V_4 -> V_57 . V_58 ) ;
continue;
}
if ( V_215 -> V_4 -> V_229 < V_279 )
V_281 += V_267 [ V_22 ] -> V_225 ;
if ( V_215 -> V_4 -> V_231 < V_280 )
V_282 += V_267 [ V_22 ] -> V_227 ;
}
V_275 [ V_278 ] . V_52 = V_281 ;
V_275 [ V_278 ] . V_53 = V_282 ;
F_142 ( L_14 , V_281 , V_282 , V_279 , V_280 ) ;
return 0 ;
}
static bool F_147 ( struct V_1 * V_2 ,
struct V_220 * * V_267 ,
struct V_274 * V_275 ,
bool * V_48 , int V_142 , int V_143 )
{
struct V_5 * V_215 ;
const T_9 V_184 = F_148 ( V_2 -> V_13 ) - 1 ;
T_9 V_283 = 0 ;
int V_284 = 0 ;
int V_22 ;
V_67:
F_11 (fb_helper, i) {
V_215 = V_2 -> V_16 [ V_22 ] ;
if ( V_283 & F_148 ( V_22 ) )
continue;
if ( V_48 [ V_22 ] == false ) {
V_283 |= F_148 ( V_22 ) ;
continue;
}
if ( V_284 == 0 && V_215 -> V_4 -> V_228 )
continue;
if ( V_284 == 1 ) {
if ( V_215 -> V_4 -> V_229 != 0 ||
V_215 -> V_4 -> V_231 != 0 )
continue;
} else {
if ( V_215 -> V_4 -> V_229 != V_284 - 1 &&
V_215 -> V_4 -> V_231 != V_284 - 1 )
continue;
F_146 ( V_2 , V_267 , V_275 ,
V_22 , V_215 -> V_4 -> V_229 , V_215 -> V_4 -> V_231 ) ;
}
F_142 ( L_15 ,
V_215 -> V_4 -> V_57 . V_58 ) ;
V_267 [ V_22 ] = F_137 ( V_215 ) ;
if ( ! V_267 [ V_22 ] ) {
F_142 ( L_16 ,
V_215 -> V_4 -> V_57 . V_58 , V_215 -> V_4 -> V_285 ? V_215 -> V_4 -> V_285 -> V_58 : 0 ) ;
V_267 [ V_22 ] = F_135 ( V_215 , V_142 , V_143 ) ;
}
if ( ! V_267 [ V_22 ] && ! F_53 ( & V_215 -> V_4 -> V_267 ) ) {
F_20 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_142 ( L_17 , V_267 [ V_22 ] ? V_267 [ V_22 ] -> V_286 :
L_18 ) ;
V_283 |= F_148 ( V_22 ) ;
}
if ( ( V_283 & V_184 ) != V_184 ) {
V_284 ++ ;
goto V_67;
}
return true ;
}
static int F_149 ( struct V_1 * V_2 ,
struct V_131 * * V_287 ,
struct V_220 * * V_267 ,
int V_288 , int V_142 , int V_143 )
{
int V_56 , V_289 ;
struct V_3 * V_4 ;
const struct V_290 * V_291 ;
struct V_292 * V_293 ;
int V_294 , V_295 , V_296 ;
struct V_131 * * V_297 , * V_30 ;
struct V_5 * V_215 ;
if ( V_288 == V_2 -> V_13 )
return 0 ;
V_215 = V_2 -> V_16 [ V_288 ] ;
V_4 = V_215 -> V_4 ;
V_287 [ V_288 ] = NULL ;
V_295 = F_149 ( V_2 , V_287 , V_267 , V_288 + 1 , V_142 , V_143 ) ;
if ( V_267 [ V_288 ] == NULL )
return V_295 ;
V_297 = F_5 ( V_2 -> V_13 *
sizeof( struct V_131 * ) , V_17 ) ;
if ( ! V_297 )
return V_295 ;
V_294 = 1 ;
if ( V_4 -> V_270 == V_271 )
V_294 ++ ;
if ( F_136 ( V_215 ) )
V_294 ++ ;
if ( F_135 ( V_215 , V_142 , V_143 ) )
V_294 ++ ;
V_291 = V_4 -> V_49 ;
if ( F_21 ( V_2 -> V_10 ) &&
! V_291 -> V_298 )
V_293 = F_150 ( V_4 ) ;
else
V_293 = V_291 -> V_298 ( V_4 ) ;
if ( ! V_293 )
goto V_25;
for ( V_56 = 0 ; V_56 < V_2 -> V_44 ; V_56 ++ ) {
V_30 = & V_2 -> V_47 [ V_56 ] ;
if ( ( V_293 -> V_299 & ( 1 << V_56 ) ) == 0 )
continue;
for ( V_289 = 0 ; V_289 < V_288 ; V_289 ++ )
if ( V_287 [ V_289 ] == V_30 )
break;
if ( V_289 < V_288 ) {
if ( V_2 -> V_44 > 1 )
continue;
if ( ! F_144 ( V_267 [ V_289 ] , V_267 [ V_288 ] ) )
continue;
}
V_297 [ V_288 ] = V_30 ;
memcpy ( V_297 , V_287 , V_288 * sizeof( struct V_131 * ) ) ;
V_296 = V_294 + F_149 ( V_2 , V_297 , V_267 , V_288 + 1 ,
V_142 , V_143 ) ;
if ( V_296 > V_295 ) {
V_295 = V_296 ;
memcpy ( V_287 , V_297 ,
V_2 -> V_13 *
sizeof( struct V_131 * ) ) ;
}
}
V_25:
F_13 ( V_297 ) ;
return V_295 ;
}
static void F_151 ( struct V_1 * V_2 ,
T_3 V_142 , T_3 V_143 )
{
struct V_19 * V_10 = V_2 -> V_10 ;
struct V_131 * * V_297 ;
struct V_220 * * V_267 ;
struct V_274 * V_275 ;
bool * V_48 ;
int V_22 ;
F_142 ( L_19 ) ;
if ( F_134 ( V_2 , V_142 , V_143 ) == 0 )
F_142 ( L_20 ) ;
F_152 ( & V_2 -> V_10 -> V_11 . V_12 ) ;
V_297 = F_76 ( V_2 -> V_13 ,
sizeof( struct V_131 * ) , V_17 ) ;
V_267 = F_76 ( V_2 -> V_13 ,
sizeof( struct V_220 * ) , V_17 ) ;
V_275 = F_76 ( V_2 -> V_13 ,
sizeof( struct V_274 ) , V_17 ) ;
V_48 = F_76 ( V_2 -> V_13 ,
sizeof( bool ) , V_17 ) ;
if ( ! V_297 || ! V_267 || ! V_48 || ! V_275 ) {
F_25 ( L_21 ) ;
goto V_25;
}
F_141 ( V_2 , V_48 ) ;
if ( ! ( V_2 -> V_35 -> V_300 &&
V_2 -> V_35 -> V_300 ( V_2 , V_297 , V_267 ,
V_275 ,
V_48 , V_142 , V_143 ) ) ) {
memset ( V_267 , 0 , V_2 -> V_13 * sizeof( V_267 [ 0 ] ) ) ;
memset ( V_297 , 0 , V_2 -> V_13 * sizeof( V_297 [ 0 ] ) ) ;
memset ( V_275 , 0 , V_2 -> V_13 * sizeof( V_275 [ 0 ] ) ) ;
if ( ! F_143 ( V_2 , V_267 , V_275 ,
V_48 , V_142 , V_143 ) &&
! F_147 ( V_2 , V_267 , V_275 ,
V_48 , V_142 , V_143 ) )
F_25 ( L_22 ) ;
F_142 ( L_23 ,
V_142 , V_143 ) ;
F_149 ( V_2 , V_297 , V_267 , 0 , V_142 , V_143 ) ;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_44 ; V_22 ++ )
F_60 ( V_2 ,
& V_2 -> V_47 [ V_22 ] . V_46 ) ;
F_11 (fb_helper, i) {
struct V_220 * V_110 = V_267 [ V_22 ] ;
struct V_131 * V_301 = V_297 [ V_22 ] ;
struct V_274 * V_182 = & V_275 [ V_22 ] ;
struct V_45 * V_107 = & V_301 -> V_46 ;
if ( V_110 && V_301 ) {
struct V_3 * V_4 =
V_2 -> V_16 [ V_22 ] -> V_4 ;
F_142 ( L_24 ,
V_110 -> V_286 , V_301 -> V_46 . V_30 -> V_57 . V_58 , V_182 -> V_52 , V_182 -> V_53 ) ;
V_301 -> V_221 = V_110 ;
V_301 -> V_52 = V_182 -> V_52 ;
V_301 -> V_53 = V_182 -> V_53 ;
V_107 -> V_110 = F_153 ( V_10 ,
V_301 -> V_221 ) ;
F_6 ( V_4 ) ;
V_107 -> V_109 [ V_107 -> V_108 ++ ] = V_4 ;
V_107 -> V_51 = V_2 -> V_51 ;
V_107 -> V_52 = V_182 -> V_52 ;
V_107 -> V_53 = V_182 -> V_53 ;
}
}
V_25:
F_13 ( V_297 ) ;
F_13 ( V_267 ) ;
F_13 ( V_275 ) ;
F_13 ( V_48 ) ;
}
int F_154 ( struct V_1 * V_2 , int V_302 )
{
struct V_19 * V_10 = V_2 -> V_10 ;
struct V_40 * V_41 ;
int V_23 ;
if ( ! V_9 )
return 0 ;
F_8 ( & V_10 -> V_11 . V_12 ) ;
F_151 ( V_2 ,
V_10 -> V_11 . V_303 ,
V_10 -> V_11 . V_304 ) ;
V_23 = F_130 ( V_2 , V_302 ) ;
F_15 ( & V_10 -> V_11 . V_12 ) ;
if ( V_23 )
return V_23 ;
V_41 = V_2 -> V_113 ;
V_41 -> V_157 . V_202 = 0 ;
V_23 = F_155 ( V_41 ) ;
if ( V_23 < 0 )
return V_23 ;
F_156 ( V_10 -> V_10 , L_25 ,
V_41 -> V_305 , V_41 -> V_155 . V_58 ) ;
F_8 ( & V_140 ) ;
if ( F_53 ( & V_85 ) )
F_157 ( 'v' , & V_141 ) ;
F_139 ( & V_2 -> V_126 , & V_85 ) ;
F_15 ( & V_140 ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_2 )
{
struct V_19 * V_10 = V_2 -> V_10 ;
if ( ! V_9 )
return 0 ;
F_8 ( & V_10 -> V_11 . V_12 ) ;
if ( ! V_2 -> V_51 || ! F_50 ( V_2 ) ) {
V_2 -> V_81 = true ;
F_15 ( & V_10 -> V_11 . V_12 ) ;
return 0 ;
}
F_142 ( L_19 ) ;
F_151 ( V_2 , V_2 -> V_51 -> V_142 , V_2 -> V_51 -> V_143 ) ;
F_15 ( & V_10 -> V_11 . V_12 ) ;
F_126 ( V_2 -> V_113 ) ;
return 0 ;
}
int T_10 F_158 ( void )
{
#if F_159 ( V_306 ) && ! F_159 ( V_307 )
const char V_286 [] = L_26 ;
struct V_308 * V_309 ;
F_8 ( & V_310 ) ;
V_309 = F_160 ( V_286 ) ;
F_15 ( & V_310 ) ;
if ( ! V_309 )
F_161 ( V_286 ) ;
#endif
return 0 ;
}
