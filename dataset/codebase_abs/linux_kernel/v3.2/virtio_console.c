static struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_1 ;
struct V_3 * V_4 ;
unsigned long V_5 ;
F_2 ( & V_6 , V_5 ) ;
F_3 (cons, &pdrvdata.consoles, list) {
if ( V_4 -> V_2 == V_2 ) {
V_1 = F_4 ( V_4 , struct V_1 , V_4 ) ;
goto V_7;
}
}
V_1 = NULL ;
V_7:
F_5 ( & V_6 , V_5 ) ;
return V_1 ;
}
static struct V_1 * F_6 ( struct V_8 * V_9 ,
T_2 V_10 )
{
struct V_1 * V_1 ;
unsigned long V_5 ;
F_2 ( & V_9 -> V_11 , V_5 ) ;
F_3 (port, &portdev->ports, list)
if ( V_1 -> V_12 -> V_10 == V_10 )
goto V_7;
V_1 = NULL ;
V_7:
F_5 ( & V_9 -> V_11 , V_5 ) ;
return V_1 ;
}
static struct V_1 * F_7 ( T_2 V_10 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
unsigned long V_5 ;
F_2 ( & V_6 , V_5 ) ;
F_3 (portdev, &pdrvdata.portdevs, list) {
V_1 = F_6 ( V_9 , V_10 ) ;
if ( V_1 )
goto V_7;
}
V_1 = NULL ;
V_7:
F_5 ( & V_6 , V_5 ) ;
return V_1 ;
}
static struct V_1 * F_8 ( struct V_8 * V_9 , T_1 V_13 )
{
struct V_1 * V_1 ;
unsigned long V_5 ;
F_2 ( & V_9 -> V_11 , V_5 ) ;
F_3 (port, &portdev->ports, list)
if ( V_1 -> V_13 == V_13 )
goto V_7;
V_1 = NULL ;
V_7:
F_5 ( & V_9 -> V_11 , V_5 ) ;
return V_1 ;
}
static struct V_1 * F_9 ( struct V_8 * V_9 ,
struct V_14 * V_15 )
{
struct V_1 * V_1 ;
unsigned long V_5 ;
F_2 ( & V_9 -> V_11 , V_5 ) ;
F_3 (port, &portdev->ports, list)
if ( V_1 -> V_16 == V_15 || V_1 -> V_17 == V_15 )
goto V_7;
V_1 = NULL ;
V_7:
F_5 ( & V_9 -> V_11 , V_5 ) ;
return V_1 ;
}
static bool F_10 ( struct V_1 * V_1 )
{
if ( V_1 -> V_4 . V_18 )
return true ;
return false ;
}
static inline bool F_11 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_19 )
return 0 ;
return V_9 -> V_19 -> V_20 [ 0 ] & ( 1 << V_21 ) ;
}
static void F_12 ( struct V_22 * V_23 )
{
F_13 ( V_23 -> V_23 ) ;
F_13 ( V_23 ) ;
}
static struct V_22 * F_14 ( T_3 V_24 )
{
struct V_22 * V_23 ;
V_23 = F_15 ( sizeof( * V_23 ) , V_25 ) ;
if ( ! V_23 )
goto V_26;
V_23 -> V_23 = F_16 ( V_24 , V_25 ) ;
if ( ! V_23 -> V_23 )
goto F_12;
V_23 -> V_27 = 0 ;
V_23 -> V_28 = 0 ;
V_23 -> V_29 = V_24 ;
return V_23 ;
F_12:
F_13 ( V_23 ) ;
V_26:
return NULL ;
}
static struct V_22 * F_17 ( struct V_1 * V_1 )
{
struct V_22 * V_23 ;
unsigned int V_27 ;
if ( V_1 -> V_30 )
return V_1 -> V_30 ;
V_23 = F_18 ( V_1 -> V_16 , & V_27 ) ;
if ( V_23 ) {
V_23 -> V_27 = V_27 ;
V_23 -> V_28 = 0 ;
V_1 -> V_31 . V_32 += V_27 ;
}
return V_23 ;
}
static int F_19 ( struct V_14 * V_15 , struct V_22 * V_23 )
{
struct V_33 V_34 [ 1 ] ;
int V_35 ;
F_20 ( V_34 , V_23 -> V_23 , V_23 -> V_29 ) ;
V_35 = F_21 ( V_15 , V_34 , 0 , 1 , V_23 ) ;
F_22 ( V_15 ) ;
return V_35 ;
}
static void F_23 ( struct V_1 * V_1 )
{
struct V_22 * V_23 ;
unsigned int V_36 ;
if ( ! V_1 -> V_9 ) {
return;
}
V_23 = F_17 ( V_1 ) ;
V_36 = 0 ;
while ( V_23 ) {
V_1 -> V_31 . V_37 += V_23 -> V_27 - V_23 -> V_28 ;
if ( F_19 ( V_1 -> V_16 , V_23 ) < 0 ) {
V_36 ++ ;
F_12 ( V_23 ) ;
}
V_1 -> V_30 = NULL ;
V_23 = F_17 ( V_1 ) ;
}
if ( V_36 )
F_24 ( V_1 -> V_10 , L_1 ,
V_36 ) ;
}
static bool F_25 ( struct V_1 * V_1 )
{
unsigned long V_5 ;
bool V_35 ;
V_35 = false ;
F_2 ( & V_1 -> V_38 , V_5 ) ;
V_1 -> V_30 = F_17 ( V_1 ) ;
if ( V_1 -> V_30 )
V_35 = true ;
F_5 ( & V_1 -> V_38 , V_5 ) ;
return V_35 ;
}
static T_4 F_26 ( struct V_8 * V_9 , T_1 V_39 ,
unsigned int V_40 , unsigned int V_41 )
{
struct V_33 V_34 [ 1 ] ;
struct V_42 V_43 ;
struct V_14 * V_15 ;
unsigned int V_27 ;
if ( ! F_11 ( V_9 ) )
return 0 ;
V_43 . V_13 = V_39 ;
V_43 . V_40 = V_40 ;
V_43 . V_41 = V_41 ;
V_15 = V_9 -> V_44 ;
F_20 ( V_34 , & V_43 , sizeof( V_43 ) ) ;
if ( F_21 ( V_15 , V_34 , 1 , 0 , & V_43 ) >= 0 ) {
F_22 ( V_15 ) ;
while ( ! F_18 ( V_15 , & V_27 ) )
F_27 () ;
}
return 0 ;
}
static T_4 F_28 ( struct V_1 * V_1 , unsigned int V_40 ,
unsigned int V_41 )
{
if ( V_1 -> V_9 )
return F_26 ( V_1 -> V_9 , V_1 -> V_13 , V_40 , V_41 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_1 )
{
void * V_23 ;
unsigned int V_27 ;
if ( ! V_1 -> V_9 ) {
return;
}
while ( ( V_23 = F_18 ( V_1 -> V_17 , & V_27 ) ) ) {
F_13 ( V_23 ) ;
V_1 -> V_45 = false ;
}
}
static T_4 F_30 ( struct V_1 * V_1 , void * V_46 , T_3 V_47 ,
bool V_48 )
{
struct V_33 V_34 [ 1 ] ;
struct V_14 * V_17 ;
T_4 V_35 ;
unsigned long V_5 ;
unsigned int V_27 ;
V_17 = V_1 -> V_17 ;
F_2 ( & V_1 -> V_49 , V_5 ) ;
F_29 ( V_1 ) ;
F_20 ( V_34 , V_46 , V_47 ) ;
V_35 = F_21 ( V_17 , V_34 , 1 , 0 , V_46 ) ;
F_22 ( V_17 ) ;
if ( V_35 < 0 ) {
V_47 = 0 ;
goto V_50;
}
if ( V_35 == 0 )
V_1 -> V_45 = true ;
if ( V_48 )
goto V_50;
while ( ! F_18 ( V_17 , & V_27 ) )
F_27 () ;
V_50:
F_5 ( & V_1 -> V_49 , V_5 ) ;
V_1 -> V_31 . V_51 += V_47 ;
return V_47 ;
}
static T_4 F_31 ( struct V_1 * V_1 , char * V_52 , T_3 V_53 ,
bool V_54 )
{
struct V_22 * V_23 ;
unsigned long V_5 ;
if ( ! V_53 || ! F_25 ( V_1 ) )
return 0 ;
V_23 = V_1 -> V_30 ;
V_53 = F_32 ( V_53 , V_23 -> V_27 - V_23 -> V_28 ) ;
if ( V_54 ) {
T_4 V_35 ;
V_35 = F_33 ( V_52 , V_23 -> V_23 + V_23 -> V_28 , V_53 ) ;
if ( V_35 )
return - V_55 ;
} else {
memcpy ( V_52 , V_23 -> V_23 + V_23 -> V_28 , V_53 ) ;
}
V_23 -> V_28 += V_53 ;
if ( V_23 -> V_28 == V_23 -> V_27 ) {
F_2 ( & V_1 -> V_38 , V_5 ) ;
V_1 -> V_30 = NULL ;
if ( F_19 ( V_1 -> V_16 , V_23 ) < 0 )
F_24 ( V_1 -> V_10 , L_2 ) ;
F_5 ( & V_1 -> V_38 , V_5 ) ;
}
return V_53 ;
}
static bool F_34 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_56 ) {
return false ;
}
return ! F_25 ( V_1 ) && V_1 -> V_57 ;
}
static bool F_35 ( struct V_1 * V_1 )
{
bool V_35 ;
if ( ! V_1 -> V_56 ) {
return false ;
}
if ( ! V_1 -> V_57 )
return true ;
F_36 ( & V_1 -> V_49 ) ;
F_29 ( V_1 ) ;
V_35 = V_1 -> V_45 ;
F_37 ( & V_1 -> V_49 ) ;
return V_35 ;
}
static T_4 F_38 ( struct V_58 * V_59 , char T_5 * V_60 ,
T_3 V_61 , T_6 * V_62 )
{
struct V_1 * V_1 ;
T_4 V_35 ;
V_1 = V_59 -> V_63 ;
if ( ! F_25 ( V_1 ) ) {
if ( ! V_1 -> V_57 )
return 0 ;
if ( V_59 -> V_64 & V_65 )
return - V_66 ;
V_35 = F_39 ( V_1 -> V_67 ,
! F_34 ( V_1 ) ) ;
if ( V_35 < 0 )
return V_35 ;
}
if ( ! V_1 -> V_56 )
return - V_68 ;
if ( ! F_25 ( V_1 ) && ! V_1 -> V_57 )
return 0 ;
return F_31 ( V_1 , V_60 , V_61 , true ) ;
}
static T_4 F_40 ( struct V_58 * V_59 , const char T_5 * V_60 ,
T_3 V_61 , T_6 * V_62 )
{
struct V_1 * V_1 ;
char * V_23 ;
T_4 V_35 ;
bool V_48 ;
if ( ! V_61 )
return 0 ;
V_1 = V_59 -> V_63 ;
V_48 = V_59 -> V_64 & V_65 ;
if ( F_35 ( V_1 ) ) {
if ( V_48 )
return - V_66 ;
V_35 = F_39 ( V_1 -> V_67 ,
! F_35 ( V_1 ) ) ;
if ( V_35 < 0 )
return V_35 ;
}
if ( ! V_1 -> V_56 )
return - V_68 ;
V_61 = F_32 ( ( T_3 ) ( 32 * 1024 ) , V_61 ) ;
V_23 = F_15 ( V_61 , V_25 ) ;
if ( ! V_23 )
return - V_69 ;
V_35 = F_41 ( V_23 , V_60 , V_61 ) ;
if ( V_35 ) {
V_35 = - V_55 ;
goto F_12;
}
V_48 = true ;
V_35 = F_30 ( V_1 , V_23 , V_61 , V_48 ) ;
if ( V_48 && V_35 > 0 )
goto V_7;
F_12:
F_13 ( V_23 ) ;
V_7:
return V_35 ;
}
static unsigned int F_42 ( struct V_58 * V_59 , T_7 * V_70 )
{
struct V_1 * V_1 ;
unsigned int V_35 ;
V_1 = V_59 -> V_63 ;
F_43 ( V_59 , & V_1 -> V_67 , V_70 ) ;
if ( ! V_1 -> V_56 ) {
return V_71 ;
}
V_35 = 0 ;
if ( ! F_34 ( V_1 ) )
V_35 |= V_72 | V_73 ;
if ( ! F_35 ( V_1 ) )
V_35 |= V_74 ;
if ( ! V_1 -> V_57 )
V_35 |= V_71 ;
return V_35 ;
}
static int F_44 ( struct V_75 * V_75 , struct V_58 * V_59 )
{
struct V_1 * V_1 ;
V_1 = V_59 -> V_63 ;
F_28 ( V_1 , V_76 , 0 ) ;
F_36 ( & V_1 -> V_38 ) ;
V_1 -> V_56 = false ;
F_23 ( V_1 ) ;
F_37 ( & V_1 -> V_38 ) ;
F_36 ( & V_1 -> V_49 ) ;
F_29 ( V_1 ) ;
F_37 ( & V_1 -> V_49 ) ;
F_45 ( & V_1 -> V_77 , V_78 ) ;
return 0 ;
}
static int F_46 ( struct V_75 * V_75 , struct V_58 * V_59 )
{
struct V_12 * V_12 = V_75 -> V_79 ;
struct V_1 * V_1 ;
int V_35 ;
V_1 = F_7 ( V_12 -> V_10 ) ;
V_59 -> V_63 = V_1 ;
F_36 ( & V_1 -> V_9 -> V_11 ) ;
F_47 ( & V_1 -> V_77 ) ;
F_37 ( & V_1 -> V_9 -> V_11 ) ;
if ( F_10 ( V_1 ) ) {
V_35 = - V_80 ;
goto V_7;
}
F_36 ( & V_1 -> V_38 ) ;
if ( V_1 -> V_56 ) {
F_37 ( & V_1 -> V_38 ) ;
V_35 = - V_81 ;
goto V_7;
}
V_1 -> V_56 = true ;
F_37 ( & V_1 -> V_38 ) ;
F_36 ( & V_1 -> V_49 ) ;
F_29 ( V_1 ) ;
F_37 ( & V_1 -> V_49 ) ;
F_48 ( V_75 , V_59 ) ;
F_28 ( V_59 -> V_63 , V_76 , 1 ) ;
return 0 ;
V_7:
F_45 ( & V_1 -> V_77 , V_78 ) ;
return V_35 ;
}
static int F_49 ( int V_82 , struct V_58 * V_59 , int V_83 )
{
struct V_1 * V_1 ;
V_1 = V_59 -> V_63 ;
return F_50 ( V_82 , V_59 , V_83 , & V_1 -> V_84 ) ;
}
static int F_51 ( T_1 V_2 , const char * V_23 , int V_61 )
{
struct V_1 * V_1 ;
if ( F_52 ( V_85 ) )
return V_85 ( V_2 , V_23 , V_61 ) ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_86 ;
return F_30 ( V_1 , ( void * ) V_23 , V_61 , false ) ;
}
static int F_53 ( T_1 V_2 , char * V_23 , int V_61 )
{
struct V_1 * V_1 ;
if ( F_52 ( V_85 ) )
return 0 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_86 ;
F_54 ( ! V_1 -> V_16 ) ;
return F_31 ( V_1 , V_23 , V_61 , false ) ;
}
static void F_55 ( struct V_1 * V_1 )
{
struct V_87 * V_19 ;
if ( ! V_1 || ! F_10 ( V_1 ) )
return;
V_19 = V_1 -> V_9 -> V_19 ;
if ( F_56 ( V_19 , V_88 ) )
F_57 ( V_1 -> V_4 . V_18 , V_1 -> V_4 . V_89 ) ;
}
static int F_58 ( struct V_90 * V_91 , int V_92 )
{
struct V_1 * V_1 ;
V_1 = F_1 ( V_91 -> V_2 ) ;
if ( ! V_1 )
return - V_93 ;
V_91 -> V_94 = 1 ;
F_55 ( V_1 ) ;
return 0 ;
}
static void F_59 ( struct V_90 * V_91 , int V_92 )
{
V_91 -> V_94 = 0 ;
}
int T_8 F_60 ( int (* F_51)( T_1 , const char * , int ) )
{
V_85 = F_51 ;
return F_61 ( 0 , 0 , & V_95 ) ;
}
int F_62 ( struct V_1 * V_1 )
{
int V_35 ;
V_1 -> V_4 . V_2 = V_96 . V_97 ;
V_1 -> V_4 . V_18 = F_63 ( V_1 -> V_4 . V_2 , 0 , & V_95 , V_98 ) ;
if ( F_64 ( V_1 -> V_4 . V_18 ) ) {
V_35 = F_65 ( V_1 -> V_4 . V_18 ) ;
F_66 ( V_1 -> V_10 ,
L_3 , V_35 ) ;
V_1 -> V_4 . V_18 = NULL ;
return V_35 ;
}
F_36 ( & V_6 ) ;
V_96 . V_97 ++ ;
F_67 ( & V_1 -> V_4 . V_99 , & V_96 . V_100 ) ;
F_37 ( & V_6 ) ;
V_1 -> V_56 = true ;
if ( V_85 )
V_85 = NULL ;
F_28 ( V_1 , V_76 , 1 ) ;
return 0 ;
}
static T_4 F_68 ( struct V_101 * V_10 ,
struct V_102 * V_103 , char * V_104 )
{
struct V_1 * V_1 ;
V_1 = F_69 ( V_10 ) ;
return sprintf ( V_104 , L_4 , V_1 -> V_105 ) ;
}
static int F_70 ( struct V_75 * V_75 , struct V_58 * V_59 )
{
V_59 -> V_63 = V_75 -> V_106 ;
return 0 ;
}
static T_4 F_71 ( struct V_58 * V_59 , char T_5 * V_60 ,
T_3 V_61 , T_6 * V_62 )
{
struct V_1 * V_1 ;
char * V_23 ;
T_4 V_35 , V_107 , V_53 ;
V_53 = 1024 ;
V_23 = F_15 ( V_53 , V_25 ) ;
if ( ! V_23 )
return - V_69 ;
V_1 = V_59 -> V_63 ;
V_107 = 0 ;
V_107 += snprintf ( V_23 + V_107 , V_53 ,
L_5 , V_1 -> V_105 ? V_1 -> V_105 : L_6 ) ;
V_107 += snprintf ( V_23 + V_107 , V_53 - V_107 ,
L_7 , V_1 -> V_56 ) ;
V_107 += snprintf ( V_23 + V_107 , V_53 - V_107 ,
L_8 , V_1 -> V_57 ) ;
V_107 += snprintf ( V_23 + V_107 , V_53 - V_107 ,
L_9 , V_1 -> V_45 ) ;
V_107 += snprintf ( V_23 + V_107 , V_53 - V_107 ,
L_10 , V_1 -> V_31 . V_51 ) ;
V_107 += snprintf ( V_23 + V_107 , V_53 - V_107 ,
L_11 ,
V_1 -> V_31 . V_32 ) ;
V_107 += snprintf ( V_23 + V_107 , V_53 - V_107 ,
L_12 ,
V_1 -> V_31 . V_37 ) ;
V_107 += snprintf ( V_23 + V_107 , V_53 - V_107 ,
L_13 ,
F_10 ( V_1 ) ? L_14 : L_15 ) ;
V_107 += snprintf ( V_23 + V_107 , V_53 - V_107 ,
L_16 , V_1 -> V_4 . V_2 ) ;
V_35 = F_72 ( V_60 , V_61 , V_62 , V_23 , V_107 ) ;
F_13 ( V_23 ) ;
return V_35 ;
}
static void F_73 ( struct V_1 * V_1 , T_9 V_108 , T_9 V_109 )
{
if ( ! V_1 || ! F_10 ( V_1 ) )
return;
V_1 -> V_4 . V_89 . V_110 = V_108 ;
V_1 -> V_4 . V_89 . V_111 = V_109 ;
}
static unsigned int F_74 ( struct V_14 * V_15 , T_10 * V_112 )
{
struct V_22 * V_23 ;
unsigned int V_113 ;
int V_35 ;
V_113 = 0 ;
do {
V_23 = F_14 ( V_98 ) ;
if ( ! V_23 )
break;
F_36 ( V_112 ) ;
V_35 = F_19 ( V_15 , V_23 ) ;
if ( V_35 < 0 ) {
F_37 ( V_112 ) ;
F_12 ( V_23 ) ;
break;
}
V_113 ++ ;
F_37 ( V_112 ) ;
} while ( V_35 > 0 );
return V_113 ;
}
static void F_75 ( struct V_1 * V_1 )
{
if ( V_1 -> V_84 && V_1 -> V_56 )
F_76 ( & V_1 -> V_84 , V_114 , V_115 ) ;
}
static int F_77 ( struct V_8 * V_9 , T_1 V_13 )
{
char V_116 [ 16 ] ;
struct V_1 * V_1 ;
struct V_22 * V_23 ;
T_2 V_117 ;
unsigned int V_113 ;
int V_36 ;
V_1 = F_15 ( sizeof( * V_1 ) , V_25 ) ;
if ( ! V_1 ) {
V_36 = - V_69 ;
goto V_26;
}
F_78 ( & V_1 -> V_77 ) ;
V_1 -> V_9 = V_9 ;
V_1 -> V_13 = V_13 ;
V_1 -> V_105 = NULL ;
V_1 -> V_30 = NULL ;
V_1 -> V_4 . V_18 = NULL ;
V_1 -> V_84 = NULL ;
V_1 -> V_4 . V_89 . V_110 = V_1 -> V_4 . V_89 . V_111 = 0 ;
V_1 -> V_57 = V_1 -> V_56 = false ;
V_1 -> V_31 = (struct V_118 ) { 0 } ;
V_1 -> V_45 = false ;
V_1 -> V_16 = V_9 -> V_119 [ V_1 -> V_13 ] ;
V_1 -> V_17 = V_9 -> V_120 [ V_1 -> V_13 ] ;
V_1 -> V_12 = F_79 () ;
if ( ! V_1 -> V_12 ) {
F_66 ( & V_1 -> V_9 -> V_19 -> V_10 , L_17 ) ;
V_36 = - V_69 ;
goto V_121;
}
V_1 -> V_12 -> V_122 = & V_123 ;
V_117 = F_80 ( V_9 -> V_124 , V_13 ) ;
V_36 = F_81 ( V_1 -> V_12 , V_117 , 1 ) ;
if ( V_36 < 0 ) {
F_66 ( & V_1 -> V_9 -> V_19 -> V_10 ,
L_18 , V_36 , V_13 ) ;
goto V_125;
}
V_1 -> V_10 = F_82 ( V_96 . V_126 , & V_1 -> V_9 -> V_19 -> V_10 ,
V_117 , V_1 , L_19 ,
V_1 -> V_9 -> V_127 , V_13 ) ;
if ( F_64 ( V_1 -> V_10 ) ) {
V_36 = F_65 ( V_1 -> V_10 ) ;
F_66 ( & V_1 -> V_9 -> V_19 -> V_10 ,
L_20 ,
V_36 , V_13 ) ;
goto V_125;
}
F_83 ( & V_1 -> V_38 ) ;
F_83 ( & V_1 -> V_49 ) ;
F_84 ( & V_1 -> V_67 ) ;
V_113 = F_74 ( V_1 -> V_16 , & V_1 -> V_38 ) ;
if ( ! V_113 ) {
F_66 ( V_1 -> V_10 , L_21 ) ;
V_36 = - V_69 ;
goto V_128;
}
if ( ! F_11 ( V_1 -> V_9 ) ) {
V_36 = F_62 ( V_1 ) ;
if ( V_36 )
goto V_129;
}
F_36 ( & V_9 -> V_11 ) ;
F_67 ( & V_1 -> V_99 , & V_1 -> V_9 -> V_130 ) ;
F_37 ( & V_9 -> V_11 ) ;
F_28 ( V_1 , V_131 , 1 ) ;
if ( V_96 . V_132 ) {
sprintf ( V_116 , L_19 ,
V_1 -> V_9 -> V_127 , V_13 ) ;
V_1 -> V_133 = F_85 ( V_116 , 0444 ,
V_96 . V_132 ,
V_1 ,
& V_134 ) ;
}
return 0 ;
V_129:
while ( ( V_23 = F_86 ( V_1 -> V_16 ) ) )
F_12 ( V_23 ) ;
V_128:
F_87 ( V_96 . V_126 , V_1 -> V_10 -> V_117 ) ;
V_125:
F_88 ( V_1 -> V_12 ) ;
V_121:
F_13 ( V_1 ) ;
V_26:
F_26 ( V_9 , V_13 , V_131 , 0 ) ;
return V_36 ;
}
static void V_78 ( struct V_77 * V_77 )
{
struct V_1 * V_1 ;
V_1 = F_4 ( V_77 , struct V_1 , V_77 ) ;
F_89 ( & V_1 -> V_10 -> V_135 , & V_136 ) ;
F_87 ( V_96 . V_126 , V_1 -> V_10 -> V_117 ) ;
F_88 ( V_1 -> V_12 ) ;
F_13 ( V_1 -> V_105 ) ;
F_90 ( V_1 -> V_133 ) ;
F_13 ( V_1 ) ;
}
static void F_91 ( struct V_1 * V_1 )
{
struct V_22 * V_23 ;
F_36 ( & V_1 -> V_9 -> V_11 ) ;
F_92 ( & V_1 -> V_99 ) ;
F_37 ( & V_1 -> V_9 -> V_11 ) ;
if ( V_1 -> V_56 ) {
V_1 -> V_56 = false ;
V_1 -> V_57 = false ;
F_93 ( & V_1 -> V_67 ) ;
F_75 ( V_1 ) ;
}
if ( F_10 ( V_1 ) ) {
F_36 ( & V_6 ) ;
F_92 ( & V_1 -> V_4 . V_99 ) ;
F_37 ( & V_6 ) ;
F_94 ( V_1 -> V_4 . V_18 ) ;
}
F_23 ( V_1 ) ;
F_29 ( V_1 ) ;
while ( ( V_23 = F_86 ( V_1 -> V_16 ) ) )
F_12 ( V_23 ) ;
V_1 -> V_9 = NULL ;
F_45 ( & V_1 -> V_77 , V_78 ) ;
}
static void F_95 ( struct V_8 * V_9 ,
struct V_22 * V_23 )
{
struct V_42 * V_43 ;
struct V_1 * V_1 ;
T_3 V_137 ;
int V_36 ;
V_43 = (struct V_42 * ) ( V_23 -> V_23 + V_23 -> V_28 ) ;
V_1 = F_8 ( V_9 , V_43 -> V_13 ) ;
if ( ! V_1 && V_43 -> V_40 != V_138 ) {
F_96 ( & V_9 -> V_19 -> V_10 ,
L_22 , V_43 -> V_13 ) ;
return;
}
switch ( V_43 -> V_40 ) {
case V_138 :
if ( V_1 ) {
F_96 ( & V_9 -> V_19 -> V_10 ,
L_23 , V_1 -> V_13 ) ;
F_28 ( V_1 , V_131 , 1 ) ;
break;
}
if ( V_43 -> V_13 >= V_9 -> V_139 . V_140 ) {
F_24 ( & V_9 -> V_19 -> V_10 ,
L_24 ,
V_43 -> V_13 , V_9 -> V_139 . V_140 - 1 ) ;
break;
}
F_77 ( V_9 , V_43 -> V_13 ) ;
break;
case V_141 :
F_91 ( V_1 ) ;
break;
case V_142 :
if ( ! V_43 -> V_41 )
break;
if ( F_10 ( V_1 ) )
break;
F_62 ( V_1 ) ;
F_97 ( & V_143 ) ;
break;
case V_144 : {
struct {
T_11 V_108 ;
T_11 V_109 ;
} V_29 ;
if ( ! F_10 ( V_1 ) )
break;
memcpy ( & V_29 , V_23 -> V_23 + V_23 -> V_28 + sizeof( * V_43 ) ,
sizeof( V_29 ) ) ;
F_73 ( V_1 , V_29 . V_108 , V_29 . V_109 ) ;
V_1 -> V_4 . V_18 -> V_94 = 1 ;
F_55 ( V_1 ) ;
break;
}
case V_76 :
V_1 -> V_57 = V_43 -> V_41 ;
F_93 ( & V_1 -> V_67 ) ;
F_36 ( & V_1 -> V_49 ) ;
F_29 ( V_1 ) ;
F_37 ( & V_1 -> V_49 ) ;
F_75 ( V_1 ) ;
break;
case V_145 :
if ( V_1 -> V_105 )
break;
V_137 = V_23 -> V_27 - V_23 -> V_28 - sizeof( * V_43 ) + 1 ;
V_1 -> V_105 = F_15 ( V_137 , V_25 ) ;
if ( ! V_1 -> V_105 ) {
F_66 ( V_1 -> V_10 ,
L_25 ) ;
break;
}
strncpy ( V_1 -> V_105 , V_23 -> V_23 + V_23 -> V_28 + sizeof( * V_43 ) ,
V_137 - 1 ) ;
V_1 -> V_105 [ V_137 - 1 ] = 0 ;
V_36 = F_98 ( & V_1 -> V_10 -> V_135 ,
& V_136 ) ;
if ( V_36 ) {
F_66 ( V_1 -> V_10 ,
L_26 ,
V_36 ) ;
} else {
F_99 ( & V_1 -> V_10 -> V_135 , V_146 ) ;
}
break;
}
}
static void F_100 ( struct V_147 * V_148 )
{
struct V_8 * V_9 ;
struct V_14 * V_15 ;
struct V_22 * V_23 ;
unsigned int V_27 ;
V_9 = F_4 ( V_148 , struct V_8 , V_149 ) ;
V_15 = V_9 -> V_150 ;
F_101 ( & V_9 -> V_151 ) ;
while ( ( V_23 = F_18 ( V_15 , & V_27 ) ) ) {
F_102 ( & V_9 -> V_151 ) ;
V_23 -> V_27 = V_27 ;
V_23 -> V_28 = 0 ;
F_95 ( V_9 , V_23 ) ;
F_101 ( & V_9 -> V_151 ) ;
if ( F_19 ( V_9 -> V_150 , V_23 ) < 0 ) {
F_24 ( & V_9 -> V_19 -> V_10 ,
L_27 ) ;
F_12 ( V_23 ) ;
}
}
F_102 ( & V_9 -> V_151 ) ;
}
static void F_103 ( struct V_14 * V_15 )
{
struct V_1 * V_1 ;
V_1 = F_9 ( V_15 -> V_19 -> V_152 , V_15 ) ;
if ( ! V_1 )
return;
F_93 ( & V_1 -> V_67 ) ;
}
static void F_104 ( struct V_14 * V_15 )
{
struct V_1 * V_1 ;
unsigned long V_5 ;
V_1 = F_9 ( V_15 -> V_19 -> V_152 , V_15 ) ;
if ( ! V_1 )
return;
F_2 ( & V_1 -> V_38 , V_5 ) ;
V_1 -> V_30 = F_17 ( V_1 ) ;
if ( ! V_1 -> V_56 )
F_23 ( V_1 ) ;
F_5 ( & V_1 -> V_38 , V_5 ) ;
F_93 ( & V_1 -> V_67 ) ;
F_75 ( V_1 ) ;
if ( F_10 ( V_1 ) && F_105 ( V_1 -> V_4 . V_18 ) )
F_106 () ;
}
static void F_107 ( struct V_14 * V_15 )
{
struct V_8 * V_9 ;
V_9 = V_15 -> V_19 -> V_152 ;
F_108 ( & V_9 -> V_149 ) ;
}
static void F_109 ( struct V_87 * V_19 )
{
struct V_8 * V_9 ;
V_9 = V_19 -> V_152 ;
if ( ! F_11 ( V_9 ) ) {
struct V_1 * V_1 ;
T_9 V_108 , V_109 ;
V_19 -> V_139 -> V_153 ( V_19 ,
F_110 ( struct V_154 , V_109 ) ,
& V_109 , sizeof( T_9 ) ) ;
V_19 -> V_139 -> V_153 ( V_19 ,
F_110 ( struct V_154 , V_108 ) ,
& V_108 , sizeof( T_9 ) ) ;
V_1 = F_8 ( V_9 , 0 ) ;
F_73 ( V_1 , V_108 , V_109 ) ;
F_55 ( V_1 ) ;
}
}
static int F_111 ( struct V_8 * V_9 )
{
T_12 * * V_155 ;
char * * V_156 ;
struct V_14 * * V_157 ;
T_1 V_158 , V_159 , V_160 , V_161 ;
int V_36 ;
V_160 = V_9 -> V_139 . V_140 ;
V_161 = F_11 ( V_9 ) ? ( V_160 + 1 ) * 2 : 2 ;
V_157 = F_15 ( V_161 * sizeof( struct V_14 * ) , V_25 ) ;
V_155 = F_15 ( V_161 * sizeof( T_12 * ) , V_25 ) ;
V_156 = F_15 ( V_161 * sizeof( char * ) , V_25 ) ;
V_9 -> V_119 = F_15 ( V_160 * sizeof( struct V_14 * ) ,
V_25 ) ;
V_9 -> V_120 = F_15 ( V_160 * sizeof( struct V_14 * ) ,
V_25 ) ;
if ( ! V_157 || ! V_155 || ! V_156 || ! V_9 -> V_119 ||
! V_9 -> V_120 ) {
V_36 = - V_69 ;
goto free;
}
V_159 = 0 ;
V_155 [ V_159 ] = F_104 ;
V_155 [ V_159 + 1 ] = F_103 ;
V_156 [ V_159 ] = L_28 ;
V_156 [ V_159 + 1 ] = L_29 ;
V_159 += 2 ;
if ( F_11 ( V_9 ) ) {
V_155 [ V_159 ] = F_107 ;
V_155 [ V_159 + 1 ] = NULL ;
V_156 [ V_159 ] = L_30 ;
V_156 [ V_159 + 1 ] = L_31 ;
for ( V_158 = 1 ; V_158 < V_160 ; V_158 ++ ) {
V_159 += 2 ;
V_155 [ V_159 ] = F_104 ;
V_155 [ V_159 + 1 ] = F_103 ;
V_156 [ V_159 ] = L_28 ;
V_156 [ V_159 + 1 ] = L_29 ;
}
}
V_36 = V_9 -> V_19 -> V_139 -> V_162 ( V_9 -> V_19 , V_161 , V_157 ,
V_155 ,
( const char * * ) V_156 ) ;
if ( V_36 )
goto free;
V_159 = 0 ;
V_9 -> V_119 [ 0 ] = V_157 [ 0 ] ;
V_9 -> V_120 [ 0 ] = V_157 [ 1 ] ;
V_159 += 2 ;
if ( F_11 ( V_9 ) ) {
V_9 -> V_150 = V_157 [ V_159 ] ;
V_9 -> V_44 = V_157 [ V_159 + 1 ] ;
for ( V_158 = 1 ; V_158 < V_160 ; V_158 ++ ) {
V_159 += 2 ;
V_9 -> V_119 [ V_158 ] = V_157 [ V_159 ] ;
V_9 -> V_120 [ V_158 ] = V_157 [ V_159 + 1 ] ;
}
}
F_13 ( V_156 ) ;
F_13 ( V_155 ) ;
F_13 ( V_157 ) ;
return 0 ;
free:
F_13 ( V_9 -> V_120 ) ;
F_13 ( V_9 -> V_119 ) ;
F_13 ( V_156 ) ;
F_13 ( V_155 ) ;
F_13 ( V_157 ) ;
return V_36 ;
}
static int T_13 F_112 ( struct V_87 * V_19 )
{
struct V_8 * V_9 ;
int V_36 ;
bool V_163 ;
bool V_164 = V_85 != NULL ;
F_113 () ;
V_9 = F_15 ( sizeof( * V_9 ) , V_25 ) ;
if ( ! V_9 ) {
V_36 = - V_69 ;
goto V_26;
}
V_9 -> V_19 = V_19 ;
V_19 -> V_152 = V_9 ;
F_36 ( & V_6 ) ;
V_9 -> V_127 = V_96 . V_165 ++ ;
F_37 ( & V_6 ) ;
V_9 -> V_124 = F_114 ( 0 , L_32 ,
& V_166 ) ;
if ( V_9 -> V_124 < 0 ) {
F_66 ( & V_19 -> V_10 ,
L_33 ,
V_9 -> V_124 , V_9 -> V_127 ) ;
V_36 = V_9 -> V_124 ;
goto free;
}
V_163 = false ;
V_9 -> V_139 . V_140 = 1 ;
if ( F_115 ( V_19 , V_21 ,
F_110 ( struct V_154 ,
V_140 ) ,
& V_9 -> V_139 . V_140 ) == 0 )
V_163 = true ;
V_36 = F_111 ( V_9 ) ;
if ( V_36 < 0 ) {
F_66 ( & V_19 -> V_10 , L_34 , V_36 ) ;
goto V_167;
}
F_83 ( & V_9 -> V_11 ) ;
F_116 ( & V_9 -> V_130 ) ;
if ( V_163 ) {
unsigned int V_113 ;
F_83 ( & V_9 -> V_151 ) ;
F_117 ( & V_9 -> V_149 , & F_100 ) ;
V_113 = F_74 ( V_9 -> V_150 , & V_9 -> V_151 ) ;
if ( ! V_113 ) {
F_66 ( & V_19 -> V_10 ,
L_35 ) ;
V_36 = - V_69 ;
goto V_168;
}
} else {
F_77 ( V_9 , 0 ) ;
}
F_36 ( & V_6 ) ;
F_67 ( & V_9 -> V_99 , & V_96 . V_169 ) ;
F_37 ( & V_6 ) ;
F_26 ( V_9 , V_170 ,
V_171 , 1 ) ;
if ( V_163 && V_164 )
F_118 ( & V_143 ) ;
return 0 ;
V_168:
F_26 ( V_9 , V_170 ,
V_171 , 0 ) ;
V_19 -> V_139 -> V_172 ( V_19 ) ;
F_13 ( V_9 -> V_119 ) ;
F_13 ( V_9 -> V_120 ) ;
V_167:
F_119 ( V_9 -> V_124 , L_32 ) ;
free:
F_13 ( V_9 ) ;
V_26:
return V_36 ;
}
static void F_120 ( struct V_87 * V_19 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 , * V_173 ;
V_9 = V_19 -> V_152 ;
F_36 ( & V_6 ) ;
F_92 ( & V_9 -> V_99 ) ;
F_37 ( & V_6 ) ;
V_19 -> V_139 -> V_174 ( V_19 ) ;
F_121 ( & V_9 -> V_149 ) ;
F_122 (port, port2, &portdev->ports, list)
F_91 ( V_1 ) ;
F_119 ( V_9 -> V_124 , L_32 ) ;
if ( F_11 ( V_9 ) ) {
struct V_22 * V_23 ;
unsigned int V_27 ;
while ( ( V_23 = F_18 ( V_9 -> V_150 , & V_27 ) ) )
F_12 ( V_23 ) ;
while ( ( V_23 = F_86 ( V_9 -> V_150 ) ) )
F_12 ( V_23 ) ;
}
V_19 -> V_139 -> V_172 ( V_19 ) ;
F_13 ( V_9 -> V_119 ) ;
F_13 ( V_9 -> V_120 ) ;
F_13 ( V_9 ) ;
}
static int T_8 F_123 ( void )
{
int V_36 ;
V_96 . V_126 = F_124 ( V_175 , L_36 ) ;
if ( F_64 ( V_96 . V_126 ) ) {
V_36 = F_65 ( V_96 . V_126 ) ;
F_125 ( L_37 , V_36 ) ;
return V_36 ;
}
V_96 . V_132 = F_126 ( L_36 , NULL ) ;
if ( ! V_96 . V_132 ) {
F_127 ( L_38 ,
F_65 ( V_96 . V_132 ) ) ;
}
F_116 ( & V_96 . V_100 ) ;
F_116 ( & V_96 . V_169 ) ;
return F_128 ( & V_176 ) ;
}
static void T_14 F_129 ( void )
{
F_130 ( & V_176 ) ;
F_131 ( V_96 . V_126 ) ;
if ( V_96 . V_132 )
F_132 ( V_96 . V_132 ) ;
}
