static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( F_2 ( V_3 ) ) {
F_3 ( L_1 , V_5 ) ;
return F_4 ( - V_6 ) ;
}
F_5 ( ! F_6 ( & V_7 ) ,
L_2 ) ;
F_7 (tmp_devfreq, &devfreq_list, node) {
if ( V_4 -> V_3 . V_8 == V_3 )
return V_4 ;
}
return F_4 ( - V_9 ) ;
}
static int F_8 ( struct V_1 * V_1 , unsigned long V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_12 -> V_13 ; V_11 ++ )
if ( V_10 == V_1 -> V_12 -> V_14 [ V_11 ] )
return V_11 ;
return - V_6 ;
}
static void F_9 ( struct V_1 * V_1 )
{
struct V_15 * V_12 = V_1 -> V_12 ;
struct V_16 * V_17 ;
unsigned long V_10 ;
int V_18 , V_19 ;
V_19 = F_10 ( V_1 -> V_3 . V_8 ) ;
if ( V_19 <= 0 )
return;
V_12 -> V_13 = V_19 ;
V_12 -> V_14 = F_11 ( V_1 -> V_3 . V_8 ,
V_12 -> V_13 ,
sizeof( * V_12 -> V_14 ) ,
V_20 ) ;
if ( ! V_12 -> V_14 ) {
V_12 -> V_13 = 0 ;
return;
}
F_12 () ;
for ( V_18 = 0 , V_10 = 0 ; V_18 < V_12 -> V_13 ; V_18 ++ , V_10 ++ ) {
V_17 = F_13 ( V_1 -> V_3 . V_8 , & V_10 ) ;
if ( F_14 ( V_17 ) ) {
F_15 ( V_1 -> V_3 . V_8 , V_12 -> V_14 ) ;
V_12 -> V_13 = 0 ;
F_16 () ;
return;
}
V_12 -> V_14 [ V_18 ] = V_10 ;
}
F_16 () ;
}
static int F_17 ( struct V_1 * V_1 , unsigned long V_10 )
{
int V_11 , V_21 , V_22 = 0 ;
unsigned long V_23 ;
V_23 = V_24 ;
V_21 = F_8 ( V_1 , V_1 -> V_25 ) ;
if ( V_21 < 0 ) {
V_22 = V_21 ;
goto V_26;
}
V_1 -> V_27 [ V_21 ] +=
V_23 - V_1 -> V_28 ;
V_11 = F_8 ( V_1 , V_10 ) ;
if ( V_11 < 0 ) {
V_22 = V_11 ;
goto V_26;
}
if ( V_11 != V_21 ) {
V_1 -> V_29 [ ( V_21 *
V_1 -> V_12 -> V_13 ) + V_11 ] ++ ;
V_1 -> V_30 ++ ;
}
V_26:
V_1 -> V_28 = V_23 ;
return V_22 ;
}
static struct V_31 * F_18 ( const char * V_32 )
{
struct V_31 * V_33 ;
if ( F_2 ( V_32 ) ) {
F_3 ( L_1 , V_5 ) ;
return F_4 ( - V_6 ) ;
}
F_5 ( ! F_6 ( & V_7 ) ,
L_2 ) ;
F_7 (tmp_governor, &devfreq_governor_list, node) {
if ( ! strncmp ( V_33 -> V_32 , V_32 , V_34 ) )
return V_33 ;
}
return F_4 ( - V_9 ) ;
}
static int F_19 ( struct V_1 * V_1 ,
struct V_35 * V_36 , unsigned int V_37 )
{
if ( ! V_1 )
return - V_6 ;
switch ( V_37 ) {
case V_38 :
F_20 ( & V_1 -> V_39 ,
V_38 , V_36 ) ;
break;
case V_40 :
F_20 ( & V_1 -> V_39 ,
V_40 , V_36 ) ;
break;
default:
return - V_6 ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_1 )
{
struct V_35 V_36 ;
unsigned long V_10 , V_41 ;
int V_42 = 0 ;
T_1 V_43 = 0 ;
if ( ! F_6 ( & V_1 -> V_44 ) ) {
F_5 ( true , L_3 ) ;
return - V_6 ;
}
if ( ! V_1 -> V_45 )
return - V_6 ;
V_42 = V_1 -> V_45 -> V_46 ( V_1 , & V_10 ) ;
if ( V_42 )
return V_42 ;
if ( V_1 -> V_47 && V_10 < V_1 -> V_47 ) {
V_10 = V_1 -> V_47 ;
V_43 &= ~ V_48 ;
}
if ( V_1 -> V_49 && V_10 > V_1 -> V_49 ) {
V_10 = V_1 -> V_49 ;
V_43 |= V_48 ;
}
if ( V_1 -> V_12 -> V_50 )
V_1 -> V_12 -> V_50 ( V_1 -> V_3 . V_8 , & V_41 ) ;
else
V_41 = V_1 -> V_25 ;
V_36 . V_51 = V_41 ;
V_36 . V_52 = V_10 ;
F_19 ( V_1 , & V_36 , V_38 ) ;
V_42 = V_1 -> V_12 -> V_53 ( V_1 -> V_3 . V_8 , & V_10 , V_43 ) ;
if ( V_42 ) {
V_36 . V_52 = V_41 ;
F_19 ( V_1 , & V_36 , V_40 ) ;
return V_42 ;
}
V_36 . V_52 = V_10 ;
F_19 ( V_1 , & V_36 , V_40 ) ;
if ( V_1 -> V_12 -> V_14 )
if ( F_17 ( V_1 , V_10 ) )
F_22 ( & V_1 -> V_3 ,
L_4 ) ;
V_1 -> V_25 = V_10 ;
return V_42 ;
}
static void F_23 ( struct V_54 * V_55 )
{
int V_42 ;
struct V_1 * V_1 = F_24 ( V_55 ,
struct V_1 , V_55 . V_55 ) ;
F_25 ( & V_1 -> V_44 ) ;
V_42 = F_21 ( V_1 ) ;
if ( V_42 )
F_22 ( & V_1 -> V_3 , L_5 , V_42 ) ;
F_26 ( V_56 , & V_1 -> V_55 ,
F_27 ( V_1 -> V_12 -> V_57 ) ) ;
F_28 ( & V_1 -> V_44 ) ;
}
void F_29 ( struct V_1 * V_1 )
{
F_30 ( & V_1 -> V_55 , F_23 ) ;
if ( V_1 -> V_12 -> V_57 )
F_26 ( V_56 , & V_1 -> V_55 ,
F_27 ( V_1 -> V_12 -> V_57 ) ) ;
}
void F_31 ( struct V_1 * V_1 )
{
F_32 ( & V_1 -> V_55 ) ;
}
void F_33 ( struct V_1 * V_1 )
{
F_25 ( & V_1 -> V_44 ) ;
if ( V_1 -> V_58 ) {
F_28 ( & V_1 -> V_44 ) ;
return;
}
F_17 ( V_1 , V_1 -> V_25 ) ;
V_1 -> V_58 = true ;
F_28 ( & V_1 -> V_44 ) ;
F_32 ( & V_1 -> V_55 ) ;
}
void F_34 ( struct V_1 * V_1 )
{
unsigned long V_10 ;
F_25 ( & V_1 -> V_44 ) ;
if ( ! V_1 -> V_58 )
goto V_26;
if ( ! F_35 ( & V_1 -> V_55 ) &&
V_1 -> V_12 -> V_57 )
F_26 ( V_56 , & V_1 -> V_55 ,
F_27 ( V_1 -> V_12 -> V_57 ) ) ;
V_1 -> V_28 = V_24 ;
V_1 -> V_58 = false ;
if ( V_1 -> V_12 -> V_50 &&
! V_1 -> V_12 -> V_50 ( V_1 -> V_3 . V_8 , & V_10 ) )
V_1 -> V_25 = V_10 ;
V_26:
F_28 ( & V_1 -> V_44 ) ;
}
void F_36 ( struct V_1 * V_1 , unsigned int * V_59 )
{
unsigned int V_60 = V_1 -> V_12 -> V_57 ;
unsigned int V_61 = * V_59 ;
F_25 ( & V_1 -> V_44 ) ;
V_1 -> V_12 -> V_57 = V_61 ;
if ( V_1 -> V_58 )
goto V_26;
if ( ! V_61 ) {
F_28 ( & V_1 -> V_44 ) ;
F_32 ( & V_1 -> V_55 ) ;
return;
}
if ( ! V_60 ) {
F_26 ( V_56 , & V_1 -> V_55 ,
F_27 ( V_1 -> V_12 -> V_57 ) ) ;
goto V_26;
}
if ( V_60 > V_61 ) {
F_28 ( & V_1 -> V_44 ) ;
F_32 ( & V_1 -> V_55 ) ;
F_25 ( & V_1 -> V_44 ) ;
if ( ! V_1 -> V_58 )
F_26 ( V_56 , & V_1 -> V_55 ,
F_27 ( V_1 -> V_12 -> V_57 ) ) ;
}
V_26:
F_28 ( & V_1 -> V_44 ) ;
}
static int F_37 ( struct V_62 * V_63 , unsigned long type ,
void * V_64 )
{
struct V_1 * V_1 = F_24 ( V_63 , struct V_1 , V_63 ) ;
int V_22 ;
F_25 ( & V_1 -> V_44 ) ;
V_22 = F_21 ( V_1 ) ;
F_28 ( & V_1 -> V_44 ) ;
return V_22 ;
}
static void F_38 ( struct V_1 * V_1 )
{
F_25 ( & V_7 ) ;
if ( F_14 ( F_1 ( V_1 -> V_3 . V_8 ) ) ) {
F_28 ( & V_7 ) ;
F_39 ( & V_1 -> V_3 , L_6 ) ;
return;
}
F_40 ( & V_1 -> V_65 ) ;
F_28 ( & V_7 ) ;
if ( V_1 -> V_45 )
V_1 -> V_45 -> V_66 ( V_1 ,
V_67 , NULL ) ;
if ( V_1 -> V_12 -> exit )
V_1 -> V_12 -> exit ( V_1 -> V_3 . V_8 ) ;
F_41 ( & V_1 -> V_44 ) ;
F_42 ( V_1 ) ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_44 ( V_3 ) ;
F_38 ( V_1 ) ;
}
struct V_1 * F_45 ( struct V_2 * V_3 ,
struct V_15 * V_12 ,
const char * V_68 ,
void * V_69 )
{
struct V_1 * V_1 ;
struct V_31 * V_45 ;
int V_42 = 0 ;
if ( ! V_3 || ! V_12 || ! V_68 ) {
F_22 ( V_3 , L_7 , V_5 ) ;
return F_4 ( - V_6 ) ;
}
F_25 ( & V_7 ) ;
V_1 = F_1 ( V_3 ) ;
F_28 ( & V_7 ) ;
if ( ! F_14 ( V_1 ) ) {
F_22 ( V_3 , L_8 , V_5 ) ;
V_42 = - V_6 ;
goto V_70;
}
V_1 = F_46 ( sizeof( struct V_1 ) , V_20 ) ;
if ( ! V_1 ) {
F_22 ( V_3 , L_9 ,
V_5 ) ;
V_42 = - V_71 ;
goto V_70;
}
F_47 ( & V_1 -> V_44 ) ;
F_25 ( & V_1 -> V_44 ) ;
V_1 -> V_3 . V_8 = V_3 ;
V_1 -> V_3 . V_72 = V_73 ;
V_1 -> V_3 . V_74 = F_43 ;
V_1 -> V_12 = V_12 ;
strncpy ( V_1 -> V_68 , V_68 , V_34 ) ;
V_1 -> V_25 = V_12 -> V_75 ;
V_1 -> V_76 . V_77 = V_12 -> V_75 ;
V_1 -> V_69 = V_69 ;
V_1 -> V_63 . V_78 = F_37 ;
if ( ! V_1 -> V_12 -> V_13 && ! V_1 -> V_12 -> V_14 ) {
F_28 ( & V_1 -> V_44 ) ;
F_9 ( V_1 ) ;
F_25 ( & V_1 -> V_44 ) ;
}
F_48 ( & V_1 -> V_3 , L_10 , F_49 ( V_3 ) ) ;
V_42 = F_50 ( & V_1 -> V_3 ) ;
if ( V_42 ) {
F_28 ( & V_1 -> V_44 ) ;
goto V_70;
}
V_1 -> V_29 = F_51 ( & V_1 -> V_3 , sizeof( unsigned int ) *
V_1 -> V_12 -> V_13 *
V_1 -> V_12 -> V_13 ,
V_20 ) ;
V_1 -> V_27 = F_51 ( & V_1 -> V_3 , sizeof( unsigned long ) *
V_1 -> V_12 -> V_13 ,
V_20 ) ;
V_1 -> V_28 = V_24 ;
F_52 ( & V_1 -> V_39 ) ;
F_28 ( & V_1 -> V_44 ) ;
F_25 ( & V_7 ) ;
F_53 ( & V_1 -> V_65 , & V_79 ) ;
V_45 = F_18 ( V_1 -> V_68 ) ;
if ( ! F_14 ( V_45 ) )
V_1 -> V_45 = V_45 ;
if ( V_1 -> V_45 )
V_42 = V_1 -> V_45 -> V_66 ( V_1 ,
V_80 , NULL ) ;
F_28 ( & V_7 ) ;
if ( V_42 ) {
F_22 ( V_3 , L_11 ,
V_5 ) ;
goto V_81;
}
return V_1 ;
V_81:
F_40 ( & V_1 -> V_65 ) ;
F_54 ( & V_1 -> V_3 ) ;
V_70:
return F_4 ( V_42 ) ;
}
int F_55 ( struct V_1 * V_1 )
{
if ( ! V_1 )
return - V_6 ;
F_54 ( & V_1 -> V_3 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 , void * V_82 , void * V_69 )
{
struct V_1 * * V_83 = V_82 ;
if ( F_57 ( ! V_83 || ! * V_83 ) )
return 0 ;
return * V_83 == V_69 ;
}
static void F_58 ( struct V_2 * V_3 , void * V_82 )
{
F_55 ( * (struct V_1 * * ) V_82 ) ;
}
struct V_1 * F_59 ( struct V_2 * V_3 ,
struct V_15 * V_12 ,
const char * V_68 ,
void * V_69 )
{
struct V_1 * * V_84 , * V_1 ;
V_84 = F_60 ( F_58 , sizeof( * V_84 ) , V_20 ) ;
if ( ! V_84 )
return F_4 ( - V_71 ) ;
V_1 = F_45 ( V_3 , V_12 , V_68 , V_69 ) ;
if ( F_14 ( V_1 ) ) {
F_61 ( V_84 ) ;
return F_4 ( - V_71 ) ;
}
* V_84 = V_1 ;
F_62 ( V_3 , V_84 ) ;
return V_1 ;
}
struct V_1 * F_63 ( struct V_2 * V_3 , int V_85 )
{
struct V_86 * V_65 ;
struct V_1 * V_1 ;
if ( ! V_3 )
return F_4 ( - V_6 ) ;
if ( ! V_3 -> V_87 )
return F_4 ( - V_6 ) ;
V_65 = F_64 ( V_3 -> V_87 , L_12 , V_85 ) ;
if ( ! V_65 )
return F_4 ( - V_9 ) ;
F_25 ( & V_7 ) ;
F_7 (devfreq, &devfreq_list, node) {
if ( V_1 -> V_3 . V_8
&& V_1 -> V_3 . V_8 -> V_87 == V_65 ) {
F_28 ( & V_7 ) ;
return V_1 ;
}
}
F_28 ( & V_7 ) ;
return F_4 ( - V_88 ) ;
}
struct V_1 * F_63 ( struct V_2 * V_3 , int V_85 )
{
return F_4 ( - V_9 ) ;
}
void F_65 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
F_57 ( F_66 ( V_3 , F_58 ,
F_56 , V_1 ) ) ;
}
int F_67 ( struct V_1 * V_1 )
{
if ( ! V_1 )
return - V_6 ;
if ( ! V_1 -> V_45 )
return 0 ;
return V_1 -> V_45 -> V_66 ( V_1 ,
V_89 , NULL ) ;
}
int F_68 ( struct V_1 * V_1 )
{
if ( ! V_1 )
return - V_6 ;
if ( ! V_1 -> V_45 )
return 0 ;
return V_1 -> V_45 -> V_66 ( V_1 ,
V_90 , NULL ) ;
}
int F_69 ( struct V_31 * V_45 )
{
struct V_31 * V_91 ;
struct V_1 * V_1 ;
int V_42 = 0 ;
if ( ! V_45 ) {
F_3 ( L_7 , V_5 ) ;
return - V_6 ;
}
F_25 ( & V_7 ) ;
V_91 = F_18 ( V_45 -> V_32 ) ;
if ( ! F_14 ( V_91 ) ) {
F_3 ( L_13 , V_5 ,
V_91 -> V_32 ) ;
V_42 = - V_6 ;
goto V_70;
}
F_53 ( & V_45 -> V_65 , & V_92 ) ;
F_7 (devfreq, &devfreq_list, node) {
int V_22 = 0 ;
struct V_2 * V_3 = V_1 -> V_3 . V_8 ;
if ( ! strncmp ( V_1 -> V_68 , V_45 -> V_32 ,
V_34 ) ) {
if ( V_1 -> V_45 ) {
F_39 ( V_3 ,
L_14 ,
V_5 , V_1 -> V_45 -> V_32 ) ;
V_22 = V_1 -> V_45 -> V_66 ( V_1 ,
V_67 , NULL ) ;
if ( V_22 ) {
F_39 ( V_3 ,
L_15 ,
V_5 ,
V_1 -> V_45 -> V_32 , V_22 ) ;
}
}
V_1 -> V_45 = V_45 ;
V_22 = V_1 -> V_45 -> V_66 ( V_1 ,
V_80 , NULL ) ;
if ( V_22 ) {
F_39 ( V_3 , L_16 ,
V_5 , V_1 -> V_45 -> V_32 ,
V_22 ) ;
}
}
}
V_70:
F_28 ( & V_7 ) ;
return V_42 ;
}
int F_70 ( struct V_31 * V_45 )
{
struct V_31 * V_91 ;
struct V_1 * V_1 ;
int V_42 = 0 ;
if ( ! V_45 ) {
F_3 ( L_7 , V_5 ) ;
return - V_6 ;
}
F_25 ( & V_7 ) ;
V_91 = F_18 ( V_45 -> V_32 ) ;
if ( F_14 ( V_91 ) ) {
F_3 ( L_17 , V_5 ,
V_45 -> V_32 ) ;
V_42 = F_71 ( V_91 ) ;
goto V_70;
}
F_7 (devfreq, &devfreq_list, node) {
int V_22 ;
struct V_2 * V_3 = V_1 -> V_3 . V_8 ;
if ( ! strncmp ( V_1 -> V_68 , V_45 -> V_32 ,
V_34 ) ) {
if ( ! V_1 -> V_45 ) {
F_39 ( V_3 , L_18 ,
V_5 , V_45 -> V_32 ) ;
continue;
}
V_22 = V_1 -> V_45 -> V_66 ( V_1 ,
V_67 , NULL ) ;
if ( V_22 ) {
F_39 ( V_3 , L_19 ,
V_5 , V_1 -> V_45 -> V_32 ,
V_22 ) ;
}
V_1 -> V_45 = NULL ;
}
}
F_40 ( & V_45 -> V_65 ) ;
V_70:
F_28 ( & V_7 ) ;
return V_42 ;
}
static T_2 F_72 ( struct V_2 * V_3 ,
struct V_93 * V_94 , char * V_95 )
{
if ( ! F_44 ( V_3 ) -> V_45 )
return - V_6 ;
return sprintf ( V_95 , L_20 , F_44 ( V_3 ) -> V_45 -> V_32 ) ;
}
static T_2 F_73 ( struct V_2 * V_3 , struct V_93 * V_94 ,
const char * V_95 , T_3 V_19 )
{
struct V_1 * V_96 = F_44 ( V_3 ) ;
int V_22 ;
char V_97 [ V_34 + 1 ] ;
struct V_31 * V_45 ;
V_22 = sscanf ( V_95 , L_21 F_74 ( V_34 ) L_22 , V_97 ) ;
if ( V_22 != 1 )
return - V_6 ;
F_25 ( & V_7 ) ;
V_45 = F_18 ( V_97 ) ;
if ( F_14 ( V_45 ) ) {
V_22 = F_71 ( V_45 ) ;
goto V_26;
}
if ( V_96 -> V_45 == V_45 ) {
V_22 = 0 ;
goto V_26;
}
if ( V_96 -> V_45 ) {
V_22 = V_96 -> V_45 -> V_66 ( V_96 , V_67 , NULL ) ;
if ( V_22 ) {
F_39 ( V_3 , L_23 ,
V_5 , V_96 -> V_45 -> V_32 , V_22 ) ;
goto V_26;
}
}
V_96 -> V_45 = V_45 ;
strncpy ( V_96 -> V_68 , V_45 -> V_32 , V_34 ) ;
V_22 = V_96 -> V_45 -> V_66 ( V_96 , V_80 , NULL ) ;
if ( V_22 )
F_39 ( V_3 , L_24 ,
V_5 , V_96 -> V_45 -> V_32 , V_22 ) ;
V_26:
F_28 ( & V_7 ) ;
if ( ! V_22 )
V_22 = V_19 ;
return V_22 ;
}
static T_2 F_75 ( struct V_2 * V_98 ,
struct V_93 * V_94 ,
char * V_95 )
{
struct V_31 * V_33 ;
T_2 V_19 = 0 ;
F_25 ( & V_7 ) ;
F_7 (tmp_governor, &devfreq_governor_list, node)
V_19 += F_76 ( & V_95 [ V_19 ] , ( V_99 - V_19 - 2 ) ,
L_25 , V_33 -> V_32 ) ;
F_28 ( & V_7 ) ;
if ( V_19 )
V_19 -- ;
V_19 += sprintf ( & V_95 [ V_19 ] , L_26 ) ;
return V_19 ;
}
static T_2 F_77 ( struct V_2 * V_3 , struct V_93 * V_94 ,
char * V_95 )
{
unsigned long V_10 ;
struct V_1 * V_1 = F_44 ( V_3 ) ;
if ( V_1 -> V_12 -> V_50 &&
! V_1 -> V_12 -> V_50 ( V_1 -> V_3 . V_8 , & V_10 ) )
return sprintf ( V_95 , L_27 , V_10 ) ;
return sprintf ( V_95 , L_27 , V_1 -> V_25 ) ;
}
static T_2 F_78 ( struct V_2 * V_3 ,
struct V_93 * V_94 , char * V_95 )
{
return sprintf ( V_95 , L_27 , F_44 ( V_3 ) -> V_25 ) ;
}
static T_2 F_79 ( struct V_2 * V_3 ,
struct V_93 * V_94 , char * V_95 )
{
return sprintf ( V_95 , L_28 , F_44 ( V_3 ) -> V_12 -> V_57 ) ;
}
static T_2 F_80 ( struct V_2 * V_3 ,
struct V_93 * V_94 ,
const char * V_95 , T_3 V_19 )
{
struct V_1 * V_96 = F_44 ( V_3 ) ;
unsigned int V_100 ;
int V_22 ;
if ( ! V_96 -> V_45 )
return - V_6 ;
V_22 = sscanf ( V_95 , L_29 , & V_100 ) ;
if ( V_22 != 1 )
return - V_6 ;
V_96 -> V_45 -> V_66 ( V_96 , V_101 , & V_100 ) ;
V_22 = V_19 ;
return V_22 ;
}
static T_2 F_81 ( struct V_2 * V_3 , struct V_93 * V_94 ,
const char * V_95 , T_3 V_19 )
{
struct V_1 * V_96 = F_44 ( V_3 ) ;
unsigned long V_100 ;
int V_22 ;
unsigned long V_102 ;
V_22 = sscanf ( V_95 , L_30 , & V_100 ) ;
if ( V_22 != 1 )
return - V_6 ;
F_25 ( & V_96 -> V_44 ) ;
V_102 = V_96 -> V_49 ;
if ( V_100 && V_102 && V_100 > V_102 ) {
V_22 = - V_6 ;
goto V_103;
}
V_96 -> V_47 = V_100 ;
F_21 ( V_96 ) ;
V_22 = V_19 ;
V_103:
F_28 ( & V_96 -> V_44 ) ;
return V_22 ;
}
static T_2 F_82 ( struct V_2 * V_3 , struct V_93 * V_94 ,
const char * V_95 , T_3 V_19 )
{
struct V_1 * V_96 = F_44 ( V_3 ) ;
unsigned long V_100 ;
int V_22 ;
unsigned long V_104 ;
V_22 = sscanf ( V_95 , L_30 , & V_100 ) ;
if ( V_22 != 1 )
return - V_6 ;
F_25 ( & V_96 -> V_44 ) ;
V_104 = V_96 -> V_47 ;
if ( V_100 && V_104 && V_100 < V_104 ) {
V_22 = - V_6 ;
goto V_103;
}
V_96 -> V_49 = V_100 ;
F_21 ( V_96 ) ;
V_22 = V_19 ;
V_103:
F_28 ( & V_96 -> V_44 ) ;
return V_22 ;
}
static T_2 F_83 ( struct V_2 * V_98 ,
struct V_93 * V_94 ,
char * V_95 )
{
struct V_1 * V_96 = F_44 ( V_98 ) ;
struct V_2 * V_3 = V_96 -> V_3 . V_8 ;
struct V_16 * V_17 ;
T_2 V_19 = 0 ;
unsigned long V_10 = 0 ;
F_12 () ;
do {
V_17 = F_13 ( V_3 , & V_10 ) ;
if ( F_14 ( V_17 ) )
break;
V_19 += F_76 ( & V_95 [ V_19 ] , ( V_99 - V_19 - 2 ) ,
L_31 , V_10 ) ;
V_10 ++ ;
} while ( 1 );
F_16 () ;
if ( V_19 )
V_19 -- ;
V_19 += sprintf ( & V_95 [ V_19 ] , L_26 ) ;
return V_19 ;
}
static T_2 F_84 ( struct V_2 * V_3 ,
struct V_93 * V_94 , char * V_95 )
{
struct V_1 * V_1 = F_44 ( V_3 ) ;
T_2 V_105 ;
int V_18 , V_106 ;
unsigned int V_13 = V_1 -> V_12 -> V_13 ;
if ( ! V_1 -> V_58 &&
F_17 ( V_1 , V_1 -> V_25 ) )
return 0 ;
if ( V_13 == 0 )
return sprintf ( V_95 , L_32 ) ;
V_105 = sprintf ( V_95 , L_33 ) ;
V_105 += sprintf ( V_95 + V_105 , L_34 ) ;
for ( V_18 = 0 ; V_18 < V_13 ; V_18 ++ )
V_105 += sprintf ( V_95 + V_105 , L_35 ,
V_1 -> V_12 -> V_14 [ V_18 ] ) ;
V_105 += sprintf ( V_95 + V_105 , L_36 ) ;
for ( V_18 = 0 ; V_18 < V_13 ; V_18 ++ ) {
if ( V_1 -> V_12 -> V_14 [ V_18 ]
== V_1 -> V_25 ) {
V_105 += sprintf ( V_95 + V_105 , L_37 ) ;
} else {
V_105 += sprintf ( V_95 + V_105 , L_38 ) ;
}
V_105 += sprintf ( V_95 + V_105 , L_39 ,
V_1 -> V_12 -> V_14 [ V_18 ] ) ;
for ( V_106 = 0 ; V_106 < V_13 ; V_106 ++ )
V_105 += sprintf ( V_95 + V_105 , L_40 ,
V_1 -> V_29 [ ( V_18 * V_13 ) + V_106 ] ) ;
V_105 += sprintf ( V_95 + V_105 , L_41 ,
F_85 ( V_1 -> V_27 [ V_18 ] ) ) ;
}
V_105 += sprintf ( V_95 + V_105 , L_42 ,
V_1 -> V_30 ) ;
return V_105 ;
}
static int T_4 F_86 ( void )
{
V_73 = F_87 ( V_107 , L_12 ) ;
if ( F_14 ( V_73 ) ) {
F_3 ( L_43 , __FILE__ ) ;
return F_71 ( V_73 ) ;
}
V_56 = F_88 ( L_44 ) ;
if ( ! V_56 ) {
F_89 ( V_73 ) ;
F_3 ( L_45 , __FILE__ ) ;
return - V_71 ;
}
V_73 -> V_108 = V_109 ;
return 0 ;
}
static void T_5 F_90 ( void )
{
F_89 ( V_73 ) ;
F_91 ( V_56 ) ;
}
struct V_16 * F_92 ( struct V_2 * V_3 ,
unsigned long * V_10 ,
T_1 V_43 )
{
struct V_16 * V_17 ;
if ( V_43 & V_48 ) {
V_17 = F_93 ( V_3 , V_10 ) ;
if ( V_17 == F_4 ( - V_110 ) )
V_17 = F_13 ( V_3 , V_10 ) ;
} else {
V_17 = F_13 ( V_3 , V_10 ) ;
if ( V_17 == F_4 ( - V_110 ) )
V_17 = F_93 ( V_3 , V_10 ) ;
}
return V_17 ;
}
int F_94 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
struct V_111 * V_112 ;
int V_22 = 0 ;
F_12 () ;
V_112 = F_95 ( V_3 ) ;
if ( F_14 ( V_112 ) )
V_22 = F_71 ( V_112 ) ;
F_16 () ;
if ( ! V_22 )
V_22 = F_96 ( V_112 , & V_1 -> V_63 ) ;
return V_22 ;
}
int F_97 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
struct V_111 * V_112 ;
int V_22 = 0 ;
F_12 () ;
V_112 = F_95 ( V_3 ) ;
if ( F_14 ( V_112 ) )
V_22 = F_71 ( V_112 ) ;
F_16 () ;
if ( ! V_22 )
V_22 = F_98 ( V_112 , & V_1 -> V_63 ) ;
return V_22 ;
}
static void F_99 ( struct V_2 * V_3 , void * V_82 )
{
F_97 ( V_3 , * (struct V_1 * * ) V_82 ) ;
}
int F_100 ( struct V_2 * V_3 ,
struct V_1 * V_1 )
{
struct V_1 * * V_84 ;
int V_22 ;
V_84 = F_60 ( F_99 , sizeof( * V_84 ) , V_20 ) ;
if ( ! V_84 )
return - V_71 ;
V_22 = F_94 ( V_3 , V_1 ) ;
if ( V_22 ) {
F_61 ( V_84 ) ;
return V_22 ;
}
* V_84 = V_1 ;
F_62 ( V_3 , V_84 ) ;
return 0 ;
}
void F_101 ( struct V_2 * V_3 ,
struct V_1 * V_1 )
{
F_57 ( F_66 ( V_3 , F_99 ,
F_56 , V_1 ) ) ;
}
int F_102 ( struct V_1 * V_1 ,
struct V_62 * V_63 ,
unsigned int V_113 )
{
int V_22 = 0 ;
if ( ! V_1 )
return - V_6 ;
switch ( V_113 ) {
case V_114 :
V_22 = F_96 (
& V_1 -> V_39 , V_63 ) ;
break;
default:
V_22 = - V_6 ;
}
return V_22 ;
}
int F_103 ( struct V_1 * V_1 ,
struct V_62 * V_63 ,
unsigned int V_113 )
{
int V_22 = 0 ;
if ( ! V_1 )
return - V_6 ;
switch ( V_113 ) {
case V_114 :
V_22 = F_98 (
& V_1 -> V_39 , V_63 ) ;
break;
default:
V_22 = - V_6 ;
}
return V_22 ;
}
static void F_104 ( struct V_2 * V_3 , void * V_82 )
{
struct V_115 * V_116 = V_82 ;
F_103 ( V_116 -> V_1 , V_116 -> V_63 , V_116 -> V_113 ) ;
}
int F_105 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
struct V_62 * V_63 ,
unsigned int V_113 )
{
struct V_115 * V_84 ;
int V_22 ;
V_84 = F_60 ( F_104 , sizeof( * V_84 ) ,
V_20 ) ;
if ( ! V_84 )
return - V_71 ;
V_22 = F_102 ( V_1 , V_63 , V_113 ) ;
if ( V_22 ) {
F_61 ( V_84 ) ;
return V_22 ;
}
V_84 -> V_1 = V_1 ;
V_84 -> V_63 = V_63 ;
V_84 -> V_113 = V_113 ;
F_62 ( V_3 , V_84 ) ;
return 0 ;
}
void F_106 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
struct V_62 * V_63 ,
unsigned int V_113 )
{
F_57 ( F_66 ( V_3 , F_104 ,
F_56 , V_1 ) ) ;
}
