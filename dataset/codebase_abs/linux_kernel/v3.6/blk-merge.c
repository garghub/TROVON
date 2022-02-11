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
( * V_31 ) -> V_35 &= ~ 0x02 ;
* V_31 = F_18 ( * V_31 ) ;
}
F_19 ( * V_31 , V_28 -> V_15 , V_33 , V_28 -> V_36 ) ;
( * V_32 ) ++ ;
}
* V_6 = V_28 ;
}
int F_20 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_29 * V_30 )
{
struct V_4 * V_28 , * V_6 ;
struct V_37 V_38 ;
struct V_29 * V_31 ;
int V_32 , V_7 ;
V_32 = 0 ;
V_7 = F_2 ( V_2 ) ;
V_6 = NULL ;
V_31 = NULL ;
F_21 (bvec, rq, iter) {
F_17 ( V_2 , V_28 , V_30 , & V_6 , & V_31 ,
& V_32 , & V_7 ) ;
}
if ( F_22 ( V_21 -> V_39 & V_40 ) &&
( F_23 ( V_21 ) & V_2 -> V_41 ) ) {
unsigned int V_42 =
( V_2 -> V_41 & ~ F_23 ( V_21 ) ) + 1 ;
V_31 -> V_34 += V_42 ;
V_21 -> V_43 += V_42 ;
}
if ( V_2 -> V_44 && V_2 -> V_45 ( V_21 ) ) {
if ( V_21 -> V_39 & V_46 )
memset ( V_2 -> V_47 , 0 , V_2 -> V_44 ) ;
V_31 -> V_35 &= ~ 0x02 ;
V_31 = F_18 ( V_31 ) ;
F_19 ( V_31 , F_24 ( V_2 -> V_47 ) ,
V_2 -> V_44 ,
( ( unsigned long ) V_2 -> V_47 ) &
( V_48 - 1 ) ) ;
V_32 ++ ;
V_21 -> V_43 += V_2 -> V_44 ;
}
if ( V_31 )
F_25 ( V_31 ) ;
return V_32 ;
}
int F_26 ( struct V_1 * V_2 , struct V_3 * V_3 ,
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
F_25 ( V_31 ) ;
F_27 ( V_3 -> V_25 && V_32 > V_3 -> V_25 ) ;
return V_32 ;
}
static inline int F_28 ( struct V_1 * V_2 ,
struct V_20 * V_49 ,
struct V_3 * V_3 )
{
int V_12 = F_29 ( V_2 , V_3 ) ;
if ( V_49 -> V_22 + V_12 > F_30 ( V_2 ) )
goto V_50;
if ( F_31 ( V_3 ) && F_32 ( V_2 , V_49 , V_3 ) )
goto V_50;
V_49 -> V_22 += V_12 ;
return 1 ;
V_50:
V_49 -> V_39 |= V_51 ;
if ( V_49 == V_2 -> V_52 )
V_2 -> V_52 = NULL ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 , struct V_20 * V_49 ,
struct V_3 * V_3 )
{
unsigned short V_53 ;
if ( F_22 ( V_49 -> V_54 == V_55 ) )
V_53 = F_34 ( V_2 ) ;
else
V_53 = F_35 ( V_2 ) ;
if ( F_36 ( V_49 ) + F_37 ( V_3 ) > V_53 ) {
V_49 -> V_39 |= V_51 ;
if ( V_49 == V_2 -> V_52 )
V_2 -> V_52 = NULL ;
return 0 ;
}
if ( ! F_38 ( V_49 -> V_56 , V_27 ) )
F_11 ( V_2 , V_49 -> V_56 ) ;
if ( ! F_38 ( V_3 , V_27 ) )
F_11 ( V_2 , V_3 ) ;
return F_28 ( V_2 , V_49 , V_3 ) ;
}
int F_39 ( struct V_1 * V_2 , struct V_20 * V_49 ,
struct V_3 * V_3 )
{
unsigned short V_53 ;
if ( F_22 ( V_49 -> V_54 == V_55 ) )
V_53 = F_34 ( V_2 ) ;
else
V_53 = F_35 ( V_2 ) ;
if ( F_36 ( V_49 ) + F_37 ( V_3 ) > V_53 ) {
V_49 -> V_39 |= V_51 ;
if ( V_49 == V_2 -> V_52 )
V_2 -> V_52 = NULL ;
return 0 ;
}
if ( ! F_38 ( V_3 , V_27 ) )
F_11 ( V_2 , V_3 ) ;
if ( ! F_38 ( V_49 -> V_3 , V_27 ) )
F_11 ( V_2 , V_49 -> V_3 ) ;
return F_28 ( V_2 , V_49 , V_3 ) ;
}
static int F_40 ( struct V_1 * V_2 , struct V_20 * V_49 ,
struct V_20 * V_57 )
{
int V_58 ;
unsigned int V_11 =
V_49 -> V_56 -> V_19 + V_57 -> V_3 -> V_18 ;
if ( V_49 -> V_59 || V_57 -> V_59 )
return 0 ;
if ( ( F_36 ( V_49 ) + F_36 ( V_57 ) ) > F_35 ( V_2 ) )
return 0 ;
V_58 = V_49 -> V_22 + V_57 -> V_22 ;
if ( F_12 ( V_2 , V_49 -> V_56 , V_57 -> V_3 ) ) {
if ( V_49 -> V_22 == 1 )
V_49 -> V_3 -> V_18 = V_11 ;
if ( V_57 -> V_22 == 1 )
V_57 -> V_56 -> V_19 = V_11 ;
V_58 -- ;
}
if ( V_58 > F_30 ( V_2 ) )
return 0 ;
if ( F_41 ( V_49 ) && F_42 ( V_2 , V_49 , V_57 ) )
return 0 ;
V_49 -> V_22 = V_58 ;
return 1 ;
}
void F_43 ( struct V_20 * V_21 )
{
unsigned int V_60 = V_21 -> V_39 & V_61 ;
struct V_3 * V_3 ;
if ( V_21 -> V_39 & V_62 )
return;
for ( V_3 = V_21 -> V_3 ; V_3 ; V_3 = V_3 -> V_24 ) {
F_44 ( ( V_3 -> V_63 & V_61 ) &&
( V_3 -> V_63 & V_61 ) != V_60 ) ;
V_3 -> V_63 |= V_60 ;
}
V_21 -> V_39 |= V_62 ;
}
static void F_45 ( struct V_20 * V_49 )
{
if ( F_46 ( V_49 ) ) {
struct V_64 * V_65 ;
int V_66 ;
V_66 = F_47 () ;
V_65 = V_49 -> V_65 ;
F_48 ( V_66 , V_65 ) ;
F_49 ( V_65 , F_50 ( V_49 ) ) ;
F_51 ( V_65 ) ;
F_52 () ;
}
}
static int F_53 ( struct V_1 * V_2 , struct V_20 * V_49 ,
struct V_20 * V_57 )
{
if ( ! F_54 ( V_49 ) || ! F_54 ( V_57 ) )
return 0 ;
if ( ( V_49 -> V_39 & V_67 ) != ( V_57 -> V_39 & V_67 ) )
return 0 ;
if ( ( V_49 -> V_39 & V_68 ) != ( V_57 -> V_39 & V_68 ) )
return 0 ;
if ( F_55 ( V_49 ) + F_36 ( V_49 ) != F_55 ( V_57 ) )
return 0 ;
if ( F_50 ( V_49 ) != F_50 ( V_57 )
|| V_49 -> V_69 != V_57 -> V_69
|| V_57 -> V_59 )
return 0 ;
if ( ! F_40 ( V_2 , V_49 , V_57 ) )
return 0 ;
if ( ( V_49 -> V_39 | V_57 -> V_39 ) & V_62 ||
( V_49 -> V_39 & V_61 ) !=
( V_57 -> V_39 & V_61 ) ) {
F_43 ( V_49 ) ;
F_43 ( V_57 ) ;
}
if ( F_56 ( V_49 -> V_70 , V_57 -> V_70 ) )
V_49 -> V_70 = V_57 -> V_70 ;
V_49 -> V_56 -> V_24 = V_57 -> V_3 ;
V_49 -> V_56 = V_57 -> V_56 ;
V_49 -> V_71 += F_23 ( V_57 ) ;
F_57 ( V_2 , V_49 , V_57 ) ;
F_45 ( V_57 ) ;
V_49 -> V_72 = F_58 ( V_49 -> V_72 , V_57 -> V_72 ) ;
if ( F_59 ( V_57 ) )
V_49 -> V_66 = V_57 -> V_66 ;
V_57 -> V_3 = NULL ;
F_60 ( V_2 , V_57 ) ;
return 1 ;
}
int F_61 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_20 * V_57 = F_62 ( V_2 , V_21 ) ;
if ( V_57 )
return F_53 ( V_2 , V_21 , V_57 ) ;
return 0 ;
}
int F_63 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_20 * V_73 = F_64 ( V_2 , V_21 ) ;
if ( V_73 )
return F_53 ( V_2 , V_73 , V_21 ) ;
return 0 ;
}
int F_65 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_20 * V_57 )
{
return F_53 ( V_2 , V_21 , V_57 ) ;
}
bool F_66 ( struct V_20 * V_21 , struct V_3 * V_3 )
{
if ( ! F_54 ( V_21 ) )
return false ;
if ( ( V_3 -> V_63 & V_67 ) != ( V_21 -> V_3 -> V_63 & V_67 ) )
return false ;
if ( ( V_3 -> V_63 & V_68 ) != ( V_21 -> V_3 -> V_63 & V_68 ) )
return false ;
if ( F_67 ( V_3 ) != F_50 ( V_21 ) )
return false ;
if ( V_21 -> V_69 != V_3 -> V_74 -> V_75 || V_21 -> V_59 )
return false ;
if ( F_31 ( V_3 ) != F_41 ( V_21 ) )
return false ;
return true ;
}
int F_68 ( struct V_20 * V_21 , struct V_3 * V_3 )
{
if ( F_55 ( V_21 ) + F_36 ( V_21 ) == V_3 -> V_76 )
return V_77 ;
else if ( F_55 ( V_21 ) - F_37 ( V_3 ) == V_3 -> V_76 )
return V_78 ;
return V_79 ;
}
