static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return V_2 -> V_4 [ V_3 ] . V_5 != V_6 ;
}
static inline unsigned long F_2 ( struct V_1 * V_2 ,
T_2 V_3 )
{
return F_3 ( V_2 -> V_7 [ V_3 ] ) ;
}
static inline unsigned long F_4 ( struct V_1 * V_2 ,
T_2 V_3 )
{
return ( unsigned long ) F_5 ( F_2 ( V_2 , V_3 ) ) ;
}
static T_2 F_6 ( T_3 * V_8 )
{
return ( T_2 ) V_8 -> V_9 ;
}
static void F_7 ( T_3 * V_8 , T_2 V_10 )
{
V_8 -> V_9 = V_10 ;
}
static inline T_4 F_8 ( unsigned V_11 )
{
return V_11 & ( V_12 - 1 ) ;
}
static inline T_4 F_9 ( struct V_1 * V_2 )
{
return V_12 -
V_2 -> V_13 + V_2 -> V_14 ;
}
bool F_10 ( struct V_1 * V_2 , int V_15 )
{
T_1 V_16 , V_17 ;
do {
V_16 = V_2 -> V_18 . V_19 -> V_20 ;
V_17 = V_2 -> V_18 . V_21 ;
if ( V_16 - V_17 >= V_15 )
return true ;
V_2 -> V_18 . V_19 -> V_22 = V_16 + 1 ;
F_11 () ;
} while ( V_2 -> V_18 . V_19 -> V_20 != V_16 );
return false ;
}
static bool F_12 ( int V_23 , unsigned long V_24 , int V_5 )
{
if ( V_23 == V_25 )
return true ;
if ( ( V_23 + V_24 > V_25 ) &&
( V_24 <= V_25 ) && V_23 && ! V_5 )
return true ;
return false ;
}
static struct V_26 * F_13 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_26 * V_29 ;
struct V_30 * V_31 ;
V_31 = F_14 ( & V_2 -> V_18 , V_2 -> V_18 . V_21 ++ ) ;
V_29 = V_28 -> V_29 + V_28 -> V_32 ++ ;
V_29 -> V_33 = V_34 ;
V_29 -> V_35 = 0 ;
V_29 -> V_24 = 0 ;
V_29 -> V_36 = V_31 -> V_36 ;
V_28 -> V_37 = 0 ;
V_28 -> V_38 = V_31 -> V_39 ;
return V_29 ;
}
static void F_15 ( struct V_1 * V_2 , struct V_40 * V_41 ,
struct V_27 * V_28 ,
struct V_42 * V_42 , unsigned long V_24 ,
unsigned long V_23 , int * V_5 )
{
struct V_43 * V_44 ;
struct V_26 * V_29 ;
unsigned long V_45 ;
int V_33 = V_34 ;
F_16 ( V_24 + V_23 > V_46 << F_17 ( V_42 ) ) ;
V_29 = V_28 -> V_29 + V_28 -> V_32 - 1 ;
V_42 += V_23 >> V_47 ;
V_23 &= ~ V_48 ;
while ( V_24 > 0 ) {
F_16 ( V_23 >= V_46 ) ;
F_16 ( V_28 -> V_37 > V_25 ) ;
V_45 = V_46 - V_23 ;
if ( V_45 > V_24 )
V_45 = V_24 ;
if ( F_12 ( V_28 -> V_37 , V_45 , * V_5 ) ) {
F_16 ( * V_5 ) ;
V_29 = F_13 ( V_2 , V_28 ) ;
}
if ( V_28 -> V_37 + V_45 > V_25 )
V_45 = V_25 - V_28 -> V_37 ;
V_44 = V_28 -> V_49 + V_28 -> V_50 ++ ;
V_44 -> V_51 = V_52 ;
V_44 -> V_53 = V_45 ;
V_44 -> V_54 . V_55 = V_56 ;
V_44 -> V_54 . V_57 . V_58 = F_18 ( F_19 ( V_42 ) ) ;
V_44 -> V_54 . V_23 = V_23 ;
V_44 -> V_59 . V_55 = V_2 -> V_55 ;
V_44 -> V_59 . V_23 = V_28 -> V_37 ;
V_44 -> V_59 . V_57 . V_60 = V_28 -> V_38 ;
V_28 -> V_37 += V_45 ;
V_29 -> V_24 += V_45 ;
V_23 += V_45 ;
V_24 -= V_45 ;
if ( V_23 == V_46 && V_24 ) {
F_16 ( ! F_20 ( V_42 ) ) ;
V_42 ++ ;
V_23 = 0 ;
}
if ( F_21 ( V_41 ) ) {
if ( F_22 ( V_41 ) -> V_33 & V_61 )
V_33 = V_62 ;
else if ( F_22 ( V_41 ) -> V_33 & V_63 )
V_33 = V_64 ;
}
if ( * V_5 && ( ( 1 << V_33 ) & V_2 -> V_65 ) )
V_2 -> V_18 . V_21 ++ ;
* V_5 = 0 ;
}
}
static int F_23 ( struct V_40 * V_41 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = F_24 ( V_41 -> V_66 ) ;
int V_67 = F_22 ( V_41 ) -> V_67 ;
int V_11 ;
struct V_30 * V_31 ;
struct V_26 * V_29 ;
unsigned char * V_68 ;
int V_5 = 1 ;
int V_69 ;
int V_33 ;
V_69 = V_28 -> V_32 ;
V_33 = V_34 ;
if ( F_21 ( V_41 ) ) {
if ( F_22 ( V_41 ) -> V_33 & V_61 )
V_33 = V_62 ;
else if ( F_22 ( V_41 ) -> V_33 & V_63 )
V_33 = V_64 ;
}
if ( ( 1 << V_33 ) & V_2 -> V_70 ) {
V_31 = F_14 ( & V_2 -> V_18 , V_2 -> V_18 . V_21 ++ ) ;
V_29 = V_28 -> V_29 + V_28 -> V_32 ++ ;
V_29 -> V_33 = V_33 ;
V_29 -> V_35 = F_22 ( V_41 ) -> V_35 ;
V_29 -> V_24 = 0 ;
V_29 -> V_36 = V_31 -> V_36 ;
}
V_31 = F_14 ( & V_2 -> V_18 , V_2 -> V_18 . V_21 ++ ) ;
V_29 = V_28 -> V_29 + V_28 -> V_32 ++ ;
if ( ( 1 << V_33 ) & V_2 -> V_65 ) {
V_29 -> V_33 = V_33 ;
V_29 -> V_35 = F_22 ( V_41 ) -> V_35 ;
} else {
V_29 -> V_33 = V_34 ;
V_29 -> V_35 = 0 ;
}
V_29 -> V_24 = 0 ;
V_29 -> V_36 = V_31 -> V_36 ;
V_28 -> V_37 = 0 ;
V_28 -> V_38 = V_31 -> V_39 ;
V_68 = V_41 -> V_68 ;
while ( V_68 < F_25 ( V_41 ) ) {
unsigned int V_23 = F_26 ( V_68 ) ;
unsigned int V_53 = V_46 - V_23 ;
if ( V_68 + V_53 > F_25 ( V_41 ) )
V_53 = F_25 ( V_41 ) - V_68 ;
F_15 ( V_2 , V_41 , V_28 ,
F_27 ( V_68 ) , V_53 , V_23 , & V_5 ) ;
V_68 += V_53 ;
}
for ( V_11 = 0 ; V_11 < V_67 ; V_11 ++ ) {
F_15 ( V_2 , V_41 , V_28 ,
F_28 ( & F_22 ( V_41 ) -> V_71 [ V_11 ] ) ,
F_29 ( & F_22 ( V_41 ) -> V_71 [ V_11 ] ) ,
F_22 ( V_41 ) -> V_71 [ V_11 ] . V_9 ,
& V_5 ) ;
}
return V_28 -> V_32 - V_69 ;
}
static int F_30 ( struct V_1 * V_2 , int V_72 ,
struct V_27 * V_28 )
{
struct V_43 * V_73 ;
int V_74 = V_75 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_72 ; V_11 ++ ) {
V_73 = V_28 -> V_49 + V_28 -> V_76 ++ ;
if ( V_73 -> V_74 != V_77 ) {
F_31 ( V_2 -> V_66 ,
L_1 ,
V_73 -> V_74 , V_2 -> V_55 ) ;
V_74 = V_78 ;
}
}
return V_74 ;
}
static void F_32 ( struct V_1 * V_2 , int V_74 ,
struct V_26 * V_29 ,
int V_72 )
{
int V_11 ;
unsigned long V_23 ;
if ( V_72 <= 1 )
return;
V_72 -- ;
for ( V_11 = 0 ; V_11 < V_72 ; V_11 ++ ) {
int V_51 ;
if ( V_11 == V_72 - 1 )
V_51 = 0 ;
else
V_51 = V_79 ;
V_23 = 0 ;
F_33 ( V_2 , V_29 [ V_11 ] . V_36 , V_74 , V_23 ,
V_29 [ V_11 ] . V_24 , V_51 ) ;
}
}
void F_34 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_80 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
T_5 V_74 ;
T_2 V_51 ;
struct V_81 * V_82 ;
struct V_83 V_84 ;
struct V_40 * V_41 ;
F_37 ( V_85 ) ;
int V_86 ;
unsigned long V_23 ;
struct V_87 * V_88 ;
bool V_89 = false ;
struct V_27 V_28 = {
. V_49 = V_2 -> V_90 ,
. V_29 = V_2 -> V_29 ,
} ;
F_38 ( & V_84 ) ;
while ( ( V_41 = F_39 ( & V_2 -> V_91 ) ) != NULL ) {
T_1 V_92 ;
int V_11 ;
V_92 = F_40 ( F_26 ( V_41 -> V_68 ) +
F_41 ( V_41 ) ,
V_46 ) ;
for ( V_11 = 0 ; V_11 < F_22 ( V_41 ) -> V_67 ; V_11 ++ ) {
unsigned int V_24 ;
V_24 = F_29 ( & F_22 ( V_41 ) -> V_71 [ V_11 ] ) ;
V_92 += F_40 ( V_24 , V_46 ) ;
}
if ( F_21 ( V_41 ) &&
( F_22 ( V_41 ) -> V_33 & V_61 ||
F_22 ( V_41 ) -> V_33 & V_63 ) )
V_92 ++ ;
if ( ! F_10 ( V_2 , V_92 ) ) {
F_42 ( & V_2 -> V_91 , V_41 ) ;
V_89 = true ;
V_2 -> V_93 = V_92 ;
break;
} else
V_2 -> V_93 = 0 ;
V_88 = (struct V_87 * ) V_41 -> V_94 ;
V_88 -> V_95 = F_23 ( V_41 , & V_28 ) ;
F_16 ( V_88 -> V_95 > V_92 ) ;
F_43 ( & V_84 , V_41 ) ;
}
F_16 ( V_28 . V_32 > F_44 ( V_2 -> V_29 ) ) ;
if ( ! V_28 . V_50 )
goto V_96;
F_16 ( V_28 . V_50 > V_97 ) ;
F_45 ( V_2 -> V_90 , V_28 . V_50 ) ;
while ( ( V_41 = F_46 ( & V_84 ) ) != NULL ) {
V_88 = (struct V_87 * ) V_41 -> V_94 ;
if ( ( 1 << V_2 -> V_29 [ V_28 . V_98 ] . V_33 ) &
V_2 -> V_70 ) {
V_82 = F_47 ( & V_2 -> V_18 ,
V_2 -> V_18 . V_99 ++ ) ;
V_82 -> V_51 = V_100 | V_79 ;
V_82 -> V_23 = V_2 -> V_29 [ V_28 . V_98 ] . V_35 ;
V_82 -> V_36 = V_2 -> V_29 [ V_28 . V_98 ] . V_36 ;
V_82 -> V_74 = V_88 -> V_95 ;
V_28 . V_98 ++ ;
V_88 -> V_95 -- ;
}
V_2 -> V_66 -> V_101 . V_102 += V_41 -> V_53 ;
V_2 -> V_66 -> V_101 . V_103 ++ ;
V_74 = F_30 ( V_2 , V_88 -> V_95 , & V_28 ) ;
if ( V_88 -> V_95 == 1 )
V_51 = 0 ;
else
V_51 = V_79 ;
if ( V_41 -> V_104 == V_105 )
V_51 |= V_106 | V_107 ;
else if ( V_41 -> V_104 == V_108 )
V_51 |= V_107 ;
V_23 = 0 ;
V_82 = F_33 ( V_2 , V_2 -> V_29 [ V_28 . V_98 ] . V_36 ,
V_74 , V_23 ,
V_2 -> V_29 [ V_28 . V_98 ] . V_24 ,
V_51 ) ;
if ( ( 1 << V_2 -> V_29 [ V_28 . V_98 ] . V_33 ) &
V_2 -> V_65 ) {
struct V_109 * V_110 =
(struct V_109 * )
F_47 ( & V_2 -> V_18 ,
V_2 -> V_18 . V_99 ++ ) ;
V_82 -> V_51 |= V_111 ;
V_110 -> V_57 . V_110 . type = V_2 -> V_29 [ V_28 . V_98 ] . V_33 ;
V_110 -> V_57 . V_110 . V_24 = V_2 -> V_29 [ V_28 . V_98 ] . V_35 ;
V_110 -> V_57 . V_110 . V_112 = 0 ;
V_110 -> V_57 . V_110 . V_113 = 0 ;
V_110 -> type = V_114 ;
V_110 -> V_51 = 0 ;
}
F_32 ( V_2 , V_74 ,
V_2 -> V_29 + V_28 . V_98 + 1 ,
V_88 -> V_95 ) ;
F_48 ( & V_2 -> V_18 , V_86 ) ;
V_89 |= ! ! V_86 ;
V_28 . V_98 += V_88 -> V_95 ;
F_49 ( V_41 ) ;
}
V_96:
if ( V_89 )
F_50 ( V_2 -> V_115 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
int V_116 ;
F_52 ( & V_2 -> V_117 , V_116 ) ;
if ( V_116 )
F_53 ( & V_2 -> V_118 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
unsigned long V_119 , V_120 ;
V_119 = F_14 ( & V_2 -> V_117 , V_2 -> V_117 . V_21 ) -> V_24 ;
V_119 = F_55 ( V_119 , 131072UL ) ;
V_119 = F_56 ( V_119 , V_2 -> V_121 ) ;
V_120 = V_2 -> V_122 + V_2 -> V_121 ;
if ( V_120 < V_2 -> V_122 )
V_120 = V_123 ;
V_2 -> V_122 = F_55 ( V_120 , V_119 ) ;
}
static void F_57 ( unsigned long V_68 )
{
struct V_1 * V_2 = (struct V_1 * ) V_68 ;
F_54 ( V_2 ) ;
F_51 ( V_2 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_124 * V_125 , T_1 V_126 )
{
T_1 V_17 = V_2 -> V_117 . V_21 ;
do {
F_59 ( V_2 , V_125 , V_78 ) ;
if ( V_17 == V_126 )
break;
V_125 = F_14 ( & V_2 -> V_117 , V_17 ++ ) ;
} while ( 1 );
V_2 -> V_117 . V_21 = V_17 ;
}
static void F_60 ( struct V_1 * V_2 )
{
F_61 ( V_2 -> V_66 , L_2 ) ;
F_62 ( V_2 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_124 * V_127 ,
struct V_124 * V_125 ,
int V_128 )
{
T_1 V_17 = V_2 -> V_117 . V_21 ;
int V_129 = 0 ;
int V_130 = 0 ;
int V_131 ;
if ( ! ( V_127 -> V_51 & V_132 ) )
return 0 ;
do {
struct V_124 V_133 = { 0 } ;
if ( V_129 >= V_128 ) {
F_61 ( V_2 -> V_66 ,
L_3 ,
V_128 ) ;
F_60 ( V_2 ) ;
return - V_134 ;
}
if ( F_64 ( V_129 >= V_135 ) ) {
F_61 ( V_2 -> V_66 ,
L_4 ,
V_129 , V_135 ) ;
F_60 ( V_2 ) ;
return - V_136 ;
}
if ( ! V_130 && V_129 >= V_137 ) {
if ( F_65 () )
F_31 ( V_2 -> V_66 ,
L_5 ,
V_129 , V_137 ) ;
V_130 = - V_136 ;
}
if ( V_130 )
V_125 = & V_133 ;
memcpy ( V_125 , F_14 ( & V_2 -> V_117 , V_17 + V_129 ) ,
sizeof( * V_125 ) ) ;
if ( ! V_130 && V_125 -> V_24 > V_127 -> V_24 ) {
if ( F_65 () )
F_31 ( V_2 -> V_66 ,
L_6 ,
V_125 -> V_24 , V_127 -> V_24 ) ;
V_130 = - V_138 ;
}
V_127 -> V_24 -= V_125 -> V_24 ;
V_129 ++ ;
if ( F_64 ( ( V_125 -> V_23 + V_125 -> V_24 ) > V_46 ) ) {
F_61 ( V_2 -> V_66 , L_7 ,
V_125 -> V_23 , V_125 -> V_24 ) ;
F_60 ( V_2 ) ;
return - V_139 ;
}
V_131 = V_125 -> V_51 & V_132 ;
if ( ! V_130 )
V_125 ++ ;
} while ( V_131 );
if ( V_130 ) {
F_58 ( V_2 , V_127 , V_17 + V_129 ) ;
return V_130 ;
}
return V_129 ;
}
static struct V_42 * F_66 ( struct V_1 * V_2 ,
T_2 V_10 )
{
struct V_42 * V_42 ;
V_42 = F_67 ( V_140 | V_141 ) ;
if ( ! V_42 )
return NULL ;
V_2 -> V_7 [ V_10 ] = V_42 ;
return V_42 ;
}
static struct V_43 * F_68 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_124 * V_125 ,
struct V_43 * V_142 )
{
struct V_143 * V_144 = F_22 ( V_41 ) ;
T_3 * V_71 = V_144 -> V_71 ;
T_2 V_10 = * ( ( T_2 * ) V_41 -> V_68 ) ;
T_2 V_145 = 0 ;
int V_146 , V_147 ;
struct V_42 * V_42 ;
T_4 V_148 , V_149 = 0 ;
T_6 V_150 ;
unsigned int V_151 ;
struct V_4 * V_127 = NULL ;
V_151 = V_144 -> V_67 ;
V_147 = ( F_6 ( & V_144 -> V_71 [ 0 ] ) == V_10 ) ;
for ( V_144 -> V_67 = V_146 = V_147 ; V_146 < V_151 ;
V_144 -> V_67 ++ ) {
struct V_4 * V_4 =
V_2 -> V_4 ;
V_42 = F_67 ( V_140 | V_141 ) ;
if ( ! V_42 )
goto V_152;
V_150 = 0 ;
V_127 = NULL ;
while ( V_150 < V_46 && V_146 < V_151 ) {
V_142 -> V_51 = V_153 ;
V_142 -> V_54 . V_57 . V_60 = V_125 -> V_39 ;
V_142 -> V_54 . V_55 = V_2 -> V_55 ;
V_142 -> V_54 . V_23 = V_125 -> V_23 ;
V_142 -> V_59 . V_55 = V_56 ;
V_142 -> V_59 . V_23 = V_150 ;
V_142 -> V_59 . V_57 . V_58 = F_18 ( F_19 ( V_42 ) ) ;
if ( V_150 + V_125 -> V_24 > V_46 ) {
V_142 -> V_53 = V_46 - V_150 ;
V_125 -> V_23 += V_142 -> V_53 ;
V_125 -> V_24 -= V_142 -> V_53 ;
V_150 += V_142 -> V_53 ;
} else {
V_142 -> V_53 = V_125 -> V_24 ;
V_150 += V_142 -> V_53 ;
V_148 = F_8 ( V_2 -> V_14 ++ ) ;
V_10 = V_2 -> V_154 [ V_148 ] ;
memcpy ( & V_4 [ V_10 ] . V_31 , V_125 ,
sizeof( * V_125 ) ) ;
V_2 -> V_7 [ V_10 ] = ( void * ) ( ~ 0UL ) ;
V_4 [ V_10 ] . V_5 =
V_6 ;
if ( ! V_127 ) {
V_127 = & V_4 [ V_10 ] ;
V_149 = V_148 ;
V_145 = V_10 ;
}
V_125 ++ ;
V_146 ++ ;
}
V_142 ++ ;
}
V_127 -> V_31 . V_23 = 0 ;
V_127 -> V_31 . V_24 = V_150 ;
V_127 -> V_5 = V_149 ;
V_2 -> V_7 [ V_145 ] = V_42 ;
F_7 ( & V_71 [ V_144 -> V_67 ] , V_145 ) ;
}
F_16 ( V_144 -> V_67 > V_155 ) ;
return V_142 ;
V_152:
while ( V_144 -> V_67 -- > V_147 ) {
F_69 ( V_2 ,
F_6 ( & V_71 [ V_144 -> V_67 ] ) ,
V_78 ) ;
}
if ( V_147 )
F_69 ( V_2 , V_10 , V_78 ) ;
return NULL ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_43 * * V_156 )
{
struct V_43 * V_142 = * V_156 ;
T_2 V_10 = * ( ( T_2 * ) V_41 -> V_68 ) ;
struct V_143 * V_144 = F_22 ( V_41 ) ;
struct V_4 * V_157 ;
int V_67 = V_144 -> V_67 ;
int V_11 , V_152 , V_147 ;
T_2 V_158 ;
V_152 = V_142 -> V_74 ;
if ( F_64 ( V_152 ) )
F_69 ( V_2 , V_10 , V_78 ) ;
V_147 = ( F_6 ( & V_144 -> V_71 [ 0 ] ) == V_10 ) ;
for ( V_11 = V_147 ; V_11 < V_67 ; V_11 ++ ) {
int V_159 , V_160 ;
T_4 V_5 ;
V_10 = F_6 ( & V_144 -> V_71 [ V_11 ] ) ;
V_157 = & V_2 -> V_4 [ V_10 ] ;
V_5 = V_157 -> V_5 ;
do {
V_160 = ( ++ V_142 ) -> V_74 ;
if ( V_160 )
break;
V_158 = V_2 -> V_154 [ F_8 ( ++ V_5 ) ] ;
} while ( ! F_1 ( V_2 , V_158 ) );
if ( F_71 ( ! V_160 ) ) {
if ( F_64 ( V_152 ) )
F_69 ( V_2 , V_10 ,
V_75 ) ;
continue;
}
F_69 ( V_2 , V_10 , V_78 ) ;
if ( V_152 )
continue;
V_10 = * ( ( T_2 * ) V_41 -> V_68 ) ;
F_69 ( V_2 , V_10 , V_75 ) ;
for ( V_159 = V_147 ; V_159 < V_11 ; V_159 ++ ) {
V_10 = F_6 ( & V_144 -> V_71 [ V_159 ] ) ;
F_69 ( V_2 , V_10 ,
V_75 ) ;
}
V_152 = V_160 ;
}
* V_156 = V_142 + 1 ;
return V_152 ;
}
static void F_72 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_143 * V_144 = F_22 ( V_41 ) ;
int V_67 = V_144 -> V_67 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_67 ; V_11 ++ ) {
T_3 * V_8 = V_144 -> V_71 + V_11 ;
struct V_124 * V_125 ;
struct V_42 * V_42 ;
T_2 V_10 ;
V_10 = F_6 ( V_8 ) ;
V_125 = & V_2 -> V_4 [ V_10 ] . V_31 ;
V_42 = F_27 ( F_4 ( V_2 , V_10 ) ) ;
F_73 ( V_41 , V_11 , V_42 , V_125 -> V_23 , V_125 -> V_24 ) ;
V_41 -> V_53 += V_125 -> V_24 ;
V_41 -> V_161 += V_125 -> V_24 ;
V_41 -> V_162 += V_125 -> V_24 ;
F_74 ( V_2 -> V_7 [ V_10 ] ) ;
F_69 ( V_2 , V_10 , V_75 ) ;
}
}
static int F_75 ( struct V_1 * V_2 ,
struct V_109 * V_163 ,
int V_128 )
{
struct V_109 V_164 ;
T_1 V_17 = V_2 -> V_117 . V_21 ;
do {
if ( F_64 ( V_128 -- <= 0 ) ) {
F_61 ( V_2 -> V_66 , L_8 ) ;
F_60 ( V_2 ) ;
return - V_165 ;
}
memcpy ( & V_164 , F_14 ( & V_2 -> V_117 , V_17 ) ,
sizeof( V_164 ) ) ;
if ( F_64 ( ! V_164 . type ||
V_164 . type >= V_166 ) ) {
V_2 -> V_117 . V_21 = ++ V_17 ;
F_61 ( V_2 -> V_66 ,
L_9 , V_164 . type ) ;
F_60 ( V_2 ) ;
return - V_139 ;
}
memcpy ( & V_163 [ V_164 . type - 1 ] , & V_164 , sizeof( V_164 ) ) ;
V_2 -> V_117 . V_21 = ++ V_17 ;
} while ( V_164 . V_51 & V_167 );
return V_128 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_109 * V_110 )
{
if ( ! V_110 -> V_57 . V_110 . V_24 ) {
F_61 ( V_2 -> V_66 , L_10 ) ;
F_60 ( V_2 ) ;
return - V_139 ;
}
switch ( V_110 -> V_57 . V_110 . type ) {
case V_62 :
F_22 ( V_41 ) -> V_33 = V_61 ;
break;
case V_64 :
F_22 ( V_41 ) -> V_33 = V_63 ;
break;
default:
F_61 ( V_2 -> V_66 , L_11 , V_110 -> V_57 . V_110 . type ) ;
F_60 ( V_2 ) ;
return - V_139 ;
}
F_22 ( V_41 ) -> V_35 = V_110 -> V_57 . V_110 . V_24 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
bool V_168 = false ;
if ( V_41 -> V_104 != V_105 && F_21 ( V_41 ) ) {
V_2 -> V_169 ++ ;
V_41 -> V_104 = V_105 ;
V_168 = true ;
}
if ( V_41 -> V_104 != V_105 )
return 0 ;
return F_78 ( V_41 , V_168 ) ;
}
static bool F_79 ( struct V_1 * V_2 , unsigned V_24 )
{
T_7 V_170 = F_80 () ;
T_7 V_171 = V_2 -> V_172 +
F_81 ( V_2 -> V_173 / 1000 ) ;
if ( F_82 ( & V_2 -> V_174 ) )
return true ;
if ( F_83 ( V_170 , V_171 ) ) {
V_2 -> V_172 = V_170 ;
F_54 ( V_2 ) ;
}
if ( V_24 > V_2 -> V_122 ) {
V_2 -> V_174 . V_68 =
( unsigned long ) V_2 ;
V_2 -> V_174 . V_175 =
F_57 ;
F_84 ( & V_2 -> V_174 ,
V_171 ) ;
V_2 -> V_172 = V_171 ;
return true ;
}
return false ;
}
static unsigned F_85 ( struct V_1 * V_2 , int V_176 )
{
struct V_43 * V_142 = V_2 -> V_177 , * V_178 ;
struct V_40 * V_41 ;
int V_86 ;
while ( ( F_9 ( V_2 ) + V_137
< V_12 ) &&
( F_86 ( & V_2 -> V_179 ) < V_176 ) ) {
struct V_124 V_180 ;
struct V_124 V_181 [ V_137 ] ;
struct V_42 * V_42 ;
struct V_109 V_163 [ V_166 - 1 ] ;
T_2 V_10 ;
T_1 V_3 ;
int V_128 ;
unsigned int V_161 ;
T_4 V_148 ;
if ( V_2 -> V_117 . V_19 -> V_20 - V_2 -> V_117 . V_21 >
V_182 ) {
F_61 ( V_2 -> V_66 ,
L_12
L_13 ,
V_2 -> V_117 . V_19 -> V_20 , V_2 -> V_117 . V_21 ,
V_182 ) ;
F_60 ( V_2 ) ;
continue;
}
V_128 = F_87 ( & V_2 -> V_117 ) ;
if ( ! V_128 )
break;
V_3 = V_2 -> V_117 . V_21 ;
F_88 () ;
memcpy ( & V_180 , F_14 ( & V_2 -> V_117 , V_3 ) , sizeof( V_180 ) ) ;
if ( V_180 . V_24 > V_2 -> V_122 &&
F_79 ( V_2 , V_180 . V_24 ) )
break;
V_2 -> V_122 -= V_180 . V_24 ;
V_128 -- ;
V_2 -> V_117 . V_21 = ++ V_3 ;
memset ( V_163 , 0 , sizeof( V_163 ) ) ;
if ( V_180 . V_51 & V_183 ) {
V_128 = F_75 ( V_2 , V_163 ,
V_128 ) ;
V_3 = V_2 -> V_117 . V_21 ;
if ( F_64 ( V_128 < 0 ) )
break;
}
V_86 = F_63 ( V_2 , & V_180 , V_181 , V_128 ) ;
if ( F_64 ( V_86 < 0 ) )
break;
V_3 += V_86 ;
if ( F_64 ( V_180 . V_24 < V_184 ) ) {
F_31 ( V_2 -> V_66 ,
L_14 , V_180 . V_24 ) ;
F_58 ( V_2 , & V_180 , V_3 ) ;
break;
}
if ( F_64 ( ( V_180 . V_23 + V_180 . V_24 ) > V_46 ) ) {
F_61 ( V_2 -> V_66 ,
L_15 ,
V_180 . V_23 , V_180 . V_24 ,
( V_180 . V_23 & ~ V_48 ) + V_180 . V_24 ) ;
F_60 ( V_2 ) ;
break;
}
V_148 = F_8 ( V_2 -> V_14 ) ;
V_10 = V_2 -> V_154 [ V_148 ] ;
V_161 = ( V_180 . V_24 > V_185 &&
V_86 < V_137 ) ?
V_185 : V_180 . V_24 ;
V_41 = F_89 ( V_161 + V_186 + V_187 ,
V_140 | V_188 ) ;
if ( F_64 ( V_41 == NULL ) ) {
F_31 ( V_2 -> V_66 ,
L_16 ) ;
F_58 ( V_2 , & V_180 , V_3 ) ;
break;
}
F_90 ( V_41 , V_186 + V_187 ) ;
if ( V_163 [ V_114 - 1 ] . type ) {
struct V_109 * V_110 ;
V_110 = & V_163 [ V_114 - 1 ] ;
if ( F_76 ( V_2 , V_41 , V_110 ) ) {
F_91 ( V_41 ) ;
break;
}
}
V_42 = F_66 ( V_2 , V_10 ) ;
if ( ! V_42 ) {
F_91 ( V_41 ) ;
F_58 ( V_2 , & V_180 , V_3 ) ;
break;
}
V_142 -> V_54 . V_57 . V_60 = V_180 . V_39 ;
V_142 -> V_54 . V_55 = V_2 -> V_55 ;
V_142 -> V_54 . V_23 = V_180 . V_23 ;
V_142 -> V_59 . V_57 . V_58 = F_18 ( F_19 ( V_42 ) ) ;
V_142 -> V_59 . V_55 = V_56 ;
V_142 -> V_59 . V_23 = V_180 . V_23 ;
V_142 -> V_53 = V_180 . V_24 ;
V_142 -> V_51 = V_153 ;
V_142 ++ ;
memcpy ( & V_2 -> V_4 [ V_10 ] . V_31 ,
& V_180 , sizeof( V_180 ) ) ;
V_2 -> V_4 [ V_10 ] . V_5 = V_148 ;
* ( ( T_2 * ) V_41 -> V_68 ) = V_10 ;
F_92 ( V_41 , V_161 ) ;
F_22 ( V_41 ) -> V_67 = V_86 ;
if ( V_161 < V_180 . V_24 ) {
F_22 ( V_41 ) -> V_67 ++ ;
F_7 ( & F_22 ( V_41 ) -> V_71 [ 0 ] ,
V_10 ) ;
} else {
F_7 ( & F_22 ( V_41 ) -> V_71 [ 0 ] ,
V_189 ) ;
}
V_2 -> V_14 ++ ;
V_178 = F_68 ( V_2 , V_41 , V_181 , V_142 ) ;
if ( V_178 == NULL ) {
F_91 ( V_41 ) ;
F_58 ( V_2 , & V_180 , V_3 ) ;
break;
}
V_142 = V_178 ;
F_43 ( & V_2 -> V_179 , V_41 ) ;
V_2 -> V_117 . V_21 = V_3 ;
if ( ( V_142 - V_2 -> V_177 ) >= F_44 ( V_2 -> V_177 ) )
break;
}
return V_142 - V_2 -> V_177 ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_43 * V_142 = V_2 -> V_177 ;
struct V_40 * V_41 ;
int V_190 = 0 ;
while ( ( V_41 = F_46 ( & V_2 -> V_179 ) ) != NULL ) {
struct V_124 * V_125 ;
T_2 V_10 ;
unsigned V_161 ;
V_10 = * ( ( T_2 * ) V_41 -> V_68 ) ;
V_125 = & V_2 -> V_4 [ V_10 ] . V_31 ;
if ( F_64 ( F_70 ( V_2 , V_41 , & V_142 ) ) ) {
F_31 ( V_2 -> V_66 , L_17 ) ;
F_22 ( V_41 ) -> V_67 = 0 ;
F_91 ( V_41 ) ;
continue;
}
V_161 = V_41 -> V_53 ;
memcpy ( V_41 -> V_68 ,
( void * ) ( F_4 ( V_2 , V_10 ) | V_125 -> V_23 ) ,
V_161 ) ;
if ( V_161 < V_125 -> V_24 ) {
V_125 -> V_23 += V_161 ;
V_125 -> V_24 -= V_161 ;
} else {
F_69 ( V_2 , V_10 ,
V_75 ) ;
}
if ( V_125 -> V_51 & V_191 )
V_41 -> V_104 = V_105 ;
else if ( V_125 -> V_51 & V_192 )
V_41 -> V_104 = V_108 ;
F_72 ( V_2 , V_41 ) ;
if ( F_94 ( V_41 ) && F_41 ( V_41 ) < V_185 ) {
int V_193 = F_95 ( int , V_41 -> V_53 , V_185 ) ;
F_96 ( V_41 , V_193 - F_41 ( V_41 ) ) ;
}
V_41 -> V_66 = V_2 -> V_66 ;
V_41 -> V_194 = F_97 ( V_41 , V_41 -> V_66 ) ;
F_98 ( V_41 ) ;
if ( F_77 ( V_2 , V_41 ) ) {
F_31 ( V_2 -> V_66 ,
L_18 ) ;
F_91 ( V_41 ) ;
continue;
}
F_99 ( V_41 , 0 ) ;
if ( F_21 ( V_41 ) ) {
int V_195 = F_22 ( V_41 ) -> V_35 ;
int V_196 = F_100 ( V_41 ) -
F_101 ( V_41 ) +
F_102 ( V_41 ) ;
F_22 ( V_41 ) -> V_197 =
F_40 ( V_41 -> V_53 - V_196 , V_195 ) ;
}
V_2 -> V_66 -> V_101 . V_198 += V_41 -> V_53 ;
V_2 -> V_66 -> V_101 . V_199 ++ ;
V_190 ++ ;
F_103 ( V_41 ) ;
}
return V_190 ;
}
int F_104 ( struct V_1 * V_2 , int V_176 )
{
unsigned V_200 ;
int V_190 ;
if ( F_64 ( ! F_105 ( V_2 ) ) )
return 0 ;
V_200 = F_85 ( V_2 , V_176 ) ;
if ( V_200 == 0 )
return 0 ;
F_45 ( V_2 -> V_177 , V_200 ) ;
V_190 = F_93 ( V_2 ) ;
return V_190 ;
}
static void F_69 ( struct V_1 * V_2 , T_2 V_10 ,
T_8 V_74 )
{
struct V_4 * V_4 ;
T_4 V_5 ;
T_2 V_158 ;
F_16 ( V_2 -> V_7 [ V_10 ] == ( void * ) ( ~ 0UL ) ) ;
if ( V_2 -> V_7 [ V_10 ] == NULL )
return;
V_4 = & V_2 -> V_4 [ V_10 ] ;
V_5 = V_4 -> V_5 ;
F_16 ( ! F_1 ( V_2 , V_5 ) ) ;
F_16 ( V_2 -> V_154 [ F_8 ( V_5 ) ] != V_10 ) ;
do {
T_4 V_148 ;
T_4 V_3 = F_8 ( V_5 ) ;
T_2 V_201 = V_2 -> V_154 [ V_3 ] ;
V_4 = & V_2 -> V_4 [ V_201 ] ;
F_59 ( V_2 , & V_4 -> V_31 , V_74 ) ;
V_4 -> V_5 = 0 ;
V_148 = F_8 ( V_2 -> V_13 ++ ) ;
V_2 -> V_154 [ V_148 ] = V_2 -> V_154 [ V_201 ] ;
V_158 = V_2 -> V_154 [ F_8 ( ++ V_5 ) ] ;
} while ( ! F_1 ( V_2 , V_158 ) );
F_106 ( V_2 -> V_7 [ V_10 ] ) ;
V_2 -> V_7 [ V_10 ] = NULL ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_124 * V_125 ,
T_5 V_202 )
{
T_1 V_11 = V_2 -> V_117 . V_99 ;
struct V_203 * V_82 ;
int V_85 ;
V_82 = F_47 ( & V_2 -> V_117 , V_11 ) ;
V_82 -> V_36 = V_125 -> V_36 ;
V_82 -> V_74 = V_202 ;
if ( V_125 -> V_51 & V_183 )
F_47 ( & V_2 -> V_117 , ++ V_11 ) -> V_74 = V_204 ;
V_2 -> V_117 . V_99 = ++ V_11 ;
F_48 ( & V_2 -> V_117 , V_85 ) ;
if ( V_85 )
F_50 ( V_2 -> V_205 ) ;
}
static struct V_81 * F_33 ( struct V_1 * V_2 ,
T_2 V_36 ,
T_5 V_202 ,
T_2 V_23 ,
T_2 V_24 ,
T_2 V_51 )
{
T_1 V_11 = V_2 -> V_18 . V_99 ;
struct V_81 * V_82 ;
V_82 = F_47 ( & V_2 -> V_18 , V_11 ) ;
V_82 -> V_23 = V_23 ;
V_82 -> V_51 = V_51 ;
V_82 -> V_36 = V_36 ;
V_82 -> V_74 = ( V_206 ) V_24 ;
if ( V_202 < 0 )
V_82 -> V_74 = ( V_206 ) V_202 ;
V_2 -> V_18 . V_99 = ++ V_11 ;
return V_82 ;
}
static inline int F_107 ( struct V_1 * V_2 )
{
return ! F_108 ( & V_2 -> V_91 ) &&
F_10 ( V_2 , V_2 -> V_93 ) ;
}
static inline int F_105 ( struct V_1 * V_2 )
{
if ( F_71 ( F_87 ( & V_2 -> V_117 ) ) &&
( F_9 ( V_2 ) + V_137
< V_12 ) )
return 1 ;
return 0 ;
}
void F_109 ( struct V_1 * V_2 )
{
if ( V_2 -> V_117 . V_19 )
F_110 ( F_111 ( V_2 ) ,
V_2 -> V_117 . V_19 ) ;
if ( V_2 -> V_18 . V_19 )
F_110 ( F_111 ( V_2 ) ,
V_2 -> V_18 . V_19 ) ;
}
int F_112 ( struct V_1 * V_2 ,
T_9 V_207 ,
T_9 V_208 )
{
void * V_209 ;
struct V_210 * V_211 ;
struct V_212 * V_213 ;
int V_152 = - V_214 ;
V_152 = F_113 ( F_111 ( V_2 ) ,
V_207 , & V_209 ) ;
if ( V_152 )
goto V_152;
V_211 = (struct V_210 * ) V_209 ;
F_114 ( & V_2 -> V_117 , V_211 , V_46 ) ;
V_152 = F_113 ( F_111 ( V_2 ) ,
V_208 , & V_209 ) ;
if ( V_152 )
goto V_152;
V_213 = (struct V_212 * ) V_209 ;
F_114 ( & V_2 -> V_18 , V_213 , V_46 ) ;
return 0 ;
V_152:
F_109 ( V_2 ) ;
return V_152 ;
}
void F_115 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_215 )
return;
F_116 ( V_2 -> V_66 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
if ( F_118 ( V_2 ) )
F_119 ( V_2 -> V_66 ) ;
}
int F_120 ( void * V_68 )
{
struct V_1 * V_2 = V_68 ;
struct V_40 * V_41 ;
while ( ! F_121 () ) {
F_122 ( V_2 -> V_80 ,
F_107 ( V_2 ) ||
F_121 () ) ;
if ( F_121 () )
break;
if ( ! F_108 ( & V_2 -> V_91 ) )
F_36 ( V_2 ) ;
if ( F_108 ( & V_2 -> V_91 ) &&
F_123 ( V_2 -> V_66 ) )
F_117 ( V_2 ) ;
F_124 () ;
}
while ( ( V_41 = F_39 ( & V_2 -> V_91 ) ) != NULL )
F_49 ( V_41 ) ;
return 0 ;
}
static int T_10 F_125 ( void )
{
int V_216 = 0 ;
if ( ! F_126 () )
return - V_217 ;
if ( V_135 < V_137 ) {
F_127 ( L_19 ,
V_135 , V_137 ) ;
V_135 = V_137 ;
}
V_216 = F_128 () ;
if ( V_216 )
goto V_218;
return 0 ;
V_218:
return V_216 ;
}
static void T_11 F_129 ( void )
{
F_130 () ;
}
