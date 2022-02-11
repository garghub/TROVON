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
unsigned int V_12 , V_13 , V_14 ;
struct V_6 * V_6 , * V_7 ;
F_11 ( V_15 ) ;
F_6 (page, next, list, lru) {
F_8 ( & V_6 -> V_10 ) ;
V_13 = F_12 ( V_6 ) ;
V_14 = 1 << V_13 ;
F_13 ( V_6 , V_13 , V_16 ) ;
if ( V_13 )
F_14 ( V_6 , V_13 ) ;
for ( V_12 = 0 ; V_12 < V_14 ; V_12 ++ ) {
F_15 ( & V_6 -> V_10 , & V_15 ) ;
V_6 ++ ;
}
}
F_16 ( & V_15 , V_11 ) ;
}
int F_17 ( struct V_6 * V_6 )
{
struct V_17 * V_18 ;
F_18 ( ! F_19 ( V_6 ) , V_6 ) ;
if ( ! F_20 ( V_6 ) )
return 0 ;
V_18 = F_21 ( V_6 ) ;
if ( V_18 && V_18 -> V_19 && V_18 -> V_19 -> V_20 )
return 1 ;
return 0 ;
}
void F_22 ( struct V_6 * V_6 , struct V_17 * V_18 )
{
F_18 ( ! F_19 ( V_6 ) , V_6 ) ;
F_18 ( ( unsigned long ) V_18 & V_21 , V_6 ) ;
V_6 -> V_18 = ( void * ) ( ( unsigned long ) V_18 | V_21 ) ;
}
void F_23 ( struct V_6 * V_6 )
{
F_18 ( ! F_19 ( V_6 ) , V_6 ) ;
F_18 ( ! F_17 ( V_6 ) , V_6 ) ;
V_6 -> V_18 = ( void * ) ( ( unsigned long ) V_6 -> V_18 &
V_21 ) ;
}
void F_24 ( struct V_22 * V_22 , int V_13 )
{
V_22 -> V_23 = 0 ;
V_22 -> V_24 ++ ;
if ( V_13 < V_22 -> V_25 )
V_22 -> V_25 = V_13 ;
if ( V_22 -> V_24 > V_26 )
V_22 -> V_24 = V_26 ;
F_25 ( V_22 , V_13 ) ;
}
bool F_26 ( struct V_22 * V_22 , int V_13 )
{
unsigned long V_27 = 1UL << V_22 -> V_24 ;
if ( V_13 < V_22 -> V_25 )
return false ;
if ( ++ V_22 -> V_23 > V_27 )
V_22 -> V_23 = V_27 ;
if ( V_22 -> V_23 >= V_27 )
return false ;
F_27 ( V_22 , V_13 ) ;
return true ;
}
void F_28 ( struct V_22 * V_22 , int V_13 ,
bool V_28 )
{
if ( V_28 ) {
V_22 -> V_23 = 0 ;
V_22 -> V_24 = 0 ;
}
if ( V_13 >= V_22 -> V_25 )
V_22 -> V_25 = V_13 + 1 ;
F_29 ( V_22 , V_13 ) ;
}
bool F_30 ( struct V_22 * V_22 , int V_13 )
{
if ( V_13 < V_22 -> V_25 )
return false ;
return V_22 -> V_24 == V_26 &&
V_22 -> V_23 >= 1UL << V_22 -> V_24 ;
}
static inline bool F_31 ( struct V_29 * V_30 ,
struct V_6 * V_6 )
{
if ( V_30 -> V_31 )
return true ;
return ! F_32 ( V_6 ) ;
}
static void F_33 ( struct V_22 * V_22 )
{
V_22 -> V_32 [ 0 ] = V_22 -> V_33 ;
V_22 -> V_32 [ 1 ] = V_22 -> V_33 ;
V_22 -> V_34 =
F_34 ( F_35 ( V_22 ) - 1 ) ;
}
static void F_36 ( struct V_22 * V_22 )
{
unsigned long V_35 = V_22 -> V_33 ;
unsigned long V_36 = F_35 ( V_22 ) ;
unsigned long V_9 ;
V_22 -> V_37 = false ;
for ( V_9 = V_35 ; V_9 < V_36 ; V_9 += V_38 ) {
struct V_6 * V_6 ;
F_37 () ;
V_6 = F_38 ( V_9 ) ;
if ( ! V_6 )
continue;
if ( V_22 != F_39 ( V_6 ) )
continue;
F_40 ( V_6 ) ;
}
F_33 ( V_22 ) ;
}
void F_41 ( T_1 * V_39 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
struct V_22 * V_22 = & V_39 -> V_42 [ V_40 ] ;
if ( ! F_42 ( V_22 ) )
continue;
if ( V_22 -> V_37 )
F_36 ( V_22 ) ;
}
}
static void F_43 ( struct V_29 * V_30 ,
struct V_6 * V_6 , unsigned long V_43 ,
bool V_44 )
{
struct V_22 * V_22 = V_30 -> V_22 ;
unsigned long V_9 ;
if ( V_30 -> V_31 )
return;
if ( ! V_6 )
return;
if ( V_43 )
return;
F_44 ( V_6 ) ;
V_9 = F_7 ( V_6 ) ;
if ( V_44 ) {
if ( V_9 > V_22 -> V_32 [ 0 ] )
V_22 -> V_32 [ 0 ] = V_9 ;
if ( V_30 -> V_45 != V_46 &&
V_9 > V_22 -> V_32 [ 1 ] )
V_22 -> V_32 [ 1 ] = V_9 ;
} else {
if ( V_9 < V_22 -> V_34 )
V_22 -> V_34 = V_9 ;
}
}
static inline bool F_31 ( struct V_29 * V_30 ,
struct V_6 * V_6 )
{
return true ;
}
static void F_43 ( struct V_29 * V_30 ,
struct V_6 * V_6 , unsigned long V_43 ,
bool V_44 )
{
}
static bool F_45 ( T_2 * V_47 , unsigned long * V_48 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_45 == V_46 ) {
if ( ! F_46 ( V_47 , * V_48 ) ) {
V_30 -> V_49 = true ;
return false ;
}
} else {
F_47 ( V_47 , * V_48 ) ;
}
return true ;
}
static bool F_48 ( T_2 * V_47 ,
unsigned long V_48 , bool * V_50 , struct V_29 * V_30 )
{
if ( * V_50 ) {
F_49 ( V_47 , V_48 ) ;
* V_50 = false ;
}
if ( F_50 ( V_51 ) ) {
V_30 -> V_49 = true ;
return true ;
}
if ( F_51 () ) {
if ( V_30 -> V_45 == V_46 ) {
V_30 -> V_49 = true ;
return true ;
}
F_37 () ;
}
return false ;
}
static inline bool F_52 ( struct V_29 * V_30 )
{
if ( F_51 () ) {
if ( V_30 -> V_45 == V_46 ) {
V_30 -> V_49 = true ;
return true ;
}
F_37 () ;
}
return false ;
}
static unsigned long F_53 ( struct V_29 * V_30 ,
unsigned long * V_35 ,
unsigned long V_36 ,
struct V_4 * V_5 ,
bool V_52 )
{
int V_53 = 0 , V_54 = 0 ;
struct V_6 * V_55 , * V_56 = NULL ;
unsigned long V_48 = 0 ;
bool V_50 = false ;
unsigned long V_57 = * V_35 ;
unsigned int V_13 ;
V_55 = F_54 ( V_57 ) ;
for (; V_57 < V_36 ; V_57 ++ , V_55 ++ ) {
int V_58 ;
struct V_6 * V_6 = V_55 ;
if ( ! ( V_57 % V_59 )
&& F_48 ( & V_30 -> V_22 -> V_47 , V_48 ,
& V_50 , V_30 ) )
break;
V_53 ++ ;
if ( ! F_55 ( V_57 ) )
goto V_60;
if ( ! V_56 )
V_56 = V_6 ;
if ( F_56 ( V_6 ) ) {
unsigned int V_61 = F_57 ( V_6 ) ;
if ( F_58 ( V_61 < V_62 ) ) {
V_57 += ( 1UL << V_61 ) - 1 ;
V_55 += ( 1UL << V_61 ) - 1 ;
}
goto V_60;
}
if ( ! F_59 ( V_6 ) )
goto V_60;
if ( ! V_50 ) {
V_50 = F_45 ( & V_30 -> V_22 -> V_47 ,
& V_48 , V_30 ) ;
if ( ! V_50 )
break;
if ( ! F_59 ( V_6 ) )
goto V_60;
}
V_13 = F_60 ( V_6 ) ;
V_58 = F_61 ( V_6 , V_13 ) ;
if ( ! V_58 )
break;
F_62 ( V_6 , V_13 ) ;
V_54 += V_58 ;
V_30 -> V_63 += V_58 ;
F_63 ( & V_6 -> V_10 , V_5 ) ;
if ( ! V_52 && V_30 -> V_64 <= V_30 -> V_63 ) {
V_57 += V_58 ;
break;
}
V_57 += V_58 - 1 ;
V_55 += V_58 - 1 ;
continue;
V_60:
if ( V_52 )
break;
else
continue;
}
if ( V_50 )
F_49 ( & V_30 -> V_22 -> V_47 , V_48 ) ;
if ( F_64 ( V_57 > V_36 ) )
V_57 = V_36 ;
F_65 ( * V_35 , V_57 ,
V_53 , V_54 ) ;
* V_35 = V_57 ;
if ( V_52 && V_57 < V_36 )
V_54 = 0 ;
if ( V_57 == V_36 )
F_43 ( V_30 , V_56 , V_54 , false ) ;
V_30 -> V_65 += V_53 ;
if ( V_54 )
F_3 ( V_66 , V_54 ) ;
return V_54 ;
}
unsigned long
F_66 ( struct V_29 * V_30 ,
unsigned long V_35 , unsigned long V_36 )
{
unsigned long V_58 , V_9 , V_67 , V_68 ;
F_11 ( V_5 ) ;
V_9 = V_35 ;
V_67 = F_34 ( V_9 ) ;
if ( V_67 < V_30 -> V_22 -> V_33 )
V_67 = V_30 -> V_22 -> V_33 ;
V_68 = F_67 ( V_9 ) ;
for (; V_9 < V_36 ; V_9 += V_58 ,
V_67 = V_68 ,
V_68 += V_38 ) {
unsigned long V_69 = V_9 ;
V_68 = F_68 ( V_68 , V_36 ) ;
if ( V_9 >= V_68 ) {
V_67 = F_34 ( V_9 ) ;
V_68 = F_67 ( V_9 ) ;
V_68 = F_68 ( V_68 , V_36 ) ;
}
if ( ! F_69 ( V_67 ,
V_68 , V_30 -> V_22 ) )
break;
V_58 = F_53 ( V_30 , & V_69 ,
V_68 , & V_5 , true ) ;
if ( ! V_58 )
break;
}
F_10 ( & V_5 ) ;
if ( V_9 < V_36 ) {
F_5 ( & V_5 ) ;
return 0 ;
}
return V_9 ;
}
static bool F_70 ( struct V_22 * V_22 )
{
unsigned long V_70 , V_71 , V_58 ;
V_71 = F_71 ( V_22 -> V_72 , V_73 ) +
F_71 ( V_22 -> V_72 , V_74 ) ;
V_70 = F_71 ( V_22 -> V_72 , V_75 ) +
F_71 ( V_22 -> V_72 , V_76 ) ;
V_58 = F_71 ( V_22 -> V_72 , V_77 ) +
F_71 ( V_22 -> V_72 , V_78 ) ;
return V_58 > ( V_71 + V_70 ) / 2 ;
}
static unsigned long
F_72 ( struct V_29 * V_30 , unsigned long V_79 ,
unsigned long V_36 , T_3 V_80 )
{
struct V_22 * V_22 = V_30 -> V_22 ;
unsigned long V_53 = 0 , V_43 = 0 ;
struct V_81 * V_81 ;
unsigned long V_48 = 0 ;
bool V_50 = false ;
struct V_6 * V_6 = NULL , * V_56 = NULL ;
unsigned long V_35 = V_79 ;
bool V_82 = false ;
unsigned long V_83 = 0 ;
while ( F_64 ( F_70 ( V_22 ) ) ) {
if ( V_30 -> V_45 == V_46 )
return 0 ;
F_73 ( V_84 , V_85 / 10 ) ;
if ( F_50 ( V_51 ) )
return 0 ;
}
if ( F_52 ( V_30 ) )
return 0 ;
if ( V_30 -> V_86 && ( V_30 -> V_45 == V_46 ) ) {
V_82 = true ;
V_83 = V_68 ( V_79 , V_30 -> V_13 ) ;
}
for (; V_79 < V_36 ; V_79 ++ ) {
if ( V_82 && V_79 >= V_83 ) {
if ( V_43 )
break;
V_83 = V_68 ( V_79 , V_30 -> V_13 ) ;
}
if ( ! ( V_79 % V_59 )
&& F_48 ( F_74 ( V_22 ) , V_48 ,
& V_50 , V_30 ) )
break;
if ( ! F_55 ( V_79 ) )
goto V_60;
V_53 ++ ;
V_6 = F_54 ( V_79 ) ;
if ( ! V_56 )
V_56 = V_6 ;
if ( F_59 ( V_6 ) ) {
unsigned long V_87 = F_75 ( V_6 ) ;
if ( V_87 > 0 && V_87 < V_62 )
V_79 += ( 1UL << V_87 ) - 1 ;
continue;
}
if ( F_56 ( V_6 ) ) {
unsigned int V_61 = F_57 ( V_6 ) ;
if ( F_58 ( V_61 < V_62 ) )
V_79 += ( 1UL << V_61 ) - 1 ;
goto V_60;
}
if ( ! F_76 ( V_6 ) ) {
if ( F_64 ( F_20 ( V_6 ) ) &&
! F_77 ( V_6 ) ) {
if ( V_50 ) {
F_49 ( F_74 ( V_22 ) ,
V_48 ) ;
V_50 = false ;
}
if ( ! F_78 ( V_6 , V_80 ) )
goto V_88;
}
goto V_60;
}
if ( ! F_21 ( V_6 ) &&
F_79 ( V_6 ) > F_80 ( V_6 ) )
goto V_60;
if ( ! ( V_30 -> V_89 & V_90 ) && F_21 ( V_6 ) )
goto V_60;
if ( ! V_50 ) {
V_50 = F_45 ( F_74 ( V_22 ) ,
& V_48 , V_30 ) ;
if ( ! V_50 )
break;
if ( ! F_76 ( V_6 ) )
goto V_60;
if ( F_64 ( F_56 ( V_6 ) ) ) {
V_79 += ( 1UL << F_57 ( V_6 ) ) - 1 ;
goto V_60;
}
}
V_81 = F_81 ( V_6 , V_22 -> V_72 ) ;
if ( F_82 ( V_6 , V_80 ) != 0 )
goto V_60;
F_18 ( F_56 ( V_6 ) , V_6 ) ;
F_83 ( V_6 , V_81 , F_84 ( V_6 ) ) ;
F_85 ( V_6 ,
V_78 + F_86 ( V_6 ) ) ;
V_88:
F_15 ( & V_6 -> V_10 , & V_30 -> V_91 ) ;
V_30 -> V_64 ++ ;
V_43 ++ ;
if ( ! V_30 -> V_92 )
V_30 -> V_92 = V_79 ;
if ( V_30 -> V_64 == V_93 ) {
++ V_79 ;
break;
}
continue;
V_60:
if ( ! V_82 )
continue;
if ( V_43 ) {
if ( V_50 ) {
F_49 ( F_74 ( V_22 ) , V_48 ) ;
V_50 = false ;
}
F_87 ( & V_30 -> V_91 ) ;
V_30 -> V_64 = 0 ;
V_30 -> V_92 = 0 ;
V_43 = 0 ;
}
if ( V_79 < V_83 ) {
V_79 = V_83 - 1 ;
V_83 += 1UL << V_30 -> V_13 ;
}
}
if ( F_64 ( V_79 > V_36 ) )
V_79 = V_36 ;
if ( V_50 )
F_49 ( F_74 ( V_22 ) , V_48 ) ;
if ( V_79 == V_36 )
F_43 ( V_30 , V_56 , V_43 , true ) ;
F_88 ( V_35 , V_79 ,
V_53 , V_43 ) ;
V_30 -> V_94 += V_53 ;
if ( V_43 )
F_3 ( V_66 , V_43 ) ;
return V_79 ;
}
unsigned long
F_89 ( struct V_29 * V_30 , unsigned long V_35 ,
unsigned long V_36 )
{
unsigned long V_9 , V_67 , V_68 ;
V_9 = V_35 ;
V_67 = F_34 ( V_9 ) ;
if ( V_67 < V_30 -> V_22 -> V_33 )
V_67 = V_30 -> V_22 -> V_33 ;
V_68 = F_67 ( V_9 ) ;
for (; V_9 < V_36 ; V_9 = V_68 ,
V_67 = V_68 ,
V_68 += V_38 ) {
V_68 = F_68 ( V_68 , V_36 ) ;
if ( ! F_69 ( V_67 ,
V_68 , V_30 -> V_22 ) )
continue;
V_9 = F_72 ( V_30 , V_9 , V_68 ,
V_95 ) ;
if ( ! V_9 )
break;
if ( V_30 -> V_64 == V_93 )
break;
}
return V_9 ;
}
static bool F_90 ( struct V_29 * V_30 ,
struct V_6 * V_6 )
{
int V_96 ;
if ( ( V_30 -> V_45 != V_46 ) || ! V_30 -> V_86 )
return true ;
V_96 = F_91 ( V_6 ) ;
if ( V_30 -> V_97 == V_98 )
return F_92 ( V_96 ) ;
else
return V_96 == V_30 -> V_97 ;
}
static bool F_93 ( struct V_29 * V_30 ,
struct V_6 * V_6 )
{
if ( F_59 ( V_6 ) ) {
if ( F_75 ( V_6 ) >= V_99 )
return false ;
}
if ( V_30 -> V_100 )
return true ;
if ( F_92 ( F_91 ( V_6 ) ) )
return true ;
return false ;
}
static inline bool F_94 ( struct V_29 * V_30 )
{
return ( V_30 -> V_101 >> V_99 )
<= ( V_30 -> V_102 >> V_99 ) ;
}
static void F_95 ( struct V_29 * V_30 )
{
struct V_22 * V_22 = V_30 -> V_22 ;
struct V_6 * V_6 ;
unsigned long V_67 ;
unsigned long V_69 ;
unsigned long V_68 ;
unsigned long V_79 ;
struct V_4 * V_5 = & V_30 -> V_103 ;
V_69 = V_30 -> V_101 ;
V_67 = F_34 ( V_30 -> V_101 ) ;
V_68 = F_68 ( V_67 + V_38 ,
F_35 ( V_22 ) ) ;
V_79 = F_67 ( V_30 -> V_102 ) ;
for (; V_67 >= V_79 ;
V_68 = V_67 ,
V_67 -= V_38 ,
V_69 = V_67 ) {
if ( ! ( V_67 % ( V_59 * V_38 ) )
&& F_52 ( V_30 ) )
break;
V_6 = F_69 ( V_67 , V_68 ,
V_22 ) ;
if ( ! V_6 )
continue;
if ( ! F_93 ( V_30 , V_6 ) )
continue;
if ( ! F_31 ( V_30 , V_6 ) )
continue;
F_53 ( V_30 , & V_69 , V_68 ,
V_5 , false ) ;
if ( ( V_30 -> V_63 >= V_30 -> V_64 )
|| V_30 -> V_49 ) {
if ( V_69 >= V_68 ) {
V_69 =
V_67 - V_38 ;
}
break;
} else if ( V_69 < V_68 ) {
break;
}
}
F_10 ( V_5 ) ;
V_30 -> V_101 = V_69 ;
}
static struct V_6 * F_96 ( struct V_6 * V_104 ,
unsigned long V_105 ,
int * * V_106 )
{
struct V_29 * V_30 = (struct V_29 * ) V_105 ;
struct V_6 * V_107 ;
if ( F_97 ( & V_30 -> V_103 ) ) {
if ( ! V_30 -> V_49 )
F_95 ( V_30 ) ;
if ( F_97 ( & V_30 -> V_103 ) )
return NULL ;
}
V_107 = F_98 ( V_30 -> V_103 . V_7 , struct V_6 , V_10 ) ;
F_8 ( & V_107 -> V_10 ) ;
V_30 -> V_63 -- ;
return V_107 ;
}
static void F_99 ( struct V_6 * V_6 , unsigned long V_105 )
{
struct V_29 * V_30 = (struct V_29 * ) V_105 ;
F_15 ( & V_6 -> V_10 , & V_30 -> V_103 ) ;
V_30 -> V_63 ++ ;
}
static T_4 F_100 ( struct V_22 * V_22 ,
struct V_29 * V_30 )
{
unsigned long V_67 ;
unsigned long V_68 ;
unsigned long V_79 ;
struct V_6 * V_6 ;
const T_3 V_80 =
( V_108 ? V_95 : 0 ) |
( V_30 -> V_45 != V_109 ? V_110 : 0 ) ;
V_79 = V_30 -> V_102 ;
V_67 = F_34 ( V_79 ) ;
if ( V_67 < V_22 -> V_33 )
V_67 = V_22 -> V_33 ;
V_68 = F_67 ( V_79 ) ;
for (; V_68 <= V_30 -> V_101 ;
V_79 = V_68 ,
V_67 = V_68 ,
V_68 += V_38 ) {
if ( ! ( V_79 % ( V_59 * V_38 ) )
&& F_52 ( V_30 ) )
break;
V_6 = F_69 ( V_67 , V_68 ,
V_22 ) ;
if ( ! V_6 )
continue;
if ( ! F_31 ( V_30 , V_6 ) )
continue;
if ( ! F_90 ( V_30 , V_6 ) )
continue;
V_79 = F_72 ( V_30 , V_79 ,
V_68 , V_80 ) ;
if ( ! V_79 || V_30 -> V_49 )
return V_111 ;
break;
}
V_30 -> V_102 = V_79 ;
return V_30 -> V_64 ? V_112 : V_113 ;
}
static inline bool F_101 ( int V_13 )
{
return V_13 == - 1 ;
}
static enum V_114 F_102 ( struct V_22 * V_22 ,
struct V_29 * V_30 )
{
unsigned int V_13 ;
const int V_97 = V_30 -> V_97 ;
if ( V_30 -> V_49 || F_50 ( V_51 ) )
return V_115 ;
if ( F_94 ( V_30 ) ) {
F_33 ( V_22 ) ;
if ( V_30 -> V_86 )
V_22 -> V_37 = true ;
if ( V_30 -> V_116 )
return V_117 ;
else
return V_118 ;
}
if ( F_101 ( V_30 -> V_13 ) )
return V_119 ;
if ( V_30 -> V_120 ) {
if ( F_103 ( V_30 -> V_102 , V_38 ) )
V_30 -> V_120 = false ;
else
return V_119 ;
}
for ( V_13 = V_30 -> V_13 ; V_13 < V_62 ; V_13 ++ ) {
struct V_121 * V_122 = & V_22 -> V_121 [ V_13 ] ;
bool V_123 ;
if ( ! F_97 ( & V_122 -> V_124 [ V_97 ] ) )
return V_125 ;
#ifdef F_104
if ( V_97 == V_98 &&
! F_97 ( & V_122 -> V_124 [ V_126 ] ) )
return V_125 ;
#endif
if ( F_105 ( V_122 , V_13 , V_97 ,
true , & V_123 ) != - 1 ) {
if ( V_97 == V_98 )
return V_125 ;
if ( V_30 -> V_45 == V_46 ||
F_103 ( V_30 -> V_102 ,
V_38 ) ) {
return V_125 ;
}
V_30 -> V_120 = true ;
return V_119 ;
}
}
return V_127 ;
}
static enum V_114 F_106 ( struct V_22 * V_22 ,
struct V_29 * V_30 )
{
int V_128 ;
V_128 = F_102 ( V_22 , V_30 ) ;
F_107 ( V_22 , V_30 -> V_13 , V_128 ) ;
if ( V_128 == V_127 )
V_128 = V_119 ;
return V_128 ;
}
static enum V_114 F_108 ( struct V_22 * V_22 , int V_13 ,
unsigned int V_129 ,
int V_130 ,
unsigned long V_131 )
{
unsigned long V_132 ;
if ( F_101 ( V_13 ) )
return V_119 ;
V_132 = V_22 -> V_132 [ V_129 & V_133 ] ;
if ( F_109 ( V_22 , V_13 , V_132 , V_130 ,
V_129 ) )
return V_125 ;
V_132 = ( V_13 > V_134 ) ?
F_110 ( V_22 ) : F_111 ( V_22 ) ;
V_132 += F_112 ( V_13 ) ;
if ( ! F_113 ( V_22 , 0 , V_132 , V_130 ,
V_135 , V_131 ) )
return V_136 ;
return V_119 ;
}
enum V_114 F_114 ( struct V_22 * V_22 , int V_13 ,
unsigned int V_129 ,
int V_130 )
{
enum V_114 V_128 ;
int V_137 ;
V_128 = F_108 ( V_22 , V_13 , V_129 , V_130 ,
F_115 ( V_22 , V_138 ) ) ;
if ( V_128 == V_119 && ( V_13 > V_134 ) ) {
V_137 = F_116 ( V_22 , V_13 ) ;
if ( V_137 >= 0 && V_137 <= V_139 )
V_128 = V_140 ;
}
F_117 ( V_22 , V_13 , V_128 ) ;
if ( V_128 == V_140 )
V_128 = V_136 ;
return V_128 ;
}
bool F_118 ( struct V_141 * V_142 , int V_13 ,
int V_129 )
{
struct V_22 * V_22 ;
struct V_143 * V_144 ;
F_119 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long V_145 ;
enum V_114 V_114 ;
V_145 = F_120 ( V_22 ) / V_13 ;
V_145 += F_121 ( V_22 , V_138 ) ;
V_114 = F_108 ( V_22 , V_13 , V_129 ,
F_122 ( V_142 ) , V_145 ) ;
if ( V_114 != V_136 )
return true ;
}
return false ;
}
static enum V_114 F_123 ( struct V_22 * V_22 , struct V_29 * V_30 )
{
enum V_114 V_128 ;
unsigned long V_35 = V_22 -> V_33 ;
unsigned long V_36 = F_35 ( V_22 ) ;
const bool V_146 = V_30 -> V_45 != V_46 ;
V_30 -> V_97 = F_124 ( V_30 -> V_89 ) ;
V_128 = F_114 ( V_22 , V_30 -> V_13 , V_30 -> V_129 ,
V_30 -> V_130 ) ;
if ( V_128 == V_125 || V_128 == V_136 )
return V_128 ;
F_125 ( V_128 != V_119 ) ;
if ( F_30 ( V_22 , V_30 -> V_13 ) )
F_36 ( V_22 ) ;
if ( V_30 -> V_116 ) {
V_30 -> V_102 = V_35 ;
V_30 -> V_101 = F_34 ( V_36 - 1 ) ;
} else {
V_30 -> V_102 = V_22 -> V_32 [ V_146 ] ;
V_30 -> V_101 = V_22 -> V_34 ;
if ( V_30 -> V_101 < V_35 || V_30 -> V_101 >= V_36 ) {
V_30 -> V_101 = F_34 ( V_36 - 1 ) ;
V_22 -> V_34 = V_30 -> V_101 ;
}
if ( V_30 -> V_102 < V_35 || V_30 -> V_102 >= V_36 ) {
V_30 -> V_102 = V_35 ;
V_22 -> V_32 [ 0 ] = V_30 -> V_102 ;
V_22 -> V_32 [ 1 ] = V_30 -> V_102 ;
}
if ( V_30 -> V_102 == V_35 )
V_30 -> V_116 = true ;
}
V_30 -> V_92 = 0 ;
F_126 ( V_35 , V_30 -> V_102 ,
V_30 -> V_101 , V_36 , V_146 ) ;
F_127 () ;
while ( ( V_128 = F_106 ( V_22 , V_30 ) ) == V_119 ) {
int V_147 ;
switch ( F_100 ( V_22 , V_30 ) ) {
case V_111 :
V_128 = V_115 ;
F_87 ( & V_30 -> V_91 ) ;
V_30 -> V_64 = 0 ;
goto V_148;
case V_113 :
goto V_149;
case V_112 :
;
}
V_147 = F_128 ( & V_30 -> V_91 , F_96 ,
F_99 , ( unsigned long ) V_30 , V_30 -> V_45 ,
V_150 ) ;
F_129 ( V_30 -> V_64 , V_147 ,
& V_30 -> V_91 ) ;
V_30 -> V_64 = 0 ;
if ( V_147 ) {
F_87 ( & V_30 -> V_91 ) ;
if ( V_147 == - V_151 && ! F_94 ( V_30 ) ) {
V_128 = V_115 ;
goto V_148;
}
if ( V_30 -> V_86 &&
( V_30 -> V_45 == V_46 ) ) {
V_30 -> V_102 = V_68 (
V_30 -> V_102 - 1 , V_30 -> V_13 ) ;
V_30 -> V_92 = 0 ;
}
}
V_149:
if ( V_30 -> V_13 > 0 && V_30 -> V_92 ) {
int V_152 ;
unsigned long V_153 =
V_67 ( V_30 -> V_102 , V_30 -> V_13 ) ;
if ( V_30 -> V_92 < V_153 ) {
V_152 = F_130 () ;
F_131 ( V_152 ) ;
F_132 ( V_22 ) ;
F_133 () ;
V_30 -> V_92 = 0 ;
}
}
}
V_148:
if ( V_30 -> V_63 > 0 ) {
unsigned long V_101 = F_5 ( & V_30 -> V_103 ) ;
V_30 -> V_63 = 0 ;
F_125 ( V_101 == 0 ) ;
V_101 = F_34 ( V_101 ) ;
if ( V_101 > V_22 -> V_34 )
V_22 -> V_34 = V_101 ;
}
F_3 ( V_154 , V_30 -> V_94 ) ;
F_3 ( V_155 , V_30 -> V_65 ) ;
F_134 ( V_35 , V_30 -> V_102 ,
V_30 -> V_101 , V_36 , V_146 , V_128 ) ;
return V_128 ;
}
static enum V_114 F_135 ( struct V_22 * V_22 , int V_13 ,
T_5 V_89 , enum V_156 V_157 ,
unsigned int V_129 , int V_130 )
{
enum V_114 V_128 ;
struct V_29 V_30 = {
. V_63 = 0 ,
. V_64 = 0 ,
. V_94 = 0 ,
. V_65 = 0 ,
. V_13 = V_13 ,
. V_89 = V_89 ,
. V_22 = V_22 ,
. V_45 = ( V_157 == V_158 ) ?
V_46 : V_159 ,
. V_129 = V_129 ,
. V_130 = V_130 ,
. V_86 = true ,
. V_116 = ( V_157 == V_160 ) ,
. V_31 = ( V_157 == V_160 ) ,
. V_100 = ( V_157 == V_160 )
} ;
F_136 ( & V_30 . V_103 ) ;
F_136 ( & V_30 . V_91 ) ;
V_128 = F_123 ( V_22 , & V_30 ) ;
F_125 ( ! F_97 ( & V_30 . V_103 ) ) ;
F_125 ( ! F_97 ( & V_30 . V_91 ) ) ;
return V_128 ;
}
enum V_114 F_137 ( T_5 V_89 , unsigned int V_13 ,
unsigned int V_129 , const struct V_141 * V_142 ,
enum V_156 V_157 )
{
int V_161 = V_89 & V_162 ;
struct V_143 * V_144 ;
struct V_22 * V_22 ;
enum V_114 V_163 = V_136 ;
if ( ! V_161 )
return V_136 ;
F_138 ( V_13 , V_89 , V_157 ) ;
F_119 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
enum V_114 V_164 ;
if ( V_157 > V_160
&& F_26 ( V_22 , V_13 ) ) {
V_163 = F_139 ( enum V_114 , V_165 , V_163 ) ;
continue;
}
V_164 = F_135 ( V_22 , V_13 , V_89 , V_157 ,
V_129 , F_122 ( V_142 ) ) ;
V_163 = F_140 ( V_164 , V_163 ) ;
if ( V_164 == V_125 ) {
F_28 ( V_22 , V_13 , false ) ;
break;
}
if ( V_157 != V_158 && ( V_164 == V_117 ||
V_164 == V_118 ) )
F_24 ( V_22 , V_13 ) ;
if ( ( V_157 == V_158 && F_51 () )
|| F_50 ( V_51 ) )
break;
}
return V_163 ;
}
static void F_141 ( int V_166 )
{
T_1 * V_39 = F_142 ( V_166 ) ;
int V_40 ;
struct V_22 * V_22 ;
struct V_29 V_30 = {
. V_13 = - 1 ,
. V_94 = 0 ,
. V_65 = 0 ,
. V_45 = V_109 ,
. V_31 = true ,
. V_116 = true ,
. V_89 = V_167 ,
} ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
V_22 = & V_39 -> V_42 [ V_40 ] ;
if ( ! F_42 ( V_22 ) )
continue;
V_30 . V_63 = 0 ;
V_30 . V_64 = 0 ;
V_30 . V_22 = V_22 ;
F_136 ( & V_30 . V_103 ) ;
F_136 ( & V_30 . V_91 ) ;
F_123 ( V_22 , & V_30 ) ;
F_125 ( ! F_97 ( & V_30 . V_103 ) ) ;
F_125 ( ! F_97 ( & V_30 . V_91 ) ) ;
}
}
static void F_143 ( void )
{
int V_166 ;
F_144 () ;
F_145 (nid)
F_141 ( V_166 ) ;
}
int F_146 ( struct V_168 * V_169 , int V_170 ,
void T_6 * V_171 , T_7 * V_172 , T_8 * V_173 )
{
if ( V_170 )
F_143 () ;
return 0 ;
}
int F_147 ( struct V_168 * V_169 , int V_170 ,
void T_6 * V_171 , T_7 * V_172 , T_8 * V_173 )
{
F_148 ( V_169 , V_170 , V_171 , V_172 , V_173 ) ;
return 0 ;
}
static T_9 F_149 ( struct V_174 * V_175 ,
struct V_176 * V_177 ,
const char * V_178 , T_7 V_179 )
{
int V_166 = V_175 -> V_180 ;
if ( V_166 >= 0 && V_166 < V_181 && F_150 ( V_166 ) ) {
F_144 () ;
F_141 ( V_166 ) ;
}
return V_179 ;
}
int F_151 ( struct V_182 * V_182 )
{
return F_152 ( & V_182 -> V_175 , & V_183 ) ;
}
void F_153 ( struct V_182 * V_182 )
{
return F_154 ( & V_182 -> V_175 , & V_183 ) ;
}
static inline bool F_155 ( T_1 * V_39 )
{
return V_39 -> V_184 > 0 || F_156 () ;
}
static bool F_157 ( T_1 * V_39 )
{
int V_40 ;
struct V_22 * V_22 ;
enum V_185 V_130 = V_39 -> V_186 ;
for ( V_40 = 0 ; V_40 <= V_130 ; V_40 ++ ) {
V_22 = & V_39 -> V_42 [ V_40 ] ;
if ( ! F_42 ( V_22 ) )
continue;
if ( F_114 ( V_22 , V_39 -> V_184 , 0 ,
V_130 ) == V_119 )
return true ;
}
return false ;
}
static void F_158 ( T_1 * V_39 )
{
int V_40 ;
struct V_22 * V_22 ;
struct V_29 V_30 = {
. V_13 = V_39 -> V_184 ,
. V_94 = 0 ,
. V_65 = 0 ,
. V_130 = V_39 -> V_186 ,
. V_45 = V_159 ,
. V_31 = true ,
. V_89 = V_167 ,
} ;
F_159 ( V_39 -> V_187 , V_30 . V_13 ,
V_30 . V_130 ) ;
F_1 ( V_188 ) ;
for ( V_40 = 0 ; V_40 <= V_30 . V_130 ; V_40 ++ ) {
int V_164 ;
V_22 = & V_39 -> V_42 [ V_40 ] ;
if ( ! F_42 ( V_22 ) )
continue;
if ( F_26 ( V_22 , V_30 . V_13 ) )
continue;
if ( F_114 ( V_22 , V_30 . V_13 , 0 , V_40 ) !=
V_119 )
continue;
V_30 . V_63 = 0 ;
V_30 . V_64 = 0 ;
V_30 . V_94 = 0 ;
V_30 . V_65 = 0 ;
V_30 . V_22 = V_22 ;
F_136 ( & V_30 . V_103 ) ;
F_136 ( & V_30 . V_91 ) ;
if ( F_156 () )
return;
V_164 = F_123 ( V_22 , & V_30 ) ;
if ( V_164 == V_125 ) {
F_28 ( V_22 , V_30 . V_13 , false ) ;
} else if ( V_164 == V_118 || V_164 == V_117 ) {
F_24 ( V_22 , V_30 . V_13 ) ;
}
F_3 ( V_189 ,
V_30 . V_94 ) ;
F_3 ( V_190 ,
V_30 . V_65 ) ;
F_125 ( ! F_97 ( & V_30 . V_103 ) ) ;
F_125 ( ! F_97 ( & V_30 . V_91 ) ) ;
}
if ( V_39 -> V_184 <= V_30 . V_13 )
V_39 -> V_184 = 0 ;
if ( V_39 -> V_186 >= V_30 . V_130 )
V_39 -> V_186 = V_39 -> V_191 - 1 ;
}
void F_160 ( T_1 * V_39 , int V_13 , int V_130 )
{
if ( ! V_13 )
return;
if ( V_39 -> V_184 < V_13 )
V_39 -> V_184 = V_13 ;
if ( V_39 -> V_186 > V_130 )
V_39 -> V_186 = V_130 ;
if ( ! F_161 ( & V_39 -> V_192 ) )
return;
if ( ! F_157 ( V_39 ) )
return;
F_162 ( V_39 -> V_187 , V_13 ,
V_130 ) ;
F_163 ( & V_39 -> V_192 ) ;
}
static int F_164 ( void * V_193 )
{
T_1 * V_39 = ( T_1 * ) V_193 ;
struct V_194 * V_195 = V_51 ;
const struct V_196 * V_196 = F_165 ( V_39 -> V_187 ) ;
if ( ! F_166 ( V_196 ) )
F_167 ( V_195 , V_196 ) ;
F_168 () ;
V_39 -> V_184 = 0 ;
V_39 -> V_186 = V_39 -> V_191 - 1 ;
while ( ! F_156 () ) {
F_169 ( V_39 -> V_187 ) ;
F_170 ( V_39 -> V_192 ,
F_155 ( V_39 ) ) ;
F_158 ( V_39 ) ;
}
return 0 ;
}
int F_171 ( int V_166 )
{
T_1 * V_39 = F_142 ( V_166 ) ;
int V_128 = 0 ;
if ( V_39 -> F_164 )
return 0 ;
V_39 -> F_164 = F_172 ( F_164 , V_39 , L_1 , V_166 ) ;
if ( F_173 ( V_39 -> F_164 ) ) {
F_174 ( L_2 , V_166 ) ;
V_128 = F_175 ( V_39 -> F_164 ) ;
V_39 -> F_164 = NULL ;
}
return V_128 ;
}
void F_176 ( int V_166 )
{
struct V_194 * F_164 = F_142 ( V_166 ) -> F_164 ;
if ( F_164 ) {
F_177 ( F_164 ) ;
F_142 ( V_166 ) -> F_164 = NULL ;
}
}
static int F_178 ( unsigned int V_152 )
{
int V_166 ;
F_179 (nid, N_MEMORY) {
T_1 * V_39 = F_142 ( V_166 ) ;
const struct V_196 * V_197 ;
V_197 = F_165 ( V_39 -> V_187 ) ;
if ( F_180 ( V_198 , V_197 ) < V_199 )
F_167 ( V_39 -> F_164 , V_197 ) ;
}
return 0 ;
}
static int T_10 F_181 ( void )
{
int V_166 ;
int V_128 ;
V_128 = F_182 ( V_200 ,
L_3 ,
F_178 , NULL ) ;
if ( V_128 < 0 ) {
F_174 ( L_4 ) ;
return V_128 ;
}
F_179 (nid, N_MEMORY)
F_171 ( V_166 ) ;
return 0 ;
}
