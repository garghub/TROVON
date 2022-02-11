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
unsigned long V_19 = V_16 -> V_18 + V_16 -> V_20 ;
unsigned long V_21 ;
V_16 -> V_22 = V_17 ;
V_16 -> V_23 = V_19 ;
V_16 -> V_24 = false ;
for ( V_21 = V_17 ; V_21 < V_19 ; V_21 += V_25 ) {
struct V_6 * V_6 ;
F_18 () ;
if ( ! F_19 ( V_21 ) )
continue;
V_6 = F_20 ( V_21 ) ;
if ( V_16 != F_21 ( V_6 ) )
continue;
F_22 ( V_6 ) ;
}
}
void F_23 ( T_1 * V_26 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
struct V_16 * V_16 = & V_26 -> V_29 [ V_27 ] ;
if ( ! F_24 ( V_16 ) )
continue;
if ( V_16 -> V_24 )
F_17 ( V_16 ) ;
}
}
static void F_25 ( struct V_13 * V_14 ,
struct V_6 * V_6 , unsigned long V_30 ,
bool V_31 )
{
struct V_16 * V_16 = V_14 -> V_16 ;
if ( ! V_6 )
return;
if ( ! V_30 ) {
unsigned long V_21 = F_26 ( V_6 ) ;
F_27 ( V_6 ) ;
if ( V_31 ) {
if ( ! V_14 -> V_32 &&
V_21 > V_16 -> V_22 )
V_16 -> V_22 = V_21 ;
} else {
if ( ! V_14 -> V_33 &&
V_21 < V_16 -> V_23 )
V_16 -> V_23 = V_21 ;
}
}
}
static inline bool F_15 ( struct V_13 * V_14 ,
struct V_6 * V_6 )
{
return true ;
}
static void F_25 ( struct V_13 * V_14 ,
struct V_6 * V_6 , unsigned long V_30 ,
bool V_31 )
{
}
static inline bool F_28 ( T_2 * V_34 )
{
return F_29 () || F_30 ( V_34 ) ;
}
static bool F_31 ( T_2 * V_34 , unsigned long * V_35 ,
bool V_36 , struct V_13 * V_14 )
{
if ( F_28 ( V_34 ) ) {
if ( V_36 ) {
F_32 ( V_34 , * V_35 ) ;
V_36 = false ;
}
if ( ! V_14 -> V_37 ) {
V_14 -> V_38 = true ;
return false ;
}
F_18 () ;
}
if ( ! V_36 )
F_33 ( V_34 , * V_35 ) ;
return true ;
}
static inline bool F_34 ( T_2 * V_34 ,
unsigned long * V_35 , struct V_13 * V_14 )
{
return F_31 ( V_34 , V_35 , false , V_14 ) ;
}
static bool F_35 ( struct V_6 * V_6 )
{
int V_11 = F_36 ( V_6 ) ;
if ( V_11 == V_39 || V_11 == V_40 )
return false ;
if ( F_37 ( V_6 ) && F_38 ( V_6 ) >= V_41 )
return true ;
if ( F_13 ( V_11 ) )
return true ;
return false ;
}
static unsigned long F_39 ( struct V_13 * V_14 ,
unsigned long V_42 ,
unsigned long V_19 ,
struct V_4 * V_5 ,
bool V_43 )
{
int V_44 = 0 , V_45 = 0 ;
struct V_6 * V_46 , * V_47 = NULL ;
unsigned long V_48 = V_19 - V_42 ;
unsigned long V_35 ;
bool V_36 = false ;
V_46 = F_20 ( V_42 ) ;
for (; V_42 < V_19 ; V_42 ++ , V_46 ++ ) {
int V_49 , V_50 ;
struct V_6 * V_6 = V_46 ;
V_44 ++ ;
if ( ! F_40 ( V_42 ) )
continue;
if ( ! V_47 )
V_47 = V_6 ;
if ( ! F_37 ( V_6 ) )
continue;
V_36 = F_31 ( & V_14 -> V_16 -> V_34 , & V_35 ,
V_36 , V_14 ) ;
if ( ! V_36 )
break;
if ( ! V_43 && ! F_35 ( V_6 ) )
break;
if ( ! F_37 ( V_6 ) )
continue;
V_49 = F_41 ( V_6 ) ;
if ( ! V_49 && V_43 )
break;
V_45 += V_49 ;
for ( V_50 = 0 ; V_50 < V_49 ; V_50 ++ ) {
F_42 ( & V_6 -> V_9 , V_5 ) ;
V_6 ++ ;
}
if ( V_49 ) {
V_42 += V_49 - 1 ;
V_46 += V_49 - 1 ;
}
}
F_43 ( V_44 , V_45 ) ;
if ( V_43 && V_48 > V_45 )
V_45 = 0 ;
if ( V_36 )
F_32 ( & V_14 -> V_16 -> V_34 , V_35 ) ;
if ( V_42 == V_19 )
F_25 ( V_14 , V_47 , V_45 , false ) ;
F_3 ( V_51 , V_44 ) ;
if ( V_45 )
F_3 ( V_52 , V_45 ) ;
return V_45 ;
}
unsigned long
F_44 ( struct V_13 * V_14 ,
unsigned long V_17 , unsigned long V_19 )
{
unsigned long V_49 , V_21 , V_53 ;
F_45 ( V_5 ) ;
for ( V_21 = V_17 ; V_21 < V_19 ; V_21 += V_49 ) {
if ( ! F_19 ( V_21 ) || V_14 -> V_16 != F_21 ( F_20 ( V_21 ) ) )
break;
V_53 = F_46 ( V_21 + 1 , V_25 ) ;
V_53 = F_47 ( V_53 , V_19 ) ;
V_49 = F_39 ( V_14 , V_21 , V_53 ,
& V_5 , true ) ;
if ( ! V_49 )
break;
}
F_9 ( & V_5 ) ;
if ( V_21 < V_19 ) {
F_5 ( & V_5 ) ;
return 0 ;
}
return V_21 ;
}
static void F_48 ( struct V_16 * V_16 , bool V_36 , struct V_13 * V_14 )
{
struct V_6 * V_6 ;
unsigned int V_8 [ 2 ] = { 0 , } ;
F_10 (page, &cc->migratepages, lru)
V_8 [ ! ! F_49 ( V_6 ) ] ++ ;
if ( V_36 ) {
F_50 ( V_16 , V_54 , V_8 [ 0 ] ) ;
F_50 ( V_16 , V_55 , V_8 [ 1 ] ) ;
} else {
F_51 ( V_16 , V_54 , V_8 [ 0 ] ) ;
F_51 ( V_16 , V_55 , V_8 [ 1 ] ) ;
}
}
static bool F_52 ( struct V_16 * V_16 )
{
unsigned long V_56 , V_57 , V_49 ;
V_57 = F_53 ( V_16 , V_58 ) +
F_53 ( V_16 , V_59 ) ;
V_56 = F_53 ( V_16 , V_60 ) +
F_53 ( V_16 , V_61 ) ;
V_49 = F_53 ( V_16 , V_55 ) +
F_53 ( V_16 , V_54 ) ;
return V_49 > ( V_57 + V_56 ) / 2 ;
}
unsigned long
F_54 ( struct V_16 * V_16 , struct V_13 * V_14 ,
unsigned long V_62 , unsigned long V_19 , bool V_63 )
{
unsigned long V_64 = 0 , V_65 ;
unsigned long V_44 = 0 , V_30 = 0 ;
struct V_4 * V_66 = & V_14 -> V_67 ;
T_3 V_68 = 0 ;
struct V_69 * V_69 ;
unsigned long V_35 ;
bool V_36 = false ;
struct V_6 * V_6 = NULL , * V_47 = NULL ;
while ( F_55 ( F_52 ( V_16 ) ) ) {
if ( ! V_14 -> V_37 )
return 0 ;
F_56 ( V_70 , V_71 / 10 ) ;
if ( F_57 ( V_72 ) )
return 0 ;
}
F_18 () ;
for (; V_62 < V_19 ; V_62 ++ ) {
if ( V_36 && ! ( ( V_62 + 1 ) % V_73 ) ) {
if ( F_28 ( & V_16 -> V_74 ) ) {
F_32 ( & V_16 -> V_74 , V_35 ) ;
V_36 = false ;
}
}
if ( ( V_62 & ( V_75 - 1 ) ) == 0 ) {
if ( ! F_19 ( V_62 ) ) {
V_62 += V_75 - 1 ;
continue;
}
}
if ( ! F_40 ( V_62 ) )
continue;
V_44 ++ ;
V_6 = F_20 ( V_62 ) ;
if ( F_21 ( V_6 ) != V_16 )
continue;
if ( ! V_47 )
V_47 = V_6 ;
V_65 = V_62 >> V_41 ;
if ( ! F_15 ( V_14 , V_6 ) )
goto V_76;
if ( F_37 ( V_6 ) )
continue;
if ( ! V_14 -> V_37 && V_64 != V_65 &&
! F_13 ( F_36 ( V_6 ) ) ) {
V_14 -> V_32 = true ;
goto V_76;
}
if ( ! F_58 ( V_6 ) ) {
if ( F_55 ( F_59 ( V_6 ) ) ) {
if ( V_36 && F_60 ( V_6 ) ) {
V_14 -> V_32 = true ;
F_42 ( & V_6 -> V_9 , V_66 ) ;
V_14 -> V_77 ++ ;
V_30 ++ ;
goto V_78;
}
}
continue;
}
if ( F_61 ( V_6 ) ) {
if ( ! V_36 )
goto V_76;
V_62 += ( 1 << F_62 ( V_6 ) ) - 1 ;
continue;
}
V_36 = F_31 ( & V_16 -> V_74 , & V_35 ,
V_36 , V_14 ) ;
if ( ! V_36 || F_57 ( V_72 ) )
break;
if ( ! F_58 ( V_6 ) )
continue;
if ( F_61 ( V_6 ) ) {
V_62 += ( 1 << F_62 ( V_6 ) ) - 1 ;
continue;
}
if ( ! V_14 -> V_37 )
V_68 |= V_79 ;
if ( V_63 )
V_68 |= V_80 ;
V_69 = F_63 ( V_6 , V_16 ) ;
if ( F_64 ( V_6 , V_68 ) != 0 )
continue;
F_65 ( F_66 ( V_6 ) ) ;
V_14 -> V_32 = true ;
F_67 ( V_6 , V_69 , F_68 ( V_6 ) ) ;
F_42 ( & V_6 -> V_9 , V_66 ) ;
V_14 -> V_77 ++ ;
V_30 ++ ;
V_78:
if ( V_14 -> V_77 == V_81 ) {
++ V_62 ;
break;
}
continue;
V_76:
V_62 += V_25 ;
V_62 = F_46 ( V_62 , V_25 ) - 1 ;
V_64 = V_65 ;
}
F_48 ( V_16 , V_36 , V_14 ) ;
if ( V_36 )
F_32 ( & V_16 -> V_74 , V_35 ) ;
if ( V_62 == V_19 )
F_25 ( V_14 , V_47 , V_30 , true ) ;
F_69 ( V_44 , V_30 ) ;
F_3 ( V_82 , V_44 ) ;
if ( V_30 )
F_3 ( V_52 , V_30 ) ;
return V_62 ;
}
static void F_70 ( struct V_16 * V_16 ,
struct V_13 * V_14 )
{
struct V_6 * V_6 ;
unsigned long V_83 , V_62 , V_21 , V_84 , V_19 ;
int V_85 = V_14 -> V_85 ;
struct V_4 * V_5 = & V_14 -> V_86 ;
V_21 = V_14 -> V_87 ;
V_62 = V_14 -> V_88 + V_25 ;
V_83 = F_47 ( V_62 , V_21 ) ;
V_84 = V_16 -> V_18 + V_16 -> V_20 ;
for (; V_21 > V_62 && V_14 -> V_77 > V_85 ;
V_21 -= V_25 ) {
unsigned long V_49 ;
if ( ! F_19 ( V_21 ) )
continue;
V_6 = F_20 ( V_21 ) ;
if ( F_21 ( V_6 ) != V_16 )
continue;
if ( ! F_35 ( V_6 ) )
continue;
if ( ! F_15 ( V_14 , V_6 ) )
continue;
V_49 = 0 ;
V_19 = F_46 ( V_21 + 1 , V_25 ) ;
V_19 = F_47 ( V_19 , V_84 ) ;
V_49 = F_39 ( V_14 , V_21 , V_19 ,
V_5 , false ) ;
V_85 += V_49 ;
if ( V_49 ) {
V_14 -> V_33 = true ;
V_83 = F_71 ( V_83 , V_21 ) ;
}
}
F_9 ( V_5 ) ;
V_14 -> V_87 = V_83 ;
V_14 -> V_85 = V_85 ;
}
static struct V_6 * F_72 ( struct V_6 * V_89 ,
unsigned long V_90 ,
int * * V_91 )
{
struct V_13 * V_14 = (struct V_13 * ) V_90 ;
struct V_6 * V_92 ;
if ( F_73 ( & V_14 -> V_86 ) ) {
F_70 ( V_14 -> V_16 , V_14 ) ;
if ( F_73 ( & V_14 -> V_86 ) )
return NULL ;
}
V_92 = F_74 ( V_14 -> V_86 . V_7 , struct V_6 , V_9 ) ;
F_7 ( & V_92 -> V_9 ) ;
V_14 -> V_85 -- ;
return V_92 ;
}
static void F_75 ( struct V_13 * V_14 )
{
int V_77 = 0 ;
int V_85 = 0 ;
struct V_6 * V_6 ;
F_10 (page, &cc->migratepages, lru)
V_77 ++ ;
F_10 (page, &cc->freepages, lru)
V_85 ++ ;
V_14 -> V_77 = V_77 ;
V_14 -> V_85 = V_85 ;
}
static T_4 F_76 ( struct V_16 * V_16 ,
struct V_13 * V_14 )
{
unsigned long V_62 , V_19 ;
V_62 = F_71 ( V_14 -> V_88 , V_16 -> V_18 ) ;
V_19 = F_46 ( V_62 + V_25 , V_25 ) ;
if ( V_19 > V_14 -> V_87 || ! F_19 ( V_62 ) ) {
V_14 -> V_88 = V_19 ;
return V_93 ;
}
V_62 = F_54 ( V_16 , V_14 , V_62 , V_19 , false ) ;
if ( ! V_62 || V_14 -> V_38 )
return V_94 ;
V_14 -> V_88 = V_62 ;
return V_95 ;
}
static int F_77 ( struct V_16 * V_16 ,
struct V_13 * V_14 )
{
unsigned int V_96 ;
unsigned long V_97 ;
if ( F_57 ( V_72 ) )
return V_98 ;
if ( V_14 -> V_87 <= V_14 -> V_88 ) {
if ( ! F_78 () )
V_16 -> V_24 = true ;
return V_99 ;
}
if ( V_14 -> V_96 == - 1 )
return V_100 ;
V_97 = F_79 ( V_16 ) ;
V_97 += ( 1 << V_14 -> V_96 ) ;
if ( ! F_80 ( V_16 , V_14 -> V_96 , V_97 , 0 , 0 ) )
return V_100 ;
for ( V_96 = V_14 -> V_96 ; V_96 < V_101 ; V_96 ++ ) {
struct V_102 * V_103 = & V_16 -> V_102 [ V_96 ] ;
if ( ! F_73 ( & V_103 -> V_104 [ V_14 -> V_11 ] ) )
return V_98 ;
if ( V_14 -> V_96 >= V_41 && V_103 -> V_105 )
return V_98 ;
}
return V_100 ;
}
unsigned long F_81 ( struct V_16 * V_16 , int V_96 )
{
int V_106 ;
unsigned long V_97 ;
if ( V_96 == - 1 )
return V_100 ;
V_97 = F_79 ( V_16 ) + ( 2UL << V_96 ) ;
if ( ! F_80 ( V_16 , 0 , V_97 , 0 , 0 ) )
return V_107 ;
V_106 = F_82 ( V_16 , V_96 ) ;
if ( V_106 >= 0 && V_106 <= V_108 )
return V_107 ;
if ( V_106 == - 1000 && F_80 ( V_16 , V_96 , V_97 ,
0 , 0 ) )
return V_98 ;
return V_100 ;
}
static int F_83 ( struct V_16 * V_16 , struct V_13 * V_14 )
{
int V_109 ;
unsigned long V_17 = V_16 -> V_18 ;
unsigned long V_19 = V_16 -> V_18 + V_16 -> V_20 ;
V_109 = F_81 ( V_16 , V_14 -> V_96 ) ;
switch ( V_109 ) {
case V_98 :
case V_107 :
return V_109 ;
case V_100 :
;
}
V_14 -> V_88 = V_16 -> V_22 ;
V_14 -> V_87 = V_16 -> V_23 ;
if ( V_14 -> V_87 < V_17 || V_14 -> V_87 > V_19 ) {
V_14 -> V_87 = V_19 & ~ ( V_25 - 1 ) ;
V_16 -> V_23 = V_14 -> V_87 ;
}
if ( V_14 -> V_88 < V_17 || V_14 -> V_88 > V_19 ) {
V_14 -> V_88 = V_17 ;
V_16 -> V_22 = V_14 -> V_88 ;
}
if ( F_84 ( V_16 , V_14 -> V_96 ) && ! F_78 () )
F_17 ( V_16 ) ;
F_85 () ;
while ( ( V_109 = F_77 ( V_16 , V_14 ) ) == V_100 ) {
unsigned long V_110 , V_111 ;
int V_112 ;
switch ( F_76 ( V_16 , V_14 ) ) {
case V_94 :
V_109 = V_98 ;
F_86 ( & V_14 -> V_67 ) ;
V_14 -> V_77 = 0 ;
goto V_113;
case V_93 :
continue;
case V_95 :
;
}
V_110 = V_14 -> V_77 ;
V_112 = F_87 ( & V_14 -> V_67 , F_72 ,
( unsigned long ) V_14 , false ,
V_14 -> V_37 ? V_114 : V_115 ,
V_116 ) ;
F_75 ( V_14 ) ;
V_111 = V_14 -> V_77 ;
F_88 ( V_110 - V_111 ,
V_111 ) ;
if ( V_112 ) {
F_86 ( & V_14 -> V_67 ) ;
V_14 -> V_77 = 0 ;
if ( V_112 == - V_117 ) {
V_109 = V_98 ;
goto V_113;
}
}
}
V_113:
V_14 -> V_85 -= F_5 ( & V_14 -> V_86 ) ;
F_65 ( V_14 -> V_85 != 0 ) ;
return V_109 ;
}
static unsigned long F_89 ( struct V_16 * V_16 ,
int V_96 , T_5 V_118 ,
bool V_37 , bool * V_38 )
{
unsigned long V_109 ;
struct V_13 V_14 = {
. V_85 = 0 ,
. V_77 = 0 ,
. V_96 = V_96 ,
. V_11 = F_90 ( V_118 ) ,
. V_16 = V_16 ,
. V_37 = V_37 ,
} ;
F_91 ( & V_14 . V_86 ) ;
F_91 ( & V_14 . V_67 ) ;
V_109 = F_83 ( V_16 , & V_14 ) ;
F_65 ( ! F_73 ( & V_14 . V_86 ) ) ;
F_65 ( ! F_73 ( & V_14 . V_67 ) ) ;
* V_38 = V_14 . V_38 ;
return V_109 ;
}
unsigned long F_92 ( struct V_119 * V_119 ,
int V_96 , T_5 V_118 , T_6 * V_120 ,
bool V_37 , bool * V_38 )
{
enum V_121 V_122 = F_93 ( V_118 ) ;
int V_123 = V_118 & V_124 ;
int V_125 = V_118 & V_126 ;
struct V_127 * V_128 ;
struct V_16 * V_16 ;
int V_129 = V_107 ;
int V_130 = 0 ;
if ( ! V_96 || ! V_123 || ! V_125 )
return V_129 ;
F_1 ( V_131 ) ;
#ifdef F_94
if ( F_90 ( V_118 ) == V_12 )
V_130 |= V_132 ;
#endif
F_95 (zone, z, zonelist, high_zoneidx,
nodemask) {
int V_133 ;
V_133 = F_89 ( V_16 , V_96 , V_118 , V_37 ,
V_38 ) ;
V_129 = F_71 ( V_133 , V_129 ) ;
if ( F_80 ( V_16 , V_96 , F_79 ( V_16 ) , 0 ,
V_130 ) )
break;
}
return V_129 ;
}
static int F_96 ( T_1 * V_26 , struct V_13 * V_14 )
{
int V_27 ;
struct V_16 * V_16 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
V_16 = & V_26 -> V_29 [ V_27 ] ;
if ( ! F_24 ( V_16 ) )
continue;
V_14 -> V_85 = 0 ;
V_14 -> V_77 = 0 ;
V_14 -> V_16 = V_16 ;
F_91 ( & V_14 -> V_86 ) ;
F_91 ( & V_14 -> V_67 ) ;
if ( V_14 -> V_96 == - 1 || ! F_97 ( V_16 , V_14 -> V_96 ) )
F_83 ( V_16 , V_14 ) ;
if ( V_14 -> V_96 > 0 ) {
int V_134 = F_80 ( V_16 , V_14 -> V_96 ,
F_79 ( V_16 ) , 0 , 0 ) ;
if ( V_134 && V_14 -> V_96 >= V_16 -> V_135 )
V_16 -> V_135 = V_14 -> V_96 + 1 ;
else if ( ! V_134 && V_14 -> V_37 )
F_98 ( V_16 , V_14 -> V_96 ) ;
}
F_65 ( ! F_73 ( & V_14 -> V_86 ) ) ;
F_65 ( ! F_73 ( & V_14 -> V_67 ) ) ;
}
return 0 ;
}
int F_99 ( T_1 * V_26 , int V_96 )
{
struct V_13 V_14 = {
. V_96 = V_96 ,
. V_37 = false ,
} ;
return F_96 ( V_26 , & V_14 ) ;
}
static int F_100 ( int V_136 )
{
struct V_13 V_14 = {
. V_96 = - 1 ,
. V_37 = true ,
} ;
return F_96 ( F_101 ( V_136 ) , & V_14 ) ;
}
static void F_102 ( void )
{
int V_136 ;
F_103 () ;
F_104 (nid)
F_100 ( V_136 ) ;
}
int F_105 ( struct V_137 * V_138 , int V_139 ,
void T_7 * V_140 , T_8 * V_141 , T_9 * V_142 )
{
if ( V_139 )
F_102 () ;
return 0 ;
}
int F_106 ( struct V_137 * V_138 , int V_139 ,
void T_7 * V_140 , T_8 * V_141 , T_9 * V_142 )
{
F_107 ( V_138 , V_139 , V_140 , V_141 , V_142 ) ;
return 0 ;
}
T_10 F_108 ( struct V_143 * V_144 ,
struct V_145 * V_146 ,
const char * V_147 , T_8 V_8 )
{
int V_136 = V_144 -> V_148 ;
if ( V_136 >= 0 && V_136 < V_149 && F_109 ( V_136 ) ) {
F_103 () ;
F_100 ( V_136 ) ;
}
return V_8 ;
}
int F_110 ( struct V_150 * V_150 )
{
return F_111 ( & V_150 -> V_144 , & V_151 ) ;
}
void F_112 ( struct V_150 * V_150 )
{
return F_113 ( & V_150 -> V_144 , & V_151 ) ;
}
