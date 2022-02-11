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
F_3 (port, &portdev->ports, list) {
if ( V_1 -> V_12 -> V_10 == V_10 ) {
F_7 ( & V_1 -> V_13 ) ;
goto V_7;
}
}
V_1 = NULL ;
V_7:
F_5 ( & V_9 -> V_11 , V_5 ) ;
return V_1 ;
}
static struct V_1 * F_8 ( T_2 V_10 )
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
static struct V_1 * F_9 ( struct V_8 * V_9 , T_1 V_14 )
{
struct V_1 * V_1 ;
unsigned long V_5 ;
F_2 ( & V_9 -> V_11 , V_5 ) ;
F_3 (port, &portdev->ports, list)
if ( V_1 -> V_14 == V_14 )
goto V_7;
V_1 = NULL ;
V_7:
F_5 ( & V_9 -> V_11 , V_5 ) ;
return V_1 ;
}
static struct V_1 * F_10 ( struct V_8 * V_9 ,
struct V_15 * V_16 )
{
struct V_1 * V_1 ;
unsigned long V_5 ;
F_2 ( & V_9 -> V_11 , V_5 ) ;
F_3 (port, &portdev->ports, list)
if ( V_1 -> V_17 == V_16 || V_1 -> V_18 == V_16 )
goto V_7;
V_1 = NULL ;
V_7:
F_5 ( & V_9 -> V_11 , V_5 ) ;
return V_1 ;
}
static bool F_11 ( struct V_1 * V_1 )
{
if ( V_1 -> V_4 . V_19 )
return true ;
return false ;
}
static bool F_12 ( const struct V_20 * V_21 )
{
return V_22 && V_21 -> V_14 . V_23 == V_24 ;
}
static inline bool F_13 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_21 )
return 0 ;
return V_9 -> V_21 -> V_25 [ 0 ] & ( 1 << V_26 ) ;
}
static void F_14 ( struct V_27 * V_28 , bool V_29 )
{
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < V_28 -> V_31 ; V_30 ++ ) {
struct V_32 * V_32 = F_15 ( & V_28 -> V_33 [ V_30 ] ) ;
if ( ! V_32 )
break;
F_16 ( V_32 ) ;
}
if ( ! V_28 -> V_10 ) {
F_17 ( V_28 -> V_28 ) ;
} else if ( V_22 ) {
unsigned long V_5 ;
if ( ! V_29 ) {
F_2 ( & V_34 , V_5 ) ;
F_18 ( & V_28 -> V_35 , & V_36 ) ;
F_5 ( & V_34 , V_5 ) ;
return;
}
F_19 ( V_28 -> V_10 , V_28 -> V_37 , V_28 -> V_28 , V_28 -> V_38 ) ;
F_20 ( V_28 -> V_10 ) ;
}
F_17 ( V_28 ) ;
}
static void F_21 ( void )
{
unsigned long V_5 ;
struct V_27 * V_28 , * V_39 ;
F_22 ( V_40 ) ;
if ( F_23 ( & V_36 ) )
return;
F_2 ( & V_34 , V_5 ) ;
F_24 ( & V_40 , & V_36 ,
V_36 . V_41 ) ;
F_5 ( & V_34 , V_5 ) ;
F_25 (buf, tmp, &tmp_list, list) {
F_26 ( & V_28 -> V_35 ) ;
F_14 ( V_28 , true ) ;
}
}
static struct V_27 * F_27 ( struct V_15 * V_16 , T_3 V_42 ,
int V_43 )
{
struct V_27 * V_28 ;
F_21 () ;
V_28 = F_28 ( sizeof( * V_28 ) + sizeof( struct V_44 ) * V_43 ,
V_45 ) ;
if ( ! V_28 )
goto V_46;
V_28 -> V_31 = V_43 ;
if ( V_43 > 0 ) {
V_28 -> V_10 = NULL ;
V_28 -> V_28 = NULL ;
return V_28 ;
}
if ( F_12 ( V_16 -> V_21 ) ) {
if ( ! V_16 -> V_21 -> V_10 . V_47 || ! V_16 -> V_21 -> V_10 . V_47 -> V_47 )
goto F_14;
V_28 -> V_10 = V_16 -> V_21 -> V_10 . V_47 -> V_47 ;
F_29 ( V_28 -> V_10 ) ;
V_28 -> V_28 = F_30 ( V_28 -> V_10 , V_42 , & V_28 -> V_38 ,
V_45 ) ;
} else {
V_28 -> V_10 = NULL ;
V_28 -> V_28 = F_28 ( V_42 , V_45 ) ;
}
if ( ! V_28 -> V_28 )
goto F_14;
V_28 -> V_48 = 0 ;
V_28 -> V_49 = 0 ;
V_28 -> V_37 = V_42 ;
return V_28 ;
F_14:
F_17 ( V_28 ) ;
V_46:
return NULL ;
}
static struct V_27 * F_31 ( struct V_1 * V_1 )
{
struct V_27 * V_28 ;
unsigned int V_48 ;
if ( V_1 -> V_50 )
return V_1 -> V_50 ;
V_28 = F_32 ( V_1 -> V_17 , & V_48 ) ;
if ( V_28 ) {
V_28 -> V_48 = V_48 ;
V_28 -> V_49 = 0 ;
V_1 -> V_51 . V_52 += V_48 ;
}
return V_28 ;
}
static int F_33 ( struct V_15 * V_16 , struct V_27 * V_28 )
{
struct V_44 V_33 [ 1 ] ;
int V_53 ;
F_34 ( V_33 , V_28 -> V_28 , V_28 -> V_37 ) ;
V_53 = F_35 ( V_16 , V_33 , 1 , V_28 , V_54 ) ;
F_36 ( V_16 ) ;
if ( ! V_53 )
V_53 = V_16 -> V_55 ;
return V_53 ;
}
static void F_37 ( struct V_1 * V_1 )
{
struct V_27 * V_28 ;
unsigned int V_56 ;
if ( ! V_1 -> V_9 ) {
return;
}
V_28 = F_31 ( V_1 ) ;
V_56 = 0 ;
while ( V_28 ) {
V_1 -> V_51 . V_57 += V_28 -> V_48 - V_28 -> V_49 ;
if ( F_33 ( V_1 -> V_17 , V_28 ) < 0 ) {
V_56 ++ ;
F_14 ( V_28 , false ) ;
}
V_1 -> V_50 = NULL ;
V_28 = F_31 ( V_1 ) ;
}
if ( V_56 )
F_38 ( V_1 -> V_10 , L_1 ,
V_56 ) ;
}
static bool F_39 ( struct V_1 * V_1 )
{
unsigned long V_5 ;
bool V_53 ;
V_53 = false ;
F_2 ( & V_1 -> V_58 , V_5 ) ;
V_1 -> V_50 = F_31 ( V_1 ) ;
if ( V_1 -> V_50 )
V_53 = true ;
F_5 ( & V_1 -> V_58 , V_5 ) ;
return V_53 ;
}
static T_4 F_40 ( struct V_8 * V_9 , T_1 V_59 ,
unsigned int V_60 , unsigned int V_61 )
{
struct V_44 V_33 [ 1 ] ;
struct V_62 V_63 ;
struct V_15 * V_16 ;
unsigned int V_48 ;
if ( ! F_13 ( V_9 ) )
return 0 ;
V_63 . V_14 = V_59 ;
V_63 . V_60 = V_60 ;
V_63 . V_61 = V_61 ;
V_16 = V_9 -> V_64 ;
F_34 ( V_33 , & V_63 , sizeof( V_63 ) ) ;
F_41 ( & V_9 -> V_65 ) ;
if ( F_42 ( V_16 , V_33 , 1 , & V_63 , V_54 ) == 0 ) {
F_36 ( V_16 ) ;
while ( ! F_32 ( V_16 , & V_48 )
&& ! F_43 ( V_16 ) )
F_44 () ;
}
F_45 ( & V_9 -> V_65 ) ;
return 0 ;
}
static T_4 F_46 ( struct V_1 * V_1 , unsigned int V_60 ,
unsigned int V_61 )
{
if ( V_1 -> V_9 )
return F_40 ( V_1 -> V_9 , V_1 -> V_14 , V_60 , V_61 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_1 )
{
struct V_27 * V_28 ;
unsigned int V_48 ;
if ( ! V_1 -> V_9 ) {
return;
}
while ( ( V_28 = F_32 ( V_1 -> V_18 , & V_48 ) ) ) {
F_14 ( V_28 , false ) ;
V_1 -> V_66 = false ;
}
}
static T_4 F_48 ( struct V_1 * V_1 , struct V_44 * V_33 ,
int V_67 , T_3 V_68 ,
void * V_69 , bool V_70 )
{
struct V_15 * V_18 ;
int V_56 ;
unsigned long V_5 ;
unsigned int V_48 ;
V_18 = V_1 -> V_18 ;
F_2 ( & V_1 -> V_71 , V_5 ) ;
F_47 ( V_1 ) ;
V_56 = F_42 ( V_18 , V_33 , V_67 , V_69 , V_54 ) ;
F_36 ( V_18 ) ;
if ( V_56 ) {
V_68 = 0 ;
goto V_72;
}
if ( V_18 -> V_55 == 0 )
V_1 -> V_66 = true ;
if ( V_70 )
goto V_72;
while ( ! F_32 ( V_18 , & V_48 )
&& ! F_43 ( V_18 ) )
F_44 () ;
V_72:
F_5 ( & V_1 -> V_71 , V_5 ) ;
V_1 -> V_51 . V_73 += V_68 ;
return V_68 ;
}
static T_4 F_49 ( struct V_1 * V_1 , char * V_74 , T_3 V_75 ,
bool V_76 )
{
struct V_27 * V_28 ;
unsigned long V_5 ;
if ( ! V_75 || ! F_39 ( V_1 ) )
return 0 ;
V_28 = V_1 -> V_50 ;
V_75 = F_50 ( V_75 , V_28 -> V_48 - V_28 -> V_49 ) ;
if ( V_76 ) {
T_4 V_53 ;
V_53 = F_51 ( V_74 , V_28 -> V_28 + V_28 -> V_49 , V_75 ) ;
if ( V_53 )
return - V_77 ;
} else {
memcpy ( V_74 , V_28 -> V_28 + V_28 -> V_49 , V_75 ) ;
}
V_28 -> V_49 += V_75 ;
if ( V_28 -> V_49 == V_28 -> V_48 ) {
F_2 ( & V_1 -> V_58 , V_5 ) ;
V_1 -> V_50 = NULL ;
if ( F_33 ( V_1 -> V_17 , V_28 ) < 0 )
F_38 ( V_1 -> V_10 , L_2 ) ;
F_5 ( & V_1 -> V_58 , V_5 ) ;
}
return V_75 ;
}
static bool F_52 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_78 ) {
return false ;
}
return ! F_39 ( V_1 ) && V_1 -> V_79 ;
}
static bool F_53 ( struct V_1 * V_1 )
{
bool V_53 ;
if ( ! V_1 -> V_78 ) {
return false ;
}
if ( ! V_1 -> V_79 )
return true ;
F_54 ( & V_1 -> V_71 ) ;
F_47 ( V_1 ) ;
V_53 = V_1 -> V_66 ;
F_55 ( & V_1 -> V_71 ) ;
return V_53 ;
}
static T_4 F_56 ( struct V_80 * V_81 , char T_5 * V_82 ,
T_3 V_83 , T_6 * V_84 )
{
struct V_1 * V_1 ;
T_4 V_53 ;
V_1 = V_81 -> V_85 ;
if ( ! V_1 -> V_78 )
return - V_86 ;
if ( ! F_39 ( V_1 ) ) {
if ( ! V_1 -> V_79 )
return 0 ;
if ( V_81 -> V_87 & V_88 )
return - V_89 ;
V_53 = F_57 ( V_1 -> V_90 ,
! F_52 ( V_1 ) ) ;
if ( V_53 < 0 )
return V_53 ;
}
if ( ! V_1 -> V_78 )
return - V_86 ;
if ( ! F_39 ( V_1 ) && ! V_1 -> V_79 )
return 0 ;
return F_49 ( V_1 , V_82 , V_83 , true ) ;
}
static int F_58 ( struct V_1 * V_1 , bool V_70 )
{
int V_53 ;
if ( F_53 ( V_1 ) ) {
if ( V_70 )
return - V_89 ;
V_53 = F_57 ( V_1 -> V_90 ,
! F_53 ( V_1 ) ) ;
if ( V_53 < 0 )
return V_53 ;
}
if ( ! V_1 -> V_78 )
return - V_86 ;
return 0 ;
}
static T_4 F_59 ( struct V_80 * V_81 , const char T_5 * V_82 ,
T_3 V_83 , T_6 * V_84 )
{
struct V_1 * V_1 ;
struct V_27 * V_28 ;
T_4 V_53 ;
bool V_70 ;
struct V_44 V_33 [ 1 ] ;
if ( ! V_83 )
return 0 ;
V_1 = V_81 -> V_85 ;
V_70 = V_81 -> V_87 & V_88 ;
V_53 = F_58 ( V_1 , V_70 ) ;
if ( V_53 < 0 )
return V_53 ;
V_83 = F_50 ( ( T_3 ) ( 32 * 1024 ) , V_83 ) ;
V_28 = F_27 ( V_1 -> V_18 , V_83 , 0 ) ;
if ( ! V_28 )
return - V_91 ;
V_53 = F_60 ( V_28 -> V_28 , V_82 , V_83 ) ;
if ( V_53 ) {
V_53 = - V_77 ;
goto F_14;
}
V_70 = true ;
F_34 ( V_33 , V_28 -> V_28 , V_83 ) ;
V_53 = F_48 ( V_1 , V_33 , 1 , V_83 , V_28 , V_70 ) ;
if ( V_70 && V_53 > 0 )
goto V_7;
F_14:
F_14 ( V_28 , true ) ;
V_7:
return V_53 ;
}
static int F_61 ( struct V_92 * V_93 , struct V_94 * V_28 ,
struct V_95 * V_96 )
{
struct V_97 * V_98 = V_96 -> V_99 . V_69 ;
unsigned int V_49 , V_48 ;
if ( V_98 -> V_100 == V_98 -> V_37 )
return 0 ;
if ( V_28 -> V_101 -> V_102 ( V_93 , V_28 ) == 0 ) {
F_62 ( V_28 -> V_32 ) ;
F_63 ( V_28 -> V_32 ) ;
V_48 = F_50 ( V_28 -> V_48 , V_96 -> V_48 ) ;
F_64 ( & ( V_98 -> V_33 [ V_98 -> V_100 ] ) , V_28 -> V_32 , V_48 , V_28 -> V_49 ) ;
} else {
struct V_32 * V_32 = F_65 ( V_45 ) ;
char * V_103 ;
if ( ! V_32 )
return - V_91 ;
V_49 = V_96 -> V_104 & ~ V_105 ;
V_48 = V_96 -> V_48 ;
if ( V_48 + V_49 > V_106 )
V_48 = V_106 - V_49 ;
V_103 = F_66 ( V_28 -> V_32 ) ;
memcpy ( F_67 ( V_32 ) + V_49 , V_103 + V_28 -> V_49 , V_48 ) ;
F_68 ( V_103 ) ;
F_64 ( & ( V_98 -> V_33 [ V_98 -> V_100 ] ) , V_32 , V_48 , V_49 ) ;
}
V_98 -> V_100 ++ ;
V_98 -> V_48 += V_48 ;
return V_48 ;
}
static T_4 F_69 ( struct V_92 * V_93 ,
struct V_80 * V_81 , T_6 * V_107 ,
T_3 V_48 , unsigned int V_5 )
{
struct V_1 * V_1 = V_81 -> V_85 ;
struct V_97 V_98 ;
T_4 V_53 ;
struct V_27 * V_28 ;
struct V_95 V_96 = {
. V_108 = V_48 ,
. V_5 = V_5 ,
. V_104 = * V_107 ,
. V_99 . V_69 = & V_98 ,
} ;
if ( F_12 ( V_1 -> V_18 -> V_21 ) )
return - V_109 ;
F_70 ( V_93 ) ;
if ( ! V_93 -> V_110 ) {
V_53 = 0 ;
goto V_111;
}
V_53 = F_58 ( V_1 , V_81 -> V_87 & V_88 ) ;
if ( V_53 < 0 )
goto V_111;
V_28 = F_27 ( V_1 -> V_18 , 0 , V_93 -> V_110 ) ;
if ( ! V_28 ) {
V_53 = - V_91 ;
goto V_111;
}
V_98 . V_100 = 0 ;
V_98 . V_48 = 0 ;
V_98 . V_37 = V_93 -> V_110 ;
V_98 . V_33 = V_28 -> V_33 ;
F_71 ( V_98 . V_33 , V_98 . V_37 ) ;
V_53 = F_72 ( V_93 , & V_96 , F_61 ) ;
F_73 ( V_93 ) ;
if ( F_74 ( V_53 > 0 ) )
V_53 = F_48 ( V_1 , V_28 -> V_33 , V_98 . V_100 , V_98 . V_48 , V_28 , true ) ;
if ( F_75 ( V_53 <= 0 ) )
F_14 ( V_28 , true ) ;
return V_53 ;
V_111:
F_73 ( V_93 ) ;
return V_53 ;
}
static unsigned int F_76 ( struct V_80 * V_81 , T_7 * V_112 )
{
struct V_1 * V_1 ;
unsigned int V_53 ;
V_1 = V_81 -> V_85 ;
F_77 ( V_81 , & V_1 -> V_90 , V_112 ) ;
if ( ! V_1 -> V_78 ) {
return V_113 ;
}
V_53 = 0 ;
if ( ! F_52 ( V_1 ) )
V_53 |= V_114 | V_115 ;
if ( ! F_53 ( V_1 ) )
V_53 |= V_116 ;
if ( ! V_1 -> V_79 )
V_53 |= V_113 ;
return V_53 ;
}
static int F_78 ( struct V_117 * V_117 , struct V_80 * V_81 )
{
struct V_1 * V_1 ;
V_1 = V_81 -> V_85 ;
F_46 ( V_1 , V_118 , 0 ) ;
F_54 ( & V_1 -> V_58 ) ;
V_1 -> V_78 = false ;
F_37 ( V_1 ) ;
F_55 ( & V_1 -> V_58 ) ;
F_54 ( & V_1 -> V_71 ) ;
F_47 ( V_1 ) ;
F_55 ( & V_1 -> V_71 ) ;
F_21 () ;
F_79 ( & V_1 -> V_13 , V_119 ) ;
return 0 ;
}
static int F_80 ( struct V_117 * V_117 , struct V_80 * V_81 )
{
struct V_12 * V_12 = V_117 -> V_120 ;
struct V_1 * V_1 ;
int V_53 ;
V_1 = F_8 ( V_12 -> V_10 ) ;
if ( ! V_1 ) {
return - V_121 ;
}
V_81 -> V_85 = V_1 ;
if ( F_11 ( V_1 ) ) {
V_53 = - V_121 ;
goto V_7;
}
F_54 ( & V_1 -> V_58 ) ;
if ( V_1 -> V_78 ) {
F_55 ( & V_1 -> V_58 ) ;
V_53 = - V_122 ;
goto V_7;
}
V_1 -> V_78 = true ;
F_55 ( & V_1 -> V_58 ) ;
F_54 ( & V_1 -> V_71 ) ;
F_47 ( V_1 ) ;
F_55 ( & V_1 -> V_71 ) ;
F_81 ( V_117 , V_81 ) ;
F_46 ( V_81 -> V_85 , V_118 , 1 ) ;
return 0 ;
V_7:
F_79 ( & V_1 -> V_13 , V_119 ) ;
return V_53 ;
}
static int F_82 ( int V_123 , struct V_80 * V_81 , int V_124 )
{
struct V_1 * V_1 ;
V_1 = V_81 -> V_85 ;
return F_83 ( V_123 , V_81 , V_124 , & V_1 -> V_125 ) ;
}
static int F_84 ( T_1 V_2 , const char * V_28 , int V_83 )
{
struct V_1 * V_1 ;
struct V_44 V_33 [ 1 ] ;
if ( F_75 ( V_126 ) )
return V_126 ( V_2 , V_28 , V_83 ) ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_127 ;
F_34 ( V_33 , V_28 , V_83 ) ;
return F_48 ( V_1 , V_33 , 1 , V_83 , ( void * ) V_28 , false ) ;
}
static int F_85 ( T_1 V_2 , char * V_28 , int V_83 )
{
struct V_1 * V_1 ;
if ( F_75 ( V_126 ) )
return 0 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_127 ;
F_86 ( ! V_1 -> V_17 ) ;
return F_49 ( V_1 , V_28 , V_83 , false ) ;
}
static void F_87 ( struct V_1 * V_1 )
{
struct V_20 * V_21 ;
if ( ! V_1 || ! F_11 ( V_1 ) )
return;
V_21 = V_1 -> V_9 -> V_21 ;
if ( ! F_12 ( V_21 ) &&
F_88 ( V_21 , V_128 ) )
F_89 ( V_1 -> V_4 . V_19 , V_1 -> V_4 . V_129 ) ;
}
static int F_90 ( struct V_130 * V_131 , int V_69 )
{
struct V_1 * V_1 ;
V_1 = F_1 ( V_131 -> V_2 ) ;
if ( ! V_1 )
return - V_109 ;
V_131 -> V_132 = 1 ;
F_87 ( V_1 ) ;
return 0 ;
}
static void F_91 ( struct V_130 * V_131 , int V_69 )
{
V_131 -> V_132 = 0 ;
}
int T_8 F_92 ( int (* F_84)( T_1 , const char * , int ) )
{
V_126 = F_84 ;
return F_93 ( 0 , 0 , & V_133 ) ;
}
static int F_94 ( struct V_1 * V_1 )
{
int V_53 ;
V_1 -> V_4 . V_2 = V_134 . V_135 ;
V_1 -> V_4 . V_19 = F_95 ( V_1 -> V_4 . V_2 , 0 , & V_133 , V_106 ) ;
if ( F_96 ( V_1 -> V_4 . V_19 ) ) {
V_53 = F_97 ( V_1 -> V_4 . V_19 ) ;
F_98 ( V_1 -> V_10 ,
L_3 , V_53 ) ;
V_1 -> V_4 . V_19 = NULL ;
return V_53 ;
}
F_54 ( & V_6 ) ;
V_134 . V_135 ++ ;
F_18 ( & V_1 -> V_4 . V_35 , & V_134 . V_136 ) ;
F_55 ( & V_6 ) ;
V_1 -> V_78 = true ;
if ( V_126 )
V_126 = NULL ;
F_46 ( V_1 , V_118 , 1 ) ;
return 0 ;
}
static T_4 F_99 ( struct V_23 * V_10 ,
struct V_137 * V_138 , char * V_139 )
{
struct V_1 * V_1 ;
V_1 = F_100 ( V_10 ) ;
return sprintf ( V_139 , L_4 , V_1 -> V_140 ) ;
}
static T_4 F_101 ( struct V_80 * V_81 , char T_5 * V_82 ,
T_3 V_83 , T_6 * V_84 )
{
struct V_1 * V_1 ;
char * V_28 ;
T_4 V_53 , V_141 , V_75 ;
V_75 = 1024 ;
V_28 = F_28 ( V_75 , V_45 ) ;
if ( ! V_28 )
return - V_91 ;
V_1 = V_81 -> V_85 ;
V_141 = 0 ;
V_141 += snprintf ( V_28 + V_141 , V_75 ,
L_5 , V_1 -> V_140 ? V_1 -> V_140 : L_6 ) ;
V_141 += snprintf ( V_28 + V_141 , V_75 - V_141 ,
L_7 , V_1 -> V_78 ) ;
V_141 += snprintf ( V_28 + V_141 , V_75 - V_141 ,
L_8 , V_1 -> V_79 ) ;
V_141 += snprintf ( V_28 + V_141 , V_75 - V_141 ,
L_9 , V_1 -> V_66 ) ;
V_141 += snprintf ( V_28 + V_141 , V_75 - V_141 ,
L_10 , V_1 -> V_51 . V_73 ) ;
V_141 += snprintf ( V_28 + V_141 , V_75 - V_141 ,
L_11 ,
V_1 -> V_51 . V_52 ) ;
V_141 += snprintf ( V_28 + V_141 , V_75 - V_141 ,
L_12 ,
V_1 -> V_51 . V_57 ) ;
V_141 += snprintf ( V_28 + V_141 , V_75 - V_141 ,
L_13 ,
F_11 ( V_1 ) ? L_14 : L_15 ) ;
V_141 += snprintf ( V_28 + V_141 , V_75 - V_141 ,
L_16 , V_1 -> V_4 . V_2 ) ;
V_53 = F_102 ( V_82 , V_83 , V_84 , V_28 , V_141 ) ;
F_17 ( V_28 ) ;
return V_53 ;
}
static void F_103 ( struct V_1 * V_1 , T_9 V_142 , T_9 V_143 )
{
if ( ! V_1 || ! F_11 ( V_1 ) )
return;
V_1 -> V_4 . V_129 . V_144 = V_142 ;
V_1 -> V_4 . V_129 . V_145 = V_143 ;
}
static unsigned int F_104 ( struct V_15 * V_16 , T_10 * V_146 )
{
struct V_27 * V_28 ;
unsigned int V_147 ;
int V_53 ;
V_147 = 0 ;
do {
V_28 = F_27 ( V_16 , V_106 , 0 ) ;
if ( ! V_28 )
break;
F_54 ( V_146 ) ;
V_53 = F_33 ( V_16 , V_28 ) ;
if ( V_53 < 0 ) {
F_55 ( V_146 ) ;
F_14 ( V_28 , true ) ;
break;
}
V_147 ++ ;
F_55 ( V_146 ) ;
} while ( V_53 > 0 );
return V_147 ;
}
static void F_105 ( struct V_1 * V_1 )
{
if ( V_1 -> V_125 && V_1 -> V_78 )
F_106 ( & V_1 -> V_125 , V_148 , V_149 ) ;
}
static int F_107 ( struct V_8 * V_9 , T_1 V_14 )
{
char V_150 [ 16 ] ;
struct V_1 * V_1 ;
struct V_27 * V_28 ;
T_2 V_151 ;
unsigned int V_147 ;
int V_56 ;
V_1 = F_28 ( sizeof( * V_1 ) , V_45 ) ;
if ( ! V_1 ) {
V_56 = - V_91 ;
goto V_46;
}
F_108 ( & V_1 -> V_13 ) ;
V_1 -> V_9 = V_9 ;
V_1 -> V_14 = V_14 ;
V_1 -> V_140 = NULL ;
V_1 -> V_50 = NULL ;
V_1 -> V_4 . V_19 = NULL ;
V_1 -> V_125 = NULL ;
V_1 -> V_4 . V_129 . V_144 = V_1 -> V_4 . V_129 . V_145 = 0 ;
V_1 -> V_79 = V_1 -> V_78 = false ;
V_1 -> V_51 = (struct V_152 ) { 0 } ;
V_1 -> V_66 = false ;
V_1 -> V_17 = V_9 -> V_153 [ V_1 -> V_14 ] ;
V_1 -> V_18 = V_9 -> V_154 [ V_1 -> V_14 ] ;
V_1 -> V_12 = F_109 () ;
if ( ! V_1 -> V_12 ) {
F_98 ( & V_1 -> V_9 -> V_21 -> V_10 , L_17 ) ;
V_56 = - V_91 ;
goto V_155;
}
V_1 -> V_12 -> V_101 = & V_156 ;
V_151 = F_110 ( V_9 -> V_157 , V_14 ) ;
V_56 = F_111 ( V_1 -> V_12 , V_151 , 1 ) ;
if ( V_56 < 0 ) {
F_98 ( & V_1 -> V_9 -> V_21 -> V_10 ,
L_18 , V_56 , V_14 ) ;
goto V_158;
}
V_1 -> V_10 = F_112 ( V_134 . V_159 , & V_1 -> V_9 -> V_21 -> V_10 ,
V_151 , V_1 , L_19 ,
V_1 -> V_9 -> V_21 -> V_160 , V_14 ) ;
if ( F_96 ( V_1 -> V_10 ) ) {
V_56 = F_97 ( V_1 -> V_10 ) ;
F_98 ( & V_1 -> V_9 -> V_21 -> V_10 ,
L_20 ,
V_56 , V_14 ) ;
goto V_158;
}
F_113 ( & V_1 -> V_58 ) ;
F_113 ( & V_1 -> V_71 ) ;
F_114 ( & V_1 -> V_90 ) ;
V_147 = F_104 ( V_1 -> V_17 , & V_1 -> V_58 ) ;
if ( ! V_147 ) {
F_98 ( V_1 -> V_10 , L_21 ) ;
V_56 = - V_91 ;
goto V_161;
}
if ( F_12 ( V_1 -> V_9 -> V_21 ) )
V_1 -> V_79 = true ;
else if ( ! F_13 ( V_1 -> V_9 ) ) {
V_56 = F_94 ( V_1 ) ;
if ( V_56 )
goto V_162;
}
F_54 ( & V_9 -> V_11 ) ;
F_18 ( & V_1 -> V_35 , & V_1 -> V_9 -> V_163 ) ;
F_55 ( & V_9 -> V_11 ) ;
F_46 ( V_1 , V_164 , 1 ) ;
if ( V_134 . V_165 ) {
sprintf ( V_150 , L_19 ,
V_1 -> V_9 -> V_21 -> V_160 , V_14 ) ;
V_1 -> V_166 = F_115 ( V_150 , 0444 ,
V_134 . V_165 ,
V_1 ,
& V_167 ) ;
}
return 0 ;
V_162:
while ( ( V_28 = F_116 ( V_1 -> V_17 ) ) )
F_14 ( V_28 , true ) ;
V_161:
F_117 ( V_134 . V_159 , V_1 -> V_10 -> V_151 ) ;
V_158:
F_118 ( V_1 -> V_12 ) ;
V_155:
F_17 ( V_1 ) ;
V_46:
F_40 ( V_9 , V_14 , V_164 , 0 ) ;
return V_56 ;
}
static void V_119 ( struct V_13 * V_13 )
{
struct V_1 * V_1 ;
V_1 = F_4 ( V_13 , struct V_1 , V_13 ) ;
F_17 ( V_1 ) ;
}
static void F_119 ( struct V_1 * V_1 )
{
struct V_27 * V_28 ;
F_54 ( & V_1 -> V_58 ) ;
F_37 ( V_1 ) ;
while ( ( V_28 = F_116 ( V_1 -> V_17 ) ) )
F_14 ( V_28 , true ) ;
F_55 ( & V_1 -> V_58 ) ;
F_54 ( & V_1 -> V_71 ) ;
F_47 ( V_1 ) ;
while ( ( V_28 = F_116 ( V_1 -> V_18 ) ) )
F_14 ( V_28 , true ) ;
F_55 ( & V_1 -> V_71 ) ;
}
static void F_120 ( struct V_1 * V_1 )
{
F_54 ( & V_1 -> V_9 -> V_11 ) ;
F_26 ( & V_1 -> V_35 ) ;
F_55 ( & V_1 -> V_9 -> V_11 ) ;
F_54 ( & V_1 -> V_58 ) ;
if ( V_1 -> V_78 ) {
F_105 ( V_1 ) ;
V_1 -> V_78 = false ;
V_1 -> V_79 = false ;
F_121 ( & V_1 -> V_90 ) ;
}
F_55 ( & V_1 -> V_58 ) ;
if ( F_11 ( V_1 ) ) {
F_54 ( & V_6 ) ;
F_26 ( & V_1 -> V_4 . V_35 ) ;
F_55 ( & V_6 ) ;
F_122 ( V_1 -> V_4 . V_19 ) ;
}
F_119 ( V_1 ) ;
V_1 -> V_9 = NULL ;
F_123 ( & V_1 -> V_10 -> V_168 , & V_169 ) ;
F_117 ( V_134 . V_159 , V_1 -> V_10 -> V_151 ) ;
F_118 ( V_1 -> V_12 ) ;
F_124 ( V_1 -> V_166 ) ;
F_17 ( V_1 -> V_140 ) ;
F_79 ( & V_1 -> V_13 , V_119 ) ;
}
static void F_125 ( struct V_8 * V_9 ,
struct V_27 * V_28 )
{
struct V_62 * V_63 ;
struct V_1 * V_1 ;
T_3 V_170 ;
int V_56 ;
V_63 = (struct V_62 * ) ( V_28 -> V_28 + V_28 -> V_49 ) ;
V_1 = F_9 ( V_9 , V_63 -> V_14 ) ;
if ( ! V_1 && V_63 -> V_60 != V_171 ) {
F_126 ( & V_9 -> V_21 -> V_10 ,
L_22 , V_63 -> V_14 ) ;
return;
}
switch ( V_63 -> V_60 ) {
case V_171 :
if ( V_1 ) {
F_126 ( & V_9 -> V_21 -> V_10 ,
L_23 , V_1 -> V_14 ) ;
F_46 ( V_1 , V_164 , 1 ) ;
break;
}
if ( V_63 -> V_14 >= V_9 -> V_172 . V_173 ) {
F_38 ( & V_9 -> V_21 -> V_10 ,
L_24 ,
V_63 -> V_14 , V_9 -> V_172 . V_173 - 1 ) ;
break;
}
F_107 ( V_9 , V_63 -> V_14 ) ;
break;
case V_174 :
F_120 ( V_1 ) ;
break;
case V_175 :
if ( ! V_63 -> V_61 )
break;
if ( F_11 ( V_1 ) )
break;
F_94 ( V_1 ) ;
F_127 ( & V_176 ) ;
break;
case V_177 : {
struct {
T_11 V_142 ;
T_11 V_143 ;
} V_37 ;
if ( ! F_11 ( V_1 ) )
break;
memcpy ( & V_37 , V_28 -> V_28 + V_28 -> V_49 + sizeof( * V_63 ) ,
sizeof( V_37 ) ) ;
F_103 ( V_1 , V_37 . V_142 , V_37 . V_143 ) ;
V_1 -> V_4 . V_19 -> V_132 = 1 ;
F_87 ( V_1 ) ;
break;
}
case V_118 :
V_1 -> V_79 = V_63 -> V_61 ;
F_121 ( & V_1 -> V_90 ) ;
F_54 ( & V_1 -> V_71 ) ;
F_47 ( V_1 ) ;
F_55 ( & V_1 -> V_71 ) ;
F_54 ( & V_1 -> V_58 ) ;
F_105 ( V_1 ) ;
F_55 ( & V_1 -> V_58 ) ;
break;
case V_178 :
if ( V_1 -> V_140 )
break;
V_170 = V_28 -> V_48 - V_28 -> V_49 - sizeof( * V_63 ) + 1 ;
V_1 -> V_140 = F_28 ( V_170 , V_45 ) ;
if ( ! V_1 -> V_140 ) {
F_98 ( V_1 -> V_10 ,
L_25 ) ;
break;
}
strncpy ( V_1 -> V_140 , V_28 -> V_28 + V_28 -> V_49 + sizeof( * V_63 ) ,
V_170 - 1 ) ;
V_1 -> V_140 [ V_170 - 1 ] = 0 ;
V_56 = F_128 ( & V_1 -> V_10 -> V_168 ,
& V_169 ) ;
if ( V_56 ) {
F_98 ( V_1 -> V_10 ,
L_26 ,
V_56 ) ;
} else {
F_129 ( & V_1 -> V_10 -> V_168 , V_179 ) ;
}
break;
}
}
static void F_130 ( struct V_180 * V_181 )
{
struct V_8 * V_9 ;
struct V_15 * V_16 ;
struct V_27 * V_28 ;
unsigned int V_48 ;
V_9 = F_4 ( V_181 , struct V_8 , V_182 ) ;
V_16 = V_9 -> V_183 ;
F_41 ( & V_9 -> V_184 ) ;
while ( ( V_28 = F_32 ( V_16 , & V_48 ) ) ) {
F_45 ( & V_9 -> V_184 ) ;
V_28 -> V_48 = V_48 ;
V_28 -> V_49 = 0 ;
F_125 ( V_9 , V_28 ) ;
F_41 ( & V_9 -> V_184 ) ;
if ( F_33 ( V_9 -> V_183 , V_28 ) < 0 ) {
F_38 ( & V_9 -> V_21 -> V_10 ,
L_27 ) ;
F_14 ( V_28 , false ) ;
}
}
F_45 ( & V_9 -> V_184 ) ;
}
static void F_131 ( struct V_15 * V_16 )
{
struct V_1 * V_1 ;
V_1 = F_10 ( V_16 -> V_21 -> V_185 , V_16 ) ;
if ( ! V_1 )
return;
F_121 ( & V_1 -> V_90 ) ;
}
static void F_132 ( struct V_15 * V_16 )
{
struct V_1 * V_1 ;
unsigned long V_5 ;
V_1 = F_10 ( V_16 -> V_21 -> V_185 , V_16 ) ;
if ( ! V_1 )
return;
F_2 ( & V_1 -> V_58 , V_5 ) ;
V_1 -> V_50 = F_31 ( V_1 ) ;
if ( ! V_1 -> V_78 && ! F_12 ( V_1 -> V_9 -> V_21 ) )
F_37 ( V_1 ) ;
F_105 ( V_1 ) ;
F_5 ( & V_1 -> V_58 , V_5 ) ;
F_121 ( & V_1 -> V_90 ) ;
if ( F_11 ( V_1 ) && F_133 ( V_1 -> V_4 . V_19 ) )
F_134 () ;
}
static void F_135 ( struct V_15 * V_16 )
{
struct V_8 * V_9 ;
V_9 = V_16 -> V_21 -> V_185 ;
F_136 ( & V_9 -> V_182 ) ;
}
static void F_137 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
V_9 = V_21 -> V_185 ;
if ( ! F_13 ( V_9 ) ) {
struct V_1 * V_1 ;
T_9 V_142 , V_143 ;
F_138 ( V_21 , struct V_186 , V_143 , & V_143 ) ;
F_138 ( V_21 , struct V_186 , V_142 , & V_142 ) ;
V_1 = F_9 ( V_9 , 0 ) ;
F_103 ( V_1 , V_142 , V_143 ) ;
F_87 ( V_1 ) ;
}
}
static int F_139 ( struct V_8 * V_9 )
{
T_12 * * V_187 ;
char * * V_188 ;
struct V_15 * * V_189 ;
T_1 V_30 , V_190 , V_191 , V_192 ;
int V_56 ;
V_191 = V_9 -> V_172 . V_173 ;
V_192 = F_13 ( V_9 ) ? ( V_191 + 1 ) * 2 : 2 ;
V_189 = F_28 ( V_192 * sizeof( struct V_15 * ) , V_45 ) ;
V_187 = F_28 ( V_192 * sizeof( T_12 * ) , V_45 ) ;
V_188 = F_28 ( V_192 * sizeof( char * ) , V_45 ) ;
V_9 -> V_153 = F_28 ( V_191 * sizeof( struct V_15 * ) ,
V_45 ) ;
V_9 -> V_154 = F_28 ( V_191 * sizeof( struct V_15 * ) ,
V_45 ) ;
if ( ! V_189 || ! V_187 || ! V_188 || ! V_9 -> V_153 ||
! V_9 -> V_154 ) {
V_56 = - V_91 ;
goto free;
}
V_190 = 0 ;
V_187 [ V_190 ] = F_132 ;
V_187 [ V_190 + 1 ] = F_131 ;
V_188 [ V_190 ] = L_28 ;
V_188 [ V_190 + 1 ] = L_29 ;
V_190 += 2 ;
if ( F_13 ( V_9 ) ) {
V_187 [ V_190 ] = F_135 ;
V_187 [ V_190 + 1 ] = NULL ;
V_188 [ V_190 ] = L_30 ;
V_188 [ V_190 + 1 ] = L_31 ;
for ( V_30 = 1 ; V_30 < V_191 ; V_30 ++ ) {
V_190 += 2 ;
V_187 [ V_190 ] = F_132 ;
V_187 [ V_190 + 1 ] = F_131 ;
V_188 [ V_190 ] = L_28 ;
V_188 [ V_190 + 1 ] = L_29 ;
}
}
V_56 = V_9 -> V_21 -> V_172 -> V_193 ( V_9 -> V_21 , V_192 , V_189 ,
V_187 ,
( const char * * ) V_188 ) ;
if ( V_56 )
goto free;
V_190 = 0 ;
V_9 -> V_153 [ 0 ] = V_189 [ 0 ] ;
V_9 -> V_154 [ 0 ] = V_189 [ 1 ] ;
V_190 += 2 ;
if ( F_13 ( V_9 ) ) {
V_9 -> V_183 = V_189 [ V_190 ] ;
V_9 -> V_64 = V_189 [ V_190 + 1 ] ;
for ( V_30 = 1 ; V_30 < V_191 ; V_30 ++ ) {
V_190 += 2 ;
V_9 -> V_153 [ V_30 ] = V_189 [ V_190 ] ;
V_9 -> V_154 [ V_30 ] = V_189 [ V_190 + 1 ] ;
}
}
F_17 ( V_188 ) ;
F_17 ( V_187 ) ;
F_17 ( V_189 ) ;
return 0 ;
free:
F_17 ( V_9 -> V_154 ) ;
F_17 ( V_9 -> V_153 ) ;
F_17 ( V_188 ) ;
F_17 ( V_187 ) ;
F_17 ( V_189 ) ;
return V_56 ;
}
static void F_140 ( struct V_8 * V_9 )
{
V_9 -> V_21 -> V_172 -> V_194 ( V_9 -> V_21 ) ;
F_17 ( V_9 -> V_153 ) ;
F_17 ( V_9 -> V_154 ) ;
}
static void F_141 ( struct V_8 * V_9 )
{
struct V_27 * V_28 ;
unsigned int V_48 ;
if ( ! F_13 ( V_9 ) )
return;
while ( ( V_28 = F_32 ( V_9 -> V_183 , & V_48 ) ) )
F_14 ( V_28 , true ) ;
while ( ( V_28 = F_116 ( V_9 -> V_183 ) ) )
F_14 ( V_28 , true ) ;
}
static int F_142 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
int V_56 ;
bool V_195 ;
bool V_196 = V_126 != NULL ;
F_143 () ;
V_9 = F_28 ( sizeof( * V_9 ) , V_45 ) ;
if ( ! V_9 ) {
V_56 = - V_91 ;
goto V_46;
}
V_9 -> V_21 = V_21 ;
V_21 -> V_185 = V_9 ;
V_9 -> V_157 = F_144 ( 0 , L_32 ,
& V_197 ) ;
if ( V_9 -> V_157 < 0 ) {
F_98 ( & V_21 -> V_10 ,
L_33 ,
V_9 -> V_157 , V_21 -> V_160 ) ;
V_56 = V_9 -> V_157 ;
goto free;
}
V_195 = false ;
V_9 -> V_172 . V_173 = 1 ;
if ( ! F_12 ( V_21 ) &&
F_145 ( V_21 , V_26 ,
struct V_186 , V_173 ,
& V_9 -> V_172 . V_173 ) == 0 ) {
V_195 = true ;
}
V_56 = F_139 ( V_9 ) ;
if ( V_56 < 0 ) {
F_98 ( & V_21 -> V_10 , L_34 , V_56 ) ;
goto V_198;
}
F_113 ( & V_9 -> V_11 ) ;
F_146 ( & V_9 -> V_163 ) ;
F_147 ( V_9 -> V_21 ) ;
if ( V_195 ) {
unsigned int V_147 ;
F_113 ( & V_9 -> V_184 ) ;
F_113 ( & V_9 -> V_65 ) ;
F_148 ( & V_9 -> V_182 , & F_130 ) ;
V_147 = F_104 ( V_9 -> V_183 ,
& V_9 -> V_184 ) ;
if ( ! V_147 ) {
F_98 ( & V_21 -> V_10 ,
L_35 ) ;
V_56 = - V_91 ;
goto V_199;
}
} else {
F_107 ( V_9 , 0 ) ;
}
F_54 ( & V_6 ) ;
F_18 ( & V_9 -> V_35 , & V_134 . V_200 ) ;
F_55 ( & V_6 ) ;
F_40 ( V_9 , V_201 ,
V_202 , 1 ) ;
if ( V_195 && V_196 )
F_149 ( & V_176 ) ;
return 0 ;
V_199:
F_40 ( V_9 , V_201 ,
V_202 , 0 ) ;
F_140 ( V_9 ) ;
V_198:
F_150 ( V_9 -> V_157 , L_32 ) ;
free:
F_17 ( V_9 ) ;
V_46:
return V_56 ;
}
static void F_151 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 , * V_203 ;
V_9 = V_21 -> V_185 ;
F_54 ( & V_6 ) ;
F_26 ( & V_9 -> V_35 ) ;
F_55 ( & V_6 ) ;
V_21 -> V_172 -> V_204 ( V_21 ) ;
if ( F_13 ( V_9 ) )
F_152 ( & V_9 -> V_182 ) ;
F_25 (port, port2, &portdev->ports, list)
F_120 ( V_1 ) ;
F_150 ( V_9 -> V_157 , L_32 ) ;
F_141 ( V_9 ) ;
F_140 ( V_9 ) ;
F_17 ( V_9 ) ;
}
static int F_153 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
V_9 = V_21 -> V_185 ;
V_21 -> V_172 -> V_204 ( V_21 ) ;
F_154 ( V_9 -> V_183 ) ;
F_152 ( & V_9 -> V_182 ) ;
F_154 ( V_9 -> V_183 ) ;
F_141 ( V_9 ) ;
F_3 (port, &portdev->ports, list) {
F_154 ( V_1 -> V_17 ) ;
F_154 ( V_1 -> V_18 ) ;
V_1 -> V_79 = false ;
F_119 ( V_1 ) ;
}
F_140 ( V_9 ) ;
return 0 ;
}
static int F_155 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
int V_53 ;
V_9 = V_21 -> V_185 ;
V_53 = F_139 ( V_9 ) ;
if ( V_53 )
return V_53 ;
F_147 ( V_9 -> V_21 ) ;
if ( F_13 ( V_9 ) )
F_104 ( V_9 -> V_183 , & V_9 -> V_184 ) ;
F_3 (port, &portdev->ports, list) {
V_1 -> V_17 = V_9 -> V_153 [ V_1 -> V_14 ] ;
V_1 -> V_18 = V_9 -> V_154 [ V_1 -> V_14 ] ;
F_104 ( V_1 -> V_17 , & V_1 -> V_58 ) ;
F_46 ( V_1 , V_164 , 1 ) ;
if ( V_1 -> V_78 )
F_46 ( V_1 , V_118 , 1 ) ;
}
return 0 ;
}
static int T_8 F_156 ( void )
{
int V_56 ;
V_134 . V_159 = F_157 ( V_205 , L_36 ) ;
if ( F_96 ( V_134 . V_159 ) ) {
V_56 = F_97 ( V_134 . V_159 ) ;
F_158 ( L_37 , V_56 ) ;
return V_56 ;
}
V_134 . V_165 = F_159 ( L_36 , NULL ) ;
if ( ! V_134 . V_165 )
F_160 ( L_38 ) ;
F_146 ( & V_134 . V_136 ) ;
F_146 ( & V_134 . V_200 ) ;
V_56 = F_161 ( & V_206 ) ;
if ( V_56 < 0 ) {
F_158 ( L_39 , V_56 ) ;
goto free;
}
V_56 = F_161 ( & V_207 ) ;
if ( V_56 < 0 ) {
F_158 ( L_40 ,
V_56 ) ;
goto V_208;
}
return 0 ;
V_208:
F_162 ( & V_206 ) ;
free:
F_163 ( V_134 . V_165 ) ;
F_164 ( V_134 . V_159 ) ;
return V_56 ;
}
static void T_13 F_165 ( void )
{
F_21 () ;
F_162 ( & V_206 ) ;
F_162 ( & V_207 ) ;
F_164 ( V_134 . V_159 ) ;
F_163 ( V_134 . V_165 ) ;
}
