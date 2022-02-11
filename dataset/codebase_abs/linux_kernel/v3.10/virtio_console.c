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
static bool F_11 ( const struct V_19 * V_20 )
{
return V_21 && V_20 -> V_13 . V_22 == V_23 ;
}
static inline bool F_12 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_20 )
return 0 ;
return V_9 -> V_20 -> V_24 [ 0 ] & ( 1 << V_25 ) ;
}
static void F_13 ( struct V_26 * V_27 , bool V_28 )
{
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < V_27 -> V_30 ; V_29 ++ ) {
struct V_31 * V_31 = F_14 ( & V_27 -> V_32 [ V_29 ] ) ;
if ( ! V_31 )
break;
F_15 ( V_31 ) ;
}
if ( ! V_27 -> V_10 ) {
F_16 ( V_27 -> V_27 ) ;
} else if ( V_21 ) {
unsigned long V_5 ;
if ( ! V_28 ) {
F_2 ( & V_33 , V_5 ) ;
F_17 ( & V_27 -> V_34 , & V_35 ) ;
F_5 ( & V_33 , V_5 ) ;
return;
}
F_18 ( V_27 -> V_10 , V_27 -> V_36 , V_27 -> V_27 , V_27 -> V_37 ) ;
F_19 ( V_27 -> V_10 ) ;
}
F_16 ( V_27 ) ;
}
static void F_20 ( void )
{
unsigned long V_5 ;
struct V_26 * V_27 , * V_38 ;
F_21 ( V_39 ) ;
if ( F_22 ( & V_35 ) )
return;
F_2 ( & V_33 , V_5 ) ;
F_23 ( & V_39 , & V_35 ,
V_35 . V_40 ) ;
F_5 ( & V_33 , V_5 ) ;
F_24 (buf, tmp, &tmp_list, list) {
F_25 ( & V_27 -> V_34 ) ;
F_13 ( V_27 , true ) ;
}
}
static struct V_26 * F_26 ( struct V_14 * V_15 , T_3 V_41 ,
int V_42 )
{
struct V_26 * V_27 ;
F_20 () ;
V_27 = F_27 ( sizeof( * V_27 ) + sizeof( struct V_43 ) * V_42 ,
V_44 ) ;
if ( ! V_27 )
goto V_45;
V_27 -> V_30 = V_42 ;
if ( V_42 > 0 ) {
V_27 -> V_10 = NULL ;
V_27 -> V_27 = NULL ;
return V_27 ;
}
if ( F_11 ( V_15 -> V_20 ) ) {
if ( ! V_15 -> V_20 -> V_10 . V_46 || ! V_15 -> V_20 -> V_10 . V_46 -> V_46 )
goto F_13;
V_27 -> V_10 = V_15 -> V_20 -> V_10 . V_46 -> V_46 ;
F_28 ( V_27 -> V_10 ) ;
V_27 -> V_27 = F_29 ( V_27 -> V_10 , V_41 , & V_27 -> V_37 ,
V_44 ) ;
} else {
V_27 -> V_10 = NULL ;
V_27 -> V_27 = F_27 ( V_41 , V_44 ) ;
}
if ( ! V_27 -> V_27 )
goto F_13;
V_27 -> V_47 = 0 ;
V_27 -> V_48 = 0 ;
V_27 -> V_36 = V_41 ;
return V_27 ;
F_13:
F_16 ( V_27 ) ;
V_45:
return NULL ;
}
static struct V_26 * F_30 ( struct V_1 * V_1 )
{
struct V_26 * V_27 ;
unsigned int V_47 ;
if ( V_1 -> V_49 )
return V_1 -> V_49 ;
V_27 = F_31 ( V_1 -> V_16 , & V_47 ) ;
if ( V_27 ) {
V_27 -> V_47 = V_47 ;
V_27 -> V_48 = 0 ;
V_1 -> V_50 . V_51 += V_47 ;
}
return V_27 ;
}
static int F_32 ( struct V_14 * V_15 , struct V_26 * V_27 )
{
struct V_43 V_32 [ 1 ] ;
int V_52 ;
F_33 ( V_32 , V_27 -> V_27 , V_27 -> V_36 ) ;
V_52 = F_34 ( V_15 , V_32 , 1 , V_27 , V_53 ) ;
F_35 ( V_15 ) ;
if ( ! V_52 )
V_52 = V_15 -> V_54 ;
return V_52 ;
}
static void F_36 ( struct V_1 * V_1 )
{
struct V_26 * V_27 ;
unsigned int V_55 ;
if ( ! V_1 -> V_9 ) {
return;
}
V_27 = F_30 ( V_1 ) ;
V_55 = 0 ;
while ( V_27 ) {
V_1 -> V_50 . V_56 += V_27 -> V_47 - V_27 -> V_48 ;
if ( F_32 ( V_1 -> V_16 , V_27 ) < 0 ) {
V_55 ++ ;
F_13 ( V_27 , false ) ;
}
V_1 -> V_49 = NULL ;
V_27 = F_30 ( V_1 ) ;
}
if ( V_55 )
F_37 ( V_1 -> V_10 , L_1 ,
V_55 ) ;
}
static bool F_38 ( struct V_1 * V_1 )
{
unsigned long V_5 ;
bool V_52 ;
V_52 = false ;
F_2 ( & V_1 -> V_57 , V_5 ) ;
V_1 -> V_49 = F_30 ( V_1 ) ;
if ( V_1 -> V_49 )
V_52 = true ;
F_5 ( & V_1 -> V_57 , V_5 ) ;
return V_52 ;
}
static T_4 F_39 ( struct V_8 * V_9 , T_1 V_58 ,
unsigned int V_59 , unsigned int V_60 )
{
struct V_43 V_32 [ 1 ] ;
struct V_61 V_62 ;
struct V_14 * V_15 ;
unsigned int V_47 ;
if ( ! F_12 ( V_9 ) )
return 0 ;
V_62 . V_13 = V_58 ;
V_62 . V_59 = V_59 ;
V_62 . V_60 = V_60 ;
V_15 = V_9 -> V_63 ;
F_33 ( V_32 , & V_62 , sizeof( V_62 ) ) ;
F_40 ( & V_9 -> V_64 ) ;
if ( F_41 ( V_15 , V_32 , 1 , & V_62 , V_53 ) == 0 ) {
F_35 ( V_15 ) ;
while ( ! F_31 ( V_15 , & V_47 ) )
F_42 () ;
}
F_43 ( & V_9 -> V_64 ) ;
return 0 ;
}
static T_4 F_44 ( struct V_1 * V_1 , unsigned int V_59 ,
unsigned int V_60 )
{
if ( V_1 -> V_9 )
return F_39 ( V_1 -> V_9 , V_1 -> V_13 , V_59 , V_60 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_1 )
{
struct V_26 * V_27 ;
unsigned int V_47 ;
if ( ! V_1 -> V_9 ) {
return;
}
while ( ( V_27 = F_31 ( V_1 -> V_17 , & V_47 ) ) ) {
F_13 ( V_27 , false ) ;
V_1 -> V_65 = false ;
}
}
static T_4 F_46 ( struct V_1 * V_1 , struct V_43 * V_32 ,
int V_66 , T_3 V_67 ,
void * V_68 , bool V_69 )
{
struct V_14 * V_17 ;
int V_55 ;
unsigned long V_5 ;
unsigned int V_47 ;
V_17 = V_1 -> V_17 ;
F_2 ( & V_1 -> V_70 , V_5 ) ;
F_45 ( V_1 ) ;
V_55 = F_41 ( V_17 , V_32 , V_66 , V_68 , V_53 ) ;
F_35 ( V_17 ) ;
if ( V_55 ) {
V_67 = 0 ;
goto V_71;
}
if ( V_17 -> V_54 == 0 )
V_1 -> V_65 = true ;
if ( V_69 )
goto V_71;
while ( ! F_31 ( V_17 , & V_47 ) )
F_42 () ;
V_71:
F_5 ( & V_1 -> V_70 , V_5 ) ;
V_1 -> V_50 . V_72 += V_67 ;
return V_67 ;
}
static T_4 F_47 ( struct V_1 * V_1 , char * V_73 , T_3 V_74 ,
bool V_75 )
{
struct V_26 * V_27 ;
unsigned long V_5 ;
if ( ! V_74 || ! F_38 ( V_1 ) )
return 0 ;
V_27 = V_1 -> V_49 ;
V_74 = F_48 ( V_74 , V_27 -> V_47 - V_27 -> V_48 ) ;
if ( V_75 ) {
T_4 V_52 ;
V_52 = F_49 ( V_73 , V_27 -> V_27 + V_27 -> V_48 , V_74 ) ;
if ( V_52 )
return - V_76 ;
} else {
memcpy ( V_73 , V_27 -> V_27 + V_27 -> V_48 , V_74 ) ;
}
V_27 -> V_48 += V_74 ;
if ( V_27 -> V_48 == V_27 -> V_47 ) {
F_2 ( & V_1 -> V_57 , V_5 ) ;
V_1 -> V_49 = NULL ;
if ( F_32 ( V_1 -> V_16 , V_27 ) < 0 )
F_37 ( V_1 -> V_10 , L_2 ) ;
F_5 ( & V_1 -> V_57 , V_5 ) ;
}
return V_74 ;
}
static bool F_50 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_77 ) {
return false ;
}
return ! F_38 ( V_1 ) && V_1 -> V_78 ;
}
static bool F_51 ( struct V_1 * V_1 )
{
bool V_52 ;
if ( ! V_1 -> V_77 ) {
return false ;
}
if ( ! V_1 -> V_78 )
return true ;
F_52 ( & V_1 -> V_70 ) ;
F_45 ( V_1 ) ;
V_52 = V_1 -> V_65 ;
F_53 ( & V_1 -> V_70 ) ;
return V_52 ;
}
static T_4 F_54 ( struct V_79 * V_80 , char T_5 * V_81 ,
T_3 V_82 , T_6 * V_83 )
{
struct V_1 * V_1 ;
T_4 V_52 ;
V_1 = V_80 -> V_84 ;
if ( ! F_38 ( V_1 ) ) {
if ( ! V_1 -> V_78 )
return 0 ;
if ( V_80 -> V_85 & V_86 )
return - V_87 ;
V_52 = F_55 ( V_1 -> V_88 ,
! F_50 ( V_1 ) ) ;
if ( V_52 < 0 )
return V_52 ;
}
if ( ! V_1 -> V_77 )
return - V_89 ;
if ( ! F_38 ( V_1 ) && ! V_1 -> V_78 )
return 0 ;
return F_47 ( V_1 , V_81 , V_82 , true ) ;
}
static int F_56 ( struct V_1 * V_1 , bool V_69 )
{
int V_52 ;
if ( F_51 ( V_1 ) ) {
if ( V_69 )
return - V_87 ;
V_52 = F_55 ( V_1 -> V_88 ,
! F_51 ( V_1 ) ) ;
if ( V_52 < 0 )
return V_52 ;
}
if ( ! V_1 -> V_77 )
return - V_89 ;
return 0 ;
}
static T_4 F_57 ( struct V_79 * V_80 , const char T_5 * V_81 ,
T_3 V_82 , T_6 * V_83 )
{
struct V_1 * V_1 ;
struct V_26 * V_27 ;
T_4 V_52 ;
bool V_69 ;
struct V_43 V_32 [ 1 ] ;
if ( ! V_82 )
return 0 ;
V_1 = V_80 -> V_84 ;
V_69 = V_80 -> V_85 & V_86 ;
V_52 = F_56 ( V_1 , V_69 ) ;
if ( V_52 < 0 )
return V_52 ;
V_82 = F_48 ( ( T_3 ) ( 32 * 1024 ) , V_82 ) ;
V_27 = F_26 ( V_1 -> V_17 , V_82 , 0 ) ;
if ( ! V_27 )
return - V_90 ;
V_52 = F_58 ( V_27 -> V_27 , V_81 , V_82 ) ;
if ( V_52 ) {
V_52 = - V_76 ;
goto F_13;
}
V_69 = true ;
F_33 ( V_32 , V_27 -> V_27 , V_82 ) ;
V_52 = F_46 ( V_1 , V_32 , 1 , V_82 , V_27 , V_69 ) ;
if ( V_69 && V_52 > 0 )
goto V_7;
F_13:
F_13 ( V_27 , true ) ;
V_7:
return V_52 ;
}
static int F_59 ( struct V_91 * V_92 , struct V_93 * V_27 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_98 . V_68 ;
unsigned int V_48 , V_47 ;
if ( V_97 -> V_99 == V_97 -> V_36 )
return 0 ;
if ( V_27 -> V_100 -> V_101 ( V_92 , V_27 ) == 0 ) {
F_60 ( V_27 -> V_31 ) ;
F_61 ( V_27 -> V_31 ) ;
V_47 = F_48 ( V_27 -> V_47 , V_95 -> V_47 ) ;
F_62 ( & ( V_97 -> V_32 [ V_97 -> V_99 ] ) , V_27 -> V_31 , V_47 , V_27 -> V_48 ) ;
} else {
struct V_31 * V_31 = F_63 ( V_44 ) ;
char * V_102 = V_27 -> V_100 -> V_103 ( V_92 , V_27 , 1 ) ;
char * V_104 ;
if ( ! V_31 )
return - V_90 ;
V_104 = F_64 ( V_31 ) ;
V_48 = V_95 -> V_105 & ~ V_106 ;
V_47 = V_95 -> V_47 ;
if ( V_47 + V_48 > V_107 )
V_47 = V_107 - V_48 ;
memcpy ( V_104 + V_48 , V_102 + V_27 -> V_48 , V_47 ) ;
F_65 ( V_31 ) ;
V_27 -> V_100 -> V_108 ( V_92 , V_27 , V_102 ) ;
F_62 ( & ( V_97 -> V_32 [ V_97 -> V_99 ] ) , V_31 , V_47 , V_48 ) ;
}
V_97 -> V_99 ++ ;
V_97 -> V_47 += V_47 ;
return V_47 ;
}
static T_4 F_66 ( struct V_91 * V_92 ,
struct V_79 * V_80 , T_6 * V_109 ,
T_3 V_47 , unsigned int V_5 )
{
struct V_1 * V_1 = V_80 -> V_84 ;
struct V_96 V_97 ;
T_4 V_52 ;
struct V_26 * V_27 ;
struct V_94 V_95 = {
. V_110 = V_47 ,
. V_5 = V_5 ,
. V_105 = * V_109 ,
. V_98 . V_68 = & V_97 ,
} ;
if ( F_11 ( V_1 -> V_17 -> V_20 ) )
return - V_111 ;
V_52 = F_56 ( V_1 , V_80 -> V_85 & V_86 ) ;
if ( V_52 < 0 )
return V_52 ;
V_27 = F_26 ( V_1 -> V_17 , 0 , V_92 -> V_112 ) ;
if ( ! V_27 )
return - V_90 ;
V_97 . V_99 = 0 ;
V_97 . V_47 = 0 ;
V_97 . V_36 = V_92 -> V_112 ;
V_97 . V_32 = V_27 -> V_32 ;
F_67 ( V_97 . V_32 , V_97 . V_36 ) ;
V_52 = F_68 ( V_92 , & V_95 , F_59 ) ;
if ( F_69 ( V_52 > 0 ) )
V_52 = F_46 ( V_1 , V_27 -> V_32 , V_97 . V_99 , V_97 . V_47 , V_27 , true ) ;
if ( F_70 ( V_52 <= 0 ) )
F_13 ( V_27 , true ) ;
return V_52 ;
}
static unsigned int F_71 ( struct V_79 * V_80 , T_7 * V_113 )
{
struct V_1 * V_1 ;
unsigned int V_52 ;
V_1 = V_80 -> V_84 ;
F_72 ( V_80 , & V_1 -> V_88 , V_113 ) ;
if ( ! V_1 -> V_77 ) {
return V_114 ;
}
V_52 = 0 ;
if ( ! F_50 ( V_1 ) )
V_52 |= V_115 | V_116 ;
if ( ! F_51 ( V_1 ) )
V_52 |= V_117 ;
if ( ! V_1 -> V_78 )
V_52 |= V_114 ;
return V_52 ;
}
static int F_73 ( struct V_118 * V_118 , struct V_79 * V_80 )
{
struct V_1 * V_1 ;
V_1 = V_80 -> V_84 ;
F_44 ( V_1 , V_119 , 0 ) ;
F_52 ( & V_1 -> V_57 ) ;
V_1 -> V_77 = false ;
F_36 ( V_1 ) ;
F_53 ( & V_1 -> V_57 ) ;
F_52 ( & V_1 -> V_70 ) ;
F_45 ( V_1 ) ;
F_53 ( & V_1 -> V_70 ) ;
F_20 () ;
F_74 ( & V_1 -> V_120 , V_121 ) ;
return 0 ;
}
static int F_75 ( struct V_118 * V_118 , struct V_79 * V_80 )
{
struct V_12 * V_12 = V_118 -> V_122 ;
struct V_1 * V_1 ;
int V_52 ;
V_1 = F_7 ( V_12 -> V_10 ) ;
V_80 -> V_84 = V_1 ;
F_52 ( & V_1 -> V_9 -> V_11 ) ;
F_76 ( & V_1 -> V_120 ) ;
F_53 ( & V_1 -> V_9 -> V_11 ) ;
if ( F_10 ( V_1 ) ) {
V_52 = - V_123 ;
goto V_7;
}
F_52 ( & V_1 -> V_57 ) ;
if ( V_1 -> V_77 ) {
F_53 ( & V_1 -> V_57 ) ;
V_52 = - V_124 ;
goto V_7;
}
V_1 -> V_77 = true ;
F_53 ( & V_1 -> V_57 ) ;
F_52 ( & V_1 -> V_70 ) ;
F_45 ( V_1 ) ;
F_53 ( & V_1 -> V_70 ) ;
F_77 ( V_118 , V_80 ) ;
F_44 ( V_80 -> V_84 , V_119 , 1 ) ;
return 0 ;
V_7:
F_74 ( & V_1 -> V_120 , V_121 ) ;
return V_52 ;
}
static int F_78 ( int V_125 , struct V_79 * V_80 , int V_126 )
{
struct V_1 * V_1 ;
V_1 = V_80 -> V_84 ;
return F_79 ( V_125 , V_80 , V_126 , & V_1 -> V_127 ) ;
}
static int F_80 ( T_1 V_2 , const char * V_27 , int V_82 )
{
struct V_1 * V_1 ;
struct V_43 V_32 [ 1 ] ;
if ( F_70 ( V_128 ) )
return V_128 ( V_2 , V_27 , V_82 ) ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_129 ;
F_33 ( V_32 , V_27 , V_82 ) ;
return F_46 ( V_1 , V_32 , 1 , V_82 , ( void * ) V_27 , false ) ;
}
static int F_81 ( T_1 V_2 , char * V_27 , int V_82 )
{
struct V_1 * V_1 ;
if ( F_70 ( V_128 ) )
return 0 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_129 ;
F_82 ( ! V_1 -> V_16 ) ;
return F_47 ( V_1 , V_27 , V_82 , false ) ;
}
static void F_83 ( struct V_1 * V_1 )
{
struct V_19 * V_20 ;
if ( ! V_1 || ! F_10 ( V_1 ) )
return;
V_20 = V_1 -> V_9 -> V_20 ;
if ( ! F_11 ( V_20 ) &&
F_84 ( V_20 , V_130 ) )
F_85 ( V_1 -> V_4 . V_18 , V_1 -> V_4 . V_131 ) ;
}
static int F_86 ( struct V_132 * V_133 , int V_68 )
{
struct V_1 * V_1 ;
V_1 = F_1 ( V_133 -> V_2 ) ;
if ( ! V_1 )
return - V_111 ;
V_133 -> V_134 = 1 ;
F_83 ( V_1 ) ;
return 0 ;
}
static void F_87 ( struct V_132 * V_133 , int V_68 )
{
V_133 -> V_134 = 0 ;
}
int T_8 F_88 ( int (* F_80)( T_1 , const char * , int ) )
{
V_128 = F_80 ;
return F_89 ( 0 , 0 , & V_135 ) ;
}
static int F_90 ( struct V_1 * V_1 )
{
int V_52 ;
V_1 -> V_4 . V_2 = V_136 . V_137 ;
V_1 -> V_4 . V_18 = F_91 ( V_1 -> V_4 . V_2 , 0 , & V_135 , V_107 ) ;
if ( F_92 ( V_1 -> V_4 . V_18 ) ) {
V_52 = F_93 ( V_1 -> V_4 . V_18 ) ;
F_94 ( V_1 -> V_10 ,
L_3 , V_52 ) ;
V_1 -> V_4 . V_18 = NULL ;
return V_52 ;
}
F_52 ( & V_6 ) ;
V_136 . V_137 ++ ;
F_17 ( & V_1 -> V_4 . V_34 , & V_136 . V_138 ) ;
F_53 ( & V_6 ) ;
V_1 -> V_77 = true ;
if ( V_128 )
V_128 = NULL ;
F_44 ( V_1 , V_119 , 1 ) ;
return 0 ;
}
static T_4 F_95 ( struct V_22 * V_10 ,
struct V_139 * V_140 , char * V_141 )
{
struct V_1 * V_1 ;
V_1 = F_96 ( V_10 ) ;
return sprintf ( V_141 , L_4 , V_1 -> V_142 ) ;
}
static T_4 F_97 ( struct V_79 * V_80 , char T_5 * V_81 ,
T_3 V_82 , T_6 * V_83 )
{
struct V_1 * V_1 ;
char * V_27 ;
T_4 V_52 , V_143 , V_74 ;
V_74 = 1024 ;
V_27 = F_27 ( V_74 , V_44 ) ;
if ( ! V_27 )
return - V_90 ;
V_1 = V_80 -> V_84 ;
V_143 = 0 ;
V_143 += snprintf ( V_27 + V_143 , V_74 ,
L_5 , V_1 -> V_142 ? V_1 -> V_142 : L_6 ) ;
V_143 += snprintf ( V_27 + V_143 , V_74 - V_143 ,
L_7 , V_1 -> V_77 ) ;
V_143 += snprintf ( V_27 + V_143 , V_74 - V_143 ,
L_8 , V_1 -> V_78 ) ;
V_143 += snprintf ( V_27 + V_143 , V_74 - V_143 ,
L_9 , V_1 -> V_65 ) ;
V_143 += snprintf ( V_27 + V_143 , V_74 - V_143 ,
L_10 , V_1 -> V_50 . V_72 ) ;
V_143 += snprintf ( V_27 + V_143 , V_74 - V_143 ,
L_11 ,
V_1 -> V_50 . V_51 ) ;
V_143 += snprintf ( V_27 + V_143 , V_74 - V_143 ,
L_12 ,
V_1 -> V_50 . V_56 ) ;
V_143 += snprintf ( V_27 + V_143 , V_74 - V_143 ,
L_13 ,
F_10 ( V_1 ) ? L_14 : L_15 ) ;
V_143 += snprintf ( V_27 + V_143 , V_74 - V_143 ,
L_16 , V_1 -> V_4 . V_2 ) ;
V_52 = F_98 ( V_81 , V_82 , V_83 , V_27 , V_143 ) ;
F_16 ( V_27 ) ;
return V_52 ;
}
static void F_99 ( struct V_1 * V_1 , T_9 V_144 , T_9 V_145 )
{
if ( ! V_1 || ! F_10 ( V_1 ) )
return;
V_1 -> V_4 . V_131 . V_146 = V_144 ;
V_1 -> V_4 . V_131 . V_147 = V_145 ;
}
static unsigned int F_100 ( struct V_14 * V_15 , T_10 * V_148 )
{
struct V_26 * V_27 ;
unsigned int V_149 ;
int V_52 ;
V_149 = 0 ;
do {
V_27 = F_26 ( V_15 , V_107 , 0 ) ;
if ( ! V_27 )
break;
F_52 ( V_148 ) ;
V_52 = F_32 ( V_15 , V_27 ) ;
if ( V_52 < 0 ) {
F_53 ( V_148 ) ;
F_13 ( V_27 , true ) ;
break;
}
V_149 ++ ;
F_53 ( V_148 ) ;
} while ( V_52 > 0 );
return V_149 ;
}
static void F_101 ( struct V_1 * V_1 )
{
if ( V_1 -> V_127 && V_1 -> V_77 )
F_102 ( & V_1 -> V_127 , V_150 , V_151 ) ;
}
static int F_103 ( struct V_8 * V_9 , T_1 V_13 )
{
char V_152 [ 16 ] ;
struct V_1 * V_1 ;
struct V_26 * V_27 ;
T_2 V_153 ;
unsigned int V_149 ;
int V_55 ;
V_1 = F_27 ( sizeof( * V_1 ) , V_44 ) ;
if ( ! V_1 ) {
V_55 = - V_90 ;
goto V_45;
}
F_104 ( & V_1 -> V_120 ) ;
V_1 -> V_9 = V_9 ;
V_1 -> V_13 = V_13 ;
V_1 -> V_142 = NULL ;
V_1 -> V_49 = NULL ;
V_1 -> V_4 . V_18 = NULL ;
V_1 -> V_127 = NULL ;
V_1 -> V_4 . V_131 . V_146 = V_1 -> V_4 . V_131 . V_147 = 0 ;
V_1 -> V_78 = V_1 -> V_77 = false ;
V_1 -> V_50 = (struct V_154 ) { 0 } ;
V_1 -> V_65 = false ;
V_1 -> V_16 = V_9 -> V_155 [ V_1 -> V_13 ] ;
V_1 -> V_17 = V_9 -> V_156 [ V_1 -> V_13 ] ;
V_1 -> V_12 = F_105 () ;
if ( ! V_1 -> V_12 ) {
F_94 ( & V_1 -> V_9 -> V_20 -> V_10 , L_17 ) ;
V_55 = - V_90 ;
goto V_157;
}
V_1 -> V_12 -> V_100 = & V_158 ;
V_153 = F_106 ( V_9 -> V_159 , V_13 ) ;
V_55 = F_107 ( V_1 -> V_12 , V_153 , 1 ) ;
if ( V_55 < 0 ) {
F_94 ( & V_1 -> V_9 -> V_20 -> V_10 ,
L_18 , V_55 , V_13 ) ;
goto V_160;
}
V_1 -> V_10 = F_108 ( V_136 . V_161 , & V_1 -> V_9 -> V_20 -> V_10 ,
V_153 , V_1 , L_19 ,
V_1 -> V_9 -> V_20 -> V_162 , V_13 ) ;
if ( F_92 ( V_1 -> V_10 ) ) {
V_55 = F_93 ( V_1 -> V_10 ) ;
F_94 ( & V_1 -> V_9 -> V_20 -> V_10 ,
L_20 ,
V_55 , V_13 ) ;
goto V_160;
}
F_109 ( & V_1 -> V_57 ) ;
F_109 ( & V_1 -> V_70 ) ;
F_110 ( & V_1 -> V_88 ) ;
V_149 = F_100 ( V_1 -> V_16 , & V_1 -> V_57 ) ;
if ( ! V_149 ) {
F_94 ( V_1 -> V_10 , L_21 ) ;
V_55 = - V_90 ;
goto V_163;
}
if ( F_11 ( V_1 -> V_9 -> V_20 ) )
V_1 -> V_78 = true ;
else if ( ! F_12 ( V_1 -> V_9 ) ) {
V_55 = F_90 ( V_1 ) ;
if ( V_55 )
goto V_164;
}
F_52 ( & V_9 -> V_11 ) ;
F_17 ( & V_1 -> V_34 , & V_1 -> V_9 -> V_165 ) ;
F_53 ( & V_9 -> V_11 ) ;
F_44 ( V_1 , V_166 , 1 ) ;
if ( V_136 . V_167 ) {
sprintf ( V_152 , L_19 ,
V_1 -> V_9 -> V_20 -> V_162 , V_13 ) ;
V_1 -> V_168 = F_111 ( V_152 , 0444 ,
V_136 . V_167 ,
V_1 ,
& V_169 ) ;
}
return 0 ;
V_164:
while ( ( V_27 = F_112 ( V_1 -> V_16 ) ) )
F_13 ( V_27 , true ) ;
V_163:
F_113 ( V_136 . V_161 , V_1 -> V_10 -> V_153 ) ;
V_160:
F_114 ( V_1 -> V_12 ) ;
V_157:
F_16 ( V_1 ) ;
V_45:
F_39 ( V_9 , V_13 , V_166 , 0 ) ;
return V_55 ;
}
static void V_121 ( struct V_120 * V_120 )
{
struct V_1 * V_1 ;
V_1 = F_4 ( V_120 , struct V_1 , V_120 ) ;
F_115 ( & V_1 -> V_10 -> V_170 , & V_171 ) ;
F_113 ( V_136 . V_161 , V_1 -> V_10 -> V_153 ) ;
F_114 ( V_1 -> V_12 ) ;
F_16 ( V_1 -> V_142 ) ;
F_116 ( V_1 -> V_168 ) ;
F_16 ( V_1 ) ;
}
static void F_117 ( struct V_1 * V_1 )
{
struct V_26 * V_27 ;
F_36 ( V_1 ) ;
F_45 ( V_1 ) ;
while ( ( V_27 = F_112 ( V_1 -> V_16 ) ) )
F_13 ( V_27 , true ) ;
while ( ( V_27 = F_112 ( V_1 -> V_17 ) ) )
F_13 ( V_27 , true ) ;
}
static void F_118 ( struct V_1 * V_1 )
{
F_52 ( & V_1 -> V_9 -> V_11 ) ;
F_25 ( & V_1 -> V_34 ) ;
F_53 ( & V_1 -> V_9 -> V_11 ) ;
if ( V_1 -> V_77 ) {
V_1 -> V_77 = false ;
V_1 -> V_78 = false ;
F_119 ( & V_1 -> V_88 ) ;
F_101 ( V_1 ) ;
}
if ( F_10 ( V_1 ) ) {
F_52 ( & V_6 ) ;
F_25 ( & V_1 -> V_4 . V_34 ) ;
F_53 ( & V_6 ) ;
F_120 ( V_1 -> V_4 . V_18 ) ;
}
F_117 ( V_1 ) ;
V_1 -> V_9 = NULL ;
F_74 ( & V_1 -> V_120 , V_121 ) ;
}
static void F_121 ( struct V_8 * V_9 ,
struct V_26 * V_27 )
{
struct V_61 * V_62 ;
struct V_1 * V_1 ;
T_3 V_172 ;
int V_55 ;
V_62 = (struct V_61 * ) ( V_27 -> V_27 + V_27 -> V_48 ) ;
V_1 = F_8 ( V_9 , V_62 -> V_13 ) ;
if ( ! V_1 && V_62 -> V_59 != V_173 ) {
F_122 ( & V_9 -> V_20 -> V_10 ,
L_22 , V_62 -> V_13 ) ;
return;
}
switch ( V_62 -> V_59 ) {
case V_173 :
if ( V_1 ) {
F_122 ( & V_9 -> V_20 -> V_10 ,
L_23 , V_1 -> V_13 ) ;
F_44 ( V_1 , V_166 , 1 ) ;
break;
}
if ( V_62 -> V_13 >= V_9 -> V_174 . V_175 ) {
F_37 ( & V_9 -> V_20 -> V_10 ,
L_24 ,
V_62 -> V_13 , V_9 -> V_174 . V_175 - 1 ) ;
break;
}
F_103 ( V_9 , V_62 -> V_13 ) ;
break;
case V_176 :
F_118 ( V_1 ) ;
break;
case V_177 :
if ( ! V_62 -> V_60 )
break;
if ( F_10 ( V_1 ) )
break;
F_90 ( V_1 ) ;
F_123 ( & V_178 ) ;
break;
case V_179 : {
struct {
T_11 V_144 ;
T_11 V_145 ;
} V_36 ;
if ( ! F_10 ( V_1 ) )
break;
memcpy ( & V_36 , V_27 -> V_27 + V_27 -> V_48 + sizeof( * V_62 ) ,
sizeof( V_36 ) ) ;
F_99 ( V_1 , V_36 . V_144 , V_36 . V_145 ) ;
V_1 -> V_4 . V_18 -> V_134 = 1 ;
F_83 ( V_1 ) ;
break;
}
case V_119 :
V_1 -> V_78 = V_62 -> V_60 ;
F_119 ( & V_1 -> V_88 ) ;
F_52 ( & V_1 -> V_70 ) ;
F_45 ( V_1 ) ;
F_53 ( & V_1 -> V_70 ) ;
F_101 ( V_1 ) ;
break;
case V_180 :
if ( V_1 -> V_142 )
break;
V_172 = V_27 -> V_47 - V_27 -> V_48 - sizeof( * V_62 ) + 1 ;
V_1 -> V_142 = F_27 ( V_172 , V_44 ) ;
if ( ! V_1 -> V_142 ) {
F_94 ( V_1 -> V_10 ,
L_25 ) ;
break;
}
strncpy ( V_1 -> V_142 , V_27 -> V_27 + V_27 -> V_48 + sizeof( * V_62 ) ,
V_172 - 1 ) ;
V_1 -> V_142 [ V_172 - 1 ] = 0 ;
V_55 = F_124 ( & V_1 -> V_10 -> V_170 ,
& V_171 ) ;
if ( V_55 ) {
F_94 ( V_1 -> V_10 ,
L_26 ,
V_55 ) ;
} else {
F_125 ( & V_1 -> V_10 -> V_170 , V_181 ) ;
}
break;
}
}
static void F_126 ( struct V_182 * V_183 )
{
struct V_8 * V_9 ;
struct V_14 * V_15 ;
struct V_26 * V_27 ;
unsigned int V_47 ;
V_9 = F_4 ( V_183 , struct V_8 , V_184 ) ;
V_15 = V_9 -> V_185 ;
F_40 ( & V_9 -> V_186 ) ;
while ( ( V_27 = F_31 ( V_15 , & V_47 ) ) ) {
F_43 ( & V_9 -> V_186 ) ;
V_27 -> V_47 = V_47 ;
V_27 -> V_48 = 0 ;
F_121 ( V_9 , V_27 ) ;
F_40 ( & V_9 -> V_186 ) ;
if ( F_32 ( V_9 -> V_185 , V_27 ) < 0 ) {
F_37 ( & V_9 -> V_20 -> V_10 ,
L_27 ) ;
F_13 ( V_27 , false ) ;
}
}
F_43 ( & V_9 -> V_186 ) ;
}
static void F_127 ( struct V_14 * V_15 )
{
struct V_1 * V_1 ;
V_1 = F_9 ( V_15 -> V_20 -> V_187 , V_15 ) ;
if ( ! V_1 )
return;
F_119 ( & V_1 -> V_88 ) ;
}
static void F_128 ( struct V_14 * V_15 )
{
struct V_1 * V_1 ;
unsigned long V_5 ;
V_1 = F_9 ( V_15 -> V_20 -> V_187 , V_15 ) ;
if ( ! V_1 )
return;
F_2 ( & V_1 -> V_57 , V_5 ) ;
V_1 -> V_49 = F_30 ( V_1 ) ;
if ( ! V_1 -> V_77 && ! F_11 ( V_1 -> V_9 -> V_20 ) )
F_36 ( V_1 ) ;
F_5 ( & V_1 -> V_57 , V_5 ) ;
F_119 ( & V_1 -> V_88 ) ;
F_101 ( V_1 ) ;
if ( F_10 ( V_1 ) && F_129 ( V_1 -> V_4 . V_18 ) )
F_130 () ;
}
static void F_131 ( struct V_14 * V_15 )
{
struct V_8 * V_9 ;
V_9 = V_15 -> V_20 -> V_187 ;
F_132 ( & V_9 -> V_184 ) ;
}
static void F_133 ( struct V_19 * V_20 )
{
struct V_8 * V_9 ;
V_9 = V_20 -> V_187 ;
if ( ! F_12 ( V_9 ) ) {
struct V_1 * V_1 ;
T_9 V_144 , V_145 ;
V_20 -> V_174 -> V_188 ( V_20 ,
F_134 ( struct V_189 , V_145 ) ,
& V_145 , sizeof( T_9 ) ) ;
V_20 -> V_174 -> V_188 ( V_20 ,
F_134 ( struct V_189 , V_144 ) ,
& V_144 , sizeof( T_9 ) ) ;
V_1 = F_8 ( V_9 , 0 ) ;
F_99 ( V_1 , V_144 , V_145 ) ;
F_83 ( V_1 ) ;
}
}
static int F_135 ( struct V_8 * V_9 )
{
T_12 * * V_190 ;
char * * V_191 ;
struct V_14 * * V_192 ;
T_1 V_29 , V_193 , V_194 , V_195 ;
int V_55 ;
V_194 = V_9 -> V_174 . V_175 ;
V_195 = F_12 ( V_9 ) ? ( V_194 + 1 ) * 2 : 2 ;
V_192 = F_27 ( V_195 * sizeof( struct V_14 * ) , V_44 ) ;
V_190 = F_27 ( V_195 * sizeof( T_12 * ) , V_44 ) ;
V_191 = F_27 ( V_195 * sizeof( char * ) , V_44 ) ;
V_9 -> V_155 = F_27 ( V_194 * sizeof( struct V_14 * ) ,
V_44 ) ;
V_9 -> V_156 = F_27 ( V_194 * sizeof( struct V_14 * ) ,
V_44 ) ;
if ( ! V_192 || ! V_190 || ! V_191 || ! V_9 -> V_155 ||
! V_9 -> V_156 ) {
V_55 = - V_90 ;
goto free;
}
V_193 = 0 ;
V_190 [ V_193 ] = F_128 ;
V_190 [ V_193 + 1 ] = F_127 ;
V_191 [ V_193 ] = L_28 ;
V_191 [ V_193 + 1 ] = L_29 ;
V_193 += 2 ;
if ( F_12 ( V_9 ) ) {
V_190 [ V_193 ] = F_131 ;
V_190 [ V_193 + 1 ] = NULL ;
V_191 [ V_193 ] = L_30 ;
V_191 [ V_193 + 1 ] = L_31 ;
for ( V_29 = 1 ; V_29 < V_194 ; V_29 ++ ) {
V_193 += 2 ;
V_190 [ V_193 ] = F_128 ;
V_190 [ V_193 + 1 ] = F_127 ;
V_191 [ V_193 ] = L_28 ;
V_191 [ V_193 + 1 ] = L_29 ;
}
}
V_55 = V_9 -> V_20 -> V_174 -> V_196 ( V_9 -> V_20 , V_195 , V_192 ,
V_190 ,
( const char * * ) V_191 ) ;
if ( V_55 )
goto free;
V_193 = 0 ;
V_9 -> V_155 [ 0 ] = V_192 [ 0 ] ;
V_9 -> V_156 [ 0 ] = V_192 [ 1 ] ;
V_193 += 2 ;
if ( F_12 ( V_9 ) ) {
V_9 -> V_185 = V_192 [ V_193 ] ;
V_9 -> V_63 = V_192 [ V_193 + 1 ] ;
for ( V_29 = 1 ; V_29 < V_194 ; V_29 ++ ) {
V_193 += 2 ;
V_9 -> V_155 [ V_29 ] = V_192 [ V_193 ] ;
V_9 -> V_156 [ V_29 ] = V_192 [ V_193 + 1 ] ;
}
}
F_16 ( V_191 ) ;
F_16 ( V_190 ) ;
F_16 ( V_192 ) ;
return 0 ;
free:
F_16 ( V_9 -> V_156 ) ;
F_16 ( V_9 -> V_155 ) ;
F_16 ( V_191 ) ;
F_16 ( V_190 ) ;
F_16 ( V_192 ) ;
return V_55 ;
}
static void F_136 ( struct V_8 * V_9 )
{
V_9 -> V_20 -> V_174 -> V_197 ( V_9 -> V_20 ) ;
F_16 ( V_9 -> V_155 ) ;
F_16 ( V_9 -> V_156 ) ;
}
static void F_137 ( struct V_8 * V_9 )
{
struct V_26 * V_27 ;
unsigned int V_47 ;
if ( ! F_12 ( V_9 ) )
return;
while ( ( V_27 = F_31 ( V_9 -> V_185 , & V_47 ) ) )
F_13 ( V_27 , true ) ;
while ( ( V_27 = F_112 ( V_9 -> V_185 ) ) )
F_13 ( V_27 , true ) ;
}
static int F_138 ( struct V_19 * V_20 )
{
struct V_8 * V_9 ;
int V_55 ;
bool V_198 ;
bool V_199 = V_128 != NULL ;
F_139 () ;
V_9 = F_27 ( sizeof( * V_9 ) , V_44 ) ;
if ( ! V_9 ) {
V_55 = - V_90 ;
goto V_45;
}
V_9 -> V_20 = V_20 ;
V_20 -> V_187 = V_9 ;
V_9 -> V_159 = F_140 ( 0 , L_32 ,
& V_200 ) ;
if ( V_9 -> V_159 < 0 ) {
F_94 ( & V_20 -> V_10 ,
L_33 ,
V_9 -> V_159 , V_20 -> V_162 ) ;
V_55 = V_9 -> V_159 ;
goto free;
}
V_198 = false ;
V_9 -> V_174 . V_175 = 1 ;
if ( ! F_11 ( V_20 ) &&
F_141 ( V_20 , V_25 ,
F_134 ( struct V_189 ,
V_175 ) ,
& V_9 -> V_174 . V_175 ) == 0 ) {
V_198 = true ;
}
V_55 = F_135 ( V_9 ) ;
if ( V_55 < 0 ) {
F_94 ( & V_20 -> V_10 , L_34 , V_55 ) ;
goto V_201;
}
F_109 ( & V_9 -> V_11 ) ;
F_142 ( & V_9 -> V_165 ) ;
if ( V_198 ) {
unsigned int V_149 ;
F_109 ( & V_9 -> V_186 ) ;
F_109 ( & V_9 -> V_64 ) ;
F_143 ( & V_9 -> V_184 , & F_126 ) ;
V_149 = F_100 ( V_9 -> V_185 ,
& V_9 -> V_186 ) ;
if ( ! V_149 ) {
F_94 ( & V_20 -> V_10 ,
L_35 ) ;
V_55 = - V_90 ;
goto V_202;
}
} else {
F_103 ( V_9 , 0 ) ;
}
F_52 ( & V_6 ) ;
F_17 ( & V_9 -> V_34 , & V_136 . V_203 ) ;
F_53 ( & V_6 ) ;
F_39 ( V_9 , V_204 ,
V_205 , 1 ) ;
if ( V_198 && V_199 )
F_144 ( & V_178 ) ;
return 0 ;
V_202:
F_39 ( V_9 , V_204 ,
V_205 , 0 ) ;
F_136 ( V_9 ) ;
V_201:
F_145 ( V_9 -> V_159 , L_32 ) ;
free:
F_16 ( V_9 ) ;
V_45:
return V_55 ;
}
static void F_146 ( struct V_19 * V_20 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 , * V_206 ;
V_9 = V_20 -> V_187 ;
F_52 ( & V_6 ) ;
F_25 ( & V_9 -> V_34 ) ;
F_53 ( & V_6 ) ;
V_20 -> V_174 -> V_207 ( V_20 ) ;
if ( F_12 ( V_9 ) )
F_147 ( & V_9 -> V_184 ) ;
F_24 (port, port2, &portdev->ports, list)
F_118 ( V_1 ) ;
F_145 ( V_9 -> V_159 , L_32 ) ;
F_137 ( V_9 ) ;
F_136 ( V_9 ) ;
F_16 ( V_9 ) ;
}
static int F_148 ( struct V_19 * V_20 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
V_9 = V_20 -> V_187 ;
V_20 -> V_174 -> V_207 ( V_20 ) ;
F_149 ( V_9 -> V_185 ) ;
F_147 ( & V_9 -> V_184 ) ;
F_149 ( V_9 -> V_185 ) ;
F_137 ( V_9 ) ;
F_3 (port, &portdev->ports, list) {
F_149 ( V_1 -> V_16 ) ;
F_149 ( V_1 -> V_17 ) ;
V_1 -> V_78 = false ;
F_117 ( V_1 ) ;
}
F_136 ( V_9 ) ;
return 0 ;
}
static int F_150 ( struct V_19 * V_20 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
int V_52 ;
V_9 = V_20 -> V_187 ;
V_52 = F_135 ( V_9 ) ;
if ( V_52 )
return V_52 ;
if ( F_12 ( V_9 ) )
F_100 ( V_9 -> V_185 , & V_9 -> V_186 ) ;
F_3 (port, &portdev->ports, list) {
V_1 -> V_16 = V_9 -> V_155 [ V_1 -> V_13 ] ;
V_1 -> V_17 = V_9 -> V_156 [ V_1 -> V_13 ] ;
F_100 ( V_1 -> V_16 , & V_1 -> V_57 ) ;
F_44 ( V_1 , V_166 , 1 ) ;
if ( V_1 -> V_77 )
F_44 ( V_1 , V_119 , 1 ) ;
}
return 0 ;
}
static int T_8 F_151 ( void )
{
int V_55 ;
V_136 . V_161 = F_152 ( V_208 , L_36 ) ;
if ( F_92 ( V_136 . V_161 ) ) {
V_55 = F_93 ( V_136 . V_161 ) ;
F_153 ( L_37 , V_55 ) ;
return V_55 ;
}
V_136 . V_167 = F_154 ( L_36 , NULL ) ;
if ( ! V_136 . V_167 ) {
F_155 ( L_38 ,
F_93 ( V_136 . V_167 ) ) ;
}
F_142 ( & V_136 . V_138 ) ;
F_142 ( & V_136 . V_203 ) ;
V_55 = F_156 ( & V_209 ) ;
if ( V_55 < 0 ) {
F_153 ( L_39 , V_55 ) ;
goto free;
}
V_55 = F_156 ( & V_210 ) ;
if ( V_55 < 0 ) {
F_153 ( L_40 ,
V_55 ) ;
goto V_211;
}
return 0 ;
V_211:
F_157 ( & V_209 ) ;
free:
if ( V_136 . V_167 )
F_158 ( V_136 . V_167 ) ;
F_159 ( V_136 . V_161 ) ;
return V_55 ;
}
static void T_13 F_160 ( void )
{
F_20 () ;
F_157 ( & V_209 ) ;
F_157 ( & V_210 ) ;
F_159 ( V_136 . V_161 ) ;
if ( V_136 . V_167 )
F_158 ( V_136 . V_167 ) ;
}
