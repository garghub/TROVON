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
if ( V_11 & V_16 )
memset ( V_13 , 0 , V_8 ) ;
}
return V_13 ;
}
static bool F_11 ( void * V_17 , T_3 V_8 )
{
return F_12 ( V_14 , ( unsigned long ) V_17 , V_8 ) ;
}
static int F_13 ( void * V_17 , T_3 V_8 )
{
if ( ! F_11 ( V_17 , V_8 ) )
return 0 ;
F_14 ( V_14 , ( unsigned long ) V_17 , V_8 ) ;
return 1 ;
}
static void * F_15 ( struct V_18 * V_19 , T_3 V_8 ,
T_6 * V_20 , T_4 V_11 ,
struct V_1 * V_2 )
{
if ( V_19 == NULL ) {
F_16 ( 1 , L_2 ) ;
return NULL ;
}
if ( F_17 ( V_21 ) &&
V_19 -> V_22 <= F_18 ( 32 ) )
V_11 |= V_23 ;
if ( F_17 ( V_24 ) && ( V_11 & V_25 ) ) {
struct V_9 * V_9 ;
void * V_26 ;
V_8 = F_19 ( V_8 ) ;
V_9 = F_20 ( V_19 , V_8 >> V_27 ,
F_21 ( V_8 ) ) ;
if ( ! V_9 )
return NULL ;
* V_20 = F_22 ( V_19 , F_23 ( V_9 ) ) ;
V_26 = F_24 ( V_9 ) ;
if ( V_11 & V_16 )
memset ( V_26 , 0 , V_8 ) ;
return V_26 ;
} else {
return F_25 ( V_19 , V_8 , V_20 , V_11 ) ;
}
}
static void F_26 ( struct V_18 * V_19 , T_3 V_8 ,
void * V_28 , T_6 V_20 ,
struct V_1 * V_2 )
{
bool V_29 ;
T_5 V_30 = F_27 ( V_19 , V_20 ) ;
if ( V_19 == NULL ) {
F_16 ( 1 , L_2 ) ;
return;
}
V_29 = F_28 ( V_19 ,
F_10 ( V_30 ) ,
V_8 >> V_27 ) ;
if ( ! V_29 )
F_29 ( V_19 , V_8 , V_28 , V_20 ) ;
}
static void * F_30 ( struct V_18 * V_19 , T_3 V_8 ,
T_6 * V_20 , T_4 V_11 ,
struct V_1 * V_2 )
{
struct V_9 * V_9 ;
void * V_13 , * V_31 ;
bool V_4 = F_31 ( V_19 ) ;
V_8 = F_19 ( V_8 ) ;
if ( ! V_4 && ! ( V_11 & V_25 ) ) {
struct V_9 * V_9 = NULL ;
void * V_26 = F_6 ( V_8 , & V_9 , V_11 ) ;
if ( V_26 )
* V_20 = F_22 ( V_19 , F_23 ( V_9 ) ) ;
return V_26 ;
}
V_13 = F_15 ( V_19 , V_8 , V_20 , V_11 , V_2 ) ;
if ( ! V_13 )
goto V_32;
if ( V_4 )
return V_13 ;
F_32 ( V_13 , V_13 + V_8 ) ;
V_9 = F_33 ( V_13 ) ;
V_31 = F_34 ( V_9 , V_8 , V_33 ,
F_1 ( V_2 ,
F_35 ( V_34 ) , false ) ,
NULL ) ;
if ( ! V_31 )
goto V_35;
return V_31 ;
V_35:
F_26 ( V_19 , V_8 , V_13 , * V_20 , V_2 ) ;
V_32:
* V_20 = V_36 ;
return NULL ;
}
static void F_36 ( struct V_18 * V_19 , T_3 V_8 ,
void * V_28 , T_6 V_20 ,
struct V_1 * V_2 )
{
void * V_37 = F_37 ( F_27 ( V_19 , V_20 ) ) ;
if ( ! F_31 ( V_19 ) ) {
if ( F_13 ( V_28 , V_8 ) )
return;
F_38 ( V_28 ) ;
}
F_26 ( V_19 , V_8 , V_37 , V_20 , V_2 ) ;
}
static T_6 F_39 ( struct V_18 * V_19 , struct V_9 * V_9 ,
unsigned long V_38 , T_3 V_8 ,
enum V_39 V_40 ,
struct V_1 * V_2 )
{
T_6 V_41 ;
V_41 = F_40 ( V_19 , V_9 , V_38 , V_8 , V_40 , V_2 ) ;
if ( ! F_31 ( V_19 ) )
F_41 ( F_37 ( F_27 ( V_19 , V_41 ) ) , V_8 , V_40 ) ;
return V_41 ;
}
static void F_42 ( struct V_18 * V_19 , T_6 V_41 ,
T_3 V_8 , enum V_39 V_40 ,
struct V_1 * V_2 )
{
if ( ! F_31 ( V_19 ) )
F_43 ( F_37 ( F_27 ( V_19 , V_41 ) ) , V_8 , V_40 ) ;
F_44 ( V_19 , V_41 , V_8 , V_40 , V_2 ) ;
}
static int F_45 ( struct V_18 * V_19 , struct V_42 * V_43 ,
int V_44 , enum V_39 V_40 ,
struct V_1 * V_2 )
{
struct V_42 * V_45 ;
int V_46 , V_47 ;
V_47 = F_46 ( V_19 , V_43 , V_44 , V_40 , V_2 ) ;
if ( ! F_31 ( V_19 ) )
F_47 (sgl, sg, ret, i)
F_41 ( F_37 ( F_27 ( V_19 , V_45 -> V_48 ) ) ,
V_45 -> V_49 , V_40 ) ;
return V_47 ;
}
static void F_48 ( struct V_18 * V_19 ,
struct V_42 * V_43 , int V_44 ,
enum V_39 V_40 ,
struct V_1 * V_2 )
{
struct V_42 * V_45 ;
int V_46 ;
if ( ! F_31 ( V_19 ) )
F_47 (sgl, sg, nelems, i)
F_43 ( F_37 ( F_27 ( V_19 , V_45 -> V_48 ) ) ,
V_45 -> V_49 , V_40 ) ;
F_49 ( V_19 , V_43 , V_44 , V_40 , V_2 ) ;
}
static void F_50 ( struct V_18 * V_19 ,
T_6 V_41 , T_3 V_8 ,
enum V_39 V_40 )
{
if ( ! F_31 ( V_19 ) )
F_43 ( F_37 ( F_27 ( V_19 , V_41 ) ) , V_8 , V_40 ) ;
F_51 ( V_19 , V_41 , V_8 , V_40 ) ;
}
static void F_52 ( struct V_18 * V_19 ,
T_6 V_41 , T_3 V_8 ,
enum V_39 V_40 )
{
F_53 ( V_19 , V_41 , V_8 , V_40 ) ;
if ( ! F_31 ( V_19 ) )
F_41 ( F_37 ( F_27 ( V_19 , V_41 ) ) , V_8 , V_40 ) ;
}
static void F_54 ( struct V_18 * V_19 ,
struct V_42 * V_43 , int V_44 ,
enum V_39 V_40 )
{
struct V_42 * V_45 ;
int V_46 ;
if ( ! F_31 ( V_19 ) )
F_47 (sgl, sg, nelems, i)
F_43 ( F_37 ( F_27 ( V_19 , V_45 -> V_48 ) ) ,
V_45 -> V_49 , V_40 ) ;
F_55 ( V_19 , V_43 , V_44 , V_40 ) ;
}
static void F_56 ( struct V_18 * V_19 ,
struct V_42 * V_43 , int V_44 ,
enum V_39 V_40 )
{
struct V_42 * V_45 ;
int V_46 ;
F_57 ( V_19 , V_43 , V_44 , V_40 ) ;
if ( ! F_31 ( V_19 ) )
F_47 (sgl, sg, nelems, i)
F_41 ( F_37 ( F_27 ( V_19 , V_45 -> V_48 ) ) ,
V_45 -> V_49 , V_40 ) ;
}
static int F_58 ( struct V_18 * V_19 , struct V_50 * V_51 ,
void * V_52 , T_6 V_53 , T_3 V_8 )
{
int V_47 = - V_54 ;
unsigned long V_55 = ( V_51 -> V_56 - V_51 -> V_57 ) >>
V_27 ;
unsigned long V_58 = F_19 ( V_8 ) >> V_27 ;
unsigned long V_59 = F_27 ( V_19 , V_53 ) >> V_27 ;
unsigned long V_60 = V_51 -> V_61 ;
if ( F_59 ( V_19 , V_51 , V_52 , V_8 , & V_47 ) )
return V_47 ;
if ( V_60 < V_58 && V_55 <= ( V_58 - V_60 ) ) {
V_47 = F_60 ( V_51 , V_51 -> V_57 ,
V_59 + V_60 ,
V_51 -> V_56 - V_51 -> V_57 ,
V_51 -> V_62 ) ;
}
return V_47 ;
}
static int F_61 ( struct V_18 * V_19 ,
struct V_50 * V_51 ,
void * V_52 , T_6 V_53 , T_3 V_8 ,
struct V_1 * V_2 )
{
V_51 -> V_62 = F_1 ( V_2 , V_51 -> V_62 ,
F_31 ( V_19 ) ) ;
return F_58 ( V_19 , V_51 , V_52 , V_53 , V_8 ) ;
}
static int T_2 F_62 ( void )
{
T_1 V_3 = F_35 ( V_34 ) ;
unsigned long V_58 = V_7 >> V_27 ;
struct V_9 * V_9 ;
void * V_26 ;
unsigned int V_63 = F_21 ( V_7 ) ;
if ( F_63 ( NULL ) )
V_9 = F_20 ( NULL , V_58 ,
V_63 ) ;
else
V_9 = F_64 ( V_23 , V_63 ) ;
if ( V_9 ) {
int V_47 ;
void * V_64 = F_24 ( V_9 ) ;
memset ( V_64 , 0 , V_7 ) ;
F_32 ( V_64 , V_64 + V_7 ) ;
V_14 = F_65 ( V_27 , - 1 ) ;
if ( ! V_14 )
goto V_65;
V_26 = F_34 ( V_9 , V_7 ,
V_33 , V_3 , F_62 ) ;
if ( ! V_26 )
goto V_66;
V_47 = F_66 ( V_14 , ( unsigned long ) V_26 ,
F_23 ( V_9 ) ,
V_7 , - 1 ) ;
if ( V_47 )
goto V_67;
F_67 ( V_14 ,
V_68 ,
( void * ) V_27 ) ;
F_68 ( L_3 ,
V_7 / 1024 ) ;
return 0 ;
}
goto V_69;
V_67:
F_69 ( V_26 , V_7 , V_33 ) ;
V_66:
F_70 ( V_14 ) ;
V_14 = NULL ;
V_65:
if ( ! F_28 ( NULL , V_9 , V_58 ) )
F_71 ( V_9 , V_63 ) ;
V_69:
F_72 ( L_4 ,
V_7 / 1024 ) ;
return - V_70 ;
}
static int T_2 F_73 ( void )
{
int V_47 ;
V_71 = & V_72 ;
V_47 = F_62 () ;
return V_47 ;
}
static int T_2 F_74 ( void )
{
F_75 ( V_73 ) ;
return 0 ;
}
