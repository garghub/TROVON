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
return F_14 ( V_9 -> V_21 , V_25 ) ;
}
static void F_15 ( struct V_26 * V_27 , bool V_28 )
{
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < V_27 -> V_30 ; V_29 ++ ) {
struct V_31 * V_31 = F_16 ( & V_27 -> V_32 [ V_29 ] ) ;
if ( ! V_31 )
break;
F_17 ( V_31 ) ;
}
if ( ! V_27 -> V_10 ) {
F_18 ( V_27 -> V_27 ) ;
} else if ( V_22 ) {
unsigned long V_5 ;
if ( ! V_28 ) {
F_2 ( & V_33 , V_5 ) ;
F_19 ( & V_27 -> V_34 , & V_35 ) ;
F_5 ( & V_33 , V_5 ) ;
return;
}
F_20 ( V_27 -> V_10 , V_27 -> V_36 , V_27 -> V_27 , V_27 -> V_37 ) ;
F_21 ( V_27 -> V_10 ) ;
}
F_18 ( V_27 ) ;
}
static void F_22 ( void )
{
unsigned long V_5 ;
struct V_26 * V_27 , * V_38 ;
F_23 ( V_39 ) ;
if ( F_24 ( & V_35 ) )
return;
F_2 ( & V_33 , V_5 ) ;
F_25 ( & V_39 , & V_35 ,
V_35 . V_40 ) ;
F_5 ( & V_33 , V_5 ) ;
F_26 (buf, tmp, &tmp_list, list) {
F_27 ( & V_27 -> V_34 ) ;
F_15 ( V_27 , true ) ;
}
}
static struct V_26 * F_28 ( struct V_15 * V_16 , T_3 V_41 ,
int V_42 )
{
struct V_26 * V_27 ;
F_22 () ;
V_27 = F_29 ( sizeof( * V_27 ) + sizeof( struct V_43 ) * V_42 ,
V_44 ) ;
if ( ! V_27 )
goto V_45;
V_27 -> V_30 = V_42 ;
if ( V_42 > 0 ) {
V_27 -> V_10 = NULL ;
V_27 -> V_27 = NULL ;
return V_27 ;
}
if ( F_12 ( V_16 -> V_21 ) ) {
if ( ! V_16 -> V_21 -> V_10 . V_46 || ! V_16 -> V_21 -> V_10 . V_46 -> V_46 )
goto F_15;
V_27 -> V_10 = V_16 -> V_21 -> V_10 . V_46 -> V_46 ;
F_30 ( V_27 -> V_10 ) ;
V_27 -> V_27 = F_31 ( V_27 -> V_10 , V_41 , & V_27 -> V_37 ,
V_44 ) ;
} else {
V_27 -> V_10 = NULL ;
V_27 -> V_27 = F_29 ( V_41 , V_44 ) ;
}
if ( ! V_27 -> V_27 )
goto F_15;
V_27 -> V_47 = 0 ;
V_27 -> V_48 = 0 ;
V_27 -> V_36 = V_41 ;
return V_27 ;
F_15:
F_18 ( V_27 ) ;
V_45:
return NULL ;
}
static struct V_26 * F_32 ( struct V_1 * V_1 )
{
struct V_26 * V_27 ;
unsigned int V_47 ;
if ( V_1 -> V_49 )
return V_1 -> V_49 ;
V_27 = F_33 ( V_1 -> V_17 , & V_47 ) ;
if ( V_27 ) {
V_27 -> V_47 = V_47 ;
V_27 -> V_48 = 0 ;
V_1 -> V_50 . V_51 += V_47 ;
}
return V_27 ;
}
static int F_34 ( struct V_15 * V_16 , struct V_26 * V_27 )
{
struct V_43 V_32 [ 1 ] ;
int V_52 ;
F_35 ( V_32 , V_27 -> V_27 , V_27 -> V_36 ) ;
V_52 = F_36 ( V_16 , V_32 , 1 , V_27 , V_53 ) ;
F_37 ( V_16 ) ;
if ( ! V_52 )
V_52 = V_16 -> V_54 ;
return V_52 ;
}
static void F_38 ( struct V_1 * V_1 )
{
struct V_26 * V_27 ;
unsigned int V_55 ;
if ( ! V_1 -> V_9 ) {
return;
}
V_27 = F_32 ( V_1 ) ;
V_55 = 0 ;
while ( V_27 ) {
V_1 -> V_50 . V_56 += V_27 -> V_47 - V_27 -> V_48 ;
if ( F_34 ( V_1 -> V_17 , V_27 ) < 0 ) {
V_55 ++ ;
F_15 ( V_27 , false ) ;
}
V_1 -> V_49 = NULL ;
V_27 = F_32 ( V_1 ) ;
}
if ( V_55 )
F_39 ( V_1 -> V_10 , L_1 ,
V_55 ) ;
}
static bool F_40 ( struct V_1 * V_1 )
{
unsigned long V_5 ;
bool V_52 ;
V_52 = false ;
F_2 ( & V_1 -> V_57 , V_5 ) ;
V_1 -> V_49 = F_32 ( V_1 ) ;
if ( V_1 -> V_49 )
V_52 = true ;
F_5 ( & V_1 -> V_57 , V_5 ) ;
return V_52 ;
}
static T_4 F_41 ( struct V_8 * V_9 , T_1 V_58 ,
unsigned int V_59 , unsigned int V_60 )
{
struct V_43 V_32 [ 1 ] ;
struct V_61 V_62 ;
struct V_15 * V_16 ;
unsigned int V_47 ;
if ( ! F_13 ( V_9 ) )
return 0 ;
V_62 . V_14 = F_42 ( V_9 -> V_21 , V_58 ) ;
V_62 . V_59 = F_43 ( V_9 -> V_21 , V_59 ) ;
V_62 . V_60 = F_43 ( V_9 -> V_21 , V_60 ) ;
V_16 = V_9 -> V_63 ;
F_35 ( V_32 , & V_62 , sizeof( V_62 ) ) ;
F_44 ( & V_9 -> V_64 ) ;
if ( F_45 ( V_16 , V_32 , 1 , & V_62 , V_53 ) == 0 ) {
F_37 ( V_16 ) ;
while ( ! F_33 ( V_16 , & V_47 )
&& ! F_46 ( V_16 ) )
F_47 () ;
}
F_48 ( & V_9 -> V_64 ) ;
return 0 ;
}
static T_4 F_49 ( struct V_1 * V_1 , unsigned int V_59 ,
unsigned int V_60 )
{
if ( V_1 -> V_9 )
return F_41 ( V_1 -> V_9 , V_1 -> V_14 , V_59 , V_60 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_1 )
{
struct V_26 * V_27 ;
unsigned int V_47 ;
if ( ! V_1 -> V_9 ) {
return;
}
while ( ( V_27 = F_33 ( V_1 -> V_18 , & V_47 ) ) ) {
F_15 ( V_27 , false ) ;
V_1 -> V_65 = false ;
}
}
static T_4 F_51 ( struct V_1 * V_1 , struct V_43 * V_32 ,
int V_66 , T_3 V_67 ,
void * V_68 , bool V_69 )
{
struct V_15 * V_18 ;
int V_55 ;
unsigned long V_5 ;
unsigned int V_47 ;
V_18 = V_1 -> V_18 ;
F_2 ( & V_1 -> V_70 , V_5 ) ;
F_50 ( V_1 ) ;
V_55 = F_45 ( V_18 , V_32 , V_66 , V_68 , V_53 ) ;
F_37 ( V_18 ) ;
if ( V_55 ) {
V_67 = 0 ;
goto V_71;
}
if ( V_18 -> V_54 == 0 )
V_1 -> V_65 = true ;
if ( V_69 )
goto V_71;
while ( ! F_33 ( V_18 , & V_47 )
&& ! F_46 ( V_18 ) )
F_47 () ;
V_71:
F_5 ( & V_1 -> V_70 , V_5 ) ;
V_1 -> V_50 . V_72 += V_67 ;
return V_67 ;
}
static T_4 F_52 ( struct V_1 * V_1 , char T_5 * V_73 ,
T_3 V_74 , bool V_75 )
{
struct V_26 * V_27 ;
unsigned long V_5 ;
if ( ! V_74 || ! F_40 ( V_1 ) )
return 0 ;
V_27 = V_1 -> V_49 ;
V_74 = F_53 ( V_74 , V_27 -> V_47 - V_27 -> V_48 ) ;
if ( V_75 ) {
T_4 V_52 ;
V_52 = F_54 ( V_73 , V_27 -> V_27 + V_27 -> V_48 , V_74 ) ;
if ( V_52 )
return - V_76 ;
} else {
memcpy ( ( V_77 char * ) V_73 , V_27 -> V_27 + V_27 -> V_48 ,
V_74 ) ;
}
V_27 -> V_48 += V_74 ;
if ( V_27 -> V_48 == V_27 -> V_47 ) {
F_2 ( & V_1 -> V_57 , V_5 ) ;
V_1 -> V_49 = NULL ;
if ( F_34 ( V_1 -> V_17 , V_27 ) < 0 )
F_39 ( V_1 -> V_10 , L_2 ) ;
F_5 ( & V_1 -> V_57 , V_5 ) ;
}
return V_74 ;
}
static bool F_55 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_78 ) {
return false ;
}
return ! F_40 ( V_1 ) && V_1 -> V_79 ;
}
static bool F_56 ( struct V_1 * V_1 )
{
bool V_52 ;
if ( ! V_1 -> V_78 ) {
return false ;
}
if ( ! V_1 -> V_79 )
return true ;
F_57 ( & V_1 -> V_70 ) ;
F_50 ( V_1 ) ;
V_52 = V_1 -> V_65 ;
F_58 ( & V_1 -> V_70 ) ;
return V_52 ;
}
static T_4 F_59 ( struct V_80 * V_81 , char T_5 * V_82 ,
T_3 V_83 , T_6 * V_84 )
{
struct V_1 * V_1 ;
T_4 V_52 ;
V_1 = V_81 -> V_85 ;
if ( ! V_1 -> V_78 )
return - V_86 ;
if ( ! F_40 ( V_1 ) ) {
if ( ! V_1 -> V_79 )
return 0 ;
if ( V_81 -> V_87 & V_88 )
return - V_89 ;
V_52 = F_60 ( V_1 -> V_90 ,
! F_55 ( V_1 ) ) ;
if ( V_52 < 0 )
return V_52 ;
}
if ( ! V_1 -> V_78 )
return - V_86 ;
if ( ! F_40 ( V_1 ) && ! V_1 -> V_79 )
return 0 ;
return F_52 ( V_1 , V_82 , V_83 , true ) ;
}
static int F_61 ( struct V_1 * V_1 , bool V_69 )
{
int V_52 ;
if ( F_56 ( V_1 ) ) {
if ( V_69 )
return - V_89 ;
V_52 = F_60 ( V_1 -> V_90 ,
! F_56 ( V_1 ) ) ;
if ( V_52 < 0 )
return V_52 ;
}
if ( ! V_1 -> V_78 )
return - V_86 ;
return 0 ;
}
static T_4 F_62 ( struct V_80 * V_81 , const char T_5 * V_82 ,
T_3 V_83 , T_6 * V_84 )
{
struct V_1 * V_1 ;
struct V_26 * V_27 ;
T_4 V_52 ;
bool V_69 ;
struct V_43 V_32 [ 1 ] ;
if ( ! V_83 )
return 0 ;
V_1 = V_81 -> V_85 ;
V_69 = V_81 -> V_87 & V_88 ;
V_52 = F_61 ( V_1 , V_69 ) ;
if ( V_52 < 0 )
return V_52 ;
V_83 = F_53 ( ( T_3 ) ( 32 * 1024 ) , V_83 ) ;
V_27 = F_28 ( V_1 -> V_18 , V_83 , 0 ) ;
if ( ! V_27 )
return - V_91 ;
V_52 = F_63 ( V_27 -> V_27 , V_82 , V_83 ) ;
if ( V_52 ) {
V_52 = - V_76 ;
goto F_15;
}
V_69 = true ;
F_35 ( V_32 , V_27 -> V_27 , V_83 ) ;
V_52 = F_51 ( V_1 , V_32 , 1 , V_83 , V_27 , V_69 ) ;
if ( V_69 && V_52 > 0 )
goto V_7;
F_15:
F_15 ( V_27 , true ) ;
V_7:
return V_52 ;
}
static int F_64 ( struct V_92 * V_93 , struct V_94 * V_27 ,
struct V_95 * V_96 )
{
struct V_97 * V_98 = V_96 -> V_99 . V_68 ;
unsigned int V_48 , V_47 ;
if ( V_98 -> V_100 == V_98 -> V_36 )
return 0 ;
if ( V_27 -> V_101 -> V_102 ( V_93 , V_27 ) == 0 ) {
F_65 ( V_27 -> V_31 ) ;
F_66 ( V_27 -> V_31 ) ;
V_47 = F_53 ( V_27 -> V_47 , V_96 -> V_47 ) ;
F_67 ( & ( V_98 -> V_32 [ V_98 -> V_100 ] ) , V_27 -> V_31 , V_47 , V_27 -> V_48 ) ;
} else {
struct V_31 * V_31 = F_68 ( V_44 ) ;
char * V_103 ;
if ( ! V_31 )
return - V_91 ;
V_48 = V_96 -> V_104 & ~ V_105 ;
V_47 = V_96 -> V_47 ;
if ( V_47 + V_48 > V_106 )
V_47 = V_106 - V_48 ;
V_103 = F_69 ( V_27 -> V_31 ) ;
memcpy ( F_70 ( V_31 ) + V_48 , V_103 + V_27 -> V_48 , V_47 ) ;
F_71 ( V_103 ) ;
F_67 ( & ( V_98 -> V_32 [ V_98 -> V_100 ] ) , V_31 , V_47 , V_48 ) ;
}
V_98 -> V_100 ++ ;
V_98 -> V_47 += V_47 ;
return V_47 ;
}
static T_4 F_72 ( struct V_92 * V_93 ,
struct V_80 * V_81 , T_6 * V_107 ,
T_3 V_47 , unsigned int V_5 )
{
struct V_1 * V_1 = V_81 -> V_85 ;
struct V_97 V_98 ;
T_4 V_52 ;
struct V_26 * V_27 ;
struct V_95 V_96 = {
. V_108 = V_47 ,
. V_5 = V_5 ,
. V_104 = * V_107 ,
. V_99 . V_68 = & V_98 ,
} ;
if ( F_12 ( V_1 -> V_18 -> V_21 ) )
return - V_109 ;
F_73 ( V_93 ) ;
if ( ! V_93 -> V_110 ) {
V_52 = 0 ;
goto V_111;
}
V_52 = F_61 ( V_1 , V_81 -> V_87 & V_88 ) ;
if ( V_52 < 0 )
goto V_111;
V_27 = F_28 ( V_1 -> V_18 , 0 , V_93 -> V_110 ) ;
if ( ! V_27 ) {
V_52 = - V_91 ;
goto V_111;
}
V_98 . V_100 = 0 ;
V_98 . V_47 = 0 ;
V_98 . V_36 = V_93 -> V_110 ;
V_98 . V_32 = V_27 -> V_32 ;
F_74 ( V_98 . V_32 , V_98 . V_36 ) ;
V_52 = F_75 ( V_93 , & V_96 , F_64 ) ;
F_76 ( V_93 ) ;
if ( F_77 ( V_52 > 0 ) )
V_52 = F_51 ( V_1 , V_27 -> V_32 , V_98 . V_100 , V_98 . V_47 , V_27 , true ) ;
if ( F_78 ( V_52 <= 0 ) )
F_15 ( V_27 , true ) ;
return V_52 ;
V_111:
F_76 ( V_93 ) ;
return V_52 ;
}
static unsigned int F_79 ( struct V_80 * V_81 , T_7 * V_112 )
{
struct V_1 * V_1 ;
unsigned int V_52 ;
V_1 = V_81 -> V_85 ;
F_80 ( V_81 , & V_1 -> V_90 , V_112 ) ;
if ( ! V_1 -> V_78 ) {
return V_113 ;
}
V_52 = 0 ;
if ( ! F_55 ( V_1 ) )
V_52 |= V_114 | V_115 ;
if ( ! F_56 ( V_1 ) )
V_52 |= V_116 ;
if ( ! V_1 -> V_79 )
V_52 |= V_113 ;
return V_52 ;
}
static int F_81 ( struct V_117 * V_117 , struct V_80 * V_81 )
{
struct V_1 * V_1 ;
V_1 = V_81 -> V_85 ;
F_49 ( V_1 , V_118 , 0 ) ;
F_57 ( & V_1 -> V_57 ) ;
V_1 -> V_78 = false ;
F_38 ( V_1 ) ;
F_58 ( & V_1 -> V_57 ) ;
F_57 ( & V_1 -> V_70 ) ;
F_50 ( V_1 ) ;
F_58 ( & V_1 -> V_70 ) ;
F_22 () ;
F_82 ( & V_1 -> V_13 , V_119 ) ;
return 0 ;
}
static int F_83 ( struct V_117 * V_117 , struct V_80 * V_81 )
{
struct V_12 * V_12 = V_117 -> V_120 ;
struct V_1 * V_1 ;
int V_52 ;
V_1 = F_8 ( V_12 -> V_10 ) ;
if ( ! V_1 ) {
return - V_121 ;
}
V_81 -> V_85 = V_1 ;
if ( F_11 ( V_1 ) ) {
V_52 = - V_121 ;
goto V_7;
}
F_57 ( & V_1 -> V_57 ) ;
if ( V_1 -> V_78 ) {
F_58 ( & V_1 -> V_57 ) ;
V_52 = - V_122 ;
goto V_7;
}
V_1 -> V_78 = true ;
F_58 ( & V_1 -> V_57 ) ;
F_57 ( & V_1 -> V_70 ) ;
F_50 ( V_1 ) ;
F_58 ( & V_1 -> V_70 ) ;
F_84 ( V_117 , V_81 ) ;
F_49 ( V_81 -> V_85 , V_118 , 1 ) ;
return 0 ;
V_7:
F_82 ( & V_1 -> V_13 , V_119 ) ;
return V_52 ;
}
static int F_85 ( int V_123 , struct V_80 * V_81 , int V_124 )
{
struct V_1 * V_1 ;
V_1 = V_81 -> V_85 ;
return F_86 ( V_123 , V_81 , V_124 , & V_1 -> V_125 ) ;
}
static int F_87 ( T_1 V_2 , const char * V_27 , int V_83 )
{
struct V_1 * V_1 ;
struct V_43 V_32 [ 1 ] ;
if ( F_78 ( V_126 ) )
return V_126 ( V_2 , V_27 , V_83 ) ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_127 ;
F_35 ( V_32 , V_27 , V_83 ) ;
return F_51 ( V_1 , V_32 , 1 , V_83 , ( void * ) V_27 , false ) ;
}
static int F_88 ( T_1 V_2 , char * V_27 , int V_83 )
{
struct V_1 * V_1 ;
if ( F_78 ( V_126 ) )
return 0 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_127 ;
F_89 ( ! V_1 -> V_17 ) ;
return F_52 ( V_1 , ( V_77 char T_5 * ) V_27 , V_83 , false ) ;
}
static void F_90 ( struct V_1 * V_1 )
{
struct V_20 * V_21 ;
if ( ! V_1 || ! F_11 ( V_1 ) )
return;
V_21 = V_1 -> V_9 -> V_21 ;
if ( ! F_12 ( V_21 ) &&
F_91 ( V_21 , V_128 ) )
F_92 ( V_1 -> V_4 . V_19 , V_1 -> V_4 . V_129 ) ;
}
static int F_93 ( struct V_130 * V_131 , int V_68 )
{
struct V_1 * V_1 ;
V_1 = F_1 ( V_131 -> V_2 ) ;
if ( ! V_1 )
return - V_109 ;
V_131 -> V_132 = 1 ;
F_90 ( V_1 ) ;
return 0 ;
}
static void F_94 ( struct V_130 * V_131 , int V_68 )
{
V_131 -> V_132 = 0 ;
}
int T_8 F_95 ( int (* F_87)( T_1 , const char * , int ) )
{
V_126 = F_87 ;
return F_96 ( 0 , 0 , & V_133 ) ;
}
static int F_97 ( struct V_1 * V_1 )
{
int V_52 ;
V_1 -> V_4 . V_2 = V_134 . V_135 ;
V_1 -> V_4 . V_19 = F_98 ( V_1 -> V_4 . V_2 , 0 , & V_133 , V_106 ) ;
if ( F_99 ( V_1 -> V_4 . V_19 ) ) {
V_52 = F_100 ( V_1 -> V_4 . V_19 ) ;
F_101 ( V_1 -> V_10 ,
L_3 , V_52 ) ;
V_1 -> V_4 . V_19 = NULL ;
return V_52 ;
}
F_57 ( & V_6 ) ;
V_134 . V_135 ++ ;
F_19 ( & V_1 -> V_4 . V_34 , & V_134 . V_136 ) ;
F_58 ( & V_6 ) ;
V_1 -> V_78 = true ;
if ( V_126 )
V_126 = NULL ;
F_49 ( V_1 , V_118 , 1 ) ;
return 0 ;
}
static T_4 F_102 ( struct V_23 * V_10 ,
struct V_137 * V_138 , char * V_139 )
{
struct V_1 * V_1 ;
V_1 = F_103 ( V_10 ) ;
return sprintf ( V_139 , L_4 , V_1 -> V_140 ) ;
}
static T_4 F_104 ( struct V_80 * V_81 , char T_5 * V_82 ,
T_3 V_83 , T_6 * V_84 )
{
struct V_1 * V_1 ;
char * V_27 ;
T_4 V_52 , V_141 , V_74 ;
V_74 = 1024 ;
V_27 = F_29 ( V_74 , V_44 ) ;
if ( ! V_27 )
return - V_91 ;
V_1 = V_81 -> V_85 ;
V_141 = 0 ;
V_141 += snprintf ( V_27 + V_141 , V_74 ,
L_5 , V_1 -> V_140 ? V_1 -> V_140 : L_6 ) ;
V_141 += snprintf ( V_27 + V_141 , V_74 - V_141 ,
L_7 , V_1 -> V_78 ) ;
V_141 += snprintf ( V_27 + V_141 , V_74 - V_141 ,
L_8 , V_1 -> V_79 ) ;
V_141 += snprintf ( V_27 + V_141 , V_74 - V_141 ,
L_9 , V_1 -> V_65 ) ;
V_141 += snprintf ( V_27 + V_141 , V_74 - V_141 ,
L_10 , V_1 -> V_50 . V_72 ) ;
V_141 += snprintf ( V_27 + V_141 , V_74 - V_141 ,
L_11 ,
V_1 -> V_50 . V_51 ) ;
V_141 += snprintf ( V_27 + V_141 , V_74 - V_141 ,
L_12 ,
V_1 -> V_50 . V_56 ) ;
V_141 += snprintf ( V_27 + V_141 , V_74 - V_141 ,
L_13 ,
F_11 ( V_1 ) ? L_14 : L_15 ) ;
V_141 += snprintf ( V_27 + V_141 , V_74 - V_141 ,
L_16 , V_1 -> V_4 . V_2 ) ;
V_52 = F_105 ( V_82 , V_83 , V_84 , V_27 , V_141 ) ;
F_18 ( V_27 ) ;
return V_52 ;
}
static void F_106 ( struct V_1 * V_1 , T_9 V_142 , T_9 V_143 )
{
if ( ! V_1 || ! F_11 ( V_1 ) )
return;
V_1 -> V_4 . V_129 . V_144 = V_142 ;
V_1 -> V_4 . V_129 . V_145 = V_143 ;
}
static unsigned int F_107 ( struct V_15 * V_16 , T_10 * V_146 )
{
struct V_26 * V_27 ;
unsigned int V_147 ;
int V_52 ;
V_147 = 0 ;
do {
V_27 = F_28 ( V_16 , V_106 , 0 ) ;
if ( ! V_27 )
break;
F_57 ( V_146 ) ;
V_52 = F_34 ( V_16 , V_27 ) ;
if ( V_52 < 0 ) {
F_58 ( V_146 ) ;
F_15 ( V_27 , true ) ;
break;
}
V_147 ++ ;
F_58 ( V_146 ) ;
} while ( V_52 > 0 );
return V_147 ;
}
static void F_108 ( struct V_1 * V_1 )
{
if ( V_1 -> V_125 && V_1 -> V_78 )
F_109 ( & V_1 -> V_125 , V_148 , V_149 ) ;
}
static int F_110 ( struct V_8 * V_9 , T_1 V_14 )
{
char V_150 [ 16 ] ;
struct V_1 * V_1 ;
struct V_26 * V_27 ;
T_2 V_151 ;
unsigned int V_147 ;
int V_55 ;
V_1 = F_29 ( sizeof( * V_1 ) , V_44 ) ;
if ( ! V_1 ) {
V_55 = - V_91 ;
goto V_45;
}
F_111 ( & V_1 -> V_13 ) ;
V_1 -> V_9 = V_9 ;
V_1 -> V_14 = V_14 ;
V_1 -> V_140 = NULL ;
V_1 -> V_49 = NULL ;
V_1 -> V_4 . V_19 = NULL ;
V_1 -> V_125 = NULL ;
V_1 -> V_4 . V_129 . V_144 = V_1 -> V_4 . V_129 . V_145 = 0 ;
V_1 -> V_79 = V_1 -> V_78 = false ;
V_1 -> V_50 = (struct V_152 ) { 0 } ;
V_1 -> V_65 = false ;
V_1 -> V_17 = V_9 -> V_153 [ V_1 -> V_14 ] ;
V_1 -> V_18 = V_9 -> V_154 [ V_1 -> V_14 ] ;
V_1 -> V_12 = F_112 () ;
if ( ! V_1 -> V_12 ) {
F_101 ( & V_1 -> V_9 -> V_21 -> V_10 , L_17 ) ;
V_55 = - V_91 ;
goto V_155;
}
V_1 -> V_12 -> V_101 = & V_156 ;
V_151 = F_113 ( V_9 -> V_157 , V_14 ) ;
V_55 = F_114 ( V_1 -> V_12 , V_151 , 1 ) ;
if ( V_55 < 0 ) {
F_101 ( & V_1 -> V_9 -> V_21 -> V_10 ,
L_18 , V_55 , V_14 ) ;
goto V_158;
}
V_1 -> V_10 = F_115 ( V_134 . V_159 , & V_1 -> V_9 -> V_21 -> V_10 ,
V_151 , V_1 , L_19 ,
V_1 -> V_9 -> V_21 -> V_160 , V_14 ) ;
if ( F_99 ( V_1 -> V_10 ) ) {
V_55 = F_100 ( V_1 -> V_10 ) ;
F_101 ( & V_1 -> V_9 -> V_21 -> V_10 ,
L_20 ,
V_55 , V_14 ) ;
goto V_158;
}
F_116 ( & V_1 -> V_57 ) ;
F_116 ( & V_1 -> V_70 ) ;
F_117 ( & V_1 -> V_90 ) ;
V_147 = F_107 ( V_1 -> V_17 , & V_1 -> V_57 ) ;
if ( ! V_147 ) {
F_101 ( V_1 -> V_10 , L_21 ) ;
V_55 = - V_91 ;
goto V_161;
}
if ( F_12 ( V_1 -> V_9 -> V_21 ) )
V_1 -> V_79 = true ;
else if ( ! F_13 ( V_1 -> V_9 ) ) {
V_55 = F_97 ( V_1 ) ;
if ( V_55 )
goto V_162;
}
F_57 ( & V_9 -> V_11 ) ;
F_19 ( & V_1 -> V_34 , & V_1 -> V_9 -> V_163 ) ;
F_58 ( & V_9 -> V_11 ) ;
F_49 ( V_1 , V_164 , 1 ) ;
if ( V_134 . V_165 ) {
sprintf ( V_150 , L_19 ,
V_1 -> V_9 -> V_21 -> V_160 , V_14 ) ;
V_1 -> V_166 = F_118 ( V_150 , 0444 ,
V_134 . V_165 ,
V_1 ,
& V_167 ) ;
}
return 0 ;
V_162:
while ( ( V_27 = F_119 ( V_1 -> V_17 ) ) )
F_15 ( V_27 , true ) ;
V_161:
F_120 ( V_134 . V_159 , V_1 -> V_10 -> V_151 ) ;
V_158:
F_121 ( V_1 -> V_12 ) ;
V_155:
F_18 ( V_1 ) ;
V_45:
F_41 ( V_9 , V_14 , V_164 , 0 ) ;
return V_55 ;
}
static void V_119 ( struct V_13 * V_13 )
{
struct V_1 * V_1 ;
V_1 = F_4 ( V_13 , struct V_1 , V_13 ) ;
F_18 ( V_1 ) ;
}
static void F_122 ( struct V_1 * V_1 )
{
struct V_26 * V_27 ;
F_57 ( & V_1 -> V_57 ) ;
F_38 ( V_1 ) ;
while ( ( V_27 = F_119 ( V_1 -> V_17 ) ) )
F_15 ( V_27 , true ) ;
F_58 ( & V_1 -> V_57 ) ;
F_57 ( & V_1 -> V_70 ) ;
F_50 ( V_1 ) ;
while ( ( V_27 = F_119 ( V_1 -> V_18 ) ) )
F_15 ( V_27 , true ) ;
F_58 ( & V_1 -> V_70 ) ;
}
static void F_123 ( struct V_1 * V_1 )
{
F_57 ( & V_1 -> V_9 -> V_11 ) ;
F_27 ( & V_1 -> V_34 ) ;
F_58 ( & V_1 -> V_9 -> V_11 ) ;
F_57 ( & V_1 -> V_57 ) ;
if ( V_1 -> V_78 ) {
F_108 ( V_1 ) ;
V_1 -> V_78 = false ;
V_1 -> V_79 = false ;
F_124 ( & V_1 -> V_90 ) ;
}
F_58 ( & V_1 -> V_57 ) ;
if ( F_11 ( V_1 ) ) {
F_57 ( & V_6 ) ;
F_27 ( & V_1 -> V_4 . V_34 ) ;
F_58 ( & V_6 ) ;
F_125 ( V_1 -> V_4 . V_19 ) ;
}
F_122 ( V_1 ) ;
V_1 -> V_9 = NULL ;
F_126 ( & V_1 -> V_10 -> V_168 , & V_169 ) ;
F_120 ( V_134 . V_159 , V_1 -> V_10 -> V_151 ) ;
F_121 ( V_1 -> V_12 ) ;
F_127 ( V_1 -> V_166 ) ;
F_18 ( V_1 -> V_140 ) ;
F_82 ( & V_1 -> V_13 , V_119 ) ;
}
static void F_128 ( struct V_20 * V_21 ,
struct V_8 * V_9 ,
struct V_26 * V_27 )
{
struct V_61 * V_62 ;
struct V_1 * V_1 ;
T_3 V_170 ;
int V_55 ;
V_62 = (struct V_61 * ) ( V_27 -> V_27 + V_27 -> V_48 ) ;
V_1 = F_9 ( V_9 , F_129 ( V_21 , V_62 -> V_14 ) ) ;
if ( ! V_1 &&
V_62 -> V_59 != F_43 ( V_21 , V_171 ) ) {
F_130 ( & V_9 -> V_21 -> V_10 ,
L_22 , V_62 -> V_14 ) ;
return;
}
switch ( F_131 ( V_21 , V_62 -> V_59 ) ) {
case V_171 :
if ( V_1 ) {
F_130 ( & V_9 -> V_21 -> V_10 ,
L_23 , V_1 -> V_14 ) ;
F_49 ( V_1 , V_164 , 1 ) ;
break;
}
if ( F_129 ( V_21 , V_62 -> V_14 ) >=
V_9 -> V_172 . V_173 ) {
F_39 ( & V_9 -> V_21 -> V_10 ,
L_24
L_25 ,
V_62 -> V_14 , V_9 -> V_172 . V_173 - 1 ) ;
break;
}
F_110 ( V_9 , F_129 ( V_21 , V_62 -> V_14 ) ) ;
break;
case V_174 :
F_123 ( V_1 ) ;
break;
case V_175 :
if ( ! V_62 -> V_60 )
break;
if ( F_11 ( V_1 ) )
break;
F_97 ( V_1 ) ;
F_132 ( & V_176 ) ;
break;
case V_177 : {
struct {
T_11 V_142 ;
T_11 V_143 ;
} V_36 ;
if ( ! F_11 ( V_1 ) )
break;
memcpy ( & V_36 , V_27 -> V_27 + V_27 -> V_48 + sizeof( * V_62 ) ,
sizeof( V_36 ) ) ;
F_106 ( V_1 , V_36 . V_142 , V_36 . V_143 ) ;
V_1 -> V_4 . V_19 -> V_132 = 1 ;
F_90 ( V_1 ) ;
break;
}
case V_118 :
V_1 -> V_79 = F_131 ( V_21 , V_62 -> V_60 ) ;
F_124 ( & V_1 -> V_90 ) ;
F_57 ( & V_1 -> V_70 ) ;
F_50 ( V_1 ) ;
F_58 ( & V_1 -> V_70 ) ;
F_57 ( & V_1 -> V_57 ) ;
F_108 ( V_1 ) ;
F_58 ( & V_1 -> V_57 ) ;
break;
case V_178 :
if ( V_1 -> V_140 )
break;
V_170 = V_27 -> V_47 - V_27 -> V_48 - sizeof( * V_62 ) + 1 ;
V_1 -> V_140 = F_29 ( V_170 , V_44 ) ;
if ( ! V_1 -> V_140 ) {
F_101 ( V_1 -> V_10 ,
L_26 ) ;
break;
}
strncpy ( V_1 -> V_140 , V_27 -> V_27 + V_27 -> V_48 + sizeof( * V_62 ) ,
V_170 - 1 ) ;
V_1 -> V_140 [ V_170 - 1 ] = 0 ;
V_55 = F_133 ( & V_1 -> V_10 -> V_168 ,
& V_169 ) ;
if ( V_55 ) {
F_101 ( V_1 -> V_10 ,
L_27 ,
V_55 ) ;
} else {
F_134 ( & V_1 -> V_10 -> V_168 , V_179 ) ;
}
break;
}
}
static void F_135 ( struct V_180 * V_181 )
{
struct V_8 * V_9 ;
struct V_15 * V_16 ;
struct V_26 * V_27 ;
unsigned int V_47 ;
V_9 = F_4 ( V_181 , struct V_8 , V_182 ) ;
V_16 = V_9 -> V_183 ;
F_44 ( & V_9 -> V_184 ) ;
while ( ( V_27 = F_33 ( V_16 , & V_47 ) ) ) {
F_48 ( & V_9 -> V_184 ) ;
V_27 -> V_47 = V_47 ;
V_27 -> V_48 = 0 ;
F_128 ( V_16 -> V_21 , V_9 , V_27 ) ;
F_44 ( & V_9 -> V_184 ) ;
if ( F_34 ( V_9 -> V_183 , V_27 ) < 0 ) {
F_39 ( & V_9 -> V_21 -> V_10 ,
L_28 ) ;
F_15 ( V_27 , false ) ;
}
}
F_48 ( & V_9 -> V_184 ) ;
}
static void F_136 ( struct V_15 * V_16 )
{
struct V_1 * V_1 ;
V_1 = F_10 ( V_16 -> V_21 -> V_185 , V_16 ) ;
if ( ! V_1 )
return;
F_124 ( & V_1 -> V_90 ) ;
}
static void F_137 ( struct V_15 * V_16 )
{
struct V_1 * V_1 ;
unsigned long V_5 ;
V_1 = F_10 ( V_16 -> V_21 -> V_185 , V_16 ) ;
if ( ! V_1 )
return;
F_2 ( & V_1 -> V_57 , V_5 ) ;
V_1 -> V_49 = F_32 ( V_1 ) ;
if ( ! V_1 -> V_78 && ! F_12 ( V_1 -> V_9 -> V_21 ) )
F_38 ( V_1 ) ;
F_108 ( V_1 ) ;
F_5 ( & V_1 -> V_57 , V_5 ) ;
F_124 ( & V_1 -> V_90 ) ;
if ( F_11 ( V_1 ) && F_138 ( V_1 -> V_4 . V_19 ) )
F_139 () ;
}
static void F_140 ( struct V_15 * V_16 )
{
struct V_8 * V_9 ;
V_9 = V_16 -> V_21 -> V_185 ;
F_141 ( & V_9 -> V_182 ) ;
}
static void F_142 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
V_9 = V_21 -> V_185 ;
if ( ! F_13 ( V_9 ) )
F_141 ( & V_9 -> V_186 ) ;
}
static void F_143 ( struct V_180 * V_181 )
{
struct V_8 * V_9 ;
V_9 = F_4 ( V_181 , struct V_8 , V_182 ) ;
if ( ! F_13 ( V_9 ) ) {
struct V_20 * V_21 ;
struct V_1 * V_1 ;
T_9 V_142 , V_143 ;
V_21 = V_9 -> V_21 ;
F_144 ( V_21 , struct V_187 , V_143 , & V_143 ) ;
F_144 ( V_21 , struct V_187 , V_142 , & V_142 ) ;
V_1 = F_9 ( V_9 , 0 ) ;
F_106 ( V_1 , V_142 , V_143 ) ;
F_90 ( V_1 ) ;
}
}
static int F_145 ( struct V_8 * V_9 )
{
T_12 * * V_188 ;
char * * V_189 ;
struct V_15 * * V_190 ;
T_1 V_29 , V_191 , V_192 , V_193 ;
int V_55 ;
V_192 = V_9 -> V_172 . V_173 ;
V_193 = F_13 ( V_9 ) ? ( V_192 + 1 ) * 2 : 2 ;
V_190 = F_29 ( V_193 * sizeof( struct V_15 * ) , V_44 ) ;
V_188 = F_29 ( V_193 * sizeof( T_12 * ) , V_44 ) ;
V_189 = F_29 ( V_193 * sizeof( char * ) , V_44 ) ;
V_9 -> V_153 = F_29 ( V_192 * sizeof( struct V_15 * ) ,
V_44 ) ;
V_9 -> V_154 = F_29 ( V_192 * sizeof( struct V_15 * ) ,
V_44 ) ;
if ( ! V_190 || ! V_188 || ! V_189 || ! V_9 -> V_153 ||
! V_9 -> V_154 ) {
V_55 = - V_91 ;
goto free;
}
V_191 = 0 ;
V_188 [ V_191 ] = F_137 ;
V_188 [ V_191 + 1 ] = F_136 ;
V_189 [ V_191 ] = L_29 ;
V_189 [ V_191 + 1 ] = L_30 ;
V_191 += 2 ;
if ( F_13 ( V_9 ) ) {
V_188 [ V_191 ] = F_140 ;
V_188 [ V_191 + 1 ] = NULL ;
V_189 [ V_191 ] = L_31 ;
V_189 [ V_191 + 1 ] = L_32 ;
for ( V_29 = 1 ; V_29 < V_192 ; V_29 ++ ) {
V_191 += 2 ;
V_188 [ V_191 ] = F_137 ;
V_188 [ V_191 + 1 ] = F_136 ;
V_189 [ V_191 ] = L_29 ;
V_189 [ V_191 + 1 ] = L_30 ;
}
}
V_55 = V_9 -> V_21 -> V_172 -> V_194 ( V_9 -> V_21 , V_193 , V_190 ,
V_188 ,
( const char * * ) V_189 ) ;
if ( V_55 )
goto free;
V_191 = 0 ;
V_9 -> V_153 [ 0 ] = V_190 [ 0 ] ;
V_9 -> V_154 [ 0 ] = V_190 [ 1 ] ;
V_191 += 2 ;
if ( F_13 ( V_9 ) ) {
V_9 -> V_183 = V_190 [ V_191 ] ;
V_9 -> V_63 = V_190 [ V_191 + 1 ] ;
for ( V_29 = 1 ; V_29 < V_192 ; V_29 ++ ) {
V_191 += 2 ;
V_9 -> V_153 [ V_29 ] = V_190 [ V_191 ] ;
V_9 -> V_154 [ V_29 ] = V_190 [ V_191 + 1 ] ;
}
}
F_18 ( V_189 ) ;
F_18 ( V_188 ) ;
F_18 ( V_190 ) ;
return 0 ;
free:
F_18 ( V_9 -> V_154 ) ;
F_18 ( V_9 -> V_153 ) ;
F_18 ( V_189 ) ;
F_18 ( V_188 ) ;
F_18 ( V_190 ) ;
return V_55 ;
}
static void F_146 ( struct V_8 * V_9 )
{
V_9 -> V_21 -> V_172 -> V_195 ( V_9 -> V_21 ) ;
F_18 ( V_9 -> V_153 ) ;
F_18 ( V_9 -> V_154 ) ;
}
static void F_147 ( struct V_8 * V_9 )
{
struct V_26 * V_27 ;
unsigned int V_47 ;
if ( ! F_13 ( V_9 ) )
return;
while ( ( V_27 = F_33 ( V_9 -> V_183 , & V_47 ) ) )
F_15 ( V_27 , true ) ;
while ( ( V_27 = F_119 ( V_9 -> V_183 ) ) )
F_15 ( V_27 , true ) ;
}
static int F_148 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
int V_55 ;
bool V_196 ;
bool V_197 = V_126 != NULL ;
if ( ! V_21 -> V_172 -> V_198 &&
( F_91 ( V_21 , V_128 )
|| F_91 ( V_21 , V_25 ) ) ) {
F_101 ( & V_21 -> V_10 , L_33 ,
V_199 ) ;
return - V_109 ;
}
F_149 () ;
V_9 = F_29 ( sizeof( * V_9 ) , V_44 ) ;
if ( ! V_9 ) {
V_55 = - V_91 ;
goto V_45;
}
V_9 -> V_21 = V_21 ;
V_21 -> V_185 = V_9 ;
V_9 -> V_157 = F_150 ( 0 , L_34 ,
& V_200 ) ;
if ( V_9 -> V_157 < 0 ) {
F_101 ( & V_21 -> V_10 ,
L_35 ,
V_9 -> V_157 , V_21 -> V_160 ) ;
V_55 = V_9 -> V_157 ;
goto free;
}
V_196 = false ;
V_9 -> V_172 . V_173 = 1 ;
if ( ! F_12 ( V_21 ) &&
F_151 ( V_21 , V_25 ,
struct V_187 , V_173 ,
& V_9 -> V_172 . V_173 ) == 0 ) {
V_196 = true ;
}
V_55 = F_145 ( V_9 ) ;
if ( V_55 < 0 ) {
F_101 ( & V_21 -> V_10 , L_36 , V_55 ) ;
goto V_201;
}
F_116 ( & V_9 -> V_11 ) ;
F_152 ( & V_9 -> V_163 ) ;
F_153 ( V_9 -> V_21 ) ;
F_154 ( & V_9 -> V_186 , & F_143 ) ;
F_154 ( & V_9 -> V_182 , & F_135 ) ;
if ( V_196 ) {
unsigned int V_147 ;
F_116 ( & V_9 -> V_184 ) ;
F_116 ( & V_9 -> V_64 ) ;
V_147 = F_107 ( V_9 -> V_183 ,
& V_9 -> V_184 ) ;
if ( ! V_147 ) {
F_101 ( & V_21 -> V_10 ,
L_37 ) ;
V_55 = - V_91 ;
goto V_202;
}
} else {
F_110 ( V_9 , 0 ) ;
}
F_57 ( & V_6 ) ;
F_19 ( & V_9 -> V_34 , & V_134 . V_203 ) ;
F_58 ( & V_6 ) ;
F_41 ( V_9 , V_204 ,
V_205 , 1 ) ;
if ( V_196 && V_197 )
F_155 ( & V_176 ) ;
return 0 ;
V_202:
F_41 ( V_9 , V_204 ,
V_205 , 0 ) ;
F_146 ( V_9 ) ;
V_201:
F_156 ( V_9 -> V_157 , L_34 ) ;
free:
F_18 ( V_9 ) ;
V_45:
return V_55 ;
}
static void F_157 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 , * V_206 ;
V_9 = V_21 -> V_185 ;
F_57 ( & V_6 ) ;
F_27 ( & V_9 -> V_34 ) ;
F_58 ( & V_6 ) ;
V_21 -> V_172 -> V_207 ( V_21 ) ;
if ( F_13 ( V_9 ) )
F_158 ( & V_9 -> V_182 ) ;
else
F_158 ( & V_9 -> V_186 ) ;
F_26 (port, port2, &portdev->ports, list)
F_123 ( V_1 ) ;
F_156 ( V_9 -> V_157 , L_34 ) ;
F_147 ( V_9 ) ;
F_146 ( V_9 ) ;
F_18 ( V_9 ) ;
}
static int F_159 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
V_9 = V_21 -> V_185 ;
V_21 -> V_172 -> V_207 ( V_21 ) ;
F_160 ( V_9 -> V_183 ) ;
F_158 ( & V_9 -> V_182 ) ;
F_158 ( & V_9 -> V_186 ) ;
F_160 ( V_9 -> V_183 ) ;
F_147 ( V_9 ) ;
F_3 (port, &portdev->ports, list) {
F_160 ( V_1 -> V_17 ) ;
F_160 ( V_1 -> V_18 ) ;
V_1 -> V_79 = false ;
F_122 ( V_1 ) ;
}
F_146 ( V_9 ) ;
return 0 ;
}
static int F_161 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
int V_52 ;
V_9 = V_21 -> V_185 ;
V_52 = F_145 ( V_9 ) ;
if ( V_52 )
return V_52 ;
F_153 ( V_9 -> V_21 ) ;
if ( F_13 ( V_9 ) )
F_107 ( V_9 -> V_183 , & V_9 -> V_184 ) ;
F_3 (port, &portdev->ports, list) {
V_1 -> V_17 = V_9 -> V_153 [ V_1 -> V_14 ] ;
V_1 -> V_18 = V_9 -> V_154 [ V_1 -> V_14 ] ;
F_107 ( V_1 -> V_17 , & V_1 -> V_57 ) ;
F_49 ( V_1 , V_164 , 1 ) ;
if ( V_1 -> V_78 )
F_49 ( V_1 , V_118 , 1 ) ;
}
return 0 ;
}
static int T_8 F_162 ( void )
{
int V_55 ;
V_134 . V_159 = F_163 ( V_208 , L_38 ) ;
if ( F_99 ( V_134 . V_159 ) ) {
V_55 = F_100 ( V_134 . V_159 ) ;
F_164 ( L_39 , V_55 ) ;
return V_55 ;
}
V_134 . V_165 = F_165 ( L_38 , NULL ) ;
if ( ! V_134 . V_165 )
F_166 ( L_40 ) ;
F_152 ( & V_134 . V_136 ) ;
F_152 ( & V_134 . V_203 ) ;
V_55 = F_167 ( & V_209 ) ;
if ( V_55 < 0 ) {
F_164 ( L_41 , V_55 ) ;
goto free;
}
V_55 = F_167 ( & V_210 ) ;
if ( V_55 < 0 ) {
F_164 ( L_42 ,
V_55 ) ;
goto V_211;
}
return 0 ;
V_211:
F_168 ( & V_209 ) ;
free:
F_169 ( V_134 . V_165 ) ;
F_170 ( V_134 . V_159 ) ;
return V_55 ;
}
static void T_13 F_171 ( void )
{
F_22 () ;
F_168 ( & V_209 ) ;
F_168 ( & V_210 ) ;
F_170 ( V_134 . V_159 ) ;
F_169 ( V_134 . V_165 ) ;
}
