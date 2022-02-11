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
static unsigned long F_11 ( unsigned long V_10 ,
unsigned long V_11 ,
struct V_1 * V_2 ,
bool V_12 )
{
int V_13 = 0 , V_14 = 0 ;
struct V_3 * V_15 ;
V_15 = F_12 ( V_10 ) ;
for (; V_10 < V_11 ; V_10 ++ , V_15 ++ ) {
int V_16 , V_17 ;
struct V_3 * V_3 = V_15 ;
if ( ! F_13 ( V_10 ) ) {
if ( V_12 )
return 0 ;
continue;
}
V_13 ++ ;
if ( ! F_14 ( V_3 ) ) {
if ( V_12 )
return 0 ;
continue;
}
V_16 = F_15 ( V_3 ) ;
if ( ! V_16 && V_12 )
return 0 ;
V_14 += V_16 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
F_16 ( & V_3 -> V_6 , V_2 ) ;
V_3 ++ ;
}
if ( V_16 ) {
V_10 += V_16 - 1 ;
V_15 += V_16 - 1 ;
}
}
F_17 ( V_13 , V_14 ) ;
return V_14 ;
}
unsigned long
F_18 ( unsigned long V_18 , unsigned long V_11 )
{
unsigned long V_16 , V_19 , V_20 , V_21 ;
struct V_22 * V_22 = NULL ;
F_19 ( V_2 ) ;
if ( F_20 ( V_18 ) )
V_22 = F_21 ( F_12 ( V_18 ) ) ;
for ( V_19 = V_18 ; V_19 < V_11 ; V_19 += V_16 ) {
if ( ! F_20 ( V_19 ) || V_22 != F_21 ( F_12 ( V_19 ) ) )
break;
V_20 = F_22 ( V_19 + 1 , V_23 ) ;
V_20 = F_23 ( V_20 , V_11 ) ;
F_24 ( & V_22 -> V_24 , V_21 ) ;
V_16 = F_11 ( V_19 , V_20 ,
& V_2 , true ) ;
F_25 ( & V_22 -> V_24 , V_21 ) ;
if ( ! V_16 )
break;
}
F_5 ( & V_2 ) ;
if ( V_19 < V_11 ) {
F_1 ( & V_2 ) ;
return 0 ;
}
return V_19 ;
}
static void F_26 ( struct V_22 * V_22 , struct V_25 * V_26 )
{
struct V_3 * V_3 ;
unsigned int V_5 [ 2 ] = { 0 , } ;
F_6 (page, &cc->migratepages, lru)
V_5 [ ! ! F_27 ( V_3 ) ] ++ ;
F_28 ( V_22 , V_27 , V_5 [ 0 ] ) ;
F_28 ( V_22 , V_28 , V_5 [ 1 ] ) ;
}
static bool F_29 ( struct V_22 * V_22 )
{
unsigned long V_29 , V_30 , V_16 ;
V_30 = F_30 ( V_22 , V_31 ) +
F_30 ( V_22 , V_32 ) ;
V_29 = F_30 ( V_22 , V_33 ) +
F_30 ( V_22 , V_34 ) ;
V_16 = F_30 ( V_22 , V_28 ) +
F_30 ( V_22 , V_27 ) ;
return V_16 > ( V_30 + V_29 ) / 2 ;
}
unsigned long
F_31 ( struct V_22 * V_22 , struct V_25 * V_26 ,
unsigned long V_35 , unsigned long V_11 )
{
unsigned long V_36 = 0 , V_37 ;
unsigned long V_13 = 0 , V_38 = 0 ;
struct V_1 * V_39 = & V_26 -> V_40 ;
T_1 V_41 = 0 ;
struct V_42 * V_42 ;
while ( F_32 ( F_29 ( V_22 ) ) ) {
if ( ! V_26 -> V_43 )
return 0 ;
F_33 ( V_44 , V_45 / 10 ) ;
if ( F_34 ( V_46 ) )
return 0 ;
}
F_35 () ;
F_36 ( & V_22 -> V_47 ) ;
for (; V_35 < V_11 ; V_35 ++ ) {
struct V_3 * V_3 ;
bool V_48 = true ;
if ( ! ( ( V_35 + 1 ) % V_49 ) ) {
F_37 ( & V_22 -> V_47 ) ;
V_48 = false ;
}
if ( F_38 () || F_39 ( & V_22 -> V_47 ) ) {
if ( V_48 )
F_37 ( & V_22 -> V_47 ) ;
F_35 () ;
F_36 ( & V_22 -> V_47 ) ;
if ( F_34 ( V_46 ) )
break;
} else if ( ! V_48 )
F_36 ( & V_22 -> V_47 ) ;
if ( ( V_35 & ( V_50 - 1 ) ) == 0 ) {
if ( ! F_20 ( V_35 ) ) {
V_35 += V_50 - 1 ;
continue;
}
}
if ( ! F_13 ( V_35 ) )
continue;
V_13 ++ ;
V_3 = F_12 ( V_35 ) ;
if ( F_21 ( V_3 ) != V_22 )
continue;
if ( F_14 ( V_3 ) )
continue;
V_37 = V_35 >> V_51 ;
if ( ! V_26 -> V_43 && V_36 != V_37 &&
! F_9 ( F_40 ( V_3 ) ) ) {
V_35 += V_23 ;
V_35 = F_22 ( V_35 , V_23 ) - 1 ;
V_36 = V_37 ;
continue;
}
if ( ! F_41 ( V_3 ) )
continue;
if ( F_42 ( V_3 ) ) {
V_35 += ( 1 << F_43 ( V_3 ) ) - 1 ;
continue;
}
if ( ! V_26 -> V_43 )
V_41 |= V_52 ;
V_42 = F_44 ( V_3 , V_22 ) ;
if ( F_45 ( V_3 , V_41 ) != 0 )
continue;
F_46 ( F_47 ( V_3 ) ) ;
F_48 ( V_3 , V_42 , F_49 ( V_3 ) ) ;
F_16 ( & V_3 -> V_6 , V_39 ) ;
V_26 -> V_53 ++ ;
V_38 ++ ;
if ( V_26 -> V_53 == V_54 ) {
++ V_35 ;
break;
}
}
F_26 ( V_22 , V_26 ) ;
F_37 ( & V_22 -> V_47 ) ;
F_50 ( V_13 , V_38 ) ;
return V_35 ;
}
static bool F_51 ( struct V_3 * V_3 )
{
int V_8 = F_40 ( V_3 ) ;
if ( V_8 == V_55 || V_8 == V_56 )
return false ;
if ( F_14 ( V_3 ) && F_52 ( V_3 ) >= V_51 )
return true ;
if ( F_9 ( V_8 ) )
return true ;
return false ;
}
static void F_53 ( struct V_22 * V_22 ,
struct V_25 * V_26 )
{
struct V_3 * V_3 ;
unsigned long V_57 , V_35 , V_19 , V_58 , V_11 ;
unsigned long V_21 ;
int V_59 = V_26 -> V_59 ;
struct V_1 * V_2 = & V_26 -> V_60 ;
V_19 = V_26 -> V_61 ;
V_35 = V_26 -> V_62 + V_23 ;
V_57 = F_23 ( V_35 , V_19 ) ;
V_58 = V_22 -> V_63 + V_22 -> V_64 ;
for (; V_19 > V_35 && V_26 -> V_53 > V_59 ;
V_19 -= V_23 ) {
unsigned long V_16 ;
if ( ! F_20 ( V_19 ) )
continue;
V_3 = F_12 ( V_19 ) ;
if ( F_21 ( V_3 ) != V_22 )
continue;
if ( ! F_51 ( V_3 ) )
continue;
V_16 = 0 ;
F_24 ( & V_22 -> V_24 , V_21 ) ;
if ( F_51 ( V_3 ) ) {
V_11 = F_23 ( V_19 + V_23 , V_58 ) ;
V_16 = F_11 ( V_19 , V_11 ,
V_2 , false ) ;
V_59 += V_16 ;
}
F_25 ( & V_22 -> V_24 , V_21 ) ;
if ( V_16 )
V_57 = F_54 ( V_57 , V_19 ) ;
}
F_5 ( V_2 ) ;
V_26 -> V_61 = V_57 ;
V_26 -> V_59 = V_59 ;
}
static struct V_3 * F_55 ( struct V_3 * V_65 ,
unsigned long V_66 ,
int * * V_67 )
{
struct V_25 * V_26 = (struct V_25 * ) V_66 ;
struct V_3 * V_68 ;
if ( F_56 ( & V_26 -> V_60 ) ) {
F_53 ( V_26 -> V_22 , V_26 ) ;
if ( F_56 ( & V_26 -> V_60 ) )
return NULL ;
}
V_68 = F_57 ( V_26 -> V_60 . V_4 , struct V_3 , V_6 ) ;
F_3 ( & V_68 -> V_6 ) ;
V_26 -> V_59 -- ;
return V_68 ;
}
static void F_58 ( struct V_25 * V_26 )
{
int V_53 = 0 ;
int V_59 = 0 ;
struct V_3 * V_3 ;
F_6 (page, &cc->migratepages, lru)
V_53 ++ ;
F_6 (page, &cc->freepages, lru)
V_59 ++ ;
V_26 -> V_53 = V_53 ;
V_26 -> V_59 = V_59 ;
}
static T_2 F_59 ( struct V_22 * V_22 ,
struct V_25 * V_26 )
{
unsigned long V_35 , V_11 ;
V_35 = F_54 ( V_26 -> V_62 , V_22 -> V_63 ) ;
V_11 = F_22 ( V_35 + V_23 , V_23 ) ;
if ( V_11 > V_26 -> V_61 || ! F_20 ( V_35 ) ) {
V_26 -> V_62 = V_11 ;
return V_69 ;
}
V_35 = F_31 ( V_22 , V_26 , V_35 , V_11 ) ;
if ( ! V_35 )
return V_70 ;
V_26 -> V_62 = V_35 ;
return V_71 ;
}
static int F_60 ( struct V_22 * V_22 ,
struct V_25 * V_26 )
{
unsigned int V_72 ;
unsigned long V_73 ;
if ( F_34 ( V_46 ) )
return V_74 ;
if ( V_26 -> V_61 <= V_26 -> V_62 )
return V_75 ;
if ( V_26 -> V_72 == - 1 )
return V_76 ;
V_73 = F_61 ( V_22 ) ;
V_73 += ( 1 << V_26 -> V_72 ) ;
if ( ! F_62 ( V_22 , V_26 -> V_72 , V_73 , 0 , 0 ) )
return V_76 ;
for ( V_72 = V_26 -> V_72 ; V_72 < V_77 ; V_72 ++ ) {
if ( ! F_56 ( & V_22 -> V_78 [ V_72 ] . V_79 [ V_26 -> V_8 ] ) )
return V_74 ;
if ( V_72 >= V_51 && V_22 -> V_78 [ V_72 ] . V_80 )
return V_74 ;
}
return V_76 ;
}
unsigned long F_63 ( struct V_22 * V_22 , int V_72 )
{
int V_81 ;
unsigned long V_73 ;
if ( V_72 == - 1 )
return V_76 ;
V_73 = F_61 ( V_22 ) + ( 2UL << V_72 ) ;
if ( ! F_62 ( V_22 , 0 , V_73 , 0 , 0 ) )
return V_82 ;
V_81 = F_64 ( V_22 , V_72 ) ;
if ( V_81 >= 0 && V_81 <= V_83 )
return V_82 ;
if ( V_81 == - 1000 && F_62 ( V_22 , V_72 , V_73 ,
0 , 0 ) )
return V_74 ;
return V_76 ;
}
static int F_65 ( struct V_22 * V_22 , struct V_25 * V_26 )
{
int V_84 ;
V_84 = F_63 ( V_22 , V_26 -> V_72 ) ;
switch ( V_84 ) {
case V_74 :
case V_82 :
return V_84 ;
case V_76 :
;
}
V_26 -> V_62 = V_22 -> V_63 ;
V_26 -> V_61 = V_26 -> V_62 + V_22 -> V_64 ;
V_26 -> V_61 &= ~ ( V_23 - 1 ) ;
F_66 () ;
while ( ( V_84 = F_60 ( V_22 , V_26 ) ) == V_76 ) {
unsigned long V_85 , V_86 ;
int V_87 ;
switch ( F_59 ( V_22 , V_26 ) ) {
case V_70 :
V_84 = V_74 ;
goto V_88;
case V_69 :
continue;
case V_71 :
;
}
V_85 = V_26 -> V_53 ;
V_87 = F_67 ( & V_26 -> V_40 , F_55 ,
( unsigned long ) V_26 , false ,
V_26 -> V_43 ? V_89 : V_90 ) ;
F_58 ( V_26 ) ;
V_86 = V_26 -> V_53 ;
F_68 ( V_91 ) ;
F_69 ( V_92 , V_85 - V_86 ) ;
if ( V_86 )
F_69 ( V_93 , V_86 ) ;
F_70 ( V_85 - V_86 ,
V_86 ) ;
if ( V_87 ) {
F_71 ( & V_26 -> V_40 ) ;
V_26 -> V_53 = 0 ;
if ( V_87 == - V_94 ) {
V_84 = V_74 ;
goto V_88;
}
}
}
V_88:
V_26 -> V_59 -= F_1 ( & V_26 -> V_60 ) ;
F_46 ( V_26 -> V_59 != 0 ) ;
return V_84 ;
}
static unsigned long F_72 ( struct V_22 * V_22 ,
int V_72 , T_3 V_95 ,
bool V_43 )
{
struct V_25 V_26 = {
. V_59 = 0 ,
. V_53 = 0 ,
. V_72 = V_72 ,
. V_8 = F_73 ( V_95 ) ,
. V_22 = V_22 ,
. V_43 = V_43 ,
} ;
F_74 ( & V_26 . V_60 ) ;
F_74 ( & V_26 . V_40 ) ;
return F_65 ( V_22 , & V_26 ) ;
}
unsigned long F_75 ( struct V_96 * V_96 ,
int V_72 , T_3 V_95 , T_4 * V_97 ,
bool V_43 )
{
enum V_98 V_99 = F_76 ( V_95 ) ;
int V_100 = V_95 & V_101 ;
int V_102 = V_95 & V_103 ;
struct V_104 * V_105 ;
struct V_22 * V_22 ;
int V_106 = V_82 ;
if ( ! V_72 || ! V_100 || ! V_102 )
return V_106 ;
F_68 ( V_107 ) ;
F_77 (zone, z, zonelist, high_zoneidx,
nodemask) {
int V_108 ;
V_108 = F_72 ( V_22 , V_72 , V_95 , V_43 ) ;
V_106 = F_54 ( V_108 , V_106 ) ;
if ( F_62 ( V_22 , V_72 , F_61 ( V_22 ) , 0 , 0 ) )
break;
}
return V_106 ;
}
static int F_78 ( T_5 * V_109 , struct V_25 * V_26 )
{
int V_110 ;
struct V_22 * V_22 ;
for ( V_110 = 0 ; V_110 < V_111 ; V_110 ++ ) {
V_22 = & V_109 -> V_112 [ V_110 ] ;
if ( ! F_79 ( V_22 ) )
continue;
V_26 -> V_59 = 0 ;
V_26 -> V_53 = 0 ;
V_26 -> V_22 = V_22 ;
F_74 ( & V_26 -> V_60 ) ;
F_74 ( & V_26 -> V_40 ) ;
if ( V_26 -> V_72 == - 1 || ! F_80 ( V_22 , V_26 -> V_72 ) )
F_65 ( V_22 , V_26 ) ;
if ( V_26 -> V_72 > 0 ) {
int V_113 = F_62 ( V_22 , V_26 -> V_72 ,
F_61 ( V_22 ) , 0 , 0 ) ;
if ( V_113 && V_26 -> V_72 > V_22 -> V_114 )
V_22 -> V_114 = V_26 -> V_72 + 1 ;
else if ( ! V_113 && V_26 -> V_43 )
F_81 ( V_22 , V_26 -> V_72 ) ;
}
F_46 ( ! F_56 ( & V_26 -> V_60 ) ) ;
F_46 ( ! F_56 ( & V_26 -> V_40 ) ) ;
}
return 0 ;
}
int F_82 ( T_5 * V_109 , int V_72 )
{
struct V_25 V_26 = {
. V_72 = V_72 ,
. V_43 = false ,
} ;
return F_78 ( V_109 , & V_26 ) ;
}
static int F_83 ( int V_115 )
{
struct V_25 V_26 = {
. V_72 = - 1 ,
. V_43 = true ,
} ;
return F_78 ( F_84 ( V_115 ) , & V_26 ) ;
}
static int F_85 ( void )
{
int V_115 ;
F_86 () ;
F_87 (nid)
F_83 ( V_115 ) ;
return V_75 ;
}
int F_88 ( struct V_116 * V_117 , int V_118 ,
void T_6 * V_119 , T_7 * V_120 , T_8 * V_121 )
{
if ( V_118 )
return F_85 () ;
return 0 ;
}
int F_89 ( struct V_116 * V_117 , int V_118 ,
void T_6 * V_119 , T_7 * V_120 , T_8 * V_121 )
{
F_90 ( V_117 , V_118 , V_119 , V_120 , V_121 ) ;
return 0 ;
}
T_9 F_91 ( struct V_122 * V_123 ,
struct V_124 * V_125 ,
const char * V_126 , T_7 V_5 )
{
int V_115 = V_123 -> V_127 ;
if ( V_115 >= 0 && V_115 < V_128 && F_92 ( V_115 ) ) {
F_86 () ;
F_83 ( V_115 ) ;
}
return V_5 ;
}
int F_93 ( struct V_129 * V_129 )
{
return F_94 ( & V_129 -> V_123 , & V_130 ) ;
}
void F_95 ( struct V_129 * V_129 )
{
return F_96 ( & V_129 -> V_123 , & V_130 ) ;
}
