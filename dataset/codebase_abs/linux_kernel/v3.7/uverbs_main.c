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
F_8 (uobj, tmp, &context->qp_list, list) {
struct V_19 * V_20 = V_11 -> V_32 ;
struct V_21 * V_34 =
F_2 ( V_11 , struct V_21 , V_35 . V_36 ) ;
F_16 ( & V_37 , V_11 ) ;
if ( V_20 != V_20 -> V_38 ) {
F_18 ( V_20 ) ;
} else {
F_13 ( V_20 , V_34 ) ;
F_19 ( V_20 ) ;
}
F_12 ( V_7 , & V_34 -> V_35 ) ;
F_5 ( V_34 ) ;
}
F_8 (uobj, tmp, &context->cq_list, list) {
struct V_39 * V_40 = V_11 -> V_32 ;
struct V_6 * V_9 = V_40 -> V_41 ;
struct V_10 * V_42 =
F_2 ( V_11 , struct V_10 , V_36 ) ;
F_16 ( & V_43 , V_11 ) ;
F_20 ( V_40 ) ;
F_6 ( V_7 , V_9 , V_42 ) ;
F_5 ( V_42 ) ;
}
F_8 (uobj, tmp, &context->srq_list, list) {
struct V_44 * V_45 = V_11 -> V_32 ;
struct V_18 * V_35 =
F_2 ( V_11 , struct V_18 , V_36 ) ;
F_16 ( & V_46 , V_11 ) ;
F_21 ( V_45 ) ;
F_12 ( V_7 , V_35 ) ;
F_5 ( V_35 ) ;
}
F_8 (uobj, tmp, &context->mr_list, list) {
struct V_47 * V_48 = V_11 -> V_32 ;
F_16 ( & V_49 , V_11 ) ;
F_22 ( V_48 ) ;
F_5 ( V_11 ) ;
}
F_23 ( & V_7 -> V_50 -> V_51 ) ;
F_8 (uobj, tmp, &context->xrcd_list, list) {
struct V_52 * V_53 = V_11 -> V_32 ;
struct V_54 * V_55 =
F_2 ( V_11 , struct V_54 , V_36 ) ;
F_16 ( & V_56 , V_11 ) ;
F_24 ( V_7 -> V_50 , V_53 ) ;
F_5 ( V_55 ) ;
}
F_25 ( & V_7 -> V_50 -> V_51 ) ;
F_8 (uobj, tmp, &context->pd_list, list) {
struct V_57 * V_58 = V_11 -> V_32 ;
F_16 ( & V_59 , V_11 ) ;
F_26 ( V_58 ) ;
F_5 ( V_11 ) ;
}
return V_27 -> V_50 -> V_60 ( V_27 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_8 * V_7 =
F_2 ( V_2 , struct V_8 , V_2 ) ;
F_28 ( V_7 -> V_50 -> V_61 -> V_62 ) ;
F_11 ( & V_7 -> V_50 -> V_2 , F_1 ) ;
F_5 ( V_7 ) ;
}
static T_1 F_29 ( struct V_7 * V_63 , char T_2 * V_64 ,
T_3 V_65 , T_4 * V_66 )
{
struct V_6 * V_7 = V_63 -> V_67 ;
struct V_12 * V_68 ;
int V_69 ;
int V_70 = 0 ;
F_7 ( & V_7 -> V_15 ) ;
while ( F_30 ( & V_7 -> V_71 ) ) {
F_10 ( & V_7 -> V_15 ) ;
if ( V_63 -> V_72 & V_73 )
return - V_74 ;
if ( F_31 ( V_7 -> V_75 ,
! F_30 ( & V_7 -> V_71 ) ) )
return - V_76 ;
F_7 ( & V_7 -> V_15 ) ;
}
V_68 = F_32 ( V_7 -> V_71 . V_77 , struct V_12 , V_16 ) ;
if ( V_7 -> V_78 )
V_69 = sizeof ( struct V_79 ) ;
else
V_69 = sizeof ( struct V_80 ) ;
if ( V_69 > V_65 ) {
V_70 = - V_81 ;
V_68 = NULL ;
} else {
F_9 ( V_7 -> V_71 . V_77 ) ;
if ( V_68 -> V_82 ) {
++ ( * V_68 -> V_82 ) ;
F_9 ( & V_68 -> V_83 ) ;
}
}
F_10 ( & V_7 -> V_15 ) ;
if ( V_68 ) {
if ( F_33 ( V_64 , V_68 , V_69 ) )
V_70 = - V_84 ;
else
V_70 = V_69 ;
}
F_5 ( V_68 ) ;
return V_70 ;
}
static unsigned int F_34 ( struct V_7 * V_63 ,
struct V_85 * V_86 )
{
unsigned int V_87 = 0 ;
struct V_6 * V_7 = V_63 -> V_67 ;
V_75 ( V_63 , & V_7 -> V_75 , V_86 ) ;
F_7 ( & V_7 -> V_15 ) ;
if ( ! F_30 ( & V_7 -> V_71 ) )
V_87 = V_88 | V_89 ;
F_10 ( & V_7 -> V_15 ) ;
return V_87 ;
}
static int F_35 ( int V_90 , struct V_7 * V_63 , int V_91 )
{
struct V_6 * V_7 = V_63 -> V_67 ;
return F_36 ( V_90 , V_63 , V_91 , & V_7 -> V_92 ) ;
}
static int F_37 ( struct V_93 * V_93 , struct V_7 * V_63 )
{
struct V_6 * V_7 = V_63 -> V_67 ;
struct V_12 * V_94 , * V_14 ;
F_7 ( & V_7 -> V_15 ) ;
V_7 -> V_95 = 1 ;
F_8 (entry, tmp, &file->event_list, list) {
if ( V_94 -> V_82 )
F_9 ( & V_94 -> V_83 ) ;
F_5 ( V_94 ) ;
}
F_10 ( & V_7 -> V_15 ) ;
if ( V_7 -> V_78 ) {
F_38 ( & V_7 -> V_96 -> V_97 ) ;
F_11 ( & V_7 -> V_96 -> V_2 , F_27 ) ;
}
F_11 ( & V_7 -> V_2 , F_4 ) ;
return 0 ;
}
void F_39 ( struct V_39 * V_40 , void * V_41 )
{
struct V_6 * V_7 = V_41 ;
struct V_10 * V_11 ;
struct V_12 * V_94 ;
unsigned long V_98 ;
if ( ! V_7 )
return;
F_40 ( & V_7 -> V_15 , V_98 ) ;
if ( V_7 -> V_95 ) {
F_41 ( & V_7 -> V_15 , V_98 ) ;
return;
}
V_94 = F_42 ( sizeof *V_94 , V_99 ) ;
if ( ! V_94 ) {
F_41 ( & V_7 -> V_15 , V_98 ) ;
return;
}
V_11 = F_2 ( V_40 -> V_36 , struct V_10 , V_36 ) ;
V_94 -> V_100 . V_5 . V_101 = V_40 -> V_36 -> V_102 ;
V_94 -> V_82 = & V_11 -> V_103 ;
F_43 ( & V_94 -> V_16 , & V_7 -> V_71 ) ;
F_43 ( & V_94 -> V_83 , & V_11 -> V_104 ) ;
F_41 ( & V_7 -> V_15 , V_98 ) ;
F_44 ( & V_7 -> V_75 ) ;
F_45 ( & V_7 -> V_92 , V_105 , V_106 ) ;
}
static void F_46 ( struct V_8 * V_7 ,
T_5 V_107 , T_5 V_68 ,
struct V_108 * V_83 ,
T_6 * V_82 )
{
struct V_12 * V_94 ;
unsigned long V_98 ;
F_40 ( & V_7 -> V_17 -> V_15 , V_98 ) ;
if ( V_7 -> V_17 -> V_95 ) {
F_41 ( & V_7 -> V_17 -> V_15 , V_98 ) ;
return;
}
V_94 = F_42 ( sizeof *V_94 , V_99 ) ;
if ( ! V_94 ) {
F_41 ( & V_7 -> V_17 -> V_15 , V_98 ) ;
return;
}
V_94 -> V_100 . V_109 . V_107 = V_107 ;
V_94 -> V_100 . V_109 . V_110 = V_68 ;
V_94 -> V_82 = V_82 ;
F_43 ( & V_94 -> V_16 , & V_7 -> V_17 -> V_71 ) ;
if ( V_83 )
F_43 ( & V_94 -> V_83 , V_83 ) ;
F_41 ( & V_7 -> V_17 -> V_15 , V_98 ) ;
F_44 ( & V_7 -> V_17 -> V_75 ) ;
F_45 ( & V_7 -> V_17 -> V_92 , V_105 , V_106 ) ;
}
void F_47 ( struct V_111 * V_68 , void * V_112 )
{
struct V_10 * V_11 = F_2 ( V_68 -> V_107 . V_40 -> V_36 ,
struct V_10 , V_36 ) ;
F_46 ( V_11 -> V_96 , V_11 -> V_36 . V_102 ,
V_68 -> V_68 , & V_11 -> V_113 ,
& V_11 -> V_114 ) ;
}
void F_48 ( struct V_111 * V_68 , void * V_112 )
{
struct V_18 * V_11 ;
V_11 = F_2 ( V_68 -> V_107 . V_20 -> V_36 ,
struct V_18 , V_36 ) ;
F_46 ( V_112 , V_11 -> V_36 . V_102 ,
V_68 -> V_68 , & V_11 -> V_71 ,
& V_11 -> V_115 ) ;
}
void F_49 ( struct V_111 * V_68 , void * V_112 )
{
struct V_18 * V_11 ;
V_11 = F_2 ( V_68 -> V_107 . V_45 -> V_36 ,
struct V_18 , V_36 ) ;
F_46 ( V_112 , V_11 -> V_36 . V_102 ,
V_68 -> V_68 , & V_11 -> V_71 ,
& V_11 -> V_115 ) ;
}
void F_50 ( struct V_116 * V_117 ,
struct V_111 * V_68 )
{
struct V_8 * V_7 =
F_2 ( V_117 , struct V_8 , V_97 ) ;
F_46 ( V_7 , V_68 -> V_107 . V_118 , V_68 -> V_68 ,
NULL , NULL ) ;
}
struct V_7 * F_51 ( struct V_8 * V_96 ,
int V_78 )
{
struct V_6 * V_9 ;
struct V_7 * V_63 ;
V_9 = F_42 ( sizeof *V_9 , V_119 ) ;
if ( ! V_9 )
return F_52 ( - V_120 ) ;
F_53 ( & V_9 -> V_2 ) ;
F_54 ( & V_9 -> V_15 ) ;
F_55 ( & V_9 -> V_71 ) ;
F_56 ( & V_9 -> V_75 ) ;
V_9 -> V_96 = V_96 ;
V_9 -> V_92 = NULL ;
V_9 -> V_78 = V_78 ;
V_9 -> V_95 = 0 ;
V_63 = F_57 ( L_1 , & V_121 ,
V_9 , V_122 ) ;
if ( F_58 ( V_63 ) )
F_5 ( V_9 ) ;
return V_63 ;
}
struct V_6 * F_59 ( int V_90 )
{
struct V_6 * V_9 = NULL ;
struct V_90 V_123 = F_60 ( V_90 ) ;
if ( ! V_123 . V_7 )
return NULL ;
if ( V_123 . V_7 -> V_124 != & V_121 )
goto V_125;
V_9 = V_123 . V_7 -> V_67 ;
if ( V_9 -> V_78 ) {
V_9 = NULL ;
goto V_125;
}
F_61 ( & V_9 -> V_2 ) ;
V_125:
F_62 ( V_123 ) ;
return V_9 ;
}
static T_1 F_63 ( struct V_7 * V_63 , const char T_2 * V_64 ,
T_3 V_65 , T_4 * V_66 )
{
struct V_8 * V_7 = V_63 -> V_67 ;
struct V_126 V_127 ;
if ( V_65 < sizeof V_127 )
return - V_81 ;
if ( F_64 ( & V_127 , V_64 , sizeof V_127 ) )
return - V_84 ;
if ( V_127 . V_128 * 4 != V_65 )
return - V_81 ;
if ( V_127 . V_129 >= F_65 ( V_130 ) ||
! V_130 [ V_127 . V_129 ] )
return - V_81 ;
if ( ! V_7 -> V_131 &&
V_127 . V_129 != V_132 )
return - V_81 ;
if ( ! ( V_7 -> V_50 -> V_61 -> V_133 & ( 1ull << V_127 . V_129 ) ) )
return - V_134 ;
return V_130 [ V_127 . V_129 ] ( V_7 , V_64 + sizeof V_127 ,
V_127 . V_128 * 4 , V_127 . V_135 * 4 ) ;
}
static int F_66 ( struct V_7 * V_63 , struct V_136 * V_137 )
{
struct V_8 * V_7 = V_63 -> V_67 ;
if ( ! V_7 -> V_131 )
return - V_138 ;
else
return V_7 -> V_50 -> V_61 -> V_139 ( V_7 -> V_131 , V_137 ) ;
}
static int F_67 ( struct V_93 * V_93 , struct V_7 * V_63 )
{
struct V_3 * V_4 ;
struct V_8 * V_7 ;
int V_70 ;
V_4 = F_2 ( V_93 -> V_140 , struct V_3 , V_141 ) ;
if ( V_4 )
F_61 ( & V_4 -> V_2 ) ;
else
return - V_142 ;
if ( ! F_68 ( V_4 -> V_61 -> V_62 ) ) {
V_70 = - V_138 ;
goto V_143;
}
V_7 = F_42 ( sizeof *V_7 , V_119 ) ;
if ( ! V_7 ) {
V_70 = - V_120 ;
goto V_144;
}
V_7 -> V_50 = V_4 ;
V_7 -> V_131 = NULL ;
V_7 -> V_17 = NULL ;
F_53 ( & V_7 -> V_2 ) ;
F_69 ( & V_7 -> V_145 ) ;
V_63 -> V_67 = V_7 ;
return F_70 ( V_93 , V_63 ) ;
V_144:
F_28 ( V_4 -> V_61 -> V_62 ) ;
V_143:
F_11 ( & V_4 -> V_2 , F_1 ) ;
return V_70 ;
}
static int F_71 ( struct V_93 * V_93 , struct V_7 * V_63 )
{
struct V_8 * V_7 = V_63 -> V_67 ;
F_15 ( V_7 , V_7 -> V_131 ) ;
if ( V_7 -> V_17 )
F_11 ( & V_7 -> V_17 -> V_2 , F_4 ) ;
F_11 ( & V_7 -> V_2 , F_27 ) ;
return 0 ;
}
static T_1 F_72 ( struct V_50 * V_50 , struct V_146 * V_147 ,
char * V_64 )
{
struct V_3 * V_4 = F_73 ( V_50 ) ;
if ( ! V_4 )
return - V_138 ;
return sprintf ( V_64 , L_2 , V_4 -> V_61 -> V_148 ) ;
}
static T_1 F_74 ( struct V_50 * V_50 ,
struct V_146 * V_147 , char * V_64 )
{
struct V_3 * V_4 = F_73 ( V_50 ) ;
if ( ! V_4 )
return - V_138 ;
return sprintf ( V_64 , L_3 , V_4 -> V_61 -> V_149 ) ;
}
static int F_75 ( void )
{
int V_70 ;
if ( ! V_150 ) {
V_70 = F_76 ( & V_150 , 0 , V_151 ,
L_4 ) ;
if ( V_70 ) {
F_77 ( V_152 L_5 ) ;
return V_70 ;
}
}
V_70 = F_78 ( V_153 , V_151 ) ;
if ( V_70 >= V_151 )
return - 1 ;
return V_70 ;
}
static void F_79 ( struct V_154 * V_50 )
{
int V_155 ;
T_7 V_156 ;
struct V_3 * V_157 ;
if ( ! V_50 -> V_158 )
return;
V_157 = F_80 ( sizeof *V_157 , V_119 ) ;
if ( ! V_157 )
return;
F_53 ( & V_157 -> V_2 ) ;
F_81 ( & V_157 -> V_5 ) ;
V_157 -> V_159 = V_160 ;
F_69 ( & V_157 -> V_51 ) ;
F_82 ( & V_161 ) ;
V_155 = F_78 ( V_162 , V_151 ) ;
if ( V_155 >= V_151 ) {
F_83 ( & V_161 ) ;
V_155 = F_75 () ;
if ( V_155 < 0 )
goto V_143;
F_82 ( & V_161 ) ;
V_157 -> V_155 = V_155 + V_151 ;
V_156 = V_155 + V_150 ;
F_84 ( V_155 , V_153 ) ;
} else {
V_157 -> V_155 = V_155 ;
V_156 = V_155 + V_163 ;
F_84 ( V_155 , V_162 ) ;
}
F_83 ( & V_161 ) ;
V_157 -> V_61 = V_50 ;
V_157 -> V_164 = V_50 -> V_164 ;
F_85 ( & V_157 -> V_141 , NULL ) ;
V_157 -> V_141 . V_62 = V_165 ;
V_157 -> V_141 . V_166 = V_50 -> V_139 ? & V_167 : & V_168 ;
F_86 ( & V_157 -> V_141 . V_169 , L_6 , V_157 -> V_155 ) ;
if ( F_87 ( & V_157 -> V_141 , V_156 , 1 ) )
goto V_170;
V_157 -> V_4 = F_88 ( V_171 , V_50 -> V_172 ,
V_157 -> V_141 . V_4 , V_157 ,
L_6 , V_157 -> V_155 ) ;
if ( F_58 ( V_157 -> V_4 ) )
goto V_170;
if ( F_89 ( V_157 -> V_4 , & V_173 ) )
goto V_174;
if ( F_89 ( V_157 -> V_4 , & V_175 ) )
goto V_174;
F_90 ( V_50 , & V_176 , V_157 ) ;
return;
V_174:
F_91 ( V_171 , V_157 -> V_141 . V_4 ) ;
V_170:
F_92 ( & V_157 -> V_141 ) ;
if ( V_157 -> V_155 < V_151 )
F_93 ( V_155 , V_162 ) ;
else
F_93 ( V_155 , V_153 ) ;
V_143:
F_11 ( & V_157 -> V_2 , F_1 ) ;
F_94 ( & V_157 -> V_5 ) ;
F_5 ( V_157 ) ;
return;
}
static void F_95 ( struct V_154 * V_50 )
{
struct V_3 * V_157 = F_96 ( V_50 , & V_176 ) ;
if ( ! V_157 )
return;
F_97 ( V_157 -> V_4 , NULL ) ;
F_91 ( V_171 , V_157 -> V_141 . V_4 ) ;
F_92 ( & V_157 -> V_141 ) ;
if ( V_157 -> V_155 < V_151 )
F_93 ( V_157 -> V_155 , V_162 ) ;
else
F_93 ( V_157 -> V_155 - V_151 , V_153 ) ;
F_11 ( & V_157 -> V_2 , F_1 ) ;
F_94 ( & V_157 -> V_5 ) ;
F_5 ( V_157 ) ;
}
static char * F_98 ( struct V_50 * V_4 , T_8 * V_177 )
{
if ( V_177 )
* V_177 = 0666 ;
return F_99 ( V_119 , L_7 , F_100 ( V_4 ) ) ;
}
static int T_9 F_101 ( void )
{
int V_70 ;
V_70 = F_102 ( V_163 , V_151 ,
L_4 ) ;
if ( V_70 ) {
F_77 ( V_152 L_8 ) ;
goto V_125;
}
V_171 = F_103 ( V_165 , L_4 ) ;
if ( F_58 ( V_171 ) ) {
V_70 = F_104 ( V_171 ) ;
F_77 ( V_152 L_9 ) ;
goto V_178;
}
V_171 -> V_179 = F_98 ;
V_70 = F_105 ( V_171 , & V_180 . V_147 ) ;
if ( V_70 ) {
F_77 ( V_152 L_10 ) ;
goto V_181;
}
V_70 = F_106 ( & V_176 ) ;
if ( V_70 ) {
F_77 ( V_152 L_11 ) ;
goto V_181;
}
return 0 ;
V_181:
F_107 ( V_171 ) ;
V_178:
F_108 ( V_163 , V_151 ) ;
V_125:
return V_70 ;
}
static void T_10 F_109 ( void )
{
F_110 ( & V_176 ) ;
F_107 ( V_171 ) ;
F_108 ( V_163 , V_151 ) ;
if ( V_150 )
F_108 ( V_150 , V_151 ) ;
F_111 ( & V_59 ) ;
F_111 ( & V_49 ) ;
F_111 ( & V_182 ) ;
F_111 ( & V_33 ) ;
F_111 ( & V_43 ) ;
F_111 ( & V_37 ) ;
F_111 ( & V_46 ) ;
}
