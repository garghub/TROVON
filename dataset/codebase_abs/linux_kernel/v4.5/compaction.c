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
static struct V_6 * F_17 ( unsigned long V_14 ,
unsigned long V_15 , struct V_16 * V_16 )
{
struct V_6 * V_17 ;
struct V_6 * V_18 ;
V_15 -- ;
if ( ! F_18 ( V_14 ) || ! F_18 ( V_15 ) )
return NULL ;
V_17 = F_19 ( V_14 ) ;
if ( F_20 ( V_17 ) != V_16 )
return NULL ;
V_18 = F_19 ( V_15 ) ;
if ( F_21 ( V_17 ) != F_21 ( V_18 ) )
return NULL ;
return V_17 ;
}
void F_22 ( struct V_16 * V_16 , int V_19 )
{
V_16 -> V_20 = 0 ;
V_16 -> V_21 ++ ;
if ( V_19 < V_16 -> V_22 )
V_16 -> V_22 = V_19 ;
if ( V_16 -> V_21 > V_23 )
V_16 -> V_21 = V_23 ;
F_23 ( V_16 , V_19 ) ;
}
bool F_24 ( struct V_16 * V_16 , int V_19 )
{
unsigned long V_24 = 1UL << V_16 -> V_21 ;
if ( V_19 < V_16 -> V_22 )
return false ;
if ( ++ V_16 -> V_20 > V_24 )
V_16 -> V_20 = V_24 ;
if ( V_16 -> V_20 >= V_24 )
return false ;
F_25 ( V_16 , V_19 ) ;
return true ;
}
void F_26 ( struct V_16 * V_16 , int V_19 ,
bool V_25 )
{
if ( V_25 ) {
V_16 -> V_20 = 0 ;
V_16 -> V_21 = 0 ;
}
if ( V_19 >= V_16 -> V_22 )
V_16 -> V_22 = V_19 + 1 ;
F_27 ( V_16 , V_19 ) ;
}
bool F_28 ( struct V_16 * V_16 , int V_19 )
{
if ( V_19 < V_16 -> V_22 )
return false ;
return V_16 -> V_21 == V_23 &&
V_16 -> V_20 >= 1UL << V_16 -> V_21 ;
}
static inline bool F_29 ( struct V_26 * V_27 ,
struct V_6 * V_6 )
{
if ( V_27 -> V_28 )
return true ;
return ! F_30 ( V_6 ) ;
}
static void F_31 ( struct V_16 * V_16 )
{
V_16 -> V_29 [ 0 ] = V_16 -> V_30 ;
V_16 -> V_29 [ 1 ] = V_16 -> V_30 ;
V_16 -> V_31 = F_32 ( V_16 ) ;
}
static void F_33 ( struct V_16 * V_16 )
{
unsigned long V_14 = V_16 -> V_30 ;
unsigned long V_15 = F_32 ( V_16 ) ;
unsigned long V_9 ;
V_16 -> V_32 = false ;
for ( V_9 = V_14 ; V_9 < V_15 ; V_9 += V_33 ) {
struct V_6 * V_6 ;
F_34 () ;
if ( ! F_18 ( V_9 ) )
continue;
V_6 = F_19 ( V_9 ) ;
if ( V_16 != F_20 ( V_6 ) )
continue;
F_35 ( V_6 ) ;
}
F_31 ( V_16 ) ;
}
void F_36 ( T_1 * V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
struct V_16 * V_16 = & V_34 -> V_37 [ V_35 ] ;
if ( ! F_37 ( V_16 ) )
continue;
if ( V_16 -> V_32 )
F_33 ( V_16 ) ;
}
}
static void F_38 ( struct V_26 * V_27 ,
struct V_6 * V_6 , unsigned long V_38 ,
bool V_39 )
{
struct V_16 * V_16 = V_27 -> V_16 ;
unsigned long V_9 ;
if ( V_27 -> V_28 )
return;
if ( ! V_6 )
return;
if ( V_38 )
return;
F_39 ( V_6 ) ;
V_9 = F_7 ( V_6 ) ;
if ( V_39 ) {
if ( V_9 > V_16 -> V_29 [ 0 ] )
V_16 -> V_29 [ 0 ] = V_9 ;
if ( V_27 -> V_40 != V_41 &&
V_9 > V_16 -> V_29 [ 1 ] )
V_16 -> V_29 [ 1 ] = V_9 ;
} else {
if ( V_9 < V_16 -> V_31 )
V_16 -> V_31 = V_9 ;
}
}
static inline bool F_29 ( struct V_26 * V_27 ,
struct V_6 * V_6 )
{
return true ;
}
static void F_38 ( struct V_26 * V_27 ,
struct V_6 * V_6 , unsigned long V_38 ,
bool V_39 )
{
}
static bool F_40 ( T_2 * V_42 , unsigned long * V_43 ,
struct V_26 * V_27 )
{
if ( V_27 -> V_40 == V_41 ) {
if ( ! F_41 ( V_42 , * V_43 ) ) {
V_27 -> V_44 = V_45 ;
return false ;
}
} else {
F_42 ( V_42 , * V_43 ) ;
}
return true ;
}
static bool F_43 ( T_2 * V_42 ,
unsigned long V_43 , bool * V_46 , struct V_26 * V_27 )
{
if ( * V_46 ) {
F_44 ( V_42 , V_43 ) ;
* V_46 = false ;
}
if ( F_45 ( V_47 ) ) {
V_27 -> V_44 = V_48 ;
return true ;
}
if ( F_46 () ) {
if ( V_27 -> V_40 == V_41 ) {
V_27 -> V_44 = V_48 ;
return true ;
}
F_34 () ;
}
return false ;
}
static inline bool F_47 ( struct V_26 * V_27 )
{
if ( F_46 () ) {
if ( V_27 -> V_40 == V_41 ) {
V_27 -> V_44 = V_48 ;
return true ;
}
F_34 () ;
}
return false ;
}
static unsigned long F_48 ( struct V_26 * V_27 ,
unsigned long * V_14 ,
unsigned long V_15 ,
struct V_4 * V_5 ,
bool V_49 )
{
int V_50 = 0 , V_51 = 0 ;
struct V_6 * V_52 , * V_53 = NULL ;
unsigned long V_43 = 0 ;
bool V_46 = false ;
unsigned long V_54 = * V_14 ;
V_52 = F_19 ( V_54 ) ;
for (; V_54 < V_15 ; V_54 ++ , V_52 ++ ) {
int V_55 , V_56 ;
struct V_6 * V_6 = V_52 ;
if ( ! ( V_54 % V_57 )
&& F_43 ( & V_27 -> V_16 -> V_42 , V_43 ,
& V_46 , V_27 ) )
break;
V_50 ++ ;
if ( ! F_49 ( V_54 ) )
goto V_58;
if ( ! V_53 )
V_53 = V_6 ;
if ( F_50 ( V_6 ) ) {
unsigned int V_59 = F_51 ( V_6 ) ;
if ( F_52 ( V_59 < V_60 ) ) {
V_54 += ( 1UL << V_59 ) - 1 ;
V_52 += ( 1UL << V_59 ) - 1 ;
}
goto V_58;
}
if ( ! F_53 ( V_6 ) )
goto V_58;
if ( ! V_46 ) {
V_46 = F_40 ( & V_27 -> V_16 -> V_42 ,
& V_43 , V_27 ) ;
if ( ! V_46 )
break;
if ( ! F_53 ( V_6 ) )
goto V_58;
}
V_55 = F_54 ( V_6 ) ;
V_51 += V_55 ;
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ ) {
F_55 ( & V_6 -> V_10 , V_5 ) ;
V_6 ++ ;
}
if ( V_55 ) {
V_27 -> V_61 += V_55 ;
if ( ! V_49 &&
V_27 -> V_62 <= V_27 -> V_61 ) {
V_54 += V_55 ;
break;
}
V_54 += V_55 - 1 ;
V_52 += V_55 - 1 ;
continue;
}
V_58:
if ( V_49 )
break;
else
continue;
}
if ( F_56 ( V_54 > V_15 ) )
V_54 = V_15 ;
F_57 ( * V_14 , V_54 ,
V_50 , V_51 ) ;
* V_14 = V_54 ;
if ( V_49 && V_54 < V_15 )
V_51 = 0 ;
if ( V_46 )
F_44 ( & V_27 -> V_16 -> V_42 , V_43 ) ;
if ( V_54 == V_15 )
F_38 ( V_27 , V_53 , V_51 , false ) ;
F_3 ( V_63 , V_50 ) ;
if ( V_51 )
F_3 ( V_64 , V_51 ) ;
return V_51 ;
}
unsigned long
F_58 ( struct V_26 * V_27 ,
unsigned long V_14 , unsigned long V_15 )
{
unsigned long V_55 , V_9 , V_65 ;
F_59 ( V_5 ) ;
V_9 = V_14 ;
V_65 = F_60 ( V_9 + 1 , V_33 ) ;
for (; V_9 < V_15 ; V_9 += V_55 ,
V_65 += V_33 ) {
unsigned long V_66 = V_9 ;
V_65 = F_61 ( V_65 , V_15 ) ;
if ( V_9 >= V_65 ) {
V_65 = F_60 ( V_9 + 1 , V_33 ) ;
V_65 = F_61 ( V_65 , V_15 ) ;
}
if ( ! F_17 ( V_9 , V_65 , V_27 -> V_16 ) )
break;
V_55 = F_48 ( V_27 , & V_66 ,
V_65 , & V_5 , true ) ;
if ( ! V_55 )
break;
}
F_10 ( & V_5 ) ;
if ( V_9 < V_15 ) {
F_5 ( & V_5 ) ;
return 0 ;
}
return V_9 ;
}
static void F_62 ( struct V_16 * V_16 , struct V_26 * V_27 )
{
struct V_6 * V_6 ;
unsigned int V_67 [ 2 ] = { 0 , } ;
if ( F_63 ( & V_27 -> V_68 ) )
return;
F_11 (page, &cc->migratepages, lru)
V_67 [ ! ! F_64 ( V_6 ) ] ++ ;
F_65 ( V_16 , V_69 , V_67 [ 0 ] ) ;
F_65 ( V_16 , V_70 , V_67 [ 1 ] ) ;
}
static bool F_66 ( struct V_16 * V_16 )
{
unsigned long V_71 , V_72 , V_55 ;
V_72 = F_67 ( V_16 , V_73 ) +
F_67 ( V_16 , V_74 ) ;
V_71 = F_67 ( V_16 , V_75 ) +
F_67 ( V_16 , V_76 ) ;
V_55 = F_67 ( V_16 , V_70 ) +
F_67 ( V_16 , V_69 ) ;
return V_55 > ( V_72 + V_71 ) / 2 ;
}
static unsigned long
F_68 ( struct V_26 * V_27 , unsigned long V_77 ,
unsigned long V_15 , T_3 V_78 )
{
struct V_16 * V_16 = V_27 -> V_16 ;
unsigned long V_50 = 0 , V_38 = 0 ;
struct V_4 * V_79 = & V_27 -> V_68 ;
struct V_80 * V_80 ;
unsigned long V_43 = 0 ;
bool V_46 = false ;
struct V_6 * V_6 = NULL , * V_53 = NULL ;
unsigned long V_14 = V_77 ;
while ( F_56 ( F_66 ( V_16 ) ) ) {
if ( V_27 -> V_40 == V_41 )
return 0 ;
F_69 ( V_81 , V_82 / 10 ) ;
if ( F_45 ( V_47 ) )
return 0 ;
}
if ( F_47 ( V_27 ) )
return 0 ;
for (; V_77 < V_15 ; V_77 ++ ) {
bool V_83 ;
if ( ! ( V_77 % V_57 )
&& F_43 ( & V_16 -> V_84 , V_43 ,
& V_46 , V_27 ) )
break;
if ( ! F_49 ( V_77 ) )
continue;
V_50 ++ ;
V_6 = F_19 ( V_77 ) ;
if ( ! V_53 )
V_53 = V_6 ;
if ( F_53 ( V_6 ) ) {
unsigned long V_85 = F_70 ( V_6 ) ;
if ( V_85 > 0 && V_85 < V_60 )
V_77 += ( 1UL << V_85 ) - 1 ;
continue;
}
V_83 = F_71 ( V_6 ) ;
if ( ! V_83 ) {
if ( F_56 ( F_72 ( V_6 ) ) ) {
if ( F_73 ( V_6 ) ) {
goto V_86;
}
}
}
if ( F_50 ( V_6 ) ) {
unsigned int V_59 = F_51 ( V_6 ) ;
if ( F_52 ( V_59 < V_60 ) )
V_77 += ( 1UL << V_59 ) - 1 ;
continue;
}
if ( ! V_83 )
continue;
if ( ! F_74 ( V_6 ) &&
F_75 ( V_6 ) > F_76 ( V_6 ) )
continue;
if ( ! V_46 ) {
V_46 = F_40 ( & V_16 -> V_84 ,
& V_43 , V_27 ) ;
if ( ! V_46 )
break;
if ( ! F_71 ( V_6 ) )
continue;
if ( F_56 ( F_50 ( V_6 ) ) ) {
V_77 += ( 1UL << F_51 ( V_6 ) ) - 1 ;
continue;
}
}
V_80 = F_77 ( V_6 , V_16 ) ;
if ( F_78 ( V_6 , V_78 ) != 0 )
continue;
F_79 ( F_50 ( V_6 ) , V_6 ) ;
F_80 ( V_6 , V_80 , F_81 ( V_6 ) ) ;
V_86:
F_55 ( & V_6 -> V_10 , V_79 ) ;
V_27 -> V_62 ++ ;
V_38 ++ ;
if ( V_27 -> V_62 == V_87 ) {
++ V_77 ;
break;
}
}
if ( F_56 ( V_77 > V_15 ) )
V_77 = V_15 ;
if ( V_46 )
F_44 ( & V_16 -> V_84 , V_43 ) ;
if ( V_77 == V_15 )
F_38 ( V_27 , V_53 , V_38 , true ) ;
F_82 ( V_14 , V_77 ,
V_50 , V_38 ) ;
F_3 ( V_88 , V_50 ) ;
if ( V_38 )
F_3 ( V_64 , V_38 ) ;
return V_77 ;
}
unsigned long
F_83 ( struct V_26 * V_27 , unsigned long V_14 ,
unsigned long V_15 )
{
unsigned long V_9 , V_65 ;
V_9 = V_14 ;
V_65 = F_60 ( V_9 + 1 , V_33 ) ;
for (; V_9 < V_15 ; V_9 = V_65 ,
V_65 += V_33 ) {
V_65 = F_61 ( V_65 , V_15 ) ;
if ( ! F_17 ( V_9 , V_65 , V_27 -> V_16 ) )
continue;
V_9 = F_68 ( V_27 , V_9 , V_65 ,
V_89 ) ;
if ( ! V_9 ) {
F_84 ( & V_27 -> V_68 ) ;
V_27 -> V_62 = 0 ;
break;
}
if ( V_27 -> V_62 == V_87 )
break;
}
F_62 ( V_27 -> V_16 , V_27 ) ;
return V_9 ;
}
static bool F_85 ( struct V_6 * V_6 )
{
if ( F_53 ( V_6 ) ) {
if ( F_70 ( V_6 ) >= V_90 )
return false ;
}
if ( F_15 ( F_86 ( V_6 ) ) )
return true ;
return false ;
}
static inline bool F_87 ( struct V_26 * V_27 )
{
return ( V_27 -> V_91 >> V_90 )
<= ( V_27 -> V_92 >> V_90 ) ;
}
static void F_88 ( struct V_26 * V_27 )
{
struct V_16 * V_16 = V_27 -> V_16 ;
struct V_6 * V_6 ;
unsigned long V_93 ;
unsigned long V_66 ;
unsigned long V_65 ;
unsigned long V_77 ;
struct V_4 * V_5 = & V_27 -> V_94 ;
V_66 = V_27 -> V_91 ;
V_93 = V_27 -> V_91 & ~ ( V_33 - 1 ) ;
V_65 = F_61 ( V_93 + V_33 ,
F_32 ( V_16 ) ) ;
V_77 = F_60 ( V_27 -> V_92 + 1 , V_33 ) ;
for (; V_93 >= V_77 ;
V_65 = V_93 ,
V_93 -= V_33 ,
V_66 = V_93 ) {
if ( ! ( V_93 % ( V_57 * V_33 ) )
&& F_47 ( V_27 ) )
break;
V_6 = F_17 ( V_93 , V_65 ,
V_16 ) ;
if ( ! V_6 )
continue;
if ( ! F_85 ( V_6 ) )
continue;
if ( ! F_29 ( V_27 , V_6 ) )
continue;
F_48 ( V_27 , & V_66 ,
V_65 , V_5 , false ) ;
if ( ( V_27 -> V_61 >= V_27 -> V_62 )
|| V_27 -> V_44 ) {
if ( V_66 >= V_65 )
V_66 =
V_93 - V_33 ;
break;
} else {
F_89 ( V_66 < V_65 ) ;
}
}
F_10 ( V_5 ) ;
V_27 -> V_91 = V_66 ;
}
static struct V_6 * F_90 ( struct V_6 * V_95 ,
unsigned long V_96 ,
int * * V_97 )
{
struct V_26 * V_27 = (struct V_26 * ) V_96 ;
struct V_6 * V_98 ;
if ( F_63 ( & V_27 -> V_94 ) ) {
if ( ! V_27 -> V_44 )
F_88 ( V_27 ) ;
if ( F_63 ( & V_27 -> V_94 ) )
return NULL ;
}
V_98 = F_91 ( V_27 -> V_94 . V_7 , struct V_6 , V_10 ) ;
F_8 ( & V_98 -> V_10 ) ;
V_27 -> V_61 -- ;
return V_98 ;
}
static void F_92 ( struct V_6 * V_6 , unsigned long V_96 )
{
struct V_26 * V_27 = (struct V_26 * ) V_96 ;
F_55 ( & V_6 -> V_10 , & V_27 -> V_94 ) ;
V_27 -> V_61 ++ ;
}
static T_4 F_93 ( struct V_16 * V_16 ,
struct V_26 * V_27 )
{
unsigned long V_77 , V_15 ;
unsigned long V_66 ;
struct V_6 * V_6 ;
const T_3 V_78 =
( V_99 ? V_89 : 0 ) |
( V_27 -> V_40 == V_41 ? V_100 : 0 ) ;
V_77 = V_27 -> V_92 ;
V_15 = F_60 ( V_77 + 1 , V_33 ) ;
for (; V_15 <= V_27 -> V_91 ;
V_77 = V_15 , V_15 += V_33 ) {
if ( ! ( V_77 % ( V_57 * V_33 ) )
&& F_47 ( V_27 ) )
break;
V_6 = F_17 ( V_77 , V_15 , V_16 ) ;
if ( ! V_6 )
continue;
if ( ! F_29 ( V_27 , V_6 ) )
continue;
if ( V_27 -> V_40 == V_41 &&
! F_15 ( F_86 ( V_6 ) ) )
continue;
V_66 = V_77 ;
V_77 = F_68 ( V_27 , V_77 , V_15 ,
V_78 ) ;
if ( ! V_77 || V_27 -> V_44 ) {
F_62 ( V_16 , V_27 ) ;
return V_101 ;
}
if ( V_27 -> V_62 && ! V_27 -> V_102 )
V_27 -> V_102 = V_66 ;
break;
}
F_62 ( V_16 , V_27 ) ;
V_27 -> V_92 = V_77 ;
return V_27 -> V_62 ? V_103 : V_104 ;
}
static inline bool F_94 ( int V_19 )
{
return V_19 == - 1 ;
}
static int F_95 ( struct V_16 * V_16 , struct V_26 * V_27 ,
const int V_12 )
{
unsigned int V_19 ;
unsigned long V_105 ;
if ( V_27 -> V_44 || F_45 ( V_47 ) )
return V_106 ;
if ( F_87 ( V_27 ) ) {
F_31 ( V_16 ) ;
if ( ! F_96 () )
V_16 -> V_32 = true ;
return V_107 ;
}
if ( F_94 ( V_27 -> V_19 ) )
return V_108 ;
V_105 = F_97 ( V_16 ) ;
if ( ! F_98 ( V_16 , V_27 -> V_19 , V_105 , V_27 -> V_109 ,
V_27 -> V_110 ) )
return V_108 ;
for ( V_19 = V_27 -> V_19 ; V_19 < V_60 ; V_19 ++ ) {
struct V_111 * V_112 = & V_16 -> V_111 [ V_19 ] ;
bool V_113 ;
if ( ! F_63 ( & V_112 -> V_114 [ V_12 ] ) )
return V_115 ;
#ifdef F_99
if ( V_12 == V_13 &&
! F_63 ( & V_112 -> V_114 [ V_116 ] ) )
return V_115 ;
#endif
if ( F_100 ( V_112 , V_19 , V_12 ,
true , & V_113 ) != - 1 )
return V_115 ;
}
return V_117 ;
}
static int F_101 ( struct V_16 * V_16 , struct V_26 * V_27 ,
const int V_12 )
{
int V_118 ;
V_118 = F_95 ( V_16 , V_27 , V_12 ) ;
F_102 ( V_16 , V_27 -> V_19 , V_118 ) ;
if ( V_118 == V_117 )
V_118 = V_108 ;
return V_118 ;
}
static unsigned long F_103 ( struct V_16 * V_16 , int V_19 ,
int V_110 , int V_109 )
{
int V_119 ;
unsigned long V_105 ;
if ( F_94 ( V_19 ) )
return V_108 ;
V_105 = F_97 ( V_16 ) ;
if ( F_98 ( V_16 , V_19 , V_105 , V_109 ,
V_110 ) )
return V_115 ;
V_105 += ( 2UL << V_19 ) ;
if ( ! F_98 ( V_16 , 0 , V_105 , V_109 , V_110 ) )
return V_120 ;
V_119 = F_104 ( V_16 , V_19 ) ;
if ( V_119 >= 0 && V_119 <= V_121 )
return V_122 ;
return V_108 ;
}
unsigned long F_105 ( struct V_16 * V_16 , int V_19 ,
int V_110 , int V_109 )
{
unsigned long V_118 ;
V_118 = F_103 ( V_16 , V_19 , V_110 , V_109 ) ;
F_106 ( V_16 , V_19 , V_118 ) ;
if ( V_118 == V_122 )
V_118 = V_120 ;
return V_118 ;
}
static int F_107 ( struct V_16 * V_16 , struct V_26 * V_27 )
{
int V_118 ;
unsigned long V_14 = V_16 -> V_30 ;
unsigned long V_15 = F_32 ( V_16 ) ;
const int V_12 = F_108 ( V_27 -> V_123 ) ;
const bool V_124 = V_27 -> V_40 != V_41 ;
V_118 = F_105 ( V_16 , V_27 -> V_19 , V_27 -> V_110 ,
V_27 -> V_109 ) ;
switch ( V_118 ) {
case V_115 :
case V_120 :
return V_118 ;
case V_108 :
;
}
if ( F_28 ( V_16 , V_27 -> V_19 ) && ! F_96 () )
F_33 ( V_16 ) ;
V_27 -> V_92 = V_16 -> V_29 [ V_124 ] ;
V_27 -> V_91 = V_16 -> V_31 ;
if ( V_27 -> V_91 < V_14 || V_27 -> V_91 > V_15 ) {
V_27 -> V_91 = V_15 & ~ ( V_33 - 1 ) ;
V_16 -> V_31 = V_27 -> V_91 ;
}
if ( V_27 -> V_92 < V_14 || V_27 -> V_92 > V_15 ) {
V_27 -> V_92 = V_14 ;
V_16 -> V_29 [ 0 ] = V_27 -> V_92 ;
V_16 -> V_29 [ 1 ] = V_27 -> V_92 ;
}
V_27 -> V_102 = 0 ;
F_109 ( V_14 , V_27 -> V_92 ,
V_27 -> V_91 , V_15 , V_124 ) ;
F_110 () ;
while ( ( V_118 = F_101 ( V_16 , V_27 , V_12 ) ) ==
V_108 ) {
int V_125 ;
switch ( F_93 ( V_16 , V_27 ) ) {
case V_101 :
V_118 = V_106 ;
F_84 ( & V_27 -> V_68 ) ;
V_27 -> V_62 = 0 ;
goto V_126;
case V_104 :
goto V_127;
case V_103 :
;
}
V_125 = F_111 ( & V_27 -> V_68 , F_90 ,
F_92 , ( unsigned long ) V_27 , V_27 -> V_40 ,
V_128 ) ;
F_112 ( V_27 -> V_62 , V_125 ,
& V_27 -> V_68 ) ;
V_27 -> V_62 = 0 ;
if ( V_125 ) {
F_84 ( & V_27 -> V_68 ) ;
if ( V_125 == - V_129 && ! F_87 ( V_27 ) ) {
V_118 = V_106 ;
goto V_126;
}
}
V_127:
if ( V_27 -> V_19 > 0 && V_27 -> V_102 ) {
int V_130 ;
unsigned long V_131 =
V_27 -> V_92 & ~ ( ( 1UL << V_27 -> V_19 ) - 1 ) ;
if ( V_27 -> V_102 < V_131 ) {
V_130 = F_113 () ;
F_114 ( V_130 ) ;
F_115 ( V_16 ) ;
F_116 () ;
V_27 -> V_102 = 0 ;
}
}
}
V_126:
if ( V_27 -> V_61 > 0 ) {
unsigned long V_91 = F_5 ( & V_27 -> V_94 ) ;
V_27 -> V_61 = 0 ;
F_89 ( V_91 == 0 ) ;
V_91 &= ~ ( V_33 - 1 ) ;
if ( V_91 > V_16 -> V_31 )
V_16 -> V_31 = V_91 ;
}
F_117 ( V_14 , V_27 -> V_92 ,
V_27 -> V_91 , V_15 , V_124 , V_118 ) ;
if ( V_118 == V_106 )
V_118 = V_115 ;
return V_118 ;
}
static unsigned long F_118 ( struct V_16 * V_16 , int V_19 ,
T_5 V_123 , enum V_132 V_40 , int * V_44 ,
int V_110 , int V_109 )
{
unsigned long V_118 ;
struct V_26 V_27 = {
. V_61 = 0 ,
. V_62 = 0 ,
. V_19 = V_19 ,
. V_123 = V_123 ,
. V_16 = V_16 ,
. V_40 = V_40 ,
. V_110 = V_110 ,
. V_109 = V_109 ,
} ;
F_119 ( & V_27 . V_94 ) ;
F_119 ( & V_27 . V_68 ) ;
V_118 = F_107 ( V_16 , & V_27 ) ;
F_89 ( ! F_63 ( & V_27 . V_94 ) ) ;
F_89 ( ! F_63 ( & V_27 . V_68 ) ) ;
* V_44 = V_27 . V_44 ;
return V_118 ;
}
unsigned long F_120 ( T_5 V_123 , unsigned int V_19 ,
int V_110 , const struct V_133 * V_134 ,
enum V_132 V_40 , int * V_44 )
{
int V_135 = V_123 & V_136 ;
int V_137 = V_123 & V_138 ;
struct V_139 * V_140 ;
struct V_16 * V_16 ;
int V_141 = V_142 ;
int V_143 = V_45 ;
* V_44 = V_144 ;
if ( ! V_19 || ! V_135 || ! V_137 )
return V_120 ;
F_121 ( V_19 , V_123 , V_40 ) ;
F_122 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
int V_145 ;
int V_146 ;
if ( F_24 ( V_16 , V_19 ) )
continue;
V_145 = F_118 ( V_16 , V_19 , V_123 , V_40 ,
& V_146 , V_110 ,
V_134 -> V_109 ) ;
V_141 = F_123 ( V_145 , V_141 ) ;
V_143 &= V_146 ;
if ( F_98 ( V_16 , V_19 , F_97 ( V_16 ) ,
V_134 -> V_109 , V_110 ) ) {
F_26 ( V_16 , V_19 , false ) ;
if ( V_146 == V_48 )
* V_44 = V_48 ;
goto V_147;
}
if ( V_40 != V_41 && V_145 == V_107 ) {
F_22 ( V_16 , V_19 ) ;
}
if ( ( V_146 == V_48 )
|| F_45 ( V_47 ) ) {
* V_44 = V_48 ;
goto V_147;
}
continue;
V_147:
V_143 = 0 ;
break;
}
if ( V_141 > V_120 && V_143 )
* V_44 = V_45 ;
return V_141 ;
}
static void F_124 ( T_1 * V_34 , struct V_26 * V_27 )
{
int V_35 ;
struct V_16 * V_16 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_16 = & V_34 -> V_37 [ V_35 ] ;
if ( ! F_37 ( V_16 ) )
continue;
V_27 -> V_61 = 0 ;
V_27 -> V_62 = 0 ;
V_27 -> V_16 = V_16 ;
F_119 ( & V_27 -> V_94 ) ;
F_119 ( & V_27 -> V_68 ) ;
if ( F_94 ( V_27 -> V_19 ) )
F_33 ( V_16 ) ;
if ( F_94 ( V_27 -> V_19 ) ||
! F_24 ( V_16 , V_27 -> V_19 ) )
F_107 ( V_16 , V_27 ) ;
F_89 ( ! F_63 ( & V_27 -> V_94 ) ) ;
F_89 ( ! F_63 ( & V_27 -> V_68 ) ) ;
if ( F_94 ( V_27 -> V_19 ) )
continue;
if ( F_98 ( V_16 , V_27 -> V_19 ,
F_97 ( V_16 ) , 0 , 0 ) )
F_26 ( V_16 , V_27 -> V_19 , false ) ;
}
}
void F_125 ( T_1 * V_34 , int V_19 )
{
struct V_26 V_27 = {
. V_19 = V_19 ,
. V_40 = V_41 ,
} ;
if ( ! V_19 )
return;
F_124 ( V_34 , & V_27 ) ;
}
static void F_126 ( int V_148 )
{
struct V_26 V_27 = {
. V_19 = - 1 ,
. V_40 = V_149 ,
. V_28 = true ,
} ;
F_124 ( F_127 ( V_148 ) , & V_27 ) ;
}
static void F_128 ( void )
{
int V_148 ;
F_129 () ;
F_130 (nid)
F_126 ( V_148 ) ;
}
int F_131 ( struct V_150 * V_151 , int V_152 ,
void T_6 * V_153 , T_7 * V_154 , T_8 * V_155 )
{
if ( V_152 )
F_128 () ;
return 0 ;
}
int F_132 ( struct V_150 * V_151 , int V_152 ,
void T_6 * V_153 , T_7 * V_154 , T_8 * V_155 )
{
F_133 ( V_151 , V_152 , V_153 , V_154 , V_155 ) ;
return 0 ;
}
static T_9 F_134 ( struct V_156 * V_157 ,
struct V_158 * V_159 ,
const char * V_160 , T_7 V_67 )
{
int V_148 = V_157 -> V_161 ;
if ( V_148 >= 0 && V_148 < V_162 && F_135 ( V_148 ) ) {
F_129 () ;
F_126 ( V_148 ) ;
}
return V_67 ;
}
int F_136 ( struct V_163 * V_163 )
{
return F_137 ( & V_163 -> V_157 , & V_164 ) ;
}
void F_138 ( struct V_163 * V_163 )
{
return F_139 ( & V_163 -> V_157 , & V_164 ) ;
}
