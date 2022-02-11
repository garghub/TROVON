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
F_10 (uobj, tmp, &context->srq_list, list) {
struct V_53 * V_54 = V_21 -> V_42 ;
struct V_28 * V_49 =
F_4 ( V_21 , struct V_28 , V_50 ) ;
F_18 ( & V_55 , V_21 ) ;
F_23 ( V_54 ) ;
F_14 ( V_17 , V_49 ) ;
F_6 ( V_49 ) ;
}
F_10 (uobj, tmp, &context->cq_list, list) {
struct V_56 * V_57 = V_21 -> V_42 ;
struct V_16 * V_19 = V_57 -> V_58 ;
struct V_20 * V_59 =
F_4 ( V_21 , struct V_20 , V_50 ) ;
F_18 ( & V_60 , V_21 ) ;
F_24 ( V_57 ) ;
F_8 ( V_17 , V_19 , V_59 ) ;
F_6 ( V_59 ) ;
}
F_10 (uobj, tmp, &context->mr_list, list) {
struct V_61 * V_62 = V_21 -> V_42 ;
F_18 ( & V_63 , V_21 ) ;
F_25 ( V_62 ) ;
F_6 ( V_21 ) ;
}
F_26 ( & V_17 -> V_6 -> V_64 ) ;
F_10 (uobj, tmp, &context->xrcd_list, list) {
struct V_65 * V_66 = V_21 -> V_42 ;
struct V_67 * V_68 =
F_4 ( V_21 , struct V_67 , V_50 ) ;
F_18 ( & V_69 , V_21 ) ;
F_27 ( V_17 -> V_6 , V_66 ) ;
F_6 ( V_68 ) ;
}
F_28 ( & V_17 -> V_6 -> V_64 ) ;
F_10 (uobj, tmp, &context->pd_list, list) {
struct V_3 * V_4 = V_21 -> V_42 ;
F_18 ( & V_70 , V_21 ) ;
F_29 ( V_4 ) ;
F_6 ( V_21 ) ;
}
F_30 ( V_37 -> V_71 ) ;
return V_37 -> V_6 -> V_72 ( V_37 ) ;
}
static void F_31 ( struct V_11 * V_12 )
{
F_32 ( & V_12 -> V_73 ) ;
}
static void F_33 ( struct V_14 * V_15 )
{
struct V_18 * V_17 =
F_4 ( V_15 , struct V_18 , V_15 ) ;
struct V_74 * V_75 ;
int V_76 ;
V_76 = F_34 ( & V_17 -> V_6 -> V_13 ) ;
V_75 = F_35 ( V_17 -> V_6 -> V_75 ,
& V_17 -> V_6 -> V_13 ) ;
if ( V_75 && ! V_75 -> V_77 )
F_36 ( V_75 -> V_78 ) ;
F_37 ( & V_17 -> V_6 -> V_13 , V_76 ) ;
if ( F_38 ( & V_17 -> V_6 -> V_79 ) )
F_31 ( V_17 -> V_6 ) ;
F_6 ( V_17 ) ;
}
static T_1 F_39 ( struct V_17 * V_80 , char T_2 * V_81 ,
T_3 V_82 , T_4 * V_83 )
{
struct V_16 * V_17 = V_80 -> V_84 ;
struct V_22 * V_85 ;
int V_86 ;
int V_5 = 0 ;
F_9 ( & V_17 -> V_25 ) ;
while ( F_40 ( & V_17 -> V_87 ) ) {
F_12 ( & V_17 -> V_25 ) ;
if ( V_80 -> V_88 & V_89 )
return - V_90 ;
if ( F_41 ( V_17 -> V_91 ,
( ! F_40 ( & V_17 -> V_87 ) ||
! V_17 -> V_92 -> V_6 -> V_75 ) ) )
return - V_93 ;
if ( F_40 ( & V_17 -> V_87 ) &&
! V_17 -> V_92 -> V_6 -> V_75 )
return - V_94 ;
F_9 ( & V_17 -> V_25 ) ;
}
V_85 = F_42 ( V_17 -> V_87 . V_95 , struct V_22 , V_26 ) ;
if ( V_17 -> V_96 )
V_86 = sizeof ( struct V_97 ) ;
else
V_86 = sizeof ( struct V_98 ) ;
if ( V_86 > V_82 ) {
V_5 = - V_99 ;
V_85 = NULL ;
} else {
F_11 ( V_17 -> V_87 . V_95 ) ;
if ( V_85 -> V_100 ) {
++ ( * V_85 -> V_100 ) ;
F_11 ( & V_85 -> V_101 ) ;
}
}
F_12 ( & V_17 -> V_25 ) ;
if ( V_85 ) {
if ( F_43 ( V_81 , V_85 , V_86 ) )
V_5 = - V_102 ;
else
V_5 = V_86 ;
}
F_6 ( V_85 ) ;
return V_5 ;
}
static unsigned int F_44 ( struct V_17 * V_80 ,
struct V_103 * V_104 )
{
unsigned int V_105 = 0 ;
struct V_16 * V_17 = V_80 -> V_84 ;
V_91 ( V_80 , & V_17 -> V_91 , V_104 ) ;
F_9 ( & V_17 -> V_25 ) ;
if ( ! F_40 ( & V_17 -> V_87 ) )
V_105 = V_106 | V_107 ;
F_12 ( & V_17 -> V_25 ) ;
return V_105 ;
}
static int F_45 ( int V_108 , struct V_17 * V_80 , int V_109 )
{
struct V_16 * V_17 = V_80 -> V_84 ;
return F_46 ( V_108 , V_80 , V_109 , & V_17 -> V_110 ) ;
}
static int F_47 ( struct V_111 * V_111 , struct V_17 * V_80 )
{
struct V_16 * V_17 = V_80 -> V_84 ;
struct V_22 * V_112 , * V_24 ;
int V_113 = 0 ;
F_26 ( & V_17 -> V_92 -> V_6 -> V_114 ) ;
F_9 ( & V_17 -> V_25 ) ;
V_113 = V_17 -> V_115 ;
V_17 -> V_115 = 1 ;
F_10 (entry, tmp, &file->event_list, list) {
if ( V_112 -> V_100 )
F_11 ( & V_112 -> V_101 ) ;
F_6 ( V_112 ) ;
}
F_12 ( & V_17 -> V_25 ) ;
if ( ! V_113 ) {
F_11 ( & V_17 -> V_26 ) ;
if ( V_17 -> V_96 )
F_48 ( & V_17 -> V_92 ->
V_116 ) ;
}
F_28 ( & V_17 -> V_92 -> V_6 -> V_114 ) ;
F_13 ( & V_17 -> V_92 -> V_15 , F_33 ) ;
F_13 ( & V_17 -> V_15 , F_7 ) ;
return 0 ;
}
void F_49 ( struct V_56 * V_57 , void * V_58 )
{
struct V_16 * V_17 = V_58 ;
struct V_20 * V_21 ;
struct V_22 * V_112 ;
unsigned long V_117 ;
if ( ! V_17 )
return;
F_50 ( & V_17 -> V_25 , V_117 ) ;
if ( V_17 -> V_115 ) {
F_51 ( & V_17 -> V_25 , V_117 ) ;
return;
}
V_112 = F_52 ( sizeof *V_112 , V_118 ) ;
if ( ! V_112 ) {
F_51 ( & V_17 -> V_25 , V_117 ) ;
return;
}
V_21 = F_4 ( V_57 -> V_50 , struct V_20 , V_50 ) ;
V_112 -> V_119 . V_73 . V_120 = V_57 -> V_50 -> V_121 ;
V_112 -> V_100 = & V_21 -> V_122 ;
F_53 ( & V_112 -> V_26 , & V_17 -> V_87 ) ;
F_53 ( & V_112 -> V_101 , & V_21 -> V_123 ) ;
F_51 ( & V_17 -> V_25 , V_117 ) ;
F_54 ( & V_17 -> V_91 ) ;
F_55 ( & V_17 -> V_110 , V_124 , V_125 ) ;
}
static void F_56 ( struct V_18 * V_17 ,
T_5 V_126 , T_5 V_85 ,
struct V_127 * V_101 ,
T_6 * V_100 )
{
struct V_22 * V_112 ;
unsigned long V_117 ;
F_50 ( & V_17 -> V_27 -> V_25 , V_117 ) ;
if ( V_17 -> V_27 -> V_115 ) {
F_51 ( & V_17 -> V_27 -> V_25 , V_117 ) ;
return;
}
V_112 = F_52 ( sizeof *V_112 , V_118 ) ;
if ( ! V_112 ) {
F_51 ( & V_17 -> V_27 -> V_25 , V_117 ) ;
return;
}
V_112 -> V_119 . V_128 . V_126 = V_126 ;
V_112 -> V_119 . V_128 . V_129 = V_85 ;
V_112 -> V_119 . V_128 . V_130 = 0 ;
V_112 -> V_100 = V_100 ;
F_53 ( & V_112 -> V_26 , & V_17 -> V_27 -> V_87 ) ;
if ( V_101 )
F_53 ( & V_112 -> V_101 , V_101 ) ;
F_51 ( & V_17 -> V_27 -> V_25 , V_117 ) ;
F_54 ( & V_17 -> V_27 -> V_91 ) ;
F_55 ( & V_17 -> V_27 -> V_110 , V_124 , V_125 ) ;
}
void F_57 ( struct V_131 * V_85 , void * V_132 )
{
struct V_20 * V_21 = F_4 ( V_85 -> V_126 . V_57 -> V_50 ,
struct V_20 , V_50 ) ;
F_56 ( V_21 -> V_92 , V_21 -> V_50 . V_121 ,
V_85 -> V_85 , & V_21 -> V_133 ,
& V_21 -> V_134 ) ;
}
void F_58 ( struct V_131 * V_85 , void * V_132 )
{
struct V_28 * V_21 ;
if ( ! V_85 -> V_126 . V_30 -> V_50 || ! V_85 -> V_126 . V_30 -> V_50 -> V_135 )
return;
V_21 = F_4 ( V_85 -> V_126 . V_30 -> V_50 ,
struct V_28 , V_50 ) ;
F_56 ( V_132 , V_21 -> V_50 . V_121 ,
V_85 -> V_85 , & V_21 -> V_87 ,
& V_21 -> V_136 ) ;
}
void F_59 ( struct V_131 * V_85 , void * V_132 )
{
struct V_28 * V_21 ;
V_21 = F_4 ( V_85 -> V_126 . V_54 -> V_50 ,
struct V_28 , V_50 ) ;
F_56 ( V_132 , V_21 -> V_50 . V_121 ,
V_85 -> V_85 , & V_21 -> V_87 ,
& V_21 -> V_136 ) ;
}
void F_60 ( struct V_137 * V_138 ,
struct V_131 * V_85 )
{
struct V_18 * V_17 =
F_4 ( V_138 , struct V_18 , V_116 ) ;
F_56 ( V_17 , V_85 -> V_126 . V_139 , V_85 -> V_85 ,
NULL , NULL ) ;
}
void F_61 ( struct V_18 * V_17 )
{
F_13 ( & V_17 -> V_27 -> V_15 , F_7 ) ;
V_17 -> V_27 = NULL ;
}
struct V_17 * F_62 ( struct V_18 * V_92 ,
struct V_74 * V_75 ,
int V_96 )
{
struct V_16 * V_19 ;
struct V_17 * V_80 ;
int V_5 ;
V_19 = F_63 ( sizeof( * V_19 ) , V_140 ) ;
if ( ! V_19 )
return F_64 ( - V_141 ) ;
F_65 ( & V_19 -> V_15 ) ;
F_66 ( & V_19 -> V_25 ) ;
F_67 ( & V_19 -> V_87 ) ;
F_68 ( & V_19 -> V_91 ) ;
V_19 -> V_92 = V_92 ;
F_69 ( & V_19 -> V_92 -> V_15 ) ;
V_19 -> V_110 = NULL ;
V_19 -> V_115 = 0 ;
V_80 = F_70 ( L_1 , & V_142 ,
V_19 , V_143 ) ;
if ( F_71 ( V_80 ) )
goto V_144;
F_26 ( & V_92 -> V_6 -> V_114 ) ;
F_53 ( & V_19 -> V_26 ,
& V_92 -> V_6 -> V_145 ) ;
F_28 ( & V_92 -> V_6 -> V_114 ) ;
if ( V_96 ) {
F_72 ( V_92 -> V_27 ) ;
V_92 -> V_27 = V_19 ;
F_69 ( & V_92 -> V_27 -> V_15 ) ;
F_73 ( & V_92 -> V_116 ,
V_75 ,
F_60 ) ;
V_5 = F_74 ( & V_92 -> V_116 ) ;
if ( V_5 )
goto V_146;
V_19 -> V_96 = 1 ;
}
return V_80 ;
V_146:
F_75 ( V_80 ) ;
F_13 ( & V_92 -> V_27 -> V_15 , F_7 ) ;
V_92 -> V_27 = NULL ;
return F_64 ( V_5 ) ;
V_144:
F_13 ( & V_19 -> V_92 -> V_15 , F_33 ) ;
F_13 ( & V_19 -> V_15 , F_7 ) ;
return V_80 ;
}
struct V_16 * F_76 ( int V_108 )
{
struct V_16 * V_19 = NULL ;
struct V_108 V_147 = F_77 ( V_108 ) ;
if ( ! V_147 . V_17 )
return NULL ;
if ( V_147 . V_17 -> V_148 != & V_142 )
goto V_149;
V_19 = V_147 . V_17 -> V_84 ;
if ( V_19 -> V_96 ) {
V_19 = NULL ;
goto V_149;
}
F_69 ( & V_19 -> V_15 ) ;
V_149:
F_78 ( V_147 ) ;
return V_19 ;
}
static int F_79 ( struct V_74 * V_75 , T_7 V_150 )
{
T_8 V_151 ;
if ( V_150 <= V_152 )
V_151 = V_75 -> V_153 ;
else
V_151 = V_75 -> V_154 ;
if ( V_151 & ( ( T_8 ) 1 << V_150 ) )
return 0 ;
return - 1 ;
}
static T_1 F_80 ( struct V_17 * V_80 , const char T_2 * V_81 ,
T_3 V_82 , T_4 * V_83 )
{
struct V_18 * V_17 = V_80 -> V_84 ;
struct V_74 * V_75 ;
struct V_155 V_156 ;
T_7 V_150 ;
T_7 V_117 ;
int V_76 ;
T_1 V_5 ;
if ( F_81 ( ! F_82 ( V_80 ) ) )
return - V_157 ;
if ( V_82 < sizeof V_156 )
return - V_99 ;
if ( F_83 ( & V_156 , V_81 , sizeof V_156 ) )
return - V_102 ;
V_76 = F_34 ( & V_17 -> V_6 -> V_13 ) ;
V_75 = F_35 ( V_17 -> V_6 -> V_75 ,
& V_17 -> V_6 -> V_13 ) ;
if ( ! V_75 ) {
V_5 = - V_94 ;
goto V_149;
}
if ( V_156 . V_150 & ~ ( T_7 ) ( V_158 |
V_159 ) ) {
V_5 = - V_99 ;
goto V_149;
}
V_150 = V_156 . V_150 & V_159 ;
if ( F_79 ( V_75 , V_150 ) ) {
V_5 = - V_160 ;
goto V_149;
}
if ( ! V_17 -> V_161 &&
V_150 != V_162 ) {
V_5 = - V_99 ;
goto V_149;
}
V_117 = ( V_156 . V_150 &
V_158 ) >> V_163 ;
if ( ! V_117 ) {
if ( V_150 >= F_84 ( V_164 ) ||
! V_164 [ V_150 ] ) {
V_5 = - V_99 ;
goto V_149;
}
if ( V_156 . V_165 * 4 != V_82 ) {
V_5 = - V_99 ;
goto V_149;
}
V_5 = V_164 [ V_150 ] ( V_17 , V_75 ,
V_81 + sizeof( V_156 ) ,
V_156 . V_165 * 4 ,
V_156 . V_166 * 4 ) ;
} else if ( V_117 == V_167 ) {
struct V_168 V_169 ;
struct V_170 V_171 ;
struct V_170 V_172 ;
T_3 V_173 = V_82 ;
if ( V_150 >= F_84 ( V_174 ) ||
! V_174 [ V_150 ] ) {
V_5 = - V_175 ;
goto V_149;
}
if ( ! V_17 -> V_161 ) {
V_5 = - V_99 ;
goto V_149;
}
if ( V_82 < ( sizeof( V_156 ) + sizeof( V_169 ) ) ) {
V_5 = - V_99 ;
goto V_149;
}
if ( F_83 ( & V_169 , V_81 + sizeof( V_156 ) , sizeof( V_169 ) ) ) {
V_5 = - V_102 ;
goto V_149;
}
V_82 -= sizeof( V_156 ) + sizeof( V_169 ) ;
V_81 += sizeof( V_156 ) + sizeof( V_169 ) ;
if ( ( V_156 . V_165 + V_169 . V_176 ) * 8 != V_82 ) {
V_5 = - V_99 ;
goto V_149;
}
if ( V_169 . V_177 ) {
V_5 = - V_99 ;
goto V_149;
}
if ( V_169 . V_178 ) {
if ( ! V_156 . V_166 && ! V_169 . V_179 ) {
V_5 = - V_99 ;
goto V_149;
}
if ( ! F_85 ( V_180 ,
( void T_2 * ) ( unsigned long ) V_169 . V_178 ,
( V_156 . V_166 + V_169 . V_179 ) * 8 ) ) {
V_5 = - V_102 ;
goto V_149;
}
} else {
if ( V_156 . V_166 || V_169 . V_179 ) {
V_5 = - V_99 ;
goto V_149;
}
}
F_86 ( & V_171 , V_81 , ( unsigned long ) V_169 . V_178 ,
V_156 . V_165 * 8 , V_156 . V_166 * 8 ) ;
F_86 ( & V_172 ,
V_81 + V_171 . V_181 ,
( unsigned long ) V_169 . V_178 + V_171 . V_182 ,
V_169 . V_176 * 8 ,
V_169 . V_179 * 8 ) ;
V_5 = V_174 [ V_150 ] ( V_17 ,
V_75 ,
& V_171 ,
& V_172 ) ;
if ( ! V_5 )
V_5 = V_173 ;
} else {
V_5 = - V_175 ;
}
V_149:
F_37 ( & V_17 -> V_6 -> V_13 , V_76 ) ;
return V_5 ;
}
static int F_87 ( struct V_17 * V_80 , struct V_183 * V_184 )
{
struct V_18 * V_17 = V_80 -> V_84 ;
struct V_74 * V_75 ;
int V_5 = 0 ;
int V_76 ;
V_76 = F_34 ( & V_17 -> V_6 -> V_13 ) ;
V_75 = F_35 ( V_17 -> V_6 -> V_75 ,
& V_17 -> V_6 -> V_13 ) ;
if ( ! V_75 ) {
V_5 = - V_94 ;
goto V_149;
}
if ( ! V_17 -> V_161 )
V_5 = - V_185 ;
else
V_5 = V_75 -> V_186 ( V_17 -> V_161 , V_184 ) ;
V_149:
F_37 ( & V_17 -> V_6 -> V_13 , V_76 ) ;
return V_5 ;
}
static int F_88 ( struct V_111 * V_111 , struct V_17 * V_80 )
{
struct V_11 * V_12 ;
struct V_18 * V_17 ;
struct V_74 * V_75 ;
int V_5 ;
int V_187 ;
int V_76 ;
V_12 = F_4 ( V_111 -> V_188 , struct V_11 , V_189 ) ;
if ( ! F_89 ( & V_12 -> V_79 ) )
return - V_190 ;
V_76 = F_34 ( & V_12 -> V_13 ) ;
F_26 ( & V_12 -> V_114 ) ;
V_75 = F_35 ( V_12 -> V_75 ,
& V_12 -> V_13 ) ;
if ( ! V_75 ) {
V_5 = - V_94 ;
goto V_191;
}
V_187 = ! ( V_75 -> V_77 ) ;
if ( V_187 ) {
if ( ! F_90 ( V_75 -> V_78 ) ) {
V_5 = - V_185 ;
goto V_191;
}
}
V_17 = F_63 ( sizeof( * V_17 ) , V_140 ) ;
if ( ! V_17 ) {
V_5 = - V_141 ;
if ( V_187 )
goto V_192;
goto V_191;
}
V_17 -> V_6 = V_12 ;
V_17 -> V_161 = NULL ;
V_17 -> V_27 = NULL ;
F_65 ( & V_17 -> V_15 ) ;
F_91 ( & V_17 -> V_193 ) ;
V_80 -> V_84 = V_17 ;
F_92 ( & V_12 -> V_10 ) ;
F_53 ( & V_17 -> V_26 , & V_12 -> V_194 ) ;
F_28 ( & V_12 -> V_114 ) ;
F_37 ( & V_12 -> V_13 , V_76 ) ;
return F_93 ( V_111 , V_80 ) ;
V_192:
F_36 ( V_75 -> V_78 ) ;
V_191:
F_28 ( & V_12 -> V_114 ) ;
F_37 ( & V_12 -> V_13 , V_76 ) ;
if ( F_38 ( & V_12 -> V_79 ) )
F_31 ( V_12 ) ;
return V_5 ;
}
static int F_94 ( struct V_111 * V_111 , struct V_17 * V_80 )
{
struct V_18 * V_17 = V_80 -> V_84 ;
struct V_11 * V_12 = V_17 -> V_6 ;
struct V_36 * V_161 = NULL ;
F_26 ( & V_17 -> V_6 -> V_114 ) ;
V_161 = V_17 -> V_161 ;
V_17 -> V_161 = NULL ;
if ( ! V_17 -> V_115 ) {
F_11 ( & V_17 -> V_26 ) ;
V_17 -> V_115 = 1 ;
}
F_28 ( & V_17 -> V_6 -> V_114 ) ;
if ( V_161 )
F_17 ( V_17 , V_161 ) ;
if ( V_17 -> V_27 )
F_13 ( & V_17 -> V_27 -> V_15 , F_7 ) ;
F_13 ( & V_17 -> V_15 , F_33 ) ;
F_95 ( & V_12 -> V_10 ) ;
return 0 ;
}
static T_1 F_96 ( struct V_6 * V_6 , struct V_195 * V_196 ,
char * V_81 )
{
int V_5 = - V_185 ;
int V_76 ;
struct V_11 * V_12 = F_97 ( V_6 ) ;
struct V_74 * V_75 ;
if ( ! V_12 )
return - V_185 ;
V_76 = F_34 ( & V_12 -> V_13 ) ;
V_75 = F_35 ( V_12 -> V_75 , & V_12 -> V_13 ) ;
if ( V_75 )
V_5 = sprintf ( V_81 , L_2 , V_75 -> V_197 ) ;
F_37 ( & V_12 -> V_13 , V_76 ) ;
return V_5 ;
}
static T_1 F_98 ( struct V_6 * V_6 ,
struct V_195 * V_196 , char * V_81 )
{
struct V_11 * V_12 = F_97 ( V_6 ) ;
int V_5 = - V_185 ;
int V_76 ;
struct V_74 * V_75 ;
if ( ! V_12 )
return - V_185 ;
V_76 = F_34 ( & V_12 -> V_13 ) ;
V_75 = F_35 ( V_12 -> V_75 , & V_12 -> V_13 ) ;
if ( V_75 )
V_5 = sprintf ( V_81 , L_3 , V_75 -> V_198 ) ;
F_37 ( & V_12 -> V_13 , V_76 ) ;
return V_5 ;
}
static int F_99 ( void )
{
int V_5 ;
if ( ! V_199 ) {
V_5 = F_100 ( & V_199 , 0 , V_200 ,
L_4 ) ;
if ( V_5 ) {
F_101 ( L_5 ) ;
return V_5 ;
}
}
V_5 = F_102 ( V_201 , V_200 ) ;
if ( V_5 >= V_200 )
return - 1 ;
return V_5 ;
}
static void F_103 ( struct V_74 * V_6 )
{
int V_202 ;
T_9 V_203 ;
struct V_11 * V_204 ;
int V_5 ;
if ( ! V_6 -> V_205 )
return;
V_204 = F_63 ( sizeof *V_204 , V_140 ) ;
if ( ! V_204 )
return;
V_5 = F_104 ( & V_204 -> V_13 ) ;
if ( V_5 ) {
F_6 ( V_204 ) ;
return;
}
F_105 ( & V_204 -> V_79 , 1 ) ;
F_106 ( & V_204 -> V_73 ) ;
V_204 -> V_206 = V_207 ;
F_91 ( & V_204 -> V_64 ) ;
F_107 ( & V_204 -> V_10 , & V_208 ) ;
F_91 ( & V_204 -> V_114 ) ;
F_67 ( & V_204 -> V_194 ) ;
F_67 ( & V_204 -> V_145 ) ;
F_108 ( & V_209 ) ;
V_202 = F_102 ( V_210 , V_200 ) ;
if ( V_202 >= V_200 ) {
F_109 ( & V_209 ) ;
V_202 = F_99 () ;
if ( V_202 < 0 )
goto V_191;
F_108 ( & V_209 ) ;
V_204 -> V_202 = V_202 + V_200 ;
V_203 = V_202 + V_199 ;
F_110 ( V_202 , V_201 ) ;
} else {
V_204 -> V_202 = V_202 ;
V_203 = V_202 + V_211 ;
F_110 ( V_202 , V_210 ) ;
}
F_109 ( & V_209 ) ;
F_111 ( V_204 -> V_75 , V_6 ) ;
V_204 -> V_212 = V_6 -> V_212 ;
F_112 ( & V_204 -> V_189 , NULL ) ;
V_204 -> V_189 . V_78 = V_213 ;
V_204 -> V_189 . V_214 = V_6 -> V_186 ? & V_215 : & V_216 ;
V_204 -> V_189 . V_10 . V_217 = & V_204 -> V_10 ;
F_113 ( & V_204 -> V_189 . V_10 , L_6 , V_204 -> V_202 ) ;
if ( F_114 ( & V_204 -> V_189 , V_203 , 1 ) )
goto V_218;
V_204 -> V_12 = F_115 ( V_219 , V_6 -> V_220 ,
V_204 -> V_189 . V_12 , V_204 ,
L_6 , V_204 -> V_202 ) ;
if ( F_71 ( V_204 -> V_12 ) )
goto V_218;
if ( F_116 ( V_204 -> V_12 , & V_221 ) )
goto V_222;
if ( F_116 ( V_204 -> V_12 , & V_223 ) )
goto V_222;
F_117 ( V_6 , & V_224 , V_204 ) ;
return;
V_222:
F_118 ( V_219 , V_204 -> V_189 . V_12 ) ;
V_218:
F_119 ( & V_204 -> V_189 ) ;
if ( V_204 -> V_202 < V_200 )
F_120 ( V_202 , V_210 ) ;
else
F_120 ( V_202 , V_201 ) ;
V_191:
if ( F_38 ( & V_204 -> V_79 ) )
F_31 ( V_204 ) ;
F_121 ( & V_204 -> V_73 ) ;
F_95 ( & V_204 -> V_10 ) ;
return;
}
static void F_122 ( struct V_11 * V_204 ,
struct V_74 * V_75 )
{
struct V_18 * V_17 ;
struct V_16 * V_225 ;
struct V_131 V_85 ;
F_123 ( & V_204 -> V_13 ) ;
V_85 . V_85 = V_226 ;
V_85 . V_126 . V_139 = 0 ;
V_85 . V_6 = V_75 ;
F_26 ( & V_204 -> V_114 ) ;
while ( ! F_40 ( & V_204 -> V_194 ) ) {
struct V_36 * V_161 ;
V_17 = F_124 ( & V_204 -> V_194 ,
struct V_18 , V_26 ) ;
V_17 -> V_115 = 1 ;
V_161 = V_17 -> V_161 ;
F_11 ( & V_17 -> V_26 ) ;
V_17 -> V_161 = NULL ;
F_69 ( & V_17 -> V_15 ) ;
F_28 ( & V_204 -> V_114 ) ;
F_60 ( & V_17 -> V_116 , & V_85 ) ;
if ( V_161 ) {
V_75 -> V_77 ( V_161 ) ;
F_17 ( V_17 , V_161 ) ;
}
F_26 ( & V_204 -> V_114 ) ;
F_13 ( & V_17 -> V_15 , F_33 ) ;
}
while ( ! F_40 ( & V_204 -> V_145 ) ) {
V_225 = F_124 ( & V_204 ->
V_145 ,
struct V_16 ,
V_26 ) ;
F_9 ( & V_225 -> V_25 ) ;
V_225 -> V_115 = 1 ;
F_12 ( & V_225 -> V_25 ) ;
F_11 ( & V_225 -> V_26 ) ;
if ( V_225 -> V_96 ) {
F_48 ( & V_225 -> V_92 ->
V_116 ) ;
V_225 -> V_92 -> V_116 . V_6 = NULL ;
}
F_54 ( & V_225 -> V_91 ) ;
F_55 ( & V_225 -> V_110 , V_124 , V_125 ) ;
}
F_28 ( & V_204 -> V_114 ) ;
}
static void F_125 ( struct V_74 * V_6 , void * V_227 )
{
struct V_11 * V_204 = V_227 ;
int V_228 = 1 ;
if ( ! V_204 )
return;
F_126 ( V_204 -> V_12 , NULL ) ;
F_118 ( V_219 , V_204 -> V_189 . V_12 ) ;
F_119 ( & V_204 -> V_189 ) ;
if ( V_204 -> V_202 < V_200 )
F_120 ( V_204 -> V_202 , V_210 ) ;
else
F_120 ( V_204 -> V_202 - V_200 , V_201 ) ;
if ( V_6 -> V_77 ) {
F_111 ( V_204 -> V_75 , NULL ) ;
F_122 ( V_204 , V_6 ) ;
V_228 = 0 ;
}
if ( F_38 ( & V_204 -> V_79 ) )
F_31 ( V_204 ) ;
if ( V_228 )
F_121 ( & V_204 -> V_73 ) ;
F_95 ( & V_204 -> V_10 ) ;
}
static char * F_127 ( struct V_6 * V_12 , T_10 * V_229 )
{
if ( V_229 )
* V_229 = 0666 ;
return F_128 ( V_140 , L_7 , F_129 ( V_12 ) ) ;
}
static int T_11 F_130 ( void )
{
int V_5 ;
V_5 = F_131 ( V_211 , V_200 ,
L_4 ) ;
if ( V_5 ) {
F_101 ( L_8 ) ;
goto V_149;
}
V_219 = F_132 ( V_213 , L_4 ) ;
if ( F_71 ( V_219 ) ) {
V_5 = F_133 ( V_219 ) ;
F_101 ( L_9 ) ;
goto V_230;
}
V_219 -> V_231 = F_127 ;
V_5 = F_134 ( V_219 , & V_232 . V_196 ) ;
if ( V_5 ) {
F_101 ( L_10 ) ;
goto V_233;
}
V_5 = F_135 ( & V_224 ) ;
if ( V_5 ) {
F_101 ( L_11 ) ;
goto V_233;
}
return 0 ;
V_233:
F_136 ( V_219 ) ;
V_230:
F_137 ( V_211 , V_200 ) ;
V_149:
return V_5 ;
}
static void T_12 F_138 ( void )
{
F_139 ( & V_224 ) ;
F_136 ( V_219 ) ;
F_137 ( V_211 , V_200 ) ;
if ( V_199 )
F_137 ( V_199 , V_200 ) ;
F_140 ( & V_70 ) ;
F_140 ( & V_63 ) ;
F_140 ( & V_44 ) ;
F_140 ( & V_43 ) ;
F_140 ( & V_60 ) ;
F_140 ( & V_51 ) ;
F_140 ( & V_55 ) ;
}
