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
F_8 (uobj, tmp, &context->rule_list, list) {
struct V_37 * V_38 = V_11 -> V_32 ;
F_16 ( & V_39 , V_11 ) ;
F_19 ( V_38 ) ;
F_5 ( V_11 ) ;
}
F_8 (uobj, tmp, &context->qp_list, list) {
struct V_19 * V_20 = V_11 -> V_32 ;
struct V_21 * V_40 =
F_2 ( V_11 , struct V_21 , V_41 . V_42 ) ;
F_16 ( & V_43 , V_11 ) ;
if ( V_20 != V_20 -> V_44 ) {
F_20 ( V_20 ) ;
} else {
F_13 ( V_20 , V_40 ) ;
F_21 ( V_20 ) ;
}
F_12 ( V_7 , & V_40 -> V_41 ) ;
F_5 ( V_40 ) ;
}
F_8 (uobj, tmp, &context->cq_list, list) {
struct V_45 * V_46 = V_11 -> V_32 ;
struct V_6 * V_9 = V_46 -> V_47 ;
struct V_10 * V_48 =
F_2 ( V_11 , struct V_10 , V_42 ) ;
F_16 ( & V_49 , V_11 ) ;
F_22 ( V_46 ) ;
F_6 ( V_7 , V_9 , V_48 ) ;
F_5 ( V_48 ) ;
}
F_8 (uobj, tmp, &context->srq_list, list) {
struct V_50 * V_51 = V_11 -> V_32 ;
struct V_18 * V_41 =
F_2 ( V_11 , struct V_18 , V_42 ) ;
F_16 ( & V_52 , V_11 ) ;
F_23 ( V_51 ) ;
F_12 ( V_7 , V_41 ) ;
F_5 ( V_41 ) ;
}
F_8 (uobj, tmp, &context->mr_list, list) {
struct V_53 * V_54 = V_11 -> V_32 ;
F_16 ( & V_55 , V_11 ) ;
F_24 ( V_54 ) ;
F_5 ( V_11 ) ;
}
F_25 ( & V_7 -> V_56 -> V_57 ) ;
F_8 (uobj, tmp, &context->xrcd_list, list) {
struct V_58 * V_59 = V_11 -> V_32 ;
struct V_60 * V_61 =
F_2 ( V_11 , struct V_60 , V_42 ) ;
F_16 ( & V_62 , V_11 ) ;
F_26 ( V_7 -> V_56 , V_59 ) ;
F_5 ( V_61 ) ;
}
F_27 ( & V_7 -> V_56 -> V_57 ) ;
F_8 (uobj, tmp, &context->pd_list, list) {
struct V_63 * V_64 = V_11 -> V_32 ;
F_16 ( & V_65 , V_11 ) ;
F_28 ( V_64 ) ;
F_5 ( V_11 ) ;
}
return V_27 -> V_56 -> V_66 ( V_27 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_8 * V_7 =
F_2 ( V_2 , struct V_8 , V_2 ) ;
F_30 ( V_7 -> V_56 -> V_67 -> V_68 ) ;
F_11 ( & V_7 -> V_56 -> V_2 , F_1 ) ;
F_5 ( V_7 ) ;
}
static T_1 F_31 ( struct V_7 * V_69 , char T_2 * V_70 ,
T_3 V_71 , T_4 * V_72 )
{
struct V_6 * V_7 = V_69 -> V_73 ;
struct V_12 * V_74 ;
int V_75 ;
int V_76 = 0 ;
F_7 ( & V_7 -> V_15 ) ;
while ( F_32 ( & V_7 -> V_77 ) ) {
F_10 ( & V_7 -> V_15 ) ;
if ( V_69 -> V_78 & V_79 )
return - V_80 ;
if ( F_33 ( V_7 -> V_81 ,
! F_32 ( & V_7 -> V_77 ) ) )
return - V_82 ;
F_7 ( & V_7 -> V_15 ) ;
}
V_74 = F_34 ( V_7 -> V_77 . V_83 , struct V_12 , V_16 ) ;
if ( V_7 -> V_84 )
V_75 = sizeof ( struct V_85 ) ;
else
V_75 = sizeof ( struct V_86 ) ;
if ( V_75 > V_71 ) {
V_76 = - V_87 ;
V_74 = NULL ;
} else {
F_9 ( V_7 -> V_77 . V_83 ) ;
if ( V_74 -> V_88 ) {
++ ( * V_74 -> V_88 ) ;
F_9 ( & V_74 -> V_89 ) ;
}
}
F_10 ( & V_7 -> V_15 ) ;
if ( V_74 ) {
if ( F_35 ( V_70 , V_74 , V_75 ) )
V_76 = - V_90 ;
else
V_76 = V_75 ;
}
F_5 ( V_74 ) ;
return V_76 ;
}
static unsigned int F_36 ( struct V_7 * V_69 ,
struct V_91 * V_92 )
{
unsigned int V_93 = 0 ;
struct V_6 * V_7 = V_69 -> V_73 ;
V_81 ( V_69 , & V_7 -> V_81 , V_92 ) ;
F_7 ( & V_7 -> V_15 ) ;
if ( ! F_32 ( & V_7 -> V_77 ) )
V_93 = V_94 | V_95 ;
F_10 ( & V_7 -> V_15 ) ;
return V_93 ;
}
static int F_37 ( int V_96 , struct V_7 * V_69 , int V_97 )
{
struct V_6 * V_7 = V_69 -> V_73 ;
return F_38 ( V_96 , V_69 , V_97 , & V_7 -> V_98 ) ;
}
static int F_39 ( struct V_99 * V_99 , struct V_7 * V_69 )
{
struct V_6 * V_7 = V_69 -> V_73 ;
struct V_12 * V_100 , * V_14 ;
F_7 ( & V_7 -> V_15 ) ;
V_7 -> V_101 = 1 ;
F_8 (entry, tmp, &file->event_list, list) {
if ( V_100 -> V_88 )
F_9 ( & V_100 -> V_89 ) ;
F_5 ( V_100 ) ;
}
F_10 ( & V_7 -> V_15 ) ;
if ( V_7 -> V_84 ) {
F_40 ( & V_7 -> V_102 -> V_103 ) ;
F_11 ( & V_7 -> V_102 -> V_2 , F_29 ) ;
}
F_11 ( & V_7 -> V_2 , F_4 ) ;
return 0 ;
}
void F_41 ( struct V_45 * V_46 , void * V_47 )
{
struct V_6 * V_7 = V_47 ;
struct V_10 * V_11 ;
struct V_12 * V_100 ;
unsigned long V_104 ;
if ( ! V_7 )
return;
F_42 ( & V_7 -> V_15 , V_104 ) ;
if ( V_7 -> V_101 ) {
F_43 ( & V_7 -> V_15 , V_104 ) ;
return;
}
V_100 = F_44 ( sizeof *V_100 , V_105 ) ;
if ( ! V_100 ) {
F_43 ( & V_7 -> V_15 , V_104 ) ;
return;
}
V_11 = F_2 ( V_46 -> V_42 , struct V_10 , V_42 ) ;
V_100 -> V_106 . V_5 . V_107 = V_46 -> V_42 -> V_108 ;
V_100 -> V_88 = & V_11 -> V_109 ;
F_45 ( & V_100 -> V_16 , & V_7 -> V_77 ) ;
F_45 ( & V_100 -> V_89 , & V_11 -> V_110 ) ;
F_43 ( & V_7 -> V_15 , V_104 ) ;
F_46 ( & V_7 -> V_81 ) ;
F_47 ( & V_7 -> V_98 , V_111 , V_112 ) ;
}
static void F_48 ( struct V_8 * V_7 ,
T_5 V_113 , T_5 V_74 ,
struct V_114 * V_89 ,
T_6 * V_88 )
{
struct V_12 * V_100 ;
unsigned long V_104 ;
F_42 ( & V_7 -> V_17 -> V_15 , V_104 ) ;
if ( V_7 -> V_17 -> V_101 ) {
F_43 ( & V_7 -> V_17 -> V_15 , V_104 ) ;
return;
}
V_100 = F_44 ( sizeof *V_100 , V_105 ) ;
if ( ! V_100 ) {
F_43 ( & V_7 -> V_17 -> V_15 , V_104 ) ;
return;
}
V_100 -> V_106 . V_115 . V_113 = V_113 ;
V_100 -> V_106 . V_115 . V_116 = V_74 ;
V_100 -> V_88 = V_88 ;
F_45 ( & V_100 -> V_16 , & V_7 -> V_17 -> V_77 ) ;
if ( V_89 )
F_45 ( & V_100 -> V_89 , V_89 ) ;
F_43 ( & V_7 -> V_17 -> V_15 , V_104 ) ;
F_46 ( & V_7 -> V_17 -> V_81 ) ;
F_47 ( & V_7 -> V_17 -> V_98 , V_111 , V_112 ) ;
}
void F_49 ( struct V_117 * V_74 , void * V_118 )
{
struct V_10 * V_11 = F_2 ( V_74 -> V_113 . V_46 -> V_42 ,
struct V_10 , V_42 ) ;
F_48 ( V_11 -> V_102 , V_11 -> V_42 . V_108 ,
V_74 -> V_74 , & V_11 -> V_119 ,
& V_11 -> V_120 ) ;
}
void F_50 ( struct V_117 * V_74 , void * V_118 )
{
struct V_18 * V_11 ;
V_11 = F_2 ( V_74 -> V_113 . V_20 -> V_42 ,
struct V_18 , V_42 ) ;
F_48 ( V_118 , V_11 -> V_42 . V_108 ,
V_74 -> V_74 , & V_11 -> V_77 ,
& V_11 -> V_121 ) ;
}
void F_51 ( struct V_117 * V_74 , void * V_118 )
{
struct V_18 * V_11 ;
V_11 = F_2 ( V_74 -> V_113 . V_51 -> V_42 ,
struct V_18 , V_42 ) ;
F_48 ( V_118 , V_11 -> V_42 . V_108 ,
V_74 -> V_74 , & V_11 -> V_77 ,
& V_11 -> V_121 ) ;
}
void F_52 ( struct V_122 * V_123 ,
struct V_117 * V_74 )
{
struct V_8 * V_7 =
F_2 ( V_123 , struct V_8 , V_103 ) ;
F_48 ( V_7 , V_74 -> V_113 . V_124 , V_74 -> V_74 ,
NULL , NULL ) ;
}
struct V_7 * F_53 ( struct V_8 * V_102 ,
int V_84 )
{
struct V_6 * V_9 ;
struct V_7 * V_69 ;
V_9 = F_44 ( sizeof *V_9 , V_125 ) ;
if ( ! V_9 )
return F_54 ( - V_126 ) ;
F_55 ( & V_9 -> V_2 ) ;
F_56 ( & V_9 -> V_15 ) ;
F_57 ( & V_9 -> V_77 ) ;
F_58 ( & V_9 -> V_81 ) ;
V_9 -> V_102 = V_102 ;
V_9 -> V_98 = NULL ;
V_9 -> V_84 = V_84 ;
V_9 -> V_101 = 0 ;
V_69 = F_59 ( L_1 , & V_127 ,
V_9 , V_128 ) ;
if ( F_60 ( V_69 ) )
F_5 ( V_9 ) ;
return V_69 ;
}
struct V_6 * F_61 ( int V_96 )
{
struct V_6 * V_9 = NULL ;
struct V_96 V_129 = F_62 ( V_96 ) ;
if ( ! V_129 . V_7 )
return NULL ;
if ( V_129 . V_7 -> V_130 != & V_127 )
goto V_131;
V_9 = V_129 . V_7 -> V_73 ;
if ( V_9 -> V_84 ) {
V_9 = NULL ;
goto V_131;
}
F_63 ( & V_9 -> V_2 ) ;
V_131:
F_64 ( V_129 ) ;
return V_9 ;
}
static T_1 F_65 ( struct V_7 * V_69 , const char T_2 * V_70 ,
T_3 V_71 , T_4 * V_72 )
{
struct V_8 * V_7 = V_69 -> V_73 ;
struct V_132 V_133 ;
if ( V_71 < sizeof V_133 )
return - V_87 ;
if ( F_66 ( & V_133 , V_70 , sizeof V_133 ) )
return - V_90 ;
if ( V_133 . V_134 >= F_67 ( V_135 ) ||
! V_135 [ V_133 . V_134 ] )
return - V_87 ;
if ( ! V_7 -> V_136 &&
V_133 . V_134 != V_137 )
return - V_87 ;
if ( ! ( V_7 -> V_56 -> V_67 -> V_138 & ( 1ull << V_133 . V_134 ) ) )
return - V_139 ;
#ifdef F_68
if ( V_133 . V_134 >= V_140 ) {
struct V_141 V_142 ;
if ( F_66 ( & V_142 , V_70 , sizeof( V_142 ) ) )
return - V_90 ;
if ( ( ( V_142 . V_143 + V_142 . V_144 ) * 4 ) != V_71 )
return - V_87 ;
return V_135 [ V_133 . V_134 ] ( V_7 ,
V_70 + sizeof( V_142 ) ,
( V_142 . V_143 +
V_142 . V_144 ) * 4 ,
( V_142 . V_145 +
V_142 . V_146 ) * 4 ) ;
} else {
#endif
if ( V_133 . V_143 * 4 != V_71 )
return - V_87 ;
return V_135 [ V_133 . V_134 ] ( V_7 ,
V_70 + sizeof( V_133 ) ,
V_133 . V_143 * 4 ,
V_133 . V_145 * 4 ) ;
#ifdef F_68
}
#endif
}
static int F_69 ( struct V_7 * V_69 , struct V_147 * V_148 )
{
struct V_8 * V_7 = V_69 -> V_73 ;
if ( ! V_7 -> V_136 )
return - V_149 ;
else
return V_7 -> V_56 -> V_67 -> V_150 ( V_7 -> V_136 , V_148 ) ;
}
static int F_70 ( struct V_99 * V_99 , struct V_7 * V_69 )
{
struct V_3 * V_4 ;
struct V_8 * V_7 ;
int V_76 ;
V_4 = F_2 ( V_99 -> V_151 , struct V_3 , V_152 ) ;
if ( V_4 )
F_63 ( & V_4 -> V_2 ) ;
else
return - V_153 ;
if ( ! F_71 ( V_4 -> V_67 -> V_68 ) ) {
V_76 = - V_149 ;
goto V_154;
}
V_7 = F_44 ( sizeof *V_7 , V_125 ) ;
if ( ! V_7 ) {
V_76 = - V_126 ;
goto V_155;
}
V_7 -> V_56 = V_4 ;
V_7 -> V_136 = NULL ;
V_7 -> V_17 = NULL ;
F_55 ( & V_7 -> V_2 ) ;
F_72 ( & V_7 -> V_156 ) ;
V_69 -> V_73 = V_7 ;
return F_73 ( V_99 , V_69 ) ;
V_155:
F_30 ( V_4 -> V_67 -> V_68 ) ;
V_154:
F_11 ( & V_4 -> V_2 , F_1 ) ;
return V_76 ;
}
static int F_74 ( struct V_99 * V_99 , struct V_7 * V_69 )
{
struct V_8 * V_7 = V_69 -> V_73 ;
F_15 ( V_7 , V_7 -> V_136 ) ;
if ( V_7 -> V_17 )
F_11 ( & V_7 -> V_17 -> V_2 , F_4 ) ;
F_11 ( & V_7 -> V_2 , F_29 ) ;
return 0 ;
}
static T_1 F_75 ( struct V_56 * V_56 , struct V_157 * V_158 ,
char * V_70 )
{
struct V_3 * V_4 = F_76 ( V_56 ) ;
if ( ! V_4 )
return - V_149 ;
return sprintf ( V_70 , L_2 , V_4 -> V_67 -> V_159 ) ;
}
static T_1 F_77 ( struct V_56 * V_56 ,
struct V_157 * V_158 , char * V_70 )
{
struct V_3 * V_4 = F_76 ( V_56 ) ;
if ( ! V_4 )
return - V_149 ;
return sprintf ( V_70 , L_3 , V_4 -> V_67 -> V_160 ) ;
}
static int F_78 ( void )
{
int V_76 ;
if ( ! V_161 ) {
V_76 = F_79 ( & V_161 , 0 , V_162 ,
L_4 ) ;
if ( V_76 ) {
F_80 ( V_163 L_5 ) ;
return V_76 ;
}
}
V_76 = F_81 ( V_164 , V_162 ) ;
if ( V_76 >= V_162 )
return - 1 ;
return V_76 ;
}
static void F_82 ( struct V_165 * V_56 )
{
int V_166 ;
T_7 V_167 ;
struct V_3 * V_168 ;
if ( ! V_56 -> V_169 )
return;
V_168 = F_83 ( sizeof *V_168 , V_125 ) ;
if ( ! V_168 )
return;
F_55 ( & V_168 -> V_2 ) ;
F_84 ( & V_168 -> V_5 ) ;
V_168 -> V_170 = V_171 ;
F_72 ( & V_168 -> V_57 ) ;
F_85 ( & V_172 ) ;
V_166 = F_81 ( V_173 , V_162 ) ;
if ( V_166 >= V_162 ) {
F_86 ( & V_172 ) ;
V_166 = F_78 () ;
if ( V_166 < 0 )
goto V_154;
F_85 ( & V_172 ) ;
V_168 -> V_166 = V_166 + V_162 ;
V_167 = V_166 + V_161 ;
F_87 ( V_166 , V_164 ) ;
} else {
V_168 -> V_166 = V_166 ;
V_167 = V_166 + V_174 ;
F_87 ( V_166 , V_173 ) ;
}
F_86 ( & V_172 ) ;
V_168 -> V_67 = V_56 ;
V_168 -> V_175 = V_56 -> V_175 ;
F_88 ( & V_168 -> V_152 , NULL ) ;
V_168 -> V_152 . V_68 = V_176 ;
V_168 -> V_152 . V_177 = V_56 -> V_150 ? & V_178 : & V_179 ;
F_89 ( & V_168 -> V_152 . V_180 , L_6 , V_168 -> V_166 ) ;
if ( F_90 ( & V_168 -> V_152 , V_167 , 1 ) )
goto V_181;
V_168 -> V_4 = F_91 ( V_182 , V_56 -> V_183 ,
V_168 -> V_152 . V_4 , V_168 ,
L_6 , V_168 -> V_166 ) ;
if ( F_60 ( V_168 -> V_4 ) )
goto V_181;
if ( F_92 ( V_168 -> V_4 , & V_184 ) )
goto V_185;
if ( F_92 ( V_168 -> V_4 , & V_186 ) )
goto V_185;
F_93 ( V_56 , & V_187 , V_168 ) ;
return;
V_185:
F_94 ( V_182 , V_168 -> V_152 . V_4 ) ;
V_181:
F_95 ( & V_168 -> V_152 ) ;
if ( V_168 -> V_166 < V_162 )
F_96 ( V_166 , V_173 ) ;
else
F_96 ( V_166 , V_164 ) ;
V_154:
F_11 ( & V_168 -> V_2 , F_1 ) ;
F_97 ( & V_168 -> V_5 ) ;
F_5 ( V_168 ) ;
return;
}
static void F_98 ( struct V_165 * V_56 )
{
struct V_3 * V_168 = F_99 ( V_56 , & V_187 ) ;
if ( ! V_168 )
return;
F_100 ( V_168 -> V_4 , NULL ) ;
F_94 ( V_182 , V_168 -> V_152 . V_4 ) ;
F_95 ( & V_168 -> V_152 ) ;
if ( V_168 -> V_166 < V_162 )
F_96 ( V_168 -> V_166 , V_173 ) ;
else
F_96 ( V_168 -> V_166 - V_162 , V_164 ) ;
F_11 ( & V_168 -> V_2 , F_1 ) ;
F_97 ( & V_168 -> V_5 ) ;
F_5 ( V_168 ) ;
}
static char * F_101 ( struct V_56 * V_4 , T_8 * V_188 )
{
if ( V_188 )
* V_188 = 0666 ;
return F_102 ( V_125 , L_7 , F_103 ( V_4 ) ) ;
}
static int T_9 F_104 ( void )
{
int V_76 ;
V_76 = F_105 ( V_174 , V_162 ,
L_4 ) ;
if ( V_76 ) {
F_80 ( V_163 L_8 ) ;
goto V_131;
}
V_182 = F_106 ( V_176 , L_4 ) ;
if ( F_60 ( V_182 ) ) {
V_76 = F_107 ( V_182 ) ;
F_80 ( V_163 L_9 ) ;
goto V_189;
}
V_182 -> V_190 = F_101 ;
V_76 = F_108 ( V_182 , & V_191 . V_158 ) ;
if ( V_76 ) {
F_80 ( V_163 L_10 ) ;
goto V_192;
}
V_76 = F_109 ( & V_187 ) ;
if ( V_76 ) {
F_80 ( V_163 L_11 ) ;
goto V_192;
}
return 0 ;
V_192:
F_110 ( V_182 ) ;
V_189:
F_111 ( V_174 , V_162 ) ;
V_131:
return V_76 ;
}
static void T_10 F_112 ( void )
{
F_113 ( & V_187 ) ;
F_110 ( V_182 ) ;
F_111 ( V_174 , V_162 ) ;
if ( V_161 )
F_111 ( V_161 , V_162 ) ;
F_114 ( & V_65 ) ;
F_114 ( & V_55 ) ;
F_114 ( & V_36 ) ;
F_114 ( & V_33 ) ;
F_114 ( & V_49 ) ;
F_114 ( & V_43 ) ;
F_114 ( & V_52 ) ;
}
