static int
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return - V_7 ;
V_5 -> V_3 = V_3 ;
F_3 ( & V_5 -> V_8 ) ;
F_3 ( & V_5 -> V_9 ) ;
F_4 ( & V_2 -> V_10 ) ;
F_5 ( & V_5 -> V_8 , & V_2 -> V_11 ) ;
F_6 ( & V_2 -> V_10 ) ;
return 0 ;
}
static void
F_7 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
F_8 ( & V_2 -> V_12 ) ;
F_5 ( & V_5 -> V_9 , & V_2 -> V_13 ) ;
F_9 ( & V_2 -> V_12 ) ;
}
static void
F_10 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
F_8 ( & V_2 -> V_12 ) ;
F_11 ( & V_5 -> V_9 ) ;
F_9 ( & V_2 -> V_12 ) ;
}
static struct V_4 *
F_12 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
F_4 ( & V_2 -> V_10 ) ;
F_13 (dd, &ds->dependent_devices, list) {
if ( V_3 == V_5 -> V_3 ) {
F_6 ( & V_2 -> V_10 ) ;
return V_5 ;
}
}
F_6 ( & V_2 -> V_10 ) ;
return NULL ;
}
static int F_14 ( T_1 V_3 )
{
T_2 V_14 ;
T_1 V_15 ;
V_14 = F_15 ( V_3 , L_1 , & V_15 ) ;
if ( F_16 ( V_14 ) )
return 0 ;
return 1 ;
}
static int F_17 ( T_1 V_3 )
{
T_2 V_14 ;
T_1 V_15 ;
V_14 = F_15 ( V_3 , L_2 , & V_15 ) ;
if ( F_16 ( V_14 ) )
return 0 ;
return 1 ;
}
static int F_18 ( T_1 V_3 )
{
T_1 V_15 ;
if ( ( F_19 ( F_15 ( V_3 , L_3 , & V_15 ) ) ) ||
( F_19 ( F_15 ( V_3 , L_4 , & V_15 ) ) ) ||
( F_19 ( F_15 ( V_3 , L_5 , & V_15 ) ) ) ||
( F_19 ( F_15 ( V_3 , L_6 , & V_15 ) ) ) )
return 1 ;
return 0 ;
}
static int F_20 ( T_1 V_3 )
{
struct V_16 * V_17 ;
int V_18 = 1 ;
if ( ! F_19 ( F_21 ( V_3 , & V_17 ) ) )
return 0 ;
if ( ! ( V_17 -> V_19 & V_20 ) )
V_18 = 0 ;
else
V_18 = ! strcmp ( L_7 , V_17 -> V_21 . string ) ;
F_22 ( V_17 ) ;
return V_18 ;
}
static int F_23 ( T_1 V_3 )
{
T_1 V_22 ;
if ( ! F_17 ( V_3 ) )
return 0 ;
if ( F_20 ( V_3 ) || F_18 ( V_3 ) )
return 1 ;
if ( ! F_24 ( V_3 , & V_22 ) && F_18 ( V_22 ) )
return 1 ;
return 0 ;
}
int F_25 ( T_1 V_3 )
{
struct V_1 * V_1 ;
if ( ! V_23 )
return 0 ;
if ( F_14 ( V_3 ) )
return 1 ;
F_13 (dock_station, &dock_stations, sibling)
if ( F_12 ( V_1 , V_3 ) )
return 1 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
unsigned long long V_24 ;
T_2 V_14 ;
if ( V_2 ) {
V_14 = F_27 ( V_2 -> V_3 , L_8 , NULL , & V_24 ) ;
if ( F_19 ( V_14 ) && V_24 )
return 1 ;
}
return 0 ;
}
static struct V_25 * F_28 ( T_1 V_3 )
{
struct V_25 * V_26 ;
struct V_25 * V_27 ;
T_1 V_28 ;
int V_18 ;
if ( F_29 ( V_3 , & V_26 ) ) {
F_24 ( V_3 , & V_28 ) ;
if ( F_29 ( V_28 , & V_27 ) )
V_27 = NULL ;
V_18 = F_30 ( & V_26 , V_27 , V_3 ,
V_29 ) ;
if ( V_18 ) {
F_31 ( L_9 , - V_18 ) ;
return NULL ;
}
}
return V_26 ;
}
static void F_32 ( T_1 V_3 )
{
struct V_25 * V_26 ;
int V_18 ;
if ( ! F_29 ( V_3 , & V_26 ) ) {
V_18 = F_33 ( V_26 , 1 ) ;
if ( V_18 )
F_31 ( L_10 , - V_18 ) ;
}
}
static void F_34 ( struct V_1 * V_2 , T_3 V_30 )
{
struct V_4 * V_5 ;
F_8 ( & V_2 -> V_12 ) ;
F_13 (dd, &ds->hotplug_devices, hotplug_list)
if ( V_5 -> V_31 && V_5 -> V_31 -> V_32 )
V_5 -> V_31 -> V_32 ( V_5 -> V_3 , V_30 , V_5 -> V_33 ) ;
F_13 (dd, &ds->dependent_devices, list) {
if ( V_30 == V_34 )
F_32 ( V_5 -> V_3 ) ;
else
F_28 ( V_5 -> V_3 ) ;
}
F_9 ( & V_2 -> V_12 ) ;
}
static void F_35 ( struct V_1 * V_2 , T_3 V_30 , int V_35 )
{
struct V_26 * V_36 = & V_2 -> V_37 -> V_36 ;
char V_38 [ 13 ] ;
char * V_39 [] = { V_38 , NULL } ;
struct V_4 * V_5 ;
if ( V_35 == V_40 )
sprintf ( V_38 , L_11 ) ;
else
sprintf ( V_38 , L_12 ) ;
if ( V_35 == V_41 )
F_36 ( & V_36 -> V_42 , V_43 , V_39 ) ;
F_13 (dd, &ds->hotplug_devices, hotplug_list)
if ( V_5 -> V_31 && V_5 -> V_31 -> V_44 )
V_5 -> V_31 -> V_44 ( V_5 -> V_3 , V_30 , V_5 -> V_33 ) ;
if ( V_35 != V_41 )
F_36 ( & V_36 -> V_42 , V_43 , V_39 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_45 V_46 ;
union V_47 V_48 ;
T_2 V_14 ;
T_1 V_15 ;
V_14 = F_15 ( V_2 -> V_3 , L_2 , & V_15 ) ;
if ( F_16 ( V_14 ) ) {
F_31 ( L_13 ) ;
return;
}
V_46 . V_49 = 1 ;
V_46 . V_50 = & V_48 ;
V_48 . type = V_51 ;
V_48 . integer . V_52 = 1 ;
V_14 = F_38 ( V_2 -> V_3 , L_2 , & V_46 , NULL ) ;
if ( F_16 ( V_14 ) )
F_31 ( L_14 ) ;
}
static void F_39 ( struct V_1 * V_2 , int V_53 )
{
T_2 V_14 ;
struct V_45 V_46 ;
union V_47 V_48 ;
struct V_54 V_55 = { V_56 , NULL } ;
struct V_54 V_57 = { V_56 , NULL } ;
F_40 ( V_2 -> V_3 , V_58 , & V_57 ) ;
F_41 (KERN_INFO PREFIX L_15 ,
(char *)name_buffer.pointer, dock ? L_16 : L_17 ) ;
V_46 . V_49 = 1 ;
V_46 . V_50 = & V_48 ;
V_48 . type = V_51 ;
V_48 . integer . V_52 = V_53 ;
V_14 = F_38 ( V_2 -> V_3 , L_1 , & V_46 , & V_55 ) ;
if ( F_16 ( V_14 ) && V_14 != V_59 )
F_42 ( ( V_60 , V_14 , L_18
L_19 , ( char * ) V_57 . V_50 ) ) ;
F_22 ( V_55 . V_50 ) ;
F_22 ( V_57 . V_50 ) ;
}
static inline void V_53 ( struct V_1 * V_2 )
{
F_39 ( V_2 , 1 ) ;
}
static inline void F_43 ( struct V_1 * V_2 )
{
F_39 ( V_2 , 0 ) ;
}
static inline void F_44 ( struct V_1 * V_2 )
{
V_2 -> V_61 |= V_62 ;
}
static inline void F_45 ( struct V_1 * V_2 )
{
V_2 -> V_61 &= ~ ( V_62 ) ;
V_2 -> V_63 = V_64 ;
}
static inline void F_46 ( struct V_1 * V_2 )
{
V_2 -> V_61 |= V_65 ;
}
static inline void F_47 ( struct V_1 * V_2 )
{
V_2 -> V_61 &= ~ ( V_65 ) ;
}
static void F_48 ( struct V_1 * V_2 , int V_66 )
{
struct V_45 V_46 ;
union V_47 V_48 ;
T_2 V_14 ;
V_46 . V_49 = 1 ;
V_46 . V_50 = & V_48 ;
V_48 . type = V_51 ;
V_48 . integer . V_52 = ! ! V_66 ;
V_14 = F_38 ( V_2 -> V_3 , L_20 , & V_46 , NULL ) ;
if ( F_16 ( V_14 ) && V_14 != V_59 ) {
if ( V_66 )
F_41 (KERN_WARNING PREFIX L_21 ) ;
else
F_41 (KERN_WARNING PREFIX L_22 ) ;
}
}
static int F_49 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_61 & V_62 ) ||
F_50 ( V_64 , ( V_2 -> V_63 + V_67 ) ) )
return 1 ;
return 0 ;
}
int F_51 ( struct V_68 * V_69 )
{
if ( ! V_23 )
return - V_70 ;
return F_52 ( & V_71 , V_69 ) ;
}
void F_53 ( struct V_68 * V_69 )
{
if ( ! V_23 )
return;
F_54 ( & V_71 , V_69 ) ;
}
int
F_55 ( T_1 V_3 , const struct V_72 * V_31 ,
void * V_33 )
{
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_18 = - V_73 ;
if ( ! V_23 )
return - V_70 ;
F_13 (dock_station, &dock_stations, sibling) {
V_5 = F_12 ( V_1 , V_3 ) ;
if ( V_5 ) {
V_5 -> V_31 = V_31 ;
V_5 -> V_33 = V_33 ;
F_7 ( V_1 , V_5 ) ;
V_18 = 0 ;
}
}
return V_18 ;
}
void F_56 ( T_1 V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_1 ;
if ( ! V_23 )
return;
F_13 (dock_station, &dock_stations, sibling) {
V_5 = F_12 ( V_1 , V_3 ) ;
if ( V_5 )
F_10 ( V_1 , V_5 ) ;
}
}
static int F_57 ( struct V_1 * V_2 , T_3 V_30 )
{
if ( F_49 ( V_2 ) )
return - V_74 ;
F_35 ( V_2 , V_30 , V_40 ) ;
F_34 ( V_2 , V_34 ) ;
F_43 ( V_2 ) ;
F_48 ( V_2 , 0 ) ;
F_37 ( V_2 ) ;
if ( F_26 ( V_2 ) ) {
F_41 (KERN_ERR PREFIX L_23 ) ;
return - V_74 ;
}
F_47 ( V_2 ) ;
return 0 ;
}
static void F_58 ( T_1 V_3 , T_3 V_30 , void * V_75 )
{
struct V_1 * V_2 = V_75 ;
struct V_25 * V_15 ;
int V_76 = 0 ;
if ( ( V_2 -> V_61 & V_77 ) && V_30 == V_78 )
V_30 = V_34 ;
switch ( V_30 ) {
case V_79 :
case V_78 :
if ( ! F_49 ( V_2 ) && F_29 ( V_2 -> V_3 ,
& V_15 ) ) {
F_44 ( V_2 ) ;
V_53 ( V_2 ) ;
if ( ! F_26 ( V_2 ) ) {
F_41 (KERN_ERR PREFIX L_24 ) ;
F_45 ( V_2 ) ;
break;
}
F_59 ( & V_71 ,
V_30 , NULL ) ;
F_34 ( V_2 , V_30 ) ;
F_45 ( V_2 ) ;
F_35 ( V_2 , V_30 , V_41 ) ;
F_48 ( V_2 , 1 ) ;
F_60 () ;
break;
}
if ( F_26 ( V_2 ) || F_49 ( V_2 ) )
break;
V_76 = 1 ;
V_30 = V_34 ;
case V_34 :
F_46 ( V_2 ) ;
if ( ( V_80 && ! ( V_2 -> V_61 & V_81 ) )
|| V_76 )
F_57 ( V_2 , V_30 ) ;
else
F_35 ( V_2 , V_30 , V_40 ) ;
break;
default:
F_41 (KERN_ERR PREFIX L_25 , event) ;
}
}
static void F_61 ( void * V_33 )
{
struct V_82 * V_75 = V_33 ;
F_58 ( V_75 -> V_3 , V_75 -> V_30 , V_75 -> V_2 ) ;
F_22 ( V_75 ) ;
}
static int F_62 ( struct V_68 * V_83 ,
unsigned long V_30 , void * V_75 )
{
struct V_1 * V_1 ;
T_1 V_3 = V_75 ;
if ( V_30 != V_79 && V_30 != V_78
&& V_30 != V_34 )
return 0 ;
F_13 (dock_station, &dock_stations, sibling) {
if ( V_1 -> V_3 == V_3 ) {
struct V_82 * V_5 ;
V_5 = F_63 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return 0 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_30 = V_30 ;
V_5 -> V_2 = V_1 ;
F_64 ( F_61 , V_5 ) ;
return 0 ;
}
}
return 0 ;
}
static T_2
F_65 ( T_1 V_3 , T_3 V_84 , void * V_33 , void * * V_85 )
{
T_2 V_14 ;
T_1 V_15 , V_28 ;
struct V_1 * V_2 = V_33 ;
V_14 = F_66 ( V_3 , & V_15 ) ;
if ( F_16 ( V_14 ) ) {
V_14 = F_24 ( V_3 , & V_28 ) ;
if ( F_16 ( V_14 ) )
goto V_86;
V_14 = F_66 ( V_28 , & V_15 ) ;
if ( F_16 ( V_14 ) )
goto V_86;
}
if ( V_15 == V_2 -> V_3 )
F_1 ( V_2 , V_3 ) ;
V_86:
return V_87 ;
}
static T_4 F_67 ( struct V_26 * V_36 ,
struct V_88 * V_89 , char * V_90 )
{
struct V_25 * V_15 ;
struct V_1 * V_1 = V_36 -> V_91 ;
if ( F_19 ( F_29 ( V_1 -> V_3 , & V_15 ) ) )
return snprintf ( V_90 , V_92 , L_26 ) ;
return snprintf ( V_90 , V_92 , L_27 ) ;
}
static T_4 F_68 ( struct V_26 * V_36 ,
struct V_88 * V_89 , char * V_90 )
{
struct V_1 * V_1 = V_36 -> V_91 ;
return snprintf ( V_90 , V_92 , L_28 , V_1 -> V_61 ) ;
}
static T_4 F_69 ( struct V_26 * V_36 , struct V_88 * V_89 ,
const char * V_90 , T_5 V_49 )
{
int V_18 ;
struct V_1 * V_1 = V_36 -> V_91 ;
if ( ! V_49 )
return - V_73 ;
F_46 ( V_1 ) ;
V_18 = F_57 ( V_1 , V_34 ) ;
return V_18 ? V_18 : V_49 ;
}
static T_4 F_70 ( struct V_26 * V_36 ,
struct V_88 * V_89 , char * V_90 )
{
unsigned long long V_93 ;
struct V_1 * V_1 = V_36 -> V_91 ;
T_2 V_14 = F_27 ( V_1 -> V_3 ,
L_29 , NULL , & V_93 ) ;
if ( F_16 ( V_14 ) )
return 0 ;
return snprintf ( V_90 , V_92 , L_30 , V_93 ) ;
}
static T_4 F_71 ( struct V_26 * V_36 ,
struct V_88 * V_89 , char * V_90 )
{
struct V_1 * V_1 = V_36 -> V_91 ;
char * type ;
if ( V_1 -> V_61 & V_77 )
type = L_31 ;
else if ( V_1 -> V_61 & V_81 )
type = L_32 ;
else if ( V_1 -> V_61 & V_94 )
type = L_33 ;
else
type = L_34 ;
return snprintf ( V_90 , V_92 , L_35 , type ) ;
}
static int T_6 F_72 ( T_1 V_3 )
{
int V_18 , V_95 ;
struct V_1 V_2 , * V_1 ;
struct V_96 * V_5 ;
V_95 = V_23 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_5 = F_73 ( NULL , L_36 , V_95 , & V_2 , sizeof( V_2 ) ) ;
if ( F_74 ( V_5 ) )
return F_75 ( V_5 ) ;
V_1 = V_5 -> V_36 . V_91 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_37 = V_5 ;
V_1 -> V_63 = V_64 - V_67 ;
F_76 ( & V_1 -> V_12 ) ;
F_77 ( & V_1 -> V_10 ) ;
F_3 ( & V_1 -> V_97 ) ;
F_3 ( & V_1 -> V_13 ) ;
F_78 ( & V_71 ) ;
F_3 ( & V_1 -> V_11 ) ;
F_79 ( & V_5 -> V_36 , 0 ) ;
if ( F_14 ( V_3 ) )
V_1 -> V_61 |= V_77 ;
if ( F_18 ( V_3 ) )
V_1 -> V_61 |= V_81 ;
if ( F_20 ( V_3 ) )
V_1 -> V_61 |= V_94 ;
V_18 = F_80 ( & V_5 -> V_36 . V_42 , & V_98 ) ;
if ( V_18 )
goto V_99;
F_81 ( V_100 , V_101 ,
V_102 , F_65 , NULL ,
V_1 , NULL ) ;
V_18 = F_1 ( V_1 , V_3 ) ;
if ( V_18 )
goto V_103;
V_23 ++ ;
F_82 ( & V_1 -> V_97 , & V_104 ) ;
return 0 ;
V_103:
F_83 ( & V_5 -> V_36 . V_42 , & V_98 ) ;
V_99:
F_84 ( V_5 ) ;
F_41 ( V_105 L_37 , V_106 , V_18 ) ;
return V_18 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_4 * V_5 , * V_15 ;
struct V_96 * V_37 = V_2 -> V_37 ;
if ( ! V_23 )
return 0 ;
F_86 (dd, tmp, &ds->dependent_devices, list)
F_22 ( V_5 ) ;
F_11 ( & V_2 -> V_97 ) ;
F_83 ( & V_37 -> V_36 . V_42 , & V_98 ) ;
F_84 ( V_37 ) ;
return 0 ;
}
static T_6 T_2
F_87 ( T_1 V_3 , T_3 V_84 , void * V_33 , void * * V_85 )
{
if ( F_14 ( V_3 ) )
F_72 ( V_3 ) ;
return V_87 ;
}
static T_6 T_2
F_88 ( T_1 V_3 , T_3 V_84 , void * V_33 , void * * V_85 )
{
if ( F_23 ( V_3 ) && ! F_14 ( V_3 ) )
F_72 ( V_3 ) ;
return V_87 ;
}
static int T_6 F_89 ( void )
{
if ( V_107 )
return 0 ;
F_81 ( V_100 , V_101 ,
V_102 , F_87 , NULL , NULL , NULL ) ;
F_81 ( V_100 , V_101 ,
V_102 , F_88 , NULL , NULL , NULL ) ;
if ( ! V_23 ) {
F_41 (KERN_INFO PREFIX L_38 ) ;
return 0 ;
}
F_90 ( & V_108 ) ;
F_41 (KERN_INFO PREFIX L_39 ,
ACPI_DOCK_DRIVER_DESCRIPTION, dock_station_count) ;
return 0 ;
}
static void T_7 F_91 ( void )
{
struct V_1 * V_15 , * V_1 ;
F_92 ( & V_108 ) ;
F_86 (dock_station, tmp, &dock_stations, sibling)
F_85 ( V_1 ) ;
}
