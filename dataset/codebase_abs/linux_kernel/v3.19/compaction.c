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
}
}
static inline bool F_14 ( int V_12 )
{
return F_15 ( V_12 ) || V_12 == V_13 ;
}
static struct V_6 * F_16 ( unsigned long V_14 ,
unsigned long V_15 , struct V_16 * V_16 )
{
struct V_6 * V_17 ;
struct V_6 * V_18 ;
V_15 -- ;
if ( ! F_17 ( V_14 ) || ! F_17 ( V_15 ) )
return NULL ;
V_17 = F_18 ( V_14 ) ;
if ( F_19 ( V_17 ) != V_16 )
return NULL ;
V_18 = F_18 ( V_15 ) ;
if ( F_20 ( V_17 ) != F_20 ( V_18 ) )
return NULL ;
return V_17 ;
}
static inline bool F_21 ( struct V_19 * V_20 ,
struct V_6 * V_6 )
{
if ( V_20 -> V_21 )
return true ;
return ! F_22 ( V_6 ) ;
}
static void F_23 ( struct V_16 * V_16 )
{
unsigned long V_14 = V_16 -> V_22 ;
unsigned long V_15 = F_24 ( V_16 ) ;
unsigned long V_9 ;
V_16 -> V_23 [ 0 ] = V_14 ;
V_16 -> V_23 [ 1 ] = V_14 ;
V_16 -> V_24 = V_15 ;
V_16 -> V_25 = false ;
for ( V_9 = V_14 ; V_9 < V_15 ; V_9 += V_26 ) {
struct V_6 * V_6 ;
F_25 () ;
if ( ! F_17 ( V_9 ) )
continue;
V_6 = F_18 ( V_9 ) ;
if ( V_16 != F_19 ( V_6 ) )
continue;
F_26 ( V_6 ) ;
}
}
void F_27 ( T_1 * V_27 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
struct V_16 * V_16 = & V_27 -> V_30 [ V_28 ] ;
if ( ! F_28 ( V_16 ) )
continue;
if ( V_16 -> V_25 )
F_23 ( V_16 ) ;
}
}
static void F_29 ( struct V_19 * V_20 ,
struct V_6 * V_6 , unsigned long V_31 ,
bool V_32 )
{
struct V_16 * V_16 = V_20 -> V_16 ;
unsigned long V_9 ;
if ( V_20 -> V_21 )
return;
if ( ! V_6 )
return;
if ( V_31 )
return;
F_30 ( V_6 ) ;
V_9 = F_7 ( V_6 ) ;
if ( V_32 ) {
if ( V_9 > V_16 -> V_23 [ 0 ] )
V_16 -> V_23 [ 0 ] = V_9 ;
if ( V_20 -> V_33 != V_34 &&
V_9 > V_16 -> V_23 [ 1 ] )
V_16 -> V_23 [ 1 ] = V_9 ;
} else {
if ( V_9 < V_16 -> V_24 )
V_16 -> V_24 = V_9 ;
}
}
static inline bool F_21 ( struct V_19 * V_20 ,
struct V_6 * V_6 )
{
return true ;
}
static void F_29 ( struct V_19 * V_20 ,
struct V_6 * V_6 , unsigned long V_31 ,
bool V_32 )
{
}
static bool F_31 ( T_2 * V_35 , unsigned long * V_36 ,
struct V_19 * V_20 )
{
if ( V_20 -> V_33 == V_34 ) {
if ( ! F_32 ( V_35 , * V_36 ) ) {
V_20 -> V_37 = V_38 ;
return false ;
}
} else {
F_33 ( V_35 , * V_36 ) ;
}
return true ;
}
static bool F_34 ( T_2 * V_35 ,
unsigned long V_36 , bool * V_39 , struct V_19 * V_20 )
{
if ( * V_39 ) {
F_35 ( V_35 , V_36 ) ;
* V_39 = false ;
}
if ( F_36 ( V_40 ) ) {
V_20 -> V_37 = V_41 ;
return true ;
}
if ( F_37 () ) {
if ( V_20 -> V_33 == V_34 ) {
V_20 -> V_37 = V_41 ;
return true ;
}
F_25 () ;
}
return false ;
}
static inline bool F_38 ( struct V_19 * V_20 )
{
if ( F_37 () ) {
if ( V_20 -> V_33 == V_34 ) {
V_20 -> V_37 = V_41 ;
return true ;
}
F_25 () ;
}
return false ;
}
static bool F_39 ( struct V_6 * V_6 )
{
if ( F_40 ( V_6 ) ) {
if ( F_41 ( V_6 ) >= V_42 )
return false ;
}
if ( F_14 ( F_42 ( V_6 ) ) )
return true ;
return false ;
}
static unsigned long F_43 ( struct V_19 * V_20 ,
unsigned long * V_14 ,
unsigned long V_15 ,
struct V_4 * V_5 ,
bool V_43 )
{
int V_44 = 0 , V_45 = 0 ;
struct V_6 * V_46 , * V_47 = NULL ;
unsigned long V_36 = 0 ;
bool V_39 = false ;
unsigned long V_48 = * V_14 ;
V_46 = F_18 ( V_48 ) ;
for (; V_48 < V_15 ; V_48 ++ , V_46 ++ ) {
int V_49 , V_50 ;
struct V_6 * V_6 = V_46 ;
if ( ! ( V_48 % V_51 )
&& F_34 ( & V_20 -> V_16 -> V_35 , V_36 ,
& V_39 , V_20 ) )
break;
V_44 ++ ;
if ( ! F_44 ( V_48 ) )
goto V_52;
if ( ! V_47 )
V_47 = V_6 ;
if ( ! F_40 ( V_6 ) )
goto V_52;
if ( ! V_39 ) {
V_39 = F_31 ( & V_20 -> V_16 -> V_35 ,
& V_36 , V_20 ) ;
if ( ! V_39 )
break;
if ( ! F_40 ( V_6 ) )
goto V_52;
}
V_49 = F_45 ( V_6 ) ;
V_45 += V_49 ;
for ( V_50 = 0 ; V_50 < V_49 ; V_50 ++ ) {
F_46 ( & V_6 -> V_10 , V_5 ) ;
V_6 ++ ;
}
if ( V_49 ) {
V_48 += V_49 - 1 ;
V_46 += V_49 - 1 ;
continue;
}
V_52:
if ( V_43 )
break;
else
continue;
}
* V_14 = V_48 ;
F_47 ( V_44 , V_45 ) ;
if ( V_43 && V_48 < V_15 )
V_45 = 0 ;
if ( V_39 )
F_35 ( & V_20 -> V_16 -> V_35 , V_36 ) ;
if ( V_48 == V_15 )
F_29 ( V_20 , V_47 , V_45 , false ) ;
F_3 ( V_53 , V_44 ) ;
if ( V_45 )
F_3 ( V_54 , V_45 ) ;
return V_45 ;
}
unsigned long
F_48 ( struct V_19 * V_20 ,
unsigned long V_14 , unsigned long V_15 )
{
unsigned long V_49 , V_9 , V_55 ;
F_49 ( V_5 ) ;
V_9 = V_14 ;
V_55 = F_50 ( V_9 + 1 , V_26 ) ;
for (; V_9 < V_15 ; V_9 += V_49 ,
V_55 += V_26 ) {
unsigned long V_56 = V_9 ;
V_55 = F_51 ( V_55 , V_15 ) ;
if ( V_9 >= V_55 ) {
V_55 = F_50 ( V_9 + 1 , V_26 ) ;
V_55 = F_51 ( V_55 , V_15 ) ;
}
if ( ! F_16 ( V_9 , V_55 , V_20 -> V_16 ) )
break;
V_49 = F_43 ( V_20 , & V_56 ,
V_55 , & V_5 , true ) ;
if ( ! V_49 )
break;
}
F_10 ( & V_5 ) ;
if ( V_9 < V_15 ) {
F_5 ( & V_5 ) ;
return 0 ;
}
return V_9 ;
}
static void F_52 ( struct V_16 * V_16 , struct V_19 * V_20 )
{
struct V_6 * V_6 ;
unsigned int V_57 [ 2 ] = { 0 , } ;
if ( F_53 ( & V_20 -> V_58 ) )
return;
F_11 (page, &cc->migratepages, lru)
V_57 [ ! ! F_54 ( V_6 ) ] ++ ;
F_55 ( V_16 , V_59 , V_57 [ 0 ] ) ;
F_55 ( V_16 , V_60 , V_57 [ 1 ] ) ;
}
static bool F_56 ( struct V_16 * V_16 )
{
unsigned long V_61 , V_62 , V_49 ;
V_62 = F_57 ( V_16 , V_63 ) +
F_57 ( V_16 , V_64 ) ;
V_61 = F_57 ( V_16 , V_65 ) +
F_57 ( V_16 , V_66 ) ;
V_49 = F_57 ( V_16 , V_60 ) +
F_57 ( V_16 , V_59 ) ;
return V_49 > ( V_62 + V_61 ) / 2 ;
}
static unsigned long
F_58 ( struct V_19 * V_20 , unsigned long V_67 ,
unsigned long V_15 , T_3 V_68 )
{
struct V_16 * V_16 = V_20 -> V_16 ;
unsigned long V_44 = 0 , V_31 = 0 ;
struct V_4 * V_69 = & V_20 -> V_58 ;
struct V_70 * V_70 ;
unsigned long V_36 = 0 ;
bool V_39 = false ;
struct V_6 * V_6 = NULL , * V_47 = NULL ;
while ( F_59 ( F_56 ( V_16 ) ) ) {
if ( V_20 -> V_33 == V_34 )
return 0 ;
F_60 ( V_71 , V_72 / 10 ) ;
if ( F_36 ( V_40 ) )
return 0 ;
}
if ( F_38 ( V_20 ) )
return 0 ;
for (; V_67 < V_15 ; V_67 ++ ) {
if ( ! ( V_67 % V_51 )
&& F_34 ( & V_16 -> V_73 , V_36 ,
& V_39 , V_20 ) )
break;
if ( ! F_44 ( V_67 ) )
continue;
V_44 ++ ;
V_6 = F_18 ( V_67 ) ;
if ( ! V_47 )
V_47 = V_6 ;
if ( F_40 ( V_6 ) ) {
unsigned long V_74 = F_41 ( V_6 ) ;
if ( V_74 > 0 && V_74 < V_75 )
V_67 += ( 1UL << V_74 ) - 1 ;
continue;
}
if ( ! F_61 ( V_6 ) ) {
if ( F_59 ( F_62 ( V_6 ) ) ) {
if ( F_63 ( V_6 ) ) {
goto V_76;
}
}
continue;
}
if ( F_64 ( V_6 ) ) {
if ( ! V_39 )
V_67 = F_50 ( V_67 + 1 ,
V_26 ) - 1 ;
else
V_67 += ( 1 << F_65 ( V_6 ) ) - 1 ;
continue;
}
if ( ! F_66 ( V_6 ) &&
F_67 ( V_6 ) > F_68 ( V_6 ) )
continue;
if ( ! V_39 ) {
V_39 = F_31 ( & V_16 -> V_73 ,
& V_36 , V_20 ) ;
if ( ! V_39 )
break;
if ( ! F_61 ( V_6 ) )
continue;
if ( F_64 ( V_6 ) ) {
V_67 += ( 1 << F_65 ( V_6 ) ) - 1 ;
continue;
}
}
V_70 = F_69 ( V_6 , V_16 ) ;
if ( F_70 ( V_6 , V_68 ) != 0 )
continue;
F_71 ( F_72 ( V_6 ) , V_6 ) ;
F_73 ( V_6 , V_70 , F_74 ( V_6 ) ) ;
V_76:
F_46 ( & V_6 -> V_10 , V_69 ) ;
V_20 -> V_77 ++ ;
V_31 ++ ;
if ( V_20 -> V_77 == V_78 ) {
++ V_67 ;
break;
}
}
if ( F_59 ( V_67 > V_15 ) )
V_67 = V_15 ;
if ( V_39 )
F_35 ( & V_16 -> V_73 , V_36 ) ;
if ( V_67 == V_15 )
F_29 ( V_20 , V_47 , V_31 , true ) ;
F_75 ( V_44 , V_31 ) ;
F_3 ( V_79 , V_44 ) ;
if ( V_31 )
F_3 ( V_54 , V_31 ) ;
return V_67 ;
}
unsigned long
F_76 ( struct V_19 * V_20 , unsigned long V_14 ,
unsigned long V_15 )
{
unsigned long V_9 , V_55 ;
V_9 = V_14 ;
V_55 = F_50 ( V_9 + 1 , V_26 ) ;
for (; V_9 < V_15 ; V_9 = V_55 ,
V_55 += V_26 ) {
V_55 = F_51 ( V_55 , V_15 ) ;
if ( ! F_16 ( V_9 , V_55 , V_20 -> V_16 ) )
continue;
V_9 = F_58 ( V_20 , V_9 , V_55 ,
V_80 ) ;
if ( ! V_9 ) {
F_77 ( & V_20 -> V_58 ) ;
V_20 -> V_77 = 0 ;
break;
}
if ( V_20 -> V_77 == V_78 )
break;
}
F_52 ( V_20 -> V_16 , V_20 ) ;
return V_9 ;
}
static void F_78 ( struct V_19 * V_20 )
{
struct V_16 * V_16 = V_20 -> V_16 ;
struct V_6 * V_6 ;
unsigned long V_81 ;
unsigned long V_56 ;
unsigned long V_55 ;
unsigned long V_67 ;
int V_82 = V_20 -> V_82 ;
struct V_4 * V_5 = & V_20 -> V_83 ;
V_56 = V_20 -> V_84 ;
V_81 = V_20 -> V_84 & ~ ( V_26 - 1 ) ;
V_55 = F_51 ( V_81 + V_26 ,
F_24 ( V_16 ) ) ;
V_67 = F_50 ( V_20 -> V_85 + 1 , V_26 ) ;
for (; V_81 >= V_67 && V_20 -> V_77 > V_82 ;
V_55 = V_81 ,
V_81 -= V_26 ,
V_56 = V_81 ) {
unsigned long V_49 ;
if ( ! ( V_81 % ( V_51 * V_26 ) )
&& F_38 ( V_20 ) )
break;
V_6 = F_16 ( V_81 , V_55 ,
V_16 ) ;
if ( ! V_6 )
continue;
if ( ! F_39 ( V_6 ) )
continue;
if ( ! F_21 ( V_20 , V_6 ) )
continue;
V_49 = F_43 ( V_20 , & V_56 ,
V_55 , V_5 , false ) ;
V_82 += V_49 ;
V_20 -> V_84 = ( V_56 < V_55 ) ?
V_56 :
V_81 - V_26 ;
if ( V_20 -> V_37 )
break;
}
F_10 ( V_5 ) ;
if ( V_81 < V_67 )
V_20 -> V_84 = V_20 -> V_85 ;
V_20 -> V_82 = V_82 ;
}
static struct V_6 * F_79 ( struct V_6 * V_86 ,
unsigned long V_87 ,
int * * V_88 )
{
struct V_19 * V_20 = (struct V_19 * ) V_87 ;
struct V_6 * V_89 ;
if ( F_53 ( & V_20 -> V_83 ) ) {
if ( ! V_20 -> V_37 )
F_78 ( V_20 ) ;
if ( F_53 ( & V_20 -> V_83 ) )
return NULL ;
}
V_89 = F_80 ( V_20 -> V_83 . V_7 , struct V_6 , V_10 ) ;
F_8 ( & V_89 -> V_10 ) ;
V_20 -> V_82 -- ;
return V_89 ;
}
static void F_81 ( struct V_6 * V_6 , unsigned long V_87 )
{
struct V_19 * V_20 = (struct V_19 * ) V_87 ;
F_46 ( & V_6 -> V_10 , & V_20 -> V_83 ) ;
V_20 -> V_82 ++ ;
}
static T_4 F_82 ( struct V_16 * V_16 ,
struct V_19 * V_20 )
{
unsigned long V_67 , V_15 ;
struct V_6 * V_6 ;
const T_3 V_68 =
( V_20 -> V_33 == V_34 ? V_90 : 0 ) ;
V_67 = V_20 -> V_85 ;
V_15 = F_50 ( V_67 + 1 , V_26 ) ;
for (; V_15 <= V_20 -> V_84 ;
V_67 = V_15 , V_15 += V_26 ) {
if ( ! ( V_67 % ( V_51 * V_26 ) )
&& F_38 ( V_20 ) )
break;
V_6 = F_16 ( V_67 , V_15 , V_16 ) ;
if ( ! V_6 )
continue;
if ( ! F_21 ( V_20 , V_6 ) )
continue;
if ( V_20 -> V_33 == V_34 &&
! F_14 ( F_42 ( V_6 ) ) )
continue;
V_67 = F_58 ( V_20 , V_67 , V_15 ,
V_68 ) ;
if ( ! V_67 || V_20 -> V_37 )
return V_91 ;
break;
}
F_52 ( V_16 , V_20 ) ;
V_20 -> V_85 = ( V_15 <= V_20 -> V_84 ) ? V_67 : V_20 -> V_84 ;
return V_20 -> V_77 ? V_92 : V_93 ;
}
static int F_83 ( struct V_16 * V_16 , struct V_19 * V_20 ,
const int V_12 )
{
unsigned int V_94 ;
unsigned long V_95 ;
if ( V_20 -> V_37 || F_36 ( V_40 ) )
return V_96 ;
if ( V_20 -> V_84 <= V_20 -> V_85 ) {
V_16 -> V_23 [ 0 ] = V_16 -> V_22 ;
V_16 -> V_23 [ 1 ] = V_16 -> V_22 ;
V_16 -> V_24 = F_24 ( V_16 ) ;
if ( ! F_84 () )
V_16 -> V_25 = true ;
return V_97 ;
}
if ( V_20 -> V_94 == - 1 )
return V_98 ;
V_95 = F_85 ( V_16 ) ;
if ( ! F_86 ( V_16 , V_20 -> V_94 , V_95 , V_20 -> V_99 ,
V_20 -> V_100 ) )
return V_98 ;
for ( V_94 = V_20 -> V_94 ; V_94 < V_75 ; V_94 ++ ) {
struct V_101 * V_102 = & V_16 -> V_101 [ V_94 ] ;
if ( ! F_53 ( & V_102 -> V_103 [ V_12 ] ) )
return V_96 ;
if ( V_20 -> V_94 >= V_42 && V_102 -> V_104 )
return V_96 ;
}
return V_98 ;
}
unsigned long F_87 ( struct V_16 * V_16 , int V_94 ,
int V_100 , int V_99 )
{
int V_105 ;
unsigned long V_95 ;
if ( V_94 == - 1 )
return V_98 ;
V_95 = F_85 ( V_16 ) ;
if ( F_86 ( V_16 , V_94 , V_95 , V_99 ,
V_100 ) )
return V_96 ;
V_95 += ( 2UL << V_94 ) ;
if ( ! F_86 ( V_16 , 0 , V_95 , V_99 , V_100 ) )
return V_106 ;
V_105 = F_88 ( V_16 , V_94 ) ;
if ( V_105 >= 0 && V_105 <= V_107 )
return V_106 ;
return V_98 ;
}
static int F_89 ( struct V_16 * V_16 , struct V_19 * V_20 )
{
int V_108 ;
unsigned long V_14 = V_16 -> V_22 ;
unsigned long V_15 = F_24 ( V_16 ) ;
const int V_12 = F_90 ( V_20 -> V_109 ) ;
const bool V_110 = V_20 -> V_33 != V_34 ;
unsigned long V_111 = 0 ;
V_108 = F_87 ( V_16 , V_20 -> V_94 , V_20 -> V_100 ,
V_20 -> V_99 ) ;
switch ( V_108 ) {
case V_96 :
case V_106 :
return V_108 ;
case V_98 :
;
}
if ( F_91 ( V_16 , V_20 -> V_94 ) && ! F_84 () )
F_23 ( V_16 ) ;
V_20 -> V_85 = V_16 -> V_23 [ V_110 ] ;
V_20 -> V_84 = V_16 -> V_24 ;
if ( V_20 -> V_84 < V_14 || V_20 -> V_84 > V_15 ) {
V_20 -> V_84 = V_15 & ~ ( V_26 - 1 ) ;
V_16 -> V_24 = V_20 -> V_84 ;
}
if ( V_20 -> V_85 < V_14 || V_20 -> V_85 > V_15 ) {
V_20 -> V_85 = V_14 ;
V_16 -> V_23 [ 0 ] = V_20 -> V_85 ;
V_16 -> V_23 [ 1 ] = V_20 -> V_85 ;
}
F_92 ( V_14 , V_20 -> V_85 , V_20 -> V_84 , V_15 ) ;
F_93 () ;
while ( ( V_108 = F_83 ( V_16 , V_20 , V_12 ) ) ==
V_98 ) {
int V_112 ;
unsigned long V_56 = V_20 -> V_85 ;
switch ( F_82 ( V_16 , V_20 ) ) {
case V_91 :
V_108 = V_96 ;
F_77 ( & V_20 -> V_58 ) ;
V_20 -> V_77 = 0 ;
goto V_113;
case V_93 :
goto V_114;
case V_92 :
;
}
V_112 = F_94 ( & V_20 -> V_58 , F_79 ,
F_81 , ( unsigned long ) V_20 , V_20 -> V_33 ,
V_115 ) ;
F_95 ( V_20 -> V_77 , V_112 ,
& V_20 -> V_58 ) ;
V_20 -> V_77 = 0 ;
if ( V_112 ) {
F_77 ( & V_20 -> V_58 ) ;
if ( V_112 == - V_116 && V_20 -> V_84 > V_20 -> V_85 ) {
V_108 = V_96 ;
goto V_113;
}
}
if ( ! V_111 )
V_111 = V_56 ;
V_114:
if ( V_20 -> V_94 > 0 && V_111 ) {
int V_117 ;
unsigned long V_118 =
V_20 -> V_85 & ~ ( ( 1UL << V_20 -> V_94 ) - 1 ) ;
if ( V_111 < V_118 ) {
V_117 = F_96 () ;
F_97 ( V_117 ) ;
F_98 ( V_16 ) ;
F_99 () ;
V_111 = 0 ;
}
}
}
V_113:
if ( V_20 -> V_82 > 0 ) {
unsigned long V_84 = F_5 ( & V_20 -> V_83 ) ;
V_20 -> V_82 = 0 ;
F_100 ( V_84 == 0 ) ;
V_84 &= ~ ( V_26 - 1 ) ;
if ( V_84 > V_16 -> V_24 )
V_16 -> V_24 = V_84 ;
}
F_101 ( V_108 ) ;
return V_108 ;
}
static unsigned long F_102 ( struct V_16 * V_16 , int V_94 ,
T_5 V_109 , enum V_119 V_33 , int * V_37 ,
int V_100 , int V_99 )
{
unsigned long V_108 ;
struct V_19 V_20 = {
. V_82 = 0 ,
. V_77 = 0 ,
. V_94 = V_94 ,
. V_109 = V_109 ,
. V_16 = V_16 ,
. V_33 = V_33 ,
. V_100 = V_100 ,
. V_99 = V_99 ,
} ;
F_103 ( & V_20 . V_83 ) ;
F_103 ( & V_20 . V_58 ) ;
V_108 = F_89 ( V_16 , & V_20 ) ;
F_100 ( ! F_53 ( & V_20 . V_83 ) ) ;
F_100 ( ! F_53 ( & V_20 . V_58 ) ) ;
* V_37 = V_20 . V_37 ;
return V_108 ;
}
unsigned long F_104 ( struct V_120 * V_120 ,
int V_94 , T_5 V_109 , T_6 * V_121 ,
enum V_119 V_33 , int * V_37 ,
int V_100 , int V_99 )
{
enum V_122 V_123 = F_105 ( V_109 ) ;
int V_124 = V_109 & V_125 ;
int V_126 = V_109 & V_127 ;
struct V_128 * V_129 ;
struct V_16 * V_16 ;
int V_130 = V_131 ;
int V_132 = V_38 ;
* V_37 = V_133 ;
if ( ! V_94 || ! V_124 || ! V_126 )
return V_106 ;
F_106 (zone, z, zonelist, high_zoneidx,
nodemask) {
int V_134 ;
int V_135 ;
if ( F_107 ( V_16 , V_94 ) )
continue;
V_134 = F_102 ( V_16 , V_94 , V_109 , V_33 ,
& V_135 , V_100 , V_99 ) ;
V_130 = F_108 ( V_134 , V_130 ) ;
V_132 &= V_135 ;
if ( F_86 ( V_16 , V_94 , F_85 ( V_16 ) ,
V_99 , V_100 ) ) {
F_109 ( V_16 , V_94 , false ) ;
if ( V_135 == V_41 )
* V_37 = V_41 ;
goto V_136;
}
if ( V_33 != V_34 && V_134 == V_97 ) {
F_110 ( V_16 , V_94 ) ;
}
if ( ( V_135 == V_41 )
|| F_36 ( V_40 ) ) {
* V_37 = V_41 ;
goto V_136;
}
continue;
V_136:
V_132 = 0 ;
break;
}
if ( V_130 > V_106 && V_132 )
* V_37 = V_38 ;
return V_130 ;
}
static void F_111 ( T_1 * V_27 , struct V_19 * V_20 )
{
int V_28 ;
struct V_16 * V_16 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
V_16 = & V_27 -> V_30 [ V_28 ] ;
if ( ! F_28 ( V_16 ) )
continue;
V_20 -> V_82 = 0 ;
V_20 -> V_77 = 0 ;
V_20 -> V_16 = V_16 ;
F_103 ( & V_20 -> V_83 ) ;
F_103 ( & V_20 -> V_58 ) ;
if ( V_20 -> V_94 == - 1 || ! F_107 ( V_16 , V_20 -> V_94 ) )
F_89 ( V_16 , V_20 ) ;
if ( V_20 -> V_94 > 0 ) {
if ( F_86 ( V_16 , V_20 -> V_94 ,
F_85 ( V_16 ) , 0 , 0 ) )
F_109 ( V_16 , V_20 -> V_94 , false ) ;
}
F_100 ( ! F_53 ( & V_20 -> V_83 ) ) ;
F_100 ( ! F_53 ( & V_20 -> V_58 ) ) ;
}
}
void F_112 ( T_1 * V_27 , int V_94 )
{
struct V_19 V_20 = {
. V_94 = V_94 ,
. V_33 = V_34 ,
} ;
if ( ! V_94 )
return;
F_111 ( V_27 , & V_20 ) ;
}
static void F_113 ( int V_137 )
{
struct V_19 V_20 = {
. V_94 = - 1 ,
. V_33 = V_138 ,
. V_21 = true ,
} ;
F_111 ( F_114 ( V_137 ) , & V_20 ) ;
}
static void F_115 ( void )
{
int V_137 ;
F_116 () ;
F_117 (nid)
F_113 ( V_137 ) ;
}
int F_118 ( struct V_139 * V_140 , int V_141 ,
void T_7 * V_142 , T_8 * V_143 , T_9 * V_144 )
{
if ( V_141 )
F_115 () ;
return 0 ;
}
int F_119 ( struct V_139 * V_140 , int V_141 ,
void T_7 * V_142 , T_8 * V_143 , T_9 * V_144 )
{
F_120 ( V_140 , V_141 , V_142 , V_143 , V_144 ) ;
return 0 ;
}
static T_10 F_121 ( struct V_145 * V_146 ,
struct V_147 * V_148 ,
const char * V_149 , T_8 V_57 )
{
int V_137 = V_146 -> V_150 ;
if ( V_137 >= 0 && V_137 < V_151 && F_122 ( V_137 ) ) {
F_116 () ;
F_113 ( V_137 ) ;
}
return V_57 ;
}
int F_123 ( struct V_152 * V_152 )
{
return F_124 ( & V_152 -> V_146 , & V_153 ) ;
}
void F_125 ( struct V_152 * V_152 )
{
return F_126 ( & V_152 -> V_146 , & V_153 ) ;
}
