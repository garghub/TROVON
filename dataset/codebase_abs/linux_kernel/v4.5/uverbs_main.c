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
static T_1 F_79 ( struct V_17 * V_80 , const char T_2 * V_81 ,
T_3 V_82 , T_4 * V_83 )
{
struct V_18 * V_17 = V_80 -> V_84 ;
struct V_74 * V_75 ;
struct V_150 V_151 ;
T_7 V_117 ;
int V_76 ;
T_1 V_5 ;
if ( V_82 < sizeof V_151 )
return - V_99 ;
if ( F_80 ( & V_151 , V_81 , sizeof V_151 ) )
return - V_102 ;
V_76 = F_34 ( & V_17 -> V_6 -> V_13 ) ;
V_75 = F_35 ( V_17 -> V_6 -> V_75 ,
& V_17 -> V_6 -> V_13 ) ;
if ( ! V_75 ) {
V_5 = - V_94 ;
goto V_149;
}
V_117 = ( V_151 . V_152 &
V_153 ) >> V_154 ;
if ( ! V_117 ) {
T_7 V_152 ;
if ( V_151 . V_152 & ~ ( T_7 ) ( V_153 |
V_155 ) ) {
V_5 = - V_99 ;
goto V_149;
}
V_152 = V_151 . V_152 & V_155 ;
if ( V_152 >= F_81 ( V_156 ) ||
! V_156 [ V_152 ] ) {
V_5 = - V_99 ;
goto V_149;
}
if ( ! V_17 -> V_157 &&
V_152 != V_158 ) {
V_5 = - V_99 ;
goto V_149;
}
if ( ! ( V_75 -> V_159 & ( 1ull << V_152 ) ) ) {
V_5 = - V_160 ;
goto V_149;
}
if ( V_151 . V_161 * 4 != V_82 ) {
V_5 = - V_99 ;
goto V_149;
}
V_5 = V_156 [ V_152 ] ( V_17 , V_75 ,
V_81 + sizeof( V_151 ) ,
V_151 . V_161 * 4 ,
V_151 . V_162 * 4 ) ;
} else if ( V_117 == V_163 ) {
T_7 V_152 ;
struct V_164 V_165 ;
struct V_166 V_167 ;
struct V_166 V_168 ;
T_3 V_169 = V_82 ;
if ( V_151 . V_152 & ~ ( T_7 ) ( V_153 |
V_155 ) ) {
V_5 = - V_99 ;
goto V_149;
}
V_152 = V_151 . V_152 & V_155 ;
if ( V_152 >= F_81 ( V_170 ) ||
! V_170 [ V_152 ] ) {
V_5 = - V_160 ;
goto V_149;
}
if ( ! V_17 -> V_157 ) {
V_5 = - V_99 ;
goto V_149;
}
if ( ! ( V_75 -> V_171 & ( 1ull << V_152 ) ) ) {
V_5 = - V_160 ;
goto V_149;
}
if ( V_82 < ( sizeof( V_151 ) + sizeof( V_165 ) ) ) {
V_5 = - V_99 ;
goto V_149;
}
if ( F_80 ( & V_165 , V_81 + sizeof( V_151 ) , sizeof( V_165 ) ) ) {
V_5 = - V_102 ;
goto V_149;
}
V_82 -= sizeof( V_151 ) + sizeof( V_165 ) ;
V_81 += sizeof( V_151 ) + sizeof( V_165 ) ;
if ( ( V_151 . V_161 + V_165 . V_172 ) * 8 != V_82 ) {
V_5 = - V_99 ;
goto V_149;
}
if ( V_165 . V_173 ) {
V_5 = - V_99 ;
goto V_149;
}
if ( V_165 . V_174 ) {
if ( ! V_151 . V_162 && ! V_165 . V_175 ) {
V_5 = - V_99 ;
goto V_149;
}
if ( ! F_82 ( V_176 ,
( void T_2 * ) ( unsigned long ) V_165 . V_174 ,
( V_151 . V_162 + V_165 . V_175 ) * 8 ) ) {
V_5 = - V_102 ;
goto V_149;
}
} else {
if ( V_151 . V_162 || V_165 . V_175 ) {
V_5 = - V_99 ;
goto V_149;
}
}
F_83 ( & V_167 , V_81 , ( unsigned long ) V_165 . V_174 ,
V_151 . V_161 * 8 , V_151 . V_162 * 8 ) ;
F_83 ( & V_168 ,
V_81 + V_167 . V_177 ,
( unsigned long ) V_165 . V_174 + V_167 . V_178 ,
V_165 . V_172 * 8 ,
V_165 . V_175 * 8 ) ;
V_5 = V_170 [ V_152 ] ( V_17 ,
V_75 ,
& V_167 ,
& V_168 ) ;
if ( ! V_5 )
V_5 = V_169 ;
} else {
V_5 = - V_160 ;
}
V_149:
F_37 ( & V_17 -> V_6 -> V_13 , V_76 ) ;
return V_5 ;
}
static int F_84 ( struct V_17 * V_80 , struct V_179 * V_180 )
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
if ( ! V_17 -> V_157 )
V_5 = - V_181 ;
else
V_5 = V_75 -> V_182 ( V_17 -> V_157 , V_180 ) ;
V_149:
F_37 ( & V_17 -> V_6 -> V_13 , V_76 ) ;
return V_5 ;
}
static int F_85 ( struct V_111 * V_111 , struct V_17 * V_80 )
{
struct V_11 * V_12 ;
struct V_18 * V_17 ;
struct V_74 * V_75 ;
int V_5 ;
int V_183 ;
int V_76 ;
V_12 = F_4 ( V_111 -> V_184 , struct V_11 , V_185 ) ;
if ( ! F_86 ( & V_12 -> V_79 ) )
return - V_186 ;
V_76 = F_34 ( & V_12 -> V_13 ) ;
F_26 ( & V_12 -> V_114 ) ;
V_75 = F_35 ( V_12 -> V_75 ,
& V_12 -> V_13 ) ;
if ( ! V_75 ) {
V_5 = - V_94 ;
goto V_187;
}
V_183 = ! ( V_75 -> V_77 ) ;
if ( V_183 ) {
if ( ! F_87 ( V_75 -> V_78 ) ) {
V_5 = - V_181 ;
goto V_187;
}
}
V_17 = F_63 ( sizeof( * V_17 ) , V_140 ) ;
if ( ! V_17 ) {
V_5 = - V_141 ;
if ( V_183 )
goto V_188;
goto V_187;
}
V_17 -> V_6 = V_12 ;
V_17 -> V_157 = NULL ;
V_17 -> V_27 = NULL ;
F_65 ( & V_17 -> V_15 ) ;
F_88 ( & V_17 -> V_189 ) ;
V_80 -> V_84 = V_17 ;
F_89 ( & V_12 -> V_10 ) ;
F_53 ( & V_17 -> V_26 , & V_12 -> V_190 ) ;
F_28 ( & V_12 -> V_114 ) ;
F_37 ( & V_12 -> V_13 , V_76 ) ;
return F_90 ( V_111 , V_80 ) ;
V_188:
F_36 ( V_75 -> V_78 ) ;
V_187:
F_28 ( & V_12 -> V_114 ) ;
F_37 ( & V_12 -> V_13 , V_76 ) ;
if ( F_38 ( & V_12 -> V_79 ) )
F_31 ( V_12 ) ;
return V_5 ;
}
static int F_91 ( struct V_111 * V_111 , struct V_17 * V_80 )
{
struct V_18 * V_17 = V_80 -> V_84 ;
struct V_11 * V_12 = V_17 -> V_6 ;
struct V_36 * V_157 = NULL ;
F_26 ( & V_17 -> V_6 -> V_114 ) ;
V_157 = V_17 -> V_157 ;
V_17 -> V_157 = NULL ;
if ( ! V_17 -> V_115 ) {
F_11 ( & V_17 -> V_26 ) ;
V_17 -> V_115 = 1 ;
}
F_28 ( & V_17 -> V_6 -> V_114 ) ;
if ( V_157 )
F_17 ( V_17 , V_157 ) ;
if ( V_17 -> V_27 )
F_13 ( & V_17 -> V_27 -> V_15 , F_7 ) ;
F_13 ( & V_17 -> V_15 , F_33 ) ;
F_92 ( & V_12 -> V_10 ) ;
return 0 ;
}
static T_1 F_93 ( struct V_6 * V_6 , struct V_191 * V_192 ,
char * V_81 )
{
int V_5 = - V_181 ;
int V_76 ;
struct V_11 * V_12 = F_94 ( V_6 ) ;
struct V_74 * V_75 ;
if ( ! V_12 )
return - V_181 ;
V_76 = F_34 ( & V_12 -> V_13 ) ;
V_75 = F_35 ( V_12 -> V_75 , & V_12 -> V_13 ) ;
if ( V_75 )
V_5 = sprintf ( V_81 , L_2 , V_75 -> V_193 ) ;
F_37 ( & V_12 -> V_13 , V_76 ) ;
return V_5 ;
}
static T_1 F_95 ( struct V_6 * V_6 ,
struct V_191 * V_192 , char * V_81 )
{
struct V_11 * V_12 = F_94 ( V_6 ) ;
int V_5 = - V_181 ;
int V_76 ;
struct V_74 * V_75 ;
if ( ! V_12 )
return - V_181 ;
V_76 = F_34 ( & V_12 -> V_13 ) ;
V_75 = F_35 ( V_12 -> V_75 , & V_12 -> V_13 ) ;
if ( V_75 )
V_5 = sprintf ( V_81 , L_3 , V_75 -> V_194 ) ;
F_37 ( & V_12 -> V_13 , V_76 ) ;
return V_5 ;
}
static int F_96 ( void )
{
int V_5 ;
if ( ! V_195 ) {
V_5 = F_97 ( & V_195 , 0 , V_196 ,
L_4 ) ;
if ( V_5 ) {
F_98 ( V_197 L_5 ) ;
return V_5 ;
}
}
V_5 = F_99 ( V_198 , V_196 ) ;
if ( V_5 >= V_196 )
return - 1 ;
return V_5 ;
}
static void F_100 ( struct V_74 * V_6 )
{
int V_199 ;
T_8 V_200 ;
struct V_11 * V_201 ;
int V_5 ;
if ( ! V_6 -> V_202 )
return;
V_201 = F_63 ( sizeof *V_201 , V_140 ) ;
if ( ! V_201 )
return;
V_5 = F_101 ( & V_201 -> V_13 ) ;
if ( V_5 ) {
F_6 ( V_201 ) ;
return;
}
F_102 ( & V_201 -> V_79 , 1 ) ;
F_103 ( & V_201 -> V_73 ) ;
V_201 -> V_203 = V_204 ;
F_88 ( & V_201 -> V_64 ) ;
F_104 ( & V_201 -> V_10 , & V_205 ) ;
F_88 ( & V_201 -> V_114 ) ;
F_67 ( & V_201 -> V_190 ) ;
F_67 ( & V_201 -> V_145 ) ;
F_105 ( & V_206 ) ;
V_199 = F_99 ( V_207 , V_196 ) ;
if ( V_199 >= V_196 ) {
F_106 ( & V_206 ) ;
V_199 = F_96 () ;
if ( V_199 < 0 )
goto V_187;
F_105 ( & V_206 ) ;
V_201 -> V_199 = V_199 + V_196 ;
V_200 = V_199 + V_195 ;
F_107 ( V_199 , V_198 ) ;
} else {
V_201 -> V_199 = V_199 ;
V_200 = V_199 + V_208 ;
F_107 ( V_199 , V_207 ) ;
}
F_106 ( & V_206 ) ;
F_108 ( V_201 -> V_75 , V_6 ) ;
V_201 -> V_209 = V_6 -> V_209 ;
F_109 ( & V_201 -> V_185 , NULL ) ;
V_201 -> V_185 . V_78 = V_210 ;
V_201 -> V_185 . V_211 = V_6 -> V_182 ? & V_212 : & V_213 ;
V_201 -> V_185 . V_10 . V_214 = & V_201 -> V_10 ;
F_110 ( & V_201 -> V_185 . V_10 , L_6 , V_201 -> V_199 ) ;
if ( F_111 ( & V_201 -> V_185 , V_200 , 1 ) )
goto V_215;
V_201 -> V_12 = F_112 ( V_216 , V_6 -> V_217 ,
V_201 -> V_185 . V_12 , V_201 ,
L_6 , V_201 -> V_199 ) ;
if ( F_71 ( V_201 -> V_12 ) )
goto V_215;
if ( F_113 ( V_201 -> V_12 , & V_218 ) )
goto V_219;
if ( F_113 ( V_201 -> V_12 , & V_220 ) )
goto V_219;
F_114 ( V_6 , & V_221 , V_201 ) ;
return;
V_219:
F_115 ( V_216 , V_201 -> V_185 . V_12 ) ;
V_215:
F_116 ( & V_201 -> V_185 ) ;
if ( V_201 -> V_199 < V_196 )
F_117 ( V_199 , V_207 ) ;
else
F_117 ( V_199 , V_198 ) ;
V_187:
if ( F_38 ( & V_201 -> V_79 ) )
F_31 ( V_201 ) ;
F_118 ( & V_201 -> V_73 ) ;
F_92 ( & V_201 -> V_10 ) ;
return;
}
static void F_119 ( struct V_11 * V_201 ,
struct V_74 * V_75 )
{
struct V_18 * V_17 ;
struct V_16 * V_222 ;
struct V_131 V_85 ;
F_120 ( & V_201 -> V_13 ) ;
V_85 . V_85 = V_223 ;
V_85 . V_126 . V_139 = 0 ;
V_85 . V_6 = V_75 ;
F_26 ( & V_201 -> V_114 ) ;
while ( ! F_40 ( & V_201 -> V_190 ) ) {
struct V_36 * V_157 ;
V_17 = F_121 ( & V_201 -> V_190 ,
struct V_18 , V_26 ) ;
V_17 -> V_115 = 1 ;
V_157 = V_17 -> V_157 ;
F_11 ( & V_17 -> V_26 ) ;
V_17 -> V_157 = NULL ;
F_69 ( & V_17 -> V_15 ) ;
F_28 ( & V_201 -> V_114 ) ;
F_60 ( & V_17 -> V_116 , & V_85 ) ;
if ( V_157 ) {
V_75 -> V_77 ( V_157 ) ;
F_17 ( V_17 , V_157 ) ;
}
F_26 ( & V_201 -> V_114 ) ;
F_13 ( & V_17 -> V_15 , F_33 ) ;
}
while ( ! F_40 ( & V_201 -> V_145 ) ) {
V_222 = F_121 ( & V_201 ->
V_145 ,
struct V_16 ,
V_26 ) ;
F_9 ( & V_222 -> V_25 ) ;
V_222 -> V_115 = 1 ;
F_12 ( & V_222 -> V_25 ) ;
F_11 ( & V_222 -> V_26 ) ;
if ( V_222 -> V_96 ) {
F_48 ( & V_222 -> V_92 ->
V_116 ) ;
V_222 -> V_92 -> V_116 . V_6 = NULL ;
}
F_54 ( & V_222 -> V_91 ) ;
F_55 ( & V_222 -> V_110 , V_124 , V_125 ) ;
}
F_28 ( & V_201 -> V_114 ) ;
}
static void F_122 ( struct V_74 * V_6 , void * V_224 )
{
struct V_11 * V_201 = V_224 ;
int V_225 = 1 ;
if ( ! V_201 )
return;
F_123 ( V_201 -> V_12 , NULL ) ;
F_115 ( V_216 , V_201 -> V_185 . V_12 ) ;
F_116 ( & V_201 -> V_185 ) ;
if ( V_201 -> V_199 < V_196 )
F_117 ( V_201 -> V_199 , V_207 ) ;
else
F_117 ( V_201 -> V_199 - V_196 , V_198 ) ;
if ( V_6 -> V_77 ) {
F_108 ( V_201 -> V_75 , NULL ) ;
F_119 ( V_201 , V_6 ) ;
V_225 = 0 ;
}
if ( F_38 ( & V_201 -> V_79 ) )
F_31 ( V_201 ) ;
if ( V_225 )
F_118 ( & V_201 -> V_73 ) ;
F_92 ( & V_201 -> V_10 ) ;
}
static char * F_124 ( struct V_6 * V_12 , T_9 * V_226 )
{
if ( V_226 )
* V_226 = 0666 ;
return F_125 ( V_140 , L_7 , F_126 ( V_12 ) ) ;
}
static int T_10 F_127 ( void )
{
int V_5 ;
V_5 = F_128 ( V_208 , V_196 ,
L_4 ) ;
if ( V_5 ) {
F_98 ( V_197 L_8 ) ;
goto V_149;
}
V_216 = F_129 ( V_210 , L_4 ) ;
if ( F_71 ( V_216 ) ) {
V_5 = F_130 ( V_216 ) ;
F_98 ( V_197 L_9 ) ;
goto V_227;
}
V_216 -> V_228 = F_124 ;
V_5 = F_131 ( V_216 , & V_229 . V_192 ) ;
if ( V_5 ) {
F_98 ( V_197 L_10 ) ;
goto V_230;
}
V_5 = F_132 ( & V_221 ) ;
if ( V_5 ) {
F_98 ( V_197 L_11 ) ;
goto V_230;
}
return 0 ;
V_230:
F_133 ( V_216 ) ;
V_227:
F_134 ( V_208 , V_196 ) ;
V_149:
return V_5 ;
}
static void T_11 F_135 ( void )
{
F_136 ( & V_221 ) ;
F_133 ( V_216 ) ;
F_134 ( V_208 , V_196 ) ;
if ( V_195 )
F_134 ( V_195 , V_196 ) ;
F_137 ( & V_70 ) ;
F_137 ( & V_63 ) ;
F_137 ( & V_44 ) ;
F_137 ( & V_43 ) ;
F_137 ( & V_60 ) ;
F_137 ( & V_51 ) ;
F_137 ( & V_55 ) ;
}
