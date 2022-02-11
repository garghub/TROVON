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
V_50 -> V_44 = 0 ;
V_50 -> V_33 = 0 ;
V_50 -> V_55 = V_52 -> V_55 ;
V_49 -> V_40 = 0 ;
V_49 -> V_56 = V_52 -> V_57 ;
return V_50 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_41 * V_42 ,
struct V_48 * V_49 ,
struct V_58 * V_58 , unsigned long V_33 ,
unsigned long V_32 , int * V_5 )
{
struct V_59 * V_60 ;
struct V_47 * V_50 ;
unsigned long V_39 ;
F_25 ( V_33 + V_32 > V_18 << F_26 ( V_58 ) ) ;
V_50 = V_49 -> V_50 + V_49 -> V_54 - 1 ;
V_58 += V_32 >> V_61 ;
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
V_60 = V_49 -> V_62 + V_49 -> V_63 ++ ;
V_60 -> V_64 = V_65 ;
V_60 -> V_66 = V_39 ;
V_60 -> V_67 . V_68 = V_69 ;
V_60 -> V_67 . V_70 . V_71 = F_27 ( F_28 ( V_58 ) ) ;
V_60 -> V_67 . V_32 = V_32 ;
V_60 -> V_72 . V_68 = V_2 -> V_68 ;
V_60 -> V_72 . V_32 = V_49 -> V_40 ;
V_60 -> V_72 . V_70 . V_73 = V_49 -> V_56 ;
V_49 -> V_40 += V_39 ;
V_50 -> V_33 += V_39 ;
V_32 += V_39 ;
V_33 -= V_39 ;
if ( V_32 == V_18 && V_33 ) {
F_25 ( ! F_29 ( V_58 ) ) ;
V_58 ++ ;
V_32 = 0 ;
}
if ( * V_5 && F_18 ( V_42 ) -> V_44 && ! V_2 -> V_21 )
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
int V_74 ;
V_74 = V_49 -> V_54 ;
if ( F_18 ( V_42 ) -> V_44 && V_2 -> V_21 ) {
V_52 = F_23 ( & V_2 -> V_26 , V_2 -> V_26 . V_53 ++ ) ;
V_50 = V_49 -> V_50 + V_49 -> V_54 ++ ;
V_50 -> V_44 = F_18 ( V_42 ) -> V_44 ;
V_50 -> V_33 = 0 ;
V_50 -> V_55 = V_52 -> V_55 ;
}
V_52 = F_23 ( & V_2 -> V_26 , V_2 -> V_26 . V_53 ++ ) ;
V_50 = V_49 -> V_50 + V_49 -> V_54 ++ ;
if ( ! V_2 -> V_21 )
V_50 -> V_44 = F_18 ( V_42 ) -> V_44 ;
else
V_50 -> V_44 = 0 ;
V_50 -> V_33 = 0 ;
V_50 -> V_55 = V_52 -> V_55 ;
V_49 -> V_40 = 0 ;
V_49 -> V_56 = V_52 -> V_57 ;
V_43 = V_42 -> V_43 ;
while ( V_43 < F_19 ( V_42 ) ) {
unsigned int V_32 = F_20 ( V_43 ) ;
unsigned int V_66 = V_18 - V_32 ;
if ( V_43 + V_66 > F_19 ( V_42 ) )
V_66 = F_19 ( V_42 ) - V_43 ;
F_24 ( V_2 , V_42 , V_49 ,
F_32 ( V_43 ) , V_66 , V_32 , & V_5 ) ;
V_43 += V_66 ;
}
for ( V_11 = 0 ; V_11 < V_45 ; V_11 ++ ) {
F_24 ( V_2 , V_42 , V_49 ,
F_33 ( & F_18 ( V_42 ) -> V_46 [ V_11 ] ) ,
F_21 ( & F_18 ( V_42 ) -> V_46 [ V_11 ] ) ,
F_18 ( V_42 ) -> V_46 [ V_11 ] . V_9 ,
& V_5 ) ;
}
return V_49 -> V_54 - V_74 ;
}
static int F_34 ( struct V_1 * V_2 , int V_75 ,
struct V_48 * V_49 )
{
struct V_59 * V_76 ;
int V_77 = V_78 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_75 ; V_11 ++ ) {
V_76 = V_49 -> V_62 + V_49 -> V_79 ++ ;
if ( V_76 -> V_77 != V_80 ) {
F_35 ( V_2 -> V_16 ,
L_1 ,
V_76 -> V_77 , V_2 -> V_68 ) ;
V_77 = V_81 ;
}
}
return V_77 ;
}
static void F_36 ( struct V_1 * V_2 , int V_77 ,
struct V_47 * V_50 ,
int V_75 )
{
int V_11 ;
unsigned long V_32 ;
if ( V_75 <= 1 )
return;
V_75 -- ;
for ( V_11 = 0 ; V_11 < V_75 ; V_11 ++ ) {
int V_64 ;
if ( V_11 == V_75 - 1 )
V_64 = 0 ;
else
V_64 = V_82 ;
V_32 = 0 ;
F_37 ( V_2 , V_50 [ V_11 ] . V_55 , V_77 , V_32 ,
V_50 [ V_11 ] . V_33 , V_64 ) ;
}
}
static void F_38 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_83 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
T_5 V_77 ;
T_2 V_64 ;
struct V_84 * V_85 ;
struct V_86 V_87 ;
struct V_41 * V_42 ;
F_41 ( V_88 ) ;
int V_89 ;
int V_45 ;
int V_37 ;
unsigned long V_32 ;
struct V_90 * V_91 ;
int V_92 = 0 ;
struct V_48 V_49 = {
. V_62 = V_2 -> V_93 ,
. V_50 = V_2 -> V_50 ,
} ;
F_42 ( & V_87 ) ;
V_37 = 0 ;
while ( ( V_42 = F_43 ( & V_2 -> V_94 ) ) != NULL ) {
V_2 = F_31 ( V_42 -> V_16 ) ;
V_45 = F_18 ( V_42 ) -> V_45 ;
V_91 = (struct V_90 * ) V_42 -> V_95 ;
V_91 -> V_96 = F_30 ( V_42 , & V_49 ) ;
V_37 += V_45 + 1 ;
F_44 ( & V_87 , V_42 ) ;
if ( V_37 + V_22 >= V_30 )
break;
}
F_25 ( V_49 . V_54 > F_45 ( V_2 -> V_50 ) ) ;
if ( ! V_49 . V_63 )
return;
F_25 ( V_49 . V_63 > F_45 ( V_2 -> V_93 ) ) ;
F_46 ( V_2 -> V_93 , V_49 . V_63 ) ;
while ( ( V_42 = F_47 ( & V_87 ) ) != NULL ) {
V_91 = (struct V_90 * ) V_42 -> V_95 ;
V_2 = F_31 ( V_42 -> V_16 ) ;
if ( V_2 -> V_50 [ V_49 . V_97 ] . V_44 && V_2 -> V_21 ) {
V_85 = F_48 ( & V_2 -> V_26 ,
V_2 -> V_26 . V_29 ++ ) ;
V_85 -> V_64 = V_98 | V_82 ;
V_85 -> V_32 = V_2 -> V_50 [ V_49 . V_97 ] . V_44 ;
V_85 -> V_55 = V_2 -> V_50 [ V_49 . V_97 ] . V_55 ;
V_85 -> V_77 = V_91 -> V_96 ;
V_49 . V_97 ++ ;
V_91 -> V_96 -- ;
}
V_2 -> V_16 -> V_99 . V_100 += V_42 -> V_66 ;
V_2 -> V_16 -> V_99 . V_101 ++ ;
V_77 = F_34 ( V_2 , V_91 -> V_96 , & V_49 ) ;
if ( V_91 -> V_96 == 1 )
V_64 = 0 ;
else
V_64 = V_82 ;
if ( V_42 -> V_102 == V_103 )
V_64 |= V_104 | V_105 ;
else if ( V_42 -> V_102 == V_106 )
V_64 |= V_105 ;
V_32 = 0 ;
V_85 = F_37 ( V_2 , V_2 -> V_50 [ V_49 . V_97 ] . V_55 ,
V_77 , V_32 ,
V_2 -> V_50 [ V_49 . V_97 ] . V_33 ,
V_64 ) ;
if ( V_2 -> V_50 [ V_49 . V_97 ] . V_44 && ! V_2 -> V_21 ) {
struct V_107 * V_20 =
(struct V_107 * )
F_48 ( & V_2 -> V_26 ,
V_2 -> V_26 . V_29 ++ ) ;
V_85 -> V_64 |= V_108 ;
V_20 -> V_70 . V_20 . V_33 = V_2 -> V_50 [ V_49 . V_97 ] . V_44 ;
V_20 -> V_70 . V_20 . type = V_109 ;
V_20 -> V_70 . V_20 . V_110 = 0 ;
V_20 -> V_70 . V_20 . V_111 = 0 ;
V_20 -> type = V_112 ;
V_20 -> V_64 = 0 ;
}
F_36 ( V_2 , V_77 ,
V_2 -> V_50 + V_49 . V_97 + 1 ,
V_91 -> V_96 ) ;
F_49 ( & V_2 -> V_26 , V_89 ) ;
if ( V_89 )
V_92 = 1 ;
F_50 ( V_2 ) ;
V_49 . V_97 += V_91 -> V_96 ;
F_51 ( V_42 ) ;
}
if ( V_92 )
F_52 ( V_2 -> V_113 ) ;
if ( ! F_53 ( & V_2 -> V_94 ) )
F_38 ( V_2 ) ;
}
void F_54 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
F_55 ( & V_2 -> V_94 , V_42 ) ;
F_38 ( V_2 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
int V_114 ;
F_57 ( & V_2 -> V_115 , V_114 ) ;
if ( V_114 )
F_58 ( & V_2 -> V_116 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
unsigned long V_117 , V_118 ;
V_117 = F_23 ( & V_2 -> V_115 , V_2 -> V_115 . V_53 ) -> V_33 ;
V_117 = F_60 ( V_117 , 131072UL ) ;
V_117 = V_15 ( V_117 , V_2 -> V_119 ) ;
V_118 = V_2 -> V_120 + V_2 -> V_119 ;
if ( V_118 < V_2 -> V_120 )
V_118 = V_121 ;
V_2 -> V_120 = F_60 ( V_118 , V_117 ) ;
}
static void F_61 ( unsigned long V_43 )
{
struct V_1 * V_2 = (struct V_1 * ) V_43 ;
F_59 ( V_2 ) ;
F_56 ( V_2 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_122 * V_123 , T_1 V_124 )
{
T_1 V_125 = V_2 -> V_115 . V_53 ;
do {
F_63 ( V_2 , V_123 , V_81 ) ;
if ( V_125 == V_124 )
break;
V_123 = F_23 ( & V_2 -> V_115 , V_125 ++ ) ;
} while ( 1 );
V_2 -> V_115 . V_53 = V_125 ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_65 ( V_2 -> V_16 , L_2 ) ;
F_66 ( V_2 ) ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_122 * V_126 ,
struct V_122 * V_123 ,
int V_127 )
{
T_1 V_125 = V_2 -> V_115 . V_53 ;
int V_128 = 0 ;
int V_129 = 0 ;
int V_130 ;
if ( ! ( V_126 -> V_64 & V_131 ) )
return 0 ;
do {
struct V_122 V_132 = { 0 } ;
if ( V_128 >= V_127 ) {
F_65 ( V_2 -> V_16 ,
L_3 ,
V_127 ) ;
F_64 ( V_2 ) ;
return - V_133 ;
}
if ( F_68 ( V_128 >= V_134 ) ) {
F_65 ( V_2 -> V_16 ,
L_4 ,
V_128 , V_134 ) ;
F_64 ( V_2 ) ;
return - V_135 ;
}
if ( ! V_129 && V_128 >= V_136 ) {
if ( F_69 () )
F_35 ( V_2 -> V_16 ,
L_5 ,
V_128 , V_136 ) ;
V_129 = - V_135 ;
}
if ( V_129 )
V_123 = & V_132 ;
memcpy ( V_123 , F_23 ( & V_2 -> V_115 , V_125 + V_128 ) ,
sizeof( * V_123 ) ) ;
if ( ! V_129 && V_123 -> V_33 > V_126 -> V_33 ) {
if ( F_69 () )
F_35 ( V_2 -> V_16 ,
L_6 ,
V_123 -> V_33 , V_126 -> V_33 ) ;
V_129 = - V_137 ;
}
V_126 -> V_33 -= V_123 -> V_33 ;
V_128 ++ ;
if ( F_68 ( ( V_123 -> V_32 + V_123 -> V_33 ) > V_18 ) ) {
F_65 ( V_2 -> V_16 , L_7 ,
V_123 -> V_32 , V_123 -> V_33 ) ;
F_64 ( V_2 ) ;
return - V_138 ;
}
V_130 = V_123 -> V_64 & V_131 ;
if ( ! V_129 )
V_123 ++ ;
} while ( V_130 );
if ( V_129 ) {
F_62 ( V_2 , V_126 , V_125 + V_128 ) ;
return V_129 ;
}
return V_128 ;
}
static struct V_58 * F_70 ( struct V_1 * V_2 ,
T_2 V_10 )
{
struct V_58 * V_58 ;
V_58 = F_71 ( V_139 | V_140 ) ;
if ( ! V_58 )
return NULL ;
V_2 -> V_7 [ V_10 ] = V_58 ;
return V_58 ;
}
static struct V_59 * F_72 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
struct V_122 * V_123 ,
struct V_59 * V_141 )
{
struct V_142 * V_143 = F_18 ( V_42 ) ;
T_3 * V_46 = V_143 -> V_46 ;
T_2 V_10 = * ( ( T_2 * ) V_42 -> V_43 ) ;
T_2 V_144 = 0 ;
int V_145 , V_146 ;
struct V_58 * V_58 ;
T_4 V_147 , V_148 = 0 ;
T_6 V_149 ;
unsigned int V_150 ;
struct V_4 * V_126 = NULL ;
V_150 = V_143 -> V_45 ;
V_146 = ( F_6 ( & V_143 -> V_46 [ 0 ] ) == V_10 ) ;
for ( V_143 -> V_45 = V_145 = V_146 ; V_145 < V_150 ;
V_143 -> V_45 ++ ) {
struct V_4 * V_4 =
V_2 -> V_4 ;
V_58 = F_71 ( V_139 | V_140 ) ;
if ( ! V_58 )
goto V_151;
V_149 = 0 ;
V_126 = NULL ;
while ( V_149 < V_18 && V_145 < V_150 ) {
V_141 -> V_64 = V_152 ;
V_141 -> V_67 . V_70 . V_73 = V_123 -> V_57 ;
V_141 -> V_67 . V_68 = V_2 -> V_68 ;
V_141 -> V_67 . V_32 = V_123 -> V_32 ;
V_141 -> V_72 . V_68 = V_69 ;
V_141 -> V_72 . V_32 = V_149 ;
V_141 -> V_72 . V_70 . V_71 = F_27 ( F_28 ( V_58 ) ) ;
if ( V_149 + V_123 -> V_33 > V_18 ) {
V_141 -> V_66 = V_18 - V_149 ;
V_123 -> V_32 += V_141 -> V_66 ;
V_123 -> V_33 -= V_141 -> V_66 ;
V_149 += V_141 -> V_66 ;
} else {
V_141 -> V_66 = V_123 -> V_33 ;
V_149 += V_141 -> V_66 ;
V_147 = F_8 ( V_2 -> V_14 ++ ) ;
V_10 = V_2 -> V_153 [ V_147 ] ;
memcpy ( & V_4 [ V_10 ] . V_52 , V_123 ,
sizeof( * V_123 ) ) ;
V_2 -> V_7 [ V_10 ] = ( void * ) ( ~ 0UL ) ;
V_4 [ V_10 ] . V_5 =
V_6 ;
if ( ! V_126 ) {
V_126 = & V_4 [ V_10 ] ;
V_148 = V_147 ;
V_144 = V_10 ;
}
V_123 ++ ;
V_145 ++ ;
}
V_141 ++ ;
}
V_126 -> V_52 . V_32 = 0 ;
V_126 -> V_52 . V_33 = V_149 ;
V_126 -> V_5 = V_148 ;
V_2 -> V_7 [ V_144 ] = V_58 ;
F_7 ( & V_46 [ V_143 -> V_45 ] , V_144 ) ;
}
F_25 ( V_143 -> V_45 > V_22 ) ;
return V_141 ;
V_151:
while ( V_143 -> V_45 -- > V_146 ) {
F_73 ( V_2 ,
F_6 ( & V_46 [ V_143 -> V_45 ] ) ,
V_81 ) ;
}
if ( V_146 )
F_73 ( V_2 , V_10 , V_81 ) ;
return NULL ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
struct V_59 * * V_154 )
{
struct V_59 * V_141 = * V_154 ;
T_2 V_10 = * ( ( T_2 * ) V_42 -> V_43 ) ;
struct V_142 * V_143 = F_18 ( V_42 ) ;
struct V_4 * V_155 ;
int V_45 = V_143 -> V_45 ;
int V_11 , V_151 , V_146 ;
T_2 V_23 ;
V_151 = V_141 -> V_77 ;
if ( F_68 ( V_151 ) )
F_73 ( V_2 , V_10 , V_81 ) ;
V_146 = ( F_6 ( & V_143 -> V_46 [ 0 ] ) == V_10 ) ;
for ( V_11 = V_146 ; V_11 < V_45 ; V_11 ++ ) {
int V_156 , V_157 ;
T_4 V_5 ;
V_10 = F_6 ( & V_143 -> V_46 [ V_11 ] ) ;
V_155 = & V_2 -> V_4 [ V_10 ] ;
V_5 = V_155 -> V_5 ;
do {
V_157 = ( ++ V_141 ) -> V_77 ;
if ( V_157 )
break;
V_23 = V_2 -> V_153 [ F_8 ( ++ V_5 ) ] ;
} while ( ! F_1 ( V_2 , V_23 ) );
if ( F_75 ( ! V_157 ) ) {
if ( F_68 ( V_151 ) )
F_73 ( V_2 , V_10 ,
V_78 ) ;
continue;
}
F_73 ( V_2 , V_10 , V_81 ) ;
if ( V_151 )
continue;
V_10 = * ( ( T_2 * ) V_42 -> V_43 ) ;
F_73 ( V_2 , V_10 , V_78 ) ;
for ( V_156 = V_146 ; V_156 < V_11 ; V_156 ++ ) {
V_10 = F_6 ( & V_143 -> V_46 [ V_156 ] ) ;
F_73 ( V_2 , V_10 ,
V_78 ) ;
}
V_151 = V_157 ;
}
* V_154 = V_141 + 1 ;
return V_151 ;
}
static void F_76 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_142 * V_143 = F_18 ( V_42 ) ;
int V_45 = V_143 -> V_45 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_45 ; V_11 ++ ) {
T_3 * V_8 = V_143 -> V_46 + V_11 ;
struct V_122 * V_123 ;
struct V_58 * V_58 ;
T_2 V_10 ;
V_10 = F_6 ( V_8 ) ;
V_123 = & V_2 -> V_4 [ V_10 ] . V_52 ;
V_58 = F_32 ( F_4 ( V_2 , V_10 ) ) ;
F_77 ( V_42 , V_11 , V_58 , V_123 -> V_32 , V_123 -> V_33 ) ;
V_42 -> V_66 += V_123 -> V_33 ;
V_42 -> V_158 += V_123 -> V_33 ;
V_42 -> V_159 += V_123 -> V_33 ;
F_78 ( V_2 -> V_7 [ V_10 ] ) ;
F_73 ( V_2 , V_10 , V_78 ) ;
}
}
static int F_79 ( struct V_1 * V_2 ,
struct V_107 * V_160 ,
int V_127 )
{
struct V_107 V_161 ;
T_1 V_125 = V_2 -> V_115 . V_53 ;
do {
if ( F_68 ( V_127 -- <= 0 ) ) {
F_65 ( V_2 -> V_16 , L_8 ) ;
F_64 ( V_2 ) ;
return - V_162 ;
}
memcpy ( & V_161 , F_23 ( & V_2 -> V_115 , V_125 ) ,
sizeof( V_161 ) ) ;
if ( F_68 ( ! V_161 . type ||
V_161 . type >= V_163 ) ) {
V_2 -> V_115 . V_53 = ++ V_125 ;
F_65 ( V_2 -> V_16 ,
L_9 , V_161 . type ) ;
F_64 ( V_2 ) ;
return - V_138 ;
}
memcpy ( & V_160 [ V_161 . type - 1 ] , & V_161 , sizeof( V_161 ) ) ;
V_2 -> V_115 . V_53 = ++ V_125 ;
} while ( V_161 . V_64 & V_164 );
return V_127 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
struct V_107 * V_20 )
{
if ( ! V_20 -> V_70 . V_20 . V_33 ) {
F_65 ( V_2 -> V_16 , L_10 ) ;
F_64 ( V_2 ) ;
return - V_138 ;
}
if ( V_20 -> V_70 . V_20 . type != V_109 ) {
F_65 ( V_2 -> V_16 , L_11 , V_20 -> V_70 . V_20 . type ) ;
F_64 ( V_2 ) ;
return - V_138 ;
}
F_18 ( V_42 ) -> V_44 = V_20 -> V_70 . V_20 . V_33 ;
F_18 ( V_42 ) -> V_165 = V_166 ;
F_18 ( V_42 ) -> V_165 |= V_167 ;
F_18 ( V_42 ) -> V_168 = 0 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_169 * V_170 ;
int V_151 = - V_171 ;
int V_172 = 0 ;
if ( V_42 -> V_102 != V_103 && F_82 ( V_42 ) ) {
V_2 -> V_173 ++ ;
V_42 -> V_102 = V_103 ;
V_172 = 1 ;
}
if ( V_42 -> V_102 != V_103 )
return 0 ;
if ( V_42 -> V_174 != F_83 ( V_175 ) )
goto V_176;
V_170 = ( void * ) V_42 -> V_43 ;
switch ( V_170 -> V_174 ) {
case V_177 :
if ( ! F_84 ( V_42 , 4 * V_170 -> V_178 ,
F_85 ( struct V_179 , V_180 ) ) )
goto V_176;
if ( V_172 ) {
struct V_179 * V_181 = F_86 ( V_42 ) ;
V_181 -> V_180 = ~ F_87 ( V_170 -> V_182 , V_170 -> V_183 ,
V_42 -> V_66 - V_170 -> V_178 * 4 ,
V_177 , 0 ) ;
}
break;
case V_184 :
if ( ! F_84 ( V_42 , 4 * V_170 -> V_178 ,
F_85 ( struct V_185 , V_180 ) ) )
goto V_176;
if ( V_172 ) {
struct V_185 * V_186 = F_88 ( V_42 ) ;
V_186 -> V_180 = ~ F_87 ( V_170 -> V_182 , V_170 -> V_183 ,
V_42 -> V_66 - V_170 -> V_178 * 4 ,
V_184 , 0 ) ;
}
break;
default:
if ( F_69 () )
F_65 ( V_2 -> V_16 ,
L_12 ,
V_170 -> V_174 ) ;
goto V_176;
}
V_151 = 0 ;
V_176:
return V_151 ;
}
static bool F_89 ( struct V_1 * V_2 , unsigned V_33 )
{
unsigned long V_187 = V_188 ;
unsigned long V_189 =
V_2 -> V_190 . V_191 +
F_90 ( V_2 -> V_192 / 1000 ) ;
if ( F_91 ( & V_2 -> V_190 ) )
return true ;
if ( F_92 ( V_187 , V_189 ) ) {
V_2 -> V_190 . V_191 = V_187 ;
F_59 ( V_2 ) ;
}
if ( V_33 > V_2 -> V_120 ) {
V_2 -> V_190 . V_43 =
( unsigned long ) V_2 ;
V_2 -> V_190 . V_193 =
F_61 ;
F_93 ( & V_2 -> V_190 ,
V_189 ) ;
return true ;
}
return false ;
}
static unsigned F_94 ( struct V_1 * V_2 )
{
struct V_59 * V_141 = V_2 -> V_194 , * V_195 ;
struct V_41 * V_42 ;
int V_89 ;
while ( ( F_9 ( V_2 ) + V_136
< V_12 ) ) {
struct V_122 V_196 ;
struct V_122 V_197 [ V_136 ] ;
struct V_58 * V_58 ;
struct V_107 V_160 [ V_163 - 1 ] ;
T_2 V_10 ;
T_1 V_3 ;
int V_127 ;
unsigned int V_158 ;
T_4 V_147 ;
if ( V_2 -> V_115 . V_27 -> V_28 - V_2 -> V_115 . V_53 >
V_198 ) {
F_65 ( V_2 -> V_16 ,
L_13
L_14 ,
V_2 -> V_115 . V_27 -> V_28 , V_2 -> V_115 . V_53 ,
V_198 ) ;
F_64 ( V_2 ) ;
continue;
}
F_57 ( & V_2 -> V_115 , V_127 ) ;
if ( ! V_127 )
break;
V_3 = V_2 -> V_115 . V_53 ;
F_95 () ;
memcpy ( & V_196 , F_23 ( & V_2 -> V_115 , V_3 ) , sizeof( V_196 ) ) ;
if ( V_196 . V_33 > V_2 -> V_120 &&
F_89 ( V_2 , V_196 . V_33 ) )
break;
V_2 -> V_120 -= V_196 . V_33 ;
V_127 -- ;
V_2 -> V_115 . V_53 = ++ V_3 ;
memset ( V_160 , 0 , sizeof( V_160 ) ) ;
if ( V_196 . V_64 & V_199 ) {
V_127 = F_79 ( V_2 , V_160 ,
V_127 ) ;
V_3 = V_2 -> V_115 . V_53 ;
if ( F_68 ( V_127 < 0 ) )
break;
}
V_89 = F_67 ( V_2 , & V_196 , V_197 , V_127 ) ;
if ( F_68 ( V_89 < 0 ) )
break;
V_3 += V_89 ;
if ( F_68 ( V_196 . V_33 < V_200 ) ) {
F_35 ( V_2 -> V_16 ,
L_15 , V_196 . V_33 ) ;
F_62 ( V_2 , & V_196 , V_3 ) ;
break;
}
if ( F_68 ( ( V_196 . V_32 + V_196 . V_33 ) > V_18 ) ) {
F_65 ( V_2 -> V_16 ,
L_16 ,
V_196 . V_32 , V_196 . V_33 ,
( V_196 . V_32 & ~ V_38 ) + V_196 . V_33 ) ;
F_64 ( V_2 ) ;
break;
}
V_147 = F_8 ( V_2 -> V_14 ) ;
V_10 = V_2 -> V_153 [ V_147 ] ;
V_158 = ( V_196 . V_33 > V_201 &&
V_89 < V_136 ) ?
V_201 : V_196 . V_33 ;
V_42 = F_96 ( V_158 + V_202 + V_203 ,
V_139 | V_204 ) ;
if ( F_68 ( V_42 == NULL ) ) {
F_35 ( V_2 -> V_16 ,
L_17 ) ;
F_62 ( V_2 , & V_196 , V_3 ) ;
break;
}
F_97 ( V_42 , V_202 + V_203 ) ;
if ( V_160 [ V_112 - 1 ] . type ) {
struct V_107 * V_20 ;
V_20 = & V_160 [ V_112 - 1 ] ;
if ( F_80 ( V_2 , V_42 , V_20 ) ) {
F_98 ( V_42 ) ;
break;
}
}
V_58 = F_70 ( V_2 , V_10 ) ;
if ( ! V_58 ) {
F_98 ( V_42 ) ;
F_62 ( V_2 , & V_196 , V_3 ) ;
break;
}
V_141 -> V_67 . V_70 . V_73 = V_196 . V_57 ;
V_141 -> V_67 . V_68 = V_2 -> V_68 ;
V_141 -> V_67 . V_32 = V_196 . V_32 ;
V_141 -> V_72 . V_70 . V_71 = F_27 ( F_28 ( V_58 ) ) ;
V_141 -> V_72 . V_68 = V_69 ;
V_141 -> V_72 . V_32 = V_196 . V_32 ;
V_141 -> V_66 = V_196 . V_33 ;
V_141 -> V_64 = V_152 ;
V_141 ++ ;
memcpy ( & V_2 -> V_4 [ V_10 ] . V_52 ,
& V_196 , sizeof( V_196 ) ) ;
V_2 -> V_4 [ V_10 ] . V_5 = V_147 ;
* ( ( T_2 * ) V_42 -> V_43 ) = V_10 ;
F_99 ( V_42 , V_158 ) ;
F_18 ( V_42 ) -> V_45 = V_89 ;
if ( V_158 < V_196 . V_33 ) {
F_18 ( V_42 ) -> V_45 ++ ;
F_7 ( & F_18 ( V_42 ) -> V_46 [ 0 ] ,
V_10 ) ;
} else {
F_7 ( & F_18 ( V_42 ) -> V_46 [ 0 ] ,
V_205 ) ;
}
V_2 -> V_14 ++ ;
V_195 = F_72 ( V_2 , V_42 , V_197 , V_141 ) ;
if ( V_195 == NULL ) {
F_98 ( V_42 ) ;
F_62 ( V_2 , & V_196 , V_3 ) ;
break;
}
V_141 = V_195 ;
F_44 ( & V_2 -> V_206 , V_42 ) ;
V_2 -> V_115 . V_53 = V_3 ;
if ( ( V_141 - V_2 -> V_194 ) >= F_45 ( V_2 -> V_194 ) )
break;
}
return V_141 - V_2 -> V_194 ;
}
static int F_100 ( struct V_1 * V_2 , int V_207 )
{
struct V_59 * V_141 = V_2 -> V_194 ;
struct V_41 * V_42 ;
int V_208 = 0 ;
while ( V_208 < V_207 &&
( V_42 = F_47 ( & V_2 -> V_206 ) ) != NULL ) {
struct V_122 * V_123 ;
T_2 V_10 ;
unsigned V_158 ;
V_10 = * ( ( T_2 * ) V_42 -> V_43 ) ;
V_123 = & V_2 -> V_4 [ V_10 ] . V_52 ;
if ( F_68 ( F_74 ( V_2 , V_42 , & V_141 ) ) ) {
F_35 ( V_2 -> V_16 , L_18 ) ;
F_18 ( V_42 ) -> V_45 = 0 ;
F_98 ( V_42 ) ;
continue;
}
V_158 = V_42 -> V_66 ;
memcpy ( V_42 -> V_43 ,
( void * ) ( F_4 ( V_2 , V_10 ) | V_123 -> V_32 ) ,
V_158 ) ;
if ( V_158 < V_123 -> V_33 ) {
V_123 -> V_32 += V_158 ;
V_123 -> V_33 -= V_158 ;
} else {
F_73 ( V_2 , V_10 ,
V_78 ) ;
}
if ( V_123 -> V_64 & V_209 )
V_42 -> V_102 = V_103 ;
else if ( V_123 -> V_64 & V_210 )
V_42 -> V_102 = V_106 ;
F_76 ( V_2 , V_42 ) ;
if ( F_101 ( V_42 ) < V_201 && F_102 ( V_42 ) ) {
int V_211 = F_103 ( int , V_42 -> V_66 , V_201 ) ;
F_104 ( V_42 , V_211 - F_101 ( V_42 ) ) ;
}
V_42 -> V_16 = V_2 -> V_16 ;
V_42 -> V_174 = F_105 ( V_42 , V_42 -> V_16 ) ;
F_106 ( V_42 ) ;
if ( F_81 ( V_2 , V_42 ) ) {
F_35 ( V_2 -> V_16 ,
L_19 ) ;
F_98 ( V_42 ) ;
continue;
}
F_107 ( V_42 , 0 ) ;
V_2 -> V_16 -> V_99 . V_212 += V_42 -> V_66 ;
V_2 -> V_16 -> V_99 . V_213 ++ ;
V_208 ++ ;
F_108 ( V_42 ) ;
}
return V_208 ;
}
int F_109 ( struct V_1 * V_2 , int V_207 )
{
unsigned V_214 ;
int V_208 ;
if ( F_68 ( ! F_110 ( V_2 ) ) )
return 0 ;
V_214 = F_94 ( V_2 ) ;
if ( V_214 == 0 )
return 0 ;
F_46 ( V_2 -> V_194 , V_214 ) ;
V_208 = F_100 ( V_2 , V_214 ) ;
return V_208 ;
}
static void F_73 ( struct V_1 * V_2 , T_2 V_10 ,
T_7 V_77 )
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
F_25 ( V_2 -> V_153 [ F_8 ( V_5 ) ] != V_10 ) ;
do {
T_4 V_147 ;
T_4 V_3 = F_8 ( V_5 ) ;
T_2 V_215 = V_2 -> V_153 [ V_3 ] ;
V_4 = & V_2 -> V_4 [ V_215 ] ;
F_63 ( V_2 , & V_4 -> V_52 , V_77 ) ;
V_4 -> V_5 = 0 ;
V_147 = F_8 ( V_2 -> V_13 ++ ) ;
V_2 -> V_153 [ V_147 ] = V_2 -> V_153 [ V_215 ] ;
V_23 = V_2 -> V_153 [ F_8 ( ++ V_5 ) ] ;
} while ( ! F_1 ( V_2 , V_23 ) );
F_111 ( V_2 -> V_7 [ V_10 ] ) ;
V_2 -> V_7 [ V_10 ] = NULL ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_122 * V_123 ,
T_5 V_216 )
{
T_1 V_11 = V_2 -> V_115 . V_29 ;
struct V_217 * V_85 ;
int V_88 ;
V_85 = F_48 ( & V_2 -> V_115 , V_11 ) ;
V_85 -> V_55 = V_123 -> V_55 ;
V_85 -> V_77 = V_216 ;
if ( V_123 -> V_64 & V_199 )
F_48 ( & V_2 -> V_115 , ++ V_11 ) -> V_77 = V_218 ;
V_2 -> V_115 . V_29 = ++ V_11 ;
F_49 ( & V_2 -> V_115 , V_88 ) ;
if ( V_88 )
F_52 ( V_2 -> V_219 ) ;
}
static struct V_84 * F_37 ( struct V_1 * V_2 ,
T_2 V_55 ,
T_5 V_216 ,
T_2 V_32 ,
T_2 V_33 ,
T_2 V_64 )
{
T_1 V_11 = V_2 -> V_26 . V_29 ;
struct V_84 * V_85 ;
V_85 = F_48 ( & V_2 -> V_26 , V_11 ) ;
V_85 -> V_32 = V_32 ;
V_85 -> V_64 = V_64 ;
V_85 -> V_55 = V_55 ;
V_85 -> V_77 = ( V_220 ) V_33 ;
if ( V_216 < 0 )
V_85 -> V_77 = ( V_220 ) V_216 ;
V_2 -> V_26 . V_29 = ++ V_11 ;
return V_85 ;
}
static inline int F_112 ( struct V_1 * V_2 )
{
return ! F_53 ( & V_2 -> V_94 ) ;
}
static inline int F_110 ( struct V_1 * V_2 )
{
if ( F_75 ( F_113 ( & V_2 -> V_115 ) ) &&
( F_9 ( V_2 ) + V_136
< V_12 ) )
return 1 ;
return 0 ;
}
void F_114 ( struct V_1 * V_2 )
{
if ( V_2 -> V_115 . V_27 )
F_115 ( F_116 ( V_2 ) ,
V_2 -> V_115 . V_27 ) ;
if ( V_2 -> V_26 . V_27 )
F_115 ( F_116 ( V_2 ) ,
V_2 -> V_26 . V_27 ) ;
}
int F_117 ( struct V_1 * V_2 ,
T_8 V_221 ,
T_8 V_222 )
{
void * V_223 ;
struct V_224 * V_225 ;
struct V_226 * V_227 ;
int V_151 = - V_228 ;
V_151 = F_118 ( F_116 ( V_2 ) ,
V_221 , & V_223 ) ;
if ( V_151 )
goto V_151;
V_225 = (struct V_224 * ) V_223 ;
F_119 ( & V_2 -> V_115 , V_225 , V_18 ) ;
V_151 = F_118 ( F_116 ( V_2 ) ,
V_222 , & V_223 ) ;
if ( V_151 )
goto V_151;
V_227 = (struct V_226 * ) V_223 ;
F_119 ( & V_2 -> V_26 , V_227 , V_18 ) ;
V_2 -> V_24 = 0 ;
return 0 ;
V_151:
F_114 ( V_2 ) ;
return V_151 ;
}
int F_120 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
while ( ! F_121 () ) {
F_122 ( V_2 -> V_83 ,
F_112 ( V_2 ) ||
F_121 () ) ;
if ( F_121 () )
break;
if ( F_112 ( V_2 ) )
F_40 ( V_2 ) ;
F_123 () ;
}
return 0 ;
}
static int T_9 F_124 ( void )
{
int V_229 = 0 ;
if ( ! F_125 () )
return - V_230 ;
if ( V_134 < V_136 ) {
F_126 ( L_20 ,
V_134 , V_136 ) ;
V_134 = V_136 ;
}
V_229 = F_127 () ;
if ( V_229 )
goto V_231;
return 0 ;
V_231:
return V_229 ;
}
static void T_10 F_128 ( void )
{
F_129 () ;
}
