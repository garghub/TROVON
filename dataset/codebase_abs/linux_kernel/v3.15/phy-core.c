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
F_15 (phy_provider, &phy_provider_list, list) {
if ( V_5 -> V_2 -> V_20 == V_19 )
return V_5 ;
}
return F_13 ( - V_21 ) ;
}
int F_16 ( struct V_4 * V_4 )
{
int V_22 ;
if ( ! F_17 ( & V_4 -> V_2 ) )
return - V_23 ;
V_22 = F_18 ( & V_4 -> V_2 ) ;
if ( V_22 < 0 && V_22 != - V_24 )
F_19 ( & V_4 -> V_2 ) ;
return V_22 ;
}
int F_20 ( struct V_4 * V_4 )
{
int V_22 ;
if ( ! F_17 ( & V_4 -> V_2 ) )
return - V_23 ;
V_22 = F_21 ( & V_4 -> V_2 ) ;
if ( V_22 < 0 )
F_22 ( & V_4 -> V_2 ) ;
return V_22 ;
}
int F_23 ( struct V_4 * V_4 )
{
if ( ! F_17 ( & V_4 -> V_2 ) )
return - V_23 ;
return F_24 ( & V_4 -> V_2 ) ;
}
int F_25 ( struct V_4 * V_4 )
{
if ( ! F_17 ( & V_4 -> V_2 ) )
return - V_23 ;
return F_22 ( & V_4 -> V_2 ) ;
}
void F_26 ( struct V_4 * V_4 )
{
if ( ! F_17 ( & V_4 -> V_2 ) )
return;
F_27 ( & V_4 -> V_2 ) ;
}
void F_28 ( struct V_4 * V_4 )
{
if ( ! F_17 ( & V_4 -> V_2 ) )
return;
F_29 ( & V_4 -> V_2 ) ;
}
int F_30 ( struct V_4 * V_4 )
{
int V_22 ;
if ( ! V_4 )
return 0 ;
V_22 = F_20 ( V_4 ) ;
if ( V_22 < 0 && V_22 != - V_23 )
return V_22 ;
F_31 ( & V_4 -> V_25 ) ;
if ( V_4 -> V_26 == 0 && V_4 -> V_27 -> V_28 ) {
V_22 = V_4 -> V_27 -> V_28 ( V_4 ) ;
if ( V_22 < 0 ) {
F_32 ( & V_4 -> V_2 , L_1 , V_22 ) ;
goto V_29;
}
} else {
V_22 = 0 ;
}
++ V_4 -> V_26 ;
V_29:
F_33 ( & V_4 -> V_25 ) ;
F_23 ( V_4 ) ;
return V_22 ;
}
int F_34 ( struct V_4 * V_4 )
{
int V_22 ;
if ( ! V_4 )
return 0 ;
V_22 = F_20 ( V_4 ) ;
if ( V_22 < 0 && V_22 != - V_23 )
return V_22 ;
F_31 ( & V_4 -> V_25 ) ;
if ( V_4 -> V_26 == 1 && V_4 -> V_27 -> exit ) {
V_22 = V_4 -> V_27 -> exit ( V_4 ) ;
if ( V_22 < 0 ) {
F_32 ( & V_4 -> V_2 , L_2 , V_22 ) ;
goto V_29;
}
}
-- V_4 -> V_26 ;
V_29:
F_33 ( & V_4 -> V_25 ) ;
F_23 ( V_4 ) ;
return V_22 ;
}
int F_35 ( struct V_4 * V_4 )
{
int V_22 ;
if ( ! V_4 )
return 0 ;
V_22 = F_20 ( V_4 ) ;
if ( V_22 < 0 && V_22 != - V_23 )
return V_22 ;
F_31 ( & V_4 -> V_25 ) ;
if ( V_4 -> V_30 == 0 && V_4 -> V_27 -> V_31 ) {
V_22 = V_4 -> V_27 -> V_31 ( V_4 ) ;
if ( V_22 < 0 ) {
F_32 ( & V_4 -> V_2 , L_3 , V_22 ) ;
goto V_29;
}
} else {
V_22 = 0 ;
}
++ V_4 -> V_30 ;
F_33 ( & V_4 -> V_25 ) ;
return 0 ;
V_29:
F_33 ( & V_4 -> V_25 ) ;
F_25 ( V_4 ) ;
return V_22 ;
}
int F_36 ( struct V_4 * V_4 )
{
int V_22 ;
if ( ! V_4 )
return 0 ;
F_31 ( & V_4 -> V_25 ) ;
if ( V_4 -> V_30 == 1 && V_4 -> V_27 -> V_32 ) {
V_22 = V_4 -> V_27 -> V_32 ( V_4 ) ;
if ( V_22 < 0 ) {
F_32 ( & V_4 -> V_2 , L_4 , V_22 ) ;
F_33 ( & V_4 -> V_25 ) ;
return V_22 ;
}
}
-- V_4 -> V_30 ;
F_33 ( & V_4 -> V_25 ) ;
F_23 ( V_4 ) ;
return 0 ;
}
static struct V_4 * F_37 ( struct V_18 * V_33 , int V_34 )
{
int V_22 ;
struct V_5 * V_5 ;
struct V_4 * V_4 = NULL ;
struct V_35 args ;
V_22 = F_38 ( V_33 , L_5 , L_6 ,
V_34 , & args ) ;
if ( V_22 )
return F_13 ( - V_17 ) ;
F_31 ( & V_36 ) ;
V_5 = F_14 ( args . V_33 ) ;
if ( F_39 ( V_5 ) || ! F_40 ( V_5 -> V_37 ) ) {
V_4 = F_13 ( - V_21 ) ;
goto V_38;
}
V_4 = V_5 -> V_39 ( V_5 -> V_2 , & args ) ;
F_41 ( V_5 -> V_37 ) ;
V_38:
F_33 ( & V_36 ) ;
F_42 ( args . V_33 ) ;
return V_4 ;
}
struct V_4 * F_43 ( struct V_18 * V_33 , const char * V_40 )
{
struct V_4 * V_4 = NULL ;
int V_34 = 0 ;
if ( V_40 )
V_34 = F_44 ( V_33 , L_7 , V_40 ) ;
V_4 = F_37 ( V_33 , V_34 ) ;
if ( F_39 ( V_4 ) )
return V_4 ;
if ( ! F_40 ( V_4 -> V_27 -> V_37 ) )
return F_13 ( - V_21 ) ;
F_45 ( & V_4 -> V_2 ) ;
return V_4 ;
}
void F_2 ( struct V_4 * V_4 )
{
if ( ! V_4 || F_39 ( V_4 ) )
return;
F_41 ( V_4 -> V_27 -> V_37 ) ;
F_46 ( & V_4 -> V_2 ) ;
}
void F_47 ( struct V_1 * V_2 , struct V_4 * V_4 )
{
int V_41 ;
if ( ! V_4 )
return;
V_41 = F_48 ( V_2 , F_1 , F_7 , V_4 ) ;
F_49 ( V_2 , V_41 , L_8 ) ;
}
struct V_4 * F_50 ( struct V_1 * V_2 , struct V_35
* args )
{
struct V_4 * V_4 ;
struct V_11 V_12 ;
struct V_18 * V_19 = V_2 -> V_20 ;
F_9 ( & V_12 , V_13 , NULL , NULL ) ;
while ( ( V_2 = F_10 ( & V_12 ) ) ) {
V_4 = F_11 ( V_2 ) ;
if ( V_19 != V_4 -> V_2 . V_20 )
continue;
F_12 ( & V_12 ) ;
return V_4 ;
}
F_12 ( & V_12 ) ;
return F_13 ( - V_17 ) ;
}
struct V_4 * F_51 ( struct V_1 * V_2 , const char * string )
{
int V_34 = 0 ;
struct V_4 * V_4 ;
if ( string == NULL ) {
F_52 ( V_2 , L_9 ) ;
return F_13 ( - V_42 ) ;
}
if ( V_2 -> V_20 ) {
V_34 = F_44 ( V_2 -> V_20 , L_7 ,
string ) ;
V_4 = F_37 ( V_2 -> V_20 , V_34 ) ;
} else {
V_4 = F_8 ( V_2 , string ) ;
}
if ( F_39 ( V_4 ) )
return V_4 ;
if ( ! F_40 ( V_4 -> V_27 -> V_37 ) )
return F_13 ( - V_21 ) ;
F_45 ( & V_4 -> V_2 ) ;
return V_4 ;
}
struct V_4 * F_53 ( struct V_1 * V_2 , const char * string )
{
struct V_4 * V_4 = F_51 ( V_2 , string ) ;
if ( F_54 ( V_4 ) == - V_17 )
V_4 = NULL ;
return V_4 ;
}
struct V_4 * F_55 ( struct V_1 * V_2 , const char * string )
{
struct V_4 * * V_43 , * V_4 ;
V_43 = F_56 ( F_1 , sizeof( * V_43 ) , V_44 ) ;
if ( ! V_43 )
return F_13 ( - V_45 ) ;
V_4 = F_51 ( V_2 , string ) ;
if ( ! F_39 ( V_4 ) ) {
* V_43 = V_4 ;
F_57 ( V_2 , V_43 ) ;
} else {
F_58 ( V_43 ) ;
}
return V_4 ;
}
struct V_4 * F_59 ( struct V_1 * V_2 , const char * string )
{
struct V_4 * V_4 = F_55 ( V_2 , string ) ;
if ( F_54 ( V_4 ) == - V_17 )
V_4 = NULL ;
return V_4 ;
}
struct V_4 * F_60 ( struct V_1 * V_2 , struct V_18 * V_33 ,
const char * V_40 )
{
struct V_4 * * V_43 , * V_4 ;
V_43 = F_56 ( F_1 , sizeof( * V_43 ) , V_44 ) ;
if ( ! V_43 )
return F_13 ( - V_45 ) ;
V_4 = F_43 ( V_33 , V_40 ) ;
if ( ! F_39 ( V_4 ) ) {
* V_43 = V_4 ;
F_57 ( V_2 , V_43 ) ;
} else {
F_58 ( V_43 ) ;
}
return V_4 ;
}
struct V_4 * F_61 ( struct V_1 * V_2 , const struct V_46 * V_27 ,
struct V_47 * V_14 )
{
int V_22 ;
int V_48 ;
struct V_4 * V_4 ;
if ( F_62 ( ! V_2 ) )
return F_13 ( - V_42 ) ;
V_4 = F_63 ( sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 )
return F_13 ( - V_45 ) ;
V_48 = F_64 ( & V_49 , 0 , 0 , V_44 ) ;
if ( V_48 < 0 ) {
F_32 ( V_2 , L_10 ) ;
V_22 = V_48 ;
goto V_50;
}
F_65 ( & V_4 -> V_2 ) ;
F_66 ( & V_4 -> V_25 ) ;
V_4 -> V_2 . V_51 = V_13 ;
V_4 -> V_2 . V_52 = V_2 ;
V_4 -> V_2 . V_20 = V_2 -> V_20 ;
V_4 -> V_48 = V_48 ;
V_4 -> V_27 = V_27 ;
V_4 -> V_14 = V_14 ;
V_22 = F_67 ( & V_4 -> V_2 , L_11 , V_16 ( V_2 ) , V_48 ) ;
if ( V_22 )
goto V_53;
V_22 = F_68 ( & V_4 -> V_2 ) ;
if ( V_22 )
goto V_53;
if ( F_17 ( V_2 ) ) {
F_69 ( & V_4 -> V_2 ) ;
F_70 ( & V_4 -> V_2 ) ;
}
return V_4 ;
V_53:
F_46 ( & V_4 -> V_2 ) ;
F_71 ( & V_49 , V_4 -> V_48 ) ;
V_50:
F_72 ( V_4 ) ;
return F_13 ( V_22 ) ;
}
struct V_4 * F_73 ( struct V_1 * V_2 , const struct V_46 * V_27 ,
struct V_47 * V_14 )
{
struct V_4 * * V_43 , * V_4 ;
V_43 = F_56 ( F_5 , sizeof( * V_43 ) , V_44 ) ;
if ( ! V_43 )
return F_13 ( - V_45 ) ;
V_4 = F_61 ( V_2 , V_27 , V_14 ) ;
if ( ! F_39 ( V_4 ) ) {
* V_43 = V_4 ;
F_57 ( V_2 , V_43 ) ;
} else {
F_58 ( V_43 ) ;
}
return V_4 ;
}
void F_6 ( struct V_4 * V_4 )
{
F_74 ( & V_4 -> V_2 ) ;
F_75 ( & V_4 -> V_2 ) ;
}
void F_76 ( struct V_1 * V_2 , struct V_4 * V_4 )
{
int V_41 ;
V_41 = F_48 ( V_2 , F_5 , F_7 , V_4 ) ;
F_49 ( V_2 , V_41 , L_8 ) ;
}
void F_4 ( struct V_5 * V_5 )
{
if ( F_39 ( V_5 ) )
return;
F_31 ( & V_36 ) ;
F_77 ( & V_5 -> V_54 ) ;
F_72 ( V_5 ) ;
F_33 ( & V_36 ) ;
}
void F_78 ( struct V_1 * V_2 ,
struct V_5 * V_5 ) {
int V_41 ;
V_41 = F_48 ( V_2 , F_3 , F_7 ,
V_5 ) ;
F_49 ( V_2 , V_41 , L_12 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_4 * V_4 ;
V_4 = F_11 ( V_2 ) ;
F_80 ( V_2 , L_13 , V_16 ( V_2 ) ) ;
F_71 ( & V_49 , V_4 -> V_48 ) ;
F_72 ( V_4 ) ;
}
static int T_1 F_81 ( void )
{
V_13 = F_82 ( V_55 , L_14 ) ;
if ( F_39 ( V_13 ) ) {
F_83 ( L_15 ,
F_54 ( V_13 ) ) ;
return F_54 ( V_13 ) ;
}
V_13 -> V_56 = F_79 ;
return 0 ;
}
static void T_2 F_84 ( void )
{
F_85 ( V_13 ) ;
}
