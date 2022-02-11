T_1 F_1 ( struct V_1 * V_2 , const char * V_3 ,
T_2 V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
unsigned int V_8 ;
int V_9 ;
V_9 = sscanf ( V_3 , L_1 , & V_8 ) ;
if ( V_9 != 1 )
return - V_10 ;
V_5 -> V_11 = F_3 ( V_8 , V_5 -> V_12 ) ;
F_4 (policy_dbs, &attr_set->policy_list, list) {
F_5 ( & V_7 -> V_13 ) ;
F_6 ( V_7 , 0 ) ;
F_7 ( & V_7 -> V_13 ) ;
}
return V_4 ;
}
void F_8 ( struct V_5 * V_5 )
{
struct V_6 * V_7 ;
F_4 (policy_dbs, &dbs_data->attr_set.policy_list, list) {
unsigned int V_14 ;
F_9 (j, policy_dbs->policy->cpus) {
struct V_15 * V_16 = & F_10 ( V_17 , V_14 ) ;
V_16 -> V_18 = F_11 ( V_14 , & V_16 -> V_19 ,
V_5 -> V_20 ) ;
if ( V_5 -> V_21 )
V_16 -> V_22 = F_12 ( V_14 ) . V_23 [ V_24 ] ;
}
}
}
unsigned int F_13 ( struct V_25 * V_26 )
{
struct V_6 * V_7 = V_26 -> V_27 ;
struct V_5 * V_5 = V_7 -> V_5 ;
unsigned int V_28 = V_5 -> V_21 ;
unsigned int V_29 = 0 , V_30 = V_31 ;
unsigned int V_11 , V_32 , V_14 ;
V_11 = V_5 -> V_11 * V_7 -> V_33 ;
V_32 = V_5 -> V_20 ;
F_9 (j, policy->cpus) {
struct V_15 * V_16 = & F_10 ( V_17 , V_14 ) ;
T_3 V_34 , V_35 ;
unsigned int V_36 , V_37 ;
unsigned int V_38 ;
V_35 = F_11 ( V_14 , & V_34 , V_32 ) ;
V_37 = V_34 - V_16 -> V_19 ;
V_16 -> V_19 = V_34 ;
V_36 = V_35 - V_16 -> V_18 ;
V_16 -> V_18 = V_35 ;
if ( V_28 ) {
T_3 V_39 = F_12 ( V_14 ) . V_23 [ V_24 ] ;
V_36 += F_14 ( V_39 - V_16 -> V_22 ) ;
V_16 -> V_22 = V_39 ;
}
if ( F_15 ( ! V_37 ) ) {
V_38 = V_16 -> V_40 ;
} else if ( F_15 ( V_37 > 2 * V_11 &&
V_16 -> V_40 ) ) {
V_38 = V_16 -> V_40 ;
V_16 -> V_40 = 0 ;
} else {
if ( V_37 >= V_36 ) {
V_38 = 100 * ( V_37 - V_36 ) / V_37 ;
} else {
V_38 = ( int ) V_36 < 0 ? 100 : 0 ;
}
V_16 -> V_40 = V_38 ;
}
if ( V_37 > 2 * V_11 ) {
unsigned int V_41 = V_37 / V_11 ;
if ( V_41 < V_30 )
V_30 = V_41 ;
}
if ( V_38 > V_29 )
V_29 = V_38 ;
}
V_7 -> V_30 = V_30 ;
return V_29 ;
}
static void F_16 ( struct V_42 * V_43 )
{
struct V_6 * V_7 ;
struct V_25 * V_26 ;
struct V_44 * V_45 ;
V_7 = F_17 ( V_43 , struct V_6 , V_43 ) ;
V_26 = V_7 -> V_26 ;
V_45 = F_18 ( V_26 ) ;
F_5 ( & V_7 -> V_13 ) ;
F_6 ( V_7 , V_45 -> V_46 ( V_26 ) ) ;
F_7 ( & V_7 -> V_13 ) ;
F_19 ( & V_7 -> V_47 , 0 ) ;
F_20 () ;
V_7 -> V_48 = false ;
}
static void F_21 ( struct V_49 * V_49 )
{
struct V_6 * V_7 ;
V_7 = F_17 ( V_49 , struct V_6 , V_49 ) ;
F_22 ( F_23 () , & V_7 -> V_43 ) ;
}
static void F_24 ( struct V_50 * V_51 , T_3 time ,
unsigned int V_52 )
{
struct V_15 * V_53 = F_17 ( V_51 , struct V_15 , V_54 ) ;
struct V_6 * V_7 = V_53 -> V_7 ;
T_3 V_55 , V_56 ;
if ( V_7 -> V_48 )
return;
F_25 () ;
V_56 = F_26 ( V_7 -> V_57 ) ;
V_55 = time - V_56 ;
if ( ( V_58 ) V_55 < V_7 -> V_59 )
return;
if ( V_7 -> V_60 ) {
if ( ! F_27 ( & V_7 -> V_47 , 1 , 1 ) )
return;
if ( F_15 ( V_56 != F_26 ( V_7 -> V_57 ) ) ) {
F_19 ( & V_7 -> V_47 , 0 ) ;
return;
}
}
V_7 -> V_57 = time ;
V_7 -> V_48 = true ;
F_28 ( & V_7 -> V_49 ) ;
}
static void F_29 ( struct V_6 * V_7 ,
unsigned int V_61 )
{
struct V_25 * V_26 = V_7 -> V_26 ;
int V_62 ;
F_6 ( V_7 , V_61 ) ;
V_7 -> V_57 = 0 ;
F_9 (cpu, policy->cpus) {
struct V_15 * V_53 = & F_10 ( V_17 , V_62 ) ;
F_30 ( V_62 , & V_53 -> V_54 ,
F_24 ) ;
}
}
static inline void F_31 ( struct V_25 * V_26 )
{
int V_63 ;
F_9 (i, policy->cpus)
F_32 ( V_63 ) ;
F_33 () ;
}
static struct V_6 * F_34 ( struct V_25 * V_26 ,
struct V_44 * V_45 )
{
struct V_6 * V_7 ;
int V_14 ;
V_7 = V_45 -> V_64 () ;
if ( ! V_7 )
return NULL ;
V_7 -> V_26 = V_26 ;
F_35 ( & V_7 -> V_13 ) ;
F_19 ( & V_7 -> V_47 , 0 ) ;
F_36 ( & V_7 -> V_49 , F_21 ) ;
F_37 ( & V_7 -> V_43 , F_16 ) ;
F_9 (j, policy->related_cpus) {
struct V_15 * V_16 = & F_10 ( V_17 , V_14 ) ;
V_16 -> V_7 = V_7 ;
}
return V_7 ;
}
static void F_38 ( struct V_6 * V_7 ,
struct V_44 * V_45 )
{
int V_14 ;
F_39 ( & V_7 -> V_13 ) ;
F_9 (j, policy_dbs->policy->related_cpus) {
struct V_15 * V_16 = & F_10 ( V_17 , V_14 ) ;
V_16 -> V_7 = NULL ;
V_16 -> V_54 . V_65 = NULL ;
}
V_45 -> free ( V_7 ) ;
}
int F_40 ( struct V_25 * V_26 )
{
struct V_44 * V_45 = F_18 ( V_26 ) ;
struct V_5 * V_5 ;
struct V_6 * V_7 ;
unsigned int V_66 ;
int V_9 = 0 ;
if ( V_26 -> V_27 )
return - V_67 ;
V_7 = F_34 ( V_26 , V_45 ) ;
if ( ! V_7 )
return - V_68 ;
F_5 ( & V_69 ) ;
V_5 = V_45 -> V_70 ;
if ( V_5 ) {
if ( F_41 ( F_42 () ) ) {
V_9 = - V_10 ;
goto F_38;
}
V_7 -> V_5 = V_5 ;
V_26 -> V_27 = V_7 ;
F_43 ( & V_5 -> V_2 , & V_7 -> V_71 ) ;
goto V_72;
}
V_5 = F_44 ( sizeof( * V_5 ) , V_73 ) ;
if ( ! V_5 ) {
V_9 = - V_68 ;
goto F_38;
}
F_45 ( & V_5 -> V_2 , & V_7 -> V_71 ) ;
V_9 = V_45 -> V_74 ( V_5 ) ;
if ( V_9 )
goto F_38;
V_66 = V_26 -> V_75 . V_76 / 1000 ;
if ( V_66 == 0 )
V_66 = 1 ;
V_5 -> V_12 = F_3 ( V_5 -> V_12 ,
V_77 * V_66 ) ;
V_5 -> V_11 = F_3 ( V_5 -> V_12 ,
V_78 * V_66 ) ;
if ( ! F_42 () )
V_45 -> V_70 = V_5 ;
V_7 -> V_5 = V_5 ;
V_26 -> V_27 = V_7 ;
V_45 -> V_79 . V_80 = & V_81 ;
V_9 = F_46 ( & V_5 -> V_2 . V_82 , & V_45 -> V_79 ,
F_47 ( V_26 ) ,
L_2 , V_45 -> V_45 . V_83 ) ;
if ( ! V_9 )
goto V_72;
F_48 ( L_3 , V_9 ) ;
V_26 -> V_27 = NULL ;
if ( ! F_42 () )
V_45 -> V_70 = NULL ;
V_45 -> exit ( V_5 ) ;
F_49 ( V_5 ) ;
F_38:
F_38 ( V_7 , V_45 ) ;
V_72:
F_7 ( & V_69 ) ;
return V_9 ;
}
void F_50 ( struct V_25 * V_26 )
{
struct V_44 * V_45 = F_18 ( V_26 ) ;
struct V_6 * V_7 = V_26 -> V_27 ;
struct V_5 * V_5 = V_7 -> V_5 ;
unsigned int V_4 ;
F_5 ( & V_69 ) ;
V_4 = F_51 ( & V_5 -> V_2 , & V_7 -> V_71 ) ;
V_26 -> V_27 = NULL ;
if ( ! V_4 ) {
if ( ! F_42 () )
V_45 -> V_70 = NULL ;
V_45 -> exit ( V_5 ) ;
F_49 ( V_5 ) ;
}
F_38 ( V_7 , V_45 ) ;
F_7 ( & V_69 ) ;
}
int F_52 ( struct V_25 * V_26 )
{
struct V_44 * V_45 = F_18 ( V_26 ) ;
struct V_6 * V_7 = V_26 -> V_27 ;
struct V_5 * V_5 = V_7 -> V_5 ;
unsigned int V_11 , V_28 , V_14 ;
unsigned int V_32 ;
if ( ! V_26 -> V_84 )
return - V_10 ;
V_7 -> V_60 = F_53 ( V_26 ) ;
V_7 -> V_33 = 1 ;
V_11 = V_5 -> V_11 ;
V_28 = V_5 -> V_21 ;
V_32 = V_5 -> V_20 ;
F_9 (j, policy->cpus) {
struct V_15 * V_16 = & F_10 ( V_17 , V_14 ) ;
V_16 -> V_18 = F_11 ( V_14 , & V_16 -> V_19 , V_32 ) ;
V_16 -> V_40 = 0 ;
if ( V_28 )
V_16 -> V_22 = F_12 ( V_14 ) . V_23 [ V_24 ] ;
}
V_45 -> V_85 ( V_26 ) ;
F_29 ( V_7 , V_11 ) ;
return 0 ;
}
void F_54 ( struct V_25 * V_26 )
{
struct V_6 * V_7 = V_26 -> V_27 ;
F_31 ( V_7 -> V_26 ) ;
F_55 ( & V_7 -> V_49 ) ;
F_56 ( & V_7 -> V_43 ) ;
F_19 ( & V_7 -> V_47 , 0 ) ;
V_7 -> V_48 = false ;
}
void F_57 ( struct V_25 * V_26 )
{
struct V_6 * V_7 = V_26 -> V_27 ;
F_5 ( & V_7 -> V_13 ) ;
F_58 ( V_26 ) ;
F_6 ( V_7 , 0 ) ;
F_7 ( & V_7 -> V_13 ) ;
}
