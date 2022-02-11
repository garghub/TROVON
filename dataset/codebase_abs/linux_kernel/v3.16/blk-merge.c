static unsigned int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_4 V_5 , V_6 = { NULL } ;
int V_7 , V_8 , V_9 = 1 , V_10 ;
unsigned int V_11 , V_12 ;
struct V_3 * V_13 , * V_14 ;
struct V_15 V_16 ;
if ( ! V_3 )
return 0 ;
if ( V_3 -> V_17 & V_18 )
return 1 ;
if ( V_3 -> V_17 & V_19 )
return 1 ;
V_13 = V_3 ;
V_7 = F_2 ( V_2 ) ;
V_11 = 0 ;
V_12 = 0 ;
V_10 = F_3 ( V_20 , & V_2 -> V_21 ) ;
V_8 = 0 ;
F_4 (bio) {
F_5 (bv, bio, iter) {
if ( V_10 )
goto V_22;
V_8 = F_6 ( V_5 . V_23 ) > F_7 ( V_2 ) ;
if ( ! V_8 && ! V_9 && V_7 ) {
if ( V_11 + V_5 . V_24
> F_8 ( V_2 ) )
goto V_22;
if ( ! F_9 ( & V_6 , & V_5 ) )
goto V_22;
if ( ! F_10 ( V_2 , & V_6 , & V_5 ) )
goto V_22;
V_11 += V_5 . V_24 ;
V_6 = V_5 ;
continue;
}
V_22:
if ( V_12 == 1 && V_11 >
V_13 -> V_25 )
V_13 -> V_25 = V_11 ;
V_12 ++ ;
V_6 = V_5 ;
V_11 = V_5 . V_24 ;
V_9 = V_8 ;
}
V_14 = V_3 ;
}
if ( V_12 == 1 && V_11 > V_13 -> V_25 )
V_13 -> V_25 = V_11 ;
if ( V_11 > V_14 -> V_26 )
V_14 -> V_26 = V_11 ;
return V_12 ;
}
void F_11 ( struct V_27 * V_28 )
{
V_28 -> V_29 = F_1 ( V_28 -> V_2 , V_28 -> V_3 ) ;
}
void F_12 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
if ( F_3 ( V_20 , & V_2 -> V_21 ) )
V_3 -> V_30 = V_3 -> V_31 ;
else {
struct V_3 * V_32 = V_3 -> V_33 ;
V_3 -> V_33 = NULL ;
V_3 -> V_30 = F_1 ( V_2 , V_3 ) ;
V_3 -> V_33 = V_32 ;
}
V_3 -> V_34 |= ( 1 << V_35 ) ;
}
static int F_13 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_3 * V_32 )
{
struct V_4 V_36 = { NULL } , V_37 ;
struct V_15 V_16 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( V_3 -> V_26 + V_32 -> V_25 >
F_8 ( V_2 ) )
return 0 ;
if ( ! F_14 ( V_3 ) )
return 1 ;
F_5 (end_bv, bio, iter)
if ( V_36 . V_24 == V_16 . V_38 )
break;
V_37 = F_15 ( V_32 ) ;
if ( ! F_9 ( & V_36 , & V_37 ) )
return 0 ;
if ( F_10 ( V_2 , & V_36 , & V_37 ) )
return 1 ;
return 0 ;
}
static inline void
F_16 ( struct V_1 * V_2 , struct V_4 * V_39 ,
struct V_40 * V_41 , struct V_4 * V_6 ,
struct V_40 * * V_42 , int * V_43 , int * V_7 )
{
int V_44 = V_39 -> V_24 ;
if ( * V_42 && * V_7 ) {
if ( ( * V_42 ) -> V_45 + V_44 > F_8 ( V_2 ) )
goto V_22;
if ( ! F_9 ( V_6 , V_39 ) )
goto V_22;
if ( ! F_10 ( V_2 , V_6 , V_39 ) )
goto V_22;
( * V_42 ) -> V_45 += V_44 ;
} else {
V_22:
if ( ! * V_42 )
* V_42 = V_41 ;
else {
F_17 ( * V_42 ) ;
* V_42 = F_18 ( * V_42 ) ;
}
F_19 ( * V_42 , V_39 -> V_23 , V_44 , V_39 -> V_46 ) ;
( * V_43 ) ++ ;
}
* V_6 = * V_39 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_40 * V_41 ,
struct V_40 * * V_42 )
{
struct V_4 V_39 , V_6 = { NULL } ;
struct V_15 V_16 ;
int V_43 , V_7 ;
V_43 = 0 ;
V_7 = F_2 ( V_2 ) ;
if ( V_3 -> V_17 & V_18 ) {
if ( V_3 -> V_31 )
goto V_47;
return 0 ;
}
if ( V_3 -> V_17 & V_19 ) {
V_47:
* V_42 = V_41 ;
V_39 = F_15 ( V_3 ) ;
F_19 ( * V_42 , V_39 . V_23 , V_39 . V_24 , V_39 . V_46 ) ;
return 1 ;
}
F_4 (bio)
F_5 (bvec, bio, iter)
F_16 ( V_2 , & V_39 , V_41 , & V_6 , V_42 ,
& V_43 , & V_7 ) ;
return V_43 ;
}
int F_21 ( struct V_1 * V_2 , struct V_27 * V_28 ,
struct V_40 * V_41 )
{
struct V_40 * V_42 = NULL ;
int V_43 = 0 ;
if ( V_28 -> V_3 )
V_43 = F_20 ( V_2 , V_28 -> V_3 , V_41 , & V_42 ) ;
if ( F_22 ( V_28 -> V_48 & V_49 ) &&
( F_23 ( V_28 ) & V_2 -> V_50 ) ) {
unsigned int V_51 =
( V_2 -> V_50 & ~ F_23 ( V_28 ) ) + 1 ;
V_42 -> V_45 += V_51 ;
V_28 -> V_52 += V_51 ;
}
if ( V_2 -> V_53 && V_2 -> V_54 ( V_28 ) ) {
if ( V_28 -> V_48 & V_55 )
memset ( V_2 -> V_56 , 0 , V_2 -> V_53 ) ;
V_42 -> V_57 &= ~ 0x02 ;
V_42 = F_18 ( V_42 ) ;
F_19 ( V_42 , F_24 ( V_2 -> V_56 ) ,
V_2 -> V_53 ,
( ( unsigned long ) V_2 -> V_56 ) &
( V_58 - 1 ) ) ;
V_43 ++ ;
V_28 -> V_52 += V_2 -> V_53 ;
}
if ( V_42 )
F_25 ( V_42 ) ;
return V_43 ;
}
int F_26 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_40 * V_41 )
{
struct V_40 * V_42 = NULL ;
int V_43 ;
struct V_3 * V_59 = V_3 -> V_33 ;
V_3 -> V_33 = NULL ;
V_43 = F_20 ( V_2 , V_3 , V_41 , & V_42 ) ;
V_3 -> V_33 = V_59 ;
if ( V_42 )
F_25 ( V_42 ) ;
F_27 ( V_3 -> V_30 && V_43 > V_3 -> V_30 ) ;
return V_43 ;
}
static inline int F_28 ( struct V_1 * V_2 ,
struct V_27 * V_60 ,
struct V_3 * V_3 )
{
int V_12 = F_29 ( V_2 , V_3 ) ;
if ( V_60 -> V_29 + V_12 > F_30 ( V_2 ) )
goto V_61;
if ( F_31 ( V_3 ) && F_32 ( V_2 , V_60 , V_3 ) )
goto V_61;
V_60 -> V_29 += V_12 ;
return 1 ;
V_61:
V_60 -> V_48 |= V_62 ;
if ( V_60 == V_2 -> V_63 )
V_2 -> V_63 = NULL ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 , struct V_27 * V_60 ,
struct V_3 * V_3 )
{
if ( F_34 ( V_60 ) + F_35 ( V_3 ) >
F_36 ( V_60 ) ) {
V_60 -> V_48 |= V_62 ;
if ( V_60 == V_2 -> V_63 )
V_2 -> V_63 = NULL ;
return 0 ;
}
if ( ! F_37 ( V_60 -> V_64 , V_35 ) )
F_12 ( V_2 , V_60 -> V_64 ) ;
if ( ! F_37 ( V_3 , V_35 ) )
F_12 ( V_2 , V_3 ) ;
return F_28 ( V_2 , V_60 , V_3 ) ;
}
int F_38 ( struct V_1 * V_2 , struct V_27 * V_60 ,
struct V_3 * V_3 )
{
if ( F_34 ( V_60 ) + F_35 ( V_3 ) >
F_36 ( V_60 ) ) {
V_60 -> V_48 |= V_62 ;
if ( V_60 == V_2 -> V_63 )
V_2 -> V_63 = NULL ;
return 0 ;
}
if ( ! F_37 ( V_3 , V_35 ) )
F_12 ( V_2 , V_3 ) ;
if ( ! F_37 ( V_60 -> V_3 , V_35 ) )
F_12 ( V_2 , V_60 -> V_3 ) ;
return F_28 ( V_2 , V_60 , V_3 ) ;
}
static bool F_39 ( struct V_27 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
return ! V_2 -> V_65 && V_60 -> V_66 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_27 * V_60 ,
struct V_27 * V_59 )
{
int V_67 ;
unsigned int V_11 =
V_60 -> V_64 -> V_26 + V_59 -> V_3 -> V_25 ;
if ( F_39 ( V_60 ) || F_39 ( V_59 ) )
return 0 ;
if ( ( F_34 ( V_60 ) + F_34 ( V_59 ) ) >
F_36 ( V_60 ) )
return 0 ;
V_67 = V_60 -> V_29 + V_59 -> V_29 ;
if ( F_13 ( V_2 , V_60 -> V_64 , V_59 -> V_3 ) ) {
if ( V_60 -> V_29 == 1 )
V_60 -> V_3 -> V_25 = V_11 ;
if ( V_59 -> V_29 == 1 )
V_59 -> V_64 -> V_26 = V_11 ;
V_67 -- ;
}
if ( V_67 > F_30 ( V_2 ) )
return 0 ;
if ( F_41 ( V_60 ) && F_42 ( V_2 , V_60 , V_59 ) )
return 0 ;
V_60 -> V_29 = V_67 ;
return 1 ;
}
void F_43 ( struct V_27 * V_28 )
{
unsigned int V_68 = V_28 -> V_48 & V_69 ;
struct V_3 * V_3 ;
if ( V_28 -> V_48 & V_70 )
return;
for ( V_3 = V_28 -> V_3 ; V_3 ; V_3 = V_3 -> V_33 ) {
F_44 ( ( V_3 -> V_17 & V_69 ) &&
( V_3 -> V_17 & V_69 ) != V_68 ) ;
V_3 -> V_17 |= V_68 ;
}
V_28 -> V_48 |= V_70 ;
}
static void F_45 ( struct V_27 * V_60 )
{
if ( F_46 ( V_60 ) ) {
struct V_71 * V_72 ;
int V_73 ;
V_73 = F_47 () ;
V_72 = V_60 -> V_72 ;
F_48 ( V_73 , V_72 ) ;
F_49 ( V_72 , F_50 ( V_60 ) ) ;
F_51 ( V_72 ) ;
F_52 () ;
}
}
static int F_53 ( struct V_1 * V_2 , struct V_27 * V_60 ,
struct V_27 * V_59 )
{
if ( ! F_54 ( V_60 ) || ! F_54 ( V_59 ) )
return 0 ;
if ( ! F_55 ( V_60 -> V_48 , V_59 -> V_48 ) )
return 0 ;
if ( F_56 ( V_60 ) + F_34 ( V_60 ) != F_56 ( V_59 ) )
return 0 ;
if ( F_50 ( V_60 ) != F_50 ( V_59 )
|| V_60 -> V_74 != V_59 -> V_74
|| F_39 ( V_59 ) )
return 0 ;
if ( V_60 -> V_48 & V_19 &&
! F_57 ( V_60 -> V_3 , V_59 -> V_3 ) )
return 0 ;
if ( ! F_40 ( V_2 , V_60 , V_59 ) )
return 0 ;
if ( ( V_60 -> V_48 | V_59 -> V_48 ) & V_70 ||
( V_60 -> V_48 & V_69 ) !=
( V_59 -> V_48 & V_69 ) ) {
F_43 ( V_60 ) ;
F_43 ( V_59 ) ;
}
if ( F_58 ( V_60 -> V_75 , V_59 -> V_75 ) )
V_60 -> V_75 = V_59 -> V_75 ;
V_60 -> V_64 -> V_33 = V_59 -> V_3 ;
V_60 -> V_64 = V_59 -> V_64 ;
V_60 -> V_76 += F_23 ( V_59 ) ;
F_59 ( V_2 , V_60 , V_59 ) ;
F_45 ( V_59 ) ;
V_60 -> V_77 = F_60 ( V_60 -> V_77 , V_59 -> V_77 ) ;
if ( F_61 ( V_59 ) )
V_60 -> V_73 = V_59 -> V_73 ;
V_59 -> V_3 = NULL ;
F_62 ( V_2 , V_59 ) ;
return 1 ;
}
int F_63 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_27 * V_59 = F_64 ( V_2 , V_28 ) ;
if ( V_59 )
return F_53 ( V_2 , V_28 , V_59 ) ;
return 0 ;
}
int F_65 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_27 * V_78 = F_66 ( V_2 , V_28 ) ;
if ( V_78 )
return F_53 ( V_2 , V_78 , V_28 ) ;
return 0 ;
}
int F_67 ( struct V_1 * V_2 , struct V_27 * V_28 ,
struct V_27 * V_59 )
{
return F_53 ( V_2 , V_28 , V_59 ) ;
}
bool F_68 ( struct V_27 * V_28 , struct V_3 * V_3 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
if ( ! F_54 ( V_28 ) || ! F_69 ( V_3 ) )
return false ;
if ( ! F_55 ( V_28 -> V_48 , V_3 -> V_17 ) )
return false ;
if ( F_70 ( V_3 ) != F_50 ( V_28 ) )
return false ;
if ( V_28 -> V_74 != V_3 -> V_79 -> V_80 || F_39 ( V_28 ) )
return false ;
if ( F_31 ( V_3 ) != F_41 ( V_28 ) )
return false ;
if ( V_28 -> V_48 & V_19 &&
! F_57 ( V_28 -> V_3 , V_3 ) )
return false ;
if ( V_2 -> V_21 & ( 1 << V_81 ) ) {
struct V_4 * V_82 ;
V_82 = & V_28 -> V_64 -> V_83 [ V_3 -> V_31 - 1 ] ;
if ( F_71 ( V_82 , V_3 -> V_83 [ 0 ] . V_46 ) )
return false ;
}
return true ;
}
int F_72 ( struct V_27 * V_28 , struct V_3 * V_3 )
{
if ( F_56 ( V_28 ) + F_34 ( V_28 ) == V_3 -> V_84 . V_85 )
return V_86 ;
else if ( F_56 ( V_28 ) - F_35 ( V_3 ) == V_3 -> V_84 . V_85 )
return V_87 ;
return V_88 ;
}
