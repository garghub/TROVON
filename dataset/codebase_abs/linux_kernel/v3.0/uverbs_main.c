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
F_13 ( V_20 , V_34 ) ;
F_18 ( V_20 ) ;
F_12 ( V_7 , & V_34 -> V_35 ) ;
F_5 ( V_34 ) ;
}
F_8 (uobj, tmp, &context->cq_list, list) {
struct V_38 * V_39 = V_11 -> V_32 ;
struct V_6 * V_9 = V_39 -> V_40 ;
struct V_10 * V_41 =
F_2 ( V_11 , struct V_10 , V_36 ) ;
F_16 ( & V_42 , V_11 ) ;
F_19 ( V_39 ) ;
F_6 ( V_7 , V_9 , V_41 ) ;
F_5 ( V_41 ) ;
}
F_8 (uobj, tmp, &context->srq_list, list) {
struct V_43 * V_44 = V_11 -> V_32 ;
struct V_18 * V_35 =
F_2 ( V_11 , struct V_18 , V_36 ) ;
F_16 ( & V_45 , V_11 ) ;
F_20 ( V_44 ) ;
F_12 ( V_7 , V_35 ) ;
F_5 ( V_35 ) ;
}
F_8 (uobj, tmp, &context->mr_list, list) {
struct V_46 * V_47 = V_11 -> V_32 ;
F_16 ( & V_48 , V_11 ) ;
F_21 ( V_47 ) ;
F_5 ( V_11 ) ;
}
F_8 (uobj, tmp, &context->pd_list, list) {
struct V_49 * V_50 = V_11 -> V_32 ;
F_16 ( & V_51 , V_11 ) ;
F_22 ( V_50 ) ;
F_5 ( V_11 ) ;
}
return V_27 -> V_52 -> V_53 ( V_27 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_8 * V_7 =
F_2 ( V_2 , struct V_8 , V_2 ) ;
F_24 ( V_7 -> V_52 -> V_54 -> V_55 ) ;
F_11 ( & V_7 -> V_52 -> V_2 , F_1 ) ;
F_5 ( V_7 ) ;
}
static T_1 F_25 ( struct V_7 * V_56 , char T_2 * V_57 ,
T_3 V_58 , T_4 * V_59 )
{
struct V_6 * V_7 = V_56 -> V_60 ;
struct V_12 * V_61 ;
int V_62 ;
int V_63 = 0 ;
F_7 ( & V_7 -> V_15 ) ;
while ( F_26 ( & V_7 -> V_64 ) ) {
F_10 ( & V_7 -> V_15 ) ;
if ( V_56 -> V_65 & V_66 )
return - V_67 ;
if ( F_27 ( V_7 -> V_68 ,
! F_26 ( & V_7 -> V_64 ) ) )
return - V_69 ;
F_7 ( & V_7 -> V_15 ) ;
}
V_61 = F_28 ( V_7 -> V_64 . V_70 , struct V_12 , V_16 ) ;
if ( V_7 -> V_71 )
V_62 = sizeof ( struct V_72 ) ;
else
V_62 = sizeof ( struct V_73 ) ;
if ( V_62 > V_58 ) {
V_63 = - V_74 ;
V_61 = NULL ;
} else {
F_9 ( V_7 -> V_64 . V_70 ) ;
if ( V_61 -> V_75 ) {
++ ( * V_61 -> V_75 ) ;
F_9 ( & V_61 -> V_76 ) ;
}
}
F_10 ( & V_7 -> V_15 ) ;
if ( V_61 ) {
if ( F_29 ( V_57 , V_61 , V_62 ) )
V_63 = - V_77 ;
else
V_63 = V_62 ;
}
F_5 ( V_61 ) ;
return V_63 ;
}
static unsigned int F_30 ( struct V_7 * V_56 ,
struct V_78 * V_79 )
{
unsigned int V_80 = 0 ;
struct V_6 * V_7 = V_56 -> V_60 ;
V_68 ( V_56 , & V_7 -> V_68 , V_79 ) ;
F_7 ( & V_7 -> V_15 ) ;
if ( ! F_26 ( & V_7 -> V_64 ) )
V_80 = V_81 | V_82 ;
F_10 ( & V_7 -> V_15 ) ;
return V_80 ;
}
static int F_31 ( int V_83 , struct V_7 * V_56 , int V_84 )
{
struct V_6 * V_7 = V_56 -> V_60 ;
return F_32 ( V_83 , V_56 , V_84 , & V_7 -> V_85 ) ;
}
static int F_33 ( struct V_86 * V_86 , struct V_7 * V_56 )
{
struct V_6 * V_7 = V_56 -> V_60 ;
struct V_12 * V_87 , * V_14 ;
F_7 ( & V_7 -> V_15 ) ;
V_7 -> V_88 = 1 ;
F_8 (entry, tmp, &file->event_list, list) {
if ( V_87 -> V_75 )
F_9 ( & V_87 -> V_76 ) ;
F_5 ( V_87 ) ;
}
F_10 ( & V_7 -> V_15 ) ;
if ( V_7 -> V_71 ) {
F_34 ( & V_7 -> V_89 -> V_90 ) ;
F_11 ( & V_7 -> V_89 -> V_2 , F_23 ) ;
}
F_11 ( & V_7 -> V_2 , F_4 ) ;
return 0 ;
}
void F_35 ( struct V_38 * V_39 , void * V_40 )
{
struct V_6 * V_7 = V_40 ;
struct V_10 * V_11 ;
struct V_12 * V_87 ;
unsigned long V_91 ;
if ( ! V_7 )
return;
F_36 ( & V_7 -> V_15 , V_91 ) ;
if ( V_7 -> V_88 ) {
F_37 ( & V_7 -> V_15 , V_91 ) ;
return;
}
V_87 = F_38 ( sizeof *V_87 , V_92 ) ;
if ( ! V_87 ) {
F_37 ( & V_7 -> V_15 , V_91 ) ;
return;
}
V_11 = F_2 ( V_39 -> V_36 , struct V_10 , V_36 ) ;
V_87 -> V_93 . V_5 . V_94 = V_39 -> V_36 -> V_95 ;
V_87 -> V_75 = & V_11 -> V_96 ;
F_39 ( & V_87 -> V_16 , & V_7 -> V_64 ) ;
F_39 ( & V_87 -> V_76 , & V_11 -> V_97 ) ;
F_37 ( & V_7 -> V_15 , V_91 ) ;
F_40 ( & V_7 -> V_68 ) ;
F_41 ( & V_7 -> V_85 , V_98 , V_99 ) ;
}
static void F_42 ( struct V_8 * V_7 ,
T_5 V_100 , T_5 V_61 ,
struct V_101 * V_76 ,
T_6 * V_75 )
{
struct V_12 * V_87 ;
unsigned long V_91 ;
F_36 ( & V_7 -> V_17 -> V_15 , V_91 ) ;
if ( V_7 -> V_17 -> V_88 ) {
F_37 ( & V_7 -> V_17 -> V_15 , V_91 ) ;
return;
}
V_87 = F_38 ( sizeof *V_87 , V_92 ) ;
if ( ! V_87 ) {
F_37 ( & V_7 -> V_17 -> V_15 , V_91 ) ;
return;
}
V_87 -> V_93 . V_102 . V_100 = V_100 ;
V_87 -> V_93 . V_102 . V_103 = V_61 ;
V_87 -> V_75 = V_75 ;
F_39 ( & V_87 -> V_16 , & V_7 -> V_17 -> V_64 ) ;
if ( V_76 )
F_39 ( & V_87 -> V_76 , V_76 ) ;
F_37 ( & V_7 -> V_17 -> V_15 , V_91 ) ;
F_40 ( & V_7 -> V_17 -> V_68 ) ;
F_41 ( & V_7 -> V_17 -> V_85 , V_98 , V_99 ) ;
}
void F_43 ( struct V_104 * V_61 , void * V_105 )
{
struct V_10 * V_11 = F_2 ( V_61 -> V_100 . V_39 -> V_36 ,
struct V_10 , V_36 ) ;
F_42 ( V_11 -> V_89 , V_11 -> V_36 . V_95 ,
V_61 -> V_61 , & V_11 -> V_106 ,
& V_11 -> V_107 ) ;
}
void F_44 ( struct V_104 * V_61 , void * V_105 )
{
struct V_18 * V_11 ;
V_11 = F_2 ( V_61 -> V_100 . V_20 -> V_36 ,
struct V_18 , V_36 ) ;
F_42 ( V_105 , V_11 -> V_36 . V_95 ,
V_61 -> V_61 , & V_11 -> V_64 ,
& V_11 -> V_108 ) ;
}
void F_45 ( struct V_104 * V_61 , void * V_105 )
{
struct V_18 * V_11 ;
V_11 = F_2 ( V_61 -> V_100 . V_44 -> V_36 ,
struct V_18 , V_36 ) ;
F_42 ( V_105 , V_11 -> V_36 . V_95 ,
V_61 -> V_61 , & V_11 -> V_64 ,
& V_11 -> V_108 ) ;
}
void F_46 ( struct V_109 * V_110 ,
struct V_104 * V_61 )
{
struct V_8 * V_7 =
F_2 ( V_110 , struct V_8 , V_90 ) ;
F_42 ( V_7 , V_61 -> V_100 . V_111 , V_61 -> V_61 ,
NULL , NULL ) ;
}
struct V_7 * F_47 ( struct V_8 * V_89 ,
int V_71 )
{
struct V_6 * V_9 ;
struct V_7 * V_56 ;
V_9 = F_38 ( sizeof *V_9 , V_112 ) ;
if ( ! V_9 )
return F_48 ( - V_113 ) ;
F_49 ( & V_9 -> V_2 ) ;
F_50 ( & V_9 -> V_15 ) ;
F_51 ( & V_9 -> V_64 ) ;
F_52 ( & V_9 -> V_68 ) ;
V_9 -> V_89 = V_89 ;
V_9 -> V_85 = NULL ;
V_9 -> V_71 = V_71 ;
V_9 -> V_88 = 0 ;
V_56 = F_53 ( L_1 , & V_114 ,
V_9 , V_115 ) ;
if ( F_54 ( V_56 ) )
F_5 ( V_9 ) ;
return V_56 ;
}
struct V_6 * F_55 ( int V_83 )
{
struct V_6 * V_9 = NULL ;
struct V_7 * V_56 ;
V_56 = F_56 ( V_83 ) ;
if ( ! V_56 )
return NULL ;
if ( V_56 -> V_116 != & V_114 )
goto V_117;
V_9 = V_56 -> V_60 ;
if ( V_9 -> V_71 ) {
V_9 = NULL ;
goto V_117;
}
F_57 ( & V_9 -> V_2 ) ;
V_117:
F_58 ( V_56 ) ;
return V_9 ;
}
static T_1 F_59 ( struct V_7 * V_56 , const char T_2 * V_57 ,
T_3 V_58 , T_4 * V_59 )
{
struct V_8 * V_7 = V_56 -> V_60 ;
struct V_118 V_119 ;
if ( V_58 < sizeof V_119 )
return - V_74 ;
if ( F_60 ( & V_119 , V_57 , sizeof V_119 ) )
return - V_77 ;
if ( V_119 . V_120 * 4 != V_58 )
return - V_74 ;
if ( V_119 . V_121 < 0 ||
V_119 . V_121 >= F_61 ( V_122 ) ||
! V_122 [ V_119 . V_121 ] )
return - V_74 ;
if ( ! V_7 -> V_123 &&
V_119 . V_121 != V_124 )
return - V_74 ;
if ( ! ( V_7 -> V_52 -> V_54 -> V_125 & ( 1ull << V_119 . V_121 ) ) )
return - V_126 ;
return V_122 [ V_119 . V_121 ] ( V_7 , V_57 + sizeof V_119 ,
V_119 . V_120 * 4 , V_119 . V_127 * 4 ) ;
}
static int F_62 ( struct V_7 * V_56 , struct V_128 * V_129 )
{
struct V_8 * V_7 = V_56 -> V_60 ;
if ( ! V_7 -> V_123 )
return - V_130 ;
else
return V_7 -> V_52 -> V_54 -> V_131 ( V_7 -> V_123 , V_129 ) ;
}
static int F_63 ( struct V_86 * V_86 , struct V_7 * V_56 )
{
struct V_3 * V_4 ;
struct V_8 * V_7 ;
int V_63 ;
V_4 = F_2 ( V_86 -> V_132 , struct V_3 , V_133 ) ;
if ( V_4 )
F_57 ( & V_4 -> V_2 ) ;
else
return - V_134 ;
if ( ! F_64 ( V_4 -> V_54 -> V_55 ) ) {
V_63 = - V_130 ;
goto V_135;
}
V_7 = F_38 ( sizeof *V_7 , V_112 ) ;
if ( ! V_7 ) {
V_63 = - V_113 ;
goto V_136;
}
V_7 -> V_52 = V_4 ;
V_7 -> V_123 = NULL ;
V_7 -> V_17 = NULL ;
F_49 ( & V_7 -> V_2 ) ;
F_65 ( & V_7 -> V_137 ) ;
V_56 -> V_60 = V_7 ;
return F_66 ( V_86 , V_56 ) ;
V_136:
F_24 ( V_4 -> V_54 -> V_55 ) ;
V_135:
F_11 ( & V_4 -> V_2 , F_1 ) ;
return V_63 ;
}
static int F_67 ( struct V_86 * V_86 , struct V_7 * V_56 )
{
struct V_8 * V_7 = V_56 -> V_60 ;
F_15 ( V_7 , V_7 -> V_123 ) ;
if ( V_7 -> V_17 )
F_11 ( & V_7 -> V_17 -> V_2 , F_4 ) ;
F_11 ( & V_7 -> V_2 , F_23 ) ;
return 0 ;
}
static T_1 F_68 ( struct V_52 * V_52 , struct V_138 * V_139 ,
char * V_57 )
{
struct V_3 * V_4 = F_69 ( V_52 ) ;
if ( ! V_4 )
return - V_130 ;
return sprintf ( V_57 , L_2 , V_4 -> V_54 -> V_140 ) ;
}
static T_1 F_70 ( struct V_52 * V_52 ,
struct V_138 * V_139 , char * V_57 )
{
struct V_3 * V_4 = F_69 ( V_52 ) ;
if ( ! V_4 )
return - V_130 ;
return sprintf ( V_57 , L_3 , V_4 -> V_54 -> V_141 ) ;
}
static int F_71 ( void )
{
int V_63 ;
if ( ! V_142 ) {
V_63 = F_72 ( & V_142 , 0 , V_143 ,
L_4 ) ;
if ( V_63 ) {
F_73 ( V_144 L_5 ) ;
return V_63 ;
}
}
V_63 = F_74 ( V_145 , V_143 ) ;
if ( V_63 >= V_143 )
return - 1 ;
return V_63 ;
}
static void F_75 ( struct V_146 * V_52 )
{
int V_147 ;
T_7 V_148 ;
struct V_3 * V_149 ;
if ( ! V_52 -> V_150 )
return;
V_149 = F_76 ( sizeof *V_149 , V_112 ) ;
if ( ! V_149 )
return;
F_49 ( & V_149 -> V_2 ) ;
F_77 ( & V_149 -> V_5 ) ;
F_78 ( & V_151 ) ;
V_147 = F_74 ( V_152 , V_143 ) ;
if ( V_147 >= V_143 ) {
F_79 ( & V_151 ) ;
V_147 = F_71 () ;
if ( V_147 < 0 )
goto V_135;
F_78 ( & V_151 ) ;
V_149 -> V_147 = V_147 + V_143 ;
V_148 = V_147 + V_142 ;
F_80 ( V_147 , V_145 ) ;
} else {
V_149 -> V_147 = V_147 ;
V_148 = V_147 + V_153 ;
F_80 ( V_147 , V_152 ) ;
}
F_79 ( & V_151 ) ;
V_149 -> V_54 = V_52 ;
V_149 -> V_154 = V_52 -> V_154 ;
F_81 ( & V_149 -> V_133 , NULL ) ;
V_149 -> V_133 . V_55 = V_155 ;
V_149 -> V_133 . V_156 = V_52 -> V_131 ? & V_157 : & V_158 ;
F_82 ( & V_149 -> V_133 . V_159 , L_6 , V_149 -> V_147 ) ;
if ( F_83 ( & V_149 -> V_133 , V_148 , 1 ) )
goto V_160;
V_149 -> V_4 = F_84 ( V_161 , V_52 -> V_162 ,
V_149 -> V_133 . V_4 , V_149 ,
L_6 , V_149 -> V_147 ) ;
if ( F_54 ( V_149 -> V_4 ) )
goto V_160;
if ( F_85 ( V_149 -> V_4 , & V_163 ) )
goto V_164;
if ( F_85 ( V_149 -> V_4 , & V_165 ) )
goto V_164;
F_86 ( V_52 , & V_166 , V_149 ) ;
return;
V_164:
F_87 ( V_161 , V_149 -> V_133 . V_4 ) ;
V_160:
F_88 ( & V_149 -> V_133 ) ;
if ( V_149 -> V_147 < V_143 )
F_89 ( V_147 , V_152 ) ;
else
F_89 ( V_147 , V_145 ) ;
V_135:
F_11 ( & V_149 -> V_2 , F_1 ) ;
F_90 ( & V_149 -> V_5 ) ;
F_5 ( V_149 ) ;
return;
}
static void F_91 ( struct V_146 * V_52 )
{
struct V_3 * V_149 = F_92 ( V_52 , & V_166 ) ;
if ( ! V_149 )
return;
F_93 ( V_149 -> V_4 , NULL ) ;
F_87 ( V_161 , V_149 -> V_133 . V_4 ) ;
F_88 ( & V_149 -> V_133 ) ;
if ( V_149 -> V_147 < V_143 )
F_89 ( V_149 -> V_147 , V_152 ) ;
else
F_89 ( V_149 -> V_147 - V_143 , V_145 ) ;
F_11 ( & V_149 -> V_2 , F_1 ) ;
F_90 ( & V_149 -> V_5 ) ;
F_5 ( V_149 ) ;
}
static char * F_94 ( struct V_52 * V_4 , T_8 * V_167 )
{
if ( V_167 )
* V_167 = 0666 ;
return F_95 ( V_112 , L_7 , F_96 ( V_4 ) ) ;
}
static int T_9 F_97 ( void )
{
int V_63 ;
V_63 = F_98 ( V_153 , V_143 ,
L_4 ) ;
if ( V_63 ) {
F_73 ( V_144 L_8 ) ;
goto V_117;
}
V_161 = F_99 ( V_155 , L_4 ) ;
if ( F_54 ( V_161 ) ) {
V_63 = F_100 ( V_161 ) ;
F_73 ( V_144 L_9 ) ;
goto V_168;
}
V_161 -> V_169 = F_94 ;
V_63 = F_101 ( V_161 , & V_170 . V_139 ) ;
if ( V_63 ) {
F_73 ( V_144 L_10 ) ;
goto V_171;
}
V_63 = F_102 ( & V_166 ) ;
if ( V_63 ) {
F_73 ( V_144 L_11 ) ;
goto V_171;
}
return 0 ;
V_171:
F_103 ( V_161 ) ;
V_168:
F_104 ( V_153 , V_143 ) ;
V_117:
return V_63 ;
}
static void T_10 F_105 ( void )
{
F_106 ( & V_166 ) ;
F_103 ( V_161 ) ;
F_104 ( V_153 , V_143 ) ;
if ( V_142 )
F_104 ( V_142 , V_143 ) ;
F_107 ( & V_51 ) ;
F_107 ( & V_48 ) ;
F_107 ( & V_172 ) ;
F_107 ( & V_33 ) ;
F_107 ( & V_42 ) ;
F_107 ( & V_37 ) ;
F_107 ( & V_45 ) ;
}
