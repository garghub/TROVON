static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( & V_4 -> V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
F_5 ( V_7 ) ;
}
void F_6 ( struct V_8 * V_7 ,
struct V_6 * V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 , * V_14 ;
if ( V_9 ) {
F_7 ( & V_9 -> V_15 ) ;
F_8 (evt, tmp, &uobj->comp_list, obj_list) {
F_9 ( & V_13 -> V_16 ) ;
F_5 ( V_13 ) ;
}
F_10 ( & V_9 -> V_15 ) ;
F_11 ( & V_9 -> V_2 , F_4 ) ;
}
F_7 ( & V_7 -> V_17 -> V_15 ) ;
F_8 (evt, tmp, &uobj->async_list, obj_list) {
F_9 ( & V_13 -> V_16 ) ;
F_5 ( V_13 ) ;
}
F_10 ( & V_7 -> V_17 -> V_15 ) ;
}
void F_12 ( struct V_8 * V_7 ,
struct V_18 * V_11 )
{
struct V_12 * V_13 , * V_14 ;
F_7 ( & V_7 -> V_17 -> V_15 ) ;
F_8 (evt, tmp, &uobj->event_list, obj_list) {
F_9 ( & V_13 -> V_16 ) ;
F_5 ( V_13 ) ;
}
F_10 ( & V_7 -> V_17 -> V_15 ) ;
}
static void F_13 ( struct V_19 * V_20 ,
struct V_21 * V_11 )
{
struct V_22 * V_23 , * V_14 ;
F_8 (mcast, tmp, &uobj->mcast_list, list) {
F_14 ( V_20 , & V_23 -> V_24 , V_23 -> V_25 ) ;
F_9 ( & V_23 -> V_16 ) ;
F_5 ( V_23 ) ;
}
}
static int F_15 ( struct V_8 * V_7 ,
struct V_26 * V_27 )
{
struct V_28 * V_11 , * V_14 ;
if ( ! V_27 )
return 0 ;
V_27 -> V_29 = 1 ;
F_8 (uobj, tmp, &context->ah_list, list) {
struct V_30 * V_31 = V_11 -> V_32 ;
F_16 ( & V_33 , V_11 ) ;
F_17 ( V_31 ) ;
F_5 ( V_11 ) ;
}
F_8 (uobj, tmp, &context->mw_list, list) {
struct V_34 * V_35 = V_11 -> V_32 ;
F_16 ( & V_36 , V_11 ) ;
F_18 ( V_35 ) ;
F_5 ( V_11 ) ;
}
F_8 (uobj, tmp, &context->qp_list, list) {
struct V_19 * V_20 = V_11 -> V_32 ;
struct V_21 * V_37 =
F_2 ( V_11 , struct V_21 , V_38 . V_39 ) ;
F_16 ( & V_40 , V_11 ) ;
if ( V_20 != V_20 -> V_41 ) {
F_19 ( V_20 ) ;
} else {
F_13 ( V_20 , V_37 ) ;
F_20 ( V_20 ) ;
}
F_12 ( V_7 , & V_37 -> V_38 ) ;
F_5 ( V_37 ) ;
}
F_8 (uobj, tmp, &context->cq_list, list) {
struct V_42 * V_43 = V_11 -> V_32 ;
struct V_6 * V_9 = V_43 -> V_44 ;
struct V_10 * V_45 =
F_2 ( V_11 , struct V_10 , V_39 ) ;
F_16 ( & V_46 , V_11 ) ;
F_21 ( V_43 ) ;
F_6 ( V_7 , V_9 , V_45 ) ;
F_5 ( V_45 ) ;
}
F_8 (uobj, tmp, &context->srq_list, list) {
struct V_47 * V_48 = V_11 -> V_32 ;
struct V_18 * V_38 =
F_2 ( V_11 , struct V_18 , V_39 ) ;
F_16 ( & V_49 , V_11 ) ;
F_22 ( V_48 ) ;
F_12 ( V_7 , V_38 ) ;
F_5 ( V_38 ) ;
}
F_8 (uobj, tmp, &context->mr_list, list) {
struct V_50 * V_51 = V_11 -> V_32 ;
F_16 ( & V_52 , V_11 ) ;
F_23 ( V_51 ) ;
F_5 ( V_11 ) ;
}
F_24 ( & V_7 -> V_53 -> V_54 ) ;
F_8 (uobj, tmp, &context->xrcd_list, list) {
struct V_55 * V_56 = V_11 -> V_32 ;
struct V_57 * V_58 =
F_2 ( V_11 , struct V_57 , V_39 ) ;
F_16 ( & V_59 , V_11 ) ;
F_25 ( V_7 -> V_53 , V_56 ) ;
F_5 ( V_58 ) ;
}
F_26 ( & V_7 -> V_53 -> V_54 ) ;
F_8 (uobj, tmp, &context->pd_list, list) {
struct V_60 * V_61 = V_11 -> V_32 ;
F_16 ( & V_62 , V_11 ) ;
F_27 ( V_61 ) ;
F_5 ( V_11 ) ;
}
return V_27 -> V_53 -> V_63 ( V_27 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_8 * V_7 =
F_2 ( V_2 , struct V_8 , V_2 ) ;
F_29 ( V_7 -> V_53 -> V_64 -> V_65 ) ;
F_11 ( & V_7 -> V_53 -> V_2 , F_1 ) ;
F_5 ( V_7 ) ;
}
static T_1 F_30 ( struct V_7 * V_66 , char T_2 * V_67 ,
T_3 V_68 , T_4 * V_69 )
{
struct V_6 * V_7 = V_66 -> V_70 ;
struct V_12 * V_71 ;
int V_72 ;
int V_73 = 0 ;
F_7 ( & V_7 -> V_15 ) ;
while ( F_31 ( & V_7 -> V_74 ) ) {
F_10 ( & V_7 -> V_15 ) ;
if ( V_66 -> V_75 & V_76 )
return - V_77 ;
if ( F_32 ( V_7 -> V_78 ,
! F_31 ( & V_7 -> V_74 ) ) )
return - V_79 ;
F_7 ( & V_7 -> V_15 ) ;
}
V_71 = F_33 ( V_7 -> V_74 . V_80 , struct V_12 , V_16 ) ;
if ( V_7 -> V_81 )
V_72 = sizeof ( struct V_82 ) ;
else
V_72 = sizeof ( struct V_83 ) ;
if ( V_72 > V_68 ) {
V_73 = - V_84 ;
V_71 = NULL ;
} else {
F_9 ( V_7 -> V_74 . V_80 ) ;
if ( V_71 -> V_85 ) {
++ ( * V_71 -> V_85 ) ;
F_9 ( & V_71 -> V_86 ) ;
}
}
F_10 ( & V_7 -> V_15 ) ;
if ( V_71 ) {
if ( F_34 ( V_67 , V_71 , V_72 ) )
V_73 = - V_87 ;
else
V_73 = V_72 ;
}
F_5 ( V_71 ) ;
return V_73 ;
}
static unsigned int F_35 ( struct V_7 * V_66 ,
struct V_88 * V_89 )
{
unsigned int V_90 = 0 ;
struct V_6 * V_7 = V_66 -> V_70 ;
V_78 ( V_66 , & V_7 -> V_78 , V_89 ) ;
F_7 ( & V_7 -> V_15 ) ;
if ( ! F_31 ( & V_7 -> V_74 ) )
V_90 = V_91 | V_92 ;
F_10 ( & V_7 -> V_15 ) ;
return V_90 ;
}
static int F_36 ( int V_93 , struct V_7 * V_66 , int V_94 )
{
struct V_6 * V_7 = V_66 -> V_70 ;
return F_37 ( V_93 , V_66 , V_94 , & V_7 -> V_95 ) ;
}
static int F_38 ( struct V_96 * V_96 , struct V_7 * V_66 )
{
struct V_6 * V_7 = V_66 -> V_70 ;
struct V_12 * V_97 , * V_14 ;
F_7 ( & V_7 -> V_15 ) ;
V_7 -> V_98 = 1 ;
F_8 (entry, tmp, &file->event_list, list) {
if ( V_97 -> V_85 )
F_9 ( & V_97 -> V_86 ) ;
F_5 ( V_97 ) ;
}
F_10 ( & V_7 -> V_15 ) ;
if ( V_7 -> V_81 ) {
F_39 ( & V_7 -> V_99 -> V_100 ) ;
F_11 ( & V_7 -> V_99 -> V_2 , F_28 ) ;
}
F_11 ( & V_7 -> V_2 , F_4 ) ;
return 0 ;
}
void F_40 ( struct V_42 * V_43 , void * V_44 )
{
struct V_6 * V_7 = V_44 ;
struct V_10 * V_11 ;
struct V_12 * V_97 ;
unsigned long V_101 ;
if ( ! V_7 )
return;
F_41 ( & V_7 -> V_15 , V_101 ) ;
if ( V_7 -> V_98 ) {
F_42 ( & V_7 -> V_15 , V_101 ) ;
return;
}
V_97 = F_43 ( sizeof *V_97 , V_102 ) ;
if ( ! V_97 ) {
F_42 ( & V_7 -> V_15 , V_101 ) ;
return;
}
V_11 = F_2 ( V_43 -> V_39 , struct V_10 , V_39 ) ;
V_97 -> V_103 . V_5 . V_104 = V_43 -> V_39 -> V_105 ;
V_97 -> V_85 = & V_11 -> V_106 ;
F_44 ( & V_97 -> V_16 , & V_7 -> V_74 ) ;
F_44 ( & V_97 -> V_86 , & V_11 -> V_107 ) ;
F_42 ( & V_7 -> V_15 , V_101 ) ;
F_45 ( & V_7 -> V_78 ) ;
F_46 ( & V_7 -> V_95 , V_108 , V_109 ) ;
}
static void F_47 ( struct V_8 * V_7 ,
T_5 V_110 , T_5 V_71 ,
struct V_111 * V_86 ,
T_6 * V_85 )
{
struct V_12 * V_97 ;
unsigned long V_101 ;
F_41 ( & V_7 -> V_17 -> V_15 , V_101 ) ;
if ( V_7 -> V_17 -> V_98 ) {
F_42 ( & V_7 -> V_17 -> V_15 , V_101 ) ;
return;
}
V_97 = F_43 ( sizeof *V_97 , V_102 ) ;
if ( ! V_97 ) {
F_42 ( & V_7 -> V_17 -> V_15 , V_101 ) ;
return;
}
V_97 -> V_103 . V_112 . V_110 = V_110 ;
V_97 -> V_103 . V_112 . V_113 = V_71 ;
V_97 -> V_85 = V_85 ;
F_44 ( & V_97 -> V_16 , & V_7 -> V_17 -> V_74 ) ;
if ( V_86 )
F_44 ( & V_97 -> V_86 , V_86 ) ;
F_42 ( & V_7 -> V_17 -> V_15 , V_101 ) ;
F_45 ( & V_7 -> V_17 -> V_78 ) ;
F_46 ( & V_7 -> V_17 -> V_95 , V_108 , V_109 ) ;
}
void F_48 ( struct V_114 * V_71 , void * V_115 )
{
struct V_10 * V_11 = F_2 ( V_71 -> V_110 . V_43 -> V_39 ,
struct V_10 , V_39 ) ;
F_47 ( V_11 -> V_99 , V_11 -> V_39 . V_105 ,
V_71 -> V_71 , & V_11 -> V_116 ,
& V_11 -> V_117 ) ;
}
void F_49 ( struct V_114 * V_71 , void * V_115 )
{
struct V_18 * V_11 ;
V_11 = F_2 ( V_71 -> V_110 . V_20 -> V_39 ,
struct V_18 , V_39 ) ;
F_47 ( V_115 , V_11 -> V_39 . V_105 ,
V_71 -> V_71 , & V_11 -> V_74 ,
& V_11 -> V_118 ) ;
}
void F_50 ( struct V_114 * V_71 , void * V_115 )
{
struct V_18 * V_11 ;
V_11 = F_2 ( V_71 -> V_110 . V_48 -> V_39 ,
struct V_18 , V_39 ) ;
F_47 ( V_115 , V_11 -> V_39 . V_105 ,
V_71 -> V_71 , & V_11 -> V_74 ,
& V_11 -> V_118 ) ;
}
void F_51 ( struct V_119 * V_120 ,
struct V_114 * V_71 )
{
struct V_8 * V_7 =
F_2 ( V_120 , struct V_8 , V_100 ) ;
F_47 ( V_7 , V_71 -> V_110 . V_121 , V_71 -> V_71 ,
NULL , NULL ) ;
}
struct V_7 * F_52 ( struct V_8 * V_99 ,
int V_81 )
{
struct V_6 * V_9 ;
struct V_7 * V_66 ;
V_9 = F_43 ( sizeof *V_9 , V_122 ) ;
if ( ! V_9 )
return F_53 ( - V_123 ) ;
F_54 ( & V_9 -> V_2 ) ;
F_55 ( & V_9 -> V_15 ) ;
F_56 ( & V_9 -> V_74 ) ;
F_57 ( & V_9 -> V_78 ) ;
V_9 -> V_99 = V_99 ;
V_9 -> V_95 = NULL ;
V_9 -> V_81 = V_81 ;
V_9 -> V_98 = 0 ;
V_66 = F_58 ( L_1 , & V_124 ,
V_9 , V_125 ) ;
if ( F_59 ( V_66 ) )
F_5 ( V_9 ) ;
return V_66 ;
}
struct V_6 * F_60 ( int V_93 )
{
struct V_6 * V_9 = NULL ;
struct V_93 V_126 = F_61 ( V_93 ) ;
if ( ! V_126 . V_7 )
return NULL ;
if ( V_126 . V_7 -> V_127 != & V_124 )
goto V_128;
V_9 = V_126 . V_7 -> V_70 ;
if ( V_9 -> V_81 ) {
V_9 = NULL ;
goto V_128;
}
F_62 ( & V_9 -> V_2 ) ;
V_128:
F_63 ( V_126 ) ;
return V_9 ;
}
static T_1 F_64 ( struct V_7 * V_66 , const char T_2 * V_67 ,
T_3 V_68 , T_4 * V_69 )
{
struct V_8 * V_7 = V_66 -> V_70 ;
struct V_129 V_130 ;
if ( V_68 < sizeof V_130 )
return - V_84 ;
if ( F_65 ( & V_130 , V_67 , sizeof V_130 ) )
return - V_87 ;
if ( V_130 . V_131 * 4 != V_68 )
return - V_84 ;
if ( V_130 . V_132 >= F_66 ( V_133 ) ||
! V_133 [ V_130 . V_132 ] )
return - V_84 ;
if ( ! V_7 -> V_134 &&
V_130 . V_132 != V_135 )
return - V_84 ;
if ( ! ( V_7 -> V_53 -> V_64 -> V_136 & ( 1ull << V_130 . V_132 ) ) )
return - V_137 ;
return V_133 [ V_130 . V_132 ] ( V_7 , V_67 + sizeof V_130 ,
V_130 . V_131 * 4 , V_130 . V_138 * 4 ) ;
}
static int F_67 ( struct V_7 * V_66 , struct V_139 * V_140 )
{
struct V_8 * V_7 = V_66 -> V_70 ;
if ( ! V_7 -> V_134 )
return - V_141 ;
else
return V_7 -> V_53 -> V_64 -> V_142 ( V_7 -> V_134 , V_140 ) ;
}
static int F_68 ( struct V_96 * V_96 , struct V_7 * V_66 )
{
struct V_3 * V_4 ;
struct V_8 * V_7 ;
int V_73 ;
V_4 = F_2 ( V_96 -> V_143 , struct V_3 , V_144 ) ;
if ( V_4 )
F_62 ( & V_4 -> V_2 ) ;
else
return - V_145 ;
if ( ! F_69 ( V_4 -> V_64 -> V_65 ) ) {
V_73 = - V_141 ;
goto V_146;
}
V_7 = F_43 ( sizeof *V_7 , V_122 ) ;
if ( ! V_7 ) {
V_73 = - V_123 ;
goto V_147;
}
V_7 -> V_53 = V_4 ;
V_7 -> V_134 = NULL ;
V_7 -> V_17 = NULL ;
F_54 ( & V_7 -> V_2 ) ;
F_70 ( & V_7 -> V_148 ) ;
V_66 -> V_70 = V_7 ;
return F_71 ( V_96 , V_66 ) ;
V_147:
F_29 ( V_4 -> V_64 -> V_65 ) ;
V_146:
F_11 ( & V_4 -> V_2 , F_1 ) ;
return V_73 ;
}
static int F_72 ( struct V_96 * V_96 , struct V_7 * V_66 )
{
struct V_8 * V_7 = V_66 -> V_70 ;
F_15 ( V_7 , V_7 -> V_134 ) ;
if ( V_7 -> V_17 )
F_11 ( & V_7 -> V_17 -> V_2 , F_4 ) ;
F_11 ( & V_7 -> V_2 , F_28 ) ;
return 0 ;
}
static T_1 F_73 ( struct V_53 * V_53 , struct V_149 * V_150 ,
char * V_67 )
{
struct V_3 * V_4 = F_74 ( V_53 ) ;
if ( ! V_4 )
return - V_141 ;
return sprintf ( V_67 , L_2 , V_4 -> V_64 -> V_151 ) ;
}
static T_1 F_75 ( struct V_53 * V_53 ,
struct V_149 * V_150 , char * V_67 )
{
struct V_3 * V_4 = F_74 ( V_53 ) ;
if ( ! V_4 )
return - V_141 ;
return sprintf ( V_67 , L_3 , V_4 -> V_64 -> V_152 ) ;
}
static int F_76 ( void )
{
int V_73 ;
if ( ! V_153 ) {
V_73 = F_77 ( & V_153 , 0 , V_154 ,
L_4 ) ;
if ( V_73 ) {
F_78 ( V_155 L_5 ) ;
return V_73 ;
}
}
V_73 = F_79 ( V_156 , V_154 ) ;
if ( V_73 >= V_154 )
return - 1 ;
return V_73 ;
}
static void F_80 ( struct V_157 * V_53 )
{
int V_158 ;
T_7 V_159 ;
struct V_3 * V_160 ;
if ( ! V_53 -> V_161 )
return;
V_160 = F_81 ( sizeof *V_160 , V_122 ) ;
if ( ! V_160 )
return;
F_54 ( & V_160 -> V_2 ) ;
F_82 ( & V_160 -> V_5 ) ;
V_160 -> V_162 = V_163 ;
F_70 ( & V_160 -> V_54 ) ;
F_83 ( & V_164 ) ;
V_158 = F_79 ( V_165 , V_154 ) ;
if ( V_158 >= V_154 ) {
F_84 ( & V_164 ) ;
V_158 = F_76 () ;
if ( V_158 < 0 )
goto V_146;
F_83 ( & V_164 ) ;
V_160 -> V_158 = V_158 + V_154 ;
V_159 = V_158 + V_153 ;
F_85 ( V_158 , V_156 ) ;
} else {
V_160 -> V_158 = V_158 ;
V_159 = V_158 + V_166 ;
F_85 ( V_158 , V_165 ) ;
}
F_84 ( & V_164 ) ;
V_160 -> V_64 = V_53 ;
V_160 -> V_167 = V_53 -> V_167 ;
F_86 ( & V_160 -> V_144 , NULL ) ;
V_160 -> V_144 . V_65 = V_168 ;
V_160 -> V_144 . V_169 = V_53 -> V_142 ? & V_170 : & V_171 ;
F_87 ( & V_160 -> V_144 . V_172 , L_6 , V_160 -> V_158 ) ;
if ( F_88 ( & V_160 -> V_144 , V_159 , 1 ) )
goto V_173;
V_160 -> V_4 = F_89 ( V_174 , V_53 -> V_175 ,
V_160 -> V_144 . V_4 , V_160 ,
L_6 , V_160 -> V_158 ) ;
if ( F_59 ( V_160 -> V_4 ) )
goto V_173;
if ( F_90 ( V_160 -> V_4 , & V_176 ) )
goto V_177;
if ( F_90 ( V_160 -> V_4 , & V_178 ) )
goto V_177;
F_91 ( V_53 , & V_179 , V_160 ) ;
return;
V_177:
F_92 ( V_174 , V_160 -> V_144 . V_4 ) ;
V_173:
F_93 ( & V_160 -> V_144 ) ;
if ( V_160 -> V_158 < V_154 )
F_94 ( V_158 , V_165 ) ;
else
F_94 ( V_158 , V_156 ) ;
V_146:
F_11 ( & V_160 -> V_2 , F_1 ) ;
F_95 ( & V_160 -> V_5 ) ;
F_5 ( V_160 ) ;
return;
}
static void F_96 ( struct V_157 * V_53 )
{
struct V_3 * V_160 = F_97 ( V_53 , & V_179 ) ;
if ( ! V_160 )
return;
F_98 ( V_160 -> V_4 , NULL ) ;
F_92 ( V_174 , V_160 -> V_144 . V_4 ) ;
F_93 ( & V_160 -> V_144 ) ;
if ( V_160 -> V_158 < V_154 )
F_94 ( V_160 -> V_158 , V_165 ) ;
else
F_94 ( V_160 -> V_158 - V_154 , V_156 ) ;
F_11 ( & V_160 -> V_2 , F_1 ) ;
F_95 ( & V_160 -> V_5 ) ;
F_5 ( V_160 ) ;
}
static char * F_99 ( struct V_53 * V_4 , T_8 * V_180 )
{
if ( V_180 )
* V_180 = 0666 ;
return F_100 ( V_122 , L_7 , F_101 ( V_4 ) ) ;
}
static int T_9 F_102 ( void )
{
int V_73 ;
V_73 = F_103 ( V_166 , V_154 ,
L_4 ) ;
if ( V_73 ) {
F_78 ( V_155 L_8 ) ;
goto V_128;
}
V_174 = F_104 ( V_168 , L_4 ) ;
if ( F_59 ( V_174 ) ) {
V_73 = F_105 ( V_174 ) ;
F_78 ( V_155 L_9 ) ;
goto V_181;
}
V_174 -> V_182 = F_99 ;
V_73 = F_106 ( V_174 , & V_183 . V_150 ) ;
if ( V_73 ) {
F_78 ( V_155 L_10 ) ;
goto V_184;
}
V_73 = F_107 ( & V_179 ) ;
if ( V_73 ) {
F_78 ( V_155 L_11 ) ;
goto V_184;
}
return 0 ;
V_184:
F_108 ( V_174 ) ;
V_181:
F_109 ( V_166 , V_154 ) ;
V_128:
return V_73 ;
}
static void T_10 F_110 ( void )
{
F_111 ( & V_179 ) ;
F_108 ( V_174 ) ;
F_109 ( V_166 , V_154 ) ;
if ( V_153 )
F_109 ( V_153 , V_154 ) ;
F_112 ( & V_62 ) ;
F_112 ( & V_52 ) ;
F_112 ( & V_36 ) ;
F_112 ( & V_33 ) ;
F_112 ( & V_46 ) ;
F_112 ( & V_40 ) ;
F_112 ( & V_49 ) ;
}
