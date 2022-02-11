static int
F_1 ( T_1 V_1 , T_2 V_2 )
{
return ( int ) ( V_2 & V_1 ) ;
}
int F_2 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
struct V_8 * V_9 = & V_4 -> V_10 ;
T_3 V_11 = F_4 ( & V_9 -> V_12 ) ;
T_3 V_13 = V_9 -> V_14 ;
int V_15 = 0 ;
if ( F_5 ( V_11 <= - V_13 ) ) {
V_11 = V_13 ;
F_6 ( & V_9 -> V_12 , V_11 ) ;
V_9 -> V_16 = V_13 ;
V_15 = 1 ;
}
if ( F_5 ( V_11 <= 0 ) ) {
V_11 += V_13 ;
F_6 ( & V_9 -> V_12 , V_11 ) ;
V_9 -> V_16 = V_13 ;
V_15 = 1 ;
}
if ( V_11 > ( V_6 -> V_17 >> 1 ) )
V_11 = V_6 -> V_17 >> 1 ;
F_6 ( & V_9 -> V_18 , ( T_2 ) - V_11 ) ;
V_6 -> V_19 ( V_4 , ( T_2 ) ( - V_11 ) & 0xffffffff ) ;
F_7 ( V_4 ) ;
return V_15 ;
}
T_2 F_8 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
struct V_8 * V_9 = & V_4 -> V_10 ;
T_2 V_20 , V_21 , V_22 ;
V_23:
V_21 = F_4 ( & V_9 -> V_18 ) ;
V_22 = V_6 -> V_24 ( V_4 ) ;
if ( F_9 ( & V_9 -> V_18 , V_21 ,
V_22 ) != V_21 )
goto V_23;
V_20 = ( V_22 - V_21 ) & V_6 -> V_17 ;
F_10 ( V_20 , & V_4 -> V_25 ) ;
F_11 ( V_20 , & V_9 -> V_12 ) ;
return V_22 ;
}
static void
F_12 ( struct V_3 * V_4 )
{
F_8 ( V_4 ) ;
}
static void
F_13 ( struct V_3 * V_4 , int V_26 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
struct V_8 * V_9 = & V_4 -> V_10 ;
if ( ! ( V_9 -> V_27 & V_28 ) ) {
V_6 -> V_29 ( V_4 ) ;
F_8 ( V_4 ) ;
V_9 -> V_27 |= V_28 | V_30 ;
}
}
static void F_14 ( struct V_3 * V_4 , int V_26 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
struct V_8 * V_9 = & V_4 -> V_10 ;
if ( V_26 & V_31 )
F_15 ( ! ( V_9 -> V_27 & V_30 ) ) ;
V_9 -> V_27 = 0 ;
F_2 ( V_4 ) ;
V_6 -> V_32 ( V_4 ) ;
}
static void
F_16 ( struct V_3 * V_4 , int V_26 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
struct V_33 * V_34 = F_17 ( V_6 -> V_34 ) ;
struct V_8 * V_9 = & V_4 -> V_10 ;
int V_35 = V_9 -> V_35 ;
F_13 ( V_4 , V_36 ) ;
V_34 -> V_37 [ V_35 ] = NULL ;
F_18 ( V_35 , V_34 -> V_38 ) ;
if ( V_6 -> V_39 )
V_6 -> V_39 ( V_34 , V_4 ) ;
F_7 ( V_4 ) ;
}
static int
F_19 ( struct V_3 * V_4 , int V_26 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
struct V_33 * V_34 = F_17 ( V_6 -> V_34 ) ;
struct V_8 * V_9 = & V_4 -> V_10 ;
int V_35 ;
if ( ! F_20 ( F_21 () , & V_6 -> V_40 ) )
return - V_41 ;
V_35 = V_6 -> V_42 ( V_34 , V_4 ) ;
if ( V_35 < 0 )
return V_35 ;
V_4 -> V_10 . V_35 = V_35 ;
V_6 -> V_29 ( V_4 ) ;
V_34 -> V_37 [ V_35 ] = V_4 ;
V_9 -> V_27 = V_28 | V_30 ;
if ( V_26 & V_43 )
F_14 ( V_4 , V_31 ) ;
F_7 ( V_4 ) ;
return 0 ;
}
static int
F_22 ( struct V_7 * V_7 , struct V_33 * V_34 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( F_23 ( V_4 ) )
return 1 ;
if ( V_4 -> V_7 != V_7 )
return 0 ;
if ( V_4 -> V_27 < V_44 )
return 1 ;
if ( V_4 -> V_27 == V_44 && ! V_4 -> V_45 . V_46 )
return 1 ;
V_6 = F_3 ( V_4 -> V_7 ) ;
return V_6 -> V_42 ( V_34 , V_4 ) >= 0 ;
}
static int
F_24 ( struct V_3 * V_4 )
{
struct V_3 * V_47 , * V_48 = V_4 -> V_49 ;
struct V_33 V_50 ;
memset ( & V_50 . V_38 , 0 , sizeof( V_50 . V_38 ) ) ;
if ( ! F_22 ( V_4 -> V_7 , & V_50 , V_48 ) )
return - V_51 ;
F_25 (sibling, &leader->sibling_list, group_entry) {
if ( ! F_22 ( V_4 -> V_7 , & V_50 , V_47 ) )
return - V_51 ;
}
if ( ! F_22 ( V_4 -> V_7 , & V_50 , V_4 ) )
return - V_51 ;
return 0 ;
}
static struct V_52 * F_26 ( struct V_5 * V_6 )
{
struct V_53 * V_54 = V_6 -> V_55 ;
return V_54 ? F_27 ( & V_54 -> V_56 ) : NULL ;
}
static T_4 F_28 ( int V_57 , void * V_56 )
{
struct V_5 * V_6 ;
struct V_52 * V_58 ;
int V_15 ;
T_2 V_59 , V_60 ;
V_6 = * ( void * * ) V_56 ;
V_58 = F_26 ( V_6 ) ;
V_59 = F_29 () ;
if ( V_58 && V_58 -> V_61 )
V_15 = V_58 -> V_61 ( V_57 , V_6 , V_6 -> V_61 ) ;
else
V_15 = V_6 -> V_61 ( V_57 , V_6 ) ;
V_60 = F_29 () ;
F_30 ( V_60 - V_59 ) ;
return V_15 ;
}
static int
F_31 ( struct V_62 * V_45 )
{
return V_45 -> V_63 || V_45 -> V_64 ||
V_45 -> V_65 || V_45 -> V_66 ;
}
static int
F_32 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
struct V_8 * V_9 = & V_4 -> V_10 ;
int V_67 ;
V_67 = V_6 -> V_68 ( V_4 ) ;
if ( V_67 < 0 ) {
F_33 ( L_1 , V_4 -> V_45 . type ,
V_4 -> V_45 . V_2 ) ;
return V_67 ;
}
V_9 -> V_35 = - 1 ;
V_9 -> V_69 = 0 ;
V_9 -> V_2 = 0 ;
V_9 -> V_70 = 0 ;
if ( ( ! V_6 -> V_71 ||
V_6 -> V_71 ( V_9 , & V_4 -> V_45 ) ) &&
F_31 ( & V_4 -> V_45 ) ) {
F_33 ( L_2
L_3 ) ;
return - V_72 ;
}
V_9 -> V_69 |= ( unsigned long ) V_67 ;
if ( ! F_34 ( V_4 ) ) {
V_9 -> V_14 = V_6 -> V_17 >> 1 ;
V_9 -> V_16 = V_9 -> V_14 ;
F_6 ( & V_9 -> V_12 , V_9 -> V_14 ) ;
}
if ( V_4 -> V_49 != V_4 ) {
if ( F_24 ( V_4 ) != 0 )
return - V_51 ;
}
return 0 ;
}
static int F_35 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
if ( V_4 -> V_73 != - 1 &&
! F_20 ( V_4 -> V_73 , & V_6 -> V_40 ) )
return - V_41 ;
if ( F_36 ( V_4 ) )
return - V_72 ;
if ( V_6 -> V_68 ( V_4 ) == - V_41 )
return - V_41 ;
return F_32 ( V_4 ) ;
}
static void F_37 ( struct V_7 * V_7 )
{
struct V_5 * V_6 = F_3 ( V_7 ) ;
struct V_33 * V_34 = F_17 ( V_6 -> V_34 ) ;
int V_74 = F_38 ( V_34 -> V_38 , V_6 -> V_75 ) ;
if ( ! F_20 ( F_21 () , & V_6 -> V_40 ) )
return;
if ( V_74 )
V_6 -> V_76 ( V_6 ) ;
}
static void F_39 ( struct V_7 * V_7 )
{
struct V_5 * V_6 = F_3 ( V_7 ) ;
if ( ! F_20 ( F_21 () , & V_6 -> V_40 ) )
return;
V_6 -> V_77 ( V_6 ) ;
}
static int F_40 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 ) ;
unsigned int V_73 = F_21 () ;
return F_20 ( V_73 , & V_6 -> V_40 ) ;
}
static T_5 F_41 ( struct V_78 * V_56 ,
struct V_79 * V_45 , char * V_80 )
{
struct V_5 * V_6 = F_3 ( F_42 ( V_56 ) ) ;
return F_43 ( true , V_80 , & V_6 -> V_40 ) ;
}
const char * F_44 ( void )
{
if ( ! V_81 )
return NULL ;
return V_81 -> V_82 ;
}
int F_45 ( void )
{
int V_83 = 0 ;
if ( V_81 != NULL )
V_83 = V_81 -> V_75 ;
return V_83 ;
}
void F_46 ( struct V_5 * V_6 , int V_73 )
{
struct V_33 T_6 * V_34 = V_6 -> V_34 ;
int V_57 = F_47 ( V_34 -> V_57 , V_73 ) ;
if ( ! F_48 ( V_73 , & V_6 -> V_84 ) )
return;
if ( F_49 ( V_57 ) ) {
F_50 ( V_57 , & V_34 -> V_85 ) ;
F_51 ( & V_6 -> V_84 ) ;
return;
}
F_52 ( V_57 , F_53 ( & V_34 -> V_85 , V_73 ) ) ;
}
void F_54 ( struct V_5 * V_6 )
{
int V_73 ;
F_55 (cpu, &armpmu->supported_cpus)
F_46 ( V_6 , V_73 ) ;
}
int F_56 ( struct V_5 * V_6 , int V_73 )
{
int V_86 = 0 ;
struct V_33 T_6 * V_34 = V_6 -> V_34 ;
const T_7 V_87 = F_28 ;
int V_57 = F_47 ( V_34 -> V_57 , V_73 ) ;
if ( ! V_57 )
return 0 ;
if ( F_49 ( V_57 ) && F_57 ( & V_6 -> V_84 ) ) {
V_86 = F_58 ( V_57 , V_87 , L_4 ,
& V_34 -> V_85 ) ;
} else if ( F_49 ( V_57 ) ) {
int V_88 = F_59 ( & V_6 -> V_84 ) ;
int V_89 = F_47 ( V_34 -> V_57 , V_88 ) ;
if ( V_57 != V_89 ) {
F_60 ( L_5 ) ;
V_86 = - V_51 ;
goto V_90;
}
} else {
struct V_52 * V_91 = F_26 ( V_6 ) ;
unsigned long V_92 ;
V_86 = F_61 ( V_57 , F_62 ( V_73 ) ) ;
if ( V_86 && F_63 () > 1 ) {
F_60 ( L_6 ,
V_57 , V_73 ) ;
goto V_90;
}
if ( V_91 && V_91 -> V_92 ) {
V_92 = V_91 -> V_92 ;
} else {
V_92 = V_93 |
V_94 |
V_95 ;
}
V_86 = F_64 ( V_57 , V_87 , V_92 , L_4 ,
F_53 ( & V_34 -> V_85 , V_73 ) ) ;
}
if ( V_86 )
goto V_90;
F_65 ( V_73 , & V_6 -> V_84 ) ;
return 0 ;
V_90:
F_66 ( L_7 , V_57 ) ;
return V_86 ;
}
int F_67 ( struct V_5 * V_6 )
{
int V_73 , V_86 ;
F_55 (cpu, &armpmu->supported_cpus) {
V_86 = F_56 ( V_6 , V_73 ) ;
if ( V_86 )
break;
}
return V_86 ;
}
static int F_68 ( struct V_5 * V_7 , int V_73 )
{
struct V_33 T_6 * V_34 = V_7 -> V_34 ;
return F_47 ( V_34 -> V_57 , V_73 ) ;
}
static int F_69 ( unsigned int V_73 , struct V_96 * V_97 )
{
struct V_5 * V_7 = F_70 ( V_97 , struct V_5 , V_97 ) ;
int V_57 ;
if ( ! F_20 ( V_73 , & V_7 -> V_40 ) )
return 0 ;
if ( V_7 -> V_98 )
V_7 -> V_98 ( V_7 ) ;
V_57 = F_68 ( V_7 , V_73 ) ;
if ( V_57 ) {
if ( F_49 ( V_57 ) ) {
F_71 ( V_57 , V_99 ) ;
return 0 ;
}
}
return 0 ;
}
static int F_72 ( unsigned int V_73 , struct V_96 * V_97 )
{
struct V_5 * V_7 = F_70 ( V_97 , struct V_5 , V_97 ) ;
int V_57 ;
if ( ! F_20 ( V_73 , & V_7 -> V_40 ) )
return 0 ;
V_57 = F_68 ( V_7 , V_73 ) ;
if ( V_57 && F_49 ( V_57 ) )
F_73 ( V_57 ) ;
return 0 ;
}
static void F_74 ( struct V_5 * V_6 , unsigned long V_100 )
{
struct V_33 * V_34 = F_17 ( V_6 -> V_34 ) ;
struct V_3 * V_4 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_6 -> V_75 ; V_35 ++ ) {
if ( ! F_75 ( V_35 , V_34 -> V_38 ) )
continue;
V_4 = V_34 -> V_37 [ V_35 ] ;
switch ( V_100 ) {
case V_101 :
F_13 ( V_4 , V_36 ) ;
break;
case V_102 :
case V_103 :
F_76 ( F_14 ( V_4 , V_31 ) ) ;
break;
default:
break;
}
}
}
static int F_77 ( struct V_104 * V_105 , unsigned long V_100 ,
void * V_106 )
{
struct V_5 * V_6 = F_78 ( V_105 , struct V_5 , V_107 ) ;
struct V_33 * V_34 = F_17 ( V_6 -> V_34 ) ;
int V_74 = F_38 ( V_34 -> V_38 , V_6 -> V_75 ) ;
if ( ! F_20 ( F_21 () , & V_6 -> V_40 ) )
return V_108 ;
if ( V_100 == V_102 && V_6 -> V_98 )
V_6 -> V_98 ( V_6 ) ;
if ( ! V_74 )
return V_109 ;
switch ( V_100 ) {
case V_101 :
V_6 -> V_77 ( V_6 ) ;
F_74 ( V_6 , V_100 ) ;
break;
case V_102 :
F_74 ( V_6 , V_100 ) ;
case V_103 :
V_6 -> V_76 ( V_6 ) ;
break;
default:
return V_108 ;
}
return V_109 ;
}
static int F_79 ( struct V_5 * V_110 )
{
V_110 -> V_107 . V_111 = F_77 ;
return F_80 ( & V_110 -> V_107 ) ;
}
static void F_81 ( struct V_5 * V_110 )
{
F_82 ( & V_110 -> V_107 ) ;
}
static inline int F_79 ( struct V_5 * V_110 ) { return 0 ; }
static inline void F_81 ( struct V_5 * V_110 ) { }
static int F_83 ( struct V_5 * V_110 )
{
int V_86 ;
V_86 = F_84 ( V_112 ,
& V_110 -> V_97 ) ;
if ( V_86 )
goto V_113;
V_86 = F_79 ( V_110 ) ;
if ( V_86 )
goto V_114;
return 0 ;
V_114:
F_85 ( V_112 ,
& V_110 -> V_97 ) ;
V_113:
return V_86 ;
}
static void F_86 ( struct V_5 * V_110 )
{
F_81 ( V_110 ) ;
F_85 ( V_112 ,
& V_110 -> V_97 ) ;
}
struct V_5 * F_87 ( void )
{
struct V_5 * V_7 ;
int V_73 ;
V_7 = F_88 ( sizeof( * V_7 ) , V_115 ) ;
if ( ! V_7 ) {
F_89 ( L_8 ) ;
goto V_113;
}
V_7 -> V_34 = F_90 ( struct V_33 ) ;
if ( ! V_7 -> V_34 ) {
F_89 ( L_9 ) ;
goto V_116;
}
V_7 -> V_7 = (struct V_7 ) {
. V_117 = F_37 ,
. V_118 = F_39 ,
. V_119 = F_35 ,
. V_120 = F_19 ,
. V_121 = F_16 ,
. V_76 = F_14 ,
. V_77 = F_13 ,
. V_122 = F_12 ,
. V_123 = F_40 ,
. V_124 = V_7 -> V_124 ,
. V_125 = V_126 ,
} ;
V_7 -> V_124 [ V_127 ] =
& V_128 ;
F_91 (cpu) {
struct V_33 * V_37 ;
V_37 = F_53 ( V_7 -> V_34 , V_73 ) ;
F_92 ( & V_37 -> V_129 ) ;
V_37 -> V_85 = V_7 ;
}
return V_7 ;
V_116:
F_93 ( V_7 ) ;
V_113:
return NULL ;
}
void F_94 ( struct V_5 * V_7 )
{
F_95 ( V_7 -> V_34 ) ;
F_93 ( V_7 ) ;
}
int F_96 ( struct V_5 * V_7 )
{
int V_15 ;
V_15 = F_83 ( V_7 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_97 ( & V_7 -> V_7 , V_7 -> V_82 , - 1 ) ;
if ( V_15 )
goto V_130;
if ( ! V_81 )
V_81 = V_7 ;
F_89 ( L_10 ,
V_7 -> V_82 , V_7 -> V_75 ) ;
return 0 ;
V_130:
F_86 ( V_7 ) ;
return V_15 ;
}
static int F_98 ( void )
{
int V_15 ;
V_15 = F_99 ( V_112 ,
L_11 ,
F_69 ,
F_72 ) ;
if ( V_15 )
F_66 ( L_12 ,
V_15 ) ;
return V_15 ;
}
