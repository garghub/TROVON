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
struct V_20 V_21 ;
T_1 V_22 ;
V_18 -> V_23 = false ;
F_6 ( & V_18 -> V_24 ) ;
if ( V_2 -> V_25 == NULL ) {
V_9 = F_7 ( & V_2 -> V_25 , V_2 -> V_26 , V_2 -> V_27 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_27 , L_2 , V_9 ) ;
return - V_28 ;
}
}
if ( V_18 -> V_29 ) {
V_9 = F_9 ( V_2 , V_2 -> V_25 , V_30 , 0 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_27 , L_3 , V_9 ) ;
F_10 ( V_2 -> V_25 ) ;
F_11 ( V_2 , V_31 ) ;
return V_9 ;
}
}
V_21 . V_32 = V_2 -> V_25 -> V_32 ;
V_21 . V_33 = V_2 -> V_25 -> V_33 ;
F_12 ( & V_21 ) ;
V_9 = F_13 ( V_2 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_27 , L_4 , V_9 ) ;
goto V_34;
}
V_9 = F_14 ( V_2 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_27 , L_5 , V_9 ) ;
goto V_34;
}
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
for ( V_16 = V_35 ; V_16 > 0 ; -- V_16 ) {
if ( F_1 ( V_2 , V_36 ) ) {
F_17 ( V_2 -> V_27 ,
L_6 ) ;
break;
}
F_18 ( 1 ) ;
}
if ( ! V_16 ) {
V_22 = F_2 ( V_2 , V_5 ) ;
F_8 ( V_2 -> V_27 ,
L_7 , V_22 ) ;
V_9 = - V_28 ;
goto V_37;
}
V_9 = F_3 ( V_2 , V_21 . V_32 , V_21 . V_33 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_27 , L_8 , V_9 ) ;
goto V_37;
} else {
V_9 = F_19 ( V_18 -> V_24 , V_18 -> V_23 ,
F_20 ( V_38 ) ) ;
if ( V_9 == 0 ) {
F_8 ( V_2 -> V_27 , L_9 ) ;
V_9 = - V_28 ;
goto V_37;
}
F_17 ( V_2 -> V_27 , L_10 , V_9 ) ;
V_18 -> V_39 = true ;
}
return 0 ;
V_37:
V_2 -> V_10 . V_11 . V_40 ( V_2 ) ;
V_34:
F_11 ( V_2 , V_31 ) ;
F_10 ( V_2 -> V_25 ) ;
V_2 -> V_25 = NULL ;
return V_9 ;
}
static int F_21 ( struct V_1 * V_2 , unsigned int V_41 )
{
int V_9 ;
struct V_42 V_43 ;
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned int V_44 = F_22 ( V_41 ) ;
if ( V_41 == V_45 ) {
V_9 = F_5 ( V_2 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_27 , L_11 ) ;
return V_9 ;
}
}
if ( V_41 != V_45 ) {
V_9 = F_23 ( V_2 , V_44 ) ;
if ( V_9 < 0 )
return V_9 ;
V_43 . V_44 = V_44 ;
V_43 . V_46 = V_44 ;
V_9 = F_24 ( & V_18 -> V_47 , V_48 ,
V_49 , & V_43 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_27 , L_12 ,
V_41 ) ;
F_11 ( V_2 , V_44 ) ;
}
}
V_18 -> V_50 . V_51 [ V_41 ] = V_52 ;
return V_9 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned int V_41 )
{
int V_9 ;
struct V_42 V_43 ;
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned int V_44 = F_22 ( V_41 ) ;
V_43 . V_44 = V_44 ;
V_43 . V_46 = V_53 ;
V_9 = F_24 ( & V_18 -> V_47 , V_48 , V_49 , & V_43 ) ;
if ( V_9 < 0 )
F_8 ( V_2 -> V_27 , L_13 , V_41 , V_9 ) ;
if ( V_41 == V_45 ) {
V_2 -> V_10 . V_11 . V_40 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
}
V_9 = F_11 ( V_2 , V_44 ) ;
if ( V_9 < 0 )
return V_9 ;
V_18 -> V_50 . V_51 [ V_41 ] = V_54 ;
return V_9 ;
}
static unsigned int F_29 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_55 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_2 V_56 )
{
struct V_57 * V_58 ;
F_31 (module, &ctx->module_list, list) {
if ( V_58 -> V_59 -> V_56 == V_56 )
return ++ V_58 -> V_60 ;
}
return - V_61 ;
}
static int F_32 ( struct V_1 * V_2 , T_2 V_56 )
{
struct V_57 * V_58 ;
F_31 (module, &ctx->module_list, list) {
if ( V_58 -> V_59 -> V_56 == V_56 )
return -- V_58 -> V_60 ;
}
return - V_61 ;
}
static struct V_57 * F_33 ( struct V_1 * V_2 ,
char * V_62 , int V_56 )
{
const struct V_20 * V_25 ;
struct V_57 * V_63 ;
unsigned int V_33 ;
int V_9 ;
V_9 = F_7 ( & V_25 , V_62 , V_2 -> V_27 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_27 , L_14 ,
V_62 , V_9 ) ;
return NULL ;
}
V_63 = F_34 ( V_2 -> V_27 , sizeof( * V_63 ) , V_64 ) ;
if ( V_63 == NULL ) {
F_10 ( V_25 ) ;
return NULL ;
}
V_33 = sizeof( * V_63 -> V_59 ) ;
V_63 -> V_59 = F_34 ( V_2 -> V_27 , V_33 , V_64 ) ;
if ( V_63 -> V_59 == NULL ) {
F_10 ( V_25 ) ;
return NULL ;
}
V_63 -> V_59 -> V_56 = V_56 ;
V_63 -> V_59 -> V_25 = V_25 ;
F_35 ( & V_63 -> V_65 , & V_2 -> V_66 ) ;
return V_63 ;
}
static struct V_57 * F_36 (
struct V_1 * V_2 , T_2 V_56 )
{
struct V_57 * V_58 ;
if ( F_37 ( & V_2 -> V_66 ) ) {
F_8 ( V_2 -> V_27 , L_15 ) ;
return NULL ;
}
F_31 (module, &ctx->module_list, list) {
if ( V_58 -> V_59 -> V_56 == V_56 )
return V_58 ;
}
return NULL ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_67 * V_58 )
{
int V_9 ;
struct V_17 * V_18 = V_2 -> V_19 ;
V_9 = V_2 -> V_10 . V_11 . V_12 ( V_2 , V_58 -> V_25 -> V_32 ,
V_58 -> V_25 -> V_33 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_39 ( & V_18 -> V_47 , V_68 ,
( void * ) & V_58 -> V_56 ) ;
if ( V_9 < 0 )
F_8 ( V_2 -> V_27 , L_16 , V_9 ) ;
V_2 -> V_10 . V_11 . V_15 ( V_2 ) ;
return V_9 ;
}
static int F_40 ( struct V_1 * V_2 , T_2 V_56 , T_3 * V_69 )
{
struct V_57 * V_70 = NULL ;
int V_9 = 0 ;
char V_62 [ 64 ] ;
T_4 * V_71 ;
V_71 = ( T_4 * ) V_69 ;
snprintf ( V_62 , sizeof( V_62 ) , L_17 ,
L_18 , V_71 , L_19 ) ;
V_70 = F_36 ( V_2 , V_56 ) ;
if ( V_70 == NULL ) {
V_70 = F_33 ( V_2 , V_62 , V_56 ) ;
if ( V_70 == NULL ) {
F_8 ( V_2 -> V_27 , L_20 ) ;
return - V_61 ;
}
}
if ( ! V_70 -> V_60 ) {
V_9 = F_38 ( V_2 , V_70 -> V_59 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_27 , L_20 ) ;
return V_9 ;
}
}
V_9 = F_30 ( V_2 , V_56 ) ;
return V_9 ;
}
static int F_41 ( struct V_1 * V_2 , T_2 V_56 )
{
int V_60 ;
struct V_17 * V_18 = V_2 -> V_19 ;
int V_9 = 0 ;
V_60 = F_32 ( V_2 , V_56 ) ;
if ( V_60 < 0 ) {
F_8 ( V_2 -> V_27 , L_21 , V_60 ) ;
return - V_28 ;
}
V_9 = F_42 ( & V_18 -> V_47 ,
V_68 , & V_56 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_27 , L_22 ) ;
F_30 ( V_2 , V_56 ) ;
return V_9 ;
}
return V_9 ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
if ( F_37 ( & V_2 -> V_66 ) )
return;
F_31 (module, &ctx->module_list, list) {
V_58 -> V_60 = 0 ;
}
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_57 * V_58 , * V_72 ;
if ( F_37 ( & V_2 -> V_66 ) )
return;
F_45 (module, tmp, &ctx->module_list, list) {
F_46 ( & V_58 -> V_65 ) ;
F_10 ( V_58 -> V_59 -> V_25 ) ;
}
}
int F_47 ( struct V_73 * V_27 , void T_5 * V_74 , int V_75 ,
const char * V_26 , struct V_76 V_77 , struct V_17 * * V_78 )
{
struct V_17 * V_18 ;
struct V_1 * V_79 ;
int V_9 ;
V_18 = F_34 ( V_27 , sizeof( * V_18 ) , V_64 ) ;
if ( V_18 == NULL )
return - V_80 ;
V_18 -> V_27 = V_27 ;
V_81 . V_19 = V_18 ;
F_48 ( & V_18 -> V_82 ) ;
V_18 -> V_78 = F_49 ( V_27 , & V_81 , V_75 ) ;
if ( ! V_18 -> V_78 ) {
F_8 ( V_18 -> V_27 , L_23 , V_83 ) ;
return - V_84 ;
}
V_79 = V_18 -> V_78 ;
V_79 -> V_26 = V_26 ;
V_79 -> V_85 . V_86 = V_74 ;
V_79 -> V_85 . V_87 = V_74 ;
F_50 ( V_79 , ( V_88 + V_89 ) ,
V_90 , V_91 , V_92 ) ;
F_48 ( & V_79 -> V_66 ) ;
V_79 -> V_77 = V_77 ;
V_79 -> V_93 = V_94 ;
V_9 = F_51 ( V_27 , V_18 ) ;
if ( V_9 )
return V_9 ;
V_18 -> V_50 . V_95 = 2 ;
V_18 -> V_29 = true ;
if ( V_78 )
* V_78 = V_18 ;
return V_9 ;
}
int F_52 ( struct V_73 * V_27 , struct V_17 * V_2 )
{
int V_9 ;
struct V_1 * V_79 = V_2 -> V_78 ;
V_9 = V_79 -> V_93 . V_96 ( V_79 ) ;
if ( V_9 < 0 ) {
F_8 ( V_27 , L_24 , V_9 ) ;
return V_9 ;
}
F_53 ( V_79 ) ;
V_2 -> V_29 = false ;
return 0 ;
}
void F_54 ( struct V_73 * V_27 , struct V_17 * V_2 )
{
F_44 ( V_2 -> V_78 ) ;
F_55 ( V_2 ) ;
F_56 ( & V_2 -> V_47 ) ;
V_2 -> V_78 -> V_11 -> free ( V_2 -> V_78 ) ;
if ( V_2 -> V_23 ) {
V_2 -> V_78 -> V_10 . V_11 . V_40 ( V_2 -> V_78 ) ;
F_26 ( V_2 -> V_78 ) ;
}
}
