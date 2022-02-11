static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = * (struct V_4 * * ) V_3 ;
F_2 ( V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 , void * V_3 )
{
struct V_5 * V_5 = * (struct V_5 * * ) V_3 ;
F_4 ( V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = * (struct V_4 * * ) V_3 ;
F_6 ( V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 , void * V_3 , void * V_6 )
{
return V_3 == V_6 ;
}
static struct V_4 * F_8 ( struct V_1 * V_1 , const char * V_7 )
{
unsigned int V_8 ;
struct V_4 * V_4 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_11 V_12 ;
F_9 ( & V_12 , V_13 , NULL , NULL ) ;
while ( ( V_2 = F_10 ( & V_12 ) ) ) {
V_4 = F_11 ( V_2 ) ;
if ( ! V_4 -> V_14 )
continue;
V_8 = V_4 -> V_14 -> V_15 ;
V_10 = V_4 -> V_14 -> V_10 ;
while ( V_8 -- ) {
if ( ! strcmp ( V_10 -> V_16 , V_16 ( V_1 ) ) &&
! strcmp ( V_10 -> V_7 , V_7 ) ) {
F_12 ( & V_12 ) ;
return V_4 ;
}
V_10 ++ ;
}
}
F_12 ( & V_12 ) ;
return F_13 ( - V_17 ) ;
}
static struct V_5 * F_14 ( struct V_18 * V_19 )
{
struct V_5 * V_5 ;
struct V_18 * V_20 ;
F_15 (phy_provider, &phy_provider_list, list) {
if ( V_5 -> V_2 -> V_21 == V_19 )
return V_5 ;
F_16 (phy_provider->dev->of_node, child)
if ( V_20 == V_19 )
return V_5 ;
}
return F_13 ( - V_22 ) ;
}
int F_17 ( struct V_4 * V_4 )
{
int V_23 ;
if ( ! F_18 ( & V_4 -> V_2 ) )
return - V_24 ;
V_23 = F_19 ( & V_4 -> V_2 ) ;
if ( V_23 < 0 && V_23 != - V_25 )
F_20 ( & V_4 -> V_2 ) ;
return V_23 ;
}
int F_21 ( struct V_4 * V_4 )
{
int V_23 ;
if ( ! F_18 ( & V_4 -> V_2 ) )
return - V_24 ;
V_23 = F_22 ( & V_4 -> V_2 ) ;
if ( V_23 < 0 )
F_23 ( & V_4 -> V_2 ) ;
return V_23 ;
}
int F_24 ( struct V_4 * V_4 )
{
if ( ! F_18 ( & V_4 -> V_2 ) )
return - V_24 ;
return F_25 ( & V_4 -> V_2 ) ;
}
int F_26 ( struct V_4 * V_4 )
{
if ( ! F_18 ( & V_4 -> V_2 ) )
return - V_24 ;
return F_23 ( & V_4 -> V_2 ) ;
}
void F_27 ( struct V_4 * V_4 )
{
if ( ! F_18 ( & V_4 -> V_2 ) )
return;
F_28 ( & V_4 -> V_2 ) ;
}
void F_29 ( struct V_4 * V_4 )
{
if ( ! F_18 ( & V_4 -> V_2 ) )
return;
F_30 ( & V_4 -> V_2 ) ;
}
int F_31 ( struct V_4 * V_4 )
{
int V_23 ;
if ( ! V_4 )
return 0 ;
V_23 = F_21 ( V_4 ) ;
if ( V_23 < 0 && V_23 != - V_24 )
return V_23 ;
F_32 ( & V_4 -> V_26 ) ;
if ( V_4 -> V_27 == 0 && V_4 -> V_28 -> V_29 ) {
V_23 = V_4 -> V_28 -> V_29 ( V_4 ) ;
if ( V_23 < 0 ) {
F_33 ( & V_4 -> V_2 , L_1 , V_23 ) ;
goto V_30;
}
} else {
V_23 = 0 ;
}
++ V_4 -> V_27 ;
V_30:
F_34 ( & V_4 -> V_26 ) ;
F_24 ( V_4 ) ;
return V_23 ;
}
int F_35 ( struct V_4 * V_4 )
{
int V_23 ;
if ( ! V_4 )
return 0 ;
V_23 = F_21 ( V_4 ) ;
if ( V_23 < 0 && V_23 != - V_24 )
return V_23 ;
F_32 ( & V_4 -> V_26 ) ;
if ( V_4 -> V_27 == 1 && V_4 -> V_28 -> exit ) {
V_23 = V_4 -> V_28 -> exit ( V_4 ) ;
if ( V_23 < 0 ) {
F_33 ( & V_4 -> V_2 , L_2 , V_23 ) ;
goto V_30;
}
}
-- V_4 -> V_27 ;
V_30:
F_34 ( & V_4 -> V_26 ) ;
F_24 ( V_4 ) ;
return V_23 ;
}
int F_36 ( struct V_4 * V_4 )
{
int V_23 ;
if ( ! V_4 )
return 0 ;
if ( V_4 -> V_31 ) {
V_23 = F_37 ( V_4 -> V_31 ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_21 ( V_4 ) ;
if ( V_23 < 0 && V_23 != - V_24 )
return V_23 ;
F_32 ( & V_4 -> V_26 ) ;
if ( V_4 -> V_32 == 0 && V_4 -> V_28 -> V_33 ) {
V_23 = V_4 -> V_28 -> V_33 ( V_4 ) ;
if ( V_23 < 0 ) {
F_33 ( & V_4 -> V_2 , L_3 , V_23 ) ;
goto V_30;
}
} else {
V_23 = 0 ;
}
++ V_4 -> V_32 ;
F_34 ( & V_4 -> V_26 ) ;
return 0 ;
V_30:
F_34 ( & V_4 -> V_26 ) ;
F_26 ( V_4 ) ;
if ( V_4 -> V_31 )
F_38 ( V_4 -> V_31 ) ;
return V_23 ;
}
int F_39 ( struct V_4 * V_4 )
{
int V_23 ;
if ( ! V_4 )
return 0 ;
F_32 ( & V_4 -> V_26 ) ;
if ( V_4 -> V_32 == 1 && V_4 -> V_28 -> V_34 ) {
V_23 = V_4 -> V_28 -> V_34 ( V_4 ) ;
if ( V_23 < 0 ) {
F_33 ( & V_4 -> V_2 , L_4 , V_23 ) ;
F_34 ( & V_4 -> V_26 ) ;
return V_23 ;
}
}
-- V_4 -> V_32 ;
F_34 ( & V_4 -> V_26 ) ;
F_24 ( V_4 ) ;
if ( V_4 -> V_31 )
F_38 ( V_4 -> V_31 ) ;
return 0 ;
}
static struct V_4 * F_40 ( struct V_18 * V_35 , int V_36 )
{
int V_23 ;
struct V_5 * V_5 ;
struct V_4 * V_4 = NULL ;
struct V_37 args ;
V_23 = F_41 ( V_35 , L_5 , L_6 ,
V_36 , & args ) ;
if ( V_23 )
return F_13 ( - V_17 ) ;
F_32 ( & V_38 ) ;
V_5 = F_14 ( args . V_35 ) ;
if ( F_42 ( V_5 ) || ! F_43 ( V_5 -> V_39 ) ) {
V_4 = F_13 ( - V_22 ) ;
goto V_40;
}
V_4 = V_5 -> V_41 ( V_5 -> V_2 , & args ) ;
F_44 ( V_5 -> V_39 ) ;
V_40:
F_34 ( & V_38 ) ;
F_45 ( args . V_35 ) ;
return V_4 ;
}
struct V_4 * F_46 ( struct V_18 * V_35 , const char * V_42 )
{
struct V_4 * V_4 = NULL ;
int V_36 = 0 ;
if ( V_42 )
V_36 = F_47 ( V_35 , L_7 , V_42 ) ;
V_4 = F_40 ( V_35 , V_36 ) ;
if ( F_42 ( V_4 ) )
return V_4 ;
if ( ! F_43 ( V_4 -> V_28 -> V_39 ) )
return F_13 ( - V_22 ) ;
F_48 ( & V_4 -> V_2 ) ;
return V_4 ;
}
void F_2 ( struct V_4 * V_4 )
{
if ( ! V_4 || F_42 ( V_4 ) )
return;
F_44 ( V_4 -> V_28 -> V_39 ) ;
F_49 ( & V_4 -> V_2 ) ;
}
void F_50 ( struct V_1 * V_2 , struct V_4 * V_4 )
{
int V_43 ;
if ( ! V_4 )
return;
V_43 = F_51 ( V_2 , F_1 , F_7 , V_4 ) ;
F_52 ( V_2 , V_43 , L_8 ) ;
}
struct V_4 * F_53 ( struct V_1 * V_2 , struct V_37
* args )
{
struct V_4 * V_4 ;
struct V_11 V_12 ;
struct V_18 * V_19 = V_2 -> V_21 ;
struct V_18 * V_20 ;
F_9 ( & V_12 , V_13 , NULL , NULL ) ;
while ( ( V_2 = F_10 ( & V_12 ) ) ) {
V_4 = F_11 ( V_2 ) ;
if ( V_19 != V_4 -> V_2 . V_21 ) {
F_16 (node, child) {
if ( V_20 == V_4 -> V_2 . V_21 )
goto V_44;
}
continue;
}
V_44:
F_12 ( & V_12 ) ;
return V_4 ;
}
F_12 ( & V_12 ) ;
return F_13 ( - V_17 ) ;
}
struct V_4 * F_54 ( struct V_1 * V_2 , const char * string )
{
int V_36 = 0 ;
struct V_4 * V_4 ;
if ( string == NULL ) {
F_55 ( V_2 , L_9 ) ;
return F_13 ( - V_45 ) ;
}
if ( V_2 -> V_21 ) {
V_36 = F_47 ( V_2 -> V_21 , L_7 ,
string ) ;
V_4 = F_40 ( V_2 -> V_21 , V_36 ) ;
} else {
V_4 = F_8 ( V_2 , string ) ;
}
if ( F_42 ( V_4 ) )
return V_4 ;
if ( ! F_43 ( V_4 -> V_28 -> V_39 ) )
return F_13 ( - V_22 ) ;
F_48 ( & V_4 -> V_2 ) ;
return V_4 ;
}
struct V_4 * F_56 ( struct V_1 * V_2 , const char * string )
{
struct V_4 * V_4 = F_54 ( V_2 , string ) ;
if ( F_57 ( V_4 ) == - V_17 )
V_4 = NULL ;
return V_4 ;
}
struct V_4 * F_58 ( struct V_1 * V_2 , const char * string )
{
struct V_4 * * V_46 , * V_4 ;
V_46 = F_59 ( F_1 , sizeof( * V_46 ) , V_47 ) ;
if ( ! V_46 )
return F_13 ( - V_48 ) ;
V_4 = F_54 ( V_2 , string ) ;
if ( ! F_42 ( V_4 ) ) {
* V_46 = V_4 ;
F_60 ( V_2 , V_46 ) ;
} else {
F_61 ( V_46 ) ;
}
return V_4 ;
}
struct V_4 * F_62 ( struct V_1 * V_2 , const char * string )
{
struct V_4 * V_4 = F_58 ( V_2 , string ) ;
if ( F_57 ( V_4 ) == - V_17 )
V_4 = NULL ;
return V_4 ;
}
struct V_4 * F_63 ( struct V_1 * V_2 , struct V_18 * V_35 ,
const char * V_42 )
{
struct V_4 * * V_46 , * V_4 ;
V_46 = F_59 ( F_1 , sizeof( * V_46 ) , V_47 ) ;
if ( ! V_46 )
return F_13 ( - V_48 ) ;
V_4 = F_46 ( V_35 , V_42 ) ;
if ( ! F_42 ( V_4 ) ) {
* V_46 = V_4 ;
F_60 ( V_2 , V_46 ) ;
} else {
F_61 ( V_46 ) ;
}
return V_4 ;
}
struct V_4 * F_64 ( struct V_1 * V_2 , struct V_18 * V_19 ,
const struct V_49 * V_28 ,
struct V_50 * V_14 )
{
int V_23 ;
int V_51 ;
struct V_4 * V_4 ;
if ( F_65 ( ! V_2 ) )
return F_13 ( - V_45 ) ;
V_4 = F_66 ( sizeof( * V_4 ) , V_47 ) ;
if ( ! V_4 )
return F_13 ( - V_48 ) ;
V_51 = F_67 ( & V_52 , 0 , 0 , V_47 ) ;
if ( V_51 < 0 ) {
F_33 ( V_2 , L_10 ) ;
V_23 = V_51 ;
goto V_53;
}
V_4 -> V_31 = F_68 ( V_2 , L_11 ) ;
if ( F_42 ( V_4 -> V_31 ) ) {
if ( F_57 ( V_4 -> V_31 ) == - V_22 ) {
V_23 = - V_22 ;
goto V_54;
}
V_4 -> V_31 = NULL ;
}
F_69 ( & V_4 -> V_2 ) ;
F_70 ( & V_4 -> V_26 ) ;
V_4 -> V_2 . V_55 = V_13 ;
V_4 -> V_2 . V_56 = V_2 ;
V_4 -> V_2 . V_21 = V_19 ? : V_2 -> V_21 ;
V_4 -> V_51 = V_51 ;
V_4 -> V_28 = V_28 ;
V_4 -> V_14 = V_14 ;
V_23 = F_71 ( & V_4 -> V_2 , L_12 , V_16 ( V_2 ) , V_51 ) ;
if ( V_23 )
goto V_57;
V_23 = F_72 ( & V_4 -> V_2 ) ;
if ( V_23 )
goto V_57;
if ( F_18 ( V_2 ) ) {
F_73 ( & V_4 -> V_2 ) ;
F_74 ( & V_4 -> V_2 ) ;
}
return V_4 ;
V_57:
F_49 ( & V_4 -> V_2 ) ;
return F_13 ( V_23 ) ;
V_54:
F_75 ( & V_52 , V_4 -> V_51 ) ;
V_53:
F_76 ( V_4 ) ;
return F_13 ( V_23 ) ;
}
struct V_4 * F_77 ( struct V_1 * V_2 , struct V_18 * V_19 ,
const struct V_49 * V_28 ,
struct V_50 * V_14 )
{
struct V_4 * * V_46 , * V_4 ;
V_46 = F_59 ( F_5 , sizeof( * V_46 ) , V_47 ) ;
if ( ! V_46 )
return F_13 ( - V_48 ) ;
V_4 = F_64 ( V_2 , V_19 , V_28 , V_14 ) ;
if ( ! F_42 ( V_4 ) ) {
* V_46 = V_4 ;
F_60 ( V_2 , V_46 ) ;
} else {
F_61 ( V_46 ) ;
}
return V_4 ;
}
void F_6 ( struct V_4 * V_4 )
{
F_78 ( & V_4 -> V_2 ) ;
F_79 ( & V_4 -> V_2 ) ;
}
void F_80 ( struct V_1 * V_2 , struct V_4 * V_4 )
{
int V_43 ;
V_43 = F_51 ( V_2 , F_5 , F_7 , V_4 ) ;
F_52 ( V_2 , V_43 , L_8 ) ;
}
void F_4 ( struct V_5 * V_5 )
{
if ( F_42 ( V_5 ) )
return;
F_32 ( & V_38 ) ;
F_81 ( & V_5 -> V_58 ) ;
F_76 ( V_5 ) ;
F_34 ( & V_38 ) ;
}
void F_82 ( struct V_1 * V_2 ,
struct V_5 * V_5 ) {
int V_43 ;
V_43 = F_51 ( V_2 , F_3 , F_7 ,
V_5 ) ;
F_52 ( V_2 , V_43 , L_13 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_4 * V_4 ;
V_4 = F_11 ( V_2 ) ;
F_84 ( V_2 , L_14 , V_16 ( V_2 ) ) ;
F_85 ( V_4 -> V_31 ) ;
F_75 ( & V_52 , V_4 -> V_51 ) ;
F_76 ( V_4 ) ;
}
static int T_1 F_86 ( void )
{
V_13 = F_87 ( V_59 , L_11 ) ;
if ( F_42 ( V_13 ) ) {
F_88 ( L_15 ,
F_57 ( V_13 ) ) ;
return F_57 ( V_13 ) ;
}
V_13 -> V_60 = F_83 ;
return 0 ;
}
static void T_2 F_89 ( void )
{
F_90 ( V_13 ) ;
}
