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
static inline bool F_17 ( int V_17 )
{
return F_18 ( V_17 ) || V_17 == V_18 ;
}
int F_19 ( struct V_6 * V_6 )
{
struct V_19 * V_20 ;
F_20 ( ! F_21 ( V_6 ) , V_6 ) ;
if ( ! F_22 ( V_6 ) )
return 0 ;
V_20 = F_23 ( V_6 ) ;
if ( V_20 && V_20 -> V_21 && V_20 -> V_21 -> V_22 )
return 1 ;
return 0 ;
}
void F_24 ( struct V_6 * V_6 , struct V_19 * V_20 )
{
F_20 ( ! F_21 ( V_6 ) , V_6 ) ;
F_20 ( ( unsigned long ) V_20 & V_23 , V_6 ) ;
V_6 -> V_20 = ( void * ) ( ( unsigned long ) V_20 | V_23 ) ;
}
void F_25 ( struct V_6 * V_6 )
{
F_20 ( ! F_21 ( V_6 ) , V_6 ) ;
F_20 ( ! F_19 ( V_6 ) , V_6 ) ;
V_6 -> V_20 = ( void * ) ( ( unsigned long ) V_6 -> V_20 &
V_23 ) ;
}
void F_26 ( struct V_24 * V_24 , int V_13 )
{
V_24 -> V_25 = 0 ;
V_24 -> V_26 ++ ;
if ( V_13 < V_24 -> V_27 )
V_24 -> V_27 = V_13 ;
if ( V_24 -> V_26 > V_28 )
V_24 -> V_26 = V_28 ;
F_27 ( V_24 , V_13 ) ;
}
bool F_28 ( struct V_24 * V_24 , int V_13 )
{
unsigned long V_29 = 1UL << V_24 -> V_26 ;
if ( V_13 < V_24 -> V_27 )
return false ;
if ( ++ V_24 -> V_25 > V_29 )
V_24 -> V_25 = V_29 ;
if ( V_24 -> V_25 >= V_29 )
return false ;
F_29 ( V_24 , V_13 ) ;
return true ;
}
void F_30 ( struct V_24 * V_24 , int V_13 ,
bool V_30 )
{
if ( V_30 ) {
V_24 -> V_25 = 0 ;
V_24 -> V_26 = 0 ;
}
if ( V_13 >= V_24 -> V_27 )
V_24 -> V_27 = V_13 + 1 ;
F_31 ( V_24 , V_13 ) ;
}
bool F_32 ( struct V_24 * V_24 , int V_13 )
{
if ( V_13 < V_24 -> V_27 )
return false ;
return V_24 -> V_26 == V_28 &&
V_24 -> V_25 >= 1UL << V_24 -> V_26 ;
}
static inline bool F_33 ( struct V_31 * V_32 ,
struct V_6 * V_6 )
{
if ( V_32 -> V_33 )
return true ;
return ! F_34 ( V_6 ) ;
}
static void F_35 ( struct V_24 * V_24 )
{
V_24 -> V_34 [ 0 ] = V_24 -> V_35 ;
V_24 -> V_34 [ 1 ] = V_24 -> V_35 ;
V_24 -> V_36 =
F_36 ( F_37 ( V_24 ) - 1 ) ;
}
static void F_38 ( struct V_24 * V_24 )
{
unsigned long V_37 = V_24 -> V_35 ;
unsigned long V_38 = F_37 ( V_24 ) ;
unsigned long V_9 ;
V_24 -> V_39 = false ;
for ( V_9 = V_37 ; V_9 < V_38 ; V_9 += V_40 ) {
struct V_6 * V_6 ;
F_39 () ;
if ( ! F_40 ( V_9 ) )
continue;
V_6 = F_41 ( V_9 ) ;
if ( V_24 != F_42 ( V_6 ) )
continue;
F_43 ( V_6 ) ;
}
F_35 ( V_24 ) ;
}
void F_44 ( T_1 * V_41 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
struct V_24 * V_24 = & V_41 -> V_44 [ V_42 ] ;
if ( ! F_45 ( V_24 ) )
continue;
if ( V_24 -> V_39 )
F_38 ( V_24 ) ;
}
}
static void F_46 ( struct V_31 * V_32 ,
struct V_6 * V_6 , unsigned long V_45 ,
bool V_46 )
{
struct V_24 * V_24 = V_32 -> V_24 ;
unsigned long V_9 ;
if ( V_32 -> V_33 )
return;
if ( ! V_6 )
return;
if ( V_45 )
return;
F_47 ( V_6 ) ;
V_9 = F_7 ( V_6 ) ;
if ( V_46 ) {
if ( V_9 > V_24 -> V_34 [ 0 ] )
V_24 -> V_34 [ 0 ] = V_9 ;
if ( V_32 -> V_47 != V_48 &&
V_9 > V_24 -> V_34 [ 1 ] )
V_24 -> V_34 [ 1 ] = V_9 ;
} else {
if ( V_9 < V_24 -> V_36 )
V_24 -> V_36 = V_9 ;
}
}
static inline bool F_33 ( struct V_31 * V_32 ,
struct V_6 * V_6 )
{
return true ;
}
static void F_46 ( struct V_31 * V_32 ,
struct V_6 * V_6 , unsigned long V_45 ,
bool V_46 )
{
}
static bool F_48 ( T_2 * V_49 , unsigned long * V_50 ,
struct V_31 * V_32 )
{
if ( V_32 -> V_47 == V_48 ) {
if ( ! F_49 ( V_49 , * V_50 ) ) {
V_32 -> V_51 = true ;
return false ;
}
} else {
F_50 ( V_49 , * V_50 ) ;
}
return true ;
}
static bool F_51 ( T_2 * V_49 ,
unsigned long V_50 , bool * V_52 , struct V_31 * V_32 )
{
if ( * V_52 ) {
F_52 ( V_49 , V_50 ) ;
* V_52 = false ;
}
if ( F_53 ( V_53 ) ) {
V_32 -> V_51 = true ;
return true ;
}
if ( F_54 () ) {
if ( V_32 -> V_47 == V_48 ) {
V_32 -> V_51 = true ;
return true ;
}
F_39 () ;
}
return false ;
}
static inline bool F_55 ( struct V_31 * V_32 )
{
if ( F_54 () ) {
if ( V_32 -> V_47 == V_48 ) {
V_32 -> V_51 = true ;
return true ;
}
F_39 () ;
}
return false ;
}
static unsigned long F_56 ( struct V_31 * V_32 ,
unsigned long * V_37 ,
unsigned long V_38 ,
struct V_4 * V_5 ,
bool V_54 )
{
int V_55 = 0 , V_56 = 0 ;
struct V_6 * V_57 , * V_58 = NULL ;
unsigned long V_50 = 0 ;
bool V_52 = false ;
unsigned long V_59 = * V_37 ;
unsigned int V_13 ;
V_57 = F_41 ( V_59 ) ;
for (; V_59 < V_38 ; V_59 ++ , V_57 ++ ) {
int V_60 ;
struct V_6 * V_6 = V_57 ;
if ( ! ( V_59 % V_61 )
&& F_51 ( & V_32 -> V_24 -> V_49 , V_50 ,
& V_52 , V_32 ) )
break;
V_55 ++ ;
if ( ! F_57 ( V_59 ) )
goto V_62;
if ( ! V_58 )
V_58 = V_6 ;
if ( F_58 ( V_6 ) ) {
unsigned int V_63 = F_59 ( V_6 ) ;
if ( F_60 ( V_63 < V_64 ) ) {
V_59 += ( 1UL << V_63 ) - 1 ;
V_57 += ( 1UL << V_63 ) - 1 ;
}
goto V_62;
}
if ( ! F_61 ( V_6 ) )
goto V_62;
if ( ! V_52 ) {
V_52 = F_48 ( & V_32 -> V_24 -> V_49 ,
& V_50 , V_32 ) ;
if ( ! V_52 )
break;
if ( ! F_61 ( V_6 ) )
goto V_62;
}
V_13 = F_62 ( V_6 ) ;
V_60 = F_63 ( V_6 , V_13 ) ;
if ( ! V_60 )
break;
F_64 ( V_6 , V_13 ) ;
V_56 += V_60 ;
V_32 -> V_65 += V_60 ;
F_65 ( & V_6 -> V_10 , V_5 ) ;
if ( ! V_54 && V_32 -> V_66 <= V_32 -> V_65 ) {
V_59 += V_60 ;
break;
}
V_59 += V_60 - 1 ;
V_57 += V_60 - 1 ;
continue;
V_62:
if ( V_54 )
break;
else
continue;
}
if ( V_52 )
F_52 ( & V_32 -> V_24 -> V_49 , V_50 ) ;
if ( F_66 ( V_59 > V_38 ) )
V_59 = V_38 ;
F_67 ( * V_37 , V_59 ,
V_55 , V_56 ) ;
* V_37 = V_59 ;
if ( V_54 && V_59 < V_38 )
V_56 = 0 ;
if ( V_59 == V_38 )
F_46 ( V_32 , V_58 , V_56 , false ) ;
V_32 -> V_67 += V_55 ;
if ( V_56 )
F_3 ( V_68 , V_56 ) ;
return V_56 ;
}
unsigned long
F_68 ( struct V_31 * V_32 ,
unsigned long V_37 , unsigned long V_38 )
{
unsigned long V_60 , V_9 , V_69 , V_70 ;
F_11 ( V_5 ) ;
V_9 = V_37 ;
V_69 = F_36 ( V_9 ) ;
if ( V_69 < V_32 -> V_24 -> V_35 )
V_69 = V_32 -> V_24 -> V_35 ;
V_70 = F_69 ( V_9 ) ;
for (; V_9 < V_38 ; V_9 += V_60 ,
V_69 = V_70 ,
V_70 += V_40 ) {
unsigned long V_71 = V_9 ;
V_70 = F_70 ( V_70 , V_38 ) ;
if ( V_9 >= V_70 ) {
V_69 = F_36 ( V_9 ) ;
V_70 = F_69 ( V_9 ) ;
V_70 = F_70 ( V_70 , V_38 ) ;
}
if ( ! F_71 ( V_69 ,
V_70 , V_32 -> V_24 ) )
break;
V_60 = F_56 ( V_32 , & V_71 ,
V_70 , & V_5 , true ) ;
if ( ! V_60 )
break;
}
F_10 ( & V_5 ) ;
if ( V_9 < V_38 ) {
F_5 ( & V_5 ) ;
return 0 ;
}
return V_9 ;
}
static bool F_72 ( struct V_24 * V_24 )
{
unsigned long V_72 , V_73 , V_60 ;
V_73 = F_73 ( V_24 -> V_74 , V_75 ) +
F_73 ( V_24 -> V_74 , V_76 ) ;
V_72 = F_73 ( V_24 -> V_74 , V_77 ) +
F_73 ( V_24 -> V_74 , V_78 ) ;
V_60 = F_73 ( V_24 -> V_74 , V_79 ) +
F_73 ( V_24 -> V_74 , V_80 ) ;
return V_60 > ( V_73 + V_72 ) / 2 ;
}
static unsigned long
F_74 ( struct V_31 * V_32 , unsigned long V_81 ,
unsigned long V_38 , T_3 V_82 )
{
struct V_24 * V_24 = V_32 -> V_24 ;
unsigned long V_55 = 0 , V_45 = 0 ;
struct V_83 * V_83 ;
unsigned long V_50 = 0 ;
bool V_52 = false ;
struct V_6 * V_6 = NULL , * V_58 = NULL ;
unsigned long V_37 = V_81 ;
bool V_84 = false ;
unsigned long V_85 = 0 ;
while ( F_66 ( F_72 ( V_24 ) ) ) {
if ( V_32 -> V_47 == V_48 )
return 0 ;
F_75 ( V_86 , V_87 / 10 ) ;
if ( F_53 ( V_53 ) )
return 0 ;
}
if ( F_55 ( V_32 ) )
return 0 ;
if ( V_32 -> V_88 && ( V_32 -> V_47 == V_48 ) ) {
V_84 = true ;
V_85 = V_70 ( V_81 , V_32 -> V_13 ) ;
}
for (; V_81 < V_38 ; V_81 ++ ) {
if ( V_84 && V_81 >= V_85 ) {
if ( V_45 )
break;
V_85 = V_70 ( V_81 , V_32 -> V_13 ) ;
}
if ( ! ( V_81 % V_61 )
&& F_51 ( F_76 ( V_24 ) , V_50 ,
& V_52 , V_32 ) )
break;
if ( ! F_57 ( V_81 ) )
goto V_62;
V_55 ++ ;
V_6 = F_41 ( V_81 ) ;
if ( ! V_58 )
V_58 = V_6 ;
if ( F_61 ( V_6 ) ) {
unsigned long V_89 = F_77 ( V_6 ) ;
if ( V_89 > 0 && V_89 < V_64 )
V_81 += ( 1UL << V_89 ) - 1 ;
continue;
}
if ( F_58 ( V_6 ) ) {
unsigned int V_63 = F_59 ( V_6 ) ;
if ( F_60 ( V_63 < V_64 ) )
V_81 += ( 1UL << V_63 ) - 1 ;
goto V_62;
}
if ( ! F_78 ( V_6 ) ) {
if ( F_66 ( F_22 ( V_6 ) ) &&
! F_79 ( V_6 ) ) {
if ( V_52 ) {
F_52 ( F_76 ( V_24 ) ,
V_50 ) ;
V_52 = false ;
}
if ( ! F_80 ( V_6 , V_82 ) )
goto V_90;
}
goto V_62;
}
if ( ! F_23 ( V_6 ) &&
F_81 ( V_6 ) > F_82 ( V_6 ) )
goto V_62;
if ( ! ( V_32 -> V_91 & V_92 ) && F_23 ( V_6 ) )
goto V_62;
if ( ! V_52 ) {
V_52 = F_48 ( F_76 ( V_24 ) ,
& V_50 , V_32 ) ;
if ( ! V_52 )
break;
if ( ! F_78 ( V_6 ) )
goto V_62;
if ( F_66 ( F_58 ( V_6 ) ) ) {
V_81 += ( 1UL << F_59 ( V_6 ) ) - 1 ;
goto V_62;
}
}
V_83 = F_83 ( V_6 , V_24 -> V_74 ) ;
if ( F_84 ( V_6 , V_82 ) != 0 )
goto V_62;
F_20 ( F_58 ( V_6 ) , V_6 ) ;
F_85 ( V_6 , V_83 , F_86 ( V_6 ) ) ;
F_87 ( V_6 ,
V_80 + F_88 ( V_6 ) ) ;
V_90:
F_15 ( & V_6 -> V_10 , & V_32 -> V_93 ) ;
V_32 -> V_66 ++ ;
V_45 ++ ;
if ( ! V_32 -> V_94 )
V_32 -> V_94 = V_81 ;
if ( V_32 -> V_66 == V_95 ) {
++ V_81 ;
break;
}
continue;
V_62:
if ( ! V_84 )
continue;
if ( V_45 ) {
if ( V_52 ) {
F_52 ( F_76 ( V_24 ) , V_50 ) ;
V_52 = false ;
}
F_89 ( & V_32 -> V_93 ) ;
V_32 -> V_66 = 0 ;
V_32 -> V_94 = 0 ;
V_45 = 0 ;
}
if ( V_81 < V_85 ) {
V_81 = V_85 - 1 ;
V_85 += 1UL << V_32 -> V_13 ;
}
}
if ( F_66 ( V_81 > V_38 ) )
V_81 = V_38 ;
if ( V_52 )
F_52 ( F_76 ( V_24 ) , V_50 ) ;
if ( V_81 == V_38 )
F_46 ( V_32 , V_58 , V_45 , true ) ;
F_90 ( V_37 , V_81 ,
V_55 , V_45 ) ;
V_32 -> V_96 += V_55 ;
if ( V_45 )
F_3 ( V_68 , V_45 ) ;
return V_81 ;
}
unsigned long
F_91 ( struct V_31 * V_32 , unsigned long V_37 ,
unsigned long V_38 )
{
unsigned long V_9 , V_69 , V_70 ;
V_9 = V_37 ;
V_69 = F_36 ( V_9 ) ;
if ( V_69 < V_32 -> V_24 -> V_35 )
V_69 = V_32 -> V_24 -> V_35 ;
V_70 = F_69 ( V_9 ) ;
for (; V_9 < V_38 ; V_9 = V_70 ,
V_69 = V_70 ,
V_70 += V_40 ) {
V_70 = F_70 ( V_70 , V_38 ) ;
if ( ! F_71 ( V_69 ,
V_70 , V_32 -> V_24 ) )
continue;
V_9 = F_74 ( V_32 , V_9 , V_70 ,
V_97 ) ;
if ( ! V_9 )
break;
if ( V_32 -> V_66 == V_95 )
break;
}
return V_9 ;
}
static bool F_92 ( struct V_31 * V_32 ,
struct V_6 * V_6 )
{
if ( V_32 -> V_98 )
return true ;
if ( F_61 ( V_6 ) ) {
if ( F_77 ( V_6 ) >= V_99 )
return false ;
}
if ( F_17 ( F_93 ( V_6 ) ) )
return true ;
return false ;
}
static inline bool F_94 ( struct V_31 * V_32 )
{
return ( V_32 -> V_100 >> V_99 )
<= ( V_32 -> V_101 >> V_99 ) ;
}
static void F_95 ( struct V_31 * V_32 )
{
struct V_24 * V_24 = V_32 -> V_24 ;
struct V_6 * V_6 ;
unsigned long V_69 ;
unsigned long V_71 ;
unsigned long V_70 ;
unsigned long V_81 ;
struct V_4 * V_5 = & V_32 -> V_102 ;
V_71 = V_32 -> V_100 ;
V_69 = F_36 ( V_32 -> V_100 ) ;
V_70 = F_70 ( V_69 + V_40 ,
F_37 ( V_24 ) ) ;
V_81 = F_69 ( V_32 -> V_101 ) ;
for (; V_69 >= V_81 ;
V_70 = V_69 ,
V_69 -= V_40 ,
V_71 = V_69 ) {
if ( ! ( V_69 % ( V_61 * V_40 ) )
&& F_55 ( V_32 ) )
break;
V_6 = F_71 ( V_69 , V_70 ,
V_24 ) ;
if ( ! V_6 )
continue;
if ( ! F_92 ( V_32 , V_6 ) )
continue;
if ( ! F_33 ( V_32 , V_6 ) )
continue;
F_56 ( V_32 , & V_71 , V_70 ,
V_5 , false ) ;
if ( ( V_32 -> V_65 >= V_32 -> V_66 )
|| V_32 -> V_51 ) {
if ( V_71 >= V_70 ) {
V_71 =
V_69 - V_40 ;
}
break;
} else if ( V_71 < V_70 ) {
break;
}
}
F_10 ( V_5 ) ;
V_32 -> V_100 = V_71 ;
}
static struct V_6 * F_96 ( struct V_6 * V_103 ,
unsigned long V_104 ,
int * * V_105 )
{
struct V_31 * V_32 = (struct V_31 * ) V_104 ;
struct V_6 * V_106 ;
if ( F_97 ( & V_32 -> V_102 ) ) {
if ( ! V_32 -> V_51 )
F_95 ( V_32 ) ;
if ( F_97 ( & V_32 -> V_102 ) )
return NULL ;
}
V_106 = F_98 ( V_32 -> V_102 . V_7 , struct V_6 , V_10 ) ;
F_8 ( & V_106 -> V_10 ) ;
V_32 -> V_65 -- ;
return V_106 ;
}
static void F_99 ( struct V_6 * V_6 , unsigned long V_104 )
{
struct V_31 * V_32 = (struct V_31 * ) V_104 ;
F_15 ( & V_6 -> V_10 , & V_32 -> V_102 ) ;
V_32 -> V_65 ++ ;
}
static T_4 F_100 ( struct V_24 * V_24 ,
struct V_31 * V_32 )
{
unsigned long V_69 ;
unsigned long V_70 ;
unsigned long V_81 ;
struct V_6 * V_6 ;
const T_3 V_82 =
( V_107 ? V_97 : 0 ) |
( V_32 -> V_47 != V_108 ? V_109 : 0 ) ;
V_81 = V_32 -> V_101 ;
V_69 = F_36 ( V_81 ) ;
if ( V_69 < V_24 -> V_35 )
V_69 = V_24 -> V_35 ;
V_70 = F_69 ( V_81 ) ;
for (; V_70 <= V_32 -> V_100 ;
V_81 = V_70 ,
V_69 = V_70 ,
V_70 += V_40 ) {
if ( ! ( V_81 % ( V_61 * V_40 ) )
&& F_55 ( V_32 ) )
break;
V_6 = F_71 ( V_69 , V_70 ,
V_24 ) ;
if ( ! V_6 )
continue;
if ( ! F_33 ( V_32 , V_6 ) )
continue;
if ( V_32 -> V_47 == V_48 &&
! F_17 ( F_93 ( V_6 ) ) )
continue;
V_81 = F_74 ( V_32 , V_81 ,
V_70 , V_82 ) ;
if ( ! V_81 || V_32 -> V_51 )
return V_110 ;
break;
}
V_32 -> V_101 = V_81 ;
return V_32 -> V_66 ? V_111 : V_112 ;
}
static inline bool F_101 ( int V_13 )
{
return V_13 == - 1 ;
}
static enum V_113 F_102 ( struct V_24 * V_24 , struct V_31 * V_32 ,
const int V_17 )
{
unsigned int V_13 ;
unsigned long V_114 ;
if ( V_32 -> V_51 || F_53 ( V_53 ) )
return V_115 ;
if ( F_94 ( V_32 ) ) {
F_35 ( V_24 ) ;
if ( V_32 -> V_88 )
V_24 -> V_39 = true ;
if ( V_32 -> V_116 )
return V_117 ;
else
return V_118 ;
}
if ( F_101 ( V_32 -> V_13 ) )
return V_119 ;
V_114 = V_24 -> V_114 [ V_32 -> V_120 & V_121 ] ;
if ( ! F_103 ( V_24 , V_32 -> V_13 , V_114 , V_32 -> V_122 ,
V_32 -> V_120 ) )
return V_119 ;
for ( V_13 = V_32 -> V_13 ; V_13 < V_64 ; V_13 ++ ) {
struct V_123 * V_124 = & V_24 -> V_123 [ V_13 ] ;
bool V_125 ;
if ( ! F_97 ( & V_124 -> V_126 [ V_17 ] ) )
return V_127 ;
#ifdef F_104
if ( V_17 == V_18 &&
! F_97 ( & V_124 -> V_126 [ V_128 ] ) )
return V_127 ;
#endif
if ( F_105 ( V_124 , V_13 , V_17 ,
true , & V_125 ) != - 1 )
return V_127 ;
}
return V_129 ;
}
static enum V_113 F_106 ( struct V_24 * V_24 ,
struct V_31 * V_32 ,
const int V_17 )
{
int V_130 ;
V_130 = F_102 ( V_24 , V_32 , V_17 ) ;
F_107 ( V_24 , V_32 -> V_13 , V_130 ) ;
if ( V_130 == V_129 )
V_130 = V_119 ;
return V_130 ;
}
static enum V_113 F_108 ( struct V_24 * V_24 , int V_13 ,
unsigned int V_120 ,
int V_122 ,
unsigned long V_131 )
{
unsigned long V_114 ;
if ( F_101 ( V_13 ) )
return V_119 ;
V_114 = V_24 -> V_114 [ V_120 & V_121 ] ;
if ( F_103 ( V_24 , V_13 , V_114 , V_122 ,
V_120 ) )
return V_127 ;
V_114 = ( V_13 > V_132 ) ?
F_109 ( V_24 ) : F_110 ( V_24 ) ;
V_114 += F_111 ( V_13 ) ;
if ( ! F_112 ( V_24 , 0 , V_114 , V_122 ,
V_133 , V_131 ) )
return V_134 ;
return V_119 ;
}
enum V_113 F_113 ( struct V_24 * V_24 , int V_13 ,
unsigned int V_120 ,
int V_122 )
{
enum V_113 V_130 ;
int V_135 ;
V_130 = F_108 ( V_24 , V_13 , V_120 , V_122 ,
F_114 ( V_24 , V_136 ) ) ;
if ( V_130 == V_119 && ( V_13 > V_132 ) ) {
V_135 = F_115 ( V_24 , V_13 ) ;
if ( V_135 >= 0 && V_135 <= V_137 )
V_130 = V_138 ;
}
F_116 ( V_24 , V_13 , V_130 ) ;
if ( V_130 == V_138 )
V_130 = V_134 ;
return V_130 ;
}
bool F_117 ( struct V_139 * V_140 , int V_13 ,
int V_120 )
{
struct V_24 * V_24 ;
struct V_141 * V_142 ;
F_118 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long V_143 ;
enum V_113 V_113 ;
V_143 = F_119 ( V_24 ) / V_13 ;
V_143 += F_120 ( V_24 , V_136 ) ;
V_113 = F_108 ( V_24 , V_13 , V_120 ,
F_121 ( V_140 ) , V_143 ) ;
if ( V_113 != V_134 )
return true ;
}
return false ;
}
static enum V_113 F_122 ( struct V_24 * V_24 , struct V_31 * V_32 )
{
enum V_113 V_130 ;
unsigned long V_37 = V_24 -> V_35 ;
unsigned long V_38 = F_37 ( V_24 ) ;
const int V_17 = F_123 ( V_32 -> V_91 ) ;
const bool V_144 = V_32 -> V_47 != V_48 ;
V_130 = F_113 ( V_24 , V_32 -> V_13 , V_32 -> V_120 ,
V_32 -> V_122 ) ;
if ( V_130 == V_127 || V_130 == V_134 )
return V_130 ;
F_124 ( V_130 != V_119 ) ;
if ( F_32 ( V_24 , V_32 -> V_13 ) )
F_38 ( V_24 ) ;
if ( V_32 -> V_116 ) {
V_32 -> V_101 = V_37 ;
V_32 -> V_100 = F_36 ( V_38 - 1 ) ;
} else {
V_32 -> V_101 = V_24 -> V_34 [ V_144 ] ;
V_32 -> V_100 = V_24 -> V_36 ;
if ( V_32 -> V_100 < V_37 || V_32 -> V_100 >= V_38 ) {
V_32 -> V_100 = F_36 ( V_38 - 1 ) ;
V_24 -> V_36 = V_32 -> V_100 ;
}
if ( V_32 -> V_101 < V_37 || V_32 -> V_101 >= V_38 ) {
V_32 -> V_101 = V_37 ;
V_24 -> V_34 [ 0 ] = V_32 -> V_101 ;
V_24 -> V_34 [ 1 ] = V_32 -> V_101 ;
}
if ( V_32 -> V_101 == V_37 )
V_32 -> V_116 = true ;
}
V_32 -> V_94 = 0 ;
F_125 ( V_37 , V_32 -> V_101 ,
V_32 -> V_100 , V_38 , V_144 ) ;
F_126 () ;
while ( ( V_130 = F_106 ( V_24 , V_32 , V_17 ) ) ==
V_119 ) {
int V_145 ;
switch ( F_100 ( V_24 , V_32 ) ) {
case V_110 :
V_130 = V_115 ;
F_89 ( & V_32 -> V_93 ) ;
V_32 -> V_66 = 0 ;
goto V_146;
case V_112 :
goto V_147;
case V_111 :
;
}
V_145 = F_127 ( & V_32 -> V_93 , F_96 ,
F_99 , ( unsigned long ) V_32 , V_32 -> V_47 ,
V_148 ) ;
F_128 ( V_32 -> V_66 , V_145 ,
& V_32 -> V_93 ) ;
V_32 -> V_66 = 0 ;
if ( V_145 ) {
F_89 ( & V_32 -> V_93 ) ;
if ( V_145 == - V_149 && ! F_94 ( V_32 ) ) {
V_130 = V_115 ;
goto V_146;
}
if ( V_32 -> V_88 &&
( V_32 -> V_47 == V_48 ) ) {
V_32 -> V_101 = V_70 (
V_32 -> V_101 - 1 , V_32 -> V_13 ) ;
V_32 -> V_94 = 0 ;
}
}
V_147:
if ( V_32 -> V_13 > 0 && V_32 -> V_94 ) {
int V_150 ;
unsigned long V_151 =
V_69 ( V_32 -> V_101 , V_32 -> V_13 ) ;
if ( V_32 -> V_94 < V_151 ) {
V_150 = F_129 () ;
F_130 ( V_150 ) ;
F_131 ( V_24 ) ;
F_132 () ;
V_32 -> V_94 = 0 ;
}
}
}
V_146:
if ( V_32 -> V_65 > 0 ) {
unsigned long V_100 = F_5 ( & V_32 -> V_102 ) ;
V_32 -> V_65 = 0 ;
F_124 ( V_100 == 0 ) ;
V_100 = F_36 ( V_100 ) ;
if ( V_100 > V_24 -> V_36 )
V_24 -> V_36 = V_100 ;
}
F_3 ( V_152 , V_32 -> V_96 ) ;
F_3 ( V_153 , V_32 -> V_67 ) ;
F_133 ( V_37 , V_32 -> V_101 ,
V_32 -> V_100 , V_38 , V_144 , V_130 ) ;
return V_130 ;
}
static enum V_113 F_134 ( struct V_24 * V_24 , int V_13 ,
T_5 V_91 , enum V_154 V_155 ,
unsigned int V_120 , int V_122 )
{
enum V_113 V_130 ;
struct V_31 V_32 = {
. V_65 = 0 ,
. V_66 = 0 ,
. V_96 = 0 ,
. V_67 = 0 ,
. V_13 = V_13 ,
. V_91 = V_91 ,
. V_24 = V_24 ,
. V_47 = ( V_155 == V_156 ) ?
V_48 : V_157 ,
. V_120 = V_120 ,
. V_122 = V_122 ,
. V_88 = true ,
. V_116 = ( V_155 == V_158 ) ,
. V_33 = ( V_155 == V_158 ) ,
. V_98 = ( V_155 == V_158 )
} ;
F_135 ( & V_32 . V_102 ) ;
F_135 ( & V_32 . V_93 ) ;
V_130 = F_122 ( V_24 , & V_32 ) ;
F_124 ( ! F_97 ( & V_32 . V_102 ) ) ;
F_124 ( ! F_97 ( & V_32 . V_93 ) ) ;
return V_130 ;
}
enum V_113 F_136 ( T_5 V_91 , unsigned int V_13 ,
unsigned int V_120 , const struct V_139 * V_140 ,
enum V_154 V_155 )
{
int V_159 = V_91 & V_160 ;
struct V_141 * V_142 ;
struct V_24 * V_24 ;
enum V_113 V_161 = V_134 ;
if ( ! V_159 )
return V_134 ;
F_137 ( V_13 , V_91 , V_155 ) ;
F_118 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
enum V_113 V_162 ;
if ( V_155 > V_158
&& F_28 ( V_24 , V_13 ) ) {
V_161 = F_138 ( enum V_113 , V_163 , V_161 ) ;
continue;
}
V_162 = F_134 ( V_24 , V_13 , V_91 , V_155 ,
V_120 , F_121 ( V_140 ) ) ;
V_161 = F_139 ( V_162 , V_161 ) ;
if ( V_162 == V_127 ) {
F_30 ( V_24 , V_13 , false ) ;
break;
}
if ( V_155 != V_156 && ( V_162 == V_117 ||
V_162 == V_118 ) )
F_26 ( V_24 , V_13 ) ;
if ( ( V_155 == V_156 && F_54 () )
|| F_53 ( V_53 ) )
break;
}
return V_161 ;
}
static void F_140 ( int V_164 )
{
T_1 * V_41 = F_141 ( V_164 ) ;
int V_42 ;
struct V_24 * V_24 ;
struct V_31 V_32 = {
. V_13 = - 1 ,
. V_96 = 0 ,
. V_67 = 0 ,
. V_47 = V_108 ,
. V_33 = true ,
. V_116 = true ,
. V_91 = V_165 ,
} ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_24 = & V_41 -> V_44 [ V_42 ] ;
if ( ! F_45 ( V_24 ) )
continue;
V_32 . V_65 = 0 ;
V_32 . V_66 = 0 ;
V_32 . V_24 = V_24 ;
F_135 ( & V_32 . V_102 ) ;
F_135 ( & V_32 . V_93 ) ;
F_122 ( V_24 , & V_32 ) ;
F_124 ( ! F_97 ( & V_32 . V_102 ) ) ;
F_124 ( ! F_97 ( & V_32 . V_93 ) ) ;
}
}
static void F_142 ( void )
{
int V_164 ;
F_143 () ;
F_144 (nid)
F_140 ( V_164 ) ;
}
int F_145 ( struct V_166 * V_167 , int V_168 ,
void T_6 * V_169 , T_7 * V_170 , T_8 * V_171 )
{
if ( V_168 )
F_142 () ;
return 0 ;
}
int F_146 ( struct V_166 * V_167 , int V_168 ,
void T_6 * V_169 , T_7 * V_170 , T_8 * V_171 )
{
F_147 ( V_167 , V_168 , V_169 , V_170 , V_171 ) ;
return 0 ;
}
static T_9 F_148 ( struct V_172 * V_173 ,
struct V_174 * V_175 ,
const char * V_176 , T_7 V_177 )
{
int V_164 = V_173 -> V_178 ;
if ( V_164 >= 0 && V_164 < V_179 && F_149 ( V_164 ) ) {
F_143 () ;
F_140 ( V_164 ) ;
}
return V_177 ;
}
int F_150 ( struct V_180 * V_180 )
{
return F_151 ( & V_180 -> V_173 , & V_181 ) ;
}
void F_152 ( struct V_180 * V_180 )
{
return F_153 ( & V_180 -> V_173 , & V_181 ) ;
}
static inline bool F_154 ( T_1 * V_41 )
{
return V_41 -> V_182 > 0 || F_155 () ;
}
static bool F_156 ( T_1 * V_41 )
{
int V_42 ;
struct V_24 * V_24 ;
enum V_183 V_122 = V_41 -> V_184 ;
for ( V_42 = 0 ; V_42 <= V_122 ; V_42 ++ ) {
V_24 = & V_41 -> V_44 [ V_42 ] ;
if ( ! F_45 ( V_24 ) )
continue;
if ( F_113 ( V_24 , V_41 -> V_182 , 0 ,
V_122 ) == V_119 )
return true ;
}
return false ;
}
static void F_157 ( T_1 * V_41 )
{
int V_42 ;
struct V_24 * V_24 ;
struct V_31 V_32 = {
. V_13 = V_41 -> V_182 ,
. V_96 = 0 ,
. V_67 = 0 ,
. V_122 = V_41 -> V_184 ,
. V_47 = V_157 ,
. V_33 = true ,
. V_91 = V_165 ,
} ;
F_158 ( V_41 -> V_185 , V_32 . V_13 ,
V_32 . V_122 ) ;
F_1 ( V_186 ) ;
for ( V_42 = 0 ; V_42 <= V_32 . V_122 ; V_42 ++ ) {
int V_162 ;
V_24 = & V_41 -> V_44 [ V_42 ] ;
if ( ! F_45 ( V_24 ) )
continue;
if ( F_28 ( V_24 , V_32 . V_13 ) )
continue;
if ( F_113 ( V_24 , V_32 . V_13 , 0 , V_42 ) !=
V_119 )
continue;
V_32 . V_65 = 0 ;
V_32 . V_66 = 0 ;
V_32 . V_96 = 0 ;
V_32 . V_67 = 0 ;
V_32 . V_24 = V_24 ;
F_135 ( & V_32 . V_102 ) ;
F_135 ( & V_32 . V_93 ) ;
if ( F_155 () )
return;
V_162 = F_122 ( V_24 , & V_32 ) ;
if ( V_162 == V_127 ) {
F_30 ( V_24 , V_32 . V_13 , false ) ;
} else if ( V_162 == V_118 || V_162 == V_117 ) {
F_26 ( V_24 , V_32 . V_13 ) ;
}
F_3 ( V_187 ,
V_32 . V_96 ) ;
F_3 ( V_188 ,
V_32 . V_67 ) ;
F_124 ( ! F_97 ( & V_32 . V_102 ) ) ;
F_124 ( ! F_97 ( & V_32 . V_93 ) ) ;
}
if ( V_41 -> V_182 <= V_32 . V_13 )
V_41 -> V_182 = 0 ;
if ( V_41 -> V_184 >= V_32 . V_122 )
V_41 -> V_184 = V_41 -> V_189 - 1 ;
}
void F_159 ( T_1 * V_41 , int V_13 , int V_122 )
{
if ( ! V_13 )
return;
if ( V_41 -> V_182 < V_13 )
V_41 -> V_182 = V_13 ;
F_160 () ;
if ( V_41 -> V_184 > V_122 )
V_41 -> V_184 = V_122 ;
if ( ! F_161 ( & V_41 -> V_190 ) )
return;
if ( ! F_156 ( V_41 ) )
return;
F_162 ( V_41 -> V_185 , V_13 ,
V_122 ) ;
F_163 ( & V_41 -> V_190 ) ;
}
static int F_164 ( void * V_191 )
{
T_1 * V_41 = ( T_1 * ) V_191 ;
struct V_192 * V_193 = V_53 ;
const struct V_194 * V_194 = F_165 ( V_41 -> V_185 ) ;
if ( ! F_166 ( V_194 ) )
F_167 ( V_193 , V_194 ) ;
F_168 () ;
V_41 -> V_182 = 0 ;
V_41 -> V_184 = V_41 -> V_189 - 1 ;
while ( ! F_155 () ) {
F_169 ( V_41 -> V_185 ) ;
F_170 ( V_41 -> V_190 ,
F_154 ( V_41 ) ) ;
F_157 ( V_41 ) ;
}
return 0 ;
}
int F_171 ( int V_164 )
{
T_1 * V_41 = F_141 ( V_164 ) ;
int V_130 = 0 ;
if ( V_41 -> F_164 )
return 0 ;
V_41 -> F_164 = F_172 ( F_164 , V_41 , L_1 , V_164 ) ;
if ( F_173 ( V_41 -> F_164 ) ) {
F_174 ( L_2 , V_164 ) ;
V_130 = F_175 ( V_41 -> F_164 ) ;
V_41 -> F_164 = NULL ;
}
return V_130 ;
}
void F_176 ( int V_164 )
{
struct V_192 * F_164 = F_141 ( V_164 ) -> F_164 ;
if ( F_164 ) {
F_177 ( F_164 ) ;
F_141 ( V_164 ) -> F_164 = NULL ;
}
}
static int F_178 ( unsigned int V_150 )
{
int V_164 ;
F_179 (nid, N_MEMORY) {
T_1 * V_41 = F_141 ( V_164 ) ;
const struct V_194 * V_195 ;
V_195 = F_165 ( V_41 -> V_185 ) ;
if ( F_180 ( V_196 , V_195 ) < V_197 )
F_167 ( V_41 -> F_164 , V_195 ) ;
}
return 0 ;
}
static int T_10 F_181 ( void )
{
int V_164 ;
int V_130 ;
V_130 = F_182 ( V_198 ,
L_3 ,
F_178 , NULL ) ;
if ( V_130 < 0 ) {
F_174 ( L_4 ) ;
return V_130 ;
}
F_179 (nid, N_MEMORY)
F_171 ( V_164 ) ;
return 0 ;
}
