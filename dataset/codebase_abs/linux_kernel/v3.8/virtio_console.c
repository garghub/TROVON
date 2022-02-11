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
V_52 = F_34 ( V_15 , V_32 , 0 , 1 , V_27 , V_53 ) ;
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
if ( F_34 ( V_15 , V_32 , 1 , 0 , & V_62 , V_53 ) == 0 ) {
F_35 ( V_15 ) ;
while ( ! F_31 ( V_15 , & V_47 ) )
F_40 () ;
}
return 0 ;
}
static T_4 F_41 ( struct V_1 * V_1 , unsigned int V_59 ,
unsigned int V_60 )
{
if ( V_1 -> V_9 )
return F_39 ( V_1 -> V_9 , V_1 -> V_13 , V_59 , V_60 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_1 )
{
struct V_26 * V_27 ;
unsigned int V_47 ;
if ( ! V_1 -> V_9 ) {
return;
}
while ( ( V_27 = F_31 ( V_1 -> V_17 , & V_47 ) ) ) {
F_13 ( V_27 , false ) ;
V_1 -> V_64 = false ;
}
}
static T_4 F_43 ( struct V_1 * V_1 , struct V_43 * V_32 ,
int V_65 , T_3 V_66 ,
void * V_67 , bool V_68 )
{
struct V_14 * V_17 ;
int V_55 ;
unsigned long V_5 ;
unsigned int V_47 ;
V_17 = V_1 -> V_17 ;
F_2 ( & V_1 -> V_69 , V_5 ) ;
F_42 ( V_1 ) ;
V_55 = F_34 ( V_17 , V_32 , V_65 , 0 , V_67 , V_53 ) ;
F_35 ( V_17 ) ;
if ( V_55 ) {
V_66 = 0 ;
goto V_70;
}
if ( V_17 -> V_54 == 0 )
V_1 -> V_64 = true ;
if ( V_68 )
goto V_70;
while ( ! F_31 ( V_17 , & V_47 ) )
F_40 () ;
V_70:
F_5 ( & V_1 -> V_69 , V_5 ) ;
V_1 -> V_50 . V_71 += V_66 ;
return V_66 ;
}
static T_4 F_44 ( struct V_1 * V_1 , char * V_72 , T_3 V_73 ,
bool V_74 )
{
struct V_26 * V_27 ;
unsigned long V_5 ;
if ( ! V_73 || ! F_38 ( V_1 ) )
return 0 ;
V_27 = V_1 -> V_49 ;
V_73 = F_45 ( V_73 , V_27 -> V_47 - V_27 -> V_48 ) ;
if ( V_74 ) {
T_4 V_52 ;
V_52 = F_46 ( V_72 , V_27 -> V_27 + V_27 -> V_48 , V_73 ) ;
if ( V_52 )
return - V_75 ;
} else {
memcpy ( V_72 , V_27 -> V_27 + V_27 -> V_48 , V_73 ) ;
}
V_27 -> V_48 += V_73 ;
if ( V_27 -> V_48 == V_27 -> V_47 ) {
F_2 ( & V_1 -> V_57 , V_5 ) ;
V_1 -> V_49 = NULL ;
if ( F_32 ( V_1 -> V_16 , V_27 ) < 0 )
F_37 ( V_1 -> V_10 , L_2 ) ;
F_5 ( & V_1 -> V_57 , V_5 ) ;
}
return V_73 ;
}
static bool F_47 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_76 ) {
return false ;
}
return ! F_38 ( V_1 ) && V_1 -> V_77 ;
}
static bool F_48 ( struct V_1 * V_1 )
{
bool V_52 ;
if ( ! V_1 -> V_76 ) {
return false ;
}
if ( ! V_1 -> V_77 )
return true ;
F_49 ( & V_1 -> V_69 ) ;
F_42 ( V_1 ) ;
V_52 = V_1 -> V_64 ;
F_50 ( & V_1 -> V_69 ) ;
return V_52 ;
}
static T_4 F_51 ( struct V_78 * V_79 , char T_5 * V_80 ,
T_3 V_81 , T_6 * V_82 )
{
struct V_1 * V_1 ;
T_4 V_52 ;
V_1 = V_79 -> V_83 ;
if ( ! F_38 ( V_1 ) ) {
if ( ! V_1 -> V_77 )
return 0 ;
if ( V_79 -> V_84 & V_85 )
return - V_86 ;
V_52 = F_52 ( V_1 -> V_87 ,
! F_47 ( V_1 ) ) ;
if ( V_52 < 0 )
return V_52 ;
}
if ( ! V_1 -> V_76 )
return - V_88 ;
if ( ! F_38 ( V_1 ) && ! V_1 -> V_77 )
return 0 ;
return F_44 ( V_1 , V_80 , V_81 , true ) ;
}
static int F_53 ( struct V_1 * V_1 , bool V_68 )
{
int V_52 ;
if ( F_48 ( V_1 ) ) {
if ( V_68 )
return - V_86 ;
V_52 = F_52 ( V_1 -> V_87 ,
! F_48 ( V_1 ) ) ;
if ( V_52 < 0 )
return V_52 ;
}
if ( ! V_1 -> V_76 )
return - V_88 ;
return 0 ;
}
static T_4 F_54 ( struct V_78 * V_79 , const char T_5 * V_80 ,
T_3 V_81 , T_6 * V_82 )
{
struct V_1 * V_1 ;
struct V_26 * V_27 ;
T_4 V_52 ;
bool V_68 ;
struct V_43 V_32 [ 1 ] ;
if ( ! V_81 )
return 0 ;
V_1 = V_79 -> V_83 ;
V_68 = V_79 -> V_84 & V_85 ;
V_52 = F_53 ( V_1 , V_68 ) ;
if ( V_52 < 0 )
return V_52 ;
V_81 = F_45 ( ( T_3 ) ( 32 * 1024 ) , V_81 ) ;
V_27 = F_26 ( V_1 -> V_17 , V_81 , 0 ) ;
if ( ! V_27 )
return - V_89 ;
V_52 = F_55 ( V_27 -> V_27 , V_80 , V_81 ) ;
if ( V_52 ) {
V_52 = - V_75 ;
goto F_13;
}
V_68 = true ;
F_33 ( V_32 , V_27 -> V_27 , V_81 ) ;
V_52 = F_43 ( V_1 , V_32 , 1 , V_81 , V_27 , V_68 ) ;
if ( V_68 && V_52 > 0 )
goto V_7;
F_13:
F_13 ( V_27 , true ) ;
V_7:
return V_52 ;
}
static int F_56 ( struct V_90 * V_91 , struct V_92 * V_27 ,
struct V_93 * V_94 )
{
struct V_95 * V_96 = V_94 -> V_97 . V_67 ;
unsigned int V_48 , V_47 ;
if ( V_96 -> V_98 == V_96 -> V_36 )
return 0 ;
if ( V_27 -> V_99 -> V_100 ( V_91 , V_27 ) == 0 ) {
F_57 ( V_27 -> V_31 ) ;
F_58 ( V_27 -> V_31 ) ;
V_47 = F_45 ( V_27 -> V_47 , V_94 -> V_47 ) ;
F_59 ( & ( V_96 -> V_32 [ V_96 -> V_98 ] ) , V_27 -> V_31 , V_47 , V_27 -> V_48 ) ;
} else {
struct V_31 * V_31 = F_60 ( V_44 ) ;
char * V_101 = V_27 -> V_99 -> V_102 ( V_91 , V_27 , 1 ) ;
char * V_103 ;
if ( ! V_31 )
return - V_89 ;
V_103 = F_61 ( V_31 ) ;
V_48 = V_94 -> V_104 & ~ V_105 ;
V_47 = V_94 -> V_47 ;
if ( V_47 + V_48 > V_106 )
V_47 = V_106 - V_48 ;
memcpy ( V_103 + V_48 , V_101 + V_27 -> V_48 , V_47 ) ;
F_62 ( V_31 ) ;
V_27 -> V_99 -> V_107 ( V_91 , V_27 , V_101 ) ;
F_59 ( & ( V_96 -> V_32 [ V_96 -> V_98 ] ) , V_31 , V_47 , V_48 ) ;
}
V_96 -> V_98 ++ ;
V_96 -> V_47 += V_47 ;
return V_47 ;
}
static T_4 F_63 ( struct V_90 * V_91 ,
struct V_78 * V_79 , T_6 * V_108 ,
T_3 V_47 , unsigned int V_5 )
{
struct V_1 * V_1 = V_79 -> V_83 ;
struct V_95 V_96 ;
T_4 V_52 ;
struct V_26 * V_27 ;
struct V_93 V_94 = {
. V_109 = V_47 ,
. V_5 = V_5 ,
. V_104 = * V_108 ,
. V_97 . V_67 = & V_96 ,
} ;
if ( F_11 ( V_1 -> V_17 -> V_20 ) )
return - V_110 ;
V_52 = F_53 ( V_1 , V_79 -> V_84 & V_85 ) ;
if ( V_52 < 0 )
return V_52 ;
V_27 = F_26 ( V_1 -> V_17 , 0 , V_91 -> V_111 ) ;
if ( ! V_27 )
return - V_89 ;
V_96 . V_98 = 0 ;
V_96 . V_47 = 0 ;
V_96 . V_36 = V_91 -> V_111 ;
V_96 . V_32 = V_27 -> V_32 ;
F_64 ( V_96 . V_32 , V_96 . V_36 ) ;
V_52 = F_65 ( V_91 , & V_94 , F_56 ) ;
if ( F_66 ( V_52 > 0 ) )
V_52 = F_43 ( V_1 , V_27 -> V_32 , V_96 . V_98 , V_96 . V_47 , V_27 , true ) ;
if ( F_67 ( V_52 <= 0 ) )
F_13 ( V_27 , true ) ;
return V_52 ;
}
static unsigned int F_68 ( struct V_78 * V_79 , T_7 * V_112 )
{
struct V_1 * V_1 ;
unsigned int V_52 ;
V_1 = V_79 -> V_83 ;
F_69 ( V_79 , & V_1 -> V_87 , V_112 ) ;
if ( ! V_1 -> V_76 ) {
return V_113 ;
}
V_52 = 0 ;
if ( ! F_47 ( V_1 ) )
V_52 |= V_114 | V_115 ;
if ( ! F_48 ( V_1 ) )
V_52 |= V_116 ;
if ( ! V_1 -> V_77 )
V_52 |= V_113 ;
return V_52 ;
}
static int F_70 ( struct V_117 * V_117 , struct V_78 * V_79 )
{
struct V_1 * V_1 ;
V_1 = V_79 -> V_83 ;
F_41 ( V_1 , V_118 , 0 ) ;
F_49 ( & V_1 -> V_57 ) ;
V_1 -> V_76 = false ;
F_36 ( V_1 ) ;
F_50 ( & V_1 -> V_57 ) ;
F_49 ( & V_1 -> V_69 ) ;
F_42 ( V_1 ) ;
F_50 ( & V_1 -> V_69 ) ;
F_20 () ;
F_71 ( & V_1 -> V_119 , V_120 ) ;
return 0 ;
}
static int F_72 ( struct V_117 * V_117 , struct V_78 * V_79 )
{
struct V_12 * V_12 = V_117 -> V_121 ;
struct V_1 * V_1 ;
int V_52 ;
V_1 = F_7 ( V_12 -> V_10 ) ;
V_79 -> V_83 = V_1 ;
F_49 ( & V_1 -> V_9 -> V_11 ) ;
F_73 ( & V_1 -> V_119 ) ;
F_50 ( & V_1 -> V_9 -> V_11 ) ;
if ( F_10 ( V_1 ) ) {
V_52 = - V_122 ;
goto V_7;
}
F_49 ( & V_1 -> V_57 ) ;
if ( V_1 -> V_76 ) {
F_50 ( & V_1 -> V_57 ) ;
V_52 = - V_123 ;
goto V_7;
}
V_1 -> V_76 = true ;
F_50 ( & V_1 -> V_57 ) ;
F_49 ( & V_1 -> V_69 ) ;
F_42 ( V_1 ) ;
F_50 ( & V_1 -> V_69 ) ;
F_74 ( V_117 , V_79 ) ;
F_41 ( V_79 -> V_83 , V_118 , 1 ) ;
return 0 ;
V_7:
F_71 ( & V_1 -> V_119 , V_120 ) ;
return V_52 ;
}
static int F_75 ( int V_124 , struct V_78 * V_79 , int V_125 )
{
struct V_1 * V_1 ;
V_1 = V_79 -> V_83 ;
return F_76 ( V_124 , V_79 , V_125 , & V_1 -> V_126 ) ;
}
static int F_77 ( T_1 V_2 , const char * V_27 , int V_81 )
{
struct V_1 * V_1 ;
struct V_43 V_32 [ 1 ] ;
if ( F_67 ( V_127 ) )
return V_127 ( V_2 , V_27 , V_81 ) ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_128 ;
F_33 ( V_32 , V_27 , V_81 ) ;
return F_43 ( V_1 , V_32 , 1 , V_81 , ( void * ) V_27 , false ) ;
}
static int F_78 ( T_1 V_2 , char * V_27 , int V_81 )
{
struct V_1 * V_1 ;
if ( F_67 ( V_127 ) )
return 0 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_128 ;
F_79 ( ! V_1 -> V_16 ) ;
return F_44 ( V_1 , V_27 , V_81 , false ) ;
}
static void F_80 ( struct V_1 * V_1 )
{
struct V_19 * V_20 ;
if ( ! V_1 || ! F_10 ( V_1 ) )
return;
V_20 = V_1 -> V_9 -> V_20 ;
if ( ! F_11 ( V_20 ) &&
F_81 ( V_20 , V_129 ) )
F_82 ( V_1 -> V_4 . V_18 , V_1 -> V_4 . V_130 ) ;
}
static int F_83 ( struct V_131 * V_132 , int V_67 )
{
struct V_1 * V_1 ;
V_1 = F_1 ( V_132 -> V_2 ) ;
if ( ! V_1 )
return - V_110 ;
V_132 -> V_133 = 1 ;
F_80 ( V_1 ) ;
return 0 ;
}
static void F_84 ( struct V_131 * V_132 , int V_67 )
{
V_132 -> V_133 = 0 ;
}
int T_8 F_85 ( int (* F_77)( T_1 , const char * , int ) )
{
V_127 = F_77 ;
return F_86 ( 0 , 0 , & V_134 ) ;
}
int F_87 ( struct V_1 * V_1 )
{
int V_52 ;
V_1 -> V_4 . V_2 = V_135 . V_136 ;
V_1 -> V_4 . V_18 = F_88 ( V_1 -> V_4 . V_2 , 0 , & V_134 , V_106 ) ;
if ( F_89 ( V_1 -> V_4 . V_18 ) ) {
V_52 = F_90 ( V_1 -> V_4 . V_18 ) ;
F_91 ( V_1 -> V_10 ,
L_3 , V_52 ) ;
V_1 -> V_4 . V_18 = NULL ;
return V_52 ;
}
F_49 ( & V_6 ) ;
V_135 . V_136 ++ ;
F_17 ( & V_1 -> V_4 . V_34 , & V_135 . V_137 ) ;
F_50 ( & V_6 ) ;
V_1 -> V_76 = true ;
if ( V_127 )
V_127 = NULL ;
F_41 ( V_1 , V_118 , 1 ) ;
return 0 ;
}
static T_4 F_92 ( struct V_22 * V_10 ,
struct V_138 * V_139 , char * V_140 )
{
struct V_1 * V_1 ;
V_1 = F_93 ( V_10 ) ;
return sprintf ( V_140 , L_4 , V_1 -> V_141 ) ;
}
static T_4 F_94 ( struct V_78 * V_79 , char T_5 * V_80 ,
T_3 V_81 , T_6 * V_82 )
{
struct V_1 * V_1 ;
char * V_27 ;
T_4 V_52 , V_142 , V_73 ;
V_73 = 1024 ;
V_27 = F_27 ( V_73 , V_44 ) ;
if ( ! V_27 )
return - V_89 ;
V_1 = V_79 -> V_83 ;
V_142 = 0 ;
V_142 += snprintf ( V_27 + V_142 , V_73 ,
L_5 , V_1 -> V_141 ? V_1 -> V_141 : L_6 ) ;
V_142 += snprintf ( V_27 + V_142 , V_73 - V_142 ,
L_7 , V_1 -> V_76 ) ;
V_142 += snprintf ( V_27 + V_142 , V_73 - V_142 ,
L_8 , V_1 -> V_77 ) ;
V_142 += snprintf ( V_27 + V_142 , V_73 - V_142 ,
L_9 , V_1 -> V_64 ) ;
V_142 += snprintf ( V_27 + V_142 , V_73 - V_142 ,
L_10 , V_1 -> V_50 . V_71 ) ;
V_142 += snprintf ( V_27 + V_142 , V_73 - V_142 ,
L_11 ,
V_1 -> V_50 . V_51 ) ;
V_142 += snprintf ( V_27 + V_142 , V_73 - V_142 ,
L_12 ,
V_1 -> V_50 . V_56 ) ;
V_142 += snprintf ( V_27 + V_142 , V_73 - V_142 ,
L_13 ,
F_10 ( V_1 ) ? L_14 : L_15 ) ;
V_142 += snprintf ( V_27 + V_142 , V_73 - V_142 ,
L_16 , V_1 -> V_4 . V_2 ) ;
V_52 = F_95 ( V_80 , V_81 , V_82 , V_27 , V_142 ) ;
F_16 ( V_27 ) ;
return V_52 ;
}
static void F_96 ( struct V_1 * V_1 , T_9 V_143 , T_9 V_144 )
{
if ( ! V_1 || ! F_10 ( V_1 ) )
return;
V_1 -> V_4 . V_130 . V_145 = V_143 ;
V_1 -> V_4 . V_130 . V_146 = V_144 ;
}
static unsigned int F_97 ( struct V_14 * V_15 , T_10 * V_147 )
{
struct V_26 * V_27 ;
unsigned int V_148 ;
int V_52 ;
V_148 = 0 ;
do {
V_27 = F_26 ( V_15 , V_106 , 0 ) ;
if ( ! V_27 )
break;
F_49 ( V_147 ) ;
V_52 = F_32 ( V_15 , V_27 ) ;
if ( V_52 < 0 ) {
F_50 ( V_147 ) ;
F_13 ( V_27 , true ) ;
break;
}
V_148 ++ ;
F_50 ( V_147 ) ;
} while ( V_52 > 0 );
return V_148 ;
}
static void F_98 ( struct V_1 * V_1 )
{
if ( V_1 -> V_126 && V_1 -> V_76 )
F_99 ( & V_1 -> V_126 , V_149 , V_150 ) ;
}
static int F_100 ( struct V_8 * V_9 , T_1 V_13 )
{
char V_151 [ 16 ] ;
struct V_1 * V_1 ;
struct V_26 * V_27 ;
T_2 V_152 ;
unsigned int V_148 ;
int V_55 ;
V_1 = F_27 ( sizeof( * V_1 ) , V_44 ) ;
if ( ! V_1 ) {
V_55 = - V_89 ;
goto V_45;
}
F_101 ( & V_1 -> V_119 ) ;
V_1 -> V_9 = V_9 ;
V_1 -> V_13 = V_13 ;
V_1 -> V_141 = NULL ;
V_1 -> V_49 = NULL ;
V_1 -> V_4 . V_18 = NULL ;
V_1 -> V_126 = NULL ;
V_1 -> V_4 . V_130 . V_145 = V_1 -> V_4 . V_130 . V_146 = 0 ;
V_1 -> V_77 = V_1 -> V_76 = false ;
V_1 -> V_50 = (struct V_153 ) { 0 } ;
V_1 -> V_64 = false ;
V_1 -> V_16 = V_9 -> V_154 [ V_1 -> V_13 ] ;
V_1 -> V_17 = V_9 -> V_155 [ V_1 -> V_13 ] ;
V_1 -> V_12 = F_102 () ;
if ( ! V_1 -> V_12 ) {
F_91 ( & V_1 -> V_9 -> V_20 -> V_10 , L_17 ) ;
V_55 = - V_89 ;
goto V_156;
}
V_1 -> V_12 -> V_99 = & V_157 ;
V_152 = F_103 ( V_9 -> V_158 , V_13 ) ;
V_55 = F_104 ( V_1 -> V_12 , V_152 , 1 ) ;
if ( V_55 < 0 ) {
F_91 ( & V_1 -> V_9 -> V_20 -> V_10 ,
L_18 , V_55 , V_13 ) ;
goto V_159;
}
V_1 -> V_10 = F_105 ( V_135 . V_160 , & V_1 -> V_9 -> V_20 -> V_10 ,
V_152 , V_1 , L_19 ,
V_1 -> V_9 -> V_161 , V_13 ) ;
if ( F_89 ( V_1 -> V_10 ) ) {
V_55 = F_90 ( V_1 -> V_10 ) ;
F_91 ( & V_1 -> V_9 -> V_20 -> V_10 ,
L_20 ,
V_55 , V_13 ) ;
goto V_159;
}
F_106 ( & V_1 -> V_57 ) ;
F_106 ( & V_1 -> V_69 ) ;
F_107 ( & V_1 -> V_87 ) ;
V_148 = F_97 ( V_1 -> V_16 , & V_1 -> V_57 ) ;
if ( ! V_148 ) {
F_91 ( V_1 -> V_10 , L_21 ) ;
V_55 = - V_89 ;
goto V_162;
}
if ( F_11 ( V_1 -> V_9 -> V_20 ) )
V_1 -> V_77 = true ;
else if ( ! F_12 ( V_1 -> V_9 ) ) {
V_55 = F_87 ( V_1 ) ;
if ( V_55 )
goto V_163;
}
F_49 ( & V_9 -> V_11 ) ;
F_17 ( & V_1 -> V_34 , & V_1 -> V_9 -> V_164 ) ;
F_50 ( & V_9 -> V_11 ) ;
F_41 ( V_1 , V_165 , 1 ) ;
if ( V_135 . V_166 ) {
sprintf ( V_151 , L_19 ,
V_1 -> V_9 -> V_161 , V_13 ) ;
V_1 -> V_167 = F_108 ( V_151 , 0444 ,
V_135 . V_166 ,
V_1 ,
& V_168 ) ;
}
return 0 ;
V_163:
while ( ( V_27 = F_109 ( V_1 -> V_16 ) ) )
F_13 ( V_27 , true ) ;
V_162:
F_110 ( V_135 . V_160 , V_1 -> V_10 -> V_152 ) ;
V_159:
F_111 ( V_1 -> V_12 ) ;
V_156:
F_16 ( V_1 ) ;
V_45:
F_39 ( V_9 , V_13 , V_165 , 0 ) ;
return V_55 ;
}
static void V_120 ( struct V_119 * V_119 )
{
struct V_1 * V_1 ;
V_1 = F_4 ( V_119 , struct V_1 , V_119 ) ;
F_112 ( & V_1 -> V_10 -> V_169 , & V_170 ) ;
F_110 ( V_135 . V_160 , V_1 -> V_10 -> V_152 ) ;
F_111 ( V_1 -> V_12 ) ;
F_16 ( V_1 -> V_141 ) ;
F_113 ( V_1 -> V_167 ) ;
F_16 ( V_1 ) ;
}
static void F_114 ( struct V_1 * V_1 )
{
struct V_26 * V_27 ;
F_36 ( V_1 ) ;
F_42 ( V_1 ) ;
while ( ( V_27 = F_109 ( V_1 -> V_16 ) ) )
F_13 ( V_27 , true ) ;
while ( ( V_27 = F_109 ( V_1 -> V_17 ) ) )
F_13 ( V_27 , true ) ;
}
static void F_115 ( struct V_1 * V_1 )
{
F_49 ( & V_1 -> V_9 -> V_11 ) ;
F_25 ( & V_1 -> V_34 ) ;
F_50 ( & V_1 -> V_9 -> V_11 ) ;
if ( V_1 -> V_76 ) {
V_1 -> V_76 = false ;
V_1 -> V_77 = false ;
F_116 ( & V_1 -> V_87 ) ;
F_98 ( V_1 ) ;
}
if ( F_10 ( V_1 ) ) {
F_49 ( & V_6 ) ;
F_25 ( & V_1 -> V_4 . V_34 ) ;
F_50 ( & V_6 ) ;
F_117 ( V_1 -> V_4 . V_18 ) ;
}
F_114 ( V_1 ) ;
V_1 -> V_9 = NULL ;
F_71 ( & V_1 -> V_119 , V_120 ) ;
}
static void F_118 ( struct V_8 * V_9 ,
struct V_26 * V_27 )
{
struct V_61 * V_62 ;
struct V_1 * V_1 ;
T_3 V_171 ;
int V_55 ;
V_62 = (struct V_61 * ) ( V_27 -> V_27 + V_27 -> V_48 ) ;
V_1 = F_8 ( V_9 , V_62 -> V_13 ) ;
if ( ! V_1 && V_62 -> V_59 != V_172 ) {
F_119 ( & V_9 -> V_20 -> V_10 ,
L_22 , V_62 -> V_13 ) ;
return;
}
switch ( V_62 -> V_59 ) {
case V_172 :
if ( V_1 ) {
F_119 ( & V_9 -> V_20 -> V_10 ,
L_23 , V_1 -> V_13 ) ;
F_41 ( V_1 , V_165 , 1 ) ;
break;
}
if ( V_62 -> V_13 >= V_9 -> V_173 . V_174 ) {
F_37 ( & V_9 -> V_20 -> V_10 ,
L_24 ,
V_62 -> V_13 , V_9 -> V_173 . V_174 - 1 ) ;
break;
}
F_100 ( V_9 , V_62 -> V_13 ) ;
break;
case V_175 :
F_115 ( V_1 ) ;
break;
case V_176 :
if ( ! V_62 -> V_60 )
break;
if ( F_10 ( V_1 ) )
break;
F_87 ( V_1 ) ;
F_120 ( & V_177 ) ;
break;
case V_178 : {
struct {
T_11 V_143 ;
T_11 V_144 ;
} V_36 ;
if ( ! F_10 ( V_1 ) )
break;
memcpy ( & V_36 , V_27 -> V_27 + V_27 -> V_48 + sizeof( * V_62 ) ,
sizeof( V_36 ) ) ;
F_96 ( V_1 , V_36 . V_143 , V_36 . V_144 ) ;
V_1 -> V_4 . V_18 -> V_133 = 1 ;
F_80 ( V_1 ) ;
break;
}
case V_118 :
V_1 -> V_77 = V_62 -> V_60 ;
F_116 ( & V_1 -> V_87 ) ;
F_49 ( & V_1 -> V_69 ) ;
F_42 ( V_1 ) ;
F_50 ( & V_1 -> V_69 ) ;
F_98 ( V_1 ) ;
break;
case V_179 :
if ( V_1 -> V_141 )
break;
V_171 = V_27 -> V_47 - V_27 -> V_48 - sizeof( * V_62 ) + 1 ;
V_1 -> V_141 = F_27 ( V_171 , V_44 ) ;
if ( ! V_1 -> V_141 ) {
F_91 ( V_1 -> V_10 ,
L_25 ) ;
break;
}
strncpy ( V_1 -> V_141 , V_27 -> V_27 + V_27 -> V_48 + sizeof( * V_62 ) ,
V_171 - 1 ) ;
V_1 -> V_141 [ V_171 - 1 ] = 0 ;
V_55 = F_121 ( & V_1 -> V_10 -> V_169 ,
& V_170 ) ;
if ( V_55 ) {
F_91 ( V_1 -> V_10 ,
L_26 ,
V_55 ) ;
} else {
F_122 ( & V_1 -> V_10 -> V_169 , V_180 ) ;
}
break;
}
}
static void F_123 ( struct V_181 * V_182 )
{
struct V_8 * V_9 ;
struct V_14 * V_15 ;
struct V_26 * V_27 ;
unsigned int V_47 ;
V_9 = F_4 ( V_182 , struct V_8 , V_183 ) ;
V_15 = V_9 -> V_184 ;
F_124 ( & V_9 -> V_185 ) ;
while ( ( V_27 = F_31 ( V_15 , & V_47 ) ) ) {
F_125 ( & V_9 -> V_185 ) ;
V_27 -> V_47 = V_47 ;
V_27 -> V_48 = 0 ;
F_118 ( V_9 , V_27 ) ;
F_124 ( & V_9 -> V_185 ) ;
if ( F_32 ( V_9 -> V_184 , V_27 ) < 0 ) {
F_37 ( & V_9 -> V_20 -> V_10 ,
L_27 ) ;
F_13 ( V_27 , false ) ;
}
}
F_125 ( & V_9 -> V_185 ) ;
}
static void F_126 ( struct V_14 * V_15 )
{
struct V_1 * V_1 ;
V_1 = F_9 ( V_15 -> V_20 -> V_186 , V_15 ) ;
if ( ! V_1 )
return;
F_116 ( & V_1 -> V_87 ) ;
}
static void F_127 ( struct V_14 * V_15 )
{
struct V_1 * V_1 ;
unsigned long V_5 ;
V_1 = F_9 ( V_15 -> V_20 -> V_186 , V_15 ) ;
if ( ! V_1 )
return;
F_2 ( & V_1 -> V_57 , V_5 ) ;
V_1 -> V_49 = F_30 ( V_1 ) ;
if ( ! V_1 -> V_76 )
F_36 ( V_1 ) ;
F_5 ( & V_1 -> V_57 , V_5 ) ;
F_116 ( & V_1 -> V_87 ) ;
F_98 ( V_1 ) ;
if ( F_10 ( V_1 ) && F_128 ( V_1 -> V_4 . V_18 ) )
F_129 () ;
}
static void F_130 ( struct V_14 * V_15 )
{
struct V_8 * V_9 ;
V_9 = V_15 -> V_20 -> V_186 ;
F_131 ( & V_9 -> V_183 ) ;
}
static void F_132 ( struct V_19 * V_20 )
{
struct V_8 * V_9 ;
V_9 = V_20 -> V_186 ;
if ( ! F_12 ( V_9 ) ) {
struct V_1 * V_1 ;
T_9 V_143 , V_144 ;
V_20 -> V_173 -> V_187 ( V_20 ,
F_133 ( struct V_188 , V_144 ) ,
& V_144 , sizeof( T_9 ) ) ;
V_20 -> V_173 -> V_187 ( V_20 ,
F_133 ( struct V_188 , V_143 ) ,
& V_143 , sizeof( T_9 ) ) ;
V_1 = F_8 ( V_9 , 0 ) ;
F_96 ( V_1 , V_143 , V_144 ) ;
F_80 ( V_1 ) ;
}
}
static int F_134 ( struct V_8 * V_9 )
{
T_12 * * V_189 ;
char * * V_190 ;
struct V_14 * * V_191 ;
T_1 V_29 , V_192 , V_193 , V_194 ;
int V_55 ;
V_193 = V_9 -> V_173 . V_174 ;
V_194 = F_12 ( V_9 ) ? ( V_193 + 1 ) * 2 : 2 ;
V_191 = F_27 ( V_194 * sizeof( struct V_14 * ) , V_44 ) ;
V_189 = F_27 ( V_194 * sizeof( T_12 * ) , V_44 ) ;
V_190 = F_27 ( V_194 * sizeof( char * ) , V_44 ) ;
V_9 -> V_154 = F_27 ( V_193 * sizeof( struct V_14 * ) ,
V_44 ) ;
V_9 -> V_155 = F_27 ( V_193 * sizeof( struct V_14 * ) ,
V_44 ) ;
if ( ! V_191 || ! V_189 || ! V_190 || ! V_9 -> V_154 ||
! V_9 -> V_155 ) {
V_55 = - V_89 ;
goto free;
}
V_192 = 0 ;
V_189 [ V_192 ] = F_127 ;
V_189 [ V_192 + 1 ] = F_126 ;
V_190 [ V_192 ] = L_28 ;
V_190 [ V_192 + 1 ] = L_29 ;
V_192 += 2 ;
if ( F_12 ( V_9 ) ) {
V_189 [ V_192 ] = F_130 ;
V_189 [ V_192 + 1 ] = NULL ;
V_190 [ V_192 ] = L_30 ;
V_190 [ V_192 + 1 ] = L_31 ;
for ( V_29 = 1 ; V_29 < V_193 ; V_29 ++ ) {
V_192 += 2 ;
V_189 [ V_192 ] = F_127 ;
V_189 [ V_192 + 1 ] = F_126 ;
V_190 [ V_192 ] = L_28 ;
V_190 [ V_192 + 1 ] = L_29 ;
}
}
V_55 = V_9 -> V_20 -> V_173 -> V_195 ( V_9 -> V_20 , V_194 , V_191 ,
V_189 ,
( const char * * ) V_190 ) ;
if ( V_55 )
goto free;
V_192 = 0 ;
V_9 -> V_154 [ 0 ] = V_191 [ 0 ] ;
V_9 -> V_155 [ 0 ] = V_191 [ 1 ] ;
V_192 += 2 ;
if ( F_12 ( V_9 ) ) {
V_9 -> V_184 = V_191 [ V_192 ] ;
V_9 -> V_63 = V_191 [ V_192 + 1 ] ;
for ( V_29 = 1 ; V_29 < V_193 ; V_29 ++ ) {
V_192 += 2 ;
V_9 -> V_154 [ V_29 ] = V_191 [ V_192 ] ;
V_9 -> V_155 [ V_29 ] = V_191 [ V_192 + 1 ] ;
}
}
F_16 ( V_190 ) ;
F_16 ( V_189 ) ;
F_16 ( V_191 ) ;
return 0 ;
free:
F_16 ( V_9 -> V_155 ) ;
F_16 ( V_9 -> V_154 ) ;
F_16 ( V_190 ) ;
F_16 ( V_189 ) ;
F_16 ( V_191 ) ;
return V_55 ;
}
static void F_135 ( struct V_8 * V_9 )
{
V_9 -> V_20 -> V_173 -> V_196 ( V_9 -> V_20 ) ;
F_16 ( V_9 -> V_154 ) ;
F_16 ( V_9 -> V_155 ) ;
}
static void F_136 ( struct V_8 * V_9 )
{
struct V_26 * V_27 ;
unsigned int V_47 ;
if ( ! F_12 ( V_9 ) )
return;
while ( ( V_27 = F_31 ( V_9 -> V_184 , & V_47 ) ) )
F_13 ( V_27 , true ) ;
while ( ( V_27 = F_109 ( V_9 -> V_184 ) ) )
F_13 ( V_27 , true ) ;
}
static int F_137 ( struct V_19 * V_20 )
{
struct V_8 * V_9 ;
int V_55 ;
bool V_197 ;
bool V_198 = V_127 != NULL ;
F_138 () ;
V_9 = F_27 ( sizeof( * V_9 ) , V_44 ) ;
if ( ! V_9 ) {
V_55 = - V_89 ;
goto V_45;
}
V_9 -> V_20 = V_20 ;
V_20 -> V_186 = V_9 ;
F_49 ( & V_6 ) ;
V_9 -> V_161 = V_135 . V_199 ++ ;
F_50 ( & V_6 ) ;
V_9 -> V_158 = F_139 ( 0 , L_32 ,
& V_200 ) ;
if ( V_9 -> V_158 < 0 ) {
F_91 ( & V_20 -> V_10 ,
L_33 ,
V_9 -> V_158 , V_9 -> V_161 ) ;
V_55 = V_9 -> V_158 ;
goto free;
}
V_197 = false ;
V_9 -> V_173 . V_174 = 1 ;
if ( ! F_11 ( V_20 ) &&
F_140 ( V_20 , V_25 ,
F_133 ( struct V_188 ,
V_174 ) ,
& V_9 -> V_173 . V_174 ) == 0 ) {
V_197 = true ;
}
V_55 = F_134 ( V_9 ) ;
if ( V_55 < 0 ) {
F_91 ( & V_20 -> V_10 , L_34 , V_55 ) ;
goto V_201;
}
F_106 ( & V_9 -> V_11 ) ;
F_141 ( & V_9 -> V_164 ) ;
if ( V_197 ) {
unsigned int V_148 ;
F_106 ( & V_9 -> V_185 ) ;
F_142 ( & V_9 -> V_183 , & F_123 ) ;
V_148 = F_97 ( V_9 -> V_184 , & V_9 -> V_185 ) ;
if ( ! V_148 ) {
F_91 ( & V_20 -> V_10 ,
L_35 ) ;
V_55 = - V_89 ;
goto V_202;
}
} else {
F_100 ( V_9 , 0 ) ;
}
F_49 ( & V_6 ) ;
F_17 ( & V_9 -> V_34 , & V_135 . V_203 ) ;
F_50 ( & V_6 ) ;
F_39 ( V_9 , V_204 ,
V_205 , 1 ) ;
if ( V_197 && V_198 )
F_143 ( & V_177 ) ;
return 0 ;
V_202:
F_39 ( V_9 , V_204 ,
V_205 , 0 ) ;
F_135 ( V_9 ) ;
V_201:
F_144 ( V_9 -> V_158 , L_32 ) ;
free:
F_16 ( V_9 ) ;
V_45:
return V_55 ;
}
static void F_145 ( struct V_19 * V_20 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 , * V_206 ;
V_9 = V_20 -> V_186 ;
F_49 ( & V_6 ) ;
F_25 ( & V_9 -> V_34 ) ;
F_50 ( & V_6 ) ;
V_20 -> V_173 -> V_207 ( V_20 ) ;
if ( F_12 ( V_9 ) )
F_146 ( & V_9 -> V_183 ) ;
F_24 (port, port2, &portdev->ports, list)
F_115 ( V_1 ) ;
F_144 ( V_9 -> V_158 , L_32 ) ;
F_136 ( V_9 ) ;
F_135 ( V_9 ) ;
F_16 ( V_9 ) ;
}
static int F_147 ( struct V_19 * V_20 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
V_9 = V_20 -> V_186 ;
V_20 -> V_173 -> V_207 ( V_20 ) ;
F_148 ( V_9 -> V_184 ) ;
F_146 ( & V_9 -> V_183 ) ;
F_148 ( V_9 -> V_184 ) ;
F_136 ( V_9 ) ;
F_3 (port, &portdev->ports, list) {
F_148 ( V_1 -> V_16 ) ;
F_148 ( V_1 -> V_17 ) ;
V_1 -> V_77 = false ;
F_114 ( V_1 ) ;
}
F_135 ( V_9 ) ;
return 0 ;
}
static int F_149 ( struct V_19 * V_20 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
int V_52 ;
V_9 = V_20 -> V_186 ;
V_52 = F_134 ( V_9 ) ;
if ( V_52 )
return V_52 ;
if ( F_12 ( V_9 ) )
F_97 ( V_9 -> V_184 , & V_9 -> V_185 ) ;
F_3 (port, &portdev->ports, list) {
V_1 -> V_16 = V_9 -> V_154 [ V_1 -> V_13 ] ;
V_1 -> V_17 = V_9 -> V_155 [ V_1 -> V_13 ] ;
F_97 ( V_1 -> V_16 , & V_1 -> V_57 ) ;
F_41 ( V_1 , V_165 , 1 ) ;
if ( V_1 -> V_76 )
F_41 ( V_1 , V_118 , 1 ) ;
}
return 0 ;
}
static int T_8 F_150 ( void )
{
int V_55 ;
V_135 . V_160 = F_151 ( V_208 , L_36 ) ;
if ( F_89 ( V_135 . V_160 ) ) {
V_55 = F_90 ( V_135 . V_160 ) ;
F_152 ( L_37 , V_55 ) ;
return V_55 ;
}
V_135 . V_166 = F_153 ( L_36 , NULL ) ;
if ( ! V_135 . V_166 ) {
F_154 ( L_38 ,
F_90 ( V_135 . V_166 ) ) ;
}
F_141 ( & V_135 . V_137 ) ;
F_141 ( & V_135 . V_203 ) ;
V_55 = F_155 ( & V_209 ) ;
if ( V_55 < 0 ) {
F_152 ( L_39 , V_55 ) ;
goto free;
}
V_55 = F_155 ( & V_210 ) ;
if ( V_55 < 0 ) {
F_152 ( L_40 ,
V_55 ) ;
goto V_211;
}
return 0 ;
V_211:
F_156 ( & V_209 ) ;
free:
if ( V_135 . V_166 )
F_157 ( V_135 . V_166 ) ;
F_158 ( V_135 . V_160 ) ;
return V_55 ;
}
static void T_13 F_159 ( void )
{
F_20 () ;
F_156 ( & V_209 ) ;
F_156 ( & V_210 ) ;
F_158 ( V_135 . V_160 ) ;
if ( V_135 . V_166 )
F_157 ( V_135 . V_166 ) ;
}
