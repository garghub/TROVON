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
static int F_10 ( struct V_1 * V_2 )
{
int V_15 = F_11 ( V_2 -> V_16 -> V_17 , V_18 ) ;
if ( V_2 -> V_19 || V_2 -> V_20 || V_2 -> V_21 )
V_15 += V_22 + 1 ;
return V_15 ;
}
int F_12 ( struct V_1 * V_2 )
{
T_1 V_23 = V_2 -> V_24 ;
T_1 V_25 = F_10 ( V_2 ) ;
return ( ( V_2 -> V_26 . V_27 -> V_28 - V_23 ) < V_25 ) ||
( ( V_2 -> V_26 . V_29 + V_30 - V_23 ) < V_25 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
if ( ! F_12 ( V_2 ) )
return 0 ;
V_2 -> V_26 . V_27 -> V_31 = V_2 -> V_24 +
F_10 ( V_2 ) ;
F_14 () ;
return F_12 ( V_2 ) ;
}
static bool F_15 ( int V_32 , unsigned long V_33 , int V_5 )
{
if ( V_32 == V_34 )
return true ;
if ( ( V_32 + V_33 > V_34 ) &&
( V_33 <= V_34 ) && V_32 && ! V_5 )
return true ;
return false ;
}
unsigned int F_16 ( struct V_1 * V_2 ,
unsigned long V_32 , unsigned long V_33 ,
struct V_35 * V_36 )
{
unsigned V_37 = 0 ;
V_32 &= ~ V_38 ;
while ( V_33 > 0 ) {
unsigned long V_39 ;
V_39 = V_18 - V_32 ;
if ( V_39 > V_33 )
V_39 = V_33 ;
if ( F_15 ( V_36 -> V_40 , V_39 , V_36 -> V_5 ) ) {
V_37 ++ ;
V_36 -> V_40 = 0 ;
}
if ( V_36 -> V_40 + V_39 > V_34 )
V_39 = V_34 - V_36 -> V_40 ;
V_36 -> V_40 += V_39 ;
V_32 += V_39 ;
V_33 -= V_39 ;
if ( V_32 == V_18 )
V_32 = 0 ;
V_36 -> V_5 = false ;
}
return V_37 ;
}
unsigned int F_17 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_35 V_36 ;
unsigned int V_37 ;
unsigned char * V_43 ;
unsigned V_11 ;
V_36 . V_5 = true ;
V_36 . V_40 = 0 ;
V_37 = 1 ;
if ( F_18 ( V_42 ) -> V_44 )
V_37 ++ ;
V_43 = V_42 -> V_43 ;
while ( V_43 < F_19 ( V_42 ) ) {
unsigned long V_32 = F_20 ( V_43 ) ;
unsigned long V_33 = V_18 - V_32 ;
if ( V_43 + V_33 > F_19 ( V_42 ) )
V_33 = F_19 ( V_42 ) - V_43 ;
V_37 += F_16 ( V_2 , V_32 , V_33 , & V_36 ) ;
V_43 += V_33 ;
}
for ( V_11 = 0 ; V_11 < F_18 ( V_42 ) -> V_45 ; V_11 ++ ) {
unsigned long V_33 = F_21 ( & F_18 ( V_42 ) -> V_46 [ V_11 ] ) ;
unsigned long V_32 = F_18 ( V_42 ) -> V_46 [ V_11 ] . V_9 ;
V_37 += F_16 ( V_2 , V_32 , V_33 , & V_36 ) ;
}
return V_37 ;
}
static struct V_47 * F_22 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
struct V_47 * V_50 ;
struct V_51 * V_52 ;
V_52 = F_23 ( & V_2 -> V_26 , V_2 -> V_26 . V_53 ++ ) ;
V_50 = V_49 -> V_50 + V_49 -> V_54 ++ ;
V_50 -> V_55 = V_56 ;
V_50 -> V_44 = 0 ;
V_50 -> V_33 = 0 ;
V_50 -> V_57 = V_52 -> V_57 ;
V_49 -> V_40 = 0 ;
V_49 -> V_58 = V_52 -> V_59 ;
return V_50 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_41 * V_42 ,
struct V_48 * V_49 ,
struct V_60 * V_60 , unsigned long V_33 ,
unsigned long V_32 , int * V_5 )
{
struct V_61 * V_62 ;
struct V_47 * V_50 ;
unsigned long V_39 ;
int V_55 ;
F_25 ( V_33 + V_32 > V_18 << F_26 ( V_60 ) ) ;
V_50 = V_49 -> V_50 + V_49 -> V_54 - 1 ;
V_60 += V_32 >> V_63 ;
V_32 &= ~ V_38 ;
while ( V_33 > 0 ) {
F_25 ( V_32 >= V_18 ) ;
F_25 ( V_49 -> V_40 > V_34 ) ;
V_39 = V_18 - V_32 ;
if ( V_39 > V_33 )
V_39 = V_33 ;
if ( F_15 ( V_49 -> V_40 , V_39 , * V_5 ) ) {
F_25 ( * V_5 ) ;
V_50 = F_22 ( V_2 , V_49 ) ;
}
if ( V_49 -> V_40 + V_39 > V_34 )
V_39 = V_34 - V_49 -> V_40 ;
V_62 = V_49 -> V_64 + V_49 -> V_65 ++ ;
V_62 -> V_66 = V_67 ;
V_62 -> V_68 = V_39 ;
V_62 -> V_69 . V_70 = V_71 ;
V_62 -> V_69 . V_72 . V_73 = F_27 ( F_28 ( V_60 ) ) ;
V_62 -> V_69 . V_32 = V_32 ;
V_62 -> V_74 . V_70 = V_2 -> V_70 ;
V_62 -> V_74 . V_32 = V_49 -> V_40 ;
V_62 -> V_74 . V_72 . V_75 = V_49 -> V_58 ;
V_49 -> V_40 += V_39 ;
V_50 -> V_33 += V_39 ;
V_32 += V_39 ;
V_33 -= V_39 ;
if ( V_32 == V_18 && V_33 ) {
F_25 ( ! F_29 ( V_60 ) ) ;
V_60 ++ ;
V_32 = 0 ;
}
if ( F_18 ( V_42 ) -> V_55 & V_76 )
V_55 = V_77 ;
else if ( F_18 ( V_42 ) -> V_55 & V_78 )
V_55 = V_79 ;
else
V_55 = V_56 ;
if ( * V_5 && ( ( 1 << V_55 ) & V_2 -> V_20 ) )
V_2 -> V_26 . V_53 ++ ;
* V_5 = 0 ;
}
}
static int F_30 ( struct V_41 * V_42 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = F_31 ( V_42 -> V_16 ) ;
int V_45 = F_18 ( V_42 ) -> V_45 ;
int V_11 ;
struct V_51 * V_52 ;
struct V_47 * V_50 ;
unsigned char * V_43 ;
int V_5 = 1 ;
int V_80 ;
int V_55 ;
int V_44 ;
V_80 = V_49 -> V_54 ;
if ( F_18 ( V_42 ) -> V_55 & V_76 ) {
V_55 = V_77 ;
V_44 = F_18 ( V_42 ) -> V_44 ;
} else if ( F_18 ( V_42 ) -> V_55 & V_78 ) {
V_55 = V_79 ;
V_44 = F_18 ( V_42 ) -> V_44 ;
} else {
V_55 = V_56 ;
V_44 = 0 ;
}
if ( ( 1 << V_55 ) & V_2 -> V_21 ) {
V_52 = F_23 ( & V_2 -> V_26 , V_2 -> V_26 . V_53 ++ ) ;
V_50 = V_49 -> V_50 + V_49 -> V_54 ++ ;
V_50 -> V_55 = V_55 ;
V_50 -> V_44 = V_44 ;
V_50 -> V_33 = 0 ;
V_50 -> V_57 = V_52 -> V_57 ;
}
V_52 = F_23 ( & V_2 -> V_26 , V_2 -> V_26 . V_53 ++ ) ;
V_50 = V_49 -> V_50 + V_49 -> V_54 ++ ;
if ( ( 1 << V_55 ) & V_2 -> V_20 ) {
V_50 -> V_55 = V_55 ;
V_50 -> V_44 = V_44 ;
} else {
V_50 -> V_55 = V_56 ;
V_50 -> V_44 = 0 ;
}
V_50 -> V_33 = 0 ;
V_50 -> V_57 = V_52 -> V_57 ;
V_49 -> V_40 = 0 ;
V_49 -> V_58 = V_52 -> V_59 ;
V_43 = V_42 -> V_43 ;
while ( V_43 < F_19 ( V_42 ) ) {
unsigned int V_32 = F_20 ( V_43 ) ;
unsigned int V_68 = V_18 - V_32 ;
if ( V_43 + V_68 > F_19 ( V_42 ) )
V_68 = F_19 ( V_42 ) - V_43 ;
F_24 ( V_2 , V_42 , V_49 ,
F_32 ( V_43 ) , V_68 , V_32 , & V_5 ) ;
V_43 += V_68 ;
}
for ( V_11 = 0 ; V_11 < V_45 ; V_11 ++ ) {
F_24 ( V_2 , V_42 , V_49 ,
F_33 ( & F_18 ( V_42 ) -> V_46 [ V_11 ] ) ,
F_21 ( & F_18 ( V_42 ) -> V_46 [ V_11 ] ) ,
F_18 ( V_42 ) -> V_46 [ V_11 ] . V_9 ,
& V_5 ) ;
}
return V_49 -> V_54 - V_80 ;
}
static int F_34 ( struct V_1 * V_2 , int V_81 ,
struct V_48 * V_49 )
{
struct V_61 * V_82 ;
int V_83 = V_84 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_81 ; V_11 ++ ) {
V_82 = V_49 -> V_64 + V_49 -> V_85 ++ ;
if ( V_82 -> V_83 != V_86 ) {
F_35 ( V_2 -> V_16 ,
L_1 ,
V_82 -> V_83 , V_2 -> V_70 ) ;
V_83 = V_87 ;
}
}
return V_83 ;
}
static void F_36 ( struct V_1 * V_2 , int V_83 ,
struct V_47 * V_50 ,
int V_81 )
{
int V_11 ;
unsigned long V_32 ;
if ( V_81 <= 1 )
return;
V_81 -- ;
for ( V_11 = 0 ; V_11 < V_81 ; V_11 ++ ) {
int V_66 ;
if ( V_11 == V_81 - 1 )
V_66 = 0 ;
else
V_66 = V_88 ;
V_32 = 0 ;
F_37 ( V_2 , V_50 [ V_11 ] . V_57 , V_83 , V_32 ,
V_50 [ V_11 ] . V_33 , V_66 ) ;
}
}
static void F_38 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_89 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
T_5 V_83 ;
T_2 V_66 ;
struct V_90 * V_91 ;
struct V_92 V_93 ;
struct V_41 * V_42 ;
F_41 ( V_94 ) ;
int V_95 ;
int V_45 ;
int V_37 ;
unsigned long V_32 ;
struct V_96 * V_97 ;
int V_98 = 0 ;
struct V_48 V_49 = {
. V_64 = V_2 -> V_99 ,
. V_50 = V_2 -> V_50 ,
} ;
F_42 ( & V_93 ) ;
V_37 = 0 ;
while ( ( V_42 = F_43 ( & V_2 -> V_100 ) ) != NULL ) {
V_2 = F_31 ( V_42 -> V_16 ) ;
V_45 = F_18 ( V_42 ) -> V_45 ;
V_97 = (struct V_96 * ) V_42 -> V_101 ;
V_97 -> V_102 = F_30 ( V_42 , & V_49 ) ;
V_37 += V_45 + 1 ;
F_44 ( & V_93 , V_42 ) ;
if ( V_37 + V_22 >= V_30 )
break;
}
F_25 ( V_49 . V_54 > F_45 ( V_2 -> V_50 ) ) ;
if ( ! V_49 . V_65 )
return;
F_25 ( V_49 . V_65 > V_103 ) ;
F_46 ( V_2 -> V_99 , V_49 . V_65 ) ;
while ( ( V_42 = F_47 ( & V_93 ) ) != NULL ) {
V_97 = (struct V_96 * ) V_42 -> V_101 ;
V_2 = F_31 ( V_42 -> V_16 ) ;
if ( ( 1 << V_2 -> V_50 [ V_49 . V_104 ] . V_55 ) &
V_2 -> V_21 ) {
V_91 = F_48 ( & V_2 -> V_26 ,
V_2 -> V_26 . V_29 ++ ) ;
V_91 -> V_66 = V_105 | V_88 ;
V_91 -> V_32 = V_2 -> V_50 [ V_49 . V_104 ] . V_44 ;
V_91 -> V_57 = V_2 -> V_50 [ V_49 . V_104 ] . V_57 ;
V_91 -> V_83 = V_97 -> V_102 ;
V_49 . V_104 ++ ;
V_97 -> V_102 -- ;
}
V_2 -> V_16 -> V_106 . V_107 += V_42 -> V_68 ;
V_2 -> V_16 -> V_106 . V_108 ++ ;
V_83 = F_34 ( V_2 , V_97 -> V_102 , & V_49 ) ;
if ( V_97 -> V_102 == 1 )
V_66 = 0 ;
else
V_66 = V_88 ;
if ( V_42 -> V_109 == V_110 )
V_66 |= V_111 | V_112 ;
else if ( V_42 -> V_109 == V_113 )
V_66 |= V_112 ;
V_32 = 0 ;
V_91 = F_37 ( V_2 , V_2 -> V_50 [ V_49 . V_104 ] . V_57 ,
V_83 , V_32 ,
V_2 -> V_50 [ V_49 . V_104 ] . V_33 ,
V_66 ) ;
if ( ( 1 << V_2 -> V_50 [ V_49 . V_104 ] . V_55 ) &
V_2 -> V_20 ) {
struct V_114 * V_115 =
(struct V_114 * )
F_48 ( & V_2 -> V_26 ,
V_2 -> V_26 . V_29 ++ ) ;
V_91 -> V_66 |= V_116 ;
V_115 -> V_72 . V_115 . type = V_2 -> V_50 [ V_49 . V_104 ] . V_55 ;
V_115 -> V_72 . V_115 . V_33 = V_2 -> V_50 [ V_49 . V_104 ] . V_44 ;
V_115 -> V_72 . V_115 . V_117 = 0 ;
V_115 -> V_72 . V_115 . V_118 = 0 ;
V_115 -> type = V_119 ;
V_115 -> V_66 = 0 ;
}
F_36 ( V_2 , V_83 ,
V_2 -> V_50 + V_49 . V_104 + 1 ,
V_97 -> V_102 ) ;
F_49 ( & V_2 -> V_26 , V_95 ) ;
if ( V_95 )
V_98 = 1 ;
F_50 ( V_2 ) ;
V_49 . V_104 += V_97 -> V_102 ;
F_51 ( V_42 ) ;
}
if ( V_98 )
F_52 ( V_2 -> V_120 ) ;
if ( ! F_53 ( & V_2 -> V_100 ) )
F_38 ( V_2 ) ;
}
void F_54 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
F_55 ( & V_2 -> V_100 , V_42 ) ;
F_38 ( V_2 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
int V_121 ;
F_57 ( & V_2 -> V_122 , V_121 ) ;
if ( V_121 )
F_58 ( & V_2 -> V_123 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
unsigned long V_124 , V_125 ;
V_124 = F_23 ( & V_2 -> V_122 , V_2 -> V_122 . V_53 ) -> V_33 ;
V_124 = F_60 ( V_124 , 131072UL ) ;
V_124 = V_15 ( V_124 , V_2 -> V_126 ) ;
V_125 = V_2 -> V_127 + V_2 -> V_126 ;
if ( V_125 < V_2 -> V_127 )
V_125 = V_128 ;
V_2 -> V_127 = F_60 ( V_125 , V_124 ) ;
}
static void F_61 ( unsigned long V_43 )
{
struct V_1 * V_2 = (struct V_1 * ) V_43 ;
F_59 ( V_2 ) ;
F_56 ( V_2 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_129 * V_130 , T_1 V_131 )
{
T_1 V_132 = V_2 -> V_122 . V_53 ;
do {
F_63 ( V_2 , V_130 , V_87 ) ;
if ( V_132 == V_131 )
break;
V_130 = F_23 ( & V_2 -> V_122 , V_132 ++ ) ;
} while ( 1 );
V_2 -> V_122 . V_53 = V_132 ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_65 ( V_2 -> V_16 , L_2 ) ;
F_66 ( V_2 ) ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_129 * V_133 ,
struct V_129 * V_130 ,
int V_134 )
{
T_1 V_132 = V_2 -> V_122 . V_53 ;
int V_135 = 0 ;
int V_136 = 0 ;
int V_137 ;
if ( ! ( V_133 -> V_66 & V_138 ) )
return 0 ;
do {
struct V_129 V_139 = { 0 } ;
if ( V_135 >= V_134 ) {
F_65 ( V_2 -> V_16 ,
L_3 ,
V_134 ) ;
F_64 ( V_2 ) ;
return - V_140 ;
}
if ( F_68 ( V_135 >= V_141 ) ) {
F_65 ( V_2 -> V_16 ,
L_4 ,
V_135 , V_141 ) ;
F_64 ( V_2 ) ;
return - V_142 ;
}
if ( ! V_136 && V_135 >= V_143 ) {
if ( F_69 () )
F_35 ( V_2 -> V_16 ,
L_5 ,
V_135 , V_143 ) ;
V_136 = - V_142 ;
}
if ( V_136 )
V_130 = & V_139 ;
memcpy ( V_130 , F_23 ( & V_2 -> V_122 , V_132 + V_135 ) ,
sizeof( * V_130 ) ) ;
if ( ! V_136 && V_130 -> V_33 > V_133 -> V_33 ) {
if ( F_69 () )
F_35 ( V_2 -> V_16 ,
L_6 ,
V_130 -> V_33 , V_133 -> V_33 ) ;
V_136 = - V_144 ;
}
V_133 -> V_33 -= V_130 -> V_33 ;
V_135 ++ ;
if ( F_68 ( ( V_130 -> V_32 + V_130 -> V_33 ) > V_18 ) ) {
F_65 ( V_2 -> V_16 , L_7 ,
V_130 -> V_32 , V_130 -> V_33 ) ;
F_64 ( V_2 ) ;
return - V_145 ;
}
V_137 = V_130 -> V_66 & V_138 ;
if ( ! V_136 )
V_130 ++ ;
} while ( V_137 );
if ( V_136 ) {
F_62 ( V_2 , V_133 , V_132 + V_135 ) ;
return V_136 ;
}
return V_135 ;
}
static struct V_60 * F_70 ( struct V_1 * V_2 ,
T_2 V_10 )
{
struct V_60 * V_60 ;
V_60 = F_71 ( V_146 | V_147 ) ;
if ( ! V_60 )
return NULL ;
V_2 -> V_7 [ V_10 ] = V_60 ;
return V_60 ;
}
static struct V_61 * F_72 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
struct V_129 * V_130 ,
struct V_61 * V_148 )
{
struct V_149 * V_150 = F_18 ( V_42 ) ;
T_3 * V_46 = V_150 -> V_46 ;
T_2 V_10 = * ( ( T_2 * ) V_42 -> V_43 ) ;
T_2 V_151 = 0 ;
int V_152 , V_153 ;
struct V_60 * V_60 ;
T_4 V_154 , V_155 = 0 ;
T_6 V_156 ;
unsigned int V_157 ;
struct V_4 * V_133 = NULL ;
V_157 = V_150 -> V_45 ;
V_153 = ( F_6 ( & V_150 -> V_46 [ 0 ] ) == V_10 ) ;
for ( V_150 -> V_45 = V_152 = V_153 ; V_152 < V_157 ;
V_150 -> V_45 ++ ) {
struct V_4 * V_4 =
V_2 -> V_4 ;
V_60 = F_71 ( V_146 | V_147 ) ;
if ( ! V_60 )
goto V_158;
V_156 = 0 ;
V_133 = NULL ;
while ( V_156 < V_18 && V_152 < V_157 ) {
V_148 -> V_66 = V_159 ;
V_148 -> V_69 . V_72 . V_75 = V_130 -> V_59 ;
V_148 -> V_69 . V_70 = V_2 -> V_70 ;
V_148 -> V_69 . V_32 = V_130 -> V_32 ;
V_148 -> V_74 . V_70 = V_71 ;
V_148 -> V_74 . V_32 = V_156 ;
V_148 -> V_74 . V_72 . V_73 = F_27 ( F_28 ( V_60 ) ) ;
if ( V_156 + V_130 -> V_33 > V_18 ) {
V_148 -> V_68 = V_18 - V_156 ;
V_130 -> V_32 += V_148 -> V_68 ;
V_130 -> V_33 -= V_148 -> V_68 ;
V_156 += V_148 -> V_68 ;
} else {
V_148 -> V_68 = V_130 -> V_33 ;
V_156 += V_148 -> V_68 ;
V_154 = F_8 ( V_2 -> V_14 ++ ) ;
V_10 = V_2 -> V_160 [ V_154 ] ;
memcpy ( & V_4 [ V_10 ] . V_52 , V_130 ,
sizeof( * V_130 ) ) ;
V_2 -> V_7 [ V_10 ] = ( void * ) ( ~ 0UL ) ;
V_4 [ V_10 ] . V_5 =
V_6 ;
if ( ! V_133 ) {
V_133 = & V_4 [ V_10 ] ;
V_155 = V_154 ;
V_151 = V_10 ;
}
V_130 ++ ;
V_152 ++ ;
}
V_148 ++ ;
}
V_133 -> V_52 . V_32 = 0 ;
V_133 -> V_52 . V_33 = V_156 ;
V_133 -> V_5 = V_155 ;
V_2 -> V_7 [ V_151 ] = V_60 ;
F_7 ( & V_46 [ V_150 -> V_45 ] , V_151 ) ;
}
F_25 ( V_150 -> V_45 > V_22 ) ;
return V_148 ;
V_158:
while ( V_150 -> V_45 -- > V_153 ) {
F_73 ( V_2 ,
F_6 ( & V_46 [ V_150 -> V_45 ] ) ,
V_87 ) ;
}
if ( V_153 )
F_73 ( V_2 , V_10 , V_87 ) ;
return NULL ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
struct V_61 * * V_161 )
{
struct V_61 * V_148 = * V_161 ;
T_2 V_10 = * ( ( T_2 * ) V_42 -> V_43 ) ;
struct V_149 * V_150 = F_18 ( V_42 ) ;
struct V_4 * V_162 ;
int V_45 = V_150 -> V_45 ;
int V_11 , V_158 , V_153 ;
T_2 V_23 ;
V_158 = V_148 -> V_83 ;
if ( F_68 ( V_158 ) )
F_73 ( V_2 , V_10 , V_87 ) ;
V_153 = ( F_6 ( & V_150 -> V_46 [ 0 ] ) == V_10 ) ;
for ( V_11 = V_153 ; V_11 < V_45 ; V_11 ++ ) {
int V_163 , V_164 ;
T_4 V_5 ;
V_10 = F_6 ( & V_150 -> V_46 [ V_11 ] ) ;
V_162 = & V_2 -> V_4 [ V_10 ] ;
V_5 = V_162 -> V_5 ;
do {
V_164 = ( ++ V_148 ) -> V_83 ;
if ( V_164 )
break;
V_23 = V_2 -> V_160 [ F_8 ( ++ V_5 ) ] ;
} while ( ! F_1 ( V_2 , V_23 ) );
if ( F_75 ( ! V_164 ) ) {
if ( F_68 ( V_158 ) )
F_73 ( V_2 , V_10 ,
V_84 ) ;
continue;
}
F_73 ( V_2 , V_10 , V_87 ) ;
if ( V_158 )
continue;
V_10 = * ( ( T_2 * ) V_42 -> V_43 ) ;
F_73 ( V_2 , V_10 , V_84 ) ;
for ( V_163 = V_153 ; V_163 < V_11 ; V_163 ++ ) {
V_10 = F_6 ( & V_150 -> V_46 [ V_163 ] ) ;
F_73 ( V_2 , V_10 ,
V_84 ) ;
}
V_158 = V_164 ;
}
* V_161 = V_148 + 1 ;
return V_158 ;
}
static void F_76 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_149 * V_150 = F_18 ( V_42 ) ;
int V_45 = V_150 -> V_45 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_45 ; V_11 ++ ) {
T_3 * V_8 = V_150 -> V_46 + V_11 ;
struct V_129 * V_130 ;
struct V_60 * V_60 ;
T_2 V_10 ;
V_10 = F_6 ( V_8 ) ;
V_130 = & V_2 -> V_4 [ V_10 ] . V_52 ;
V_60 = F_32 ( F_4 ( V_2 , V_10 ) ) ;
F_77 ( V_42 , V_11 , V_60 , V_130 -> V_32 , V_130 -> V_33 ) ;
V_42 -> V_68 += V_130 -> V_33 ;
V_42 -> V_165 += V_130 -> V_33 ;
V_42 -> V_166 += V_130 -> V_33 ;
F_78 ( V_2 -> V_7 [ V_10 ] ) ;
F_73 ( V_2 , V_10 , V_84 ) ;
}
}
static int F_79 ( struct V_1 * V_2 ,
struct V_114 * V_167 ,
int V_134 )
{
struct V_114 V_168 ;
T_1 V_132 = V_2 -> V_122 . V_53 ;
do {
if ( F_68 ( V_134 -- <= 0 ) ) {
F_65 ( V_2 -> V_16 , L_8 ) ;
F_64 ( V_2 ) ;
return - V_169 ;
}
memcpy ( & V_168 , F_23 ( & V_2 -> V_122 , V_132 ) ,
sizeof( V_168 ) ) ;
if ( F_68 ( ! V_168 . type ||
V_168 . type >= V_170 ) ) {
V_2 -> V_122 . V_53 = ++ V_132 ;
F_65 ( V_2 -> V_16 ,
L_9 , V_168 . type ) ;
F_64 ( V_2 ) ;
return - V_145 ;
}
memcpy ( & V_167 [ V_168 . type - 1 ] , & V_168 , sizeof( V_168 ) ) ;
V_2 -> V_122 . V_53 = ++ V_132 ;
} while ( V_168 . V_66 & V_171 );
return V_134 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
struct V_114 * V_115 )
{
if ( ! V_115 -> V_72 . V_115 . V_33 ) {
F_65 ( V_2 -> V_16 , L_10 ) ;
F_64 ( V_2 ) ;
return - V_145 ;
}
switch ( V_115 -> V_72 . V_115 . type ) {
case V_77 :
F_18 ( V_42 ) -> V_55 = V_76 ;
break;
case V_79 :
F_18 ( V_42 ) -> V_55 = V_78 ;
break;
default:
F_65 ( V_2 -> V_16 , L_11 , V_115 -> V_72 . V_115 . type ) ;
F_64 ( V_2 ) ;
return - V_145 ;
}
F_18 ( V_42 ) -> V_44 = V_115 -> V_72 . V_115 . V_33 ;
F_18 ( V_42 ) -> V_55 |= V_172 ;
F_18 ( V_42 ) -> V_173 = 0 ;
return 0 ;
}
static inline int F_81 ( struct V_41 * V_42 , unsigned int V_68 ,
unsigned int V_15 )
{
if ( F_82 ( V_42 ) >= V_68 )
return 0 ;
if ( V_15 > V_42 -> V_68 )
V_15 = V_42 -> V_68 ;
if ( F_83 ( V_42 , V_15 - F_82 ( V_42 ) ) == NULL )
return - V_174 ;
if ( F_82 ( V_42 ) < V_68 )
return - V_175 ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_41 * V_42 ,
int V_176 )
{
unsigned int V_177 ;
bool V_178 ;
int V_158 ;
V_178 = false ;
V_158 = F_81 ( V_42 ,
sizeof( struct V_179 ) ,
V_180 ) ;
if ( V_158 < 0 )
goto V_181;
if ( F_85 ( V_42 ) -> V_182 & F_86 ( V_183 | V_184 ) )
V_178 = true ;
V_177 = F_87 ( V_42 ) ;
V_158 = - V_175 ;
if ( V_178 )
goto V_181;
switch ( F_85 ( V_42 ) -> V_185 ) {
case V_186 :
V_158 = F_81 ( V_42 ,
V_177 + sizeof( struct V_187 ) ,
V_180 ) ;
if ( V_158 < 0 )
goto V_181;
if ( ! F_88 ( V_42 , V_177 ,
F_89 ( struct V_187 , V_188 ) ) ) {
V_158 = - V_175 ;
goto V_181;
}
if ( V_176 )
F_90 ( V_42 ) -> V_188 =
~ F_91 ( F_85 ( V_42 ) -> V_189 ,
F_85 ( V_42 ) -> V_190 ,
V_42 -> V_68 - V_177 ,
V_186 , 0 ) ;
break;
case V_191 :
V_158 = F_81 ( V_42 ,
V_177 + sizeof( struct V_192 ) ,
V_180 ) ;
if ( V_158 < 0 )
goto V_181;
if ( ! F_88 ( V_42 , V_177 ,
F_89 ( struct V_192 , V_188 ) ) ) {
V_158 = - V_175 ;
goto V_181;
}
if ( V_176 )
F_92 ( V_42 ) -> V_188 =
~ F_91 ( F_85 ( V_42 ) -> V_189 ,
F_85 ( V_42 ) -> V_190 ,
V_42 -> V_68 - V_177 ,
V_191 , 0 ) ;
break;
default:
goto V_181;
}
V_158 = 0 ;
V_181:
return V_158 ;
}
static int F_93 ( struct V_1 * V_2 , struct V_41 * V_42 ,
int V_176 )
{
int V_158 ;
T_7 V_193 ;
unsigned int V_177 ;
unsigned int V_68 ;
bool V_178 ;
bool V_194 ;
V_178 = false ;
V_194 = false ;
V_177 = sizeof( struct V_195 ) ;
V_158 = F_81 ( V_42 , V_177 , V_196 ) ;
if ( V_158 < 0 )
goto V_181;
V_193 = F_94 ( V_42 ) -> V_193 ;
V_68 = sizeof( struct V_195 ) + F_95 ( F_94 ( V_42 ) -> V_197 ) ;
while ( V_177 <= V_68 && ! V_194 ) {
switch ( V_193 ) {
case V_198 :
case V_199 :
case V_200 : {
struct V_201 * V_202 ;
V_158 = F_81 ( V_42 ,
V_177 +
sizeof( struct V_201 ) ,
V_196 ) ;
if ( V_158 < 0 )
goto V_181;
V_202 = F_96 ( struct V_201 , V_42 , V_177 ) ;
V_193 = V_202 -> V_193 ;
V_177 += F_97 ( V_202 ) ;
break;
}
case V_203 : {
struct V_204 * V_202 ;
V_158 = F_81 ( V_42 ,
V_177 +
sizeof( struct V_204 ) ,
V_196 ) ;
if ( V_158 < 0 )
goto V_181;
V_202 = F_96 ( struct V_204 , V_42 , V_177 ) ;
V_193 = V_202 -> V_193 ;
V_177 += F_98 ( V_202 ) ;
break;
}
case V_205 : {
struct V_206 * V_202 ;
V_158 = F_81 ( V_42 ,
V_177 +
sizeof( struct V_206 ) ,
V_196 ) ;
if ( V_158 < 0 )
goto V_181;
V_202 = F_96 ( struct V_206 , V_42 , V_177 ) ;
if ( V_202 -> V_182 & F_86 ( V_207 | V_208 ) )
V_178 = true ;
V_193 = V_202 -> V_193 ;
V_177 += sizeof( struct V_206 ) ;
break;
}
default:
V_194 = true ;
break;
}
}
V_158 = - V_175 ;
if ( ! V_194 || V_178 )
goto V_181;
switch ( V_193 ) {
case V_186 :
V_158 = F_81 ( V_42 ,
V_177 + sizeof( struct V_187 ) ,
V_196 ) ;
if ( V_158 < 0 )
goto V_181;
if ( ! F_88 ( V_42 , V_177 ,
F_89 ( struct V_187 , V_188 ) ) ) {
V_158 = - V_175 ;
goto V_181;
}
if ( V_176 )
F_90 ( V_42 ) -> V_188 =
~ F_99 ( & F_94 ( V_42 ) -> V_189 ,
& F_94 ( V_42 ) -> V_190 ,
V_42 -> V_68 - V_177 ,
V_186 , 0 ) ;
break;
case V_191 :
V_158 = F_81 ( V_42 ,
V_177 + sizeof( struct V_192 ) ,
V_196 ) ;
if ( V_158 < 0 )
goto V_181;
if ( ! F_88 ( V_42 , V_177 ,
F_89 ( struct V_192 , V_188 ) ) ) {
V_158 = - V_175 ;
goto V_181;
}
if ( V_176 )
F_92 ( V_42 ) -> V_188 =
~ F_99 ( & F_94 ( V_42 ) -> V_189 ,
& F_94 ( V_42 ) -> V_190 ,
V_42 -> V_68 - V_177 ,
V_191 , 0 ) ;
break;
default:
goto V_181;
}
V_158 = 0 ;
V_181:
return V_158 ;
}
static int F_100 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
int V_158 = - V_175 ;
int V_176 = 0 ;
if ( V_42 -> V_109 != V_110 && F_101 ( V_42 ) ) {
V_2 -> V_209 ++ ;
V_42 -> V_109 = V_110 ;
V_176 = 1 ;
}
if ( V_42 -> V_109 != V_110 )
return 0 ;
if ( V_42 -> V_185 == F_86 ( V_210 ) )
V_158 = F_84 ( V_2 , V_42 , V_176 ) ;
else if ( V_42 -> V_185 == F_86 ( V_211 ) )
V_158 = F_93 ( V_2 , V_42 , V_176 ) ;
return V_158 ;
}
static bool F_102 ( struct V_1 * V_2 , unsigned V_33 )
{
T_8 V_212 = F_103 () ;
T_8 V_213 = V_2 -> V_214 +
F_104 ( V_2 -> V_215 / 1000 ) ;
if ( F_105 ( & V_2 -> V_216 ) )
return true ;
if ( F_106 ( V_212 , V_213 ) ) {
V_2 -> V_214 = V_212 ;
F_59 ( V_2 ) ;
}
if ( V_33 > V_2 -> V_127 ) {
V_2 -> V_216 . V_43 =
( unsigned long ) V_2 ;
V_2 -> V_216 . V_217 =
F_61 ;
F_107 ( & V_2 -> V_216 ,
V_213 ) ;
V_2 -> V_214 = V_213 ;
return true ;
}
return false ;
}
static unsigned F_108 ( struct V_1 * V_2 , int V_218 )
{
struct V_61 * V_148 = V_2 -> V_219 , * V_220 ;
struct V_41 * V_42 ;
int V_95 ;
while ( ( F_9 ( V_2 ) + V_143
< V_12 ) &&
( F_109 ( & V_2 -> V_221 ) < V_218 ) ) {
struct V_129 V_222 ;
struct V_129 V_223 [ V_143 ] ;
struct V_60 * V_60 ;
struct V_114 V_167 [ V_170 - 1 ] ;
T_2 V_10 ;
T_1 V_3 ;
int V_134 ;
unsigned int V_165 ;
T_4 V_154 ;
if ( V_2 -> V_122 . V_27 -> V_28 - V_2 -> V_122 . V_53 >
V_224 ) {
F_65 ( V_2 -> V_16 ,
L_12
L_13 ,
V_2 -> V_122 . V_27 -> V_28 , V_2 -> V_122 . V_53 ,
V_224 ) ;
F_64 ( V_2 ) ;
continue;
}
V_134 = F_110 ( & V_2 -> V_122 ) ;
if ( ! V_134 )
break;
V_3 = V_2 -> V_122 . V_53 ;
F_111 () ;
memcpy ( & V_222 , F_23 ( & V_2 -> V_122 , V_3 ) , sizeof( V_222 ) ) ;
if ( V_222 . V_33 > V_2 -> V_127 &&
F_102 ( V_2 , V_222 . V_33 ) )
break;
V_2 -> V_127 -= V_222 . V_33 ;
V_134 -- ;
V_2 -> V_122 . V_53 = ++ V_3 ;
memset ( V_167 , 0 , sizeof( V_167 ) ) ;
if ( V_222 . V_66 & V_225 ) {
V_134 = F_79 ( V_2 , V_167 ,
V_134 ) ;
V_3 = V_2 -> V_122 . V_53 ;
if ( F_68 ( V_134 < 0 ) )
break;
}
V_95 = F_67 ( V_2 , & V_222 , V_223 , V_134 ) ;
if ( F_68 ( V_95 < 0 ) )
break;
V_3 += V_95 ;
if ( F_68 ( V_222 . V_33 < V_226 ) ) {
F_35 ( V_2 -> V_16 ,
L_14 , V_222 . V_33 ) ;
F_62 ( V_2 , & V_222 , V_3 ) ;
break;
}
if ( F_68 ( ( V_222 . V_32 + V_222 . V_33 ) > V_18 ) ) {
F_65 ( V_2 -> V_16 ,
L_15 ,
V_222 . V_32 , V_222 . V_33 ,
( V_222 . V_32 & ~ V_38 ) + V_222 . V_33 ) ;
F_64 ( V_2 ) ;
break;
}
V_154 = F_8 ( V_2 -> V_14 ) ;
V_10 = V_2 -> V_160 [ V_154 ] ;
V_165 = ( V_222 . V_33 > V_227 &&
V_95 < V_143 ) ?
V_227 : V_222 . V_33 ;
V_42 = F_112 ( V_165 + V_228 + V_229 ,
V_146 | V_230 ) ;
if ( F_68 ( V_42 == NULL ) ) {
F_35 ( V_2 -> V_16 ,
L_16 ) ;
F_62 ( V_2 , & V_222 , V_3 ) ;
break;
}
F_113 ( V_42 , V_228 + V_229 ) ;
if ( V_167 [ V_119 - 1 ] . type ) {
struct V_114 * V_115 ;
V_115 = & V_167 [ V_119 - 1 ] ;
if ( F_80 ( V_2 , V_42 , V_115 ) ) {
F_114 ( V_42 ) ;
break;
}
}
V_60 = F_70 ( V_2 , V_10 ) ;
if ( ! V_60 ) {
F_114 ( V_42 ) ;
F_62 ( V_2 , & V_222 , V_3 ) ;
break;
}
V_148 -> V_69 . V_72 . V_75 = V_222 . V_59 ;
V_148 -> V_69 . V_70 = V_2 -> V_70 ;
V_148 -> V_69 . V_32 = V_222 . V_32 ;
V_148 -> V_74 . V_72 . V_73 = F_27 ( F_28 ( V_60 ) ) ;
V_148 -> V_74 . V_70 = V_71 ;
V_148 -> V_74 . V_32 = V_222 . V_32 ;
V_148 -> V_68 = V_222 . V_33 ;
V_148 -> V_66 = V_159 ;
V_148 ++ ;
memcpy ( & V_2 -> V_4 [ V_10 ] . V_52 ,
& V_222 , sizeof( V_222 ) ) ;
V_2 -> V_4 [ V_10 ] . V_5 = V_154 ;
* ( ( T_2 * ) V_42 -> V_43 ) = V_10 ;
F_115 ( V_42 , V_165 ) ;
F_18 ( V_42 ) -> V_45 = V_95 ;
if ( V_165 < V_222 . V_33 ) {
F_18 ( V_42 ) -> V_45 ++ ;
F_7 ( & F_18 ( V_42 ) -> V_46 [ 0 ] ,
V_10 ) ;
} else {
F_7 ( & F_18 ( V_42 ) -> V_46 [ 0 ] ,
V_231 ) ;
}
V_2 -> V_14 ++ ;
V_220 = F_72 ( V_2 , V_42 , V_223 , V_148 ) ;
if ( V_220 == NULL ) {
F_114 ( V_42 ) ;
F_62 ( V_2 , & V_222 , V_3 ) ;
break;
}
V_148 = V_220 ;
F_44 ( & V_2 -> V_221 , V_42 ) ;
V_2 -> V_122 . V_53 = V_3 ;
if ( ( V_148 - V_2 -> V_219 ) >= F_45 ( V_2 -> V_219 ) )
break;
}
return V_148 - V_2 -> V_219 ;
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_61 * V_148 = V_2 -> V_219 ;
struct V_41 * V_42 ;
int V_232 = 0 ;
while ( ( V_42 = F_47 ( & V_2 -> V_221 ) ) != NULL ) {
struct V_129 * V_130 ;
T_2 V_10 ;
unsigned V_165 ;
V_10 = * ( ( T_2 * ) V_42 -> V_43 ) ;
V_130 = & V_2 -> V_4 [ V_10 ] . V_52 ;
if ( F_68 ( F_74 ( V_2 , V_42 , & V_148 ) ) ) {
F_35 ( V_2 -> V_16 , L_17 ) ;
F_18 ( V_42 ) -> V_45 = 0 ;
F_114 ( V_42 ) ;
continue;
}
V_165 = V_42 -> V_68 ;
memcpy ( V_42 -> V_43 ,
( void * ) ( F_4 ( V_2 , V_10 ) | V_130 -> V_32 ) ,
V_165 ) ;
if ( V_165 < V_130 -> V_33 ) {
V_130 -> V_32 += V_165 ;
V_130 -> V_33 -= V_165 ;
} else {
F_73 ( V_2 , V_10 ,
V_84 ) ;
}
if ( V_130 -> V_66 & V_233 )
V_42 -> V_109 = V_110 ;
else if ( V_130 -> V_66 & V_234 )
V_42 -> V_109 = V_113 ;
F_76 ( V_2 , V_42 ) ;
if ( F_117 ( V_42 ) && F_82 ( V_42 ) < V_227 ) {
int V_235 = F_118 ( int , V_42 -> V_68 , V_227 ) ;
F_83 ( V_42 , V_235 - F_82 ( V_42 ) ) ;
}
V_42 -> V_16 = V_2 -> V_16 ;
V_42 -> V_185 = F_119 ( V_42 , V_42 -> V_16 ) ;
F_120 ( V_42 ) ;
if ( F_100 ( V_2 , V_42 ) ) {
F_35 ( V_2 -> V_16 ,
L_18 ) ;
F_114 ( V_42 ) ;
continue;
}
F_121 ( V_42 , 0 ) ;
V_2 -> V_16 -> V_106 . V_236 += V_42 -> V_68 ;
V_2 -> V_16 -> V_106 . V_237 ++ ;
V_232 ++ ;
F_122 ( V_42 ) ;
}
return V_232 ;
}
int F_123 ( struct V_1 * V_2 , int V_218 )
{
unsigned V_238 ;
int V_232 ;
if ( F_68 ( ! F_124 ( V_2 ) ) )
return 0 ;
V_238 = F_108 ( V_2 , V_218 ) ;
if ( V_238 == 0 )
return 0 ;
F_46 ( V_2 -> V_219 , V_238 ) ;
V_232 = F_116 ( V_2 ) ;
return V_232 ;
}
static void F_73 ( struct V_1 * V_2 , T_2 V_10 ,
T_7 V_83 )
{
struct V_4 * V_4 ;
T_4 V_5 ;
T_2 V_23 ;
F_25 ( V_2 -> V_7 [ V_10 ] == ( void * ) ( ~ 0UL ) ) ;
if ( V_2 -> V_7 [ V_10 ] == NULL )
return;
V_4 = & V_2 -> V_4 [ V_10 ] ;
V_5 = V_4 -> V_5 ;
F_25 ( ! F_1 ( V_2 , V_5 ) ) ;
F_25 ( V_2 -> V_160 [ F_8 ( V_5 ) ] != V_10 ) ;
do {
T_4 V_154 ;
T_4 V_3 = F_8 ( V_5 ) ;
T_2 V_239 = V_2 -> V_160 [ V_3 ] ;
V_4 = & V_2 -> V_4 [ V_239 ] ;
F_63 ( V_2 , & V_4 -> V_52 , V_83 ) ;
V_4 -> V_5 = 0 ;
V_154 = F_8 ( V_2 -> V_13 ++ ) ;
V_2 -> V_160 [ V_154 ] = V_2 -> V_160 [ V_239 ] ;
V_23 = V_2 -> V_160 [ F_8 ( ++ V_5 ) ] ;
} while ( ! F_1 ( V_2 , V_23 ) );
F_125 ( V_2 -> V_7 [ V_10 ] ) ;
V_2 -> V_7 [ V_10 ] = NULL ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_129 * V_130 ,
T_5 V_240 )
{
T_1 V_11 = V_2 -> V_122 . V_29 ;
struct V_241 * V_91 ;
int V_94 ;
V_91 = F_48 ( & V_2 -> V_122 , V_11 ) ;
V_91 -> V_57 = V_130 -> V_57 ;
V_91 -> V_83 = V_240 ;
if ( V_130 -> V_66 & V_225 )
F_48 ( & V_2 -> V_122 , ++ V_11 ) -> V_83 = V_242 ;
V_2 -> V_122 . V_29 = ++ V_11 ;
F_49 ( & V_2 -> V_122 , V_94 ) ;
if ( V_94 )
F_52 ( V_2 -> V_243 ) ;
}
static struct V_90 * F_37 ( struct V_1 * V_2 ,
T_2 V_57 ,
T_5 V_240 ,
T_2 V_32 ,
T_2 V_33 ,
T_2 V_66 )
{
T_1 V_11 = V_2 -> V_26 . V_29 ;
struct V_90 * V_91 ;
V_91 = F_48 ( & V_2 -> V_26 , V_11 ) ;
V_91 -> V_32 = V_32 ;
V_91 -> V_66 = V_66 ;
V_91 -> V_57 = V_57 ;
V_91 -> V_83 = ( V_244 ) V_33 ;
if ( V_240 < 0 )
V_91 -> V_83 = ( V_244 ) V_240 ;
V_2 -> V_26 . V_29 = ++ V_11 ;
return V_91 ;
}
static inline int F_126 ( struct V_1 * V_2 )
{
return ! F_53 ( & V_2 -> V_100 ) ;
}
static inline int F_124 ( struct V_1 * V_2 )
{
if ( F_75 ( F_110 ( & V_2 -> V_122 ) ) &&
( F_9 ( V_2 ) + V_143
< V_12 ) )
return 1 ;
return 0 ;
}
void F_127 ( struct V_1 * V_2 )
{
if ( V_2 -> V_122 . V_27 )
F_128 ( F_129 ( V_2 ) ,
V_2 -> V_122 . V_27 ) ;
if ( V_2 -> V_26 . V_27 )
F_128 ( F_129 ( V_2 ) ,
V_2 -> V_26 . V_27 ) ;
}
int F_130 ( struct V_1 * V_2 ,
T_9 V_245 ,
T_9 V_246 )
{
void * V_247 ;
struct V_248 * V_249 ;
struct V_250 * V_251 ;
int V_158 = - V_174 ;
V_158 = F_131 ( F_129 ( V_2 ) ,
V_245 , & V_247 ) ;
if ( V_158 )
goto V_158;
V_249 = (struct V_248 * ) V_247 ;
F_132 ( & V_2 -> V_122 , V_249 , V_18 ) ;
V_158 = F_131 ( F_129 ( V_2 ) ,
V_246 , & V_247 ) ;
if ( V_158 )
goto V_158;
V_251 = (struct V_250 * ) V_247 ;
F_132 ( & V_2 -> V_26 , V_251 , V_18 ) ;
V_2 -> V_24 = 0 ;
return 0 ;
V_158:
F_127 ( V_2 ) ;
return V_158 ;
}
int F_133 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
while ( ! F_134 () ) {
F_135 ( V_2 -> V_89 ,
F_126 ( V_2 ) ||
F_134 () ) ;
if ( F_134 () )
break;
if ( F_126 ( V_2 ) )
F_40 ( V_2 ) ;
F_136 () ;
}
return 0 ;
}
static int T_10 F_137 ( void )
{
int V_252 = 0 ;
if ( ! F_138 () )
return - V_253 ;
if ( V_141 < V_143 ) {
F_139 ( L_19 ,
V_141 , V_143 ) ;
V_141 = V_143 ;
}
V_252 = F_140 () ;
if ( V_252 )
goto V_254;
return 0 ;
V_254:
return V_252 ;
}
static void T_11 F_141 ( void )
{
F_142 () ;
}
