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
V_4 -> V_3 -> V_8 &= ~ V_9 ;
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
static struct V_1 * F_21 ( int V_10 , int V_11 ,
int V_12 , int V_13 )
{
struct V_1 * V_4 = NULL ;
unsigned long V_14 ;
F_22 ( & V_15 , V_14 ) ;
F_23 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 != NULL
&& V_10 == F_24 ( V_4 -> V_3 -> V_11 )
&& V_11 == V_4 -> V_3 -> V_11 -> V_16
&& F_25 ( V_12 , V_13 ) == V_4 -> V_3 -> V_17 ) {
F_17 ( V_4 ) ;
goto V_18;
}
}
V_4 = NULL ;
V_18:
F_26 ( & V_15 , V_14 ) ;
return V_4 ;
}
static struct V_2 * F_27 ( struct V_19 * V_20 ,
struct V_1 * V_4 )
{
struct V_2 * V_2 = NULL ;
unsigned long V_14 ;
F_17 ( V_4 ) ;
F_22 ( & V_4 -> V_7 , V_14 ) ;
if ( ! V_4 -> V_20 ) {
V_4 -> V_20 = V_20 ;
V_2 = V_4 -> V_3 ;
}
F_26 ( & V_4 -> V_7 , V_14 ) ;
if ( ! V_2 )
F_19 ( V_4 ) ;
return V_2 ;
}
struct V_2 * F_28 ( struct V_19 * V_20 ,
int V_10 , int V_11 ,
int V_12 , int V_13 )
{
struct V_1 * V_4 ;
struct V_2 * V_21 = NULL ;
unsigned long V_14 ;
F_22 ( & V_15 , V_14 ) ;
F_23 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 != NULL
&& V_10 == F_24 ( V_4 -> V_3 -> V_11 )
&& V_11 == V_4 -> V_3 -> V_11 -> V_16
&& F_25 ( V_12 , V_13 ) == V_4 -> V_3 -> V_17 ) {
V_21 = F_27 ( V_20 , V_4 ) ;
break;
}
}
F_26 ( & V_15 , V_14 ) ;
return V_21 ;
}
struct V_2 * F_29 ( struct V_19 * V_20 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_2 * V_21 = NULL ;
unsigned long V_14 ;
F_22 ( & V_15 , V_14 ) ;
F_23 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_21 = F_27 ( V_20 , V_4 ) ;
break;
}
}
F_26 ( & V_15 , V_14 ) ;
return V_21 ;
}
void F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_22 = NULL ;
unsigned long V_14 ;
F_22 ( & V_15 , V_14 ) ;
F_23 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_22 = V_4 ;
break;
}
}
F_26 ( & V_15 , V_14 ) ;
if ( F_31 ( ! V_22 ) )
return;
F_32 ( & V_23 ) ;
F_11 ( V_22 -> V_3 ) ;
F_12 ( V_22 -> V_3 ) ;
F_33 ( V_22 -> V_3 ) ;
F_10 ( V_22 -> V_3 ) ;
F_22 ( & V_22 -> V_7 , V_14 ) ;
V_22 -> V_20 = NULL ;
F_26 ( & V_22 -> V_7 , V_14 ) ;
F_19 ( V_22 ) ;
F_34 ( & V_23 ) ;
}
static int T_1 F_35 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
for (; V_3 != NULL ; V_3 = V_3 -> V_11 -> V_26 ) {
if ( F_24 ( V_3 -> V_11 ) == V_25 -> V_10
&& V_3 -> V_11 -> V_16 == V_25 -> V_11
&& V_3 -> V_17 == V_25 -> V_17 )
return 1 ;
if ( V_3 == V_3 -> V_11 -> V_26 )
break;
}
return 0 ;
}
static int T_1 F_36 ( struct V_2 * V_3 )
{
struct V_24 * V_25 ;
unsigned long V_14 ;
int V_27 = 0 ;
F_22 ( & V_28 , V_14 ) ;
F_23 (pdev_id, &pcistub_device_ids, slot_list) {
if ( F_35 ( V_3 , V_25 ) ) {
V_27 = 1 ;
break;
}
}
F_26 ( & V_28 , V_14 ) ;
return V_27 ;
}
static int T_1 F_37 ( struct V_2 * V_3 )
{
struct V_29 * V_30 ;
int V_31 = 0 ;
F_2 ( & V_3 -> V_3 , L_3 ) ;
V_30 = F_3 ( sizeof( * V_30 ) + strlen ( V_32 L_4 )
+ strlen ( F_38 ( V_3 ) ) + 1 , V_5 ) ;
if ( ! V_30 ) {
V_31 = - V_33 ;
goto V_18;
}
F_15 ( V_3 , V_30 ) ;
sprintf ( V_30 -> V_34 , V_32 L_5 , F_38 ( V_3 ) ) ;
F_2 ( & V_3 -> V_3 , L_6 ) ;
F_39 ( & V_35 ) ;
V_31 = F_40 ( V_3 ) ;
if ( V_31 )
goto V_18;
F_2 ( & V_3 -> V_3 , L_7 ) ;
V_31 = F_41 ( V_3 ) ;
if ( V_31 )
goto V_36;
F_2 ( & V_3 -> V_3 , L_8 ) ;
F_11 ( V_3 ) ;
V_3 -> V_8 |= V_9 ;
return 0 ;
V_36:
F_13 ( V_3 ) ;
V_18:
F_15 ( V_3 , NULL ) ;
F_5 ( V_30 ) ;
return V_31 ;
}
static int T_2 F_42 ( void )
{
struct V_1 * V_4 ;
unsigned long V_14 ;
int V_31 = 0 ;
F_43 ( V_32 L_9 ) ;
F_22 ( & V_15 , V_14 ) ;
while ( ! F_44 ( & V_37 ) ) {
V_4 = F_9 ( V_37 . V_38 ,
struct V_1 , V_39 ) ;
F_45 ( & V_4 -> V_39 ) ;
F_26 ( & V_15 , V_14 ) ;
V_31 = F_37 ( V_4 -> V_3 ) ;
if ( V_31 ) {
F_46 ( & V_4 -> V_3 -> V_3 ,
L_10 , V_31 ) ;
F_5 ( V_4 ) ;
V_4 = NULL ;
}
F_22 ( & V_15 , V_14 ) ;
if ( V_4 )
F_47 ( & V_4 -> V_39 , & V_40 ) ;
}
V_41 = 1 ;
F_26 ( & V_15 , V_14 ) ;
return 0 ;
}
static int T_1 F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_14 ;
int V_31 = 0 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_33 ;
F_22 ( & V_15 , V_14 ) ;
if ( V_41 ) {
F_26 ( & V_15 , V_14 ) ;
V_31 = F_37 ( V_4 -> V_3 ) ;
F_22 ( & V_15 , V_14 ) ;
if ( ! V_31 )
F_49 ( & V_4 -> V_39 , & V_40 ) ;
} else {
F_2 ( & V_3 -> V_3 , L_11 ) ;
F_49 ( & V_4 -> V_39 , & V_37 ) ;
}
F_26 ( & V_15 , V_14 ) ;
if ( V_31 )
F_19 ( V_4 ) ;
return V_31 ;
}
static int T_1 F_50 ( struct V_2 * V_3 ,
const struct V_42 * V_43 )
{
int V_31 = 0 ;
F_2 ( & V_3 -> V_3 , L_12 ) ;
if ( F_36 ( V_3 ) ) {
if ( V_3 -> V_44 != V_45
&& V_3 -> V_44 != V_46 ) {
F_46 ( & V_3 -> V_3 , L_13
L_14
L_15 ) ;
V_31 = - V_47 ;
goto V_18;
}
F_51 ( & V_3 -> V_3 , L_16 ) ;
V_31 = F_48 ( V_3 ) ;
} else
V_31 = - V_47 ;
V_18:
return V_31 ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_22 = NULL ;
unsigned long V_14 ;
F_2 ( & V_3 -> V_3 , L_17 ) ;
F_22 ( & V_15 , V_14 ) ;
F_53 ( V_3 ) ;
F_23 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_22 = V_4 ;
break;
}
}
F_26 ( & V_15 , V_14 ) ;
if ( V_22 ) {
F_2 ( & V_3 -> V_3 , L_18 ,
V_22 -> V_20 ) ;
if ( V_22 -> V_20 ) {
F_54 (KERN_WARNING DRV_NAME L_19
L_20 ,
pci_name(found_psdev->dev)) ;
F_54 (KERN_WARNING DRV_NAME L_21
L_22 ) ;
F_54 (KERN_WARNING DRV_NAME L_23
L_24 ) ;
F_54 (KERN_WARNING DRV_NAME L_25
L_26 ) ;
F_55 ( V_22 -> V_20 ,
V_22 -> V_3 ) ;
}
F_22 ( & V_15 , V_14 ) ;
F_45 ( & V_22 -> V_39 ) ;
F_26 ( & V_15 , V_14 ) ;
F_19 ( V_22 ) ;
}
}
static void F_56 ( struct V_1 * V_4 )
{
struct V_48 V_49 ;
int V_31 ;
char V_50 [ V_51 ] ;
F_57 ( ! V_4 ) ;
snprintf ( V_50 , V_51 , L_27 ,
V_4 -> V_20 -> V_52 -> V_53 ) ;
V_54:
V_31 = F_58 ( & V_49 ) ;
if ( V_31 ) {
F_46 ( & V_4 -> V_3 -> V_3 ,
L_28 , V_31 ) ;
return;
}
F_59 ( V_49 , V_50 , L_29 , L_30 ) ;
V_31 = F_60 ( V_49 , 0 ) ;
if ( V_31 ) {
if ( V_31 == - V_55 )
goto V_54;
F_46 ( & V_4 -> V_3 -> V_3 ,
L_31 , V_31 ) ;
return;
}
}
static T_3 F_61 ( struct V_1 * V_4 ,
T_4 V_56 , int V_57 ,
T_3 V_58 )
{
T_3 V_59 = V_58 ;
struct V_60 * V_61 ;
int V_62 ;
V_61 = & ( V_4 -> V_20 -> V_63 -> V_61 ) ;
V_61 -> V_64 = V_57 ;
V_61 -> V_31 = V_56 ;
V_62 = F_62 ( V_4 -> V_3 , V_4 -> V_20 ,
& V_61 -> V_10 , & V_61 -> V_11 , & V_61 -> V_17 ) ;
if ( ! V_62 ) {
F_46 ( & V_4 -> V_3 -> V_3 ,
V_32 L_32 ) ;
return V_65 ;
}
F_63 () ;
F_2 ( & V_4 -> V_3 -> V_3 ,
V_32 L_33 ,
V_57 , V_61 -> V_10 , V_61 -> V_11 , V_61 -> V_17 ) ;
F_64 ( V_66 , ( unsigned long * ) & V_4 -> V_20 -> V_14 ) ;
F_64 ( V_67 ,
( unsigned long * ) & V_4 -> V_20 -> V_63 -> V_14 ) ;
F_63 () ;
F_65 ( V_4 -> V_20 -> V_68 ) ;
V_62 = F_66 ( V_35 ,
! ( F_67 ( V_67 , ( unsigned long * )
& V_4 -> V_20 -> V_63 -> V_14 ) ) , 300 * V_69 ) ;
if ( ! V_62 ) {
if ( F_67 ( V_67 ,
( unsigned long * ) & V_4 -> V_20 -> V_63 -> V_14 ) ) {
F_46 ( & V_4 -> V_3 -> V_3 ,
L_34 ) ;
F_68 ( V_67 ,
( unsigned long * ) & V_4 -> V_20 -> V_63 -> V_14 ) ;
V_61 -> V_31 = V_65 ;
return V_59 ;
}
}
F_68 ( V_66 , ( unsigned long * ) & V_4 -> V_20 -> V_14 ) ;
if ( F_67 ( V_70 ,
( unsigned long * ) & V_4 -> V_20 -> V_63 -> V_14 ) ) {
F_2 ( & V_4 -> V_3 -> V_3 ,
L_35 V_32 L_36 ) ;
F_69 ( V_4 -> V_20 ) ;
}
V_59 = ( T_3 ) V_61 -> V_31 ;
return V_59 ;
}
static T_3 F_70 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
T_3 V_58 ;
V_58 = V_71 ;
F_2 ( & V_3 -> V_3 , L_37 ,
V_3 -> V_11 -> V_16 , V_3 -> V_17 ) ;
F_32 ( & V_23 ) ;
V_4 = F_21 ( F_24 ( V_3 -> V_11 ) ,
V_3 -> V_11 -> V_16 ,
F_71 ( V_3 -> V_17 ) ,
F_72 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_20 ) {
F_46 ( & V_3 -> V_3 ,
V_32 L_38 ) ;
goto V_72;
}
if ( ! V_4 -> V_20 -> V_63 ) {
F_46 ( & V_3 -> V_3 , V_32 L_39
L_40 ) ;
F_56 ( V_4 ) ;
goto V_73;
}
if ( ! F_67 ( V_74 ,
( unsigned long * ) & V_4 -> V_20 -> V_63 -> V_14 ) ) {
F_46 ( & V_3 -> V_3 ,
L_41 ) ;
goto V_73;
}
V_58 = F_61 ( V_4 , 1 , V_75 , V_58 ) ;
if ( V_58 == V_65 ||
V_58 == V_76 ) {
F_2 ( & V_3 -> V_3 ,
L_42 ) ;
F_56 ( V_4 ) ;
}
V_73:
F_19 ( V_4 ) ;
V_72:
F_34 ( & V_23 ) ;
return V_58 ;
}
static T_3 F_73 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
T_3 V_58 ;
V_58 = V_71 ;
F_2 ( & V_3 -> V_3 , L_43 ,
V_3 -> V_11 -> V_16 , V_3 -> V_17 ) ;
F_32 ( & V_23 ) ;
V_4 = F_21 ( F_24 ( V_3 -> V_11 ) ,
V_3 -> V_11 -> V_16 ,
F_71 ( V_3 -> V_17 ) ,
F_72 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_20 ) {
F_46 ( & V_3 -> V_3 ,
V_32 L_38 ) ;
goto V_72;
}
if ( ! V_4 -> V_20 -> V_63 ) {
F_46 ( & V_3 -> V_3 , V_32 L_39
L_40 ) ;
F_56 ( V_4 ) ;
goto V_73;
}
if ( ! F_67 ( V_74 ,
( unsigned long * ) & V_4 -> V_20 -> V_63 -> V_14 ) ) {
F_46 ( & V_3 -> V_3 ,
L_41 ) ;
goto V_73;
}
V_58 = F_61 ( V_4 , 1 , V_77 , V_58 ) ;
if ( V_58 == V_65 ||
V_58 == V_76 ) {
F_2 ( & V_3 -> V_3 ,
L_44 ) ;
F_56 ( V_4 ) ;
}
V_73:
F_19 ( V_4 ) ;
V_72:
F_34 ( & V_23 ) ;
return V_58 ;
}
static T_3 F_74 ( struct V_2 * V_3 ,
T_4 error )
{
struct V_1 * V_4 ;
T_3 V_58 ;
V_58 = V_78 ;
F_2 ( & V_3 -> V_3 , L_45 ,
V_3 -> V_11 -> V_16 , V_3 -> V_17 ) ;
F_32 ( & V_23 ) ;
V_4 = F_21 ( F_24 ( V_3 -> V_11 ) ,
V_3 -> V_11 -> V_16 ,
F_71 ( V_3 -> V_17 ) ,
F_72 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_20 ) {
F_46 ( & V_3 -> V_3 ,
V_32 L_38 ) ;
goto V_72;
}
if ( ! V_4 -> V_20 -> V_63 ) {
F_46 ( & V_3 -> V_3 , V_32 L_39
L_40 ) ;
F_56 ( V_4 ) ;
goto V_73;
}
if ( ! F_67 ( V_74 ,
( unsigned long * ) & V_4 -> V_20 -> V_63 -> V_14 ) ) {
F_2 ( & V_3 -> V_3 , L_46 ) ;
F_56 ( V_4 ) ;
goto V_73;
}
V_58 = F_61 ( V_4 , error , V_79 , V_58 ) ;
if ( V_58 == V_65 ||
V_58 == V_76 ) {
F_2 ( & V_3 -> V_3 ,
L_47 ) ;
F_56 ( V_4 ) ;
}
V_73:
F_19 ( V_4 ) ;
V_72:
F_34 ( & V_23 ) ;
return V_58 ;
}
static void F_75 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_3 -> V_3 , L_48 ,
V_3 -> V_11 -> V_16 , V_3 -> V_17 ) ;
F_32 ( & V_23 ) ;
V_4 = F_21 ( F_24 ( V_3 -> V_11 ) ,
V_3 -> V_11 -> V_16 ,
F_71 ( V_3 -> V_17 ) ,
F_72 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_20 ) {
F_46 ( & V_3 -> V_3 ,
V_32 L_38 ) ;
goto V_72;
}
if ( ! V_4 -> V_20 -> V_63 ) {
F_46 ( & V_3 -> V_3 , V_32 L_39
L_40 ) ;
F_56 ( V_4 ) ;
goto V_73;
}
if ( ! F_67 ( V_74 ,
( unsigned long * ) & V_4 -> V_20 -> V_63 -> V_14 ) ) {
F_46 ( & V_3 -> V_3 ,
L_41 ) ;
F_56 ( V_4 ) ;
goto V_73;
}
F_61 ( V_4 , 1 , V_80 ,
V_71 ) ;
V_73:
F_19 ( V_4 ) ;
V_72:
F_34 ( & V_23 ) ;
return;
}
static inline int F_76 ( const char * V_81 , int * V_10 , int * V_11 ,
int * V_12 , int * V_13 )
{
int V_31 ;
V_31 = sscanf ( V_81 , L_49 , V_10 , V_11 , V_12 , V_13 ) ;
if ( V_31 == 4 )
return 0 ;
else if ( V_31 < 0 )
return - V_82 ;
* V_10 = 0 ;
V_31 = sscanf ( V_81 , L_50 , V_11 , V_12 , V_13 ) ;
if ( V_31 == 3 )
return 0 ;
return - V_82 ;
}
static inline int F_77 ( const char * V_81 , int * V_10 , int * V_11 , int
* V_12 , int * V_13 , int * V_83 , int * V_84 , int * V_85 )
{
int V_31 ;
V_31 =
sscanf ( V_81 , L_51 , V_10 , V_11 , V_12 ,
V_13 , V_83 , V_84 , V_85 ) ;
if ( V_31 == 7 )
return 0 ;
return - V_82 ;
}
static int F_78 ( int V_10 , int V_11 , int V_12 , int V_13 )
{
struct V_24 * V_86 ;
unsigned long V_14 ;
V_86 = F_79 ( sizeof( * V_86 ) , V_87 ) ;
if ( ! V_86 )
return - V_33 ;
V_86 -> V_10 = V_10 ;
V_86 -> V_11 = V_11 ;
V_86 -> V_17 = F_25 ( V_12 , V_13 ) ;
F_43 ( V_32 L_52 ,
V_10 , V_11 , V_12 , V_13 ) ;
F_22 ( & V_28 , V_14 ) ;
F_47 ( & V_86 -> V_88 , & V_89 ) ;
F_26 ( & V_28 , V_14 ) ;
return 0 ;
}
static int F_80 ( int V_10 , int V_11 , int V_12 , int V_13 )
{
struct V_24 * V_86 , * V_90 ;
int V_17 = F_25 ( V_12 , V_13 ) ;
int V_31 = - V_91 ;
unsigned long V_14 ;
F_22 ( & V_28 , V_14 ) ;
F_81 (pci_dev_id, t, &pcistub_device_ids,
slot_list) {
if ( V_86 -> V_10 == V_10
&& V_86 -> V_11 == V_11 && V_86 -> V_17 == V_17 ) {
F_45 ( & V_86 -> V_88 ) ;
F_5 ( V_86 ) ;
V_31 = 0 ;
F_43 ( V_32 L_53
L_54 , V_10 , V_11 , V_12 , V_13 ) ;
}
}
F_26 ( & V_28 , V_14 ) ;
return V_31 ;
}
static int F_82 ( int V_10 , int V_11 , int V_12 , int V_13 , int V_83 ,
int V_84 , int V_85 )
{
int V_31 = 0 ;
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_92 * V_93 ;
V_4 = F_21 ( V_10 , V_11 , V_12 , V_13 ) ;
if ( ! V_4 || ! V_4 -> V_3 ) {
V_31 = - V_47 ;
goto V_18;
}
V_3 = V_4 -> V_3 ;
V_93 = F_3 ( sizeof( * V_93 ) , V_5 ) ;
if ( ! V_93 ) {
V_31 = - V_33 ;
goto V_18;
}
V_93 -> V_94 = V_83 ;
V_93 -> V_84 = V_84 ;
V_93 -> V_85 = V_85 ;
V_93 -> V_95 = NULL ;
V_93 -> V_96 = NULL ;
V_93 -> V_73 = NULL ;
V_93 -> V_97 = V_98 ;
V_31 = F_83 ( V_3 , V_93 ) ;
if ( V_31 )
F_5 ( V_93 ) ;
V_18:
return V_31 ;
}
static T_5 F_84 ( struct V_99 * V_100 , const char * V_81 ,
T_6 V_101 )
{
int V_10 , V_11 , V_12 , V_13 ;
int V_31 ;
V_31 = F_76 ( V_81 , & V_10 , & V_11 , & V_12 , & V_13 ) ;
if ( V_31 )
goto V_18;
V_31 = F_78 ( V_10 , V_11 , V_12 , V_13 ) ;
V_18:
if ( ! V_31 )
V_31 = V_101 ;
return V_31 ;
}
static T_5 F_85 ( struct V_99 * V_100 , const char * V_81 ,
T_6 V_101 )
{
int V_10 , V_11 , V_12 , V_13 ;
int V_31 ;
V_31 = F_76 ( V_81 , & V_10 , & V_11 , & V_12 , & V_13 ) ;
if ( V_31 )
goto V_18;
V_31 = F_80 ( V_10 , V_11 , V_12 , V_13 ) ;
V_18:
if ( ! V_31 )
V_31 = V_101 ;
return V_31 ;
}
static T_5 F_86 ( struct V_99 * V_100 , char * V_81 )
{
struct V_24 * V_86 ;
T_6 V_101 = 0 ;
unsigned long V_14 ;
F_22 ( & V_28 , V_14 ) ;
F_23 (pci_dev_id, &pcistub_device_ids, slot_list) {
if ( V_101 >= V_102 )
break;
V_101 += F_87 ( V_81 + V_101 , V_102 - V_101 ,
L_55 ,
V_86 -> V_10 , V_86 -> V_11 ,
F_71 ( V_86 -> V_17 ) ,
F_72 ( V_86 -> V_17 ) ) ;
}
F_26 ( & V_28 , V_14 ) ;
return V_101 ;
}
static T_5 F_88 ( struct V_99 * V_100 , char * V_81 )
{
struct V_1 * V_4 ;
struct V_29 * V_30 ;
T_6 V_101 = 0 ;
unsigned long V_14 ;
F_22 ( & V_15 , V_14 ) ;
F_23 (psdev, &pcistub_devices, dev_list) {
if ( V_101 >= V_102 )
break;
if ( ! V_4 -> V_3 )
continue;
V_30 = F_14 ( V_4 -> V_3 ) ;
if ( ! V_30 )
continue;
V_101 +=
F_87 ( V_81 + V_101 , V_102 - V_101 ,
L_56 ,
F_38 ( V_4 -> V_3 ) ,
V_30 -> V_103 ? L_57 : L_58 ,
V_30 -> V_104 ? L_59 : L_60 ,
V_30 -> V_105 ) ;
}
F_26 ( & V_15 , V_14 ) ;
return V_101 ;
}
static T_5 F_89 ( struct V_99 * V_100 ,
const char * V_81 ,
T_6 V_101 )
{
struct V_1 * V_4 ;
struct V_29 * V_30 ;
int V_10 , V_11 , V_12 , V_13 ;
int V_31 = - V_91 ;
V_31 = F_76 ( V_81 , & V_10 , & V_11 , & V_12 , & V_13 ) ;
if ( V_31 )
goto V_18;
V_4 = F_21 ( V_10 , V_11 , V_12 , V_13 ) ;
if ( ! V_4 )
goto V_18;
V_30 = F_14 ( V_4 -> V_3 ) ;
if ( ! V_30 )
goto V_18;
F_2 ( & V_4 -> V_3 -> V_3 , L_61 ,
V_30 -> V_34 , V_30 -> V_103 ,
! V_30 -> V_103 ) ;
V_30 -> V_103 = ! ( V_30 -> V_103 ) ;
if ( V_30 -> V_103 )
V_30 -> V_104 = 1 ;
V_18:
if ( ! V_31 )
V_31 = V_101 ;
return V_31 ;
}
static T_5 F_90 ( struct V_99 * V_100 , const char * V_81 ,
T_6 V_101 )
{
int V_10 , V_11 , V_12 , V_13 , V_83 , V_84 , V_85 ;
int V_31 ;
V_31 = F_77 ( V_81 , & V_10 , & V_11 , & V_12 , & V_13 , & V_83 , & V_84 ,
& V_85 ) ;
if ( V_31 )
goto V_18;
V_31 = F_82 ( V_10 , V_11 , V_12 , V_13 , V_83 , V_84 , V_85 ) ;
V_18:
if ( ! V_31 )
V_31 = V_101 ;
return V_31 ;
}
static T_5 F_91 ( struct V_99 * V_100 , char * V_81 )
{
int V_101 = 0 ;
unsigned long V_14 ;
struct V_106 * V_107 ;
struct V_29 * V_30 ;
const struct V_92 * V_93 ;
const struct V_108 * V_109 ;
F_22 ( & V_28 , V_14 ) ;
F_23 (quirk, &xen_pcibk_quirks, quirks_list) {
if ( V_101 >= V_102 )
goto V_18;
V_101 += F_87 ( V_81 + V_101 , V_102 - V_101 ,
L_62 ,
V_107 -> V_20 -> V_11 -> V_16 ,
F_71 ( V_107 -> V_20 -> V_17 ) ,
F_72 ( V_107 -> V_20 -> V_17 ) ,
V_107 -> V_110 . V_111 , V_107 -> V_110 . V_112 ,
V_107 -> V_110 . V_113 ,
V_107 -> V_110 . V_114 ) ;
V_30 = F_14 ( V_107 -> V_20 ) ;
F_23 (cfg_entry, &dev_data->config_fields, list) {
V_93 = V_109 -> V_93 ;
if ( V_101 >= V_102 )
goto V_18;
V_101 += F_87 ( V_81 + V_101 , V_102 - V_101 ,
L_63 ,
V_109 -> V_115 +
V_93 -> V_94 , V_93 -> V_84 ,
V_93 -> V_85 ) ;
}
}
V_18:
F_26 ( & V_28 , V_14 ) ;
return V_101 ;
}
static T_5 F_92 ( struct V_99 * V_100 , const char * V_81 ,
T_6 V_101 )
{
int V_10 , V_11 , V_12 , V_13 ;
int V_31 ;
struct V_1 * V_4 ;
struct V_29 * V_30 ;
V_31 = F_76 ( V_81 , & V_10 , & V_11 , & V_12 , & V_13 ) ;
if ( V_31 )
goto V_18;
V_4 = F_21 ( V_10 , V_11 , V_12 , V_13 ) ;
if ( ! V_4 ) {
V_31 = - V_47 ;
goto V_18;
}
if ( ! V_4 -> V_3 ) {
V_31 = - V_47 ;
goto V_73;
}
V_30 = F_14 ( V_4 -> V_3 ) ;
if ( ! V_30 ) {
V_31 = - V_116 ;
goto V_73;
}
if ( ! V_30 -> V_117 ) {
V_30 -> V_117 = 1 ;
F_93 ( & V_4 -> V_3 -> V_3 , L_64
L_65 ) ;
F_93 ( & V_4 -> V_3 -> V_3 ,
L_66 ) ;
}
V_73:
F_19 ( V_4 ) ;
V_18:
if ( ! V_31 )
V_31 = V_101 ;
return V_31 ;
}
static T_5 F_94 ( struct V_99 * V_100 , char * V_81 )
{
struct V_1 * V_4 ;
struct V_29 * V_30 ;
T_6 V_101 = 0 ;
unsigned long V_14 ;
F_22 ( & V_15 , V_14 ) ;
F_23 (psdev, &pcistub_devices, dev_list) {
if ( V_101 >= V_102 )
break;
if ( ! V_4 -> V_3 )
continue;
V_30 = F_14 ( V_4 -> V_3 ) ;
if ( ! V_30 || ! V_30 -> V_117 )
continue;
V_101 +=
F_87 ( V_81 + V_101 , V_102 - V_101 , L_67 ,
F_38 ( V_4 -> V_3 ) ) ;
}
F_26 ( & V_15 , V_14 ) ;
return V_101 ;
}
static void F_95 ( void )
{
F_96 ( & V_118 . V_119 , & V_120 ) ;
F_96 ( & V_118 . V_119 ,
& V_121 ) ;
F_96 ( & V_118 . V_119 , & V_122 ) ;
F_96 ( & V_118 . V_119 , & V_123 ) ;
F_96 ( & V_118 . V_119 ,
& V_124 ) ;
F_96 ( & V_118 . V_119 ,
& V_125 ) ;
F_96 ( & V_118 . V_119 ,
& V_126 ) ;
F_97 ( & V_118 ) ;
}
static int T_2 F_98 ( void )
{
int V_127 = 0 ;
int V_31 = 0 ;
int V_10 , V_11 , V_12 , V_13 ;
int V_128 ;
if ( V_129 && * V_129 ) {
do {
V_128 = 0 ;
V_31 = sscanf ( V_129 + V_127 ,
L_68 ,
& V_10 , & V_11 , & V_12 , & V_13 , & V_128 ) ;
if ( V_31 != 4 ) {
V_10 = 0 ;
V_31 = sscanf ( V_129 + V_127 ,
L_69 ,
& V_11 , & V_12 , & V_13 , & V_128 ) ;
if ( V_31 != 3 )
goto V_130;
}
V_31 = F_78 ( V_10 , V_11 , V_12 , V_13 ) ;
if ( V_31 )
goto V_18;
V_127 += V_128 ;
} while ( V_128 > 0 && V_129 [ V_127 ] );
}
V_31 = F_99 ( & V_118 ) ;
if ( V_31 < 0 )
goto V_18;
V_31 = F_100 ( & V_118 . V_119 ,
& V_120 ) ;
if ( ! V_31 )
V_31 = F_100 ( & V_118 . V_119 ,
& V_121 ) ;
if ( ! V_31 )
V_31 = F_100 ( & V_118 . V_119 ,
& V_122 ) ;
if ( ! V_31 )
V_31 = F_100 ( & V_118 . V_119 ,
& V_123 ) ;
if ( ! V_31 )
V_31 = F_100 ( & V_118 . V_119 ,
& V_124 ) ;
if ( ! V_31 )
V_31 = F_100 ( & V_118 . V_119 ,
& V_125 ) ;
if ( ! V_31 )
V_31 = F_100 ( & V_118 . V_119 ,
& V_126 ) ;
if ( V_31 )
F_95 () ;
V_18:
return V_31 ;
V_130:
F_54 (KERN_ERR DRV_NAME L_70 ,
pci_devs_to_hide + pos) ;
return - V_82 ;
}
static int T_2 F_101 ( void )
{
int V_31 ;
if ( ! F_102 () )
return - V_47 ;
V_31 = F_103 () ;
if ( V_31 )
return V_31 ;
#ifdef F_104
V_31 = F_98 () ;
if ( V_31 < 0 )
return V_31 ;
#endif
F_42 () ;
V_31 = F_105 () ;
if ( V_31 )
F_95 () ;
return V_31 ;
}
static void T_7 F_106 ( void )
{
F_107 () ;
F_95 () ;
}
