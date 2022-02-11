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
static void F_29 ( struct V_33 * V_34 , unsigned int V_46 )
{
int V_47 ;
struct V_48 * V_48 ;
for ( V_47 = 0 ; V_47 < V_46 ; V_47 ++ ) {
V_48 = F_30 ( & V_34 [ V_47 ] ) ;
if ( ! V_48 )
break;
F_31 ( V_48 ) ;
}
F_13 ( V_34 ) ;
}
static void F_32 ( struct V_1 * V_1 )
{
struct V_49 * V_50 ;
unsigned int V_27 ;
if ( ! V_1 -> V_9 ) {
return;
}
while ( ( V_50 = F_18 ( V_1 -> V_17 , & V_27 ) ) ) {
if ( V_50 -> V_51 )
F_29 ( V_50 -> V_52 . V_34 , V_50 -> V_51 ) ;
else
F_13 ( V_50 -> V_52 . V_23 ) ;
F_13 ( V_50 ) ;
V_1 -> V_53 = false ;
}
}
static T_4 F_33 ( struct V_1 * V_1 , struct V_33 * V_34 ,
int V_54 , T_3 V_55 ,
struct V_49 * V_50 , bool V_56 )
{
struct V_14 * V_17 ;
T_4 V_35 ;
unsigned long V_5 ;
unsigned int V_27 ;
V_17 = V_1 -> V_17 ;
F_2 ( & V_1 -> V_57 , V_5 ) ;
F_32 ( V_1 ) ;
V_35 = F_21 ( V_17 , V_34 , V_54 , 0 , V_50 , V_36 ) ;
F_22 ( V_17 ) ;
if ( V_35 < 0 ) {
V_55 = 0 ;
goto V_58;
}
if ( V_35 == 0 )
V_1 -> V_53 = true ;
if ( V_56 )
goto V_58;
while ( ! F_18 ( V_17 , & V_27 ) )
F_27 () ;
V_58:
F_5 ( & V_1 -> V_57 , V_5 ) ;
V_1 -> V_31 . V_59 += V_55 ;
return V_55 ;
}
static T_4 F_34 ( struct V_1 * V_1 , void * V_60 , T_3 V_55 ,
bool V_56 )
{
struct V_33 V_34 [ 1 ] ;
struct V_49 * V_50 ;
V_50 = F_15 ( sizeof( * V_50 ) , V_36 ) ;
if ( ! V_50 )
return - V_61 ;
V_50 -> V_51 = 0 ;
V_50 -> V_52 . V_23 = V_60 ;
F_20 ( V_34 , V_60 , V_55 ) ;
return F_33 ( V_1 , V_34 , 1 , V_55 , V_50 , V_56 ) ;
}
static T_4 F_35 ( struct V_1 * V_1 , struct V_33 * V_34 , int V_54 ,
T_3 V_55 , bool V_56 )
{
struct V_49 * V_50 ;
V_50 = F_15 ( sizeof( * V_50 ) , V_36 ) ;
if ( ! V_50 )
return - V_61 ;
V_50 -> V_51 = V_54 ;
V_50 -> V_52 . V_34 = V_34 ;
return F_33 ( V_1 , V_34 , V_54 , V_55 , V_50 , V_56 ) ;
}
static T_4 F_36 ( struct V_1 * V_1 , char * V_62 , T_3 V_63 ,
bool V_64 )
{
struct V_22 * V_23 ;
unsigned long V_5 ;
if ( ! V_63 || ! F_25 ( V_1 ) )
return 0 ;
V_23 = V_1 -> V_30 ;
V_63 = F_37 ( V_63 , V_23 -> V_27 - V_23 -> V_28 ) ;
if ( V_64 ) {
T_4 V_35 ;
V_35 = F_38 ( V_62 , V_23 -> V_23 + V_23 -> V_28 , V_63 ) ;
if ( V_35 )
return - V_65 ;
} else {
memcpy ( V_62 , V_23 -> V_23 + V_23 -> V_28 , V_63 ) ;
}
V_23 -> V_28 += V_63 ;
if ( V_23 -> V_28 == V_23 -> V_27 ) {
F_2 ( & V_1 -> V_39 , V_5 ) ;
V_1 -> V_30 = NULL ;
if ( F_19 ( V_1 -> V_16 , V_23 ) < 0 )
F_24 ( V_1 -> V_10 , L_2 ) ;
F_5 ( & V_1 -> V_39 , V_5 ) ;
}
return V_63 ;
}
static bool F_39 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_66 ) {
return false ;
}
return ! F_25 ( V_1 ) && V_1 -> V_67 ;
}
static bool F_40 ( struct V_1 * V_1 )
{
bool V_35 ;
if ( ! V_1 -> V_66 ) {
return false ;
}
if ( ! V_1 -> V_67 )
return true ;
F_41 ( & V_1 -> V_57 ) ;
F_32 ( V_1 ) ;
V_35 = V_1 -> V_53 ;
F_42 ( & V_1 -> V_57 ) ;
return V_35 ;
}
static T_4 F_43 ( struct V_68 * V_69 , char T_5 * V_70 ,
T_3 V_71 , T_6 * V_72 )
{
struct V_1 * V_1 ;
T_4 V_35 ;
V_1 = V_69 -> V_73 ;
if ( ! F_25 ( V_1 ) ) {
if ( ! V_1 -> V_67 )
return 0 ;
if ( V_69 -> V_74 & V_75 )
return - V_76 ;
V_35 = F_44 ( V_1 -> V_77 ,
! F_39 ( V_1 ) ) ;
if ( V_35 < 0 )
return V_35 ;
}
if ( ! V_1 -> V_66 )
return - V_78 ;
if ( ! F_25 ( V_1 ) && ! V_1 -> V_67 )
return 0 ;
return F_36 ( V_1 , V_70 , V_71 , true ) ;
}
static int F_45 ( struct V_1 * V_1 , bool V_56 )
{
int V_35 ;
if ( F_40 ( V_1 ) ) {
if ( V_56 )
return - V_76 ;
V_35 = F_44 ( V_1 -> V_77 ,
! F_40 ( V_1 ) ) ;
if ( V_35 < 0 )
return V_35 ;
}
if ( ! V_1 -> V_66 )
return - V_78 ;
return 0 ;
}
static T_4 F_46 ( struct V_68 * V_69 , const char T_5 * V_70 ,
T_3 V_71 , T_6 * V_72 )
{
struct V_1 * V_1 ;
char * V_23 ;
T_4 V_35 ;
bool V_56 ;
if ( ! V_71 )
return 0 ;
V_1 = V_69 -> V_73 ;
V_56 = V_69 -> V_74 & V_75 ;
V_35 = F_45 ( V_1 , V_56 ) ;
if ( V_35 < 0 )
return V_35 ;
V_71 = F_37 ( ( T_3 ) ( 32 * 1024 ) , V_71 ) ;
V_23 = F_15 ( V_71 , V_25 ) ;
if ( ! V_23 )
return - V_61 ;
V_35 = F_47 ( V_23 , V_70 , V_71 ) ;
if ( V_35 ) {
V_35 = - V_65 ;
goto F_12;
}
V_56 = true ;
V_35 = F_34 ( V_1 , V_23 , V_71 , V_56 ) ;
if ( V_56 && V_35 > 0 )
goto V_7;
F_12:
F_13 ( V_23 ) ;
V_7:
return V_35 ;
}
static int F_48 ( struct V_79 * V_80 , struct V_81 * V_23 ,
struct V_82 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_52 . V_86 ;
unsigned int V_28 , V_27 ;
if ( V_85 -> V_87 == V_85 -> V_29 )
return 0 ;
if ( V_23 -> V_88 -> V_89 ( V_80 , V_23 ) == 0 ) {
F_49 ( V_23 -> V_48 ) ;
F_50 ( V_23 -> V_48 ) ;
V_27 = F_37 ( V_23 -> V_27 , V_83 -> V_27 ) ;
F_51 ( & ( V_85 -> V_34 [ V_85 -> V_87 ] ) , V_23 -> V_48 , V_27 , V_23 -> V_28 ) ;
} else {
struct V_48 * V_48 = F_52 ( V_25 ) ;
char * V_90 = V_23 -> V_88 -> V_91 ( V_80 , V_23 , 1 ) ;
char * V_92 ;
if ( ! V_48 )
return - V_61 ;
V_92 = F_53 ( V_48 ) ;
V_28 = V_83 -> V_93 & ~ V_94 ;
V_27 = V_83 -> V_27 ;
if ( V_27 + V_28 > V_95 )
V_27 = V_95 - V_28 ;
memcpy ( V_92 + V_28 , V_90 + V_23 -> V_28 , V_27 ) ;
F_54 ( V_48 ) ;
V_23 -> V_88 -> V_96 ( V_80 , V_23 , V_90 ) ;
F_51 ( & ( V_85 -> V_34 [ V_85 -> V_87 ] ) , V_48 , V_27 , V_28 ) ;
}
V_85 -> V_87 ++ ;
V_85 -> V_27 += V_27 ;
return V_27 ;
}
static T_4 F_55 ( struct V_79 * V_80 ,
struct V_68 * V_69 , T_6 * V_97 ,
T_3 V_27 , unsigned int V_5 )
{
struct V_1 * V_1 = V_69 -> V_73 ;
struct V_84 V_85 ;
T_4 V_35 ;
struct V_82 V_83 = {
. V_98 = V_27 ,
. V_5 = V_5 ,
. V_93 = * V_97 ,
. V_52 . V_86 = & V_85 ,
} ;
V_35 = F_45 ( V_1 , V_69 -> V_74 & V_75 ) ;
if ( V_35 < 0 )
return V_35 ;
V_85 . V_87 = 0 ;
V_85 . V_27 = 0 ;
V_85 . V_29 = V_80 -> V_99 ;
V_85 . V_34 = F_15 ( sizeof( struct V_33 ) * V_85 . V_29 , V_25 ) ;
if ( F_56 ( ! V_85 . V_34 ) )
return - V_61 ;
F_57 ( V_85 . V_34 , V_85 . V_29 ) ;
V_35 = F_58 ( V_80 , & V_83 , F_48 ) ;
if ( F_59 ( V_35 > 0 ) )
V_35 = F_35 ( V_1 , V_85 . V_34 , V_85 . V_87 , V_85 . V_27 , true ) ;
return V_35 ;
}
static unsigned int F_60 ( struct V_68 * V_69 , T_7 * V_100 )
{
struct V_1 * V_1 ;
unsigned int V_35 ;
V_1 = V_69 -> V_73 ;
F_61 ( V_69 , & V_1 -> V_77 , V_100 ) ;
if ( ! V_1 -> V_66 ) {
return V_101 ;
}
V_35 = 0 ;
if ( ! F_39 ( V_1 ) )
V_35 |= V_102 | V_103 ;
if ( ! F_40 ( V_1 ) )
V_35 |= V_104 ;
if ( ! V_1 -> V_67 )
V_35 |= V_101 ;
return V_35 ;
}
static int F_62 ( struct V_105 * V_105 , struct V_68 * V_69 )
{
struct V_1 * V_1 ;
V_1 = V_69 -> V_73 ;
F_28 ( V_1 , V_106 , 0 ) ;
F_41 ( & V_1 -> V_39 ) ;
V_1 -> V_66 = false ;
F_23 ( V_1 ) ;
F_42 ( & V_1 -> V_39 ) ;
F_41 ( & V_1 -> V_57 ) ;
F_32 ( V_1 ) ;
F_42 ( & V_1 -> V_57 ) ;
F_63 ( & V_1 -> V_107 , V_108 ) ;
return 0 ;
}
static int F_64 ( struct V_105 * V_105 , struct V_68 * V_69 )
{
struct V_12 * V_12 = V_105 -> V_109 ;
struct V_1 * V_1 ;
int V_35 ;
V_1 = F_7 ( V_12 -> V_10 ) ;
V_69 -> V_73 = V_1 ;
F_41 ( & V_1 -> V_9 -> V_11 ) ;
F_65 ( & V_1 -> V_107 ) ;
F_42 ( & V_1 -> V_9 -> V_11 ) ;
if ( F_10 ( V_1 ) ) {
V_35 = - V_110 ;
goto V_7;
}
F_41 ( & V_1 -> V_39 ) ;
if ( V_1 -> V_66 ) {
F_42 ( & V_1 -> V_39 ) ;
V_35 = - V_111 ;
goto V_7;
}
V_1 -> V_66 = true ;
F_42 ( & V_1 -> V_39 ) ;
F_41 ( & V_1 -> V_57 ) ;
F_32 ( V_1 ) ;
F_42 ( & V_1 -> V_57 ) ;
F_66 ( V_105 , V_69 ) ;
F_28 ( V_69 -> V_73 , V_106 , 1 ) ;
return 0 ;
V_7:
F_63 ( & V_1 -> V_107 , V_108 ) ;
return V_35 ;
}
static int F_67 ( int V_112 , struct V_68 * V_69 , int V_113 )
{
struct V_1 * V_1 ;
V_1 = V_69 -> V_73 ;
return F_68 ( V_112 , V_69 , V_113 , & V_1 -> V_114 ) ;
}
static int F_69 ( T_1 V_2 , const char * V_23 , int V_71 )
{
struct V_1 * V_1 ;
if ( F_56 ( V_115 ) )
return V_115 ( V_2 , V_23 , V_71 ) ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_116 ;
return F_34 ( V_1 , ( void * ) V_23 , V_71 , false ) ;
}
static int F_70 ( T_1 V_2 , char * V_23 , int V_71 )
{
struct V_1 * V_1 ;
if ( F_56 ( V_115 ) )
return 0 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_116 ;
F_71 ( ! V_1 -> V_16 ) ;
return F_36 ( V_1 , V_23 , V_71 , false ) ;
}
static void F_72 ( struct V_1 * V_1 )
{
struct V_117 * V_19 ;
if ( ! V_1 || ! F_10 ( V_1 ) )
return;
V_19 = V_1 -> V_9 -> V_19 ;
if ( F_73 ( V_19 , V_118 ) )
F_74 ( V_1 -> V_4 . V_18 , V_1 -> V_4 . V_119 ) ;
}
static int F_75 ( struct V_120 * V_121 , int V_86 )
{
struct V_1 * V_1 ;
V_1 = F_1 ( V_121 -> V_2 ) ;
if ( ! V_1 )
return - V_122 ;
V_121 -> V_123 = 1 ;
F_72 ( V_1 ) ;
return 0 ;
}
static void F_76 ( struct V_120 * V_121 , int V_86 )
{
V_121 -> V_123 = 0 ;
}
int T_8 F_77 ( int (* F_69)( T_1 , const char * , int ) )
{
V_115 = F_69 ;
return F_78 ( 0 , 0 , & V_124 ) ;
}
int F_79 ( struct V_1 * V_1 )
{
int V_35 ;
V_1 -> V_4 . V_2 = V_125 . V_126 ;
V_1 -> V_4 . V_18 = F_80 ( V_1 -> V_4 . V_2 , 0 , & V_124 , V_95 ) ;
if ( F_81 ( V_1 -> V_4 . V_18 ) ) {
V_35 = F_82 ( V_1 -> V_4 . V_18 ) ;
F_83 ( V_1 -> V_10 ,
L_3 , V_35 ) ;
V_1 -> V_4 . V_18 = NULL ;
return V_35 ;
}
F_41 ( & V_6 ) ;
V_125 . V_126 ++ ;
F_84 ( & V_1 -> V_4 . V_127 , & V_125 . V_128 ) ;
F_42 ( & V_6 ) ;
V_1 -> V_66 = true ;
if ( V_115 )
V_115 = NULL ;
F_28 ( V_1 , V_106 , 1 ) ;
return 0 ;
}
static T_4 F_85 ( struct V_129 * V_10 ,
struct V_130 * V_131 , char * V_132 )
{
struct V_1 * V_1 ;
V_1 = F_86 ( V_10 ) ;
return sprintf ( V_132 , L_4 , V_1 -> V_133 ) ;
}
static T_4 F_87 ( struct V_68 * V_69 , char T_5 * V_70 ,
T_3 V_71 , T_6 * V_72 )
{
struct V_1 * V_1 ;
char * V_23 ;
T_4 V_35 , V_134 , V_63 ;
V_63 = 1024 ;
V_23 = F_15 ( V_63 , V_25 ) ;
if ( ! V_23 )
return - V_61 ;
V_1 = V_69 -> V_73 ;
V_134 = 0 ;
V_134 += snprintf ( V_23 + V_134 , V_63 ,
L_5 , V_1 -> V_133 ? V_1 -> V_133 : L_6 ) ;
V_134 += snprintf ( V_23 + V_134 , V_63 - V_134 ,
L_7 , V_1 -> V_66 ) ;
V_134 += snprintf ( V_23 + V_134 , V_63 - V_134 ,
L_8 , V_1 -> V_67 ) ;
V_134 += snprintf ( V_23 + V_134 , V_63 - V_134 ,
L_9 , V_1 -> V_53 ) ;
V_134 += snprintf ( V_23 + V_134 , V_63 - V_134 ,
L_10 , V_1 -> V_31 . V_59 ) ;
V_134 += snprintf ( V_23 + V_134 , V_63 - V_134 ,
L_11 ,
V_1 -> V_31 . V_32 ) ;
V_134 += snprintf ( V_23 + V_134 , V_63 - V_134 ,
L_12 ,
V_1 -> V_31 . V_38 ) ;
V_134 += snprintf ( V_23 + V_134 , V_63 - V_134 ,
L_13 ,
F_10 ( V_1 ) ? L_14 : L_15 ) ;
V_134 += snprintf ( V_23 + V_134 , V_63 - V_134 ,
L_16 , V_1 -> V_4 . V_2 ) ;
V_35 = F_88 ( V_70 , V_71 , V_72 , V_23 , V_134 ) ;
F_13 ( V_23 ) ;
return V_35 ;
}
static void F_89 ( struct V_1 * V_1 , T_9 V_135 , T_9 V_136 )
{
if ( ! V_1 || ! F_10 ( V_1 ) )
return;
V_1 -> V_4 . V_119 . V_137 = V_135 ;
V_1 -> V_4 . V_119 . V_138 = V_136 ;
}
static unsigned int F_90 ( struct V_14 * V_15 , T_10 * V_139 )
{
struct V_22 * V_23 ;
unsigned int V_140 ;
int V_35 ;
V_140 = 0 ;
do {
V_23 = F_14 ( V_95 ) ;
if ( ! V_23 )
break;
F_41 ( V_139 ) ;
V_35 = F_19 ( V_15 , V_23 ) ;
if ( V_35 < 0 ) {
F_42 ( V_139 ) ;
F_12 ( V_23 ) ;
break;
}
V_140 ++ ;
F_42 ( V_139 ) ;
} while ( V_35 > 0 );
return V_140 ;
}
static void F_91 ( struct V_1 * V_1 )
{
if ( V_1 -> V_114 && V_1 -> V_66 )
F_92 ( & V_1 -> V_114 , V_141 , V_142 ) ;
}
static int F_93 ( struct V_8 * V_9 , T_1 V_13 )
{
char V_143 [ 16 ] ;
struct V_1 * V_1 ;
struct V_22 * V_23 ;
T_2 V_144 ;
unsigned int V_140 ;
int V_37 ;
V_1 = F_15 ( sizeof( * V_1 ) , V_25 ) ;
if ( ! V_1 ) {
V_37 = - V_61 ;
goto V_26;
}
F_94 ( & V_1 -> V_107 ) ;
V_1 -> V_9 = V_9 ;
V_1 -> V_13 = V_13 ;
V_1 -> V_133 = NULL ;
V_1 -> V_30 = NULL ;
V_1 -> V_4 . V_18 = NULL ;
V_1 -> V_114 = NULL ;
V_1 -> V_4 . V_119 . V_137 = V_1 -> V_4 . V_119 . V_138 = 0 ;
V_1 -> V_67 = V_1 -> V_66 = false ;
V_1 -> V_31 = (struct V_145 ) { 0 } ;
V_1 -> V_53 = false ;
V_1 -> V_16 = V_9 -> V_146 [ V_1 -> V_13 ] ;
V_1 -> V_17 = V_9 -> V_147 [ V_1 -> V_13 ] ;
V_1 -> V_12 = F_95 () ;
if ( ! V_1 -> V_12 ) {
F_83 ( & V_1 -> V_9 -> V_19 -> V_10 , L_17 ) ;
V_37 = - V_61 ;
goto V_148;
}
V_1 -> V_12 -> V_88 = & V_149 ;
V_144 = F_96 ( V_9 -> V_150 , V_13 ) ;
V_37 = F_97 ( V_1 -> V_12 , V_144 , 1 ) ;
if ( V_37 < 0 ) {
F_83 ( & V_1 -> V_9 -> V_19 -> V_10 ,
L_18 , V_37 , V_13 ) ;
goto V_151;
}
V_1 -> V_10 = F_98 ( V_125 . V_152 , & V_1 -> V_9 -> V_19 -> V_10 ,
V_144 , V_1 , L_19 ,
V_1 -> V_9 -> V_153 , V_13 ) ;
if ( F_81 ( V_1 -> V_10 ) ) {
V_37 = F_82 ( V_1 -> V_10 ) ;
F_83 ( & V_1 -> V_9 -> V_19 -> V_10 ,
L_20 ,
V_37 , V_13 ) ;
goto V_151;
}
F_99 ( & V_1 -> V_39 ) ;
F_99 ( & V_1 -> V_57 ) ;
F_100 ( & V_1 -> V_77 ) ;
V_140 = F_90 ( V_1 -> V_16 , & V_1 -> V_39 ) ;
if ( ! V_140 ) {
F_83 ( V_1 -> V_10 , L_21 ) ;
V_37 = - V_61 ;
goto V_154;
}
if ( ! F_11 ( V_1 -> V_9 ) ) {
V_37 = F_79 ( V_1 ) ;
if ( V_37 )
goto V_155;
}
F_41 ( & V_9 -> V_11 ) ;
F_84 ( & V_1 -> V_127 , & V_1 -> V_9 -> V_156 ) ;
F_42 ( & V_9 -> V_11 ) ;
F_28 ( V_1 , V_157 , 1 ) ;
if ( V_125 . V_158 ) {
sprintf ( V_143 , L_19 ,
V_1 -> V_9 -> V_153 , V_13 ) ;
V_1 -> V_159 = F_101 ( V_143 , 0444 ,
V_125 . V_158 ,
V_1 ,
& V_160 ) ;
}
return 0 ;
V_155:
while ( ( V_23 = F_102 ( V_1 -> V_16 ) ) )
F_12 ( V_23 ) ;
V_154:
F_103 ( V_125 . V_152 , V_1 -> V_10 -> V_144 ) ;
V_151:
F_104 ( V_1 -> V_12 ) ;
V_148:
F_13 ( V_1 ) ;
V_26:
F_26 ( V_9 , V_13 , V_157 , 0 ) ;
return V_37 ;
}
static void V_108 ( struct V_107 * V_107 )
{
struct V_1 * V_1 ;
V_1 = F_4 ( V_107 , struct V_1 , V_107 ) ;
F_105 ( & V_1 -> V_10 -> V_161 , & V_162 ) ;
F_103 ( V_125 . V_152 , V_1 -> V_10 -> V_144 ) ;
F_104 ( V_1 -> V_12 ) ;
F_13 ( V_1 -> V_133 ) ;
F_106 ( V_1 -> V_159 ) ;
F_13 ( V_1 ) ;
}
static void F_107 ( struct V_1 * V_1 )
{
struct V_22 * V_23 ;
F_23 ( V_1 ) ;
F_32 ( V_1 ) ;
while ( ( V_23 = F_102 ( V_1 -> V_16 ) ) )
F_12 ( V_23 ) ;
}
static void F_108 ( struct V_1 * V_1 )
{
F_41 ( & V_1 -> V_9 -> V_11 ) ;
F_109 ( & V_1 -> V_127 ) ;
F_42 ( & V_1 -> V_9 -> V_11 ) ;
if ( V_1 -> V_66 ) {
V_1 -> V_66 = false ;
V_1 -> V_67 = false ;
F_110 ( & V_1 -> V_77 ) ;
F_91 ( V_1 ) ;
}
if ( F_10 ( V_1 ) ) {
F_41 ( & V_6 ) ;
F_109 ( & V_1 -> V_4 . V_127 ) ;
F_42 ( & V_6 ) ;
F_111 ( V_1 -> V_4 . V_18 ) ;
}
F_107 ( V_1 ) ;
V_1 -> V_9 = NULL ;
F_63 ( & V_1 -> V_107 , V_108 ) ;
}
static void F_112 ( struct V_8 * V_9 ,
struct V_22 * V_23 )
{
struct V_43 * V_44 ;
struct V_1 * V_1 ;
T_3 V_163 ;
int V_37 ;
V_44 = (struct V_43 * ) ( V_23 -> V_23 + V_23 -> V_28 ) ;
V_1 = F_8 ( V_9 , V_44 -> V_13 ) ;
if ( ! V_1 && V_44 -> V_41 != V_164 ) {
F_113 ( & V_9 -> V_19 -> V_10 ,
L_22 , V_44 -> V_13 ) ;
return;
}
switch ( V_44 -> V_41 ) {
case V_164 :
if ( V_1 ) {
F_113 ( & V_9 -> V_19 -> V_10 ,
L_23 , V_1 -> V_13 ) ;
F_28 ( V_1 , V_157 , 1 ) ;
break;
}
if ( V_44 -> V_13 >= V_9 -> V_165 . V_166 ) {
F_24 ( & V_9 -> V_19 -> V_10 ,
L_24 ,
V_44 -> V_13 , V_9 -> V_165 . V_166 - 1 ) ;
break;
}
F_93 ( V_9 , V_44 -> V_13 ) ;
break;
case V_167 :
F_108 ( V_1 ) ;
break;
case V_168 :
if ( ! V_44 -> V_42 )
break;
if ( F_10 ( V_1 ) )
break;
F_79 ( V_1 ) ;
F_114 ( & V_169 ) ;
break;
case V_170 : {
struct {
T_11 V_135 ;
T_11 V_136 ;
} V_29 ;
if ( ! F_10 ( V_1 ) )
break;
memcpy ( & V_29 , V_23 -> V_23 + V_23 -> V_28 + sizeof( * V_44 ) ,
sizeof( V_29 ) ) ;
F_89 ( V_1 , V_29 . V_135 , V_29 . V_136 ) ;
V_1 -> V_4 . V_18 -> V_123 = 1 ;
F_72 ( V_1 ) ;
break;
}
case V_106 :
V_1 -> V_67 = V_44 -> V_42 ;
F_110 ( & V_1 -> V_77 ) ;
F_41 ( & V_1 -> V_57 ) ;
F_32 ( V_1 ) ;
F_42 ( & V_1 -> V_57 ) ;
F_91 ( V_1 ) ;
break;
case V_171 :
if ( V_1 -> V_133 )
break;
V_163 = V_23 -> V_27 - V_23 -> V_28 - sizeof( * V_44 ) + 1 ;
V_1 -> V_133 = F_15 ( V_163 , V_25 ) ;
if ( ! V_1 -> V_133 ) {
F_83 ( V_1 -> V_10 ,
L_25 ) ;
break;
}
strncpy ( V_1 -> V_133 , V_23 -> V_23 + V_23 -> V_28 + sizeof( * V_44 ) ,
V_163 - 1 ) ;
V_1 -> V_133 [ V_163 - 1 ] = 0 ;
V_37 = F_115 ( & V_1 -> V_10 -> V_161 ,
& V_162 ) ;
if ( V_37 ) {
F_83 ( V_1 -> V_10 ,
L_26 ,
V_37 ) ;
} else {
F_116 ( & V_1 -> V_10 -> V_161 , V_172 ) ;
}
break;
}
}
static void F_117 ( struct V_173 * V_174 )
{
struct V_8 * V_9 ;
struct V_14 * V_15 ;
struct V_22 * V_23 ;
unsigned int V_27 ;
V_9 = F_4 ( V_174 , struct V_8 , V_175 ) ;
V_15 = V_9 -> V_176 ;
F_118 ( & V_9 -> V_177 ) ;
while ( ( V_23 = F_18 ( V_15 , & V_27 ) ) ) {
F_119 ( & V_9 -> V_177 ) ;
V_23 -> V_27 = V_27 ;
V_23 -> V_28 = 0 ;
F_112 ( V_9 , V_23 ) ;
F_118 ( & V_9 -> V_177 ) ;
if ( F_19 ( V_9 -> V_176 , V_23 ) < 0 ) {
F_24 ( & V_9 -> V_19 -> V_10 ,
L_27 ) ;
F_12 ( V_23 ) ;
}
}
F_119 ( & V_9 -> V_177 ) ;
}
static void F_120 ( struct V_14 * V_15 )
{
struct V_1 * V_1 ;
V_1 = F_9 ( V_15 -> V_19 -> V_178 , V_15 ) ;
if ( ! V_1 )
return;
F_110 ( & V_1 -> V_77 ) ;
}
static void F_121 ( struct V_14 * V_15 )
{
struct V_1 * V_1 ;
unsigned long V_5 ;
V_1 = F_9 ( V_15 -> V_19 -> V_178 , V_15 ) ;
if ( ! V_1 )
return;
F_2 ( & V_1 -> V_39 , V_5 ) ;
V_1 -> V_30 = F_17 ( V_1 ) ;
if ( ! V_1 -> V_66 )
F_23 ( V_1 ) ;
F_5 ( & V_1 -> V_39 , V_5 ) ;
F_110 ( & V_1 -> V_77 ) ;
F_91 ( V_1 ) ;
if ( F_10 ( V_1 ) && F_122 ( V_1 -> V_4 . V_18 ) )
F_123 () ;
}
static void F_124 ( struct V_14 * V_15 )
{
struct V_8 * V_9 ;
V_9 = V_15 -> V_19 -> V_178 ;
F_125 ( & V_9 -> V_175 ) ;
}
static void F_126 ( struct V_117 * V_19 )
{
struct V_8 * V_9 ;
V_9 = V_19 -> V_178 ;
if ( ! F_11 ( V_9 ) ) {
struct V_1 * V_1 ;
T_9 V_135 , V_136 ;
V_19 -> V_165 -> V_179 ( V_19 ,
F_127 ( struct V_180 , V_136 ) ,
& V_136 , sizeof( T_9 ) ) ;
V_19 -> V_165 -> V_179 ( V_19 ,
F_127 ( struct V_180 , V_135 ) ,
& V_135 , sizeof( T_9 ) ) ;
V_1 = F_8 ( V_9 , 0 ) ;
F_89 ( V_1 , V_135 , V_136 ) ;
F_72 ( V_1 ) ;
}
}
static int F_128 ( struct V_8 * V_9 )
{
T_12 * * V_181 ;
char * * V_182 ;
struct V_14 * * V_183 ;
T_1 V_47 , V_184 , V_185 , V_186 ;
int V_37 ;
V_185 = V_9 -> V_165 . V_166 ;
V_186 = F_11 ( V_9 ) ? ( V_185 + 1 ) * 2 : 2 ;
V_183 = F_15 ( V_186 * sizeof( struct V_14 * ) , V_25 ) ;
V_181 = F_15 ( V_186 * sizeof( T_12 * ) , V_25 ) ;
V_182 = F_15 ( V_186 * sizeof( char * ) , V_25 ) ;
V_9 -> V_146 = F_15 ( V_185 * sizeof( struct V_14 * ) ,
V_25 ) ;
V_9 -> V_147 = F_15 ( V_185 * sizeof( struct V_14 * ) ,
V_25 ) ;
if ( ! V_183 || ! V_181 || ! V_182 || ! V_9 -> V_146 ||
! V_9 -> V_147 ) {
V_37 = - V_61 ;
goto free;
}
V_184 = 0 ;
V_181 [ V_184 ] = F_121 ;
V_181 [ V_184 + 1 ] = F_120 ;
V_182 [ V_184 ] = L_28 ;
V_182 [ V_184 + 1 ] = L_29 ;
V_184 += 2 ;
if ( F_11 ( V_9 ) ) {
V_181 [ V_184 ] = F_124 ;
V_181 [ V_184 + 1 ] = NULL ;
V_182 [ V_184 ] = L_30 ;
V_182 [ V_184 + 1 ] = L_31 ;
for ( V_47 = 1 ; V_47 < V_185 ; V_47 ++ ) {
V_184 += 2 ;
V_181 [ V_184 ] = F_121 ;
V_181 [ V_184 + 1 ] = F_120 ;
V_182 [ V_184 ] = L_28 ;
V_182 [ V_184 + 1 ] = L_29 ;
}
}
V_37 = V_9 -> V_19 -> V_165 -> V_187 ( V_9 -> V_19 , V_186 , V_183 ,
V_181 ,
( const char * * ) V_182 ) ;
if ( V_37 )
goto free;
V_184 = 0 ;
V_9 -> V_146 [ 0 ] = V_183 [ 0 ] ;
V_9 -> V_147 [ 0 ] = V_183 [ 1 ] ;
V_184 += 2 ;
if ( F_11 ( V_9 ) ) {
V_9 -> V_176 = V_183 [ V_184 ] ;
V_9 -> V_45 = V_183 [ V_184 + 1 ] ;
for ( V_47 = 1 ; V_47 < V_185 ; V_47 ++ ) {
V_184 += 2 ;
V_9 -> V_146 [ V_47 ] = V_183 [ V_184 ] ;
V_9 -> V_147 [ V_47 ] = V_183 [ V_184 + 1 ] ;
}
}
F_13 ( V_182 ) ;
F_13 ( V_181 ) ;
F_13 ( V_183 ) ;
return 0 ;
free:
F_13 ( V_9 -> V_147 ) ;
F_13 ( V_9 -> V_146 ) ;
F_13 ( V_182 ) ;
F_13 ( V_181 ) ;
F_13 ( V_183 ) ;
return V_37 ;
}
static void F_129 ( struct V_8 * V_9 )
{
V_9 -> V_19 -> V_165 -> V_188 ( V_9 -> V_19 ) ;
F_13 ( V_9 -> V_146 ) ;
F_13 ( V_9 -> V_147 ) ;
}
static void F_130 ( struct V_8 * V_9 )
{
struct V_22 * V_23 ;
unsigned int V_27 ;
if ( ! F_11 ( V_9 ) )
return;
while ( ( V_23 = F_18 ( V_9 -> V_176 , & V_27 ) ) )
F_12 ( V_23 ) ;
while ( ( V_23 = F_102 ( V_9 -> V_176 ) ) )
F_12 ( V_23 ) ;
}
static int T_13 F_131 ( struct V_117 * V_19 )
{
struct V_8 * V_9 ;
int V_37 ;
bool V_189 ;
bool V_190 = V_115 != NULL ;
F_132 () ;
V_9 = F_15 ( sizeof( * V_9 ) , V_25 ) ;
if ( ! V_9 ) {
V_37 = - V_61 ;
goto V_26;
}
V_9 -> V_19 = V_19 ;
V_19 -> V_178 = V_9 ;
F_41 ( & V_6 ) ;
V_9 -> V_153 = V_125 . V_191 ++ ;
F_42 ( & V_6 ) ;
V_9 -> V_150 = F_133 ( 0 , L_32 ,
& V_192 ) ;
if ( V_9 -> V_150 < 0 ) {
F_83 ( & V_19 -> V_10 ,
L_33 ,
V_9 -> V_150 , V_9 -> V_153 ) ;
V_37 = V_9 -> V_150 ;
goto free;
}
V_189 = false ;
V_9 -> V_165 . V_166 = 1 ;
if ( F_134 ( V_19 , V_21 ,
F_127 ( struct V_180 ,
V_166 ) ,
& V_9 -> V_165 . V_166 ) == 0 )
V_189 = true ;
V_37 = F_128 ( V_9 ) ;
if ( V_37 < 0 ) {
F_83 ( & V_19 -> V_10 , L_34 , V_37 ) ;
goto V_193;
}
F_99 ( & V_9 -> V_11 ) ;
F_135 ( & V_9 -> V_156 ) ;
if ( V_189 ) {
unsigned int V_140 ;
F_99 ( & V_9 -> V_177 ) ;
F_136 ( & V_9 -> V_175 , & F_117 ) ;
V_140 = F_90 ( V_9 -> V_176 , & V_9 -> V_177 ) ;
if ( ! V_140 ) {
F_83 ( & V_19 -> V_10 ,
L_35 ) ;
V_37 = - V_61 ;
goto V_194;
}
} else {
F_93 ( V_9 , 0 ) ;
}
F_41 ( & V_6 ) ;
F_84 ( & V_9 -> V_127 , & V_125 . V_195 ) ;
F_42 ( & V_6 ) ;
F_26 ( V_9 , V_196 ,
V_197 , 1 ) ;
if ( V_189 && V_190 )
F_137 ( & V_169 ) ;
return 0 ;
V_194:
F_26 ( V_9 , V_196 ,
V_197 , 0 ) ;
F_129 ( V_9 ) ;
V_193:
F_138 ( V_9 -> V_150 , L_32 ) ;
free:
F_13 ( V_9 ) ;
V_26:
return V_37 ;
}
static void F_139 ( struct V_117 * V_19 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 , * V_198 ;
V_9 = V_19 -> V_178 ;
F_41 ( & V_6 ) ;
F_109 ( & V_9 -> V_127 ) ;
F_42 ( & V_6 ) ;
V_19 -> V_165 -> V_199 ( V_19 ) ;
F_140 ( & V_9 -> V_175 ) ;
F_141 (port, port2, &portdev->ports, list)
F_108 ( V_1 ) ;
F_138 ( V_9 -> V_150 , L_32 ) ;
F_130 ( V_9 ) ;
F_129 ( V_9 ) ;
F_13 ( V_9 ) ;
}
static int F_142 ( struct V_117 * V_19 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
V_9 = V_19 -> V_178 ;
V_19 -> V_165 -> V_199 ( V_19 ) ;
F_143 ( V_9 -> V_176 ) ;
F_140 ( & V_9 -> V_175 ) ;
F_143 ( V_9 -> V_176 ) ;
F_130 ( V_9 ) ;
F_3 (port, &portdev->ports, list) {
F_143 ( V_1 -> V_16 ) ;
F_143 ( V_1 -> V_17 ) ;
V_1 -> V_67 = false ;
F_107 ( V_1 ) ;
}
F_129 ( V_9 ) ;
return 0 ;
}
static int F_144 ( struct V_117 * V_19 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
int V_35 ;
V_9 = V_19 -> V_178 ;
V_35 = F_128 ( V_9 ) ;
if ( V_35 )
return V_35 ;
if ( F_11 ( V_9 ) )
F_90 ( V_9 -> V_176 , & V_9 -> V_177 ) ;
F_3 (port, &portdev->ports, list) {
V_1 -> V_16 = V_9 -> V_146 [ V_1 -> V_13 ] ;
V_1 -> V_17 = V_9 -> V_147 [ V_1 -> V_13 ] ;
F_90 ( V_1 -> V_16 , & V_1 -> V_39 ) ;
F_28 ( V_1 , V_157 , 1 ) ;
if ( V_1 -> V_66 )
F_28 ( V_1 , V_106 , 1 ) ;
}
return 0 ;
}
static int T_8 F_145 ( void )
{
int V_37 ;
V_125 . V_152 = F_146 ( V_200 , L_36 ) ;
if ( F_81 ( V_125 . V_152 ) ) {
V_37 = F_82 ( V_125 . V_152 ) ;
F_147 ( L_37 , V_37 ) ;
return V_37 ;
}
V_125 . V_158 = F_148 ( L_36 , NULL ) ;
if ( ! V_125 . V_158 ) {
F_149 ( L_38 ,
F_82 ( V_125 . V_158 ) ) ;
}
F_135 ( & V_125 . V_128 ) ;
F_135 ( & V_125 . V_195 ) ;
V_37 = F_150 ( & V_201 ) ;
if ( V_37 < 0 ) {
F_147 ( L_39 , V_37 ) ;
goto free;
}
return 0 ;
free:
if ( V_125 . V_158 )
F_151 ( V_125 . V_158 ) ;
F_152 ( V_125 . V_152 ) ;
return V_37 ;
}
static void T_14 F_153 ( void )
{
F_154 ( & V_201 ) ;
F_152 ( V_125 . V_152 ) ;
if ( V_125 . V_158 )
F_151 ( V_125 . V_158 ) ;
}
