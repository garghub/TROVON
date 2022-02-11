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
F_8 (uobj, tmp, &context->srq_list, list) {
struct V_45 * V_46 = V_11 -> V_32 ;
struct V_18 * V_41 =
F_2 ( V_11 , struct V_18 , V_42 ) ;
F_16 ( & V_47 , V_11 ) ;
F_22 ( V_46 ) ;
F_12 ( V_7 , V_41 ) ;
F_5 ( V_41 ) ;
}
F_8 (uobj, tmp, &context->cq_list, list) {
struct V_48 * V_49 = V_11 -> V_32 ;
struct V_6 * V_9 = V_49 -> V_50 ;
struct V_10 * V_51 =
F_2 ( V_11 , struct V_10 , V_42 ) ;
F_16 ( & V_52 , V_11 ) ;
F_23 ( V_49 ) ;
F_6 ( V_7 , V_9 , V_51 ) ;
F_5 ( V_51 ) ;
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
F_29 ( V_27 -> V_66 ) ;
return V_27 -> V_56 -> V_67 ( V_27 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_8 * V_7 =
F_2 ( V_2 , struct V_8 , V_2 ) ;
F_31 ( V_7 -> V_56 -> V_68 -> V_69 ) ;
F_11 ( & V_7 -> V_56 -> V_2 , F_1 ) ;
F_5 ( V_7 ) ;
}
static T_1 F_32 ( struct V_7 * V_70 , char T_2 * V_71 ,
T_3 V_72 , T_4 * V_73 )
{
struct V_6 * V_7 = V_70 -> V_74 ;
struct V_12 * V_75 ;
int V_76 ;
int V_77 = 0 ;
F_7 ( & V_7 -> V_15 ) ;
while ( F_33 ( & V_7 -> V_78 ) ) {
F_10 ( & V_7 -> V_15 ) ;
if ( V_70 -> V_79 & V_80 )
return - V_81 ;
if ( F_34 ( V_7 -> V_82 ,
! F_33 ( & V_7 -> V_78 ) ) )
return - V_83 ;
F_7 ( & V_7 -> V_15 ) ;
}
V_75 = F_35 ( V_7 -> V_78 . V_84 , struct V_12 , V_16 ) ;
if ( V_7 -> V_85 )
V_76 = sizeof ( struct V_86 ) ;
else
V_76 = sizeof ( struct V_87 ) ;
if ( V_76 > V_72 ) {
V_77 = - V_88 ;
V_75 = NULL ;
} else {
F_9 ( V_7 -> V_78 . V_84 ) ;
if ( V_75 -> V_89 ) {
++ ( * V_75 -> V_89 ) ;
F_9 ( & V_75 -> V_90 ) ;
}
}
F_10 ( & V_7 -> V_15 ) ;
if ( V_75 ) {
if ( F_36 ( V_71 , V_75 , V_76 ) )
V_77 = - V_91 ;
else
V_77 = V_76 ;
}
F_5 ( V_75 ) ;
return V_77 ;
}
static unsigned int F_37 ( struct V_7 * V_70 ,
struct V_92 * V_93 )
{
unsigned int V_94 = 0 ;
struct V_6 * V_7 = V_70 -> V_74 ;
V_82 ( V_70 , & V_7 -> V_82 , V_93 ) ;
F_7 ( & V_7 -> V_15 ) ;
if ( ! F_33 ( & V_7 -> V_78 ) )
V_94 = V_95 | V_96 ;
F_10 ( & V_7 -> V_15 ) ;
return V_94 ;
}
static int F_38 ( int V_97 , struct V_7 * V_70 , int V_98 )
{
struct V_6 * V_7 = V_70 -> V_74 ;
return F_39 ( V_97 , V_70 , V_98 , & V_7 -> V_99 ) ;
}
static int F_40 ( struct V_100 * V_100 , struct V_7 * V_70 )
{
struct V_6 * V_7 = V_70 -> V_74 ;
struct V_12 * V_101 , * V_14 ;
F_7 ( & V_7 -> V_15 ) ;
V_7 -> V_102 = 1 ;
F_8 (entry, tmp, &file->event_list, list) {
if ( V_101 -> V_89 )
F_9 ( & V_101 -> V_90 ) ;
F_5 ( V_101 ) ;
}
F_10 ( & V_7 -> V_15 ) ;
if ( V_7 -> V_85 ) {
F_41 ( & V_7 -> V_103 -> V_104 ) ;
F_11 ( & V_7 -> V_103 -> V_2 , F_30 ) ;
}
F_11 ( & V_7 -> V_2 , F_4 ) ;
return 0 ;
}
void F_42 ( struct V_48 * V_49 , void * V_50 )
{
struct V_6 * V_7 = V_50 ;
struct V_10 * V_11 ;
struct V_12 * V_101 ;
unsigned long V_105 ;
if ( ! V_7 )
return;
F_43 ( & V_7 -> V_15 , V_105 ) ;
if ( V_7 -> V_102 ) {
F_44 ( & V_7 -> V_15 , V_105 ) ;
return;
}
V_101 = F_45 ( sizeof *V_101 , V_106 ) ;
if ( ! V_101 ) {
F_44 ( & V_7 -> V_15 , V_105 ) ;
return;
}
V_11 = F_2 ( V_49 -> V_42 , struct V_10 , V_42 ) ;
V_101 -> V_107 . V_5 . V_108 = V_49 -> V_42 -> V_109 ;
V_101 -> V_89 = & V_11 -> V_110 ;
F_46 ( & V_101 -> V_16 , & V_7 -> V_78 ) ;
F_46 ( & V_101 -> V_90 , & V_11 -> V_111 ) ;
F_44 ( & V_7 -> V_15 , V_105 ) ;
F_47 ( & V_7 -> V_82 ) ;
F_48 ( & V_7 -> V_99 , V_112 , V_113 ) ;
}
static void F_49 ( struct V_8 * V_7 ,
T_5 V_114 , T_5 V_75 ,
struct V_115 * V_90 ,
T_6 * V_89 )
{
struct V_12 * V_101 ;
unsigned long V_105 ;
F_43 ( & V_7 -> V_17 -> V_15 , V_105 ) ;
if ( V_7 -> V_17 -> V_102 ) {
F_44 ( & V_7 -> V_17 -> V_15 , V_105 ) ;
return;
}
V_101 = F_45 ( sizeof *V_101 , V_106 ) ;
if ( ! V_101 ) {
F_44 ( & V_7 -> V_17 -> V_15 , V_105 ) ;
return;
}
V_101 -> V_107 . V_116 . V_114 = V_114 ;
V_101 -> V_107 . V_116 . V_117 = V_75 ;
V_101 -> V_107 . V_116 . V_118 = 0 ;
V_101 -> V_89 = V_89 ;
F_46 ( & V_101 -> V_16 , & V_7 -> V_17 -> V_78 ) ;
if ( V_90 )
F_46 ( & V_101 -> V_90 , V_90 ) ;
F_44 ( & V_7 -> V_17 -> V_15 , V_105 ) ;
F_47 ( & V_7 -> V_17 -> V_82 ) ;
F_48 ( & V_7 -> V_17 -> V_99 , V_112 , V_113 ) ;
}
void F_50 ( struct V_119 * V_75 , void * V_120 )
{
struct V_10 * V_11 = F_2 ( V_75 -> V_114 . V_49 -> V_42 ,
struct V_10 , V_42 ) ;
F_49 ( V_11 -> V_103 , V_11 -> V_42 . V_109 ,
V_75 -> V_75 , & V_11 -> V_121 ,
& V_11 -> V_122 ) ;
}
void F_51 ( struct V_119 * V_75 , void * V_120 )
{
struct V_18 * V_11 ;
if ( ! V_75 -> V_114 . V_20 -> V_42 || ! V_75 -> V_114 . V_20 -> V_42 -> V_123 )
return;
V_11 = F_2 ( V_75 -> V_114 . V_20 -> V_42 ,
struct V_18 , V_42 ) ;
F_49 ( V_120 , V_11 -> V_42 . V_109 ,
V_75 -> V_75 , & V_11 -> V_78 ,
& V_11 -> V_124 ) ;
}
void F_52 ( struct V_119 * V_75 , void * V_120 )
{
struct V_18 * V_11 ;
V_11 = F_2 ( V_75 -> V_114 . V_46 -> V_42 ,
struct V_18 , V_42 ) ;
F_49 ( V_120 , V_11 -> V_42 . V_109 ,
V_75 -> V_75 , & V_11 -> V_78 ,
& V_11 -> V_124 ) ;
}
void F_53 ( struct V_125 * V_126 ,
struct V_119 * V_75 )
{
struct V_8 * V_7 =
F_2 ( V_126 , struct V_8 , V_104 ) ;
F_49 ( V_7 , V_75 -> V_114 . V_127 , V_75 -> V_75 ,
NULL , NULL ) ;
}
struct V_7 * F_54 ( struct V_8 * V_103 ,
int V_85 )
{
struct V_6 * V_9 ;
struct V_7 * V_70 ;
V_9 = F_45 ( sizeof *V_9 , V_128 ) ;
if ( ! V_9 )
return F_55 ( - V_129 ) ;
F_56 ( & V_9 -> V_2 ) ;
F_57 ( & V_9 -> V_15 ) ;
F_58 ( & V_9 -> V_78 ) ;
F_59 ( & V_9 -> V_82 ) ;
V_9 -> V_103 = V_103 ;
V_9 -> V_99 = NULL ;
V_9 -> V_85 = V_85 ;
V_9 -> V_102 = 0 ;
V_70 = F_60 ( L_1 , & V_130 ,
V_9 , V_131 ) ;
if ( F_61 ( V_70 ) )
F_5 ( V_9 ) ;
return V_70 ;
}
struct V_6 * F_62 ( int V_97 )
{
struct V_6 * V_9 = NULL ;
struct V_97 V_132 = F_63 ( V_97 ) ;
if ( ! V_132 . V_7 )
return NULL ;
if ( V_132 . V_7 -> V_133 != & V_130 )
goto V_134;
V_9 = V_132 . V_7 -> V_74 ;
if ( V_9 -> V_85 ) {
V_9 = NULL ;
goto V_134;
}
F_64 ( & V_9 -> V_2 ) ;
V_134:
F_65 ( V_132 ) ;
return V_9 ;
}
static T_1 F_66 ( struct V_7 * V_70 , const char T_2 * V_71 ,
T_3 V_72 , T_4 * V_73 )
{
struct V_8 * V_7 = V_70 -> V_74 ;
struct V_135 V_136 ;
T_7 V_105 ;
if ( V_72 < sizeof V_136 )
return - V_88 ;
if ( F_67 ( & V_136 , V_71 , sizeof V_136 ) )
return - V_91 ;
V_105 = ( V_136 . V_137 &
V_138 ) >> V_139 ;
if ( ! V_105 ) {
T_7 V_137 ;
if ( V_136 . V_137 & ~ ( T_7 ) ( V_138 |
V_140 ) )
return - V_88 ;
V_137 = V_136 . V_137 & V_140 ;
if ( V_137 >= F_68 ( V_141 ) ||
! V_141 [ V_137 ] )
return - V_88 ;
if ( ! V_7 -> V_142 &&
V_137 != V_143 )
return - V_88 ;
if ( ! ( V_7 -> V_56 -> V_68 -> V_144 & ( 1ull << V_137 ) ) )
return - V_145 ;
if ( V_136 . V_146 * 4 != V_72 )
return - V_88 ;
return V_141 [ V_137 ] ( V_7 ,
V_71 + sizeof( V_136 ) ,
V_136 . V_146 * 4 ,
V_136 . V_147 * 4 ) ;
} else if ( V_105 == V_148 ) {
T_7 V_137 ;
struct V_149 V_150 ;
struct V_151 V_152 ;
struct V_151 V_153 ;
int V_154 ;
T_3 V_155 = V_72 ;
if ( V_136 . V_137 & ~ ( T_7 ) ( V_138 |
V_140 ) )
return - V_88 ;
V_137 = V_136 . V_137 & V_140 ;
if ( V_137 >= F_68 ( V_156 ) ||
! V_156 [ V_137 ] )
return - V_145 ;
if ( ! V_7 -> V_142 )
return - V_88 ;
if ( ! ( V_7 -> V_56 -> V_68 -> V_157 & ( 1ull << V_137 ) ) )
return - V_145 ;
if ( V_72 < ( sizeof( V_136 ) + sizeof( V_150 ) ) )
return - V_88 ;
if ( F_67 ( & V_150 , V_71 + sizeof( V_136 ) , sizeof( V_150 ) ) )
return - V_91 ;
V_72 -= sizeof( V_136 ) + sizeof( V_150 ) ;
V_71 += sizeof( V_136 ) + sizeof( V_150 ) ;
if ( ( V_136 . V_146 + V_150 . V_158 ) * 8 != V_72 )
return - V_88 ;
if ( V_150 . V_159 )
return - V_88 ;
if ( V_150 . V_160 ) {
if ( ! V_136 . V_147 && ! V_150 . V_161 )
return - V_88 ;
if ( ! F_69 ( V_162 ,
( void T_2 * ) ( unsigned long ) V_150 . V_160 ,
( V_136 . V_147 + V_150 . V_161 ) * 8 ) )
return - V_91 ;
} else {
if ( V_136 . V_147 || V_150 . V_161 )
return - V_88 ;
}
F_70 ( & V_152 , V_71 , ( unsigned long ) V_150 . V_160 ,
V_136 . V_146 * 8 , V_136 . V_147 * 8 ) ;
F_70 ( & V_153 ,
V_71 + V_152 . V_163 ,
( unsigned long ) V_150 . V_160 + V_152 . V_164 ,
V_150 . V_158 * 8 ,
V_150 . V_161 * 8 ) ;
V_154 = V_156 [ V_137 ] ( V_7 ,
& V_152 ,
& V_153 ) ;
if ( V_154 )
return V_154 ;
return V_155 ;
}
return - V_145 ;
}
static int F_71 ( struct V_7 * V_70 , struct V_165 * V_166 )
{
struct V_8 * V_7 = V_70 -> V_74 ;
if ( ! V_7 -> V_142 )
return - V_167 ;
else
return V_7 -> V_56 -> V_68 -> V_168 ( V_7 -> V_142 , V_166 ) ;
}
static int F_72 ( struct V_100 * V_100 , struct V_7 * V_70 )
{
struct V_3 * V_4 ;
struct V_8 * V_7 ;
int V_77 ;
V_4 = F_2 ( V_100 -> V_169 , struct V_3 , V_170 ) ;
if ( V_4 )
F_64 ( & V_4 -> V_2 ) ;
else
return - V_171 ;
if ( ! F_73 ( V_4 -> V_68 -> V_69 ) ) {
V_77 = - V_167 ;
goto V_154;
}
V_7 = F_45 ( sizeof *V_7 , V_128 ) ;
if ( ! V_7 ) {
V_77 = - V_129 ;
goto V_172;
}
V_7 -> V_56 = V_4 ;
V_7 -> V_142 = NULL ;
V_7 -> V_17 = NULL ;
F_56 ( & V_7 -> V_2 ) ;
F_74 ( & V_7 -> V_173 ) ;
V_70 -> V_74 = V_7 ;
return F_75 ( V_100 , V_70 ) ;
V_172:
F_31 ( V_4 -> V_68 -> V_69 ) ;
V_154:
F_11 ( & V_4 -> V_2 , F_1 ) ;
return V_77 ;
}
static int F_76 ( struct V_100 * V_100 , struct V_7 * V_70 )
{
struct V_8 * V_7 = V_70 -> V_74 ;
F_15 ( V_7 , V_7 -> V_142 ) ;
if ( V_7 -> V_17 )
F_11 ( & V_7 -> V_17 -> V_2 , F_4 ) ;
F_11 ( & V_7 -> V_2 , F_30 ) ;
return 0 ;
}
static T_1 F_77 ( struct V_56 * V_56 , struct V_174 * V_175 ,
char * V_71 )
{
struct V_3 * V_4 = F_78 ( V_56 ) ;
if ( ! V_4 )
return - V_167 ;
return sprintf ( V_71 , L_2 , V_4 -> V_68 -> V_176 ) ;
}
static T_1 F_79 ( struct V_56 * V_56 ,
struct V_174 * V_175 , char * V_71 )
{
struct V_3 * V_4 = F_78 ( V_56 ) ;
if ( ! V_4 )
return - V_167 ;
return sprintf ( V_71 , L_3 , V_4 -> V_68 -> V_177 ) ;
}
static int F_80 ( void )
{
int V_77 ;
if ( ! V_178 ) {
V_77 = F_81 ( & V_178 , 0 , V_179 ,
L_4 ) ;
if ( V_77 ) {
F_82 ( V_180 L_5 ) ;
return V_77 ;
}
}
V_77 = F_83 ( V_181 , V_179 ) ;
if ( V_77 >= V_179 )
return - 1 ;
return V_77 ;
}
static void F_84 ( struct V_182 * V_56 )
{
int V_183 ;
T_8 V_184 ;
struct V_3 * V_185 ;
if ( ! V_56 -> V_186 )
return;
V_185 = F_85 ( sizeof *V_185 , V_128 ) ;
if ( ! V_185 )
return;
F_56 ( & V_185 -> V_2 ) ;
F_86 ( & V_185 -> V_5 ) ;
V_185 -> V_187 = V_188 ;
F_74 ( & V_185 -> V_57 ) ;
F_87 ( & V_189 ) ;
V_183 = F_83 ( V_190 , V_179 ) ;
if ( V_183 >= V_179 ) {
F_88 ( & V_189 ) ;
V_183 = F_80 () ;
if ( V_183 < 0 )
goto V_154;
F_87 ( & V_189 ) ;
V_185 -> V_183 = V_183 + V_179 ;
V_184 = V_183 + V_178 ;
F_89 ( V_183 , V_181 ) ;
} else {
V_185 -> V_183 = V_183 ;
V_184 = V_183 + V_191 ;
F_89 ( V_183 , V_190 ) ;
}
F_88 ( & V_189 ) ;
V_185 -> V_68 = V_56 ;
V_185 -> V_192 = V_56 -> V_192 ;
F_90 ( & V_185 -> V_170 , NULL ) ;
V_185 -> V_170 . V_69 = V_193 ;
V_185 -> V_170 . V_194 = V_56 -> V_168 ? & V_195 : & V_196 ;
F_91 ( & V_185 -> V_170 . V_197 , L_6 , V_185 -> V_183 ) ;
if ( F_92 ( & V_185 -> V_170 , V_184 , 1 ) )
goto V_198;
V_185 -> V_4 = F_93 ( V_199 , V_56 -> V_200 ,
V_185 -> V_170 . V_4 , V_185 ,
L_6 , V_185 -> V_183 ) ;
if ( F_61 ( V_185 -> V_4 ) )
goto V_198;
if ( F_94 ( V_185 -> V_4 , & V_201 ) )
goto V_202;
if ( F_94 ( V_185 -> V_4 , & V_203 ) )
goto V_202;
F_95 ( V_56 , & V_204 , V_185 ) ;
return;
V_202:
F_96 ( V_199 , V_185 -> V_170 . V_4 ) ;
V_198:
F_97 ( & V_185 -> V_170 ) ;
if ( V_185 -> V_183 < V_179 )
F_98 ( V_183 , V_190 ) ;
else
F_98 ( V_183 , V_181 ) ;
V_154:
F_11 ( & V_185 -> V_2 , F_1 ) ;
F_99 ( & V_185 -> V_5 ) ;
F_5 ( V_185 ) ;
return;
}
static void F_100 ( struct V_182 * V_56 )
{
struct V_3 * V_185 = F_101 ( V_56 , & V_204 ) ;
if ( ! V_185 )
return;
F_102 ( V_185 -> V_4 , NULL ) ;
F_96 ( V_199 , V_185 -> V_170 . V_4 ) ;
F_97 ( & V_185 -> V_170 ) ;
if ( V_185 -> V_183 < V_179 )
F_98 ( V_185 -> V_183 , V_190 ) ;
else
F_98 ( V_185 -> V_183 - V_179 , V_181 ) ;
F_11 ( & V_185 -> V_2 , F_1 ) ;
F_99 ( & V_185 -> V_5 ) ;
F_5 ( V_185 ) ;
}
static char * F_103 ( struct V_56 * V_4 , T_9 * V_205 )
{
if ( V_205 )
* V_205 = 0666 ;
return F_104 ( V_128 , L_7 , F_105 ( V_4 ) ) ;
}
static int T_10 F_106 ( void )
{
int V_77 ;
V_77 = F_107 ( V_191 , V_179 ,
L_4 ) ;
if ( V_77 ) {
F_82 ( V_180 L_8 ) ;
goto V_134;
}
V_199 = F_108 ( V_193 , L_4 ) ;
if ( F_61 ( V_199 ) ) {
V_77 = F_109 ( V_199 ) ;
F_82 ( V_180 L_9 ) ;
goto V_206;
}
V_199 -> V_207 = F_103 ;
V_77 = F_110 ( V_199 , & V_208 . V_175 ) ;
if ( V_77 ) {
F_82 ( V_180 L_10 ) ;
goto V_209;
}
V_77 = F_111 ( & V_204 ) ;
if ( V_77 ) {
F_82 ( V_180 L_11 ) ;
goto V_209;
}
return 0 ;
V_209:
F_112 ( V_199 ) ;
V_206:
F_113 ( V_191 , V_179 ) ;
V_134:
return V_77 ;
}
static void T_11 F_114 ( void )
{
F_115 ( & V_204 ) ;
F_112 ( V_199 ) ;
F_113 ( V_191 , V_179 ) ;
if ( V_178 )
F_113 ( V_178 , V_179 ) ;
F_116 ( & V_65 ) ;
F_116 ( & V_55 ) ;
F_116 ( & V_36 ) ;
F_116 ( & V_33 ) ;
F_116 ( & V_52 ) ;
F_116 ( & V_43 ) ;
F_116 ( & V_47 ) ;
}
