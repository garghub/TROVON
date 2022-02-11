static unsigned int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_4 * V_5 , * V_6 = NULL ;
int V_7 , V_8 , V_9 , V_10 = 1 ;
unsigned int V_11 , V_12 ;
struct V_3 * V_13 , * V_14 ;
if ( ! V_3 )
return 0 ;
V_13 = V_3 ;
V_7 = F_2 ( V_2 ) ;
V_11 = 0 ;
V_12 = 0 ;
F_3 (bio) {
F_4 (bv, bio, i) {
V_9 = F_5 ( V_5 -> V_15 ) > F_6 ( V_2 ) ;
if ( V_9 || V_10 )
goto V_16;
if ( V_7 ) {
if ( V_11 + V_5 -> V_17
> F_7 ( V_2 ) )
goto V_16;
if ( ! F_8 ( V_6 , V_5 ) )
goto V_16;
if ( ! F_9 ( V_2 , V_6 , V_5 ) )
goto V_16;
V_11 += V_5 -> V_17 ;
V_6 = V_5 ;
continue;
}
V_16:
if ( V_12 == 1 && V_11 >
V_13 -> V_18 )
V_13 -> V_18 = V_11 ;
V_12 ++ ;
V_6 = V_5 ;
V_11 = V_5 -> V_17 ;
V_10 = V_9 ;
}
V_14 = V_3 ;
}
if ( V_12 == 1 && V_11 > V_13 -> V_18 )
V_13 -> V_18 = V_11 ;
if ( V_11 > V_14 -> V_19 )
V_14 -> V_19 = V_11 ;
return V_12 ;
}
void F_10 ( struct V_20 * V_21 )
{
V_21 -> V_22 = F_1 ( V_21 -> V_2 , V_21 -> V_3 ) ;
}
void F_11 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_3 * V_23 = V_3 -> V_24 ;
V_3 -> V_24 = NULL ;
V_3 -> V_25 = F_1 ( V_2 , V_3 ) ;
V_3 -> V_24 = V_23 ;
V_3 -> V_26 |= ( 1 << V_27 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_3 * V_23 )
{
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( V_3 -> V_19 + V_23 -> V_18 >
F_7 ( V_2 ) )
return 0 ;
if ( ! F_13 ( V_3 ) )
return 1 ;
if ( ! F_8 ( F_14 ( V_3 ) , F_15 ( V_23 ) ) )
return 0 ;
if ( F_16 ( V_2 , V_3 , V_23 ) )
return 1 ;
return 0 ;
}
static void
F_17 ( struct V_1 * V_2 , struct V_4 * V_28 ,
struct V_29 * V_30 , struct V_4 * * V_6 ,
struct V_29 * * V_31 , int * V_32 , int * V_7 )
{
int V_33 = V_28 -> V_17 ;
if ( * V_6 && * V_7 ) {
if ( ( * V_31 ) -> V_34 + V_33 > F_7 ( V_2 ) )
goto V_16;
if ( ! F_8 ( * V_6 , V_28 ) )
goto V_16;
if ( ! F_9 ( V_2 , * V_6 , V_28 ) )
goto V_16;
( * V_31 ) -> V_34 += V_33 ;
} else {
V_16:
if ( ! * V_31 )
* V_31 = V_30 ;
else {
F_18 ( * V_31 ) ;
* V_31 = F_19 ( * V_31 ) ;
}
F_20 ( * V_31 , V_28 -> V_15 , V_33 , V_28 -> V_35 ) ;
( * V_32 ) ++ ;
}
* V_6 = V_28 ;
}
int F_21 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_29 * V_30 )
{
struct V_4 * V_28 , * V_6 ;
struct V_36 V_37 ;
struct V_29 * V_31 ;
int V_32 , V_7 ;
V_32 = 0 ;
V_7 = F_2 ( V_2 ) ;
V_6 = NULL ;
V_31 = NULL ;
F_22 (bvec, rq, iter) {
F_17 ( V_2 , V_28 , V_30 , & V_6 , & V_31 ,
& V_32 , & V_7 ) ;
}
if ( F_23 ( V_21 -> V_38 & V_39 ) &&
( F_24 ( V_21 ) & V_2 -> V_40 ) ) {
unsigned int V_41 =
( V_2 -> V_40 & ~ F_24 ( V_21 ) ) + 1 ;
V_31 -> V_34 += V_41 ;
V_21 -> V_42 += V_41 ;
}
if ( V_2 -> V_43 && V_2 -> V_44 ( V_21 ) ) {
if ( V_21 -> V_38 & V_45 )
memset ( V_2 -> V_46 , 0 , V_2 -> V_43 ) ;
V_31 -> V_47 &= ~ 0x02 ;
V_31 = F_19 ( V_31 ) ;
F_20 ( V_31 , F_25 ( V_2 -> V_46 ) ,
V_2 -> V_43 ,
( ( unsigned long ) V_2 -> V_46 ) &
( V_48 - 1 ) ) ;
V_32 ++ ;
V_21 -> V_42 += V_2 -> V_43 ;
}
if ( V_31 )
F_26 ( V_31 ) ;
return V_32 ;
}
int F_27 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_29 * V_30 )
{
struct V_4 * V_28 , * V_6 ;
struct V_29 * V_31 ;
int V_32 , V_7 ;
unsigned long V_8 ;
V_32 = 0 ;
V_7 = F_2 ( V_2 ) ;
V_6 = NULL ;
V_31 = NULL ;
F_4 (bvec, bio, i) {
F_17 ( V_2 , V_28 , V_30 , & V_6 , & V_31 ,
& V_32 , & V_7 ) ;
}
if ( V_31 )
F_26 ( V_31 ) ;
F_28 ( V_3 -> V_25 && V_32 > V_3 -> V_25 ) ;
return V_32 ;
}
static inline int F_29 ( struct V_1 * V_2 ,
struct V_20 * V_49 ,
struct V_3 * V_3 )
{
int V_12 = F_30 ( V_2 , V_3 ) ;
if ( V_49 -> V_22 + V_12 > F_31 ( V_2 ) )
goto V_50;
if ( F_32 ( V_3 ) && F_33 ( V_2 , V_49 , V_3 ) )
goto V_50;
V_49 -> V_22 += V_12 ;
return 1 ;
V_50:
V_49 -> V_38 |= V_51 ;
if ( V_49 == V_2 -> V_52 )
V_2 -> V_52 = NULL ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 , struct V_20 * V_49 ,
struct V_3 * V_3 )
{
if ( F_35 ( V_49 ) + F_36 ( V_3 ) >
F_37 ( V_49 ) ) {
V_49 -> V_38 |= V_51 ;
if ( V_49 == V_2 -> V_52 )
V_2 -> V_52 = NULL ;
return 0 ;
}
if ( ! F_38 ( V_49 -> V_53 , V_27 ) )
F_11 ( V_2 , V_49 -> V_53 ) ;
if ( ! F_38 ( V_3 , V_27 ) )
F_11 ( V_2 , V_3 ) ;
return F_29 ( V_2 , V_49 , V_3 ) ;
}
int F_39 ( struct V_1 * V_2 , struct V_20 * V_49 ,
struct V_3 * V_3 )
{
if ( F_35 ( V_49 ) + F_36 ( V_3 ) >
F_37 ( V_49 ) ) {
V_49 -> V_38 |= V_51 ;
if ( V_49 == V_2 -> V_52 )
V_2 -> V_52 = NULL ;
return 0 ;
}
if ( ! F_38 ( V_3 , V_27 ) )
F_11 ( V_2 , V_3 ) ;
if ( ! F_38 ( V_49 -> V_3 , V_27 ) )
F_11 ( V_2 , V_49 -> V_3 ) ;
return F_29 ( V_2 , V_49 , V_3 ) ;
}
static int F_40 ( struct V_1 * V_2 , struct V_20 * V_49 ,
struct V_20 * V_54 )
{
int V_55 ;
unsigned int V_11 =
V_49 -> V_53 -> V_19 + V_54 -> V_3 -> V_18 ;
if ( V_49 -> V_56 || V_54 -> V_56 )
return 0 ;
if ( ( F_35 ( V_49 ) + F_35 ( V_54 ) ) >
F_37 ( V_49 ) )
return 0 ;
V_55 = V_49 -> V_22 + V_54 -> V_22 ;
if ( F_12 ( V_2 , V_49 -> V_53 , V_54 -> V_3 ) ) {
if ( V_49 -> V_22 == 1 )
V_49 -> V_3 -> V_18 = V_11 ;
if ( V_54 -> V_22 == 1 )
V_54 -> V_53 -> V_19 = V_11 ;
V_55 -- ;
}
if ( V_55 > F_31 ( V_2 ) )
return 0 ;
if ( F_41 ( V_49 ) && F_42 ( V_2 , V_49 , V_54 ) )
return 0 ;
V_49 -> V_22 = V_55 ;
return 1 ;
}
void F_43 ( struct V_20 * V_21 )
{
unsigned int V_57 = V_21 -> V_38 & V_58 ;
struct V_3 * V_3 ;
if ( V_21 -> V_38 & V_59 )
return;
for ( V_3 = V_21 -> V_3 ; V_3 ; V_3 = V_3 -> V_24 ) {
F_44 ( ( V_3 -> V_60 & V_58 ) &&
( V_3 -> V_60 & V_58 ) != V_57 ) ;
V_3 -> V_60 |= V_57 ;
}
V_21 -> V_38 |= V_59 ;
}
static void F_45 ( struct V_20 * V_49 )
{
if ( F_46 ( V_49 ) ) {
struct V_61 * V_62 ;
int V_63 ;
V_63 = F_47 () ;
V_62 = V_49 -> V_62 ;
F_48 ( V_63 , V_62 ) ;
F_49 ( V_62 , F_50 ( V_49 ) ) ;
F_51 ( V_62 ) ;
F_52 () ;
}
}
static int F_53 ( struct V_1 * V_2 , struct V_20 * V_49 ,
struct V_20 * V_54 )
{
if ( ! F_54 ( V_49 ) || ! F_54 ( V_54 ) )
return 0 ;
if ( ! F_55 ( V_49 -> V_38 , V_54 -> V_38 ) )
return 0 ;
if ( F_56 ( V_49 ) + F_35 ( V_49 ) != F_56 ( V_54 ) )
return 0 ;
if ( F_50 ( V_49 ) != F_50 ( V_54 )
|| V_49 -> V_64 != V_54 -> V_64
|| V_54 -> V_56 )
return 0 ;
if ( V_49 -> V_38 & V_65 &&
! F_57 ( V_49 -> V_3 , V_54 -> V_3 ) )
return 0 ;
if ( ! F_40 ( V_2 , V_49 , V_54 ) )
return 0 ;
if ( ( V_49 -> V_38 | V_54 -> V_38 ) & V_59 ||
( V_49 -> V_38 & V_58 ) !=
( V_54 -> V_38 & V_58 ) ) {
F_43 ( V_49 ) ;
F_43 ( V_54 ) ;
}
if ( F_58 ( V_49 -> V_66 , V_54 -> V_66 ) )
V_49 -> V_66 = V_54 -> V_66 ;
V_49 -> V_53 -> V_24 = V_54 -> V_3 ;
V_49 -> V_53 = V_54 -> V_53 ;
V_49 -> V_67 += F_24 ( V_54 ) ;
F_59 ( V_2 , V_49 , V_54 ) ;
F_45 ( V_54 ) ;
V_49 -> V_68 = F_60 ( V_49 -> V_68 , V_54 -> V_68 ) ;
if ( F_61 ( V_54 ) )
V_49 -> V_63 = V_54 -> V_63 ;
V_54 -> V_3 = NULL ;
F_62 ( V_2 , V_54 ) ;
return 1 ;
}
int F_63 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_20 * V_54 = F_64 ( V_2 , V_21 ) ;
if ( V_54 )
return F_53 ( V_2 , V_21 , V_54 ) ;
return 0 ;
}
int F_65 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_20 * V_69 = F_66 ( V_2 , V_21 ) ;
if ( V_69 )
return F_53 ( V_2 , V_69 , V_21 ) ;
return 0 ;
}
int F_67 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_20 * V_54 )
{
return F_53 ( V_2 , V_21 , V_54 ) ;
}
bool F_68 ( struct V_20 * V_21 , struct V_3 * V_3 )
{
if ( ! F_54 ( V_21 ) || ! F_69 ( V_3 ) )
return false ;
if ( ! F_55 ( V_21 -> V_38 , V_3 -> V_60 ) )
return false ;
if ( F_70 ( V_3 ) != F_50 ( V_21 ) )
return false ;
if ( V_21 -> V_64 != V_3 -> V_70 -> V_71 || V_21 -> V_56 )
return false ;
if ( F_32 ( V_3 ) != F_41 ( V_21 ) )
return false ;
if ( V_21 -> V_38 & V_65 &&
! F_57 ( V_21 -> V_3 , V_3 ) )
return false ;
return true ;
}
int F_71 ( struct V_20 * V_21 , struct V_3 * V_3 )
{
if ( F_56 ( V_21 ) + F_35 ( V_21 ) == V_3 -> V_72 )
return V_73 ;
else if ( F_56 ( V_21 ) - F_36 ( V_3 ) == V_3 -> V_72 )
return V_74 ;
return V_75 ;
}
