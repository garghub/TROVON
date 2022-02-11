static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( & V_4 -> V_5 ) ;
F_4 ( V_4 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 =
F_2 ( V_7 , struct V_8 , V_7 ) ;
F_4 ( V_9 ) ;
}
void F_6 ( struct V_10 * V_9 ,
struct V_8 * V_11 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 , * V_16 ;
if ( V_11 ) {
F_7 ( & V_11 -> V_17 ) ;
F_8 (evt, tmp, &uobj->comp_list, obj_list) {
F_9 ( & V_15 -> V_18 ) ;
F_4 ( V_15 ) ;
}
F_10 ( & V_11 -> V_17 ) ;
F_11 ( & V_11 -> V_7 , F_5 ) ;
}
F_7 ( & V_9 -> V_19 -> V_17 ) ;
F_8 (evt, tmp, &uobj->async_list, obj_list) {
F_9 ( & V_15 -> V_18 ) ;
F_4 ( V_15 ) ;
}
F_10 ( & V_9 -> V_19 -> V_17 ) ;
}
void F_12 ( struct V_10 * V_9 ,
struct V_20 * V_13 )
{
struct V_14 * V_15 , * V_16 ;
F_7 ( & V_9 -> V_19 -> V_17 ) ;
F_8 (evt, tmp, &uobj->event_list, obj_list) {
F_9 ( & V_15 -> V_18 ) ;
F_4 ( V_15 ) ;
}
F_10 ( & V_9 -> V_19 -> V_17 ) ;
}
static void F_13 ( struct V_21 * V_22 ,
struct V_23 * V_13 )
{
struct V_24 * V_25 , * V_16 ;
F_8 (mcast, tmp, &uobj->mcast_list, list) {
F_14 ( V_22 , & V_25 -> V_26 , V_25 -> V_27 ) ;
F_9 ( & V_25 -> V_18 ) ;
F_4 ( V_25 ) ;
}
}
static int F_15 ( struct V_10 * V_9 ,
struct V_28 * V_29 )
{
struct V_30 * V_13 , * V_16 ;
V_29 -> V_31 = 1 ;
F_8 (uobj, tmp, &context->ah_list, list) {
struct V_32 * V_33 = V_13 -> V_34 ;
F_16 ( & V_35 , V_13 ) ;
F_17 ( V_33 ) ;
F_4 ( V_13 ) ;
}
F_8 (uobj, tmp, &context->mw_list, list) {
struct V_36 * V_37 = V_13 -> V_34 ;
F_16 ( & V_38 , V_13 ) ;
F_18 ( V_37 ) ;
F_4 ( V_13 ) ;
}
F_8 (uobj, tmp, &context->rule_list, list) {
struct V_39 * V_40 = V_13 -> V_34 ;
F_16 ( & V_41 , V_13 ) ;
F_19 ( V_40 ) ;
F_4 ( V_13 ) ;
}
F_8 (uobj, tmp, &context->qp_list, list) {
struct V_21 * V_22 = V_13 -> V_34 ;
struct V_23 * V_42 =
F_2 ( V_13 , struct V_23 , V_43 . V_44 ) ;
F_16 ( & V_45 , V_13 ) ;
if ( V_22 != V_22 -> V_46 ) {
F_20 ( V_22 ) ;
} else {
F_13 ( V_22 , V_42 ) ;
F_21 ( V_22 ) ;
}
F_12 ( V_9 , & V_42 -> V_43 ) ;
F_4 ( V_42 ) ;
}
F_8 (uobj, tmp, &context->srq_list, list) {
struct V_47 * V_48 = V_13 -> V_34 ;
struct V_20 * V_43 =
F_2 ( V_13 , struct V_20 , V_44 ) ;
F_16 ( & V_49 , V_13 ) ;
F_22 ( V_48 ) ;
F_12 ( V_9 , V_43 ) ;
F_4 ( V_43 ) ;
}
F_8 (uobj, tmp, &context->cq_list, list) {
struct V_50 * V_51 = V_13 -> V_34 ;
struct V_8 * V_11 = V_51 -> V_52 ;
struct V_12 * V_53 =
F_2 ( V_13 , struct V_12 , V_44 ) ;
F_16 ( & V_54 , V_13 ) ;
F_23 ( V_51 ) ;
F_6 ( V_9 , V_11 , V_53 ) ;
F_4 ( V_53 ) ;
}
F_8 (uobj, tmp, &context->mr_list, list) {
struct V_55 * V_56 = V_13 -> V_34 ;
F_16 ( & V_57 , V_13 ) ;
F_24 ( V_56 ) ;
F_4 ( V_13 ) ;
}
F_25 ( & V_9 -> V_58 -> V_59 ) ;
F_8 (uobj, tmp, &context->xrcd_list, list) {
struct V_60 * V_61 = V_13 -> V_34 ;
struct V_62 * V_63 =
F_2 ( V_13 , struct V_62 , V_44 ) ;
F_16 ( & V_64 , V_13 ) ;
F_26 ( V_9 -> V_58 , V_61 ) ;
F_4 ( V_63 ) ;
}
F_27 ( & V_9 -> V_58 -> V_59 ) ;
F_8 (uobj, tmp, &context->pd_list, list) {
struct V_65 * V_66 = V_13 -> V_34 ;
F_16 ( & V_67 , V_13 ) ;
F_28 ( V_66 ) ;
F_4 ( V_13 ) ;
}
F_29 ( V_29 -> V_68 ) ;
return V_29 -> V_58 -> V_69 ( V_29 ) ;
}
static void F_30 ( struct V_3 * V_4 )
{
F_31 ( & V_4 -> V_70 ) ;
}
static void F_32 ( struct V_6 * V_7 )
{
struct V_10 * V_9 =
F_2 ( V_7 , struct V_10 , V_7 ) ;
struct V_71 * V_72 ;
int V_73 ;
V_73 = F_33 ( & V_9 -> V_58 -> V_5 ) ;
V_72 = F_34 ( V_9 -> V_58 -> V_72 ,
& V_9 -> V_58 -> V_5 ) ;
if ( V_72 && ! V_72 -> V_74 )
F_35 ( V_72 -> V_75 ) ;
F_36 ( & V_9 -> V_58 -> V_5 , V_73 ) ;
if ( F_37 ( & V_9 -> V_58 -> V_76 ) )
F_30 ( V_9 -> V_58 ) ;
F_4 ( V_9 ) ;
}
static T_1 F_38 ( struct V_9 * V_77 , char T_2 * V_78 ,
T_3 V_79 , T_4 * V_80 )
{
struct V_8 * V_9 = V_77 -> V_81 ;
struct V_14 * V_82 ;
int V_83 ;
int V_84 = 0 ;
F_7 ( & V_9 -> V_17 ) ;
while ( F_39 ( & V_9 -> V_85 ) ) {
F_10 ( & V_9 -> V_17 ) ;
if ( V_77 -> V_86 & V_87 )
return - V_88 ;
if ( F_40 ( V_9 -> V_89 ,
( ! F_39 ( & V_9 -> V_85 ) ||
! V_9 -> V_90 -> V_58 -> V_72 ) ) )
return - V_91 ;
if ( F_39 ( & V_9 -> V_85 ) &&
! V_9 -> V_90 -> V_58 -> V_72 )
return - V_92 ;
F_7 ( & V_9 -> V_17 ) ;
}
V_82 = F_41 ( V_9 -> V_85 . V_93 , struct V_14 , V_18 ) ;
if ( V_9 -> V_94 )
V_83 = sizeof ( struct V_95 ) ;
else
V_83 = sizeof ( struct V_96 ) ;
if ( V_83 > V_79 ) {
V_84 = - V_97 ;
V_82 = NULL ;
} else {
F_9 ( V_9 -> V_85 . V_93 ) ;
if ( V_82 -> V_98 ) {
++ ( * V_82 -> V_98 ) ;
F_9 ( & V_82 -> V_99 ) ;
}
}
F_10 ( & V_9 -> V_17 ) ;
if ( V_82 ) {
if ( F_42 ( V_78 , V_82 , V_83 ) )
V_84 = - V_100 ;
else
V_84 = V_83 ;
}
F_4 ( V_82 ) ;
return V_84 ;
}
static unsigned int F_43 ( struct V_9 * V_77 ,
struct V_101 * V_102 )
{
unsigned int V_103 = 0 ;
struct V_8 * V_9 = V_77 -> V_81 ;
V_89 ( V_77 , & V_9 -> V_89 , V_102 ) ;
F_7 ( & V_9 -> V_17 ) ;
if ( ! F_39 ( & V_9 -> V_85 ) )
V_103 = V_104 | V_105 ;
F_10 ( & V_9 -> V_17 ) ;
return V_103 ;
}
static int F_44 ( int V_106 , struct V_9 * V_77 , int V_107 )
{
struct V_8 * V_9 = V_77 -> V_81 ;
return F_45 ( V_106 , V_77 , V_107 , & V_9 -> V_108 ) ;
}
static int F_46 ( struct V_109 * V_109 , struct V_9 * V_77 )
{
struct V_8 * V_9 = V_77 -> V_81 ;
struct V_14 * V_110 , * V_16 ;
int V_111 = 0 ;
F_25 ( & V_9 -> V_90 -> V_58 -> V_112 ) ;
F_7 ( & V_9 -> V_17 ) ;
V_111 = V_9 -> V_113 ;
V_9 -> V_113 = 1 ;
F_8 (entry, tmp, &file->event_list, list) {
if ( V_110 -> V_98 )
F_9 ( & V_110 -> V_99 ) ;
F_4 ( V_110 ) ;
}
F_10 ( & V_9 -> V_17 ) ;
if ( ! V_111 ) {
F_9 ( & V_9 -> V_18 ) ;
if ( V_9 -> V_94 )
F_47 ( & V_9 -> V_90 ->
V_114 ) ;
}
F_27 ( & V_9 -> V_90 -> V_58 -> V_112 ) ;
F_11 ( & V_9 -> V_90 -> V_7 , F_32 ) ;
F_11 ( & V_9 -> V_7 , F_5 ) ;
return 0 ;
}
void F_48 ( struct V_50 * V_51 , void * V_52 )
{
struct V_8 * V_9 = V_52 ;
struct V_12 * V_13 ;
struct V_14 * V_110 ;
unsigned long V_115 ;
if ( ! V_9 )
return;
F_49 ( & V_9 -> V_17 , V_115 ) ;
if ( V_9 -> V_113 ) {
F_50 ( & V_9 -> V_17 , V_115 ) ;
return;
}
V_110 = F_51 ( sizeof *V_110 , V_116 ) ;
if ( ! V_110 ) {
F_50 ( & V_9 -> V_17 , V_115 ) ;
return;
}
V_13 = F_2 ( V_51 -> V_44 , struct V_12 , V_44 ) ;
V_110 -> V_117 . V_70 . V_118 = V_51 -> V_44 -> V_119 ;
V_110 -> V_98 = & V_13 -> V_120 ;
F_52 ( & V_110 -> V_18 , & V_9 -> V_85 ) ;
F_52 ( & V_110 -> V_99 , & V_13 -> V_121 ) ;
F_50 ( & V_9 -> V_17 , V_115 ) ;
F_53 ( & V_9 -> V_89 ) ;
F_54 ( & V_9 -> V_108 , V_122 , V_123 ) ;
}
static void F_55 ( struct V_10 * V_9 ,
T_5 V_124 , T_5 V_82 ,
struct V_125 * V_99 ,
T_6 * V_98 )
{
struct V_14 * V_110 ;
unsigned long V_115 ;
F_49 ( & V_9 -> V_19 -> V_17 , V_115 ) ;
if ( V_9 -> V_19 -> V_113 ) {
F_50 ( & V_9 -> V_19 -> V_17 , V_115 ) ;
return;
}
V_110 = F_51 ( sizeof *V_110 , V_116 ) ;
if ( ! V_110 ) {
F_50 ( & V_9 -> V_19 -> V_17 , V_115 ) ;
return;
}
V_110 -> V_117 . V_126 . V_124 = V_124 ;
V_110 -> V_117 . V_126 . V_127 = V_82 ;
V_110 -> V_117 . V_126 . V_128 = 0 ;
V_110 -> V_98 = V_98 ;
F_52 ( & V_110 -> V_18 , & V_9 -> V_19 -> V_85 ) ;
if ( V_99 )
F_52 ( & V_110 -> V_99 , V_99 ) ;
F_50 ( & V_9 -> V_19 -> V_17 , V_115 ) ;
F_53 ( & V_9 -> V_19 -> V_89 ) ;
F_54 ( & V_9 -> V_19 -> V_108 , V_122 , V_123 ) ;
}
void F_56 ( struct V_129 * V_82 , void * V_130 )
{
struct V_12 * V_13 = F_2 ( V_82 -> V_124 . V_51 -> V_44 ,
struct V_12 , V_44 ) ;
F_55 ( V_13 -> V_90 , V_13 -> V_44 . V_119 ,
V_82 -> V_82 , & V_13 -> V_131 ,
& V_13 -> V_132 ) ;
}
void F_57 ( struct V_129 * V_82 , void * V_130 )
{
struct V_20 * V_13 ;
if ( ! V_82 -> V_124 . V_22 -> V_44 || ! V_82 -> V_124 . V_22 -> V_44 -> V_133 )
return;
V_13 = F_2 ( V_82 -> V_124 . V_22 -> V_44 ,
struct V_20 , V_44 ) ;
F_55 ( V_130 , V_13 -> V_44 . V_119 ,
V_82 -> V_82 , & V_13 -> V_85 ,
& V_13 -> V_134 ) ;
}
void F_58 ( struct V_129 * V_82 , void * V_130 )
{
struct V_20 * V_13 ;
V_13 = F_2 ( V_82 -> V_124 . V_48 -> V_44 ,
struct V_20 , V_44 ) ;
F_55 ( V_130 , V_13 -> V_44 . V_119 ,
V_82 -> V_82 , & V_13 -> V_85 ,
& V_13 -> V_134 ) ;
}
void F_59 ( struct V_135 * V_136 ,
struct V_129 * V_82 )
{
struct V_10 * V_9 =
F_2 ( V_136 , struct V_10 , V_114 ) ;
F_55 ( V_9 , V_82 -> V_124 . V_137 , V_82 -> V_82 ,
NULL , NULL ) ;
}
void F_60 ( struct V_10 * V_9 )
{
F_11 ( & V_9 -> V_19 -> V_7 , F_5 ) ;
V_9 -> V_19 = NULL ;
}
struct V_9 * F_61 ( struct V_10 * V_90 ,
struct V_71 * V_72 ,
int V_94 )
{
struct V_8 * V_11 ;
struct V_9 * V_77 ;
int V_84 ;
V_11 = F_62 ( sizeof( * V_11 ) , V_138 ) ;
if ( ! V_11 )
return F_63 ( - V_139 ) ;
F_64 ( & V_11 -> V_7 ) ;
F_65 ( & V_11 -> V_17 ) ;
F_66 ( & V_11 -> V_85 ) ;
F_67 ( & V_11 -> V_89 ) ;
V_11 -> V_90 = V_90 ;
F_68 ( & V_11 -> V_90 -> V_7 ) ;
V_11 -> V_108 = NULL ;
V_11 -> V_113 = 0 ;
V_77 = F_69 ( L_1 , & V_140 ,
V_11 , V_141 ) ;
if ( F_70 ( V_77 ) )
goto V_142;
F_25 ( & V_90 -> V_58 -> V_112 ) ;
F_52 ( & V_11 -> V_18 ,
& V_90 -> V_58 -> V_143 ) ;
F_27 ( & V_90 -> V_58 -> V_112 ) ;
if ( V_94 ) {
F_71 ( V_90 -> V_19 ) ;
V_90 -> V_19 = V_11 ;
F_68 ( & V_90 -> V_19 -> V_7 ) ;
F_72 ( & V_90 -> V_114 ,
V_72 ,
F_59 ) ;
V_84 = F_73 ( & V_90 -> V_114 ) ;
if ( V_84 )
goto V_144;
V_11 -> V_94 = 1 ;
}
return V_77 ;
V_144:
F_74 ( V_77 ) ;
F_11 ( & V_90 -> V_19 -> V_7 , F_5 ) ;
V_90 -> V_19 = NULL ;
return F_63 ( V_84 ) ;
V_142:
F_11 ( & V_11 -> V_90 -> V_7 , F_32 ) ;
F_11 ( & V_11 -> V_7 , F_5 ) ;
return V_77 ;
}
struct V_8 * F_75 ( int V_106 )
{
struct V_8 * V_11 = NULL ;
struct V_106 V_145 = F_76 ( V_106 ) ;
if ( ! V_145 . V_9 )
return NULL ;
if ( V_145 . V_9 -> V_146 != & V_140 )
goto V_147;
V_11 = V_145 . V_9 -> V_81 ;
if ( V_11 -> V_94 ) {
V_11 = NULL ;
goto V_147;
}
F_68 ( & V_11 -> V_7 ) ;
V_147:
F_77 ( V_145 ) ;
return V_11 ;
}
static T_1 F_78 ( struct V_9 * V_77 , const char T_2 * V_78 ,
T_3 V_79 , T_4 * V_80 )
{
struct V_10 * V_9 = V_77 -> V_81 ;
struct V_71 * V_72 ;
struct V_148 V_149 ;
T_7 V_115 ;
int V_73 ;
T_1 V_84 ;
if ( V_79 < sizeof V_149 )
return - V_97 ;
if ( F_79 ( & V_149 , V_78 , sizeof V_149 ) )
return - V_100 ;
V_73 = F_33 ( & V_9 -> V_58 -> V_5 ) ;
V_72 = F_34 ( V_9 -> V_58 -> V_72 ,
& V_9 -> V_58 -> V_5 ) ;
if ( ! V_72 ) {
V_84 = - V_92 ;
goto V_147;
}
V_115 = ( V_149 . V_150 &
V_151 ) >> V_152 ;
if ( ! V_115 ) {
T_7 V_150 ;
if ( V_149 . V_150 & ~ ( T_7 ) ( V_151 |
V_153 ) ) {
V_84 = - V_97 ;
goto V_147;
}
V_150 = V_149 . V_150 & V_153 ;
if ( V_150 >= F_80 ( V_154 ) ||
! V_154 [ V_150 ] ) {
V_84 = - V_97 ;
goto V_147;
}
if ( ! V_9 -> V_155 &&
V_150 != V_156 ) {
V_84 = - V_97 ;
goto V_147;
}
if ( ! ( V_72 -> V_157 & ( 1ull << V_150 ) ) ) {
V_84 = - V_158 ;
goto V_147;
}
if ( V_149 . V_159 * 4 != V_79 ) {
V_84 = - V_97 ;
goto V_147;
}
V_84 = V_154 [ V_150 ] ( V_9 , V_72 ,
V_78 + sizeof( V_149 ) ,
V_149 . V_159 * 4 ,
V_149 . V_160 * 4 ) ;
} else if ( V_115 == V_161 ) {
T_7 V_150 ;
struct V_162 V_163 ;
struct V_164 V_165 ;
struct V_164 V_166 ;
T_3 V_167 = V_79 ;
if ( V_149 . V_150 & ~ ( T_7 ) ( V_151 |
V_153 ) ) {
V_84 = - V_97 ;
goto V_147;
}
V_150 = V_149 . V_150 & V_153 ;
if ( V_150 >= F_80 ( V_168 ) ||
! V_168 [ V_150 ] ) {
V_84 = - V_158 ;
goto V_147;
}
if ( ! V_9 -> V_155 ) {
V_84 = - V_97 ;
goto V_147;
}
if ( ! ( V_72 -> V_169 & ( 1ull << V_150 ) ) ) {
V_84 = - V_158 ;
goto V_147;
}
if ( V_79 < ( sizeof( V_149 ) + sizeof( V_163 ) ) ) {
V_84 = - V_97 ;
goto V_147;
}
if ( F_79 ( & V_163 , V_78 + sizeof( V_149 ) , sizeof( V_163 ) ) ) {
V_84 = - V_100 ;
goto V_147;
}
V_79 -= sizeof( V_149 ) + sizeof( V_163 ) ;
V_78 += sizeof( V_149 ) + sizeof( V_163 ) ;
if ( ( V_149 . V_159 + V_163 . V_170 ) * 8 != V_79 ) {
V_84 = - V_97 ;
goto V_147;
}
if ( V_163 . V_171 ) {
V_84 = - V_97 ;
goto V_147;
}
if ( V_163 . V_172 ) {
if ( ! V_149 . V_160 && ! V_163 . V_173 ) {
V_84 = - V_97 ;
goto V_147;
}
if ( ! F_81 ( V_174 ,
( void T_2 * ) ( unsigned long ) V_163 . V_172 ,
( V_149 . V_160 + V_163 . V_173 ) * 8 ) ) {
V_84 = - V_100 ;
goto V_147;
}
} else {
if ( V_149 . V_160 || V_163 . V_173 ) {
V_84 = - V_97 ;
goto V_147;
}
}
F_82 ( & V_165 , V_78 , ( unsigned long ) V_163 . V_172 ,
V_149 . V_159 * 8 , V_149 . V_160 * 8 ) ;
F_82 ( & V_166 ,
V_78 + V_165 . V_175 ,
( unsigned long ) V_163 . V_172 + V_165 . V_176 ,
V_163 . V_170 * 8 ,
V_163 . V_173 * 8 ) ;
V_84 = V_168 [ V_150 ] ( V_9 ,
V_72 ,
& V_165 ,
& V_166 ) ;
if ( ! V_84 )
V_84 = V_167 ;
} else {
V_84 = - V_158 ;
}
V_147:
F_36 ( & V_9 -> V_58 -> V_5 , V_73 ) ;
return V_84 ;
}
static int F_83 ( struct V_9 * V_77 , struct V_177 * V_178 )
{
struct V_10 * V_9 = V_77 -> V_81 ;
struct V_71 * V_72 ;
int V_84 = 0 ;
int V_73 ;
V_73 = F_33 ( & V_9 -> V_58 -> V_5 ) ;
V_72 = F_34 ( V_9 -> V_58 -> V_72 ,
& V_9 -> V_58 -> V_5 ) ;
if ( ! V_72 ) {
V_84 = - V_92 ;
goto V_147;
}
if ( ! V_9 -> V_155 )
V_84 = - V_179 ;
else
V_84 = V_72 -> V_180 ( V_9 -> V_155 , V_178 ) ;
V_147:
F_36 ( & V_9 -> V_58 -> V_5 , V_73 ) ;
return V_84 ;
}
static int F_84 ( struct V_109 * V_109 , struct V_9 * V_77 )
{
struct V_3 * V_4 ;
struct V_10 * V_9 ;
struct V_71 * V_72 ;
int V_84 ;
int V_181 ;
int V_73 ;
V_4 = F_2 ( V_109 -> V_182 , struct V_3 , V_183 ) ;
if ( ! F_85 ( & V_4 -> V_76 ) )
return - V_184 ;
V_73 = F_33 ( & V_4 -> V_5 ) ;
F_25 ( & V_4 -> V_112 ) ;
V_72 = F_34 ( V_4 -> V_72 ,
& V_4 -> V_5 ) ;
if ( ! V_72 ) {
V_84 = - V_92 ;
goto V_185;
}
V_181 = ! ( V_72 -> V_74 ) ;
if ( V_181 ) {
if ( ! F_86 ( V_72 -> V_75 ) ) {
V_84 = - V_179 ;
goto V_185;
}
}
V_9 = F_62 ( sizeof( * V_9 ) , V_138 ) ;
if ( ! V_9 ) {
V_84 = - V_139 ;
if ( V_181 )
goto V_186;
goto V_185;
}
V_9 -> V_58 = V_4 ;
V_9 -> V_155 = NULL ;
V_9 -> V_19 = NULL ;
F_64 ( & V_9 -> V_7 ) ;
F_87 ( & V_9 -> V_187 ) ;
V_77 -> V_81 = V_9 ;
F_88 ( & V_4 -> V_2 ) ;
F_52 ( & V_9 -> V_18 , & V_4 -> V_188 ) ;
F_27 ( & V_4 -> V_112 ) ;
F_36 ( & V_4 -> V_5 , V_73 ) ;
return F_89 ( V_109 , V_77 ) ;
V_186:
F_35 ( V_72 -> V_75 ) ;
V_185:
F_27 ( & V_4 -> V_112 ) ;
F_36 ( & V_4 -> V_5 , V_73 ) ;
if ( F_37 ( & V_4 -> V_76 ) )
F_30 ( V_4 ) ;
return V_84 ;
}
static int F_90 ( struct V_109 * V_109 , struct V_9 * V_77 )
{
struct V_10 * V_9 = V_77 -> V_81 ;
struct V_3 * V_4 = V_9 -> V_58 ;
struct V_28 * V_155 = NULL ;
F_25 ( & V_9 -> V_58 -> V_112 ) ;
V_155 = V_9 -> V_155 ;
V_9 -> V_155 = NULL ;
if ( ! V_9 -> V_113 ) {
F_9 ( & V_9 -> V_18 ) ;
V_9 -> V_113 = 1 ;
}
F_27 ( & V_9 -> V_58 -> V_112 ) ;
if ( V_155 )
F_15 ( V_9 , V_155 ) ;
if ( V_9 -> V_19 )
F_11 ( & V_9 -> V_19 -> V_7 , F_5 ) ;
F_11 ( & V_9 -> V_7 , F_32 ) ;
F_91 ( & V_4 -> V_2 ) ;
return 0 ;
}
static T_1 F_92 ( struct V_58 * V_58 , struct V_189 * V_190 ,
char * V_78 )
{
int V_84 = - V_179 ;
int V_73 ;
struct V_3 * V_4 = F_93 ( V_58 ) ;
struct V_71 * V_72 ;
if ( ! V_4 )
return - V_179 ;
V_73 = F_33 ( & V_4 -> V_5 ) ;
V_72 = F_34 ( V_4 -> V_72 , & V_4 -> V_5 ) ;
if ( V_72 )
V_84 = sprintf ( V_78 , L_2 , V_72 -> V_191 ) ;
F_36 ( & V_4 -> V_5 , V_73 ) ;
return V_84 ;
}
static T_1 F_94 ( struct V_58 * V_58 ,
struct V_189 * V_190 , char * V_78 )
{
struct V_3 * V_4 = F_93 ( V_58 ) ;
int V_84 = - V_179 ;
int V_73 ;
struct V_71 * V_72 ;
if ( ! V_4 )
return - V_179 ;
V_73 = F_33 ( & V_4 -> V_5 ) ;
V_72 = F_34 ( V_4 -> V_72 , & V_4 -> V_5 ) ;
if ( V_72 )
V_84 = sprintf ( V_78 , L_3 , V_72 -> V_192 ) ;
F_36 ( & V_4 -> V_5 , V_73 ) ;
return V_84 ;
}
static int F_95 ( void )
{
int V_84 ;
if ( ! V_193 ) {
V_84 = F_96 ( & V_193 , 0 , V_194 ,
L_4 ) ;
if ( V_84 ) {
F_97 ( V_195 L_5 ) ;
return V_84 ;
}
}
V_84 = F_98 ( V_196 , V_194 ) ;
if ( V_84 >= V_194 )
return - 1 ;
return V_84 ;
}
static void F_99 ( struct V_71 * V_58 )
{
int V_197 ;
T_8 V_198 ;
struct V_3 * V_199 ;
int V_84 ;
if ( ! V_58 -> V_200 )
return;
V_199 = F_62 ( sizeof *V_199 , V_138 ) ;
if ( ! V_199 )
return;
V_84 = F_100 ( & V_199 -> V_5 ) ;
if ( V_84 ) {
F_4 ( V_199 ) ;
return;
}
F_101 ( & V_199 -> V_76 , 1 ) ;
F_102 ( & V_199 -> V_70 ) ;
V_199 -> V_201 = V_202 ;
F_87 ( & V_199 -> V_59 ) ;
F_103 ( & V_199 -> V_2 , & V_203 ) ;
F_87 ( & V_199 -> V_112 ) ;
F_66 ( & V_199 -> V_188 ) ;
F_66 ( & V_199 -> V_143 ) ;
F_104 ( & V_204 ) ;
V_197 = F_98 ( V_205 , V_194 ) ;
if ( V_197 >= V_194 ) {
F_105 ( & V_204 ) ;
V_197 = F_95 () ;
if ( V_197 < 0 )
goto V_185;
F_104 ( & V_204 ) ;
V_199 -> V_197 = V_197 + V_194 ;
V_198 = V_197 + V_193 ;
F_106 ( V_197 , V_196 ) ;
} else {
V_199 -> V_197 = V_197 ;
V_198 = V_197 + V_206 ;
F_106 ( V_197 , V_205 ) ;
}
F_105 ( & V_204 ) ;
F_107 ( V_199 -> V_72 , V_58 ) ;
V_199 -> V_207 = V_58 -> V_207 ;
F_108 ( & V_199 -> V_183 , NULL ) ;
V_199 -> V_183 . V_75 = V_208 ;
V_199 -> V_183 . V_209 = V_58 -> V_180 ? & V_210 : & V_211 ;
V_199 -> V_183 . V_2 . V_212 = & V_199 -> V_2 ;
F_109 ( & V_199 -> V_183 . V_2 , L_6 , V_199 -> V_197 ) ;
if ( F_110 ( & V_199 -> V_183 , V_198 , 1 ) )
goto V_213;
V_199 -> V_4 = F_111 ( V_214 , V_58 -> V_215 ,
V_199 -> V_183 . V_4 , V_199 ,
L_6 , V_199 -> V_197 ) ;
if ( F_70 ( V_199 -> V_4 ) )
goto V_213;
if ( F_112 ( V_199 -> V_4 , & V_216 ) )
goto V_217;
if ( F_112 ( V_199 -> V_4 , & V_218 ) )
goto V_217;
F_113 ( V_58 , & V_219 , V_199 ) ;
return;
V_217:
F_114 ( V_214 , V_199 -> V_183 . V_4 ) ;
V_213:
F_115 ( & V_199 -> V_183 ) ;
if ( V_199 -> V_197 < V_194 )
F_116 ( V_197 , V_205 ) ;
else
F_116 ( V_197 , V_196 ) ;
V_185:
if ( F_37 ( & V_199 -> V_76 ) )
F_30 ( V_199 ) ;
F_117 ( & V_199 -> V_70 ) ;
F_91 ( & V_199 -> V_2 ) ;
return;
}
static void F_118 ( struct V_3 * V_199 ,
struct V_71 * V_72 )
{
struct V_10 * V_9 ;
struct V_8 * V_220 ;
struct V_129 V_82 ;
F_119 ( & V_199 -> V_5 ) ;
V_82 . V_82 = V_221 ;
V_82 . V_124 . V_137 = 0 ;
V_82 . V_58 = V_72 ;
F_25 ( & V_199 -> V_112 ) ;
while ( ! F_39 ( & V_199 -> V_188 ) ) {
struct V_28 * V_155 ;
V_9 = F_120 ( & V_199 -> V_188 ,
struct V_10 , V_18 ) ;
V_9 -> V_113 = 1 ;
V_155 = V_9 -> V_155 ;
F_9 ( & V_9 -> V_18 ) ;
V_9 -> V_155 = NULL ;
F_68 ( & V_9 -> V_7 ) ;
F_27 ( & V_199 -> V_112 ) ;
F_59 ( & V_9 -> V_114 , & V_82 ) ;
if ( V_155 ) {
V_72 -> V_74 ( V_155 ) ;
F_15 ( V_9 , V_155 ) ;
}
F_25 ( & V_199 -> V_112 ) ;
F_11 ( & V_9 -> V_7 , F_32 ) ;
}
while ( ! F_39 ( & V_199 -> V_143 ) ) {
V_220 = F_120 ( & V_199 ->
V_143 ,
struct V_8 ,
V_18 ) ;
F_7 ( & V_220 -> V_17 ) ;
V_220 -> V_113 = 1 ;
F_10 ( & V_220 -> V_17 ) ;
F_9 ( & V_220 -> V_18 ) ;
if ( V_220 -> V_94 ) {
F_47 ( & V_220 -> V_90 ->
V_114 ) ;
V_220 -> V_90 -> V_114 . V_58 = NULL ;
}
F_53 ( & V_220 -> V_89 ) ;
F_54 ( & V_220 -> V_108 , V_122 , V_123 ) ;
}
F_27 ( & V_199 -> V_112 ) ;
}
static void F_121 ( struct V_71 * V_58 , void * V_222 )
{
struct V_3 * V_199 = V_222 ;
int V_223 = 1 ;
if ( ! V_199 )
return;
F_122 ( V_199 -> V_4 , NULL ) ;
F_114 ( V_214 , V_199 -> V_183 . V_4 ) ;
F_115 ( & V_199 -> V_183 ) ;
if ( V_199 -> V_197 < V_194 )
F_116 ( V_199 -> V_197 , V_205 ) ;
else
F_116 ( V_199 -> V_197 - V_194 , V_196 ) ;
if ( V_58 -> V_74 ) {
F_107 ( V_199 -> V_72 , NULL ) ;
F_118 ( V_199 , V_58 ) ;
V_223 = 0 ;
}
if ( F_37 ( & V_199 -> V_76 ) )
F_30 ( V_199 ) ;
if ( V_223 )
F_117 ( & V_199 -> V_70 ) ;
F_91 ( & V_199 -> V_2 ) ;
}
static char * F_123 ( struct V_58 * V_4 , T_9 * V_224 )
{
if ( V_224 )
* V_224 = 0666 ;
return F_124 ( V_138 , L_7 , F_125 ( V_4 ) ) ;
}
static int T_10 F_126 ( void )
{
int V_84 ;
V_84 = F_127 ( V_206 , V_194 ,
L_4 ) ;
if ( V_84 ) {
F_97 ( V_195 L_8 ) ;
goto V_147;
}
V_214 = F_128 ( V_208 , L_4 ) ;
if ( F_70 ( V_214 ) ) {
V_84 = F_129 ( V_214 ) ;
F_97 ( V_195 L_9 ) ;
goto V_225;
}
V_214 -> V_226 = F_123 ;
V_84 = F_130 ( V_214 , & V_227 . V_190 ) ;
if ( V_84 ) {
F_97 ( V_195 L_10 ) ;
goto V_228;
}
V_84 = F_131 ( & V_219 ) ;
if ( V_84 ) {
F_97 ( V_195 L_11 ) ;
goto V_228;
}
return 0 ;
V_228:
F_132 ( V_214 ) ;
V_225:
F_133 ( V_206 , V_194 ) ;
V_147:
return V_84 ;
}
static void T_11 F_134 ( void )
{
F_135 ( & V_219 ) ;
F_132 ( V_214 ) ;
F_133 ( V_206 , V_194 ) ;
if ( V_193 )
F_133 ( V_193 , V_194 ) ;
F_136 ( & V_67 ) ;
F_136 ( & V_57 ) ;
F_136 ( & V_38 ) ;
F_136 ( & V_35 ) ;
F_136 ( & V_54 ) ;
F_136 ( & V_45 ) ;
F_136 ( & V_49 ) ;
}
