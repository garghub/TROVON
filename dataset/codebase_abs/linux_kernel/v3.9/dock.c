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
int V_18 ;
if ( F_29 ( V_3 , & V_26 ) ) {
V_18 = F_30 ( V_3 ) ;
if ( V_18 )
F_31 ( L_9 , - V_18 ) ;
F_29 ( V_3 , & V_26 ) ;
}
return V_26 ;
}
static void F_32 ( T_1 V_3 )
{
struct V_25 * V_26 ;
if ( ! F_29 ( V_3 , & V_26 ) )
F_33 ( V_26 ) ;
}
static void F_34 ( struct V_1 * V_2 , T_3 V_27 )
{
struct V_4 * V_5 ;
F_8 ( & V_2 -> V_12 ) ;
F_13 (dd, &ds->hotplug_devices, hotplug_list)
if ( V_5 -> V_28 && V_5 -> V_28 -> V_29 )
V_5 -> V_28 -> V_29 ( V_5 -> V_3 , V_27 , V_5 -> V_30 ) ;
F_13 (dd, &ds->dependent_devices, list) {
if ( V_27 == V_31 )
F_32 ( V_5 -> V_3 ) ;
else
F_28 ( V_5 -> V_3 ) ;
}
F_9 ( & V_2 -> V_12 ) ;
}
static void F_35 ( struct V_1 * V_2 , T_3 V_27 , int V_32 )
{
struct V_26 * V_33 = & V_2 -> V_34 -> V_33 ;
char V_35 [ 13 ] ;
char * V_36 [] = { V_35 , NULL } ;
struct V_4 * V_5 ;
if ( V_32 == V_37 )
sprintf ( V_35 , L_10 ) ;
else
sprintf ( V_35 , L_11 ) ;
if ( V_32 == V_38 )
F_36 ( & V_33 -> V_39 , V_40 , V_36 ) ;
F_13 (dd, &ds->hotplug_devices, hotplug_list)
if ( V_5 -> V_28 && V_5 -> V_28 -> V_41 )
V_5 -> V_28 -> V_41 ( V_5 -> V_3 , V_27 , V_5 -> V_30 ) ;
if ( V_32 != V_38 )
F_36 ( & V_33 -> V_39 , V_40 , V_36 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_42 V_43 ;
union V_44 V_45 ;
T_2 V_14 ;
T_1 V_15 ;
V_14 = F_15 ( V_2 -> V_3 , L_2 , & V_15 ) ;
if ( F_16 ( V_14 ) ) {
F_31 ( L_12 ) ;
return;
}
V_43 . V_46 = 1 ;
V_43 . V_47 = & V_45 ;
V_45 . type = V_48 ;
V_45 . integer . V_49 = 1 ;
V_14 = F_38 ( V_2 -> V_3 , L_2 , & V_43 , NULL ) ;
if ( F_16 ( V_14 ) )
F_31 ( L_13 ) ;
}
static void F_39 ( struct V_1 * V_2 , int V_50 )
{
T_2 V_14 ;
struct V_42 V_43 ;
union V_44 V_45 ;
struct V_51 V_52 = { V_53 , NULL } ;
F_40 ( V_2 -> V_3 , L_14 , V_50 ? L_15 : L_16 ) ;
V_43 . V_46 = 1 ;
V_43 . V_47 = & V_45 ;
V_45 . type = V_48 ;
V_45 . integer . V_49 = V_50 ;
V_14 = F_38 ( V_2 -> V_3 , L_1 , & V_43 , & V_52 ) ;
if ( F_16 ( V_14 ) && V_14 != V_54 )
F_41 ( V_2 -> V_3 , L_17 ,
V_14 ) ;
F_22 ( V_52 . V_47 ) ;
}
static inline void V_50 ( struct V_1 * V_2 )
{
F_39 ( V_2 , 1 ) ;
}
static inline void F_42 ( struct V_1 * V_2 )
{
F_39 ( V_2 , 0 ) ;
}
static inline void F_43 ( struct V_1 * V_2 )
{
V_2 -> V_55 |= V_56 ;
}
static inline void F_44 ( struct V_1 * V_2 )
{
V_2 -> V_55 &= ~ ( V_56 ) ;
V_2 -> V_57 = V_58 ;
}
static inline void F_45 ( struct V_1 * V_2 )
{
V_2 -> V_55 |= V_59 ;
}
static inline void F_46 ( struct V_1 * V_2 )
{
V_2 -> V_55 &= ~ ( V_59 ) ;
}
static void F_47 ( struct V_1 * V_2 , int V_60 )
{
struct V_42 V_43 ;
union V_44 V_45 ;
T_2 V_14 ;
V_43 . V_46 = 1 ;
V_43 . V_47 = & V_45 ;
V_45 . type = V_48 ;
V_45 . integer . V_49 = ! ! V_60 ;
V_14 = F_38 ( V_2 -> V_3 , L_18 , & V_43 , NULL ) ;
if ( F_16 ( V_14 ) && V_14 != V_54 ) {
if ( V_60 )
F_48 ( V_2 -> V_3 ,
L_19 , V_14 ) ;
else
F_48 ( V_2 -> V_3 ,
L_20 , V_14 ) ;
}
}
static int F_49 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_55 & V_56 ) ||
F_50 ( V_58 , ( V_2 -> V_57 + V_61 ) ) )
return 1 ;
return 0 ;
}
int F_51 ( struct V_62 * V_63 )
{
if ( ! V_23 )
return - V_64 ;
return F_52 ( & V_65 , V_63 ) ;
}
void F_53 ( struct V_62 * V_63 )
{
if ( ! V_23 )
return;
F_54 ( & V_65 , V_63 ) ;
}
int
F_55 ( T_1 V_3 , const struct V_66 * V_28 ,
void * V_30 )
{
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_18 = - V_67 ;
if ( ! V_23 )
return - V_64 ;
F_13 (dock_station, &dock_stations, sibling) {
V_5 = F_12 ( V_1 , V_3 ) ;
if ( V_5 ) {
V_5 -> V_28 = V_28 ;
V_5 -> V_30 = V_30 ;
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
static int F_57 ( struct V_1 * V_2 , T_3 V_27 )
{
if ( F_49 ( V_2 ) )
return - V_68 ;
F_35 ( V_2 , V_27 , V_37 ) ;
F_34 ( V_2 , V_31 ) ;
F_42 ( V_2 ) ;
F_47 ( V_2 , 0 ) ;
F_37 ( V_2 ) ;
if ( F_26 ( V_2 ) ) {
F_41 ( V_2 -> V_3 , L_21 ) ;
return - V_68 ;
}
F_46 ( V_2 ) ;
return 0 ;
}
static void F_58 ( T_1 V_3 , T_3 V_27 , void * V_69 )
{
struct V_1 * V_2 = V_69 ;
struct V_25 * V_15 ;
int V_70 = 0 ;
if ( ( V_2 -> V_55 & V_71 ) && V_27 == V_72 )
V_27 = V_31 ;
switch ( V_27 ) {
case V_73 :
case V_72 :
if ( ! F_49 ( V_2 ) && F_29 ( V_2 -> V_3 ,
& V_15 ) ) {
F_43 ( V_2 ) ;
V_50 ( V_2 ) ;
if ( ! F_26 ( V_2 ) ) {
F_41 ( V_3 , L_22 ) ;
F_44 ( V_2 ) ;
break;
}
F_59 ( & V_65 ,
V_27 , NULL ) ;
F_34 ( V_2 , V_27 ) ;
F_44 ( V_2 ) ;
F_35 ( V_2 , V_27 , V_38 ) ;
F_47 ( V_2 , 1 ) ;
F_60 () ;
break;
}
if ( F_26 ( V_2 ) || F_49 ( V_2 ) )
break;
V_70 = 1 ;
V_27 = V_31 ;
case V_31 :
F_45 ( V_2 ) ;
if ( ( V_74 && ! ( V_2 -> V_55 & V_75 ) )
|| V_70 )
F_57 ( V_2 , V_27 ) ;
else
F_35 ( V_2 , V_27 , V_37 ) ;
break;
default:
F_41 ( V_3 , L_23 , V_27 ) ;
}
}
static void F_61 ( void * V_30 )
{
struct V_76 * V_69 = V_30 ;
F_62 () ;
F_58 ( V_69 -> V_3 , V_69 -> V_27 , V_69 -> V_2 ) ;
F_63 () ;
F_22 ( V_69 ) ;
}
static int F_64 ( struct V_62 * V_77 ,
unsigned long V_27 , void * V_69 )
{
struct V_1 * V_1 ;
T_1 V_3 = V_69 ;
if ( V_27 != V_73 && V_27 != V_72
&& V_27 != V_31 )
return 0 ;
F_62 () ;
F_13 (dock_station, &dock_stations, sibling) {
if ( V_1 -> V_3 == V_3 ) {
struct V_76 * V_5 ;
T_2 V_14 ;
V_5 = F_65 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
break;
V_5 -> V_3 = V_3 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_2 = V_1 ;
V_14 = F_66 ( F_61 ,
V_5 ) ;
if ( F_16 ( V_14 ) )
F_22 ( V_5 ) ;
break;
}
}
F_63 () ;
return 0 ;
}
static T_2
F_67 ( T_1 V_3 , T_3 V_78 , void * V_30 , void * * V_79 )
{
T_2 V_14 ;
T_1 V_15 , V_80 ;
struct V_1 * V_2 = V_30 ;
V_14 = F_68 ( V_3 , & V_15 ) ;
if ( F_16 ( V_14 ) ) {
V_14 = F_24 ( V_3 , & V_80 ) ;
if ( F_16 ( V_14 ) )
goto V_81;
V_14 = F_68 ( V_80 , & V_15 ) ;
if ( F_16 ( V_14 ) )
goto V_81;
}
if ( V_15 == V_2 -> V_3 )
F_1 ( V_2 , V_3 ) ;
V_81:
return V_82 ;
}
static T_4 F_69 ( struct V_26 * V_33 ,
struct V_83 * V_84 , char * V_85 )
{
struct V_25 * V_15 ;
struct V_1 * V_1 = V_33 -> V_86 ;
if ( ! F_29 ( V_1 -> V_3 , & V_15 ) )
return snprintf ( V_85 , V_87 , L_24 ) ;
return snprintf ( V_85 , V_87 , L_25 ) ;
}
static T_4 F_70 ( struct V_26 * V_33 ,
struct V_83 * V_84 , char * V_85 )
{
struct V_1 * V_1 = V_33 -> V_86 ;
return snprintf ( V_85 , V_87 , L_26 , V_1 -> V_55 ) ;
}
static T_4 F_71 ( struct V_26 * V_33 , struct V_83 * V_84 ,
const char * V_85 , T_5 V_46 )
{
int V_18 ;
struct V_1 * V_1 = V_33 -> V_86 ;
if ( ! V_46 )
return - V_67 ;
F_45 ( V_1 ) ;
V_18 = F_57 ( V_1 , V_31 ) ;
return V_18 ? V_18 : V_46 ;
}
static T_4 F_72 ( struct V_26 * V_33 ,
struct V_83 * V_84 , char * V_85 )
{
unsigned long long V_88 ;
struct V_1 * V_1 = V_33 -> V_86 ;
T_2 V_14 = F_27 ( V_1 -> V_3 ,
L_27 , NULL , & V_88 ) ;
if ( F_16 ( V_14 ) )
return 0 ;
return snprintf ( V_85 , V_87 , L_28 , V_88 ) ;
}
static T_4 F_73 ( struct V_26 * V_33 ,
struct V_83 * V_84 , char * V_85 )
{
struct V_1 * V_1 = V_33 -> V_86 ;
char * type ;
if ( V_1 -> V_55 & V_71 )
type = L_29 ;
else if ( V_1 -> V_55 & V_75 )
type = L_30 ;
else if ( V_1 -> V_55 & V_89 )
type = L_31 ;
else
type = L_32 ;
return snprintf ( V_85 , V_87 , L_14 , type ) ;
}
static int T_6 F_74 ( T_1 V_3 )
{
int V_18 , V_90 ;
struct V_1 V_2 , * V_1 ;
struct V_91 * V_5 ;
V_90 = V_23 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_5 = F_75 ( NULL , L_33 , V_90 , & V_2 , sizeof( V_2 ) ) ;
if ( F_76 ( V_5 ) )
return F_77 ( V_5 ) ;
V_1 = V_5 -> V_33 . V_86 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_34 = V_5 ;
V_1 -> V_57 = V_58 - V_61 ;
F_78 ( & V_1 -> V_12 ) ;
F_79 ( & V_1 -> V_10 ) ;
F_3 ( & V_1 -> V_92 ) ;
F_3 ( & V_1 -> V_13 ) ;
F_80 ( & V_65 ) ;
F_3 ( & V_1 -> V_11 ) ;
F_81 ( & V_5 -> V_33 , 0 ) ;
if ( F_14 ( V_3 ) )
V_1 -> V_55 |= V_71 ;
if ( F_18 ( V_3 ) )
V_1 -> V_55 |= V_75 ;
if ( F_20 ( V_3 ) )
V_1 -> V_55 |= V_89 ;
V_18 = F_82 ( & V_5 -> V_33 . V_39 , & V_93 ) ;
if ( V_18 )
goto V_94;
F_83 ( V_95 , V_96 ,
V_97 , F_67 , NULL ,
V_1 , NULL ) ;
V_18 = F_1 ( V_1 , V_3 ) ;
if ( V_18 )
goto V_98;
V_23 ++ ;
F_84 ( & V_1 -> V_92 , & V_99 ) ;
return 0 ;
V_98:
F_85 ( & V_5 -> V_33 . V_39 , & V_93 ) ;
V_94:
F_86 ( V_5 ) ;
F_41 ( V_3 , L_34 , V_100 , V_18 ) ;
return V_18 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_4 * V_5 , * V_15 ;
struct V_91 * V_34 = V_2 -> V_34 ;
if ( ! V_23 )
return 0 ;
F_88 (dd, tmp, &ds->dependent_devices, list)
F_22 ( V_5 ) ;
F_11 ( & V_2 -> V_92 ) ;
F_85 ( & V_34 -> V_33 . V_39 , & V_93 ) ;
F_86 ( V_34 ) ;
return 0 ;
}
static T_6 T_2
F_89 ( T_1 V_3 , T_3 V_78 , void * V_30 , void * * V_79 )
{
if ( F_14 ( V_3 ) || F_23 ( V_3 ) )
F_74 ( V_3 ) ;
return V_82 ;
}
static int T_6 F_90 ( void )
{
if ( V_101 )
return 0 ;
F_83 ( V_95 , V_96 ,
V_97 , F_89 , NULL , NULL , NULL ) ;
if ( ! V_23 ) {
F_91 ( V_102 L_35 ) ;
return 0 ;
}
F_92 ( & V_103 ) ;
F_91 ( V_102 L_36 ,
V_104 , V_23 ) ;
return 0 ;
}
static void T_7 F_93 ( void )
{
struct V_1 * V_15 , * V_1 ;
F_94 ( & V_103 ) ;
F_88 (dock_station, tmp, &dock_stations, sibling)
F_87 ( V_1 ) ;
}
