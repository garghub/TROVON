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
F_10 ( V_1 , V_1 -> V_20 ) ;
V_1 -> V_40 = true ;
F_19 ( & V_1 -> V_29 ) ;
F_23 ( & V_1 -> V_37 ) ;
}
void F_25 ( struct V_1 * V_1 )
{
unsigned long V_10 ;
F_16 ( & V_1 -> V_29 ) ;
if ( ! V_1 -> V_40 )
goto V_41;
if ( ! F_26 ( & V_1 -> V_37 ) &&
V_1 -> V_12 -> V_39 )
F_17 ( V_38 , & V_1 -> V_37 ,
F_18 ( V_1 -> V_12 -> V_39 ) ) ;
V_1 -> V_19 = V_17 ;
V_1 -> V_40 = false ;
if ( V_1 -> V_12 -> V_42 &&
! V_1 -> V_12 -> V_42 ( V_1 -> V_3 . V_8 , & V_10 ) )
V_1 -> V_20 = V_10 ;
V_41:
F_19 ( & V_1 -> V_29 ) ;
}
void F_27 ( struct V_1 * V_1 , unsigned int * V_43 )
{
unsigned int V_44 = V_1 -> V_12 -> V_39 ;
unsigned int V_45 = * V_43 ;
F_16 ( & V_1 -> V_29 ) ;
V_1 -> V_12 -> V_39 = V_45 ;
if ( V_1 -> V_40 )
goto V_41;
if ( ! V_45 ) {
F_19 ( & V_1 -> V_29 ) ;
F_23 ( & V_1 -> V_37 ) ;
return;
}
if ( ! V_44 ) {
F_17 ( V_38 , & V_1 -> V_37 ,
F_18 ( V_1 -> V_12 -> V_39 ) ) ;
goto V_41;
}
if ( V_44 > V_45 ) {
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
static int F_28 ( struct V_46 * V_47 , unsigned long type ,
void * V_48 )
{
struct V_1 * V_1 = F_15 ( V_47 , struct V_1 , V_47 ) ;
int V_49 ;
F_16 ( & V_1 -> V_29 ) ;
V_49 = F_12 ( V_1 ) ;
F_19 ( & V_1 -> V_29 ) ;
return V_49 ;
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
if ( V_1 -> V_30 )
V_1 -> V_30 -> V_52 ( V_1 ,
V_53 , NULL ) ;
if ( V_1 -> V_12 -> exit )
V_1 -> V_12 -> exit ( V_1 -> V_3 . V_8 ) ;
if ( ! V_50 && F_33 ( & V_1 -> V_3 ) ) {
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
struct V_54 * V_12 ,
const char * V_55 ,
void * V_56 )
{
struct V_1 * V_1 ;
struct V_23 * V_30 ;
int V_27 = 0 ;
if ( ! V_3 || ! V_12 || ! V_55 ) {
F_13 ( V_3 , L_7 , V_5 ) ;
return F_5 ( - V_6 ) ;
}
F_16 ( & V_7 ) ;
V_1 = F_1 ( V_3 ) ;
F_19 ( & V_7 ) ;
if ( ! F_30 ( V_1 ) ) {
F_13 ( V_3 , L_8 , V_5 ) ;
V_27 = - V_6 ;
goto V_57;
}
V_1 = F_41 ( sizeof( struct V_1 ) , V_58 ) ;
if ( ! V_1 ) {
F_13 ( V_3 , L_9 ,
V_5 ) ;
V_27 = - V_59 ;
goto V_57;
}
F_42 ( & V_1 -> V_29 ) ;
F_16 ( & V_1 -> V_29 ) ;
V_1 -> V_3 . V_8 = V_3 ;
V_1 -> V_3 . V_60 = V_61 ;
V_1 -> V_3 . V_62 = F_38 ;
V_1 -> V_12 = V_12 ;
strncpy ( V_1 -> V_55 , V_55 , V_26 ) ;
V_1 -> V_20 = V_12 -> V_63 ;
V_1 -> V_56 = V_56 ;
V_1 -> V_47 . V_64 = F_28 ;
V_1 -> V_21 = F_43 ( V_3 , sizeof( unsigned int ) *
V_1 -> V_12 -> V_13 *
V_1 -> V_12 -> V_13 ,
V_58 ) ;
V_1 -> V_18 = F_43 ( V_3 , sizeof( unsigned int ) *
V_1 -> V_12 -> V_13 ,
V_58 ) ;
V_1 -> V_19 = V_17 ;
F_44 ( & V_1 -> V_3 , L_10 , F_45 ( V_3 ) ) ;
V_27 = F_46 ( & V_1 -> V_3 ) ;
if ( V_27 ) {
F_35 ( & V_1 -> V_3 ) ;
F_19 ( & V_1 -> V_29 ) ;
goto V_65;
}
F_19 ( & V_1 -> V_29 ) ;
F_16 ( & V_7 ) ;
F_47 ( & V_1 -> V_51 , & V_66 ) ;
V_30 = F_11 ( V_1 -> V_55 ) ;
if ( ! F_30 ( V_30 ) )
V_1 -> V_30 = V_30 ;
if ( V_1 -> V_30 )
V_27 = V_1 -> V_30 -> V_52 ( V_1 ,
V_67 , NULL ) ;
F_19 ( & V_7 ) ;
if ( V_27 ) {
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
return V_1 -> V_30 -> V_52 ( V_1 ,
V_69 , NULL ) ;
}
int F_50 ( struct V_1 * V_1 )
{
if ( ! V_1 )
return - V_6 ;
if ( ! V_1 -> V_30 )
return 0 ;
return V_1 -> V_30 -> V_52 ( V_1 ,
V_70 , NULL ) ;
}
int F_51 ( struct V_23 * V_30 )
{
struct V_23 * V_71 ;
struct V_1 * V_1 ;
int V_27 = 0 ;
if ( ! V_30 ) {
F_4 ( L_7 , V_5 ) ;
return - V_6 ;
}
F_16 ( & V_7 ) ;
V_71 = F_11 ( V_30 -> V_24 ) ;
if ( ! F_30 ( V_71 ) ) {
F_4 ( L_12 , V_5 ,
V_71 -> V_24 ) ;
V_27 = - V_6 ;
goto V_57;
}
F_47 ( & V_30 -> V_51 , & V_72 ) ;
F_8 (devfreq, &devfreq_list, node) {
int V_49 = 0 ;
struct V_2 * V_3 = V_1 -> V_3 . V_8 ;
if ( ! strncmp ( V_1 -> V_55 , V_30 -> V_24 ,
V_26 ) ) {
if ( V_1 -> V_30 ) {
F_31 ( V_3 ,
L_13 ,
V_5 , V_1 -> V_30 -> V_24 ) ;
V_49 = V_1 -> V_30 -> V_52 ( V_1 ,
V_53 , NULL ) ;
if ( V_49 ) {
F_31 ( V_3 ,
L_14 ,
V_5 ,
V_1 -> V_30 -> V_24 , V_49 ) ;
}
}
V_1 -> V_30 = V_30 ;
V_49 = V_1 -> V_30 -> V_52 ( V_1 ,
V_67 , NULL ) ;
if ( V_49 ) {
F_31 ( V_3 , L_15 ,
V_5 , V_1 -> V_30 -> V_24 ,
V_49 ) ;
}
}
}
V_57:
F_19 ( & V_7 ) ;
return V_27 ;
}
int F_52 ( struct V_23 * V_30 )
{
struct V_23 * V_71 ;
struct V_1 * V_1 ;
int V_27 = 0 ;
if ( ! V_30 ) {
F_4 ( L_7 , V_5 ) ;
return - V_6 ;
}
F_16 ( & V_7 ) ;
V_71 = F_11 ( V_30 -> V_24 ) ;
if ( F_30 ( V_71 ) ) {
F_4 ( L_16 , V_5 ,
V_30 -> V_24 ) ;
V_27 = F_53 ( V_71 ) ;
goto V_57;
}
F_8 (devfreq, &devfreq_list, node) {
int V_49 ;
struct V_2 * V_3 = V_1 -> V_3 . V_8 ;
if ( ! strncmp ( V_1 -> V_55 , V_30 -> V_24 ,
V_26 ) ) {
if ( ! V_1 -> V_30 ) {
F_31 ( V_3 , L_17 ,
V_5 , V_30 -> V_24 ) ;
continue;
}
V_49 = V_1 -> V_30 -> V_52 ( V_1 ,
V_53 , NULL ) ;
if ( V_49 ) {
F_31 ( V_3 , L_18 ,
V_5 , V_1 -> V_30 -> V_24 ,
V_49 ) ;
}
V_1 -> V_30 = NULL ;
}
}
F_32 ( & V_30 -> V_51 ) ;
V_57:
F_19 ( & V_7 ) ;
return V_27 ;
}
static T_2 F_54 ( struct V_2 * V_3 ,
struct V_73 * V_74 , char * V_75 )
{
if ( ! F_39 ( V_3 ) -> V_30 )
return - V_6 ;
return sprintf ( V_75 , L_19 , F_39 ( V_3 ) -> V_30 -> V_24 ) ;
}
static T_2 F_55 ( struct V_2 * V_3 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_76 )
{
struct V_1 * V_77 = F_39 ( V_3 ) ;
int V_49 ;
char V_78 [ V_26 + 1 ] ;
struct V_23 * V_30 ;
V_49 = sscanf ( V_75 , L_20 F_56 ( V_26 ) L_21 , V_78 ) ;
if ( V_49 != 1 )
return - V_6 ;
F_16 ( & V_7 ) ;
V_30 = F_11 ( V_78 ) ;
if ( F_30 ( V_30 ) ) {
V_49 = F_53 ( V_30 ) ;
goto V_41;
}
if ( V_77 -> V_30 == V_30 )
goto V_41;
if ( V_77 -> V_30 ) {
V_49 = V_77 -> V_30 -> V_52 ( V_77 , V_53 , NULL ) ;
if ( V_49 ) {
F_31 ( V_3 , L_22 ,
V_5 , V_77 -> V_30 -> V_24 , V_49 ) ;
goto V_41;
}
}
V_77 -> V_30 = V_30 ;
strncpy ( V_77 -> V_55 , V_30 -> V_24 , V_26 ) ;
V_49 = V_77 -> V_30 -> V_52 ( V_77 , V_67 , NULL ) ;
if ( V_49 )
F_31 ( V_3 , L_23 ,
V_5 , V_77 -> V_30 -> V_24 , V_49 ) ;
V_41:
F_19 ( & V_7 ) ;
if ( ! V_49 )
V_49 = V_76 ;
return V_49 ;
}
static T_2 F_57 ( struct V_2 * V_79 ,
struct V_73 * V_74 ,
char * V_75 )
{
struct V_23 * V_25 ;
T_2 V_76 = 0 ;
F_16 ( & V_7 ) ;
F_8 (tmp_governor, &devfreq_governor_list, node)
V_76 += F_58 ( & V_75 [ V_76 ] , ( V_80 - V_76 - 2 ) ,
L_24 , V_25 -> V_24 ) ;
F_19 ( & V_7 ) ;
if ( V_76 )
V_76 -- ;
V_76 += sprintf ( & V_75 [ V_76 ] , L_25 ) ;
return V_76 ;
}
static T_2 F_59 ( struct V_2 * V_3 ,
struct V_73 * V_74 , char * V_75 )
{
unsigned long V_10 ;
struct V_1 * V_1 = F_39 ( V_3 ) ;
if ( V_1 -> V_12 -> V_42 &&
! V_1 -> V_12 -> V_42 ( V_1 -> V_3 . V_8 , & V_10 ) )
return sprintf ( V_75 , L_26 , V_10 ) ;
return sprintf ( V_75 , L_26 , V_1 -> V_20 ) ;
}
static T_2 F_60 ( struct V_2 * V_3 ,
struct V_73 * V_74 , char * V_75 )
{
return sprintf ( V_75 , L_26 , F_39 ( V_3 ) -> V_20 ) ;
}
static T_2 F_61 ( struct V_2 * V_3 ,
struct V_73 * V_74 , char * V_75 )
{
return sprintf ( V_75 , L_27 , F_39 ( V_3 ) -> V_12 -> V_39 ) ;
}
static T_2 F_62 ( struct V_2 * V_3 ,
struct V_73 * V_74 ,
const char * V_75 , T_3 V_76 )
{
struct V_1 * V_77 = F_39 ( V_3 ) ;
unsigned int V_81 ;
int V_49 ;
if ( ! V_77 -> V_30 )
return - V_6 ;
V_49 = sscanf ( V_75 , L_28 , & V_81 ) ;
if ( V_49 != 1 )
return - V_6 ;
V_77 -> V_30 -> V_52 ( V_77 , V_82 , & V_81 ) ;
V_49 = V_76 ;
return V_49 ;
}
static T_2 F_63 ( struct V_2 * V_3 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_76 )
{
struct V_1 * V_77 = F_39 ( V_3 ) ;
unsigned long V_81 ;
int V_49 ;
unsigned long V_83 ;
V_49 = sscanf ( V_75 , L_29 , & V_81 ) ;
if ( V_49 != 1 )
return - V_6 ;
F_16 ( & V_77 -> V_29 ) ;
V_83 = V_77 -> V_34 ;
if ( V_81 && V_83 && V_81 > V_83 ) {
V_49 = - V_6 ;
goto V_84;
}
V_77 -> V_32 = V_81 ;
F_12 ( V_77 ) ;
V_49 = V_76 ;
V_84:
F_19 ( & V_77 -> V_29 ) ;
return V_49 ;
}
static T_2 F_64 ( struct V_2 * V_3 , struct V_73 * V_74 ,
char * V_75 )
{
return sprintf ( V_75 , L_26 , F_39 ( V_3 ) -> V_32 ) ;
}
static T_2 F_65 ( struct V_2 * V_3 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_76 )
{
struct V_1 * V_77 = F_39 ( V_3 ) ;
unsigned long V_81 ;
int V_49 ;
unsigned long V_85 ;
V_49 = sscanf ( V_75 , L_29 , & V_81 ) ;
if ( V_49 != 1 )
return - V_6 ;
F_16 ( & V_77 -> V_29 ) ;
V_85 = V_77 -> V_32 ;
if ( V_81 && V_85 && V_81 < V_85 ) {
V_49 = - V_6 ;
goto V_84;
}
V_77 -> V_34 = V_81 ;
F_12 ( V_77 ) ;
V_49 = V_76 ;
V_84:
F_19 ( & V_77 -> V_29 ) ;
return V_49 ;
}
static T_2 F_66 ( struct V_2 * V_3 , struct V_73 * V_74 ,
char * V_75 )
{
return sprintf ( V_75 , L_26 , F_39 ( V_3 ) -> V_34 ) ;
}
static T_2 F_67 ( struct V_2 * V_79 ,
struct V_73 * V_74 ,
char * V_75 )
{
struct V_1 * V_77 = F_39 ( V_79 ) ;
struct V_2 * V_3 = V_77 -> V_3 . V_8 ;
struct V_86 * V_86 ;
T_2 V_76 = 0 ;
unsigned long V_10 = 0 ;
F_68 () ;
do {
V_86 = F_69 ( V_3 , & V_10 ) ;
if ( F_30 ( V_86 ) )
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
static T_2 F_71 ( struct V_2 * V_3 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_1 * V_1 = F_39 ( V_3 ) ;
T_2 V_87 ;
int V_88 , V_89 ;
unsigned int V_13 = V_1 -> V_12 -> V_13 ;
if ( ! V_1 -> V_40 &&
F_10 ( V_1 , V_1 -> V_20 ) )
return 0 ;
V_87 = sprintf ( V_75 , L_31 ) ;
V_87 += sprintf ( V_75 + V_87 , L_32 ) ;
for ( V_88 = 0 ; V_88 < V_13 ; V_88 ++ )
V_87 += sprintf ( V_75 + V_87 , L_33 ,
V_1 -> V_12 -> V_14 [ V_88 ] ) ;
V_87 += sprintf ( V_75 + V_87 , L_34 ) ;
for ( V_88 = 0 ; V_88 < V_13 ; V_88 ++ ) {
if ( V_1 -> V_12 -> V_14 [ V_88 ]
== V_1 -> V_20 ) {
V_87 += sprintf ( V_75 + V_87 , L_35 ) ;
} else {
V_87 += sprintf ( V_75 + V_87 , L_36 ) ;
}
V_87 += sprintf ( V_75 + V_87 , L_37 ,
V_1 -> V_12 -> V_14 [ V_88 ] ) ;
for ( V_89 = 0 ; V_89 < V_13 ; V_89 ++ )
V_87 += sprintf ( V_75 + V_87 , L_33 ,
V_1 -> V_21 [ ( V_88 * V_13 ) + V_89 ] ) ;
V_87 += sprintf ( V_75 + V_87 , L_38 ,
F_72 ( V_1 -> V_18 [ V_88 ] ) ) ;
}
V_87 += sprintf ( V_75 + V_87 , L_39 ,
V_1 -> V_22 ) ;
return V_87 ;
}
static int T_4 F_73 ( void )
{
V_61 = F_74 ( V_90 , L_40 ) ;
if ( F_30 ( V_61 ) ) {
F_4 ( L_41 , __FILE__ ) ;
return F_53 ( V_61 ) ;
}
V_38 = F_75 ( L_42 ) ;
if ( F_30 ( V_38 ) ) {
F_76 ( V_61 ) ;
F_4 ( L_43 , __FILE__ ) ;
return F_53 ( V_38 ) ;
}
V_61 -> V_91 = V_92 ;
return 0 ;
}
static void T_5 F_77 ( void )
{
F_76 ( V_61 ) ;
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
int V_49 = 0 ;
F_68 () ;
V_95 = F_82 ( V_3 ) ;
if ( F_30 ( V_95 ) )
V_49 = F_53 ( V_95 ) ;
F_70 () ;
if ( ! V_49 )
V_49 = F_83 ( V_95 , & V_1 -> V_47 ) ;
return V_49 ;
}
int F_84 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
struct V_94 * V_95 ;
int V_49 = 0 ;
F_68 () ;
V_95 = F_82 ( V_3 ) ;
if ( F_30 ( V_95 ) )
V_49 = F_53 ( V_95 ) ;
F_70 () ;
if ( ! V_49 )
V_49 = F_85 ( V_95 , & V_1 -> V_47 ) ;
return V_49 ;
}
