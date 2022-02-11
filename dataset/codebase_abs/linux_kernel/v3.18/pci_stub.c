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
F_22 ( V_3 ) ;
F_23 ( V_3 ) ;
F_5 ( V_4 ) ;
}
static inline void F_24 ( struct V_1 * V_4 )
{
F_25 ( & V_4 -> V_6 ) ;
}
static inline void F_26 ( struct V_1 * V_4 )
{
F_27 ( & V_4 -> V_6 , F_8 ) ;
}
static struct V_1 * F_28 ( int V_20 , int V_15 ,
int V_21 , int V_22 )
{
struct V_1 * V_4 = NULL ;
unsigned long V_23 ;
F_29 ( & V_24 , V_23 ) ;
F_30 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 != NULL
&& V_20 == F_15 ( V_4 -> V_3 -> V_15 )
&& V_15 == V_4 -> V_3 -> V_15 -> V_16
&& V_21 == F_31 ( V_4 -> V_3 -> V_17 )
&& V_22 == F_32 ( V_4 -> V_3 -> V_17 ) ) {
F_24 ( V_4 ) ;
goto V_25;
}
}
V_4 = NULL ;
V_25:
F_33 ( & V_24 , V_23 ) ;
return V_4 ;
}
static struct V_2 * F_34 ( struct V_26 * V_27 ,
struct V_1 * V_4 )
{
struct V_2 * V_2 = NULL ;
unsigned long V_23 ;
F_24 ( V_4 ) ;
F_29 ( & V_4 -> V_7 , V_23 ) ;
if ( ! V_4 -> V_27 ) {
V_4 -> V_27 = V_27 ;
V_2 = V_4 -> V_3 ;
}
F_33 ( & V_4 -> V_7 , V_23 ) ;
if ( ! V_2 )
F_26 ( V_4 ) ;
return V_2 ;
}
struct V_2 * F_35 ( struct V_26 * V_27 ,
int V_20 , int V_15 ,
int V_21 , int V_22 )
{
struct V_1 * V_4 ;
struct V_2 * V_28 = NULL ;
unsigned long V_23 ;
F_29 ( & V_24 , V_23 ) ;
F_30 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 != NULL
&& V_20 == F_15 ( V_4 -> V_3 -> V_15 )
&& V_15 == V_4 -> V_3 -> V_15 -> V_16
&& V_21 == F_31 ( V_4 -> V_3 -> V_17 )
&& V_22 == F_32 ( V_4 -> V_3 -> V_17 ) ) {
V_28 = F_34 ( V_27 , V_4 ) ;
break;
}
}
F_33 ( & V_24 , V_23 ) ;
return V_28 ;
}
struct V_2 * F_36 ( struct V_26 * V_27 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_2 * V_28 = NULL ;
unsigned long V_23 ;
F_29 ( & V_24 , V_23 ) ;
F_30 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_28 = F_34 ( V_27 , V_4 ) ;
break;
}
}
F_33 ( & V_24 , V_23 ) ;
return V_28 ;
}
void F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_29 = NULL ;
unsigned long V_23 ;
F_29 ( & V_24 , V_23 ) ;
F_30 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_29 = V_4 ;
break;
}
}
F_33 ( & V_24 , V_23 ) ;
if ( F_38 ( ! V_29 ) )
return;
F_39 ( & V_30 ) ;
F_40 ( V_3 ) ;
F_14 ( V_3 ) ;
F_18 ( V_3 ) ;
F_41 ( V_3 ) ;
F_20 ( V_3 ) ;
F_11 ( V_3 ) ;
F_29 ( & V_29 -> V_7 , V_23 ) ;
V_29 -> V_27 = NULL ;
F_33 ( & V_29 -> V_7 , V_23 ) ;
F_26 ( V_29 ) ;
F_42 ( & V_30 ) ;
}
static int F_43 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
for (; V_3 != NULL ; V_3 = V_3 -> V_15 -> V_33 ) {
if ( F_15 ( V_3 -> V_15 ) == V_32 -> V_20
&& V_3 -> V_15 -> V_16 == V_32 -> V_15
&& V_3 -> V_17 == V_32 -> V_17 )
return 1 ;
if ( V_3 == V_3 -> V_15 -> V_33 )
break;
}
return 0 ;
}
static int F_44 ( struct V_2 * V_3 )
{
struct V_31 * V_32 ;
unsigned long V_23 ;
int V_34 = 0 ;
F_29 ( & V_35 , V_23 ) ;
F_30 (pdev_id, &pcistub_device_ids, slot_list) {
if ( F_43 ( V_3 , V_32 ) ) {
V_34 = 1 ;
break;
}
}
F_33 ( & V_35 , V_23 ) ;
return V_34 ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_8 * V_9 ;
int V_18 = 0 ;
F_2 ( & V_3 -> V_3 , L_5 ) ;
V_9 = F_3 ( sizeof( * V_9 ) + strlen ( V_36 L_6 )
+ strlen ( F_46 ( V_3 ) ) + 1 , V_5 ) ;
if ( ! V_9 ) {
V_18 = - V_37 ;
goto V_25;
}
F_19 ( V_3 , V_9 ) ;
sprintf ( V_9 -> V_38 , V_36 L_7 , F_46 ( V_3 ) ) ;
F_2 ( & V_3 -> V_3 , L_8 ) ;
F_47 ( & V_39 ) ;
V_18 = F_48 ( V_3 ) ;
if ( V_18 )
goto V_25;
F_2 ( & V_3 -> V_3 , L_9 ) ;
V_18 = F_49 ( V_3 ) ;
if ( V_18 )
goto V_40;
if ( V_3 -> V_11 ) {
struct V_12 V_13 = {
. V_14 = F_15 ( V_3 -> V_15 ) ,
. V_15 = V_3 -> V_15 -> V_16 ,
. V_17 = V_3 -> V_17
} ;
V_18 = F_16 ( V_41 , & V_13 ) ;
if ( V_18 )
F_50 ( & V_3 -> V_3 , L_10 ,
V_18 ) ;
}
F_2 ( & V_3 -> V_3 , L_11 ) ;
F_51 ( V_3 ) ;
V_9 -> V_10 = F_52 ( V_3 ) ;
if ( ! V_9 -> V_10 )
F_50 ( & V_3 -> V_3 , L_12 ) ;
else {
F_2 ( & V_3 -> V_3 , L_13 ) ;
F_12 ( V_3 ) ;
F_14 ( V_3 ) ;
}
F_2 ( & V_3 -> V_3 , L_14 ) ;
F_18 ( V_3 ) ;
F_53 ( V_3 ) ;
return 0 ;
V_40:
F_21 ( V_3 ) ;
V_25:
F_19 ( V_3 , NULL ) ;
F_5 ( V_9 ) ;
return V_18 ;
}
static int T_1 F_54 ( void )
{
struct V_1 * V_4 ;
unsigned long V_23 ;
int V_18 = 0 ;
F_29 ( & V_24 , V_23 ) ;
while ( ! F_55 ( & V_42 ) ) {
V_4 = F_9 ( V_42 . V_43 ,
struct V_1 , V_44 ) ;
F_56 ( & V_4 -> V_44 ) ;
F_33 ( & V_24 , V_23 ) ;
V_18 = F_45 ( V_4 -> V_3 ) ;
if ( V_18 ) {
F_50 ( & V_4 -> V_3 -> V_3 ,
L_15 , V_18 ) ;
F_5 ( V_4 ) ;
V_4 = NULL ;
}
F_29 ( & V_24 , V_23 ) ;
if ( V_4 )
F_57 ( & V_4 -> V_44 , & V_45 ) ;
}
V_46 = 1 ;
F_33 ( & V_24 , V_23 ) ;
return 0 ;
}
static int F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_23 ;
int V_18 = 0 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_37 ;
F_29 ( & V_24 , V_23 ) ;
if ( V_46 ) {
F_33 ( & V_24 , V_23 ) ;
V_18 = F_45 ( V_4 -> V_3 ) ;
F_29 ( & V_24 , V_23 ) ;
if ( ! V_18 )
F_59 ( & V_4 -> V_44 , & V_45 ) ;
} else {
F_2 ( & V_3 -> V_3 , L_16 ) ;
F_59 ( & V_4 -> V_44 , & V_42 ) ;
}
F_33 ( & V_24 , V_23 ) ;
if ( V_18 )
F_26 ( V_4 ) ;
return V_18 ;
}
static int F_60 ( struct V_2 * V_3 , const struct V_47 * V_48 )
{
int V_18 = 0 ;
F_2 ( & V_3 -> V_3 , L_17 ) ;
if ( F_44 ( V_3 ) ) {
if ( V_3 -> V_49 != V_50
&& V_3 -> V_49 != V_51 ) {
F_50 ( & V_3 -> V_3 , L_18
L_19
L_20 ) ;
V_18 = - V_52 ;
goto V_25;
}
F_61 ( & V_3 -> V_3 , L_21 ) ;
V_18 = F_58 ( V_3 ) ;
} else
V_18 = - V_52 ;
V_25:
return V_18 ;
}
static void F_62 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_29 = NULL ;
unsigned long V_23 ;
F_2 ( & V_3 -> V_3 , L_22 ) ;
F_29 ( & V_24 , V_23 ) ;
F_63 ( V_3 ) ;
F_30 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_29 = V_4 ;
break;
}
}
F_33 ( & V_24 , V_23 ) ;
if ( V_29 ) {
F_2 ( & V_3 -> V_3 , L_23 ,
V_29 -> V_27 ) ;
if ( V_29 -> V_27 ) {
F_64 ( L_24 ,
F_46 ( V_29 -> V_3 ) ) ;
F_64 ( L_25 ) ;
F_64 ( L_26 ) ;
F_64 ( L_27 ) ;
F_65 ( V_29 -> V_27 ,
V_29 -> V_3 ) ;
}
F_29 ( & V_24 , V_23 ) ;
F_56 ( & V_29 -> V_44 ) ;
F_33 ( & V_24 , V_23 ) ;
F_26 ( V_29 ) ;
}
}
static void F_66 ( struct V_1 * V_4 )
{
struct V_53 V_54 ;
int V_18 ;
char V_55 [ V_56 ] ;
F_67 ( ! V_4 ) ;
snprintf ( V_55 , V_56 , L_28 ,
V_4 -> V_27 -> V_57 -> V_58 ) ;
V_59:
V_18 = F_68 ( & V_54 ) ;
if ( V_18 ) {
F_50 ( & V_4 -> V_3 -> V_3 ,
L_29 , V_18 ) ;
return;
}
F_69 ( V_54 , V_55 , L_30 , L_31 ) ;
V_18 = F_70 ( V_54 , 0 ) ;
if ( V_18 ) {
if ( V_18 == - V_60 )
goto V_59;
F_50 ( & V_4 -> V_3 -> V_3 ,
L_32 , V_18 ) ;
return;
}
}
static T_2 F_71 ( struct V_1 * V_4 ,
T_3 V_61 , int V_62 ,
T_2 V_63 )
{
T_2 V_64 = V_63 ;
struct V_65 * V_66 ;
int V_67 ;
V_66 = & ( V_4 -> V_27 -> V_68 -> V_66 ) ;
V_66 -> V_69 = V_62 ;
V_66 -> V_18 = V_61 ;
V_67 = F_72 ( V_4 -> V_3 , V_4 -> V_27 ,
& V_66 -> V_20 , & V_66 -> V_15 , & V_66 -> V_17 ) ;
if ( ! V_67 ) {
F_50 ( & V_4 -> V_3 -> V_3 ,
V_36 L_33 ) ;
return V_70 ;
}
F_73 () ;
F_2 ( & V_4 -> V_3 -> V_3 ,
V_36 L_34 ,
V_62 , V_66 -> V_20 , V_66 -> V_15 , V_66 -> V_17 ) ;
F_74 ( V_71 , ( unsigned long * ) & V_4 -> V_27 -> V_23 ) ;
F_74 ( V_72 ,
( unsigned long * ) & V_4 -> V_27 -> V_68 -> V_23 ) ;
F_73 () ;
F_75 ( V_4 -> V_27 -> V_73 ) ;
V_67 = F_76 ( V_39 ,
! ( F_77 ( V_72 , ( unsigned long * )
& V_4 -> V_27 -> V_68 -> V_23 ) ) , 300 * V_74 ) ;
if ( ! V_67 ) {
if ( F_77 ( V_72 ,
( unsigned long * ) & V_4 -> V_27 -> V_68 -> V_23 ) ) {
F_50 ( & V_4 -> V_3 -> V_3 ,
L_35 ) ;
F_78 ( V_72 ,
( unsigned long * ) & V_4 -> V_27 -> V_68 -> V_23 ) ;
V_66 -> V_18 = V_70 ;
return V_64 ;
}
}
F_78 ( V_71 , ( unsigned long * ) & V_4 -> V_27 -> V_23 ) ;
if ( F_77 ( V_75 ,
( unsigned long * ) & V_4 -> V_27 -> V_68 -> V_23 ) ) {
F_2 ( & V_4 -> V_3 -> V_3 ,
L_36 V_36 L_37 ) ;
F_79 ( V_4 -> V_27 ) ;
}
V_64 = ( T_2 ) V_66 -> V_18 ;
return V_64 ;
}
static T_2 F_80 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
T_2 V_63 ;
V_63 = V_76 ;
F_2 ( & V_3 -> V_3 , L_38 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_39 ( & V_30 ) ;
V_4 = F_28 ( F_15 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_31 ( V_3 -> V_17 ) ,
F_32 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_27 ) {
F_50 ( & V_3 -> V_3 ,
V_36 L_39 ) ;
goto V_77;
}
if ( ! V_4 -> V_27 -> V_68 ) {
F_50 ( & V_3 -> V_3 , V_36 L_40
L_41 ) ;
F_66 ( V_4 ) ;
goto V_77;
}
if ( ! F_77 ( V_78 ,
( unsigned long * ) & V_4 -> V_27 -> V_68 -> V_23 ) ) {
F_50 ( & V_3 -> V_3 ,
L_42 ) ;
goto V_77;
}
V_63 = F_71 ( V_4 , 1 , V_79 , V_63 ) ;
if ( V_63 == V_70 ||
V_63 == V_80 ) {
F_2 ( & V_3 -> V_3 ,
L_43 ) ;
F_66 ( V_4 ) ;
}
V_77:
if ( V_4 )
F_26 ( V_4 ) ;
F_42 ( & V_30 ) ;
return V_63 ;
}
static T_2 F_81 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
T_2 V_63 ;
V_63 = V_76 ;
F_2 ( & V_3 -> V_3 , L_44 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_39 ( & V_30 ) ;
V_4 = F_28 ( F_15 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_31 ( V_3 -> V_17 ) ,
F_32 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_27 ) {
F_50 ( & V_3 -> V_3 ,
V_36 L_39 ) ;
goto V_77;
}
if ( ! V_4 -> V_27 -> V_68 ) {
F_50 ( & V_3 -> V_3 , V_36 L_40
L_41 ) ;
F_66 ( V_4 ) ;
goto V_77;
}
if ( ! F_77 ( V_78 ,
( unsigned long * ) & V_4 -> V_27 -> V_68 -> V_23 ) ) {
F_50 ( & V_3 -> V_3 ,
L_42 ) ;
goto V_77;
}
V_63 = F_71 ( V_4 , 1 , V_81 , V_63 ) ;
if ( V_63 == V_70 ||
V_63 == V_80 ) {
F_2 ( & V_3 -> V_3 ,
L_45 ) ;
F_66 ( V_4 ) ;
}
V_77:
if ( V_4 )
F_26 ( V_4 ) ;
F_42 ( & V_30 ) ;
return V_63 ;
}
static T_2 F_82 ( struct V_2 * V_3 ,
T_3 error )
{
struct V_1 * V_4 ;
T_2 V_63 ;
V_63 = V_82 ;
F_2 ( & V_3 -> V_3 , L_46 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_39 ( & V_30 ) ;
V_4 = F_28 ( F_15 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_31 ( V_3 -> V_17 ) ,
F_32 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_27 ) {
F_50 ( & V_3 -> V_3 ,
V_36 L_39 ) ;
goto V_77;
}
if ( ! V_4 -> V_27 -> V_68 ) {
F_50 ( & V_3 -> V_3 , V_36 L_40
L_41 ) ;
F_66 ( V_4 ) ;
goto V_77;
}
if ( ! F_77 ( V_78 ,
( unsigned long * ) & V_4 -> V_27 -> V_68 -> V_23 ) ) {
F_2 ( & V_3 -> V_3 , L_47 ) ;
F_66 ( V_4 ) ;
goto V_77;
}
V_63 = F_71 ( V_4 , error , V_83 , V_63 ) ;
if ( V_63 == V_70 ||
V_63 == V_80 ) {
F_2 ( & V_3 -> V_3 ,
L_48 ) ;
F_66 ( V_4 ) ;
}
V_77:
if ( V_4 )
F_26 ( V_4 ) ;
F_42 ( & V_30 ) ;
return V_63 ;
}
static void F_83 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_3 -> V_3 , L_49 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_39 ( & V_30 ) ;
V_4 = F_28 ( F_15 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_31 ( V_3 -> V_17 ) ,
F_32 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_27 ) {
F_50 ( & V_3 -> V_3 ,
V_36 L_39 ) ;
goto V_77;
}
if ( ! V_4 -> V_27 -> V_68 ) {
F_50 ( & V_3 -> V_3 , V_36 L_40
L_41 ) ;
F_66 ( V_4 ) ;
goto V_77;
}
if ( ! F_77 ( V_78 ,
( unsigned long * ) & V_4 -> V_27 -> V_68 -> V_23 ) ) {
F_50 ( & V_3 -> V_3 ,
L_42 ) ;
F_66 ( V_4 ) ;
goto V_77;
}
F_71 ( V_4 , 1 , V_84 ,
V_76 ) ;
V_77:
if ( V_4 )
F_26 ( V_4 ) ;
F_42 ( & V_30 ) ;
return;
}
static inline int F_84 ( const char * V_85 , int * V_20 , int * V_15 ,
int * V_21 , int * V_22 )
{
int V_86 = 0 ;
switch ( sscanf ( V_85 , L_50 , V_20 , V_15 , V_21 , V_22 ,
& V_86 ) ) {
case 3 :
* V_22 = - 1 ;
sscanf ( V_85 , L_51 , V_20 , V_15 , V_21 , & V_86 ) ;
break;
case 2 :
* V_21 = * V_22 = - 1 ;
sscanf ( V_85 , L_52 , V_20 , V_15 , & V_86 ) ;
break;
}
if ( V_86 && ! V_85 [ V_86 ] )
return 0 ;
* V_20 = 0 ;
switch ( sscanf ( V_85 , L_53 , V_15 , V_21 , V_22 , & V_86 ) ) {
case 2 :
* V_22 = - 1 ;
sscanf ( V_85 , L_54 , V_15 , V_21 , & V_86 ) ;
break;
case 1 :
* V_21 = * V_22 = - 1 ;
sscanf ( V_85 , L_55 , V_15 , & V_86 ) ;
break;
}
if ( V_86 && ! V_85 [ V_86 ] )
return 0 ;
return - V_87 ;
}
static inline int F_85 ( const char * V_85 , int * V_20 , int * V_15 , int
* V_21 , int * V_22 , int * V_88 , int * V_89 , int * V_90 )
{
int V_86 = 0 ;
sscanf ( V_85 , L_56 , V_20 , V_15 , V_21 , V_22 ,
V_88 , V_89 , V_90 , & V_86 ) ;
if ( V_86 && ! V_85 [ V_86 ] )
return 0 ;
* V_20 = 0 ;
sscanf ( V_85 , L_57 , V_15 , V_21 , V_22 , V_88 , V_89 ,
V_90 , & V_86 ) ;
if ( V_86 && ! V_85 [ V_86 ] )
return 0 ;
return - V_87 ;
}
static int F_86 ( int V_20 , int V_15 , int V_21 , int V_22 )
{
struct V_31 * V_91 ;
unsigned long V_23 ;
int V_92 = 0 , V_17 = F_87 ( V_21 , V_22 ) ;
if ( V_21 < 0 ) {
for ( V_21 = 0 ; ! V_92 && V_21 < 32 ; ++ V_21 )
V_92 = F_86 ( V_20 , V_15 , V_21 , V_22 ) ;
return V_92 ;
}
if ( V_22 < 0 ) {
for ( V_22 = 0 ; ! V_92 && V_22 < 8 ; ++ V_22 )
V_92 = F_86 ( V_20 , V_15 , V_21 , V_22 ) ;
return V_92 ;
}
if ( (
#if ! F_88 ( V_93 ) \
|| ! F_88 ( V_94 )
! V_95 ? V_20 :
#endif
V_20 < 0 || V_20 > 0xffff )
|| V_15 < 0 || V_15 > 0xff
|| F_31 ( V_17 ) != V_21
|| F_32 ( V_17 ) != V_22 )
return - V_87 ;
V_91 = F_89 ( sizeof( * V_91 ) , V_96 ) ;
if ( ! V_91 )
return - V_37 ;
V_91 -> V_20 = V_20 ;
V_91 -> V_15 = V_15 ;
V_91 -> V_17 = V_17 ;
F_90 ( L_58 ,
V_20 , V_15 , V_21 , V_22 ) ;
F_29 ( & V_35 , V_23 ) ;
F_57 ( & V_91 -> V_97 , & V_98 ) ;
F_33 ( & V_35 , V_23 ) ;
return 0 ;
}
static int F_91 ( int V_20 , int V_15 , int V_21 , int V_22 )
{
struct V_31 * V_91 , * V_99 ;
int V_18 = - V_100 ;
unsigned long V_23 ;
F_29 ( & V_35 , V_23 ) ;
F_92 (pci_dev_id, t, &pcistub_device_ids,
slot_list) {
if ( V_91 -> V_20 == V_20 && V_91 -> V_15 == V_15
&& ( V_21 < 0 || F_31 ( V_91 -> V_17 ) == V_21 )
&& ( V_22 < 0 || F_32 ( V_91 -> V_17 ) == V_22 ) ) {
F_56 ( & V_91 -> V_97 ) ;
F_5 ( V_91 ) ;
V_18 = 0 ;
F_90 ( L_59 ,
V_20 , V_15 , V_21 , V_22 ) ;
}
}
F_33 ( & V_35 , V_23 ) ;
return V_18 ;
}
static int F_93 ( int V_20 , int V_15 , int V_21 , int V_22 ,
unsigned int V_88 , unsigned int V_89 ,
unsigned int V_90 )
{
int V_18 = 0 ;
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_101 * V_102 ;
if ( V_88 > 0xfff || ( V_89 < 4 && ( V_90 >> ( V_89 * 8 ) ) ) )
return - V_87 ;
V_4 = F_28 ( V_20 , V_15 , V_21 , V_22 ) ;
if ( ! V_4 ) {
V_18 = - V_52 ;
goto V_25;
}
V_3 = V_4 -> V_3 ;
V_102 = F_3 ( sizeof( * V_102 ) , V_5 ) ;
if ( ! V_102 ) {
V_18 = - V_37 ;
goto V_25;
}
V_102 -> V_103 = V_88 ;
V_102 -> V_89 = V_89 ;
V_102 -> V_90 = V_90 ;
V_102 -> V_104 = NULL ;
V_102 -> V_105 = NULL ;
V_102 -> V_106 = NULL ;
V_102 -> V_107 = V_108 ;
V_18 = F_94 ( V_3 , V_102 ) ;
if ( V_18 )
F_5 ( V_102 ) ;
V_25:
if ( V_4 )
F_26 ( V_4 ) ;
return V_18 ;
}
static T_4 F_95 ( struct V_109 * V_110 , const char * V_85 ,
T_5 V_111 )
{
int V_20 , V_15 , V_21 , V_22 ;
int V_18 ;
V_18 = F_84 ( V_85 , & V_20 , & V_15 , & V_21 , & V_22 ) ;
if ( V_18 )
goto V_25;
V_18 = F_86 ( V_20 , V_15 , V_21 , V_22 ) ;
V_25:
if ( ! V_18 )
V_18 = V_111 ;
return V_18 ;
}
static T_4 F_96 ( struct V_109 * V_110 , const char * V_85 ,
T_5 V_111 )
{
int V_20 , V_15 , V_21 , V_22 ;
int V_18 ;
V_18 = F_84 ( V_85 , & V_20 , & V_15 , & V_21 , & V_22 ) ;
if ( V_18 )
goto V_25;
V_18 = F_91 ( V_20 , V_15 , V_21 , V_22 ) ;
V_25:
if ( ! V_18 )
V_18 = V_111 ;
return V_18 ;
}
static T_4 F_97 ( struct V_109 * V_110 , char * V_85 )
{
struct V_31 * V_91 ;
T_5 V_111 = 0 ;
unsigned long V_23 ;
F_29 ( & V_35 , V_23 ) ;
F_30 (pci_dev_id, &pcistub_device_ids, slot_list) {
if ( V_111 >= V_112 )
break;
V_111 += F_98 ( V_85 + V_111 , V_112 - V_111 ,
L_60 ,
V_91 -> V_20 , V_91 -> V_15 ,
F_31 ( V_91 -> V_17 ) ,
F_32 ( V_91 -> V_17 ) ) ;
}
F_33 ( & V_35 , V_23 ) ;
return V_111 ;
}
static T_4 F_99 ( struct V_109 * V_110 , char * V_85 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
T_5 V_111 = 0 ;
unsigned long V_23 ;
F_29 ( & V_24 , V_23 ) ;
F_30 (psdev, &pcistub_devices, dev_list) {
if ( V_111 >= V_112 )
break;
if ( ! V_4 -> V_3 )
continue;
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 )
continue;
V_111 +=
F_98 ( V_85 + V_111 , V_112 - V_111 ,
L_61 ,
F_46 ( V_4 -> V_3 ) ,
V_9 -> V_113 ? L_62 : L_63 ,
V_9 -> V_114 ? L_64 : L_65 ,
V_9 -> V_115 ) ;
}
F_33 ( & V_24 , V_23 ) ;
return V_111 ;
}
static T_4 F_100 ( struct V_109 * V_110 ,
const char * V_85 ,
T_5 V_111 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
int V_20 , V_15 , V_21 , V_22 ;
int V_18 ;
V_18 = F_84 ( V_85 , & V_20 , & V_15 , & V_21 , & V_22 ) ;
if ( V_18 )
return V_18 ;
V_4 = F_28 ( V_20 , V_15 , V_21 , V_22 ) ;
if ( ! V_4 ) {
V_18 = - V_100 ;
goto V_25;
}
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 ) {
V_18 = - V_100 ;
goto V_25;
}
F_2 ( & V_4 -> V_3 -> V_3 , L_66 ,
V_9 -> V_38 , V_9 -> V_113 ,
! V_9 -> V_113 ) ;
V_9 -> V_113 = ! ( V_9 -> V_113 ) ;
if ( V_9 -> V_113 )
V_9 -> V_114 = 1 ;
V_25:
if ( V_4 )
F_26 ( V_4 ) ;
if ( ! V_18 )
V_18 = V_111 ;
return V_18 ;
}
static T_4 F_101 ( struct V_109 * V_110 , const char * V_85 ,
T_5 V_111 )
{
int V_20 , V_15 , V_21 , V_22 , V_88 , V_89 , V_90 ;
int V_18 ;
V_18 = F_85 ( V_85 , & V_20 , & V_15 , & V_21 , & V_22 , & V_88 , & V_89 ,
& V_90 ) ;
if ( V_18 )
goto V_25;
V_18 = F_93 ( V_20 , V_15 , V_21 , V_22 , V_88 , V_89 , V_90 ) ;
V_25:
if ( ! V_18 )
V_18 = V_111 ;
return V_18 ;
}
static T_4 F_102 ( struct V_109 * V_110 , char * V_85 )
{
int V_111 = 0 ;
unsigned long V_23 ;
struct V_116 * V_117 ;
struct V_8 * V_9 ;
const struct V_101 * V_102 ;
const struct V_118 * V_119 ;
F_29 ( & V_35 , V_23 ) ;
F_30 (quirk, &xen_pcibk_quirks, quirks_list) {
if ( V_111 >= V_112 )
goto V_25;
V_111 += F_98 ( V_85 + V_111 , V_112 - V_111 ,
L_67 ,
V_117 -> V_27 -> V_15 -> V_16 ,
F_31 ( V_117 -> V_27 -> V_17 ) ,
F_32 ( V_117 -> V_27 -> V_17 ) ,
V_117 -> V_120 . V_121 , V_117 -> V_120 . V_122 ,
V_117 -> V_120 . V_123 ,
V_117 -> V_120 . V_124 ) ;
V_9 = F_10 ( V_117 -> V_27 ) ;
F_30 (cfg_entry, &dev_data->config_fields, list) {
V_102 = V_119 -> V_102 ;
if ( V_111 >= V_112 )
goto V_25;
V_111 += F_98 ( V_85 + V_111 , V_112 - V_111 ,
L_68 ,
V_119 -> V_125 +
V_102 -> V_103 , V_102 -> V_89 ,
V_102 -> V_90 ) ;
}
}
V_25:
F_33 ( & V_35 , V_23 ) ;
return V_111 ;
}
static T_4 F_103 ( struct V_109 * V_110 , const char * V_85 ,
T_5 V_111 )
{
int V_20 , V_15 , V_21 , V_22 ;
int V_18 ;
struct V_1 * V_4 ;
struct V_8 * V_9 ;
V_18 = F_84 ( V_85 , & V_20 , & V_15 , & V_21 , & V_22 ) ;
if ( V_18 )
goto V_25;
V_4 = F_28 ( V_20 , V_15 , V_21 , V_22 ) ;
if ( ! V_4 ) {
V_18 = - V_52 ;
goto V_25;
}
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 ) {
V_18 = - V_126 ;
goto V_106;
}
if ( ! V_9 -> V_127 ) {
V_9 -> V_127 = 1 ;
F_17 ( & V_4 -> V_3 -> V_3 , L_69
L_70 ) ;
F_17 ( & V_4 -> V_3 -> V_3 ,
L_71 ) ;
}
V_106:
F_26 ( V_4 ) ;
V_25:
if ( ! V_18 )
V_18 = V_111 ;
return V_18 ;
}
static T_4 F_104 ( struct V_109 * V_110 , char * V_85 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
T_5 V_111 = 0 ;
unsigned long V_23 ;
F_29 ( & V_24 , V_23 ) ;
F_30 (psdev, &pcistub_devices, dev_list) {
if ( V_111 >= V_112 )
break;
if ( ! V_4 -> V_3 )
continue;
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 || ! V_9 -> V_127 )
continue;
V_111 +=
F_98 ( V_85 + V_111 , V_112 - V_111 , L_72 ,
F_46 ( V_4 -> V_3 ) ) ;
}
F_33 ( & V_24 , V_23 ) ;
return V_111 ;
}
static void F_105 ( void )
{
F_106 ( & V_128 . V_129 , & V_130 ) ;
F_106 ( & V_128 . V_129 ,
& V_131 ) ;
F_106 ( & V_128 . V_129 , & V_132 ) ;
F_106 ( & V_128 . V_129 , & V_133 ) ;
F_106 ( & V_128 . V_129 ,
& V_134 ) ;
F_106 ( & V_128 . V_129 ,
& V_135 ) ;
F_106 ( & V_128 . V_129 ,
& V_136 ) ;
F_107 ( & V_128 ) ;
}
static int T_1 F_108 ( void )
{
int V_137 = 0 ;
int V_18 = 0 ;
int V_20 , V_15 , V_21 , V_22 ;
int V_86 ;
if ( V_138 && * V_138 ) {
do {
V_86 = 0 ;
V_18 = sscanf ( V_138 + V_137 ,
L_73 ,
& V_20 , & V_15 , & V_21 , & V_22 , & V_86 ) ;
switch ( V_18 ) {
case 3 :
V_22 = - 1 ;
sscanf ( V_138 + V_137 ,
L_74 ,
& V_20 , & V_15 , & V_21 , & V_86 ) ;
break;
case 2 :
V_21 = V_22 = - 1 ;
sscanf ( V_138 + V_137 ,
L_75 ,
& V_20 , & V_15 , & V_86 ) ;
break;
}
if ( ! V_86 ) {
V_20 = 0 ;
V_18 = sscanf ( V_138 + V_137 ,
L_76 ,
& V_15 , & V_21 , & V_22 , & V_86 ) ;
switch ( V_18 ) {
case 2 :
V_22 = - 1 ;
sscanf ( V_138 + V_137 ,
L_77 ,
& V_15 , & V_21 , & V_86 ) ;
break;
case 1 :
V_21 = V_22 = - 1 ;
sscanf ( V_138 + V_137 ,
L_78 ,
& V_15 , & V_86 ) ;
break;
}
}
if ( V_86 <= 0 )
goto V_139;
V_18 = F_86 ( V_20 , V_15 , V_21 , V_22 ) ;
if ( V_18 )
goto V_25;
V_137 += V_86 ;
} while ( V_138 [ V_137 ] );
}
V_18 = F_109 ( & V_128 ) ;
if ( V_18 < 0 )
goto V_25;
V_18 = F_110 ( & V_128 . V_129 ,
& V_130 ) ;
if ( ! V_18 )
V_18 = F_110 ( & V_128 . V_129 ,
& V_131 ) ;
if ( ! V_18 )
V_18 = F_110 ( & V_128 . V_129 ,
& V_132 ) ;
if ( ! V_18 )
V_18 = F_110 ( & V_128 . V_129 ,
& V_133 ) ;
if ( ! V_18 )
V_18 = F_110 ( & V_128 . V_129 ,
& V_134 ) ;
if ( ! V_18 )
V_18 = F_110 ( & V_128 . V_129 ,
& V_135 ) ;
if ( ! V_18 )
V_18 = F_110 ( & V_128 . V_129 ,
& V_136 ) ;
if ( V_18 )
F_105 () ;
V_25:
return V_18 ;
V_139:
F_111 ( L_79 ,
V_138 + V_137 ) ;
return - V_87 ;
}
static int T_1 F_112 ( void )
{
int V_18 ;
if ( ! F_113 () )
return - V_52 ;
V_18 = F_114 () ;
if ( V_18 )
return V_18 ;
#ifdef V_93
V_18 = F_108 () ;
if ( V_18 < 0 )
return V_18 ;
#endif
F_54 () ;
V_18 = F_115 () ;
if ( V_18 )
F_105 () ;
return V_18 ;
}
static void T_6 F_116 ( void )
{
F_117 () ;
F_105 () ;
}
