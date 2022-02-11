static void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
V_2 -> V_4 = V_5 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 ( & V_2 -> V_7 , V_3 ) ;
F_4 ( & V_2 -> V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_9 )
{
struct V_10 * * V_11 ;
if ( V_9 >= V_2 -> V_12 )
return;
V_11 = & V_2 -> V_13 ;
while ( V_9 -- )
V_11 = & ( * V_11 ) -> V_14 ;
while ( * V_11 ) {
struct V_10 * V_15 = * V_11 ;
* V_11 = V_15 -> V_14 ;
F_6 ( V_15 ) ;
V_2 -> V_12 -- ;
}
}
void F_7 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 ) )
V_8 ( & V_2 -> V_8 ) ;
}
void F_9 ( struct V_1 * V_2 , struct V_10 * V_15 )
{
T_1 V_16 = V_15 -> V_17 ;
F_10 ( V_16 , V_2 -> V_18 ) ;
if ( V_16 == V_2 -> V_4 ) {
T_1 V_19 = F_11 ( V_2 -> V_18 , V_16 ) ;
if ( V_19 < V_16 )
V_2 -> V_4 = V_19 ;
else {
V_2 -> V_4 = V_5 ;
F_7 ( V_2 ) ;
}
}
F_12 ( L_1 , V_20 ,
V_16 , V_2 -> V_4 ) ;
}
static struct V_10 * F_13 ( struct V_1 * V_2 ,
T_1 V_16 , T_1 V_21 , T_2 V_22 )
{
struct V_10 * V_15 ;
V_15 = F_14 ( sizeof( * V_15 ) , V_22 ) ;
if ( V_15 ) {
V_15 -> V_23 = V_2 ;
V_15 -> V_17 = V_16 ;
V_15 -> V_24 = V_21 ;
}
return V_15 ;
}
static struct V_10 * F_15 ( struct V_1 * V_2 ,
T_1 V_16 , T_1 V_21 , T_2 V_22 )
{
struct V_10 * * V_11 , * V_15 ;
V_11 = & V_2 -> V_13 ;
for (; ; ) {
if ( * V_11 == NULL ) {
* V_11 = F_13 ( V_2 , V_2 -> V_12 ,
V_21 , V_22 ) ;
if ( * V_11 == NULL )
break;
V_2 -> V_12 ++ ;
}
V_15 = * V_11 ;
if ( V_15 -> V_17 == V_16 )
return V_15 ;
V_11 = & V_15 -> V_14 ;
}
return F_16 ( - V_25 ) ;
}
struct V_10 * F_17 ( struct V_1 * V_2 )
{
struct V_10 * V_26 = F_16 ( - V_27 ) ;
T_1 V_16 ;
F_12 ( L_2 ,
V_20 , V_2 -> V_18 [ 0 ] , V_2 -> V_4 ,
V_2 -> V_28 + 1 ) ;
V_16 = F_18 ( V_2 -> V_18 , V_2 -> V_28 + 1 ) ;
if ( V_16 > V_2 -> V_28 )
goto V_29;
V_26 = F_15 ( V_2 , V_16 , 1 , V_30 ) ;
if ( F_19 ( V_26 ) )
goto V_29;
F_20 ( V_16 , V_2 -> V_18 ) ;
if ( V_16 > V_2 -> V_4 ||
V_2 -> V_4 == V_5 )
V_2 -> V_4 = V_16 ;
V_26 -> V_31 = V_2 -> V_31 ;
V_29:
F_12 ( L_3 ,
V_20 , V_2 -> V_18 [ 0 ] , V_2 -> V_4 ,
! F_19 ( V_26 ) ? V_26 -> V_17 : V_5 ) ;
return V_26 ;
}
static int F_21 ( struct V_1 * V_2 ,
T_1 V_32 , T_1 V_33 )
{
if ( V_32 <= V_2 -> V_12 )
return 0 ;
if ( ! F_19 ( F_15 ( V_2 , V_32 - 1 , V_33 , V_34 ) ) )
return 0 ;
return - V_25 ;
}
static void F_22 ( struct V_1 * V_2 ,
T_1 V_35 ,
T_1 V_33 )
{
struct V_10 * * V_11 ;
F_5 ( V_2 , V_35 + 1 ) ;
V_11 = & V_2 -> V_13 ;
while ( * V_11 ) {
( * V_11 ) -> V_24 = V_33 ;
( * V_11 ) -> V_36 = 0 ;
V_11 = & ( * V_11 ) -> V_14 ;
}
V_2 -> V_4 = V_5 ;
V_2 -> V_37 = V_35 ;
V_2 -> V_35 = V_35 ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = 0 ;
V_2 -> V_28 = V_35 ;
}
static int F_23 ( struct V_1 * V_2 ,
T_1 V_32 , T_1 V_33 )
{
int V_26 ;
F_12 ( L_4 , V_20 ,
V_32 , V_2 -> V_12 ) ;
if ( V_32 > V_40 )
V_32 = V_40 ;
V_26 = F_21 ( V_2 , V_32 , V_33 ) ;
if ( V_26 )
goto V_29;
F_24 ( & V_2 -> V_6 ) ;
F_22 ( V_2 , V_32 - 1 , V_33 ) ;
F_25 ( & V_2 -> V_6 ) ;
F_12 ( L_5 , V_20 ,
V_2 , V_2 -> V_13 , V_2 -> V_12 ) ;
V_29:
F_12 ( L_6 , V_20 , V_26 ) ;
return V_26 ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
F_28 ( & V_2 -> V_7 ) ;
}
int F_29 ( struct V_1 * V_2 , unsigned int V_32 ,
const char * V_3 )
{
F_1 ( V_2 , V_3 ) ;
return F_23 ( V_2 , V_32 , 0 ) ;
}
static bool F_30 ( struct V_41 * V_42 , void * V_43 )
{
struct V_44 * args = V_42 -> V_45 . V_46 ;
struct V_47 * V_48 = V_42 -> V_45 . V_49 ;
struct V_10 * V_15 = V_43 ;
struct V_1 * V_2 = V_15 -> V_23 ;
if ( F_8 ( V_2 ) && ! args -> V_50 )
return false ;
V_15 -> V_31 = V_2 -> V_31 ;
args -> V_51 = V_15 ;
V_48 -> V_52 = V_53 ;
V_48 -> V_54 = V_15 ;
V_48 -> V_55 = 0 ;
V_48 -> V_56 = 1 ;
return true ;
}
static bool F_31 ( struct V_1 * V_2 ,
struct V_10 * V_15 )
{
if ( F_32 ( & V_2 -> V_7 , F_30 , V_15 ) )
return true ;
return false ;
}
bool F_33 ( struct V_1 * V_2 ,
struct V_10 * V_15 )
{
if ( V_15 -> V_17 > V_2 -> V_28 )
return false ;
return F_31 ( V_2 , V_15 ) ;
}
static bool F_34 ( struct V_1 * V_2 )
{
struct V_10 * V_15 = F_17 ( V_2 ) ;
if ( ! F_19 ( V_15 ) ) {
bool V_26 = F_31 ( V_2 , V_15 ) ;
if ( V_26 )
return V_26 ;
F_9 ( V_2 , V_15 ) ;
}
return false ;
}
void F_35 ( struct V_1 * V_2 )
{
for (; ; ) {
if ( ! F_34 ( V_2 ) )
break;
}
}
static void F_36 ( struct V_1 * V_2 ,
T_1 V_37 )
{
T_1 V_28 ;
V_28 = F_37 ( V_40 - 1 , V_37 ) ;
if ( V_28 > V_2 -> V_35 )
V_28 = V_2 -> V_35 ;
if ( V_28 > V_2 -> V_37 )
V_28 = V_2 -> V_37 ;
V_2 -> V_28 = V_28 ;
F_35 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
T_1 V_37 )
{
if ( V_2 -> V_37 == V_37 )
return;
V_2 -> V_37 = V_37 ;
V_2 -> V_31 ++ ;
}
void F_39 ( struct V_1 * V_2 ,
T_1 V_37 )
{
F_24 ( & V_2 -> V_6 ) ;
F_38 ( V_2 , V_37 ) ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = 0 ;
F_36 ( V_2 , V_37 ) ;
F_25 ( & V_2 -> V_6 ) ;
}
static void F_40 ( struct V_1 * V_2 ,
T_1 V_57 )
{
if ( V_2 -> V_35 == V_57 )
return;
if ( V_2 -> V_4 > V_57 )
return;
F_5 ( V_2 , V_57 + 1 ) ;
V_2 -> V_35 = V_57 ;
}
static T_3 F_41 ( T_3 V_58 , T_3 V_59 )
{
V_58 -= V_59 ;
if ( V_58 == 0 )
return 0 ;
if ( V_58 < 0 )
return ( V_58 - 1 ) >> 1 ;
return ( V_58 + 1 ) >> 1 ;
}
static int F_42 ( T_3 V_58 )
{
if ( V_58 > 0 )
return 1 ;
if ( V_58 < 0 )
return - 1 ;
return 0 ;
}
static bool F_43 ( T_3 V_58 , T_3 V_59 )
{
if ( ! V_58 || ! V_59 )
return true ;
return F_42 ( V_58 ) == F_42 ( V_59 ) ;
}
static bool F_44 ( struct V_1 * V_2 ,
T_1 V_60 )
{
T_3 V_61 , V_62 ;
bool V_26 = true ;
V_61 = F_41 ( V_60 ,
V_2 -> V_37 ) ;
V_62 = F_41 ( V_61 ,
V_2 -> V_38 ) ;
if ( F_43 ( V_61 , V_2 -> V_38 ) )
V_26 = false ;
if ( F_43 ( V_62 , V_2 -> V_39 ) )
V_26 = false ;
V_2 -> V_38 = V_61 ;
V_2 -> V_39 = V_62 ;
return V_26 ;
}
void F_45 ( struct V_1 * V_2 ,
struct V_10 * V_15 ,
struct V_47 * V_48 )
{
F_24 ( & V_2 -> V_6 ) ;
if ( ! F_44 ( V_2 , V_48 -> V_63 ) )
F_38 ( V_2 , V_48 -> V_63 ) ;
if ( V_2 -> V_31 == V_15 -> V_31 )
F_40 ( V_2 , V_48 -> V_64 ) ;
F_36 ( V_2 , V_48 -> V_63 ) ;
F_25 ( & V_2 -> V_6 ) ;
}
static void F_46 ( struct V_65 * V_66 )
{
F_26 ( & V_66 -> V_67 ) ;
F_26 ( & V_66 -> V_68 ) ;
}
int F_47 ( struct V_65 * V_69 )
{
struct V_1 * V_2 ;
int V_70 ;
F_12 ( L_7 , V_20 ) ;
V_2 = & V_69 -> V_67 ;
V_2 -> V_66 = V_69 ;
V_70 = F_23 ( V_2 , V_69 -> V_71 . V_32 , 1 ) ;
if ( V_70 || ! ( V_69 -> V_72 & V_73 ) )
return V_70 ;
V_2 = & V_69 -> V_68 ;
V_2 -> V_66 = V_69 ;
V_70 = F_23 ( V_2 , V_69 -> V_74 . V_32 , 0 ) ;
if ( V_70 && V_2 -> V_13 == NULL )
F_46 ( V_69 ) ;
return V_70 ;
}
struct V_65 * F_48 ( struct V_75 * V_76 )
{
struct V_65 * V_66 ;
V_66 = F_14 ( sizeof( struct V_65 ) , V_34 ) ;
if ( ! V_66 )
return NULL ;
F_1 ( & V_66 -> V_67 , L_8 ) ;
F_1 ( & V_66 -> V_68 , L_9 ) ;
V_66 -> V_77 = 1 << V_78 ;
V_66 -> V_76 = V_76 ;
return V_66 ;
}
static void F_49 ( struct V_65 * V_66 )
{
F_27 ( & V_66 -> V_67 ) ;
F_27 ( & V_66 -> V_68 ) ;
}
void F_50 ( struct V_65 * V_66 )
{
struct V_79 * V_80 ;
struct V_81 * V_82 ;
V_82 = F_51 ( V_66 -> V_76 ) ;
F_52 ( V_66 , V_82 ) ;
if ( V_82 )
F_53 ( V_82 ) ;
F_54 () ;
V_80 = F_55 ( V_66 -> V_76 -> V_83 -> V_84 ) ;
F_56 () ;
F_12 ( L_10 ,
V_20 , V_80 ) ;
F_57 ( V_80 , V_85 ) ;
F_49 ( V_66 ) ;
F_6 ( V_66 ) ;
}
static int F_58 ( struct V_75 * V_76 )
{
int V_26 ;
if ( V_76 -> V_86 == V_87 ) {
V_26 = F_59 ( V_76 ) ;
if ( V_26 )
return V_26 ;
}
if ( V_76 -> V_86 < V_88 )
return - V_89 ;
F_60 () ;
return 0 ;
}
int F_61 ( struct V_75 * V_76 )
{
if ( ! F_62 ( V_76 ) )
return 0 ;
F_63 ( V_78 , & V_76 -> V_90 -> V_77 ) ;
return F_58 ( V_76 ) ;
}
int F_64 ( struct V_75 * V_76 , unsigned long V_91 )
{
struct V_65 * V_66 = V_76 -> V_90 ;
int V_26 ;
F_24 ( & V_76 -> V_92 ) ;
if ( F_65 ( V_78 , & V_66 -> V_77 ) ) {
V_76 -> V_93 = V_91 ;
V_76 -> V_94 = V_53 ;
}
F_25 ( & V_76 -> V_92 ) ;
V_26 = F_58 ( V_76 ) ;
if ( V_26 )
return V_26 ;
if ( ! F_66 ( V_76 ) )
return - V_95 ;
return 0 ;
}
