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
struct V_1 * V_4 = NULL ;
unsigned long V_24 ;
F_30 ( & V_25 , V_24 ) ;
F_31 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 != NULL
&& V_21 == F_16 ( V_4 -> V_3 -> V_15 )
&& V_15 == V_4 -> V_3 -> V_15 -> V_16
&& V_22 == F_32 ( V_4 -> V_3 -> V_17 )
&& V_23 == F_33 ( V_4 -> V_3 -> V_17 ) ) {
F_25 ( V_4 ) ;
goto V_26;
}
}
V_4 = NULL ;
V_26:
F_34 ( & V_25 , V_24 ) ;
return V_4 ;
}
static struct V_2 * F_35 ( struct V_27 * V_28 ,
struct V_1 * V_4 )
{
struct V_2 * V_2 = NULL ;
unsigned long V_24 ;
F_25 ( V_4 ) ;
F_30 ( & V_4 -> V_7 , V_24 ) ;
if ( ! V_4 -> V_28 ) {
V_4 -> V_28 = V_28 ;
V_2 = V_4 -> V_3 ;
}
F_34 ( & V_4 -> V_7 , V_24 ) ;
if ( ! V_2 )
F_27 ( V_4 ) ;
return V_2 ;
}
struct V_2 * F_36 ( struct V_27 * V_28 ,
int V_21 , int V_15 ,
int V_22 , int V_23 )
{
struct V_1 * V_4 ;
struct V_2 * V_29 = NULL ;
unsigned long V_24 ;
F_30 ( & V_25 , V_24 ) ;
F_31 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 != NULL
&& V_21 == F_16 ( V_4 -> V_3 -> V_15 )
&& V_15 == V_4 -> V_3 -> V_15 -> V_16
&& V_22 == F_32 ( V_4 -> V_3 -> V_17 )
&& V_23 == F_33 ( V_4 -> V_3 -> V_17 ) ) {
V_29 = F_35 ( V_28 , V_4 ) ;
break;
}
}
F_34 ( & V_25 , V_24 ) ;
return V_29 ;
}
struct V_2 * F_37 ( struct V_27 * V_28 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_2 * V_29 = NULL ;
unsigned long V_24 ;
F_30 ( & V_25 , V_24 ) ;
F_31 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_29 = F_35 ( V_28 , V_4 ) ;
break;
}
}
F_34 ( & V_25 , V_24 ) ;
return V_29 ;
}
void F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_30 = NULL ;
unsigned long V_24 ;
struct V_8 * V_9 ;
int V_31 ;
F_30 ( & V_25 , V_24 ) ;
F_31 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_30 = V_4 ;
break;
}
}
F_34 ( & V_25 , V_24 ) ;
if ( F_39 ( ! V_30 ) )
return;
F_40 ( & V_32 ) ;
F_41 ( & V_3 -> V_3 ) ;
F_12 ( V_3 ) ;
V_9 = F_10 ( V_3 ) ;
V_31 = F_42 ( V_3 , V_9 -> V_10 ) ;
if ( ! V_31 ) {
F_15 ( V_3 ) ;
} else
F_14 ( & V_3 -> V_3 , L_3 ) ;
F_19 ( V_3 ) ;
F_43 ( V_3 ) ;
F_21 ( V_3 ) ;
F_11 ( V_3 ) ;
F_30 ( & V_30 -> V_7 , V_24 ) ;
V_30 -> V_28 = NULL ;
F_34 ( & V_30 -> V_7 , V_24 ) ;
F_27 ( V_30 ) ;
F_44 ( & V_32 ) ;
}
static int F_45 ( struct V_2 * V_3 ,
struct V_33 * V_34 )
{
for (; V_3 != NULL ; V_3 = V_3 -> V_15 -> V_35 ) {
if ( F_16 ( V_3 -> V_15 ) == V_34 -> V_21
&& V_3 -> V_15 -> V_16 == V_34 -> V_15
&& V_3 -> V_17 == V_34 -> V_17 )
return 1 ;
if ( V_3 == V_3 -> V_15 -> V_35 )
break;
}
return 0 ;
}
static int F_46 ( struct V_2 * V_3 )
{
struct V_33 * V_34 ;
unsigned long V_24 ;
int V_36 = 0 ;
F_30 ( & V_37 , V_24 ) ;
F_31 (pdev_id, &pcistub_device_ids, slot_list) {
if ( F_45 ( V_3 , V_34 ) ) {
V_36 = 1 ;
break;
}
}
F_34 ( & V_37 , V_24 ) ;
return V_36 ;
}
static int F_47 ( struct V_2 * V_3 )
{
struct V_8 * V_9 ;
int V_18 = 0 ;
F_2 ( & V_3 -> V_3 , L_5 ) ;
V_9 = F_3 ( sizeof( * V_9 ) + strlen ( V_38 L_6 )
+ strlen ( F_48 ( V_3 ) ) + 1 , V_5 ) ;
if ( ! V_9 ) {
V_18 = - V_39 ;
goto V_26;
}
F_20 ( V_3 , V_9 ) ;
sprintf ( V_9 -> V_40 , V_38 L_7 , F_48 ( V_3 ) ) ;
F_2 ( & V_3 -> V_3 , L_8 ) ;
F_49 ( & V_41 ) ;
V_18 = F_50 ( V_3 ) ;
if ( V_18 )
goto V_26;
F_2 ( & V_3 -> V_3 , L_9 ) ;
V_18 = F_51 ( V_3 ) ;
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
F_52 ( & V_3 -> V_3 , L_10 ,
V_18 ) ;
}
F_2 ( & V_3 -> V_3 , L_11 ) ;
F_53 ( V_3 ) ;
V_9 -> V_10 = F_54 ( V_3 ) ;
if ( ! V_9 -> V_10 )
F_52 ( & V_3 -> V_3 , L_12 ) ;
else {
F_2 ( & V_3 -> V_3 , L_13 ) ;
F_12 ( V_3 ) ;
F_15 ( V_3 ) ;
}
F_2 ( & V_3 -> V_3 , L_14 ) ;
F_19 ( V_3 ) ;
F_55 ( V_3 ) ;
return 0 ;
V_42:
F_22 ( V_3 ) ;
V_26:
F_20 ( V_3 , NULL ) ;
F_5 ( V_9 ) ;
return V_18 ;
}
static int T_1 F_56 ( void )
{
struct V_1 * V_4 ;
unsigned long V_24 ;
int V_18 = 0 ;
F_30 ( & V_25 , V_24 ) ;
while ( ! F_57 ( & V_44 ) ) {
V_4 = F_9 ( V_44 . V_45 ,
struct V_1 , V_46 ) ;
F_58 ( & V_4 -> V_46 ) ;
F_34 ( & V_25 , V_24 ) ;
V_18 = F_47 ( V_4 -> V_3 ) ;
if ( V_18 ) {
F_52 ( & V_4 -> V_3 -> V_3 ,
L_15 , V_18 ) ;
F_5 ( V_4 ) ;
V_4 = NULL ;
}
F_30 ( & V_25 , V_24 ) ;
if ( V_4 )
F_59 ( & V_4 -> V_46 , & V_47 ) ;
}
V_48 = 1 ;
F_34 ( & V_25 , V_24 ) ;
return 0 ;
}
static int F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_24 ;
int V_18 = 0 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_39 ;
F_30 ( & V_25 , V_24 ) ;
if ( V_48 ) {
F_34 ( & V_25 , V_24 ) ;
V_18 = F_47 ( V_4 -> V_3 ) ;
F_30 ( & V_25 , V_24 ) ;
if ( ! V_18 )
F_61 ( & V_4 -> V_46 , & V_47 ) ;
} else {
F_2 ( & V_3 -> V_3 , L_16 ) ;
F_61 ( & V_4 -> V_46 , & V_44 ) ;
}
F_34 ( & V_25 , V_24 ) ;
if ( V_18 )
F_27 ( V_4 ) ;
return V_18 ;
}
static int F_62 ( struct V_2 * V_3 , const struct V_49 * V_50 )
{
int V_18 = 0 ;
F_2 ( & V_3 -> V_3 , L_17 ) ;
if ( F_46 ( V_3 ) ) {
if ( V_3 -> V_51 != V_52
&& V_3 -> V_51 != V_53 ) {
F_52 ( & V_3 -> V_3 , L_18
L_19
L_20 ) ;
V_18 = - V_54 ;
goto V_26;
}
F_14 ( & V_3 -> V_3 , L_21 ) ;
V_18 = F_60 ( V_3 ) ;
} else
V_18 = - V_54 ;
V_26:
return V_18 ;
}
static void F_63 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_30 = NULL ;
unsigned long V_24 ;
F_2 ( & V_3 -> V_3 , L_22 ) ;
F_30 ( & V_25 , V_24 ) ;
F_64 ( V_3 ) ;
F_31 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_30 = V_4 ;
break;
}
}
F_34 ( & V_25 , V_24 ) ;
if ( V_30 ) {
F_2 ( & V_3 -> V_3 , L_23 ,
V_30 -> V_28 ? L_24 : L_25 ) ;
if ( V_30 -> V_28 ) {
int V_55 = F_65 ( V_3 ) ;
F_66 ( L_26 ,
F_48 ( V_30 -> V_3 ) , V_55 ) ;
F_66 ( L_27 ) ;
F_66 ( L_28 ) ;
F_66 ( L_29 ) ;
F_67 ( V_30 -> V_28 ,
V_30 -> V_3 ,
false ) ;
}
F_30 ( & V_25 , V_24 ) ;
F_58 ( & V_30 -> V_46 ) ;
F_34 ( & V_25 , V_24 ) ;
F_27 ( V_30 ) ;
}
}
static void F_68 ( struct V_1 * V_4 )
{
struct V_56 V_57 ;
int V_18 ;
char V_58 [ V_59 ] ;
F_69 ( ! V_4 ) ;
snprintf ( V_58 , V_59 , L_30 ,
V_4 -> V_28 -> V_60 -> V_61 ) ;
V_62:
V_18 = F_70 ( & V_57 ) ;
if ( V_18 ) {
F_52 ( & V_4 -> V_3 -> V_3 ,
L_31 , V_18 ) ;
return;
}
F_71 ( V_57 , V_58 , L_32 , L_33 ) ;
V_18 = F_72 ( V_57 , 0 ) ;
if ( V_18 ) {
if ( V_18 == - V_63 )
goto V_62;
F_52 ( & V_4 -> V_3 -> V_3 ,
L_34 , V_18 ) ;
return;
}
}
static T_2 F_73 ( struct V_1 * V_4 ,
T_3 V_64 , int V_65 ,
T_2 V_66 )
{
T_2 V_67 = V_66 ;
struct V_68 * V_69 ;
struct V_27 * V_28 = V_4 -> V_28 ;
struct V_70 * V_71 = V_28 -> V_71 ;
int V_31 ;
V_69 = & ( V_71 -> V_69 ) ;
V_69 -> V_72 = V_65 ;
V_69 -> V_18 = V_64 ;
V_31 = F_74 ( V_4 -> V_3 , V_4 -> V_28 ,
& V_69 -> V_21 , & V_69 -> V_15 , & V_69 -> V_17 ) ;
if ( ! V_31 ) {
F_52 ( & V_4 -> V_3 -> V_3 ,
V_38 L_35 ) ;
return V_73 ;
}
F_75 () ;
F_2 ( & V_4 -> V_3 -> V_3 ,
V_38 L_36 ,
V_65 , V_69 -> V_21 , V_69 -> V_15 , V_69 -> V_17 ) ;
F_76 ( V_74 , ( unsigned long * ) & V_28 -> V_24 ) ;
F_76 ( V_75 ,
( unsigned long * ) & V_71 -> V_24 ) ;
F_75 () ;
F_77 ( V_28 -> V_76 ) ;
V_31 = F_78 ( V_41 ,
! ( F_79 ( V_75 , ( unsigned long * )
& V_71 -> V_24 ) ) , 300 * V_77 ) ;
if ( ! V_31 ) {
if ( F_79 ( V_75 ,
( unsigned long * ) & V_71 -> V_24 ) ) {
F_52 ( & V_4 -> V_3 -> V_3 ,
L_37 ) ;
F_80 ( V_75 ,
( unsigned long * ) & V_71 -> V_24 ) ;
V_69 -> V_18 = V_73 ;
return V_67 ;
}
}
F_80 ( V_74 , ( unsigned long * ) & V_28 -> V_24 ) ;
if ( F_79 ( V_78 ,
( unsigned long * ) & V_71 -> V_24 ) ) {
F_2 ( & V_4 -> V_3 -> V_3 ,
L_38 V_38 L_39 ) ;
F_81 ( V_4 -> V_28 ) ;
}
V_67 = ( T_2 ) V_69 -> V_18 ;
return V_67 ;
}
static T_2 F_82 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
T_2 V_66 ;
V_66 = V_79 ;
F_2 ( & V_3 -> V_3 , L_40 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_40 ( & V_32 ) ;
V_4 = F_29 ( F_16 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_32 ( V_3 -> V_17 ) ,
F_33 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_28 ) {
F_52 ( & V_3 -> V_3 ,
V_38 L_41 ) ;
goto V_80;
}
if ( ! V_4 -> V_28 -> V_71 ) {
F_52 ( & V_3 -> V_3 , V_38 L_42
L_43 ) ;
F_68 ( V_4 ) ;
goto V_80;
}
if ( ! F_79 ( V_81 ,
( unsigned long * ) & V_4 -> V_28 -> V_71 -> V_24 ) ) {
F_52 ( & V_3 -> V_3 ,
L_44 ) ;
goto V_80;
}
V_66 = F_73 ( V_4 , 1 , V_82 , V_66 ) ;
if ( V_66 == V_73 ||
V_66 == V_83 ) {
F_2 ( & V_3 -> V_3 ,
L_45 ) ;
F_68 ( V_4 ) ;
}
V_80:
if ( V_4 )
F_27 ( V_4 ) ;
F_44 ( & V_32 ) ;
return V_66 ;
}
static T_2 F_83 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
T_2 V_66 ;
V_66 = V_79 ;
F_2 ( & V_3 -> V_3 , L_46 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_40 ( & V_32 ) ;
V_4 = F_29 ( F_16 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_32 ( V_3 -> V_17 ) ,
F_33 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_28 ) {
F_52 ( & V_3 -> V_3 ,
V_38 L_41 ) ;
goto V_80;
}
if ( ! V_4 -> V_28 -> V_71 ) {
F_52 ( & V_3 -> V_3 , V_38 L_42
L_43 ) ;
F_68 ( V_4 ) ;
goto V_80;
}
if ( ! F_79 ( V_81 ,
( unsigned long * ) & V_4 -> V_28 -> V_71 -> V_24 ) ) {
F_52 ( & V_3 -> V_3 ,
L_44 ) ;
goto V_80;
}
V_66 = F_73 ( V_4 , 1 , V_84 , V_66 ) ;
if ( V_66 == V_73 ||
V_66 == V_83 ) {
F_2 ( & V_3 -> V_3 ,
L_47 ) ;
F_68 ( V_4 ) ;
}
V_80:
if ( V_4 )
F_27 ( V_4 ) ;
F_44 ( & V_32 ) ;
return V_66 ;
}
static T_2 F_84 ( struct V_2 * V_3 ,
T_3 error )
{
struct V_1 * V_4 ;
T_2 V_66 ;
V_66 = V_85 ;
F_2 ( & V_3 -> V_3 , L_48 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_40 ( & V_32 ) ;
V_4 = F_29 ( F_16 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_32 ( V_3 -> V_17 ) ,
F_33 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_28 ) {
F_52 ( & V_3 -> V_3 ,
V_38 L_41 ) ;
goto V_80;
}
if ( ! V_4 -> V_28 -> V_71 ) {
F_52 ( & V_3 -> V_3 , V_38 L_42
L_43 ) ;
F_68 ( V_4 ) ;
goto V_80;
}
if ( ! F_79 ( V_81 ,
( unsigned long * ) & V_4 -> V_28 -> V_71 -> V_24 ) ) {
F_2 ( & V_3 -> V_3 , L_49 ) ;
F_68 ( V_4 ) ;
goto V_80;
}
V_66 = F_73 ( V_4 , error , V_86 , V_66 ) ;
if ( V_66 == V_73 ||
V_66 == V_83 ) {
F_2 ( & V_3 -> V_3 ,
L_50 ) ;
F_68 ( V_4 ) ;
}
V_80:
if ( V_4 )
F_27 ( V_4 ) ;
F_44 ( & V_32 ) ;
return V_66 ;
}
static void F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_3 -> V_3 , L_51 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_40 ( & V_32 ) ;
V_4 = F_29 ( F_16 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_32 ( V_3 -> V_17 ) ,
F_33 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_28 ) {
F_52 ( & V_3 -> V_3 ,
V_38 L_41 ) ;
goto V_80;
}
if ( ! V_4 -> V_28 -> V_71 ) {
F_52 ( & V_3 -> V_3 , V_38 L_42
L_43 ) ;
F_68 ( V_4 ) ;
goto V_80;
}
if ( ! F_79 ( V_81 ,
( unsigned long * ) & V_4 -> V_28 -> V_71 -> V_24 ) ) {
F_52 ( & V_3 -> V_3 ,
L_44 ) ;
F_68 ( V_4 ) ;
goto V_80;
}
F_73 ( V_4 , 1 , V_87 ,
V_79 ) ;
V_80:
if ( V_4 )
F_27 ( V_4 ) ;
F_44 ( & V_32 ) ;
return;
}
static inline int F_86 ( const char * V_88 , int * V_21 , int * V_15 ,
int * V_22 , int * V_23 )
{
int V_89 = 0 ;
switch ( sscanf ( V_88 , L_52 , V_21 , V_15 , V_22 , V_23 ,
& V_89 ) ) {
case 3 :
* V_23 = - 1 ;
sscanf ( V_88 , L_53 , V_21 , V_15 , V_22 , & V_89 ) ;
break;
case 2 :
* V_22 = * V_23 = - 1 ;
sscanf ( V_88 , L_54 , V_21 , V_15 , & V_89 ) ;
break;
}
if ( V_89 && ! V_88 [ V_89 ] )
return 0 ;
* V_21 = 0 ;
switch ( sscanf ( V_88 , L_55 , V_15 , V_22 , V_23 , & V_89 ) ) {
case 2 :
* V_23 = - 1 ;
sscanf ( V_88 , L_56 , V_15 , V_22 , & V_89 ) ;
break;
case 1 :
* V_22 = * V_23 = - 1 ;
sscanf ( V_88 , L_57 , V_15 , & V_89 ) ;
break;
}
if ( V_89 && ! V_88 [ V_89 ] )
return 0 ;
return - V_90 ;
}
static inline int F_87 ( const char * V_88 , int * V_21 , int * V_15 , int
* V_22 , int * V_23 , int * V_91 , int * V_92 , int * V_93 )
{
int V_89 = 0 ;
sscanf ( V_88 , L_58 , V_21 , V_15 , V_22 , V_23 ,
V_91 , V_92 , V_93 , & V_89 ) ;
if ( V_89 && ! V_88 [ V_89 ] )
return 0 ;
* V_21 = 0 ;
sscanf ( V_88 , L_59 , V_15 , V_22 , V_23 , V_91 , V_92 ,
V_93 , & V_89 ) ;
if ( V_89 && ! V_88 [ V_89 ] )
return 0 ;
return - V_90 ;
}
static int F_88 ( int V_21 , int V_15 , int V_22 , int V_23 )
{
struct V_33 * V_94 ;
unsigned long V_24 ;
int V_95 = 0 , V_17 = F_89 ( V_22 , V_23 ) ;
if ( V_22 < 0 ) {
for ( V_22 = 0 ; ! V_95 && V_22 < 32 ; ++ V_22 )
V_95 = F_88 ( V_21 , V_15 , V_22 , V_23 ) ;
return V_95 ;
}
if ( V_23 < 0 ) {
for ( V_23 = 0 ; ! V_95 && V_23 < 8 ; ++ V_23 )
V_95 = F_88 ( V_21 , V_15 , V_22 , V_23 ) ;
return V_95 ;
}
if ( (
#if ! F_90 ( V_96 ) \
|| ! F_90 ( V_97 )
! V_98 ? V_21 :
#endif
V_21 < 0 || V_21 > 0xffff )
|| V_15 < 0 || V_15 > 0xff
|| F_32 ( V_17 ) != V_22
|| F_33 ( V_17 ) != V_23 )
return - V_90 ;
V_94 = F_91 ( sizeof( * V_94 ) , V_99 ) ;
if ( ! V_94 )
return - V_39 ;
V_94 -> V_21 = V_21 ;
V_94 -> V_15 = V_15 ;
V_94 -> V_17 = V_17 ;
F_92 ( L_60 ,
V_21 , V_15 , V_22 , V_23 ) ;
F_30 ( & V_37 , V_24 ) ;
F_59 ( & V_94 -> V_100 , & V_101 ) ;
F_34 ( & V_37 , V_24 ) ;
return 0 ;
}
static int F_93 ( int V_21 , int V_15 , int V_22 , int V_23 )
{
struct V_33 * V_94 , * V_102 ;
int V_18 = - V_103 ;
unsigned long V_24 ;
F_30 ( & V_37 , V_24 ) ;
F_94 (pci_dev_id, t, &pcistub_device_ids,
slot_list) {
if ( V_94 -> V_21 == V_21 && V_94 -> V_15 == V_15
&& ( V_22 < 0 || F_32 ( V_94 -> V_17 ) == V_22 )
&& ( V_23 < 0 || F_33 ( V_94 -> V_17 ) == V_23 ) ) {
F_58 ( & V_94 -> V_100 ) ;
F_5 ( V_94 ) ;
V_18 = 0 ;
F_92 ( L_61 ,
V_21 , V_15 , V_22 , V_23 ) ;
}
}
F_34 ( & V_37 , V_24 ) ;
return V_18 ;
}
static int F_95 ( int V_21 , int V_15 , int V_22 , int V_23 ,
unsigned int V_91 , unsigned int V_92 ,
unsigned int V_93 )
{
int V_18 = 0 ;
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_104 * V_105 ;
if ( V_91 > 0xfff || ( V_92 < 4 && ( V_93 >> ( V_92 * 8 ) ) ) )
return - V_90 ;
V_4 = F_29 ( V_21 , V_15 , V_22 , V_23 ) ;
if ( ! V_4 ) {
V_18 = - V_54 ;
goto V_26;
}
V_3 = V_4 -> V_3 ;
V_105 = F_3 ( sizeof( * V_105 ) , V_5 ) ;
if ( ! V_105 ) {
V_18 = - V_39 ;
goto V_26;
}
V_105 -> V_106 = V_91 ;
V_105 -> V_92 = V_92 ;
V_105 -> V_93 = V_93 ;
V_105 -> V_107 = NULL ;
V_105 -> V_108 = NULL ;
V_105 -> V_109 = NULL ;
V_105 -> V_110 = V_111 ;
V_18 = F_96 ( V_3 , V_105 ) ;
if ( V_18 )
F_5 ( V_105 ) ;
V_26:
if ( V_4 )
F_27 ( V_4 ) ;
return V_18 ;
}
static T_4 F_97 ( struct V_112 * V_113 , const char * V_88 ,
T_5 V_114 )
{
int V_21 , V_15 , V_22 , V_23 ;
int V_18 ;
V_18 = F_86 ( V_88 , & V_21 , & V_15 , & V_22 , & V_23 ) ;
if ( V_18 )
goto V_26;
V_18 = F_88 ( V_21 , V_15 , V_22 , V_23 ) ;
V_26:
if ( ! V_18 )
V_18 = V_114 ;
return V_18 ;
}
static T_4 F_98 ( struct V_112 * V_113 , const char * V_88 ,
T_5 V_114 )
{
int V_21 , V_15 , V_22 , V_23 ;
int V_18 ;
V_18 = F_86 ( V_88 , & V_21 , & V_15 , & V_22 , & V_23 ) ;
if ( V_18 )
goto V_26;
V_18 = F_93 ( V_21 , V_15 , V_22 , V_23 ) ;
V_26:
if ( ! V_18 )
V_18 = V_114 ;
return V_18 ;
}
static T_4 F_99 ( struct V_112 * V_113 , char * V_88 )
{
struct V_33 * V_94 ;
T_5 V_114 = 0 ;
unsigned long V_24 ;
F_30 ( & V_37 , V_24 ) ;
F_31 (pci_dev_id, &pcistub_device_ids, slot_list) {
if ( V_114 >= V_115 )
break;
V_114 += F_100 ( V_88 + V_114 , V_115 - V_114 ,
L_62 ,
V_94 -> V_21 , V_94 -> V_15 ,
F_32 ( V_94 -> V_17 ) ,
F_33 ( V_94 -> V_17 ) ) ;
}
F_34 ( & V_37 , V_24 ) ;
return V_114 ;
}
static T_4 F_101 ( struct V_112 * V_113 , char * V_88 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
T_5 V_114 = 0 ;
unsigned long V_24 ;
F_30 ( & V_25 , V_24 ) ;
F_31 (psdev, &pcistub_devices, dev_list) {
if ( V_114 >= V_115 )
break;
if ( ! V_4 -> V_3 )
continue;
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 )
continue;
V_114 +=
F_100 ( V_88 + V_114 , V_115 - V_114 ,
L_63 ,
F_48 ( V_4 -> V_3 ) ,
V_9 -> V_116 ? L_64 : L_65 ,
V_9 -> V_117 ? L_66 : L_67 ,
V_9 -> V_118 ) ;
}
F_34 ( & V_25 , V_24 ) ;
return V_114 ;
}
static T_4 F_102 ( struct V_112 * V_113 ,
const char * V_88 ,
T_5 V_114 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
int V_21 , V_15 , V_22 , V_23 ;
int V_18 ;
V_18 = F_86 ( V_88 , & V_21 , & V_15 , & V_22 , & V_23 ) ;
if ( V_18 )
return V_18 ;
V_4 = F_29 ( V_21 , V_15 , V_22 , V_23 ) ;
if ( ! V_4 ) {
V_18 = - V_103 ;
goto V_26;
}
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 ) {
V_18 = - V_103 ;
goto V_26;
}
F_2 ( & V_4 -> V_3 -> V_3 , L_68 ,
V_9 -> V_40 , V_9 -> V_116 ,
! V_9 -> V_116 ) ;
V_9 -> V_116 = ! ( V_9 -> V_116 ) ;
if ( V_9 -> V_116 )
V_9 -> V_117 = 1 ;
V_26:
if ( V_4 )
F_27 ( V_4 ) ;
if ( ! V_18 )
V_18 = V_114 ;
return V_18 ;
}
static T_4 F_103 ( struct V_112 * V_113 , const char * V_88 ,
T_5 V_114 )
{
int V_21 , V_15 , V_22 , V_23 , V_91 , V_92 , V_93 ;
int V_18 ;
V_18 = F_87 ( V_88 , & V_21 , & V_15 , & V_22 , & V_23 , & V_91 , & V_92 ,
& V_93 ) ;
if ( V_18 )
goto V_26;
V_18 = F_95 ( V_21 , V_15 , V_22 , V_23 , V_91 , V_92 , V_93 ) ;
V_26:
if ( ! V_18 )
V_18 = V_114 ;
return V_18 ;
}
static T_4 F_104 ( struct V_112 * V_113 , char * V_88 )
{
int V_114 = 0 ;
unsigned long V_24 ;
struct V_119 * V_120 ;
struct V_8 * V_9 ;
const struct V_104 * V_105 ;
const struct V_121 * V_122 ;
F_30 ( & V_37 , V_24 ) ;
F_31 (quirk, &xen_pcibk_quirks, quirks_list) {
if ( V_114 >= V_115 )
goto V_26;
V_114 += F_100 ( V_88 + V_114 , V_115 - V_114 ,
L_69 ,
V_120 -> V_28 -> V_15 -> V_16 ,
F_32 ( V_120 -> V_28 -> V_17 ) ,
F_33 ( V_120 -> V_28 -> V_17 ) ,
V_120 -> V_123 . V_124 , V_120 -> V_123 . V_125 ,
V_120 -> V_123 . V_126 ,
V_120 -> V_123 . V_127 ) ;
V_9 = F_10 ( V_120 -> V_28 ) ;
F_31 (cfg_entry, &dev_data->config_fields, list) {
V_105 = V_122 -> V_105 ;
if ( V_114 >= V_115 )
goto V_26;
V_114 += F_100 ( V_88 + V_114 , V_115 - V_114 ,
L_70 ,
V_122 -> V_128 +
V_105 -> V_106 , V_105 -> V_92 ,
V_105 -> V_93 ) ;
}
}
V_26:
F_34 ( & V_37 , V_24 ) ;
return V_114 ;
}
static T_4 F_105 ( struct V_112 * V_113 , const char * V_88 ,
T_5 V_114 )
{
int V_21 , V_15 , V_22 , V_23 ;
int V_18 ;
struct V_1 * V_4 ;
struct V_8 * V_9 ;
V_18 = F_86 ( V_88 , & V_21 , & V_15 , & V_22 , & V_23 ) ;
if ( V_18 )
goto V_26;
V_4 = F_29 ( V_21 , V_15 , V_22 , V_23 ) ;
if ( ! V_4 ) {
V_18 = - V_54 ;
goto V_26;
}
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 ) {
V_18 = - V_129 ;
goto V_109;
}
if ( ! V_9 -> V_130 ) {
V_9 -> V_130 = 1 ;
F_18 ( & V_4 -> V_3 -> V_3 , L_71
L_72 ) ;
F_18 ( & V_4 -> V_3 -> V_3 ,
L_73 ) ;
}
V_109:
F_27 ( V_4 ) ;
V_26:
if ( ! V_18 )
V_18 = V_114 ;
return V_18 ;
}
static T_4 F_106 ( struct V_112 * V_113 , char * V_88 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
T_5 V_114 = 0 ;
unsigned long V_24 ;
F_30 ( & V_25 , V_24 ) ;
F_31 (psdev, &pcistub_devices, dev_list) {
if ( V_114 >= V_115 )
break;
if ( ! V_4 -> V_3 )
continue;
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 || ! V_9 -> V_130 )
continue;
V_114 +=
F_100 ( V_88 + V_114 , V_115 - V_114 , L_74 ,
F_48 ( V_4 -> V_3 ) ) ;
}
F_34 ( & V_25 , V_24 ) ;
return V_114 ;
}
static void F_107 ( void )
{
F_108 ( & V_131 . V_132 , & V_133 ) ;
F_108 ( & V_131 . V_132 ,
& V_134 ) ;
F_108 ( & V_131 . V_132 , & V_135 ) ;
F_108 ( & V_131 . V_132 , & V_136 ) ;
F_108 ( & V_131 . V_132 ,
& V_137 ) ;
F_108 ( & V_131 . V_132 ,
& V_138 ) ;
F_108 ( & V_131 . V_132 ,
& V_139 ) ;
F_109 ( & V_131 ) ;
}
static int T_1 F_110 ( void )
{
int V_140 = 0 ;
int V_18 = 0 ;
int V_21 , V_15 , V_22 , V_23 ;
int V_89 ;
if ( V_141 && * V_141 ) {
do {
V_89 = 0 ;
V_18 = sscanf ( V_141 + V_140 ,
L_75 ,
& V_21 , & V_15 , & V_22 , & V_23 , & V_89 ) ;
switch ( V_18 ) {
case 3 :
V_23 = - 1 ;
sscanf ( V_141 + V_140 ,
L_76 ,
& V_21 , & V_15 , & V_22 , & V_89 ) ;
break;
case 2 :
V_22 = V_23 = - 1 ;
sscanf ( V_141 + V_140 ,
L_77 ,
& V_21 , & V_15 , & V_89 ) ;
break;
}
if ( ! V_89 ) {
V_21 = 0 ;
V_18 = sscanf ( V_141 + V_140 ,
L_78 ,
& V_15 , & V_22 , & V_23 , & V_89 ) ;
switch ( V_18 ) {
case 2 :
V_23 = - 1 ;
sscanf ( V_141 + V_140 ,
L_79 ,
& V_15 , & V_22 , & V_89 ) ;
break;
case 1 :
V_22 = V_23 = - 1 ;
sscanf ( V_141 + V_140 ,
L_80 ,
& V_15 , & V_89 ) ;
break;
}
}
if ( V_89 <= 0 )
goto V_142;
V_18 = F_88 ( V_21 , V_15 , V_22 , V_23 ) ;
if ( V_18 )
goto V_26;
V_140 += V_89 ;
} while ( V_141 [ V_140 ] );
}
V_18 = F_111 ( & V_131 ) ;
if ( V_18 < 0 )
goto V_26;
V_18 = F_112 ( & V_131 . V_132 ,
& V_133 ) ;
if ( ! V_18 )
V_18 = F_112 ( & V_131 . V_132 ,
& V_134 ) ;
if ( ! V_18 )
V_18 = F_112 ( & V_131 . V_132 ,
& V_135 ) ;
if ( ! V_18 )
V_18 = F_112 ( & V_131 . V_132 ,
& V_136 ) ;
if ( ! V_18 )
V_18 = F_112 ( & V_131 . V_132 ,
& V_137 ) ;
if ( ! V_18 )
V_18 = F_112 ( & V_131 . V_132 ,
& V_138 ) ;
if ( ! V_18 )
V_18 = F_112 ( & V_131 . V_132 ,
& V_139 ) ;
if ( V_18 )
F_107 () ;
V_26:
return V_18 ;
V_142:
F_113 ( L_81 ,
V_141 + V_140 ) ;
return - V_90 ;
}
static struct V_1 * F_114 ( const struct V_2 * V_28 )
{
struct V_1 * V_4 = NULL ;
unsigned long V_24 ;
bool V_36 = false ;
F_30 ( & V_25 , V_24 ) ;
F_31 (psdev, &pcistub_devices, dev_list) {
if ( ! V_4 -> V_28 && V_4 -> V_3 != V_28
&& F_115 ( V_4 -> V_3 ) == V_28 ) {
V_36 = true ;
break;
}
}
F_34 ( & V_25 , V_24 ) ;
if ( V_36 )
return V_4 ;
return NULL ;
}
static int F_116 ( struct V_143 * V_144 ,
unsigned long V_145 , void * V_146 )
{
struct V_125 * V_3 = V_146 ;
const struct V_2 * V_28 = F_117 ( V_3 ) ;
if ( V_145 != V_147 )
return V_148 ;
if ( ! V_28 -> V_149 )
return V_148 ;
for (; ; ) {
struct V_1 * V_4 = F_114 ( V_28 ) ;
if ( ! V_4 )
break;
F_118 ( & V_4 -> V_3 -> V_3 ) ;
}
return V_148 ;
}
static int T_1 F_119 ( void )
{
int V_18 ;
if ( ! F_120 () )
return - V_54 ;
V_18 = F_121 () ;
if ( V_18 )
return V_18 ;
#ifdef V_96
V_18 = F_110 () ;
if ( V_18 < 0 )
return V_18 ;
#endif
F_56 () ;
V_18 = F_122 () ;
if ( V_18 )
F_107 () ;
#ifdef F_123
else
F_124 ( & V_150 , & V_151 ) ;
#endif
return V_18 ;
}
static void T_6 F_125 ( void )
{
#ifdef F_123
F_126 ( & V_150 , & V_151 ) ;
#endif
F_127 () ;
F_107 () ;
}
