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
static bool F_11 ( T_1 * V_10 , unsigned long * V_11 ,
bool V_12 , struct V_13 * V_14 )
{
if ( F_12 () || F_13 ( V_10 ) ) {
if ( V_12 ) {
F_14 ( V_10 , * V_11 ) ;
V_12 = false ;
}
if ( ! V_14 -> V_15 ) {
if ( V_14 -> V_16 )
* V_14 -> V_16 = true ;
return false ;
}
F_15 () ;
if ( F_16 ( V_17 ) )
return false ;
}
if ( ! V_12 )
F_17 ( V_10 , * V_11 ) ;
return true ;
}
static inline bool F_18 ( T_1 * V_10 ,
unsigned long * V_11 , struct V_13 * V_14 )
{
return F_11 ( V_10 , V_11 , false , V_14 ) ;
}
static unsigned long F_19 ( unsigned long V_18 ,
unsigned long V_19 ,
struct V_1 * V_2 ,
bool V_20 )
{
int V_21 = 0 , V_22 = 0 ;
struct V_3 * V_23 ;
V_23 = F_20 ( V_18 ) ;
for (; V_18 < V_19 ; V_18 ++ , V_23 ++ ) {
int V_24 , V_25 ;
struct V_3 * V_3 = V_23 ;
if ( ! F_21 ( V_18 ) ) {
if ( V_20 )
return 0 ;
continue;
}
V_21 ++ ;
if ( ! F_22 ( V_3 ) ) {
if ( V_20 )
return 0 ;
continue;
}
V_24 = F_23 ( V_3 ) ;
if ( ! V_24 && V_20 )
return 0 ;
V_22 += V_24 ;
for ( V_25 = 0 ; V_25 < V_24 ; V_25 ++ ) {
F_24 ( & V_3 -> V_6 , V_2 ) ;
V_3 ++ ;
}
if ( V_24 ) {
V_18 += V_24 - 1 ;
V_23 += V_24 - 1 ;
}
}
F_25 ( V_21 , V_22 ) ;
return V_22 ;
}
unsigned long
F_26 ( unsigned long V_26 , unsigned long V_19 )
{
unsigned long V_24 , V_27 , V_28 , V_11 ;
struct V_29 * V_29 = NULL ;
F_27 ( V_2 ) ;
if ( F_28 ( V_26 ) )
V_29 = F_29 ( F_20 ( V_26 ) ) ;
for ( V_27 = V_26 ; V_27 < V_19 ; V_27 += V_24 ) {
if ( ! F_28 ( V_27 ) || V_29 != F_29 ( F_20 ( V_27 ) ) )
break;
V_28 = F_30 ( V_27 + 1 , V_30 ) ;
V_28 = F_31 ( V_28 , V_19 ) ;
F_17 ( & V_29 -> V_10 , V_11 ) ;
V_24 = F_19 ( V_27 , V_28 ,
& V_2 , true ) ;
F_14 ( & V_29 -> V_10 , V_11 ) ;
if ( ! V_24 )
break;
}
F_5 ( & V_2 ) ;
if ( V_27 < V_19 ) {
F_1 ( & V_2 ) ;
return 0 ;
}
return V_27 ;
}
static void F_32 ( struct V_29 * V_29 , bool V_12 , struct V_13 * V_14 )
{
struct V_3 * V_3 ;
unsigned int V_5 [ 2 ] = { 0 , } ;
F_6 (page, &cc->migratepages, lru)
V_5 [ ! ! F_33 ( V_3 ) ] ++ ;
if ( V_12 ) {
F_34 ( V_29 , V_31 , V_5 [ 0 ] ) ;
F_34 ( V_29 , V_32 , V_5 [ 1 ] ) ;
} else {
F_35 ( V_29 , V_31 , V_5 [ 0 ] ) ;
F_35 ( V_29 , V_32 , V_5 [ 1 ] ) ;
}
}
static bool F_36 ( struct V_29 * V_29 )
{
unsigned long V_33 , V_34 , V_24 ;
V_34 = F_37 ( V_29 , V_35 ) +
F_37 ( V_29 , V_36 ) ;
V_33 = F_37 ( V_29 , V_37 ) +
F_37 ( V_29 , V_38 ) ;
V_24 = F_37 ( V_29 , V_32 ) +
F_37 ( V_29 , V_31 ) ;
return V_24 > ( V_34 + V_33 ) / 2 ;
}
unsigned long
F_38 ( struct V_29 * V_29 , struct V_13 * V_14 ,
unsigned long V_39 , unsigned long V_19 )
{
unsigned long V_40 = 0 , V_41 ;
unsigned long V_21 = 0 , V_42 = 0 ;
struct V_1 * V_43 = & V_14 -> V_44 ;
T_2 V_45 = 0 ;
struct V_46 * V_46 ;
unsigned long V_11 ;
bool V_12 ;
while ( F_39 ( F_36 ( V_29 ) ) ) {
if ( ! V_14 -> V_15 )
return 0 ;
F_40 ( V_47 , V_48 / 10 ) ;
if ( F_16 ( V_17 ) )
return 0 ;
}
F_15 () ;
F_17 ( & V_29 -> V_49 , V_11 ) ;
V_12 = true ;
for (; V_39 < V_19 ; V_39 ++ ) {
struct V_3 * V_3 ;
if ( ! ( ( V_39 + 1 ) % V_50 ) ) {
F_14 ( & V_29 -> V_49 , V_11 ) ;
V_12 = false ;
}
V_12 = F_11 ( & V_29 -> V_49 , & V_11 ,
V_12 , V_14 ) ;
if ( ! V_12 )
break;
if ( ( V_39 & ( V_51 - 1 ) ) == 0 ) {
if ( ! F_28 ( V_39 ) ) {
V_39 += V_51 - 1 ;
continue;
}
}
if ( ! F_21 ( V_39 ) )
continue;
V_21 ++ ;
V_3 = F_20 ( V_39 ) ;
if ( F_29 ( V_3 ) != V_29 )
continue;
if ( F_22 ( V_3 ) )
continue;
V_41 = V_39 >> V_52 ;
if ( ! V_14 -> V_15 && V_40 != V_41 &&
! F_9 ( F_41 ( V_3 ) ) ) {
V_39 += V_30 ;
V_39 = F_30 ( V_39 , V_30 ) - 1 ;
V_40 = V_41 ;
continue;
}
if ( ! F_42 ( V_3 ) )
continue;
if ( F_43 ( V_3 ) ) {
V_39 += ( 1 << F_44 ( V_3 ) ) - 1 ;
continue;
}
if ( ! V_14 -> V_15 )
V_45 |= V_53 ;
V_46 = F_45 ( V_3 , V_29 ) ;
if ( F_46 ( V_3 , V_45 ) != 0 )
continue;
F_47 ( F_48 ( V_3 ) ) ;
F_49 ( V_3 , V_46 , F_50 ( V_3 ) ) ;
F_24 ( & V_3 -> V_6 , V_43 ) ;
V_14 -> V_54 ++ ;
V_42 ++ ;
if ( V_14 -> V_54 == V_55 ) {
++ V_39 ;
break;
}
}
F_32 ( V_29 , V_12 , V_14 ) ;
if ( V_12 )
F_14 ( & V_29 -> V_49 , V_11 ) ;
F_51 ( V_21 , V_42 ) ;
return V_39 ;
}
static bool F_52 ( struct V_3 * V_3 )
{
int V_8 = F_41 ( V_3 ) ;
if ( V_8 == V_56 || V_8 == V_57 )
return false ;
if ( F_22 ( V_3 ) && F_53 ( V_3 ) >= V_52 )
return true ;
if ( F_9 ( V_8 ) )
return true ;
return false ;
}
static unsigned long F_54 ( struct V_29 * V_29 )
{
unsigned long V_58 ;
V_58 = V_29 -> V_59 + V_29 -> V_60 ;
V_58 &= ~ ( V_30 - 1 ) ;
return V_58 ;
}
static void F_55 ( struct V_29 * V_29 ,
struct V_13 * V_14 )
{
struct V_3 * V_3 ;
unsigned long V_61 , V_39 , V_27 , V_62 , V_19 ;
unsigned long V_11 ;
int V_63 = V_14 -> V_63 ;
struct V_1 * V_2 = & V_14 -> V_64 ;
V_27 = V_14 -> V_58 ;
V_39 = V_14 -> V_65 + V_30 ;
V_61 = F_31 ( V_39 , V_27 ) ;
V_62 = V_29 -> V_59 + V_29 -> V_60 ;
for (; V_27 > V_39 && V_14 -> V_54 > V_63 ;
V_27 -= V_30 ) {
unsigned long V_24 ;
if ( ! F_28 ( V_27 ) )
continue;
V_3 = F_20 ( V_27 ) ;
if ( F_29 ( V_3 ) != V_29 )
continue;
if ( ! F_52 ( V_3 ) )
continue;
V_24 = 0 ;
if ( ! F_18 ( & V_29 -> V_10 , & V_11 , V_14 ) )
break;
if ( F_52 ( V_3 ) ) {
V_19 = F_31 ( V_27 + V_30 , V_62 ) ;
V_24 = F_19 ( V_27 , V_19 ,
V_2 , false ) ;
V_63 += V_24 ;
}
F_14 ( & V_29 -> V_10 , V_11 ) ;
if ( V_24 ) {
V_61 = F_56 ( V_61 , V_27 ) ;
if ( V_14 -> V_66 > 0 && V_14 -> V_67 )
V_29 -> V_68 = V_61 ;
}
}
F_5 ( V_2 ) ;
V_14 -> V_58 = V_61 ;
V_14 -> V_63 = V_63 ;
if ( V_14 -> V_66 > 0 && ! V_14 -> V_67 &&
V_29 -> V_68 == F_54 ( V_29 ) )
V_29 -> V_68 = V_61 ;
}
static struct V_3 * F_57 ( struct V_3 * V_69 ,
unsigned long V_70 ,
int * * V_71 )
{
struct V_13 * V_14 = (struct V_13 * ) V_70 ;
struct V_3 * V_72 ;
if ( F_58 ( & V_14 -> V_64 ) ) {
F_55 ( V_14 -> V_29 , V_14 ) ;
if ( F_58 ( & V_14 -> V_64 ) )
return NULL ;
}
V_72 = F_59 ( V_14 -> V_64 . V_4 , struct V_3 , V_6 ) ;
F_3 ( & V_72 -> V_6 ) ;
V_14 -> V_63 -- ;
return V_72 ;
}
static void F_60 ( struct V_13 * V_14 )
{
int V_54 = 0 ;
int V_63 = 0 ;
struct V_3 * V_3 ;
F_6 (page, &cc->migratepages, lru)
V_54 ++ ;
F_6 (page, &cc->freepages, lru)
V_63 ++ ;
V_14 -> V_54 = V_54 ;
V_14 -> V_63 = V_63 ;
}
static T_3 F_61 ( struct V_29 * V_29 ,
struct V_13 * V_14 )
{
unsigned long V_39 , V_19 ;
V_39 = F_56 ( V_14 -> V_65 , V_29 -> V_59 ) ;
V_19 = F_30 ( V_39 + V_30 , V_30 ) ;
if ( V_19 > V_14 -> V_58 || ! F_28 ( V_39 ) ) {
V_14 -> V_65 = V_19 ;
return V_73 ;
}
V_39 = F_38 ( V_29 , V_14 , V_39 , V_19 ) ;
if ( ! V_39 )
return V_74 ;
V_14 -> V_65 = V_39 ;
return V_75 ;
}
static int F_62 ( struct V_29 * V_29 ,
struct V_13 * V_14 )
{
unsigned int V_66 ;
unsigned long V_76 ;
if ( F_16 ( V_17 ) )
return V_77 ;
if ( V_14 -> V_58 <= V_14 -> V_65 ) {
if ( V_14 -> V_66 > 0 && ! V_14 -> V_67 ) {
unsigned long V_58 = F_54 ( V_29 ) ;
V_29 -> V_68 = V_58 ;
V_14 -> V_58 = V_58 ;
V_14 -> V_67 = 1 ;
return V_78 ;
}
return V_79 ;
}
if ( V_14 -> V_67 && V_14 -> V_58 <= V_14 -> F_54 )
return V_79 ;
if ( V_14 -> V_66 == - 1 )
return V_78 ;
V_76 = F_63 ( V_29 ) ;
V_76 += ( 1 << V_14 -> V_66 ) ;
if ( ! F_64 ( V_29 , V_14 -> V_66 , V_76 , 0 , 0 ) )
return V_78 ;
for ( V_66 = V_14 -> V_66 ; V_66 < V_80 ; V_66 ++ ) {
if ( ! F_58 ( & V_29 -> V_81 [ V_66 ] . V_82 [ V_14 -> V_8 ] ) )
return V_77 ;
if ( V_66 >= V_52 && V_29 -> V_81 [ V_66 ] . V_83 )
return V_77 ;
}
return V_78 ;
}
unsigned long F_65 ( struct V_29 * V_29 , int V_66 )
{
int V_84 ;
unsigned long V_76 ;
if ( V_66 == - 1 )
return V_78 ;
V_76 = F_63 ( V_29 ) + ( 2UL << V_66 ) ;
if ( ! F_64 ( V_29 , 0 , V_76 , 0 , 0 ) )
return V_85 ;
V_84 = F_66 ( V_29 , V_66 ) ;
if ( V_84 >= 0 && V_84 <= V_86 )
return V_85 ;
if ( V_84 == - 1000 && F_64 ( V_29 , V_66 , V_76 ,
0 , 0 ) )
return V_77 ;
return V_78 ;
}
static int F_67 ( struct V_29 * V_29 , struct V_13 * V_14 )
{
int V_87 ;
V_87 = F_65 ( V_29 , V_14 -> V_66 ) ;
switch ( V_87 ) {
case V_77 :
case V_85 :
return V_87 ;
case V_78 :
;
}
V_14 -> V_65 = V_29 -> V_59 ;
if ( V_14 -> V_66 > 0 ) {
V_14 -> V_58 = V_29 -> V_68 ;
V_14 -> F_54 = V_14 -> V_58 ;
} else {
V_14 -> V_58 = F_54 ( V_29 ) ;
}
F_68 () ;
while ( ( V_87 = F_62 ( V_29 , V_14 ) ) == V_78 ) {
unsigned long V_88 , V_89 ;
int V_90 ;
switch ( F_61 ( V_29 , V_14 ) ) {
case V_74 :
V_87 = V_77 ;
goto V_91;
case V_73 :
continue;
case V_75 :
;
}
V_88 = V_14 -> V_54 ;
V_90 = F_69 ( & V_14 -> V_44 , F_57 ,
( unsigned long ) V_14 , false ,
V_14 -> V_15 ? V_92 : V_93 ) ;
F_60 ( V_14 ) ;
V_89 = V_14 -> V_54 ;
F_70 ( V_94 ) ;
F_71 ( V_95 , V_88 - V_89 ) ;
if ( V_89 )
F_71 ( V_96 , V_89 ) ;
F_72 ( V_88 - V_89 ,
V_89 ) ;
if ( V_90 ) {
F_73 ( & V_14 -> V_44 ) ;
V_14 -> V_54 = 0 ;
if ( V_90 == - V_97 ) {
V_87 = V_77 ;
goto V_91;
}
}
}
V_91:
V_14 -> V_63 -= F_1 ( & V_14 -> V_64 ) ;
F_47 ( V_14 -> V_63 != 0 ) ;
return V_87 ;
}
static unsigned long F_74 ( struct V_29 * V_29 ,
int V_66 , T_4 V_98 ,
bool V_15 , bool * V_16 )
{
struct V_13 V_14 = {
. V_63 = 0 ,
. V_54 = 0 ,
. V_66 = V_66 ,
. V_8 = F_75 ( V_98 ) ,
. V_29 = V_29 ,
. V_15 = V_15 ,
. V_16 = V_16 ,
} ;
F_76 ( & V_14 . V_64 ) ;
F_76 ( & V_14 . V_44 ) ;
return F_67 ( V_29 , & V_14 ) ;
}
unsigned long F_77 ( struct V_99 * V_99 ,
int V_66 , T_4 V_98 , T_5 * V_100 ,
bool V_15 , bool * V_16 )
{
enum V_101 V_102 = F_78 ( V_98 ) ;
int V_103 = V_98 & V_104 ;
int V_105 = V_98 & V_106 ;
struct V_107 * V_108 ;
struct V_29 * V_29 ;
int V_109 = V_85 ;
if ( ! V_66 || ! V_103 || ! V_105 )
return V_109 ;
F_70 ( V_110 ) ;
F_79 (zone, z, zonelist, high_zoneidx,
nodemask) {
int V_111 ;
V_111 = F_74 ( V_29 , V_66 , V_98 , V_15 ,
V_16 ) ;
V_109 = F_56 ( V_111 , V_109 ) ;
if ( F_64 ( V_29 , V_66 , F_63 ( V_29 ) , 0 , 0 ) )
break;
}
return V_109 ;
}
static int F_80 ( T_6 * V_112 , struct V_13 * V_14 )
{
int V_113 ;
struct V_29 * V_29 ;
for ( V_113 = 0 ; V_113 < V_114 ; V_113 ++ ) {
V_29 = & V_112 -> V_115 [ V_113 ] ;
if ( ! F_81 ( V_29 ) )
continue;
V_14 -> V_63 = 0 ;
V_14 -> V_54 = 0 ;
V_14 -> V_29 = V_29 ;
F_76 ( & V_14 -> V_64 ) ;
F_76 ( & V_14 -> V_44 ) ;
if ( V_14 -> V_66 == - 1 || ! F_82 ( V_29 , V_14 -> V_66 ) )
F_67 ( V_29 , V_14 ) ;
if ( V_14 -> V_66 > 0 ) {
int V_116 = F_64 ( V_29 , V_14 -> V_66 ,
F_63 ( V_29 ) , 0 , 0 ) ;
if ( V_116 && V_14 -> V_66 >= V_29 -> V_117 )
V_29 -> V_117 = V_14 -> V_66 + 1 ;
else if ( ! V_116 && V_14 -> V_15 )
F_83 ( V_29 , V_14 -> V_66 ) ;
}
F_47 ( ! F_58 ( & V_14 -> V_64 ) ) ;
F_47 ( ! F_58 ( & V_14 -> V_44 ) ) ;
}
return 0 ;
}
int F_84 ( T_6 * V_112 , int V_66 )
{
struct V_13 V_14 = {
. V_66 = V_66 ,
. V_15 = false ,
} ;
return F_80 ( V_112 , & V_14 ) ;
}
static int F_85 ( int V_118 )
{
struct V_13 V_14 = {
. V_66 = - 1 ,
. V_15 = true ,
} ;
return F_80 ( F_86 ( V_118 ) , & V_14 ) ;
}
static int F_87 ( void )
{
int V_118 ;
F_88 () ;
F_89 (nid)
F_85 ( V_118 ) ;
return V_79 ;
}
int F_90 ( struct V_119 * V_120 , int V_121 ,
void T_7 * V_122 , T_8 * V_123 , T_9 * V_124 )
{
if ( V_121 )
return F_87 () ;
return 0 ;
}
int F_91 ( struct V_119 * V_120 , int V_121 ,
void T_7 * V_122 , T_8 * V_123 , T_9 * V_124 )
{
F_92 ( V_120 , V_121 , V_122 , V_123 , V_124 ) ;
return 0 ;
}
T_10 F_93 ( struct V_125 * V_126 ,
struct V_127 * V_128 ,
const char * V_129 , T_8 V_5 )
{
int V_118 = V_126 -> V_130 ;
if ( V_118 >= 0 && V_118 < V_131 && F_94 ( V_118 ) ) {
F_88 () ;
F_85 ( V_118 ) ;
}
return V_5 ;
}
int F_95 ( struct V_132 * V_132 )
{
return F_96 ( & V_132 -> V_126 , & V_133 ) ;
}
void F_97 ( struct V_132 * V_132 )
{
return F_98 ( & V_132 -> V_126 , & V_133 ) ;
}
