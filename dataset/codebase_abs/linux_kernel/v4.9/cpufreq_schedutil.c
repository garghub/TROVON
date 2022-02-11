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
static unsigned int F_8 ( struct V_16 * V_17 , unsigned long V_18 ,
unsigned long V_19 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_20 = F_9 () ?
V_11 -> V_21 . V_22 : V_11 -> V_13 ;
V_20 = ( V_20 + ( V_20 >> 2 ) ) * V_18 / V_19 ;
if ( V_20 == V_17 -> V_23 && V_2 -> V_6 != V_7 )
return V_2 -> V_6 ;
V_17 -> V_23 = V_20 ;
return F_10 ( V_11 , V_20 ) ;
}
static void F_11 ( unsigned long * V_18 , unsigned long * V_19 )
{
struct V_24 * V_24 = F_12 () ;
unsigned long V_25 ;
V_25 = F_13 ( NULL , F_5 () ) ;
* V_18 = F_14 ( V_24 -> V_26 . V_27 . V_28 , V_25 ) ;
* V_19 = V_25 ;
}
static void F_15 ( struct V_16 * V_17 , T_1 time ,
unsigned int V_29 )
{
if ( V_29 & V_30 ) {
V_17 -> V_31 = V_17 -> V_32 ;
} else if ( V_17 -> V_31 ) {
T_2 V_3 = time - V_17 -> V_33 ;
if ( V_3 > V_34 )
V_17 -> V_31 = 0 ;
}
}
static void F_16 ( struct V_16 * V_17 , unsigned long * V_18 ,
unsigned long * V_19 )
{
unsigned long V_35 = V_17 -> V_31 ;
unsigned long V_36 = V_17 -> V_32 ;
if ( ! V_35 )
return;
if ( * V_18 * V_36 < * V_19 * V_35 ) {
* V_18 = V_35 ;
* V_19 = V_36 ;
}
V_17 -> V_31 >>= 1 ;
}
static void F_17 ( struct V_37 * V_38 , T_1 time ,
unsigned int V_29 )
{
struct V_16 * V_17 = F_18 ( V_38 , struct V_16 , V_39 ) ;
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_18 , V_19 ;
unsigned int V_40 ;
F_15 ( V_17 , time , V_29 ) ;
V_17 -> V_33 = time ;
if ( ! F_1 ( V_2 , time ) )
return;
if ( V_29 & V_41 ) {
V_40 = V_11 -> V_21 . V_22 ;
} else {
F_11 ( & V_18 , & V_19 ) ;
F_16 ( V_17 , & V_18 , & V_19 ) ;
V_40 = F_8 ( V_17 , V_18 , V_19 ) ;
}
F_3 ( V_2 , time , V_40 ) ;
}
static unsigned int F_19 ( struct V_16 * V_17 ,
unsigned long V_18 , unsigned long V_19 ,
unsigned int V_29 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_42 = V_11 -> V_21 . V_22 ;
T_1 V_8 = V_2 -> V_8 ;
unsigned int V_43 ;
if ( V_29 & V_41 )
return V_42 ;
F_16 ( V_17 , & V_18 , & V_19 ) ;
F_20 (j, policy->cpus) {
struct V_16 * V_44 ;
unsigned long V_45 , V_46 ;
T_2 V_3 ;
if ( V_43 == F_5 () )
continue;
V_44 = & F_21 ( V_16 , V_43 ) ;
V_3 = V_8 - V_44 -> V_33 ;
if ( V_3 > V_34 ) {
V_44 -> V_31 = 0 ;
continue;
}
if ( V_44 -> V_29 & V_41 )
return V_42 ;
V_45 = V_44 -> V_18 ;
V_46 = V_44 -> V_19 ;
if ( V_45 * V_19 > V_46 * V_18 ) {
V_18 = V_45 ;
V_19 = V_46 ;
}
F_16 ( V_44 , & V_18 , & V_19 ) ;
}
return F_8 ( V_17 , V_18 , V_19 ) ;
}
static void F_22 ( struct V_37 * V_38 , T_1 time ,
unsigned int V_29 )
{
struct V_16 * V_17 = F_18 ( V_38 , struct V_16 , V_39 ) ;
struct V_1 * V_2 = V_17 -> V_2 ;
unsigned long V_18 , V_19 ;
unsigned int V_40 ;
F_11 ( & V_18 , & V_19 ) ;
F_23 ( & V_2 -> V_47 ) ;
V_17 -> V_18 = V_18 ;
V_17 -> V_19 = V_19 ;
V_17 -> V_29 = V_29 ;
F_15 ( V_17 , time , V_29 ) ;
V_17 -> V_33 = time ;
if ( F_1 ( V_2 , time ) ) {
V_40 = F_19 ( V_17 , V_18 , V_19 , V_29 ) ;
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
F_30 ( F_5 () , & V_2 -> V_49 ) ;
}
static inline struct V_52 * F_31 ( struct V_53 * V_54 )
{
return F_18 ( V_54 , struct V_52 , V_54 ) ;
}
static T_3 F_32 ( struct V_53 * V_54 , char * V_55 )
{
struct V_52 * V_56 = F_31 ( V_54 ) ;
return sprintf ( V_55 , L_1 , V_56 -> V_57 ) ;
}
static T_3 F_33 ( struct V_53 * V_54 , const char * V_55 ,
T_4 V_58 )
{
struct V_52 * V_56 = F_31 ( V_54 ) ;
struct V_1 * V_2 ;
unsigned int V_57 ;
if ( F_34 ( V_55 , 10 , & V_57 ) )
return - V_59 ;
V_56 -> V_57 = V_57 ;
F_35 (sg_policy, &attr_set->policy_list, tunables_hook)
V_2 -> V_9 = V_57 * V_60 ;
return V_58 ;
}
static struct V_1 * F_36 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
V_2 = F_37 ( sizeof( * V_2 ) , V_61 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = V_11 ;
F_38 ( & V_2 -> V_15 , F_29 ) ;
F_39 ( & V_2 -> V_49 , F_25 ) ;
F_40 ( & V_2 -> V_50 ) ;
F_41 ( & V_2 -> V_47 ) ;
return V_2 ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_43 ( & V_2 -> V_50 ) ;
F_44 ( V_2 ) ;
}
static struct V_52 * F_45 ( struct V_1 * V_2 )
{
struct V_52 * V_56 ;
V_56 = F_37 ( sizeof( * V_56 ) , V_61 ) ;
if ( V_56 ) {
F_46 ( & V_56 -> V_54 , & V_2 -> V_62 ) ;
if ( ! F_47 () )
V_63 = V_56 ;
}
return V_56 ;
}
static void F_48 ( struct V_52 * V_56 )
{
if ( ! F_47 () )
V_63 = NULL ;
F_44 ( V_56 ) ;
}
static int F_49 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
struct V_52 * V_56 ;
unsigned int V_64 ;
int V_65 = 0 ;
if ( V_11 -> V_66 )
return - V_67 ;
V_2 = F_36 ( V_11 ) ;
if ( ! V_2 )
return - V_68 ;
F_26 ( & V_69 ) ;
if ( V_63 ) {
if ( F_50 ( F_47 () ) ) {
V_65 = - V_59 ;
goto V_70;
}
V_11 -> V_66 = V_2 ;
V_2 -> V_56 = V_63 ;
F_51 ( & V_63 -> V_54 , & V_2 -> V_62 ) ;
goto V_71;
}
V_56 = F_45 ( V_2 ) ;
if ( ! V_56 ) {
V_65 = - V_68 ;
goto V_70;
}
V_56 -> V_57 = V_72 ;
V_64 = V_11 -> V_21 . V_73 / V_60 ;
if ( V_64 )
V_56 -> V_57 *= V_64 ;
V_11 -> V_66 = V_2 ;
V_2 -> V_56 = V_56 ;
V_65 = F_52 ( & V_56 -> V_54 . V_74 , & V_75 ,
F_53 ( V_11 ) , L_2 ,
V_76 . V_77 ) ;
if ( V_65 )
goto V_78;
V_71:
F_28 ( & V_69 ) ;
F_54 ( V_11 ) ;
return 0 ;
V_78:
V_11 -> V_66 = NULL ;
F_48 ( V_56 ) ;
V_70:
F_28 ( & V_69 ) ;
F_42 ( V_2 ) ;
F_55 ( L_3 , V_65 ) ;
return V_65 ;
}
static void F_56 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_66 ;
struct V_52 * V_56 = V_2 -> V_56 ;
unsigned int V_58 ;
F_57 ( V_11 ) ;
F_26 ( & V_69 ) ;
V_58 = F_58 ( & V_56 -> V_54 , & V_2 -> V_62 ) ;
V_11 -> V_66 = NULL ;
if ( ! V_58 )
F_48 ( V_56 ) ;
F_28 ( & V_69 ) ;
F_42 ( V_2 ) ;
}
static int F_59 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_66 ;
unsigned int V_79 ;
V_2 -> V_9 = V_2 -> V_56 -> V_57 * V_60 ;
V_2 -> V_8 = 0 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_4 = false ;
V_2 -> V_5 = false ;
F_20 (cpu, policy->cpus) {
struct V_16 * V_17 = & F_21 ( V_16 , V_79 ) ;
V_17 -> V_2 = V_2 ;
if ( F_60 ( V_11 ) ) {
V_17 -> V_18 = 0 ;
V_17 -> V_19 = 0 ;
V_17 -> V_29 = V_80 ;
V_17 -> V_33 = 0 ;
V_17 -> V_23 = 0 ;
V_17 -> V_31 = 0 ;
V_17 -> V_32 = V_11 -> V_21 . V_22 ;
F_61 ( V_79 , & V_17 -> V_39 ,
F_22 ) ;
} else {
F_61 ( V_79 , & V_17 -> V_39 ,
F_17 ) ;
}
}
return 0 ;
}
static void F_62 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_66 ;
unsigned int V_79 ;
F_20 (cpu, policy->cpus)
F_63 ( V_79 ) ;
F_64 () ;
F_65 ( & V_2 -> V_15 ) ;
F_66 ( & V_2 -> V_49 ) ;
}
static void F_67 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_66 ;
if ( ! V_11 -> V_12 ) {
F_26 ( & V_2 -> V_50 ) ;
F_68 ( V_11 ) ;
F_28 ( & V_2 -> V_50 ) ;
}
V_2 -> V_5 = true ;
}
struct V_81 * F_69 ( void )
{
return & V_76 ;
}
static int T_5 F_70 ( void )
{
return F_71 ( & V_76 ) ;
}
