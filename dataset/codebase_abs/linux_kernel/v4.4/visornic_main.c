static unsigned int
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
F_9 ( ! V_7 ) ;
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
static T_1 F_10 ( struct V_28 * V_28 ,
const char T_2 * V_29 ,
T_3 V_7 , T_4 * V_30 )
{
return V_7 ;
}
static void
F_11 ( struct V_31 * V_32 )
{
struct V_33 * V_34 ;
V_34 = V_32 -> V_34 ;
F_12 ( & V_32 -> V_35 ) ;
F_13 () ;
F_14 ( V_34 ) ;
F_15 () ;
F_16 ( & V_32 -> V_36 , 0 ) ;
V_32 -> V_37 . V_38 = 0 ;
V_32 -> V_37 . V_39 = 0 ;
if ( V_32 -> V_40 )
(* V_32 -> V_40 )( V_32 -> V_41 , 0 ) ;
V_32 -> V_42 = true ;
V_32 -> V_43 = false ;
V_32 -> V_40 = NULL ;
}
static int
F_17 ( struct V_31 * V_32 ,
T_5 V_44 )
{
unsigned long V_45 ;
F_18 ( & V_32 -> V_46 , V_45 ) ;
if ( ! V_32 -> V_42 && ! V_32 -> V_43 ) {
if ( V_32 -> V_47 ) {
F_19 ( & V_32 -> V_46 , V_45 ) ;
F_20 ( & V_32 -> V_41 -> V_48 ,
L_1 ,
V_49 ) ;
return - V_50 ;
}
V_32 -> V_43 = true ;
V_32 -> V_40 = V_44 ;
F_19 ( & V_32 -> V_46 , V_45 ) ;
F_11 ( V_32 ) ;
} else if ( V_32 -> V_43 ) {
F_20 ( & V_32 -> V_41 -> V_48 , L_2 ,
V_49 ) ;
F_19 ( & V_32 -> V_46 , V_45 ) ;
return - V_15 ;
} else
F_19 ( & V_32 -> V_46 , V_45 ) ;
return 0 ;
}
static struct V_1 *
F_21 ( struct V_33 * V_34 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_51 , V_52 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_41 = V_34 ;
V_2 -> V_26 = V_51 ;
V_2 -> V_27 = 0 ;
return V_2 ;
}
static inline void
F_23 ( struct V_53 * V_54 ,
struct V_31 * V_32 , struct V_1 * V_2 )
{
V_54 -> V_55 . V_56 = V_2 ;
V_54 -> V_55 . V_57 . V_58 . V_16 = F_4 ( F_5 ( V_2 -> V_17 ) ) ;
V_54 -> V_55 . V_57 . V_58 . V_18 =
( unsigned long ) V_2 -> V_17 & V_19 ;
V_54 -> V_55 . V_57 . V_58 . V_20 = V_2 -> V_26 ;
V_54 -> V_55 . V_57 . V_59 = V_32 -> V_60 ;
if ( ( V_54 -> V_55 . V_57 . V_58 . V_18 + V_2 -> V_26 ) <= V_14 ) {
V_54 -> V_55 . type = V_61 ;
V_54 -> V_62 = V_63 ;
if ( F_24 ( V_32 -> V_41 -> V_64 ,
V_65 ,
V_54 ) ) {
F_25 ( & V_32 -> V_36 ) ;
V_32 -> V_37 . V_66 ++ ;
} else {
V_32 -> V_37 . V_67 ++ ;
}
}
}
static void
F_26 ( struct V_33 * V_34 , int V_68 ,
struct V_31 * V_32 )
{
V_32 -> V_69 -> V_55 . V_70 . V_71 = V_68 ;
V_32 -> V_69 -> V_55 . V_70 . V_72 = V_34 ;
V_32 -> V_69 -> V_55 . type = V_73 ;
V_32 -> V_69 -> V_62 = V_63 ;
if ( F_24 ( V_32 -> V_41 -> V_64 ,
V_65 ,
V_32 -> V_69 ) )
V_32 -> V_37 . V_74 ++ ;
}
static int
F_27 ( struct V_33 * V_34 , const int V_75 )
{
struct V_31 * V_32 = F_28 ( V_34 ) ;
int V_76 ;
unsigned long V_45 ;
int V_77 = 0 ;
F_18 ( & V_32 -> V_46 , V_45 ) ;
V_32 -> V_78 = 0 ;
V_32 -> V_79 = 0 ;
F_19 ( & V_32 -> V_46 , V_45 ) ;
F_26 ( V_34 , 0 , V_32 ) ;
F_18 ( & V_32 -> V_46 , V_45 ) ;
while ( ( V_75 == V_80 ) ||
( V_77 < V_75 ) ) {
if ( V_32 -> V_79 )
break;
if ( V_32 -> V_42 || V_32 -> V_43 ) {
F_19 ( & V_32 -> V_46 , V_45 ) ;
F_20 ( & V_34 -> V_41 , L_3 ,
V_49 ) ;
return - V_81 ;
}
F_29 ( V_82 ) ;
F_19 ( & V_32 -> V_46 , V_45 ) ;
V_77 += F_30 ( F_31 ( 10 ) ) ;
F_18 ( & V_32 -> V_46 , V_45 ) ;
}
if ( F_32 ( & V_32 -> V_83 ) > 1 ) {
while ( 1 ) {
F_29 ( V_82 ) ;
F_19 ( & V_32 -> V_46 , V_45 ) ;
F_30 ( F_31 ( 10 ) ) ;
F_18 ( & V_32 -> V_46 , V_45 ) ;
if ( F_32 ( & V_32 -> V_83 ) )
break;
}
}
F_19 ( & V_32 -> V_46 , V_45 ) ;
F_33 ( V_34 ) ;
F_34 ( & V_32 -> V_84 ) ;
F_35 ( & V_32 -> V_85 ) ;
for ( V_76 = 0 ; V_76 < V_32 -> V_86 ; V_76 ++ ) {
if ( V_32 -> V_87 [ V_76 ] ) {
F_36 ( V_32 -> V_87 [ V_76 ] ) ;
V_32 -> V_87 [ V_76 ] = NULL ;
}
}
return 0 ;
}
static int
F_37 ( struct V_33 * V_34 , struct V_31 * V_32 )
{
int V_76 , V_7 ;
for ( V_76 = 0 ; V_76 < V_32 -> V_86 ; V_76 ++ ) {
V_32 -> V_87 [ V_76 ] = F_21 ( V_34 ) ;
if ( ! V_32 -> V_87 [ V_76 ] )
break;
}
if ( V_76 == 0 )
return - V_88 ;
V_7 = V_76 ;
if ( V_7 < ( ( 2 * V_32 -> V_86 ) / 3 ) ) {
for ( V_76 = 0 ; V_76 < V_7 ; V_76 ++ ) {
F_36 ( V_32 -> V_87 [ V_76 ] ) ;
V_32 -> V_87 [ V_76 ] = NULL ;
}
return - V_88 ;
}
for ( V_76 = 0 ; V_76 < V_7 ; V_76 ++ )
F_23 ( V_32 -> V_69 , V_32 , V_32 -> V_87 [ V_76 ] ) ;
return 0 ;
}
static int
F_38 ( struct V_33 * V_34 , const int V_75 )
{
int V_76 ;
struct V_31 * V_32 = F_28 ( V_34 ) ;
unsigned long V_45 ;
int V_77 = 0 ;
V_76 = F_37 ( V_34 , V_32 ) ;
if ( V_76 < 0 ) {
F_39 ( & V_34 -> V_41 ,
L_4 , V_49 , V_76 ) ;
return V_76 ;
}
F_18 ( & V_32 -> V_46 , V_45 ) ;
V_32 -> V_78 = 1 ;
V_32 -> V_79 = 0 ;
V_32 -> V_89 = 0 ;
F_19 ( & V_32 -> V_46 , V_45 ) ;
F_40 ( & V_32 -> V_84 ) ;
F_26 ( V_34 , 1 , V_32 ) ;
F_18 ( & V_32 -> V_46 , V_45 ) ;
while ( ( V_75 == V_80 ) ||
( V_77 < V_75 ) ) {
if ( V_32 -> V_79 )
break;
if ( V_32 -> V_42 || V_32 -> V_43 ) {
F_19 ( & V_32 -> V_46 , V_45 ) ;
F_20 ( & V_34 -> V_41 , L_3 ,
V_49 ) ;
return - V_81 ;
}
F_29 ( V_82 ) ;
F_19 ( & V_32 -> V_46 , V_45 ) ;
V_77 += F_30 ( F_31 ( 10 ) ) ;
F_18 ( & V_32 -> V_46 , V_45 ) ;
}
F_19 ( & V_32 -> V_46 , V_45 ) ;
if ( ! V_32 -> V_79 ) {
F_39 ( & V_34 -> V_41 , L_5 , V_49 ) ;
return - V_81 ;
}
F_41 ( V_34 ) ;
return 0 ;
}
static void
F_42 ( struct V_90 * V_91 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
int V_92 = 0 ;
V_32 = F_43 ( V_91 , struct V_31 , V_93 ) ;
V_34 = V_32 -> V_34 ;
F_13 () ;
if ( ! F_44 ( V_34 ) ) {
F_15 () ;
return;
}
V_92 = F_27 ( V_34 ,
V_80 ) ;
if ( V_92 )
goto V_94;
V_92 = F_38 ( V_34 ,
V_80 ) ;
if ( V_92 )
goto V_94;
F_15 () ;
return;
V_94:
F_17 ( V_32 , NULL ) ;
F_15 () ;
}
static int
F_45 ( struct V_33 * V_34 )
{
F_38 ( V_34 , V_80 ) ;
return 0 ;
}
static int
F_46 ( struct V_33 * V_34 )
{
F_27 ( V_34 , V_80 ) ;
return 0 ;
}
static unsigned long F_47 ( struct V_31 * V_32 )
{
if ( V_32 -> V_37 . V_38 >= V_32 -> V_37 . V_39 )
return V_32 -> V_37 . V_38 -
V_32 -> V_37 . V_39 ;
else
return ( V_95 - V_32 -> V_37 . V_39
+ V_32 -> V_37 . V_38 + 1 ) ;
}
static inline bool F_48 ( struct V_31 * V_32 ,
T_6 V_96 )
{
return ( F_47 ( V_32 ) >= V_96 ) ;
}
static inline bool F_49 ( struct V_31 * V_32 ,
T_6 V_97 )
{
return ( F_47 ( V_32 ) <= V_97 ) ;
}
static int
F_50 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_31 * V_32 ;
int V_26 , V_3 , V_98 ;
struct V_53 * V_54 = NULL ;
unsigned long V_45 ;
V_32 = F_28 ( V_34 ) ;
F_18 ( & V_32 -> V_46 , V_45 ) ;
if ( F_51 ( V_34 ) || V_32 -> V_42 ||
V_32 -> V_43 ) {
F_19 ( & V_32 -> V_46 , V_45 ) ;
V_32 -> V_99 ++ ;
F_20 ( & V_34 -> V_41 ,
L_6 , V_49 ) ;
F_36 ( V_2 ) ;
return V_100 ;
}
V_26 = V_2 -> V_26 ;
V_3 = V_2 -> V_26 - V_2 -> V_27 ;
if ( V_3 < V_101 ) {
F_19 ( & V_32 -> V_46 , V_45 ) ;
V_32 -> V_99 ++ ;
F_39 ( & V_34 -> V_41 ,
L_7 ,
V_49 , V_3 ) ;
F_36 ( V_2 ) ;
return V_100 ;
}
if ( ( V_26 < V_102 ) &&
( ( F_52 ( V_2 ) - V_2 -> V_17 ) >= V_102 ) ) {
V_98 = V_102 - V_26 ;
memset ( & V_2 -> V_17 [ V_26 ] , 0 , V_98 ) ;
V_2 -> V_103 += V_98 ;
V_2 -> V_26 += V_98 ;
V_26 += V_98 ;
V_3 += V_98 ;
}
V_54 = V_32 -> V_104 ;
memset ( V_54 , 0 , V_105 ) ;
V_54 -> V_55 . type = V_106 ;
V_54 -> V_62 = V_63 ;
V_54 -> V_55 . V_56 = V_2 ;
if ( F_48 ( V_32 ,
V_32 -> V_107 ) ) {
V_32 -> V_37 . V_108 ++ ;
if ( ! V_32 -> V_109 &&
( ( V_32 -> V_37 . V_108 & 0x3ff ) == 1 ) )
V_32 -> V_109 = 1 ;
F_33 ( V_34 ) ;
F_19 ( & V_32 -> V_46 , V_45 ) ;
V_32 -> V_99 ++ ;
F_20 ( & V_34 -> V_41 ,
L_8 ,
V_49 ) ;
F_36 ( V_2 ) ;
return V_100 ;
}
if ( V_32 -> V_109 )
V_32 -> V_109 = 0 ;
if ( V_2 -> V_110 == V_111 ) {
V_54 -> V_55 . V_112 . V_113 . V_114 = 1 ;
V_54 -> V_55 . V_112 . V_113 . V_115 = V_2 -> V_115 ;
if ( F_53 ( V_2 ) > V_2 -> V_17 ) {
V_54 -> V_55 . V_112 . V_113 . V_116 =
F_53 ( V_2 ) - V_2 -> V_17 ;
V_54 -> V_55 . V_112 . V_113 . V_116 = 1 ;
}
if ( F_54 ( V_2 ) > V_2 -> V_17 ) {
V_54 -> V_55 . V_112 . V_113 . V_117 =
F_54 ( V_2 ) - V_2 -> V_17 ;
V_54 -> V_55 . V_112 . V_113 . V_118 = 1 ;
}
V_54 -> V_55 . V_112 . V_113 . V_119 = V_2 -> V_119 ;
} else {
V_54 -> V_55 . V_112 . V_113 . V_114 = 0 ;
}
V_54 -> V_55 . V_112 . V_26 = V_26 ;
memcpy ( V_54 -> V_55 . V_112 . V_120 , V_2 -> V_17 , V_101 ) ;
V_54 -> V_55 . V_112 . V_121 =
F_1 ( V_2 , V_3 ,
V_122 ,
V_54 -> V_55 . V_112 . V_6 ) ;
if ( V_54 -> V_55 . V_112 . V_121 < 0 ) {
F_19 ( & V_32 -> V_46 , V_45 ) ;
V_32 -> V_99 ++ ;
F_39 ( & V_34 -> V_41 ,
L_9 , V_49 ) ;
F_36 ( V_2 ) ;
return V_100 ;
}
if ( ! F_24 ( V_32 -> V_41 -> V_64 ,
V_65 , V_54 ) ) {
F_33 ( V_34 ) ;
F_19 ( & V_32 -> V_46 , V_45 ) ;
V_32 -> V_99 ++ ;
F_20 ( & V_34 -> V_41 ,
L_10 , V_49 ) ;
F_36 ( V_2 ) ;
return V_100 ;
}
F_55 ( & V_32 -> V_85 , V_2 ) ;
V_32 -> V_123 . V_124 ++ ;
V_32 -> V_123 . V_125 += V_2 -> V_26 ;
V_32 -> V_37 . V_38 ++ ;
if ( F_48 ( V_32 ,
V_32 -> V_126 ) ) {
F_33 ( V_34 ) ;
F_20 ( & V_34 -> V_41 ,
L_11 ,
V_49 ) ;
V_32 -> V_127 ++ ;
}
F_19 ( & V_32 -> V_46 , V_45 ) ;
return V_100 ;
}
static struct V_128 *
F_56 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = F_28 ( V_34 ) ;
return & V_32 -> V_123 ;
}
static int
F_57 ( struct V_33 * V_34 , int V_129 )
{
return - V_15 ;
}
static void
F_58 ( struct V_33 * V_34 )
{
struct V_53 * V_54 ;
struct V_31 * V_32 = F_28 ( V_34 ) ;
if ( V_32 -> V_130 != V_34 -> V_45 ) {
if ( ( V_34 -> V_45 & V_131 ) !=
( V_32 -> V_130 & V_131 ) ) {
V_54 = F_59 ( V_105 , V_52 ) ;
if ( ! V_54 )
return;
V_54 -> V_62 = V_63 ;
V_54 -> V_55 . type = V_132 ;
V_54 -> V_55 . V_70 . V_72 = V_34 ;
V_54 -> V_55 . V_70 . V_71 =
( V_34 -> V_45 & V_131 ) ;
F_24 ( V_32 -> V_41 -> V_64 ,
V_65 ,
V_54 ) ;
F_60 ( V_54 ) ;
}
V_32 -> V_130 = V_34 -> V_45 ;
}
}
static void
F_61 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = F_28 ( V_34 ) ;
unsigned long V_45 ;
F_18 ( & V_32 -> V_46 , V_45 ) ;
if ( V_32 -> V_47 ) {
F_19 ( & V_32 -> V_46 , V_45 ) ;
F_20 ( & V_32 -> V_41 -> V_48 ,
L_1 ,
V_49 ) ;
return;
}
if ( ! V_32 -> V_78 ||
( V_32 -> V_42 && ! V_32 -> V_43 ) ) {
F_20 ( & V_34 -> V_41 , L_12 ,
V_49 ) ;
F_19 ( & V_32 -> V_46 , V_45 ) ;
return;
}
F_62 ( V_133 , & V_32 -> V_93 ) ;
F_19 ( & V_32 -> V_46 , V_45 ) ;
}
static inline int
F_63 ( struct V_53 * V_54 , struct V_31 * V_32 ,
struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_134 V_135 ;
int V_76 = 0 , V_136 , V_137 ;
int V_138 = 0 ;
int V_139 = 0 ;
V_135 = V_54 -> V_55 . V_140 ;
switch ( V_135 . V_141 ) {
case 0 :
V_32 -> V_142 ++ ;
break;
case 1 :
V_32 -> V_143 ++ ;
break;
case 2 :
V_32 -> V_144 ++ ;
break;
default:
V_32 -> V_145 ++ ;
break;
}
for ( V_136 = 0 , V_137 = 0 ; V_136 < V_135 . V_141 ; V_136 ++ ) {
for ( V_76 = 0 ; V_76 < V_32 -> V_86 ; V_76 ++ ) {
if ( V_32 -> V_87 [ V_76 ] != V_135 . V_87 [ V_136 ] )
continue;
if ( ( V_2 ) && V_32 -> V_87 [ V_76 ] == V_2 ) {
V_32 -> V_146 ++ ;
V_138 = 1 ;
V_32 -> V_147 ++ ;
}
V_32 -> V_87 [ V_76 ] = F_21 ( V_34 ) ;
if ( ! V_32 -> V_87 [ V_76 ] ) {
V_32 -> V_148 ++ ;
V_32 -> V_149 ++ ;
V_139 = - V_88 ;
break;
}
F_23 ( V_54 , V_32 , V_32 -> V_87 [ V_76 ] ) ;
V_137 ++ ;
break;
}
}
if ( V_137 != V_135 . V_141 ) {
V_32 -> V_150 ++ ;
V_139 = - V_15 ;
}
if ( V_2 ) {
if ( V_138 ) {
F_36 ( V_2 ) ;
} else {
V_139 = - V_15 ;
V_32 -> V_151 ++ ;
}
}
return V_139 ;
}
static int
F_64 ( struct V_53 * V_54 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 , * V_152 , * V_153 ;
struct V_33 * V_34 ;
int V_136 , V_154 , V_155 ;
struct V_120 * V_156 ;
unsigned long V_45 ;
int V_157 = 0 ;
V_2 = V_54 -> V_55 . V_56 ;
V_34 = V_2 -> V_41 ;
V_32 = F_28 ( V_34 ) ;
F_18 ( & V_32 -> V_46 , V_45 ) ;
F_65 ( & V_32 -> V_36 ) ;
V_2 -> V_26 = V_54 -> V_55 . V_140 . V_158 ;
V_32 -> V_123 . V_159 ++ ;
V_32 -> V_123 . V_160 += V_2 -> V_26 ;
if ( ! ( V_32 -> V_78 && V_32 -> V_79 ) ) {
F_19 ( & V_32 -> V_46 , V_45 ) ;
F_63 ( V_54 , V_32 , V_2 , V_34 ) ;
return V_157 ;
}
F_19 ( & V_32 -> V_46 , V_45 ) ;
if ( V_2 -> V_26 > V_51 ) {
if ( V_54 -> V_55 . V_140 . V_141 < 2 ) {
if ( F_63 ( V_54 , V_32 , V_2 , V_34 ) < 0 )
F_39 ( & V_32 -> V_34 -> V_41 ,
L_13 ) ;
return V_157 ;
}
V_2 -> V_103 += V_51 ;
V_2 -> V_27 = V_2 -> V_26 - V_51 ;
} else {
if ( V_54 -> V_55 . V_140 . V_141 != 1 ) {
if ( F_63 ( V_54 , V_32 , V_2 , V_34 ) < 0 )
F_39 ( & V_32 -> V_34 -> V_41 ,
L_13 ) ;
return V_157 ;
}
V_2 -> V_103 += V_2 -> V_26 ;
V_2 -> V_27 = 0 ;
}
V_155 = F_66 ( V_2 ) - V_2 -> V_17 ;
if ( V_54 -> V_55 . V_140 . V_87 [ 0 ] != V_2 ) {
if ( F_63 ( V_54 , V_32 , V_2 , V_34 ) < 0 )
F_39 ( & V_32 -> V_34 -> V_41 , L_13 ) ;
return V_157 ;
}
if ( V_54 -> V_55 . V_140 . V_141 > 1 ) {
for ( V_136 = 1 , V_152 = NULL ;
V_136 < V_54 -> V_55 . V_140 . V_141 ; V_136 ++ ) {
V_153 = (struct V_1 * ) V_54 -> V_55 . V_140 . V_87 [ V_136 ] ;
V_153 -> V_25 = NULL ;
if ( ! V_152 )
F_2 ( V_2 ) -> V_22 = V_153 ;
else
V_152 -> V_25 = V_153 ;
V_152 = V_153 ;
V_154 = F_67 ( V_2 -> V_26 - V_155 ,
( unsigned int ) V_51 ) ;
V_153 -> V_26 = V_154 ;
V_153 -> V_103 += V_154 ;
V_153 -> V_27 = 0 ;
V_155 += V_154 ;
}
if ( V_2 -> V_26 != V_155 ) {
F_68 ( V_32 -> V_34 ,
L_14 ,
V_2 -> V_26 , V_155 ) ;
}
}
V_2 -> V_115 = F_69 ( V_2 , V_34 ) ;
V_156 = F_70 ( V_2 ) ;
V_2 -> V_119 = 0 ;
V_2 -> V_110 = V_161 ;
do {
if ( V_34 -> V_45 & V_131 )
break;
if ( V_2 -> V_162 == V_163 ) {
if ( V_34 -> V_45 & V_164 )
break;
} else if ( V_2 -> V_162 == V_165 ) {
if ( ( V_34 -> V_45 & V_166 ) &&
( F_71 ( V_34 ) ) ) {
struct V_167 * V_168 ;
int V_169 = 0 ;
F_72 (ha, netdev) {
if ( F_73 ( V_156 -> V_170 ,
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
L_15 ,
V_34 -> V_174 , V_156 -> V_170 , V_34 -> V_175 ) ;
}
V_32 -> V_89 ++ ;
F_63 ( V_54 , V_32 , V_2 , V_34 ) ;
return V_157 ;
} while ( 0 );
V_157 ++ ;
F_74 ( V_2 ) ;
V_2 = NULL ;
F_63 ( V_54 , V_32 , V_2 , V_34 ) ;
return V_157 ;
}
static struct V_31 *
F_75 ( struct V_31 * V_32 , struct V_176 * V_41 )
{
if ( ! V_32 )
return NULL ;
memset ( V_32 , '\0' , sizeof( struct V_31 ) ) ;
V_32 -> V_41 = V_41 ;
V_32 -> V_60 = F_76 () ;
return V_32 ;
}
static void F_77 ( struct V_31 * V_32 )
{
F_60 ( V_32 -> V_87 ) ;
F_60 ( V_32 -> V_69 ) ;
F_60 ( V_32 -> V_104 ) ;
}
static T_1 F_78 ( struct V_28 * V_28 , char T_2 * V_56 ,
T_3 V_26 , T_4 * V_10 )
{
T_1 V_177 = 0 ;
int V_178 = 0 ;
struct V_31 * V_32 ;
struct V_33 * V_41 ;
char * V_179 ;
if ( V_26 > V_180 )
V_26 = V_180 ;
V_179 = F_79 ( V_26 , V_181 ) ;
if ( ! V_179 )
return - V_88 ;
F_80 () ;
F_81 (current->nsproxy->net_ns, dev) {
if ( ( V_41 -> V_182 != & V_183 ) ||
( ! F_51 ( V_41 ) ) )
continue;
V_32 = F_28 ( V_41 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_16 ,
V_41 -> V_174 ,
V_41 ,
V_41 -> V_175 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_17 , V_32 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_18 ,
V_32 -> V_86 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_19 ,
V_32 -> V_107 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_20 ,
V_32 -> V_126 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_21 ,
V_32 -> V_184 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_22 ,
V_32 -> V_109 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_23 ,
V_32 -> V_37 . V_185 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_24 ,
V_32 -> V_37 . V_186 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_25 ,
V_32 -> V_37 . V_39 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_26 ,
V_32 -> V_37 . V_187 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_27 ,
V_32 -> V_37 . V_74 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_28 ,
V_32 -> V_37 . V_188 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_29 ,
V_32 -> V_37 . V_66 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_30 ,
V_32 -> V_37 . V_67 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_31 ,
V_32 -> V_37 . V_38 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_32 ,
V_32 -> V_37 . V_108 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_33 ,
V_32 -> V_37 . V_189 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_34 , V_32 -> V_142 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_35 , V_32 -> V_143 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_36 , V_32 -> V_144 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_37 , V_32 -> V_145 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_38 ,
F_32 ( & V_32 -> V_36 ) ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_39 ,
V_32 -> V_190 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_40 ,
V_32 -> V_149 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_41 ,
V_32 -> V_146 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_42 ,
V_32 -> V_147 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_43 ,
V_32 -> V_150 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_44 ,
V_32 -> V_151 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_45 ,
V_32 -> V_89 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_46 ,
V_32 -> V_191 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_47 ,
V_32 -> V_192 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_48 ,
V_32 -> V_193 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_49 ,
V_32 -> V_99 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_50 ,
V_32 -> V_127 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_51 ,
V_32 -> V_194 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_52 ,
F_51 ( V_32 -> V_34 ) ?
L_53 : L_54 ) ;
V_178 += F_82 ( V_179 + V_178 , V_26 - V_178 ,
L_55 ,
F_47 ( V_32 ) ) ;
}
F_83 () ;
V_177 = F_84 ( V_56 , V_26 , V_10 , V_179 , V_178 ) ;
F_60 ( V_179 ) ;
return V_177 ;
}
static void
F_85 ( struct V_31 * V_32 )
{
int V_76 ;
struct V_33 * V_34 ;
struct V_53 * V_54 = V_32 -> V_69 ;
int V_195 , V_196 ;
if ( ! ( V_32 -> V_78 && V_32 -> V_79 ) )
return;
V_34 = V_32 -> V_34 ;
V_196 = 0 ;
V_195 = V_32 -> V_148 ;
while ( V_195 > 0 ) {
V_195 -- ;
for ( V_76 = 0 ; V_76 < V_32 -> V_86 ; V_76 ++ ) {
if ( V_32 -> V_87 [ V_76 ] )
continue;
V_32 -> V_87 [ V_76 ] = F_21 ( V_34 ) ;
if ( ! V_32 -> V_87 [ V_76 ] ) {
V_32 -> V_190 ++ ;
break;
}
V_196 ++ ;
F_23 ( V_54 , V_32 , V_32 -> V_87 [ V_76 ] ) ;
V_32 -> V_37 . V_189 ++ ;
}
}
V_32 -> V_148 -= V_196 ;
}
static void
F_86 ( struct V_53 * V_54 , struct V_31 * V_32 )
{
while ( F_87 ( V_32 -> V_41 -> V_64 ,
V_197 ,
V_54 ) )
;
}
static void
F_88 ( struct V_53 * V_54 , struct V_31 * V_32 ,
int * V_198 )
{
unsigned long V_45 ;
struct V_33 * V_34 ;
for (; ; ) {
if ( ! F_87 ( V_32 -> V_41 -> V_64 ,
V_197 ,
V_54 ) )
break;
switch ( V_54 -> V_55 . type ) {
case V_199 :
V_32 -> V_37 . V_185 ++ ;
* V_198 += F_64 ( V_54 ) ;
break;
case V_200 :
F_18 ( & V_32 -> V_46 , V_45 ) ;
V_32 -> V_37 . V_39 ++ ;
if ( V_54 -> V_55 . V_201 . V_202 )
V_32 -> V_37 . V_187 ++ ;
V_34 = ( (struct V_1 * ) V_54 -> V_55 . V_56 ) -> V_41 ;
if ( ( V_34 == V_32 -> V_34 ) &&
F_51 ( V_34 ) ) {
if ( F_49 ( V_32 ,
V_32 -> V_184 ) ) {
F_89 ( V_34 ) ;
V_32 -> V_194 ++ ;
}
}
F_90 ( V_54 -> V_55 . V_56 , & V_32 -> V_85 ) ;
F_19 ( & V_32 -> V_46 , V_45 ) ;
F_36 ( V_54 -> V_55 . V_56 ) ;
break;
case V_203 :
V_32 -> V_37 . V_186 ++ ;
V_34 = (struct V_33 * )
V_54 -> V_55 . V_70 . V_72 ;
F_18 ( & V_32 -> V_46 , V_45 ) ;
V_32 -> V_79 = 1 ;
F_19 ( & V_32 -> V_46 , V_45 ) ;
if ( V_32 -> V_42 &&
V_32 -> V_43 ) {
V_32 -> V_42 = false ;
V_32 -> V_43 = false ;
F_89 ( V_34 ) ;
F_91 ( V_34 ) ;
}
break;
case V_204 :
V_34 = V_32 -> V_34 ;
if ( V_54 -> V_55 . V_70 . V_71 == 1 ) {
F_18 ( & V_32 -> V_46 , V_45 ) ;
V_32 -> V_78 = V_54 -> V_55 . V_70 . V_71 ;
F_19 ( & V_32 -> V_46 ,
V_45 ) ;
F_89 ( V_34 ) ;
F_91 ( V_34 ) ;
} else {
F_33 ( V_34 ) ;
F_92 ( V_34 ) ;
F_18 ( & V_32 -> V_46 , V_45 ) ;
V_32 -> V_78 = V_54 -> V_55 . V_70 . V_71 ;
F_19 ( & V_32 -> V_46 ,
V_45 ) ;
}
break;
default:
break;
}
}
}
static int F_93 ( struct V_205 * V_84 , int V_206 )
{
struct V_31 * V_32 = F_43 ( V_84 ,
struct V_31 ,
V_84 ) ;
int V_157 = 0 ;
F_85 ( V_32 ) ;
F_88 ( V_32 -> V_54 , V_32 , & V_157 ) ;
if ( V_157 < V_206 )
F_94 ( V_84 ) ;
return V_157 ;
}
static void
F_95 ( unsigned long V_207 )
{
struct V_31 * V_32 = (struct V_31 * ) V_207 ;
if ( ! F_96 (
V_32 -> V_41 -> V_64 ,
V_197 ) )
F_97 ( & V_32 -> V_84 ) ;
F_16 ( & V_32 -> V_208 , 0 ) ;
F_98 ( & V_32 -> V_35 , F_31 ( 2 ) ) ;
}
static int F_99 ( struct V_176 * V_41 )
{
struct V_31 * V_32 = NULL ;
struct V_33 * V_34 = NULL ;
int V_209 ;
int V_210 = 0 ;
T_7 V_211 ;
V_34 = F_100 ( sizeof( struct V_31 ) ) ;
if ( ! V_34 ) {
F_39 ( & V_41 -> V_48 ,
L_56 , V_49 ) ;
return - V_88 ;
}
V_34 -> V_182 = & V_183 ;
V_34 -> V_212 = ( 5 * V_213 ) ;
F_101 ( V_34 , & V_41 -> V_48 ) ;
V_34 -> V_214 = V_215 ;
V_210 = F_102 ( struct V_216 ,
V_217 . V_218 ) ;
V_209 = F_103 ( V_41 , V_210 , V_34 -> V_175 ,
V_215 ) ;
if ( V_209 < 0 ) {
F_39 ( & V_41 -> V_48 ,
L_57 ,
V_49 , V_209 ) ;
goto V_219;
}
V_32 = F_75 ( F_28 ( V_34 ) , V_41 ) ;
if ( ! V_32 ) {
F_39 ( & V_41 -> V_48 ,
L_58 , V_49 ) ;
V_209 = - V_88 ;
goto V_219;
}
F_86 ( V_32 -> V_54 , V_32 ) ;
V_32 -> V_34 = V_34 ;
F_104 ( & V_41 -> V_48 , V_32 ) ;
F_105 ( & V_32 -> V_220 ) ;
F_106 ( & V_32 -> V_46 ) ;
V_32 -> V_78 = 0 ;
F_16 ( & V_32 -> V_83 , 1 ) ;
V_210 = F_102 ( struct V_216 ,
V_217 . V_86 ) ;
V_209 = F_103 ( V_41 , V_210 ,
& V_32 -> V_86 , 4 ) ;
if ( V_209 ) {
F_39 ( & V_41 -> V_48 ,
L_59 ,
V_49 , V_209 ) ;
goto V_219;
}
V_32 -> V_87 = F_107 ( V_32 -> V_86 ,
sizeof( struct V_1 * ) , V_181 ) ;
if ( ! V_32 -> V_87 ) {
V_209 = - V_88 ;
goto V_221;
}
V_32 -> V_107 =
F_108 (unsigned long, 3 , ((devdata->num_rcv_bufs / 3) - 2)) ;
V_32 -> V_126 =
F_108 (unsigned long,
2 , (devdata->max_outstanding_net_xmits - 1)) ;
V_32 -> V_184 =
F_108 (unsigned long,
1 , (devdata->max_outstanding_net_xmits / 2)) ;
F_109 ( & V_32 -> V_85 ) ;
V_32 -> V_69 = F_59 ( V_105 , V_52 ) ;
if ( ! V_32 -> V_69 ) {
V_209 = - V_88 ;
goto V_222;
}
V_32 -> V_104 = F_59 ( V_105 , V_52 ) ;
if ( ! V_32 -> V_104 ) {
V_209 = - V_88 ;
goto V_223;
}
F_110 ( & V_32 -> V_93 , F_42 ) ;
V_32 -> V_42 = false ;
V_32 -> V_43 = false ;
V_210 = F_102 ( struct V_216 ,
V_217 . V_224 ) ;
V_209 = F_103 ( V_41 , V_210 , & V_34 -> V_224 , 4 ) ;
if ( V_209 ) {
F_39 ( & V_41 -> V_48 ,
L_60 ,
V_49 , V_209 ) ;
goto V_223;
}
F_111 ( V_34 , & V_32 -> V_84 , F_93 , 64 ) ;
F_112 ( & V_32 -> V_35 , F_95 ,
( unsigned long ) V_32 ) ;
F_98 ( & V_32 -> V_35 , F_31 ( 2 ) ) ;
V_210 = F_102 ( struct V_216 ,
V_225 . V_211 ) ;
V_209 = F_103 ( V_41 , V_210 , & V_211 , 8 ) ;
if ( V_209 ) {
F_39 ( & V_41 -> V_48 ,
L_61 ,
V_49 , V_209 ) ;
goto V_226;
}
V_211 |= V_227 ;
V_211 |= V_228 ;
V_209 = F_113 ( V_41 , V_210 , & V_211 , 8 ) ;
if ( V_209 ) {
F_39 ( & V_41 -> V_48 ,
L_62 ,
V_49 , V_209 ) ;
goto V_226;
}
V_209 = F_114 ( V_34 ) ;
if ( V_209 ) {
F_39 ( & V_41 -> V_48 ,
L_63 , V_49 , V_209 ) ;
goto V_226;
}
V_32 -> V_229 = F_115 ( V_34 -> V_174 ,
V_230 ) ;
if ( ! V_32 -> V_229 ) {
F_39 ( & V_41 -> V_48 ,
L_64 ,
V_49 , V_34 -> V_174 ) ;
V_209 = - V_88 ;
goto V_231;
}
F_116 ( & V_41 -> V_48 , L_65 ,
V_49 , V_34 -> V_174 ) ;
return 0 ;
V_231:
F_117 ( V_34 ) ;
V_226:
F_12 ( & V_32 -> V_35 ) ;
F_118 ( & V_32 -> V_84 ) ;
V_223:
F_60 ( V_32 -> V_104 ) ;
V_222:
F_60 ( V_32 -> V_69 ) ;
V_221:
F_60 ( V_32 -> V_87 ) ;
V_219:
F_119 ( V_34 ) ;
return V_209 ;
}
static void F_120 ( struct V_31 * V_32 )
{
unsigned long V_45 ;
F_18 ( & V_32 -> V_46 , V_45 ) ;
V_32 -> V_41 = NULL ;
F_19 ( & V_32 -> V_46 , V_45 ) ;
}
static void F_121 ( struct V_176 * V_41 )
{
struct V_31 * V_32 = F_122 ( & V_41 -> V_48 ) ;
struct V_33 * V_34 ;
unsigned long V_45 ;
if ( ! V_32 ) {
F_39 ( & V_41 -> V_48 , L_66 , V_49 ) ;
return;
}
F_18 ( & V_32 -> V_46 , V_45 ) ;
if ( V_32 -> V_47 ) {
F_19 ( & V_32 -> V_46 , V_45 ) ;
F_39 ( & V_41 -> V_48 , L_67 , V_49 ) ;
return;
}
V_32 -> V_47 = true ;
F_19 ( & V_32 -> V_46 , V_45 ) ;
V_34 = V_32 -> V_34 ;
if ( ! V_34 ) {
F_39 ( & V_41 -> V_48 , L_68 , V_49 ) ;
return;
}
F_123 ( V_133 ) ;
F_124 ( V_32 -> V_229 ) ;
F_117 ( V_34 ) ;
F_12 ( & V_32 -> V_35 ) ;
F_118 ( & V_32 -> V_84 ) ;
F_104 ( & V_41 -> V_48 , NULL ) ;
F_120 ( V_32 ) ;
F_77 ( V_32 ) ;
F_119 ( V_34 ) ;
}
static int F_125 ( struct V_176 * V_41 ,
T_5 V_44 )
{
struct V_31 * V_32 = F_122 ( & V_41 -> V_48 ) ;
F_17 ( V_32 , V_44 ) ;
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
F_39 ( & V_41 -> V_48 , L_66 , V_49 ) ;
return - V_15 ;
}
V_34 = V_32 -> V_34 ;
F_18 ( & V_32 -> V_46 , V_45 ) ;
if ( V_32 -> V_43 ) {
F_19 ( & V_32 -> V_46 , V_45 ) ;
F_39 ( & V_41 -> V_48 , L_69 ,
V_49 ) ;
return - V_15 ;
}
if ( ! V_32 -> V_42 ) {
F_19 ( & V_32 -> V_46 , V_45 ) ;
F_39 ( & V_41 -> V_48 , L_70 , V_49 ) ;
V_44 ( V_41 , 0 ) ;
return 0 ;
}
V_32 -> V_43 = true ;
F_19 ( & V_32 -> V_46 , V_45 ) ;
F_98 ( & V_32 -> V_35 , F_31 ( 2 ) ) ;
F_37 ( V_34 , V_32 ) ;
F_13 () ;
F_127 ( V_34 ) ;
F_15 () ;
V_44 ( V_41 , 0 ) ;
return 0 ;
}
static int F_128 ( void )
{
struct V_232 * V_233 ;
int V_209 = - V_88 ;
V_230 = F_115 ( L_71 , NULL ) ;
if ( ! V_230 )
return V_209 ;
V_233 = F_129 ( L_72 , V_234 , V_230 , NULL ,
& V_235 ) ;
if ( ! V_233 )
goto V_236;
V_233 = F_129 ( L_73 , V_237 , V_230 ,
NULL , & V_238 ) ;
if ( ! V_233 )
goto V_236;
V_133 =
F_130 ( L_74 ) ;
if ( ! V_133 )
goto V_239;
V_209 = F_131 ( & V_240 ) ;
if ( ! V_209 )
return 0 ;
V_239:
if ( V_133 ) {
F_123 ( V_133 ) ;
F_132 ( V_133 ) ;
}
V_236:
F_124 ( V_230 ) ;
return V_209 ;
}
static void F_133 ( void )
{
F_134 ( & V_240 ) ;
if ( V_133 ) {
F_123 ( V_133 ) ;
F_132 ( V_133 ) ;
}
F_124 ( V_230 ) ;
}
