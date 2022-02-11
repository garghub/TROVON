static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
struct V_4 * V_5 )
{
unsigned int V_6 , V_7 ;
int V_8 ;
T_1 V_9 ;
unsigned V_10 ;
V_7 = F_2 ( V_3 -> V_11 . V_12 >> 9 , 1U ) ;
V_6 = F_3 ( V_3 -> V_11 . V_6 , V_13 >> 9 ) ;
V_6 -= V_6 % V_7 ;
if ( F_4 ( ! V_6 ) ) {
return NULL ;
}
if ( F_5 ( V_1 ) <= V_6 )
return NULL ;
V_10 = V_6 ;
V_8 = ( V_3 -> V_11 . V_14 >> 9 ) % V_7 ;
V_9 = V_1 -> V_15 . V_16 + V_10 - V_8 ;
V_9 = F_6 ( V_9 , V_7 ) ;
if ( V_10 > V_9 )
V_10 -= V_9 ;
return F_7 ( V_1 , V_10 , V_17 , V_5 ) ;
}
static struct V_1 * F_8 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
struct V_4 * V_5 )
{
if ( ! V_3 -> V_11 . V_18 )
return NULL ;
if ( F_5 ( V_1 ) <= V_3 -> V_11 . V_18 )
return NULL ;
return F_7 ( V_1 , V_3 -> V_11 . V_18 , V_17 , V_5 ) ;
}
static struct V_1 * F_9 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
struct V_4 * V_5 )
{
struct V_19 V_20 , V_21 , * V_22 = NULL ;
struct V_23 V_24 ;
unsigned V_25 = 0 , V_26 = 0 , V_27 = 0 ;
F_10 (bv, bio, iter) {
if ( V_27 + ( V_20 . V_28 >> 9 ) > F_11 ( V_3 ) )
goto V_29;
if ( V_22 && F_12 ( V_3 , V_22 , V_20 . V_30 ) )
goto V_29;
if ( V_22 && F_13 ( V_3 ) ) {
if ( V_25 + V_20 . V_28 > F_14 ( V_3 ) )
goto V_31;
if ( ! F_15 ( V_22 , & V_20 ) )
goto V_31;
if ( ! F_16 ( V_3 , V_22 , & V_20 ) )
goto V_31;
V_25 += V_20 . V_28 ;
V_21 = V_20 ;
V_22 = & V_20 ;
V_27 += V_20 . V_28 >> 9 ;
continue;
}
V_31:
if ( V_26 == F_17 ( V_3 ) )
goto V_29;
V_26 ++ ;
V_21 = V_20 ;
V_22 = & V_20 ;
V_25 = V_20 . V_28 ;
V_27 += V_20 . V_28 >> 9 ;
}
return NULL ;
V_29:
return F_7 ( V_1 , V_27 , V_17 , V_5 ) ;
}
void F_18 ( struct V_2 * V_3 , struct V_1 * * V_1 ,
struct V_4 * V_5 )
{
struct V_1 * V_29 ;
if ( ( * V_1 ) -> V_32 & V_33 )
V_29 = F_1 ( V_3 , * V_1 , V_5 ) ;
else if ( ( * V_1 ) -> V_32 & V_34 )
V_29 = F_8 ( V_3 , * V_1 , V_5 ) ;
else
V_29 = F_9 ( V_3 , * V_1 , V_3 -> F_7 ) ;
if ( V_29 ) {
F_19 ( V_29 , * V_1 ) ;
F_20 ( * V_1 ) ;
* V_1 = V_29 ;
}
}
static unsigned int F_21 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
bool V_35 )
{
struct V_19 V_20 , V_21 = { NULL } ;
int V_36 , V_37 = 0 ;
unsigned int V_25 , V_38 ;
struct V_1 * V_39 , * V_40 ;
struct V_23 V_24 ;
if ( ! V_1 )
return 0 ;
if ( V_1 -> V_32 & V_33 )
return 1 ;
if ( V_1 -> V_32 & V_34 )
return 1 ;
V_39 = V_1 ;
V_36 = F_13 ( V_3 ) ;
V_25 = 0 ;
V_38 = 0 ;
F_22 (bio) {
F_10 (bv, bio, iter) {
if ( V_35 )
goto V_31;
if ( V_37 && V_36 ) {
if ( V_25 + V_20 . V_28
> F_14 ( V_3 ) )
goto V_31;
if ( ! F_15 ( & V_21 , & V_20 ) )
goto V_31;
if ( ! F_16 ( V_3 , & V_21 , & V_20 ) )
goto V_31;
V_25 += V_20 . V_28 ;
V_21 = V_20 ;
continue;
}
V_31:
if ( V_38 == 1 && V_25 >
V_39 -> V_41 )
V_39 -> V_41 = V_25 ;
V_38 ++ ;
V_21 = V_20 ;
V_37 = 1 ;
V_25 = V_20 . V_28 ;
}
V_40 = V_1 ;
}
if ( V_38 == 1 && V_25 > V_39 -> V_41 )
V_39 -> V_41 = V_25 ;
if ( V_25 > V_40 -> V_42 )
V_40 -> V_42 = V_25 ;
return V_38 ;
}
void F_23 ( struct V_43 * V_44 )
{
bool V_35 = ! ! F_24 ( V_45 ,
& V_44 -> V_3 -> V_46 ) ;
V_44 -> V_47 = F_21 ( V_44 -> V_3 , V_44 -> V_1 ,
V_35 ) ;
}
void F_25 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
unsigned short V_48 ;
if ( F_26 ( V_1 , V_49 ) )
V_48 = F_27 ( V_1 ) ;
else
V_48 = V_1 -> V_50 ;
if ( F_24 ( V_45 , & V_3 -> V_46 ) &&
( V_48 < F_17 ( V_3 ) ) )
V_1 -> V_51 = V_48 ;
else {
struct V_1 * V_52 = V_1 -> V_53 ;
V_1 -> V_53 = NULL ;
V_1 -> V_51 = F_21 ( V_3 , V_1 , false ) ;
V_1 -> V_53 = V_52 ;
}
F_28 ( V_1 , V_54 ) ;
}
static int F_29 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_1 * V_52 )
{
struct V_19 V_55 = { NULL } , V_56 ;
struct V_23 V_24 ;
if ( ! F_13 ( V_3 ) )
return 0 ;
if ( V_1 -> V_42 + V_52 -> V_41 >
F_14 ( V_3 ) )
return 0 ;
if ( ! F_30 ( V_1 ) )
return 1 ;
F_10 (end_bv, bio, iter)
if ( V_55 . V_28 == V_24 . V_57 )
break;
V_56 = F_31 ( V_52 ) ;
if ( ! F_15 ( & V_55 , & V_56 ) )
return 0 ;
if ( F_16 ( V_3 , & V_55 , & V_56 ) )
return 1 ;
return 0 ;
}
static inline void
F_32 ( struct V_2 * V_3 , struct V_19 * V_58 ,
struct V_59 * V_60 , struct V_19 * V_21 ,
struct V_59 * * V_61 , int * V_26 , int * V_36 )
{
int V_62 = V_58 -> V_28 ;
if ( * V_61 && * V_36 ) {
if ( ( * V_61 ) -> V_63 + V_62 > F_14 ( V_3 ) )
goto V_31;
if ( ! F_15 ( V_21 , V_58 ) )
goto V_31;
if ( ! F_16 ( V_3 , V_21 , V_58 ) )
goto V_31;
( * V_61 ) -> V_63 += V_62 ;
} else {
V_31:
if ( ! * V_61 )
* V_61 = V_60 ;
else {
F_33 ( * V_61 ) ;
* V_61 = F_34 ( * V_61 ) ;
}
F_35 ( * V_61 , V_58 -> V_64 , V_62 , V_58 -> V_30 ) ;
( * V_26 ) ++ ;
}
* V_21 = * V_58 ;
}
static int F_36 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_59 * V_60 ,
struct V_59 * * V_61 )
{
struct V_19 V_58 , V_21 = { NULL } ;
struct V_23 V_24 ;
int V_26 , V_36 ;
V_26 = 0 ;
V_36 = F_13 ( V_3 ) ;
if ( V_1 -> V_32 & V_33 ) {
if ( V_1 -> V_50 )
goto V_65;
return 0 ;
}
if ( V_1 -> V_32 & V_34 ) {
V_65:
* V_61 = V_60 ;
V_58 = F_31 ( V_1 ) ;
F_35 ( * V_61 , V_58 . V_64 , V_58 . V_28 , V_58 . V_30 ) ;
return 1 ;
}
F_22 (bio)
F_10 (bvec, bio, iter)
F_32 ( V_3 , & V_58 , V_60 , & V_21 , V_61 ,
& V_26 , & V_36 ) ;
return V_26 ;
}
int F_37 ( struct V_2 * V_3 , struct V_43 * V_44 ,
struct V_59 * V_60 )
{
struct V_59 * V_61 = NULL ;
int V_26 = 0 ;
if ( V_44 -> V_1 )
V_26 = F_36 ( V_3 , V_44 -> V_1 , V_60 , & V_61 ) ;
if ( F_4 ( V_44 -> V_66 & V_67 ) &&
( F_38 ( V_44 ) & V_3 -> V_68 ) ) {
unsigned int V_69 =
( V_3 -> V_68 & ~ F_38 ( V_44 ) ) + 1 ;
V_61 -> V_63 += V_69 ;
V_44 -> V_70 += V_69 ;
}
if ( V_3 -> V_71 && V_3 -> V_72 ( V_44 ) ) {
if ( V_44 -> V_66 & V_73 )
memset ( V_3 -> V_74 , 0 , V_3 -> V_71 ) ;
F_33 ( V_61 ) ;
V_61 = F_34 ( V_61 ) ;
F_35 ( V_61 , F_39 ( V_3 -> V_74 ) ,
V_3 -> V_71 ,
( ( unsigned long ) V_3 -> V_74 ) &
( V_75 - 1 ) ) ;
V_26 ++ ;
V_44 -> V_70 += V_3 -> V_71 ;
}
if ( V_61 )
F_40 ( V_61 ) ;
return V_26 ;
}
static inline int F_41 ( struct V_2 * V_3 ,
struct V_43 * V_76 ,
struct V_1 * V_1 )
{
int V_38 = F_42 ( V_3 , V_1 ) ;
if ( V_76 -> V_47 + V_38 > F_17 ( V_3 ) )
goto V_77;
if ( F_43 ( V_3 , V_76 , V_1 ) == false )
goto V_77;
V_76 -> V_47 += V_38 ;
return 1 ;
V_77:
V_76 -> V_66 |= V_78 ;
if ( V_76 == V_3 -> V_79 )
V_3 -> V_79 = NULL ;
return 0 ;
}
int F_44 ( struct V_2 * V_3 , struct V_43 * V_76 ,
struct V_1 * V_1 )
{
if ( F_45 ( V_76 , V_1 ) )
return 0 ;
if ( F_46 ( V_76 ) &&
F_47 ( V_76 , V_1 ) )
return 0 ;
if ( F_48 ( V_76 ) + F_5 ( V_1 ) >
F_49 ( V_76 ) ) {
V_76 -> V_66 |= V_78 ;
if ( V_76 == V_3 -> V_79 )
V_3 -> V_79 = NULL ;
return 0 ;
}
if ( ! F_26 ( V_76 -> V_80 , V_54 ) )
F_25 ( V_3 , V_76 -> V_80 ) ;
if ( ! F_26 ( V_1 , V_54 ) )
F_25 ( V_3 , V_1 ) ;
return F_41 ( V_3 , V_76 , V_1 ) ;
}
int F_50 ( struct V_2 * V_3 , struct V_43 * V_76 ,
struct V_1 * V_1 )
{
if ( F_51 ( V_76 , V_1 ) )
return 0 ;
if ( F_46 ( V_76 ) &&
F_52 ( V_76 , V_1 ) )
return 0 ;
if ( F_48 ( V_76 ) + F_5 ( V_1 ) >
F_49 ( V_76 ) ) {
V_76 -> V_66 |= V_78 ;
if ( V_76 == V_3 -> V_79 )
V_3 -> V_79 = NULL ;
return 0 ;
}
if ( ! F_26 ( V_1 , V_54 ) )
F_25 ( V_3 , V_1 ) ;
if ( ! F_26 ( V_76 -> V_1 , V_54 ) )
F_25 ( V_3 , V_76 -> V_1 ) ;
return F_41 ( V_3 , V_76 , V_1 ) ;
}
static bool F_53 ( struct V_43 * V_76 )
{
struct V_2 * V_3 = V_76 -> V_3 ;
return ! V_3 -> V_81 && V_76 -> V_82 ;
}
static int F_54 ( struct V_2 * V_3 , struct V_43 * V_76 ,
struct V_43 * V_83 )
{
int V_84 ;
unsigned int V_25 =
V_76 -> V_80 -> V_42 + V_83 -> V_1 -> V_41 ;
if ( F_53 ( V_76 ) || F_53 ( V_83 ) )
return 0 ;
if ( F_45 ( V_76 , V_83 -> V_1 ) )
return 0 ;
if ( ( F_48 ( V_76 ) + F_48 ( V_83 ) ) >
F_49 ( V_76 ) )
return 0 ;
V_84 = V_76 -> V_47 + V_83 -> V_47 ;
if ( F_29 ( V_3 , V_76 -> V_80 , V_83 -> V_1 ) ) {
if ( V_76 -> V_47 == 1 )
V_76 -> V_1 -> V_41 = V_25 ;
if ( V_83 -> V_47 == 1 )
V_83 -> V_80 -> V_42 = V_25 ;
V_84 -- ;
}
if ( V_84 > F_17 ( V_3 ) )
return 0 ;
if ( F_55 ( V_3 , V_76 , V_83 ) == false )
return 0 ;
V_76 -> V_47 = V_84 ;
return 1 ;
}
void F_56 ( struct V_43 * V_44 )
{
unsigned int V_85 = V_44 -> V_66 & V_86 ;
struct V_1 * V_1 ;
if ( V_44 -> V_66 & V_87 )
return;
for ( V_1 = V_44 -> V_1 ; V_1 ; V_1 = V_1 -> V_53 ) {
F_57 ( ( V_1 -> V_32 & V_86 ) &&
( V_1 -> V_32 & V_86 ) != V_85 ) ;
V_1 -> V_32 |= V_85 ;
}
V_44 -> V_66 |= V_87 ;
}
static void F_58 ( struct V_43 * V_76 )
{
if ( F_59 ( V_76 ) ) {
struct V_88 * V_89 ;
int V_90 ;
V_90 = F_60 () ;
V_89 = V_76 -> V_89 ;
F_61 ( V_90 , V_89 ) ;
F_62 ( V_89 , F_63 ( V_76 ) ) ;
F_64 ( V_89 ) ;
F_65 () ;
}
}
static int F_66 ( struct V_2 * V_3 , struct V_43 * V_76 ,
struct V_43 * V_83 )
{
if ( ! F_67 ( V_76 ) || ! F_67 ( V_83 ) )
return 0 ;
if ( ! F_68 ( V_76 -> V_66 , V_83 -> V_66 ) )
return 0 ;
if ( F_69 ( V_76 ) + F_48 ( V_76 ) != F_69 ( V_83 ) )
return 0 ;
if ( F_63 ( V_76 ) != F_63 ( V_83 )
|| V_76 -> V_91 != V_83 -> V_91
|| F_53 ( V_83 ) )
return 0 ;
if ( V_76 -> V_66 & V_34 &&
! F_70 ( V_76 -> V_1 , V_83 -> V_1 ) )
return 0 ;
if ( ! F_54 ( V_3 , V_76 , V_83 ) )
return 0 ;
if ( ( V_76 -> V_66 | V_83 -> V_66 ) & V_87 ||
( V_76 -> V_66 & V_86 ) !=
( V_83 -> V_66 & V_86 ) ) {
F_56 ( V_76 ) ;
F_56 ( V_83 ) ;
}
if ( F_71 ( V_76 -> V_92 , V_83 -> V_92 ) )
V_76 -> V_92 = V_83 -> V_92 ;
V_76 -> V_80 -> V_53 = V_83 -> V_1 ;
V_76 -> V_80 = V_83 -> V_80 ;
V_76 -> V_93 += F_38 ( V_83 ) ;
F_72 ( V_3 , V_76 , V_83 ) ;
F_58 ( V_83 ) ;
V_76 -> V_94 = F_73 ( V_76 -> V_94 , V_83 -> V_94 ) ;
if ( F_74 ( V_83 ) )
V_76 -> V_90 = V_83 -> V_90 ;
V_83 -> V_1 = NULL ;
F_75 ( V_3 , V_83 ) ;
return 1 ;
}
int F_76 ( struct V_2 * V_3 , struct V_43 * V_44 )
{
struct V_43 * V_83 = F_77 ( V_3 , V_44 ) ;
if ( V_83 )
return F_66 ( V_3 , V_44 , V_83 ) ;
return 0 ;
}
int F_78 ( struct V_2 * V_3 , struct V_43 * V_44 )
{
struct V_43 * V_37 = F_79 ( V_3 , V_44 ) ;
if ( V_37 )
return F_66 ( V_3 , V_37 , V_44 ) ;
return 0 ;
}
int F_80 ( struct V_2 * V_3 , struct V_43 * V_44 ,
struct V_43 * V_83 )
{
return F_66 ( V_3 , V_44 , V_83 ) ;
}
bool F_81 ( struct V_43 * V_44 , struct V_1 * V_1 )
{
if ( ! F_67 ( V_44 ) || ! F_82 ( V_1 ) )
return false ;
if ( ! F_68 ( V_44 -> V_66 , V_1 -> V_32 ) )
return false ;
if ( F_83 ( V_1 ) != F_63 ( V_44 ) )
return false ;
if ( V_44 -> V_91 != V_1 -> V_95 -> V_96 || F_53 ( V_44 ) )
return false ;
if ( F_43 ( V_44 -> V_3 , V_44 , V_1 ) == false )
return false ;
if ( V_44 -> V_66 & V_34 &&
! F_70 ( V_44 -> V_1 , V_1 ) )
return false ;
return true ;
}
int F_84 ( struct V_43 * V_44 , struct V_1 * V_1 )
{
if ( F_69 ( V_44 ) + F_48 ( V_44 ) == V_1 -> V_15 . V_16 )
return V_97 ;
else if ( F_69 ( V_44 ) - F_5 ( V_1 ) == V_1 -> V_15 . V_16 )
return V_98 ;
return V_99 ;
}
