static T_1 F_1 ( unsigned long V_1 , T_1 V_2 ,
bool V_3 )
{
if ( ! V_3 || ( V_1 & V_4 ) )
return F_2 ( V_2 ) ;
return V_2 ;
}
static int T_2 F_3 ( char * V_5 )
{
V_6 = F_4 ( V_5 , & V_5 ) ;
return 0 ;
}
static void * F_5 ( T_3 V_7 , struct V_8 * * V_9 , T_4 V_10 )
{
unsigned long V_11 ;
void * V_12 = NULL ;
if ( ! V_13 ) {
F_6 ( 1 , L_1 ) ;
return NULL ;
}
V_11 = F_7 ( V_13 , V_7 ) ;
if ( V_11 ) {
T_5 V_14 = F_8 ( V_13 , V_11 ) ;
* V_9 = F_9 ( V_14 ) ;
V_12 = ( void * ) V_11 ;
memset ( V_12 , 0 , V_7 ) ;
}
return V_12 ;
}
static bool F_10 ( void * V_15 , T_3 V_7 )
{
return F_11 ( V_13 , ( unsigned long ) V_15 , V_7 ) ;
}
static int F_12 ( void * V_15 , T_3 V_7 )
{
if ( ! F_10 ( V_15 , V_7 ) )
return 0 ;
F_13 ( V_13 , ( unsigned long ) V_15 , V_7 ) ;
return 1 ;
}
static void * F_14 ( struct V_16 * V_17 , T_3 V_7 ,
T_6 * V_18 , T_4 V_10 ,
unsigned long V_1 )
{
if ( V_17 == NULL ) {
F_15 ( 1 , L_2 ) ;
return NULL ;
}
if ( F_16 ( V_19 ) &&
V_17 -> V_20 <= F_17 ( 32 ) )
V_10 |= V_21 ;
if ( F_18 ( V_17 ) && F_19 ( V_10 ) ) {
struct V_8 * V_8 ;
void * V_22 ;
V_8 = F_20 ( V_17 , V_7 >> V_23 ,
F_21 ( V_7 ) ) ;
if ( ! V_8 )
return NULL ;
* V_18 = F_22 ( V_17 , F_23 ( V_8 ) ) ;
V_22 = F_24 ( V_8 ) ;
memset ( V_22 , 0 , V_7 ) ;
return V_22 ;
} else {
return F_25 ( V_17 , V_7 , V_18 , V_10 ) ;
}
}
static void F_26 ( struct V_16 * V_17 , T_3 V_7 ,
void * V_24 , T_6 V_18 ,
unsigned long V_1 )
{
bool V_25 ;
T_5 V_26 = F_27 ( V_17 , V_18 ) ;
if ( V_17 == NULL ) {
F_15 ( 1 , L_2 ) ;
return;
}
V_25 = F_28 ( V_17 ,
F_9 ( V_26 ) ,
V_7 >> V_23 ) ;
if ( ! V_25 )
F_29 ( V_17 , V_7 , V_24 , V_18 ) ;
}
static void * F_30 ( struct V_16 * V_17 , T_3 V_7 ,
T_6 * V_18 , T_4 V_10 ,
unsigned long V_1 )
{
struct V_8 * V_8 ;
void * V_12 , * V_27 ;
bool V_3 = F_31 ( V_17 ) ;
T_1 V_2 = F_1 ( V_1 , V_28 , false ) ;
V_7 = F_32 ( V_7 ) ;
if ( ! V_3 && ! F_19 ( V_10 ) ) {
struct V_8 * V_8 = NULL ;
void * V_22 = F_5 ( V_7 , & V_8 , V_10 ) ;
if ( V_22 )
* V_18 = F_22 ( V_17 , F_23 ( V_8 ) ) ;
return V_22 ;
}
V_12 = F_14 ( V_17 , V_7 , V_18 , V_10 , V_1 ) ;
if ( ! V_12 )
goto V_29;
if ( V_3 )
return V_12 ;
F_33 ( V_12 , V_7 ) ;
V_8 = F_34 ( V_12 ) ;
V_27 = F_35 ( V_8 , V_7 , V_30 ,
V_2 , NULL ) ;
if ( ! V_27 )
goto V_31;
return V_27 ;
V_31:
F_26 ( V_17 , V_7 , V_12 , * V_18 , V_1 ) ;
V_29:
* V_18 = V_32 ;
return NULL ;
}
static void F_36 ( struct V_16 * V_17 , T_3 V_7 ,
void * V_24 , T_6 V_18 ,
unsigned long V_1 )
{
void * V_33 = F_37 ( F_27 ( V_17 , V_18 ) ) ;
V_7 = F_32 ( V_7 ) ;
if ( ! F_31 ( V_17 ) ) {
if ( F_12 ( V_24 , V_7 ) )
return;
F_38 ( V_24 ) ;
}
F_26 ( V_17 , V_7 , V_33 , V_18 , V_1 ) ;
}
static T_6 F_39 ( struct V_16 * V_17 , struct V_8 * V_8 ,
unsigned long V_34 , T_3 V_7 ,
enum V_35 V_36 ,
unsigned long V_1 )
{
T_6 V_37 ;
V_37 = F_40 ( V_17 , V_8 , V_34 , V_7 , V_36 , V_1 ) ;
if ( ! F_31 ( V_17 ) )
F_41 ( F_37 ( F_27 ( V_17 , V_37 ) ) , V_7 , V_36 ) ;
return V_37 ;
}
static void F_42 ( struct V_16 * V_17 , T_6 V_37 ,
T_3 V_7 , enum V_35 V_36 ,
unsigned long V_1 )
{
if ( ! F_31 ( V_17 ) )
F_43 ( F_37 ( F_27 ( V_17 , V_37 ) ) , V_7 , V_36 ) ;
F_44 ( V_17 , V_37 , V_7 , V_36 , V_1 ) ;
}
static int F_45 ( struct V_16 * V_17 , struct V_38 * V_39 ,
int V_40 , enum V_35 V_36 ,
unsigned long V_1 )
{
struct V_38 * V_41 ;
int V_42 , V_43 ;
V_43 = F_46 ( V_17 , V_39 , V_40 , V_36 , V_1 ) ;
if ( ! F_31 ( V_17 ) )
F_47 (sgl, sg, ret, i)
F_41 ( F_37 ( F_27 ( V_17 , V_41 -> V_44 ) ) ,
V_41 -> V_45 , V_36 ) ;
return V_43 ;
}
static void F_48 ( struct V_16 * V_17 ,
struct V_38 * V_39 , int V_40 ,
enum V_35 V_36 ,
unsigned long V_1 )
{
struct V_38 * V_41 ;
int V_42 ;
if ( ! F_31 ( V_17 ) )
F_47 (sgl, sg, nelems, i)
F_43 ( F_37 ( F_27 ( V_17 , V_41 -> V_44 ) ) ,
V_41 -> V_45 , V_36 ) ;
F_49 ( V_17 , V_39 , V_40 , V_36 , V_1 ) ;
}
static void F_50 ( struct V_16 * V_17 ,
T_6 V_37 , T_3 V_7 ,
enum V_35 V_36 )
{
if ( ! F_31 ( V_17 ) )
F_43 ( F_37 ( F_27 ( V_17 , V_37 ) ) , V_7 , V_36 ) ;
F_51 ( V_17 , V_37 , V_7 , V_36 ) ;
}
static void F_52 ( struct V_16 * V_17 ,
T_6 V_37 , T_3 V_7 ,
enum V_35 V_36 )
{
F_53 ( V_17 , V_37 , V_7 , V_36 ) ;
if ( ! F_31 ( V_17 ) )
F_41 ( F_37 ( F_27 ( V_17 , V_37 ) ) , V_7 , V_36 ) ;
}
static void F_54 ( struct V_16 * V_17 ,
struct V_38 * V_39 , int V_40 ,
enum V_35 V_36 )
{
struct V_38 * V_41 ;
int V_42 ;
if ( ! F_31 ( V_17 ) )
F_47 (sgl, sg, nelems, i)
F_43 ( F_37 ( F_27 ( V_17 , V_41 -> V_44 ) ) ,
V_41 -> V_45 , V_36 ) ;
F_55 ( V_17 , V_39 , V_40 , V_36 ) ;
}
static void F_56 ( struct V_16 * V_17 ,
struct V_38 * V_39 , int V_40 ,
enum V_35 V_36 )
{
struct V_38 * V_41 ;
int V_42 ;
F_57 ( V_17 , V_39 , V_40 , V_36 ) ;
if ( ! F_31 ( V_17 ) )
F_47 (sgl, sg, nelems, i)
F_41 ( F_37 ( F_27 ( V_17 , V_41 -> V_44 ) ) ,
V_41 -> V_45 , V_36 ) ;
}
static int F_58 ( struct V_16 * V_17 ,
struct V_46 * V_47 ,
void * V_48 , T_6 V_49 , T_3 V_7 ,
unsigned long V_1 )
{
int V_43 = - V_50 ;
unsigned long V_51 = ( V_47 -> V_52 - V_47 -> V_53 ) >>
V_23 ;
unsigned long V_54 = F_32 ( V_7 ) >> V_23 ;
unsigned long V_55 = F_27 ( V_17 , V_49 ) >> V_23 ;
unsigned long V_56 = V_47 -> V_57 ;
V_47 -> V_58 = F_1 ( V_1 , V_47 -> V_58 ,
F_31 ( V_17 ) ) ;
if ( F_59 ( V_17 , V_47 , V_48 , V_7 , & V_43 ) )
return V_43 ;
if ( V_56 < V_54 && V_51 <= ( V_54 - V_56 ) ) {
V_43 = F_60 ( V_47 , V_47 -> V_53 ,
V_55 + V_56 ,
V_47 -> V_52 - V_47 -> V_53 ,
V_47 -> V_58 ) ;
}
return V_43 ;
}
static int F_61 ( struct V_16 * V_17 , struct V_59 * V_60 ,
void * V_48 , T_6 V_61 , T_3 V_7 ,
unsigned long V_1 )
{
int V_43 = F_62 ( V_60 , 1 , V_62 ) ;
if ( ! V_43 )
F_63 ( V_60 -> V_39 , F_9 ( F_27 ( V_17 , V_61 ) ) ,
F_32 ( V_7 ) , 0 ) ;
return V_43 ;
}
static int F_64 ( struct V_16 * V_63 , T_7 V_64 )
{
if ( V_65 )
return F_65 ( V_63 , V_64 ) ;
return 1 ;
}
static int T_2 F_66 ( void )
{
T_1 V_2 = F_67 ( V_66 ) ;
unsigned long V_54 = V_6 >> V_23 ;
struct V_8 * V_8 ;
void * V_22 ;
unsigned int V_67 = F_21 ( V_6 ) ;
if ( F_18 ( NULL ) )
V_8 = F_20 ( NULL , V_54 ,
V_67 ) ;
else
V_8 = F_68 ( V_21 , V_67 ) ;
if ( V_8 ) {
int V_43 ;
void * V_68 = F_24 ( V_8 ) ;
memset ( V_68 , 0 , V_6 ) ;
F_33 ( V_68 , V_6 ) ;
V_13 = F_69 ( V_23 , - 1 ) ;
if ( ! V_13 )
goto V_69;
V_22 = F_35 ( V_8 , V_6 ,
V_30 , V_2 , F_66 ) ;
if ( ! V_22 )
goto V_70;
V_43 = F_70 ( V_13 , ( unsigned long ) V_22 ,
F_23 ( V_8 ) ,
V_6 , - 1 ) ;
if ( V_43 )
goto V_71;
F_71 ( V_13 ,
V_72 ,
( void * ) V_23 ) ;
F_72 ( L_3 ,
V_6 / 1024 ) ;
return 0 ;
}
goto V_73;
V_71:
F_73 ( V_22 , V_6 , V_30 ) ;
V_70:
F_74 ( V_13 ) ;
V_13 = NULL ;
V_69:
if ( ! F_28 ( NULL , V_8 , V_54 ) )
F_75 ( V_8 , V_67 ) ;
V_73:
F_76 ( L_4 ,
V_6 / 1024 ) ;
return - V_74 ;
}
static void * F_77 ( struct V_16 * V_17 , T_3 V_7 ,
T_6 * V_18 , T_4 V_10 ,
unsigned long V_1 )
{
return NULL ;
}
static void F_78 ( struct V_16 * V_17 , T_3 V_7 ,
void * V_24 , T_6 V_18 ,
unsigned long V_1 )
{
}
static int F_79 ( struct V_16 * V_17 ,
struct V_46 * V_47 ,
void * V_48 , T_6 V_49 , T_3 V_7 ,
unsigned long V_1 )
{
return - V_50 ;
}
static T_6 F_80 ( struct V_16 * V_17 , struct V_8 * V_8 ,
unsigned long V_34 , T_3 V_7 ,
enum V_35 V_36 ,
unsigned long V_1 )
{
return V_32 ;
}
static void F_81 ( struct V_16 * V_17 , T_6 V_37 ,
T_3 V_7 , enum V_35 V_36 ,
unsigned long V_1 )
{
}
static int F_82 ( struct V_16 * V_17 , struct V_38 * V_39 ,
int V_40 , enum V_35 V_36 ,
unsigned long V_1 )
{
return 0 ;
}
static void F_83 ( struct V_16 * V_17 ,
struct V_38 * V_39 , int V_40 ,
enum V_35 V_36 ,
unsigned long V_1 )
{
}
static void F_84 ( struct V_16 * V_17 ,
T_6 V_37 , T_3 V_7 ,
enum V_35 V_36 )
{
}
static void F_85 ( struct V_16 * V_17 ,
struct V_38 * V_39 , int V_40 ,
enum V_35 V_36 )
{
}
static int F_86 ( struct V_16 * V_63 , T_6 V_49 )
{
return 1 ;
}
static int F_87 ( struct V_16 * V_63 , T_7 V_64 )
{
return 0 ;
}
static int T_2 F_88 ( void )
{
if ( V_75 || V_76 > ( V_77 >> V_23 ) )
V_65 = 1 ;
return F_66 () ;
}
static int T_2 F_89 ( void )
{
F_90 ( V_78 ) ;
return 0 ;
}
static void F_91 ( struct V_16 * V_17 , const void * V_79 , T_5 V_14 )
{
F_33 ( V_79 , V_80 ) ;
}
static void * F_92 ( struct V_16 * V_17 , T_3 V_7 ,
T_6 * V_61 , T_4 V_81 ,
unsigned long V_1 )
{
bool V_3 = F_31 ( V_17 ) ;
int V_82 = F_93 ( V_83 , V_3 ) ;
T_3 V_84 = V_7 ;
void * V_22 ;
if ( F_6 ( ! V_17 , L_5 ) )
return NULL ;
V_7 = F_32 ( V_7 ) ;
V_81 |= V_85 ;
if ( F_19 ( V_81 ) ) {
struct V_8 * * V_86 ;
T_1 V_2 = F_1 ( V_1 , V_28 , V_3 ) ;
V_86 = F_94 ( V_17 , V_84 , V_81 , V_1 , V_82 ,
V_61 , F_91 ) ;
if ( ! V_86 )
return NULL ;
V_22 = F_95 ( V_86 , V_7 , V_30 , V_2 ,
F_96 ( 0 ) ) ;
if ( ! V_22 )
F_97 ( V_17 , V_86 , V_84 , V_61 ) ;
} else {
struct V_8 * V_8 ;
if ( V_3 ) {
V_8 = F_68 ( V_81 , F_21 ( V_7 ) ) ;
V_22 = V_8 ? F_24 ( V_8 ) : NULL ;
} else {
V_22 = F_5 ( V_7 , & V_8 , V_81 ) ;
}
if ( ! V_22 )
return NULL ;
* V_61 = F_98 ( V_17 , V_8 , 0 , V_84 , V_82 ) ;
if ( F_99 ( V_17 , * V_61 ) ) {
if ( V_3 )
F_75 ( V_8 , F_21 ( V_7 ) ) ;
else
F_12 ( V_22 , V_7 ) ;
V_22 = NULL ;
}
}
return V_22 ;
}
static void F_100 ( struct V_16 * V_17 , T_3 V_7 , void * V_48 ,
T_6 V_61 , unsigned long V_1 )
{
T_3 V_84 = V_7 ;
V_7 = F_32 ( V_7 ) ;
if ( F_10 ( V_48 , V_7 ) ) {
F_101 ( V_17 , V_61 , V_84 , 0 , 0 ) ;
F_12 ( V_48 , V_7 ) ;
} else if ( F_102 ( V_48 ) ) {
struct V_87 * V_88 = F_103 ( V_48 ) ;
if ( F_104 ( ! V_88 || ! V_88 -> V_86 ) )
return;
F_97 ( V_17 , V_88 -> V_86 , V_84 , & V_61 ) ;
F_73 ( V_48 , V_7 , V_30 ) ;
} else {
F_101 ( V_17 , V_61 , V_84 , 0 , 0 ) ;
F_75 ( F_34 ( V_48 ) , F_21 ( V_7 ) ) ;
}
}
static int F_105 ( struct V_16 * V_17 , struct V_46 * V_47 ,
void * V_48 , T_6 V_49 , T_3 V_7 ,
unsigned long V_1 )
{
struct V_87 * V_88 ;
int V_43 ;
V_47 -> V_58 = F_1 ( V_1 , V_47 -> V_58 ,
F_31 ( V_17 ) ) ;
if ( F_59 ( V_17 , V_47 , V_48 , V_7 , & V_43 ) )
return V_43 ;
V_88 = F_103 ( V_48 ) ;
if ( F_104 ( ! V_88 || ! V_88 -> V_86 ) )
return - V_50 ;
return F_106 ( V_88 -> V_86 , V_7 , V_47 ) ;
}
static int F_107 ( struct V_16 * V_17 , struct V_59 * V_60 ,
void * V_48 , T_6 V_49 ,
T_3 V_7 , unsigned long V_1 )
{
unsigned int V_89 = F_32 ( V_7 ) >> V_23 ;
struct V_87 * V_88 = F_103 ( V_48 ) ;
if ( F_104 ( ! V_88 || ! V_88 -> V_86 ) )
return - V_50 ;
return F_108 ( V_60 , V_88 -> V_86 , V_89 , 0 , V_7 ,
V_62 ) ;
}
static void F_109 ( struct V_16 * V_17 ,
T_6 V_37 , T_3 V_7 ,
enum V_35 V_36 )
{
T_5 V_14 ;
if ( F_31 ( V_17 ) )
return;
V_14 = F_110 ( F_111 ( V_17 ) , V_37 ) ;
F_43 ( F_37 ( V_14 ) , V_7 , V_36 ) ;
}
static void F_112 ( struct V_16 * V_17 ,
T_6 V_37 , T_3 V_7 ,
enum V_35 V_36 )
{
T_5 V_14 ;
if ( F_31 ( V_17 ) )
return;
V_14 = F_110 ( F_111 ( V_17 ) , V_37 ) ;
F_41 ( F_37 ( V_14 ) , V_7 , V_36 ) ;
}
static T_6 F_113 ( struct V_16 * V_17 , struct V_8 * V_8 ,
unsigned long V_34 , T_3 V_7 ,
enum V_35 V_36 ,
unsigned long V_1 )
{
bool V_3 = F_31 ( V_17 ) ;
int V_2 = F_93 ( V_36 , V_3 ) ;
T_6 V_37 = F_98 ( V_17 , V_8 , V_34 , V_7 , V_2 ) ;
if ( ! F_99 ( V_17 , V_37 ) &&
( V_1 & V_90 ) == 0 )
F_112 ( V_17 , V_37 , V_7 , V_36 ) ;
return V_37 ;
}
static void F_114 ( struct V_16 * V_17 , T_6 V_37 ,
T_3 V_7 , enum V_35 V_36 ,
unsigned long V_1 )
{
if ( ( V_1 & V_90 ) == 0 )
F_109 ( V_17 , V_37 , V_7 , V_36 ) ;
F_101 ( V_17 , V_37 , V_7 , V_36 , V_1 ) ;
}
static void F_115 ( struct V_16 * V_17 ,
struct V_38 * V_39 , int V_40 ,
enum V_35 V_36 )
{
struct V_38 * V_41 ;
int V_42 ;
if ( F_31 ( V_17 ) )
return;
F_47 (sgl, sg, nelems, i)
F_43 ( F_116 ( V_41 ) , V_41 -> V_45 , V_36 ) ;
}
static void F_117 ( struct V_16 * V_17 ,
struct V_38 * V_39 , int V_40 ,
enum V_35 V_36 )
{
struct V_38 * V_41 ;
int V_42 ;
if ( F_31 ( V_17 ) )
return;
F_47 (sgl, sg, nelems, i)
F_41 ( F_116 ( V_41 ) , V_41 -> V_45 , V_36 ) ;
}
static int F_118 ( struct V_16 * V_17 , struct V_38 * V_39 ,
int V_40 , enum V_35 V_36 ,
unsigned long V_1 )
{
bool V_3 = F_31 ( V_17 ) ;
if ( ( V_1 & V_90 ) == 0 )
F_117 ( V_17 , V_39 , V_40 , V_36 ) ;
return F_119 ( V_17 , V_39 , V_40 ,
F_93 ( V_36 , V_3 ) ) ;
}
static void F_120 ( struct V_16 * V_17 ,
struct V_38 * V_39 , int V_40 ,
enum V_35 V_36 ,
unsigned long V_1 )
{
if ( ( V_1 & V_90 ) == 0 )
F_115 ( V_17 , V_39 , V_40 , V_36 ) ;
F_121 ( V_17 , V_39 , V_40 , V_36 , V_1 ) ;
}
static bool F_122 ( struct V_16 * V_17 , const struct V_91 * V_92 ,
T_7 V_93 , T_7 V_7 )
{
struct V_94 * V_95 = F_111 ( V_17 ) ;
if ( ! V_95 || F_123 ( V_95 , V_93 , V_7 , V_17 ) ) {
F_124 ( L_6 ,
F_125 ( V_17 ) ) ;
return false ;
}
V_17 -> V_96 . V_97 = & V_98 ;
return true ;
}
static void F_126 ( struct V_16 * V_17 , const struct V_91 * V_92 ,
T_7 V_93 , T_7 V_7 )
{
struct V_99 * V_100 ;
V_100 = F_127 ( sizeof( * V_100 ) , V_62 ) ;
if ( ! V_100 )
return;
V_100 -> V_17 = V_17 ;
V_100 -> V_92 = V_92 ;
V_100 -> V_93 = V_93 ;
V_100 -> V_7 = V_7 ;
F_128 ( & V_101 ) ;
F_129 ( & V_100 -> V_102 , & V_103 ) ;
F_130 ( & V_101 ) ;
}
static int F_131 ( struct V_104 * V_105 ,
unsigned long V_106 , void * V_107 )
{
struct V_99 * V_108 , * V_109 ;
if ( V_106 != V_110 )
return 0 ;
F_128 ( & V_101 ) ;
F_132 (master, tmp, &iommu_dma_masters, list) {
if ( V_107 == V_108 -> V_17 && F_122 ( V_108 -> V_17 ,
V_108 -> V_92 , V_108 -> V_93 , V_108 -> V_7 ) ) {
F_133 ( & V_108 -> V_102 ) ;
F_134 ( V_108 ) ;
break;
}
}
F_130 ( & V_101 ) ;
return 0 ;
}
static int T_2 F_135 ( struct V_111 * V_112 )
{
struct V_104 * V_105 = F_127 ( sizeof( * V_105 ) , V_62 ) ;
int V_43 ;
if ( ! V_105 )
return - V_74 ;
V_105 -> V_113 = F_131 ;
V_43 = F_136 ( V_112 , V_105 ) ;
if ( V_43 ) {
F_124 ( L_7 ,
V_112 -> V_114 ) ;
F_134 ( V_105 ) ;
}
return V_43 ;
}
static int T_2 F_137 ( void )
{
int V_43 ;
V_43 = F_138 () ;
if ( ! V_43 )
V_43 = F_135 ( & V_115 ) ;
if ( ! V_43 )
V_43 = F_135 ( & V_116 ) ;
#ifdef F_139
if ( ! V_43 )
V_43 = F_135 ( & V_117 ) ;
#endif
return V_43 ;
}
static void F_140 ( struct V_16 * V_17 , T_7 V_93 , T_7 V_7 ,
const struct V_91 * V_92 )
{
struct V_118 * V_119 ;
if ( ! V_92 )
return;
V_119 = F_141 ( V_17 ) ;
if ( V_119 ) {
F_122 ( V_17 , V_92 , V_93 , V_7 ) ;
F_142 ( V_119 ) ;
} else {
F_126 ( V_17 , V_92 , V_93 , V_7 ) ;
}
}
void F_143 ( struct V_16 * V_17 )
{
struct V_94 * V_95 = F_111 ( V_17 ) ;
if ( F_104 ( V_95 ) )
F_144 ( V_95 , V_17 ) ;
V_17 -> V_96 . V_97 = NULL ;
}
static void F_140 ( struct V_16 * V_17 , T_7 V_93 , T_7 V_7 ,
const struct V_91 * V_120 )
{ }
void F_145 ( struct V_16 * V_17 , T_7 V_93 , T_7 V_7 ,
const struct V_91 * V_120 , bool V_3 )
{
if ( ! V_17 -> V_96 . V_97 )
V_17 -> V_96 . V_97 = & V_121 ;
V_17 -> V_96 . V_122 = V_3 ;
F_140 ( V_17 , V_93 , V_7 , V_120 ) ;
}
