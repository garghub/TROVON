static unsigned int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
bool V_4 )
{
struct V_5 V_6 , V_7 = { NULL } ;
int V_8 , V_9 , V_10 = 1 ;
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
V_8 = F_2 ( V_2 ) ;
V_11 = 0 ;
V_12 = 0 ;
V_9 = 0 ;
F_3 (bio) {
F_4 (bv, bio, iter) {
if ( V_4 )
goto V_20;
V_9 = F_5 ( V_6 . V_21 ) > F_6 ( V_2 ) ;
if ( ! V_9 && ! V_10 && V_8 ) {
if ( V_11 + V_6 . V_22
> F_7 ( V_2 ) )
goto V_20;
if ( ! F_8 ( & V_7 , & V_6 ) )
goto V_20;
if ( ! F_9 ( V_2 , & V_7 , & V_6 ) )
goto V_20;
V_11 += V_6 . V_22 ;
V_7 = V_6 ;
continue;
}
V_20:
if ( V_12 == 1 && V_11 >
V_13 -> V_23 )
V_13 -> V_23 = V_11 ;
V_12 ++ ;
V_7 = V_6 ;
V_11 = V_6 . V_22 ;
V_10 = V_9 ;
}
V_14 = V_3 ;
}
if ( V_12 == 1 && V_11 > V_13 -> V_23 )
V_13 -> V_23 = V_11 ;
if ( V_11 > V_14 -> V_24 )
V_14 -> V_24 = V_11 ;
return V_12 ;
}
void F_10 ( struct V_25 * V_26 )
{
bool V_4 = ! ! F_11 ( V_27 ,
& V_26 -> V_2 -> V_28 ) ;
V_26 -> V_29 = F_1 ( V_26 -> V_2 , V_26 -> V_3 ,
V_4 ) ;
}
void F_12 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
unsigned short V_30 ;
if ( F_13 ( V_3 , V_31 ) )
V_30 = F_14 ( V_3 ) ;
else
V_30 = V_3 -> V_32 ;
if ( F_11 ( V_27 , & V_2 -> V_28 ) &&
( V_30 < F_15 ( V_2 ) ) )
V_3 -> V_33 = V_30 ;
else {
struct V_3 * V_34 = V_3 -> V_35 ;
V_3 -> V_35 = NULL ;
V_3 -> V_33 = F_1 ( V_2 , V_3 , false ) ;
V_3 -> V_35 = V_34 ;
}
V_3 -> V_36 |= ( 1 << V_37 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_3 * V_34 )
{
struct V_5 V_38 = { NULL } , V_39 ;
struct V_15 V_16 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( V_3 -> V_24 + V_34 -> V_23 >
F_7 ( V_2 ) )
return 0 ;
if ( ! F_17 ( V_3 ) )
return 1 ;
F_4 (end_bv, bio, iter)
if ( V_38 . V_22 == V_16 . V_40 )
break;
V_39 = F_18 ( V_34 ) ;
if ( ! F_8 ( & V_38 , & V_39 ) )
return 0 ;
if ( F_9 ( V_2 , & V_38 , & V_39 ) )
return 1 ;
return 0 ;
}
static inline void
F_19 ( struct V_1 * V_2 , struct V_5 * V_41 ,
struct V_42 * V_43 , struct V_5 * V_7 ,
struct V_42 * * V_44 , int * V_45 , int * V_8 )
{
int V_46 = V_41 -> V_22 ;
if ( * V_44 && * V_8 ) {
if ( ( * V_44 ) -> V_47 + V_46 > F_7 ( V_2 ) )
goto V_20;
if ( ! F_8 ( V_7 , V_41 ) )
goto V_20;
if ( ! F_9 ( V_2 , V_7 , V_41 ) )
goto V_20;
( * V_44 ) -> V_47 += V_46 ;
} else {
V_20:
if ( ! * V_44 )
* V_44 = V_43 ;
else {
F_20 ( * V_44 ) ;
* V_44 = F_21 ( * V_44 ) ;
}
F_22 ( * V_44 , V_41 -> V_21 , V_46 , V_41 -> V_48 ) ;
( * V_45 ) ++ ;
}
* V_7 = * V_41 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_42 * V_43 ,
struct V_42 * * V_44 )
{
struct V_5 V_41 , V_7 = { NULL } ;
struct V_15 V_16 ;
int V_45 , V_8 ;
V_45 = 0 ;
V_8 = F_2 ( V_2 ) ;
if ( V_3 -> V_17 & V_18 ) {
if ( V_3 -> V_32 )
goto V_49;
return 0 ;
}
if ( V_3 -> V_17 & V_19 ) {
V_49:
* V_44 = V_43 ;
V_41 = F_18 ( V_3 ) ;
F_22 ( * V_44 , V_41 . V_21 , V_41 . V_22 , V_41 . V_48 ) ;
return 1 ;
}
F_3 (bio)
F_4 (bvec, bio, iter)
F_19 ( V_2 , & V_41 , V_43 , & V_7 , V_44 ,
& V_45 , & V_8 ) ;
return V_45 ;
}
int F_24 ( struct V_1 * V_2 , struct V_25 * V_26 ,
struct V_42 * V_43 )
{
struct V_42 * V_44 = NULL ;
int V_45 = 0 ;
if ( V_26 -> V_3 )
V_45 = F_23 ( V_2 , V_26 -> V_3 , V_43 , & V_44 ) ;
if ( F_25 ( V_26 -> V_50 & V_51 ) &&
( F_26 ( V_26 ) & V_2 -> V_52 ) ) {
unsigned int V_53 =
( V_2 -> V_52 & ~ F_26 ( V_26 ) ) + 1 ;
V_44 -> V_47 += V_53 ;
V_26 -> V_54 += V_53 ;
}
if ( V_2 -> V_55 && V_2 -> V_56 ( V_26 ) ) {
if ( V_26 -> V_50 & V_57 )
memset ( V_2 -> V_58 , 0 , V_2 -> V_55 ) ;
V_44 -> V_59 &= ~ 0x02 ;
V_44 = F_21 ( V_44 ) ;
F_22 ( V_44 , F_27 ( V_2 -> V_58 ) ,
V_2 -> V_55 ,
( ( unsigned long ) V_2 -> V_58 ) &
( V_60 - 1 ) ) ;
V_45 ++ ;
V_26 -> V_54 += V_2 -> V_55 ;
}
if ( V_44 )
F_28 ( V_44 ) ;
return V_45 ;
}
static inline int F_29 ( struct V_1 * V_2 ,
struct V_25 * V_61 ,
struct V_3 * V_3 )
{
int V_12 = F_30 ( V_2 , V_3 ) ;
if ( V_61 -> V_29 + V_12 > F_15 ( V_2 ) )
goto V_62;
if ( F_31 ( V_2 , V_61 , V_3 ) == false )
goto V_62;
V_61 -> V_29 += V_12 ;
return 1 ;
V_62:
V_61 -> V_50 |= V_63 ;
if ( V_61 == V_2 -> V_64 )
V_2 -> V_64 = NULL ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , struct V_25 * V_61 ,
struct V_3 * V_3 )
{
if ( F_33 ( V_61 ) + F_34 ( V_3 ) >
F_35 ( V_61 ) ) {
V_61 -> V_50 |= V_63 ;
if ( V_61 == V_2 -> V_64 )
V_2 -> V_64 = NULL ;
return 0 ;
}
if ( ! F_13 ( V_61 -> V_65 , V_37 ) )
F_12 ( V_2 , V_61 -> V_65 ) ;
if ( ! F_13 ( V_3 , V_37 ) )
F_12 ( V_2 , V_3 ) ;
return F_29 ( V_2 , V_61 , V_3 ) ;
}
int F_36 ( struct V_1 * V_2 , struct V_25 * V_61 ,
struct V_3 * V_3 )
{
if ( F_33 ( V_61 ) + F_34 ( V_3 ) >
F_35 ( V_61 ) ) {
V_61 -> V_50 |= V_63 ;
if ( V_61 == V_2 -> V_64 )
V_2 -> V_64 = NULL ;
return 0 ;
}
if ( ! F_13 ( V_3 , V_37 ) )
F_12 ( V_2 , V_3 ) ;
if ( ! F_13 ( V_61 -> V_3 , V_37 ) )
F_12 ( V_2 , V_61 -> V_3 ) ;
return F_29 ( V_2 , V_61 , V_3 ) ;
}
static bool F_37 ( struct V_25 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_2 ;
return ! V_2 -> V_66 && V_61 -> V_67 ;
}
static int F_38 ( struct V_25 * V_61 , struct V_25 * V_68 )
{
struct V_3 * V_69 = V_61 -> V_65 ;
return F_39 ( & V_69 -> V_70 [ V_69 -> V_32 - 1 ] ,
V_68 -> V_3 -> V_70 [ 0 ] . V_48 ) ;
}
static int F_40 ( struct V_1 * V_2 , struct V_25 * V_61 ,
struct V_25 * V_68 )
{
int V_71 ;
unsigned int V_11 =
V_61 -> V_65 -> V_24 + V_68 -> V_3 -> V_23 ;
if ( F_37 ( V_61 ) || F_37 ( V_68 ) )
return 0 ;
if ( F_11 ( V_72 , & V_2 -> V_28 ) &&
F_38 ( V_61 , V_68 ) )
return 0 ;
if ( ( F_33 ( V_61 ) + F_33 ( V_68 ) ) >
F_35 ( V_61 ) )
return 0 ;
V_71 = V_61 -> V_29 + V_68 -> V_29 ;
if ( F_16 ( V_2 , V_61 -> V_65 , V_68 -> V_3 ) ) {
if ( V_61 -> V_29 == 1 )
V_61 -> V_3 -> V_23 = V_11 ;
if ( V_68 -> V_29 == 1 )
V_68 -> V_65 -> V_24 = V_11 ;
V_71 -- ;
}
if ( V_71 > F_15 ( V_2 ) )
return 0 ;
if ( F_41 ( V_2 , V_61 , V_68 ) == false )
return 0 ;
V_61 -> V_29 = V_71 ;
return 1 ;
}
void F_42 ( struct V_25 * V_26 )
{
unsigned int V_73 = V_26 -> V_50 & V_74 ;
struct V_3 * V_3 ;
if ( V_26 -> V_50 & V_75 )
return;
for ( V_3 = V_26 -> V_3 ; V_3 ; V_3 = V_3 -> V_35 ) {
F_43 ( ( V_3 -> V_17 & V_74 ) &&
( V_3 -> V_17 & V_74 ) != V_73 ) ;
V_3 -> V_17 |= V_73 ;
}
V_26 -> V_50 |= V_75 ;
}
static void F_44 ( struct V_25 * V_61 )
{
if ( F_45 ( V_61 ) ) {
struct V_76 * V_77 ;
int V_78 ;
V_78 = F_46 () ;
V_77 = V_61 -> V_77 ;
F_47 ( V_78 , V_77 ) ;
F_48 ( V_77 , F_49 ( V_61 ) ) ;
F_50 ( V_77 ) ;
F_51 () ;
}
}
static int F_52 ( struct V_1 * V_2 , struct V_25 * V_61 ,
struct V_25 * V_68 )
{
if ( ! F_53 ( V_61 ) || ! F_53 ( V_68 ) )
return 0 ;
if ( ! F_54 ( V_61 -> V_50 , V_68 -> V_50 ) )
return 0 ;
if ( F_55 ( V_61 ) + F_33 ( V_61 ) != F_55 ( V_68 ) )
return 0 ;
if ( F_49 ( V_61 ) != F_49 ( V_68 )
|| V_61 -> V_79 != V_68 -> V_79
|| F_37 ( V_68 ) )
return 0 ;
if ( V_61 -> V_50 & V_19 &&
! F_56 ( V_61 -> V_3 , V_68 -> V_3 ) )
return 0 ;
if ( ! F_40 ( V_2 , V_61 , V_68 ) )
return 0 ;
if ( ( V_61 -> V_50 | V_68 -> V_50 ) & V_75 ||
( V_61 -> V_50 & V_74 ) !=
( V_68 -> V_50 & V_74 ) ) {
F_42 ( V_61 ) ;
F_42 ( V_68 ) ;
}
if ( F_57 ( V_61 -> V_80 , V_68 -> V_80 ) )
V_61 -> V_80 = V_68 -> V_80 ;
V_61 -> V_65 -> V_35 = V_68 -> V_3 ;
V_61 -> V_65 = V_68 -> V_65 ;
V_61 -> V_81 += F_26 ( V_68 ) ;
F_58 ( V_2 , V_61 , V_68 ) ;
F_44 ( V_68 ) ;
V_61 -> V_82 = F_59 ( V_61 -> V_82 , V_68 -> V_82 ) ;
if ( F_60 ( V_68 ) )
V_61 -> V_78 = V_68 -> V_78 ;
V_68 -> V_3 = NULL ;
F_61 ( V_2 , V_68 ) ;
return 1 ;
}
int F_62 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_25 * V_68 = F_63 ( V_2 , V_26 ) ;
if ( V_68 )
return F_52 ( V_2 , V_26 , V_68 ) ;
return 0 ;
}
int F_64 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_25 * V_69 = F_65 ( V_2 , V_26 ) ;
if ( V_69 )
return F_52 ( V_2 , V_69 , V_26 ) ;
return 0 ;
}
int F_66 ( struct V_1 * V_2 , struct V_25 * V_26 ,
struct V_25 * V_68 )
{
return F_52 ( V_2 , V_26 , V_68 ) ;
}
bool F_67 ( struct V_25 * V_26 , struct V_3 * V_3 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
if ( ! F_53 ( V_26 ) || ! F_68 ( V_3 ) )
return false ;
if ( ! F_54 ( V_26 -> V_50 , V_3 -> V_17 ) )
return false ;
if ( F_69 ( V_3 ) != F_49 ( V_26 ) )
return false ;
if ( V_26 -> V_79 != V_3 -> V_83 -> V_84 || F_37 ( V_26 ) )
return false ;
if ( F_31 ( V_26 -> V_2 , V_26 , V_3 ) == false )
return false ;
if ( V_26 -> V_50 & V_19 &&
! F_56 ( V_26 -> V_3 , V_3 ) )
return false ;
if ( V_2 -> V_28 & ( 1 << V_72 ) ) {
struct V_5 * V_85 ;
V_85 = & V_26 -> V_65 -> V_70 [ V_26 -> V_65 -> V_32 - 1 ] ;
if ( F_39 ( V_85 , V_3 -> V_70 [ 0 ] . V_48 ) )
return false ;
}
return true ;
}
int F_70 ( struct V_25 * V_26 , struct V_3 * V_3 )
{
if ( F_55 ( V_26 ) + F_33 ( V_26 ) == V_3 -> V_86 . V_87 )
return V_88 ;
else if ( F_55 ( V_26 ) - F_34 ( V_3 ) == V_3 -> V_86 . V_87 )
return V_89 ;
return V_90 ;
}
