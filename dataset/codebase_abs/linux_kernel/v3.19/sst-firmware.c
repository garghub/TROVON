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
V_31 = F_24 ( V_46 , & V_50 ) ;
if ( V_31 )
return F_18 ( V_31 ) ;
return V_46 ;
}
static void F_25 ( struct V_42 * V_46 )
{
F_26 ( V_46 ) ;
}
static bool F_27 ( struct V_51 * V_52 , void * V_53 )
{
struct V_5 * V_25 = (struct V_5 * ) V_53 ;
return V_52 -> V_17 -> V_7 == V_25 -> V_54 ;
}
int F_28 ( struct V_5 * V_25 , int V_55 )
{
struct V_13 * V_14 = V_25 -> V_14 ;
struct V_56 V_57 ;
T_5 V_58 ;
int V_39 ;
F_29 ( V_58 ) ;
F_30 ( V_59 , V_58 ) ;
F_30 ( V_60 , V_58 ) ;
V_14 -> V_15 = F_31 ( V_58 , F_27 , V_25 ) ;
if ( V_14 -> V_15 == NULL ) {
F_6 ( V_25 -> V_7 , L_7 ) ;
return - V_61 ;
}
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_62 = V_63 ;
V_57 . V_64 =
V_57 . V_65 = V_66 ;
V_57 . V_67 = V_57 . V_68 = V_69 ;
V_39 = F_32 ( V_14 -> V_15 , & V_57 ) ;
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
struct V_70 * V_70 = V_6 -> V_71 ;
struct V_13 * V_14 ;
struct V_43 V_44 ;
const char * V_72 ;
int V_39 = 0 ;
switch ( V_6 -> V_71 -> V_73 ) {
case V_74 :
V_72 = L_9 ;
break;
case V_75 :
V_72 = L_10 ;
break;
default:
F_6 ( V_6 -> V_7 , L_11 ,
V_6 -> V_71 -> V_73 ) ;
return - V_20 ;
}
V_14 = F_17 ( V_6 -> V_7 , sizeof( struct V_13 ) , V_47 ) ;
if ( ! V_14 )
return - V_48 ;
V_14 -> V_6 = V_6 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_76 = V_6 -> V_77 . V_78 + V_70 -> V_79 ;
V_44 . V_80 = V_6 -> V_77 . V_78 + V_70 -> V_79 + V_70 -> V_81 - 1 ;
V_44 . V_82 = V_83 ;
V_14 -> V_46 = F_16 ( V_6 -> V_54 , & V_44 , V_70 -> V_45 ) ;
if ( F_20 ( V_14 -> V_46 ) ) {
F_6 ( V_6 -> V_7 , L_12 ) ;
V_39 = F_36 ( V_14 -> V_46 ) ;
goto V_84;
}
V_6 -> V_14 = V_14 ;
V_6 -> V_85 = true ;
return 0 ;
V_84:
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
struct V_86 * F_39 ( struct V_5 * V_25 ,
const struct V_87 * V_88 , void * V_89 )
{
struct V_86 * V_86 ;
int V_31 ;
if ( ! V_25 -> V_32 -> V_90 )
return NULL ;
V_86 = F_40 ( sizeof( * V_86 ) , V_47 ) ;
if ( V_86 == NULL )
return NULL ;
V_86 -> V_25 = V_25 ;
V_86 -> V_89 = V_89 ;
V_86 -> V_10 = V_88 -> V_10 ;
V_86 -> V_91 = F_41 ( V_25 -> V_54 , V_86 -> V_10 ,
& V_86 -> V_92 , V_93 | V_47 ) ;
if ( ! V_86 -> V_91 ) {
F_6 ( V_25 -> V_7 , L_13 ) ;
F_42 ( V_86 ) ;
return NULL ;
}
memcpy ( ( void * ) V_86 -> V_91 , ( void * ) V_88 -> V_94 , V_88 -> V_10 ) ;
if ( V_25 -> V_85 ) {
V_31 = F_28 ( V_25 , 0 ) ;
if ( V_31 < 0 )
goto V_95;
}
V_31 = V_25 -> V_32 -> V_90 ( V_86 ) ;
if ( V_31 < 0 ) {
F_6 ( V_25 -> V_7 , L_14 , V_31 ) ;
goto V_96;
}
if ( V_25 -> V_85 )
F_34 ( V_25 ) ;
F_43 ( & V_25 -> V_97 ) ;
F_44 ( & V_86 -> V_36 , & V_25 -> V_98 ) ;
F_45 ( & V_25 -> V_97 ) ;
return V_86 ;
V_96:
if ( V_25 -> V_85 )
F_34 ( V_25 ) ;
V_95:
F_46 ( V_25 -> V_54 , V_86 -> V_10 ,
V_86 -> V_91 ,
V_86 -> V_92 ) ;
V_86 -> V_91 = NULL ;
F_42 ( V_86 ) ;
return NULL ;
}
int F_47 ( struct V_86 * V_86 )
{
struct V_5 * V_25 = V_86 -> V_25 ;
int V_39 ;
F_4 ( V_25 -> V_7 , L_15 ) ;
V_39 = V_25 -> V_32 -> V_90 ( V_86 ) ;
if ( V_39 < 0 )
F_6 ( V_25 -> V_7 , L_14 , V_39 ) ;
return V_39 ;
}
void F_48 ( struct V_86 * V_86 )
{
struct V_5 * V_25 = V_86 -> V_25 ;
struct V_99 * V_100 , * V_101 ;
struct V_102 * V_103 , * V_104 ;
F_4 ( V_25 -> V_7 , L_16 ) ;
F_43 ( & V_25 -> V_97 ) ;
F_12 (module, mtmp, &dsp->module_list, list) {
if ( V_100 -> V_86 == V_86 ) {
F_12 (runtime, rtmp, &module->runtime_list, list) {
F_10 ( V_25 , & V_103 -> V_27 ) ;
F_13 ( & V_103 -> V_36 ) ;
F_42 ( V_103 ) ;
}
F_10 ( V_25 , & V_100 -> V_27 ) ;
F_13 ( & V_100 -> V_36 ) ;
F_42 ( V_100 ) ;
}
}
F_10 ( V_25 , & V_25 -> V_105 ) ;
F_45 ( & V_25 -> V_97 ) ;
}
void F_49 ( struct V_86 * V_86 )
{
struct V_5 * V_25 = V_86 -> V_25 ;
F_43 ( & V_25 -> V_97 ) ;
F_13 ( & V_86 -> V_36 ) ;
F_45 ( & V_25 -> V_97 ) ;
if ( V_86 -> V_91 )
F_46 ( V_25 -> V_54 , V_86 -> V_10 , V_86 -> V_91 ,
V_86 -> V_92 ) ;
F_42 ( V_86 ) ;
}
void F_50 ( struct V_5 * V_25 )
{
struct V_86 * V_86 , * V_106 ;
F_43 ( & V_25 -> V_97 ) ;
F_12 (sst_fw, t, &dsp->fw_list, list) {
F_13 ( & V_86 -> V_36 ) ;
F_46 ( V_25 -> V_7 , V_86 -> V_10 , V_86 -> V_91 ,
V_86 -> V_92 ) ;
F_42 ( V_86 ) ;
}
F_45 ( & V_25 -> V_97 ) ;
}
struct V_99 * F_51 ( struct V_86 * V_86 ,
struct V_107 * V_108 , void * V_89 )
{
struct V_5 * V_25 = V_86 -> V_25 ;
struct V_99 * V_99 ;
V_99 = F_40 ( sizeof( * V_99 ) , V_47 ) ;
if ( V_99 == NULL )
return NULL ;
V_99 -> V_109 = V_108 -> V_109 ;
V_99 -> V_25 = V_25 ;
V_99 -> V_86 = V_86 ;
V_99 -> V_110 = V_108 -> V_110 ;
V_99 -> V_111 = V_108 -> V_111 ;
F_52 ( & V_99 -> V_27 ) ;
F_52 ( & V_99 -> V_112 ) ;
F_43 ( & V_25 -> V_97 ) ;
F_44 ( & V_99 -> V_36 , & V_25 -> V_35 ) ;
F_45 ( & V_25 -> V_97 ) ;
return V_99 ;
}
void F_53 ( struct V_99 * V_99 )
{
struct V_5 * V_25 = V_99 -> V_25 ;
F_43 ( & V_25 -> V_97 ) ;
F_13 ( & V_99 -> V_36 ) ;
F_45 ( & V_25 -> V_97 ) ;
F_42 ( V_99 ) ;
}
struct V_102 * F_54 ( struct V_99 * V_100 ,
int V_109 , void * V_89 )
{
struct V_5 * V_25 = V_100 -> V_25 ;
struct V_102 * V_103 ;
V_103 = F_40 ( sizeof( * V_103 ) , V_47 ) ;
if ( V_103 == NULL )
return NULL ;
V_103 -> V_109 = V_109 ;
V_103 -> V_25 = V_25 ;
V_103 -> V_100 = V_100 ;
F_52 ( & V_103 -> V_27 ) ;
F_43 ( & V_25 -> V_97 ) ;
F_44 ( & V_103 -> V_36 , & V_100 -> V_112 ) ;
F_45 ( & V_25 -> V_97 ) ;
return V_103 ;
}
void F_55 ( struct V_102 * V_103 )
{
struct V_5 * V_25 = V_103 -> V_25 ;
F_43 ( & V_25 -> V_97 ) ;
F_13 ( & V_103 -> V_36 ) ;
F_45 ( & V_25 -> V_97 ) ;
F_42 ( V_103 ) ;
}
static struct V_28 * F_56 ( struct V_5 * V_25 ,
struct V_113 * V_114 )
{
struct V_28 * V_29 ;
F_11 (block, &dsp->free_block_list, list) {
if ( V_29 -> type == V_114 -> type && V_29 -> V_38 == V_114 -> V_38 )
return V_29 ;
}
return NULL ;
}
static int F_57 ( struct V_5 * V_25 ,
struct V_113 * V_114 , struct V_26 * V_27 )
{
struct V_26 V_30 = F_58 ( V_30 ) ;
struct V_28 * V_29 ;
T_2 V_115 = V_116 ;
int V_10 = V_114 -> V_10 , V_38 = V_114 -> V_38 ;
while ( V_114 -> V_10 > 0 ) {
V_29 = F_56 ( V_25 , V_114 ) ;
if ( ! V_29 ) {
F_59 ( & V_30 , & V_25 -> V_37 ) ;
V_114 -> V_10 = V_10 ;
V_114 -> V_38 = V_38 ;
return - V_48 ;
}
F_60 ( & V_29 -> V_36 , & V_30 ) ;
V_114 -> V_38 += V_29 -> V_10 ;
V_114 -> V_10 -= V_29 -> V_10 ;
}
V_114 -> V_10 = V_10 ;
V_114 -> V_38 = V_38 ;
F_11 (block, &tmp, list) {
if ( V_29 -> V_38 < V_115 )
V_115 = V_29 -> V_38 ;
F_44 ( & V_29 -> V_35 , V_27 ) ;
F_4 ( V_25 -> V_7 , L_17 ,
V_29 -> type , V_29 -> V_34 , V_29 -> V_38 ) ;
}
F_59 ( & V_30 , & V_25 -> V_117 ) ;
return 0 ;
}
static int F_61 ( struct V_5 * V_25 , struct V_113 * V_114 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 , * V_30 ;
int V_39 = 0 ;
if ( V_114 -> V_10 == 0 )
return 0 ;
F_12 (block, tmp, &dsp->free_block_list, list) {
if ( V_29 -> type != V_114 -> type )
continue;
if ( V_114 -> V_10 > V_29 -> V_10 )
continue;
V_114 -> V_38 = V_29 -> V_38 ;
V_29 -> V_118 = V_114 -> V_10 % V_29 -> V_10 ;
F_44 ( & V_29 -> V_35 , V_27 ) ;
F_14 ( & V_29 -> V_36 , & V_25 -> V_117 ) ;
F_4 ( V_25 -> V_7 , L_17 ,
V_29 -> type , V_29 -> V_34 , V_29 -> V_38 ) ;
return 0 ;
}
F_12 (block, tmp, &dsp->free_block_list, list) {
if ( V_29 -> type != V_114 -> type )
continue;
if ( V_114 -> V_10 > V_29 -> V_10 ) {
V_114 -> V_38 = V_29 -> V_38 ;
V_39 = F_57 ( V_25 , V_114 , V_27 ) ;
if ( V_39 == 0 )
return V_39 ;
}
}
return - V_48 ;
}
int F_62 ( struct V_5 * V_25 , struct V_113 * V_114 ,
struct V_26 * V_27 )
{
int V_39 ;
F_4 ( V_25 -> V_7 , L_18 ,
V_114 -> V_10 , V_114 -> V_38 , V_114 -> type ) ;
F_43 ( & V_25 -> V_97 ) ;
V_39 = F_61 ( V_25 , V_114 , V_27 ) ;
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 , L_19 , V_39 ) ;
goto V_119;
}
V_39 = F_15 ( V_25 , V_27 ) ;
if ( V_39 < 0 )
F_6 ( V_25 -> V_7 , L_20 ) ;
V_119:
F_45 ( & V_25 -> V_97 ) ;
return V_39 ;
}
int F_63 ( struct V_5 * V_25 , struct V_26 * V_27 )
{
F_43 ( & V_25 -> V_97 ) ;
F_10 ( V_25 , V_27 ) ;
F_45 ( & V_25 -> V_97 ) ;
return 0 ;
}
static int F_64 ( struct V_5 * V_25 , struct V_113 * V_114 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 , * V_30 ;
struct V_113 V_120 = * V_114 ;
T_2 V_80 = V_114 -> V_38 + V_114 -> V_10 , V_121 ;
int V_31 ;
if ( V_114 -> type != V_122 && V_114 -> type != V_123 )
return 0 ;
F_12 (block, tmp, block_list, module_list) {
if ( V_29 -> type != V_114 -> type )
continue;
V_121 = V_29 -> V_38 + V_29 -> V_10 ;
if ( V_114 -> V_38 >= V_29 -> V_38 && V_80 <= V_121 )
return 0 ;
if ( V_114 -> V_38 >= V_29 -> V_38 && V_114 -> V_38 < V_121 ) {
V_120 . V_10 -= V_121 - V_114 -> V_38 ;
V_120 . V_38 = V_121 ;
V_31 = F_57 ( V_25 , & V_120 , V_27 ) ;
if ( V_31 < 0 )
return - V_48 ;
return 0 ;
}
}
F_12 (block, tmp, &dsp->free_block_list, list) {
V_121 = V_29 -> V_38 + V_29 -> V_10 ;
if ( V_29 -> type != V_114 -> type )
continue;
if ( V_114 -> V_38 >= V_29 -> V_38 && V_80 <= V_121 ) {
F_14 ( & V_29 -> V_36 , & V_25 -> V_117 ) ;
F_44 ( & V_29 -> V_35 , V_27 ) ;
F_4 ( V_25 -> V_7 , L_17 ,
V_29 -> type , V_29 -> V_34 , V_29 -> V_38 ) ;
return 0 ;
}
if ( V_114 -> V_38 >= V_29 -> V_38 && V_114 -> V_38 < V_121 ) {
F_14 ( & V_29 -> V_36 , & V_25 -> V_117 ) ;
F_44 ( & V_29 -> V_35 , V_27 ) ;
V_120 . V_10 -= V_121 - V_114 -> V_38 ;
V_120 . V_38 = V_121 ;
V_31 = F_57 ( V_25 , & V_120 , V_27 ) ;
if ( V_31 < 0 )
return - V_48 ;
return 0 ;
}
}
return - V_48 ;
}
int F_65 ( struct V_99 * V_100 )
{
struct V_5 * V_25 = V_100 -> V_25 ;
struct V_86 * V_86 = V_100 -> V_86 ;
struct V_113 V_114 ;
int V_39 ;
V_114 . V_10 = V_100 -> V_10 ;
V_114 . type = V_100 -> type ;
V_114 . V_38 = V_100 -> V_38 ;
F_4 ( V_25 -> V_7 , L_18 ,
V_114 . V_10 , V_114 . V_38 , V_114 . type ) ;
F_43 ( & V_25 -> V_97 ) ;
V_39 = F_64 ( V_25 , & V_114 , & V_100 -> V_27 ) ;
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 ,
L_21 ,
V_100 -> V_38 , V_100 -> V_10 ) ;
F_45 ( & V_25 -> V_97 ) ;
return - V_48 ;
}
V_39 = F_15 ( V_25 , & V_100 -> V_27 ) ;
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 , L_22 ) ;
goto V_31;
}
if ( V_25 -> V_85 ) {
V_39 = F_8 ( V_25 ,
V_25 -> V_77 . V_78 + V_100 -> V_38 ,
V_86 -> V_92 + V_100 -> V_124 ,
V_100 -> V_10 ) ;
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 , L_23 ) ;
goto V_31;
}
} else
F_1 ( V_25 -> V_77 . V_125 + V_100 -> V_38 , V_100 -> V_94 ,
V_100 -> V_10 ) ;
F_45 ( & V_25 -> V_97 ) ;
return V_39 ;
V_31:
F_10 ( V_25 , & V_100 -> V_27 ) ;
F_45 ( & V_25 -> V_97 ) ;
return V_39 ;
}
int F_66 ( struct V_99 * V_100 )
{
struct V_5 * V_25 = V_100 -> V_25 ;
F_43 ( & V_25 -> V_97 ) ;
F_10 ( V_25 , & V_100 -> V_27 ) ;
F_45 ( & V_25 -> V_97 ) ;
return 0 ;
}
int F_67 ( struct V_102 * V_103 ,
int V_38 )
{
struct V_5 * V_25 = V_103 -> V_25 ;
struct V_99 * V_100 = V_103 -> V_100 ;
struct V_113 V_114 ;
int V_39 ;
if ( V_100 -> V_111 == 0 )
return 0 ;
V_114 . V_10 = V_100 -> V_111 ;
V_114 . type = V_123 ;
F_43 ( & V_25 -> V_97 ) ;
if ( V_38 != 0 ) {
V_114 . V_38 = V_38 ;
F_4 ( V_25 -> V_7 , L_24 ,
V_114 . V_10 , V_114 . type , V_114 . V_38 ) ;
V_39 = F_64 ( V_25 , & V_114 , & V_103 -> V_27 ) ;
} else {
F_4 ( V_25 -> V_7 , L_25 ,
V_114 . V_10 , V_114 . type ) ;
V_39 = F_61 ( V_25 , & V_114 , & V_103 -> V_27 ) ;
}
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 ,
L_26 ,
V_100 -> V_111 ) ;
F_45 ( & V_25 -> V_97 ) ;
return - V_48 ;
}
V_103 -> V_126 = V_114 . V_38 ;
V_39 = F_15 ( V_25 , & V_103 -> V_27 ) ;
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 , L_27 ) ;
goto V_31;
}
F_45 ( & V_25 -> V_97 ) ;
return V_39 ;
V_31:
F_10 ( V_25 , & V_100 -> V_27 ) ;
F_45 ( & V_25 -> V_97 ) ;
return V_39 ;
}
int F_68 ( struct V_102 * V_103 )
{
struct V_5 * V_25 = V_103 -> V_25 ;
F_43 ( & V_25 -> V_97 ) ;
F_10 ( V_25 , & V_103 -> V_27 ) ;
F_45 ( & V_25 -> V_97 ) ;
return 0 ;
}
int F_69 ( struct V_102 * V_103 ,
struct V_127 * V_128 )
{
struct V_5 * V_25 = V_103 -> V_25 ;
struct V_99 * V_100 = V_103 -> V_100 ;
int V_39 = 0 ;
F_4 ( V_25 -> V_7 , L_28 ,
V_103 -> V_109 , V_103 -> V_126 ,
V_100 -> V_111 ) ;
V_128 -> V_129 = F_41 ( V_25 -> V_54 ,
V_100 -> V_111 ,
& V_128 -> V_130 , V_93 | V_47 ) ;
if ( ! V_128 -> V_129 ) {
F_6 ( V_25 -> V_7 , L_29 ) ;
return - V_48 ;
}
F_43 ( & V_25 -> V_97 ) ;
if ( V_25 -> V_85 ) {
V_39 = F_28 ( V_25 , 0 ) ;
if ( V_39 < 0 )
goto V_31;
V_39 = F_9 ( V_25 , V_128 -> V_130 ,
V_25 -> V_77 . V_78 + V_103 -> V_126 ,
V_100 -> V_111 ) ;
F_34 ( V_25 ) ;
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 , L_30 ) ;
goto V_31;
}
} else
F_1 ( V_128 -> V_129 , V_25 -> V_77 . V_125 +
V_103 -> V_126 ,
V_100 -> V_111 ) ;
V_31:
F_45 ( & V_25 -> V_97 ) ;
return V_39 ;
}
int F_70 ( struct V_102 * V_103 ,
struct V_127 * V_128 )
{
struct V_5 * V_25 = V_103 -> V_25 ;
struct V_99 * V_100 = V_103 -> V_100 ;
int V_39 = 0 ;
F_4 ( V_25 -> V_7 , L_31 ,
V_103 -> V_109 , V_103 -> V_126 ,
V_100 -> V_111 ) ;
F_43 ( & V_25 -> V_97 ) ;
if ( ! V_128 -> V_129 ) {
F_71 ( V_25 -> V_7 , L_32 ) ;
goto V_31;
}
if ( V_25 -> V_85 ) {
V_39 = F_28 ( V_25 , 0 ) ;
if ( V_39 < 0 )
goto V_31;
V_39 = F_8 ( V_25 ,
V_25 -> V_77 . V_78 + V_103 -> V_126 ,
V_128 -> V_130 , V_100 -> V_111 ) ;
F_34 ( V_25 ) ;
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 , L_23 ) ;
goto V_31;
}
} else
F_1 ( V_25 -> V_77 . V_125 + V_103 -> V_126 ,
V_128 -> V_129 , V_100 -> V_111 ) ;
F_46 ( V_25 -> V_54 , V_100 -> V_111 ,
V_128 -> V_129 , V_128 -> V_130 ) ;
V_128 -> V_129 = NULL ;
V_31:
F_45 ( & V_25 -> V_97 ) ;
return V_39 ;
}
struct V_28 * F_72 ( struct V_5 * V_25 , T_2 V_38 ,
T_2 V_10 , enum V_131 type , struct V_132 * V_32 , T_2 V_34 ,
void * V_89 )
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
V_29 -> V_89 = V_89 ;
V_29 -> V_32 = V_32 ;
F_43 ( & V_25 -> V_97 ) ;
F_44 ( & V_29 -> V_36 , & V_25 -> V_37 ) ;
F_45 ( & V_25 -> V_97 ) ;
return V_29 ;
}
void F_73 ( struct V_5 * V_25 )
{
struct V_28 * V_29 , * V_30 ;
F_43 ( & V_25 -> V_97 ) ;
F_12 (block, tmp, &dsp->used_block_list, list) {
F_13 ( & V_29 -> V_36 ) ;
F_42 ( V_29 ) ;
}
F_12 (block, tmp, &dsp->free_block_list, list) {
F_13 ( & V_29 -> V_36 ) ;
F_42 ( V_29 ) ;
}
F_45 ( & V_25 -> V_97 ) ;
}
int F_74 ( struct V_5 * V_25 )
{
struct V_99 * V_100 ;
struct V_113 V_114 ;
int V_39 ;
F_43 ( & V_25 -> V_97 ) ;
V_25 -> V_110 = 0 ;
F_11 (module, &dsp->module_list, list) {
F_4 ( V_25 -> V_7 , L_33 ,
V_100 -> V_109 , V_100 -> V_110 ) ;
if ( V_25 -> V_110 < V_100 -> V_110 )
V_25 -> V_110 = V_100 -> V_110 ;
}
F_4 ( V_25 -> V_7 , L_34 ,
V_25 -> V_110 ) ;
if ( V_25 -> V_110 == 0 ) {
F_71 ( V_25 -> V_7 , L_35 ) ;
F_45 ( & V_25 -> V_97 ) ;
return 0 ;
}
F_4 ( V_25 -> V_7 , L_36 ) ;
V_114 . V_10 = V_25 -> V_110 ;
V_114 . type = V_123 ;
if ( V_25 -> V_133 != 0 ) {
F_4 ( V_25 -> V_7 , L_37 ,
V_114 . V_10 , V_114 . type , V_114 . V_38 ) ;
V_114 . V_38 = V_25 -> V_133 ;
V_39 = F_64 ( V_25 , & V_114 , & V_25 -> V_105 ) ;
} else {
F_4 ( V_25 -> V_7 , L_38 ,
V_114 . V_10 , V_114 . type ) ;
V_114 . V_38 = 0 ;
V_39 = F_61 ( V_25 , & V_114 , & V_25 -> V_105 ) ;
}
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 , L_39 ) ;
F_45 ( & V_25 -> V_97 ) ;
return V_39 ;
}
V_39 = F_15 ( V_25 , & V_25 -> V_105 ) ;
if ( V_39 < 0 ) {
F_6 ( V_25 -> V_7 , L_40 ) ;
F_45 ( & V_25 -> V_97 ) ;
return V_39 ;
}
V_25 -> V_133 = V_114 . V_38 ;
F_45 ( & V_25 -> V_97 ) ;
return V_25 -> V_110 ;
}
void F_75 ( struct V_5 * V_25 )
{
F_43 ( & V_25 -> V_97 ) ;
F_10 ( V_25 , & V_25 -> V_105 ) ;
F_45 ( & V_25 -> V_97 ) ;
}
struct V_99 * F_76 ( struct V_5 * V_25 , T_2 V_109 )
{
struct V_99 * V_100 ;
F_43 ( & V_25 -> V_97 ) ;
F_11 (module, &dsp->module_list, list) {
if ( V_100 -> V_109 == V_109 ) {
F_45 ( & V_25 -> V_97 ) ;
return V_100 ;
}
}
F_45 ( & V_25 -> V_97 ) ;
return NULL ;
}
struct V_102 * F_77 (
struct V_99 * V_100 , T_2 V_109 )
{
struct V_102 * V_103 ;
struct V_5 * V_25 = V_100 -> V_25 ;
F_43 ( & V_25 -> V_97 ) ;
F_11 (runtime, &module->runtime_list, list) {
if ( V_103 -> V_109 == V_109 ) {
F_45 ( & V_25 -> V_97 ) ;
return V_103 ;
}
}
F_45 ( & V_25 -> V_97 ) ;
return NULL ;
}
T_2 F_78 ( struct V_5 * V_25 , T_2 V_38 ,
enum V_131 type )
{
switch ( type ) {
case V_122 :
return V_38 - V_25 -> V_77 . V_134 +
V_25 -> V_77 . V_135 ;
case V_123 :
return V_38 - V_25 -> V_77 . V_136 +
V_25 -> V_77 . V_137 ;
default:
return 0 ;
}
}
