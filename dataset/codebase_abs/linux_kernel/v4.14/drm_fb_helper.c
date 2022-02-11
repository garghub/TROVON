static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_5 * * V_7 ;
unsigned int V_8 ;
if ( ! V_9 )
return 0 ;
F_2 ( & V_2 -> V_10 ) ;
V_8 = V_2 -> V_11 + 1 ;
if ( V_8 > V_2 -> V_12 ) {
T_1 V_13 = V_8 * sizeof( V_6 ) ;
V_7 = F_3 ( V_2 -> V_14 , V_13 , V_15 ) ;
if ( ! V_7 )
return - V_16 ;
V_2 -> V_12 = V_8 ;
V_2 -> V_14 = V_7 ;
}
V_6 = F_4 ( sizeof( * V_6 ) , V_15 ) ;
if ( ! V_6 )
return - V_16 ;
F_5 ( V_4 ) ;
V_6 -> V_4 = V_4 ;
V_2 -> V_14 [ V_2 -> V_11 ++ ] = V_6 ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_17 ;
F_7 ( & V_2 -> V_10 ) ;
V_17 = F_1 ( V_2 , V_4 ) ;
F_8 ( & V_2 -> V_10 ) ;
return V_17 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_3 * V_4 ;
struct V_20 V_21 ;
int V_22 , V_23 = 0 ;
if ( ! V_9 )
return 0 ;
F_7 ( & V_2 -> V_10 ) ;
F_10 ( V_19 , & V_21 ) ;
F_11 (connector, &conn_iter) {
V_23 = F_1 ( V_2 , V_4 ) ;
if ( V_23 )
goto V_24;
}
goto V_25;
V_24:
F_12 (fb_helper, i) {
struct V_5 * V_26 =
V_2 -> V_14 [ V_22 ] ;
F_13 ( V_26 -> V_4 ) ;
F_14 ( V_26 ) ;
V_2 -> V_14 [ V_22 ] = NULL ;
}
V_2 -> V_11 = 0 ;
V_25:
F_15 ( & V_21 ) ;
F_8 ( & V_2 -> V_10 ) ;
return V_23 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_26 ;
int V_22 , V_27 ;
if ( ! V_9 )
return 0 ;
F_2 ( & V_2 -> V_10 ) ;
F_12 (fb_helper, i) {
if ( V_2 -> V_14 [ V_22 ] -> V_4 == V_4 )
break;
}
if ( V_22 == V_2 -> V_11 )
return - V_28 ;
V_26 = V_2 -> V_14 [ V_22 ] ;
F_13 ( V_26 -> V_4 ) ;
for ( V_27 = V_22 + 1 ; V_27 < V_2 -> V_11 ; V_27 ++ )
V_2 -> V_14 [ V_27 - 1 ] = V_2 -> V_14 [ V_27 ] ;
V_2 -> V_11 -- ;
F_14 ( V_26 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_17 ;
F_7 ( & V_2 -> V_10 ) ;
V_17 = F_16 ( V_2 , V_4 ) ;
F_8 ( & V_2 -> V_10 ) ;
return V_17 ;
}
static void F_18 ( struct V_29 * V_30 )
{
T_2 * V_31 , * V_32 , * V_33 ;
if ( V_30 -> V_34 -> V_35 == NULL )
return;
V_31 = V_30 -> V_36 ;
V_32 = V_31 + V_30 -> V_37 ;
V_33 = V_32 + V_30 -> V_37 ;
V_30 -> V_34 -> V_35 ( V_30 , V_31 , V_32 , V_33 ,
V_30 -> V_37 , NULL ) ;
}
int F_19 ( struct V_38 * V_39 )
{
struct V_1 * V_40 = V_39 -> V_41 ;
const struct V_42 * V_34 ;
int V_22 ;
F_20 (helper, &kernel_fb_helper_list, kernel_fb_list) {
for ( V_22 = 0 ; V_22 < V_40 -> V_43 ; V_22 ++ ) {
struct V_44 * V_45 =
& V_40 -> V_46 [ V_22 ] . V_45 ;
if ( ! V_45 -> V_30 -> V_47 )
continue;
V_34 = V_45 -> V_30 -> V_48 ;
if ( V_34 -> V_49 == NULL )
continue;
if ( F_21 ( V_45 -> V_30 -> V_19 ) )
continue;
V_34 -> V_49 ( V_45 -> V_30 ,
V_45 -> V_50 ,
V_45 -> V_51 ,
V_45 -> V_52 ,
V_53 ) ;
}
}
return 0 ;
}
int F_22 ( struct V_38 * V_39 )
{
struct V_1 * V_40 = V_39 -> V_41 ;
struct V_29 * V_30 ;
const struct V_42 * V_34 ;
struct V_54 * V_50 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_40 -> V_43 ; V_22 ++ ) {
struct V_44 * V_45 = & V_40 -> V_46 [ V_22 ] . V_45 ;
V_30 = V_45 -> V_30 ;
if ( F_21 ( V_30 -> V_19 ) )
continue;
V_34 = V_30 -> V_48 ;
V_50 = V_30 -> V_55 -> V_50 ;
if ( ! V_30 -> V_47 )
continue;
if ( ! V_50 ) {
F_23 ( L_1 ) ;
continue;
}
if ( V_34 -> V_49 == NULL )
continue;
F_18 ( V_45 -> V_30 ) ;
V_34 -> V_49 ( V_45 -> V_30 , V_50 , V_30 -> V_51 ,
V_30 -> V_52 , V_56 ) ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , bool V_57 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
int V_22 , V_23 ;
unsigned int V_62 ;
struct V_63 V_64 ;
F_25 ( & V_64 , 0 ) ;
V_61 = F_26 ( V_19 ) ;
if ( ! V_61 ) {
V_23 = - V_16 ;
goto V_65;
}
V_61 -> V_66 = & V_64 ;
V_67:
V_62 = 0 ;
F_27 (plane, dev) {
struct V_68 * V_69 ;
V_69 = F_28 ( V_61 , V_59 ) ;
if ( F_29 ( V_69 ) ) {
V_23 = F_30 ( V_69 ) ;
goto V_70;
}
V_69 -> V_71 = V_72 ;
V_59 -> V_73 = V_59 -> V_50 ;
V_62 |= 1 << F_31 ( V_59 ) ;
if ( V_59 -> type == V_74 )
continue;
V_23 = F_32 ( V_59 , V_69 ) ;
if ( V_23 != 0 )
goto V_70;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_43 ; V_22 ++ ) {
struct V_44 * V_45 = & V_2 -> V_46 [ V_22 ] . V_45 ;
V_23 = F_33 ( V_45 , V_61 ) ;
if ( V_23 != 0 )
goto V_70;
if ( ! V_57 ) {
struct V_29 * V_30 = V_45 -> V_30 ;
struct V_75 * V_76 = F_34 ( V_61 , V_30 ) ;
V_76 -> V_57 = false ;
}
}
V_23 = F_35 ( V_61 ) ;
V_70:
F_36 ( V_19 , V_62 , V_23 ) ;
if ( V_23 == - V_77 )
goto V_78;
F_37 ( V_61 ) ;
V_65:
F_38 ( & V_64 ) ;
F_39 ( & V_64 ) ;
return V_23 ;
V_78:
F_40 ( V_61 ) ;
F_41 ( & V_64 ) ;
goto V_67;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_58 * V_59 ;
int V_22 , V_23 = 0 ;
F_43 ( V_2 -> V_19 ) ;
F_27 (plane, dev) {
if ( V_59 -> type != V_74 )
F_44 ( V_59 ) ;
if ( V_59 -> V_79 )
F_45 ( V_59 ,
V_59 -> V_79 ,
V_72 ) ;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_43 ; V_22 ++ ) {
struct V_44 * V_45 = & V_2 -> V_46 [ V_22 ] . V_45 ;
struct V_29 * V_30 = V_45 -> V_30 ;
if ( V_30 -> V_34 -> V_80 ) {
V_23 = V_30 -> V_34 -> V_80 ( V_30 , NULL , 0 , 0 , 0 , 0 , 0 ) ;
if ( V_23 )
goto V_25;
} else if ( V_30 -> V_34 -> V_81 ) {
V_23 = V_30 -> V_34 -> V_81 ( V_30 , NULL , 0 , 0 , 0 ) ;
if ( V_23 )
goto V_25;
}
V_23 = F_46 ( V_45 ) ;
if ( V_23 )
goto V_25;
}
V_25:
F_47 ( V_2 -> V_19 ) ;
return V_23 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
if ( F_21 ( V_19 ) )
return F_24 ( V_2 , true ) ;
else
return F_42 ( V_2 ) ;
}
int F_49 ( struct V_1 * V_2 )
{
bool V_82 ;
int V_23 ;
if ( ! V_9 )
return - V_83 ;
if ( F_50 ( V_2 -> V_84 ) )
return 0 ;
F_7 ( & V_2 -> V_10 ) ;
V_23 = F_48 ( V_2 ) ;
V_82 = V_2 -> V_85 ;
if ( V_82 )
V_2 -> V_85 = false ;
F_8 ( & V_2 -> V_10 ) ;
if ( V_82 )
F_51 ( V_2 ) ;
return V_23 ;
}
static bool F_52 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_29 * V_30 ;
int V_86 = 0 , V_87 = 0 ;
if ( F_50 ( V_19 -> V_88 ) )
return false ;
F_53 (crtc, dev) {
F_54 ( & V_30 -> V_89 , NULL ) ;
if ( V_30 -> V_55 -> V_50 )
V_87 ++ ;
if ( V_30 -> V_55 -> V_50 == V_2 -> V_50 )
V_86 ++ ;
F_55 ( & V_30 -> V_89 ) ;
}
if ( V_86 < V_87 )
return false ;
return true ;
}
static bool F_56 ( void )
{
bool V_23 , error = false ;
struct V_1 * V_40 ;
if ( F_57 ( & V_90 ) )
return false ;
F_20 (helper, &kernel_fb_helper_list, kernel_fb_list) {
struct V_18 * V_19 = V_40 -> V_19 ;
if ( V_19 -> V_91 == V_92 )
continue;
F_7 ( & V_40 -> V_10 ) ;
V_23 = F_48 ( V_40 ) ;
if ( V_23 )
error = true ;
F_8 ( & V_40 -> V_10 ) ;
}
return error ;
}
static void F_58 ( struct V_93 * V_94 )
{
bool V_23 ;
V_23 = F_56 () ;
if ( V_23 == true )
F_23 ( L_2 ) ;
}
static void F_59 ( int V_95 )
{
F_60 ( & V_96 ) ;
}
static void F_61 ( struct V_1 * V_2 , int V_97 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_29 * V_30 ;
struct V_3 * V_4 ;
int V_22 , V_27 ;
F_43 ( V_19 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_43 ; V_22 ++ ) {
V_30 = V_2 -> V_46 [ V_22 ] . V_45 . V_30 ;
if ( ! V_30 -> V_47 )
continue;
F_12 (fb_helper, j) {
V_4 = V_2 -> V_14 [ V_27 ] -> V_4 ;
V_4 -> V_34 -> V_98 ( V_4 , V_97 ) ;
F_62 ( & V_4 -> V_99 ,
V_19 -> V_100 . V_101 , V_97 ) ;
}
}
F_47 ( V_19 ) ;
}
static void F_63 ( struct V_38 * V_39 , int V_97 )
{
struct V_1 * V_2 = V_39 -> V_41 ;
F_7 ( & V_2 -> V_10 ) ;
if ( ! F_52 ( V_2 ) ) {
F_8 ( & V_2 -> V_10 ) ;
return;
}
if ( F_21 ( V_2 -> V_19 ) )
F_24 ( V_2 , V_97 == V_102 ) ;
else
F_61 ( V_2 , V_97 ) ;
F_8 ( & V_2 -> V_10 ) ;
}
int F_64 ( int V_103 , struct V_38 * V_39 )
{
if ( V_104 )
return - V_105 ;
switch ( V_103 ) {
case V_106 :
F_63 ( V_39 , V_102 ) ;
break;
case V_107 :
F_63 ( V_39 , V_108 ) ;
break;
case V_109 :
F_63 ( V_39 , V_108 ) ;
break;
case V_110 :
F_63 ( V_39 , V_111 ) ;
break;
case V_112 :
F_63 ( V_39 , V_113 ) ;
break;
}
return 0 ;
}
static void F_65 ( struct V_1 * V_40 ,
struct V_44 * V_114 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_114 -> V_115 ; V_22 ++ ) {
F_13 ( V_114 -> V_116 [ V_22 ] ) ;
V_114 -> V_116 [ V_22 ] = NULL ;
}
V_114 -> V_115 = 0 ;
F_66 ( V_40 -> V_19 , V_114 -> V_117 ) ;
V_114 -> V_117 = NULL ;
V_114 -> V_50 = NULL ;
}
static void F_67 ( struct V_1 * V_40 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_40 -> V_11 ; V_22 ++ ) {
F_13 ( V_40 -> V_14 [ V_22 ] -> V_4 ) ;
F_14 ( V_40 -> V_14 [ V_22 ] ) ;
}
F_14 ( V_40 -> V_14 ) ;
for ( V_22 = 0 ; V_22 < V_40 -> V_43 ; V_22 ++ ) {
struct V_44 * V_114 = & V_40 -> V_46 [ V_22 ] . V_45 ;
F_65 ( V_40 , V_114 ) ;
F_14 ( V_114 -> V_116 ) ;
}
F_14 ( V_40 -> V_46 ) ;
}
static void F_68 ( struct V_93 * V_118 )
{
struct V_1 * V_40 = F_69 ( V_118 , struct V_1 ,
V_119 ) ;
F_70 () ;
F_71 ( V_40 -> V_120 , 0 ) ;
F_72 () ;
}
static void F_73 ( struct V_93 * V_118 )
{
struct V_1 * V_40 = F_69 ( V_118 , struct V_1 ,
V_121 ) ;
struct V_122 * V_123 = & V_40 -> V_124 ;
struct V_122 V_125 ;
unsigned long V_126 ;
F_74 ( & V_40 -> V_127 , V_126 ) ;
V_125 = * V_123 ;
V_123 -> V_128 = V_123 -> y1 = ~ 0 ;
V_123 -> V_129 = V_123 -> V_130 = 0 ;
F_75 ( & V_40 -> V_127 , V_126 ) ;
if ( V_125 . V_128 < V_125 . V_129 && V_125 . y1 < V_125 . V_130 )
V_40 -> V_50 -> V_34 -> V_131 ( V_40 -> V_50 , NULL , 0 , 0 , & V_125 , 1 ) ;
}
void F_76 ( struct V_18 * V_19 , struct V_1 * V_40 ,
const struct V_132 * V_34 )
{
F_77 ( & V_40 -> V_133 ) ;
F_78 ( & V_40 -> V_127 ) ;
F_79 ( & V_40 -> V_119 , F_68 ) ;
F_79 ( & V_40 -> V_121 , F_73 ) ;
V_40 -> V_124 . V_128 = V_40 -> V_124 . y1 = ~ 0 ;
F_80 ( & V_40 -> V_10 ) ;
V_40 -> V_34 = V_34 ;
V_40 -> V_19 = V_19 ;
}
int F_81 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_134 )
{
struct V_29 * V_30 ;
struct V_135 * V_136 = & V_19 -> V_100 ;
int V_22 ;
if ( ! V_9 )
return 0 ;
if ( ! V_134 )
return - V_28 ;
V_2 -> V_46 = F_82 ( V_136 -> V_137 , sizeof( struct V_138 ) , V_15 ) ;
if ( ! V_2 -> V_46 )
return - V_16 ;
V_2 -> V_43 = V_136 -> V_137 ;
V_2 -> V_14 = F_82 ( V_19 -> V_100 . V_139 , sizeof( struct V_5 * ) , V_15 ) ;
if ( ! V_2 -> V_14 ) {
F_14 ( V_2 -> V_46 ) ;
return - V_16 ;
}
V_2 -> V_12 = V_19 -> V_100 . V_139 ;
V_2 -> V_11 = 0 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_43 ; V_22 ++ ) {
V_2 -> V_46 [ V_22 ] . V_45 . V_116 =
F_82 ( V_134 ,
sizeof( struct V_3 * ) ,
V_15 ) ;
if ( ! V_2 -> V_46 [ V_22 ] . V_45 . V_116 )
goto V_140;
V_2 -> V_46 [ V_22 ] . V_45 . V_115 = 0 ;
}
V_22 = 0 ;
F_53 (crtc, dev) {
V_2 -> V_46 [ V_22 ] . V_45 . V_30 = V_30 ;
V_22 ++ ;
}
return 0 ;
V_140:
F_67 ( V_2 ) ;
return - V_16 ;
}
struct V_38 * F_83 ( struct V_1 * V_2 )
{
struct V_141 * V_19 = V_2 -> V_19 -> V_19 ;
struct V_38 * V_39 ;
int V_23 ;
V_39 = F_84 ( 0 , V_19 ) ;
if ( ! V_39 )
return F_85 ( - V_16 ) ;
V_23 = F_86 ( & V_39 -> V_142 , 256 , 0 ) ;
if ( V_23 )
goto V_143;
V_39 -> V_144 = F_87 ( 1 ) ;
if ( ! V_39 -> V_144 ) {
V_23 = - V_16 ;
goto V_145;
}
V_2 -> V_120 = V_39 ;
return V_39 ;
V_145:
F_88 ( & V_39 -> V_142 ) ;
V_143:
F_89 ( V_39 ) ;
return F_85 ( V_23 ) ;
}
void F_90 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_120 )
F_91 ( V_2 -> V_120 ) ;
}
void F_92 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
if ( ! V_9 || ! V_2 )
return;
V_39 = V_2 -> V_120 ;
if ( V_39 ) {
if ( V_39 -> V_142 . V_146 )
F_88 ( & V_39 -> V_142 ) ;
F_89 ( V_39 ) ;
}
V_2 -> V_120 = NULL ;
F_93 ( & V_2 -> V_119 ) ;
F_93 ( & V_2 -> V_121 ) ;
F_7 ( & V_147 ) ;
if ( ! F_57 ( & V_2 -> V_133 ) ) {
F_94 ( & V_2 -> V_133 ) ;
if ( F_57 ( & V_90 ) )
F_95 ( 'v' , & V_148 ) ;
}
F_8 ( & V_147 ) ;
F_96 ( & V_2 -> V_10 ) ;
F_67 ( V_2 ) ;
}
void F_97 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_120 )
F_98 ( V_2 -> V_120 ) ;
}
static void F_99 ( struct V_38 * V_39 , T_3 V_51 , T_3 V_52 ,
T_3 V_149 , T_3 V_150 )
{
struct V_1 * V_40 = V_39 -> V_41 ;
struct V_122 * V_123 = & V_40 -> V_124 ;
unsigned long V_126 ;
if ( ! V_40 -> V_50 -> V_34 -> V_131 )
return;
F_74 ( & V_40 -> V_127 , V_126 ) ;
V_123 -> V_128 = F_100 ( T_3 , V_123 -> V_128 , V_51 ) ;
V_123 -> y1 = F_100 ( T_3 , V_123 -> y1 , V_52 ) ;
V_123 -> V_129 = F_101 ( T_3 , V_123 -> V_129 , V_51 + V_149 ) ;
V_123 -> V_130 = F_101 ( T_3 , V_123 -> V_130 , V_52 + V_150 ) ;
F_75 ( & V_40 -> V_127 , V_126 ) ;
F_60 ( & V_40 -> V_121 ) ;
}
void F_102 ( struct V_38 * V_39 ,
struct V_151 * V_152 )
{
unsigned long V_153 , V_154 , V_155 , V_156 ;
struct V_157 * V_157 ;
T_3 y1 , V_130 ;
V_155 = V_158 ;
V_156 = 0 ;
F_20 (page, pagelist, lru) {
V_153 = V_157 -> V_159 << V_160 ;
V_154 = V_153 + V_161 - 1 ;
V_155 = V_155 ( V_155 , V_153 ) ;
V_156 = V_156 ( V_156 , V_154 ) ;
}
if ( V_155 < V_156 ) {
y1 = V_155 / V_39 -> V_162 . V_163 ;
V_130 = F_100 ( T_3 , F_103 ( V_156 , V_39 -> V_162 . V_163 ) ,
V_39 -> V_164 . V_165 ) ;
F_99 ( V_39 , 0 , y1 , V_39 -> V_164 . V_166 , V_130 - y1 ) ;
}
}
T_4 F_104 ( struct V_38 * V_39 , char T_5 * V_167 ,
T_1 V_8 , T_6 * V_168 )
{
return F_105 ( V_39 , V_167 , V_8 , V_168 ) ;
}
T_4 F_106 ( struct V_38 * V_39 , const char T_5 * V_167 ,
T_1 V_8 , T_6 * V_168 )
{
T_4 V_23 ;
V_23 = F_107 ( V_39 , V_167 , V_8 , V_168 ) ;
if ( V_23 > 0 )
F_99 ( V_39 , 0 , 0 , V_39 -> V_164 . V_166 ,
V_39 -> V_164 . V_165 ) ;
return V_23 ;
}
void F_108 ( struct V_38 * V_39 ,
const struct V_169 * V_170 )
{
F_109 ( V_39 , V_170 ) ;
F_99 ( V_39 , V_170 -> V_171 , V_170 -> V_172 ,
V_170 -> V_149 , V_170 -> V_150 ) ;
}
void F_110 ( struct V_38 * V_39 ,
const struct V_173 * V_174 )
{
F_111 ( V_39 , V_174 ) ;
F_99 ( V_39 , V_174 -> V_171 , V_174 -> V_172 ,
V_174 -> V_149 , V_174 -> V_150 ) ;
}
void F_112 ( struct V_38 * V_39 ,
const struct V_175 * V_176 )
{
F_113 ( V_39 , V_176 ) ;
F_99 ( V_39 , V_176 -> V_171 , V_176 -> V_172 ,
V_176 -> V_149 , V_176 -> V_150 ) ;
}
void F_114 ( struct V_38 * V_39 ,
const struct V_169 * V_170 )
{
F_115 ( V_39 , V_170 ) ;
F_99 ( V_39 , V_170 -> V_171 , V_170 -> V_172 ,
V_170 -> V_149 , V_170 -> V_150 ) ;
}
void F_116 ( struct V_38 * V_39 ,
const struct V_173 * V_174 )
{
F_117 ( V_39 , V_174 ) ;
F_99 ( V_39 , V_174 -> V_171 , V_174 -> V_172 ,
V_174 -> V_149 , V_174 -> V_150 ) ;
}
void F_118 ( struct V_38 * V_39 ,
const struct V_175 * V_176 )
{
F_119 ( V_39 , V_176 ) ;
F_99 ( V_39 , V_176 -> V_171 , V_176 -> V_172 ,
V_176 -> V_149 , V_176 -> V_150 ) ;
}
void F_120 ( struct V_1 * V_2 , bool V_177 )
{
if ( V_2 && V_2 -> V_120 )
F_71 ( V_2 -> V_120 , V_177 ) ;
}
void F_121 ( struct V_1 * V_2 ,
bool V_177 )
{
if ( ! V_2 || ! V_2 -> V_120 )
return;
F_122 ( & V_2 -> V_119 ) ;
if ( V_177 ) {
if ( V_2 -> V_120 -> V_61 != V_178 )
return;
F_70 () ;
} else {
if ( V_2 -> V_120 -> V_61 == V_178 )
return;
if ( ! F_123 () ) {
F_60 ( & V_2 -> V_119 ) ;
return;
}
}
F_71 ( V_2 -> V_120 , V_177 ) ;
F_72 () ;
}
static int F_124 ( struct V_179 * V_142 , struct V_38 * V_39 )
{
T_3 * V_180 = ( T_3 * ) V_39 -> V_181 ;
int V_22 ;
if ( V_142 -> V_153 + V_142 -> V_146 > 16 )
return - V_28 ;
for ( V_22 = 0 ; V_22 < V_142 -> V_146 ; ++ V_22 ) {
T_7 V_182 = V_142 -> V_182 [ V_22 ] ;
T_7 V_183 = V_142 -> V_183 [ V_22 ] ;
T_7 V_184 = V_142 -> V_184 [ V_22 ] ;
T_3 V_185 ;
V_182 >>= 16 - V_39 -> V_164 . V_182 . V_186 ;
V_183 >>= 16 - V_39 -> V_164 . V_183 . V_186 ;
V_184 >>= 16 - V_39 -> V_164 . V_184 . V_186 ;
V_185 = ( V_182 << V_39 -> V_164 . V_182 . V_187 ) |
( V_183 << V_39 -> V_164 . V_183 . V_187 ) |
( V_184 << V_39 -> V_164 . V_184 . V_187 ) ;
if ( V_39 -> V_164 . V_188 . V_186 > 0 ) {
T_3 V_189 = ( 1 << V_39 -> V_164 . V_188 . V_186 ) - 1 ;
V_189 <<= V_39 -> V_164 . V_188 . V_187 ;
V_185 |= V_189 ;
}
V_180 [ V_142 -> V_153 + V_22 ] = V_185 ;
}
return 0 ;
}
static int F_125 ( struct V_179 * V_142 , struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_41 ;
struct V_29 * V_30 ;
T_7 * V_190 , * V_191 , * V_192 ;
int V_22 , V_23 = 0 ;
F_43 ( V_2 -> V_19 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_43 ; V_22 ++ ) {
V_30 = V_2 -> V_46 [ V_22 ] . V_45 . V_30 ;
if ( ! V_30 -> V_34 -> V_35 || ! V_30 -> V_37 )
return - V_28 ;
if ( V_142 -> V_153 + V_142 -> V_146 > V_30 -> V_37 )
return - V_28 ;
V_190 = V_30 -> V_36 ;
V_191 = V_190 + V_30 -> V_37 ;
V_192 = V_191 + V_30 -> V_37 ;
memcpy ( V_190 + V_142 -> V_153 , V_142 -> V_182 , V_142 -> V_146 * sizeof( * V_190 ) ) ;
memcpy ( V_191 + V_142 -> V_153 , V_142 -> V_183 , V_142 -> V_146 * sizeof( * V_191 ) ) ;
memcpy ( V_192 + V_142 -> V_153 , V_142 -> V_184 , V_142 -> V_146 * sizeof( * V_192 ) ) ;
V_23 = V_30 -> V_34 -> V_35 ( V_30 , V_190 , V_191 , V_192 ,
V_30 -> V_37 , NULL ) ;
if ( V_23 )
return V_23 ;
}
F_47 ( V_2 -> V_19 ) ;
return V_23 ;
}
static struct V_193 * F_126 ( struct V_29 * V_30 ,
struct V_179 * V_142 )
{
struct V_18 * V_19 = V_30 -> V_19 ;
struct V_193 * V_194 ;
struct V_195 * V_196 ;
int V_13 = V_30 -> V_37 ;
int V_22 ;
if ( ! V_13 || V_142 -> V_153 + V_142 -> V_146 > V_13 )
return F_85 ( - V_28 ) ;
V_194 = F_127 ( V_19 , sizeof( * V_196 ) * V_13 , NULL ) ;
if ( F_29 ( V_194 ) )
return V_194 ;
V_196 = (struct V_195 * ) V_194 -> V_197 ;
if ( V_142 -> V_153 || V_142 -> V_146 != V_13 ) {
T_7 * V_190 = V_30 -> V_36 ;
T_7 * V_191 = V_190 + V_30 -> V_37 ;
T_7 * V_192 = V_191 + V_30 -> V_37 ;
for ( V_22 = 0 ; V_22 < V_142 -> V_153 ; V_22 ++ ) {
V_196 [ V_22 ] . V_182 = V_190 [ V_22 ] ;
V_196 [ V_22 ] . V_183 = V_191 [ V_22 ] ;
V_196 [ V_22 ] . V_184 = V_192 [ V_22 ] ;
}
for ( V_22 = V_142 -> V_153 + V_142 -> V_146 ; V_22 < V_13 ; V_22 ++ ) {
V_196 [ V_22 ] . V_182 = V_190 [ V_22 ] ;
V_196 [ V_22 ] . V_183 = V_191 [ V_22 ] ;
V_196 [ V_22 ] . V_184 = V_192 [ V_22 ] ;
}
}
for ( V_22 = 0 ; V_22 < V_142 -> V_146 ; V_22 ++ ) {
V_196 [ V_142 -> V_153 + V_22 ] . V_182 = V_142 -> V_182 [ V_22 ] ;
V_196 [ V_142 -> V_153 + V_22 ] . V_183 = V_142 -> V_183 [ V_22 ] ;
V_196 [ V_142 -> V_153 + V_22 ] . V_184 = V_142 -> V_184 [ V_22 ] ;
}
return V_194 ;
}
static int F_128 ( struct V_179 * V_142 , struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_41 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_193 * V_194 = NULL ;
struct V_63 V_64 ;
struct V_75 * V_76 ;
struct V_60 * V_61 ;
struct V_29 * V_30 ;
T_7 * V_190 , * V_191 , * V_192 ;
int V_22 , V_23 = 0 ;
bool V_198 ;
F_25 ( & V_64 , 0 ) ;
V_61 = F_26 ( V_19 ) ;
if ( ! V_61 ) {
V_23 = - V_16 ;
goto V_65;
}
V_61 -> V_66 = & V_64 ;
V_67:
for ( V_22 = 0 ; V_22 < V_2 -> V_43 ; V_22 ++ ) {
V_30 = V_2 -> V_46 [ V_22 ] . V_45 . V_30 ;
if ( ! V_194 )
V_194 = F_126 ( V_30 , V_142 ) ;
if ( F_29 ( V_194 ) ) {
V_23 = F_30 ( V_194 ) ;
V_194 = NULL ;
goto V_70;
}
V_76 = F_129 ( V_61 , V_30 ) ;
if ( F_29 ( V_76 ) ) {
V_23 = F_30 ( V_76 ) ;
goto V_70;
}
V_198 = F_130 ( & V_76 -> V_199 ,
NULL ) ;
V_198 |= F_130 ( & V_76 -> V_200 , NULL ) ;
V_198 |= F_130 ( & V_76 -> V_194 ,
V_194 ) ;
V_76 -> V_201 |= V_198 ;
}
V_23 = F_35 ( V_61 ) ;
if ( V_23 )
goto V_70;
for ( V_22 = 0 ; V_22 < V_2 -> V_43 ; V_22 ++ ) {
V_30 = V_2 -> V_46 [ V_22 ] . V_45 . V_30 ;
V_190 = V_30 -> V_36 ;
V_191 = V_190 + V_30 -> V_37 ;
V_192 = V_191 + V_30 -> V_37 ;
memcpy ( V_190 + V_142 -> V_153 , V_142 -> V_182 , V_142 -> V_146 * sizeof( * V_190 ) ) ;
memcpy ( V_191 + V_142 -> V_153 , V_142 -> V_183 , V_142 -> V_146 * sizeof( * V_191 ) ) ;
memcpy ( V_192 + V_142 -> V_153 , V_142 -> V_184 , V_142 -> V_146 * sizeof( * V_192 ) ) ;
}
V_70:
if ( V_23 == - V_77 )
goto V_78;
F_131 ( V_194 ) ;
F_37 ( V_61 ) ;
V_65:
F_38 ( & V_64 ) ;
F_39 ( & V_64 ) ;
return V_23 ;
V_78:
F_40 ( V_61 ) ;
F_41 ( & V_64 ) ;
goto V_67;
}
int F_132 ( struct V_179 * V_142 , struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_41 ;
int V_23 ;
if ( V_104 )
return - V_105 ;
F_7 ( & V_2 -> V_10 ) ;
if ( ! F_52 ( V_2 ) ) {
V_23 = - V_105 ;
goto V_25;
}
if ( V_39 -> V_162 . V_202 == V_203 )
V_23 = F_124 ( V_142 , V_39 ) ;
else if ( F_21 ( V_2 -> V_19 ) )
V_23 = F_128 ( V_142 , V_39 ) ;
else
V_23 = F_125 ( V_142 , V_39 ) ;
V_25:
F_8 ( & V_2 -> V_10 ) ;
return V_23 ;
}
int F_133 ( struct V_38 * V_39 , unsigned int V_204 ,
unsigned long V_205 )
{
struct V_1 * V_2 = V_39 -> V_41 ;
struct V_44 * V_45 ;
struct V_29 * V_30 ;
int V_23 = 0 ;
F_7 ( & V_2 -> V_10 ) ;
if ( ! F_52 ( V_2 ) ) {
V_23 = - V_105 ;
goto V_206;
}
switch ( V_204 ) {
case V_207 :
V_45 = & V_2 -> V_46 [ 0 ] . V_45 ;
V_30 = V_45 -> V_30 ;
V_23 = F_134 ( V_30 ) ;
if ( ! V_23 ) {
F_135 ( V_30 ) ;
F_136 ( V_30 ) ;
}
V_23 = 0 ;
goto V_206;
default:
V_23 = - V_208 ;
}
V_206:
F_8 ( & V_2 -> V_10 ) ;
return V_23 ;
}
int F_137 ( struct V_209 * V_164 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_41 ;
struct V_54 * V_50 = V_2 -> V_50 ;
int V_210 ;
if ( V_164 -> V_211 != 0 || F_138 () )
return - V_28 ;
if ( V_164 -> V_212 != V_50 -> V_213 -> V_214 [ 0 ] * 8 ||
V_164 -> V_166 > V_50 -> V_149 || V_164 -> V_165 > V_50 -> V_150 ||
V_164 -> V_215 > V_50 -> V_149 || V_164 -> V_216 > V_50 -> V_150 ) {
F_139 ( L_3
L_4 ,
V_164 -> V_166 , V_164 -> V_165 , V_164 -> V_212 ,
V_164 -> V_215 , V_164 -> V_216 ,
V_50 -> V_149 , V_50 -> V_150 , V_50 -> V_213 -> V_214 [ 0 ] * 8 ) ;
return - V_28 ;
}
switch ( V_164 -> V_212 ) {
case 16 :
V_210 = ( V_164 -> V_183 . V_186 == 6 ) ? 16 : 15 ;
break;
case 32 :
V_210 = ( V_164 -> V_188 . V_186 > 0 ) ? 32 : 24 ;
break;
default:
V_210 = V_164 -> V_212 ;
break;
}
switch ( V_210 ) {
case 8 :
V_164 -> V_182 . V_187 = 0 ;
V_164 -> V_183 . V_187 = 0 ;
V_164 -> V_184 . V_187 = 0 ;
V_164 -> V_182 . V_186 = 8 ;
V_164 -> V_183 . V_186 = 8 ;
V_164 -> V_184 . V_186 = 8 ;
V_164 -> V_188 . V_186 = 0 ;
V_164 -> V_188 . V_187 = 0 ;
break;
case 15 :
V_164 -> V_182 . V_187 = 10 ;
V_164 -> V_183 . V_187 = 5 ;
V_164 -> V_184 . V_187 = 0 ;
V_164 -> V_182 . V_186 = 5 ;
V_164 -> V_183 . V_186 = 5 ;
V_164 -> V_184 . V_186 = 5 ;
V_164 -> V_188 . V_186 = 1 ;
V_164 -> V_188 . V_187 = 15 ;
break;
case 16 :
V_164 -> V_182 . V_187 = 11 ;
V_164 -> V_183 . V_187 = 5 ;
V_164 -> V_184 . V_187 = 0 ;
V_164 -> V_182 . V_186 = 5 ;
V_164 -> V_183 . V_186 = 6 ;
V_164 -> V_184 . V_186 = 5 ;
V_164 -> V_188 . V_186 = 0 ;
V_164 -> V_188 . V_187 = 0 ;
break;
case 24 :
V_164 -> V_182 . V_187 = 16 ;
V_164 -> V_183 . V_187 = 8 ;
V_164 -> V_184 . V_187 = 0 ;
V_164 -> V_182 . V_186 = 8 ;
V_164 -> V_183 . V_186 = 8 ;
V_164 -> V_184 . V_186 = 8 ;
V_164 -> V_188 . V_186 = 0 ;
V_164 -> V_188 . V_187 = 0 ;
break;
case 32 :
V_164 -> V_182 . V_187 = 16 ;
V_164 -> V_183 . V_187 = 8 ;
V_164 -> V_184 . V_187 = 0 ;
V_164 -> V_182 . V_186 = 8 ;
V_164 -> V_183 . V_186 = 8 ;
V_164 -> V_184 . V_186 = 8 ;
V_164 -> V_188 . V_186 = 8 ;
V_164 -> V_188 . V_187 = 24 ;
break;
default:
return - V_28 ;
}
return 0 ;
}
int F_140 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_41 ;
struct V_209 * V_164 = & V_39 -> V_164 ;
if ( V_104 )
return - V_105 ;
if ( V_164 -> V_211 != 0 ) {
F_23 ( L_5 ) ;
return - V_28 ;
}
F_49 ( V_2 ) ;
return 0 ;
}
static void F_141 ( struct V_1 * V_2 , int V_51 , int V_52 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_43 ; V_22 ++ ) {
struct V_44 * V_45 ;
V_45 = & V_2 -> V_46 [ V_22 ] . V_45 ;
V_45 -> V_51 = V_51 ;
V_45 -> V_52 = V_52 ;
}
}
static int F_142 ( struct V_209 * V_164 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_41 ;
int V_23 ;
F_141 ( V_2 , V_164 -> V_217 , V_164 -> V_218 ) ;
V_23 = F_24 ( V_2 , true ) ;
if ( ! V_23 ) {
V_39 -> V_164 . V_217 = V_164 -> V_217 ;
V_39 -> V_164 . V_218 = V_164 -> V_218 ;
} else
F_141 ( V_2 , V_39 -> V_164 . V_217 , V_39 -> V_164 . V_218 ) ;
return V_23 ;
}
static int F_143 ( struct V_209 * V_164 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_41 ;
struct V_44 * V_114 ;
int V_23 = 0 ;
int V_22 ;
F_43 ( V_2 -> V_19 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_43 ; V_22 ++ ) {
V_114 = & V_2 -> V_46 [ V_22 ] . V_45 ;
V_114 -> V_51 = V_164 -> V_217 ;
V_114 -> V_52 = V_164 -> V_218 ;
if ( V_114 -> V_115 ) {
V_23 = F_46 ( V_114 ) ;
if ( ! V_23 ) {
V_39 -> V_164 . V_217 = V_164 -> V_217 ;
V_39 -> V_164 . V_218 = V_164 -> V_218 ;
}
}
}
F_47 ( V_2 -> V_19 ) ;
return V_23 ;
}
int F_144 ( struct V_209 * V_164 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_41 ;
struct V_18 * V_19 = V_2 -> V_19 ;
int V_23 ;
if ( V_104 )
return - V_105 ;
F_7 ( & V_2 -> V_10 ) ;
if ( ! F_52 ( V_2 ) ) {
F_8 ( & V_2 -> V_10 ) ;
return - V_105 ;
}
if ( F_21 ( V_19 ) )
V_23 = F_142 ( V_164 , V_39 ) ;
else
V_23 = F_143 ( V_164 , V_39 ) ;
F_8 ( & V_2 -> V_10 ) ;
return V_23 ;
}
static int F_145 ( struct V_1 * V_2 ,
int V_219 )
{
int V_23 = 0 ;
int V_43 = 0 ;
int V_22 ;
struct V_220 V_221 ;
int V_37 = 0 ;
memset ( & V_221 , 0 , sizeof( struct V_220 ) ) ;
V_221 . V_222 = 24 ;
V_221 . V_223 = 32 ;
V_221 . V_224 = ( T_3 ) - 1 ;
V_221 . V_225 = ( T_3 ) - 1 ;
if ( V_219 != V_221 . V_223 )
V_221 . V_222 = V_221 . V_223 = V_219 ;
F_12 (fb_helper, i) {
struct V_5 * V_226 = V_2 -> V_14 [ V_22 ] ;
struct V_227 * V_228 ;
V_228 = & V_226 -> V_4 -> V_228 ;
if ( V_228 -> V_229 ) {
switch ( V_228 -> V_230 ) {
case 8 :
V_221 . V_222 = V_221 . V_223 = 8 ;
break;
case 15 :
V_221 . V_222 = 15 ;
V_221 . V_223 = 16 ;
break;
case 16 :
V_221 . V_222 = V_221 . V_223 = 16 ;
break;
case 24 :
V_221 . V_222 = V_221 . V_223 = 24 ;
break;
case 32 :
V_221 . V_222 = 24 ;
V_221 . V_223 = 32 ;
break;
}
break;
}
}
V_43 = 0 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_43 ; V_22 ++ ) {
struct V_231 * V_232 ;
struct V_44 * V_45 ;
int V_51 , V_52 , V_27 ;
bool V_233 = true , V_234 = true ;
V_232 = V_2 -> V_46 [ V_22 ] . V_232 ;
V_45 = & V_2 -> V_46 [ V_22 ] . V_45 ;
if ( ! V_232 )
continue;
V_43 ++ ;
V_51 = V_2 -> V_46 [ V_22 ] . V_51 ;
V_52 = V_2 -> V_46 [ V_22 ] . V_52 ;
if ( V_37 == 0 )
V_37 = V_2 -> V_46 [ V_22 ] . V_45 . V_30 -> V_37 ;
V_221 . V_235 = F_101 ( T_3 , V_232 -> V_236 + V_51 , V_221 . V_235 ) ;
V_221 . V_237 = F_101 ( T_3 , V_232 -> V_238 + V_52 , V_221 . V_237 ) ;
for ( V_27 = 0 ; V_27 < V_45 -> V_115 ; V_27 ++ ) {
struct V_3 * V_4 = V_45 -> V_116 [ V_27 ] ;
if ( V_4 -> V_239 ) {
V_234 = ( V_4 -> V_240 == ( V_4 -> V_241 - 1 ) ) ;
V_233 = ( V_4 -> V_242 == ( V_4 -> V_243 - 1 ) ) ;
break;
}
}
if ( V_234 )
V_221 . V_224 = F_100 ( T_3 , V_232 -> V_236 + V_51 , V_221 . V_224 ) ;
if ( V_233 )
V_221 . V_225 = F_100 ( T_3 , V_232 -> V_238 + V_52 , V_221 . V_225 ) ;
}
if ( V_43 == 0 || V_221 . V_224 == - 1 || V_221 . V_225 == - 1 ) {
F_146 ( L_6 ) ;
return - V_244 ;
}
V_221 . V_237 *= V_245 ;
V_221 . V_237 /= 100 ;
V_23 = (* V_2 -> V_34 -> V_246 )( V_2 , & V_221 ) ;
if ( V_23 < 0 )
return V_23 ;
return 0 ;
}
void F_147 ( struct V_38 * V_39 , T_8 V_247 ,
T_8 V_210 )
{
V_39 -> V_162 . type = V_248 ;
V_39 -> V_162 . V_202 = V_210 == 8 ? V_249 :
V_203 ;
V_39 -> V_162 . V_250 = 0 ;
V_39 -> V_162 . V_251 = 0 ;
V_39 -> V_162 . V_252 = 0 ;
V_39 -> V_162 . V_253 = 1 ;
V_39 -> V_162 . V_254 = 1 ;
V_39 -> V_162 . V_255 = 0 ;
V_39 -> V_162 . V_256 = V_257 ;
V_39 -> V_162 . V_163 = V_247 ;
}
void F_148 ( struct V_38 * V_39 , struct V_1 * V_2 ,
T_8 V_224 , T_8 V_225 )
{
struct V_54 * V_50 = V_2 -> V_50 ;
V_39 -> V_181 = V_2 -> V_181 ;
V_39 -> V_164 . V_215 = V_50 -> V_149 ;
V_39 -> V_164 . V_216 = V_50 -> V_150 ;
V_39 -> V_164 . V_212 = V_50 -> V_213 -> V_214 [ 0 ] * 8 ;
V_39 -> V_164 . V_258 = V_259 ;
V_39 -> V_164 . V_217 = 0 ;
V_39 -> V_164 . V_218 = 0 ;
V_39 -> V_164 . V_260 = V_261 ;
switch ( V_50 -> V_213 -> V_210 ) {
case 8 :
V_39 -> V_164 . V_182 . V_187 = 0 ;
V_39 -> V_164 . V_183 . V_187 = 0 ;
V_39 -> V_164 . V_184 . V_187 = 0 ;
V_39 -> V_164 . V_182 . V_186 = 8 ;
V_39 -> V_164 . V_183 . V_186 = 8 ;
V_39 -> V_164 . V_184 . V_186 = 8 ;
V_39 -> V_164 . V_188 . V_187 = 0 ;
V_39 -> V_164 . V_188 . V_186 = 0 ;
break;
case 15 :
V_39 -> V_164 . V_182 . V_187 = 10 ;
V_39 -> V_164 . V_183 . V_187 = 5 ;
V_39 -> V_164 . V_184 . V_187 = 0 ;
V_39 -> V_164 . V_182 . V_186 = 5 ;
V_39 -> V_164 . V_183 . V_186 = 5 ;
V_39 -> V_164 . V_184 . V_186 = 5 ;
V_39 -> V_164 . V_188 . V_187 = 15 ;
V_39 -> V_164 . V_188 . V_186 = 1 ;
break;
case 16 :
V_39 -> V_164 . V_182 . V_187 = 11 ;
V_39 -> V_164 . V_183 . V_187 = 5 ;
V_39 -> V_164 . V_184 . V_187 = 0 ;
V_39 -> V_164 . V_182 . V_186 = 5 ;
V_39 -> V_164 . V_183 . V_186 = 6 ;
V_39 -> V_164 . V_184 . V_186 = 5 ;
V_39 -> V_164 . V_188 . V_187 = 0 ;
break;
case 24 :
V_39 -> V_164 . V_182 . V_187 = 16 ;
V_39 -> V_164 . V_183 . V_187 = 8 ;
V_39 -> V_164 . V_184 . V_187 = 0 ;
V_39 -> V_164 . V_182 . V_186 = 8 ;
V_39 -> V_164 . V_183 . V_186 = 8 ;
V_39 -> V_164 . V_184 . V_186 = 8 ;
V_39 -> V_164 . V_188 . V_187 = 0 ;
V_39 -> V_164 . V_188 . V_186 = 0 ;
break;
case 32 :
V_39 -> V_164 . V_182 . V_187 = 16 ;
V_39 -> V_164 . V_183 . V_187 = 8 ;
V_39 -> V_164 . V_184 . V_187 = 0 ;
V_39 -> V_164 . V_182 . V_186 = 8 ;
V_39 -> V_164 . V_183 . V_186 = 8 ;
V_39 -> V_164 . V_184 . V_186 = 8 ;
V_39 -> V_164 . V_188 . V_187 = 24 ;
V_39 -> V_164 . V_188 . V_186 = 8 ;
break;
default:
break;
}
V_39 -> V_164 . V_166 = V_224 ;
V_39 -> V_164 . V_165 = V_225 ;
}
static int F_149 ( struct V_1 * V_2 ,
T_8 V_262 ,
T_8 V_263 )
{
struct V_3 * V_4 ;
int V_22 , V_8 = 0 ;
F_12 (fb_helper, i) {
V_4 = V_2 -> V_14 [ V_22 ] -> V_4 ;
V_8 += V_4 -> V_34 -> V_264 ( V_4 , V_262 , V_263 ) ;
}
return V_8 ;
}
struct V_231 * F_150 ( struct V_5 * V_265 , int V_149 , int V_150 )
{
struct V_231 * V_117 ;
F_20 (mode, &fb_connector->connector->modes, head) {
if ( V_117 -> V_236 > V_149 ||
V_117 -> V_238 > V_150 )
continue;
if ( V_117 -> type & V_266 )
return V_117 ;
}
return NULL ;
}
static bool F_151 ( struct V_5 * V_265 )
{
return V_265 -> V_4 -> V_228 . V_267 ;
}
struct V_231 * F_152 ( struct V_5 * V_226 )
{
struct V_227 * V_228 ;
struct V_231 * V_117 ;
bool V_268 ;
V_228 = & V_226 -> V_4 -> V_228 ;
if ( V_228 -> V_267 == false )
return NULL ;
if ( V_228 -> V_269 || V_228 -> V_270 )
goto V_271;
V_268 = ! V_228 -> V_272 ;
V_273:
F_20 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_117 -> V_236 != V_228 -> V_166 ||
V_117 -> V_238 != V_228 -> V_165 )
continue;
if ( V_228 -> V_274 ) {
if ( V_117 -> V_275 != V_228 -> V_276 )
continue;
}
if ( V_228 -> V_272 ) {
if ( ! ( V_117 -> V_126 & V_277 ) )
continue;
} else if ( V_268 ) {
if ( V_117 -> V_126 & V_277 )
continue;
}
return V_117 ;
}
if ( V_268 ) {
V_268 = false ;
goto V_273;
}
V_271:
V_117 = F_153 ( V_226 -> V_4 -> V_19 ,
V_228 ) ;
F_154 ( & V_117 -> V_278 , & V_226 -> V_4 -> V_279 ) ;
return V_117 ;
}
static bool F_155 ( struct V_3 * V_4 , bool V_280 )
{
bool V_281 ;
if ( V_280 )
V_281 = V_4 -> V_282 == V_283 ;
else
V_281 = V_4 -> V_282 != V_284 ;
return V_281 ;
}
static void F_156 ( struct V_1 * V_2 ,
bool * V_47 )
{
bool V_285 = false ;
struct V_3 * V_4 ;
int V_22 = 0 ;
F_12 (fb_helper, i) {
V_4 = V_2 -> V_14 [ V_22 ] -> V_4 ;
V_47 [ V_22 ] = F_155 ( V_4 , true ) ;
F_157 ( L_7 , V_4 -> V_99 . V_286 ,
V_47 [ V_22 ] ? L_8 : L_9 ) ;
V_285 |= V_47 [ V_22 ] ;
}
if ( V_285 )
return;
F_12 (fb_helper, i) {
V_4 = V_2 -> V_14 [ V_22 ] -> V_4 ;
V_47 [ V_22 ] = F_155 ( V_4 , false ) ;
}
}
static bool F_158 ( struct V_1 * V_2 ,
struct V_231 * * V_279 ,
struct V_287 * V_288 ,
bool * V_47 , int V_149 , int V_150 )
{
int V_8 , V_22 , V_27 ;
bool V_289 = false ;
struct V_5 * V_226 ;
struct V_231 * V_290 , * V_117 ;
if ( V_2 -> V_43 > 1 )
return false ;
V_8 = 0 ;
F_12 (fb_helper, i) {
if ( V_47 [ V_22 ] )
V_8 ++ ;
}
if ( V_8 <= 1 )
return false ;
V_289 = true ;
F_12 (fb_helper, i) {
if ( ! V_47 [ V_22 ] )
continue;
V_226 = V_2 -> V_14 [ V_22 ] ;
V_279 [ V_22 ] = F_152 ( V_226 ) ;
if ( ! V_279 [ V_22 ] ) {
V_289 = false ;
break;
}
for ( V_27 = 0 ; V_27 < V_22 ; V_27 ++ ) {
if ( ! V_47 [ V_27 ] )
continue;
if ( ! F_159 ( V_279 [ V_27 ] , V_279 [ V_22 ] ) )
V_289 = false ;
}
}
if ( V_289 ) {
F_157 ( L_10 ) ;
return true ;
}
V_289 = true ;
V_290 = F_160 ( V_2 -> V_19 , 1024 , 768 , 60 , false ) ;
F_12 (fb_helper, i) {
if ( ! V_47 [ V_22 ] )
continue;
V_226 = V_2 -> V_14 [ V_22 ] ;
F_20 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_159 ( V_117 , V_290 ) )
V_279 [ V_22 ] = V_117 ;
}
if ( ! V_279 [ V_22 ] )
V_289 = false ;
}
if ( V_289 ) {
F_157 ( L_11 ) ;
return true ;
}
F_146 ( L_12 ) ;
return false ;
}
static int F_161 ( struct V_1 * V_2 ,
struct V_231 * * V_279 ,
struct V_287 * V_288 ,
int V_291 ,
int V_292 , int V_293 )
{
struct V_5 * V_226 ;
int V_22 ;
int V_294 = 0 , V_295 = 0 ;
F_12 (fb_helper, i) {
V_226 = V_2 -> V_14 [ V_22 ] ;
if ( ! V_226 -> V_4 -> V_239 )
continue;
if ( ! V_279 [ V_22 ] && ( V_292 || V_293 ) ) {
F_157 ( L_13 , V_22 ,
V_226 -> V_4 -> V_99 . V_286 ) ;
continue;
}
if ( V_226 -> V_4 -> V_240 < V_292 )
V_294 += V_279 [ V_22 ] -> V_236 ;
if ( V_226 -> V_4 -> V_242 < V_293 )
V_295 += V_279 [ V_22 ] -> V_238 ;
}
V_288 [ V_291 ] . V_51 = V_294 ;
V_288 [ V_291 ] . V_52 = V_295 ;
F_157 ( L_14 , V_294 , V_295 , V_292 , V_293 ) ;
return 0 ;
}
static bool F_162 ( struct V_1 * V_2 ,
struct V_231 * * V_279 ,
struct V_287 * V_288 ,
bool * V_47 , int V_149 , int V_150 )
{
struct V_5 * V_226 ;
const T_9 V_189 = F_163 ( V_2 -> V_11 ) - 1 ;
T_9 V_296 = 0 ;
int V_297 = 0 ;
int V_22 ;
V_67:
F_12 (fb_helper, i) {
V_226 = V_2 -> V_14 [ V_22 ] ;
if ( V_296 & F_163 ( V_22 ) )
continue;
if ( V_47 [ V_22 ] == false ) {
V_296 |= F_163 ( V_22 ) ;
continue;
}
if ( V_297 == 0 && V_226 -> V_4 -> V_239 )
continue;
if ( V_297 == 1 ) {
if ( V_226 -> V_4 -> V_240 != 0 ||
V_226 -> V_4 -> V_242 != 0 )
continue;
} else {
if ( V_226 -> V_4 -> V_240 != V_297 - 1 &&
V_226 -> V_4 -> V_242 != V_297 - 1 )
continue;
F_161 ( V_2 , V_279 , V_288 ,
V_22 , V_226 -> V_4 -> V_240 , V_226 -> V_4 -> V_242 ) ;
}
F_157 ( L_15 ,
V_226 -> V_4 -> V_99 . V_286 ) ;
V_279 [ V_22 ] = F_152 ( V_226 ) ;
if ( ! V_279 [ V_22 ] ) {
F_157 ( L_16 ,
V_226 -> V_4 -> V_99 . V_286 , V_226 -> V_4 -> V_298 ? V_226 -> V_4 -> V_298 -> V_286 : 0 ) ;
V_279 [ V_22 ] = F_150 ( V_226 , V_149 , V_150 ) ;
}
if ( ! V_279 [ V_22 ] && ! F_57 ( & V_226 -> V_4 -> V_279 ) ) {
F_20 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_157 ( L_17 , V_279 [ V_22 ] ? V_279 [ V_22 ] -> V_299 :
L_18 ) ;
V_296 |= F_163 ( V_22 ) ;
}
if ( ( V_296 & V_189 ) != V_189 ) {
V_297 ++ ;
goto V_67;
}
return true ;
}
static int F_164 ( struct V_1 * V_2 ,
struct V_138 * * V_300 ,
struct V_231 * * V_279 ,
int V_301 , int V_149 , int V_150 )
{
int V_302 , V_303 ;
struct V_3 * V_4 ;
const struct V_304 * V_305 ;
struct V_306 * V_307 ;
int V_308 , V_309 , V_310 ;
struct V_138 * * V_311 , * V_30 ;
struct V_5 * V_226 ;
if ( V_301 == V_2 -> V_11 )
return 0 ;
V_226 = V_2 -> V_14 [ V_301 ] ;
V_4 = V_226 -> V_4 ;
V_300 [ V_301 ] = NULL ;
V_309 = F_164 ( V_2 , V_300 , V_279 , V_301 + 1 , V_149 , V_150 ) ;
if ( V_279 [ V_301 ] == NULL )
return V_309 ;
V_311 = F_4 ( V_2 -> V_11 *
sizeof( struct V_138 * ) , V_15 ) ;
if ( ! V_311 )
return V_309 ;
V_308 = 1 ;
if ( V_4 -> V_282 == V_283 )
V_308 ++ ;
if ( F_151 ( V_226 ) )
V_308 ++ ;
if ( F_150 ( V_226 , V_149 , V_150 ) )
V_308 ++ ;
V_305 = V_4 -> V_48 ;
if ( F_21 ( V_2 -> V_19 ) &&
! V_305 -> V_312 )
V_307 = F_165 ( V_4 ) ;
else
V_307 = V_305 -> V_312 ( V_4 ) ;
if ( ! V_307 )
goto V_25;
for ( V_302 = 0 ; V_302 < V_2 -> V_43 ; V_302 ++ ) {
V_30 = & V_2 -> V_46 [ V_302 ] ;
if ( ( V_307 -> V_313 & ( 1 << V_302 ) ) == 0 )
continue;
for ( V_303 = 0 ; V_303 < V_301 ; V_303 ++ )
if ( V_300 [ V_303 ] == V_30 )
break;
if ( V_303 < V_301 ) {
if ( V_2 -> V_43 > 1 )
continue;
if ( ! F_159 ( V_279 [ V_303 ] , V_279 [ V_301 ] ) )
continue;
}
V_311 [ V_301 ] = V_30 ;
memcpy ( V_311 , V_300 , V_301 * sizeof( struct V_138 * ) ) ;
V_310 = V_308 + F_164 ( V_2 , V_311 , V_279 , V_301 + 1 ,
V_149 , V_150 ) ;
if ( V_310 > V_309 ) {
V_309 = V_310 ;
memcpy ( V_300 , V_311 ,
V_2 -> V_11 *
sizeof( struct V_138 * ) ) ;
}
}
V_25:
F_14 ( V_311 ) ;
return V_309 ;
}
static void F_166 ( struct V_1 * V_2 ,
T_3 V_149 , T_3 V_150 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_138 * * V_311 ;
struct V_231 * * V_279 ;
struct V_287 * V_288 ;
bool * V_47 ;
int V_22 ;
F_157 ( L_19 ) ;
F_2 ( & V_2 -> V_10 ) ;
V_311 = F_82 ( V_2 -> V_11 ,
sizeof( struct V_138 * ) , V_15 ) ;
V_279 = F_82 ( V_2 -> V_11 ,
sizeof( struct V_231 * ) , V_15 ) ;
V_288 = F_82 ( V_2 -> V_11 ,
sizeof( struct V_287 ) , V_15 ) ;
V_47 = F_82 ( V_2 -> V_11 ,
sizeof( bool ) , V_15 ) ;
if ( ! V_311 || ! V_279 || ! V_47 || ! V_288 ) {
F_23 ( L_20 ) ;
goto V_25;
}
F_7 ( & V_2 -> V_19 -> V_100 . V_89 ) ;
if ( F_149 ( V_2 , V_149 , V_150 ) == 0 )
F_157 ( L_21 ) ;
F_156 ( V_2 , V_47 ) ;
if ( ! ( V_2 -> V_34 -> V_314 &&
V_2 -> V_34 -> V_314 ( V_2 , V_311 , V_279 ,
V_288 ,
V_47 , V_149 , V_150 ) ) ) {
memset ( V_279 , 0 , V_2 -> V_11 * sizeof( V_279 [ 0 ] ) ) ;
memset ( V_311 , 0 , V_2 -> V_11 * sizeof( V_311 [ 0 ] ) ) ;
memset ( V_288 , 0 , V_2 -> V_11 * sizeof( V_288 [ 0 ] ) ) ;
if ( ! F_158 ( V_2 , V_279 , V_288 ,
V_47 , V_149 , V_150 ) &&
! F_162 ( V_2 , V_279 , V_288 ,
V_47 , V_149 , V_150 ) )
F_23 ( L_22 ) ;
F_157 ( L_23 ,
V_149 , V_150 ) ;
F_164 ( V_2 , V_311 , V_279 , 0 , V_149 , V_150 ) ;
}
F_8 ( & V_2 -> V_19 -> V_100 . V_89 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_43 ; V_22 ++ )
F_65 ( V_2 ,
& V_2 -> V_46 [ V_22 ] . V_45 ) ;
F_12 (fb_helper, i) {
struct V_231 * V_117 = V_279 [ V_22 ] ;
struct V_138 * V_315 = V_311 [ V_22 ] ;
struct V_287 * V_187 = & V_288 [ V_22 ] ;
if ( V_117 && V_315 ) {
struct V_44 * V_114 = & V_315 -> V_45 ;
struct V_3 * V_4 =
V_2 -> V_14 [ V_22 ] -> V_4 ;
F_157 ( L_24 ,
V_117 -> V_299 , V_315 -> V_45 . V_30 -> V_99 . V_286 , V_187 -> V_51 , V_187 -> V_52 ) ;
V_315 -> V_232 = V_117 ;
V_315 -> V_51 = V_187 -> V_51 ;
V_315 -> V_52 = V_187 -> V_52 ;
V_114 -> V_117 = F_167 ( V_19 ,
V_315 -> V_232 ) ;
F_5 ( V_4 ) ;
V_114 -> V_116 [ V_114 -> V_115 ++ ] = V_4 ;
V_114 -> V_51 = V_187 -> V_51 ;
V_114 -> V_52 = V_187 -> V_52 ;
}
}
V_25:
F_14 ( V_311 ) ;
F_14 ( V_279 ) ;
F_14 ( V_288 ) ;
F_14 ( V_47 ) ;
}
static void F_168 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_120 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_43 ; V_22 ++ )
if ( V_2 -> V_46 [ V_22 ] . V_45 . V_115 )
V_2 -> V_46 [ V_22 ] . V_45 . V_50 = V_2 -> V_50 ;
F_7 ( & V_2 -> V_19 -> V_100 . V_89 ) ;
F_12 (fb_helper, i) {
struct V_3 * V_4 =
V_2 -> V_14 [ V_22 ] -> V_4 ;
if ( V_4 -> V_282 == V_283 ) {
V_39 -> V_164 . V_149 = V_4 -> V_316 . V_317 ;
V_39 -> V_164 . V_150 = V_4 -> V_316 . V_318 ;
break;
}
}
F_8 ( & V_2 -> V_19 -> V_100 . V_89 ) ;
}
static int
F_169 ( struct V_1 * V_2 ,
int V_319 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_38 * V_39 ;
unsigned int V_149 , V_150 ;
int V_23 ;
V_149 = V_19 -> V_100 . V_320 ;
V_150 = V_19 -> V_100 . V_321 ;
F_166 ( V_2 , V_149 , V_150 ) ;
V_23 = F_145 ( V_2 , V_319 ) ;
if ( V_23 < 0 ) {
if ( V_23 == - V_244 ) {
V_2 -> V_219 = V_319 ;
V_2 -> V_84 = true ;
V_23 = 0 ;
}
F_8 ( & V_2 -> V_10 ) ;
return V_23 ;
}
F_168 ( V_2 ) ;
V_2 -> V_84 = false ;
V_39 = V_2 -> V_120 ;
V_39 -> V_164 . V_211 = 0 ;
F_8 ( & V_2 -> V_10 ) ;
V_23 = F_170 ( V_39 ) ;
if ( V_23 < 0 )
return V_23 ;
F_171 ( V_19 -> V_19 , L_25 ,
V_39 -> V_322 , V_39 -> V_162 . V_286 ) ;
F_7 ( & V_147 ) ;
if ( F_57 ( & V_90 ) )
F_172 ( 'v' , & V_148 ) ;
F_154 ( & V_2 -> V_133 , & V_90 ) ;
F_8 ( & V_147 ) ;
return 0 ;
}
int F_173 ( struct V_1 * V_2 , int V_319 )
{
int V_23 ;
if ( ! V_9 )
return 0 ;
F_7 ( & V_2 -> V_10 ) ;
V_23 = F_169 ( V_2 , V_319 ) ;
return V_23 ;
}
int F_51 ( struct V_1 * V_2 )
{
int V_17 = 0 ;
if ( ! V_9 )
return 0 ;
F_7 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_84 ) {
V_17 = F_169 ( V_2 ,
V_2 -> V_219 ) ;
return V_17 ;
}
if ( ! V_2 -> V_50 || ! F_52 ( V_2 ) ) {
V_2 -> V_85 = true ;
F_8 ( & V_2 -> V_10 ) ;
return V_17 ;
}
F_157 ( L_19 ) ;
F_166 ( V_2 , V_2 -> V_50 -> V_149 , V_2 -> V_50 -> V_150 ) ;
F_168 ( V_2 ) ;
F_8 ( & V_2 -> V_10 ) ;
F_140 ( V_2 -> V_120 ) ;
return 0 ;
}
int T_10 F_174 ( void )
{
#if F_175 ( V_323 ) && ! F_175 ( V_324 )
const char V_299 [] = L_26 ;
struct V_325 * V_326 ;
F_7 ( & V_327 ) ;
V_326 = F_176 ( V_299 ) ;
F_8 ( & V_327 ) ;
if ( ! V_326 )
F_177 ( V_299 ) ;
#endif
return 0 ;
}
