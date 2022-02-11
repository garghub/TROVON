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
void F_12 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
F_8 ( & V_7 -> V_23 ) ;
F_13 ( & V_5 -> V_24 ) ;
F_10 ( & V_7 -> V_23 ) ;
F_11 ( V_7 -> V_17 , V_5 -> V_15 , V_5 -> V_16 ,
V_5 -> V_18 ) ;
F_7 ( V_5 ) ;
}
void F_14 ( struct V_6 * V_7 )
{
struct V_5 * V_5 , * V_26 ;
F_8 ( & V_7 -> V_23 ) ;
F_15 (sst_fw, t, &dsp->fw_list, list) {
F_13 ( & V_5 -> V_24 ) ;
F_11 ( V_7 -> V_20 , V_5 -> V_15 , V_5 -> V_16 ,
V_5 -> V_18 ) ;
F_7 ( V_5 ) ;
}
F_10 ( & V_7 -> V_23 ) ;
}
struct V_27 * F_16 ( struct V_5 * V_5 ,
struct V_28 * V_29 , void * V_10 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_27 * V_27 ;
V_27 = F_4 ( sizeof( * V_27 ) , V_14 ) ;
if ( V_27 == NULL )
return NULL ;
V_27 -> V_30 = V_29 -> V_30 ;
V_27 -> V_7 = V_7 ;
V_27 -> V_5 = V_5 ;
memcpy ( & V_27 -> V_31 , & V_29 -> V_31 , sizeof( struct V_32 ) ) ;
memcpy ( & V_27 -> V_33 , & V_29 -> V_33 , sizeof( struct V_32 ) ) ;
F_17 ( & V_27 -> V_34 ) ;
F_8 ( & V_7 -> V_23 ) ;
F_9 ( & V_27 -> V_24 , & V_7 -> V_35 ) ;
F_10 ( & V_7 -> V_23 ) ;
return V_27 ;
}
void F_18 ( struct V_27 * V_27 )
{
struct V_6 * V_7 = V_27 -> V_7 ;
F_8 ( & V_7 -> V_23 ) ;
F_13 ( & V_27 -> V_24 ) ;
F_10 ( & V_7 -> V_23 ) ;
F_7 ( V_27 ) ;
}
static struct V_36 * F_19 ( struct V_6 * V_7 , int type ,
T_2 V_37 )
{
struct V_36 * V_38 ;
F_20 (block, &dsp->free_block_list, list) {
if ( V_38 -> type == type && V_38 -> V_37 == V_37 )
return V_38 ;
}
return NULL ;
}
static int F_21 ( struct V_27 * V_39 ,
struct V_32 * V_21 , T_2 V_37 , int V_15 )
{
struct V_40 V_41 = F_22 ( V_41 ) ;
struct V_6 * V_7 = V_39 -> V_7 ;
struct V_36 * V_38 ;
while ( V_15 > 0 ) {
V_38 = F_19 ( V_7 , V_21 -> type , V_37 ) ;
if ( ! V_38 ) {
F_23 ( & V_41 , & V_7 -> V_42 ) ;
return - V_43 ;
}
F_24 ( & V_38 -> V_24 , & V_41 ) ;
V_37 += V_38 -> V_15 ;
V_15 -= V_38 -> V_15 ;
}
F_20 (block, &tmp, list)
F_9 ( & V_38 -> V_35 , & V_39 -> V_34 ) ;
F_23 ( & V_41 , & V_7 -> V_44 ) ;
return 0 ;
}
static int F_25 ( struct V_27 * V_39 ,
struct V_32 * V_21 )
{
struct V_6 * V_7 = V_39 -> V_7 ;
struct V_36 * V_38 , * V_41 ;
int V_45 = 0 ;
if ( V_21 -> V_15 == 0 )
return 0 ;
F_15 (block, tmp, &dsp->free_block_list, list) {
if ( V_38 -> type != V_21 -> type )
continue;
if ( V_21 -> V_15 > V_38 -> V_15 )
continue;
V_21 -> V_37 = V_38 -> V_37 ;
V_38 -> V_46 = V_21 -> V_46 ;
V_38 -> V_47 = V_21 -> V_15 % V_38 -> V_15 ;
F_9 ( & V_38 -> V_35 , & V_39 -> V_34 ) ;
F_26 ( & V_38 -> V_24 , & V_7 -> V_44 ) ;
F_27 ( V_7 -> V_20 , L_3 ,
V_39 -> V_30 , V_38 -> type , V_38 -> V_48 ) ;
return 0 ;
}
F_15 (block, tmp, &dsp->free_block_list, list) {
if ( V_38 -> type != V_21 -> type )
continue;
if ( V_21 -> V_15 > V_38 -> V_15 ) {
V_45 = F_21 ( V_39 , V_21 ,
V_38 -> V_37 , V_21 -> V_15 ) ;
if ( V_45 == 0 )
return V_45 ;
}
}
return - V_43 ;
}
static void F_28 ( struct V_27 * V_39 )
{
struct V_36 * V_38 , * V_41 ;
struct V_6 * V_7 = V_39 -> V_7 ;
int V_11 ;
F_20 (block, &module->block_list, module_list) {
if ( V_38 -> V_12 && V_38 -> V_12 -> V_49 ) {
V_11 = V_38 -> V_12 -> V_49 ( V_38 ) ;
if ( V_11 < 0 )
F_6 ( V_7 -> V_20 ,
L_4 ,
V_38 -> type , V_38 -> V_48 ) ;
}
}
F_15 (block, tmp, &module->block_list, module_list) {
F_13 ( & V_38 -> V_35 ) ;
F_26 ( & V_38 -> V_24 , & V_7 -> V_42 ) ;
}
}
static int F_29 ( struct V_27 * V_39 )
{
struct V_36 * V_38 ;
int V_45 = 0 ;
F_20 (block, &module->block_list, module_list) {
if ( V_38 -> V_12 && V_38 -> V_12 -> V_50 ) {
V_45 = V_38 -> V_12 -> V_50 ( V_38 ) ;
if ( V_45 < 0 ) {
F_6 ( V_39 -> V_7 -> V_20 ,
L_4 ,
V_38 -> type , V_38 -> V_48 ) ;
goto V_11;
}
}
}
return V_45 ;
V_11:
F_20 (block, &module->block_list, module_list) {
if ( V_38 -> V_12 && V_38 -> V_12 -> V_49 )
V_38 -> V_12 -> V_49 ( V_38 ) ;
}
return V_45 ;
}
static int F_30 ( struct V_27 * V_39 ,
struct V_32 * V_21 )
{
struct V_6 * V_7 = V_39 -> V_7 ;
struct V_36 * V_38 , * V_41 ;
T_2 V_51 = V_21 -> V_37 + V_21 -> V_15 , V_52 ;
int V_11 ;
if ( V_21 -> type != V_53 && V_21 -> type != V_54 )
return 0 ;
F_15 (block, tmp, &module->block_list, module_list) {
if ( V_38 -> V_46 != V_21 -> V_46 )
continue;
V_52 = V_38 -> V_37 + V_38 -> V_15 ;
if ( V_21 -> V_37 >= V_38 -> V_37 && V_51 < V_52 )
return 0 ;
if ( V_21 -> V_37 >= V_38 -> V_37 && V_21 -> V_37 < V_52 ) {
V_11 = F_21 ( V_39 , V_21 ,
V_38 -> V_37 + V_38 -> V_15 ,
V_21 -> V_15 - V_38 -> V_15 ) ;
if ( V_11 < 0 )
return - V_43 ;
return 0 ;
}
}
F_15 (block, tmp, &dsp->free_block_list, list) {
V_52 = V_38 -> V_37 + V_38 -> V_15 ;
if ( V_21 -> V_37 >= V_38 -> V_37 && V_51 < V_52 ) {
V_38 -> V_46 = V_21 -> V_46 ;
F_26 ( & V_38 -> V_24 , & V_7 -> V_44 ) ;
F_9 ( & V_38 -> V_35 , & V_39 -> V_34 ) ;
return 0 ;
}
if ( V_21 -> V_37 >= V_38 -> V_37 && V_21 -> V_37 < V_52 ) {
V_11 = F_21 ( V_39 , V_21 ,
V_38 -> V_37 , V_21 -> V_15 ) ;
if ( V_11 < 0 )
return - V_43 ;
return 0 ;
}
}
return - V_43 ;
}
int F_31 ( struct V_27 * V_39 ,
struct V_32 * V_21 )
{
struct V_6 * V_7 = V_39 -> V_7 ;
int V_45 ;
F_8 ( & V_7 -> V_23 ) ;
V_45 = F_30 ( V_39 , V_21 ) ;
if ( V_45 < 0 ) {
F_6 ( V_7 -> V_20 ,
L_5 ,
V_21 -> V_37 , V_21 -> V_15 ) ;
F_10 ( & V_7 -> V_23 ) ;
return - V_43 ;
}
V_45 = F_29 ( V_39 ) ;
if ( V_45 < 0 ) {
F_6 ( V_7 -> V_20 , L_6 ) ;
goto V_11;
}
F_1 ( V_7 -> V_55 . V_56 + V_21 -> V_37 , V_21 -> V_21 , V_21 -> V_15 ) ;
F_10 ( & V_7 -> V_23 ) ;
return V_45 ;
V_11:
F_28 ( V_39 ) ;
F_10 ( & V_7 -> V_23 ) ;
return V_45 ;
}
int F_32 ( struct V_27 * V_39 )
{
struct V_6 * V_7 = V_39 -> V_7 ;
F_8 ( & V_7 -> V_23 ) ;
F_28 ( V_39 ) ;
F_10 ( & V_7 -> V_23 ) ;
return 0 ;
}
struct V_36 * F_33 ( struct V_6 * V_7 , T_2 V_37 ,
T_2 V_15 , enum V_57 type , struct V_58 * V_12 , T_2 V_48 ,
void * V_10 )
{
struct V_36 * V_38 ;
V_38 = F_4 ( sizeof( * V_38 ) , V_14 ) ;
if ( V_38 == NULL )
return NULL ;
V_38 -> V_37 = V_37 ;
V_38 -> V_15 = V_15 ;
V_38 -> V_48 = V_48 ;
V_38 -> type = type ;
V_38 -> V_7 = V_7 ;
V_38 -> V_10 = V_10 ;
V_38 -> V_12 = V_12 ;
F_8 ( & V_7 -> V_23 ) ;
F_9 ( & V_38 -> V_24 , & V_7 -> V_42 ) ;
F_10 ( & V_7 -> V_23 ) ;
return V_38 ;
}
void F_34 ( struct V_6 * V_7 )
{
struct V_36 * V_38 , * V_41 ;
F_8 ( & V_7 -> V_23 ) ;
F_15 (block, tmp, &dsp->used_block_list, list) {
F_13 ( & V_38 -> V_24 ) ;
F_7 ( V_38 ) ;
}
F_15 (block, tmp, &dsp->free_block_list, list) {
F_13 ( & V_38 -> V_24 ) ;
F_7 ( V_38 ) ;
}
F_10 ( & V_7 -> V_23 ) ;
}
struct V_27 * F_35 ( struct V_6 * V_7 )
{
struct V_27 * V_27 , * V_59 ;
struct V_36 * V_38 , * V_41 ;
T_2 V_60 ;
int V_45 = 0 ;
V_59 = F_4 ( sizeof( struct V_27 ) , V_14 ) ;
if ( V_59 == NULL )
return NULL ;
F_8 ( & V_7 -> V_23 ) ;
F_20 (sst_module, &dsp->module_list, list) {
if ( V_59 -> V_31 . V_15 > V_27 -> V_31 . V_15 )
V_59 -> V_31 . V_15 = V_59 -> V_31 . V_15 ;
else
V_59 -> V_31 . V_15 = V_27 -> V_31 . V_15 ;
}
F_27 ( V_7 -> V_20 , L_7 ,
V_59 -> V_31 . V_15 ) ;
V_59 -> V_7 = V_7 ;
V_59 -> V_31 . type = V_54 ;
V_59 -> V_31 . V_46 = V_61 ;
F_17 ( & V_59 -> V_34 ) ;
if ( ! F_36 ( & V_7 -> V_42 ) )
V_38 = F_37 ( & V_7 -> V_42 ,
struct V_36 , V_24 ) ;
else
V_38 = F_37 ( & V_7 -> V_44 ,
struct V_36 , V_24 ) ;
V_60 = V_38 -> V_15 ;
F_27 ( V_7 -> V_20 , L_8 ) ;
V_45 = F_25 ( V_59 , & V_59 -> V_31 ) ;
if ( V_45 < 0 ) {
F_6 ( V_7 -> V_20 , L_9 ) ;
goto V_11;
}
F_20 (sst_module, &dsp->module_list, list)
V_27 -> V_31 . V_37 = V_59 -> V_31 . V_37 ;
F_10 ( & V_7 -> V_23 ) ;
return V_59 ;
V_11:
F_15 (block, tmp, &scratch->block_list, module_list)
F_13 ( & V_38 -> V_35 ) ;
F_10 ( & V_7 -> V_23 ) ;
return NULL ;
}
void F_38 ( struct V_6 * V_7 ,
struct V_27 * V_59 )
{
struct V_36 * V_38 , * V_41 ;
F_8 ( & V_7 -> V_23 ) ;
F_15 (block, tmp, &scratch->block_list, module_list)
F_13 ( & V_38 -> V_35 ) ;
F_10 ( & V_7 -> V_23 ) ;
}
struct V_27 * F_39 ( struct V_6 * V_7 , T_2 V_30 )
{
struct V_27 * V_39 ;
F_8 ( & V_7 -> V_23 ) ;
F_20 (module, &dsp->module_list, list) {
if ( V_39 -> V_30 == V_30 ) {
F_10 ( & V_7 -> V_23 ) ;
return V_39 ;
}
}
F_10 ( & V_7 -> V_23 ) ;
return NULL ;
}
