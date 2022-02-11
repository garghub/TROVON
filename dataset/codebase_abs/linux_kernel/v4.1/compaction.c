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
unsigned long V_14 = V_16 -> V_29 ;
unsigned long V_15 = F_32 ( V_16 ) ;
unsigned long V_9 ;
V_16 -> V_30 [ 0 ] = V_14 ;
V_16 -> V_30 [ 1 ] = V_14 ;
V_16 -> V_31 = V_15 ;
V_16 -> V_32 = false ;
for ( V_9 = V_14 ; V_9 < V_15 ; V_9 += V_33 ) {
struct V_6 * V_6 ;
F_33 () ;
if ( ! F_18 ( V_9 ) )
continue;
V_6 = F_19 ( V_9 ) ;
if ( V_16 != F_20 ( V_6 ) )
continue;
F_34 ( V_6 ) ;
}
}
void F_35 ( T_1 * V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
struct V_16 * V_16 = & V_34 -> V_37 [ V_35 ] ;
if ( ! F_36 ( V_16 ) )
continue;
if ( V_16 -> V_32 )
F_31 ( V_16 ) ;
}
}
static void F_37 ( struct V_26 * V_27 ,
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
F_38 ( V_6 ) ;
V_9 = F_7 ( V_6 ) ;
if ( V_39 ) {
if ( V_9 > V_16 -> V_30 [ 0 ] )
V_16 -> V_30 [ 0 ] = V_9 ;
if ( V_27 -> V_40 != V_41 &&
V_9 > V_16 -> V_30 [ 1 ] )
V_16 -> V_30 [ 1 ] = V_9 ;
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
static void F_37 ( struct V_26 * V_27 ,
struct V_6 * V_6 , unsigned long V_38 ,
bool V_39 )
{
}
static bool F_39 ( T_2 * V_42 , unsigned long * V_43 ,
struct V_26 * V_27 )
{
if ( V_27 -> V_40 == V_41 ) {
if ( ! F_40 ( V_42 , * V_43 ) ) {
V_27 -> V_44 = V_45 ;
return false ;
}
} else {
F_41 ( V_42 , * V_43 ) ;
}
return true ;
}
static bool F_42 ( T_2 * V_42 ,
unsigned long V_43 , bool * V_46 , struct V_26 * V_27 )
{
if ( * V_46 ) {
F_43 ( V_42 , V_43 ) ;
* V_46 = false ;
}
if ( F_44 ( V_47 ) ) {
V_27 -> V_44 = V_48 ;
return true ;
}
if ( F_45 () ) {
if ( V_27 -> V_40 == V_41 ) {
V_27 -> V_44 = V_48 ;
return true ;
}
F_33 () ;
}
return false ;
}
static inline bool F_46 ( struct V_26 * V_27 )
{
if ( F_45 () ) {
if ( V_27 -> V_40 == V_41 ) {
V_27 -> V_44 = V_48 ;
return true ;
}
F_33 () ;
}
return false ;
}
static unsigned long F_47 ( struct V_26 * V_27 ,
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
&& F_42 ( & V_27 -> V_16 -> V_42 , V_43 ,
& V_46 , V_27 ) )
break;
V_50 ++ ;
if ( ! F_48 ( V_54 ) )
goto V_58;
if ( ! V_53 )
V_53 = V_6 ;
if ( ! F_49 ( V_6 ) )
goto V_58;
if ( ! V_46 ) {
V_46 = F_39 ( & V_27 -> V_16 -> V_42 ,
& V_43 , V_27 ) ;
if ( ! V_46 )
break;
if ( ! F_49 ( V_6 ) )
goto V_58;
}
V_55 = F_50 ( V_6 ) ;
V_51 += V_55 ;
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ ) {
F_51 ( & V_6 -> V_10 , V_5 ) ;
V_6 ++ ;
}
if ( V_55 ) {
V_27 -> V_59 += V_55 ;
if ( ! V_49 &&
V_27 -> V_60 <= V_27 -> V_59 ) {
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
F_52 ( * V_14 , V_54 ,
V_50 , V_51 ) ;
* V_14 = V_54 ;
if ( V_49 && V_54 < V_15 )
V_51 = 0 ;
if ( V_46 )
F_43 ( & V_27 -> V_16 -> V_42 , V_43 ) ;
if ( V_54 == V_15 )
F_37 ( V_27 , V_53 , V_51 , false ) ;
F_3 ( V_61 , V_50 ) ;
if ( V_51 )
F_3 ( V_62 , V_51 ) ;
return V_51 ;
}
unsigned long
F_53 ( struct V_26 * V_27 ,
unsigned long V_14 , unsigned long V_15 )
{
unsigned long V_55 , V_9 , V_63 ;
F_54 ( V_5 ) ;
V_9 = V_14 ;
V_63 = F_55 ( V_9 + 1 , V_33 ) ;
for (; V_9 < V_15 ; V_9 += V_55 ,
V_63 += V_33 ) {
unsigned long V_64 = V_9 ;
V_63 = F_56 ( V_63 , V_15 ) ;
if ( V_9 >= V_63 ) {
V_63 = F_55 ( V_9 + 1 , V_33 ) ;
V_63 = F_56 ( V_63 , V_15 ) ;
}
if ( ! F_17 ( V_9 , V_63 , V_27 -> V_16 ) )
break;
V_55 = F_47 ( V_27 , & V_64 ,
V_63 , & V_5 , true ) ;
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
static void F_57 ( struct V_16 * V_16 , struct V_26 * V_27 )
{
struct V_6 * V_6 ;
unsigned int V_65 [ 2 ] = { 0 , } ;
if ( F_58 ( & V_27 -> V_66 ) )
return;
F_11 (page, &cc->migratepages, lru)
V_65 [ ! ! F_59 ( V_6 ) ] ++ ;
F_60 ( V_16 , V_67 , V_65 [ 0 ] ) ;
F_60 ( V_16 , V_68 , V_65 [ 1 ] ) ;
}
static bool F_61 ( struct V_16 * V_16 )
{
unsigned long V_69 , V_70 , V_55 ;
V_70 = F_62 ( V_16 , V_71 ) +
F_62 ( V_16 , V_72 ) ;
V_69 = F_62 ( V_16 , V_73 ) +
F_62 ( V_16 , V_74 ) ;
V_55 = F_62 ( V_16 , V_68 ) +
F_62 ( V_16 , V_67 ) ;
return V_55 > ( V_70 + V_69 ) / 2 ;
}
static unsigned long
F_63 ( struct V_26 * V_27 , unsigned long V_75 ,
unsigned long V_15 , T_3 V_76 )
{
struct V_16 * V_16 = V_27 -> V_16 ;
unsigned long V_50 = 0 , V_38 = 0 ;
struct V_4 * V_77 = & V_27 -> V_66 ;
struct V_78 * V_78 ;
unsigned long V_43 = 0 ;
bool V_46 = false ;
struct V_6 * V_6 = NULL , * V_53 = NULL ;
unsigned long V_14 = V_75 ;
while ( F_64 ( F_61 ( V_16 ) ) ) {
if ( V_27 -> V_40 == V_41 )
return 0 ;
F_65 ( V_79 , V_80 / 10 ) ;
if ( F_44 ( V_47 ) )
return 0 ;
}
if ( F_46 ( V_27 ) )
return 0 ;
for (; V_75 < V_15 ; V_75 ++ ) {
if ( ! ( V_75 % V_57 )
&& F_42 ( & V_16 -> V_81 , V_43 ,
& V_46 , V_27 ) )
break;
if ( ! F_48 ( V_75 ) )
continue;
V_50 ++ ;
V_6 = F_19 ( V_75 ) ;
if ( ! V_53 )
V_53 = V_6 ;
if ( F_49 ( V_6 ) ) {
unsigned long V_82 = F_66 ( V_6 ) ;
if ( V_82 > 0 && V_82 < V_83 )
V_75 += ( 1UL << V_82 ) - 1 ;
continue;
}
if ( ! F_67 ( V_6 ) ) {
if ( F_64 ( F_68 ( V_6 ) ) ) {
if ( F_69 ( V_6 ) ) {
goto V_84;
}
}
continue;
}
if ( F_70 ( V_6 ) ) {
if ( ! V_46 )
V_75 = F_55 ( V_75 + 1 ,
V_33 ) - 1 ;
else
V_75 += ( 1 << F_71 ( V_6 ) ) - 1 ;
continue;
}
if ( ! F_72 ( V_6 ) &&
F_73 ( V_6 ) > F_74 ( V_6 ) )
continue;
if ( ! V_46 ) {
V_46 = F_39 ( & V_16 -> V_81 ,
& V_43 , V_27 ) ;
if ( ! V_46 )
break;
if ( ! F_67 ( V_6 ) )
continue;
if ( F_70 ( V_6 ) ) {
V_75 += ( 1 << F_71 ( V_6 ) ) - 1 ;
continue;
}
}
V_78 = F_75 ( V_6 , V_16 ) ;
if ( F_76 ( V_6 , V_76 ) != 0 )
continue;
F_77 ( F_78 ( V_6 ) , V_6 ) ;
F_79 ( V_6 , V_78 , F_80 ( V_6 ) ) ;
V_84:
F_51 ( & V_6 -> V_10 , V_77 ) ;
V_27 -> V_60 ++ ;
V_38 ++ ;
if ( V_27 -> V_60 == V_85 ) {
++ V_75 ;
break;
}
}
if ( F_64 ( V_75 > V_15 ) )
V_75 = V_15 ;
if ( V_46 )
F_43 ( & V_16 -> V_81 , V_43 ) ;
if ( V_75 == V_15 )
F_37 ( V_27 , V_53 , V_38 , true ) ;
F_81 ( V_14 , V_75 ,
V_50 , V_38 ) ;
F_3 ( V_86 , V_50 ) ;
if ( V_38 )
F_3 ( V_62 , V_38 ) ;
return V_75 ;
}
unsigned long
F_82 ( struct V_26 * V_27 , unsigned long V_14 ,
unsigned long V_15 )
{
unsigned long V_9 , V_63 ;
V_9 = V_14 ;
V_63 = F_55 ( V_9 + 1 , V_33 ) ;
for (; V_9 < V_15 ; V_9 = V_63 ,
V_63 += V_33 ) {
V_63 = F_56 ( V_63 , V_15 ) ;
if ( ! F_17 ( V_9 , V_63 , V_27 -> V_16 ) )
continue;
V_9 = F_63 ( V_27 , V_9 , V_63 ,
V_87 ) ;
if ( ! V_9 ) {
F_83 ( & V_27 -> V_66 ) ;
V_27 -> V_60 = 0 ;
break;
}
if ( V_27 -> V_60 == V_85 )
break;
}
F_57 ( V_27 -> V_16 , V_27 ) ;
return V_9 ;
}
static bool F_84 ( struct V_6 * V_6 )
{
if ( F_49 ( V_6 ) ) {
if ( F_66 ( V_6 ) >= V_88 )
return false ;
}
if ( F_15 ( F_85 ( V_6 ) ) )
return true ;
return false ;
}
static void F_86 ( struct V_26 * V_27 )
{
struct V_16 * V_16 = V_27 -> V_16 ;
struct V_6 * V_6 ;
unsigned long V_89 ;
unsigned long V_64 ;
unsigned long V_63 ;
unsigned long V_75 ;
struct V_4 * V_5 = & V_27 -> V_90 ;
V_64 = V_27 -> V_91 ;
V_89 = V_27 -> V_91 & ~ ( V_33 - 1 ) ;
V_63 = F_56 ( V_89 + V_33 ,
F_32 ( V_16 ) ) ;
V_75 = F_55 ( V_27 -> V_92 + 1 , V_33 ) ;
for (; V_89 >= V_75 &&
V_27 -> V_60 > V_27 -> V_59 ;
V_63 = V_89 ,
V_89 -= V_33 ,
V_64 = V_89 ) {
if ( ! ( V_89 % ( V_57 * V_33 ) )
&& F_46 ( V_27 ) )
break;
V_6 = F_17 ( V_89 , V_63 ,
V_16 ) ;
if ( ! V_6 )
continue;
if ( ! F_84 ( V_6 ) )
continue;
if ( ! F_29 ( V_27 , V_6 ) )
continue;
F_47 ( V_27 , & V_64 ,
V_63 , V_5 , false ) ;
V_27 -> V_91 = ( V_64 < V_63 ) ?
V_64 :
V_89 - V_33 ;
if ( V_27 -> V_44 )
break;
}
F_10 ( V_5 ) ;
if ( V_89 < V_75 )
V_27 -> V_91 = V_27 -> V_92 ;
}
static struct V_6 * F_87 ( struct V_6 * V_93 ,
unsigned long V_94 ,
int * * V_95 )
{
struct V_26 * V_27 = (struct V_26 * ) V_94 ;
struct V_6 * V_96 ;
if ( F_58 ( & V_27 -> V_90 ) ) {
if ( ! V_27 -> V_44 )
F_86 ( V_27 ) ;
if ( F_58 ( & V_27 -> V_90 ) )
return NULL ;
}
V_96 = F_88 ( V_27 -> V_90 . V_7 , struct V_6 , V_10 ) ;
F_8 ( & V_96 -> V_10 ) ;
V_27 -> V_59 -- ;
return V_96 ;
}
static void F_89 ( struct V_6 * V_6 , unsigned long V_94 )
{
struct V_26 * V_27 = (struct V_26 * ) V_94 ;
F_51 ( & V_6 -> V_10 , & V_27 -> V_90 ) ;
V_27 -> V_59 ++ ;
}
static T_4 F_90 ( struct V_16 * V_16 ,
struct V_26 * V_27 )
{
unsigned long V_75 , V_15 ;
struct V_6 * V_6 ;
const T_3 V_76 =
( V_97 ? V_87 : 0 ) |
( V_27 -> V_40 == V_41 ? V_98 : 0 ) ;
V_75 = V_27 -> V_92 ;
V_15 = F_55 ( V_75 + 1 , V_33 ) ;
for (; V_15 <= V_27 -> V_91 ;
V_75 = V_15 , V_15 += V_33 ) {
if ( ! ( V_75 % ( V_57 * V_33 ) )
&& F_46 ( V_27 ) )
break;
V_6 = F_17 ( V_75 , V_15 , V_16 ) ;
if ( ! V_6 )
continue;
if ( ! F_29 ( V_27 , V_6 ) )
continue;
if ( V_27 -> V_40 == V_41 &&
! F_15 ( F_85 ( V_6 ) ) )
continue;
V_75 = F_63 ( V_27 , V_75 , V_15 ,
V_76 ) ;
if ( ! V_75 || V_27 -> V_44 ) {
F_57 ( V_16 , V_27 ) ;
return V_99 ;
}
break;
}
F_57 ( V_16 , V_27 ) ;
V_27 -> V_92 = ( V_15 <= V_27 -> V_91 ) ? V_75 : V_27 -> V_91 ;
return V_27 -> V_60 ? V_100 : V_101 ;
}
static int F_91 ( struct V_16 * V_16 , struct V_26 * V_27 ,
const int V_12 )
{
unsigned int V_19 ;
unsigned long V_102 ;
if ( V_27 -> V_44 || F_44 ( V_47 ) )
return V_103 ;
if ( V_27 -> V_91 <= V_27 -> V_92 ) {
V_16 -> V_30 [ 0 ] = V_16 -> V_29 ;
V_16 -> V_30 [ 1 ] = V_16 -> V_29 ;
V_16 -> V_31 = F_32 ( V_16 ) ;
if ( ! F_92 () )
V_16 -> V_32 = true ;
return V_104 ;
}
if ( V_27 -> V_19 == - 1 )
return V_105 ;
V_102 = F_93 ( V_16 ) ;
if ( ! F_94 ( V_16 , V_27 -> V_19 , V_102 , V_27 -> V_106 ,
V_27 -> V_107 ) )
return V_105 ;
for ( V_19 = V_27 -> V_19 ; V_19 < V_83 ; V_19 ++ ) {
struct V_108 * V_109 = & V_16 -> V_108 [ V_19 ] ;
bool V_110 ;
if ( ! F_58 ( & V_109 -> V_111 [ V_12 ] ) )
return V_103 ;
#ifdef F_95
if ( V_12 == V_13 &&
! F_58 ( & V_109 -> V_111 [ V_112 ] ) )
return V_103 ;
#endif
if ( F_96 ( V_109 , V_19 , V_12 ,
true , & V_110 ) != - 1 )
return V_103 ;
}
return V_113 ;
}
static int F_97 ( struct V_16 * V_16 , struct V_26 * V_27 ,
const int V_12 )
{
int V_114 ;
V_114 = F_91 ( V_16 , V_27 , V_12 ) ;
F_98 ( V_16 , V_27 -> V_19 , V_114 ) ;
if ( V_114 == V_113 )
V_114 = V_105 ;
return V_114 ;
}
static unsigned long F_99 ( struct V_16 * V_16 , int V_19 ,
int V_107 , int V_106 )
{
int V_115 ;
unsigned long V_102 ;
if ( V_19 == - 1 )
return V_105 ;
V_102 = F_93 ( V_16 ) ;
if ( F_94 ( V_16 , V_19 , V_102 , V_106 ,
V_107 ) )
return V_103 ;
V_102 += ( 2UL << V_19 ) ;
if ( ! F_94 ( V_16 , 0 , V_102 , V_106 , V_107 ) )
return V_116 ;
V_115 = F_100 ( V_16 , V_19 ) ;
if ( V_115 >= 0 && V_115 <= V_117 )
return V_118 ;
return V_105 ;
}
unsigned long F_101 ( struct V_16 * V_16 , int V_19 ,
int V_107 , int V_106 )
{
unsigned long V_114 ;
V_114 = F_99 ( V_16 , V_19 , V_107 , V_106 ) ;
F_102 ( V_16 , V_19 , V_114 ) ;
if ( V_114 == V_118 )
V_114 = V_116 ;
return V_114 ;
}
static int F_103 ( struct V_16 * V_16 , struct V_26 * V_27 )
{
int V_114 ;
unsigned long V_14 = V_16 -> V_29 ;
unsigned long V_15 = F_32 ( V_16 ) ;
const int V_12 = F_104 ( V_27 -> V_119 ) ;
const bool V_120 = V_27 -> V_40 != V_41 ;
unsigned long V_121 = 0 ;
V_114 = F_101 ( V_16 , V_27 -> V_19 , V_27 -> V_107 ,
V_27 -> V_106 ) ;
switch ( V_114 ) {
case V_103 :
case V_116 :
return V_114 ;
case V_105 :
;
}
if ( F_28 ( V_16 , V_27 -> V_19 ) && ! F_92 () )
F_31 ( V_16 ) ;
V_27 -> V_92 = V_16 -> V_30 [ V_120 ] ;
V_27 -> V_91 = V_16 -> V_31 ;
if ( V_27 -> V_91 < V_14 || V_27 -> V_91 > V_15 ) {
V_27 -> V_91 = V_15 & ~ ( V_33 - 1 ) ;
V_16 -> V_31 = V_27 -> V_91 ;
}
if ( V_27 -> V_92 < V_14 || V_27 -> V_92 > V_15 ) {
V_27 -> V_92 = V_14 ;
V_16 -> V_30 [ 0 ] = V_27 -> V_92 ;
V_16 -> V_30 [ 1 ] = V_27 -> V_92 ;
}
F_105 ( V_14 , V_27 -> V_92 ,
V_27 -> V_91 , V_15 , V_120 ) ;
F_106 () ;
while ( ( V_114 = F_97 ( V_16 , V_27 , V_12 ) ) ==
V_105 ) {
int V_122 ;
unsigned long V_64 = V_27 -> V_92 ;
switch ( F_90 ( V_16 , V_27 ) ) {
case V_99 :
V_114 = V_103 ;
F_83 ( & V_27 -> V_66 ) ;
V_27 -> V_60 = 0 ;
goto V_123;
case V_101 :
goto V_124;
case V_100 :
;
}
V_122 = F_107 ( & V_27 -> V_66 , F_87 ,
F_89 , ( unsigned long ) V_27 , V_27 -> V_40 ,
V_125 ) ;
F_108 ( V_27 -> V_60 , V_122 ,
& V_27 -> V_66 ) ;
V_27 -> V_60 = 0 ;
if ( V_122 ) {
F_83 ( & V_27 -> V_66 ) ;
if ( V_122 == - V_126 && V_27 -> V_91 > V_27 -> V_92 ) {
V_114 = V_103 ;
goto V_123;
}
}
if ( ! V_121 )
V_121 = V_64 ;
V_124:
if ( V_27 -> V_19 > 0 && V_121 ) {
int V_127 ;
unsigned long V_128 =
V_27 -> V_92 & ~ ( ( 1UL << V_27 -> V_19 ) - 1 ) ;
if ( V_121 < V_128 ) {
V_127 = F_109 () ;
F_110 ( V_127 ) ;
F_111 ( V_16 ) ;
F_112 () ;
V_121 = 0 ;
}
}
}
V_123:
if ( V_27 -> V_59 > 0 ) {
unsigned long V_91 = F_5 ( & V_27 -> V_90 ) ;
V_27 -> V_59 = 0 ;
F_113 ( V_91 == 0 ) ;
V_91 &= ~ ( V_33 - 1 ) ;
if ( V_91 > V_16 -> V_31 )
V_16 -> V_31 = V_91 ;
}
F_114 ( V_14 , V_27 -> V_92 ,
V_27 -> V_91 , V_15 , V_120 , V_114 ) ;
return V_114 ;
}
static unsigned long F_115 ( struct V_16 * V_16 , int V_19 ,
T_5 V_119 , enum V_129 V_40 , int * V_44 ,
int V_107 , int V_106 )
{
unsigned long V_114 ;
struct V_26 V_27 = {
. V_59 = 0 ,
. V_60 = 0 ,
. V_19 = V_19 ,
. V_119 = V_119 ,
. V_16 = V_16 ,
. V_40 = V_40 ,
. V_107 = V_107 ,
. V_106 = V_106 ,
} ;
F_116 ( & V_27 . V_90 ) ;
F_116 ( & V_27 . V_66 ) ;
V_114 = F_103 ( V_16 , & V_27 ) ;
F_113 ( ! F_58 ( & V_27 . V_90 ) ) ;
F_113 ( ! F_58 ( & V_27 . V_66 ) ) ;
* V_44 = V_27 . V_44 ;
return V_114 ;
}
unsigned long F_117 ( T_5 V_119 , unsigned int V_19 ,
int V_107 , const struct V_130 * V_131 ,
enum V_129 V_40 , int * V_44 )
{
int V_132 = V_119 & V_133 ;
int V_134 = V_119 & V_135 ;
struct V_136 * V_137 ;
struct V_16 * V_16 ;
int V_138 = V_139 ;
int V_140 = V_45 ;
* V_44 = V_141 ;
if ( ! V_19 || ! V_132 || ! V_134 )
return V_116 ;
F_118 ( V_19 , V_119 , V_40 ) ;
F_119 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
int V_142 ;
int V_143 ;
if ( F_24 ( V_16 , V_19 ) )
continue;
V_142 = F_115 ( V_16 , V_19 , V_119 , V_40 ,
& V_143 , V_107 ,
V_131 -> V_106 ) ;
V_138 = F_120 ( V_142 , V_138 ) ;
V_140 &= V_143 ;
if ( F_94 ( V_16 , V_19 , F_93 ( V_16 ) ,
V_131 -> V_106 , V_107 ) ) {
F_26 ( V_16 , V_19 , false ) ;
if ( V_143 == V_48 )
* V_44 = V_48 ;
goto V_144;
}
if ( V_40 != V_41 && V_142 == V_104 ) {
F_22 ( V_16 , V_19 ) ;
}
if ( ( V_143 == V_48 )
|| F_44 ( V_47 ) ) {
* V_44 = V_48 ;
goto V_144;
}
continue;
V_144:
V_140 = 0 ;
break;
}
if ( V_138 > V_116 && V_140 )
* V_44 = V_45 ;
return V_138 ;
}
static void F_121 ( T_1 * V_34 , struct V_26 * V_27 )
{
int V_35 ;
struct V_16 * V_16 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_16 = & V_34 -> V_37 [ V_35 ] ;
if ( ! F_36 ( V_16 ) )
continue;
V_27 -> V_59 = 0 ;
V_27 -> V_60 = 0 ;
V_27 -> V_16 = V_16 ;
F_116 ( & V_27 -> V_90 ) ;
F_116 ( & V_27 -> V_66 ) ;
if ( V_27 -> V_19 == - 1 )
F_31 ( V_16 ) ;
if ( V_27 -> V_19 == - 1 || ! F_24 ( V_16 , V_27 -> V_19 ) )
F_103 ( V_16 , V_27 ) ;
if ( V_27 -> V_19 > 0 ) {
if ( F_94 ( V_16 , V_27 -> V_19 ,
F_93 ( V_16 ) , 0 , 0 ) )
F_26 ( V_16 , V_27 -> V_19 , false ) ;
}
F_113 ( ! F_58 ( & V_27 -> V_90 ) ) ;
F_113 ( ! F_58 ( & V_27 -> V_66 ) ) ;
}
}
void F_122 ( T_1 * V_34 , int V_19 )
{
struct V_26 V_27 = {
. V_19 = V_19 ,
. V_40 = V_41 ,
} ;
if ( ! V_19 )
return;
F_121 ( V_34 , & V_27 ) ;
}
static void F_123 ( int V_145 )
{
struct V_26 V_27 = {
. V_19 = - 1 ,
. V_40 = V_146 ,
. V_28 = true ,
} ;
F_121 ( F_124 ( V_145 ) , & V_27 ) ;
}
static void F_125 ( void )
{
int V_145 ;
F_126 () ;
F_127 (nid)
F_123 ( V_145 ) ;
}
int F_128 ( struct V_147 * V_148 , int V_149 ,
void T_6 * V_150 , T_7 * V_151 , T_8 * V_152 )
{
if ( V_149 )
F_125 () ;
return 0 ;
}
int F_129 ( struct V_147 * V_148 , int V_149 ,
void T_6 * V_150 , T_7 * V_151 , T_8 * V_152 )
{
F_130 ( V_148 , V_149 , V_150 , V_151 , V_152 ) ;
return 0 ;
}
static T_9 F_131 ( struct V_153 * V_154 ,
struct V_155 * V_156 ,
const char * V_157 , T_7 V_65 )
{
int V_145 = V_154 -> V_158 ;
if ( V_145 >= 0 && V_145 < V_159 && F_132 ( V_145 ) ) {
F_126 () ;
F_123 ( V_145 ) ;
}
return V_65 ;
}
int F_133 ( struct V_160 * V_160 )
{
return F_134 ( & V_160 -> V_154 , & V_161 ) ;
}
void F_135 ( struct V_160 * V_160 )
{
return F_136 ( & V_160 -> V_154 , & V_161 ) ;
}
