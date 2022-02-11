static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( F_2 ( F_3 ( V_3 ) ) ) {
F_4 ( L_1 , V_5 ) ;
return F_5 ( - V_6 ) ;
}
F_6 ( ! F_7 ( & V_7 ) ,
L_2 ) ;
F_8 (tmp_devfreq, &devfreq_list, node) {
if ( V_4 -> V_3 . V_8 == V_3 )
return V_4 ;
}
return F_5 ( - V_9 ) ;
}
static int F_9 ( struct V_1 * V_1 , unsigned long V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_12 -> V_13 ; V_11 ++ )
if ( V_10 == V_1 -> V_12 -> V_14 [ V_11 ] )
return V_11 ;
return - V_6 ;
}
static int F_10 ( struct V_1 * V_1 , unsigned long V_10 )
{
int V_11 , V_15 ;
unsigned long V_16 ;
V_11 = F_9 ( V_1 , V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
V_16 = V_17 ;
V_1 -> V_18 [ V_11 ] +=
V_16 - V_1 -> V_19 ;
if ( V_10 != V_1 -> V_20 ) {
V_15 = F_9 ( V_1 ,
V_1 -> V_20 ) ;
V_1 -> V_21 [ ( V_15 *
V_1 -> V_12 -> V_13 ) + V_11 ] ++ ;
V_1 -> V_22 ++ ;
}
V_1 -> V_19 = V_16 ;
return 0 ;
}
static struct V_23 * F_11 ( const char * V_24 )
{
struct V_23 * V_25 ;
if ( F_2 ( F_3 ( V_24 ) ) ) {
F_4 ( L_1 , V_5 ) ;
return F_5 ( - V_6 ) ;
}
F_6 ( ! F_7 ( & V_7 ) ,
L_2 ) ;
F_8 (tmp_governor, &devfreq_governor_list, node) {
if ( ! strncmp ( V_25 -> V_24 , V_24 , V_26 ) )
return V_25 ;
}
return F_5 ( - V_9 ) ;
}
int F_12 ( struct V_1 * V_1 )
{
unsigned long V_10 ;
int V_27 = 0 ;
T_1 V_28 = 0 ;
if ( ! F_7 ( & V_1 -> V_29 ) ) {
F_6 ( true , L_3 ) ;
return - V_6 ;
}
if ( ! V_1 -> V_30 )
return - V_6 ;
V_27 = V_1 -> V_30 -> V_31 ( V_1 , & V_10 ) ;
if ( V_27 )
return V_27 ;
if ( V_1 -> V_32 && V_10 < V_1 -> V_32 ) {
V_10 = V_1 -> V_32 ;
V_28 &= ~ V_33 ;
}
if ( V_1 -> V_34 && V_10 > V_1 -> V_34 ) {
V_10 = V_1 -> V_34 ;
V_28 |= V_33 ;
}
V_27 = V_1 -> V_12 -> V_35 ( V_1 -> V_3 . V_8 , & V_10 , V_28 ) ;
if ( V_27 )
return V_27 ;
if ( V_1 -> V_12 -> V_14 )
if ( F_10 ( V_1 , V_10 ) )
F_13 ( & V_1 -> V_3 ,
L_4 ) ;
V_1 -> V_20 = V_10 ;
return V_27 ;
}
static void F_14 ( struct V_36 * V_37 )
{
int V_27 ;
struct V_1 * V_1 = F_15 ( V_37 ,
struct V_1 , V_37 . V_37 ) ;
F_16 ( & V_1 -> V_29 ) ;
V_27 = F_12 ( V_1 ) ;
if ( V_27 )
F_13 ( & V_1 -> V_3 , L_5 , V_27 ) ;
F_17 ( V_38 , & V_1 -> V_37 ,
F_18 ( V_1 -> V_12 -> V_39 ) ) ;
F_19 ( & V_1 -> V_29 ) ;
}
void F_20 ( struct V_1 * V_1 )
{
F_21 ( & V_1 -> V_37 , F_14 ) ;
if ( V_1 -> V_12 -> V_39 )
F_17 ( V_38 , & V_1 -> V_37 ,
F_18 ( V_1 -> V_12 -> V_39 ) ) ;
}
void F_22 ( struct V_1 * V_1 )
{
F_23 ( & V_1 -> V_37 ) ;
}
void F_24 ( struct V_1 * V_1 )
{
F_16 ( & V_1 -> V_29 ) ;
if ( V_1 -> V_40 ) {
F_19 ( & V_1 -> V_29 ) ;
return;
}
V_1 -> V_40 = true ;
F_19 ( & V_1 -> V_29 ) ;
F_23 ( & V_1 -> V_37 ) ;
}
void F_25 ( struct V_1 * V_1 )
{
F_16 ( & V_1 -> V_29 ) ;
if ( ! V_1 -> V_40 )
goto V_41;
if ( ! F_26 ( & V_1 -> V_37 ) &&
V_1 -> V_12 -> V_39 )
F_17 ( V_38 , & V_1 -> V_37 ,
F_18 ( V_1 -> V_12 -> V_39 ) ) ;
V_1 -> V_40 = false ;
V_41:
F_19 ( & V_1 -> V_29 ) ;
}
void F_27 ( struct V_1 * V_1 , unsigned int * V_42 )
{
unsigned int V_43 = V_1 -> V_12 -> V_39 ;
unsigned int V_44 = * V_42 ;
F_16 ( & V_1 -> V_29 ) ;
V_1 -> V_12 -> V_39 = V_44 ;
if ( V_1 -> V_40 )
goto V_41;
if ( ! V_44 ) {
F_19 ( & V_1 -> V_29 ) ;
F_23 ( & V_1 -> V_37 ) ;
return;
}
if ( ! V_43 ) {
F_17 ( V_38 , & V_1 -> V_37 ,
F_18 ( V_1 -> V_12 -> V_39 ) ) ;
goto V_41;
}
if ( V_43 > V_44 ) {
F_19 ( & V_1 -> V_29 ) ;
F_23 ( & V_1 -> V_37 ) ;
F_16 ( & V_1 -> V_29 ) ;
if ( ! V_1 -> V_40 )
F_17 ( V_38 , & V_1 -> V_37 ,
F_18 ( V_1 -> V_12 -> V_39 ) ) ;
}
V_41:
F_19 ( & V_1 -> V_29 ) ;
}
static int F_28 ( struct V_45 * V_46 , unsigned long type ,
void * V_47 )
{
struct V_1 * V_1 = F_15 ( V_46 , struct V_1 , V_46 ) ;
int V_48 ;
F_16 ( & V_1 -> V_29 ) ;
V_48 = F_12 ( V_1 ) ;
F_19 ( & V_1 -> V_29 ) ;
return V_48 ;
}
static void F_29 ( struct V_1 * V_1 , bool V_49 )
{
F_16 ( & V_7 ) ;
if ( F_30 ( F_1 ( V_1 -> V_3 . V_8 ) ) ) {
F_19 ( & V_7 ) ;
F_31 ( & V_1 -> V_3 , L_6 ) ;
return;
}
F_32 ( & V_1 -> V_50 ) ;
F_19 ( & V_7 ) ;
if ( V_1 -> V_30 )
V_1 -> V_30 -> V_51 ( V_1 ,
V_52 , NULL ) ;
if ( V_1 -> V_12 -> exit )
V_1 -> V_12 -> exit ( V_1 -> V_3 . V_8 ) ;
if ( ! V_49 && F_33 ( & V_1 -> V_3 ) ) {
F_34 ( & V_1 -> V_3 ) ;
F_35 ( & V_1 -> V_3 ) ;
}
F_36 ( & V_1 -> V_29 ) ;
F_37 ( V_1 ) ;
}
static void F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_39 ( V_3 ) ;
F_29 ( V_1 , true ) ;
}
struct V_1 * F_40 ( struct V_2 * V_3 ,
struct V_53 * V_12 ,
const char * V_54 ,
void * V_55 )
{
struct V_1 * V_1 ;
struct V_23 * V_30 ;
int V_27 = 0 ;
if ( ! V_3 || ! V_12 || ! V_54 ) {
F_13 ( V_3 , L_7 , V_5 ) ;
return F_5 ( - V_6 ) ;
}
F_16 ( & V_7 ) ;
V_1 = F_1 ( V_3 ) ;
F_19 ( & V_7 ) ;
if ( ! F_30 ( V_1 ) ) {
F_13 ( V_3 , L_8 , V_5 ) ;
V_27 = - V_6 ;
goto V_56;
}
V_1 = F_41 ( sizeof( struct V_1 ) , V_57 ) ;
if ( ! V_1 ) {
F_13 ( V_3 , L_9 ,
V_5 ) ;
V_27 = - V_58 ;
goto V_56;
}
F_42 ( & V_1 -> V_29 ) ;
F_16 ( & V_1 -> V_29 ) ;
V_1 -> V_3 . V_8 = V_3 ;
V_1 -> V_3 . V_59 = V_60 ;
V_1 -> V_3 . V_61 = F_38 ;
V_1 -> V_12 = V_12 ;
strncpy ( V_1 -> V_54 , V_54 , V_26 ) ;
V_1 -> V_20 = V_12 -> V_62 ;
V_1 -> V_55 = V_55 ;
V_1 -> V_46 . V_63 = F_28 ;
V_1 -> V_21 = F_43 ( V_3 , sizeof( unsigned int ) *
V_1 -> V_12 -> V_13 *
V_1 -> V_12 -> V_13 ,
V_57 ) ;
V_1 -> V_18 = F_43 ( V_3 , sizeof( unsigned int ) *
V_1 -> V_12 -> V_13 ,
V_57 ) ;
V_1 -> V_19 = V_17 ;
F_44 ( & V_1 -> V_3 , F_45 ( V_3 ) ) ;
V_27 = F_46 ( & V_1 -> V_3 ) ;
if ( V_27 ) {
F_35 ( & V_1 -> V_3 ) ;
F_19 ( & V_1 -> V_29 ) ;
goto V_64;
}
F_19 ( & V_1 -> V_29 ) ;
F_16 ( & V_7 ) ;
F_47 ( & V_1 -> V_50 , & V_65 ) ;
V_30 = F_11 ( V_1 -> V_54 ) ;
if ( ! F_30 ( V_30 ) )
V_1 -> V_30 = V_30 ;
if ( V_1 -> V_30 )
V_27 = V_1 -> V_30 -> V_51 ( V_1 ,
V_66 , NULL ) ;
F_19 ( & V_7 ) ;
if ( V_27 ) {
F_13 ( V_3 , L_10 ,
V_5 ) ;
goto V_67;
}
return V_1 ;
V_67:
F_32 ( & V_1 -> V_50 ) ;
F_34 ( & V_1 -> V_3 ) ;
V_64:
F_37 ( V_1 ) ;
V_56:
return F_5 ( V_27 ) ;
}
int F_48 ( struct V_1 * V_1 )
{
if ( ! V_1 )
return - V_6 ;
F_29 ( V_1 , false ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_1 )
{
if ( ! V_1 )
return - V_6 ;
if ( ! V_1 -> V_30 )
return 0 ;
return V_1 -> V_30 -> V_51 ( V_1 ,
V_68 , NULL ) ;
}
int F_50 ( struct V_1 * V_1 )
{
if ( ! V_1 )
return - V_6 ;
if ( ! V_1 -> V_30 )
return 0 ;
return V_1 -> V_30 -> V_51 ( V_1 ,
V_69 , NULL ) ;
}
int F_51 ( struct V_23 * V_30 )
{
struct V_23 * V_70 ;
struct V_1 * V_1 ;
int V_27 = 0 ;
if ( ! V_30 ) {
F_4 ( L_7 , V_5 ) ;
return - V_6 ;
}
F_16 ( & V_7 ) ;
V_70 = F_11 ( V_30 -> V_24 ) ;
if ( ! F_30 ( V_70 ) ) {
F_4 ( L_11 , V_5 ,
V_70 -> V_24 ) ;
V_27 = - V_6 ;
goto V_56;
}
F_47 ( & V_30 -> V_50 , & V_71 ) ;
F_8 (devfreq, &devfreq_list, node) {
int V_48 = 0 ;
struct V_2 * V_3 = V_1 -> V_3 . V_8 ;
if ( ! strncmp ( V_1 -> V_54 , V_30 -> V_24 ,
V_26 ) ) {
if ( V_1 -> V_30 ) {
F_31 ( V_3 ,
L_12 ,
V_5 , V_1 -> V_30 -> V_24 ) ;
V_48 = V_1 -> V_30 -> V_51 ( V_1 ,
V_52 , NULL ) ;
if ( V_48 ) {
F_31 ( V_3 ,
L_13 ,
V_5 ,
V_1 -> V_30 -> V_24 , V_48 ) ;
}
}
V_1 -> V_30 = V_30 ;
V_48 = V_1 -> V_30 -> V_51 ( V_1 ,
V_66 , NULL ) ;
if ( V_48 ) {
F_31 ( V_3 , L_14 ,
V_5 , V_1 -> V_30 -> V_24 ,
V_48 ) ;
}
}
}
V_56:
F_19 ( & V_7 ) ;
return V_27 ;
}
int F_52 ( struct V_23 * V_30 )
{
struct V_23 * V_70 ;
struct V_1 * V_1 ;
int V_27 = 0 ;
if ( ! V_30 ) {
F_4 ( L_7 , V_5 ) ;
return - V_6 ;
}
F_16 ( & V_7 ) ;
V_70 = F_11 ( V_30 -> V_24 ) ;
if ( F_30 ( V_70 ) ) {
F_4 ( L_15 , V_5 ,
V_30 -> V_24 ) ;
V_27 = F_53 ( V_70 ) ;
goto V_56;
}
F_8 (devfreq, &devfreq_list, node) {
int V_48 ;
struct V_2 * V_3 = V_1 -> V_3 . V_8 ;
if ( ! strncmp ( V_1 -> V_54 , V_30 -> V_24 ,
V_26 ) ) {
if ( ! V_1 -> V_30 ) {
F_31 ( V_3 , L_16 ,
V_5 , V_30 -> V_24 ) ;
continue;
}
V_48 = V_1 -> V_30 -> V_51 ( V_1 ,
V_52 , NULL ) ;
if ( V_48 ) {
F_31 ( V_3 , L_17 ,
V_5 , V_1 -> V_30 -> V_24 ,
V_48 ) ;
}
V_1 -> V_30 = NULL ;
}
}
F_32 ( & V_30 -> V_50 ) ;
V_56:
F_19 ( & V_7 ) ;
return V_27 ;
}
static T_2 F_54 ( struct V_2 * V_3 ,
struct V_72 * V_73 , char * V_74 )
{
if ( ! F_39 ( V_3 ) -> V_30 )
return - V_6 ;
return sprintf ( V_74 , L_18 , F_39 ( V_3 ) -> V_30 -> V_24 ) ;
}
static T_2 F_55 ( struct V_2 * V_3 , struct V_72 * V_73 ,
const char * V_74 , T_3 V_75 )
{
struct V_1 * V_76 = F_39 ( V_3 ) ;
int V_48 ;
char V_77 [ V_26 + 1 ] ;
struct V_23 * V_30 ;
V_48 = sscanf ( V_74 , L_19 F_56 ( V_26 ) L_20 , V_77 ) ;
if ( V_48 != 1 )
return - V_6 ;
F_16 ( & V_7 ) ;
V_30 = F_11 ( V_77 ) ;
if ( F_30 ( V_30 ) ) {
V_48 = F_53 ( V_30 ) ;
goto V_41;
}
if ( V_76 -> V_30 == V_30 )
goto V_41;
if ( V_76 -> V_30 ) {
V_48 = V_76 -> V_30 -> V_51 ( V_76 , V_52 , NULL ) ;
if ( V_48 ) {
F_31 ( V_3 , L_21 ,
V_5 , V_76 -> V_30 -> V_24 , V_48 ) ;
goto V_41;
}
}
V_76 -> V_30 = V_30 ;
strncpy ( V_76 -> V_54 , V_30 -> V_24 , V_26 ) ;
V_48 = V_76 -> V_30 -> V_51 ( V_76 , V_66 , NULL ) ;
if ( V_48 )
F_31 ( V_3 , L_22 ,
V_5 , V_76 -> V_30 -> V_24 , V_48 ) ;
V_41:
F_19 ( & V_7 ) ;
if ( ! V_48 )
V_48 = V_75 ;
return V_48 ;
}
static T_2 F_57 ( struct V_2 * V_78 ,
struct V_72 * V_73 ,
char * V_74 )
{
struct V_23 * V_25 ;
T_2 V_75 = 0 ;
F_16 ( & V_7 ) ;
F_8 (tmp_governor, &devfreq_governor_list, node)
V_75 += F_58 ( & V_74 [ V_75 ] , ( V_79 - V_75 - 2 ) ,
L_23 , V_25 -> V_24 ) ;
F_19 ( & V_7 ) ;
if ( V_75 )
V_75 -- ;
V_75 += sprintf ( & V_74 [ V_75 ] , L_24 ) ;
return V_75 ;
}
static T_2 F_59 ( struct V_2 * V_3 ,
struct V_72 * V_73 , char * V_74 )
{
unsigned long V_10 ;
struct V_1 * V_1 = F_39 ( V_3 ) ;
if ( V_1 -> V_12 -> V_80 &&
! V_1 -> V_12 -> V_80 ( V_1 -> V_3 . V_8 , & V_10 ) )
return sprintf ( V_74 , L_25 , V_10 ) ;
return sprintf ( V_74 , L_25 , V_1 -> V_20 ) ;
}
static T_2 F_60 ( struct V_2 * V_3 ,
struct V_72 * V_73 , char * V_74 )
{
return sprintf ( V_74 , L_25 , F_39 ( V_3 ) -> V_20 ) ;
}
static T_2 F_61 ( struct V_2 * V_3 ,
struct V_72 * V_73 , char * V_74 )
{
return sprintf ( V_74 , L_26 , F_39 ( V_3 ) -> V_12 -> V_39 ) ;
}
static T_2 F_62 ( struct V_2 * V_3 ,
struct V_72 * V_73 ,
const char * V_74 , T_3 V_75 )
{
struct V_1 * V_76 = F_39 ( V_3 ) ;
unsigned int V_81 ;
int V_48 ;
if ( ! V_76 -> V_30 )
return - V_6 ;
V_48 = sscanf ( V_74 , L_27 , & V_81 ) ;
if ( V_48 != 1 )
return - V_6 ;
V_76 -> V_30 -> V_51 ( V_76 , V_82 , & V_81 ) ;
V_48 = V_75 ;
return V_48 ;
}
static T_2 F_63 ( struct V_2 * V_3 , struct V_72 * V_73 ,
const char * V_74 , T_3 V_75 )
{
struct V_1 * V_76 = F_39 ( V_3 ) ;
unsigned long V_81 ;
int V_48 ;
unsigned long V_83 ;
V_48 = sscanf ( V_74 , L_28 , & V_81 ) ;
if ( V_48 != 1 )
return - V_6 ;
F_16 ( & V_76 -> V_29 ) ;
V_83 = V_76 -> V_34 ;
if ( V_81 && V_83 && V_81 > V_83 ) {
V_48 = - V_6 ;
goto V_84;
}
V_76 -> V_32 = V_81 ;
F_12 ( V_76 ) ;
V_48 = V_75 ;
V_84:
F_19 ( & V_76 -> V_29 ) ;
return V_48 ;
}
static T_2 F_64 ( struct V_2 * V_3 , struct V_72 * V_73 ,
char * V_74 )
{
return sprintf ( V_74 , L_25 , F_39 ( V_3 ) -> V_32 ) ;
}
static T_2 F_65 ( struct V_2 * V_3 , struct V_72 * V_73 ,
const char * V_74 , T_3 V_75 )
{
struct V_1 * V_76 = F_39 ( V_3 ) ;
unsigned long V_81 ;
int V_48 ;
unsigned long V_85 ;
V_48 = sscanf ( V_74 , L_28 , & V_81 ) ;
if ( V_48 != 1 )
return - V_6 ;
F_16 ( & V_76 -> V_29 ) ;
V_85 = V_76 -> V_32 ;
if ( V_81 && V_85 && V_81 < V_85 ) {
V_48 = - V_6 ;
goto V_84;
}
V_76 -> V_34 = V_81 ;
F_12 ( V_76 ) ;
V_48 = V_75 ;
V_84:
F_19 ( & V_76 -> V_29 ) ;
return V_48 ;
}
static T_2 F_66 ( struct V_2 * V_3 , struct V_72 * V_73 ,
char * V_74 )
{
return sprintf ( V_74 , L_25 , F_39 ( V_3 ) -> V_34 ) ;
}
static T_2 F_67 ( struct V_2 * V_78 ,
struct V_72 * V_73 ,
char * V_74 )
{
struct V_1 * V_76 = F_39 ( V_78 ) ;
struct V_2 * V_3 = V_76 -> V_3 . V_8 ;
struct V_86 * V_86 ;
T_2 V_75 = 0 ;
unsigned long V_10 = 0 ;
F_68 () ;
do {
V_86 = F_69 ( V_3 , & V_10 ) ;
if ( F_30 ( V_86 ) )
break;
V_75 += F_58 ( & V_74 [ V_75 ] , ( V_79 - V_75 - 2 ) ,
L_29 , V_10 ) ;
V_10 ++ ;
} while ( 1 );
F_70 () ;
if ( V_75 )
V_75 -- ;
V_75 += sprintf ( & V_74 [ V_75 ] , L_24 ) ;
return V_75 ;
}
static T_2 F_71 ( struct V_2 * V_3 , struct V_72 * V_73 ,
char * V_74 )
{
struct V_1 * V_1 = F_39 ( V_3 ) ;
T_2 V_87 ;
int V_88 , V_89 , V_27 ;
unsigned int V_13 = V_1 -> V_12 -> V_13 ;
V_27 = F_10 ( V_1 , V_1 -> V_20 ) ;
if ( V_27 )
return 0 ;
V_87 = sprintf ( V_74 , L_30 ) ;
V_87 += sprintf ( V_74 + V_87 , L_31 ) ;
for ( V_88 = 0 ; V_88 < V_13 ; V_88 ++ )
V_87 += sprintf ( V_74 + V_87 , L_32 ,
V_1 -> V_12 -> V_14 [ V_88 ] ) ;
V_87 += sprintf ( V_74 + V_87 , L_33 ) ;
for ( V_88 = 0 ; V_88 < V_13 ; V_88 ++ ) {
if ( V_1 -> V_12 -> V_14 [ V_88 ]
== V_1 -> V_20 ) {
V_87 += sprintf ( V_74 + V_87 , L_34 ) ;
} else {
V_87 += sprintf ( V_74 + V_87 , L_35 ) ;
}
V_87 += sprintf ( V_74 + V_87 , L_36 ,
V_1 -> V_12 -> V_14 [ V_88 ] ) ;
for ( V_89 = 0 ; V_89 < V_13 ; V_89 ++ )
V_87 += sprintf ( V_74 + V_87 , L_32 ,
V_1 -> V_21 [ ( V_88 * V_13 ) + V_89 ] ) ;
V_87 += sprintf ( V_74 + V_87 , L_37 ,
F_72 ( V_1 -> V_18 [ V_88 ] ) ) ;
}
V_87 += sprintf ( V_74 + V_87 , L_38 ,
V_1 -> V_22 ) ;
return V_87 ;
}
static int T_4 F_73 ( void )
{
V_60 = F_74 ( V_90 , L_39 ) ;
if ( F_30 ( V_60 ) ) {
F_4 ( L_40 , __FILE__ ) ;
return F_53 ( V_60 ) ;
}
V_38 = F_75 ( L_41 ) ;
if ( F_30 ( V_38 ) ) {
F_76 ( V_60 ) ;
F_4 ( L_42 , __FILE__ ) ;
return F_53 ( V_38 ) ;
}
V_60 -> V_91 = V_92 ;
return 0 ;
}
static void T_5 F_77 ( void )
{
F_76 ( V_60 ) ;
F_78 ( V_38 ) ;
}
struct V_86 * F_79 ( struct V_2 * V_3 , unsigned long * V_10 ,
T_1 V_28 )
{
struct V_86 * V_86 ;
if ( V_28 & V_33 ) {
V_86 = F_80 ( V_3 , V_10 ) ;
if ( V_86 == F_5 ( - V_93 ) )
V_86 = F_69 ( V_3 , V_10 ) ;
} else {
V_86 = F_69 ( V_3 , V_10 ) ;
if ( V_86 == F_5 ( - V_93 ) )
V_86 = F_80 ( V_3 , V_10 ) ;
}
return V_86 ;
}
int F_81 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
struct V_94 * V_95 ;
int V_48 = 0 ;
F_68 () ;
V_95 = F_82 ( V_3 ) ;
if ( F_30 ( V_95 ) )
V_48 = F_53 ( V_95 ) ;
F_70 () ;
if ( ! V_48 )
V_48 = F_83 ( V_95 , & V_1 -> V_46 ) ;
return V_48 ;
}
int F_84 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
struct V_94 * V_95 ;
int V_48 = 0 ;
F_68 () ;
V_95 = F_82 ( V_3 ) ;
if ( F_30 ( V_95 ) )
V_48 = F_53 ( V_95 ) ;
F_70 () ;
if ( ! V_48 )
V_48 = F_85 ( V_95 , & V_1 -> V_46 ) ;
return V_48 ;
}
