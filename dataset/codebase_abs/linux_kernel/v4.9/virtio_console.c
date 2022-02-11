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
return false ;
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
struct V_15 * V_16 ;
unsigned int V_47 ;
if ( ! F_13 ( V_9 ) )
return 0 ;
V_16 = V_9 -> V_61 ;
F_42 ( & V_9 -> V_62 ) ;
V_9 -> V_63 . V_14 = F_43 ( V_9 -> V_21 , V_58 ) ;
V_9 -> V_63 . V_59 = F_44 ( V_9 -> V_21 , V_59 ) ;
V_9 -> V_63 . V_60 = F_44 ( V_9 -> V_21 , V_60 ) ;
F_35 ( V_32 , & V_9 -> V_63 , sizeof( struct V_64 ) ) ;
if ( F_45 ( V_16 , V_32 , 1 , & V_9 -> V_63 , V_53 ) == 0 ) {
F_37 ( V_16 ) ;
while ( ! F_33 ( V_16 , & V_47 )
&& ! F_46 ( V_16 ) )
F_47 () ;
}
F_48 ( & V_9 -> V_62 ) ;
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
if ( F_65 ( V_93 , V_27 ) == 0 ) {
F_66 ( V_27 -> V_31 ) ;
F_67 ( V_27 -> V_31 ) ;
V_47 = F_53 ( V_27 -> V_47 , V_96 -> V_47 ) ;
F_68 ( & ( V_98 -> V_32 [ V_98 -> V_100 ] ) , V_27 -> V_31 , V_47 , V_27 -> V_48 ) ;
} else {
struct V_31 * V_31 = F_69 ( V_44 ) ;
char * V_101 ;
if ( ! V_31 )
return - V_91 ;
V_48 = V_96 -> V_102 & ~ V_103 ;
V_47 = V_96 -> V_47 ;
if ( V_47 + V_48 > V_104 )
V_47 = V_104 - V_48 ;
V_101 = F_70 ( V_27 -> V_31 ) ;
memcpy ( F_71 ( V_31 ) + V_48 , V_101 + V_27 -> V_48 , V_47 ) ;
F_72 ( V_101 ) ;
F_68 ( & ( V_98 -> V_32 [ V_98 -> V_100 ] ) , V_31 , V_47 , V_48 ) ;
}
V_98 -> V_100 ++ ;
V_98 -> V_47 += V_47 ;
return V_47 ;
}
static T_4 F_73 ( struct V_92 * V_93 ,
struct V_80 * V_81 , T_6 * V_105 ,
T_3 V_47 , unsigned int V_5 )
{
struct V_1 * V_1 = V_81 -> V_85 ;
struct V_97 V_98 ;
T_4 V_52 ;
struct V_26 * V_27 ;
struct V_95 V_96 = {
. V_106 = V_47 ,
. V_5 = V_5 ,
. V_102 = * V_105 ,
. V_99 . V_68 = & V_98 ,
} ;
if ( F_12 ( V_1 -> V_18 -> V_21 ) )
return - V_107 ;
F_74 ( V_93 ) ;
if ( ! V_93 -> V_108 ) {
V_52 = 0 ;
goto V_109;
}
V_52 = F_61 ( V_1 , V_81 -> V_87 & V_88 ) ;
if ( V_52 < 0 )
goto V_109;
V_27 = F_28 ( V_1 -> V_18 , 0 , V_93 -> V_108 ) ;
if ( ! V_27 ) {
V_52 = - V_91 ;
goto V_109;
}
V_98 . V_100 = 0 ;
V_98 . V_47 = 0 ;
V_98 . V_36 = V_93 -> V_108 ;
V_98 . V_32 = V_27 -> V_32 ;
F_75 ( V_98 . V_32 , V_98 . V_36 ) ;
V_52 = F_76 ( V_93 , & V_96 , F_64 ) ;
F_77 ( V_93 ) ;
if ( F_78 ( V_52 > 0 ) )
V_52 = F_51 ( V_1 , V_27 -> V_32 , V_98 . V_100 , V_98 . V_47 , V_27 , true ) ;
if ( F_79 ( V_52 <= 0 ) )
F_15 ( V_27 , true ) ;
return V_52 ;
V_109:
F_77 ( V_93 ) ;
return V_52 ;
}
static unsigned int F_80 ( struct V_80 * V_81 , T_7 * V_110 )
{
struct V_1 * V_1 ;
unsigned int V_52 ;
V_1 = V_81 -> V_85 ;
F_81 ( V_81 , & V_1 -> V_90 , V_110 ) ;
if ( ! V_1 -> V_78 ) {
return V_111 ;
}
V_52 = 0 ;
if ( ! F_55 ( V_1 ) )
V_52 |= V_112 | V_113 ;
if ( ! F_56 ( V_1 ) )
V_52 |= V_114 ;
if ( ! V_1 -> V_79 )
V_52 |= V_111 ;
return V_52 ;
}
static int F_82 ( struct V_115 * V_115 , struct V_80 * V_81 )
{
struct V_1 * V_1 ;
V_1 = V_81 -> V_85 ;
F_49 ( V_1 , V_116 , 0 ) ;
F_57 ( & V_1 -> V_57 ) ;
V_1 -> V_78 = false ;
F_38 ( V_1 ) ;
F_58 ( & V_1 -> V_57 ) ;
F_57 ( & V_1 -> V_70 ) ;
F_50 ( V_1 ) ;
F_58 ( & V_1 -> V_70 ) ;
F_22 () ;
F_83 ( & V_1 -> V_13 , V_117 ) ;
return 0 ;
}
static int F_84 ( struct V_115 * V_115 , struct V_80 * V_81 )
{
struct V_12 * V_12 = V_115 -> V_118 ;
struct V_1 * V_1 ;
int V_52 ;
V_1 = F_8 ( V_12 -> V_10 ) ;
if ( ! V_1 ) {
return - V_119 ;
}
V_81 -> V_85 = V_1 ;
if ( F_11 ( V_1 ) ) {
V_52 = - V_119 ;
goto V_7;
}
F_57 ( & V_1 -> V_57 ) ;
if ( V_1 -> V_78 ) {
F_58 ( & V_1 -> V_57 ) ;
V_52 = - V_120 ;
goto V_7;
}
V_1 -> V_78 = true ;
F_58 ( & V_1 -> V_57 ) ;
F_57 ( & V_1 -> V_70 ) ;
F_50 ( V_1 ) ;
F_58 ( & V_1 -> V_70 ) ;
F_85 ( V_115 , V_81 ) ;
F_49 ( V_81 -> V_85 , V_116 , 1 ) ;
return 0 ;
V_7:
F_83 ( & V_1 -> V_13 , V_117 ) ;
return V_52 ;
}
static int F_86 ( int V_121 , struct V_80 * V_81 , int V_122 )
{
struct V_1 * V_1 ;
V_1 = V_81 -> V_85 ;
return F_87 ( V_121 , V_81 , V_122 , & V_1 -> V_123 ) ;
}
static int F_88 ( T_1 V_2 , const char * V_27 , int V_83 )
{
struct V_1 * V_1 ;
struct V_43 V_32 [ 1 ] ;
if ( F_79 ( V_124 ) )
return V_124 ( V_2 , V_27 , V_83 ) ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_125 ;
F_35 ( V_32 , V_27 , V_83 ) ;
return F_51 ( V_1 , V_32 , 1 , V_83 , ( void * ) V_27 , false ) ;
}
static int F_89 ( T_1 V_2 , char * V_27 , int V_83 )
{
struct V_1 * V_1 ;
if ( F_79 ( V_124 ) )
return 0 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_125 ;
F_90 ( ! V_1 -> V_17 ) ;
return F_52 ( V_1 , ( V_77 char T_5 * ) V_27 , V_83 , false ) ;
}
static void F_91 ( struct V_1 * V_1 )
{
struct V_20 * V_21 ;
if ( ! V_1 || ! F_11 ( V_1 ) )
return;
V_21 = V_1 -> V_9 -> V_21 ;
if ( ! F_12 ( V_21 ) &&
F_92 ( V_21 , V_126 ) )
F_93 ( V_1 -> V_4 . V_19 , V_1 -> V_4 . V_127 ) ;
}
static int F_94 ( struct V_128 * V_129 , int V_68 )
{
struct V_1 * V_1 ;
V_1 = F_1 ( V_129 -> V_2 ) ;
if ( ! V_1 )
return - V_107 ;
V_129 -> V_130 = 1 ;
F_91 ( V_1 ) ;
return 0 ;
}
static void F_95 ( struct V_128 * V_129 , int V_68 )
{
V_129 -> V_130 = 0 ;
}
int T_8 F_96 ( int (* F_88)( T_1 , const char * , int ) )
{
V_124 = F_88 ;
return F_97 ( 0 , 0 , & V_131 ) ;
}
static int F_98 ( struct V_1 * V_1 )
{
int V_52 ;
V_1 -> V_4 . V_2 = V_132 . V_133 ;
V_1 -> V_4 . V_19 = F_99 ( V_1 -> V_4 . V_2 , 0 , & V_131 , V_104 ) ;
if ( F_100 ( V_1 -> V_4 . V_19 ) ) {
V_52 = F_101 ( V_1 -> V_4 . V_19 ) ;
F_102 ( V_1 -> V_10 ,
L_3 , V_52 ) ;
V_1 -> V_4 . V_19 = NULL ;
return V_52 ;
}
F_57 ( & V_6 ) ;
V_132 . V_133 ++ ;
F_19 ( & V_1 -> V_4 . V_34 , & V_132 . V_134 ) ;
F_58 ( & V_6 ) ;
V_1 -> V_78 = true ;
if ( V_124 )
V_124 = NULL ;
F_49 ( V_1 , V_116 , 1 ) ;
return 0 ;
}
static T_4 F_103 ( struct V_23 * V_10 ,
struct V_135 * V_136 , char * V_137 )
{
struct V_1 * V_1 ;
V_1 = F_104 ( V_10 ) ;
return sprintf ( V_137 , L_4 , V_1 -> V_138 ) ;
}
static T_4 F_105 ( struct V_80 * V_81 , char T_5 * V_82 ,
T_3 V_83 , T_6 * V_84 )
{
struct V_1 * V_1 ;
char * V_27 ;
T_4 V_52 , V_139 , V_74 ;
V_74 = 1024 ;
V_27 = F_29 ( V_74 , V_44 ) ;
if ( ! V_27 )
return - V_91 ;
V_1 = V_81 -> V_85 ;
V_139 = 0 ;
V_139 += snprintf ( V_27 + V_139 , V_74 ,
L_5 , V_1 -> V_138 ? V_1 -> V_138 : L_6 ) ;
V_139 += snprintf ( V_27 + V_139 , V_74 - V_139 ,
L_7 , V_1 -> V_78 ) ;
V_139 += snprintf ( V_27 + V_139 , V_74 - V_139 ,
L_8 , V_1 -> V_79 ) ;
V_139 += snprintf ( V_27 + V_139 , V_74 - V_139 ,
L_9 , V_1 -> V_65 ) ;
V_139 += snprintf ( V_27 + V_139 , V_74 - V_139 ,
L_10 , V_1 -> V_50 . V_72 ) ;
V_139 += snprintf ( V_27 + V_139 , V_74 - V_139 ,
L_11 ,
V_1 -> V_50 . V_51 ) ;
V_139 += snprintf ( V_27 + V_139 , V_74 - V_139 ,
L_12 ,
V_1 -> V_50 . V_56 ) ;
V_139 += snprintf ( V_27 + V_139 , V_74 - V_139 ,
L_13 ,
F_11 ( V_1 ) ? L_14 : L_15 ) ;
V_139 += snprintf ( V_27 + V_139 , V_74 - V_139 ,
L_16 , V_1 -> V_4 . V_2 ) ;
V_52 = F_106 ( V_82 , V_83 , V_84 , V_27 , V_139 ) ;
F_18 ( V_27 ) ;
return V_52 ;
}
static void F_107 ( struct V_1 * V_1 , T_9 V_140 , T_9 V_141 )
{
if ( ! V_1 || ! F_11 ( V_1 ) )
return;
V_1 -> V_4 . V_127 . V_142 = V_140 ;
V_1 -> V_4 . V_127 . V_143 = V_141 ;
}
static unsigned int F_108 ( struct V_15 * V_16 , T_10 * V_144 )
{
struct V_26 * V_27 ;
unsigned int V_145 ;
int V_52 ;
V_145 = 0 ;
do {
V_27 = F_28 ( V_16 , V_104 , 0 ) ;
if ( ! V_27 )
break;
F_57 ( V_144 ) ;
V_52 = F_34 ( V_16 , V_27 ) ;
if ( V_52 < 0 ) {
F_58 ( V_144 ) ;
F_15 ( V_27 , true ) ;
break;
}
V_145 ++ ;
F_58 ( V_144 ) ;
} while ( V_52 > 0 );
return V_145 ;
}
static void F_109 ( struct V_1 * V_1 )
{
if ( V_1 -> V_123 && V_1 -> V_78 )
F_110 ( & V_1 -> V_123 , V_146 , V_147 ) ;
}
static int F_111 ( struct V_8 * V_9 , T_1 V_14 )
{
char V_148 [ 16 ] ;
struct V_1 * V_1 ;
struct V_26 * V_27 ;
T_2 V_149 ;
unsigned int V_145 ;
int V_55 ;
V_1 = F_29 ( sizeof( * V_1 ) , V_44 ) ;
if ( ! V_1 ) {
V_55 = - V_91 ;
goto V_45;
}
F_112 ( & V_1 -> V_13 ) ;
V_1 -> V_9 = V_9 ;
V_1 -> V_14 = V_14 ;
V_1 -> V_138 = NULL ;
V_1 -> V_49 = NULL ;
V_1 -> V_4 . V_19 = NULL ;
V_1 -> V_123 = NULL ;
V_1 -> V_4 . V_127 . V_142 = V_1 -> V_4 . V_127 . V_143 = 0 ;
V_1 -> V_79 = V_1 -> V_78 = false ;
V_1 -> V_50 = (struct V_150 ) { 0 } ;
V_1 -> V_65 = false ;
V_1 -> V_17 = V_9 -> V_151 [ V_1 -> V_14 ] ;
V_1 -> V_18 = V_9 -> V_152 [ V_1 -> V_14 ] ;
V_1 -> V_12 = F_113 () ;
if ( ! V_1 -> V_12 ) {
F_102 ( & V_1 -> V_9 -> V_21 -> V_10 , L_17 ) ;
V_55 = - V_91 ;
goto V_153;
}
V_1 -> V_12 -> V_154 = & V_155 ;
V_149 = F_114 ( V_9 -> V_156 , V_14 ) ;
V_55 = F_115 ( V_1 -> V_12 , V_149 , 1 ) ;
if ( V_55 < 0 ) {
F_102 ( & V_1 -> V_9 -> V_21 -> V_10 ,
L_18 , V_55 , V_14 ) ;
goto V_157;
}
V_1 -> V_10 = F_116 ( V_132 . V_158 , & V_1 -> V_9 -> V_21 -> V_10 ,
V_149 , V_1 , L_19 ,
V_1 -> V_9 -> V_21 -> V_159 , V_14 ) ;
if ( F_100 ( V_1 -> V_10 ) ) {
V_55 = F_101 ( V_1 -> V_10 ) ;
F_102 ( & V_1 -> V_9 -> V_21 -> V_10 ,
L_20 ,
V_55 , V_14 ) ;
goto V_157;
}
F_117 ( & V_1 -> V_57 ) ;
F_117 ( & V_1 -> V_70 ) ;
F_118 ( & V_1 -> V_90 ) ;
V_145 = F_108 ( V_1 -> V_17 , & V_1 -> V_57 ) ;
if ( ! V_145 ) {
F_102 ( V_1 -> V_10 , L_21 ) ;
V_55 = - V_91 ;
goto V_160;
}
if ( F_12 ( V_1 -> V_9 -> V_21 ) )
V_1 -> V_79 = true ;
else if ( ! F_13 ( V_1 -> V_9 ) ) {
V_55 = F_98 ( V_1 ) ;
if ( V_55 )
goto V_161;
}
F_57 ( & V_9 -> V_11 ) ;
F_19 ( & V_1 -> V_34 , & V_1 -> V_9 -> V_162 ) ;
F_58 ( & V_9 -> V_11 ) ;
F_49 ( V_1 , V_163 , 1 ) ;
if ( V_132 . V_164 ) {
snprintf ( V_148 , sizeof( V_148 ) , L_19 ,
V_1 -> V_9 -> V_21 -> V_159 , V_14 ) ;
V_1 -> V_165 = F_119 ( V_148 , 0444 ,
V_132 . V_164 ,
V_1 ,
& V_166 ) ;
}
return 0 ;
V_161:
while ( ( V_27 = F_120 ( V_1 -> V_17 ) ) )
F_15 ( V_27 , true ) ;
V_160:
F_121 ( V_132 . V_158 , V_1 -> V_10 -> V_149 ) ;
V_157:
F_122 ( V_1 -> V_12 ) ;
V_153:
F_18 ( V_1 ) ;
V_45:
F_41 ( V_9 , V_14 , V_163 , 0 ) ;
return V_55 ;
}
static void V_117 ( struct V_13 * V_13 )
{
struct V_1 * V_1 ;
V_1 = F_4 ( V_13 , struct V_1 , V_13 ) ;
F_18 ( V_1 ) ;
}
static void F_123 ( struct V_1 * V_1 )
{
struct V_26 * V_27 ;
F_57 ( & V_1 -> V_57 ) ;
F_38 ( V_1 ) ;
F_58 ( & V_1 -> V_57 ) ;
do {
F_57 ( & V_1 -> V_57 ) ;
V_27 = F_120 ( V_1 -> V_17 ) ;
F_58 ( & V_1 -> V_57 ) ;
if ( V_27 )
F_15 ( V_27 , true ) ;
} while ( V_27 );
F_57 ( & V_1 -> V_70 ) ;
F_50 ( V_1 ) ;
F_58 ( & V_1 -> V_70 ) ;
do {
F_57 ( & V_1 -> V_70 ) ;
V_27 = F_120 ( V_1 -> V_18 ) ;
F_58 ( & V_1 -> V_70 ) ;
if ( V_27 )
F_15 ( V_27 , true ) ;
} while ( V_27 );
}
static void F_124 ( struct V_1 * V_1 )
{
F_57 ( & V_1 -> V_9 -> V_11 ) ;
F_27 ( & V_1 -> V_34 ) ;
F_58 ( & V_1 -> V_9 -> V_11 ) ;
F_57 ( & V_1 -> V_57 ) ;
if ( V_1 -> V_78 ) {
F_109 ( V_1 ) ;
V_1 -> V_78 = false ;
V_1 -> V_79 = false ;
F_125 ( & V_1 -> V_90 ) ;
}
F_58 ( & V_1 -> V_57 ) ;
if ( F_11 ( V_1 ) ) {
F_57 ( & V_6 ) ;
F_27 ( & V_1 -> V_4 . V_34 ) ;
F_58 ( & V_6 ) ;
F_126 ( V_1 -> V_4 . V_19 ) ;
}
F_123 ( V_1 ) ;
V_1 -> V_9 = NULL ;
F_127 ( & V_1 -> V_10 -> V_167 , & V_168 ) ;
F_121 ( V_132 . V_158 , V_1 -> V_10 -> V_149 ) ;
F_122 ( V_1 -> V_12 ) ;
F_128 ( V_1 -> V_165 ) ;
F_18 ( V_1 -> V_138 ) ;
F_83 ( & V_1 -> V_13 , V_117 ) ;
}
static void F_129 ( struct V_20 * V_21 ,
struct V_8 * V_9 ,
struct V_26 * V_27 )
{
struct V_64 * V_63 ;
struct V_1 * V_1 ;
T_3 V_169 ;
int V_55 ;
V_63 = (struct V_64 * ) ( V_27 -> V_27 + V_27 -> V_48 ) ;
V_1 = F_9 ( V_9 , F_130 ( V_21 , V_63 -> V_14 ) ) ;
if ( ! V_1 &&
V_63 -> V_59 != F_44 ( V_21 , V_170 ) ) {
F_131 ( & V_9 -> V_21 -> V_10 ,
L_22 , V_63 -> V_14 ) ;
return;
}
switch ( F_132 ( V_21 , V_63 -> V_59 ) ) {
case V_170 :
if ( V_1 ) {
F_131 ( & V_9 -> V_21 -> V_10 ,
L_23 , V_1 -> V_14 ) ;
F_49 ( V_1 , V_163 , 1 ) ;
break;
}
if ( F_130 ( V_21 , V_63 -> V_14 ) >=
V_9 -> V_171 . V_172 ) {
F_39 ( & V_9 -> V_21 -> V_10 ,
L_24
L_25 ,
V_63 -> V_14 , V_9 -> V_171 . V_172 - 1 ) ;
break;
}
F_111 ( V_9 , F_130 ( V_21 , V_63 -> V_14 ) ) ;
break;
case V_173 :
F_124 ( V_1 ) ;
break;
case V_174 :
if ( ! V_63 -> V_60 )
break;
if ( F_11 ( V_1 ) )
break;
F_98 ( V_1 ) ;
F_133 ( & V_175 ) ;
break;
case V_176 : {
struct {
T_11 V_140 ;
T_11 V_141 ;
} V_36 ;
if ( ! F_11 ( V_1 ) )
break;
memcpy ( & V_36 , V_27 -> V_27 + V_27 -> V_48 + sizeof( * V_63 ) ,
sizeof( V_36 ) ) ;
F_107 ( V_1 , V_36 . V_140 , V_36 . V_141 ) ;
V_1 -> V_4 . V_19 -> V_130 = 1 ;
F_91 ( V_1 ) ;
break;
}
case V_116 :
V_1 -> V_79 = F_132 ( V_21 , V_63 -> V_60 ) ;
F_125 ( & V_1 -> V_90 ) ;
F_57 ( & V_1 -> V_70 ) ;
F_50 ( V_1 ) ;
F_58 ( & V_1 -> V_70 ) ;
F_57 ( & V_1 -> V_57 ) ;
F_109 ( V_1 ) ;
F_58 ( & V_1 -> V_57 ) ;
break;
case V_177 :
if ( V_1 -> V_138 )
break;
V_169 = V_27 -> V_47 - V_27 -> V_48 - sizeof( * V_63 ) + 1 ;
V_1 -> V_138 = F_29 ( V_169 , V_44 ) ;
if ( ! V_1 -> V_138 ) {
F_102 ( V_1 -> V_10 ,
L_26 ) ;
break;
}
strncpy ( V_1 -> V_138 , V_27 -> V_27 + V_27 -> V_48 + sizeof( * V_63 ) ,
V_169 - 1 ) ;
V_1 -> V_138 [ V_169 - 1 ] = 0 ;
V_55 = F_134 ( & V_1 -> V_10 -> V_167 ,
& V_168 ) ;
if ( V_55 ) {
F_102 ( V_1 -> V_10 ,
L_27 ,
V_55 ) ;
} else {
F_135 ( & V_1 -> V_10 -> V_167 , V_178 ) ;
}
break;
}
}
static void F_136 ( struct V_179 * V_180 )
{
struct V_8 * V_9 ;
struct V_15 * V_16 ;
struct V_26 * V_27 ;
unsigned int V_47 ;
V_9 = F_4 ( V_180 , struct V_8 , V_181 ) ;
V_16 = V_9 -> V_182 ;
F_42 ( & V_9 -> V_183 ) ;
while ( ( V_27 = F_33 ( V_16 , & V_47 ) ) ) {
F_48 ( & V_9 -> V_183 ) ;
V_27 -> V_47 = V_47 ;
V_27 -> V_48 = 0 ;
F_129 ( V_16 -> V_21 , V_9 , V_27 ) ;
F_42 ( & V_9 -> V_183 ) ;
if ( F_34 ( V_9 -> V_182 , V_27 ) < 0 ) {
F_39 ( & V_9 -> V_21 -> V_10 ,
L_28 ) ;
F_15 ( V_27 , false ) ;
}
}
F_48 ( & V_9 -> V_183 ) ;
}
static void F_137 ( struct V_15 * V_16 )
{
struct V_1 * V_1 ;
V_1 = F_10 ( V_16 -> V_21 -> V_184 , V_16 ) ;
if ( ! V_1 )
return;
F_125 ( & V_1 -> V_90 ) ;
}
static void F_138 ( struct V_15 * V_16 )
{
struct V_1 * V_1 ;
unsigned long V_5 ;
V_1 = F_10 ( V_16 -> V_21 -> V_184 , V_16 ) ;
if ( ! V_1 )
return;
F_2 ( & V_1 -> V_57 , V_5 ) ;
V_1 -> V_49 = F_32 ( V_1 ) ;
if ( ! V_1 -> V_78 && ! F_12 ( V_1 -> V_9 -> V_21 ) )
F_38 ( V_1 ) ;
F_109 ( V_1 ) ;
F_5 ( & V_1 -> V_57 , V_5 ) ;
F_125 ( & V_1 -> V_90 ) ;
if ( F_11 ( V_1 ) && F_139 ( V_1 -> V_4 . V_19 ) )
F_140 () ;
}
static void F_141 ( struct V_15 * V_16 )
{
struct V_8 * V_9 ;
V_9 = V_16 -> V_21 -> V_184 ;
F_142 ( & V_9 -> V_181 ) ;
}
static void F_143 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
V_9 = V_21 -> V_184 ;
if ( ! F_13 ( V_9 ) )
F_142 ( & V_9 -> V_185 ) ;
}
static void F_144 ( struct V_179 * V_180 )
{
struct V_8 * V_9 ;
V_9 = F_4 ( V_180 , struct V_8 , V_181 ) ;
if ( ! F_13 ( V_9 ) ) {
struct V_20 * V_21 ;
struct V_1 * V_1 ;
T_9 V_140 , V_141 ;
V_21 = V_9 -> V_21 ;
F_145 ( V_21 , struct V_186 , V_141 , & V_141 ) ;
F_145 ( V_21 , struct V_186 , V_140 , & V_140 ) ;
V_1 = F_9 ( V_9 , 0 ) ;
F_107 ( V_1 , V_140 , V_141 ) ;
F_91 ( V_1 ) ;
}
}
static int F_146 ( struct V_8 * V_9 )
{
T_12 * * V_187 ;
char * * V_188 ;
struct V_15 * * V_189 ;
T_1 V_29 , V_190 , V_191 , V_192 ;
int V_55 ;
V_191 = V_9 -> V_171 . V_172 ;
V_192 = F_13 ( V_9 ) ? ( V_191 + 1 ) * 2 : 2 ;
V_189 = F_29 ( V_192 * sizeof( struct V_15 * ) , V_44 ) ;
V_187 = F_29 ( V_192 * sizeof( T_12 * ) , V_44 ) ;
V_188 = F_29 ( V_192 * sizeof( char * ) , V_44 ) ;
V_9 -> V_151 = F_29 ( V_191 * sizeof( struct V_15 * ) ,
V_44 ) ;
V_9 -> V_152 = F_29 ( V_191 * sizeof( struct V_15 * ) ,
V_44 ) ;
if ( ! V_189 || ! V_187 || ! V_188 || ! V_9 -> V_151 ||
! V_9 -> V_152 ) {
V_55 = - V_91 ;
goto free;
}
V_190 = 0 ;
V_187 [ V_190 ] = F_138 ;
V_187 [ V_190 + 1 ] = F_137 ;
V_188 [ V_190 ] = L_29 ;
V_188 [ V_190 + 1 ] = L_30 ;
V_190 += 2 ;
if ( F_13 ( V_9 ) ) {
V_187 [ V_190 ] = F_141 ;
V_187 [ V_190 + 1 ] = NULL ;
V_188 [ V_190 ] = L_31 ;
V_188 [ V_190 + 1 ] = L_32 ;
for ( V_29 = 1 ; V_29 < V_191 ; V_29 ++ ) {
V_190 += 2 ;
V_187 [ V_190 ] = F_138 ;
V_187 [ V_190 + 1 ] = F_137 ;
V_188 [ V_190 ] = L_29 ;
V_188 [ V_190 + 1 ] = L_30 ;
}
}
V_55 = V_9 -> V_21 -> V_171 -> V_193 ( V_9 -> V_21 , V_192 , V_189 ,
V_187 ,
( const char * * ) V_188 ) ;
if ( V_55 )
goto free;
V_190 = 0 ;
V_9 -> V_151 [ 0 ] = V_189 [ 0 ] ;
V_9 -> V_152 [ 0 ] = V_189 [ 1 ] ;
V_190 += 2 ;
if ( F_13 ( V_9 ) ) {
V_9 -> V_182 = V_189 [ V_190 ] ;
V_9 -> V_61 = V_189 [ V_190 + 1 ] ;
for ( V_29 = 1 ; V_29 < V_191 ; V_29 ++ ) {
V_190 += 2 ;
V_9 -> V_151 [ V_29 ] = V_189 [ V_190 ] ;
V_9 -> V_152 [ V_29 ] = V_189 [ V_190 + 1 ] ;
}
}
F_18 ( V_188 ) ;
F_18 ( V_187 ) ;
F_18 ( V_189 ) ;
return 0 ;
free:
F_18 ( V_9 -> V_152 ) ;
F_18 ( V_9 -> V_151 ) ;
F_18 ( V_188 ) ;
F_18 ( V_187 ) ;
F_18 ( V_189 ) ;
return V_55 ;
}
static void F_147 ( struct V_8 * V_9 )
{
V_9 -> V_21 -> V_171 -> V_194 ( V_9 -> V_21 ) ;
F_18 ( V_9 -> V_151 ) ;
F_18 ( V_9 -> V_152 ) ;
}
static void F_148 ( struct V_8 * V_9 )
{
struct V_26 * V_27 ;
unsigned int V_47 ;
if ( ! F_13 ( V_9 ) )
return;
while ( ( V_27 = F_33 ( V_9 -> V_182 , & V_47 ) ) )
F_15 ( V_27 , true ) ;
while ( ( V_27 = F_120 ( V_9 -> V_182 ) ) )
F_15 ( V_27 , true ) ;
}
static int F_149 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
int V_55 ;
bool V_195 ;
bool V_196 = V_124 != NULL ;
if ( ! V_21 -> V_171 -> V_197 &&
( F_92 ( V_21 , V_126 )
|| F_92 ( V_21 , V_25 ) ) ) {
F_102 ( & V_21 -> V_10 , L_33 ,
V_198 ) ;
return - V_107 ;
}
F_150 () ;
V_9 = F_29 ( sizeof( * V_9 ) , V_44 ) ;
if ( ! V_9 ) {
V_55 = - V_91 ;
goto V_45;
}
V_9 -> V_21 = V_21 ;
V_21 -> V_184 = V_9 ;
V_9 -> V_156 = F_151 ( 0 , L_34 ,
& V_199 ) ;
if ( V_9 -> V_156 < 0 ) {
F_102 ( & V_21 -> V_10 ,
L_35 ,
V_9 -> V_156 , V_21 -> V_159 ) ;
V_55 = V_9 -> V_156 ;
goto free;
}
V_195 = false ;
V_9 -> V_171 . V_172 = 1 ;
if ( ! F_12 ( V_21 ) &&
F_152 ( V_21 , V_25 ,
struct V_186 , V_172 ,
& V_9 -> V_171 . V_172 ) == 0 ) {
V_195 = true ;
}
V_55 = F_146 ( V_9 ) ;
if ( V_55 < 0 ) {
F_102 ( & V_21 -> V_10 , L_36 , V_55 ) ;
goto V_200;
}
F_117 ( & V_9 -> V_11 ) ;
F_153 ( & V_9 -> V_162 ) ;
F_154 ( V_9 -> V_21 ) ;
F_155 ( & V_9 -> V_185 , & F_144 ) ;
F_155 ( & V_9 -> V_181 , & F_136 ) ;
if ( V_195 ) {
unsigned int V_145 ;
F_117 ( & V_9 -> V_183 ) ;
F_117 ( & V_9 -> V_62 ) ;
V_145 = F_108 ( V_9 -> V_182 ,
& V_9 -> V_183 ) ;
if ( ! V_145 ) {
F_102 ( & V_21 -> V_10 ,
L_37 ) ;
V_55 = - V_91 ;
goto V_201;
}
} else {
F_111 ( V_9 , 0 ) ;
}
F_57 ( & V_6 ) ;
F_19 ( & V_9 -> V_34 , & V_132 . V_202 ) ;
F_58 ( & V_6 ) ;
F_41 ( V_9 , V_203 ,
V_204 , 1 ) ;
if ( V_195 && V_196 )
F_156 ( & V_175 ) ;
return 0 ;
V_201:
F_41 ( V_9 , V_203 ,
V_204 , 0 ) ;
F_147 ( V_9 ) ;
V_200:
F_157 ( V_9 -> V_156 , L_34 ) ;
free:
F_18 ( V_9 ) ;
V_45:
return V_55 ;
}
static void F_158 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 , * V_205 ;
V_9 = V_21 -> V_184 ;
F_57 ( & V_6 ) ;
F_27 ( & V_9 -> V_34 ) ;
F_58 ( & V_6 ) ;
V_21 -> V_171 -> V_206 ( V_21 ) ;
if ( F_13 ( V_9 ) )
F_159 ( & V_9 -> V_181 ) ;
else
F_159 ( & V_9 -> V_185 ) ;
F_26 (port, port2, &portdev->ports, list)
F_124 ( V_1 ) ;
F_157 ( V_9 -> V_156 , L_34 ) ;
F_148 ( V_9 ) ;
F_147 ( V_9 ) ;
F_18 ( V_9 ) ;
}
static int F_160 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
V_9 = V_21 -> V_184 ;
V_21 -> V_171 -> V_206 ( V_21 ) ;
F_161 ( V_9 -> V_182 ) ;
F_159 ( & V_9 -> V_181 ) ;
F_159 ( & V_9 -> V_185 ) ;
F_161 ( V_9 -> V_182 ) ;
F_148 ( V_9 ) ;
F_3 (port, &portdev->ports, list) {
F_161 ( V_1 -> V_17 ) ;
F_161 ( V_1 -> V_18 ) ;
V_1 -> V_79 = false ;
F_123 ( V_1 ) ;
}
F_147 ( V_9 ) ;
return 0 ;
}
static int F_162 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
int V_52 ;
V_9 = V_21 -> V_184 ;
V_52 = F_146 ( V_9 ) ;
if ( V_52 )
return V_52 ;
F_154 ( V_9 -> V_21 ) ;
if ( F_13 ( V_9 ) )
F_108 ( V_9 -> V_182 , & V_9 -> V_183 ) ;
F_3 (port, &portdev->ports, list) {
V_1 -> V_17 = V_9 -> V_151 [ V_1 -> V_14 ] ;
V_1 -> V_18 = V_9 -> V_152 [ V_1 -> V_14 ] ;
F_108 ( V_1 -> V_17 , & V_1 -> V_57 ) ;
F_49 ( V_1 , V_163 , 1 ) ;
if ( V_1 -> V_78 )
F_49 ( V_1 , V_116 , 1 ) ;
}
return 0 ;
}
static int T_8 F_163 ( void )
{
int V_55 ;
V_132 . V_158 = F_164 ( V_207 , L_38 ) ;
if ( F_100 ( V_132 . V_158 ) ) {
V_55 = F_101 ( V_132 . V_158 ) ;
F_165 ( L_39 , V_55 ) ;
return V_55 ;
}
V_132 . V_164 = F_166 ( L_38 , NULL ) ;
if ( ! V_132 . V_164 )
F_167 ( L_40 ) ;
F_153 ( & V_132 . V_134 ) ;
F_153 ( & V_132 . V_202 ) ;
V_55 = F_168 ( & V_208 ) ;
if ( V_55 < 0 ) {
F_165 ( L_41 , V_55 ) ;
goto free;
}
V_55 = F_168 ( & V_209 ) ;
if ( V_55 < 0 ) {
F_165 ( L_42 ,
V_55 ) ;
goto V_210;
}
return 0 ;
V_210:
F_169 ( & V_208 ) ;
free:
F_170 ( V_132 . V_164 ) ;
F_171 ( V_132 . V_158 ) ;
return V_55 ;
}
static void T_13 F_172 ( void )
{
F_22 () ;
F_169 ( & V_208 ) ;
F_169 ( & V_209 ) ;
F_171 ( V_132 . V_158 ) ;
F_170 ( V_132 . V_164 ) ;
}
