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
static void * F_17 ( struct V_1 * V_1 )
{
struct V_22 * V_23 ;
struct V_14 * V_15 ;
unsigned int V_27 ;
V_15 = V_1 -> V_16 ;
V_23 = F_18 ( V_15 , & V_27 ) ;
if ( V_23 ) {
V_23 -> V_27 = V_27 ;
V_23 -> V_28 = 0 ;
}
return V_23 ;
}
static int F_19 ( struct V_14 * V_15 , struct V_22 * V_23 )
{
struct V_30 V_31 [ 1 ] ;
int V_32 ;
F_20 ( V_31 , V_23 -> V_23 , V_23 -> V_29 ) ;
V_32 = F_21 ( V_15 , V_31 , 0 , 1 , V_23 ) ;
F_22 ( V_15 ) ;
return V_32 ;
}
static void F_23 ( struct V_1 * V_1 )
{
struct V_22 * V_23 ;
struct V_14 * V_15 ;
unsigned int V_27 ;
int V_32 ;
if ( ! V_1 -> V_9 ) {
return;
}
V_15 = V_1 -> V_16 ;
if ( V_1 -> V_33 )
V_23 = V_1 -> V_33 ;
else
V_23 = F_18 ( V_15 , & V_27 ) ;
V_32 = 0 ;
while ( V_23 ) {
if ( F_19 ( V_15 , V_23 ) < 0 ) {
V_32 ++ ;
F_12 ( V_23 ) ;
}
V_23 = F_18 ( V_15 , & V_27 ) ;
}
V_1 -> V_33 = NULL ;
if ( V_32 )
F_24 ( V_1 -> V_10 , L_1 ,
V_32 ) ;
}
static bool F_25 ( struct V_1 * V_1 )
{
unsigned long V_5 ;
bool V_32 ;
F_2 ( & V_1 -> V_34 , V_5 ) ;
if ( V_1 -> V_33 ) {
V_32 = true ;
goto V_7;
}
V_1 -> V_33 = F_17 ( V_1 ) ;
if ( V_1 -> V_33 ) {
V_32 = true ;
goto V_7;
}
V_32 = false ;
V_7:
F_5 ( & V_1 -> V_34 , V_5 ) ;
return V_32 ;
}
static T_4 F_26 ( struct V_8 * V_9 , T_1 V_35 ,
unsigned int V_36 , unsigned int V_37 )
{
struct V_30 V_31 [ 1 ] ;
struct V_38 V_39 ;
struct V_14 * V_15 ;
unsigned int V_27 ;
if ( ! F_11 ( V_9 ) )
return 0 ;
V_39 . V_13 = V_35 ;
V_39 . V_36 = V_36 ;
V_39 . V_37 = V_37 ;
V_15 = V_9 -> V_40 ;
F_20 ( V_31 , & V_39 , sizeof( V_39 ) ) ;
if ( F_21 ( V_15 , V_31 , 1 , 0 , & V_39 ) >= 0 ) {
F_22 ( V_15 ) ;
while ( ! F_18 ( V_15 , & V_27 ) )
F_27 () ;
}
return 0 ;
}
static T_4 F_28 ( struct V_1 * V_1 , unsigned int V_36 ,
unsigned int V_37 )
{
if ( V_1 -> V_9 )
return F_26 ( V_1 -> V_9 , V_1 -> V_13 , V_36 , V_37 ) ;
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
V_1 -> V_41 = false ;
}
}
static T_4 F_30 ( struct V_1 * V_1 , void * V_42 , T_3 V_43 ,
bool V_44 )
{
struct V_30 V_31 [ 1 ] ;
struct V_14 * V_17 ;
T_4 V_32 ;
unsigned long V_5 ;
unsigned int V_27 ;
V_17 = V_1 -> V_17 ;
F_2 ( & V_1 -> V_45 , V_5 ) ;
F_29 ( V_1 ) ;
F_20 ( V_31 , V_42 , V_43 ) ;
V_32 = F_21 ( V_17 , V_31 , 1 , 0 , V_42 ) ;
F_22 ( V_17 ) ;
if ( V_32 < 0 ) {
V_43 = 0 ;
goto V_46;
}
if ( V_32 == 0 )
V_1 -> V_41 = true ;
if ( V_44 )
goto V_46;
while ( ! F_18 ( V_17 , & V_27 ) )
F_27 () ;
V_46:
F_5 ( & V_1 -> V_45 , V_5 ) ;
return V_43 ;
}
static T_4 F_31 ( struct V_1 * V_1 , char * V_47 , T_3 V_48 ,
bool V_49 )
{
struct V_22 * V_23 ;
unsigned long V_5 ;
if ( ! V_48 || ! F_25 ( V_1 ) )
return 0 ;
V_23 = V_1 -> V_33 ;
V_48 = F_32 ( V_48 , V_23 -> V_27 - V_23 -> V_28 ) ;
if ( V_49 ) {
T_4 V_32 ;
V_32 = F_33 ( V_47 , V_23 -> V_23 + V_23 -> V_28 , V_48 ) ;
if ( V_32 )
return - V_50 ;
} else {
memcpy ( V_47 , V_23 -> V_23 + V_23 -> V_28 , V_48 ) ;
}
V_23 -> V_28 += V_48 ;
if ( V_23 -> V_28 == V_23 -> V_27 ) {
F_2 ( & V_1 -> V_34 , V_5 ) ;
V_1 -> V_33 = NULL ;
if ( F_19 ( V_1 -> V_16 , V_23 ) < 0 )
F_24 ( V_1 -> V_10 , L_2 ) ;
F_5 ( & V_1 -> V_34 , V_5 ) ;
}
return V_48 ;
}
static bool F_34 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_51 ) {
return false ;
}
return ! F_25 ( V_1 ) && V_1 -> V_52 ;
}
static bool F_35 ( struct V_1 * V_1 )
{
bool V_32 ;
if ( ! V_1 -> V_51 ) {
return false ;
}
if ( ! V_1 -> V_52 )
return true ;
F_36 ( & V_1 -> V_45 ) ;
F_29 ( V_1 ) ;
V_32 = V_1 -> V_41 ;
F_37 ( & V_1 -> V_45 ) ;
return V_32 ;
}
static T_4 F_38 ( struct V_53 * V_54 , char T_5 * V_55 ,
T_3 V_56 , T_6 * V_57 )
{
struct V_1 * V_1 ;
T_4 V_32 ;
V_1 = V_54 -> V_58 ;
if ( ! F_25 ( V_1 ) ) {
if ( ! V_1 -> V_52 )
return 0 ;
if ( V_54 -> V_59 & V_60 )
return - V_61 ;
V_32 = F_39 ( V_1 -> V_62 ,
! F_34 ( V_1 ) ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( ! V_1 -> V_51 )
return - V_63 ;
if ( ! F_25 ( V_1 ) && ! V_1 -> V_52 )
return 0 ;
return F_31 ( V_1 , V_55 , V_56 , true ) ;
}
static T_4 F_40 ( struct V_53 * V_54 , const char T_5 * V_55 ,
T_3 V_56 , T_6 * V_57 )
{
struct V_1 * V_1 ;
char * V_23 ;
T_4 V_32 ;
bool V_44 ;
if ( ! V_56 )
return 0 ;
V_1 = V_54 -> V_58 ;
V_44 = V_54 -> V_59 & V_60 ;
if ( F_35 ( V_1 ) ) {
if ( V_44 )
return - V_61 ;
V_32 = F_39 ( V_1 -> V_62 ,
! F_35 ( V_1 ) ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( ! V_1 -> V_51 )
return - V_63 ;
V_56 = F_32 ( ( T_3 ) ( 32 * 1024 ) , V_56 ) ;
V_23 = F_15 ( V_56 , V_25 ) ;
if ( ! V_23 )
return - V_64 ;
V_32 = F_41 ( V_23 , V_55 , V_56 ) ;
if ( V_32 ) {
V_32 = - V_50 ;
goto F_12;
}
V_44 = true ;
V_32 = F_30 ( V_1 , V_23 , V_56 , V_44 ) ;
if ( V_44 && V_32 > 0 )
goto V_7;
F_12:
F_13 ( V_23 ) ;
V_7:
return V_32 ;
}
static unsigned int F_42 ( struct V_53 * V_54 , T_7 * V_65 )
{
struct V_1 * V_1 ;
unsigned int V_32 ;
V_1 = V_54 -> V_58 ;
F_43 ( V_54 , & V_1 -> V_62 , V_65 ) ;
if ( ! V_1 -> V_51 ) {
return V_66 ;
}
V_32 = 0 ;
if ( ! F_34 ( V_1 ) )
V_32 |= V_67 | V_68 ;
if ( ! F_35 ( V_1 ) )
V_32 |= V_69 ;
if ( ! V_1 -> V_52 )
V_32 |= V_66 ;
return V_32 ;
}
static int F_44 ( struct V_70 * V_70 , struct V_53 * V_54 )
{
struct V_1 * V_1 ;
V_1 = V_54 -> V_58 ;
F_28 ( V_1 , V_71 , 0 ) ;
F_36 ( & V_1 -> V_34 ) ;
V_1 -> V_51 = false ;
F_23 ( V_1 ) ;
F_37 ( & V_1 -> V_34 ) ;
F_36 ( & V_1 -> V_45 ) ;
F_29 ( V_1 ) ;
F_37 ( & V_1 -> V_45 ) ;
F_45 ( & V_1 -> V_72 , V_73 ) ;
return 0 ;
}
static int F_46 ( struct V_70 * V_70 , struct V_53 * V_54 )
{
struct V_12 * V_12 = V_70 -> V_74 ;
struct V_1 * V_1 ;
int V_32 ;
V_1 = F_7 ( V_12 -> V_10 ) ;
V_54 -> V_58 = V_1 ;
F_36 ( & V_1 -> V_9 -> V_11 ) ;
F_47 ( & V_1 -> V_72 ) ;
F_37 ( & V_1 -> V_9 -> V_11 ) ;
if ( F_10 ( V_1 ) ) {
V_32 = - V_75 ;
goto V_7;
}
F_36 ( & V_1 -> V_34 ) ;
if ( V_1 -> V_51 ) {
F_37 ( & V_1 -> V_34 ) ;
V_32 = - V_76 ;
goto V_7;
}
V_1 -> V_51 = true ;
F_37 ( & V_1 -> V_34 ) ;
F_36 ( & V_1 -> V_45 ) ;
F_29 ( V_1 ) ;
F_37 ( & V_1 -> V_45 ) ;
F_48 ( V_70 , V_54 ) ;
F_28 ( V_54 -> V_58 , V_71 , 1 ) ;
return 0 ;
V_7:
F_45 ( & V_1 -> V_72 , V_73 ) ;
return V_32 ;
}
static int F_49 ( int V_77 , struct V_53 * V_54 , int V_78 )
{
struct V_1 * V_1 ;
V_1 = V_54 -> V_58 ;
return F_50 ( V_77 , V_54 , V_78 , & V_1 -> V_79 ) ;
}
static int F_51 ( T_1 V_2 , const char * V_23 , int V_56 )
{
struct V_1 * V_1 ;
if ( F_52 ( V_80 ) )
return V_80 ( V_2 , V_23 , V_56 ) ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_81 ;
return F_30 ( V_1 , ( void * ) V_23 , V_56 , false ) ;
}
static int F_53 ( T_1 V_2 , char * V_23 , int V_56 )
{
struct V_1 * V_1 ;
if ( F_52 ( V_80 ) )
return 0 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_81 ;
F_54 ( ! V_1 -> V_16 ) ;
return F_31 ( V_1 , V_23 , V_56 , false ) ;
}
static void F_55 ( struct V_1 * V_1 )
{
struct V_82 * V_19 ;
if ( ! V_1 || ! F_10 ( V_1 ) )
return;
V_19 = V_1 -> V_9 -> V_19 ;
if ( F_56 ( V_19 , V_83 ) )
F_57 ( V_1 -> V_4 . V_18 , V_1 -> V_4 . V_84 ) ;
}
static int F_58 ( struct V_85 * V_86 , int V_87 )
{
struct V_1 * V_1 ;
V_1 = F_1 ( V_86 -> V_2 ) ;
if ( ! V_1 )
return - V_88 ;
V_86 -> V_89 = 1 ;
F_55 ( V_1 ) ;
return 0 ;
}
static void F_59 ( struct V_85 * V_86 , int V_87 )
{
V_86 -> V_89 = 0 ;
}
int T_8 F_60 ( int (* F_51)( T_1 , const char * , int ) )
{
V_80 = F_51 ;
return F_61 ( 0 , 0 , & V_90 ) ;
}
int F_62 ( struct V_1 * V_1 )
{
int V_32 ;
V_1 -> V_4 . V_2 = V_91 . V_92 ;
V_1 -> V_4 . V_18 = F_63 ( V_1 -> V_4 . V_2 , 0 , & V_90 , V_93 ) ;
if ( F_64 ( V_1 -> V_4 . V_18 ) ) {
V_32 = F_65 ( V_1 -> V_4 . V_18 ) ;
F_66 ( V_1 -> V_10 ,
L_3 , V_32 ) ;
V_1 -> V_4 . V_18 = NULL ;
return V_32 ;
}
F_36 ( & V_6 ) ;
V_91 . V_92 ++ ;
F_67 ( & V_1 -> V_4 . V_94 , & V_91 . V_95 ) ;
F_37 ( & V_6 ) ;
V_1 -> V_51 = true ;
if ( V_80 )
V_80 = NULL ;
F_28 ( V_1 , V_71 , 1 ) ;
return 0 ;
}
static T_4 F_68 ( struct V_96 * V_10 ,
struct V_97 * V_98 , char * V_99 )
{
struct V_1 * V_1 ;
V_1 = F_69 ( V_10 ) ;
return sprintf ( V_99 , L_4 , V_1 -> V_100 ) ;
}
static int F_70 ( struct V_70 * V_70 , struct V_53 * V_54 )
{
V_54 -> V_58 = V_70 -> V_101 ;
return 0 ;
}
static T_4 F_71 ( struct V_53 * V_54 , char T_5 * V_55 ,
T_3 V_56 , T_6 * V_57 )
{
struct V_1 * V_1 ;
char * V_23 ;
T_4 V_32 , V_102 , V_48 ;
V_48 = 1024 ;
V_23 = F_15 ( V_48 , V_25 ) ;
if ( ! V_23 )
return - V_64 ;
V_1 = V_54 -> V_58 ;
V_102 = 0 ;
V_102 += snprintf ( V_23 + V_102 , V_48 ,
L_5 , V_1 -> V_100 ? V_1 -> V_100 : L_6 ) ;
V_102 += snprintf ( V_23 + V_102 , V_48 - V_102 ,
L_7 , V_1 -> V_51 ) ;
V_102 += snprintf ( V_23 + V_102 , V_48 - V_102 ,
L_8 , V_1 -> V_52 ) ;
V_102 += snprintf ( V_23 + V_102 , V_48 - V_102 ,
L_9 , V_1 -> V_41 ) ;
V_102 += snprintf ( V_23 + V_102 , V_48 - V_102 ,
L_10 ,
F_10 ( V_1 ) ? L_11 : L_12 ) ;
V_102 += snprintf ( V_23 + V_102 , V_48 - V_102 ,
L_13 , V_1 -> V_4 . V_2 ) ;
V_32 = F_72 ( V_55 , V_56 , V_57 , V_23 , V_102 ) ;
F_13 ( V_23 ) ;
return V_32 ;
}
static void F_73 ( struct V_1 * V_1 , T_9 V_103 , T_9 V_104 )
{
if ( ! V_1 || ! F_10 ( V_1 ) )
return;
V_1 -> V_4 . V_84 . V_105 = V_103 ;
V_1 -> V_4 . V_84 . V_106 = V_104 ;
}
static unsigned int F_74 ( struct V_14 * V_15 , T_10 * V_107 )
{
struct V_22 * V_23 ;
unsigned int V_108 ;
int V_32 ;
V_108 = 0 ;
do {
V_23 = F_14 ( V_93 ) ;
if ( ! V_23 )
break;
F_36 ( V_107 ) ;
V_32 = F_19 ( V_15 , V_23 ) ;
if ( V_32 < 0 ) {
F_37 ( V_107 ) ;
F_12 ( V_23 ) ;
break;
}
V_108 ++ ;
F_37 ( V_107 ) ;
} while ( V_32 > 0 );
return V_108 ;
}
static void F_75 ( struct V_1 * V_1 )
{
if ( V_1 -> V_79 && V_1 -> V_51 )
F_76 ( & V_1 -> V_79 , V_109 , V_110 ) ;
}
static int F_77 ( struct V_8 * V_9 , T_1 V_13 )
{
char V_111 [ 16 ] ;
struct V_1 * V_1 ;
struct V_22 * V_23 ;
T_2 V_112 ;
unsigned int V_108 ;
int V_113 ;
V_1 = F_15 ( sizeof( * V_1 ) , V_25 ) ;
if ( ! V_1 ) {
V_113 = - V_64 ;
goto V_26;
}
F_78 ( & V_1 -> V_72 ) ;
V_1 -> V_9 = V_9 ;
V_1 -> V_13 = V_13 ;
V_1 -> V_100 = NULL ;
V_1 -> V_33 = NULL ;
V_1 -> V_4 . V_18 = NULL ;
V_1 -> V_79 = NULL ;
V_1 -> V_4 . V_84 . V_105 = V_1 -> V_4 . V_84 . V_106 = 0 ;
V_1 -> V_52 = V_1 -> V_51 = false ;
V_1 -> V_41 = false ;
V_1 -> V_16 = V_9 -> V_114 [ V_1 -> V_13 ] ;
V_1 -> V_17 = V_9 -> V_115 [ V_1 -> V_13 ] ;
V_1 -> V_12 = F_79 () ;
if ( ! V_1 -> V_12 ) {
F_66 ( & V_1 -> V_9 -> V_19 -> V_10 , L_14 ) ;
V_113 = - V_64 ;
goto V_116;
}
V_1 -> V_12 -> V_117 = & V_118 ;
V_112 = F_80 ( V_9 -> V_119 , V_13 ) ;
V_113 = F_81 ( V_1 -> V_12 , V_112 , 1 ) ;
if ( V_113 < 0 ) {
F_66 ( & V_1 -> V_9 -> V_19 -> V_10 ,
L_15 , V_113 , V_13 ) ;
goto V_120;
}
V_1 -> V_10 = F_82 ( V_91 . V_121 , & V_1 -> V_9 -> V_19 -> V_10 ,
V_112 , V_1 , L_16 ,
V_1 -> V_9 -> V_122 , V_13 ) ;
if ( F_64 ( V_1 -> V_10 ) ) {
V_113 = F_65 ( V_1 -> V_10 ) ;
F_66 ( & V_1 -> V_9 -> V_19 -> V_10 ,
L_17 ,
V_113 , V_13 ) ;
goto V_120;
}
F_83 ( & V_1 -> V_34 ) ;
F_83 ( & V_1 -> V_45 ) ;
F_84 ( & V_1 -> V_62 ) ;
V_108 = F_74 ( V_1 -> V_16 , & V_1 -> V_34 ) ;
if ( ! V_108 ) {
F_66 ( V_1 -> V_10 , L_18 ) ;
V_113 = - V_64 ;
goto V_123;
}
if ( ! F_11 ( V_1 -> V_9 ) ) {
V_113 = F_62 ( V_1 ) ;
if ( V_113 )
goto V_124;
}
F_36 ( & V_9 -> V_11 ) ;
F_67 ( & V_1 -> V_94 , & V_1 -> V_9 -> V_125 ) ;
F_37 ( & V_9 -> V_11 ) ;
F_28 ( V_1 , V_126 , 1 ) ;
if ( V_91 . V_127 ) {
sprintf ( V_111 , L_16 ,
V_1 -> V_9 -> V_122 , V_13 ) ;
V_1 -> V_128 = F_85 ( V_111 , 0444 ,
V_91 . V_127 ,
V_1 ,
& V_129 ) ;
}
return 0 ;
V_124:
while ( ( V_23 = F_86 ( V_1 -> V_16 ) ) )
F_12 ( V_23 ) ;
V_123:
F_87 ( V_91 . V_121 , V_1 -> V_10 -> V_112 ) ;
V_120:
F_88 ( V_1 -> V_12 ) ;
V_116:
F_13 ( V_1 ) ;
V_26:
F_26 ( V_9 , V_13 , V_126 , 0 ) ;
return V_113 ;
}
static void V_73 ( struct V_72 * V_72 )
{
struct V_1 * V_1 ;
V_1 = F_4 ( V_72 , struct V_1 , V_72 ) ;
F_89 ( & V_1 -> V_10 -> V_130 , & V_131 ) ;
F_87 ( V_91 . V_121 , V_1 -> V_10 -> V_112 ) ;
F_88 ( V_1 -> V_12 ) ;
F_13 ( V_1 -> V_100 ) ;
F_90 ( V_1 -> V_128 ) ;
F_13 ( V_1 ) ;
}
static void F_91 ( struct V_1 * V_1 )
{
struct V_22 * V_23 ;
F_36 ( & V_1 -> V_9 -> V_11 ) ;
F_92 ( & V_1 -> V_94 ) ;
F_37 ( & V_1 -> V_9 -> V_11 ) ;
if ( V_1 -> V_51 ) {
V_1 -> V_51 = false ;
V_1 -> V_52 = false ;
F_93 ( & V_1 -> V_62 ) ;
F_75 ( V_1 ) ;
}
if ( F_10 ( V_1 ) ) {
F_36 ( & V_6 ) ;
F_92 ( & V_1 -> V_4 . V_94 ) ;
F_37 ( & V_6 ) ;
F_94 ( V_1 -> V_4 . V_18 ) ;
}
F_23 ( V_1 ) ;
F_29 ( V_1 ) ;
while ( ( V_23 = F_86 ( V_1 -> V_16 ) ) )
F_12 ( V_23 ) ;
V_1 -> V_9 = NULL ;
F_45 ( & V_1 -> V_72 , V_73 ) ;
}
static void F_95 ( struct V_8 * V_9 ,
struct V_22 * V_23 )
{
struct V_38 * V_39 ;
struct V_1 * V_1 ;
T_3 V_132 ;
int V_113 ;
V_39 = (struct V_38 * ) ( V_23 -> V_23 + V_23 -> V_28 ) ;
V_1 = F_8 ( V_9 , V_39 -> V_13 ) ;
if ( ! V_1 && V_39 -> V_36 != V_133 ) {
F_96 ( & V_9 -> V_19 -> V_10 ,
L_19 , V_39 -> V_13 ) ;
return;
}
switch ( V_39 -> V_36 ) {
case V_133 :
if ( V_1 ) {
F_96 ( & V_9 -> V_19 -> V_10 ,
L_20 , V_1 -> V_13 ) ;
F_28 ( V_1 , V_126 , 1 ) ;
break;
}
if ( V_39 -> V_13 >= V_9 -> V_134 . V_135 ) {
F_24 ( & V_9 -> V_19 -> V_10 ,
L_21 ,
V_39 -> V_13 , V_9 -> V_134 . V_135 - 1 ) ;
break;
}
F_77 ( V_9 , V_39 -> V_13 ) ;
break;
case V_136 :
F_91 ( V_1 ) ;
break;
case V_137 :
if ( ! V_39 -> V_37 )
break;
if ( F_10 ( V_1 ) )
break;
F_62 ( V_1 ) ;
break;
case V_138 : {
struct {
T_11 V_103 ;
T_11 V_104 ;
} V_29 ;
if ( ! F_10 ( V_1 ) )
break;
memcpy ( & V_29 , V_23 -> V_23 + V_23 -> V_28 + sizeof( * V_39 ) ,
sizeof( V_29 ) ) ;
F_73 ( V_1 , V_29 . V_103 , V_29 . V_104 ) ;
V_1 -> V_4 . V_18 -> V_89 = 1 ;
F_55 ( V_1 ) ;
break;
}
case V_71 :
V_1 -> V_52 = V_39 -> V_37 ;
F_93 ( & V_1 -> V_62 ) ;
F_36 ( & V_1 -> V_45 ) ;
F_29 ( V_1 ) ;
F_37 ( & V_1 -> V_45 ) ;
F_75 ( V_1 ) ;
break;
case V_139 :
V_132 = V_23 -> V_27 - V_23 -> V_28 - sizeof( * V_39 ) + 1 ;
V_1 -> V_100 = F_15 ( V_132 , V_25 ) ;
if ( ! V_1 -> V_100 ) {
F_66 ( V_1 -> V_10 ,
L_22 ) ;
break;
}
strncpy ( V_1 -> V_100 , V_23 -> V_23 + V_23 -> V_28 + sizeof( * V_39 ) ,
V_132 - 1 ) ;
V_1 -> V_100 [ V_132 - 1 ] = 0 ;
V_113 = F_97 ( & V_1 -> V_10 -> V_130 ,
& V_131 ) ;
if ( V_113 ) {
F_66 ( V_1 -> V_10 ,
L_23 ,
V_113 ) ;
} else {
F_98 ( & V_1 -> V_10 -> V_130 , V_140 ) ;
}
break;
}
}
static void F_99 ( struct V_141 * V_142 )
{
struct V_8 * V_9 ;
struct V_14 * V_15 ;
struct V_22 * V_23 ;
unsigned int V_27 ;
V_9 = F_4 ( V_142 , struct V_8 , V_143 ) ;
V_15 = V_9 -> V_144 ;
F_100 ( & V_9 -> V_145 ) ;
while ( ( V_23 = F_18 ( V_15 , & V_27 ) ) ) {
F_101 ( & V_9 -> V_145 ) ;
V_23 -> V_27 = V_27 ;
V_23 -> V_28 = 0 ;
F_95 ( V_9 , V_23 ) ;
F_100 ( & V_9 -> V_145 ) ;
if ( F_19 ( V_9 -> V_144 , V_23 ) < 0 ) {
F_24 ( & V_9 -> V_19 -> V_10 ,
L_24 ) ;
F_12 ( V_23 ) ;
}
}
F_101 ( & V_9 -> V_145 ) ;
}
static void F_102 ( struct V_14 * V_15 )
{
struct V_1 * V_1 ;
V_1 = F_9 ( V_15 -> V_19 -> V_146 , V_15 ) ;
if ( ! V_1 )
return;
F_93 ( & V_1 -> V_62 ) ;
}
static void F_103 ( struct V_14 * V_15 )
{
struct V_1 * V_1 ;
unsigned long V_5 ;
V_1 = F_9 ( V_15 -> V_19 -> V_146 , V_15 ) ;
if ( ! V_1 )
return;
F_2 ( & V_1 -> V_34 , V_5 ) ;
if ( ! V_1 -> V_33 )
V_1 -> V_33 = F_17 ( V_1 ) ;
if ( ! V_1 -> V_51 )
F_23 ( V_1 ) ;
F_5 ( & V_1 -> V_34 , V_5 ) ;
F_93 ( & V_1 -> V_62 ) ;
F_75 ( V_1 ) ;
if ( F_10 ( V_1 ) && F_104 ( V_1 -> V_4 . V_18 ) )
F_105 () ;
}
static void F_106 ( struct V_14 * V_15 )
{
struct V_8 * V_9 ;
V_9 = V_15 -> V_19 -> V_146 ;
F_107 ( & V_9 -> V_143 ) ;
}
static void F_108 ( struct V_82 * V_19 )
{
struct V_8 * V_9 ;
V_9 = V_19 -> V_146 ;
if ( ! F_11 ( V_9 ) ) {
struct V_1 * V_1 ;
T_9 V_103 , V_104 ;
V_19 -> V_134 -> V_147 ( V_19 ,
F_109 ( struct V_148 , V_104 ) ,
& V_104 , sizeof( T_9 ) ) ;
V_19 -> V_134 -> V_147 ( V_19 ,
F_109 ( struct V_148 , V_103 ) ,
& V_103 , sizeof( T_9 ) ) ;
V_1 = F_8 ( V_9 , 0 ) ;
F_73 ( V_1 , V_103 , V_104 ) ;
F_55 ( V_1 ) ;
}
}
static int F_110 ( struct V_8 * V_9 )
{
T_12 * * V_149 ;
char * * V_150 ;
struct V_14 * * V_151 ;
T_1 V_152 , V_153 , V_154 , V_155 ;
int V_113 ;
V_154 = V_9 -> V_134 . V_135 ;
V_155 = F_11 ( V_9 ) ? ( V_154 + 1 ) * 2 : 2 ;
V_151 = F_15 ( V_155 * sizeof( struct V_14 * ) , V_25 ) ;
V_149 = F_15 ( V_155 * sizeof( T_12 * ) , V_25 ) ;
V_150 = F_15 ( V_155 * sizeof( char * ) , V_25 ) ;
V_9 -> V_114 = F_15 ( V_154 * sizeof( struct V_14 * ) ,
V_25 ) ;
V_9 -> V_115 = F_15 ( V_154 * sizeof( struct V_14 * ) ,
V_25 ) ;
if ( ! V_151 || ! V_149 || ! V_150 || ! V_9 -> V_114 ||
! V_9 -> V_115 ) {
V_113 = - V_64 ;
goto free;
}
V_153 = 0 ;
V_149 [ V_153 ] = F_103 ;
V_149 [ V_153 + 1 ] = F_102 ;
V_150 [ V_153 ] = L_25 ;
V_150 [ V_153 + 1 ] = L_26 ;
V_153 += 2 ;
if ( F_11 ( V_9 ) ) {
V_149 [ V_153 ] = F_106 ;
V_149 [ V_153 + 1 ] = NULL ;
V_150 [ V_153 ] = L_27 ;
V_150 [ V_153 + 1 ] = L_28 ;
for ( V_152 = 1 ; V_152 < V_154 ; V_152 ++ ) {
V_153 += 2 ;
V_149 [ V_153 ] = F_103 ;
V_149 [ V_153 + 1 ] = F_102 ;
V_150 [ V_153 ] = L_25 ;
V_150 [ V_153 + 1 ] = L_26 ;
}
}
V_113 = V_9 -> V_19 -> V_134 -> V_156 ( V_9 -> V_19 , V_155 , V_151 ,
V_149 ,
( const char * * ) V_150 ) ;
if ( V_113 )
goto free;
V_153 = 0 ;
V_9 -> V_114 [ 0 ] = V_151 [ 0 ] ;
V_9 -> V_115 [ 0 ] = V_151 [ 1 ] ;
V_153 += 2 ;
if ( F_11 ( V_9 ) ) {
V_9 -> V_144 = V_151 [ V_153 ] ;
V_9 -> V_40 = V_151 [ V_153 + 1 ] ;
for ( V_152 = 1 ; V_152 < V_154 ; V_152 ++ ) {
V_153 += 2 ;
V_9 -> V_114 [ V_152 ] = V_151 [ V_153 ] ;
V_9 -> V_115 [ V_152 ] = V_151 [ V_153 + 1 ] ;
}
}
F_13 ( V_150 ) ;
F_13 ( V_149 ) ;
F_13 ( V_151 ) ;
return 0 ;
free:
F_13 ( V_9 -> V_115 ) ;
F_13 ( V_9 -> V_114 ) ;
F_13 ( V_150 ) ;
F_13 ( V_149 ) ;
F_13 ( V_151 ) ;
return V_113 ;
}
static int T_13 F_111 ( struct V_82 * V_19 )
{
struct V_8 * V_9 ;
int V_113 ;
bool V_157 ;
V_9 = F_15 ( sizeof( * V_9 ) , V_25 ) ;
if ( ! V_9 ) {
V_113 = - V_64 ;
goto V_26;
}
V_9 -> V_19 = V_19 ;
V_19 -> V_146 = V_9 ;
F_36 ( & V_6 ) ;
V_9 -> V_122 = V_91 . V_158 ++ ;
F_37 ( & V_6 ) ;
V_9 -> V_119 = F_112 ( 0 , L_29 ,
& V_159 ) ;
if ( V_9 -> V_119 < 0 ) {
F_66 ( & V_19 -> V_10 ,
L_30 ,
V_9 -> V_119 , V_9 -> V_122 ) ;
V_113 = V_9 -> V_119 ;
goto free;
}
V_157 = false ;
V_9 -> V_134 . V_135 = 1 ;
if ( F_56 ( V_19 , V_21 ) ) {
V_157 = true ;
V_19 -> V_134 -> V_147 ( V_19 , F_109 ( struct V_148 ,
V_135 ) ,
& V_9 -> V_134 . V_135 ,
sizeof( V_9 -> V_134 . V_135 ) ) ;
}
V_113 = F_110 ( V_9 ) ;
if ( V_113 < 0 ) {
F_66 ( & V_19 -> V_10 , L_31 , V_113 ) ;
goto V_160;
}
F_83 ( & V_9 -> V_11 ) ;
F_113 ( & V_9 -> V_125 ) ;
if ( V_157 ) {
unsigned int V_108 ;
F_83 ( & V_9 -> V_145 ) ;
F_114 ( & V_9 -> V_143 , & F_99 ) ;
V_108 = F_74 ( V_9 -> V_144 , & V_9 -> V_145 ) ;
if ( ! V_108 ) {
F_66 ( & V_19 -> V_10 ,
L_32 ) ;
V_113 = - V_64 ;
goto V_161;
}
} else {
F_77 ( V_9 , 0 ) ;
}
F_36 ( & V_6 ) ;
F_67 ( & V_9 -> V_94 , & V_91 . V_162 ) ;
F_37 ( & V_6 ) ;
F_26 ( V_9 , V_163 ,
V_164 , 1 ) ;
return 0 ;
V_161:
F_26 ( V_9 , V_163 ,
V_164 , 0 ) ;
V_19 -> V_134 -> V_165 ( V_19 ) ;
F_13 ( V_9 -> V_114 ) ;
F_13 ( V_9 -> V_115 ) ;
V_160:
F_115 ( V_9 -> V_119 , L_29 ) ;
free:
F_13 ( V_9 ) ;
V_26:
return V_113 ;
}
static void F_116 ( struct V_82 * V_19 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 , * V_166 ;
V_9 = V_19 -> V_146 ;
F_36 ( & V_6 ) ;
F_92 ( & V_9 -> V_94 ) ;
F_37 ( & V_6 ) ;
V_19 -> V_134 -> V_167 ( V_19 ) ;
F_117 ( & V_9 -> V_143 ) ;
F_118 (port, port2, &portdev->ports, list)
F_91 ( V_1 ) ;
F_115 ( V_9 -> V_119 , L_29 ) ;
if ( F_11 ( V_9 ) ) {
struct V_22 * V_23 ;
unsigned int V_27 ;
while ( ( V_23 = F_18 ( V_9 -> V_144 , & V_27 ) ) )
F_12 ( V_23 ) ;
while ( ( V_23 = F_86 ( V_9 -> V_144 ) ) )
F_12 ( V_23 ) ;
}
V_19 -> V_134 -> V_165 ( V_19 ) ;
F_13 ( V_9 -> V_114 ) ;
F_13 ( V_9 -> V_115 ) ;
F_13 ( V_9 ) ;
}
static int T_8 F_119 ( void )
{
int V_113 ;
V_91 . V_121 = F_120 ( V_168 , L_33 ) ;
if ( F_64 ( V_91 . V_121 ) ) {
V_113 = F_65 ( V_91 . V_121 ) ;
F_121 ( L_34 , V_113 ) ;
return V_113 ;
}
V_91 . V_127 = F_122 ( L_33 , NULL ) ;
if ( ! V_91 . V_127 ) {
F_123 ( L_35 ,
F_65 ( V_91 . V_127 ) ) ;
}
F_113 ( & V_91 . V_95 ) ;
F_113 ( & V_91 . V_162 ) ;
return F_124 ( & V_169 ) ;
}
static void T_14 F_125 ( void )
{
F_126 ( & V_169 ) ;
F_127 ( V_91 . V_121 ) ;
if ( V_91 . V_127 )
F_128 ( V_91 . V_127 ) ;
}
