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
static unsigned int F_8 ( struct V_10 * V_11 ,
unsigned long V_16 , unsigned long V_17 )
{
unsigned int V_18 = F_9 () ?
V_11 -> V_19 . V_20 : V_11 -> V_13 ;
return ( V_18 + ( V_18 >> 2 ) ) * V_16 / V_17 ;
}
static void F_10 ( struct V_21 * V_22 , T_1 time ,
unsigned long V_16 , unsigned long V_17 )
{
struct V_23 * V_24 = F_11 ( V_22 , struct V_23 , V_25 ) ;
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_26 ;
if ( ! F_1 ( V_2 , time ) )
return;
V_26 = V_16 == V_27 ? V_11 -> V_19 . V_20 :
F_8 ( V_11 , V_16 , V_17 ) ;
F_3 ( V_2 , time , V_26 ) ;
}
static unsigned int F_12 ( struct V_1 * V_2 ,
unsigned long V_16 , unsigned long V_17 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_28 = V_11 -> V_19 . V_20 ;
T_1 V_8 = V_2 -> V_8 ;
unsigned int V_29 ;
if ( V_16 == V_27 )
return V_28 ;
F_13 (j, policy->cpus) {
struct V_23 * V_30 ;
unsigned long V_31 , V_32 ;
T_2 V_3 ;
if ( V_29 == F_5 () )
continue;
V_30 = & F_14 ( V_23 , V_29 ) ;
V_3 = V_8 - V_30 -> V_33 ;
if ( V_3 > V_34 )
continue;
V_31 = V_30 -> V_16 ;
if ( V_31 == V_27 )
return V_28 ;
V_32 = V_30 -> V_17 ;
if ( V_31 * V_17 > V_32 * V_16 ) {
V_16 = V_31 ;
V_17 = V_32 ;
}
}
return F_8 ( V_11 , V_16 , V_17 ) ;
}
static void F_15 ( struct V_21 * V_22 , T_1 time ,
unsigned long V_16 , unsigned long V_17 )
{
struct V_23 * V_24 = F_11 ( V_22 , struct V_23 , V_25 ) ;
struct V_1 * V_2 = V_24 -> V_2 ;
unsigned int V_26 ;
F_16 ( & V_2 -> V_35 ) ;
V_24 -> V_16 = V_16 ;
V_24 -> V_17 = V_17 ;
V_24 -> V_33 = time ;
if ( F_1 ( V_2 , time ) ) {
V_26 = F_12 ( V_2 , V_16 , V_17 ) ;
F_3 ( V_2 , time , V_26 ) ;
}
F_17 ( & V_2 -> V_35 ) ;
}
static void F_18 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_11 ( V_37 , struct V_1 , V_37 ) ;
F_19 ( & V_2 -> V_38 ) ;
F_20 ( V_2 -> V_11 , V_2 -> V_6 ,
V_39 ) ;
F_21 ( & V_2 -> V_38 ) ;
V_2 -> V_4 = false ;
}
static void F_22 ( struct V_15 * V_15 )
{
struct V_1 * V_2 ;
V_2 = F_11 ( V_15 , struct V_1 , V_15 ) ;
F_23 ( F_5 () , & V_2 -> V_37 ) ;
}
static inline struct V_40 * F_24 ( struct V_41 * V_42 )
{
return F_11 ( V_42 , struct V_40 , V_42 ) ;
}
static T_3 F_25 ( struct V_41 * V_42 , char * V_43 )
{
struct V_40 * V_44 = F_24 ( V_42 ) ;
return sprintf ( V_43 , L_1 , V_44 -> V_45 ) ;
}
static T_3 F_26 ( struct V_41 * V_42 , const char * V_43 ,
T_4 V_46 )
{
struct V_40 * V_44 = F_24 ( V_42 ) ;
struct V_1 * V_2 ;
unsigned int V_45 ;
if ( F_27 ( V_43 , 10 , & V_45 ) )
return - V_47 ;
V_44 -> V_45 = V_45 ;
F_28 (sg_policy, &attr_set->policy_list, tunables_hook)
V_2 -> V_9 = V_45 * V_48 ;
return V_46 ;
}
static struct V_1 * F_29 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
V_2 = F_30 ( sizeof( * V_2 ) , V_49 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = V_11 ;
F_31 ( & V_2 -> V_15 , F_22 ) ;
F_32 ( & V_2 -> V_37 , F_18 ) ;
F_33 ( & V_2 -> V_38 ) ;
F_34 ( & V_2 -> V_35 ) ;
return V_2 ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_38 ) ;
F_37 ( V_2 ) ;
}
static struct V_40 * F_38 ( struct V_1 * V_2 )
{
struct V_40 * V_44 ;
V_44 = F_30 ( sizeof( * V_44 ) , V_49 ) ;
if ( V_44 ) {
F_39 ( & V_44 -> V_42 , & V_2 -> V_50 ) ;
if ( ! F_40 () )
V_51 = V_44 ;
}
return V_44 ;
}
static void F_41 ( struct V_40 * V_44 )
{
if ( ! F_40 () )
V_51 = NULL ;
F_37 ( V_44 ) ;
}
static int F_42 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
struct V_40 * V_44 ;
unsigned int V_52 ;
int V_53 = 0 ;
if ( V_11 -> V_54 )
return - V_55 ;
V_2 = F_29 ( V_11 ) ;
if ( ! V_2 )
return - V_56 ;
F_19 ( & V_57 ) ;
if ( V_51 ) {
if ( F_43 ( F_40 () ) ) {
V_53 = - V_47 ;
goto V_58;
}
V_11 -> V_54 = V_2 ;
V_2 -> V_44 = V_51 ;
F_44 ( & V_51 -> V_42 , & V_2 -> V_50 ) ;
goto V_59;
}
V_44 = F_38 ( V_2 ) ;
if ( ! V_44 ) {
V_53 = - V_56 ;
goto V_58;
}
V_44 -> V_45 = V_60 ;
V_52 = V_11 -> V_19 . V_61 / V_48 ;
if ( V_52 )
V_44 -> V_45 *= V_52 ;
V_11 -> V_54 = V_2 ;
V_2 -> V_44 = V_44 ;
V_53 = F_45 ( & V_44 -> V_42 . V_62 , & V_63 ,
F_46 ( V_11 ) , L_2 ,
V_64 . V_65 ) ;
if ( V_53 )
goto V_66;
V_59:
F_21 ( & V_57 ) ;
F_47 ( V_11 ) ;
return 0 ;
V_66:
V_11 -> V_54 = NULL ;
F_41 ( V_44 ) ;
V_58:
F_21 ( & V_57 ) ;
F_35 ( V_2 ) ;
F_48 ( L_3 , V_53 ) ;
return V_53 ;
}
static int F_49 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_54 ;
struct V_40 * V_44 = V_2 -> V_44 ;
unsigned int V_46 ;
F_50 ( V_11 ) ;
F_19 ( & V_57 ) ;
V_46 = F_51 ( & V_44 -> V_42 , & V_2 -> V_50 ) ;
V_11 -> V_54 = NULL ;
if ( ! V_46 )
F_41 ( V_44 ) ;
F_21 ( & V_57 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
static int F_52 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_54 ;
unsigned int V_67 ;
V_2 -> V_9 = V_2 -> V_44 -> V_45 * V_48 ;
V_2 -> V_8 = 0 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_4 = false ;
V_2 -> V_5 = false ;
F_13 (cpu, policy->cpus) {
struct V_23 * V_24 = & F_14 ( V_23 , V_67 ) ;
V_24 -> V_2 = V_2 ;
if ( F_53 ( V_11 ) ) {
V_24 -> V_16 = V_27 ;
V_24 -> V_17 = 0 ;
V_24 -> V_33 = 0 ;
F_54 ( V_67 , & V_24 -> V_25 ,
F_15 ) ;
} else {
F_54 ( V_67 , & V_24 -> V_25 ,
F_10 ) ;
}
}
return 0 ;
}
static int F_55 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_54 ;
unsigned int V_67 ;
F_13 (cpu, policy->cpus)
F_56 ( V_67 ) ;
F_57 () ;
F_58 ( & V_2 -> V_15 ) ;
F_59 ( & V_2 -> V_37 ) ;
return 0 ;
}
static int F_60 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_54 ;
if ( ! V_11 -> V_12 ) {
F_19 ( & V_2 -> V_38 ) ;
if ( V_11 -> V_17 < V_11 -> V_13 )
F_20 ( V_11 , V_11 -> V_17 ,
V_68 ) ;
else if ( V_11 -> V_69 > V_11 -> V_13 )
F_20 ( V_11 , V_11 -> V_69 ,
V_39 ) ;
F_21 ( & V_2 -> V_38 ) ;
}
V_2 -> V_5 = true ;
return 0 ;
}
int F_61 ( struct V_10 * V_11 , unsigned int V_70 )
{
if ( V_70 == V_71 ) {
return F_42 ( V_11 ) ;
} else if ( V_11 -> V_54 ) {
switch ( V_70 ) {
case V_72 :
return F_49 ( V_11 ) ;
case V_73 :
return F_52 ( V_11 ) ;
case V_74 :
return F_55 ( V_11 ) ;
case V_75 :
return F_60 ( V_11 ) ;
}
}
return - V_47 ;
}
static int T_5 F_62 ( void )
{
return F_63 ( & V_64 ) ;
}
static void T_6 F_64 ( void )
{
F_65 ( & V_64 ) ;
}
struct V_76 * F_66 ( void )
{
return & V_64 ;
}
