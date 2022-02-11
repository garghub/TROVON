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
while ( ! F_32 ( V_16 , & V_48 ) )
F_43 () ;
}
F_44 ( & V_9 -> V_65 ) ;
return 0 ;
}
static T_4 F_45 ( struct V_1 * V_1 , unsigned int V_60 ,
unsigned int V_61 )
{
if ( V_1 -> V_9 )
return F_40 ( V_1 -> V_9 , V_1 -> V_14 , V_60 , V_61 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_1 )
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
static T_4 F_47 ( struct V_1 * V_1 , struct V_44 * V_33 ,
int V_67 , T_3 V_68 ,
void * V_69 , bool V_70 )
{
struct V_15 * V_18 ;
int V_56 ;
unsigned long V_5 ;
unsigned int V_48 ;
V_18 = V_1 -> V_18 ;
F_2 ( & V_1 -> V_71 , V_5 ) ;
F_46 ( V_1 ) ;
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
while ( ! F_32 ( V_18 , & V_48 ) )
F_43 () ;
V_72:
F_5 ( & V_1 -> V_71 , V_5 ) ;
V_1 -> V_51 . V_73 += V_68 ;
return V_68 ;
}
static T_4 F_48 ( struct V_1 * V_1 , char * V_74 , T_3 V_75 ,
bool V_76 )
{
struct V_27 * V_28 ;
unsigned long V_5 ;
if ( ! V_75 || ! F_39 ( V_1 ) )
return 0 ;
V_28 = V_1 -> V_50 ;
V_75 = F_49 ( V_75 , V_28 -> V_48 - V_28 -> V_49 ) ;
if ( V_76 ) {
T_4 V_53 ;
V_53 = F_50 ( V_74 , V_28 -> V_28 + V_28 -> V_49 , V_75 ) ;
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
static bool F_51 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_78 ) {
return false ;
}
return ! F_39 ( V_1 ) && V_1 -> V_79 ;
}
static bool F_52 ( struct V_1 * V_1 )
{
bool V_53 ;
if ( ! V_1 -> V_78 ) {
return false ;
}
if ( ! V_1 -> V_79 )
return true ;
F_53 ( & V_1 -> V_71 ) ;
F_46 ( V_1 ) ;
V_53 = V_1 -> V_66 ;
F_54 ( & V_1 -> V_71 ) ;
return V_53 ;
}
static T_4 F_55 ( struct V_80 * V_81 , char T_5 * V_82 ,
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
V_53 = F_56 ( V_1 -> V_90 ,
! F_51 ( V_1 ) ) ;
if ( V_53 < 0 )
return V_53 ;
}
if ( ! V_1 -> V_78 )
return - V_86 ;
if ( ! F_39 ( V_1 ) && ! V_1 -> V_79 )
return 0 ;
return F_48 ( V_1 , V_82 , V_83 , true ) ;
}
static int F_57 ( struct V_1 * V_1 , bool V_70 )
{
int V_53 ;
if ( F_52 ( V_1 ) ) {
if ( V_70 )
return - V_89 ;
V_53 = F_56 ( V_1 -> V_90 ,
! F_52 ( V_1 ) ) ;
if ( V_53 < 0 )
return V_53 ;
}
if ( ! V_1 -> V_78 )
return - V_86 ;
return 0 ;
}
static T_4 F_58 ( struct V_80 * V_81 , const char T_5 * V_82 ,
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
V_53 = F_57 ( V_1 , V_70 ) ;
if ( V_53 < 0 )
return V_53 ;
V_83 = F_49 ( ( T_3 ) ( 32 * 1024 ) , V_83 ) ;
V_28 = F_27 ( V_1 -> V_18 , V_83 , 0 ) ;
if ( ! V_28 )
return - V_91 ;
V_53 = F_59 ( V_28 -> V_28 , V_82 , V_83 ) ;
if ( V_53 ) {
V_53 = - V_77 ;
goto F_14;
}
V_70 = true ;
F_34 ( V_33 , V_28 -> V_28 , V_83 ) ;
V_53 = F_47 ( V_1 , V_33 , 1 , V_83 , V_28 , V_70 ) ;
if ( V_70 && V_53 > 0 )
goto V_7;
F_14:
F_14 ( V_28 , true ) ;
V_7:
return V_53 ;
}
static int F_60 ( struct V_92 * V_93 , struct V_94 * V_28 ,
struct V_95 * V_96 )
{
struct V_97 * V_98 = V_96 -> V_99 . V_69 ;
unsigned int V_49 , V_48 ;
if ( V_98 -> V_100 == V_98 -> V_37 )
return 0 ;
if ( V_28 -> V_101 -> V_102 ( V_93 , V_28 ) == 0 ) {
F_61 ( V_28 -> V_32 ) ;
F_62 ( V_28 -> V_32 ) ;
V_48 = F_49 ( V_28 -> V_48 , V_96 -> V_48 ) ;
F_63 ( & ( V_98 -> V_33 [ V_98 -> V_100 ] ) , V_28 -> V_32 , V_48 , V_28 -> V_49 ) ;
} else {
struct V_32 * V_32 = F_64 ( V_45 ) ;
char * V_103 = V_28 -> V_101 -> V_104 ( V_93 , V_28 , 1 ) ;
char * V_105 ;
if ( ! V_32 )
return - V_91 ;
V_105 = F_65 ( V_32 ) ;
V_49 = V_96 -> V_106 & ~ V_107 ;
V_48 = V_96 -> V_48 ;
if ( V_48 + V_49 > V_108 )
V_48 = V_108 - V_49 ;
memcpy ( V_105 + V_49 , V_103 + V_28 -> V_49 , V_48 ) ;
F_66 ( V_32 ) ;
V_28 -> V_101 -> V_109 ( V_93 , V_28 , V_103 ) ;
F_63 ( & ( V_98 -> V_33 [ V_98 -> V_100 ] ) , V_32 , V_48 , V_49 ) ;
}
V_98 -> V_100 ++ ;
V_98 -> V_48 += V_48 ;
return V_48 ;
}
static T_4 F_67 ( struct V_92 * V_93 ,
struct V_80 * V_81 , T_6 * V_110 ,
T_3 V_48 , unsigned int V_5 )
{
struct V_1 * V_1 = V_81 -> V_85 ;
struct V_97 V_98 ;
T_4 V_53 ;
struct V_27 * V_28 ;
struct V_95 V_96 = {
. V_111 = V_48 ,
. V_5 = V_5 ,
. V_106 = * V_110 ,
. V_99 . V_69 = & V_98 ,
} ;
if ( F_12 ( V_1 -> V_18 -> V_21 ) )
return - V_112 ;
F_68 ( V_93 ) ;
if ( ! V_93 -> V_113 ) {
V_53 = 0 ;
goto V_114;
}
V_53 = F_57 ( V_1 , V_81 -> V_87 & V_88 ) ;
if ( V_53 < 0 )
goto V_114;
V_28 = F_27 ( V_1 -> V_18 , 0 , V_93 -> V_113 ) ;
if ( ! V_28 ) {
V_53 = - V_91 ;
goto V_114;
}
V_98 . V_100 = 0 ;
V_98 . V_48 = 0 ;
V_98 . V_37 = V_93 -> V_113 ;
V_98 . V_33 = V_28 -> V_33 ;
F_69 ( V_98 . V_33 , V_98 . V_37 ) ;
V_53 = F_70 ( V_93 , & V_96 , F_60 ) ;
F_71 ( V_93 ) ;
if ( F_72 ( V_53 > 0 ) )
V_53 = F_47 ( V_1 , V_28 -> V_33 , V_98 . V_100 , V_98 . V_48 , V_28 , true ) ;
if ( F_73 ( V_53 <= 0 ) )
F_14 ( V_28 , true ) ;
return V_53 ;
V_114:
F_71 ( V_93 ) ;
return V_53 ;
}
static unsigned int F_74 ( struct V_80 * V_81 , T_7 * V_115 )
{
struct V_1 * V_1 ;
unsigned int V_53 ;
V_1 = V_81 -> V_85 ;
F_75 ( V_81 , & V_1 -> V_90 , V_115 ) ;
if ( ! V_1 -> V_78 ) {
return V_116 ;
}
V_53 = 0 ;
if ( ! F_51 ( V_1 ) )
V_53 |= V_117 | V_118 ;
if ( ! F_52 ( V_1 ) )
V_53 |= V_119 ;
if ( ! V_1 -> V_79 )
V_53 |= V_116 ;
return V_53 ;
}
static int F_76 ( struct V_120 * V_120 , struct V_80 * V_81 )
{
struct V_1 * V_1 ;
V_1 = V_81 -> V_85 ;
F_45 ( V_1 , V_121 , 0 ) ;
F_53 ( & V_1 -> V_58 ) ;
V_1 -> V_78 = false ;
F_37 ( V_1 ) ;
F_54 ( & V_1 -> V_58 ) ;
F_53 ( & V_1 -> V_71 ) ;
F_46 ( V_1 ) ;
F_54 ( & V_1 -> V_71 ) ;
F_21 () ;
F_77 ( & V_1 -> V_13 , V_122 ) ;
return 0 ;
}
static int F_78 ( struct V_120 * V_120 , struct V_80 * V_81 )
{
struct V_12 * V_12 = V_120 -> V_123 ;
struct V_1 * V_1 ;
int V_53 ;
V_1 = F_8 ( V_12 -> V_10 ) ;
if ( ! V_1 ) {
return - V_124 ;
}
V_81 -> V_85 = V_1 ;
if ( F_11 ( V_1 ) ) {
V_53 = - V_124 ;
goto V_7;
}
F_53 ( & V_1 -> V_58 ) ;
if ( V_1 -> V_78 ) {
F_54 ( & V_1 -> V_58 ) ;
V_53 = - V_125 ;
goto V_7;
}
V_1 -> V_78 = true ;
F_54 ( & V_1 -> V_58 ) ;
F_53 ( & V_1 -> V_71 ) ;
F_46 ( V_1 ) ;
F_54 ( & V_1 -> V_71 ) ;
F_79 ( V_120 , V_81 ) ;
F_45 ( V_81 -> V_85 , V_121 , 1 ) ;
return 0 ;
V_7:
F_77 ( & V_1 -> V_13 , V_122 ) ;
return V_53 ;
}
static int F_80 ( int V_126 , struct V_80 * V_81 , int V_127 )
{
struct V_1 * V_1 ;
V_1 = V_81 -> V_85 ;
return F_81 ( V_126 , V_81 , V_127 , & V_1 -> V_128 ) ;
}
static int F_82 ( T_1 V_2 , const char * V_28 , int V_83 )
{
struct V_1 * V_1 ;
struct V_44 V_33 [ 1 ] ;
if ( F_73 ( V_129 ) )
return V_129 ( V_2 , V_28 , V_83 ) ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_130 ;
F_34 ( V_33 , V_28 , V_83 ) ;
return F_47 ( V_1 , V_33 , 1 , V_83 , ( void * ) V_28 , false ) ;
}
static int F_83 ( T_1 V_2 , char * V_28 , int V_83 )
{
struct V_1 * V_1 ;
if ( F_73 ( V_129 ) )
return 0 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_130 ;
F_84 ( ! V_1 -> V_17 ) ;
return F_48 ( V_1 , V_28 , V_83 , false ) ;
}
static void F_85 ( struct V_1 * V_1 )
{
struct V_20 * V_21 ;
if ( ! V_1 || ! F_11 ( V_1 ) )
return;
V_21 = V_1 -> V_9 -> V_21 ;
if ( ! F_12 ( V_21 ) &&
F_86 ( V_21 , V_131 ) )
F_87 ( V_1 -> V_4 . V_19 , V_1 -> V_4 . V_132 ) ;
}
static int F_88 ( struct V_133 * V_134 , int V_69 )
{
struct V_1 * V_1 ;
V_1 = F_1 ( V_134 -> V_2 ) ;
if ( ! V_1 )
return - V_112 ;
V_134 -> V_135 = 1 ;
F_85 ( V_1 ) ;
return 0 ;
}
static void F_89 ( struct V_133 * V_134 , int V_69 )
{
V_134 -> V_135 = 0 ;
}
int T_8 F_90 ( int (* F_82)( T_1 , const char * , int ) )
{
V_129 = F_82 ;
return F_91 ( 0 , 0 , & V_136 ) ;
}
static int F_92 ( struct V_1 * V_1 )
{
int V_53 ;
V_1 -> V_4 . V_2 = V_137 . V_138 ;
V_1 -> V_4 . V_19 = F_93 ( V_1 -> V_4 . V_2 , 0 , & V_136 , V_108 ) ;
if ( F_94 ( V_1 -> V_4 . V_19 ) ) {
V_53 = F_95 ( V_1 -> V_4 . V_19 ) ;
F_96 ( V_1 -> V_10 ,
L_3 , V_53 ) ;
V_1 -> V_4 . V_19 = NULL ;
return V_53 ;
}
F_53 ( & V_6 ) ;
V_137 . V_138 ++ ;
F_18 ( & V_1 -> V_4 . V_35 , & V_137 . V_139 ) ;
F_54 ( & V_6 ) ;
V_1 -> V_78 = true ;
if ( V_129 )
V_129 = NULL ;
F_45 ( V_1 , V_121 , 1 ) ;
return 0 ;
}
static T_4 F_97 ( struct V_23 * V_10 ,
struct V_140 * V_141 , char * V_142 )
{
struct V_1 * V_1 ;
V_1 = F_98 ( V_10 ) ;
return sprintf ( V_142 , L_4 , V_1 -> V_143 ) ;
}
static T_4 F_99 ( struct V_80 * V_81 , char T_5 * V_82 ,
T_3 V_83 , T_6 * V_84 )
{
struct V_1 * V_1 ;
char * V_28 ;
T_4 V_53 , V_144 , V_75 ;
V_75 = 1024 ;
V_28 = F_28 ( V_75 , V_45 ) ;
if ( ! V_28 )
return - V_91 ;
V_1 = V_81 -> V_85 ;
V_144 = 0 ;
V_144 += snprintf ( V_28 + V_144 , V_75 ,
L_5 , V_1 -> V_143 ? V_1 -> V_143 : L_6 ) ;
V_144 += snprintf ( V_28 + V_144 , V_75 - V_144 ,
L_7 , V_1 -> V_78 ) ;
V_144 += snprintf ( V_28 + V_144 , V_75 - V_144 ,
L_8 , V_1 -> V_79 ) ;
V_144 += snprintf ( V_28 + V_144 , V_75 - V_144 ,
L_9 , V_1 -> V_66 ) ;
V_144 += snprintf ( V_28 + V_144 , V_75 - V_144 ,
L_10 , V_1 -> V_51 . V_73 ) ;
V_144 += snprintf ( V_28 + V_144 , V_75 - V_144 ,
L_11 ,
V_1 -> V_51 . V_52 ) ;
V_144 += snprintf ( V_28 + V_144 , V_75 - V_144 ,
L_12 ,
V_1 -> V_51 . V_57 ) ;
V_144 += snprintf ( V_28 + V_144 , V_75 - V_144 ,
L_13 ,
F_11 ( V_1 ) ? L_14 : L_15 ) ;
V_144 += snprintf ( V_28 + V_144 , V_75 - V_144 ,
L_16 , V_1 -> V_4 . V_2 ) ;
V_53 = F_100 ( V_82 , V_83 , V_84 , V_28 , V_144 ) ;
F_17 ( V_28 ) ;
return V_53 ;
}
static void F_101 ( struct V_1 * V_1 , T_9 V_145 , T_9 V_146 )
{
if ( ! V_1 || ! F_11 ( V_1 ) )
return;
V_1 -> V_4 . V_132 . V_147 = V_145 ;
V_1 -> V_4 . V_132 . V_148 = V_146 ;
}
static unsigned int F_102 ( struct V_15 * V_16 , T_10 * V_149 )
{
struct V_27 * V_28 ;
unsigned int V_150 ;
int V_53 ;
V_150 = 0 ;
do {
V_28 = F_27 ( V_16 , V_108 , 0 ) ;
if ( ! V_28 )
break;
F_53 ( V_149 ) ;
V_53 = F_33 ( V_16 , V_28 ) ;
if ( V_53 < 0 ) {
F_54 ( V_149 ) ;
F_14 ( V_28 , true ) ;
break;
}
V_150 ++ ;
F_54 ( V_149 ) ;
} while ( V_53 > 0 );
return V_150 ;
}
static void F_103 ( struct V_1 * V_1 )
{
if ( V_1 -> V_128 && V_1 -> V_78 )
F_104 ( & V_1 -> V_128 , V_151 , V_152 ) ;
}
static int F_105 ( struct V_8 * V_9 , T_1 V_14 )
{
char V_153 [ 16 ] ;
struct V_1 * V_1 ;
struct V_27 * V_28 ;
T_2 V_154 ;
unsigned int V_150 ;
int V_56 ;
V_1 = F_28 ( sizeof( * V_1 ) , V_45 ) ;
if ( ! V_1 ) {
V_56 = - V_91 ;
goto V_46;
}
F_106 ( & V_1 -> V_13 ) ;
V_1 -> V_9 = V_9 ;
V_1 -> V_14 = V_14 ;
V_1 -> V_143 = NULL ;
V_1 -> V_50 = NULL ;
V_1 -> V_4 . V_19 = NULL ;
V_1 -> V_128 = NULL ;
V_1 -> V_4 . V_132 . V_147 = V_1 -> V_4 . V_132 . V_148 = 0 ;
V_1 -> V_79 = V_1 -> V_78 = false ;
V_1 -> V_51 = (struct V_155 ) { 0 } ;
V_1 -> V_66 = false ;
V_1 -> V_17 = V_9 -> V_156 [ V_1 -> V_14 ] ;
V_1 -> V_18 = V_9 -> V_157 [ V_1 -> V_14 ] ;
V_1 -> V_12 = F_107 () ;
if ( ! V_1 -> V_12 ) {
F_96 ( & V_1 -> V_9 -> V_21 -> V_10 , L_17 ) ;
V_56 = - V_91 ;
goto V_158;
}
V_1 -> V_12 -> V_101 = & V_159 ;
V_154 = F_108 ( V_9 -> V_160 , V_14 ) ;
V_56 = F_109 ( V_1 -> V_12 , V_154 , 1 ) ;
if ( V_56 < 0 ) {
F_96 ( & V_1 -> V_9 -> V_21 -> V_10 ,
L_18 , V_56 , V_14 ) ;
goto V_161;
}
V_1 -> V_10 = F_110 ( V_137 . V_162 , & V_1 -> V_9 -> V_21 -> V_10 ,
V_154 , V_1 , L_19 ,
V_1 -> V_9 -> V_21 -> V_163 , V_14 ) ;
if ( F_94 ( V_1 -> V_10 ) ) {
V_56 = F_95 ( V_1 -> V_10 ) ;
F_96 ( & V_1 -> V_9 -> V_21 -> V_10 ,
L_20 ,
V_56 , V_14 ) ;
goto V_161;
}
F_111 ( & V_1 -> V_58 ) ;
F_111 ( & V_1 -> V_71 ) ;
F_112 ( & V_1 -> V_90 ) ;
V_150 = F_102 ( V_1 -> V_17 , & V_1 -> V_58 ) ;
if ( ! V_150 ) {
F_96 ( V_1 -> V_10 , L_21 ) ;
V_56 = - V_91 ;
goto V_164;
}
if ( F_12 ( V_1 -> V_9 -> V_21 ) )
V_1 -> V_79 = true ;
else if ( ! F_13 ( V_1 -> V_9 ) ) {
V_56 = F_92 ( V_1 ) ;
if ( V_56 )
goto V_165;
}
F_53 ( & V_9 -> V_11 ) ;
F_18 ( & V_1 -> V_35 , & V_1 -> V_9 -> V_166 ) ;
F_54 ( & V_9 -> V_11 ) ;
F_45 ( V_1 , V_167 , 1 ) ;
if ( V_137 . V_168 ) {
sprintf ( V_153 , L_19 ,
V_1 -> V_9 -> V_21 -> V_163 , V_14 ) ;
V_1 -> V_169 = F_113 ( V_153 , 0444 ,
V_137 . V_168 ,
V_1 ,
& V_170 ) ;
}
return 0 ;
V_165:
while ( ( V_28 = F_114 ( V_1 -> V_17 ) ) )
F_14 ( V_28 , true ) ;
V_164:
F_115 ( V_137 . V_162 , V_1 -> V_10 -> V_154 ) ;
V_161:
F_116 ( V_1 -> V_12 ) ;
V_158:
F_17 ( V_1 ) ;
V_46:
F_40 ( V_9 , V_14 , V_167 , 0 ) ;
return V_56 ;
}
static void V_122 ( struct V_13 * V_13 )
{
struct V_1 * V_1 ;
V_1 = F_4 ( V_13 , struct V_1 , V_13 ) ;
F_17 ( V_1 ) ;
}
static void F_117 ( struct V_1 * V_1 )
{
struct V_27 * V_28 ;
F_53 ( & V_1 -> V_58 ) ;
F_37 ( V_1 ) ;
while ( ( V_28 = F_114 ( V_1 -> V_17 ) ) )
F_14 ( V_28 , true ) ;
F_54 ( & V_1 -> V_58 ) ;
F_53 ( & V_1 -> V_71 ) ;
F_46 ( V_1 ) ;
while ( ( V_28 = F_114 ( V_1 -> V_18 ) ) )
F_14 ( V_28 , true ) ;
F_54 ( & V_1 -> V_71 ) ;
}
static void F_118 ( struct V_1 * V_1 )
{
F_53 ( & V_1 -> V_9 -> V_11 ) ;
F_26 ( & V_1 -> V_35 ) ;
F_54 ( & V_1 -> V_9 -> V_11 ) ;
F_53 ( & V_1 -> V_58 ) ;
if ( V_1 -> V_78 ) {
F_103 ( V_1 ) ;
V_1 -> V_78 = false ;
V_1 -> V_79 = false ;
F_119 ( & V_1 -> V_90 ) ;
}
F_54 ( & V_1 -> V_58 ) ;
if ( F_11 ( V_1 ) ) {
F_53 ( & V_6 ) ;
F_26 ( & V_1 -> V_4 . V_35 ) ;
F_54 ( & V_6 ) ;
F_120 ( V_1 -> V_4 . V_19 ) ;
}
F_117 ( V_1 ) ;
V_1 -> V_9 = NULL ;
F_121 ( & V_1 -> V_10 -> V_171 , & V_172 ) ;
F_115 ( V_137 . V_162 , V_1 -> V_10 -> V_154 ) ;
F_116 ( V_1 -> V_12 ) ;
F_122 ( V_1 -> V_169 ) ;
F_17 ( V_1 -> V_143 ) ;
F_77 ( & V_1 -> V_13 , V_122 ) ;
}
static void F_123 ( struct V_8 * V_9 ,
struct V_27 * V_28 )
{
struct V_62 * V_63 ;
struct V_1 * V_1 ;
T_3 V_173 ;
int V_56 ;
V_63 = (struct V_62 * ) ( V_28 -> V_28 + V_28 -> V_49 ) ;
V_1 = F_9 ( V_9 , V_63 -> V_14 ) ;
if ( ! V_1 && V_63 -> V_60 != V_174 ) {
F_124 ( & V_9 -> V_21 -> V_10 ,
L_22 , V_63 -> V_14 ) ;
return;
}
switch ( V_63 -> V_60 ) {
case V_174 :
if ( V_1 ) {
F_124 ( & V_9 -> V_21 -> V_10 ,
L_23 , V_1 -> V_14 ) ;
F_45 ( V_1 , V_167 , 1 ) ;
break;
}
if ( V_63 -> V_14 >= V_9 -> V_175 . V_176 ) {
F_38 ( & V_9 -> V_21 -> V_10 ,
L_24 ,
V_63 -> V_14 , V_9 -> V_175 . V_176 - 1 ) ;
break;
}
F_105 ( V_9 , V_63 -> V_14 ) ;
break;
case V_177 :
F_118 ( V_1 ) ;
break;
case V_178 :
if ( ! V_63 -> V_61 )
break;
if ( F_11 ( V_1 ) )
break;
F_92 ( V_1 ) ;
F_125 ( & V_179 ) ;
break;
case V_180 : {
struct {
T_11 V_145 ;
T_11 V_146 ;
} V_37 ;
if ( ! F_11 ( V_1 ) )
break;
memcpy ( & V_37 , V_28 -> V_28 + V_28 -> V_49 + sizeof( * V_63 ) ,
sizeof( V_37 ) ) ;
F_101 ( V_1 , V_37 . V_145 , V_37 . V_146 ) ;
V_1 -> V_4 . V_19 -> V_135 = 1 ;
F_85 ( V_1 ) ;
break;
}
case V_121 :
V_1 -> V_79 = V_63 -> V_61 ;
F_119 ( & V_1 -> V_90 ) ;
F_53 ( & V_1 -> V_71 ) ;
F_46 ( V_1 ) ;
F_54 ( & V_1 -> V_71 ) ;
F_53 ( & V_1 -> V_58 ) ;
F_103 ( V_1 ) ;
F_54 ( & V_1 -> V_58 ) ;
break;
case V_181 :
if ( V_1 -> V_143 )
break;
V_173 = V_28 -> V_48 - V_28 -> V_49 - sizeof( * V_63 ) + 1 ;
V_1 -> V_143 = F_28 ( V_173 , V_45 ) ;
if ( ! V_1 -> V_143 ) {
F_96 ( V_1 -> V_10 ,
L_25 ) ;
break;
}
strncpy ( V_1 -> V_143 , V_28 -> V_28 + V_28 -> V_49 + sizeof( * V_63 ) ,
V_173 - 1 ) ;
V_1 -> V_143 [ V_173 - 1 ] = 0 ;
V_56 = F_126 ( & V_1 -> V_10 -> V_171 ,
& V_172 ) ;
if ( V_56 ) {
F_96 ( V_1 -> V_10 ,
L_26 ,
V_56 ) ;
} else {
F_127 ( & V_1 -> V_10 -> V_171 , V_182 ) ;
}
break;
}
}
static void F_128 ( struct V_183 * V_184 )
{
struct V_8 * V_9 ;
struct V_15 * V_16 ;
struct V_27 * V_28 ;
unsigned int V_48 ;
V_9 = F_4 ( V_184 , struct V_8 , V_185 ) ;
V_16 = V_9 -> V_186 ;
F_41 ( & V_9 -> V_187 ) ;
while ( ( V_28 = F_32 ( V_16 , & V_48 ) ) ) {
F_44 ( & V_9 -> V_187 ) ;
V_28 -> V_48 = V_48 ;
V_28 -> V_49 = 0 ;
F_123 ( V_9 , V_28 ) ;
F_41 ( & V_9 -> V_187 ) ;
if ( F_33 ( V_9 -> V_186 , V_28 ) < 0 ) {
F_38 ( & V_9 -> V_21 -> V_10 ,
L_27 ) ;
F_14 ( V_28 , false ) ;
}
}
F_44 ( & V_9 -> V_187 ) ;
}
static void F_129 ( struct V_15 * V_16 )
{
struct V_1 * V_1 ;
V_1 = F_10 ( V_16 -> V_21 -> V_188 , V_16 ) ;
if ( ! V_1 )
return;
F_119 ( & V_1 -> V_90 ) ;
}
static void F_130 ( struct V_15 * V_16 )
{
struct V_1 * V_1 ;
unsigned long V_5 ;
V_1 = F_10 ( V_16 -> V_21 -> V_188 , V_16 ) ;
if ( ! V_1 )
return;
F_2 ( & V_1 -> V_58 , V_5 ) ;
V_1 -> V_50 = F_31 ( V_1 ) ;
if ( ! V_1 -> V_78 && ! F_12 ( V_1 -> V_9 -> V_21 ) )
F_37 ( V_1 ) ;
F_103 ( V_1 ) ;
F_5 ( & V_1 -> V_58 , V_5 ) ;
F_119 ( & V_1 -> V_90 ) ;
if ( F_11 ( V_1 ) && F_131 ( V_1 -> V_4 . V_19 ) )
F_132 () ;
}
static void F_133 ( struct V_15 * V_16 )
{
struct V_8 * V_9 ;
V_9 = V_16 -> V_21 -> V_188 ;
F_134 ( & V_9 -> V_185 ) ;
}
static void F_135 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
V_9 = V_21 -> V_188 ;
if ( ! F_13 ( V_9 ) ) {
struct V_1 * V_1 ;
T_9 V_145 , V_146 ;
V_21 -> V_175 -> V_189 ( V_21 ,
F_136 ( struct V_190 , V_146 ) ,
& V_146 , sizeof( T_9 ) ) ;
V_21 -> V_175 -> V_189 ( V_21 ,
F_136 ( struct V_190 , V_145 ) ,
& V_145 , sizeof( T_9 ) ) ;
V_1 = F_9 ( V_9 , 0 ) ;
F_101 ( V_1 , V_145 , V_146 ) ;
F_85 ( V_1 ) ;
}
}
static int F_137 ( struct V_8 * V_9 )
{
T_12 * * V_191 ;
char * * V_192 ;
struct V_15 * * V_193 ;
T_1 V_30 , V_194 , V_195 , V_196 ;
int V_56 ;
V_195 = V_9 -> V_175 . V_176 ;
V_196 = F_13 ( V_9 ) ? ( V_195 + 1 ) * 2 : 2 ;
V_193 = F_28 ( V_196 * sizeof( struct V_15 * ) , V_45 ) ;
V_191 = F_28 ( V_196 * sizeof( T_12 * ) , V_45 ) ;
V_192 = F_28 ( V_196 * sizeof( char * ) , V_45 ) ;
V_9 -> V_156 = F_28 ( V_195 * sizeof( struct V_15 * ) ,
V_45 ) ;
V_9 -> V_157 = F_28 ( V_195 * sizeof( struct V_15 * ) ,
V_45 ) ;
if ( ! V_193 || ! V_191 || ! V_192 || ! V_9 -> V_156 ||
! V_9 -> V_157 ) {
V_56 = - V_91 ;
goto free;
}
V_194 = 0 ;
V_191 [ V_194 ] = F_130 ;
V_191 [ V_194 + 1 ] = F_129 ;
V_192 [ V_194 ] = L_28 ;
V_192 [ V_194 + 1 ] = L_29 ;
V_194 += 2 ;
if ( F_13 ( V_9 ) ) {
V_191 [ V_194 ] = F_133 ;
V_191 [ V_194 + 1 ] = NULL ;
V_192 [ V_194 ] = L_30 ;
V_192 [ V_194 + 1 ] = L_31 ;
for ( V_30 = 1 ; V_30 < V_195 ; V_30 ++ ) {
V_194 += 2 ;
V_191 [ V_194 ] = F_130 ;
V_191 [ V_194 + 1 ] = F_129 ;
V_192 [ V_194 ] = L_28 ;
V_192 [ V_194 + 1 ] = L_29 ;
}
}
V_56 = V_9 -> V_21 -> V_175 -> V_197 ( V_9 -> V_21 , V_196 , V_193 ,
V_191 ,
( const char * * ) V_192 ) ;
if ( V_56 )
goto free;
V_194 = 0 ;
V_9 -> V_156 [ 0 ] = V_193 [ 0 ] ;
V_9 -> V_157 [ 0 ] = V_193 [ 1 ] ;
V_194 += 2 ;
if ( F_13 ( V_9 ) ) {
V_9 -> V_186 = V_193 [ V_194 ] ;
V_9 -> V_64 = V_193 [ V_194 + 1 ] ;
for ( V_30 = 1 ; V_30 < V_195 ; V_30 ++ ) {
V_194 += 2 ;
V_9 -> V_156 [ V_30 ] = V_193 [ V_194 ] ;
V_9 -> V_157 [ V_30 ] = V_193 [ V_194 + 1 ] ;
}
}
F_17 ( V_192 ) ;
F_17 ( V_191 ) ;
F_17 ( V_193 ) ;
return 0 ;
free:
F_17 ( V_9 -> V_157 ) ;
F_17 ( V_9 -> V_156 ) ;
F_17 ( V_192 ) ;
F_17 ( V_191 ) ;
F_17 ( V_193 ) ;
return V_56 ;
}
static void F_138 ( struct V_8 * V_9 )
{
V_9 -> V_21 -> V_175 -> V_198 ( V_9 -> V_21 ) ;
F_17 ( V_9 -> V_156 ) ;
F_17 ( V_9 -> V_157 ) ;
}
static void F_139 ( struct V_8 * V_9 )
{
struct V_27 * V_28 ;
unsigned int V_48 ;
if ( ! F_13 ( V_9 ) )
return;
while ( ( V_28 = F_32 ( V_9 -> V_186 , & V_48 ) ) )
F_14 ( V_28 , true ) ;
while ( ( V_28 = F_114 ( V_9 -> V_186 ) ) )
F_14 ( V_28 , true ) ;
}
static int F_140 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
int V_56 ;
bool V_199 ;
bool V_200 = V_129 != NULL ;
F_141 () ;
V_9 = F_28 ( sizeof( * V_9 ) , V_45 ) ;
if ( ! V_9 ) {
V_56 = - V_91 ;
goto V_46;
}
V_9 -> V_21 = V_21 ;
V_21 -> V_188 = V_9 ;
V_9 -> V_160 = F_142 ( 0 , L_32 ,
& V_201 ) ;
if ( V_9 -> V_160 < 0 ) {
F_96 ( & V_21 -> V_10 ,
L_33 ,
V_9 -> V_160 , V_21 -> V_163 ) ;
V_56 = V_9 -> V_160 ;
goto free;
}
V_199 = false ;
V_9 -> V_175 . V_176 = 1 ;
if ( ! F_12 ( V_21 ) &&
F_143 ( V_21 , V_26 ,
F_136 ( struct V_190 ,
V_176 ) ,
& V_9 -> V_175 . V_176 ) == 0 ) {
V_199 = true ;
}
V_56 = F_137 ( V_9 ) ;
if ( V_56 < 0 ) {
F_96 ( & V_21 -> V_10 , L_34 , V_56 ) ;
goto V_202;
}
F_111 ( & V_9 -> V_11 ) ;
F_144 ( & V_9 -> V_166 ) ;
if ( V_199 ) {
unsigned int V_150 ;
F_111 ( & V_9 -> V_187 ) ;
F_111 ( & V_9 -> V_65 ) ;
F_145 ( & V_9 -> V_185 , & F_128 ) ;
V_150 = F_102 ( V_9 -> V_186 ,
& V_9 -> V_187 ) ;
if ( ! V_150 ) {
F_96 ( & V_21 -> V_10 ,
L_35 ) ;
V_56 = - V_91 ;
goto V_203;
}
} else {
F_105 ( V_9 , 0 ) ;
}
F_53 ( & V_6 ) ;
F_18 ( & V_9 -> V_35 , & V_137 . V_204 ) ;
F_54 ( & V_6 ) ;
F_40 ( V_9 , V_205 ,
V_206 , 1 ) ;
if ( V_199 && V_200 )
F_146 ( & V_179 ) ;
return 0 ;
V_203:
F_40 ( V_9 , V_205 ,
V_206 , 0 ) ;
F_138 ( V_9 ) ;
V_202:
F_147 ( V_9 -> V_160 , L_32 ) ;
free:
F_17 ( V_9 ) ;
V_46:
return V_56 ;
}
static void F_148 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 , * V_207 ;
V_9 = V_21 -> V_188 ;
F_53 ( & V_6 ) ;
F_26 ( & V_9 -> V_35 ) ;
F_54 ( & V_6 ) ;
V_21 -> V_175 -> V_208 ( V_21 ) ;
if ( F_13 ( V_9 ) )
F_149 ( & V_9 -> V_185 ) ;
F_25 (port, port2, &portdev->ports, list)
F_118 ( V_1 ) ;
F_147 ( V_9 -> V_160 , L_32 ) ;
F_139 ( V_9 ) ;
F_138 ( V_9 ) ;
F_17 ( V_9 ) ;
}
static int F_150 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
V_9 = V_21 -> V_188 ;
V_21 -> V_175 -> V_208 ( V_21 ) ;
F_151 ( V_9 -> V_186 ) ;
F_149 ( & V_9 -> V_185 ) ;
F_151 ( V_9 -> V_186 ) ;
F_139 ( V_9 ) ;
F_3 (port, &portdev->ports, list) {
F_151 ( V_1 -> V_17 ) ;
F_151 ( V_1 -> V_18 ) ;
V_1 -> V_79 = false ;
F_117 ( V_1 ) ;
}
F_138 ( V_9 ) ;
return 0 ;
}
static int F_152 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
int V_53 ;
V_9 = V_21 -> V_188 ;
V_53 = F_137 ( V_9 ) ;
if ( V_53 )
return V_53 ;
if ( F_13 ( V_9 ) )
F_102 ( V_9 -> V_186 , & V_9 -> V_187 ) ;
F_3 (port, &portdev->ports, list) {
V_1 -> V_17 = V_9 -> V_156 [ V_1 -> V_14 ] ;
V_1 -> V_18 = V_9 -> V_157 [ V_1 -> V_14 ] ;
F_102 ( V_1 -> V_17 , & V_1 -> V_58 ) ;
F_45 ( V_1 , V_167 , 1 ) ;
if ( V_1 -> V_78 )
F_45 ( V_1 , V_121 , 1 ) ;
}
return 0 ;
}
static int T_8 F_153 ( void )
{
int V_56 ;
V_137 . V_162 = F_154 ( V_209 , L_36 ) ;
if ( F_94 ( V_137 . V_162 ) ) {
V_56 = F_95 ( V_137 . V_162 ) ;
F_155 ( L_37 , V_56 ) ;
return V_56 ;
}
V_137 . V_168 = F_156 ( L_36 , NULL ) ;
if ( ! V_137 . V_168 )
F_157 ( L_38 ) ;
F_144 ( & V_137 . V_139 ) ;
F_144 ( & V_137 . V_204 ) ;
V_56 = F_158 ( & V_210 ) ;
if ( V_56 < 0 ) {
F_155 ( L_39 , V_56 ) ;
goto free;
}
V_56 = F_158 ( & V_211 ) ;
if ( V_56 < 0 ) {
F_155 ( L_40 ,
V_56 ) ;
goto V_212;
}
return 0 ;
V_212:
F_159 ( & V_210 ) ;
free:
if ( V_137 . V_168 )
F_160 ( V_137 . V_168 ) ;
F_161 ( V_137 . V_162 ) ;
return V_56 ;
}
static void T_13 F_162 ( void )
{
F_21 () ;
F_159 ( & V_210 ) ;
F_159 ( & V_211 ) ;
F_161 ( V_137 . V_162 ) ;
if ( V_137 . V_168 )
F_160 ( V_137 . V_168 ) ;
}
