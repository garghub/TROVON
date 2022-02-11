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
V_24 -> V_29 -> V_33 ( V_24 , V_26 , V_27 , V_28 , 0 , V_24 -> V_32 ) ;
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
if ( V_2 -> V_70 )
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
if ( V_4 -> V_53 -> V_79 )
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
F_43 ( V_4 ) ;
V_8 = F_37 ( V_25 ) ;
if ( V_8 )
error = true ;
F_44 ( V_4 ) ;
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
F_53 ( & V_6 -> V_51 ,
V_4 -> V_10 . V_89 , V_87 ) ;
}
}
F_44 ( V_4 ) ;
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
static void F_55 ( struct V_1 * V_25 )
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
F_56 ( V_25 -> V_4 , V_25 -> V_41 [ V_7 ] . V_40 . V_103 ) ;
}
F_6 ( V_25 -> V_41 ) ;
}
static void F_57 ( struct V_83 * V_104 )
{
struct V_1 * V_25 = F_58 ( V_104 , struct V_1 ,
V_105 ) ;
struct V_106 * V_107 = & V_25 -> V_108 ;
struct V_106 V_109 ;
unsigned long V_110 ;
F_59 ( & V_25 -> V_111 , V_110 ) ;
V_109 = * V_107 ;
V_107 -> V_112 = V_107 -> y1 = ~ 0 ;
V_107 -> V_113 = V_107 -> V_114 = 0 ;
F_60 ( & V_25 -> V_111 , V_110 ) ;
V_25 -> V_45 -> V_29 -> V_115 ( V_25 -> V_45 , NULL , 0 , 0 , & V_109 , 1 ) ;
}
void F_61 ( struct V_3 * V_4 , struct V_1 * V_25 ,
const struct V_116 * V_29 )
{
F_62 ( & V_25 -> V_117 ) ;
F_63 ( & V_25 -> V_111 ) ;
F_64 ( & V_25 -> V_105 , F_57 ) ;
V_25 -> V_108 . V_112 = V_25 -> V_108 . y1 = ~ 0 ;
V_25 -> V_29 = V_29 ;
V_25 -> V_4 = V_4 ;
}
int F_65 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_38 , int V_118 )
{
struct V_23 * V_24 ;
int V_7 ;
if ( ! V_9 )
return 0 ;
if ( ! V_118 )
return - V_22 ;
V_2 -> V_41 = F_66 ( V_38 , sizeof( struct V_119 ) , V_19 ) ;
if ( ! V_2 -> V_41 )
return - V_20 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_14 = F_66 ( V_4 -> V_10 . V_120 , sizeof( struct V_15 * ) , V_19 ) ;
if ( ! V_2 -> V_14 ) {
F_6 ( V_2 -> V_41 ) ;
return - V_20 ;
}
V_2 -> V_18 = V_4 -> V_10 . V_120 ;
V_2 -> V_13 = 0 ;
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ ) {
V_2 -> V_41 [ V_7 ] . V_40 . V_102 =
F_66 ( V_118 ,
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
V_2 -> V_70 = ! ! F_67 ( V_4 , V_123 ) ;
return 0 ;
V_121:
F_55 ( V_2 ) ;
return - V_20 ;
}
struct V_34 * F_68 ( struct V_1 * V_2 )
{
struct V_124 * V_4 = V_2 -> V_4 -> V_4 ;
struct V_34 * V_35 ;
int V_8 ;
V_35 = F_69 ( 0 , V_4 ) ;
if ( ! V_35 )
return F_70 ( - V_20 ) ;
V_8 = F_71 ( & V_35 -> V_125 , 256 , 0 ) ;
if ( V_8 )
goto V_126;
V_35 -> V_127 = F_72 ( 1 ) ;
if ( ! V_35 -> V_127 ) {
V_8 = - V_20 ;
goto V_128;
}
V_2 -> V_129 = V_35 ;
return V_35 ;
V_128:
F_73 ( & V_35 -> V_125 ) ;
V_126:
F_74 ( V_35 ) ;
return F_70 ( V_8 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_129 )
F_76 ( V_2 -> V_129 ) ;
}
void F_77 ( struct V_1 * V_2 )
{
if ( V_2 ) {
struct V_34 * V_35 = V_2 -> V_129 ;
if ( V_35 ) {
if ( V_35 -> V_125 . V_130 )
F_73 ( & V_35 -> V_125 ) ;
F_74 ( V_35 ) ;
}
V_2 -> V_129 = NULL ;
}
}
void F_78 ( struct V_1 * V_2 )
{
if ( ! V_9 )
return;
if ( ! F_48 ( & V_2 -> V_117 ) ) {
F_79 ( & V_2 -> V_117 ) ;
if ( F_48 ( & V_80 ) ) {
F_80 ( 'v' , & V_131 ) ;
}
}
F_55 ( V_2 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_129 )
F_82 ( V_2 -> V_129 ) ;
}
static void F_83 ( struct V_34 * V_35 , T_2 V_46 , T_2 V_47 ,
T_2 V_132 , T_2 V_133 )
{
struct V_1 * V_25 = V_35 -> V_36 ;
struct V_106 * V_107 = & V_25 -> V_108 ;
unsigned long V_110 ;
if ( ! V_25 -> V_45 -> V_29 -> V_115 )
return;
F_59 ( & V_25 -> V_111 , V_110 ) ;
V_107 -> V_112 = F_84 ( T_2 , V_107 -> V_112 , V_46 ) ;
V_107 -> y1 = F_84 ( T_2 , V_107 -> y1 , V_47 ) ;
V_107 -> V_113 = F_85 ( T_2 , V_107 -> V_113 , V_46 + V_132 ) ;
V_107 -> V_114 = F_85 ( T_2 , V_107 -> V_114 , V_47 + V_133 ) ;
F_60 ( & V_25 -> V_111 , V_110 ) ;
F_51 ( & V_25 -> V_105 ) ;
}
void F_86 ( struct V_34 * V_35 ,
struct V_134 * V_135 )
{
unsigned long V_136 , V_137 , V_138 , V_139 ;
struct V_140 * V_140 ;
T_2 y1 , V_114 ;
V_138 = V_141 ;
V_139 = 0 ;
F_17 (page, pagelist, lru) {
V_136 = V_140 -> V_142 << V_143 ;
V_137 = V_136 + V_144 - 1 ;
V_138 = V_138 ( V_138 , V_136 ) ;
V_139 = V_139 ( V_139 , V_137 ) ;
}
if ( V_138 < V_139 ) {
y1 = V_138 / V_35 -> V_145 . V_146 ;
V_114 = F_84 ( T_2 , F_87 ( V_139 , V_35 -> V_145 . V_146 ) ,
V_35 -> V_147 . V_148 ) ;
F_83 ( V_35 , 0 , y1 , V_35 -> V_147 . V_149 , V_114 - y1 ) ;
}
}
T_3 F_88 ( struct V_34 * V_35 , char T_4 * V_150 ,
T_5 V_151 , T_6 * V_152 )
{
return F_89 ( V_35 , V_150 , V_151 , V_152 ) ;
}
T_3 F_90 ( struct V_34 * V_35 , const char T_4 * V_150 ,
T_5 V_151 , T_6 * V_152 )
{
T_3 V_8 ;
V_8 = F_91 ( V_35 , V_150 , V_151 , V_152 ) ;
if ( V_8 > 0 )
F_83 ( V_35 , 0 , 0 , V_35 -> V_147 . V_149 ,
V_35 -> V_147 . V_148 ) ;
return V_8 ;
}
void F_92 ( struct V_34 * V_35 ,
const struct V_153 * V_154 )
{
F_93 ( V_35 , V_154 ) ;
F_83 ( V_35 , V_154 -> V_155 , V_154 -> V_156 ,
V_154 -> V_132 , V_154 -> V_133 ) ;
}
void F_94 ( struct V_34 * V_35 ,
const struct V_157 * V_158 )
{
F_95 ( V_35 , V_158 ) ;
F_83 ( V_35 , V_158 -> V_155 , V_158 -> V_156 ,
V_158 -> V_132 , V_158 -> V_133 ) ;
}
void F_96 ( struct V_34 * V_35 ,
const struct V_159 * V_160 )
{
F_97 ( V_35 , V_160 ) ;
F_83 ( V_35 , V_160 -> V_155 , V_160 -> V_156 ,
V_160 -> V_132 , V_160 -> V_133 ) ;
}
void F_98 ( struct V_34 * V_35 ,
const struct V_153 * V_154 )
{
F_99 ( V_35 , V_154 ) ;
F_83 ( V_35 , V_154 -> V_155 , V_154 -> V_156 ,
V_154 -> V_132 , V_154 -> V_133 ) ;
}
void F_100 ( struct V_34 * V_35 ,
const struct V_157 * V_158 )
{
F_101 ( V_35 , V_158 ) ;
F_83 ( V_35 , V_158 -> V_155 , V_158 -> V_156 ,
V_158 -> V_132 , V_158 -> V_133 ) ;
}
void F_102 ( struct V_34 * V_35 ,
const struct V_159 * V_160 )
{
F_103 ( V_35 , V_160 ) ;
F_83 ( V_35 , V_160 -> V_155 , V_160 -> V_156 ,
V_160 -> V_132 , V_160 -> V_133 ) ;
}
void F_104 ( struct V_1 * V_2 , int V_58 )
{
if ( V_2 && V_2 -> V_129 )
F_105 ( V_2 -> V_129 , V_58 ) ;
}
static int F_106 ( struct V_23 * V_24 , T_7 V_161 , T_7 V_162 ,
T_7 V_163 , T_7 V_164 , struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_49 * V_45 = V_2 -> V_45 ;
int V_165 ;
if ( V_35 -> V_145 . V_166 == V_167 ) {
T_2 * V_168 ;
T_2 V_169 ;
if ( V_164 > 16 )
return - V_22 ;
V_168 = ( T_2 * ) V_35 -> V_170 ;
V_161 >>= ( 16 - V_35 -> V_147 . V_161 . V_171 ) ;
V_162 >>= ( 16 - V_35 -> V_147 . V_162 . V_171 ) ;
V_163 >>= ( 16 - V_35 -> V_147 . V_163 . V_171 ) ;
V_169 = ( V_161 << V_35 -> V_147 . V_161 . V_172 ) |
( V_162 << V_35 -> V_147 . V_162 . V_172 ) |
( V_163 << V_35 -> V_147 . V_163 . V_172 ) ;
if ( V_35 -> V_147 . V_173 . V_171 > 0 ) {
T_2 V_174 = ( 1 << V_35 -> V_147 . V_173 . V_171 ) - 1 ;
V_174 <<= V_35 -> V_147 . V_173 . V_172 ;
V_169 |= V_174 ;
}
V_168 [ V_164 ] = V_169 ;
return 0 ;
}
if ( F_7 ( ! V_2 -> V_29 -> V_33 ||
! V_2 -> V_29 -> V_30 ) )
return - V_22 ;
V_165 = V_164 ;
if ( V_45 -> V_175 == 16 ) {
V_165 = V_164 << 3 ;
if ( V_45 -> V_176 == 16 && V_164 > 63 )
return - V_22 ;
if ( V_45 -> V_176 == 15 && V_164 > 31 )
return - V_22 ;
if ( V_45 -> V_176 == 16 ) {
T_7 V_177 , V_178 , V_179 ;
int V_7 ;
if ( V_164 < 32 ) {
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
V_2 -> V_29 -> V_33 ( V_24 , V_161 ,
V_162 , V_163 , V_165 + V_7 ) ;
}
V_2 -> V_29 -> V_30 ( V_24 , & V_177 ,
& V_178 , & V_179 ,
V_165 >> 1 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
V_2 -> V_29 -> V_33 ( V_24 , V_177 ,
V_162 , V_179 ,
( V_165 >> 1 ) + V_7 ) ;
}
}
if ( V_45 -> V_176 != 16 )
V_2 -> V_29 -> V_33 ( V_24 , V_161 , V_162 , V_163 , V_165 ) ;
return 0 ;
}
int F_107 ( struct V_180 * V_125 , struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_37 * V_181 ;
T_7 * V_161 , * V_162 , * V_163 , * V_173 ;
struct V_23 * V_24 ;
int V_7 , V_21 , V_182 = 0 ;
int V_136 ;
if ( V_91 )
return - V_92 ;
F_43 ( V_4 ) ;
if ( ! F_46 ( V_2 ) ) {
F_44 ( V_4 ) ;
return - V_92 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
V_24 = V_2 -> V_41 [ V_7 ] . V_40 . V_24 ;
V_181 = V_24 -> V_43 ;
V_161 = V_125 -> V_161 ;
V_162 = V_125 -> V_162 ;
V_163 = V_125 -> V_163 ;
V_173 = V_125 -> V_173 ;
V_136 = V_125 -> V_136 ;
for ( V_21 = 0 ; V_21 < V_125 -> V_130 ; V_21 ++ ) {
T_7 V_183 , V_184 , V_185 , V_186 = 0xffff ;
V_183 = * V_161 ++ ;
V_184 = * V_162 ++ ;
V_185 = * V_163 ++ ;
if ( V_173 )
V_186 = * V_173 ++ ;
V_182 = F_106 ( V_24 , V_183 , V_184 , V_185 , V_136 ++ , V_35 ) ;
if ( V_182 )
goto V_187;
}
if ( V_181 -> V_188 )
V_181 -> V_188 ( V_24 ) ;
}
V_187:
F_44 ( V_4 ) ;
return V_182 ;
}
int F_108 ( struct V_189 * V_147 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_49 * V_45 = V_2 -> V_45 ;
int V_176 ;
if ( V_147 -> V_190 != 0 || F_109 () )
return - V_22 ;
if ( V_147 -> V_175 > V_45 -> V_175 ||
V_147 -> V_149 > V_45 -> V_132 || V_147 -> V_148 > V_45 -> V_133 ||
V_147 -> V_191 > V_45 -> V_132 || V_147 -> V_192 > V_45 -> V_133 ) {
F_110 ( L_3
L_4 ,
V_147 -> V_149 , V_147 -> V_148 , V_147 -> V_175 ,
V_147 -> V_191 , V_147 -> V_192 ,
V_45 -> V_132 , V_45 -> V_133 , V_45 -> V_175 ) ;
return - V_22 ;
}
switch ( V_147 -> V_175 ) {
case 16 :
V_176 = ( V_147 -> V_162 . V_171 == 6 ) ? 16 : 15 ;
break;
case 32 :
V_176 = ( V_147 -> V_173 . V_171 > 0 ) ? 32 : 24 ;
break;
default:
V_176 = V_147 -> V_175 ;
break;
}
switch ( V_176 ) {
case 8 :
V_147 -> V_161 . V_172 = 0 ;
V_147 -> V_162 . V_172 = 0 ;
V_147 -> V_163 . V_172 = 0 ;
V_147 -> V_161 . V_171 = 8 ;
V_147 -> V_162 . V_171 = 8 ;
V_147 -> V_163 . V_171 = 8 ;
V_147 -> V_173 . V_171 = 0 ;
V_147 -> V_173 . V_172 = 0 ;
break;
case 15 :
V_147 -> V_161 . V_172 = 10 ;
V_147 -> V_162 . V_172 = 5 ;
V_147 -> V_163 . V_172 = 0 ;
V_147 -> V_161 . V_171 = 5 ;
V_147 -> V_162 . V_171 = 5 ;
V_147 -> V_163 . V_171 = 5 ;
V_147 -> V_173 . V_171 = 1 ;
V_147 -> V_173 . V_172 = 15 ;
break;
case 16 :
V_147 -> V_161 . V_172 = 11 ;
V_147 -> V_162 . V_172 = 5 ;
V_147 -> V_163 . V_172 = 0 ;
V_147 -> V_161 . V_171 = 5 ;
V_147 -> V_162 . V_171 = 6 ;
V_147 -> V_163 . V_171 = 5 ;
V_147 -> V_173 . V_171 = 0 ;
V_147 -> V_173 . V_172 = 0 ;
break;
case 24 :
V_147 -> V_161 . V_172 = 16 ;
V_147 -> V_162 . V_172 = 8 ;
V_147 -> V_163 . V_172 = 0 ;
V_147 -> V_161 . V_171 = 8 ;
V_147 -> V_162 . V_171 = 8 ;
V_147 -> V_163 . V_171 = 8 ;
V_147 -> V_173 . V_171 = 0 ;
V_147 -> V_173 . V_172 = 0 ;
break;
case 32 :
V_147 -> V_161 . V_172 = 16 ;
V_147 -> V_162 . V_172 = 8 ;
V_147 -> V_163 . V_172 = 0 ;
V_147 -> V_161 . V_171 = 8 ;
V_147 -> V_162 . V_171 = 8 ;
V_147 -> V_163 . V_171 = 8 ;
V_147 -> V_173 . V_171 = 8 ;
V_147 -> V_173 . V_172 = 24 ;
break;
default:
return - V_22 ;
}
return 0 ;
}
int F_111 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_189 * V_147 = & V_35 -> V_147 ;
if ( V_91 )
return - V_92 ;
if ( V_147 -> V_190 != 0 ) {
F_21 ( L_5 ) ;
return - V_22 ;
}
F_42 ( V_2 ) ;
return 0 ;
}
static int F_112 ( struct V_189 * V_147 ,
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
V_40 -> V_46 = V_147 -> V_193 ;
V_40 -> V_47 = V_147 -> V_194 ;
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
V_35 -> V_147 . V_193 = V_147 -> V_193 ;
V_35 -> V_147 . V_194 = V_147 -> V_194 ;
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
int F_113 ( struct V_189 * V_147 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_39 * V_195 ;
int V_8 = 0 ;
int V_7 ;
if ( V_91 )
return - V_92 ;
F_43 ( V_4 ) ;
if ( ! F_46 ( V_2 ) ) {
F_44 ( V_4 ) ;
return - V_92 ;
}
if ( V_2 -> V_70 ) {
V_8 = F_112 ( V_147 , V_35 ) ;
goto V_196;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
V_195 = & V_2 -> V_41 [ V_7 ] . V_40 ;
V_195 -> V_46 = V_147 -> V_193 ;
V_195 -> V_47 = V_147 -> V_194 ;
if ( V_195 -> V_122 ) {
V_8 = F_41 ( V_195 ) ;
if ( ! V_8 ) {
V_35 -> V_147 . V_193 = V_147 -> V_193 ;
V_35 -> V_147 . V_194 = V_147 -> V_194 ;
}
}
}
V_196:
F_44 ( V_4 ) ;
return V_8 ;
}
static int F_114 ( struct V_1 * V_2 ,
int V_197 )
{
int V_8 = 0 ;
int V_38 = 0 ;
int V_7 ;
struct V_34 * V_35 ;
struct V_198 V_199 ;
int V_32 = 0 ;
memset ( & V_199 , 0 , sizeof( struct V_198 ) ) ;
V_199 . V_200 = 24 ;
V_199 . V_201 = 32 ;
V_199 . V_202 = ( unsigned ) - 1 ;
V_199 . V_203 = ( unsigned ) - 1 ;
if ( V_197 != V_199 . V_201 )
V_199 . V_200 = V_199 . V_201 = V_197 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_15 * V_204 = V_2 -> V_14 [ V_7 ] ;
struct V_205 * V_206 ;
V_206 = & V_204 -> V_6 -> V_206 ;
if ( V_206 -> V_207 ) {
switch ( V_206 -> V_208 ) {
case 8 :
V_199 . V_200 = V_199 . V_201 = 8 ;
break;
case 15 :
V_199 . V_200 = 15 ;
V_199 . V_201 = 16 ;
break;
case 16 :
V_199 . V_200 = V_199 . V_201 = 16 ;
break;
case 24 :
V_199 . V_200 = V_199 . V_201 = 24 ;
break;
case 32 :
V_199 . V_200 = 24 ;
V_199 . V_201 = 32 ;
break;
}
break;
}
}
V_38 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
struct V_209 * V_210 ;
struct V_39 * V_40 ;
int V_46 , V_47 , V_21 ;
bool V_211 = true , V_212 = true ;
V_210 = V_2 -> V_41 [ V_7 ] . V_210 ;
V_40 = & V_2 -> V_41 [ V_7 ] . V_40 ;
if ( ! V_210 )
continue;
V_38 ++ ;
V_46 = V_2 -> V_41 [ V_7 ] . V_46 ;
V_47 = V_2 -> V_41 [ V_7 ] . V_47 ;
if ( V_32 == 0 )
V_32 = V_2 -> V_41 [ V_7 ] . V_40 . V_24 -> V_32 ;
V_199 . V_213 = F_85 ( T_2 , V_210 -> V_214 + V_46 , V_199 . V_213 ) ;
V_199 . V_215 = F_85 ( T_2 , V_210 -> V_216 + V_47 , V_199 . V_215 ) ;
for ( V_21 = 0 ; V_21 < V_40 -> V_122 ; V_21 ++ ) {
struct V_5 * V_6 = V_40 -> V_102 [ V_21 ] ;
if ( V_6 -> V_217 ) {
V_212 = ( V_6 -> V_218 == ( V_6 -> V_219 - 1 ) ) ;
V_211 = ( V_6 -> V_220 == ( V_6 -> V_221 - 1 ) ) ;
break;
}
}
if ( V_212 )
V_199 . V_202 = F_84 ( T_2 , V_210 -> V_214 + V_46 , V_199 . V_202 ) ;
if ( V_211 )
V_199 . V_203 = F_84 ( T_2 , V_210 -> V_216 + V_47 , V_199 . V_203 ) ;
}
if ( V_38 == 0 || V_199 . V_202 == - 1 || V_199 . V_203 == - 1 ) {
F_115 ( L_6 ) ;
V_199 . V_202 = V_199 . V_213 = 1024 ;
V_199 . V_203 = V_199 . V_215 = 768 ;
}
V_8 = (* V_2 -> V_29 -> V_222 )( V_2 , & V_199 ) ;
if ( V_8 < 0 )
return V_8 ;
V_35 = V_2 -> V_129 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ )
if ( V_2 -> V_41 [ V_7 ] . V_40 . V_122 )
V_2 -> V_41 [ V_7 ] . V_40 . V_45 = V_2 -> V_45 ;
V_35 -> V_147 . V_190 = 0 ;
if ( F_116 ( V_35 ) < 0 )
return - V_22 ;
F_117 ( V_2 -> V_4 -> V_4 , L_7 ,
V_35 -> V_223 , V_35 -> V_145 . V_52 ) ;
if ( F_48 ( & V_80 ) ) {
F_118 ( 'v' , & V_131 ) ;
}
F_119 ( & V_2 -> V_117 , & V_80 ) ;
return 0 ;
}
void F_120 ( struct V_34 * V_35 , T_8 V_224 ,
T_8 V_176 )
{
V_35 -> V_145 . type = V_225 ;
V_35 -> V_145 . V_166 = V_176 == 8 ? V_226 :
V_167 ;
V_35 -> V_145 . V_227 = 0 ;
V_35 -> V_145 . V_228 = 0 ;
V_35 -> V_145 . V_229 = 0 ;
V_35 -> V_145 . V_230 = 1 ;
V_35 -> V_145 . V_231 = 1 ;
V_35 -> V_145 . V_232 = 0 ;
V_35 -> V_145 . V_233 = V_234 ;
V_35 -> V_145 . V_146 = V_224 ;
return;
}
void F_121 ( struct V_34 * V_35 , struct V_1 * V_2 ,
T_8 V_202 , T_8 V_203 )
{
struct V_49 * V_45 = V_2 -> V_45 ;
V_35 -> V_170 = V_2 -> V_170 ;
V_35 -> V_147 . V_191 = V_45 -> V_132 ;
V_35 -> V_147 . V_192 = V_45 -> V_133 ;
V_35 -> V_147 . V_175 = V_45 -> V_175 ;
V_35 -> V_147 . V_235 = V_236 ;
V_35 -> V_147 . V_193 = 0 ;
V_35 -> V_147 . V_194 = 0 ;
V_35 -> V_147 . V_237 = V_238 ;
V_35 -> V_147 . V_133 = - 1 ;
V_35 -> V_147 . V_132 = - 1 ;
switch ( V_45 -> V_176 ) {
case 8 :
V_35 -> V_147 . V_161 . V_172 = 0 ;
V_35 -> V_147 . V_162 . V_172 = 0 ;
V_35 -> V_147 . V_163 . V_172 = 0 ;
V_35 -> V_147 . V_161 . V_171 = 8 ;
V_35 -> V_147 . V_162 . V_171 = 8 ;
V_35 -> V_147 . V_163 . V_171 = 8 ;
V_35 -> V_147 . V_173 . V_172 = 0 ;
V_35 -> V_147 . V_173 . V_171 = 0 ;
break;
case 15 :
V_35 -> V_147 . V_161 . V_172 = 10 ;
V_35 -> V_147 . V_162 . V_172 = 5 ;
V_35 -> V_147 . V_163 . V_172 = 0 ;
V_35 -> V_147 . V_161 . V_171 = 5 ;
V_35 -> V_147 . V_162 . V_171 = 5 ;
V_35 -> V_147 . V_163 . V_171 = 5 ;
V_35 -> V_147 . V_173 . V_172 = 15 ;
V_35 -> V_147 . V_173 . V_171 = 1 ;
break;
case 16 :
V_35 -> V_147 . V_161 . V_172 = 11 ;
V_35 -> V_147 . V_162 . V_172 = 5 ;
V_35 -> V_147 . V_163 . V_172 = 0 ;
V_35 -> V_147 . V_161 . V_171 = 5 ;
V_35 -> V_147 . V_162 . V_171 = 6 ;
V_35 -> V_147 . V_163 . V_171 = 5 ;
V_35 -> V_147 . V_173 . V_172 = 0 ;
break;
case 24 :
V_35 -> V_147 . V_161 . V_172 = 16 ;
V_35 -> V_147 . V_162 . V_172 = 8 ;
V_35 -> V_147 . V_163 . V_172 = 0 ;
V_35 -> V_147 . V_161 . V_171 = 8 ;
V_35 -> V_147 . V_162 . V_171 = 8 ;
V_35 -> V_147 . V_163 . V_171 = 8 ;
V_35 -> V_147 . V_173 . V_172 = 0 ;
V_35 -> V_147 . V_173 . V_171 = 0 ;
break;
case 32 :
V_35 -> V_147 . V_161 . V_172 = 16 ;
V_35 -> V_147 . V_162 . V_172 = 8 ;
V_35 -> V_147 . V_163 . V_172 = 0 ;
V_35 -> V_147 . V_161 . V_171 = 8 ;
V_35 -> V_147 . V_162 . V_171 = 8 ;
V_35 -> V_147 . V_163 . V_171 = 8 ;
V_35 -> V_147 . V_173 . V_172 = 24 ;
V_35 -> V_147 . V_173 . V_171 = 8 ;
break;
default:
break;
}
V_35 -> V_147 . V_149 = V_202 ;
V_35 -> V_147 . V_148 = V_203 ;
}
static int F_122 ( struct V_1 * V_2 ,
T_8 V_239 ,
T_8 V_240 )
{
struct V_5 * V_6 ;
int V_151 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_14 [ V_7 ] -> V_6 ;
V_151 += V_6 -> V_29 -> V_241 ( V_6 , V_239 , V_240 ) ;
}
return V_151 ;
}
struct V_209 * F_123 ( struct V_15 * V_242 , int V_132 , int V_133 )
{
struct V_209 * V_103 ;
F_17 (mode, &fb_connector->connector->modes, head) {
if ( V_103 -> V_214 > V_132 ||
V_103 -> V_216 > V_133 )
continue;
if ( V_103 -> type & V_243 )
return V_103 ;
}
return NULL ;
}
static bool F_124 ( struct V_15 * V_242 )
{
return V_242 -> V_6 -> V_206 . V_244 ;
}
struct V_209 * F_125 ( struct V_15 * V_204 ,
int V_132 , int V_133 )
{
struct V_205 * V_206 ;
struct V_209 * V_103 ;
bool V_245 ;
V_206 = & V_204 -> V_6 -> V_206 ;
if ( V_206 -> V_244 == false )
return NULL ;
if ( V_206 -> V_246 || V_206 -> V_247 )
goto V_248;
V_245 = ! V_206 -> V_249 ;
V_250:
F_17 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_103 -> V_214 != V_206 -> V_149 ||
V_103 -> V_216 != V_206 -> V_148 )
continue;
if ( V_206 -> V_251 ) {
if ( V_103 -> V_252 != V_206 -> V_253 )
continue;
}
if ( V_206 -> V_249 ) {
if ( ! ( V_103 -> V_110 & V_254 ) )
continue;
} else if ( V_245 ) {
if ( V_103 -> V_110 & V_254 )
continue;
}
return V_103 ;
}
if ( V_245 ) {
V_245 = false ;
goto V_250;
}
V_248:
V_103 = F_126 ( V_204 -> V_6 -> V_4 ,
V_206 ) ;
F_119 ( & V_103 -> V_255 , & V_204 -> V_6 -> V_256 ) ;
return V_103 ;
}
static bool F_127 ( struct V_5 * V_6 , bool V_257 )
{
bool V_258 ;
if ( V_257 )
V_258 = V_6 -> V_259 == V_260 ;
else
V_258 = V_6 -> V_259 != V_261 ;
return V_258 ;
}
static void F_128 ( struct V_1 * V_2 ,
bool * V_42 )
{
bool V_262 = false ;
struct V_5 * V_6 ;
int V_7 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_14 [ V_7 ] -> V_6 ;
V_42 [ V_7 ] = F_127 ( V_6 , true ) ;
F_129 ( L_8 , V_6 -> V_51 . V_52 ,
V_42 [ V_7 ] ? L_9 : L_10 ) ;
V_262 |= V_42 [ V_7 ] ;
}
if ( V_262 )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_14 [ V_7 ] -> V_6 ;
V_42 [ V_7 ] = F_127 ( V_6 , false ) ;
}
}
static bool F_130 ( struct V_1 * V_2 ,
struct V_209 * * V_256 ,
struct V_263 * V_264 ,
bool * V_42 , int V_132 , int V_133 )
{
int V_151 , V_7 , V_21 ;
bool V_265 = false ;
struct V_15 * V_204 ;
struct V_209 * V_266 , * V_103 ;
if ( V_2 -> V_38 > 1 )
return false ;
V_151 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( V_42 [ V_7 ] )
V_151 ++ ;
}
if ( V_151 <= 1 )
return false ;
V_265 = true ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_42 [ V_7 ] )
continue;
V_204 = V_2 -> V_14 [ V_7 ] ;
V_256 [ V_7 ] = F_125 ( V_204 , V_132 , V_133 ) ;
if ( ! V_256 [ V_7 ] ) {
V_265 = false ;
break;
}
for ( V_21 = 0 ; V_21 < V_7 ; V_21 ++ ) {
if ( ! V_42 [ V_21 ] )
continue;
if ( ! F_131 ( V_256 [ V_21 ] , V_256 [ V_7 ] ) )
V_265 = false ;
}
}
if ( V_265 ) {
F_129 ( L_11 ) ;
return true ;
}
V_265 = true ;
V_266 = F_132 ( V_2 -> V_4 , 1024 , 768 , 60 , false ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_42 [ V_7 ] )
continue;
V_204 = V_2 -> V_14 [ V_7 ] ;
F_17 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_131 ( V_103 , V_266 ) )
V_256 [ V_7 ] = V_103 ;
}
if ( ! V_256 [ V_7 ] )
V_265 = false ;
}
if ( V_265 ) {
F_129 ( L_12 ) ;
return true ;
}
F_115 ( L_13 ) ;
return false ;
}
static int F_133 ( struct V_1 * V_2 ,
struct V_209 * * V_256 ,
struct V_263 * V_264 ,
int V_267 ,
int V_268 , int V_269 )
{
struct V_15 * V_204 ;
int V_7 ;
int V_270 = 0 , V_271 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_204 = V_2 -> V_14 [ V_7 ] ;
if ( ! V_204 -> V_6 -> V_217 )
continue;
if ( ! V_256 [ V_7 ] && ( V_268 || V_269 ) ) {
F_129 ( L_14 , V_7 ,
V_204 -> V_6 -> V_51 . V_52 ) ;
continue;
}
if ( V_204 -> V_6 -> V_218 < V_268 )
V_270 += V_256 [ V_7 ] -> V_214 ;
if ( V_204 -> V_6 -> V_220 < V_269 )
V_271 += V_256 [ V_7 ] -> V_216 ;
}
V_264 [ V_267 ] . V_46 = V_270 ;
V_264 [ V_267 ] . V_47 = V_271 ;
F_129 ( L_15 , V_270 , V_271 , V_268 , V_269 ) ;
return 0 ;
}
static bool F_134 ( struct V_1 * V_2 ,
struct V_209 * * V_256 ,
struct V_263 * V_264 ,
bool * V_42 , int V_132 , int V_133 )
{
struct V_15 * V_204 ;
int V_7 ;
T_9 V_272 = 0 , V_174 ;
int V_273 = 0 ;
V_174 = ( 1 << V_2 -> V_13 ) - 1 ;
V_61:
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_204 = V_2 -> V_14 [ V_7 ] ;
if ( V_272 & ( 1 << V_7 ) )
continue;
if ( V_42 [ V_7 ] == false ) {
V_272 |= ( 1 << V_7 ) ;
continue;
}
if ( V_273 == 0 && V_204 -> V_6 -> V_217 )
continue;
if ( V_273 == 1 ) {
if ( V_204 -> V_6 -> V_218 != 0 ||
V_204 -> V_6 -> V_220 != 0 )
continue;
} else {
if ( V_204 -> V_6 -> V_218 != V_273 - 1 &&
V_204 -> V_6 -> V_220 != V_273 - 1 )
continue;
F_133 ( V_2 , V_256 , V_264 ,
V_7 , V_204 -> V_6 -> V_218 , V_204 -> V_6 -> V_220 ) ;
}
F_129 ( L_16 ,
V_204 -> V_6 -> V_51 . V_52 ) ;
V_256 [ V_7 ] = F_125 ( V_204 , V_132 , V_133 ) ;
if ( ! V_256 [ V_7 ] ) {
F_129 ( L_17 ,
V_204 -> V_6 -> V_51 . V_52 , V_204 -> V_6 -> V_274 ? V_204 -> V_6 -> V_274 -> V_52 : 0 ) ;
V_256 [ V_7 ] = F_123 ( V_204 , V_132 , V_133 ) ;
}
if ( ! V_256 [ V_7 ] && ! F_48 ( & V_204 -> V_6 -> V_256 ) ) {
F_17 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_129 ( L_18 , V_256 [ V_7 ] ? V_256 [ V_7 ] -> V_275 :
L_19 ) ;
V_272 |= ( 1 << V_7 ) ;
}
if ( ( V_272 & V_174 ) != V_174 ) {
V_273 ++ ;
goto V_61;
}
return true ;
}
static int F_135 ( struct V_1 * V_2 ,
struct V_119 * * V_276 ,
struct V_209 * * V_256 ,
int V_277 , int V_132 , int V_133 )
{
int V_50 , V_278 ;
struct V_5 * V_6 ;
const struct V_279 * V_280 ;
struct V_281 * V_282 ;
int V_283 , V_284 , V_285 ;
struct V_119 * * V_286 , * V_24 ;
struct V_15 * V_204 ;
if ( V_277 == V_2 -> V_13 )
return 0 ;
V_204 = V_2 -> V_14 [ V_277 ] ;
V_6 = V_204 -> V_6 ;
V_276 [ V_277 ] = NULL ;
V_284 = F_135 ( V_2 , V_276 , V_256 , V_277 + 1 , V_132 , V_133 ) ;
if ( V_256 [ V_277 ] == NULL )
return V_284 ;
V_286 = F_10 ( V_2 -> V_13 *
sizeof( struct V_119 * ) , V_19 ) ;
if ( ! V_286 )
return V_284 ;
V_283 = 1 ;
if ( V_6 -> V_259 == V_260 )
V_283 ++ ;
if ( F_124 ( V_204 ) )
V_283 ++ ;
if ( F_123 ( V_204 , V_132 , V_133 ) )
V_283 ++ ;
V_280 = V_6 -> V_43 ;
V_282 = V_280 -> V_287 ( V_6 ) ;
if ( ! V_282 )
goto V_187;
for ( V_50 = 0 ; V_50 < V_2 -> V_38 ; V_50 ++ ) {
V_24 = & V_2 -> V_41 [ V_50 ] ;
if ( ( V_282 -> V_288 & ( 1 << V_50 ) ) == 0 )
continue;
for ( V_278 = 0 ; V_278 < V_277 ; V_278 ++ )
if ( V_276 [ V_278 ] == V_24 )
break;
if ( V_278 < V_277 ) {
if ( V_2 -> V_38 > 1 )
continue;
if ( ! F_131 ( V_256 [ V_278 ] , V_256 [ V_277 ] ) )
continue;
}
V_286 [ V_277 ] = V_24 ;
memcpy ( V_286 , V_276 , V_277 * sizeof( struct V_119 * ) ) ;
V_285 = V_283 + F_135 ( V_2 , V_286 , V_256 , V_277 + 1 ,
V_132 , V_133 ) ;
if ( V_285 > V_284 ) {
V_284 = V_285 ;
memcpy ( V_276 , V_286 ,
V_2 -> V_13 *
sizeof( struct V_119 * ) ) ;
}
}
V_187:
F_6 ( V_286 ) ;
return V_284 ;
}
static void F_136 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_119 * * V_286 ;
struct V_209 * * V_256 ;
struct V_263 * V_264 ;
struct V_39 * V_195 ;
bool * V_42 ;
int V_132 , V_133 ;
int V_7 ;
F_129 ( L_20 ) ;
V_132 = V_4 -> V_10 . V_289 ;
V_133 = V_4 -> V_10 . V_290 ;
V_286 = F_66 ( V_2 -> V_13 ,
sizeof( struct V_119 * ) , V_19 ) ;
V_256 = F_66 ( V_2 -> V_13 ,
sizeof( struct V_209 * ) , V_19 ) ;
V_264 = F_66 ( V_2 -> V_13 ,
sizeof( struct V_263 ) , V_19 ) ;
V_42 = F_66 ( V_2 -> V_13 ,
sizeof( bool ) , V_19 ) ;
if ( ! V_286 || ! V_256 || ! V_42 || ! V_264 ) {
F_21 ( L_21 ) ;
goto V_187;
}
F_128 ( V_2 , V_42 ) ;
if ( ! ( V_2 -> V_29 -> V_291 &&
V_2 -> V_29 -> V_291 ( V_2 , V_286 , V_256 ,
V_264 ,
V_42 , V_132 , V_133 ) ) ) {
memset ( V_256 , 0 , V_2 -> V_13 * sizeof( V_256 [ 0 ] ) ) ;
memset ( V_286 , 0 , V_2 -> V_13 * sizeof( V_286 [ 0 ] ) ) ;
memset ( V_264 , 0 , V_2 -> V_13 * sizeof( V_264 [ 0 ] ) ) ;
if ( ! F_130 ( V_2 , V_256 , V_264 ,
V_42 , V_132 , V_133 ) &&
! F_134 ( V_2 , V_256 , V_264 ,
V_42 , V_132 , V_133 ) )
F_21 ( L_22 ) ;
F_129 ( L_23 ,
V_132 , V_133 ) ;
F_135 ( V_2 , V_286 , V_256 , 0 , V_132 , V_133 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
V_195 = & V_2 -> V_41 [ V_7 ] . V_40 ;
V_195 -> V_122 = 0 ;
V_195 -> V_45 = NULL ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_209 * V_103 = V_256 [ V_7 ] ;
struct V_119 * V_292 = V_286 [ V_7 ] ;
struct V_263 * V_172 = & V_264 [ V_7 ] ;
V_195 = & V_292 -> V_40 ;
if ( V_103 && V_292 ) {
F_129 ( L_24 ,
V_103 -> V_275 , V_292 -> V_40 . V_24 -> V_51 . V_52 , V_172 -> V_46 , V_172 -> V_47 ) ;
V_292 -> V_210 = V_103 ;
V_292 -> V_46 = V_172 -> V_46 ;
V_292 -> V_47 = V_172 -> V_47 ;
if ( V_195 -> V_103 )
F_56 ( V_4 , V_195 -> V_103 ) ;
V_195 -> V_103 = F_137 ( V_4 ,
V_292 -> V_210 ) ;
V_195 -> V_102 [ V_195 -> V_122 ++ ] = V_2 -> V_14 [ V_7 ] -> V_6 ;
V_195 -> V_45 = V_2 -> V_45 ;
V_195 -> V_46 = V_172 -> V_46 ;
V_195 -> V_47 = V_172 -> V_47 ;
}
}
for ( V_7 = 0 ; V_7 < V_2 -> V_38 ; V_7 ++ ) {
V_195 = & V_2 -> V_41 [ V_7 ] . V_40 ;
if ( V_195 -> V_122 == 0 ) {
F_138 ( V_195 -> V_45 ) ;
if ( V_195 -> V_103 )
F_56 ( V_4 , V_195 -> V_103 ) ;
V_195 -> V_103 = NULL ;
}
}
V_187:
F_6 ( V_286 ) ;
F_6 ( V_256 ) ;
F_6 ( V_264 ) ;
F_6 ( V_42 ) ;
}
int F_139 ( struct V_1 * V_2 , int V_293 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_151 = 0 ;
if ( ! V_9 )
return 0 ;
F_2 ( & V_4 -> V_10 . V_11 ) ;
V_151 = F_122 ( V_2 ,
V_4 -> V_10 . V_289 ,
V_4 -> V_10 . V_290 ) ;
F_5 ( & V_4 -> V_10 . V_11 ) ;
if ( V_151 == 0 )
F_117 ( V_2 -> V_4 -> V_4 , L_25 ) ;
F_136 ( V_2 ) ;
return F_114 ( V_2 , V_293 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_289 , V_290 ;
if ( ! V_9 )
return 0 ;
F_2 ( & V_2 -> V_4 -> V_10 . V_11 ) ;
if ( ! V_2 -> V_45 || ! F_46 ( V_2 ) ) {
V_2 -> V_76 = true ;
F_5 ( & V_2 -> V_4 -> V_10 . V_11 ) ;
return 0 ;
}
F_129 ( L_20 ) ;
V_289 = V_2 -> V_45 -> V_132 ;
V_290 = V_2 -> V_45 -> V_133 ;
F_122 ( V_2 , V_289 , V_290 ) ;
F_5 ( & V_2 -> V_4 -> V_10 . V_11 ) ;
F_43 ( V_4 ) ;
F_136 ( V_2 ) ;
F_44 ( V_4 ) ;
F_111 ( V_2 -> V_129 ) ;
return 0 ;
}
int T_10 F_140 ( void )
{
#if F_141 ( V_294 ) && ! F_141 ( V_295 )
const char * V_275 = L_26 ;
struct V_296 * V_297 ;
F_2 ( & V_298 ) ;
V_297 = F_142 ( V_275 ) ;
F_5 ( & V_298 ) ;
if ( ! V_297 )
F_143 ( V_275 ) ;
#endif
return 0 ;
}
