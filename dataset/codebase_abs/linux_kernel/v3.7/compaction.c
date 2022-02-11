static unsigned long F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 , * V_4 ;
unsigned long V_5 = 0 ;
F_2 (page, next, freelist, lru) {
F_3 ( & V_3 -> V_6 ) ;
F_4 ( V_3 ) ;
V_5 ++ ;
}
return V_5 ;
}
static void F_5 ( struct V_1 * V_7 )
{
struct V_3 * V_3 ;
F_6 (page, list, lru) {
F_7 ( V_3 , 0 ) ;
F_8 ( V_3 , 1 , 1 ) ;
}
}
static inline bool F_9 ( int V_8 )
{
return F_10 ( V_8 ) || V_8 == V_9 ;
}
static inline bool F_11 ( struct V_10 * V_11 ,
struct V_3 * V_3 )
{
if ( V_11 -> V_12 )
return true ;
return ! F_12 ( V_3 ) ;
}
static void F_13 ( struct V_13 * V_13 )
{
unsigned long V_14 = V_13 -> V_15 ;
unsigned long V_16 = V_13 -> V_15 + V_13 -> V_17 ;
unsigned long V_18 ;
V_13 -> V_19 = V_14 ;
V_13 -> V_20 = V_16 ;
V_13 -> V_21 = false ;
for ( V_18 = V_14 ; V_18 < V_16 ; V_18 += V_22 ) {
struct V_3 * V_3 ;
F_14 () ;
if ( ! F_15 ( V_18 ) )
continue;
V_3 = F_16 ( V_18 ) ;
if ( V_13 != F_17 ( V_3 ) )
continue;
F_18 ( V_3 ) ;
}
}
void F_19 ( T_1 * V_23 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
struct V_13 * V_13 = & V_23 -> V_26 [ V_24 ] ;
if ( ! F_20 ( V_13 ) )
continue;
if ( V_13 -> V_21 )
F_13 ( V_13 ) ;
}
}
static void F_21 ( struct V_10 * V_11 ,
struct V_3 * V_3 , unsigned long V_27 ,
bool V_28 )
{
struct V_13 * V_13 = V_11 -> V_13 ;
if ( ! V_3 )
return;
if ( ! V_27 ) {
unsigned long V_18 = F_22 ( V_3 ) ;
F_23 ( V_3 ) ;
if ( V_28 ) {
if ( ! V_11 -> V_29 &&
V_18 > V_13 -> V_19 )
V_13 -> V_19 = V_18 ;
} else {
if ( ! V_11 -> V_30 &&
V_18 < V_13 -> V_20 )
V_13 -> V_20 = V_18 ;
}
}
}
static inline bool F_11 ( struct V_10 * V_11 ,
struct V_3 * V_3 )
{
return true ;
}
static void F_21 ( struct V_10 * V_11 ,
struct V_3 * V_3 , unsigned long V_27 ,
bool V_28 )
{
}
static inline bool F_24 ( T_2 * V_31 )
{
return F_25 () || F_26 ( V_31 ) ;
}
static bool F_27 ( T_2 * V_31 , unsigned long * V_32 ,
bool V_33 , struct V_10 * V_11 )
{
if ( F_24 ( V_31 ) ) {
if ( V_33 ) {
F_28 ( V_31 , * V_32 ) ;
V_33 = false ;
}
if ( ! V_11 -> V_34 ) {
V_11 -> V_35 = true ;
return false ;
}
F_14 () ;
}
if ( ! V_33 )
F_29 ( V_31 , * V_32 ) ;
return true ;
}
static inline bool F_30 ( T_2 * V_31 ,
unsigned long * V_32 , struct V_10 * V_11 )
{
return F_27 ( V_31 , V_32 , false , V_11 ) ;
}
static bool F_31 ( struct V_3 * V_3 )
{
int V_8 = F_32 ( V_3 ) ;
if ( V_8 == V_36 || V_8 == V_37 )
return false ;
if ( F_33 ( V_3 ) && F_34 ( V_3 ) >= V_38 )
return true ;
if ( F_9 ( V_8 ) )
return true ;
return false ;
}
static void F_35 ( struct V_10 * V_11 )
{
unsigned long V_32 ;
int V_39 , V_40 , V_41 ;
if ( ! V_11 -> V_3 || * V_11 -> V_3 )
return;
if ( V_11 -> V_8 == V_9 ) {
V_40 = 0 ;
V_41 = V_42 ;
} else {
V_40 = V_11 -> V_8 ;
V_41 = V_11 -> V_8 + 1 ;
}
for ( V_39 = V_40 ; V_39 < V_41 ; V_39 ++ ) {
int V_43 ;
for ( V_43 = V_11 -> V_43 ; V_43 < V_44 ; V_43 ++ ) {
struct V_3 * V_3 ;
struct V_45 * V_46 ;
V_46 = & ( V_11 -> V_13 -> V_45 [ V_43 ] ) ;
if ( F_36 ( & V_46 -> V_47 [ V_39 ] ) )
continue;
if ( ! F_30 ( & V_11 -> V_13 -> V_31 , & V_32 , V_11 ) )
return;
if ( ! F_36 ( & V_46 -> V_47 [ V_39 ] ) ) {
V_3 = F_37 ( V_46 -> V_47 [ V_39 ] . V_4 ,
struct V_3 , V_6 ) ;
if ( F_38 ( V_3 , V_11 -> V_43 , V_39 ) ) {
F_28 ( & V_11 -> V_13 -> V_31 ,
V_32 ) ;
* V_11 -> V_3 = V_3 ;
return;
}
}
F_28 ( & V_11 -> V_13 -> V_31 , V_32 ) ;
}
}
}
static unsigned long F_39 ( struct V_10 * V_11 ,
unsigned long V_48 ,
unsigned long V_16 ,
struct V_1 * V_2 ,
bool V_49 )
{
int V_50 = 0 , V_51 = 0 ;
struct V_3 * V_52 , * V_53 = NULL ;
unsigned long V_54 = V_16 - V_48 ;
unsigned long V_32 ;
bool V_33 = false ;
V_52 = F_16 ( V_48 ) ;
for (; V_48 < V_16 ; V_48 ++ , V_52 ++ ) {
int V_55 , V_56 ;
struct V_3 * V_3 = V_52 ;
V_50 ++ ;
if ( ! F_40 ( V_48 ) )
continue;
if ( ! V_53 )
V_53 = V_3 ;
if ( ! F_33 ( V_3 ) )
continue;
V_33 = F_27 ( & V_11 -> V_13 -> V_31 , & V_32 ,
V_33 , V_11 ) ;
if ( ! V_33 )
break;
if ( ! V_49 && ! F_31 ( V_3 ) )
break;
if ( ! F_33 ( V_3 ) )
continue;
V_55 = F_41 ( V_3 ) ;
if ( ! V_55 && V_49 )
break;
V_51 += V_55 ;
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ ) {
F_42 ( & V_3 -> V_6 , V_2 ) ;
V_3 ++ ;
}
if ( V_55 ) {
V_48 += V_55 - 1 ;
V_52 += V_55 - 1 ;
}
}
F_43 ( V_50 , V_51 ) ;
if ( V_49 && V_54 > V_51 )
V_51 = 0 ;
if ( V_33 )
F_28 ( & V_11 -> V_13 -> V_31 , V_32 ) ;
if ( V_48 == V_16 )
F_21 ( V_11 , V_53 , V_51 , false ) ;
return V_51 ;
}
unsigned long
F_44 ( struct V_10 * V_11 ,
unsigned long V_14 , unsigned long V_16 )
{
unsigned long V_55 , V_18 , V_57 ;
F_45 ( V_2 ) ;
for ( V_18 = V_14 ; V_18 < V_16 ; V_18 += V_55 ) {
if ( ! F_15 ( V_18 ) || V_11 -> V_13 != F_17 ( F_16 ( V_18 ) ) )
break;
V_57 = F_46 ( V_18 + 1 , V_22 ) ;
V_57 = F_47 ( V_57 , V_16 ) ;
V_55 = F_39 ( V_11 , V_18 , V_57 ,
& V_2 , true ) ;
if ( ! V_55 )
break;
}
F_5 ( & V_2 ) ;
if ( V_18 < V_16 ) {
F_1 ( & V_2 ) ;
return 0 ;
}
return V_18 ;
}
static void F_48 ( struct V_13 * V_13 , bool V_33 , struct V_10 * V_11 )
{
struct V_3 * V_3 ;
unsigned int V_5 [ 2 ] = { 0 , } ;
F_6 (page, &cc->migratepages, lru)
V_5 [ ! ! F_49 ( V_3 ) ] ++ ;
if ( V_33 ) {
F_50 ( V_13 , V_58 , V_5 [ 0 ] ) ;
F_50 ( V_13 , V_59 , V_5 [ 1 ] ) ;
} else {
F_51 ( V_13 , V_58 , V_5 [ 0 ] ) ;
F_51 ( V_13 , V_59 , V_5 [ 1 ] ) ;
}
}
static bool F_52 ( struct V_13 * V_13 )
{
unsigned long V_60 , V_61 , V_55 ;
V_61 = F_53 ( V_13 , V_62 ) +
F_53 ( V_13 , V_63 ) ;
V_60 = F_53 ( V_13 , V_64 ) +
F_53 ( V_13 , V_65 ) ;
V_55 = F_53 ( V_13 , V_59 ) +
F_53 ( V_13 , V_58 ) ;
return V_55 > ( V_61 + V_60 ) / 2 ;
}
unsigned long
F_54 ( struct V_13 * V_13 , struct V_10 * V_11 ,
unsigned long V_66 , unsigned long V_16 , bool V_67 )
{
unsigned long V_68 = 0 , V_69 ;
unsigned long V_50 = 0 , V_27 = 0 ;
struct V_1 * V_70 = & V_11 -> V_71 ;
T_3 V_72 = 0 ;
struct V_73 * V_73 ;
unsigned long V_32 ;
bool V_33 = false ;
struct V_3 * V_3 = NULL , * V_53 = NULL ;
while ( F_55 ( F_52 ( V_13 ) ) ) {
if ( ! V_11 -> V_34 )
return 0 ;
F_56 ( V_74 , V_75 / 10 ) ;
if ( F_57 ( V_76 ) )
return 0 ;
}
F_14 () ;
for (; V_66 < V_16 ; V_66 ++ ) {
if ( V_33 && ! ( ( V_66 + 1 ) % V_77 ) ) {
if ( F_24 ( & V_13 -> V_78 ) ) {
F_28 ( & V_13 -> V_78 , V_32 ) ;
V_33 = false ;
}
}
if ( ( V_66 & ( V_79 - 1 ) ) == 0 ) {
if ( ! F_15 ( V_66 ) ) {
V_66 += V_79 - 1 ;
continue;
}
}
if ( ! F_40 ( V_66 ) )
continue;
V_50 ++ ;
V_3 = F_16 ( V_66 ) ;
if ( F_17 ( V_3 ) != V_13 )
continue;
if ( ! V_53 )
V_53 = V_3 ;
V_69 = V_66 >> V_38 ;
if ( ! F_11 ( V_11 , V_3 ) )
goto V_80;
if ( F_33 ( V_3 ) )
continue;
if ( ! V_11 -> V_34 && V_68 != V_69 &&
! F_9 ( F_32 ( V_3 ) ) ) {
V_11 -> V_29 = true ;
goto V_80;
}
if ( ! F_58 ( V_3 ) )
continue;
if ( F_59 ( V_3 ) ) {
if ( ! V_33 )
goto V_80;
V_66 += ( 1 << F_60 ( V_3 ) ) - 1 ;
continue;
}
V_33 = F_27 ( & V_13 -> V_78 , & V_32 ,
V_33 , V_11 ) ;
if ( ! V_33 || F_57 ( V_76 ) )
break;
if ( ! F_58 ( V_3 ) )
continue;
if ( F_59 ( V_3 ) ) {
V_66 += ( 1 << F_60 ( V_3 ) ) - 1 ;
continue;
}
if ( ! V_11 -> V_34 )
V_72 |= V_81 ;
if ( V_67 )
V_72 |= V_82 ;
V_73 = F_61 ( V_3 , V_13 ) ;
if ( F_62 ( V_3 , V_72 ) != 0 )
continue;
F_63 ( F_64 ( V_3 ) ) ;
V_11 -> V_29 = true ;
F_65 ( V_3 , V_73 , F_66 ( V_3 ) ) ;
F_42 ( & V_3 -> V_6 , V_70 ) ;
V_11 -> V_83 ++ ;
V_27 ++ ;
if ( V_11 -> V_83 == V_84 ) {
++ V_66 ;
break;
}
continue;
V_80:
V_66 += V_22 ;
V_66 = F_46 ( V_66 , V_22 ) - 1 ;
V_68 = V_69 ;
}
F_48 ( V_13 , V_33 , V_11 ) ;
if ( V_33 )
F_28 ( & V_13 -> V_78 , V_32 ) ;
if ( V_66 == V_16 )
F_21 ( V_11 , V_53 , V_27 , true ) ;
F_67 ( V_50 , V_27 ) ;
return V_66 ;
}
static void F_68 ( struct V_13 * V_13 ,
struct V_10 * V_11 )
{
struct V_3 * V_3 ;
unsigned long V_85 , V_66 , V_18 , V_86 , V_16 ;
int V_87 = V_11 -> V_87 ;
struct V_1 * V_2 = & V_11 -> V_88 ;
V_18 = V_11 -> V_89 ;
V_66 = V_11 -> V_90 + V_22 ;
V_85 = F_47 ( V_66 , V_18 ) ;
V_86 = V_13 -> V_15 + V_13 -> V_17 ;
for (; V_18 > V_66 && V_11 -> V_83 > V_87 ;
V_18 -= V_22 ) {
unsigned long V_55 ;
if ( ! F_15 ( V_18 ) )
continue;
V_3 = F_16 ( V_18 ) ;
if ( F_17 ( V_3 ) != V_13 )
continue;
if ( ! F_31 ( V_3 ) )
continue;
if ( ! F_11 ( V_11 , V_3 ) )
continue;
V_55 = 0 ;
V_16 = F_46 ( V_18 + 1 , V_22 ) ;
V_16 = F_47 ( V_16 , V_86 ) ;
V_55 = F_39 ( V_11 , V_18 , V_16 ,
V_2 , false ) ;
V_87 += V_55 ;
if ( V_55 ) {
V_11 -> V_30 = true ;
V_85 = F_69 ( V_85 , V_18 ) ;
}
}
F_5 ( V_2 ) ;
V_11 -> V_89 = V_85 ;
V_11 -> V_87 = V_87 ;
}
static struct V_3 * F_70 ( struct V_3 * V_91 ,
unsigned long V_92 ,
int * * V_93 )
{
struct V_10 * V_11 = (struct V_10 * ) V_92 ;
struct V_3 * V_94 ;
if ( F_36 ( & V_11 -> V_88 ) ) {
F_68 ( V_11 -> V_13 , V_11 ) ;
if ( F_36 ( & V_11 -> V_88 ) )
return NULL ;
}
V_94 = F_37 ( V_11 -> V_88 . V_4 , struct V_3 , V_6 ) ;
F_3 ( & V_94 -> V_6 ) ;
V_11 -> V_87 -- ;
return V_94 ;
}
static void F_71 ( struct V_10 * V_11 )
{
int V_83 = 0 ;
int V_87 = 0 ;
struct V_3 * V_3 ;
F_6 (page, &cc->migratepages, lru)
V_83 ++ ;
F_6 (page, &cc->freepages, lru)
V_87 ++ ;
V_11 -> V_83 = V_83 ;
V_11 -> V_87 = V_87 ;
}
static T_4 F_72 ( struct V_13 * V_13 ,
struct V_10 * V_11 )
{
unsigned long V_66 , V_16 ;
V_66 = F_69 ( V_11 -> V_90 , V_13 -> V_15 ) ;
V_16 = F_46 ( V_66 + V_22 , V_22 ) ;
if ( V_16 > V_11 -> V_89 || ! F_15 ( V_66 ) ) {
V_11 -> V_90 = V_16 ;
return V_95 ;
}
V_66 = F_54 ( V_13 , V_11 , V_66 , V_16 , false ) ;
if ( ! V_66 || V_11 -> V_35 )
return V_96 ;
V_11 -> V_90 = V_66 ;
return V_97 ;
}
static int F_73 ( struct V_13 * V_13 ,
struct V_10 * V_11 )
{
unsigned long V_98 ;
if ( F_57 ( V_76 ) )
return V_99 ;
if ( V_11 -> V_89 <= V_11 -> V_90 ) {
if ( ! F_74 () )
V_13 -> V_21 = true ;
return V_100 ;
}
if ( V_11 -> V_43 == - 1 )
return V_101 ;
V_98 = F_75 ( V_13 ) ;
V_98 += ( 1 << V_11 -> V_43 ) ;
if ( ! F_76 ( V_13 , V_11 -> V_43 , V_98 , 0 , 0 ) )
return V_101 ;
if ( V_11 -> V_3 ) {
if ( * V_11 -> V_3 )
return V_99 ;
} else {
unsigned int V_43 ;
for ( V_43 = V_11 -> V_43 ; V_43 < V_44 ; V_43 ++ ) {
struct V_45 * V_46 = & V_13 -> V_45 [ V_11 -> V_43 ] ;
if ( ! F_36 ( & V_46 -> V_47 [ V_11 -> V_8 ] ) )
return V_99 ;
if ( V_11 -> V_43 >= V_38 && V_46 -> V_102 )
return V_99 ;
}
}
return V_101 ;
}
unsigned long F_77 ( struct V_13 * V_13 , int V_43 )
{
int V_103 ;
unsigned long V_98 ;
if ( V_43 == - 1 )
return V_101 ;
V_98 = F_75 ( V_13 ) + ( 2UL << V_43 ) ;
if ( ! F_76 ( V_13 , 0 , V_98 , 0 , 0 ) )
return V_104 ;
V_103 = F_78 ( V_13 , V_43 ) ;
if ( V_103 >= 0 && V_103 <= V_105 )
return V_104 ;
if ( V_103 == - 1000 && F_76 ( V_13 , V_43 , V_98 ,
0 , 0 ) )
return V_99 ;
return V_101 ;
}
static int F_79 ( struct V_13 * V_13 , struct V_10 * V_11 )
{
int V_106 ;
unsigned long V_14 = V_13 -> V_15 ;
unsigned long V_16 = V_13 -> V_15 + V_13 -> V_17 ;
V_106 = F_77 ( V_13 , V_11 -> V_43 ) ;
switch ( V_106 ) {
case V_99 :
case V_104 :
return V_106 ;
case V_101 :
;
}
V_11 -> V_90 = V_13 -> V_19 ;
V_11 -> V_89 = V_13 -> V_20 ;
if ( V_11 -> V_89 < V_14 || V_11 -> V_89 > V_16 ) {
V_11 -> V_89 = V_16 & ~ ( V_22 - 1 ) ;
V_13 -> V_20 = V_11 -> V_89 ;
}
if ( V_11 -> V_90 < V_14 || V_11 -> V_90 > V_16 ) {
V_11 -> V_90 = V_14 ;
V_13 -> V_19 = V_11 -> V_90 ;
}
if ( F_80 ( V_13 , V_11 -> V_43 ) && ! F_74 () )
F_13 ( V_13 ) ;
F_81 () ;
while ( ( V_106 = F_73 ( V_13 , V_11 ) ) == V_101 ) {
unsigned long V_107 , V_108 ;
int V_109 ;
switch ( F_72 ( V_13 , V_11 ) ) {
case V_96 :
V_106 = V_99 ;
F_82 ( & V_11 -> V_71 ) ;
V_11 -> V_83 = 0 ;
goto V_110;
case V_95 :
continue;
case V_97 :
;
}
V_107 = V_11 -> V_83 ;
V_109 = F_83 ( & V_11 -> V_71 , F_70 ,
( unsigned long ) V_11 , false ,
V_11 -> V_34 ? V_111 : V_112 ) ;
F_71 ( V_11 ) ;
V_108 = V_11 -> V_83 ;
F_84 ( V_113 ) ;
F_85 ( V_114 , V_107 - V_108 ) ;
if ( V_108 )
F_85 ( V_115 , V_108 ) ;
F_86 ( V_107 - V_108 ,
V_108 ) ;
if ( V_109 ) {
F_82 ( & V_11 -> V_71 ) ;
V_11 -> V_83 = 0 ;
if ( V_109 == - V_116 ) {
V_106 = V_99 ;
goto V_110;
}
}
F_35 ( V_11 ) ;
}
V_110:
V_11 -> V_87 -= F_1 ( & V_11 -> V_88 ) ;
F_63 ( V_11 -> V_87 != 0 ) ;
return V_106 ;
}
static unsigned long F_87 ( struct V_13 * V_13 ,
int V_43 , T_5 V_117 ,
bool V_34 , bool * V_35 ,
struct V_3 * * V_3 )
{
unsigned long V_106 ;
struct V_10 V_11 = {
. V_87 = 0 ,
. V_83 = 0 ,
. V_43 = V_43 ,
. V_8 = F_88 ( V_117 ) ,
. V_13 = V_13 ,
. V_34 = V_34 ,
. V_3 = V_3 ,
} ;
F_89 ( & V_11 . V_88 ) ;
F_89 ( & V_11 . V_71 ) ;
V_106 = F_79 ( V_13 , & V_11 ) ;
F_63 ( ! F_36 ( & V_11 . V_88 ) ) ;
F_63 ( ! F_36 ( & V_11 . V_71 ) ) ;
* V_35 = V_11 . V_35 ;
return V_106 ;
}
unsigned long F_90 ( struct V_118 * V_118 ,
int V_43 , T_5 V_117 , T_6 * V_119 ,
bool V_34 , bool * V_35 , struct V_3 * * V_3 )
{
enum V_120 V_121 = F_91 ( V_117 ) ;
int V_122 = V_117 & V_123 ;
int V_124 = V_117 & V_125 ;
struct V_126 * V_127 ;
struct V_13 * V_13 ;
int V_128 = V_104 ;
int V_129 = 0 ;
if ( ! V_43 || ! V_122 || ! V_124 )
return V_128 ;
F_84 ( V_130 ) ;
#ifdef F_92
if ( F_88 ( V_117 ) == V_9 )
V_129 |= V_131 ;
#endif
F_93 (zone, z, zonelist, high_zoneidx,
nodemask) {
int V_132 ;
V_132 = F_87 ( V_13 , V_43 , V_117 , V_34 ,
V_35 , V_3 ) ;
V_128 = F_69 ( V_132 , V_128 ) ;
if ( F_76 ( V_13 , V_43 , F_75 ( V_13 ) , 0 ,
V_129 ) )
break;
}
return V_128 ;
}
static int F_94 ( T_1 * V_23 , struct V_10 * V_11 )
{
int V_24 ;
struct V_13 * V_13 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
V_13 = & V_23 -> V_26 [ V_24 ] ;
if ( ! F_20 ( V_13 ) )
continue;
V_11 -> V_87 = 0 ;
V_11 -> V_83 = 0 ;
V_11 -> V_13 = V_13 ;
F_89 ( & V_11 -> V_88 ) ;
F_89 ( & V_11 -> V_71 ) ;
if ( V_11 -> V_43 == - 1 || ! F_95 ( V_13 , V_11 -> V_43 ) )
F_79 ( V_13 , V_11 ) ;
if ( V_11 -> V_43 > 0 ) {
int V_133 = F_76 ( V_13 , V_11 -> V_43 ,
F_75 ( V_13 ) , 0 , 0 ) ;
if ( V_133 && V_11 -> V_43 >= V_13 -> V_134 )
V_13 -> V_134 = V_11 -> V_43 + 1 ;
else if ( ! V_133 && V_11 -> V_34 )
F_96 ( V_13 , V_11 -> V_43 ) ;
}
F_63 ( ! F_36 ( & V_11 -> V_88 ) ) ;
F_63 ( ! F_36 ( & V_11 -> V_71 ) ) ;
}
return 0 ;
}
int F_97 ( T_1 * V_23 , int V_43 )
{
struct V_10 V_11 = {
. V_43 = V_43 ,
. V_34 = false ,
. V_3 = NULL ,
} ;
return F_94 ( V_23 , & V_11 ) ;
}
static int F_98 ( int V_135 )
{
struct V_10 V_11 = {
. V_43 = - 1 ,
. V_34 = true ,
. V_3 = NULL ,
} ;
return F_94 ( F_99 ( V_135 ) , & V_11 ) ;
}
static int F_100 ( void )
{
int V_135 ;
F_101 () ;
F_102 (nid)
F_98 ( V_135 ) ;
return V_100 ;
}
int F_103 ( struct V_136 * V_137 , int V_138 ,
void T_7 * V_139 , T_8 * V_140 , T_9 * V_141 )
{
if ( V_138 )
return F_100 () ;
return 0 ;
}
int F_104 ( struct V_136 * V_137 , int V_138 ,
void T_7 * V_139 , T_8 * V_140 , T_9 * V_141 )
{
F_105 ( V_137 , V_138 , V_139 , V_140 , V_141 ) ;
return 0 ;
}
T_10 F_106 ( struct V_142 * V_143 ,
struct V_144 * V_145 ,
const char * V_146 , T_8 V_5 )
{
int V_135 = V_143 -> V_147 ;
if ( V_135 >= 0 && V_135 < V_148 && F_107 ( V_135 ) ) {
F_101 () ;
F_98 ( V_135 ) ;
}
return V_5 ;
}
int F_108 ( struct V_149 * V_149 )
{
return F_109 ( & V_149 -> V_143 , & V_150 ) ;
}
void F_110 ( struct V_149 * V_149 )
{
return F_111 ( & V_149 -> V_143 , & V_150 ) ;
}
