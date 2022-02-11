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
unsigned V_35 = 0 ;
F_13 (bv, bio, iter) {
if ( V_35 ++ >= V_36 )
goto V_37;
if ( V_26 && F_14 ( V_3 , V_26 , V_24 . V_38 ) )
goto V_37;
if ( V_20 + ( V_24 . V_39 >> 9 ) > V_34 ) {
if ( V_6 < F_15 ( V_3 ) &&
V_20 < V_34 ) {
V_6 ++ ;
V_20 = V_34 ;
}
if ( V_20 )
goto V_37;
}
if ( V_26 && F_16 ( V_3 ) ) {
if ( V_29 + V_24 . V_39 > F_17 ( V_3 ) )
goto V_40;
if ( ! F_18 ( V_26 , & V_24 ) )
goto V_40;
if ( ! F_19 ( V_3 , V_26 , & V_24 ) )
goto V_40;
V_29 += V_24 . V_39 ;
V_25 = V_24 ;
V_26 = & V_25 ;
V_20 += V_24 . V_39 >> 9 ;
if ( V_6 == 1 && V_29 > V_30 )
V_30 = V_29 ;
continue;
}
V_40:
if ( V_6 == F_15 ( V_3 ) )
goto V_37;
V_6 ++ ;
V_25 = V_24 ;
V_26 = & V_25 ;
V_29 = V_24 . V_39 ;
V_20 += V_24 . V_39 >> 9 ;
if ( V_6 == 1 && V_29 > V_30 )
V_30 = V_29 ;
}
V_32 = false ;
V_37:
* V_22 = V_6 ;
if ( V_32 ) {
V_33 = F_7 ( V_1 , V_20 , V_18 , V_5 ) ;
if ( V_33 )
V_1 = V_33 ;
}
V_1 -> V_31 = V_30 ;
if ( V_29 > V_1 -> V_41 )
V_1 -> V_41 = V_29 ;
return V_32 ? V_33 : NULL ;
}
void F_20 ( struct V_2 * V_3 , struct V_1 * * V_1 ,
struct V_4 * V_5 )
{
struct V_1 * V_37 , * V_42 ;
unsigned V_6 ;
switch ( F_21 ( * V_1 ) ) {
case V_43 :
case V_44 :
V_37 = F_1 ( V_3 , * V_1 , V_5 , & V_6 ) ;
break;
case V_45 :
V_37 = F_8 ( V_3 , * V_1 , V_5 , & V_6 ) ;
break;
default:
V_37 = F_12 ( V_3 , * V_1 , V_3 -> F_7 , & V_6 ) ;
break;
}
V_42 = V_37 ? V_37 : * V_1 ;
V_42 -> V_46 = V_6 ;
F_22 ( V_42 , V_47 ) ;
if ( V_37 ) {
V_37 -> V_48 |= V_49 ;
F_23 ( V_37 , * V_1 ) ;
F_24 ( V_3 , V_37 , ( * V_1 ) -> V_16 . V_17 ) ;
F_25 ( * V_1 ) ;
* V_1 = V_37 ;
}
}
static unsigned int F_26 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
bool V_50 )
{
struct V_23 V_24 , V_25 = { NULL } ;
int V_51 , V_52 = 0 ;
unsigned int V_29 , V_53 ;
struct V_1 * V_54 , * V_55 ;
struct V_27 V_28 ;
if ( ! V_1 )
return 0 ;
if ( F_21 ( V_1 ) == V_43 || F_21 ( V_1 ) == V_44 )
return 1 ;
if ( F_21 ( V_1 ) == V_45 )
return 1 ;
V_54 = V_1 ;
V_51 = F_16 ( V_3 ) ;
V_29 = 0 ;
V_53 = 0 ;
F_27 (bio) {
F_13 (bv, bio, iter) {
if ( V_50 )
goto V_40;
if ( V_52 && V_51 ) {
if ( V_29 + V_24 . V_39
> F_17 ( V_3 ) )
goto V_40;
if ( ! F_18 ( & V_25 , & V_24 ) )
goto V_40;
if ( ! F_19 ( V_3 , & V_25 , & V_24 ) )
goto V_40;
V_29 += V_24 . V_39 ;
V_25 = V_24 ;
continue;
}
V_40:
if ( V_53 == 1 && V_29 >
V_54 -> V_31 )
V_54 -> V_31 = V_29 ;
V_53 ++ ;
V_25 = V_24 ;
V_52 = 1 ;
V_29 = V_24 . V_39 ;
}
V_55 = V_1 ;
}
if ( V_53 == 1 && V_29 > V_54 -> V_31 )
V_54 -> V_31 = V_29 ;
if ( V_29 > V_55 -> V_41 )
V_55 -> V_41 = V_29 ;
return V_53 ;
}
void F_28 ( struct V_56 * V_57 )
{
bool V_50 = ! ! F_29 ( V_58 ,
& V_57 -> V_3 -> V_59 ) ;
V_57 -> V_60 = F_26 ( V_57 -> V_3 , V_57 -> V_1 ,
V_50 ) ;
}
void F_30 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
unsigned short V_61 ;
if ( F_31 ( V_1 , V_62 ) )
V_61 = F_32 ( V_1 ) ;
else
V_61 = V_1 -> V_63 ;
if ( F_29 ( V_58 , & V_3 -> V_59 ) &&
( V_61 < F_15 ( V_3 ) ) )
V_1 -> V_46 = V_61 ;
else {
struct V_1 * V_64 = V_1 -> V_65 ;
V_1 -> V_65 = NULL ;
V_1 -> V_46 = F_26 ( V_3 , V_1 , false ) ;
V_1 -> V_65 = V_64 ;
}
F_22 ( V_1 , V_47 ) ;
}
static int F_33 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_1 * V_64 )
{
struct V_23 V_66 = { NULL } , V_67 ;
if ( ! F_16 ( V_3 ) )
return 0 ;
if ( V_1 -> V_41 + V_64 -> V_31 >
F_17 ( V_3 ) )
return 0 ;
if ( ! F_34 ( V_1 ) )
return 1 ;
F_35 ( V_1 , & V_66 ) ;
F_36 ( V_64 , & V_67 ) ;
if ( ! F_18 ( & V_66 , & V_67 ) )
return 0 ;
if ( F_19 ( V_3 , & V_66 , & V_67 ) )
return 1 ;
return 0 ;
}
static inline void
F_37 ( struct V_2 * V_3 , struct V_23 * V_68 ,
struct V_69 * V_70 , struct V_23 * V_25 ,
struct V_69 * * V_71 , int * V_6 , int * V_51 )
{
int V_72 = V_68 -> V_39 ;
if ( * V_71 && * V_51 ) {
if ( ( * V_71 ) -> V_73 + V_72 > F_17 ( V_3 ) )
goto V_40;
if ( ! F_18 ( V_25 , V_68 ) )
goto V_40;
if ( ! F_19 ( V_3 , V_25 , V_68 ) )
goto V_40;
( * V_71 ) -> V_73 += V_72 ;
} else {
V_40:
if ( ! * V_71 )
* V_71 = V_70 ;
else {
F_38 ( * V_71 ) ;
* V_71 = F_39 ( * V_71 ) ;
}
F_40 ( * V_71 , V_68 -> V_74 , V_72 , V_68 -> V_38 ) ;
( * V_6 ) ++ ;
}
* V_25 = * V_68 ;
}
static int F_41 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_69 * V_70 ,
struct V_69 * * V_71 )
{
struct V_23 V_68 , V_25 = { NULL } ;
struct V_27 V_28 ;
int V_6 , V_51 ;
V_6 = 0 ;
V_51 = F_16 ( V_3 ) ;
switch ( F_21 ( V_1 ) ) {
case V_43 :
case V_44 :
if ( ! V_1 -> V_63 )
return 0 ;
case V_45 :
* V_71 = V_70 ;
V_68 = F_42 ( V_1 ) ;
F_40 ( * V_71 , V_68 . V_74 , V_68 . V_39 , V_68 . V_38 ) ;
return 1 ;
default:
break;
}
F_27 (bio)
F_13 (bvec, bio, iter)
F_37 ( V_3 , & V_68 , V_70 , & V_25 , V_71 ,
& V_6 , & V_51 ) ;
return V_6 ;
}
int F_43 ( struct V_2 * V_3 , struct V_56 * V_57 ,
struct V_69 * V_70 )
{
struct V_69 * V_71 = NULL ;
int V_6 = 0 ;
if ( V_57 -> V_1 )
V_6 = F_41 ( V_3 , V_57 -> V_1 , V_70 , & V_71 ) ;
if ( F_4 ( V_57 -> V_75 & V_76 ) &&
( F_44 ( V_57 ) & V_3 -> V_77 ) ) {
unsigned int V_78 =
( V_3 -> V_77 & ~ F_44 ( V_57 ) ) + 1 ;
V_71 -> V_73 += V_78 ;
V_57 -> V_79 += V_78 ;
}
if ( V_3 -> V_80 && V_3 -> V_81 ( V_57 ) ) {
if ( F_45 ( F_46 ( V_57 ) ) )
memset ( V_3 -> V_82 , 0 , V_3 -> V_80 ) ;
F_38 ( V_71 ) ;
V_71 = F_39 ( V_71 ) ;
F_40 ( V_71 , F_47 ( V_3 -> V_82 ) ,
V_3 -> V_80 ,
( ( unsigned long ) V_3 -> V_82 ) &
( V_83 - 1 ) ) ;
V_6 ++ ;
V_57 -> V_79 += V_3 -> V_80 ;
}
if ( V_71 )
F_48 ( V_71 ) ;
F_49 ( V_6 > V_57 -> V_60 ) ;
return V_6 ;
}
static inline int F_50 ( struct V_2 * V_3 ,
struct V_56 * V_84 ,
struct V_1 * V_1 )
{
int V_53 = F_51 ( V_3 , V_1 ) ;
if ( V_84 -> V_60 + V_53 > F_15 ( V_3 ) )
goto V_85;
if ( F_52 ( V_3 , V_84 , V_1 ) == false )
goto V_85;
V_84 -> V_60 += V_53 ;
return 1 ;
V_85:
V_84 -> V_75 |= V_49 ;
if ( V_84 == V_3 -> V_86 )
V_3 -> V_86 = NULL ;
return 0 ;
}
int F_53 ( struct V_2 * V_3 , struct V_56 * V_84 ,
struct V_1 * V_1 )
{
if ( F_54 ( V_84 , V_1 ) )
return 0 ;
if ( F_55 ( V_84 ) &&
F_56 ( V_84 , V_1 ) )
return 0 ;
if ( F_57 ( V_84 ) + F_5 ( V_1 ) >
F_58 ( V_84 , F_59 ( V_84 ) ) ) {
V_84 -> V_75 |= V_49 ;
if ( V_84 == V_3 -> V_86 )
V_3 -> V_86 = NULL ;
return 0 ;
}
if ( ! F_31 ( V_84 -> V_87 , V_47 ) )
F_30 ( V_3 , V_84 -> V_87 ) ;
if ( ! F_31 ( V_1 , V_47 ) )
F_30 ( V_3 , V_1 ) ;
return F_50 ( V_3 , V_84 , V_1 ) ;
}
int F_60 ( struct V_2 * V_3 , struct V_56 * V_84 ,
struct V_1 * V_1 )
{
if ( F_61 ( V_84 , V_1 ) )
return 0 ;
if ( F_55 ( V_84 ) &&
F_62 ( V_84 , V_1 ) )
return 0 ;
if ( F_57 ( V_84 ) + F_5 ( V_1 ) >
F_58 ( V_84 , V_1 -> V_16 . V_17 ) ) {
V_84 -> V_75 |= V_49 ;
if ( V_84 == V_3 -> V_86 )
V_3 -> V_86 = NULL ;
return 0 ;
}
if ( ! F_31 ( V_1 , V_47 ) )
F_30 ( V_3 , V_1 ) ;
if ( ! F_31 ( V_84 -> V_1 , V_47 ) )
F_30 ( V_3 , V_84 -> V_1 ) ;
return F_50 ( V_3 , V_84 , V_1 ) ;
}
static bool F_63 ( struct V_56 * V_84 )
{
struct V_2 * V_3 = V_84 -> V_3 ;
return ! V_3 -> V_88 && V_84 -> V_89 ;
}
static int F_64 ( struct V_2 * V_3 , struct V_56 * V_84 ,
struct V_56 * V_90 )
{
int V_91 ;
unsigned int V_29 =
V_84 -> V_87 -> V_41 + V_90 -> V_1 -> V_31 ;
if ( F_63 ( V_84 ) || F_63 ( V_90 ) )
return 0 ;
if ( F_54 ( V_84 , V_90 -> V_1 ) )
return 0 ;
if ( ( F_57 ( V_84 ) + F_57 ( V_90 ) ) >
F_58 ( V_84 , F_59 ( V_84 ) ) )
return 0 ;
V_91 = V_84 -> V_60 + V_90 -> V_60 ;
if ( F_33 ( V_3 , V_84 -> V_87 , V_90 -> V_1 ) ) {
if ( V_84 -> V_60 == 1 )
V_84 -> V_1 -> V_31 = V_29 ;
if ( V_90 -> V_60 == 1 )
V_90 -> V_87 -> V_41 = V_29 ;
V_91 -- ;
}
if ( V_91 > F_15 ( V_3 ) )
return 0 ;
if ( F_65 ( V_3 , V_84 , V_90 ) == false )
return 0 ;
V_84 -> V_60 = V_91 ;
return 1 ;
}
void F_66 ( struct V_56 * V_57 )
{
unsigned int V_92 = V_57 -> V_75 & V_93 ;
struct V_1 * V_1 ;
if ( V_57 -> V_75 & V_94 )
return;
for ( V_1 = V_57 -> V_1 ; V_1 ; V_1 = V_1 -> V_65 ) {
F_67 ( ( V_1 -> V_48 & V_93 ) &&
( V_1 -> V_48 & V_93 ) != V_92 ) ;
V_1 -> V_48 |= V_92 ;
}
V_57 -> V_75 |= V_94 ;
}
static void F_68 ( struct V_56 * V_84 )
{
if ( F_69 ( V_84 ) ) {
struct V_95 * V_96 ;
int V_97 ;
V_97 = F_70 () ;
V_96 = V_84 -> V_96 ;
F_71 ( V_97 , V_96 ) ;
F_72 ( V_96 , F_73 ( V_84 ) ) ;
F_74 ( V_96 ) ;
F_75 () ;
}
}
static int F_76 ( struct V_2 * V_3 , struct V_56 * V_84 ,
struct V_56 * V_90 )
{
if ( ! F_77 ( V_84 ) || ! F_77 ( V_90 ) )
return 0 ;
if ( F_46 ( V_84 ) != F_46 ( V_90 ) )
return 0 ;
if ( F_59 ( V_84 ) + F_57 ( V_84 ) != F_59 ( V_90 ) )
return 0 ;
if ( F_73 ( V_84 ) != F_73 ( V_90 )
|| V_84 -> V_98 != V_90 -> V_98
|| F_63 ( V_90 ) )
return 0 ;
if ( F_46 ( V_84 ) == V_45 &&
! F_78 ( V_84 -> V_1 , V_90 -> V_1 ) )
return 0 ;
if ( ! F_64 ( V_3 , V_84 , V_90 ) )
return 0 ;
if ( ( V_84 -> V_75 | V_90 -> V_75 ) & V_94 ||
( V_84 -> V_75 & V_93 ) !=
( V_90 -> V_75 & V_93 ) ) {
F_66 ( V_84 ) ;
F_66 ( V_90 ) ;
}
if ( F_79 ( V_84 -> V_99 , V_90 -> V_99 ) )
V_84 -> V_99 = V_90 -> V_99 ;
V_84 -> V_87 -> V_65 = V_90 -> V_1 ;
V_84 -> V_87 = V_90 -> V_87 ;
V_84 -> V_100 += F_44 ( V_90 ) ;
F_80 ( V_3 , V_84 , V_90 ) ;
F_68 ( V_90 ) ;
V_84 -> V_101 = F_81 ( V_84 -> V_101 , V_90 -> V_101 ) ;
if ( F_82 ( V_90 ) )
V_84 -> V_97 = V_90 -> V_97 ;
V_90 -> V_1 = NULL ;
F_83 ( V_3 , V_90 ) ;
return 1 ;
}
int F_84 ( struct V_2 * V_3 , struct V_56 * V_57 )
{
struct V_56 * V_90 = F_85 ( V_3 , V_57 ) ;
if ( V_90 )
return F_76 ( V_3 , V_57 , V_90 ) ;
return 0 ;
}
int F_86 ( struct V_2 * V_3 , struct V_56 * V_57 )
{
struct V_56 * V_52 = F_87 ( V_3 , V_57 ) ;
if ( V_52 )
return F_76 ( V_3 , V_52 , V_57 ) ;
return 0 ;
}
int F_88 ( struct V_2 * V_3 , struct V_56 * V_57 ,
struct V_56 * V_90 )
{
struct V_102 * V_103 = V_3 -> V_104 ;
if ( V_103 -> type -> V_105 . V_106 )
if ( ! V_103 -> type -> V_105 . V_106 ( V_3 , V_57 , V_90 ) )
return 0 ;
return F_76 ( V_3 , V_57 , V_90 ) ;
}
bool F_89 ( struct V_56 * V_57 , struct V_1 * V_1 )
{
if ( ! F_77 ( V_57 ) || ! F_90 ( V_1 ) )
return false ;
if ( F_46 ( V_57 ) != F_21 ( V_1 ) )
return false ;
if ( F_91 ( V_1 ) != F_73 ( V_57 ) )
return false ;
if ( V_57 -> V_98 != V_1 -> V_107 -> V_108 || F_63 ( V_57 ) )
return false ;
if ( F_52 ( V_57 -> V_3 , V_57 , V_1 ) == false )
return false ;
if ( F_46 ( V_57 ) == V_45 &&
! F_78 ( V_57 -> V_1 , V_1 ) )
return false ;
return true ;
}
int F_92 ( struct V_56 * V_57 , struct V_1 * V_1 )
{
if ( F_59 ( V_57 ) + F_57 ( V_57 ) == V_1 -> V_16 . V_17 )
return V_109 ;
else if ( F_59 ( V_57 ) - F_5 ( V_1 ) == V_1 -> V_16 . V_17 )
return V_110 ;
return V_111 ;
}
