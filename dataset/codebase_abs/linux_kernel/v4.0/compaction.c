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
static bool F_47 ( struct V_6 * V_6 )
{
if ( F_48 ( V_6 ) ) {
if ( F_49 ( V_6 ) >= V_49 )
return false ;
}
if ( F_15 ( F_50 ( V_6 ) ) )
return true ;
return false ;
}
static unsigned long F_51 ( struct V_26 * V_27 ,
unsigned long * V_14 ,
unsigned long V_15 ,
struct V_4 * V_5 ,
bool V_50 )
{
int V_51 = 0 , V_52 = 0 ;
struct V_6 * V_53 , * V_54 = NULL ;
unsigned long V_43 = 0 ;
bool V_46 = false ;
unsigned long V_55 = * V_14 ;
V_53 = F_19 ( V_55 ) ;
for (; V_55 < V_15 ; V_55 ++ , V_53 ++ ) {
int V_56 , V_57 ;
struct V_6 * V_6 = V_53 ;
if ( ! ( V_55 % V_58 )
&& F_42 ( & V_27 -> V_16 -> V_42 , V_43 ,
& V_46 , V_27 ) )
break;
V_51 ++ ;
if ( ! F_52 ( V_55 ) )
goto V_59;
if ( ! V_54 )
V_54 = V_6 ;
if ( ! F_48 ( V_6 ) )
goto V_59;
if ( ! V_46 ) {
V_46 = F_39 ( & V_27 -> V_16 -> V_42 ,
& V_43 , V_27 ) ;
if ( ! V_46 )
break;
if ( ! F_48 ( V_6 ) )
goto V_59;
}
V_56 = F_53 ( V_6 ) ;
V_52 += V_56 ;
for ( V_57 = 0 ; V_57 < V_56 ; V_57 ++ ) {
F_54 ( & V_6 -> V_10 , V_5 ) ;
V_6 ++ ;
}
if ( V_56 ) {
V_27 -> V_60 += V_56 ;
if ( ! V_50 &&
V_27 -> V_61 <= V_27 -> V_60 ) {
V_55 += V_56 ;
break;
}
V_55 += V_56 - 1 ;
V_53 += V_56 - 1 ;
continue;
}
V_59:
if ( V_50 )
break;
else
continue;
}
F_55 ( * V_14 , V_55 ,
V_51 , V_52 ) ;
* V_14 = V_55 ;
if ( V_50 && V_55 < V_15 )
V_52 = 0 ;
if ( V_46 )
F_43 ( & V_27 -> V_16 -> V_42 , V_43 ) ;
if ( V_55 == V_15 )
F_37 ( V_27 , V_54 , V_52 , false ) ;
F_3 ( V_62 , V_51 ) ;
if ( V_52 )
F_3 ( V_63 , V_52 ) ;
return V_52 ;
}
unsigned long
F_56 ( struct V_26 * V_27 ,
unsigned long V_14 , unsigned long V_15 )
{
unsigned long V_56 , V_9 , V_64 ;
F_57 ( V_5 ) ;
V_9 = V_14 ;
V_64 = F_58 ( V_9 + 1 , V_33 ) ;
for (; V_9 < V_15 ; V_9 += V_56 ,
V_64 += V_33 ) {
unsigned long V_65 = V_9 ;
V_64 = F_59 ( V_64 , V_15 ) ;
if ( V_9 >= V_64 ) {
V_64 = F_58 ( V_9 + 1 , V_33 ) ;
V_64 = F_59 ( V_64 , V_15 ) ;
}
if ( ! F_17 ( V_9 , V_64 , V_27 -> V_16 ) )
break;
V_56 = F_51 ( V_27 , & V_65 ,
V_64 , & V_5 , true ) ;
if ( ! V_56 )
break;
}
F_10 ( & V_5 ) ;
if ( V_9 < V_15 ) {
F_5 ( & V_5 ) ;
return 0 ;
}
return V_9 ;
}
static void F_60 ( struct V_16 * V_16 , struct V_26 * V_27 )
{
struct V_6 * V_6 ;
unsigned int V_66 [ 2 ] = { 0 , } ;
if ( F_61 ( & V_27 -> V_67 ) )
return;
F_11 (page, &cc->migratepages, lru)
V_66 [ ! ! F_62 ( V_6 ) ] ++ ;
F_63 ( V_16 , V_68 , V_66 [ 0 ] ) ;
F_63 ( V_16 , V_69 , V_66 [ 1 ] ) ;
}
static bool F_64 ( struct V_16 * V_16 )
{
unsigned long V_70 , V_71 , V_56 ;
V_71 = F_65 ( V_16 , V_72 ) +
F_65 ( V_16 , V_73 ) ;
V_70 = F_65 ( V_16 , V_74 ) +
F_65 ( V_16 , V_75 ) ;
V_56 = F_65 ( V_16 , V_69 ) +
F_65 ( V_16 , V_68 ) ;
return V_56 > ( V_71 + V_70 ) / 2 ;
}
static unsigned long
F_66 ( struct V_26 * V_27 , unsigned long V_76 ,
unsigned long V_15 , T_3 V_77 )
{
struct V_16 * V_16 = V_27 -> V_16 ;
unsigned long V_51 = 0 , V_38 = 0 ;
struct V_4 * V_78 = & V_27 -> V_67 ;
struct V_79 * V_79 ;
unsigned long V_43 = 0 ;
bool V_46 = false ;
struct V_6 * V_6 = NULL , * V_54 = NULL ;
unsigned long V_14 = V_76 ;
while ( F_67 ( F_64 ( V_16 ) ) ) {
if ( V_27 -> V_40 == V_41 )
return 0 ;
F_68 ( V_80 , V_81 / 10 ) ;
if ( F_44 ( V_47 ) )
return 0 ;
}
if ( F_46 ( V_27 ) )
return 0 ;
for (; V_76 < V_15 ; V_76 ++ ) {
if ( ! ( V_76 % V_58 )
&& F_42 ( & V_16 -> V_82 , V_43 ,
& V_46 , V_27 ) )
break;
if ( ! F_52 ( V_76 ) )
continue;
V_51 ++ ;
V_6 = F_19 ( V_76 ) ;
if ( ! V_54 )
V_54 = V_6 ;
if ( F_48 ( V_6 ) ) {
unsigned long V_83 = F_49 ( V_6 ) ;
if ( V_83 > 0 && V_83 < V_84 )
V_76 += ( 1UL << V_83 ) - 1 ;
continue;
}
if ( ! F_69 ( V_6 ) ) {
if ( F_67 ( F_70 ( V_6 ) ) ) {
if ( F_71 ( V_6 ) ) {
goto V_85;
}
}
continue;
}
if ( F_72 ( V_6 ) ) {
if ( ! V_46 )
V_76 = F_58 ( V_76 + 1 ,
V_33 ) - 1 ;
else
V_76 += ( 1 << F_73 ( V_6 ) ) - 1 ;
continue;
}
if ( ! F_74 ( V_6 ) &&
F_75 ( V_6 ) > F_76 ( V_6 ) )
continue;
if ( ! V_46 ) {
V_46 = F_39 ( & V_16 -> V_82 ,
& V_43 , V_27 ) ;
if ( ! V_46 )
break;
if ( ! F_69 ( V_6 ) )
continue;
if ( F_72 ( V_6 ) ) {
V_76 += ( 1 << F_73 ( V_6 ) ) - 1 ;
continue;
}
}
V_79 = F_77 ( V_6 , V_16 ) ;
if ( F_78 ( V_6 , V_77 ) != 0 )
continue;
F_79 ( F_80 ( V_6 ) , V_6 ) ;
F_81 ( V_6 , V_79 , F_82 ( V_6 ) ) ;
V_85:
F_54 ( & V_6 -> V_10 , V_78 ) ;
V_27 -> V_61 ++ ;
V_38 ++ ;
if ( V_27 -> V_61 == V_86 ) {
++ V_76 ;
break;
}
}
if ( F_67 ( V_76 > V_15 ) )
V_76 = V_15 ;
if ( V_46 )
F_43 ( & V_16 -> V_82 , V_43 ) ;
if ( V_76 == V_15 )
F_37 ( V_27 , V_54 , V_38 , true ) ;
F_83 ( V_14 , V_76 ,
V_51 , V_38 ) ;
F_3 ( V_87 , V_51 ) ;
if ( V_38 )
F_3 ( V_63 , V_38 ) ;
return V_76 ;
}
unsigned long
F_84 ( struct V_26 * V_27 , unsigned long V_14 ,
unsigned long V_15 )
{
unsigned long V_9 , V_64 ;
V_9 = V_14 ;
V_64 = F_58 ( V_9 + 1 , V_33 ) ;
for (; V_9 < V_15 ; V_9 = V_64 ,
V_64 += V_33 ) {
V_64 = F_59 ( V_64 , V_15 ) ;
if ( ! F_17 ( V_9 , V_64 , V_27 -> V_16 ) )
continue;
V_9 = F_66 ( V_27 , V_9 , V_64 ,
V_88 ) ;
if ( ! V_9 ) {
F_85 ( & V_27 -> V_67 ) ;
V_27 -> V_61 = 0 ;
break;
}
if ( V_27 -> V_61 == V_86 )
break;
}
F_60 ( V_27 -> V_16 , V_27 ) ;
return V_9 ;
}
static void F_86 ( struct V_26 * V_27 )
{
struct V_16 * V_16 = V_27 -> V_16 ;
struct V_6 * V_6 ;
unsigned long V_89 ;
unsigned long V_65 ;
unsigned long V_64 ;
unsigned long V_76 ;
struct V_4 * V_5 = & V_27 -> V_90 ;
V_65 = V_27 -> V_91 ;
V_89 = V_27 -> V_91 & ~ ( V_33 - 1 ) ;
V_64 = F_59 ( V_89 + V_33 ,
F_32 ( V_16 ) ) ;
V_76 = F_58 ( V_27 -> V_92 + 1 , V_33 ) ;
for (; V_89 >= V_76 &&
V_27 -> V_61 > V_27 -> V_60 ;
V_64 = V_89 ,
V_89 -= V_33 ,
V_65 = V_89 ) {
if ( ! ( V_89 % ( V_58 * V_33 ) )
&& F_46 ( V_27 ) )
break;
V_6 = F_17 ( V_89 , V_64 ,
V_16 ) ;
if ( ! V_6 )
continue;
if ( ! F_47 ( V_6 ) )
continue;
if ( ! F_29 ( V_27 , V_6 ) )
continue;
F_51 ( V_27 , & V_65 ,
V_64 , V_5 , false ) ;
V_27 -> V_91 = ( V_65 < V_64 ) ?
V_65 :
V_89 - V_33 ;
if ( V_27 -> V_44 )
break;
}
F_10 ( V_5 ) ;
if ( V_89 < V_76 )
V_27 -> V_91 = V_27 -> V_92 ;
}
static struct V_6 * F_87 ( struct V_6 * V_93 ,
unsigned long V_94 ,
int * * V_95 )
{
struct V_26 * V_27 = (struct V_26 * ) V_94 ;
struct V_6 * V_96 ;
if ( F_61 ( & V_27 -> V_90 ) ) {
if ( ! V_27 -> V_44 )
F_86 ( V_27 ) ;
if ( F_61 ( & V_27 -> V_90 ) )
return NULL ;
}
V_96 = F_88 ( V_27 -> V_90 . V_7 , struct V_6 , V_10 ) ;
F_8 ( & V_96 -> V_10 ) ;
V_27 -> V_60 -- ;
return V_96 ;
}
static void F_89 ( struct V_6 * V_6 , unsigned long V_94 )
{
struct V_26 * V_27 = (struct V_26 * ) V_94 ;
F_54 ( & V_6 -> V_10 , & V_27 -> V_90 ) ;
V_27 -> V_60 ++ ;
}
static T_4 F_90 ( struct V_16 * V_16 ,
struct V_26 * V_27 )
{
unsigned long V_76 , V_15 ;
struct V_6 * V_6 ;
const T_3 V_77 =
( V_27 -> V_40 == V_41 ? V_97 : 0 ) ;
V_76 = V_27 -> V_92 ;
V_15 = F_58 ( V_76 + 1 , V_33 ) ;
for (; V_15 <= V_27 -> V_91 ;
V_76 = V_15 , V_15 += V_33 ) {
if ( ! ( V_76 % ( V_58 * V_33 ) )
&& F_46 ( V_27 ) )
break;
V_6 = F_17 ( V_76 , V_15 , V_16 ) ;
if ( ! V_6 )
continue;
if ( ! F_29 ( V_27 , V_6 ) )
continue;
if ( V_27 -> V_40 == V_41 &&
! F_15 ( F_50 ( V_6 ) ) )
continue;
V_76 = F_66 ( V_27 , V_76 , V_15 ,
V_77 ) ;
if ( ! V_76 || V_27 -> V_44 ) {
F_60 ( V_16 , V_27 ) ;
return V_98 ;
}
break;
}
F_60 ( V_16 , V_27 ) ;
V_27 -> V_92 = ( V_15 <= V_27 -> V_91 ) ? V_76 : V_27 -> V_91 ;
return V_27 -> V_61 ? V_99 : V_100 ;
}
static int F_91 ( struct V_16 * V_16 , struct V_26 * V_27 ,
const int V_12 )
{
unsigned int V_19 ;
unsigned long V_101 ;
if ( V_27 -> V_44 || F_44 ( V_47 ) )
return V_102 ;
if ( V_27 -> V_91 <= V_27 -> V_92 ) {
V_16 -> V_30 [ 0 ] = V_16 -> V_29 ;
V_16 -> V_30 [ 1 ] = V_16 -> V_29 ;
V_16 -> V_31 = F_32 ( V_16 ) ;
if ( ! F_92 () )
V_16 -> V_32 = true ;
return V_103 ;
}
if ( V_27 -> V_19 == - 1 )
return V_104 ;
V_101 = F_93 ( V_16 ) ;
if ( ! F_94 ( V_16 , V_27 -> V_19 , V_101 , V_27 -> V_105 ,
V_27 -> V_106 ) )
return V_104 ;
for ( V_19 = V_27 -> V_19 ; V_19 < V_84 ; V_19 ++ ) {
struct V_107 * V_108 = & V_16 -> V_107 [ V_19 ] ;
if ( ! F_61 ( & V_108 -> V_109 [ V_12 ] ) )
return V_102 ;
if ( V_19 >= V_49 && V_108 -> V_110 )
return V_102 ;
}
return V_111 ;
}
static int F_95 ( struct V_16 * V_16 , struct V_26 * V_27 ,
const int V_12 )
{
int V_112 ;
V_112 = F_91 ( V_16 , V_27 , V_12 ) ;
F_96 ( V_16 , V_27 -> V_19 , V_112 ) ;
if ( V_112 == V_111 )
V_112 = V_104 ;
return V_112 ;
}
static unsigned long F_97 ( struct V_16 * V_16 , int V_19 ,
int V_106 , int V_105 )
{
int V_113 ;
unsigned long V_101 ;
if ( V_19 == - 1 )
return V_104 ;
V_101 = F_93 ( V_16 ) ;
if ( F_94 ( V_16 , V_19 , V_101 , V_105 ,
V_106 ) )
return V_102 ;
V_101 += ( 2UL << V_19 ) ;
if ( ! F_94 ( V_16 , 0 , V_101 , V_105 , V_106 ) )
return V_114 ;
V_113 = F_98 ( V_16 , V_19 ) ;
if ( V_113 >= 0 && V_113 <= V_115 )
return V_116 ;
return V_104 ;
}
unsigned long F_99 ( struct V_16 * V_16 , int V_19 ,
int V_106 , int V_105 )
{
unsigned long V_112 ;
V_112 = F_97 ( V_16 , V_19 , V_106 , V_105 ) ;
F_100 ( V_16 , V_19 , V_112 ) ;
if ( V_112 == V_116 )
V_112 = V_114 ;
return V_112 ;
}
static int F_101 ( struct V_16 * V_16 , struct V_26 * V_27 )
{
int V_112 ;
unsigned long V_14 = V_16 -> V_29 ;
unsigned long V_15 = F_32 ( V_16 ) ;
const int V_12 = F_102 ( V_27 -> V_117 ) ;
const bool V_118 = V_27 -> V_40 != V_41 ;
unsigned long V_119 = 0 ;
V_112 = F_99 ( V_16 , V_27 -> V_19 , V_27 -> V_106 ,
V_27 -> V_105 ) ;
switch ( V_112 ) {
case V_102 :
case V_114 :
return V_112 ;
case V_104 :
;
}
if ( F_28 ( V_16 , V_27 -> V_19 ) && ! F_92 () )
F_31 ( V_16 ) ;
V_27 -> V_92 = V_16 -> V_30 [ V_118 ] ;
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
F_103 ( V_14 , V_27 -> V_92 ,
V_27 -> V_91 , V_15 , V_118 ) ;
F_104 () ;
while ( ( V_112 = F_95 ( V_16 , V_27 , V_12 ) ) ==
V_104 ) {
int V_120 ;
unsigned long V_65 = V_27 -> V_92 ;
switch ( F_90 ( V_16 , V_27 ) ) {
case V_98 :
V_112 = V_102 ;
F_85 ( & V_27 -> V_67 ) ;
V_27 -> V_61 = 0 ;
goto V_121;
case V_100 :
goto V_122;
case V_99 :
;
}
V_120 = F_105 ( & V_27 -> V_67 , F_87 ,
F_89 , ( unsigned long ) V_27 , V_27 -> V_40 ,
V_123 ) ;
F_106 ( V_27 -> V_61 , V_120 ,
& V_27 -> V_67 ) ;
V_27 -> V_61 = 0 ;
if ( V_120 ) {
F_85 ( & V_27 -> V_67 ) ;
if ( V_120 == - V_124 && V_27 -> V_91 > V_27 -> V_92 ) {
V_112 = V_102 ;
goto V_121;
}
}
if ( ! V_119 )
V_119 = V_65 ;
V_122:
if ( V_27 -> V_19 > 0 && V_119 ) {
int V_125 ;
unsigned long V_126 =
V_27 -> V_92 & ~ ( ( 1UL << V_27 -> V_19 ) - 1 ) ;
if ( V_119 < V_126 ) {
V_125 = F_107 () ;
F_108 ( V_125 ) ;
F_109 ( V_16 ) ;
F_110 () ;
V_119 = 0 ;
}
}
}
V_121:
if ( V_27 -> V_60 > 0 ) {
unsigned long V_91 = F_5 ( & V_27 -> V_90 ) ;
V_27 -> V_60 = 0 ;
F_111 ( V_91 == 0 ) ;
V_91 &= ~ ( V_33 - 1 ) ;
if ( V_91 > V_16 -> V_31 )
V_16 -> V_31 = V_91 ;
}
F_112 ( V_14 , V_27 -> V_92 ,
V_27 -> V_91 , V_15 , V_118 , V_112 ) ;
return V_112 ;
}
static unsigned long F_113 ( struct V_16 * V_16 , int V_19 ,
T_5 V_117 , enum V_127 V_40 , int * V_44 ,
int V_106 , int V_105 )
{
unsigned long V_112 ;
struct V_26 V_27 = {
. V_60 = 0 ,
. V_61 = 0 ,
. V_19 = V_19 ,
. V_117 = V_117 ,
. V_16 = V_16 ,
. V_40 = V_40 ,
. V_106 = V_106 ,
. V_105 = V_105 ,
} ;
F_114 ( & V_27 . V_90 ) ;
F_114 ( & V_27 . V_67 ) ;
V_112 = F_101 ( V_16 , & V_27 ) ;
F_111 ( ! F_61 ( & V_27 . V_90 ) ) ;
F_111 ( ! F_61 ( & V_27 . V_67 ) ) ;
* V_44 = V_27 . V_44 ;
return V_112 ;
}
unsigned long F_115 ( T_5 V_117 , unsigned int V_19 ,
int V_106 , const struct V_128 * V_129 ,
enum V_127 V_40 , int * V_44 )
{
int V_130 = V_117 & V_131 ;
int V_132 = V_117 & V_133 ;
struct V_134 * V_135 ;
struct V_16 * V_16 ;
int V_136 = V_137 ;
int V_138 = V_45 ;
* V_44 = V_139 ;
if ( ! V_19 || ! V_130 || ! V_132 )
return V_114 ;
F_116 ( V_19 , V_117 , V_40 ) ;
F_117 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
int V_140 ;
int V_141 ;
if ( F_24 ( V_16 , V_19 ) )
continue;
V_140 = F_113 ( V_16 , V_19 , V_117 , V_40 ,
& V_141 , V_106 ,
V_129 -> V_105 ) ;
V_136 = F_118 ( V_140 , V_136 ) ;
V_138 &= V_141 ;
if ( F_94 ( V_16 , V_19 , F_93 ( V_16 ) ,
V_129 -> V_105 , V_106 ) ) {
F_26 ( V_16 , V_19 , false ) ;
if ( V_141 == V_48 )
* V_44 = V_48 ;
goto V_142;
}
if ( V_40 != V_41 && V_140 == V_103 ) {
F_22 ( V_16 , V_19 ) ;
}
if ( ( V_141 == V_48 )
|| F_44 ( V_47 ) ) {
* V_44 = V_48 ;
goto V_142;
}
continue;
V_142:
V_138 = 0 ;
break;
}
if ( V_136 > V_114 && V_138 )
* V_44 = V_45 ;
return V_136 ;
}
static void F_119 ( T_1 * V_34 , struct V_26 * V_27 )
{
int V_35 ;
struct V_16 * V_16 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_16 = & V_34 -> V_37 [ V_35 ] ;
if ( ! F_36 ( V_16 ) )
continue;
V_27 -> V_60 = 0 ;
V_27 -> V_61 = 0 ;
V_27 -> V_16 = V_16 ;
F_114 ( & V_27 -> V_90 ) ;
F_114 ( & V_27 -> V_67 ) ;
if ( V_27 -> V_19 == - 1 || ! F_24 ( V_16 , V_27 -> V_19 ) )
F_101 ( V_16 , V_27 ) ;
if ( V_27 -> V_19 > 0 ) {
if ( F_94 ( V_16 , V_27 -> V_19 ,
F_93 ( V_16 ) , 0 , 0 ) )
F_26 ( V_16 , V_27 -> V_19 , false ) ;
}
F_111 ( ! F_61 ( & V_27 -> V_90 ) ) ;
F_111 ( ! F_61 ( & V_27 -> V_67 ) ) ;
}
}
void F_120 ( T_1 * V_34 , int V_19 )
{
struct V_26 V_27 = {
. V_19 = V_19 ,
. V_40 = V_41 ,
} ;
if ( ! V_19 )
return;
F_119 ( V_34 , & V_27 ) ;
}
static void F_121 ( int V_143 )
{
struct V_26 V_27 = {
. V_19 = - 1 ,
. V_40 = V_144 ,
. V_28 = true ,
} ;
F_119 ( F_122 ( V_143 ) , & V_27 ) ;
}
static void F_123 ( void )
{
int V_143 ;
F_124 () ;
F_125 (nid)
F_121 ( V_143 ) ;
}
int F_126 ( struct V_145 * V_146 , int V_147 ,
void T_6 * V_148 , T_7 * V_149 , T_8 * V_150 )
{
if ( V_147 )
F_123 () ;
return 0 ;
}
int F_127 ( struct V_145 * V_146 , int V_147 ,
void T_6 * V_148 , T_7 * V_149 , T_8 * V_150 )
{
F_128 ( V_146 , V_147 , V_148 , V_149 , V_150 ) ;
return 0 ;
}
static T_9 F_129 ( struct V_151 * V_152 ,
struct V_153 * V_154 ,
const char * V_155 , T_7 V_66 )
{
int V_143 = V_152 -> V_156 ;
if ( V_143 >= 0 && V_143 < V_157 && F_130 ( V_143 ) ) {
F_124 () ;
F_121 ( V_143 ) ;
}
return V_66 ;
}
int F_131 ( struct V_158 * V_158 )
{
return F_132 ( & V_158 -> V_152 , & V_159 ) ;
}
void F_133 ( struct V_158 * V_158 )
{
return F_134 ( & V_158 -> V_152 , & V_159 ) ;
}
