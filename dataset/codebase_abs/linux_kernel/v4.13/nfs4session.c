static void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
V_2 -> V_4 = V_5 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 ( & V_2 -> V_7 , V_3 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( & V_2 -> V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_10 )
{
struct V_11 * * V_12 ;
if ( V_10 >= V_2 -> V_13 )
return;
V_12 = & V_2 -> V_14 ;
while ( V_10 -- )
V_12 = & ( * V_12 ) -> V_15 ;
while ( * V_12 ) {
struct V_11 * V_16 = * V_12 ;
* V_12 = V_16 -> V_15 ;
F_7 ( V_16 ) ;
V_2 -> V_13 -- ;
}
}
void F_8 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 ) )
V_9 ( & V_2 -> V_9 ) ;
}
void F_10 ( struct V_1 * V_2 , struct V_11 * V_16 )
{
T_1 V_17 = V_16 -> V_18 ;
F_11 ( V_17 , V_2 -> V_19 ) ;
if ( V_17 == V_2 -> V_4 ) {
T_1 V_20 = F_12 ( V_2 -> V_19 , V_17 ) ;
if ( V_20 < V_17 )
V_2 -> V_4 = V_20 ;
else {
V_2 -> V_4 = V_5 ;
F_8 ( V_2 ) ;
}
}
F_13 ( L_1 , V_21 ,
V_17 , V_2 -> V_4 ) ;
}
static struct V_11 * F_14 ( struct V_1 * V_2 ,
T_1 V_17 , T_1 V_22 , T_2 V_23 )
{
struct V_11 * V_16 ;
V_16 = F_15 ( sizeof( * V_16 ) , V_23 ) ;
if ( V_16 ) {
V_16 -> V_24 = V_2 ;
V_16 -> V_18 = V_17 ;
V_16 -> V_25 = V_22 ;
}
return V_16 ;
}
static struct V_11 * F_16 ( struct V_1 * V_2 ,
T_1 V_17 , T_1 V_22 , T_2 V_23 )
{
struct V_11 * * V_12 , * V_16 ;
V_12 = & V_2 -> V_14 ;
for (; ; ) {
if ( * V_12 == NULL ) {
* V_12 = F_14 ( V_2 , V_2 -> V_13 ,
V_22 , V_23 ) ;
if ( * V_12 == NULL )
break;
V_2 -> V_13 ++ ;
}
V_16 = * V_12 ;
if ( V_16 -> V_18 == V_17 )
return V_16 ;
V_12 = & V_16 -> V_15 ;
}
return F_17 ( - V_26 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_11 * V_16 )
{
T_1 V_17 = V_16 -> V_18 ;
F_19 ( V_17 , V_2 -> V_19 ) ;
if ( V_17 > V_2 -> V_4 ||
V_2 -> V_4 == V_5 )
V_2 -> V_4 = V_17 ;
V_16 -> V_27 = V_2 -> V_27 ;
}
bool F_20 ( struct V_1 * V_2 , struct V_11 * V_16 )
{
if ( F_21 ( V_2 , V_16 -> V_18 ) )
return false ;
F_18 ( V_2 , V_16 ) ;
return true ;
}
struct V_11 * F_22 ( struct V_1 * V_2 , T_1 V_17 )
{
if ( V_17 <= V_2 -> V_28 )
return F_16 ( V_2 , V_17 , 0 , V_29 ) ;
return F_17 ( - V_30 ) ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_17 ,
T_1 * V_25 )
__must_hold( &tbl->slot_tbl_lock
static bool F_24 ( struct V_1 * V_2 ,
T_1 V_17 , T_1 V_25 )
{
T_1 V_31 = 0 ;
bool V_32 = false ;
F_25 ( & V_2 -> V_6 ) ;
if ( F_23 ( V_2 , V_17 , & V_31 ) == 0 &&
V_31 == V_25 && F_26 ( V_17 , V_2 -> V_19 ) )
V_32 = true ;
F_27 ( & V_2 -> V_6 ) ;
return V_32 ;
}
int F_28 ( struct V_1 * V_2 ,
T_1 V_17 , T_1 V_25 ,
unsigned long V_33 )
{
if ( F_29 ( V_2 -> V_8 ,
! F_24 ( V_2 , V_17 , V_25 ) ,
V_33 ) == 0 )
return - V_34 ;
return 0 ;
}
struct V_11 * F_30 ( struct V_1 * V_2 )
{
struct V_11 * V_32 = F_17 ( - V_35 ) ;
T_1 V_17 ;
F_13 ( L_2 ,
V_21 , V_2 -> V_19 [ 0 ] , V_2 -> V_4 ,
V_2 -> V_28 + 1 ) ;
V_17 = F_31 ( V_2 -> V_19 , V_2 -> V_28 + 1 ) ;
if ( V_17 <= V_2 -> V_28 ) {
V_32 = F_16 ( V_2 , V_17 , 1 , V_29 ) ;
if ( ! F_32 ( V_32 ) )
F_18 ( V_2 , V_32 ) ;
}
F_13 ( L_3 ,
V_21 , V_2 -> V_19 [ 0 ] , V_2 -> V_4 ,
! F_32 ( V_32 ) ? V_32 -> V_18 : V_5 ) ;
return V_32 ;
}
static int F_33 ( struct V_1 * V_2 ,
T_1 V_36 , T_1 V_37 )
{
if ( V_36 <= V_2 -> V_13 )
return 0 ;
if ( ! F_32 ( F_16 ( V_2 , V_36 - 1 , V_37 , V_38 ) ) )
return 0 ;
return - V_26 ;
}
static void F_34 ( struct V_1 * V_2 ,
T_1 V_39 ,
T_1 V_37 )
{
struct V_11 * * V_12 ;
F_6 ( V_2 , V_39 + 1 ) ;
V_12 = & V_2 -> V_14 ;
while ( * V_12 ) {
( * V_12 ) -> V_25 = V_37 ;
( * V_12 ) -> V_40 = 0 ;
V_12 = & ( * V_12 ) -> V_15 ;
}
V_2 -> V_4 = V_5 ;
V_2 -> V_41 = V_39 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_42 = 0 ;
V_2 -> V_43 = 0 ;
V_2 -> V_28 = V_39 ;
}
static int F_35 ( struct V_1 * V_2 ,
T_1 V_36 , T_1 V_37 )
{
int V_32 ;
F_13 ( L_4 , V_21 ,
V_36 , V_2 -> V_13 ) ;
if ( V_36 > V_44 )
V_36 = V_44 ;
V_32 = F_33 ( V_2 , V_36 , V_37 ) ;
if ( V_32 )
goto V_45;
F_25 ( & V_2 -> V_6 ) ;
F_34 ( V_2 , V_36 - 1 , V_37 ) ;
F_27 ( & V_2 -> V_6 ) ;
F_13 ( L_5 , V_21 ,
V_2 , V_2 -> V_14 , V_2 -> V_13 ) ;
V_45:
F_13 ( L_6 , V_21 , V_32 ) ;
return V_32 ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_6 ( V_2 , 0 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
F_36 ( V_2 ) ;
F_38 ( & V_2 -> V_7 ) ;
}
int F_39 ( struct V_1 * V_2 , unsigned int V_36 ,
const char * V_3 )
{
F_1 ( V_2 , V_3 ) ;
return F_35 ( V_2 , V_36 , 0 ) ;
}
static bool F_40 ( struct V_46 * V_47 , void * V_48 )
{
struct V_49 * args = V_47 -> V_50 . V_51 ;
struct V_52 * V_53 = V_47 -> V_50 . V_54 ;
struct V_11 * V_16 = V_48 ;
struct V_1 * V_2 = V_16 -> V_24 ;
if ( F_9 ( V_2 ) && ! args -> V_55 )
return false ;
V_16 -> V_27 = V_2 -> V_27 ;
args -> V_56 = V_16 ;
V_53 -> V_57 = V_58 ;
V_53 -> V_59 = V_16 ;
V_53 -> V_60 = 0 ;
V_53 -> V_61 = 1 ;
return true ;
}
static bool F_41 ( struct V_1 * V_2 ,
struct V_11 * V_16 )
{
if ( F_42 ( & V_2 -> V_7 , F_40 , V_16 ) )
return true ;
return false ;
}
bool F_43 ( struct V_1 * V_2 ,
struct V_11 * V_16 )
{
if ( V_16 -> V_18 > V_2 -> V_28 )
return false ;
return F_41 ( V_2 , V_16 ) ;
}
static bool F_44 ( struct V_1 * V_2 )
{
struct V_11 * V_16 = F_30 ( V_2 ) ;
if ( ! F_32 ( V_16 ) ) {
bool V_32 = F_41 ( V_2 , V_16 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_16 ) ;
}
return false ;
}
void F_45 ( struct V_1 * V_2 )
{
for (; ; ) {
if ( ! F_44 ( V_2 ) )
break;
}
}
static void F_46 ( struct V_1 * V_2 ,
T_1 V_41 )
{
T_1 V_28 ;
V_28 = F_47 ( V_44 - 1 , V_41 ) ;
if ( V_28 > V_2 -> V_39 )
V_28 = V_2 -> V_39 ;
if ( V_28 > V_2 -> V_41 )
V_28 = V_2 -> V_41 ;
V_2 -> V_28 = V_28 ;
F_45 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
T_1 V_41 )
{
if ( V_2 -> V_41 == V_41 )
return;
V_2 -> V_41 = V_41 ;
V_2 -> V_27 ++ ;
}
void F_49 ( struct V_1 * V_2 ,
T_1 V_41 )
{
F_25 ( & V_2 -> V_6 ) ;
F_48 ( V_2 , V_41 ) ;
V_2 -> V_42 = 0 ;
V_2 -> V_43 = 0 ;
F_46 ( V_2 , V_41 ) ;
F_27 ( & V_2 -> V_6 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
T_1 V_62 )
{
if ( V_2 -> V_39 == V_62 )
return;
if ( V_2 -> V_4 > V_62 )
return;
F_6 ( V_2 , V_62 + 1 ) ;
V_2 -> V_39 = V_62 ;
}
static T_3 F_51 ( T_3 V_63 , T_3 V_64 )
{
V_63 -= V_64 ;
if ( V_63 == 0 )
return 0 ;
if ( V_63 < 0 )
return ( V_63 - 1 ) >> 1 ;
return ( V_63 + 1 ) >> 1 ;
}
static int F_52 ( T_3 V_63 )
{
if ( V_63 > 0 )
return 1 ;
if ( V_63 < 0 )
return - 1 ;
return 0 ;
}
static bool F_53 ( T_3 V_63 , T_3 V_64 )
{
if ( ! V_63 || ! V_64 )
return true ;
return F_52 ( V_63 ) == F_52 ( V_64 ) ;
}
static bool F_54 ( struct V_1 * V_2 ,
T_1 V_65 )
{
T_3 V_66 , V_67 ;
bool V_32 = true ;
V_66 = F_51 ( V_65 ,
V_2 -> V_41 ) ;
V_67 = F_51 ( V_66 ,
V_2 -> V_42 ) ;
if ( F_53 ( V_66 , V_2 -> V_42 ) )
V_32 = false ;
if ( F_53 ( V_67 , V_2 -> V_43 ) )
V_32 = false ;
V_2 -> V_42 = V_66 ;
V_2 -> V_43 = V_67 ;
return V_32 ;
}
void F_55 ( struct V_1 * V_2 ,
struct V_11 * V_16 ,
struct V_52 * V_53 )
{
F_25 ( & V_2 -> V_6 ) ;
if ( ! F_54 ( V_2 , V_53 -> V_68 ) )
F_48 ( V_2 , V_53 -> V_68 ) ;
if ( V_2 -> V_27 == V_16 -> V_27 )
F_50 ( V_2 , V_53 -> V_69 ) ;
F_46 ( V_2 , V_53 -> V_68 ) ;
F_27 ( & V_2 -> V_6 ) ;
}
static void F_56 ( struct V_70 * V_71 )
{
F_36 ( & V_71 -> V_72 ) ;
F_36 ( & V_71 -> V_73 ) ;
}
int F_57 ( struct V_70 * V_74 )
{
struct V_1 * V_2 ;
int V_75 ;
F_13 ( L_7 , V_21 ) ;
V_2 = & V_74 -> V_72 ;
V_2 -> V_71 = V_74 ;
V_75 = F_35 ( V_2 , V_74 -> V_76 . V_36 , 1 ) ;
if ( V_75 || ! ( V_74 -> V_77 & V_78 ) )
return V_75 ;
V_2 = & V_74 -> V_73 ;
V_2 -> V_71 = V_74 ;
V_75 = F_35 ( V_2 , V_74 -> V_79 . V_36 , 0 ) ;
if ( V_75 && V_2 -> V_14 == NULL )
F_56 ( V_74 ) ;
return V_75 ;
}
struct V_70 * F_58 ( struct V_80 * V_81 )
{
struct V_70 * V_71 ;
V_71 = F_15 ( sizeof( struct V_70 ) , V_38 ) ;
if ( ! V_71 )
return NULL ;
F_1 ( & V_71 -> V_72 , L_8 ) ;
F_1 ( & V_71 -> V_73 , L_9 ) ;
V_71 -> V_82 = 1 << V_83 ;
V_71 -> V_81 = V_81 ;
return V_71 ;
}
static void F_59 ( struct V_70 * V_71 )
{
F_37 ( & V_71 -> V_72 ) ;
F_37 ( & V_71 -> V_73 ) ;
}
void F_60 ( struct V_70 * V_71 )
{
struct V_84 * V_85 ;
struct V_86 * V_87 ;
V_87 = F_61 ( V_71 -> V_81 ) ;
F_62 ( V_71 , V_87 ) ;
if ( V_87 )
F_63 ( V_87 ) ;
F_64 () ;
V_85 = F_65 ( V_71 -> V_81 -> V_88 -> V_89 ) ;
F_66 () ;
F_13 ( L_10 ,
V_21 , V_85 ) ;
F_67 ( V_85 , V_90 ) ;
F_59 ( V_71 ) ;
F_7 ( V_71 ) ;
}
static int F_68 ( struct V_80 * V_81 )
{
int V_32 ;
if ( V_81 -> V_91 == V_92 ) {
V_32 = F_69 ( V_81 ) ;
if ( V_32 )
return V_32 ;
}
if ( V_81 -> V_91 < V_93 )
return - V_94 ;
F_70 () ;
return 0 ;
}
int F_71 ( struct V_80 * V_81 )
{
if ( ! F_72 ( V_81 ) )
return 0 ;
F_73 ( V_83 , & V_81 -> V_95 -> V_82 ) ;
return F_68 ( V_81 ) ;
}
int F_74 ( struct V_80 * V_81 , unsigned long V_96 )
{
struct V_70 * V_71 = V_81 -> V_95 ;
int V_32 ;
F_25 ( & V_81 -> V_97 ) ;
if ( F_75 ( V_83 , & V_71 -> V_82 ) ) {
V_81 -> V_98 = V_96 ;
V_81 -> V_99 = V_58 ;
}
F_27 ( & V_81 -> V_97 ) ;
V_32 = F_68 ( V_81 ) ;
if ( V_32 )
return V_32 ;
if ( ! F_76 ( V_81 ) )
return - V_100 ;
return 0 ;
}
