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
F_21 (phy_provider->children, child)
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
int V_23 = 0 ;
if ( ! V_4 )
goto V_30;
if ( V_4 -> V_31 ) {
V_23 = F_40 ( V_4 -> V_31 ) ;
if ( V_23 )
goto V_30;
}
V_23 = F_26 ( V_4 ) ;
if ( V_23 < 0 && V_23 != - V_24 )
goto V_32;
V_23 = 0 ;
F_10 ( & V_4 -> V_26 ) ;
if ( V_4 -> V_33 == 0 && V_4 -> V_28 -> V_34 ) {
V_23 = V_4 -> V_28 -> V_34 ( V_4 ) ;
if ( V_23 < 0 ) {
F_37 ( & V_4 -> V_2 , L_3 , V_23 ) ;
goto V_35;
}
}
++ V_4 -> V_33 ;
F_12 ( & V_4 -> V_26 ) ;
return 0 ;
V_35:
F_12 ( & V_4 -> V_26 ) ;
F_31 ( V_4 ) ;
V_32:
if ( V_4 -> V_31 )
F_41 ( V_4 -> V_31 ) ;
V_30:
return V_23 ;
}
int F_42 ( struct V_4 * V_4 )
{
int V_23 ;
if ( ! V_4 )
return 0 ;
F_10 ( & V_4 -> V_26 ) ;
if ( V_4 -> V_33 == 1 && V_4 -> V_28 -> V_36 ) {
V_23 = V_4 -> V_28 -> V_36 ( V_4 ) ;
if ( V_23 < 0 ) {
F_37 ( & V_4 -> V_2 , L_4 , V_23 ) ;
F_12 ( & V_4 -> V_26 ) ;
return V_23 ;
}
}
-- V_4 -> V_33 ;
F_12 ( & V_4 -> V_26 ) ;
F_29 ( V_4 ) ;
if ( V_4 -> V_31 )
F_41 ( V_4 -> V_31 ) ;
return 0 ;
}
int F_43 ( struct V_4 * V_4 , enum V_37 V_38 )
{
int V_23 ;
if ( ! V_4 || ! V_4 -> V_28 -> V_39 )
return 0 ;
F_10 ( & V_4 -> V_26 ) ;
V_23 = V_4 -> V_28 -> V_39 ( V_4 , V_38 ) ;
F_12 ( & V_4 -> V_26 ) ;
return V_23 ;
}
static struct V_4 * F_44 ( struct V_19 * V_40 , int V_41 )
{
int V_23 ;
struct V_5 * V_5 ;
struct V_4 * V_4 = NULL ;
struct V_42 args ;
V_23 = F_45 ( V_40 , L_5 , L_6 ,
V_41 , & args ) ;
if ( V_23 )
return F_19 ( - V_18 ) ;
F_10 ( & V_14 ) ;
V_5 = F_20 ( args . V_40 ) ;
if ( F_46 ( V_5 ) || ! F_47 ( V_5 -> V_43 ) ) {
V_4 = F_19 ( - V_22 ) ;
goto V_44;
}
if ( ! F_48 ( args . V_40 ) ) {
F_49 ( V_5 -> V_2 , L_7 ) ;
V_4 = F_19 ( - V_18 ) ;
goto V_45;
}
V_4 = V_5 -> V_46 ( V_5 -> V_2 , & args ) ;
V_45:
F_50 ( V_5 -> V_43 ) ;
V_44:
F_12 ( & V_14 ) ;
F_51 ( args . V_40 ) ;
return V_4 ;
}
struct V_4 * F_52 ( struct V_19 * V_40 , const char * V_7 )
{
struct V_4 * V_4 = NULL ;
int V_41 = 0 ;
if ( V_7 )
V_41 = F_53 ( V_40 , L_8 , V_7 ) ;
V_4 = F_44 ( V_40 , V_41 ) ;
if ( F_46 ( V_4 ) )
return V_4 ;
if ( ! F_47 ( V_4 -> V_28 -> V_43 ) )
return F_19 ( - V_22 ) ;
F_54 ( & V_4 -> V_2 ) ;
return V_4 ;
}
void F_2 ( struct V_4 * V_4 )
{
if ( ! V_4 || F_46 ( V_4 ) )
return;
F_50 ( V_4 -> V_28 -> V_43 ) ;
F_55 ( & V_4 -> V_2 ) ;
}
void F_56 ( struct V_1 * V_2 , struct V_4 * V_4 )
{
int V_47 ;
if ( ! V_4 )
return;
V_47 = F_57 ( V_2 , F_1 , F_7 , V_4 ) ;
F_58 ( V_2 , V_47 , L_9 ) ;
}
struct V_4 * F_59 ( struct V_1 * V_2 , struct V_42
* args )
{
struct V_4 * V_4 ;
struct V_48 V_49 ;
F_60 ( & V_49 , V_50 , NULL , NULL ) ;
while ( ( V_2 = F_61 ( & V_49 ) ) ) {
V_4 = F_62 ( V_2 ) ;
if ( args -> V_40 != V_4 -> V_2 . V_21 )
continue;
F_63 ( & V_49 ) ;
return V_4 ;
}
F_63 ( & V_49 ) ;
return F_19 ( - V_18 ) ;
}
struct V_4 * F_64 ( struct V_1 * V_2 , const char * string )
{
int V_41 = 0 ;
struct V_4 * V_4 ;
if ( string == NULL ) {
F_65 ( V_2 , L_10 ) ;
return F_19 ( - V_11 ) ;
}
if ( V_2 -> V_21 ) {
V_41 = F_53 ( V_2 -> V_21 , L_8 ,
string ) ;
V_4 = F_44 ( V_2 -> V_21 , V_41 ) ;
} else {
V_4 = F_17 ( V_2 , string ) ;
}
if ( F_46 ( V_4 ) )
return V_4 ;
if ( ! F_47 ( V_4 -> V_28 -> V_43 ) )
return F_19 ( - V_22 ) ;
F_54 ( & V_4 -> V_2 ) ;
return V_4 ;
}
struct V_4 * F_66 ( struct V_1 * V_2 , const char * string )
{
struct V_4 * V_4 = F_64 ( V_2 , string ) ;
if ( F_46 ( V_4 ) && ( F_67 ( V_4 ) == - V_18 ) )
V_4 = NULL ;
return V_4 ;
}
struct V_4 * F_68 ( struct V_1 * V_2 , const char * string )
{
struct V_4 * * V_51 , * V_4 ;
V_51 = F_69 ( F_1 , sizeof( * V_51 ) , V_12 ) ;
if ( ! V_51 )
return F_19 ( - V_13 ) ;
V_4 = F_64 ( V_2 , string ) ;
if ( ! F_46 ( V_4 ) ) {
* V_51 = V_4 ;
F_70 ( V_2 , V_51 ) ;
} else {
F_71 ( V_51 ) ;
}
return V_4 ;
}
struct V_4 * F_72 ( struct V_1 * V_2 , const char * string )
{
struct V_4 * V_4 = F_68 ( V_2 , string ) ;
if ( F_46 ( V_4 ) && ( F_67 ( V_4 ) == - V_18 ) )
V_4 = NULL ;
return V_4 ;
}
struct V_4 * F_73 ( struct V_1 * V_2 , struct V_19 * V_40 ,
const char * V_7 )
{
struct V_4 * * V_51 , * V_4 ;
V_51 = F_69 ( F_1 , sizeof( * V_51 ) , V_12 ) ;
if ( ! V_51 )
return F_19 ( - V_13 ) ;
V_4 = F_52 ( V_40 , V_7 ) ;
if ( ! F_46 ( V_4 ) ) {
* V_51 = V_4 ;
F_70 ( V_2 , V_51 ) ;
} else {
F_71 ( V_51 ) ;
}
return V_4 ;
}
struct V_4 * F_74 ( struct V_1 * V_2 , struct V_19 * V_40 ,
int V_41 )
{
struct V_4 * * V_51 , * V_4 ;
V_51 = F_69 ( F_1 , sizeof( * V_51 ) , V_12 ) ;
if ( ! V_51 )
return F_19 ( - V_13 ) ;
V_4 = F_44 ( V_40 , V_41 ) ;
if ( F_46 ( V_4 ) ) {
F_71 ( V_51 ) ;
return V_4 ;
}
if ( ! F_47 ( V_4 -> V_28 -> V_43 ) ) {
F_71 ( V_51 ) ;
return F_19 ( - V_22 ) ;
}
F_54 ( & V_4 -> V_2 ) ;
* V_51 = V_4 ;
F_70 ( V_2 , V_51 ) ;
return V_4 ;
}
struct V_4 * F_75 ( struct V_1 * V_2 , struct V_19 * V_15 ,
const struct V_52 * V_28 )
{
int V_23 ;
int V_53 ;
struct V_4 * V_4 ;
if ( F_76 ( ! V_2 ) )
return F_19 ( - V_11 ) ;
V_4 = F_9 ( sizeof( * V_4 ) , V_12 ) ;
if ( ! V_4 )
return F_19 ( - V_13 ) ;
V_53 = F_77 ( & V_54 , 0 , 0 , V_12 ) ;
if ( V_53 < 0 ) {
F_37 ( V_2 , L_11 ) ;
V_23 = V_53 ;
goto V_55;
}
F_78 ( & V_4 -> V_2 ) ;
F_79 ( & V_4 -> V_26 ) ;
V_4 -> V_2 . V_56 = V_50 ;
V_4 -> V_2 . V_57 = V_2 ;
V_4 -> V_2 . V_21 = V_15 ? : V_2 -> V_21 ;
V_4 -> V_53 = V_53 ;
V_4 -> V_28 = V_28 ;
V_23 = F_80 ( & V_4 -> V_2 , L_12 , F_18 ( V_2 ) , V_53 ) ;
if ( V_23 )
goto V_58;
V_4 -> V_31 = F_81 ( & V_4 -> V_2 , L_13 ) ;
if ( F_46 ( V_4 -> V_31 ) ) {
V_23 = F_67 ( V_4 -> V_31 ) ;
if ( V_23 == - V_22 )
goto V_58;
V_4 -> V_31 = NULL ;
}
V_23 = F_82 ( & V_4 -> V_2 ) ;
if ( V_23 )
goto V_58;
if ( F_23 ( V_2 ) ) {
F_83 ( & V_4 -> V_2 ) ;
F_84 ( & V_4 -> V_2 ) ;
}
return V_4 ;
V_58:
F_55 ( & V_4 -> V_2 ) ;
return F_19 ( V_23 ) ;
V_55:
F_16 ( V_4 ) ;
return F_19 ( V_23 ) ;
}
struct V_4 * F_85 ( struct V_1 * V_2 , struct V_19 * V_15 ,
const struct V_52 * V_28 )
{
struct V_4 * * V_51 , * V_4 ;
V_51 = F_69 ( F_5 , sizeof( * V_51 ) , V_12 ) ;
if ( ! V_51 )
return F_19 ( - V_13 ) ;
V_4 = F_75 ( V_2 , V_15 , V_28 ) ;
if ( ! F_46 ( V_4 ) ) {
* V_51 = V_4 ;
F_70 ( V_2 , V_51 ) ;
} else {
F_71 ( V_51 ) ;
}
return V_4 ;
}
void F_6 ( struct V_4 * V_4 )
{
F_86 ( & V_4 -> V_2 ) ;
F_87 ( & V_4 -> V_2 ) ;
}
void F_88 ( struct V_1 * V_2 , struct V_4 * V_4 )
{
int V_47 ;
V_47 = F_57 ( V_2 , F_5 , F_7 , V_4 ) ;
F_58 ( V_2 , V_47 , L_9 ) ;
}
void F_4 ( struct V_5 * V_5 )
{
if ( F_46 ( V_5 ) )
return;
F_10 ( & V_14 ) ;
F_15 ( & V_5 -> V_59 ) ;
F_51 ( V_5 -> V_60 ) ;
F_16 ( V_5 ) ;
F_12 ( & V_14 ) ;
}
void F_89 ( struct V_1 * V_2 ,
struct V_5 * V_5 ) {
int V_47 ;
V_47 = F_57 ( V_2 , F_3 , F_7 ,
V_5 ) ;
F_58 ( V_2 , V_47 , L_14 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_4 * V_4 ;
V_4 = F_62 ( V_2 ) ;
F_91 ( V_2 , L_15 , F_18 ( V_2 ) ) ;
F_92 ( V_4 -> V_31 ) ;
F_93 ( & V_54 , V_4 -> V_53 ) ;
F_16 ( V_4 ) ;
}
static int T_1 F_94 ( void )
{
V_50 = F_95 ( V_61 , L_13 ) ;
if ( F_46 ( V_50 ) ) {
F_96 ( L_16 ,
F_67 ( V_50 ) ) ;
return F_67 ( V_50 ) ;
}
V_50 -> V_62 = F_90 ;
return 0 ;
}
static void T_2 F_97 ( void )
{
F_98 ( V_50 ) ;
}
