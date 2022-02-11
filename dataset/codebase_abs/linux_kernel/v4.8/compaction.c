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
F_3 ( V_67 , V_55 ) ;
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
static void F_72 ( struct V_24 * V_24 , struct V_31 * V_32 )
{
struct V_6 * V_6 ;
unsigned int V_72 [ 2 ] = { 0 , } ;
if ( F_73 ( & V_32 -> V_73 ) )
return;
F_74 (page, &cc->migratepages, lru)
V_72 [ ! ! F_75 ( V_6 ) ] ++ ;
F_76 ( V_24 -> V_74 , V_75 , V_72 [ 0 ] ) ;
F_76 ( V_24 -> V_74 , V_76 , V_72 [ 1 ] ) ;
}
static bool F_77 ( struct V_24 * V_24 )
{
unsigned long V_77 , V_78 , V_60 ;
V_78 = F_78 ( V_24 -> V_74 , V_79 ) +
F_78 ( V_24 -> V_74 , V_80 ) ;
V_77 = F_78 ( V_24 -> V_74 , V_81 ) +
F_78 ( V_24 -> V_74 , V_82 ) ;
V_60 = F_78 ( V_24 -> V_74 , V_76 ) +
F_78 ( V_24 -> V_74 , V_75 ) ;
return V_60 > ( V_78 + V_77 ) / 2 ;
}
static unsigned long
F_79 ( struct V_31 * V_32 , unsigned long V_83 ,
unsigned long V_38 , T_3 V_84 )
{
struct V_24 * V_24 = V_32 -> V_24 ;
unsigned long V_55 = 0 , V_45 = 0 ;
struct V_85 * V_85 ;
unsigned long V_50 = 0 ;
bool V_52 = false ;
struct V_6 * V_6 = NULL , * V_58 = NULL ;
unsigned long V_37 = V_83 ;
bool V_86 = false ;
unsigned long V_87 = 0 ;
while ( F_66 ( F_77 ( V_24 ) ) ) {
if ( V_32 -> V_47 == V_48 )
return 0 ;
F_80 ( V_88 , V_89 / 10 ) ;
if ( F_53 ( V_53 ) )
return 0 ;
}
if ( F_55 ( V_32 ) )
return 0 ;
if ( V_32 -> V_90 && ( V_32 -> V_47 == V_48 ) ) {
V_86 = true ;
V_87 = V_70 ( V_83 , V_32 -> V_13 ) ;
}
for (; V_83 < V_38 ; V_83 ++ ) {
if ( V_86 && V_83 >= V_87 ) {
if ( V_45 )
break;
V_87 = V_70 ( V_83 , V_32 -> V_13 ) ;
}
if ( ! ( V_83 % V_61 )
&& F_51 ( F_81 ( V_24 ) , V_50 ,
& V_52 , V_32 ) )
break;
if ( ! F_57 ( V_83 ) )
goto V_62;
V_55 ++ ;
V_6 = F_41 ( V_83 ) ;
if ( ! V_58 )
V_58 = V_6 ;
if ( F_61 ( V_6 ) ) {
unsigned long V_91 = F_82 ( V_6 ) ;
if ( V_91 > 0 && V_91 < V_64 )
V_83 += ( 1UL << V_91 ) - 1 ;
continue;
}
if ( F_58 ( V_6 ) ) {
unsigned int V_63 = F_59 ( V_6 ) ;
if ( F_60 ( V_63 < V_64 ) )
V_83 += ( 1UL << V_63 ) - 1 ;
goto V_62;
}
if ( ! F_83 ( V_6 ) ) {
if ( F_66 ( F_22 ( V_6 ) ) &&
! F_84 ( V_6 ) ) {
if ( V_52 ) {
F_52 ( F_81 ( V_24 ) ,
V_50 ) ;
V_52 = false ;
}
if ( F_85 ( V_6 , V_84 ) )
goto V_92;
}
goto V_62;
}
if ( ! F_23 ( V_6 ) &&
F_86 ( V_6 ) > F_87 ( V_6 ) )
goto V_62;
if ( ! V_52 ) {
V_52 = F_48 ( F_81 ( V_24 ) ,
& V_50 , V_32 ) ;
if ( ! V_52 )
break;
if ( ! F_83 ( V_6 ) )
goto V_62;
if ( F_66 ( F_58 ( V_6 ) ) ) {
V_83 += ( 1UL << F_59 ( V_6 ) ) - 1 ;
goto V_62;
}
}
V_85 = F_88 ( V_6 , V_24 -> V_74 ) ;
if ( F_89 ( V_6 , V_84 ) != 0 )
goto V_62;
F_20 ( F_58 ( V_6 ) , V_6 ) ;
F_90 ( V_6 , V_85 , F_91 ( V_6 ) ) ;
V_92:
F_15 ( & V_6 -> V_10 , & V_32 -> V_73 ) ;
V_32 -> V_66 ++ ;
V_45 ++ ;
if ( ! V_32 -> V_93 )
V_32 -> V_93 = V_83 ;
if ( V_32 -> V_66 == V_94 ) {
++ V_83 ;
break;
}
continue;
V_62:
if ( ! V_86 )
continue;
if ( V_45 ) {
if ( V_52 ) {
F_52 ( F_81 ( V_24 ) , V_50 ) ;
V_52 = false ;
}
F_72 ( V_24 , V_32 ) ;
F_92 ( & V_32 -> V_73 ) ;
V_32 -> V_66 = 0 ;
V_32 -> V_93 = 0 ;
V_45 = 0 ;
}
if ( V_83 < V_87 ) {
V_83 = V_87 - 1 ;
V_87 += 1UL << V_32 -> V_13 ;
}
}
if ( F_66 ( V_83 > V_38 ) )
V_83 = V_38 ;
if ( V_52 )
F_52 ( F_81 ( V_24 ) , V_50 ) ;
if ( V_83 == V_38 )
F_46 ( V_32 , V_58 , V_45 , true ) ;
F_93 ( V_37 , V_83 ,
V_55 , V_45 ) ;
F_3 ( V_95 , V_55 ) ;
if ( V_45 )
F_3 ( V_68 , V_45 ) ;
return V_83 ;
}
unsigned long
F_94 ( struct V_31 * V_32 , unsigned long V_37 ,
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
V_9 = F_79 ( V_32 , V_9 , V_70 ,
V_96 ) ;
if ( ! V_9 )
break;
if ( V_32 -> V_66 == V_94 )
break;
}
F_72 ( V_32 -> V_24 , V_32 ) ;
return V_9 ;
}
static bool F_95 ( struct V_6 * V_6 )
{
if ( F_61 ( V_6 ) ) {
if ( F_82 ( V_6 ) >= V_97 )
return false ;
}
if ( F_17 ( F_96 ( V_6 ) ) )
return true ;
return false ;
}
static inline bool F_97 ( struct V_31 * V_32 )
{
return ( V_32 -> V_98 >> V_97 )
<= ( V_32 -> V_99 >> V_97 ) ;
}
static void F_98 ( struct V_31 * V_32 )
{
struct V_24 * V_24 = V_32 -> V_24 ;
struct V_6 * V_6 ;
unsigned long V_69 ;
unsigned long V_71 ;
unsigned long V_70 ;
unsigned long V_83 ;
struct V_4 * V_5 = & V_32 -> V_100 ;
V_71 = V_32 -> V_98 ;
V_69 = F_36 ( V_32 -> V_98 ) ;
V_70 = F_70 ( V_69 + V_40 ,
F_37 ( V_24 ) ) ;
V_83 = F_69 ( V_32 -> V_99 ) ;
for (; V_69 >= V_83 ;
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
if ( ! F_95 ( V_6 ) )
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
V_32 -> V_98 = V_71 ;
}
static struct V_6 * F_99 ( struct V_6 * V_101 ,
unsigned long V_102 ,
int * * V_103 )
{
struct V_31 * V_32 = (struct V_31 * ) V_102 ;
struct V_6 * V_104 ;
if ( F_73 ( & V_32 -> V_100 ) ) {
if ( ! V_32 -> V_51 )
F_98 ( V_32 ) ;
if ( F_73 ( & V_32 -> V_100 ) )
return NULL ;
}
V_104 = F_100 ( V_32 -> V_100 . V_7 , struct V_6 , V_10 ) ;
F_8 ( & V_104 -> V_10 ) ;
V_32 -> V_65 -- ;
return V_104 ;
}
static void F_101 ( struct V_6 * V_6 , unsigned long V_102 )
{
struct V_31 * V_32 = (struct V_31 * ) V_102 ;
F_15 ( & V_6 -> V_10 , & V_32 -> V_100 ) ;
V_32 -> V_65 ++ ;
}
static T_4 F_102 ( struct V_24 * V_24 ,
struct V_31 * V_32 )
{
unsigned long V_69 ;
unsigned long V_70 ;
unsigned long V_83 ;
struct V_6 * V_6 ;
const T_3 V_84 =
( V_105 ? V_96 : 0 ) |
( V_32 -> V_47 != V_106 ? V_107 : 0 ) ;
V_83 = V_32 -> V_99 ;
V_69 = F_36 ( V_83 ) ;
if ( V_69 < V_24 -> V_35 )
V_69 = V_24 -> V_35 ;
V_70 = F_69 ( V_83 ) ;
for (; V_70 <= V_32 -> V_98 ;
V_83 = V_70 ,
V_69 = V_70 ,
V_70 += V_40 ) {
if ( ! ( V_83 % ( V_61 * V_40 ) )
&& F_55 ( V_32 ) )
break;
V_6 = F_71 ( V_69 , V_70 ,
V_24 ) ;
if ( ! V_6 )
continue;
if ( ! F_33 ( V_32 , V_6 ) )
continue;
if ( V_32 -> V_47 == V_48 &&
! F_17 ( F_96 ( V_6 ) ) )
continue;
V_83 = F_79 ( V_32 , V_83 ,
V_70 , V_84 ) ;
if ( ! V_83 || V_32 -> V_51 ) {
F_72 ( V_24 , V_32 ) ;
return V_108 ;
}
break;
}
F_72 ( V_24 , V_32 ) ;
V_32 -> V_99 = V_83 ;
return V_32 -> V_66 ? V_109 : V_110 ;
}
static inline bool F_103 ( int V_13 )
{
return V_13 == - 1 ;
}
static enum V_111 F_104 ( struct V_24 * V_24 , struct V_31 * V_32 ,
const int V_17 )
{
unsigned int V_13 ;
unsigned long V_112 ;
if ( V_32 -> V_51 || F_53 ( V_53 ) )
return V_113 ;
if ( F_97 ( V_32 ) ) {
F_35 ( V_24 ) ;
if ( V_32 -> V_90 )
V_24 -> V_39 = true ;
if ( V_32 -> V_114 )
return V_115 ;
else
return V_116 ;
}
if ( F_103 ( V_32 -> V_13 ) )
return V_117 ;
V_112 = F_105 ( V_24 ) ;
if ( ! F_106 ( V_24 , V_32 -> V_13 , V_112 , V_32 -> V_118 ,
V_32 -> V_119 ) )
return V_117 ;
for ( V_13 = V_32 -> V_13 ; V_13 < V_64 ; V_13 ++ ) {
struct V_120 * V_121 = & V_24 -> V_120 [ V_13 ] ;
bool V_122 ;
if ( ! F_73 ( & V_121 -> V_123 [ V_17 ] ) )
return V_124 ;
#ifdef F_107
if ( V_17 == V_18 &&
! F_73 ( & V_121 -> V_123 [ V_125 ] ) )
return V_124 ;
#endif
if ( F_108 ( V_121 , V_13 , V_17 ,
true , & V_122 ) != - 1 )
return V_124 ;
}
return V_126 ;
}
static enum V_111 F_109 ( struct V_24 * V_24 ,
struct V_31 * V_32 ,
const int V_17 )
{
int V_127 ;
V_127 = F_104 ( V_24 , V_32 , V_17 ) ;
F_110 ( V_24 , V_32 -> V_13 , V_127 ) ;
if ( V_127 == V_126 )
V_127 = V_117 ;
return V_127 ;
}
static enum V_111 F_111 ( struct V_24 * V_24 , int V_13 ,
unsigned int V_119 ,
int V_118 ,
unsigned long V_128 )
{
int V_129 ;
unsigned long V_112 ;
if ( F_103 ( V_13 ) )
return V_117 ;
V_112 = F_105 ( V_24 ) ;
if ( F_106 ( V_24 , V_13 , V_112 , V_118 ,
V_119 ) )
return V_124 ;
V_112 += ( 2UL << V_13 ) ;
if ( ! F_112 ( V_24 , 0 , V_112 , V_118 ,
V_119 , V_128 ) )
return V_130 ;
V_129 = F_113 ( V_24 , V_13 ) ;
if ( V_129 >= 0 && V_129 <= V_131 )
return V_132 ;
return V_117 ;
}
enum V_111 F_114 ( struct V_24 * V_24 , int V_13 ,
unsigned int V_119 ,
int V_118 )
{
enum V_111 V_127 ;
V_127 = F_111 ( V_24 , V_13 , V_119 , V_118 ,
F_115 ( V_24 , V_133 ) ) ;
F_116 ( V_24 , V_13 , V_127 ) ;
if ( V_127 == V_132 )
V_127 = V_130 ;
return V_127 ;
}
bool F_117 ( struct V_134 * V_135 , int V_13 ,
int V_119 )
{
struct V_24 * V_24 ;
struct V_136 * V_137 ;
F_118 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long V_138 ;
enum V_111 V_111 ;
V_138 = F_119 ( V_24 ) / V_13 ;
V_138 += F_120 ( V_24 , V_133 ) ;
V_111 = F_111 ( V_24 , V_13 , V_119 ,
F_121 ( V_135 ) , V_138 ) ;
if ( V_111 != V_130 &&
V_111 != V_132 )
return true ;
}
return false ;
}
static enum V_111 F_122 ( struct V_24 * V_24 , struct V_31 * V_32 )
{
enum V_111 V_127 ;
unsigned long V_37 = V_24 -> V_35 ;
unsigned long V_38 = F_37 ( V_24 ) ;
const int V_17 = F_123 ( V_32 -> V_139 ) ;
const bool V_140 = V_32 -> V_47 != V_48 ;
V_127 = F_114 ( V_24 , V_32 -> V_13 , V_32 -> V_119 ,
V_32 -> V_118 ) ;
if ( V_127 == V_124 || V_127 == V_130 )
return V_127 ;
F_124 ( V_127 != V_117 ) ;
if ( F_32 ( V_24 , V_32 -> V_13 ) )
F_38 ( V_24 ) ;
V_32 -> V_99 = V_24 -> V_34 [ V_140 ] ;
V_32 -> V_98 = V_24 -> V_36 ;
if ( V_32 -> V_98 < V_37 || V_32 -> V_98 >= V_38 ) {
V_32 -> V_98 = F_36 ( V_38 - 1 ) ;
V_24 -> V_36 = V_32 -> V_98 ;
}
if ( V_32 -> V_99 < V_37 || V_32 -> V_99 >= V_38 ) {
V_32 -> V_99 = V_37 ;
V_24 -> V_34 [ 0 ] = V_32 -> V_99 ;
V_24 -> V_34 [ 1 ] = V_32 -> V_99 ;
}
if ( V_32 -> V_99 == V_37 )
V_32 -> V_114 = true ;
V_32 -> V_93 = 0 ;
F_125 ( V_37 , V_32 -> V_99 ,
V_32 -> V_98 , V_38 , V_140 ) ;
F_126 () ;
while ( ( V_127 = F_109 ( V_24 , V_32 , V_17 ) ) ==
V_117 ) {
int V_141 ;
switch ( F_102 ( V_24 , V_32 ) ) {
case V_108 :
V_127 = V_113 ;
F_92 ( & V_32 -> V_73 ) ;
V_32 -> V_66 = 0 ;
goto V_142;
case V_110 :
goto V_143;
case V_109 :
;
}
V_141 = F_127 ( & V_32 -> V_73 , F_99 ,
F_101 , ( unsigned long ) V_32 , V_32 -> V_47 ,
V_144 ) ;
F_128 ( V_32 -> V_66 , V_141 ,
& V_32 -> V_73 ) ;
V_32 -> V_66 = 0 ;
if ( V_141 ) {
F_92 ( & V_32 -> V_73 ) ;
if ( V_141 == - V_145 && ! F_97 ( V_32 ) ) {
V_127 = V_113 ;
goto V_142;
}
if ( V_32 -> V_90 &&
( V_32 -> V_47 == V_48 ) ) {
V_32 -> V_99 = V_70 (
V_32 -> V_99 - 1 , V_32 -> V_13 ) ;
V_32 -> V_93 = 0 ;
}
}
V_143:
if ( V_32 -> V_13 > 0 && V_32 -> V_93 ) {
int V_146 ;
unsigned long V_147 =
V_69 ( V_32 -> V_99 , V_32 -> V_13 ) ;
if ( V_32 -> V_93 < V_147 ) {
V_146 = F_129 () ;
F_130 ( V_146 ) ;
F_131 ( V_24 ) ;
F_132 () ;
V_32 -> V_93 = 0 ;
}
}
}
V_142:
if ( V_32 -> V_65 > 0 ) {
unsigned long V_98 = F_5 ( & V_32 -> V_100 ) ;
V_32 -> V_65 = 0 ;
F_124 ( V_98 == 0 ) ;
V_98 = F_36 ( V_98 ) ;
if ( V_98 > V_24 -> V_36 )
V_24 -> V_36 = V_98 ;
}
F_133 ( V_37 , V_32 -> V_99 ,
V_32 -> V_98 , V_38 , V_140 , V_127 ) ;
return V_127 ;
}
static enum V_111 F_134 ( struct V_24 * V_24 , int V_13 ,
T_5 V_139 , enum V_148 V_149 ,
unsigned int V_119 , int V_118 )
{
enum V_111 V_127 ;
struct V_31 V_32 = {
. V_65 = 0 ,
. V_66 = 0 ,
. V_13 = V_13 ,
. V_139 = V_139 ,
. V_24 = V_24 ,
. V_47 = ( V_149 == V_150 ) ?
V_48 : V_151 ,
. V_119 = V_119 ,
. V_118 = V_118 ,
. V_90 = true ,
} ;
F_135 ( & V_32 . V_100 ) ;
F_135 ( & V_32 . V_73 ) ;
V_127 = F_122 ( V_24 , & V_32 ) ;
F_124 ( ! F_73 ( & V_32 . V_100 ) ) ;
F_124 ( ! F_73 ( & V_32 . V_73 ) ) ;
return V_127 ;
}
enum V_111 F_136 ( T_5 V_139 , unsigned int V_13 ,
unsigned int V_119 , const struct V_134 * V_135 ,
enum V_148 V_149 )
{
int V_152 = V_139 & V_153 ;
int V_154 = V_139 & V_155 ;
struct V_136 * V_137 ;
struct V_24 * V_24 ;
enum V_111 V_156 = V_130 ;
if ( ! V_152 || ! V_154 )
return V_130 ;
F_137 ( V_13 , V_139 , V_149 ) ;
F_118 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
enum V_111 V_157 ;
if ( F_28 ( V_24 , V_13 ) ) {
V_156 = F_138 ( enum V_111 , V_158 , V_156 ) ;
continue;
}
V_157 = F_134 ( V_24 , V_13 , V_139 , V_149 ,
V_119 , F_121 ( V_135 ) ) ;
V_156 = F_139 ( V_157 , V_156 ) ;
if ( F_106 ( V_24 , V_13 , F_105 ( V_24 ) ,
F_121 ( V_135 ) , V_119 ) ) {
F_30 ( V_24 , V_13 , false ) ;
break;
}
if ( V_149 != V_150 && ( V_157 == V_115 ||
V_157 == V_116 ) )
F_26 ( V_24 , V_13 ) ;
if ( ( V_149 == V_150 && F_54 () )
|| F_53 ( V_53 ) )
break;
}
return V_156 ;
}
static void F_140 ( T_1 * V_41 , struct V_31 * V_32 )
{
int V_42 ;
struct V_24 * V_24 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_24 = & V_41 -> V_44 [ V_42 ] ;
if ( ! F_45 ( V_24 ) )
continue;
V_32 -> V_65 = 0 ;
V_32 -> V_66 = 0 ;
V_32 -> V_24 = V_24 ;
F_135 ( & V_32 -> V_100 ) ;
F_135 ( & V_32 -> V_73 ) ;
if ( F_103 ( V_32 -> V_13 ) )
F_38 ( V_24 ) ;
if ( F_103 ( V_32 -> V_13 ) ||
! F_28 ( V_24 , V_32 -> V_13 ) )
F_122 ( V_24 , V_32 ) ;
F_124 ( ! F_73 ( & V_32 -> V_100 ) ) ;
F_124 ( ! F_73 ( & V_32 -> V_73 ) ) ;
if ( F_103 ( V_32 -> V_13 ) )
continue;
if ( F_106 ( V_24 , V_32 -> V_13 ,
F_105 ( V_24 ) , 0 , 0 ) )
F_30 ( V_24 , V_32 -> V_13 , false ) ;
}
}
void F_141 ( T_1 * V_41 , int V_13 )
{
struct V_31 V_32 = {
. V_13 = V_13 ,
. V_47 = V_48 ,
} ;
if ( ! V_13 )
return;
F_140 ( V_41 , & V_32 ) ;
}
static void F_142 ( int V_159 )
{
struct V_31 V_32 = {
. V_13 = - 1 ,
. V_47 = V_106 ,
. V_33 = true ,
} ;
F_140 ( F_143 ( V_159 ) , & V_32 ) ;
}
static void F_144 ( void )
{
int V_159 ;
F_145 () ;
F_146 (nid)
F_142 ( V_159 ) ;
}
int F_147 ( struct V_160 * V_161 , int V_162 ,
void T_6 * V_163 , T_7 * V_164 , T_8 * V_165 )
{
if ( V_162 )
F_144 () ;
return 0 ;
}
int F_148 ( struct V_160 * V_161 , int V_162 ,
void T_6 * V_163 , T_7 * V_164 , T_8 * V_165 )
{
F_149 ( V_161 , V_162 , V_163 , V_164 , V_165 ) ;
return 0 ;
}
static T_9 F_150 ( struct V_166 * V_167 ,
struct V_168 * V_169 ,
const char * V_170 , T_7 V_72 )
{
int V_159 = V_167 -> V_171 ;
if ( V_159 >= 0 && V_159 < V_172 && F_151 ( V_159 ) ) {
F_145 () ;
F_142 ( V_159 ) ;
}
return V_72 ;
}
int F_152 ( struct V_173 * V_173 )
{
return F_153 ( & V_173 -> V_167 , & V_174 ) ;
}
void F_154 ( struct V_173 * V_173 )
{
return F_155 ( & V_173 -> V_167 , & V_174 ) ;
}
static inline bool F_156 ( T_1 * V_41 )
{
return V_41 -> V_175 > 0 || F_157 () ;
}
static bool F_158 ( T_1 * V_41 )
{
int V_42 ;
struct V_24 * V_24 ;
enum V_176 V_118 = V_41 -> V_177 ;
for ( V_42 = 0 ; V_42 <= V_118 ; V_42 ++ ) {
V_24 = & V_41 -> V_44 [ V_42 ] ;
if ( ! F_45 ( V_24 ) )
continue;
if ( F_114 ( V_24 , V_41 -> V_175 , 0 ,
V_118 ) == V_117 )
return true ;
}
return false ;
}
static void F_159 ( T_1 * V_41 )
{
int V_42 ;
struct V_24 * V_24 ;
struct V_31 V_32 = {
. V_13 = V_41 -> V_175 ,
. V_118 = V_41 -> V_177 ,
. V_47 = V_151 ,
. V_33 = true ,
} ;
bool V_178 = false ;
F_160 ( V_41 -> V_179 , V_32 . V_13 ,
V_32 . V_118 ) ;
F_2 ( V_180 ) ;
for ( V_42 = 0 ; V_42 <= V_32 . V_118 ; V_42 ++ ) {
int V_157 ;
V_24 = & V_41 -> V_44 [ V_42 ] ;
if ( ! F_45 ( V_24 ) )
continue;
if ( F_28 ( V_24 , V_32 . V_13 ) )
continue;
if ( F_114 ( V_24 , V_32 . V_13 , 0 , V_42 ) !=
V_117 )
continue;
V_32 . V_65 = 0 ;
V_32 . V_66 = 0 ;
V_32 . V_24 = V_24 ;
F_135 ( & V_32 . V_100 ) ;
F_135 ( & V_32 . V_73 ) ;
if ( F_157 () )
return;
V_157 = F_122 ( V_24 , & V_32 ) ;
if ( F_106 ( V_24 , V_32 . V_13 , F_105 ( V_24 ) ,
V_32 . V_118 , 0 ) ) {
V_178 = true ;
F_30 ( V_24 , V_32 . V_13 , false ) ;
} else if ( V_157 == V_116 || V_157 == V_115 ) {
F_26 ( V_24 , V_32 . V_13 ) ;
}
F_124 ( ! F_73 ( & V_32 . V_100 ) ) ;
F_124 ( ! F_73 ( & V_32 . V_73 ) ) ;
}
if ( V_41 -> V_175 <= V_32 . V_13 )
V_41 -> V_175 = 0 ;
if ( V_41 -> V_177 >= V_32 . V_118 )
V_41 -> V_177 = V_41 -> V_181 - 1 ;
}
void F_161 ( T_1 * V_41 , int V_13 , int V_118 )
{
if ( ! V_13 )
return;
if ( V_41 -> V_175 < V_13 )
V_41 -> V_175 = V_13 ;
if ( V_41 -> V_177 > V_118 )
V_41 -> V_177 = V_118 ;
if ( ! F_162 ( & V_41 -> V_182 ) )
return;
if ( ! F_158 ( V_41 ) )
return;
F_163 ( V_41 -> V_179 , V_13 ,
V_118 ) ;
F_164 ( & V_41 -> V_182 ) ;
}
static int F_165 ( void * V_183 )
{
T_1 * V_41 = ( T_1 * ) V_183 ;
struct V_184 * V_185 = V_53 ;
const struct V_186 * V_186 = F_166 ( V_41 -> V_179 ) ;
if ( ! F_167 ( V_186 ) )
F_168 ( V_185 , V_186 ) ;
F_169 () ;
V_41 -> V_175 = 0 ;
V_41 -> V_177 = V_41 -> V_181 - 1 ;
while ( ! F_157 () ) {
F_170 ( V_41 -> V_179 ) ;
F_171 ( V_41 -> V_182 ,
F_156 ( V_41 ) ) ;
F_159 ( V_41 ) ;
}
return 0 ;
}
int F_172 ( int V_159 )
{
T_1 * V_41 = F_143 ( V_159 ) ;
int V_127 = 0 ;
if ( V_41 -> F_165 )
return 0 ;
V_41 -> F_165 = F_173 ( F_165 , V_41 , L_1 , V_159 ) ;
if ( F_174 ( V_41 -> F_165 ) ) {
F_175 ( L_2 , V_159 ) ;
V_127 = F_176 ( V_41 -> F_165 ) ;
V_41 -> F_165 = NULL ;
}
return V_127 ;
}
void F_177 ( int V_159 )
{
struct V_184 * F_165 = F_143 ( V_159 ) -> F_165 ;
if ( F_165 ) {
F_178 ( F_165 ) ;
F_143 ( V_159 ) -> F_165 = NULL ;
}
}
static int F_179 ( struct V_187 * V_188 , unsigned long V_189 ,
void * V_190 )
{
int V_159 ;
if ( V_189 == V_191 || V_189 == V_192 ) {
F_180 (nid, N_MEMORY) {
T_1 * V_41 = F_143 ( V_159 ) ;
const struct V_186 * V_193 ;
V_193 = F_166 ( V_41 -> V_179 ) ;
if ( F_181 ( V_194 , V_193 ) < V_195 )
F_168 ( V_41 -> F_165 , V_193 ) ;
}
}
return V_196 ;
}
static int T_10 F_182 ( void )
{
int V_159 ;
F_180 (nid, N_MEMORY)
F_172 ( V_159 ) ;
F_183 ( F_179 , 0 ) ;
return 0 ;
}
