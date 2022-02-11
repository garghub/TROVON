static struct V_1 * F_1 ( const struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 ;
F_2 (list_dev, &dev_opp->dev_list, node)
if ( V_6 -> V_3 == V_3 )
return V_6 ;
return NULL ;
}
static struct V_4 * F_3 ( const struct V_7 * V_8 )
{
struct V_4 * V_5 ;
F_4 (dev_opp, &dev_opp_list, node) {
if ( V_5 -> V_8 == V_8 ) {
return V_5 -> V_9 ? V_5 : NULL ;
}
}
return NULL ;
}
static struct V_4 * F_5 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
if ( F_6 ( V_3 ) ) {
F_7 ( L_1 , V_10 ) ;
return F_8 ( - V_11 ) ;
}
F_4 (dev_opp, &dev_opp_list, node)
if ( F_1 ( V_3 , V_5 ) )
return V_5 ;
return F_8 ( - V_12 ) ;
}
unsigned long F_9 ( struct V_13 * V_14 )
{
struct V_13 * V_15 ;
unsigned long V_16 = 0 ;
F_10 () ;
V_15 = F_11 ( V_14 ) ;
if ( F_6 ( V_15 ) || ! V_15 -> V_17 )
F_7 ( L_1 , V_10 ) ;
else
V_16 = V_15 -> V_18 ;
return V_16 ;
}
unsigned long F_12 ( struct V_13 * V_14 )
{
struct V_13 * V_15 ;
unsigned long V_19 = 0 ;
F_10 () ;
V_15 = F_11 ( V_14 ) ;
if ( F_6 ( V_15 ) || ! V_15 -> V_17 )
F_7 ( L_1 , V_10 ) ;
else
V_19 = V_15 -> V_20 ;
return V_19 ;
}
bool F_13 ( struct V_13 * V_14 )
{
struct V_13 * V_15 ;
F_10 () ;
V_15 = F_11 ( V_14 ) ;
if ( F_6 ( V_15 ) || ! V_15 -> V_17 ) {
F_7 ( L_1 , V_10 ) ;
return false ;
}
return V_15 -> V_21 ;
}
unsigned long F_14 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
unsigned long V_22 ;
F_15 () ;
V_5 = F_5 ( V_3 ) ;
if ( F_16 ( V_5 ) )
V_22 = 0 ;
else
V_22 = V_5 -> V_23 ;
F_17 () ;
return V_22 ;
}
struct V_13 * F_18 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
F_10 () ;
V_5 = F_5 ( V_3 ) ;
if ( F_16 ( V_5 ) || ! V_5 -> V_24 ||
! V_5 -> V_24 -> V_17 )
return NULL ;
return V_5 -> V_24 ;
}
int F_19 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_13 * V_25 ;
int V_26 = 0 ;
F_15 () ;
V_5 = F_5 ( V_3 ) ;
if ( F_16 ( V_5 ) ) {
V_26 = F_20 ( V_5 ) ;
F_21 ( V_3 , L_2 ,
V_10 , V_26 ) ;
goto V_27;
}
F_4 (temp_opp, &dev_opp->opp_list, node) {
if ( V_25 -> V_17 )
V_26 ++ ;
}
V_27:
F_17 () ;
return V_26 ;
}
struct V_13 * F_22 ( struct V_2 * V_3 ,
unsigned long V_28 ,
bool V_17 )
{
struct V_4 * V_5 ;
struct V_13 * V_25 , * V_14 = F_8 ( - V_29 ) ;
F_10 () ;
V_5 = F_5 ( V_3 ) ;
if ( F_16 ( V_5 ) ) {
int V_30 = F_20 ( V_5 ) ;
F_21 ( V_3 , L_2 , V_10 , V_30 ) ;
return F_8 ( V_30 ) ;
}
F_4 (temp_opp, &dev_opp->opp_list, node) {
if ( V_25 -> V_17 == V_17 &&
V_25 -> V_20 == V_28 ) {
V_14 = V_25 ;
break;
}
}
return V_14 ;
}
struct V_13 * F_23 ( struct V_2 * V_3 ,
unsigned long * V_28 )
{
struct V_4 * V_5 ;
struct V_13 * V_25 , * V_14 = F_8 ( - V_29 ) ;
F_10 () ;
if ( ! V_3 || ! V_28 ) {
F_21 ( V_3 , L_3 , V_10 , V_28 ) ;
return F_8 ( - V_11 ) ;
}
V_5 = F_5 ( V_3 ) ;
if ( F_16 ( V_5 ) )
return F_24 ( V_5 ) ;
F_4 (temp_opp, &dev_opp->opp_list, node) {
if ( V_25 -> V_17 && V_25 -> V_20 >= * V_28 ) {
V_14 = V_25 ;
* V_28 = V_14 -> V_20 ;
break;
}
}
return V_14 ;
}
struct V_13 * F_25 ( struct V_2 * V_3 ,
unsigned long * V_28 )
{
struct V_4 * V_5 ;
struct V_13 * V_25 , * V_14 = F_8 ( - V_29 ) ;
F_10 () ;
if ( ! V_3 || ! V_28 ) {
F_21 ( V_3 , L_3 , V_10 , V_28 ) ;
return F_8 ( - V_11 ) ;
}
V_5 = F_5 ( V_3 ) ;
if ( F_16 ( V_5 ) )
return F_24 ( V_5 ) ;
F_4 (temp_opp, &dev_opp->opp_list, node) {
if ( V_25 -> V_17 ) {
if ( V_25 -> V_20 > * V_28 )
break;
else
V_14 = V_25 ;
}
}
if ( ! F_16 ( V_14 ) )
* V_28 = V_14 -> V_20 ;
return V_14 ;
}
static void F_26 ( struct V_31 * V_32 )
{
struct V_1 * V_6 ;
V_6 = F_27 ( V_32 , struct V_1 , V_31 ) ;
F_28 ( V_6 , V_31 ) ;
}
static void F_29 ( struct V_1 * V_6 ,
struct V_4 * V_5 )
{
F_30 ( & V_6 -> V_33 ) ;
F_31 ( & V_5 -> V_34 . V_35 , & V_6 -> V_31 ,
F_26 ) ;
}
static struct V_1 * F_32 ( const struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 ;
V_6 = F_33 ( sizeof( * V_6 ) , V_36 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_3 = V_3 ;
F_34 ( & V_6 -> V_33 , & V_5 -> V_37 ) ;
return V_6 ;
}
static struct V_4 * F_35 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_6 ;
V_5 = F_5 ( V_3 ) ;
if ( ! F_16 ( V_5 ) )
return V_5 ;
V_5 = F_33 ( sizeof( * V_5 ) , V_36 ) ;
if ( ! V_5 )
return NULL ;
F_36 ( & V_5 -> V_37 ) ;
V_6 = F_32 ( V_3 , V_5 ) ;
if ( ! V_6 ) {
F_37 ( V_5 ) ;
return NULL ;
}
F_38 ( & V_5 -> V_34 ) ;
F_36 ( & V_5 -> V_38 ) ;
F_34 ( & V_5 -> V_33 , & V_39 ) ;
return V_5 ;
}
static void F_39 ( struct V_31 * V_32 )
{
struct V_4 * V_4 = F_27 ( V_32 , struct V_4 , V_31 ) ;
F_28 ( V_4 , V_31 ) ;
}
static void F_40 ( struct V_4 * V_5 )
{
struct V_1 * V_6 ;
if ( ! F_41 ( & V_5 -> V_38 ) )
return;
V_6 = F_42 ( & V_5 -> V_37 , struct V_1 ,
V_33 ) ;
F_29 ( V_6 , V_5 ) ;
F_43 ( ! F_41 ( & V_5 -> V_37 ) ) ;
F_44 ( & V_5 -> V_33 ) ;
F_31 ( & V_5 -> V_34 . V_35 , & V_5 -> V_31 ,
F_39 ) ;
}
static void F_45 ( struct V_31 * V_32 )
{
struct V_13 * V_14 = F_27 ( V_32 , struct V_13 , V_31 ) ;
F_28 ( V_14 , V_31 ) ;
}
static void F_46 ( struct V_4 * V_5 ,
struct V_13 * V_14 , bool V_40 )
{
if ( V_40 )
F_47 ( & V_5 -> V_34 , V_41 , V_14 ) ;
F_44 ( & V_14 -> V_33 ) ;
F_31 ( & V_5 -> V_34 . V_35 , & V_14 -> V_31 , F_45 ) ;
F_40 ( V_5 ) ;
}
void F_48 ( struct V_2 * V_3 , unsigned long V_28 )
{
struct V_13 * V_14 ;
struct V_4 * V_5 ;
bool V_42 = false ;
F_49 ( & V_43 ) ;
V_5 = F_5 ( V_3 ) ;
if ( F_16 ( V_5 ) )
goto V_44;
F_2 (opp, &dev_opp->opp_list, node) {
if ( V_14 -> V_20 == V_28 ) {
V_42 = true ;
break;
}
}
if ( ! V_42 ) {
F_50 ( V_3 , L_4 ,
V_10 , V_28 ) ;
goto V_44;
}
F_46 ( V_5 , V_14 , true ) ;
V_44:
F_51 ( & V_43 ) ;
}
static struct V_13 * F_52 ( struct V_2 * V_3 ,
struct V_4 * * V_5 )
{
struct V_13 * V_14 ;
V_14 = F_33 ( sizeof( * V_14 ) , V_36 ) ;
if ( ! V_14 )
return NULL ;
F_36 ( & V_14 -> V_33 ) ;
* V_5 = F_35 ( V_3 ) ;
if ( ! * V_5 ) {
F_37 ( V_14 ) ;
return NULL ;
}
return V_14 ;
}
static int F_53 ( struct V_2 * V_3 , struct V_13 * V_45 ,
struct V_4 * V_5 )
{
struct V_13 * V_14 ;
struct V_46 * V_32 = & V_5 -> V_38 ;
F_4 (opp, &dev_opp->opp_list, node) {
if ( V_45 -> V_20 > V_14 -> V_20 ) {
V_32 = & V_14 -> V_33 ;
continue;
}
if ( V_45 -> V_20 < V_14 -> V_20 )
break;
F_50 ( V_3 , L_5 ,
V_10 , V_14 -> V_20 , V_14 -> V_18 , V_14 -> V_17 ,
V_45 -> V_20 , V_45 -> V_18 , V_45 -> V_17 ) ;
return V_14 -> V_17 && V_45 -> V_18 == V_14 -> V_18 ?
0 : - V_47 ;
}
V_45 -> V_5 = V_5 ;
F_34 ( & V_45 -> V_33 , V_32 ) ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 , unsigned long V_28 ,
long V_18 , bool V_48 )
{
struct V_4 * V_5 ;
struct V_13 * V_45 ;
int V_49 ;
F_49 ( & V_43 ) ;
V_45 = F_52 ( V_3 , & V_5 ) ;
if ( ! V_45 ) {
V_49 = - V_50 ;
goto V_44;
}
V_45 -> V_20 = V_28 ;
V_45 -> V_18 = V_18 ;
V_45 -> V_17 = true ;
V_45 -> V_48 = V_48 ;
V_49 = F_53 ( V_3 , V_45 , V_5 ) ;
if ( V_49 )
goto V_51;
F_51 ( & V_43 ) ;
F_47 ( & V_5 -> V_34 , V_52 , V_45 ) ;
return 0 ;
V_51:
F_46 ( V_5 , V_45 , false ) ;
V_44:
F_51 ( & V_43 ) ;
return V_49 ;
}
static int F_55 ( struct V_13 * V_14 , struct V_2 * V_3 )
{
T_1 V_53 [ 3 ] = { 0 } ;
int V_26 , V_49 ;
if ( ! F_56 ( V_14 -> V_8 , L_6 , NULL ) )
return 0 ;
V_26 = F_57 ( V_14 -> V_8 , L_6 ) ;
if ( V_26 < 0 ) {
F_21 ( V_3 , L_7 ,
V_10 , V_26 ) ;
return V_26 ;
}
if ( V_26 != 1 && V_26 != 3 ) {
F_21 ( V_3 , L_8 ,
V_10 , V_26 ) ;
return - V_11 ;
}
V_49 = F_58 ( V_14 -> V_8 , L_6 , V_53 ,
V_26 ) ;
if ( V_49 ) {
F_21 ( V_3 , L_9 , V_10 ,
V_49 ) ;
return - V_11 ;
}
V_14 -> V_18 = V_53 [ 0 ] ;
V_14 -> V_54 = V_53 [ 1 ] ;
V_14 -> V_55 = V_53 [ 2 ] ;
return 0 ;
}
static int F_59 ( struct V_2 * V_3 , struct V_7 * V_8 )
{
struct V_4 * V_5 ;
struct V_13 * V_45 ;
T_2 V_20 ;
T_1 V_56 ;
int V_49 ;
F_49 ( & V_43 ) ;
V_45 = F_52 ( V_3 , & V_5 ) ;
if ( ! V_45 ) {
V_49 = - V_50 ;
goto V_44;
}
V_49 = F_60 ( V_8 , L_10 , & V_20 ) ;
if ( V_49 < 0 ) {
F_21 ( V_3 , L_11 , V_10 ) ;
goto V_51;
}
V_45 -> V_20 = ( unsigned long ) V_20 ;
V_45 -> V_21 = F_61 ( V_8 , L_12 ) ;
V_45 -> V_8 = V_8 ;
V_45 -> V_48 = false ;
V_45 -> V_17 = true ;
if ( ! F_62 ( V_8 , L_13 , & V_56 ) )
V_45 -> V_22 = V_56 ;
V_49 = F_55 ( V_45 , V_3 ) ;
if ( V_49 )
goto V_51;
if ( ! F_62 ( V_45 -> V_8 , L_14 , & V_56 ) )
V_45 -> V_57 = V_56 ;
V_49 = F_53 ( V_3 , V_45 , V_5 ) ;
if ( V_49 )
goto V_51;
if ( F_61 ( V_8 , L_15 ) ) {
if ( V_5 -> V_24 )
F_50 ( V_3 , L_16 ,
V_10 , V_5 -> V_24 -> V_20 ,
V_45 -> V_20 ) ;
else
V_5 -> V_24 = V_45 ;
}
if ( V_45 -> V_22 > V_5 -> V_23 )
V_5 -> V_23 = V_45 -> V_22 ;
F_51 ( & V_43 ) ;
F_63 ( L_17 ,
V_10 , V_45 -> V_21 , V_45 -> V_20 , V_45 -> V_18 ,
V_45 -> V_54 , V_45 -> V_55 ,
V_45 -> V_22 ) ;
F_47 ( & V_5 -> V_34 , V_52 , V_45 ) ;
return 0 ;
V_51:
F_46 ( V_5 , V_45 , false ) ;
V_44:
F_51 ( & V_43 ) ;
return V_49 ;
}
int F_64 ( struct V_2 * V_3 , unsigned long V_28 , unsigned long V_18 )
{
return F_54 ( V_3 , V_28 , V_18 , true ) ;
}
static int F_65 ( struct V_2 * V_3 , unsigned long V_28 ,
bool V_58 )
{
struct V_4 * V_5 ;
struct V_13 * V_45 , * V_15 , * V_14 = F_8 ( - V_12 ) ;
int V_30 = 0 ;
V_45 = F_66 ( sizeof( * V_45 ) , V_36 ) ;
if ( ! V_45 )
return - V_50 ;
F_49 ( & V_43 ) ;
V_5 = F_5 ( V_3 ) ;
if ( F_16 ( V_5 ) ) {
V_30 = F_20 ( V_5 ) ;
F_50 ( V_3 , L_18 , V_10 , V_30 ) ;
goto V_44;
}
F_2 (tmp_opp, &dev_opp->opp_list, node) {
if ( V_15 -> V_20 == V_28 ) {
V_14 = V_15 ;
break;
}
}
if ( F_16 ( V_14 ) ) {
V_30 = F_20 ( V_14 ) ;
goto V_44;
}
if ( V_14 -> V_17 == V_58 )
goto V_44;
* V_45 = * V_14 ;
V_45 -> V_17 = V_58 ;
F_67 ( & V_14 -> V_33 , & V_45 -> V_33 ) ;
F_51 ( & V_43 ) ;
F_31 ( & V_5 -> V_34 . V_35 , & V_14 -> V_31 , F_45 ) ;
if ( V_58 )
F_47 ( & V_5 -> V_34 , V_59 ,
V_45 ) ;
else
F_47 ( & V_5 -> V_34 , V_60 ,
V_45 ) ;
return 0 ;
V_44:
F_51 ( & V_43 ) ;
F_37 ( V_45 ) ;
return V_30 ;
}
int F_68 ( struct V_2 * V_3 , unsigned long V_28 )
{
return F_65 ( V_3 , V_28 , true ) ;
}
int F_69 ( struct V_2 * V_3 , unsigned long V_28 )
{
return F_65 ( V_3 , V_28 , false ) ;
}
struct V_61 * F_70 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_5 ( V_3 ) ;
if ( F_16 ( V_5 ) )
return F_24 ( V_5 ) ;
return & V_5 -> V_34 ;
}
void F_71 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_13 * V_14 , * V_62 ;
F_49 ( & V_43 ) ;
V_5 = F_5 ( V_3 ) ;
if ( F_16 ( V_5 ) ) {
int error = F_20 ( V_5 ) ;
if ( error != - V_12 )
F_72 ( 1 , L_19 ,
F_6 ( V_3 ) ?
L_20 : F_73 ( V_3 ) ,
error ) ;
goto V_44;
}
if ( F_74 ( & V_5 -> V_37 ) ) {
F_75 (opp, tmp, &dev_opp->opp_list, node) {
if ( ! V_14 -> V_48 )
F_46 ( V_5 , V_14 , true ) ;
}
} else {
F_29 ( F_1 ( V_3 , V_5 ) , V_5 ) ;
}
V_44:
F_51 ( & V_43 ) ;
}
void F_76 ( T_3 V_63 )
{
struct V_2 * V_64 ;
int V_65 ;
F_43 ( F_77 ( V_63 ) ) ;
F_78 (cpu, cpumask) {
V_64 = F_79 ( V_65 ) ;
if ( ! V_64 ) {
F_7 ( L_21 , V_10 ,
V_65 ) ;
continue;
}
F_71 ( V_64 ) ;
}
}
static struct V_7 *
F_80 ( struct V_2 * V_3 , const struct V_66 * V_67 )
{
struct V_7 * V_68 ;
V_68 = F_81 ( F_82 ( V_67 -> V_69 ) ) ;
if ( ! V_68 ) {
F_21 ( V_3 , L_22 ,
V_10 , V_67 -> V_70 ) ;
return F_8 ( - V_11 ) ;
}
return V_68 ;
}
static struct V_7 * F_83 ( struct V_2 * V_3 )
{
const struct V_66 * V_67 ;
V_67 = F_56 ( V_3 -> V_71 , L_23 , NULL ) ;
if ( ! V_67 )
return F_8 ( - V_12 ) ;
if ( ! V_67 -> V_69 )
return F_8 ( - V_72 ) ;
if ( V_67 -> V_73 != sizeof( V_74 ) ) {
F_21 ( V_3 , L_24 , V_10 ) ;
return F_8 ( - V_11 ) ;
}
return F_80 ( V_3 , V_67 ) ;
}
static int F_84 ( struct V_2 * V_3 ,
const struct V_66 * V_67 )
{
struct V_7 * V_68 , * V_8 ;
struct V_4 * V_5 ;
int V_49 = 0 , V_26 = 0 ;
if ( ! V_67 -> V_69 )
return - V_72 ;
V_68 = F_80 ( V_3 , V_67 ) ;
if ( F_16 ( V_68 ) )
return F_20 ( V_68 ) ;
V_5 = F_3 ( V_68 ) ;
if ( V_5 ) {
if ( ! F_32 ( V_3 , V_5 ) )
V_49 = - V_50 ;
goto V_75;
}
F_85 (opp_np, np) {
V_26 ++ ;
V_49 = F_59 ( V_3 , V_8 ) ;
if ( V_49 ) {
F_21 ( V_3 , L_25 , V_10 ,
V_49 ) ;
goto V_76;
}
}
if ( F_43 ( ! V_26 ) ) {
V_49 = - V_77 ;
goto V_75;
}
V_5 = F_5 ( V_3 ) ;
if ( F_43 ( F_16 ( V_5 ) ) ) {
V_49 = F_20 ( V_5 ) ;
goto V_76;
}
V_5 -> V_8 = V_68 ;
V_5 -> V_9 = F_61 ( V_68 , L_26 ) ;
F_86 ( V_68 ) ;
return 0 ;
V_76:
F_71 ( V_3 ) ;
V_75:
F_86 ( V_68 ) ;
return V_49 ;
}
static int F_87 ( struct V_2 * V_3 )
{
const struct V_66 * V_67 ;
const V_74 * V_56 ;
int V_78 ;
V_67 = F_56 ( V_3 -> V_71 , L_27 , NULL ) ;
if ( ! V_67 )
return - V_12 ;
if ( ! V_67 -> V_69 )
return - V_72 ;
V_78 = V_67 -> V_73 / sizeof( T_1 ) ;
if ( V_78 % 2 ) {
F_21 ( V_3 , L_28 , V_10 ) ;
return - V_11 ;
}
V_56 = V_67 -> V_69 ;
while ( V_78 ) {
unsigned long V_28 = F_82 ( V_56 ++ ) * 1000 ;
unsigned long V_79 = F_82 ( V_56 ++ ) ;
if ( F_54 ( V_3 , V_28 , V_79 , false ) )
F_50 ( V_3 , L_29 ,
V_10 , V_28 ) ;
V_78 -= 2 ;
}
return 0 ;
}
int F_88 ( struct V_2 * V_3 )
{
const struct V_66 * V_67 ;
V_67 = F_56 ( V_3 -> V_71 , L_23 , NULL ) ;
if ( ! V_67 ) {
return F_87 ( V_3 ) ;
}
return F_84 ( V_3 , V_67 ) ;
}
int F_89 ( T_3 V_63 )
{
struct V_2 * V_64 ;
int V_65 , V_49 = 0 ;
F_43 ( F_77 ( V_63 ) ) ;
F_78 (cpu, cpumask) {
V_64 = F_79 ( V_65 ) ;
if ( ! V_64 ) {
F_7 ( L_21 , V_10 ,
V_65 ) ;
continue;
}
V_49 = F_88 ( V_64 ) ;
if ( V_49 ) {
F_7 ( L_30 ,
V_10 , V_65 , V_49 ) ;
F_76 ( V_63 ) ;
break;
}
}
return V_49 ;
}
int F_90 ( struct V_2 * V_64 , T_3 V_63 )
{
struct V_1 * V_6 ;
struct V_4 * V_5 ;
struct V_2 * V_3 ;
int V_65 , V_49 = 0 ;
F_15 () ;
V_5 = F_5 ( V_64 ) ;
if ( F_16 ( V_5 ) ) {
V_49 = - V_11 ;
goto V_80;
}
F_78 (cpu, cpumask) {
if ( V_65 == V_64 -> V_81 )
continue;
V_3 = F_79 ( V_65 ) ;
if ( ! V_3 ) {
F_21 ( V_64 , L_21 ,
V_10 , V_65 ) ;
continue;
}
V_6 = F_32 ( V_3 , V_5 ) ;
if ( ! V_6 ) {
F_21 ( V_3 , L_31 ,
V_10 , V_65 ) ;
continue;
}
}
V_80:
F_17 () ;
return 0 ;
}
int F_91 ( struct V_2 * V_64 , T_3 V_63 )
{
struct V_7 * V_8 , * V_82 ;
struct V_2 * V_83 ;
int V_65 , V_49 = 0 ;
V_8 = F_83 ( V_64 ) ;
if ( F_16 ( V_8 ) ) {
F_92 ( V_64 , L_32 , V_10 ,
F_20 ( V_8 ) ) ;
return - V_77 ;
}
if ( ! F_61 ( V_8 , L_26 ) )
goto V_84;
F_93 (cpu) {
if ( V_65 == V_64 -> V_81 )
continue;
V_83 = F_79 ( V_65 ) ;
if ( ! V_83 ) {
F_21 ( V_64 , L_21 ,
V_10 , V_65 ) ;
V_49 = - V_12 ;
goto V_84;
}
V_82 = F_83 ( V_83 ) ;
if ( F_16 ( V_82 ) ) {
F_21 ( V_83 , L_32 ,
V_10 , F_20 ( V_82 ) ) ;
V_49 = F_20 ( V_82 ) ;
goto V_84;
}
if ( V_8 == V_82 )
F_94 ( V_65 , V_63 ) ;
F_86 ( V_82 ) ;
}
V_84:
F_86 ( V_8 ) ;
return V_49 ;
}
