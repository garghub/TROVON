static int
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return - V_7 ;
V_5 -> V_3 = V_3 ;
F_3 ( & V_5 -> V_8 ) ;
F_4 ( & V_2 -> V_9 ) ;
F_5 ( & V_5 -> V_8 , & V_2 -> V_10 ) ;
F_6 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 ,
const struct V_11 * V_12 , void * V_13 ,
void (* F_8)( void * ) , void (* F_9)( void * ) )
{
int V_14 = 0 ;
F_10 ( & V_15 ) ;
if ( V_5 -> V_16 ) {
V_14 = - V_17 ;
} else {
V_5 -> V_18 = 1 ;
V_5 -> V_19 = V_12 ;
V_5 -> V_16 = V_13 ;
V_5 -> V_20 = F_9 ;
}
if ( ! F_11 ( V_14 ) && F_8 )
F_8 ( V_13 ) ;
F_12 ( & V_15 ) ;
return V_14 ;
}
static void F_13 ( struct V_4 * V_5 )
{
void (* F_9)( void * ) = NULL ;
void * V_13 = NULL ;
F_10 ( & V_15 ) ;
if ( V_5 -> V_16 && ! -- V_5 -> V_18 ) {
V_5 -> V_19 = NULL ;
V_13 = V_5 -> V_16 ;
V_5 -> V_16 = NULL ;
F_9 = V_5 -> V_20 ;
V_5 -> V_20 = NULL ;
}
if ( F_9 && V_13 )
F_9 ( V_13 ) ;
F_12 ( & V_15 ) ;
}
static void F_14 ( struct V_4 * V_5 , T_2 V_21 ,
bool V_22 )
{
T_3 V_23 = NULL ;
bool V_24 = false ;
F_10 ( & V_15 ) ;
if ( V_5 -> V_16 ) {
V_24 = true ;
V_5 -> V_18 ++ ;
if ( V_5 -> V_19 )
V_23 = V_22 ? V_5 -> V_19 -> V_22 : V_5 -> V_19 -> V_25 ;
}
F_12 ( & V_15 ) ;
if ( ! V_24 )
return;
if ( V_23 )
V_23 ( V_5 -> V_3 , V_21 , V_5 -> V_16 ) ;
F_13 ( V_5 ) ;
}
static struct V_4 *
F_15 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
F_4 ( & V_2 -> V_9 ) ;
F_16 (dd, &ds->dependent_devices, list) {
if ( V_3 == V_5 -> V_3 ) {
F_6 ( & V_2 -> V_9 ) ;
return V_5 ;
}
}
F_6 ( & V_2 -> V_9 ) ;
return NULL ;
}
static int F_17 ( T_1 V_3 )
{
T_4 V_26 ;
T_1 V_27 ;
V_26 = F_18 ( V_3 , L_1 , & V_27 ) ;
if ( F_19 ( V_26 ) )
return 0 ;
return 1 ;
}
static int F_20 ( T_1 V_3 )
{
T_4 V_26 ;
T_1 V_27 ;
V_26 = F_18 ( V_3 , L_2 , & V_27 ) ;
if ( F_19 ( V_26 ) )
return 0 ;
return 1 ;
}
static int F_21 ( T_1 V_3 )
{
T_1 V_27 ;
if ( ( F_22 ( F_18 ( V_3 , L_3 , & V_27 ) ) ) ||
( F_22 ( F_18 ( V_3 , L_4 , & V_27 ) ) ) ||
( F_22 ( F_18 ( V_3 , L_5 , & V_27 ) ) ) ||
( F_22 ( F_18 ( V_3 , L_6 , & V_27 ) ) ) )
return 1 ;
return 0 ;
}
static int F_23 ( T_1 V_3 )
{
struct V_28 * V_29 ;
int V_14 = 1 ;
if ( ! F_22 ( F_24 ( V_3 , & V_29 ) ) )
return 0 ;
if ( ! ( V_29 -> V_30 & V_31 ) )
V_14 = 0 ;
else
V_14 = ! strcmp ( L_7 , V_29 -> V_32 . string ) ;
F_25 ( V_29 ) ;
return V_14 ;
}
static int F_26 ( T_1 V_3 )
{
T_1 V_33 ;
if ( ! F_20 ( V_3 ) )
return 0 ;
if ( F_23 ( V_3 ) || F_21 ( V_3 ) )
return 1 ;
if ( ! F_27 ( V_3 , & V_33 ) && F_21 ( V_33 ) )
return 1 ;
return 0 ;
}
int F_28 ( T_1 V_3 )
{
struct V_1 * V_1 ;
if ( ! V_34 )
return 0 ;
if ( F_17 ( V_3 ) )
return 1 ;
F_16 (dock_station, &dock_stations, sibling)
if ( F_15 ( V_1 , V_3 ) )
return 1 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
unsigned long long V_35 ;
T_4 V_26 ;
if ( V_2 ) {
V_26 = F_30 ( V_2 -> V_3 , L_8 , NULL , & V_35 ) ;
if ( F_22 ( V_26 ) && V_35 )
return 1 ;
}
return 0 ;
}
static struct V_36 * F_31 ( T_1 V_3 )
{
struct V_36 * V_37 ;
int V_14 ;
if ( F_32 ( V_3 , & V_37 ) ) {
V_14 = F_33 ( V_3 ) ;
if ( V_14 )
F_34 ( L_9 , - V_14 ) ;
F_32 ( V_3 , & V_37 ) ;
}
return V_37 ;
}
static void F_35 ( T_1 V_3 )
{
struct V_36 * V_37 ;
if ( ! F_32 ( V_3 , & V_37 ) )
F_36 ( V_37 ) ;
}
static void F_37 ( struct V_1 * V_2 , T_2 V_21 )
{
struct V_4 * V_5 ;
F_10 ( & V_2 -> V_38 ) ;
F_16 (dd, &ds->dependent_devices, list)
F_14 ( V_5 , V_21 , false ) ;
F_16 (dd, &ds->dependent_devices, list) {
if ( V_21 == V_39 )
F_35 ( V_5 -> V_3 ) ;
else
F_31 ( V_5 -> V_3 ) ;
}
F_12 ( & V_2 -> V_38 ) ;
}
static void F_38 ( struct V_1 * V_2 , T_2 V_21 , int V_40 )
{
struct V_37 * V_41 = & V_2 -> V_42 -> V_41 ;
char V_43 [ 13 ] ;
char * V_44 [] = { V_43 , NULL } ;
struct V_4 * V_5 ;
if ( V_40 == V_45 )
sprintf ( V_43 , L_10 ) ;
else
sprintf ( V_43 , L_11 ) ;
if ( V_40 == V_46 )
F_39 ( & V_41 -> V_47 , V_48 , V_44 ) ;
F_16 (dd, &ds->dependent_devices, list)
F_14 ( V_5 , V_21 , true ) ;
if ( V_40 != V_46 )
F_39 ( & V_41 -> V_47 , V_48 , V_44 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_49 V_50 ;
union V_51 V_52 ;
T_4 V_26 ;
T_1 V_27 ;
V_26 = F_18 ( V_2 -> V_3 , L_2 , & V_27 ) ;
if ( F_19 ( V_26 ) ) {
F_34 ( L_12 ) ;
return;
}
V_50 . V_53 = 1 ;
V_50 . V_54 = & V_52 ;
V_52 . type = V_55 ;
V_52 . integer . V_56 = 1 ;
V_26 = F_41 ( V_2 -> V_3 , L_2 , & V_50 , NULL ) ;
if ( F_19 ( V_26 ) )
F_34 ( L_13 ) ;
}
static void F_42 ( struct V_1 * V_2 , int V_57 )
{
T_4 V_26 ;
struct V_49 V_50 ;
union V_51 V_52 ;
struct V_58 V_59 = { V_60 , NULL } ;
F_43 ( V_2 -> V_3 , L_14 , V_57 ? L_15 : L_16 ) ;
V_50 . V_53 = 1 ;
V_50 . V_54 = & V_52 ;
V_52 . type = V_55 ;
V_52 . integer . V_56 = V_57 ;
V_26 = F_41 ( V_2 -> V_3 , L_1 , & V_50 , & V_59 ) ;
if ( F_19 ( V_26 ) && V_26 != V_61 )
F_44 ( V_2 -> V_3 , L_17 ,
V_26 ) ;
F_25 ( V_59 . V_54 ) ;
}
static inline void V_57 ( struct V_1 * V_2 )
{
F_42 ( V_2 , 1 ) ;
}
static inline void F_45 ( struct V_1 * V_2 )
{
F_42 ( V_2 , 0 ) ;
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
static void F_50 ( struct V_1 * V_2 , int V_67 )
{
struct V_49 V_50 ;
union V_51 V_52 ;
T_4 V_26 ;
V_50 . V_53 = 1 ;
V_50 . V_54 = & V_52 ;
V_52 . type = V_55 ;
V_52 . integer . V_56 = ! ! V_67 ;
V_26 = F_41 ( V_2 -> V_3 , L_18 , & V_50 , NULL ) ;
if ( F_19 ( V_26 ) && V_26 != V_61 ) {
if ( V_67 )
F_51 ( V_2 -> V_3 ,
L_19 , V_26 ) ;
else
F_51 ( V_2 -> V_3 ,
L_20 , V_26 ) ;
}
}
static int F_52 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_62 & V_63 ) ||
F_53 ( V_65 , ( V_2 -> V_64 + V_68 ) ) )
return 1 ;
return 0 ;
}
int F_54 ( struct V_69 * V_70 )
{
if ( ! V_34 )
return - V_71 ;
return F_55 ( & V_72 , V_70 ) ;
}
void F_56 ( struct V_69 * V_70 )
{
if ( ! V_34 )
return;
F_57 ( & V_72 , V_70 ) ;
}
int F_58 ( T_1 V_3 ,
const struct V_11 * V_12 , void * V_13 ,
void (* F_8)( void * ) , void (* F_9)( void * ) )
{
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_14 = - V_73 ;
if ( F_11 ( ! V_13 ) )
return - V_73 ;
if ( ! V_34 )
return - V_71 ;
F_16 (dock_station, &dock_stations, sibling) {
V_5 = F_15 ( V_1 , V_3 ) ;
if ( V_5 && ! F_7 ( V_5 , V_12 , V_13 , F_8 , F_9 ) )
V_14 = 0 ;
}
return V_14 ;
}
void F_59 ( T_1 V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_1 ;
if ( ! V_34 )
return;
F_16 (dock_station, &dock_stations, sibling) {
V_5 = F_15 ( V_1 , V_3 ) ;
if ( V_5 )
F_13 ( V_5 ) ;
}
}
static int F_60 ( struct V_1 * V_2 , T_2 V_21 )
{
if ( F_52 ( V_2 ) )
return - V_74 ;
F_38 ( V_2 , V_21 , V_45 ) ;
F_37 ( V_2 , V_39 ) ;
F_45 ( V_2 ) ;
F_50 ( V_2 , 0 ) ;
F_40 ( V_2 ) ;
if ( F_29 ( V_2 ) ) {
F_44 ( V_2 -> V_3 , L_21 ) ;
return - V_74 ;
}
F_49 ( V_2 ) ;
return 0 ;
}
static void F_61 ( T_1 V_3 , T_2 V_21 , void * V_75 )
{
struct V_1 * V_2 = V_75 ;
struct V_36 * V_27 ;
int V_76 = 0 ;
if ( ( V_2 -> V_62 & V_77 ) && V_21 == V_78 )
V_21 = V_39 ;
switch ( V_21 ) {
case V_79 :
case V_78 :
if ( ! F_52 ( V_2 ) && F_32 ( V_2 -> V_3 ,
& V_27 ) ) {
F_46 ( V_2 ) ;
V_57 ( V_2 ) ;
if ( ! F_29 ( V_2 ) ) {
F_44 ( V_3 , L_22 ) ;
F_47 ( V_2 ) ;
break;
}
F_62 ( & V_72 ,
V_21 , NULL ) ;
F_37 ( V_2 , V_21 ) ;
F_47 ( V_2 ) ;
F_38 ( V_2 , V_21 , V_46 ) ;
F_50 ( V_2 , 1 ) ;
F_63 () ;
break;
}
if ( F_29 ( V_2 ) || F_52 ( V_2 ) )
break;
V_76 = 1 ;
V_21 = V_39 ;
case V_39 :
F_48 ( V_2 ) ;
if ( ( V_80 && ! ( V_2 -> V_62 & V_81 ) )
|| V_76 )
F_60 ( V_2 , V_21 ) ;
else
F_38 ( V_2 , V_21 , V_45 ) ;
break;
default:
F_44 ( V_3 , L_23 , V_21 ) ;
}
}
static void F_64 ( void * V_13 )
{
struct V_82 * V_75 = V_13 ;
F_65 () ;
F_61 ( V_75 -> V_3 , V_75 -> V_21 , V_75 -> V_2 ) ;
F_66 () ;
F_25 ( V_75 ) ;
}
static int F_67 ( struct V_69 * V_83 ,
unsigned long V_21 , void * V_75 )
{
struct V_1 * V_1 ;
T_1 V_3 = V_75 ;
if ( V_21 != V_79 && V_21 != V_78
&& V_21 != V_39 )
return 0 ;
F_65 () ;
F_16 (dock_station, &dock_stations, sibling) {
if ( V_1 -> V_3 == V_3 ) {
struct V_82 * V_5 ;
T_4 V_26 ;
V_5 = F_68 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
break;
V_5 -> V_3 = V_3 ;
V_5 -> V_21 = V_21 ;
V_5 -> V_2 = V_1 ;
V_26 = F_69 ( F_64 ,
V_5 ) ;
if ( F_19 ( V_26 ) )
F_25 ( V_5 ) ;
break;
}
}
F_66 () ;
return 0 ;
}
static T_4
F_70 ( T_1 V_3 , T_2 V_84 , void * V_13 , void * * V_85 )
{
T_4 V_26 ;
T_1 V_27 , V_86 ;
struct V_1 * V_2 = V_13 ;
V_26 = F_71 ( V_3 , & V_27 ) ;
if ( F_19 ( V_26 ) ) {
V_26 = F_27 ( V_3 , & V_86 ) ;
if ( F_19 ( V_26 ) )
goto V_87;
V_26 = F_71 ( V_86 , & V_27 ) ;
if ( F_19 ( V_26 ) )
goto V_87;
}
if ( V_27 == V_2 -> V_3 )
F_1 ( V_2 , V_3 ) ;
V_87:
return V_88 ;
}
static T_5 F_72 ( struct V_37 * V_41 ,
struct V_89 * V_90 , char * V_91 )
{
struct V_36 * V_27 ;
struct V_1 * V_1 = V_41 -> V_92 ;
if ( ! F_32 ( V_1 -> V_3 , & V_27 ) )
return snprintf ( V_91 , V_93 , L_24 ) ;
return snprintf ( V_91 , V_93 , L_25 ) ;
}
static T_5 F_73 ( struct V_37 * V_41 ,
struct V_89 * V_90 , char * V_91 )
{
struct V_1 * V_1 = V_41 -> V_92 ;
return snprintf ( V_91 , V_93 , L_26 , V_1 -> V_62 ) ;
}
static T_5 F_74 ( struct V_37 * V_41 , struct V_89 * V_90 ,
const char * V_91 , T_6 V_53 )
{
int V_14 ;
struct V_1 * V_1 = V_41 -> V_92 ;
if ( ! V_53 )
return - V_73 ;
F_65 () ;
F_48 ( V_1 ) ;
V_14 = F_60 ( V_1 , V_39 ) ;
F_66 () ;
return V_14 ? V_14 : V_53 ;
}
static T_5 F_75 ( struct V_37 * V_41 ,
struct V_89 * V_90 , char * V_91 )
{
unsigned long long V_94 ;
struct V_1 * V_1 = V_41 -> V_92 ;
T_4 V_26 = F_30 ( V_1 -> V_3 ,
L_27 , NULL , & V_94 ) ;
if ( F_19 ( V_26 ) )
return 0 ;
return snprintf ( V_91 , V_93 , L_28 , V_94 ) ;
}
static T_5 F_76 ( struct V_37 * V_41 ,
struct V_89 * V_90 , char * V_91 )
{
struct V_1 * V_1 = V_41 -> V_92 ;
char * type ;
if ( V_1 -> V_62 & V_77 )
type = L_29 ;
else if ( V_1 -> V_62 & V_81 )
type = L_30 ;
else if ( V_1 -> V_62 & V_95 )
type = L_31 ;
else
type = L_32 ;
return snprintf ( V_91 , V_93 , L_14 , type ) ;
}
static int T_7 F_77 ( T_1 V_3 )
{
int V_14 , V_96 ;
struct V_1 V_2 , * V_1 ;
struct V_97 * V_5 ;
V_96 = V_34 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_5 = F_78 ( NULL , L_33 , V_96 , & V_2 , sizeof( V_2 ) ) ;
if ( F_79 ( V_5 ) )
return F_80 ( V_5 ) ;
V_1 = V_5 -> V_41 . V_92 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_42 = V_5 ;
V_1 -> V_64 = V_65 - V_68 ;
F_81 ( & V_1 -> V_38 ) ;
F_82 ( & V_1 -> V_9 ) ;
F_3 ( & V_1 -> V_98 ) ;
F_83 ( & V_72 ) ;
F_3 ( & V_1 -> V_10 ) ;
F_84 ( & V_5 -> V_41 , 0 ) ;
if ( F_17 ( V_3 ) )
V_1 -> V_62 |= V_77 ;
if ( F_21 ( V_3 ) )
V_1 -> V_62 |= V_81 ;
if ( F_23 ( V_3 ) )
V_1 -> V_62 |= V_95 ;
V_14 = F_85 ( & V_5 -> V_41 . V_47 , & V_99 ) ;
if ( V_14 )
goto V_100;
F_86 ( V_101 , V_102 ,
V_103 , F_70 , NULL ,
V_1 , NULL ) ;
V_14 = F_1 ( V_1 , V_3 ) ;
if ( V_14 )
goto V_104;
V_34 ++ ;
F_87 ( & V_1 -> V_98 , & V_105 ) ;
return 0 ;
V_104:
F_88 ( & V_5 -> V_41 . V_47 , & V_99 ) ;
V_100:
F_89 ( V_5 ) ;
F_44 ( V_3 , L_34 , V_106 , V_14 ) ;
return V_14 ;
}
static T_7 T_4
F_90 ( T_1 V_3 , T_2 V_84 , void * V_13 , void * * V_85 )
{
if ( F_17 ( V_3 ) || F_26 ( V_3 ) )
F_77 ( V_3 ) ;
return V_88 ;
}
int T_7 F_91 ( void )
{
if ( V_107 )
return 0 ;
F_86 ( V_101 , V_102 ,
V_103 , F_90 , NULL , NULL , NULL ) ;
if ( ! V_34 ) {
F_92 ( V_108 L_35 ) ;
return 0 ;
}
F_93 ( & V_109 ) ;
F_92 ( V_108 L_36 ,
V_110 , V_34 ) ;
return 0 ;
}
