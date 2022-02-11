static bool F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 , V_5 ) & V_6 ;
return ( V_4 == V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
const void * V_7 , T_1 V_8 )
{
int V_9 = 0 ;
V_9 = V_2 -> V_10 . V_11 . V_12 ( V_2 , V_7 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_4 ( V_2 ,
V_5 ,
V_6 ,
V_13 ,
V_14 ,
L_1 ) ;
V_2 -> V_10 . V_11 . V_15 ( V_2 ) ;
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_9 = 0 , V_16 ;
struct V_17 * V_18 = V_2 -> V_19 ;
T_1 V_20 ;
V_18 -> V_21 = false ;
F_6 ( & V_18 -> V_22 ) ;
if ( V_2 -> V_23 == NULL ) {
V_9 = F_7 ( & V_2 -> V_23 , V_2 -> V_24 , V_2 -> V_25 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_25 , L_2 , V_9 ) ;
F_9 ( V_2 ) ;
return - V_26 ;
}
}
V_9 = F_10 ( V_2 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_25 , L_3 , V_9 ) ;
goto V_27;
}
V_9 = F_11 ( V_2 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_25 , L_4 , V_9 ) ;
goto V_27;
}
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
for ( V_16 = V_28 ; V_16 > 0 ; -- V_16 ) {
if ( F_1 ( V_2 , V_29 ) ) {
F_14 ( V_2 -> V_25 ,
L_5 ) ;
break;
}
F_15 ( 1 ) ;
}
if ( ! V_16 ) {
V_20 = F_2 ( V_2 , V_5 ) ;
F_8 ( V_2 -> V_25 ,
L_6 , V_20 ) ;
V_9 = - V_26 ;
goto V_30;
}
V_9 = F_3 ( V_2 , V_2 -> V_23 -> V_31 , V_2 -> V_23 -> V_32 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_25 , L_7 , V_9 ) ;
goto V_30;
} else {
V_9 = F_16 ( V_18 -> V_22 , V_18 -> V_21 ,
F_17 ( V_33 ) ) ;
if ( V_9 == 0 ) {
F_8 ( V_2 -> V_25 , L_8 ) ;
V_9 = - V_26 ;
goto V_30;
}
F_14 ( V_2 -> V_25 , L_9 , V_9 ) ;
F_18 ( V_2 , V_34 ) ;
}
return 0 ;
V_30:
V_2 -> V_10 . V_11 . V_35 ( V_2 ) ;
V_27:
F_9 ( V_2 ) ;
F_19 ( V_2 -> V_23 ) ;
V_2 -> V_23 = NULL ;
return V_9 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_5 ( V_2 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_25 , L_10 ) ;
return V_9 ;
}
F_18 ( V_2 , V_34 ) ;
return V_9 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_9 ;
struct V_36 V_37 ;
struct V_17 * V_18 = V_2 -> V_19 ;
F_14 ( V_2 -> V_25 , L_11 , V_38 ) ;
F_22 ( & V_2 -> V_39 ) ;
if ( ! F_23 ( V_2 ) ) {
F_24 ( & V_2 -> V_39 ) ;
return 0 ;
}
F_24 ( & V_2 -> V_39 ) ;
V_37 . V_40 = V_41 ;
V_37 . V_42 = V_43 ;
V_9 = F_25 ( & V_18 -> V_44 , V_45 , V_46 , & V_37 ) ;
if ( V_9 < 0 )
F_8 ( V_2 -> V_25 ,
L_12 , V_9 ) ;
V_2 -> V_10 . V_11 . V_35 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
V_9 = F_9 ( V_2 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_25 , L_13 , V_9 ) ;
V_9 = - V_26 ;
}
F_18 ( V_2 , V_47 ) ;
return V_9 ;
}
static unsigned int F_29 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_48 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_2 V_49 )
{
struct V_50 * V_51 ;
F_31 (module, &ctx->module_list, list) {
if ( V_51 -> V_52 -> V_49 == V_49 )
return ++ V_51 -> V_53 ;
}
return - V_54 ;
}
static int F_32 ( struct V_1 * V_2 , T_2 V_49 )
{
struct V_50 * V_51 ;
F_31 (module, &ctx->module_list, list) {
if ( V_51 -> V_52 -> V_49 == V_49 )
return -- V_51 -> V_53 ;
}
return - V_54 ;
}
static struct V_50 * F_33 ( struct V_1 * V_2 ,
char * V_55 , int V_49 )
{
const struct V_56 * V_23 ;
struct V_50 * V_57 ;
unsigned int V_32 ;
int V_9 ;
V_9 = F_7 ( & V_23 , V_55 , V_2 -> V_25 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_25 , L_14 ,
V_55 , V_9 ) ;
return NULL ;
}
V_57 = F_34 ( V_2 -> V_25 , sizeof( * V_57 ) , V_58 ) ;
if ( V_57 == NULL ) {
F_19 ( V_23 ) ;
return NULL ;
}
V_32 = sizeof( * V_57 -> V_52 ) ;
V_57 -> V_52 = F_34 ( V_2 -> V_25 , V_32 , V_58 ) ;
if ( V_57 -> V_52 == NULL ) {
F_19 ( V_23 ) ;
return NULL ;
}
V_57 -> V_52 -> V_49 = V_49 ;
V_57 -> V_52 -> V_23 = V_23 ;
F_35 ( & V_57 -> V_59 , & V_2 -> V_60 ) ;
return V_57 ;
}
static struct V_50 * F_36 (
struct V_1 * V_2 , T_2 V_49 )
{
struct V_50 * V_51 ;
if ( F_37 ( & V_2 -> V_60 ) ) {
F_8 ( V_2 -> V_25 , L_15 ) ;
return NULL ;
}
F_31 (module, &ctx->module_list, list) {
if ( V_51 -> V_52 -> V_49 == V_49 )
return V_51 ;
}
return NULL ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_61 * V_51 )
{
int V_9 ;
struct V_17 * V_18 = V_2 -> V_19 ;
V_9 = V_2 -> V_10 . V_11 . V_12 ( V_2 , V_51 -> V_23 -> V_31 ,
V_51 -> V_23 -> V_32 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_39 ( & V_18 -> V_44 , V_62 ,
( void * ) & V_51 -> V_49 ) ;
if ( V_9 < 0 )
F_8 ( V_2 -> V_25 , L_16 , V_9 ) ;
V_2 -> V_10 . V_11 . V_15 ( V_2 ) ;
return V_9 ;
}
static int F_40 ( struct V_1 * V_2 , T_2 V_49 , T_3 * V_63 )
{
struct V_50 * V_64 = NULL ;
int V_9 = 0 ;
char V_55 [ 64 ] ;
T_4 * V_65 ;
V_65 = ( T_4 * ) V_63 ;
snprintf ( V_55 , sizeof( V_55 ) , L_17 ,
L_18 , V_65 , L_19 ) ;
V_64 = F_36 ( V_2 , V_49 ) ;
if ( V_64 == NULL ) {
V_64 = F_33 ( V_2 , V_55 , V_49 ) ;
if ( V_64 == NULL ) {
F_8 ( V_2 -> V_25 , L_20 ) ;
return - V_54 ;
}
}
if ( ! V_64 -> V_53 ) {
V_9 = F_38 ( V_2 , V_64 -> V_52 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_25 , L_20 ) ;
return V_9 ;
}
}
V_9 = F_30 ( V_2 , V_49 ) ;
return V_9 ;
}
static int F_41 ( struct V_1 * V_2 , T_2 V_49 )
{
int V_53 ;
struct V_17 * V_18 = V_2 -> V_19 ;
int V_9 = 0 ;
V_53 = F_32 ( V_2 , V_49 ) ;
if ( V_53 < 0 ) {
F_8 ( V_2 -> V_25 , L_21 , V_53 ) ;
return - V_26 ;
}
V_9 = F_42 ( & V_18 -> V_44 ,
V_62 , & V_49 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_25 , L_22 ) ;
F_30 ( V_2 , V_49 ) ;
return V_9 ;
}
return V_9 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_50 * V_51 , * V_66 ;
if ( F_37 ( & V_2 -> V_60 ) )
return;
F_44 (module, tmp, &ctx->module_list, list) {
F_45 ( & V_51 -> V_59 ) ;
F_19 ( V_51 -> V_52 -> V_23 ) ;
}
}
int F_46 ( struct V_67 * V_25 , void T_5 * V_68 , int V_69 ,
const char * V_24 , struct V_70 V_71 , struct V_17 * * V_72 )
{
struct V_17 * V_18 ;
struct V_1 * V_73 ;
int V_9 ;
V_18 = F_34 ( V_25 , sizeof( * V_18 ) , V_58 ) ;
if ( V_18 == NULL )
return - V_74 ;
V_18 -> V_25 = V_25 ;
V_75 . V_19 = V_18 ;
V_18 -> V_72 = F_47 ( V_25 , & V_75 , V_69 ) ;
if ( ! V_18 -> V_72 ) {
F_8 ( V_18 -> V_25 , L_23 , V_38 ) ;
return - V_76 ;
}
V_73 = V_18 -> V_72 ;
V_73 -> V_24 = V_24 ;
V_73 -> V_77 . V_78 = V_68 ;
V_73 -> V_77 . V_79 = V_68 ;
F_48 ( V_73 , ( V_80 + V_81 ) ,
V_82 , V_83 , V_84 ) ;
F_49 ( & V_73 -> V_60 ) ;
V_73 -> V_71 = V_71 ;
V_73 -> V_85 = V_86 ;
V_9 = F_50 ( V_25 , V_18 ) ;
if ( V_9 )
return V_9 ;
V_9 = V_73 -> V_85 . V_87 ( V_73 ) ;
if ( V_9 < 0 ) {
F_8 ( V_25 , L_24 , V_9 ) ;
goto V_88;
}
if ( V_72 )
* V_72 = V_18 ;
return V_9 ;
V_88:
F_51 ( V_25 , V_18 ) ;
return V_9 ;
}
void F_51 ( struct V_67 * V_25 , struct V_17 * V_2 )
{
F_43 ( V_2 -> V_72 ) ;
F_52 ( & V_2 -> V_44 ) ;
V_2 -> V_72 -> V_11 -> free ( V_2 -> V_72 ) ;
if ( V_2 -> V_21 ) {
V_2 -> V_72 -> V_10 . V_11 . V_35 ( V_2 -> V_72 ) ;
F_26 ( V_2 -> V_72 ) ;
}
}
