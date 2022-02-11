static inline void F_1 ( enum V_1 V_2 )
{
F_2 ( V_2 ) ;
}
static inline void F_3 ( enum V_1 V_2 , long V_3 )
{
F_4 ( V_2 , V_3 ) ;
}
static unsigned long F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_6 , * V_7 ;
unsigned long V_8 = 0 ;
F_6 (page, next, freelist, lru) {
F_7 ( & V_6 -> V_9 ) ;
F_8 ( V_6 ) ;
V_8 ++ ;
}
return V_8 ;
}
static void F_9 ( struct V_4 * V_10 )
{
struct V_6 * V_6 ;
F_10 (page, list, lru) {
F_11 ( V_6 , 0 ) ;
F_12 ( V_6 , 1 , 1 ) ;
}
}
static inline bool F_13 ( int V_11 )
{
return F_14 ( V_11 ) || V_11 == V_12 ;
}
static struct V_6 * F_15 ( unsigned long V_13 ,
unsigned long V_14 , struct V_15 * V_15 )
{
struct V_6 * V_16 ;
struct V_6 * V_17 ;
V_14 -- ;
if ( ! F_16 ( V_13 ) || ! F_16 ( V_14 ) )
return NULL ;
V_16 = F_17 ( V_13 ) ;
if ( F_18 ( V_16 ) != V_15 )
return NULL ;
V_17 = F_17 ( V_14 ) ;
if ( F_19 ( V_16 ) != F_19 ( V_17 ) )
return NULL ;
return V_16 ;
}
static inline bool F_20 ( struct V_18 * V_19 ,
struct V_6 * V_6 )
{
if ( V_19 -> V_20 )
return true ;
return ! F_21 ( V_6 ) ;
}
static void F_22 ( struct V_15 * V_15 )
{
unsigned long V_13 = V_15 -> V_21 ;
unsigned long V_14 = F_23 ( V_15 ) ;
unsigned long V_22 ;
V_15 -> V_23 [ 0 ] = V_13 ;
V_15 -> V_23 [ 1 ] = V_13 ;
V_15 -> V_24 = V_14 ;
V_15 -> V_25 = false ;
for ( V_22 = V_13 ; V_22 < V_14 ; V_22 += V_26 ) {
struct V_6 * V_6 ;
F_24 () ;
if ( ! F_16 ( V_22 ) )
continue;
V_6 = F_17 ( V_22 ) ;
if ( V_15 != F_18 ( V_6 ) )
continue;
F_25 ( V_6 ) ;
}
}
void F_26 ( T_1 * V_27 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
struct V_15 * V_15 = & V_27 -> V_30 [ V_28 ] ;
if ( ! F_27 ( V_15 ) )
continue;
if ( V_15 -> V_25 )
F_22 ( V_15 ) ;
}
}
static void F_28 ( struct V_18 * V_19 ,
struct V_6 * V_6 , unsigned long V_31 ,
bool V_32 )
{
struct V_15 * V_15 = V_19 -> V_15 ;
unsigned long V_22 ;
if ( V_19 -> V_20 )
return;
if ( ! V_6 )
return;
if ( V_31 )
return;
F_29 ( V_6 ) ;
V_22 = F_30 ( V_6 ) ;
if ( V_32 ) {
if ( V_19 -> V_33 )
return;
if ( V_22 > V_15 -> V_23 [ 0 ] )
V_15 -> V_23 [ 0 ] = V_22 ;
if ( V_19 -> V_34 != V_35 &&
V_22 > V_15 -> V_23 [ 1 ] )
V_15 -> V_23 [ 1 ] = V_22 ;
} else {
if ( V_19 -> V_36 )
return;
if ( V_22 < V_15 -> V_24 )
V_15 -> V_24 = V_22 ;
}
}
static inline bool F_20 ( struct V_18 * V_19 ,
struct V_6 * V_6 )
{
return true ;
}
static void F_28 ( struct V_18 * V_19 ,
struct V_6 * V_6 , unsigned long V_31 ,
bool V_32 )
{
}
static bool F_31 ( T_2 * V_37 , unsigned long * V_38 ,
struct V_18 * V_19 )
{
if ( V_19 -> V_34 == V_35 ) {
if ( ! F_32 ( V_37 , * V_38 ) ) {
V_19 -> V_39 = V_40 ;
return false ;
}
} else {
F_33 ( V_37 , * V_38 ) ;
}
return true ;
}
static bool F_34 ( T_2 * V_37 ,
unsigned long V_38 , bool * V_41 , struct V_18 * V_19 )
{
if ( * V_41 ) {
F_35 ( V_37 , V_38 ) ;
* V_41 = false ;
}
if ( F_36 ( V_42 ) ) {
V_19 -> V_39 = V_43 ;
return true ;
}
if ( F_37 () ) {
if ( V_19 -> V_34 == V_35 ) {
V_19 -> V_39 = V_43 ;
return true ;
}
F_24 () ;
}
return false ;
}
static inline bool F_38 ( struct V_18 * V_19 )
{
if ( F_37 () ) {
if ( V_19 -> V_34 == V_35 ) {
V_19 -> V_39 = V_43 ;
return true ;
}
F_24 () ;
}
return false ;
}
static bool F_39 ( struct V_6 * V_6 )
{
if ( F_40 ( V_6 ) ) {
if ( F_41 ( V_6 ) >= V_44 )
return false ;
}
if ( F_13 ( F_42 ( V_6 ) ) )
return true ;
return false ;
}
static unsigned long F_43 ( struct V_18 * V_19 ,
unsigned long * V_13 ,
unsigned long V_14 ,
struct V_4 * V_5 ,
bool V_45 )
{
int V_46 = 0 , V_47 = 0 ;
struct V_6 * V_48 , * V_49 = NULL ;
unsigned long V_38 = 0 ;
bool V_41 = false ;
unsigned long V_50 = * V_13 ;
V_48 = F_17 ( V_50 ) ;
for (; V_50 < V_14 ; V_50 ++ , V_48 ++ ) {
int V_51 , V_52 ;
struct V_6 * V_6 = V_48 ;
if ( ! ( V_50 % V_53 )
&& F_34 ( & V_19 -> V_15 -> V_37 , V_38 ,
& V_41 , V_19 ) )
break;
V_46 ++ ;
if ( ! F_44 ( V_50 ) )
goto V_54;
if ( ! V_49 )
V_49 = V_6 ;
if ( ! F_40 ( V_6 ) )
goto V_54;
if ( ! V_41 ) {
V_41 = F_31 ( & V_19 -> V_15 -> V_37 ,
& V_38 , V_19 ) ;
if ( ! V_41 )
break;
if ( ! F_40 ( V_6 ) )
goto V_54;
}
V_51 = F_45 ( V_6 ) ;
V_47 += V_51 ;
for ( V_52 = 0 ; V_52 < V_51 ; V_52 ++ ) {
F_46 ( & V_6 -> V_9 , V_5 ) ;
V_6 ++ ;
}
if ( V_51 ) {
V_50 += V_51 - 1 ;
V_48 += V_51 - 1 ;
continue;
}
V_54:
if ( V_45 )
break;
else
continue;
}
* V_13 = V_50 ;
F_47 ( V_46 , V_47 ) ;
if ( V_45 && V_50 < V_14 )
V_47 = 0 ;
if ( V_41 )
F_35 ( & V_19 -> V_15 -> V_37 , V_38 ) ;
if ( V_50 == V_14 )
F_28 ( V_19 , V_49 , V_47 , false ) ;
F_3 ( V_55 , V_46 ) ;
if ( V_47 )
F_3 ( V_56 , V_47 ) ;
return V_47 ;
}
unsigned long
F_48 ( struct V_18 * V_19 ,
unsigned long V_13 , unsigned long V_14 )
{
unsigned long V_51 , V_22 , V_57 ;
F_49 ( V_5 ) ;
V_22 = V_13 ;
V_57 = F_50 ( V_22 + 1 , V_26 ) ;
for (; V_22 < V_14 ; V_22 += V_51 ,
V_57 += V_26 ) {
unsigned long V_58 = V_22 ;
V_57 = F_51 ( V_57 , V_14 ) ;
if ( V_22 >= V_57 ) {
V_57 = F_50 ( V_22 + 1 , V_26 ) ;
V_57 = F_51 ( V_57 , V_14 ) ;
}
if ( ! F_15 ( V_22 , V_57 , V_19 -> V_15 ) )
break;
V_51 = F_43 ( V_19 , & V_58 ,
V_57 , & V_5 , true ) ;
if ( ! V_51 )
break;
}
F_9 ( & V_5 ) ;
if ( V_22 < V_14 ) {
F_5 ( & V_5 ) ;
return 0 ;
}
return V_22 ;
}
static void F_52 ( struct V_15 * V_15 , struct V_18 * V_19 )
{
struct V_6 * V_6 ;
unsigned int V_8 [ 2 ] = { 0 , } ;
if ( F_53 ( & V_19 -> V_59 ) )
return;
F_10 (page, &cc->migratepages, lru)
V_8 [ ! ! F_54 ( V_6 ) ] ++ ;
F_55 ( V_15 , V_60 , V_8 [ 0 ] ) ;
F_55 ( V_15 , V_61 , V_8 [ 1 ] ) ;
}
static bool F_56 ( struct V_15 * V_15 )
{
unsigned long V_62 , V_63 , V_51 ;
V_63 = F_57 ( V_15 , V_64 ) +
F_57 ( V_15 , V_65 ) ;
V_62 = F_57 ( V_15 , V_66 ) +
F_57 ( V_15 , V_67 ) ;
V_51 = F_57 ( V_15 , V_61 ) +
F_57 ( V_15 , V_60 ) ;
return V_51 > ( V_63 + V_62 ) / 2 ;
}
static unsigned long
F_58 ( struct V_18 * V_19 , unsigned long V_68 ,
unsigned long V_14 , T_3 V_69 )
{
struct V_15 * V_15 = V_19 -> V_15 ;
unsigned long V_46 = 0 , V_31 = 0 ;
struct V_4 * V_70 = & V_19 -> V_59 ;
struct V_71 * V_71 ;
unsigned long V_38 = 0 ;
bool V_41 = false ;
struct V_6 * V_6 = NULL , * V_49 = NULL ;
while ( F_59 ( F_56 ( V_15 ) ) ) {
if ( V_19 -> V_34 == V_35 )
return 0 ;
F_60 ( V_72 , V_73 / 10 ) ;
if ( F_36 ( V_42 ) )
return 0 ;
}
if ( F_38 ( V_19 ) )
return 0 ;
for (; V_68 < V_14 ; V_68 ++ ) {
if ( ! ( V_68 % V_53 )
&& F_34 ( & V_15 -> V_74 , V_38 ,
& V_41 , V_19 ) )
break;
if ( ! F_44 ( V_68 ) )
continue;
V_46 ++ ;
V_6 = F_17 ( V_68 ) ;
if ( ! V_49 )
V_49 = V_6 ;
if ( F_40 ( V_6 ) ) {
unsigned long V_75 = F_41 ( V_6 ) ;
if ( V_75 > 0 && V_75 < V_76 )
V_68 += ( 1UL << V_75 ) - 1 ;
continue;
}
if ( ! F_61 ( V_6 ) ) {
if ( F_59 ( F_62 ( V_6 ) ) ) {
if ( F_63 ( V_6 ) ) {
goto V_77;
}
}
continue;
}
if ( F_64 ( V_6 ) ) {
if ( ! V_41 )
V_68 = F_50 ( V_68 + 1 ,
V_26 ) - 1 ;
else
V_68 += ( 1 << F_65 ( V_6 ) ) - 1 ;
continue;
}
if ( ! F_66 ( V_6 ) &&
F_67 ( V_6 ) > F_68 ( V_6 ) )
continue;
if ( ! V_41 ) {
V_41 = F_31 ( & V_15 -> V_74 ,
& V_38 , V_19 ) ;
if ( ! V_41 )
break;
if ( ! F_61 ( V_6 ) )
continue;
if ( F_64 ( V_6 ) ) {
V_68 += ( 1 << F_65 ( V_6 ) ) - 1 ;
continue;
}
}
V_71 = F_69 ( V_6 , V_15 ) ;
if ( F_70 ( V_6 , V_69 ) != 0 )
continue;
F_71 ( F_72 ( V_6 ) , V_6 ) ;
F_73 ( V_6 , V_71 , F_74 ( V_6 ) ) ;
V_77:
V_19 -> V_33 = true ;
F_46 ( & V_6 -> V_9 , V_70 ) ;
V_19 -> V_78 ++ ;
V_31 ++ ;
if ( V_19 -> V_78 == V_79 ) {
++ V_68 ;
break;
}
}
if ( F_59 ( V_68 > V_14 ) )
V_68 = V_14 ;
if ( V_41 )
F_35 ( & V_15 -> V_74 , V_38 ) ;
if ( V_68 == V_14 )
F_28 ( V_19 , V_49 , V_31 , true ) ;
F_75 ( V_46 , V_31 ) ;
F_3 ( V_80 , V_46 ) ;
if ( V_31 )
F_3 ( V_56 , V_31 ) ;
return V_68 ;
}
unsigned long
F_76 ( struct V_18 * V_19 , unsigned long V_13 ,
unsigned long V_14 )
{
unsigned long V_22 , V_57 ;
V_22 = V_13 ;
V_57 = F_50 ( V_22 + 1 , V_26 ) ;
for (; V_22 < V_14 ; V_22 = V_57 ,
V_57 += V_26 ) {
V_57 = F_51 ( V_57 , V_14 ) ;
if ( ! F_15 ( V_22 , V_57 , V_19 -> V_15 ) )
continue;
V_22 = F_58 ( V_19 , V_22 , V_57 ,
V_81 ) ;
if ( ! V_22 ) {
F_77 ( & V_19 -> V_59 ) ;
V_19 -> V_78 = 0 ;
break;
}
if ( V_19 -> V_78 == V_79 )
break;
}
F_52 ( V_19 -> V_15 , V_19 ) ;
return V_22 ;
}
static void F_78 ( struct V_18 * V_19 )
{
struct V_15 * V_15 = V_19 -> V_15 ;
struct V_6 * V_6 ;
unsigned long V_82 ;
unsigned long V_58 ;
unsigned long V_57 ;
unsigned long V_68 ;
int V_83 = V_19 -> V_83 ;
struct V_4 * V_5 = & V_19 -> V_84 ;
V_58 = V_19 -> V_85 ;
V_82 = V_19 -> V_85 & ~ ( V_26 - 1 ) ;
V_57 = F_51 ( V_82 + V_26 ,
F_23 ( V_15 ) ) ;
V_68 = F_50 ( V_19 -> V_86 + 1 , V_26 ) ;
for (; V_82 >= V_68 && V_19 -> V_78 > V_83 ;
V_57 = V_82 ,
V_82 -= V_26 ,
V_58 = V_82 ) {
unsigned long V_51 ;
if ( ! ( V_82 % ( V_53 * V_26 ) )
&& F_38 ( V_19 ) )
break;
V_6 = F_15 ( V_82 , V_57 ,
V_15 ) ;
if ( ! V_6 )
continue;
if ( ! F_39 ( V_6 ) )
continue;
if ( ! F_20 ( V_19 , V_6 ) )
continue;
V_51 = F_43 ( V_19 , & V_58 ,
V_57 , V_5 , false ) ;
V_83 += V_51 ;
V_19 -> V_85 = ( V_58 < V_57 ) ?
V_58 :
V_82 - V_26 ;
if ( V_51 )
V_19 -> V_36 = true ;
if ( V_19 -> V_39 )
break;
}
F_9 ( V_5 ) ;
if ( V_82 < V_68 )
V_19 -> V_85 = V_19 -> V_86 ;
V_19 -> V_83 = V_83 ;
}
static struct V_6 * F_79 ( struct V_6 * V_87 ,
unsigned long V_88 ,
int * * V_89 )
{
struct V_18 * V_19 = (struct V_18 * ) V_88 ;
struct V_6 * V_90 ;
if ( F_53 ( & V_19 -> V_84 ) ) {
if ( ! V_19 -> V_39 )
F_78 ( V_19 ) ;
if ( F_53 ( & V_19 -> V_84 ) )
return NULL ;
}
V_90 = F_80 ( V_19 -> V_84 . V_7 , struct V_6 , V_9 ) ;
F_7 ( & V_90 -> V_9 ) ;
V_19 -> V_83 -- ;
return V_90 ;
}
static void F_81 ( struct V_6 * V_6 , unsigned long V_88 )
{
struct V_18 * V_19 = (struct V_18 * ) V_88 ;
F_46 ( & V_6 -> V_9 , & V_19 -> V_84 ) ;
V_19 -> V_83 ++ ;
}
static T_4 F_82 ( struct V_15 * V_15 ,
struct V_18 * V_19 )
{
unsigned long V_68 , V_14 ;
struct V_6 * V_6 ;
const T_3 V_69 =
( V_19 -> V_34 == V_35 ? V_91 : 0 ) ;
V_68 = V_19 -> V_86 ;
V_14 = F_50 ( V_68 + 1 , V_26 ) ;
for (; V_14 <= V_19 -> V_85 ;
V_68 = V_14 , V_14 += V_26 ) {
if ( ! ( V_68 % ( V_53 * V_26 ) )
&& F_38 ( V_19 ) )
break;
V_6 = F_15 ( V_68 , V_14 , V_15 ) ;
if ( ! V_6 )
continue;
if ( ! F_20 ( V_19 , V_6 ) )
continue;
if ( V_19 -> V_34 == V_35 &&
! F_13 ( F_42 ( V_6 ) ) )
continue;
V_68 = F_58 ( V_19 , V_68 , V_14 ,
V_69 ) ;
if ( ! V_68 || V_19 -> V_39 )
return V_92 ;
break;
}
F_52 ( V_15 , V_19 ) ;
V_19 -> V_86 = ( V_14 <= V_19 -> V_85 ) ? V_68 : V_19 -> V_85 ;
return V_19 -> V_78 ? V_93 : V_94 ;
}
static int F_83 ( struct V_15 * V_15 , struct V_18 * V_19 ,
const int V_11 )
{
unsigned int V_95 ;
unsigned long V_96 ;
if ( V_19 -> V_39 || F_36 ( V_42 ) )
return V_97 ;
if ( V_19 -> V_85 <= V_19 -> V_86 ) {
V_15 -> V_23 [ 0 ] = V_15 -> V_21 ;
V_15 -> V_23 [ 1 ] = V_15 -> V_21 ;
V_15 -> V_24 = F_23 ( V_15 ) ;
if ( ! F_84 () )
V_15 -> V_25 = true ;
return V_98 ;
}
if ( V_19 -> V_95 == - 1 )
return V_99 ;
V_96 = F_85 ( V_15 ) ;
V_96 += ( 1 << V_19 -> V_95 ) ;
if ( ! F_86 ( V_15 , V_19 -> V_95 , V_96 , 0 , 0 ) )
return V_99 ;
for ( V_95 = V_19 -> V_95 ; V_95 < V_76 ; V_95 ++ ) {
struct V_100 * V_101 = & V_15 -> V_100 [ V_95 ] ;
if ( ! F_53 ( & V_101 -> V_102 [ V_11 ] ) )
return V_97 ;
if ( V_19 -> V_95 >= V_44 && V_101 -> V_103 )
return V_97 ;
}
return V_99 ;
}
unsigned long F_87 ( struct V_15 * V_15 , int V_95 )
{
int V_104 ;
unsigned long V_96 ;
if ( V_95 == - 1 )
return V_99 ;
V_96 = F_85 ( V_15 ) + ( 2UL << V_95 ) ;
if ( ! F_86 ( V_15 , 0 , V_96 , 0 , 0 ) )
return V_105 ;
V_104 = F_88 ( V_15 , V_95 ) ;
if ( V_104 >= 0 && V_104 <= V_106 )
return V_105 ;
if ( V_104 == - 1000 && F_86 ( V_15 , V_95 , V_96 ,
0 , 0 ) )
return V_97 ;
return V_99 ;
}
static int F_89 ( struct V_15 * V_15 , struct V_18 * V_19 )
{
int V_107 ;
unsigned long V_13 = V_15 -> V_21 ;
unsigned long V_14 = F_23 ( V_15 ) ;
const int V_11 = F_90 ( V_19 -> V_108 ) ;
const bool V_109 = V_19 -> V_34 != V_35 ;
V_107 = F_87 ( V_15 , V_19 -> V_95 ) ;
switch ( V_107 ) {
case V_97 :
case V_105 :
return V_107 ;
case V_99 :
;
}
if ( F_91 ( V_15 , V_19 -> V_95 ) && ! F_84 () )
F_22 ( V_15 ) ;
V_19 -> V_86 = V_15 -> V_23 [ V_109 ] ;
V_19 -> V_85 = V_15 -> V_24 ;
if ( V_19 -> V_85 < V_13 || V_19 -> V_85 > V_14 ) {
V_19 -> V_85 = V_14 & ~ ( V_26 - 1 ) ;
V_15 -> V_24 = V_19 -> V_85 ;
}
if ( V_19 -> V_86 < V_13 || V_19 -> V_86 > V_14 ) {
V_19 -> V_86 = V_13 ;
V_15 -> V_23 [ 0 ] = V_19 -> V_86 ;
V_15 -> V_23 [ 1 ] = V_19 -> V_86 ;
}
F_92 ( V_13 , V_19 -> V_86 , V_19 -> V_85 , V_14 ) ;
F_93 () ;
while ( ( V_107 = F_83 ( V_15 , V_19 , V_11 ) ) ==
V_99 ) {
int V_110 ;
switch ( F_82 ( V_15 , V_19 ) ) {
case V_92 :
V_107 = V_97 ;
F_77 ( & V_19 -> V_59 ) ;
V_19 -> V_78 = 0 ;
goto V_111;
case V_94 :
continue;
case V_93 :
;
}
V_110 = F_94 ( & V_19 -> V_59 , F_79 ,
F_81 , ( unsigned long ) V_19 , V_19 -> V_34 ,
V_112 ) ;
F_95 ( V_19 -> V_78 , V_110 ,
& V_19 -> V_59 ) ;
V_19 -> V_78 = 0 ;
if ( V_110 ) {
F_77 ( & V_19 -> V_59 ) ;
if ( V_110 == - V_113 && V_19 -> V_85 > V_19 -> V_86 ) {
V_107 = V_97 ;
goto V_111;
}
}
}
V_111:
V_19 -> V_83 -= F_5 ( & V_19 -> V_84 ) ;
F_96 ( V_19 -> V_83 != 0 ) ;
F_97 ( V_107 ) ;
return V_107 ;
}
static unsigned long F_98 ( struct V_15 * V_15 , int V_95 ,
T_5 V_108 , enum V_114 V_34 , int * V_39 )
{
unsigned long V_107 ;
struct V_18 V_19 = {
. V_83 = 0 ,
. V_78 = 0 ,
. V_95 = V_95 ,
. V_108 = V_108 ,
. V_15 = V_15 ,
. V_34 = V_34 ,
} ;
F_99 ( & V_19 . V_84 ) ;
F_99 ( & V_19 . V_59 ) ;
V_107 = F_89 ( V_15 , & V_19 ) ;
F_96 ( ! F_53 ( & V_19 . V_84 ) ) ;
F_96 ( ! F_53 ( & V_19 . V_59 ) ) ;
* V_39 = V_19 . V_39 ;
return V_107 ;
}
unsigned long F_100 ( struct V_115 * V_115 ,
int V_95 , T_5 V_108 , T_6 * V_116 ,
enum V_114 V_34 , int * V_39 ,
struct V_15 * * V_117 )
{
enum V_118 V_119 = F_101 ( V_108 ) ;
int V_120 = V_108 & V_121 ;
int V_122 = V_108 & V_123 ;
struct V_124 * V_125 ;
struct V_15 * V_15 ;
int V_126 = V_127 ;
int V_128 = 0 ;
int V_129 = V_40 ;
* V_39 = V_130 ;
if ( ! V_95 || ! V_120 || ! V_122 )
return V_105 ;
#ifdef F_102
if ( F_90 ( V_108 ) == V_12 )
V_128 |= V_131 ;
#endif
F_103 (zone, z, zonelist, high_zoneidx,
nodemask) {
int V_132 ;
int V_133 ;
if ( F_104 ( V_15 , V_95 ) )
continue;
V_132 = F_98 ( V_15 , V_95 , V_108 , V_34 ,
& V_133 ) ;
V_126 = F_105 ( V_132 , V_126 ) ;
V_129 &= V_133 ;
if ( F_86 ( V_15 , V_95 , F_85 ( V_15 ) , 0 ,
V_128 ) ) {
* V_117 = V_15 ;
F_106 ( V_15 , V_95 , false ) ;
if ( V_133 == V_43 )
* V_39 = V_43 ;
goto V_134;
}
if ( V_34 != V_35 ) {
F_107 ( V_15 , V_95 ) ;
}
if ( ( V_133 == V_43 )
|| F_36 ( V_42 ) ) {
* V_39 = V_43 ;
goto V_134;
}
continue;
V_134:
V_129 = 0 ;
break;
}
if ( V_126 > V_105 && V_129 )
* V_39 = V_40 ;
return V_126 ;
}
static void F_108 ( T_1 * V_27 , struct V_18 * V_19 )
{
int V_28 ;
struct V_15 * V_15 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
V_15 = & V_27 -> V_30 [ V_28 ] ;
if ( ! F_27 ( V_15 ) )
continue;
V_19 -> V_83 = 0 ;
V_19 -> V_78 = 0 ;
V_19 -> V_15 = V_15 ;
F_99 ( & V_19 -> V_84 ) ;
F_99 ( & V_19 -> V_59 ) ;
if ( V_19 -> V_95 == - 1 || ! F_104 ( V_15 , V_19 -> V_95 ) )
F_89 ( V_15 , V_19 ) ;
if ( V_19 -> V_95 > 0 ) {
if ( F_86 ( V_15 , V_19 -> V_95 ,
F_85 ( V_15 ) , 0 , 0 ) )
F_106 ( V_15 , V_19 -> V_95 , false ) ;
}
F_96 ( ! F_53 ( & V_19 -> V_84 ) ) ;
F_96 ( ! F_53 ( & V_19 -> V_59 ) ) ;
}
}
void F_109 ( T_1 * V_27 , int V_95 )
{
struct V_18 V_19 = {
. V_95 = V_95 ,
. V_34 = V_35 ,
} ;
if ( ! V_95 )
return;
F_108 ( V_27 , & V_19 ) ;
}
static void F_110 ( int V_135 )
{
struct V_18 V_19 = {
. V_95 = - 1 ,
. V_34 = V_136 ,
. V_20 = true ,
} ;
F_108 ( F_111 ( V_135 ) , & V_19 ) ;
}
static void F_112 ( void )
{
int V_135 ;
F_113 () ;
F_114 (nid)
F_110 ( V_135 ) ;
}
int F_115 ( struct V_137 * V_138 , int V_139 ,
void T_7 * V_140 , T_8 * V_141 , T_9 * V_142 )
{
if ( V_139 )
F_112 () ;
return 0 ;
}
int F_116 ( struct V_137 * V_138 , int V_139 ,
void T_7 * V_140 , T_8 * V_141 , T_9 * V_142 )
{
F_117 ( V_138 , V_139 , V_140 , V_141 , V_142 ) ;
return 0 ;
}
static T_10 F_118 ( struct V_143 * V_144 ,
struct V_145 * V_146 ,
const char * V_147 , T_8 V_8 )
{
int V_135 = V_144 -> V_148 ;
if ( V_135 >= 0 && V_135 < V_149 && F_119 ( V_135 ) ) {
F_113 () ;
F_110 ( V_135 ) ;
}
return V_8 ;
}
int F_120 ( struct V_150 * V_150 )
{
return F_121 ( & V_150 -> V_144 , & V_151 ) ;
}
void F_122 ( struct V_150 * V_150 )
{
return F_123 ( & V_150 -> V_144 , & V_151 ) ;
}
