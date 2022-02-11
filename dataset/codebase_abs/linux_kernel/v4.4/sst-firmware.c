static inline void F_1 ( volatile void T_1 * V_1 , void * V_2 , T_2 V_3 )
{
F_2 ( ( void * ) V_1 , V_2 , V_3 / 4 ) ;
}
static void F_3 ( void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 ;
F_4 ( V_6 -> V_7 , L_1 ) ;
}
static int F_5 ( struct V_5 * V_6 , T_3 V_8 ,
T_3 V_9 , T_4 V_10 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 = V_6 -> V_14 ;
if ( V_14 -> V_15 == NULL ) {
F_6 ( V_6 -> V_7 , L_2 ) ;
return - V_16 ;
}
F_4 ( V_6 -> V_7 , L_3 ,
( unsigned long ) V_9 , ( unsigned long ) V_8 , V_10 ) ;
V_12 = V_14 -> V_15 -> V_17 -> V_18 ( V_14 -> V_15 , V_8 ,
V_9 , V_10 , V_19 ) ;
if ( ! V_12 ) {
F_6 ( V_6 -> V_7 , L_4 ) ;
return - V_20 ;
}
V_12 -> V_21 = F_3 ;
V_12 -> V_22 = V_6 ;
V_12 -> V_23 ( V_12 ) ;
F_7 ( V_12 ) ;
return 0 ;
}
int F_8 ( struct V_5 * V_6 , T_3 V_8 ,
T_3 V_9 , T_4 V_10 )
{
return F_5 ( V_6 , V_8 | V_24 ,
V_9 , V_10 ) ;
}
int F_9 ( struct V_5 * V_6 , T_3 V_8 ,
T_3 V_9 , T_4 V_10 )
{
return F_5 ( V_6 , V_8 ,
V_9 | V_24 , V_10 ) ;
}
static void F_10 ( struct V_5 * V_25 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 , * V_30 ;
int V_31 ;
F_11 (block, block_list, module_list) {
if ( V_29 -> V_32 && V_29 -> V_32 -> V_33 ) {
V_31 = V_29 -> V_32 -> V_33 ( V_29 ) ;
if ( V_31 < 0 )
F_6 ( V_25 -> V_7 ,
L_5 ,
V_29 -> type , V_29 -> V_34 ) ;
}
}
F_12 (block, tmp, block_list, module_list) {
F_13 ( & V_29 -> V_35 ) ;
F_14 ( & V_29 -> V_36 , & V_25 -> V_37 ) ;
F_4 ( V_25 -> V_7 , L_6 ,
V_29 -> type , V_29 -> V_34 , V_29 -> V_38 ) ;
}
}
static int F_15 ( struct V_5 * V_25 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 ;
int V_39 = 0 ;
F_11 (block, block_list, module_list) {
if ( V_29 -> V_32 && V_29 -> V_32 -> V_40 && ! V_29 -> V_41 ) {
V_39 = V_29 -> V_32 -> V_40 ( V_29 ) ;
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 ,
L_5 ,
V_29 -> type , V_29 -> V_34 ) ;
goto V_31;
}
}
}
return V_39 ;
V_31:
F_11 (block, block_list, module_list) {
if ( V_29 -> V_32 && V_29 -> V_32 -> V_33 )
V_29 -> V_32 -> V_33 ( V_29 ) ;
}
return V_39 ;
}
static struct V_42 * F_16 ( struct V_17 * V_7 , struct V_43 * V_44 ,
int V_45 )
{
struct V_42 * V_46 ;
int V_31 ;
V_46 = F_17 ( V_7 , sizeof( * V_46 ) , V_47 ) ;
if ( ! V_46 )
return F_18 ( - V_48 ) ;
V_46 -> V_45 = V_45 ;
V_46 -> V_49 = F_19 ( V_7 , V_44 ) ;
if ( F_20 ( V_46 -> V_49 ) )
return F_21 ( V_46 -> V_49 ) ;
V_31 = F_22 ( V_7 , F_23 ( 31 ) ) ;
if ( V_31 )
return F_18 ( V_31 ) ;
V_46 -> V_7 = V_7 ;
V_31 = F_24 ( V_46 , NULL ) ;
if ( V_31 )
return F_18 ( V_31 ) ;
return V_46 ;
}
static void F_25 ( struct V_42 * V_46 )
{
F_26 ( V_46 ) ;
}
static bool F_27 ( struct V_50 * V_51 , void * V_52 )
{
struct V_5 * V_25 = (struct V_5 * ) V_52 ;
return V_51 -> V_17 -> V_7 == V_25 -> V_53 ;
}
int F_28 ( struct V_5 * V_25 , int V_54 )
{
struct V_13 * V_14 = V_25 -> V_14 ;
struct V_55 V_56 ;
T_5 V_57 ;
int V_39 ;
F_29 ( V_57 ) ;
F_30 ( V_58 , V_57 ) ;
F_30 ( V_59 , V_57 ) ;
V_14 -> V_15 = F_31 ( V_57 , F_27 , V_25 ) ;
if ( V_14 -> V_15 == NULL ) {
F_6 ( V_25 -> V_7 , L_7 ) ;
return - V_60 ;
}
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_61 = V_62 ;
V_56 . V_63 =
V_56 . V_64 = V_65 ;
V_56 . V_66 = V_56 . V_67 = V_68 ;
V_39 = F_32 ( V_14 -> V_15 , & V_56 ) ;
if ( V_39 ) {
F_6 ( V_25 -> V_7 , L_8 ,
V_39 ) ;
F_33 ( V_14 -> V_15 ) ;
V_14 -> V_15 = NULL ;
}
return V_39 ;
}
void F_34 ( struct V_5 * V_25 )
{
struct V_13 * V_14 = V_25 -> V_14 ;
if ( ! V_14 -> V_15 )
return;
F_33 ( V_14 -> V_15 ) ;
V_14 -> V_15 = NULL ;
}
int F_35 ( struct V_5 * V_6 )
{
struct V_69 * V_69 = V_6 -> V_70 ;
struct V_13 * V_14 ;
struct V_43 V_44 ;
const char * V_71 ;
int V_39 = 0 ;
if ( V_6 -> V_70 -> V_72 == - 1 )
return 0 ;
switch ( V_6 -> V_70 -> V_73 ) {
case V_74 :
V_71 = L_9 ;
break;
default:
F_6 ( V_6 -> V_7 , L_10 ,
V_6 -> V_70 -> V_73 ) ;
return - V_20 ;
}
V_14 = F_17 ( V_6 -> V_7 , sizeof( struct V_13 ) , V_47 ) ;
if ( ! V_14 )
return - V_48 ;
V_14 -> V_6 = V_6 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_75 = V_6 -> V_76 . V_77 + V_69 -> V_78 ;
V_44 . V_79 = V_6 -> V_76 . V_77 + V_69 -> V_78 + V_69 -> V_80 - 1 ;
V_44 . V_81 = V_82 ;
V_14 -> V_46 = F_16 ( V_6 -> V_53 , & V_44 , V_69 -> V_45 ) ;
if ( F_20 ( V_14 -> V_46 ) ) {
F_6 ( V_6 -> V_7 , L_11 ) ;
V_39 = F_36 ( V_14 -> V_46 ) ;
goto V_83;
}
V_6 -> V_14 = V_14 ;
V_6 -> V_84 = true ;
return 0 ;
V_83:
F_37 ( V_6 -> V_7 , V_14 ) ;
return V_39 ;
}
void F_38 ( struct V_13 * V_14 )
{
if ( V_14 == NULL )
return;
if ( V_14 -> V_15 )
F_33 ( V_14 -> V_15 ) ;
if ( V_14 -> V_46 )
F_25 ( V_14 -> V_46 ) ;
}
struct V_85 * F_39 ( struct V_5 * V_25 ,
const struct V_86 * V_87 , void * V_88 )
{
struct V_85 * V_85 ;
int V_31 ;
if ( ! V_25 -> V_32 -> V_89 )
return NULL ;
V_85 = F_40 ( sizeof( * V_85 ) , V_47 ) ;
if ( V_85 == NULL )
return NULL ;
V_85 -> V_25 = V_25 ;
V_85 -> V_88 = V_88 ;
V_85 -> V_10 = V_87 -> V_10 ;
V_85 -> V_90 = F_41 ( V_25 -> V_53 , V_85 -> V_10 ,
& V_85 -> V_91 , V_92 | V_47 ) ;
if ( ! V_85 -> V_90 ) {
F_6 ( V_25 -> V_7 , L_12 ) ;
F_42 ( V_85 ) ;
return NULL ;
}
memcpy ( ( void * ) V_85 -> V_90 , ( void * ) V_87 -> V_93 , V_87 -> V_10 ) ;
if ( V_25 -> V_84 ) {
V_31 = F_28 ( V_25 , 0 ) ;
if ( V_31 < 0 )
goto V_94;
}
V_31 = V_25 -> V_32 -> V_89 ( V_85 ) ;
if ( V_31 < 0 ) {
F_6 ( V_25 -> V_7 , L_13 , V_31 ) ;
goto V_95;
}
if ( V_25 -> V_84 )
F_34 ( V_25 ) ;
F_43 ( & V_25 -> V_96 ) ;
F_44 ( & V_85 -> V_36 , & V_25 -> V_97 ) ;
F_45 ( & V_25 -> V_96 ) ;
return V_85 ;
V_95:
if ( V_25 -> V_84 )
F_34 ( V_25 ) ;
V_94:
F_46 ( V_25 -> V_53 , V_85 -> V_10 ,
V_85 -> V_90 ,
V_85 -> V_91 ) ;
V_85 -> V_90 = NULL ;
F_42 ( V_85 ) ;
return NULL ;
}
int F_47 ( struct V_85 * V_85 )
{
struct V_5 * V_25 = V_85 -> V_25 ;
int V_39 ;
F_4 ( V_25 -> V_7 , L_14 ) ;
V_39 = V_25 -> V_32 -> V_89 ( V_85 ) ;
if ( V_39 < 0 )
F_6 ( V_25 -> V_7 , L_13 , V_39 ) ;
return V_39 ;
}
void F_48 ( struct V_85 * V_85 )
{
struct V_5 * V_25 = V_85 -> V_25 ;
struct V_98 * V_99 , * V_100 ;
struct V_101 * V_102 , * V_103 ;
F_4 ( V_25 -> V_7 , L_15 ) ;
F_43 ( & V_25 -> V_96 ) ;
F_12 (module, mtmp, &dsp->module_list, list) {
if ( V_99 -> V_85 == V_85 ) {
F_12 (runtime, rtmp, &module->runtime_list, list) {
F_10 ( V_25 , & V_102 -> V_27 ) ;
F_13 ( & V_102 -> V_36 ) ;
F_42 ( V_102 ) ;
}
F_10 ( V_25 , & V_99 -> V_27 ) ;
F_13 ( & V_99 -> V_36 ) ;
F_42 ( V_99 ) ;
}
}
F_10 ( V_25 , & V_25 -> V_104 ) ;
F_45 ( & V_25 -> V_96 ) ;
}
void F_49 ( struct V_85 * V_85 )
{
struct V_5 * V_25 = V_85 -> V_25 ;
F_43 ( & V_25 -> V_96 ) ;
F_13 ( & V_85 -> V_36 ) ;
F_45 ( & V_25 -> V_96 ) ;
if ( V_85 -> V_90 )
F_46 ( V_25 -> V_53 , V_85 -> V_10 , V_85 -> V_90 ,
V_85 -> V_91 ) ;
F_42 ( V_85 ) ;
}
void F_50 ( struct V_5 * V_25 )
{
struct V_85 * V_85 , * V_105 ;
F_43 ( & V_25 -> V_96 ) ;
F_12 (sst_fw, t, &dsp->fw_list, list) {
F_13 ( & V_85 -> V_36 ) ;
F_46 ( V_25 -> V_7 , V_85 -> V_10 , V_85 -> V_90 ,
V_85 -> V_91 ) ;
F_42 ( V_85 ) ;
}
F_45 ( & V_25 -> V_96 ) ;
}
struct V_98 * F_51 ( struct V_85 * V_85 ,
struct V_106 * V_107 , void * V_88 )
{
struct V_5 * V_25 = V_85 -> V_25 ;
struct V_98 * V_98 ;
V_98 = F_40 ( sizeof( * V_98 ) , V_47 ) ;
if ( V_98 == NULL )
return NULL ;
V_98 -> V_108 = V_107 -> V_108 ;
V_98 -> V_25 = V_25 ;
V_98 -> V_85 = V_85 ;
V_98 -> V_109 = V_107 -> V_109 ;
V_98 -> V_110 = V_107 -> V_110 ;
V_98 -> V_111 = V_107 -> V_111 ;
V_98 -> V_112 = V_113 ;
F_52 ( & V_98 -> V_27 ) ;
F_52 ( & V_98 -> V_114 ) ;
F_43 ( & V_25 -> V_96 ) ;
F_44 ( & V_98 -> V_36 , & V_25 -> V_35 ) ;
F_45 ( & V_25 -> V_96 ) ;
return V_98 ;
}
void F_53 ( struct V_98 * V_98 )
{
struct V_5 * V_25 = V_98 -> V_25 ;
F_43 ( & V_25 -> V_96 ) ;
F_13 ( & V_98 -> V_36 ) ;
F_45 ( & V_25 -> V_96 ) ;
F_42 ( V_98 ) ;
}
struct V_101 * F_54 ( struct V_98 * V_99 ,
int V_108 , void * V_88 )
{
struct V_5 * V_25 = V_99 -> V_25 ;
struct V_101 * V_102 ;
V_102 = F_40 ( sizeof( * V_102 ) , V_47 ) ;
if ( V_102 == NULL )
return NULL ;
V_102 -> V_108 = V_108 ;
V_102 -> V_25 = V_25 ;
V_102 -> V_99 = V_99 ;
F_52 ( & V_102 -> V_27 ) ;
F_43 ( & V_25 -> V_96 ) ;
F_44 ( & V_102 -> V_36 , & V_99 -> V_114 ) ;
F_45 ( & V_25 -> V_96 ) ;
return V_102 ;
}
void F_55 ( struct V_101 * V_102 )
{
struct V_5 * V_25 = V_102 -> V_25 ;
F_43 ( & V_25 -> V_96 ) ;
F_13 ( & V_102 -> V_36 ) ;
F_45 ( & V_25 -> V_96 ) ;
F_42 ( V_102 ) ;
}
static struct V_28 * F_56 ( struct V_5 * V_25 ,
struct V_115 * V_116 )
{
struct V_28 * V_29 ;
F_11 (block, &dsp->free_block_list, list) {
if ( V_29 -> type == V_116 -> type && V_29 -> V_38 == V_116 -> V_38 )
return V_29 ;
}
return NULL ;
}
static int F_57 ( struct V_5 * V_25 ,
struct V_115 * V_116 , struct V_26 * V_27 )
{
struct V_26 V_30 = F_58 ( V_30 ) ;
struct V_28 * V_29 ;
T_2 V_117 = V_118 ;
int V_10 = V_116 -> V_10 , V_38 = V_116 -> V_38 ;
while ( V_116 -> V_10 > 0 ) {
V_29 = F_56 ( V_25 , V_116 ) ;
if ( ! V_29 ) {
F_59 ( & V_30 , & V_25 -> V_37 ) ;
V_116 -> V_10 = V_10 ;
V_116 -> V_38 = V_38 ;
return - V_48 ;
}
F_60 ( & V_29 -> V_36 , & V_30 ) ;
V_116 -> V_38 += V_29 -> V_10 ;
V_116 -> V_10 -= V_29 -> V_10 ;
}
V_116 -> V_10 = V_10 ;
V_116 -> V_38 = V_38 ;
F_11 (block, &tmp, list) {
if ( V_29 -> V_38 < V_117 )
V_117 = V_29 -> V_38 ;
F_44 ( & V_29 -> V_35 , V_27 ) ;
F_4 ( V_25 -> V_7 , L_16 ,
V_29 -> type , V_29 -> V_34 , V_29 -> V_38 ) ;
}
F_59 ( & V_30 , & V_25 -> V_119 ) ;
return 0 ;
}
static int F_61 ( struct V_5 * V_25 , struct V_115 * V_116 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 , * V_30 ;
int V_39 = 0 ;
if ( V_116 -> V_10 == 0 )
return 0 ;
F_12 (block, tmp, &dsp->free_block_list, list) {
if ( V_29 -> type != V_116 -> type )
continue;
if ( V_116 -> V_10 > V_29 -> V_10 )
continue;
V_116 -> V_38 = V_29 -> V_38 ;
V_29 -> V_120 = V_116 -> V_10 % V_29 -> V_10 ;
F_44 ( & V_29 -> V_35 , V_27 ) ;
F_14 ( & V_29 -> V_36 , & V_25 -> V_119 ) ;
F_4 ( V_25 -> V_7 , L_16 ,
V_29 -> type , V_29 -> V_34 , V_29 -> V_38 ) ;
return 0 ;
}
F_12 (block, tmp, &dsp->free_block_list, list) {
if ( V_29 -> type != V_116 -> type )
continue;
if ( V_116 -> V_10 > V_29 -> V_10 ) {
V_116 -> V_38 = V_29 -> V_38 ;
V_39 = F_57 ( V_25 , V_116 , V_27 ) ;
if ( V_39 == 0 )
return V_39 ;
}
}
return - V_48 ;
}
int F_62 ( struct V_5 * V_25 , struct V_115 * V_116 ,
struct V_26 * V_27 )
{
int V_39 ;
F_4 ( V_25 -> V_7 , L_17 ,
V_116 -> V_10 , V_116 -> V_38 , V_116 -> type ) ;
F_43 ( & V_25 -> V_96 ) ;
V_39 = F_61 ( V_25 , V_116 , V_27 ) ;
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 , L_18 , V_39 ) ;
goto V_121;
}
V_39 = F_15 ( V_25 , V_27 ) ;
if ( V_39 < 0 )
F_6 ( V_25 -> V_7 , L_19 ) ;
V_121:
F_45 ( & V_25 -> V_96 ) ;
return V_39 ;
}
int F_63 ( struct V_5 * V_25 , struct V_26 * V_27 )
{
F_43 ( & V_25 -> V_96 ) ;
F_10 ( V_25 , V_27 ) ;
F_45 ( & V_25 -> V_96 ) ;
return 0 ;
}
static int F_64 ( struct V_5 * V_25 , struct V_115 * V_116 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 , * V_30 ;
struct V_115 V_122 = * V_116 ;
T_2 V_79 = V_116 -> V_38 + V_116 -> V_10 , V_123 ;
int V_31 ;
if ( V_116 -> type != V_124 && V_116 -> type != V_125 )
return 0 ;
F_12 (block, tmp, block_list, module_list) {
if ( V_29 -> type != V_116 -> type )
continue;
V_123 = V_29 -> V_38 + V_29 -> V_10 ;
if ( V_116 -> V_38 >= V_29 -> V_38 && V_79 <= V_123 )
return 0 ;
if ( V_116 -> V_38 >= V_29 -> V_38 && V_116 -> V_38 < V_123 ) {
V_122 . V_10 -= V_123 - V_116 -> V_38 ;
V_122 . V_38 = V_123 ;
V_31 = F_57 ( V_25 , & V_122 , V_27 ) ;
if ( V_31 < 0 )
return - V_48 ;
return 0 ;
}
}
F_12 (block, tmp, &dsp->free_block_list, list) {
V_123 = V_29 -> V_38 + V_29 -> V_10 ;
if ( V_29 -> type != V_116 -> type )
continue;
if ( V_116 -> V_38 >= V_29 -> V_38 && V_79 <= V_123 ) {
F_14 ( & V_29 -> V_36 , & V_25 -> V_119 ) ;
F_44 ( & V_29 -> V_35 , V_27 ) ;
F_4 ( V_25 -> V_7 , L_16 ,
V_29 -> type , V_29 -> V_34 , V_29 -> V_38 ) ;
return 0 ;
}
if ( V_116 -> V_38 >= V_29 -> V_38 && V_116 -> V_38 < V_123 ) {
F_14 ( & V_29 -> V_36 , & V_25 -> V_119 ) ;
F_44 ( & V_29 -> V_35 , V_27 ) ;
V_122 . V_10 -= V_123 - V_116 -> V_38 ;
V_122 . V_38 = V_123 ;
V_31 = F_57 ( V_25 , & V_122 , V_27 ) ;
if ( V_31 < 0 )
return - V_48 ;
return 0 ;
}
}
return - V_48 ;
}
int F_65 ( struct V_98 * V_99 )
{
struct V_5 * V_25 = V_99 -> V_25 ;
struct V_85 * V_85 = V_99 -> V_85 ;
struct V_115 V_116 ;
int V_39 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_10 = V_99 -> V_10 ;
V_116 . type = V_99 -> type ;
V_116 . V_38 = V_99 -> V_38 ;
F_4 ( V_25 -> V_7 , L_17 ,
V_116 . V_10 , V_116 . V_38 , V_116 . type ) ;
F_43 ( & V_25 -> V_96 ) ;
V_39 = F_64 ( V_25 , & V_116 , & V_99 -> V_27 ) ;
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 ,
L_20 ,
V_99 -> V_38 , V_99 -> V_10 ) ;
F_45 ( & V_25 -> V_96 ) ;
return - V_48 ;
}
V_39 = F_15 ( V_25 , & V_99 -> V_27 ) ;
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 , L_21 ) ;
goto V_31;
}
if ( V_25 -> V_84 ) {
V_39 = F_8 ( V_25 ,
V_25 -> V_76 . V_77 + V_99 -> V_38 ,
V_85 -> V_91 + V_99 -> V_126 ,
V_99 -> V_10 ) ;
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 , L_22 ) ;
goto V_31;
}
} else
F_1 ( V_25 -> V_76 . V_127 + V_99 -> V_38 , V_99 -> V_93 ,
V_99 -> V_10 ) ;
F_45 ( & V_25 -> V_96 ) ;
return V_39 ;
V_31:
F_10 ( V_25 , & V_99 -> V_27 ) ;
F_45 ( & V_25 -> V_96 ) ;
return V_39 ;
}
int F_66 ( struct V_98 * V_99 )
{
struct V_5 * V_25 = V_99 -> V_25 ;
F_43 ( & V_25 -> V_96 ) ;
F_10 ( V_25 , & V_99 -> V_27 ) ;
F_45 ( & V_25 -> V_96 ) ;
return 0 ;
}
int F_67 ( struct V_101 * V_102 ,
int V_38 )
{
struct V_5 * V_25 = V_102 -> V_25 ;
struct V_98 * V_99 = V_102 -> V_99 ;
struct V_115 V_116 ;
int V_39 ;
if ( V_99 -> V_110 == 0 )
return 0 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_10 = V_99 -> V_110 ;
V_116 . type = V_125 ;
F_43 ( & V_25 -> V_96 ) ;
if ( V_38 != 0 ) {
V_116 . V_38 = V_38 ;
F_4 ( V_25 -> V_7 , L_23 ,
V_116 . V_10 , V_116 . type , V_116 . V_38 ) ;
V_39 = F_64 ( V_25 , & V_116 , & V_102 -> V_27 ) ;
} else {
F_4 ( V_25 -> V_7 , L_24 ,
V_116 . V_10 , V_116 . type ) ;
V_39 = F_61 ( V_25 , & V_116 , & V_102 -> V_27 ) ;
}
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 ,
L_25 ,
V_99 -> V_110 ) ;
F_45 ( & V_25 -> V_96 ) ;
return - V_48 ;
}
V_102 -> V_128 = V_116 . V_38 ;
V_39 = F_15 ( V_25 , & V_102 -> V_27 ) ;
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 , L_26 ) ;
goto V_31;
}
F_45 ( & V_25 -> V_96 ) ;
return V_39 ;
V_31:
F_10 ( V_25 , & V_99 -> V_27 ) ;
F_45 ( & V_25 -> V_96 ) ;
return V_39 ;
}
int F_68 ( struct V_101 * V_102 )
{
struct V_5 * V_25 = V_102 -> V_25 ;
F_43 ( & V_25 -> V_96 ) ;
F_10 ( V_25 , & V_102 -> V_27 ) ;
F_45 ( & V_25 -> V_96 ) ;
return 0 ;
}
int F_69 ( struct V_101 * V_102 ,
struct V_129 * V_130 )
{
struct V_5 * V_25 = V_102 -> V_25 ;
struct V_98 * V_99 = V_102 -> V_99 ;
int V_39 = 0 ;
F_4 ( V_25 -> V_7 , L_27 ,
V_102 -> V_108 , V_102 -> V_128 ,
V_99 -> V_110 ) ;
V_130 -> V_131 = F_41 ( V_25 -> V_53 ,
V_99 -> V_110 ,
& V_130 -> V_132 , V_92 | V_47 ) ;
if ( ! V_130 -> V_131 ) {
F_6 ( V_25 -> V_7 , L_28 ) ;
return - V_48 ;
}
F_43 ( & V_25 -> V_96 ) ;
if ( V_25 -> V_84 ) {
V_39 = F_28 ( V_25 , 0 ) ;
if ( V_39 < 0 )
goto V_31;
V_39 = F_9 ( V_25 , V_130 -> V_132 ,
V_25 -> V_76 . V_77 + V_102 -> V_128 ,
V_99 -> V_110 ) ;
F_34 ( V_25 ) ;
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 , L_29 ) ;
goto V_31;
}
} else
F_1 ( V_130 -> V_131 , V_25 -> V_76 . V_127 +
V_102 -> V_128 ,
V_99 -> V_110 ) ;
V_31:
F_45 ( & V_25 -> V_96 ) ;
return V_39 ;
}
int F_70 ( struct V_101 * V_102 ,
struct V_129 * V_130 )
{
struct V_5 * V_25 = V_102 -> V_25 ;
struct V_98 * V_99 = V_102 -> V_99 ;
int V_39 = 0 ;
F_4 ( V_25 -> V_7 , L_30 ,
V_102 -> V_108 , V_102 -> V_128 ,
V_99 -> V_110 ) ;
F_43 ( & V_25 -> V_96 ) ;
if ( ! V_130 -> V_131 ) {
F_71 ( V_25 -> V_7 , L_31 ) ;
goto V_31;
}
if ( V_25 -> V_84 ) {
V_39 = F_28 ( V_25 , 0 ) ;
if ( V_39 < 0 )
goto V_31;
V_39 = F_8 ( V_25 ,
V_25 -> V_76 . V_77 + V_102 -> V_128 ,
V_130 -> V_132 , V_99 -> V_110 ) ;
F_34 ( V_25 ) ;
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 , L_22 ) ;
goto V_31;
}
} else
F_1 ( V_25 -> V_76 . V_127 + V_102 -> V_128 ,
V_130 -> V_131 , V_99 -> V_110 ) ;
F_46 ( V_25 -> V_53 , V_99 -> V_110 ,
V_130 -> V_131 , V_130 -> V_132 ) ;
V_130 -> V_131 = NULL ;
V_31:
F_45 ( & V_25 -> V_96 ) ;
return V_39 ;
}
struct V_28 * F_72 ( struct V_5 * V_25 , T_2 V_38 ,
T_2 V_10 , enum V_133 type , struct V_134 * V_32 , T_2 V_34 ,
void * V_88 )
{
struct V_28 * V_29 ;
V_29 = F_40 ( sizeof( * V_29 ) , V_47 ) ;
if ( V_29 == NULL )
return NULL ;
V_29 -> V_38 = V_38 ;
V_29 -> V_10 = V_10 ;
V_29 -> V_34 = V_34 ;
V_29 -> type = type ;
V_29 -> V_25 = V_25 ;
V_29 -> V_88 = V_88 ;
V_29 -> V_32 = V_32 ;
F_43 ( & V_25 -> V_96 ) ;
F_44 ( & V_29 -> V_36 , & V_25 -> V_37 ) ;
F_45 ( & V_25 -> V_96 ) ;
return V_29 ;
}
void F_73 ( struct V_5 * V_25 )
{
struct V_28 * V_29 , * V_30 ;
F_43 ( & V_25 -> V_96 ) ;
F_12 (block, tmp, &dsp->used_block_list, list) {
F_13 ( & V_29 -> V_36 ) ;
F_42 ( V_29 ) ;
}
F_12 (block, tmp, &dsp->free_block_list, list) {
F_13 ( & V_29 -> V_36 ) ;
F_42 ( V_29 ) ;
}
F_45 ( & V_25 -> V_96 ) ;
}
int F_74 ( struct V_5 * V_25 )
{
struct V_98 * V_99 ;
struct V_115 V_116 ;
int V_39 ;
F_43 ( & V_25 -> V_96 ) ;
V_25 -> V_109 = 0 ;
F_11 (module, &dsp->module_list, list) {
F_4 ( V_25 -> V_7 , L_32 ,
V_99 -> V_108 , V_99 -> V_109 ) ;
if ( V_25 -> V_109 < V_99 -> V_109 )
V_25 -> V_109 = V_99 -> V_109 ;
}
F_4 ( V_25 -> V_7 , L_33 ,
V_25 -> V_109 ) ;
if ( V_25 -> V_109 == 0 ) {
F_71 ( V_25 -> V_7 , L_34 ) ;
F_45 ( & V_25 -> V_96 ) ;
return 0 ;
}
F_4 ( V_25 -> V_7 , L_35 ) ;
V_116 . V_10 = V_25 -> V_109 ;
V_116 . type = V_125 ;
if ( V_25 -> V_135 != 0 ) {
F_4 ( V_25 -> V_7 , L_36 ,
V_116 . V_10 , V_116 . type , V_116 . V_38 ) ;
V_116 . V_38 = V_25 -> V_135 ;
V_39 = F_64 ( V_25 , & V_116 , & V_25 -> V_104 ) ;
} else {
F_4 ( V_25 -> V_7 , L_37 ,
V_116 . V_10 , V_116 . type ) ;
V_116 . V_38 = 0 ;
V_39 = F_61 ( V_25 , & V_116 , & V_25 -> V_104 ) ;
}
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 , L_38 ) ;
F_45 ( & V_25 -> V_96 ) ;
return V_39 ;
}
V_39 = F_15 ( V_25 , & V_25 -> V_104 ) ;
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 , L_39 ) ;
F_45 ( & V_25 -> V_96 ) ;
return V_39 ;
}
V_25 -> V_135 = V_116 . V_38 ;
F_45 ( & V_25 -> V_96 ) ;
return V_25 -> V_109 ;
}
void F_75 ( struct V_5 * V_25 )
{
F_43 ( & V_25 -> V_96 ) ;
F_10 ( V_25 , & V_25 -> V_104 ) ;
F_45 ( & V_25 -> V_96 ) ;
}
struct V_98 * F_76 ( struct V_5 * V_25 , T_2 V_108 )
{
struct V_98 * V_99 ;
F_43 ( & V_25 -> V_96 ) ;
F_11 (module, &dsp->module_list, list) {
if ( V_99 -> V_108 == V_108 ) {
F_45 ( & V_25 -> V_96 ) ;
return V_99 ;
}
}
F_45 ( & V_25 -> V_96 ) ;
return NULL ;
}
struct V_101 * F_77 (
struct V_98 * V_99 , T_2 V_108 )
{
struct V_101 * V_102 ;
struct V_5 * V_25 = V_99 -> V_25 ;
F_43 ( & V_25 -> V_96 ) ;
F_11 (runtime, &module->runtime_list, list) {
if ( V_102 -> V_108 == V_108 ) {
F_45 ( & V_25 -> V_96 ) ;
return V_102 ;
}
}
F_45 ( & V_25 -> V_96 ) ;
return NULL ;
}
T_2 F_78 ( struct V_5 * V_25 , T_2 V_38 ,
enum V_133 type )
{
switch ( type ) {
case V_124 :
return V_38 - V_25 -> V_76 . V_136 +
V_25 -> V_76 . V_137 ;
case V_125 :
return V_38 - V_25 -> V_76 . V_138 +
V_25 -> V_76 . V_139 ;
default:
return 0 ;
}
}
