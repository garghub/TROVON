static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
struct V_5 V_6 [] )
{
unsigned int V_7 = 0 , V_8 , V_9 , V_10 = 0 , V_11 ;
unsigned int V_12 ;
V_11 = F_2 ( V_2 ) -> V_13 ;
V_12 = V_11 + ( V_3 / V_14 ) ;
if ( V_3 % V_14 )
V_12 ++ ;
if ( V_12 > V_4 ) {
if ( F_3 ( V_2 ) )
return - V_15 ;
V_11 = F_2 ( V_2 ) -> V_13 ;
V_3 = 0 ;
}
while ( V_3 ) {
if ( V_7 == V_4 )
return - V_15 ;
V_6 [ V_7 ] . V_16 =
F_4 ( F_5 ( V_2 -> V_17 + V_10 ) ) ;
V_6 [ V_7 ] . V_18 =
( unsigned long ) ( V_2 -> V_17 + V_10 ) & V_19 ;
V_9 = F_6 (unsigned int, firstfraglen,
PI_PAGE_SIZE - frags[count].pi_off) ;
V_6 [ V_7 ] . V_20 = V_9 ;
V_3 -= V_9 ;
V_10 += V_9 ;
V_7 ++ ;
}
if ( V_11 ) {
if ( ( V_7 + V_11 ) > V_4 )
return - V_15 ;
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ ) {
V_7 = F_7 ( F_4 (
F_8 ( & F_2 ( V_2 ) -> V_6 [ V_8 ] ) ) ,
F_2 ( V_2 ) -> V_6 [ V_8 ] .
V_21 ,
F_2 ( V_2 ) -> V_6 [ V_8 ] .
V_9 , V_7 , V_4 , V_6 ) ;
if ( ! V_7 )
return - V_15 ;
}
}
if ( F_2 ( V_2 ) -> V_22 ) {
struct V_1 * V_23 ;
int V_24 ;
for ( V_23 = F_2 ( V_2 ) -> V_22 ; V_23 ;
V_23 = V_23 -> V_25 ) {
V_24 = F_1 ( V_23 ,
V_23 -> V_26 -
V_23 -> V_27 ,
V_4 - V_7 ,
& V_6 [ V_7 ] ) ;
if ( V_24 < 0 )
return V_24 ;
V_7 += V_24 ;
}
}
return V_7 ;
}
static T_1 F_9 ( struct V_28 * V_28 ,
const char T_2 * V_29 ,
T_3 V_7 , T_4 * V_30 )
{
return V_7 ;
}
static void
F_10 ( struct V_31 * V_32 )
{
struct V_33 * V_34 ;
V_34 = V_32 -> V_34 ;
F_11 ( & V_32 -> V_35 ) ;
F_12 () ;
F_13 ( V_34 ) ;
F_14 () ;
F_15 ( & V_32 -> V_36 , 0 ) ;
V_32 -> V_37 . V_38 = 0 ;
V_32 -> V_37 . V_39 = 0 ;
if ( V_32 -> V_40 )
(* V_32 -> V_40 )( V_32 -> V_41 , 0 ) ;
V_32 -> V_42 = true ;
V_32 -> V_43 = false ;
V_32 -> V_40 = NULL ;
}
static int
F_16 ( struct V_31 * V_32 ,
T_5 V_44 )
{
unsigned long V_45 ;
int V_46 ;
F_17 ( & V_32 -> V_47 , V_45 ) ;
if ( V_32 -> V_43 ) {
F_18 ( & V_32 -> V_41 -> V_48 , L_1 ,
V_49 ) ;
V_46 = - V_15 ;
goto V_50;
}
if ( V_32 -> V_42 ) {
F_18 ( & V_32 -> V_41 -> V_48 , L_2 ,
V_49 ) ;
V_46 = - V_15 ;
goto V_50;
}
if ( V_32 -> V_51 ) {
F_18 ( & V_32 -> V_41 -> V_48 ,
L_3 ,
V_49 ) ;
V_46 = - V_52 ;
goto V_50;
}
V_32 -> V_43 = true ;
V_32 -> V_40 = V_44 ;
F_19 ( & V_32 -> V_47 , V_45 ) ;
F_10 ( V_32 ) ;
return 0 ;
V_50:
F_19 ( & V_32 -> V_47 , V_45 ) ;
return V_46 ;
}
static struct V_1 *
F_20 ( struct V_33 * V_34 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_53 , V_54 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_41 = V_34 ;
V_2 -> V_26 = V_53 ;
V_2 -> V_27 = 0 ;
return V_2 ;
}
static inline void
F_22 ( struct V_55 * V_56 ,
struct V_31 * V_32 , struct V_1 * V_2 )
{
V_56 -> V_57 . V_58 = V_2 ;
V_56 -> V_57 . V_59 . V_8 . V_16 = F_4 ( F_5 ( V_2 -> V_17 ) ) ;
V_56 -> V_57 . V_59 . V_8 . V_18 =
( unsigned long ) V_2 -> V_17 & V_19 ;
V_56 -> V_57 . V_59 . V_8 . V_20 = V_2 -> V_26 ;
V_56 -> V_57 . V_59 . V_60 = V_32 -> V_61 ;
if ( ( V_56 -> V_57 . V_59 . V_8 . V_18 + V_2 -> V_26 ) <= V_14 ) {
V_56 -> V_57 . type = V_62 ;
V_56 -> V_63 = V_64 ;
if ( ! F_23 ( V_32 -> V_41 -> V_65 ,
V_66 ,
V_56 ) ) {
F_24 ( & V_32 -> V_36 ) ;
V_32 -> V_37 . V_67 ++ ;
} else {
V_32 -> V_37 . V_68 ++ ;
}
}
}
static void
F_25 ( struct V_33 * V_34 , int V_69 ,
struct V_31 * V_32 )
{
V_32 -> V_70 -> V_57 . V_71 . V_72 = V_69 ;
V_32 -> V_70 -> V_57 . V_71 . V_73 = V_34 ;
V_32 -> V_70 -> V_57 . type = V_74 ;
V_32 -> V_70 -> V_63 = V_64 ;
if ( ! F_23 ( V_32 -> V_41 -> V_65 ,
V_66 ,
V_32 -> V_70 ) )
V_32 -> V_37 . V_75 ++ ;
}
static int
F_26 ( struct V_33 * V_34 , const int V_76 )
{
struct V_31 * V_32 = F_27 ( V_34 ) ;
int V_77 ;
unsigned long V_45 ;
int V_78 = 0 ;
F_17 ( & V_32 -> V_47 , V_45 ) ;
V_32 -> V_79 = 0 ;
V_32 -> V_80 = 0 ;
F_19 ( & V_32 -> V_47 , V_45 ) ;
F_25 ( V_34 , 0 , V_32 ) ;
F_17 ( & V_32 -> V_47 , V_45 ) ;
while ( ( V_76 == V_81 ) ||
( V_78 < V_76 ) ) {
if ( V_32 -> V_80 )
break;
if ( V_32 -> V_42 || V_32 -> V_43 ) {
F_18 ( & V_34 -> V_41 , L_4 ,
V_49 ) ;
break;
}
F_28 ( V_82 ) ;
F_19 ( & V_32 -> V_47 , V_45 ) ;
V_78 += F_29 ( F_30 ( 10 ) ) ;
F_17 ( & V_32 -> V_47 , V_45 ) ;
}
if ( F_31 ( & V_32 -> V_83 ) > 1 ) {
while ( 1 ) {
F_28 ( V_82 ) ;
F_19 ( & V_32 -> V_47 , V_45 ) ;
F_29 ( F_30 ( 10 ) ) ;
F_17 ( & V_32 -> V_47 , V_45 ) ;
if ( F_31 ( & V_32 -> V_83 ) )
break;
}
}
F_19 ( & V_32 -> V_47 , V_45 ) ;
F_32 ( V_34 ) ;
F_33 ( & V_32 -> V_84 ) ;
F_34 ( & V_32 -> V_85 ) ;
for ( V_77 = 0 ; V_77 < V_32 -> V_86 ; V_77 ++ ) {
if ( V_32 -> V_87 [ V_77 ] ) {
F_35 ( V_32 -> V_87 [ V_77 ] ) ;
V_32 -> V_87 [ V_77 ] = NULL ;
}
}
return 0 ;
}
static int
F_36 ( struct V_33 * V_34 , struct V_31 * V_32 )
{
int V_77 , V_7 ;
for ( V_77 = 0 ; V_77 < V_32 -> V_86 ; V_77 ++ ) {
V_32 -> V_87 [ V_77 ] = F_20 ( V_34 ) ;
if ( ! V_32 -> V_87 [ V_77 ] )
break;
}
if ( V_77 == 0 )
return - V_88 ;
V_7 = V_77 ;
if ( V_7 < ( ( 2 * V_32 -> V_86 ) / 3 ) ) {
for ( V_77 = 0 ; V_77 < V_7 ; V_77 ++ ) {
F_35 ( V_32 -> V_87 [ V_77 ] ) ;
V_32 -> V_87 [ V_77 ] = NULL ;
}
return - V_88 ;
}
for ( V_77 = 0 ; V_77 < V_7 ; V_77 ++ )
F_22 ( V_32 -> V_70 , V_32 , V_32 -> V_87 [ V_77 ] ) ;
return 0 ;
}
static int
F_37 ( struct V_33 * V_34 , const int V_76 )
{
int V_77 ;
struct V_31 * V_32 = F_27 ( V_34 ) ;
unsigned long V_45 ;
int V_78 = 0 ;
F_38 ( & V_32 -> V_84 ) ;
V_77 = F_36 ( V_34 , V_32 ) ;
if ( V_77 < 0 ) {
F_39 ( & V_34 -> V_41 ,
L_5 , V_49 , V_77 ) ;
return V_77 ;
}
F_17 ( & V_32 -> V_47 , V_45 ) ;
V_32 -> V_79 = 1 ;
V_32 -> V_80 = 0 ;
V_32 -> V_89 = 0 ;
F_19 ( & V_32 -> V_47 , V_45 ) ;
F_25 ( V_34 , 1 , V_32 ) ;
F_17 ( & V_32 -> V_47 , V_45 ) ;
while ( ( V_76 == V_81 ) ||
( V_78 < V_76 ) ) {
if ( V_32 -> V_80 )
break;
if ( V_32 -> V_42 || V_32 -> V_43 ) {
F_18 ( & V_34 -> V_41 , L_4 ,
V_49 ) ;
break;
}
F_28 ( V_82 ) ;
F_19 ( & V_32 -> V_47 , V_45 ) ;
V_78 += F_29 ( F_30 ( 10 ) ) ;
F_17 ( & V_32 -> V_47 , V_45 ) ;
}
F_19 ( & V_32 -> V_47 , V_45 ) ;
if ( ! V_32 -> V_80 ) {
F_39 ( & V_34 -> V_41 , L_6 , V_49 ) ;
return - V_90 ;
}
F_40 ( V_34 ) ;
return 0 ;
}
static void
F_41 ( struct V_91 * V_92 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
int V_93 = 0 ;
V_32 = F_42 ( V_92 , struct V_31 , V_94 ) ;
V_34 = V_32 -> V_34 ;
F_12 () ;
if ( ! F_43 ( V_34 ) ) {
F_14 () ;
return;
}
V_93 = F_26 ( V_34 ,
V_81 ) ;
if ( V_93 )
goto V_95;
V_93 = F_37 ( V_34 ,
V_81 ) ;
if ( V_93 )
goto V_95;
F_14 () ;
return;
V_95:
F_16 ( V_32 , NULL ) ;
F_14 () ;
}
static int
F_44 ( struct V_33 * V_34 )
{
F_37 ( V_34 , V_81 ) ;
return 0 ;
}
static int
F_45 ( struct V_33 * V_34 )
{
F_26 ( V_34 , V_81 ) ;
return 0 ;
}
static unsigned long F_46 ( struct V_31 * V_32 )
{
if ( V_32 -> V_37 . V_38 >= V_32 -> V_37 . V_39 )
return V_32 -> V_37 . V_38 -
V_32 -> V_37 . V_39 ;
return ( V_96 - V_32 -> V_37 . V_39
+ V_32 -> V_37 . V_38 + 1 ) ;
}
static inline bool F_47 ( struct V_31 * V_32 ,
T_6 V_97 )
{
return ( F_46 ( V_32 ) >= V_97 ) ;
}
static inline bool F_48 ( struct V_31 * V_32 ,
T_6 V_98 )
{
return ( F_46 ( V_32 ) <= V_98 ) ;
}
static int
F_49 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_31 * V_32 ;
int V_26 , V_3 , V_99 ;
struct V_55 * V_56 = NULL ;
unsigned long V_45 ;
V_32 = F_27 ( V_34 ) ;
F_17 ( & V_32 -> V_47 , V_45 ) ;
if ( F_50 ( V_34 ) || V_32 -> V_42 ||
V_32 -> V_43 ) {
F_19 ( & V_32 -> V_47 , V_45 ) ;
V_32 -> V_100 ++ ;
F_18 ( & V_34 -> V_41 ,
L_7 , V_49 ) ;
F_35 ( V_2 ) ;
return V_101 ;
}
V_26 = V_2 -> V_26 ;
V_3 = V_2 -> V_26 - V_2 -> V_27 ;
if ( V_3 < V_102 ) {
F_19 ( & V_32 -> V_47 , V_45 ) ;
V_32 -> V_100 ++ ;
F_39 ( & V_34 -> V_41 ,
L_8 ,
V_49 , V_3 ) ;
F_35 ( V_2 ) ;
return V_101 ;
}
if ( ( V_26 < V_103 ) &&
( ( F_51 ( V_2 ) - V_2 -> V_17 ) >= V_103 ) ) {
V_99 = V_103 - V_26 ;
memset ( & V_2 -> V_17 [ V_26 ] , 0 , V_99 ) ;
V_2 -> V_104 += V_99 ;
V_2 -> V_26 += V_99 ;
V_26 += V_99 ;
V_3 += V_99 ;
}
V_56 = V_32 -> V_105 ;
memset ( V_56 , 0 , V_106 ) ;
V_56 -> V_57 . type = V_107 ;
V_56 -> V_63 = V_64 ;
V_56 -> V_57 . V_58 = V_2 ;
if ( F_47 ( V_32 ,
V_32 -> V_108 ) ) {
V_32 -> V_37 . V_109 ++ ;
if ( ! V_32 -> V_110 &&
( ( V_32 -> V_37 . V_109 & 0x3ff ) == 1 ) )
V_32 -> V_110 = 1 ;
F_32 ( V_34 ) ;
F_19 ( & V_32 -> V_47 , V_45 ) ;
V_32 -> V_100 ++ ;
F_18 ( & V_34 -> V_41 ,
L_9 ,
V_49 ) ;
F_35 ( V_2 ) ;
return V_101 ;
}
if ( V_32 -> V_110 )
V_32 -> V_110 = 0 ;
if ( V_2 -> V_111 == V_112 ) {
V_56 -> V_57 . V_113 . V_114 . V_115 = 1 ;
V_56 -> V_57 . V_113 . V_114 . V_116 = V_2 -> V_116 ;
if ( F_52 ( V_2 ) > V_2 -> V_17 ) {
V_56 -> V_57 . V_113 . V_114 . V_117 =
F_52 ( V_2 ) - V_2 -> V_17 ;
V_56 -> V_57 . V_113 . V_114 . V_117 = 1 ;
}
if ( F_53 ( V_2 ) > V_2 -> V_17 ) {
V_56 -> V_57 . V_113 . V_114 . V_118 =
F_53 ( V_2 ) - V_2 -> V_17 ;
V_56 -> V_57 . V_113 . V_114 . V_119 = 1 ;
}
V_56 -> V_57 . V_113 . V_114 . V_120 = V_2 -> V_120 ;
} else {
V_56 -> V_57 . V_113 . V_114 . V_115 = 0 ;
}
V_56 -> V_57 . V_113 . V_26 = V_26 ;
memcpy ( V_56 -> V_57 . V_113 . V_121 , V_2 -> V_17 , V_102 ) ;
V_56 -> V_57 . V_113 . V_122 =
F_1 ( V_2 , V_3 ,
V_123 ,
V_56 -> V_57 . V_113 . V_6 ) ;
if ( V_56 -> V_57 . V_113 . V_122 < 0 ) {
F_19 ( & V_32 -> V_47 , V_45 ) ;
V_32 -> V_100 ++ ;
F_39 ( & V_34 -> V_41 ,
L_10 , V_49 ) ;
F_35 ( V_2 ) ;
return V_101 ;
}
if ( F_23 ( V_32 -> V_41 -> V_65 ,
V_66 , V_56 ) ) {
F_32 ( V_34 ) ;
F_19 ( & V_32 -> V_47 , V_45 ) ;
V_32 -> V_100 ++ ;
F_18 ( & V_34 -> V_41 ,
L_11 , V_49 ) ;
F_35 ( V_2 ) ;
return V_101 ;
}
F_54 ( & V_32 -> V_85 , V_2 ) ;
V_32 -> V_124 . V_125 ++ ;
V_32 -> V_124 . V_126 += V_2 -> V_26 ;
V_32 -> V_37 . V_38 ++ ;
if ( F_47 ( V_32 ,
V_32 -> V_127 ) ) {
F_32 ( V_34 ) ;
F_18 ( & V_34 -> V_41 ,
L_12 ,
V_49 ) ;
V_32 -> V_128 ++ ;
}
F_19 ( & V_32 -> V_47 , V_45 ) ;
return V_101 ;
}
static struct V_129 *
F_55 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = F_27 ( V_34 ) ;
return & V_32 -> V_124 ;
}
static int
F_56 ( struct V_33 * V_34 , int V_130 )
{
return - V_15 ;
}
static void
F_57 ( struct V_33 * V_34 )
{
struct V_55 * V_56 ;
struct V_31 * V_32 = F_27 ( V_34 ) ;
if ( V_32 -> V_131 == V_34 -> V_45 )
return;
if ( ( V_34 -> V_45 & V_132 ) ==
( V_32 -> V_131 & V_132 ) )
goto V_133;
V_56 = F_58 ( V_106 , V_54 ) ;
if ( ! V_56 )
return;
V_56 -> V_63 = V_64 ;
V_56 -> V_57 . type = V_134 ;
V_56 -> V_57 . V_71 . V_73 = V_34 ;
V_56 -> V_57 . V_71 . V_72 =
V_34 -> V_45 & V_132 ;
F_23 ( V_32 -> V_41 -> V_65 ,
V_66 ,
V_56 ) ;
F_59 ( V_56 ) ;
V_133:
V_32 -> V_131 = V_34 -> V_45 ;
}
static void
F_60 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = F_27 ( V_34 ) ;
unsigned long V_45 ;
F_17 ( & V_32 -> V_47 , V_45 ) ;
if ( V_32 -> V_51 ) {
F_19 ( & V_32 -> V_47 , V_45 ) ;
F_18 ( & V_32 -> V_41 -> V_48 ,
L_3 ,
V_49 ) ;
return;
}
if ( ! V_32 -> V_79 ||
( V_32 -> V_42 && ! V_32 -> V_43 ) ) {
F_18 ( & V_34 -> V_41 , L_13 ,
V_49 ) ;
F_19 ( & V_32 -> V_47 , V_45 ) ;
return;
}
F_61 ( & V_32 -> V_94 ) ;
F_19 ( & V_32 -> V_47 , V_45 ) ;
}
static inline int
F_62 ( struct V_55 * V_56 , struct V_31 * V_32 ,
struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_135 V_136 ;
int V_77 = 0 , V_137 , V_138 ;
int V_139 = 0 ;
int V_140 = 0 ;
V_136 = V_56 -> V_57 . V_141 ;
switch ( V_136 . V_142 ) {
case 0 :
V_32 -> V_143 ++ ;
break;
case 1 :
V_32 -> V_144 ++ ;
break;
case 2 :
V_32 -> V_145 ++ ;
break;
default:
V_32 -> V_146 ++ ;
break;
}
for ( V_137 = 0 , V_138 = 0 ; V_137 < V_136 . V_142 ; V_137 ++ ) {
for ( V_77 = 0 ; V_77 < V_32 -> V_86 ; V_77 ++ ) {
if ( V_32 -> V_87 [ V_77 ] != V_136 . V_87 [ V_137 ] )
continue;
if ( ( V_2 ) && V_32 -> V_87 [ V_77 ] == V_2 ) {
V_32 -> V_147 ++ ;
V_139 = 1 ;
V_32 -> V_148 ++ ;
}
V_32 -> V_87 [ V_77 ] = F_20 ( V_34 ) ;
if ( ! V_32 -> V_87 [ V_77 ] ) {
V_32 -> V_149 ++ ;
V_32 -> V_150 ++ ;
V_140 = - V_88 ;
break;
}
F_22 ( V_56 , V_32 , V_32 -> V_87 [ V_77 ] ) ;
V_138 ++ ;
break;
}
}
if ( V_138 != V_136 . V_142 ) {
V_32 -> V_151 ++ ;
V_140 = - V_15 ;
}
if ( V_2 ) {
if ( V_139 ) {
F_35 ( V_2 ) ;
} else {
V_140 = - V_15 ;
V_32 -> V_152 ++ ;
}
}
return V_140 ;
}
static int
F_63 ( struct V_55 * V_56 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 , * V_153 , * V_154 ;
struct V_33 * V_34 ;
int V_137 , V_155 , V_156 ;
struct V_121 * V_157 ;
unsigned long V_45 ;
V_2 = V_56 -> V_57 . V_58 ;
V_34 = V_2 -> V_41 ;
V_32 = F_27 ( V_34 ) ;
F_17 ( & V_32 -> V_47 , V_45 ) ;
F_64 ( & V_32 -> V_36 ) ;
V_2 -> V_26 = V_56 -> V_57 . V_141 . V_158 ;
V_32 -> V_124 . V_159 ++ ;
V_32 -> V_124 . V_160 += V_2 -> V_26 ;
if ( ! ( V_32 -> V_79 && V_32 -> V_80 ) ) {
F_19 ( & V_32 -> V_47 , V_45 ) ;
F_62 ( V_56 , V_32 , V_2 , V_34 ) ;
return 0 ;
}
F_19 ( & V_32 -> V_47 , V_45 ) ;
if ( V_2 -> V_26 > V_53 ) {
if ( V_56 -> V_57 . V_141 . V_142 < 2 ) {
if ( F_62 ( V_56 , V_32 , V_2 , V_34 ) < 0 )
F_39 ( & V_32 -> V_34 -> V_41 ,
L_14 ) ;
return 0 ;
}
V_2 -> V_104 += V_53 ;
V_2 -> V_27 = V_2 -> V_26 - V_53 ;
} else {
if ( V_56 -> V_57 . V_141 . V_142 != 1 ) {
if ( F_62 ( V_56 , V_32 , V_2 , V_34 ) < 0 )
F_39 ( & V_32 -> V_34 -> V_41 ,
L_14 ) ;
return 0 ;
}
V_2 -> V_104 += V_2 -> V_26 ;
V_2 -> V_27 = 0 ;
}
V_156 = F_65 ( V_2 ) - V_2 -> V_17 ;
if ( V_56 -> V_57 . V_141 . V_87 [ 0 ] != V_2 ) {
if ( F_62 ( V_56 , V_32 , V_2 , V_34 ) < 0 )
F_39 ( & V_32 -> V_34 -> V_41 , L_14 ) ;
return 0 ;
}
if ( V_56 -> V_57 . V_141 . V_142 > 1 ) {
for ( V_137 = 1 , V_153 = NULL ;
V_137 < V_56 -> V_57 . V_141 . V_142 ; V_137 ++ ) {
V_154 = (struct V_1 * ) V_56 -> V_57 . V_141 . V_87 [ V_137 ] ;
V_154 -> V_25 = NULL ;
if ( ! V_153 )
F_2 ( V_2 ) -> V_22 = V_154 ;
else
V_153 -> V_25 = V_154 ;
V_153 = V_154 ;
V_155 = F_66 ( V_2 -> V_26 - V_156 ,
( unsigned int ) V_53 ) ;
V_154 -> V_26 = V_155 ;
V_154 -> V_104 += V_155 ;
V_154 -> V_27 = 0 ;
V_156 += V_155 ;
}
if ( V_2 -> V_26 != V_156 ) {
F_67 ( V_32 -> V_34 ,
L_15 ,
V_2 -> V_26 , V_156 ) ;
}
}
V_2 -> V_116 = F_68 ( V_2 , V_34 ) ;
V_157 = F_69 ( V_2 ) ;
V_2 -> V_120 = 0 ;
V_2 -> V_111 = V_161 ;
do {
if ( V_34 -> V_45 & V_132 )
break;
if ( V_2 -> V_162 == V_163 ) {
if ( V_34 -> V_45 & V_164 )
break;
} else if ( V_2 -> V_162 == V_165 ) {
if ( ( V_34 -> V_45 & V_166 ) &&
( F_70 ( V_34 ) ) ) {
struct V_167 * V_168 ;
int V_169 = 0 ;
F_71 (ha, netdev) {
if ( F_72 ( V_157 -> V_170 ,
V_168 -> V_171 ) ) {
V_169 = 1 ;
break;
}
}
if ( V_169 )
break;
}
} else if ( V_2 -> V_162 == V_172 ) {
break;
} else if ( V_2 -> V_162 == V_173 ) {
F_39 ( & V_32 -> V_34 -> V_41 ,
L_16 ,
V_34 -> V_174 , V_157 -> V_170 , V_34 -> V_175 ) ;
}
V_32 -> V_89 ++ ;
F_62 ( V_56 , V_32 , V_2 , V_34 ) ;
return 0 ;
} while ( 0 );
F_73 ( V_2 ) ;
V_2 = NULL ;
F_62 ( V_56 , V_32 , V_2 , V_34 ) ;
return 1 ;
}
static struct V_31 *
F_74 ( struct V_31 * V_32 , struct V_176 * V_41 )
{
V_32 -> V_41 = V_41 ;
V_32 -> V_61 = F_75 () ;
return V_32 ;
}
static void F_76 ( struct V_31 * V_32 )
{
F_59 ( V_32 -> V_87 ) ;
F_59 ( V_32 -> V_70 ) ;
F_59 ( V_32 -> V_105 ) ;
}
static T_1 F_77 ( struct V_28 * V_28 , char T_2 * V_58 ,
T_3 V_26 , T_4 * V_10 )
{
T_1 V_177 = 0 ;
int V_178 = 0 ;
struct V_31 * V_32 ;
struct V_33 * V_41 ;
char * V_179 ;
if ( V_26 > V_180 )
V_26 = V_180 ;
V_179 = F_78 ( V_26 , V_181 ) ;
if ( ! V_179 )
return - V_88 ;
F_79 () ;
F_80 (current->nsproxy->net_ns, dev) {
if ( ( V_41 -> V_182 != & V_183 ) ||
( ! F_50 ( V_41 ) ) )
continue;
V_32 = F_27 ( V_41 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_17 ,
V_41 -> V_174 ,
V_41 ,
V_41 -> V_175 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_18 , V_32 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_19 ,
V_32 -> V_86 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_20 ,
V_32 -> V_108 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_21 ,
V_32 -> V_127 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_22 ,
V_32 -> V_184 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_23 ,
V_32 -> V_110 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_24 ,
V_32 -> V_37 . V_185 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_25 ,
V_32 -> V_37 . V_186 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_26 ,
V_32 -> V_37 . V_39 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_27 ,
V_32 -> V_37 . V_187 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_28 ,
V_32 -> V_37 . V_75 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_29 ,
V_32 -> V_37 . V_188 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_30 ,
V_32 -> V_37 . V_67 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_31 ,
V_32 -> V_37 . V_68 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_32 ,
V_32 -> V_37 . V_38 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_33 ,
V_32 -> V_37 . V_109 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_34 ,
V_32 -> V_37 . V_189 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_35 , V_32 -> V_143 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_36 , V_32 -> V_144 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_37 , V_32 -> V_145 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_38 , V_32 -> V_146 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_39 ,
F_31 ( & V_32 -> V_36 ) ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_40 ,
V_32 -> V_190 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_41 ,
V_32 -> V_150 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_42 ,
V_32 -> V_147 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_43 ,
V_32 -> V_148 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_44 ,
V_32 -> V_151 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_45 ,
V_32 -> V_152 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_46 ,
V_32 -> V_89 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_47 ,
V_32 -> V_191 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_48 ,
V_32 -> V_192 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_49 ,
V_32 -> V_193 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_50 ,
V_32 -> V_100 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_51 ,
V_32 -> V_128 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_52 ,
V_32 -> V_194 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_53 ,
F_50 ( V_32 -> V_34 ) ?
L_54 : L_55 ) ;
V_178 += F_81 ( V_179 + V_178 , V_26 - V_178 ,
L_56 ,
F_46 ( V_32 ) ) ;
}
F_82 () ;
V_177 = F_83 ( V_58 , V_26 , V_10 , V_179 , V_178 ) ;
F_59 ( V_179 ) ;
return V_177 ;
}
static void
F_84 ( struct V_31 * V_32 )
{
int V_77 ;
struct V_33 * V_34 ;
struct V_55 * V_56 = V_32 -> V_70 ;
int V_195 , V_196 ;
if ( ! ( V_32 -> V_79 && V_32 -> V_80 ) )
return;
V_34 = V_32 -> V_34 ;
V_196 = 0 ;
V_195 = V_32 -> V_149 ;
while ( V_195 > 0 ) {
V_195 -- ;
for ( V_77 = 0 ; V_77 < V_32 -> V_86 ; V_77 ++ ) {
if ( V_32 -> V_87 [ V_77 ] )
continue;
V_32 -> V_87 [ V_77 ] = F_20 ( V_34 ) ;
if ( ! V_32 -> V_87 [ V_77 ] ) {
V_32 -> V_190 ++ ;
break;
}
V_196 ++ ;
F_22 ( V_56 , V_32 , V_32 -> V_87 [ V_77 ] ) ;
V_32 -> V_37 . V_189 ++ ;
}
}
V_32 -> V_149 -= V_196 ;
}
static void
F_85 ( struct V_55 * V_56 , struct V_31 * V_32 )
{
while ( ! F_86 ( V_32 -> V_41 -> V_65 ,
V_197 ,
V_56 ) )
;
}
static void
F_87 ( struct V_55 * V_56 , struct V_31 * V_32 ,
int * V_198 , int V_199 )
{
unsigned long V_45 ;
struct V_33 * V_34 ;
while ( * V_198 < V_199 ) {
if ( F_86 ( V_32 -> V_41 -> V_65 ,
V_197 ,
V_56 ) )
break;
switch ( V_56 -> V_57 . type ) {
case V_200 :
V_32 -> V_37 . V_185 ++ ;
* V_198 += F_63 ( V_56 ) ;
break;
case V_201 :
F_17 ( & V_32 -> V_47 , V_45 ) ;
V_32 -> V_37 . V_39 ++ ;
if ( V_56 -> V_57 . V_202 . V_203 )
V_32 -> V_37 . V_187 ++ ;
V_34 = ( (struct V_1 * ) V_56 -> V_57 . V_58 ) -> V_41 ;
if ( ( V_34 == V_32 -> V_34 ) &&
F_50 ( V_34 ) ) {
if ( F_48
( V_32 ,
V_32 -> V_184 ) ) {
F_88 ( V_34 ) ;
V_32 -> V_194 ++ ;
}
}
F_89 ( V_56 -> V_57 . V_58 , & V_32 -> V_85 ) ;
F_19 ( & V_32 -> V_47 , V_45 ) ;
F_35 ( V_56 -> V_57 . V_58 ) ;
break;
case V_204 :
V_32 -> V_37 . V_186 ++ ;
V_34 = (struct V_33 * )
V_56 -> V_57 . V_71 . V_73 ;
F_17 ( & V_32 -> V_47 , V_45 ) ;
V_32 -> V_80 = 1 ;
F_19 ( & V_32 -> V_47 , V_45 ) ;
if ( V_32 -> V_42 &&
V_32 -> V_43 ) {
V_32 -> V_42 = false ;
V_32 -> V_43 = false ;
F_88 ( V_34 ) ;
F_90 ( V_34 ) ;
}
break;
case V_205 :
V_34 = V_32 -> V_34 ;
if ( V_56 -> V_57 . V_71 . V_72 == 1 ) {
F_17 ( & V_32 -> V_47 , V_45 ) ;
V_32 -> V_79 = V_56 -> V_57 . V_71 . V_72 ;
F_19 ( & V_32 -> V_47 ,
V_45 ) ;
F_88 ( V_34 ) ;
F_90 ( V_34 ) ;
} else {
F_32 ( V_34 ) ;
F_91 ( V_34 ) ;
F_17 ( & V_32 -> V_47 , V_45 ) ;
V_32 -> V_79 = V_56 -> V_57 . V_71 . V_72 ;
F_19 ( & V_32 -> V_47 ,
V_45 ) ;
}
break;
default:
break;
}
}
}
static int F_92 ( struct V_206 * V_84 , int V_199 )
{
struct V_31 * V_32 = F_42 ( V_84 ,
struct V_31 ,
V_84 ) ;
int V_207 = 0 ;
F_84 ( V_32 ) ;
F_87 ( V_32 -> V_56 , V_32 , & V_207 , V_199 ) ;
if ( V_207 < V_199 )
F_93 ( V_84 , V_207 ) ;
return V_207 ;
}
static void
F_94 ( unsigned long V_208 )
{
struct V_31 * V_32 = (struct V_31 * ) V_208 ;
if ( ! F_95 (
V_32 -> V_41 -> V_65 ,
V_197 ) )
F_96 ( & V_32 -> V_84 ) ;
F_15 ( & V_32 -> V_209 , 0 ) ;
F_97 ( & V_32 -> V_35 , F_30 ( 2 ) ) ;
}
static int F_98 ( struct V_176 * V_41 )
{
struct V_31 * V_32 = NULL ;
struct V_33 * V_34 = NULL ;
int V_46 ;
int V_210 = 0 ;
T_7 V_211 ;
V_34 = F_99 ( sizeof( struct V_31 ) ) ;
if ( ! V_34 ) {
F_39 ( & V_41 -> V_48 ,
L_57 , V_49 ) ;
return - V_88 ;
}
V_34 -> V_182 = & V_183 ;
V_34 -> V_212 = 5 * V_213 ;
F_100 ( V_34 , & V_41 -> V_48 ) ;
V_34 -> V_214 = V_215 ;
V_210 = F_101 ( struct V_216 ,
V_217 . V_218 ) ;
V_46 = F_102 ( V_41 , V_210 , V_34 -> V_175 ,
V_215 ) ;
if ( V_46 < 0 ) {
F_39 ( & V_41 -> V_48 ,
L_58 ,
V_49 , V_46 ) ;
goto V_219;
}
V_32 = F_74 ( F_27 ( V_34 ) , V_41 ) ;
if ( ! V_32 ) {
F_39 ( & V_41 -> V_48 ,
L_59 , V_49 ) ;
V_46 = - V_88 ;
goto V_219;
}
F_85 ( V_32 -> V_56 , V_32 ) ;
V_32 -> V_34 = V_34 ;
F_103 ( & V_41 -> V_48 , V_32 ) ;
F_104 ( & V_32 -> V_220 ) ;
F_105 ( & V_32 -> V_47 ) ;
V_32 -> V_79 = 0 ;
F_15 ( & V_32 -> V_83 , 1 ) ;
V_210 = F_101 ( struct V_216 ,
V_217 . V_86 ) ;
V_46 = F_102 ( V_41 , V_210 ,
& V_32 -> V_86 , 4 ) ;
if ( V_46 ) {
F_39 ( & V_41 -> V_48 ,
L_60 ,
V_49 , V_46 ) ;
goto V_219;
}
V_32 -> V_87 = F_106 ( V_32 -> V_86 ,
sizeof( struct V_1 * ) , V_181 ) ;
if ( ! V_32 -> V_87 ) {
V_46 = - V_88 ;
goto V_219;
}
V_32 -> V_108 =
F_107 (unsigned long, 3 , ((devdata->num_rcv_bufs / 3) - 2)) ;
V_32 -> V_127 =
F_107 (unsigned long,
2 , (devdata->max_outstanding_net_xmits - 1)) ;
V_32 -> V_184 =
F_107 (unsigned long,
1 , (devdata->max_outstanding_net_xmits / 2)) ;
F_108 ( & V_32 -> V_85 ) ;
V_32 -> V_70 = F_58 ( V_106 , V_54 ) ;
if ( ! V_32 -> V_70 ) {
V_46 = - V_88 ;
goto V_221;
}
V_32 -> V_105 = F_58 ( V_106 , V_54 ) ;
if ( ! V_32 -> V_105 ) {
V_46 = - V_88 ;
goto V_222;
}
F_109 ( & V_32 -> V_94 , F_41 ) ;
V_32 -> V_42 = false ;
V_32 -> V_43 = false ;
V_210 = F_101 ( struct V_216 ,
V_217 . V_223 ) ;
V_46 = F_102 ( V_41 , V_210 , & V_34 -> V_223 , 4 ) ;
if ( V_46 ) {
F_39 ( & V_41 -> V_48 ,
L_61 ,
V_49 , V_46 ) ;
goto V_224;
}
F_110 ( V_34 , & V_32 -> V_84 , F_92 , V_225 ) ;
F_111 ( & V_32 -> V_35 , F_94 ,
( unsigned long ) V_32 ) ;
F_97 ( & V_32 -> V_35 , F_30 ( 2 ) ) ;
V_210 = F_101 ( struct V_216 ,
V_226 . V_211 ) ;
V_46 = F_102 ( V_41 , V_210 , & V_211 , 8 ) ;
if ( V_46 ) {
F_39 ( & V_41 -> V_48 ,
L_62 ,
V_49 , V_46 ) ;
goto V_227;
}
V_211 |= V_228 ;
V_211 |= V_229 ;
V_46 = F_112 ( V_41 , V_210 , & V_211 , 8 ) ;
if ( V_46 ) {
F_39 ( & V_41 -> V_48 ,
L_63 ,
V_49 , V_46 ) ;
goto V_227;
}
F_113 ( V_41 ) ;
V_46 = F_114 ( V_34 ) ;
if ( V_46 ) {
F_39 ( & V_41 -> V_48 ,
L_64 , V_49 , V_46 ) ;
goto V_227;
}
V_32 -> V_230 = F_115 ( V_34 -> V_174 ,
V_231 ) ;
if ( ! V_32 -> V_230 ) {
F_39 ( & V_41 -> V_48 ,
L_65 ,
V_49 , V_34 -> V_174 ) ;
V_46 = - V_88 ;
goto V_232;
}
F_116 ( & V_41 -> V_48 , L_66 ,
V_49 , V_34 -> V_174 ) ;
return 0 ;
V_232:
F_117 ( V_34 ) ;
V_227:
F_11 ( & V_32 -> V_35 ) ;
F_118 ( & V_32 -> V_84 ) ;
V_224:
F_59 ( V_32 -> V_105 ) ;
V_222:
F_59 ( V_32 -> V_70 ) ;
V_221:
F_59 ( V_32 -> V_87 ) ;
V_219:
F_119 ( V_34 ) ;
return V_46 ;
}
static void F_120 ( struct V_31 * V_32 )
{
unsigned long V_45 ;
F_17 ( & V_32 -> V_47 , V_45 ) ;
V_32 -> V_41 = NULL ;
F_19 ( & V_32 -> V_47 , V_45 ) ;
}
static void F_121 ( struct V_176 * V_41 )
{
struct V_31 * V_32 = F_122 ( & V_41 -> V_48 ) ;
struct V_33 * V_34 ;
unsigned long V_45 ;
if ( ! V_32 ) {
F_39 ( & V_41 -> V_48 , L_67 , V_49 ) ;
return;
}
F_17 ( & V_32 -> V_47 , V_45 ) ;
if ( V_32 -> V_51 ) {
F_19 ( & V_32 -> V_47 , V_45 ) ;
F_39 ( & V_41 -> V_48 , L_68 , V_49 ) ;
return;
}
V_32 -> V_51 = true ;
F_19 ( & V_32 -> V_47 , V_45 ) ;
V_34 = V_32 -> V_34 ;
if ( ! V_34 ) {
F_39 ( & V_41 -> V_48 , L_69 , V_49 ) ;
return;
}
F_123 ( & V_32 -> V_94 ) ;
F_124 ( V_32 -> V_230 ) ;
F_117 ( V_34 ) ;
F_11 ( & V_32 -> V_35 ) ;
F_118 ( & V_32 -> V_84 ) ;
F_103 ( & V_41 -> V_48 , NULL ) ;
F_120 ( V_32 ) ;
F_76 ( V_32 ) ;
F_119 ( V_34 ) ;
}
static int F_125 ( struct V_176 * V_41 ,
T_5 V_44 )
{
struct V_31 * V_32 = F_122 ( & V_41 -> V_48 ) ;
F_16 ( V_32 , V_44 ) ;
return 0 ;
}
static int F_126 ( struct V_176 * V_41 ,
T_5 V_44 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
unsigned long V_45 ;
V_32 = F_122 ( & V_41 -> V_48 ) ;
if ( ! V_32 ) {
F_39 ( & V_41 -> V_48 , L_67 , V_49 ) ;
return - V_15 ;
}
V_34 = V_32 -> V_34 ;
F_17 ( & V_32 -> V_47 , V_45 ) ;
if ( V_32 -> V_43 ) {
F_19 ( & V_32 -> V_47 , V_45 ) ;
F_39 ( & V_41 -> V_48 , L_70 ,
V_49 ) ;
return - V_15 ;
}
if ( ! V_32 -> V_42 ) {
F_19 ( & V_32 -> V_47 , V_45 ) ;
F_39 ( & V_41 -> V_48 , L_71 , V_49 ) ;
V_44 ( V_41 , 0 ) ;
return 0 ;
}
V_32 -> V_43 = true ;
F_19 ( & V_32 -> V_47 , V_45 ) ;
F_97 ( & V_32 -> V_35 , F_30 ( 2 ) ) ;
F_12 () ;
F_127 ( V_34 ) ;
F_14 () ;
V_44 ( V_41 , 0 ) ;
return 0 ;
}
static int F_128 ( void )
{
struct V_233 * V_234 ;
int V_46 = - V_88 ;
V_231 = F_115 ( L_72 , NULL ) ;
if ( ! V_231 )
return V_46 ;
V_234 = F_129 ( L_73 , V_235 , V_231 , NULL ,
& V_236 ) ;
if ( ! V_234 )
goto V_237;
V_234 = F_129 ( L_74 , V_238 , V_231 ,
NULL , & V_239 ) ;
if ( ! V_234 )
goto V_237;
V_46 = F_130 ( & V_240 ) ;
if ( V_46 )
goto V_237;
return 0 ;
V_237:
F_124 ( V_231 ) ;
return V_46 ;
}
static void F_131 ( void )
{
F_132 ( & V_240 ) ;
F_124 ( V_231 ) ;
}
