static inline void F_1 ( volatile void T_1 * V_1 , void * V_2 , T_2 V_3 )
{
T_2 V_4 = 0 ;
int V_5 , V_6 , V_7 ;
const T_3 * V_8 = V_2 ;
V_6 = V_3 / 4 ;
V_7 = V_3 % 4 ;
F_2 ( ( void * ) V_1 , V_2 , V_6 ) ;
if ( V_7 ) {
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ )
V_4 |= ( T_2 ) * ( V_8 + V_6 * 4 + V_5 ) << ( V_5 * 8 ) ;
F_2 ( ( void * ) ( V_1 + V_6 * 4 ) , & V_4 , 1 ) ;
}
}
static void F_3 ( void * V_9 )
{
struct V_10 * V_11 = (struct V_10 * ) V_9 ;
F_4 ( V_11 -> V_12 , L_1 ) ;
}
static int F_5 ( struct V_10 * V_11 , T_4 V_13 ,
T_4 V_14 , T_5 V_15 )
{
struct V_16 * V_17 ;
struct V_18 * V_19 = V_11 -> V_19 ;
if ( V_19 -> V_20 == NULL ) {
F_6 ( V_11 -> V_12 , L_2 ) ;
return - V_21 ;
}
F_4 ( V_11 -> V_12 , L_3 ,
( unsigned long ) V_14 , ( unsigned long ) V_13 , V_15 ) ;
V_17 = V_19 -> V_20 -> V_22 -> V_23 ( V_19 -> V_20 , V_13 ,
V_14 , V_15 , V_24 ) ;
if ( ! V_17 ) {
F_6 ( V_11 -> V_12 , L_4 ) ;
return - V_25 ;
}
V_17 -> V_26 = F_3 ;
V_17 -> V_27 = V_11 ;
V_17 -> V_28 ( V_17 ) ;
F_7 ( V_17 ) ;
return 0 ;
}
int F_8 ( struct V_10 * V_11 , T_4 V_13 ,
T_4 V_14 , T_5 V_15 )
{
return F_5 ( V_11 , V_13 | V_29 ,
V_14 , V_15 ) ;
}
int F_9 ( struct V_10 * V_11 , T_4 V_13 ,
T_4 V_14 , T_5 V_15 )
{
return F_5 ( V_11 , V_13 ,
V_14 | V_29 , V_15 ) ;
}
static void F_10 ( struct V_10 * V_30 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 , * V_4 ;
int V_35 ;
F_11 (block, block_list, module_list) {
if ( V_34 -> V_36 && V_34 -> V_36 -> V_37 ) {
V_35 = V_34 -> V_36 -> V_37 ( V_34 ) ;
if ( V_35 < 0 )
F_6 ( V_30 -> V_12 ,
L_5 ,
V_34 -> type , V_34 -> V_38 ) ;
}
}
F_12 (block, tmp, block_list, module_list) {
F_13 ( & V_34 -> V_39 ) ;
F_14 ( & V_34 -> V_40 , & V_30 -> V_41 ) ;
F_4 ( V_30 -> V_12 , L_6 ,
V_34 -> type , V_34 -> V_38 , V_34 -> V_42 ) ;
}
}
static int F_15 ( struct V_10 * V_30 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 ;
int V_43 = 0 ;
F_11 (block, block_list, module_list) {
if ( V_34 -> V_36 && V_34 -> V_36 -> V_44 && ! V_34 -> V_45 ) {
V_43 = V_34 -> V_36 -> V_44 ( V_34 ) ;
if ( V_43 < 0 ) {
F_6 ( V_30 -> V_12 ,
L_5 ,
V_34 -> type , V_34 -> V_38 ) ;
goto V_35;
}
}
}
return V_43 ;
V_35:
F_11 (block, block_list, module_list) {
if ( V_34 -> V_36 && V_34 -> V_36 -> V_37 )
V_34 -> V_36 -> V_37 ( V_34 ) ;
}
return V_43 ;
}
static struct V_46 * F_16 ( struct V_22 * V_12 , struct V_47 * V_48 ,
int V_49 )
{
struct V_46 * V_50 ;
int V_35 ;
V_50 = F_17 ( V_12 , sizeof( * V_50 ) , V_51 ) ;
if ( ! V_50 )
return F_18 ( - V_52 ) ;
V_50 -> V_49 = V_49 ;
V_50 -> V_53 = F_19 ( V_12 , V_48 ) ;
if ( F_20 ( V_50 -> V_53 ) )
return F_21 ( V_50 -> V_53 ) ;
V_35 = F_22 ( V_12 , F_23 ( 31 ) ) ;
if ( V_35 )
return F_18 ( V_35 ) ;
V_50 -> V_12 = V_12 ;
V_35 = F_24 ( V_50 ) ;
if ( V_35 )
return F_18 ( V_35 ) ;
return V_50 ;
}
static void F_25 ( struct V_46 * V_50 )
{
F_26 ( V_50 ) ;
}
static bool F_27 ( struct V_54 * V_55 , void * V_56 )
{
struct V_10 * V_30 = (struct V_10 * ) V_56 ;
return V_55 -> V_22 -> V_12 == V_30 -> V_57 ;
}
int F_28 ( struct V_10 * V_30 , int V_58 )
{
struct V_18 * V_19 = V_30 -> V_19 ;
struct V_59 V_60 ;
T_6 V_61 ;
int V_43 ;
F_29 ( V_61 ) ;
F_30 ( V_62 , V_61 ) ;
F_30 ( V_63 , V_61 ) ;
V_19 -> V_20 = F_31 ( V_61 , F_27 , V_30 ) ;
if ( V_19 -> V_20 == NULL ) {
F_6 ( V_30 -> V_12 , L_7 ) ;
return - V_64 ;
}
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_65 = V_66 ;
V_60 . V_67 =
V_60 . V_68 = V_69 ;
V_60 . V_70 = V_60 . V_71 = V_72 ;
V_43 = F_32 ( V_19 -> V_20 , & V_60 ) ;
if ( V_43 ) {
F_6 ( V_30 -> V_12 , L_8 ,
V_43 ) ;
F_33 ( V_19 -> V_20 ) ;
V_19 -> V_20 = NULL ;
}
return V_43 ;
}
void F_34 ( struct V_10 * V_30 )
{
struct V_18 * V_19 = V_30 -> V_19 ;
if ( ! V_19 -> V_20 )
return;
F_33 ( V_19 -> V_20 ) ;
V_19 -> V_20 = NULL ;
}
int F_35 ( struct V_10 * V_11 )
{
struct V_73 * V_73 = V_11 -> V_74 ;
struct V_18 * V_19 ;
struct V_47 V_48 ;
const char * V_75 ;
int V_43 = 0 ;
if ( V_11 -> V_74 -> V_76 == - 1 )
return 0 ;
switch ( V_11 -> V_74 -> V_77 ) {
case V_78 :
V_75 = L_9 ;
break;
default:
F_6 ( V_11 -> V_12 , L_10 ,
V_11 -> V_74 -> V_77 ) ;
return - V_25 ;
}
V_19 = F_17 ( V_11 -> V_12 , sizeof( struct V_18 ) , V_51 ) ;
if ( ! V_19 )
return - V_52 ;
V_19 -> V_11 = V_11 ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_48 . V_79 = V_11 -> V_80 . V_81 + V_73 -> V_82 ;
V_48 . V_83 = V_11 -> V_80 . V_81 + V_73 -> V_82 + V_73 -> V_84 - 1 ;
V_48 . V_85 = V_86 ;
V_19 -> V_50 = F_16 ( V_11 -> V_57 , & V_48 , V_73 -> V_49 ) ;
if ( F_20 ( V_19 -> V_50 ) ) {
F_6 ( V_11 -> V_12 , L_11 ) ;
V_43 = F_36 ( V_19 -> V_50 ) ;
goto V_87;
}
V_11 -> V_19 = V_19 ;
V_11 -> V_88 = true ;
return 0 ;
V_87:
F_37 ( V_11 -> V_12 , V_19 ) ;
return V_43 ;
}
void F_38 ( struct V_18 * V_19 )
{
if ( V_19 == NULL )
return;
if ( V_19 -> V_20 )
F_33 ( V_19 -> V_20 ) ;
if ( V_19 -> V_50 )
F_25 ( V_19 -> V_50 ) ;
}
struct V_89 * F_39 ( struct V_10 * V_30 ,
const struct V_90 * V_91 , void * V_92 )
{
struct V_89 * V_89 ;
int V_35 ;
if ( ! V_30 -> V_36 -> V_93 )
return NULL ;
V_89 = F_40 ( sizeof( * V_89 ) , V_51 ) ;
if ( V_89 == NULL )
return NULL ;
V_89 -> V_30 = V_30 ;
V_89 -> V_92 = V_92 ;
V_89 -> V_15 = V_91 -> V_15 ;
V_89 -> V_94 = F_41 ( V_30 -> V_57 , V_89 -> V_15 ,
& V_89 -> V_95 , V_96 | V_51 ) ;
if ( ! V_89 -> V_94 ) {
F_6 ( V_30 -> V_12 , L_12 ) ;
F_42 ( V_89 ) ;
return NULL ;
}
memcpy ( ( void * ) V_89 -> V_94 , ( void * ) V_91 -> V_97 , V_91 -> V_15 ) ;
if ( V_30 -> V_88 ) {
V_35 = F_28 ( V_30 , 0 ) ;
if ( V_35 < 0 )
goto V_98;
}
V_35 = V_30 -> V_36 -> V_93 ( V_89 ) ;
if ( V_35 < 0 ) {
F_6 ( V_30 -> V_12 , L_13 , V_35 ) ;
goto V_99;
}
if ( V_30 -> V_88 )
F_34 ( V_30 ) ;
F_43 ( & V_30 -> V_100 ) ;
F_44 ( & V_89 -> V_40 , & V_30 -> V_101 ) ;
F_45 ( & V_30 -> V_100 ) ;
return V_89 ;
V_99:
if ( V_30 -> V_88 )
F_34 ( V_30 ) ;
V_98:
F_46 ( V_30 -> V_57 , V_89 -> V_15 ,
V_89 -> V_94 ,
V_89 -> V_95 ) ;
V_89 -> V_94 = NULL ;
F_42 ( V_89 ) ;
return NULL ;
}
int F_47 ( struct V_89 * V_89 )
{
struct V_10 * V_30 = V_89 -> V_30 ;
int V_43 ;
F_4 ( V_30 -> V_12 , L_14 ) ;
V_43 = V_30 -> V_36 -> V_93 ( V_89 ) ;
if ( V_43 < 0 )
F_6 ( V_30 -> V_12 , L_13 , V_43 ) ;
return V_43 ;
}
void F_48 ( struct V_89 * V_89 )
{
struct V_10 * V_30 = V_89 -> V_30 ;
struct V_102 * V_103 , * V_104 ;
struct V_105 * V_106 , * V_107 ;
F_4 ( V_30 -> V_12 , L_15 ) ;
F_43 ( & V_30 -> V_100 ) ;
F_12 (module, mtmp, &dsp->module_list, list) {
if ( V_103 -> V_89 == V_89 ) {
F_12 (runtime, rtmp, &module->runtime_list, list) {
F_10 ( V_30 , & V_106 -> V_32 ) ;
F_13 ( & V_106 -> V_40 ) ;
F_42 ( V_106 ) ;
}
F_10 ( V_30 , & V_103 -> V_32 ) ;
F_13 ( & V_103 -> V_40 ) ;
F_42 ( V_103 ) ;
}
}
F_10 ( V_30 , & V_30 -> V_108 ) ;
F_45 ( & V_30 -> V_100 ) ;
}
void F_49 ( struct V_89 * V_89 )
{
struct V_10 * V_30 = V_89 -> V_30 ;
F_43 ( & V_30 -> V_100 ) ;
F_13 ( & V_89 -> V_40 ) ;
F_45 ( & V_30 -> V_100 ) ;
if ( V_89 -> V_94 )
F_46 ( V_30 -> V_57 , V_89 -> V_15 , V_89 -> V_94 ,
V_89 -> V_95 ) ;
F_42 ( V_89 ) ;
}
void F_50 ( struct V_10 * V_30 )
{
struct V_89 * V_89 , * V_109 ;
F_43 ( & V_30 -> V_100 ) ;
F_12 (sst_fw, t, &dsp->fw_list, list) {
F_13 ( & V_89 -> V_40 ) ;
F_46 ( V_30 -> V_12 , V_89 -> V_15 , V_89 -> V_94 ,
V_89 -> V_95 ) ;
F_42 ( V_89 ) ;
}
F_45 ( & V_30 -> V_100 ) ;
}
struct V_102 * F_51 ( struct V_89 * V_89 ,
struct V_110 * V_111 , void * V_92 )
{
struct V_10 * V_30 = V_89 -> V_30 ;
struct V_102 * V_102 ;
V_102 = F_40 ( sizeof( * V_102 ) , V_51 ) ;
if ( V_102 == NULL )
return NULL ;
V_102 -> V_112 = V_111 -> V_112 ;
V_102 -> V_30 = V_30 ;
V_102 -> V_89 = V_89 ;
V_102 -> V_113 = V_111 -> V_113 ;
V_102 -> V_114 = V_111 -> V_114 ;
V_102 -> V_115 = V_111 -> V_115 ;
V_102 -> V_116 = V_117 ;
F_52 ( & V_102 -> V_32 ) ;
F_52 ( & V_102 -> V_118 ) ;
F_43 ( & V_30 -> V_100 ) ;
F_44 ( & V_102 -> V_40 , & V_30 -> V_39 ) ;
F_45 ( & V_30 -> V_100 ) ;
return V_102 ;
}
void F_53 ( struct V_102 * V_102 )
{
struct V_10 * V_30 = V_102 -> V_30 ;
F_43 ( & V_30 -> V_100 ) ;
F_13 ( & V_102 -> V_40 ) ;
F_45 ( & V_30 -> V_100 ) ;
F_42 ( V_102 ) ;
}
struct V_105 * F_54 ( struct V_102 * V_103 ,
int V_112 , void * V_92 )
{
struct V_10 * V_30 = V_103 -> V_30 ;
struct V_105 * V_106 ;
V_106 = F_40 ( sizeof( * V_106 ) , V_51 ) ;
if ( V_106 == NULL )
return NULL ;
V_106 -> V_112 = V_112 ;
V_106 -> V_30 = V_30 ;
V_106 -> V_103 = V_103 ;
F_52 ( & V_106 -> V_32 ) ;
F_43 ( & V_30 -> V_100 ) ;
F_44 ( & V_106 -> V_40 , & V_103 -> V_118 ) ;
F_45 ( & V_30 -> V_100 ) ;
return V_106 ;
}
void F_55 ( struct V_105 * V_106 )
{
struct V_10 * V_30 = V_106 -> V_30 ;
F_43 ( & V_30 -> V_100 ) ;
F_13 ( & V_106 -> V_40 ) ;
F_45 ( & V_30 -> V_100 ) ;
F_42 ( V_106 ) ;
}
static struct V_33 * F_56 ( struct V_10 * V_30 ,
struct V_119 * V_120 )
{
struct V_33 * V_34 ;
F_11 (block, &dsp->free_block_list, list) {
if ( V_34 -> type == V_120 -> type && V_34 -> V_42 == V_120 -> V_42 )
return V_34 ;
}
return NULL ;
}
static int F_57 ( struct V_10 * V_30 ,
struct V_119 * V_120 , struct V_31 * V_32 )
{
struct V_31 V_4 = F_58 ( V_4 ) ;
struct V_33 * V_34 ;
T_2 V_121 = V_122 ;
int V_15 = V_120 -> V_15 , V_42 = V_120 -> V_42 ;
while ( V_120 -> V_15 > 0 ) {
V_34 = F_56 ( V_30 , V_120 ) ;
if ( ! V_34 ) {
F_59 ( & V_4 , & V_30 -> V_41 ) ;
V_120 -> V_15 = V_15 ;
V_120 -> V_42 = V_42 ;
return - V_52 ;
}
F_60 ( & V_34 -> V_40 , & V_4 ) ;
V_120 -> V_42 += V_34 -> V_15 ;
V_120 -> V_15 -= V_34 -> V_15 ;
}
V_120 -> V_15 = V_15 ;
V_120 -> V_42 = V_42 ;
F_11 (block, &tmp, list) {
if ( V_34 -> V_42 < V_121 )
V_121 = V_34 -> V_42 ;
F_44 ( & V_34 -> V_39 , V_32 ) ;
F_4 ( V_30 -> V_12 , L_16 ,
V_34 -> type , V_34 -> V_38 , V_34 -> V_42 ) ;
}
F_59 ( & V_4 , & V_30 -> V_123 ) ;
return 0 ;
}
static int F_61 ( struct V_10 * V_30 , struct V_119 * V_120 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 , * V_4 ;
int V_43 = 0 ;
if ( V_120 -> V_15 == 0 )
return 0 ;
F_12 (block, tmp, &dsp->free_block_list, list) {
if ( V_34 -> type != V_120 -> type )
continue;
if ( V_120 -> V_15 > V_34 -> V_15 )
continue;
V_120 -> V_42 = V_34 -> V_42 ;
V_34 -> V_124 = V_120 -> V_15 % V_34 -> V_15 ;
F_44 ( & V_34 -> V_39 , V_32 ) ;
F_14 ( & V_34 -> V_40 , & V_30 -> V_123 ) ;
F_4 ( V_30 -> V_12 , L_16 ,
V_34 -> type , V_34 -> V_38 , V_34 -> V_42 ) ;
return 0 ;
}
F_12 (block, tmp, &dsp->free_block_list, list) {
if ( V_34 -> type != V_120 -> type )
continue;
if ( V_120 -> V_15 > V_34 -> V_15 ) {
V_120 -> V_42 = V_34 -> V_42 ;
V_43 = F_57 ( V_30 , V_120 , V_32 ) ;
if ( V_43 == 0 )
return V_43 ;
}
}
return - V_52 ;
}
int F_62 ( struct V_10 * V_30 , struct V_119 * V_120 ,
struct V_31 * V_32 )
{
int V_43 ;
F_4 ( V_30 -> V_12 , L_17 ,
V_120 -> V_15 , V_120 -> V_42 , V_120 -> type ) ;
F_43 ( & V_30 -> V_100 ) ;
V_43 = F_61 ( V_30 , V_120 , V_32 ) ;
if ( V_43 < 0 ) {
F_6 ( V_30 -> V_12 , L_18 , V_43 ) ;
goto V_125;
}
V_43 = F_15 ( V_30 , V_32 ) ;
if ( V_43 < 0 )
F_6 ( V_30 -> V_12 , L_19 ) ;
V_125:
F_45 ( & V_30 -> V_100 ) ;
return V_43 ;
}
int F_63 ( struct V_10 * V_30 , struct V_31 * V_32 )
{
F_43 ( & V_30 -> V_100 ) ;
F_10 ( V_30 , V_32 ) ;
F_45 ( & V_30 -> V_100 ) ;
return 0 ;
}
static int F_64 ( struct V_10 * V_30 , struct V_119 * V_120 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 , * V_4 ;
struct V_119 V_126 = * V_120 ;
T_2 V_83 = V_120 -> V_42 + V_120 -> V_15 , V_127 ;
int V_35 ;
if ( V_120 -> type != V_128 && V_120 -> type != V_129 )
return 0 ;
F_12 (block, tmp, block_list, module_list) {
if ( V_34 -> type != V_120 -> type )
continue;
V_127 = V_34 -> V_42 + V_34 -> V_15 ;
if ( V_120 -> V_42 >= V_34 -> V_42 && V_83 <= V_127 )
return 0 ;
if ( V_120 -> V_42 >= V_34 -> V_42 && V_120 -> V_42 < V_127 ) {
V_126 . V_15 -= V_127 - V_120 -> V_42 ;
V_126 . V_42 = V_127 ;
V_35 = F_57 ( V_30 , & V_126 , V_32 ) ;
if ( V_35 < 0 )
return - V_52 ;
return 0 ;
}
}
F_12 (block, tmp, &dsp->free_block_list, list) {
V_127 = V_34 -> V_42 + V_34 -> V_15 ;
if ( V_34 -> type != V_120 -> type )
continue;
if ( V_120 -> V_42 >= V_34 -> V_42 && V_83 <= V_127 ) {
F_14 ( & V_34 -> V_40 , & V_30 -> V_123 ) ;
F_44 ( & V_34 -> V_39 , V_32 ) ;
F_4 ( V_30 -> V_12 , L_16 ,
V_34 -> type , V_34 -> V_38 , V_34 -> V_42 ) ;
return 0 ;
}
if ( V_120 -> V_42 >= V_34 -> V_42 && V_120 -> V_42 < V_127 ) {
F_14 ( & V_34 -> V_40 , & V_30 -> V_123 ) ;
F_44 ( & V_34 -> V_39 , V_32 ) ;
V_126 . V_15 -= V_127 - V_120 -> V_42 ;
V_126 . V_42 = V_127 ;
V_35 = F_57 ( V_30 , & V_126 , V_32 ) ;
if ( V_35 < 0 )
return - V_52 ;
return 0 ;
}
}
return - V_52 ;
}
int F_65 ( struct V_102 * V_103 )
{
struct V_10 * V_30 = V_103 -> V_30 ;
struct V_89 * V_89 = V_103 -> V_89 ;
struct V_119 V_120 ;
int V_43 ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_15 = V_103 -> V_15 ;
V_120 . type = V_103 -> type ;
V_120 . V_42 = V_103 -> V_42 ;
F_4 ( V_30 -> V_12 , L_17 ,
V_120 . V_15 , V_120 . V_42 , V_120 . type ) ;
F_43 ( & V_30 -> V_100 ) ;
V_43 = F_64 ( V_30 , & V_120 , & V_103 -> V_32 ) ;
if ( V_43 < 0 ) {
F_6 ( V_30 -> V_12 ,
L_20 ,
V_103 -> V_42 , V_103 -> V_15 ) ;
F_45 ( & V_30 -> V_100 ) ;
return - V_52 ;
}
V_43 = F_15 ( V_30 , & V_103 -> V_32 ) ;
if ( V_43 < 0 ) {
F_6 ( V_30 -> V_12 , L_21 ) ;
goto V_35;
}
if ( V_30 -> V_88 ) {
V_43 = F_8 ( V_30 ,
V_30 -> V_80 . V_81 + V_103 -> V_42 ,
V_89 -> V_95 + V_103 -> V_130 ,
V_103 -> V_15 ) ;
if ( V_43 < 0 ) {
F_6 ( V_30 -> V_12 , L_22 ) ;
goto V_35;
}
} else
F_1 ( V_30 -> V_80 . V_131 + V_103 -> V_42 , V_103 -> V_97 ,
V_103 -> V_15 ) ;
F_45 ( & V_30 -> V_100 ) ;
return V_43 ;
V_35:
F_10 ( V_30 , & V_103 -> V_32 ) ;
F_45 ( & V_30 -> V_100 ) ;
return V_43 ;
}
int F_66 ( struct V_102 * V_103 )
{
struct V_10 * V_30 = V_103 -> V_30 ;
F_43 ( & V_30 -> V_100 ) ;
F_10 ( V_30 , & V_103 -> V_32 ) ;
F_45 ( & V_30 -> V_100 ) ;
return 0 ;
}
int F_67 ( struct V_105 * V_106 ,
int V_42 )
{
struct V_10 * V_30 = V_106 -> V_30 ;
struct V_102 * V_103 = V_106 -> V_103 ;
struct V_119 V_120 ;
int V_43 ;
if ( V_103 -> V_114 == 0 )
return 0 ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_15 = V_103 -> V_114 ;
V_120 . type = V_129 ;
F_43 ( & V_30 -> V_100 ) ;
if ( V_42 != 0 ) {
V_120 . V_42 = V_42 ;
F_4 ( V_30 -> V_12 , L_23 ,
V_120 . V_15 , V_120 . type , V_120 . V_42 ) ;
V_43 = F_64 ( V_30 , & V_120 , & V_106 -> V_32 ) ;
} else {
F_4 ( V_30 -> V_12 , L_24 ,
V_120 . V_15 , V_120 . type ) ;
V_43 = F_61 ( V_30 , & V_120 , & V_106 -> V_32 ) ;
}
if ( V_43 < 0 ) {
F_6 ( V_30 -> V_12 ,
L_25 ,
V_103 -> V_114 ) ;
F_45 ( & V_30 -> V_100 ) ;
return - V_52 ;
}
V_106 -> V_132 = V_120 . V_42 ;
V_43 = F_15 ( V_30 , & V_106 -> V_32 ) ;
if ( V_43 < 0 ) {
F_6 ( V_30 -> V_12 , L_26 ) ;
goto V_35;
}
F_45 ( & V_30 -> V_100 ) ;
return V_43 ;
V_35:
F_10 ( V_30 , & V_103 -> V_32 ) ;
F_45 ( & V_30 -> V_100 ) ;
return V_43 ;
}
int F_68 ( struct V_105 * V_106 )
{
struct V_10 * V_30 = V_106 -> V_30 ;
F_43 ( & V_30 -> V_100 ) ;
F_10 ( V_30 , & V_106 -> V_32 ) ;
F_45 ( & V_30 -> V_100 ) ;
return 0 ;
}
int F_69 ( struct V_105 * V_106 ,
struct V_133 * V_134 )
{
struct V_10 * V_30 = V_106 -> V_30 ;
struct V_102 * V_103 = V_106 -> V_103 ;
int V_43 = 0 ;
F_4 ( V_30 -> V_12 , L_27 ,
V_106 -> V_112 , V_106 -> V_132 ,
V_103 -> V_114 ) ;
V_134 -> V_135 = F_41 ( V_30 -> V_57 ,
V_103 -> V_114 ,
& V_134 -> V_136 , V_96 | V_51 ) ;
if ( ! V_134 -> V_135 ) {
F_6 ( V_30 -> V_12 , L_28 ) ;
return - V_52 ;
}
F_43 ( & V_30 -> V_100 ) ;
if ( V_30 -> V_88 ) {
V_43 = F_28 ( V_30 , 0 ) ;
if ( V_43 < 0 )
goto V_35;
V_43 = F_9 ( V_30 , V_134 -> V_136 ,
V_30 -> V_80 . V_81 + V_106 -> V_132 ,
V_103 -> V_114 ) ;
F_34 ( V_30 ) ;
if ( V_43 < 0 ) {
F_6 ( V_30 -> V_12 , L_29 ) ;
goto V_35;
}
} else
F_1 ( V_134 -> V_135 , V_30 -> V_80 . V_131 +
V_106 -> V_132 ,
V_103 -> V_114 ) ;
V_35:
F_45 ( & V_30 -> V_100 ) ;
return V_43 ;
}
int F_70 ( struct V_105 * V_106 ,
struct V_133 * V_134 )
{
struct V_10 * V_30 = V_106 -> V_30 ;
struct V_102 * V_103 = V_106 -> V_103 ;
int V_43 = 0 ;
F_4 ( V_30 -> V_12 , L_30 ,
V_106 -> V_112 , V_106 -> V_132 ,
V_103 -> V_114 ) ;
F_43 ( & V_30 -> V_100 ) ;
if ( ! V_134 -> V_135 ) {
F_71 ( V_30 -> V_12 , L_31 ) ;
goto V_35;
}
if ( V_30 -> V_88 ) {
V_43 = F_28 ( V_30 , 0 ) ;
if ( V_43 < 0 )
goto V_35;
V_43 = F_8 ( V_30 ,
V_30 -> V_80 . V_81 + V_106 -> V_132 ,
V_134 -> V_136 , V_103 -> V_114 ) ;
F_34 ( V_30 ) ;
if ( V_43 < 0 ) {
F_6 ( V_30 -> V_12 , L_22 ) ;
goto V_35;
}
} else
F_1 ( V_30 -> V_80 . V_131 + V_106 -> V_132 ,
V_134 -> V_135 , V_103 -> V_114 ) ;
F_46 ( V_30 -> V_57 , V_103 -> V_114 ,
V_134 -> V_135 , V_134 -> V_136 ) ;
V_134 -> V_135 = NULL ;
V_35:
F_45 ( & V_30 -> V_100 ) ;
return V_43 ;
}
struct V_33 * F_72 ( struct V_10 * V_30 , T_2 V_42 ,
T_2 V_15 , enum V_137 type , const struct V_138 * V_36 ,
T_2 V_38 , void * V_92 )
{
struct V_33 * V_34 ;
V_34 = F_40 ( sizeof( * V_34 ) , V_51 ) ;
if ( V_34 == NULL )
return NULL ;
V_34 -> V_42 = V_42 ;
V_34 -> V_15 = V_15 ;
V_34 -> V_38 = V_38 ;
V_34 -> type = type ;
V_34 -> V_30 = V_30 ;
V_34 -> V_92 = V_92 ;
V_34 -> V_36 = V_36 ;
F_43 ( & V_30 -> V_100 ) ;
F_44 ( & V_34 -> V_40 , & V_30 -> V_41 ) ;
F_45 ( & V_30 -> V_100 ) ;
return V_34 ;
}
void F_73 ( struct V_10 * V_30 )
{
struct V_33 * V_34 , * V_4 ;
F_43 ( & V_30 -> V_100 ) ;
F_12 (block, tmp, &dsp->used_block_list, list) {
F_13 ( & V_34 -> V_40 ) ;
F_42 ( V_34 ) ;
}
F_12 (block, tmp, &dsp->free_block_list, list) {
F_13 ( & V_34 -> V_40 ) ;
F_42 ( V_34 ) ;
}
F_45 ( & V_30 -> V_100 ) ;
}
int F_74 ( struct V_10 * V_30 )
{
struct V_102 * V_103 ;
struct V_119 V_120 ;
int V_43 ;
F_43 ( & V_30 -> V_100 ) ;
V_30 -> V_113 = 0 ;
F_11 (module, &dsp->module_list, list) {
F_4 ( V_30 -> V_12 , L_32 ,
V_103 -> V_112 , V_103 -> V_113 ) ;
if ( V_30 -> V_113 < V_103 -> V_113 )
V_30 -> V_113 = V_103 -> V_113 ;
}
F_4 ( V_30 -> V_12 , L_33 ,
V_30 -> V_113 ) ;
if ( V_30 -> V_113 == 0 ) {
F_71 ( V_30 -> V_12 , L_34 ) ;
F_45 ( & V_30 -> V_100 ) ;
return 0 ;
}
F_4 ( V_30 -> V_12 , L_35 ) ;
V_120 . V_15 = V_30 -> V_113 ;
V_120 . type = V_129 ;
if ( V_30 -> V_139 != 0 ) {
F_4 ( V_30 -> V_12 , L_36 ,
V_120 . V_15 , V_120 . type , V_120 . V_42 ) ;
V_120 . V_42 = V_30 -> V_139 ;
V_43 = F_64 ( V_30 , & V_120 , & V_30 -> V_108 ) ;
} else {
F_4 ( V_30 -> V_12 , L_37 ,
V_120 . V_15 , V_120 . type ) ;
V_120 . V_42 = 0 ;
V_43 = F_61 ( V_30 , & V_120 , & V_30 -> V_108 ) ;
}
if ( V_43 < 0 ) {
F_6 ( V_30 -> V_12 , L_38 ) ;
F_45 ( & V_30 -> V_100 ) ;
return V_43 ;
}
V_43 = F_15 ( V_30 , & V_30 -> V_108 ) ;
if ( V_43 < 0 ) {
F_6 ( V_30 -> V_12 , L_39 ) ;
F_45 ( & V_30 -> V_100 ) ;
return V_43 ;
}
V_30 -> V_139 = V_120 . V_42 ;
F_45 ( & V_30 -> V_100 ) ;
return V_30 -> V_113 ;
}
void F_75 ( struct V_10 * V_30 )
{
F_43 ( & V_30 -> V_100 ) ;
F_10 ( V_30 , & V_30 -> V_108 ) ;
F_45 ( & V_30 -> V_100 ) ;
}
struct V_102 * F_76 ( struct V_10 * V_30 , T_2 V_112 )
{
struct V_102 * V_103 ;
F_43 ( & V_30 -> V_100 ) ;
F_11 (module, &dsp->module_list, list) {
if ( V_103 -> V_112 == V_112 ) {
F_45 ( & V_30 -> V_100 ) ;
return V_103 ;
}
}
F_45 ( & V_30 -> V_100 ) ;
return NULL ;
}
struct V_105 * F_77 (
struct V_102 * V_103 , T_2 V_112 )
{
struct V_105 * V_106 ;
struct V_10 * V_30 = V_103 -> V_30 ;
F_43 ( & V_30 -> V_100 ) ;
F_11 (runtime, &module->runtime_list, list) {
if ( V_106 -> V_112 == V_112 ) {
F_45 ( & V_30 -> V_100 ) ;
return V_106 ;
}
}
F_45 ( & V_30 -> V_100 ) ;
return NULL ;
}
T_2 F_78 ( struct V_10 * V_30 , T_2 V_42 ,
enum V_137 type )
{
switch ( type ) {
case V_128 :
return V_42 - V_30 -> V_80 . V_140 +
V_30 -> V_80 . V_141 ;
case V_129 :
return V_42 - V_30 -> V_80 . V_142 +
V_30 -> V_80 . V_143 ;
default:
return 0 ;
}
}
