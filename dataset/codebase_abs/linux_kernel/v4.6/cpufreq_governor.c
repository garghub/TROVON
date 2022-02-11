T_1 F_1 ( struct V_1 * V_1 , const char * V_2 ,
T_2 V_3 )
{
struct V_4 * V_5 ;
unsigned int V_6 ;
int V_7 ;
V_7 = sscanf ( V_2 , L_1 , & V_6 ) ;
if ( V_7 != 1 )
return - V_8 ;
V_1 -> V_9 = F_2 ( V_6 , V_1 -> V_10 ) ;
F_3 (policy_dbs, &dbs_data->policy_dbs_list, list) {
F_4 ( & V_5 -> V_11 ) ;
F_5 ( V_5 , 0 ) ;
F_6 ( & V_5 -> V_11 ) ;
}
return V_3 ;
}
void F_7 ( struct V_1 * V_1 )
{
struct V_4 * V_5 ;
F_3 (policy_dbs, &dbs_data->policy_dbs_list, list) {
unsigned int V_12 ;
F_8 (j, policy_dbs->policy->cpus) {
struct V_13 * V_14 = & F_9 ( V_15 , V_12 ) ;
V_14 -> V_16 = F_10 ( V_12 , & V_14 -> V_17 ,
V_1 -> V_18 ) ;
if ( V_1 -> V_19 )
V_14 -> V_20 = F_11 ( V_12 ) . V_21 [ V_22 ] ;
}
}
}
static inline struct V_1 * F_12 ( struct V_23 * V_24 )
{
return F_13 ( V_24 , struct V_1 , V_24 ) ;
}
static inline struct V_25 * F_14 ( struct V_26 * V_27 )
{
return F_13 ( V_27 , struct V_25 , V_27 ) ;
}
static T_1 F_15 ( struct V_23 * V_24 , struct V_26 * V_27 ,
char * V_2 )
{
struct V_1 * V_1 = F_12 ( V_24 ) ;
struct V_25 * V_28 = F_14 ( V_27 ) ;
return V_28 -> V_29 ( V_1 , V_2 ) ;
}
static T_1 F_16 ( struct V_23 * V_24 , struct V_26 * V_27 ,
const char * V_2 , T_2 V_3 )
{
struct V_1 * V_1 = F_12 ( V_24 ) ;
struct V_25 * V_28 = F_14 ( V_27 ) ;
int V_7 = - V_30 ;
F_4 ( & V_1 -> V_31 ) ;
if ( V_1 -> V_32 )
V_7 = V_28 -> V_33 ( V_1 , V_2 , V_3 ) ;
F_6 ( & V_1 -> V_31 ) ;
return V_7 ;
}
unsigned int F_17 ( struct V_34 * V_35 )
{
struct V_4 * V_5 = V_35 -> V_36 ;
struct V_1 * V_1 = V_5 -> V_1 ;
unsigned int V_37 = V_1 -> V_19 ;
unsigned int V_38 = 0 ;
unsigned int V_9 , V_39 , V_12 ;
V_9 = V_1 -> V_9 * V_5 -> V_40 ;
V_39 = V_1 -> V_18 ;
F_8 (j, policy->cpus) {
struct V_13 * V_14 = & F_9 ( V_15 , V_12 ) ;
T_3 V_41 , V_42 ;
unsigned int V_43 , V_44 ;
unsigned int V_45 ;
V_42 = F_10 ( V_12 , & V_41 , V_39 ) ;
V_44 = V_41 - V_14 -> V_17 ;
V_14 -> V_17 = V_41 ;
V_43 = V_42 - V_14 -> V_16 ;
V_14 -> V_16 = V_42 ;
if ( V_37 ) {
T_3 V_46 = F_11 ( V_12 ) . V_21 [ V_22 ] ;
V_43 += F_18 ( V_46 - V_14 -> V_20 ) ;
V_14 -> V_20 = V_46 ;
}
if ( F_19 ( ! V_44 || V_44 < V_43 ) )
continue;
if ( F_19 ( V_44 > ( 2 * V_9 ) &&
V_14 -> V_47 ) ) {
V_45 = V_14 -> V_47 ;
V_14 -> V_47 = 0 ;
} else {
V_45 = 100 * ( V_44 - V_43 ) / V_44 ;
V_14 -> V_47 = V_45 ;
}
if ( V_45 > V_38 )
V_38 = V_45 ;
}
return V_38 ;
}
static void F_20 ( struct V_4 * V_5 ,
unsigned int V_48 )
{
struct V_34 * V_35 = V_5 -> V_35 ;
int V_49 ;
F_5 ( V_5 , V_48 ) ;
V_5 -> V_50 = 0 ;
F_8 (cpu, policy->cpus) {
struct V_13 * V_51 = & F_9 ( V_15 , V_49 ) ;
F_21 ( V_49 , & V_51 -> V_52 ) ;
}
}
static inline void F_22 ( struct V_34 * V_35 )
{
int V_53 ;
F_8 (i, policy->cpus)
F_21 ( V_53 , NULL ) ;
F_23 () ;
}
static void F_24 ( struct V_34 * V_35 )
{
struct V_4 * V_5 = V_35 -> V_36 ;
F_22 ( V_5 -> V_35 ) ;
F_25 ( & V_5 -> V_54 ) ;
F_26 ( & V_5 -> V_55 ) ;
F_27 ( & V_5 -> V_56 , 0 ) ;
V_5 -> V_57 = false ;
}
static void F_28 ( struct V_58 * V_55 )
{
struct V_4 * V_5 ;
struct V_34 * V_35 ;
struct V_59 * V_60 ;
V_5 = F_13 ( V_55 , struct V_4 , V_55 ) ;
V_35 = V_5 -> V_35 ;
V_60 = F_29 ( V_35 ) ;
F_4 ( & V_5 -> V_11 ) ;
F_5 ( V_5 , V_60 -> V_61 ( V_35 ) ) ;
F_6 ( & V_5 -> V_11 ) ;
F_27 ( & V_5 -> V_56 , 0 ) ;
F_30 () ;
V_5 -> V_57 = false ;
}
static void F_31 ( struct V_54 * V_54 )
{
struct V_4 * V_5 ;
V_5 = F_13 ( V_54 , struct V_4 , V_54 ) ;
F_32 ( F_33 () , & V_5 -> V_55 ) ;
}
static void F_34 ( struct V_62 * V_63 , T_3 time ,
unsigned long V_64 , unsigned long F_2 )
{
struct V_13 * V_51 = F_13 ( V_63 , struct V_13 , V_52 ) ;
struct V_4 * V_5 = V_51 -> V_5 ;
T_3 V_65 , V_66 ;
if ( V_5 -> V_57 )
return;
F_35 () ;
V_66 = F_36 ( V_5 -> V_50 ) ;
V_65 = time - V_66 ;
if ( ( V_67 ) V_65 < V_5 -> V_68 )
return;
if ( V_5 -> V_69 ) {
if ( ! F_37 ( & V_5 -> V_56 , 1 , 1 ) )
return;
if ( F_19 ( V_66 != F_36 ( V_5 -> V_50 ) ) ) {
F_27 ( & V_5 -> V_56 , 0 ) ;
return;
}
}
V_5 -> V_50 = time ;
V_5 -> V_57 = true ;
F_38 ( & V_5 -> V_54 ) ;
}
static struct V_4 * F_39 ( struct V_34 * V_35 ,
struct V_59 * V_60 )
{
struct V_4 * V_5 ;
int V_12 ;
V_5 = V_60 -> V_70 () ;
if ( ! V_5 )
return NULL ;
V_5 -> V_35 = V_35 ;
F_40 ( & V_5 -> V_11 ) ;
F_27 ( & V_5 -> V_56 , 0 ) ;
F_41 ( & V_5 -> V_54 , F_31 ) ;
F_42 ( & V_5 -> V_55 , F_28 ) ;
F_8 (j, policy->related_cpus) {
struct V_13 * V_14 = & F_9 ( V_15 , V_12 ) ;
V_14 -> V_5 = V_5 ;
V_14 -> V_52 . V_71 = F_34 ;
}
return V_5 ;
}
static void F_43 ( struct V_4 * V_5 ,
struct V_59 * V_60 )
{
int V_12 ;
F_44 ( & V_5 -> V_11 ) ;
F_8 (j, policy_dbs->policy->related_cpus) {
struct V_13 * V_14 = & F_9 ( V_15 , V_12 ) ;
V_14 -> V_5 = NULL ;
V_14 -> V_52 . V_71 = NULL ;
}
V_60 -> free ( V_5 ) ;
}
static int F_45 ( struct V_34 * V_35 )
{
struct V_59 * V_60 = F_29 ( V_35 ) ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
unsigned int V_72 ;
int V_7 = 0 ;
if ( V_35 -> V_36 )
return - V_30 ;
V_5 = F_39 ( V_35 , V_60 ) ;
if ( ! V_5 )
return - V_73 ;
F_4 ( & V_74 ) ;
V_1 = V_60 -> V_75 ;
if ( V_1 ) {
if ( F_46 ( F_47 () ) ) {
V_7 = - V_8 ;
goto F_43;
}
V_5 -> V_1 = V_1 ;
V_35 -> V_36 = V_5 ;
F_4 ( & V_1 -> V_31 ) ;
V_1 -> V_32 ++ ;
F_48 ( & V_5 -> V_76 , & V_1 -> V_77 ) ;
F_6 ( & V_1 -> V_31 ) ;
goto V_78;
}
V_1 = F_49 ( sizeof( * V_1 ) , V_79 ) ;
if ( ! V_1 ) {
V_7 = - V_73 ;
goto F_43;
}
F_50 ( & V_1 -> V_77 ) ;
F_40 ( & V_1 -> V_31 ) ;
V_7 = V_60 -> V_80 ( V_1 , ! V_35 -> V_81 -> V_82 ) ;
if ( V_7 )
goto F_43;
V_72 = V_35 -> V_83 . V_84 / 1000 ;
if ( V_72 == 0 )
V_72 = 1 ;
V_1 -> V_10 = F_2 ( V_1 -> V_10 ,
V_85 * V_72 ) ;
V_1 -> V_9 = F_2 ( V_1 -> V_10 ,
V_86 * V_72 ) ;
if ( ! F_47 () )
V_60 -> V_75 = V_1 ;
V_35 -> V_36 = V_5 ;
V_5 -> V_1 = V_1 ;
V_1 -> V_32 = 1 ;
F_48 ( & V_5 -> V_76 , & V_1 -> V_77 ) ;
V_60 -> V_87 . V_88 = & V_89 ;
V_7 = F_51 ( & V_1 -> V_24 , & V_60 -> V_87 ,
F_52 ( V_35 ) ,
L_2 , V_60 -> V_60 . V_90 ) ;
if ( ! V_7 )
goto V_78;
F_53 ( L_3 , V_7 ) ;
V_35 -> V_36 = NULL ;
if ( ! F_47 () )
V_60 -> V_75 = NULL ;
V_60 -> exit ( V_1 , ! V_35 -> V_81 -> V_82 ) ;
F_54 ( V_1 ) ;
F_43:
F_43 ( V_5 , V_60 ) ;
V_78:
F_6 ( & V_74 ) ;
return V_7 ;
}
static int F_55 ( struct V_34 * V_35 )
{
struct V_59 * V_60 = F_29 ( V_35 ) ;
struct V_4 * V_5 = V_35 -> V_36 ;
struct V_1 * V_1 = V_5 -> V_1 ;
int V_3 ;
F_4 ( & V_74 ) ;
F_4 ( & V_1 -> V_31 ) ;
F_56 ( & V_5 -> V_76 ) ;
V_3 = -- V_1 -> V_32 ;
F_6 ( & V_1 -> V_31 ) ;
if ( ! V_3 ) {
F_57 ( & V_1 -> V_24 ) ;
V_35 -> V_36 = NULL ;
if ( ! F_47 () )
V_60 -> V_75 = NULL ;
V_60 -> exit ( V_1 , V_35 -> V_81 -> V_82 == 1 ) ;
F_44 ( & V_1 -> V_31 ) ;
F_54 ( V_1 ) ;
} else {
V_35 -> V_36 = NULL ;
}
F_43 ( V_5 , V_60 ) ;
F_6 ( & V_74 ) ;
return 0 ;
}
static int F_58 ( struct V_34 * V_35 )
{
struct V_59 * V_60 = F_29 ( V_35 ) ;
struct V_4 * V_5 = V_35 -> V_36 ;
struct V_1 * V_1 = V_5 -> V_1 ;
unsigned int V_9 , V_37 , V_12 ;
unsigned int V_39 ;
if ( ! V_35 -> V_91 )
return - V_8 ;
V_5 -> V_69 = F_59 ( V_35 ) ;
V_5 -> V_40 = 1 ;
V_9 = V_1 -> V_9 ;
V_37 = V_1 -> V_19 ;
V_39 = V_1 -> V_18 ;
F_8 (j, policy->cpus) {
struct V_13 * V_14 = & F_9 ( V_15 , V_12 ) ;
unsigned int V_47 ;
V_14 -> V_16 = F_10 ( V_12 , & V_14 -> V_17 , V_39 ) ;
V_47 = V_14 -> V_17 - V_14 -> V_16 ;
V_14 -> V_47 = 100 * V_47 / ( unsigned int ) V_14 -> V_17 ;
if ( V_37 )
V_14 -> V_20 = F_11 ( V_12 ) . V_21 [ V_22 ] ;
}
V_60 -> V_92 ( V_35 ) ;
F_20 ( V_5 , V_9 ) ;
return 0 ;
}
static int F_60 ( struct V_34 * V_35 )
{
F_24 ( V_35 ) ;
return 0 ;
}
static int F_61 ( struct V_34 * V_35 )
{
struct V_4 * V_5 = V_35 -> V_36 ;
F_4 ( & V_5 -> V_11 ) ;
if ( V_35 -> F_2 < V_35 -> V_91 )
F_62 ( V_35 , V_35 -> F_2 , V_93 ) ;
else if ( V_35 -> V_94 > V_35 -> V_91 )
F_62 ( V_35 , V_35 -> V_94 , V_95 ) ;
F_5 ( V_5 , 0 ) ;
F_6 ( & V_5 -> V_11 ) ;
return 0 ;
}
int F_63 ( struct V_34 * V_35 , unsigned int V_96 )
{
if ( V_96 == V_97 ) {
return F_45 ( V_35 ) ;
} else if ( V_35 -> V_36 ) {
switch ( V_96 ) {
case V_98 :
return F_55 ( V_35 ) ;
case V_99 :
return F_58 ( V_35 ) ;
case V_100 :
return F_60 ( V_35 ) ;
case V_101 :
return F_61 ( V_35 ) ;
}
}
return - V_8 ;
}
