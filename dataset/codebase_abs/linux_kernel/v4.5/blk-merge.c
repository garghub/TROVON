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
static inline unsigned F_9 ( struct V_2 * V_3 ,
struct V_1 * V_1 )
{
unsigned V_20 = F_10 ( V_3 , V_1 -> V_16 . V_17 ) ;
unsigned V_21 = F_11 ( V_3 ) - 1 ;
V_20 &= ~ ( V_21 >> 9 ) ;
return V_20 ;
}
static struct V_1 * F_12 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
struct V_4 * V_5 ,
unsigned * V_22 )
{
struct V_23 V_24 , V_25 , * V_26 = NULL ;
struct V_27 V_28 ;
unsigned V_29 = 0 , V_6 = 0 , V_20 = 0 ;
unsigned V_30 = V_1 -> V_31 ;
bool V_32 = true ;
struct V_1 * V_33 = NULL ;
const unsigned V_34 = F_9 ( V_3 , V_1 ) ;
F_13 (bv, bio, iter) {
if ( V_26 && F_14 ( V_3 , V_26 , V_24 . V_35 ) )
goto V_36;
if ( V_20 + ( V_24 . V_37 >> 9 ) > V_34 ) {
if ( V_6 < F_15 ( V_3 ) &&
V_20 < V_34 ) {
V_6 ++ ;
V_20 = V_34 ;
}
if ( V_20 )
goto V_36;
}
if ( V_26 && F_16 ( V_3 ) ) {
if ( V_29 + V_24 . V_37 > F_17 ( V_3 ) )
goto V_38;
if ( ! F_18 ( V_26 , & V_24 ) )
goto V_38;
if ( ! F_19 ( V_3 , V_26 , & V_24 ) )
goto V_38;
V_29 += V_24 . V_37 ;
V_25 = V_24 ;
V_26 = & V_25 ;
V_20 += V_24 . V_37 >> 9 ;
if ( V_6 == 1 && V_29 > V_30 )
V_30 = V_29 ;
continue;
}
V_38:
if ( V_6 == F_15 ( V_3 ) )
goto V_36;
V_6 ++ ;
V_25 = V_24 ;
V_26 = & V_25 ;
V_29 = V_24 . V_37 ;
V_20 += V_24 . V_37 >> 9 ;
if ( V_6 == 1 && V_29 > V_30 )
V_30 = V_29 ;
}
V_32 = false ;
V_36:
* V_22 = V_6 ;
if ( V_32 ) {
V_33 = F_7 ( V_1 , V_20 , V_18 , V_5 ) ;
if ( V_33 )
V_1 = V_33 ;
}
V_1 -> V_31 = V_30 ;
if ( V_29 > V_1 -> V_39 )
V_1 -> V_39 = V_29 ;
return V_32 ? V_33 : NULL ;
}
void F_20 ( struct V_2 * V_3 , struct V_1 * * V_1 ,
struct V_4 * V_5 )
{
struct V_1 * V_36 , * V_40 ;
unsigned V_6 ;
if ( ( * V_1 ) -> V_41 & V_42 )
V_36 = F_1 ( V_3 , * V_1 , V_5 , & V_6 ) ;
else if ( ( * V_1 ) -> V_41 & V_43 )
V_36 = F_8 ( V_3 , * V_1 , V_5 , & V_6 ) ;
else
V_36 = F_12 ( V_3 , * V_1 , V_3 -> F_7 , & V_6 ) ;
V_40 = V_36 ? V_36 : * V_1 ;
V_40 -> V_44 = V_6 ;
F_21 ( V_40 , V_45 ) ;
if ( V_36 ) {
V_36 -> V_41 |= V_46 ;
F_22 ( V_36 , * V_1 ) ;
F_23 ( V_3 , V_36 , ( * V_1 ) -> V_16 . V_17 ) ;
F_24 ( * V_1 ) ;
* V_1 = V_36 ;
}
}
static unsigned int F_25 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
bool V_47 )
{
struct V_23 V_24 , V_25 = { NULL } ;
int V_48 , V_49 = 0 ;
unsigned int V_29 , V_50 ;
struct V_1 * V_51 , * V_52 ;
struct V_27 V_28 ;
if ( ! V_1 )
return 0 ;
if ( V_1 -> V_41 & V_42 )
return 1 ;
if ( V_1 -> V_41 & V_43 )
return 1 ;
V_51 = V_1 ;
V_48 = F_16 ( V_3 ) ;
V_29 = 0 ;
V_50 = 0 ;
F_26 (bio) {
F_13 (bv, bio, iter) {
if ( V_47 )
goto V_38;
if ( V_49 && V_48 ) {
if ( V_29 + V_24 . V_37
> F_17 ( V_3 ) )
goto V_38;
if ( ! F_18 ( & V_25 , & V_24 ) )
goto V_38;
if ( ! F_19 ( V_3 , & V_25 , & V_24 ) )
goto V_38;
V_29 += V_24 . V_37 ;
V_25 = V_24 ;
continue;
}
V_38:
if ( V_50 == 1 && V_29 >
V_51 -> V_31 )
V_51 -> V_31 = V_29 ;
V_50 ++ ;
V_25 = V_24 ;
V_49 = 1 ;
V_29 = V_24 . V_37 ;
}
V_52 = V_1 ;
}
if ( V_50 == 1 && V_29 > V_51 -> V_31 )
V_51 -> V_31 = V_29 ;
if ( V_29 > V_52 -> V_39 )
V_52 -> V_39 = V_29 ;
return V_50 ;
}
void F_27 ( struct V_53 * V_54 )
{
bool V_47 = ! ! F_28 ( V_55 ,
& V_54 -> V_3 -> V_56 ) ;
V_54 -> V_57 = F_25 ( V_54 -> V_3 , V_54 -> V_1 ,
V_47 ) ;
}
void F_29 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
unsigned short V_58 ;
if ( F_30 ( V_1 , V_59 ) )
V_58 = F_31 ( V_1 ) ;
else
V_58 = V_1 -> V_60 ;
if ( F_28 ( V_55 , & V_3 -> V_56 ) &&
( V_58 < F_15 ( V_3 ) ) )
V_1 -> V_44 = V_58 ;
else {
struct V_1 * V_61 = V_1 -> V_62 ;
V_1 -> V_62 = NULL ;
V_1 -> V_44 = F_25 ( V_3 , V_1 , false ) ;
V_1 -> V_62 = V_61 ;
}
F_21 ( V_1 , V_45 ) ;
}
static int F_32 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_1 * V_61 )
{
struct V_23 V_63 = { NULL } , V_64 ;
if ( ! F_16 ( V_3 ) )
return 0 ;
if ( V_1 -> V_39 + V_61 -> V_31 >
F_17 ( V_3 ) )
return 0 ;
if ( ! F_33 ( V_1 ) )
return 1 ;
F_34 ( V_1 , & V_63 ) ;
F_35 ( V_61 , & V_64 ) ;
if ( ! F_18 ( & V_63 , & V_64 ) )
return 0 ;
if ( F_19 ( V_3 , & V_63 , & V_64 ) )
return 1 ;
return 0 ;
}
static inline void
F_36 ( struct V_2 * V_3 , struct V_23 * V_65 ,
struct V_66 * V_67 , struct V_23 * V_25 ,
struct V_66 * * V_68 , int * V_6 , int * V_48 )
{
int V_69 = V_65 -> V_37 ;
if ( * V_68 && * V_48 ) {
if ( ( * V_68 ) -> V_70 + V_69 > F_17 ( V_3 ) )
goto V_38;
if ( ! F_18 ( V_25 , V_65 ) )
goto V_38;
if ( ! F_19 ( V_3 , V_25 , V_65 ) )
goto V_38;
( * V_68 ) -> V_70 += V_69 ;
} else {
V_38:
if ( ! * V_68 )
* V_68 = V_67 ;
else {
F_37 ( * V_68 ) ;
* V_68 = F_38 ( * V_68 ) ;
}
F_39 ( * V_68 , V_65 -> V_71 , V_69 , V_65 -> V_35 ) ;
( * V_6 ) ++ ;
}
* V_25 = * V_65 ;
}
static int F_40 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_66 * V_67 ,
struct V_66 * * V_68 )
{
struct V_23 V_65 , V_25 = { NULL } ;
struct V_27 V_28 ;
int V_6 , V_48 ;
V_6 = 0 ;
V_48 = F_16 ( V_3 ) ;
if ( V_1 -> V_41 & V_42 ) {
if ( V_1 -> V_60 )
goto V_72;
return 0 ;
}
if ( V_1 -> V_41 & V_43 ) {
V_72:
* V_68 = V_67 ;
V_65 = F_41 ( V_1 ) ;
F_39 ( * V_68 , V_65 . V_71 , V_65 . V_37 , V_65 . V_35 ) ;
return 1 ;
}
F_26 (bio)
F_13 (bvec, bio, iter)
F_36 ( V_3 , & V_65 , V_67 , & V_25 , V_68 ,
& V_6 , & V_48 ) ;
return V_6 ;
}
int F_42 ( struct V_2 * V_3 , struct V_53 * V_54 ,
struct V_66 * V_67 )
{
struct V_66 * V_68 = NULL ;
int V_6 = 0 ;
if ( V_54 -> V_1 )
V_6 = F_40 ( V_3 , V_54 -> V_1 , V_67 , & V_68 ) ;
if ( F_4 ( V_54 -> V_73 & V_74 ) &&
( F_43 ( V_54 ) & V_3 -> V_75 ) ) {
unsigned int V_76 =
( V_3 -> V_75 & ~ F_43 ( V_54 ) ) + 1 ;
V_68 -> V_70 += V_76 ;
V_54 -> V_77 += V_76 ;
}
if ( V_3 -> V_78 && V_3 -> V_79 ( V_54 ) ) {
if ( V_54 -> V_73 & V_80 )
memset ( V_3 -> V_81 , 0 , V_3 -> V_78 ) ;
F_37 ( V_68 ) ;
V_68 = F_38 ( V_68 ) ;
F_39 ( V_68 , F_44 ( V_3 -> V_81 ) ,
V_3 -> V_78 ,
( ( unsigned long ) V_3 -> V_81 ) &
( V_82 - 1 ) ) ;
V_6 ++ ;
V_54 -> V_77 += V_3 -> V_78 ;
}
if ( V_68 )
F_45 ( V_68 ) ;
F_46 ( V_6 > V_54 -> V_57 ) ;
return V_6 ;
}
static inline int F_47 ( struct V_2 * V_3 ,
struct V_53 * V_83 ,
struct V_1 * V_1 )
{
int V_50 = F_48 ( V_3 , V_1 ) ;
if ( V_83 -> V_57 + V_50 > F_15 ( V_3 ) )
goto V_84;
if ( F_49 ( V_3 , V_83 , V_1 ) == false )
goto V_84;
V_83 -> V_57 += V_50 ;
return 1 ;
V_84:
V_83 -> V_73 |= V_46 ;
if ( V_83 == V_3 -> V_85 )
V_3 -> V_85 = NULL ;
return 0 ;
}
int F_50 ( struct V_2 * V_3 , struct V_53 * V_83 ,
struct V_1 * V_1 )
{
if ( F_51 ( V_83 , V_1 ) )
return 0 ;
if ( F_52 ( V_83 ) &&
F_53 ( V_83 , V_1 ) )
return 0 ;
if ( F_54 ( V_83 ) + F_5 ( V_1 ) >
F_55 ( V_83 ) ) {
V_83 -> V_73 |= V_46 ;
if ( V_83 == V_3 -> V_85 )
V_3 -> V_85 = NULL ;
return 0 ;
}
if ( ! F_30 ( V_83 -> V_86 , V_45 ) )
F_29 ( V_3 , V_83 -> V_86 ) ;
if ( ! F_30 ( V_1 , V_45 ) )
F_29 ( V_3 , V_1 ) ;
return F_47 ( V_3 , V_83 , V_1 ) ;
}
int F_56 ( struct V_2 * V_3 , struct V_53 * V_83 ,
struct V_1 * V_1 )
{
if ( F_57 ( V_83 , V_1 ) )
return 0 ;
if ( F_52 ( V_83 ) &&
F_58 ( V_83 , V_1 ) )
return 0 ;
if ( F_54 ( V_83 ) + F_5 ( V_1 ) >
F_55 ( V_83 ) ) {
V_83 -> V_73 |= V_46 ;
if ( V_83 == V_3 -> V_85 )
V_3 -> V_85 = NULL ;
return 0 ;
}
if ( ! F_30 ( V_1 , V_45 ) )
F_29 ( V_3 , V_1 ) ;
if ( ! F_30 ( V_83 -> V_1 , V_45 ) )
F_29 ( V_3 , V_83 -> V_1 ) ;
return F_47 ( V_3 , V_83 , V_1 ) ;
}
static bool F_59 ( struct V_53 * V_83 )
{
struct V_2 * V_3 = V_83 -> V_3 ;
return ! V_3 -> V_87 && V_83 -> V_88 ;
}
static int F_60 ( struct V_2 * V_3 , struct V_53 * V_83 ,
struct V_53 * V_89 )
{
int V_90 ;
unsigned int V_29 =
V_83 -> V_86 -> V_39 + V_89 -> V_1 -> V_31 ;
if ( F_59 ( V_83 ) || F_59 ( V_89 ) )
return 0 ;
if ( F_51 ( V_83 , V_89 -> V_1 ) )
return 0 ;
if ( ( F_54 ( V_83 ) + F_54 ( V_89 ) ) >
F_55 ( V_83 ) )
return 0 ;
V_90 = V_83 -> V_57 + V_89 -> V_57 ;
if ( F_32 ( V_3 , V_83 -> V_86 , V_89 -> V_1 ) ) {
if ( V_83 -> V_57 == 1 )
V_83 -> V_1 -> V_31 = V_29 ;
if ( V_89 -> V_57 == 1 )
V_89 -> V_86 -> V_39 = V_29 ;
V_90 -- ;
}
if ( V_90 > F_15 ( V_3 ) )
return 0 ;
if ( F_61 ( V_3 , V_83 , V_89 ) == false )
return 0 ;
V_83 -> V_57 = V_90 ;
return 1 ;
}
void F_62 ( struct V_53 * V_54 )
{
unsigned int V_91 = V_54 -> V_73 & V_92 ;
struct V_1 * V_1 ;
if ( V_54 -> V_73 & V_93 )
return;
for ( V_1 = V_54 -> V_1 ; V_1 ; V_1 = V_1 -> V_62 ) {
F_63 ( ( V_1 -> V_41 & V_92 ) &&
( V_1 -> V_41 & V_92 ) != V_91 ) ;
V_1 -> V_41 |= V_91 ;
}
V_54 -> V_73 |= V_93 ;
}
static void F_64 ( struct V_53 * V_83 )
{
if ( F_65 ( V_83 ) ) {
struct V_94 * V_95 ;
int V_96 ;
V_96 = F_66 () ;
V_95 = V_83 -> V_95 ;
F_67 ( V_96 , V_95 ) ;
F_68 ( V_95 , F_69 ( V_83 ) ) ;
F_70 ( V_95 ) ;
F_71 () ;
}
}
static int F_72 ( struct V_2 * V_3 , struct V_53 * V_83 ,
struct V_53 * V_89 )
{
if ( ! F_73 ( V_83 ) || ! F_73 ( V_89 ) )
return 0 ;
if ( ! F_74 ( V_83 -> V_73 , V_89 -> V_73 ) )
return 0 ;
if ( F_75 ( V_83 ) + F_54 ( V_83 ) != F_75 ( V_89 ) )
return 0 ;
if ( F_69 ( V_83 ) != F_69 ( V_89 )
|| V_83 -> V_97 != V_89 -> V_97
|| F_59 ( V_89 ) )
return 0 ;
if ( V_83 -> V_73 & V_43 &&
! F_76 ( V_83 -> V_1 , V_89 -> V_1 ) )
return 0 ;
if ( ! F_60 ( V_3 , V_83 , V_89 ) )
return 0 ;
if ( ( V_83 -> V_73 | V_89 -> V_73 ) & V_93 ||
( V_83 -> V_73 & V_92 ) !=
( V_89 -> V_73 & V_92 ) ) {
F_62 ( V_83 ) ;
F_62 ( V_89 ) ;
}
if ( F_77 ( V_83 -> V_98 , V_89 -> V_98 ) )
V_83 -> V_98 = V_89 -> V_98 ;
V_83 -> V_86 -> V_62 = V_89 -> V_1 ;
V_83 -> V_86 = V_89 -> V_86 ;
V_83 -> V_99 += F_43 ( V_89 ) ;
F_78 ( V_3 , V_83 , V_89 ) ;
F_64 ( V_89 ) ;
V_83 -> V_100 = F_79 ( V_83 -> V_100 , V_89 -> V_100 ) ;
if ( F_80 ( V_89 ) )
V_83 -> V_96 = V_89 -> V_96 ;
V_89 -> V_1 = NULL ;
F_81 ( V_3 , V_89 ) ;
return 1 ;
}
int F_82 ( struct V_2 * V_3 , struct V_53 * V_54 )
{
struct V_53 * V_89 = F_83 ( V_3 , V_54 ) ;
if ( V_89 )
return F_72 ( V_3 , V_54 , V_89 ) ;
return 0 ;
}
int F_84 ( struct V_2 * V_3 , struct V_53 * V_54 )
{
struct V_53 * V_49 = F_85 ( V_3 , V_54 ) ;
if ( V_49 )
return F_72 ( V_3 , V_49 , V_54 ) ;
return 0 ;
}
int F_86 ( struct V_2 * V_3 , struct V_53 * V_54 ,
struct V_53 * V_89 )
{
return F_72 ( V_3 , V_54 , V_89 ) ;
}
bool F_87 ( struct V_53 * V_54 , struct V_1 * V_1 )
{
if ( ! F_73 ( V_54 ) || ! F_88 ( V_1 ) )
return false ;
if ( ! F_74 ( V_54 -> V_73 , V_1 -> V_41 ) )
return false ;
if ( F_89 ( V_1 ) != F_69 ( V_54 ) )
return false ;
if ( V_54 -> V_97 != V_1 -> V_101 -> V_102 || F_59 ( V_54 ) )
return false ;
if ( F_49 ( V_54 -> V_3 , V_54 , V_1 ) == false )
return false ;
if ( V_54 -> V_73 & V_43 &&
! F_76 ( V_54 -> V_1 , V_1 ) )
return false ;
return true ;
}
int F_90 ( struct V_53 * V_54 , struct V_1 * V_1 )
{
if ( F_75 ( V_54 ) + F_54 ( V_54 ) == V_1 -> V_16 . V_17 )
return V_103 ;
else if ( F_75 ( V_54 ) - F_5 ( V_1 ) == V_1 -> V_16 . V_17 )
return V_104 ;
return V_105 ;
}
