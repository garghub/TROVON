int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
int V_7 , V_8 ;
if ( ! V_9 )
return 0 ;
F_2 ( & V_4 -> V_10 . V_11 ) ;
F_3 (connector, dev) {
V_8 = F_4 ( V_2 , V_6 ) ;
if ( V_8 )
goto V_12;
}
F_5 ( & V_4 -> V_10 . V_11 ) ;
return 0 ;
V_12:
F_6 (fb_helper, i) {
struct V_13 * V_14 =
V_2 -> V_15 [ V_7 ] ;
F_7 ( V_14 -> V_6 ) ;
F_8 ( V_14 ) ;
V_2 -> V_15 [ V_7 ] = NULL ;
}
V_2 -> V_16 = 0 ;
F_5 ( & V_4 -> V_10 . V_11 ) ;
return V_8 ;
}
int F_4 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_13 * * V_17 ;
struct V_13 * V_14 ;
if ( ! V_9 )
return 0 ;
F_9 ( ! F_10 ( & V_2 -> V_4 -> V_10 . V_11 ) ) ;
if ( V_2 -> V_16 + 1 > V_2 -> V_18 ) {
V_17 = F_11 ( V_2 -> V_15 , sizeof( struct V_13 * ) * ( V_2 -> V_16 + 1 ) , V_19 ) ;
if ( ! V_17 )
return - V_20 ;
V_2 -> V_18 = V_2 -> V_16 + 1 ;
V_2 -> V_15 = V_17 ;
}
V_14 = F_12 ( sizeof( struct V_13 ) , V_19 ) ;
if ( ! V_14 )
return - V_20 ;
F_13 ( V_6 ) ;
V_14 -> V_6 = V_6 ;
V_2 -> V_15 [ V_2 -> V_16 ++ ] = V_14 ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_13 * V_14 ;
int V_7 , V_21 ;
if ( ! V_9 )
return 0 ;
F_9 ( ! F_10 ( & V_2 -> V_4 -> V_10 . V_11 ) ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_16 ; V_7 ++ ) {
if ( V_2 -> V_15 [ V_7 ] -> V_6 == V_6 )
break;
}
if ( V_7 == V_2 -> V_16 )
return - V_22 ;
V_14 = V_2 -> V_15 [ V_7 ] ;
F_7 ( V_14 -> V_6 ) ;
for ( V_21 = V_7 + 1 ; V_21 < V_2 -> V_16 ; V_21 ++ ) {
V_2 -> V_15 [ V_21 - 1 ] = V_2 -> V_15 [ V_21 ] ;
}
V_2 -> V_16 -- ;
F_8 ( V_14 ) ;
return 0 ;
}
static void F_15 ( struct V_23 * V_24 , struct V_1 * V_25 )
{
T_1 * V_26 , * V_27 , * V_28 ;
int V_7 ;
if ( V_25 -> V_29 -> V_30 == NULL )
return;
V_26 = V_24 -> V_31 ;
V_27 = V_26 + V_24 -> V_32 ;
V_28 = V_27 + V_24 -> V_32 ;
for ( V_7 = 0 ; V_7 < V_24 -> V_32 ; V_7 ++ )
V_25 -> V_29 -> V_30 ( V_24 , & V_26 [ V_7 ] , & V_27 [ V_7 ] , & V_28 [ V_7 ] , V_7 ) ;
}
static void F_16 ( struct V_23 * V_24 )
{
T_1 * V_26 , * V_27 , * V_28 ;
if ( V_24 -> V_29 -> V_33 == NULL )
return;
V_26 = V_24 -> V_31 ;
V_27 = V_26 + V_24 -> V_32 ;
V_28 = V_27 + V_24 -> V_32 ;
V_24 -> V_29 -> V_33 ( V_24 , V_26 , V_27 , V_28 , V_24 -> V_32 ) ;
}
int F_17 ( struct V_34 * V_35 )
{
struct V_1 * V_25 = V_35 -> V_36 ;
const struct V_37 * V_29 ;
int V_7 ;
F_18 (helper, &kernel_fb_helper_list, kernel_fb_list) {
for ( V_7 = 0 ; V_7 < V_25 -> V_38 ; V_7 ++ ) {
struct V_39 * V_40 =
& V_25 -> V_41 [ V_7 ] . V_40 ;
if ( ! V_40 -> V_24 -> V_42 )
continue;
V_29 = V_40 -> V_24 -> V_43 ;
if ( V_29 -> V_44 == NULL )
continue;
F_15 ( V_40 -> V_24 , V_25 ) ;
V_29 -> V_44 ( V_40 -> V_24 ,
V_40 -> V_45 ,
V_40 -> V_46 ,
V_40 -> V_47 ,
V_48 ) ;
}
}
return 0 ;
}
static struct V_49 * F_19 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_4 ;
struct V_23 * V_50 ;
F_20 (c, dev) {
if ( V_24 -> V_51 . V_52 == V_50 -> V_51 . V_52 )
return V_50 -> V_53 -> V_45 ;
}
return NULL ;
}
int F_21 ( struct V_34 * V_35 )
{
struct V_1 * V_25 = V_35 -> V_36 ;
struct V_23 * V_24 ;
const struct V_37 * V_29 ;
struct V_49 * V_45 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_25 -> V_38 ; V_7 ++ ) {
struct V_39 * V_40 = & V_25 -> V_41 [ V_7 ] . V_40 ;
V_24 = V_40 -> V_24 ;
V_29 = V_24 -> V_43 ;
V_45 = F_19 ( V_24 ) ;
if ( ! V_24 -> V_42 )
continue;
if ( ! V_45 ) {
F_22 ( L_1 ) ;
continue;
}
if ( V_29 -> V_44 == NULL )
continue;
F_16 ( V_40 -> V_24 ) ;
V_29 -> V_44 ( V_40 -> V_24 , V_45 , V_24 -> V_46 ,
V_24 -> V_47 , V_54 ) ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
int V_7 , V_8 ;
unsigned V_59 ;
V_58 = F_24 ( V_4 ) ;
if ( ! V_58 )
return - V_20 ;
V_58 -> V_60 = V_4 -> V_10 . V_60 ;
V_61:
V_59 = 0 ;
F_25 (plane, dev) {
struct V_62 * V_63 ;
V_63 = F_26 ( V_58 , V_56 ) ;
if ( F_27 ( V_63 ) ) {
V_8 = F_28 ( V_63 ) ;
goto V_12;
}
V_63 -> V_64 = V_65 ;
V_56 -> V_66 = V_56 -> V_45 ;
V_59 |= 1 << F_29 ( V_56 ) ;
if ( V_56 -> type == V_67 )
continue;
V_8 = F_30 ( V_56 , V_63 ) ;
if ( V_8 != 0 )
goto V_12;
}
for( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
struct V_39 * V_40 = & V_2 -> V_41 [ V_7 ] . V_40 ;
V_8 = F_31 ( V_40 , V_58 ) ;
if ( V_8 != 0 )
goto V_12;
}
V_8 = F_32 ( V_58 ) ;
V_12:
F_33 ( V_4 , V_59 , V_8 ) ;
if ( V_8 == - V_68 )
goto V_69;
F_34 ( V_58 ) ;
return V_8 ;
V_69:
F_35 ( V_58 ) ;
F_36 ( V_58 ) ;
goto V_61;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_55 * V_56 ;
int V_7 ;
F_38 ( V_4 ) ;
if ( V_4 -> V_10 . V_29 -> V_70 )
return F_23 ( V_2 ) ;
F_25 (plane, dev) {
if ( V_56 -> type != V_67 )
F_39 ( V_56 ) ;
if ( V_56 -> V_71 )
F_40 ( V_56 ,
V_56 -> V_71 ,
V_65 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
struct V_39 * V_40 = & V_2 -> V_41 [ V_7 ] . V_40 ;
struct V_23 * V_24 = V_40 -> V_24 ;
int V_8 ;
if ( V_24 -> V_29 -> V_72 ) {
V_8 = V_24 -> V_29 -> V_72 ( V_24 , NULL , 0 , 0 , 0 , 0 , 0 ) ;
if ( V_8 )
return V_8 ;
} else if ( V_24 -> V_29 -> V_73 ) {
V_8 = V_24 -> V_29 -> V_73 ( V_24 , NULL , 0 , 0 , 0 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_41 ( V_40 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
int F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_74 ;
int V_8 ;
if ( ! V_9 )
return - V_75 ;
F_43 ( V_4 ) ;
V_8 = F_37 ( V_2 ) ;
V_74 = V_2 -> V_76 ;
if ( V_74 )
V_2 -> V_76 = false ;
F_44 ( V_4 ) ;
if ( V_74 )
F_45 ( V_2 ) ;
return V_8 ;
}
static bool F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 ;
int V_77 = 0 , V_78 = 0 ;
if ( F_47 ( V_4 -> V_79 ) )
return false ;
F_20 (crtc, dev) {
if ( V_24 -> V_53 -> V_45 )
V_78 ++ ;
if ( V_24 -> V_53 -> V_45 == V_2 -> V_45 )
V_77 ++ ;
}
if ( V_77 < V_78 )
return false ;
return true ;
}
static bool F_48 ( void )
{
bool V_8 , error = false ;
struct V_1 * V_25 ;
if ( F_49 ( & V_80 ) )
return false ;
F_18 (helper, &kernel_fb_helper_list, kernel_fb_list) {
struct V_3 * V_4 = V_25 -> V_4 ;
if ( V_4 -> V_81 == V_82 )
continue;
F_43 ( V_4 ) ;
V_8 = F_37 ( V_25 ) ;
if ( V_8 )
error = true ;
F_44 ( V_4 ) ;
}
return error ;
}
static void F_50 ( struct V_83 * V_84 )
{
bool V_8 ;
V_8 = F_48 () ;
if ( V_8 == true )
F_22 ( L_2 ) ;
}
static void F_51 ( int V_85 )
{
F_52 ( & V_86 ) ;
}
static void F_53 ( struct V_34 * V_35 , int V_87 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 ;
struct V_5 * V_6 ;
int V_7 , V_21 ;
F_43 ( V_4 ) ;
if ( ! F_46 ( V_2 ) ) {
F_44 ( V_4 ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
V_24 = V_2 -> V_41 [ V_7 ] . V_40 . V_24 ;
if ( ! V_24 -> V_42 )
continue;
F_6 (fb_helper, j) {
V_6 = V_2 -> V_15 [ V_21 ] -> V_6 ;
V_6 -> V_29 -> V_88 ( V_6 , V_87 ) ;
F_54 ( & V_6 -> V_51 ,
V_4 -> V_10 . V_89 , V_87 ) ;
}
}
F_44 ( V_4 ) ;
}
int F_55 ( int V_90 , struct V_34 * V_35 )
{
if ( V_91 )
return - V_92 ;
switch ( V_90 ) {
case V_93 :
F_53 ( V_35 , V_94 ) ;
break;
case V_95 :
F_53 ( V_35 , V_96 ) ;
break;
case V_97 :
F_53 ( V_35 , V_96 ) ;
break;
case V_98 :
F_53 ( V_35 , V_99 ) ;
break;
case V_100 :
F_53 ( V_35 , V_101 ) ;
break;
}
return 0 ;
}
static void F_56 ( struct V_1 * V_25 ,
struct V_39 * V_102 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_102 -> V_103 ; V_7 ++ ) {
F_7 ( V_102 -> V_104 [ V_7 ] ) ;
V_102 -> V_104 [ V_7 ] = NULL ;
}
V_102 -> V_103 = 0 ;
F_57 ( V_25 -> V_4 , V_102 -> V_105 ) ;
V_102 -> V_105 = NULL ;
V_102 -> V_45 = NULL ;
}
static void F_58 ( struct V_1 * V_25 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_25 -> V_16 ; V_7 ++ ) {
F_7 ( V_25 -> V_15 [ V_7 ] -> V_6 ) ;
F_8 ( V_25 -> V_15 [ V_7 ] ) ;
}
F_8 ( V_25 -> V_15 ) ;
for ( V_7 = 0 ; V_7 < V_25 -> V_38 ; V_7 ++ ) {
struct V_39 * V_102 = & V_25 -> V_41 [ V_7 ] . V_40 ;
F_56 ( V_25 , V_102 ) ;
F_8 ( V_102 -> V_104 ) ;
}
F_8 ( V_25 -> V_41 ) ;
}
static void F_59 ( struct V_83 * V_106 )
{
struct V_1 * V_25 = F_60 ( V_106 , struct V_1 ,
V_107 ) ;
F_61 () ;
F_62 ( V_25 -> V_108 , 0 ) ;
F_63 () ;
}
static void F_64 ( struct V_83 * V_106 )
{
struct V_1 * V_25 = F_60 ( V_106 , struct V_1 ,
V_109 ) ;
struct V_110 * V_111 = & V_25 -> V_112 ;
struct V_110 V_113 ;
unsigned long V_114 ;
F_65 ( & V_25 -> V_115 , V_114 ) ;
V_113 = * V_111 ;
V_111 -> V_116 = V_111 -> y1 = ~ 0 ;
V_111 -> V_117 = V_111 -> V_118 = 0 ;
F_66 ( & V_25 -> V_115 , V_114 ) ;
if ( V_113 . V_116 < V_113 . V_117 && V_113 . y1 < V_113 . V_118 )
V_25 -> V_45 -> V_29 -> V_119 ( V_25 -> V_45 , NULL , 0 , 0 , & V_113 , 1 ) ;
}
void F_67 ( struct V_3 * V_4 , struct V_1 * V_25 ,
const struct V_120 * V_29 )
{
F_68 ( & V_25 -> V_121 ) ;
F_69 ( & V_25 -> V_115 ) ;
F_70 ( & V_25 -> V_107 , F_59 ) ;
F_70 ( & V_25 -> V_109 , F_64 ) ;
V_25 -> V_112 . V_116 = V_25 -> V_112 . y1 = ~ 0 ;
V_25 -> V_29 = V_29 ;
V_25 -> V_4 = V_4 ;
}
int F_71 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_38 , int V_122 )
{
struct V_23 * V_24 ;
int V_7 ;
if ( ! V_9 )
return 0 ;
if ( ! V_122 )
return - V_22 ;
V_2 -> V_41 = F_72 ( V_38 , sizeof( struct V_123 ) , V_19 ) ;
if ( ! V_2 -> V_41 )
return - V_20 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_15 = F_72 ( V_4 -> V_10 . V_124 , sizeof( struct V_13 * ) , V_19 ) ;
if ( ! V_2 -> V_15 ) {
F_8 ( V_2 -> V_41 ) ;
return - V_20 ;
}
V_2 -> V_18 = V_4 -> V_10 . V_124 ;
V_2 -> V_16 = 0 ;
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ ) {
V_2 -> V_41 [ V_7 ] . V_40 . V_104 =
F_72 ( V_122 ,
sizeof( struct V_5 * ) ,
V_19 ) ;
if ( ! V_2 -> V_41 [ V_7 ] . V_40 . V_104 )
goto V_125;
V_2 -> V_41 [ V_7 ] . V_40 . V_103 = 0 ;
}
V_7 = 0 ;
F_20 (crtc, dev) {
V_2 -> V_41 [ V_7 ] . V_40 . V_24 = V_24 ;
V_7 ++ ;
}
return 0 ;
V_125:
F_58 ( V_2 ) ;
return - V_20 ;
}
struct V_34 * F_73 ( struct V_1 * V_2 )
{
struct V_126 * V_4 = V_2 -> V_4 -> V_4 ;
struct V_34 * V_35 ;
int V_8 ;
V_35 = F_74 ( 0 , V_4 ) ;
if ( ! V_35 )
return F_75 ( - V_20 ) ;
V_8 = F_76 ( & V_35 -> V_127 , 256 , 0 ) ;
if ( V_8 )
goto V_128;
V_35 -> V_129 = F_77 ( 1 ) ;
if ( ! V_35 -> V_129 ) {
V_8 = - V_20 ;
goto V_130;
}
V_2 -> V_108 = V_35 ;
return V_35 ;
V_130:
F_78 ( & V_35 -> V_127 ) ;
V_128:
F_79 ( V_35 ) ;
return F_75 ( V_8 ) ;
}
void F_80 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_108 )
F_81 ( V_2 -> V_108 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
if ( V_2 ) {
struct V_34 * V_35 = V_2 -> V_108 ;
if ( V_35 ) {
if ( V_35 -> V_127 . V_131 )
F_78 ( & V_35 -> V_127 ) ;
F_79 ( V_35 ) ;
}
V_2 -> V_108 = NULL ;
}
}
void F_83 ( struct V_1 * V_2 )
{
if ( ! V_9 )
return;
F_2 ( & V_132 ) ;
if ( ! F_49 ( & V_2 -> V_121 ) ) {
F_84 ( & V_2 -> V_121 ) ;
if ( F_49 ( & V_80 ) ) {
F_85 ( 'v' , & V_133 ) ;
}
}
F_5 ( & V_132 ) ;
F_58 ( V_2 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_108 )
F_87 ( V_2 -> V_108 ) ;
}
static void F_88 ( struct V_34 * V_35 , T_2 V_46 , T_2 V_47 ,
T_2 V_134 , T_2 V_135 )
{
struct V_1 * V_25 = V_35 -> V_36 ;
struct V_110 * V_111 = & V_25 -> V_112 ;
unsigned long V_114 ;
if ( ! V_25 -> V_45 -> V_29 -> V_119 )
return;
F_65 ( & V_25 -> V_115 , V_114 ) ;
V_111 -> V_116 = F_89 ( T_2 , V_111 -> V_116 , V_46 ) ;
V_111 -> y1 = F_89 ( T_2 , V_111 -> y1 , V_47 ) ;
V_111 -> V_117 = F_90 ( T_2 , V_111 -> V_117 , V_46 + V_134 ) ;
V_111 -> V_118 = F_90 ( T_2 , V_111 -> V_118 , V_47 + V_135 ) ;
F_66 ( & V_25 -> V_115 , V_114 ) ;
F_52 ( & V_25 -> V_109 ) ;
}
void F_91 ( struct V_34 * V_35 ,
struct V_136 * V_137 )
{
unsigned long V_138 , V_139 , V_140 , V_141 ;
struct V_142 * V_142 ;
T_2 y1 , V_118 ;
V_140 = V_143 ;
V_141 = 0 ;
F_18 (page, pagelist, lru) {
V_138 = V_142 -> V_144 << V_145 ;
V_139 = V_138 + V_146 - 1 ;
V_140 = V_140 ( V_140 , V_138 ) ;
V_141 = V_141 ( V_141 , V_139 ) ;
}
if ( V_140 < V_141 ) {
y1 = V_140 / V_35 -> V_147 . V_148 ;
V_118 = F_89 ( T_2 , F_92 ( V_141 , V_35 -> V_147 . V_148 ) ,
V_35 -> V_149 . V_150 ) ;
F_88 ( V_35 , 0 , y1 , V_35 -> V_149 . V_151 , V_118 - y1 ) ;
}
}
T_3 F_93 ( struct V_34 * V_35 , char T_4 * V_152 ,
T_5 V_153 , T_6 * V_154 )
{
return F_94 ( V_35 , V_152 , V_153 , V_154 ) ;
}
T_3 F_95 ( struct V_34 * V_35 , const char T_4 * V_152 ,
T_5 V_153 , T_6 * V_154 )
{
T_3 V_8 ;
V_8 = F_96 ( V_35 , V_152 , V_153 , V_154 ) ;
if ( V_8 > 0 )
F_88 ( V_35 , 0 , 0 , V_35 -> V_149 . V_151 ,
V_35 -> V_149 . V_150 ) ;
return V_8 ;
}
void F_97 ( struct V_34 * V_35 ,
const struct V_155 * V_156 )
{
F_98 ( V_35 , V_156 ) ;
F_88 ( V_35 , V_156 -> V_157 , V_156 -> V_158 ,
V_156 -> V_134 , V_156 -> V_135 ) ;
}
void F_99 ( struct V_34 * V_35 ,
const struct V_159 * V_160 )
{
F_100 ( V_35 , V_160 ) ;
F_88 ( V_35 , V_160 -> V_157 , V_160 -> V_158 ,
V_160 -> V_134 , V_160 -> V_135 ) ;
}
void F_101 ( struct V_34 * V_35 ,
const struct V_161 * V_162 )
{
F_102 ( V_35 , V_162 ) ;
F_88 ( V_35 , V_162 -> V_157 , V_162 -> V_158 ,
V_162 -> V_134 , V_162 -> V_135 ) ;
}
void F_103 ( struct V_34 * V_35 ,
const struct V_155 * V_156 )
{
F_104 ( V_35 , V_156 ) ;
F_88 ( V_35 , V_156 -> V_157 , V_156 -> V_158 ,
V_156 -> V_134 , V_156 -> V_135 ) ;
}
void F_105 ( struct V_34 * V_35 ,
const struct V_159 * V_160 )
{
F_106 ( V_35 , V_160 ) ;
F_88 ( V_35 , V_160 -> V_157 , V_160 -> V_158 ,
V_160 -> V_134 , V_160 -> V_135 ) ;
}
void F_107 ( struct V_34 * V_35 ,
const struct V_161 * V_162 )
{
F_108 ( V_35 , V_162 ) ;
F_88 ( V_35 , V_162 -> V_157 , V_162 -> V_158 ,
V_162 -> V_134 , V_162 -> V_135 ) ;
}
void F_109 ( struct V_1 * V_2 , bool V_163 )
{
if ( V_2 && V_2 -> V_108 )
F_62 ( V_2 -> V_108 , V_163 ) ;
}
void F_110 ( struct V_1 * V_2 ,
bool V_163 )
{
if ( ! V_2 || ! V_2 -> V_108 )
return;
F_111 ( & V_2 -> V_107 ) ;
if ( V_163 ) {
if ( V_2 -> V_108 -> V_58 != V_164 )
return;
F_61 () ;
} else {
if ( V_2 -> V_108 -> V_58 == V_164 )
return;
if ( ! F_112 () ) {
F_52 ( & V_2 -> V_107 ) ;
return;
}
}
F_62 ( V_2 -> V_108 , V_163 ) ;
F_63 () ;
}
static int F_113 ( struct V_23 * V_24 , T_7 V_165 , T_7 V_166 ,
T_7 V_167 , T_7 V_168 , struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_49 * V_45 = V_2 -> V_45 ;
if ( V_35 -> V_147 . V_169 == V_170 ) {
T_2 * V_171 ;
T_2 V_172 ;
if ( V_168 > 16 )
return - V_22 ;
V_171 = ( T_2 * ) V_35 -> V_173 ;
V_165 >>= ( 16 - V_35 -> V_149 . V_165 . V_174 ) ;
V_166 >>= ( 16 - V_35 -> V_149 . V_166 . V_174 ) ;
V_167 >>= ( 16 - V_35 -> V_149 . V_167 . V_174 ) ;
V_172 = ( V_165 << V_35 -> V_149 . V_165 . V_175 ) |
( V_166 << V_35 -> V_149 . V_166 . V_175 ) |
( V_167 << V_35 -> V_149 . V_167 . V_175 ) ;
if ( V_35 -> V_149 . V_176 . V_174 > 0 ) {
T_2 V_177 = ( 1 << V_35 -> V_149 . V_176 . V_174 ) - 1 ;
V_177 <<= V_35 -> V_149 . V_176 . V_175 ;
V_172 |= V_177 ;
}
V_171 [ V_168 ] = V_172 ;
return 0 ;
}
if ( F_9 ( ! V_2 -> V_29 -> V_33 ||
! V_2 -> V_29 -> V_30 ) )
return - V_22 ;
F_9 ( V_45 -> V_178 != 8 ) ;
V_2 -> V_29 -> V_33 ( V_24 , V_165 , V_166 , V_167 , V_168 ) ;
return 0 ;
}
int F_114 ( struct V_179 * V_127 , struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_37 * V_180 ;
T_7 * V_165 , * V_166 , * V_167 , * V_176 ;
struct V_23 * V_24 ;
int V_7 , V_21 , V_181 = 0 ;
int V_138 ;
if ( V_91 )
return - V_92 ;
F_43 ( V_4 ) ;
if ( ! F_46 ( V_2 ) ) {
F_44 ( V_4 ) ;
return - V_92 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
V_24 = V_2 -> V_41 [ V_7 ] . V_40 . V_24 ;
V_180 = V_24 -> V_43 ;
V_165 = V_127 -> V_165 ;
V_166 = V_127 -> V_166 ;
V_167 = V_127 -> V_167 ;
V_176 = V_127 -> V_176 ;
V_138 = V_127 -> V_138 ;
for ( V_21 = 0 ; V_21 < V_127 -> V_131 ; V_21 ++ ) {
T_7 V_182 , V_183 , V_184 , V_185 = 0xffff ;
V_182 = * V_165 ++ ;
V_183 = * V_166 ++ ;
V_184 = * V_167 ++ ;
if ( V_176 )
V_185 = * V_176 ++ ;
V_181 = F_113 ( V_24 , V_182 , V_183 , V_184 , V_138 ++ , V_35 ) ;
if ( V_181 )
goto V_186;
}
if ( V_180 -> V_187 )
V_180 -> V_187 ( V_24 ) ;
}
V_186:
F_44 ( V_4 ) ;
return V_181 ;
}
int F_115 ( struct V_188 * V_149 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_49 * V_45 = V_2 -> V_45 ;
int V_189 ;
if ( V_149 -> V_190 != 0 || F_116 () )
return - V_22 ;
if ( V_149 -> V_178 != V_45 -> V_178 ||
V_149 -> V_151 != V_45 -> V_134 || V_149 -> V_150 != V_45 -> V_135 ||
V_149 -> V_191 != V_45 -> V_134 || V_149 -> V_192 != V_45 -> V_135 ) {
F_117 ( L_3
L_4 ,
V_149 -> V_151 , V_149 -> V_150 , V_149 -> V_178 ,
V_149 -> V_191 , V_149 -> V_192 ,
V_45 -> V_134 , V_45 -> V_135 , V_45 -> V_178 ) ;
return - V_22 ;
}
switch ( V_149 -> V_178 ) {
case 16 :
V_189 = ( V_149 -> V_166 . V_174 == 6 ) ? 16 : 15 ;
break;
case 32 :
V_189 = ( V_149 -> V_176 . V_174 > 0 ) ? 32 : 24 ;
break;
default:
V_189 = V_149 -> V_178 ;
break;
}
switch ( V_189 ) {
case 8 :
V_149 -> V_165 . V_175 = 0 ;
V_149 -> V_166 . V_175 = 0 ;
V_149 -> V_167 . V_175 = 0 ;
V_149 -> V_165 . V_174 = 8 ;
V_149 -> V_166 . V_174 = 8 ;
V_149 -> V_167 . V_174 = 8 ;
V_149 -> V_176 . V_174 = 0 ;
V_149 -> V_176 . V_175 = 0 ;
break;
case 15 :
V_149 -> V_165 . V_175 = 10 ;
V_149 -> V_166 . V_175 = 5 ;
V_149 -> V_167 . V_175 = 0 ;
V_149 -> V_165 . V_174 = 5 ;
V_149 -> V_166 . V_174 = 5 ;
V_149 -> V_167 . V_174 = 5 ;
V_149 -> V_176 . V_174 = 1 ;
V_149 -> V_176 . V_175 = 15 ;
break;
case 16 :
V_149 -> V_165 . V_175 = 11 ;
V_149 -> V_166 . V_175 = 5 ;
V_149 -> V_167 . V_175 = 0 ;
V_149 -> V_165 . V_174 = 5 ;
V_149 -> V_166 . V_174 = 6 ;
V_149 -> V_167 . V_174 = 5 ;
V_149 -> V_176 . V_174 = 0 ;
V_149 -> V_176 . V_175 = 0 ;
break;
case 24 :
V_149 -> V_165 . V_175 = 16 ;
V_149 -> V_166 . V_175 = 8 ;
V_149 -> V_167 . V_175 = 0 ;
V_149 -> V_165 . V_174 = 8 ;
V_149 -> V_166 . V_174 = 8 ;
V_149 -> V_167 . V_174 = 8 ;
V_149 -> V_176 . V_174 = 0 ;
V_149 -> V_176 . V_175 = 0 ;
break;
case 32 :
V_149 -> V_165 . V_175 = 16 ;
V_149 -> V_166 . V_175 = 8 ;
V_149 -> V_167 . V_175 = 0 ;
V_149 -> V_165 . V_174 = 8 ;
V_149 -> V_166 . V_174 = 8 ;
V_149 -> V_167 . V_174 = 8 ;
V_149 -> V_176 . V_174 = 8 ;
V_149 -> V_176 . V_175 = 24 ;
break;
default:
return - V_22 ;
}
return 0 ;
}
int F_118 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_188 * V_149 = & V_35 -> V_149 ;
if ( V_91 )
return - V_92 ;
if ( V_149 -> V_190 != 0 ) {
F_22 ( L_5 ) ;
return - V_22 ;
}
F_42 ( V_2 ) ;
return 0 ;
}
static int F_119 ( struct V_188 * V_149 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_57 * V_58 ;
struct V_55 * V_56 ;
int V_7 , V_8 ;
unsigned V_59 ;
V_58 = F_24 ( V_4 ) ;
if ( ! V_58 )
return - V_20 ;
V_58 -> V_60 = V_4 -> V_10 . V_60 ;
V_61:
V_59 = 0 ;
for( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
struct V_39 * V_40 ;
V_40 = & V_2 -> V_41 [ V_7 ] . V_40 ;
V_40 -> V_46 = V_149 -> V_193 ;
V_40 -> V_47 = V_149 -> V_194 ;
V_8 = F_31 ( V_40 , V_58 ) ;
if ( V_8 != 0 )
goto V_12;
V_56 = V_40 -> V_24 -> V_53 ;
V_59 |= ( 1 << F_29 ( V_56 ) ) ;
V_56 -> V_66 = V_56 -> V_45 ;
}
V_8 = F_32 ( V_58 ) ;
if ( V_8 != 0 )
goto V_12;
V_35 -> V_149 . V_193 = V_149 -> V_193 ;
V_35 -> V_149 . V_194 = V_149 -> V_194 ;
V_12:
F_33 ( V_4 , V_59 , V_8 ) ;
if ( V_8 == - V_68 )
goto V_69;
F_34 ( V_58 ) ;
return V_8 ;
V_69:
F_35 ( V_58 ) ;
F_36 ( V_58 ) ;
goto V_61;
}
int F_120 ( struct V_188 * V_149 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_39 * V_102 ;
int V_8 = 0 ;
int V_7 ;
if ( V_91 )
return - V_92 ;
F_43 ( V_4 ) ;
if ( ! F_46 ( V_2 ) ) {
F_44 ( V_4 ) ;
return - V_92 ;
}
if ( V_4 -> V_10 . V_29 -> V_70 ) {
V_8 = F_119 ( V_149 , V_35 ) ;
goto V_195;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
V_102 = & V_2 -> V_41 [ V_7 ] . V_40 ;
V_102 -> V_46 = V_149 -> V_193 ;
V_102 -> V_47 = V_149 -> V_194 ;
if ( V_102 -> V_103 ) {
V_8 = F_41 ( V_102 ) ;
if ( ! V_8 ) {
V_35 -> V_149 . V_193 = V_149 -> V_193 ;
V_35 -> V_149 . V_194 = V_149 -> V_194 ;
}
}
}
V_195:
F_44 ( V_4 ) ;
return V_8 ;
}
static int F_121 ( struct V_1 * V_2 ,
int V_196 )
{
int V_8 = 0 ;
int V_38 = 0 ;
int V_7 ;
struct V_197 V_198 ;
int V_32 = 0 ;
memset ( & V_198 , 0 , sizeof( struct V_197 ) ) ;
V_198 . V_199 = 24 ;
V_198 . V_200 = 32 ;
V_198 . V_201 = ( unsigned ) - 1 ;
V_198 . V_202 = ( unsigned ) - 1 ;
if ( V_196 != V_198 . V_200 )
V_198 . V_199 = V_198 . V_200 = V_196 ;
F_6 (fb_helper, i) {
struct V_13 * V_203 = V_2 -> V_15 [ V_7 ] ;
struct V_204 * V_205 ;
V_205 = & V_203 -> V_6 -> V_205 ;
if ( V_205 -> V_206 ) {
switch ( V_205 -> V_207 ) {
case 8 :
V_198 . V_199 = V_198 . V_200 = 8 ;
break;
case 15 :
V_198 . V_199 = 15 ;
V_198 . V_200 = 16 ;
break;
case 16 :
V_198 . V_199 = V_198 . V_200 = 16 ;
break;
case 24 :
V_198 . V_199 = V_198 . V_200 = 24 ;
break;
case 32 :
V_198 . V_199 = 24 ;
V_198 . V_200 = 32 ;
break;
}
break;
}
}
V_38 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
struct V_208 * V_209 ;
struct V_39 * V_40 ;
int V_46 , V_47 , V_21 ;
bool V_210 = true , V_211 = true ;
V_209 = V_2 -> V_41 [ V_7 ] . V_209 ;
V_40 = & V_2 -> V_41 [ V_7 ] . V_40 ;
if ( ! V_209 )
continue;
V_38 ++ ;
V_46 = V_2 -> V_41 [ V_7 ] . V_46 ;
V_47 = V_2 -> V_41 [ V_7 ] . V_47 ;
if ( V_32 == 0 )
V_32 = V_2 -> V_41 [ V_7 ] . V_40 . V_24 -> V_32 ;
V_198 . V_212 = F_90 ( T_2 , V_209 -> V_213 + V_46 , V_198 . V_212 ) ;
V_198 . V_214 = F_90 ( T_2 , V_209 -> V_215 + V_47 , V_198 . V_214 ) ;
for ( V_21 = 0 ; V_21 < V_40 -> V_103 ; V_21 ++ ) {
struct V_5 * V_6 = V_40 -> V_104 [ V_21 ] ;
if ( V_6 -> V_216 ) {
V_211 = ( V_6 -> V_217 == ( V_6 -> V_218 - 1 ) ) ;
V_210 = ( V_6 -> V_219 == ( V_6 -> V_220 - 1 ) ) ;
break;
}
}
if ( V_211 )
V_198 . V_201 = F_89 ( T_2 , V_209 -> V_213 + V_46 , V_198 . V_201 ) ;
if ( V_210 )
V_198 . V_202 = F_89 ( T_2 , V_209 -> V_215 + V_47 , V_198 . V_202 ) ;
}
if ( V_38 == 0 || V_198 . V_201 == - 1 || V_198 . V_202 == - 1 ) {
F_122 ( L_6 ) ;
V_198 . V_201 = V_198 . V_212 = 1024 ;
V_198 . V_202 = V_198 . V_214 = 768 ;
}
V_8 = (* V_2 -> V_29 -> V_221 )( V_2 , & V_198 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ )
if ( V_2 -> V_41 [ V_7 ] . V_40 . V_103 )
V_2 -> V_41 [ V_7 ] . V_40 . V_45 = V_2 -> V_45 ;
return 0 ;
}
void F_123 ( struct V_34 * V_35 , T_8 V_222 ,
T_8 V_189 )
{
V_35 -> V_147 . type = V_223 ;
V_35 -> V_147 . V_169 = V_189 == 8 ? V_224 :
V_170 ;
V_35 -> V_147 . V_225 = 0 ;
V_35 -> V_147 . V_226 = 0 ;
V_35 -> V_147 . V_227 = 0 ;
V_35 -> V_147 . V_228 = 1 ;
V_35 -> V_147 . V_229 = 1 ;
V_35 -> V_147 . V_230 = 0 ;
V_35 -> V_147 . V_231 = V_232 ;
V_35 -> V_147 . V_148 = V_222 ;
return;
}
void F_124 ( struct V_34 * V_35 , struct V_1 * V_2 ,
T_8 V_201 , T_8 V_202 )
{
struct V_49 * V_45 = V_2 -> V_45 ;
V_35 -> V_173 = V_2 -> V_173 ;
V_35 -> V_149 . V_191 = V_45 -> V_134 ;
V_35 -> V_149 . V_192 = V_45 -> V_135 ;
V_35 -> V_149 . V_178 = V_45 -> V_178 ;
V_35 -> V_149 . V_233 = V_234 ;
V_35 -> V_149 . V_193 = 0 ;
V_35 -> V_149 . V_194 = 0 ;
V_35 -> V_149 . V_235 = V_236 ;
V_35 -> V_149 . V_135 = - 1 ;
V_35 -> V_149 . V_134 = - 1 ;
switch ( V_45 -> V_189 ) {
case 8 :
V_35 -> V_149 . V_165 . V_175 = 0 ;
V_35 -> V_149 . V_166 . V_175 = 0 ;
V_35 -> V_149 . V_167 . V_175 = 0 ;
V_35 -> V_149 . V_165 . V_174 = 8 ;
V_35 -> V_149 . V_166 . V_174 = 8 ;
V_35 -> V_149 . V_167 . V_174 = 8 ;
V_35 -> V_149 . V_176 . V_175 = 0 ;
V_35 -> V_149 . V_176 . V_174 = 0 ;
break;
case 15 :
V_35 -> V_149 . V_165 . V_175 = 10 ;
V_35 -> V_149 . V_166 . V_175 = 5 ;
V_35 -> V_149 . V_167 . V_175 = 0 ;
V_35 -> V_149 . V_165 . V_174 = 5 ;
V_35 -> V_149 . V_166 . V_174 = 5 ;
V_35 -> V_149 . V_167 . V_174 = 5 ;
V_35 -> V_149 . V_176 . V_175 = 15 ;
V_35 -> V_149 . V_176 . V_174 = 1 ;
break;
case 16 :
V_35 -> V_149 . V_165 . V_175 = 11 ;
V_35 -> V_149 . V_166 . V_175 = 5 ;
V_35 -> V_149 . V_167 . V_175 = 0 ;
V_35 -> V_149 . V_165 . V_174 = 5 ;
V_35 -> V_149 . V_166 . V_174 = 6 ;
V_35 -> V_149 . V_167 . V_174 = 5 ;
V_35 -> V_149 . V_176 . V_175 = 0 ;
break;
case 24 :
V_35 -> V_149 . V_165 . V_175 = 16 ;
V_35 -> V_149 . V_166 . V_175 = 8 ;
V_35 -> V_149 . V_167 . V_175 = 0 ;
V_35 -> V_149 . V_165 . V_174 = 8 ;
V_35 -> V_149 . V_166 . V_174 = 8 ;
V_35 -> V_149 . V_167 . V_174 = 8 ;
V_35 -> V_149 . V_176 . V_175 = 0 ;
V_35 -> V_149 . V_176 . V_174 = 0 ;
break;
case 32 :
V_35 -> V_149 . V_165 . V_175 = 16 ;
V_35 -> V_149 . V_166 . V_175 = 8 ;
V_35 -> V_149 . V_167 . V_175 = 0 ;
V_35 -> V_149 . V_165 . V_174 = 8 ;
V_35 -> V_149 . V_166 . V_174 = 8 ;
V_35 -> V_149 . V_167 . V_174 = 8 ;
V_35 -> V_149 . V_176 . V_175 = 24 ;
V_35 -> V_149 . V_176 . V_174 = 8 ;
break;
default:
break;
}
V_35 -> V_149 . V_151 = V_201 ;
V_35 -> V_149 . V_150 = V_202 ;
}
static int F_125 ( struct V_1 * V_2 ,
T_8 V_237 ,
T_8 V_238 )
{
struct V_5 * V_6 ;
int V_153 = 0 ;
int V_7 ;
F_6 (fb_helper, i) {
V_6 = V_2 -> V_15 [ V_7 ] -> V_6 ;
V_153 += V_6 -> V_29 -> V_239 ( V_6 , V_237 , V_238 ) ;
}
return V_153 ;
}
struct V_208 * F_126 ( struct V_13 * V_240 , int V_134 , int V_135 )
{
struct V_208 * V_105 ;
F_18 (mode, &fb_connector->connector->modes, head) {
if ( V_105 -> V_213 > V_134 ||
V_105 -> V_215 > V_135 )
continue;
if ( V_105 -> type & V_241 )
return V_105 ;
}
return NULL ;
}
static bool F_127 ( struct V_13 * V_240 )
{
return V_240 -> V_6 -> V_205 . V_242 ;
}
struct V_208 * F_128 ( struct V_13 * V_203 ,
int V_134 , int V_135 )
{
struct V_204 * V_205 ;
struct V_208 * V_105 ;
bool V_243 ;
V_205 = & V_203 -> V_6 -> V_205 ;
if ( V_205 -> V_242 == false )
return NULL ;
if ( V_205 -> V_244 || V_205 -> V_245 )
goto V_246;
V_243 = ! V_205 -> V_247 ;
V_248:
F_18 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_105 -> V_213 != V_205 -> V_151 ||
V_105 -> V_215 != V_205 -> V_150 )
continue;
if ( V_205 -> V_249 ) {
if ( V_105 -> V_250 != V_205 -> V_251 )
continue;
}
if ( V_205 -> V_247 ) {
if ( ! ( V_105 -> V_114 & V_252 ) )
continue;
} else if ( V_243 ) {
if ( V_105 -> V_114 & V_252 )
continue;
}
return V_105 ;
}
if ( V_243 ) {
V_243 = false ;
goto V_248;
}
V_246:
V_105 = F_129 ( V_203 -> V_6 -> V_4 ,
V_205 ) ;
F_130 ( & V_105 -> V_253 , & V_203 -> V_6 -> V_254 ) ;
return V_105 ;
}
static bool F_131 ( struct V_5 * V_6 , bool V_255 )
{
bool V_256 ;
if ( V_255 )
V_256 = V_6 -> V_257 == V_258 ;
else
V_256 = V_6 -> V_257 != V_259 ;
return V_256 ;
}
static void F_132 ( struct V_1 * V_2 ,
bool * V_42 )
{
bool V_260 = false ;
struct V_5 * V_6 ;
int V_7 = 0 ;
F_6 (fb_helper, i) {
V_6 = V_2 -> V_15 [ V_7 ] -> V_6 ;
V_42 [ V_7 ] = F_131 ( V_6 , true ) ;
F_133 ( L_7 , V_6 -> V_51 . V_52 ,
V_42 [ V_7 ] ? L_8 : L_9 ) ;
V_260 |= V_42 [ V_7 ] ;
}
if ( V_260 )
return;
F_6 (fb_helper, i) {
V_6 = V_2 -> V_15 [ V_7 ] -> V_6 ;
V_42 [ V_7 ] = F_131 ( V_6 , false ) ;
}
}
static bool F_134 ( struct V_1 * V_2 ,
struct V_208 * * V_254 ,
struct V_261 * V_262 ,
bool * V_42 , int V_134 , int V_135 )
{
int V_153 , V_7 , V_21 ;
bool V_263 = false ;
struct V_13 * V_203 ;
struct V_208 * V_264 , * V_105 ;
if ( V_2 -> V_38 > 1 )
return false ;
V_153 = 0 ;
F_6 (fb_helper, i) {
if ( V_42 [ V_7 ] )
V_153 ++ ;
}
if ( V_153 <= 1 )
return false ;
V_263 = true ;
F_6 (fb_helper, i) {
if ( ! V_42 [ V_7 ] )
continue;
V_203 = V_2 -> V_15 [ V_7 ] ;
V_254 [ V_7 ] = F_128 ( V_203 , V_134 , V_135 ) ;
if ( ! V_254 [ V_7 ] ) {
V_263 = false ;
break;
}
for ( V_21 = 0 ; V_21 < V_7 ; V_21 ++ ) {
if ( ! V_42 [ V_21 ] )
continue;
if ( ! F_135 ( V_254 [ V_21 ] , V_254 [ V_7 ] ) )
V_263 = false ;
}
}
if ( V_263 ) {
F_133 ( L_10 ) ;
return true ;
}
V_263 = true ;
V_264 = F_136 ( V_2 -> V_4 , 1024 , 768 , 60 , false ) ;
F_6 (fb_helper, i) {
if ( ! V_42 [ V_7 ] )
continue;
V_203 = V_2 -> V_15 [ V_7 ] ;
F_18 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_135 ( V_105 , V_264 ) )
V_254 [ V_7 ] = V_105 ;
}
if ( ! V_254 [ V_7 ] )
V_263 = false ;
}
if ( V_263 ) {
F_133 ( L_11 ) ;
return true ;
}
F_122 ( L_12 ) ;
return false ;
}
static int F_137 ( struct V_1 * V_2 ,
struct V_208 * * V_254 ,
struct V_261 * V_262 ,
int V_265 ,
int V_266 , int V_267 )
{
struct V_13 * V_203 ;
int V_7 ;
int V_268 = 0 , V_269 = 0 ;
F_6 (fb_helper, i) {
V_203 = V_2 -> V_15 [ V_7 ] ;
if ( ! V_203 -> V_6 -> V_216 )
continue;
if ( ! V_254 [ V_7 ] && ( V_266 || V_267 ) ) {
F_133 ( L_13 , V_7 ,
V_203 -> V_6 -> V_51 . V_52 ) ;
continue;
}
if ( V_203 -> V_6 -> V_217 < V_266 )
V_268 += V_254 [ V_7 ] -> V_213 ;
if ( V_203 -> V_6 -> V_219 < V_267 )
V_269 += V_254 [ V_7 ] -> V_215 ;
}
V_262 [ V_265 ] . V_46 = V_268 ;
V_262 [ V_265 ] . V_47 = V_269 ;
F_133 ( L_14 , V_268 , V_269 , V_266 , V_267 ) ;
return 0 ;
}
static bool F_138 ( struct V_1 * V_2 ,
struct V_208 * * V_254 ,
struct V_261 * V_262 ,
bool * V_42 , int V_134 , int V_135 )
{
struct V_13 * V_203 ;
const T_9 V_177 = F_139 ( V_2 -> V_16 ) - 1 ;
T_9 V_270 = 0 ;
int V_271 = 0 ;
int V_7 ;
V_61:
F_6 (fb_helper, i) {
V_203 = V_2 -> V_15 [ V_7 ] ;
if ( V_270 & F_139 ( V_7 ) )
continue;
if ( V_42 [ V_7 ] == false ) {
V_270 |= F_139 ( V_7 ) ;
continue;
}
if ( V_271 == 0 && V_203 -> V_6 -> V_216 )
continue;
if ( V_271 == 1 ) {
if ( V_203 -> V_6 -> V_217 != 0 ||
V_203 -> V_6 -> V_219 != 0 )
continue;
} else {
if ( V_203 -> V_6 -> V_217 != V_271 - 1 &&
V_203 -> V_6 -> V_219 != V_271 - 1 )
continue;
F_137 ( V_2 , V_254 , V_262 ,
V_7 , V_203 -> V_6 -> V_217 , V_203 -> V_6 -> V_219 ) ;
}
F_133 ( L_15 ,
V_203 -> V_6 -> V_51 . V_52 ) ;
V_254 [ V_7 ] = F_128 ( V_203 , V_134 , V_135 ) ;
if ( ! V_254 [ V_7 ] ) {
F_133 ( L_16 ,
V_203 -> V_6 -> V_51 . V_52 , V_203 -> V_6 -> V_272 ? V_203 -> V_6 -> V_272 -> V_52 : 0 ) ;
V_254 [ V_7 ] = F_126 ( V_203 , V_134 , V_135 ) ;
}
if ( ! V_254 [ V_7 ] && ! F_49 ( & V_203 -> V_6 -> V_254 ) ) {
F_18 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_133 ( L_17 , V_254 [ V_7 ] ? V_254 [ V_7 ] -> V_273 :
L_18 ) ;
V_270 |= F_139 ( V_7 ) ;
}
if ( ( V_270 & V_177 ) != V_177 ) {
V_271 ++ ;
goto V_61;
}
return true ;
}
static int F_140 ( struct V_1 * V_2 ,
struct V_123 * * V_274 ,
struct V_208 * * V_254 ,
int V_275 , int V_134 , int V_135 )
{
int V_50 , V_276 ;
struct V_5 * V_6 ;
const struct V_277 * V_278 ;
struct V_279 * V_280 ;
int V_281 , V_282 , V_283 ;
struct V_123 * * V_284 , * V_24 ;
struct V_13 * V_203 ;
if ( V_275 == V_2 -> V_16 )
return 0 ;
V_203 = V_2 -> V_15 [ V_275 ] ;
V_6 = V_203 -> V_6 ;
V_274 [ V_275 ] = NULL ;
V_282 = F_140 ( V_2 , V_274 , V_254 , V_275 + 1 , V_134 , V_135 ) ;
if ( V_254 [ V_275 ] == NULL )
return V_282 ;
V_284 = F_12 ( V_2 -> V_16 *
sizeof( struct V_123 * ) , V_19 ) ;
if ( ! V_284 )
return V_282 ;
V_281 = 1 ;
if ( V_6 -> V_257 == V_258 )
V_281 ++ ;
if ( F_127 ( V_203 ) )
V_281 ++ ;
if ( F_126 ( V_203 , V_134 , V_135 ) )
V_281 ++ ;
V_278 = V_6 -> V_43 ;
if ( V_2 -> V_4 -> V_10 . V_29 -> V_70 &&
! V_278 -> V_285 )
V_280 = F_141 ( V_6 ) ;
else
V_280 = V_278 -> V_285 ( V_6 ) ;
if ( ! V_280 )
goto V_186;
for ( V_50 = 0 ; V_50 < V_2 -> V_38 ; V_50 ++ ) {
V_24 = & V_2 -> V_41 [ V_50 ] ;
if ( ( V_280 -> V_286 & ( 1 << V_50 ) ) == 0 )
continue;
for ( V_276 = 0 ; V_276 < V_275 ; V_276 ++ )
if ( V_274 [ V_276 ] == V_24 )
break;
if ( V_276 < V_275 ) {
if ( V_2 -> V_38 > 1 )
continue;
if ( ! F_135 ( V_254 [ V_276 ] , V_254 [ V_275 ] ) )
continue;
}
V_284 [ V_275 ] = V_24 ;
memcpy ( V_284 , V_274 , V_275 * sizeof( struct V_123 * ) ) ;
V_283 = V_281 + F_140 ( V_2 , V_284 , V_254 , V_275 + 1 ,
V_134 , V_135 ) ;
if ( V_283 > V_282 ) {
V_282 = V_283 ;
memcpy ( V_274 , V_284 ,
V_2 -> V_16 *
sizeof( struct V_123 * ) ) ;
}
}
V_186:
F_8 ( V_284 ) ;
return V_282 ;
}
static void F_142 ( struct V_1 * V_2 ,
T_2 V_134 , T_2 V_135 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_123 * * V_284 ;
struct V_208 * * V_254 ;
struct V_261 * V_262 ;
bool * V_42 ;
int V_7 ;
F_133 ( L_19 ) ;
if ( F_125 ( V_2 , V_134 , V_135 ) == 0 )
F_133 ( L_20 ) ;
F_143 ( & V_2 -> V_4 -> V_10 . V_11 ) ;
V_284 = F_72 ( V_2 -> V_16 ,
sizeof( struct V_123 * ) , V_19 ) ;
V_254 = F_72 ( V_2 -> V_16 ,
sizeof( struct V_208 * ) , V_19 ) ;
V_262 = F_72 ( V_2 -> V_16 ,
sizeof( struct V_261 ) , V_19 ) ;
V_42 = F_72 ( V_2 -> V_16 ,
sizeof( bool ) , V_19 ) ;
if ( ! V_284 || ! V_254 || ! V_42 || ! V_262 ) {
F_22 ( L_21 ) ;
goto V_186;
}
F_132 ( V_2 , V_42 ) ;
if ( ! ( V_2 -> V_29 -> V_287 &&
V_2 -> V_29 -> V_287 ( V_2 , V_284 , V_254 ,
V_262 ,
V_42 , V_134 , V_135 ) ) ) {
memset ( V_254 , 0 , V_2 -> V_16 * sizeof( V_254 [ 0 ] ) ) ;
memset ( V_284 , 0 , V_2 -> V_16 * sizeof( V_284 [ 0 ] ) ) ;
memset ( V_262 , 0 , V_2 -> V_16 * sizeof( V_262 [ 0 ] ) ) ;
if ( ! F_134 ( V_2 , V_254 , V_262 ,
V_42 , V_134 , V_135 ) &&
! F_138 ( V_2 , V_254 , V_262 ,
V_42 , V_134 , V_135 ) )
F_22 ( L_22 ) ;
F_133 ( L_23 ,
V_134 , V_135 ) ;
F_140 ( V_2 , V_284 , V_254 , 0 , V_134 , V_135 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ )
F_56 ( V_2 ,
& V_2 -> V_41 [ V_7 ] . V_40 ) ;
F_6 (fb_helper, i) {
struct V_208 * V_105 = V_254 [ V_7 ] ;
struct V_123 * V_288 = V_284 [ V_7 ] ;
struct V_261 * V_175 = & V_262 [ V_7 ] ;
struct V_39 * V_102 = & V_288 -> V_40 ;
if ( V_105 && V_288 ) {
struct V_5 * V_6 =
V_2 -> V_15 [ V_7 ] -> V_6 ;
F_133 ( L_24 ,
V_105 -> V_273 , V_288 -> V_40 . V_24 -> V_51 . V_52 , V_175 -> V_46 , V_175 -> V_47 ) ;
V_288 -> V_209 = V_105 ;
V_288 -> V_46 = V_175 -> V_46 ;
V_288 -> V_47 = V_175 -> V_47 ;
V_102 -> V_105 = F_144 ( V_4 ,
V_288 -> V_209 ) ;
F_13 ( V_6 ) ;
V_102 -> V_104 [ V_102 -> V_103 ++ ] = V_6 ;
V_102 -> V_45 = V_2 -> V_45 ;
V_102 -> V_46 = V_175 -> V_46 ;
V_102 -> V_47 = V_175 -> V_47 ;
}
}
V_186:
F_8 ( V_284 ) ;
F_8 ( V_254 ) ;
F_8 ( V_262 ) ;
F_8 ( V_42 ) ;
}
int F_145 ( struct V_1 * V_2 , int V_289 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_34 * V_35 ;
int V_8 ;
if ( ! V_9 )
return 0 ;
F_2 ( & V_4 -> V_10 . V_11 ) ;
F_142 ( V_2 ,
V_4 -> V_10 . V_290 ,
V_4 -> V_10 . V_291 ) ;
V_8 = F_121 ( V_2 , V_289 ) ;
F_5 ( & V_4 -> V_10 . V_11 ) ;
if ( V_8 )
return V_8 ;
V_35 = V_2 -> V_108 ;
V_35 -> V_149 . V_190 = 0 ;
V_8 = F_146 ( V_35 ) ;
if ( V_8 < 0 )
return V_8 ;
F_147 ( V_4 -> V_4 , L_25 ,
V_35 -> V_292 , V_35 -> V_147 . V_52 ) ;
F_2 ( & V_132 ) ;
if ( F_49 ( & V_80 ) )
F_148 ( 'v' , & V_133 ) ;
F_130 ( & V_2 -> V_121 , & V_80 ) ;
F_5 ( & V_132 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! V_9 )
return 0 ;
F_2 ( & V_4 -> V_10 . V_11 ) ;
if ( ! V_2 -> V_45 || ! F_46 ( V_2 ) ) {
V_2 -> V_76 = true ;
F_5 ( & V_4 -> V_10 . V_11 ) ;
return 0 ;
}
F_133 ( L_19 ) ;
F_142 ( V_2 , V_2 -> V_45 -> V_134 , V_2 -> V_45 -> V_135 ) ;
F_5 ( & V_4 -> V_10 . V_11 ) ;
F_118 ( V_2 -> V_108 ) ;
return 0 ;
}
int T_10 F_149 ( void )
{
#if F_150 ( V_293 ) && ! F_150 ( V_294 )
const char * V_273 = L_26 ;
struct V_295 * V_296 ;
F_2 ( & V_297 ) ;
V_296 = F_151 ( V_273 ) ;
F_5 ( & V_297 ) ;
if ( ! V_296 )
F_152 ( V_273 ) ;
#endif
return 0 ;
}
