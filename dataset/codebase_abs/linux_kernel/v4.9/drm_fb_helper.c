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
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_14 * V_15 =
V_2 -> V_16 [ V_7 ] ;
F_6 ( V_15 -> V_6 ) ;
F_7 ( V_15 ) ;
V_2 -> V_16 [ V_7 ] = NULL ;
}
V_2 -> V_13 = 0 ;
F_5 ( & V_4 -> V_10 . V_11 ) ;
return V_8 ;
}
int F_4 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_14 * * V_17 ;
struct V_14 * V_15 ;
if ( ! V_9 )
return 0 ;
F_8 ( ! F_9 ( & V_2 -> V_4 -> V_10 . V_11 ) ) ;
if ( V_2 -> V_13 + 1 > V_2 -> V_18 ) {
V_17 = F_10 ( V_2 -> V_16 , sizeof( struct V_14 * ) * ( V_2 -> V_13 + 1 ) , V_19 ) ;
if ( ! V_17 )
return - V_20 ;
V_2 -> V_18 = V_2 -> V_13 + 1 ;
V_2 -> V_16 = V_17 ;
}
V_15 = F_11 ( sizeof( struct V_14 ) , V_19 ) ;
if ( ! V_15 )
return - V_20 ;
F_12 ( V_6 ) ;
V_15 -> V_6 = V_6 ;
V_2 -> V_16 [ V_2 -> V_13 ++ ] = V_15 ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_14 * V_15 ;
int V_7 , V_21 ;
if ( ! V_9 )
return 0 ;
F_8 ( ! F_9 ( & V_2 -> V_4 -> V_10 . V_11 ) ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( V_2 -> V_16 [ V_7 ] -> V_6 == V_6 )
break;
}
if ( V_7 == V_2 -> V_13 )
return - V_22 ;
V_15 = V_2 -> V_16 [ V_7 ] ;
F_6 ( V_15 -> V_6 ) ;
for ( V_21 = V_7 + 1 ; V_21 < V_2 -> V_13 ; V_21 ++ ) {
V_2 -> V_16 [ V_21 - 1 ] = V_2 -> V_16 [ V_21 ] ;
}
V_2 -> V_13 -- ;
F_7 ( V_15 ) ;
return 0 ;
}
static void F_14 ( struct V_23 * V_24 , struct V_1 * V_25 )
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
static void F_15 ( struct V_23 * V_24 )
{
T_1 * V_26 , * V_27 , * V_28 ;
if ( V_24 -> V_29 -> V_33 == NULL )
return;
V_26 = V_24 -> V_31 ;
V_27 = V_26 + V_24 -> V_32 ;
V_28 = V_27 + V_24 -> V_32 ;
V_24 -> V_29 -> V_33 ( V_24 , V_26 , V_27 , V_28 , V_24 -> V_32 ) ;
}
int F_16 ( struct V_34 * V_35 )
{
struct V_1 * V_25 = V_35 -> V_36 ;
const struct V_37 * V_29 ;
int V_7 ;
F_17 (helper, &kernel_fb_helper_list, kernel_fb_list) {
for ( V_7 = 0 ; V_7 < V_25 -> V_38 ; V_7 ++ ) {
struct V_39 * V_40 =
& V_25 -> V_41 [ V_7 ] . V_40 ;
if ( ! V_40 -> V_24 -> V_42 )
continue;
V_29 = V_40 -> V_24 -> V_43 ;
F_14 ( V_40 -> V_24 , V_25 ) ;
V_29 -> V_44 ( V_40 -> V_24 ,
V_40 -> V_45 ,
V_40 -> V_46 ,
V_40 -> V_47 ,
V_48 ) ;
}
}
return 0 ;
}
static struct V_49 * F_18 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_4 ;
struct V_23 * V_50 ;
F_19 (c, dev) {
if ( V_24 -> V_51 . V_52 == V_50 -> V_51 . V_52 )
return V_50 -> V_53 -> V_45 ;
}
return NULL ;
}
int F_20 ( struct V_34 * V_35 )
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
V_45 = F_18 ( V_24 ) ;
if ( ! V_24 -> V_42 )
continue;
if ( ! V_45 ) {
F_21 ( L_1 ) ;
continue;
}
F_15 ( V_40 -> V_24 ) ;
V_29 -> V_44 ( V_40 -> V_24 , V_45 , V_24 -> V_46 ,
V_24 -> V_47 , V_54 ) ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
int V_7 , V_8 ;
unsigned V_59 ;
V_58 = F_23 ( V_4 ) ;
if ( ! V_58 )
return - V_20 ;
V_58 -> V_60 = V_4 -> V_10 . V_60 ;
V_61:
V_59 = 0 ;
F_24 (plane, dev) {
struct V_62 * V_63 ;
V_63 = F_25 ( V_58 , V_56 ) ;
if ( F_26 ( V_63 ) ) {
V_8 = F_27 ( V_63 ) ;
goto V_12;
}
V_63 -> V_64 = V_65 ;
V_56 -> V_66 = V_56 -> V_45 ;
V_59 |= 1 << F_28 ( V_56 ) ;
if ( V_56 -> type == V_67 )
continue;
V_8 = F_29 ( V_56 , V_63 ) ;
if ( V_8 != 0 )
goto V_12;
}
for( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
struct V_39 * V_40 = & V_2 -> V_41 [ V_7 ] . V_40 ;
V_8 = F_30 ( V_40 , V_58 ) ;
if ( V_8 != 0 )
goto V_12;
}
V_8 = F_31 ( V_58 ) ;
V_12:
F_32 ( V_4 , V_59 , V_8 ) ;
if ( V_8 == - V_68 )
goto V_69;
if ( V_8 != 0 )
F_33 ( V_58 ) ;
return V_8 ;
V_69:
F_34 ( V_58 ) ;
F_35 ( V_58 ) ;
goto V_61;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_55 * V_56 ;
int V_7 ;
F_37 ( V_4 ) ;
if ( V_4 -> V_10 . V_29 -> V_70 )
return F_22 ( V_2 ) ;
F_24 (plane, dev) {
if ( V_56 -> type != V_67 )
F_38 ( V_56 ) ;
if ( V_4 -> V_10 . V_71 ) {
F_39 ( V_56 ,
V_4 -> V_10 . V_71 ,
V_65 ) ;
}
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
V_8 = F_40 ( V_40 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
int F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_74 ;
int V_8 ;
if ( ! V_9 )
return - V_75 ;
F_42 ( V_4 ) ;
V_8 = F_36 ( V_2 ) ;
V_74 = V_2 -> V_76 ;
if ( V_74 )
V_2 -> V_76 = false ;
F_43 ( V_4 ) ;
if ( V_74 )
F_44 ( V_2 ) ;
return V_8 ;
}
static bool F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 ;
int V_77 = 0 , V_78 = 0 ;
if ( F_46 ( V_4 -> V_79 ) )
return false ;
F_19 (crtc, dev) {
if ( V_24 -> V_53 -> V_45 )
V_78 ++ ;
if ( V_24 -> V_53 -> V_45 == V_2 -> V_45 )
V_77 ++ ;
}
if ( V_77 < V_78 )
return false ;
return true ;
}
static bool F_47 ( void )
{
bool V_8 , error = false ;
struct V_1 * V_25 ;
if ( F_48 ( & V_80 ) )
return false ;
F_17 (helper, &kernel_fb_helper_list, kernel_fb_list) {
struct V_3 * V_4 = V_25 -> V_4 ;
if ( V_4 -> V_81 == V_82 )
continue;
F_42 ( V_4 ) ;
V_8 = F_36 ( V_25 ) ;
if ( V_8 )
error = true ;
F_43 ( V_4 ) ;
}
return error ;
}
static void F_49 ( struct V_83 * V_84 )
{
bool V_8 ;
V_8 = F_47 () ;
if ( V_8 == true )
F_21 ( L_2 ) ;
}
static void F_50 ( int V_85 )
{
F_51 ( & V_86 ) ;
}
static void F_52 ( struct V_34 * V_35 , int V_87 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 ;
struct V_5 * V_6 ;
int V_7 , V_21 ;
F_42 ( V_4 ) ;
if ( ! F_45 ( V_2 ) ) {
F_43 ( V_4 ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
V_24 = V_2 -> V_41 [ V_7 ] . V_40 . V_24 ;
if ( ! V_24 -> V_42 )
continue;
for ( V_21 = 0 ; V_21 < V_2 -> V_13 ; V_21 ++ ) {
V_6 = V_2 -> V_16 [ V_21 ] -> V_6 ;
V_6 -> V_29 -> V_88 ( V_6 , V_87 ) ;
F_53 ( & V_6 -> V_51 ,
V_4 -> V_10 . V_89 , V_87 ) ;
}
}
F_43 ( V_4 ) ;
}
int F_54 ( int V_90 , struct V_34 * V_35 )
{
if ( V_91 )
return - V_92 ;
switch ( V_90 ) {
case V_93 :
F_52 ( V_35 , V_94 ) ;
break;
case V_95 :
F_52 ( V_35 , V_96 ) ;
break;
case V_97 :
F_52 ( V_35 , V_96 ) ;
break;
case V_98 :
F_52 ( V_35 , V_99 ) ;
break;
case V_100 :
F_52 ( V_35 , V_101 ) ;
break;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_25 ,
struct V_39 * V_102 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_102 -> V_103 ; V_7 ++ ) {
F_6 ( V_102 -> V_104 [ V_7 ] ) ;
V_102 -> V_104 [ V_7 ] = NULL ;
}
V_102 -> V_103 = 0 ;
F_56 ( V_25 -> V_4 , V_102 -> V_105 ) ;
V_102 -> V_105 = NULL ;
V_102 -> V_45 = NULL ;
}
static void F_57 ( struct V_1 * V_25 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_25 -> V_13 ; V_7 ++ ) {
F_6 ( V_25 -> V_16 [ V_7 ] -> V_6 ) ;
F_7 ( V_25 -> V_16 [ V_7 ] ) ;
}
F_7 ( V_25 -> V_16 ) ;
for ( V_7 = 0 ; V_7 < V_25 -> V_38 ; V_7 ++ ) {
struct V_39 * V_102 = & V_25 -> V_41 [ V_7 ] . V_40 ;
F_55 ( V_25 , V_102 ) ;
F_7 ( V_102 -> V_104 ) ;
}
F_7 ( V_25 -> V_41 ) ;
}
static void F_58 ( struct V_83 * V_106 )
{
struct V_1 * V_25 = F_59 ( V_106 , struct V_1 ,
V_107 ) ;
F_60 () ;
F_61 ( V_25 -> V_108 , 0 ) ;
F_62 () ;
}
static void F_63 ( struct V_83 * V_106 )
{
struct V_1 * V_25 = F_59 ( V_106 , struct V_1 ,
V_109 ) ;
struct V_110 * V_111 = & V_25 -> V_112 ;
struct V_110 V_113 ;
unsigned long V_114 ;
F_64 ( & V_25 -> V_115 , V_114 ) ;
V_113 = * V_111 ;
V_111 -> V_116 = V_111 -> y1 = ~ 0 ;
V_111 -> V_117 = V_111 -> V_118 = 0 ;
F_65 ( & V_25 -> V_115 , V_114 ) ;
if ( V_113 . V_116 < V_113 . V_117 && V_113 . y1 < V_113 . V_118 )
V_25 -> V_45 -> V_29 -> V_119 ( V_25 -> V_45 , NULL , 0 , 0 , & V_113 , 1 ) ;
}
void F_66 ( struct V_3 * V_4 , struct V_1 * V_25 ,
const struct V_120 * V_29 )
{
F_67 ( & V_25 -> V_121 ) ;
F_68 ( & V_25 -> V_115 ) ;
F_69 ( & V_25 -> V_107 , F_58 ) ;
F_69 ( & V_25 -> V_109 , F_63 ) ;
V_25 -> V_112 . V_116 = V_25 -> V_112 . y1 = ~ 0 ;
V_25 -> V_29 = V_29 ;
V_25 -> V_4 = V_4 ;
}
int F_70 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_38 , int V_122 )
{
struct V_23 * V_24 ;
int V_7 ;
if ( ! V_9 )
return 0 ;
if ( ! V_122 )
return - V_22 ;
V_2 -> V_41 = F_71 ( V_38 , sizeof( struct V_123 ) , V_19 ) ;
if ( ! V_2 -> V_41 )
return - V_20 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_16 = F_71 ( V_4 -> V_10 . V_124 , sizeof( struct V_14 * ) , V_19 ) ;
if ( ! V_2 -> V_16 ) {
F_7 ( V_2 -> V_41 ) ;
return - V_20 ;
}
V_2 -> V_18 = V_4 -> V_10 . V_124 ;
V_2 -> V_13 = 0 ;
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ ) {
V_2 -> V_41 [ V_7 ] . V_40 . V_104 =
F_71 ( V_122 ,
sizeof( struct V_5 * ) ,
V_19 ) ;
if ( ! V_2 -> V_41 [ V_7 ] . V_40 . V_104 )
goto V_125;
V_2 -> V_41 [ V_7 ] . V_40 . V_103 = 0 ;
}
V_7 = 0 ;
F_19 (crtc, dev) {
V_2 -> V_41 [ V_7 ] . V_40 . V_24 = V_24 ;
V_7 ++ ;
}
return 0 ;
V_125:
F_57 ( V_2 ) ;
return - V_20 ;
}
struct V_34 * F_72 ( struct V_1 * V_2 )
{
struct V_126 * V_4 = V_2 -> V_4 -> V_4 ;
struct V_34 * V_35 ;
int V_8 ;
V_35 = F_73 ( 0 , V_4 ) ;
if ( ! V_35 )
return F_74 ( - V_20 ) ;
V_8 = F_75 ( & V_35 -> V_127 , 256 , 0 ) ;
if ( V_8 )
goto V_128;
V_35 -> V_129 = F_76 ( 1 ) ;
if ( ! V_35 -> V_129 ) {
V_8 = - V_20 ;
goto V_130;
}
V_2 -> V_108 = V_35 ;
return V_35 ;
V_130:
F_77 ( & V_35 -> V_127 ) ;
V_128:
F_78 ( V_35 ) ;
return F_74 ( V_8 ) ;
}
void F_79 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_108 )
F_80 ( V_2 -> V_108 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
if ( V_2 ) {
struct V_34 * V_35 = V_2 -> V_108 ;
if ( V_35 ) {
if ( V_35 -> V_127 . V_131 )
F_77 ( & V_35 -> V_127 ) ;
F_78 ( V_35 ) ;
}
V_2 -> V_108 = NULL ;
}
}
void F_82 ( struct V_1 * V_2 )
{
if ( ! V_9 )
return;
if ( ! F_48 ( & V_2 -> V_121 ) ) {
F_83 ( & V_2 -> V_121 ) ;
if ( F_48 ( & V_80 ) ) {
F_84 ( 'v' , & V_132 ) ;
}
}
F_57 ( V_2 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_108 )
F_86 ( V_2 -> V_108 ) ;
}
static void F_87 ( struct V_34 * V_35 , T_2 V_46 , T_2 V_47 ,
T_2 V_133 , T_2 V_134 )
{
struct V_1 * V_25 = V_35 -> V_36 ;
struct V_110 * V_111 = & V_25 -> V_112 ;
unsigned long V_114 ;
if ( ! V_25 -> V_45 -> V_29 -> V_119 )
return;
F_64 ( & V_25 -> V_115 , V_114 ) ;
V_111 -> V_116 = F_88 ( T_2 , V_111 -> V_116 , V_46 ) ;
V_111 -> y1 = F_88 ( T_2 , V_111 -> y1 , V_47 ) ;
V_111 -> V_117 = F_89 ( T_2 , V_111 -> V_117 , V_46 + V_133 ) ;
V_111 -> V_118 = F_89 ( T_2 , V_111 -> V_118 , V_47 + V_134 ) ;
F_65 ( & V_25 -> V_115 , V_114 ) ;
F_51 ( & V_25 -> V_109 ) ;
}
void F_90 ( struct V_34 * V_35 ,
struct V_135 * V_136 )
{
unsigned long V_137 , V_138 , V_139 , V_140 ;
struct V_141 * V_141 ;
T_2 y1 , V_118 ;
V_139 = V_142 ;
V_140 = 0 ;
F_17 (page, pagelist, lru) {
V_137 = V_141 -> V_143 << V_144 ;
V_138 = V_137 + V_145 - 1 ;
V_139 = V_139 ( V_139 , V_137 ) ;
V_140 = V_140 ( V_140 , V_138 ) ;
}
if ( V_139 < V_140 ) {
y1 = V_139 / V_35 -> V_146 . V_147 ;
V_118 = F_88 ( T_2 , F_91 ( V_140 , V_35 -> V_146 . V_147 ) ,
V_35 -> V_148 . V_149 ) ;
F_87 ( V_35 , 0 , y1 , V_35 -> V_148 . V_150 , V_118 - y1 ) ;
}
}
T_3 F_92 ( struct V_34 * V_35 , char T_4 * V_151 ,
T_5 V_152 , T_6 * V_153 )
{
return F_93 ( V_35 , V_151 , V_152 , V_153 ) ;
}
T_3 F_94 ( struct V_34 * V_35 , const char T_4 * V_151 ,
T_5 V_152 , T_6 * V_153 )
{
T_3 V_8 ;
V_8 = F_95 ( V_35 , V_151 , V_152 , V_153 ) ;
if ( V_8 > 0 )
F_87 ( V_35 , 0 , 0 , V_35 -> V_148 . V_150 ,
V_35 -> V_148 . V_149 ) ;
return V_8 ;
}
void F_96 ( struct V_34 * V_35 ,
const struct V_154 * V_155 )
{
F_97 ( V_35 , V_155 ) ;
F_87 ( V_35 , V_155 -> V_156 , V_155 -> V_157 ,
V_155 -> V_133 , V_155 -> V_134 ) ;
}
void F_98 ( struct V_34 * V_35 ,
const struct V_158 * V_159 )
{
F_99 ( V_35 , V_159 ) ;
F_87 ( V_35 , V_159 -> V_156 , V_159 -> V_157 ,
V_159 -> V_133 , V_159 -> V_134 ) ;
}
void F_100 ( struct V_34 * V_35 ,
const struct V_160 * V_161 )
{
F_101 ( V_35 , V_161 ) ;
F_87 ( V_35 , V_161 -> V_156 , V_161 -> V_157 ,
V_161 -> V_133 , V_161 -> V_134 ) ;
}
void F_102 ( struct V_34 * V_35 ,
const struct V_154 * V_155 )
{
F_103 ( V_35 , V_155 ) ;
F_87 ( V_35 , V_155 -> V_156 , V_155 -> V_157 ,
V_155 -> V_133 , V_155 -> V_134 ) ;
}
void F_104 ( struct V_34 * V_35 ,
const struct V_158 * V_159 )
{
F_105 ( V_35 , V_159 ) ;
F_87 ( V_35 , V_159 -> V_156 , V_159 -> V_157 ,
V_159 -> V_133 , V_159 -> V_134 ) ;
}
void F_106 ( struct V_34 * V_35 ,
const struct V_160 * V_161 )
{
F_107 ( V_35 , V_161 ) ;
F_87 ( V_35 , V_161 -> V_156 , V_161 -> V_157 ,
V_161 -> V_133 , V_161 -> V_134 ) ;
}
void F_108 ( struct V_1 * V_2 , bool V_162 )
{
if ( V_2 && V_2 -> V_108 )
F_61 ( V_2 -> V_108 , V_162 ) ;
}
void F_109 ( struct V_1 * V_2 ,
bool V_162 )
{
if ( ! V_2 || ! V_2 -> V_108 )
return;
F_110 ( & V_2 -> V_107 ) ;
if ( V_162 ) {
if ( V_2 -> V_108 -> V_58 != V_163 )
return;
F_60 () ;
} else {
if ( V_2 -> V_108 -> V_58 == V_163 )
return;
if ( ! F_111 () ) {
F_51 ( & V_2 -> V_107 ) ;
return;
}
}
F_61 ( V_2 -> V_108 , V_162 ) ;
F_62 () ;
}
static int F_112 ( struct V_23 * V_24 , T_7 V_164 , T_7 V_165 ,
T_7 V_166 , T_7 V_167 , struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_49 * V_45 = V_2 -> V_45 ;
if ( V_35 -> V_146 . V_168 == V_169 ) {
T_2 * V_170 ;
T_2 V_171 ;
if ( V_167 > 16 )
return - V_22 ;
V_170 = ( T_2 * ) V_35 -> V_172 ;
V_164 >>= ( 16 - V_35 -> V_148 . V_164 . V_173 ) ;
V_165 >>= ( 16 - V_35 -> V_148 . V_165 . V_173 ) ;
V_166 >>= ( 16 - V_35 -> V_148 . V_166 . V_173 ) ;
V_171 = ( V_164 << V_35 -> V_148 . V_164 . V_174 ) |
( V_165 << V_35 -> V_148 . V_165 . V_174 ) |
( V_166 << V_35 -> V_148 . V_166 . V_174 ) ;
if ( V_35 -> V_148 . V_175 . V_173 > 0 ) {
T_2 V_176 = ( 1 << V_35 -> V_148 . V_175 . V_173 ) - 1 ;
V_176 <<= V_35 -> V_148 . V_175 . V_174 ;
V_171 |= V_176 ;
}
V_170 [ V_167 ] = V_171 ;
return 0 ;
}
if ( F_8 ( ! V_2 -> V_29 -> V_33 ||
! V_2 -> V_29 -> V_30 ) )
return - V_22 ;
F_8 ( V_45 -> V_177 != 8 ) ;
V_2 -> V_29 -> V_33 ( V_24 , V_164 , V_165 , V_166 , V_167 ) ;
return 0 ;
}
int F_113 ( struct V_178 * V_127 , struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_37 * V_179 ;
T_7 * V_164 , * V_165 , * V_166 , * V_175 ;
struct V_23 * V_24 ;
int V_7 , V_21 , V_180 = 0 ;
int V_137 ;
if ( V_91 )
return - V_92 ;
F_42 ( V_4 ) ;
if ( ! F_45 ( V_2 ) ) {
F_43 ( V_4 ) ;
return - V_92 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
V_24 = V_2 -> V_41 [ V_7 ] . V_40 . V_24 ;
V_179 = V_24 -> V_43 ;
V_164 = V_127 -> V_164 ;
V_165 = V_127 -> V_165 ;
V_166 = V_127 -> V_166 ;
V_175 = V_127 -> V_175 ;
V_137 = V_127 -> V_137 ;
for ( V_21 = 0 ; V_21 < V_127 -> V_131 ; V_21 ++ ) {
T_7 V_181 , V_182 , V_183 , V_184 = 0xffff ;
V_181 = * V_164 ++ ;
V_182 = * V_165 ++ ;
V_183 = * V_166 ++ ;
if ( V_175 )
V_184 = * V_175 ++ ;
V_180 = F_112 ( V_24 , V_181 , V_182 , V_183 , V_137 ++ , V_35 ) ;
if ( V_180 )
goto V_185;
}
if ( V_179 -> V_186 )
V_179 -> V_186 ( V_24 ) ;
}
V_185:
F_43 ( V_4 ) ;
return V_180 ;
}
int F_114 ( struct V_187 * V_148 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_49 * V_45 = V_2 -> V_45 ;
int V_188 ;
if ( V_148 -> V_189 != 0 || F_115 () )
return - V_22 ;
if ( V_148 -> V_177 > V_45 -> V_177 ||
V_148 -> V_150 > V_45 -> V_133 || V_148 -> V_149 > V_45 -> V_134 ||
V_148 -> V_190 > V_45 -> V_133 || V_148 -> V_191 > V_45 -> V_134 ) {
F_116 ( L_3
L_4 ,
V_148 -> V_150 , V_148 -> V_149 , V_148 -> V_177 ,
V_148 -> V_190 , V_148 -> V_191 ,
V_45 -> V_133 , V_45 -> V_134 , V_45 -> V_177 ) ;
return - V_22 ;
}
switch ( V_148 -> V_177 ) {
case 16 :
V_188 = ( V_148 -> V_165 . V_173 == 6 ) ? 16 : 15 ;
break;
case 32 :
V_188 = ( V_148 -> V_175 . V_173 > 0 ) ? 32 : 24 ;
break;
default:
V_188 = V_148 -> V_177 ;
break;
}
switch ( V_188 ) {
case 8 :
V_148 -> V_164 . V_174 = 0 ;
V_148 -> V_165 . V_174 = 0 ;
V_148 -> V_166 . V_174 = 0 ;
V_148 -> V_164 . V_173 = 8 ;
V_148 -> V_165 . V_173 = 8 ;
V_148 -> V_166 . V_173 = 8 ;
V_148 -> V_175 . V_173 = 0 ;
V_148 -> V_175 . V_174 = 0 ;
break;
case 15 :
V_148 -> V_164 . V_174 = 10 ;
V_148 -> V_165 . V_174 = 5 ;
V_148 -> V_166 . V_174 = 0 ;
V_148 -> V_164 . V_173 = 5 ;
V_148 -> V_165 . V_173 = 5 ;
V_148 -> V_166 . V_173 = 5 ;
V_148 -> V_175 . V_173 = 1 ;
V_148 -> V_175 . V_174 = 15 ;
break;
case 16 :
V_148 -> V_164 . V_174 = 11 ;
V_148 -> V_165 . V_174 = 5 ;
V_148 -> V_166 . V_174 = 0 ;
V_148 -> V_164 . V_173 = 5 ;
V_148 -> V_165 . V_173 = 6 ;
V_148 -> V_166 . V_173 = 5 ;
V_148 -> V_175 . V_173 = 0 ;
V_148 -> V_175 . V_174 = 0 ;
break;
case 24 :
V_148 -> V_164 . V_174 = 16 ;
V_148 -> V_165 . V_174 = 8 ;
V_148 -> V_166 . V_174 = 0 ;
V_148 -> V_164 . V_173 = 8 ;
V_148 -> V_165 . V_173 = 8 ;
V_148 -> V_166 . V_173 = 8 ;
V_148 -> V_175 . V_173 = 0 ;
V_148 -> V_175 . V_174 = 0 ;
break;
case 32 :
V_148 -> V_164 . V_174 = 16 ;
V_148 -> V_165 . V_174 = 8 ;
V_148 -> V_166 . V_174 = 0 ;
V_148 -> V_164 . V_173 = 8 ;
V_148 -> V_165 . V_173 = 8 ;
V_148 -> V_166 . V_173 = 8 ;
V_148 -> V_175 . V_173 = 8 ;
V_148 -> V_175 . V_174 = 24 ;
break;
default:
return - V_22 ;
}
return 0 ;
}
int F_117 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_187 * V_148 = & V_35 -> V_148 ;
if ( V_91 )
return - V_92 ;
if ( V_148 -> V_189 != 0 ) {
F_21 ( L_5 ) ;
return - V_22 ;
}
F_41 ( V_2 ) ;
return 0 ;
}
static int F_118 ( struct V_187 * V_148 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_57 * V_58 ;
struct V_55 * V_56 ;
int V_7 , V_8 ;
unsigned V_59 ;
V_58 = F_23 ( V_4 ) ;
if ( ! V_58 )
return - V_20 ;
V_58 -> V_60 = V_4 -> V_10 . V_60 ;
V_61:
V_59 = 0 ;
for( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
struct V_39 * V_40 ;
V_40 = & V_2 -> V_41 [ V_7 ] . V_40 ;
V_40 -> V_46 = V_148 -> V_192 ;
V_40 -> V_47 = V_148 -> V_193 ;
V_8 = F_30 ( V_40 , V_58 ) ;
if ( V_8 != 0 )
goto V_12;
V_56 = V_40 -> V_24 -> V_53 ;
V_59 |= ( 1 << F_28 ( V_56 ) ) ;
V_56 -> V_66 = V_56 -> V_45 ;
}
V_8 = F_31 ( V_58 ) ;
if ( V_8 != 0 )
goto V_12;
V_35 -> V_148 . V_192 = V_148 -> V_192 ;
V_35 -> V_148 . V_193 = V_148 -> V_193 ;
V_12:
F_32 ( V_4 , V_59 , V_8 ) ;
if ( V_8 == - V_68 )
goto V_69;
if ( V_8 != 0 )
F_33 ( V_58 ) ;
return V_8 ;
V_69:
F_34 ( V_58 ) ;
F_35 ( V_58 ) ;
goto V_61;
}
int F_119 ( struct V_187 * V_148 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_39 * V_102 ;
int V_8 = 0 ;
int V_7 ;
if ( V_91 )
return - V_92 ;
F_42 ( V_4 ) ;
if ( ! F_45 ( V_2 ) ) {
F_43 ( V_4 ) ;
return - V_92 ;
}
if ( V_4 -> V_10 . V_29 -> V_70 ) {
V_8 = F_118 ( V_148 , V_35 ) ;
goto V_194;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
V_102 = & V_2 -> V_41 [ V_7 ] . V_40 ;
V_102 -> V_46 = V_148 -> V_192 ;
V_102 -> V_47 = V_148 -> V_193 ;
if ( V_102 -> V_103 ) {
V_8 = F_40 ( V_102 ) ;
if ( ! V_8 ) {
V_35 -> V_148 . V_192 = V_148 -> V_192 ;
V_35 -> V_148 . V_193 = V_148 -> V_193 ;
}
}
}
V_194:
F_43 ( V_4 ) ;
return V_8 ;
}
static int F_120 ( struct V_1 * V_2 ,
int V_195 )
{
int V_8 = 0 ;
int V_38 = 0 ;
int V_7 ;
struct V_34 * V_35 ;
struct V_196 V_197 ;
int V_32 = 0 ;
memset ( & V_197 , 0 , sizeof( struct V_196 ) ) ;
V_197 . V_198 = 24 ;
V_197 . V_199 = 32 ;
V_197 . V_200 = ( unsigned ) - 1 ;
V_197 . V_201 = ( unsigned ) - 1 ;
if ( V_195 != V_197 . V_199 )
V_197 . V_198 = V_197 . V_199 = V_195 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_14 * V_202 = V_2 -> V_16 [ V_7 ] ;
struct V_203 * V_204 ;
V_204 = & V_202 -> V_6 -> V_204 ;
if ( V_204 -> V_205 ) {
switch ( V_204 -> V_206 ) {
case 8 :
V_197 . V_198 = V_197 . V_199 = 8 ;
break;
case 15 :
V_197 . V_198 = 15 ;
V_197 . V_199 = 16 ;
break;
case 16 :
V_197 . V_198 = V_197 . V_199 = 16 ;
break;
case 24 :
V_197 . V_198 = V_197 . V_199 = 24 ;
break;
case 32 :
V_197 . V_198 = 24 ;
V_197 . V_199 = 32 ;
break;
}
break;
}
}
V_38 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
struct V_207 * V_208 ;
struct V_39 * V_40 ;
int V_46 , V_47 , V_21 ;
bool V_209 = true , V_210 = true ;
V_208 = V_2 -> V_41 [ V_7 ] . V_208 ;
V_40 = & V_2 -> V_41 [ V_7 ] . V_40 ;
if ( ! V_208 )
continue;
V_38 ++ ;
V_46 = V_2 -> V_41 [ V_7 ] . V_46 ;
V_47 = V_2 -> V_41 [ V_7 ] . V_47 ;
if ( V_32 == 0 )
V_32 = V_2 -> V_41 [ V_7 ] . V_40 . V_24 -> V_32 ;
V_197 . V_211 = F_89 ( T_2 , V_208 -> V_212 + V_46 , V_197 . V_211 ) ;
V_197 . V_213 = F_89 ( T_2 , V_208 -> V_214 + V_47 , V_197 . V_213 ) ;
for ( V_21 = 0 ; V_21 < V_40 -> V_103 ; V_21 ++ ) {
struct V_5 * V_6 = V_40 -> V_104 [ V_21 ] ;
if ( V_6 -> V_215 ) {
V_210 = ( V_6 -> V_216 == ( V_6 -> V_217 - 1 ) ) ;
V_209 = ( V_6 -> V_218 == ( V_6 -> V_219 - 1 ) ) ;
break;
}
}
if ( V_210 )
V_197 . V_200 = F_88 ( T_2 , V_208 -> V_212 + V_46 , V_197 . V_200 ) ;
if ( V_209 )
V_197 . V_201 = F_88 ( T_2 , V_208 -> V_214 + V_47 , V_197 . V_201 ) ;
}
if ( V_38 == 0 || V_197 . V_200 == - 1 || V_197 . V_201 == - 1 ) {
F_121 ( L_6 ) ;
V_197 . V_200 = V_197 . V_211 = 1024 ;
V_197 . V_201 = V_197 . V_213 = 768 ;
}
V_8 = (* V_2 -> V_29 -> V_220 )( V_2 , & V_197 ) ;
if ( V_8 < 0 )
return V_8 ;
V_35 = V_2 -> V_108 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ )
if ( V_2 -> V_41 [ V_7 ] . V_40 . V_103 )
V_2 -> V_41 [ V_7 ] . V_40 . V_45 = V_2 -> V_45 ;
V_35 -> V_148 . V_189 = 0 ;
if ( F_122 ( V_35 ) < 0 )
return - V_22 ;
F_123 ( V_2 -> V_4 -> V_4 , L_7 ,
V_35 -> V_221 , V_35 -> V_146 . V_52 ) ;
if ( F_48 ( & V_80 ) ) {
F_124 ( 'v' , & V_132 ) ;
}
F_125 ( & V_2 -> V_121 , & V_80 ) ;
return 0 ;
}
void F_126 ( struct V_34 * V_35 , T_8 V_222 ,
T_8 V_188 )
{
V_35 -> V_146 . type = V_223 ;
V_35 -> V_146 . V_168 = V_188 == 8 ? V_224 :
V_169 ;
V_35 -> V_146 . V_225 = 0 ;
V_35 -> V_146 . V_226 = 0 ;
V_35 -> V_146 . V_227 = 0 ;
V_35 -> V_146 . V_228 = 1 ;
V_35 -> V_146 . V_229 = 1 ;
V_35 -> V_146 . V_230 = 0 ;
V_35 -> V_146 . V_231 = V_232 ;
V_35 -> V_146 . V_147 = V_222 ;
return;
}
void F_127 ( struct V_34 * V_35 , struct V_1 * V_2 ,
T_8 V_200 , T_8 V_201 )
{
struct V_49 * V_45 = V_2 -> V_45 ;
V_35 -> V_172 = V_2 -> V_172 ;
V_35 -> V_148 . V_190 = V_45 -> V_133 ;
V_35 -> V_148 . V_191 = V_45 -> V_134 ;
V_35 -> V_148 . V_177 = V_45 -> V_177 ;
V_35 -> V_148 . V_233 = V_234 ;
V_35 -> V_148 . V_192 = 0 ;
V_35 -> V_148 . V_193 = 0 ;
V_35 -> V_148 . V_235 = V_236 ;
V_35 -> V_148 . V_134 = - 1 ;
V_35 -> V_148 . V_133 = - 1 ;
switch ( V_45 -> V_188 ) {
case 8 :
V_35 -> V_148 . V_164 . V_174 = 0 ;
V_35 -> V_148 . V_165 . V_174 = 0 ;
V_35 -> V_148 . V_166 . V_174 = 0 ;
V_35 -> V_148 . V_164 . V_173 = 8 ;
V_35 -> V_148 . V_165 . V_173 = 8 ;
V_35 -> V_148 . V_166 . V_173 = 8 ;
V_35 -> V_148 . V_175 . V_174 = 0 ;
V_35 -> V_148 . V_175 . V_173 = 0 ;
break;
case 15 :
V_35 -> V_148 . V_164 . V_174 = 10 ;
V_35 -> V_148 . V_165 . V_174 = 5 ;
V_35 -> V_148 . V_166 . V_174 = 0 ;
V_35 -> V_148 . V_164 . V_173 = 5 ;
V_35 -> V_148 . V_165 . V_173 = 5 ;
V_35 -> V_148 . V_166 . V_173 = 5 ;
V_35 -> V_148 . V_175 . V_174 = 15 ;
V_35 -> V_148 . V_175 . V_173 = 1 ;
break;
case 16 :
V_35 -> V_148 . V_164 . V_174 = 11 ;
V_35 -> V_148 . V_165 . V_174 = 5 ;
V_35 -> V_148 . V_166 . V_174 = 0 ;
V_35 -> V_148 . V_164 . V_173 = 5 ;
V_35 -> V_148 . V_165 . V_173 = 6 ;
V_35 -> V_148 . V_166 . V_173 = 5 ;
V_35 -> V_148 . V_175 . V_174 = 0 ;
break;
case 24 :
V_35 -> V_148 . V_164 . V_174 = 16 ;
V_35 -> V_148 . V_165 . V_174 = 8 ;
V_35 -> V_148 . V_166 . V_174 = 0 ;
V_35 -> V_148 . V_164 . V_173 = 8 ;
V_35 -> V_148 . V_165 . V_173 = 8 ;
V_35 -> V_148 . V_166 . V_173 = 8 ;
V_35 -> V_148 . V_175 . V_174 = 0 ;
V_35 -> V_148 . V_175 . V_173 = 0 ;
break;
case 32 :
V_35 -> V_148 . V_164 . V_174 = 16 ;
V_35 -> V_148 . V_165 . V_174 = 8 ;
V_35 -> V_148 . V_166 . V_174 = 0 ;
V_35 -> V_148 . V_164 . V_173 = 8 ;
V_35 -> V_148 . V_165 . V_173 = 8 ;
V_35 -> V_148 . V_166 . V_173 = 8 ;
V_35 -> V_148 . V_175 . V_174 = 24 ;
V_35 -> V_148 . V_175 . V_173 = 8 ;
break;
default:
break;
}
V_35 -> V_148 . V_150 = V_200 ;
V_35 -> V_148 . V_149 = V_201 ;
}
static int F_128 ( struct V_1 * V_2 ,
T_8 V_237 ,
T_8 V_238 )
{
struct V_5 * V_6 ;
int V_152 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_16 [ V_7 ] -> V_6 ;
V_152 += V_6 -> V_29 -> V_239 ( V_6 , V_237 , V_238 ) ;
}
return V_152 ;
}
struct V_207 * F_129 ( struct V_14 * V_240 , int V_133 , int V_134 )
{
struct V_207 * V_105 ;
F_17 (mode, &fb_connector->connector->modes, head) {
if ( V_105 -> V_212 > V_133 ||
V_105 -> V_214 > V_134 )
continue;
if ( V_105 -> type & V_241 )
return V_105 ;
}
return NULL ;
}
static bool F_130 ( struct V_14 * V_240 )
{
return V_240 -> V_6 -> V_204 . V_242 ;
}
struct V_207 * F_131 ( struct V_14 * V_202 ,
int V_133 , int V_134 )
{
struct V_203 * V_204 ;
struct V_207 * V_105 ;
bool V_243 ;
V_204 = & V_202 -> V_6 -> V_204 ;
if ( V_204 -> V_242 == false )
return NULL ;
if ( V_204 -> V_244 || V_204 -> V_245 )
goto V_246;
V_243 = ! V_204 -> V_247 ;
V_248:
F_17 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_105 -> V_212 != V_204 -> V_150 ||
V_105 -> V_214 != V_204 -> V_149 )
continue;
if ( V_204 -> V_249 ) {
if ( V_105 -> V_250 != V_204 -> V_251 )
continue;
}
if ( V_204 -> V_247 ) {
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
V_105 = F_132 ( V_202 -> V_6 -> V_4 ,
V_204 ) ;
F_125 ( & V_105 -> V_253 , & V_202 -> V_6 -> V_254 ) ;
return V_105 ;
}
static bool F_133 ( struct V_5 * V_6 , bool V_255 )
{
bool V_256 ;
if ( V_255 )
V_256 = V_6 -> V_257 == V_258 ;
else
V_256 = V_6 -> V_257 != V_259 ;
return V_256 ;
}
static void F_134 ( struct V_1 * V_2 ,
bool * V_42 )
{
bool V_260 = false ;
struct V_5 * V_6 ;
int V_7 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_16 [ V_7 ] -> V_6 ;
V_42 [ V_7 ] = F_133 ( V_6 , true ) ;
F_135 ( L_8 , V_6 -> V_51 . V_52 ,
V_42 [ V_7 ] ? L_9 : L_10 ) ;
V_260 |= V_42 [ V_7 ] ;
}
if ( V_260 )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_16 [ V_7 ] -> V_6 ;
V_42 [ V_7 ] = F_133 ( V_6 , false ) ;
}
}
static bool F_136 ( struct V_1 * V_2 ,
struct V_207 * * V_254 ,
struct V_261 * V_262 ,
bool * V_42 , int V_133 , int V_134 )
{
int V_152 , V_7 , V_21 ;
bool V_263 = false ;
struct V_14 * V_202 ;
struct V_207 * V_264 , * V_105 ;
if ( V_2 -> V_38 > 1 )
return false ;
V_152 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( V_42 [ V_7 ] )
V_152 ++ ;
}
if ( V_152 <= 1 )
return false ;
V_263 = true ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_42 [ V_7 ] )
continue;
V_202 = V_2 -> V_16 [ V_7 ] ;
V_254 [ V_7 ] = F_131 ( V_202 , V_133 , V_134 ) ;
if ( ! V_254 [ V_7 ] ) {
V_263 = false ;
break;
}
for ( V_21 = 0 ; V_21 < V_7 ; V_21 ++ ) {
if ( ! V_42 [ V_21 ] )
continue;
if ( ! F_137 ( V_254 [ V_21 ] , V_254 [ V_7 ] ) )
V_263 = false ;
}
}
if ( V_263 ) {
F_135 ( L_11 ) ;
return true ;
}
V_263 = true ;
V_264 = F_138 ( V_2 -> V_4 , 1024 , 768 , 60 , false ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_42 [ V_7 ] )
continue;
V_202 = V_2 -> V_16 [ V_7 ] ;
F_17 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_137 ( V_105 , V_264 ) )
V_254 [ V_7 ] = V_105 ;
}
if ( ! V_254 [ V_7 ] )
V_263 = false ;
}
if ( V_263 ) {
F_135 ( L_12 ) ;
return true ;
}
F_121 ( L_13 ) ;
return false ;
}
static int F_139 ( struct V_1 * V_2 ,
struct V_207 * * V_254 ,
struct V_261 * V_262 ,
int V_265 ,
int V_266 , int V_267 )
{
struct V_14 * V_202 ;
int V_7 ;
int V_268 = 0 , V_269 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_202 = V_2 -> V_16 [ V_7 ] ;
if ( ! V_202 -> V_6 -> V_215 )
continue;
if ( ! V_254 [ V_7 ] && ( V_266 || V_267 ) ) {
F_135 ( L_14 , V_7 ,
V_202 -> V_6 -> V_51 . V_52 ) ;
continue;
}
if ( V_202 -> V_6 -> V_216 < V_266 )
V_268 += V_254 [ V_7 ] -> V_212 ;
if ( V_202 -> V_6 -> V_218 < V_267 )
V_269 += V_254 [ V_7 ] -> V_214 ;
}
V_262 [ V_265 ] . V_46 = V_268 ;
V_262 [ V_265 ] . V_47 = V_269 ;
F_135 ( L_15 , V_268 , V_269 , V_266 , V_267 ) ;
return 0 ;
}
static bool F_140 ( struct V_1 * V_2 ,
struct V_207 * * V_254 ,
struct V_261 * V_262 ,
bool * V_42 , int V_133 , int V_134 )
{
struct V_14 * V_202 ;
int V_7 ;
T_9 V_270 = 0 , V_176 ;
int V_271 = 0 ;
V_176 = ( 1 << V_2 -> V_13 ) - 1 ;
V_61:
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_202 = V_2 -> V_16 [ V_7 ] ;
if ( V_270 & ( 1 << V_7 ) )
continue;
if ( V_42 [ V_7 ] == false ) {
V_270 |= ( 1 << V_7 ) ;
continue;
}
if ( V_271 == 0 && V_202 -> V_6 -> V_215 )
continue;
if ( V_271 == 1 ) {
if ( V_202 -> V_6 -> V_216 != 0 ||
V_202 -> V_6 -> V_218 != 0 )
continue;
} else {
if ( V_202 -> V_6 -> V_216 != V_271 - 1 &&
V_202 -> V_6 -> V_218 != V_271 - 1 )
continue;
F_139 ( V_2 , V_254 , V_262 ,
V_7 , V_202 -> V_6 -> V_216 , V_202 -> V_6 -> V_218 ) ;
}
F_135 ( L_16 ,
V_202 -> V_6 -> V_51 . V_52 ) ;
V_254 [ V_7 ] = F_131 ( V_202 , V_133 , V_134 ) ;
if ( ! V_254 [ V_7 ] ) {
F_135 ( L_17 ,
V_202 -> V_6 -> V_51 . V_52 , V_202 -> V_6 -> V_272 ? V_202 -> V_6 -> V_272 -> V_52 : 0 ) ;
V_254 [ V_7 ] = F_129 ( V_202 , V_133 , V_134 ) ;
}
if ( ! V_254 [ V_7 ] && ! F_48 ( & V_202 -> V_6 -> V_254 ) ) {
F_17 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_135 ( L_18 , V_254 [ V_7 ] ? V_254 [ V_7 ] -> V_273 :
L_19 ) ;
V_270 |= ( 1 << V_7 ) ;
}
if ( ( V_270 & V_176 ) != V_176 ) {
V_271 ++ ;
goto V_61;
}
return true ;
}
static int F_141 ( struct V_1 * V_2 ,
struct V_123 * * V_274 ,
struct V_207 * * V_254 ,
int V_275 , int V_133 , int V_134 )
{
int V_50 , V_276 ;
struct V_5 * V_6 ;
const struct V_277 * V_278 ;
struct V_279 * V_280 ;
int V_281 , V_282 , V_283 ;
struct V_123 * * V_284 , * V_24 ;
struct V_14 * V_202 ;
if ( V_275 == V_2 -> V_13 )
return 0 ;
V_202 = V_2 -> V_16 [ V_275 ] ;
V_6 = V_202 -> V_6 ;
V_274 [ V_275 ] = NULL ;
V_282 = F_141 ( V_2 , V_274 , V_254 , V_275 + 1 , V_133 , V_134 ) ;
if ( V_254 [ V_275 ] == NULL )
return V_282 ;
V_284 = F_11 ( V_2 -> V_13 *
sizeof( struct V_123 * ) , V_19 ) ;
if ( ! V_284 )
return V_282 ;
V_281 = 1 ;
if ( V_6 -> V_257 == V_258 )
V_281 ++ ;
if ( F_130 ( V_202 ) )
V_281 ++ ;
if ( F_129 ( V_202 , V_133 , V_134 ) )
V_281 ++ ;
V_278 = V_6 -> V_43 ;
if ( V_2 -> V_4 -> V_10 . V_29 -> V_70 &&
! V_278 -> V_285 )
V_280 = F_142 ( V_6 ) ;
else
V_280 = V_278 -> V_285 ( V_6 ) ;
if ( ! V_280 )
goto V_185;
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
if ( ! F_137 ( V_254 [ V_276 ] , V_254 [ V_275 ] ) )
continue;
}
V_284 [ V_275 ] = V_24 ;
memcpy ( V_284 , V_274 , V_275 * sizeof( struct V_123 * ) ) ;
V_283 = V_281 + F_141 ( V_2 , V_284 , V_254 , V_275 + 1 ,
V_133 , V_134 ) ;
if ( V_283 > V_282 ) {
V_282 = V_283 ;
memcpy ( V_274 , V_284 ,
V_2 -> V_13 *
sizeof( struct V_123 * ) ) ;
}
}
V_185:
F_7 ( V_284 ) ;
return V_282 ;
}
static void F_143 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_123 * * V_284 ;
struct V_207 * * V_254 ;
struct V_261 * V_262 ;
bool * V_42 ;
int V_133 , V_134 ;
int V_7 ;
F_135 ( L_20 ) ;
V_133 = V_4 -> V_10 . V_287 ;
V_134 = V_4 -> V_10 . V_288 ;
V_284 = F_71 ( V_2 -> V_13 ,
sizeof( struct V_123 * ) , V_19 ) ;
V_254 = F_71 ( V_2 -> V_13 ,
sizeof( struct V_207 * ) , V_19 ) ;
V_262 = F_71 ( V_2 -> V_13 ,
sizeof( struct V_261 ) , V_19 ) ;
V_42 = F_71 ( V_2 -> V_13 ,
sizeof( bool ) , V_19 ) ;
if ( ! V_284 || ! V_254 || ! V_42 || ! V_262 ) {
F_21 ( L_21 ) ;
goto V_185;
}
F_134 ( V_2 , V_42 ) ;
if ( ! ( V_2 -> V_29 -> V_289 &&
V_2 -> V_29 -> V_289 ( V_2 , V_284 , V_254 ,
V_262 ,
V_42 , V_133 , V_134 ) ) ) {
memset ( V_254 , 0 , V_2 -> V_13 * sizeof( V_254 [ 0 ] ) ) ;
memset ( V_284 , 0 , V_2 -> V_13 * sizeof( V_284 [ 0 ] ) ) ;
memset ( V_262 , 0 , V_2 -> V_13 * sizeof( V_262 [ 0 ] ) ) ;
if ( ! F_136 ( V_2 , V_254 , V_262 ,
V_42 , V_133 , V_134 ) &&
! F_140 ( V_2 , V_254 , V_262 ,
V_42 , V_133 , V_134 ) )
F_21 ( L_22 ) ;
F_135 ( L_23 ,
V_133 , V_134 ) ;
F_141 ( V_2 , V_284 , V_254 , 0 , V_133 , V_134 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ )
F_55 ( V_2 ,
& V_2 -> V_41 [ V_7 ] . V_40 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_207 * V_105 = V_254 [ V_7 ] ;
struct V_123 * V_290 = V_284 [ V_7 ] ;
struct V_261 * V_174 = & V_262 [ V_7 ] ;
struct V_39 * V_102 = & V_290 -> V_40 ;
if ( V_105 && V_290 ) {
struct V_5 * V_6 =
V_2 -> V_16 [ V_7 ] -> V_6 ;
F_135 ( L_24 ,
V_105 -> V_273 , V_290 -> V_40 . V_24 -> V_51 . V_52 , V_174 -> V_46 , V_174 -> V_47 ) ;
V_290 -> V_208 = V_105 ;
V_290 -> V_46 = V_174 -> V_46 ;
V_290 -> V_47 = V_174 -> V_47 ;
V_102 -> V_105 = F_144 ( V_4 ,
V_290 -> V_208 ) ;
F_12 ( V_6 ) ;
V_102 -> V_104 [ V_102 -> V_103 ++ ] = V_6 ;
V_102 -> V_45 = V_2 -> V_45 ;
V_102 -> V_46 = V_174 -> V_46 ;
V_102 -> V_47 = V_174 -> V_47 ;
}
}
V_185:
F_7 ( V_284 ) ;
F_7 ( V_254 ) ;
F_7 ( V_262 ) ;
F_7 ( V_42 ) ;
}
int F_145 ( struct V_1 * V_2 , int V_291 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_152 = 0 ;
if ( ! V_9 )
return 0 ;
F_2 ( & V_4 -> V_10 . V_11 ) ;
V_152 = F_128 ( V_2 ,
V_4 -> V_10 . V_287 ,
V_4 -> V_10 . V_288 ) ;
F_5 ( & V_4 -> V_10 . V_11 ) ;
if ( V_152 == 0 )
F_123 ( V_2 -> V_4 -> V_4 , L_25 ) ;
F_143 ( V_2 ) ;
return F_120 ( V_2 , V_291 ) ;
}
int F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_287 , V_288 ;
if ( ! V_9 )
return 0 ;
F_2 ( & V_2 -> V_4 -> V_10 . V_11 ) ;
if ( ! V_2 -> V_45 || ! F_45 ( V_2 ) ) {
V_2 -> V_76 = true ;
F_5 ( & V_2 -> V_4 -> V_10 . V_11 ) ;
return 0 ;
}
F_135 ( L_20 ) ;
V_287 = V_2 -> V_45 -> V_133 ;
V_288 = V_2 -> V_45 -> V_134 ;
F_128 ( V_2 , V_287 , V_288 ) ;
F_5 ( & V_2 -> V_4 -> V_10 . V_11 ) ;
F_42 ( V_4 ) ;
F_143 ( V_2 ) ;
F_43 ( V_4 ) ;
F_117 ( V_2 -> V_108 ) ;
return 0 ;
}
int T_10 F_146 ( void )
{
#if F_147 ( V_292 ) && ! F_147 ( V_293 )
const char * V_273 = L_26 ;
struct V_294 * V_295 ;
F_2 ( & V_296 ) ;
V_295 = F_148 ( V_273 ) ;
F_5 ( & V_296 ) ;
if ( ! V_295 )
F_149 ( V_273 ) ;
#endif
return 0 ;
}
