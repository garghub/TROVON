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
struct V_1 * V_1 , struct V_4 * V_5 , unsigned * V_6 )
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
unsigned * V_6 )
{
* V_6 = 1 ;
if ( ! V_3 -> V_12 . V_20 )
return NULL ;
if ( F_5 ( V_1 ) <= V_3 -> V_12 . V_20 )
return NULL ;
return F_7 ( V_1 , V_3 -> V_12 . V_20 , V_18 , V_5 ) ;
}
static inline unsigned F_10 ( struct V_2 * V_3 ,
struct V_1 * V_1 )
{
unsigned V_21 = F_11 ( V_3 , V_1 -> V_16 . V_17 ) ;
unsigned V_22 = F_12 ( V_3 ) - 1 ;
V_21 &= ~ ( V_22 >> 9 ) ;
return V_21 ;
}
static struct V_1 * F_13 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
struct V_4 * V_5 ,
unsigned * V_23 )
{
struct V_24 V_25 , V_26 , * V_27 = NULL ;
struct V_28 V_29 ;
unsigned V_30 = 0 , V_6 = 0 , V_21 = 0 ;
unsigned V_31 = V_1 -> V_32 ;
bool V_33 = true ;
struct V_1 * V_34 = NULL ;
const unsigned V_35 = F_10 ( V_3 , V_1 ) ;
unsigned V_36 = 0 ;
F_14 (bv, bio, iter) {
if ( V_36 ++ >= V_37 )
goto V_38;
if ( V_27 && F_15 ( V_3 , V_27 , V_25 . V_39 ) )
goto V_38;
if ( V_21 + ( V_25 . V_40 >> 9 ) > V_35 ) {
if ( V_6 < F_16 ( V_3 ) &&
V_21 < V_35 ) {
V_6 ++ ;
V_21 = V_35 ;
}
if ( V_21 )
goto V_38;
}
if ( V_27 && F_17 ( V_3 ) ) {
if ( V_30 + V_25 . V_40 > F_18 ( V_3 ) )
goto V_41;
if ( ! F_19 ( V_27 , & V_25 ) )
goto V_41;
if ( ! F_20 ( V_3 , V_27 , & V_25 ) )
goto V_41;
V_30 += V_25 . V_40 ;
V_26 = V_25 ;
V_27 = & V_26 ;
V_21 += V_25 . V_40 >> 9 ;
if ( V_6 == 1 && V_30 > V_31 )
V_31 = V_30 ;
continue;
}
V_41:
if ( V_6 == F_16 ( V_3 ) )
goto V_38;
V_6 ++ ;
V_26 = V_25 ;
V_27 = & V_26 ;
V_30 = V_25 . V_40 ;
V_21 += V_25 . V_40 >> 9 ;
if ( V_6 == 1 && V_30 > V_31 )
V_31 = V_30 ;
}
V_33 = false ;
V_38:
* V_23 = V_6 ;
if ( V_33 ) {
V_34 = F_7 ( V_1 , V_21 , V_18 , V_5 ) ;
if ( V_34 )
V_1 = V_34 ;
}
V_1 -> V_32 = V_31 ;
if ( V_30 > V_1 -> V_42 )
V_1 -> V_42 = V_30 ;
return V_33 ? V_34 : NULL ;
}
void F_21 ( struct V_2 * V_3 , struct V_1 * * V_1 ,
struct V_4 * V_5 )
{
struct V_1 * V_38 , * V_43 ;
unsigned V_6 ;
switch ( F_22 ( * V_1 ) ) {
case V_44 :
case V_45 :
V_38 = F_1 ( V_3 , * V_1 , V_5 , & V_6 ) ;
break;
case V_46 :
V_38 = F_8 ( V_3 , * V_1 , V_5 , & V_6 ) ;
break;
case V_47 :
V_38 = F_9 ( V_3 , * V_1 , V_5 , & V_6 ) ;
break;
default:
V_38 = F_13 ( V_3 , * V_1 , V_3 -> F_7 , & V_6 ) ;
break;
}
V_43 = V_38 ? V_38 : * V_1 ;
V_43 -> V_48 = V_6 ;
F_23 ( V_43 , V_49 ) ;
if ( V_38 ) {
V_38 -> V_50 |= V_51 ;
F_24 ( V_38 , * V_1 ) ;
F_25 ( V_3 , V_38 , ( * V_1 ) -> V_16 . V_17 ) ;
F_26 ( * V_1 ) ;
* V_1 = V_38 ;
}
}
static unsigned int F_27 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
bool V_52 )
{
struct V_24 V_25 , V_26 = { NULL } ;
int V_53 , V_54 = 0 ;
unsigned int V_30 , V_55 ;
struct V_1 * V_56 , * V_57 ;
struct V_28 V_29 ;
if ( ! V_1 )
return 0 ;
switch ( F_22 ( V_1 ) ) {
case V_44 :
case V_45 :
case V_46 :
return 0 ;
case V_47 :
return 1 ;
}
V_56 = V_1 ;
V_53 = F_17 ( V_3 ) ;
V_30 = 0 ;
V_55 = 0 ;
F_28 (bio) {
F_14 (bv, bio, iter) {
if ( V_52 )
goto V_41;
if ( V_54 && V_53 ) {
if ( V_30 + V_25 . V_40
> F_18 ( V_3 ) )
goto V_41;
if ( ! F_19 ( & V_26 , & V_25 ) )
goto V_41;
if ( ! F_20 ( V_3 , & V_26 , & V_25 ) )
goto V_41;
V_30 += V_25 . V_40 ;
V_26 = V_25 ;
continue;
}
V_41:
if ( V_55 == 1 && V_30 >
V_56 -> V_32 )
V_56 -> V_32 = V_30 ;
V_55 ++ ;
V_26 = V_25 ;
V_54 = 1 ;
V_30 = V_25 . V_40 ;
}
V_57 = V_1 ;
}
if ( V_55 == 1 && V_30 > V_56 -> V_32 )
V_56 -> V_32 = V_30 ;
if ( V_30 > V_57 -> V_42 )
V_57 -> V_42 = V_30 ;
return V_55 ;
}
void F_29 ( struct V_58 * V_59 )
{
bool V_52 = ! ! F_30 ( V_60 ,
& V_59 -> V_3 -> V_61 ) ;
V_59 -> V_62 = F_27 ( V_59 -> V_3 , V_59 -> V_1 ,
V_52 ) ;
}
void F_31 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
unsigned short V_63 ;
if ( F_32 ( V_1 , V_64 ) )
V_63 = F_33 ( V_1 ) ;
else
V_63 = V_1 -> V_65 ;
if ( F_30 ( V_60 , & V_3 -> V_61 ) &&
( V_63 < F_16 ( V_3 ) ) )
V_1 -> V_48 = V_63 ;
else {
struct V_1 * V_66 = V_1 -> V_67 ;
V_1 -> V_67 = NULL ;
V_1 -> V_48 = F_27 ( V_3 , V_1 , false ) ;
V_1 -> V_67 = V_66 ;
}
F_23 ( V_1 , V_49 ) ;
}
static int F_34 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_1 * V_66 )
{
struct V_24 V_68 = { NULL } , V_69 ;
if ( ! F_17 ( V_3 ) )
return 0 ;
if ( V_1 -> V_42 + V_66 -> V_32 >
F_18 ( V_3 ) )
return 0 ;
if ( ! F_35 ( V_1 ) )
return 1 ;
F_36 ( V_1 , & V_68 ) ;
F_37 ( V_66 , & V_69 ) ;
if ( ! F_19 ( & V_68 , & V_69 ) )
return 0 ;
if ( F_20 ( V_3 , & V_68 , & V_69 ) )
return 1 ;
return 0 ;
}
static inline void
F_38 ( struct V_2 * V_3 , struct V_24 * V_70 ,
struct V_71 * V_72 , struct V_24 * V_26 ,
struct V_71 * * V_73 , int * V_6 , int * V_53 )
{
int V_74 = V_70 -> V_40 ;
if ( * V_73 && * V_53 ) {
if ( ( * V_73 ) -> V_75 + V_74 > F_18 ( V_3 ) )
goto V_41;
if ( ! F_19 ( V_26 , V_70 ) )
goto V_41;
if ( ! F_20 ( V_3 , V_26 , V_70 ) )
goto V_41;
( * V_73 ) -> V_75 += V_74 ;
} else {
V_41:
if ( ! * V_73 )
* V_73 = V_72 ;
else {
F_39 ( * V_73 ) ;
* V_73 = F_40 ( * V_73 ) ;
}
F_41 ( * V_73 , V_70 -> V_76 , V_74 , V_70 -> V_39 ) ;
( * V_6 ) ++ ;
}
* V_26 = * V_70 ;
}
static inline int F_42 ( struct V_2 * V_3 , struct V_24 V_25 ,
struct V_71 * V_72 , struct V_71 * * V_73 )
{
* V_73 = V_72 ;
F_41 ( * V_73 , V_25 . V_76 , V_25 . V_40 , V_25 . V_39 ) ;
return 1 ;
}
static int F_43 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_71 * V_72 ,
struct V_71 * * V_73 )
{
struct V_24 V_70 , V_26 = { NULL } ;
struct V_28 V_29 ;
int V_53 = F_17 ( V_3 ) , V_6 = 0 ;
F_28 (bio)
F_14 (bvec, bio, iter)
F_38 ( V_3 , & V_70 , V_72 , & V_26 , V_73 ,
& V_6 , & V_53 ) ;
return V_6 ;
}
int F_44 ( struct V_2 * V_3 , struct V_58 * V_59 ,
struct V_71 * V_72 )
{
struct V_71 * V_73 = NULL ;
int V_6 = 0 ;
if ( V_59 -> V_77 & V_78 )
V_6 = F_42 ( V_3 , V_59 -> V_79 , V_72 , & V_73 ) ;
else if ( V_59 -> V_1 && F_22 ( V_59 -> V_1 ) == V_47 )
V_6 = F_42 ( V_3 , F_45 ( V_59 -> V_1 ) , V_72 , & V_73 ) ;
else if ( V_59 -> V_1 )
V_6 = F_43 ( V_3 , V_59 -> V_1 , V_72 , & V_73 ) ;
if ( F_4 ( V_59 -> V_77 & V_80 ) &&
( F_46 ( V_59 ) & V_3 -> V_81 ) ) {
unsigned int V_82 =
( V_3 -> V_81 & ~ F_46 ( V_59 ) ) + 1 ;
V_73 -> V_75 += V_82 ;
V_59 -> V_83 += V_82 ;
}
if ( V_3 -> V_84 && V_3 -> V_85 ( V_59 ) ) {
if ( F_47 ( F_48 ( V_59 ) ) )
memset ( V_3 -> V_86 , 0 , V_3 -> V_84 ) ;
F_39 ( V_73 ) ;
V_73 = F_40 ( V_73 ) ;
F_41 ( V_73 , F_49 ( V_3 -> V_86 ) ,
V_3 -> V_84 ,
( ( unsigned long ) V_3 -> V_86 ) &
( V_87 - 1 ) ) ;
V_6 ++ ;
V_59 -> V_83 += V_3 -> V_84 ;
}
if ( V_73 )
F_50 ( V_73 ) ;
F_51 ( V_6 > F_52 ( V_59 ) ) ;
return V_6 ;
}
static inline int F_53 ( struct V_2 * V_3 ,
struct V_58 * V_88 ,
struct V_1 * V_1 )
{
int V_55 = F_54 ( V_3 , V_1 ) ;
if ( V_88 -> V_62 + V_55 > F_16 ( V_3 ) )
goto V_89;
if ( F_55 ( V_3 , V_88 , V_1 ) == false )
goto V_89;
V_88 -> V_62 += V_55 ;
return 1 ;
V_89:
F_56 ( V_3 , V_88 ) ;
return 0 ;
}
int F_57 ( struct V_2 * V_3 , struct V_58 * V_88 ,
struct V_1 * V_1 )
{
if ( F_58 ( V_88 , V_1 ) )
return 0 ;
if ( F_59 ( V_88 ) &&
F_60 ( V_88 , V_1 ) )
return 0 ;
if ( F_61 ( V_88 ) + F_5 ( V_1 ) >
F_62 ( V_88 , F_63 ( V_88 ) ) ) {
F_56 ( V_3 , V_88 ) ;
return 0 ;
}
if ( ! F_32 ( V_88 -> V_90 , V_49 ) )
F_31 ( V_3 , V_88 -> V_90 ) ;
if ( ! F_32 ( V_1 , V_49 ) )
F_31 ( V_3 , V_1 ) ;
return F_53 ( V_3 , V_88 , V_1 ) ;
}
int F_64 ( struct V_2 * V_3 , struct V_58 * V_88 ,
struct V_1 * V_1 )
{
if ( F_65 ( V_88 , V_1 ) )
return 0 ;
if ( F_59 ( V_88 ) &&
F_66 ( V_88 , V_1 ) )
return 0 ;
if ( F_61 ( V_88 ) + F_5 ( V_1 ) >
F_62 ( V_88 , V_1 -> V_16 . V_17 ) ) {
F_56 ( V_3 , V_88 ) ;
return 0 ;
}
if ( ! F_32 ( V_1 , V_49 ) )
F_31 ( V_3 , V_1 ) ;
if ( ! F_32 ( V_88 -> V_1 , V_49 ) )
F_31 ( V_3 , V_88 -> V_1 ) ;
return F_53 ( V_3 , V_88 , V_1 ) ;
}
static bool F_67 ( struct V_58 * V_88 )
{
struct V_2 * V_3 = V_88 -> V_3 ;
return ! V_3 -> V_91 && V_88 -> V_92 ;
}
static int F_68 ( struct V_2 * V_3 , struct V_58 * V_88 ,
struct V_58 * V_93 )
{
int V_94 ;
unsigned int V_30 =
V_88 -> V_90 -> V_42 + V_93 -> V_1 -> V_32 ;
if ( F_67 ( V_88 ) || F_67 ( V_93 ) )
return 0 ;
if ( F_58 ( V_88 , V_93 -> V_1 ) )
return 0 ;
if ( ( F_61 ( V_88 ) + F_61 ( V_93 ) ) >
F_62 ( V_88 , F_63 ( V_88 ) ) )
return 0 ;
V_94 = V_88 -> V_62 + V_93 -> V_62 ;
if ( F_34 ( V_3 , V_88 -> V_90 , V_93 -> V_1 ) ) {
if ( V_88 -> V_62 == 1 )
V_88 -> V_1 -> V_32 = V_30 ;
if ( V_93 -> V_62 == 1 )
V_93 -> V_90 -> V_42 = V_30 ;
V_94 -- ;
}
if ( V_94 > F_16 ( V_3 ) )
return 0 ;
if ( F_69 ( V_3 , V_88 , V_93 ) == false )
return 0 ;
V_88 -> V_62 = V_94 ;
return 1 ;
}
void F_70 ( struct V_58 * V_59 )
{
unsigned int V_95 = V_59 -> V_96 & V_97 ;
struct V_1 * V_1 ;
if ( V_59 -> V_77 & V_98 )
return;
for ( V_1 = V_59 -> V_1 ; V_1 ; V_1 = V_1 -> V_67 ) {
F_71 ( ( V_1 -> V_50 & V_97 ) &&
( V_1 -> V_50 & V_97 ) != V_95 ) ;
V_1 -> V_50 |= V_95 ;
}
V_59 -> V_77 |= V_98 ;
}
static void F_72 ( struct V_58 * V_88 )
{
if ( F_73 ( V_88 ) ) {
struct V_99 * V_100 ;
int V_101 ;
V_101 = F_74 () ;
V_100 = V_88 -> V_100 ;
F_75 ( V_101 , V_100 ) ;
F_76 ( V_100 , F_77 ( V_88 ) ) ;
F_78 ( V_100 ) ;
F_79 () ;
}
}
static struct V_58 * F_80 ( struct V_2 * V_3 ,
struct V_58 * V_88 , struct V_58 * V_93 )
{
if ( ! F_81 ( V_88 ) || ! F_81 ( V_93 ) )
return NULL ;
if ( F_48 ( V_88 ) != F_48 ( V_93 ) )
return NULL ;
if ( F_63 ( V_88 ) + F_61 ( V_88 ) != F_63 ( V_93 ) )
return NULL ;
if ( F_77 ( V_88 ) != F_77 ( V_93 )
|| V_88 -> V_102 != V_93 -> V_102
|| F_67 ( V_93 ) )
return NULL ;
if ( F_48 ( V_88 ) == V_47 &&
! F_82 ( V_88 -> V_1 , V_93 -> V_1 ) )
return NULL ;
if ( ! F_68 ( V_3 , V_88 , V_93 ) )
return NULL ;
if ( ( ( V_88 -> V_77 | V_93 -> V_77 ) & V_98 ) ||
( V_88 -> V_96 & V_97 ) !=
( V_93 -> V_96 & V_97 ) ) {
F_70 ( V_88 ) ;
F_70 ( V_93 ) ;
}
if ( F_83 ( V_88 -> V_103 , V_93 -> V_103 ) )
V_88 -> V_103 = V_93 -> V_103 ;
V_88 -> V_90 -> V_67 = V_93 -> V_1 ;
V_88 -> V_90 = V_93 -> V_90 ;
V_88 -> V_104 += F_46 ( V_93 ) ;
F_84 ( V_3 , V_88 , V_93 ) ;
F_72 ( V_93 ) ;
V_88 -> V_105 = F_85 ( V_88 -> V_105 , V_93 -> V_105 ) ;
if ( F_86 ( V_93 ) )
V_88 -> V_101 = V_93 -> V_101 ;
V_93 -> V_1 = NULL ;
return V_93 ;
}
struct V_58 * F_87 ( struct V_2 * V_3 , struct V_58 * V_59 )
{
struct V_58 * V_93 = F_88 ( V_3 , V_59 ) ;
if ( V_93 )
return F_80 ( V_3 , V_59 , V_93 ) ;
return NULL ;
}
struct V_58 * F_89 ( struct V_2 * V_3 , struct V_58 * V_59 )
{
struct V_58 * V_54 = F_90 ( V_3 , V_59 ) ;
if ( V_54 )
return F_80 ( V_3 , V_54 , V_59 ) ;
return NULL ;
}
int F_91 ( struct V_2 * V_3 , struct V_58 * V_59 ,
struct V_58 * V_93 )
{
struct V_106 * V_107 = V_3 -> V_108 ;
struct V_58 * free ;
if ( ! V_107 -> V_109 && V_107 -> type -> V_110 . V_111 . V_112 )
if ( ! V_107 -> type -> V_110 . V_111 . V_112 ( V_3 , V_59 , V_93 ) )
return 0 ;
free = F_80 ( V_3 , V_59 , V_93 ) ;
if ( free ) {
F_92 ( V_3 , free ) ;
return 1 ;
}
return 0 ;
}
bool F_93 ( struct V_58 * V_59 , struct V_1 * V_1 )
{
if ( ! F_81 ( V_59 ) || ! F_94 ( V_1 ) )
return false ;
if ( F_48 ( V_59 ) != F_22 ( V_1 ) )
return false ;
if ( F_95 ( V_1 ) != F_77 ( V_59 ) )
return false ;
if ( V_59 -> V_102 != V_1 -> V_113 -> V_114 || F_67 ( V_59 ) )
return false ;
if ( F_55 ( V_59 -> V_3 , V_59 , V_1 ) == false )
return false ;
if ( F_48 ( V_59 ) == V_47 &&
! F_82 ( V_59 -> V_1 , V_1 ) )
return false ;
return true ;
}
enum V_115 F_96 ( struct V_58 * V_59 , struct V_1 * V_1 )
{
if ( F_48 ( V_59 ) == V_44 &&
F_97 ( V_59 -> V_3 ) > 1 )
return V_116 ;
else if ( F_63 ( V_59 ) + F_61 ( V_59 ) == V_1 -> V_16 . V_17 )
return V_117 ;
else if ( F_63 ( V_59 ) - F_5 ( V_1 ) == V_1 -> V_16 . V_17 )
return V_118 ;
return V_119 ;
}
