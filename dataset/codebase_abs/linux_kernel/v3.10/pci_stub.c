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
struct V_2 * V_3 ;
struct V_8 * V_9 ;
V_4 = F_9 ( V_6 , struct V_1 , V_6 ) ;
V_3 = V_4 -> V_3 ;
V_9 = F_10 ( V_3 ) ;
F_2 ( & V_3 -> V_3 , L_2 ) ;
F_11 ( V_3 ) ;
F_12 ( V_3 ) ;
if ( F_13 ( V_3 , & V_9 -> V_10 ) )
F_2 ( & V_3 -> V_3 , L_3 ) ;
else
F_14 ( V_3 ) ;
if ( V_3 -> V_11 ) {
struct V_12 V_13 = {
. V_14 = F_15 ( V_3 -> V_15 ) ,
. V_15 = V_3 -> V_15 -> V_16 ,
. V_17 = V_3 -> V_17
} ;
int V_18 = F_16 ( V_19 ,
& V_13 ) ;
if ( V_18 )
F_17 ( & V_3 -> V_3 , L_4 ,
V_18 ) ;
}
F_18 ( V_3 ) ;
F_5 ( V_9 ) ;
F_19 ( V_3 , NULL ) ;
F_20 ( V_3 ) ;
F_21 ( V_3 ) ;
V_3 -> V_20 &= ~ V_21 ;
F_22 ( V_3 ) ;
F_5 ( V_4 ) ;
}
static inline void F_23 ( struct V_1 * V_4 )
{
F_24 ( & V_4 -> V_6 ) ;
}
static inline void F_25 ( struct V_1 * V_4 )
{
F_26 ( & V_4 -> V_6 , F_8 ) ;
}
static struct V_1 * F_27 ( int V_22 , int V_15 ,
int V_23 , int V_24 )
{
struct V_1 * V_4 = NULL ;
unsigned long V_25 ;
F_28 ( & V_26 , V_25 ) ;
F_29 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 != NULL
&& V_22 == F_15 ( V_4 -> V_3 -> V_15 )
&& V_15 == V_4 -> V_3 -> V_15 -> V_16
&& V_23 == F_30 ( V_4 -> V_3 -> V_17 )
&& V_24 == F_31 ( V_4 -> V_3 -> V_17 ) ) {
F_23 ( V_4 ) ;
goto V_27;
}
}
V_4 = NULL ;
V_27:
F_32 ( & V_26 , V_25 ) ;
return V_4 ;
}
static struct V_2 * F_33 ( struct V_28 * V_29 ,
struct V_1 * V_4 )
{
struct V_2 * V_2 = NULL ;
unsigned long V_25 ;
F_23 ( V_4 ) ;
F_28 ( & V_4 -> V_7 , V_25 ) ;
if ( ! V_4 -> V_29 ) {
V_4 -> V_29 = V_29 ;
V_2 = V_4 -> V_3 ;
}
F_32 ( & V_4 -> V_7 , V_25 ) ;
if ( ! V_2 )
F_25 ( V_4 ) ;
return V_2 ;
}
struct V_2 * F_34 ( struct V_28 * V_29 ,
int V_22 , int V_15 ,
int V_23 , int V_24 )
{
struct V_1 * V_4 ;
struct V_2 * V_30 = NULL ;
unsigned long V_25 ;
F_28 ( & V_26 , V_25 ) ;
F_29 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 != NULL
&& V_22 == F_15 ( V_4 -> V_3 -> V_15 )
&& V_15 == V_4 -> V_3 -> V_15 -> V_16
&& V_23 == F_30 ( V_4 -> V_3 -> V_17 )
&& V_24 == F_31 ( V_4 -> V_3 -> V_17 ) ) {
V_30 = F_33 ( V_29 , V_4 ) ;
break;
}
}
F_32 ( & V_26 , V_25 ) ;
return V_30 ;
}
struct V_2 * F_35 ( struct V_28 * V_29 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_2 * V_30 = NULL ;
unsigned long V_25 ;
F_28 ( & V_26 , V_25 ) ;
F_29 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_30 = F_33 ( V_29 , V_4 ) ;
break;
}
}
F_32 ( & V_26 , V_25 ) ;
return V_30 ;
}
void F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_31 = NULL ;
unsigned long V_25 ;
F_28 ( & V_26 , V_25 ) ;
F_29 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_31 = V_4 ;
break;
}
}
F_32 ( & V_26 , V_25 ) ;
if ( F_37 ( ! V_31 ) )
return;
F_38 ( & V_32 ) ;
F_39 ( V_3 ) ;
F_14 ( V_4 -> V_3 ) ;
F_18 ( V_31 -> V_3 ) ;
F_20 ( V_31 -> V_3 ) ;
F_40 ( V_31 -> V_3 ) ;
F_11 ( V_31 -> V_3 ) ;
F_28 ( & V_31 -> V_7 , V_25 ) ;
V_31 -> V_29 = NULL ;
F_32 ( & V_31 -> V_7 , V_25 ) ;
F_25 ( V_31 ) ;
F_41 ( & V_32 ) ;
}
static int F_42 ( struct V_2 * V_3 ,
struct V_33 * V_34 )
{
for (; V_3 != NULL ; V_3 = V_3 -> V_15 -> V_35 ) {
if ( F_15 ( V_3 -> V_15 ) == V_34 -> V_22
&& V_3 -> V_15 -> V_16 == V_34 -> V_15
&& V_3 -> V_17 == V_34 -> V_17 )
return 1 ;
if ( V_3 == V_3 -> V_15 -> V_35 )
break;
}
return 0 ;
}
static int F_43 ( struct V_2 * V_3 )
{
struct V_33 * V_34 ;
unsigned long V_25 ;
int V_36 = 0 ;
F_28 ( & V_37 , V_25 ) ;
F_29 (pdev_id, &pcistub_device_ids, slot_list) {
if ( F_42 ( V_3 , V_34 ) ) {
V_36 = 1 ;
break;
}
}
F_32 ( & V_37 , V_25 ) ;
return V_36 ;
}
static int F_44 ( struct V_2 * V_3 )
{
struct V_8 * V_9 ;
int V_18 = 0 ;
F_2 ( & V_3 -> V_3 , L_5 ) ;
V_9 = F_3 ( sizeof( * V_9 ) + strlen ( V_38 L_6 )
+ strlen ( F_45 ( V_3 ) ) + 1 , V_5 ) ;
if ( ! V_9 ) {
V_18 = - V_39 ;
goto V_27;
}
F_19 ( V_3 , V_9 ) ;
sprintf ( V_9 -> V_40 , V_38 L_7 , F_45 ( V_3 ) ) ;
F_2 ( & V_3 -> V_3 , L_8 ) ;
F_46 ( & V_41 ) ;
V_18 = F_47 ( V_3 ) ;
if ( V_18 )
goto V_27;
F_2 ( & V_3 -> V_3 , L_9 ) ;
V_18 = F_48 ( V_3 ) ;
if ( V_18 )
goto V_42;
if ( V_3 -> V_11 ) {
struct V_12 V_13 = {
. V_14 = F_15 ( V_3 -> V_15 ) ,
. V_15 = V_3 -> V_15 -> V_16 ,
. V_17 = V_3 -> V_17
} ;
V_18 = F_16 ( V_43 , & V_13 ) ;
if ( V_18 )
F_49 ( & V_3 -> V_3 , L_10 ,
V_18 ) ;
}
F_2 ( & V_3 -> V_3 , L_11 ) ;
F_50 ( V_3 ) ;
V_9 -> V_10 = F_51 ( V_3 ) ;
if ( ! V_9 -> V_10 )
F_49 ( & V_3 -> V_3 , L_12 ) ;
else {
F_2 ( & V_3 -> V_3 , L_13 ) ;
F_12 ( V_3 ) ;
F_14 ( V_3 ) ;
}
F_2 ( & V_3 -> V_3 , L_14 ) ;
F_18 ( V_3 ) ;
V_3 -> V_20 |= V_21 ;
return 0 ;
V_42:
F_21 ( V_3 ) ;
V_27:
F_19 ( V_3 , NULL ) ;
F_5 ( V_9 ) ;
return V_18 ;
}
static int T_1 F_52 ( void )
{
struct V_1 * V_4 ;
unsigned long V_25 ;
int V_18 = 0 ;
F_53 ( V_38 L_15 ) ;
F_28 ( & V_26 , V_25 ) ;
while ( ! F_54 ( & V_44 ) ) {
V_4 = F_9 ( V_44 . V_45 ,
struct V_1 , V_46 ) ;
F_55 ( & V_4 -> V_46 ) ;
F_32 ( & V_26 , V_25 ) ;
V_18 = F_44 ( V_4 -> V_3 ) ;
if ( V_18 ) {
F_49 ( & V_4 -> V_3 -> V_3 ,
L_16 , V_18 ) ;
F_5 ( V_4 ) ;
V_4 = NULL ;
}
F_28 ( & V_26 , V_25 ) ;
if ( V_4 )
F_56 ( & V_4 -> V_46 , & V_47 ) ;
}
V_48 = 1 ;
F_32 ( & V_26 , V_25 ) ;
return 0 ;
}
static int F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_25 ;
int V_18 = 0 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_39 ;
F_28 ( & V_26 , V_25 ) ;
if ( V_48 ) {
F_32 ( & V_26 , V_25 ) ;
V_18 = F_44 ( V_4 -> V_3 ) ;
F_28 ( & V_26 , V_25 ) ;
if ( ! V_18 )
F_58 ( & V_4 -> V_46 , & V_47 ) ;
} else {
F_2 ( & V_3 -> V_3 , L_17 ) ;
F_58 ( & V_4 -> V_46 , & V_44 ) ;
}
F_32 ( & V_26 , V_25 ) ;
if ( V_18 )
F_25 ( V_4 ) ;
return V_18 ;
}
static int F_59 ( struct V_2 * V_3 , const struct V_49 * V_50 )
{
int V_18 = 0 ;
F_2 ( & V_3 -> V_3 , L_18 ) ;
if ( F_43 ( V_3 ) ) {
if ( V_3 -> V_51 != V_52
&& V_3 -> V_51 != V_53 ) {
F_49 ( & V_3 -> V_3 , L_19
L_20
L_21 ) ;
V_18 = - V_54 ;
goto V_27;
}
F_60 ( & V_3 -> V_3 , L_22 ) ;
V_18 = F_57 ( V_3 ) ;
} else
V_18 = - V_54 ;
V_27:
return V_18 ;
}
static void F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_31 = NULL ;
unsigned long V_25 ;
F_2 ( & V_3 -> V_3 , L_23 ) ;
F_28 ( & V_26 , V_25 ) ;
F_62 ( V_3 ) ;
F_29 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_31 = V_4 ;
break;
}
}
F_32 ( & V_26 , V_25 ) ;
if ( V_31 ) {
F_2 ( & V_3 -> V_3 , L_24 ,
V_31 -> V_29 ) ;
if ( V_31 -> V_29 ) {
F_63 (KERN_WARNING DRV_NAME L_25
L_26 ,
pci_name(found_psdev->dev)) ;
F_63 (KERN_WARNING DRV_NAME L_27
L_28 ) ;
F_63 (KERN_WARNING DRV_NAME L_29
L_30 ) ;
F_63 (KERN_WARNING DRV_NAME L_31
L_32 ) ;
F_64 ( V_31 -> V_29 ,
V_31 -> V_3 ) ;
}
F_28 ( & V_26 , V_25 ) ;
F_55 ( & V_31 -> V_46 ) ;
F_32 ( & V_26 , V_25 ) ;
F_25 ( V_31 ) ;
}
}
static void F_65 ( struct V_1 * V_4 )
{
struct V_55 V_56 ;
int V_18 ;
char V_57 [ V_58 ] ;
F_66 ( ! V_4 ) ;
snprintf ( V_57 , V_58 , L_33 ,
V_4 -> V_29 -> V_59 -> V_60 ) ;
V_61:
V_18 = F_67 ( & V_56 ) ;
if ( V_18 ) {
F_49 ( & V_4 -> V_3 -> V_3 ,
L_34 , V_18 ) ;
return;
}
F_68 ( V_56 , V_57 , L_35 , L_36 ) ;
V_18 = F_69 ( V_56 , 0 ) ;
if ( V_18 ) {
if ( V_18 == - V_62 )
goto V_61;
F_49 ( & V_4 -> V_3 -> V_3 ,
L_37 , V_18 ) ;
return;
}
}
static T_2 F_70 ( struct V_1 * V_4 ,
T_3 V_63 , int V_64 ,
T_2 V_65 )
{
T_2 V_66 = V_65 ;
struct V_67 * V_68 ;
int V_69 ;
V_68 = & ( V_4 -> V_29 -> V_70 -> V_68 ) ;
V_68 -> V_71 = V_64 ;
V_68 -> V_18 = V_63 ;
V_69 = F_71 ( V_4 -> V_3 , V_4 -> V_29 ,
& V_68 -> V_22 , & V_68 -> V_15 , & V_68 -> V_17 ) ;
if ( ! V_69 ) {
F_49 ( & V_4 -> V_3 -> V_3 ,
V_38 L_38 ) ;
return V_72 ;
}
F_72 () ;
F_2 ( & V_4 -> V_3 -> V_3 ,
V_38 L_39 ,
V_64 , V_68 -> V_22 , V_68 -> V_15 , V_68 -> V_17 ) ;
F_73 ( V_73 , ( unsigned long * ) & V_4 -> V_29 -> V_25 ) ;
F_73 ( V_74 ,
( unsigned long * ) & V_4 -> V_29 -> V_70 -> V_25 ) ;
F_72 () ;
F_74 ( V_4 -> V_29 -> V_75 ) ;
V_69 = F_75 ( V_41 ,
! ( F_76 ( V_74 , ( unsigned long * )
& V_4 -> V_29 -> V_70 -> V_25 ) ) , 300 * V_76 ) ;
if ( ! V_69 ) {
if ( F_76 ( V_74 ,
( unsigned long * ) & V_4 -> V_29 -> V_70 -> V_25 ) ) {
F_49 ( & V_4 -> V_3 -> V_3 ,
L_40 ) ;
F_77 ( V_74 ,
( unsigned long * ) & V_4 -> V_29 -> V_70 -> V_25 ) ;
V_68 -> V_18 = V_72 ;
return V_66 ;
}
}
F_77 ( V_73 , ( unsigned long * ) & V_4 -> V_29 -> V_25 ) ;
if ( F_76 ( V_77 ,
( unsigned long * ) & V_4 -> V_29 -> V_70 -> V_25 ) ) {
F_2 ( & V_4 -> V_3 -> V_3 ,
L_41 V_38 L_42 ) ;
F_78 ( V_4 -> V_29 ) ;
}
V_66 = ( T_2 ) V_68 -> V_18 ;
return V_66 ;
}
static T_2 F_79 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
T_2 V_65 ;
V_65 = V_78 ;
F_2 ( & V_3 -> V_3 , L_43 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_38 ( & V_32 ) ;
V_4 = F_27 ( F_15 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_30 ( V_3 -> V_17 ) ,
F_31 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_29 ) {
F_49 ( & V_3 -> V_3 ,
V_38 L_44 ) ;
goto V_79;
}
if ( ! V_4 -> V_29 -> V_70 ) {
F_49 ( & V_3 -> V_3 , V_38 L_45
L_46 ) ;
F_65 ( V_4 ) ;
goto V_79;
}
if ( ! F_76 ( V_80 ,
( unsigned long * ) & V_4 -> V_29 -> V_70 -> V_25 ) ) {
F_49 ( & V_3 -> V_3 ,
L_47 ) ;
goto V_79;
}
V_65 = F_70 ( V_4 , 1 , V_81 , V_65 ) ;
if ( V_65 == V_72 ||
V_65 == V_82 ) {
F_2 ( & V_3 -> V_3 ,
L_48 ) ;
F_65 ( V_4 ) ;
}
V_79:
if ( V_4 )
F_25 ( V_4 ) ;
F_41 ( & V_32 ) ;
return V_65 ;
}
static T_2 F_80 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
T_2 V_65 ;
V_65 = V_78 ;
F_2 ( & V_3 -> V_3 , L_49 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_38 ( & V_32 ) ;
V_4 = F_27 ( F_15 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_30 ( V_3 -> V_17 ) ,
F_31 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_29 ) {
F_49 ( & V_3 -> V_3 ,
V_38 L_44 ) ;
goto V_79;
}
if ( ! V_4 -> V_29 -> V_70 ) {
F_49 ( & V_3 -> V_3 , V_38 L_45
L_46 ) ;
F_65 ( V_4 ) ;
goto V_79;
}
if ( ! F_76 ( V_80 ,
( unsigned long * ) & V_4 -> V_29 -> V_70 -> V_25 ) ) {
F_49 ( & V_3 -> V_3 ,
L_47 ) ;
goto V_79;
}
V_65 = F_70 ( V_4 , 1 , V_83 , V_65 ) ;
if ( V_65 == V_72 ||
V_65 == V_82 ) {
F_2 ( & V_3 -> V_3 ,
L_50 ) ;
F_65 ( V_4 ) ;
}
V_79:
if ( V_4 )
F_25 ( V_4 ) ;
F_41 ( & V_32 ) ;
return V_65 ;
}
static T_2 F_81 ( struct V_2 * V_3 ,
T_3 error )
{
struct V_1 * V_4 ;
T_2 V_65 ;
V_65 = V_84 ;
F_2 ( & V_3 -> V_3 , L_51 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_38 ( & V_32 ) ;
V_4 = F_27 ( F_15 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_30 ( V_3 -> V_17 ) ,
F_31 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_29 ) {
F_49 ( & V_3 -> V_3 ,
V_38 L_44 ) ;
goto V_79;
}
if ( ! V_4 -> V_29 -> V_70 ) {
F_49 ( & V_3 -> V_3 , V_38 L_45
L_46 ) ;
F_65 ( V_4 ) ;
goto V_79;
}
if ( ! F_76 ( V_80 ,
( unsigned long * ) & V_4 -> V_29 -> V_70 -> V_25 ) ) {
F_2 ( & V_3 -> V_3 , L_52 ) ;
F_65 ( V_4 ) ;
goto V_79;
}
V_65 = F_70 ( V_4 , error , V_85 , V_65 ) ;
if ( V_65 == V_72 ||
V_65 == V_82 ) {
F_2 ( & V_3 -> V_3 ,
L_53 ) ;
F_65 ( V_4 ) ;
}
V_79:
if ( V_4 )
F_25 ( V_4 ) ;
F_41 ( & V_32 ) ;
return V_65 ;
}
static void F_82 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_3 -> V_3 , L_54 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_38 ( & V_32 ) ;
V_4 = F_27 ( F_15 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_30 ( V_3 -> V_17 ) ,
F_31 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_29 ) {
F_49 ( & V_3 -> V_3 ,
V_38 L_44 ) ;
goto V_79;
}
if ( ! V_4 -> V_29 -> V_70 ) {
F_49 ( & V_3 -> V_3 , V_38 L_45
L_46 ) ;
F_65 ( V_4 ) ;
goto V_79;
}
if ( ! F_76 ( V_80 ,
( unsigned long * ) & V_4 -> V_29 -> V_70 -> V_25 ) ) {
F_49 ( & V_3 -> V_3 ,
L_47 ) ;
F_65 ( V_4 ) ;
goto V_79;
}
F_70 ( V_4 , 1 , V_86 ,
V_78 ) ;
V_79:
if ( V_4 )
F_25 ( V_4 ) ;
F_41 ( & V_32 ) ;
return;
}
static inline int F_83 ( const char * V_87 , int * V_22 , int * V_15 ,
int * V_23 , int * V_24 )
{
int V_88 = 0 ;
switch ( sscanf ( V_87 , L_55 , V_22 , V_15 , V_23 , V_24 ,
& V_88 ) ) {
case 3 :
* V_24 = - 1 ;
sscanf ( V_87 , L_56 , V_22 , V_15 , V_23 , & V_88 ) ;
break;
case 2 :
* V_23 = * V_24 = - 1 ;
sscanf ( V_87 , L_57 , V_22 , V_15 , & V_88 ) ;
break;
}
if ( V_88 && ! V_87 [ V_88 ] )
return 0 ;
* V_22 = 0 ;
switch ( sscanf ( V_87 , L_58 , V_15 , V_23 , V_24 , & V_88 ) ) {
case 2 :
* V_24 = - 1 ;
sscanf ( V_87 , L_59 , V_15 , V_23 , & V_88 ) ;
break;
case 1 :
* V_23 = * V_24 = - 1 ;
sscanf ( V_87 , L_60 , V_15 , & V_88 ) ;
break;
}
if ( V_88 && ! V_87 [ V_88 ] )
return 0 ;
return - V_89 ;
}
static inline int F_84 ( const char * V_87 , int * V_22 , int * V_15 , int
* V_23 , int * V_24 , int * V_90 , int * V_91 , int * V_92 )
{
int V_88 = 0 ;
sscanf ( V_87 , L_61 , V_22 , V_15 , V_23 , V_24 ,
V_90 , V_91 , V_92 , & V_88 ) ;
if ( V_88 && ! V_87 [ V_88 ] )
return 0 ;
* V_22 = 0 ;
sscanf ( V_87 , L_62 , V_15 , V_23 , V_24 , V_90 , V_91 ,
V_92 , & V_88 ) ;
if ( V_88 && ! V_87 [ V_88 ] )
return 0 ;
return - V_89 ;
}
static int F_85 ( int V_22 , int V_15 , int V_23 , int V_24 )
{
struct V_33 * V_93 ;
unsigned long V_25 ;
int V_94 = 0 , V_17 = F_86 ( V_23 , V_24 ) ;
if ( V_23 < 0 ) {
for ( V_23 = 0 ; ! V_94 && V_23 < 32 ; ++ V_23 )
V_94 = F_85 ( V_22 , V_15 , V_23 , V_24 ) ;
return V_94 ;
}
if ( V_24 < 0 ) {
for ( V_24 = 0 ; ! V_94 && V_24 < 8 ; ++ V_24 )
V_94 = F_85 ( V_22 , V_15 , V_23 , V_24 ) ;
return V_94 ;
}
if ( (
#if ! F_87 ( V_95 ) \
|| ! F_87 ( V_96 )
! V_97 ? V_22 :
#endif
V_22 < 0 || V_22 > 0xffff )
|| V_15 < 0 || V_15 > 0xff
|| F_30 ( V_17 ) != V_23
|| F_31 ( V_17 ) != V_24 )
return - V_89 ;
V_93 = F_88 ( sizeof( * V_93 ) , V_98 ) ;
if ( ! V_93 )
return - V_39 ;
V_93 -> V_22 = V_22 ;
V_93 -> V_15 = V_15 ;
V_93 -> V_17 = V_17 ;
F_53 ( V_38 L_63 ,
V_22 , V_15 , V_23 , V_24 ) ;
F_28 ( & V_37 , V_25 ) ;
F_56 ( & V_93 -> V_99 , & V_100 ) ;
F_32 ( & V_37 , V_25 ) ;
return 0 ;
}
static int F_89 ( int V_22 , int V_15 , int V_23 , int V_24 )
{
struct V_33 * V_93 , * V_101 ;
int V_18 = - V_102 ;
unsigned long V_25 ;
F_28 ( & V_37 , V_25 ) ;
F_90 (pci_dev_id, t, &pcistub_device_ids,
slot_list) {
if ( V_93 -> V_22 == V_22 && V_93 -> V_15 == V_15
&& ( V_23 < 0 || F_30 ( V_93 -> V_17 ) == V_23 )
&& ( V_24 < 0 || F_31 ( V_93 -> V_17 ) == V_24 ) ) {
F_55 ( & V_93 -> V_99 ) ;
F_5 ( V_93 ) ;
V_18 = 0 ;
F_53 ( V_38 L_64
L_65 , V_22 , V_15 , V_23 , V_24 ) ;
}
}
F_32 ( & V_37 , V_25 ) ;
return V_18 ;
}
static int F_91 ( int V_22 , int V_15 , int V_23 , int V_24 ,
unsigned int V_90 , unsigned int V_91 ,
unsigned int V_92 )
{
int V_18 = 0 ;
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_103 * V_104 ;
if ( V_90 > 0xfff || ( V_91 < 4 && ( V_92 >> ( V_91 * 8 ) ) ) )
return - V_89 ;
V_4 = F_27 ( V_22 , V_15 , V_23 , V_24 ) ;
if ( ! V_4 ) {
V_18 = - V_54 ;
goto V_27;
}
V_3 = V_4 -> V_3 ;
V_104 = F_3 ( sizeof( * V_104 ) , V_5 ) ;
if ( ! V_104 ) {
V_18 = - V_39 ;
goto V_27;
}
V_104 -> V_105 = V_90 ;
V_104 -> V_91 = V_91 ;
V_104 -> V_92 = V_92 ;
V_104 -> V_106 = NULL ;
V_104 -> V_107 = NULL ;
V_104 -> V_108 = NULL ;
V_104 -> V_109 = V_110 ;
V_18 = F_92 ( V_3 , V_104 ) ;
if ( V_18 )
F_5 ( V_104 ) ;
V_27:
if ( V_4 )
F_25 ( V_4 ) ;
return V_18 ;
}
static T_4 F_93 ( struct V_111 * V_112 , const char * V_87 ,
T_5 V_113 )
{
int V_22 , V_15 , V_23 , V_24 ;
int V_18 ;
V_18 = F_83 ( V_87 , & V_22 , & V_15 , & V_23 , & V_24 ) ;
if ( V_18 )
goto V_27;
V_18 = F_85 ( V_22 , V_15 , V_23 , V_24 ) ;
V_27:
if ( ! V_18 )
V_18 = V_113 ;
return V_18 ;
}
static T_4 F_94 ( struct V_111 * V_112 , const char * V_87 ,
T_5 V_113 )
{
int V_22 , V_15 , V_23 , V_24 ;
int V_18 ;
V_18 = F_83 ( V_87 , & V_22 , & V_15 , & V_23 , & V_24 ) ;
if ( V_18 )
goto V_27;
V_18 = F_89 ( V_22 , V_15 , V_23 , V_24 ) ;
V_27:
if ( ! V_18 )
V_18 = V_113 ;
return V_18 ;
}
static T_4 F_95 ( struct V_111 * V_112 , char * V_87 )
{
struct V_33 * V_93 ;
T_5 V_113 = 0 ;
unsigned long V_25 ;
F_28 ( & V_37 , V_25 ) ;
F_29 (pci_dev_id, &pcistub_device_ids, slot_list) {
if ( V_113 >= V_114 )
break;
V_113 += F_96 ( V_87 + V_113 , V_114 - V_113 ,
L_66 ,
V_93 -> V_22 , V_93 -> V_15 ,
F_30 ( V_93 -> V_17 ) ,
F_31 ( V_93 -> V_17 ) ) ;
}
F_32 ( & V_37 , V_25 ) ;
return V_113 ;
}
static T_4 F_97 ( struct V_111 * V_112 , char * V_87 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
T_5 V_113 = 0 ;
unsigned long V_25 ;
F_28 ( & V_26 , V_25 ) ;
F_29 (psdev, &pcistub_devices, dev_list) {
if ( V_113 >= V_114 )
break;
if ( ! V_4 -> V_3 )
continue;
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 )
continue;
V_113 +=
F_96 ( V_87 + V_113 , V_114 - V_113 ,
L_67 ,
F_45 ( V_4 -> V_3 ) ,
V_9 -> V_115 ? L_68 : L_69 ,
V_9 -> V_116 ? L_70 : L_71 ,
V_9 -> V_117 ) ;
}
F_32 ( & V_26 , V_25 ) ;
return V_113 ;
}
static T_4 F_98 ( struct V_111 * V_112 ,
const char * V_87 ,
T_5 V_113 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
int V_22 , V_15 , V_23 , V_24 ;
int V_18 = - V_102 ;
V_18 = F_83 ( V_87 , & V_22 , & V_15 , & V_23 , & V_24 ) ;
if ( V_18 )
return V_18 ;
V_4 = F_27 ( V_22 , V_15 , V_23 , V_24 ) ;
if ( ! V_4 )
goto V_27;
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 )
goto V_27;
F_2 ( & V_4 -> V_3 -> V_3 , L_72 ,
V_9 -> V_40 , V_9 -> V_115 ,
! V_9 -> V_115 ) ;
V_9 -> V_115 = ! ( V_9 -> V_115 ) ;
if ( V_9 -> V_115 )
V_9 -> V_116 = 1 ;
V_27:
if ( V_4 )
F_25 ( V_4 ) ;
if ( ! V_18 )
V_18 = V_113 ;
return V_18 ;
}
static T_4 F_99 ( struct V_111 * V_112 , const char * V_87 ,
T_5 V_113 )
{
int V_22 , V_15 , V_23 , V_24 , V_90 , V_91 , V_92 ;
int V_18 ;
V_18 = F_84 ( V_87 , & V_22 , & V_15 , & V_23 , & V_24 , & V_90 , & V_91 ,
& V_92 ) ;
if ( V_18 )
goto V_27;
V_18 = F_91 ( V_22 , V_15 , V_23 , V_24 , V_90 , V_91 , V_92 ) ;
V_27:
if ( ! V_18 )
V_18 = V_113 ;
return V_18 ;
}
static T_4 F_100 ( struct V_111 * V_112 , char * V_87 )
{
int V_113 = 0 ;
unsigned long V_25 ;
struct V_118 * V_119 ;
struct V_8 * V_9 ;
const struct V_103 * V_104 ;
const struct V_120 * V_121 ;
F_28 ( & V_37 , V_25 ) ;
F_29 (quirk, &xen_pcibk_quirks, quirks_list) {
if ( V_113 >= V_114 )
goto V_27;
V_113 += F_96 ( V_87 + V_113 , V_114 - V_113 ,
L_73 ,
V_119 -> V_29 -> V_15 -> V_16 ,
F_30 ( V_119 -> V_29 -> V_17 ) ,
F_31 ( V_119 -> V_29 -> V_17 ) ,
V_119 -> V_122 . V_123 , V_119 -> V_122 . V_124 ,
V_119 -> V_122 . V_125 ,
V_119 -> V_122 . V_126 ) ;
V_9 = F_10 ( V_119 -> V_29 ) ;
F_29 (cfg_entry, &dev_data->config_fields, list) {
V_104 = V_121 -> V_104 ;
if ( V_113 >= V_114 )
goto V_27;
V_113 += F_96 ( V_87 + V_113 , V_114 - V_113 ,
L_74 ,
V_121 -> V_127 +
V_104 -> V_105 , V_104 -> V_91 ,
V_104 -> V_92 ) ;
}
}
V_27:
F_32 ( & V_37 , V_25 ) ;
return V_113 ;
}
static T_4 F_101 ( struct V_111 * V_112 , const char * V_87 ,
T_5 V_113 )
{
int V_22 , V_15 , V_23 , V_24 ;
int V_18 ;
struct V_1 * V_4 ;
struct V_8 * V_9 ;
V_18 = F_83 ( V_87 , & V_22 , & V_15 , & V_23 , & V_24 ) ;
if ( V_18 )
goto V_27;
V_4 = F_27 ( V_22 , V_15 , V_23 , V_24 ) ;
if ( ! V_4 ) {
V_18 = - V_54 ;
goto V_27;
}
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 ) {
V_18 = - V_128 ;
goto V_108;
}
if ( ! V_9 -> V_129 ) {
V_9 -> V_129 = 1 ;
F_17 ( & V_4 -> V_3 -> V_3 , L_75
L_76 ) ;
F_17 ( & V_4 -> V_3 -> V_3 ,
L_77 ) ;
}
V_108:
F_25 ( V_4 ) ;
V_27:
if ( ! V_18 )
V_18 = V_113 ;
return V_18 ;
}
static T_4 F_102 ( struct V_111 * V_112 , char * V_87 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
T_5 V_113 = 0 ;
unsigned long V_25 ;
F_28 ( & V_26 , V_25 ) ;
F_29 (psdev, &pcistub_devices, dev_list) {
if ( V_113 >= V_114 )
break;
if ( ! V_4 -> V_3 )
continue;
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 || ! V_9 -> V_129 )
continue;
V_113 +=
F_96 ( V_87 + V_113 , V_114 - V_113 , L_78 ,
F_45 ( V_4 -> V_3 ) ) ;
}
F_32 ( & V_26 , V_25 ) ;
return V_113 ;
}
static void F_103 ( void )
{
F_104 ( & V_130 . V_131 , & V_132 ) ;
F_104 ( & V_130 . V_131 ,
& V_133 ) ;
F_104 ( & V_130 . V_131 , & V_134 ) ;
F_104 ( & V_130 . V_131 , & V_135 ) ;
F_104 ( & V_130 . V_131 ,
& V_136 ) ;
F_104 ( & V_130 . V_131 ,
& V_137 ) ;
F_104 ( & V_130 . V_131 ,
& V_138 ) ;
F_105 ( & V_130 ) ;
}
static int T_1 F_106 ( void )
{
int V_139 = 0 ;
int V_18 = 0 ;
int V_22 , V_15 , V_23 , V_24 ;
int V_88 ;
if ( V_140 && * V_140 ) {
do {
V_88 = 0 ;
V_18 = sscanf ( V_140 + V_139 ,
L_79 ,
& V_22 , & V_15 , & V_23 , & V_24 , & V_88 ) ;
switch ( V_18 ) {
case 3 :
V_24 = - 1 ;
sscanf ( V_140 + V_139 ,
L_80 ,
& V_22 , & V_15 , & V_23 , & V_88 ) ;
break;
case 2 :
V_23 = V_24 = - 1 ;
sscanf ( V_140 + V_139 ,
L_81 ,
& V_22 , & V_15 , & V_88 ) ;
break;
}
if ( ! V_88 ) {
V_22 = 0 ;
V_18 = sscanf ( V_140 + V_139 ,
L_82 ,
& V_15 , & V_23 , & V_24 , & V_88 ) ;
switch ( V_18 ) {
case 2 :
V_24 = - 1 ;
sscanf ( V_140 + V_139 ,
L_83 ,
& V_15 , & V_23 , & V_88 ) ;
break;
case 1 :
V_23 = V_24 = - 1 ;
sscanf ( V_140 + V_139 ,
L_84 ,
& V_15 , & V_88 ) ;
break;
}
}
if ( V_88 <= 0 )
goto V_141;
V_18 = F_85 ( V_22 , V_15 , V_23 , V_24 ) ;
if ( V_18 )
goto V_27;
V_139 += V_88 ;
} while ( V_140 [ V_139 ] );
}
V_18 = F_107 ( & V_130 ) ;
if ( V_18 < 0 )
goto V_27;
V_18 = F_108 ( & V_130 . V_131 ,
& V_132 ) ;
if ( ! V_18 )
V_18 = F_108 ( & V_130 . V_131 ,
& V_133 ) ;
if ( ! V_18 )
V_18 = F_108 ( & V_130 . V_131 ,
& V_134 ) ;
if ( ! V_18 )
V_18 = F_108 ( & V_130 . V_131 ,
& V_135 ) ;
if ( ! V_18 )
V_18 = F_108 ( & V_130 . V_131 ,
& V_136 ) ;
if ( ! V_18 )
V_18 = F_108 ( & V_130 . V_131 ,
& V_137 ) ;
if ( ! V_18 )
V_18 = F_108 ( & V_130 . V_131 ,
& V_138 ) ;
if ( V_18 )
F_103 () ;
V_27:
return V_18 ;
V_141:
F_63 (KERN_ERR DRV_NAME L_85 ,
pci_devs_to_hide + pos) ;
return - V_89 ;
}
static int T_1 F_109 ( void )
{
int V_18 ;
if ( ! F_110 () )
return - V_54 ;
V_18 = F_111 () ;
if ( V_18 )
return V_18 ;
#ifdef V_95
V_18 = F_106 () ;
if ( V_18 < 0 )
return V_18 ;
#endif
F_52 () ;
V_18 = F_112 () ;
if ( V_18 )
F_103 () ;
return V_18 ;
}
static void T_6 F_113 ( void )
{
F_114 () ;
F_103 () ;
}
