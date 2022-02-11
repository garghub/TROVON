struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 , & V_5 ,
V_6 , V_7 ) ;
if ( V_4 ) {
F_3 ( V_4 ) ;
V_4 -> V_8 = V_4 -> V_9 = 1 ;
}
return V_4 ;
}
int F_4 ( struct V_10 * V_11 )
{
int V_12 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_11 -> V_13 . V_14 . V_15 ) ;
if ( ! V_4 )
return - V_16 ;
V_4 -> V_17 = V_18 ;
V_12 = F_5 ( V_4 ) ;
F_6 ( V_4 ) ;
return V_12 ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
F_8 ( L_1 ,
V_3 -> V_19 -> V_20 . V_21 ,
F_9 ( V_3 -> V_19 ) ) ;
return - V_16 ;
}
F_10 ( V_22 , V_4 , L_2 ,
V_3 -> V_19 -> V_20 . V_21 , F_9 ( V_3 -> V_19 ) ) ;
F_11 ( V_4 ) ;
return 0 ;
}
static void F_12 ( struct V_2 * V_3 , int V_23 )
{
int time = V_23 ? V_24 : V_25 ;
if ( V_3 -> V_26 == V_27 ) {
int V_28 = F_13 ( int , V_29 ,
V_30 ? 0 :
F_14 ( & V_3 -> V_31 . V_32 ) ) ;
time = F_15 ( time , V_28 ) ;
}
V_3 -> V_33 = F_16 ( time ) ;
}
static inline int F_17 ( struct V_2 * V_3 )
{
return ( V_3 -> V_34 ||
F_18 ( V_35 ) ) ;
}
static inline int F_19 ( struct V_2 * V_3 )
{
if ( V_3 -> V_36 )
return F_16 ( V_37 / 2 ) ;
else
return F_16 ( V_37 ) ;
}
static long F_20 ( unsigned long time )
{
struct V_38 * V_39 ;
unsigned long V_40 = V_25 ;
F_21 ( & V_41 ) ;
F_22 (item, &timeout_list, ti_chain) {
int V_42 = V_39 -> V_42 ;
if ( V_40 > V_42 )
V_40 = V_42 ;
break;
}
F_23 ( & V_41 ) ;
return F_24 ( F_25 ( time , F_26 ( V_40 ) ) ,
F_27 () ) ;
}
void F_28 ( void )
{
F_29 ( V_43 , L_3 ) ;
V_44 = true ;
}
void F_30 ( void )
{
F_29 ( V_43 , L_4 ) ;
V_44 = false ;
}
static void F_31 ( struct V_2 * V_3 ,
unsigned long V_45 )
{
int V_46 ;
int V_47 ;
int V_48 ;
int V_49 ;
F_32 ( & V_3 -> V_50 ) ;
V_46 = V_3 -> V_26 ;
V_47 = V_3 -> V_51 ;
V_48 = V_3 -> V_52 ;
V_49 = V_44 && F_33 ( & V_3 -> V_53 , V_54 ) ;
V_3 -> V_51 = 0 ;
if ( F_34 ( V_3 -> V_33 - 5 * V_55 , V_45 ) &&
! V_47 ) {
F_35 ( & V_3 -> V_50 ) ;
return;
}
V_3 -> V_52 = 0 ;
F_35 ( & V_3 -> V_50 ) ;
F_29 ( V_46 == V_18 ? V_22 : V_43 , L_5 ,
V_3 -> V_19 -> V_20 . V_21 , F_9 ( V_3 -> V_19 ) ,
F_36 ( V_46 ) , V_46 , V_47 , V_48 ,
V_3 -> V_34 , V_3 -> V_56 , V_49 ) ;
if ( V_46 == V_27 && ! F_17 ( V_3 ) ) {
V_3 -> V_33 = F_19 ( V_3 ) ;
if ( ! V_3 -> V_57 )
F_37 ( V_3 ) ;
} else if ( V_46 != V_18 ||
V_3 -> V_19 -> V_58 ||
F_17 ( V_3 ) ) {
F_29 ( V_43 , L_6 ,
V_3 -> V_19 -> V_20 . V_21 , F_9 ( V_3 -> V_19 ) ,
F_36 ( V_46 ) ) ;
if ( V_47 ) {
F_32 ( & V_3 -> V_50 ) ;
V_3 -> V_51 = 1 ;
F_35 ( & V_3 -> V_50 ) ;
}
} else if ( ( V_3 -> V_56 && ! V_49 ) || V_48 || V_47 ) {
F_7 ( V_3 ) ;
}
}
static int F_38 ( void * V_59 )
{
struct V_60 * V_61 = V_59 ;
F_39 ( V_61 , V_62 ) ;
F_40 ( & V_61 -> V_63 ) ;
while ( 1 ) {
unsigned long V_45 = F_27 () ;
struct V_64 V_65 ;
long V_66 ;
struct V_38 * V_39 ;
struct V_67 * V_68 ;
F_21 ( & V_41 ) ;
F_22 (item, &timeout_list, ti_chain) {
V_39 -> V_69 ( V_39 , V_39 -> V_70 ) ;
}
F_41 (iter, &pinger_imports) {
struct V_2 * V_3 =
F_42 ( V_68 , struct V_2 ,
V_71 ) ;
F_31 ( V_3 , V_45 ) ;
if ( V_3 -> V_56 && V_3 -> V_33 &&
F_43 ( V_3 -> V_33 ,
F_25 ( V_45 ,
F_26 ( V_25 ) ) ) )
F_12 ( V_3 , 0 ) ;
}
F_23 ( & V_41 ) ;
V_66 = F_20 ( V_45 ) ;
F_29 ( V_22 , L_7 V_72 L_8 ,
V_66 ,
F_25 ( V_45 ,
F_26 ( V_25 ) ) ) ;
if ( V_66 > 0 ) {
V_65 = F_44 ( F_13 ( long , V_66 ,
F_26 ( 1 ) ) ,
NULL , NULL ) ;
F_45 ( V_61 -> V_63 ,
F_46 ( V_61 ) ||
F_47 ( V_61 ) ,
& V_65 ) ;
if ( F_48 ( V_61 , V_73 ) )
break;
F_48 ( V_61 , V_74 ) ;
}
}
F_39 ( V_61 , V_75 ) ;
F_40 ( & V_61 -> V_63 ) ;
F_29 ( V_76 , L_9 , F_49 () ) ;
return 0 ;
}
int F_50 ( void )
{
struct V_64 V_65 = { 0 } ;
struct V_77 * V_78 ;
int V_12 ;
if ( ! F_51 ( & V_79 ) &&
! F_52 ( & V_79 ) )
return - V_80 ;
F_53 ( & V_79 . V_63 ) ;
strcpy ( V_79 . V_81 , L_10 ) ;
V_78 = F_54 ( F_38 , & V_79 ,
V_79 . V_81 ) ;
if ( F_55 ( V_78 ) ) {
V_12 = F_56 ( V_78 ) ;
F_8 ( L_11 , V_12 ) ;
return V_12 ;
}
F_45 ( V_79 . V_63 ,
F_57 ( & V_79 ) , & V_65 ) ;
return 0 ;
}
int F_58 ( void )
{
struct V_64 V_65 = { 0 } ;
int V_12 = 0 ;
if ( F_51 ( & V_79 ) ||
F_52 ( & V_79 ) )
return - V_80 ;
F_59 () ;
F_39 ( & V_79 , V_73 ) ;
F_40 ( & V_79 . V_63 ) ;
F_45 ( V_79 . V_63 ,
F_52 ( & V_79 ) , & V_65 ) ;
return V_12 ;
}
void F_60 ( struct V_2 * V_3 )
{
F_12 ( V_3 , 0 ) ;
}
void F_61 ( struct V_2 * V_3 )
{
F_12 ( V_3 , 1 ) ;
F_62 ( & V_3 -> V_50 ) ;
if ( V_3 -> V_26 != V_18 ||
F_33 ( & V_3 -> V_53 , V_54 ) )
V_3 -> V_52 = 1 ;
}
int F_63 ( struct V_2 * V_3 )
{
if ( ! F_64 ( & V_3 -> V_71 ) )
return - V_80 ;
F_21 ( & V_41 ) ;
F_29 ( V_43 , L_12 ,
V_3 -> V_19 -> V_20 . V_21 , F_9 ( V_3 -> V_19 ) ) ;
V_3 -> V_19 -> V_58 = 0 ;
F_12 ( V_3 , 0 ) ;
F_65 ( & V_3 -> V_71 , & V_82 ) ;
F_66 ( V_3 ) ;
F_67 () ;
F_23 ( & V_41 ) ;
return 0 ;
}
int F_68 ( struct V_2 * V_3 )
{
if ( F_64 ( & V_3 -> V_71 ) )
return - V_83 ;
F_21 ( & V_41 ) ;
F_69 ( & V_3 -> V_71 ) ;
F_29 ( V_43 , L_13 ,
V_3 -> V_19 -> V_20 . V_21 , F_9 ( V_3 -> V_19 ) ) ;
V_3 -> V_19 -> V_58 = 1 ;
F_70 ( V_3 ) ;
F_23 ( & V_41 ) ;
return 0 ;
}
static struct V_38 * F_71 ( int time ,
enum V_84 V_85 ,
T_1 V_86 , void * V_87 )
{
struct V_38 * V_88 ;
V_88 = F_72 ( sizeof( * V_88 ) , V_89 ) ;
if ( ! V_88 )
return NULL ;
F_73 ( & V_88 -> V_90 ) ;
F_73 ( & V_88 -> V_91 ) ;
V_88 -> V_42 = time ;
V_88 -> V_92 = V_85 ;
V_88 -> V_69 = V_86 ;
V_88 -> V_70 = V_87 ;
return V_88 ;
}
static struct V_38 *
F_74 ( int time , enum V_84 V_85 ,
T_1 V_86 , void * V_87 )
{
struct V_38 * V_39 , * V_93 ;
F_75 ( F_76 ( & V_41 ) ) ;
F_22 (item, &timeout_list, ti_chain)
if ( V_39 -> V_92 == V_85 )
goto V_94;
V_39 = F_71 ( time , V_85 , V_86 , V_87 ) ;
if ( V_39 ) {
F_77 (tmp, &timeout_list, ti_chain) {
if ( V_93 -> V_42 < time ) {
F_78 ( & V_39 -> V_91 , & V_93 -> V_91 ) ;
goto V_94;
}
}
F_78 ( & V_39 -> V_91 , & V_95 ) ;
}
V_94:
return V_39 ;
}
int F_79 ( int time , enum V_84 V_85 ,
T_1 V_86 , void * V_87 ,
struct V_67 * V_96 )
{
struct V_38 * V_88 ;
F_21 ( & V_41 ) ;
V_88 = F_74 ( time , V_85 , V_86 , V_87 ) ;
if ( ! V_88 ) {
F_23 ( & V_41 ) ;
return - V_97 ;
}
F_78 ( V_96 , & V_88 -> V_90 ) ;
F_23 ( & V_41 ) ;
return 0 ;
}
int F_80 ( struct V_67 * V_96 ,
enum V_84 V_85 )
{
struct V_38 * V_88 = NULL , * V_39 ;
if ( F_64 ( V_96 ) )
return 0 ;
F_21 ( & V_41 ) ;
F_69 ( V_96 ) ;
F_22 (item, &timeout_list, ti_chain) {
if ( V_39 -> V_92 == V_85 ) {
V_88 = V_39 ;
break;
}
}
if ( F_64 ( & V_88 -> V_90 ) ) {
F_81 ( & V_88 -> V_91 ) ;
F_82 ( V_88 ) ;
}
F_23 ( & V_41 ) ;
return 0 ;
}
static int F_59 ( void )
{
struct V_38 * V_39 , * V_93 ;
F_21 ( & V_41 ) ;
F_83 (item, tmp, &timeout_list, ti_chain) {
F_75 ( F_64 ( & V_39 -> V_90 ) ) ;
F_81 ( & V_39 -> V_91 ) ;
F_82 ( V_39 ) ;
}
F_23 ( & V_41 ) ;
return 0 ;
}
void F_67 ( void )
{
F_84 ( & V_79 , V_74 ) ;
F_40 ( & V_79 . V_63 ) ;
}
