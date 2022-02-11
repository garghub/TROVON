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
if ( V_30 != V_30 -> V_52 ) {
F_21 ( V_30 ) ;
} else {
F_15 ( V_30 , V_48 ) ;
F_22 ( V_30 ) ;
}
F_14 ( V_17 , & V_48 -> V_49 ) ;
F_6 ( V_48 ) ;
}
F_10 (uobj, tmp, &context->rwq_ind_tbl_list, list) {
struct V_53 * V_54 = V_21 -> V_42 ;
struct V_55 * * V_56 = V_54 -> V_56 ;
F_18 ( & V_57 , V_21 ) ;
F_23 ( V_54 ) ;
F_6 ( V_56 ) ;
F_6 ( V_21 ) ;
}
F_10 (uobj, tmp, &context->wq_list, list) {
struct V_55 * V_58 = V_21 -> V_42 ;
struct V_59 * V_60 =
F_4 ( V_21 , struct V_59 , V_49 . V_50 ) ;
F_18 ( & V_61 , V_21 ) ;
F_24 ( V_58 ) ;
F_14 ( V_17 , & V_60 -> V_49 ) ;
F_6 ( V_60 ) ;
}
F_10 (uobj, tmp, &context->srq_list, list) {
struct V_62 * V_63 = V_21 -> V_42 ;
struct V_28 * V_49 =
F_4 ( V_21 , struct V_28 , V_50 ) ;
F_18 ( & V_64 , V_21 ) ;
F_25 ( V_63 ) ;
F_14 ( V_17 , V_49 ) ;
F_6 ( V_49 ) ;
}
F_10 (uobj, tmp, &context->cq_list, list) {
struct V_65 * V_66 = V_21 -> V_42 ;
struct V_16 * V_19 = V_66 -> V_67 ;
struct V_20 * V_68 =
F_4 ( V_21 , struct V_20 , V_50 ) ;
F_18 ( & V_69 , V_21 ) ;
F_26 ( V_66 ) ;
F_8 ( V_17 , V_19 , V_68 ) ;
F_6 ( V_68 ) ;
}
F_10 (uobj, tmp, &context->mr_list, list) {
struct V_70 * V_71 = V_21 -> V_42 ;
F_18 ( & V_72 , V_21 ) ;
F_27 ( V_71 ) ;
F_6 ( V_21 ) ;
}
F_28 ( & V_17 -> V_6 -> V_73 ) ;
F_10 (uobj, tmp, &context->xrcd_list, list) {
struct V_74 * V_75 = V_21 -> V_42 ;
struct V_76 * V_77 =
F_4 ( V_21 , struct V_76 , V_50 ) ;
F_18 ( & V_78 , V_21 ) ;
F_29 ( V_17 -> V_6 , V_75 ) ;
F_6 ( V_77 ) ;
}
F_30 ( & V_17 -> V_6 -> V_73 ) ;
F_10 (uobj, tmp, &context->pd_list, list) {
struct V_3 * V_4 = V_21 -> V_42 ;
F_18 ( & V_79 , V_21 ) ;
F_31 ( V_4 ) ;
F_6 ( V_21 ) ;
}
F_32 ( V_37 -> V_80 ) ;
return V_37 -> V_6 -> V_81 ( V_37 ) ;
}
static void F_33 ( struct V_11 * V_12 )
{
F_34 ( & V_12 -> V_82 ) ;
}
static void F_35 ( struct V_14 * V_15 )
{
struct V_18 * V_17 =
F_4 ( V_15 , struct V_18 , V_15 ) ;
struct V_83 * V_84 ;
int V_85 ;
V_85 = F_36 ( & V_17 -> V_6 -> V_13 ) ;
V_84 = F_37 ( V_17 -> V_6 -> V_84 ,
& V_17 -> V_6 -> V_13 ) ;
if ( V_84 && ! V_84 -> V_86 )
F_38 ( V_84 -> V_87 ) ;
F_39 ( & V_17 -> V_6 -> V_13 , V_85 ) ;
if ( F_40 ( & V_17 -> V_6 -> V_88 ) )
F_33 ( V_17 -> V_6 ) ;
F_6 ( V_17 ) ;
}
static T_1 F_41 ( struct V_17 * V_89 , char T_2 * V_90 ,
T_3 V_91 , T_4 * V_92 )
{
struct V_16 * V_17 = V_89 -> V_93 ;
struct V_22 * V_94 ;
int V_95 ;
int V_5 = 0 ;
F_9 ( & V_17 -> V_25 ) ;
while ( F_42 ( & V_17 -> V_96 ) ) {
F_12 ( & V_17 -> V_25 ) ;
if ( V_89 -> V_97 & V_98 )
return - V_99 ;
if ( F_43 ( V_17 -> V_100 ,
( ! F_42 ( & V_17 -> V_96 ) ||
! V_17 -> V_101 -> V_6 -> V_84 ) ) )
return - V_102 ;
if ( F_42 ( & V_17 -> V_96 ) &&
! V_17 -> V_101 -> V_6 -> V_84 )
return - V_103 ;
F_9 ( & V_17 -> V_25 ) ;
}
V_94 = F_44 ( V_17 -> V_96 . V_104 , struct V_22 , V_26 ) ;
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
if ( F_45 ( V_90 , V_94 , V_95 ) )
V_5 = - V_111 ;
else
V_5 = V_95 ;
}
F_6 ( V_94 ) ;
return V_5 ;
}
static unsigned int F_46 ( struct V_17 * V_89 ,
struct V_112 * V_113 )
{
unsigned int V_114 = 0 ;
struct V_16 * V_17 = V_89 -> V_93 ;
V_100 ( V_89 , & V_17 -> V_100 , V_113 ) ;
F_9 ( & V_17 -> V_25 ) ;
if ( ! F_42 ( & V_17 -> V_96 ) )
V_114 = V_115 | V_116 ;
F_12 ( & V_17 -> V_25 ) ;
return V_114 ;
}
static int F_47 ( int V_117 , struct V_17 * V_89 , int V_118 )
{
struct V_16 * V_17 = V_89 -> V_93 ;
return F_48 ( V_117 , V_89 , V_118 , & V_17 -> V_119 ) ;
}
static int F_49 ( struct V_120 * V_120 , struct V_17 * V_89 )
{
struct V_16 * V_17 = V_89 -> V_93 ;
struct V_22 * V_121 , * V_24 ;
int V_122 = 0 ;
F_28 ( & V_17 -> V_101 -> V_6 -> V_123 ) ;
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
F_50 ( & V_17 -> V_101 ->
V_125 ) ;
}
F_30 ( & V_17 -> V_101 -> V_6 -> V_123 ) ;
F_13 ( & V_17 -> V_101 -> V_15 , F_35 ) ;
F_13 ( & V_17 -> V_15 , F_7 ) ;
return 0 ;
}
void F_51 ( struct V_65 * V_66 , void * V_67 )
{
struct V_16 * V_17 = V_67 ;
struct V_20 * V_21 ;
struct V_22 * V_121 ;
unsigned long V_126 ;
if ( ! V_17 )
return;
F_52 ( & V_17 -> V_25 , V_126 ) ;
if ( V_17 -> V_124 ) {
F_53 ( & V_17 -> V_25 , V_126 ) ;
return;
}
V_121 = F_54 ( sizeof *V_121 , V_127 ) ;
if ( ! V_121 ) {
F_53 ( & V_17 -> V_25 , V_126 ) ;
return;
}
V_21 = F_4 ( V_66 -> V_50 , struct V_20 , V_50 ) ;
V_121 -> V_128 . V_82 . V_129 = V_66 -> V_50 -> V_130 ;
V_121 -> V_109 = & V_21 -> V_131 ;
F_55 ( & V_121 -> V_26 , & V_17 -> V_96 ) ;
F_55 ( & V_121 -> V_110 , & V_21 -> V_132 ) ;
F_53 ( & V_17 -> V_25 , V_126 ) ;
F_56 ( & V_17 -> V_100 ) ;
F_57 ( & V_17 -> V_119 , V_133 , V_134 ) ;
}
static void F_58 ( struct V_18 * V_17 ,
T_5 V_135 , T_5 V_94 ,
struct V_136 * V_110 ,
T_6 * V_109 )
{
struct V_22 * V_121 ;
unsigned long V_126 ;
F_52 ( & V_17 -> V_27 -> V_25 , V_126 ) ;
if ( V_17 -> V_27 -> V_124 ) {
F_53 ( & V_17 -> V_27 -> V_25 , V_126 ) ;
return;
}
V_121 = F_54 ( sizeof *V_121 , V_127 ) ;
if ( ! V_121 ) {
F_53 ( & V_17 -> V_27 -> V_25 , V_126 ) ;
return;
}
V_121 -> V_128 . V_137 . V_135 = V_135 ;
V_121 -> V_128 . V_137 . V_138 = V_94 ;
V_121 -> V_128 . V_137 . V_139 = 0 ;
V_121 -> V_109 = V_109 ;
F_55 ( & V_121 -> V_26 , & V_17 -> V_27 -> V_96 ) ;
if ( V_110 )
F_55 ( & V_121 -> V_110 , V_110 ) ;
F_53 ( & V_17 -> V_27 -> V_25 , V_126 ) ;
F_56 ( & V_17 -> V_27 -> V_100 ) ;
F_57 ( & V_17 -> V_27 -> V_119 , V_133 , V_134 ) ;
}
void F_59 ( struct V_140 * V_94 , void * V_141 )
{
struct V_20 * V_21 = F_4 ( V_94 -> V_135 . V_66 -> V_50 ,
struct V_20 , V_50 ) ;
F_58 ( V_21 -> V_101 , V_21 -> V_50 . V_130 ,
V_94 -> V_94 , & V_21 -> V_142 ,
& V_21 -> V_143 ) ;
}
void F_60 ( struct V_140 * V_94 , void * V_141 )
{
struct V_28 * V_21 ;
if ( ! V_94 -> V_135 . V_30 -> V_50 || ! V_94 -> V_135 . V_30 -> V_50 -> V_144 )
return;
V_21 = F_4 ( V_94 -> V_135 . V_30 -> V_50 ,
struct V_28 , V_50 ) ;
F_58 ( V_141 , V_21 -> V_50 . V_130 ,
V_94 -> V_94 , & V_21 -> V_96 ,
& V_21 -> V_145 ) ;
}
void F_61 ( struct V_140 * V_94 , void * V_141 )
{
struct V_28 * V_21 = F_4 ( V_94 -> V_135 . V_58 -> V_50 ,
struct V_28 , V_50 ) ;
F_58 ( V_141 , V_21 -> V_50 . V_130 ,
V_94 -> V_94 , & V_21 -> V_96 ,
& V_21 -> V_145 ) ;
}
void F_62 ( struct V_140 * V_94 , void * V_141 )
{
struct V_28 * V_21 ;
V_21 = F_4 ( V_94 -> V_135 . V_63 -> V_50 ,
struct V_28 , V_50 ) ;
F_58 ( V_141 , V_21 -> V_50 . V_130 ,
V_94 -> V_94 , & V_21 -> V_96 ,
& V_21 -> V_145 ) ;
}
void F_63 ( struct V_146 * V_147 ,
struct V_140 * V_94 )
{
struct V_18 * V_17 =
F_4 ( V_147 , struct V_18 , V_125 ) ;
F_58 ( V_17 , V_94 -> V_135 . V_148 , V_94 -> V_94 ,
NULL , NULL ) ;
}
void F_64 ( struct V_18 * V_17 )
{
F_13 ( & V_17 -> V_27 -> V_15 , F_7 ) ;
V_17 -> V_27 = NULL ;
}
struct V_17 * F_65 ( struct V_18 * V_101 ,
struct V_83 * V_84 ,
int V_105 )
{
struct V_16 * V_19 ;
struct V_17 * V_89 ;
int V_5 ;
V_19 = F_66 ( sizeof( * V_19 ) , V_149 ) ;
if ( ! V_19 )
return F_67 ( - V_150 ) ;
F_68 ( & V_19 -> V_15 ) ;
F_69 ( & V_19 -> V_25 ) ;
F_70 ( & V_19 -> V_96 ) ;
F_71 ( & V_19 -> V_100 ) ;
V_19 -> V_101 = V_101 ;
F_72 ( & V_19 -> V_101 -> V_15 ) ;
V_19 -> V_119 = NULL ;
V_19 -> V_124 = 0 ;
V_89 = F_73 ( L_1 , & V_151 ,
V_19 , V_152 ) ;
if ( F_74 ( V_89 ) )
goto V_153;
F_28 ( & V_101 -> V_6 -> V_123 ) ;
F_55 ( & V_19 -> V_26 ,
& V_101 -> V_6 -> V_154 ) ;
F_30 ( & V_101 -> V_6 -> V_123 ) ;
if ( V_105 ) {
F_75 ( V_101 -> V_27 ) ;
V_101 -> V_27 = V_19 ;
F_72 ( & V_101 -> V_27 -> V_15 ) ;
F_76 ( & V_101 -> V_125 ,
V_84 ,
F_63 ) ;
V_5 = F_77 ( & V_101 -> V_125 ) ;
if ( V_5 )
goto V_155;
V_19 -> V_105 = 1 ;
}
return V_89 ;
V_155:
F_78 ( V_89 ) ;
F_13 ( & V_101 -> V_27 -> V_15 , F_7 ) ;
V_101 -> V_27 = NULL ;
return F_67 ( V_5 ) ;
V_153:
F_13 ( & V_19 -> V_101 -> V_15 , F_35 ) ;
F_13 ( & V_19 -> V_15 , F_7 ) ;
return V_89 ;
}
struct V_16 * F_79 ( int V_117 )
{
struct V_16 * V_19 = NULL ;
struct V_117 V_156 = F_80 ( V_117 ) ;
if ( ! V_156 . V_17 )
return NULL ;
if ( V_156 . V_17 -> V_157 != & V_151 )
goto V_158;
V_19 = V_156 . V_17 -> V_93 ;
if ( V_19 -> V_105 ) {
V_19 = NULL ;
goto V_158;
}
F_72 ( & V_19 -> V_15 ) ;
V_158:
F_81 ( V_156 ) ;
return V_19 ;
}
static int F_82 ( struct V_83 * V_84 , T_7 V_159 )
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
static T_1 F_83 ( struct V_17 * V_89 , const char T_2 * V_90 ,
T_3 V_91 , T_4 * V_92 )
{
struct V_18 * V_17 = V_89 -> V_93 ;
struct V_83 * V_84 ;
struct V_164 V_165 ;
T_7 V_159 ;
T_7 V_126 ;
int V_85 ;
T_1 V_5 ;
if ( F_84 ( ! F_85 ( V_89 ) ) )
return - V_166 ;
if ( V_91 < sizeof V_165 )
return - V_108 ;
if ( F_86 ( & V_165 , V_90 , sizeof V_165 ) )
return - V_111 ;
V_85 = F_36 ( & V_17 -> V_6 -> V_13 ) ;
V_84 = F_37 ( V_17 -> V_6 -> V_84 ,
& V_17 -> V_6 -> V_13 ) ;
if ( ! V_84 ) {
V_5 = - V_103 ;
goto V_158;
}
if ( V_165 . V_159 & ~ ( T_7 ) ( V_167 |
V_168 ) ) {
V_5 = - V_108 ;
goto V_158;
}
V_159 = V_165 . V_159 & V_168 ;
if ( F_82 ( V_84 , V_159 ) ) {
V_5 = - V_169 ;
goto V_158;
}
if ( ! V_17 -> V_170 &&
V_159 != V_171 ) {
V_5 = - V_108 ;
goto V_158;
}
V_126 = ( V_165 . V_159 &
V_167 ) >> V_172 ;
if ( ! V_126 ) {
if ( V_159 >= F_87 ( V_173 ) ||
! V_173 [ V_159 ] ) {
V_5 = - V_108 ;
goto V_158;
}
if ( V_165 . V_174 * 4 != V_91 ) {
V_5 = - V_108 ;
goto V_158;
}
V_5 = V_173 [ V_159 ] ( V_17 , V_84 ,
V_90 + sizeof( V_165 ) ,
V_165 . V_174 * 4 ,
V_165 . V_175 * 4 ) ;
} else if ( V_126 == V_176 ) {
struct V_177 V_178 ;
struct V_179 V_180 ;
struct V_179 V_181 ;
T_3 V_182 = V_91 ;
if ( V_159 >= F_87 ( V_183 ) ||
! V_183 [ V_159 ] ) {
V_5 = - V_184 ;
goto V_158;
}
if ( ! V_17 -> V_170 ) {
V_5 = - V_108 ;
goto V_158;
}
if ( V_91 < ( sizeof( V_165 ) + sizeof( V_178 ) ) ) {
V_5 = - V_108 ;
goto V_158;
}
if ( F_86 ( & V_178 , V_90 + sizeof( V_165 ) , sizeof( V_178 ) ) ) {
V_5 = - V_111 ;
goto V_158;
}
V_91 -= sizeof( V_165 ) + sizeof( V_178 ) ;
V_90 += sizeof( V_165 ) + sizeof( V_178 ) ;
if ( ( V_165 . V_174 + V_178 . V_185 ) * 8 != V_91 ) {
V_5 = - V_108 ;
goto V_158;
}
if ( V_178 . V_186 ) {
V_5 = - V_108 ;
goto V_158;
}
if ( V_178 . V_187 ) {
if ( ! V_165 . V_175 && ! V_178 . V_188 ) {
V_5 = - V_108 ;
goto V_158;
}
if ( ! F_88 ( V_189 ,
( void T_2 * ) ( unsigned long ) V_178 . V_187 ,
( V_165 . V_175 + V_178 . V_188 ) * 8 ) ) {
V_5 = - V_111 ;
goto V_158;
}
} else {
if ( V_165 . V_175 || V_178 . V_188 ) {
V_5 = - V_108 ;
goto V_158;
}
}
F_89 ( & V_180 , V_90 , ( unsigned long ) V_178 . V_187 ,
V_165 . V_174 * 8 , V_165 . V_175 * 8 ) ;
F_89 ( & V_181 ,
V_90 + V_180 . V_190 ,
( unsigned long ) V_178 . V_187 + V_180 . V_191 ,
V_178 . V_185 * 8 ,
V_178 . V_188 * 8 ) ;
V_5 = V_183 [ V_159 ] ( V_17 ,
V_84 ,
& V_180 ,
& V_181 ) ;
if ( ! V_5 )
V_5 = V_182 ;
} else {
V_5 = - V_184 ;
}
V_158:
F_39 ( & V_17 -> V_6 -> V_13 , V_85 ) ;
return V_5 ;
}
static int F_90 ( struct V_17 * V_89 , struct V_192 * V_193 )
{
struct V_18 * V_17 = V_89 -> V_93 ;
struct V_83 * V_84 ;
int V_5 = 0 ;
int V_85 ;
V_85 = F_36 ( & V_17 -> V_6 -> V_13 ) ;
V_84 = F_37 ( V_17 -> V_6 -> V_84 ,
& V_17 -> V_6 -> V_13 ) ;
if ( ! V_84 ) {
V_5 = - V_103 ;
goto V_158;
}
if ( ! V_17 -> V_170 )
V_5 = - V_194 ;
else
V_5 = V_84 -> V_195 ( V_17 -> V_170 , V_193 ) ;
V_158:
F_39 ( & V_17 -> V_6 -> V_13 , V_85 ) ;
return V_5 ;
}
static int F_91 ( struct V_120 * V_120 , struct V_17 * V_89 )
{
struct V_11 * V_12 ;
struct V_18 * V_17 ;
struct V_83 * V_84 ;
int V_5 ;
int V_196 ;
int V_85 ;
V_12 = F_4 ( V_120 -> V_197 , struct V_11 , V_198 ) ;
if ( ! F_92 ( & V_12 -> V_88 ) )
return - V_199 ;
V_85 = F_36 ( & V_12 -> V_13 ) ;
F_28 ( & V_12 -> V_123 ) ;
V_84 = F_37 ( V_12 -> V_84 ,
& V_12 -> V_13 ) ;
if ( ! V_84 ) {
V_5 = - V_103 ;
goto V_200;
}
V_196 = ! ( V_84 -> V_86 ) ;
if ( V_196 ) {
if ( ! F_93 ( V_84 -> V_87 ) ) {
V_5 = - V_194 ;
goto V_200;
}
}
V_17 = F_66 ( sizeof( * V_17 ) , V_149 ) ;
if ( ! V_17 ) {
V_5 = - V_150 ;
if ( V_196 )
goto V_201;
goto V_200;
}
V_17 -> V_6 = V_12 ;
V_17 -> V_170 = NULL ;
V_17 -> V_27 = NULL ;
F_68 ( & V_17 -> V_15 ) ;
F_94 ( & V_17 -> V_202 ) ;
F_94 ( & V_17 -> V_203 ) ;
V_89 -> V_93 = V_17 ;
F_95 ( & V_12 -> V_10 ) ;
F_55 ( & V_17 -> V_26 , & V_12 -> V_204 ) ;
F_30 ( & V_12 -> V_123 ) ;
F_39 ( & V_12 -> V_13 , V_85 ) ;
return F_96 ( V_120 , V_89 ) ;
V_201:
F_38 ( V_84 -> V_87 ) ;
V_200:
F_30 ( & V_12 -> V_123 ) ;
F_39 ( & V_12 -> V_13 , V_85 ) ;
if ( F_40 ( & V_12 -> V_88 ) )
F_33 ( V_12 ) ;
return V_5 ;
}
static int F_97 ( struct V_120 * V_120 , struct V_17 * V_89 )
{
struct V_18 * V_17 = V_89 -> V_93 ;
struct V_11 * V_12 = V_17 -> V_6 ;
F_28 ( & V_17 -> V_203 ) ;
if ( V_17 -> V_170 ) {
F_17 ( V_17 , V_17 -> V_170 ) ;
V_17 -> V_170 = NULL ;
}
F_30 ( & V_17 -> V_203 ) ;
F_28 ( & V_17 -> V_6 -> V_123 ) ;
if ( ! V_17 -> V_124 ) {
F_11 ( & V_17 -> V_26 ) ;
V_17 -> V_124 = 1 ;
}
F_30 ( & V_17 -> V_6 -> V_123 ) ;
if ( V_17 -> V_27 )
F_13 ( & V_17 -> V_27 -> V_15 , F_7 ) ;
F_13 ( & V_17 -> V_15 , F_35 ) ;
F_98 ( & V_12 -> V_10 ) ;
return 0 ;
}
static T_1 F_99 ( struct V_6 * V_6 , struct V_205 * V_206 ,
char * V_90 )
{
int V_5 = - V_194 ;
int V_85 ;
struct V_11 * V_12 = F_100 ( V_6 ) ;
struct V_83 * V_84 ;
if ( ! V_12 )
return - V_194 ;
V_85 = F_36 ( & V_12 -> V_13 ) ;
V_84 = F_37 ( V_12 -> V_84 , & V_12 -> V_13 ) ;
if ( V_84 )
V_5 = sprintf ( V_90 , L_2 , V_84 -> V_207 ) ;
F_39 ( & V_12 -> V_13 , V_85 ) ;
return V_5 ;
}
static T_1 F_101 ( struct V_6 * V_6 ,
struct V_205 * V_206 , char * V_90 )
{
struct V_11 * V_12 = F_100 ( V_6 ) ;
int V_5 = - V_194 ;
int V_85 ;
struct V_83 * V_84 ;
if ( ! V_12 )
return - V_194 ;
V_85 = F_36 ( & V_12 -> V_13 ) ;
V_84 = F_37 ( V_12 -> V_84 , & V_12 -> V_13 ) ;
if ( V_84 )
V_5 = sprintf ( V_90 , L_3 , V_84 -> V_208 ) ;
F_39 ( & V_12 -> V_13 , V_85 ) ;
return V_5 ;
}
static int F_102 ( void )
{
int V_5 ;
if ( ! V_209 ) {
V_5 = F_103 ( & V_209 , 0 , V_210 ,
L_4 ) ;
if ( V_5 ) {
F_104 ( L_5 ) ;
return V_5 ;
}
}
V_5 = F_105 ( V_211 , V_210 ) ;
if ( V_5 >= V_210 )
return - 1 ;
return V_5 ;
}
static void F_106 ( struct V_83 * V_6 )
{
int V_212 ;
T_9 V_213 ;
struct V_11 * V_214 ;
int V_5 ;
if ( ! V_6 -> V_215 )
return;
V_214 = F_66 ( sizeof *V_214 , V_149 ) ;
if ( ! V_214 )
return;
V_5 = F_107 ( & V_214 -> V_13 ) ;
if ( V_5 ) {
F_6 ( V_214 ) ;
return;
}
F_108 ( & V_214 -> V_88 , 1 ) ;
F_109 ( & V_214 -> V_82 ) ;
V_214 -> V_216 = V_217 ;
F_94 ( & V_214 -> V_73 ) ;
F_110 ( & V_214 -> V_10 , & V_218 ) ;
F_94 ( & V_214 -> V_123 ) ;
F_70 ( & V_214 -> V_204 ) ;
F_70 ( & V_214 -> V_154 ) ;
F_111 ( & V_219 ) ;
V_212 = F_105 ( V_220 , V_210 ) ;
if ( V_212 >= V_210 ) {
F_112 ( & V_219 ) ;
V_212 = F_102 () ;
if ( V_212 < 0 )
goto V_200;
F_111 ( & V_219 ) ;
V_214 -> V_212 = V_212 + V_210 ;
V_213 = V_212 + V_209 ;
F_113 ( V_212 , V_211 ) ;
} else {
V_214 -> V_212 = V_212 ;
V_213 = V_212 + V_221 ;
F_113 ( V_212 , V_220 ) ;
}
F_112 ( & V_219 ) ;
F_114 ( V_214 -> V_84 , V_6 ) ;
V_214 -> V_222 = V_6 -> V_222 ;
F_115 ( & V_214 -> V_198 , NULL ) ;
V_214 -> V_198 . V_87 = V_223 ;
V_214 -> V_198 . V_224 = V_6 -> V_195 ? & V_225 : & V_226 ;
V_214 -> V_198 . V_10 . V_227 = & V_214 -> V_10 ;
F_116 ( & V_214 -> V_198 . V_10 , L_6 , V_214 -> V_212 ) ;
if ( F_117 ( & V_214 -> V_198 , V_213 , 1 ) )
goto V_228;
V_214 -> V_12 = F_118 ( V_229 , V_6 -> V_230 ,
V_214 -> V_198 . V_12 , V_214 ,
L_6 , V_214 -> V_212 ) ;
if ( F_74 ( V_214 -> V_12 ) )
goto V_228;
if ( F_119 ( V_214 -> V_12 , & V_231 ) )
goto V_232;
if ( F_119 ( V_214 -> V_12 , & V_233 ) )
goto V_232;
F_120 ( V_6 , & V_234 , V_214 ) ;
return;
V_232:
F_121 ( V_229 , V_214 -> V_198 . V_12 ) ;
V_228:
F_122 ( & V_214 -> V_198 ) ;
if ( V_214 -> V_212 < V_210 )
F_123 ( V_212 , V_220 ) ;
else
F_123 ( V_212 , V_211 ) ;
V_200:
if ( F_40 ( & V_214 -> V_88 ) )
F_33 ( V_214 ) ;
F_124 ( & V_214 -> V_82 ) ;
F_98 ( & V_214 -> V_10 ) ;
return;
}
static void F_125 ( struct V_11 * V_214 ,
struct V_83 * V_84 )
{
struct V_18 * V_17 ;
struct V_16 * V_235 ;
struct V_140 V_94 ;
F_126 ( & V_214 -> V_13 ) ;
V_94 . V_94 = V_236 ;
V_94 . V_135 . V_148 = 0 ;
V_94 . V_6 = V_84 ;
F_28 ( & V_214 -> V_123 ) ;
while ( ! F_42 ( & V_214 -> V_204 ) ) {
struct V_36 * V_170 ;
V_17 = F_127 ( & V_214 -> V_204 ,
struct V_18 , V_26 ) ;
V_17 -> V_124 = 1 ;
F_11 ( & V_17 -> V_26 ) ;
F_72 ( & V_17 -> V_15 ) ;
F_30 ( & V_214 -> V_123 ) ;
F_63 ( & V_17 -> V_125 , & V_94 ) ;
F_28 ( & V_17 -> V_203 ) ;
V_170 = V_17 -> V_170 ;
V_17 -> V_170 = NULL ;
F_30 ( & V_17 -> V_203 ) ;
if ( V_170 ) {
V_84 -> V_86 ( V_170 ) ;
F_17 ( V_17 , V_170 ) ;
}
F_28 ( & V_214 -> V_123 ) ;
F_13 ( & V_17 -> V_15 , F_35 ) ;
}
while ( ! F_42 ( & V_214 -> V_154 ) ) {
V_235 = F_127 ( & V_214 ->
V_154 ,
struct V_16 ,
V_26 ) ;
F_9 ( & V_235 -> V_25 ) ;
V_235 -> V_124 = 1 ;
F_12 ( & V_235 -> V_25 ) ;
F_11 ( & V_235 -> V_26 ) ;
if ( V_235 -> V_105 ) {
F_50 ( & V_235 -> V_101 ->
V_125 ) ;
V_235 -> V_101 -> V_125 . V_6 = NULL ;
}
F_56 ( & V_235 -> V_100 ) ;
F_57 ( & V_235 -> V_119 , V_133 , V_134 ) ;
}
F_30 ( & V_214 -> V_123 ) ;
}
static void F_128 ( struct V_83 * V_6 , void * V_237 )
{
struct V_11 * V_214 = V_237 ;
int V_238 = 1 ;
if ( ! V_214 )
return;
F_129 ( V_214 -> V_12 , NULL ) ;
F_121 ( V_229 , V_214 -> V_198 . V_12 ) ;
F_122 ( & V_214 -> V_198 ) ;
if ( V_214 -> V_212 < V_210 )
F_123 ( V_214 -> V_212 , V_220 ) ;
else
F_123 ( V_214 -> V_212 - V_210 , V_211 ) ;
if ( V_6 -> V_86 ) {
F_114 ( V_214 -> V_84 , NULL ) ;
F_125 ( V_214 , V_6 ) ;
V_238 = 0 ;
}
if ( F_40 ( & V_214 -> V_88 ) )
F_33 ( V_214 ) ;
if ( V_238 )
F_124 ( & V_214 -> V_82 ) ;
F_98 ( & V_214 -> V_10 ) ;
}
static char * F_130 ( struct V_6 * V_12 , T_10 * V_239 )
{
if ( V_239 )
* V_239 = 0666 ;
return F_131 ( V_149 , L_7 , F_132 ( V_12 ) ) ;
}
static int T_11 F_133 ( void )
{
int V_5 ;
V_5 = F_134 ( V_221 , V_210 ,
L_4 ) ;
if ( V_5 ) {
F_104 ( L_8 ) ;
goto V_158;
}
V_229 = F_135 ( V_223 , L_4 ) ;
if ( F_74 ( V_229 ) ) {
V_5 = F_136 ( V_229 ) ;
F_104 ( L_9 ) ;
goto V_240;
}
V_229 -> V_241 = F_130 ;
V_5 = F_137 ( V_229 , & V_242 . V_206 ) ;
if ( V_5 ) {
F_104 ( L_10 ) ;
goto V_243;
}
V_5 = F_138 ( & V_234 ) ;
if ( V_5 ) {
F_104 ( L_11 ) ;
goto V_243;
}
return 0 ;
V_243:
F_139 ( V_229 ) ;
V_240:
F_140 ( V_221 , V_210 ) ;
V_158:
return V_5 ;
}
static void T_12 F_141 ( void )
{
F_142 ( & V_234 ) ;
F_139 ( V_229 ) ;
F_140 ( V_221 , V_210 ) ;
if ( V_209 )
F_140 ( V_209 , V_210 ) ;
F_143 ( & V_79 ) ;
F_143 ( & V_72 ) ;
F_143 ( & V_44 ) ;
F_143 ( & V_43 ) ;
F_143 ( & V_69 ) ;
F_143 ( & V_51 ) ;
F_143 ( & V_64 ) ;
}
