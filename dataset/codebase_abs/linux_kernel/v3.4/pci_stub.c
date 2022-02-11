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
struct V_8 * V_9 ;
V_4 = F_9 ( V_6 , struct V_1 , V_6 ) ;
V_9 = F_10 ( V_4 -> V_3 ) ;
F_2 ( & V_4 -> V_3 -> V_3 , L_2 ) ;
F_11 ( V_4 -> V_3 ) ;
F_12 ( V_4 -> V_3 ) ;
if ( F_13 ( V_4 -> V_3 ,
& V_9 -> V_10 ) ) {
F_2 ( & V_4 -> V_3 -> V_3 , L_3 ) ;
} else
F_14 ( V_4 -> V_3 ) ;
F_15 ( V_4 -> V_3 ) ;
F_5 ( V_9 ) ;
F_16 ( V_4 -> V_3 , NULL ) ;
F_17 ( V_4 -> V_3 ) ;
F_18 ( V_4 -> V_3 ) ;
V_4 -> V_3 -> V_11 &= ~ V_12 ;
F_19 ( V_4 -> V_3 ) ;
F_5 ( V_4 ) ;
}
static inline void F_20 ( struct V_1 * V_4 )
{
F_21 ( & V_4 -> V_6 ) ;
}
static inline void F_22 ( struct V_1 * V_4 )
{
F_23 ( & V_4 -> V_6 , F_8 ) ;
}
static struct V_1 * F_24 ( int V_13 , int V_14 ,
int V_15 , int V_16 )
{
struct V_1 * V_4 = NULL ;
unsigned long V_17 ;
F_25 ( & V_18 , V_17 ) ;
F_26 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 != NULL
&& V_13 == F_27 ( V_4 -> V_3 -> V_14 )
&& V_14 == V_4 -> V_3 -> V_14 -> V_19
&& F_28 ( V_15 , V_16 ) == V_4 -> V_3 -> V_20 ) {
F_20 ( V_4 ) ;
goto V_21;
}
}
V_4 = NULL ;
V_21:
F_29 ( & V_18 , V_17 ) ;
return V_4 ;
}
static struct V_2 * F_30 ( struct V_22 * V_23 ,
struct V_1 * V_4 )
{
struct V_2 * V_2 = NULL ;
unsigned long V_17 ;
F_20 ( V_4 ) ;
F_25 ( & V_4 -> V_7 , V_17 ) ;
if ( ! V_4 -> V_23 ) {
V_4 -> V_23 = V_23 ;
V_2 = V_4 -> V_3 ;
}
F_29 ( & V_4 -> V_7 , V_17 ) ;
if ( ! V_2 )
F_22 ( V_4 ) ;
return V_2 ;
}
struct V_2 * F_31 ( struct V_22 * V_23 ,
int V_13 , int V_14 ,
int V_15 , int V_16 )
{
struct V_1 * V_4 ;
struct V_2 * V_24 = NULL ;
unsigned long V_17 ;
F_25 ( & V_18 , V_17 ) ;
F_26 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 != NULL
&& V_13 == F_27 ( V_4 -> V_3 -> V_14 )
&& V_14 == V_4 -> V_3 -> V_14 -> V_19
&& F_28 ( V_15 , V_16 ) == V_4 -> V_3 -> V_20 ) {
V_24 = F_30 ( V_23 , V_4 ) ;
break;
}
}
F_29 ( & V_18 , V_17 ) ;
return V_24 ;
}
struct V_2 * F_32 ( struct V_22 * V_23 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_2 * V_24 = NULL ;
unsigned long V_17 ;
F_25 ( & V_18 , V_17 ) ;
F_26 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_24 = F_30 ( V_23 , V_4 ) ;
break;
}
}
F_29 ( & V_18 , V_17 ) ;
return V_24 ;
}
void F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_25 = NULL ;
unsigned long V_17 ;
F_25 ( & V_18 , V_17 ) ;
F_26 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_25 = V_4 ;
break;
}
}
F_29 ( & V_18 , V_17 ) ;
if ( F_34 ( ! V_25 ) )
return;
F_35 ( & V_26 ) ;
F_36 ( V_3 ) ;
F_14 ( V_4 -> V_3 ) ;
F_15 ( V_25 -> V_3 ) ;
F_17 ( V_25 -> V_3 ) ;
F_37 ( V_25 -> V_3 ) ;
F_11 ( V_25 -> V_3 ) ;
F_25 ( & V_25 -> V_7 , V_17 ) ;
V_25 -> V_23 = NULL ;
F_29 ( & V_25 -> V_7 , V_17 ) ;
F_22 ( V_25 ) ;
F_38 ( & V_26 ) ;
}
static int T_1 F_39 ( struct V_2 * V_3 ,
struct V_27 * V_28 )
{
for (; V_3 != NULL ; V_3 = V_3 -> V_14 -> V_29 ) {
if ( F_27 ( V_3 -> V_14 ) == V_28 -> V_13
&& V_3 -> V_14 -> V_19 == V_28 -> V_14
&& V_3 -> V_20 == V_28 -> V_20 )
return 1 ;
if ( V_3 == V_3 -> V_14 -> V_29 )
break;
}
return 0 ;
}
static int T_1 F_40 ( struct V_2 * V_3 )
{
struct V_27 * V_28 ;
unsigned long V_17 ;
int V_30 = 0 ;
F_25 ( & V_31 , V_17 ) ;
F_26 (pdev_id, &pcistub_device_ids, slot_list) {
if ( F_39 ( V_3 , V_28 ) ) {
V_30 = 1 ;
break;
}
}
F_29 ( & V_31 , V_17 ) ;
return V_30 ;
}
static int T_1 F_41 ( struct V_2 * V_3 )
{
struct V_8 * V_9 ;
int V_32 = 0 ;
F_2 ( & V_3 -> V_3 , L_4 ) ;
V_9 = F_3 ( sizeof( * V_9 ) + strlen ( V_33 L_5 )
+ strlen ( F_42 ( V_3 ) ) + 1 , V_5 ) ;
if ( ! V_9 ) {
V_32 = - V_34 ;
goto V_21;
}
F_16 ( V_3 , V_9 ) ;
sprintf ( V_9 -> V_35 , V_33 L_6 , F_42 ( V_3 ) ) ;
F_2 ( & V_3 -> V_3 , L_7 ) ;
F_43 ( & V_36 ) ;
V_32 = F_44 ( V_3 ) ;
if ( V_32 )
goto V_21;
F_2 ( & V_3 -> V_3 , L_8 ) ;
V_32 = F_45 ( V_3 ) ;
if ( V_32 )
goto V_37;
F_2 ( & V_3 -> V_3 , L_9 ) ;
F_12 ( V_3 ) ;
F_2 ( & V_3 -> V_3 , L_10 ) ;
F_46 ( V_3 ) ;
V_9 -> V_10 = F_47 ( V_3 ) ;
if ( ! V_9 -> V_10 )
F_48 ( & V_3 -> V_3 , L_11 ) ;
F_2 ( & V_3 -> V_3 , L_12 ) ;
F_15 ( V_3 ) ;
V_3 -> V_11 |= V_12 ;
return 0 ;
V_37:
F_18 ( V_3 ) ;
V_21:
F_16 ( V_3 , NULL ) ;
F_5 ( V_9 ) ;
return V_32 ;
}
static int T_2 F_49 ( void )
{
struct V_1 * V_4 ;
unsigned long V_17 ;
int V_32 = 0 ;
F_50 ( V_33 L_13 ) ;
F_25 ( & V_18 , V_17 ) ;
while ( ! F_51 ( & V_38 ) ) {
V_4 = F_9 ( V_38 . V_39 ,
struct V_1 , V_40 ) ;
F_52 ( & V_4 -> V_40 ) ;
F_29 ( & V_18 , V_17 ) ;
V_32 = F_41 ( V_4 -> V_3 ) ;
if ( V_32 ) {
F_48 ( & V_4 -> V_3 -> V_3 ,
L_14 , V_32 ) ;
F_5 ( V_4 ) ;
V_4 = NULL ;
}
F_25 ( & V_18 , V_17 ) ;
if ( V_4 )
F_53 ( & V_4 -> V_40 , & V_41 ) ;
}
V_42 = 1 ;
F_29 ( & V_18 , V_17 ) ;
return 0 ;
}
static int T_1 F_54 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_17 ;
int V_32 = 0 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_34 ;
F_25 ( & V_18 , V_17 ) ;
if ( V_42 ) {
F_29 ( & V_18 , V_17 ) ;
V_32 = F_41 ( V_4 -> V_3 ) ;
F_25 ( & V_18 , V_17 ) ;
if ( ! V_32 )
F_55 ( & V_4 -> V_40 , & V_41 ) ;
} else {
F_2 ( & V_3 -> V_3 , L_15 ) ;
F_55 ( & V_4 -> V_40 , & V_38 ) ;
}
F_29 ( & V_18 , V_17 ) ;
if ( V_32 )
F_22 ( V_4 ) ;
return V_32 ;
}
static int T_1 F_56 ( struct V_2 * V_3 ,
const struct V_43 * V_44 )
{
int V_32 = 0 ;
F_2 ( & V_3 -> V_3 , L_16 ) ;
if ( F_40 ( V_3 ) ) {
if ( V_3 -> V_45 != V_46
&& V_3 -> V_45 != V_47 ) {
F_48 ( & V_3 -> V_3 , L_17
L_18
L_19 ) ;
V_32 = - V_48 ;
goto V_21;
}
F_57 ( & V_3 -> V_3 , L_20 ) ;
V_32 = F_54 ( V_3 ) ;
} else
V_32 = - V_48 ;
V_21:
return V_32 ;
}
static void F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_25 = NULL ;
unsigned long V_17 ;
F_2 ( & V_3 -> V_3 , L_21 ) ;
F_25 ( & V_18 , V_17 ) ;
F_59 ( V_3 ) ;
F_26 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_25 = V_4 ;
break;
}
}
F_29 ( & V_18 , V_17 ) ;
if ( V_25 ) {
F_2 ( & V_3 -> V_3 , L_22 ,
V_25 -> V_23 ) ;
if ( V_25 -> V_23 ) {
F_60 (KERN_WARNING DRV_NAME L_23
L_24 ,
pci_name(found_psdev->dev)) ;
F_60 (KERN_WARNING DRV_NAME L_25
L_26 ) ;
F_60 (KERN_WARNING DRV_NAME L_27
L_28 ) ;
F_60 (KERN_WARNING DRV_NAME L_29
L_30 ) ;
F_61 ( V_25 -> V_23 ,
V_25 -> V_3 ) ;
}
F_25 ( & V_18 , V_17 ) ;
F_52 ( & V_25 -> V_40 ) ;
F_29 ( & V_18 , V_17 ) ;
F_22 ( V_25 ) ;
}
}
static void F_62 ( struct V_1 * V_4 )
{
struct V_49 V_50 ;
int V_32 ;
char V_51 [ V_52 ] ;
F_63 ( ! V_4 ) ;
snprintf ( V_51 , V_52 , L_31 ,
V_4 -> V_23 -> V_53 -> V_54 ) ;
V_55:
V_32 = F_64 ( & V_50 ) ;
if ( V_32 ) {
F_48 ( & V_4 -> V_3 -> V_3 ,
L_32 , V_32 ) ;
return;
}
F_65 ( V_50 , V_51 , L_33 , L_34 ) ;
V_32 = F_66 ( V_50 , 0 ) ;
if ( V_32 ) {
if ( V_32 == - V_56 )
goto V_55;
F_48 ( & V_4 -> V_3 -> V_3 ,
L_35 , V_32 ) ;
return;
}
}
static T_3 F_67 ( struct V_1 * V_4 ,
T_4 V_57 , int V_58 ,
T_3 V_59 )
{
T_3 V_60 = V_59 ;
struct V_61 * V_62 ;
int V_63 ;
V_62 = & ( V_4 -> V_23 -> V_64 -> V_62 ) ;
V_62 -> V_65 = V_58 ;
V_62 -> V_32 = V_57 ;
V_63 = F_68 ( V_4 -> V_3 , V_4 -> V_23 ,
& V_62 -> V_13 , & V_62 -> V_14 , & V_62 -> V_20 ) ;
if ( ! V_63 ) {
F_48 ( & V_4 -> V_3 -> V_3 ,
V_33 L_36 ) ;
return V_66 ;
}
F_69 () ;
F_2 ( & V_4 -> V_3 -> V_3 ,
V_33 L_37 ,
V_58 , V_62 -> V_13 , V_62 -> V_14 , V_62 -> V_20 ) ;
F_70 ( V_67 , ( unsigned long * ) & V_4 -> V_23 -> V_17 ) ;
F_70 ( V_68 ,
( unsigned long * ) & V_4 -> V_23 -> V_64 -> V_17 ) ;
F_69 () ;
F_71 ( V_4 -> V_23 -> V_69 ) ;
V_63 = F_72 ( V_36 ,
! ( F_73 ( V_68 , ( unsigned long * )
& V_4 -> V_23 -> V_64 -> V_17 ) ) , 300 * V_70 ) ;
if ( ! V_63 ) {
if ( F_73 ( V_68 ,
( unsigned long * ) & V_4 -> V_23 -> V_64 -> V_17 ) ) {
F_48 ( & V_4 -> V_3 -> V_3 ,
L_38 ) ;
F_74 ( V_68 ,
( unsigned long * ) & V_4 -> V_23 -> V_64 -> V_17 ) ;
V_62 -> V_32 = V_66 ;
return V_60 ;
}
}
F_74 ( V_67 , ( unsigned long * ) & V_4 -> V_23 -> V_17 ) ;
if ( F_73 ( V_71 ,
( unsigned long * ) & V_4 -> V_23 -> V_64 -> V_17 ) ) {
F_2 ( & V_4 -> V_3 -> V_3 ,
L_39 V_33 L_40 ) ;
F_75 ( V_4 -> V_23 ) ;
}
V_60 = ( T_3 ) V_62 -> V_32 ;
return V_60 ;
}
static T_3 F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
T_3 V_59 ;
V_59 = V_72 ;
F_2 ( & V_3 -> V_3 , L_41 ,
V_3 -> V_14 -> V_19 , V_3 -> V_20 ) ;
F_35 ( & V_26 ) ;
V_4 = F_24 ( F_27 ( V_3 -> V_14 ) ,
V_3 -> V_14 -> V_19 ,
F_77 ( V_3 -> V_20 ) ,
F_78 ( V_3 -> V_20 ) ) ;
if ( ! V_4 || ! V_4 -> V_23 ) {
F_48 ( & V_3 -> V_3 ,
V_33 L_42 ) ;
goto V_73;
}
if ( ! V_4 -> V_23 -> V_64 ) {
F_48 ( & V_3 -> V_3 , V_33 L_43
L_44 ) ;
F_62 ( V_4 ) ;
goto V_74;
}
if ( ! F_73 ( V_75 ,
( unsigned long * ) & V_4 -> V_23 -> V_64 -> V_17 ) ) {
F_48 ( & V_3 -> V_3 ,
L_45 ) ;
goto V_74;
}
V_59 = F_67 ( V_4 , 1 , V_76 , V_59 ) ;
if ( V_59 == V_66 ||
V_59 == V_77 ) {
F_2 ( & V_3 -> V_3 ,
L_46 ) ;
F_62 ( V_4 ) ;
}
V_74:
F_22 ( V_4 ) ;
V_73:
F_38 ( & V_26 ) ;
return V_59 ;
}
static T_3 F_79 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
T_3 V_59 ;
V_59 = V_72 ;
F_2 ( & V_3 -> V_3 , L_47 ,
V_3 -> V_14 -> V_19 , V_3 -> V_20 ) ;
F_35 ( & V_26 ) ;
V_4 = F_24 ( F_27 ( V_3 -> V_14 ) ,
V_3 -> V_14 -> V_19 ,
F_77 ( V_3 -> V_20 ) ,
F_78 ( V_3 -> V_20 ) ) ;
if ( ! V_4 || ! V_4 -> V_23 ) {
F_48 ( & V_3 -> V_3 ,
V_33 L_42 ) ;
goto V_73;
}
if ( ! V_4 -> V_23 -> V_64 ) {
F_48 ( & V_3 -> V_3 , V_33 L_43
L_44 ) ;
F_62 ( V_4 ) ;
goto V_74;
}
if ( ! F_73 ( V_75 ,
( unsigned long * ) & V_4 -> V_23 -> V_64 -> V_17 ) ) {
F_48 ( & V_3 -> V_3 ,
L_45 ) ;
goto V_74;
}
V_59 = F_67 ( V_4 , 1 , V_78 , V_59 ) ;
if ( V_59 == V_66 ||
V_59 == V_77 ) {
F_2 ( & V_3 -> V_3 ,
L_48 ) ;
F_62 ( V_4 ) ;
}
V_74:
F_22 ( V_4 ) ;
V_73:
F_38 ( & V_26 ) ;
return V_59 ;
}
static T_3 F_80 ( struct V_2 * V_3 ,
T_4 error )
{
struct V_1 * V_4 ;
T_3 V_59 ;
V_59 = V_79 ;
F_2 ( & V_3 -> V_3 , L_49 ,
V_3 -> V_14 -> V_19 , V_3 -> V_20 ) ;
F_35 ( & V_26 ) ;
V_4 = F_24 ( F_27 ( V_3 -> V_14 ) ,
V_3 -> V_14 -> V_19 ,
F_77 ( V_3 -> V_20 ) ,
F_78 ( V_3 -> V_20 ) ) ;
if ( ! V_4 || ! V_4 -> V_23 ) {
F_48 ( & V_3 -> V_3 ,
V_33 L_42 ) ;
goto V_73;
}
if ( ! V_4 -> V_23 -> V_64 ) {
F_48 ( & V_3 -> V_3 , V_33 L_43
L_44 ) ;
F_62 ( V_4 ) ;
goto V_74;
}
if ( ! F_73 ( V_75 ,
( unsigned long * ) & V_4 -> V_23 -> V_64 -> V_17 ) ) {
F_2 ( & V_3 -> V_3 , L_50 ) ;
F_62 ( V_4 ) ;
goto V_74;
}
V_59 = F_67 ( V_4 , error , V_80 , V_59 ) ;
if ( V_59 == V_66 ||
V_59 == V_77 ) {
F_2 ( & V_3 -> V_3 ,
L_51 ) ;
F_62 ( V_4 ) ;
}
V_74:
F_22 ( V_4 ) ;
V_73:
F_38 ( & V_26 ) ;
return V_59 ;
}
static void F_81 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_3 -> V_3 , L_52 ,
V_3 -> V_14 -> V_19 , V_3 -> V_20 ) ;
F_35 ( & V_26 ) ;
V_4 = F_24 ( F_27 ( V_3 -> V_14 ) ,
V_3 -> V_14 -> V_19 ,
F_77 ( V_3 -> V_20 ) ,
F_78 ( V_3 -> V_20 ) ) ;
if ( ! V_4 || ! V_4 -> V_23 ) {
F_48 ( & V_3 -> V_3 ,
V_33 L_42 ) ;
goto V_73;
}
if ( ! V_4 -> V_23 -> V_64 ) {
F_48 ( & V_3 -> V_3 , V_33 L_43
L_44 ) ;
F_62 ( V_4 ) ;
goto V_74;
}
if ( ! F_73 ( V_75 ,
( unsigned long * ) & V_4 -> V_23 -> V_64 -> V_17 ) ) {
F_48 ( & V_3 -> V_3 ,
L_45 ) ;
F_62 ( V_4 ) ;
goto V_74;
}
F_67 ( V_4 , 1 , V_81 ,
V_72 ) ;
V_74:
F_22 ( V_4 ) ;
V_73:
F_38 ( & V_26 ) ;
return;
}
static inline int F_82 ( const char * V_82 , int * V_13 , int * V_14 ,
int * V_15 , int * V_16 )
{
int V_32 ;
V_32 = sscanf ( V_82 , L_53 , V_13 , V_14 , V_15 , V_16 ) ;
if ( V_32 == 4 )
return 0 ;
else if ( V_32 < 0 )
return - V_83 ;
* V_13 = 0 ;
V_32 = sscanf ( V_82 , L_54 , V_14 , V_15 , V_16 ) ;
if ( V_32 == 3 )
return 0 ;
return - V_83 ;
}
static inline int F_83 ( const char * V_82 , int * V_13 , int * V_14 , int
* V_15 , int * V_16 , int * V_84 , int * V_85 , int * V_86 )
{
int V_32 ;
V_32 =
sscanf ( V_82 , L_55 , V_13 , V_14 , V_15 ,
V_16 , V_84 , V_85 , V_86 ) ;
if ( V_32 == 7 )
return 0 ;
return - V_83 ;
}
static int F_84 ( int V_13 , int V_14 , int V_15 , int V_16 )
{
struct V_27 * V_87 ;
unsigned long V_17 ;
V_87 = F_85 ( sizeof( * V_87 ) , V_88 ) ;
if ( ! V_87 )
return - V_34 ;
V_87 -> V_13 = V_13 ;
V_87 -> V_14 = V_14 ;
V_87 -> V_20 = F_28 ( V_15 , V_16 ) ;
F_50 ( V_33 L_56 ,
V_13 , V_14 , V_15 , V_16 ) ;
F_25 ( & V_31 , V_17 ) ;
F_53 ( & V_87 -> V_89 , & V_90 ) ;
F_29 ( & V_31 , V_17 ) ;
return 0 ;
}
static int F_86 ( int V_13 , int V_14 , int V_15 , int V_16 )
{
struct V_27 * V_87 , * V_91 ;
int V_20 = F_28 ( V_15 , V_16 ) ;
int V_32 = - V_92 ;
unsigned long V_17 ;
F_25 ( & V_31 , V_17 ) ;
F_87 (pci_dev_id, t, &pcistub_device_ids,
slot_list) {
if ( V_87 -> V_13 == V_13
&& V_87 -> V_14 == V_14 && V_87 -> V_20 == V_20 ) {
F_52 ( & V_87 -> V_89 ) ;
F_5 ( V_87 ) ;
V_32 = 0 ;
F_50 ( V_33 L_57
L_58 , V_13 , V_14 , V_15 , V_16 ) ;
}
}
F_29 ( & V_31 , V_17 ) ;
return V_32 ;
}
static int F_88 ( int V_13 , int V_14 , int V_15 , int V_16 , int V_84 ,
int V_85 , int V_86 )
{
int V_32 = 0 ;
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_93 * V_94 ;
V_4 = F_24 ( V_13 , V_14 , V_15 , V_16 ) ;
if ( ! V_4 || ! V_4 -> V_3 ) {
V_32 = - V_48 ;
goto V_21;
}
V_3 = V_4 -> V_3 ;
V_94 = F_3 ( sizeof( * V_94 ) , V_5 ) ;
if ( ! V_94 ) {
V_32 = - V_34 ;
goto V_21;
}
V_94 -> V_95 = V_84 ;
V_94 -> V_85 = V_85 ;
V_94 -> V_86 = V_86 ;
V_94 -> V_96 = NULL ;
V_94 -> V_97 = NULL ;
V_94 -> V_74 = NULL ;
V_94 -> V_98 = V_99 ;
V_32 = F_89 ( V_3 , V_94 ) ;
if ( V_32 )
F_5 ( V_94 ) ;
V_21:
return V_32 ;
}
static T_5 F_90 ( struct V_100 * V_101 , const char * V_82 ,
T_6 V_102 )
{
int V_13 , V_14 , V_15 , V_16 ;
int V_32 ;
V_32 = F_82 ( V_82 , & V_13 , & V_14 , & V_15 , & V_16 ) ;
if ( V_32 )
goto V_21;
V_32 = F_84 ( V_13 , V_14 , V_15 , V_16 ) ;
V_21:
if ( ! V_32 )
V_32 = V_102 ;
return V_32 ;
}
static T_5 F_91 ( struct V_100 * V_101 , const char * V_82 ,
T_6 V_102 )
{
int V_13 , V_14 , V_15 , V_16 ;
int V_32 ;
V_32 = F_82 ( V_82 , & V_13 , & V_14 , & V_15 , & V_16 ) ;
if ( V_32 )
goto V_21;
V_32 = F_86 ( V_13 , V_14 , V_15 , V_16 ) ;
V_21:
if ( ! V_32 )
V_32 = V_102 ;
return V_32 ;
}
static T_5 F_92 ( struct V_100 * V_101 , char * V_82 )
{
struct V_27 * V_87 ;
T_6 V_102 = 0 ;
unsigned long V_17 ;
F_25 ( & V_31 , V_17 ) ;
F_26 (pci_dev_id, &pcistub_device_ids, slot_list) {
if ( V_102 >= V_103 )
break;
V_102 += F_93 ( V_82 + V_102 , V_103 - V_102 ,
L_59 ,
V_87 -> V_13 , V_87 -> V_14 ,
F_77 ( V_87 -> V_20 ) ,
F_78 ( V_87 -> V_20 ) ) ;
}
F_29 ( & V_31 , V_17 ) ;
return V_102 ;
}
static T_5 F_94 ( struct V_100 * V_101 , char * V_82 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
T_6 V_102 = 0 ;
unsigned long V_17 ;
F_25 ( & V_18 , V_17 ) ;
F_26 (psdev, &pcistub_devices, dev_list) {
if ( V_102 >= V_103 )
break;
if ( ! V_4 -> V_3 )
continue;
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 )
continue;
V_102 +=
F_93 ( V_82 + V_102 , V_103 - V_102 ,
L_60 ,
F_42 ( V_4 -> V_3 ) ,
V_9 -> V_104 ? L_61 : L_62 ,
V_9 -> V_105 ? L_63 : L_64 ,
V_9 -> V_106 ) ;
}
F_29 ( & V_18 , V_17 ) ;
return V_102 ;
}
static T_5 F_95 ( struct V_100 * V_101 ,
const char * V_82 ,
T_6 V_102 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
int V_13 , V_14 , V_15 , V_16 ;
int V_32 = - V_92 ;
V_32 = F_82 ( V_82 , & V_13 , & V_14 , & V_15 , & V_16 ) ;
if ( V_32 )
goto V_21;
V_4 = F_24 ( V_13 , V_14 , V_15 , V_16 ) ;
if ( ! V_4 )
goto V_21;
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 )
goto V_21;
F_2 ( & V_4 -> V_3 -> V_3 , L_65 ,
V_9 -> V_35 , V_9 -> V_104 ,
! V_9 -> V_104 ) ;
V_9 -> V_104 = ! ( V_9 -> V_104 ) ;
if ( V_9 -> V_104 )
V_9 -> V_105 = 1 ;
V_21:
if ( ! V_32 )
V_32 = V_102 ;
return V_32 ;
}
static T_5 F_96 ( struct V_100 * V_101 , const char * V_82 ,
T_6 V_102 )
{
int V_13 , V_14 , V_15 , V_16 , V_84 , V_85 , V_86 ;
int V_32 ;
V_32 = F_83 ( V_82 , & V_13 , & V_14 , & V_15 , & V_16 , & V_84 , & V_85 ,
& V_86 ) ;
if ( V_32 )
goto V_21;
V_32 = F_88 ( V_13 , V_14 , V_15 , V_16 , V_84 , V_85 , V_86 ) ;
V_21:
if ( ! V_32 )
V_32 = V_102 ;
return V_32 ;
}
static T_5 F_97 ( struct V_100 * V_101 , char * V_82 )
{
int V_102 = 0 ;
unsigned long V_17 ;
struct V_107 * V_108 ;
struct V_8 * V_9 ;
const struct V_93 * V_94 ;
const struct V_109 * V_110 ;
F_25 ( & V_31 , V_17 ) ;
F_26 (quirk, &xen_pcibk_quirks, quirks_list) {
if ( V_102 >= V_103 )
goto V_21;
V_102 += F_93 ( V_82 + V_102 , V_103 - V_102 ,
L_66 ,
V_108 -> V_23 -> V_14 -> V_19 ,
F_77 ( V_108 -> V_23 -> V_20 ) ,
F_78 ( V_108 -> V_23 -> V_20 ) ,
V_108 -> V_111 . V_112 , V_108 -> V_111 . V_113 ,
V_108 -> V_111 . V_114 ,
V_108 -> V_111 . V_115 ) ;
V_9 = F_10 ( V_108 -> V_23 ) ;
F_26 (cfg_entry, &dev_data->config_fields, list) {
V_94 = V_110 -> V_94 ;
if ( V_102 >= V_103 )
goto V_21;
V_102 += F_93 ( V_82 + V_102 , V_103 - V_102 ,
L_67 ,
V_110 -> V_116 +
V_94 -> V_95 , V_94 -> V_85 ,
V_94 -> V_86 ) ;
}
}
V_21:
F_29 ( & V_31 , V_17 ) ;
return V_102 ;
}
static T_5 F_98 ( struct V_100 * V_101 , const char * V_82 ,
T_6 V_102 )
{
int V_13 , V_14 , V_15 , V_16 ;
int V_32 ;
struct V_1 * V_4 ;
struct V_8 * V_9 ;
V_32 = F_82 ( V_82 , & V_13 , & V_14 , & V_15 , & V_16 ) ;
if ( V_32 )
goto V_21;
V_4 = F_24 ( V_13 , V_14 , V_15 , V_16 ) ;
if ( ! V_4 ) {
V_32 = - V_48 ;
goto V_21;
}
if ( ! V_4 -> V_3 ) {
V_32 = - V_48 ;
goto V_74;
}
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 ) {
V_32 = - V_117 ;
goto V_74;
}
if ( ! V_9 -> V_118 ) {
V_9 -> V_118 = 1 ;
F_99 ( & V_4 -> V_3 -> V_3 , L_68
L_69 ) ;
F_99 ( & V_4 -> V_3 -> V_3 ,
L_70 ) ;
}
V_74:
F_22 ( V_4 ) ;
V_21:
if ( ! V_32 )
V_32 = V_102 ;
return V_32 ;
}
static T_5 F_100 ( struct V_100 * V_101 , char * V_82 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
T_6 V_102 = 0 ;
unsigned long V_17 ;
F_25 ( & V_18 , V_17 ) ;
F_26 (psdev, &pcistub_devices, dev_list) {
if ( V_102 >= V_103 )
break;
if ( ! V_4 -> V_3 )
continue;
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 || ! V_9 -> V_118 )
continue;
V_102 +=
F_93 ( V_82 + V_102 , V_103 - V_102 , L_71 ,
F_42 ( V_4 -> V_3 ) ) ;
}
F_29 ( & V_18 , V_17 ) ;
return V_102 ;
}
static void F_101 ( void )
{
F_102 ( & V_119 . V_120 , & V_121 ) ;
F_102 ( & V_119 . V_120 ,
& V_122 ) ;
F_102 ( & V_119 . V_120 , & V_123 ) ;
F_102 ( & V_119 . V_120 , & V_124 ) ;
F_102 ( & V_119 . V_120 ,
& V_125 ) ;
F_102 ( & V_119 . V_120 ,
& V_126 ) ;
F_102 ( & V_119 . V_120 ,
& V_127 ) ;
F_103 ( & V_119 ) ;
}
static int T_2 F_104 ( void )
{
int V_128 = 0 ;
int V_32 = 0 ;
int V_13 , V_14 , V_15 , V_16 ;
int V_129 ;
if ( V_130 && * V_130 ) {
do {
V_129 = 0 ;
V_32 = sscanf ( V_130 + V_128 ,
L_72 ,
& V_13 , & V_14 , & V_15 , & V_16 , & V_129 ) ;
if ( V_32 != 4 ) {
V_13 = 0 ;
V_32 = sscanf ( V_130 + V_128 ,
L_73 ,
& V_14 , & V_15 , & V_16 , & V_129 ) ;
if ( V_32 != 3 )
goto V_131;
}
V_32 = F_84 ( V_13 , V_14 , V_15 , V_16 ) ;
if ( V_32 )
goto V_21;
V_128 += V_129 ;
} while ( V_129 > 0 && V_130 [ V_128 ] );
}
V_32 = F_105 ( & V_119 ) ;
if ( V_32 < 0 )
goto V_21;
V_32 = F_106 ( & V_119 . V_120 ,
& V_121 ) ;
if ( ! V_32 )
V_32 = F_106 ( & V_119 . V_120 ,
& V_122 ) ;
if ( ! V_32 )
V_32 = F_106 ( & V_119 . V_120 ,
& V_123 ) ;
if ( ! V_32 )
V_32 = F_106 ( & V_119 . V_120 ,
& V_124 ) ;
if ( ! V_32 )
V_32 = F_106 ( & V_119 . V_120 ,
& V_125 ) ;
if ( ! V_32 )
V_32 = F_106 ( & V_119 . V_120 ,
& V_126 ) ;
if ( ! V_32 )
V_32 = F_106 ( & V_119 . V_120 ,
& V_127 ) ;
if ( V_32 )
F_101 () ;
V_21:
return V_32 ;
V_131:
F_60 (KERN_ERR DRV_NAME L_74 ,
pci_devs_to_hide + pos) ;
return - V_83 ;
}
static int T_2 F_107 ( void )
{
int V_32 ;
if ( ! F_108 () )
return - V_48 ;
V_32 = F_109 () ;
if ( V_32 )
return V_32 ;
#ifdef F_110
V_32 = F_104 () ;
if ( V_32 < 0 )
return V_32 ;
#endif
F_49 () ;
V_32 = F_111 () ;
if ( V_32 )
F_101 () ;
return V_32 ;
}
static void T_7 F_112 ( void )
{
F_113 () ;
F_101 () ;
}
