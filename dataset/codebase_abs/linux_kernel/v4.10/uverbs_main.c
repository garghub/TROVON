int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
V_5 = V_2 -> V_6 -> V_7 ( V_2 ) ;
if ( ! V_5 )
F_2 ( & V_4 -> V_8 ) ;
return V_5 ;
}
static void F_3 ( struct V_9 * V_10 )
{
struct V_11 * V_12 =
F_4 ( V_10 , struct V_11 , V_10 ) ;
F_5 ( & V_12 -> V_13 ) ;
F_6 ( V_12 ) ;
}
static void F_7 ( struct V_14 * V_15 )
{
struct V_16 * V_17 =
F_4 ( V_15 , struct V_16 , V_15 ) ;
F_6 ( V_17 ) ;
}
void F_8 ( struct V_18 * V_17 ,
struct V_16 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 , * V_24 ;
if ( V_19 ) {
F_9 ( & V_19 -> V_25 ) ;
F_10 (evt, tmp, &uobj->comp_list, obj_list) {
F_11 ( & V_23 -> V_26 ) ;
F_6 ( V_23 ) ;
}
F_12 ( & V_19 -> V_25 ) ;
F_13 ( & V_19 -> V_15 , F_7 ) ;
}
F_9 ( & V_17 -> V_27 -> V_25 ) ;
F_10 (evt, tmp, &uobj->async_list, obj_list) {
F_11 ( & V_23 -> V_26 ) ;
F_6 ( V_23 ) ;
}
F_12 ( & V_17 -> V_27 -> V_25 ) ;
}
void F_14 ( struct V_18 * V_17 ,
struct V_28 * V_21 )
{
struct V_22 * V_23 , * V_24 ;
F_9 ( & V_17 -> V_27 -> V_25 ) ;
F_10 (evt, tmp, &uobj->event_list, obj_list) {
F_11 ( & V_23 -> V_26 ) ;
F_6 ( V_23 ) ;
}
F_12 ( & V_17 -> V_27 -> V_25 ) ;
}
static void F_15 ( struct V_29 * V_30 ,
struct V_31 * V_21 )
{
struct V_32 * V_33 , * V_24 ;
F_10 (mcast, tmp, &uobj->mcast_list, list) {
F_16 ( V_30 , & V_33 -> V_34 , V_33 -> V_35 ) ;
F_11 ( & V_33 -> V_26 ) ;
F_6 ( V_33 ) ;
}
}
static int F_17 ( struct V_18 * V_17 ,
struct V_36 * V_37 )
{
struct V_38 * V_21 , * V_24 ;
V_37 -> V_39 = 1 ;
F_10 (uobj, tmp, &context->ah_list, list) {
struct V_40 * V_41 = V_21 -> V_42 ;
F_18 ( & V_43 , V_21 ) ;
F_19 ( V_41 ) ;
F_6 ( V_21 ) ;
}
F_10 (uobj, tmp, &context->mw_list, list) {
struct V_1 * V_2 = V_21 -> V_42 ;
F_18 ( & V_44 , V_21 ) ;
F_1 ( V_2 ) ;
F_6 ( V_21 ) ;
}
F_10 (uobj, tmp, &context->rule_list, list) {
struct V_45 * V_46 = V_21 -> V_42 ;
F_18 ( & V_47 , V_21 ) ;
F_20 ( V_46 ) ;
F_6 ( V_21 ) ;
}
F_10 (uobj, tmp, &context->qp_list, list) {
struct V_29 * V_30 = V_21 -> V_42 ;
struct V_31 * V_48 =
F_4 ( V_21 , struct V_31 , V_49 . V_50 ) ;
F_18 ( & V_51 , V_21 ) ;
if ( V_30 == V_30 -> V_52 )
F_15 ( V_30 , V_48 ) ;
F_21 ( V_30 ) ;
F_14 ( V_17 , & V_48 -> V_49 ) ;
F_6 ( V_48 ) ;
}
F_10 (uobj, tmp, &context->rwq_ind_tbl_list, list) {
struct V_53 * V_54 = V_21 -> V_42 ;
struct V_55 * * V_56 = V_54 -> V_56 ;
F_18 ( & V_57 , V_21 ) ;
F_22 ( V_54 ) ;
F_6 ( V_56 ) ;
F_6 ( V_21 ) ;
}
F_10 (uobj, tmp, &context->wq_list, list) {
struct V_55 * V_58 = V_21 -> V_42 ;
struct V_59 * V_60 =
F_4 ( V_21 , struct V_59 , V_49 . V_50 ) ;
F_18 ( & V_61 , V_21 ) ;
F_23 ( V_58 ) ;
F_14 ( V_17 , & V_60 -> V_49 ) ;
F_6 ( V_60 ) ;
}
F_10 (uobj, tmp, &context->srq_list, list) {
struct V_62 * V_63 = V_21 -> V_42 ;
struct V_28 * V_49 =
F_4 ( V_21 , struct V_28 , V_50 ) ;
F_18 ( & V_64 , V_21 ) ;
F_24 ( V_63 ) ;
F_14 ( V_17 , V_49 ) ;
F_6 ( V_49 ) ;
}
F_10 (uobj, tmp, &context->cq_list, list) {
struct V_65 * V_66 = V_21 -> V_42 ;
struct V_16 * V_19 = V_66 -> V_67 ;
struct V_20 * V_68 =
F_4 ( V_21 , struct V_20 , V_50 ) ;
F_18 ( & V_69 , V_21 ) ;
F_25 ( V_66 ) ;
F_8 ( V_17 , V_19 , V_68 ) ;
F_6 ( V_68 ) ;
}
F_10 (uobj, tmp, &context->mr_list, list) {
struct V_70 * V_71 = V_21 -> V_42 ;
F_18 ( & V_72 , V_21 ) ;
F_26 ( V_71 ) ;
F_6 ( V_21 ) ;
}
F_27 ( & V_17 -> V_6 -> V_73 ) ;
F_10 (uobj, tmp, &context->xrcd_list, list) {
struct V_74 * V_75 = V_21 -> V_42 ;
struct V_76 * V_77 =
F_4 ( V_21 , struct V_76 , V_50 ) ;
F_18 ( & V_78 , V_21 ) ;
F_28 ( V_17 -> V_6 , V_75 ) ;
F_6 ( V_77 ) ;
}
F_29 ( & V_17 -> V_6 -> V_73 ) ;
F_10 (uobj, tmp, &context->pd_list, list) {
struct V_3 * V_4 = V_21 -> V_42 ;
F_18 ( & V_79 , V_21 ) ;
F_30 ( V_4 ) ;
F_6 ( V_21 ) ;
}
F_31 ( V_37 -> V_80 ) ;
return V_37 -> V_6 -> V_81 ( V_37 ) ;
}
static void F_32 ( struct V_11 * V_12 )
{
F_33 ( & V_12 -> V_82 ) ;
}
static void F_34 ( struct V_14 * V_15 )
{
struct V_18 * V_17 =
F_4 ( V_15 , struct V_18 , V_15 ) ;
struct V_83 * V_84 ;
int V_85 ;
V_85 = F_35 ( & V_17 -> V_6 -> V_13 ) ;
V_84 = F_36 ( V_17 -> V_6 -> V_84 ,
& V_17 -> V_6 -> V_13 ) ;
if ( V_84 && ! V_84 -> V_86 )
F_37 ( V_84 -> V_87 ) ;
F_38 ( & V_17 -> V_6 -> V_13 , V_85 ) ;
if ( F_39 ( & V_17 -> V_6 -> V_88 ) )
F_32 ( V_17 -> V_6 ) ;
F_6 ( V_17 ) ;
}
static T_1 F_40 ( struct V_17 * V_89 , char T_2 * V_90 ,
T_3 V_91 , T_4 * V_92 )
{
struct V_16 * V_17 = V_89 -> V_93 ;
struct V_22 * V_94 ;
int V_95 ;
int V_5 = 0 ;
F_9 ( & V_17 -> V_25 ) ;
while ( F_41 ( & V_17 -> V_96 ) ) {
F_12 ( & V_17 -> V_25 ) ;
if ( V_89 -> V_97 & V_98 )
return - V_99 ;
if ( F_42 ( V_17 -> V_100 ,
( ! F_41 ( & V_17 -> V_96 ) ||
! V_17 -> V_101 -> V_6 -> V_84 ) ) )
return - V_102 ;
if ( F_41 ( & V_17 -> V_96 ) &&
! V_17 -> V_101 -> V_6 -> V_84 )
return - V_103 ;
F_9 ( & V_17 -> V_25 ) ;
}
V_94 = F_43 ( V_17 -> V_96 . V_104 , struct V_22 , V_26 ) ;
if ( V_17 -> V_105 )
V_95 = sizeof ( struct V_106 ) ;
else
V_95 = sizeof ( struct V_107 ) ;
if ( V_95 > V_91 ) {
V_5 = - V_108 ;
V_94 = NULL ;
} else {
F_11 ( V_17 -> V_96 . V_104 ) ;
if ( V_94 -> V_109 ) {
++ ( * V_94 -> V_109 ) ;
F_11 ( & V_94 -> V_110 ) ;
}
}
F_12 ( & V_17 -> V_25 ) ;
if ( V_94 ) {
if ( F_44 ( V_90 , V_94 , V_95 ) )
V_5 = - V_111 ;
else
V_5 = V_95 ;
}
F_6 ( V_94 ) ;
return V_5 ;
}
static unsigned int F_45 ( struct V_17 * V_89 ,
struct V_112 * V_113 )
{
unsigned int V_114 = 0 ;
struct V_16 * V_17 = V_89 -> V_93 ;
V_100 ( V_89 , & V_17 -> V_100 , V_113 ) ;
F_9 ( & V_17 -> V_25 ) ;
if ( ! F_41 ( & V_17 -> V_96 ) )
V_114 = V_115 | V_116 ;
F_12 ( & V_17 -> V_25 ) ;
return V_114 ;
}
static int F_46 ( int V_117 , struct V_17 * V_89 , int V_118 )
{
struct V_16 * V_17 = V_89 -> V_93 ;
return F_47 ( V_117 , V_89 , V_118 , & V_17 -> V_119 ) ;
}
static int F_48 ( struct V_120 * V_120 , struct V_17 * V_89 )
{
struct V_16 * V_17 = V_89 -> V_93 ;
struct V_22 * V_121 , * V_24 ;
int V_122 = 0 ;
F_27 ( & V_17 -> V_101 -> V_6 -> V_123 ) ;
F_9 ( & V_17 -> V_25 ) ;
V_122 = V_17 -> V_124 ;
V_17 -> V_124 = 1 ;
F_10 (entry, tmp, &file->event_list, list) {
if ( V_121 -> V_109 )
F_11 ( & V_121 -> V_110 ) ;
F_6 ( V_121 ) ;
}
F_12 ( & V_17 -> V_25 ) ;
if ( ! V_122 ) {
F_11 ( & V_17 -> V_26 ) ;
if ( V_17 -> V_105 )
F_49 ( & V_17 -> V_101 ->
V_125 ) ;
}
F_29 ( & V_17 -> V_101 -> V_6 -> V_123 ) ;
F_13 ( & V_17 -> V_101 -> V_15 , F_34 ) ;
F_13 ( & V_17 -> V_15 , F_7 ) ;
return 0 ;
}
void F_50 ( struct V_65 * V_66 , void * V_67 )
{
struct V_16 * V_17 = V_67 ;
struct V_20 * V_21 ;
struct V_22 * V_121 ;
unsigned long V_126 ;
if ( ! V_17 )
return;
F_51 ( & V_17 -> V_25 , V_126 ) ;
if ( V_17 -> V_124 ) {
F_52 ( & V_17 -> V_25 , V_126 ) ;
return;
}
V_121 = F_53 ( sizeof *V_121 , V_127 ) ;
if ( ! V_121 ) {
F_52 ( & V_17 -> V_25 , V_126 ) ;
return;
}
V_21 = F_4 ( V_66 -> V_50 , struct V_20 , V_50 ) ;
V_121 -> V_128 . V_82 . V_129 = V_66 -> V_50 -> V_130 ;
V_121 -> V_109 = & V_21 -> V_131 ;
F_54 ( & V_121 -> V_26 , & V_17 -> V_96 ) ;
F_54 ( & V_121 -> V_110 , & V_21 -> V_132 ) ;
F_52 ( & V_17 -> V_25 , V_126 ) ;
F_55 ( & V_17 -> V_100 ) ;
F_56 ( & V_17 -> V_119 , V_133 , V_134 ) ;
}
static void F_57 ( struct V_18 * V_17 ,
T_5 V_135 , T_5 V_94 ,
struct V_136 * V_110 ,
T_6 * V_109 )
{
struct V_22 * V_121 ;
unsigned long V_126 ;
F_51 ( & V_17 -> V_27 -> V_25 , V_126 ) ;
if ( V_17 -> V_27 -> V_124 ) {
F_52 ( & V_17 -> V_27 -> V_25 , V_126 ) ;
return;
}
V_121 = F_53 ( sizeof *V_121 , V_127 ) ;
if ( ! V_121 ) {
F_52 ( & V_17 -> V_27 -> V_25 , V_126 ) ;
return;
}
V_121 -> V_128 . V_137 . V_135 = V_135 ;
V_121 -> V_128 . V_137 . V_138 = V_94 ;
V_121 -> V_128 . V_137 . V_139 = 0 ;
V_121 -> V_109 = V_109 ;
F_54 ( & V_121 -> V_26 , & V_17 -> V_27 -> V_96 ) ;
if ( V_110 )
F_54 ( & V_121 -> V_110 , V_110 ) ;
F_52 ( & V_17 -> V_27 -> V_25 , V_126 ) ;
F_55 ( & V_17 -> V_27 -> V_100 ) ;
F_56 ( & V_17 -> V_27 -> V_119 , V_133 , V_134 ) ;
}
void F_58 ( struct V_140 * V_94 , void * V_141 )
{
struct V_20 * V_21 = F_4 ( V_94 -> V_135 . V_66 -> V_50 ,
struct V_20 , V_50 ) ;
F_57 ( V_21 -> V_101 , V_21 -> V_50 . V_130 ,
V_94 -> V_94 , & V_21 -> V_142 ,
& V_21 -> V_143 ) ;
}
void F_59 ( struct V_140 * V_94 , void * V_141 )
{
struct V_28 * V_21 ;
if ( ! V_94 -> V_135 . V_30 -> V_50 || ! V_94 -> V_135 . V_30 -> V_50 -> V_144 )
return;
V_21 = F_4 ( V_94 -> V_135 . V_30 -> V_50 ,
struct V_28 , V_50 ) ;
F_57 ( V_141 , V_21 -> V_50 . V_130 ,
V_94 -> V_94 , & V_21 -> V_96 ,
& V_21 -> V_145 ) ;
}
void F_60 ( struct V_140 * V_94 , void * V_141 )
{
struct V_28 * V_21 = F_4 ( V_94 -> V_135 . V_58 -> V_50 ,
struct V_28 , V_50 ) ;
F_57 ( V_141 , V_21 -> V_50 . V_130 ,
V_94 -> V_94 , & V_21 -> V_96 ,
& V_21 -> V_145 ) ;
}
void F_61 ( struct V_140 * V_94 , void * V_141 )
{
struct V_28 * V_21 ;
V_21 = F_4 ( V_94 -> V_135 . V_63 -> V_50 ,
struct V_28 , V_50 ) ;
F_57 ( V_141 , V_21 -> V_50 . V_130 ,
V_94 -> V_94 , & V_21 -> V_96 ,
& V_21 -> V_145 ) ;
}
void F_62 ( struct V_146 * V_147 ,
struct V_140 * V_94 )
{
struct V_18 * V_17 =
F_4 ( V_147 , struct V_18 , V_125 ) ;
F_57 ( V_17 , V_94 -> V_135 . V_148 , V_94 -> V_94 ,
NULL , NULL ) ;
}
void F_63 ( struct V_18 * V_17 )
{
F_13 ( & V_17 -> V_27 -> V_15 , F_7 ) ;
V_17 -> V_27 = NULL ;
}
struct V_17 * F_64 ( struct V_18 * V_101 ,
struct V_83 * V_84 ,
int V_105 )
{
struct V_16 * V_19 ;
struct V_17 * V_89 ;
int V_5 ;
V_19 = F_65 ( sizeof( * V_19 ) , V_149 ) ;
if ( ! V_19 )
return F_66 ( - V_150 ) ;
F_67 ( & V_19 -> V_15 ) ;
F_68 ( & V_19 -> V_25 ) ;
F_69 ( & V_19 -> V_96 ) ;
F_70 ( & V_19 -> V_100 ) ;
V_19 -> V_101 = V_101 ;
F_71 ( & V_19 -> V_101 -> V_15 ) ;
V_19 -> V_119 = NULL ;
V_19 -> V_124 = 0 ;
V_89 = F_72 ( L_1 , & V_151 ,
V_19 , V_152 ) ;
if ( F_73 ( V_89 ) )
goto V_153;
F_27 ( & V_101 -> V_6 -> V_123 ) ;
F_54 ( & V_19 -> V_26 ,
& V_101 -> V_6 -> V_154 ) ;
F_29 ( & V_101 -> V_6 -> V_123 ) ;
if ( V_105 ) {
F_74 ( V_101 -> V_27 ) ;
V_101 -> V_27 = V_19 ;
F_71 ( & V_101 -> V_27 -> V_15 ) ;
F_75 ( & V_101 -> V_125 ,
V_84 ,
F_62 ) ;
V_5 = F_76 ( & V_101 -> V_125 ) ;
if ( V_5 )
goto V_155;
V_19 -> V_105 = 1 ;
}
return V_89 ;
V_155:
F_77 ( V_89 ) ;
F_13 ( & V_101 -> V_27 -> V_15 , F_7 ) ;
V_101 -> V_27 = NULL ;
return F_66 ( V_5 ) ;
V_153:
F_13 ( & V_19 -> V_101 -> V_15 , F_34 ) ;
F_13 ( & V_19 -> V_15 , F_7 ) ;
return V_89 ;
}
struct V_16 * F_78 ( int V_117 )
{
struct V_16 * V_19 = NULL ;
struct V_117 V_156 = F_79 ( V_117 ) ;
if ( ! V_156 . V_17 )
return NULL ;
if ( V_156 . V_17 -> V_157 != & V_151 )
goto V_158;
V_19 = V_156 . V_17 -> V_93 ;
if ( V_19 -> V_105 ) {
V_19 = NULL ;
goto V_158;
}
F_71 ( & V_19 -> V_15 ) ;
V_158:
F_80 ( V_156 ) ;
return V_19 ;
}
static int F_81 ( struct V_83 * V_84 , T_7 V_159 )
{
T_8 V_160 ;
if ( V_159 <= V_161 )
V_160 = V_84 -> V_162 ;
else
V_160 = V_84 -> V_163 ;
if ( V_160 & ( ( T_8 ) 1 << V_159 ) )
return 0 ;
return - 1 ;
}
static T_1 F_82 ( struct V_17 * V_89 , const char T_2 * V_90 ,
T_3 V_91 , T_4 * V_92 )
{
struct V_18 * V_17 = V_89 -> V_93 ;
struct V_83 * V_84 ;
struct V_164 V_165 ;
T_7 V_159 ;
T_7 V_126 ;
int V_85 ;
T_1 V_5 ;
if ( ! F_83 ( V_89 ) ) {
F_84 ( L_2 ,
F_85 ( V_166 ) , V_166 -> V_167 ) ;
return - V_168 ;
}
if ( V_91 < sizeof V_165 )
return - V_108 ;
if ( F_86 ( & V_165 , V_90 , sizeof V_165 ) )
return - V_111 ;
V_85 = F_35 ( & V_17 -> V_6 -> V_13 ) ;
V_84 = F_36 ( V_17 -> V_6 -> V_84 ,
& V_17 -> V_6 -> V_13 ) ;
if ( ! V_84 ) {
V_5 = - V_103 ;
goto V_158;
}
if ( V_165 . V_159 & ~ ( T_7 ) ( V_169 |
V_170 ) ) {
V_5 = - V_108 ;
goto V_158;
}
V_159 = V_165 . V_159 & V_170 ;
if ( F_81 ( V_84 , V_159 ) ) {
V_5 = - V_171 ;
goto V_158;
}
if ( ! V_17 -> V_172 &&
V_159 != V_173 ) {
V_5 = - V_108 ;
goto V_158;
}
V_126 = ( V_165 . V_159 &
V_169 ) >> V_174 ;
if ( ! V_126 ) {
if ( V_159 >= F_87 ( V_175 ) ||
! V_175 [ V_159 ] ) {
V_5 = - V_108 ;
goto V_158;
}
if ( V_165 . V_176 * 4 != V_91 ) {
V_5 = - V_108 ;
goto V_158;
}
V_5 = V_175 [ V_159 ] ( V_17 , V_84 ,
V_90 + sizeof( V_165 ) ,
V_165 . V_176 * 4 ,
V_165 . V_177 * 4 ) ;
} else if ( V_126 == V_178 ) {
struct V_179 V_180 ;
struct V_181 V_182 ;
struct V_181 V_183 ;
T_3 V_184 = V_91 ;
if ( V_159 >= F_87 ( V_185 ) ||
! V_185 [ V_159 ] ) {
V_5 = - V_186 ;
goto V_158;
}
if ( ! V_17 -> V_172 ) {
V_5 = - V_108 ;
goto V_158;
}
if ( V_91 < ( sizeof( V_165 ) + sizeof( V_180 ) ) ) {
V_5 = - V_108 ;
goto V_158;
}
if ( F_86 ( & V_180 , V_90 + sizeof( V_165 ) , sizeof( V_180 ) ) ) {
V_5 = - V_111 ;
goto V_158;
}
V_91 -= sizeof( V_165 ) + sizeof( V_180 ) ;
V_90 += sizeof( V_165 ) + sizeof( V_180 ) ;
if ( ( V_165 . V_176 + V_180 . V_187 ) * 8 != V_91 ) {
V_5 = - V_108 ;
goto V_158;
}
if ( V_180 . V_188 ) {
V_5 = - V_108 ;
goto V_158;
}
if ( V_180 . V_189 ) {
if ( ! V_165 . V_177 && ! V_180 . V_190 ) {
V_5 = - V_108 ;
goto V_158;
}
if ( ! F_88 ( V_191 ,
( void T_2 * ) ( unsigned long ) V_180 . V_189 ,
( V_165 . V_177 + V_180 . V_190 ) * 8 ) ) {
V_5 = - V_111 ;
goto V_158;
}
} else {
if ( V_165 . V_177 || V_180 . V_190 ) {
V_5 = - V_108 ;
goto V_158;
}
}
F_89 ( & V_182 , V_90 , ( unsigned long ) V_180 . V_189 ,
V_165 . V_176 * 8 , V_165 . V_177 * 8 ) ;
F_89 ( & V_183 ,
V_90 + V_182 . V_192 ,
( unsigned long ) V_180 . V_189 + V_182 . V_193 ,
V_180 . V_187 * 8 ,
V_180 . V_190 * 8 ) ;
V_5 = V_185 [ V_159 ] ( V_17 ,
V_84 ,
& V_182 ,
& V_183 ) ;
if ( ! V_5 )
V_5 = V_184 ;
} else {
V_5 = - V_186 ;
}
V_158:
F_38 ( & V_17 -> V_6 -> V_13 , V_85 ) ;
return V_5 ;
}
static int F_90 ( struct V_17 * V_89 , struct V_194 * V_195 )
{
struct V_18 * V_17 = V_89 -> V_93 ;
struct V_83 * V_84 ;
int V_5 = 0 ;
int V_85 ;
V_85 = F_35 ( & V_17 -> V_6 -> V_13 ) ;
V_84 = F_36 ( V_17 -> V_6 -> V_84 ,
& V_17 -> V_6 -> V_13 ) ;
if ( ! V_84 ) {
V_5 = - V_103 ;
goto V_158;
}
if ( ! V_17 -> V_172 )
V_5 = - V_196 ;
else
V_5 = V_84 -> V_197 ( V_17 -> V_172 , V_195 ) ;
V_158:
F_38 ( & V_17 -> V_6 -> V_13 , V_85 ) ;
return V_5 ;
}
static int F_91 ( struct V_120 * V_120 , struct V_17 * V_89 )
{
struct V_11 * V_12 ;
struct V_18 * V_17 ;
struct V_83 * V_84 ;
int V_5 ;
int V_198 ;
int V_85 ;
V_12 = F_4 ( V_120 -> V_199 , struct V_11 , V_200 ) ;
if ( ! F_92 ( & V_12 -> V_88 ) )
return - V_201 ;
V_85 = F_35 ( & V_12 -> V_13 ) ;
F_27 ( & V_12 -> V_123 ) ;
V_84 = F_36 ( V_12 -> V_84 ,
& V_12 -> V_13 ) ;
if ( ! V_84 ) {
V_5 = - V_103 ;
goto V_202;
}
V_198 = ! ( V_84 -> V_86 ) ;
if ( V_198 ) {
if ( ! F_93 ( V_84 -> V_87 ) ) {
V_5 = - V_196 ;
goto V_202;
}
}
V_17 = F_65 ( sizeof( * V_17 ) , V_149 ) ;
if ( ! V_17 ) {
V_5 = - V_150 ;
if ( V_198 )
goto V_203;
goto V_202;
}
V_17 -> V_6 = V_12 ;
V_17 -> V_172 = NULL ;
V_17 -> V_27 = NULL ;
F_67 ( & V_17 -> V_15 ) ;
F_94 ( & V_17 -> V_204 ) ;
F_94 ( & V_17 -> V_205 ) ;
V_89 -> V_93 = V_17 ;
F_95 ( & V_12 -> V_10 ) ;
F_54 ( & V_17 -> V_26 , & V_12 -> V_206 ) ;
F_29 ( & V_12 -> V_123 ) ;
F_38 ( & V_12 -> V_13 , V_85 ) ;
return F_96 ( V_120 , V_89 ) ;
V_203:
F_37 ( V_84 -> V_87 ) ;
V_202:
F_29 ( & V_12 -> V_123 ) ;
F_38 ( & V_12 -> V_13 , V_85 ) ;
if ( F_39 ( & V_12 -> V_88 ) )
F_32 ( V_12 ) ;
return V_5 ;
}
static int F_97 ( struct V_120 * V_120 , struct V_17 * V_89 )
{
struct V_18 * V_17 = V_89 -> V_93 ;
struct V_11 * V_12 = V_17 -> V_6 ;
F_27 ( & V_17 -> V_205 ) ;
if ( V_17 -> V_172 ) {
F_17 ( V_17 , V_17 -> V_172 ) ;
V_17 -> V_172 = NULL ;
}
F_29 ( & V_17 -> V_205 ) ;
F_27 ( & V_17 -> V_6 -> V_123 ) ;
if ( ! V_17 -> V_124 ) {
F_11 ( & V_17 -> V_26 ) ;
V_17 -> V_124 = 1 ;
}
F_29 ( & V_17 -> V_6 -> V_123 ) ;
if ( V_17 -> V_27 )
F_13 ( & V_17 -> V_27 -> V_15 , F_7 ) ;
F_13 ( & V_17 -> V_15 , F_34 ) ;
F_98 ( & V_12 -> V_10 ) ;
return 0 ;
}
static T_1 F_99 ( struct V_6 * V_6 , struct V_207 * V_208 ,
char * V_90 )
{
int V_5 = - V_196 ;
int V_85 ;
struct V_11 * V_12 = F_100 ( V_6 ) ;
struct V_83 * V_84 ;
if ( ! V_12 )
return - V_196 ;
V_85 = F_35 ( & V_12 -> V_13 ) ;
V_84 = F_36 ( V_12 -> V_84 , & V_12 -> V_13 ) ;
if ( V_84 )
V_5 = sprintf ( V_90 , L_3 , V_84 -> V_209 ) ;
F_38 ( & V_12 -> V_13 , V_85 ) ;
return V_5 ;
}
static T_1 F_101 ( struct V_6 * V_6 ,
struct V_207 * V_208 , char * V_90 )
{
struct V_11 * V_12 = F_100 ( V_6 ) ;
int V_5 = - V_196 ;
int V_85 ;
struct V_83 * V_84 ;
if ( ! V_12 )
return - V_196 ;
V_85 = F_35 ( & V_12 -> V_13 ) ;
V_84 = F_36 ( V_12 -> V_84 , & V_12 -> V_13 ) ;
if ( V_84 )
V_5 = sprintf ( V_90 , L_4 , V_84 -> V_210 ) ;
F_38 ( & V_12 -> V_13 , V_85 ) ;
return V_5 ;
}
static int F_102 ( void )
{
int V_5 ;
if ( ! V_211 ) {
V_5 = F_103 ( & V_211 , 0 , V_212 ,
L_5 ) ;
if ( V_5 ) {
F_104 ( L_6 ) ;
return V_5 ;
}
}
V_5 = F_105 ( V_213 , V_212 ) ;
if ( V_5 >= V_212 )
return - 1 ;
return V_5 ;
}
static void F_106 ( struct V_83 * V_6 )
{
int V_214 ;
T_9 V_215 ;
struct V_11 * V_216 ;
int V_5 ;
if ( ! V_6 -> V_217 )
return;
V_216 = F_65 ( sizeof *V_216 , V_149 ) ;
if ( ! V_216 )
return;
V_5 = F_107 ( & V_216 -> V_13 ) ;
if ( V_5 ) {
F_6 ( V_216 ) ;
return;
}
F_108 ( & V_216 -> V_88 , 1 ) ;
F_109 ( & V_216 -> V_82 ) ;
V_216 -> V_218 = V_219 ;
F_94 ( & V_216 -> V_73 ) ;
F_110 ( & V_216 -> V_10 , & V_220 ) ;
F_94 ( & V_216 -> V_123 ) ;
F_69 ( & V_216 -> V_206 ) ;
F_69 ( & V_216 -> V_154 ) ;
F_111 ( & V_221 ) ;
V_214 = F_105 ( V_222 , V_212 ) ;
if ( V_214 >= V_212 ) {
F_112 ( & V_221 ) ;
V_214 = F_102 () ;
if ( V_214 < 0 )
goto V_202;
F_111 ( & V_221 ) ;
V_216 -> V_214 = V_214 + V_212 ;
V_215 = V_214 + V_211 ;
F_113 ( V_214 , V_213 ) ;
} else {
V_216 -> V_214 = V_214 ;
V_215 = V_214 + V_223 ;
F_113 ( V_214 , V_222 ) ;
}
F_112 ( & V_221 ) ;
F_114 ( V_216 -> V_84 , V_6 ) ;
V_216 -> V_224 = V_6 -> V_224 ;
F_115 ( & V_216 -> V_200 , NULL ) ;
V_216 -> V_200 . V_87 = V_225 ;
V_216 -> V_200 . V_226 = V_6 -> V_197 ? & V_227 : & V_228 ;
V_216 -> V_200 . V_10 . V_229 = & V_216 -> V_10 ;
F_116 ( & V_216 -> V_200 . V_10 , L_7 , V_216 -> V_214 ) ;
if ( F_117 ( & V_216 -> V_200 , V_215 , 1 ) )
goto V_230;
V_216 -> V_12 = F_118 ( V_231 , V_6 -> V_232 ,
V_216 -> V_200 . V_12 , V_216 ,
L_7 , V_216 -> V_214 ) ;
if ( F_73 ( V_216 -> V_12 ) )
goto V_230;
if ( F_119 ( V_216 -> V_12 , & V_233 ) )
goto V_234;
if ( F_119 ( V_216 -> V_12 , & V_235 ) )
goto V_234;
F_120 ( V_6 , & V_236 , V_216 ) ;
return;
V_234:
F_121 ( V_231 , V_216 -> V_200 . V_12 ) ;
V_230:
F_122 ( & V_216 -> V_200 ) ;
if ( V_216 -> V_214 < V_212 )
F_123 ( V_214 , V_222 ) ;
else
F_123 ( V_214 , V_213 ) ;
V_202:
if ( F_39 ( & V_216 -> V_88 ) )
F_32 ( V_216 ) ;
F_124 ( & V_216 -> V_82 ) ;
F_98 ( & V_216 -> V_10 ) ;
return;
}
static void F_125 ( struct V_11 * V_216 ,
struct V_83 * V_84 )
{
struct V_18 * V_17 ;
struct V_16 * V_237 ;
struct V_140 V_94 ;
F_126 ( & V_216 -> V_13 ) ;
V_94 . V_94 = V_238 ;
V_94 . V_135 . V_148 = 0 ;
V_94 . V_6 = V_84 ;
F_27 ( & V_216 -> V_123 ) ;
while ( ! F_41 ( & V_216 -> V_206 ) ) {
struct V_36 * V_172 ;
V_17 = F_127 ( & V_216 -> V_206 ,
struct V_18 , V_26 ) ;
V_17 -> V_124 = 1 ;
F_11 ( & V_17 -> V_26 ) ;
F_71 ( & V_17 -> V_15 ) ;
F_29 ( & V_216 -> V_123 ) ;
F_62 ( & V_17 -> V_125 , & V_94 ) ;
F_27 ( & V_17 -> V_205 ) ;
V_172 = V_17 -> V_172 ;
V_17 -> V_172 = NULL ;
F_29 ( & V_17 -> V_205 ) ;
if ( V_172 ) {
V_84 -> V_86 ( V_172 ) ;
F_17 ( V_17 , V_172 ) ;
}
F_27 ( & V_216 -> V_123 ) ;
F_13 ( & V_17 -> V_15 , F_34 ) ;
}
while ( ! F_41 ( & V_216 -> V_154 ) ) {
V_237 = F_127 ( & V_216 ->
V_154 ,
struct V_16 ,
V_26 ) ;
F_9 ( & V_237 -> V_25 ) ;
V_237 -> V_124 = 1 ;
F_12 ( & V_237 -> V_25 ) ;
F_11 ( & V_237 -> V_26 ) ;
if ( V_237 -> V_105 ) {
F_49 ( & V_237 -> V_101 ->
V_125 ) ;
V_237 -> V_101 -> V_125 . V_6 = NULL ;
}
F_55 ( & V_237 -> V_100 ) ;
F_56 ( & V_237 -> V_119 , V_133 , V_134 ) ;
}
F_29 ( & V_216 -> V_123 ) ;
}
static void F_128 ( struct V_83 * V_6 , void * V_239 )
{
struct V_11 * V_216 = V_239 ;
int V_240 = 1 ;
if ( ! V_216 )
return;
F_129 ( V_216 -> V_12 , NULL ) ;
F_121 ( V_231 , V_216 -> V_200 . V_12 ) ;
F_122 ( & V_216 -> V_200 ) ;
if ( V_216 -> V_214 < V_212 )
F_123 ( V_216 -> V_214 , V_222 ) ;
else
F_123 ( V_216 -> V_214 - V_212 , V_213 ) ;
if ( V_6 -> V_86 ) {
F_114 ( V_216 -> V_84 , NULL ) ;
F_125 ( V_216 , V_6 ) ;
V_240 = 0 ;
}
if ( F_39 ( & V_216 -> V_88 ) )
F_32 ( V_216 ) ;
if ( V_240 )
F_124 ( & V_216 -> V_82 ) ;
F_98 ( & V_216 -> V_10 ) ;
}
static char * F_130 ( struct V_6 * V_12 , T_10 * V_241 )
{
if ( V_241 )
* V_241 = 0666 ;
return F_131 ( V_149 , L_8 , F_132 ( V_12 ) ) ;
}
static int T_11 F_133 ( void )
{
int V_5 ;
V_5 = F_134 ( V_223 , V_212 ,
L_5 ) ;
if ( V_5 ) {
F_104 ( L_9 ) ;
goto V_158;
}
V_231 = F_135 ( V_225 , L_5 ) ;
if ( F_73 ( V_231 ) ) {
V_5 = F_136 ( V_231 ) ;
F_104 ( L_10 ) ;
goto V_242;
}
V_231 -> V_243 = F_130 ;
V_5 = F_137 ( V_231 , & V_244 . V_208 ) ;
if ( V_5 ) {
F_104 ( L_11 ) ;
goto V_245;
}
V_5 = F_138 ( & V_236 ) ;
if ( V_5 ) {
F_104 ( L_12 ) ;
goto V_245;
}
return 0 ;
V_245:
F_139 ( V_231 ) ;
V_242:
F_140 ( V_223 , V_212 ) ;
V_158:
return V_5 ;
}
static void T_12 F_141 ( void )
{
F_142 ( & V_236 ) ;
F_139 ( V_231 ) ;
F_140 ( V_223 , V_212 ) ;
if ( V_211 )
F_140 ( V_211 , V_212 ) ;
F_143 ( & V_79 ) ;
F_143 ( & V_72 ) ;
F_143 ( & V_44 ) ;
F_143 ( & V_43 ) ;
F_143 ( & V_69 ) ;
F_143 ( & V_51 ) ;
F_143 ( & V_64 ) ;
}
