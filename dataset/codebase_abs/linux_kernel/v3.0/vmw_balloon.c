static bool F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 , V_4 ;
F_2 ( V_2 -> V_5 . V_6 ) ;
V_3 = F_3 ( V_7 , V_8 , V_4 ) ;
if ( V_3 == V_9 )
return true ;
F_4 ( L_1 , V_10 , V_3 ) ;
F_2 ( V_2 -> V_5 . V_11 ) ;
return false ;
}
static bool F_5 ( struct V_1 * V_2 , unsigned long V_3 )
{
switch ( V_3 ) {
case V_9 :
return true ;
case V_12 :
V_2 -> V_13 = true ;
default:
return false ;
}
}
static bool F_6 ( struct V_1 * V_2 )
{
unsigned long V_3 , V_4 ;
V_3 = F_3 ( V_14 , V_15 , V_4 ) ;
F_2 ( V_2 -> V_5 . V_16 ) ;
if ( F_5 ( V_2 , V_3 ) )
return true ;
F_4 ( L_1 , V_10 , V_3 ) ;
F_2 ( V_2 -> V_5 . V_17 ) ;
return false ;
}
static bool F_7 ( struct V_1 * V_2 , T_1 * V_18 )
{
unsigned long V_3 ;
unsigned long V_19 ;
unsigned long V_20 ;
T_1 V_21 ;
F_8 ( & V_2 -> V_22 ) ;
V_20 = V_2 -> V_22 . V_23 ;
V_21 = ( T_1 ) V_20 ;
if ( V_20 != V_21 )
return false ;
F_2 ( V_2 -> V_5 . V_19 ) ;
V_3 = F_3 ( V_24 , V_20 , V_19 ) ;
if ( F_5 ( V_2 , V_3 ) ) {
* V_18 = V_19 ;
return true ;
}
F_4 ( L_1 , V_10 , V_3 ) ;
F_2 ( V_2 -> V_5 . V_25 ) ;
return false ;
}
static bool F_9 ( struct V_1 * V_2 , unsigned long V_26 ,
unsigned int * V_27 )
{
unsigned long V_3 , V_4 ;
T_1 V_28 ;
V_28 = ( T_1 ) V_26 ;
if ( V_28 != V_26 )
return false ;
F_2 ( V_2 -> V_5 . V_29 ) ;
* V_27 = V_3 = F_3 ( V_30 , V_26 , V_4 ) ;
if ( F_5 ( V_2 , V_3 ) )
return true ;
F_4 ( L_2 , V_10 , V_26 , V_3 ) ;
F_2 ( V_2 -> V_5 . V_31 ) ;
return false ;
}
static bool F_10 ( struct V_1 * V_2 , unsigned long V_26 )
{
unsigned long V_3 , V_4 ;
T_1 V_28 ;
V_28 = ( T_1 ) V_26 ;
if ( V_28 != V_26 )
return false ;
F_2 ( V_2 -> V_5 . V_32 ) ;
V_3 = F_3 ( V_33 , V_26 , V_4 ) ;
if ( F_5 ( V_2 , V_3 ) )
return true ;
F_4 ( L_2 , V_10 , V_26 , V_3 ) ;
F_2 ( V_2 -> V_5 . V_34 ) ;
return false ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_35 * V_35 , * V_36 ;
unsigned int V_37 = 0 ;
F_12 (page, next, &b->pages, lru) {
F_13 ( & V_35 -> V_38 ) ;
F_14 ( V_35 ) ;
F_2 ( V_2 -> V_5 . free ) ;
V_2 -> V_39 -- ;
if ( ++ V_37 >= V_2 -> V_40 ) {
V_37 = 0 ;
F_15 () ;
}
}
}
static void F_16 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_13 = false ;
if ( ! F_6 ( V_2 ) )
F_17 ( L_3 ) ;
}
}
static int F_18 ( struct V_1 * V_2 , bool V_41 )
{
struct V_35 * V_35 ;
T_2 V_42 ;
unsigned int V_27 ;
bool V_43 = false ;
do {
if ( ! V_41 )
F_2 ( V_2 -> V_5 . V_44 ) ;
else
F_2 ( V_2 -> V_5 . V_45 ) ;
V_42 = V_41 ? V_46 : V_47 ;
V_35 = F_19 ( V_42 ) ;
if ( ! V_35 ) {
if ( ! V_41 )
F_2 ( V_2 -> V_5 . V_48 ) ;
else
F_2 ( V_2 -> V_5 . V_49 ) ;
return - V_50 ;
}
V_43 = F_9 ( V_2 , F_20 ( V_35 ) , & V_27 ) ;
if ( ! V_43 ) {
F_2 ( V_2 -> V_5 . V_51 ) ;
if ( V_27 == V_12 ||
V_27 == V_52 ) {
F_14 ( V_35 ) ;
return - V_53 ;
}
F_21 ( & V_35 -> V_38 , & V_2 -> V_54 ) ;
if ( ++ V_2 -> V_55 >= V_56 )
return - V_53 ;
}
} while ( ! V_43 );
F_21 ( & V_35 -> V_38 , & V_2 -> V_57 ) ;
V_2 -> V_39 ++ ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_35 * V_35 )
{
if ( ! F_10 ( V_2 , F_20 ( V_35 ) ) )
return - V_53 ;
F_13 ( & V_35 -> V_38 ) ;
F_14 ( V_35 ) ;
F_2 ( V_2 -> V_5 . free ) ;
V_2 -> V_39 -- ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_35 * V_35 , * V_36 ;
F_12 (page, next, &b->refused_pages, lru) {
F_13 ( & V_35 -> V_38 ) ;
F_14 ( V_35 ) ;
F_2 ( V_2 -> V_5 . V_58 ) ;
}
V_2 -> V_55 = 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
unsigned int V_59 ;
unsigned int V_60 ;
unsigned int V_61 ;
unsigned int V_62 = 0 ;
int error = 0 ;
bool V_63 = false ;
F_4 ( L_4 , V_10 , V_2 -> V_39 , V_2 -> V_19 ) ;
V_59 = V_2 -> V_19 - V_2 -> V_39 ;
V_60 = V_2 -> V_64 ?
V_2 -> V_65 : V_66 ;
F_4 ( L_5 ,
V_10 , V_59 , V_60 , V_2 -> V_65 ) ;
for ( V_61 = 0 ; V_61 < V_59 ; V_61 ++ ) {
error = F_18 ( V_2 , V_63 ) ;
if ( error ) {
if ( error != - V_50 ) {
break;
}
if ( V_63 ) {
V_2 -> V_65 = F_25 ( V_2 -> V_65 / 2 ,
V_67 ) ;
break;
}
V_2 -> V_64 = V_68 ;
if ( V_61 >= V_2 -> V_65 )
break;
V_63 = true ;
V_60 = V_2 -> V_65 ;
}
if ( ++ V_62 > V_69 ) {
F_15 () ;
V_62 = 0 ;
}
if ( V_61 >= V_60 ) {
break;
}
}
if ( error == 0 && V_61 >= V_2 -> V_65 ) {
unsigned int V_70 = V_61 / V_2 -> V_65 ;
V_2 -> V_65 =
F_26 ( V_2 -> V_65 + V_70 * V_71 ,
V_72 ) ;
}
F_23 ( V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_35 * V_35 , * V_36 ;
unsigned int V_61 = 0 ;
unsigned int V_59 ;
int error ;
F_4 ( L_4 , V_10 , V_2 -> V_39 , V_2 -> V_19 ) ;
V_59 = F_26 ( V_2 -> V_39 - V_2 -> V_19 , V_2 -> V_40 ) ;
F_4 ( L_6 , V_10 , V_59 , V_2 -> V_40 ) ;
F_12 (page, next, &b->pages, lru) {
error = F_22 ( V_2 , V_35 ) ;
if ( error ) {
V_2 -> V_40 = F_25 ( V_2 -> V_40 / 2 ,
V_73 ) ;
return;
}
if ( ++ V_61 >= V_59 )
break;
}
V_2 -> V_40 = F_26 ( V_2 -> V_40 + V_74 ,
V_75 ) ;
}
static void F_28 ( struct V_76 * V_77 )
{
struct V_78 * V_79 = F_29 ( V_77 ) ;
struct V_1 * V_2 = F_30 ( V_79 , struct V_1 , V_79 ) ;
unsigned int V_19 ;
F_2 ( V_2 -> V_5 . V_80 ) ;
if ( V_2 -> V_13 )
F_16 ( V_2 ) ;
if ( V_2 -> V_64 > 0 )
V_2 -> V_64 -- ;
if ( F_7 ( V_2 , & V_19 ) ) {
V_2 -> V_19 = V_19 ;
if ( V_2 -> V_39 < V_19 )
F_24 ( V_2 ) ;
else if ( V_2 -> V_39 > V_19 )
F_27 ( V_2 ) ;
}
F_31 ( V_81 , V_79 , F_32 ( V_82 ) ) ;
}
static int F_33 ( struct V_83 * V_84 , void * V_85 )
{
struct V_1 * V_2 = V_84 -> V_86 ;
struct V_87 * V_5 = & V_2 -> V_5 ;
F_34 ( V_84 ,
L_7
L_8 ,
V_2 -> V_19 , V_2 -> V_39 ) ;
F_34 ( V_84 ,
L_9
L_10
L_11 ,
V_66 ,
V_2 -> V_65 , V_2 -> V_40 ) ;
F_34 ( V_84 ,
L_12
L_13
L_14
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22
L_23 ,
V_5 -> V_80 ,
V_5 -> V_6 , V_5 -> V_11 ,
V_5 -> V_16 , V_5 -> V_17 ,
V_5 -> V_29 , V_5 -> V_31 ,
V_5 -> V_32 , V_5 -> V_34 ,
V_5 -> V_19 , V_5 -> V_25 ,
V_5 -> V_44 , V_5 -> V_48 ,
V_5 -> V_45 , V_5 -> V_49 ,
V_5 -> free ,
V_5 -> V_51 , V_5 -> V_58 ) ;
return 0 ;
}
static int F_35 ( struct V_88 * V_88 , struct V_89 * V_89 )
{
return F_36 ( V_89 , F_33 , V_88 -> V_90 ) ;
}
static int T_3 F_37 ( struct V_1 * V_2 )
{
int error ;
V_2 -> V_91 = F_38 ( L_24 , V_92 , NULL , V_2 ,
& V_93 ) ;
if ( F_39 ( V_2 -> V_91 ) ) {
error = F_40 ( V_2 -> V_91 ) ;
F_17 ( L_25 , error ) ;
return error ;
}
return 0 ;
}
static void T_4 F_41 ( struct V_1 * V_2 )
{
F_42 ( V_2 -> V_91 ) ;
}
static inline int F_37 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_41 ( struct V_1 * V_2 )
{
}
static int T_3 F_43 ( void )
{
int error ;
if ( V_94 != & V_95 )
return - V_96 ;
V_81 = F_44 ( L_24 ) ;
if ( ! V_81 ) {
F_17 ( L_26 ) ;
return - V_50 ;
}
F_45 ( & V_97 . V_57 ) ;
F_45 ( & V_97 . V_54 ) ;
V_97 . V_65 = V_72 ;
V_97 . V_40 = V_75 ;
F_46 ( & V_97 . V_79 , F_28 ) ;
if ( ! F_1 ( & V_97 ) ) {
F_17 ( L_27 ) ;
error = - V_53 ;
goto V_98;
}
if ( ! F_6 ( & V_97 ) ) {
F_17 ( L_3 ) ;
error = - V_53 ;
goto V_98;
}
error = F_37 ( & V_97 ) ;
if ( error )
goto V_98;
F_31 ( V_81 , & V_97 . V_79 , 0 ) ;
return 0 ;
V_98:
F_47 ( V_81 ) ;
return error ;
}
static void T_4 F_48 ( void )
{
F_49 ( & V_97 . V_79 ) ;
F_47 ( V_81 ) ;
F_41 ( & V_97 ) ;
F_1 ( & V_97 ) ;
F_11 ( & V_97 ) ;
}
