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
if ( F_37 ( V_6 ) && F_38 ( V_6 ) >= V_38 )
return false ;
if ( F_13 ( F_39 ( V_6 ) ) )
return true ;
return false ;
}
static unsigned long F_40 ( struct V_13 * V_14 ,
unsigned long V_39 ,
unsigned long V_19 ,
struct V_4 * V_5 ,
bool V_40 )
{
int V_41 = 0 , V_42 = 0 ;
struct V_6 * V_43 , * V_44 = NULL ;
unsigned long V_34 ;
bool V_35 = false ;
bool V_45 = false ;
V_43 = F_21 ( V_39 ) ;
for (; V_39 < V_19 ; V_39 ++ , V_43 ++ ) {
int V_46 , V_47 ;
struct V_6 * V_6 = V_43 ;
V_41 ++ ;
if ( ! F_41 ( V_39 ) )
goto V_48;
if ( ! V_44 )
V_44 = V_6 ;
if ( ! F_37 ( V_6 ) )
goto V_48;
V_35 = F_32 ( & V_14 -> V_16 -> V_33 , & V_34 ,
V_35 , V_14 ) ;
if ( ! V_35 )
break;
if ( ! V_40 && ! V_45 ) {
V_45 = true ;
if ( ! F_36 ( V_6 ) )
break;
}
if ( ! F_37 ( V_6 ) )
goto V_48;
V_46 = F_42 ( V_6 ) ;
V_42 += V_46 ;
for ( V_47 = 0 ; V_47 < V_46 ; V_47 ++ ) {
F_43 ( & V_6 -> V_9 , V_5 ) ;
V_6 ++ ;
}
if ( V_46 ) {
V_39 += V_46 - 1 ;
V_43 += V_46 - 1 ;
continue;
}
V_48:
if ( V_40 )
break;
else
continue;
}
F_44 ( V_41 , V_42 ) ;
if ( V_40 && V_39 < V_19 )
V_42 = 0 ;
if ( V_35 )
F_33 ( & V_14 -> V_16 -> V_33 , V_34 ) ;
if ( V_39 == V_19 )
F_26 ( V_14 , V_44 , V_42 , false ) ;
F_3 ( V_49 , V_41 ) ;
if ( V_42 )
F_3 ( V_50 , V_42 ) ;
return V_42 ;
}
unsigned long
F_45 ( struct V_13 * V_14 ,
unsigned long V_17 , unsigned long V_19 )
{
unsigned long V_46 , V_20 , V_51 ;
F_46 ( V_5 ) ;
for ( V_20 = V_17 ; V_20 < V_19 ; V_20 += V_46 ) {
if ( ! F_20 ( V_20 ) || V_14 -> V_16 != F_22 ( F_21 ( V_20 ) ) )
break;
V_51 = F_47 ( V_20 + 1 , V_24 ) ;
V_51 = F_48 ( V_51 , V_19 ) ;
V_46 = F_40 ( V_14 , V_20 , V_51 ,
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
static void F_49 ( struct V_16 * V_16 , bool V_35 , struct V_13 * V_14 )
{
struct V_6 * V_6 ;
unsigned int V_8 [ 2 ] = { 0 , } ;
F_10 (page, &cc->migratepages, lru)
V_8 [ ! ! F_50 ( V_6 ) ] ++ ;
if ( V_35 ) {
F_51 ( V_16 , V_52 , V_8 [ 0 ] ) ;
F_51 ( V_16 , V_53 , V_8 [ 1 ] ) ;
} else {
F_52 ( V_16 , V_52 , V_8 [ 0 ] ) ;
F_52 ( V_16 , V_53 , V_8 [ 1 ] ) ;
}
}
static bool F_53 ( struct V_16 * V_16 )
{
unsigned long V_54 , V_55 , V_46 ;
V_55 = F_54 ( V_16 , V_56 ) +
F_54 ( V_16 , V_57 ) ;
V_54 = F_54 ( V_16 , V_58 ) +
F_54 ( V_16 , V_59 ) ;
V_46 = F_54 ( V_16 , V_53 ) +
F_54 ( V_16 , V_52 ) ;
return V_46 > ( V_55 + V_54 ) / 2 ;
}
unsigned long
F_55 ( struct V_16 * V_16 , struct V_13 * V_14 ,
unsigned long V_60 , unsigned long V_19 , bool V_61 )
{
unsigned long V_62 = 0 , V_63 ;
unsigned long V_41 = 0 , V_29 = 0 ;
struct V_4 * V_64 = & V_14 -> V_65 ;
struct V_66 * V_66 ;
unsigned long V_34 ;
bool V_35 = false ;
struct V_6 * V_6 = NULL , * V_44 = NULL ;
bool V_67 = false ;
const T_3 V_68 = ( ! V_14 -> V_36 ? V_69 : 0 ) |
( V_61 ? V_70 : 0 ) ;
while ( F_56 ( F_53 ( V_16 ) ) ) {
if ( ! V_14 -> V_36 )
return 0 ;
F_57 ( V_71 , V_72 / 10 ) ;
if ( F_58 ( V_73 ) )
return 0 ;
}
F_19 () ;
for (; V_60 < V_19 ; V_60 ++ ) {
if ( V_35 && ! ( V_60 % V_74 ) ) {
if ( F_29 ( & V_16 -> V_75 ) ) {
F_33 ( & V_16 -> V_75 , V_34 ) ;
V_35 = false ;
}
}
if ( ( V_60 & ( V_76 - 1 ) ) == 0 ) {
if ( ! F_20 ( V_60 ) ) {
V_60 += V_76 - 1 ;
continue;
}
}
if ( ! F_41 ( V_60 ) )
continue;
V_41 ++ ;
V_6 = F_21 ( V_60 ) ;
if ( F_22 ( V_6 ) != V_16 )
continue;
if ( ! V_44 )
V_44 = V_6 ;
V_63 = V_60 >> V_38 ;
if ( V_62 != V_63 ) {
int V_77 ;
V_62 = V_63 ;
if ( ! F_15 ( V_14 , V_6 ) )
goto V_78;
V_77 = F_39 ( V_6 ) ;
if ( ! V_14 -> V_36 && ! F_13 ( V_77 ) ) {
V_14 -> V_31 = true ;
V_67 = true ;
goto V_78;
}
}
if ( F_37 ( V_6 ) )
continue;
if ( ! F_59 ( V_6 ) ) {
if ( F_56 ( F_60 ( V_6 ) ) ) {
if ( V_35 && F_61 ( V_6 ) ) {
goto V_79;
}
}
continue;
}
if ( F_62 ( V_6 ) ) {
if ( ! V_35 )
goto V_78;
V_60 += ( 1 << F_63 ( V_6 ) ) - 1 ;
continue;
}
if ( ! F_64 ( V_6 ) &&
F_65 ( V_6 ) > F_66 ( V_6 ) )
continue;
V_35 = F_32 ( & V_16 -> V_75 , & V_34 ,
V_35 , V_14 ) ;
if ( ! V_35 || F_58 ( V_73 ) )
break;
if ( ! F_59 ( V_6 ) )
continue;
if ( F_62 ( V_6 ) ) {
V_60 += ( 1 << F_63 ( V_6 ) ) - 1 ;
continue;
}
V_66 = F_67 ( V_6 , V_16 ) ;
if ( F_68 ( V_6 , V_68 ) != 0 )
continue;
F_69 ( F_70 ( V_6 ) , V_6 ) ;
F_71 ( V_6 , V_66 , F_72 ( V_6 ) ) ;
V_79:
V_14 -> V_31 = true ;
F_43 ( & V_6 -> V_9 , V_64 ) ;
V_14 -> V_80 ++ ;
V_29 ++ ;
if ( V_14 -> V_80 == V_81 ) {
++ V_60 ;
break;
}
continue;
V_78:
V_60 = F_47 ( V_60 + 1 , V_24 ) - 1 ;
}
F_49 ( V_16 , V_35 , V_14 ) ;
if ( V_35 )
F_33 ( & V_16 -> V_75 , V_34 ) ;
if ( V_60 == V_19 && ! V_67 )
F_26 ( V_14 , V_44 , V_29 , true ) ;
F_73 ( V_41 , V_29 ) ;
F_3 ( V_82 , V_41 ) ;
if ( V_29 )
F_3 ( V_50 , V_29 ) ;
return V_60 ;
}
static void F_74 ( struct V_16 * V_16 ,
struct V_13 * V_14 )
{
struct V_6 * V_6 ;
unsigned long V_83 , V_60 , V_20 , V_84 ;
int V_85 = V_14 -> V_85 ;
struct V_4 * V_5 = & V_14 -> V_86 ;
V_20 = V_14 -> V_87 & ~ ( V_24 - 1 ) ;
V_60 = F_47 ( V_14 -> V_88 + 1 , V_24 ) ;
V_83 = F_48 ( V_60 , V_20 ) ;
V_84 = F_18 ( V_16 ) ;
for (; V_20 >= V_60 && V_14 -> V_80 > V_85 ;
V_20 -= V_24 ) {
unsigned long V_46 ;
unsigned long V_19 ;
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
V_19 = F_48 ( V_20 + V_24 , V_84 ) ;
V_46 = F_40 ( V_14 , V_20 , V_19 ,
V_5 , false ) ;
V_85 += V_46 ;
if ( V_46 ) {
V_14 -> V_32 = true ;
V_83 = F_75 ( V_83 , V_20 ) ;
}
}
F_9 ( V_5 ) ;
if ( V_20 < V_60 )
V_14 -> V_87 = F_75 ( V_20 , V_16 -> V_18 ) ;
else
V_14 -> V_87 = V_83 ;
V_14 -> V_85 = V_85 ;
}
static struct V_6 * F_76 ( struct V_6 * V_89 ,
unsigned long V_90 ,
int * * V_91 )
{
struct V_13 * V_14 = (struct V_13 * ) V_90 ;
struct V_6 * V_92 ;
if ( F_77 ( & V_14 -> V_86 ) ) {
F_74 ( V_14 -> V_16 , V_14 ) ;
if ( F_77 ( & V_14 -> V_86 ) )
return NULL ;
}
V_92 = F_78 ( V_14 -> V_86 . V_7 , struct V_6 , V_9 ) ;
F_7 ( & V_92 -> V_9 ) ;
V_14 -> V_85 -- ;
return V_92 ;
}
static void F_79 ( struct V_13 * V_14 )
{
int V_80 = 0 ;
int V_85 = 0 ;
struct V_6 * V_6 ;
F_10 (page, &cc->migratepages, lru)
V_80 ++ ;
F_10 (page, &cc->freepages, lru)
V_85 ++ ;
V_14 -> V_80 = V_80 ;
V_14 -> V_85 = V_85 ;
}
static T_4 F_80 ( struct V_16 * V_16 ,
struct V_13 * V_14 )
{
unsigned long V_60 , V_19 ;
V_60 = F_75 ( V_14 -> V_88 , V_16 -> V_18 ) ;
V_19 = F_47 ( V_60 + 1 , V_24 ) ;
if ( V_19 > V_14 -> V_87 || ! F_20 ( V_60 ) ) {
V_14 -> V_88 = V_19 ;
return V_93 ;
}
V_60 = F_55 ( V_16 , V_14 , V_60 , V_19 , false ) ;
if ( ! V_60 || V_14 -> V_37 )
return V_94 ;
V_14 -> V_88 = V_60 ;
return V_95 ;
}
static int F_81 ( struct V_16 * V_16 ,
struct V_13 * V_14 )
{
unsigned int V_96 ;
unsigned long V_97 ;
if ( F_58 ( V_73 ) )
return V_98 ;
if ( V_14 -> V_87 <= V_14 -> V_88 ) {
V_16 -> V_21 = V_16 -> V_18 ;
V_16 -> V_22 = F_18 ( V_16 ) ;
if ( ! F_82 () )
V_16 -> V_23 = true ;
return V_99 ;
}
if ( V_14 -> V_96 == - 1 )
return V_100 ;
V_97 = F_83 ( V_16 ) ;
V_97 += ( 1 << V_14 -> V_96 ) ;
if ( ! F_84 ( V_16 , V_14 -> V_96 , V_97 , 0 , 0 ) )
return V_100 ;
for ( V_96 = V_14 -> V_96 ; V_96 < V_101 ; V_96 ++ ) {
struct V_102 * V_103 = & V_16 -> V_102 [ V_96 ] ;
if ( ! F_77 ( & V_103 -> V_104 [ V_14 -> V_11 ] ) )
return V_98 ;
if ( V_14 -> V_96 >= V_38 && V_103 -> V_105 )
return V_98 ;
}
return V_100 ;
}
unsigned long F_85 ( struct V_16 * V_16 , int V_96 )
{
int V_106 ;
unsigned long V_97 ;
if ( V_96 == - 1 )
return V_100 ;
V_97 = F_83 ( V_16 ) + ( 2UL << V_96 ) ;
if ( ! F_84 ( V_16 , 0 , V_97 , 0 , 0 ) )
return V_107 ;
V_106 = F_86 ( V_16 , V_96 ) ;
if ( V_106 >= 0 && V_106 <= V_108 )
return V_107 ;
if ( V_106 == - 1000 && F_84 ( V_16 , V_96 , V_97 ,
0 , 0 ) )
return V_98 ;
return V_100 ;
}
static int F_87 ( struct V_16 * V_16 , struct V_13 * V_14 )
{
int V_109 ;
unsigned long V_17 = V_16 -> V_18 ;
unsigned long V_19 = F_18 ( V_16 ) ;
V_109 = F_85 ( V_16 , V_14 -> V_96 ) ;
switch ( V_109 ) {
case V_98 :
case V_107 :
return V_109 ;
case V_100 :
;
}
if ( F_88 ( V_16 , V_14 -> V_96 ) && ! F_82 () )
F_17 ( V_16 ) ;
V_14 -> V_88 = V_16 -> V_21 ;
V_14 -> V_87 = V_16 -> V_22 ;
if ( V_14 -> V_87 < V_17 || V_14 -> V_87 > V_19 ) {
V_14 -> V_87 = V_19 & ~ ( V_24 - 1 ) ;
V_16 -> V_22 = V_14 -> V_87 ;
}
if ( V_14 -> V_88 < V_17 || V_14 -> V_88 > V_19 ) {
V_14 -> V_88 = V_17 ;
V_16 -> V_21 = V_14 -> V_88 ;
}
F_89 ( V_17 , V_14 -> V_88 , V_14 -> V_87 , V_19 ) ;
F_90 () ;
while ( ( V_109 = F_81 ( V_16 , V_14 ) ) == V_100 ) {
unsigned long V_110 , V_111 ;
int V_112 ;
switch ( F_80 ( V_16 , V_14 ) ) {
case V_94 :
V_109 = V_98 ;
F_91 ( & V_14 -> V_65 ) ;
V_14 -> V_80 = 0 ;
goto V_113;
case V_93 :
continue;
case V_95 :
;
}
V_110 = V_14 -> V_80 ;
V_112 = F_92 ( & V_14 -> V_65 , F_76 ,
( unsigned long ) V_14 ,
V_14 -> V_36 ? V_114 : V_115 ,
V_116 ) ;
F_79 ( V_14 ) ;
V_111 = V_14 -> V_80 ;
F_93 ( V_110 - V_111 ,
V_111 ) ;
if ( V_112 ) {
F_91 ( & V_14 -> V_65 ) ;
V_14 -> V_80 = 0 ;
if ( V_112 == - V_117 && V_14 -> V_87 > V_14 -> V_88 ) {
V_109 = V_98 ;
goto V_113;
}
}
}
V_113:
V_14 -> V_85 -= F_5 ( & V_14 -> V_86 ) ;
F_94 ( V_14 -> V_85 != 0 ) ;
F_95 ( V_109 ) ;
return V_109 ;
}
static unsigned long F_96 ( struct V_16 * V_16 ,
int V_96 , T_5 V_118 ,
bool V_36 , bool * V_37 )
{
unsigned long V_109 ;
struct V_13 V_14 = {
. V_85 = 0 ,
. V_80 = 0 ,
. V_96 = V_96 ,
. V_11 = F_97 ( V_118 ) ,
. V_16 = V_16 ,
. V_36 = V_36 ,
} ;
F_98 ( & V_14 . V_86 ) ;
F_98 ( & V_14 . V_65 ) ;
V_109 = F_87 ( V_16 , & V_14 ) ;
F_94 ( ! F_77 ( & V_14 . V_86 ) ) ;
F_94 ( ! F_77 ( & V_14 . V_65 ) ) ;
* V_37 = V_14 . V_37 ;
return V_109 ;
}
unsigned long F_99 ( struct V_119 * V_119 ,
int V_96 , T_5 V_118 , T_6 * V_120 ,
bool V_36 , bool * V_37 )
{
enum V_121 V_122 = F_100 ( V_118 ) ;
int V_123 = V_118 & V_124 ;
int V_125 = V_118 & V_126 ;
struct V_127 * V_128 ;
struct V_16 * V_16 ;
int V_129 = V_107 ;
int V_130 = 0 ;
if ( ! V_96 || ! V_123 || ! V_125 )
return V_129 ;
F_1 ( V_131 ) ;
#ifdef F_101
if ( F_97 ( V_118 ) == V_12 )
V_130 |= V_132 ;
#endif
F_102 (zone, z, zonelist, high_zoneidx,
nodemask) {
int V_133 ;
V_133 = F_96 ( V_16 , V_96 , V_118 , V_36 ,
V_37 ) ;
V_129 = F_75 ( V_133 , V_129 ) ;
if ( F_84 ( V_16 , V_96 , F_83 ( V_16 ) , 0 ,
V_130 ) )
break;
}
return V_129 ;
}
static void F_103 ( T_1 * V_25 , struct V_13 * V_14 )
{
int V_26 ;
struct V_16 * V_16 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
V_16 = & V_25 -> V_28 [ V_26 ] ;
if ( ! F_25 ( V_16 ) )
continue;
V_14 -> V_85 = 0 ;
V_14 -> V_80 = 0 ;
V_14 -> V_16 = V_16 ;
F_98 ( & V_14 -> V_86 ) ;
F_98 ( & V_14 -> V_65 ) ;
if ( V_14 -> V_96 == - 1 || ! F_104 ( V_16 , V_14 -> V_96 ) )
F_87 ( V_16 , V_14 ) ;
if ( V_14 -> V_96 > 0 ) {
if ( F_84 ( V_16 , V_14 -> V_96 ,
F_83 ( V_16 ) , 0 , 0 ) )
F_105 ( V_16 , V_14 -> V_96 , false ) ;
else if ( V_14 -> V_36 )
F_106 ( V_16 , V_14 -> V_96 ) ;
}
F_94 ( ! F_77 ( & V_14 -> V_86 ) ) ;
F_94 ( ! F_77 ( & V_14 -> V_65 ) ) ;
}
}
void F_107 ( T_1 * V_25 , int V_96 )
{
struct V_13 V_14 = {
. V_96 = V_96 ,
. V_36 = false ,
} ;
if ( ! V_96 )
return;
F_103 ( V_25 , & V_14 ) ;
}
static void F_108 ( int V_134 )
{
struct V_13 V_14 = {
. V_96 = - 1 ,
. V_36 = true ,
. V_15 = true ,
} ;
F_103 ( F_109 ( V_134 ) , & V_14 ) ;
}
static void F_110 ( void )
{
int V_134 ;
F_111 () ;
F_112 (nid)
F_108 ( V_134 ) ;
}
int F_113 ( struct V_135 * V_136 , int V_137 ,
void T_7 * V_138 , T_8 * V_139 , T_9 * V_140 )
{
if ( V_137 )
F_110 () ;
return 0 ;
}
int F_114 ( struct V_135 * V_136 , int V_137 ,
void T_7 * V_138 , T_8 * V_139 , T_9 * V_140 )
{
F_115 ( V_136 , V_137 , V_138 , V_139 , V_140 ) ;
return 0 ;
}
static T_10 F_116 ( struct V_141 * V_142 ,
struct V_143 * V_144 ,
const char * V_145 , T_8 V_8 )
{
int V_134 = V_142 -> V_146 ;
if ( V_134 >= 0 && V_134 < V_147 && F_117 ( V_134 ) ) {
F_111 () ;
F_108 ( V_134 ) ;
}
return V_8 ;
}
int F_118 ( struct V_148 * V_148 )
{
return F_119 ( & V_148 -> V_142 , & V_149 ) ;
}
void F_120 ( struct V_148 * V_148 )
{
return F_121 ( & V_148 -> V_142 , & V_149 ) ;
}
