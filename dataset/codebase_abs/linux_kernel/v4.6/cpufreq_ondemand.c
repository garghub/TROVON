static int F_1 ( void )
{
#if F_2 ( V_1 )
if ( V_2 . V_3 == V_4 &&
V_2 . V_5 == 6 &&
V_2 . V_6 >= 15 )
return 1 ;
#endif
return 0 ;
}
static unsigned int F_3 ( struct V_7 * V_8 ,
unsigned int V_9 , unsigned int V_10 )
{
unsigned int V_11 , V_12 , V_13 ;
unsigned int V_14 , V_15 ;
unsigned int V_16 = 0 ;
unsigned int V_17 ;
struct V_18 * V_19 = V_8 -> V_20 ;
struct V_21 * V_22 = F_4 ( V_19 ) ;
struct V_23 * V_23 = V_19 -> V_23 ;
struct V_24 * V_25 = V_23 -> V_26 ;
if ( ! V_22 -> V_27 ) {
V_22 -> V_15 = 0 ;
V_22 -> V_28 = 0 ;
return V_9 ;
}
F_5 ( V_8 , V_22 -> V_27 , V_9 ,
V_10 , & V_16 ) ;
V_11 = V_22 -> V_27 [ V_16 ] . V_29 ;
V_12 = V_11 * V_25 -> V_30 / 1000 ;
V_13 = V_11 - V_12 ;
V_16 = 0 ;
F_5 ( V_8 , V_22 -> V_27 , V_13 ,
V_31 , & V_16 ) ;
V_15 = V_22 -> V_27 [ V_16 ] . V_29 ;
V_16 = 0 ;
F_5 ( V_8 , V_22 -> V_27 , V_13 ,
V_32 , & V_16 ) ;
V_14 = V_22 -> V_27 [ V_16 ] . V_29 ;
if ( V_14 == V_15 ) {
V_22 -> V_15 = 0 ;
V_22 -> V_28 = 0 ;
return V_15 ;
}
V_17 = ( V_13 - V_15 ) * V_23 -> V_33 ;
V_17 += ( V_14 - V_15 ) / 2 ;
V_17 /= V_14 - V_15 ;
V_22 -> V_34 = V_17 ;
V_22 -> V_15 = V_15 ;
V_22 -> V_28 = V_23 -> V_33 - V_17 ;
return V_14 ;
}
static void F_6 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_4 ( V_8 -> V_20 ) ;
V_22 -> V_27 = F_7 ( V_8 -> V_35 ) ;
V_22 -> V_15 = 0 ;
}
static void F_8 ( struct V_7 * V_8 , unsigned int V_36 )
{
struct V_18 * V_19 = V_8 -> V_20 ;
struct V_23 * V_23 = V_19 -> V_23 ;
struct V_24 * V_25 = V_23 -> V_26 ;
if ( V_25 -> V_30 )
V_36 = V_37 . V_38 ( V_8 , V_36 ,
V_31 ) ;
else if ( V_8 -> V_39 == V_8 -> V_40 )
return;
F_9 ( V_8 , V_36 , V_25 -> V_30 ?
V_32 : V_31 ) ;
}
static void F_10 ( struct V_7 * V_8 )
{
struct V_18 * V_19 = V_8 -> V_20 ;
struct V_21 * V_22 = F_4 ( V_19 ) ;
struct V_23 * V_23 = V_19 -> V_23 ;
struct V_24 * V_25 = V_23 -> V_26 ;
unsigned int V_41 = F_11 ( V_8 ) ;
V_22 -> V_15 = 0 ;
if ( V_41 > V_23 -> V_42 ) {
if ( V_8 -> V_39 < V_8 -> V_40 )
V_19 -> V_43 = V_23 -> V_44 ;
F_8 ( V_8 , V_8 -> V_40 ) ;
} else {
unsigned int V_9 , V_45 , V_46 ;
V_45 = V_8 -> V_47 . V_48 ;
V_46 = V_8 -> V_47 . V_49 ;
V_9 = V_45 + V_41 * ( V_46 - V_45 ) / 100 ;
V_19 -> V_43 = 1 ;
if ( V_25 -> V_30 )
V_9 = V_37 . V_38 ( V_8 ,
V_9 ,
V_32 ) ;
F_9 ( V_8 , V_9 , V_50 ) ;
}
}
static unsigned int F_12 ( struct V_7 * V_8 )
{
struct V_18 * V_19 = V_8 -> V_20 ;
struct V_23 * V_23 = V_19 -> V_23 ;
struct V_21 * V_22 = F_4 ( V_19 ) ;
int V_51 = V_22 -> V_51 ;
V_22 -> V_51 = V_52 ;
if ( V_51 == V_53 && V_19 -> V_54 > 0 ) {
F_9 ( V_8 , V_22 -> V_15 ,
V_31 ) ;
return V_22 -> V_28 ;
}
F_10 ( V_8 ) ;
if ( V_22 -> V_15 ) {
V_22 -> V_51 = V_53 ;
return V_22 -> V_34 ;
}
return V_23 -> V_33 * V_19 -> V_43 ;
}
static T_1 F_13 ( struct V_23 * V_23 , const char * V_55 ,
T_2 V_56 )
{
unsigned int V_57 ;
int V_58 ;
V_58 = sscanf ( V_55 , L_1 , & V_57 ) ;
if ( V_58 != 1 )
return - V_59 ;
V_23 -> V_60 = ! ! V_57 ;
F_14 ( V_23 ) ;
return V_56 ;
}
static T_1 F_15 ( struct V_23 * V_23 , const char * V_55 ,
T_2 V_56 )
{
unsigned int V_57 ;
int V_58 ;
V_58 = sscanf ( V_55 , L_1 , & V_57 ) ;
if ( V_58 != 1 || V_57 > V_61 ||
V_57 < V_62 ) {
return - V_59 ;
}
V_23 -> V_42 = V_57 ;
return V_56 ;
}
static T_1 F_16 ( struct V_23 * V_23 ,
const char * V_55 , T_2 V_56 )
{
struct V_18 * V_19 ;
unsigned int V_57 ;
int V_58 ;
V_58 = sscanf ( V_55 , L_1 , & V_57 ) ;
if ( V_58 != 1 || V_57 > V_63 || V_57 < 1 )
return - V_59 ;
V_23 -> V_44 = V_57 ;
F_17 (policy_dbs, &dbs_data->policy_dbs_list, list) {
F_18 ( & V_19 -> V_64 ) ;
V_19 -> V_43 = 1 ;
F_19 ( & V_19 -> V_64 ) ;
}
return V_56 ;
}
static T_1 F_20 ( struct V_23 * V_23 ,
const char * V_55 , T_2 V_56 )
{
unsigned int V_57 ;
int V_58 ;
V_58 = sscanf ( V_55 , L_1 , & V_57 ) ;
if ( V_58 != 1 )
return - V_59 ;
if ( V_57 > 1 )
V_57 = 1 ;
if ( V_57 == V_23 -> V_65 ) {
return V_56 ;
}
V_23 -> V_65 = V_57 ;
F_14 ( V_23 ) ;
return V_56 ;
}
static T_1 F_21 ( struct V_23 * V_23 , const char * V_55 ,
T_2 V_56 )
{
struct V_24 * V_25 = V_23 -> V_26 ;
struct V_18 * V_19 ;
unsigned int V_57 ;
int V_58 ;
V_58 = sscanf ( V_55 , L_1 , & V_57 ) ;
if ( V_58 != 1 )
return - V_59 ;
if ( V_57 > 1000 )
V_57 = 1000 ;
V_25 -> V_30 = V_57 ;
F_17 (policy_dbs, &dbs_data->policy_dbs_list, list)
F_6 ( V_19 -> V_8 ) ;
return V_56 ;
}
static struct V_18 * F_22 ( void )
{
struct V_21 * V_22 ;
V_22 = F_23 ( sizeof( * V_22 ) , V_66 ) ;
return V_22 ? & V_22 -> V_19 : NULL ;
}
static void F_24 ( struct V_18 * V_19 )
{
F_25 ( F_4 ( V_19 ) ) ;
}
static int F_26 ( struct V_23 * V_23 , bool V_67 )
{
struct V_24 * V_26 ;
T_3 V_68 ;
int V_35 ;
V_26 = F_23 ( sizeof( * V_26 ) , V_66 ) ;
if ( ! V_26 ) {
F_27 ( L_2 , V_69 ) ;
return - V_70 ;
}
V_35 = F_28 () ;
V_68 = F_29 ( V_35 , NULL ) ;
F_30 () ;
if ( V_68 != - 1ULL ) {
V_23 -> V_42 = V_71 ;
V_23 -> V_72 = V_73 ;
} else {
V_23 -> V_42 = V_74 ;
V_23 -> V_72 = V_75 *
F_31 ( 10 ) ;
}
V_23 -> V_44 = V_76 ;
V_23 -> V_65 = 0 ;
V_26 -> V_30 = V_77 ;
V_23 -> V_60 = F_1 () ;
V_23 -> V_26 = V_26 ;
return 0 ;
}
static void F_32 ( struct V_23 * V_23 , bool V_67 )
{
F_25 ( V_23 -> V_26 ) ;
}
static void F_33 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_4 ( V_8 -> V_20 ) ;
V_22 -> V_51 = V_52 ;
F_6 ( V_8 ) ;
}
static void F_34 ( unsigned int V_30 )
{
unsigned int V_35 ;
T_4 V_78 ;
V_77 = V_30 ;
F_35 ( & V_78 ) ;
F_36 () ;
F_37 (cpu) {
struct V_7 * V_8 ;
struct V_18 * V_19 ;
struct V_23 * V_23 ;
struct V_24 * V_25 ;
if ( F_38 ( V_35 , & V_78 ) )
continue;
V_8 = F_39 ( V_35 ) ;
if ( ! V_8 || V_8 -> V_79 != V_80 )
continue;
V_19 = V_8 -> V_20 ;
if ( ! V_19 )
continue;
F_40 ( & V_78 , & V_78 , V_8 -> V_81 ) ;
V_23 = V_19 -> V_23 ;
V_25 = V_23 -> V_26 ;
V_25 -> V_30 = V_77 ;
}
F_41 () ;
}
void F_42 ( void )
{
V_37 . V_38 = F_3 ;
F_34 ( 0 ) ;
}
static int T_5 F_43 ( void )
{
return F_44 ( V_80 ) ;
}
static void T_6 F_45 ( void )
{
F_46 ( V_80 ) ;
}
struct V_82 * F_47 ( void )
{
return V_80 ;
}
