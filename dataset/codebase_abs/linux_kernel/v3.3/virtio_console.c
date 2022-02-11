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
static int F_70 ( struct V_76 * V_76 , struct V_59 * V_60 )
{
V_60 -> V_64 = V_76 -> V_107 ;
return 0 ;
}
static T_4 F_71 ( struct V_59 * V_60 , char T_5 * V_61 ,
T_3 V_62 , T_6 * V_63 )
{
struct V_1 * V_1 ;
char * V_23 ;
T_4 V_35 , V_108 , V_54 ;
V_54 = 1024 ;
V_23 = F_15 ( V_54 , V_25 ) ;
if ( ! V_23 )
return - V_70 ;
V_1 = V_60 -> V_64 ;
V_108 = 0 ;
V_108 += snprintf ( V_23 + V_108 , V_54 ,
L_5 , V_1 -> V_106 ? V_1 -> V_106 : L_6 ) ;
V_108 += snprintf ( V_23 + V_108 , V_54 - V_108 ,
L_7 , V_1 -> V_57 ) ;
V_108 += snprintf ( V_23 + V_108 , V_54 - V_108 ,
L_8 , V_1 -> V_58 ) ;
V_108 += snprintf ( V_23 + V_108 , V_54 - V_108 ,
L_9 , V_1 -> V_46 ) ;
V_108 += snprintf ( V_23 + V_108 , V_54 - V_108 ,
L_10 , V_1 -> V_31 . V_52 ) ;
V_108 += snprintf ( V_23 + V_108 , V_54 - V_108 ,
L_11 ,
V_1 -> V_31 . V_32 ) ;
V_108 += snprintf ( V_23 + V_108 , V_54 - V_108 ,
L_12 ,
V_1 -> V_31 . V_38 ) ;
V_108 += snprintf ( V_23 + V_108 , V_54 - V_108 ,
L_13 ,
F_10 ( V_1 ) ? L_14 : L_15 ) ;
V_108 += snprintf ( V_23 + V_108 , V_54 - V_108 ,
L_16 , V_1 -> V_4 . V_2 ) ;
V_35 = F_72 ( V_61 , V_62 , V_63 , V_23 , V_108 ) ;
F_13 ( V_23 ) ;
return V_35 ;
}
static void F_73 ( struct V_1 * V_1 , T_9 V_109 , T_9 V_110 )
{
if ( ! V_1 || ! F_10 ( V_1 ) )
return;
V_1 -> V_4 . V_90 . V_111 = V_109 ;
V_1 -> V_4 . V_90 . V_112 = V_110 ;
}
static unsigned int F_74 ( struct V_14 * V_15 , T_10 * V_113 )
{
struct V_22 * V_23 ;
unsigned int V_114 ;
int V_35 ;
V_114 = 0 ;
do {
V_23 = F_14 ( V_99 ) ;
if ( ! V_23 )
break;
F_36 ( V_113 ) ;
V_35 = F_19 ( V_15 , V_23 ) ;
if ( V_35 < 0 ) {
F_37 ( V_113 ) ;
F_12 ( V_23 ) ;
break;
}
V_114 ++ ;
F_37 ( V_113 ) ;
} while ( V_35 > 0 );
return V_114 ;
}
static void F_75 ( struct V_1 * V_1 )
{
if ( V_1 -> V_85 && V_1 -> V_57 )
F_76 ( & V_1 -> V_85 , V_115 , V_116 ) ;
}
static int F_77 ( struct V_8 * V_9 , T_1 V_13 )
{
char V_117 [ 16 ] ;
struct V_1 * V_1 ;
struct V_22 * V_23 ;
T_2 V_118 ;
unsigned int V_114 ;
int V_37 ;
V_1 = F_15 ( sizeof( * V_1 ) , V_25 ) ;
if ( ! V_1 ) {
V_37 = - V_70 ;
goto V_26;
}
F_78 ( & V_1 -> V_78 ) ;
V_1 -> V_9 = V_9 ;
V_1 -> V_13 = V_13 ;
V_1 -> V_106 = NULL ;
V_1 -> V_30 = NULL ;
V_1 -> V_4 . V_18 = NULL ;
V_1 -> V_85 = NULL ;
V_1 -> V_4 . V_90 . V_111 = V_1 -> V_4 . V_90 . V_112 = 0 ;
V_1 -> V_58 = V_1 -> V_57 = false ;
V_1 -> V_31 = (struct V_119 ) { 0 } ;
V_1 -> V_46 = false ;
V_1 -> V_16 = V_9 -> V_120 [ V_1 -> V_13 ] ;
V_1 -> V_17 = V_9 -> V_121 [ V_1 -> V_13 ] ;
V_1 -> V_12 = F_79 () ;
if ( ! V_1 -> V_12 ) {
F_66 ( & V_1 -> V_9 -> V_19 -> V_10 , L_17 ) ;
V_37 = - V_70 ;
goto V_122;
}
V_1 -> V_12 -> V_123 = & V_124 ;
V_118 = F_80 ( V_9 -> V_125 , V_13 ) ;
V_37 = F_81 ( V_1 -> V_12 , V_118 , 1 ) ;
if ( V_37 < 0 ) {
F_66 ( & V_1 -> V_9 -> V_19 -> V_10 ,
L_18 , V_37 , V_13 ) ;
goto V_126;
}
V_1 -> V_10 = F_82 ( V_97 . V_127 , & V_1 -> V_9 -> V_19 -> V_10 ,
V_118 , V_1 , L_19 ,
V_1 -> V_9 -> V_128 , V_13 ) ;
if ( F_64 ( V_1 -> V_10 ) ) {
V_37 = F_65 ( V_1 -> V_10 ) ;
F_66 ( & V_1 -> V_9 -> V_19 -> V_10 ,
L_20 ,
V_37 , V_13 ) ;
goto V_126;
}
F_83 ( & V_1 -> V_39 ) ;
F_83 ( & V_1 -> V_50 ) ;
F_84 ( & V_1 -> V_68 ) ;
V_114 = F_74 ( V_1 -> V_16 , & V_1 -> V_39 ) ;
if ( ! V_114 ) {
F_66 ( V_1 -> V_10 , L_21 ) ;
V_37 = - V_70 ;
goto V_129;
}
if ( ! F_11 ( V_1 -> V_9 ) ) {
V_37 = F_62 ( V_1 ) ;
if ( V_37 )
goto V_130;
}
F_36 ( & V_9 -> V_11 ) ;
F_67 ( & V_1 -> V_100 , & V_1 -> V_9 -> V_131 ) ;
F_37 ( & V_9 -> V_11 ) ;
F_28 ( V_1 , V_132 , 1 ) ;
if ( V_97 . V_133 ) {
sprintf ( V_117 , L_19 ,
V_1 -> V_9 -> V_128 , V_13 ) ;
V_1 -> V_134 = F_85 ( V_117 , 0444 ,
V_97 . V_133 ,
V_1 ,
& V_135 ) ;
}
return 0 ;
V_130:
while ( ( V_23 = F_86 ( V_1 -> V_16 ) ) )
F_12 ( V_23 ) ;
V_129:
F_87 ( V_97 . V_127 , V_1 -> V_10 -> V_118 ) ;
V_126:
F_88 ( V_1 -> V_12 ) ;
V_122:
F_13 ( V_1 ) ;
V_26:
F_26 ( V_9 , V_13 , V_132 , 0 ) ;
return V_37 ;
}
static void V_79 ( struct V_78 * V_78 )
{
struct V_1 * V_1 ;
V_1 = F_4 ( V_78 , struct V_1 , V_78 ) ;
F_89 ( & V_1 -> V_10 -> V_136 , & V_137 ) ;
F_87 ( V_97 . V_127 , V_1 -> V_10 -> V_118 ) ;
F_88 ( V_1 -> V_12 ) ;
F_13 ( V_1 -> V_106 ) ;
F_90 ( V_1 -> V_134 ) ;
F_13 ( V_1 ) ;
}
static void F_91 ( struct V_1 * V_1 )
{
struct V_22 * V_23 ;
F_23 ( V_1 ) ;
F_29 ( V_1 ) ;
while ( ( V_23 = F_86 ( V_1 -> V_16 ) ) )
F_12 ( V_23 ) ;
}
static void F_92 ( struct V_1 * V_1 )
{
F_36 ( & V_1 -> V_9 -> V_11 ) ;
F_93 ( & V_1 -> V_100 ) ;
F_37 ( & V_1 -> V_9 -> V_11 ) ;
if ( V_1 -> V_57 ) {
V_1 -> V_57 = false ;
V_1 -> V_58 = false ;
F_94 ( & V_1 -> V_68 ) ;
F_75 ( V_1 ) ;
}
if ( F_10 ( V_1 ) ) {
F_36 ( & V_6 ) ;
F_93 ( & V_1 -> V_4 . V_100 ) ;
F_37 ( & V_6 ) ;
F_95 ( V_1 -> V_4 . V_18 ) ;
}
F_91 ( V_1 ) ;
V_1 -> V_9 = NULL ;
F_45 ( & V_1 -> V_78 , V_79 ) ;
}
static void F_96 ( struct V_8 * V_9 ,
struct V_22 * V_23 )
{
struct V_43 * V_44 ;
struct V_1 * V_1 ;
T_3 V_138 ;
int V_37 ;
V_44 = (struct V_43 * ) ( V_23 -> V_23 + V_23 -> V_28 ) ;
V_1 = F_8 ( V_9 , V_44 -> V_13 ) ;
if ( ! V_1 && V_44 -> V_41 != V_139 ) {
F_97 ( & V_9 -> V_19 -> V_10 ,
L_22 , V_44 -> V_13 ) ;
return;
}
switch ( V_44 -> V_41 ) {
case V_139 :
if ( V_1 ) {
F_97 ( & V_9 -> V_19 -> V_10 ,
L_23 , V_1 -> V_13 ) ;
F_28 ( V_1 , V_132 , 1 ) ;
break;
}
if ( V_44 -> V_13 >= V_9 -> V_140 . V_141 ) {
F_24 ( & V_9 -> V_19 -> V_10 ,
L_24 ,
V_44 -> V_13 , V_9 -> V_140 . V_141 - 1 ) ;
break;
}
F_77 ( V_9 , V_44 -> V_13 ) ;
break;
case V_142 :
F_92 ( V_1 ) ;
break;
case V_143 :
if ( ! V_44 -> V_42 )
break;
if ( F_10 ( V_1 ) )
break;
F_62 ( V_1 ) ;
F_98 ( & V_144 ) ;
break;
case V_145 : {
struct {
T_11 V_109 ;
T_11 V_110 ;
} V_29 ;
if ( ! F_10 ( V_1 ) )
break;
memcpy ( & V_29 , V_23 -> V_23 + V_23 -> V_28 + sizeof( * V_44 ) ,
sizeof( V_29 ) ) ;
F_73 ( V_1 , V_29 . V_109 , V_29 . V_110 ) ;
V_1 -> V_4 . V_18 -> V_95 = 1 ;
F_55 ( V_1 ) ;
break;
}
case V_77 :
V_1 -> V_58 = V_44 -> V_42 ;
F_94 ( & V_1 -> V_68 ) ;
F_36 ( & V_1 -> V_50 ) ;
F_29 ( V_1 ) ;
F_37 ( & V_1 -> V_50 ) ;
F_75 ( V_1 ) ;
break;
case V_146 :
if ( V_1 -> V_106 )
break;
V_138 = V_23 -> V_27 - V_23 -> V_28 - sizeof( * V_44 ) + 1 ;
V_1 -> V_106 = F_15 ( V_138 , V_25 ) ;
if ( ! V_1 -> V_106 ) {
F_66 ( V_1 -> V_10 ,
L_25 ) ;
break;
}
strncpy ( V_1 -> V_106 , V_23 -> V_23 + V_23 -> V_28 + sizeof( * V_44 ) ,
V_138 - 1 ) ;
V_1 -> V_106 [ V_138 - 1 ] = 0 ;
V_37 = F_99 ( & V_1 -> V_10 -> V_136 ,
& V_137 ) ;
if ( V_37 ) {
F_66 ( V_1 -> V_10 ,
L_26 ,
V_37 ) ;
} else {
F_100 ( & V_1 -> V_10 -> V_136 , V_147 ) ;
}
break;
}
}
static void F_101 ( struct V_148 * V_149 )
{
struct V_8 * V_9 ;
struct V_14 * V_15 ;
struct V_22 * V_23 ;
unsigned int V_27 ;
V_9 = F_4 ( V_149 , struct V_8 , V_150 ) ;
V_15 = V_9 -> V_151 ;
F_102 ( & V_9 -> V_152 ) ;
while ( ( V_23 = F_18 ( V_15 , & V_27 ) ) ) {
F_103 ( & V_9 -> V_152 ) ;
V_23 -> V_27 = V_27 ;
V_23 -> V_28 = 0 ;
F_96 ( V_9 , V_23 ) ;
F_102 ( & V_9 -> V_152 ) ;
if ( F_19 ( V_9 -> V_151 , V_23 ) < 0 ) {
F_24 ( & V_9 -> V_19 -> V_10 ,
L_27 ) ;
F_12 ( V_23 ) ;
}
}
F_103 ( & V_9 -> V_152 ) ;
}
static void F_104 ( struct V_14 * V_15 )
{
struct V_1 * V_1 ;
V_1 = F_9 ( V_15 -> V_19 -> V_153 , V_15 ) ;
if ( ! V_1 )
return;
F_94 ( & V_1 -> V_68 ) ;
}
static void F_105 ( struct V_14 * V_15 )
{
struct V_1 * V_1 ;
unsigned long V_5 ;
V_1 = F_9 ( V_15 -> V_19 -> V_153 , V_15 ) ;
if ( ! V_1 )
return;
F_2 ( & V_1 -> V_39 , V_5 ) ;
V_1 -> V_30 = F_17 ( V_1 ) ;
if ( ! V_1 -> V_57 )
F_23 ( V_1 ) ;
F_5 ( & V_1 -> V_39 , V_5 ) ;
F_94 ( & V_1 -> V_68 ) ;
F_75 ( V_1 ) ;
if ( F_10 ( V_1 ) && F_106 ( V_1 -> V_4 . V_18 ) )
F_107 () ;
}
static void F_108 ( struct V_14 * V_15 )
{
struct V_8 * V_9 ;
V_9 = V_15 -> V_19 -> V_153 ;
F_109 ( & V_9 -> V_150 ) ;
}
static void F_110 ( struct V_88 * V_19 )
{
struct V_8 * V_9 ;
V_9 = V_19 -> V_153 ;
if ( ! F_11 ( V_9 ) ) {
struct V_1 * V_1 ;
T_9 V_109 , V_110 ;
V_19 -> V_140 -> V_154 ( V_19 ,
F_111 ( struct V_155 , V_110 ) ,
& V_110 , sizeof( T_9 ) ) ;
V_19 -> V_140 -> V_154 ( V_19 ,
F_111 ( struct V_155 , V_109 ) ,
& V_109 , sizeof( T_9 ) ) ;
V_1 = F_8 ( V_9 , 0 ) ;
F_73 ( V_1 , V_109 , V_110 ) ;
F_55 ( V_1 ) ;
}
}
static int F_112 ( struct V_8 * V_9 )
{
T_12 * * V_156 ;
char * * V_157 ;
struct V_14 * * V_158 ;
T_1 V_159 , V_160 , V_161 , V_162 ;
int V_37 ;
V_161 = V_9 -> V_140 . V_141 ;
V_162 = F_11 ( V_9 ) ? ( V_161 + 1 ) * 2 : 2 ;
V_158 = F_15 ( V_162 * sizeof( struct V_14 * ) , V_25 ) ;
V_156 = F_15 ( V_162 * sizeof( T_12 * ) , V_25 ) ;
V_157 = F_15 ( V_162 * sizeof( char * ) , V_25 ) ;
V_9 -> V_120 = F_15 ( V_161 * sizeof( struct V_14 * ) ,
V_25 ) ;
V_9 -> V_121 = F_15 ( V_161 * sizeof( struct V_14 * ) ,
V_25 ) ;
if ( ! V_158 || ! V_156 || ! V_157 || ! V_9 -> V_120 ||
! V_9 -> V_121 ) {
V_37 = - V_70 ;
goto free;
}
V_160 = 0 ;
V_156 [ V_160 ] = F_105 ;
V_156 [ V_160 + 1 ] = F_104 ;
V_157 [ V_160 ] = L_28 ;
V_157 [ V_160 + 1 ] = L_29 ;
V_160 += 2 ;
if ( F_11 ( V_9 ) ) {
V_156 [ V_160 ] = F_108 ;
V_156 [ V_160 + 1 ] = NULL ;
V_157 [ V_160 ] = L_30 ;
V_157 [ V_160 + 1 ] = L_31 ;
for ( V_159 = 1 ; V_159 < V_161 ; V_159 ++ ) {
V_160 += 2 ;
V_156 [ V_160 ] = F_105 ;
V_156 [ V_160 + 1 ] = F_104 ;
V_157 [ V_160 ] = L_28 ;
V_157 [ V_160 + 1 ] = L_29 ;
}
}
V_37 = V_9 -> V_19 -> V_140 -> V_163 ( V_9 -> V_19 , V_162 , V_158 ,
V_156 ,
( const char * * ) V_157 ) ;
if ( V_37 )
goto free;
V_160 = 0 ;
V_9 -> V_120 [ 0 ] = V_158 [ 0 ] ;
V_9 -> V_121 [ 0 ] = V_158 [ 1 ] ;
V_160 += 2 ;
if ( F_11 ( V_9 ) ) {
V_9 -> V_151 = V_158 [ V_160 ] ;
V_9 -> V_45 = V_158 [ V_160 + 1 ] ;
for ( V_159 = 1 ; V_159 < V_161 ; V_159 ++ ) {
V_160 += 2 ;
V_9 -> V_120 [ V_159 ] = V_158 [ V_160 ] ;
V_9 -> V_121 [ V_159 ] = V_158 [ V_160 + 1 ] ;
}
}
F_13 ( V_157 ) ;
F_13 ( V_156 ) ;
F_13 ( V_158 ) ;
return 0 ;
free:
F_13 ( V_9 -> V_121 ) ;
F_13 ( V_9 -> V_120 ) ;
F_13 ( V_157 ) ;
F_13 ( V_156 ) ;
F_13 ( V_158 ) ;
return V_37 ;
}
static void F_113 ( struct V_8 * V_9 )
{
V_9 -> V_19 -> V_140 -> V_164 ( V_9 -> V_19 ) ;
F_13 ( V_9 -> V_120 ) ;
F_13 ( V_9 -> V_121 ) ;
}
static void F_114 ( struct V_8 * V_9 )
{
struct V_22 * V_23 ;
unsigned int V_27 ;
if ( ! F_11 ( V_9 ) )
return;
while ( ( V_23 = F_18 ( V_9 -> V_151 , & V_27 ) ) )
F_12 ( V_23 ) ;
while ( ( V_23 = F_86 ( V_9 -> V_151 ) ) )
F_12 ( V_23 ) ;
}
static int T_13 F_115 ( struct V_88 * V_19 )
{
struct V_8 * V_9 ;
int V_37 ;
bool V_165 ;
bool V_166 = V_86 != NULL ;
F_116 () ;
V_9 = F_15 ( sizeof( * V_9 ) , V_25 ) ;
if ( ! V_9 ) {
V_37 = - V_70 ;
goto V_26;
}
V_9 -> V_19 = V_19 ;
V_19 -> V_153 = V_9 ;
F_36 ( & V_6 ) ;
V_9 -> V_128 = V_97 . V_167 ++ ;
F_37 ( & V_6 ) ;
V_9 -> V_125 = F_117 ( 0 , L_32 ,
& V_168 ) ;
if ( V_9 -> V_125 < 0 ) {
F_66 ( & V_19 -> V_10 ,
L_33 ,
V_9 -> V_125 , V_9 -> V_128 ) ;
V_37 = V_9 -> V_125 ;
goto free;
}
V_165 = false ;
V_9 -> V_140 . V_141 = 1 ;
if ( F_118 ( V_19 , V_21 ,
F_111 ( struct V_155 ,
V_141 ) ,
& V_9 -> V_140 . V_141 ) == 0 )
V_165 = true ;
V_37 = F_112 ( V_9 ) ;
if ( V_37 < 0 ) {
F_66 ( & V_19 -> V_10 , L_34 , V_37 ) ;
goto V_169;
}
F_83 ( & V_9 -> V_11 ) ;
F_119 ( & V_9 -> V_131 ) ;
if ( V_165 ) {
unsigned int V_114 ;
F_83 ( & V_9 -> V_152 ) ;
F_120 ( & V_9 -> V_150 , & F_101 ) ;
V_114 = F_74 ( V_9 -> V_151 , & V_9 -> V_152 ) ;
if ( ! V_114 ) {
F_66 ( & V_19 -> V_10 ,
L_35 ) ;
V_37 = - V_70 ;
goto V_170;
}
} else {
F_77 ( V_9 , 0 ) ;
}
F_36 ( & V_6 ) ;
F_67 ( & V_9 -> V_100 , & V_97 . V_171 ) ;
F_37 ( & V_6 ) ;
F_26 ( V_9 , V_172 ,
V_173 , 1 ) ;
if ( V_165 && V_166 )
F_121 ( & V_144 ) ;
return 0 ;
V_170:
F_26 ( V_9 , V_172 ,
V_173 , 0 ) ;
F_113 ( V_9 ) ;
V_169:
F_122 ( V_9 -> V_125 , L_32 ) ;
free:
F_13 ( V_9 ) ;
V_26:
return V_37 ;
}
static void F_123 ( struct V_88 * V_19 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 , * V_174 ;
V_9 = V_19 -> V_153 ;
F_36 ( & V_6 ) ;
F_93 ( & V_9 -> V_100 ) ;
F_37 ( & V_6 ) ;
V_19 -> V_140 -> V_175 ( V_19 ) ;
F_124 ( & V_9 -> V_150 ) ;
F_125 (port, port2, &portdev->ports, list)
F_92 ( V_1 ) ;
F_122 ( V_9 -> V_125 , L_32 ) ;
F_114 ( V_9 ) ;
F_113 ( V_9 ) ;
F_13 ( V_9 ) ;
}
static int F_126 ( struct V_88 * V_19 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
V_9 = V_19 -> V_153 ;
V_19 -> V_140 -> V_175 ( V_19 ) ;
F_127 ( V_9 -> V_151 ) ;
F_124 ( & V_9 -> V_150 ) ;
F_127 ( V_9 -> V_151 ) ;
F_114 ( V_9 ) ;
F_3 (port, &portdev->ports, list) {
F_127 ( V_1 -> V_16 ) ;
F_127 ( V_1 -> V_17 ) ;
V_1 -> V_58 = false ;
F_91 ( V_1 ) ;
}
F_113 ( V_9 ) ;
return 0 ;
}
static int F_128 ( struct V_88 * V_19 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
int V_35 ;
V_9 = V_19 -> V_153 ;
V_35 = F_112 ( V_9 ) ;
if ( V_35 )
return V_35 ;
if ( F_11 ( V_9 ) )
F_74 ( V_9 -> V_151 , & V_9 -> V_152 ) ;
F_3 (port, &portdev->ports, list) {
V_1 -> V_16 = V_9 -> V_120 [ V_1 -> V_13 ] ;
V_1 -> V_17 = V_9 -> V_121 [ V_1 -> V_13 ] ;
F_74 ( V_1 -> V_16 , & V_1 -> V_39 ) ;
F_28 ( V_1 , V_132 , 1 ) ;
}
return 0 ;
}
static int T_8 F_129 ( void )
{
int V_37 ;
V_97 . V_127 = F_130 ( V_176 , L_36 ) ;
if ( F_64 ( V_97 . V_127 ) ) {
V_37 = F_65 ( V_97 . V_127 ) ;
F_131 ( L_37 , V_37 ) ;
return V_37 ;
}
V_97 . V_133 = F_132 ( L_36 , NULL ) ;
if ( ! V_97 . V_133 ) {
F_133 ( L_38 ,
F_65 ( V_97 . V_133 ) ) ;
}
F_119 ( & V_97 . V_101 ) ;
F_119 ( & V_97 . V_171 ) ;
return F_134 ( & V_177 ) ;
}
static void T_14 F_135 ( void )
{
F_136 ( & V_177 ) ;
F_137 ( V_97 . V_127 ) ;
if ( V_97 . V_133 )
F_138 ( V_97 . V_133 ) ;
}
