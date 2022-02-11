static bool F_1 ( struct V_1 * V_2 , T_1 time )
{
T_2 V_3 ;
if ( V_2 -> V_4 -> V_5 &&
! F_2 ( V_2 -> V_4 ) )
return false ;
if ( V_2 -> V_6 )
return false ;
if ( F_3 ( V_2 -> V_7 ) ) {
V_2 -> V_7 = false ;
V_2 -> V_8 = V_9 ;
return true ;
}
V_3 = time - V_2 -> V_10 ;
return V_3 >= V_2 -> V_11 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 time ,
unsigned int V_8 )
{
struct V_12 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_8 == V_8 )
return;
V_2 -> V_8 = V_8 ;
V_2 -> V_10 = time ;
if ( V_4 -> V_5 ) {
V_8 = F_5 ( V_4 , V_8 ) ;
if ( ! V_8 )
return;
V_4 -> V_13 = V_8 ;
F_6 ( V_8 , F_7 () ) ;
} else {
V_2 -> V_6 = true ;
F_8 ( & V_2 -> V_14 ) ;
}
}
static unsigned int F_9 ( struct V_1 * V_2 ,
unsigned long V_15 , unsigned long V_16 )
{
struct V_12 * V_4 = V_2 -> V_4 ;
unsigned int V_17 = F_10 () ?
V_4 -> V_18 . V_19 : V_4 -> V_13 ;
V_17 = ( V_17 + ( V_17 >> 2 ) ) * V_15 / V_16 ;
if ( V_17 == V_2 -> V_20 && V_2 -> V_8 != V_9 )
return V_2 -> V_8 ;
V_2 -> V_20 = V_17 ;
return F_11 ( V_4 , V_17 ) ;
}
static void F_12 ( unsigned long * V_15 , unsigned long * V_16 , int V_21 )
{
struct V_22 * V_22 = F_13 ( V_21 ) ;
unsigned long V_23 ;
V_23 = F_14 ( NULL , V_21 ) ;
* V_15 = F_15 ( V_22 -> V_24 . V_25 . V_26 , V_23 ) ;
* V_16 = V_23 ;
}
static void F_16 ( struct V_27 * V_28 , T_1 time ,
unsigned int V_29 )
{
if ( V_29 & V_30 ) {
if ( V_28 -> V_31 )
return;
V_28 -> V_31 = true ;
if ( V_28 -> V_32 ) {
V_28 -> V_32 <<= 1 ;
if ( V_28 -> V_32 > V_28 -> V_33 )
V_28 -> V_32 = V_28 -> V_33 ;
} else {
V_28 -> V_32 = V_28 -> V_2 -> V_4 -> F_15 ;
}
} else if ( V_28 -> V_32 ) {
T_2 V_3 = time - V_28 -> V_34 ;
if ( V_3 > V_35 ) {
V_28 -> V_32 = 0 ;
V_28 -> V_31 = false ;
}
}
}
static void F_17 ( struct V_27 * V_28 , unsigned long * V_15 ,
unsigned long * V_16 )
{
unsigned int V_36 , V_37 ;
if ( ! V_28 -> V_32 )
return;
if ( V_28 -> V_31 ) {
V_28 -> V_31 = false ;
} else {
V_28 -> V_32 >>= 1 ;
if ( V_28 -> V_32 < V_28 -> V_2 -> V_4 -> F_15 ) {
V_28 -> V_32 = 0 ;
return;
}
}
V_36 = V_28 -> V_32 ;
V_37 = V_28 -> V_33 ;
if ( * V_15 * V_37 < * V_16 * V_36 ) {
* V_15 = V_36 ;
* V_16 = V_37 ;
}
}
static bool F_18 ( struct V_27 * V_28 )
{
unsigned long V_38 = F_19 () ;
bool V_39 = V_38 == V_28 -> V_40 ;
V_28 -> V_40 = V_38 ;
return V_39 ;
}
static inline bool F_18 ( struct V_27 * V_28 ) { return false ; }
static void F_20 ( struct V_41 * V_42 , T_1 time ,
unsigned int V_29 )
{
struct V_27 * V_28 = F_21 ( V_42 , struct V_27 , V_43 ) ;
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_12 * V_4 = V_2 -> V_4 ;
unsigned long V_15 , V_16 ;
unsigned int V_44 ;
bool V_45 ;
F_16 ( V_28 , time , V_29 ) ;
V_28 -> V_34 = time ;
if ( ! F_1 ( V_2 , time ) )
return;
V_45 = F_18 ( V_28 ) ;
if ( V_29 & V_46 ) {
V_44 = V_4 -> V_18 . V_19 ;
} else {
F_12 ( & V_15 , & V_16 , V_28 -> V_21 ) ;
F_17 ( V_28 , & V_15 , & V_16 ) ;
V_44 = F_9 ( V_2 , V_15 , V_16 ) ;
if ( V_45 && V_44 < V_2 -> V_8 )
V_44 = V_2 -> V_8 ;
}
F_4 ( V_2 , time , V_44 ) ;
}
static unsigned int F_22 ( struct V_27 * V_28 , T_1 time )
{
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_12 * V_4 = V_2 -> V_4 ;
unsigned long V_15 = 0 , V_16 = 1 ;
unsigned int V_47 ;
F_23 (j, policy->cpus) {
struct V_27 * V_48 = & F_24 ( V_27 , V_47 ) ;
unsigned long V_49 , V_50 ;
T_2 V_3 ;
V_3 = time - V_48 -> V_34 ;
if ( V_3 > V_35 ) {
V_48 -> V_32 = 0 ;
V_48 -> V_31 = false ;
continue;
}
if ( V_48 -> V_29 & V_46 )
return V_4 -> V_18 . V_19 ;
V_49 = V_48 -> V_15 ;
V_50 = V_48 -> V_16 ;
if ( V_49 * V_16 > V_50 * V_15 ) {
V_15 = V_49 ;
V_16 = V_50 ;
}
F_17 ( V_48 , & V_15 , & V_16 ) ;
}
return F_9 ( V_2 , V_15 , V_16 ) ;
}
static void F_25 ( struct V_41 * V_42 , T_1 time ,
unsigned int V_29 )
{
struct V_27 * V_28 = F_21 ( V_42 , struct V_27 , V_43 ) ;
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned long V_15 , V_16 ;
unsigned int V_44 ;
F_12 ( & V_15 , & V_16 , V_28 -> V_21 ) ;
F_26 ( & V_2 -> V_51 ) ;
V_28 -> V_15 = V_15 ;
V_28 -> V_16 = V_16 ;
V_28 -> V_29 = V_29 ;
F_16 ( V_28 , time , V_29 ) ;
V_28 -> V_34 = time ;
if ( F_1 ( V_2 , time ) ) {
if ( V_29 & V_46 )
V_44 = V_2 -> V_4 -> V_18 . V_19 ;
else
V_44 = F_22 ( V_28 , time ) ;
F_4 ( V_2 , time , V_44 ) ;
}
F_27 ( & V_2 -> V_51 ) ;
}
static void F_28 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_21 ( V_53 , struct V_1 , V_53 ) ;
F_29 ( & V_2 -> V_54 ) ;
F_30 ( V_2 -> V_4 , V_2 -> V_8 ,
V_55 ) ;
F_31 ( & V_2 -> V_54 ) ;
V_2 -> V_6 = false ;
}
static void F_32 ( struct V_14 * V_14 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_14 , struct V_1 , V_14 ) ;
F_33 ( & V_2 -> V_56 , & V_2 -> V_53 ) ;
}
static inline struct V_57 * F_34 ( struct V_58 * V_59 )
{
return F_21 ( V_59 , struct V_57 , V_59 ) ;
}
static T_3 F_35 ( struct V_58 * V_59 , char * V_60 )
{
struct V_57 * V_61 = F_34 ( V_59 ) ;
return sprintf ( V_60 , L_1 , V_61 -> V_62 ) ;
}
static T_3 F_36 ( struct V_58 * V_59 , const char * V_60 ,
T_4 V_63 )
{
struct V_57 * V_61 = F_34 ( V_59 ) ;
struct V_1 * V_2 ;
unsigned int V_62 ;
if ( F_37 ( V_60 , 10 , & V_62 ) )
return - V_64 ;
V_61 -> V_62 = V_62 ;
F_38 (sg_policy, &attr_set->policy_list, tunables_hook)
V_2 -> V_11 = V_62 * V_65 ;
return V_63 ;
}
static struct V_1 * F_39 ( struct V_12 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_40 ( sizeof( * V_2 ) , V_66 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_4 = V_4 ;
F_41 ( & V_2 -> V_51 ) ;
return V_2 ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_67 * V_68 ;
struct V_69 V_70 = { . V_71 = V_72 / 2 } ;
struct V_12 * V_4 = V_2 -> V_4 ;
int V_39 ;
if ( V_4 -> V_5 )
return 0 ;
F_45 ( & V_2 -> V_53 , F_28 ) ;
F_46 ( & V_2 -> V_56 ) ;
V_68 = F_47 ( V_73 , & V_2 -> V_56 ,
L_2 ,
F_48 ( V_4 -> V_74 ) ) ;
if ( F_49 ( V_68 ) ) {
F_50 ( L_3 , F_51 ( V_68 ) ) ;
return F_51 ( V_68 ) ;
}
V_39 = F_52 ( V_68 , V_75 , & V_70 ) ;
if ( V_39 ) {
F_53 ( V_68 ) ;
F_54 ( L_4 , V_76 ) ;
return V_39 ;
}
V_2 -> V_68 = V_68 ;
if ( ! V_4 -> V_77 )
F_55 ( V_68 , V_4 -> V_74 ) ;
F_56 ( & V_2 -> V_14 , F_32 ) ;
F_57 ( & V_2 -> V_54 ) ;
F_58 ( V_68 ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 -> V_5 )
return;
F_60 ( & V_2 -> V_56 ) ;
F_53 ( V_2 -> V_68 ) ;
F_61 ( & V_2 -> V_54 ) ;
}
static struct V_57 * F_62 ( struct V_1 * V_2 )
{
struct V_57 * V_61 ;
V_61 = F_40 ( sizeof( * V_61 ) , V_66 ) ;
if ( V_61 ) {
F_63 ( & V_61 -> V_59 , & V_2 -> V_78 ) ;
if ( ! F_64 () )
V_79 = V_61 ;
}
return V_61 ;
}
static void F_65 ( struct V_57 * V_61 )
{
if ( ! F_64 () )
V_79 = NULL ;
F_43 ( V_61 ) ;
}
static int F_66 ( struct V_12 * V_4 )
{
struct V_1 * V_2 ;
struct V_57 * V_61 ;
int V_39 = 0 ;
if ( V_4 -> V_80 )
return - V_81 ;
F_67 ( V_4 ) ;
V_2 = F_39 ( V_4 ) ;
if ( ! V_2 ) {
V_39 = - V_82 ;
goto V_83;
}
V_39 = F_44 ( V_2 ) ;
if ( V_39 )
goto V_84;
F_29 ( & V_85 ) ;
if ( V_79 ) {
if ( F_68 ( F_64 () ) ) {
V_39 = - V_64 ;
goto V_86;
}
V_4 -> V_80 = V_2 ;
V_2 -> V_61 = V_79 ;
F_69 ( & V_79 -> V_59 , & V_2 -> V_78 ) ;
goto V_87;
}
V_61 = F_62 ( V_2 ) ;
if ( ! V_61 ) {
V_39 = - V_82 ;
goto V_86;
}
V_61 -> V_62 = F_70 ( V_4 ) ;
V_4 -> V_80 = V_2 ;
V_2 -> V_61 = V_61 ;
V_39 = F_71 ( & V_61 -> V_59 . V_88 , & V_89 ,
F_72 ( V_4 ) , L_5 ,
V_90 . V_91 ) ;
if ( V_39 )
goto V_92;
V_87:
F_31 ( & V_85 ) ;
return 0 ;
V_92:
V_4 -> V_80 = NULL ;
F_65 ( V_61 ) ;
V_86:
F_59 ( V_2 ) ;
V_84:
F_31 ( & V_85 ) ;
F_42 ( V_2 ) ;
V_83:
F_73 ( V_4 ) ;
F_50 ( L_6 , V_39 ) ;
return V_39 ;
}
static void F_74 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_80 ;
struct V_57 * V_61 = V_2 -> V_61 ;
unsigned int V_63 ;
F_29 ( & V_85 ) ;
V_63 = F_75 ( & V_61 -> V_59 , & V_2 -> V_78 ) ;
V_4 -> V_80 = NULL ;
if ( ! V_63 )
F_65 ( V_61 ) ;
F_31 ( & V_85 ) ;
F_59 ( V_2 ) ;
F_42 ( V_2 ) ;
F_73 ( V_4 ) ;
}
static int F_76 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_80 ;
unsigned int V_21 ;
V_2 -> V_11 = V_2 -> V_61 -> V_62 * V_65 ;
V_2 -> V_10 = 0 ;
V_2 -> V_8 = V_9 ;
V_2 -> V_6 = false ;
V_2 -> V_7 = false ;
V_2 -> V_20 = 0 ;
F_23 (cpu, policy->cpus) {
struct V_27 * V_28 = & F_24 ( V_27 , V_21 ) ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_21 = V_21 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_29 = V_93 ;
V_28 -> V_33 = V_4 -> V_18 . V_19 ;
}
F_23 (cpu, policy->cpus) {
struct V_27 * V_28 = & F_24 ( V_27 , V_21 ) ;
F_77 ( V_21 , & V_28 -> V_43 ,
F_78 ( V_4 ) ?
F_25 :
F_20 ) ;
}
return 0 ;
}
static void F_79 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_80 ;
unsigned int V_21 ;
F_23 (cpu, policy->cpus)
F_80 ( V_21 ) ;
F_81 () ;
if ( ! V_4 -> V_5 ) {
F_82 ( & V_2 -> V_14 ) ;
F_83 ( & V_2 -> V_53 ) ;
}
}
static void F_84 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_80 ;
if ( ! V_4 -> V_5 ) {
F_29 ( & V_2 -> V_54 ) ;
F_85 ( V_4 ) ;
F_31 ( & V_2 -> V_54 ) ;
}
V_2 -> V_7 = true ;
}
struct V_94 * F_86 ( void )
{
return & V_90 ;
}
static int T_5 F_87 ( void )
{
return F_88 ( & V_90 ) ;
}
