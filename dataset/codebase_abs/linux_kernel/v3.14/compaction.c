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
static inline bool F_15 ( struct V_13 * V_14 ,
struct V_6 * V_6 )
{
if ( V_14 -> V_15 )
return true ;
return ! F_16 ( V_6 ) ;
}
static void F_17 ( struct V_16 * V_16 )
{
unsigned long V_17 = V_16 -> V_18 ;
unsigned long V_19 = F_18 ( V_16 ) ;
unsigned long V_20 ;
V_16 -> V_21 = V_17 ;
V_16 -> V_22 = V_19 ;
V_16 -> V_23 = false ;
for ( V_20 = V_17 ; V_20 < V_19 ; V_20 += V_24 ) {
struct V_6 * V_6 ;
F_19 () ;
if ( ! F_20 ( V_20 ) )
continue;
V_6 = F_21 ( V_20 ) ;
if ( V_16 != F_22 ( V_6 ) )
continue;
F_23 ( V_6 ) ;
}
}
void F_24 ( T_1 * V_25 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
struct V_16 * V_16 = & V_25 -> V_28 [ V_26 ] ;
if ( ! F_25 ( V_16 ) )
continue;
if ( V_16 -> V_23 )
F_17 ( V_16 ) ;
}
}
static void F_26 ( struct V_13 * V_14 ,
struct V_6 * V_6 , unsigned long V_29 ,
bool V_30 )
{
struct V_16 * V_16 = V_14 -> V_16 ;
if ( V_14 -> V_15 )
return;
if ( ! V_6 )
return;
if ( ! V_29 ) {
unsigned long V_20 = F_27 ( V_6 ) ;
F_28 ( V_6 ) ;
if ( V_30 ) {
if ( ! V_14 -> V_31 &&
V_20 > V_16 -> V_21 )
V_16 -> V_21 = V_20 ;
} else {
if ( ! V_14 -> V_32 &&
V_20 < V_16 -> V_22 )
V_16 -> V_22 = V_20 ;
}
}
}
static inline bool F_15 ( struct V_13 * V_14 ,
struct V_6 * V_6 )
{
return true ;
}
static void F_26 ( struct V_13 * V_14 ,
struct V_6 * V_6 , unsigned long V_29 ,
bool V_30 )
{
}
static inline bool F_29 ( T_2 * V_33 )
{
return F_30 () || F_31 ( V_33 ) ;
}
static bool F_32 ( T_2 * V_33 , unsigned long * V_34 ,
bool V_35 , struct V_13 * V_14 )
{
if ( F_29 ( V_33 ) ) {
if ( V_35 ) {
F_33 ( V_33 , * V_34 ) ;
V_35 = false ;
}
if ( ! V_14 -> V_36 ) {
V_14 -> V_37 = true ;
return false ;
}
F_19 () ;
}
if ( ! V_35 )
F_34 ( V_33 , * V_34 ) ;
return true ;
}
static inline bool F_35 ( T_2 * V_33 ,
unsigned long * V_34 , struct V_13 * V_14 )
{
return F_32 ( V_33 , V_34 , false , V_14 ) ;
}
static bool F_36 ( struct V_6 * V_6 )
{
int V_11 = F_37 ( V_6 ) ;
if ( V_11 == V_38 )
return false ;
if ( F_38 ( V_11 ) )
return false ;
if ( F_39 ( V_6 ) && F_40 ( V_6 ) >= V_39 )
return true ;
if ( F_13 ( V_11 ) )
return true ;
return false ;
}
static unsigned long F_41 ( struct V_13 * V_14 ,
unsigned long V_40 ,
unsigned long V_19 ,
struct V_4 * V_5 ,
bool V_41 )
{
int V_42 = 0 , V_43 = 0 ;
struct V_6 * V_44 , * V_45 = NULL ;
unsigned long V_34 ;
bool V_35 = false ;
V_44 = F_21 ( V_40 ) ;
for (; V_40 < V_19 ; V_40 ++ , V_44 ++ ) {
int V_46 , V_47 ;
struct V_6 * V_6 = V_44 ;
V_42 ++ ;
if ( ! F_42 ( V_40 ) )
goto V_48;
if ( ! V_45 )
V_45 = V_6 ;
if ( ! F_39 ( V_6 ) )
goto V_48;
V_35 = F_32 ( & V_14 -> V_16 -> V_33 , & V_34 ,
V_35 , V_14 ) ;
if ( ! V_35 )
break;
if ( ! V_41 && ! F_36 ( V_6 ) )
break;
if ( ! F_39 ( V_6 ) )
goto V_48;
V_46 = F_43 ( V_6 ) ;
V_43 += V_46 ;
for ( V_47 = 0 ; V_47 < V_46 ; V_47 ++ ) {
F_44 ( & V_6 -> V_9 , V_5 ) ;
V_6 ++ ;
}
if ( V_46 ) {
V_40 += V_46 - 1 ;
V_44 += V_46 - 1 ;
continue;
}
V_48:
if ( V_41 )
break;
else
continue;
}
F_45 ( V_42 , V_43 ) ;
if ( V_41 && V_40 < V_19 )
V_43 = 0 ;
if ( V_35 )
F_33 ( & V_14 -> V_16 -> V_33 , V_34 ) ;
if ( V_40 == V_19 )
F_26 ( V_14 , V_45 , V_43 , false ) ;
F_3 ( V_49 , V_42 ) ;
if ( V_43 )
F_3 ( V_50 , V_43 ) ;
return V_43 ;
}
unsigned long
F_46 ( struct V_13 * V_14 ,
unsigned long V_17 , unsigned long V_19 )
{
unsigned long V_46 , V_20 , V_51 ;
F_47 ( V_5 ) ;
for ( V_20 = V_17 ; V_20 < V_19 ; V_20 += V_46 ) {
if ( ! F_20 ( V_20 ) || V_14 -> V_16 != F_22 ( F_21 ( V_20 ) ) )
break;
V_51 = F_48 ( V_20 + 1 , V_24 ) ;
V_51 = F_49 ( V_51 , V_19 ) ;
V_46 = F_41 ( V_14 , V_20 , V_51 ,
& V_5 , true ) ;
if ( ! V_46 )
break;
}
F_9 ( & V_5 ) ;
if ( V_20 < V_19 ) {
F_5 ( & V_5 ) ;
return 0 ;
}
return V_20 ;
}
static void F_50 ( struct V_16 * V_16 , bool V_35 , struct V_13 * V_14 )
{
struct V_6 * V_6 ;
unsigned int V_8 [ 2 ] = { 0 , } ;
F_10 (page, &cc->migratepages, lru)
V_8 [ ! ! F_51 ( V_6 ) ] ++ ;
if ( V_35 ) {
F_52 ( V_16 , V_52 , V_8 [ 0 ] ) ;
F_52 ( V_16 , V_53 , V_8 [ 1 ] ) ;
} else {
F_53 ( V_16 , V_52 , V_8 [ 0 ] ) ;
F_53 ( V_16 , V_53 , V_8 [ 1 ] ) ;
}
}
static bool F_54 ( struct V_16 * V_16 )
{
unsigned long V_54 , V_55 , V_46 ;
V_55 = F_55 ( V_16 , V_56 ) +
F_55 ( V_16 , V_57 ) ;
V_54 = F_55 ( V_16 , V_58 ) +
F_55 ( V_16 , V_59 ) ;
V_46 = F_55 ( V_16 , V_53 ) +
F_55 ( V_16 , V_52 ) ;
return V_46 > ( V_55 + V_54 ) / 2 ;
}
unsigned long
F_56 ( struct V_16 * V_16 , struct V_13 * V_14 ,
unsigned long V_60 , unsigned long V_19 , bool V_61 )
{
unsigned long V_62 = 0 , V_63 ;
unsigned long V_42 = 0 , V_29 = 0 ;
struct V_4 * V_64 = & V_14 -> V_65 ;
T_3 V_66 = 0 ;
struct V_67 * V_67 ;
unsigned long V_34 ;
bool V_35 = false ;
struct V_6 * V_6 = NULL , * V_45 = NULL ;
bool V_68 = false ;
while ( F_57 ( F_54 ( V_16 ) ) ) {
if ( ! V_14 -> V_36 )
return 0 ;
F_58 ( V_69 , V_70 / 10 ) ;
if ( F_59 ( V_71 ) )
return 0 ;
}
F_19 () ;
for (; V_60 < V_19 ; V_60 ++ ) {
if ( V_35 && ! ( ( V_60 + 1 ) % V_72 ) ) {
if ( F_29 ( & V_16 -> V_73 ) ) {
F_33 ( & V_16 -> V_73 , V_34 ) ;
V_35 = false ;
}
}
if ( ( V_60 & ( V_74 - 1 ) ) == 0 ) {
if ( ! F_20 ( V_60 ) ) {
V_60 += V_74 - 1 ;
continue;
}
}
if ( ! F_42 ( V_60 ) )
continue;
V_42 ++ ;
V_6 = F_21 ( V_60 ) ;
if ( F_22 ( V_6 ) != V_16 )
continue;
if ( ! V_45 )
V_45 = V_6 ;
V_63 = V_60 >> V_39 ;
if ( ! F_15 ( V_14 , V_6 ) )
goto V_75;
if ( F_39 ( V_6 ) )
continue;
if ( ! V_14 -> V_36 && V_62 != V_63 &&
! F_13 ( F_37 ( V_6 ) ) ) {
V_14 -> V_31 = true ;
V_68 = true ;
goto V_75;
}
if ( ! F_60 ( V_6 ) ) {
if ( F_57 ( F_61 ( V_6 ) ) ) {
if ( V_35 && F_62 ( V_6 ) ) {
V_14 -> V_31 = true ;
F_44 ( & V_6 -> V_9 , V_64 ) ;
V_14 -> V_76 ++ ;
V_29 ++ ;
goto V_77;
}
}
continue;
}
if ( F_63 ( V_6 ) ) {
if ( ! V_35 )
goto V_75;
V_60 += ( 1 << F_64 ( V_6 ) ) - 1 ;
continue;
}
V_35 = F_32 ( & V_16 -> V_73 , & V_34 ,
V_35 , V_14 ) ;
if ( ! V_35 || F_59 ( V_71 ) )
break;
if ( ! F_60 ( V_6 ) )
continue;
if ( F_63 ( V_6 ) ) {
V_60 += ( 1 << F_64 ( V_6 ) ) - 1 ;
continue;
}
if ( ! V_14 -> V_36 )
V_66 |= V_78 ;
if ( V_61 )
V_66 |= V_79 ;
V_67 = F_65 ( V_6 , V_16 ) ;
if ( F_66 ( V_6 , V_66 ) != 0 )
continue;
F_67 ( F_68 ( V_6 ) , V_6 ) ;
V_14 -> V_31 = true ;
F_69 ( V_6 , V_67 , F_70 ( V_6 ) ) ;
F_44 ( & V_6 -> V_9 , V_64 ) ;
V_14 -> V_76 ++ ;
V_29 ++ ;
V_77:
if ( V_14 -> V_76 == V_80 ) {
++ V_60 ;
break;
}
continue;
V_75:
V_60 = F_48 ( V_60 + 1 , V_24 ) - 1 ;
V_62 = V_63 ;
}
F_50 ( V_16 , V_35 , V_14 ) ;
if ( V_35 )
F_33 ( & V_16 -> V_73 , V_34 ) ;
if ( V_60 == V_19 && ! V_68 )
F_26 ( V_14 , V_45 , V_29 , true ) ;
F_71 ( V_42 , V_29 ) ;
F_3 ( V_81 , V_42 ) ;
if ( V_29 )
F_3 ( V_50 , V_29 ) ;
return V_60 ;
}
static void F_72 ( struct V_16 * V_16 ,
struct V_13 * V_14 )
{
struct V_6 * V_6 ;
unsigned long V_82 , V_60 , V_20 , V_83 , V_19 ;
int V_84 = V_14 -> V_84 ;
struct V_4 * V_5 = & V_14 -> V_85 ;
V_20 = V_14 -> V_86 ;
V_60 = F_48 ( V_14 -> V_87 + 1 , V_24 ) ;
V_82 = F_49 ( V_60 , V_20 ) ;
V_83 = F_18 ( V_16 ) ;
for (; V_20 >= V_60 && V_14 -> V_76 > V_84 ;
V_20 -= V_24 ) {
unsigned long V_46 ;
F_19 () ;
if ( ! F_20 ( V_20 ) )
continue;
V_6 = F_21 ( V_20 ) ;
if ( F_22 ( V_6 ) != V_16 )
continue;
if ( ! F_36 ( V_6 ) )
continue;
if ( ! F_15 ( V_14 , V_6 ) )
continue;
V_46 = 0 ;
V_19 = F_48 ( V_20 + 1 , V_24 ) ;
V_19 = F_49 ( V_19 , V_83 ) ;
V_46 = F_41 ( V_14 , V_20 , V_19 ,
V_5 , false ) ;
V_84 += V_46 ;
if ( V_46 ) {
V_14 -> V_32 = true ;
V_82 = F_73 ( V_82 , V_20 ) ;
}
}
F_9 ( V_5 ) ;
if ( V_20 < V_60 )
V_14 -> V_86 = F_73 ( V_20 , V_16 -> V_18 ) ;
else
V_14 -> V_86 = V_82 ;
V_14 -> V_84 = V_84 ;
}
static struct V_6 * F_74 ( struct V_6 * V_88 ,
unsigned long V_89 ,
int * * V_90 )
{
struct V_13 * V_14 = (struct V_13 * ) V_89 ;
struct V_6 * V_91 ;
if ( F_75 ( & V_14 -> V_85 ) ) {
F_72 ( V_14 -> V_16 , V_14 ) ;
if ( F_75 ( & V_14 -> V_85 ) )
return NULL ;
}
V_91 = F_76 ( V_14 -> V_85 . V_7 , struct V_6 , V_9 ) ;
F_7 ( & V_91 -> V_9 ) ;
V_14 -> V_84 -- ;
return V_91 ;
}
static void F_77 ( struct V_13 * V_14 )
{
int V_76 = 0 ;
int V_84 = 0 ;
struct V_6 * V_6 ;
F_10 (page, &cc->migratepages, lru)
V_76 ++ ;
F_10 (page, &cc->freepages, lru)
V_84 ++ ;
V_14 -> V_76 = V_76 ;
V_14 -> V_84 = V_84 ;
}
static T_4 F_78 ( struct V_16 * V_16 ,
struct V_13 * V_14 )
{
unsigned long V_60 , V_19 ;
V_60 = F_73 ( V_14 -> V_87 , V_16 -> V_18 ) ;
V_19 = F_48 ( V_60 + 1 , V_24 ) ;
if ( V_19 > V_14 -> V_86 || ! F_20 ( V_60 ) ) {
V_14 -> V_87 = V_19 ;
return V_92 ;
}
V_60 = F_56 ( V_16 , V_14 , V_60 , V_19 , false ) ;
if ( ! V_60 || V_14 -> V_37 )
return V_93 ;
V_14 -> V_87 = V_60 ;
return V_94 ;
}
static int F_79 ( struct V_16 * V_16 ,
struct V_13 * V_14 )
{
unsigned int V_95 ;
unsigned long V_96 ;
if ( F_59 ( V_71 ) )
return V_97 ;
if ( V_14 -> V_86 <= V_14 -> V_87 ) {
V_16 -> V_21 = V_16 -> V_18 ;
V_16 -> V_22 = F_18 ( V_16 ) ;
if ( ! F_80 () )
V_16 -> V_23 = true ;
return V_98 ;
}
if ( V_14 -> V_95 == - 1 )
return V_99 ;
V_96 = F_81 ( V_16 ) ;
V_96 += ( 1 << V_14 -> V_95 ) ;
if ( ! F_82 ( V_16 , V_14 -> V_95 , V_96 , 0 , 0 ) )
return V_99 ;
for ( V_95 = V_14 -> V_95 ; V_95 < V_100 ; V_95 ++ ) {
struct V_101 * V_102 = & V_16 -> V_101 [ V_95 ] ;
if ( ! F_75 ( & V_102 -> V_103 [ V_14 -> V_11 ] ) )
return V_97 ;
if ( V_14 -> V_95 >= V_39 && V_102 -> V_104 )
return V_97 ;
}
return V_99 ;
}
unsigned long F_83 ( struct V_16 * V_16 , int V_95 )
{
int V_105 ;
unsigned long V_96 ;
if ( V_95 == - 1 )
return V_99 ;
V_96 = F_81 ( V_16 ) + ( 2UL << V_95 ) ;
if ( ! F_82 ( V_16 , 0 , V_96 , 0 , 0 ) )
return V_106 ;
V_105 = F_84 ( V_16 , V_95 ) ;
if ( V_105 >= 0 && V_105 <= V_107 )
return V_106 ;
if ( V_105 == - 1000 && F_82 ( V_16 , V_95 , V_96 ,
0 , 0 ) )
return V_97 ;
return V_99 ;
}
static int F_85 ( struct V_16 * V_16 , struct V_13 * V_14 )
{
int V_108 ;
unsigned long V_17 = V_16 -> V_18 ;
unsigned long V_19 = F_18 ( V_16 ) ;
V_108 = F_83 ( V_16 , V_14 -> V_95 ) ;
switch ( V_108 ) {
case V_97 :
case V_106 :
return V_108 ;
case V_99 :
;
}
if ( F_86 ( V_16 , V_14 -> V_95 ) && ! F_80 () )
F_17 ( V_16 ) ;
V_14 -> V_87 = V_16 -> V_21 ;
V_14 -> V_86 = V_16 -> V_22 ;
if ( V_14 -> V_86 < V_17 || V_14 -> V_86 > V_19 ) {
V_14 -> V_86 = V_19 & ~ ( V_24 - 1 ) ;
V_16 -> V_22 = V_14 -> V_86 ;
}
if ( V_14 -> V_87 < V_17 || V_14 -> V_87 > V_19 ) {
V_14 -> V_87 = V_17 ;
V_16 -> V_21 = V_14 -> V_87 ;
}
F_87 ( V_17 , V_14 -> V_87 , V_14 -> V_86 , V_19 ) ;
F_88 () ;
while ( ( V_108 = F_79 ( V_16 , V_14 ) ) == V_99 ) {
unsigned long V_109 , V_110 ;
int V_111 ;
switch ( F_78 ( V_16 , V_14 ) ) {
case V_93 :
V_108 = V_97 ;
F_89 ( & V_14 -> V_65 ) ;
V_14 -> V_76 = 0 ;
goto V_112;
case V_92 :
continue;
case V_94 :
;
}
V_109 = V_14 -> V_76 ;
V_111 = F_90 ( & V_14 -> V_65 , F_74 ,
( unsigned long ) V_14 ,
V_14 -> V_36 ? V_113 : V_114 ,
V_115 ) ;
F_77 ( V_14 ) ;
V_110 = V_14 -> V_76 ;
F_91 ( V_109 - V_110 ,
V_110 ) ;
if ( V_111 ) {
F_89 ( & V_14 -> V_65 ) ;
V_14 -> V_76 = 0 ;
if ( V_111 == - V_116 && V_14 -> V_86 > V_14 -> V_87 ) {
V_108 = V_97 ;
goto V_112;
}
}
}
V_112:
V_14 -> V_84 -= F_5 ( & V_14 -> V_85 ) ;
F_92 ( V_14 -> V_84 != 0 ) ;
F_93 ( V_108 ) ;
return V_108 ;
}
static unsigned long F_94 ( struct V_16 * V_16 ,
int V_95 , T_5 V_117 ,
bool V_36 , bool * V_37 )
{
unsigned long V_108 ;
struct V_13 V_14 = {
. V_84 = 0 ,
. V_76 = 0 ,
. V_95 = V_95 ,
. V_11 = F_95 ( V_117 ) ,
. V_16 = V_16 ,
. V_36 = V_36 ,
} ;
F_96 ( & V_14 . V_85 ) ;
F_96 ( & V_14 . V_65 ) ;
V_108 = F_85 ( V_16 , & V_14 ) ;
F_92 ( ! F_75 ( & V_14 . V_85 ) ) ;
F_92 ( ! F_75 ( & V_14 . V_65 ) ) ;
* V_37 = V_14 . V_37 ;
return V_108 ;
}
unsigned long F_97 ( struct V_118 * V_118 ,
int V_95 , T_5 V_117 , T_6 * V_119 ,
bool V_36 , bool * V_37 )
{
enum V_120 V_121 = F_98 ( V_117 ) ;
int V_122 = V_117 & V_123 ;
int V_124 = V_117 & V_125 ;
struct V_126 * V_127 ;
struct V_16 * V_16 ;
int V_128 = V_106 ;
int V_129 = 0 ;
if ( ! V_95 || ! V_122 || ! V_124 )
return V_128 ;
F_1 ( V_130 ) ;
#ifdef F_99
if ( F_95 ( V_117 ) == V_12 )
V_129 |= V_131 ;
#endif
F_100 (zone, z, zonelist, high_zoneidx,
nodemask) {
int V_132 ;
V_132 = F_94 ( V_16 , V_95 , V_117 , V_36 ,
V_37 ) ;
V_128 = F_73 ( V_132 , V_128 ) ;
if ( F_82 ( V_16 , V_95 , F_81 ( V_16 ) , 0 ,
V_129 ) )
break;
}
return V_128 ;
}
static void F_101 ( T_1 * V_25 , struct V_13 * V_14 )
{
int V_26 ;
struct V_16 * V_16 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
V_16 = & V_25 -> V_28 [ V_26 ] ;
if ( ! F_25 ( V_16 ) )
continue;
V_14 -> V_84 = 0 ;
V_14 -> V_76 = 0 ;
V_14 -> V_16 = V_16 ;
F_96 ( & V_14 -> V_85 ) ;
F_96 ( & V_14 -> V_65 ) ;
if ( V_14 -> V_95 == - 1 || ! F_102 ( V_16 , V_14 -> V_95 ) )
F_85 ( V_16 , V_14 ) ;
if ( V_14 -> V_95 > 0 ) {
if ( F_82 ( V_16 , V_14 -> V_95 ,
F_81 ( V_16 ) , 0 , 0 ) )
F_103 ( V_16 , V_14 -> V_95 , false ) ;
else if ( V_14 -> V_36 )
F_104 ( V_16 , V_14 -> V_95 ) ;
}
F_92 ( ! F_75 ( & V_14 -> V_85 ) ) ;
F_92 ( ! F_75 ( & V_14 -> V_65 ) ) ;
}
}
void F_105 ( T_1 * V_25 , int V_95 )
{
struct V_13 V_14 = {
. V_95 = V_95 ,
. V_36 = false ,
} ;
if ( ! V_95 )
return;
F_101 ( V_25 , & V_14 ) ;
}
static void F_106 ( int V_133 )
{
struct V_13 V_14 = {
. V_95 = - 1 ,
. V_36 = true ,
} ;
F_101 ( F_107 ( V_133 ) , & V_14 ) ;
}
static void F_108 ( void )
{
int V_133 ;
F_109 () ;
F_110 (nid)
F_106 ( V_133 ) ;
}
int F_111 ( struct V_134 * V_135 , int V_136 ,
void T_7 * V_137 , T_8 * V_138 , T_9 * V_139 )
{
if ( V_136 )
F_108 () ;
return 0 ;
}
int F_112 ( struct V_134 * V_135 , int V_136 ,
void T_7 * V_137 , T_8 * V_138 , T_9 * V_139 )
{
F_113 ( V_135 , V_136 , V_137 , V_138 , V_139 ) ;
return 0 ;
}
T_10 F_114 ( struct V_140 * V_141 ,
struct V_142 * V_143 ,
const char * V_144 , T_8 V_8 )
{
int V_133 = V_141 -> V_145 ;
if ( V_133 >= 0 && V_133 < V_146 && F_115 ( V_133 ) ) {
F_109 () ;
F_106 ( V_133 ) ;
}
return V_8 ;
}
int F_116 ( struct V_147 * V_147 )
{
return F_117 ( & V_147 -> V_141 , & V_148 ) ;
}
void F_118 ( struct V_147 * V_147 )
{
return F_119 ( & V_147 -> V_141 , & V_148 ) ;
}
