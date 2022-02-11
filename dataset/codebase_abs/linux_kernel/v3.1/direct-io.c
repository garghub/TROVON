static void F_1 ( struct V_1 * V_1 )
{
T_1 * V_2 = F_2 ( & V_1 -> V_3 , V_4 ) ;
F_3 ( V_5 , & V_1 -> V_3 , V_4 ) ;
do {
F_4 ( V_2 , & V_5 . V_6 , V_7 ) ;
if ( F_5 ( & V_1 -> V_8 ) )
F_6 () ;
} while ( F_5 ( & V_1 -> V_8 ) );
F_7 ( V_2 , & V_5 . V_6 ) ;
}
void F_8 ( struct V_1 * V_1 )
{
if ( F_5 ( & V_1 -> V_8 ) )
F_1 ( V_1 ) ;
}
void F_9 ( struct V_1 * V_1 )
{
if ( F_10 ( & V_1 -> V_8 ) )
F_11 ( & V_1 -> V_3 , V_4 ) ;
}
static inline unsigned F_12 ( struct V_9 * V_9 )
{
return V_9 -> V_10 - V_9 -> V_11 ;
}
static int F_13 ( struct V_9 * V_9 )
{
int V_12 ;
int V_13 ;
V_13 = F_14 ( V_9 -> V_14 - V_9 -> V_15 , V_16 ) ;
V_12 = F_15 (
V_9 -> V_17 ,
V_13 ,
V_9 -> V_18 == V_19 ,
& V_9 -> V_20 [ 0 ] ) ;
if ( V_12 < 0 && V_9 -> V_21 && ( V_9 -> V_18 & V_22 ) ) {
struct V_23 * V_23 = F_16 ( 0 ) ;
if ( V_9 -> V_24 == 0 )
V_9 -> V_24 = V_12 ;
F_17 ( V_23 ) ;
V_9 -> V_20 [ 0 ] = V_23 ;
V_9 -> V_11 = 0 ;
V_9 -> V_10 = 1 ;
V_12 = 0 ;
goto V_25;
}
if ( V_12 >= 0 ) {
V_9 -> V_17 += V_12 * V_26 ;
V_9 -> V_15 += V_12 ;
V_9 -> V_11 = 0 ;
V_9 -> V_10 = V_12 ;
V_12 = 0 ;
}
V_25:
return V_12 ;
}
static struct V_23 * F_18 ( struct V_9 * V_9 )
{
if ( F_12 ( V_9 ) == 0 ) {
int V_12 ;
V_12 = F_13 ( V_9 ) ;
if ( V_12 )
return F_19 ( V_12 ) ;
F_20 ( F_12 ( V_9 ) == 0 ) ;
}
return V_9 -> V_20 [ V_9 -> V_11 ++ ] ;
}
static T_2 F_21 ( struct V_9 * V_9 , T_3 V_27 , T_2 V_12 , bool V_28 )
{
T_2 V_29 = 0 ;
if ( V_12 == - V_30 )
V_12 = 0 ;
if ( V_9 -> V_31 ) {
V_29 = V_9 -> V_31 ;
if ( ( V_9 -> V_18 == V_19 ) && ( ( V_27 + V_29 ) > V_9 -> V_32 ) )
V_29 = V_9 -> V_32 - V_27 ;
}
if ( V_12 == 0 )
V_12 = V_9 -> V_24 ;
if ( V_12 == 0 )
V_12 = V_9 -> V_33 ;
if ( V_12 == 0 )
V_12 = V_29 ;
if ( V_9 -> V_34 && V_9 -> V_31 ) {
V_9 -> V_34 ( V_9 -> V_35 , V_27 , V_29 ,
V_9 -> V_36 . V_37 , V_12 , V_28 ) ;
} else {
if ( V_28 )
F_22 ( V_9 -> V_35 , V_12 , 0 ) ;
F_9 ( V_9 -> V_1 ) ;
}
return V_12 ;
}
static void F_23 ( struct V_38 * V_38 , int error )
{
struct V_9 * V_9 = V_38 -> V_39 ;
unsigned long V_40 ;
unsigned long V_41 ;
F_24 ( V_9 , V_38 ) ;
F_25 ( & V_9 -> V_42 , V_41 ) ;
V_40 = -- V_9 -> V_43 ;
if ( V_40 == 1 && V_9 -> V_44 )
F_26 ( V_9 -> V_44 ) ;
F_27 ( & V_9 -> V_42 , V_41 ) ;
if ( V_40 == 0 ) {
F_21 ( V_9 , V_9 -> V_35 -> V_45 , 0 , true ) ;
F_28 ( V_9 ) ;
}
}
static void F_29 ( struct V_38 * V_38 , int error )
{
struct V_9 * V_9 = V_38 -> V_39 ;
unsigned long V_41 ;
F_25 ( & V_9 -> V_42 , V_41 ) ;
V_38 -> V_39 = V_9 -> V_46 ;
V_9 -> V_46 = V_38 ;
if ( -- V_9 -> V_43 == 1 && V_9 -> V_44 )
F_26 ( V_9 -> V_44 ) ;
F_27 ( & V_9 -> V_42 , V_41 ) ;
}
void F_30 ( struct V_38 * V_38 , int error )
{
struct V_9 * V_9 = V_38 -> V_39 ;
if ( V_9 -> V_28 )
F_23 ( V_38 , error ) ;
else
F_29 ( V_38 , error ) ;
}
static void
F_31 ( struct V_9 * V_9 , struct V_47 * V_48 ,
T_4 V_49 , int V_50 )
{
struct V_38 * V_38 ;
V_38 = F_32 ( V_51 , V_50 ) ;
V_38 -> V_52 = V_48 ;
V_38 -> V_53 = V_49 ;
if ( V_9 -> V_28 )
V_38 -> V_54 = F_23 ;
else
V_38 -> V_54 = F_29 ;
V_9 -> V_38 = V_38 ;
V_9 -> V_55 = V_9 -> V_56 ;
}
static void F_33 ( struct V_9 * V_9 )
{
struct V_38 * V_38 = V_9 -> V_38 ;
unsigned long V_41 ;
V_38 -> V_39 = V_9 ;
F_25 ( & V_9 -> V_42 , V_41 ) ;
V_9 -> V_43 ++ ;
F_27 ( & V_9 -> V_42 , V_41 ) ;
if ( V_9 -> V_28 && V_9 -> V_18 == V_19 )
F_34 ( V_38 ) ;
if ( V_9 -> V_57 )
V_9 -> V_57 ( V_9 -> V_18 , V_38 , V_9 -> V_1 ,
V_9 -> V_55 ) ;
else
F_35 ( V_9 -> V_18 , V_38 ) ;
V_9 -> V_38 = NULL ;
V_9 -> V_58 = 0 ;
V_9 -> V_55 = 0 ;
}
static void F_36 ( struct V_9 * V_9 )
{
while ( F_12 ( V_9 ) )
F_37 ( F_18 ( V_9 ) ) ;
}
static struct V_38 * F_38 ( struct V_9 * V_9 )
{
unsigned long V_41 ;
struct V_38 * V_38 = NULL ;
F_25 ( & V_9 -> V_42 , V_41 ) ;
while ( V_9 -> V_43 > 1 && V_9 -> V_46 == NULL ) {
F_39 ( V_7 ) ;
V_9 -> V_44 = V_59 ;
F_27 ( & V_9 -> V_42 , V_41 ) ;
F_40 () ;
F_25 ( & V_9 -> V_42 , V_41 ) ;
V_9 -> V_44 = NULL ;
}
if ( V_9 -> V_46 ) {
V_38 = V_9 -> V_46 ;
V_9 -> V_46 = V_38 -> V_39 ;
}
F_27 ( & V_9 -> V_42 , V_41 ) ;
return V_38 ;
}
static int F_24 ( struct V_9 * V_9 , struct V_38 * V_38 )
{
const int V_60 = F_41 ( V_61 , & V_38 -> V_62 ) ;
struct V_63 * V_64 = V_38 -> V_65 ;
int V_66 ;
if ( ! V_60 )
V_9 -> V_33 = - V_67 ;
if ( V_9 -> V_28 && V_9 -> V_18 == V_19 ) {
F_42 ( V_38 ) ;
} else {
for ( V_66 = 0 ; V_66 < V_38 -> V_68 ; V_66 ++ ) {
struct V_23 * V_23 = V_64 [ V_66 ] . V_69 ;
if ( V_9 -> V_18 == V_19 && ! F_43 ( V_23 ) )
F_44 ( V_23 ) ;
F_37 ( V_23 ) ;
}
F_45 ( V_38 ) ;
}
return V_60 ? 0 : - V_67 ;
}
static void F_46 ( struct V_9 * V_9 )
{
struct V_38 * V_38 ;
do {
V_38 = F_38 ( V_9 ) ;
if ( V_38 )
F_24 ( V_9 , V_38 ) ;
} while ( V_38 );
}
static int F_47 ( struct V_9 * V_9 )
{
int V_12 = 0 ;
if ( V_9 -> V_70 ++ >= 64 ) {
while ( V_9 -> V_46 ) {
unsigned long V_41 ;
struct V_38 * V_38 ;
int V_71 ;
F_25 ( & V_9 -> V_42 , V_41 ) ;
V_38 = V_9 -> V_46 ;
V_9 -> V_46 = V_38 -> V_39 ;
F_27 ( & V_9 -> V_42 , V_41 ) ;
V_71 = F_24 ( V_9 , V_38 ) ;
if ( V_12 == 0 )
V_12 = V_71 ;
}
V_9 -> V_70 = 0 ;
}
return V_12 ;
}
static int F_48 ( struct V_9 * V_9 )
{
int V_12 ;
struct V_72 * V_36 = & V_9 -> V_36 ;
T_4 V_73 ;
unsigned long V_74 ;
unsigned long V_75 ;
unsigned long V_76 ;
int V_77 ;
V_12 = V_9 -> V_24 ;
if ( V_12 == 0 ) {
F_20 ( V_9 -> V_78 >= V_9 -> V_79 ) ;
V_73 = V_9 -> V_78 >> V_9 -> V_80 ;
V_75 = V_9 -> V_79 - V_9 -> V_78 ;
V_74 = V_75 >> V_9 -> V_80 ;
V_76 = ( 1 << V_9 -> V_80 ) - 1 ;
if ( V_75 & V_76 )
V_74 ++ ;
V_36 -> V_81 = 0 ;
V_36 -> V_82 = V_74 << V_9 -> V_1 -> V_83 ;
V_77 = V_9 -> V_18 & V_22 ;
if ( V_9 -> V_41 & V_84 ) {
if ( V_9 -> V_78 < ( F_49 ( V_9 -> V_1 ) >>
V_9 -> V_85 ) )
V_77 = 0 ;
}
V_12 = (* V_9 -> V_86 )( V_9 -> V_1 , V_73 ,
V_36 , V_77 ) ;
}
return V_12 ;
}
static int F_50 ( struct V_9 * V_9 , T_4 V_87 )
{
T_4 V_88 ;
int V_12 , V_13 ;
V_12 = F_47 ( V_9 ) ;
if ( V_12 )
goto V_25;
V_88 = V_87 << ( V_9 -> V_85 - 9 ) ;
V_13 = F_14 ( V_9 -> V_89 , F_51 ( V_9 -> V_36 . V_90 ) ) ;
V_13 = F_14 ( V_13 , V_91 ) ;
F_20 ( V_13 <= 0 ) ;
F_31 ( V_9 , V_9 -> V_36 . V_90 , V_88 , V_13 ) ;
V_9 -> V_58 = 0 ;
V_25:
return V_12 ;
}
static int F_52 ( struct V_9 * V_9 )
{
int V_12 ;
V_12 = F_53 ( V_9 -> V_38 , V_9 -> V_92 ,
V_9 -> V_93 , V_9 -> V_94 ) ;
if ( V_12 == V_9 -> V_93 ) {
if ( ( V_9 -> V_93 + V_9 -> V_94 ) == V_26 )
V_9 -> V_89 -- ;
F_17 ( V_9 -> V_92 ) ;
V_9 -> V_95 = V_9 -> V_96 +
( V_9 -> V_93 >> V_9 -> V_85 ) ;
V_12 = 0 ;
} else {
V_12 = 1 ;
}
return V_12 ;
}
static int F_54 ( struct V_9 * V_9 )
{
int V_12 = 0 ;
if ( V_9 -> V_38 ) {
T_3 V_97 = V_9 -> V_56 ;
T_3 V_98 = V_9 -> V_55 +
V_9 -> V_38 -> V_99 ;
if ( V_9 -> V_95 != V_9 -> V_96 ||
V_97 != V_98 )
F_33 ( V_9 ) ;
else if ( V_9 -> V_58 )
F_33 ( V_9 ) ;
}
if ( V_9 -> V_38 == NULL ) {
V_12 = F_50 ( V_9 , V_9 -> V_96 ) ;
if ( V_12 )
goto V_25;
}
if ( F_52 ( V_9 ) != 0 ) {
F_33 ( V_9 ) ;
V_12 = F_50 ( V_9 , V_9 -> V_96 ) ;
if ( V_12 == 0 ) {
V_12 = F_52 ( V_9 ) ;
F_20 ( V_12 != 0 ) ;
}
}
V_25:
return V_12 ;
}
static int
F_55 ( struct V_9 * V_9 , struct V_23 * V_23 ,
unsigned V_27 , unsigned V_100 , T_4 V_101 )
{
int V_12 = 0 ;
if ( V_9 -> V_18 & V_22 ) {
F_56 ( V_100 ) ;
}
if ( ( V_9 -> V_92 == V_23 ) &&
( V_9 -> V_94 + V_9 -> V_93 == V_27 ) &&
( V_9 -> V_96 +
( V_9 -> V_93 >> V_9 -> V_85 ) == V_101 ) ) {
V_9 -> V_93 += V_100 ;
if ( V_9 -> V_58 ) {
V_12 = F_54 ( V_9 ) ;
F_37 ( V_9 -> V_92 ) ;
V_9 -> V_92 = NULL ;
}
goto V_25;
}
if ( V_9 -> V_92 ) {
V_12 = F_54 ( V_9 ) ;
F_37 ( V_9 -> V_92 ) ;
V_9 -> V_92 = NULL ;
if ( V_12 )
goto V_25;
}
F_17 ( V_23 ) ;
V_9 -> V_92 = V_23 ;
V_9 -> V_94 = V_27 ;
V_9 -> V_93 = V_100 ;
V_9 -> V_96 = V_101 ;
V_9 -> V_56 = V_9 -> V_78 << V_9 -> V_85 ;
V_25:
return V_12 ;
}
static void F_57 ( struct V_9 * V_9 )
{
unsigned V_102 ;
unsigned V_103 ;
V_103 = V_9 -> V_36 . V_82 >> V_9 -> V_1 -> V_83 ;
for ( V_102 = 0 ; V_102 < V_103 ; V_102 ++ ) {
F_58 ( V_9 -> V_36 . V_90 ,
V_9 -> V_36 . V_104 + V_102 ) ;
}
}
static void F_59 ( struct V_9 * V_9 , int V_105 )
{
unsigned V_106 ;
unsigned V_107 ;
unsigned V_108 ;
struct V_23 * V_23 ;
V_9 -> V_109 = 1 ;
if ( ! V_9 -> V_80 || ! F_60 ( & V_9 -> V_36 ) )
return;
V_106 = 1 << V_9 -> V_80 ;
V_107 = V_9 -> V_78 & ( V_106 - 1 ) ;
if ( ! V_107 )
return;
if ( V_105 )
V_107 = V_106 - V_107 ;
V_108 = V_107 << V_9 -> V_85 ;
V_23 = F_16 ( 0 ) ;
if ( F_55 ( V_9 , V_23 , 0 , V_108 ,
V_9 -> V_110 ) )
return;
V_9 -> V_110 += V_107 ;
}
static int F_61 ( struct V_9 * V_9 )
{
const unsigned V_85 = V_9 -> V_85 ;
const unsigned V_111 = V_26 >> V_85 ;
struct V_23 * V_23 ;
unsigned V_112 ;
struct V_72 * V_36 = & V_9 -> V_36 ;
int V_12 = 0 ;
V_112 = V_9 -> V_113 ;
while ( V_9 -> V_78 < V_9 -> V_79 ) {
V_23 = F_18 ( V_9 ) ;
if ( F_62 ( V_23 ) ) {
V_12 = F_63 ( V_23 ) ;
goto V_25;
}
while ( V_112 < V_111 ) {
unsigned V_114 = V_112 << V_85 ;
unsigned V_108 ;
unsigned V_107 ;
unsigned V_115 ;
if ( V_9 -> V_21 == 0 ) {
unsigned long V_76 ;
unsigned long V_116 ;
V_12 = F_48 ( V_9 ) ;
if ( V_12 ) {
F_37 ( V_23 ) ;
goto V_25;
}
if ( ! F_64 ( V_36 ) )
goto V_117;
V_9 -> V_21 =
V_36 -> V_82 >> V_9 -> V_85 ;
V_9 -> V_110 =
V_36 -> V_104 << V_9 -> V_80 ;
if ( F_60 ( V_36 ) )
F_57 ( V_9 ) ;
if ( ! V_9 -> V_80 )
goto V_117;
V_76 = ( 1 << V_9 -> V_80 ) - 1 ;
V_116 = ( V_9 -> V_78 & V_76 ) ;
if ( ! F_60 ( V_36 ) )
V_9 -> V_110 += V_116 ;
V_9 -> V_21 -= V_116 ;
}
V_117:
if ( ! F_64 ( V_36 ) ) {
T_3 V_118 ;
if ( V_9 -> V_18 & V_22 ) {
F_37 ( V_23 ) ;
return - V_119 ;
}
V_118 = F_65 ( F_49 ( V_9 -> V_1 ) ,
1 << V_85 ) ;
if ( V_9 -> V_78 >=
V_118 >> V_85 ) {
F_37 ( V_23 ) ;
goto V_25;
}
F_66 ( V_23 , V_112 << V_85 ,
1 << V_85 ) ;
V_9 -> V_78 ++ ;
V_112 ++ ;
goto V_120;
}
if ( F_67 ( V_9 -> V_80 && ! V_9 -> V_109 ) )
F_59 ( V_9 , 0 ) ;
V_107 = V_9 -> V_21 ;
V_115 = ( V_26 - V_114 ) >> V_85 ;
if ( V_107 > V_115 )
V_107 = V_115 ;
V_115 = V_9 -> V_79 - V_9 -> V_78 ;
if ( V_107 > V_115 )
V_107 = V_115 ;
V_108 = V_107 << V_85 ;
F_20 ( V_108 == 0 ) ;
V_9 -> V_58 = F_68 ( V_36 ) ;
V_12 = F_55 ( V_9 , V_23 , V_114 ,
V_108 , V_9 -> V_110 ) ;
if ( V_12 ) {
F_37 ( V_23 ) ;
goto V_25;
}
V_9 -> V_110 += V_107 ;
V_9 -> V_78 += V_107 ;
V_112 += V_107 ;
V_9 -> V_21 -= V_107 ;
V_120:
F_20 ( V_9 -> V_78 > V_9 -> V_79 ) ;
if ( V_9 -> V_78 == V_9 -> V_79 )
break;
}
F_37 ( V_23 ) ;
V_112 = 0 ;
}
V_25:
return V_12 ;
}
static T_2
F_69 ( int V_18 , struct V_121 * V_35 , struct V_1 * V_1 ,
const struct V_122 * V_123 , T_3 V_27 , unsigned long V_124 ,
unsigned V_85 , T_5 V_86 , T_6 V_34 ,
T_7 V_57 , struct V_9 * V_9 )
{
unsigned long V_125 ;
unsigned long V_41 ;
int V_126 ;
T_2 V_12 = 0 ;
T_2 V_71 ;
T_8 V_127 ;
V_9 -> V_1 = V_1 ;
V_9 -> V_18 = V_18 ;
V_9 -> V_85 = V_85 ;
V_9 -> V_80 = V_1 -> V_83 - V_85 ;
V_9 -> V_78 = V_27 >> V_85 ;
V_9 -> V_86 = V_86 ;
V_9 -> V_34 = V_34 ;
V_9 -> V_57 = V_57 ;
V_9 -> V_95 = - 1 ;
V_9 -> V_110 = - 1 ;
V_9 -> V_35 = V_35 ;
V_9 -> V_32 = F_49 ( V_1 ) ;
F_70 ( & V_9 -> V_42 ) ;
V_9 -> V_43 = 1 ;
if ( F_67 ( V_9 -> V_80 ) )
V_9 -> V_89 = 2 ;
for ( V_126 = 0 ; V_126 < V_124 ; V_126 ++ ) {
V_125 = ( unsigned long ) V_123 [ V_126 ] . V_128 ;
V_9 -> V_89 +=
( ( V_125 + V_123 [ V_126 ] . V_129 + V_26 - 1 ) / V_26
- V_125 / V_26 ) ;
}
for ( V_126 = 0 ; V_126 < V_124 ; V_126 ++ ) {
V_125 = ( unsigned long ) V_123 [ V_126 ] . V_128 ;
V_9 -> V_130 += V_127 = V_123 [ V_126 ] . V_129 ;
V_9 -> V_113 = ( V_125 & ~ V_131 ) >> V_85 ;
V_9 -> V_79 = V_9 -> V_78 +
( V_127 >> V_85 ) ;
V_9 -> V_11 = 0 ;
V_9 -> V_10 = 0 ;
V_9 -> V_15 = 0 ;
V_9 -> V_14 = 0 ;
if ( V_125 & ( V_26 - 1 ) ) {
V_9 -> V_14 ++ ;
V_127 -= V_26 - ( V_125 & ( V_26 - 1 ) ) ;
}
V_9 -> V_14 += ( V_127 + V_26 - 1 ) / V_26 ;
V_9 -> V_17 = V_125 ;
V_12 = F_61 ( V_9 ) ;
V_9 -> V_31 += V_123 [ V_126 ] . V_129 -
( ( V_9 -> V_79 - V_9 -> V_78 ) <<
V_85 ) ;
if ( V_12 ) {
F_36 ( V_9 ) ;
break;
}
}
if ( V_12 == - V_119 ) {
V_12 = 0 ;
}
F_59 ( V_9 , 1 ) ;
if ( V_9 -> V_92 ) {
V_71 = F_54 ( V_9 ) ;
if ( V_12 == 0 )
V_12 = V_71 ;
F_37 ( V_9 -> V_92 ) ;
V_9 -> V_92 = NULL ;
}
if ( V_9 -> V_38 )
F_33 ( V_9 ) ;
F_36 ( V_9 ) ;
if ( V_18 == V_19 && ( V_9 -> V_41 & V_132 ) )
F_71 ( & V_9 -> V_1 -> V_133 ) ;
F_20 ( V_12 == - V_30 ) ;
if ( V_9 -> V_28 && V_12 == 0 && V_9 -> V_31 &&
( ( V_18 & V_19 ) || ( V_9 -> V_31 == V_9 -> V_130 ) ) )
V_12 = - V_30 ;
if ( V_12 != - V_30 )
F_46 ( V_9 ) ;
F_25 ( & V_9 -> V_42 , V_41 ) ;
V_71 = -- V_9 -> V_43 ;
F_27 ( & V_9 -> V_42 , V_41 ) ;
if ( V_71 == 0 ) {
V_12 = F_21 ( V_9 , V_27 , V_12 , false ) ;
F_28 ( V_9 ) ;
} else
F_20 ( V_12 != - V_30 ) ;
return V_12 ;
}
T_2
F_72 ( int V_18 , struct V_121 * V_35 , struct V_1 * V_1 ,
struct V_47 * V_48 , const struct V_122 * V_123 , T_3 V_27 ,
unsigned long V_124 , T_5 V_86 , T_6 V_34 ,
T_7 V_57 , int V_41 )
{
int V_126 ;
T_8 V_130 ;
unsigned long V_134 ;
unsigned V_85 = V_1 -> V_83 ;
unsigned V_135 = 0 ;
unsigned V_136 = ( 1 << V_85 ) - 1 ;
T_2 V_137 = - V_138 ;
T_3 V_105 = V_27 ;
struct V_9 * V_9 ;
if ( V_18 & V_22 )
V_18 = V_139 ;
if ( V_48 )
V_135 = F_73 ( F_74 ( V_48 ) ) ;
if ( V_27 & V_136 ) {
if ( V_48 )
V_85 = V_135 ;
V_136 = ( 1 << V_85 ) - 1 ;
if ( V_27 & V_136 )
goto V_25;
}
for ( V_126 = 0 ; V_126 < V_124 ; V_126 ++ ) {
V_134 = ( unsigned long ) V_123 [ V_126 ] . V_128 ;
V_130 = V_123 [ V_126 ] . V_129 ;
V_105 += V_130 ;
if ( ( V_134 & V_136 ) || ( V_130 & V_136 ) ) {
if ( V_48 )
V_85 = V_135 ;
V_136 = ( 1 << V_85 ) - 1 ;
if ( ( V_134 & V_136 ) || ( V_130 & V_136 ) )
goto V_25;
}
}
if ( V_18 == V_19 && V_105 == V_27 )
return 0 ;
V_9 = F_75 ( sizeof( * V_9 ) , V_51 ) ;
V_137 = - V_140 ;
if ( ! V_9 )
goto V_25;
memset ( V_9 , 0 , F_76 ( struct V_9 , V_20 ) ) ;
V_9 -> V_41 = V_41 ;
if ( V_9 -> V_41 & V_132 ) {
if ( V_18 == V_19 ) {
struct V_141 * V_142 =
V_35 -> V_143 -> V_144 ;
F_77 ( & V_1 -> V_133 ) ;
V_137 = F_78 ( V_142 , V_27 ,
V_105 - 1 ) ;
if ( V_137 ) {
F_71 ( & V_1 -> V_133 ) ;
F_28 ( V_9 ) ;
goto V_25;
}
}
}
F_79 ( & V_1 -> V_8 ) ;
V_9 -> V_28 = ! F_80 ( V_35 ) && ! ( ( V_18 & V_22 ) &&
( V_105 > F_49 ( V_1 ) ) ) ;
V_137 = F_69 ( V_18 , V_35 , V_1 , V_123 , V_27 ,
V_124 , V_85 , V_86 , V_34 ,
V_57 , V_9 ) ;
V_25:
return V_137 ;
}
