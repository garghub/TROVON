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
static void * F_6 ( T_3 V_8 , struct V_9 * * V_10 )
{
unsigned long V_11 ;
void * V_12 = NULL ;
if ( ! V_13 ) {
F_7 ( 1 , L_1 ) ;
return NULL ;
}
V_11 = F_8 ( V_13 , V_8 ) ;
if ( V_11 ) {
T_4 V_14 = F_9 ( V_13 , V_11 ) ;
* V_10 = F_10 ( V_14 ) ;
V_12 = ( void * ) V_11 ;
}
return V_12 ;
}
static bool F_11 ( void * V_15 , T_3 V_8 )
{
return F_12 ( V_13 , ( unsigned long ) V_15 , V_8 ) ;
}
static int F_13 ( void * V_15 , T_3 V_8 )
{
if ( ! F_11 ( V_15 , V_8 ) )
return 0 ;
F_14 ( V_13 , ( unsigned long ) V_15 , V_8 ) ;
return 1 ;
}
static void * F_15 ( struct V_16 * V_17 , T_3 V_8 ,
T_5 * V_18 , T_6 V_19 ,
struct V_1 * V_2 )
{
if ( V_17 == NULL ) {
F_16 ( 1 , L_2 ) ;
return NULL ;
}
if ( F_17 ( V_20 ) &&
V_17 -> V_21 <= F_18 ( 32 ) )
V_19 |= V_22 ;
if ( F_17 ( V_23 ) && ( V_19 & V_24 ) ) {
struct V_9 * V_9 ;
V_8 = F_19 ( V_8 ) ;
V_9 = F_20 ( V_17 , V_8 >> V_25 ,
F_21 ( V_8 ) ) ;
if ( ! V_9 )
return NULL ;
* V_18 = F_22 ( V_17 , F_23 ( V_9 ) ) ;
return F_24 ( V_9 ) ;
} else {
return F_25 ( V_17 , V_8 , V_18 , V_19 ) ;
}
}
static void F_26 ( struct V_16 * V_17 , T_3 V_8 ,
void * V_26 , T_5 V_18 ,
struct V_1 * V_2 )
{
bool V_27 ;
T_4 V_28 = F_27 ( V_17 , V_18 ) ;
if ( V_17 == NULL ) {
F_16 ( 1 , L_2 ) ;
return;
}
V_27 = F_28 ( V_17 ,
F_10 ( V_28 ) ,
V_8 >> V_25 ) ;
if ( ! V_27 )
F_29 ( V_17 , V_8 , V_26 , V_18 ) ;
}
static void * F_30 ( struct V_16 * V_17 , T_3 V_8 ,
T_5 * V_18 , T_6 V_19 ,
struct V_1 * V_2 )
{
struct V_9 * V_9 ;
void * V_12 , * V_29 ;
V_8 = F_19 ( V_8 ) ;
if ( ! ( V_19 & V_24 ) ) {
struct V_9 * V_9 = NULL ;
void * V_30 = F_6 ( V_8 , & V_9 ) ;
if ( V_30 )
* V_18 = F_22 ( V_17 , F_23 ( V_9 ) ) ;
return V_30 ;
}
V_12 = F_15 ( V_17 , V_8 , V_18 , V_19 , V_2 ) ;
if ( ! V_12 )
goto V_31;
F_31 ( V_12 , V_12 + V_8 ) ;
V_9 = F_32 ( V_12 ) ;
V_29 = F_33 ( V_9 , V_8 , V_32 ,
F_1 ( V_2 ,
F_34 ( V_33 ) , false ) ,
NULL ) ;
if ( ! V_29 )
goto V_34;
return V_29 ;
V_34:
F_26 ( V_17 , V_8 , V_12 , * V_18 , V_2 ) ;
V_31:
* V_18 = V_35 ;
return NULL ;
}
static void F_35 ( struct V_16 * V_17 , T_3 V_8 ,
void * V_26 , T_5 V_18 ,
struct V_1 * V_2 )
{
void * V_36 = F_36 ( F_27 ( V_17 , V_18 ) ) ;
if ( F_13 ( V_26 , V_8 ) )
return;
F_37 ( V_26 ) ;
F_26 ( V_17 , V_8 , V_36 , V_18 , V_2 ) ;
}
static T_5 F_38 ( struct V_16 * V_17 , struct V_9 * V_9 ,
unsigned long V_37 , T_3 V_8 ,
enum V_38 V_39 ,
struct V_1 * V_2 )
{
T_5 V_40 ;
V_40 = F_39 ( V_17 , V_9 , V_37 , V_8 , V_39 , V_2 ) ;
F_40 ( F_36 ( F_27 ( V_17 , V_40 ) ) , V_8 , V_39 ) ;
return V_40 ;
}
static void F_41 ( struct V_16 * V_17 , T_5 V_40 ,
T_3 V_8 , enum V_38 V_39 ,
struct V_1 * V_2 )
{
F_42 ( F_36 ( F_27 ( V_17 , V_40 ) ) , V_8 , V_39 ) ;
F_43 ( V_17 , V_40 , V_8 , V_39 , V_2 ) ;
}
static int F_44 ( struct V_16 * V_17 , struct V_41 * V_42 ,
int V_43 , enum V_38 V_39 ,
struct V_1 * V_2 )
{
struct V_41 * V_44 ;
int V_45 , V_46 ;
V_46 = F_45 ( V_17 , V_42 , V_43 , V_39 , V_2 ) ;
F_46 (sgl, sg, ret, i)
F_40 ( F_36 ( F_27 ( V_17 , V_44 -> V_47 ) ) ,
V_44 -> V_48 , V_39 ) ;
return V_46 ;
}
static void F_47 ( struct V_16 * V_17 ,
struct V_41 * V_42 , int V_43 ,
enum V_38 V_39 ,
struct V_1 * V_2 )
{
struct V_41 * V_44 ;
int V_45 ;
F_46 (sgl, sg, nelems, i)
F_42 ( F_36 ( F_27 ( V_17 , V_44 -> V_47 ) ) ,
V_44 -> V_48 , V_39 ) ;
F_48 ( V_17 , V_42 , V_43 , V_39 , V_2 ) ;
}
static void F_49 ( struct V_16 * V_17 ,
T_5 V_40 , T_3 V_8 ,
enum V_38 V_39 )
{
F_42 ( F_36 ( F_27 ( V_17 , V_40 ) ) , V_8 , V_39 ) ;
F_50 ( V_17 , V_40 , V_8 , V_39 ) ;
}
static void F_51 ( struct V_16 * V_17 ,
T_5 V_40 , T_3 V_8 ,
enum V_38 V_39 )
{
F_52 ( V_17 , V_40 , V_8 , V_39 ) ;
F_40 ( F_36 ( F_27 ( V_17 , V_40 ) ) , V_8 , V_39 ) ;
}
static void F_53 ( struct V_16 * V_17 ,
struct V_41 * V_42 , int V_43 ,
enum V_38 V_39 )
{
struct V_41 * V_44 ;
int V_45 ;
F_46 (sgl, sg, nelems, i)
F_42 ( F_36 ( F_27 ( V_17 , V_44 -> V_47 ) ) ,
V_44 -> V_48 , V_39 ) ;
F_54 ( V_17 , V_42 , V_43 , V_39 ) ;
}
static void F_55 ( struct V_16 * V_17 ,
struct V_41 * V_42 , int V_43 ,
enum V_38 V_39 )
{
struct V_41 * V_44 ;
int V_45 ;
F_56 ( V_17 , V_42 , V_43 , V_39 ) ;
F_46 (sgl, sg, nelems, i)
F_40 ( F_36 ( F_27 ( V_17 , V_44 -> V_47 ) ) ,
V_44 -> V_48 , V_39 ) ;
}
static int F_57 ( struct V_16 * V_17 , struct V_49 * V_50 ,
void * V_51 , T_5 V_52 , T_3 V_8 )
{
int V_46 = - V_53 ;
unsigned long V_54 = ( V_50 -> V_55 - V_50 -> V_56 ) >>
V_25 ;
unsigned long V_57 = F_19 ( V_8 ) >> V_25 ;
unsigned long V_58 = F_27 ( V_17 , V_52 ) >> V_25 ;
unsigned long V_59 = V_50 -> V_60 ;
if ( F_58 ( V_17 , V_50 , V_51 , V_8 , & V_46 ) )
return V_46 ;
if ( V_59 < V_57 && V_54 <= ( V_57 - V_59 ) ) {
V_46 = F_59 ( V_50 , V_50 -> V_56 ,
V_58 + V_59 ,
V_50 -> V_55 - V_50 -> V_56 ,
V_50 -> V_61 ) ;
}
return V_46 ;
}
static int F_60 ( struct V_16 * V_17 ,
struct V_49 * V_50 ,
void * V_51 , T_5 V_52 , T_3 V_8 ,
struct V_1 * V_2 )
{
V_50 -> V_61 = F_1 ( V_2 , V_50 -> V_61 , false ) ;
return F_57 ( V_17 , V_50 , V_51 , V_52 , V_8 ) ;
}
static int F_61 ( struct V_16 * V_17 ,
struct V_49 * V_50 ,
void * V_51 , T_5 V_52 , T_3 V_8 ,
struct V_1 * V_2 )
{
return F_57 ( V_17 , V_50 , V_51 , V_52 , V_8 ) ;
}
static int T_2 F_62 ( void )
{
T_1 V_3 = F_34 ( V_33 ) ;
unsigned long V_57 = V_7 >> V_25 ;
struct V_9 * V_9 ;
void * V_30 ;
unsigned int V_62 = F_21 ( V_7 ) ;
if ( F_63 ( NULL ) )
V_9 = F_20 ( NULL , V_57 ,
V_62 ) ;
else
V_9 = F_64 ( V_22 , V_62 ) ;
if ( V_9 ) {
int V_46 ;
void * V_63 = F_24 ( V_9 ) ;
memset ( V_63 , 0 , V_7 ) ;
F_31 ( V_63 , V_63 + V_7 ) ;
V_13 = F_65 ( V_25 , - 1 ) ;
if ( ! V_13 )
goto V_64;
V_30 = F_33 ( V_9 , V_7 ,
V_32 , V_3 , F_62 ) ;
if ( ! V_30 )
goto V_65;
V_46 = F_66 ( V_13 , ( unsigned long ) V_30 ,
F_23 ( V_9 ) ,
V_7 , - 1 ) ;
if ( V_46 )
goto V_66;
F_67 ( V_13 ,
V_67 ,
( void * ) V_25 ) ;
F_68 ( L_3 ,
V_7 / 1024 ) ;
return 0 ;
}
goto V_68;
V_66:
F_69 ( V_30 , V_7 , V_32 ) ;
V_65:
F_70 ( V_13 ) ;
V_13 = NULL ;
V_64:
if ( ! F_28 ( NULL , V_9 , V_57 ) )
F_71 ( V_9 , V_62 ) ;
V_68:
F_72 ( L_4 ,
V_7 / 1024 ) ;
return - V_69 ;
}
static int T_2 F_73 ( void )
{
T_3 V_70 = F_74 ( V_71 , V_72 << V_25 ) ;
V_73 = & V_74 ;
return F_75 ( V_70 ) ;
}
static int T_2 F_76 ( void )
{
int V_46 = 0 ;
V_46 |= F_73 () ;
V_46 |= F_62 () ;
return V_46 ;
}
static int T_2 F_77 ( void )
{
F_78 ( V_75 ) ;
return 0 ;
}
