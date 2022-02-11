int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_7 V_8 ;
int V_9 , V_10 = 0 ;
if ( ! V_11 )
return 0 ;
F_2 ( & V_4 -> V_12 . V_13 ) ;
F_3 ( V_4 , & V_8 ) ;
F_4 (connector, &conn_iter) {
V_10 = F_5 ( V_2 , V_6 ) ;
if ( V_10 )
goto V_14;
}
goto V_15;
V_14:
F_6 (fb_helper, i) {
struct V_16 * V_17 =
V_2 -> V_18 [ V_9 ] ;
F_7 ( V_17 -> V_6 ) ;
F_8 ( V_17 ) ;
V_2 -> V_18 [ V_9 ] = NULL ;
}
V_2 -> V_19 = 0 ;
V_15:
F_9 ( & V_8 ) ;
F_10 ( & V_4 -> V_12 . V_13 ) ;
return V_10 ;
}
int F_5 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_16 * * V_20 ;
struct V_16 * V_17 ;
if ( ! V_11 )
return 0 ;
F_11 ( ! F_12 ( & V_2 -> V_4 -> V_12 . V_13 ) ) ;
if ( V_2 -> V_19 + 1 > V_2 -> V_21 ) {
V_20 = F_13 ( V_2 -> V_18 , sizeof( struct V_16 * ) * ( V_2 -> V_19 + 1 ) , V_22 ) ;
if ( ! V_20 )
return - V_23 ;
V_2 -> V_21 = V_2 -> V_19 + 1 ;
V_2 -> V_18 = V_20 ;
}
V_17 = F_14 ( sizeof( struct V_16 ) , V_22 ) ;
if ( ! V_17 )
return - V_23 ;
F_15 ( V_6 ) ;
V_17 -> V_6 = V_6 ;
V_2 -> V_18 [ V_2 -> V_19 ++ ] = V_17 ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_16 * V_17 ;
int V_9 , V_24 ;
if ( ! V_11 )
return 0 ;
F_11 ( ! F_12 ( & V_2 -> V_4 -> V_12 . V_13 ) ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_19 ; V_9 ++ ) {
if ( V_2 -> V_18 [ V_9 ] -> V_6 == V_6 )
break;
}
if ( V_9 == V_2 -> V_19 )
return - V_25 ;
V_17 = V_2 -> V_18 [ V_9 ] ;
F_7 ( V_17 -> V_6 ) ;
for ( V_24 = V_9 + 1 ; V_24 < V_2 -> V_19 ; V_24 ++ ) {
V_2 -> V_18 [ V_24 - 1 ] = V_2 -> V_18 [ V_24 ] ;
}
V_2 -> V_19 -- ;
F_8 ( V_17 ) ;
return 0 ;
}
static void F_17 ( struct V_26 * V_27 , struct V_1 * V_28 )
{
T_1 * V_29 , * V_30 , * V_31 ;
int V_9 ;
if ( V_28 -> V_32 -> V_33 == NULL )
return;
V_29 = V_27 -> V_34 ;
V_30 = V_29 + V_27 -> V_35 ;
V_31 = V_30 + V_27 -> V_35 ;
for ( V_9 = 0 ; V_9 < V_27 -> V_35 ; V_9 ++ )
V_28 -> V_32 -> V_33 ( V_27 , & V_29 [ V_9 ] , & V_30 [ V_9 ] , & V_31 [ V_9 ] , V_9 ) ;
}
static void F_18 ( struct V_26 * V_27 )
{
T_1 * V_29 , * V_30 , * V_31 ;
if ( V_27 -> V_32 -> V_36 == NULL )
return;
V_29 = V_27 -> V_34 ;
V_30 = V_29 + V_27 -> V_35 ;
V_31 = V_30 + V_27 -> V_35 ;
V_27 -> V_32 -> V_36 ( V_27 , V_29 , V_30 , V_31 , V_27 -> V_35 ) ;
}
int F_19 ( struct V_37 * V_38 )
{
struct V_1 * V_28 = V_38 -> V_39 ;
const struct V_40 * V_32 ;
int V_9 ;
F_20 (helper, &kernel_fb_helper_list, kernel_fb_list) {
for ( V_9 = 0 ; V_9 < V_28 -> V_41 ; V_9 ++ ) {
struct V_42 * V_43 =
& V_28 -> V_44 [ V_9 ] . V_43 ;
if ( ! V_43 -> V_27 -> V_45 )
continue;
V_32 = V_43 -> V_27 -> V_46 ;
if ( V_32 -> V_47 == NULL )
continue;
F_17 ( V_43 -> V_27 , V_28 ) ;
V_32 -> V_47 ( V_43 -> V_27 ,
V_43 -> V_48 ,
V_43 -> V_49 ,
V_43 -> V_50 ,
V_51 ) ;
}
}
return 0 ;
}
static struct V_52 * F_21 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = V_27 -> V_4 ;
struct V_26 * V_53 ;
F_22 (c, dev) {
if ( V_27 -> V_54 . V_55 == V_53 -> V_54 . V_55 )
return V_53 -> V_56 -> V_48 ;
}
return NULL ;
}
int F_23 ( struct V_37 * V_38 )
{
struct V_1 * V_28 = V_38 -> V_39 ;
struct V_26 * V_27 ;
const struct V_40 * V_32 ;
struct V_52 * V_48 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_28 -> V_41 ; V_9 ++ ) {
struct V_42 * V_43 = & V_28 -> V_44 [ V_9 ] . V_43 ;
V_27 = V_43 -> V_27 ;
V_32 = V_27 -> V_46 ;
V_48 = F_21 ( V_27 ) ;
if ( ! V_27 -> V_45 )
continue;
if ( ! V_48 ) {
F_24 ( L_1 ) ;
continue;
}
if ( V_32 -> V_47 == NULL )
continue;
F_18 ( V_43 -> V_27 ) ;
V_32 -> V_47 ( V_43 -> V_27 , V_48 , V_27 -> V_49 ,
V_27 -> V_50 , V_57 ) ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
int V_9 , V_10 ;
unsigned V_62 ;
V_61 = F_26 ( V_4 ) ;
if ( ! V_61 )
return - V_23 ;
V_61 -> V_63 = V_4 -> V_12 . V_63 ;
V_64:
V_62 = 0 ;
F_27 (plane, dev) {
struct V_65 * V_66 ;
V_66 = F_28 ( V_61 , V_59 ) ;
if ( F_29 ( V_66 ) ) {
V_10 = F_30 ( V_66 ) ;
goto V_14;
}
V_66 -> V_67 = V_68 ;
V_59 -> V_69 = V_59 -> V_48 ;
V_62 |= 1 << F_31 ( V_59 ) ;
if ( V_59 -> type == V_70 )
continue;
V_10 = F_32 ( V_59 , V_66 ) ;
if ( V_10 != 0 )
goto V_14;
}
for( V_9 = 0 ; V_9 < V_2 -> V_41 ; V_9 ++ ) {
struct V_42 * V_43 = & V_2 -> V_44 [ V_9 ] . V_43 ;
V_10 = F_33 ( V_43 , V_61 ) ;
if ( V_10 != 0 )
goto V_14;
}
V_10 = F_34 ( V_61 ) ;
V_14:
F_35 ( V_4 , V_62 , V_10 ) ;
if ( V_10 == - V_71 )
goto V_72;
F_36 ( V_61 ) ;
return V_10 ;
V_72:
F_37 ( V_61 ) ;
F_38 ( V_61 ) ;
goto V_64;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_58 * V_59 ;
int V_9 ;
F_40 ( V_4 ) ;
if ( F_41 ( V_4 ) )
return F_25 ( V_2 ) ;
F_27 (plane, dev) {
if ( V_59 -> type != V_70 )
F_42 ( V_59 ) ;
if ( V_59 -> V_73 )
F_43 ( V_59 ,
V_59 -> V_73 ,
V_68 ) ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_41 ; V_9 ++ ) {
struct V_42 * V_43 = & V_2 -> V_44 [ V_9 ] . V_43 ;
struct V_26 * V_27 = V_43 -> V_27 ;
int V_10 ;
if ( V_27 -> V_32 -> V_74 ) {
V_10 = V_27 -> V_32 -> V_74 ( V_27 , NULL , 0 , 0 , 0 , 0 , 0 ) ;
if ( V_10 )
return V_10 ;
} else if ( V_27 -> V_32 -> V_75 ) {
V_10 = V_27 -> V_32 -> V_75 ( V_27 , NULL , 0 , 0 , 0 ) ;
if ( V_10 )
return V_10 ;
}
V_10 = F_44 ( V_43 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
int F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_76 ;
int V_10 ;
if ( ! V_11 )
return - V_77 ;
F_46 ( V_4 ) ;
V_10 = F_39 ( V_2 ) ;
V_76 = V_2 -> V_78 ;
if ( V_76 )
V_2 -> V_78 = false ;
F_47 ( V_4 ) ;
if ( V_76 )
F_48 ( V_2 ) ;
return V_10 ;
}
static bool F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_26 * V_27 ;
int V_79 = 0 , V_80 = 0 ;
if ( F_50 ( V_4 -> V_81 ) )
return false ;
F_22 (crtc, dev) {
if ( V_27 -> V_56 -> V_48 )
V_80 ++ ;
if ( V_27 -> V_56 -> V_48 == V_2 -> V_48 )
V_79 ++ ;
}
if ( V_79 < V_80 )
return false ;
return true ;
}
static bool F_51 ( void )
{
bool V_10 , error = false ;
struct V_1 * V_28 ;
if ( F_52 ( & V_82 ) )
return false ;
F_20 (helper, &kernel_fb_helper_list, kernel_fb_list) {
struct V_3 * V_4 = V_28 -> V_4 ;
if ( V_4 -> V_83 == V_84 )
continue;
F_46 ( V_4 ) ;
V_10 = F_39 ( V_28 ) ;
if ( V_10 )
error = true ;
F_47 ( V_4 ) ;
}
return error ;
}
static void F_53 ( struct V_85 * V_86 )
{
bool V_10 ;
V_10 = F_51 () ;
if ( V_10 == true )
F_24 ( L_2 ) ;
}
static void F_54 ( int V_87 )
{
F_55 ( & V_88 ) ;
}
static void F_56 ( struct V_37 * V_38 , int V_89 )
{
struct V_1 * V_2 = V_38 -> V_39 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_26 * V_27 ;
struct V_5 * V_6 ;
int V_9 , V_24 ;
F_46 ( V_4 ) ;
if ( ! F_49 ( V_2 ) ) {
F_47 ( V_4 ) ;
return;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_41 ; V_9 ++ ) {
V_27 = V_2 -> V_44 [ V_9 ] . V_43 . V_27 ;
if ( ! V_27 -> V_45 )
continue;
F_6 (fb_helper, j) {
V_6 = V_2 -> V_18 [ V_24 ] -> V_6 ;
V_6 -> V_32 -> V_90 ( V_6 , V_89 ) ;
F_57 ( & V_6 -> V_54 ,
V_4 -> V_12 . V_91 , V_89 ) ;
}
}
F_47 ( V_4 ) ;
}
int F_58 ( int V_92 , struct V_37 * V_38 )
{
if ( V_93 )
return - V_94 ;
switch ( V_92 ) {
case V_95 :
F_56 ( V_38 , V_96 ) ;
break;
case V_97 :
F_56 ( V_38 , V_98 ) ;
break;
case V_99 :
F_56 ( V_38 , V_98 ) ;
break;
case V_100 :
F_56 ( V_38 , V_101 ) ;
break;
case V_102 :
F_56 ( V_38 , V_103 ) ;
break;
}
return 0 ;
}
static void F_59 ( struct V_1 * V_28 ,
struct V_42 * V_104 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_104 -> V_105 ; V_9 ++ ) {
F_7 ( V_104 -> V_106 [ V_9 ] ) ;
V_104 -> V_106 [ V_9 ] = NULL ;
}
V_104 -> V_105 = 0 ;
F_60 ( V_28 -> V_4 , V_104 -> V_107 ) ;
V_104 -> V_107 = NULL ;
V_104 -> V_48 = NULL ;
}
static void F_61 ( struct V_1 * V_28 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_28 -> V_19 ; V_9 ++ ) {
F_7 ( V_28 -> V_18 [ V_9 ] -> V_6 ) ;
F_8 ( V_28 -> V_18 [ V_9 ] ) ;
}
F_8 ( V_28 -> V_18 ) ;
for ( V_9 = 0 ; V_9 < V_28 -> V_41 ; V_9 ++ ) {
struct V_42 * V_104 = & V_28 -> V_44 [ V_9 ] . V_43 ;
F_59 ( V_28 , V_104 ) ;
F_8 ( V_104 -> V_106 ) ;
}
F_8 ( V_28 -> V_44 ) ;
}
static void F_62 ( struct V_85 * V_108 )
{
struct V_1 * V_28 = F_63 ( V_108 , struct V_1 ,
V_109 ) ;
F_64 () ;
F_65 ( V_28 -> V_110 , 0 ) ;
F_66 () ;
}
static void F_67 ( struct V_85 * V_108 )
{
struct V_1 * V_28 = F_63 ( V_108 , struct V_1 ,
V_111 ) ;
struct V_112 * V_113 = & V_28 -> V_114 ;
struct V_112 V_115 ;
unsigned long V_116 ;
F_68 ( & V_28 -> V_117 , V_116 ) ;
V_115 = * V_113 ;
V_113 -> V_118 = V_113 -> y1 = ~ 0 ;
V_113 -> V_119 = V_113 -> V_120 = 0 ;
F_69 ( & V_28 -> V_117 , V_116 ) ;
if ( V_115 . V_118 < V_115 . V_119 && V_115 . y1 < V_115 . V_120 )
V_28 -> V_48 -> V_32 -> V_121 ( V_28 -> V_48 , NULL , 0 , 0 , & V_115 , 1 ) ;
}
void F_70 ( struct V_3 * V_4 , struct V_1 * V_28 ,
const struct V_122 * V_32 )
{
F_71 ( & V_28 -> V_123 ) ;
F_72 ( & V_28 -> V_117 ) ;
F_73 ( & V_28 -> V_109 , F_62 ) ;
F_73 ( & V_28 -> V_111 , F_67 ) ;
V_28 -> V_114 . V_118 = V_28 -> V_114 . y1 = ~ 0 ;
V_28 -> V_32 = V_32 ;
V_28 -> V_4 = V_4 ;
}
int F_74 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_124 )
{
struct V_26 * V_27 ;
struct V_125 * V_126 = & V_4 -> V_12 ;
int V_9 ;
if ( ! V_11 )
return 0 ;
if ( ! V_124 )
return - V_25 ;
V_2 -> V_44 = F_75 ( V_126 -> V_127 , sizeof( struct V_128 ) , V_22 ) ;
if ( ! V_2 -> V_44 )
return - V_23 ;
V_2 -> V_41 = V_126 -> V_127 ;
V_2 -> V_18 = F_75 ( V_4 -> V_12 . V_129 , sizeof( struct V_16 * ) , V_22 ) ;
if ( ! V_2 -> V_18 ) {
F_8 ( V_2 -> V_44 ) ;
return - V_23 ;
}
V_2 -> V_21 = V_4 -> V_12 . V_129 ;
V_2 -> V_19 = 0 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_41 ; V_9 ++ ) {
V_2 -> V_44 [ V_9 ] . V_43 . V_106 =
F_75 ( V_124 ,
sizeof( struct V_5 * ) ,
V_22 ) ;
if ( ! V_2 -> V_44 [ V_9 ] . V_43 . V_106 )
goto V_130;
V_2 -> V_44 [ V_9 ] . V_43 . V_105 = 0 ;
}
V_9 = 0 ;
F_22 (crtc, dev) {
V_2 -> V_44 [ V_9 ] . V_43 . V_27 = V_27 ;
V_9 ++ ;
}
return 0 ;
V_130:
F_61 ( V_2 ) ;
return - V_23 ;
}
struct V_37 * F_76 ( struct V_1 * V_2 )
{
struct V_131 * V_4 = V_2 -> V_4 -> V_4 ;
struct V_37 * V_38 ;
int V_10 ;
V_38 = F_77 ( 0 , V_4 ) ;
if ( ! V_38 )
return F_78 ( - V_23 ) ;
V_10 = F_79 ( & V_38 -> V_132 , 256 , 0 ) ;
if ( V_10 )
goto V_133;
V_38 -> V_134 = F_80 ( 1 ) ;
if ( ! V_38 -> V_134 ) {
V_10 = - V_23 ;
goto V_135;
}
V_2 -> V_110 = V_38 ;
return V_38 ;
V_135:
F_81 ( & V_38 -> V_132 ) ;
V_133:
F_82 ( V_38 ) ;
return F_78 ( V_10 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_110 )
F_84 ( V_2 -> V_110 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
if ( V_2 ) {
struct V_37 * V_38 = V_2 -> V_110 ;
if ( V_38 ) {
if ( V_38 -> V_132 . V_136 )
F_81 ( & V_38 -> V_132 ) ;
F_82 ( V_38 ) ;
}
V_2 -> V_110 = NULL ;
}
}
void F_86 ( struct V_1 * V_2 )
{
if ( ! V_11 )
return;
F_87 ( & V_2 -> V_109 ) ;
F_87 ( & V_2 -> V_111 ) ;
F_2 ( & V_137 ) ;
if ( ! F_52 ( & V_2 -> V_123 ) ) {
F_88 ( & V_2 -> V_123 ) ;
if ( F_52 ( & V_82 ) ) {
F_89 ( 'v' , & V_138 ) ;
}
}
F_10 ( & V_137 ) ;
F_61 ( V_2 ) ;
}
void F_90 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_110 )
F_91 ( V_2 -> V_110 ) ;
}
static void F_92 ( struct V_37 * V_38 , T_2 V_49 , T_2 V_50 ,
T_2 V_139 , T_2 V_140 )
{
struct V_1 * V_28 = V_38 -> V_39 ;
struct V_112 * V_113 = & V_28 -> V_114 ;
unsigned long V_116 ;
if ( ! V_28 -> V_48 -> V_32 -> V_121 )
return;
F_68 ( & V_28 -> V_117 , V_116 ) ;
V_113 -> V_118 = F_93 ( T_2 , V_113 -> V_118 , V_49 ) ;
V_113 -> y1 = F_93 ( T_2 , V_113 -> y1 , V_50 ) ;
V_113 -> V_119 = F_94 ( T_2 , V_113 -> V_119 , V_49 + V_139 ) ;
V_113 -> V_120 = F_94 ( T_2 , V_113 -> V_120 , V_50 + V_140 ) ;
F_69 ( & V_28 -> V_117 , V_116 ) ;
F_55 ( & V_28 -> V_111 ) ;
}
void F_95 ( struct V_37 * V_38 ,
struct V_141 * V_142 )
{
unsigned long V_143 , V_144 , V_145 , V_146 ;
struct V_147 * V_147 ;
T_2 y1 , V_120 ;
V_145 = V_148 ;
V_146 = 0 ;
F_20 (page, pagelist, lru) {
V_143 = V_147 -> V_149 << V_150 ;
V_144 = V_143 + V_151 - 1 ;
V_145 = V_145 ( V_145 , V_143 ) ;
V_146 = V_146 ( V_146 , V_144 ) ;
}
if ( V_145 < V_146 ) {
y1 = V_145 / V_38 -> V_152 . V_153 ;
V_120 = F_93 ( T_2 , F_96 ( V_146 , V_38 -> V_152 . V_153 ) ,
V_38 -> V_154 . V_155 ) ;
F_92 ( V_38 , 0 , y1 , V_38 -> V_154 . V_156 , V_120 - y1 ) ;
}
}
T_3 F_97 ( struct V_37 * V_38 , char T_4 * V_157 ,
T_5 V_158 , T_6 * V_159 )
{
return F_98 ( V_38 , V_157 , V_158 , V_159 ) ;
}
T_3 F_99 ( struct V_37 * V_38 , const char T_4 * V_157 ,
T_5 V_158 , T_6 * V_159 )
{
T_3 V_10 ;
V_10 = F_100 ( V_38 , V_157 , V_158 , V_159 ) ;
if ( V_10 > 0 )
F_92 ( V_38 , 0 , 0 , V_38 -> V_154 . V_156 ,
V_38 -> V_154 . V_155 ) ;
return V_10 ;
}
void F_101 ( struct V_37 * V_38 ,
const struct V_160 * V_161 )
{
F_102 ( V_38 , V_161 ) ;
F_92 ( V_38 , V_161 -> V_162 , V_161 -> V_163 ,
V_161 -> V_139 , V_161 -> V_140 ) ;
}
void F_103 ( struct V_37 * V_38 ,
const struct V_164 * V_165 )
{
F_104 ( V_38 , V_165 ) ;
F_92 ( V_38 , V_165 -> V_162 , V_165 -> V_163 ,
V_165 -> V_139 , V_165 -> V_140 ) ;
}
void F_105 ( struct V_37 * V_38 ,
const struct V_166 * V_167 )
{
F_106 ( V_38 , V_167 ) ;
F_92 ( V_38 , V_167 -> V_162 , V_167 -> V_163 ,
V_167 -> V_139 , V_167 -> V_140 ) ;
}
void F_107 ( struct V_37 * V_38 ,
const struct V_160 * V_161 )
{
F_108 ( V_38 , V_161 ) ;
F_92 ( V_38 , V_161 -> V_162 , V_161 -> V_163 ,
V_161 -> V_139 , V_161 -> V_140 ) ;
}
void F_109 ( struct V_37 * V_38 ,
const struct V_164 * V_165 )
{
F_110 ( V_38 , V_165 ) ;
F_92 ( V_38 , V_165 -> V_162 , V_165 -> V_163 ,
V_165 -> V_139 , V_165 -> V_140 ) ;
}
void F_111 ( struct V_37 * V_38 ,
const struct V_166 * V_167 )
{
F_112 ( V_38 , V_167 ) ;
F_92 ( V_38 , V_167 -> V_162 , V_167 -> V_163 ,
V_167 -> V_139 , V_167 -> V_140 ) ;
}
void F_113 ( struct V_1 * V_2 , bool V_168 )
{
if ( V_2 && V_2 -> V_110 )
F_65 ( V_2 -> V_110 , V_168 ) ;
}
void F_114 ( struct V_1 * V_2 ,
bool V_168 )
{
if ( ! V_2 || ! V_2 -> V_110 )
return;
F_115 ( & V_2 -> V_109 ) ;
if ( V_168 ) {
if ( V_2 -> V_110 -> V_61 != V_169 )
return;
F_64 () ;
} else {
if ( V_2 -> V_110 -> V_61 == V_169 )
return;
if ( ! F_116 () ) {
F_55 ( & V_2 -> V_109 ) ;
return;
}
}
F_65 ( V_2 -> V_110 , V_168 ) ;
F_66 () ;
}
static int F_117 ( struct V_26 * V_27 , T_7 V_170 , T_7 V_171 ,
T_7 V_172 , T_7 V_173 , struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_39 ;
struct V_52 * V_48 = V_2 -> V_48 ;
if ( V_38 -> V_152 . V_174 == V_175 ) {
T_2 * V_176 ;
T_2 V_177 ;
if ( V_173 > 16 )
return - V_25 ;
V_176 = ( T_2 * ) V_38 -> V_178 ;
V_170 >>= ( 16 - V_38 -> V_154 . V_170 . V_179 ) ;
V_171 >>= ( 16 - V_38 -> V_154 . V_171 . V_179 ) ;
V_172 >>= ( 16 - V_38 -> V_154 . V_172 . V_179 ) ;
V_177 = ( V_170 << V_38 -> V_154 . V_170 . V_180 ) |
( V_171 << V_38 -> V_154 . V_171 . V_180 ) |
( V_172 << V_38 -> V_154 . V_172 . V_180 ) ;
if ( V_38 -> V_154 . V_181 . V_179 > 0 ) {
T_2 V_182 = ( 1 << V_38 -> V_154 . V_181 . V_179 ) - 1 ;
V_182 <<= V_38 -> V_154 . V_181 . V_180 ;
V_177 |= V_182 ;
}
V_176 [ V_173 ] = V_177 ;
return 0 ;
}
if ( F_11 ( ! V_2 -> V_32 -> V_36 ||
! V_2 -> V_32 -> V_33 ) )
return - V_25 ;
F_11 ( V_48 -> V_183 -> V_184 [ 0 ] != 1 ) ;
V_2 -> V_32 -> V_36 ( V_27 , V_170 , V_171 , V_172 , V_173 ) ;
return 0 ;
}
int F_118 ( struct V_185 * V_132 , struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_39 ;
struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_40 * V_186 ;
T_7 * V_170 , * V_171 , * V_172 , * V_181 ;
struct V_26 * V_27 ;
int V_9 , V_24 , V_187 = 0 ;
int V_143 ;
if ( V_93 )
return - V_94 ;
F_46 ( V_4 ) ;
if ( ! F_49 ( V_2 ) ) {
F_47 ( V_4 ) ;
return - V_94 ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_41 ; V_9 ++ ) {
V_27 = V_2 -> V_44 [ V_9 ] . V_43 . V_27 ;
V_186 = V_27 -> V_46 ;
V_170 = V_132 -> V_170 ;
V_171 = V_132 -> V_171 ;
V_172 = V_132 -> V_172 ;
V_181 = V_132 -> V_181 ;
V_143 = V_132 -> V_143 ;
for ( V_24 = 0 ; V_24 < V_132 -> V_136 ; V_24 ++ ) {
T_7 V_188 , V_189 , V_190 , V_191 = 0xffff ;
V_188 = * V_170 ++ ;
V_189 = * V_171 ++ ;
V_190 = * V_172 ++ ;
if ( V_181 )
V_191 = * V_181 ++ ;
V_187 = F_117 ( V_27 , V_188 , V_189 , V_190 , V_143 ++ , V_38 ) ;
if ( V_187 )
goto V_15;
}
if ( V_186 -> V_192 )
V_186 -> V_192 ( V_27 ) ;
}
V_15:
F_47 ( V_4 ) ;
return V_187 ;
}
int F_119 ( struct V_193 * V_154 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_39 ;
struct V_52 * V_48 = V_2 -> V_48 ;
int V_194 ;
if ( V_154 -> V_195 != 0 || F_120 () )
return - V_25 ;
if ( V_154 -> V_196 != V_48 -> V_183 -> V_184 [ 0 ] * 8 ||
V_154 -> V_156 > V_48 -> V_139 || V_154 -> V_155 > V_48 -> V_140 ||
V_154 -> V_197 > V_48 -> V_139 || V_154 -> V_198 > V_48 -> V_140 ) {
F_121 ( L_3
L_4 ,
V_154 -> V_156 , V_154 -> V_155 , V_154 -> V_196 ,
V_154 -> V_197 , V_154 -> V_198 ,
V_48 -> V_139 , V_48 -> V_140 , V_48 -> V_183 -> V_184 [ 0 ] * 8 ) ;
return - V_25 ;
}
switch ( V_154 -> V_196 ) {
case 16 :
V_194 = ( V_154 -> V_171 . V_179 == 6 ) ? 16 : 15 ;
break;
case 32 :
V_194 = ( V_154 -> V_181 . V_179 > 0 ) ? 32 : 24 ;
break;
default:
V_194 = V_154 -> V_196 ;
break;
}
switch ( V_194 ) {
case 8 :
V_154 -> V_170 . V_180 = 0 ;
V_154 -> V_171 . V_180 = 0 ;
V_154 -> V_172 . V_180 = 0 ;
V_154 -> V_170 . V_179 = 8 ;
V_154 -> V_171 . V_179 = 8 ;
V_154 -> V_172 . V_179 = 8 ;
V_154 -> V_181 . V_179 = 0 ;
V_154 -> V_181 . V_180 = 0 ;
break;
case 15 :
V_154 -> V_170 . V_180 = 10 ;
V_154 -> V_171 . V_180 = 5 ;
V_154 -> V_172 . V_180 = 0 ;
V_154 -> V_170 . V_179 = 5 ;
V_154 -> V_171 . V_179 = 5 ;
V_154 -> V_172 . V_179 = 5 ;
V_154 -> V_181 . V_179 = 1 ;
V_154 -> V_181 . V_180 = 15 ;
break;
case 16 :
V_154 -> V_170 . V_180 = 11 ;
V_154 -> V_171 . V_180 = 5 ;
V_154 -> V_172 . V_180 = 0 ;
V_154 -> V_170 . V_179 = 5 ;
V_154 -> V_171 . V_179 = 6 ;
V_154 -> V_172 . V_179 = 5 ;
V_154 -> V_181 . V_179 = 0 ;
V_154 -> V_181 . V_180 = 0 ;
break;
case 24 :
V_154 -> V_170 . V_180 = 16 ;
V_154 -> V_171 . V_180 = 8 ;
V_154 -> V_172 . V_180 = 0 ;
V_154 -> V_170 . V_179 = 8 ;
V_154 -> V_171 . V_179 = 8 ;
V_154 -> V_172 . V_179 = 8 ;
V_154 -> V_181 . V_179 = 0 ;
V_154 -> V_181 . V_180 = 0 ;
break;
case 32 :
V_154 -> V_170 . V_180 = 16 ;
V_154 -> V_171 . V_180 = 8 ;
V_154 -> V_172 . V_180 = 0 ;
V_154 -> V_170 . V_179 = 8 ;
V_154 -> V_171 . V_179 = 8 ;
V_154 -> V_172 . V_179 = 8 ;
V_154 -> V_181 . V_179 = 8 ;
V_154 -> V_181 . V_180 = 24 ;
break;
default:
return - V_25 ;
}
return 0 ;
}
int F_122 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_39 ;
struct V_193 * V_154 = & V_38 -> V_154 ;
if ( V_93 )
return - V_94 ;
if ( V_154 -> V_195 != 0 ) {
F_24 ( L_5 ) ;
return - V_25 ;
}
F_45 ( V_2 ) ;
return 0 ;
}
static int F_123 ( struct V_193 * V_154 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_39 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_60 * V_61 ;
struct V_58 * V_59 ;
int V_9 , V_10 ;
unsigned V_62 ;
V_61 = F_26 ( V_4 ) ;
if ( ! V_61 )
return - V_23 ;
V_61 -> V_63 = V_4 -> V_12 . V_63 ;
V_64:
V_62 = 0 ;
for( V_9 = 0 ; V_9 < V_2 -> V_41 ; V_9 ++ ) {
struct V_42 * V_43 ;
V_43 = & V_2 -> V_44 [ V_9 ] . V_43 ;
V_43 -> V_49 = V_154 -> V_199 ;
V_43 -> V_50 = V_154 -> V_200 ;
V_10 = F_33 ( V_43 , V_61 ) ;
if ( V_10 != 0 )
goto V_14;
V_59 = V_43 -> V_27 -> V_56 ;
V_62 |= ( 1 << F_31 ( V_59 ) ) ;
V_59 -> V_69 = V_59 -> V_48 ;
}
V_10 = F_34 ( V_61 ) ;
if ( V_10 != 0 )
goto V_14;
V_38 -> V_154 . V_199 = V_154 -> V_199 ;
V_38 -> V_154 . V_200 = V_154 -> V_200 ;
V_14:
F_35 ( V_4 , V_62 , V_10 ) ;
if ( V_10 == - V_71 )
goto V_72;
F_36 ( V_61 ) ;
return V_10 ;
V_72:
F_37 ( V_61 ) ;
F_38 ( V_61 ) ;
goto V_64;
}
int F_124 ( struct V_193 * V_154 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_39 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_42 * V_104 ;
int V_10 = 0 ;
int V_9 ;
if ( V_93 )
return - V_94 ;
F_46 ( V_4 ) ;
if ( ! F_49 ( V_2 ) ) {
F_47 ( V_4 ) ;
return - V_94 ;
}
if ( F_41 ( V_4 ) ) {
V_10 = F_123 ( V_154 , V_38 ) ;
goto V_201;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_41 ; V_9 ++ ) {
V_104 = & V_2 -> V_44 [ V_9 ] . V_43 ;
V_104 -> V_49 = V_154 -> V_199 ;
V_104 -> V_50 = V_154 -> V_200 ;
if ( V_104 -> V_105 ) {
V_10 = F_44 ( V_104 ) ;
if ( ! V_10 ) {
V_38 -> V_154 . V_199 = V_154 -> V_199 ;
V_38 -> V_154 . V_200 = V_154 -> V_200 ;
}
}
}
V_201:
F_47 ( V_4 ) ;
return V_10 ;
}
static int F_125 ( struct V_1 * V_2 ,
int V_202 )
{
int V_10 = 0 ;
int V_41 = 0 ;
int V_9 ;
struct V_203 V_204 ;
int V_35 = 0 ;
memset ( & V_204 , 0 , sizeof( struct V_203 ) ) ;
V_204 . V_205 = 24 ;
V_204 . V_206 = 32 ;
V_204 . V_207 = ( unsigned ) - 1 ;
V_204 . V_208 = ( unsigned ) - 1 ;
if ( V_202 != V_204 . V_206 )
V_204 . V_205 = V_204 . V_206 = V_202 ;
F_6 (fb_helper, i) {
struct V_16 * V_209 = V_2 -> V_18 [ V_9 ] ;
struct V_210 * V_211 ;
V_211 = & V_209 -> V_6 -> V_211 ;
if ( V_211 -> V_212 ) {
switch ( V_211 -> V_213 ) {
case 8 :
V_204 . V_205 = V_204 . V_206 = 8 ;
break;
case 15 :
V_204 . V_205 = 15 ;
V_204 . V_206 = 16 ;
break;
case 16 :
V_204 . V_205 = V_204 . V_206 = 16 ;
break;
case 24 :
V_204 . V_205 = V_204 . V_206 = 24 ;
break;
case 32 :
V_204 . V_205 = 24 ;
V_204 . V_206 = 32 ;
break;
}
break;
}
}
V_41 = 0 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_41 ; V_9 ++ ) {
struct V_214 * V_215 ;
struct V_42 * V_43 ;
int V_49 , V_50 , V_24 ;
bool V_216 = true , V_217 = true ;
V_215 = V_2 -> V_44 [ V_9 ] . V_215 ;
V_43 = & V_2 -> V_44 [ V_9 ] . V_43 ;
if ( ! V_215 )
continue;
V_41 ++ ;
V_49 = V_2 -> V_44 [ V_9 ] . V_49 ;
V_50 = V_2 -> V_44 [ V_9 ] . V_50 ;
if ( V_35 == 0 )
V_35 = V_2 -> V_44 [ V_9 ] . V_43 . V_27 -> V_35 ;
V_204 . V_218 = F_94 ( T_2 , V_215 -> V_219 + V_49 , V_204 . V_218 ) ;
V_204 . V_220 = F_94 ( T_2 , V_215 -> V_221 + V_50 , V_204 . V_220 ) ;
for ( V_24 = 0 ; V_24 < V_43 -> V_105 ; V_24 ++ ) {
struct V_5 * V_6 = V_43 -> V_106 [ V_24 ] ;
if ( V_6 -> V_222 ) {
V_217 = ( V_6 -> V_223 == ( V_6 -> V_224 - 1 ) ) ;
V_216 = ( V_6 -> V_225 == ( V_6 -> V_226 - 1 ) ) ;
break;
}
}
if ( V_217 )
V_204 . V_207 = F_93 ( T_2 , V_215 -> V_219 + V_49 , V_204 . V_207 ) ;
if ( V_216 )
V_204 . V_208 = F_93 ( T_2 , V_215 -> V_221 + V_50 , V_204 . V_208 ) ;
}
if ( V_41 == 0 || V_204 . V_207 == - 1 || V_204 . V_208 == - 1 ) {
F_126 ( L_6 ) ;
V_204 . V_207 = V_204 . V_218 = 1024 ;
V_204 . V_208 = V_204 . V_220 = 768 ;
}
V_10 = (* V_2 -> V_32 -> V_227 )( V_2 , & V_204 ) ;
if ( V_10 < 0 )
return V_10 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_41 ; V_9 ++ )
if ( V_2 -> V_44 [ V_9 ] . V_43 . V_105 )
V_2 -> V_44 [ V_9 ] . V_43 . V_48 = V_2 -> V_48 ;
return 0 ;
}
void F_127 ( struct V_37 * V_38 , T_8 V_228 ,
T_8 V_194 )
{
V_38 -> V_152 . type = V_229 ;
V_38 -> V_152 . V_174 = V_194 == 8 ? V_230 :
V_175 ;
V_38 -> V_152 . V_231 = 0 ;
V_38 -> V_152 . V_232 = 0 ;
V_38 -> V_152 . V_233 = 0 ;
V_38 -> V_152 . V_234 = 1 ;
V_38 -> V_152 . V_235 = 1 ;
V_38 -> V_152 . V_236 = 0 ;
V_38 -> V_152 . V_237 = V_238 ;
V_38 -> V_152 . V_153 = V_228 ;
return;
}
void F_128 ( struct V_37 * V_38 , struct V_1 * V_2 ,
T_8 V_207 , T_8 V_208 )
{
struct V_52 * V_48 = V_2 -> V_48 ;
V_38 -> V_178 = V_2 -> V_178 ;
V_38 -> V_154 . V_197 = V_48 -> V_139 ;
V_38 -> V_154 . V_198 = V_48 -> V_140 ;
V_38 -> V_154 . V_196 = V_48 -> V_183 -> V_184 [ 0 ] * 8 ;
V_38 -> V_154 . V_239 = V_240 ;
V_38 -> V_154 . V_199 = 0 ;
V_38 -> V_154 . V_200 = 0 ;
V_38 -> V_154 . V_241 = V_242 ;
V_38 -> V_154 . V_140 = - 1 ;
V_38 -> V_154 . V_139 = - 1 ;
switch ( V_48 -> V_183 -> V_194 ) {
case 8 :
V_38 -> V_154 . V_170 . V_180 = 0 ;
V_38 -> V_154 . V_171 . V_180 = 0 ;
V_38 -> V_154 . V_172 . V_180 = 0 ;
V_38 -> V_154 . V_170 . V_179 = 8 ;
V_38 -> V_154 . V_171 . V_179 = 8 ;
V_38 -> V_154 . V_172 . V_179 = 8 ;
V_38 -> V_154 . V_181 . V_180 = 0 ;
V_38 -> V_154 . V_181 . V_179 = 0 ;
break;
case 15 :
V_38 -> V_154 . V_170 . V_180 = 10 ;
V_38 -> V_154 . V_171 . V_180 = 5 ;
V_38 -> V_154 . V_172 . V_180 = 0 ;
V_38 -> V_154 . V_170 . V_179 = 5 ;
V_38 -> V_154 . V_171 . V_179 = 5 ;
V_38 -> V_154 . V_172 . V_179 = 5 ;
V_38 -> V_154 . V_181 . V_180 = 15 ;
V_38 -> V_154 . V_181 . V_179 = 1 ;
break;
case 16 :
V_38 -> V_154 . V_170 . V_180 = 11 ;
V_38 -> V_154 . V_171 . V_180 = 5 ;
V_38 -> V_154 . V_172 . V_180 = 0 ;
V_38 -> V_154 . V_170 . V_179 = 5 ;
V_38 -> V_154 . V_171 . V_179 = 6 ;
V_38 -> V_154 . V_172 . V_179 = 5 ;
V_38 -> V_154 . V_181 . V_180 = 0 ;
break;
case 24 :
V_38 -> V_154 . V_170 . V_180 = 16 ;
V_38 -> V_154 . V_171 . V_180 = 8 ;
V_38 -> V_154 . V_172 . V_180 = 0 ;
V_38 -> V_154 . V_170 . V_179 = 8 ;
V_38 -> V_154 . V_171 . V_179 = 8 ;
V_38 -> V_154 . V_172 . V_179 = 8 ;
V_38 -> V_154 . V_181 . V_180 = 0 ;
V_38 -> V_154 . V_181 . V_179 = 0 ;
break;
case 32 :
V_38 -> V_154 . V_170 . V_180 = 16 ;
V_38 -> V_154 . V_171 . V_180 = 8 ;
V_38 -> V_154 . V_172 . V_180 = 0 ;
V_38 -> V_154 . V_170 . V_179 = 8 ;
V_38 -> V_154 . V_171 . V_179 = 8 ;
V_38 -> V_154 . V_172 . V_179 = 8 ;
V_38 -> V_154 . V_181 . V_180 = 24 ;
V_38 -> V_154 . V_181 . V_179 = 8 ;
break;
default:
break;
}
V_38 -> V_154 . V_156 = V_207 ;
V_38 -> V_154 . V_155 = V_208 ;
}
static int F_129 ( struct V_1 * V_2 ,
T_8 V_243 ,
T_8 V_244 )
{
struct V_5 * V_6 ;
int V_158 = 0 ;
int V_9 ;
F_6 (fb_helper, i) {
V_6 = V_2 -> V_18 [ V_9 ] -> V_6 ;
V_158 += V_6 -> V_32 -> V_245 ( V_6 , V_243 , V_244 ) ;
}
return V_158 ;
}
struct V_214 * F_130 ( struct V_16 * V_246 , int V_139 , int V_140 )
{
struct V_214 * V_107 ;
F_20 (mode, &fb_connector->connector->modes, head) {
if ( V_107 -> V_219 > V_139 ||
V_107 -> V_221 > V_140 )
continue;
if ( V_107 -> type & V_247 )
return V_107 ;
}
return NULL ;
}
static bool F_131 ( struct V_16 * V_246 )
{
return V_246 -> V_6 -> V_211 . V_248 ;
}
struct V_214 * F_132 ( struct V_16 * V_209 )
{
struct V_210 * V_211 ;
struct V_214 * V_107 ;
bool V_249 ;
V_211 = & V_209 -> V_6 -> V_211 ;
if ( V_211 -> V_248 == false )
return NULL ;
if ( V_211 -> V_250 || V_211 -> V_251 )
goto V_252;
V_249 = ! V_211 -> V_253 ;
V_254:
F_20 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_107 -> V_219 != V_211 -> V_156 ||
V_107 -> V_221 != V_211 -> V_155 )
continue;
if ( V_211 -> V_255 ) {
if ( V_107 -> V_256 != V_211 -> V_257 )
continue;
}
if ( V_211 -> V_253 ) {
if ( ! ( V_107 -> V_116 & V_258 ) )
continue;
} else if ( V_249 ) {
if ( V_107 -> V_116 & V_258 )
continue;
}
return V_107 ;
}
if ( V_249 ) {
V_249 = false ;
goto V_254;
}
V_252:
V_107 = F_133 ( V_209 -> V_6 -> V_4 ,
V_211 ) ;
F_134 ( & V_107 -> V_259 , & V_209 -> V_6 -> V_260 ) ;
return V_107 ;
}
static bool F_135 ( struct V_5 * V_6 , bool V_261 )
{
bool V_262 ;
if ( V_261 )
V_262 = V_6 -> V_263 == V_264 ;
else
V_262 = V_6 -> V_263 != V_265 ;
return V_262 ;
}
static void F_136 ( struct V_1 * V_2 ,
bool * V_45 )
{
bool V_266 = false ;
struct V_5 * V_6 ;
int V_9 = 0 ;
F_6 (fb_helper, i) {
V_6 = V_2 -> V_18 [ V_9 ] -> V_6 ;
V_45 [ V_9 ] = F_135 ( V_6 , true ) ;
F_137 ( L_7 , V_6 -> V_54 . V_55 ,
V_45 [ V_9 ] ? L_8 : L_9 ) ;
V_266 |= V_45 [ V_9 ] ;
}
if ( V_266 )
return;
F_6 (fb_helper, i) {
V_6 = V_2 -> V_18 [ V_9 ] -> V_6 ;
V_45 [ V_9 ] = F_135 ( V_6 , false ) ;
}
}
static bool F_138 ( struct V_1 * V_2 ,
struct V_214 * * V_260 ,
struct V_267 * V_268 ,
bool * V_45 , int V_139 , int V_140 )
{
int V_158 , V_9 , V_24 ;
bool V_269 = false ;
struct V_16 * V_209 ;
struct V_214 * V_270 , * V_107 ;
if ( V_2 -> V_41 > 1 )
return false ;
V_158 = 0 ;
F_6 (fb_helper, i) {
if ( V_45 [ V_9 ] )
V_158 ++ ;
}
if ( V_158 <= 1 )
return false ;
V_269 = true ;
F_6 (fb_helper, i) {
if ( ! V_45 [ V_9 ] )
continue;
V_209 = V_2 -> V_18 [ V_9 ] ;
V_260 [ V_9 ] = F_132 ( V_209 ) ;
if ( ! V_260 [ V_9 ] ) {
V_269 = false ;
break;
}
for ( V_24 = 0 ; V_24 < V_9 ; V_24 ++ ) {
if ( ! V_45 [ V_24 ] )
continue;
if ( ! F_139 ( V_260 [ V_24 ] , V_260 [ V_9 ] ) )
V_269 = false ;
}
}
if ( V_269 ) {
F_137 ( L_10 ) ;
return true ;
}
V_269 = true ;
V_270 = F_140 ( V_2 -> V_4 , 1024 , 768 , 60 , false ) ;
F_6 (fb_helper, i) {
if ( ! V_45 [ V_9 ] )
continue;
V_209 = V_2 -> V_18 [ V_9 ] ;
F_20 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_139 ( V_107 , V_270 ) )
V_260 [ V_9 ] = V_107 ;
}
if ( ! V_260 [ V_9 ] )
V_269 = false ;
}
if ( V_269 ) {
F_137 ( L_11 ) ;
return true ;
}
F_126 ( L_12 ) ;
return false ;
}
static int F_141 ( struct V_1 * V_2 ,
struct V_214 * * V_260 ,
struct V_267 * V_268 ,
int V_271 ,
int V_272 , int V_273 )
{
struct V_16 * V_209 ;
int V_9 ;
int V_274 = 0 , V_275 = 0 ;
F_6 (fb_helper, i) {
V_209 = V_2 -> V_18 [ V_9 ] ;
if ( ! V_209 -> V_6 -> V_222 )
continue;
if ( ! V_260 [ V_9 ] && ( V_272 || V_273 ) ) {
F_137 ( L_13 , V_9 ,
V_209 -> V_6 -> V_54 . V_55 ) ;
continue;
}
if ( V_209 -> V_6 -> V_223 < V_272 )
V_274 += V_260 [ V_9 ] -> V_219 ;
if ( V_209 -> V_6 -> V_225 < V_273 )
V_275 += V_260 [ V_9 ] -> V_221 ;
}
V_268 [ V_271 ] . V_49 = V_274 ;
V_268 [ V_271 ] . V_50 = V_275 ;
F_137 ( L_14 , V_274 , V_275 , V_272 , V_273 ) ;
return 0 ;
}
static bool F_142 ( struct V_1 * V_2 ,
struct V_214 * * V_260 ,
struct V_267 * V_268 ,
bool * V_45 , int V_139 , int V_140 )
{
struct V_16 * V_209 ;
const T_9 V_182 = F_143 ( V_2 -> V_19 ) - 1 ;
T_9 V_276 = 0 ;
int V_277 = 0 ;
int V_9 ;
V_64:
F_6 (fb_helper, i) {
V_209 = V_2 -> V_18 [ V_9 ] ;
if ( V_276 & F_143 ( V_9 ) )
continue;
if ( V_45 [ V_9 ] == false ) {
V_276 |= F_143 ( V_9 ) ;
continue;
}
if ( V_277 == 0 && V_209 -> V_6 -> V_222 )
continue;
if ( V_277 == 1 ) {
if ( V_209 -> V_6 -> V_223 != 0 ||
V_209 -> V_6 -> V_225 != 0 )
continue;
} else {
if ( V_209 -> V_6 -> V_223 != V_277 - 1 &&
V_209 -> V_6 -> V_225 != V_277 - 1 )
continue;
F_141 ( V_2 , V_260 , V_268 ,
V_9 , V_209 -> V_6 -> V_223 , V_209 -> V_6 -> V_225 ) ;
}
F_137 ( L_15 ,
V_209 -> V_6 -> V_54 . V_55 ) ;
V_260 [ V_9 ] = F_132 ( V_209 ) ;
if ( ! V_260 [ V_9 ] ) {
F_137 ( L_16 ,
V_209 -> V_6 -> V_54 . V_55 , V_209 -> V_6 -> V_278 ? V_209 -> V_6 -> V_278 -> V_55 : 0 ) ;
V_260 [ V_9 ] = F_130 ( V_209 , V_139 , V_140 ) ;
}
if ( ! V_260 [ V_9 ] && ! F_52 ( & V_209 -> V_6 -> V_260 ) ) {
F_20 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_137 ( L_17 , V_260 [ V_9 ] ? V_260 [ V_9 ] -> V_279 :
L_18 ) ;
V_276 |= F_143 ( V_9 ) ;
}
if ( ( V_276 & V_182 ) != V_182 ) {
V_277 ++ ;
goto V_64;
}
return true ;
}
static int F_144 ( struct V_1 * V_2 ,
struct V_128 * * V_280 ,
struct V_214 * * V_260 ,
int V_281 , int V_139 , int V_140 )
{
int V_53 , V_282 ;
struct V_5 * V_6 ;
const struct V_283 * V_284 ;
struct V_285 * V_286 ;
int V_287 , V_288 , V_289 ;
struct V_128 * * V_290 , * V_27 ;
struct V_16 * V_209 ;
if ( V_281 == V_2 -> V_19 )
return 0 ;
V_209 = V_2 -> V_18 [ V_281 ] ;
V_6 = V_209 -> V_6 ;
V_280 [ V_281 ] = NULL ;
V_288 = F_144 ( V_2 , V_280 , V_260 , V_281 + 1 , V_139 , V_140 ) ;
if ( V_260 [ V_281 ] == NULL )
return V_288 ;
V_290 = F_14 ( V_2 -> V_19 *
sizeof( struct V_128 * ) , V_22 ) ;
if ( ! V_290 )
return V_288 ;
V_287 = 1 ;
if ( V_6 -> V_263 == V_264 )
V_287 ++ ;
if ( F_131 ( V_209 ) )
V_287 ++ ;
if ( F_130 ( V_209 , V_139 , V_140 ) )
V_287 ++ ;
V_284 = V_6 -> V_46 ;
if ( F_41 ( V_2 -> V_4 ) &&
! V_284 -> V_291 )
V_286 = F_145 ( V_6 ) ;
else
V_286 = V_284 -> V_291 ( V_6 ) ;
if ( ! V_286 )
goto V_15;
for ( V_53 = 0 ; V_53 < V_2 -> V_41 ; V_53 ++ ) {
V_27 = & V_2 -> V_44 [ V_53 ] ;
if ( ( V_286 -> V_292 & ( 1 << V_53 ) ) == 0 )
continue;
for ( V_282 = 0 ; V_282 < V_281 ; V_282 ++ )
if ( V_280 [ V_282 ] == V_27 )
break;
if ( V_282 < V_281 ) {
if ( V_2 -> V_41 > 1 )
continue;
if ( ! F_139 ( V_260 [ V_282 ] , V_260 [ V_281 ] ) )
continue;
}
V_290 [ V_281 ] = V_27 ;
memcpy ( V_290 , V_280 , V_281 * sizeof( struct V_128 * ) ) ;
V_289 = V_287 + F_144 ( V_2 , V_290 , V_260 , V_281 + 1 ,
V_139 , V_140 ) ;
if ( V_289 > V_288 ) {
V_288 = V_289 ;
memcpy ( V_280 , V_290 ,
V_2 -> V_19 *
sizeof( struct V_128 * ) ) ;
}
}
V_15:
F_8 ( V_290 ) ;
return V_288 ;
}
static void F_146 ( struct V_1 * V_2 ,
T_2 V_139 , T_2 V_140 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_128 * * V_290 ;
struct V_214 * * V_260 ;
struct V_267 * V_268 ;
bool * V_45 ;
int V_9 ;
F_137 ( L_19 ) ;
if ( F_129 ( V_2 , V_139 , V_140 ) == 0 )
F_137 ( L_20 ) ;
F_147 ( & V_2 -> V_4 -> V_12 . V_13 ) ;
V_290 = F_75 ( V_2 -> V_19 ,
sizeof( struct V_128 * ) , V_22 ) ;
V_260 = F_75 ( V_2 -> V_19 ,
sizeof( struct V_214 * ) , V_22 ) ;
V_268 = F_75 ( V_2 -> V_19 ,
sizeof( struct V_267 ) , V_22 ) ;
V_45 = F_75 ( V_2 -> V_19 ,
sizeof( bool ) , V_22 ) ;
if ( ! V_290 || ! V_260 || ! V_45 || ! V_268 ) {
F_24 ( L_21 ) ;
goto V_15;
}
F_136 ( V_2 , V_45 ) ;
if ( ! ( V_2 -> V_32 -> V_293 &&
V_2 -> V_32 -> V_293 ( V_2 , V_290 , V_260 ,
V_268 ,
V_45 , V_139 , V_140 ) ) ) {
memset ( V_260 , 0 , V_2 -> V_19 * sizeof( V_260 [ 0 ] ) ) ;
memset ( V_290 , 0 , V_2 -> V_19 * sizeof( V_290 [ 0 ] ) ) ;
memset ( V_268 , 0 , V_2 -> V_19 * sizeof( V_268 [ 0 ] ) ) ;
if ( ! F_138 ( V_2 , V_260 , V_268 ,
V_45 , V_139 , V_140 ) &&
! F_142 ( V_2 , V_260 , V_268 ,
V_45 , V_139 , V_140 ) )
F_24 ( L_22 ) ;
F_137 ( L_23 ,
V_139 , V_140 ) ;
F_144 ( V_2 , V_290 , V_260 , 0 , V_139 , V_140 ) ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_41 ; V_9 ++ )
F_59 ( V_2 ,
& V_2 -> V_44 [ V_9 ] . V_43 ) ;
F_6 (fb_helper, i) {
struct V_214 * V_107 = V_260 [ V_9 ] ;
struct V_128 * V_294 = V_290 [ V_9 ] ;
struct V_267 * V_180 = & V_268 [ V_9 ] ;
struct V_42 * V_104 = & V_294 -> V_43 ;
if ( V_107 && V_294 ) {
struct V_5 * V_6 =
V_2 -> V_18 [ V_9 ] -> V_6 ;
F_137 ( L_24 ,
V_107 -> V_279 , V_294 -> V_43 . V_27 -> V_54 . V_55 , V_180 -> V_49 , V_180 -> V_50 ) ;
V_294 -> V_215 = V_107 ;
V_294 -> V_49 = V_180 -> V_49 ;
V_294 -> V_50 = V_180 -> V_50 ;
V_104 -> V_107 = F_148 ( V_4 ,
V_294 -> V_215 ) ;
F_15 ( V_6 ) ;
V_104 -> V_106 [ V_104 -> V_105 ++ ] = V_6 ;
V_104 -> V_48 = V_2 -> V_48 ;
V_104 -> V_49 = V_180 -> V_49 ;
V_104 -> V_50 = V_180 -> V_50 ;
}
}
V_15:
F_8 ( V_290 ) ;
F_8 ( V_260 ) ;
F_8 ( V_268 ) ;
F_8 ( V_45 ) ;
}
int F_149 ( struct V_1 * V_2 , int V_295 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_37 * V_38 ;
int V_10 ;
if ( ! V_11 )
return 0 ;
F_2 ( & V_4 -> V_12 . V_13 ) ;
F_146 ( V_2 ,
V_4 -> V_12 . V_296 ,
V_4 -> V_12 . V_297 ) ;
V_10 = F_125 ( V_2 , V_295 ) ;
F_10 ( & V_4 -> V_12 . V_13 ) ;
if ( V_10 )
return V_10 ;
V_38 = V_2 -> V_110 ;
V_38 -> V_154 . V_195 = 0 ;
V_10 = F_150 ( V_38 ) ;
if ( V_10 < 0 )
return V_10 ;
F_151 ( V_4 -> V_4 , L_25 ,
V_38 -> V_298 , V_38 -> V_152 . V_55 ) ;
F_2 ( & V_137 ) ;
if ( F_52 ( & V_82 ) )
F_152 ( 'v' , & V_138 ) ;
F_134 ( & V_2 -> V_123 , & V_82 ) ;
F_10 ( & V_137 ) ;
return 0 ;
}
int F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! V_11 )
return 0 ;
F_2 ( & V_4 -> V_12 . V_13 ) ;
if ( ! V_2 -> V_48 || ! F_49 ( V_2 ) ) {
V_2 -> V_78 = true ;
F_10 ( & V_4 -> V_12 . V_13 ) ;
return 0 ;
}
F_137 ( L_19 ) ;
F_146 ( V_2 , V_2 -> V_48 -> V_139 , V_2 -> V_48 -> V_140 ) ;
F_10 ( & V_4 -> V_12 . V_13 ) ;
F_122 ( V_2 -> V_110 ) ;
return 0 ;
}
int T_10 F_153 ( void )
{
#if F_154 ( V_299 ) && ! F_154 ( V_300 )
const char * V_279 = L_26 ;
struct V_301 * V_302 ;
F_2 ( & V_303 ) ;
V_302 = F_155 ( V_279 ) ;
F_10 ( & V_303 ) ;
if ( ! V_302 )
F_156 ( V_279 ) ;
#endif
return 0 ;
}
