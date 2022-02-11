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
V_16 -> V_21 [ 0 ] = V_17 ;
V_16 -> V_21 [ 1 ] = V_17 ;
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
bool V_30 , bool V_31 )
{
struct V_16 * V_16 = V_14 -> V_16 ;
unsigned long V_20 ;
if ( V_14 -> V_15 )
return;
if ( ! V_6 )
return;
if ( V_29 )
return;
if ( V_30 )
F_27 ( V_6 ) ;
V_20 = F_28 ( V_6 ) ;
if ( V_31 ) {
if ( V_14 -> V_32 )
return;
if ( V_20 > V_16 -> V_21 [ 0 ] )
V_16 -> V_21 [ 0 ] = V_20 ;
if ( V_14 -> V_33 != V_34 &&
V_20 > V_16 -> V_21 [ 1 ] )
V_16 -> V_21 [ 1 ] = V_20 ;
} else {
if ( V_14 -> V_35 )
return;
if ( V_20 < V_16 -> V_22 )
V_16 -> V_22 = V_20 ;
}
}
static inline bool F_15 ( struct V_13 * V_14 ,
struct V_6 * V_6 )
{
return true ;
}
static void F_26 ( struct V_13 * V_14 ,
struct V_6 * V_6 , unsigned long V_29 ,
bool V_30 , bool V_31 )
{
}
static inline bool F_29 ( T_2 * V_36 )
{
return F_30 () || F_31 ( V_36 ) ;
}
static bool F_32 ( T_2 * V_36 , unsigned long * V_37 ,
bool V_38 , struct V_13 * V_14 )
{
if ( F_29 ( V_36 ) ) {
if ( V_38 ) {
F_33 ( V_36 , * V_37 ) ;
V_38 = false ;
}
if ( V_14 -> V_33 == V_34 ) {
V_14 -> V_39 = true ;
return false ;
}
F_19 () ;
}
if ( ! V_38 )
F_34 ( V_36 , * V_37 ) ;
return true ;
}
static inline bool F_35 ( struct V_13 * V_14 )
{
if ( F_30 () ) {
if ( V_14 -> V_33 == V_34 ) {
V_14 -> V_39 = true ;
return true ;
}
F_19 () ;
}
return false ;
}
static bool F_36 ( struct V_6 * V_6 )
{
if ( F_37 ( V_6 ) && F_38 ( V_6 ) >= V_40 )
return false ;
if ( F_13 ( F_39 ( V_6 ) ) )
return true ;
return false ;
}
static unsigned long F_40 ( struct V_13 * V_14 ,
unsigned long V_41 ,
unsigned long V_19 ,
struct V_4 * V_5 ,
bool V_42 )
{
int V_43 = 0 , V_44 = 0 ;
struct V_6 * V_45 , * V_46 = NULL ;
unsigned long V_37 ;
bool V_38 = false ;
bool V_47 = false ;
V_45 = F_21 ( V_41 ) ;
for (; V_41 < V_19 ; V_41 ++ , V_45 ++ ) {
int V_48 , V_49 ;
struct V_6 * V_6 = V_45 ;
V_43 ++ ;
if ( ! F_41 ( V_41 ) )
goto V_50;
if ( ! V_46 )
V_46 = V_6 ;
if ( ! F_37 ( V_6 ) )
goto V_50;
V_38 = F_32 ( & V_14 -> V_16 -> V_36 , & V_37 ,
V_38 , V_14 ) ;
if ( ! V_38 )
break;
if ( ! V_42 && ! V_47 ) {
V_47 = true ;
if ( ! F_36 ( V_6 ) )
break;
}
if ( ! F_37 ( V_6 ) )
goto V_50;
V_48 = F_42 ( V_6 ) ;
V_44 += V_48 ;
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ ) {
F_43 ( & V_6 -> V_9 , V_5 ) ;
V_6 ++ ;
}
if ( V_48 ) {
V_41 += V_48 - 1 ;
V_45 += V_48 - 1 ;
continue;
}
V_50:
if ( V_42 )
break;
else
continue;
}
F_44 ( V_43 , V_44 ) ;
if ( V_42 && V_41 < V_19 )
V_44 = 0 ;
if ( V_38 )
F_33 ( & V_14 -> V_16 -> V_36 , V_37 ) ;
if ( V_41 == V_19 )
F_26 ( V_14 , V_46 , V_44 , true ,
false ) ;
F_3 ( V_51 , V_43 ) ;
if ( V_44 )
F_3 ( V_52 , V_44 ) ;
return V_44 ;
}
unsigned long
F_45 ( struct V_13 * V_14 ,
unsigned long V_17 , unsigned long V_19 )
{
unsigned long V_48 , V_20 , V_53 ;
F_46 ( V_5 ) ;
for ( V_20 = V_17 ; V_20 < V_19 ; V_20 += V_48 ) {
if ( ! F_20 ( V_20 ) || V_14 -> V_16 != F_22 ( F_21 ( V_20 ) ) )
break;
V_53 = F_47 ( V_20 + 1 , V_24 ) ;
V_53 = F_48 ( V_53 , V_19 ) ;
V_48 = F_40 ( V_14 , V_20 , V_53 ,
& V_5 , true ) ;
if ( ! V_48 )
break;
}
F_9 ( & V_5 ) ;
if ( V_20 < V_19 ) {
F_5 ( & V_5 ) ;
return 0 ;
}
return V_20 ;
}
static void F_49 ( struct V_16 * V_16 , bool V_38 , struct V_13 * V_14 )
{
struct V_6 * V_6 ;
unsigned int V_8 [ 2 ] = { 0 , } ;
F_10 (page, &cc->migratepages, lru)
V_8 [ ! ! F_50 ( V_6 ) ] ++ ;
if ( V_38 ) {
F_51 ( V_16 , V_54 , V_8 [ 0 ] ) ;
F_51 ( V_16 , V_55 , V_8 [ 1 ] ) ;
} else {
F_52 ( V_16 , V_54 , V_8 [ 0 ] ) ;
F_52 ( V_16 , V_55 , V_8 [ 1 ] ) ;
}
}
static bool F_53 ( struct V_16 * V_16 )
{
unsigned long V_56 , V_57 , V_48 ;
V_57 = F_54 ( V_16 , V_58 ) +
F_54 ( V_16 , V_59 ) ;
V_56 = F_54 ( V_16 , V_60 ) +
F_54 ( V_16 , V_61 ) ;
V_48 = F_54 ( V_16 , V_55 ) +
F_54 ( V_16 , V_54 ) ;
return V_48 > ( V_57 + V_56 ) / 2 ;
}
unsigned long
F_55 ( struct V_16 * V_16 , struct V_13 * V_14 ,
unsigned long V_62 , unsigned long V_19 , bool V_63 )
{
unsigned long V_64 = 0 , V_65 ;
unsigned long V_43 = 0 , V_29 = 0 ;
struct V_4 * V_66 = & V_14 -> V_67 ;
struct V_68 * V_68 ;
unsigned long V_37 ;
bool V_38 = false ;
struct V_6 * V_6 = NULL , * V_46 = NULL ;
bool V_30 = true ;
const T_3 V_33 = ( V_14 -> V_33 == V_34 ?
V_69 : 0 ) |
( V_63 ? V_70 : 0 ) ;
while ( F_56 ( F_53 ( V_16 ) ) ) {
if ( V_14 -> V_33 == V_34 )
return 0 ;
F_57 ( V_71 , V_72 / 10 ) ;
if ( F_58 ( V_73 ) )
return 0 ;
}
if ( F_35 ( V_14 ) )
return 0 ;
for (; V_62 < V_19 ; V_62 ++ ) {
if ( V_38 && ! ( V_62 % V_74 ) ) {
if ( F_29 ( & V_16 -> V_75 ) ) {
F_33 ( & V_16 -> V_75 , V_37 ) ;
V_38 = false ;
}
}
if ( ( V_62 & ( V_76 - 1 ) ) == 0 ) {
if ( ! F_20 ( V_62 ) ) {
V_62 += V_76 - 1 ;
continue;
}
}
if ( ! F_41 ( V_62 ) )
continue;
V_43 ++ ;
V_6 = F_21 ( V_62 ) ;
if ( F_22 ( V_6 ) != V_16 )
continue;
if ( ! V_46 )
V_46 = V_6 ;
V_65 = V_62 >> V_40 ;
if ( V_64 != V_65 ) {
int V_77 ;
V_64 = V_65 ;
if ( ! F_15 ( V_14 , V_6 ) )
goto V_78;
V_77 = F_39 ( V_6 ) ;
if ( V_14 -> V_33 == V_34 &&
! F_13 ( V_77 ) ) {
V_30 = false ;
goto V_78;
}
}
if ( F_37 ( V_6 ) )
continue;
if ( ! F_59 ( V_6 ) ) {
if ( F_56 ( F_60 ( V_6 ) ) ) {
if ( V_38 && F_61 ( V_6 ) ) {
goto V_79;
}
}
continue;
}
if ( F_62 ( V_6 ) ) {
if ( ! V_38 )
goto V_78;
V_62 += ( 1 << F_63 ( V_6 ) ) - 1 ;
continue;
}
if ( ! F_64 ( V_6 ) &&
F_65 ( V_6 ) > F_66 ( V_6 ) )
continue;
V_38 = F_32 ( & V_16 -> V_75 , & V_37 ,
V_38 , V_14 ) ;
if ( ! V_38 || F_58 ( V_73 ) )
break;
if ( ! F_59 ( V_6 ) )
continue;
if ( F_62 ( V_6 ) ) {
V_62 += ( 1 << F_63 ( V_6 ) ) - 1 ;
continue;
}
V_68 = F_67 ( V_6 , V_16 ) ;
if ( F_68 ( V_6 , V_33 ) != 0 )
continue;
F_69 ( F_70 ( V_6 ) , V_6 ) ;
F_71 ( V_6 , V_68 , F_72 ( V_6 ) ) ;
V_79:
V_14 -> V_32 = true ;
F_43 ( & V_6 -> V_9 , V_66 ) ;
V_14 -> V_80 ++ ;
V_29 ++ ;
if ( V_14 -> V_80 == V_81 ) {
++ V_62 ;
break;
}
continue;
V_78:
V_62 = F_47 ( V_62 + 1 , V_24 ) - 1 ;
}
F_49 ( V_16 , V_38 , V_14 ) ;
if ( V_38 )
F_33 ( & V_16 -> V_75 , V_37 ) ;
if ( V_62 == V_19 )
F_26 ( V_14 , V_46 , V_29 ,
V_30 , true ) ;
F_73 ( V_43 , V_29 ) ;
F_3 ( V_82 , V_43 ) ;
if ( V_29 )
F_3 ( V_52 , V_29 ) ;
return V_62 ;
}
static void F_74 ( struct V_16 * V_16 ,
struct V_13 * V_14 )
{
struct V_6 * V_6 ;
unsigned long V_83 ;
unsigned long V_53 ;
unsigned long V_62 ;
int V_84 = V_14 -> V_84 ;
struct V_4 * V_5 = & V_14 -> V_85 ;
V_83 = V_14 -> V_86 & ~ ( V_24 - 1 ) ;
V_53 = F_48 ( V_83 + V_24 ,
F_18 ( V_16 ) ) ;
V_62 = F_47 ( V_14 -> V_87 + 1 , V_24 ) ;
for (; V_83 >= V_62 && V_14 -> V_80 > V_84 ;
V_53 = V_83 ,
V_83 -= V_24 ) {
unsigned long V_48 ;
if ( ! ( V_83 % ( V_74 * V_24 ) )
&& F_35 ( V_14 ) )
break;
if ( ! F_20 ( V_83 ) )
continue;
V_6 = F_21 ( V_83 ) ;
if ( F_22 ( V_6 ) != V_16 )
continue;
if ( ! F_36 ( V_6 ) )
continue;
if ( ! F_15 ( V_14 , V_6 ) )
continue;
V_14 -> V_86 = V_83 ;
V_48 = F_40 ( V_14 , V_83 ,
V_53 , V_5 , false ) ;
V_84 += V_48 ;
if ( V_48 )
V_14 -> V_35 = true ;
if ( V_14 -> V_39 )
break;
}
F_9 ( V_5 ) ;
if ( V_83 < V_62 )
V_14 -> V_86 = V_14 -> V_87 ;
V_14 -> V_84 = V_84 ;
}
static struct V_6 * F_75 ( struct V_6 * V_88 ,
unsigned long V_89 ,
int * * V_90 )
{
struct V_13 * V_14 = (struct V_13 * ) V_89 ;
struct V_6 * V_91 ;
if ( F_76 ( & V_14 -> V_85 ) ) {
if ( ! V_14 -> V_39 )
F_74 ( V_14 -> V_16 , V_14 ) ;
if ( F_76 ( & V_14 -> V_85 ) )
return NULL ;
}
V_91 = F_77 ( V_14 -> V_85 . V_7 , struct V_6 , V_9 ) ;
F_7 ( & V_91 -> V_9 ) ;
V_14 -> V_84 -- ;
return V_91 ;
}
static void F_78 ( struct V_6 * V_6 , unsigned long V_89 )
{
struct V_13 * V_14 = (struct V_13 * ) V_89 ;
F_43 ( & V_6 -> V_9 , & V_14 -> V_85 ) ;
V_14 -> V_84 ++ ;
}
static T_4 F_79 ( struct V_16 * V_16 ,
struct V_13 * V_14 )
{
unsigned long V_62 , V_19 ;
V_62 = F_80 ( V_14 -> V_87 , V_16 -> V_18 ) ;
V_19 = F_47 ( V_62 + 1 , V_24 ) ;
if ( V_19 > V_14 -> V_86 || ! F_20 ( V_62 ) ) {
V_14 -> V_87 = V_19 ;
return V_92 ;
}
V_62 = F_55 ( V_16 , V_14 , V_62 , V_19 , false ) ;
if ( ! V_62 || V_14 -> V_39 )
return V_93 ;
V_14 -> V_87 = V_62 ;
return V_94 ;
}
static int F_81 ( struct V_16 * V_16 ,
struct V_13 * V_14 )
{
unsigned int V_95 ;
unsigned long V_96 ;
if ( V_14 -> V_39 || F_58 ( V_73 ) )
return V_97 ;
if ( V_14 -> V_86 <= V_14 -> V_87 ) {
V_16 -> V_21 [ 0 ] = V_16 -> V_18 ;
V_16 -> V_21 [ 1 ] = V_16 -> V_18 ;
V_16 -> V_22 = F_18 ( V_16 ) ;
if ( ! F_82 () )
V_16 -> V_23 = true ;
return V_98 ;
}
if ( V_14 -> V_95 == - 1 )
return V_99 ;
V_96 = F_83 ( V_16 ) ;
V_96 += ( 1 << V_14 -> V_95 ) ;
if ( ! F_84 ( V_16 , V_14 -> V_95 , V_96 , 0 , 0 ) )
return V_99 ;
for ( V_95 = V_14 -> V_95 ; V_95 < V_100 ; V_95 ++ ) {
struct V_101 * V_102 = & V_16 -> V_101 [ V_95 ] ;
if ( ! F_76 ( & V_102 -> V_103 [ V_14 -> V_11 ] ) )
return V_97 ;
if ( V_14 -> V_95 >= V_40 && V_102 -> V_104 )
return V_97 ;
}
return V_99 ;
}
unsigned long F_85 ( struct V_16 * V_16 , int V_95 )
{
int V_105 ;
unsigned long V_96 ;
if ( V_95 == - 1 )
return V_99 ;
V_96 = F_83 ( V_16 ) + ( 2UL << V_95 ) ;
if ( ! F_84 ( V_16 , 0 , V_96 , 0 , 0 ) )
return V_106 ;
V_105 = F_86 ( V_16 , V_95 ) ;
if ( V_105 >= 0 && V_105 <= V_107 )
return V_106 ;
if ( V_105 == - 1000 && F_84 ( V_16 , V_95 , V_96 ,
0 , 0 ) )
return V_97 ;
return V_99 ;
}
static int F_87 ( struct V_16 * V_16 , struct V_13 * V_14 )
{
int V_108 ;
unsigned long V_17 = V_16 -> V_18 ;
unsigned long V_19 = F_18 ( V_16 ) ;
const bool V_109 = V_14 -> V_33 != V_34 ;
V_108 = F_85 ( V_16 , V_14 -> V_95 ) ;
switch ( V_108 ) {
case V_97 :
case V_106 :
return V_108 ;
case V_99 :
;
}
if ( F_88 ( V_16 , V_14 -> V_95 ) && ! F_82 () )
F_17 ( V_16 ) ;
V_14 -> V_87 = V_16 -> V_21 [ V_109 ] ;
V_14 -> V_86 = V_16 -> V_22 ;
if ( V_14 -> V_86 < V_17 || V_14 -> V_86 > V_19 ) {
V_14 -> V_86 = V_19 & ~ ( V_24 - 1 ) ;
V_16 -> V_22 = V_14 -> V_86 ;
}
if ( V_14 -> V_87 < V_17 || V_14 -> V_87 > V_19 ) {
V_14 -> V_87 = V_17 ;
V_16 -> V_21 [ 0 ] = V_14 -> V_87 ;
V_16 -> V_21 [ 1 ] = V_14 -> V_87 ;
}
F_89 ( V_17 , V_14 -> V_87 , V_14 -> V_86 , V_19 ) ;
F_90 () ;
while ( ( V_108 = F_81 ( V_16 , V_14 ) ) == V_99 ) {
int V_110 ;
switch ( F_79 ( V_16 , V_14 ) ) {
case V_93 :
V_108 = V_97 ;
F_91 ( & V_14 -> V_67 ) ;
V_14 -> V_80 = 0 ;
goto V_111;
case V_92 :
continue;
case V_94 :
;
}
if ( ! V_14 -> V_80 )
continue;
V_110 = F_92 ( & V_14 -> V_67 , F_75 ,
F_78 , ( unsigned long ) V_14 , V_14 -> V_33 ,
V_112 ) ;
F_93 ( V_14 -> V_80 , V_110 ,
& V_14 -> V_67 ) ;
V_14 -> V_80 = 0 ;
if ( V_110 ) {
F_91 ( & V_14 -> V_67 ) ;
if ( V_110 == - V_113 && V_14 -> V_86 > V_14 -> V_87 ) {
V_108 = V_97 ;
goto V_111;
}
}
}
V_111:
V_14 -> V_84 -= F_5 ( & V_14 -> V_85 ) ;
F_94 ( V_14 -> V_84 != 0 ) ;
F_95 ( V_108 ) ;
return V_108 ;
}
static unsigned long F_96 ( struct V_16 * V_16 , int V_95 ,
T_5 V_114 , enum V_115 V_33 , bool * V_39 )
{
unsigned long V_108 ;
struct V_13 V_14 = {
. V_84 = 0 ,
. V_80 = 0 ,
. V_95 = V_95 ,
. V_11 = F_97 ( V_114 ) ,
. V_16 = V_16 ,
. V_33 = V_33 ,
} ;
F_98 ( & V_14 . V_85 ) ;
F_98 ( & V_14 . V_67 ) ;
V_108 = F_87 ( V_16 , & V_14 ) ;
F_94 ( ! F_76 ( & V_14 . V_85 ) ) ;
F_94 ( ! F_76 ( & V_14 . V_67 ) ) ;
* V_39 = V_14 . V_39 ;
return V_108 ;
}
unsigned long F_99 ( struct V_116 * V_116 ,
int V_95 , T_5 V_114 , T_6 * V_117 ,
enum V_115 V_33 , bool * V_39 )
{
enum V_118 V_119 = F_100 ( V_114 ) ;
int V_120 = V_114 & V_121 ;
int V_122 = V_114 & V_123 ;
struct V_124 * V_125 ;
struct V_16 * V_16 ;
int V_126 = V_106 ;
int V_127 = 0 ;
if ( ! V_95 || ! V_120 || ! V_122 )
return V_126 ;
F_1 ( V_128 ) ;
#ifdef F_101
if ( F_97 ( V_114 ) == V_12 )
V_127 |= V_129 ;
#endif
F_102 (zone, z, zonelist, high_zoneidx,
nodemask) {
int V_130 ;
V_130 = F_96 ( V_16 , V_95 , V_114 , V_33 ,
V_39 ) ;
V_126 = F_80 ( V_130 , V_126 ) ;
if ( F_84 ( V_16 , V_95 , F_83 ( V_16 ) , 0 ,
V_127 ) )
break;
}
return V_126 ;
}
static void F_103 ( T_1 * V_25 , struct V_13 * V_14 )
{
int V_26 ;
struct V_16 * V_16 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
V_16 = & V_25 -> V_28 [ V_26 ] ;
if ( ! F_25 ( V_16 ) )
continue;
V_14 -> V_84 = 0 ;
V_14 -> V_80 = 0 ;
V_14 -> V_16 = V_16 ;
F_98 ( & V_14 -> V_85 ) ;
F_98 ( & V_14 -> V_67 ) ;
if ( V_14 -> V_95 == - 1 || ! F_104 ( V_16 , V_14 -> V_95 ) )
F_87 ( V_16 , V_14 ) ;
if ( V_14 -> V_95 > 0 ) {
if ( F_84 ( V_16 , V_14 -> V_95 ,
F_83 ( V_16 ) , 0 , 0 ) )
F_105 ( V_16 , V_14 -> V_95 , false ) ;
}
F_94 ( ! F_76 ( & V_14 -> V_85 ) ) ;
F_94 ( ! F_76 ( & V_14 -> V_67 ) ) ;
}
}
void F_106 ( T_1 * V_25 , int V_95 )
{
struct V_13 V_14 = {
. V_95 = V_95 ,
. V_33 = V_34 ,
} ;
if ( ! V_95 )
return;
F_103 ( V_25 , & V_14 ) ;
}
static void F_107 ( int V_131 )
{
struct V_13 V_14 = {
. V_95 = - 1 ,
. V_33 = V_132 ,
. V_15 = true ,
} ;
F_103 ( F_108 ( V_131 ) , & V_14 ) ;
}
static void F_109 ( void )
{
int V_131 ;
F_110 () ;
F_111 (nid)
F_107 ( V_131 ) ;
}
int F_112 ( struct V_133 * V_134 , int V_135 ,
void T_7 * V_136 , T_8 * V_137 , T_9 * V_138 )
{
if ( V_135 )
F_109 () ;
return 0 ;
}
int F_113 ( struct V_133 * V_134 , int V_135 ,
void T_7 * V_136 , T_8 * V_137 , T_9 * V_138 )
{
F_114 ( V_134 , V_135 , V_136 , V_137 , V_138 ) ;
return 0 ;
}
static T_10 F_115 ( struct V_139 * V_140 ,
struct V_141 * V_142 ,
const char * V_143 , T_8 V_8 )
{
int V_131 = V_140 -> V_144 ;
if ( V_131 >= 0 && V_131 < V_145 && F_116 ( V_131 ) ) {
F_110 () ;
F_107 ( V_131 ) ;
}
return V_8 ;
}
int F_117 ( struct V_146 * V_146 )
{
return F_118 ( & V_146 -> V_140 , & V_147 ) ;
}
void F_119 ( struct V_146 * V_146 )
{
return F_120 ( & V_146 -> V_140 , & V_147 ) ;
}
