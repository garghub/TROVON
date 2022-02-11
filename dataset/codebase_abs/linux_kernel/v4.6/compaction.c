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
unsigned long V_9 = F_7 ( V_6 ) ;
F_8 ( & V_6 -> V_10 ) ;
F_9 ( V_6 ) ;
if ( V_9 > V_8 )
V_8 = V_9 ;
}
return V_8 ;
}
static void F_10 ( struct V_4 * V_11 )
{
struct V_6 * V_6 ;
F_11 (page, list, lru) {
F_12 ( V_6 , 0 ) ;
F_13 ( V_6 , 1 , 1 ) ;
F_14 ( V_6 , 0 ) ;
}
}
static inline bool F_15 ( int V_12 )
{
return F_16 ( V_12 ) || V_12 == V_13 ;
}
void F_17 ( struct V_14 * V_14 , int V_15 )
{
V_14 -> V_16 = 0 ;
V_14 -> V_17 ++ ;
if ( V_15 < V_14 -> V_18 )
V_14 -> V_18 = V_15 ;
if ( V_14 -> V_17 > V_19 )
V_14 -> V_17 = V_19 ;
F_18 ( V_14 , V_15 ) ;
}
bool F_19 ( struct V_14 * V_14 , int V_15 )
{
unsigned long V_20 = 1UL << V_14 -> V_17 ;
if ( V_15 < V_14 -> V_18 )
return false ;
if ( ++ V_14 -> V_16 > V_20 )
V_14 -> V_16 = V_20 ;
if ( V_14 -> V_16 >= V_20 )
return false ;
F_20 ( V_14 , V_15 ) ;
return true ;
}
void F_21 ( struct V_14 * V_14 , int V_15 ,
bool V_21 )
{
if ( V_21 ) {
V_14 -> V_16 = 0 ;
V_14 -> V_17 = 0 ;
}
if ( V_15 >= V_14 -> V_18 )
V_14 -> V_18 = V_15 + 1 ;
F_22 ( V_14 , V_15 ) ;
}
bool F_23 ( struct V_14 * V_14 , int V_15 )
{
if ( V_15 < V_14 -> V_18 )
return false ;
return V_14 -> V_17 == V_19 &&
V_14 -> V_16 >= 1UL << V_14 -> V_17 ;
}
static inline bool F_24 ( struct V_22 * V_23 ,
struct V_6 * V_6 )
{
if ( V_23 -> V_24 )
return true ;
return ! F_25 ( V_6 ) ;
}
static void F_26 ( struct V_14 * V_14 )
{
V_14 -> V_25 [ 0 ] = V_14 -> V_26 ;
V_14 -> V_25 [ 1 ] = V_14 -> V_26 ;
V_14 -> V_27 =
F_27 ( F_28 ( V_14 ) - 1 , V_28 ) ;
}
static void F_29 ( struct V_14 * V_14 )
{
unsigned long V_29 = V_14 -> V_26 ;
unsigned long V_30 = F_28 ( V_14 ) ;
unsigned long V_9 ;
V_14 -> V_31 = false ;
for ( V_9 = V_29 ; V_9 < V_30 ; V_9 += V_28 ) {
struct V_6 * V_6 ;
F_30 () ;
if ( ! F_31 ( V_9 ) )
continue;
V_6 = F_32 ( V_9 ) ;
if ( V_14 != F_33 ( V_6 ) )
continue;
F_34 ( V_6 ) ;
}
F_26 ( V_14 ) ;
}
void F_35 ( T_1 * V_32 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
struct V_14 * V_14 = & V_32 -> V_35 [ V_33 ] ;
if ( ! F_36 ( V_14 ) )
continue;
if ( V_14 -> V_31 )
F_29 ( V_14 ) ;
}
}
static void F_37 ( struct V_22 * V_23 ,
struct V_6 * V_6 , unsigned long V_36 ,
bool V_37 )
{
struct V_14 * V_14 = V_23 -> V_14 ;
unsigned long V_9 ;
if ( V_23 -> V_24 )
return;
if ( ! V_6 )
return;
if ( V_36 )
return;
F_38 ( V_6 ) ;
V_9 = F_7 ( V_6 ) ;
if ( V_37 ) {
if ( V_9 > V_14 -> V_25 [ 0 ] )
V_14 -> V_25 [ 0 ] = V_9 ;
if ( V_23 -> V_38 != V_39 &&
V_9 > V_14 -> V_25 [ 1 ] )
V_14 -> V_25 [ 1 ] = V_9 ;
} else {
if ( V_9 < V_14 -> V_27 )
V_14 -> V_27 = V_9 ;
}
}
static inline bool F_24 ( struct V_22 * V_23 ,
struct V_6 * V_6 )
{
return true ;
}
static void F_37 ( struct V_22 * V_23 ,
struct V_6 * V_6 , unsigned long V_36 ,
bool V_37 )
{
}
static bool F_39 ( T_2 * V_40 , unsigned long * V_41 ,
struct V_22 * V_23 )
{
if ( V_23 -> V_38 == V_39 ) {
if ( ! F_40 ( V_40 , * V_41 ) ) {
V_23 -> V_42 = V_43 ;
return false ;
}
} else {
F_41 ( V_40 , * V_41 ) ;
}
return true ;
}
static bool F_42 ( T_2 * V_40 ,
unsigned long V_41 , bool * V_44 , struct V_22 * V_23 )
{
if ( * V_44 ) {
F_43 ( V_40 , V_41 ) ;
* V_44 = false ;
}
if ( F_44 ( V_45 ) ) {
V_23 -> V_42 = V_46 ;
return true ;
}
if ( F_45 () ) {
if ( V_23 -> V_38 == V_39 ) {
V_23 -> V_42 = V_46 ;
return true ;
}
F_30 () ;
}
return false ;
}
static inline bool F_46 ( struct V_22 * V_23 )
{
if ( F_45 () ) {
if ( V_23 -> V_38 == V_39 ) {
V_23 -> V_42 = V_46 ;
return true ;
}
F_30 () ;
}
return false ;
}
static unsigned long F_47 ( struct V_22 * V_23 ,
unsigned long * V_29 ,
unsigned long V_30 ,
struct V_4 * V_5 ,
bool V_47 )
{
int V_48 = 0 , V_49 = 0 ;
struct V_6 * V_50 , * V_51 = NULL ;
unsigned long V_41 = 0 ;
bool V_44 = false ;
unsigned long V_52 = * V_29 ;
V_50 = F_32 ( V_52 ) ;
for (; V_52 < V_30 ; V_52 ++ , V_50 ++ ) {
int V_53 , V_54 ;
struct V_6 * V_6 = V_50 ;
if ( ! ( V_52 % V_55 )
&& F_42 ( & V_23 -> V_14 -> V_40 , V_41 ,
& V_44 , V_23 ) )
break;
V_48 ++ ;
if ( ! F_48 ( V_52 ) )
goto V_56;
if ( ! V_51 )
V_51 = V_6 ;
if ( F_49 ( V_6 ) ) {
unsigned int V_57 = F_50 ( V_6 ) ;
if ( F_51 ( V_57 < V_58 ) ) {
V_52 += ( 1UL << V_57 ) - 1 ;
V_50 += ( 1UL << V_57 ) - 1 ;
}
goto V_56;
}
if ( ! F_52 ( V_6 ) )
goto V_56;
if ( ! V_44 ) {
V_44 = F_39 ( & V_23 -> V_14 -> V_40 ,
& V_41 , V_23 ) ;
if ( ! V_44 )
break;
if ( ! F_52 ( V_6 ) )
goto V_56;
}
V_53 = F_53 ( V_6 ) ;
V_49 += V_53 ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ ) {
F_54 ( & V_6 -> V_10 , V_5 ) ;
V_6 ++ ;
}
if ( V_53 ) {
V_23 -> V_59 += V_53 ;
if ( ! V_47 &&
V_23 -> V_60 <= V_23 -> V_59 ) {
V_52 += V_53 ;
break;
}
V_52 += V_53 - 1 ;
V_50 += V_53 - 1 ;
continue;
}
V_56:
if ( V_47 )
break;
else
continue;
}
if ( F_55 ( V_52 > V_30 ) )
V_52 = V_30 ;
F_56 ( * V_29 , V_52 ,
V_48 , V_49 ) ;
* V_29 = V_52 ;
if ( V_47 && V_52 < V_30 )
V_49 = 0 ;
if ( V_44 )
F_43 ( & V_23 -> V_14 -> V_40 , V_41 ) ;
if ( V_52 == V_30 )
F_37 ( V_23 , V_51 , V_49 , false ) ;
F_3 ( V_61 , V_48 ) ;
if ( V_49 )
F_3 ( V_62 , V_49 ) ;
return V_49 ;
}
unsigned long
F_57 ( struct V_22 * V_23 ,
unsigned long V_29 , unsigned long V_30 )
{
unsigned long V_53 , V_9 , V_63 , V_64 ;
F_58 ( V_5 ) ;
V_9 = V_29 ;
V_63 = V_9 & ~ ( V_28 - 1 ) ;
if ( V_63 < V_23 -> V_14 -> V_26 )
V_63 = V_23 -> V_14 -> V_26 ;
V_64 = F_59 ( V_9 + 1 , V_28 ) ;
for (; V_9 < V_30 ; V_9 += V_53 ,
V_63 = V_64 ,
V_64 += V_28 ) {
unsigned long V_65 = V_9 ;
V_64 = F_60 ( V_64 , V_30 ) ;
if ( V_9 >= V_64 ) {
V_63 = V_9 & ~ ( V_28 - 1 ) ;
V_64 = F_59 ( V_9 + 1 , V_28 ) ;
V_64 = F_60 ( V_64 , V_30 ) ;
}
if ( ! F_61 ( V_63 ,
V_64 , V_23 -> V_14 ) )
break;
V_53 = F_47 ( V_23 , & V_65 ,
V_64 , & V_5 , true ) ;
if ( ! V_53 )
break;
}
F_10 ( & V_5 ) ;
if ( V_9 < V_30 ) {
F_5 ( & V_5 ) ;
return 0 ;
}
return V_9 ;
}
static void F_62 ( struct V_14 * V_14 , struct V_22 * V_23 )
{
struct V_6 * V_6 ;
unsigned int V_66 [ 2 ] = { 0 , } ;
if ( F_63 ( & V_23 -> V_67 ) )
return;
F_11 (page, &cc->migratepages, lru)
V_66 [ ! ! F_64 ( V_6 ) ] ++ ;
F_65 ( V_14 , V_68 , V_66 [ 0 ] ) ;
F_65 ( V_14 , V_69 , V_66 [ 1 ] ) ;
}
static bool F_66 ( struct V_14 * V_14 )
{
unsigned long V_70 , V_71 , V_53 ;
V_71 = F_67 ( V_14 , V_72 ) +
F_67 ( V_14 , V_73 ) ;
V_70 = F_67 ( V_14 , V_74 ) +
F_67 ( V_14 , V_75 ) ;
V_53 = F_67 ( V_14 , V_69 ) +
F_67 ( V_14 , V_68 ) ;
return V_53 > ( V_71 + V_70 ) / 2 ;
}
static unsigned long
F_68 ( struct V_22 * V_23 , unsigned long V_76 ,
unsigned long V_30 , T_3 V_77 )
{
struct V_14 * V_14 = V_23 -> V_14 ;
unsigned long V_48 = 0 , V_36 = 0 ;
struct V_4 * V_78 = & V_23 -> V_67 ;
struct V_79 * V_79 ;
unsigned long V_41 = 0 ;
bool V_44 = false ;
struct V_6 * V_6 = NULL , * V_51 = NULL ;
unsigned long V_29 = V_76 ;
while ( F_55 ( F_66 ( V_14 ) ) ) {
if ( V_23 -> V_38 == V_39 )
return 0 ;
F_69 ( V_80 , V_81 / 10 ) ;
if ( F_44 ( V_45 ) )
return 0 ;
}
if ( F_46 ( V_23 ) )
return 0 ;
for (; V_76 < V_30 ; V_76 ++ ) {
bool V_82 ;
if ( ! ( V_76 % V_55 )
&& F_42 ( & V_14 -> V_83 , V_41 ,
& V_44 , V_23 ) )
break;
if ( ! F_48 ( V_76 ) )
continue;
V_48 ++ ;
V_6 = F_32 ( V_76 ) ;
if ( ! V_51 )
V_51 = V_6 ;
if ( F_52 ( V_6 ) ) {
unsigned long V_84 = F_70 ( V_6 ) ;
if ( V_84 > 0 && V_84 < V_58 )
V_76 += ( 1UL << V_84 ) - 1 ;
continue;
}
V_82 = F_71 ( V_6 ) ;
if ( ! V_82 ) {
if ( F_55 ( F_72 ( V_6 ) ) ) {
if ( F_73 ( V_6 ) ) {
goto V_85;
}
}
}
if ( F_49 ( V_6 ) ) {
unsigned int V_57 = F_50 ( V_6 ) ;
if ( F_51 ( V_57 < V_58 ) )
V_76 += ( 1UL << V_57 ) - 1 ;
continue;
}
if ( ! V_82 )
continue;
if ( ! F_74 ( V_6 ) &&
F_75 ( V_6 ) > F_76 ( V_6 ) )
continue;
if ( ! V_44 ) {
V_44 = F_39 ( & V_14 -> V_83 ,
& V_41 , V_23 ) ;
if ( ! V_44 )
break;
if ( ! F_71 ( V_6 ) )
continue;
if ( F_55 ( F_49 ( V_6 ) ) ) {
V_76 += ( 1UL << F_50 ( V_6 ) ) - 1 ;
continue;
}
}
V_79 = F_77 ( V_6 , V_14 ) ;
if ( F_78 ( V_6 , V_77 ) != 0 )
continue;
F_79 ( F_49 ( V_6 ) , V_6 ) ;
F_80 ( V_6 , V_79 , F_81 ( V_6 ) ) ;
V_85:
F_54 ( & V_6 -> V_10 , V_78 ) ;
V_23 -> V_60 ++ ;
V_36 ++ ;
if ( V_23 -> V_60 == V_86 ) {
++ V_76 ;
break;
}
}
if ( F_55 ( V_76 > V_30 ) )
V_76 = V_30 ;
if ( V_44 )
F_43 ( & V_14 -> V_83 , V_41 ) ;
if ( V_76 == V_30 )
F_37 ( V_23 , V_51 , V_36 , true ) ;
F_82 ( V_29 , V_76 ,
V_48 , V_36 ) ;
F_3 ( V_87 , V_48 ) ;
if ( V_36 )
F_3 ( V_62 , V_36 ) ;
return V_76 ;
}
unsigned long
F_83 ( struct V_22 * V_23 , unsigned long V_29 ,
unsigned long V_30 )
{
unsigned long V_9 , V_63 , V_64 ;
V_9 = V_29 ;
V_63 = V_9 & ~ ( V_28 - 1 ) ;
if ( V_63 < V_23 -> V_14 -> V_26 )
V_63 = V_23 -> V_14 -> V_26 ;
V_64 = F_59 ( V_9 + 1 , V_28 ) ;
for (; V_9 < V_30 ; V_9 = V_64 ,
V_63 = V_64 ,
V_64 += V_28 ) {
V_64 = F_60 ( V_64 , V_30 ) ;
if ( ! F_61 ( V_63 ,
V_64 , V_23 -> V_14 ) )
continue;
V_9 = F_68 ( V_23 , V_9 , V_64 ,
V_88 ) ;
if ( ! V_9 )
break;
if ( V_23 -> V_60 == V_86 )
break;
}
F_62 ( V_23 -> V_14 , V_23 ) ;
return V_9 ;
}
static bool F_84 ( struct V_6 * V_6 )
{
if ( F_52 ( V_6 ) ) {
if ( F_70 ( V_6 ) >= V_89 )
return false ;
}
if ( F_15 ( F_85 ( V_6 ) ) )
return true ;
return false ;
}
static inline bool F_86 ( struct V_22 * V_23 )
{
return ( V_23 -> V_90 >> V_89 )
<= ( V_23 -> V_91 >> V_89 ) ;
}
static void F_87 ( struct V_22 * V_23 )
{
struct V_14 * V_14 = V_23 -> V_14 ;
struct V_6 * V_6 ;
unsigned long V_63 ;
unsigned long V_65 ;
unsigned long V_64 ;
unsigned long V_76 ;
struct V_4 * V_5 = & V_23 -> V_92 ;
V_65 = V_23 -> V_90 ;
V_63 = V_23 -> V_90 & ~ ( V_28 - 1 ) ;
V_64 = F_60 ( V_63 + V_28 ,
F_28 ( V_14 ) ) ;
V_76 = F_59 ( V_23 -> V_91 + 1 , V_28 ) ;
for (; V_63 >= V_76 ;
V_64 = V_63 ,
V_63 -= V_28 ,
V_65 = V_63 ) {
if ( ! ( V_63 % ( V_55 * V_28 ) )
&& F_46 ( V_23 ) )
break;
V_6 = F_61 ( V_63 , V_64 ,
V_14 ) ;
if ( ! V_6 )
continue;
if ( ! F_84 ( V_6 ) )
continue;
if ( ! F_24 ( V_23 , V_6 ) )
continue;
F_47 ( V_23 , & V_65 ,
V_64 , V_5 , false ) ;
if ( ( V_23 -> V_59 >= V_23 -> V_60 )
|| V_23 -> V_42 ) {
if ( V_65 >= V_64 )
V_65 =
V_63 - V_28 ;
break;
} else {
F_88 ( V_65 < V_64 ) ;
}
}
F_10 ( V_5 ) ;
V_23 -> V_90 = V_65 ;
}
static struct V_6 * F_89 ( struct V_6 * V_93 ,
unsigned long V_94 ,
int * * V_95 )
{
struct V_22 * V_23 = (struct V_22 * ) V_94 ;
struct V_6 * V_96 ;
if ( F_63 ( & V_23 -> V_92 ) ) {
if ( ! V_23 -> V_42 )
F_87 ( V_23 ) ;
if ( F_63 ( & V_23 -> V_92 ) )
return NULL ;
}
V_96 = F_90 ( V_23 -> V_92 . V_7 , struct V_6 , V_10 ) ;
F_8 ( & V_96 -> V_10 ) ;
V_23 -> V_59 -- ;
return V_96 ;
}
static void F_91 ( struct V_6 * V_6 , unsigned long V_94 )
{
struct V_22 * V_23 = (struct V_22 * ) V_94 ;
F_54 ( & V_6 -> V_10 , & V_23 -> V_92 ) ;
V_23 -> V_59 ++ ;
}
static T_4 F_92 ( struct V_14 * V_14 ,
struct V_22 * V_23 )
{
unsigned long V_63 ;
unsigned long V_64 ;
unsigned long V_76 ;
unsigned long V_65 ;
struct V_6 * V_6 ;
const T_3 V_77 =
( V_97 ? V_88 : 0 ) |
( V_23 -> V_38 == V_39 ? V_98 : 0 ) ;
V_76 = V_23 -> V_91 ;
V_63 = V_23 -> V_91 & ~ ( V_28 - 1 ) ;
if ( V_63 < V_14 -> V_26 )
V_63 = V_14 -> V_26 ;
V_64 = F_59 ( V_76 + 1 , V_28 ) ;
for (; V_64 <= V_23 -> V_90 ;
V_76 = V_64 ,
V_63 = V_64 ,
V_64 += V_28 ) {
if ( ! ( V_76 % ( V_55 * V_28 ) )
&& F_46 ( V_23 ) )
break;
V_6 = F_61 ( V_63 , V_64 ,
V_14 ) ;
if ( ! V_6 )
continue;
if ( ! F_24 ( V_23 , V_6 ) )
continue;
if ( V_23 -> V_38 == V_39 &&
! F_15 ( F_85 ( V_6 ) ) )
continue;
V_65 = V_76 ;
V_76 = F_68 ( V_23 , V_76 ,
V_64 , V_77 ) ;
if ( ! V_76 || V_23 -> V_42 ) {
F_62 ( V_14 , V_23 ) ;
return V_99 ;
}
if ( V_23 -> V_60 && ! V_23 -> V_100 )
V_23 -> V_100 = V_65 ;
break;
}
F_62 ( V_14 , V_23 ) ;
V_23 -> V_91 = V_76 ;
return V_23 -> V_60 ? V_101 : V_102 ;
}
static inline bool F_93 ( int V_15 )
{
return V_15 == - 1 ;
}
static int F_94 ( struct V_14 * V_14 , struct V_22 * V_23 ,
const int V_12 )
{
unsigned int V_15 ;
unsigned long V_103 ;
if ( V_23 -> V_42 || F_44 ( V_45 ) )
return V_104 ;
if ( F_86 ( V_23 ) ) {
F_26 ( V_14 ) ;
if ( V_23 -> V_105 )
V_14 -> V_31 = true ;
return V_106 ;
}
if ( F_93 ( V_23 -> V_15 ) )
return V_107 ;
V_103 = F_95 ( V_14 ) ;
if ( ! F_96 ( V_14 , V_23 -> V_15 , V_103 , V_23 -> V_108 ,
V_23 -> V_109 ) )
return V_107 ;
for ( V_15 = V_23 -> V_15 ; V_15 < V_58 ; V_15 ++ ) {
struct V_110 * V_111 = & V_14 -> V_110 [ V_15 ] ;
bool V_112 ;
if ( ! F_63 ( & V_111 -> V_113 [ V_12 ] ) )
return V_114 ;
#ifdef F_97
if ( V_12 == V_13 &&
! F_63 ( & V_111 -> V_113 [ V_115 ] ) )
return V_114 ;
#endif
if ( F_98 ( V_111 , V_15 , V_12 ,
true , & V_112 ) != - 1 )
return V_114 ;
}
return V_116 ;
}
static int F_99 ( struct V_14 * V_14 , struct V_22 * V_23 ,
const int V_12 )
{
int V_117 ;
V_117 = F_94 ( V_14 , V_23 , V_12 ) ;
F_100 ( V_14 , V_23 -> V_15 , V_117 ) ;
if ( V_117 == V_116 )
V_117 = V_107 ;
return V_117 ;
}
static unsigned long F_101 ( struct V_14 * V_14 , int V_15 ,
int V_109 , int V_108 )
{
int V_118 ;
unsigned long V_103 ;
if ( F_93 ( V_15 ) )
return V_107 ;
V_103 = F_95 ( V_14 ) ;
if ( F_96 ( V_14 , V_15 , V_103 , V_108 ,
V_109 ) )
return V_114 ;
V_103 += ( 2UL << V_15 ) ;
if ( ! F_96 ( V_14 , 0 , V_103 , V_108 , V_109 ) )
return V_119 ;
V_118 = F_102 ( V_14 , V_15 ) ;
if ( V_118 >= 0 && V_118 <= V_120 )
return V_121 ;
return V_107 ;
}
unsigned long F_103 ( struct V_14 * V_14 , int V_15 ,
int V_109 , int V_108 )
{
unsigned long V_117 ;
V_117 = F_101 ( V_14 , V_15 , V_109 , V_108 ) ;
F_104 ( V_14 , V_15 , V_117 ) ;
if ( V_117 == V_121 )
V_117 = V_119 ;
return V_117 ;
}
static int F_105 ( struct V_14 * V_14 , struct V_22 * V_23 )
{
int V_117 ;
unsigned long V_29 = V_14 -> V_26 ;
unsigned long V_30 = F_28 ( V_14 ) ;
const int V_12 = F_106 ( V_23 -> V_122 ) ;
const bool V_123 = V_23 -> V_38 != V_39 ;
V_117 = F_103 ( V_14 , V_23 -> V_15 , V_23 -> V_109 ,
V_23 -> V_108 ) ;
switch ( V_117 ) {
case V_114 :
case V_119 :
return V_117 ;
case V_107 :
;
}
if ( F_23 ( V_14 , V_23 -> V_15 ) )
F_29 ( V_14 ) ;
V_23 -> V_91 = V_14 -> V_25 [ V_123 ] ;
V_23 -> V_90 = V_14 -> V_27 ;
if ( V_23 -> V_90 < V_29 || V_23 -> V_90 >= V_30 ) {
V_23 -> V_90 = F_27 ( V_30 - 1 , V_28 ) ;
V_14 -> V_27 = V_23 -> V_90 ;
}
if ( V_23 -> V_91 < V_29 || V_23 -> V_91 >= V_30 ) {
V_23 -> V_91 = V_29 ;
V_14 -> V_25 [ 0 ] = V_23 -> V_91 ;
V_14 -> V_25 [ 1 ] = V_23 -> V_91 ;
}
V_23 -> V_100 = 0 ;
F_107 ( V_29 , V_23 -> V_91 ,
V_23 -> V_90 , V_30 , V_123 ) ;
F_108 () ;
while ( ( V_117 = F_99 ( V_14 , V_23 , V_12 ) ) ==
V_107 ) {
int V_124 ;
switch ( F_92 ( V_14 , V_23 ) ) {
case V_99 :
V_117 = V_104 ;
F_109 ( & V_23 -> V_67 ) ;
V_23 -> V_60 = 0 ;
goto V_125;
case V_102 :
goto V_126;
case V_101 :
;
}
V_124 = F_110 ( & V_23 -> V_67 , F_89 ,
F_91 , ( unsigned long ) V_23 , V_23 -> V_38 ,
V_127 ) ;
F_111 ( V_23 -> V_60 , V_124 ,
& V_23 -> V_67 ) ;
V_23 -> V_60 = 0 ;
if ( V_124 ) {
F_109 ( & V_23 -> V_67 ) ;
if ( V_124 == - V_128 && ! F_86 ( V_23 ) ) {
V_117 = V_104 ;
goto V_125;
}
}
V_126:
if ( V_23 -> V_15 > 0 && V_23 -> V_100 ) {
int V_129 ;
unsigned long V_130 =
V_23 -> V_91 & ~ ( ( 1UL << V_23 -> V_15 ) - 1 ) ;
if ( V_23 -> V_100 < V_130 ) {
V_129 = F_112 () ;
F_113 ( V_129 ) ;
F_114 ( V_14 ) ;
F_115 () ;
V_23 -> V_100 = 0 ;
}
}
}
V_125:
if ( V_23 -> V_59 > 0 ) {
unsigned long V_90 = F_5 ( & V_23 -> V_92 ) ;
V_23 -> V_59 = 0 ;
F_88 ( V_90 == 0 ) ;
V_90 &= ~ ( V_28 - 1 ) ;
if ( V_90 > V_14 -> V_27 )
V_14 -> V_27 = V_90 ;
}
F_116 ( V_29 , V_23 -> V_91 ,
V_23 -> V_90 , V_30 , V_123 , V_117 ) ;
if ( V_117 == V_104 )
V_117 = V_114 ;
return V_117 ;
}
static unsigned long F_117 ( struct V_14 * V_14 , int V_15 ,
T_5 V_122 , enum V_131 V_38 , int * V_42 ,
int V_109 , int V_108 )
{
unsigned long V_117 ;
struct V_22 V_23 = {
. V_59 = 0 ,
. V_60 = 0 ,
. V_15 = V_15 ,
. V_122 = V_122 ,
. V_14 = V_14 ,
. V_38 = V_38 ,
. V_109 = V_109 ,
. V_108 = V_108 ,
. V_105 = true ,
} ;
F_118 ( & V_23 . V_92 ) ;
F_118 ( & V_23 . V_67 ) ;
V_117 = F_105 ( V_14 , & V_23 ) ;
F_88 ( ! F_63 ( & V_23 . V_92 ) ) ;
F_88 ( ! F_63 ( & V_23 . V_67 ) ) ;
* V_42 = V_23 . V_42 ;
return V_117 ;
}
unsigned long F_119 ( T_5 V_122 , unsigned int V_15 ,
int V_109 , const struct V_132 * V_133 ,
enum V_131 V_38 , int * V_42 )
{
int V_134 = V_122 & V_135 ;
int V_136 = V_122 & V_137 ;
struct V_138 * V_139 ;
struct V_14 * V_14 ;
int V_140 = V_141 ;
int V_142 = V_43 ;
* V_42 = V_143 ;
if ( ! V_15 || ! V_134 || ! V_136 )
return V_119 ;
F_120 ( V_15 , V_122 , V_38 ) ;
F_121 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
int V_144 ;
int V_145 ;
if ( F_19 ( V_14 , V_15 ) )
continue;
V_144 = F_117 ( V_14 , V_15 , V_122 , V_38 ,
& V_145 , V_109 ,
V_133 -> V_108 ) ;
V_140 = F_122 ( V_144 , V_140 ) ;
V_142 &= V_145 ;
if ( F_96 ( V_14 , V_15 , F_95 ( V_14 ) ,
V_133 -> V_108 , V_109 ) ) {
F_21 ( V_14 , V_15 , false ) ;
if ( V_145 == V_46 )
* V_42 = V_46 ;
goto V_146;
}
if ( V_38 != V_39 && V_144 == V_106 ) {
F_17 ( V_14 , V_15 ) ;
}
if ( ( V_145 == V_46 )
|| F_44 ( V_45 ) ) {
* V_42 = V_46 ;
goto V_146;
}
continue;
V_146:
V_142 = 0 ;
break;
}
if ( V_140 > V_119 && V_142 )
* V_42 = V_43 ;
return V_140 ;
}
static void F_123 ( T_1 * V_32 , struct V_22 * V_23 )
{
int V_33 ;
struct V_14 * V_14 ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
V_14 = & V_32 -> V_35 [ V_33 ] ;
if ( ! F_36 ( V_14 ) )
continue;
V_23 -> V_59 = 0 ;
V_23 -> V_60 = 0 ;
V_23 -> V_14 = V_14 ;
F_118 ( & V_23 -> V_92 ) ;
F_118 ( & V_23 -> V_67 ) ;
if ( F_93 ( V_23 -> V_15 ) )
F_29 ( V_14 ) ;
if ( F_93 ( V_23 -> V_15 ) ||
! F_19 ( V_14 , V_23 -> V_15 ) )
F_105 ( V_14 , V_23 ) ;
F_88 ( ! F_63 ( & V_23 -> V_92 ) ) ;
F_88 ( ! F_63 ( & V_23 -> V_67 ) ) ;
if ( F_93 ( V_23 -> V_15 ) )
continue;
if ( F_96 ( V_14 , V_23 -> V_15 ,
F_95 ( V_14 ) , 0 , 0 ) )
F_21 ( V_14 , V_23 -> V_15 , false ) ;
}
}
void F_124 ( T_1 * V_32 , int V_15 )
{
struct V_22 V_23 = {
. V_15 = V_15 ,
. V_38 = V_39 ,
} ;
if ( ! V_15 )
return;
F_123 ( V_32 , & V_23 ) ;
}
static void F_125 ( int V_147 )
{
struct V_22 V_23 = {
. V_15 = - 1 ,
. V_38 = V_148 ,
. V_24 = true ,
} ;
F_123 ( F_126 ( V_147 ) , & V_23 ) ;
}
static void F_127 ( void )
{
int V_147 ;
F_128 () ;
F_129 (nid)
F_125 ( V_147 ) ;
}
int F_130 ( struct V_149 * V_150 , int V_151 ,
void T_6 * V_152 , T_7 * V_153 , T_8 * V_154 )
{
if ( V_151 )
F_127 () ;
return 0 ;
}
int F_131 ( struct V_149 * V_150 , int V_151 ,
void T_6 * V_152 , T_7 * V_153 , T_8 * V_154 )
{
F_132 ( V_150 , V_151 , V_152 , V_153 , V_154 ) ;
return 0 ;
}
static T_9 F_133 ( struct V_155 * V_156 ,
struct V_157 * V_158 ,
const char * V_159 , T_7 V_66 )
{
int V_147 = V_156 -> V_160 ;
if ( V_147 >= 0 && V_147 < V_161 && F_134 ( V_147 ) ) {
F_128 () ;
F_125 ( V_147 ) ;
}
return V_66 ;
}
int F_135 ( struct V_162 * V_162 )
{
return F_136 ( & V_162 -> V_156 , & V_163 ) ;
}
void F_137 ( struct V_162 * V_162 )
{
return F_138 ( & V_162 -> V_156 , & V_163 ) ;
}
static inline bool F_139 ( T_1 * V_32 )
{
return V_32 -> V_164 > 0 || F_140 () ;
}
static bool F_141 ( T_1 * V_32 )
{
int V_33 ;
struct V_14 * V_14 ;
enum V_165 V_108 = V_32 -> V_166 ;
for ( V_33 = 0 ; V_33 < V_108 ; V_33 ++ ) {
V_14 = & V_32 -> V_35 [ V_33 ] ;
if ( ! F_36 ( V_14 ) )
continue;
if ( F_103 ( V_14 , V_32 -> V_164 , 0 ,
V_108 ) == V_107 )
return true ;
}
return false ;
}
static void F_142 ( T_1 * V_32 )
{
int V_33 ;
struct V_14 * V_14 ;
struct V_22 V_23 = {
. V_15 = V_32 -> V_164 ,
. V_108 = V_32 -> V_166 ,
. V_38 = V_167 ,
. V_24 = true ,
} ;
bool V_168 = false ;
F_143 ( V_32 -> V_169 , V_23 . V_15 ,
V_23 . V_108 ) ;
F_2 ( V_170 ) ;
for ( V_33 = 0 ; V_33 < V_23 . V_108 ; V_33 ++ ) {
int V_144 ;
V_14 = & V_32 -> V_35 [ V_33 ] ;
if ( ! F_36 ( V_14 ) )
continue;
if ( F_19 ( V_14 , V_23 . V_15 ) )
continue;
if ( F_103 ( V_14 , V_23 . V_15 , 0 , V_33 ) !=
V_107 )
continue;
V_23 . V_59 = 0 ;
V_23 . V_60 = 0 ;
V_23 . V_14 = V_14 ;
F_118 ( & V_23 . V_92 ) ;
F_118 ( & V_23 . V_67 ) ;
if ( F_140 () )
return;
V_144 = F_105 ( V_14 , & V_23 ) ;
if ( F_96 ( V_14 , V_23 . V_15 , F_95 ( V_14 ) ,
V_23 . V_108 , 0 ) ) {
V_168 = true ;
F_21 ( V_14 , V_23 . V_15 , false ) ;
} else if ( V_144 == V_106 ) {
F_17 ( V_14 , V_23 . V_15 ) ;
}
F_88 ( ! F_63 ( & V_23 . V_92 ) ) ;
F_88 ( ! F_63 ( & V_23 . V_67 ) ) ;
}
if ( V_32 -> V_164 <= V_23 . V_15 )
V_32 -> V_164 = 0 ;
if ( V_32 -> V_166 >= V_23 . V_108 )
V_32 -> V_166 = V_32 -> V_171 - 1 ;
}
void F_144 ( T_1 * V_32 , int V_15 , int V_108 )
{
if ( ! V_15 )
return;
if ( V_32 -> V_164 < V_15 )
V_32 -> V_164 = V_15 ;
if ( V_32 -> V_166 > V_108 )
V_32 -> V_166 = V_108 ;
if ( ! F_145 ( & V_32 -> V_172 ) )
return;
if ( ! F_141 ( V_32 ) )
return;
F_146 ( V_32 -> V_169 , V_15 ,
V_108 ) ;
F_147 ( & V_32 -> V_172 ) ;
}
static int F_148 ( void * V_173 )
{
T_1 * V_32 = ( T_1 * ) V_173 ;
struct V_174 * V_175 = V_45 ;
const struct V_176 * V_176 = F_149 ( V_32 -> V_169 ) ;
if ( ! F_150 ( V_176 ) )
F_151 ( V_175 , V_176 ) ;
F_152 () ;
V_32 -> V_164 = 0 ;
V_32 -> V_166 = V_32 -> V_171 - 1 ;
while ( ! F_140 () ) {
F_153 ( V_32 -> V_169 ) ;
F_154 ( V_32 -> V_172 ,
F_139 ( V_32 ) ) ;
F_142 ( V_32 ) ;
}
return 0 ;
}
int F_155 ( int V_147 )
{
T_1 * V_32 = F_126 ( V_147 ) ;
int V_117 = 0 ;
if ( V_32 -> F_148 )
return 0 ;
V_32 -> F_148 = F_156 ( F_148 , V_32 , L_1 , V_147 ) ;
if ( F_157 ( V_32 -> F_148 ) ) {
F_158 ( L_2 , V_147 ) ;
V_117 = F_159 ( V_32 -> F_148 ) ;
V_32 -> F_148 = NULL ;
}
return V_117 ;
}
void F_160 ( int V_147 )
{
struct V_174 * F_148 = F_126 ( V_147 ) -> F_148 ;
if ( F_148 ) {
F_161 ( F_148 ) ;
F_126 ( V_147 ) -> F_148 = NULL ;
}
}
static int F_162 ( struct V_177 * V_178 , unsigned long V_179 ,
void * V_180 )
{
int V_147 ;
if ( V_179 == V_181 || V_179 == V_182 ) {
F_163 (nid, N_MEMORY) {
T_1 * V_32 = F_126 ( V_147 ) ;
const struct V_176 * V_183 ;
V_183 = F_149 ( V_32 -> V_169 ) ;
if ( F_164 ( V_184 , V_183 ) < V_185 )
F_151 ( V_32 -> F_148 , V_183 ) ;
}
}
return V_186 ;
}
static int T_10 F_165 ( void )
{
int V_147 ;
F_163 (nid, N_MEMORY)
F_155 ( V_147 ) ;
F_166 ( F_162 , 0 ) ;
return 0 ;
}
