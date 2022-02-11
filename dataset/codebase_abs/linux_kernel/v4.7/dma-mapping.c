static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_4 )
{
if ( ! V_4 || F_2 ( V_5 , V_2 ) )
return F_3 ( V_3 ) ;
return V_3 ;
}
static int T_2 F_4 ( char * V_6 )
{
V_7 = F_5 ( V_6 , & V_6 ) ;
return 0 ;
}
static void * F_6 ( T_3 V_8 , struct V_9 * * V_10 , T_4 V_11 )
{
unsigned long V_12 ;
void * V_13 = NULL ;
if ( ! V_14 ) {
F_7 ( 1 , L_1 ) ;
return NULL ;
}
V_12 = F_8 ( V_14 , V_8 ) ;
if ( V_12 ) {
T_5 V_15 = F_9 ( V_14 , V_12 ) ;
* V_10 = F_10 ( V_15 ) ;
V_13 = ( void * ) V_12 ;
memset ( V_13 , 0 , V_8 ) ;
}
return V_13 ;
}
static bool F_11 ( void * V_16 , T_3 V_8 )
{
return F_12 ( V_14 , ( unsigned long ) V_16 , V_8 ) ;
}
static int F_13 ( void * V_16 , T_3 V_8 )
{
if ( ! F_11 ( V_16 , V_8 ) )
return 0 ;
F_14 ( V_14 , ( unsigned long ) V_16 , V_8 ) ;
return 1 ;
}
static void * F_15 ( struct V_17 * V_18 , T_3 V_8 ,
T_6 * V_19 , T_4 V_11 ,
struct V_1 * V_2 )
{
if ( V_18 == NULL ) {
F_16 ( 1 , L_2 ) ;
return NULL ;
}
if ( F_17 ( V_20 ) &&
V_18 -> V_21 <= F_18 ( 32 ) )
V_11 |= V_22 ;
if ( F_19 ( V_18 ) && F_20 ( V_11 ) ) {
struct V_9 * V_9 ;
void * V_23 ;
V_9 = F_21 ( V_18 , V_8 >> V_24 ,
F_22 ( V_8 ) ) ;
if ( ! V_9 )
return NULL ;
* V_19 = F_23 ( V_18 , F_24 ( V_9 ) ) ;
V_23 = F_25 ( V_9 ) ;
memset ( V_23 , 0 , V_8 ) ;
return V_23 ;
} else {
return F_26 ( V_18 , V_8 , V_19 , V_11 ) ;
}
}
static void F_27 ( struct V_17 * V_18 , T_3 V_8 ,
void * V_25 , T_6 V_19 ,
struct V_1 * V_2 )
{
bool V_26 ;
T_5 V_27 = F_28 ( V_18 , V_19 ) ;
if ( V_18 == NULL ) {
F_16 ( 1 , L_2 ) ;
return;
}
V_26 = F_29 ( V_18 ,
F_10 ( V_27 ) ,
V_8 >> V_24 ) ;
if ( ! V_26 )
F_30 ( V_18 , V_8 , V_25 , V_19 ) ;
}
static void * F_31 ( struct V_17 * V_18 , T_3 V_8 ,
T_6 * V_19 , T_4 V_11 ,
struct V_1 * V_2 )
{
struct V_9 * V_9 ;
void * V_13 , * V_28 ;
bool V_4 = F_32 ( V_18 ) ;
T_1 V_3 = F_1 ( V_2 , V_29 , false ) ;
V_8 = F_33 ( V_8 ) ;
if ( ! V_4 && ! F_20 ( V_11 ) ) {
struct V_9 * V_9 = NULL ;
void * V_23 = F_6 ( V_8 , & V_9 , V_11 ) ;
if ( V_23 )
* V_19 = F_23 ( V_18 , F_24 ( V_9 ) ) ;
return V_23 ;
}
V_13 = F_15 ( V_18 , V_8 , V_19 , V_11 , V_2 ) ;
if ( ! V_13 )
goto V_30;
if ( V_4 )
return V_13 ;
F_34 ( V_13 , V_13 + V_8 ) ;
V_9 = F_35 ( V_13 ) ;
V_28 = F_36 ( V_9 , V_8 , V_31 ,
V_3 , NULL ) ;
if ( ! V_28 )
goto V_32;
return V_28 ;
V_32:
F_27 ( V_18 , V_8 , V_13 , * V_19 , V_2 ) ;
V_30:
* V_19 = V_33 ;
return NULL ;
}
static void F_37 ( struct V_17 * V_18 , T_3 V_8 ,
void * V_25 , T_6 V_19 ,
struct V_1 * V_2 )
{
void * V_34 = F_38 ( F_28 ( V_18 , V_19 ) ) ;
V_8 = F_33 ( V_8 ) ;
if ( ! F_32 ( V_18 ) ) {
if ( F_13 ( V_25 , V_8 ) )
return;
F_39 ( V_25 ) ;
}
F_27 ( V_18 , V_8 , V_34 , V_19 , V_2 ) ;
}
static T_6 F_40 ( struct V_17 * V_18 , struct V_9 * V_9 ,
unsigned long V_35 , T_3 V_8 ,
enum V_36 V_37 ,
struct V_1 * V_2 )
{
T_6 V_38 ;
V_38 = F_41 ( V_18 , V_9 , V_35 , V_8 , V_37 , V_2 ) ;
if ( ! F_32 ( V_18 ) )
F_42 ( F_38 ( F_28 ( V_18 , V_38 ) ) , V_8 , V_37 ) ;
return V_38 ;
}
static void F_43 ( struct V_17 * V_18 , T_6 V_38 ,
T_3 V_8 , enum V_36 V_37 ,
struct V_1 * V_2 )
{
if ( ! F_32 ( V_18 ) )
F_44 ( F_38 ( F_28 ( V_18 , V_38 ) ) , V_8 , V_37 ) ;
F_45 ( V_18 , V_38 , V_8 , V_37 , V_2 ) ;
}
static int F_46 ( struct V_17 * V_18 , struct V_39 * V_40 ,
int V_41 , enum V_36 V_37 ,
struct V_1 * V_2 )
{
struct V_39 * V_42 ;
int V_43 , V_44 ;
V_44 = F_47 ( V_18 , V_40 , V_41 , V_37 , V_2 ) ;
if ( ! F_32 ( V_18 ) )
F_48 (sgl, sg, ret, i)
F_42 ( F_38 ( F_28 ( V_18 , V_42 -> V_45 ) ) ,
V_42 -> V_46 , V_37 ) ;
return V_44 ;
}
static void F_49 ( struct V_17 * V_18 ,
struct V_39 * V_40 , int V_41 ,
enum V_36 V_37 ,
struct V_1 * V_2 )
{
struct V_39 * V_42 ;
int V_43 ;
if ( ! F_32 ( V_18 ) )
F_48 (sgl, sg, nelems, i)
F_44 ( F_38 ( F_28 ( V_18 , V_42 -> V_45 ) ) ,
V_42 -> V_46 , V_37 ) ;
F_50 ( V_18 , V_40 , V_41 , V_37 , V_2 ) ;
}
static void F_51 ( struct V_17 * V_18 ,
T_6 V_38 , T_3 V_8 ,
enum V_36 V_37 )
{
if ( ! F_32 ( V_18 ) )
F_44 ( F_38 ( F_28 ( V_18 , V_38 ) ) , V_8 , V_37 ) ;
F_52 ( V_18 , V_38 , V_8 , V_37 ) ;
}
static void F_53 ( struct V_17 * V_18 ,
T_6 V_38 , T_3 V_8 ,
enum V_36 V_37 )
{
F_54 ( V_18 , V_38 , V_8 , V_37 ) ;
if ( ! F_32 ( V_18 ) )
F_42 ( F_38 ( F_28 ( V_18 , V_38 ) ) , V_8 , V_37 ) ;
}
static void F_55 ( struct V_17 * V_18 ,
struct V_39 * V_40 , int V_41 ,
enum V_36 V_37 )
{
struct V_39 * V_42 ;
int V_43 ;
if ( ! F_32 ( V_18 ) )
F_48 (sgl, sg, nelems, i)
F_44 ( F_38 ( F_28 ( V_18 , V_42 -> V_45 ) ) ,
V_42 -> V_46 , V_37 ) ;
F_56 ( V_18 , V_40 , V_41 , V_37 ) ;
}
static void F_57 ( struct V_17 * V_18 ,
struct V_39 * V_40 , int V_41 ,
enum V_36 V_37 )
{
struct V_39 * V_42 ;
int V_43 ;
F_58 ( V_18 , V_40 , V_41 , V_37 ) ;
if ( ! F_32 ( V_18 ) )
F_48 (sgl, sg, nelems, i)
F_42 ( F_38 ( F_28 ( V_18 , V_42 -> V_45 ) ) ,
V_42 -> V_46 , V_37 ) ;
}
static int F_59 ( struct V_17 * V_18 ,
struct V_47 * V_48 ,
void * V_49 , T_6 V_50 , T_3 V_8 ,
struct V_1 * V_2 )
{
int V_44 = - V_51 ;
unsigned long V_52 = ( V_48 -> V_53 - V_48 -> V_54 ) >>
V_24 ;
unsigned long V_55 = F_33 ( V_8 ) >> V_24 ;
unsigned long V_56 = F_28 ( V_18 , V_50 ) >> V_24 ;
unsigned long V_57 = V_48 -> V_58 ;
V_48 -> V_59 = F_1 ( V_2 , V_48 -> V_59 ,
F_32 ( V_18 ) ) ;
if ( F_60 ( V_18 , V_48 , V_49 , V_8 , & V_44 ) )
return V_44 ;
if ( V_57 < V_55 && V_52 <= ( V_55 - V_57 ) ) {
V_44 = F_61 ( V_48 , V_48 -> V_54 ,
V_56 + V_57 ,
V_48 -> V_53 - V_48 -> V_54 ,
V_48 -> V_59 ) ;
}
return V_44 ;
}
static int F_62 ( struct V_17 * V_18 , struct V_60 * V_61 ,
void * V_49 , T_6 V_62 , T_3 V_8 ,
struct V_1 * V_2 )
{
int V_44 = F_63 ( V_61 , 1 , V_63 ) ;
if ( ! V_44 )
F_64 ( V_61 -> V_40 , F_10 ( F_28 ( V_18 , V_62 ) ) ,
F_33 ( V_8 ) , 0 ) ;
return V_44 ;
}
static int T_2 F_65 ( void )
{
T_1 V_3 = F_66 ( V_64 ) ;
unsigned long V_55 = V_7 >> V_24 ;
struct V_9 * V_9 ;
void * V_23 ;
unsigned int V_65 = F_22 ( V_7 ) ;
if ( F_19 ( NULL ) )
V_9 = F_21 ( NULL , V_55 ,
V_65 ) ;
else
V_9 = F_67 ( V_22 , V_65 ) ;
if ( V_9 ) {
int V_44 ;
void * V_66 = F_25 ( V_9 ) ;
memset ( V_66 , 0 , V_7 ) ;
F_34 ( V_66 , V_66 + V_7 ) ;
V_14 = F_68 ( V_24 , - 1 ) ;
if ( ! V_14 )
goto V_67;
V_23 = F_36 ( V_9 , V_7 ,
V_31 , V_3 , F_65 ) ;
if ( ! V_23 )
goto V_68;
V_44 = F_69 ( V_14 , ( unsigned long ) V_23 ,
F_24 ( V_9 ) ,
V_7 , - 1 ) ;
if ( V_44 )
goto V_69;
F_70 ( V_14 ,
V_70 ,
( void * ) V_24 ) ;
F_71 ( L_3 ,
V_7 / 1024 ) ;
return 0 ;
}
goto V_71;
V_69:
F_72 ( V_23 , V_7 , V_31 ) ;
V_68:
F_73 ( V_14 ) ;
V_14 = NULL ;
V_67:
if ( ! F_29 ( NULL , V_9 , V_55 ) )
F_74 ( V_9 , V_65 ) ;
V_71:
F_75 ( L_4 ,
V_7 / 1024 ) ;
return - V_72 ;
}
static void * F_76 ( struct V_17 * V_18 , T_3 V_8 ,
T_6 * V_19 , T_4 V_11 ,
struct V_1 * V_2 )
{
return NULL ;
}
static void F_77 ( struct V_17 * V_18 , T_3 V_8 ,
void * V_25 , T_6 V_19 ,
struct V_1 * V_2 )
{
}
static int F_78 ( struct V_17 * V_18 ,
struct V_47 * V_48 ,
void * V_49 , T_6 V_50 , T_3 V_8 ,
struct V_1 * V_2 )
{
return - V_51 ;
}
static T_6 F_79 ( struct V_17 * V_18 , struct V_9 * V_9 ,
unsigned long V_35 , T_3 V_8 ,
enum V_36 V_37 ,
struct V_1 * V_2 )
{
return V_33 ;
}
static void F_80 ( struct V_17 * V_18 , T_6 V_38 ,
T_3 V_8 , enum V_36 V_37 ,
struct V_1 * V_2 )
{
}
static int F_81 ( struct V_17 * V_18 , struct V_39 * V_40 ,
int V_41 , enum V_36 V_37 ,
struct V_1 * V_2 )
{
return 0 ;
}
static void F_82 ( struct V_17 * V_18 ,
struct V_39 * V_40 , int V_41 ,
enum V_36 V_37 ,
struct V_1 * V_2 )
{
}
static void F_83 ( struct V_17 * V_18 ,
T_6 V_38 , T_3 V_8 ,
enum V_36 V_37 )
{
}
static void F_84 ( struct V_17 * V_18 ,
struct V_39 * V_40 , int V_41 ,
enum V_36 V_37 )
{
}
static int F_85 ( struct V_17 * V_73 , T_6 V_50 )
{
return 1 ;
}
static int F_86 ( struct V_17 * V_73 , T_7 V_74 )
{
return 0 ;
}
static int T_2 F_87 ( void )
{
return F_65 () ;
}
static int T_2 F_88 ( void )
{
F_89 ( V_75 ) ;
return 0 ;
}
static void F_90 ( struct V_17 * V_18 , const void * V_76 , T_5 V_15 )
{
F_34 ( V_76 , V_76 + V_77 ) ;
}
static void * F_91 ( struct V_17 * V_18 , T_3 V_8 ,
T_6 * V_62 , T_4 V_78 ,
struct V_1 * V_2 )
{
bool V_4 = F_32 ( V_18 ) ;
int V_79 = F_92 ( V_80 , V_4 ) ;
T_3 V_81 = V_8 ;
void * V_23 ;
if ( F_7 ( ! V_18 , L_5 ) )
return NULL ;
V_8 = F_33 ( V_8 ) ;
V_78 |= V_82 ;
if ( F_20 ( V_78 ) ) {
struct V_9 * * V_83 ;
T_1 V_3 = F_1 ( V_2 , V_29 , V_4 ) ;
V_83 = F_93 ( V_18 , V_81 , V_78 , V_2 , V_79 ,
V_62 , F_90 ) ;
if ( ! V_83 )
return NULL ;
V_23 = F_94 ( V_83 , V_8 , V_31 , V_3 ,
F_95 ( 0 ) ) ;
if ( ! V_23 )
F_96 ( V_18 , V_83 , V_81 , V_62 ) ;
} else {
struct V_9 * V_9 ;
if ( V_4 ) {
V_9 = F_67 ( V_78 , F_22 ( V_8 ) ) ;
V_23 = V_9 ? F_25 ( V_9 ) : NULL ;
} else {
V_23 = F_6 ( V_8 , & V_9 , V_78 ) ;
}
if ( ! V_23 )
return NULL ;
* V_62 = F_97 ( V_18 , V_9 , 0 , V_81 , V_79 ) ;
if ( F_98 ( V_18 , * V_62 ) ) {
if ( V_4 )
F_74 ( V_9 , F_22 ( V_8 ) ) ;
else
F_13 ( V_23 , V_8 ) ;
V_23 = NULL ;
}
}
return V_23 ;
}
static void F_99 ( struct V_17 * V_18 , T_3 V_8 , void * V_49 ,
T_6 V_62 , struct V_1 * V_2 )
{
T_3 V_81 = V_8 ;
V_8 = F_33 ( V_8 ) ;
if ( F_11 ( V_49 , V_8 ) ) {
F_100 ( V_18 , V_62 , V_81 , 0 , NULL ) ;
F_13 ( V_49 , V_8 ) ;
} else if ( F_101 ( V_49 ) ) {
struct V_84 * V_85 = F_102 ( V_49 ) ;
if ( F_103 ( ! V_85 || ! V_85 -> V_83 ) )
return;
F_96 ( V_18 , V_85 -> V_83 , V_81 , & V_62 ) ;
F_72 ( V_49 , V_8 , V_31 ) ;
} else {
F_100 ( V_18 , V_62 , V_81 , 0 , NULL ) ;
F_74 ( F_35 ( V_49 ) , F_22 ( V_8 ) ) ;
}
}
static int F_104 ( struct V_17 * V_18 , struct V_47 * V_48 ,
void * V_49 , T_6 V_50 , T_3 V_8 ,
struct V_1 * V_2 )
{
struct V_84 * V_85 ;
int V_44 ;
V_48 -> V_59 = F_1 ( V_2 , V_48 -> V_59 ,
F_32 ( V_18 ) ) ;
if ( F_60 ( V_18 , V_48 , V_49 , V_8 , & V_44 ) )
return V_44 ;
V_85 = F_102 ( V_49 ) ;
if ( F_103 ( ! V_85 || ! V_85 -> V_83 ) )
return - V_51 ;
return F_105 ( V_85 -> V_83 , V_8 , V_48 ) ;
}
static int F_106 ( struct V_17 * V_18 , struct V_60 * V_61 ,
void * V_49 , T_6 V_50 ,
T_3 V_8 , struct V_1 * V_2 )
{
unsigned int V_86 = F_33 ( V_8 ) >> V_24 ;
struct V_84 * V_85 = F_102 ( V_49 ) ;
if ( F_103 ( ! V_85 || ! V_85 -> V_83 ) )
return - V_51 ;
return F_107 ( V_61 , V_85 -> V_83 , V_86 , 0 , V_8 ,
V_63 ) ;
}
static void F_108 ( struct V_17 * V_18 ,
T_6 V_38 , T_3 V_8 ,
enum V_36 V_37 )
{
T_5 V_15 ;
if ( F_32 ( V_18 ) )
return;
V_15 = F_109 ( F_110 ( V_18 ) , V_38 ) ;
F_44 ( F_38 ( V_15 ) , V_8 , V_37 ) ;
}
static void F_111 ( struct V_17 * V_18 ,
T_6 V_38 , T_3 V_8 ,
enum V_36 V_37 )
{
T_5 V_15 ;
if ( F_32 ( V_18 ) )
return;
V_15 = F_109 ( F_110 ( V_18 ) , V_38 ) ;
F_42 ( F_38 ( V_15 ) , V_8 , V_37 ) ;
}
static T_6 F_112 ( struct V_17 * V_18 , struct V_9 * V_9 ,
unsigned long V_35 , T_3 V_8 ,
enum V_36 V_37 ,
struct V_1 * V_2 )
{
bool V_4 = F_32 ( V_18 ) ;
int V_3 = F_92 ( V_37 , V_4 ) ;
T_6 V_38 = F_97 ( V_18 , V_9 , V_35 , V_8 , V_3 ) ;
if ( ! F_98 ( V_18 , V_38 ) &&
! F_2 ( V_87 , V_2 ) )
F_111 ( V_18 , V_38 , V_8 , V_37 ) ;
return V_38 ;
}
static void F_113 ( struct V_17 * V_18 , T_6 V_38 ,
T_3 V_8 , enum V_36 V_37 ,
struct V_1 * V_2 )
{
if ( ! F_2 ( V_87 , V_2 ) )
F_108 ( V_18 , V_38 , V_8 , V_37 ) ;
F_100 ( V_18 , V_38 , V_8 , V_37 , V_2 ) ;
}
static void F_114 ( struct V_17 * V_18 ,
struct V_39 * V_40 , int V_41 ,
enum V_36 V_37 )
{
struct V_39 * V_42 ;
int V_43 ;
if ( F_32 ( V_18 ) )
return;
F_48 (sgl, sg, nelems, i)
F_44 ( F_115 ( V_42 ) , V_42 -> V_46 , V_37 ) ;
}
static void F_116 ( struct V_17 * V_18 ,
struct V_39 * V_40 , int V_41 ,
enum V_36 V_37 )
{
struct V_39 * V_42 ;
int V_43 ;
if ( F_32 ( V_18 ) )
return;
F_48 (sgl, sg, nelems, i)
F_42 ( F_115 ( V_42 ) , V_42 -> V_46 , V_37 ) ;
}
static int F_117 ( struct V_17 * V_18 , struct V_39 * V_40 ,
int V_41 , enum V_36 V_37 ,
struct V_1 * V_2 )
{
bool V_4 = F_32 ( V_18 ) ;
if ( ! F_2 ( V_87 , V_2 ) )
F_116 ( V_18 , V_40 , V_41 , V_37 ) ;
return F_118 ( V_18 , V_40 , V_41 ,
F_92 ( V_37 , V_4 ) ) ;
}
static void F_119 ( struct V_17 * V_18 ,
struct V_39 * V_40 , int V_41 ,
enum V_36 V_37 ,
struct V_1 * V_2 )
{
if ( ! F_2 ( V_87 , V_2 ) )
F_114 ( V_18 , V_40 , V_41 , V_37 ) ;
F_120 ( V_18 , V_40 , V_41 , V_37 , V_2 ) ;
}
static bool F_121 ( struct V_17 * V_18 , const struct V_88 * V_89 ,
T_7 V_90 , T_7 V_8 )
{
struct V_91 * V_92 = F_110 ( V_18 ) ;
if ( ! V_92 || F_122 ( V_92 , V_90 , V_8 ) ) {
F_123 ( L_6 ,
F_124 ( V_18 ) ) ;
return false ;
}
V_18 -> V_93 . V_94 = & V_95 ;
return true ;
}
static void F_125 ( struct V_17 * V_18 , const struct V_88 * V_89 ,
T_7 V_90 , T_7 V_8 )
{
struct V_96 * V_97 ;
V_97 = F_126 ( sizeof( * V_97 ) , V_63 ) ;
if ( ! V_97 )
return;
V_97 -> V_18 = V_18 ;
V_97 -> V_89 = V_89 ;
V_97 -> V_90 = V_90 ;
V_97 -> V_8 = V_8 ;
F_127 ( & V_98 ) ;
F_128 ( & V_97 -> V_99 , & V_100 ) ;
F_129 ( & V_98 ) ;
}
static int F_130 ( struct V_101 * V_102 ,
unsigned long V_103 , void * V_104 )
{
struct V_96 * V_105 , * V_106 ;
if ( V_103 != V_107 )
return 0 ;
F_127 ( & V_98 ) ;
F_131 (master, tmp, &iommu_dma_masters, list) {
if ( F_121 ( V_105 -> V_18 , V_105 -> V_89 ,
V_105 -> V_90 , V_105 -> V_8 ) ) {
F_132 ( & V_105 -> V_99 ) ;
F_133 ( V_105 ) ;
}
}
F_129 ( & V_98 ) ;
return 0 ;
}
static int T_2 F_134 ( struct V_108 * V_109 )
{
struct V_101 * V_102 = F_126 ( sizeof( * V_102 ) , V_63 ) ;
int V_44 ;
if ( ! V_102 )
return - V_72 ;
V_102 -> V_110 = F_130 ;
V_102 -> V_111 = - 100 ;
V_44 = F_135 ( V_109 , V_102 ) ;
if ( V_44 ) {
F_123 ( L_7 ,
V_109 -> V_112 ) ;
F_133 ( V_102 ) ;
}
return V_44 ;
}
static int T_2 F_136 ( void )
{
int V_44 ;
V_44 = F_137 () ;
if ( ! V_44 )
V_44 = F_134 ( & V_113 ) ;
if ( ! V_44 )
V_44 = F_134 ( & V_114 ) ;
#ifdef F_138
if ( ! V_44 )
V_44 = F_134 ( & V_115 ) ;
#endif
if ( ! V_44 )
F_130 ( NULL , V_107 , NULL ) ;
return V_44 ;
}
static void F_139 ( struct V_17 * V_18 , T_7 V_90 , T_7 V_8 ,
const struct V_88 * V_89 )
{
struct V_116 * V_117 ;
if ( ! V_89 )
return;
V_117 = F_140 ( V_18 ) ;
if ( V_117 ) {
F_121 ( V_18 , V_89 , V_90 , V_8 ) ;
F_141 ( V_117 ) ;
} else {
F_125 ( V_18 , V_89 , V_90 , V_8 ) ;
}
}
void F_142 ( struct V_17 * V_18 )
{
struct V_91 * V_92 = F_110 ( V_18 ) ;
if ( F_103 ( V_92 ) )
F_143 ( V_92 , V_18 ) ;
V_18 -> V_93 . V_94 = NULL ;
}
static void F_139 ( struct V_17 * V_18 , T_7 V_90 , T_7 V_8 ,
const struct V_88 * V_118 )
{ }
void F_144 ( struct V_17 * V_18 , T_7 V_90 , T_7 V_8 ,
const struct V_88 * V_118 , bool V_4 )
{
if ( ! V_18 -> V_93 . V_94 )
V_18 -> V_93 . V_94 = & V_119 ;
V_18 -> V_93 . V_120 = V_4 ;
F_139 ( V_18 , V_90 , V_8 , V_118 ) ;
}
