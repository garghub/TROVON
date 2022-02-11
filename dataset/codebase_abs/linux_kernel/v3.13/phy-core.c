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
if ( ! F_17 ( & V_4 -> V_2 ) )
return - V_22 ;
return F_18 ( & V_4 -> V_2 ) ;
}
int F_19 ( struct V_4 * V_4 )
{
if ( ! F_17 ( & V_4 -> V_2 ) )
return - V_22 ;
return F_20 ( & V_4 -> V_2 ) ;
}
int F_21 ( struct V_4 * V_4 )
{
if ( ! F_17 ( & V_4 -> V_2 ) )
return - V_22 ;
return F_22 ( & V_4 -> V_2 ) ;
}
int F_23 ( struct V_4 * V_4 )
{
if ( ! F_17 ( & V_4 -> V_2 ) )
return - V_22 ;
return F_24 ( & V_4 -> V_2 ) ;
}
void F_25 ( struct V_4 * V_4 )
{
if ( ! F_17 ( & V_4 -> V_2 ) )
return;
F_26 ( & V_4 -> V_2 ) ;
}
void F_27 ( struct V_4 * V_4 )
{
if ( ! F_17 ( & V_4 -> V_2 ) )
return;
F_28 ( & V_4 -> V_2 ) ;
}
int F_29 ( struct V_4 * V_4 )
{
int V_23 ;
V_23 = F_19 ( V_4 ) ;
if ( V_23 < 0 && V_23 != - V_22 )
return V_23 ;
F_30 ( & V_4 -> V_24 ) ;
if ( V_4 -> V_25 ++ == 0 && V_4 -> V_26 -> V_27 ) {
V_23 = V_4 -> V_26 -> V_27 ( V_4 ) ;
if ( V_23 < 0 ) {
F_31 ( & V_4 -> V_2 , L_1 , V_23 ) ;
goto V_28;
}
}
V_28:
F_32 ( & V_4 -> V_24 ) ;
F_21 ( V_4 ) ;
return V_23 ;
}
int F_33 ( struct V_4 * V_4 )
{
int V_23 ;
V_23 = F_19 ( V_4 ) ;
if ( V_23 < 0 && V_23 != - V_22 )
return V_23 ;
F_30 ( & V_4 -> V_24 ) ;
if ( -- V_4 -> V_25 == 0 && V_4 -> V_26 -> exit ) {
V_23 = V_4 -> V_26 -> exit ( V_4 ) ;
if ( V_23 < 0 ) {
F_31 ( & V_4 -> V_2 , L_2 , V_23 ) ;
goto V_28;
}
}
V_28:
F_32 ( & V_4 -> V_24 ) ;
F_21 ( V_4 ) ;
return V_23 ;
}
int F_34 ( struct V_4 * V_4 )
{
int V_23 = - V_22 ;
V_23 = F_19 ( V_4 ) ;
if ( V_23 < 0 && V_23 != - V_22 )
return V_23 ;
F_30 ( & V_4 -> V_24 ) ;
if ( V_4 -> V_29 ++ == 0 && V_4 -> V_26 -> V_30 ) {
V_23 = V_4 -> V_26 -> V_30 ( V_4 ) ;
if ( V_23 < 0 ) {
F_31 ( & V_4 -> V_2 , L_3 , V_23 ) ;
goto V_28;
}
}
V_28:
F_32 ( & V_4 -> V_24 ) ;
return V_23 ;
}
int F_35 ( struct V_4 * V_4 )
{
int V_23 = - V_22 ;
F_30 ( & V_4 -> V_24 ) ;
if ( -- V_4 -> V_29 == 0 && V_4 -> V_26 -> V_31 ) {
V_23 = V_4 -> V_26 -> V_31 ( V_4 ) ;
if ( V_23 < 0 ) {
F_31 ( & V_4 -> V_2 , L_4 , V_23 ) ;
goto V_28;
}
}
V_28:
F_32 ( & V_4 -> V_24 ) ;
F_21 ( V_4 ) ;
return V_23 ;
}
static struct V_4 * F_36 ( struct V_1 * V_2 , int V_32 )
{
int V_23 ;
struct V_5 * V_5 ;
struct V_4 * V_4 = NULL ;
struct V_33 args ;
V_23 = F_37 ( V_2 -> V_20 , L_5 , L_6 ,
V_32 , & args ) ;
if ( V_23 ) {
F_38 ( V_2 , L_7 ,
V_2 -> V_20 -> V_34 ) ;
return F_13 ( - V_17 ) ;
}
F_30 ( & V_35 ) ;
V_5 = F_14 ( args . V_36 ) ;
if ( F_39 ( V_5 ) || ! F_40 ( V_5 -> V_37 ) ) {
V_4 = F_13 ( - V_21 ) ;
goto V_38;
}
V_4 = V_5 -> V_39 ( V_5 -> V_2 , & args ) ;
F_41 ( V_5 -> V_37 ) ;
V_38:
F_32 ( & V_35 ) ;
F_42 ( args . V_36 ) ;
return V_4 ;
}
void F_2 ( struct V_4 * V_4 )
{
if ( F_39 ( V_4 ) )
return;
F_41 ( V_4 -> V_26 -> V_37 ) ;
F_43 ( & V_4 -> V_2 ) ;
}
void F_44 ( struct V_1 * V_2 , struct V_4 * V_4 )
{
int V_40 ;
V_40 = F_45 ( V_2 , F_1 , F_7 , V_4 ) ;
F_46 ( V_2 , V_40 , L_8 ) ;
}
struct V_4 * F_47 ( struct V_1 * V_2 , struct V_33
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
struct V_4 * F_48 ( struct V_1 * V_2 , const char * string )
{
int V_32 = 0 ;
struct V_4 * V_4 = NULL ;
if ( string == NULL ) {
F_49 ( V_2 , L_9 ) ;
return F_13 ( - V_41 ) ;
}
if ( V_2 -> V_20 ) {
V_32 = F_50 ( V_2 -> V_20 , L_10 ,
string ) ;
V_4 = F_36 ( V_2 , V_32 ) ;
if ( F_39 ( V_4 ) ) {
F_31 ( V_2 , L_11 ) ;
return V_4 ;
}
} else {
V_4 = F_8 ( V_2 , string ) ;
if ( F_39 ( V_4 ) ) {
F_31 ( V_2 , L_11 ) ;
return V_4 ;
}
}
if ( ! F_40 ( V_4 -> V_26 -> V_37 ) )
return F_13 ( - V_21 ) ;
F_51 ( & V_4 -> V_2 ) ;
return V_4 ;
}
struct V_4 * F_52 ( struct V_1 * V_2 , const char * string )
{
struct V_4 * * V_42 , * V_4 ;
V_42 = F_53 ( F_1 , sizeof( * V_42 ) , V_43 ) ;
if ( ! V_42 )
return F_13 ( - V_44 ) ;
V_4 = F_48 ( V_2 , string ) ;
if ( ! F_39 ( V_4 ) ) {
* V_42 = V_4 ;
F_54 ( V_2 , V_42 ) ;
} else {
F_55 ( V_42 ) ;
}
return V_4 ;
}
struct V_4 * F_56 ( struct V_1 * V_2 , const struct V_45 * V_26 ,
struct V_46 * V_14 )
{
int V_23 ;
int V_47 ;
struct V_4 * V_4 ;
if ( F_57 ( ! V_2 ) )
return F_13 ( - V_41 ) ;
V_4 = F_58 ( sizeof( * V_4 ) , V_43 ) ;
if ( ! V_4 )
return F_13 ( - V_44 ) ;
V_47 = F_59 ( & V_48 , 0 , 0 , V_43 ) ;
if ( V_47 < 0 ) {
F_31 ( V_2 , L_12 ) ;
V_23 = V_47 ;
goto V_49;
}
F_60 ( & V_4 -> V_2 ) ;
F_61 ( & V_4 -> V_24 ) ;
V_4 -> V_2 . V_50 = V_13 ;
V_4 -> V_2 . V_51 = V_2 ;
V_4 -> V_2 . V_20 = V_2 -> V_20 ;
V_4 -> V_47 = V_47 ;
V_4 -> V_26 = V_26 ;
V_4 -> V_14 = V_14 ;
V_23 = F_62 ( & V_4 -> V_2 , L_13 , V_16 ( V_2 ) , V_47 ) ;
if ( V_23 )
goto V_52;
V_23 = F_63 ( & V_4 -> V_2 ) ;
if ( V_23 )
goto V_52;
if ( F_17 ( V_2 ) ) {
F_64 ( & V_4 -> V_2 ) ;
F_65 ( & V_4 -> V_2 ) ;
}
return V_4 ;
V_52:
F_43 ( & V_4 -> V_2 ) ;
F_66 ( & V_48 , V_4 -> V_47 ) ;
V_49:
F_67 ( V_4 ) ;
return F_13 ( V_23 ) ;
}
struct V_4 * F_68 ( struct V_1 * V_2 , const struct V_45 * V_26 ,
struct V_46 * V_14 )
{
struct V_4 * * V_42 , * V_4 ;
V_42 = F_53 ( F_5 , sizeof( * V_42 ) , V_43 ) ;
if ( ! V_42 )
return F_13 ( - V_44 ) ;
V_4 = F_56 ( V_2 , V_26 , V_14 ) ;
if ( ! F_39 ( V_4 ) ) {
* V_42 = V_4 ;
F_54 ( V_2 , V_42 ) ;
} else {
F_55 ( V_42 ) ;
}
return V_4 ;
}
void F_6 ( struct V_4 * V_4 )
{
F_69 ( & V_4 -> V_2 ) ;
F_70 ( & V_4 -> V_2 ) ;
}
void F_71 ( struct V_1 * V_2 , struct V_4 * V_4 )
{
int V_40 ;
V_40 = F_45 ( V_2 , F_5 , F_7 , V_4 ) ;
F_46 ( V_2 , V_40 , L_8 ) ;
}
void F_4 ( struct V_5 * V_5 )
{
if ( F_39 ( V_5 ) )
return;
F_30 ( & V_35 ) ;
F_72 ( & V_5 -> V_53 ) ;
F_67 ( V_5 ) ;
F_32 ( & V_35 ) ;
}
void F_73 ( struct V_1 * V_2 ,
struct V_5 * V_5 ) {
int V_40 ;
V_40 = F_45 ( V_2 , F_3 , F_7 ,
V_5 ) ;
F_46 ( V_2 , V_40 , L_14 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_4 * V_4 ;
V_4 = F_11 ( V_2 ) ;
F_75 ( V_2 , L_15 , V_16 ( V_2 ) ) ;
F_66 ( & V_48 , V_4 -> V_47 ) ;
F_67 ( V_4 ) ;
}
static int T_1 F_76 ( void )
{
V_13 = F_77 ( V_54 , L_16 ) ;
if ( F_39 ( V_13 ) ) {
F_78 ( L_17 ,
F_79 ( V_13 ) ) ;
return F_79 ( V_13 ) ;
}
V_13 -> V_55 = F_74 ;
return 0 ;
}
static void T_2 F_80 ( void )
{
F_81 ( V_13 ) ;
}
