static bool F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 , V_4 ;
F_2 ( V_2 -> V_5 . V_6 ) ;
V_3 = F_3 ( V_7 , V_8 ,
V_4 ) ;
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
unsigned long V_3 , V_14 ;
V_3 = F_3 ( V_15 , V_16 , V_14 ) ;
F_2 ( V_2 -> V_5 . V_17 ) ;
if ( F_5 ( V_2 , V_3 ) )
return true ;
F_4 ( L_1 , V_10 , V_3 ) ;
F_2 ( V_2 -> V_5 . V_18 ) ;
return false ;
}
static bool F_7 ( struct V_1 * V_2 , T_1 * V_19 )
{
unsigned long V_3 ;
unsigned long V_20 ;
unsigned long V_21 ;
T_1 V_22 ;
F_8 ( & V_2 -> V_23 ) ;
V_21 = V_2 -> V_23 . V_24 ;
V_22 = ( T_1 ) V_21 ;
if ( V_21 != V_22 )
return false ;
F_2 ( V_2 -> V_5 . V_20 ) ;
V_3 = F_3 ( V_25 , V_21 , V_20 ) ;
if ( F_5 ( V_2 , V_3 ) ) {
* V_19 = V_20 ;
return true ;
}
F_4 ( L_1 , V_10 , V_3 ) ;
F_2 ( V_2 -> V_5 . V_26 ) ;
return false ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long V_27 ,
unsigned int * V_28 )
{
unsigned long V_3 , V_14 ;
T_1 V_29 ;
V_29 = ( T_1 ) V_27 ;
if ( V_29 != V_27 )
return - 1 ;
F_2 ( V_2 -> V_5 . V_30 ) ;
* V_28 = V_3 = F_3 ( V_31 , V_27 , V_14 ) ;
if ( F_5 ( V_2 , V_3 ) )
return 0 ;
F_4 ( L_2 , V_10 , V_27 , V_3 ) ;
F_2 ( V_2 -> V_5 . V_32 ) ;
return 1 ;
}
static bool F_10 ( struct V_1 * V_2 , unsigned long V_27 )
{
unsigned long V_3 , V_14 ;
T_1 V_29 ;
V_29 = ( T_1 ) V_27 ;
if ( V_29 != V_27 )
return false ;
F_2 ( V_2 -> V_5 . V_33 ) ;
V_3 = F_3 ( V_34 , V_27 , V_14 ) ;
if ( F_5 ( V_2 , V_3 ) )
return true ;
F_4 ( L_2 , V_10 , V_27 , V_3 ) ;
F_2 ( V_2 -> V_5 . V_35 ) ;
return false ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_36 * V_36 , * V_37 ;
unsigned int V_38 = 0 ;
F_12 (page, next, &b->pages, lru) {
F_13 ( & V_36 -> V_39 ) ;
F_14 ( V_36 ) ;
F_2 ( V_2 -> V_5 . free ) ;
V_2 -> V_40 -- ;
if ( ++ V_38 >= V_2 -> V_41 ) {
V_38 = 0 ;
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
static int F_18 ( struct V_1 * V_2 , struct V_36 * V_36 )
{
int V_42 , V_28 ;
V_42 = F_9 ( V_2 , F_19 ( V_36 ) , & V_28 ) ;
if ( V_42 > 0 ) {
F_2 ( V_2 -> V_5 . V_43 ) ;
if ( V_28 == V_12 ||
V_28 == V_44 ) {
F_14 ( V_36 ) ;
return - V_45 ;
}
if ( V_2 -> V_46 < V_47 ) {
V_2 -> V_46 ++ ;
F_20 ( & V_36 -> V_39 , & V_2 -> V_48 ) ;
} else {
F_14 ( V_36 ) ;
}
return - V_45 ;
}
F_20 ( & V_36 -> V_39 , & V_2 -> V_49 ) ;
V_2 -> V_40 ++ ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_36 * V_36 )
{
if ( ! F_10 ( V_2 , F_19 ( V_36 ) ) )
return - V_45 ;
F_13 ( & V_36 -> V_39 ) ;
F_14 ( V_36 ) ;
F_2 ( V_2 -> V_5 . free ) ;
V_2 -> V_40 -- ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_36 * V_36 , * V_37 ;
F_12 (page, next, &b->refused_pages, lru) {
F_13 ( & V_36 -> V_39 ) ;
F_14 ( V_36 ) ;
F_2 ( V_2 -> V_5 . V_50 ) ;
}
V_2 -> V_46 = 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
unsigned int V_51 ;
unsigned int V_52 ;
unsigned int V_53 ;
unsigned int V_54 = 0 ;
int error = 0 ;
T_2 V_55 = V_56 ;
F_4 ( L_4 , V_10 , V_2 -> V_40 , V_2 -> V_20 ) ;
V_51 = V_2 -> V_20 - V_2 -> V_40 ;
V_52 = V_2 -> V_57 ?
V_2 -> V_58 : V_59 ;
F_4 ( L_5 ,
V_10 , V_51 , V_52 , V_2 -> V_58 ) ;
for ( V_53 = 0 ; V_53 < V_51 ; V_53 ++ ) {
struct V_36 * V_36 ;
if ( V_55 == V_56 )
F_2 ( V_2 -> V_5 . V_60 ) ;
else
F_2 ( V_2 -> V_5 . V_61 ) ;
V_36 = F_24 ( V_55 ) ;
if ( ! V_36 ) {
if ( V_55 == V_62 ) {
V_2 -> V_58 = F_25 ( V_2 -> V_58 / 2 ,
V_63 ) ;
F_2 ( V_2 -> V_5 . V_64 ) ;
break;
}
F_2 ( V_2 -> V_5 . V_65 ) ;
V_2 -> V_57 = V_66 ;
if ( V_53 >= V_2 -> V_58 )
break;
V_55 = V_62 ;
V_52 = V_2 -> V_58 ;
continue;
}
error = F_18 ( V_2 , V_36 ) ;
if ( error )
break;
if ( ++ V_54 > V_67 ) {
F_15 () ;
V_54 = 0 ;
}
if ( V_53 >= V_52 ) {
break;
}
}
if ( error == 0 && V_53 >= V_2 -> V_58 ) {
unsigned int V_68 = V_53 / V_2 -> V_58 ;
V_2 -> V_58 =
F_26 ( V_2 -> V_58 + V_68 * V_69 ,
V_70 ) ;
}
F_22 ( V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_36 * V_36 , * V_37 ;
unsigned int V_53 = 0 ;
unsigned int V_51 ;
int error ;
F_4 ( L_4 , V_10 , V_2 -> V_40 , V_2 -> V_20 ) ;
V_51 = F_26 ( V_2 -> V_40 - V_2 -> V_20 , V_2 -> V_41 ) ;
F_4 ( L_6 , V_10 , V_51 , V_2 -> V_41 ) ;
F_12 (page, next, &b->pages, lru) {
error = F_21 ( V_2 , V_36 ) ;
if ( error ) {
V_2 -> V_41 = F_25 ( V_2 -> V_41 / 2 ,
V_71 ) ;
return;
}
if ( ++ V_53 >= V_51 )
break;
}
V_2 -> V_41 = F_26 ( V_2 -> V_41 + V_72 ,
V_73 ) ;
}
static void F_28 ( struct V_74 * V_75 )
{
struct V_76 * V_77 = F_29 ( V_75 ) ;
struct V_1 * V_2 = F_30 ( V_77 , struct V_1 , V_77 ) ;
unsigned int V_20 ;
F_2 ( V_2 -> V_5 . V_78 ) ;
if ( V_2 -> V_13 )
F_16 ( V_2 ) ;
if ( V_2 -> V_57 > 0 )
V_2 -> V_57 -- ;
if ( F_7 ( V_2 , & V_20 ) ) {
V_2 -> V_20 = V_20 ;
if ( V_2 -> V_40 < V_20 )
F_23 ( V_2 ) ;
else if ( V_2 -> V_40 > V_20 )
F_27 ( V_2 ) ;
}
F_31 ( V_79 ,
V_77 , F_32 ( V_80 ) ) ;
}
static int F_33 ( struct V_81 * V_82 , void * V_83 )
{
struct V_1 * V_2 = V_82 -> V_84 ;
struct V_85 * V_5 = & V_2 -> V_5 ;
F_34 ( V_82 ,
L_7
L_8 ,
V_2 -> V_20 , V_2 -> V_40 ) ;
F_34 ( V_82 ,
L_9
L_10
L_11 ,
V_59 ,
V_2 -> V_58 , V_2 -> V_41 ) ;
F_34 ( V_82 ,
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
V_5 -> V_78 ,
V_5 -> V_6 , V_5 -> V_11 ,
V_5 -> V_17 , V_5 -> V_18 ,
V_5 -> V_30 , V_5 -> V_32 ,
V_5 -> V_33 , V_5 -> V_35 ,
V_5 -> V_20 , V_5 -> V_26 ,
V_5 -> V_60 , V_5 -> V_65 ,
V_5 -> V_61 , V_5 -> V_64 ,
V_5 -> free ,
V_5 -> V_43 , V_5 -> V_50 ) ;
return 0 ;
}
static int F_35 ( struct V_86 * V_86 , struct V_87 * V_87 )
{
return F_36 ( V_87 , F_33 , V_86 -> V_88 ) ;
}
static int T_3 F_37 ( struct V_1 * V_2 )
{
int error ;
V_2 -> V_89 = F_38 ( L_24 , V_90 , NULL , V_2 ,
& V_91 ) ;
if ( F_39 ( V_2 -> V_89 ) ) {
error = F_40 ( V_2 -> V_89 ) ;
F_17 ( L_25 , error ) ;
return error ;
}
return 0 ;
}
static void T_4 F_41 ( struct V_1 * V_2 )
{
F_42 ( V_2 -> V_89 ) ;
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
if ( V_92 != & V_93 )
return - V_94 ;
F_44 ( & V_95 . V_49 ) ;
F_44 ( & V_95 . V_48 ) ;
V_95 . V_58 = V_70 ;
V_95 . V_41 = V_73 ;
F_45 ( & V_95 . V_77 , F_28 ) ;
if ( ! F_1 ( & V_95 ) ) {
F_17 ( L_26 ) ;
return - V_45 ;
}
if ( ! F_6 ( & V_95 ) ) {
F_17 ( L_3 ) ;
return - V_45 ;
}
error = F_37 ( & V_95 ) ;
if ( error )
return error ;
F_31 ( V_79 , & V_95 . V_77 , 0 ) ;
return 0 ;
}
static void T_4 F_46 ( void )
{
F_47 ( & V_95 . V_77 ) ;
F_41 ( & V_95 ) ;
F_1 ( & V_95 ) ;
F_11 ( & V_95 ) ;
}
