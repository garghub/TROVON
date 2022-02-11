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
F_21 ( V_7 ) , V_10 ) ;
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
if ( ! F_31 ( V_17 ) &&
( V_1 & V_38 ) == 0 )
F_41 ( F_37 ( F_27 ( V_17 , V_37 ) ) , V_7 , V_36 ) ;
return V_37 ;
}
static void F_42 ( struct V_16 * V_17 , T_6 V_37 ,
T_3 V_7 , enum V_35 V_36 ,
unsigned long V_1 )
{
if ( ! F_31 ( V_17 ) &&
( V_1 & V_38 ) == 0 )
F_43 ( F_37 ( F_27 ( V_17 , V_37 ) ) , V_7 , V_36 ) ;
F_44 ( V_17 , V_37 , V_7 , V_36 , V_1 ) ;
}
static int F_45 ( struct V_16 * V_17 , struct V_39 * V_40 ,
int V_41 , enum V_35 V_36 ,
unsigned long V_1 )
{
struct V_39 * V_42 ;
int V_43 , V_44 ;
V_44 = F_46 ( V_17 , V_40 , V_41 , V_36 , V_1 ) ;
if ( ! F_31 ( V_17 ) &&
( V_1 & V_38 ) == 0 )
F_47 (sgl, sg, ret, i)
F_41 ( F_37 ( F_27 ( V_17 , V_42 -> V_45 ) ) ,
V_42 -> V_46 , V_36 ) ;
return V_44 ;
}
static void F_48 ( struct V_16 * V_17 ,
struct V_39 * V_40 , int V_41 ,
enum V_35 V_36 ,
unsigned long V_1 )
{
struct V_39 * V_42 ;
int V_43 ;
if ( ! F_31 ( V_17 ) &&
( V_1 & V_38 ) == 0 )
F_47 (sgl, sg, nelems, i)
F_43 ( F_37 ( F_27 ( V_17 , V_42 -> V_45 ) ) ,
V_42 -> V_46 , V_36 ) ;
F_49 ( V_17 , V_40 , V_41 , V_36 , V_1 ) ;
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
struct V_39 * V_40 , int V_41 ,
enum V_35 V_36 )
{
struct V_39 * V_42 ;
int V_43 ;
if ( ! F_31 ( V_17 ) )
F_47 (sgl, sg, nelems, i)
F_43 ( F_37 ( F_27 ( V_17 , V_42 -> V_45 ) ) ,
V_42 -> V_46 , V_36 ) ;
F_55 ( V_17 , V_40 , V_41 , V_36 ) ;
}
static void F_56 ( struct V_16 * V_17 ,
struct V_39 * V_40 , int V_41 ,
enum V_35 V_36 )
{
struct V_39 * V_42 ;
int V_43 ;
F_57 ( V_17 , V_40 , V_41 , V_36 ) ;
if ( ! F_31 ( V_17 ) )
F_47 (sgl, sg, nelems, i)
F_41 ( F_37 ( F_27 ( V_17 , V_42 -> V_45 ) ) ,
V_42 -> V_46 , V_36 ) ;
}
static int F_58 ( struct V_47 * V_48 ,
unsigned long V_49 , T_3 V_7 )
{
int V_44 = - V_50 ;
unsigned long V_51 = ( V_48 -> V_52 - V_48 -> V_53 ) >>
V_23 ;
unsigned long V_54 = F_32 ( V_7 ) >> V_23 ;
unsigned long V_55 = V_48 -> V_56 ;
if ( V_55 < V_54 && V_51 <= ( V_54 - V_55 ) ) {
V_44 = F_59 ( V_48 , V_48 -> V_53 ,
V_49 + V_55 ,
V_48 -> V_52 - V_48 -> V_53 ,
V_48 -> V_57 ) ;
}
return V_44 ;
}
static int F_60 ( struct V_16 * V_17 ,
struct V_47 * V_48 ,
void * V_58 , T_6 V_59 , T_3 V_7 ,
unsigned long V_1 )
{
int V_44 ;
unsigned long V_49 = F_27 ( V_17 , V_59 ) >> V_23 ;
V_48 -> V_57 = F_1 ( V_1 , V_48 -> V_57 ,
F_31 ( V_17 ) ) ;
if ( F_61 ( V_17 , V_48 , V_58 , V_7 , & V_44 ) )
return V_44 ;
return F_58 ( V_48 , V_49 , V_7 ) ;
}
static int F_62 ( struct V_60 * V_61 ,
struct V_8 * V_8 , T_3 V_7 )
{
int V_44 = F_63 ( V_61 , 1 , V_62 ) ;
if ( ! V_44 )
F_64 ( V_61 -> V_40 , V_8 , F_32 ( V_7 ) , 0 ) ;
return V_44 ;
}
static int F_65 ( struct V_16 * V_17 , struct V_60 * V_61 ,
void * V_58 , T_6 V_63 , T_3 V_7 ,
unsigned long V_1 )
{
struct V_8 * V_8 = F_9 ( F_27 ( V_17 , V_63 ) ) ;
return F_62 ( V_61 , V_8 , V_7 ) ;
}
static int F_66 ( struct V_16 * V_64 , T_7 V_65 )
{
if ( V_66 )
return F_67 ( V_64 , V_65 ) ;
return 1 ;
}
static int F_68 ( struct V_16 * V_64 , T_6 V_22 )
{
if ( V_66 )
return F_69 ( V_64 , V_22 ) ;
return 0 ;
}
static int T_2 F_70 ( void )
{
T_1 V_2 = F_71 ( V_67 ) ;
unsigned long V_54 = V_6 >> V_23 ;
struct V_8 * V_8 ;
void * V_22 ;
unsigned int V_68 = F_21 ( V_6 ) ;
if ( F_18 ( NULL ) )
V_8 = F_20 ( NULL , V_54 ,
V_68 , V_62 ) ;
else
V_8 = F_72 ( V_21 , V_68 ) ;
if ( V_8 ) {
int V_44 ;
void * V_69 = F_24 ( V_8 ) ;
memset ( V_69 , 0 , V_6 ) ;
F_33 ( V_69 , V_6 ) ;
V_13 = F_73 ( V_23 , - 1 ) ;
if ( ! V_13 )
goto V_70;
V_22 = F_35 ( V_8 , V_6 ,
V_30 , V_2 , F_70 ) ;
if ( ! V_22 )
goto V_71;
V_44 = F_74 ( V_13 , ( unsigned long ) V_22 ,
F_23 ( V_8 ) ,
V_6 , - 1 ) ;
if ( V_44 )
goto V_72;
F_75 ( V_13 ,
V_73 ,
( void * ) V_23 ) ;
F_76 ( L_3 ,
V_6 / 1024 ) ;
return 0 ;
}
goto V_74;
V_72:
F_77 ( V_22 , V_6 , V_30 ) ;
V_71:
F_78 ( V_13 ) ;
V_13 = NULL ;
V_70:
if ( ! F_28 ( NULL , V_8 , V_54 ) )
F_79 ( V_8 , V_68 ) ;
V_74:
F_80 ( L_4 ,
V_6 / 1024 ) ;
return - V_75 ;
}
static void * F_81 ( struct V_16 * V_17 , T_3 V_7 ,
T_6 * V_18 , T_4 V_10 ,
unsigned long V_1 )
{
return NULL ;
}
static void F_82 ( struct V_16 * V_17 , T_3 V_7 ,
void * V_24 , T_6 V_18 ,
unsigned long V_1 )
{
}
static int F_83 ( struct V_16 * V_17 ,
struct V_47 * V_48 ,
void * V_58 , T_6 V_59 , T_3 V_7 ,
unsigned long V_1 )
{
return - V_50 ;
}
static T_6 F_84 ( struct V_16 * V_17 , struct V_8 * V_8 ,
unsigned long V_34 , T_3 V_7 ,
enum V_35 V_36 ,
unsigned long V_1 )
{
return V_32 ;
}
static void F_85 ( struct V_16 * V_17 , T_6 V_37 ,
T_3 V_7 , enum V_35 V_36 ,
unsigned long V_1 )
{
}
static int F_86 ( struct V_16 * V_17 , struct V_39 * V_40 ,
int V_41 , enum V_35 V_36 ,
unsigned long V_1 )
{
return 0 ;
}
static void F_87 ( struct V_16 * V_17 ,
struct V_39 * V_40 , int V_41 ,
enum V_35 V_36 ,
unsigned long V_1 )
{
}
static void F_88 ( struct V_16 * V_17 ,
T_6 V_37 , T_3 V_7 ,
enum V_35 V_36 )
{
}
static void F_89 ( struct V_16 * V_17 ,
struct V_39 * V_40 , int V_41 ,
enum V_35 V_36 )
{
}
static int F_90 ( struct V_16 * V_64 , T_6 V_59 )
{
return 1 ;
}
static int F_91 ( struct V_16 * V_64 , T_7 V_65 )
{
return 0 ;
}
static int T_2 F_92 ( void )
{
if ( V_76 == V_77 ||
V_78 > ( V_79 >> V_23 ) )
V_66 = 1 ;
return F_70 () ;
}
static int T_2 F_93 ( void )
{
F_94 ( V_80 ) ;
return 0 ;
}
static void F_95 ( struct V_16 * V_17 , const void * V_81 , T_5 V_14 )
{
F_33 ( V_81 , V_82 ) ;
}
static void * F_96 ( struct V_16 * V_17 , T_3 V_7 ,
T_6 * V_63 , T_4 V_83 ,
unsigned long V_1 )
{
bool V_3 = F_31 ( V_17 ) ;
int V_84 = F_97 ( V_85 , V_3 , V_1 ) ;
T_3 V_86 = V_7 ;
void * V_22 ;
if ( F_6 ( ! V_17 , L_5 ) )
return NULL ;
V_7 = F_32 ( V_7 ) ;
V_83 |= V_87 ;
if ( ! F_19 ( V_83 ) ) {
struct V_8 * V_8 ;
if ( V_3 ) {
V_8 = F_72 ( V_83 , F_21 ( V_7 ) ) ;
V_22 = V_8 ? F_24 ( V_8 ) : NULL ;
} else {
V_22 = F_5 ( V_7 , & V_8 , V_83 ) ;
}
if ( ! V_22 )
return NULL ;
* V_63 = F_98 ( V_17 , V_8 , 0 , V_86 , V_84 ) ;
if ( F_99 ( V_17 , * V_63 ) ) {
if ( V_3 )
F_79 ( V_8 , F_21 ( V_7 ) ) ;
else
F_12 ( V_22 , V_7 ) ;
V_22 = NULL ;
}
} else if ( V_1 & V_88 ) {
T_1 V_2 = F_1 ( V_1 , V_28 , V_3 ) ;
struct V_8 * V_8 ;
V_8 = F_20 ( V_17 , V_7 >> V_23 ,
F_21 ( V_7 ) , V_83 ) ;
if ( ! V_8 )
return NULL ;
* V_63 = F_98 ( V_17 , V_8 , 0 , V_86 , V_84 ) ;
if ( F_99 ( V_17 , * V_63 ) ) {
F_28 ( V_17 , V_8 ,
V_7 >> V_23 ) ;
return NULL ;
}
if ( ! V_3 )
F_33 ( F_100 ( V_8 ) , V_86 ) ;
V_22 = F_35 ( V_8 , V_7 , V_30 ,
V_2 ,
F_101 ( 0 ) ) ;
if ( ! V_22 ) {
F_102 ( V_17 , * V_63 , V_86 , 0 , V_1 ) ;
F_28 ( V_17 , V_8 ,
V_7 >> V_23 ) ;
}
} else {
T_1 V_2 = F_1 ( V_1 , V_28 , V_3 ) ;
struct V_8 * * V_89 ;
V_89 = F_103 ( V_17 , V_86 , V_83 , V_1 , V_84 ,
V_63 , F_95 ) ;
if ( ! V_89 )
return NULL ;
V_22 = F_104 ( V_89 , V_7 , V_30 , V_2 ,
F_101 ( 0 ) ) ;
if ( ! V_22 )
F_105 ( V_17 , V_89 , V_86 , V_63 ) ;
}
return V_22 ;
}
static void F_106 ( struct V_16 * V_17 , T_3 V_7 , void * V_58 ,
T_6 V_63 , unsigned long V_1 )
{
T_3 V_86 = V_7 ;
V_7 = F_32 ( V_7 ) ;
if ( F_10 ( V_58 , V_7 ) ) {
F_102 ( V_17 , V_63 , V_86 , 0 , 0 ) ;
F_12 ( V_58 , V_7 ) ;
} else if ( V_1 & V_88 ) {
struct V_8 * V_8 = F_107 ( V_58 ) ;
F_102 ( V_17 , V_63 , V_86 , 0 , V_1 ) ;
F_28 ( V_17 , V_8 , V_7 >> V_23 ) ;
F_77 ( V_58 , V_7 , V_30 ) ;
} else if ( F_108 ( V_58 ) ) {
struct V_90 * V_91 = F_109 ( V_58 ) ;
if ( F_110 ( ! V_91 || ! V_91 -> V_89 ) )
return;
F_105 ( V_17 , V_91 -> V_89 , V_86 , & V_63 ) ;
F_77 ( V_58 , V_7 , V_30 ) ;
} else {
F_102 ( V_17 , V_63 , V_86 , 0 , 0 ) ;
F_79 ( F_34 ( V_58 ) , F_21 ( V_7 ) ) ;
}
}
static int F_111 ( struct V_16 * V_17 , struct V_47 * V_48 ,
void * V_58 , T_6 V_59 , T_3 V_7 ,
unsigned long V_1 )
{
struct V_90 * V_91 ;
int V_44 ;
V_48 -> V_57 = F_1 ( V_1 , V_48 -> V_57 ,
F_31 ( V_17 ) ) ;
if ( F_61 ( V_17 , V_48 , V_58 , V_7 , & V_44 ) )
return V_44 ;
if ( V_1 & V_88 ) {
unsigned long V_49 = F_112 ( V_58 ) ;
return F_58 ( V_48 , V_49 , V_7 ) ;
}
V_91 = F_109 ( V_58 ) ;
if ( F_110 ( ! V_91 || ! V_91 -> V_89 ) )
return - V_50 ;
return F_113 ( V_91 -> V_89 , V_7 , V_48 ) ;
}
static int F_114 ( struct V_16 * V_17 , struct V_60 * V_61 ,
void * V_58 , T_6 V_59 ,
T_3 V_7 , unsigned long V_1 )
{
unsigned int V_92 = F_32 ( V_7 ) >> V_23 ;
struct V_90 * V_91 = F_109 ( V_58 ) ;
if ( V_1 & V_88 ) {
struct V_8 * V_8 = F_107 ( V_58 ) ;
return F_62 ( V_61 , V_8 , V_7 ) ;
}
if ( F_110 ( ! V_91 || ! V_91 -> V_89 ) )
return - V_50 ;
return F_115 ( V_61 , V_91 -> V_89 , V_92 , 0 , V_7 ,
V_62 ) ;
}
static void F_116 ( struct V_16 * V_17 ,
T_6 V_37 , T_3 V_7 ,
enum V_35 V_36 )
{
T_5 V_14 ;
if ( F_31 ( V_17 ) )
return;
V_14 = F_117 ( F_118 ( V_17 ) , V_37 ) ;
F_43 ( F_37 ( V_14 ) , V_7 , V_36 ) ;
}
static void F_119 ( struct V_16 * V_17 ,
T_6 V_37 , T_3 V_7 ,
enum V_35 V_36 )
{
T_5 V_14 ;
if ( F_31 ( V_17 ) )
return;
V_14 = F_117 ( F_118 ( V_17 ) , V_37 ) ;
F_41 ( F_37 ( V_14 ) , V_7 , V_36 ) ;
}
static T_6 F_120 ( struct V_16 * V_17 , struct V_8 * V_8 ,
unsigned long V_34 , T_3 V_7 ,
enum V_35 V_36 ,
unsigned long V_1 )
{
bool V_3 = F_31 ( V_17 ) ;
int V_2 = F_97 ( V_36 , V_3 , V_1 ) ;
T_6 V_37 = F_98 ( V_17 , V_8 , V_34 , V_7 , V_2 ) ;
if ( ! F_99 ( V_17 , V_37 ) &&
( V_1 & V_38 ) == 0 )
F_119 ( V_17 , V_37 , V_7 , V_36 ) ;
return V_37 ;
}
static void F_121 ( struct V_16 * V_17 , T_6 V_37 ,
T_3 V_7 , enum V_35 V_36 ,
unsigned long V_1 )
{
if ( ( V_1 & V_38 ) == 0 )
F_116 ( V_17 , V_37 , V_7 , V_36 ) ;
F_102 ( V_17 , V_37 , V_7 , V_36 , V_1 ) ;
}
static void F_122 ( struct V_16 * V_17 ,
struct V_39 * V_40 , int V_41 ,
enum V_35 V_36 )
{
struct V_39 * V_42 ;
int V_43 ;
if ( F_31 ( V_17 ) )
return;
F_47 (sgl, sg, nelems, i)
F_43 ( F_123 ( V_42 ) , V_42 -> V_46 , V_36 ) ;
}
static void F_124 ( struct V_16 * V_17 ,
struct V_39 * V_40 , int V_41 ,
enum V_35 V_36 )
{
struct V_39 * V_42 ;
int V_43 ;
if ( F_31 ( V_17 ) )
return;
F_47 (sgl, sg, nelems, i)
F_41 ( F_123 ( V_42 ) , V_42 -> V_46 , V_36 ) ;
}
static int F_125 ( struct V_16 * V_17 , struct V_39 * V_40 ,
int V_41 , enum V_35 V_36 ,
unsigned long V_1 )
{
bool V_3 = F_31 ( V_17 ) ;
if ( ( V_1 & V_38 ) == 0 )
F_124 ( V_17 , V_40 , V_41 , V_36 ) ;
return F_126 ( V_17 , V_40 , V_41 ,
F_97 ( V_36 , V_3 , V_1 ) ) ;
}
static void F_127 ( struct V_16 * V_17 ,
struct V_39 * V_40 , int V_41 ,
enum V_35 V_36 ,
unsigned long V_1 )
{
if ( ( V_1 & V_38 ) == 0 )
F_122 ( V_17 , V_40 , V_41 , V_36 ) ;
F_128 ( V_17 , V_40 , V_41 , V_36 , V_1 ) ;
}
static int T_2 F_129 ( void )
{
return F_130 () ;
}
static void F_131 ( struct V_16 * V_17 , T_7 V_93 , T_7 V_7 ,
const struct V_94 * V_95 )
{
struct V_96 * V_97 ;
if ( ! V_95 )
return;
V_97 = F_118 ( V_17 ) ;
if ( ! V_97 )
goto V_98;
if ( V_97 -> type == V_99 ) {
if ( F_132 ( V_97 , V_93 , V_7 , V_17 ) )
goto V_98;
V_17 -> V_100 = & V_101 ;
}
return;
V_98:
F_133 ( L_6 ,
F_134 ( V_17 ) ) ;
}
void F_135 ( struct V_16 * V_17 )
{
V_17 -> V_100 = NULL ;
}
static void F_131 ( struct V_16 * V_17 , T_7 V_93 , T_7 V_7 ,
const struct V_94 * V_102 )
{ }
void F_136 ( struct V_16 * V_17 , T_7 V_93 , T_7 V_7 ,
const struct V_94 * V_102 , bool V_3 )
{
if ( ! V_17 -> V_100 )
V_17 -> V_100 = & V_103 ;
V_17 -> V_104 . V_105 = V_3 ;
F_131 ( V_17 , V_93 , V_7 , V_102 ) ;
#ifdef F_137
if ( F_138 () ) {
V_17 -> V_104 . V_106 = V_17 -> V_100 ;
V_17 -> V_100 = V_107 ;
}
#endif
}
