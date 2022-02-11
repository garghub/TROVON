static int T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return - V_7 ;
V_5 -> V_3 = V_3 ;
F_3 ( & V_5 -> V_8 ) ;
F_4 ( & V_5 -> V_8 , & V_2 -> V_9 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 , * V_10 ;
F_6 (dd, aux, &ds->dependent_devices, list) {
F_7 ( & V_5 -> V_8 ) ;
F_8 ( V_5 ) ;
}
}
static int F_9 ( struct V_4 * V_5 ,
const struct V_11 * V_12 , void * V_13 ,
void (* F_10)( void * ) , void (* F_11)( void * ) )
{
int V_14 = 0 ;
F_12 ( & V_15 ) ;
if ( F_13 ( V_5 -> V_16 ) ) {
V_14 = - V_17 ;
} else {
V_5 -> V_18 = 1 ;
V_5 -> V_19 = V_12 ;
V_5 -> V_16 = V_13 ;
V_5 -> V_20 = F_11 ;
if ( F_10 )
F_10 ( V_13 ) ;
}
F_14 ( & V_15 ) ;
return V_14 ;
}
static void F_15 ( struct V_4 * V_5 )
{
F_12 ( & V_15 ) ;
if ( V_5 -> V_16 && ! -- V_5 -> V_18 ) {
void (* F_11)( void * ) = V_5 -> V_20 ;
void * V_13 = V_5 -> V_16 ;
V_5 -> V_19 = NULL ;
V_5 -> V_16 = NULL ;
V_5 -> V_20 = NULL ;
if ( F_11 )
F_11 ( V_13 ) ;
}
F_14 ( & V_15 ) ;
}
static void F_16 ( struct V_4 * V_5 , T_3 V_21 ,
enum V_22 V_23 )
{
T_4 V_24 = NULL ;
bool V_25 = false ;
F_12 ( & V_15 ) ;
if ( V_5 -> V_16 ) {
V_25 = true ;
V_5 -> V_18 ++ ;
if ( V_5 -> V_19 ) {
switch ( V_23 ) {
case V_26 :
V_24 = V_5 -> V_19 -> V_27 ;
break;
case V_28 :
V_24 = V_5 -> V_19 -> V_29 ;
break;
default:
V_24 = V_5 -> V_19 -> V_30 ;
}
}
}
F_14 ( & V_15 ) ;
if ( ! V_25 )
return;
if ( V_24 )
V_24 ( V_5 -> V_3 , V_21 , V_5 -> V_16 ) ;
F_15 ( V_5 ) ;
}
static struct V_4 *
F_17 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_4 * V_5 ;
F_18 (dd, &ds->dependent_devices, list)
if ( V_3 == V_5 -> V_3 )
return V_5 ;
return NULL ;
}
static int T_1 F_19 ( T_2 V_3 )
{
struct V_31 * V_32 ;
int V_14 = 1 ;
if ( ! F_20 ( F_21 ( V_3 , & V_32 ) ) )
return 0 ;
if ( ! ( V_32 -> V_33 & V_34 ) )
V_14 = 0 ;
else
V_14 = ! strcmp ( L_1 , V_32 -> V_35 . string ) ;
F_8 ( V_32 ) ;
return V_14 ;
}
static bool T_1 F_22 ( T_2 V_3 )
{
if ( F_23 ( V_3 , L_2 ) && F_19 ( V_3 ) )
return true ;
return F_24 ( V_3 ) ;
}
int F_25 ( T_2 V_3 )
{
struct V_1 * V_1 ;
if ( ! V_36 )
return 0 ;
if ( F_26 ( V_3 ) )
return 1 ;
F_18 (dock_station, &dock_stations, sibling)
if ( F_17 ( V_1 , V_3 ) )
return 1 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
unsigned long long V_37 ;
T_5 V_38 ;
if ( V_2 ) {
V_38 = F_28 ( V_2 -> V_3 , L_3 , NULL , & V_37 ) ;
if ( F_20 ( V_38 ) && V_37 )
return 1 ;
}
return 0 ;
}
static void F_29 ( T_2 V_3 )
{
struct V_39 * V_40 = NULL ;
int V_14 ;
F_30 ( V_3 , & V_40 ) ;
if ( ! F_31 ( V_40 ) ) {
V_14 = F_32 ( V_3 ) ;
if ( V_14 )
F_33 ( L_4 , - V_14 ) ;
}
}
static void F_34 ( T_2 V_3 )
{
struct V_39 * V_40 ;
if ( ! F_30 ( V_3 , & V_40 ) )
F_35 ( V_40 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
F_37 (dd, &ds->dependent_devices, list)
F_16 ( V_5 , V_41 , false ) ;
F_37 (dd, &ds->dependent_devices, list)
F_34 ( V_5 -> V_3 ) ;
}
static void F_38 ( struct V_1 * V_2 , T_3 V_21 )
{
struct V_4 * V_5 ;
F_18 (dd, &ds->dependent_devices, list)
F_16 ( V_5 , V_21 , V_26 ) ;
F_18 (dd, &ds->dependent_devices, list)
F_16 ( V_5 , V_21 , V_42 ) ;
F_18 (dd, &ds->dependent_devices, list)
F_29 ( V_5 -> V_3 ) ;
}
static void F_39 ( struct V_1 * V_2 , T_3 V_21 , int V_43 )
{
struct V_40 * V_44 = & V_2 -> V_45 -> V_44 ;
char V_46 [ 13 ] ;
char * V_47 [] = { V_46 , NULL } ;
struct V_4 * V_5 ;
if ( V_43 == V_48 )
sprintf ( V_46 , L_5 ) ;
else
sprintf ( V_46 , L_6 ) ;
if ( V_43 == V_49 )
F_40 ( & V_44 -> V_50 , V_51 , V_47 ) ;
F_18 (dd, &ds->dependent_devices, list)
F_16 ( V_5 , V_21 , V_28 ) ;
if ( V_43 != V_49 )
F_40 ( & V_44 -> V_50 , V_51 , V_47 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_52 )
{
T_5 V_38 ;
struct V_53 V_54 ;
union V_55 V_56 ;
unsigned long long V_57 ;
F_42 ( V_2 -> V_3 , L_7 , V_52 ? L_8 : L_9 ) ;
V_54 . V_58 = 1 ;
V_54 . V_59 = & V_56 ;
V_56 . type = V_60 ;
V_56 . integer . V_57 = V_52 ;
V_38 = F_28 ( V_2 -> V_3 , L_10 , & V_54 , & V_57 ) ;
if ( F_43 ( V_38 ) && V_38 != V_61 )
F_44 ( V_2 -> V_3 , L_11 ,
V_38 ) ;
}
static inline void V_52 ( struct V_1 * V_2 )
{
F_41 ( V_2 , 1 ) ;
}
static inline void F_45 ( struct V_1 * V_2 )
{
F_41 ( V_2 , 0 ) ;
}
static inline void F_46 ( struct V_1 * V_2 )
{
V_2 -> V_62 |= V_63 ;
}
static inline void F_47 ( struct V_1 * V_2 )
{
V_2 -> V_62 &= ~ ( V_63 ) ;
V_2 -> V_64 = V_65 ;
}
static inline void F_48 ( struct V_1 * V_2 )
{
V_2 -> V_62 |= V_66 ;
}
static inline void F_49 ( struct V_1 * V_2 )
{
V_2 -> V_62 &= ~ ( V_66 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_62 & V_63 ) ||
F_51 ( V_65 , ( V_2 -> V_64 + V_67 ) ) )
return 1 ;
return 0 ;
}
int F_52 ( T_2 V_3 ,
const struct V_11 * V_12 , void * V_13 ,
void (* F_10)( void * ) , void (* F_11)( void * ) )
{
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_14 = - V_68 ;
if ( F_13 ( ! V_13 ) )
return - V_68 ;
if ( ! V_36 )
return - V_69 ;
F_18 (dock_station, &dock_stations, sibling) {
V_5 = F_17 ( V_1 , V_3 ) ;
if ( V_5 && ! F_9 ( V_5 , V_12 , V_13 , F_10 , F_11 ) )
V_14 = 0 ;
}
return V_14 ;
}
void F_53 ( T_2 V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_1 ;
if ( ! V_36 )
return;
F_18 (dock_station, &dock_stations, sibling) {
V_5 = F_17 ( V_1 , V_3 ) ;
if ( V_5 )
F_15 ( V_5 ) ;
}
}
static int F_54 ( struct V_1 * V_2 , T_3 V_21 )
{
if ( F_50 ( V_2 ) )
return - V_70 ;
F_39 ( V_2 , V_21 , V_48 ) ;
F_36 ( V_2 ) ;
F_45 ( V_2 ) ;
F_55 ( V_2 -> V_3 , 0 ) ;
F_56 ( V_2 -> V_3 ) ;
if ( F_27 ( V_2 ) ) {
F_44 ( V_2 -> V_3 , L_12 ) ;
return - V_70 ;
}
F_49 ( V_2 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 , T_3 V_21 )
{
T_2 V_3 = V_2 -> V_3 ;
struct V_39 * V_71 = NULL ;
int V_72 = 0 ;
if ( ( V_2 -> V_62 & V_73 ) && V_21 == V_74 )
V_21 = V_41 ;
switch ( V_21 ) {
case V_75 :
case V_74 :
F_30 ( V_3 , & V_71 ) ;
if ( ! F_50 ( V_2 ) && ! F_31 ( V_71 ) ) {
F_46 ( V_2 ) ;
V_52 ( V_2 ) ;
if ( ! F_27 ( V_2 ) ) {
F_44 ( V_3 , L_13 ) ;
F_47 ( V_2 ) ;
break;
}
F_38 ( V_2 , V_21 ) ;
F_47 ( V_2 ) ;
F_39 ( V_2 , V_21 , V_49 ) ;
F_55 ( V_2 -> V_3 , 1 ) ;
F_58 () ;
break;
}
if ( F_27 ( V_2 ) || F_50 ( V_2 ) )
break;
V_72 = 1 ;
V_21 = V_41 ;
case V_41 :
F_48 ( V_2 ) ;
if ( ( V_76 && ! ( V_2 -> V_62 & V_77 ) )
|| V_72 )
F_54 ( V_2 , V_21 ) ;
else
F_39 ( V_2 , V_21 , V_48 ) ;
break;
default:
F_44 ( V_3 , L_14 , V_21 ) ;
}
}
static void F_59 ( void * V_78 , T_3 V_21 )
{
F_60 () ;
F_57 ( V_78 , V_21 ) ;
F_61 () ;
}
static void F_62 ( T_2 V_3 , T_3 V_21 , void * V_78 )
{
if ( V_21 != V_75 && V_21 != V_74
&& V_21 != V_41 )
return;
F_63 ( F_59 , V_78 , V_21 ) ;
}
static T_5 T_1 F_64 ( T_2 V_3 , T_3 V_79 ,
void * V_13 , void * * V_80 )
{
struct V_1 * V_2 = V_13 ;
T_2 V_81 = NULL ;
F_65 ( V_3 , & V_81 ) ;
if ( V_81 == V_2 -> V_3 )
F_1 ( V_2 , V_3 ) ;
return V_82 ;
}
static T_6 F_66 ( struct V_40 * V_44 ,
struct V_83 * V_84 , char * V_85 )
{
struct V_1 * V_1 = V_44 -> V_86 ;
struct V_39 * V_71 = NULL ;
F_30 ( V_1 -> V_3 , & V_71 ) ;
return snprintf ( V_85 , V_87 , L_15 , F_31 ( V_71 ) ) ;
}
static T_6 F_67 ( struct V_40 * V_44 ,
struct V_83 * V_84 , char * V_85 )
{
struct V_1 * V_1 = V_44 -> V_86 ;
return snprintf ( V_85 , V_87 , L_16 , V_1 -> V_62 ) ;
}
static T_6 F_68 ( struct V_40 * V_44 , struct V_83 * V_84 ,
const char * V_85 , T_7 V_58 )
{
int V_14 ;
struct V_1 * V_1 = V_44 -> V_86 ;
if ( ! V_58 )
return - V_68 ;
F_60 () ;
F_48 ( V_1 ) ;
V_14 = F_54 ( V_1 , V_41 ) ;
F_61 () ;
return V_14 ? V_14 : V_58 ;
}
static T_6 F_69 ( struct V_40 * V_44 ,
struct V_83 * V_84 , char * V_85 )
{
unsigned long long V_88 ;
struct V_1 * V_1 = V_44 -> V_86 ;
T_5 V_38 = F_28 ( V_1 -> V_3 ,
L_17 , NULL , & V_88 ) ;
if ( F_43 ( V_38 ) )
return 0 ;
return snprintf ( V_85 , V_87 , L_18 , V_88 ) ;
}
static T_6 F_70 ( struct V_40 * V_44 ,
struct V_83 * V_84 , char * V_85 )
{
struct V_1 * V_1 = V_44 -> V_86 ;
char * type ;
if ( V_1 -> V_62 & V_73 )
type = L_19 ;
else if ( V_1 -> V_62 & V_77 )
type = L_20 ;
else if ( V_1 -> V_62 & V_89 )
type = L_21 ;
else
type = L_22 ;
return snprintf ( V_85 , V_87 , L_7 , type ) ;
}
static int T_1 F_71 ( T_2 V_3 )
{
struct V_1 * V_1 , V_2 = { NULL , } ;
struct V_90 * V_5 ;
T_5 V_38 ;
int V_14 ;
V_5 = F_72 ( NULL , L_23 , V_36 ,
& V_2 , sizeof( V_2 ) ) ;
if ( F_73 ( V_5 ) )
return F_74 ( V_5 ) ;
V_1 = V_5 -> V_44 . V_86 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_45 = V_5 ;
V_1 -> V_64 = V_65 - V_67 ;
F_3 ( & V_1 -> V_91 ) ;
F_3 ( & V_1 -> V_9 ) ;
F_75 ( & V_5 -> V_44 , 0 ) ;
if ( F_26 ( V_3 ) )
V_1 -> V_62 |= V_73 ;
if ( F_76 ( V_3 ) )
V_1 -> V_62 |= V_77 ;
if ( F_19 ( V_3 ) )
V_1 -> V_62 |= V_89 ;
V_14 = F_77 ( & V_5 -> V_44 . V_50 , & V_92 ) ;
if ( V_14 )
goto V_93;
F_78 ( V_94 , V_95 ,
V_96 , F_64 , NULL ,
V_1 , NULL ) ;
V_14 = F_1 ( V_1 , V_3 ) ;
if ( V_14 )
goto V_97;
V_38 = F_79 ( V_3 , V_98 ,
F_62 , V_1 ) ;
if ( F_43 ( V_38 ) ) {
V_14 = - V_69 ;
goto V_97;
}
V_36 ++ ;
F_80 ( & V_1 -> V_91 , & V_99 ) ;
return 0 ;
V_97:
F_5 ( V_1 ) ;
F_81 ( & V_5 -> V_44 . V_50 , & V_92 ) ;
V_93:
F_82 ( V_5 ) ;
F_44 ( V_3 , L_24 , V_100 , V_14 ) ;
return V_14 ;
}
static T_5 T_1
F_83 ( T_2 V_3 , T_3 V_79 , void * V_13 , void * * V_80 )
{
if ( F_26 ( V_3 ) || F_22 ( V_3 ) )
F_71 ( V_3 ) ;
return V_82 ;
}
void T_1 F_84 ( void )
{
F_78 ( V_94 , V_95 ,
V_96 , F_83 , NULL , NULL , NULL ) ;
if ( ! V_36 ) {
F_85 ( V_101 L_25 ) ;
return;
}
F_85 ( V_101 L_26 ,
V_102 , V_36 ) ;
}
