static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
struct V_4 * V_5 ,
unsigned * V_6 )
{
unsigned int V_7 , V_8 ;
int V_9 ;
T_1 V_10 ;
unsigned V_11 ;
* V_6 = 1 ;
V_8 = F_2 ( V_3 -> V_12 . V_13 >> 9 , 1U ) ;
V_7 = F_3 ( V_3 -> V_12 . V_7 , V_14 >> 9 ) ;
V_7 -= V_7 % V_8 ;
if ( F_4 ( ! V_7 ) ) {
return NULL ;
}
if ( F_5 ( V_1 ) <= V_7 )
return NULL ;
V_11 = V_7 ;
V_9 = ( V_3 -> V_12 . V_15 >> 9 ) % V_8 ;
V_10 = V_1 -> V_16 . V_17 + V_11 - V_9 ;
V_10 = F_6 ( V_10 , V_8 ) ;
if ( V_11 > V_10 )
V_11 -= V_10 ;
return F_7 ( V_1 , V_11 , V_18 , V_5 ) ;
}
static struct V_1 * F_8 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
struct V_4 * V_5 ,
unsigned * V_6 )
{
* V_6 = 1 ;
if ( ! V_3 -> V_12 . V_19 )
return NULL ;
if ( F_5 ( V_1 ) <= V_3 -> V_12 . V_19 )
return NULL ;
return F_7 ( V_1 , V_3 -> V_12 . V_19 , V_18 , V_5 ) ;
}
static struct V_1 * F_9 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
struct V_4 * V_5 ,
unsigned * V_20 )
{
struct V_21 V_22 , V_23 , * V_24 = NULL ;
struct V_25 V_26 ;
unsigned V_27 = 0 , V_6 = 0 , V_28 = 0 ;
unsigned V_29 = V_1 -> V_30 ;
bool V_31 = true ;
struct V_1 * V_32 = NULL ;
F_10 (bv, bio, iter) {
if ( V_28 + ( V_22 . V_33 >> 9 ) > F_11 ( V_3 ) )
goto V_34;
if ( V_24 && F_12 ( V_3 , V_24 , V_22 . V_35 ) )
goto V_34;
if ( V_24 && F_13 ( V_3 ) ) {
if ( V_27 + V_22 . V_33 > F_14 ( V_3 ) )
goto V_36;
if ( ! F_15 ( V_24 , & V_22 ) )
goto V_36;
if ( ! F_16 ( V_3 , V_24 , & V_22 ) )
goto V_36;
V_27 += V_22 . V_33 ;
V_23 = V_22 ;
V_24 = & V_23 ;
V_28 += V_22 . V_33 >> 9 ;
if ( V_6 == 1 && V_27 > V_29 )
V_29 = V_27 ;
continue;
}
V_36:
if ( V_6 == F_17 ( V_3 ) )
goto V_34;
V_6 ++ ;
V_23 = V_22 ;
V_24 = & V_23 ;
V_27 = V_22 . V_33 ;
V_28 += V_22 . V_33 >> 9 ;
if ( V_6 == 1 && V_27 > V_29 )
V_29 = V_27 ;
}
V_31 = false ;
V_34:
* V_20 = V_6 ;
if ( V_31 ) {
V_32 = F_7 ( V_1 , V_28 , V_18 , V_5 ) ;
if ( V_32 )
V_1 = V_32 ;
}
V_1 -> V_30 = V_29 ;
if ( V_27 > V_1 -> V_37 )
V_1 -> V_37 = V_27 ;
return V_31 ? V_32 : NULL ;
}
void F_18 ( struct V_2 * V_3 , struct V_1 * * V_1 ,
struct V_4 * V_5 )
{
struct V_1 * V_34 , * V_38 ;
unsigned V_6 ;
if ( ( * V_1 ) -> V_39 & V_40 )
V_34 = F_1 ( V_3 , * V_1 , V_5 , & V_6 ) ;
else if ( ( * V_1 ) -> V_39 & V_41 )
V_34 = F_8 ( V_3 , * V_1 , V_5 , & V_6 ) ;
else
V_34 = F_9 ( V_3 , * V_1 , V_3 -> F_7 , & V_6 ) ;
V_38 = V_34 ? V_34 : * V_1 ;
V_38 -> V_42 = V_6 ;
F_19 ( V_38 , V_43 ) ;
if ( V_34 ) {
V_34 -> V_39 |= V_44 ;
F_20 ( V_34 , * V_1 ) ;
F_21 ( * V_1 ) ;
* V_1 = V_34 ;
}
}
static unsigned int F_22 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
bool V_45 )
{
struct V_21 V_22 , V_23 = { NULL } ;
int V_46 , V_47 = 0 ;
unsigned int V_27 , V_48 ;
struct V_1 * V_49 , * V_50 ;
struct V_25 V_26 ;
if ( ! V_1 )
return 0 ;
if ( V_1 -> V_39 & V_40 )
return 1 ;
if ( V_1 -> V_39 & V_41 )
return 1 ;
V_49 = V_1 ;
V_46 = F_13 ( V_3 ) ;
V_27 = 0 ;
V_48 = 0 ;
F_23 (bio) {
F_10 (bv, bio, iter) {
if ( V_45 )
goto V_36;
if ( V_47 && V_46 ) {
if ( V_27 + V_22 . V_33
> F_14 ( V_3 ) )
goto V_36;
if ( ! F_15 ( & V_23 , & V_22 ) )
goto V_36;
if ( ! F_16 ( V_3 , & V_23 , & V_22 ) )
goto V_36;
V_27 += V_22 . V_33 ;
V_23 = V_22 ;
continue;
}
V_36:
if ( V_48 == 1 && V_27 >
V_49 -> V_30 )
V_49 -> V_30 = V_27 ;
V_48 ++ ;
V_23 = V_22 ;
V_47 = 1 ;
V_27 = V_22 . V_33 ;
}
V_50 = V_1 ;
}
if ( V_48 == 1 && V_27 > V_49 -> V_30 )
V_49 -> V_30 = V_27 ;
if ( V_27 > V_50 -> V_37 )
V_50 -> V_37 = V_27 ;
return V_48 ;
}
void F_24 ( struct V_51 * V_52 )
{
bool V_45 = ! ! F_25 ( V_53 ,
& V_52 -> V_3 -> V_54 ) ;
V_52 -> V_55 = F_22 ( V_52 -> V_3 , V_52 -> V_1 ,
V_45 ) ;
}
void F_26 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
unsigned short V_56 ;
if ( F_27 ( V_1 , V_57 ) )
V_56 = F_28 ( V_1 ) ;
else
V_56 = V_1 -> V_58 ;
if ( F_25 ( V_53 , & V_3 -> V_54 ) &&
( V_56 < F_17 ( V_3 ) ) )
V_1 -> V_42 = V_56 ;
else {
struct V_1 * V_59 = V_1 -> V_60 ;
V_1 -> V_60 = NULL ;
V_1 -> V_42 = F_22 ( V_3 , V_1 , false ) ;
V_1 -> V_60 = V_59 ;
}
F_19 ( V_1 , V_43 ) ;
}
static int F_29 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_1 * V_59 )
{
struct V_21 V_61 = { NULL } , V_62 ;
struct V_25 V_26 ;
if ( ! F_13 ( V_3 ) )
return 0 ;
if ( V_1 -> V_37 + V_59 -> V_30 >
F_14 ( V_3 ) )
return 0 ;
if ( ! F_30 ( V_1 ) )
return 1 ;
F_10 (end_bv, bio, iter)
if ( V_61 . V_33 == V_26 . V_63 )
break;
V_62 = F_31 ( V_59 ) ;
if ( ! F_15 ( & V_61 , & V_62 ) )
return 0 ;
if ( F_16 ( V_3 , & V_61 , & V_62 ) )
return 1 ;
return 0 ;
}
static inline void
F_32 ( struct V_2 * V_3 , struct V_21 * V_64 ,
struct V_65 * V_66 , struct V_21 * V_23 ,
struct V_65 * * V_67 , int * V_6 , int * V_46 )
{
int V_68 = V_64 -> V_33 ;
if ( * V_67 && * V_46 ) {
if ( ( * V_67 ) -> V_69 + V_68 > F_14 ( V_3 ) )
goto V_36;
if ( ! F_15 ( V_23 , V_64 ) )
goto V_36;
if ( ! F_16 ( V_3 , V_23 , V_64 ) )
goto V_36;
( * V_67 ) -> V_69 += V_68 ;
} else {
V_36:
if ( ! * V_67 )
* V_67 = V_66 ;
else {
F_33 ( * V_67 ) ;
* V_67 = F_34 ( * V_67 ) ;
}
F_35 ( * V_67 , V_64 -> V_70 , V_68 , V_64 -> V_35 ) ;
( * V_6 ) ++ ;
}
* V_23 = * V_64 ;
}
static int F_36 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_65 * V_66 ,
struct V_65 * * V_67 )
{
struct V_21 V_64 , V_23 = { NULL } ;
struct V_25 V_26 ;
int V_6 , V_46 ;
V_6 = 0 ;
V_46 = F_13 ( V_3 ) ;
if ( V_1 -> V_39 & V_40 ) {
if ( V_1 -> V_58 )
goto V_71;
return 0 ;
}
if ( V_1 -> V_39 & V_41 ) {
V_71:
* V_67 = V_66 ;
V_64 = F_31 ( V_1 ) ;
F_35 ( * V_67 , V_64 . V_70 , V_64 . V_33 , V_64 . V_35 ) ;
return 1 ;
}
F_23 (bio)
F_10 (bvec, bio, iter)
F_32 ( V_3 , & V_64 , V_66 , & V_23 , V_67 ,
& V_6 , & V_46 ) ;
return V_6 ;
}
int F_37 ( struct V_2 * V_3 , struct V_51 * V_52 ,
struct V_65 * V_66 )
{
struct V_65 * V_67 = NULL ;
int V_6 = 0 ;
if ( V_52 -> V_1 )
V_6 = F_36 ( V_3 , V_52 -> V_1 , V_66 , & V_67 ) ;
if ( F_4 ( V_52 -> V_72 & V_73 ) &&
( F_38 ( V_52 ) & V_3 -> V_74 ) ) {
unsigned int V_75 =
( V_3 -> V_74 & ~ F_38 ( V_52 ) ) + 1 ;
V_67 -> V_69 += V_75 ;
V_52 -> V_76 += V_75 ;
}
if ( V_3 -> V_77 && V_3 -> V_78 ( V_52 ) ) {
if ( V_52 -> V_72 & V_79 )
memset ( V_3 -> V_80 , 0 , V_3 -> V_77 ) ;
F_33 ( V_67 ) ;
V_67 = F_34 ( V_67 ) ;
F_35 ( V_67 , F_39 ( V_3 -> V_80 ) ,
V_3 -> V_77 ,
( ( unsigned long ) V_3 -> V_80 ) &
( V_81 - 1 ) ) ;
V_6 ++ ;
V_52 -> V_76 += V_3 -> V_77 ;
}
if ( V_67 )
F_40 ( V_67 ) ;
F_41 ( V_6 > V_52 -> V_55 ) ;
return V_6 ;
}
static inline int F_42 ( struct V_2 * V_3 ,
struct V_51 * V_82 ,
struct V_1 * V_1 )
{
int V_48 = F_43 ( V_3 , V_1 ) ;
if ( V_82 -> V_55 + V_48 > F_17 ( V_3 ) )
goto V_83;
if ( F_44 ( V_3 , V_82 , V_1 ) == false )
goto V_83;
V_82 -> V_55 += V_48 ;
return 1 ;
V_83:
V_82 -> V_72 |= V_44 ;
if ( V_82 == V_3 -> V_84 )
V_3 -> V_84 = NULL ;
return 0 ;
}
int F_45 ( struct V_2 * V_3 , struct V_51 * V_82 ,
struct V_1 * V_1 )
{
if ( F_46 ( V_82 , V_1 ) )
return 0 ;
if ( F_47 ( V_82 ) &&
F_48 ( V_82 , V_1 ) )
return 0 ;
if ( F_49 ( V_82 ) + F_5 ( V_1 ) >
F_50 ( V_82 ) ) {
V_82 -> V_72 |= V_44 ;
if ( V_82 == V_3 -> V_84 )
V_3 -> V_84 = NULL ;
return 0 ;
}
if ( ! F_27 ( V_82 -> V_85 , V_43 ) )
F_26 ( V_3 , V_82 -> V_85 ) ;
if ( ! F_27 ( V_1 , V_43 ) )
F_26 ( V_3 , V_1 ) ;
return F_42 ( V_3 , V_82 , V_1 ) ;
}
int F_51 ( struct V_2 * V_3 , struct V_51 * V_82 ,
struct V_1 * V_1 )
{
if ( F_52 ( V_82 , V_1 ) )
return 0 ;
if ( F_47 ( V_82 ) &&
F_53 ( V_82 , V_1 ) )
return 0 ;
if ( F_49 ( V_82 ) + F_5 ( V_1 ) >
F_50 ( V_82 ) ) {
V_82 -> V_72 |= V_44 ;
if ( V_82 == V_3 -> V_84 )
V_3 -> V_84 = NULL ;
return 0 ;
}
if ( ! F_27 ( V_1 , V_43 ) )
F_26 ( V_3 , V_1 ) ;
if ( ! F_27 ( V_82 -> V_1 , V_43 ) )
F_26 ( V_3 , V_82 -> V_1 ) ;
return F_42 ( V_3 , V_82 , V_1 ) ;
}
static bool F_54 ( struct V_51 * V_82 )
{
struct V_2 * V_3 = V_82 -> V_3 ;
return ! V_3 -> V_86 && V_82 -> V_87 ;
}
static int F_55 ( struct V_2 * V_3 , struct V_51 * V_82 ,
struct V_51 * V_88 )
{
int V_89 ;
unsigned int V_27 =
V_82 -> V_85 -> V_37 + V_88 -> V_1 -> V_30 ;
if ( F_54 ( V_82 ) || F_54 ( V_88 ) )
return 0 ;
if ( F_46 ( V_82 , V_88 -> V_1 ) )
return 0 ;
if ( ( F_49 ( V_82 ) + F_49 ( V_88 ) ) >
F_50 ( V_82 ) )
return 0 ;
V_89 = V_82 -> V_55 + V_88 -> V_55 ;
if ( F_29 ( V_3 , V_82 -> V_85 , V_88 -> V_1 ) ) {
if ( V_82 -> V_55 == 1 )
V_82 -> V_1 -> V_30 = V_27 ;
if ( V_88 -> V_55 == 1 )
V_88 -> V_85 -> V_37 = V_27 ;
V_89 -- ;
}
if ( V_89 > F_17 ( V_3 ) )
return 0 ;
if ( F_56 ( V_3 , V_82 , V_88 ) == false )
return 0 ;
V_82 -> V_55 = V_89 ;
return 1 ;
}
void F_57 ( struct V_51 * V_52 )
{
unsigned int V_90 = V_52 -> V_72 & V_91 ;
struct V_1 * V_1 ;
if ( V_52 -> V_72 & V_92 )
return;
for ( V_1 = V_52 -> V_1 ; V_1 ; V_1 = V_1 -> V_60 ) {
F_58 ( ( V_1 -> V_39 & V_91 ) &&
( V_1 -> V_39 & V_91 ) != V_90 ) ;
V_1 -> V_39 |= V_90 ;
}
V_52 -> V_72 |= V_92 ;
}
static void F_59 ( struct V_51 * V_82 )
{
if ( F_60 ( V_82 ) ) {
struct V_93 * V_94 ;
int V_95 ;
V_95 = F_61 () ;
V_94 = V_82 -> V_94 ;
F_62 ( V_95 , V_94 ) ;
F_63 ( V_94 , F_64 ( V_82 ) ) ;
F_65 ( V_94 ) ;
F_66 () ;
}
}
static int F_67 ( struct V_2 * V_3 , struct V_51 * V_82 ,
struct V_51 * V_88 )
{
if ( ! F_68 ( V_82 ) || ! F_68 ( V_88 ) )
return 0 ;
if ( ! F_69 ( V_82 -> V_72 , V_88 -> V_72 ) )
return 0 ;
if ( F_70 ( V_82 ) + F_49 ( V_82 ) != F_70 ( V_88 ) )
return 0 ;
if ( F_64 ( V_82 ) != F_64 ( V_88 )
|| V_82 -> V_96 != V_88 -> V_96
|| F_54 ( V_88 ) )
return 0 ;
if ( V_82 -> V_72 & V_41 &&
! F_71 ( V_82 -> V_1 , V_88 -> V_1 ) )
return 0 ;
if ( ! F_55 ( V_3 , V_82 , V_88 ) )
return 0 ;
if ( ( V_82 -> V_72 | V_88 -> V_72 ) & V_92 ||
( V_82 -> V_72 & V_91 ) !=
( V_88 -> V_72 & V_91 ) ) {
F_57 ( V_82 ) ;
F_57 ( V_88 ) ;
}
if ( F_72 ( V_82 -> V_97 , V_88 -> V_97 ) )
V_82 -> V_97 = V_88 -> V_97 ;
V_82 -> V_85 -> V_60 = V_88 -> V_1 ;
V_82 -> V_85 = V_88 -> V_85 ;
V_82 -> V_98 += F_38 ( V_88 ) ;
F_73 ( V_3 , V_82 , V_88 ) ;
F_59 ( V_88 ) ;
V_82 -> V_99 = F_74 ( V_82 -> V_99 , V_88 -> V_99 ) ;
if ( F_75 ( V_88 ) )
V_82 -> V_95 = V_88 -> V_95 ;
V_88 -> V_1 = NULL ;
F_76 ( V_3 , V_88 ) ;
return 1 ;
}
int F_77 ( struct V_2 * V_3 , struct V_51 * V_52 )
{
struct V_51 * V_88 = F_78 ( V_3 , V_52 ) ;
if ( V_88 )
return F_67 ( V_3 , V_52 , V_88 ) ;
return 0 ;
}
int F_79 ( struct V_2 * V_3 , struct V_51 * V_52 )
{
struct V_51 * V_47 = F_80 ( V_3 , V_52 ) ;
if ( V_47 )
return F_67 ( V_3 , V_47 , V_52 ) ;
return 0 ;
}
int F_81 ( struct V_2 * V_3 , struct V_51 * V_52 ,
struct V_51 * V_88 )
{
return F_67 ( V_3 , V_52 , V_88 ) ;
}
bool F_82 ( struct V_51 * V_52 , struct V_1 * V_1 )
{
if ( ! F_68 ( V_52 ) || ! F_83 ( V_1 ) )
return false ;
if ( ! F_69 ( V_52 -> V_72 , V_1 -> V_39 ) )
return false ;
if ( F_84 ( V_1 ) != F_64 ( V_52 ) )
return false ;
if ( V_52 -> V_96 != V_1 -> V_100 -> V_101 || F_54 ( V_52 ) )
return false ;
if ( F_44 ( V_52 -> V_3 , V_52 , V_1 ) == false )
return false ;
if ( V_52 -> V_72 & V_41 &&
! F_71 ( V_52 -> V_1 , V_1 ) )
return false ;
return true ;
}
int F_85 ( struct V_51 * V_52 , struct V_1 * V_1 )
{
if ( F_70 ( V_52 ) + F_49 ( V_52 ) == V_1 -> V_16 . V_17 )
return V_102 ;
else if ( F_70 ( V_52 ) - F_5 ( V_1 ) == V_1 -> V_16 . V_17 )
return V_103 ;
return V_104 ;
}
