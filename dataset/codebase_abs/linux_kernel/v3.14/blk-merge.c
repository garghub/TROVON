static unsigned int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_4 V_5 , V_6 = { NULL } ;
int V_7 , V_8 , V_9 = 1 ;
unsigned int V_10 , V_11 ;
struct V_3 * V_12 , * V_13 ;
struct V_14 V_15 ;
if ( ! V_3 )
return 0 ;
if ( V_3 -> V_16 & V_17 )
return 1 ;
if ( V_3 -> V_16 & V_18 )
return 1 ;
V_12 = V_3 ;
V_7 = F_2 ( V_2 ) ;
V_10 = 0 ;
V_11 = 0 ;
F_3 (bio) {
F_4 (bv, bio, iter) {
V_8 = F_5 ( V_5 . V_19 ) > F_6 ( V_2 ) ;
if ( ! V_8 && ! V_9 && V_7 ) {
if ( V_10 + V_5 . V_20
> F_7 ( V_2 ) )
goto V_21;
if ( ! F_8 ( & V_6 , & V_5 ) )
goto V_21;
if ( ! F_9 ( V_2 , & V_6 , & V_5 ) )
goto V_21;
V_10 += V_5 . V_20 ;
V_6 = V_5 ;
continue;
}
V_21:
if ( V_11 == 1 && V_10 >
V_12 -> V_22 )
V_12 -> V_22 = V_10 ;
V_11 ++ ;
V_6 = V_5 ;
V_10 = V_5 . V_20 ;
V_9 = V_8 ;
}
V_13 = V_3 ;
}
if ( V_11 == 1 && V_10 > V_12 -> V_22 )
V_12 -> V_22 = V_10 ;
if ( V_10 > V_13 -> V_23 )
V_13 -> V_23 = V_10 ;
return V_11 ;
}
void F_10 ( struct V_24 * V_25 )
{
V_25 -> V_26 = F_1 ( V_25 -> V_2 , V_25 -> V_3 ) ;
}
void F_11 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_3 * V_27 = V_3 -> V_28 ;
V_3 -> V_28 = NULL ;
V_3 -> V_29 = F_1 ( V_2 , V_3 ) ;
V_3 -> V_28 = V_27 ;
V_3 -> V_30 |= ( 1 << V_31 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_3 * V_27 )
{
struct V_4 V_32 = { NULL } , V_33 ;
struct V_14 V_15 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( V_3 -> V_23 + V_27 -> V_22 >
F_7 ( V_2 ) )
return 0 ;
if ( ! F_13 ( V_3 ) )
return 1 ;
F_4 (end_bv, bio, iter)
if ( V_32 . V_20 == V_15 . V_34 )
break;
V_33 = F_14 ( V_27 ) ;
if ( ! F_8 ( & V_32 , & V_33 ) )
return 0 ;
if ( F_9 ( V_2 , & V_32 , & V_33 ) )
return 1 ;
return 0 ;
}
static inline void
F_15 ( struct V_1 * V_2 , struct V_4 * V_35 ,
struct V_36 * V_37 , struct V_4 * V_6 ,
struct V_36 * * V_38 , int * V_39 , int * V_7 )
{
int V_40 = V_35 -> V_20 ;
if ( * V_38 && * V_7 ) {
if ( ( * V_38 ) -> V_41 + V_40 > F_7 ( V_2 ) )
goto V_21;
if ( ! F_8 ( V_6 , V_35 ) )
goto V_21;
if ( ! F_9 ( V_2 , V_6 , V_35 ) )
goto V_21;
( * V_38 ) -> V_41 += V_40 ;
} else {
V_21:
if ( ! * V_38 )
* V_38 = V_37 ;
else {
F_16 ( * V_38 ) ;
* V_38 = F_17 ( * V_38 ) ;
}
F_18 ( * V_38 , V_35 -> V_19 , V_40 , V_35 -> V_42 ) ;
( * V_39 ) ++ ;
}
* V_6 = * V_35 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_36 * V_37 ,
struct V_36 * * V_38 )
{
struct V_4 V_35 , V_6 = { NULL } ;
struct V_14 V_15 ;
int V_39 , V_7 ;
V_39 = 0 ;
V_7 = F_2 ( V_2 ) ;
if ( V_3 -> V_16 & V_17 ) {
if ( V_3 -> V_43 )
goto V_44;
return 0 ;
}
if ( V_3 -> V_16 & V_18 ) {
V_44:
* V_38 = V_37 ;
V_35 = F_14 ( V_3 ) ;
F_18 ( * V_38 , V_35 . V_19 , V_35 . V_20 , V_35 . V_42 ) ;
return 1 ;
}
F_3 (bio)
F_4 (bvec, bio, iter)
F_15 ( V_2 , & V_35 , V_37 , & V_6 , V_38 ,
& V_39 , & V_7 ) ;
return V_39 ;
}
int F_20 ( struct V_1 * V_2 , struct V_24 * V_25 ,
struct V_36 * V_37 )
{
struct V_36 * V_38 = NULL ;
int V_39 = 0 ;
if ( V_25 -> V_3 )
V_39 = F_19 ( V_2 , V_25 -> V_3 , V_37 , & V_38 ) ;
if ( F_21 ( V_25 -> V_45 & V_46 ) &&
( F_22 ( V_25 ) & V_2 -> V_47 ) ) {
unsigned int V_48 =
( V_2 -> V_47 & ~ F_22 ( V_25 ) ) + 1 ;
V_38 -> V_41 += V_48 ;
V_25 -> V_49 += V_48 ;
}
if ( V_2 -> V_50 && V_2 -> V_51 ( V_25 ) ) {
if ( V_25 -> V_45 & V_52 )
memset ( V_2 -> V_53 , 0 , V_2 -> V_50 ) ;
V_38 -> V_54 &= ~ 0x02 ;
V_38 = F_17 ( V_38 ) ;
F_18 ( V_38 , F_23 ( V_2 -> V_53 ) ,
V_2 -> V_50 ,
( ( unsigned long ) V_2 -> V_53 ) &
( V_55 - 1 ) ) ;
V_39 ++ ;
V_25 -> V_49 += V_2 -> V_50 ;
}
if ( V_38 )
F_24 ( V_38 ) ;
return V_39 ;
}
int F_25 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_36 * V_37 )
{
struct V_36 * V_38 = NULL ;
int V_39 ;
struct V_3 * V_56 = V_3 -> V_28 ;
V_3 -> V_28 = NULL ;
V_39 = F_19 ( V_2 , V_3 , V_37 , & V_38 ) ;
V_3 -> V_28 = V_56 ;
if ( V_38 )
F_24 ( V_38 ) ;
F_26 ( V_3 -> V_29 && V_39 > V_3 -> V_29 ) ;
return V_39 ;
}
static inline int F_27 ( struct V_1 * V_2 ,
struct V_24 * V_57 ,
struct V_3 * V_3 )
{
int V_11 = F_28 ( V_2 , V_3 ) ;
if ( V_57 -> V_26 + V_11 > F_29 ( V_2 ) )
goto V_58;
if ( F_30 ( V_3 ) && F_31 ( V_2 , V_57 , V_3 ) )
goto V_58;
V_57 -> V_26 += V_11 ;
return 1 ;
V_58:
V_57 -> V_45 |= V_59 ;
if ( V_57 == V_2 -> V_60 )
V_2 -> V_60 = NULL ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , struct V_24 * V_57 ,
struct V_3 * V_3 )
{
if ( F_33 ( V_57 ) + F_34 ( V_3 ) >
F_35 ( V_57 ) ) {
V_57 -> V_45 |= V_59 ;
if ( V_57 == V_2 -> V_60 )
V_2 -> V_60 = NULL ;
return 0 ;
}
if ( ! F_36 ( V_57 -> V_61 , V_31 ) )
F_11 ( V_2 , V_57 -> V_61 ) ;
if ( ! F_36 ( V_3 , V_31 ) )
F_11 ( V_2 , V_3 ) ;
return F_27 ( V_2 , V_57 , V_3 ) ;
}
int F_37 ( struct V_1 * V_2 , struct V_24 * V_57 ,
struct V_3 * V_3 )
{
if ( F_33 ( V_57 ) + F_34 ( V_3 ) >
F_35 ( V_57 ) ) {
V_57 -> V_45 |= V_59 ;
if ( V_57 == V_2 -> V_60 )
V_2 -> V_60 = NULL ;
return 0 ;
}
if ( ! F_36 ( V_3 , V_31 ) )
F_11 ( V_2 , V_3 ) ;
if ( ! F_36 ( V_57 -> V_3 , V_31 ) )
F_11 ( V_2 , V_57 -> V_3 ) ;
return F_27 ( V_2 , V_57 , V_3 ) ;
}
static bool F_38 ( struct V_24 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_2 ;
return ! V_2 -> V_62 && V_57 -> V_63 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_24 * V_57 ,
struct V_24 * V_56 )
{
int V_64 ;
unsigned int V_10 =
V_57 -> V_61 -> V_23 + V_56 -> V_3 -> V_22 ;
if ( F_38 ( V_57 ) || F_38 ( V_56 ) )
return 0 ;
if ( ( F_33 ( V_57 ) + F_33 ( V_56 ) ) >
F_35 ( V_57 ) )
return 0 ;
V_64 = V_57 -> V_26 + V_56 -> V_26 ;
if ( F_12 ( V_2 , V_57 -> V_61 , V_56 -> V_3 ) ) {
if ( V_57 -> V_26 == 1 )
V_57 -> V_3 -> V_22 = V_10 ;
if ( V_56 -> V_26 == 1 )
V_56 -> V_61 -> V_23 = V_10 ;
V_64 -- ;
}
if ( V_64 > F_29 ( V_2 ) )
return 0 ;
if ( F_40 ( V_57 ) && F_41 ( V_2 , V_57 , V_56 ) )
return 0 ;
V_57 -> V_26 = V_64 ;
return 1 ;
}
void F_42 ( struct V_24 * V_25 )
{
unsigned int V_65 = V_25 -> V_45 & V_66 ;
struct V_3 * V_3 ;
if ( V_25 -> V_45 & V_67 )
return;
for ( V_3 = V_25 -> V_3 ; V_3 ; V_3 = V_3 -> V_28 ) {
F_43 ( ( V_3 -> V_16 & V_66 ) &&
( V_3 -> V_16 & V_66 ) != V_65 ) ;
V_3 -> V_16 |= V_65 ;
}
V_25 -> V_45 |= V_67 ;
}
static void F_44 ( struct V_24 * V_57 )
{
if ( F_45 ( V_57 ) ) {
struct V_68 * V_69 ;
int V_70 ;
V_70 = F_46 () ;
V_69 = V_57 -> V_69 ;
F_47 ( V_70 , V_69 ) ;
F_48 ( V_69 , F_49 ( V_57 ) ) ;
F_50 ( V_69 ) ;
F_51 () ;
}
}
static int F_52 ( struct V_1 * V_2 , struct V_24 * V_57 ,
struct V_24 * V_56 )
{
if ( ! F_53 ( V_57 ) || ! F_53 ( V_56 ) )
return 0 ;
if ( ! F_54 ( V_57 -> V_45 , V_56 -> V_45 ) )
return 0 ;
if ( F_55 ( V_57 ) + F_33 ( V_57 ) != F_55 ( V_56 ) )
return 0 ;
if ( F_49 ( V_57 ) != F_49 ( V_56 )
|| V_57 -> V_71 != V_56 -> V_71
|| F_38 ( V_56 ) )
return 0 ;
if ( V_57 -> V_45 & V_18 &&
! F_56 ( V_57 -> V_3 , V_56 -> V_3 ) )
return 0 ;
if ( ! F_39 ( V_2 , V_57 , V_56 ) )
return 0 ;
if ( ( V_57 -> V_45 | V_56 -> V_45 ) & V_67 ||
( V_57 -> V_45 & V_66 ) !=
( V_56 -> V_45 & V_66 ) ) {
F_42 ( V_57 ) ;
F_42 ( V_56 ) ;
}
if ( F_57 ( V_57 -> V_72 , V_56 -> V_72 ) )
V_57 -> V_72 = V_56 -> V_72 ;
V_57 -> V_61 -> V_28 = V_56 -> V_3 ;
V_57 -> V_61 = V_56 -> V_61 ;
V_57 -> V_73 += F_22 ( V_56 ) ;
F_58 ( V_2 , V_57 , V_56 ) ;
F_44 ( V_56 ) ;
V_57 -> V_74 = F_59 ( V_57 -> V_74 , V_56 -> V_74 ) ;
if ( F_60 ( V_56 ) )
V_57 -> V_70 = V_56 -> V_70 ;
V_56 -> V_3 = NULL ;
F_61 ( V_2 , V_56 ) ;
return 1 ;
}
int F_62 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_24 * V_56 = F_63 ( V_2 , V_25 ) ;
if ( V_56 )
return F_52 ( V_2 , V_25 , V_56 ) ;
return 0 ;
}
int F_64 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_24 * V_75 = F_65 ( V_2 , V_25 ) ;
if ( V_75 )
return F_52 ( V_2 , V_75 , V_25 ) ;
return 0 ;
}
int F_66 ( struct V_1 * V_2 , struct V_24 * V_25 ,
struct V_24 * V_56 )
{
return F_52 ( V_2 , V_25 , V_56 ) ;
}
bool F_67 ( struct V_24 * V_25 , struct V_3 * V_3 )
{
if ( ! F_53 ( V_25 ) || ! F_68 ( V_3 ) )
return false ;
if ( ! F_54 ( V_25 -> V_45 , V_3 -> V_16 ) )
return false ;
if ( F_69 ( V_3 ) != F_49 ( V_25 ) )
return false ;
if ( V_25 -> V_71 != V_3 -> V_76 -> V_77 || F_38 ( V_25 ) )
return false ;
if ( F_30 ( V_3 ) != F_40 ( V_25 ) )
return false ;
if ( V_25 -> V_45 & V_18 &&
! F_56 ( V_25 -> V_3 , V_3 ) )
return false ;
return true ;
}
int F_70 ( struct V_24 * V_25 , struct V_3 * V_3 )
{
if ( F_55 ( V_25 ) + F_33 ( V_25 ) == V_3 -> V_78 . V_79 )
return V_80 ;
else if ( F_55 ( V_25 ) - F_34 ( V_3 ) == V_3 -> V_78 . V_79 )
return V_81 ;
return V_82 ;
}
