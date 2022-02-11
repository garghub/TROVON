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
unsigned int V_5 [ V_36 ] = { 0 , } ;
F_22 (page, &cc->migratepages, lru) {
int V_6 = F_26 ( V_3 ) ;
V_5 [ V_6 ] ++ ;
}
V_25 -> V_37 = V_5 [ V_38 ] + V_5 [ V_39 ] ;
V_25 -> V_40 = V_5 [ V_41 ] + V_5 [ V_42 ] ;
F_27 ( V_7 , V_43 , V_25 -> V_37 ) ;
F_27 ( V_7 , V_44 , V_25 -> V_40 ) ;
}
static bool F_28 ( struct V_7 * V_7 )
{
unsigned long V_45 , V_46 , V_17 ;
V_46 = F_29 ( V_7 , V_47 ) +
F_29 ( V_7 , V_48 ) ;
V_45 = F_29 ( V_7 , V_49 ) +
F_29 ( V_7 , V_50 ) ;
V_17 = F_29 ( V_7 , V_44 ) +
F_29 ( V_7 , V_43 ) ;
return V_17 > ( V_46 + V_45 ) / 2 ;
}
static T_1 F_30 ( struct V_7 * V_7 ,
struct V_24 * V_25 )
{
unsigned long V_27 , V_10 ;
unsigned long V_51 = 0 , V_52 ;
unsigned long V_11 = 0 , V_53 = 0 ;
struct V_1 * V_54 = & V_25 -> V_55 ;
V_27 = F_21 ( V_25 -> V_33 , V_7 -> V_14 ) ;
V_10 = F_31 ( V_27 + V_16 , V_16 ) ;
if ( V_10 > V_25 -> V_32 || ! F_17 ( V_27 ) ) {
V_25 -> V_33 = V_10 ;
return V_56 ;
}
while ( F_32 ( F_28 ( V_7 ) ) ) {
if ( ! V_25 -> V_57 )
return V_58 ;
F_33 ( V_59 , V_60 / 10 ) ;
if ( F_34 ( V_61 ) )
return V_58 ;
}
F_35 () ;
F_36 ( & V_7 -> V_62 ) ;
for (; V_27 < V_10 ; V_27 ++ ) {
struct V_3 * V_3 ;
bool V_63 = true ;
if ( ! ( ( V_27 + 1 ) % V_64 ) ) {
F_37 ( & V_7 -> V_62 ) ;
V_63 = false ;
}
if ( F_38 () || F_39 ( & V_7 -> V_62 ) ) {
if ( V_63 )
F_37 ( & V_7 -> V_62 ) ;
F_35 () ;
F_36 ( & V_7 -> V_62 ) ;
if ( F_34 ( V_61 ) )
break;
} else if ( ! V_63 )
F_36 ( & V_7 -> V_62 ) ;
if ( ! F_7 ( V_27 ) )
continue;
V_11 ++ ;
V_3 = F_8 ( V_27 ) ;
if ( F_9 ( V_3 ) )
continue;
V_52 = V_27 >> V_22 ;
if ( ! V_25 -> V_57 && V_51 != V_52 &&
F_14 ( V_3 ) != V_23 ) {
V_27 += V_16 ;
V_27 = F_31 ( V_27 , V_16 ) - 1 ;
V_51 = V_52 ;
continue;
}
if ( ! F_40 ( V_3 ) )
continue;
if ( F_41 ( V_3 ) ) {
V_27 += ( 1 << F_42 ( V_3 ) ) - 1 ;
continue;
}
if ( F_43 ( V_3 , V_65 , 0 ) != 0 )
continue;
F_44 ( F_45 ( V_3 ) ) ;
F_46 ( V_7 , V_3 , F_47 ( V_3 ) ) ;
F_11 ( & V_3 -> V_6 , V_54 ) ;
V_25 -> V_34 ++ ;
V_53 ++ ;
if ( V_25 -> V_34 == V_66 )
break;
}
F_25 ( V_7 , V_25 ) ;
F_37 ( & V_7 -> V_62 ) ;
V_25 -> V_33 = V_27 ;
F_48 ( V_11 , V_53 ) ;
return V_67 ;
}
static struct V_3 * F_49 ( struct V_3 * V_68 ,
unsigned long V_69 ,
int * * V_70 )
{
struct V_24 * V_25 = (struct V_24 * ) V_69 ;
struct V_3 * V_71 ;
if ( F_50 ( & V_25 -> V_31 ) ) {
F_16 ( V_25 -> V_7 , V_25 ) ;
if ( F_50 ( & V_25 -> V_31 ) )
return NULL ;
}
V_71 = F_51 ( V_25 -> V_31 . V_4 , struct V_3 , V_6 ) ;
F_3 ( & V_71 -> V_6 ) ;
V_25 -> V_30 -- ;
return V_71 ;
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
unsigned int V_72 ;
unsigned long V_73 ;
if ( F_34 ( V_61 ) )
return V_74 ;
if ( V_25 -> V_32 <= V_25 -> V_33 )
return V_75 ;
if ( V_25 -> V_72 == - 1 )
return V_76 ;
V_73 = F_54 ( V_7 ) ;
V_73 += ( 1 << V_25 -> V_72 ) ;
if ( ! F_55 ( V_7 , V_25 -> V_72 , V_73 , 0 , 0 ) )
return V_76 ;
for ( V_72 = V_25 -> V_72 ; V_72 < V_77 ; V_72 ++ ) {
if ( ! F_50 ( & V_7 -> V_78 [ V_72 ] . V_79 [ V_25 -> V_19 ] ) )
return V_74 ;
if ( V_72 >= V_22 && V_7 -> V_78 [ V_72 ] . V_80 )
return V_74 ;
}
return V_76 ;
}
unsigned long F_56 ( struct V_7 * V_7 , int V_72 )
{
int V_81 ;
unsigned long V_73 ;
if ( V_72 == - 1 )
return V_76 ;
V_73 = F_54 ( V_7 ) + ( 2UL << V_72 ) ;
if ( ! F_55 ( V_7 , 0 , V_73 , 0 , 0 ) )
return V_82 ;
V_81 = F_57 ( V_7 , V_72 ) ;
if ( V_81 >= 0 && V_81 <= V_83 )
return V_82 ;
if ( V_81 == - 1000 && F_55 ( V_7 , V_72 , V_73 ,
0 , 0 ) )
return V_74 ;
return V_76 ;
}
static int F_58 ( struct V_7 * V_7 , struct V_24 * V_25 )
{
int V_84 ;
V_84 = F_56 ( V_7 , V_25 -> V_72 ) ;
switch ( V_84 ) {
case V_74 :
case V_82 :
return V_84 ;
case V_76 :
;
}
V_25 -> V_33 = V_7 -> V_14 ;
V_25 -> V_32 = V_25 -> V_33 + V_7 -> V_15 ;
V_25 -> V_32 &= ~ ( V_16 - 1 ) ;
F_59 () ;
while ( ( V_84 = F_53 ( V_7 , V_25 ) ) == V_76 ) {
unsigned long V_85 , V_86 ;
int V_87 ;
switch ( F_30 ( V_7 , V_25 ) ) {
case V_58 :
V_84 = V_74 ;
goto V_88;
case V_56 :
continue;
case V_67 :
;
}
V_85 = V_25 -> V_34 ;
V_87 = F_60 ( & V_25 -> V_55 , F_49 ,
( unsigned long ) V_25 , false ,
V_25 -> V_57 ) ;
F_52 ( V_25 ) ;
V_86 = V_25 -> V_34 ;
F_61 ( V_89 ) ;
F_62 ( V_90 , V_85 - V_86 ) ;
if ( V_86 )
F_62 ( V_91 , V_86 ) ;
F_63 ( V_85 - V_86 ,
V_86 ) ;
if ( V_87 ) {
F_64 ( & V_25 -> V_55 ) ;
V_25 -> V_34 = 0 ;
}
}
V_88:
V_25 -> V_30 -= F_1 ( & V_25 -> V_31 ) ;
F_44 ( V_25 -> V_30 != 0 ) ;
return V_84 ;
}
unsigned long F_65 ( struct V_7 * V_7 ,
int V_72 , T_2 V_92 ,
bool V_57 )
{
struct V_24 V_25 = {
. V_30 = 0 ,
. V_34 = 0 ,
. V_72 = V_72 ,
. V_19 = F_66 ( V_92 ) ,
. V_7 = V_7 ,
. V_57 = V_57 ,
} ;
F_67 ( & V_25 . V_31 ) ;
F_67 ( & V_25 . V_55 ) ;
return F_58 ( V_7 , & V_25 ) ;
}
unsigned long F_68 ( struct V_93 * V_93 ,
int V_72 , T_2 V_92 , T_3 * V_94 ,
bool V_57 )
{
enum V_95 V_96 = F_69 ( V_92 ) ;
int V_97 = V_92 & V_98 ;
int V_99 = V_92 & V_100 ;
struct V_101 * V_102 ;
struct V_7 * V_7 ;
int V_103 = V_82 ;
if ( ! V_72 || ! V_97 || ! V_99 )
return V_103 ;
F_61 ( V_104 ) ;
F_70 (zone, z, zonelist, high_zoneidx,
nodemask) {
int V_105 ;
V_105 = F_65 ( V_7 , V_72 , V_92 , V_57 ) ;
V_103 = F_21 ( V_105 , V_103 ) ;
if ( F_55 ( V_7 , V_72 , F_54 ( V_7 ) , 0 , 0 ) )
break;
}
return V_103 ;
}
static int F_71 ( int V_106 )
{
int V_107 ;
T_4 * V_108 ;
struct V_7 * V_7 ;
if ( V_106 < 0 || V_106 >= V_109 || ! F_72 ( V_106 ) )
return - V_110 ;
V_108 = F_73 ( V_106 ) ;
F_74 () ;
for ( V_107 = 0 ; V_107 < V_111 ; V_107 ++ ) {
struct V_24 V_25 = {
. V_30 = 0 ,
. V_34 = 0 ,
. V_72 = - 1 ,
} ;
V_7 = & V_108 -> V_112 [ V_107 ] ;
if ( ! F_75 ( V_7 ) )
continue;
V_25 . V_7 = V_7 ;
F_67 ( & V_25 . V_31 ) ;
F_67 ( & V_25 . V_55 ) ;
F_58 ( V_7 , & V_25 ) ;
F_44 ( ! F_50 ( & V_25 . V_31 ) ) ;
F_44 ( ! F_50 ( & V_25 . V_55 ) ) ;
}
return 0 ;
}
static int F_76 ( void )
{
int V_106 ;
F_77 (nid)
F_71 ( V_106 ) ;
return V_75 ;
}
int F_78 ( struct V_113 * V_114 , int V_115 ,
void T_5 * V_116 , T_6 * V_117 , T_7 * V_118 )
{
if ( V_115 )
return F_76 () ;
return 0 ;
}
int F_79 ( struct V_113 * V_114 , int V_115 ,
void T_5 * V_116 , T_6 * V_117 , T_7 * V_118 )
{
F_80 ( V_114 , V_115 , V_116 , V_117 , V_118 ) ;
return 0 ;
}
T_8 F_81 ( struct V_119 * V_120 ,
struct V_121 * V_122 ,
const char * V_123 , T_6 V_5 )
{
F_71 ( V_120 -> V_124 ) ;
return V_5 ;
}
int F_82 ( struct V_125 * V_125 )
{
return F_83 ( & V_125 -> V_126 , & V_127 ) ;
}
void F_84 ( struct V_125 * V_125 )
{
return F_85 ( & V_125 -> V_126 , & V_127 ) ;
}
