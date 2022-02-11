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
static void F_11 ( struct V_24 * V_25 , T_1 time ,
unsigned long V_18 , unsigned long V_19 )
{
struct V_16 * V_17 = F_12 ( V_25 , struct V_16 , V_26 ) ;
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_27 ;
if ( ! F_1 ( V_2 , time ) )
return;
V_27 = V_18 == V_28 ? V_11 -> V_21 . V_22 :
F_8 ( V_17 , V_18 , V_19 ) ;
F_3 ( V_2 , time , V_27 ) ;
}
static unsigned int F_13 ( struct V_16 * V_17 ,
unsigned long V_18 , unsigned long V_19 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_29 = V_11 -> V_21 . V_22 ;
T_1 V_8 = V_2 -> V_8 ;
unsigned int V_30 ;
if ( V_18 == V_28 )
return V_29 ;
F_14 (j, policy->cpus) {
struct V_16 * V_31 ;
unsigned long V_32 , V_33 ;
T_2 V_3 ;
if ( V_30 == F_5 () )
continue;
V_31 = & F_15 ( V_16 , V_30 ) ;
V_3 = V_8 - V_31 -> V_34 ;
if ( V_3 > V_35 )
continue;
V_32 = V_31 -> V_18 ;
if ( V_32 == V_28 )
return V_29 ;
V_33 = V_31 -> V_19 ;
if ( V_32 * V_19 > V_33 * V_18 ) {
V_18 = V_32 ;
V_19 = V_33 ;
}
}
return F_8 ( V_17 , V_18 , V_19 ) ;
}
static void F_16 ( struct V_24 * V_25 , T_1 time ,
unsigned long V_18 , unsigned long V_19 )
{
struct V_16 * V_17 = F_12 ( V_25 , struct V_16 , V_26 ) ;
struct V_1 * V_2 = V_17 -> V_2 ;
unsigned int V_27 ;
F_17 ( & V_2 -> V_36 ) ;
V_17 -> V_18 = V_18 ;
V_17 -> V_19 = V_19 ;
V_17 -> V_34 = time ;
if ( F_1 ( V_2 , time ) ) {
V_27 = F_13 ( V_17 , V_18 , V_19 ) ;
F_3 ( V_2 , time , V_27 ) ;
}
F_18 ( & V_2 -> V_36 ) ;
}
static void F_19 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_12 ( V_38 , struct V_1 , V_38 ) ;
F_20 ( & V_2 -> V_39 ) ;
F_21 ( V_2 -> V_11 , V_2 -> V_6 ,
V_40 ) ;
F_22 ( & V_2 -> V_39 ) ;
V_2 -> V_4 = false ;
}
static void F_23 ( struct V_15 * V_15 )
{
struct V_1 * V_2 ;
V_2 = F_12 ( V_15 , struct V_1 , V_15 ) ;
F_24 ( F_5 () , & V_2 -> V_38 ) ;
}
static inline struct V_41 * F_25 ( struct V_42 * V_43 )
{
return F_12 ( V_43 , struct V_41 , V_43 ) ;
}
static T_3 F_26 ( struct V_42 * V_43 , char * V_44 )
{
struct V_41 * V_45 = F_25 ( V_43 ) ;
return sprintf ( V_44 , L_1 , V_45 -> V_46 ) ;
}
static T_3 F_27 ( struct V_42 * V_43 , const char * V_44 ,
T_4 V_47 )
{
struct V_41 * V_45 = F_25 ( V_43 ) ;
struct V_1 * V_2 ;
unsigned int V_46 ;
if ( F_28 ( V_44 , 10 , & V_46 ) )
return - V_48 ;
V_45 -> V_46 = V_46 ;
F_29 (sg_policy, &attr_set->policy_list, tunables_hook)
V_2 -> V_9 = V_46 * V_49 ;
return V_47 ;
}
static struct V_1 * F_30 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
V_2 = F_31 ( sizeof( * V_2 ) , V_50 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = V_11 ;
F_32 ( & V_2 -> V_15 , F_23 ) ;
F_33 ( & V_2 -> V_38 , F_19 ) ;
F_34 ( & V_2 -> V_39 ) ;
F_35 ( & V_2 -> V_36 ) ;
return V_2 ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_39 ) ;
F_38 ( V_2 ) ;
}
static struct V_41 * F_39 ( struct V_1 * V_2 )
{
struct V_41 * V_45 ;
V_45 = F_31 ( sizeof( * V_45 ) , V_50 ) ;
if ( V_45 ) {
F_40 ( & V_45 -> V_43 , & V_2 -> V_51 ) ;
if ( ! F_41 () )
V_52 = V_45 ;
}
return V_45 ;
}
static void F_42 ( struct V_41 * V_45 )
{
if ( ! F_41 () )
V_52 = NULL ;
F_38 ( V_45 ) ;
}
static int F_43 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
struct V_41 * V_45 ;
unsigned int V_53 ;
int V_54 = 0 ;
if ( V_11 -> V_55 )
return - V_56 ;
V_2 = F_30 ( V_11 ) ;
if ( ! V_2 )
return - V_57 ;
F_20 ( & V_58 ) ;
if ( V_52 ) {
if ( F_44 ( F_41 () ) ) {
V_54 = - V_48 ;
goto V_59;
}
V_11 -> V_55 = V_2 ;
V_2 -> V_45 = V_52 ;
F_45 ( & V_52 -> V_43 , & V_2 -> V_51 ) ;
goto V_60;
}
V_45 = F_39 ( V_2 ) ;
if ( ! V_45 ) {
V_54 = - V_57 ;
goto V_59;
}
V_45 -> V_46 = V_61 ;
V_53 = V_11 -> V_21 . V_62 / V_49 ;
if ( V_53 )
V_45 -> V_46 *= V_53 ;
V_11 -> V_55 = V_2 ;
V_2 -> V_45 = V_45 ;
V_54 = F_46 ( & V_45 -> V_43 . V_63 , & V_64 ,
F_47 ( V_11 ) , L_2 ,
V_65 . V_66 ) ;
if ( V_54 )
goto V_67;
V_60:
F_22 ( & V_58 ) ;
F_48 ( V_11 ) ;
return 0 ;
V_67:
V_11 -> V_55 = NULL ;
F_42 ( V_45 ) ;
V_59:
F_22 ( & V_58 ) ;
F_36 ( V_2 ) ;
F_49 ( L_3 , V_54 ) ;
return V_54 ;
}
static void F_50 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_55 ;
struct V_41 * V_45 = V_2 -> V_45 ;
unsigned int V_47 ;
F_51 ( V_11 ) ;
F_20 ( & V_58 ) ;
V_47 = F_52 ( & V_45 -> V_43 , & V_2 -> V_51 ) ;
V_11 -> V_55 = NULL ;
if ( ! V_47 )
F_42 ( V_45 ) ;
F_22 ( & V_58 ) ;
F_36 ( V_2 ) ;
}
static int F_53 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_55 ;
unsigned int V_68 ;
V_2 -> V_9 = V_2 -> V_45 -> V_46 * V_49 ;
V_2 -> V_8 = 0 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_4 = false ;
V_2 -> V_5 = false ;
F_14 (cpu, policy->cpus) {
struct V_16 * V_17 = & F_15 ( V_16 , V_68 ) ;
V_17 -> V_2 = V_2 ;
if ( F_54 ( V_11 ) ) {
V_17 -> V_18 = V_28 ;
V_17 -> V_19 = 0 ;
V_17 -> V_34 = 0 ;
V_17 -> V_23 = 0 ;
F_55 ( V_68 , & V_17 -> V_26 ,
F_16 ) ;
} else {
F_55 ( V_68 , & V_17 -> V_26 ,
F_11 ) ;
}
}
return 0 ;
}
static void F_56 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_55 ;
unsigned int V_68 ;
F_14 (cpu, policy->cpus)
F_57 ( V_68 ) ;
F_58 () ;
F_59 ( & V_2 -> V_15 ) ;
F_60 ( & V_2 -> V_38 ) ;
}
static void F_61 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_55 ;
if ( ! V_11 -> V_12 ) {
F_20 ( & V_2 -> V_39 ) ;
F_62 ( V_11 ) ;
F_22 ( & V_2 -> V_39 ) ;
}
V_2 -> V_5 = true ;
}
static int T_5 F_63 ( void )
{
return F_64 ( & V_65 ) ;
}
static void T_6 F_65 ( void )
{
F_66 ( & V_65 ) ;
}
struct V_69 * F_67 ( void )
{
return & V_65 ;
}
