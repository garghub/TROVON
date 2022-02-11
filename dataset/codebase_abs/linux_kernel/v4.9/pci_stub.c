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
F_14 ( & V_3 -> V_3 , L_3 ) ;
else
F_15 ( V_3 ) ;
if ( V_3 -> V_11 ) {
struct V_12 V_13 = {
. V_14 = F_16 ( V_3 -> V_15 ) ,
. V_15 = V_3 -> V_15 -> V_16 ,
. V_17 = V_3 -> V_17
} ;
int V_18 = F_17 ( V_19 ,
& V_13 ) ;
if ( V_18 && V_18 != - V_20 )
F_18 ( & V_3 -> V_3 , L_4 ,
V_18 ) ;
}
F_19 ( V_3 ) ;
F_5 ( V_9 ) ;
F_20 ( V_3 , NULL ) ;
F_21 ( V_3 ) ;
F_22 ( V_3 ) ;
F_23 ( V_3 ) ;
F_24 ( V_3 ) ;
F_5 ( V_4 ) ;
}
static inline void F_25 ( struct V_1 * V_4 )
{
F_26 ( & V_4 -> V_6 ) ;
}
static inline void F_27 ( struct V_1 * V_4 )
{
F_28 ( & V_4 -> V_6 , F_8 ) ;
}
static struct V_1 * F_29 ( int V_21 , int V_15 ,
int V_22 , int V_23 )
{
struct V_1 * V_4 ;
F_30 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 != NULL
&& V_21 == F_16 ( V_4 -> V_3 -> V_15 )
&& V_15 == V_4 -> V_3 -> V_15 -> V_16
&& V_22 == F_31 ( V_4 -> V_3 -> V_17 )
&& V_23 == F_32 ( V_4 -> V_3 -> V_17 ) ) {
return V_4 ;
}
}
return NULL ;
}
static struct V_1 * F_33 ( int V_21 , int V_15 ,
int V_22 , int V_23 )
{
struct V_1 * V_4 ;
unsigned long V_24 ;
F_34 ( & V_25 , V_24 ) ;
V_4 = F_29 ( V_21 , V_15 , V_22 , V_23 ) ;
if ( V_4 )
F_25 ( V_4 ) ;
F_35 ( & V_25 , V_24 ) ;
return V_4 ;
}
static struct V_2 * F_36 ( struct V_26 * V_27 ,
struct V_1 * V_4 )
{
struct V_2 * V_2 = NULL ;
unsigned long V_24 ;
F_25 ( V_4 ) ;
F_34 ( & V_4 -> V_7 , V_24 ) ;
if ( ! V_4 -> V_27 ) {
V_4 -> V_27 = V_27 ;
V_2 = V_4 -> V_3 ;
}
F_35 ( & V_4 -> V_7 , V_24 ) ;
if ( ! V_2 )
F_27 ( V_4 ) ;
return V_2 ;
}
struct V_2 * F_37 ( struct V_26 * V_27 ,
int V_21 , int V_15 ,
int V_22 , int V_23 )
{
struct V_1 * V_4 ;
struct V_2 * V_28 = NULL ;
unsigned long V_24 ;
F_34 ( & V_25 , V_24 ) ;
V_4 = F_29 ( V_21 , V_15 , V_22 , V_23 ) ;
if ( V_4 )
V_28 = F_36 ( V_27 , V_4 ) ;
F_35 ( & V_25 , V_24 ) ;
return V_28 ;
}
struct V_2 * F_38 ( struct V_26 * V_27 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_2 * V_28 = NULL ;
unsigned long V_24 ;
F_34 ( & V_25 , V_24 ) ;
F_30 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_28 = F_36 ( V_27 , V_4 ) ;
break;
}
}
F_35 ( & V_25 , V_24 ) ;
return V_28 ;
}
void F_39 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_29 = NULL ;
unsigned long V_24 ;
struct V_8 * V_9 ;
int V_30 ;
F_34 ( & V_25 , V_24 ) ;
F_30 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_29 = V_4 ;
break;
}
}
F_35 ( & V_25 , V_24 ) ;
if ( F_40 ( ! V_29 ) )
return;
F_41 ( & V_31 ) ;
F_42 ( & V_3 -> V_3 ) ;
F_12 ( V_3 ) ;
V_9 = F_10 ( V_3 ) ;
V_30 = F_43 ( V_3 , V_9 -> V_10 ) ;
if ( ! V_30 ) {
F_15 ( V_3 ) ;
} else
F_14 ( & V_3 -> V_3 , L_3 ) ;
F_19 ( V_3 ) ;
F_44 ( V_3 ) ;
F_21 ( V_3 ) ;
F_11 ( V_3 ) ;
F_34 ( & V_29 -> V_7 , V_24 ) ;
V_29 -> V_27 = NULL ;
F_35 ( & V_29 -> V_7 , V_24 ) ;
F_27 ( V_29 ) ;
F_45 ( & V_31 ) ;
}
static int F_46 ( struct V_2 * V_3 ,
struct V_32 * V_33 )
{
for (; V_3 != NULL ; V_3 = V_3 -> V_15 -> V_34 ) {
if ( F_16 ( V_3 -> V_15 ) == V_33 -> V_21
&& V_3 -> V_15 -> V_16 == V_33 -> V_15
&& V_3 -> V_17 == V_33 -> V_17 )
return 1 ;
if ( V_3 == V_3 -> V_15 -> V_34 )
break;
}
return 0 ;
}
static int F_47 ( struct V_2 * V_3 )
{
struct V_32 * V_33 ;
unsigned long V_24 ;
int V_35 = 0 ;
F_34 ( & V_36 , V_24 ) ;
F_30 (pdev_id, &pcistub_device_ids, slot_list) {
if ( F_46 ( V_3 , V_33 ) ) {
V_35 = 1 ;
break;
}
}
F_35 ( & V_36 , V_24 ) ;
return V_35 ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_8 * V_9 ;
int V_18 = 0 ;
F_2 ( & V_3 -> V_3 , L_5 ) ;
V_9 = F_3 ( sizeof( * V_9 ) + strlen ( V_37 L_6 )
+ strlen ( F_49 ( V_3 ) ) + 1 , V_5 ) ;
if ( ! V_9 ) {
V_18 = - V_38 ;
goto V_39;
}
F_20 ( V_3 , V_9 ) ;
sprintf ( V_9 -> V_40 , V_37 L_7 , F_49 ( V_3 ) ) ;
F_2 ( & V_3 -> V_3 , L_8 ) ;
F_50 ( & V_41 ) ;
V_18 = F_51 ( V_3 ) ;
if ( V_18 )
goto V_39;
F_2 ( & V_3 -> V_3 , L_9 ) ;
V_18 = F_52 ( V_3 ) ;
if ( V_18 )
goto V_42;
if ( V_3 -> V_11 ) {
struct V_12 V_13 = {
. V_14 = F_16 ( V_3 -> V_15 ) ,
. V_15 = V_3 -> V_15 -> V_16 ,
. V_17 = V_3 -> V_17
} ;
V_18 = F_17 ( V_43 , & V_13 ) ;
if ( V_18 && V_18 != - V_20 )
F_53 ( & V_3 -> V_3 , L_10 ,
V_18 ) ;
}
F_2 ( & V_3 -> V_3 , L_11 ) ;
F_54 ( V_3 ) ;
V_9 -> V_10 = F_55 ( V_3 ) ;
if ( ! V_9 -> V_10 )
F_53 ( & V_3 -> V_3 , L_12 ) ;
else {
F_2 ( & V_3 -> V_3 , L_13 ) ;
F_12 ( V_3 ) ;
F_15 ( V_3 ) ;
}
F_2 ( & V_3 -> V_3 , L_14 ) ;
F_19 ( V_3 ) ;
F_56 ( V_3 ) ;
return 0 ;
V_42:
F_22 ( V_3 ) ;
V_39:
F_20 ( V_3 , NULL ) ;
F_5 ( V_9 ) ;
return V_18 ;
}
static int T_1 F_57 ( void )
{
struct V_1 * V_4 ;
unsigned long V_24 ;
int V_18 = 0 ;
F_34 ( & V_25 , V_24 ) ;
while ( ! F_58 ( & V_44 ) ) {
V_4 = F_9 ( V_44 . V_45 ,
struct V_1 , V_46 ) ;
F_59 ( & V_4 -> V_46 ) ;
F_35 ( & V_25 , V_24 ) ;
V_18 = F_48 ( V_4 -> V_3 ) ;
if ( V_18 ) {
F_53 ( & V_4 -> V_3 -> V_3 ,
L_15 , V_18 ) ;
F_5 ( V_4 ) ;
V_4 = NULL ;
}
F_34 ( & V_25 , V_24 ) ;
if ( V_4 )
F_60 ( & V_4 -> V_46 , & V_47 ) ;
}
V_48 = 1 ;
F_35 ( & V_25 , V_24 ) ;
return 0 ;
}
static void F_61 ( struct V_32 * V_49 ,
int V_21 , int V_15 , unsigned int V_17 )
{
struct V_32 * V_50 ;
unsigned long V_24 ;
int V_35 = 0 ;
F_34 ( & V_36 , V_24 ) ;
F_30 (pci_dev_id, &pcistub_device_ids, slot_list) {
if ( V_50 -> V_21 == V_21 && V_50 -> V_15 == V_15 &&
V_50 -> V_17 == V_17 ) {
V_35 = 1 ;
break;
}
}
if ( ! V_35 ) {
V_49 -> V_21 = V_21 ;
V_49 -> V_15 = V_15 ;
V_49 -> V_17 = V_17 ;
F_60 ( & V_49 -> V_51 , & V_52 ) ;
}
F_35 ( & V_36 , V_24 ) ;
if ( V_35 )
F_5 ( V_49 ) ;
}
static int F_62 ( struct V_2 * V_3 ,
struct V_32 * V_50 )
{
struct V_1 * V_4 ;
unsigned long V_24 ;
int V_18 = 0 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
F_5 ( V_50 ) ;
return - V_38 ;
}
F_34 ( & V_25 , V_24 ) ;
if ( V_48 ) {
F_35 ( & V_25 , V_24 ) ;
V_18 = F_48 ( V_4 -> V_3 ) ;
F_34 ( & V_25 , V_24 ) ;
if ( ! V_18 )
F_63 ( & V_4 -> V_46 , & V_47 ) ;
} else {
F_2 ( & V_3 -> V_3 , L_16 ) ;
F_63 ( & V_4 -> V_46 , & V_44 ) ;
}
F_35 ( & V_25 , V_24 ) ;
if ( V_18 ) {
F_5 ( V_50 ) ;
F_27 ( V_4 ) ;
} else if ( V_50 )
F_61 ( V_50 , F_16 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
return V_18 ;
}
static int F_64 ( struct V_2 * V_3 , const struct V_53 * V_54 )
{
int V_18 = 0 , V_55 ;
struct V_32 * V_50 = NULL ;
F_2 ( & V_3 -> V_3 , L_17 ) ;
V_55 = F_47 ( V_3 ) ;
if ( ( V_3 -> V_56 &&
! strcmp ( V_3 -> V_56 , V_57 ) ) ||
V_55 ) {
if ( V_3 -> V_58 != V_59
&& V_3 -> V_58 != V_60 ) {
F_53 ( & V_3 -> V_3 , L_18
L_19
L_20 ) ;
V_18 = - V_61 ;
goto V_39;
}
if ( ! V_55 ) {
V_50 = F_65 ( sizeof( * V_50 ) , V_5 ) ;
if ( ! V_50 ) {
V_18 = - V_38 ;
goto V_39;
}
}
F_14 ( & V_3 -> V_3 , L_21 ) ;
V_18 = F_62 ( V_3 , V_50 ) ;
} else
V_18 = - V_61 ;
V_39:
return V_18 ;
}
static void F_66 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_29 = NULL ;
unsigned long V_24 ;
F_2 ( & V_3 -> V_3 , L_22 ) ;
F_34 ( & V_25 , V_24 ) ;
F_67 ( V_3 ) ;
F_30 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_29 = V_4 ;
break;
}
}
F_35 ( & V_25 , V_24 ) ;
if ( V_29 ) {
F_2 ( & V_3 -> V_3 , L_23 ,
V_29 -> V_27 ? L_24 : L_25 ) ;
if ( V_29 -> V_27 ) {
int V_62 = F_68 ( V_3 ) ;
F_69 ( L_26 ,
F_49 ( V_29 -> V_3 ) , V_62 ) ;
F_69 ( L_27 ) ;
F_69 ( L_28 ) ;
F_69 ( L_29 ) ;
F_70 ( V_29 -> V_27 ,
V_29 -> V_3 ,
false ) ;
}
F_34 ( & V_25 , V_24 ) ;
F_59 ( & V_29 -> V_46 ) ;
F_35 ( & V_25 , V_24 ) ;
F_27 ( V_29 ) ;
}
}
static void F_71 ( struct V_1 * V_4 )
{
struct V_63 V_64 ;
int V_18 ;
char V_65 [ V_66 ] ;
F_72 ( ! V_4 ) ;
snprintf ( V_65 , V_66 , L_30 ,
V_4 -> V_27 -> V_67 -> V_68 ) ;
V_69:
V_18 = F_73 ( & V_64 ) ;
if ( V_18 ) {
F_53 ( & V_4 -> V_3 -> V_3 ,
L_31 , V_18 ) ;
return;
}
F_74 ( V_64 , V_65 , L_32 , L_33 ) ;
V_18 = F_75 ( V_64 , 0 ) ;
if ( V_18 ) {
if ( V_18 == - V_70 )
goto V_69;
F_53 ( & V_4 -> V_3 -> V_3 ,
L_34 , V_18 ) ;
return;
}
}
static T_2 F_76 ( struct V_1 * V_4 ,
T_3 V_71 , int V_72 ,
T_2 V_73 )
{
T_2 V_74 = V_73 ;
struct V_75 * V_76 ;
struct V_26 * V_27 = V_4 -> V_27 ;
struct V_77 * V_78 = V_27 -> V_78 ;
int V_30 ;
V_76 = & ( V_78 -> V_76 ) ;
V_76 -> V_79 = V_72 ;
V_76 -> V_18 = V_71 ;
V_30 = F_77 ( V_4 -> V_3 , V_4 -> V_27 ,
& V_76 -> V_21 , & V_76 -> V_15 , & V_76 -> V_17 ) ;
if ( ! V_30 ) {
F_53 ( & V_4 -> V_3 -> V_3 ,
V_37 L_35 ) ;
return V_80 ;
}
F_78 () ;
F_2 ( & V_4 -> V_3 -> V_3 ,
V_37 L_36 ,
V_72 , V_76 -> V_21 , V_76 -> V_15 , V_76 -> V_17 ) ;
F_79 ( V_81 , ( unsigned long * ) & V_27 -> V_24 ) ;
F_79 ( V_82 ,
( unsigned long * ) & V_78 -> V_24 ) ;
F_78 () ;
F_80 ( V_27 -> V_83 ) ;
V_30 = F_81 ( V_41 ,
! ( F_82 ( V_82 , ( unsigned long * )
& V_78 -> V_24 ) ) , 300 * V_84 ) ;
if ( ! V_30 ) {
if ( F_82 ( V_82 ,
( unsigned long * ) & V_78 -> V_24 ) ) {
F_53 ( & V_4 -> V_3 -> V_3 ,
L_37 ) ;
F_83 ( V_82 ,
( unsigned long * ) & V_78 -> V_24 ) ;
V_76 -> V_18 = V_80 ;
return V_74 ;
}
}
F_83 ( V_81 , ( unsigned long * ) & V_27 -> V_24 ) ;
if ( F_82 ( V_85 ,
( unsigned long * ) & V_78 -> V_24 ) ) {
F_2 ( & V_4 -> V_3 -> V_3 ,
L_38 V_37 L_39 ) ;
F_84 ( V_4 -> V_27 ) ;
}
V_74 = ( T_2 ) V_76 -> V_18 ;
return V_74 ;
}
static T_2 F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
T_2 V_73 ;
V_73 = V_86 ;
F_2 ( & V_3 -> V_3 , L_40 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_41 ( & V_31 ) ;
V_4 = F_33 ( F_16 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_31 ( V_3 -> V_17 ) ,
F_32 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_27 ) {
F_53 ( & V_3 -> V_3 ,
V_37 L_41 ) ;
goto V_87;
}
if ( ! V_4 -> V_27 -> V_78 ) {
F_53 ( & V_3 -> V_3 , V_37 L_42
L_43 ) ;
F_71 ( V_4 ) ;
goto V_87;
}
if ( ! F_82 ( V_88 ,
( unsigned long * ) & V_4 -> V_27 -> V_78 -> V_24 ) ) {
F_53 ( & V_3 -> V_3 ,
L_44 ) ;
goto V_87;
}
V_73 = F_76 ( V_4 , 1 , V_89 , V_73 ) ;
if ( V_73 == V_80 ||
V_73 == V_90 ) {
F_2 ( & V_3 -> V_3 ,
L_45 ) ;
F_71 ( V_4 ) ;
}
V_87:
if ( V_4 )
F_27 ( V_4 ) ;
F_45 ( & V_31 ) ;
return V_73 ;
}
static T_2 F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
T_2 V_73 ;
V_73 = V_86 ;
F_2 ( & V_3 -> V_3 , L_46 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_41 ( & V_31 ) ;
V_4 = F_33 ( F_16 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_31 ( V_3 -> V_17 ) ,
F_32 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_27 ) {
F_53 ( & V_3 -> V_3 ,
V_37 L_41 ) ;
goto V_87;
}
if ( ! V_4 -> V_27 -> V_78 ) {
F_53 ( & V_3 -> V_3 , V_37 L_42
L_43 ) ;
F_71 ( V_4 ) ;
goto V_87;
}
if ( ! F_82 ( V_88 ,
( unsigned long * ) & V_4 -> V_27 -> V_78 -> V_24 ) ) {
F_53 ( & V_3 -> V_3 ,
L_44 ) ;
goto V_87;
}
V_73 = F_76 ( V_4 , 1 , V_91 , V_73 ) ;
if ( V_73 == V_80 ||
V_73 == V_90 ) {
F_2 ( & V_3 -> V_3 ,
L_47 ) ;
F_71 ( V_4 ) ;
}
V_87:
if ( V_4 )
F_27 ( V_4 ) ;
F_45 ( & V_31 ) ;
return V_73 ;
}
static T_2 F_87 ( struct V_2 * V_3 ,
T_3 error )
{
struct V_1 * V_4 ;
T_2 V_73 ;
V_73 = V_92 ;
F_2 ( & V_3 -> V_3 , L_48 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_41 ( & V_31 ) ;
V_4 = F_33 ( F_16 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_31 ( V_3 -> V_17 ) ,
F_32 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_27 ) {
F_53 ( & V_3 -> V_3 ,
V_37 L_41 ) ;
goto V_87;
}
if ( ! V_4 -> V_27 -> V_78 ) {
F_53 ( & V_3 -> V_3 , V_37 L_42
L_43 ) ;
F_71 ( V_4 ) ;
goto V_87;
}
if ( ! F_82 ( V_88 ,
( unsigned long * ) & V_4 -> V_27 -> V_78 -> V_24 ) ) {
F_2 ( & V_3 -> V_3 , L_49 ) ;
F_71 ( V_4 ) ;
goto V_87;
}
V_73 = F_76 ( V_4 , error , V_93 , V_73 ) ;
if ( V_73 == V_80 ||
V_73 == V_90 ) {
F_2 ( & V_3 -> V_3 ,
L_50 ) ;
F_71 ( V_4 ) ;
}
V_87:
if ( V_4 )
F_27 ( V_4 ) ;
F_45 ( & V_31 ) ;
return V_73 ;
}
static void F_88 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_3 -> V_3 , L_51 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_41 ( & V_31 ) ;
V_4 = F_33 ( F_16 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_31 ( V_3 -> V_17 ) ,
F_32 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_27 ) {
F_53 ( & V_3 -> V_3 ,
V_37 L_41 ) ;
goto V_87;
}
if ( ! V_4 -> V_27 -> V_78 ) {
F_53 ( & V_3 -> V_3 , V_37 L_42
L_43 ) ;
F_71 ( V_4 ) ;
goto V_87;
}
if ( ! F_82 ( V_88 ,
( unsigned long * ) & V_4 -> V_27 -> V_78 -> V_24 ) ) {
F_53 ( & V_3 -> V_3 ,
L_44 ) ;
F_71 ( V_4 ) ;
goto V_87;
}
F_76 ( V_4 , 1 , V_94 ,
V_86 ) ;
V_87:
if ( V_4 )
F_27 ( V_4 ) ;
F_45 ( & V_31 ) ;
return;
}
static inline int F_89 ( const char * V_95 , int * V_21 , int * V_15 ,
int * V_22 , int * V_23 )
{
int V_96 = 0 ;
switch ( sscanf ( V_95 , L_52 , V_21 , V_15 , V_22 , V_23 ,
& V_96 ) ) {
case 3 :
* V_23 = - 1 ;
sscanf ( V_95 , L_53 , V_21 , V_15 , V_22 , & V_96 ) ;
break;
case 2 :
* V_22 = * V_23 = - 1 ;
sscanf ( V_95 , L_54 , V_21 , V_15 , & V_96 ) ;
break;
}
if ( V_96 && ! V_95 [ V_96 ] )
return 0 ;
* V_21 = 0 ;
switch ( sscanf ( V_95 , L_55 , V_15 , V_22 , V_23 , & V_96 ) ) {
case 2 :
* V_23 = - 1 ;
sscanf ( V_95 , L_56 , V_15 , V_22 , & V_96 ) ;
break;
case 1 :
* V_22 = * V_23 = - 1 ;
sscanf ( V_95 , L_57 , V_15 , & V_96 ) ;
break;
}
if ( V_96 && ! V_95 [ V_96 ] )
return 0 ;
return - V_97 ;
}
static inline int F_90 ( const char * V_95 , int * V_21 , int * V_15 , int
* V_22 , int * V_23 , int * V_98 , int * V_99 , int * V_100 )
{
int V_96 = 0 ;
sscanf ( V_95 , L_58 , V_21 , V_15 , V_22 , V_23 ,
V_98 , V_99 , V_100 , & V_96 ) ;
if ( V_96 && ! V_95 [ V_96 ] )
return 0 ;
* V_21 = 0 ;
sscanf ( V_95 , L_59 , V_15 , V_22 , V_23 , V_98 , V_99 ,
V_100 , & V_96 ) ;
if ( V_96 && ! V_95 [ V_96 ] )
return 0 ;
return - V_97 ;
}
static int F_91 ( int V_21 , int V_15 , int V_22 , int V_23 )
{
struct V_32 * V_50 ;
int V_101 = 0 , V_17 = F_92 ( V_22 , V_23 ) ;
if ( V_22 < 0 ) {
for ( V_22 = 0 ; ! V_101 && V_22 < 32 ; ++ V_22 )
V_101 = F_91 ( V_21 , V_15 , V_22 , V_23 ) ;
return V_101 ;
}
if ( V_23 < 0 ) {
for ( V_23 = 0 ; ! V_101 && V_23 < 8 ; ++ V_23 )
V_101 = F_91 ( V_21 , V_15 , V_22 , V_23 ) ;
return V_101 ;
}
if ( (
#if ! F_93 ( V_102 ) \
|| ! F_93 ( V_103 )
! V_104 ? V_21 :
#endif
V_21 < 0 || V_21 > 0xffff )
|| V_15 < 0 || V_15 > 0xff
|| F_31 ( V_17 ) != V_22
|| F_32 ( V_17 ) != V_23 )
return - V_97 ;
V_50 = F_65 ( sizeof( * V_50 ) , V_105 ) ;
if ( ! V_50 )
return - V_38 ;
F_94 ( L_60 ,
V_21 , V_15 , V_22 , V_23 ) ;
F_61 ( V_50 , V_21 , V_15 , V_17 ) ;
return 0 ;
}
static int F_95 ( int V_21 , int V_15 , int V_22 , int V_23 )
{
struct V_32 * V_50 , * V_106 ;
int V_18 = - V_107 ;
unsigned long V_24 ;
F_34 ( & V_36 , V_24 ) ;
F_96 (pci_dev_id, t, &pcistub_device_ids,
slot_list) {
if ( V_50 -> V_21 == V_21 && V_50 -> V_15 == V_15
&& ( V_22 < 0 || F_31 ( V_50 -> V_17 ) == V_22 )
&& ( V_23 < 0 || F_32 ( V_50 -> V_17 ) == V_23 ) ) {
F_59 ( & V_50 -> V_51 ) ;
F_5 ( V_50 ) ;
V_18 = 0 ;
F_94 ( L_61 ,
V_21 , V_15 , V_22 , V_23 ) ;
}
}
F_35 ( & V_36 , V_24 ) ;
return V_18 ;
}
static int F_97 ( int V_21 , int V_15 , int V_22 , int V_23 ,
unsigned int V_98 , unsigned int V_99 ,
unsigned int V_100 )
{
int V_18 = 0 ;
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_108 * V_109 ;
if ( V_98 > 0xfff || ( V_99 < 4 && ( V_100 >> ( V_99 * 8 ) ) ) )
return - V_97 ;
V_4 = F_33 ( V_21 , V_15 , V_22 , V_23 ) ;
if ( ! V_4 ) {
V_18 = - V_61 ;
goto V_39;
}
V_3 = V_4 -> V_3 ;
V_109 = F_3 ( sizeof( * V_109 ) , V_5 ) ;
if ( ! V_109 ) {
V_18 = - V_38 ;
goto V_39;
}
V_109 -> V_110 = V_98 ;
V_109 -> V_99 = V_99 ;
V_109 -> V_100 = V_100 ;
V_109 -> V_111 = NULL ;
V_109 -> V_112 = NULL ;
V_109 -> V_113 = NULL ;
V_109 -> V_114 = V_115 ;
V_18 = F_98 ( V_3 , V_109 ) ;
if ( V_18 )
F_5 ( V_109 ) ;
V_39:
if ( V_4 )
F_27 ( V_4 ) ;
return V_18 ;
}
static T_4 F_99 ( struct V_116 * V_117 , const char * V_95 ,
T_5 V_118 )
{
int V_21 , V_15 , V_22 , V_23 ;
int V_18 ;
V_18 = F_89 ( V_95 , & V_21 , & V_15 , & V_22 , & V_23 ) ;
if ( V_18 )
goto V_39;
V_18 = F_91 ( V_21 , V_15 , V_22 , V_23 ) ;
V_39:
if ( ! V_18 )
V_18 = V_118 ;
return V_18 ;
}
static T_4 F_100 ( struct V_116 * V_117 , const char * V_95 ,
T_5 V_118 )
{
int V_21 , V_15 , V_22 , V_23 ;
int V_18 ;
V_18 = F_89 ( V_95 , & V_21 , & V_15 , & V_22 , & V_23 ) ;
if ( V_18 )
goto V_39;
V_18 = F_95 ( V_21 , V_15 , V_22 , V_23 ) ;
V_39:
if ( ! V_18 )
V_18 = V_118 ;
return V_18 ;
}
static T_4 F_101 ( struct V_116 * V_117 , char * V_95 )
{
struct V_32 * V_50 ;
T_5 V_118 = 0 ;
unsigned long V_24 ;
F_34 ( & V_36 , V_24 ) ;
F_30 (pci_dev_id, &pcistub_device_ids, slot_list) {
if ( V_118 >= V_119 )
break;
V_118 += F_102 ( V_95 + V_118 , V_119 - V_118 ,
L_62 ,
V_50 -> V_21 , V_50 -> V_15 ,
F_31 ( V_50 -> V_17 ) ,
F_32 ( V_50 -> V_17 ) ) ;
}
F_35 ( & V_36 , V_24 ) ;
return V_118 ;
}
static T_4 F_103 ( struct V_116 * V_117 , char * V_95 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
T_5 V_118 = 0 ;
unsigned long V_24 ;
F_34 ( & V_25 , V_24 ) ;
F_30 (psdev, &pcistub_devices, dev_list) {
if ( V_118 >= V_119 )
break;
if ( ! V_4 -> V_3 )
continue;
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 )
continue;
V_118 +=
F_102 ( V_95 + V_118 , V_119 - V_118 ,
L_63 ,
F_49 ( V_4 -> V_3 ) ,
V_9 -> V_120 ? L_64 : L_65 ,
V_9 -> V_121 ? L_66 : L_67 ,
V_9 -> V_122 ) ;
}
F_35 ( & V_25 , V_24 ) ;
return V_118 ;
}
static T_4 F_104 ( struct V_116 * V_117 ,
const char * V_95 ,
T_5 V_118 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
int V_21 , V_15 , V_22 , V_23 ;
int V_18 ;
V_18 = F_89 ( V_95 , & V_21 , & V_15 , & V_22 , & V_23 ) ;
if ( V_18 )
return V_18 ;
V_4 = F_33 ( V_21 , V_15 , V_22 , V_23 ) ;
if ( ! V_4 ) {
V_18 = - V_107 ;
goto V_39;
}
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 ) {
V_18 = - V_107 ;
goto V_39;
}
F_2 ( & V_4 -> V_3 -> V_3 , L_68 ,
V_9 -> V_40 , V_9 -> V_120 ,
! V_9 -> V_120 ) ;
V_9 -> V_120 = ! ( V_9 -> V_120 ) ;
if ( V_9 -> V_120 )
V_9 -> V_121 = 1 ;
V_39:
if ( V_4 )
F_27 ( V_4 ) ;
if ( ! V_18 )
V_18 = V_118 ;
return V_18 ;
}
static T_4 F_105 ( struct V_116 * V_117 , const char * V_95 ,
T_5 V_118 )
{
int V_21 , V_15 , V_22 , V_23 , V_98 , V_99 , V_100 ;
int V_18 ;
V_18 = F_90 ( V_95 , & V_21 , & V_15 , & V_22 , & V_23 , & V_98 , & V_99 ,
& V_100 ) ;
if ( V_18 )
goto V_39;
V_18 = F_97 ( V_21 , V_15 , V_22 , V_23 , V_98 , V_99 , V_100 ) ;
V_39:
if ( ! V_18 )
V_18 = V_118 ;
return V_18 ;
}
static T_4 F_106 ( struct V_116 * V_117 , char * V_95 )
{
int V_118 = 0 ;
unsigned long V_24 ;
struct V_123 * V_124 ;
struct V_8 * V_9 ;
const struct V_108 * V_109 ;
const struct V_125 * V_126 ;
F_34 ( & V_36 , V_24 ) ;
F_30 (quirk, &xen_pcibk_quirks, quirks_list) {
if ( V_118 >= V_119 )
goto V_39;
V_118 += F_102 ( V_95 + V_118 , V_119 - V_118 ,
L_69 ,
V_124 -> V_27 -> V_15 -> V_16 ,
F_31 ( V_124 -> V_27 -> V_17 ) ,
F_32 ( V_124 -> V_27 -> V_17 ) ,
V_124 -> V_127 . V_128 , V_124 -> V_127 . V_129 ,
V_124 -> V_127 . V_130 ,
V_124 -> V_127 . V_131 ) ;
V_9 = F_10 ( V_124 -> V_27 ) ;
F_30 (cfg_entry, &dev_data->config_fields, list) {
V_109 = V_126 -> V_109 ;
if ( V_118 >= V_119 )
goto V_39;
V_118 += F_102 ( V_95 + V_118 , V_119 - V_118 ,
L_70 ,
V_126 -> V_132 +
V_109 -> V_110 , V_109 -> V_99 ,
V_109 -> V_100 ) ;
}
}
V_39:
F_35 ( & V_36 , V_24 ) ;
return V_118 ;
}
static T_4 F_107 ( struct V_116 * V_117 , const char * V_95 ,
T_5 V_118 )
{
int V_21 , V_15 , V_22 , V_23 ;
int V_18 ;
struct V_1 * V_4 ;
struct V_8 * V_9 ;
V_18 = F_89 ( V_95 , & V_21 , & V_15 , & V_22 , & V_23 ) ;
if ( V_18 )
goto V_39;
V_4 = F_33 ( V_21 , V_15 , V_22 , V_23 ) ;
if ( ! V_4 ) {
V_18 = - V_61 ;
goto V_39;
}
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 ) {
V_18 = - V_133 ;
goto V_113;
}
if ( ! V_9 -> V_134 ) {
V_9 -> V_134 = 1 ;
F_18 ( & V_4 -> V_3 -> V_3 , L_71
L_72 ) ;
F_18 ( & V_4 -> V_3 -> V_3 ,
L_73 ) ;
}
V_113:
F_27 ( V_4 ) ;
V_39:
if ( ! V_18 )
V_18 = V_118 ;
return V_18 ;
}
static T_4 F_108 ( struct V_116 * V_117 , char * V_95 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
T_5 V_118 = 0 ;
unsigned long V_24 ;
F_34 ( & V_25 , V_24 ) ;
F_30 (psdev, &pcistub_devices, dev_list) {
if ( V_118 >= V_119 )
break;
if ( ! V_4 -> V_3 )
continue;
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 || ! V_9 -> V_134 )
continue;
V_118 +=
F_102 ( V_95 + V_118 , V_119 - V_118 , L_74 ,
F_49 ( V_4 -> V_3 ) ) ;
}
F_35 ( & V_25 , V_24 ) ;
return V_118 ;
}
static void F_109 ( void )
{
F_110 ( & V_135 . V_136 , & V_137 ) ;
F_110 ( & V_135 . V_136 ,
& V_138 ) ;
F_110 ( & V_135 . V_136 , & V_139 ) ;
F_110 ( & V_135 . V_136 , & V_140 ) ;
F_110 ( & V_135 . V_136 ,
& V_141 ) ;
F_110 ( & V_135 . V_136 ,
& V_142 ) ;
F_110 ( & V_135 . V_136 ,
& V_143 ) ;
F_111 ( & V_135 ) ;
}
static int T_1 F_112 ( void )
{
int V_144 = 0 ;
int V_18 = 0 ;
int V_21 , V_15 , V_22 , V_23 ;
int V_96 ;
if ( V_145 && * V_145 ) {
do {
V_96 = 0 ;
V_18 = sscanf ( V_145 + V_144 ,
L_75 ,
& V_21 , & V_15 , & V_22 , & V_23 , & V_96 ) ;
switch ( V_18 ) {
case 3 :
V_23 = - 1 ;
sscanf ( V_145 + V_144 ,
L_76 ,
& V_21 , & V_15 , & V_22 , & V_96 ) ;
break;
case 2 :
V_22 = V_23 = - 1 ;
sscanf ( V_145 + V_144 ,
L_77 ,
& V_21 , & V_15 , & V_96 ) ;
break;
}
if ( ! V_96 ) {
V_21 = 0 ;
V_18 = sscanf ( V_145 + V_144 ,
L_78 ,
& V_15 , & V_22 , & V_23 , & V_96 ) ;
switch ( V_18 ) {
case 2 :
V_23 = - 1 ;
sscanf ( V_145 + V_144 ,
L_79 ,
& V_15 , & V_22 , & V_96 ) ;
break;
case 1 :
V_22 = V_23 = - 1 ;
sscanf ( V_145 + V_144 ,
L_80 ,
& V_15 , & V_96 ) ;
break;
}
}
if ( V_96 <= 0 )
goto V_146;
V_18 = F_91 ( V_21 , V_15 , V_22 , V_23 ) ;
if ( V_18 )
goto V_39;
V_144 += V_96 ;
} while ( V_145 [ V_144 ] );
}
V_18 = F_113 ( & V_135 ) ;
if ( V_18 < 0 )
goto V_39;
V_18 = F_114 ( & V_135 . V_136 ,
& V_137 ) ;
if ( ! V_18 )
V_18 = F_114 ( & V_135 . V_136 ,
& V_138 ) ;
if ( ! V_18 )
V_18 = F_114 ( & V_135 . V_136 ,
& V_139 ) ;
if ( ! V_18 )
V_18 = F_114 ( & V_135 . V_136 ,
& V_140 ) ;
if ( ! V_18 )
V_18 = F_114 ( & V_135 . V_136 ,
& V_141 ) ;
if ( ! V_18 )
V_18 = F_114 ( & V_135 . V_136 ,
& V_142 ) ;
if ( ! V_18 )
V_18 = F_114 ( & V_135 . V_136 ,
& V_143 ) ;
if ( V_18 )
F_109 () ;
V_39:
return V_18 ;
V_146:
F_115 ( L_81 ,
V_145 + V_144 ) ;
return - V_97 ;
}
static struct V_1 * F_116 ( const struct V_2 * V_27 )
{
struct V_1 * V_4 = NULL ;
unsigned long V_24 ;
bool V_35 = false ;
F_34 ( & V_25 , V_24 ) ;
F_30 (psdev, &pcistub_devices, dev_list) {
if ( ! V_4 -> V_27 && V_4 -> V_3 != V_27
&& F_117 ( V_4 -> V_3 ) == V_27 ) {
V_35 = true ;
break;
}
}
F_35 ( & V_25 , V_24 ) ;
if ( V_35 )
return V_4 ;
return NULL ;
}
static int F_118 ( struct V_147 * V_148 ,
unsigned long V_149 , void * V_150 )
{
struct V_129 * V_3 = V_150 ;
const struct V_2 * V_27 = F_119 ( V_3 ) ;
if ( V_149 != V_151 )
return V_152 ;
if ( ! V_27 -> V_153 )
return V_152 ;
for (; ; ) {
struct V_1 * V_4 = F_116 ( V_27 ) ;
if ( ! V_4 )
break;
F_120 ( & V_4 -> V_3 -> V_3 ) ;
}
return V_152 ;
}
static int T_1 F_121 ( void )
{
int V_18 ;
if ( ! F_122 () )
return - V_61 ;
V_18 = F_123 () ;
if ( V_18 )
return V_18 ;
#ifdef V_102
V_18 = F_112 () ;
if ( V_18 < 0 )
return V_18 ;
#endif
F_57 () ;
V_18 = F_124 () ;
if ( V_18 )
F_109 () ;
#ifdef F_125
else
F_126 ( & V_154 , & V_155 ) ;
#endif
return V_18 ;
}
static void T_6 F_127 ( void )
{
#ifdef F_125
F_128 ( & V_154 , & V_155 ) ;
#endif
F_129 () ;
F_109 () ;
}
