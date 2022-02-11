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
if ( F_19 ( V_18 ) && ( V_11 & V_23 ) ) {
struct V_9 * V_9 ;
void * V_24 ;
V_9 = F_20 ( V_18 , V_8 >> V_25 ,
F_21 ( V_8 ) ) ;
if ( ! V_9 )
return NULL ;
* V_19 = F_22 ( V_18 , F_23 ( V_9 ) ) ;
V_24 = F_24 ( V_9 ) ;
memset ( V_24 , 0 , V_8 ) ;
return V_24 ;
} else {
return F_25 ( V_18 , V_8 , V_19 , V_11 ) ;
}
}
static void F_26 ( struct V_17 * V_18 , T_3 V_8 ,
void * V_26 , T_6 V_19 ,
struct V_1 * V_2 )
{
bool V_27 ;
T_5 V_28 = F_27 ( V_18 , V_19 ) ;
if ( V_18 == NULL ) {
F_16 ( 1 , L_2 ) ;
return;
}
V_27 = F_28 ( V_18 ,
F_10 ( V_28 ) ,
V_8 >> V_25 ) ;
if ( ! V_27 )
F_29 ( V_18 , V_8 , V_26 , V_19 ) ;
}
static void * F_30 ( struct V_17 * V_18 , T_3 V_8 ,
T_6 * V_19 , T_4 V_11 ,
struct V_1 * V_2 )
{
struct V_9 * V_9 ;
void * V_13 , * V_29 ;
bool V_4 = F_31 ( V_18 ) ;
T_1 V_3 = F_1 ( V_2 , V_30 , false ) ;
V_8 = F_32 ( V_8 ) ;
if ( ! V_4 && ! ( V_11 & V_23 ) ) {
struct V_9 * V_9 = NULL ;
void * V_24 = F_6 ( V_8 , & V_9 , V_11 ) ;
if ( V_24 )
* V_19 = F_22 ( V_18 , F_23 ( V_9 ) ) ;
return V_24 ;
}
V_13 = F_15 ( V_18 , V_8 , V_19 , V_11 , V_2 ) ;
if ( ! V_13 )
goto V_31;
if ( V_4 )
return V_13 ;
F_33 ( V_13 , V_13 + V_8 ) ;
V_9 = F_34 ( V_13 ) ;
V_29 = F_35 ( V_9 , V_8 , V_32 ,
V_3 , NULL ) ;
if ( ! V_29 )
goto V_33;
return V_29 ;
V_33:
F_26 ( V_18 , V_8 , V_13 , * V_19 , V_2 ) ;
V_31:
* V_19 = V_34 ;
return NULL ;
}
static void F_36 ( struct V_17 * V_18 , T_3 V_8 ,
void * V_26 , T_6 V_19 ,
struct V_1 * V_2 )
{
void * V_35 = F_37 ( F_27 ( V_18 , V_19 ) ) ;
V_8 = F_32 ( V_8 ) ;
if ( ! F_31 ( V_18 ) ) {
if ( F_13 ( V_26 , V_8 ) )
return;
F_38 ( V_26 ) ;
}
F_26 ( V_18 , V_8 , V_35 , V_19 , V_2 ) ;
}
static T_6 F_39 ( struct V_17 * V_18 , struct V_9 * V_9 ,
unsigned long V_36 , T_3 V_8 ,
enum V_37 V_38 ,
struct V_1 * V_2 )
{
T_6 V_39 ;
V_39 = F_40 ( V_18 , V_9 , V_36 , V_8 , V_38 , V_2 ) ;
if ( ! F_31 ( V_18 ) )
F_41 ( F_37 ( F_27 ( V_18 , V_39 ) ) , V_8 , V_38 ) ;
return V_39 ;
}
static void F_42 ( struct V_17 * V_18 , T_6 V_39 ,
T_3 V_8 , enum V_37 V_38 ,
struct V_1 * V_2 )
{
if ( ! F_31 ( V_18 ) )
F_43 ( F_37 ( F_27 ( V_18 , V_39 ) ) , V_8 , V_38 ) ;
F_44 ( V_18 , V_39 , V_8 , V_38 , V_2 ) ;
}
static int F_45 ( struct V_17 * V_18 , struct V_40 * V_41 ,
int V_42 , enum V_37 V_38 ,
struct V_1 * V_2 )
{
struct V_40 * V_43 ;
int V_44 , V_45 ;
V_45 = F_46 ( V_18 , V_41 , V_42 , V_38 , V_2 ) ;
if ( ! F_31 ( V_18 ) )
F_47 (sgl, sg, ret, i)
F_41 ( F_37 ( F_27 ( V_18 , V_43 -> V_46 ) ) ,
V_43 -> V_47 , V_38 ) ;
return V_45 ;
}
static void F_48 ( struct V_17 * V_18 ,
struct V_40 * V_41 , int V_42 ,
enum V_37 V_38 ,
struct V_1 * V_2 )
{
struct V_40 * V_43 ;
int V_44 ;
if ( ! F_31 ( V_18 ) )
F_47 (sgl, sg, nelems, i)
F_43 ( F_37 ( F_27 ( V_18 , V_43 -> V_46 ) ) ,
V_43 -> V_47 , V_38 ) ;
F_49 ( V_18 , V_41 , V_42 , V_38 , V_2 ) ;
}
static void F_50 ( struct V_17 * V_18 ,
T_6 V_39 , T_3 V_8 ,
enum V_37 V_38 )
{
if ( ! F_31 ( V_18 ) )
F_43 ( F_37 ( F_27 ( V_18 , V_39 ) ) , V_8 , V_38 ) ;
F_51 ( V_18 , V_39 , V_8 , V_38 ) ;
}
static void F_52 ( struct V_17 * V_18 ,
T_6 V_39 , T_3 V_8 ,
enum V_37 V_38 )
{
F_53 ( V_18 , V_39 , V_8 , V_38 ) ;
if ( ! F_31 ( V_18 ) )
F_41 ( F_37 ( F_27 ( V_18 , V_39 ) ) , V_8 , V_38 ) ;
}
static void F_54 ( struct V_17 * V_18 ,
struct V_40 * V_41 , int V_42 ,
enum V_37 V_38 )
{
struct V_40 * V_43 ;
int V_44 ;
if ( ! F_31 ( V_18 ) )
F_47 (sgl, sg, nelems, i)
F_43 ( F_37 ( F_27 ( V_18 , V_43 -> V_46 ) ) ,
V_43 -> V_47 , V_38 ) ;
F_55 ( V_18 , V_41 , V_42 , V_38 ) ;
}
static void F_56 ( struct V_17 * V_18 ,
struct V_40 * V_41 , int V_42 ,
enum V_37 V_38 )
{
struct V_40 * V_43 ;
int V_44 ;
F_57 ( V_18 , V_41 , V_42 , V_38 ) ;
if ( ! F_31 ( V_18 ) )
F_47 (sgl, sg, nelems, i)
F_41 ( F_37 ( F_27 ( V_18 , V_43 -> V_46 ) ) ,
V_43 -> V_47 , V_38 ) ;
}
static int F_58 ( struct V_17 * V_18 ,
struct V_48 * V_49 ,
void * V_50 , T_6 V_51 , T_3 V_8 ,
struct V_1 * V_2 )
{
int V_45 = - V_52 ;
unsigned long V_53 = ( V_49 -> V_54 - V_49 -> V_55 ) >>
V_25 ;
unsigned long V_56 = F_32 ( V_8 ) >> V_25 ;
unsigned long V_57 = F_27 ( V_18 , V_51 ) >> V_25 ;
unsigned long V_58 = V_49 -> V_59 ;
V_49 -> V_60 = F_1 ( V_2 , V_49 -> V_60 ,
F_31 ( V_18 ) ) ;
if ( F_59 ( V_18 , V_49 , V_50 , V_8 , & V_45 ) )
return V_45 ;
if ( V_58 < V_56 && V_53 <= ( V_56 - V_58 ) ) {
V_45 = F_60 ( V_49 , V_49 -> V_55 ,
V_57 + V_58 ,
V_49 -> V_54 - V_49 -> V_55 ,
V_49 -> V_60 ) ;
}
return V_45 ;
}
static int F_61 ( struct V_17 * V_18 , struct V_61 * V_62 ,
void * V_50 , T_6 V_63 , T_3 V_8 ,
struct V_1 * V_2 )
{
int V_45 = F_62 ( V_62 , 1 , V_64 ) ;
if ( ! V_45 )
F_63 ( V_62 -> V_41 , F_10 ( F_27 ( V_18 , V_63 ) ) ,
F_32 ( V_8 ) , 0 ) ;
return V_45 ;
}
static int T_2 F_64 ( void )
{
T_1 V_3 = F_65 ( V_65 ) ;
unsigned long V_56 = V_7 >> V_25 ;
struct V_9 * V_9 ;
void * V_24 ;
unsigned int V_66 = F_21 ( V_7 ) ;
if ( F_19 ( NULL ) )
V_9 = F_20 ( NULL , V_56 ,
V_66 ) ;
else
V_9 = F_66 ( V_22 , V_66 ) ;
if ( V_9 ) {
int V_45 ;
void * V_67 = F_24 ( V_9 ) ;
memset ( V_67 , 0 , V_7 ) ;
F_33 ( V_67 , V_67 + V_7 ) ;
V_14 = F_67 ( V_25 , - 1 ) ;
if ( ! V_14 )
goto V_68;
V_24 = F_35 ( V_9 , V_7 ,
V_32 , V_3 , F_64 ) ;
if ( ! V_24 )
goto V_69;
V_45 = F_68 ( V_14 , ( unsigned long ) V_24 ,
F_23 ( V_9 ) ,
V_7 , - 1 ) ;
if ( V_45 )
goto V_70;
F_69 ( V_14 ,
V_71 ,
( void * ) V_25 ) ;
F_70 ( L_3 ,
V_7 / 1024 ) ;
return 0 ;
}
goto V_72;
V_70:
F_71 ( V_24 , V_7 , V_32 ) ;
V_69:
F_72 ( V_14 ) ;
V_14 = NULL ;
V_68:
if ( ! F_28 ( NULL , V_9 , V_56 ) )
F_73 ( V_9 , V_66 ) ;
V_72:
F_74 ( L_4 ,
V_7 / 1024 ) ;
return - V_73 ;
}
static void * F_75 ( struct V_17 * V_18 , T_3 V_8 ,
T_6 * V_19 , T_4 V_11 ,
struct V_1 * V_2 )
{
return NULL ;
}
static void F_76 ( struct V_17 * V_18 , T_3 V_8 ,
void * V_26 , T_6 V_19 ,
struct V_1 * V_2 )
{
}
static int F_77 ( struct V_17 * V_18 ,
struct V_48 * V_49 ,
void * V_50 , T_6 V_51 , T_3 V_8 ,
struct V_1 * V_2 )
{
return - V_52 ;
}
static T_6 F_78 ( struct V_17 * V_18 , struct V_9 * V_9 ,
unsigned long V_36 , T_3 V_8 ,
enum V_37 V_38 ,
struct V_1 * V_2 )
{
return V_34 ;
}
static void F_79 ( struct V_17 * V_18 , T_6 V_39 ,
T_3 V_8 , enum V_37 V_38 ,
struct V_1 * V_2 )
{
}
static int F_80 ( struct V_17 * V_18 , struct V_40 * V_41 ,
int V_42 , enum V_37 V_38 ,
struct V_1 * V_2 )
{
return 0 ;
}
static void F_81 ( struct V_17 * V_18 ,
struct V_40 * V_41 , int V_42 ,
enum V_37 V_38 ,
struct V_1 * V_2 )
{
}
static void F_82 ( struct V_17 * V_18 ,
T_6 V_39 , T_3 V_8 ,
enum V_37 V_38 )
{
}
static void F_83 ( struct V_17 * V_18 ,
struct V_40 * V_41 , int V_42 ,
enum V_37 V_38 )
{
}
static int F_84 ( struct V_17 * V_74 , T_6 V_51 )
{
return 1 ;
}
static int F_85 ( struct V_17 * V_74 , T_7 V_75 )
{
return 0 ;
}
static int T_2 F_86 ( void )
{
int V_45 ;
V_76 = & V_77 ;
V_45 = F_64 () ;
return V_45 ;
}
static int T_2 F_87 ( void )
{
F_88 ( V_78 ) ;
return 0 ;
}
