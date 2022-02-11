T_1 F_1 ( struct V_1 * V_2 , const char * V_3 ,
T_2 V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
int V_8 ;
V_8 = sscanf ( V_3 , L_1 , & V_5 -> V_9 ) ;
if ( V_8 != 1 )
return - V_10 ;
F_3 (policy_dbs, &attr_set->policy_list, list) {
F_4 ( & V_7 -> V_11 ) ;
F_5 ( V_7 , 0 ) ;
F_6 ( & V_7 -> V_11 ) ;
}
return V_4 ;
}
void F_7 ( struct V_5 * V_5 )
{
struct V_6 * V_7 ;
F_3 (policy_dbs, &dbs_data->attr_set.policy_list, list) {
unsigned int V_12 ;
F_8 (j, policy_dbs->policy->cpus) {
struct V_13 * V_14 = & F_9 ( V_15 , V_12 ) ;
V_14 -> V_16 = F_10 ( V_12 , & V_14 -> V_17 ,
V_5 -> V_18 ) ;
if ( V_5 -> V_19 )
V_14 -> V_20 = F_11 ( V_12 ) . V_21 [ V_22 ] ;
}
}
}
unsigned int F_12 ( struct V_23 * V_24 )
{
struct V_6 * V_7 = V_24 -> V_25 ;
struct V_5 * V_5 = V_7 -> V_5 ;
unsigned int V_26 = V_5 -> V_19 ;
unsigned int V_27 = 0 , V_28 = V_29 ;
unsigned int V_9 , V_30 , V_12 ;
V_9 = V_5 -> V_9 * V_7 -> V_31 ;
V_30 = V_5 -> V_18 ;
F_8 (j, policy->cpus) {
struct V_13 * V_14 = & F_9 ( V_15 , V_12 ) ;
T_3 V_32 , V_33 ;
unsigned int V_34 , V_35 ;
unsigned int V_36 ;
V_33 = F_10 ( V_12 , & V_32 , V_30 ) ;
V_35 = V_32 - V_14 -> V_17 ;
V_14 -> V_17 = V_32 ;
V_34 = V_33 - V_14 -> V_16 ;
V_14 -> V_16 = V_33 ;
if ( V_26 ) {
T_3 V_37 = F_11 ( V_12 ) . V_21 [ V_22 ] ;
V_34 += F_13 ( V_37 - V_14 -> V_20 , V_38 ) ;
V_14 -> V_20 = V_37 ;
}
if ( F_14 ( ! V_35 ) ) {
V_36 = V_14 -> V_39 ;
} else if ( F_14 ( V_35 > 2 * V_9 &&
V_14 -> V_39 ) ) {
V_36 = V_14 -> V_39 ;
V_14 -> V_39 = 0 ;
} else {
if ( V_35 >= V_34 ) {
V_36 = 100 * ( V_35 - V_34 ) / V_35 ;
} else {
V_36 = ( int ) V_34 < 0 ? 100 : 0 ;
}
V_14 -> V_39 = V_36 ;
}
if ( V_35 > 2 * V_9 ) {
unsigned int V_40 = V_35 / V_9 ;
if ( V_40 < V_28 )
V_28 = V_40 ;
}
if ( V_36 > V_27 )
V_27 = V_36 ;
}
V_7 -> V_28 = V_28 ;
return V_27 ;
}
static void F_15 ( struct V_41 * V_42 )
{
struct V_6 * V_7 ;
struct V_23 * V_24 ;
struct V_43 * V_44 ;
V_7 = F_16 ( V_42 , struct V_6 , V_42 ) ;
V_24 = V_7 -> V_24 ;
V_44 = F_17 ( V_24 ) ;
F_4 ( & V_7 -> V_11 ) ;
F_5 ( V_7 , V_44 -> V_45 ( V_24 ) ) ;
F_6 ( & V_7 -> V_11 ) ;
F_18 ( & V_7 -> V_46 , 0 ) ;
F_19 () ;
V_7 -> V_47 = false ;
}
static void F_20 ( struct V_48 * V_48 )
{
struct V_6 * V_7 ;
V_7 = F_16 ( V_48 , struct V_6 , V_48 ) ;
F_21 ( F_22 () , & V_7 -> V_42 ) ;
}
static void F_23 ( struct V_49 * V_50 , T_3 time ,
unsigned int V_51 )
{
struct V_13 * V_52 = F_16 ( V_50 , struct V_13 , V_53 ) ;
struct V_6 * V_7 = V_52 -> V_7 ;
T_3 V_54 , V_55 ;
if ( ! F_24 ( V_7 -> V_24 ) )
return;
if ( V_7 -> V_47 )
return;
F_25 () ;
V_55 = F_26 ( V_7 -> V_56 ) ;
V_54 = time - V_55 ;
if ( ( V_57 ) V_54 < V_7 -> V_58 )
return;
if ( V_7 -> V_59 ) {
if ( ! F_27 ( & V_7 -> V_46 , 1 , 1 ) )
return;
if ( F_14 ( V_55 != F_26 ( V_7 -> V_56 ) ) ) {
F_18 ( & V_7 -> V_46 , 0 ) ;
return;
}
}
V_7 -> V_56 = time ;
V_7 -> V_47 = true ;
F_28 ( & V_7 -> V_48 ) ;
}
static void F_29 ( struct V_6 * V_7 ,
unsigned int V_60 )
{
struct V_23 * V_24 = V_7 -> V_24 ;
int V_61 ;
F_5 ( V_7 , V_60 ) ;
V_7 -> V_56 = 0 ;
F_8 (cpu, policy->cpus) {
struct V_13 * V_52 = & F_9 ( V_15 , V_61 ) ;
F_30 ( V_61 , & V_52 -> V_53 ,
F_23 ) ;
}
}
static inline void F_31 ( struct V_23 * V_24 )
{
int V_62 ;
F_8 (i, policy->cpus)
F_32 ( V_62 ) ;
F_33 () ;
}
static struct V_6 * F_34 ( struct V_23 * V_24 ,
struct V_43 * V_44 )
{
struct V_6 * V_7 ;
int V_12 ;
V_7 = V_44 -> V_63 () ;
if ( ! V_7 )
return NULL ;
V_7 -> V_24 = V_24 ;
F_35 ( & V_7 -> V_11 ) ;
F_18 ( & V_7 -> V_46 , 0 ) ;
F_36 ( & V_7 -> V_48 , F_20 ) ;
F_37 ( & V_7 -> V_42 , F_15 ) ;
F_8 (j, policy->related_cpus) {
struct V_13 * V_14 = & F_9 ( V_15 , V_12 ) ;
V_14 -> V_7 = V_7 ;
}
return V_7 ;
}
static void F_38 ( struct V_6 * V_7 ,
struct V_43 * V_44 )
{
int V_12 ;
F_39 ( & V_7 -> V_11 ) ;
F_8 (j, policy_dbs->policy->related_cpus) {
struct V_13 * V_14 = & F_9 ( V_15 , V_12 ) ;
V_14 -> V_7 = NULL ;
V_14 -> V_53 . V_64 = NULL ;
}
V_44 -> free ( V_7 ) ;
}
int F_40 ( struct V_23 * V_24 )
{
struct V_43 * V_44 = F_17 ( V_24 ) ;
struct V_5 * V_5 ;
struct V_6 * V_7 ;
int V_8 = 0 ;
if ( V_24 -> V_25 )
return - V_65 ;
V_7 = F_34 ( V_24 , V_44 ) ;
if ( ! V_7 )
return - V_66 ;
F_4 ( & V_67 ) ;
V_5 = V_44 -> V_68 ;
if ( V_5 ) {
if ( F_41 ( F_42 () ) ) {
V_8 = - V_10 ;
goto F_38;
}
V_7 -> V_5 = V_5 ;
V_24 -> V_25 = V_7 ;
F_43 ( & V_5 -> V_2 , & V_7 -> V_69 ) ;
goto V_70;
}
V_5 = F_44 ( sizeof( * V_5 ) , V_71 ) ;
if ( ! V_5 ) {
V_8 = - V_66 ;
goto F_38;
}
F_45 ( & V_5 -> V_2 , & V_7 -> V_69 ) ;
V_8 = V_44 -> V_72 ( V_5 ) ;
if ( V_8 )
goto F_38;
V_5 -> V_9 = F_46 ( V_24 ) ;
if ( ! F_42 () )
V_44 -> V_68 = V_5 ;
V_7 -> V_5 = V_5 ;
V_24 -> V_25 = V_7 ;
V_44 -> V_73 . V_74 = & V_75 ;
V_8 = F_47 ( & V_5 -> V_2 . V_76 , & V_44 -> V_73 ,
F_48 ( V_24 ) ,
L_2 , V_44 -> V_44 . V_77 ) ;
if ( ! V_8 )
goto V_70;
F_49 ( L_3 , V_8 ) ;
V_24 -> V_25 = NULL ;
if ( ! F_42 () )
V_44 -> V_68 = NULL ;
V_44 -> exit ( V_5 ) ;
F_50 ( V_5 ) ;
F_38:
F_38 ( V_7 , V_44 ) ;
V_70:
F_6 ( & V_67 ) ;
return V_8 ;
}
void F_51 ( struct V_23 * V_24 )
{
struct V_43 * V_44 = F_17 ( V_24 ) ;
struct V_6 * V_7 = V_24 -> V_25 ;
struct V_5 * V_5 = V_7 -> V_5 ;
unsigned int V_4 ;
F_4 ( & V_67 ) ;
V_4 = F_52 ( & V_5 -> V_2 , & V_7 -> V_69 ) ;
V_24 -> V_25 = NULL ;
if ( ! V_4 ) {
if ( ! F_42 () )
V_44 -> V_68 = NULL ;
V_44 -> exit ( V_5 ) ;
F_50 ( V_5 ) ;
}
F_38 ( V_7 , V_44 ) ;
F_6 ( & V_67 ) ;
}
int F_53 ( struct V_23 * V_24 )
{
struct V_43 * V_44 = F_17 ( V_24 ) ;
struct V_6 * V_7 = V_24 -> V_25 ;
struct V_5 * V_5 = V_7 -> V_5 ;
unsigned int V_9 , V_26 , V_12 ;
unsigned int V_30 ;
if ( ! V_24 -> V_78 )
return - V_10 ;
V_7 -> V_59 = F_54 ( V_24 ) ;
V_7 -> V_31 = 1 ;
V_9 = V_5 -> V_9 ;
V_26 = V_5 -> V_19 ;
V_30 = V_5 -> V_18 ;
F_8 (j, policy->cpus) {
struct V_13 * V_14 = & F_9 ( V_15 , V_12 ) ;
V_14 -> V_16 = F_10 ( V_12 , & V_14 -> V_17 , V_30 ) ;
V_14 -> V_39 = 0 ;
if ( V_26 )
V_14 -> V_20 = F_11 ( V_12 ) . V_21 [ V_22 ] ;
}
V_44 -> V_79 ( V_24 ) ;
F_29 ( V_7 , V_9 ) ;
return 0 ;
}
void F_55 ( struct V_23 * V_24 )
{
struct V_6 * V_7 = V_24 -> V_25 ;
F_31 ( V_7 -> V_24 ) ;
F_56 ( & V_7 -> V_48 ) ;
F_57 ( & V_7 -> V_42 ) ;
F_18 ( & V_7 -> V_46 , 0 ) ;
V_7 -> V_47 = false ;
}
void F_58 ( struct V_23 * V_24 )
{
struct V_6 * V_7 = V_24 -> V_25 ;
F_4 ( & V_7 -> V_11 ) ;
F_59 ( V_24 ) ;
F_5 ( V_7 , 0 ) ;
F_6 ( & V_7 -> V_11 ) ;
}
