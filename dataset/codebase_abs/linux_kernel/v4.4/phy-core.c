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
struct V_4 * * V_4 = V_3 ;
return * V_4 == V_6 ;
}
int F_8 ( struct V_4 * V_4 , const char * V_7 , const char * V_8 )
{
struct V_9 * V_10 ;
if ( ! V_4 || ! V_8 || ! V_7 )
return - V_11 ;
V_10 = F_9 ( sizeof( * V_10 ) , V_12 ) ;
if ( ! V_10 )
return - V_13 ;
V_10 -> V_8 = V_8 ;
V_10 -> V_7 = V_7 ;
V_10 -> V_4 = V_4 ;
F_10 ( & V_14 ) ;
F_11 ( & V_10 -> V_15 , & V_16 ) ;
F_12 ( & V_14 ) ;
return 0 ;
}
void F_13 ( struct V_4 * V_4 , const char * V_7 , const char * V_8 )
{
struct V_9 * V_10 ;
if ( ! V_4 || ! V_8 || ! V_7 )
return;
F_10 ( & V_14 ) ;
F_14 (pl, &phys, node)
if ( V_10 -> V_4 == V_4 && ! strcmp ( V_10 -> V_8 , V_8 ) &&
! strcmp ( V_10 -> V_7 , V_7 ) ) {
F_15 ( & V_10 -> V_15 ) ;
F_16 ( V_10 ) ;
break;
}
F_12 ( & V_14 ) ;
}
static struct V_4 * F_17 ( struct V_1 * V_2 , const char * V_7 )
{
const char * V_8 = F_18 ( V_2 ) ;
struct V_9 * V_17 , * V_10 = NULL ;
F_10 ( & V_14 ) ;
F_14 (p, &phys, node)
if ( ! strcmp ( V_17 -> V_8 , V_8 ) && ! strcmp ( V_17 -> V_7 , V_7 ) ) {
V_10 = V_17 ;
break;
}
F_12 ( & V_14 ) ;
return V_10 ? V_10 -> V_4 : F_19 ( - V_18 ) ;
}
static struct V_5 * F_20 ( struct V_19 * V_15 )
{
struct V_5 * V_5 ;
struct V_19 * V_20 ;
F_14 (phy_provider, &phy_provider_list, list) {
if ( V_5 -> V_2 -> V_21 == V_15 )
return V_5 ;
F_21 (phy_provider->dev->of_node, child)
if ( V_20 == V_15 )
return V_5 ;
}
return F_19 ( - V_22 ) ;
}
int F_22 ( struct V_4 * V_4 )
{
int V_23 ;
if ( ! F_23 ( & V_4 -> V_2 ) )
return - V_24 ;
V_23 = F_24 ( & V_4 -> V_2 ) ;
if ( V_23 < 0 && V_23 != - V_25 )
F_25 ( & V_4 -> V_2 ) ;
return V_23 ;
}
int F_26 ( struct V_4 * V_4 )
{
int V_23 ;
if ( ! F_23 ( & V_4 -> V_2 ) )
return - V_24 ;
V_23 = F_27 ( & V_4 -> V_2 ) ;
if ( V_23 < 0 )
F_28 ( & V_4 -> V_2 ) ;
return V_23 ;
}
int F_29 ( struct V_4 * V_4 )
{
if ( ! F_23 ( & V_4 -> V_2 ) )
return - V_24 ;
return F_30 ( & V_4 -> V_2 ) ;
}
int F_31 ( struct V_4 * V_4 )
{
if ( ! F_23 ( & V_4 -> V_2 ) )
return - V_24 ;
return F_28 ( & V_4 -> V_2 ) ;
}
void F_32 ( struct V_4 * V_4 )
{
if ( ! F_23 ( & V_4 -> V_2 ) )
return;
F_33 ( & V_4 -> V_2 ) ;
}
void F_34 ( struct V_4 * V_4 )
{
if ( ! F_23 ( & V_4 -> V_2 ) )
return;
F_35 ( & V_4 -> V_2 ) ;
}
int F_36 ( struct V_4 * V_4 )
{
int V_23 ;
if ( ! V_4 )
return 0 ;
V_23 = F_26 ( V_4 ) ;
if ( V_23 < 0 && V_23 != - V_24 )
return V_23 ;
V_23 = 0 ;
F_10 ( & V_4 -> V_26 ) ;
if ( V_4 -> V_27 == 0 && V_4 -> V_28 -> V_29 ) {
V_23 = V_4 -> V_28 -> V_29 ( V_4 ) ;
if ( V_23 < 0 ) {
F_37 ( & V_4 -> V_2 , L_1 , V_23 ) ;
goto V_30;
}
}
++ V_4 -> V_27 ;
V_30:
F_12 ( & V_4 -> V_26 ) ;
F_29 ( V_4 ) ;
return V_23 ;
}
int F_38 ( struct V_4 * V_4 )
{
int V_23 ;
if ( ! V_4 )
return 0 ;
V_23 = F_26 ( V_4 ) ;
if ( V_23 < 0 && V_23 != - V_24 )
return V_23 ;
V_23 = 0 ;
F_10 ( & V_4 -> V_26 ) ;
if ( V_4 -> V_27 == 1 && V_4 -> V_28 -> exit ) {
V_23 = V_4 -> V_28 -> exit ( V_4 ) ;
if ( V_23 < 0 ) {
F_37 ( & V_4 -> V_2 , L_2 , V_23 ) ;
goto V_30;
}
}
-- V_4 -> V_27 ;
V_30:
F_12 ( & V_4 -> V_26 ) ;
F_29 ( V_4 ) ;
return V_23 ;
}
int F_39 ( struct V_4 * V_4 )
{
int V_23 ;
if ( ! V_4 )
return 0 ;
if ( V_4 -> V_31 ) {
V_23 = F_40 ( V_4 -> V_31 ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_26 ( V_4 ) ;
if ( V_23 < 0 && V_23 != - V_24 )
return V_23 ;
V_23 = 0 ;
F_10 ( & V_4 -> V_26 ) ;
if ( V_4 -> V_32 == 0 && V_4 -> V_28 -> V_33 ) {
V_23 = V_4 -> V_28 -> V_33 ( V_4 ) ;
if ( V_23 < 0 ) {
F_37 ( & V_4 -> V_2 , L_3 , V_23 ) ;
goto V_30;
}
}
++ V_4 -> V_32 ;
F_12 ( & V_4 -> V_26 ) ;
return 0 ;
V_30:
F_12 ( & V_4 -> V_26 ) ;
F_31 ( V_4 ) ;
if ( V_4 -> V_31 )
F_41 ( V_4 -> V_31 ) ;
return V_23 ;
}
int F_42 ( struct V_4 * V_4 )
{
int V_23 ;
if ( ! V_4 )
return 0 ;
F_10 ( & V_4 -> V_26 ) ;
if ( V_4 -> V_32 == 1 && V_4 -> V_28 -> V_34 ) {
V_23 = V_4 -> V_28 -> V_34 ( V_4 ) ;
if ( V_23 < 0 ) {
F_37 ( & V_4 -> V_2 , L_4 , V_23 ) ;
F_12 ( & V_4 -> V_26 ) ;
return V_23 ;
}
}
-- V_4 -> V_32 ;
F_12 ( & V_4 -> V_26 ) ;
F_29 ( V_4 ) ;
if ( V_4 -> V_31 )
F_41 ( V_4 -> V_31 ) ;
return 0 ;
}
static struct V_4 * F_43 ( struct V_19 * V_35 , int V_36 )
{
int V_23 ;
struct V_5 * V_5 ;
struct V_4 * V_4 = NULL ;
struct V_37 args ;
V_23 = F_44 ( V_35 , L_5 , L_6 ,
V_36 , & args ) ;
if ( V_23 )
return F_19 ( - V_18 ) ;
F_10 ( & V_14 ) ;
V_5 = F_20 ( args . V_35 ) ;
if ( F_45 ( V_5 ) || ! F_46 ( V_5 -> V_38 ) ) {
V_4 = F_19 ( - V_22 ) ;
goto V_39;
}
if ( ! F_47 ( args . V_35 ) ) {
F_48 ( V_5 -> V_2 , L_7 ) ;
V_4 = F_19 ( - V_18 ) ;
goto V_40;
}
V_4 = V_5 -> V_41 ( V_5 -> V_2 , & args ) ;
V_40:
F_49 ( V_5 -> V_38 ) ;
V_39:
F_12 ( & V_14 ) ;
F_50 ( args . V_35 ) ;
return V_4 ;
}
struct V_4 * F_51 ( struct V_19 * V_35 , const char * V_7 )
{
struct V_4 * V_4 = NULL ;
int V_36 = 0 ;
if ( V_7 )
V_36 = F_52 ( V_35 , L_8 , V_7 ) ;
V_4 = F_43 ( V_35 , V_36 ) ;
if ( F_45 ( V_4 ) )
return V_4 ;
if ( ! F_46 ( V_4 -> V_28 -> V_38 ) )
return F_19 ( - V_22 ) ;
F_53 ( & V_4 -> V_2 ) ;
return V_4 ;
}
void F_2 ( struct V_4 * V_4 )
{
if ( ! V_4 || F_45 ( V_4 ) )
return;
F_49 ( V_4 -> V_28 -> V_38 ) ;
F_54 ( & V_4 -> V_2 ) ;
}
void F_55 ( struct V_1 * V_2 , struct V_4 * V_4 )
{
int V_42 ;
if ( ! V_4 )
return;
V_42 = F_56 ( V_2 , F_1 , F_7 , V_4 ) ;
F_57 ( V_2 , V_42 , L_9 ) ;
}
struct V_4 * F_58 ( struct V_1 * V_2 , struct V_37
* args )
{
struct V_4 * V_4 ;
struct V_43 V_44 ;
F_59 ( & V_44 , V_45 , NULL , NULL ) ;
while ( ( V_2 = F_60 ( & V_44 ) ) ) {
V_4 = F_61 ( V_2 ) ;
if ( args -> V_35 != V_4 -> V_2 . V_21 )
continue;
F_62 ( & V_44 ) ;
return V_4 ;
}
F_62 ( & V_44 ) ;
return F_19 ( - V_18 ) ;
}
struct V_4 * F_63 ( struct V_1 * V_2 , const char * string )
{
int V_36 = 0 ;
struct V_4 * V_4 ;
if ( string == NULL ) {
F_64 ( V_2 , L_10 ) ;
return F_19 ( - V_11 ) ;
}
if ( V_2 -> V_21 ) {
V_36 = F_52 ( V_2 -> V_21 , L_8 ,
string ) ;
V_4 = F_43 ( V_2 -> V_21 , V_36 ) ;
} else {
V_4 = F_17 ( V_2 , string ) ;
}
if ( F_45 ( V_4 ) )
return V_4 ;
if ( ! F_46 ( V_4 -> V_28 -> V_38 ) )
return F_19 ( - V_22 ) ;
F_53 ( & V_4 -> V_2 ) ;
return V_4 ;
}
struct V_4 * F_65 ( struct V_1 * V_2 , const char * string )
{
struct V_4 * V_4 = F_63 ( V_2 , string ) ;
if ( F_45 ( V_4 ) && ( F_66 ( V_4 ) == - V_18 ) )
V_4 = NULL ;
return V_4 ;
}
struct V_4 * F_67 ( struct V_1 * V_2 , const char * string )
{
struct V_4 * * V_46 , * V_4 ;
V_46 = F_68 ( F_1 , sizeof( * V_46 ) , V_12 ) ;
if ( ! V_46 )
return F_19 ( - V_13 ) ;
V_4 = F_63 ( V_2 , string ) ;
if ( ! F_45 ( V_4 ) ) {
* V_46 = V_4 ;
F_69 ( V_2 , V_46 ) ;
} else {
F_70 ( V_46 ) ;
}
return V_4 ;
}
struct V_4 * F_71 ( struct V_1 * V_2 , const char * string )
{
struct V_4 * V_4 = F_67 ( V_2 , string ) ;
if ( F_45 ( V_4 ) && ( F_66 ( V_4 ) == - V_18 ) )
V_4 = NULL ;
return V_4 ;
}
struct V_4 * F_72 ( struct V_1 * V_2 , struct V_19 * V_35 ,
const char * V_7 )
{
struct V_4 * * V_46 , * V_4 ;
V_46 = F_68 ( F_1 , sizeof( * V_46 ) , V_12 ) ;
if ( ! V_46 )
return F_19 ( - V_13 ) ;
V_4 = F_51 ( V_35 , V_7 ) ;
if ( ! F_45 ( V_4 ) ) {
* V_46 = V_4 ;
F_69 ( V_2 , V_46 ) ;
} else {
F_70 ( V_46 ) ;
}
return V_4 ;
}
struct V_4 * F_73 ( struct V_1 * V_2 , struct V_19 * V_35 ,
int V_36 )
{
struct V_4 * * V_46 , * V_4 ;
V_46 = F_68 ( F_1 , sizeof( * V_46 ) , V_12 ) ;
if ( ! V_46 )
return F_19 ( - V_13 ) ;
V_4 = F_43 ( V_35 , V_36 ) ;
if ( F_45 ( V_4 ) ) {
F_70 ( V_46 ) ;
return V_4 ;
}
if ( ! F_46 ( V_4 -> V_28 -> V_38 ) ) {
F_70 ( V_46 ) ;
return F_19 ( - V_22 ) ;
}
F_53 ( & V_4 -> V_2 ) ;
* V_46 = V_4 ;
F_69 ( V_2 , V_46 ) ;
return V_4 ;
}
struct V_4 * F_74 ( struct V_1 * V_2 , struct V_19 * V_15 ,
const struct V_47 * V_28 )
{
int V_23 ;
int V_48 ;
struct V_4 * V_4 ;
if ( F_75 ( ! V_2 ) )
return F_19 ( - V_11 ) ;
V_4 = F_9 ( sizeof( * V_4 ) , V_12 ) ;
if ( ! V_4 )
return F_19 ( - V_13 ) ;
V_48 = F_76 ( & V_49 , 0 , 0 , V_12 ) ;
if ( V_48 < 0 ) {
F_37 ( V_2 , L_11 ) ;
V_23 = V_48 ;
goto V_50;
}
F_77 ( & V_4 -> V_2 ) ;
F_78 ( & V_4 -> V_26 ) ;
V_4 -> V_2 . V_51 = V_45 ;
V_4 -> V_2 . V_52 = V_2 ;
V_4 -> V_2 . V_21 = V_15 ? : V_2 -> V_21 ;
V_4 -> V_48 = V_48 ;
V_4 -> V_28 = V_28 ;
V_23 = F_79 ( & V_4 -> V_2 , L_12 , F_18 ( V_2 ) , V_48 ) ;
if ( V_23 )
goto V_53;
V_4 -> V_31 = F_80 ( & V_4 -> V_2 , L_13 ) ;
if ( F_45 ( V_4 -> V_31 ) ) {
V_23 = F_66 ( V_4 -> V_31 ) ;
if ( V_23 == - V_22 )
goto V_53;
V_4 -> V_31 = NULL ;
}
V_23 = F_81 ( & V_4 -> V_2 ) ;
if ( V_23 )
goto V_53;
if ( F_23 ( V_2 ) ) {
F_82 ( & V_4 -> V_2 ) ;
F_83 ( & V_4 -> V_2 ) ;
}
return V_4 ;
V_53:
F_54 ( & V_4 -> V_2 ) ;
return F_19 ( V_23 ) ;
V_50:
F_16 ( V_4 ) ;
return F_19 ( V_23 ) ;
}
struct V_4 * F_84 ( struct V_1 * V_2 , struct V_19 * V_15 ,
const struct V_47 * V_28 )
{
struct V_4 * * V_46 , * V_4 ;
V_46 = F_68 ( F_5 , sizeof( * V_46 ) , V_12 ) ;
if ( ! V_46 )
return F_19 ( - V_13 ) ;
V_4 = F_74 ( V_2 , V_15 , V_28 ) ;
if ( ! F_45 ( V_4 ) ) {
* V_46 = V_4 ;
F_69 ( V_2 , V_46 ) ;
} else {
F_70 ( V_46 ) ;
}
return V_4 ;
}
void F_6 ( struct V_4 * V_4 )
{
F_85 ( & V_4 -> V_2 ) ;
F_86 ( & V_4 -> V_2 ) ;
}
void F_87 ( struct V_1 * V_2 , struct V_4 * V_4 )
{
int V_42 ;
V_42 = F_56 ( V_2 , F_5 , F_7 , V_4 ) ;
F_57 ( V_2 , V_42 , L_9 ) ;
}
void F_4 ( struct V_5 * V_5 )
{
if ( F_45 ( V_5 ) )
return;
F_10 ( & V_14 ) ;
F_15 ( & V_5 -> V_54 ) ;
F_16 ( V_5 ) ;
F_12 ( & V_14 ) ;
}
void F_88 ( struct V_1 * V_2 ,
struct V_5 * V_5 ) {
int V_42 ;
V_42 = F_56 ( V_2 , F_3 , F_7 ,
V_5 ) ;
F_57 ( V_2 , V_42 , L_14 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_4 * V_4 ;
V_4 = F_61 ( V_2 ) ;
F_90 ( V_2 , L_15 , F_18 ( V_2 ) ) ;
F_91 ( V_4 -> V_31 ) ;
F_92 ( & V_49 , V_4 -> V_48 ) ;
F_16 ( V_4 ) ;
}
static int T_1 F_93 ( void )
{
V_45 = F_94 ( V_55 , L_13 ) ;
if ( F_45 ( V_45 ) ) {
F_95 ( L_16 ,
F_66 ( V_45 ) ) ;
return F_66 ( V_45 ) ;
}
V_45 -> V_56 = F_89 ;
return 0 ;
}
static void T_2 F_96 ( void )
{
F_97 ( V_45 ) ;
}
