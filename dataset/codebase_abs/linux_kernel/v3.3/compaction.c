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
static unsigned long F_5 ( struct V_7 * V_7 ,
unsigned long V_8 ,
struct V_1 * V_2 )
{
unsigned long V_9 , V_10 ;
int V_11 = 0 , V_12 = 0 ;
struct V_3 * V_13 ;
V_9 = V_7 -> V_14 + V_7 -> V_15 ;
V_10 = F_6 ( V_8 + V_16 , V_9 ) ;
for (; V_8 < V_10 ; V_8 ++ ) {
if ( F_7 ( V_8 ) )
break;
}
V_13 = F_8 ( V_8 ) ;
for (; V_8 < V_10 ; V_8 ++ , V_13 ++ ) {
int V_17 , V_18 ;
struct V_3 * V_3 = V_13 ;
if ( ! F_7 ( V_8 ) )
continue;
V_11 ++ ;
if ( ! F_9 ( V_3 ) )
continue;
V_17 = F_10 ( V_3 ) ;
V_12 += V_17 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
F_11 ( & V_3 -> V_6 , V_2 ) ;
V_3 ++ ;
}
if ( V_17 ) {
V_8 += V_17 - 1 ;
V_13 += V_17 - 1 ;
}
}
F_12 ( V_11 , V_12 ) ;
return V_12 ;
}
static bool F_13 ( struct V_3 * V_3 )
{
int V_19 = F_14 ( V_3 ) ;
if ( V_19 == V_20 || V_19 == V_21 )
return false ;
if ( F_9 ( V_3 ) && F_15 ( V_3 ) >= V_22 )
return true ;
if ( V_19 == V_23 )
return true ;
return false ;
}
static void F_16 ( struct V_7 * V_7 ,
struct V_24 * V_25 )
{
struct V_3 * V_3 ;
unsigned long V_26 , V_27 , V_28 ;
unsigned long V_29 ;
int V_30 = V_25 -> V_30 ;
struct V_1 * V_2 = & V_25 -> V_31 ;
V_28 = V_25 -> V_32 ;
V_27 = V_25 -> V_33 + V_16 ;
V_26 = F_6 ( V_27 , V_28 ) ;
for (; V_28 > V_27 && V_25 -> V_34 > V_30 ;
V_28 -= V_16 ) {
unsigned long V_17 ;
if ( ! F_17 ( V_28 ) )
continue;
V_3 = F_8 ( V_28 ) ;
if ( F_18 ( V_3 ) != V_7 )
continue;
if ( ! F_13 ( V_3 ) )
continue;
V_17 = 0 ;
F_19 ( & V_7 -> V_35 , V_29 ) ;
if ( F_13 ( V_3 ) ) {
V_17 = F_5 ( V_7 , V_28 , V_2 ) ;
V_30 += V_17 ;
}
F_20 ( & V_7 -> V_35 , V_29 ) ;
if ( V_17 )
V_26 = F_21 ( V_26 , V_28 ) ;
}
F_22 (page, freelist, lru) {
F_23 ( V_3 , 0 ) ;
F_24 ( V_3 , 1 , 1 ) ;
}
V_25 -> V_32 = V_26 ;
V_25 -> V_30 = V_30 ;
}
static void F_25 ( struct V_7 * V_7 , struct V_24 * V_25 )
{
struct V_3 * V_3 ;
unsigned int V_5 [ 2 ] = { 0 , } ;
F_22 (page, &cc->migratepages, lru)
V_5 [ ! ! F_26 ( V_3 ) ] ++ ;
F_27 ( V_7 , V_36 , V_5 [ 0 ] ) ;
F_27 ( V_7 , V_37 , V_5 [ 1 ] ) ;
}
static bool F_28 ( struct V_7 * V_7 )
{
unsigned long V_38 , V_39 , V_17 ;
V_39 = F_29 ( V_7 , V_40 ) +
F_29 ( V_7 , V_41 ) ;
V_38 = F_29 ( V_7 , V_42 ) +
F_29 ( V_7 , V_43 ) ;
V_17 = F_29 ( V_7 , V_37 ) +
F_29 ( V_7 , V_36 ) ;
return V_17 > ( V_39 + V_38 ) / 2 ;
}
static T_1 F_30 ( struct V_7 * V_7 ,
struct V_24 * V_25 )
{
unsigned long V_27 , V_10 ;
unsigned long V_44 = 0 , V_45 ;
unsigned long V_11 = 0 , V_46 = 0 ;
struct V_1 * V_47 = & V_25 -> V_48 ;
T_2 V_49 = V_50 | V_51 ;
V_27 = F_21 ( V_25 -> V_33 , V_7 -> V_14 ) ;
V_10 = F_31 ( V_27 + V_16 , V_16 ) ;
if ( V_10 > V_25 -> V_32 || ! F_17 ( V_27 ) ) {
V_25 -> V_33 = V_10 ;
return V_52 ;
}
while ( F_32 ( F_28 ( V_7 ) ) ) {
if ( ! V_25 -> V_53 )
return V_54 ;
F_33 ( V_55 , V_56 / 10 ) ;
if ( F_34 ( V_57 ) )
return V_54 ;
}
F_35 () ;
F_36 ( & V_7 -> V_58 ) ;
for (; V_27 < V_10 ; V_27 ++ ) {
struct V_3 * V_3 ;
bool V_59 = true ;
if ( ! ( ( V_27 + 1 ) % V_60 ) ) {
F_37 ( & V_7 -> V_58 ) ;
V_59 = false ;
}
if ( F_38 () || F_39 ( & V_7 -> V_58 ) ) {
if ( V_59 )
F_37 ( & V_7 -> V_58 ) ;
F_35 () ;
F_36 ( & V_7 -> V_58 ) ;
if ( F_34 ( V_57 ) )
break;
} else if ( ! V_59 )
F_36 ( & V_7 -> V_58 ) ;
if ( ( V_27 & ( V_61 - 1 ) ) == 0 ) {
if ( ! F_17 ( V_27 ) ) {
V_27 += V_61 - 1 ;
continue;
}
}
if ( ! F_7 ( V_27 ) )
continue;
V_11 ++ ;
V_3 = F_8 ( V_27 ) ;
if ( F_18 ( V_3 ) != V_7 )
continue;
if ( F_9 ( V_3 ) )
continue;
V_45 = V_27 >> V_22 ;
if ( ! V_25 -> V_53 && V_44 != V_45 &&
F_14 ( V_3 ) != V_23 ) {
V_27 += V_16 ;
V_27 = F_31 ( V_27 , V_16 ) - 1 ;
V_44 = V_45 ;
continue;
}
if ( ! F_40 ( V_3 ) )
continue;
if ( F_41 ( V_3 ) ) {
V_27 += ( 1 << F_42 ( V_3 ) ) - 1 ;
continue;
}
if ( ! V_25 -> V_53 )
V_49 |= V_62 ;
if ( F_43 ( V_3 , V_49 , 0 ) != 0 )
continue;
F_44 ( F_45 ( V_3 ) ) ;
F_46 ( V_7 , V_3 , F_47 ( V_3 ) ) ;
F_11 ( & V_3 -> V_6 , V_47 ) ;
V_25 -> V_34 ++ ;
V_46 ++ ;
if ( V_25 -> V_34 == V_63 ) {
++ V_27 ;
break;
}
}
F_25 ( V_7 , V_25 ) ;
F_37 ( & V_7 -> V_58 ) ;
V_25 -> V_33 = V_27 ;
F_48 ( V_11 , V_46 ) ;
return V_64 ;
}
static struct V_3 * F_49 ( struct V_3 * V_65 ,
unsigned long V_66 ,
int * * V_67 )
{
struct V_24 * V_25 = (struct V_24 * ) V_66 ;
struct V_3 * V_68 ;
if ( F_50 ( & V_25 -> V_31 ) ) {
F_16 ( V_25 -> V_7 , V_25 ) ;
if ( F_50 ( & V_25 -> V_31 ) )
return NULL ;
}
V_68 = F_51 ( V_25 -> V_31 . V_4 , struct V_3 , V_6 ) ;
F_3 ( & V_68 -> V_6 ) ;
V_25 -> V_30 -- ;
return V_68 ;
}
static void F_52 ( struct V_24 * V_25 )
{
int V_34 = 0 ;
int V_30 = 0 ;
struct V_3 * V_3 ;
F_22 (page, &cc->migratepages, lru)
V_34 ++ ;
F_22 (page, &cc->freepages, lru)
V_30 ++ ;
V_25 -> V_34 = V_34 ;
V_25 -> V_30 = V_30 ;
}
static int F_53 ( struct V_7 * V_7 ,
struct V_24 * V_25 )
{
unsigned int V_69 ;
unsigned long V_70 ;
if ( F_34 ( V_57 ) )
return V_71 ;
if ( V_25 -> V_32 <= V_25 -> V_33 )
return V_72 ;
if ( V_25 -> V_69 == - 1 )
return V_73 ;
V_70 = F_54 ( V_7 ) ;
V_70 += ( 1 << V_25 -> V_69 ) ;
if ( ! F_55 ( V_7 , V_25 -> V_69 , V_70 , 0 , 0 ) )
return V_73 ;
for ( V_69 = V_25 -> V_69 ; V_69 < V_74 ; V_69 ++ ) {
if ( ! F_50 ( & V_7 -> V_75 [ V_69 ] . V_76 [ V_25 -> V_19 ] ) )
return V_71 ;
if ( V_69 >= V_22 && V_7 -> V_75 [ V_69 ] . V_77 )
return V_71 ;
}
return V_73 ;
}
unsigned long F_56 ( struct V_7 * V_7 , int V_69 )
{
int V_78 ;
unsigned long V_70 ;
if ( V_69 == - 1 )
return V_73 ;
V_70 = F_54 ( V_7 ) + ( 2UL << V_69 ) ;
if ( ! F_55 ( V_7 , 0 , V_70 , 0 , 0 ) )
return V_79 ;
V_78 = F_57 ( V_7 , V_69 ) ;
if ( V_78 >= 0 && V_78 <= V_80 )
return V_79 ;
if ( V_78 == - 1000 && F_55 ( V_7 , V_69 , V_70 ,
0 , 0 ) )
return V_71 ;
return V_73 ;
}
static int F_58 ( struct V_7 * V_7 , struct V_24 * V_25 )
{
int V_81 ;
V_81 = F_56 ( V_7 , V_25 -> V_69 ) ;
switch ( V_81 ) {
case V_71 :
case V_79 :
return V_81 ;
case V_73 :
;
}
V_25 -> V_33 = V_7 -> V_14 ;
V_25 -> V_32 = V_25 -> V_33 + V_7 -> V_15 ;
V_25 -> V_32 &= ~ ( V_16 - 1 ) ;
F_59 () ;
while ( ( V_81 = F_53 ( V_7 , V_25 ) ) == V_73 ) {
unsigned long V_82 , V_83 ;
int V_84 ;
switch ( F_30 ( V_7 , V_25 ) ) {
case V_54 :
V_81 = V_71 ;
goto V_85;
case V_52 :
continue;
case V_64 :
;
}
V_82 = V_25 -> V_34 ;
V_84 = F_60 ( & V_25 -> V_48 , F_49 ,
( unsigned long ) V_25 , false ,
V_25 -> V_53 ? V_86 : V_87 ) ;
F_52 ( V_25 ) ;
V_83 = V_25 -> V_34 ;
F_61 ( V_88 ) ;
F_62 ( V_89 , V_82 - V_83 ) ;
if ( V_83 )
F_62 ( V_90 , V_83 ) ;
F_63 ( V_82 - V_83 ,
V_83 ) ;
if ( V_84 ) {
F_64 ( & V_25 -> V_48 ) ;
V_25 -> V_34 = 0 ;
}
}
V_85:
V_25 -> V_30 -= F_1 ( & V_25 -> V_31 ) ;
F_44 ( V_25 -> V_30 != 0 ) ;
return V_81 ;
}
static unsigned long F_65 ( struct V_7 * V_7 ,
int V_69 , T_3 V_91 ,
bool V_53 )
{
struct V_24 V_25 = {
. V_30 = 0 ,
. V_34 = 0 ,
. V_69 = V_69 ,
. V_19 = F_66 ( V_91 ) ,
. V_7 = V_7 ,
. V_53 = V_53 ,
} ;
F_67 ( & V_25 . V_31 ) ;
F_67 ( & V_25 . V_48 ) ;
return F_58 ( V_7 , & V_25 ) ;
}
unsigned long F_68 ( struct V_92 * V_92 ,
int V_69 , T_3 V_91 , T_4 * V_93 ,
bool V_53 )
{
enum V_94 V_95 = F_69 ( V_91 ) ;
int V_96 = V_91 & V_97 ;
int V_98 = V_91 & V_99 ;
struct V_100 * V_101 ;
struct V_7 * V_7 ;
int V_102 = V_79 ;
if ( ! V_69 || ! V_96 || ! V_98 )
return V_102 ;
F_61 ( V_103 ) ;
F_70 (zone, z, zonelist, high_zoneidx,
nodemask) {
int V_104 ;
V_104 = F_65 ( V_7 , V_69 , V_91 , V_53 ) ;
V_102 = F_21 ( V_104 , V_102 ) ;
if ( F_55 ( V_7 , V_69 , F_54 ( V_7 ) , 0 , 0 ) )
break;
}
return V_102 ;
}
static int F_71 ( int V_105 )
{
int V_106 ;
T_5 * V_107 ;
struct V_7 * V_7 ;
if ( V_105 < 0 || V_105 >= V_108 || ! F_72 ( V_105 ) )
return - V_109 ;
V_107 = F_73 ( V_105 ) ;
F_74 () ;
for ( V_106 = 0 ; V_106 < V_110 ; V_106 ++ ) {
struct V_24 V_25 = {
. V_30 = 0 ,
. V_34 = 0 ,
. V_69 = - 1 ,
. V_53 = true ,
} ;
V_7 = & V_107 -> V_111 [ V_106 ] ;
if ( ! F_75 ( V_7 ) )
continue;
V_25 . V_7 = V_7 ;
F_67 ( & V_25 . V_31 ) ;
F_67 ( & V_25 . V_48 ) ;
F_58 ( V_7 , & V_25 ) ;
F_44 ( ! F_50 ( & V_25 . V_31 ) ) ;
F_44 ( ! F_50 ( & V_25 . V_48 ) ) ;
}
return 0 ;
}
static int F_76 ( void )
{
int V_105 ;
F_77 (nid)
F_71 ( V_105 ) ;
return V_72 ;
}
int F_78 ( struct V_112 * V_113 , int V_114 ,
void T_6 * V_115 , T_7 * V_116 , T_8 * V_117 )
{
if ( V_114 )
return F_76 () ;
return 0 ;
}
int F_79 ( struct V_112 * V_113 , int V_114 ,
void T_6 * V_115 , T_7 * V_116 , T_8 * V_117 )
{
F_80 ( V_113 , V_114 , V_115 , V_116 , V_117 ) ;
return 0 ;
}
T_9 F_81 ( struct V_118 * V_119 ,
struct V_120 * V_121 ,
const char * V_122 , T_7 V_5 )
{
F_71 ( V_119 -> V_123 ) ;
return V_5 ;
}
int F_82 ( struct V_124 * V_124 )
{
return F_83 ( & V_124 -> V_119 , & V_125 ) ;
}
void F_84 ( struct V_124 * V_124 )
{
return F_85 ( & V_124 -> V_119 , & V_125 ) ;
}
