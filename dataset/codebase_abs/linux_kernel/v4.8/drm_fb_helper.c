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
F_6 ( V_2 -> V_14 [ V_7 ] ) ;
V_2 -> V_14 [ V_7 ] = NULL ;
}
V_2 -> V_13 = 0 ;
F_5 ( & V_4 -> V_10 . V_11 ) ;
return V_8 ;
}
int F_4 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_15 * * V_16 ;
struct V_15 * V_17 ;
if ( ! V_9 )
return 0 ;
F_7 ( ! F_8 ( & V_2 -> V_4 -> V_10 . V_11 ) ) ;
if ( V_2 -> V_13 + 1 > V_2 -> V_18 ) {
V_16 = F_9 ( V_2 -> V_14 , sizeof( struct V_15 * ) * ( V_2 -> V_13 + 1 ) , V_19 ) ;
if ( ! V_16 )
return - V_20 ;
V_2 -> V_18 = V_2 -> V_13 + 1 ;
V_2 -> V_14 = V_16 ;
}
V_17 = F_10 ( sizeof( struct V_15 ) , V_19 ) ;
if ( ! V_17 )
return - V_20 ;
F_11 ( V_6 ) ;
V_17 -> V_6 = V_6 ;
V_2 -> V_14 [ V_2 -> V_13 ++ ] = V_17 ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_15 * V_17 ;
int V_7 , V_21 ;
if ( ! V_9 )
return 0 ;
F_7 ( ! F_8 ( & V_2 -> V_4 -> V_10 . V_11 ) ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( V_2 -> V_14 [ V_7 ] -> V_6 == V_6 )
break;
}
if ( V_7 == V_2 -> V_13 )
return - V_22 ;
V_17 = V_2 -> V_14 [ V_7 ] ;
F_13 ( V_17 -> V_6 ) ;
for ( V_21 = V_7 + 1 ; V_21 < V_2 -> V_13 ; V_21 ++ ) {
V_2 -> V_14 [ V_21 - 1 ] = V_2 -> V_14 [ V_21 ] ;
}
V_2 -> V_13 -- ;
F_6 ( V_17 ) ;
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
V_63 -> V_64 = F_28 ( V_65 ) ;
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
if ( V_8 != 0 )
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
return F_22 ( V_2 ) ;
F_24 (plane, dev) {
if ( V_56 -> type != V_67 )
F_39 ( V_56 ) ;
if ( V_4 -> V_10 . V_71 ) {
F_40 ( V_56 ,
V_4 -> V_10 . V_71 ,
F_28 ( V_65 ) ) ;
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
static bool F_48 ( void )
{
bool V_8 , error = false ;
struct V_1 * V_25 ;
if ( F_49 ( & V_80 ) )
return false ;
F_17 (helper, &kernel_fb_helper_list, kernel_fb_list) {
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
F_21 ( L_2 ) ;
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
for ( V_21 = 0 ; V_21 < V_2 -> V_13 ; V_21 ++ ) {
V_6 = V_2 -> V_14 [ V_21 ] -> V_6 ;
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
static void F_56 ( struct V_1 * V_25 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_25 -> V_13 ; V_7 ++ ) {
F_13 ( V_25 -> V_14 [ V_7 ] -> V_6 ) ;
F_6 ( V_25 -> V_14 [ V_7 ] ) ;
}
F_6 ( V_25 -> V_14 ) ;
for ( V_7 = 0 ; V_7 < V_25 -> V_38 ; V_7 ++ ) {
F_6 ( V_25 -> V_41 [ V_7 ] . V_40 . V_102 ) ;
if ( V_25 -> V_41 [ V_7 ] . V_40 . V_103 )
F_57 ( V_25 -> V_4 , V_25 -> V_41 [ V_7 ] . V_40 . V_103 ) ;
}
F_6 ( V_25 -> V_41 ) ;
}
static void F_58 ( struct V_83 * V_104 )
{
struct V_1 * V_25 = F_59 ( V_104 , struct V_1 ,
V_105 ) ;
struct V_106 * V_107 = & V_25 -> V_108 ;
struct V_106 V_109 ;
unsigned long V_110 ;
F_60 ( & V_25 -> V_111 , V_110 ) ;
V_109 = * V_107 ;
V_107 -> V_112 = V_107 -> y1 = ~ 0 ;
V_107 -> V_113 = V_107 -> V_114 = 0 ;
F_61 ( & V_25 -> V_111 , V_110 ) ;
V_25 -> V_45 -> V_29 -> V_115 ( V_25 -> V_45 , NULL , 0 , 0 , & V_109 , 1 ) ;
}
void F_62 ( struct V_3 * V_4 , struct V_1 * V_25 ,
const struct V_116 * V_29 )
{
F_63 ( & V_25 -> V_117 ) ;
F_64 ( & V_25 -> V_111 ) ;
F_65 ( & V_25 -> V_105 , F_58 ) ;
V_25 -> V_108 . V_112 = V_25 -> V_108 . y1 = ~ 0 ;
V_25 -> V_29 = V_29 ;
V_25 -> V_4 = V_4 ;
}
int F_66 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_38 , int V_118 )
{
struct V_23 * V_24 ;
int V_7 ;
if ( ! V_9 )
return 0 ;
if ( ! V_118 )
return - V_22 ;
V_2 -> V_41 = F_67 ( V_38 , sizeof( struct V_119 ) , V_19 ) ;
if ( ! V_2 -> V_41 )
return - V_20 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_14 = F_67 ( V_4 -> V_10 . V_120 , sizeof( struct V_15 * ) , V_19 ) ;
if ( ! V_2 -> V_14 ) {
F_6 ( V_2 -> V_41 ) ;
return - V_20 ;
}
V_2 -> V_18 = V_4 -> V_10 . V_120 ;
V_2 -> V_13 = 0 ;
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ ) {
V_2 -> V_41 [ V_7 ] . V_40 . V_102 =
F_67 ( V_118 ,
sizeof( struct V_5 * ) ,
V_19 ) ;
if ( ! V_2 -> V_41 [ V_7 ] . V_40 . V_102 )
goto V_121;
V_2 -> V_41 [ V_7 ] . V_40 . V_122 = 0 ;
}
V_7 = 0 ;
F_19 (crtc, dev) {
V_2 -> V_41 [ V_7 ] . V_40 . V_24 = V_24 ;
V_7 ++ ;
}
return 0 ;
V_121:
F_56 ( V_2 ) ;
return - V_20 ;
}
struct V_34 * F_68 ( struct V_1 * V_2 )
{
struct V_123 * V_4 = V_2 -> V_4 -> V_4 ;
struct V_34 * V_35 ;
int V_8 ;
V_35 = F_69 ( 0 , V_4 ) ;
if ( ! V_35 )
return F_70 ( - V_20 ) ;
V_8 = F_71 ( & V_35 -> V_124 , 256 , 0 ) ;
if ( V_8 )
goto V_125;
V_35 -> V_126 = F_72 ( 1 ) ;
if ( ! V_35 -> V_126 ) {
V_8 = - V_20 ;
goto V_127;
}
V_2 -> V_128 = V_35 ;
return V_35 ;
V_127:
F_73 ( & V_35 -> V_124 ) ;
V_125:
F_74 ( V_35 ) ;
return F_70 ( V_8 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_128 )
F_76 ( V_2 -> V_128 ) ;
}
void F_77 ( struct V_1 * V_2 )
{
if ( V_2 ) {
struct V_34 * V_35 = V_2 -> V_128 ;
if ( V_35 ) {
if ( V_35 -> V_124 . V_129 )
F_73 ( & V_35 -> V_124 ) ;
F_74 ( V_35 ) ;
}
V_2 -> V_128 = NULL ;
}
}
void F_78 ( struct V_1 * V_2 )
{
if ( ! V_9 )
return;
if ( ! F_49 ( & V_2 -> V_117 ) ) {
F_79 ( & V_2 -> V_117 ) ;
if ( F_49 ( & V_80 ) ) {
F_80 ( 'v' , & V_130 ) ;
}
}
F_56 ( V_2 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_128 )
F_82 ( V_2 -> V_128 ) ;
}
static void F_83 ( struct V_34 * V_35 , T_2 V_46 , T_2 V_47 ,
T_2 V_131 , T_2 V_132 )
{
struct V_1 * V_25 = V_35 -> V_36 ;
struct V_106 * V_107 = & V_25 -> V_108 ;
unsigned long V_110 ;
if ( ! V_25 -> V_45 -> V_29 -> V_115 )
return;
F_60 ( & V_25 -> V_111 , V_110 ) ;
V_107 -> V_112 = F_84 ( T_2 , V_107 -> V_112 , V_46 ) ;
V_107 -> y1 = F_84 ( T_2 , V_107 -> y1 , V_47 ) ;
V_107 -> V_113 = F_85 ( T_2 , V_107 -> V_113 , V_46 + V_131 ) ;
V_107 -> V_114 = F_85 ( T_2 , V_107 -> V_114 , V_47 + V_132 ) ;
F_61 ( & V_25 -> V_111 , V_110 ) ;
F_52 ( & V_25 -> V_105 ) ;
}
void F_86 ( struct V_34 * V_35 ,
struct V_133 * V_134 )
{
unsigned long V_135 , V_136 , V_137 , V_138 ;
struct V_139 * V_139 ;
T_2 y1 , V_114 ;
V_137 = V_140 ;
V_138 = 0 ;
F_17 (page, pagelist, lru) {
V_135 = V_139 -> V_141 << V_142 ;
V_136 = V_135 + V_143 - 1 ;
V_137 = V_137 ( V_137 , V_135 ) ;
V_138 = V_138 ( V_138 , V_136 ) ;
}
if ( V_137 < V_138 ) {
y1 = V_137 / V_35 -> V_144 . V_145 ;
V_114 = F_84 ( T_2 , F_87 ( V_138 , V_35 -> V_144 . V_145 ) ,
V_35 -> V_146 . V_147 ) ;
F_83 ( V_35 , 0 , y1 , V_35 -> V_146 . V_148 , V_114 - y1 ) ;
}
}
T_3 F_88 ( struct V_34 * V_35 , char T_4 * V_149 ,
T_5 V_150 , T_6 * V_151 )
{
return F_89 ( V_35 , V_149 , V_150 , V_151 ) ;
}
T_3 F_90 ( struct V_34 * V_35 , const char T_4 * V_149 ,
T_5 V_150 , T_6 * V_151 )
{
T_3 V_8 ;
V_8 = F_91 ( V_35 , V_149 , V_150 , V_151 ) ;
if ( V_8 > 0 )
F_83 ( V_35 , 0 , 0 , V_35 -> V_146 . V_148 ,
V_35 -> V_146 . V_147 ) ;
return V_8 ;
}
void F_92 ( struct V_34 * V_35 ,
const struct V_152 * V_153 )
{
F_93 ( V_35 , V_153 ) ;
F_83 ( V_35 , V_153 -> V_154 , V_153 -> V_155 ,
V_153 -> V_131 , V_153 -> V_132 ) ;
}
void F_94 ( struct V_34 * V_35 ,
const struct V_156 * V_157 )
{
F_95 ( V_35 , V_157 ) ;
F_83 ( V_35 , V_157 -> V_154 , V_157 -> V_155 ,
V_157 -> V_131 , V_157 -> V_132 ) ;
}
void F_96 ( struct V_34 * V_35 ,
const struct V_158 * V_159 )
{
F_97 ( V_35 , V_159 ) ;
F_83 ( V_35 , V_159 -> V_154 , V_159 -> V_155 ,
V_159 -> V_131 , V_159 -> V_132 ) ;
}
void F_98 ( struct V_34 * V_35 ,
const struct V_152 * V_153 )
{
F_99 ( V_35 , V_153 ) ;
F_83 ( V_35 , V_153 -> V_154 , V_153 -> V_155 ,
V_153 -> V_131 , V_153 -> V_132 ) ;
}
void F_100 ( struct V_34 * V_35 ,
const struct V_156 * V_157 )
{
F_101 ( V_35 , V_157 ) ;
F_83 ( V_35 , V_157 -> V_154 , V_157 -> V_155 ,
V_157 -> V_131 , V_157 -> V_132 ) ;
}
void F_102 ( struct V_34 * V_35 ,
const struct V_158 * V_159 )
{
F_103 ( V_35 , V_159 ) ;
F_83 ( V_35 , V_159 -> V_154 , V_159 -> V_155 ,
V_159 -> V_131 , V_159 -> V_132 ) ;
}
void F_104 ( struct V_1 * V_2 , int V_58 )
{
if ( V_2 && V_2 -> V_128 )
F_105 ( V_2 -> V_128 , V_58 ) ;
}
static int F_106 ( struct V_23 * V_24 , T_7 V_160 , T_7 V_161 ,
T_7 V_162 , T_7 V_163 , struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_49 * V_45 = V_2 -> V_45 ;
if ( V_35 -> V_144 . V_164 == V_165 ) {
T_2 * V_166 ;
T_2 V_167 ;
if ( V_163 > 16 )
return - V_22 ;
V_166 = ( T_2 * ) V_35 -> V_168 ;
V_160 >>= ( 16 - V_35 -> V_146 . V_160 . V_169 ) ;
V_161 >>= ( 16 - V_35 -> V_146 . V_161 . V_169 ) ;
V_162 >>= ( 16 - V_35 -> V_146 . V_162 . V_169 ) ;
V_167 = ( V_160 << V_35 -> V_146 . V_160 . V_170 ) |
( V_161 << V_35 -> V_146 . V_161 . V_170 ) |
( V_162 << V_35 -> V_146 . V_162 . V_170 ) ;
if ( V_35 -> V_146 . V_171 . V_169 > 0 ) {
T_2 V_172 = ( 1 << V_35 -> V_146 . V_171 . V_169 ) - 1 ;
V_172 <<= V_35 -> V_146 . V_171 . V_170 ;
V_167 |= V_172 ;
}
V_166 [ V_163 ] = V_167 ;
return 0 ;
}
if ( F_7 ( ! V_2 -> V_29 -> V_33 ||
! V_2 -> V_29 -> V_30 ) )
return - V_22 ;
F_7 ( V_45 -> V_173 != 8 ) ;
V_2 -> V_29 -> V_33 ( V_24 , V_160 , V_161 , V_162 , V_163 ) ;
return 0 ;
}
int F_107 ( struct V_174 * V_124 , struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_37 * V_175 ;
T_7 * V_160 , * V_161 , * V_162 , * V_171 ;
struct V_23 * V_24 ;
int V_7 , V_21 , V_176 = 0 ;
int V_135 ;
if ( V_91 )
return - V_92 ;
F_43 ( V_4 ) ;
if ( ! F_46 ( V_2 ) ) {
F_44 ( V_4 ) ;
return - V_92 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
V_24 = V_2 -> V_41 [ V_7 ] . V_40 . V_24 ;
V_175 = V_24 -> V_43 ;
V_160 = V_124 -> V_160 ;
V_161 = V_124 -> V_161 ;
V_162 = V_124 -> V_162 ;
V_171 = V_124 -> V_171 ;
V_135 = V_124 -> V_135 ;
for ( V_21 = 0 ; V_21 < V_124 -> V_129 ; V_21 ++ ) {
T_7 V_177 , V_178 , V_179 , V_180 = 0xffff ;
V_177 = * V_160 ++ ;
V_178 = * V_161 ++ ;
V_179 = * V_162 ++ ;
if ( V_171 )
V_180 = * V_171 ++ ;
V_176 = F_106 ( V_24 , V_177 , V_178 , V_179 , V_135 ++ , V_35 ) ;
if ( V_176 )
goto V_181;
}
if ( V_175 -> V_182 )
V_175 -> V_182 ( V_24 ) ;
}
V_181:
F_44 ( V_4 ) ;
return V_176 ;
}
int F_108 ( struct V_183 * V_146 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_49 * V_45 = V_2 -> V_45 ;
int V_184 ;
if ( V_146 -> V_185 != 0 || F_109 () )
return - V_22 ;
if ( V_146 -> V_173 > V_45 -> V_173 ||
V_146 -> V_148 > V_45 -> V_131 || V_146 -> V_147 > V_45 -> V_132 ||
V_146 -> V_186 > V_45 -> V_131 || V_146 -> V_187 > V_45 -> V_132 ) {
F_110 ( L_3
L_4 ,
V_146 -> V_148 , V_146 -> V_147 , V_146 -> V_173 ,
V_146 -> V_186 , V_146 -> V_187 ,
V_45 -> V_131 , V_45 -> V_132 , V_45 -> V_173 ) ;
return - V_22 ;
}
switch ( V_146 -> V_173 ) {
case 16 :
V_184 = ( V_146 -> V_161 . V_169 == 6 ) ? 16 : 15 ;
break;
case 32 :
V_184 = ( V_146 -> V_171 . V_169 > 0 ) ? 32 : 24 ;
break;
default:
V_184 = V_146 -> V_173 ;
break;
}
switch ( V_184 ) {
case 8 :
V_146 -> V_160 . V_170 = 0 ;
V_146 -> V_161 . V_170 = 0 ;
V_146 -> V_162 . V_170 = 0 ;
V_146 -> V_160 . V_169 = 8 ;
V_146 -> V_161 . V_169 = 8 ;
V_146 -> V_162 . V_169 = 8 ;
V_146 -> V_171 . V_169 = 0 ;
V_146 -> V_171 . V_170 = 0 ;
break;
case 15 :
V_146 -> V_160 . V_170 = 10 ;
V_146 -> V_161 . V_170 = 5 ;
V_146 -> V_162 . V_170 = 0 ;
V_146 -> V_160 . V_169 = 5 ;
V_146 -> V_161 . V_169 = 5 ;
V_146 -> V_162 . V_169 = 5 ;
V_146 -> V_171 . V_169 = 1 ;
V_146 -> V_171 . V_170 = 15 ;
break;
case 16 :
V_146 -> V_160 . V_170 = 11 ;
V_146 -> V_161 . V_170 = 5 ;
V_146 -> V_162 . V_170 = 0 ;
V_146 -> V_160 . V_169 = 5 ;
V_146 -> V_161 . V_169 = 6 ;
V_146 -> V_162 . V_169 = 5 ;
V_146 -> V_171 . V_169 = 0 ;
V_146 -> V_171 . V_170 = 0 ;
break;
case 24 :
V_146 -> V_160 . V_170 = 16 ;
V_146 -> V_161 . V_170 = 8 ;
V_146 -> V_162 . V_170 = 0 ;
V_146 -> V_160 . V_169 = 8 ;
V_146 -> V_161 . V_169 = 8 ;
V_146 -> V_162 . V_169 = 8 ;
V_146 -> V_171 . V_169 = 0 ;
V_146 -> V_171 . V_170 = 0 ;
break;
case 32 :
V_146 -> V_160 . V_170 = 16 ;
V_146 -> V_161 . V_170 = 8 ;
V_146 -> V_162 . V_170 = 0 ;
V_146 -> V_160 . V_169 = 8 ;
V_146 -> V_161 . V_169 = 8 ;
V_146 -> V_162 . V_169 = 8 ;
V_146 -> V_171 . V_169 = 8 ;
V_146 -> V_171 . V_170 = 24 ;
break;
default:
return - V_22 ;
}
return 0 ;
}
int F_111 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_183 * V_146 = & V_35 -> V_146 ;
if ( V_91 )
return - V_92 ;
if ( V_146 -> V_185 != 0 ) {
F_21 ( L_5 ) ;
return - V_22 ;
}
F_42 ( V_2 ) ;
return 0 ;
}
static int F_112 ( struct V_183 * V_146 ,
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
V_40 -> V_46 = V_146 -> V_188 ;
V_40 -> V_47 = V_146 -> V_189 ;
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
V_35 -> V_146 . V_188 = V_146 -> V_188 ;
V_35 -> V_146 . V_189 = V_146 -> V_189 ;
V_12:
F_33 ( V_4 , V_59 , V_8 ) ;
if ( V_8 == - V_68 )
goto V_69;
if ( V_8 != 0 )
F_34 ( V_58 ) ;
return V_8 ;
V_69:
F_35 ( V_58 ) ;
F_36 ( V_58 ) ;
goto V_61;
}
int F_113 ( struct V_183 * V_146 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_39 * V_190 ;
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
V_8 = F_112 ( V_146 , V_35 ) ;
goto V_191;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
V_190 = & V_2 -> V_41 [ V_7 ] . V_40 ;
V_190 -> V_46 = V_146 -> V_188 ;
V_190 -> V_47 = V_146 -> V_189 ;
if ( V_190 -> V_122 ) {
V_8 = F_41 ( V_190 ) ;
if ( ! V_8 ) {
V_35 -> V_146 . V_188 = V_146 -> V_188 ;
V_35 -> V_146 . V_189 = V_146 -> V_189 ;
}
}
}
V_191:
F_44 ( V_4 ) ;
return V_8 ;
}
static int F_114 ( struct V_1 * V_2 ,
int V_192 )
{
int V_8 = 0 ;
int V_38 = 0 ;
int V_7 ;
struct V_34 * V_35 ;
struct V_193 V_194 ;
int V_32 = 0 ;
memset ( & V_194 , 0 , sizeof( struct V_193 ) ) ;
V_194 . V_195 = 24 ;
V_194 . V_196 = 32 ;
V_194 . V_197 = ( unsigned ) - 1 ;
V_194 . V_198 = ( unsigned ) - 1 ;
if ( V_192 != V_194 . V_196 )
V_194 . V_195 = V_194 . V_196 = V_192 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_15 * V_199 = V_2 -> V_14 [ V_7 ] ;
struct V_200 * V_201 ;
V_201 = & V_199 -> V_6 -> V_201 ;
if ( V_201 -> V_202 ) {
switch ( V_201 -> V_203 ) {
case 8 :
V_194 . V_195 = V_194 . V_196 = 8 ;
break;
case 15 :
V_194 . V_195 = 15 ;
V_194 . V_196 = 16 ;
break;
case 16 :
V_194 . V_195 = V_194 . V_196 = 16 ;
break;
case 24 :
V_194 . V_195 = V_194 . V_196 = 24 ;
break;
case 32 :
V_194 . V_195 = 24 ;
V_194 . V_196 = 32 ;
break;
}
break;
}
}
V_38 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
struct V_204 * V_205 ;
struct V_39 * V_40 ;
int V_46 , V_47 , V_21 ;
bool V_206 = true , V_207 = true ;
V_205 = V_2 -> V_41 [ V_7 ] . V_205 ;
V_40 = & V_2 -> V_41 [ V_7 ] . V_40 ;
if ( ! V_205 )
continue;
V_38 ++ ;
V_46 = V_2 -> V_41 [ V_7 ] . V_46 ;
V_47 = V_2 -> V_41 [ V_7 ] . V_47 ;
if ( V_32 == 0 )
V_32 = V_2 -> V_41 [ V_7 ] . V_40 . V_24 -> V_32 ;
V_194 . V_208 = F_85 ( T_2 , V_205 -> V_209 + V_46 , V_194 . V_208 ) ;
V_194 . V_210 = F_85 ( T_2 , V_205 -> V_211 + V_47 , V_194 . V_210 ) ;
for ( V_21 = 0 ; V_21 < V_40 -> V_122 ; V_21 ++ ) {
struct V_5 * V_6 = V_40 -> V_102 [ V_21 ] ;
if ( V_6 -> V_212 ) {
V_207 = ( V_6 -> V_213 == ( V_6 -> V_214 - 1 ) ) ;
V_206 = ( V_6 -> V_215 == ( V_6 -> V_216 - 1 ) ) ;
break;
}
}
if ( V_207 )
V_194 . V_197 = F_84 ( T_2 , V_205 -> V_209 + V_46 , V_194 . V_197 ) ;
if ( V_206 )
V_194 . V_198 = F_84 ( T_2 , V_205 -> V_211 + V_47 , V_194 . V_198 ) ;
}
if ( V_38 == 0 || V_194 . V_197 == - 1 || V_194 . V_198 == - 1 ) {
F_115 ( L_6 ) ;
V_194 . V_197 = V_194 . V_208 = 1024 ;
V_194 . V_198 = V_194 . V_210 = 768 ;
}
V_8 = (* V_2 -> V_29 -> V_217 )( V_2 , & V_194 ) ;
if ( V_8 < 0 )
return V_8 ;
V_35 = V_2 -> V_128 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ )
if ( V_2 -> V_41 [ V_7 ] . V_40 . V_122 )
V_2 -> V_41 [ V_7 ] . V_40 . V_45 = V_2 -> V_45 ;
V_35 -> V_146 . V_185 = 0 ;
if ( F_116 ( V_35 ) < 0 )
return - V_22 ;
F_117 ( V_2 -> V_4 -> V_4 , L_7 ,
V_35 -> V_218 , V_35 -> V_144 . V_52 ) ;
if ( F_49 ( & V_80 ) ) {
F_118 ( 'v' , & V_130 ) ;
}
F_119 ( & V_2 -> V_117 , & V_80 ) ;
return 0 ;
}
void F_120 ( struct V_34 * V_35 , T_8 V_219 ,
T_8 V_184 )
{
V_35 -> V_144 . type = V_220 ;
V_35 -> V_144 . V_164 = V_184 == 8 ? V_221 :
V_165 ;
V_35 -> V_144 . V_222 = 0 ;
V_35 -> V_144 . V_223 = 0 ;
V_35 -> V_144 . V_224 = 0 ;
V_35 -> V_144 . V_225 = 1 ;
V_35 -> V_144 . V_226 = 1 ;
V_35 -> V_144 . V_227 = 0 ;
V_35 -> V_144 . V_228 = V_229 ;
V_35 -> V_144 . V_145 = V_219 ;
return;
}
void F_121 ( struct V_34 * V_35 , struct V_1 * V_2 ,
T_8 V_197 , T_8 V_198 )
{
struct V_49 * V_45 = V_2 -> V_45 ;
V_35 -> V_168 = V_2 -> V_168 ;
V_35 -> V_146 . V_186 = V_45 -> V_131 ;
V_35 -> V_146 . V_187 = V_45 -> V_132 ;
V_35 -> V_146 . V_173 = V_45 -> V_173 ;
V_35 -> V_146 . V_230 = V_231 ;
V_35 -> V_146 . V_188 = 0 ;
V_35 -> V_146 . V_189 = 0 ;
V_35 -> V_146 . V_232 = V_233 ;
V_35 -> V_146 . V_132 = - 1 ;
V_35 -> V_146 . V_131 = - 1 ;
switch ( V_45 -> V_184 ) {
case 8 :
V_35 -> V_146 . V_160 . V_170 = 0 ;
V_35 -> V_146 . V_161 . V_170 = 0 ;
V_35 -> V_146 . V_162 . V_170 = 0 ;
V_35 -> V_146 . V_160 . V_169 = 8 ;
V_35 -> V_146 . V_161 . V_169 = 8 ;
V_35 -> V_146 . V_162 . V_169 = 8 ;
V_35 -> V_146 . V_171 . V_170 = 0 ;
V_35 -> V_146 . V_171 . V_169 = 0 ;
break;
case 15 :
V_35 -> V_146 . V_160 . V_170 = 10 ;
V_35 -> V_146 . V_161 . V_170 = 5 ;
V_35 -> V_146 . V_162 . V_170 = 0 ;
V_35 -> V_146 . V_160 . V_169 = 5 ;
V_35 -> V_146 . V_161 . V_169 = 5 ;
V_35 -> V_146 . V_162 . V_169 = 5 ;
V_35 -> V_146 . V_171 . V_170 = 15 ;
V_35 -> V_146 . V_171 . V_169 = 1 ;
break;
case 16 :
V_35 -> V_146 . V_160 . V_170 = 11 ;
V_35 -> V_146 . V_161 . V_170 = 5 ;
V_35 -> V_146 . V_162 . V_170 = 0 ;
V_35 -> V_146 . V_160 . V_169 = 5 ;
V_35 -> V_146 . V_161 . V_169 = 6 ;
V_35 -> V_146 . V_162 . V_169 = 5 ;
V_35 -> V_146 . V_171 . V_170 = 0 ;
break;
case 24 :
V_35 -> V_146 . V_160 . V_170 = 16 ;
V_35 -> V_146 . V_161 . V_170 = 8 ;
V_35 -> V_146 . V_162 . V_170 = 0 ;
V_35 -> V_146 . V_160 . V_169 = 8 ;
V_35 -> V_146 . V_161 . V_169 = 8 ;
V_35 -> V_146 . V_162 . V_169 = 8 ;
V_35 -> V_146 . V_171 . V_170 = 0 ;
V_35 -> V_146 . V_171 . V_169 = 0 ;
break;
case 32 :
V_35 -> V_146 . V_160 . V_170 = 16 ;
V_35 -> V_146 . V_161 . V_170 = 8 ;
V_35 -> V_146 . V_162 . V_170 = 0 ;
V_35 -> V_146 . V_160 . V_169 = 8 ;
V_35 -> V_146 . V_161 . V_169 = 8 ;
V_35 -> V_146 . V_162 . V_169 = 8 ;
V_35 -> V_146 . V_171 . V_170 = 24 ;
V_35 -> V_146 . V_171 . V_169 = 8 ;
break;
default:
break;
}
V_35 -> V_146 . V_148 = V_197 ;
V_35 -> V_146 . V_147 = V_198 ;
}
static int F_122 ( struct V_1 * V_2 ,
T_8 V_234 ,
T_8 V_235 )
{
struct V_5 * V_6 ;
int V_150 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_14 [ V_7 ] -> V_6 ;
V_150 += V_6 -> V_29 -> V_236 ( V_6 , V_234 , V_235 ) ;
}
return V_150 ;
}
struct V_204 * F_123 ( struct V_15 * V_237 , int V_131 , int V_132 )
{
struct V_204 * V_103 ;
F_17 (mode, &fb_connector->connector->modes, head) {
if ( V_103 -> V_209 > V_131 ||
V_103 -> V_211 > V_132 )
continue;
if ( V_103 -> type & V_238 )
return V_103 ;
}
return NULL ;
}
static bool F_124 ( struct V_15 * V_237 )
{
return V_237 -> V_6 -> V_201 . V_239 ;
}
struct V_204 * F_125 ( struct V_15 * V_199 ,
int V_131 , int V_132 )
{
struct V_200 * V_201 ;
struct V_204 * V_103 ;
bool V_240 ;
V_201 = & V_199 -> V_6 -> V_201 ;
if ( V_201 -> V_239 == false )
return NULL ;
if ( V_201 -> V_241 || V_201 -> V_242 )
goto V_243;
V_240 = ! V_201 -> V_244 ;
V_245:
F_17 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_103 -> V_209 != V_201 -> V_148 ||
V_103 -> V_211 != V_201 -> V_147 )
continue;
if ( V_201 -> V_246 ) {
if ( V_103 -> V_247 != V_201 -> V_248 )
continue;
}
if ( V_201 -> V_244 ) {
if ( ! ( V_103 -> V_110 & V_249 ) )
continue;
} else if ( V_240 ) {
if ( V_103 -> V_110 & V_249 )
continue;
}
return V_103 ;
}
if ( V_240 ) {
V_240 = false ;
goto V_245;
}
V_243:
V_103 = F_126 ( V_199 -> V_6 -> V_4 ,
V_201 ) ;
F_119 ( & V_103 -> V_250 , & V_199 -> V_6 -> V_251 ) ;
return V_103 ;
}
static bool F_127 ( struct V_5 * V_6 , bool V_252 )
{
bool V_253 ;
if ( V_252 )
V_253 = V_6 -> V_254 == V_255 ;
else
V_253 = V_6 -> V_254 != V_256 ;
return V_253 ;
}
static void F_128 ( struct V_1 * V_2 ,
bool * V_42 )
{
bool V_257 = false ;
struct V_5 * V_6 ;
int V_7 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_14 [ V_7 ] -> V_6 ;
V_42 [ V_7 ] = F_127 ( V_6 , true ) ;
F_129 ( L_8 , V_6 -> V_51 . V_52 ,
V_42 [ V_7 ] ? L_9 : L_10 ) ;
V_257 |= V_42 [ V_7 ] ;
}
if ( V_257 )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_14 [ V_7 ] -> V_6 ;
V_42 [ V_7 ] = F_127 ( V_6 , false ) ;
}
}
static bool F_130 ( struct V_1 * V_2 ,
struct V_204 * * V_251 ,
struct V_258 * V_259 ,
bool * V_42 , int V_131 , int V_132 )
{
int V_150 , V_7 , V_21 ;
bool V_260 = false ;
struct V_15 * V_199 ;
struct V_204 * V_261 , * V_103 ;
if ( V_2 -> V_38 > 1 )
return false ;
V_150 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( V_42 [ V_7 ] )
V_150 ++ ;
}
if ( V_150 <= 1 )
return false ;
V_260 = true ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_42 [ V_7 ] )
continue;
V_199 = V_2 -> V_14 [ V_7 ] ;
V_251 [ V_7 ] = F_125 ( V_199 , V_131 , V_132 ) ;
if ( ! V_251 [ V_7 ] ) {
V_260 = false ;
break;
}
for ( V_21 = 0 ; V_21 < V_7 ; V_21 ++ ) {
if ( ! V_42 [ V_21 ] )
continue;
if ( ! F_131 ( V_251 [ V_21 ] , V_251 [ V_7 ] ) )
V_260 = false ;
}
}
if ( V_260 ) {
F_129 ( L_11 ) ;
return true ;
}
V_260 = true ;
V_261 = F_132 ( V_2 -> V_4 , 1024 , 768 , 60 , false ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_42 [ V_7 ] )
continue;
V_199 = V_2 -> V_14 [ V_7 ] ;
F_17 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_131 ( V_103 , V_261 ) )
V_251 [ V_7 ] = V_103 ;
}
if ( ! V_251 [ V_7 ] )
V_260 = false ;
}
if ( V_260 ) {
F_129 ( L_12 ) ;
return true ;
}
F_115 ( L_13 ) ;
return false ;
}
static int F_133 ( struct V_1 * V_2 ,
struct V_204 * * V_251 ,
struct V_258 * V_259 ,
int V_262 ,
int V_263 , int V_264 )
{
struct V_15 * V_199 ;
int V_7 ;
int V_265 = 0 , V_266 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_199 = V_2 -> V_14 [ V_7 ] ;
if ( ! V_199 -> V_6 -> V_212 )
continue;
if ( ! V_251 [ V_7 ] && ( V_263 || V_264 ) ) {
F_129 ( L_14 , V_7 ,
V_199 -> V_6 -> V_51 . V_52 ) ;
continue;
}
if ( V_199 -> V_6 -> V_213 < V_263 )
V_265 += V_251 [ V_7 ] -> V_209 ;
if ( V_199 -> V_6 -> V_215 < V_264 )
V_266 += V_251 [ V_7 ] -> V_211 ;
}
V_259 [ V_262 ] . V_46 = V_265 ;
V_259 [ V_262 ] . V_47 = V_266 ;
F_129 ( L_15 , V_265 , V_266 , V_263 , V_264 ) ;
return 0 ;
}
static bool F_134 ( struct V_1 * V_2 ,
struct V_204 * * V_251 ,
struct V_258 * V_259 ,
bool * V_42 , int V_131 , int V_132 )
{
struct V_15 * V_199 ;
int V_7 ;
T_9 V_267 = 0 , V_172 ;
int V_268 = 0 ;
V_172 = ( 1 << V_2 -> V_13 ) - 1 ;
V_61:
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_199 = V_2 -> V_14 [ V_7 ] ;
if ( V_267 & ( 1 << V_7 ) )
continue;
if ( V_42 [ V_7 ] == false ) {
V_267 |= ( 1 << V_7 ) ;
continue;
}
if ( V_268 == 0 && V_199 -> V_6 -> V_212 )
continue;
if ( V_268 == 1 ) {
if ( V_199 -> V_6 -> V_213 != 0 ||
V_199 -> V_6 -> V_215 != 0 )
continue;
} else {
if ( V_199 -> V_6 -> V_213 != V_268 - 1 &&
V_199 -> V_6 -> V_215 != V_268 - 1 )
continue;
F_133 ( V_2 , V_251 , V_259 ,
V_7 , V_199 -> V_6 -> V_213 , V_199 -> V_6 -> V_215 ) ;
}
F_129 ( L_16 ,
V_199 -> V_6 -> V_51 . V_52 ) ;
V_251 [ V_7 ] = F_125 ( V_199 , V_131 , V_132 ) ;
if ( ! V_251 [ V_7 ] ) {
F_129 ( L_17 ,
V_199 -> V_6 -> V_51 . V_52 , V_199 -> V_6 -> V_269 ? V_199 -> V_6 -> V_269 -> V_52 : 0 ) ;
V_251 [ V_7 ] = F_123 ( V_199 , V_131 , V_132 ) ;
}
if ( ! V_251 [ V_7 ] && ! F_49 ( & V_199 -> V_6 -> V_251 ) ) {
F_17 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_129 ( L_18 , V_251 [ V_7 ] ? V_251 [ V_7 ] -> V_270 :
L_19 ) ;
V_267 |= ( 1 << V_7 ) ;
}
if ( ( V_267 & V_172 ) != V_172 ) {
V_268 ++ ;
goto V_61;
}
return true ;
}
static int F_135 ( struct V_1 * V_2 ,
struct V_119 * * V_271 ,
struct V_204 * * V_251 ,
int V_272 , int V_131 , int V_132 )
{
int V_50 , V_273 ;
struct V_5 * V_6 ;
const struct V_274 * V_275 ;
struct V_276 * V_277 ;
int V_278 , V_279 , V_280 ;
struct V_119 * * V_281 , * V_24 ;
struct V_15 * V_199 ;
if ( V_272 == V_2 -> V_13 )
return 0 ;
V_199 = V_2 -> V_14 [ V_272 ] ;
V_6 = V_199 -> V_6 ;
V_271 [ V_272 ] = NULL ;
V_279 = F_135 ( V_2 , V_271 , V_251 , V_272 + 1 , V_131 , V_132 ) ;
if ( V_251 [ V_272 ] == NULL )
return V_279 ;
V_281 = F_10 ( V_2 -> V_13 *
sizeof( struct V_119 * ) , V_19 ) ;
if ( ! V_281 )
return V_279 ;
V_278 = 1 ;
if ( V_6 -> V_254 == V_255 )
V_278 ++ ;
if ( F_124 ( V_199 ) )
V_278 ++ ;
if ( F_123 ( V_199 , V_131 , V_132 ) )
V_278 ++ ;
V_275 = V_6 -> V_43 ;
if ( V_2 -> V_4 -> V_10 . V_29 -> V_70 &&
! V_275 -> V_282 )
V_277 = F_136 ( V_6 ) ;
else
V_277 = V_275 -> V_282 ( V_6 ) ;
if ( ! V_277 )
goto V_181;
for ( V_50 = 0 ; V_50 < V_2 -> V_38 ; V_50 ++ ) {
V_24 = & V_2 -> V_41 [ V_50 ] ;
if ( ( V_277 -> V_283 & ( 1 << V_50 ) ) == 0 )
continue;
for ( V_273 = 0 ; V_273 < V_272 ; V_273 ++ )
if ( V_271 [ V_273 ] == V_24 )
break;
if ( V_273 < V_272 ) {
if ( V_2 -> V_38 > 1 )
continue;
if ( ! F_131 ( V_251 [ V_273 ] , V_251 [ V_272 ] ) )
continue;
}
V_281 [ V_272 ] = V_24 ;
memcpy ( V_281 , V_271 , V_272 * sizeof( struct V_119 * ) ) ;
V_280 = V_278 + F_135 ( V_2 , V_281 , V_251 , V_272 + 1 ,
V_131 , V_132 ) ;
if ( V_280 > V_279 ) {
V_279 = V_280 ;
memcpy ( V_271 , V_281 ,
V_2 -> V_13 *
sizeof( struct V_119 * ) ) ;
}
}
V_181:
F_6 ( V_281 ) ;
return V_279 ;
}
static void F_137 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_119 * * V_281 ;
struct V_204 * * V_251 ;
struct V_258 * V_259 ;
struct V_39 * V_190 ;
bool * V_42 ;
int V_131 , V_132 ;
int V_7 ;
F_129 ( L_20 ) ;
V_131 = V_4 -> V_10 . V_284 ;
V_132 = V_4 -> V_10 . V_285 ;
V_281 = F_67 ( V_2 -> V_13 ,
sizeof( struct V_119 * ) , V_19 ) ;
V_251 = F_67 ( V_2 -> V_13 ,
sizeof( struct V_204 * ) , V_19 ) ;
V_259 = F_67 ( V_2 -> V_13 ,
sizeof( struct V_258 ) , V_19 ) ;
V_42 = F_67 ( V_2 -> V_13 ,
sizeof( bool ) , V_19 ) ;
if ( ! V_281 || ! V_251 || ! V_42 || ! V_259 ) {
F_21 ( L_21 ) ;
goto V_181;
}
F_128 ( V_2 , V_42 ) ;
if ( ! ( V_2 -> V_29 -> V_286 &&
V_2 -> V_29 -> V_286 ( V_2 , V_281 , V_251 ,
V_259 ,
V_42 , V_131 , V_132 ) ) ) {
memset ( V_251 , 0 , V_2 -> V_13 * sizeof( V_251 [ 0 ] ) ) ;
memset ( V_281 , 0 , V_2 -> V_13 * sizeof( V_281 [ 0 ] ) ) ;
memset ( V_259 , 0 , V_2 -> V_13 * sizeof( V_259 [ 0 ] ) ) ;
if ( ! F_130 ( V_2 , V_251 , V_259 ,
V_42 , V_131 , V_132 ) &&
! F_134 ( V_2 , V_251 , V_259 ,
V_42 , V_131 , V_132 ) )
F_21 ( L_22 ) ;
F_129 ( L_23 ,
V_131 , V_132 ) ;
F_135 ( V_2 , V_281 , V_251 , 0 , V_131 , V_132 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
V_190 = & V_2 -> V_41 [ V_7 ] . V_40 ;
V_190 -> V_122 = 0 ;
V_190 -> V_45 = NULL ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_204 * V_103 = V_251 [ V_7 ] ;
struct V_119 * V_287 = V_281 [ V_7 ] ;
struct V_258 * V_170 = & V_259 [ V_7 ] ;
V_190 = & V_287 -> V_40 ;
if ( V_103 && V_287 ) {
F_129 ( L_24 ,
V_103 -> V_270 , V_287 -> V_40 . V_24 -> V_51 . V_52 , V_170 -> V_46 , V_170 -> V_47 ) ;
V_287 -> V_205 = V_103 ;
V_287 -> V_46 = V_170 -> V_46 ;
V_287 -> V_47 = V_170 -> V_47 ;
if ( V_190 -> V_103 )
F_57 ( V_4 , V_190 -> V_103 ) ;
V_190 -> V_103 = F_138 ( V_4 ,
V_287 -> V_205 ) ;
V_190 -> V_102 [ V_190 -> V_122 ++ ] = V_2 -> V_14 [ V_7 ] -> V_6 ;
V_190 -> V_45 = V_2 -> V_45 ;
V_190 -> V_46 = V_170 -> V_46 ;
V_190 -> V_47 = V_170 -> V_47 ;
}
}
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
V_190 = & V_2 -> V_41 [ V_7 ] . V_40 ;
if ( V_190 -> V_122 == 0 ) {
F_139 ( V_190 -> V_45 ) ;
if ( V_190 -> V_103 )
F_57 ( V_4 , V_190 -> V_103 ) ;
V_190 -> V_103 = NULL ;
}
}
V_181:
F_6 ( V_281 ) ;
F_6 ( V_251 ) ;
F_6 ( V_259 ) ;
F_6 ( V_42 ) ;
}
int F_140 ( struct V_1 * V_2 , int V_288 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_150 = 0 ;
if ( ! V_9 )
return 0 ;
F_2 ( & V_4 -> V_10 . V_11 ) ;
V_150 = F_122 ( V_2 ,
V_4 -> V_10 . V_284 ,
V_4 -> V_10 . V_285 ) ;
F_5 ( & V_4 -> V_10 . V_11 ) ;
if ( V_150 == 0 )
F_117 ( V_2 -> V_4 -> V_4 , L_25 ) ;
F_137 ( V_2 ) ;
return F_114 ( V_2 , V_288 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_284 , V_285 ;
if ( ! V_9 )
return 0 ;
F_2 ( & V_2 -> V_4 -> V_10 . V_11 ) ;
if ( ! V_2 -> V_45 || ! F_46 ( V_2 ) ) {
V_2 -> V_76 = true ;
F_5 ( & V_2 -> V_4 -> V_10 . V_11 ) ;
return 0 ;
}
F_129 ( L_20 ) ;
V_284 = V_2 -> V_45 -> V_131 ;
V_285 = V_2 -> V_45 -> V_132 ;
F_122 ( V_2 , V_284 , V_285 ) ;
F_5 ( & V_2 -> V_4 -> V_10 . V_11 ) ;
F_43 ( V_4 ) ;
F_137 ( V_2 ) ;
F_44 ( V_4 ) ;
F_111 ( V_2 -> V_128 ) ;
return 0 ;
}
int T_10 F_141 ( void )
{
#if F_142 ( V_289 ) && ! F_142 ( V_290 )
const char * V_270 = L_26 ;
struct V_291 * V_292 ;
F_2 ( & V_293 ) ;
V_292 = F_143 ( V_270 ) ;
F_5 ( & V_293 ) ;
if ( ! V_292 )
F_144 ( V_270 ) ;
#endif
return 0 ;
}
