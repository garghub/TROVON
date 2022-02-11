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
V_9 = V_2 -> V_10 . V_11 . V_12 ( V_2 , V_7 , V_8 ,
true ) ;
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
if ( V_18 -> V_46 > 1 ) {
V_9 = V_2 -> V_47 . V_48 ( V_2 , V_18 -> V_49 ,
V_18 -> V_46 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_27 , L_12 ,
V_9 ) ;
return V_9 ;
}
}
}
if ( V_41 != V_45 ) {
V_9 = F_23 ( V_2 , V_44 ) ;
if ( V_9 < 0 )
return V_9 ;
V_43 . V_44 = V_44 ;
V_43 . V_50 = V_44 ;
V_9 = F_24 ( & V_18 -> V_51 , V_52 ,
V_53 , & V_43 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_27 , L_13 ,
V_41 ) ;
F_11 ( V_2 , V_44 ) ;
}
}
V_18 -> V_54 . V_55 [ V_41 ] = V_56 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned int V_41 )
{
int V_9 ;
struct V_42 V_43 ;
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned int V_44 = F_22 ( V_41 ) ;
V_43 . V_44 = V_44 ;
V_43 . V_50 = V_57 ;
V_9 = F_24 ( & V_18 -> V_51 , V_52 , V_53 , & V_43 ) ;
if ( V_9 < 0 )
F_8 ( V_2 -> V_27 , L_14 , V_41 , V_9 ) ;
if ( V_41 == V_45 ) {
V_2 -> V_10 . V_11 . V_40 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
}
V_9 = F_11 ( V_2 , V_44 ) ;
if ( V_9 < 0 )
return V_9 ;
V_18 -> V_54 . V_55 [ V_41 ] = V_58 ;
return V_9 ;
}
static unsigned int F_29 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_59 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_2 V_60 )
{
struct V_61 * V_62 ;
F_31 (module, &ctx->module_list, list) {
if ( V_62 -> V_63 -> V_60 == V_60 )
return ++ V_62 -> V_64 ;
}
return - V_65 ;
}
static int F_32 ( struct V_1 * V_2 , T_2 V_60 )
{
struct V_61 * V_62 ;
F_31 (module, &ctx->module_list, list) {
if ( V_62 -> V_63 -> V_60 == V_60 )
return -- V_62 -> V_64 ;
}
return - V_65 ;
}
static struct V_61 * F_33 ( struct V_1 * V_2 ,
char * V_66 , int V_60 )
{
const struct V_20 * V_25 ;
struct V_61 * V_67 ;
unsigned int V_33 ;
int V_9 ;
V_9 = F_7 ( & V_25 , V_66 , V_2 -> V_27 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_27 , L_15 ,
V_66 , V_9 ) ;
return NULL ;
}
V_67 = F_34 ( V_2 -> V_27 , sizeof( * V_67 ) , V_68 ) ;
if ( V_67 == NULL ) {
F_10 ( V_25 ) ;
return NULL ;
}
V_33 = sizeof( * V_67 -> V_63 ) ;
V_67 -> V_63 = F_34 ( V_2 -> V_27 , V_33 , V_68 ) ;
if ( V_67 -> V_63 == NULL ) {
F_10 ( V_25 ) ;
return NULL ;
}
V_67 -> V_63 -> V_60 = V_60 ;
V_67 -> V_63 -> V_25 = V_25 ;
F_35 ( & V_67 -> V_69 , & V_2 -> V_70 ) ;
return V_67 ;
}
static struct V_61 * F_36 (
struct V_1 * V_2 , T_2 V_60 )
{
struct V_61 * V_62 ;
if ( F_37 ( & V_2 -> V_70 ) ) {
F_8 ( V_2 -> V_27 , L_16 ) ;
return NULL ;
}
F_31 (module, &ctx->module_list, list) {
if ( V_62 -> V_63 -> V_60 == V_60 )
return V_62 ;
}
return NULL ;
}
static int F_38 ( struct V_1 * V_2 , const void * V_32 ,
T_1 V_33 , T_2 V_60 , T_3 V_71 , bool V_72 )
{
int V_9 , V_73 , V_74 ;
struct V_17 * V_18 = V_2 -> V_19 ;
V_18 -> V_75 = false ;
V_73 = V_2 -> V_10 . V_11 . V_12 ( V_2 , V_32 , V_33 , false ) ;
if ( V_73 < 0 )
return V_73 ;
if ( V_72 )
V_9 = F_39 ( & V_18 -> V_51 , V_76 , & V_60 ) ;
else
V_9 = F_40 ( & V_18 -> V_51 , 0 , V_71 , false ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_27 , L_17 ,
V_72 ? L_18 : L_19 , V_9 ) ;
goto V_77;
}
while ( V_73 > 0 ) {
V_74 = V_33 - V_73 ;
V_9 = F_41 ( V_2 ) ;
if ( V_9 < 0 )
goto V_77;
V_73 = V_2 -> V_10 . V_11 . V_12 ( V_2 ,
V_32 + V_74 ,
V_73 , false ) ;
}
V_9 = F_19 ( V_18 -> V_78 , V_18 -> V_75 ,
F_20 ( V_38 ) ) ;
if ( V_9 == 0 || ! V_18 -> V_79 ) {
F_8 ( V_2 -> V_27 , L_20 ) ;
V_9 = - V_28 ;
}
V_77:
V_2 -> V_10 . V_11 . V_15 ( V_2 ) ;
return V_9 ;
}
static int
F_42 ( struct V_1 * V_2 , struct V_80 * V_81 , int V_46 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
struct V_20 V_21 ;
int V_9 , V_16 ;
for ( V_16 = 1 ; V_16 < V_46 ; V_16 ++ ) {
V_9 = F_43 ( V_18 , & V_18 -> V_49 [ V_16 ] , & V_21 ,
V_30 , V_16 ) ;
if ( V_9 < 0 )
goto V_82;
V_9 = F_38 ( V_2 , V_21 . V_32 ,
V_21 . V_33 , 0 , V_16 , false ) ;
if ( V_9 < 0 )
goto V_82;
}
return 0 ;
V_82:
F_44 ( V_81 , V_46 ) ;
return V_9 ;
}
static int F_45 ( struct V_1 * V_2 , T_2 V_60 , T_3 * V_83 )
{
struct V_61 * V_84 = NULL ;
int V_9 = 0 ;
char V_66 [ 64 ] ;
T_4 * V_85 ;
V_85 = ( T_4 * ) V_83 ;
snprintf ( V_66 , sizeof( V_66 ) , L_21 ,
L_22 , V_85 , L_23 ) ;
V_84 = F_36 ( V_2 , V_60 ) ;
if ( V_84 == NULL ) {
V_84 = F_33 ( V_2 , V_66 , V_60 ) ;
if ( V_84 == NULL ) {
F_8 ( V_2 -> V_27 , L_24 ) ;
return - V_65 ;
}
}
if ( ! V_84 -> V_64 ) {
V_9 = F_38 ( V_2 , V_84 -> V_63 -> V_25 -> V_32 ,
V_84 -> V_63 -> V_25 -> V_33 ,
V_60 , 0 , true ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_27 , L_24 ) ;
return V_9 ;
}
}
V_9 = F_30 ( V_2 , V_60 ) ;
return V_9 ;
}
static int F_46 ( struct V_1 * V_2 , T_2 V_60 )
{
int V_64 ;
struct V_17 * V_18 = V_2 -> V_19 ;
int V_9 = 0 ;
V_64 = F_32 ( V_2 , V_60 ) ;
if ( V_64 < 0 ) {
F_8 ( V_2 -> V_27 , L_25 , V_64 ) ;
return - V_28 ;
}
if ( V_64 > 0 )
return 0 ;
V_9 = F_47 ( & V_18 -> V_51 ,
V_76 , & V_60 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_27 , L_26 ) ;
F_30 ( V_2 , V_60 ) ;
return V_9 ;
}
return V_9 ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_61 * V_62 ;
if ( F_37 ( & V_2 -> V_70 ) )
return;
F_31 (module, &ctx->module_list, list) {
V_62 -> V_64 = 0 ;
}
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_61 * V_62 , * V_86 ;
if ( F_37 ( & V_2 -> V_70 ) )
return;
F_50 (module, tmp, &ctx->module_list, list) {
F_51 ( & V_62 -> V_69 ) ;
F_10 ( V_62 -> V_63 -> V_25 ) ;
}
}
int F_52 ( struct V_87 * V_27 , void T_5 * V_88 , int V_89 ,
const char * V_26 , struct V_90 V_91 , struct V_17 * * V_92 )
{
struct V_17 * V_18 ;
struct V_1 * V_93 ;
int V_9 ;
V_9 = F_53 ( V_27 , V_89 , V_26 , V_91 , V_92 , & V_94 ) ;
if ( V_9 < 0 ) {
F_8 ( V_27 , L_27 , V_95 ) ;
return V_9 ;
}
V_18 = * V_92 ;
V_93 = V_18 -> V_92 ;
V_93 -> V_96 . V_97 = V_88 ;
V_93 -> V_96 . V_98 = V_88 ;
F_54 ( V_93 , ( V_99 + V_100 ) ,
V_101 , V_102 , V_103 ) ;
V_93 -> V_47 = V_104 ;
V_18 -> V_54 . V_105 = 2 ;
return 0 ;
}
int F_55 ( struct V_87 * V_27 , void T_5 * V_88 , int V_89 ,
const char * V_26 , struct V_90 V_91 ,
struct V_17 * * V_92 )
{
struct V_1 * V_93 ;
int V_9 ;
V_9 = F_52 ( V_27 , V_88 , V_89 , V_26 , V_91 , V_92 ) ;
if ( V_9 < 0 ) {
F_8 ( V_27 , L_28 , V_95 , V_9 ) ;
return V_9 ;
}
V_93 = ( * V_92 ) -> V_92 ;
V_93 -> V_47 = V_106 ;
return 0 ;
}
int F_56 ( struct V_87 * V_27 , struct V_17 * V_2 )
{
int V_9 ;
struct V_1 * V_93 = V_2 -> V_92 ;
V_9 = V_93 -> V_47 . V_107 ( V_93 ) ;
if ( V_9 < 0 ) {
F_8 ( V_27 , L_29 , V_9 ) ;
return V_9 ;
}
F_57 ( V_93 ) ;
if ( V_2 -> V_46 > 1 ) {
V_9 = V_93 -> V_47 . V_48 ( V_93 , V_2 -> V_49 ,
V_2 -> V_46 ) ;
if ( V_9 < 0 ) {
F_8 ( V_27 , L_30 , V_9 ) ;
return V_9 ;
}
}
V_2 -> V_29 = false ;
return 0 ;
}
void F_58 ( struct V_87 * V_27 , struct V_17 * V_2 )
{
if ( V_2 -> V_92 -> V_25 )
F_10 ( V_2 -> V_92 -> V_25 ) ;
F_49 ( V_2 -> V_92 ) ;
F_59 ( V_2 ) ;
F_60 ( & V_2 -> V_51 ) ;
V_2 -> V_92 -> V_11 -> free ( V_2 -> V_92 ) ;
if ( V_2 -> V_23 ) {
V_2 -> V_92 -> V_10 . V_11 . V_40 ( V_2 -> V_92 ) ;
F_26 ( V_2 -> V_92 ) ;
}
}
