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
F_20 ( & V_21 -> V_44 , V_37 -> V_6 ,
V_45 ) ;
F_6 ( V_21 ) ;
}
F_10 (uobj, tmp, &context->mw_list, list) {
struct V_1 * V_2 = V_21 -> V_42 ;
F_18 ( & V_46 , V_21 ) ;
F_1 ( V_2 ) ;
F_20 ( & V_21 -> V_44 , V_37 -> V_6 ,
V_45 ) ;
F_6 ( V_21 ) ;
}
F_10 (uobj, tmp, &context->rule_list, list) {
struct V_47 * V_48 = V_21 -> V_42 ;
F_18 ( & V_49 , V_21 ) ;
F_21 ( V_48 ) ;
F_20 ( & V_21 -> V_44 , V_37 -> V_6 ,
V_45 ) ;
F_6 ( V_21 ) ;
}
F_10 (uobj, tmp, &context->qp_list, list) {
struct V_29 * V_30 = V_21 -> V_42 ;
struct V_31 * V_50 =
F_4 ( V_21 , struct V_31 , V_51 . V_52 ) ;
F_18 ( & V_53 , V_21 ) ;
if ( V_30 == V_30 -> V_54 )
F_15 ( V_30 , V_50 ) ;
F_22 ( V_30 ) ;
F_20 ( & V_21 -> V_44 , V_37 -> V_6 ,
V_45 ) ;
F_14 ( V_17 , & V_50 -> V_51 ) ;
F_6 ( V_50 ) ;
}
F_10 (uobj, tmp, &context->rwq_ind_tbl_list, list) {
struct V_55 * V_56 = V_21 -> V_42 ;
struct V_57 * * V_58 = V_56 -> V_58 ;
F_18 ( & V_59 , V_21 ) ;
F_23 ( V_56 ) ;
F_6 ( V_58 ) ;
F_6 ( V_21 ) ;
}
F_10 (uobj, tmp, &context->wq_list, list) {
struct V_57 * V_60 = V_21 -> V_42 ;
struct V_61 * V_62 =
F_4 ( V_21 , struct V_61 , V_51 . V_52 ) ;
F_18 ( & V_63 , V_21 ) ;
F_24 ( V_60 ) ;
F_14 ( V_17 , & V_62 -> V_51 ) ;
F_6 ( V_62 ) ;
}
F_10 (uobj, tmp, &context->srq_list, list) {
struct V_64 * V_65 = V_21 -> V_42 ;
struct V_28 * V_51 =
F_4 ( V_21 , struct V_28 , V_52 ) ;
F_18 ( & V_66 , V_21 ) ;
F_25 ( V_65 ) ;
F_20 ( & V_21 -> V_44 , V_37 -> V_6 ,
V_45 ) ;
F_14 ( V_17 , V_51 ) ;
F_6 ( V_51 ) ;
}
F_10 (uobj, tmp, &context->cq_list, list) {
struct V_67 * V_68 = V_21 -> V_42 ;
struct V_16 * V_19 = V_68 -> V_69 ;
struct V_20 * V_70 =
F_4 ( V_21 , struct V_20 , V_52 ) ;
F_18 ( & V_71 , V_21 ) ;
F_26 ( V_68 ) ;
F_20 ( & V_21 -> V_44 , V_37 -> V_6 ,
V_45 ) ;
F_8 ( V_17 , V_19 , V_70 ) ;
F_6 ( V_70 ) ;
}
F_10 (uobj, tmp, &context->mr_list, list) {
struct V_72 * V_73 = V_21 -> V_42 ;
F_18 ( & V_74 , V_21 ) ;
F_27 ( V_73 ) ;
F_20 ( & V_21 -> V_44 , V_37 -> V_6 ,
V_45 ) ;
F_6 ( V_21 ) ;
}
F_28 ( & V_17 -> V_6 -> V_75 ) ;
F_10 (uobj, tmp, &context->xrcd_list, list) {
struct V_76 * V_77 = V_21 -> V_42 ;
struct V_78 * V_79 =
F_4 ( V_21 , struct V_78 , V_52 ) ;
F_18 ( & V_80 , V_21 ) ;
F_29 ( V_17 -> V_6 , V_77 ) ;
F_6 ( V_79 ) ;
}
F_30 ( & V_17 -> V_6 -> V_75 ) ;
F_10 (uobj, tmp, &context->pd_list, list) {
struct V_3 * V_4 = V_21 -> V_42 ;
F_18 ( & V_81 , V_21 ) ;
F_31 ( V_4 ) ;
F_20 ( & V_21 -> V_44 , V_37 -> V_6 ,
V_45 ) ;
F_6 ( V_21 ) ;
}
F_32 ( V_37 -> V_82 ) ;
F_20 ( & V_37 -> V_44 , V_37 -> V_6 ,
V_83 ) ;
return V_37 -> V_6 -> V_84 ( V_37 ) ;
}
static void F_33 ( struct V_11 * V_12 )
{
F_34 ( & V_12 -> V_85 ) ;
}
static void F_35 ( struct V_14 * V_15 )
{
struct V_18 * V_17 =
F_4 ( V_15 , struct V_18 , V_15 ) ;
struct V_86 * V_87 ;
int V_88 ;
V_88 = F_36 ( & V_17 -> V_6 -> V_13 ) ;
V_87 = F_37 ( V_17 -> V_6 -> V_87 ,
& V_17 -> V_6 -> V_13 ) ;
if ( V_87 && ! V_87 -> V_89 )
F_38 ( V_87 -> V_90 ) ;
F_39 ( & V_17 -> V_6 -> V_13 , V_88 ) ;
if ( F_40 ( & V_17 -> V_6 -> V_91 ) )
F_33 ( V_17 -> V_6 ) ;
F_6 ( V_17 ) ;
}
static T_1 F_41 ( struct V_17 * V_92 , char T_2 * V_93 ,
T_3 V_94 , T_4 * V_95 )
{
struct V_16 * V_17 = V_92 -> V_96 ;
struct V_22 * V_97 ;
int V_98 ;
int V_5 = 0 ;
F_9 ( & V_17 -> V_25 ) ;
while ( F_42 ( & V_17 -> V_99 ) ) {
F_12 ( & V_17 -> V_25 ) ;
if ( V_92 -> V_100 & V_101 )
return - V_102 ;
if ( F_43 ( V_17 -> V_103 ,
( ! F_42 ( & V_17 -> V_99 ) ||
! V_17 -> V_104 -> V_6 -> V_87 ) ) )
return - V_105 ;
if ( F_42 ( & V_17 -> V_99 ) &&
! V_17 -> V_104 -> V_6 -> V_87 )
return - V_106 ;
F_9 ( & V_17 -> V_25 ) ;
}
V_97 = F_44 ( V_17 -> V_99 . V_107 , struct V_22 , V_26 ) ;
if ( V_17 -> V_108 )
V_98 = sizeof ( struct V_109 ) ;
else
V_98 = sizeof ( struct V_110 ) ;
if ( V_98 > V_94 ) {
V_5 = - V_111 ;
V_97 = NULL ;
} else {
F_11 ( V_17 -> V_99 . V_107 ) ;
if ( V_97 -> V_112 ) {
++ ( * V_97 -> V_112 ) ;
F_11 ( & V_97 -> V_113 ) ;
}
}
F_12 ( & V_17 -> V_25 ) ;
if ( V_97 ) {
if ( F_45 ( V_93 , V_97 , V_98 ) )
V_5 = - V_114 ;
else
V_5 = V_98 ;
}
F_6 ( V_97 ) ;
return V_5 ;
}
static unsigned int F_46 ( struct V_17 * V_92 ,
struct V_115 * V_116 )
{
unsigned int V_117 = 0 ;
struct V_16 * V_17 = V_92 -> V_96 ;
V_103 ( V_92 , & V_17 -> V_103 , V_116 ) ;
F_9 ( & V_17 -> V_25 ) ;
if ( ! F_42 ( & V_17 -> V_99 ) )
V_117 = V_118 | V_119 ;
F_12 ( & V_17 -> V_25 ) ;
return V_117 ;
}
static int F_47 ( int V_120 , struct V_17 * V_92 , int V_121 )
{
struct V_16 * V_17 = V_92 -> V_96 ;
return F_48 ( V_120 , V_92 , V_121 , & V_17 -> V_122 ) ;
}
static int F_49 ( struct V_123 * V_123 , struct V_17 * V_92 )
{
struct V_16 * V_17 = V_92 -> V_96 ;
struct V_22 * V_124 , * V_24 ;
int V_125 = 0 ;
F_28 ( & V_17 -> V_104 -> V_6 -> V_126 ) ;
F_9 ( & V_17 -> V_25 ) ;
V_125 = V_17 -> V_127 ;
V_17 -> V_127 = 1 ;
F_10 (entry, tmp, &file->event_list, list) {
if ( V_124 -> V_112 )
F_11 ( & V_124 -> V_113 ) ;
F_6 ( V_124 ) ;
}
F_12 ( & V_17 -> V_25 ) ;
if ( ! V_125 ) {
F_11 ( & V_17 -> V_26 ) ;
if ( V_17 -> V_108 )
F_50 ( & V_17 -> V_104 ->
V_128 ) ;
}
F_30 ( & V_17 -> V_104 -> V_6 -> V_126 ) ;
F_13 ( & V_17 -> V_104 -> V_15 , F_35 ) ;
F_13 ( & V_17 -> V_15 , F_7 ) ;
return 0 ;
}
void F_51 ( struct V_67 * V_68 , void * V_69 )
{
struct V_16 * V_17 = V_69 ;
struct V_20 * V_21 ;
struct V_22 * V_124 ;
unsigned long V_129 ;
if ( ! V_17 )
return;
F_52 ( & V_17 -> V_25 , V_129 ) ;
if ( V_17 -> V_127 ) {
F_53 ( & V_17 -> V_25 , V_129 ) ;
return;
}
V_124 = F_54 ( sizeof *V_124 , V_130 ) ;
if ( ! V_124 ) {
F_53 ( & V_17 -> V_25 , V_129 ) ;
return;
}
V_21 = F_4 ( V_68 -> V_52 , struct V_20 , V_52 ) ;
V_124 -> V_131 . V_85 . V_132 = V_68 -> V_52 -> V_133 ;
V_124 -> V_112 = & V_21 -> V_134 ;
F_55 ( & V_124 -> V_26 , & V_17 -> V_99 ) ;
F_55 ( & V_124 -> V_113 , & V_21 -> V_135 ) ;
F_53 ( & V_17 -> V_25 , V_129 ) ;
F_56 ( & V_17 -> V_103 ) ;
F_57 ( & V_17 -> V_122 , V_136 , V_137 ) ;
}
static void F_58 ( struct V_18 * V_17 ,
T_5 V_138 , T_5 V_97 ,
struct V_139 * V_113 ,
T_6 * V_112 )
{
struct V_22 * V_124 ;
unsigned long V_129 ;
F_52 ( & V_17 -> V_27 -> V_25 , V_129 ) ;
if ( V_17 -> V_27 -> V_127 ) {
F_53 ( & V_17 -> V_27 -> V_25 , V_129 ) ;
return;
}
V_124 = F_54 ( sizeof *V_124 , V_130 ) ;
if ( ! V_124 ) {
F_53 ( & V_17 -> V_27 -> V_25 , V_129 ) ;
return;
}
V_124 -> V_131 . V_140 . V_138 = V_138 ;
V_124 -> V_131 . V_140 . V_141 = V_97 ;
V_124 -> V_131 . V_140 . V_142 = 0 ;
V_124 -> V_112 = V_112 ;
F_55 ( & V_124 -> V_26 , & V_17 -> V_27 -> V_99 ) ;
if ( V_113 )
F_55 ( & V_124 -> V_113 , V_113 ) ;
F_53 ( & V_17 -> V_27 -> V_25 , V_129 ) ;
F_56 ( & V_17 -> V_27 -> V_103 ) ;
F_57 ( & V_17 -> V_27 -> V_122 , V_136 , V_137 ) ;
}
void F_59 ( struct V_143 * V_97 , void * V_144 )
{
struct V_20 * V_21 = F_4 ( V_97 -> V_138 . V_68 -> V_52 ,
struct V_20 , V_52 ) ;
F_58 ( V_21 -> V_104 , V_21 -> V_52 . V_133 ,
V_97 -> V_97 , & V_21 -> V_145 ,
& V_21 -> V_146 ) ;
}
void F_60 ( struct V_143 * V_97 , void * V_144 )
{
struct V_28 * V_21 ;
if ( ! V_97 -> V_138 . V_30 -> V_52 || ! V_97 -> V_138 . V_30 -> V_52 -> V_147 )
return;
V_21 = F_4 ( V_97 -> V_138 . V_30 -> V_52 ,
struct V_28 , V_52 ) ;
F_58 ( V_144 , V_21 -> V_52 . V_133 ,
V_97 -> V_97 , & V_21 -> V_99 ,
& V_21 -> V_148 ) ;
}
void F_61 ( struct V_143 * V_97 , void * V_144 )
{
struct V_28 * V_21 = F_4 ( V_97 -> V_138 . V_60 -> V_52 ,
struct V_28 , V_52 ) ;
F_58 ( V_144 , V_21 -> V_52 . V_133 ,
V_97 -> V_97 , & V_21 -> V_99 ,
& V_21 -> V_148 ) ;
}
void F_62 ( struct V_143 * V_97 , void * V_144 )
{
struct V_28 * V_21 ;
V_21 = F_4 ( V_97 -> V_138 . V_65 -> V_52 ,
struct V_28 , V_52 ) ;
F_58 ( V_144 , V_21 -> V_52 . V_133 ,
V_97 -> V_97 , & V_21 -> V_99 ,
& V_21 -> V_148 ) ;
}
void F_63 ( struct V_149 * V_150 ,
struct V_143 * V_97 )
{
struct V_18 * V_17 =
F_4 ( V_150 , struct V_18 , V_128 ) ;
F_58 ( V_17 , V_97 -> V_138 . V_151 , V_97 -> V_97 ,
NULL , NULL ) ;
}
void F_64 ( struct V_18 * V_17 )
{
F_13 ( & V_17 -> V_27 -> V_15 , F_7 ) ;
V_17 -> V_27 = NULL ;
}
struct V_17 * F_65 ( struct V_18 * V_104 ,
struct V_86 * V_87 ,
int V_108 )
{
struct V_16 * V_19 ;
struct V_17 * V_92 ;
int V_5 ;
V_19 = F_66 ( sizeof( * V_19 ) , V_152 ) ;
if ( ! V_19 )
return F_67 ( - V_153 ) ;
F_68 ( & V_19 -> V_15 ) ;
F_69 ( & V_19 -> V_25 ) ;
F_70 ( & V_19 -> V_99 ) ;
F_71 ( & V_19 -> V_103 ) ;
V_19 -> V_104 = V_104 ;
F_72 ( & V_19 -> V_104 -> V_15 ) ;
V_19 -> V_122 = NULL ;
V_19 -> V_127 = 0 ;
V_92 = F_73 ( L_1 , & V_154 ,
V_19 , V_155 ) ;
if ( F_74 ( V_92 ) )
goto V_156;
F_28 ( & V_104 -> V_6 -> V_126 ) ;
F_55 ( & V_19 -> V_26 ,
& V_104 -> V_6 -> V_157 ) ;
F_30 ( & V_104 -> V_6 -> V_126 ) ;
if ( V_108 ) {
F_75 ( V_104 -> V_27 ) ;
V_104 -> V_27 = V_19 ;
F_72 ( & V_104 -> V_27 -> V_15 ) ;
F_76 ( & V_104 -> V_128 ,
V_87 ,
F_63 ) ;
V_5 = F_77 ( & V_104 -> V_128 ) ;
if ( V_5 )
goto V_158;
V_19 -> V_108 = 1 ;
}
return V_92 ;
V_158:
F_78 ( V_92 ) ;
F_13 ( & V_104 -> V_27 -> V_15 , F_7 ) ;
V_104 -> V_27 = NULL ;
return F_67 ( V_5 ) ;
V_156:
F_13 ( & V_19 -> V_104 -> V_15 , F_35 ) ;
F_13 ( & V_19 -> V_15 , F_7 ) ;
return V_92 ;
}
struct V_16 * F_79 ( int V_120 )
{
struct V_16 * V_19 = NULL ;
struct V_120 V_159 = F_80 ( V_120 ) ;
if ( ! V_159 . V_17 )
return NULL ;
if ( V_159 . V_17 -> V_160 != & V_154 )
goto V_161;
V_19 = V_159 . V_17 -> V_96 ;
if ( V_19 -> V_108 ) {
V_19 = NULL ;
goto V_161;
}
F_72 ( & V_19 -> V_15 ) ;
V_161:
F_81 ( V_159 ) ;
return V_19 ;
}
static int F_82 ( struct V_86 * V_87 , T_7 V_162 )
{
T_8 V_163 ;
if ( V_162 <= V_164 )
V_163 = V_87 -> V_165 ;
else
V_163 = V_87 -> V_166 ;
if ( V_163 & ( ( T_8 ) 1 << V_162 ) )
return 0 ;
return - 1 ;
}
static T_1 F_83 ( struct V_17 * V_92 , const char T_2 * V_93 ,
T_3 V_94 , T_4 * V_95 )
{
struct V_18 * V_17 = V_92 -> V_96 ;
struct V_86 * V_87 ;
struct V_167 V_168 ;
T_7 V_162 ;
T_7 V_129 ;
int V_88 ;
T_1 V_5 ;
if ( ! F_84 ( V_92 ) ) {
F_85 ( L_2 ,
F_86 ( V_169 ) , V_169 -> V_170 ) ;
return - V_171 ;
}
if ( V_94 < sizeof V_168 )
return - V_111 ;
if ( F_87 ( & V_168 , V_93 , sizeof V_168 ) )
return - V_114 ;
V_88 = F_36 ( & V_17 -> V_6 -> V_13 ) ;
V_87 = F_37 ( V_17 -> V_6 -> V_87 ,
& V_17 -> V_6 -> V_13 ) ;
if ( ! V_87 ) {
V_5 = - V_106 ;
goto V_161;
}
if ( V_168 . V_162 & ~ ( T_7 ) ( V_172 |
V_173 ) ) {
V_5 = - V_111 ;
goto V_161;
}
V_162 = V_168 . V_162 & V_173 ;
if ( F_82 ( V_87 , V_162 ) ) {
V_5 = - V_174 ;
goto V_161;
}
if ( ! V_17 -> V_175 &&
V_162 != V_176 ) {
V_5 = - V_111 ;
goto V_161;
}
V_129 = ( V_168 . V_162 &
V_172 ) >> V_177 ;
if ( ! V_129 ) {
if ( V_162 >= F_88 ( V_178 ) ||
! V_178 [ V_162 ] ) {
V_5 = - V_111 ;
goto V_161;
}
if ( V_168 . V_179 * 4 != V_94 ) {
V_5 = - V_111 ;
goto V_161;
}
V_5 = V_178 [ V_162 ] ( V_17 , V_87 ,
V_93 + sizeof( V_168 ) ,
V_168 . V_179 * 4 ,
V_168 . V_180 * 4 ) ;
} else if ( V_129 == V_181 ) {
struct V_182 V_183 ;
struct V_184 V_185 ;
struct V_184 V_186 ;
T_3 V_187 = V_94 ;
if ( V_162 >= F_88 ( V_188 ) ||
! V_188 [ V_162 ] ) {
V_5 = - V_189 ;
goto V_161;
}
if ( ! V_17 -> V_175 ) {
V_5 = - V_111 ;
goto V_161;
}
if ( V_94 < ( sizeof( V_168 ) + sizeof( V_183 ) ) ) {
V_5 = - V_111 ;
goto V_161;
}
if ( F_87 ( & V_183 , V_93 + sizeof( V_168 ) , sizeof( V_183 ) ) ) {
V_5 = - V_114 ;
goto V_161;
}
V_94 -= sizeof( V_168 ) + sizeof( V_183 ) ;
V_93 += sizeof( V_168 ) + sizeof( V_183 ) ;
if ( ( V_168 . V_179 + V_183 . V_190 ) * 8 != V_94 ) {
V_5 = - V_111 ;
goto V_161;
}
if ( V_183 . V_191 ) {
V_5 = - V_111 ;
goto V_161;
}
if ( V_183 . V_192 ) {
if ( ! V_168 . V_180 && ! V_183 . V_193 ) {
V_5 = - V_111 ;
goto V_161;
}
if ( ! F_89 ( V_194 ,
( void T_2 * ) ( unsigned long ) V_183 . V_192 ,
( V_168 . V_180 + V_183 . V_193 ) * 8 ) ) {
V_5 = - V_114 ;
goto V_161;
}
} else {
if ( V_168 . V_180 || V_183 . V_193 ) {
V_5 = - V_111 ;
goto V_161;
}
}
F_90 ( & V_185 , V_93 , ( unsigned long ) V_183 . V_192 ,
V_168 . V_179 * 8 , V_168 . V_180 * 8 ) ;
F_90 ( & V_186 ,
V_93 + V_185 . V_195 ,
( unsigned long ) V_183 . V_192 + V_185 . V_196 ,
V_183 . V_190 * 8 ,
V_183 . V_193 * 8 ) ;
V_5 = V_188 [ V_162 ] ( V_17 ,
V_87 ,
& V_185 ,
& V_186 ) ;
if ( ! V_5 )
V_5 = V_187 ;
} else {
V_5 = - V_189 ;
}
V_161:
F_39 ( & V_17 -> V_6 -> V_13 , V_88 ) ;
return V_5 ;
}
static int F_91 ( struct V_17 * V_92 , struct V_197 * V_198 )
{
struct V_18 * V_17 = V_92 -> V_96 ;
struct V_86 * V_87 ;
int V_5 = 0 ;
int V_88 ;
V_88 = F_36 ( & V_17 -> V_6 -> V_13 ) ;
V_87 = F_37 ( V_17 -> V_6 -> V_87 ,
& V_17 -> V_6 -> V_13 ) ;
if ( ! V_87 ) {
V_5 = - V_106 ;
goto V_161;
}
if ( ! V_17 -> V_175 )
V_5 = - V_199 ;
else
V_5 = V_87 -> V_200 ( V_17 -> V_175 , V_198 ) ;
V_161:
F_39 ( & V_17 -> V_6 -> V_13 , V_88 ) ;
return V_5 ;
}
static int F_92 ( struct V_123 * V_123 , struct V_17 * V_92 )
{
struct V_11 * V_12 ;
struct V_18 * V_17 ;
struct V_86 * V_87 ;
int V_5 ;
int V_201 ;
int V_88 ;
V_12 = F_4 ( V_123 -> V_202 , struct V_11 , V_203 ) ;
if ( ! F_93 ( & V_12 -> V_91 ) )
return - V_204 ;
V_88 = F_36 ( & V_12 -> V_13 ) ;
F_28 ( & V_12 -> V_126 ) ;
V_87 = F_37 ( V_12 -> V_87 ,
& V_12 -> V_13 ) ;
if ( ! V_87 ) {
V_5 = - V_106 ;
goto V_205;
}
V_201 = ! ( V_87 -> V_89 ) ;
if ( V_201 ) {
if ( ! F_94 ( V_87 -> V_90 ) ) {
V_5 = - V_199 ;
goto V_205;
}
}
V_17 = F_66 ( sizeof( * V_17 ) , V_152 ) ;
if ( ! V_17 ) {
V_5 = - V_153 ;
if ( V_201 )
goto V_206;
goto V_205;
}
V_17 -> V_6 = V_12 ;
V_17 -> V_175 = NULL ;
V_17 -> V_27 = NULL ;
F_68 ( & V_17 -> V_15 ) ;
F_95 ( & V_17 -> V_207 ) ;
F_95 ( & V_17 -> V_208 ) ;
V_92 -> V_96 = V_17 ;
F_96 ( & V_12 -> V_10 ) ;
F_55 ( & V_17 -> V_26 , & V_12 -> V_209 ) ;
F_30 ( & V_12 -> V_126 ) ;
F_39 ( & V_12 -> V_13 , V_88 ) ;
return F_97 ( V_123 , V_92 ) ;
V_206:
F_38 ( V_87 -> V_90 ) ;
V_205:
F_30 ( & V_12 -> V_126 ) ;
F_39 ( & V_12 -> V_13 , V_88 ) ;
if ( F_40 ( & V_12 -> V_91 ) )
F_33 ( V_12 ) ;
return V_5 ;
}
static int F_98 ( struct V_123 * V_123 , struct V_17 * V_92 )
{
struct V_18 * V_17 = V_92 -> V_96 ;
struct V_11 * V_12 = V_17 -> V_6 ;
F_28 ( & V_17 -> V_208 ) ;
if ( V_17 -> V_175 ) {
F_17 ( V_17 , V_17 -> V_175 ) ;
V_17 -> V_175 = NULL ;
}
F_30 ( & V_17 -> V_208 ) ;
F_28 ( & V_17 -> V_6 -> V_126 ) ;
if ( ! V_17 -> V_127 ) {
F_11 ( & V_17 -> V_26 ) ;
V_17 -> V_127 = 1 ;
}
F_30 ( & V_17 -> V_6 -> V_126 ) ;
if ( V_17 -> V_27 )
F_13 ( & V_17 -> V_27 -> V_15 , F_7 ) ;
F_13 ( & V_17 -> V_15 , F_35 ) ;
F_99 ( & V_12 -> V_10 ) ;
return 0 ;
}
static T_1 F_100 ( struct V_6 * V_6 , struct V_210 * V_211 ,
char * V_93 )
{
int V_5 = - V_199 ;
int V_88 ;
struct V_11 * V_12 = F_101 ( V_6 ) ;
struct V_86 * V_87 ;
if ( ! V_12 )
return - V_199 ;
V_88 = F_36 ( & V_12 -> V_13 ) ;
V_87 = F_37 ( V_12 -> V_87 , & V_12 -> V_13 ) ;
if ( V_87 )
V_5 = sprintf ( V_93 , L_3 , V_87 -> V_212 ) ;
F_39 ( & V_12 -> V_13 , V_88 ) ;
return V_5 ;
}
static T_1 F_102 ( struct V_6 * V_6 ,
struct V_210 * V_211 , char * V_93 )
{
struct V_11 * V_12 = F_101 ( V_6 ) ;
int V_5 = - V_199 ;
int V_88 ;
struct V_86 * V_87 ;
if ( ! V_12 )
return - V_199 ;
V_88 = F_36 ( & V_12 -> V_13 ) ;
V_87 = F_37 ( V_12 -> V_87 , & V_12 -> V_13 ) ;
if ( V_87 )
V_5 = sprintf ( V_93 , L_4 , V_87 -> V_213 ) ;
F_39 ( & V_12 -> V_13 , V_88 ) ;
return V_5 ;
}
static int F_103 ( void )
{
int V_5 ;
if ( ! V_214 ) {
V_5 = F_104 ( & V_214 , 0 , V_215 ,
L_5 ) ;
if ( V_5 ) {
F_105 ( L_6 ) ;
return V_5 ;
}
}
V_5 = F_106 ( V_216 , V_215 ) ;
if ( V_5 >= V_215 )
return - 1 ;
return V_5 ;
}
static void F_107 ( struct V_86 * V_6 )
{
int V_217 ;
T_9 V_218 ;
struct V_11 * V_219 ;
int V_5 ;
if ( ! V_6 -> V_220 )
return;
V_219 = F_66 ( sizeof *V_219 , V_152 ) ;
if ( ! V_219 )
return;
V_5 = F_108 ( & V_219 -> V_13 ) ;
if ( V_5 ) {
F_6 ( V_219 ) ;
return;
}
F_109 ( & V_219 -> V_91 , 1 ) ;
F_110 ( & V_219 -> V_85 ) ;
V_219 -> V_221 = V_222 ;
F_95 ( & V_219 -> V_75 ) ;
F_111 ( & V_219 -> V_10 , & V_223 ) ;
F_95 ( & V_219 -> V_126 ) ;
F_70 ( & V_219 -> V_209 ) ;
F_70 ( & V_219 -> V_157 ) ;
F_112 ( & V_224 ) ;
V_217 = F_106 ( V_225 , V_215 ) ;
if ( V_217 >= V_215 ) {
F_113 ( & V_224 ) ;
V_217 = F_103 () ;
if ( V_217 < 0 )
goto V_205;
F_112 ( & V_224 ) ;
V_219 -> V_217 = V_217 + V_215 ;
V_218 = V_217 + V_214 ;
F_114 ( V_217 , V_216 ) ;
} else {
V_219 -> V_217 = V_217 ;
V_218 = V_217 + V_226 ;
F_114 ( V_217 , V_225 ) ;
}
F_113 ( & V_224 ) ;
F_115 ( V_219 -> V_87 , V_6 ) ;
V_219 -> V_227 = V_6 -> V_227 ;
F_116 ( & V_219 -> V_203 , NULL ) ;
V_219 -> V_203 . V_90 = V_228 ;
V_219 -> V_203 . V_229 = V_6 -> V_200 ? & V_230 : & V_231 ;
V_219 -> V_203 . V_10 . V_232 = & V_219 -> V_10 ;
F_117 ( & V_219 -> V_203 . V_10 , L_7 , V_219 -> V_217 ) ;
if ( F_118 ( & V_219 -> V_203 , V_218 , 1 ) )
goto V_233;
V_219 -> V_12 = F_119 ( V_234 , V_6 -> V_12 . V_232 ,
V_219 -> V_203 . V_12 , V_219 ,
L_7 , V_219 -> V_217 ) ;
if ( F_74 ( V_219 -> V_12 ) )
goto V_233;
if ( F_120 ( V_219 -> V_12 , & V_235 ) )
goto V_236;
if ( F_120 ( V_219 -> V_12 , & V_237 ) )
goto V_236;
F_121 ( V_6 , & V_238 , V_219 ) ;
return;
V_236:
F_122 ( V_234 , V_219 -> V_203 . V_12 ) ;
V_233:
F_123 ( & V_219 -> V_203 ) ;
if ( V_219 -> V_217 < V_215 )
F_124 ( V_217 , V_225 ) ;
else
F_124 ( V_217 , V_216 ) ;
V_205:
if ( F_40 ( & V_219 -> V_91 ) )
F_33 ( V_219 ) ;
F_125 ( & V_219 -> V_85 ) ;
F_99 ( & V_219 -> V_10 ) ;
return;
}
static void F_126 ( struct V_11 * V_219 ,
struct V_86 * V_87 )
{
struct V_18 * V_17 ;
struct V_16 * V_239 ;
struct V_143 V_97 ;
F_127 ( & V_219 -> V_13 ) ;
V_97 . V_97 = V_240 ;
V_97 . V_138 . V_151 = 0 ;
V_97 . V_6 = V_87 ;
F_28 ( & V_219 -> V_126 ) ;
while ( ! F_42 ( & V_219 -> V_209 ) ) {
struct V_36 * V_175 ;
V_17 = F_128 ( & V_219 -> V_209 ,
struct V_18 , V_26 ) ;
V_17 -> V_127 = 1 ;
F_11 ( & V_17 -> V_26 ) ;
F_72 ( & V_17 -> V_15 ) ;
F_30 ( & V_219 -> V_126 ) ;
F_63 ( & V_17 -> V_128 , & V_97 ) ;
F_28 ( & V_17 -> V_208 ) ;
V_175 = V_17 -> V_175 ;
V_17 -> V_175 = NULL ;
F_30 ( & V_17 -> V_208 ) ;
if ( V_175 ) {
V_87 -> V_89 ( V_175 ) ;
F_17 ( V_17 , V_175 ) ;
}
F_28 ( & V_219 -> V_126 ) ;
F_13 ( & V_17 -> V_15 , F_35 ) ;
}
while ( ! F_42 ( & V_219 -> V_157 ) ) {
V_239 = F_128 ( & V_219 ->
V_157 ,
struct V_16 ,
V_26 ) ;
F_9 ( & V_239 -> V_25 ) ;
V_239 -> V_127 = 1 ;
F_12 ( & V_239 -> V_25 ) ;
F_11 ( & V_239 -> V_26 ) ;
if ( V_239 -> V_108 ) {
F_50 ( & V_239 -> V_104 ->
V_128 ) ;
V_239 -> V_104 -> V_128 . V_6 = NULL ;
}
F_56 ( & V_239 -> V_103 ) ;
F_57 ( & V_239 -> V_122 , V_136 , V_137 ) ;
}
F_30 ( & V_219 -> V_126 ) ;
}
static void F_129 ( struct V_86 * V_6 , void * V_241 )
{
struct V_11 * V_219 = V_241 ;
int V_242 = 1 ;
if ( ! V_219 )
return;
F_130 ( V_219 -> V_12 , NULL ) ;
F_122 ( V_234 , V_219 -> V_203 . V_12 ) ;
F_123 ( & V_219 -> V_203 ) ;
if ( V_219 -> V_217 < V_215 )
F_124 ( V_219 -> V_217 , V_225 ) ;
else
F_124 ( V_219 -> V_217 - V_215 , V_216 ) ;
if ( V_6 -> V_89 ) {
F_115 ( V_219 -> V_87 , NULL ) ;
F_126 ( V_219 , V_6 ) ;
V_242 = 0 ;
}
if ( F_40 ( & V_219 -> V_91 ) )
F_33 ( V_219 ) ;
if ( V_242 )
F_125 ( & V_219 -> V_85 ) ;
F_99 ( & V_219 -> V_10 ) ;
}
static char * F_131 ( struct V_6 * V_12 , T_10 * V_243 )
{
if ( V_243 )
* V_243 = 0666 ;
return F_132 ( V_152 , L_8 , F_133 ( V_12 ) ) ;
}
static int T_11 F_134 ( void )
{
int V_5 ;
V_5 = F_135 ( V_226 , V_215 ,
L_5 ) ;
if ( V_5 ) {
F_105 ( L_9 ) ;
goto V_161;
}
V_234 = F_136 ( V_228 , L_5 ) ;
if ( F_74 ( V_234 ) ) {
V_5 = F_137 ( V_234 ) ;
F_105 ( L_10 ) ;
goto V_244;
}
V_234 -> V_245 = F_131 ;
V_5 = F_138 ( V_234 , & V_246 . V_211 ) ;
if ( V_5 ) {
F_105 ( L_11 ) ;
goto V_247;
}
V_5 = F_139 ( & V_238 ) ;
if ( V_5 ) {
F_105 ( L_12 ) ;
goto V_247;
}
return 0 ;
V_247:
F_140 ( V_234 ) ;
V_244:
F_141 ( V_226 , V_215 ) ;
V_161:
return V_5 ;
}
static void T_12 F_142 ( void )
{
F_143 ( & V_238 ) ;
F_140 ( V_234 ) ;
F_141 ( V_226 , V_215 ) ;
if ( V_214 )
F_141 ( V_214 , V_215 ) ;
F_144 ( & V_81 ) ;
F_144 ( & V_74 ) ;
F_144 ( & V_46 ) ;
F_144 ( & V_43 ) ;
F_144 ( & V_71 ) ;
F_144 ( & V_53 ) ;
F_144 ( & V_66 ) ;
}
