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
V_35 = F_21 ( V_15 , V_34 , 0 , 1 , V_23 , V_36 ) ;
F_22 ( V_15 ) ;
return V_35 ;
}
static void F_23 ( struct V_1 * V_1 )
{
struct V_22 * V_23 ;
unsigned int V_37 ;
if ( ! V_1 -> V_9 ) {
return;
}
V_23 = F_17 ( V_1 ) ;
V_37 = 0 ;
while ( V_23 ) {
V_1 -> V_31 . V_38 += V_23 -> V_27 - V_23 -> V_28 ;
if ( F_19 ( V_1 -> V_16 , V_23 ) < 0 ) {
V_37 ++ ;
F_12 ( V_23 ) ;
}
V_1 -> V_30 = NULL ;
V_23 = F_17 ( V_1 ) ;
}
if ( V_37 )
F_24 ( V_1 -> V_10 , L_1 ,
V_37 ) ;
}
static bool F_25 ( struct V_1 * V_1 )
{
unsigned long V_5 ;
bool V_35 ;
V_35 = false ;
F_2 ( & V_1 -> V_39 , V_5 ) ;
V_1 -> V_30 = F_17 ( V_1 ) ;
if ( V_1 -> V_30 )
V_35 = true ;
F_5 ( & V_1 -> V_39 , V_5 ) ;
return V_35 ;
}
static T_4 F_26 ( struct V_8 * V_9 , T_1 V_40 ,
unsigned int V_41 , unsigned int V_42 )
{
struct V_33 V_34 [ 1 ] ;
struct V_43 V_44 ;
struct V_14 * V_15 ;
unsigned int V_27 ;
if ( ! F_11 ( V_9 ) )
return 0 ;
V_44 . V_13 = V_40 ;
V_44 . V_41 = V_41 ;
V_44 . V_42 = V_42 ;
V_15 = V_9 -> V_45 ;
F_20 ( V_34 , & V_44 , sizeof( V_44 ) ) ;
if ( F_21 ( V_15 , V_34 , 1 , 0 , & V_44 , V_36 ) >= 0 ) {
F_22 ( V_15 ) ;
while ( ! F_18 ( V_15 , & V_27 ) )
F_27 () ;
}
return 0 ;
}
static T_4 F_28 ( struct V_1 * V_1 , unsigned int V_41 ,
unsigned int V_42 )
{
if ( V_1 -> V_9 )
return F_26 ( V_1 -> V_9 , V_1 -> V_13 , V_41 , V_42 ) ;
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
V_1 -> V_46 = false ;
}
}
static T_4 F_30 ( struct V_1 * V_1 , void * V_47 , T_3 V_48 ,
bool V_49 )
{
struct V_33 V_34 [ 1 ] ;
struct V_14 * V_17 ;
T_4 V_35 ;
unsigned long V_5 ;
unsigned int V_27 ;
V_17 = V_1 -> V_17 ;
F_2 ( & V_1 -> V_50 , V_5 ) ;
F_29 ( V_1 ) ;
F_20 ( V_34 , V_47 , V_48 ) ;
V_35 = F_21 ( V_17 , V_34 , 1 , 0 , V_47 , V_36 ) ;
F_22 ( V_17 ) ;
if ( V_35 < 0 ) {
V_48 = 0 ;
goto V_51;
}
if ( V_35 == 0 )
V_1 -> V_46 = true ;
if ( V_49 )
goto V_51;
while ( ! F_18 ( V_17 , & V_27 ) )
F_27 () ;
V_51:
F_5 ( & V_1 -> V_50 , V_5 ) ;
V_1 -> V_31 . V_52 += V_48 ;
return V_48 ;
}
static T_4 F_31 ( struct V_1 * V_1 , char * V_53 , T_3 V_54 ,
bool V_55 )
{
struct V_22 * V_23 ;
unsigned long V_5 ;
if ( ! V_54 || ! F_25 ( V_1 ) )
return 0 ;
V_23 = V_1 -> V_30 ;
V_54 = F_32 ( V_54 , V_23 -> V_27 - V_23 -> V_28 ) ;
if ( V_55 ) {
T_4 V_35 ;
V_35 = F_33 ( V_53 , V_23 -> V_23 + V_23 -> V_28 , V_54 ) ;
if ( V_35 )
return - V_56 ;
} else {
memcpy ( V_53 , V_23 -> V_23 + V_23 -> V_28 , V_54 ) ;
}
V_23 -> V_28 += V_54 ;
if ( V_23 -> V_28 == V_23 -> V_27 ) {
F_2 ( & V_1 -> V_39 , V_5 ) ;
V_1 -> V_30 = NULL ;
if ( F_19 ( V_1 -> V_16 , V_23 ) < 0 )
F_24 ( V_1 -> V_10 , L_2 ) ;
F_5 ( & V_1 -> V_39 , V_5 ) ;
}
return V_54 ;
}
static bool F_34 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_57 ) {
return false ;
}
return ! F_25 ( V_1 ) && V_1 -> V_58 ;
}
static bool F_35 ( struct V_1 * V_1 )
{
bool V_35 ;
if ( ! V_1 -> V_57 ) {
return false ;
}
if ( ! V_1 -> V_58 )
return true ;
F_36 ( & V_1 -> V_50 ) ;
F_29 ( V_1 ) ;
V_35 = V_1 -> V_46 ;
F_37 ( & V_1 -> V_50 ) ;
return V_35 ;
}
static T_4 F_38 ( struct V_59 * V_60 , char T_5 * V_61 ,
T_3 V_62 , T_6 * V_63 )
{
struct V_1 * V_1 ;
T_4 V_35 ;
V_1 = V_60 -> V_64 ;
if ( ! F_25 ( V_1 ) ) {
if ( ! V_1 -> V_58 )
return 0 ;
if ( V_60 -> V_65 & V_66 )
return - V_67 ;
V_35 = F_39 ( V_1 -> V_68 ,
! F_34 ( V_1 ) ) ;
if ( V_35 < 0 )
return V_35 ;
}
if ( ! V_1 -> V_57 )
return - V_69 ;
if ( ! F_25 ( V_1 ) && ! V_1 -> V_58 )
return 0 ;
return F_31 ( V_1 , V_61 , V_62 , true ) ;
}
static T_4 F_40 ( struct V_59 * V_60 , const char T_5 * V_61 ,
T_3 V_62 , T_6 * V_63 )
{
struct V_1 * V_1 ;
char * V_23 ;
T_4 V_35 ;
bool V_49 ;
if ( ! V_62 )
return 0 ;
V_1 = V_60 -> V_64 ;
V_49 = V_60 -> V_65 & V_66 ;
if ( F_35 ( V_1 ) ) {
if ( V_49 )
return - V_67 ;
V_35 = F_39 ( V_1 -> V_68 ,
! F_35 ( V_1 ) ) ;
if ( V_35 < 0 )
return V_35 ;
}
if ( ! V_1 -> V_57 )
return - V_69 ;
V_62 = F_32 ( ( T_3 ) ( 32 * 1024 ) , V_62 ) ;
V_23 = F_15 ( V_62 , V_25 ) ;
if ( ! V_23 )
return - V_70 ;
V_35 = F_41 ( V_23 , V_61 , V_62 ) ;
if ( V_35 ) {
V_35 = - V_56 ;
goto F_12;
}
V_49 = true ;
V_35 = F_30 ( V_1 , V_23 , V_62 , V_49 ) ;
if ( V_49 && V_35 > 0 )
goto V_7;
F_12:
F_13 ( V_23 ) ;
V_7:
return V_35 ;
}
static unsigned int F_42 ( struct V_59 * V_60 , T_7 * V_71 )
{
struct V_1 * V_1 ;
unsigned int V_35 ;
V_1 = V_60 -> V_64 ;
F_43 ( V_60 , & V_1 -> V_68 , V_71 ) ;
if ( ! V_1 -> V_57 ) {
return V_72 ;
}
V_35 = 0 ;
if ( ! F_34 ( V_1 ) )
V_35 |= V_73 | V_74 ;
if ( ! F_35 ( V_1 ) )
V_35 |= V_75 ;
if ( ! V_1 -> V_58 )
V_35 |= V_72 ;
return V_35 ;
}
static int F_44 ( struct V_76 * V_76 , struct V_59 * V_60 )
{
struct V_1 * V_1 ;
V_1 = V_60 -> V_64 ;
F_28 ( V_1 , V_77 , 0 ) ;
F_36 ( & V_1 -> V_39 ) ;
V_1 -> V_57 = false ;
F_23 ( V_1 ) ;
F_37 ( & V_1 -> V_39 ) ;
F_36 ( & V_1 -> V_50 ) ;
F_29 ( V_1 ) ;
F_37 ( & V_1 -> V_50 ) ;
F_45 ( & V_1 -> V_78 , V_79 ) ;
return 0 ;
}
static int F_46 ( struct V_76 * V_76 , struct V_59 * V_60 )
{
struct V_12 * V_12 = V_76 -> V_80 ;
struct V_1 * V_1 ;
int V_35 ;
V_1 = F_7 ( V_12 -> V_10 ) ;
V_60 -> V_64 = V_1 ;
F_36 ( & V_1 -> V_9 -> V_11 ) ;
F_47 ( & V_1 -> V_78 ) ;
F_37 ( & V_1 -> V_9 -> V_11 ) ;
if ( F_10 ( V_1 ) ) {
V_35 = - V_81 ;
goto V_7;
}
F_36 ( & V_1 -> V_39 ) ;
if ( V_1 -> V_57 ) {
F_37 ( & V_1 -> V_39 ) ;
V_35 = - V_82 ;
goto V_7;
}
V_1 -> V_57 = true ;
F_37 ( & V_1 -> V_39 ) ;
F_36 ( & V_1 -> V_50 ) ;
F_29 ( V_1 ) ;
F_37 ( & V_1 -> V_50 ) ;
F_48 ( V_76 , V_60 ) ;
F_28 ( V_60 -> V_64 , V_77 , 1 ) ;
return 0 ;
V_7:
F_45 ( & V_1 -> V_78 , V_79 ) ;
return V_35 ;
}
static int F_49 ( int V_83 , struct V_59 * V_60 , int V_84 )
{
struct V_1 * V_1 ;
V_1 = V_60 -> V_64 ;
return F_50 ( V_83 , V_60 , V_84 , & V_1 -> V_85 ) ;
}
static int F_51 ( T_1 V_2 , const char * V_23 , int V_62 )
{
struct V_1 * V_1 ;
if ( F_52 ( V_86 ) )
return V_86 ( V_2 , V_23 , V_62 ) ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_87 ;
return F_30 ( V_1 , ( void * ) V_23 , V_62 , false ) ;
}
static int F_53 ( T_1 V_2 , char * V_23 , int V_62 )
{
struct V_1 * V_1 ;
if ( F_52 ( V_86 ) )
return 0 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_87 ;
F_54 ( ! V_1 -> V_16 ) ;
return F_31 ( V_1 , V_23 , V_62 , false ) ;
}
static void F_55 ( struct V_1 * V_1 )
{
struct V_88 * V_19 ;
if ( ! V_1 || ! F_10 ( V_1 ) )
return;
V_19 = V_1 -> V_9 -> V_19 ;
if ( F_56 ( V_19 , V_89 ) )
F_57 ( V_1 -> V_4 . V_18 , V_1 -> V_4 . V_90 ) ;
}
static int F_58 ( struct V_91 * V_92 , int V_93 )
{
struct V_1 * V_1 ;
V_1 = F_1 ( V_92 -> V_2 ) ;
if ( ! V_1 )
return - V_94 ;
V_92 -> V_95 = 1 ;
F_55 ( V_1 ) ;
return 0 ;
}
static void F_59 ( struct V_91 * V_92 , int V_93 )
{
V_92 -> V_95 = 0 ;
}
int T_8 F_60 ( int (* F_51)( T_1 , const char * , int ) )
{
V_86 = F_51 ;
return F_61 ( 0 , 0 , & V_96 ) ;
}
int F_62 ( struct V_1 * V_1 )
{
int V_35 ;
V_1 -> V_4 . V_2 = V_97 . V_98 ;
V_1 -> V_4 . V_18 = F_63 ( V_1 -> V_4 . V_2 , 0 , & V_96 , V_99 ) ;
if ( F_64 ( V_1 -> V_4 . V_18 ) ) {
V_35 = F_65 ( V_1 -> V_4 . V_18 ) ;
F_66 ( V_1 -> V_10 ,
L_3 , V_35 ) ;
V_1 -> V_4 . V_18 = NULL ;
return V_35 ;
}
F_36 ( & V_6 ) ;
V_97 . V_98 ++ ;
F_67 ( & V_1 -> V_4 . V_100 , & V_97 . V_101 ) ;
F_37 ( & V_6 ) ;
V_1 -> V_57 = true ;
if ( V_86 )
V_86 = NULL ;
F_28 ( V_1 , V_77 , 1 ) ;
return 0 ;
}
static T_4 F_68 ( struct V_102 * V_10 ,
struct V_103 * V_104 , char * V_105 )
{
struct V_1 * V_1 ;
V_1 = F_69 ( V_10 ) ;
return sprintf ( V_105 , L_4 , V_1 -> V_106 ) ;
}
static T_4 F_70 ( struct V_59 * V_60 , char T_5 * V_61 ,
T_3 V_62 , T_6 * V_63 )
{
struct V_1 * V_1 ;
char * V_23 ;
T_4 V_35 , V_107 , V_54 ;
V_54 = 1024 ;
V_23 = F_15 ( V_54 , V_25 ) ;
if ( ! V_23 )
return - V_70 ;
V_1 = V_60 -> V_64 ;
V_107 = 0 ;
V_107 += snprintf ( V_23 + V_107 , V_54 ,
L_5 , V_1 -> V_106 ? V_1 -> V_106 : L_6 ) ;
V_107 += snprintf ( V_23 + V_107 , V_54 - V_107 ,
L_7 , V_1 -> V_57 ) ;
V_107 += snprintf ( V_23 + V_107 , V_54 - V_107 ,
L_8 , V_1 -> V_58 ) ;
V_107 += snprintf ( V_23 + V_107 , V_54 - V_107 ,
L_9 , V_1 -> V_46 ) ;
V_107 += snprintf ( V_23 + V_107 , V_54 - V_107 ,
L_10 , V_1 -> V_31 . V_52 ) ;
V_107 += snprintf ( V_23 + V_107 , V_54 - V_107 ,
L_11 ,
V_1 -> V_31 . V_32 ) ;
V_107 += snprintf ( V_23 + V_107 , V_54 - V_107 ,
L_12 ,
V_1 -> V_31 . V_38 ) ;
V_107 += snprintf ( V_23 + V_107 , V_54 - V_107 ,
L_13 ,
F_10 ( V_1 ) ? L_14 : L_15 ) ;
V_107 += snprintf ( V_23 + V_107 , V_54 - V_107 ,
L_16 , V_1 -> V_4 . V_2 ) ;
V_35 = F_71 ( V_61 , V_62 , V_63 , V_23 , V_107 ) ;
F_13 ( V_23 ) ;
return V_35 ;
}
static void F_72 ( struct V_1 * V_1 , T_9 V_108 , T_9 V_109 )
{
if ( ! V_1 || ! F_10 ( V_1 ) )
return;
V_1 -> V_4 . V_90 . V_110 = V_108 ;
V_1 -> V_4 . V_90 . V_111 = V_109 ;
}
static unsigned int F_73 ( struct V_14 * V_15 , T_10 * V_112 )
{
struct V_22 * V_23 ;
unsigned int V_113 ;
int V_35 ;
V_113 = 0 ;
do {
V_23 = F_14 ( V_99 ) ;
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
static void F_74 ( struct V_1 * V_1 )
{
if ( V_1 -> V_85 && V_1 -> V_57 )
F_75 ( & V_1 -> V_85 , V_114 , V_115 ) ;
}
static int F_76 ( struct V_8 * V_9 , T_1 V_13 )
{
char V_116 [ 16 ] ;
struct V_1 * V_1 ;
struct V_22 * V_23 ;
T_2 V_117 ;
unsigned int V_113 ;
int V_37 ;
V_1 = F_15 ( sizeof( * V_1 ) , V_25 ) ;
if ( ! V_1 ) {
V_37 = - V_70 ;
goto V_26;
}
F_77 ( & V_1 -> V_78 ) ;
V_1 -> V_9 = V_9 ;
V_1 -> V_13 = V_13 ;
V_1 -> V_106 = NULL ;
V_1 -> V_30 = NULL ;
V_1 -> V_4 . V_18 = NULL ;
V_1 -> V_85 = NULL ;
V_1 -> V_4 . V_90 . V_110 = V_1 -> V_4 . V_90 . V_111 = 0 ;
V_1 -> V_58 = V_1 -> V_57 = false ;
V_1 -> V_31 = (struct V_118 ) { 0 } ;
V_1 -> V_46 = false ;
V_1 -> V_16 = V_9 -> V_119 [ V_1 -> V_13 ] ;
V_1 -> V_17 = V_9 -> V_120 [ V_1 -> V_13 ] ;
V_1 -> V_12 = F_78 () ;
if ( ! V_1 -> V_12 ) {
F_66 ( & V_1 -> V_9 -> V_19 -> V_10 , L_17 ) ;
V_37 = - V_70 ;
goto V_121;
}
V_1 -> V_12 -> V_122 = & V_123 ;
V_117 = F_79 ( V_9 -> V_124 , V_13 ) ;
V_37 = F_80 ( V_1 -> V_12 , V_117 , 1 ) ;
if ( V_37 < 0 ) {
F_66 ( & V_1 -> V_9 -> V_19 -> V_10 ,
L_18 , V_37 , V_13 ) ;
goto V_125;
}
V_1 -> V_10 = F_81 ( V_97 . V_126 , & V_1 -> V_9 -> V_19 -> V_10 ,
V_117 , V_1 , L_19 ,
V_1 -> V_9 -> V_127 , V_13 ) ;
if ( F_64 ( V_1 -> V_10 ) ) {
V_37 = F_65 ( V_1 -> V_10 ) ;
F_66 ( & V_1 -> V_9 -> V_19 -> V_10 ,
L_20 ,
V_37 , V_13 ) ;
goto V_125;
}
F_82 ( & V_1 -> V_39 ) ;
F_82 ( & V_1 -> V_50 ) ;
F_83 ( & V_1 -> V_68 ) ;
V_113 = F_73 ( V_1 -> V_16 , & V_1 -> V_39 ) ;
if ( ! V_113 ) {
F_66 ( V_1 -> V_10 , L_21 ) ;
V_37 = - V_70 ;
goto V_128;
}
if ( ! F_11 ( V_1 -> V_9 ) ) {
V_37 = F_62 ( V_1 ) ;
if ( V_37 )
goto V_129;
}
F_36 ( & V_9 -> V_11 ) ;
F_67 ( & V_1 -> V_100 , & V_1 -> V_9 -> V_130 ) ;
F_37 ( & V_9 -> V_11 ) ;
F_28 ( V_1 , V_131 , 1 ) ;
if ( V_97 . V_132 ) {
sprintf ( V_116 , L_19 ,
V_1 -> V_9 -> V_127 , V_13 ) ;
V_1 -> V_133 = F_84 ( V_116 , 0444 ,
V_97 . V_132 ,
V_1 ,
& V_134 ) ;
}
return 0 ;
V_129:
while ( ( V_23 = F_85 ( V_1 -> V_16 ) ) )
F_12 ( V_23 ) ;
V_128:
F_86 ( V_97 . V_126 , V_1 -> V_10 -> V_117 ) ;
V_125:
F_87 ( V_1 -> V_12 ) ;
V_121:
F_13 ( V_1 ) ;
V_26:
F_26 ( V_9 , V_13 , V_131 , 0 ) ;
return V_37 ;
}
static void V_79 ( struct V_78 * V_78 )
{
struct V_1 * V_1 ;
V_1 = F_4 ( V_78 , struct V_1 , V_78 ) ;
F_88 ( & V_1 -> V_10 -> V_135 , & V_136 ) ;
F_86 ( V_97 . V_126 , V_1 -> V_10 -> V_117 ) ;
F_87 ( V_1 -> V_12 ) ;
F_13 ( V_1 -> V_106 ) ;
F_89 ( V_1 -> V_133 ) ;
F_13 ( V_1 ) ;
}
static void F_90 ( struct V_1 * V_1 )
{
struct V_22 * V_23 ;
F_23 ( V_1 ) ;
F_29 ( V_1 ) ;
while ( ( V_23 = F_85 ( V_1 -> V_16 ) ) )
F_12 ( V_23 ) ;
}
static void F_91 ( struct V_1 * V_1 )
{
F_36 ( & V_1 -> V_9 -> V_11 ) ;
F_92 ( & V_1 -> V_100 ) ;
F_37 ( & V_1 -> V_9 -> V_11 ) ;
if ( V_1 -> V_57 ) {
V_1 -> V_57 = false ;
V_1 -> V_58 = false ;
F_93 ( & V_1 -> V_68 ) ;
F_74 ( V_1 ) ;
}
if ( F_10 ( V_1 ) ) {
F_36 ( & V_6 ) ;
F_92 ( & V_1 -> V_4 . V_100 ) ;
F_37 ( & V_6 ) ;
F_94 ( V_1 -> V_4 . V_18 ) ;
}
F_90 ( V_1 ) ;
V_1 -> V_9 = NULL ;
F_45 ( & V_1 -> V_78 , V_79 ) ;
}
static void F_95 ( struct V_8 * V_9 ,
struct V_22 * V_23 )
{
struct V_43 * V_44 ;
struct V_1 * V_1 ;
T_3 V_137 ;
int V_37 ;
V_44 = (struct V_43 * ) ( V_23 -> V_23 + V_23 -> V_28 ) ;
V_1 = F_8 ( V_9 , V_44 -> V_13 ) ;
if ( ! V_1 && V_44 -> V_41 != V_138 ) {
F_96 ( & V_9 -> V_19 -> V_10 ,
L_22 , V_44 -> V_13 ) ;
return;
}
switch ( V_44 -> V_41 ) {
case V_138 :
if ( V_1 ) {
F_96 ( & V_9 -> V_19 -> V_10 ,
L_23 , V_1 -> V_13 ) ;
F_28 ( V_1 , V_131 , 1 ) ;
break;
}
if ( V_44 -> V_13 >= V_9 -> V_139 . V_140 ) {
F_24 ( & V_9 -> V_19 -> V_10 ,
L_24 ,
V_44 -> V_13 , V_9 -> V_139 . V_140 - 1 ) ;
break;
}
F_76 ( V_9 , V_44 -> V_13 ) ;
break;
case V_141 :
F_91 ( V_1 ) ;
break;
case V_142 :
if ( ! V_44 -> V_42 )
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
memcpy ( & V_29 , V_23 -> V_23 + V_23 -> V_28 + sizeof( * V_44 ) ,
sizeof( V_29 ) ) ;
F_72 ( V_1 , V_29 . V_108 , V_29 . V_109 ) ;
V_1 -> V_4 . V_18 -> V_95 = 1 ;
F_55 ( V_1 ) ;
break;
}
case V_77 :
V_1 -> V_58 = V_44 -> V_42 ;
F_93 ( & V_1 -> V_68 ) ;
F_36 ( & V_1 -> V_50 ) ;
F_29 ( V_1 ) ;
F_37 ( & V_1 -> V_50 ) ;
F_74 ( V_1 ) ;
break;
case V_145 :
if ( V_1 -> V_106 )
break;
V_137 = V_23 -> V_27 - V_23 -> V_28 - sizeof( * V_44 ) + 1 ;
V_1 -> V_106 = F_15 ( V_137 , V_25 ) ;
if ( ! V_1 -> V_106 ) {
F_66 ( V_1 -> V_10 ,
L_25 ) ;
break;
}
strncpy ( V_1 -> V_106 , V_23 -> V_23 + V_23 -> V_28 + sizeof( * V_44 ) ,
V_137 - 1 ) ;
V_1 -> V_106 [ V_137 - 1 ] = 0 ;
V_37 = F_98 ( & V_1 -> V_10 -> V_135 ,
& V_136 ) ;
if ( V_37 ) {
F_66 ( V_1 -> V_10 ,
L_26 ,
V_37 ) ;
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
F_93 ( & V_1 -> V_68 ) ;
}
static void F_104 ( struct V_14 * V_15 )
{
struct V_1 * V_1 ;
unsigned long V_5 ;
V_1 = F_9 ( V_15 -> V_19 -> V_152 , V_15 ) ;
if ( ! V_1 )
return;
F_2 ( & V_1 -> V_39 , V_5 ) ;
V_1 -> V_30 = F_17 ( V_1 ) ;
if ( ! V_1 -> V_57 )
F_23 ( V_1 ) ;
F_5 ( & V_1 -> V_39 , V_5 ) ;
F_93 ( & V_1 -> V_68 ) ;
F_74 ( V_1 ) ;
if ( F_10 ( V_1 ) && F_105 ( V_1 -> V_4 . V_18 ) )
F_106 () ;
}
static void F_107 ( struct V_14 * V_15 )
{
struct V_8 * V_9 ;
V_9 = V_15 -> V_19 -> V_152 ;
F_108 ( & V_9 -> V_149 ) ;
}
static void F_109 ( struct V_88 * V_19 )
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
F_72 ( V_1 , V_108 , V_109 ) ;
F_55 ( V_1 ) ;
}
}
static int F_111 ( struct V_8 * V_9 )
{
T_12 * * V_155 ;
char * * V_156 ;
struct V_14 * * V_157 ;
T_1 V_158 , V_159 , V_160 , V_161 ;
int V_37 ;
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
V_37 = - V_70 ;
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
V_37 = V_9 -> V_19 -> V_139 -> V_162 ( V_9 -> V_19 , V_161 , V_157 ,
V_155 ,
( const char * * ) V_156 ) ;
if ( V_37 )
goto free;
V_159 = 0 ;
V_9 -> V_119 [ 0 ] = V_157 [ 0 ] ;
V_9 -> V_120 [ 0 ] = V_157 [ 1 ] ;
V_159 += 2 ;
if ( F_11 ( V_9 ) ) {
V_9 -> V_150 = V_157 [ V_159 ] ;
V_9 -> V_45 = V_157 [ V_159 + 1 ] ;
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
return V_37 ;
}
static void F_112 ( struct V_8 * V_9 )
{
V_9 -> V_19 -> V_139 -> V_163 ( V_9 -> V_19 ) ;
F_13 ( V_9 -> V_119 ) ;
F_13 ( V_9 -> V_120 ) ;
}
static void F_113 ( struct V_8 * V_9 )
{
struct V_22 * V_23 ;
unsigned int V_27 ;
if ( ! F_11 ( V_9 ) )
return;
while ( ( V_23 = F_18 ( V_9 -> V_150 , & V_27 ) ) )
F_12 ( V_23 ) ;
while ( ( V_23 = F_85 ( V_9 -> V_150 ) ) )
F_12 ( V_23 ) ;
}
static int T_13 F_114 ( struct V_88 * V_19 )
{
struct V_8 * V_9 ;
int V_37 ;
bool V_164 ;
bool V_165 = V_86 != NULL ;
F_115 () ;
V_9 = F_15 ( sizeof( * V_9 ) , V_25 ) ;
if ( ! V_9 ) {
V_37 = - V_70 ;
goto V_26;
}
V_9 -> V_19 = V_19 ;
V_19 -> V_152 = V_9 ;
F_36 ( & V_6 ) ;
V_9 -> V_127 = V_97 . V_166 ++ ;
F_37 ( & V_6 ) ;
V_9 -> V_124 = F_116 ( 0 , L_32 ,
& V_167 ) ;
if ( V_9 -> V_124 < 0 ) {
F_66 ( & V_19 -> V_10 ,
L_33 ,
V_9 -> V_124 , V_9 -> V_127 ) ;
V_37 = V_9 -> V_124 ;
goto free;
}
V_164 = false ;
V_9 -> V_139 . V_140 = 1 ;
if ( F_117 ( V_19 , V_21 ,
F_110 ( struct V_154 ,
V_140 ) ,
& V_9 -> V_139 . V_140 ) == 0 )
V_164 = true ;
V_37 = F_111 ( V_9 ) ;
if ( V_37 < 0 ) {
F_66 ( & V_19 -> V_10 , L_34 , V_37 ) ;
goto V_168;
}
F_82 ( & V_9 -> V_11 ) ;
F_118 ( & V_9 -> V_130 ) ;
if ( V_164 ) {
unsigned int V_113 ;
F_82 ( & V_9 -> V_151 ) ;
F_119 ( & V_9 -> V_149 , & F_100 ) ;
V_113 = F_73 ( V_9 -> V_150 , & V_9 -> V_151 ) ;
if ( ! V_113 ) {
F_66 ( & V_19 -> V_10 ,
L_35 ) ;
V_37 = - V_70 ;
goto V_169;
}
} else {
F_76 ( V_9 , 0 ) ;
}
F_36 ( & V_6 ) ;
F_67 ( & V_9 -> V_100 , & V_97 . V_170 ) ;
F_37 ( & V_6 ) ;
F_26 ( V_9 , V_171 ,
V_172 , 1 ) ;
if ( V_164 && V_165 )
F_120 ( & V_143 ) ;
return 0 ;
V_169:
F_26 ( V_9 , V_171 ,
V_172 , 0 ) ;
F_112 ( V_9 ) ;
V_168:
F_121 ( V_9 -> V_124 , L_32 ) ;
free:
F_13 ( V_9 ) ;
V_26:
return V_37 ;
}
static void F_122 ( struct V_88 * V_19 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 , * V_173 ;
V_9 = V_19 -> V_152 ;
F_36 ( & V_6 ) ;
F_92 ( & V_9 -> V_100 ) ;
F_37 ( & V_6 ) ;
V_19 -> V_139 -> V_174 ( V_19 ) ;
F_123 ( & V_9 -> V_149 ) ;
F_124 (port, port2, &portdev->ports, list)
F_91 ( V_1 ) ;
F_121 ( V_9 -> V_124 , L_32 ) ;
F_113 ( V_9 ) ;
F_112 ( V_9 ) ;
F_13 ( V_9 ) ;
}
static int F_125 ( struct V_88 * V_19 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
V_9 = V_19 -> V_152 ;
V_19 -> V_139 -> V_174 ( V_19 ) ;
F_126 ( V_9 -> V_150 ) ;
F_123 ( & V_9 -> V_149 ) ;
F_126 ( V_9 -> V_150 ) ;
F_113 ( V_9 ) ;
F_3 (port, &portdev->ports, list) {
F_126 ( V_1 -> V_16 ) ;
F_126 ( V_1 -> V_17 ) ;
V_1 -> V_58 = false ;
F_90 ( V_1 ) ;
}
F_112 ( V_9 ) ;
return 0 ;
}
static int F_127 ( struct V_88 * V_19 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
int V_35 ;
V_9 = V_19 -> V_152 ;
V_35 = F_111 ( V_9 ) ;
if ( V_35 )
return V_35 ;
if ( F_11 ( V_9 ) )
F_73 ( V_9 -> V_150 , & V_9 -> V_151 ) ;
F_3 (port, &portdev->ports, list) {
V_1 -> V_16 = V_9 -> V_119 [ V_1 -> V_13 ] ;
V_1 -> V_17 = V_9 -> V_120 [ V_1 -> V_13 ] ;
F_73 ( V_1 -> V_16 , & V_1 -> V_39 ) ;
F_28 ( V_1 , V_131 , 1 ) ;
if ( V_1 -> V_57 )
F_28 ( V_1 , V_77 , 1 ) ;
}
return 0 ;
}
static int T_8 F_128 ( void )
{
int V_37 ;
V_97 . V_126 = F_129 ( V_175 , L_36 ) ;
if ( F_64 ( V_97 . V_126 ) ) {
V_37 = F_65 ( V_97 . V_126 ) ;
F_130 ( L_37 , V_37 ) ;
return V_37 ;
}
V_97 . V_132 = F_131 ( L_36 , NULL ) ;
if ( ! V_97 . V_132 ) {
F_132 ( L_38 ,
F_65 ( V_97 . V_132 ) ) ;
}
F_118 ( & V_97 . V_101 ) ;
F_118 ( & V_97 . V_170 ) ;
return F_133 ( & V_176 ) ;
}
static void T_14 F_134 ( void )
{
F_135 ( & V_176 ) ;
F_136 ( V_97 . V_126 ) ;
if ( V_97 . V_132 )
F_137 ( V_97 . V_132 ) ;
}
