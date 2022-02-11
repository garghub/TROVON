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
F_14 (bv, bio, iter) {
if ( V_27 && F_15 ( V_3 , V_27 , V_25 . V_36 ) )
goto V_37;
if ( V_21 + ( V_25 . V_38 >> 9 ) > V_35 ) {
if ( V_6 < F_16 ( V_3 ) &&
V_21 < V_35 ) {
V_6 ++ ;
V_21 = V_35 ;
}
if ( V_21 )
goto V_37;
}
if ( V_27 && F_17 ( V_3 ) ) {
if ( V_30 + V_25 . V_38 > F_18 ( V_3 ) )
goto V_39;
if ( ! F_19 ( V_27 , & V_25 ) )
goto V_39;
if ( ! F_20 ( V_3 , V_27 , & V_25 ) )
goto V_39;
V_30 += V_25 . V_38 ;
V_26 = V_25 ;
V_27 = & V_26 ;
V_21 += V_25 . V_38 >> 9 ;
if ( V_6 == 1 && V_30 > V_31 )
V_31 = V_30 ;
continue;
}
V_39:
if ( V_6 == F_16 ( V_3 ) )
goto V_37;
V_6 ++ ;
V_26 = V_25 ;
V_27 = & V_26 ;
V_30 = V_25 . V_38 ;
V_21 += V_25 . V_38 >> 9 ;
if ( V_6 == 1 && V_30 > V_31 )
V_31 = V_30 ;
}
V_33 = false ;
V_37:
* V_23 = V_6 ;
if ( V_33 ) {
V_34 = F_7 ( V_1 , V_21 , V_18 , V_5 ) ;
if ( V_34 )
V_1 = V_34 ;
}
V_1 -> V_32 = V_31 ;
if ( V_30 > V_1 -> V_40 )
V_1 -> V_40 = V_30 ;
return V_33 ? V_34 : NULL ;
}
void F_21 ( struct V_2 * V_3 , struct V_1 * * V_1 )
{
struct V_1 * V_37 , * V_41 ;
unsigned V_6 ;
switch ( F_22 ( * V_1 ) ) {
case V_42 :
case V_43 :
V_37 = F_1 ( V_3 , * V_1 , V_3 -> F_7 , & V_6 ) ;
break;
case V_44 :
V_37 = F_8 ( V_3 , * V_1 , V_3 -> F_7 , & V_6 ) ;
break;
case V_45 :
V_37 = F_9 ( V_3 , * V_1 , V_3 -> F_7 , & V_6 ) ;
break;
default:
V_37 = F_13 ( V_3 , * V_1 , V_3 -> F_7 , & V_6 ) ;
break;
}
V_41 = V_37 ? V_37 : * V_1 ;
V_41 -> V_46 = V_6 ;
F_23 ( V_41 , V_47 ) ;
if ( V_37 ) {
V_37 -> V_48 |= V_49 ;
F_24 ( V_37 , * V_1 ) ;
F_25 ( V_3 , V_37 , ( * V_1 ) -> V_16 . V_17 ) ;
F_26 ( * V_1 ) ;
* V_1 = V_37 ;
}
}
static unsigned int F_27 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
bool V_50 )
{
struct V_24 V_25 , V_26 = { NULL } ;
int V_51 , V_52 = 0 ;
unsigned int V_30 , V_53 ;
struct V_1 * V_54 , * V_55 ;
struct V_28 V_29 ;
if ( ! V_1 )
return 0 ;
switch ( F_22 ( V_1 ) ) {
case V_42 :
case V_43 :
case V_44 :
return 0 ;
case V_45 :
return 1 ;
}
V_54 = V_1 ;
V_51 = F_17 ( V_3 ) ;
V_30 = 0 ;
V_53 = 0 ;
F_28 (bio) {
F_14 (bv, bio, iter) {
if ( V_50 )
goto V_39;
if ( V_52 && V_51 ) {
if ( V_30 + V_25 . V_38
> F_18 ( V_3 ) )
goto V_39;
if ( ! F_19 ( & V_26 , & V_25 ) )
goto V_39;
if ( ! F_20 ( V_3 , & V_26 , & V_25 ) )
goto V_39;
V_30 += V_25 . V_38 ;
V_26 = V_25 ;
continue;
}
V_39:
if ( V_53 == 1 && V_30 >
V_54 -> V_32 )
V_54 -> V_32 = V_30 ;
V_53 ++ ;
V_26 = V_25 ;
V_52 = 1 ;
V_30 = V_25 . V_38 ;
}
V_55 = V_1 ;
}
if ( V_53 == 1 && V_30 > V_54 -> V_32 )
V_54 -> V_32 = V_30 ;
if ( V_30 > V_55 -> V_40 )
V_55 -> V_40 = V_30 ;
return V_53 ;
}
void F_29 ( struct V_56 * V_57 )
{
bool V_50 = ! ! F_30 ( V_58 ,
& V_57 -> V_3 -> V_59 ) ;
V_57 -> V_60 = F_27 ( V_57 -> V_3 , V_57 -> V_1 ,
V_50 ) ;
}
void F_31 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
unsigned short V_61 ;
if ( F_32 ( V_1 , V_62 ) )
V_61 = F_33 ( V_1 ) ;
else
V_61 = V_1 -> V_63 ;
if ( F_30 ( V_58 , & V_3 -> V_59 ) &&
( V_61 < F_16 ( V_3 ) ) )
V_1 -> V_46 = V_61 ;
else {
struct V_1 * V_64 = V_1 -> V_65 ;
V_1 -> V_65 = NULL ;
V_1 -> V_46 = F_27 ( V_3 , V_1 , false ) ;
V_1 -> V_65 = V_64 ;
}
F_23 ( V_1 , V_47 ) ;
}
static int F_34 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_1 * V_64 )
{
struct V_24 V_66 = { NULL } , V_67 ;
if ( ! F_17 ( V_3 ) )
return 0 ;
if ( V_1 -> V_40 + V_64 -> V_32 >
F_18 ( V_3 ) )
return 0 ;
if ( ! F_35 ( V_1 ) )
return 1 ;
F_36 ( V_1 , & V_66 ) ;
F_37 ( V_64 , & V_67 ) ;
if ( ! F_19 ( & V_66 , & V_67 ) )
return 0 ;
if ( F_20 ( V_3 , & V_66 , & V_67 ) )
return 1 ;
return 0 ;
}
static inline void
F_38 ( struct V_2 * V_3 , struct V_24 * V_68 ,
struct V_69 * V_70 , struct V_24 * V_26 ,
struct V_69 * * V_71 , int * V_6 , int * V_51 )
{
int V_72 = V_68 -> V_38 ;
if ( * V_71 && * V_51 ) {
if ( ( * V_71 ) -> V_73 + V_72 > F_18 ( V_3 ) )
goto V_39;
if ( ! F_19 ( V_26 , V_68 ) )
goto V_39;
if ( ! F_20 ( V_3 , V_26 , V_68 ) )
goto V_39;
( * V_71 ) -> V_73 += V_72 ;
} else {
V_39:
if ( ! * V_71 )
* V_71 = V_70 ;
else {
F_39 ( * V_71 ) ;
* V_71 = F_40 ( * V_71 ) ;
}
F_41 ( * V_71 , V_68 -> V_74 , V_72 , V_68 -> V_36 ) ;
( * V_6 ) ++ ;
}
* V_26 = * V_68 ;
}
static inline int F_42 ( struct V_2 * V_3 , struct V_24 V_25 ,
struct V_69 * V_70 , struct V_69 * * V_71 )
{
* V_71 = V_70 ;
F_41 ( * V_71 , V_25 . V_74 , V_25 . V_38 , V_25 . V_36 ) ;
return 1 ;
}
static int F_43 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_69 * V_70 ,
struct V_69 * * V_71 )
{
struct V_24 V_68 , V_26 = { NULL } ;
struct V_28 V_29 ;
int V_51 = F_17 ( V_3 ) , V_6 = 0 ;
F_28 (bio)
F_14 (bvec, bio, iter)
F_38 ( V_3 , & V_68 , V_70 , & V_26 , V_71 ,
& V_6 , & V_51 ) ;
return V_6 ;
}
int F_44 ( struct V_2 * V_3 , struct V_56 * V_57 ,
struct V_69 * V_70 )
{
struct V_69 * V_71 = NULL ;
int V_6 = 0 ;
if ( V_57 -> V_75 & V_76 )
V_6 = F_42 ( V_3 , V_57 -> V_77 , V_70 , & V_71 ) ;
else if ( V_57 -> V_1 && F_22 ( V_57 -> V_1 ) == V_45 )
V_6 = F_42 ( V_3 , F_45 ( V_57 -> V_1 ) , V_70 , & V_71 ) ;
else if ( V_57 -> V_1 )
V_6 = F_43 ( V_3 , V_57 -> V_1 , V_70 , & V_71 ) ;
if ( F_4 ( V_57 -> V_75 & V_78 ) &&
( F_46 ( V_57 ) & V_3 -> V_79 ) ) {
unsigned int V_80 =
( V_3 -> V_79 & ~ F_46 ( V_57 ) ) + 1 ;
V_71 -> V_73 += V_80 ;
V_57 -> V_81 += V_80 ;
}
if ( V_3 -> V_82 && V_3 -> V_83 ( V_57 ) ) {
if ( F_47 ( F_48 ( V_57 ) ) )
memset ( V_3 -> V_84 , 0 , V_3 -> V_82 ) ;
F_39 ( V_71 ) ;
V_71 = F_40 ( V_71 ) ;
F_41 ( V_71 , F_49 ( V_3 -> V_84 ) ,
V_3 -> V_82 ,
( ( unsigned long ) V_3 -> V_84 ) &
( V_85 - 1 ) ) ;
V_6 ++ ;
V_57 -> V_81 += V_3 -> V_82 ;
}
if ( V_71 )
F_50 ( V_71 ) ;
F_51 ( V_6 > F_52 ( V_57 ) ) ;
return V_6 ;
}
static inline int F_53 ( struct V_2 * V_3 ,
struct V_56 * V_86 ,
struct V_1 * V_1 )
{
int V_53 = F_54 ( V_3 , V_1 ) ;
if ( V_86 -> V_60 + V_53 > F_16 ( V_3 ) )
goto V_87;
if ( F_55 ( V_3 , V_86 , V_1 ) == false )
goto V_87;
V_86 -> V_60 += V_53 ;
return 1 ;
V_87:
F_56 ( V_3 , V_86 ) ;
return 0 ;
}
int F_57 ( struct V_2 * V_3 , struct V_56 * V_86 ,
struct V_1 * V_1 )
{
if ( F_58 ( V_86 , V_1 ) )
return 0 ;
if ( F_59 ( V_86 ) &&
F_60 ( V_86 , V_1 ) )
return 0 ;
if ( F_61 ( V_86 ) + F_5 ( V_1 ) >
F_62 ( V_86 , F_63 ( V_86 ) ) ) {
F_56 ( V_3 , V_86 ) ;
return 0 ;
}
if ( ! F_32 ( V_86 -> V_88 , V_47 ) )
F_31 ( V_3 , V_86 -> V_88 ) ;
if ( ! F_32 ( V_1 , V_47 ) )
F_31 ( V_3 , V_1 ) ;
return F_53 ( V_3 , V_86 , V_1 ) ;
}
int F_64 ( struct V_2 * V_3 , struct V_56 * V_86 ,
struct V_1 * V_1 )
{
if ( F_65 ( V_86 , V_1 ) )
return 0 ;
if ( F_59 ( V_86 ) &&
F_66 ( V_86 , V_1 ) )
return 0 ;
if ( F_61 ( V_86 ) + F_5 ( V_1 ) >
F_62 ( V_86 , V_1 -> V_16 . V_17 ) ) {
F_56 ( V_3 , V_86 ) ;
return 0 ;
}
if ( ! F_32 ( V_1 , V_47 ) )
F_31 ( V_3 , V_1 ) ;
if ( ! F_32 ( V_86 -> V_1 , V_47 ) )
F_31 ( V_3 , V_86 -> V_1 ) ;
return F_53 ( V_3 , V_86 , V_1 ) ;
}
static bool F_67 ( struct V_56 * V_86 )
{
struct V_2 * V_3 = V_86 -> V_3 ;
return ! V_3 -> V_89 && V_86 -> V_90 ;
}
static int F_68 ( struct V_2 * V_3 , struct V_56 * V_86 ,
struct V_56 * V_91 )
{
int V_92 ;
unsigned int V_30 =
V_86 -> V_88 -> V_40 + V_91 -> V_1 -> V_32 ;
if ( F_67 ( V_86 ) || F_67 ( V_91 ) )
return 0 ;
if ( F_58 ( V_86 , V_91 -> V_1 ) )
return 0 ;
if ( ( F_61 ( V_86 ) + F_61 ( V_91 ) ) >
F_62 ( V_86 , F_63 ( V_86 ) ) )
return 0 ;
V_92 = V_86 -> V_60 + V_91 -> V_60 ;
if ( F_34 ( V_3 , V_86 -> V_88 , V_91 -> V_1 ) ) {
if ( V_86 -> V_60 == 1 )
V_86 -> V_1 -> V_32 = V_30 ;
if ( V_91 -> V_60 == 1 )
V_91 -> V_88 -> V_40 = V_30 ;
V_92 -- ;
}
if ( V_92 > F_16 ( V_3 ) )
return 0 ;
if ( F_69 ( V_3 , V_86 , V_91 ) == false )
return 0 ;
V_86 -> V_60 = V_92 ;
return 1 ;
}
void F_70 ( struct V_56 * V_57 )
{
unsigned int V_93 = V_57 -> V_94 & V_95 ;
struct V_1 * V_1 ;
if ( V_57 -> V_75 & V_96 )
return;
for ( V_1 = V_57 -> V_1 ; V_1 ; V_1 = V_1 -> V_65 ) {
F_71 ( ( V_1 -> V_48 & V_95 ) &&
( V_1 -> V_48 & V_95 ) != V_93 ) ;
V_1 -> V_48 |= V_93 ;
}
V_57 -> V_75 |= V_96 ;
}
static void F_72 ( struct V_56 * V_86 )
{
if ( F_73 ( V_86 ) ) {
struct V_97 * V_98 ;
int V_99 ;
V_99 = F_74 () ;
V_98 = V_86 -> V_98 ;
F_75 ( V_86 -> V_3 , V_99 , V_98 ) ;
F_76 ( V_86 -> V_3 , V_98 , F_77 ( V_86 ) ) ;
F_78 ( V_98 ) ;
F_79 () ;
}
}
static struct V_56 * F_80 ( struct V_2 * V_3 ,
struct V_56 * V_86 , struct V_56 * V_91 )
{
if ( ! V_3 -> V_89 )
F_81 ( V_3 -> V_100 ) ;
if ( ! F_82 ( V_86 ) || ! F_82 ( V_91 ) )
return NULL ;
if ( F_48 ( V_86 ) != F_48 ( V_91 ) )
return NULL ;
if ( F_63 ( V_86 ) + F_61 ( V_86 ) != F_63 ( V_91 ) )
return NULL ;
if ( F_77 ( V_86 ) != F_77 ( V_91 )
|| V_86 -> V_101 != V_91 -> V_101
|| F_67 ( V_91 ) )
return NULL ;
if ( F_48 ( V_86 ) == V_45 &&
! F_83 ( V_86 -> V_1 , V_91 -> V_1 ) )
return NULL ;
if ( V_86 -> V_102 != V_91 -> V_102 )
return NULL ;
if ( ! F_68 ( V_3 , V_86 , V_91 ) )
return NULL ;
if ( ( ( V_86 -> V_75 | V_91 -> V_75 ) & V_96 ) ||
( V_86 -> V_94 & V_95 ) !=
( V_91 -> V_94 & V_95 ) ) {
F_70 ( V_86 ) ;
F_70 ( V_91 ) ;
}
if ( F_84 ( V_86 -> V_103 , V_91 -> V_103 ) )
V_86 -> V_103 = V_91 -> V_103 ;
V_86 -> V_88 -> V_65 = V_91 -> V_1 ;
V_86 -> V_88 = V_91 -> V_88 ;
V_86 -> V_104 += F_46 ( V_91 ) ;
F_85 ( V_3 , V_86 , V_91 ) ;
F_72 ( V_91 ) ;
V_86 -> V_105 = F_86 ( V_86 -> V_105 , V_91 -> V_105 ) ;
if ( F_87 ( V_91 ) )
V_86 -> V_99 = V_91 -> V_99 ;
V_91 -> V_1 = NULL ;
return V_91 ;
}
struct V_56 * F_88 ( struct V_2 * V_3 , struct V_56 * V_57 )
{
struct V_56 * V_91 = F_89 ( V_3 , V_57 ) ;
if ( V_91 )
return F_80 ( V_3 , V_57 , V_91 ) ;
return NULL ;
}
struct V_56 * F_90 ( struct V_2 * V_3 , struct V_56 * V_57 )
{
struct V_56 * V_52 = F_91 ( V_3 , V_57 ) ;
if ( V_52 )
return F_80 ( V_3 , V_52 , V_57 ) ;
return NULL ;
}
int F_92 ( struct V_2 * V_3 , struct V_56 * V_57 ,
struct V_56 * V_91 )
{
struct V_106 * V_107 = V_3 -> V_108 ;
struct V_56 * free ;
if ( ! V_107 -> V_109 && V_107 -> type -> V_110 . V_111 . V_112 )
if ( ! V_107 -> type -> V_110 . V_111 . V_112 ( V_3 , V_57 , V_91 ) )
return 0 ;
free = F_80 ( V_3 , V_57 , V_91 ) ;
if ( free ) {
F_93 ( V_3 , free ) ;
return 1 ;
}
return 0 ;
}
bool F_94 ( struct V_56 * V_57 , struct V_1 * V_1 )
{
if ( ! F_82 ( V_57 ) || ! F_95 ( V_1 ) )
return false ;
if ( F_48 ( V_57 ) != F_22 ( V_1 ) )
return false ;
if ( F_96 ( V_1 ) != F_77 ( V_57 ) )
return false ;
if ( V_57 -> V_101 != V_1 -> V_113 || F_67 ( V_57 ) )
return false ;
if ( F_55 ( V_57 -> V_3 , V_57 , V_1 ) == false )
return false ;
if ( F_48 ( V_57 ) == V_45 &&
! F_83 ( V_57 -> V_1 , V_1 ) )
return false ;
if ( V_57 -> V_102 != V_1 -> V_114 )
return false ;
return true ;
}
enum V_115 F_97 ( struct V_56 * V_57 , struct V_1 * V_1 )
{
if ( F_48 ( V_57 ) == V_42 &&
F_98 ( V_57 -> V_3 ) > 1 )
return V_116 ;
else if ( F_63 ( V_57 ) + F_61 ( V_57 ) == V_1 -> V_16 . V_17 )
return V_117 ;
else if ( F_63 ( V_57 ) - F_5 ( V_1 ) == V_1 -> V_16 . V_17 )
return V_118 ;
return V_119 ;
}
