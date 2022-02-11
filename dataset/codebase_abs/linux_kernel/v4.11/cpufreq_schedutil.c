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
V_2 -> V_8 = time ;
if ( V_11 -> V_12 ) {
if ( V_2 -> V_6 == V_6 ) {
F_4 ( V_11 -> V_13 , F_5 () ) ;
return;
}
V_2 -> V_6 = V_6 ;
V_6 = F_6 ( V_11 , V_6 ) ;
if ( V_6 == V_14 )
return;
V_11 -> V_13 = V_6 ;
F_4 ( V_6 , F_5 () ) ;
} else if ( V_2 -> V_6 != V_6 ) {
V_2 -> V_6 = V_6 ;
V_2 -> V_4 = true ;
F_7 ( & V_2 -> V_15 ) ;
}
}
static unsigned int F_8 ( struct V_1 * V_2 ,
unsigned long V_16 , unsigned long V_17 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_18 = F_9 () ?
V_11 -> V_19 . V_20 : V_11 -> V_13 ;
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
V_23 = F_13 ( NULL , F_5 () ) ;
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
static void F_17 ( struct V_37 * V_38 , T_1 time ,
unsigned int V_29 )
{
struct V_27 * V_28 = F_18 ( V_38 , struct V_27 , V_39 ) ;
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_16 , V_17 ;
unsigned int V_40 ;
F_15 ( V_28 , time , V_29 ) ;
V_28 -> V_33 = time ;
if ( ! F_1 ( V_2 , time ) )
return;
if ( V_29 & V_41 ) {
V_40 = V_11 -> V_19 . V_20 ;
} else {
F_11 ( & V_16 , & V_17 ) ;
F_16 ( V_28 , & V_16 , & V_17 ) ;
V_40 = F_8 ( V_2 , V_16 , V_17 ) ;
}
F_3 ( V_2 , time , V_40 ) ;
}
static unsigned int F_19 ( struct V_27 * V_28 ,
unsigned long V_16 , unsigned long V_17 ,
unsigned int V_29 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_42 = V_11 -> V_19 . V_20 ;
T_1 V_8 = V_2 -> V_8 ;
unsigned int V_43 ;
if ( V_29 & V_41 )
return V_42 ;
F_16 ( V_28 , & V_16 , & V_17 ) ;
F_20 (j, policy->cpus) {
struct V_27 * V_44 ;
unsigned long V_45 , V_46 ;
T_2 V_3 ;
if ( V_43 == F_5 () )
continue;
V_44 = & F_21 ( V_27 , V_43 ) ;
V_3 = V_8 - V_44 -> V_33 ;
if ( V_3 > V_34 ) {
V_44 -> V_31 = 0 ;
continue;
}
if ( V_44 -> V_29 & V_41 )
return V_42 ;
V_45 = V_44 -> V_16 ;
V_46 = V_44 -> V_17 ;
if ( V_45 * V_17 > V_46 * V_16 ) {
V_16 = V_45 ;
V_17 = V_46 ;
}
F_16 ( V_44 , & V_16 , & V_17 ) ;
}
return F_8 ( V_2 , V_16 , V_17 ) ;
}
static void F_22 ( struct V_37 * V_38 , T_1 time ,
unsigned int V_29 )
{
struct V_27 * V_28 = F_18 ( V_38 , struct V_27 , V_39 ) ;
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned long V_16 , V_17 ;
unsigned int V_40 ;
F_11 ( & V_16 , & V_17 ) ;
F_23 ( & V_2 -> V_47 ) ;
V_28 -> V_16 = V_16 ;
V_28 -> V_17 = V_17 ;
V_28 -> V_29 = V_29 ;
F_15 ( V_28 , time , V_29 ) ;
V_28 -> V_33 = time ;
if ( F_1 ( V_2 , time ) ) {
V_40 = F_19 ( V_28 , V_16 , V_17 , V_29 ) ;
F_3 ( V_2 , time , V_40 ) ;
}
F_24 ( & V_2 -> V_47 ) ;
}
static void F_25 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_18 ( V_49 , struct V_1 , V_49 ) ;
F_26 ( & V_2 -> V_50 ) ;
F_27 ( V_2 -> V_11 , V_2 -> V_6 ,
V_51 ) ;
F_28 ( & V_2 -> V_50 ) ;
V_2 -> V_4 = false ;
}
static void F_29 ( struct V_15 * V_15 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( V_15 , struct V_1 , V_15 ) ;
F_30 ( & V_2 -> V_52 , & V_2 -> V_49 ) ;
}
static inline struct V_53 * F_31 ( struct V_54 * V_55 )
{
return F_18 ( V_55 , struct V_53 , V_55 ) ;
}
static T_3 F_32 ( struct V_54 * V_55 , char * V_56 )
{
struct V_53 * V_57 = F_31 ( V_55 ) ;
return sprintf ( V_56 , L_1 , V_57 -> V_58 ) ;
}
static T_3 F_33 ( struct V_54 * V_55 , const char * V_56 ,
T_4 V_59 )
{
struct V_53 * V_57 = F_31 ( V_55 ) ;
struct V_1 * V_2 ;
unsigned int V_58 ;
if ( F_34 ( V_56 , 10 , & V_58 ) )
return - V_60 ;
V_57 -> V_58 = V_58 ;
F_35 (sg_policy, &attr_set->policy_list, tunables_hook)
V_2 -> V_9 = V_58 * V_61 ;
return V_59 ;
}
static struct V_1 * F_36 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
V_2 = F_37 ( sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = V_11 ;
F_38 ( & V_2 -> V_47 ) ;
return V_2 ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
struct V_65 V_66 = { . V_67 = V_68 / 2 } ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_69 ;
if ( V_11 -> V_12 )
return 0 ;
F_42 ( & V_2 -> V_49 , F_25 ) ;
F_43 ( & V_2 -> V_52 ) ;
V_64 = F_44 ( V_70 , & V_2 -> V_52 ,
L_2 ,
F_45 ( V_11 -> V_71 ) ) ;
if ( F_46 ( V_64 ) ) {
F_47 ( L_3 , F_48 ( V_64 ) ) ;
return F_48 ( V_64 ) ;
}
V_69 = F_49 ( V_64 , V_72 , & V_66 ) ;
if ( V_69 ) {
F_50 ( V_64 ) ;
F_51 ( L_4 , V_73 ) ;
return V_69 ;
}
V_2 -> V_64 = V_64 ;
F_52 ( V_64 , V_11 -> V_71 ) ;
F_53 ( & V_2 -> V_15 , F_29 ) ;
F_54 ( & V_2 -> V_50 ) ;
F_55 ( V_64 ) ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 -> V_12 )
return;
F_57 ( & V_2 -> V_52 ) ;
F_50 ( V_2 -> V_64 ) ;
F_58 ( & V_2 -> V_50 ) ;
}
static struct V_53 * F_59 ( struct V_1 * V_2 )
{
struct V_53 * V_57 ;
V_57 = F_37 ( sizeof( * V_57 ) , V_62 ) ;
if ( V_57 ) {
F_60 ( & V_57 -> V_55 , & V_2 -> V_74 ) ;
if ( ! F_61 () )
V_75 = V_57 ;
}
return V_57 ;
}
static void F_62 ( struct V_53 * V_57 )
{
if ( ! F_61 () )
V_75 = NULL ;
F_40 ( V_57 ) ;
}
static int F_63 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
struct V_53 * V_57 ;
unsigned int V_76 ;
int V_69 = 0 ;
if ( V_11 -> V_77 )
return - V_78 ;
F_64 ( V_11 ) ;
V_2 = F_36 ( V_11 ) ;
if ( ! V_2 ) {
V_69 = - V_79 ;
goto V_80;
}
V_69 = F_41 ( V_2 ) ;
if ( V_69 )
goto V_81;
F_26 ( & V_82 ) ;
if ( V_75 ) {
if ( F_65 ( F_61 () ) ) {
V_69 = - V_60 ;
goto V_83;
}
V_11 -> V_77 = V_2 ;
V_2 -> V_57 = V_75 ;
F_66 ( & V_75 -> V_55 , & V_2 -> V_74 ) ;
goto V_84;
}
V_57 = F_59 ( V_2 ) ;
if ( ! V_57 ) {
V_69 = - V_79 ;
goto V_83;
}
V_57 -> V_58 = V_85 ;
V_76 = V_11 -> V_19 . V_86 / V_61 ;
if ( V_76 )
V_57 -> V_58 *= V_76 ;
V_11 -> V_77 = V_2 ;
V_2 -> V_57 = V_57 ;
V_69 = F_67 ( & V_57 -> V_55 . V_87 , & V_88 ,
F_68 ( V_11 ) , L_5 ,
V_89 . V_90 ) ;
if ( V_69 )
goto V_91;
V_84:
F_28 ( & V_82 ) ;
return 0 ;
V_91:
V_11 -> V_77 = NULL ;
F_62 ( V_57 ) ;
V_83:
F_56 ( V_2 ) ;
V_81:
F_28 ( & V_82 ) ;
F_39 ( V_2 ) ;
V_80:
F_69 ( V_11 ) ;
F_47 ( L_6 , V_69 ) ;
return V_69 ;
}
static void F_70 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_77 ;
struct V_53 * V_57 = V_2 -> V_57 ;
unsigned int V_59 ;
F_26 ( & V_82 ) ;
V_59 = F_71 ( & V_57 -> V_55 , & V_2 -> V_74 ) ;
V_11 -> V_77 = NULL ;
if ( ! V_59 )
F_62 ( V_57 ) ;
F_28 ( & V_82 ) ;
F_56 ( V_2 ) ;
F_39 ( V_2 ) ;
F_69 ( V_11 ) ;
}
static int F_72 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_77 ;
unsigned int V_92 ;
V_2 -> V_9 = V_2 -> V_57 -> V_58 * V_61 ;
V_2 -> V_8 = 0 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_4 = false ;
V_2 -> V_5 = false ;
V_2 -> V_21 = 0 ;
F_20 (cpu, policy->cpus) {
struct V_27 * V_28 = & F_21 ( V_27 , V_92 ) ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_2 = V_2 ;
V_28 -> V_29 = V_93 ;
V_28 -> V_32 = V_11 -> V_19 . V_20 ;
F_73 ( V_92 , & V_28 -> V_39 ,
F_74 ( V_11 ) ?
F_22 :
F_17 ) ;
}
return 0 ;
}
static void F_75 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_77 ;
unsigned int V_92 ;
F_20 (cpu, policy->cpus)
F_76 ( V_92 ) ;
F_77 () ;
if ( ! V_11 -> V_12 ) {
F_78 ( & V_2 -> V_15 ) ;
F_79 ( & V_2 -> V_49 ) ;
}
}
static void F_80 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_77 ;
if ( ! V_11 -> V_12 ) {
F_26 ( & V_2 -> V_50 ) ;
F_81 ( V_11 ) ;
F_28 ( & V_2 -> V_50 ) ;
}
V_2 -> V_5 = true ;
}
struct V_94 * F_82 ( void )
{
return & V_89 ;
}
static int T_5 F_83 ( void )
{
return F_84 ( & V_89 ) ;
}
