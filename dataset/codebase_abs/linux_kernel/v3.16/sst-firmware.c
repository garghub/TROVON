static void F_1 ( volatile void T_1 * V_1 , void * V_2 , T_2 V_3 )
{
T_2 V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 += 4 )
F_2 ( V_1 + V_4 , V_2 + V_4 , 4 ) ;
}
struct V_5 * F_3 ( struct V_6 * V_7 ,
const struct V_8 * V_9 , void * V_10 )
{
struct V_5 * V_5 ;
int V_11 ;
if ( ! V_7 -> V_12 -> V_13 )
return NULL ;
V_5 = F_4 ( sizeof( * V_5 ) , V_14 ) ;
if ( V_5 == NULL )
return NULL ;
V_5 -> V_7 = V_7 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_15 = V_9 -> V_15 ;
V_5 -> V_16 = F_5 ( V_7 -> V_17 , V_5 -> V_15 ,
& V_5 -> V_18 , V_19 | V_14 ) ;
if ( ! V_5 -> V_16 ) {
F_6 ( V_7 -> V_20 , L_1 ) ;
F_7 ( V_5 ) ;
return NULL ;
}
memcpy ( ( void * ) V_5 -> V_16 , ( void * ) V_9 -> V_21 , V_9 -> V_15 ) ;
V_11 = V_7 -> V_12 -> V_13 ( V_5 ) ;
if ( V_11 < 0 ) {
F_6 ( V_7 -> V_20 , L_2 , V_11 ) ;
goto V_22;
}
F_8 ( & V_7 -> V_23 ) ;
F_9 ( & V_5 -> V_24 , & V_7 -> V_25 ) ;
F_10 ( & V_7 -> V_23 ) ;
return V_5 ;
V_22:
F_11 ( V_7 -> V_20 , V_5 -> V_15 ,
V_5 -> V_16 ,
V_5 -> V_18 ) ;
F_7 ( V_5 ) ;
return NULL ;
}
int F_12 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
int V_26 ;
F_13 ( V_7 -> V_20 , L_3 ) ;
V_26 = V_7 -> V_12 -> V_13 ( V_5 ) ;
if ( V_26 < 0 )
F_6 ( V_7 -> V_20 , L_2 , V_26 ) ;
return V_26 ;
}
void F_14 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_27 * V_28 , * V_29 ;
F_13 ( V_7 -> V_20 , L_4 ) ;
F_8 ( & V_7 -> V_23 ) ;
F_15 (module, tmp, &dsp->module_list, list) {
if ( V_28 -> V_5 == V_5 ) {
F_16 ( V_28 ) ;
F_17 ( & V_28 -> V_24 ) ;
F_7 ( V_28 ) ;
}
}
F_10 ( & V_7 -> V_23 ) ;
}
void F_18 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
F_8 ( & V_7 -> V_23 ) ;
F_17 ( & V_5 -> V_24 ) ;
F_10 ( & V_7 -> V_23 ) ;
F_11 ( V_7 -> V_17 , V_5 -> V_15 , V_5 -> V_16 ,
V_5 -> V_18 ) ;
F_7 ( V_5 ) ;
}
void F_19 ( struct V_6 * V_7 )
{
struct V_5 * V_5 , * V_30 ;
F_8 ( & V_7 -> V_23 ) ;
F_15 (sst_fw, t, &dsp->fw_list, list) {
F_17 ( & V_5 -> V_24 ) ;
F_11 ( V_7 -> V_20 , V_5 -> V_15 , V_5 -> V_16 ,
V_5 -> V_18 ) ;
F_7 ( V_5 ) ;
}
F_10 ( & V_7 -> V_23 ) ;
}
struct V_27 * F_20 ( struct V_5 * V_5 ,
struct V_31 * V_32 , void * V_10 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_27 * V_27 ;
V_27 = F_4 ( sizeof( * V_27 ) , V_14 ) ;
if ( V_27 == NULL )
return NULL ;
V_27 -> V_33 = V_32 -> V_33 ;
V_27 -> V_7 = V_7 ;
V_27 -> V_5 = V_5 ;
memcpy ( & V_27 -> V_34 , & V_32 -> V_34 , sizeof( struct V_35 ) ) ;
memcpy ( & V_27 -> V_36 , & V_32 -> V_36 , sizeof( struct V_35 ) ) ;
F_21 ( & V_27 -> V_37 ) ;
F_8 ( & V_7 -> V_23 ) ;
F_9 ( & V_27 -> V_24 , & V_7 -> V_38 ) ;
F_10 ( & V_7 -> V_23 ) ;
return V_27 ;
}
void F_22 ( struct V_27 * V_27 )
{
struct V_6 * V_7 = V_27 -> V_7 ;
F_8 ( & V_7 -> V_23 ) ;
F_17 ( & V_27 -> V_24 ) ;
F_10 ( & V_7 -> V_23 ) ;
F_7 ( V_27 ) ;
}
static struct V_39 * F_23 ( struct V_6 * V_7 , int type ,
T_2 V_40 )
{
struct V_39 * V_41 ;
F_24 (block, &dsp->free_block_list, list) {
if ( V_41 -> type == type && V_41 -> V_40 == V_40 )
return V_41 ;
}
return NULL ;
}
static int F_25 ( struct V_27 * V_28 ,
struct V_35 * V_21 , T_2 V_40 , int V_15 )
{
struct V_42 V_29 = F_26 ( V_29 ) ;
struct V_6 * V_7 = V_28 -> V_7 ;
struct V_39 * V_41 ;
while ( V_15 > 0 ) {
V_41 = F_23 ( V_7 , V_21 -> type , V_40 ) ;
if ( ! V_41 ) {
F_27 ( & V_29 , & V_7 -> V_43 ) ;
return - V_44 ;
}
F_28 ( & V_41 -> V_24 , & V_29 ) ;
V_40 += V_41 -> V_15 ;
V_15 -= V_41 -> V_15 ;
}
F_24 (block, &tmp, list)
F_9 ( & V_41 -> V_38 , & V_28 -> V_37 ) ;
F_27 ( & V_29 , & V_7 -> V_45 ) ;
return 0 ;
}
static int F_29 ( struct V_27 * V_28 ,
struct V_35 * V_21 )
{
struct V_6 * V_7 = V_28 -> V_7 ;
struct V_39 * V_41 , * V_29 ;
int V_26 = 0 ;
if ( V_21 -> V_15 == 0 )
return 0 ;
F_15 (block, tmp, &dsp->free_block_list, list) {
if ( V_41 -> type != V_21 -> type )
continue;
if ( V_21 -> V_15 > V_41 -> V_15 )
continue;
V_21 -> V_40 = V_41 -> V_40 ;
V_41 -> V_46 = V_21 -> V_46 ;
V_41 -> V_47 = V_21 -> V_15 % V_41 -> V_15 ;
F_9 ( & V_41 -> V_38 , & V_28 -> V_37 ) ;
F_30 ( & V_41 -> V_24 , & V_7 -> V_45 ) ;
F_13 ( V_7 -> V_20 , L_5 ,
V_28 -> V_33 , V_41 -> type , V_41 -> V_48 ) ;
return 0 ;
}
F_15 (block, tmp, &dsp->free_block_list, list) {
if ( V_41 -> type != V_21 -> type )
continue;
if ( V_21 -> V_15 > V_41 -> V_15 ) {
V_26 = F_25 ( V_28 , V_21 ,
V_41 -> V_40 , V_21 -> V_15 ) ;
if ( V_26 == 0 )
return V_26 ;
}
}
return - V_44 ;
}
static void F_16 ( struct V_27 * V_28 )
{
struct V_39 * V_41 , * V_29 ;
struct V_6 * V_7 = V_28 -> V_7 ;
int V_11 ;
F_24 (block, &module->block_list, module_list) {
if ( V_41 -> V_12 && V_41 -> V_12 -> V_49 ) {
V_11 = V_41 -> V_12 -> V_49 ( V_41 ) ;
if ( V_11 < 0 )
F_6 ( V_7 -> V_20 ,
L_6 ,
V_41 -> type , V_41 -> V_48 ) ;
}
}
F_15 (block, tmp, &module->block_list, module_list) {
F_17 ( & V_41 -> V_38 ) ;
F_30 ( & V_41 -> V_24 , & V_7 -> V_43 ) ;
}
}
static int F_31 ( struct V_27 * V_28 )
{
struct V_39 * V_41 ;
int V_26 = 0 ;
F_24 (block, &module->block_list, module_list) {
if ( V_41 -> V_12 && V_41 -> V_12 -> V_50 ) {
V_26 = V_41 -> V_12 -> V_50 ( V_41 ) ;
if ( V_26 < 0 ) {
F_6 ( V_28 -> V_7 -> V_20 ,
L_6 ,
V_41 -> type , V_41 -> V_48 ) ;
goto V_11;
}
}
}
return V_26 ;
V_11:
F_24 (block, &module->block_list, module_list) {
if ( V_41 -> V_12 && V_41 -> V_12 -> V_49 )
V_41 -> V_12 -> V_49 ( V_41 ) ;
}
return V_26 ;
}
static int F_32 ( struct V_27 * V_28 ,
struct V_35 * V_21 )
{
struct V_6 * V_7 = V_28 -> V_7 ;
struct V_39 * V_41 , * V_29 ;
T_2 V_51 = V_21 -> V_40 + V_21 -> V_15 , V_52 ;
int V_11 ;
if ( V_21 -> type != V_53 && V_21 -> type != V_54 )
return 0 ;
F_15 (block, tmp, &module->block_list, module_list) {
if ( V_41 -> V_46 != V_21 -> V_46 )
continue;
V_52 = V_41 -> V_40 + V_41 -> V_15 ;
if ( V_21 -> V_40 >= V_41 -> V_40 && V_51 < V_52 )
return 0 ;
if ( V_21 -> V_40 >= V_41 -> V_40 && V_21 -> V_40 < V_52 ) {
V_11 = F_25 ( V_28 , V_21 ,
V_41 -> V_40 + V_41 -> V_15 ,
V_21 -> V_15 - V_41 -> V_15 ) ;
if ( V_11 < 0 )
return - V_44 ;
return 0 ;
}
}
F_15 (block, tmp, &dsp->free_block_list, list) {
V_52 = V_41 -> V_40 + V_41 -> V_15 ;
if ( V_21 -> V_40 >= V_41 -> V_40 && V_51 < V_52 ) {
V_41 -> V_46 = V_21 -> V_46 ;
F_30 ( & V_41 -> V_24 , & V_7 -> V_45 ) ;
F_9 ( & V_41 -> V_38 , & V_28 -> V_37 ) ;
return 0 ;
}
if ( V_21 -> V_40 >= V_41 -> V_40 && V_21 -> V_40 < V_52 ) {
V_11 = F_25 ( V_28 , V_21 ,
V_41 -> V_40 , V_21 -> V_15 ) ;
if ( V_11 < 0 )
return - V_44 ;
return 0 ;
}
}
return - V_44 ;
}
int F_33 ( struct V_27 * V_28 ,
struct V_35 * V_21 )
{
struct V_6 * V_7 = V_28 -> V_7 ;
int V_26 ;
F_8 ( & V_7 -> V_23 ) ;
V_26 = F_32 ( V_28 , V_21 ) ;
if ( V_26 < 0 ) {
F_6 ( V_7 -> V_20 ,
L_7 ,
V_21 -> V_40 , V_21 -> V_15 ) ;
F_10 ( & V_7 -> V_23 ) ;
return - V_44 ;
}
V_26 = F_31 ( V_28 ) ;
if ( V_26 < 0 ) {
F_6 ( V_7 -> V_20 , L_8 ) ;
goto V_11;
}
F_1 ( V_7 -> V_55 . V_56 + V_21 -> V_40 , V_21 -> V_21 , V_21 -> V_15 ) ;
F_10 ( & V_7 -> V_23 ) ;
return V_26 ;
V_11:
F_16 ( V_28 ) ;
F_10 ( & V_7 -> V_23 ) ;
return V_26 ;
}
int F_34 ( struct V_27 * V_28 )
{
struct V_6 * V_7 = V_28 -> V_7 ;
F_8 ( & V_7 -> V_23 ) ;
F_16 ( V_28 ) ;
F_10 ( & V_7 -> V_23 ) ;
return 0 ;
}
struct V_39 * F_35 ( struct V_6 * V_7 , T_2 V_40 ,
T_2 V_15 , enum V_57 type , struct V_58 * V_12 , T_2 V_48 ,
void * V_10 )
{
struct V_39 * V_41 ;
V_41 = F_4 ( sizeof( * V_41 ) , V_14 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_40 = V_40 ;
V_41 -> V_15 = V_15 ;
V_41 -> V_48 = V_48 ;
V_41 -> type = type ;
V_41 -> V_7 = V_7 ;
V_41 -> V_10 = V_10 ;
V_41 -> V_12 = V_12 ;
F_8 ( & V_7 -> V_23 ) ;
F_9 ( & V_41 -> V_24 , & V_7 -> V_43 ) ;
F_10 ( & V_7 -> V_23 ) ;
return V_41 ;
}
void F_36 ( struct V_6 * V_7 )
{
struct V_39 * V_41 , * V_29 ;
F_8 ( & V_7 -> V_23 ) ;
F_15 (block, tmp, &dsp->used_block_list, list) {
F_17 ( & V_41 -> V_24 ) ;
F_7 ( V_41 ) ;
}
F_15 (block, tmp, &dsp->free_block_list, list) {
F_17 ( & V_41 -> V_24 ) ;
F_7 ( V_41 ) ;
}
F_10 ( & V_7 -> V_23 ) ;
}
struct V_27 * F_37 ( struct V_6 * V_7 )
{
struct V_27 * V_27 , * V_59 ;
struct V_39 * V_41 , * V_29 ;
T_2 V_60 ;
int V_26 = 0 ;
V_59 = F_4 ( sizeof( struct V_27 ) , V_14 ) ;
if ( V_59 == NULL )
return NULL ;
F_8 ( & V_7 -> V_23 ) ;
F_24 (sst_module, &dsp->module_list, list) {
if ( V_59 -> V_34 . V_15 < V_27 -> V_34 . V_15 )
V_59 -> V_34 . V_15 = V_27 -> V_34 . V_15 ;
}
F_13 ( V_7 -> V_20 , L_9 ,
V_59 -> V_34 . V_15 ) ;
V_59 -> V_7 = V_7 ;
V_59 -> V_34 . type = V_54 ;
V_59 -> V_34 . V_46 = V_61 ;
F_21 ( & V_59 -> V_37 ) ;
if ( ! F_38 ( & V_7 -> V_43 ) )
V_41 = F_39 ( & V_7 -> V_43 ,
struct V_39 , V_24 ) ;
else
V_41 = F_39 ( & V_7 -> V_45 ,
struct V_39 , V_24 ) ;
V_60 = V_41 -> V_15 ;
F_13 ( V_7 -> V_20 , L_10 ) ;
V_26 = F_29 ( V_59 , & V_59 -> V_34 ) ;
if ( V_26 < 0 ) {
F_6 ( V_7 -> V_20 , L_11 ) ;
goto V_11;
}
F_24 (sst_module, &dsp->module_list, list)
V_27 -> V_34 . V_40 = V_59 -> V_34 . V_40 ;
F_10 ( & V_7 -> V_23 ) ;
return V_59 ;
V_11:
F_15 (block, tmp, &scratch->block_list, module_list)
F_17 ( & V_41 -> V_38 ) ;
F_10 ( & V_7 -> V_23 ) ;
return NULL ;
}
void F_40 ( struct V_6 * V_7 ,
struct V_27 * V_59 )
{
struct V_39 * V_41 , * V_29 ;
F_8 ( & V_7 -> V_23 ) ;
F_15 (block, tmp, &scratch->block_list, module_list)
F_17 ( & V_41 -> V_38 ) ;
F_10 ( & V_7 -> V_23 ) ;
}
struct V_27 * F_41 ( struct V_6 * V_7 , T_2 V_33 )
{
struct V_27 * V_28 ;
F_8 ( & V_7 -> V_23 ) ;
F_24 (module, &dsp->module_list, list) {
if ( V_28 -> V_33 == V_33 ) {
F_10 ( & V_7 -> V_23 ) ;
return V_28 ;
}
}
F_10 ( & V_7 -> V_23 ) ;
return NULL ;
}
