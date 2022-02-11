static bool F_1 ( struct V_1 * V_2 , T_1 time )
{
T_2 V_3 ;
if ( V_2 -> V_4 )
return false ;
if ( F_2 ( V_2 -> V_5 ) ) {
V_2 -> V_5 = false ;
V_2 -> V_6 = V_7 ;
return true ;
}
V_3 = time - V_2 -> V_8 ;
return V_3 >= V_2 -> V_9 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 time ,
unsigned int V_6 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_2 -> V_6 == V_6 )
return;
V_2 -> V_6 = V_6 ;
V_2 -> V_8 = time ;
if ( V_11 -> V_12 ) {
V_6 = F_4 ( V_11 , V_6 ) ;
if ( V_6 == V_13 )
return;
V_11 -> V_14 = V_6 ;
F_5 ( V_6 , F_6 () ) ;
} else {
V_2 -> V_4 = true ;
F_7 ( & V_2 -> V_15 ) ;
}
}
static unsigned int F_8 ( struct V_1 * V_2 ,
unsigned long V_16 , unsigned long V_17 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_18 = F_9 () ?
V_11 -> V_19 . V_20 : V_11 -> V_14 ;
V_18 = ( V_18 + ( V_18 >> 2 ) ) * V_16 / V_17 ;
if ( V_18 == V_2 -> V_21 && V_2 -> V_6 != V_7 )
return V_2 -> V_6 ;
V_2 -> V_21 = V_18 ;
return F_10 ( V_11 , V_18 ) ;
}
static void F_11 ( unsigned long * V_16 , unsigned long * V_17 )
{
struct V_22 * V_22 = F_12 () ;
unsigned long V_23 ;
V_23 = F_13 ( NULL , F_6 () ) ;
* V_16 = F_14 ( V_22 -> V_24 . V_25 . V_26 , V_23 ) ;
* V_17 = V_23 ;
}
static void F_15 ( struct V_27 * V_28 , T_1 time ,
unsigned int V_29 )
{
if ( V_29 & V_30 ) {
V_28 -> V_31 = V_28 -> V_32 ;
} else if ( V_28 -> V_31 ) {
T_2 V_3 = time - V_28 -> V_33 ;
if ( V_3 > V_34 )
V_28 -> V_31 = 0 ;
}
}
static void F_16 ( struct V_27 * V_28 , unsigned long * V_16 ,
unsigned long * V_17 )
{
unsigned long V_35 = V_28 -> V_31 ;
unsigned long V_36 = V_28 -> V_32 ;
if ( ! V_35 )
return;
if ( * V_16 * V_36 < * V_17 * V_35 ) {
* V_16 = V_35 ;
* V_17 = V_36 ;
}
V_28 -> V_31 >>= 1 ;
}
static bool F_17 ( struct V_27 * V_28 )
{
unsigned long V_37 = F_18 () ;
bool V_38 = V_37 == V_28 -> V_39 ;
V_28 -> V_39 = V_37 ;
return V_38 ;
}
static inline bool F_17 ( struct V_27 * V_28 ) { return false ; }
static void F_19 ( struct V_40 * V_41 , T_1 time ,
unsigned int V_29 )
{
struct V_27 * V_28 = F_20 ( V_41 , struct V_27 , V_42 ) ;
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_16 , V_17 ;
unsigned int V_43 ;
bool V_44 ;
F_15 ( V_28 , time , V_29 ) ;
V_28 -> V_33 = time ;
if ( ! F_1 ( V_2 , time ) )
return;
V_44 = F_17 ( V_28 ) ;
if ( V_29 & V_45 ) {
V_43 = V_11 -> V_19 . V_20 ;
} else {
F_11 ( & V_16 , & V_17 ) ;
F_16 ( V_28 , & V_16 , & V_17 ) ;
V_43 = F_8 ( V_2 , V_16 , V_17 ) ;
if ( V_44 && V_43 < V_2 -> V_6 )
V_43 = V_2 -> V_6 ;
}
F_3 ( V_2 , time , V_43 ) ;
}
static unsigned int F_21 ( struct V_27 * V_28 , T_1 time )
{
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_16 = 0 , V_17 = 1 ;
unsigned int V_46 ;
F_22 (j, policy->cpus) {
struct V_27 * V_47 = & F_23 ( V_27 , V_46 ) ;
unsigned long V_48 , V_49 ;
T_2 V_3 ;
V_3 = time - V_47 -> V_33 ;
if ( V_3 > V_34 ) {
V_47 -> V_31 = 0 ;
continue;
}
if ( V_47 -> V_29 & V_45 )
return V_11 -> V_19 . V_20 ;
V_48 = V_47 -> V_16 ;
V_49 = V_47 -> V_17 ;
if ( V_48 * V_17 > V_49 * V_16 ) {
V_16 = V_48 ;
V_17 = V_49 ;
}
F_16 ( V_47 , & V_16 , & V_17 ) ;
}
return F_8 ( V_2 , V_16 , V_17 ) ;
}
static void F_24 ( struct V_40 * V_41 , T_1 time ,
unsigned int V_29 )
{
struct V_27 * V_28 = F_20 ( V_41 , struct V_27 , V_42 ) ;
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned long V_16 , V_17 ;
unsigned int V_43 ;
F_11 ( & V_16 , & V_17 ) ;
F_25 ( & V_2 -> V_50 ) ;
V_28 -> V_16 = V_16 ;
V_28 -> V_17 = V_17 ;
V_28 -> V_29 = V_29 ;
F_15 ( V_28 , time , V_29 ) ;
V_28 -> V_33 = time ;
if ( F_1 ( V_2 , time ) ) {
if ( V_29 & V_45 )
V_43 = V_2 -> V_11 -> V_19 . V_20 ;
else
V_43 = F_21 ( V_28 , time ) ;
F_3 ( V_2 , time , V_43 ) ;
}
F_26 ( & V_2 -> V_50 ) ;
}
static void F_27 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_20 ( V_52 , struct V_1 , V_52 ) ;
F_28 ( & V_2 -> V_53 ) ;
F_29 ( V_2 -> V_11 , V_2 -> V_6 ,
V_54 ) ;
F_30 ( & V_2 -> V_53 ) ;
V_2 -> V_4 = false ;
}
static void F_31 ( struct V_15 * V_15 )
{
struct V_1 * V_2 ;
V_2 = F_20 ( V_15 , struct V_1 , V_15 ) ;
F_32 ( & V_2 -> V_55 , & V_2 -> V_52 ) ;
}
static inline struct V_56 * F_33 ( struct V_57 * V_58 )
{
return F_20 ( V_58 , struct V_56 , V_58 ) ;
}
static T_3 F_34 ( struct V_57 * V_58 , char * V_59 )
{
struct V_56 * V_60 = F_33 ( V_58 ) ;
return sprintf ( V_59 , L_1 , V_60 -> V_61 ) ;
}
static T_3 F_35 ( struct V_57 * V_58 , const char * V_59 ,
T_4 V_62 )
{
struct V_56 * V_60 = F_33 ( V_58 ) ;
struct V_1 * V_2 ;
unsigned int V_61 ;
if ( F_36 ( V_59 , 10 , & V_61 ) )
return - V_63 ;
V_60 -> V_61 = V_61 ;
F_37 (sg_policy, &attr_set->policy_list, tunables_hook)
V_2 -> V_9 = V_61 * V_64 ;
return V_62 ;
}
static struct V_1 * F_38 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
V_2 = F_39 ( sizeof( * V_2 ) , V_65 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = V_11 ;
F_40 ( & V_2 -> V_50 ) ;
return V_2 ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_42 ( V_2 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_66 * V_67 ;
struct V_68 V_69 = { . V_70 = V_71 / 2 } ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_38 ;
if ( V_11 -> V_12 )
return 0 ;
F_44 ( & V_2 -> V_52 , F_27 ) ;
F_45 ( & V_2 -> V_55 ) ;
V_67 = F_46 ( V_72 , & V_2 -> V_55 ,
L_2 ,
F_47 ( V_11 -> V_73 ) ) ;
if ( F_48 ( V_67 ) ) {
F_49 ( L_3 , F_50 ( V_67 ) ) ;
return F_50 ( V_67 ) ;
}
V_38 = F_51 ( V_67 , V_74 , & V_69 ) ;
if ( V_38 ) {
F_52 ( V_67 ) ;
F_53 ( L_4 , V_75 ) ;
return V_38 ;
}
V_2 -> V_67 = V_67 ;
F_54 ( V_67 , V_11 -> V_73 ) ;
F_55 ( & V_2 -> V_15 , F_31 ) ;
F_56 ( & V_2 -> V_53 ) ;
F_57 ( V_67 ) ;
return 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 -> V_12 )
return;
F_59 ( & V_2 -> V_55 ) ;
F_52 ( V_2 -> V_67 ) ;
F_60 ( & V_2 -> V_53 ) ;
}
static struct V_56 * F_61 ( struct V_1 * V_2 )
{
struct V_56 * V_60 ;
V_60 = F_39 ( sizeof( * V_60 ) , V_65 ) ;
if ( V_60 ) {
F_62 ( & V_60 -> V_58 , & V_2 -> V_76 ) ;
if ( ! F_63 () )
V_77 = V_60 ;
}
return V_60 ;
}
static void F_64 ( struct V_56 * V_60 )
{
if ( ! F_63 () )
V_77 = NULL ;
F_42 ( V_60 ) ;
}
static int F_65 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
struct V_56 * V_60 ;
int V_38 = 0 ;
if ( V_11 -> V_78 )
return - V_79 ;
F_66 ( V_11 ) ;
V_2 = F_38 ( V_11 ) ;
if ( ! V_2 ) {
V_38 = - V_80 ;
goto V_81;
}
V_38 = F_43 ( V_2 ) ;
if ( V_38 )
goto V_82;
F_28 ( & V_83 ) ;
if ( V_77 ) {
if ( F_67 ( F_63 () ) ) {
V_38 = - V_63 ;
goto V_84;
}
V_11 -> V_78 = V_2 ;
V_2 -> V_60 = V_77 ;
F_68 ( & V_77 -> V_58 , & V_2 -> V_76 ) ;
goto V_85;
}
V_60 = F_61 ( V_2 ) ;
if ( ! V_60 ) {
V_38 = - V_80 ;
goto V_84;
}
if ( V_11 -> V_86 ) {
V_60 -> V_61 = V_11 -> V_86 ;
} else {
unsigned int V_87 ;
V_60 -> V_61 = V_88 ;
V_87 = V_11 -> V_19 . V_89 / V_64 ;
if ( V_87 )
V_60 -> V_61 *= V_87 ;
}
V_11 -> V_78 = V_2 ;
V_2 -> V_60 = V_60 ;
V_38 = F_69 ( & V_60 -> V_58 . V_90 , & V_91 ,
F_70 ( V_11 ) , L_5 ,
V_92 . V_93 ) ;
if ( V_38 )
goto V_94;
V_85:
F_30 ( & V_83 ) ;
return 0 ;
V_94:
V_11 -> V_78 = NULL ;
F_64 ( V_60 ) ;
V_84:
F_58 ( V_2 ) ;
V_82:
F_30 ( & V_83 ) ;
F_41 ( V_2 ) ;
V_81:
F_71 ( V_11 ) ;
F_49 ( L_6 , V_38 ) ;
return V_38 ;
}
static void F_72 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_78 ;
struct V_56 * V_60 = V_2 -> V_60 ;
unsigned int V_62 ;
F_28 ( & V_83 ) ;
V_62 = F_73 ( & V_60 -> V_58 , & V_2 -> V_76 ) ;
V_11 -> V_78 = NULL ;
if ( ! V_62 )
F_64 ( V_60 ) ;
F_30 ( & V_83 ) ;
F_58 ( V_2 ) ;
F_41 ( V_2 ) ;
F_71 ( V_11 ) ;
}
static int F_74 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_78 ;
unsigned int V_95 ;
V_2 -> V_9 = V_2 -> V_60 -> V_61 * V_64 ;
V_2 -> V_8 = 0 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_4 = false ;
V_2 -> V_5 = false ;
V_2 -> V_21 = 0 ;
F_22 (cpu, policy->cpus) {
struct V_27 * V_28 = & F_23 ( V_27 , V_95 ) ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_2 = V_2 ;
V_28 -> V_29 = V_96 ;
V_28 -> V_32 = V_11 -> V_19 . V_20 ;
F_75 ( V_95 , & V_28 -> V_42 ,
F_76 ( V_11 ) ?
F_24 :
F_19 ) ;
}
return 0 ;
}
static void F_77 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_78 ;
unsigned int V_95 ;
F_22 (cpu, policy->cpus)
F_78 ( V_95 ) ;
F_79 () ;
if ( ! V_11 -> V_12 ) {
F_80 ( & V_2 -> V_15 ) ;
F_81 ( & V_2 -> V_52 ) ;
}
}
static void F_82 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_78 ;
if ( ! V_11 -> V_12 ) {
F_28 ( & V_2 -> V_53 ) ;
F_83 ( V_11 ) ;
F_30 ( & V_2 -> V_53 ) ;
}
V_2 -> V_5 = true ;
}
struct V_97 * F_84 ( void )
{
return & V_92 ;
}
static int T_5 F_85 ( void )
{
return F_86 ( & V_92 ) ;
}
