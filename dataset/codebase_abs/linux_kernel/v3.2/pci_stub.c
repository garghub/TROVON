static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_3 -> V_3 , L_1 ) ;
V_4 = F_3 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_3 = F_4 ( V_3 ) ;
if ( ! V_4 -> V_3 ) {
F_5 ( V_4 ) ;
return NULL ;
}
F_6 ( & V_4 -> V_6 ) ;
F_7 ( & V_4 -> V_7 ) ;
return V_4 ;
}
static void F_8 ( struct V_6 * V_6 )
{
struct V_1 * V_4 ;
V_4 = F_9 ( V_6 , struct V_1 , V_6 ) ;
F_2 ( & V_4 -> V_3 -> V_3 , L_2 ) ;
F_10 ( V_4 -> V_3 ) ;
F_11 ( V_4 -> V_3 ) ;
F_12 ( V_4 -> V_3 ) ;
F_13 ( V_4 -> V_3 ) ;
F_5 ( F_14 ( V_4 -> V_3 ) ) ;
F_15 ( V_4 -> V_3 , NULL ) ;
F_16 ( V_4 -> V_3 ) ;
F_5 ( V_4 ) ;
}
static inline void F_17 ( struct V_1 * V_4 )
{
F_18 ( & V_4 -> V_6 ) ;
}
static inline void F_19 ( struct V_1 * V_4 )
{
F_20 ( & V_4 -> V_6 , F_8 ) ;
}
static struct V_1 * F_21 ( int V_8 , int V_9 ,
int V_10 , int V_11 )
{
struct V_1 * V_4 = NULL ;
unsigned long V_12 ;
F_22 ( & V_13 , V_12 ) ;
F_23 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 != NULL
&& V_8 == F_24 ( V_4 -> V_3 -> V_9 )
&& V_9 == V_4 -> V_3 -> V_9 -> V_14
&& F_25 ( V_10 , V_11 ) == V_4 -> V_3 -> V_15 ) {
F_17 ( V_4 ) ;
goto V_16;
}
}
V_4 = NULL ;
V_16:
F_26 ( & V_13 , V_12 ) ;
return V_4 ;
}
static struct V_2 * F_27 ( struct V_17 * V_18 ,
struct V_1 * V_4 )
{
struct V_2 * V_2 = NULL ;
unsigned long V_12 ;
F_17 ( V_4 ) ;
F_22 ( & V_4 -> V_7 , V_12 ) ;
if ( ! V_4 -> V_18 ) {
V_4 -> V_18 = V_18 ;
V_2 = V_4 -> V_3 ;
}
F_26 ( & V_4 -> V_7 , V_12 ) ;
if ( ! V_2 )
F_19 ( V_4 ) ;
return V_2 ;
}
struct V_2 * F_28 ( struct V_17 * V_18 ,
int V_8 , int V_9 ,
int V_10 , int V_11 )
{
struct V_1 * V_4 ;
struct V_2 * V_19 = NULL ;
unsigned long V_12 ;
F_22 ( & V_13 , V_12 ) ;
F_23 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 != NULL
&& V_8 == F_24 ( V_4 -> V_3 -> V_9 )
&& V_9 == V_4 -> V_3 -> V_9 -> V_14
&& F_25 ( V_10 , V_11 ) == V_4 -> V_3 -> V_15 ) {
V_19 = F_27 ( V_18 , V_4 ) ;
break;
}
}
F_26 ( & V_13 , V_12 ) ;
return V_19 ;
}
struct V_2 * F_29 ( struct V_17 * V_18 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_2 * V_19 = NULL ;
unsigned long V_12 ;
F_22 ( & V_13 , V_12 ) ;
F_23 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_19 = F_27 ( V_18 , V_4 ) ;
break;
}
}
F_26 ( & V_13 , V_12 ) ;
return V_19 ;
}
void F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_20 = NULL ;
unsigned long V_12 ;
F_22 ( & V_13 , V_12 ) ;
F_23 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_20 = V_4 ;
break;
}
}
F_26 ( & V_13 , V_12 ) ;
if ( F_31 ( ! V_20 ) )
return;
F_32 ( & V_21 ) ;
F_11 ( V_20 -> V_3 ) ;
F_12 ( V_20 -> V_3 ) ;
F_33 ( V_20 -> V_3 ) ;
F_22 ( & V_20 -> V_7 , V_12 ) ;
V_20 -> V_18 = NULL ;
F_26 ( & V_20 -> V_7 , V_12 ) ;
F_19 ( V_20 ) ;
F_34 ( & V_21 ) ;
}
static int T_1 F_35 ( struct V_2 * V_3 ,
struct V_22 * V_23 )
{
for (; V_3 != NULL ; V_3 = V_3 -> V_9 -> V_24 ) {
if ( F_24 ( V_3 -> V_9 ) == V_23 -> V_8
&& V_3 -> V_9 -> V_14 == V_23 -> V_9
&& V_3 -> V_15 == V_23 -> V_15 )
return 1 ;
if ( V_3 == V_3 -> V_9 -> V_24 )
break;
}
return 0 ;
}
static int T_1 F_36 ( struct V_2 * V_3 )
{
struct V_22 * V_23 ;
unsigned long V_12 ;
int V_25 = 0 ;
F_22 ( & V_26 , V_12 ) ;
F_23 (pdev_id, &pcistub_device_ids, slot_list) {
if ( F_35 ( V_3 , V_23 ) ) {
V_25 = 1 ;
break;
}
}
F_26 ( & V_26 , V_12 ) ;
return V_25 ;
}
static int T_1 F_37 ( struct V_2 * V_3 )
{
struct V_27 * V_28 ;
int V_29 = 0 ;
F_2 ( & V_3 -> V_3 , L_3 ) ;
V_28 = F_3 ( sizeof( * V_28 ) + strlen ( V_30 L_4 )
+ strlen ( F_38 ( V_3 ) ) + 1 , V_5 ) ;
if ( ! V_28 ) {
V_29 = - V_31 ;
goto V_16;
}
F_15 ( V_3 , V_28 ) ;
sprintf ( V_28 -> V_32 , V_30 L_5 , F_38 ( V_3 ) ) ;
F_2 ( & V_3 -> V_3 , L_6 ) ;
F_39 ( & V_33 ) ;
V_29 = F_40 ( V_3 ) ;
if ( V_29 )
goto V_16;
F_2 ( & V_3 -> V_3 , L_7 ) ;
V_29 = F_41 ( V_3 ) ;
if ( V_29 )
goto V_34;
F_2 ( & V_3 -> V_3 , L_8 ) ;
F_11 ( V_3 ) ;
return 0 ;
V_34:
F_13 ( V_3 ) ;
V_16:
F_15 ( V_3 , NULL ) ;
F_5 ( V_28 ) ;
return V_29 ;
}
static int T_2 F_42 ( void )
{
struct V_1 * V_4 ;
unsigned long V_12 ;
int V_29 = 0 ;
F_43 ( V_30 L_9 ) ;
F_22 ( & V_13 , V_12 ) ;
while ( ! F_44 ( & V_35 ) ) {
V_4 = F_9 ( V_35 . V_36 ,
struct V_1 , V_37 ) ;
F_45 ( & V_4 -> V_37 ) ;
F_26 ( & V_13 , V_12 ) ;
V_29 = F_37 ( V_4 -> V_3 ) ;
if ( V_29 ) {
F_46 ( & V_4 -> V_3 -> V_3 ,
L_10 , V_29 ) ;
F_5 ( V_4 ) ;
V_4 = NULL ;
}
F_22 ( & V_13 , V_12 ) ;
if ( V_4 )
F_47 ( & V_4 -> V_37 , & V_38 ) ;
}
V_39 = 1 ;
F_26 ( & V_13 , V_12 ) ;
return 0 ;
}
static int T_1 F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_12 ;
int V_29 = 0 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_31 ;
F_22 ( & V_13 , V_12 ) ;
if ( V_39 ) {
F_26 ( & V_13 , V_12 ) ;
V_29 = F_37 ( V_4 -> V_3 ) ;
F_22 ( & V_13 , V_12 ) ;
if ( ! V_29 )
F_49 ( & V_4 -> V_37 , & V_38 ) ;
} else {
F_2 ( & V_3 -> V_3 , L_11 ) ;
F_49 ( & V_4 -> V_37 , & V_35 ) ;
}
F_26 ( & V_13 , V_12 ) ;
if ( V_29 )
F_19 ( V_4 ) ;
return V_29 ;
}
static int T_1 F_50 ( struct V_2 * V_3 ,
const struct V_40 * V_41 )
{
int V_29 = 0 ;
F_2 ( & V_3 -> V_3 , L_12 ) ;
if ( F_36 ( V_3 ) ) {
if ( V_3 -> V_42 != V_43
&& V_3 -> V_42 != V_44 ) {
F_46 ( & V_3 -> V_3 , L_13
L_14
L_15 ) ;
V_29 = - V_45 ;
goto V_16;
}
F_51 ( & V_3 -> V_3 , L_16 ) ;
V_29 = F_48 ( V_3 ) ;
} else
V_29 = - V_45 ;
V_16:
return V_29 ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_20 = NULL ;
unsigned long V_12 ;
F_2 ( & V_3 -> V_3 , L_17 ) ;
F_22 ( & V_13 , V_12 ) ;
F_53 ( V_3 ) ;
F_23 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_20 = V_4 ;
break;
}
}
F_26 ( & V_13 , V_12 ) ;
if ( V_20 ) {
F_2 ( & V_3 -> V_3 , L_18 ,
V_20 -> V_18 ) ;
if ( V_20 -> V_18 ) {
F_54 (KERN_WARNING DRV_NAME L_19
L_20 ,
pci_name(found_psdev->dev)) ;
F_54 (KERN_WARNING DRV_NAME L_21
L_22 ) ;
F_54 (KERN_WARNING DRV_NAME L_23
L_24 ) ;
F_54 (KERN_WARNING DRV_NAME L_25
L_26 ) ;
F_55 ( V_20 -> V_18 ,
V_20 -> V_3 ) ;
}
F_22 ( & V_13 , V_12 ) ;
F_45 ( & V_20 -> V_37 ) ;
F_26 ( & V_13 , V_12 ) ;
F_19 ( V_20 ) ;
}
}
static void F_56 ( struct V_1 * V_4 )
{
struct V_46 V_47 ;
int V_29 ;
char V_48 [ V_49 ] ;
F_57 ( ! V_4 ) ;
snprintf ( V_48 , V_49 , L_27 ,
V_4 -> V_18 -> V_50 -> V_51 ) ;
V_52:
V_29 = F_58 ( & V_47 ) ;
if ( V_29 ) {
F_46 ( & V_4 -> V_3 -> V_3 ,
L_28 , V_29 ) ;
return;
}
F_59 ( V_47 , V_48 , L_29 , L_30 ) ;
V_29 = F_60 ( V_47 , 0 ) ;
if ( V_29 ) {
if ( V_29 == - V_53 )
goto V_52;
F_46 ( & V_4 -> V_3 -> V_3 ,
L_31 , V_29 ) ;
return;
}
}
static T_3 F_61 ( struct V_1 * V_4 ,
T_4 V_54 , int V_55 ,
T_3 V_56 )
{
T_3 V_57 = V_56 ;
struct V_58 * V_59 ;
int V_60 ;
V_59 = & ( V_4 -> V_18 -> V_61 -> V_59 ) ;
V_59 -> V_62 = V_55 ;
V_59 -> V_29 = V_54 ;
V_60 = F_62 ( V_4 -> V_3 , V_4 -> V_18 ,
& V_59 -> V_8 , & V_59 -> V_9 , & V_59 -> V_15 ) ;
if ( ! V_60 ) {
F_46 ( & V_4 -> V_3 -> V_3 ,
V_30 L_32 ) ;
return V_63 ;
}
F_63 () ;
F_2 ( & V_4 -> V_3 -> V_3 ,
V_30 L_33 ,
V_55 , V_59 -> V_8 , V_59 -> V_9 , V_59 -> V_15 ) ;
F_64 ( V_64 , ( unsigned long * ) & V_4 -> V_18 -> V_12 ) ;
F_64 ( V_65 ,
( unsigned long * ) & V_4 -> V_18 -> V_61 -> V_12 ) ;
F_63 () ;
F_65 ( V_4 -> V_18 -> V_66 ) ;
V_60 = F_66 ( V_33 ,
! ( F_67 ( V_65 , ( unsigned long * )
& V_4 -> V_18 -> V_61 -> V_12 ) ) , 300 * V_67 ) ;
if ( ! V_60 ) {
if ( F_67 ( V_65 ,
( unsigned long * ) & V_4 -> V_18 -> V_61 -> V_12 ) ) {
F_46 ( & V_4 -> V_3 -> V_3 ,
L_34 ) ;
F_68 ( V_65 ,
( unsigned long * ) & V_4 -> V_18 -> V_61 -> V_12 ) ;
V_59 -> V_29 = V_63 ;
return V_57 ;
}
}
F_68 ( V_64 , ( unsigned long * ) & V_4 -> V_18 -> V_12 ) ;
if ( F_67 ( V_68 ,
( unsigned long * ) & V_4 -> V_18 -> V_61 -> V_12 ) ) {
F_2 ( & V_4 -> V_3 -> V_3 ,
L_35 V_30 L_36 ) ;
F_69 ( V_4 -> V_18 ) ;
}
V_57 = ( T_3 ) V_59 -> V_29 ;
return V_57 ;
}
static T_3 F_70 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
T_3 V_56 ;
V_56 = V_69 ;
F_2 ( & V_3 -> V_3 , L_37 ,
V_3 -> V_9 -> V_14 , V_3 -> V_15 ) ;
F_32 ( & V_21 ) ;
V_4 = F_21 ( F_24 ( V_3 -> V_9 ) ,
V_3 -> V_9 -> V_14 ,
F_71 ( V_3 -> V_15 ) ,
F_72 ( V_3 -> V_15 ) ) ;
if ( ! V_4 || ! V_4 -> V_18 ) {
F_46 ( & V_3 -> V_3 ,
V_30 L_38 ) ;
goto V_70;
}
if ( ! V_4 -> V_18 -> V_61 ) {
F_46 ( & V_3 -> V_3 , V_30 L_39
L_40 ) ;
F_56 ( V_4 ) ;
goto V_71;
}
if ( ! F_67 ( V_72 ,
( unsigned long * ) & V_4 -> V_18 -> V_61 -> V_12 ) ) {
F_46 ( & V_3 -> V_3 ,
L_41 ) ;
goto V_71;
}
V_56 = F_61 ( V_4 , 1 , V_73 , V_56 ) ;
if ( V_56 == V_63 ||
V_56 == V_74 ) {
F_2 ( & V_3 -> V_3 ,
L_42 ) ;
F_56 ( V_4 ) ;
}
V_71:
F_19 ( V_4 ) ;
V_70:
F_34 ( & V_21 ) ;
return V_56 ;
}
static T_3 F_73 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
T_3 V_56 ;
V_56 = V_69 ;
F_2 ( & V_3 -> V_3 , L_43 ,
V_3 -> V_9 -> V_14 , V_3 -> V_15 ) ;
F_32 ( & V_21 ) ;
V_4 = F_21 ( F_24 ( V_3 -> V_9 ) ,
V_3 -> V_9 -> V_14 ,
F_71 ( V_3 -> V_15 ) ,
F_72 ( V_3 -> V_15 ) ) ;
if ( ! V_4 || ! V_4 -> V_18 ) {
F_46 ( & V_3 -> V_3 ,
V_30 L_38 ) ;
goto V_70;
}
if ( ! V_4 -> V_18 -> V_61 ) {
F_46 ( & V_3 -> V_3 , V_30 L_39
L_40 ) ;
F_56 ( V_4 ) ;
goto V_71;
}
if ( ! F_67 ( V_72 ,
( unsigned long * ) & V_4 -> V_18 -> V_61 -> V_12 ) ) {
F_46 ( & V_3 -> V_3 ,
L_41 ) ;
goto V_71;
}
V_56 = F_61 ( V_4 , 1 , V_75 , V_56 ) ;
if ( V_56 == V_63 ||
V_56 == V_74 ) {
F_2 ( & V_3 -> V_3 ,
L_44 ) ;
F_56 ( V_4 ) ;
}
V_71:
F_19 ( V_4 ) ;
V_70:
F_34 ( & V_21 ) ;
return V_56 ;
}
static T_3 F_74 ( struct V_2 * V_3 ,
T_4 error )
{
struct V_1 * V_4 ;
T_3 V_56 ;
V_56 = V_76 ;
F_2 ( & V_3 -> V_3 , L_45 ,
V_3 -> V_9 -> V_14 , V_3 -> V_15 ) ;
F_32 ( & V_21 ) ;
V_4 = F_21 ( F_24 ( V_3 -> V_9 ) ,
V_3 -> V_9 -> V_14 ,
F_71 ( V_3 -> V_15 ) ,
F_72 ( V_3 -> V_15 ) ) ;
if ( ! V_4 || ! V_4 -> V_18 ) {
F_46 ( & V_3 -> V_3 ,
V_30 L_38 ) ;
goto V_70;
}
if ( ! V_4 -> V_18 -> V_61 ) {
F_46 ( & V_3 -> V_3 , V_30 L_39
L_40 ) ;
F_56 ( V_4 ) ;
goto V_71;
}
if ( ! F_67 ( V_72 ,
( unsigned long * ) & V_4 -> V_18 -> V_61 -> V_12 ) ) {
F_2 ( & V_3 -> V_3 , L_46 ) ;
F_56 ( V_4 ) ;
goto V_71;
}
V_56 = F_61 ( V_4 , error , V_77 , V_56 ) ;
if ( V_56 == V_63 ||
V_56 == V_74 ) {
F_2 ( & V_3 -> V_3 ,
L_47 ) ;
F_56 ( V_4 ) ;
}
V_71:
F_19 ( V_4 ) ;
V_70:
F_34 ( & V_21 ) ;
return V_56 ;
}
static void F_75 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_3 -> V_3 , L_48 ,
V_3 -> V_9 -> V_14 , V_3 -> V_15 ) ;
F_32 ( & V_21 ) ;
V_4 = F_21 ( F_24 ( V_3 -> V_9 ) ,
V_3 -> V_9 -> V_14 ,
F_71 ( V_3 -> V_15 ) ,
F_72 ( V_3 -> V_15 ) ) ;
if ( ! V_4 || ! V_4 -> V_18 ) {
F_46 ( & V_3 -> V_3 ,
V_30 L_38 ) ;
goto V_70;
}
if ( ! V_4 -> V_18 -> V_61 ) {
F_46 ( & V_3 -> V_3 , V_30 L_39
L_40 ) ;
F_56 ( V_4 ) ;
goto V_71;
}
if ( ! F_67 ( V_72 ,
( unsigned long * ) & V_4 -> V_18 -> V_61 -> V_12 ) ) {
F_46 ( & V_3 -> V_3 ,
L_41 ) ;
F_56 ( V_4 ) ;
goto V_71;
}
F_61 ( V_4 , 1 , V_78 ,
V_69 ) ;
V_71:
F_19 ( V_4 ) ;
V_70:
F_34 ( & V_21 ) ;
return;
}
static inline int F_76 ( const char * V_79 , int * V_8 , int * V_9 ,
int * V_10 , int * V_11 )
{
int V_29 ;
V_29 = sscanf ( V_79 , L_49 , V_8 , V_9 , V_10 , V_11 ) ;
if ( V_29 == 4 )
return 0 ;
else if ( V_29 < 0 )
return - V_80 ;
* V_8 = 0 ;
V_29 = sscanf ( V_79 , L_50 , V_9 , V_10 , V_11 ) ;
if ( V_29 == 3 )
return 0 ;
return - V_80 ;
}
static inline int F_77 ( const char * V_79 , int * V_8 , int * V_9 , int
* V_10 , int * V_11 , int * V_81 , int * V_82 , int * V_83 )
{
int V_29 ;
V_29 =
sscanf ( V_79 , L_51 , V_8 , V_9 , V_10 ,
V_11 , V_81 , V_82 , V_83 ) ;
if ( V_29 == 7 )
return 0 ;
return - V_80 ;
}
static int F_78 ( int V_8 , int V_9 , int V_10 , int V_11 )
{
struct V_22 * V_84 ;
unsigned long V_12 ;
V_84 = F_79 ( sizeof( * V_84 ) , V_85 ) ;
if ( ! V_84 )
return - V_31 ;
V_84 -> V_8 = V_8 ;
V_84 -> V_9 = V_9 ;
V_84 -> V_15 = F_25 ( V_10 , V_11 ) ;
F_43 ( V_30 L_52 ,
V_8 , V_9 , V_10 , V_11 ) ;
F_22 ( & V_26 , V_12 ) ;
F_47 ( & V_84 -> V_86 , & V_87 ) ;
F_26 ( & V_26 , V_12 ) ;
return 0 ;
}
static int F_80 ( int V_8 , int V_9 , int V_10 , int V_11 )
{
struct V_22 * V_84 , * V_88 ;
int V_15 = F_25 ( V_10 , V_11 ) ;
int V_29 = - V_89 ;
unsigned long V_12 ;
F_22 ( & V_26 , V_12 ) ;
F_81 (pci_dev_id, t, &pcistub_device_ids,
slot_list) {
if ( V_84 -> V_8 == V_8
&& V_84 -> V_9 == V_9 && V_84 -> V_15 == V_15 ) {
F_45 ( & V_84 -> V_86 ) ;
F_5 ( V_84 ) ;
V_29 = 0 ;
F_43 ( V_30 L_53
L_54 , V_8 , V_9 , V_10 , V_11 ) ;
}
}
F_26 ( & V_26 , V_12 ) ;
return V_29 ;
}
static int F_82 ( int V_8 , int V_9 , int V_10 , int V_11 , int V_81 ,
int V_82 , int V_83 )
{
int V_29 = 0 ;
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_90 * V_91 ;
V_4 = F_21 ( V_8 , V_9 , V_10 , V_11 ) ;
if ( ! V_4 || ! V_4 -> V_3 ) {
V_29 = - V_45 ;
goto V_16;
}
V_3 = V_4 -> V_3 ;
V_91 = F_3 ( sizeof( * V_91 ) , V_5 ) ;
if ( ! V_91 ) {
V_29 = - V_31 ;
goto V_16;
}
V_91 -> V_92 = V_81 ;
V_91 -> V_82 = V_82 ;
V_91 -> V_83 = V_83 ;
V_91 -> V_93 = NULL ;
V_91 -> V_94 = NULL ;
V_91 -> V_71 = NULL ;
V_91 -> V_95 = V_96 ;
V_29 = F_83 ( V_3 , V_91 ) ;
if ( V_29 )
F_5 ( V_91 ) ;
V_16:
return V_29 ;
}
static T_5 F_84 ( struct V_97 * V_98 , const char * V_79 ,
T_6 V_99 )
{
int V_8 , V_9 , V_10 , V_11 ;
int V_29 ;
V_29 = F_76 ( V_79 , & V_8 , & V_9 , & V_10 , & V_11 ) ;
if ( V_29 )
goto V_16;
V_29 = F_78 ( V_8 , V_9 , V_10 , V_11 ) ;
V_16:
if ( ! V_29 )
V_29 = V_99 ;
return V_29 ;
}
static T_5 F_85 ( struct V_97 * V_98 , const char * V_79 ,
T_6 V_99 )
{
int V_8 , V_9 , V_10 , V_11 ;
int V_29 ;
V_29 = F_76 ( V_79 , & V_8 , & V_9 , & V_10 , & V_11 ) ;
if ( V_29 )
goto V_16;
V_29 = F_80 ( V_8 , V_9 , V_10 , V_11 ) ;
V_16:
if ( ! V_29 )
V_29 = V_99 ;
return V_29 ;
}
static T_5 F_86 ( struct V_97 * V_98 , char * V_79 )
{
struct V_22 * V_84 ;
T_6 V_99 = 0 ;
unsigned long V_12 ;
F_22 ( & V_26 , V_12 ) ;
F_23 (pci_dev_id, &pcistub_device_ids, slot_list) {
if ( V_99 >= V_100 )
break;
V_99 += F_87 ( V_79 + V_99 , V_100 - V_99 ,
L_55 ,
V_84 -> V_8 , V_84 -> V_9 ,
F_71 ( V_84 -> V_15 ) ,
F_72 ( V_84 -> V_15 ) ) ;
}
F_26 ( & V_26 , V_12 ) ;
return V_99 ;
}
static T_5 F_88 ( struct V_97 * V_98 , char * V_79 )
{
struct V_1 * V_4 ;
struct V_27 * V_28 ;
T_6 V_99 = 0 ;
unsigned long V_12 ;
F_22 ( & V_13 , V_12 ) ;
F_23 (psdev, &pcistub_devices, dev_list) {
if ( V_99 >= V_100 )
break;
if ( ! V_4 -> V_3 )
continue;
V_28 = F_14 ( V_4 -> V_3 ) ;
if ( ! V_28 )
continue;
V_99 +=
F_87 ( V_79 + V_99 , V_100 - V_99 ,
L_56 ,
F_38 ( V_4 -> V_3 ) ,
V_28 -> V_101 ? L_57 : L_58 ,
V_28 -> V_102 ? L_59 : L_60 ,
V_28 -> V_103 ) ;
}
F_26 ( & V_13 , V_12 ) ;
return V_99 ;
}
static T_5 F_89 ( struct V_97 * V_98 ,
const char * V_79 ,
T_6 V_99 )
{
struct V_1 * V_4 ;
struct V_27 * V_28 ;
int V_8 , V_9 , V_10 , V_11 ;
int V_29 = - V_89 ;
V_29 = F_76 ( V_79 , & V_8 , & V_9 , & V_10 , & V_11 ) ;
if ( V_29 )
goto V_16;
V_4 = F_21 ( V_8 , V_9 , V_10 , V_11 ) ;
if ( ! V_4 )
goto V_16;
V_28 = F_14 ( V_4 -> V_3 ) ;
if ( ! V_28 )
goto V_16;
F_2 ( & V_4 -> V_3 -> V_3 , L_61 ,
V_28 -> V_32 , V_28 -> V_101 ,
! V_28 -> V_101 ) ;
V_28 -> V_101 = ! ( V_28 -> V_101 ) ;
if ( V_28 -> V_101 )
V_28 -> V_102 = 1 ;
V_16:
if ( ! V_29 )
V_29 = V_99 ;
return V_29 ;
}
static T_5 F_90 ( struct V_97 * V_98 , const char * V_79 ,
T_6 V_99 )
{
int V_8 , V_9 , V_10 , V_11 , V_81 , V_82 , V_83 ;
int V_29 ;
V_29 = F_77 ( V_79 , & V_8 , & V_9 , & V_10 , & V_11 , & V_81 , & V_82 ,
& V_83 ) ;
if ( V_29 )
goto V_16;
V_29 = F_82 ( V_8 , V_9 , V_10 , V_11 , V_81 , V_82 , V_83 ) ;
V_16:
if ( ! V_29 )
V_29 = V_99 ;
return V_29 ;
}
static T_5 F_91 ( struct V_97 * V_98 , char * V_79 )
{
int V_99 = 0 ;
unsigned long V_12 ;
struct V_104 * V_105 ;
struct V_27 * V_28 ;
const struct V_90 * V_91 ;
const struct V_106 * V_107 ;
F_22 ( & V_26 , V_12 ) ;
F_23 (quirk, &xen_pcibk_quirks, quirks_list) {
if ( V_99 >= V_100 )
goto V_16;
V_99 += F_87 ( V_79 + V_99 , V_100 - V_99 ,
L_62 ,
V_105 -> V_18 -> V_9 -> V_14 ,
F_71 ( V_105 -> V_18 -> V_15 ) ,
F_72 ( V_105 -> V_18 -> V_15 ) ,
V_105 -> V_108 . V_109 , V_105 -> V_108 . V_110 ,
V_105 -> V_108 . V_111 ,
V_105 -> V_108 . V_112 ) ;
V_28 = F_14 ( V_105 -> V_18 ) ;
F_23 (cfg_entry, &dev_data->config_fields, list) {
V_91 = V_107 -> V_91 ;
if ( V_99 >= V_100 )
goto V_16;
V_99 += F_87 ( V_79 + V_99 , V_100 - V_99 ,
L_63 ,
V_107 -> V_113 +
V_91 -> V_92 , V_91 -> V_82 ,
V_91 -> V_83 ) ;
}
}
V_16:
F_26 ( & V_26 , V_12 ) ;
return V_99 ;
}
static T_5 F_92 ( struct V_97 * V_98 , const char * V_79 ,
T_6 V_99 )
{
int V_8 , V_9 , V_10 , V_11 ;
int V_29 ;
struct V_1 * V_4 ;
struct V_27 * V_28 ;
V_29 = F_76 ( V_79 , & V_8 , & V_9 , & V_10 , & V_11 ) ;
if ( V_29 )
goto V_16;
V_4 = F_21 ( V_8 , V_9 , V_10 , V_11 ) ;
if ( ! V_4 ) {
V_29 = - V_45 ;
goto V_16;
}
if ( ! V_4 -> V_3 ) {
V_29 = - V_45 ;
goto V_71;
}
V_28 = F_14 ( V_4 -> V_3 ) ;
if ( ! V_28 ) {
V_29 = - V_114 ;
goto V_71;
}
if ( ! V_28 -> V_115 ) {
V_28 -> V_115 = 1 ;
F_93 ( & V_4 -> V_3 -> V_3 , L_64
L_65 ) ;
F_93 ( & V_4 -> V_3 -> V_3 ,
L_66 ) ;
}
V_71:
F_19 ( V_4 ) ;
V_16:
if ( ! V_29 )
V_29 = V_99 ;
return V_29 ;
}
static T_5 F_94 ( struct V_97 * V_98 , char * V_79 )
{
struct V_1 * V_4 ;
struct V_27 * V_28 ;
T_6 V_99 = 0 ;
unsigned long V_12 ;
F_22 ( & V_13 , V_12 ) ;
F_23 (psdev, &pcistub_devices, dev_list) {
if ( V_99 >= V_100 )
break;
if ( ! V_4 -> V_3 )
continue;
V_28 = F_14 ( V_4 -> V_3 ) ;
if ( ! V_28 || ! V_28 -> V_115 )
continue;
V_99 +=
F_87 ( V_79 + V_99 , V_100 - V_99 , L_67 ,
F_38 ( V_4 -> V_3 ) ) ;
}
F_26 ( & V_13 , V_12 ) ;
return V_99 ;
}
static void F_95 ( void )
{
F_96 ( & V_116 . V_117 , & V_118 ) ;
F_96 ( & V_116 . V_117 ,
& V_119 ) ;
F_96 ( & V_116 . V_117 , & V_120 ) ;
F_96 ( & V_116 . V_117 , & V_121 ) ;
F_96 ( & V_116 . V_117 ,
& V_122 ) ;
F_96 ( & V_116 . V_117 ,
& V_123 ) ;
F_96 ( & V_116 . V_117 ,
& V_124 ) ;
F_97 ( & V_116 ) ;
}
static int T_2 F_98 ( void )
{
int V_125 = 0 ;
int V_29 = 0 ;
int V_8 , V_9 , V_10 , V_11 ;
int V_126 ;
if ( V_127 && * V_127 ) {
do {
V_126 = 0 ;
V_29 = sscanf ( V_127 + V_125 ,
L_68 ,
& V_8 , & V_9 , & V_10 , & V_11 , & V_126 ) ;
if ( V_29 != 4 ) {
V_8 = 0 ;
V_29 = sscanf ( V_127 + V_125 ,
L_69 ,
& V_9 , & V_10 , & V_11 , & V_126 ) ;
if ( V_29 != 3 )
goto V_128;
}
V_29 = F_78 ( V_8 , V_9 , V_10 , V_11 ) ;
if ( V_29 )
goto V_16;
V_125 += V_126 ;
} while ( V_126 > 0 && V_127 [ V_125 ] );
}
V_29 = F_99 ( & V_116 ) ;
if ( V_29 < 0 )
goto V_16;
V_29 = F_100 ( & V_116 . V_117 ,
& V_118 ) ;
if ( ! V_29 )
V_29 = F_100 ( & V_116 . V_117 ,
& V_119 ) ;
if ( ! V_29 )
V_29 = F_100 ( & V_116 . V_117 ,
& V_120 ) ;
if ( ! V_29 )
V_29 = F_100 ( & V_116 . V_117 ,
& V_121 ) ;
if ( ! V_29 )
V_29 = F_100 ( & V_116 . V_117 ,
& V_122 ) ;
if ( ! V_29 )
V_29 = F_100 ( & V_116 . V_117 ,
& V_123 ) ;
if ( ! V_29 )
V_29 = F_100 ( & V_116 . V_117 ,
& V_124 ) ;
if ( V_29 )
F_95 () ;
V_16:
return V_29 ;
V_128:
F_54 (KERN_ERR DRV_NAME L_70 ,
pci_devs_to_hide + pos) ;
return - V_80 ;
}
static int T_2 F_101 ( void )
{
int V_29 ;
if ( ! F_102 () )
return - V_45 ;
V_29 = F_103 () ;
if ( V_29 )
return V_29 ;
#ifdef F_104
V_29 = F_98 () ;
if ( V_29 < 0 )
return V_29 ;
#endif
F_42 () ;
V_29 = F_105 () ;
if ( V_29 )
F_95 () ;
return V_29 ;
}
static void T_7 F_106 ( void )
{
F_107 () ;
F_95 () ;
}
