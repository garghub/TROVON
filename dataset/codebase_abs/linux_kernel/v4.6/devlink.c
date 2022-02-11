static struct V_1 * F_1 ( const struct V_2 * V_2 )
{
return F_2 ( & V_2 -> V_3 ) ;
}
static void F_3 ( struct V_2 * V_2 , struct V_1 * V_1 )
{
F_4 ( & V_2 -> V_3 , V_1 ) ;
}
static struct V_2 * F_5 ( struct V_1 * V_1 ,
struct V_4 * * V_5 )
{
struct V_2 * V_2 ;
char * V_6 ;
char * V_7 ;
if ( ! V_5 [ V_8 ] || ! V_5 [ V_9 ] )
return F_6 ( - V_10 ) ;
V_6 = F_7 ( V_5 [ V_8 ] ) ;
V_7 = F_7 ( V_5 [ V_9 ] ) ;
F_8 (devlink, &devlink_list, list) {
if ( strcmp ( V_2 -> V_11 -> V_12 -> V_13 , V_6 ) == 0 &&
strcmp ( F_9 ( V_2 -> V_11 ) , V_7 ) == 0 &&
F_10 ( F_1 ( V_2 ) , V_1 ) )
return V_2 ;
}
return F_6 ( - V_14 ) ;
}
static struct V_2 * F_11 ( struct V_15 * V_16 )
{
return F_5 ( F_12 ( V_16 ) , V_16 -> V_5 ) ;
}
static struct V_17 * F_13 ( struct V_2 * V_2 ,
int V_18 )
{
struct V_17 * V_17 ;
F_8 (devlink_port, &devlink->port_list, list) {
if ( V_17 -> V_19 == V_18 )
return V_17 ;
}
return NULL ;
}
static bool F_14 ( struct V_2 * V_2 , int V_18 )
{
return F_13 ( V_2 , V_18 ) ;
}
static struct V_17 * F_15 ( struct V_2 * V_2 ,
struct V_4 * * V_5 )
{
if ( V_5 [ V_20 ] ) {
T_1 V_18 = F_16 ( V_5 [ V_20 ] ) ;
struct V_17 * V_17 ;
V_17 = F_13 ( V_2 , V_18 ) ;
if ( ! V_17 )
return F_6 ( - V_14 ) ;
return V_17 ;
}
return F_6 ( - V_10 ) ;
}
static struct V_17 * F_17 ( struct V_2 * V_2 ,
struct V_15 * V_16 )
{
return F_15 ( V_2 , V_16 -> V_5 ) ;
}
static int F_18 ( const struct V_21 * V_22 ,
struct V_23 * V_24 , struct V_15 * V_16 )
{
struct V_2 * V_2 ;
F_19 ( & V_25 ) ;
V_2 = F_11 ( V_16 ) ;
if ( F_20 ( V_2 ) ) {
F_21 ( & V_25 ) ;
return F_22 ( V_2 ) ;
}
V_16 -> V_26 [ 0 ] = V_2 ;
if ( V_22 -> V_27 & V_28 ) {
struct V_17 * V_17 ;
F_19 ( & V_29 ) ;
V_17 = F_17 ( V_2 , V_16 ) ;
if ( F_20 ( V_17 ) ) {
F_21 ( & V_29 ) ;
F_21 ( & V_25 ) ;
return F_22 ( V_17 ) ;
}
V_16 -> V_26 [ 1 ] = V_17 ;
}
return 0 ;
}
static void F_23 ( const struct V_21 * V_22 ,
struct V_23 * V_24 , struct V_15 * V_16 )
{
if ( V_22 -> V_27 & V_28 )
F_21 ( & V_29 ) ;
F_21 ( & V_25 ) ;
}
static int F_24 ( struct V_23 * V_30 , struct V_2 * V_2 )
{
if ( F_25 ( V_30 , V_8 , V_2 -> V_11 -> V_12 -> V_13 ) )
return - V_31 ;
if ( F_25 ( V_30 , V_9 , F_9 ( V_2 -> V_11 ) ) )
return - V_31 ;
return 0 ;
}
static int F_26 ( struct V_23 * V_30 , struct V_2 * V_2 ,
enum V_32 V_33 , T_1 V_34 ,
T_1 V_35 , int V_36 )
{
void * V_37 ;
V_37 = F_27 ( V_30 , V_34 , V_35 , & V_38 , V_36 , V_33 ) ;
if ( ! V_37 )
return - V_31 ;
if ( F_24 ( V_30 , V_2 ) )
goto V_39;
F_28 ( V_30 , V_37 ) ;
return 0 ;
V_39:
F_29 ( V_30 , V_37 ) ;
return - V_31 ;
}
static void F_30 ( struct V_2 * V_2 , enum V_32 V_33 )
{
struct V_23 * V_30 ;
int V_40 ;
F_31 ( V_33 != V_41 && V_33 != V_42 ) ;
V_30 = F_32 ( V_43 , V_44 ) ;
if ( ! V_30 )
return;
V_40 = F_26 ( V_30 , V_2 , V_33 , 0 , 0 , 0 ) ;
if ( V_40 ) {
F_33 ( V_30 ) ;
return;
}
F_34 ( & V_38 , F_1 ( V_2 ) ,
V_30 , 0 , V_45 , V_44 ) ;
}
static int F_35 ( struct V_23 * V_30 , struct V_2 * V_2 ,
struct V_17 * V_17 ,
enum V_32 V_33 , T_1 V_34 ,
T_1 V_35 , int V_36 )
{
void * V_37 ;
V_37 = F_27 ( V_30 , V_34 , V_35 , & V_38 , V_36 , V_33 ) ;
if ( ! V_37 )
return - V_31 ;
if ( F_24 ( V_30 , V_2 ) )
goto V_39;
if ( F_36 ( V_30 , V_20 , V_17 -> V_19 ) )
goto V_39;
if ( F_37 ( V_30 , V_46 , V_17 -> type ) )
goto V_39;
if ( V_17 -> V_47 != V_48 &&
F_37 ( V_30 , V_49 ,
V_17 -> V_47 ) )
goto V_39;
if ( V_17 -> type == V_50 ) {
struct V_51 * V_52 = V_17 -> V_53 ;
if ( V_52 &&
( F_36 ( V_30 , V_54 ,
V_52 -> V_55 ) ||
F_25 ( V_30 , V_56 ,
V_52 -> V_13 ) ) )
goto V_39;
}
if ( V_17 -> type == V_57 ) {
struct V_58 * V_59 = V_17 -> V_53 ;
if ( V_59 &&
F_25 ( V_30 , V_60 ,
V_59 -> V_13 ) )
goto V_39;
}
if ( V_17 -> V_61 &&
F_36 ( V_30 , V_62 ,
V_17 -> V_63 ) )
goto V_39;
F_28 ( V_30 , V_37 ) ;
return 0 ;
V_39:
F_29 ( V_30 , V_37 ) ;
return - V_31 ;
}
static void F_38 ( struct V_17 * V_17 ,
enum V_32 V_33 )
{
struct V_2 * V_2 = V_17 -> V_2 ;
struct V_23 * V_30 ;
int V_40 ;
if ( ! V_17 -> V_64 )
return;
F_31 ( V_33 != V_65 && V_33 != V_66 ) ;
V_30 = F_32 ( V_43 , V_44 ) ;
if ( ! V_30 )
return;
V_40 = F_35 ( V_30 , V_2 , V_17 , V_33 , 0 , 0 , 0 ) ;
if ( V_40 ) {
F_33 ( V_30 ) ;
return;
}
F_34 ( & V_38 , F_1 ( V_2 ) ,
V_30 , 0 , V_45 , V_44 ) ;
}
static int F_39 ( struct V_23 * V_24 , struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_26 [ 0 ] ;
struct V_23 * V_30 ;
int V_40 ;
V_30 = F_32 ( V_43 , V_44 ) ;
if ( ! V_30 )
return - V_67 ;
V_40 = F_26 ( V_30 , V_2 , V_41 ,
V_16 -> V_68 , V_16 -> V_69 , 0 ) ;
if ( V_40 ) {
F_33 ( V_30 ) ;
return V_40 ;
}
return F_40 ( V_30 , V_16 ) ;
}
static int F_41 ( struct V_23 * V_30 ,
struct V_70 * V_71 )
{
struct V_2 * V_2 ;
int V_72 = V_71 -> args [ 0 ] ;
int V_73 = 0 ;
int V_40 ;
F_19 ( & V_25 ) ;
F_8 (devlink, &devlink_list, list) {
if ( ! F_10 ( F_1 ( V_2 ) , F_42 ( V_30 -> V_74 ) ) )
continue;
if ( V_73 < V_72 ) {
V_73 ++ ;
continue;
}
V_40 = F_26 ( V_30 , V_2 , V_41 ,
F_43 ( V_71 -> V_24 ) . V_34 ,
V_71 -> V_75 -> V_76 , V_77 ) ;
if ( V_40 )
goto V_78;
V_73 ++ ;
}
V_78:
F_21 ( & V_25 ) ;
V_71 -> args [ 0 ] = V_73 ;
return V_30 -> V_79 ;
}
static int F_44 ( struct V_23 * V_24 ,
struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_26 [ 0 ] ;
struct V_17 * V_17 = V_16 -> V_26 [ 1 ] ;
struct V_23 * V_30 ;
int V_40 ;
V_30 = F_32 ( V_43 , V_44 ) ;
if ( ! V_30 )
return - V_67 ;
V_40 = F_35 ( V_30 , V_2 , V_17 ,
V_65 ,
V_16 -> V_68 , V_16 -> V_69 , 0 ) ;
if ( V_40 ) {
F_33 ( V_30 ) ;
return V_40 ;
}
return F_40 ( V_30 , V_16 ) ;
}
static int F_45 ( struct V_23 * V_30 ,
struct V_70 * V_71 )
{
struct V_2 * V_2 ;
struct V_17 * V_17 ;
int V_72 = V_71 -> args [ 0 ] ;
int V_73 = 0 ;
int V_40 ;
F_19 ( & V_25 ) ;
F_19 ( & V_29 ) ;
F_8 (devlink, &devlink_list, list) {
if ( ! F_10 ( F_1 ( V_2 ) , F_42 ( V_30 -> V_74 ) ) )
continue;
F_8 (devlink_port, &devlink->port_list, list) {
if ( V_73 < V_72 ) {
V_73 ++ ;
continue;
}
V_40 = F_35 ( V_30 , V_2 , V_17 ,
V_41 ,
F_43 ( V_71 -> V_24 ) . V_34 ,
V_71 -> V_75 -> V_76 ,
V_77 ) ;
if ( V_40 )
goto V_78;
V_73 ++ ;
}
}
V_78:
F_21 ( & V_29 ) ;
F_21 ( & V_25 ) ;
V_71 -> args [ 0 ] = V_73 ;
return V_30 -> V_79 ;
}
static int F_46 ( struct V_2 * V_2 ,
struct V_17 * V_17 ,
enum V_80 V_81 )
{
int V_40 ;
if ( V_2 -> V_22 && V_2 -> V_22 -> V_82 ) {
if ( V_81 == V_48 )
return - V_10 ;
V_40 = V_2 -> V_22 -> V_82 ( V_17 , V_81 ) ;
if ( V_40 )
return V_40 ;
V_17 -> V_47 = V_81 ;
F_38 ( V_17 , V_65 ) ;
return 0 ;
}
return - V_83 ;
}
static int F_47 ( struct V_23 * V_24 ,
struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_26 [ 0 ] ;
struct V_17 * V_17 = V_16 -> V_26 [ 1 ] ;
int V_40 ;
if ( V_16 -> V_5 [ V_46 ] ) {
enum V_80 V_81 ;
V_81 = F_48 ( V_16 -> V_5 [ V_46 ] ) ;
V_40 = F_46 ( V_2 , V_17 , V_81 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static int F_49 ( struct V_2 * V_2 ,
T_1 V_18 , T_1 V_84 )
{
if ( V_2 -> V_22 && V_2 -> V_22 -> V_85 )
return V_2 -> V_22 -> V_85 ( V_2 , V_18 , V_84 ) ;
return - V_83 ;
}
static int F_50 ( struct V_23 * V_24 ,
struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_26 [ 0 ] ;
T_1 V_18 ;
T_1 V_84 ;
if ( ! V_16 -> V_5 [ V_20 ] ||
! V_16 -> V_5 [ V_86 ] )
return - V_10 ;
V_18 = F_16 ( V_16 -> V_5 [ V_20 ] ) ;
V_84 = F_16 ( V_16 -> V_5 [ V_86 ] ) ;
return F_49 ( V_2 , V_18 , V_84 ) ;
}
static int F_51 ( struct V_2 * V_2 , T_1 V_18 )
{
if ( V_2 -> V_22 && V_2 -> V_22 -> V_87 )
return V_2 -> V_22 -> V_87 ( V_2 , V_18 ) ;
return - V_83 ;
}
static int F_52 ( struct V_23 * V_24 ,
struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_26 [ 0 ] ;
T_1 V_18 ;
if ( ! V_16 -> V_5 [ V_20 ] )
return - V_10 ;
V_18 = F_16 ( V_16 -> V_5 [ V_20 ] ) ;
return F_51 ( V_2 , V_18 ) ;
}
struct V_2 * F_53 ( const struct V_88 * V_22 , T_2 V_89 )
{
struct V_2 * V_2 ;
V_2 = F_54 ( sizeof( * V_2 ) + V_89 , V_44 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_22 = V_22 ;
F_3 ( V_2 , & V_90 ) ;
F_55 ( & V_2 -> V_91 ) ;
return V_2 ;
}
int F_56 ( struct V_2 * V_2 , struct V_92 * V_11 )
{
F_19 ( & V_25 ) ;
V_2 -> V_11 = V_11 ;
F_57 ( & V_2 -> V_93 , & V_94 ) ;
F_30 ( V_2 , V_41 ) ;
F_21 ( & V_25 ) ;
return 0 ;
}
void F_58 ( struct V_2 * V_2 )
{
F_19 ( & V_25 ) ;
F_30 ( V_2 , V_42 ) ;
F_59 ( & V_2 -> V_93 ) ;
F_21 ( & V_25 ) ;
}
void F_60 ( struct V_2 * V_2 )
{
F_61 ( V_2 ) ;
}
int F_62 ( struct V_2 * V_2 ,
struct V_17 * V_17 ,
unsigned int V_18 )
{
F_19 ( & V_29 ) ;
if ( F_14 ( V_2 , V_18 ) ) {
F_21 ( & V_29 ) ;
return - V_95 ;
}
V_17 -> V_2 = V_2 ;
V_17 -> V_19 = V_18 ;
V_17 -> type = V_48 ;
V_17 -> V_64 = true ;
F_57 ( & V_17 -> V_93 , & V_2 -> V_91 ) ;
F_21 ( & V_29 ) ;
F_38 ( V_17 , V_65 ) ;
return 0 ;
}
void F_63 ( struct V_17 * V_17 )
{
F_38 ( V_17 , V_66 ) ;
F_19 ( & V_29 ) ;
F_59 ( & V_17 -> V_93 ) ;
F_21 ( & V_29 ) ;
}
static void F_64 ( struct V_17 * V_17 ,
enum V_80 type ,
void * V_53 )
{
V_17 -> type = type ;
V_17 -> V_53 = V_53 ;
F_38 ( V_17 , V_65 ) ;
}
void F_65 ( struct V_17 * V_17 ,
struct V_51 * V_52 )
{
return F_64 ( V_17 ,
V_50 , V_52 ) ;
}
void F_66 ( struct V_17 * V_17 ,
struct V_58 * V_59 )
{
return F_64 ( V_17 ,
V_57 , V_59 ) ;
}
void F_67 ( struct V_17 * V_17 )
{
return F_64 ( V_17 ,
V_48 , NULL ) ;
}
void F_68 ( struct V_17 * V_17 ,
T_1 V_63 )
{
V_17 -> V_61 = true ;
V_17 -> V_63 = V_63 ;
F_38 ( V_17 , V_65 ) ;
}
static int T_3 F_69 ( void )
{
return F_70 ( & V_38 ,
V_96 ,
V_97 ) ;
}
static void T_4 F_71 ( void )
{
F_72 ( & V_38 ) ;
}
