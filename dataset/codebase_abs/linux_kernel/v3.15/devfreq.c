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
int V_11 , V_15 , V_16 = 0 ;
unsigned long V_17 ;
V_17 = V_18 ;
V_15 = F_9 ( V_1 , V_1 -> V_19 ) ;
if ( V_15 < 0 ) {
V_16 = V_15 ;
goto V_20;
}
V_1 -> V_21 [ V_15 ] +=
V_17 - V_1 -> V_22 ;
V_11 = F_9 ( V_1 , V_10 ) ;
if ( V_11 < 0 ) {
V_16 = V_11 ;
goto V_20;
}
if ( V_11 != V_15 ) {
V_1 -> V_23 [ ( V_15 *
V_1 -> V_12 -> V_13 ) + V_11 ] ++ ;
V_1 -> V_24 ++ ;
}
V_20:
V_1 -> V_22 = V_17 ;
return V_16 ;
}
static struct V_25 * F_11 ( const char * V_26 )
{
struct V_25 * V_27 ;
if ( F_2 ( F_3 ( V_26 ) ) ) {
F_4 ( L_1 , V_5 ) ;
return F_5 ( - V_6 ) ;
}
F_6 ( ! F_7 ( & V_7 ) ,
L_2 ) ;
F_8 (tmp_governor, &devfreq_governor_list, node) {
if ( ! strncmp ( V_27 -> V_26 , V_26 , V_28 ) )
return V_27 ;
}
return F_5 ( - V_9 ) ;
}
int F_12 ( struct V_1 * V_1 )
{
unsigned long V_10 ;
int V_29 = 0 ;
T_1 V_30 = 0 ;
if ( ! F_7 ( & V_1 -> V_31 ) ) {
F_6 ( true , L_3 ) ;
return - V_6 ;
}
if ( ! V_1 -> V_32 )
return - V_6 ;
V_29 = V_1 -> V_32 -> V_33 ( V_1 , & V_10 ) ;
if ( V_29 )
return V_29 ;
if ( V_1 -> V_34 && V_10 < V_1 -> V_34 ) {
V_10 = V_1 -> V_34 ;
V_30 &= ~ V_35 ;
}
if ( V_1 -> V_36 && V_10 > V_1 -> V_36 ) {
V_10 = V_1 -> V_36 ;
V_30 |= V_35 ;
}
V_29 = V_1 -> V_12 -> V_37 ( V_1 -> V_3 . V_8 , & V_10 , V_30 ) ;
if ( V_29 )
return V_29 ;
if ( V_1 -> V_12 -> V_14 )
if ( F_10 ( V_1 , V_10 ) )
F_13 ( & V_1 -> V_3 ,
L_4 ) ;
V_1 -> V_19 = V_10 ;
return V_29 ;
}
static void F_14 ( struct V_38 * V_39 )
{
int V_29 ;
struct V_1 * V_1 = F_15 ( V_39 ,
struct V_1 , V_39 . V_39 ) ;
F_16 ( & V_1 -> V_31 ) ;
V_29 = F_12 ( V_1 ) ;
if ( V_29 )
F_13 ( & V_1 -> V_3 , L_5 , V_29 ) ;
F_17 ( V_40 , & V_1 -> V_39 ,
F_18 ( V_1 -> V_12 -> V_41 ) ) ;
F_19 ( & V_1 -> V_31 ) ;
}
void F_20 ( struct V_1 * V_1 )
{
F_21 ( & V_1 -> V_39 , F_14 ) ;
if ( V_1 -> V_12 -> V_41 )
F_17 ( V_40 , & V_1 -> V_39 ,
F_18 ( V_1 -> V_12 -> V_41 ) ) ;
}
void F_22 ( struct V_1 * V_1 )
{
F_23 ( & V_1 -> V_39 ) ;
}
void F_24 ( struct V_1 * V_1 )
{
F_16 ( & V_1 -> V_31 ) ;
if ( V_1 -> V_42 ) {
F_19 ( & V_1 -> V_31 ) ;
return;
}
F_10 ( V_1 , V_1 -> V_19 ) ;
V_1 -> V_42 = true ;
F_19 ( & V_1 -> V_31 ) ;
F_23 ( & V_1 -> V_39 ) ;
}
void F_25 ( struct V_1 * V_1 )
{
unsigned long V_10 ;
F_16 ( & V_1 -> V_31 ) ;
if ( ! V_1 -> V_42 )
goto V_20;
if ( ! F_26 ( & V_1 -> V_39 ) &&
V_1 -> V_12 -> V_41 )
F_17 ( V_40 , & V_1 -> V_39 ,
F_18 ( V_1 -> V_12 -> V_41 ) ) ;
V_1 -> V_22 = V_18 ;
V_1 -> V_42 = false ;
if ( V_1 -> V_12 -> V_43 &&
! V_1 -> V_12 -> V_43 ( V_1 -> V_3 . V_8 , & V_10 ) )
V_1 -> V_19 = V_10 ;
V_20:
F_19 ( & V_1 -> V_31 ) ;
}
void F_27 ( struct V_1 * V_1 , unsigned int * V_44 )
{
unsigned int V_45 = V_1 -> V_12 -> V_41 ;
unsigned int V_46 = * V_44 ;
F_16 ( & V_1 -> V_31 ) ;
V_1 -> V_12 -> V_41 = V_46 ;
if ( V_1 -> V_42 )
goto V_20;
if ( ! V_46 ) {
F_19 ( & V_1 -> V_31 ) ;
F_23 ( & V_1 -> V_39 ) ;
return;
}
if ( ! V_45 ) {
F_17 ( V_40 , & V_1 -> V_39 ,
F_18 ( V_1 -> V_12 -> V_41 ) ) ;
goto V_20;
}
if ( V_45 > V_46 ) {
F_19 ( & V_1 -> V_31 ) ;
F_23 ( & V_1 -> V_39 ) ;
F_16 ( & V_1 -> V_31 ) ;
if ( ! V_1 -> V_42 )
F_17 ( V_40 , & V_1 -> V_39 ,
F_18 ( V_1 -> V_12 -> V_41 ) ) ;
}
V_20:
F_19 ( & V_1 -> V_31 ) ;
}
static int F_28 ( struct V_47 * V_48 , unsigned long type ,
void * V_49 )
{
struct V_1 * V_1 = F_15 ( V_48 , struct V_1 , V_48 ) ;
int V_16 ;
F_16 ( & V_1 -> V_31 ) ;
V_16 = F_12 ( V_1 ) ;
F_19 ( & V_1 -> V_31 ) ;
return V_16 ;
}
static void F_29 ( struct V_1 * V_1 , bool V_50 )
{
F_16 ( & V_7 ) ;
if ( F_30 ( F_1 ( V_1 -> V_3 . V_8 ) ) ) {
F_19 ( & V_7 ) ;
F_31 ( & V_1 -> V_3 , L_6 ) ;
return;
}
F_32 ( & V_1 -> V_51 ) ;
F_19 ( & V_7 ) ;
if ( V_1 -> V_32 )
V_1 -> V_32 -> V_52 ( V_1 ,
V_53 , NULL ) ;
if ( V_1 -> V_12 -> exit )
V_1 -> V_12 -> exit ( V_1 -> V_3 . V_8 ) ;
if ( ! V_50 && F_33 ( & V_1 -> V_3 ) ) {
F_34 ( & V_1 -> V_3 ) ;
F_35 ( & V_1 -> V_3 ) ;
}
F_36 ( & V_1 -> V_31 ) ;
F_37 ( V_1 ) ;
}
static void F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_39 ( V_3 ) ;
F_29 ( V_1 , true ) ;
}
struct V_1 * F_40 ( struct V_2 * V_3 ,
struct V_54 * V_12 ,
const char * V_55 ,
void * V_56 )
{
struct V_1 * V_1 ;
struct V_25 * V_32 ;
int V_29 = 0 ;
if ( ! V_3 || ! V_12 || ! V_55 ) {
F_13 ( V_3 , L_7 , V_5 ) ;
return F_5 ( - V_6 ) ;
}
F_16 ( & V_7 ) ;
V_1 = F_1 ( V_3 ) ;
F_19 ( & V_7 ) ;
if ( ! F_30 ( V_1 ) ) {
F_13 ( V_3 , L_8 , V_5 ) ;
V_29 = - V_6 ;
goto V_57;
}
V_1 = F_41 ( sizeof( struct V_1 ) , V_58 ) ;
if ( ! V_1 ) {
F_13 ( V_3 , L_9 ,
V_5 ) ;
V_29 = - V_59 ;
goto V_57;
}
F_42 ( & V_1 -> V_31 ) ;
F_16 ( & V_1 -> V_31 ) ;
V_1 -> V_3 . V_8 = V_3 ;
V_1 -> V_3 . V_60 = V_61 ;
V_1 -> V_3 . V_62 = F_38 ;
V_1 -> V_12 = V_12 ;
strncpy ( V_1 -> V_55 , V_55 , V_28 ) ;
V_1 -> V_19 = V_12 -> V_63 ;
V_1 -> V_56 = V_56 ;
V_1 -> V_48 . V_64 = F_28 ;
V_1 -> V_23 = F_43 ( V_3 , sizeof( unsigned int ) *
V_1 -> V_12 -> V_13 *
V_1 -> V_12 -> V_13 ,
V_58 ) ;
V_1 -> V_21 = F_43 ( V_3 , sizeof( unsigned int ) *
V_1 -> V_12 -> V_13 ,
V_58 ) ;
V_1 -> V_22 = V_18 ;
F_44 ( & V_1 -> V_3 , L_10 , F_45 ( V_3 ) ) ;
V_29 = F_46 ( & V_1 -> V_3 ) ;
if ( V_29 ) {
F_35 ( & V_1 -> V_3 ) ;
F_19 ( & V_1 -> V_31 ) ;
goto V_65;
}
F_19 ( & V_1 -> V_31 ) ;
F_16 ( & V_7 ) ;
F_47 ( & V_1 -> V_51 , & V_66 ) ;
V_32 = F_11 ( V_1 -> V_55 ) ;
if ( ! F_30 ( V_32 ) )
V_1 -> V_32 = V_32 ;
if ( V_1 -> V_32 )
V_29 = V_1 -> V_32 -> V_52 ( V_1 ,
V_67 , NULL ) ;
F_19 ( & V_7 ) ;
if ( V_29 ) {
F_13 ( V_3 , L_11 ,
V_5 ) ;
goto V_68;
}
return V_1 ;
V_68:
F_32 ( & V_1 -> V_51 ) ;
F_34 ( & V_1 -> V_3 ) ;
V_65:
F_37 ( V_1 ) ;
V_57:
return F_5 ( V_29 ) ;
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
if ( ! V_1 -> V_32 )
return 0 ;
return V_1 -> V_32 -> V_52 ( V_1 ,
V_69 , NULL ) ;
}
int F_50 ( struct V_1 * V_1 )
{
if ( ! V_1 )
return - V_6 ;
if ( ! V_1 -> V_32 )
return 0 ;
return V_1 -> V_32 -> V_52 ( V_1 ,
V_70 , NULL ) ;
}
int F_51 ( struct V_25 * V_32 )
{
struct V_25 * V_71 ;
struct V_1 * V_1 ;
int V_29 = 0 ;
if ( ! V_32 ) {
F_4 ( L_7 , V_5 ) ;
return - V_6 ;
}
F_16 ( & V_7 ) ;
V_71 = F_11 ( V_32 -> V_26 ) ;
if ( ! F_30 ( V_71 ) ) {
F_4 ( L_12 , V_5 ,
V_71 -> V_26 ) ;
V_29 = - V_6 ;
goto V_57;
}
F_47 ( & V_32 -> V_51 , & V_72 ) ;
F_8 (devfreq, &devfreq_list, node) {
int V_16 = 0 ;
struct V_2 * V_3 = V_1 -> V_3 . V_8 ;
if ( ! strncmp ( V_1 -> V_55 , V_32 -> V_26 ,
V_28 ) ) {
if ( V_1 -> V_32 ) {
F_31 ( V_3 ,
L_13 ,
V_5 , V_1 -> V_32 -> V_26 ) ;
V_16 = V_1 -> V_32 -> V_52 ( V_1 ,
V_53 , NULL ) ;
if ( V_16 ) {
F_31 ( V_3 ,
L_14 ,
V_5 ,
V_1 -> V_32 -> V_26 , V_16 ) ;
}
}
V_1 -> V_32 = V_32 ;
V_16 = V_1 -> V_32 -> V_52 ( V_1 ,
V_67 , NULL ) ;
if ( V_16 ) {
F_31 ( V_3 , L_15 ,
V_5 , V_1 -> V_32 -> V_26 ,
V_16 ) ;
}
}
}
V_57:
F_19 ( & V_7 ) ;
return V_29 ;
}
int F_52 ( struct V_25 * V_32 )
{
struct V_25 * V_71 ;
struct V_1 * V_1 ;
int V_29 = 0 ;
if ( ! V_32 ) {
F_4 ( L_7 , V_5 ) ;
return - V_6 ;
}
F_16 ( & V_7 ) ;
V_71 = F_11 ( V_32 -> V_26 ) ;
if ( F_30 ( V_71 ) ) {
F_4 ( L_16 , V_5 ,
V_32 -> V_26 ) ;
V_29 = F_53 ( V_71 ) ;
goto V_57;
}
F_8 (devfreq, &devfreq_list, node) {
int V_16 ;
struct V_2 * V_3 = V_1 -> V_3 . V_8 ;
if ( ! strncmp ( V_1 -> V_55 , V_32 -> V_26 ,
V_28 ) ) {
if ( ! V_1 -> V_32 ) {
F_31 ( V_3 , L_17 ,
V_5 , V_32 -> V_26 ) ;
continue;
}
V_16 = V_1 -> V_32 -> V_52 ( V_1 ,
V_53 , NULL ) ;
if ( V_16 ) {
F_31 ( V_3 , L_18 ,
V_5 , V_1 -> V_32 -> V_26 ,
V_16 ) ;
}
V_1 -> V_32 = NULL ;
}
}
F_32 ( & V_32 -> V_51 ) ;
V_57:
F_19 ( & V_7 ) ;
return V_29 ;
}
static T_2 F_54 ( struct V_2 * V_3 ,
struct V_73 * V_74 , char * V_75 )
{
if ( ! F_39 ( V_3 ) -> V_32 )
return - V_6 ;
return sprintf ( V_75 , L_19 , F_39 ( V_3 ) -> V_32 -> V_26 ) ;
}
static T_2 F_55 ( struct V_2 * V_3 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_76 )
{
struct V_1 * V_77 = F_39 ( V_3 ) ;
int V_16 ;
char V_78 [ V_28 + 1 ] ;
struct V_25 * V_32 ;
V_16 = sscanf ( V_75 , L_20 F_56 ( V_28 ) L_21 , V_78 ) ;
if ( V_16 != 1 )
return - V_6 ;
F_16 ( & V_7 ) ;
V_32 = F_11 ( V_78 ) ;
if ( F_30 ( V_32 ) ) {
V_16 = F_53 ( V_32 ) ;
goto V_20;
}
if ( V_77 -> V_32 == V_32 )
goto V_20;
if ( V_77 -> V_32 ) {
V_16 = V_77 -> V_32 -> V_52 ( V_77 , V_53 , NULL ) ;
if ( V_16 ) {
F_31 ( V_3 , L_22 ,
V_5 , V_77 -> V_32 -> V_26 , V_16 ) ;
goto V_20;
}
}
V_77 -> V_32 = V_32 ;
strncpy ( V_77 -> V_55 , V_32 -> V_26 , V_28 ) ;
V_16 = V_77 -> V_32 -> V_52 ( V_77 , V_67 , NULL ) ;
if ( V_16 )
F_31 ( V_3 , L_23 ,
V_5 , V_77 -> V_32 -> V_26 , V_16 ) ;
V_20:
F_19 ( & V_7 ) ;
if ( ! V_16 )
V_16 = V_76 ;
return V_16 ;
}
static T_2 F_57 ( struct V_2 * V_79 ,
struct V_73 * V_74 ,
char * V_75 )
{
struct V_25 * V_27 ;
T_2 V_76 = 0 ;
F_16 ( & V_7 ) ;
F_8 (tmp_governor, &devfreq_governor_list, node)
V_76 += F_58 ( & V_75 [ V_76 ] , ( V_80 - V_76 - 2 ) ,
L_24 , V_27 -> V_26 ) ;
F_19 ( & V_7 ) ;
if ( V_76 )
V_76 -- ;
V_76 += sprintf ( & V_75 [ V_76 ] , L_25 ) ;
return V_76 ;
}
static T_2 F_59 ( struct V_2 * V_3 , struct V_73 * V_74 ,
char * V_75 )
{
unsigned long V_10 ;
struct V_1 * V_1 = F_39 ( V_3 ) ;
if ( V_1 -> V_12 -> V_43 &&
! V_1 -> V_12 -> V_43 ( V_1 -> V_3 . V_8 , & V_10 ) )
return sprintf ( V_75 , L_26 , V_10 ) ;
return sprintf ( V_75 , L_26 , V_1 -> V_19 ) ;
}
static T_2 F_60 ( struct V_2 * V_3 ,
struct V_73 * V_74 , char * V_75 )
{
return sprintf ( V_75 , L_26 , F_39 ( V_3 ) -> V_19 ) ;
}
static T_2 F_61 ( struct V_2 * V_3 ,
struct V_73 * V_74 , char * V_75 )
{
return sprintf ( V_75 , L_27 , F_39 ( V_3 ) -> V_12 -> V_41 ) ;
}
static T_2 F_62 ( struct V_2 * V_3 ,
struct V_73 * V_74 ,
const char * V_75 , T_3 V_76 )
{
struct V_1 * V_77 = F_39 ( V_3 ) ;
unsigned int V_81 ;
int V_16 ;
if ( ! V_77 -> V_32 )
return - V_6 ;
V_16 = sscanf ( V_75 , L_28 , & V_81 ) ;
if ( V_16 != 1 )
return - V_6 ;
V_77 -> V_32 -> V_52 ( V_77 , V_82 , & V_81 ) ;
V_16 = V_76 ;
return V_16 ;
}
static T_2 F_63 ( struct V_2 * V_3 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_76 )
{
struct V_1 * V_77 = F_39 ( V_3 ) ;
unsigned long V_81 ;
int V_16 ;
unsigned long V_83 ;
V_16 = sscanf ( V_75 , L_29 , & V_81 ) ;
if ( V_16 != 1 )
return - V_6 ;
F_16 ( & V_77 -> V_31 ) ;
V_83 = V_77 -> V_36 ;
if ( V_81 && V_83 && V_81 > V_83 ) {
V_16 = - V_6 ;
goto V_84;
}
V_77 -> V_34 = V_81 ;
F_12 ( V_77 ) ;
V_16 = V_76 ;
V_84:
F_19 ( & V_77 -> V_31 ) ;
return V_16 ;
}
static T_2 F_64 ( struct V_2 * V_3 , struct V_73 * V_74 ,
char * V_75 )
{
return sprintf ( V_75 , L_26 , F_39 ( V_3 ) -> V_34 ) ;
}
static T_2 F_65 ( struct V_2 * V_3 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_76 )
{
struct V_1 * V_77 = F_39 ( V_3 ) ;
unsigned long V_81 ;
int V_16 ;
unsigned long V_85 ;
V_16 = sscanf ( V_75 , L_29 , & V_81 ) ;
if ( V_16 != 1 )
return - V_6 ;
F_16 ( & V_77 -> V_31 ) ;
V_85 = V_77 -> V_34 ;
if ( V_81 && V_85 && V_81 < V_85 ) {
V_16 = - V_6 ;
goto V_84;
}
V_77 -> V_36 = V_81 ;
F_12 ( V_77 ) ;
V_16 = V_76 ;
V_84:
F_19 ( & V_77 -> V_31 ) ;
return V_16 ;
}
static T_2 F_66 ( struct V_2 * V_3 , struct V_73 * V_74 ,
char * V_75 )
{
return sprintf ( V_75 , L_26 , F_39 ( V_3 ) -> V_36 ) ;
}
static T_2 F_67 ( struct V_2 * V_79 ,
struct V_73 * V_74 ,
char * V_75 )
{
struct V_1 * V_77 = F_39 ( V_79 ) ;
struct V_2 * V_3 = V_77 -> V_3 . V_8 ;
struct V_86 * V_87 ;
T_2 V_76 = 0 ;
unsigned long V_10 = 0 ;
F_68 () ;
do {
V_87 = F_69 ( V_3 , & V_10 ) ;
if ( F_30 ( V_87 ) )
break;
V_76 += F_58 ( & V_75 [ V_76 ] , ( V_80 - V_76 - 2 ) ,
L_30 , V_10 ) ;
V_10 ++ ;
} while ( 1 );
F_70 () ;
if ( V_76 )
V_76 -- ;
V_76 += sprintf ( & V_75 [ V_76 ] , L_25 ) ;
return V_76 ;
}
static T_2 F_71 ( struct V_2 * V_3 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_1 * V_1 = F_39 ( V_3 ) ;
T_2 V_88 ;
int V_89 , V_90 ;
unsigned int V_13 = V_1 -> V_12 -> V_13 ;
if ( ! V_1 -> V_42 &&
F_10 ( V_1 , V_1 -> V_19 ) )
return 0 ;
V_88 = sprintf ( V_75 , L_31 ) ;
V_88 += sprintf ( V_75 + V_88 , L_32 ) ;
for ( V_89 = 0 ; V_89 < V_13 ; V_89 ++ )
V_88 += sprintf ( V_75 + V_88 , L_33 ,
V_1 -> V_12 -> V_14 [ V_89 ] ) ;
V_88 += sprintf ( V_75 + V_88 , L_34 ) ;
for ( V_89 = 0 ; V_89 < V_13 ; V_89 ++ ) {
if ( V_1 -> V_12 -> V_14 [ V_89 ]
== V_1 -> V_19 ) {
V_88 += sprintf ( V_75 + V_88 , L_35 ) ;
} else {
V_88 += sprintf ( V_75 + V_88 , L_36 ) ;
}
V_88 += sprintf ( V_75 + V_88 , L_37 ,
V_1 -> V_12 -> V_14 [ V_89 ] ) ;
for ( V_90 = 0 ; V_90 < V_13 ; V_90 ++ )
V_88 += sprintf ( V_75 + V_88 , L_33 ,
V_1 -> V_23 [ ( V_89 * V_13 ) + V_90 ] ) ;
V_88 += sprintf ( V_75 + V_88 , L_38 ,
F_72 ( V_1 -> V_21 [ V_89 ] ) ) ;
}
V_88 += sprintf ( V_75 + V_88 , L_39 ,
V_1 -> V_24 ) ;
return V_88 ;
}
static int T_4 F_73 ( void )
{
V_61 = F_74 ( V_91 , L_40 ) ;
if ( F_30 ( V_61 ) ) {
F_4 ( L_41 , __FILE__ ) ;
return F_53 ( V_61 ) ;
}
V_40 = F_75 ( L_42 ) ;
if ( ! V_40 ) {
F_76 ( V_61 ) ;
F_4 ( L_43 , __FILE__ ) ;
return - V_59 ;
}
V_61 -> V_92 = V_93 ;
return 0 ;
}
static void T_5 F_77 ( void )
{
F_76 ( V_61 ) ;
F_78 ( V_40 ) ;
}
struct V_86 * F_79 ( struct V_2 * V_3 ,
unsigned long * V_10 ,
T_1 V_30 )
{
struct V_86 * V_87 ;
if ( V_30 & V_35 ) {
V_87 = F_80 ( V_3 , V_10 ) ;
if ( V_87 == F_5 ( - V_94 ) )
V_87 = F_69 ( V_3 , V_10 ) ;
} else {
V_87 = F_69 ( V_3 , V_10 ) ;
if ( V_87 == F_5 ( - V_94 ) )
V_87 = F_80 ( V_3 , V_10 ) ;
}
return V_87 ;
}
int F_81 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
struct V_95 * V_96 ;
int V_16 = 0 ;
F_68 () ;
V_96 = F_82 ( V_3 ) ;
if ( F_30 ( V_96 ) )
V_16 = F_53 ( V_96 ) ;
F_70 () ;
if ( ! V_16 )
V_16 = F_83 ( V_96 , & V_1 -> V_48 ) ;
return V_16 ;
}
int F_84 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
struct V_95 * V_96 ;
int V_16 = 0 ;
F_68 () ;
V_96 = F_82 ( V_3 ) ;
if ( F_30 ( V_96 ) )
V_16 = F_53 ( V_96 ) ;
F_70 () ;
if ( ! V_16 )
V_16 = F_85 ( V_96 , & V_1 -> V_48 ) ;
return V_16 ;
}
