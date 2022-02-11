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
static void F_17 ( struct V_1 * V_2 ,
struct V_10 * V_15 )
{
T_1 V_16 = V_15 -> V_17 ;
F_18 ( V_16 , V_2 -> V_18 ) ;
if ( V_16 > V_2 -> V_4 ||
V_2 -> V_4 == V_5 )
V_2 -> V_4 = V_16 ;
V_15 -> V_26 = V_2 -> V_26 ;
}
bool F_19 ( struct V_1 * V_2 , struct V_10 * V_15 )
{
if ( F_20 ( V_2 , V_15 -> V_17 ) )
return false ;
F_17 ( V_2 , V_15 ) ;
return true ;
}
struct V_10 * F_21 ( struct V_1 * V_2 , T_1 V_16 )
{
if ( V_16 <= V_2 -> V_27 )
return F_15 ( V_2 , V_16 , 1 , V_28 ) ;
return F_16 ( - V_29 ) ;
}
struct V_10 * F_22 ( struct V_1 * V_2 )
{
struct V_10 * V_30 = F_16 ( - V_31 ) ;
T_1 V_16 ;
F_12 ( L_2 ,
V_20 , V_2 -> V_18 [ 0 ] , V_2 -> V_4 ,
V_2 -> V_27 + 1 ) ;
V_16 = F_23 ( V_2 -> V_18 , V_2 -> V_27 + 1 ) ;
if ( V_16 <= V_2 -> V_27 ) {
V_30 = F_15 ( V_2 , V_16 , 1 , V_28 ) ;
if ( ! F_24 ( V_30 ) )
F_17 ( V_2 , V_30 ) ;
}
F_12 ( L_3 ,
V_20 , V_2 -> V_18 [ 0 ] , V_2 -> V_4 ,
! F_24 ( V_30 ) ? V_30 -> V_17 : V_5 ) ;
return V_30 ;
}
static int F_25 ( struct V_1 * V_2 ,
T_1 V_32 , T_1 V_33 )
{
if ( V_32 <= V_2 -> V_12 )
return 0 ;
if ( ! F_24 ( F_15 ( V_2 , V_32 - 1 , V_33 , V_34 ) ) )
return 0 ;
return - V_25 ;
}
static void F_26 ( struct V_1 * V_2 ,
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
V_2 -> V_27 = V_35 ;
}
static int F_27 ( struct V_1 * V_2 ,
T_1 V_32 , T_1 V_33 )
{
int V_30 ;
F_12 ( L_4 , V_20 ,
V_32 , V_2 -> V_12 ) ;
if ( V_32 > V_40 )
V_32 = V_40 ;
V_30 = F_25 ( V_2 , V_32 , V_33 ) ;
if ( V_30 )
goto V_41;
F_28 ( & V_2 -> V_6 ) ;
F_26 ( V_2 , V_32 - 1 , V_33 ) ;
F_29 ( & V_2 -> V_6 ) ;
F_12 ( L_5 , V_20 ,
V_2 , V_2 -> V_13 , V_2 -> V_12 ) ;
V_41:
F_12 ( L_6 , V_20 , V_30 ) ;
return V_30 ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
F_32 ( & V_2 -> V_7 ) ;
}
int F_33 ( struct V_1 * V_2 , unsigned int V_32 ,
const char * V_3 )
{
F_1 ( V_2 , V_3 ) ;
return F_27 ( V_2 , V_32 , 0 ) ;
}
static bool F_34 ( struct V_42 * V_43 , void * V_44 )
{
struct V_45 * args = V_43 -> V_46 . V_47 ;
struct V_48 * V_49 = V_43 -> V_46 . V_50 ;
struct V_10 * V_15 = V_44 ;
struct V_1 * V_2 = V_15 -> V_23 ;
if ( F_8 ( V_2 ) && ! args -> V_51 )
return false ;
V_15 -> V_26 = V_2 -> V_26 ;
args -> V_52 = V_15 ;
V_49 -> V_53 = V_54 ;
V_49 -> V_55 = V_15 ;
V_49 -> V_56 = 0 ;
V_49 -> V_57 = 1 ;
return true ;
}
static bool F_35 ( struct V_1 * V_2 ,
struct V_10 * V_15 )
{
if ( F_36 ( & V_2 -> V_7 , F_34 , V_15 ) )
return true ;
return false ;
}
bool F_37 ( struct V_1 * V_2 ,
struct V_10 * V_15 )
{
if ( V_15 -> V_17 > V_2 -> V_27 )
return false ;
return F_35 ( V_2 , V_15 ) ;
}
static bool F_38 ( struct V_1 * V_2 )
{
struct V_10 * V_15 = F_22 ( V_2 ) ;
if ( ! F_24 ( V_15 ) ) {
bool V_30 = F_35 ( V_2 , V_15 ) ;
if ( V_30 )
return V_30 ;
F_9 ( V_2 , V_15 ) ;
}
return false ;
}
void F_39 ( struct V_1 * V_2 )
{
for (; ; ) {
if ( ! F_38 ( V_2 ) )
break;
}
}
static void F_40 ( struct V_1 * V_2 ,
T_1 V_37 )
{
T_1 V_27 ;
V_27 = F_41 ( V_40 - 1 , V_37 ) ;
if ( V_27 > V_2 -> V_35 )
V_27 = V_2 -> V_35 ;
if ( V_27 > V_2 -> V_37 )
V_27 = V_2 -> V_37 ;
V_2 -> V_27 = V_27 ;
F_39 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
T_1 V_37 )
{
if ( V_2 -> V_37 == V_37 )
return;
V_2 -> V_37 = V_37 ;
V_2 -> V_26 ++ ;
}
void F_43 ( struct V_1 * V_2 ,
T_1 V_37 )
{
F_28 ( & V_2 -> V_6 ) ;
F_42 ( V_2 , V_37 ) ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = 0 ;
F_40 ( V_2 , V_37 ) ;
F_29 ( & V_2 -> V_6 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
T_1 V_58 )
{
if ( V_2 -> V_35 == V_58 )
return;
if ( V_2 -> V_4 > V_58 )
return;
F_5 ( V_2 , V_58 + 1 ) ;
V_2 -> V_35 = V_58 ;
}
static T_3 F_45 ( T_3 V_59 , T_3 V_60 )
{
V_59 -= V_60 ;
if ( V_59 == 0 )
return 0 ;
if ( V_59 < 0 )
return ( V_59 - 1 ) >> 1 ;
return ( V_59 + 1 ) >> 1 ;
}
static int F_46 ( T_3 V_59 )
{
if ( V_59 > 0 )
return 1 ;
if ( V_59 < 0 )
return - 1 ;
return 0 ;
}
static bool F_47 ( T_3 V_59 , T_3 V_60 )
{
if ( ! V_59 || ! V_60 )
return true ;
return F_46 ( V_59 ) == F_46 ( V_60 ) ;
}
static bool F_48 ( struct V_1 * V_2 ,
T_1 V_61 )
{
T_3 V_62 , V_63 ;
bool V_30 = true ;
V_62 = F_45 ( V_61 ,
V_2 -> V_37 ) ;
V_63 = F_45 ( V_62 ,
V_2 -> V_38 ) ;
if ( F_47 ( V_62 , V_2 -> V_38 ) )
V_30 = false ;
if ( F_47 ( V_63 , V_2 -> V_39 ) )
V_30 = false ;
V_2 -> V_38 = V_62 ;
V_2 -> V_39 = V_63 ;
return V_30 ;
}
void F_49 ( struct V_1 * V_2 ,
struct V_10 * V_15 ,
struct V_48 * V_49 )
{
F_28 ( & V_2 -> V_6 ) ;
if ( ! F_48 ( V_2 , V_49 -> V_64 ) )
F_42 ( V_2 , V_49 -> V_64 ) ;
if ( V_2 -> V_26 == V_15 -> V_26 )
F_44 ( V_2 , V_49 -> V_65 ) ;
F_40 ( V_2 , V_49 -> V_64 ) ;
F_29 ( & V_2 -> V_6 ) ;
}
static void F_50 ( struct V_66 * V_67 )
{
F_30 ( & V_67 -> V_68 ) ;
F_30 ( & V_67 -> V_69 ) ;
}
int F_51 ( struct V_66 * V_70 )
{
struct V_1 * V_2 ;
int V_71 ;
F_12 ( L_7 , V_20 ) ;
V_2 = & V_70 -> V_68 ;
V_2 -> V_67 = V_70 ;
V_71 = F_27 ( V_2 , V_70 -> V_72 . V_32 , 1 ) ;
if ( V_71 || ! ( V_70 -> V_73 & V_74 ) )
return V_71 ;
V_2 = & V_70 -> V_69 ;
V_2 -> V_67 = V_70 ;
V_71 = F_27 ( V_2 , V_70 -> V_75 . V_32 , 0 ) ;
if ( V_71 && V_2 -> V_13 == NULL )
F_50 ( V_70 ) ;
return V_71 ;
}
struct V_66 * F_52 ( struct V_76 * V_77 )
{
struct V_66 * V_67 ;
V_67 = F_14 ( sizeof( struct V_66 ) , V_34 ) ;
if ( ! V_67 )
return NULL ;
F_1 ( & V_67 -> V_68 , L_8 ) ;
F_1 ( & V_67 -> V_69 , L_9 ) ;
V_67 -> V_78 = 1 << V_79 ;
V_67 -> V_77 = V_77 ;
return V_67 ;
}
static void F_53 ( struct V_66 * V_67 )
{
F_31 ( & V_67 -> V_68 ) ;
F_31 ( & V_67 -> V_69 ) ;
}
void F_54 ( struct V_66 * V_67 )
{
struct V_80 * V_81 ;
struct V_82 * V_83 ;
V_83 = F_55 ( V_67 -> V_77 ) ;
F_56 ( V_67 , V_83 ) ;
if ( V_83 )
F_57 ( V_83 ) ;
F_58 () ;
V_81 = F_59 ( V_67 -> V_77 -> V_84 -> V_85 ) ;
F_60 () ;
F_12 ( L_10 ,
V_20 , V_81 ) ;
F_61 ( V_81 , V_86 ) ;
F_53 ( V_67 ) ;
F_6 ( V_67 ) ;
}
static int F_62 ( struct V_76 * V_77 )
{
int V_30 ;
if ( V_77 -> V_87 == V_88 ) {
V_30 = F_63 ( V_77 ) ;
if ( V_30 )
return V_30 ;
}
if ( V_77 -> V_87 < V_89 )
return - V_90 ;
F_64 () ;
return 0 ;
}
int F_65 ( struct V_76 * V_77 )
{
if ( ! F_66 ( V_77 ) )
return 0 ;
F_67 ( V_79 , & V_77 -> V_91 -> V_78 ) ;
return F_62 ( V_77 ) ;
}
int F_68 ( struct V_76 * V_77 , unsigned long V_92 )
{
struct V_66 * V_67 = V_77 -> V_91 ;
int V_30 ;
F_28 ( & V_77 -> V_93 ) ;
if ( F_69 ( V_79 , & V_67 -> V_78 ) ) {
V_77 -> V_94 = V_92 ;
V_77 -> V_95 = V_54 ;
}
F_29 ( & V_77 -> V_93 ) ;
V_30 = F_62 ( V_77 ) ;
if ( V_30 )
return V_30 ;
if ( ! F_70 ( V_77 ) )
return - V_96 ;
return 0 ;
}
