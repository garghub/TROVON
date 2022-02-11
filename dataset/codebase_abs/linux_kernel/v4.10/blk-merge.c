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
V_37 = NULL ;
V_6 = ( * V_1 ) -> V_46 ;
break;
case V_47 :
V_37 = F_8 ( V_3 , * V_1 , V_5 , & V_6 ) ;
break;
default:
V_37 = F_12 ( V_3 , * V_1 , V_3 -> F_7 , & V_6 ) ;
break;
}
V_42 = V_37 ? V_37 : * V_1 ;
V_42 -> V_46 = V_6 ;
F_22 ( V_42 , V_48 ) ;
if ( V_37 ) {
V_37 -> V_49 |= V_50 ;
F_23 ( V_37 , * V_1 ) ;
F_24 ( V_3 , V_37 , ( * V_1 ) -> V_16 . V_17 ) ;
F_25 ( * V_1 ) ;
* V_1 = V_37 ;
}
}
static unsigned int F_26 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
bool V_51 )
{
struct V_23 V_24 , V_25 = { NULL } ;
int V_52 , V_53 = 0 ;
unsigned int V_29 , V_54 ;
struct V_1 * V_55 , * V_56 ;
struct V_27 V_28 ;
if ( ! V_1 )
return 0 ;
switch ( F_21 ( V_1 ) ) {
case V_43 :
case V_44 :
case V_45 :
return 0 ;
case V_47 :
return 1 ;
}
V_55 = V_1 ;
V_52 = F_16 ( V_3 ) ;
V_29 = 0 ;
V_54 = 0 ;
F_27 (bio) {
F_13 (bv, bio, iter) {
if ( V_51 )
goto V_40;
if ( V_53 && V_52 ) {
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
if ( V_54 == 1 && V_29 >
V_55 -> V_31 )
V_55 -> V_31 = V_29 ;
V_54 ++ ;
V_25 = V_24 ;
V_53 = 1 ;
V_29 = V_24 . V_39 ;
}
V_56 = V_1 ;
}
if ( V_54 == 1 && V_29 > V_55 -> V_31 )
V_55 -> V_31 = V_29 ;
if ( V_29 > V_56 -> V_41 )
V_56 -> V_41 = V_29 ;
return V_54 ;
}
void F_28 ( struct V_57 * V_58 )
{
bool V_51 = ! ! F_29 ( V_59 ,
& V_58 -> V_3 -> V_60 ) ;
V_58 -> V_61 = F_26 ( V_58 -> V_3 , V_58 -> V_1 ,
V_51 ) ;
}
void F_30 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
unsigned short V_62 ;
if ( F_31 ( V_1 , V_63 ) )
V_62 = F_32 ( V_1 ) ;
else
V_62 = V_1 -> V_64 ;
if ( F_29 ( V_59 , & V_3 -> V_60 ) &&
( V_62 < F_15 ( V_3 ) ) )
V_1 -> V_46 = V_62 ;
else {
struct V_1 * V_65 = V_1 -> V_66 ;
V_1 -> V_66 = NULL ;
V_1 -> V_46 = F_26 ( V_3 , V_1 , false ) ;
V_1 -> V_66 = V_65 ;
}
F_22 ( V_1 , V_48 ) ;
}
static int F_33 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_1 * V_65 )
{
struct V_23 V_67 = { NULL } , V_68 ;
if ( ! F_16 ( V_3 ) )
return 0 ;
if ( V_1 -> V_41 + V_65 -> V_31 >
F_17 ( V_3 ) )
return 0 ;
if ( ! F_34 ( V_1 ) )
return 1 ;
F_35 ( V_1 , & V_67 ) ;
F_36 ( V_65 , & V_68 ) ;
if ( ! F_18 ( & V_67 , & V_68 ) )
return 0 ;
if ( F_19 ( V_3 , & V_67 , & V_68 ) )
return 1 ;
return 0 ;
}
static inline void
F_37 ( struct V_2 * V_3 , struct V_23 * V_69 ,
struct V_70 * V_71 , struct V_23 * V_25 ,
struct V_70 * * V_72 , int * V_6 , int * V_52 )
{
int V_73 = V_69 -> V_39 ;
if ( * V_72 && * V_52 ) {
if ( ( * V_72 ) -> V_74 + V_73 > F_17 ( V_3 ) )
goto V_40;
if ( ! F_18 ( V_25 , V_69 ) )
goto V_40;
if ( ! F_19 ( V_3 , V_25 , V_69 ) )
goto V_40;
( * V_72 ) -> V_74 += V_73 ;
} else {
V_40:
if ( ! * V_72 )
* V_72 = V_71 ;
else {
F_38 ( * V_72 ) ;
* V_72 = F_39 ( * V_72 ) ;
}
F_40 ( * V_72 , V_69 -> V_75 , V_73 , V_69 -> V_38 ) ;
( * V_6 ) ++ ;
}
* V_25 = * V_69 ;
}
static inline int F_41 ( struct V_2 * V_3 , struct V_23 V_24 ,
struct V_70 * V_71 , struct V_70 * * V_72 )
{
* V_72 = V_71 ;
F_40 ( * V_72 , V_24 . V_75 , V_24 . V_39 , V_24 . V_38 ) ;
return 1 ;
}
static int F_42 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_70 * V_71 ,
struct V_70 * * V_72 )
{
struct V_23 V_69 , V_25 = { NULL } ;
struct V_27 V_28 ;
int V_52 = F_16 ( V_3 ) , V_6 = 0 ;
F_27 (bio)
F_13 (bvec, bio, iter)
F_37 ( V_3 , & V_69 , V_71 , & V_25 , V_72 ,
& V_6 , & V_52 ) ;
return V_6 ;
}
int F_43 ( struct V_2 * V_3 , struct V_57 * V_58 ,
struct V_70 * V_71 )
{
struct V_70 * V_72 = NULL ;
int V_6 = 0 ;
if ( V_58 -> V_76 & V_77 )
V_6 = F_41 ( V_3 , V_58 -> V_78 , V_71 , & V_72 ) ;
else if ( V_58 -> V_1 && F_21 ( V_58 -> V_1 ) == V_47 )
V_6 = F_41 ( V_3 , F_44 ( V_58 -> V_1 ) , V_71 , & V_72 ) ;
else if ( V_58 -> V_1 )
V_6 = F_42 ( V_3 , V_58 -> V_1 , V_71 , & V_72 ) ;
if ( F_4 ( V_58 -> V_76 & V_79 ) &&
( F_45 ( V_58 ) & V_3 -> V_80 ) ) {
unsigned int V_81 =
( V_3 -> V_80 & ~ F_45 ( V_58 ) ) + 1 ;
V_72 -> V_74 += V_81 ;
V_58 -> V_82 += V_81 ;
}
if ( V_3 -> V_83 && V_3 -> V_84 ( V_58 ) ) {
if ( F_46 ( F_47 ( V_58 ) ) )
memset ( V_3 -> V_85 , 0 , V_3 -> V_83 ) ;
F_38 ( V_72 ) ;
V_72 = F_39 ( V_72 ) ;
F_40 ( V_72 , F_48 ( V_3 -> V_85 ) ,
V_3 -> V_83 ,
( ( unsigned long ) V_3 -> V_85 ) &
( V_86 - 1 ) ) ;
V_6 ++ ;
V_58 -> V_82 += V_3 -> V_83 ;
}
if ( V_72 )
F_49 ( V_72 ) ;
F_50 ( V_6 > F_51 ( V_58 ) ) ;
return V_6 ;
}
static void F_52 ( struct V_2 * V_3 , struct V_57 * V_87 )
{
V_87 -> V_88 |= V_50 ;
if ( V_87 == V_3 -> V_89 )
V_3 -> V_89 = NULL ;
}
static inline int F_53 ( struct V_2 * V_3 ,
struct V_57 * V_87 ,
struct V_1 * V_1 )
{
int V_54 = F_54 ( V_3 , V_1 ) ;
if ( V_87 -> V_61 + V_54 > F_15 ( V_3 ) )
goto V_90;
if ( F_55 ( V_3 , V_87 , V_1 ) == false )
goto V_90;
V_87 -> V_61 += V_54 ;
return 1 ;
V_90:
F_52 ( V_3 , V_87 ) ;
return 0 ;
}
int F_56 ( struct V_2 * V_3 , struct V_57 * V_87 ,
struct V_1 * V_1 )
{
if ( F_57 ( V_87 , V_1 ) )
return 0 ;
if ( F_58 ( V_87 ) &&
F_59 ( V_87 , V_1 ) )
return 0 ;
if ( F_60 ( V_87 ) + F_5 ( V_1 ) >
F_61 ( V_87 , F_62 ( V_87 ) ) ) {
F_52 ( V_3 , V_87 ) ;
return 0 ;
}
if ( ! F_31 ( V_87 -> V_91 , V_48 ) )
F_30 ( V_3 , V_87 -> V_91 ) ;
if ( ! F_31 ( V_1 , V_48 ) )
F_30 ( V_3 , V_1 ) ;
return F_53 ( V_3 , V_87 , V_1 ) ;
}
int F_63 ( struct V_2 * V_3 , struct V_57 * V_87 ,
struct V_1 * V_1 )
{
if ( F_64 ( V_87 , V_1 ) )
return 0 ;
if ( F_58 ( V_87 ) &&
F_65 ( V_87 , V_1 ) )
return 0 ;
if ( F_60 ( V_87 ) + F_5 ( V_1 ) >
F_61 ( V_87 , V_1 -> V_16 . V_17 ) ) {
F_52 ( V_3 , V_87 ) ;
return 0 ;
}
if ( ! F_31 ( V_1 , V_48 ) )
F_30 ( V_3 , V_1 ) ;
if ( ! F_31 ( V_87 -> V_1 , V_48 ) )
F_30 ( V_3 , V_87 -> V_1 ) ;
return F_53 ( V_3 , V_87 , V_1 ) ;
}
static bool F_66 ( struct V_57 * V_87 )
{
struct V_2 * V_3 = V_87 -> V_3 ;
return ! V_3 -> V_92 && V_87 -> V_93 ;
}
static int F_67 ( struct V_2 * V_3 , struct V_57 * V_87 ,
struct V_57 * V_94 )
{
int V_95 ;
unsigned int V_29 =
V_87 -> V_91 -> V_41 + V_94 -> V_1 -> V_31 ;
if ( F_66 ( V_87 ) || F_66 ( V_94 ) )
return 0 ;
if ( F_57 ( V_87 , V_94 -> V_1 ) )
return 0 ;
if ( ( F_60 ( V_87 ) + F_60 ( V_94 ) ) >
F_61 ( V_87 , F_62 ( V_87 ) ) )
return 0 ;
V_95 = V_87 -> V_61 + V_94 -> V_61 ;
if ( F_33 ( V_3 , V_87 -> V_91 , V_94 -> V_1 ) ) {
if ( V_87 -> V_61 == 1 )
V_87 -> V_1 -> V_31 = V_29 ;
if ( V_94 -> V_61 == 1 )
V_94 -> V_91 -> V_41 = V_29 ;
V_95 -- ;
}
if ( V_95 > F_15 ( V_3 ) )
return 0 ;
if ( F_68 ( V_3 , V_87 , V_94 ) == false )
return 0 ;
V_87 -> V_61 = V_95 ;
return 1 ;
}
void F_69 ( struct V_57 * V_58 )
{
unsigned int V_96 = V_58 -> V_88 & V_97 ;
struct V_1 * V_1 ;
if ( V_58 -> V_76 & V_98 )
return;
for ( V_1 = V_58 -> V_1 ; V_1 ; V_1 = V_1 -> V_66 ) {
F_70 ( ( V_1 -> V_49 & V_97 ) &&
( V_1 -> V_49 & V_97 ) != V_96 ) ;
V_1 -> V_49 |= V_96 ;
}
V_58 -> V_76 |= V_98 ;
}
static void F_71 ( struct V_57 * V_87 )
{
if ( F_72 ( V_87 ) ) {
struct V_99 * V_100 ;
int V_101 ;
V_101 = F_73 () ;
V_100 = V_87 -> V_100 ;
F_74 ( V_101 , V_100 ) ;
F_75 ( V_100 , F_76 ( V_87 ) ) ;
F_77 ( V_100 ) ;
F_78 () ;
}
}
static int F_79 ( struct V_2 * V_3 , struct V_57 * V_87 ,
struct V_57 * V_94 )
{
if ( ! F_80 ( V_87 ) || ! F_80 ( V_94 ) )
return 0 ;
if ( F_47 ( V_87 ) != F_47 ( V_94 ) )
return 0 ;
if ( F_62 ( V_87 ) + F_60 ( V_87 ) != F_62 ( V_94 ) )
return 0 ;
if ( F_76 ( V_87 ) != F_76 ( V_94 )
|| V_87 -> V_102 != V_94 -> V_102
|| F_66 ( V_94 ) )
return 0 ;
if ( F_47 ( V_87 ) == V_47 &&
! F_81 ( V_87 -> V_1 , V_94 -> V_1 ) )
return 0 ;
if ( ! F_67 ( V_3 , V_87 , V_94 ) )
return 0 ;
if ( ( ( V_87 -> V_76 | V_94 -> V_76 ) & V_98 ) ||
( V_87 -> V_88 & V_97 ) !=
( V_94 -> V_88 & V_97 ) ) {
F_69 ( V_87 ) ;
F_69 ( V_94 ) ;
}
if ( F_82 ( V_87 -> V_103 , V_94 -> V_103 ) )
V_87 -> V_103 = V_94 -> V_103 ;
V_87 -> V_91 -> V_66 = V_94 -> V_1 ;
V_87 -> V_91 = V_94 -> V_91 ;
V_87 -> V_104 += F_45 ( V_94 ) ;
F_83 ( V_3 , V_87 , V_94 ) ;
F_71 ( V_94 ) ;
V_87 -> V_105 = F_84 ( V_87 -> V_105 , V_94 -> V_105 ) ;
if ( F_85 ( V_94 ) )
V_87 -> V_101 = V_94 -> V_101 ;
V_94 -> V_1 = NULL ;
F_86 ( V_3 , V_94 ) ;
return 1 ;
}
int F_87 ( struct V_2 * V_3 , struct V_57 * V_58 )
{
struct V_57 * V_94 = F_88 ( V_3 , V_58 ) ;
if ( V_94 )
return F_79 ( V_3 , V_58 , V_94 ) ;
return 0 ;
}
int F_89 ( struct V_2 * V_3 , struct V_57 * V_58 )
{
struct V_57 * V_53 = F_90 ( V_3 , V_58 ) ;
if ( V_53 )
return F_79 ( V_3 , V_53 , V_58 ) ;
return 0 ;
}
int F_91 ( struct V_2 * V_3 , struct V_57 * V_58 ,
struct V_57 * V_94 )
{
struct V_106 * V_107 = V_3 -> V_108 ;
if ( V_107 -> type -> V_109 . V_110 )
if ( ! V_107 -> type -> V_109 . V_110 ( V_3 , V_58 , V_94 ) )
return 0 ;
return F_79 ( V_3 , V_58 , V_94 ) ;
}
bool F_92 ( struct V_57 * V_58 , struct V_1 * V_1 )
{
if ( ! F_80 ( V_58 ) || ! F_93 ( V_1 ) )
return false ;
if ( F_47 ( V_58 ) != F_21 ( V_1 ) )
return false ;
if ( F_94 ( V_1 ) != F_76 ( V_58 ) )
return false ;
if ( V_58 -> V_102 != V_1 -> V_111 -> V_112 || F_66 ( V_58 ) )
return false ;
if ( F_55 ( V_58 -> V_3 , V_58 , V_1 ) == false )
return false ;
if ( F_47 ( V_58 ) == V_47 &&
! F_81 ( V_58 -> V_1 , V_1 ) )
return false ;
return true ;
}
int F_95 ( struct V_57 * V_58 , struct V_1 * V_1 )
{
if ( F_62 ( V_58 ) + F_60 ( V_58 ) == V_1 -> V_16 . V_17 )
return V_113 ;
else if ( F_62 ( V_58 ) - F_5 ( V_1 ) == V_1 -> V_16 . V_17 )
return V_114 ;
return V_115 ;
}
