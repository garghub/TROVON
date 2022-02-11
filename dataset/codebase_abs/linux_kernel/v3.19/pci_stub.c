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
if ( V_18 )
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
static struct V_1 * F_29 ( int V_20 , int V_15 ,
int V_21 , int V_22 )
{
struct V_1 * V_4 = NULL ;
unsigned long V_23 ;
F_30 ( & V_24 , V_23 ) ;
F_31 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 != NULL
&& V_20 == F_16 ( V_4 -> V_3 -> V_15 )
&& V_15 == V_4 -> V_3 -> V_15 -> V_16
&& V_21 == F_32 ( V_4 -> V_3 -> V_17 )
&& V_22 == F_33 ( V_4 -> V_3 -> V_17 ) ) {
F_25 ( V_4 ) ;
goto V_25;
}
}
V_4 = NULL ;
V_25:
F_34 ( & V_24 , V_23 ) ;
return V_4 ;
}
static struct V_2 * F_35 ( struct V_26 * V_27 ,
struct V_1 * V_4 )
{
struct V_2 * V_2 = NULL ;
unsigned long V_23 ;
F_25 ( V_4 ) ;
F_30 ( & V_4 -> V_7 , V_23 ) ;
if ( ! V_4 -> V_27 ) {
V_4 -> V_27 = V_27 ;
V_2 = V_4 -> V_3 ;
}
F_34 ( & V_4 -> V_7 , V_23 ) ;
if ( ! V_2 )
F_27 ( V_4 ) ;
return V_2 ;
}
struct V_2 * F_36 ( struct V_26 * V_27 ,
int V_20 , int V_15 ,
int V_21 , int V_22 )
{
struct V_1 * V_4 ;
struct V_2 * V_28 = NULL ;
unsigned long V_23 ;
F_30 ( & V_24 , V_23 ) ;
F_31 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 != NULL
&& V_20 == F_16 ( V_4 -> V_3 -> V_15 )
&& V_15 == V_4 -> V_3 -> V_15 -> V_16
&& V_21 == F_32 ( V_4 -> V_3 -> V_17 )
&& V_22 == F_33 ( V_4 -> V_3 -> V_17 ) ) {
V_28 = F_35 ( V_27 , V_4 ) ;
break;
}
}
F_34 ( & V_24 , V_23 ) ;
return V_28 ;
}
struct V_2 * F_37 ( struct V_26 * V_27 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_2 * V_28 = NULL ;
unsigned long V_23 ;
F_30 ( & V_24 , V_23 ) ;
F_31 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_28 = F_35 ( V_27 , V_4 ) ;
break;
}
}
F_34 ( & V_24 , V_23 ) ;
return V_28 ;
}
void F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_29 = NULL ;
unsigned long V_23 ;
struct V_8 * V_9 ;
int V_30 ;
F_30 ( & V_24 , V_23 ) ;
F_31 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_29 = V_4 ;
break;
}
}
F_34 ( & V_24 , V_23 ) ;
if ( F_39 ( ! V_29 ) )
return;
F_40 ( & V_31 ) ;
F_41 ( & V_3 -> V_3 ) ;
F_12 ( V_3 ) ;
V_9 = F_10 ( V_3 ) ;
V_30 = F_42 ( V_3 , V_9 -> V_10 ) ;
if ( ! V_30 ) {
F_15 ( V_3 ) ;
} else
F_14 ( & V_3 -> V_3 , L_3 ) ;
F_19 ( V_3 ) ;
F_43 ( V_3 ) ;
F_21 ( V_3 ) ;
F_11 ( V_3 ) ;
F_30 ( & V_29 -> V_7 , V_23 ) ;
V_29 -> V_27 = NULL ;
F_34 ( & V_29 -> V_7 , V_23 ) ;
F_27 ( V_29 ) ;
F_44 ( & V_31 ) ;
}
static int F_45 ( struct V_2 * V_3 ,
struct V_32 * V_33 )
{
for (; V_3 != NULL ; V_3 = V_3 -> V_15 -> V_34 ) {
if ( F_16 ( V_3 -> V_15 ) == V_33 -> V_20
&& V_3 -> V_15 -> V_16 == V_33 -> V_15
&& V_3 -> V_17 == V_33 -> V_17 )
return 1 ;
if ( V_3 == V_3 -> V_15 -> V_34 )
break;
}
return 0 ;
}
static int F_46 ( struct V_2 * V_3 )
{
struct V_32 * V_33 ;
unsigned long V_23 ;
int V_35 = 0 ;
F_30 ( & V_36 , V_23 ) ;
F_31 (pdev_id, &pcistub_device_ids, slot_list) {
if ( F_45 ( V_3 , V_33 ) ) {
V_35 = 1 ;
break;
}
}
F_34 ( & V_36 , V_23 ) ;
return V_35 ;
}
static int F_47 ( struct V_2 * V_3 )
{
struct V_8 * V_9 ;
int V_18 = 0 ;
F_2 ( & V_3 -> V_3 , L_5 ) ;
V_9 = F_3 ( sizeof( * V_9 ) + strlen ( V_37 L_6 )
+ strlen ( F_48 ( V_3 ) ) + 1 , V_5 ) ;
if ( ! V_9 ) {
V_18 = - V_38 ;
goto V_25;
}
F_20 ( V_3 , V_9 ) ;
sprintf ( V_9 -> V_39 , V_37 L_7 , F_48 ( V_3 ) ) ;
F_2 ( & V_3 -> V_3 , L_8 ) ;
F_49 ( & V_40 ) ;
V_18 = F_50 ( V_3 ) ;
if ( V_18 )
goto V_25;
F_2 ( & V_3 -> V_3 , L_9 ) ;
V_18 = F_51 ( V_3 ) ;
if ( V_18 )
goto V_41;
if ( V_3 -> V_11 ) {
struct V_12 V_13 = {
. V_14 = F_16 ( V_3 -> V_15 ) ,
. V_15 = V_3 -> V_15 -> V_16 ,
. V_17 = V_3 -> V_17
} ;
V_18 = F_17 ( V_42 , & V_13 ) ;
if ( V_18 )
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
V_41:
F_22 ( V_3 ) ;
V_25:
F_20 ( V_3 , NULL ) ;
F_5 ( V_9 ) ;
return V_18 ;
}
static int T_1 F_56 ( void )
{
struct V_1 * V_4 ;
unsigned long V_23 ;
int V_18 = 0 ;
F_30 ( & V_24 , V_23 ) ;
while ( ! F_57 ( & V_43 ) ) {
V_4 = F_9 ( V_43 . V_44 ,
struct V_1 , V_45 ) ;
F_58 ( & V_4 -> V_45 ) ;
F_34 ( & V_24 , V_23 ) ;
V_18 = F_47 ( V_4 -> V_3 ) ;
if ( V_18 ) {
F_52 ( & V_4 -> V_3 -> V_3 ,
L_15 , V_18 ) ;
F_5 ( V_4 ) ;
V_4 = NULL ;
}
F_30 ( & V_24 , V_23 ) ;
if ( V_4 )
F_59 ( & V_4 -> V_45 , & V_46 ) ;
}
V_47 = 1 ;
F_34 ( & V_24 , V_23 ) ;
return 0 ;
}
static int F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_23 ;
int V_18 = 0 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_38 ;
F_30 ( & V_24 , V_23 ) ;
if ( V_47 ) {
F_34 ( & V_24 , V_23 ) ;
V_18 = F_47 ( V_4 -> V_3 ) ;
F_30 ( & V_24 , V_23 ) ;
if ( ! V_18 )
F_61 ( & V_4 -> V_45 , & V_46 ) ;
} else {
F_2 ( & V_3 -> V_3 , L_16 ) ;
F_61 ( & V_4 -> V_45 , & V_43 ) ;
}
F_34 ( & V_24 , V_23 ) ;
if ( V_18 )
F_27 ( V_4 ) ;
return V_18 ;
}
static int F_62 ( struct V_2 * V_3 , const struct V_48 * V_49 )
{
int V_18 = 0 ;
F_2 ( & V_3 -> V_3 , L_17 ) ;
if ( F_46 ( V_3 ) ) {
if ( V_3 -> V_50 != V_51
&& V_3 -> V_50 != V_52 ) {
F_52 ( & V_3 -> V_3 , L_18
L_19
L_20 ) ;
V_18 = - V_53 ;
goto V_25;
}
F_14 ( & V_3 -> V_3 , L_21 ) ;
V_18 = F_60 ( V_3 ) ;
} else
V_18 = - V_53 ;
V_25:
return V_18 ;
}
static void F_63 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_29 = NULL ;
unsigned long V_23 ;
F_2 ( & V_3 -> V_3 , L_22 ) ;
F_30 ( & V_24 , V_23 ) ;
F_64 ( V_3 ) ;
F_31 (psdev, &pcistub_devices, dev_list) {
if ( V_4 -> V_3 == V_3 ) {
V_29 = V_4 ;
break;
}
}
F_34 ( & V_24 , V_23 ) ;
if ( V_29 ) {
F_2 ( & V_3 -> V_3 , L_23 ,
V_29 -> V_27 ? L_24 : L_25 ) ;
if ( V_29 -> V_27 ) {
int V_54 = F_65 ( V_3 ) ;
F_66 ( L_26 ,
F_48 ( V_29 -> V_3 ) , V_54 ) ;
F_66 ( L_27 ) ;
F_66 ( L_28 ) ;
F_66 ( L_29 ) ;
F_67 ( V_29 -> V_27 ,
V_29 -> V_3 ,
false ) ;
}
F_30 ( & V_24 , V_23 ) ;
F_58 ( & V_29 -> V_45 ) ;
F_34 ( & V_24 , V_23 ) ;
F_27 ( V_29 ) ;
}
}
static void F_68 ( struct V_1 * V_4 )
{
struct V_55 V_56 ;
int V_18 ;
char V_57 [ V_58 ] ;
F_69 ( ! V_4 ) ;
snprintf ( V_57 , V_58 , L_30 ,
V_4 -> V_27 -> V_59 -> V_60 ) ;
V_61:
V_18 = F_70 ( & V_56 ) ;
if ( V_18 ) {
F_52 ( & V_4 -> V_3 -> V_3 ,
L_31 , V_18 ) ;
return;
}
F_71 ( V_56 , V_57 , L_32 , L_33 ) ;
V_18 = F_72 ( V_56 , 0 ) ;
if ( V_18 ) {
if ( V_18 == - V_62 )
goto V_61;
F_52 ( & V_4 -> V_3 -> V_3 ,
L_34 , V_18 ) ;
return;
}
}
static T_2 F_73 ( struct V_1 * V_4 ,
T_3 V_63 , int V_64 ,
T_2 V_65 )
{
T_2 V_66 = V_65 ;
struct V_67 * V_68 ;
struct V_26 * V_27 = V_4 -> V_27 ;
struct V_69 * V_70 = V_27 -> V_70 ;
int V_30 ;
V_68 = & ( V_70 -> V_68 ) ;
V_68 -> V_71 = V_64 ;
V_68 -> V_18 = V_63 ;
V_30 = F_74 ( V_4 -> V_3 , V_4 -> V_27 ,
& V_68 -> V_20 , & V_68 -> V_15 , & V_68 -> V_17 ) ;
if ( ! V_30 ) {
F_52 ( & V_4 -> V_3 -> V_3 ,
V_37 L_35 ) ;
return V_72 ;
}
F_75 () ;
F_2 ( & V_4 -> V_3 -> V_3 ,
V_37 L_36 ,
V_64 , V_68 -> V_20 , V_68 -> V_15 , V_68 -> V_17 ) ;
F_76 ( V_73 , ( unsigned long * ) & V_27 -> V_23 ) ;
F_76 ( V_74 ,
( unsigned long * ) & V_70 -> V_23 ) ;
F_75 () ;
F_77 ( V_27 -> V_75 ) ;
V_30 = F_78 ( V_40 ,
! ( F_79 ( V_74 , ( unsigned long * )
& V_70 -> V_23 ) ) , 300 * V_76 ) ;
if ( ! V_30 ) {
if ( F_79 ( V_74 ,
( unsigned long * ) & V_70 -> V_23 ) ) {
F_52 ( & V_4 -> V_3 -> V_3 ,
L_37 ) ;
F_80 ( V_74 ,
( unsigned long * ) & V_70 -> V_23 ) ;
V_68 -> V_18 = V_72 ;
return V_66 ;
}
}
F_80 ( V_73 , ( unsigned long * ) & V_27 -> V_23 ) ;
if ( F_79 ( V_77 ,
( unsigned long * ) & V_70 -> V_23 ) ) {
F_2 ( & V_4 -> V_3 -> V_3 ,
L_38 V_37 L_39 ) ;
F_81 ( V_4 -> V_27 ) ;
}
V_66 = ( T_2 ) V_68 -> V_18 ;
return V_66 ;
}
static T_2 F_82 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
T_2 V_65 ;
V_65 = V_78 ;
F_2 ( & V_3 -> V_3 , L_40 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_40 ( & V_31 ) ;
V_4 = F_29 ( F_16 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_32 ( V_3 -> V_17 ) ,
F_33 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_27 ) {
F_52 ( & V_3 -> V_3 ,
V_37 L_41 ) ;
goto V_79;
}
if ( ! V_4 -> V_27 -> V_70 ) {
F_52 ( & V_3 -> V_3 , V_37 L_42
L_43 ) ;
F_68 ( V_4 ) ;
goto V_79;
}
if ( ! F_79 ( V_80 ,
( unsigned long * ) & V_4 -> V_27 -> V_70 -> V_23 ) ) {
F_52 ( & V_3 -> V_3 ,
L_44 ) ;
goto V_79;
}
V_65 = F_73 ( V_4 , 1 , V_81 , V_65 ) ;
if ( V_65 == V_72 ||
V_65 == V_82 ) {
F_2 ( & V_3 -> V_3 ,
L_45 ) ;
F_68 ( V_4 ) ;
}
V_79:
if ( V_4 )
F_27 ( V_4 ) ;
F_44 ( & V_31 ) ;
return V_65 ;
}
static T_2 F_83 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
T_2 V_65 ;
V_65 = V_78 ;
F_2 ( & V_3 -> V_3 , L_46 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_40 ( & V_31 ) ;
V_4 = F_29 ( F_16 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_32 ( V_3 -> V_17 ) ,
F_33 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_27 ) {
F_52 ( & V_3 -> V_3 ,
V_37 L_41 ) ;
goto V_79;
}
if ( ! V_4 -> V_27 -> V_70 ) {
F_52 ( & V_3 -> V_3 , V_37 L_42
L_43 ) ;
F_68 ( V_4 ) ;
goto V_79;
}
if ( ! F_79 ( V_80 ,
( unsigned long * ) & V_4 -> V_27 -> V_70 -> V_23 ) ) {
F_52 ( & V_3 -> V_3 ,
L_44 ) ;
goto V_79;
}
V_65 = F_73 ( V_4 , 1 , V_83 , V_65 ) ;
if ( V_65 == V_72 ||
V_65 == V_82 ) {
F_2 ( & V_3 -> V_3 ,
L_47 ) ;
F_68 ( V_4 ) ;
}
V_79:
if ( V_4 )
F_27 ( V_4 ) ;
F_44 ( & V_31 ) ;
return V_65 ;
}
static T_2 F_84 ( struct V_2 * V_3 ,
T_3 error )
{
struct V_1 * V_4 ;
T_2 V_65 ;
V_65 = V_84 ;
F_2 ( & V_3 -> V_3 , L_48 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_40 ( & V_31 ) ;
V_4 = F_29 ( F_16 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_32 ( V_3 -> V_17 ) ,
F_33 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_27 ) {
F_52 ( & V_3 -> V_3 ,
V_37 L_41 ) ;
goto V_79;
}
if ( ! V_4 -> V_27 -> V_70 ) {
F_52 ( & V_3 -> V_3 , V_37 L_42
L_43 ) ;
F_68 ( V_4 ) ;
goto V_79;
}
if ( ! F_79 ( V_80 ,
( unsigned long * ) & V_4 -> V_27 -> V_70 -> V_23 ) ) {
F_2 ( & V_3 -> V_3 , L_49 ) ;
F_68 ( V_4 ) ;
goto V_79;
}
V_65 = F_73 ( V_4 , error , V_85 , V_65 ) ;
if ( V_65 == V_72 ||
V_65 == V_82 ) {
F_2 ( & V_3 -> V_3 ,
L_50 ) ;
F_68 ( V_4 ) ;
}
V_79:
if ( V_4 )
F_27 ( V_4 ) ;
F_44 ( & V_31 ) ;
return V_65 ;
}
static void F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_3 -> V_3 , L_51 ,
V_3 -> V_15 -> V_16 , V_3 -> V_17 ) ;
F_40 ( & V_31 ) ;
V_4 = F_29 ( F_16 ( V_3 -> V_15 ) ,
V_3 -> V_15 -> V_16 ,
F_32 ( V_3 -> V_17 ) ,
F_33 ( V_3 -> V_17 ) ) ;
if ( ! V_4 || ! V_4 -> V_27 ) {
F_52 ( & V_3 -> V_3 ,
V_37 L_41 ) ;
goto V_79;
}
if ( ! V_4 -> V_27 -> V_70 ) {
F_52 ( & V_3 -> V_3 , V_37 L_42
L_43 ) ;
F_68 ( V_4 ) ;
goto V_79;
}
if ( ! F_79 ( V_80 ,
( unsigned long * ) & V_4 -> V_27 -> V_70 -> V_23 ) ) {
F_52 ( & V_3 -> V_3 ,
L_44 ) ;
F_68 ( V_4 ) ;
goto V_79;
}
F_73 ( V_4 , 1 , V_86 ,
V_78 ) ;
V_79:
if ( V_4 )
F_27 ( V_4 ) ;
F_44 ( & V_31 ) ;
return;
}
static inline int F_86 ( const char * V_87 , int * V_20 , int * V_15 ,
int * V_21 , int * V_22 )
{
int V_88 = 0 ;
switch ( sscanf ( V_87 , L_52 , V_20 , V_15 , V_21 , V_22 ,
& V_88 ) ) {
case 3 :
* V_22 = - 1 ;
sscanf ( V_87 , L_53 , V_20 , V_15 , V_21 , & V_88 ) ;
break;
case 2 :
* V_21 = * V_22 = - 1 ;
sscanf ( V_87 , L_54 , V_20 , V_15 , & V_88 ) ;
break;
}
if ( V_88 && ! V_87 [ V_88 ] )
return 0 ;
* V_20 = 0 ;
switch ( sscanf ( V_87 , L_55 , V_15 , V_21 , V_22 , & V_88 ) ) {
case 2 :
* V_22 = - 1 ;
sscanf ( V_87 , L_56 , V_15 , V_21 , & V_88 ) ;
break;
case 1 :
* V_21 = * V_22 = - 1 ;
sscanf ( V_87 , L_57 , V_15 , & V_88 ) ;
break;
}
if ( V_88 && ! V_87 [ V_88 ] )
return 0 ;
return - V_89 ;
}
static inline int F_87 ( const char * V_87 , int * V_20 , int * V_15 , int
* V_21 , int * V_22 , int * V_90 , int * V_91 , int * V_92 )
{
int V_88 = 0 ;
sscanf ( V_87 , L_58 , V_20 , V_15 , V_21 , V_22 ,
V_90 , V_91 , V_92 , & V_88 ) ;
if ( V_88 && ! V_87 [ V_88 ] )
return 0 ;
* V_20 = 0 ;
sscanf ( V_87 , L_59 , V_15 , V_21 , V_22 , V_90 , V_91 ,
V_92 , & V_88 ) ;
if ( V_88 && ! V_87 [ V_88 ] )
return 0 ;
return - V_89 ;
}
static int F_88 ( int V_20 , int V_15 , int V_21 , int V_22 )
{
struct V_32 * V_93 ;
unsigned long V_23 ;
int V_94 = 0 , V_17 = F_89 ( V_21 , V_22 ) ;
if ( V_21 < 0 ) {
for ( V_21 = 0 ; ! V_94 && V_21 < 32 ; ++ V_21 )
V_94 = F_88 ( V_20 , V_15 , V_21 , V_22 ) ;
return V_94 ;
}
if ( V_22 < 0 ) {
for ( V_22 = 0 ; ! V_94 && V_22 < 8 ; ++ V_22 )
V_94 = F_88 ( V_20 , V_15 , V_21 , V_22 ) ;
return V_94 ;
}
if ( (
#if ! F_90 ( V_95 ) \
|| ! F_90 ( V_96 )
! V_97 ? V_20 :
#endif
V_20 < 0 || V_20 > 0xffff )
|| V_15 < 0 || V_15 > 0xff
|| F_32 ( V_17 ) != V_21
|| F_33 ( V_17 ) != V_22 )
return - V_89 ;
V_93 = F_91 ( sizeof( * V_93 ) , V_98 ) ;
if ( ! V_93 )
return - V_38 ;
V_93 -> V_20 = V_20 ;
V_93 -> V_15 = V_15 ;
V_93 -> V_17 = V_17 ;
F_92 ( L_60 ,
V_20 , V_15 , V_21 , V_22 ) ;
F_30 ( & V_36 , V_23 ) ;
F_59 ( & V_93 -> V_99 , & V_100 ) ;
F_34 ( & V_36 , V_23 ) ;
return 0 ;
}
static int F_93 ( int V_20 , int V_15 , int V_21 , int V_22 )
{
struct V_32 * V_93 , * V_101 ;
int V_18 = - V_102 ;
unsigned long V_23 ;
F_30 ( & V_36 , V_23 ) ;
F_94 (pci_dev_id, t, &pcistub_device_ids,
slot_list) {
if ( V_93 -> V_20 == V_20 && V_93 -> V_15 == V_15
&& ( V_21 < 0 || F_32 ( V_93 -> V_17 ) == V_21 )
&& ( V_22 < 0 || F_33 ( V_93 -> V_17 ) == V_22 ) ) {
F_58 ( & V_93 -> V_99 ) ;
F_5 ( V_93 ) ;
V_18 = 0 ;
F_92 ( L_61 ,
V_20 , V_15 , V_21 , V_22 ) ;
}
}
F_34 ( & V_36 , V_23 ) ;
return V_18 ;
}
static int F_95 ( int V_20 , int V_15 , int V_21 , int V_22 ,
unsigned int V_90 , unsigned int V_91 ,
unsigned int V_92 )
{
int V_18 = 0 ;
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_103 * V_104 ;
if ( V_90 > 0xfff || ( V_91 < 4 && ( V_92 >> ( V_91 * 8 ) ) ) )
return - V_89 ;
V_4 = F_29 ( V_20 , V_15 , V_21 , V_22 ) ;
if ( ! V_4 ) {
V_18 = - V_53 ;
goto V_25;
}
V_3 = V_4 -> V_3 ;
V_104 = F_3 ( sizeof( * V_104 ) , V_5 ) ;
if ( ! V_104 ) {
V_18 = - V_38 ;
goto V_25;
}
V_104 -> V_105 = V_90 ;
V_104 -> V_91 = V_91 ;
V_104 -> V_92 = V_92 ;
V_104 -> V_106 = NULL ;
V_104 -> V_107 = NULL ;
V_104 -> V_108 = NULL ;
V_104 -> V_109 = V_110 ;
V_18 = F_96 ( V_3 , V_104 ) ;
if ( V_18 )
F_5 ( V_104 ) ;
V_25:
if ( V_4 )
F_27 ( V_4 ) ;
return V_18 ;
}
static T_4 F_97 ( struct V_111 * V_112 , const char * V_87 ,
T_5 V_113 )
{
int V_20 , V_15 , V_21 , V_22 ;
int V_18 ;
V_18 = F_86 ( V_87 , & V_20 , & V_15 , & V_21 , & V_22 ) ;
if ( V_18 )
goto V_25;
V_18 = F_88 ( V_20 , V_15 , V_21 , V_22 ) ;
V_25:
if ( ! V_18 )
V_18 = V_113 ;
return V_18 ;
}
static T_4 F_98 ( struct V_111 * V_112 , const char * V_87 ,
T_5 V_113 )
{
int V_20 , V_15 , V_21 , V_22 ;
int V_18 ;
V_18 = F_86 ( V_87 , & V_20 , & V_15 , & V_21 , & V_22 ) ;
if ( V_18 )
goto V_25;
V_18 = F_93 ( V_20 , V_15 , V_21 , V_22 ) ;
V_25:
if ( ! V_18 )
V_18 = V_113 ;
return V_18 ;
}
static T_4 F_99 ( struct V_111 * V_112 , char * V_87 )
{
struct V_32 * V_93 ;
T_5 V_113 = 0 ;
unsigned long V_23 ;
F_30 ( & V_36 , V_23 ) ;
F_31 (pci_dev_id, &pcistub_device_ids, slot_list) {
if ( V_113 >= V_114 )
break;
V_113 += F_100 ( V_87 + V_113 , V_114 - V_113 ,
L_62 ,
V_93 -> V_20 , V_93 -> V_15 ,
F_32 ( V_93 -> V_17 ) ,
F_33 ( V_93 -> V_17 ) ) ;
}
F_34 ( & V_36 , V_23 ) ;
return V_113 ;
}
static T_4 F_101 ( struct V_111 * V_112 , char * V_87 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
T_5 V_113 = 0 ;
unsigned long V_23 ;
F_30 ( & V_24 , V_23 ) ;
F_31 (psdev, &pcistub_devices, dev_list) {
if ( V_113 >= V_114 )
break;
if ( ! V_4 -> V_3 )
continue;
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 )
continue;
V_113 +=
F_100 ( V_87 + V_113 , V_114 - V_113 ,
L_63 ,
F_48 ( V_4 -> V_3 ) ,
V_9 -> V_115 ? L_64 : L_65 ,
V_9 -> V_116 ? L_66 : L_67 ,
V_9 -> V_117 ) ;
}
F_34 ( & V_24 , V_23 ) ;
return V_113 ;
}
static T_4 F_102 ( struct V_111 * V_112 ,
const char * V_87 ,
T_5 V_113 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
int V_20 , V_15 , V_21 , V_22 ;
int V_18 ;
V_18 = F_86 ( V_87 , & V_20 , & V_15 , & V_21 , & V_22 ) ;
if ( V_18 )
return V_18 ;
V_4 = F_29 ( V_20 , V_15 , V_21 , V_22 ) ;
if ( ! V_4 ) {
V_18 = - V_102 ;
goto V_25;
}
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 ) {
V_18 = - V_102 ;
goto V_25;
}
F_2 ( & V_4 -> V_3 -> V_3 , L_68 ,
V_9 -> V_39 , V_9 -> V_115 ,
! V_9 -> V_115 ) ;
V_9 -> V_115 = ! ( V_9 -> V_115 ) ;
if ( V_9 -> V_115 )
V_9 -> V_116 = 1 ;
V_25:
if ( V_4 )
F_27 ( V_4 ) ;
if ( ! V_18 )
V_18 = V_113 ;
return V_18 ;
}
static T_4 F_103 ( struct V_111 * V_112 , const char * V_87 ,
T_5 V_113 )
{
int V_20 , V_15 , V_21 , V_22 , V_90 , V_91 , V_92 ;
int V_18 ;
V_18 = F_87 ( V_87 , & V_20 , & V_15 , & V_21 , & V_22 , & V_90 , & V_91 ,
& V_92 ) ;
if ( V_18 )
goto V_25;
V_18 = F_95 ( V_20 , V_15 , V_21 , V_22 , V_90 , V_91 , V_92 ) ;
V_25:
if ( ! V_18 )
V_18 = V_113 ;
return V_18 ;
}
static T_4 F_104 ( struct V_111 * V_112 , char * V_87 )
{
int V_113 = 0 ;
unsigned long V_23 ;
struct V_118 * V_119 ;
struct V_8 * V_9 ;
const struct V_103 * V_104 ;
const struct V_120 * V_121 ;
F_30 ( & V_36 , V_23 ) ;
F_31 (quirk, &xen_pcibk_quirks, quirks_list) {
if ( V_113 >= V_114 )
goto V_25;
V_113 += F_100 ( V_87 + V_113 , V_114 - V_113 ,
L_69 ,
V_119 -> V_27 -> V_15 -> V_16 ,
F_32 ( V_119 -> V_27 -> V_17 ) ,
F_33 ( V_119 -> V_27 -> V_17 ) ,
V_119 -> V_122 . V_123 , V_119 -> V_122 . V_124 ,
V_119 -> V_122 . V_125 ,
V_119 -> V_122 . V_126 ) ;
V_9 = F_10 ( V_119 -> V_27 ) ;
F_31 (cfg_entry, &dev_data->config_fields, list) {
V_104 = V_121 -> V_104 ;
if ( V_113 >= V_114 )
goto V_25;
V_113 += F_100 ( V_87 + V_113 , V_114 - V_113 ,
L_70 ,
V_121 -> V_127 +
V_104 -> V_105 , V_104 -> V_91 ,
V_104 -> V_92 ) ;
}
}
V_25:
F_34 ( & V_36 , V_23 ) ;
return V_113 ;
}
static T_4 F_105 ( struct V_111 * V_112 , const char * V_87 ,
T_5 V_113 )
{
int V_20 , V_15 , V_21 , V_22 ;
int V_18 ;
struct V_1 * V_4 ;
struct V_8 * V_9 ;
V_18 = F_86 ( V_87 , & V_20 , & V_15 , & V_21 , & V_22 ) ;
if ( V_18 )
goto V_25;
V_4 = F_29 ( V_20 , V_15 , V_21 , V_22 ) ;
if ( ! V_4 ) {
V_18 = - V_53 ;
goto V_25;
}
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 ) {
V_18 = - V_128 ;
goto V_108;
}
if ( ! V_9 -> V_129 ) {
V_9 -> V_129 = 1 ;
F_18 ( & V_4 -> V_3 -> V_3 , L_71
L_72 ) ;
F_18 ( & V_4 -> V_3 -> V_3 ,
L_73 ) ;
}
V_108:
F_27 ( V_4 ) ;
V_25:
if ( ! V_18 )
V_18 = V_113 ;
return V_18 ;
}
static T_4 F_106 ( struct V_111 * V_112 , char * V_87 )
{
struct V_1 * V_4 ;
struct V_8 * V_9 ;
T_5 V_113 = 0 ;
unsigned long V_23 ;
F_30 ( & V_24 , V_23 ) ;
F_31 (psdev, &pcistub_devices, dev_list) {
if ( V_113 >= V_114 )
break;
if ( ! V_4 -> V_3 )
continue;
V_9 = F_10 ( V_4 -> V_3 ) ;
if ( ! V_9 || ! V_9 -> V_129 )
continue;
V_113 +=
F_100 ( V_87 + V_113 , V_114 - V_113 , L_74 ,
F_48 ( V_4 -> V_3 ) ) ;
}
F_34 ( & V_24 , V_23 ) ;
return V_113 ;
}
static void F_107 ( void )
{
F_108 ( & V_130 . V_131 , & V_132 ) ;
F_108 ( & V_130 . V_131 ,
& V_133 ) ;
F_108 ( & V_130 . V_131 , & V_134 ) ;
F_108 ( & V_130 . V_131 , & V_135 ) ;
F_108 ( & V_130 . V_131 ,
& V_136 ) ;
F_108 ( & V_130 . V_131 ,
& V_137 ) ;
F_108 ( & V_130 . V_131 ,
& V_138 ) ;
F_109 ( & V_130 ) ;
}
static int T_1 F_110 ( void )
{
int V_139 = 0 ;
int V_18 = 0 ;
int V_20 , V_15 , V_21 , V_22 ;
int V_88 ;
if ( V_140 && * V_140 ) {
do {
V_88 = 0 ;
V_18 = sscanf ( V_140 + V_139 ,
L_75 ,
& V_20 , & V_15 , & V_21 , & V_22 , & V_88 ) ;
switch ( V_18 ) {
case 3 :
V_22 = - 1 ;
sscanf ( V_140 + V_139 ,
L_76 ,
& V_20 , & V_15 , & V_21 , & V_88 ) ;
break;
case 2 :
V_21 = V_22 = - 1 ;
sscanf ( V_140 + V_139 ,
L_77 ,
& V_20 , & V_15 , & V_88 ) ;
break;
}
if ( ! V_88 ) {
V_20 = 0 ;
V_18 = sscanf ( V_140 + V_139 ,
L_78 ,
& V_15 , & V_21 , & V_22 , & V_88 ) ;
switch ( V_18 ) {
case 2 :
V_22 = - 1 ;
sscanf ( V_140 + V_139 ,
L_79 ,
& V_15 , & V_21 , & V_88 ) ;
break;
case 1 :
V_21 = V_22 = - 1 ;
sscanf ( V_140 + V_139 ,
L_80 ,
& V_15 , & V_88 ) ;
break;
}
}
if ( V_88 <= 0 )
goto V_141;
V_18 = F_88 ( V_20 , V_15 , V_21 , V_22 ) ;
if ( V_18 )
goto V_25;
V_139 += V_88 ;
} while ( V_140 [ V_139 ] );
}
V_18 = F_111 ( & V_130 ) ;
if ( V_18 < 0 )
goto V_25;
V_18 = F_112 ( & V_130 . V_131 ,
& V_132 ) ;
if ( ! V_18 )
V_18 = F_112 ( & V_130 . V_131 ,
& V_133 ) ;
if ( ! V_18 )
V_18 = F_112 ( & V_130 . V_131 ,
& V_134 ) ;
if ( ! V_18 )
V_18 = F_112 ( & V_130 . V_131 ,
& V_135 ) ;
if ( ! V_18 )
V_18 = F_112 ( & V_130 . V_131 ,
& V_136 ) ;
if ( ! V_18 )
V_18 = F_112 ( & V_130 . V_131 ,
& V_137 ) ;
if ( ! V_18 )
V_18 = F_112 ( & V_130 . V_131 ,
& V_138 ) ;
if ( V_18 )
F_107 () ;
V_25:
return V_18 ;
V_141:
F_113 ( L_81 ,
V_140 + V_139 ) ;
return - V_89 ;
}
static struct V_1 * F_114 ( const struct V_2 * V_27 )
{
struct V_1 * V_4 = NULL ;
unsigned long V_23 ;
bool V_35 = false ;
F_30 ( & V_24 , V_23 ) ;
F_31 (psdev, &pcistub_devices, dev_list) {
if ( ! V_4 -> V_27 && V_4 -> V_3 != V_27
&& F_115 ( V_4 -> V_3 ) == V_27 ) {
V_35 = true ;
break;
}
}
F_34 ( & V_24 , V_23 ) ;
if ( V_35 )
return V_4 ;
return NULL ;
}
static int F_116 ( struct V_142 * V_143 ,
unsigned long V_144 , void * V_145 )
{
struct V_124 * V_3 = V_145 ;
const struct V_2 * V_27 = F_117 ( V_3 ) ;
if ( V_144 != V_146 )
return V_147 ;
if ( ! V_27 -> V_148 )
return V_147 ;
for (; ; ) {
struct V_1 * V_4 = F_114 ( V_27 ) ;
if ( ! V_4 )
break;
F_118 ( & V_4 -> V_3 -> V_3 ) ;
}
return V_147 ;
}
static int T_1 F_119 ( void )
{
int V_18 ;
if ( ! F_120 () )
return - V_53 ;
V_18 = F_121 () ;
if ( V_18 )
return V_18 ;
#ifdef V_95
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
F_124 ( & V_149 , & V_150 ) ;
#endif
return V_18 ;
}
static void T_6 F_125 ( void )
{
#ifdef F_123
F_126 ( & V_149 , & V_150 ) ;
#endif
F_127 () ;
F_107 () ;
}
