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
if ( F_17 ( V_23 ) && ( V_11 & V_24 ) ) {
struct V_9 * V_9 ;
void * V_25 ;
V_9 = F_19 ( V_18 , V_8 >> V_26 ,
F_20 ( V_8 ) ) ;
if ( ! V_9 )
return NULL ;
* V_19 = F_21 ( V_18 , F_22 ( V_9 ) ) ;
V_25 = F_23 ( V_9 ) ;
memset ( V_25 , 0 , V_8 ) ;
return V_25 ;
} else {
return F_24 ( V_18 , V_8 , V_19 , V_11 ) ;
}
}
static void F_25 ( struct V_17 * V_18 , T_3 V_8 ,
void * V_27 , T_6 V_19 ,
struct V_1 * V_2 )
{
bool V_28 ;
T_5 V_29 = F_26 ( V_18 , V_19 ) ;
if ( V_18 == NULL ) {
F_16 ( 1 , L_2 ) ;
return;
}
V_28 = F_27 ( V_18 ,
F_10 ( V_29 ) ,
V_8 >> V_26 ) ;
if ( ! V_28 )
F_28 ( V_18 , V_8 , V_27 , V_19 ) ;
}
static void * F_29 ( struct V_17 * V_18 , T_3 V_8 ,
T_6 * V_19 , T_4 V_11 ,
struct V_1 * V_2 )
{
struct V_9 * V_9 ;
void * V_13 , * V_30 ;
bool V_4 = F_30 ( V_18 ) ;
V_8 = F_31 ( V_8 ) ;
if ( ! V_4 && ! ( V_11 & V_24 ) ) {
struct V_9 * V_9 = NULL ;
void * V_25 = F_6 ( V_8 , & V_9 , V_11 ) ;
if ( V_25 )
* V_19 = F_21 ( V_18 , F_22 ( V_9 ) ) ;
return V_25 ;
}
V_13 = F_15 ( V_18 , V_8 , V_19 , V_11 , V_2 ) ;
if ( ! V_13 )
goto V_31;
if ( V_4 )
return V_13 ;
F_32 ( V_13 , V_13 + V_8 ) ;
V_9 = F_33 ( V_13 ) ;
V_30 = F_34 ( V_9 , V_8 , V_32 ,
F_1 ( V_2 ,
F_35 ( V_33 ) , false ) ,
NULL ) ;
if ( ! V_30 )
goto V_34;
return V_30 ;
V_34:
F_25 ( V_18 , V_8 , V_13 , * V_19 , V_2 ) ;
V_31:
* V_19 = V_35 ;
return NULL ;
}
static void F_36 ( struct V_17 * V_18 , T_3 V_8 ,
void * V_27 , T_6 V_19 ,
struct V_1 * V_2 )
{
void * V_36 = F_37 ( F_26 ( V_18 , V_19 ) ) ;
V_8 = F_31 ( V_8 ) ;
if ( ! F_30 ( V_18 ) ) {
if ( F_13 ( V_27 , V_8 ) )
return;
F_38 ( V_27 ) ;
}
F_25 ( V_18 , V_8 , V_36 , V_19 , V_2 ) ;
}
static T_6 F_39 ( struct V_17 * V_18 , struct V_9 * V_9 ,
unsigned long V_37 , T_3 V_8 ,
enum V_38 V_39 ,
struct V_1 * V_2 )
{
T_6 V_40 ;
V_40 = F_40 ( V_18 , V_9 , V_37 , V_8 , V_39 , V_2 ) ;
if ( ! F_30 ( V_18 ) )
F_41 ( F_37 ( F_26 ( V_18 , V_40 ) ) , V_8 , V_39 ) ;
return V_40 ;
}
static void F_42 ( struct V_17 * V_18 , T_6 V_40 ,
T_3 V_8 , enum V_38 V_39 ,
struct V_1 * V_2 )
{
if ( ! F_30 ( V_18 ) )
F_43 ( F_37 ( F_26 ( V_18 , V_40 ) ) , V_8 , V_39 ) ;
F_44 ( V_18 , V_40 , V_8 , V_39 , V_2 ) ;
}
static int F_45 ( struct V_17 * V_18 , struct V_41 * V_42 ,
int V_43 , enum V_38 V_39 ,
struct V_1 * V_2 )
{
struct V_41 * V_44 ;
int V_45 , V_46 ;
V_46 = F_46 ( V_18 , V_42 , V_43 , V_39 , V_2 ) ;
if ( ! F_30 ( V_18 ) )
F_47 (sgl, sg, ret, i)
F_41 ( F_37 ( F_26 ( V_18 , V_44 -> V_47 ) ) ,
V_44 -> V_48 , V_39 ) ;
return V_46 ;
}
static void F_48 ( struct V_17 * V_18 ,
struct V_41 * V_42 , int V_43 ,
enum V_38 V_39 ,
struct V_1 * V_2 )
{
struct V_41 * V_44 ;
int V_45 ;
if ( ! F_30 ( V_18 ) )
F_47 (sgl, sg, nelems, i)
F_43 ( F_37 ( F_26 ( V_18 , V_44 -> V_47 ) ) ,
V_44 -> V_48 , V_39 ) ;
F_49 ( V_18 , V_42 , V_43 , V_39 , V_2 ) ;
}
static void F_50 ( struct V_17 * V_18 ,
T_6 V_40 , T_3 V_8 ,
enum V_38 V_39 )
{
if ( ! F_30 ( V_18 ) )
F_43 ( F_37 ( F_26 ( V_18 , V_40 ) ) , V_8 , V_39 ) ;
F_51 ( V_18 , V_40 , V_8 , V_39 ) ;
}
static void F_52 ( struct V_17 * V_18 ,
T_6 V_40 , T_3 V_8 ,
enum V_38 V_39 )
{
F_53 ( V_18 , V_40 , V_8 , V_39 ) ;
if ( ! F_30 ( V_18 ) )
F_41 ( F_37 ( F_26 ( V_18 , V_40 ) ) , V_8 , V_39 ) ;
}
static void F_54 ( struct V_17 * V_18 ,
struct V_41 * V_42 , int V_43 ,
enum V_38 V_39 )
{
struct V_41 * V_44 ;
int V_45 ;
if ( ! F_30 ( V_18 ) )
F_47 (sgl, sg, nelems, i)
F_43 ( F_37 ( F_26 ( V_18 , V_44 -> V_47 ) ) ,
V_44 -> V_48 , V_39 ) ;
F_55 ( V_18 , V_42 , V_43 , V_39 ) ;
}
static void F_56 ( struct V_17 * V_18 ,
struct V_41 * V_42 , int V_43 ,
enum V_38 V_39 )
{
struct V_41 * V_44 ;
int V_45 ;
F_57 ( V_18 , V_42 , V_43 , V_39 ) ;
if ( ! F_30 ( V_18 ) )
F_47 (sgl, sg, nelems, i)
F_41 ( F_37 ( F_26 ( V_18 , V_44 -> V_47 ) ) ,
V_44 -> V_48 , V_39 ) ;
}
static int F_58 ( struct V_17 * V_18 , struct V_49 * V_50 ,
void * V_51 , T_6 V_52 , T_3 V_8 )
{
int V_46 = - V_53 ;
unsigned long V_54 = ( V_50 -> V_55 - V_50 -> V_56 ) >>
V_26 ;
unsigned long V_57 = F_31 ( V_8 ) >> V_26 ;
unsigned long V_58 = F_26 ( V_18 , V_52 ) >> V_26 ;
unsigned long V_59 = V_50 -> V_60 ;
if ( F_59 ( V_18 , V_50 , V_51 , V_8 , & V_46 ) )
return V_46 ;
if ( V_59 < V_57 && V_54 <= ( V_57 - V_59 ) ) {
V_46 = F_60 ( V_50 , V_50 -> V_56 ,
V_58 + V_59 ,
V_50 -> V_55 - V_50 -> V_56 ,
V_50 -> V_61 ) ;
}
return V_46 ;
}
static int F_61 ( struct V_17 * V_18 ,
struct V_49 * V_50 ,
void * V_51 , T_6 V_52 , T_3 V_8 ,
struct V_1 * V_2 )
{
V_50 -> V_61 = F_1 ( V_2 , V_50 -> V_61 ,
F_30 ( V_18 ) ) ;
return F_58 ( V_18 , V_50 , V_51 , V_52 , V_8 ) ;
}
static int T_2 F_62 ( void )
{
T_1 V_3 = F_35 ( V_33 ) ;
unsigned long V_57 = V_7 >> V_26 ;
struct V_9 * V_9 ;
void * V_25 ;
unsigned int V_62 = F_20 ( V_7 ) ;
if ( F_63 ( NULL ) )
V_9 = F_19 ( NULL , V_57 ,
V_62 ) ;
else
V_9 = F_64 ( V_22 , V_62 ) ;
if ( V_9 ) {
int V_46 ;
void * V_63 = F_23 ( V_9 ) ;
memset ( V_63 , 0 , V_7 ) ;
F_32 ( V_63 , V_63 + V_7 ) ;
V_14 = F_65 ( V_26 , - 1 ) ;
if ( ! V_14 )
goto V_64;
V_25 = F_34 ( V_9 , V_7 ,
V_32 , V_3 , F_62 ) ;
if ( ! V_25 )
goto V_65;
V_46 = F_66 ( V_14 , ( unsigned long ) V_25 ,
F_22 ( V_9 ) ,
V_7 , - 1 ) ;
if ( V_46 )
goto V_66;
F_67 ( V_14 ,
V_67 ,
( void * ) V_26 ) ;
F_68 ( L_3 ,
V_7 / 1024 ) ;
return 0 ;
}
goto V_68;
V_66:
F_69 ( V_25 , V_7 , V_32 ) ;
V_65:
F_70 ( V_14 ) ;
V_14 = NULL ;
V_64:
if ( ! F_27 ( NULL , V_9 , V_57 ) )
F_71 ( V_9 , V_62 ) ;
V_68:
F_72 ( L_4 ,
V_7 / 1024 ) ;
return - V_69 ;
}
static void * F_73 ( struct V_17 * V_18 , T_3 V_8 ,
T_6 * V_19 , T_4 V_11 ,
struct V_1 * V_2 )
{
return NULL ;
}
static void F_74 ( struct V_17 * V_18 , T_3 V_8 ,
void * V_27 , T_6 V_19 ,
struct V_1 * V_2 )
{
}
static int F_75 ( struct V_17 * V_18 ,
struct V_49 * V_50 ,
void * V_51 , T_6 V_52 , T_3 V_8 ,
struct V_1 * V_2 )
{
return - V_53 ;
}
static T_6 F_76 ( struct V_17 * V_18 , struct V_9 * V_9 ,
unsigned long V_37 , T_3 V_8 ,
enum V_38 V_39 ,
struct V_1 * V_2 )
{
return V_35 ;
}
static void F_77 ( struct V_17 * V_18 , T_6 V_40 ,
T_3 V_8 , enum V_38 V_39 ,
struct V_1 * V_2 )
{
}
static int F_78 ( struct V_17 * V_18 , struct V_41 * V_42 ,
int V_43 , enum V_38 V_39 ,
struct V_1 * V_2 )
{
return 0 ;
}
static void F_79 ( struct V_17 * V_18 ,
struct V_41 * V_42 , int V_43 ,
enum V_38 V_39 ,
struct V_1 * V_2 )
{
}
static void F_80 ( struct V_17 * V_18 ,
T_6 V_40 , T_3 V_8 ,
enum V_38 V_39 )
{
}
static void F_81 ( struct V_17 * V_18 ,
struct V_41 * V_42 , int V_43 ,
enum V_38 V_39 )
{
}
static int F_82 ( struct V_17 * V_70 , T_6 V_52 )
{
return 1 ;
}
static int F_83 ( struct V_17 * V_70 , T_7 V_71 )
{
return 0 ;
}
static int T_2 F_84 ( void )
{
int V_46 ;
V_72 = & V_73 ;
V_46 = F_62 () ;
return V_46 ;
}
static int T_2 F_85 ( void )
{
F_86 ( V_74 ) ;
return 0 ;
}
