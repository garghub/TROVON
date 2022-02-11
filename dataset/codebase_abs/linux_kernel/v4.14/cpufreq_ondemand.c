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
unsigned int V_16 ;
unsigned int V_17 ;
struct V_18 * V_19 = V_8 -> V_20 ;
struct V_21 * V_22 = F_4 ( V_19 ) ;
struct V_23 * V_23 = V_19 -> V_23 ;
struct V_24 * V_25 = V_23 -> V_26 ;
struct V_27 * V_28 = V_8 -> V_28 ;
if ( ! V_28 ) {
V_22 -> V_15 = 0 ;
V_22 -> V_29 = 0 ;
return V_9 ;
}
V_16 = F_5 ( V_8 , V_9 , V_10 ) ;
V_11 = V_28 [ V_16 ] . V_30 ;
V_12 = V_11 * V_25 -> V_31 / 1000 ;
V_13 = V_11 - V_12 ;
V_16 = F_6 ( V_8 , V_13 ) ;
V_15 = V_28 [ V_16 ] . V_30 ;
V_16 = F_7 ( V_8 , V_13 ) ;
V_14 = V_28 [ V_16 ] . V_30 ;
if ( V_14 == V_15 ) {
V_22 -> V_15 = 0 ;
V_22 -> V_29 = 0 ;
return V_15 ;
}
V_17 = ( V_13 - V_15 ) * V_23 -> V_32 ;
V_17 += ( V_14 - V_15 ) / 2 ;
V_17 /= V_14 - V_15 ;
V_22 -> V_33 = V_17 ;
V_22 -> V_15 = V_15 ;
V_22 -> V_29 = V_23 -> V_32 - V_17 ;
return V_14 ;
}
static void F_8 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_4 ( V_8 -> V_20 ) ;
V_22 -> V_15 = 0 ;
}
static void F_9 ( struct V_7 * V_8 , unsigned int V_34 )
{
struct V_18 * V_19 = V_8 -> V_20 ;
struct V_23 * V_23 = V_19 -> V_23 ;
struct V_24 * V_25 = V_23 -> V_26 ;
if ( V_25 -> V_31 )
V_34 = V_35 . V_36 ( V_8 , V_34 ,
V_37 ) ;
else if ( V_8 -> V_38 == V_8 -> V_39 )
return;
F_10 ( V_8 , V_34 , V_25 -> V_31 ?
V_40 : V_37 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
struct V_18 * V_19 = V_8 -> V_20 ;
struct V_21 * V_22 = F_4 ( V_19 ) ;
struct V_23 * V_23 = V_19 -> V_23 ;
struct V_24 * V_25 = V_23 -> V_26 ;
unsigned int V_41 = F_12 ( V_8 ) ;
V_22 -> V_15 = 0 ;
if ( V_41 > V_23 -> V_42 ) {
if ( V_8 -> V_38 < V_8 -> V_39 )
V_19 -> V_43 = V_23 -> V_44 ;
F_9 ( V_8 , V_8 -> V_39 ) ;
} else {
unsigned int V_9 , V_45 , V_46 ;
V_45 = V_8 -> V_47 . V_48 ;
V_46 = V_8 -> V_47 . V_49 ;
V_9 = V_45 + V_41 * ( V_46 - V_45 ) / 100 ;
V_19 -> V_43 = 1 ;
if ( V_25 -> V_31 )
V_9 = V_35 . V_36 ( V_8 ,
V_9 ,
V_40 ) ;
F_10 ( V_8 , V_9 , V_50 ) ;
}
}
static unsigned int F_13 ( struct V_7 * V_8 )
{
struct V_18 * V_19 = V_8 -> V_20 ;
struct V_23 * V_23 = V_19 -> V_23 ;
struct V_21 * V_22 = F_4 ( V_19 ) ;
int V_51 = V_22 -> V_51 ;
V_22 -> V_51 = V_52 ;
if ( V_51 == V_53 && V_19 -> V_54 > 0 ) {
F_10 ( V_8 , V_22 -> V_15 ,
V_37 ) ;
return V_22 -> V_29 ;
}
F_11 ( V_8 ) ;
if ( V_22 -> V_15 ) {
V_22 -> V_51 = V_53 ;
return V_22 -> V_33 ;
}
return V_23 -> V_32 * V_19 -> V_43 ;
}
static T_1 F_14 ( struct V_55 * V_56 , const char * V_57 ,
T_2 V_58 )
{
struct V_23 * V_23 = F_15 ( V_56 ) ;
unsigned int V_59 ;
int V_60 ;
V_60 = sscanf ( V_57 , L_1 , & V_59 ) ;
if ( V_60 != 1 )
return - V_61 ;
V_23 -> V_62 = ! ! V_59 ;
F_16 ( V_23 ) ;
return V_58 ;
}
static T_1 F_17 ( struct V_55 * V_56 ,
const char * V_57 , T_2 V_58 )
{
struct V_23 * V_23 = F_15 ( V_56 ) ;
unsigned int V_59 ;
int V_60 ;
V_60 = sscanf ( V_57 , L_1 , & V_59 ) ;
if ( V_60 != 1 || V_59 > V_63 ||
V_59 < V_64 ) {
return - V_61 ;
}
V_23 -> V_42 = V_59 ;
return V_58 ;
}
static T_1 F_18 ( struct V_55 * V_56 ,
const char * V_57 , T_2 V_58 )
{
struct V_23 * V_23 = F_15 ( V_56 ) ;
struct V_18 * V_19 ;
unsigned int V_59 ;
int V_60 ;
V_60 = sscanf ( V_57 , L_1 , & V_59 ) ;
if ( V_60 != 1 || V_59 > V_65 || V_59 < 1 )
return - V_61 ;
V_23 -> V_44 = V_59 ;
F_19 (policy_dbs, &attr_set->policy_list, list) {
F_20 ( & V_19 -> V_66 ) ;
V_19 -> V_43 = 1 ;
F_21 ( & V_19 -> V_66 ) ;
}
return V_58 ;
}
static T_1 F_22 ( struct V_55 * V_56 ,
const char * V_57 , T_2 V_58 )
{
struct V_23 * V_23 = F_15 ( V_56 ) ;
unsigned int V_59 ;
int V_60 ;
V_60 = sscanf ( V_57 , L_1 , & V_59 ) ;
if ( V_60 != 1 )
return - V_61 ;
if ( V_59 > 1 )
V_59 = 1 ;
if ( V_59 == V_23 -> V_67 ) {
return V_58 ;
}
V_23 -> V_67 = V_59 ;
F_16 ( V_23 ) ;
return V_58 ;
}
static T_1 F_23 ( struct V_55 * V_56 ,
const char * V_57 , T_2 V_58 )
{
struct V_23 * V_23 = F_15 ( V_56 ) ;
struct V_24 * V_25 = V_23 -> V_26 ;
struct V_18 * V_19 ;
unsigned int V_59 ;
int V_60 ;
V_60 = sscanf ( V_57 , L_1 , & V_59 ) ;
if ( V_60 != 1 )
return - V_61 ;
if ( V_59 > 1000 )
V_59 = 1000 ;
V_25 -> V_31 = V_59 ;
F_19 (policy_dbs, &attr_set->policy_list, list)
F_8 ( V_19 -> V_8 ) ;
return V_58 ;
}
static struct V_18 * F_24 ( void )
{
struct V_21 * V_22 ;
V_22 = F_25 ( sizeof( * V_22 ) , V_68 ) ;
return V_22 ? & V_22 -> V_19 : NULL ;
}
static void F_26 ( struct V_18 * V_19 )
{
F_27 ( F_4 ( V_19 ) ) ;
}
static int F_28 ( struct V_23 * V_23 )
{
struct V_24 * V_26 ;
T_3 V_69 ;
int V_70 ;
V_26 = F_25 ( sizeof( * V_26 ) , V_68 ) ;
if ( ! V_26 )
return - V_71 ;
V_70 = F_29 () ;
V_69 = F_30 ( V_70 , NULL ) ;
F_31 () ;
if ( V_69 != - 1ULL ) {
V_23 -> V_42 = V_72 ;
} else {
V_23 -> V_42 = V_73 ;
}
V_23 -> V_44 = V_74 ;
V_23 -> V_67 = 0 ;
V_26 -> V_31 = V_75 ;
V_23 -> V_62 = F_1 () ;
V_23 -> V_26 = V_26 ;
return 0 ;
}
static void F_32 ( struct V_23 * V_23 )
{
F_27 ( V_23 -> V_26 ) ;
}
static void F_33 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_4 ( V_8 -> V_20 ) ;
V_22 -> V_51 = V_52 ;
F_8 ( V_8 ) ;
}
static void F_34 ( unsigned int V_31 )
{
unsigned int V_70 ;
T_4 V_76 ;
V_75 = V_31 ;
F_35 ( & V_76 ) ;
F_36 () ;
F_37 (cpu) {
struct V_7 * V_8 ;
struct V_18 * V_19 ;
struct V_23 * V_23 ;
struct V_24 * V_25 ;
if ( F_38 ( V_70 , & V_76 ) )
continue;
V_8 = F_39 ( V_70 ) ;
if ( ! V_8 || V_8 -> V_77 != V_78 )
continue;
V_19 = V_8 -> V_20 ;
if ( ! V_19 )
continue;
F_40 ( & V_76 , & V_76 , V_8 -> V_79 ) ;
V_23 = V_19 -> V_23 ;
V_25 = V_23 -> V_26 ;
V_25 -> V_31 = V_75 ;
}
F_41 () ;
}
void F_42 ( void )
{
V_35 . V_36 = F_3 ;
F_34 ( 0 ) ;
}
static int T_5 F_43 ( void )
{
return F_44 ( V_78 ) ;
}
static void T_6 F_45 ( void )
{
F_46 ( V_78 ) ;
}
struct V_80 * F_47 ( void )
{
return V_78 ;
}
