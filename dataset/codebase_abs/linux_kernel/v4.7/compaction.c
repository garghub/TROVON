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
F_27 ( F_28 ( V_14 ) - 1 ) ;
}
static void F_29 ( struct V_14 * V_14 )
{
unsigned long V_28 = V_14 -> V_26 ;
unsigned long V_29 = F_28 ( V_14 ) ;
unsigned long V_9 ;
V_14 -> V_30 = false ;
for ( V_9 = V_28 ; V_9 < V_29 ; V_9 += V_31 ) {
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
if ( V_14 -> V_30 )
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
unsigned long * V_28 ,
unsigned long V_29 ,
struct V_4 * V_5 ,
bool V_47 )
{
int V_48 = 0 , V_49 = 0 ;
struct V_6 * V_50 , * V_51 = NULL ;
unsigned long V_41 = 0 ;
bool V_44 = false ;
unsigned long V_52 = * V_28 ;
V_50 = F_32 ( V_52 ) ;
for (; V_52 < V_29 ; V_52 ++ , V_50 ++ ) {
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
if ( ! V_53 )
break;
V_49 += V_53 ;
V_23 -> V_59 += V_53 ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ ) {
F_54 ( & V_6 -> V_10 , V_5 ) ;
V_6 ++ ;
}
if ( ! V_47 && V_23 -> V_60 <= V_23 -> V_59 ) {
V_52 += V_53 ;
break;
}
V_52 += V_53 - 1 ;
V_50 += V_53 - 1 ;
continue;
V_56:
if ( V_47 )
break;
else
continue;
}
if ( V_44 )
F_43 ( & V_23 -> V_14 -> V_40 , V_41 ) ;
if ( F_55 ( V_52 > V_29 ) )
V_52 = V_29 ;
F_56 ( * V_28 , V_52 ,
V_48 , V_49 ) ;
* V_28 = V_52 ;
if ( V_47 && V_52 < V_29 )
V_49 = 0 ;
if ( V_52 == V_29 )
F_37 ( V_23 , V_51 , V_49 , false ) ;
F_3 ( V_61 , V_48 ) ;
if ( V_49 )
F_3 ( V_62 , V_49 ) ;
return V_49 ;
}
unsigned long
F_57 ( struct V_22 * V_23 ,
unsigned long V_28 , unsigned long V_29 )
{
unsigned long V_53 , V_9 , V_63 , V_64 ;
F_58 ( V_5 ) ;
V_9 = V_28 ;
V_63 = F_27 ( V_9 ) ;
if ( V_63 < V_23 -> V_14 -> V_26 )
V_63 = V_23 -> V_14 -> V_26 ;
V_64 = F_59 ( V_9 ) ;
for (; V_9 < V_29 ; V_9 += V_53 ,
V_63 = V_64 ,
V_64 += V_31 ) {
unsigned long V_65 = V_9 ;
V_64 = F_60 ( V_64 , V_29 ) ;
if ( V_9 >= V_64 ) {
V_63 = F_27 ( V_9 ) ;
V_64 = F_59 ( V_9 ) ;
V_64 = F_60 ( V_64 , V_29 ) ;
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
if ( V_9 < V_29 ) {
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
unsigned long V_29 , T_3 V_77 )
{
struct V_14 * V_14 = V_23 -> V_14 ;
unsigned long V_48 = 0 , V_36 = 0 ;
struct V_78 * V_78 ;
unsigned long V_41 = 0 ;
bool V_44 = false ;
struct V_6 * V_6 = NULL , * V_51 = NULL ;
unsigned long V_28 = V_76 ;
bool V_79 = false ;
unsigned long V_80 = 0 ;
while ( F_55 ( F_66 ( V_14 ) ) ) {
if ( V_23 -> V_38 == V_39 )
return 0 ;
F_69 ( V_81 , V_82 / 10 ) ;
if ( F_44 ( V_45 ) )
return 0 ;
}
if ( F_46 ( V_23 ) )
return 0 ;
if ( V_23 -> V_83 && ( V_23 -> V_38 == V_39 ) ) {
V_79 = true ;
V_80 = V_64 ( V_76 , V_23 -> V_15 ) ;
}
for (; V_76 < V_29 ; V_76 ++ ) {
bool V_84 ;
if ( V_79 && V_76 >= V_80 ) {
if ( V_36 )
break;
V_80 = V_64 ( V_76 , V_23 -> V_15 ) ;
}
if ( ! ( V_76 % V_55 )
&& F_42 ( & V_14 -> V_85 , V_41 ,
& V_44 , V_23 ) )
break;
if ( ! F_48 ( V_76 ) )
goto V_56;
V_48 ++ ;
V_6 = F_32 ( V_76 ) ;
if ( ! V_51 )
V_51 = V_6 ;
if ( F_52 ( V_6 ) ) {
unsigned long V_86 = F_70 ( V_6 ) ;
if ( V_86 > 0 && V_86 < V_58 )
V_76 += ( 1UL << V_86 ) - 1 ;
continue;
}
V_84 = F_71 ( V_6 ) ;
if ( ! V_84 ) {
if ( F_55 ( F_72 ( V_6 ) ) ) {
if ( F_73 ( V_6 ) ) {
goto V_87;
}
}
}
if ( F_49 ( V_6 ) ) {
unsigned int V_57 = F_50 ( V_6 ) ;
if ( F_51 ( V_57 < V_58 ) )
V_76 += ( 1UL << V_57 ) - 1 ;
goto V_56;
}
if ( ! V_84 )
goto V_56;
if ( ! F_74 ( V_6 ) &&
F_75 ( V_6 ) > F_76 ( V_6 ) )
goto V_56;
if ( ! V_44 ) {
V_44 = F_39 ( & V_14 -> V_85 ,
& V_41 , V_23 ) ;
if ( ! V_44 )
break;
if ( ! F_71 ( V_6 ) )
goto V_56;
if ( F_55 ( F_49 ( V_6 ) ) ) {
V_76 += ( 1UL << F_50 ( V_6 ) ) - 1 ;
goto V_56;
}
}
V_78 = F_77 ( V_6 , V_14 ) ;
if ( F_78 ( V_6 , V_77 ) != 0 )
goto V_56;
F_79 ( F_49 ( V_6 ) , V_6 ) ;
F_80 ( V_6 , V_78 , F_81 ( V_6 ) ) ;
V_87:
F_54 ( & V_6 -> V_10 , & V_23 -> V_67 ) ;
V_23 -> V_60 ++ ;
V_36 ++ ;
if ( ! V_23 -> V_88 )
V_23 -> V_88 = V_76 ;
if ( V_23 -> V_60 == V_89 ) {
++ V_76 ;
break;
}
continue;
V_56:
if ( ! V_79 )
continue;
if ( V_36 ) {
if ( V_44 ) {
F_43 ( & V_14 -> V_85 , V_41 ) ;
V_44 = false ;
}
F_62 ( V_14 , V_23 ) ;
F_82 ( & V_23 -> V_67 ) ;
V_23 -> V_60 = 0 ;
V_23 -> V_88 = 0 ;
V_36 = 0 ;
}
if ( V_76 < V_80 ) {
V_76 = V_80 - 1 ;
V_80 += 1UL << V_23 -> V_15 ;
}
}
if ( F_55 ( V_76 > V_29 ) )
V_76 = V_29 ;
if ( V_44 )
F_43 ( & V_14 -> V_85 , V_41 ) ;
if ( V_76 == V_29 )
F_37 ( V_23 , V_51 , V_36 , true ) ;
F_83 ( V_28 , V_76 ,
V_48 , V_36 ) ;
F_3 ( V_90 , V_48 ) ;
if ( V_36 )
F_3 ( V_62 , V_36 ) ;
return V_76 ;
}
unsigned long
F_84 ( struct V_22 * V_23 , unsigned long V_28 ,
unsigned long V_29 )
{
unsigned long V_9 , V_63 , V_64 ;
V_9 = V_28 ;
V_63 = F_27 ( V_9 ) ;
if ( V_63 < V_23 -> V_14 -> V_26 )
V_63 = V_23 -> V_14 -> V_26 ;
V_64 = F_59 ( V_9 ) ;
for (; V_9 < V_29 ; V_9 = V_64 ,
V_63 = V_64 ,
V_64 += V_31 ) {
V_64 = F_60 ( V_64 , V_29 ) ;
if ( ! F_61 ( V_63 ,
V_64 , V_23 -> V_14 ) )
continue;
V_9 = F_68 ( V_23 , V_9 , V_64 ,
V_91 ) ;
if ( ! V_9 )
break;
if ( V_23 -> V_60 == V_89 )
break;
}
F_62 ( V_23 -> V_14 , V_23 ) ;
return V_9 ;
}
static bool F_85 ( struct V_6 * V_6 )
{
if ( F_52 ( V_6 ) ) {
if ( F_70 ( V_6 ) >= V_92 )
return false ;
}
if ( F_15 ( F_86 ( V_6 ) ) )
return true ;
return false ;
}
static inline bool F_87 ( struct V_22 * V_23 )
{
return ( V_23 -> V_93 >> V_92 )
<= ( V_23 -> V_94 >> V_92 ) ;
}
static void F_88 ( struct V_22 * V_23 )
{
struct V_14 * V_14 = V_23 -> V_14 ;
struct V_6 * V_6 ;
unsigned long V_63 ;
unsigned long V_65 ;
unsigned long V_64 ;
unsigned long V_76 ;
struct V_4 * V_5 = & V_23 -> V_95 ;
V_65 = V_23 -> V_93 ;
V_63 = F_27 ( V_23 -> V_93 ) ;
V_64 = F_60 ( V_63 + V_31 ,
F_28 ( V_14 ) ) ;
V_76 = F_59 ( V_23 -> V_94 ) ;
for (; V_63 >= V_76 ;
V_64 = V_63 ,
V_63 -= V_31 ,
V_65 = V_63 ) {
if ( ! ( V_63 % ( V_55 * V_31 ) )
&& F_46 ( V_23 ) )
break;
V_6 = F_61 ( V_63 , V_64 ,
V_14 ) ;
if ( ! V_6 )
continue;
if ( ! F_85 ( V_6 ) )
continue;
if ( ! F_24 ( V_23 , V_6 ) )
continue;
F_47 ( V_23 , & V_65 , V_64 ,
V_5 , false ) ;
if ( ( V_23 -> V_59 >= V_23 -> V_60 )
|| V_23 -> V_42 ) {
if ( V_65 >= V_64 ) {
V_65 =
V_63 - V_31 ;
}
break;
} else if ( V_65 < V_64 ) {
break;
}
}
F_10 ( V_5 ) ;
V_23 -> V_93 = V_65 ;
}
static struct V_6 * F_89 ( struct V_6 * V_96 ,
unsigned long V_97 ,
int * * V_98 )
{
struct V_22 * V_23 = (struct V_22 * ) V_97 ;
struct V_6 * V_99 ;
if ( F_63 ( & V_23 -> V_95 ) ) {
if ( ! V_23 -> V_42 )
F_88 ( V_23 ) ;
if ( F_63 ( & V_23 -> V_95 ) )
return NULL ;
}
V_99 = F_90 ( V_23 -> V_95 . V_7 , struct V_6 , V_10 ) ;
F_8 ( & V_99 -> V_10 ) ;
V_23 -> V_59 -- ;
return V_99 ;
}
static void F_91 ( struct V_6 * V_6 , unsigned long V_97 )
{
struct V_22 * V_23 = (struct V_22 * ) V_97 ;
F_54 ( & V_6 -> V_10 , & V_23 -> V_95 ) ;
V_23 -> V_59 ++ ;
}
static T_4 F_92 ( struct V_14 * V_14 ,
struct V_22 * V_23 )
{
unsigned long V_63 ;
unsigned long V_64 ;
unsigned long V_76 ;
struct V_6 * V_6 ;
const T_3 V_77 =
( V_100 ? V_91 : 0 ) |
( V_23 -> V_38 == V_39 ? V_101 : 0 ) ;
V_76 = V_23 -> V_94 ;
V_63 = F_27 ( V_76 ) ;
if ( V_63 < V_14 -> V_26 )
V_63 = V_14 -> V_26 ;
V_64 = F_59 ( V_76 ) ;
for (; V_64 <= V_23 -> V_93 ;
V_76 = V_64 ,
V_63 = V_64 ,
V_64 += V_31 ) {
if ( ! ( V_76 % ( V_55 * V_31 ) )
&& F_46 ( V_23 ) )
break;
V_6 = F_61 ( V_63 , V_64 ,
V_14 ) ;
if ( ! V_6 )
continue;
if ( ! F_24 ( V_23 , V_6 ) )
continue;
if ( V_23 -> V_38 == V_39 &&
! F_15 ( F_86 ( V_6 ) ) )
continue;
V_76 = F_68 ( V_23 , V_76 ,
V_64 , V_77 ) ;
if ( ! V_76 || V_23 -> V_42 ) {
F_62 ( V_14 , V_23 ) ;
return V_102 ;
}
break;
}
F_62 ( V_14 , V_23 ) ;
V_23 -> V_94 = V_76 ;
return V_23 -> V_60 ? V_103 : V_104 ;
}
static inline bool F_93 ( int V_15 )
{
return V_15 == - 1 ;
}
static enum V_105 F_94 ( struct V_14 * V_14 , struct V_22 * V_23 ,
const int V_12 )
{
unsigned int V_15 ;
unsigned long V_106 ;
if ( V_23 -> V_42 || F_44 ( V_45 ) )
return V_107 ;
if ( F_87 ( V_23 ) ) {
F_26 ( V_14 ) ;
if ( V_23 -> V_83 )
V_14 -> V_30 = true ;
if ( V_23 -> V_108 )
return V_109 ;
else
return V_110 ;
}
if ( F_93 ( V_23 -> V_15 ) )
return V_111 ;
V_106 = F_95 ( V_14 ) ;
if ( ! F_96 ( V_14 , V_23 -> V_15 , V_106 , V_23 -> V_112 ,
V_23 -> V_113 ) )
return V_111 ;
for ( V_15 = V_23 -> V_15 ; V_15 < V_58 ; V_15 ++ ) {
struct V_114 * V_115 = & V_14 -> V_114 [ V_15 ] ;
bool V_116 ;
if ( ! F_63 ( & V_115 -> V_117 [ V_12 ] ) )
return V_118 ;
#ifdef F_97
if ( V_12 == V_13 &&
! F_63 ( & V_115 -> V_117 [ V_119 ] ) )
return V_118 ;
#endif
if ( F_98 ( V_115 , V_15 , V_12 ,
true , & V_116 ) != - 1 )
return V_118 ;
}
return V_120 ;
}
static enum V_105 F_99 ( struct V_14 * V_14 ,
struct V_22 * V_23 ,
const int V_12 )
{
int V_121 ;
V_121 = F_94 ( V_14 , V_23 , V_12 ) ;
F_100 ( V_14 , V_23 -> V_15 , V_121 ) ;
if ( V_121 == V_120 )
V_121 = V_111 ;
return V_121 ;
}
static enum V_105 F_101 ( struct V_14 * V_14 , int V_15 ,
unsigned int V_113 ,
int V_112 ,
unsigned long V_122 )
{
int V_123 ;
unsigned long V_106 ;
if ( F_93 ( V_15 ) )
return V_111 ;
V_106 = F_95 ( V_14 ) ;
if ( F_96 ( V_14 , V_15 , V_106 , V_112 ,
V_113 ) )
return V_118 ;
V_106 += ( 2UL << V_15 ) ;
if ( ! F_102 ( V_14 , 0 , V_106 , V_112 ,
V_113 , V_122 ) )
return V_124 ;
V_123 = F_103 ( V_14 , V_15 ) ;
if ( V_123 >= 0 && V_123 <= V_125 )
return V_126 ;
return V_111 ;
}
enum V_105 F_104 ( struct V_14 * V_14 , int V_15 ,
unsigned int V_113 ,
int V_112 )
{
enum V_105 V_121 ;
V_121 = F_101 ( V_14 , V_15 , V_113 , V_112 ,
F_67 ( V_14 , V_127 ) ) ;
F_105 ( V_14 , V_15 , V_121 ) ;
if ( V_121 == V_126 )
V_121 = V_124 ;
return V_121 ;
}
bool F_106 ( struct V_128 * V_129 , int V_15 ,
int V_113 )
{
struct V_14 * V_14 ;
struct V_130 * V_131 ;
F_107 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long V_132 ;
enum V_105 V_105 ;
V_132 = F_108 ( V_14 ) / V_15 ;
V_132 += F_109 ( V_14 , V_127 ) ;
V_105 = F_101 ( V_14 , V_15 , V_113 ,
F_110 ( V_129 ) , V_132 ) ;
if ( V_105 != V_124 &&
V_105 != V_126 )
return true ;
}
return false ;
}
static enum V_105 F_111 ( struct V_14 * V_14 , struct V_22 * V_23 )
{
enum V_105 V_121 ;
unsigned long V_28 = V_14 -> V_26 ;
unsigned long V_29 = F_28 ( V_14 ) ;
const int V_12 = F_112 ( V_23 -> V_133 ) ;
const bool V_134 = V_23 -> V_38 != V_39 ;
V_121 = F_104 ( V_14 , V_23 -> V_15 , V_23 -> V_113 ,
V_23 -> V_112 ) ;
if ( V_121 == V_118 || V_121 == V_124 )
return V_121 ;
F_113 ( V_121 != V_111 ) ;
if ( F_23 ( V_14 , V_23 -> V_15 ) )
F_29 ( V_14 ) ;
V_23 -> V_94 = V_14 -> V_25 [ V_134 ] ;
V_23 -> V_93 = V_14 -> V_27 ;
if ( V_23 -> V_93 < V_28 || V_23 -> V_93 >= V_29 ) {
V_23 -> V_93 = F_27 ( V_29 - 1 ) ;
V_14 -> V_27 = V_23 -> V_93 ;
}
if ( V_23 -> V_94 < V_28 || V_23 -> V_94 >= V_29 ) {
V_23 -> V_94 = V_28 ;
V_14 -> V_25 [ 0 ] = V_23 -> V_94 ;
V_14 -> V_25 [ 1 ] = V_23 -> V_94 ;
}
if ( V_23 -> V_94 == V_28 )
V_23 -> V_108 = true ;
V_23 -> V_88 = 0 ;
F_114 ( V_28 , V_23 -> V_94 ,
V_23 -> V_93 , V_29 , V_134 ) ;
F_115 () ;
while ( ( V_121 = F_99 ( V_14 , V_23 , V_12 ) ) ==
V_111 ) {
int V_135 ;
switch ( F_92 ( V_14 , V_23 ) ) {
case V_102 :
V_121 = V_107 ;
F_82 ( & V_23 -> V_67 ) ;
V_23 -> V_60 = 0 ;
goto V_136;
case V_104 :
goto V_137;
case V_103 :
;
}
V_135 = F_116 ( & V_23 -> V_67 , F_89 ,
F_91 , ( unsigned long ) V_23 , V_23 -> V_38 ,
V_138 ) ;
F_117 ( V_23 -> V_60 , V_135 ,
& V_23 -> V_67 ) ;
V_23 -> V_60 = 0 ;
if ( V_135 ) {
F_82 ( & V_23 -> V_67 ) ;
if ( V_135 == - V_139 && ! F_87 ( V_23 ) ) {
V_121 = V_107 ;
goto V_136;
}
if ( V_23 -> V_83 &&
( V_23 -> V_38 == V_39 ) ) {
V_23 -> V_94 = V_64 (
V_23 -> V_94 - 1 , V_23 -> V_15 ) ;
V_23 -> V_88 = 0 ;
}
}
V_137:
if ( V_23 -> V_15 > 0 && V_23 -> V_88 ) {
int V_140 ;
unsigned long V_141 =
V_63 ( V_23 -> V_94 , V_23 -> V_15 ) ;
if ( V_23 -> V_88 < V_141 ) {
V_140 = F_118 () ;
F_119 ( V_140 ) ;
F_120 ( V_14 ) ;
F_121 () ;
V_23 -> V_88 = 0 ;
}
}
}
V_136:
if ( V_23 -> V_59 > 0 ) {
unsigned long V_93 = F_5 ( & V_23 -> V_95 ) ;
V_23 -> V_59 = 0 ;
F_113 ( V_93 == 0 ) ;
V_93 = F_27 ( V_93 ) ;
if ( V_93 > V_14 -> V_27 )
V_14 -> V_27 = V_93 ;
}
F_122 ( V_28 , V_23 -> V_94 ,
V_23 -> V_93 , V_29 , V_134 , V_121 ) ;
if ( V_121 == V_107 )
V_121 = V_118 ;
return V_121 ;
}
static enum V_105 F_123 ( struct V_14 * V_14 , int V_15 ,
T_5 V_133 , enum V_142 V_38 , int * V_42 ,
unsigned int V_113 , int V_112 )
{
enum V_105 V_121 ;
struct V_22 V_23 = {
. V_59 = 0 ,
. V_60 = 0 ,
. V_15 = V_15 ,
. V_133 = V_133 ,
. V_14 = V_14 ,
. V_38 = V_38 ,
. V_113 = V_113 ,
. V_112 = V_112 ,
. V_83 = true ,
} ;
F_124 ( & V_23 . V_95 ) ;
F_124 ( & V_23 . V_67 ) ;
V_121 = F_111 ( V_14 , & V_23 ) ;
F_113 ( ! F_63 ( & V_23 . V_95 ) ) ;
F_113 ( ! F_63 ( & V_23 . V_67 ) ) ;
* V_42 = V_23 . V_42 ;
return V_121 ;
}
enum V_105 F_125 ( T_5 V_133 , unsigned int V_15 ,
unsigned int V_113 , const struct V_128 * V_129 ,
enum V_142 V_38 , int * V_42 )
{
int V_143 = V_133 & V_144 ;
int V_145 = V_133 & V_146 ;
struct V_130 * V_131 ;
struct V_14 * V_14 ;
enum V_105 V_147 = V_124 ;
int V_148 = V_43 ;
* V_42 = V_149 ;
if ( ! V_15 || ! V_143 || ! V_145 )
return V_124 ;
F_126 ( V_15 , V_133 , V_38 ) ;
F_107 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
enum V_105 V_150 ;
int V_151 ;
if ( F_19 ( V_14 , V_15 ) ) {
V_147 = F_127 ( enum V_105 , V_152 , V_147 ) ;
continue;
}
V_150 = F_123 ( V_14 , V_15 , V_133 , V_38 ,
& V_151 , V_113 ,
F_110 ( V_129 ) ) ;
V_147 = F_128 ( V_150 , V_147 ) ;
V_148 &= V_151 ;
if ( F_96 ( V_14 , V_15 , F_95 ( V_14 ) ,
F_110 ( V_129 ) , V_113 ) ) {
F_21 ( V_14 , V_15 , false ) ;
if ( V_151 == V_46 )
* V_42 = V_46 ;
goto V_153;
}
if ( V_38 != V_39 && ( V_150 == V_109 ||
V_150 == V_110 ) ) {
F_17 ( V_14 , V_15 ) ;
}
if ( ( V_151 == V_46 )
|| F_44 ( V_45 ) ) {
* V_42 = V_46 ;
goto V_153;
}
continue;
V_153:
V_148 = 0 ;
break;
}
if ( V_147 > V_154 && V_148 )
* V_42 = V_43 ;
return V_147 ;
}
static void F_129 ( T_1 * V_32 , struct V_22 * V_23 )
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
F_124 ( & V_23 -> V_95 ) ;
F_124 ( & V_23 -> V_67 ) ;
if ( F_93 ( V_23 -> V_15 ) )
F_29 ( V_14 ) ;
if ( F_93 ( V_23 -> V_15 ) ||
! F_19 ( V_14 , V_23 -> V_15 ) )
F_111 ( V_14 , V_23 ) ;
F_113 ( ! F_63 ( & V_23 -> V_95 ) ) ;
F_113 ( ! F_63 ( & V_23 -> V_67 ) ) ;
if ( F_93 ( V_23 -> V_15 ) )
continue;
if ( F_96 ( V_14 , V_23 -> V_15 ,
F_95 ( V_14 ) , 0 , 0 ) )
F_21 ( V_14 , V_23 -> V_15 , false ) ;
}
}
void F_130 ( T_1 * V_32 , int V_15 )
{
struct V_22 V_23 = {
. V_15 = V_15 ,
. V_38 = V_39 ,
} ;
if ( ! V_15 )
return;
F_129 ( V_32 , & V_23 ) ;
}
static void F_131 ( int V_155 )
{
struct V_22 V_23 = {
. V_15 = - 1 ,
. V_38 = V_156 ,
. V_24 = true ,
} ;
F_129 ( F_132 ( V_155 ) , & V_23 ) ;
}
static void F_133 ( void )
{
int V_155 ;
F_134 () ;
F_135 (nid)
F_131 ( V_155 ) ;
}
int F_136 ( struct V_157 * V_158 , int V_159 ,
void T_6 * V_160 , T_7 * V_161 , T_8 * V_162 )
{
if ( V_159 )
F_133 () ;
return 0 ;
}
int F_137 ( struct V_157 * V_158 , int V_159 ,
void T_6 * V_160 , T_7 * V_161 , T_8 * V_162 )
{
F_138 ( V_158 , V_159 , V_160 , V_161 , V_162 ) ;
return 0 ;
}
static T_9 F_139 ( struct V_163 * V_164 ,
struct V_165 * V_166 ,
const char * V_167 , T_7 V_66 )
{
int V_155 = V_164 -> V_168 ;
if ( V_155 >= 0 && V_155 < V_169 && F_140 ( V_155 ) ) {
F_134 () ;
F_131 ( V_155 ) ;
}
return V_66 ;
}
int F_141 ( struct V_170 * V_170 )
{
return F_142 ( & V_170 -> V_164 , & V_171 ) ;
}
void F_143 ( struct V_170 * V_170 )
{
return F_144 ( & V_170 -> V_164 , & V_171 ) ;
}
static inline bool F_145 ( T_1 * V_32 )
{
return V_32 -> V_172 > 0 || F_146 () ;
}
static bool F_147 ( T_1 * V_32 )
{
int V_33 ;
struct V_14 * V_14 ;
enum V_173 V_112 = V_32 -> V_174 ;
for ( V_33 = 0 ; V_33 <= V_112 ; V_33 ++ ) {
V_14 = & V_32 -> V_35 [ V_33 ] ;
if ( ! F_36 ( V_14 ) )
continue;
if ( F_104 ( V_14 , V_32 -> V_172 , 0 ,
V_112 ) == V_111 )
return true ;
}
return false ;
}
static void F_148 ( T_1 * V_32 )
{
int V_33 ;
struct V_14 * V_14 ;
struct V_22 V_23 = {
. V_15 = V_32 -> V_172 ,
. V_112 = V_32 -> V_174 ,
. V_38 = V_175 ,
. V_24 = true ,
} ;
bool V_176 = false ;
F_149 ( V_32 -> V_177 , V_23 . V_15 ,
V_23 . V_112 ) ;
F_2 ( V_178 ) ;
for ( V_33 = 0 ; V_33 <= V_23 . V_112 ; V_33 ++ ) {
int V_150 ;
V_14 = & V_32 -> V_35 [ V_33 ] ;
if ( ! F_36 ( V_14 ) )
continue;
if ( F_19 ( V_14 , V_23 . V_15 ) )
continue;
if ( F_104 ( V_14 , V_23 . V_15 , 0 , V_33 ) !=
V_111 )
continue;
V_23 . V_59 = 0 ;
V_23 . V_60 = 0 ;
V_23 . V_14 = V_14 ;
F_124 ( & V_23 . V_95 ) ;
F_124 ( & V_23 . V_67 ) ;
if ( F_146 () )
return;
V_150 = F_111 ( V_14 , & V_23 ) ;
if ( F_96 ( V_14 , V_23 . V_15 , F_95 ( V_14 ) ,
V_23 . V_112 , 0 ) ) {
V_176 = true ;
F_21 ( V_14 , V_23 . V_15 , false ) ;
} else if ( V_150 == V_110 || V_150 == V_109 ) {
F_17 ( V_14 , V_23 . V_15 ) ;
}
F_113 ( ! F_63 ( & V_23 . V_95 ) ) ;
F_113 ( ! F_63 ( & V_23 . V_67 ) ) ;
}
if ( V_32 -> V_172 <= V_23 . V_15 )
V_32 -> V_172 = 0 ;
if ( V_32 -> V_174 >= V_23 . V_112 )
V_32 -> V_174 = V_32 -> V_179 - 1 ;
}
void F_150 ( T_1 * V_32 , int V_15 , int V_112 )
{
if ( ! V_15 )
return;
if ( V_32 -> V_172 < V_15 )
V_32 -> V_172 = V_15 ;
if ( V_32 -> V_174 > V_112 )
V_32 -> V_174 = V_112 ;
if ( ! F_151 ( & V_32 -> V_180 ) )
return;
if ( ! F_147 ( V_32 ) )
return;
F_152 ( V_32 -> V_177 , V_15 ,
V_112 ) ;
F_153 ( & V_32 -> V_180 ) ;
}
static int F_154 ( void * V_181 )
{
T_1 * V_32 = ( T_1 * ) V_181 ;
struct V_182 * V_183 = V_45 ;
const struct V_184 * V_184 = F_155 ( V_32 -> V_177 ) ;
if ( ! F_156 ( V_184 ) )
F_157 ( V_183 , V_184 ) ;
F_158 () ;
V_32 -> V_172 = 0 ;
V_32 -> V_174 = V_32 -> V_179 - 1 ;
while ( ! F_146 () ) {
F_159 ( V_32 -> V_177 ) ;
F_160 ( V_32 -> V_180 ,
F_145 ( V_32 ) ) ;
F_148 ( V_32 ) ;
}
return 0 ;
}
int F_161 ( int V_155 )
{
T_1 * V_32 = F_132 ( V_155 ) ;
int V_121 = 0 ;
if ( V_32 -> F_154 )
return 0 ;
V_32 -> F_154 = F_162 ( F_154 , V_32 , L_1 , V_155 ) ;
if ( F_163 ( V_32 -> F_154 ) ) {
F_164 ( L_2 , V_155 ) ;
V_121 = F_165 ( V_32 -> F_154 ) ;
V_32 -> F_154 = NULL ;
}
return V_121 ;
}
void F_166 ( int V_155 )
{
struct V_182 * F_154 = F_132 ( V_155 ) -> F_154 ;
if ( F_154 ) {
F_167 ( F_154 ) ;
F_132 ( V_155 ) -> F_154 = NULL ;
}
}
static int F_168 ( struct V_185 * V_186 , unsigned long V_187 ,
void * V_188 )
{
int V_155 ;
if ( V_187 == V_189 || V_187 == V_190 ) {
F_169 (nid, N_MEMORY) {
T_1 * V_32 = F_132 ( V_155 ) ;
const struct V_184 * V_191 ;
V_191 = F_155 ( V_32 -> V_177 ) ;
if ( F_170 ( V_192 , V_191 ) < V_193 )
F_157 ( V_32 -> F_154 , V_191 ) ;
}
}
return V_194 ;
}
static int T_10 F_171 ( void )
{
int V_155 ;
F_169 (nid, N_MEMORY)
F_161 ( V_155 ) ;
F_172 ( F_168 , 0 ) ;
return 0 ;
}
