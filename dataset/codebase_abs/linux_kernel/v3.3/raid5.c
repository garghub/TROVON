static inline struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
int V_5 = ( V_4 >> V_6 ) & V_7 ;
return & V_3 -> V_8 [ V_5 ] ;
}
static inline struct V_9 * F_2 ( struct V_9 * V_9 , T_1 V_10 )
{
int V_11 = V_9 -> V_12 >> 9 ;
if ( V_9 -> V_13 + V_11 < V_10 + V_14 )
return V_9 -> V_15 ;
else
return NULL ;
}
static inline int F_3 ( struct V_9 * V_9 )
{
return V_9 -> V_16 & 0xffff ;
}
static inline int F_4 ( struct V_9 * V_9 )
{
return ( V_9 -> V_16 >> 16 ) & 0xffff ;
}
static inline int F_5 ( struct V_9 * V_9 )
{
-- V_9 -> V_16 ;
return F_3 ( V_9 ) ;
}
static inline int F_6 ( struct V_9 * V_9 )
{
unsigned short V_17 = F_4 ( V_9 ) ;
-- V_17 ;
V_9 -> V_16 = ( V_17 << 16 ) | F_3 ( V_9 ) ;
return V_17 ;
}
static inline void F_7 ( struct V_9 * V_9 , unsigned int V_18 )
{
V_9 -> V_16 = F_3 ( V_9 ) | ( V_18 << 16 ) ;
}
static inline int F_8 ( struct V_19 * V_20 )
{
if ( V_20 -> V_21 )
return 0 ;
if ( V_20 -> V_22 == V_20 -> V_23 - 1 )
return 0 ;
else
return V_20 -> V_22 + 1 ;
}
static inline int F_9 ( int V_24 , int V_25 )
{
V_24 ++ ;
return ( V_24 < V_25 ) ? V_24 : 0 ;
}
static int F_10 ( int V_26 , struct V_19 * V_20 ,
int * V_27 , int V_28 )
{
int V_29 = * V_27 ;
if ( V_20 -> V_21 )
( * V_27 ) ++ ;
if ( V_26 == V_20 -> V_30 )
return V_28 ;
if ( V_26 == V_20 -> V_22 )
return V_28 + 1 ;
if ( ! V_20 -> V_21 )
( * V_27 ) ++ ;
return V_29 ;
}
static void F_11 ( struct V_9 * V_31 )
{
struct V_9 * V_32 = V_31 ;
while ( V_32 ) {
V_31 = V_32 -> V_15 ;
V_32 -> V_15 = NULL ;
V_32 -> V_12 = 0 ;
F_12 ( V_32 , 0 ) ;
V_32 = V_31 ;
}
}
static int F_13 ( struct V_19 * V_20 )
{
return V_20 -> V_33 || V_20 -> V_34 ||
F_14 ( V_35 , & V_20 -> V_36 ) ||
F_14 ( V_37 , & V_20 -> V_36 ) ;
}
static void F_15 ( struct V_2 * V_3 , struct V_19 * V_20 )
{
if ( F_16 ( & V_20 -> V_27 ) ) {
F_17 ( ! F_18 ( & V_20 -> V_38 ) ) ;
F_17 ( F_19 ( & V_3 -> V_39 ) == 0 ) ;
if ( F_14 ( V_40 , & V_20 -> V_36 ) ) {
if ( F_14 ( V_41 , & V_20 -> V_36 ) )
F_20 ( & V_20 -> V_38 , & V_3 -> V_42 ) ;
else if ( F_14 ( V_43 , & V_20 -> V_36 ) &&
V_20 -> V_44 - V_3 -> V_45 > 0 )
F_20 ( & V_20 -> V_38 , & V_3 -> V_46 ) ;
else {
F_21 ( V_43 , & V_20 -> V_36 ) ;
F_20 ( & V_20 -> V_38 , & V_3 -> V_47 ) ;
}
F_22 ( V_3 -> V_48 -> V_49 ) ;
} else {
F_17 ( F_13 ( V_20 ) ) ;
if ( F_23 ( V_50 , & V_20 -> V_36 ) ) {
F_24 ( & V_3 -> V_51 ) ;
if ( F_19 ( & V_3 -> V_51 ) < V_52 )
F_22 ( V_3 -> V_48 -> V_49 ) ;
}
F_24 ( & V_3 -> V_39 ) ;
if ( ! F_14 ( V_53 , & V_20 -> V_36 ) ) {
F_20 ( & V_20 -> V_38 , & V_3 -> V_54 ) ;
F_25 ( & V_3 -> V_55 ) ;
if ( V_3 -> V_56 )
F_22 ( V_3 -> V_48 -> V_49 ) ;
}
}
}
}
static void F_26 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = V_20 -> V_57 ;
unsigned long V_58 ;
F_27 ( & V_3 -> V_59 , V_58 ) ;
F_15 ( V_3 , V_20 ) ;
F_28 ( & V_3 -> V_59 , V_58 ) ;
}
static inline void F_29 ( struct V_19 * V_20 )
{
F_30 ( L_1 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_31 ( & V_20 -> V_5 ) ;
}
static inline void F_32 ( struct V_2 * V_3 , struct V_19 * V_20 )
{
struct V_1 * V_60 = F_1 ( V_3 , V_20 -> V_10 ) ;
F_30 ( L_2 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_33 ( & V_20 -> V_5 , V_60 ) ;
}
static struct V_19 * F_34 ( struct V_2 * V_3 )
{
struct V_19 * V_20 = NULL ;
struct V_61 * V_62 ;
if ( F_18 ( & V_3 -> V_54 ) )
goto V_63;
V_62 = V_3 -> V_54 . V_64 ;
V_20 = F_35 ( V_62 , struct V_19 , V_38 ) ;
F_36 ( V_62 ) ;
F_29 ( V_20 ) ;
F_37 ( & V_3 -> V_39 ) ;
V_63:
return V_20 ;
}
static void F_38 ( struct V_19 * V_20 )
{
struct V_65 * V_66 ;
int V_67 ;
int V_68 = V_20 -> V_57 -> V_69 ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
V_66 = V_20 -> V_70 [ V_67 ] . V_65 ;
if ( ! V_66 )
continue;
V_20 -> V_70 [ V_67 ] . V_65 = NULL ;
F_39 ( V_66 ) ;
}
}
static int F_40 ( struct V_19 * V_20 )
{
int V_67 ;
int V_68 = V_20 -> V_57 -> V_69 ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
struct V_65 * V_65 ;
if ( ! ( V_65 = F_41 ( V_71 ) ) ) {
return 1 ;
}
V_20 -> V_70 [ V_67 ] . V_65 = V_65 ;
}
return 0 ;
}
static void F_42 ( struct V_19 * V_20 , T_1 V_10 , int V_72 )
{
struct V_2 * V_3 = V_20 -> V_57 ;
int V_67 ;
F_17 ( F_19 ( & V_20 -> V_27 ) != 0 ) ;
F_17 ( F_14 ( V_40 , & V_20 -> V_36 ) ) ;
F_17 ( F_13 ( V_20 ) ) ;
F_30 ( L_3 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_29 ( V_20 ) ;
V_20 -> V_73 = V_3 -> V_73 - V_72 ;
V_20 -> V_23 = V_72 ? V_3 -> V_74 : V_3 -> V_25 ;
V_20 -> V_10 = V_10 ;
F_43 ( V_10 , V_3 , V_72 , V_20 ) ;
V_20 -> V_36 = 0 ;
for ( V_67 = V_20 -> V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( V_70 -> V_76 || V_70 -> V_77 || V_70 -> V_78 || V_70 -> V_79 ||
F_14 ( V_80 , & V_70 -> V_58 ) ) {
F_44 ( V_81 L_4 ,
( unsigned long long ) V_20 -> V_10 , V_67 , V_70 -> V_76 ,
V_70 -> V_77 , V_70 -> V_78 , V_70 -> V_79 ,
F_14 ( V_80 , & V_70 -> V_58 ) ) ;
F_45 ( 1 ) ;
}
V_70 -> V_58 = 0 ;
F_46 ( V_20 , V_67 , V_72 ) ;
}
F_32 ( V_3 , V_20 ) ;
}
static struct V_19 * F_47 ( struct V_2 * V_3 , T_1 V_10 ,
short V_73 )
{
struct V_19 * V_20 ;
struct V_82 * V_83 ;
F_30 ( L_5 , ( unsigned long long ) V_10 ) ;
F_48 (sh, hn, stripe_hash(conf, sector), hash)
if ( V_20 -> V_10 == V_10 && V_20 -> V_73 == V_73 )
return V_20 ;
F_30 ( L_6 , ( unsigned long long ) V_10 ) ;
return NULL ;
}
static int F_49 ( struct V_2 * V_3 )
{
int V_84 , V_85 ;
int V_67 ;
F_50 () ;
V_84 = 0 ;
for ( V_67 = 0 ; V_67 < V_3 -> V_74 ; V_67 ++ ) {
struct V_86 * V_87 = F_51 ( V_3 -> V_23 [ V_67 ] . V_87 ) ;
if ( ! V_87 || F_14 ( V_88 , & V_87 -> V_58 ) )
V_84 ++ ;
else if ( F_14 ( V_89 , & V_87 -> V_58 ) )
;
else
if ( V_3 -> V_25 >= V_3 -> V_74 )
V_84 ++ ;
}
F_52 () ;
if ( V_3 -> V_25 == V_3 -> V_74 )
return V_84 ;
F_50 () ;
V_85 = 0 ;
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ ) {
struct V_86 * V_87 = F_51 ( V_3 -> V_23 [ V_67 ] . V_87 ) ;
if ( ! V_87 || F_14 ( V_88 , & V_87 -> V_58 ) )
V_85 ++ ;
else if ( F_14 ( V_89 , & V_87 -> V_58 ) )
;
else
if ( V_3 -> V_25 <= V_3 -> V_74 )
V_85 ++ ;
}
F_52 () ;
if ( V_85 > V_84 )
return V_85 ;
return V_84 ;
}
static int F_53 ( struct V_2 * V_3 )
{
int V_84 ;
if ( V_3 -> V_48 -> V_90 == V_91 )
return V_3 -> V_48 -> V_84 > V_3 -> V_92 ;
V_84 = F_49 ( V_3 ) ;
if ( V_84 > V_3 -> V_92 )
return 1 ;
return 0 ;
}
static struct V_19 *
F_54 ( struct V_2 * V_3 , T_1 V_10 ,
int V_72 , int V_93 , int V_94 )
{
struct V_19 * V_20 ;
F_30 ( L_7 , ( unsigned long long ) V_10 ) ;
F_55 ( & V_3 -> V_59 ) ;
do {
F_56 ( V_3 -> V_55 ,
V_3 -> V_95 == 0 || V_94 ,
V_3 -> V_59 , ) ;
V_20 = F_47 ( V_3 , V_10 , V_3 -> V_73 - V_72 ) ;
if ( ! V_20 ) {
if ( ! V_3 -> V_96 )
V_20 = F_34 ( V_3 ) ;
if ( V_93 && V_20 == NULL )
break;
if ( ! V_20 ) {
V_3 -> V_96 = 1 ;
F_56 ( V_3 -> V_55 ,
! F_18 ( & V_3 -> V_54 ) &&
( F_19 ( & V_3 -> V_39 )
< ( V_3 -> V_97 * 3 / 4 )
|| ! V_3 -> V_96 ) ,
V_3 -> V_59 ,
) ;
V_3 -> V_96 = 0 ;
} else
F_42 ( V_20 , V_10 , V_72 ) ;
} else {
if ( F_19 ( & V_20 -> V_27 ) ) {
F_17 ( ! F_18 ( & V_20 -> V_38 )
&& ! F_14 ( V_53 , & V_20 -> V_36 ) ) ;
} else {
if ( ! F_14 ( V_40 , & V_20 -> V_36 ) )
F_37 ( & V_3 -> V_39 ) ;
if ( F_18 ( & V_20 -> V_38 ) &&
! F_14 ( V_53 , & V_20 -> V_36 ) )
F_57 () ;
F_36 ( & V_20 -> V_38 ) ;
}
}
} while ( V_20 == NULL );
if ( V_20 )
F_37 ( & V_20 -> V_27 ) ;
F_58 ( & V_3 -> V_59 ) ;
return V_20 ;
}
static void F_59 ( struct V_19 * V_20 , struct V_98 * V_99 )
{
struct V_2 * V_3 = V_20 -> V_57 ;
int V_67 , V_23 = V_20 -> V_23 ;
F_60 () ;
for ( V_67 = V_23 ; V_67 -- ; ) {
int V_100 ;
int V_101 = 0 ;
struct V_9 * V_32 , * V_102 ;
struct V_86 * V_87 , * V_103 = NULL ;
if ( F_23 ( V_104 , & V_20 -> V_70 [ V_67 ] . V_58 ) ) {
if ( F_23 ( V_105 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
V_100 = V_106 ;
else
V_100 = V_107 ;
} else if ( F_23 ( V_108 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
V_100 = V_109 ;
else if ( F_23 ( V_110 ,
& V_20 -> V_70 [ V_67 ] . V_58 ) ) {
V_100 = V_107 ;
V_101 = 1 ;
} else
continue;
V_32 = & V_20 -> V_70 [ V_67 ] . V_111 ;
V_102 = & V_20 -> V_70 [ V_67 ] . V_112 ;
V_32 -> V_113 = V_100 ;
V_102 -> V_113 = V_100 ;
if ( V_100 & V_107 ) {
V_32 -> V_114 = V_115 ;
V_102 -> V_114 = V_115 ;
} else
V_32 -> V_114 = V_116 ;
F_50 () ;
V_103 = F_51 ( V_3 -> V_23 [ V_67 ] . V_117 ) ;
F_61 () ;
V_87 = F_51 ( V_3 -> V_23 [ V_67 ] . V_87 ) ;
if ( ! V_87 ) {
V_87 = V_103 ;
V_103 = NULL ;
}
if ( V_100 & V_107 ) {
if ( V_101 )
V_87 = NULL ;
if ( V_87 == V_103 )
V_103 = NULL ;
} else {
if ( F_14 ( V_118 , & V_20 -> V_70 [ V_67 ] . V_58 ) && V_103 )
V_87 = V_103 ;
V_103 = NULL ;
}
if ( V_87 && F_14 ( V_88 , & V_87 -> V_58 ) )
V_87 = NULL ;
if ( V_87 )
F_37 ( & V_87 -> V_119 ) ;
if ( V_103 && F_14 ( V_88 , & V_103 -> V_58 ) )
V_103 = NULL ;
if ( V_103 )
F_37 ( & V_103 -> V_119 ) ;
F_52 () ;
while ( ( V_100 & V_107 ) && V_87 &&
F_14 ( V_120 , & V_87 -> V_58 ) ) {
T_1 V_121 ;
int V_122 ;
int V_123 = F_62 ( V_87 , V_20 -> V_10 , V_14 ,
& V_121 , & V_122 ) ;
if ( ! V_123 )
break;
if ( V_123 < 0 ) {
F_63 ( V_124 , & V_87 -> V_58 ) ;
if ( ! V_3 -> V_48 -> V_125 &&
V_3 -> V_48 -> V_58 ) {
F_64 ( V_3 -> V_48 ) ;
}
F_65 ( V_87 , V_3 -> V_48 ) ;
} else {
F_66 ( V_87 , V_3 -> V_48 ) ;
V_87 = NULL ;
}
}
if ( V_87 ) {
if ( V_99 -> V_126 || V_99 -> V_127 || V_99 -> V_128
|| V_99 -> V_129 )
F_67 ( V_87 -> V_130 , V_14 ) ;
F_63 ( V_131 , & V_20 -> V_36 ) ;
V_32 -> V_132 = V_87 -> V_130 ;
F_30 ( L_8 ,
V_133 , ( unsigned long long ) V_20 -> V_10 ,
V_32 -> V_113 , V_67 ) ;
F_37 ( & V_20 -> V_27 ) ;
V_32 -> V_13 = V_20 -> V_10 + V_87 -> V_134 ;
V_32 -> V_135 = 1 << V_136 ;
V_32 -> V_137 = 0 ;
V_32 -> V_138 [ 0 ] . V_139 = V_140 ;
V_32 -> V_138 [ 0 ] . V_141 = 0 ;
V_32 -> V_12 = V_140 ;
V_32 -> V_15 = NULL ;
if ( V_103 )
F_63 ( V_142 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_68 ( V_32 ) ;
}
if ( V_103 ) {
if ( V_99 -> V_126 || V_99 -> V_127 || V_99 -> V_128
|| V_99 -> V_129 )
F_67 ( V_103 -> V_130 , V_14 ) ;
F_63 ( V_131 , & V_20 -> V_36 ) ;
V_102 -> V_132 = V_103 -> V_130 ;
F_30 ( L_9
L_10 ,
V_133 , ( unsigned long long ) V_20 -> V_10 ,
V_102 -> V_113 , V_67 ) ;
F_37 ( & V_20 -> V_27 ) ;
V_102 -> V_13 = V_20 -> V_10 + V_103 -> V_134 ;
V_102 -> V_135 = 1 << V_136 ;
V_102 -> V_137 = 0 ;
V_102 -> V_138 [ 0 ] . V_139 = V_140 ;
V_102 -> V_138 [ 0 ] . V_141 = 0 ;
V_102 -> V_12 = V_140 ;
V_102 -> V_15 = NULL ;
F_68 ( V_102 ) ;
}
if ( ! V_87 && ! V_103 ) {
if ( V_100 & V_107 )
F_63 ( V_143 , & V_20 -> V_36 ) ;
F_30 ( L_11 ,
V_32 -> V_113 , V_67 , ( unsigned long long ) V_20 -> V_10 ) ;
F_21 ( V_80 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_63 ( V_40 , & V_20 -> V_36 ) ;
}
}
}
static struct V_144 *
F_69 ( int V_145 , struct V_9 * V_9 , struct V_65 * V_65 ,
T_1 V_10 , struct V_144 * V_146 )
{
struct V_147 * V_148 ;
struct V_65 * V_149 ;
int V_67 ;
int V_150 ;
struct V_151 V_152 ;
enum V_153 V_58 = 0 ;
if ( V_9 -> V_13 >= V_10 )
V_150 = ( signed ) ( V_9 -> V_13 - V_10 ) * 512 ;
else
V_150 = ( signed ) ( V_10 - V_9 -> V_13 ) * - 512 ;
if ( V_145 )
V_58 |= V_154 ;
F_70 ( & V_152 , V_58 , V_146 , NULL , NULL , NULL ) ;
F_71 (bvl, bio, i) {
int V_155 = V_148 -> V_139 ;
int V_156 ;
int V_157 = 0 ;
if ( V_150 < 0 ) {
V_157 = - V_150 ;
V_150 += V_157 ;
V_155 -= V_157 ;
}
if ( V_155 > 0 && V_150 + V_155 > V_140 )
V_156 = V_140 - V_150 ;
else
V_156 = V_155 ;
if ( V_156 > 0 ) {
V_157 += V_148 -> V_141 ;
V_149 = V_148 -> V_158 ;
if ( V_145 )
V_146 = F_72 ( V_65 , V_149 , V_150 ,
V_157 , V_156 , & V_152 ) ;
else
V_146 = F_72 ( V_149 , V_65 , V_157 ,
V_150 , V_156 , & V_152 ) ;
}
V_152 . V_159 = V_146 ;
if ( V_156 < V_155 )
break;
V_150 += V_155 ;
}
return V_146 ;
}
static void F_73 ( void * V_160 )
{
struct V_19 * V_20 = V_160 ;
struct V_9 * V_31 = NULL ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_67 ;
F_30 ( L_12 , V_133 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_55 ( & V_3 -> V_59 ) ;
for ( V_67 = V_20 -> V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( F_23 ( V_161 , & V_70 -> V_58 ) ) {
struct V_9 * V_102 , * V_162 ;
F_17 ( ! V_70 -> V_77 ) ;
V_102 = V_70 -> V_77 ;
V_70 -> V_77 = NULL ;
while ( V_102 && V_102 -> V_13 <
V_70 -> V_10 + V_14 ) {
V_162 = F_2 ( V_102 , V_70 -> V_10 ) ;
if ( ! F_5 ( V_102 ) ) {
V_102 -> V_15 = V_31 ;
V_31 = V_102 ;
}
V_102 = V_162 ;
}
}
}
F_58 ( & V_3 -> V_59 ) ;
F_21 ( V_35 , & V_20 -> V_36 ) ;
F_11 ( V_31 ) ;
F_63 ( V_40 , & V_20 -> V_36 ) ;
F_26 ( V_20 ) ;
}
static void F_74 ( struct V_19 * V_20 )
{
struct V_144 * V_146 = NULL ;
struct V_2 * V_3 = V_20 -> V_57 ;
struct V_151 V_152 ;
int V_67 ;
F_30 ( L_12 , V_133 ,
( unsigned long long ) V_20 -> V_10 ) ;
for ( V_67 = V_20 -> V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( F_14 ( V_161 , & V_70 -> V_58 ) ) {
struct V_9 * V_102 ;
F_55 ( & V_3 -> V_59 ) ;
V_70 -> V_77 = V_102 = V_70 -> V_76 ;
V_70 -> V_76 = NULL ;
F_58 ( & V_3 -> V_59 ) ;
while ( V_102 && V_102 -> V_13 <
V_70 -> V_10 + V_14 ) {
V_146 = F_69 ( 0 , V_102 , V_70 -> V_65 ,
V_70 -> V_10 , V_146 ) ;
V_102 = F_2 ( V_102 , V_70 -> V_10 ) ;
}
}
}
F_37 ( & V_20 -> V_27 ) ;
F_70 ( & V_152 , V_163 , V_146 , F_73 , V_20 , NULL ) ;
F_75 ( & V_152 ) ;
}
static void F_76 ( struct V_19 * V_20 , int V_164 )
{
struct V_75 * V_165 ;
if ( V_164 < 0 )
return;
V_165 = & V_20 -> V_70 [ V_164 ] ;
F_63 ( V_166 , & V_165 -> V_58 ) ;
F_17 ( ! F_14 ( V_167 , & V_165 -> V_58 ) ) ;
F_21 ( V_167 , & V_165 -> V_58 ) ;
}
static void F_77 ( void * V_160 )
{
struct V_19 * V_20 = V_160 ;
F_30 ( L_12 , V_133 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_76 ( V_20 , V_20 -> V_168 . V_164 ) ;
F_76 ( V_20 , V_20 -> V_168 . V_169 ) ;
F_21 ( V_37 , & V_20 -> V_36 ) ;
if ( V_20 -> V_33 == V_170 )
V_20 -> V_33 = V_171 ;
F_63 ( V_40 , & V_20 -> V_36 ) ;
F_26 ( V_20 ) ;
}
static T_2 * F_78 ( struct V_19 * V_20 ,
struct V_172 * V_173 )
{
return V_173 -> V_174 + sizeof( struct V_65 * ) * ( V_20 -> V_23 + 2 ) ;
}
static struct V_144 *
F_79 ( struct V_19 * V_20 , struct V_172 * V_173 )
{
int V_23 = V_20 -> V_23 ;
struct V_65 * * V_175 = V_173 -> V_174 ;
int V_164 = V_20 -> V_168 . V_164 ;
struct V_75 * V_165 = & V_20 -> V_70 [ V_164 ] ;
struct V_65 * V_176 = V_165 -> V_65 ;
int V_27 = 0 ;
struct V_144 * V_146 ;
struct V_151 V_152 ;
int V_67 ;
F_30 ( L_13 ,
V_133 , ( unsigned long long ) V_20 -> V_10 , V_164 ) ;
F_17 ( ! F_14 ( V_167 , & V_165 -> V_58 ) ) ;
for ( V_67 = V_23 ; V_67 -- ; )
if ( V_67 != V_164 )
V_175 [ V_27 ++ ] = V_20 -> V_70 [ V_67 ] . V_65 ;
F_37 ( & V_20 -> V_27 ) ;
F_70 ( & V_152 , V_154 | V_177 , NULL ,
F_77 , V_20 , F_78 ( V_20 , V_173 ) ) ;
if ( F_80 ( V_27 == 1 ) )
V_146 = F_72 ( V_176 , V_175 [ 0 ] , 0 , 0 , V_140 , & V_152 ) ;
else
V_146 = F_81 ( V_176 , V_175 , 0 , V_27 , V_140 , & V_152 ) ;
return V_146 ;
}
static int F_82 ( struct V_65 * * V_178 , struct V_19 * V_20 )
{
int V_23 = V_20 -> V_23 ;
int V_28 = V_20 -> V_21 ? V_23 : ( V_23 - 2 ) ;
int V_179 = F_8 ( V_20 ) ;
int V_27 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_23 ; V_67 ++ )
V_178 [ V_67 ] = NULL ;
V_27 = 0 ;
V_67 = V_179 ;
do {
int V_29 = F_10 ( V_67 , V_20 , & V_27 , V_28 ) ;
V_178 [ V_29 ] = V_20 -> V_70 [ V_67 ] . V_65 ;
V_67 = F_9 ( V_67 , V_23 ) ;
} while ( V_67 != V_179 );
return V_28 ;
}
static struct V_144 *
F_83 ( struct V_19 * V_20 , struct V_172 * V_173 )
{
int V_23 = V_20 -> V_23 ;
struct V_65 * * V_180 = V_173 -> V_174 ;
int V_164 ;
int V_22 = V_20 -> V_22 ;
struct V_144 * V_146 ;
struct V_151 V_152 ;
struct V_75 * V_165 ;
struct V_65 * V_181 ;
int V_67 ;
int V_27 ;
if ( V_20 -> V_168 . V_164 < 0 )
V_164 = V_20 -> V_168 . V_169 ;
else if ( V_20 -> V_168 . V_169 < 0 )
V_164 = V_20 -> V_168 . V_164 ;
else
F_57 () ;
F_17 ( V_164 < 0 ) ;
F_30 ( L_13 ,
V_133 , ( unsigned long long ) V_20 -> V_10 , V_164 ) ;
V_165 = & V_20 -> V_70 [ V_164 ] ;
F_17 ( ! F_14 ( V_167 , & V_165 -> V_58 ) ) ;
V_181 = V_165 -> V_65 ;
F_37 ( & V_20 -> V_27 ) ;
if ( V_164 == V_22 ) {
V_27 = F_82 ( V_180 , V_20 ) ;
V_180 [ V_27 ] = NULL ;
F_17 ( V_180 [ V_27 + 1 ] != V_181 ) ;
F_70 ( & V_152 , V_154 , NULL ,
F_77 , V_20 ,
F_78 ( V_20 , V_173 ) ) ;
V_146 = F_84 ( V_180 , 0 , V_27 + 2 , V_140 , & V_152 ) ;
} else {
V_27 = 0 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
if ( V_67 == V_164 || V_67 == V_22 )
continue;
V_180 [ V_27 ++ ] = V_20 -> V_70 [ V_67 ] . V_65 ;
}
F_70 ( & V_152 , V_154 | V_177 ,
NULL , F_77 , V_20 ,
F_78 ( V_20 , V_173 ) ) ;
V_146 = F_81 ( V_181 , V_180 , 0 , V_27 , V_140 , & V_152 ) ;
}
return V_146 ;
}
static struct V_144 *
F_85 ( struct V_19 * V_20 , struct V_172 * V_173 )
{
int V_67 , V_27 , V_23 = V_20 -> V_23 ;
int V_28 = V_20 -> V_21 ? V_23 : V_23 - 2 ;
int V_179 = F_8 ( V_20 ) ;
int V_182 = - 1 , V_183 = - 1 ;
int V_164 = V_20 -> V_168 . V_164 ;
int V_169 = V_20 -> V_168 . V_169 ;
struct V_75 * V_165 = & V_20 -> V_70 [ V_164 ] ;
struct V_75 * V_184 = & V_20 -> V_70 [ V_169 ] ;
struct V_144 * V_146 ;
struct V_65 * * V_180 = V_173 -> V_174 ;
struct V_151 V_152 ;
F_30 ( L_14 ,
V_133 , ( unsigned long long ) V_20 -> V_10 , V_164 , V_169 ) ;
F_17 ( V_164 < 0 || V_169 < 0 ) ;
F_17 ( ! F_14 ( V_167 , & V_165 -> V_58 ) ) ;
F_17 ( ! F_14 ( V_167 , & V_184 -> V_58 ) ) ;
for ( V_67 = 0 ; V_67 < V_23 ; V_67 ++ )
V_180 [ V_67 ] = NULL ;
V_27 = 0 ;
V_67 = V_179 ;
do {
int V_29 = F_10 ( V_67 , V_20 , & V_27 , V_28 ) ;
V_180 [ V_29 ] = V_20 -> V_70 [ V_67 ] . V_65 ;
if ( V_67 == V_164 )
V_182 = V_29 ;
if ( V_67 == V_169 )
V_183 = V_29 ;
V_67 = F_9 ( V_67 , V_23 ) ;
} while ( V_67 != V_179 );
F_17 ( V_182 == V_183 ) ;
if ( V_183 < V_182 )
F_86 ( V_182 , V_183 ) ;
F_30 ( L_15 ,
V_133 , ( unsigned long long ) V_20 -> V_10 , V_182 , V_183 ) ;
F_37 ( & V_20 -> V_27 ) ;
if ( V_183 == V_28 + 1 ) {
if ( V_182 == V_28 ) {
F_70 ( & V_152 , V_154 , NULL ,
F_77 , V_20 ,
F_78 ( V_20 , V_173 ) ) ;
return F_84 ( V_180 , 0 , V_28 + 2 ,
V_140 , & V_152 ) ;
} else {
struct V_65 * V_181 ;
int V_185 ;
int V_22 = V_20 -> V_22 ;
if ( V_164 == V_22 )
V_185 = V_169 ;
else
V_185 = V_164 ;
V_27 = 0 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
if ( V_67 == V_185 || V_67 == V_22 )
continue;
V_180 [ V_27 ++ ] = V_20 -> V_70 [ V_67 ] . V_65 ;
}
V_181 = V_20 -> V_70 [ V_185 ] . V_65 ;
F_70 ( & V_152 ,
V_154 | V_177 ,
NULL , NULL , NULL ,
F_78 ( V_20 , V_173 ) ) ;
V_146 = F_81 ( V_181 , V_180 , 0 , V_27 , V_140 ,
& V_152 ) ;
V_27 = F_82 ( V_180 , V_20 ) ;
F_70 ( & V_152 , V_154 , V_146 ,
F_77 , V_20 ,
F_78 ( V_20 , V_173 ) ) ;
return F_84 ( V_180 , 0 , V_27 + 2 ,
V_140 , & V_152 ) ;
}
} else {
F_70 ( & V_152 , V_154 , NULL ,
F_77 , V_20 ,
F_78 ( V_20 , V_173 ) ) ;
if ( V_183 == V_28 ) {
return F_87 ( V_28 + 2 ,
V_140 , V_182 ,
V_180 , & V_152 ) ;
} else {
return F_88 ( V_28 + 2 ,
V_140 , V_182 , V_183 ,
V_180 , & V_152 ) ;
}
}
}
static void F_89 ( void * V_160 )
{
struct V_19 * V_20 = V_160 ;
F_30 ( L_12 , V_133 ,
( unsigned long long ) V_20 -> V_10 ) ;
}
static struct V_144 *
F_90 ( struct V_19 * V_20 , struct V_172 * V_173 ,
struct V_144 * V_146 )
{
int V_23 = V_20 -> V_23 ;
struct V_65 * * V_175 = V_173 -> V_174 ;
int V_27 = 0 , V_30 = V_20 -> V_30 , V_67 ;
struct V_151 V_152 ;
struct V_65 * V_176 = V_175 [ V_27 ++ ] = V_20 -> V_70 [ V_30 ] . V_65 ;
F_30 ( L_12 , V_133 ,
( unsigned long long ) V_20 -> V_10 ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( F_14 ( V_186 , & V_70 -> V_58 ) )
V_175 [ V_27 ++ ] = V_70 -> V_65 ;
}
F_70 ( & V_152 , V_154 | V_187 , V_146 ,
F_89 , V_20 , F_78 ( V_20 , V_173 ) ) ;
V_146 = F_81 ( V_176 , V_175 , 0 , V_27 , V_140 , & V_152 ) ;
return V_146 ;
}
static struct V_144 *
F_91 ( struct V_19 * V_20 , struct V_144 * V_146 )
{
int V_23 = V_20 -> V_23 ;
int V_67 ;
F_30 ( L_12 , V_133 ,
( unsigned long long ) V_20 -> V_10 ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
struct V_9 * V_188 ;
if ( F_23 ( V_186 , & V_70 -> V_58 ) ) {
struct V_9 * V_189 ;
F_55 ( & V_20 -> V_57 -> V_59 ) ;
V_188 = V_70 -> V_78 ;
V_70 -> V_78 = NULL ;
F_17 ( V_70 -> V_79 ) ;
V_189 = V_70 -> V_79 = V_188 ;
F_58 ( & V_20 -> V_57 -> V_59 ) ;
while ( V_189 && V_189 -> V_13 <
V_70 -> V_10 + V_14 ) {
if ( V_189 -> V_113 & V_190 )
F_63 ( V_105 , & V_70 -> V_58 ) ;
V_146 = F_69 ( 1 , V_189 , V_70 -> V_65 ,
V_70 -> V_10 , V_146 ) ;
V_189 = F_2 ( V_189 , V_70 -> V_10 ) ;
}
}
}
return V_146 ;
}
static void F_92 ( void * V_160 )
{
struct V_19 * V_20 = V_160 ;
int V_23 = V_20 -> V_23 ;
int V_30 = V_20 -> V_30 ;
int V_22 = V_20 -> V_22 ;
int V_67 ;
bool V_191 = false ;
F_30 ( L_12 , V_133 ,
( unsigned long long ) V_20 -> V_10 ) ;
for ( V_67 = V_23 ; V_67 -- ; )
V_191 |= F_14 ( V_105 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( V_70 -> V_79 || V_67 == V_30 || V_67 == V_22 ) {
F_63 ( V_166 , & V_70 -> V_58 ) ;
if ( V_191 )
F_63 ( V_105 , & V_70 -> V_58 ) ;
}
}
if ( V_20 -> V_34 == V_192 )
V_20 -> V_34 = V_193 ;
else if ( V_20 -> V_34 == V_194 )
V_20 -> V_34 = V_195 ;
else {
F_17 ( V_20 -> V_34 != V_196 ) ;
V_20 -> V_34 = V_197 ;
}
F_63 ( V_40 , & V_20 -> V_36 ) ;
F_26 ( V_20 ) ;
}
static void
F_93 ( struct V_19 * V_20 , struct V_172 * V_173 ,
struct V_144 * V_146 )
{
int V_23 = V_20 -> V_23 ;
struct V_65 * * V_175 = V_173 -> V_174 ;
struct V_151 V_152 ;
int V_27 = 0 , V_30 = V_20 -> V_30 , V_67 ;
struct V_65 * V_176 ;
int V_198 = 0 ;
unsigned long V_58 ;
F_30 ( L_12 , V_133 ,
( unsigned long long ) V_20 -> V_10 ) ;
if ( V_20 -> V_34 == V_194 ) {
V_198 = 1 ;
V_176 = V_175 [ V_27 ++ ] = V_20 -> V_70 [ V_30 ] . V_65 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( V_70 -> V_79 )
V_175 [ V_27 ++ ] = V_70 -> V_65 ;
}
} else {
V_176 = V_20 -> V_70 [ V_30 ] . V_65 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( V_67 != V_30 )
V_175 [ V_27 ++ ] = V_70 -> V_65 ;
}
}
V_58 = V_163 |
( V_198 ? V_187 : V_177 ) ;
F_37 ( & V_20 -> V_27 ) ;
F_70 ( & V_152 , V_58 , V_146 , F_92 , V_20 ,
F_78 ( V_20 , V_173 ) ) ;
if ( F_80 ( V_27 == 1 ) )
V_146 = F_72 ( V_176 , V_175 [ 0 ] , 0 , 0 , V_140 , & V_152 ) ;
else
V_146 = F_81 ( V_176 , V_175 , 0 , V_27 , V_140 , & V_152 ) ;
}
static void
F_94 ( struct V_19 * V_20 , struct V_172 * V_173 ,
struct V_144 * V_146 )
{
struct V_151 V_152 ;
struct V_65 * * V_180 = V_173 -> V_174 ;
int V_27 ;
F_30 ( L_12 , V_133 , ( unsigned long long ) V_20 -> V_10 ) ;
V_27 = F_82 ( V_180 , V_20 ) ;
F_37 ( & V_20 -> V_27 ) ;
F_70 ( & V_152 , V_163 , V_146 , F_92 ,
V_20 , F_78 ( V_20 , V_173 ) ) ;
F_84 ( V_180 , 0 , V_27 + 2 , V_140 , & V_152 ) ;
}
static void F_95 ( void * V_160 )
{
struct V_19 * V_20 = V_160 ;
F_30 ( L_12 , V_133 ,
( unsigned long long ) V_20 -> V_10 ) ;
V_20 -> V_33 = V_199 ;
F_63 ( V_40 , & V_20 -> V_36 ) ;
F_26 ( V_20 ) ;
}
static void F_96 ( struct V_19 * V_20 , struct V_172 * V_173 )
{
int V_23 = V_20 -> V_23 ;
int V_30 = V_20 -> V_30 ;
int V_22 = V_20 -> V_22 ;
struct V_65 * V_176 ;
struct V_65 * * V_175 = V_173 -> V_174 ;
struct V_144 * V_146 ;
struct V_151 V_152 ;
int V_27 ;
int V_67 ;
F_30 ( L_12 , V_133 ,
( unsigned long long ) V_20 -> V_10 ) ;
V_27 = 0 ;
V_176 = V_20 -> V_70 [ V_30 ] . V_65 ;
V_175 [ V_27 ++ ] = V_176 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
if ( V_67 == V_30 || V_67 == V_22 )
continue;
V_175 [ V_27 ++ ] = V_20 -> V_70 [ V_67 ] . V_65 ;
}
F_70 ( & V_152 , 0 , NULL , NULL , NULL ,
F_78 ( V_20 , V_173 ) ) ;
V_146 = F_97 ( V_176 , V_175 , 0 , V_27 , V_140 ,
& V_20 -> V_168 . V_200 , & V_152 ) ;
F_37 ( & V_20 -> V_27 ) ;
F_70 ( & V_152 , V_163 , V_146 , F_95 , V_20 , NULL ) ;
V_146 = F_75 ( & V_152 ) ;
}
static void F_98 ( struct V_19 * V_20 , struct V_172 * V_173 , int V_201 )
{
struct V_65 * * V_178 = V_173 -> V_174 ;
struct V_151 V_152 ;
int V_27 ;
F_30 ( L_16 , V_133 ,
( unsigned long long ) V_20 -> V_10 , V_201 ) ;
V_27 = F_82 ( V_178 , V_20 ) ;
if ( ! V_201 )
V_178 [ V_27 ] = NULL ;
F_37 ( & V_20 -> V_27 ) ;
F_70 ( & V_152 , V_163 , NULL , F_95 ,
V_20 , F_78 ( V_20 , V_173 ) ) ;
F_99 ( V_178 , 0 , V_27 + 2 , V_140 ,
& V_20 -> V_168 . V_200 , V_173 -> V_202 , & V_152 ) ;
}
static void F_100 ( struct V_19 * V_20 , unsigned long V_203 )
{
int V_204 = 0 , V_67 , V_23 = V_20 -> V_23 ;
struct V_144 * V_146 = NULL ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_205 = V_3 -> V_205 ;
struct V_172 * V_173 ;
unsigned long V_206 ;
V_206 = F_101 () ;
V_173 = F_102 ( V_3 -> V_173 , V_206 ) ;
if ( F_14 ( V_207 , & V_203 ) ) {
F_74 ( V_20 ) ;
V_204 ++ ;
}
if ( F_14 ( V_208 , & V_203 ) ) {
if ( V_205 < 6 )
V_146 = F_79 ( V_20 , V_173 ) ;
else {
if ( V_20 -> V_168 . V_169 < 0 || V_20 -> V_168 . V_164 < 0 )
V_146 = F_83 ( V_20 , V_173 ) ;
else
V_146 = F_85 ( V_20 , V_173 ) ;
}
if ( V_146 && ! F_14 ( V_209 , & V_203 ) )
F_103 ( V_146 ) ;
}
if ( F_14 ( V_210 , & V_203 ) )
V_146 = F_90 ( V_20 , V_173 , V_146 ) ;
if ( F_14 ( V_211 , & V_203 ) ) {
V_146 = F_91 ( V_20 , V_146 ) ;
V_204 ++ ;
}
if ( F_14 ( V_209 , & V_203 ) ) {
if ( V_205 < 6 )
F_93 ( V_20 , V_173 , V_146 ) ;
else
F_94 ( V_20 , V_173 , V_146 ) ;
}
if ( F_14 ( V_212 , & V_203 ) ) {
if ( V_20 -> V_33 == V_213 )
F_96 ( V_20 , V_173 ) ;
else if ( V_20 -> V_33 == V_214 )
F_98 ( V_20 , V_173 , 0 ) ;
else if ( V_20 -> V_33 == V_215 )
F_98 ( V_20 , V_173 , 1 ) ;
else
F_57 () ;
}
if ( V_204 )
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( F_23 ( V_216 , & V_70 -> V_58 ) )
F_25 ( & V_20 -> V_57 -> V_217 ) ;
}
F_104 () ;
}
static void F_105 ( void * V_218 , T_3 V_219 )
{
struct V_19 * V_20 = V_218 ;
unsigned long V_203 = V_20 -> V_168 . V_220 ;
F_106 ( V_221 , & V_20 -> V_36 ) ;
F_25 ( & V_20 -> V_168 . V_222 ) ;
F_100 ( V_20 , V_203 ) ;
F_26 ( V_20 ) ;
}
static void F_107 ( struct V_19 * V_20 , unsigned long V_203 )
{
F_108 ( V_20 -> V_168 . V_222 ,
! F_109 ( V_221 , & V_20 -> V_36 ) ) ;
V_20 -> V_168 . V_220 = V_203 ;
F_37 ( & V_20 -> V_27 ) ;
F_110 ( F_105 , V_20 ) ;
}
static int F_111 ( struct V_2 * V_3 )
{
struct V_19 * V_20 ;
V_20 = F_112 ( V_3 -> V_223 , V_71 ) ;
if ( ! V_20 )
return 0 ;
V_20 -> V_57 = V_3 ;
#ifdef F_113
F_114 ( & V_20 -> V_168 . V_222 ) ;
#endif
if ( F_40 ( V_20 ) ) {
F_38 ( V_20 ) ;
F_115 ( V_3 -> V_223 , V_20 ) ;
return 0 ;
}
F_116 ( & V_20 -> V_27 , 1 ) ;
F_37 ( & V_3 -> V_39 ) ;
F_117 ( & V_20 -> V_38 ) ;
F_26 ( V_20 ) ;
return 1 ;
}
static int F_118 ( struct V_2 * V_3 , int V_68 )
{
struct V_224 * V_225 ;
int V_226 = F_119 ( V_3 -> V_25 , V_3 -> V_74 ) ;
if ( V_3 -> V_48 -> V_227 )
sprintf ( V_3 -> V_228 [ 0 ] ,
L_17 , V_3 -> V_205 , F_120 ( V_3 -> V_48 ) ) ;
else
sprintf ( V_3 -> V_228 [ 0 ] ,
L_18 , V_3 -> V_205 , V_3 -> V_48 ) ;
sprintf ( V_3 -> V_228 [ 1 ] , L_19 , V_3 -> V_228 [ 0 ] ) ;
V_3 -> V_229 = 0 ;
V_225 = F_121 ( V_3 -> V_228 [ V_3 -> V_229 ] ,
sizeof( struct V_19 ) + ( V_226 - 1 ) * sizeof( struct V_75 ) ,
0 , 0 , NULL ) ;
if ( ! V_225 )
return 1 ;
V_3 -> V_223 = V_225 ;
V_3 -> V_69 = V_226 ;
while ( V_68 -- )
if ( ! F_111 ( V_3 ) )
return 1 ;
return 0 ;
}
static T_4 F_122 ( int V_68 )
{
T_4 V_155 ;
V_155 = sizeof( struct V_65 * ) * ( V_68 + 2 ) + sizeof( T_2 ) * ( V_68 + 2 ) ;
return V_155 ;
}
static int F_123 ( struct V_2 * V_3 , int V_230 )
{
struct V_19 * V_231 , * V_232 ;
F_124 ( V_233 ) ;
struct V_234 * V_235 ;
unsigned long V_206 ;
int V_236 ;
struct V_224 * V_225 ;
int V_67 ;
if ( V_230 <= V_3 -> V_69 )
return 0 ;
V_236 = F_125 ( V_3 -> V_48 ) ;
if ( V_236 )
return V_236 ;
V_225 = F_121 ( V_3 -> V_228 [ 1 - V_3 -> V_229 ] ,
sizeof( struct V_19 ) + ( V_230 - 1 ) * sizeof( struct V_75 ) ,
0 , 0 , NULL ) ;
if ( ! V_225 )
return - V_237 ;
for ( V_67 = V_3 -> V_97 ; V_67 ; V_67 -- ) {
V_232 = F_112 ( V_225 , V_71 ) ;
if ( ! V_232 )
break;
V_232 -> V_57 = V_3 ;
#ifdef F_113
F_114 ( & V_232 -> V_168 . V_222 ) ;
#endif
F_126 ( & V_232 -> V_38 , & V_233 ) ;
}
if ( V_67 ) {
while ( ! F_18 ( & V_233 ) ) {
V_232 = F_35 ( V_233 . V_64 , struct V_19 , V_38 ) ;
F_127 ( & V_232 -> V_38 ) ;
F_115 ( V_225 , V_232 ) ;
}
F_128 ( V_225 ) ;
return - V_237 ;
}
F_129 (nsh, &newstripes, lru) {
F_55 ( & V_3 -> V_59 ) ;
F_56 ( V_3 -> V_55 ,
! F_18 ( & V_3 -> V_54 ) ,
V_3 -> V_59 ,
) ;
V_231 = F_34 ( V_3 ) ;
F_58 ( & V_3 -> V_59 ) ;
F_116 ( & V_232 -> V_27 , 1 ) ;
for( V_67 = 0 ; V_67 < V_3 -> V_69 ; V_67 ++ )
V_232 -> V_70 [ V_67 ] . V_65 = V_231 -> V_70 [ V_67 ] . V_65 ;
for( ; V_67 < V_230 ; V_67 ++ )
V_232 -> V_70 [ V_67 ] . V_65 = NULL ;
F_115 ( V_3 -> V_223 , V_231 ) ;
}
F_128 ( V_3 -> V_223 ) ;
V_235 = F_130 ( V_230 * sizeof( struct V_234 ) , V_238 ) ;
if ( V_235 ) {
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ )
V_235 [ V_67 ] = V_3 -> V_23 [ V_67 ] ;
F_131 ( V_3 -> V_23 ) ;
V_3 -> V_23 = V_235 ;
} else
V_236 = - V_237 ;
F_132 () ;
V_3 -> F_122 = F_122 ( V_230 ) ;
F_133 (cpu) {
struct V_172 * V_173 ;
void * V_174 ;
V_173 = F_102 ( V_3 -> V_173 , V_206 ) ;
V_174 = F_134 ( V_3 -> F_122 , V_238 ) ;
if ( V_174 ) {
F_131 ( V_173 -> V_174 ) ;
V_173 -> V_174 = V_174 ;
} else {
V_236 = - V_237 ;
break;
}
}
F_135 () ;
while( ! F_18 ( & V_233 ) ) {
V_232 = F_35 ( V_233 . V_64 , struct V_19 , V_38 ) ;
F_36 ( & V_232 -> V_38 ) ;
for ( V_67 = V_3 -> V_25 ; V_67 < V_230 ; V_67 ++ )
if ( V_232 -> V_70 [ V_67 ] . V_65 == NULL ) {
struct V_65 * V_66 = F_41 ( V_238 ) ;
V_232 -> V_70 [ V_67 ] . V_65 = V_66 ;
if ( ! V_66 )
V_236 = - V_237 ;
}
F_26 ( V_232 ) ;
}
V_3 -> V_223 = V_225 ;
V_3 -> V_229 = 1 - V_3 -> V_229 ;
V_3 -> V_69 = V_230 ;
return V_236 ;
}
static int F_136 ( struct V_2 * V_3 )
{
struct V_19 * V_20 ;
F_55 ( & V_3 -> V_59 ) ;
V_20 = F_34 ( V_3 ) ;
F_58 ( & V_3 -> V_59 ) ;
if ( ! V_20 )
return 0 ;
F_17 ( F_19 ( & V_20 -> V_27 ) ) ;
F_38 ( V_20 ) ;
F_115 ( V_3 -> V_223 , V_20 ) ;
F_24 ( & V_3 -> V_39 ) ;
return 1 ;
}
static void F_137 ( struct V_2 * V_3 )
{
while ( F_136 ( V_3 ) )
;
if ( V_3 -> V_223 )
F_128 ( V_3 -> V_223 ) ;
V_3 -> V_223 = NULL ;
}
static void V_116 ( struct V_9 * V_32 , int error )
{
struct V_19 * V_20 = V_32 -> V_239 ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_23 = V_20 -> V_23 , V_67 ;
int V_240 = F_14 ( V_136 , & V_32 -> V_135 ) ;
char V_241 [ V_242 ] ;
struct V_86 * V_87 = NULL ;
for ( V_67 = 0 ; V_67 < V_23 ; V_67 ++ )
if ( V_32 == & V_20 -> V_70 [ V_67 ] . V_111 )
break;
F_30 ( L_20 ,
( unsigned long long ) V_20 -> V_10 , V_67 , F_19 ( & V_20 -> V_27 ) ,
V_240 ) ;
if ( V_67 == V_23 ) {
F_57 () ;
return;
}
if ( F_14 ( V_118 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
V_87 = V_3 -> V_23 [ V_67 ] . V_117 ;
if ( ! V_87 )
V_87 = V_3 -> V_23 [ V_67 ] . V_87 ;
if ( V_240 ) {
F_63 ( V_166 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
if ( F_14 ( V_243 , & V_20 -> V_70 [ V_67 ] . V_58 ) ) {
F_138 (
V_244
L_21
L_22 ,
F_120 ( V_3 -> V_48 ) , V_14 ,
( unsigned long long ) ( V_20 -> V_10
+ V_87 -> V_134 ) ,
F_139 ( V_87 -> V_130 , V_241 ) ) ;
F_140 ( V_14 , & V_87 -> V_245 ) ;
F_21 ( V_243 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_21 ( V_246 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
}
if ( F_19 ( & V_87 -> V_247 ) )
F_116 ( & V_87 -> V_247 , 0 ) ;
} else {
const char * V_248 = F_139 ( V_87 -> V_130 , V_241 ) ;
int V_249 = 0 ;
F_21 ( V_166 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_37 ( & V_87 -> V_247 ) ;
if ( F_14 ( V_118 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
F_138 (
V_250
L_23
L_24 ,
F_120 ( V_3 -> V_48 ) ,
( unsigned long long ) ( V_20 -> V_10
+ V_87 -> V_134 ) ,
V_248 ) ;
else if ( V_3 -> V_48 -> V_84 >= V_3 -> V_92 )
F_138 (
V_250
L_25
L_24 ,
F_120 ( V_3 -> V_48 ) ,
( unsigned long long ) ( V_20 -> V_10
+ V_87 -> V_134 ) ,
V_248 ) ;
else if ( F_14 ( V_246 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
F_138 (
V_250
L_26
L_24 ,
F_120 ( V_3 -> V_48 ) ,
( unsigned long long ) ( V_20 -> V_10
+ V_87 -> V_134 ) ,
V_248 ) ;
else if ( F_19 ( & V_87 -> V_247 )
> V_3 -> V_97 )
F_44 ( V_250
L_27 ,
F_120 ( V_3 -> V_48 ) , V_248 ) ;
else
V_249 = 1 ;
if ( V_249 )
F_63 ( V_243 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
else {
F_21 ( V_243 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_21 ( V_246 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_141 ( V_3 -> V_48 , V_87 ) ;
}
}
F_66 ( V_87 , V_3 -> V_48 ) ;
F_21 ( V_80 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_63 ( V_40 , & V_20 -> V_36 ) ;
F_26 ( V_20 ) ;
}
static void V_115 ( struct V_9 * V_32 , int error )
{
struct V_19 * V_20 = V_32 -> V_239 ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_23 = V_20 -> V_23 , V_67 ;
struct V_86 * V_251 ( V_87 ) ;
int V_240 = F_14 ( V_136 , & V_32 -> V_135 ) ;
T_1 V_121 ;
int V_122 ;
int V_117 = 0 ;
for ( V_67 = 0 ; V_67 < V_23 ; V_67 ++ ) {
if ( V_32 == & V_20 -> V_70 [ V_67 ] . V_111 ) {
V_87 = V_3 -> V_23 [ V_67 ] . V_87 ;
break;
}
if ( V_32 == & V_20 -> V_70 [ V_67 ] . V_112 ) {
V_87 = V_3 -> V_23 [ V_67 ] . V_117 ;
if ( V_87 )
V_117 = 1 ;
else
V_87 = V_3 -> V_23 [ V_67 ] . V_87 ;
break;
}
}
F_30 ( L_28 ,
( unsigned long long ) V_20 -> V_10 , V_67 , F_19 ( & V_20 -> V_27 ) ,
V_240 ) ;
if ( V_67 == V_23 ) {
F_57 () ;
return;
}
if ( V_117 ) {
if ( ! V_240 )
F_141 ( V_3 -> V_48 , V_87 ) ;
else if ( F_62 ( V_87 , V_20 -> V_10 ,
V_14 ,
& V_121 , & V_122 ) )
F_63 ( V_252 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
} else {
if ( ! V_240 ) {
F_63 ( V_120 , & V_87 -> V_58 ) ;
F_63 ( V_253 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
if ( ! F_142 ( V_254 , & V_87 -> V_58 ) )
F_63 ( V_255 ,
& V_87 -> V_48 -> V_256 ) ;
} else if ( F_62 ( V_87 , V_20 -> V_10 ,
V_14 ,
& V_121 , & V_122 ) )
F_63 ( V_257 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
}
F_66 ( V_87 , V_3 -> V_48 ) ;
if ( ! F_23 ( V_142 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
F_21 ( V_80 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_63 ( V_40 , & V_20 -> V_36 ) ;
F_26 ( V_20 ) ;
}
static void F_46 ( struct V_19 * V_20 , int V_67 , int V_72 )
{
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
F_143 ( & V_70 -> V_111 ) ;
V_70 -> V_111 . V_138 = & V_70 -> V_258 ;
V_70 -> V_111 . V_259 ++ ;
V_70 -> V_111 . V_260 ++ ;
V_70 -> V_111 . V_239 = V_20 ;
V_70 -> V_258 . V_158 = V_70 -> V_65 ;
F_143 ( & V_70 -> V_112 ) ;
V_70 -> V_112 . V_138 = & V_70 -> V_261 ;
V_70 -> V_112 . V_259 ++ ;
V_70 -> V_112 . V_260 ++ ;
V_70 -> V_112 . V_239 = V_20 ;
V_70 -> V_261 . V_158 = V_70 -> V_65 ;
V_70 -> V_58 = 0 ;
V_70 -> V_10 = F_144 ( V_20 , V_67 , V_72 ) ;
}
static void error ( struct V_48 * V_48 , struct V_86 * V_87 )
{
char V_241 [ V_242 ] ;
struct V_2 * V_3 = V_48 -> V_262 ;
unsigned long V_58 ;
F_30 ( L_29 ) ;
F_27 ( & V_3 -> V_59 , V_58 ) ;
F_21 ( V_89 , & V_87 -> V_58 ) ;
V_48 -> V_84 = F_49 ( V_3 ) ;
F_28 ( & V_3 -> V_59 , V_58 ) ;
F_63 ( V_263 , & V_48 -> V_256 ) ;
F_63 ( V_264 , & V_87 -> V_58 ) ;
F_63 ( V_88 , & V_87 -> V_58 ) ;
F_63 ( V_265 , & V_48 -> V_58 ) ;
F_44 ( V_266
L_30
L_31 ,
F_120 ( V_48 ) ,
F_139 ( V_87 -> V_130 , V_241 ) ,
F_120 ( V_48 ) ,
V_3 -> V_25 - V_48 -> V_84 ) ;
}
static T_1 F_145 ( struct V_2 * V_3 , T_1 V_267 ,
int V_72 , int * V_268 ,
struct V_19 * V_20 )
{
T_1 V_269 , V_270 ;
T_1 V_271 ;
unsigned int V_272 ;
int V_30 , V_22 ;
int V_21 = 0 ;
T_1 V_273 ;
int V_274 = V_72 ? V_3 -> V_275
: V_3 -> V_274 ;
int V_276 = V_72 ? V_3 -> V_277
: V_3 -> V_278 ;
int V_25 = V_72 ? V_3 -> V_74
: V_3 -> V_25 ;
int V_279 = V_25 - V_3 -> V_92 ;
V_272 = F_146 ( V_267 , V_276 ) ;
V_271 = V_267 ;
V_269 = V_271 ;
* V_268 = F_146 ( V_269 , V_279 ) ;
V_270 = V_269 ;
V_30 = V_22 = - 1 ;
switch( V_3 -> V_205 ) {
case 4 :
V_30 = V_279 ;
break;
case 5 :
switch ( V_274 ) {
case V_280 :
V_30 = V_279 - F_146 ( V_270 , V_25 ) ;
if ( * V_268 >= V_30 )
( * V_268 ) ++ ;
break;
case V_281 :
V_30 = F_146 ( V_270 , V_25 ) ;
if ( * V_268 >= V_30 )
( * V_268 ) ++ ;
break;
case V_282 :
V_30 = V_279 - F_146 ( V_270 , V_25 ) ;
* V_268 = ( V_30 + 1 + * V_268 ) % V_25 ;
break;
case V_283 :
V_30 = F_146 ( V_270 , V_25 ) ;
* V_268 = ( V_30 + 1 + * V_268 ) % V_25 ;
break;
case V_284 :
V_30 = 0 ;
( * V_268 ) ++ ;
break;
case V_285 :
V_30 = V_279 ;
break;
default:
F_57 () ;
}
break;
case 6 :
switch ( V_274 ) {
case V_280 :
V_30 = V_25 - 1 - F_146 ( V_270 , V_25 ) ;
V_22 = V_30 + 1 ;
if ( V_30 == V_25 - 1 ) {
( * V_268 ) ++ ;
V_22 = 0 ;
} else if ( * V_268 >= V_30 )
( * V_268 ) += 2 ;
break;
case V_281 :
V_30 = F_146 ( V_270 , V_25 ) ;
V_22 = V_30 + 1 ;
if ( V_30 == V_25 - 1 ) {
( * V_268 ) ++ ;
V_22 = 0 ;
} else if ( * V_268 >= V_30 )
( * V_268 ) += 2 ;
break;
case V_282 :
V_30 = V_25 - 1 - F_146 ( V_270 , V_25 ) ;
V_22 = ( V_30 + 1 ) % V_25 ;
* V_268 = ( V_30 + 2 + * V_268 ) % V_25 ;
break;
case V_283 :
V_30 = F_146 ( V_270 , V_25 ) ;
V_22 = ( V_30 + 1 ) % V_25 ;
* V_268 = ( V_30 + 2 + * V_268 ) % V_25 ;
break;
case V_284 :
V_30 = 0 ;
V_22 = 1 ;
( * V_268 ) += 2 ;
break;
case V_285 :
V_30 = V_279 ;
V_22 = V_279 + 1 ;
break;
case V_286 :
V_30 = F_146 ( V_270 , V_25 ) ;
V_22 = V_30 + 1 ;
if ( V_30 == V_25 - 1 ) {
( * V_268 ) ++ ;
V_22 = 0 ;
} else if ( * V_268 >= V_30 )
( * V_268 ) += 2 ;
V_21 = 1 ;
break;
case V_287 :
V_270 += 1 ;
V_30 = V_25 - 1 - F_146 ( V_270 , V_25 ) ;
V_22 = V_30 + 1 ;
if ( V_30 == V_25 - 1 ) {
( * V_268 ) ++ ;
V_22 = 0 ;
} else if ( * V_268 >= V_30 )
( * V_268 ) += 2 ;
V_21 = 1 ;
break;
case V_288 :
V_30 = V_25 - 1 - F_146 ( V_270 , V_25 ) ;
V_22 = ( V_30 + V_25 - 1 ) % V_25 ;
* V_268 = ( V_30 + 1 + * V_268 ) % V_25 ;
V_21 = 1 ;
break;
case V_289 :
V_30 = V_279 - F_146 ( V_270 , V_25 - 1 ) ;
if ( * V_268 >= V_30 )
( * V_268 ) ++ ;
V_22 = V_25 - 1 ;
break;
case V_290 :
V_30 = F_146 ( V_270 , V_25 - 1 ) ;
if ( * V_268 >= V_30 )
( * V_268 ) ++ ;
V_22 = V_25 - 1 ;
break;
case V_291 :
V_30 = V_279 - F_146 ( V_270 , V_25 - 1 ) ;
* V_268 = ( V_30 + 1 + * V_268 ) % ( V_25 - 1 ) ;
V_22 = V_25 - 1 ;
break;
case V_292 :
V_30 = F_146 ( V_270 , V_25 - 1 ) ;
* V_268 = ( V_30 + 1 + * V_268 ) % ( V_25 - 1 ) ;
V_22 = V_25 - 1 ;
break;
case V_293 :
V_30 = 0 ;
( * V_268 ) ++ ;
V_22 = V_25 - 1 ;
break;
default:
F_57 () ;
}
break;
}
if ( V_20 ) {
V_20 -> V_30 = V_30 ;
V_20 -> V_22 = V_22 ;
V_20 -> V_21 = V_21 ;
}
V_273 = ( T_1 ) V_269 * V_276 + V_272 ;
return V_273 ;
}
static T_1 F_144 ( struct V_19 * V_20 , int V_67 , int V_72 )
{
struct V_2 * V_3 = V_20 -> V_57 ;
int V_25 = V_20 -> V_23 ;
int V_279 = V_25 - V_3 -> V_92 ;
T_1 V_273 = V_20 -> V_10 , V_294 ;
int V_276 = V_72 ? V_3 -> V_277
: V_3 -> V_278 ;
int V_274 = V_72 ? V_3 -> V_275
: V_3 -> V_274 ;
T_1 V_269 ;
int V_272 ;
T_1 V_271 ;
int V_295 , V_268 = V_67 ;
T_1 V_267 ;
struct V_19 V_296 ;
V_272 = F_146 ( V_273 , V_276 ) ;
V_269 = V_273 ;
if ( V_67 == V_20 -> V_30 )
return 0 ;
switch( V_3 -> V_205 ) {
case 4 : break;
case 5 :
switch ( V_274 ) {
case V_280 :
case V_281 :
if ( V_67 > V_20 -> V_30 )
V_67 -- ;
break;
case V_282 :
case V_283 :
if ( V_67 < V_20 -> V_30 )
V_67 += V_25 ;
V_67 -= ( V_20 -> V_30 + 1 ) ;
break;
case V_284 :
V_67 -= 1 ;
break;
case V_285 :
break;
default:
F_57 () ;
}
break;
case 6 :
if ( V_67 == V_20 -> V_22 )
return 0 ;
switch ( V_274 ) {
case V_280 :
case V_281 :
case V_286 :
case V_287 :
if ( V_20 -> V_30 == V_25 - 1 )
V_67 -- ;
else if ( V_67 > V_20 -> V_30 )
V_67 -= 2 ;
break;
case V_282 :
case V_283 :
if ( V_20 -> V_30 == V_25 - 1 )
V_67 -- ;
else {
if ( V_67 < V_20 -> V_30 )
V_67 += V_25 ;
V_67 -= ( V_20 -> V_30 + 2 ) ;
}
break;
case V_284 :
V_67 -= 2 ;
break;
case V_285 :
break;
case V_288 :
if ( V_20 -> V_30 == 0 )
V_67 -- ;
else {
if ( V_67 < V_20 -> V_30 )
V_67 += V_25 ;
V_67 -= ( V_20 -> V_30 + 1 ) ;
}
break;
case V_289 :
case V_290 :
if ( V_67 > V_20 -> V_30 )
V_67 -- ;
break;
case V_291 :
case V_292 :
if ( V_67 < V_20 -> V_30 )
V_67 += V_279 + 1 ;
V_67 -= ( V_20 -> V_30 + 1 ) ;
break;
case V_293 :
V_67 -= 1 ;
break;
default:
F_57 () ;
}
break;
}
V_271 = V_269 * V_279 + V_67 ;
V_267 = V_271 * V_276 + V_272 ;
V_294 = F_145 ( V_3 , V_267 ,
V_72 , & V_295 , & V_296 ) ;
if ( V_294 != V_20 -> V_10 || V_295 != V_268 || V_296 . V_30 != V_20 -> V_30
|| V_296 . V_22 != V_20 -> V_22 ) {
F_44 ( V_81 L_32 ,
F_120 ( V_3 -> V_48 ) ) ;
return 0 ;
}
return V_267 ;
}
static void
F_147 ( struct V_19 * V_20 , struct V_98 * V_99 ,
int V_297 , int V_298 )
{
int V_67 , V_30 = V_20 -> V_30 , V_23 = V_20 -> V_23 ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_205 = V_3 -> V_205 ;
if ( V_297 ) {
if ( ! V_298 ) {
V_20 -> V_34 = V_192 ;
F_63 ( V_211 , & V_99 -> V_203 ) ;
} else
V_20 -> V_34 = V_196 ;
F_63 ( V_209 , & V_99 -> V_203 ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( V_70 -> V_78 ) {
F_63 ( V_80 , & V_70 -> V_58 ) ;
F_63 ( V_186 , & V_70 -> V_58 ) ;
if ( ! V_298 )
F_21 ( V_166 , & V_70 -> V_58 ) ;
V_99 -> V_299 ++ ;
}
}
if ( V_99 -> V_299 + V_3 -> V_92 == V_23 )
if ( ! F_142 ( V_300 , & V_20 -> V_36 ) )
F_37 ( & V_3 -> V_301 ) ;
} else {
F_17 ( V_205 == 6 ) ;
F_17 ( ! ( F_14 ( V_166 , & V_20 -> V_70 [ V_30 ] . V_58 ) ||
F_14 ( V_167 , & V_20 -> V_70 [ V_30 ] . V_58 ) ) ) ;
V_20 -> V_34 = V_194 ;
F_63 ( V_210 , & V_99 -> V_203 ) ;
F_63 ( V_211 , & V_99 -> V_203 ) ;
F_63 ( V_209 , & V_99 -> V_203 ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( V_67 == V_30 )
continue;
if ( V_70 -> V_78 &&
( F_14 ( V_166 , & V_70 -> V_58 ) ||
F_14 ( V_167 , & V_70 -> V_58 ) ) ) {
F_63 ( V_186 , & V_70 -> V_58 ) ;
F_63 ( V_80 , & V_70 -> V_58 ) ;
F_21 ( V_166 , & V_70 -> V_58 ) ;
V_99 -> V_299 ++ ;
}
}
}
F_63 ( V_80 , & V_20 -> V_70 [ V_30 ] . V_58 ) ;
F_21 ( V_166 , & V_20 -> V_70 [ V_30 ] . V_58 ) ;
V_99 -> V_299 ++ ;
if ( V_205 == 6 ) {
int V_22 = V_20 -> V_22 ;
struct V_75 * V_70 = & V_20 -> V_70 [ V_22 ] ;
F_63 ( V_80 , & V_70 -> V_58 ) ;
F_21 ( V_166 , & V_70 -> V_58 ) ;
V_99 -> V_299 ++ ;
}
F_30 ( L_33 ,
V_133 , ( unsigned long long ) V_20 -> V_10 ,
V_99 -> V_299 , V_99 -> V_203 ) ;
}
static int F_148 ( struct V_19 * V_20 , struct V_9 * V_32 , int V_268 , int V_302 )
{
struct V_9 * * V_303 ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_304 = 0 ;
F_30 ( L_34 ,
( unsigned long long ) V_32 -> V_13 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_55 ( & V_3 -> V_59 ) ;
if ( V_302 ) {
V_303 = & V_20 -> V_70 [ V_268 ] . V_78 ;
if ( * V_303 == NULL && V_20 -> V_70 [ V_268 ] . V_79 == NULL )
V_304 = 1 ;
} else
V_303 = & V_20 -> V_70 [ V_268 ] . V_76 ;
while ( * V_303 && ( * V_303 ) -> V_13 < V_32 -> V_13 ) {
if ( ( * V_303 ) -> V_13 + ( ( * V_303 ) -> V_12 >> 9 ) > V_32 -> V_13 )
goto V_305;
V_303 = & ( * V_303 ) -> V_15 ;
}
if ( * V_303 && ( * V_303 ) -> V_13 < V_32 -> V_13 + ( ( V_32 -> V_12 ) >> 9 ) )
goto V_305;
F_17 ( * V_303 && V_32 -> V_15 && ( * V_303 ) != V_32 -> V_15 ) ;
if ( * V_303 )
V_32 -> V_15 = * V_303 ;
* V_303 = V_32 ;
V_32 -> V_16 ++ ;
if ( V_302 ) {
T_1 V_10 = V_20 -> V_70 [ V_268 ] . V_10 ;
for ( V_32 = V_20 -> V_70 [ V_268 ] . V_78 ;
V_10 < V_20 -> V_70 [ V_268 ] . V_10 + V_14 &&
V_32 && V_32 -> V_13 <= V_10 ;
V_32 = F_2 ( V_32 , V_20 -> V_70 [ V_268 ] . V_10 ) ) {
if ( V_32 -> V_13 + ( V_32 -> V_12 >> 9 ) >= V_10 )
V_10 = V_32 -> V_13 + ( V_32 -> V_12 >> 9 ) ;
}
if ( V_10 >= V_20 -> V_70 [ V_268 ] . V_10 + V_14 )
F_63 ( V_306 , & V_20 -> V_70 [ V_268 ] . V_58 ) ;
}
F_58 ( & V_3 -> V_59 ) ;
F_30 ( L_35 ,
( unsigned long long ) ( * V_303 ) -> V_13 ,
( unsigned long long ) V_20 -> V_10 , V_268 ) ;
if ( V_3 -> V_48 -> V_307 && V_304 ) {
F_149 ( V_3 -> V_48 -> V_307 , V_20 -> V_10 ,
V_14 , 0 ) ;
V_20 -> V_44 = V_3 -> V_308 + 1 ;
F_63 ( V_43 , & V_20 -> V_36 ) ;
}
return 1 ;
V_305:
F_63 ( V_216 , & V_20 -> V_70 [ V_268 ] . V_58 ) ;
F_58 ( & V_3 -> V_59 ) ;
return 0 ;
}
static void F_43 ( T_1 V_269 , struct V_2 * V_3 , int V_72 ,
struct V_19 * V_20 )
{
int V_276 =
V_72 ? V_3 -> V_277 : V_3 -> V_278 ;
int V_268 ;
int V_272 = F_146 ( V_269 , V_276 ) ;
int V_23 = V_72 ? V_3 -> V_74 : V_3 -> V_25 ;
F_145 ( V_3 ,
V_269 * ( V_23 - V_3 -> V_92 )
* V_276 + V_272 ,
V_72 ,
& V_268 , V_20 ) ;
}
static void
F_150 ( struct V_2 * V_3 , struct V_19 * V_20 ,
struct V_98 * V_99 , int V_23 ,
struct V_9 * * V_31 )
{
int V_67 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_9 * V_32 ;
int V_309 = 0 ;
if ( F_14 ( V_243 , & V_20 -> V_70 [ V_67 ] . V_58 ) ) {
struct V_86 * V_87 ;
F_50 () ;
V_87 = F_51 ( V_3 -> V_23 [ V_67 ] . V_87 ) ;
if ( V_87 && F_14 ( V_89 , & V_87 -> V_58 ) )
F_37 ( & V_87 -> V_119 ) ;
else
V_87 = NULL ;
F_52 () ;
if ( V_87 ) {
if ( ! F_151 (
V_87 ,
V_20 -> V_10 ,
V_14 , 0 ) )
F_141 ( V_3 -> V_48 , V_87 ) ;
F_66 ( V_87 , V_3 -> V_48 ) ;
}
}
F_55 ( & V_3 -> V_59 ) ;
V_32 = V_20 -> V_70 [ V_67 ] . V_78 ;
V_20 -> V_70 [ V_67 ] . V_78 = NULL ;
if ( V_32 ) {
V_99 -> V_310 -- ;
V_309 = 1 ;
}
if ( F_23 ( V_216 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
F_25 ( & V_3 -> V_217 ) ;
while ( V_32 && V_32 -> V_13 <
V_20 -> V_70 [ V_67 ] . V_10 + V_14 ) {
struct V_9 * V_311 = F_2 ( V_32 , V_20 -> V_70 [ V_67 ] . V_10 ) ;
F_21 ( V_136 , & V_32 -> V_135 ) ;
if ( ! F_5 ( V_32 ) ) {
F_152 ( V_3 -> V_48 ) ;
V_32 -> V_15 = * V_31 ;
* V_31 = V_32 ;
}
V_32 = V_311 ;
}
V_32 = V_20 -> V_70 [ V_67 ] . V_79 ;
V_20 -> V_70 [ V_67 ] . V_79 = NULL ;
if ( V_32 ) V_309 = 1 ;
while ( V_32 && V_32 -> V_13 <
V_20 -> V_70 [ V_67 ] . V_10 + V_14 ) {
struct V_9 * V_312 = F_2 ( V_32 , V_20 -> V_70 [ V_67 ] . V_10 ) ;
F_21 ( V_136 , & V_32 -> V_135 ) ;
if ( ! F_5 ( V_32 ) ) {
F_152 ( V_3 -> V_48 ) ;
V_32 -> V_15 = * V_31 ;
* V_31 = V_32 ;
}
V_32 = V_312 ;
}
if ( ! F_14 ( V_161 , & V_20 -> V_70 [ V_67 ] . V_58 ) &&
( ! F_14 ( V_313 , & V_20 -> V_70 [ V_67 ] . V_58 ) ||
F_14 ( V_243 , & V_20 -> V_70 [ V_67 ] . V_58 ) ) ) {
V_32 = V_20 -> V_70 [ V_67 ] . V_76 ;
V_20 -> V_70 [ V_67 ] . V_76 = NULL ;
if ( F_23 ( V_216 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
F_25 ( & V_3 -> V_217 ) ;
if ( V_32 ) V_99 -> V_314 -- ;
while ( V_32 && V_32 -> V_13 <
V_20 -> V_70 [ V_67 ] . V_10 + V_14 ) {
struct V_9 * V_311 =
F_2 ( V_32 , V_20 -> V_70 [ V_67 ] . V_10 ) ;
F_21 ( V_136 , & V_32 -> V_135 ) ;
if ( ! F_5 ( V_32 ) ) {
V_32 -> V_15 = * V_31 ;
* V_31 = V_32 ;
}
V_32 = V_311 ;
}
}
F_58 ( & V_3 -> V_59 ) ;
if ( V_309 )
F_153 ( V_3 -> V_48 -> V_307 , V_20 -> V_10 ,
V_14 , 0 , 0 ) ;
F_21 ( V_80 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
}
if ( F_23 ( V_300 , & V_20 -> V_36 ) )
if ( F_16 ( & V_3 -> V_301 ) )
F_22 ( V_3 -> V_48 -> V_49 ) ;
}
static void
F_154 ( struct V_2 * V_3 , struct V_19 * V_20 ,
struct V_98 * V_99 )
{
int abort = 0 ;
int V_67 ;
F_155 ( V_3 -> V_48 , V_14 , 0 ) ;
F_21 ( V_315 , & V_20 -> V_36 ) ;
V_99 -> V_126 = 0 ;
V_99 -> V_129 = 0 ;
if ( ! F_14 ( V_316 , & V_3 -> V_48 -> V_256 ) )
return;
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ ) {
struct V_86 * V_87 = V_3 -> V_23 [ V_67 ] . V_87 ;
if ( V_87
&& ! F_14 ( V_88 , & V_87 -> V_58 )
&& ! F_14 ( V_89 , & V_87 -> V_58 )
&& ! F_151 ( V_87 , V_20 -> V_10 ,
V_14 , 0 ) )
abort = 1 ;
V_87 = V_3 -> V_23 [ V_67 ] . V_117 ;
if ( V_87
&& ! F_14 ( V_88 , & V_87 -> V_58 )
&& ! F_14 ( V_89 , & V_87 -> V_58 )
&& ! F_151 ( V_87 , V_20 -> V_10 ,
V_14 , 0 ) )
abort = 1 ;
}
if ( abort ) {
V_3 -> V_317 = V_3 -> V_48 -> V_317 ;
F_63 ( V_263 , & V_3 -> V_48 -> V_256 ) ;
}
}
static int F_156 ( struct V_19 * V_20 , int V_318 )
{
struct V_86 * V_87 ;
int V_319 = 0 ;
V_87 = V_20 -> V_57 -> V_23 [ V_318 ] . V_117 ;
if ( V_87
&& ! F_14 ( V_88 , & V_87 -> V_58 )
&& ! F_14 ( V_89 , & V_87 -> V_58 )
&& ( V_87 -> V_320 <= V_20 -> V_10
|| V_87 -> V_48 -> V_321 <= V_20 -> V_10 ) )
V_319 = 1 ;
return V_319 ;
}
static int F_157 ( struct V_19 * V_20 , struct V_98 * V_99 ,
int V_318 , int V_23 )
{
struct V_75 * V_70 = & V_20 -> V_70 [ V_318 ] ;
struct V_75 * V_322 [ 2 ] = { & V_20 -> V_70 [ V_99 -> V_323 [ 0 ] ] ,
& V_20 -> V_70 [ V_99 -> V_323 [ 1 ] ] } ;
if ( ! F_14 ( V_80 , & V_70 -> V_58 ) &&
! F_14 ( V_166 , & V_70 -> V_58 ) &&
( V_70 -> V_76 ||
( V_70 -> V_78 && ! F_14 ( V_306 , & V_70 -> V_58 ) ) ||
V_99 -> V_126 || V_99 -> V_127 ||
( V_99 -> V_129 && F_156 ( V_20 , V_318 ) ) ||
( V_99 -> V_324 >= 1 && V_322 [ 0 ] -> V_76 ) ||
( V_99 -> V_324 >= 2 && V_322 [ 1 ] -> V_76 ) ||
( V_20 -> V_57 -> V_205 <= 5 && V_99 -> V_324 && V_322 [ 0 ] -> V_78 &&
! F_14 ( V_306 , & V_322 [ 0 ] -> V_58 ) ) ||
( V_20 -> V_57 -> V_205 == 6 && V_99 -> V_324 && V_99 -> V_310 ) ) ) {
F_17 ( F_14 ( V_167 , & V_70 -> V_58 ) ) ;
F_17 ( F_14 ( V_108 , & V_70 -> V_58 ) ) ;
if ( ( V_99 -> V_240 == V_23 - 1 ) &&
( V_99 -> V_324 && ( V_318 == V_99 -> V_323 [ 0 ] ||
V_318 == V_99 -> V_323 [ 1 ] ) ) ) {
F_30 ( L_36 ,
( unsigned long long ) V_20 -> V_10 , V_318 ) ;
F_63 ( V_37 , & V_20 -> V_36 ) ;
F_63 ( V_208 , & V_99 -> V_203 ) ;
F_63 ( V_167 , & V_70 -> V_58 ) ;
V_20 -> V_168 . V_164 = V_318 ;
V_20 -> V_168 . V_169 = - 1 ;
V_99 -> V_325 = 1 ;
V_99 -> V_240 ++ ;
return 1 ;
} else if ( V_99 -> V_240 == V_23 - 2 && V_99 -> V_324 >= 2 ) {
int V_326 ;
for ( V_326 = V_23 ; V_326 -- ; ) {
if ( V_326 == V_318 )
continue;
if ( ! F_14 ( V_166 ,
& V_20 -> V_70 [ V_326 ] . V_58 ) )
break;
}
F_17 ( V_326 < 0 ) ;
F_30 ( L_37 ,
( unsigned long long ) V_20 -> V_10 ,
V_318 , V_326 ) ;
F_63 ( V_37 , & V_20 -> V_36 ) ;
F_63 ( V_208 , & V_99 -> V_203 ) ;
F_63 ( V_167 , & V_20 -> V_70 [ V_318 ] . V_58 ) ;
F_63 ( V_167 , & V_20 -> V_70 [ V_326 ] . V_58 ) ;
V_20 -> V_168 . V_164 = V_318 ;
V_20 -> V_168 . V_169 = V_326 ;
V_99 -> V_240 += 2 ;
V_99 -> V_325 = 1 ;
return 1 ;
} else if ( F_14 ( V_313 , & V_70 -> V_58 ) ) {
F_63 ( V_80 , & V_70 -> V_58 ) ;
F_63 ( V_108 , & V_70 -> V_58 ) ;
V_99 -> V_299 ++ ;
F_30 ( L_38 ,
V_318 , V_99 -> V_126 ) ;
}
}
return 0 ;
}
static void F_158 ( struct V_19 * V_20 ,
struct V_98 * V_99 ,
int V_23 )
{
int V_67 ;
if ( ! F_14 ( V_37 , & V_20 -> V_36 ) && ! V_20 -> V_33 &&
! V_20 -> V_34 )
for ( V_67 = V_23 ; V_67 -- ; )
if ( F_157 ( V_20 , V_99 , V_67 , V_23 ) )
break;
F_63 ( V_40 , & V_20 -> V_36 ) ;
}
static void F_159 ( struct V_2 * V_3 ,
struct V_19 * V_20 , int V_23 , struct V_9 * * V_31 )
{
int V_67 ;
struct V_75 * V_70 ;
for ( V_67 = V_23 ; V_67 -- ; )
if ( V_20 -> V_70 [ V_67 ] . V_79 ) {
V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( ! F_14 ( V_80 , & V_70 -> V_58 ) &&
F_14 ( V_166 , & V_70 -> V_58 ) ) {
struct V_9 * V_189 , * V_327 ;
int V_309 = 0 ;
F_30 ( L_39 , V_67 ) ;
F_55 ( & V_3 -> V_59 ) ;
V_189 = V_70 -> V_79 ;
V_70 -> V_79 = NULL ;
while ( V_189 && V_189 -> V_13 <
V_70 -> V_10 + V_14 ) {
V_327 = F_2 ( V_189 , V_70 -> V_10 ) ;
if ( ! F_5 ( V_189 ) ) {
F_152 ( V_3 -> V_48 ) ;
V_189 -> V_15 = * V_31 ;
* V_31 = V_189 ;
}
V_189 = V_327 ;
}
if ( V_70 -> V_78 == NULL )
V_309 = 1 ;
F_58 ( & V_3 -> V_59 ) ;
if ( V_309 )
F_153 ( V_3 -> V_48 -> V_307 ,
V_20 -> V_10 ,
V_14 ,
! F_14 ( V_143 , & V_20 -> V_36 ) ,
0 ) ;
}
}
if ( F_23 ( V_300 , & V_20 -> V_36 ) )
if ( F_16 ( & V_3 -> V_301 ) )
F_22 ( V_3 -> V_48 -> V_49 ) ;
}
static void F_160 ( struct V_2 * V_3 ,
struct V_19 * V_20 ,
struct V_98 * V_99 ,
int V_23 )
{
int V_328 = 0 , V_297 = 0 , V_67 ;
if ( V_3 -> V_92 == 2 ) {
V_297 = 1 ; V_328 = 2 ;
} else for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( ( V_70 -> V_78 || V_67 == V_20 -> V_30 ) &&
! F_14 ( V_80 , & V_70 -> V_58 ) &&
! ( F_14 ( V_166 , & V_70 -> V_58 ) ||
F_14 ( V_167 , & V_70 -> V_58 ) ) ) {
if ( F_14 ( V_313 , & V_70 -> V_58 ) )
V_328 ++ ;
else
V_328 += 2 * V_23 ;
}
if ( ! F_14 ( V_306 , & V_70 -> V_58 ) && V_67 != V_20 -> V_30 &&
! F_14 ( V_80 , & V_70 -> V_58 ) &&
! ( F_14 ( V_166 , & V_70 -> V_58 ) ||
F_14 ( V_167 , & V_70 -> V_58 ) ) ) {
if ( F_14 ( V_313 , & V_70 -> V_58 ) ) V_297 ++ ;
else
V_297 += 2 * V_23 ;
}
}
F_30 ( L_40 ,
( unsigned long long ) V_20 -> V_10 , V_328 , V_297 ) ;
F_63 ( V_40 , & V_20 -> V_36 ) ;
if ( V_328 < V_297 && V_328 > 0 )
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( ( V_70 -> V_78 || V_67 == V_20 -> V_30 ) &&
! F_14 ( V_80 , & V_70 -> V_58 ) &&
! ( F_14 ( V_166 , & V_70 -> V_58 ) ||
F_14 ( V_167 , & V_70 -> V_58 ) ) &&
F_14 ( V_313 , & V_70 -> V_58 ) ) {
if (
F_14 ( V_50 , & V_20 -> V_36 ) ) {
F_30 ( L_41
L_42 , V_67 ) ;
F_63 ( V_80 , & V_70 -> V_58 ) ;
F_63 ( V_108 , & V_70 -> V_58 ) ;
V_99 -> V_299 ++ ;
} else {
F_63 ( V_41 , & V_20 -> V_36 ) ;
F_63 ( V_40 , & V_20 -> V_36 ) ;
}
}
}
if ( V_297 <= V_328 && V_297 > 0 ) {
V_297 = 0 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( ! F_14 ( V_306 , & V_70 -> V_58 ) &&
V_67 != V_20 -> V_30 && V_67 != V_20 -> V_22 &&
! F_14 ( V_80 , & V_70 -> V_58 ) &&
! ( F_14 ( V_166 , & V_70 -> V_58 ) ||
F_14 ( V_167 , & V_70 -> V_58 ) ) ) {
V_297 ++ ;
if ( ! F_14 ( V_313 , & V_70 -> V_58 ) )
continue;
if (
F_14 ( V_50 , & V_20 -> V_36 ) ) {
F_30 ( L_41
L_43 , V_67 ) ;
F_63 ( V_80 , & V_70 -> V_58 ) ;
F_63 ( V_108 , & V_70 -> V_58 ) ;
V_99 -> V_299 ++ ;
} else {
F_63 ( V_41 , & V_20 -> V_36 ) ;
F_63 ( V_40 , & V_20 -> V_36 ) ;
}
}
}
}
if ( ( V_99 -> V_325 || ! F_14 ( V_37 , & V_20 -> V_36 ) ) &&
( V_99 -> V_299 == 0 && ( V_297 == 0 || V_328 == 0 ) &&
! F_14 ( V_43 , & V_20 -> V_36 ) ) )
F_147 ( V_20 , V_99 , V_297 == 0 , 0 ) ;
}
static void F_161 ( struct V_2 * V_3 , struct V_19 * V_20 ,
struct V_98 * V_99 , int V_23 )
{
struct V_75 * V_70 = NULL ;
F_63 ( V_40 , & V_20 -> V_36 ) ;
switch ( V_20 -> V_33 ) {
case V_329 :
if ( V_99 -> V_324 == 0 ) {
F_17 ( V_99 -> V_240 != V_23 ) ;
V_20 -> V_33 = V_213 ;
F_63 ( V_212 , & V_99 -> V_203 ) ;
F_21 ( V_166 , & V_20 -> V_70 [ V_20 -> V_30 ] . V_58 ) ;
V_99 -> V_240 -- ;
break;
}
V_70 = & V_20 -> V_70 [ V_99 -> V_323 [ 0 ] ] ;
case V_171 :
V_20 -> V_33 = V_329 ;
if ( ! V_70 )
V_70 = & V_20 -> V_70 [ V_20 -> V_30 ] ;
if ( F_14 ( V_330 , & V_20 -> V_36 ) )
break;
F_17 ( ! F_14 ( V_166 , & V_70 -> V_58 ) ) ;
F_17 ( V_99 -> V_240 != V_23 ) ;
F_63 ( V_80 , & V_70 -> V_58 ) ;
V_99 -> V_299 ++ ;
F_63 ( V_104 , & V_70 -> V_58 ) ;
F_21 ( V_143 , & V_20 -> V_36 ) ;
F_63 ( V_330 , & V_20 -> V_36 ) ;
break;
case V_213 :
break;
case V_199 :
V_20 -> V_33 = V_329 ;
if ( V_99 -> V_324 )
break;
if ( ( V_20 -> V_168 . V_200 & V_331 ) == 0 )
F_63 ( V_330 , & V_20 -> V_36 ) ;
else {
V_3 -> V_48 -> V_332 += V_14 ;
if ( F_14 ( V_333 , & V_3 -> V_48 -> V_256 ) )
F_63 ( V_330 , & V_20 -> V_36 ) ;
else {
V_20 -> V_33 = V_170 ;
F_63 ( V_37 , & V_20 -> V_36 ) ;
F_63 ( V_208 , & V_99 -> V_203 ) ;
F_63 ( V_167 ,
& V_20 -> V_70 [ V_20 -> V_30 ] . V_58 ) ;
V_20 -> V_168 . V_164 = V_20 -> V_30 ;
V_20 -> V_168 . V_169 = - 1 ;
V_99 -> V_240 ++ ;
}
}
break;
case V_170 :
break;
default:
F_44 ( V_81 L_44 ,
V_133 , V_20 -> V_33 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_57 () ;
}
}
static void F_162 ( struct V_2 * V_3 , struct V_19 * V_20 ,
struct V_98 * V_99 ,
int V_23 )
{
int V_30 = V_20 -> V_30 ;
int V_22 = V_20 -> V_22 ;
struct V_75 * V_70 ;
F_63 ( V_40 , & V_20 -> V_36 ) ;
F_17 ( V_99 -> V_324 > 2 ) ;
switch ( V_20 -> V_33 ) {
case V_329 :
if ( V_99 -> V_324 == V_99 -> V_334 ) {
V_20 -> V_33 = V_213 ;
}
if ( ! V_99 -> V_334 && V_99 -> V_324 < 2 ) {
if ( V_20 -> V_33 == V_213 )
V_20 -> V_33 = V_215 ;
else
V_20 -> V_33 = V_214 ;
}
V_20 -> V_168 . V_200 = 0 ;
if ( V_20 -> V_33 == V_213 ) {
F_21 ( V_166 , & V_20 -> V_70 [ V_30 ] . V_58 ) ;
V_99 -> V_240 -- ;
}
if ( V_20 -> V_33 >= V_213 &&
V_20 -> V_33 <= V_215 ) {
F_63 ( V_212 , & V_99 -> V_203 ) ;
break;
}
F_17 ( V_99 -> V_324 != 2 ) ;
case V_171 :
V_20 -> V_33 = V_329 ;
if ( F_14 ( V_330 , & V_20 -> V_36 ) )
break;
F_17 ( V_99 -> V_240 < V_23 - 1 ) ;
if ( V_99 -> V_324 == 2 ) {
V_70 = & V_20 -> V_70 [ V_99 -> V_323 [ 1 ] ] ;
V_99 -> V_299 ++ ;
F_63 ( V_80 , & V_70 -> V_58 ) ;
F_63 ( V_104 , & V_70 -> V_58 ) ;
}
if ( V_99 -> V_324 >= 1 ) {
V_70 = & V_20 -> V_70 [ V_99 -> V_323 [ 0 ] ] ;
V_99 -> V_299 ++ ;
F_63 ( V_80 , & V_70 -> V_58 ) ;
F_63 ( V_104 , & V_70 -> V_58 ) ;
}
if ( V_20 -> V_168 . V_200 & V_331 ) {
V_70 = & V_20 -> V_70 [ V_30 ] ;
V_99 -> V_299 ++ ;
F_63 ( V_80 , & V_70 -> V_58 ) ;
F_63 ( V_104 , & V_70 -> V_58 ) ;
}
if ( V_20 -> V_168 . V_200 & V_335 ) {
V_70 = & V_20 -> V_70 [ V_22 ] ;
V_99 -> V_299 ++ ;
F_63 ( V_80 , & V_70 -> V_58 ) ;
F_63 ( V_104 , & V_70 -> V_58 ) ;
}
F_21 ( V_143 , & V_20 -> V_36 ) ;
F_63 ( V_330 , & V_20 -> V_36 ) ;
break;
case V_213 :
case V_214 :
case V_215 :
break;
case V_199 :
V_20 -> V_33 = V_329 ;
if ( V_20 -> V_168 . V_200 == 0 ) {
if ( ! V_99 -> V_324 )
F_63 ( V_330 , & V_20 -> V_36 ) ;
else {
V_20 -> V_33 = V_171 ;
}
} else {
V_3 -> V_48 -> V_332 += V_14 ;
if ( F_14 ( V_333 , & V_3 -> V_48 -> V_256 ) )
F_63 ( V_330 , & V_20 -> V_36 ) ;
else {
int * V_164 = & V_20 -> V_168 . V_164 ;
V_20 -> V_168 . V_164 = - 1 ;
V_20 -> V_168 . V_169 = - 1 ;
V_20 -> V_33 = V_170 ;
F_63 ( V_37 , & V_20 -> V_36 ) ;
F_63 ( V_208 , & V_99 -> V_203 ) ;
if ( V_20 -> V_168 . V_200 & V_331 ) {
F_63 ( V_167 ,
& V_20 -> V_70 [ V_30 ] . V_58 ) ;
* V_164 = V_30 ;
V_164 = & V_20 -> V_168 . V_169 ;
V_99 -> V_240 ++ ;
}
if ( V_20 -> V_168 . V_200 & V_335 ) {
F_63 ( V_167 ,
& V_20 -> V_70 [ V_22 ] . V_58 ) ;
* V_164 = V_22 ;
V_99 -> V_240 ++ ;
}
}
}
break;
case V_170 :
break;
default:
F_44 ( V_81 L_44 ,
V_133 , V_20 -> V_33 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_57 () ;
}
}
static void F_163 ( struct V_2 * V_3 , struct V_19 * V_20 )
{
int V_67 ;
struct V_144 * V_146 = NULL ;
F_21 ( V_336 , & V_20 -> V_36 ) ;
for ( V_67 = 0 ; V_67 < V_20 -> V_23 ; V_67 ++ )
if ( V_67 != V_20 -> V_30 && V_67 != V_20 -> V_22 ) {
int V_268 , V_337 ;
struct V_19 * V_296 ;
struct V_151 V_152 ;
T_1 V_338 = F_144 ( V_20 , V_67 , 1 ) ;
T_1 V_99 = F_145 ( V_3 , V_338 , 0 ,
& V_268 , NULL ) ;
V_296 = F_54 ( V_3 , V_99 , 0 , 1 , 1 ) ;
if ( V_296 == NULL )
continue;
if ( ! F_14 ( V_53 , & V_296 -> V_36 ) ||
F_14 ( V_339 , & V_296 -> V_70 [ V_268 ] . V_58 ) ) {
F_26 ( V_296 ) ;
continue;
}
F_70 ( & V_152 , 0 , V_146 , NULL , NULL , NULL ) ;
V_146 = F_72 ( V_296 -> V_70 [ V_268 ] . V_65 ,
V_20 -> V_70 [ V_67 ] . V_65 , 0 , 0 , V_140 ,
& V_152 ) ;
F_63 ( V_339 , & V_296 -> V_70 [ V_268 ] . V_58 ) ;
F_63 ( V_166 , & V_296 -> V_70 [ V_268 ] . V_58 ) ;
for ( V_337 = 0 ; V_337 < V_3 -> V_25 ; V_337 ++ )
if ( V_337 != V_296 -> V_30 &&
V_337 != V_296 -> V_22 &&
! F_14 ( V_339 , & V_296 -> V_70 [ V_337 ] . V_58 ) )
break;
if ( V_337 == V_3 -> V_25 ) {
F_63 ( V_340 , & V_296 -> V_36 ) ;
F_63 ( V_40 , & V_296 -> V_36 ) ;
}
F_26 ( V_296 ) ;
}
if ( V_146 ) {
F_103 ( V_146 ) ;
F_164 ( V_146 ) ;
}
}
static void F_165 ( struct V_19 * V_20 , struct V_98 * V_99 )
{
struct V_2 * V_3 = V_20 -> V_57 ;
int V_23 = V_20 -> V_23 ;
struct V_75 * V_70 ;
int V_67 ;
int V_341 = 0 ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
V_99 -> V_127 = F_14 ( V_336 , & V_20 -> V_36 ) ;
V_99 -> V_128 = F_14 ( V_340 , & V_20 -> V_36 ) ;
V_99 -> V_323 [ 0 ] = - 1 ;
V_99 -> V_323 [ 1 ] = - 1 ;
F_50 () ;
F_55 ( & V_3 -> V_59 ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_86 * V_87 ;
T_1 V_121 ;
int V_122 ;
int V_342 = 0 ;
V_70 = & V_20 -> V_70 [ V_67 ] ;
F_30 ( L_45 ,
V_67 , V_70 -> V_58 ,
V_70 -> V_76 , V_70 -> V_78 , V_70 -> V_79 ) ;
if ( F_14 ( V_166 , & V_70 -> V_58 ) && V_70 -> V_76 &&
! F_14 ( V_35 , & V_20 -> V_36 ) )
F_63 ( V_161 , & V_70 -> V_58 ) ;
if ( F_14 ( V_80 , & V_70 -> V_58 ) )
V_99 -> V_299 ++ ;
if ( F_14 ( V_166 , & V_70 -> V_58 ) )
V_99 -> V_240 ++ ;
if ( F_14 ( V_167 , & V_70 -> V_58 ) ) {
V_99 -> V_343 ++ ;
F_17 ( V_99 -> V_343 > 2 ) ;
}
if ( F_14 ( V_161 , & V_70 -> V_58 ) )
V_99 -> V_344 ++ ;
else if ( V_70 -> V_76 )
V_99 -> V_314 ++ ;
if ( V_70 -> V_78 ) {
V_99 -> V_310 ++ ;
if ( ! F_14 ( V_306 , & V_70 -> V_58 ) )
V_99 -> V_345 ++ ;
}
if ( V_70 -> V_79 )
V_99 -> V_79 ++ ;
V_87 = F_51 ( V_3 -> V_23 [ V_67 ] . V_117 ) ;
if ( V_87 && ! F_14 ( V_88 , & V_87 -> V_58 ) &&
V_87 -> V_320 >= V_20 -> V_10 + V_14 &&
! F_62 ( V_87 , V_20 -> V_10 , V_14 ,
& V_121 , & V_122 ) )
F_63 ( V_118 , & V_70 -> V_58 ) ;
else {
if ( V_87 )
F_63 ( V_346 , & V_70 -> V_58 ) ;
V_87 = F_51 ( V_3 -> V_23 [ V_67 ] . V_87 ) ;
F_21 ( V_118 , & V_70 -> V_58 ) ;
}
if ( V_87 && F_14 ( V_88 , & V_87 -> V_58 ) )
V_87 = NULL ;
if ( V_87 ) {
V_342 = F_62 ( V_87 , V_20 -> V_10 , V_14 ,
& V_121 , & V_122 ) ;
if ( V_99 -> V_347 == NULL
&& ( F_14 ( V_264 , & V_87 -> V_58 )
|| V_342 < 0 ) ) {
if ( V_342 < 0 )
F_63 ( V_124 ,
& V_87 -> V_58 ) ;
V_99 -> V_347 = V_87 ;
F_37 ( & V_87 -> V_119 ) ;
}
}
F_21 ( V_313 , & V_70 -> V_58 ) ;
if ( ! V_87 )
;
else if ( V_342 ) {
if ( ! F_14 ( V_120 , & V_87 -> V_58 ) ) {
F_63 ( V_313 , & V_70 -> V_58 ) ;
F_63 ( V_243 , & V_70 -> V_58 ) ;
}
} else if ( F_14 ( V_89 , & V_87 -> V_58 ) )
F_63 ( V_313 , & V_70 -> V_58 ) ;
else if ( V_20 -> V_10 + V_14 <= V_87 -> V_320 )
F_63 ( V_313 , & V_70 -> V_58 ) ;
else if ( F_14 ( V_166 , & V_70 -> V_58 ) &&
F_14 ( V_339 , & V_70 -> V_58 ) )
F_63 ( V_313 , & V_70 -> V_58 ) ;
if ( V_87 && F_14 ( V_253 , & V_70 -> V_58 ) ) {
struct V_86 * V_348 = F_51 (
V_3 -> V_23 [ V_67 ] . V_87 ) ;
if ( V_348 == V_87 )
F_21 ( V_313 , & V_70 -> V_58 ) ;
if ( V_348 && ! F_14 ( V_88 , & V_348 -> V_58 ) ) {
V_99 -> V_349 = 1 ;
F_37 ( & V_348 -> V_119 ) ;
} else
F_21 ( V_253 , & V_70 -> V_58 ) ;
}
if ( V_87 && F_14 ( V_257 , & V_70 -> V_58 ) ) {
struct V_86 * V_348 = F_51 (
V_3 -> V_23 [ V_67 ] . V_87 ) ;
if ( V_348 && ! F_14 ( V_88 , & V_348 -> V_58 ) ) {
V_99 -> V_349 = 1 ;
F_37 ( & V_348 -> V_119 ) ;
} else
F_21 ( V_257 , & V_70 -> V_58 ) ;
}
if ( F_14 ( V_252 , & V_70 -> V_58 ) ) {
struct V_86 * V_348 = F_51 (
V_3 -> V_23 [ V_67 ] . V_117 ) ;
if ( V_348 && ! F_14 ( V_88 , & V_348 -> V_58 ) ) {
V_99 -> V_349 = 1 ;
F_37 ( & V_348 -> V_119 ) ;
} else
F_21 ( V_252 , & V_70 -> V_58 ) ;
}
if ( ! F_14 ( V_313 , & V_70 -> V_58 ) ) {
F_21 ( V_243 , & V_70 -> V_58 ) ;
F_21 ( V_246 , & V_70 -> V_58 ) ;
}
if ( F_14 ( V_243 , & V_70 -> V_58 ) )
F_21 ( V_313 , & V_70 -> V_58 ) ;
if ( ! F_14 ( V_313 , & V_70 -> V_58 ) ) {
if ( V_99 -> V_324 < 2 )
V_99 -> V_323 [ V_99 -> V_324 ] = V_67 ;
V_99 -> V_324 ++ ;
if ( V_87 && ! F_14 ( V_88 , & V_87 -> V_58 ) )
V_341 = 1 ;
}
}
F_58 ( & V_3 -> V_59 ) ;
if ( F_14 ( V_315 , & V_20 -> V_36 ) ) {
if ( V_341 ||
V_20 -> V_10 >= V_3 -> V_48 -> V_321 )
V_99 -> V_126 = 1 ;
else
V_99 -> V_129 = 1 ;
}
F_52 () ;
}
static void F_166 ( struct V_19 * V_20 )
{
struct V_98 V_99 ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_67 ;
int V_198 ;
int V_23 = V_20 -> V_23 ;
struct V_75 * V_350 , * V_351 ;
F_21 ( V_40 , & V_20 -> V_36 ) ;
if ( F_109 ( V_352 , & V_20 -> V_36 ) ) {
F_63 ( V_40 , & V_20 -> V_36 ) ;
return;
}
if ( F_23 ( V_353 , & V_20 -> V_36 ) ) {
F_63 ( V_315 , & V_20 -> V_36 ) ;
F_21 ( V_330 , & V_20 -> V_36 ) ;
}
F_21 ( V_41 , & V_20 -> V_36 ) ;
F_30 ( L_46
L_47 ,
( unsigned long long ) V_20 -> V_10 , V_20 -> V_36 ,
F_19 ( & V_20 -> V_27 ) , V_20 -> V_30 , V_20 -> V_22 ,
V_20 -> V_33 , V_20 -> V_34 ) ;
F_165 ( V_20 , & V_99 ) ;
if ( V_99 . V_349 ) {
F_63 ( V_40 , & V_20 -> V_36 ) ;
goto V_354;
}
if ( F_80 ( V_99 . V_347 ) ) {
if ( V_99 . V_126 || V_99 . V_127 || V_99 . V_128 ||
V_99 . V_129 || V_99 . V_310 || V_99 . V_79 ) {
F_63 ( V_40 , & V_20 -> V_36 ) ;
goto V_354;
}
F_66 ( V_99 . V_347 , V_3 -> V_48 ) ;
V_99 . V_347 = NULL ;
}
if ( V_99 . V_344 && ! F_14 ( V_35 , & V_20 -> V_36 ) ) {
F_63 ( V_207 , & V_99 . V_203 ) ;
F_63 ( V_35 , & V_20 -> V_36 ) ;
}
F_30 ( L_48
L_49 ,
V_99 . V_299 , V_99 . V_240 , V_99 . V_314 , V_99 . V_310 , V_99 . V_324 ,
V_99 . V_323 [ 0 ] , V_99 . V_323 [ 1 ] ) ;
if ( V_99 . V_324 > V_3 -> V_92 ) {
V_20 -> V_33 = 0 ;
V_20 -> V_34 = 0 ;
if ( V_99 . V_314 + V_99 . V_310 + V_99 . V_79 )
F_150 ( V_3 , V_20 , & V_99 , V_23 , & V_99 . V_31 ) ;
if ( V_99 . V_126 + V_99 . V_129 )
F_154 ( V_3 , V_20 , & V_99 ) ;
}
V_350 = & V_20 -> V_70 [ V_20 -> V_30 ] ;
V_99 . V_355 = ( V_99 . V_324 >= 1 && V_99 . V_323 [ 0 ] == V_20 -> V_30 )
|| ( V_99 . V_324 >= 2 && V_99 . V_323 [ 1 ] == V_20 -> V_30 ) ;
V_351 = & V_20 -> V_70 [ V_20 -> V_22 ] ;
V_99 . V_334 = ( V_99 . V_324 >= 1 && V_99 . V_323 [ 0 ] == V_20 -> V_22 )
|| ( V_99 . V_324 >= 2 && V_99 . V_323 [ 1 ] == V_20 -> V_22 )
|| V_3 -> V_205 < 6 ;
if ( V_99 . V_79 &&
( V_99 . V_355 || ( ( F_14 ( V_313 , & V_350 -> V_58 )
&& ! F_14 ( V_80 , & V_350 -> V_58 )
&& F_14 ( V_166 , & V_350 -> V_58 ) ) ) ) &&
( V_99 . V_334 || ( ( F_14 ( V_313 , & V_351 -> V_58 )
&& ! F_14 ( V_80 , & V_351 -> V_58 )
&& F_14 ( V_166 , & V_351 -> V_58 ) ) ) ) )
F_159 ( V_3 , V_20 , V_23 , & V_99 . V_31 ) ;
if ( V_99 . V_314 || V_99 . V_345
|| ( V_3 -> V_205 == 6 && V_99 . V_310 && V_99 . V_324 )
|| ( V_99 . V_126 && ( V_99 . V_240 + V_99 . V_343 < V_23 ) )
|| V_99 . V_129
|| V_99 . V_127 )
F_158 ( V_20 , & V_99 , V_23 ) ;
V_198 = 0 ;
if ( V_20 -> V_34 == V_195 )
V_198 = 1 ;
if ( V_20 -> V_34 == V_193 ||
V_20 -> V_34 == V_195 ) {
V_20 -> V_34 = V_356 ;
F_17 ( ! F_14 ( V_166 , & V_20 -> V_70 [ V_20 -> V_30 ] . V_58 ) ) ;
F_17 ( V_20 -> V_22 >= 0 &&
! F_14 ( V_166 , & V_20 -> V_70 [ V_20 -> V_22 ] . V_58 ) ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( F_14 ( V_80 , & V_70 -> V_58 ) &&
( V_67 == V_20 -> V_30 || V_67 == V_20 -> V_22 ||
V_70 -> V_79 ) ) {
F_30 ( L_50 , V_67 ) ;
F_63 ( V_104 , & V_70 -> V_58 ) ;
if ( V_198 )
continue;
if ( ! F_14 ( V_313 , & V_70 -> V_58 ) ||
( ( V_67 == V_20 -> V_30 || V_67 == V_20 -> V_22 ) &&
V_99 . V_324 == 0 ) )
F_63 ( V_330 , & V_20 -> V_36 ) ;
}
}
if ( F_23 ( V_50 , & V_20 -> V_36 ) )
V_99 . V_357 = 1 ;
}
if ( V_99 . V_310 && ! V_20 -> V_34 && ! V_20 -> V_33 )
F_160 ( V_3 , V_20 , & V_99 , V_23 ) ;
if ( V_20 -> V_33 ||
( V_99 . V_126 && V_99 . V_299 == 0 &&
! F_14 ( V_37 , & V_20 -> V_36 ) &&
! F_14 ( V_330 , & V_20 -> V_36 ) ) ) {
if ( V_3 -> V_205 == 6 )
F_162 ( V_3 , V_20 , & V_99 , V_23 ) ;
else
F_161 ( V_3 , V_20 , & V_99 , V_23 ) ;
}
if ( V_99 . V_129 && V_99 . V_299 == 0
&& ! F_14 ( V_330 , & V_20 -> V_36 ) ) {
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ )
if ( F_14 ( V_166 , & V_20 -> V_70 [ V_67 ] . V_58 ) &&
F_14 ( V_346 , & V_20 -> V_70 [ V_67 ] . V_58 ) ) {
F_63 ( V_110 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_63 ( V_80 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
V_99 . V_299 ++ ;
}
F_63 ( V_330 , & V_20 -> V_36 ) ;
}
if ( ( V_99 . V_126 || V_99 . V_129 ) && V_99 . V_299 == 0 &&
F_14 ( V_330 , & V_20 -> V_36 ) ) {
F_155 ( V_3 -> V_48 , V_14 , 1 ) ;
F_21 ( V_315 , & V_20 -> V_36 ) ;
}
if ( V_99 . V_324 <= V_3 -> V_92 && ! V_3 -> V_48 -> V_358 )
for ( V_67 = 0 ; V_67 < V_99 . V_324 ; V_67 ++ ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_99 . V_323 [ V_67 ] ] ;
if ( F_14 ( V_243 , & V_70 -> V_58 )
&& ! F_14 ( V_80 , & V_70 -> V_58 )
&& F_14 ( V_166 , & V_70 -> V_58 )
) {
if ( ! F_14 ( V_246 , & V_70 -> V_58 ) ) {
F_63 ( V_104 , & V_70 -> V_58 ) ;
F_63 ( V_246 , & V_70 -> V_58 ) ;
F_63 ( V_80 , & V_70 -> V_58 ) ;
V_99 . V_299 ++ ;
} else {
F_63 ( V_108 , & V_70 -> V_58 ) ;
F_63 ( V_80 , & V_70 -> V_58 ) ;
V_99 . V_299 ++ ;
}
}
}
if ( V_20 -> V_34 == V_197 ) {
struct V_19 * V_359
= F_54 ( V_3 , V_20 -> V_10 , 1 , 1 , 1 ) ;
if ( V_359 && F_14 ( V_336 , & V_359 -> V_36 ) ) {
F_63 ( V_41 , & V_20 -> V_36 ) ;
F_63 ( V_40 , & V_20 -> V_36 ) ;
if ( ! F_142 ( V_50 ,
& V_359 -> V_36 ) )
F_37 ( & V_3 -> V_51 ) ;
F_26 ( V_359 ) ;
goto V_354;
}
if ( V_359 )
F_26 ( V_359 ) ;
V_20 -> V_34 = V_356 ;
F_21 ( V_53 , & V_20 -> V_36 ) ;
for ( V_67 = V_3 -> V_25 ; V_67 -- ; ) {
F_63 ( V_104 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_63 ( V_80 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
V_99 . V_299 ++ ;
}
}
if ( V_99 . V_128 && F_14 ( V_53 , & V_20 -> V_36 ) &&
! V_20 -> V_34 ) {
V_20 -> V_23 = V_3 -> V_25 ;
F_43 ( V_20 -> V_10 , V_3 , 0 , V_20 ) ;
F_147 ( V_20 , & V_99 , 1 , 1 ) ;
} else if ( V_99 . V_128 && ! V_20 -> V_34 && V_99 . V_299 == 0 ) {
F_21 ( V_340 , & V_20 -> V_36 ) ;
F_24 ( & V_3 -> V_360 ) ;
F_25 ( & V_3 -> V_217 ) ;
F_155 ( V_3 -> V_48 , V_14 , 1 ) ;
}
if ( V_99 . V_127 && V_99 . V_299 == 0 &&
! F_14 ( V_37 , & V_20 -> V_36 ) )
F_163 ( V_3 , V_20 ) ;
V_354:
if ( V_3 -> V_48 -> V_125 && F_80 ( V_99 . V_347 ) )
F_65 ( V_99 . V_347 , V_3 -> V_48 ) ;
if ( V_99 . V_349 )
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_86 * V_87 ;
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( F_23 ( V_253 , & V_70 -> V_58 ) ) {
V_87 = V_3 -> V_23 [ V_67 ] . V_87 ;
if ( ! F_151 ( V_87 , V_20 -> V_10 ,
V_14 , 0 ) )
F_141 ( V_3 -> V_48 , V_87 ) ;
F_66 ( V_87 , V_3 -> V_48 ) ;
}
if ( F_23 ( V_257 , & V_70 -> V_58 ) ) {
V_87 = V_3 -> V_23 [ V_67 ] . V_87 ;
F_167 ( V_87 , V_20 -> V_10 ,
V_14 ) ;
F_66 ( V_87 , V_3 -> V_48 ) ;
}
if ( F_23 ( V_252 , & V_70 -> V_58 ) ) {
V_87 = V_3 -> V_23 [ V_67 ] . V_117 ;
if ( ! V_87 )
V_87 = V_3 -> V_23 [ V_67 ] . V_87 ;
F_167 ( V_87 , V_20 -> V_10 ,
V_14 ) ;
F_66 ( V_87 , V_3 -> V_48 ) ;
}
}
if ( V_99 . V_203 )
F_107 ( V_20 , V_99 . V_203 ) ;
F_59 ( V_20 , & V_99 ) ;
if ( V_99 . V_357 ) {
F_24 ( & V_3 -> V_51 ) ;
if ( F_19 ( & V_3 -> V_51 ) <
V_52 )
F_22 ( V_3 -> V_48 -> V_49 ) ;
}
F_11 ( V_99 . V_31 ) ;
F_106 ( V_352 , & V_20 -> V_36 ) ;
}
static void F_168 ( struct V_2 * V_3 )
{
if ( F_19 ( & V_3 -> V_51 ) < V_52 ) {
while ( ! F_18 ( & V_3 -> V_42 ) ) {
struct V_61 * V_361 = V_3 -> V_42 . V_64 ;
struct V_19 * V_20 ;
V_20 = F_35 ( V_361 , struct V_19 , V_38 ) ;
F_36 ( V_361 ) ;
F_21 ( V_41 , & V_20 -> V_36 ) ;
if ( ! F_142 ( V_50 , & V_20 -> V_36 ) )
F_37 ( & V_3 -> V_51 ) ;
F_20 ( & V_20 -> V_38 , & V_3 -> V_362 ) ;
}
}
}
static void F_169 ( struct V_2 * V_3 )
{
struct V_61 V_363 ;
F_126 ( & V_363 , & V_3 -> V_46 ) ;
F_36 ( & V_3 -> V_46 ) ;
while ( ! F_18 ( & V_363 ) ) {
struct V_19 * V_20 = F_35 ( V_363 . V_64 , struct V_19 , V_38 ) ;
F_36 ( & V_20 -> V_38 ) ;
F_37 ( & V_20 -> V_27 ) ;
F_15 ( V_3 , V_20 ) ;
}
}
int F_170 ( struct V_48 * V_48 , int V_364 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
if ( V_3 -> V_96 )
return 1 ;
if ( V_3 -> V_95 )
return 1 ;
if ( F_171 ( & V_3 -> V_54 ) )
return 1 ;
return 0 ;
}
static int F_172 ( void * V_365 , int V_364 )
{
struct V_48 * V_48 = V_365 ;
return F_173 ( V_48 , V_364 ) ||
F_170 ( V_48 , V_364 ) ;
}
static int F_174 ( struct V_366 * V_367 ,
struct V_368 * V_369 ,
struct V_147 * V_370 )
{
struct V_48 * V_48 = V_367 -> V_371 ;
T_1 V_10 = V_369 -> V_13 + F_175 ( V_369 -> V_132 ) ;
int F_119 ;
unsigned int V_278 = V_48 -> V_278 ;
unsigned int V_372 = V_369 -> V_12 >> 9 ;
if ( ( V_369 -> V_113 & 1 ) == V_107 )
return V_370 -> V_139 ;
if ( V_48 -> V_373 < V_48 -> V_278 )
V_278 = V_48 -> V_373 ;
F_119 = ( V_278 - ( ( V_10 & ( V_278 - 1 ) ) + V_372 ) ) << 9 ;
if ( F_119 < 0 ) F_119 = 0 ;
if ( F_119 <= V_370 -> V_139 && V_372 == 0 )
return V_370 -> V_139 ;
else
return F_119 ;
}
static int F_176 ( struct V_48 * V_48 , struct V_9 * V_9 )
{
T_1 V_10 = V_9 -> V_13 + F_175 ( V_9 -> V_132 ) ;
unsigned int V_278 = V_48 -> V_278 ;
unsigned int V_372 = V_9 -> V_12 >> 9 ;
if ( V_48 -> V_373 < V_48 -> V_278 )
V_278 = V_48 -> V_373 ;
return V_278 >=
( ( V_10 & ( V_278 - 1 ) ) + V_372 ) ;
}
static void F_177 ( struct V_9 * V_32 , struct V_2 * V_3 )
{
unsigned long V_58 ;
F_27 ( & V_3 -> V_59 , V_58 ) ;
V_32 -> V_15 = V_3 -> V_374 ;
V_3 -> V_374 = V_32 ;
F_28 ( & V_3 -> V_59 , V_58 ) ;
F_22 ( V_3 -> V_48 -> V_49 ) ;
}
static struct V_9 * F_178 ( struct V_2 * V_3 )
{
struct V_9 * V_32 ;
V_32 = V_3 -> V_56 ;
if ( V_32 ) {
V_3 -> V_56 = NULL ;
return V_32 ;
}
V_32 = V_3 -> V_374 ;
if( V_32 ) {
V_3 -> V_374 = V_32 -> V_15 ;
V_32 -> V_15 = NULL ;
V_32 -> V_16 = 1 ;
}
return V_32 ;
}
static void F_179 ( struct V_9 * V_32 , int error )
{
struct V_9 * V_375 = V_32 -> V_239 ;
struct V_48 * V_48 ;
struct V_2 * V_3 ;
int V_240 = F_14 ( V_136 , & V_32 -> V_135 ) ;
struct V_86 * V_87 ;
F_180 ( V_32 ) ;
V_87 = ( void * ) V_375 -> V_15 ;
V_375 -> V_15 = NULL ;
V_48 = V_87 -> V_48 ;
V_3 = V_48 -> V_262 ;
F_66 ( V_87 , V_3 -> V_48 ) ;
if ( ! error && V_240 ) {
F_12 ( V_375 , 0 ) ;
if ( F_16 ( & V_3 -> V_376 ) )
F_25 ( & V_3 -> V_55 ) ;
return;
}
F_30 ( L_51 ) ;
F_177 ( V_375 , V_3 ) ;
}
static int F_181 ( struct V_9 * V_32 )
{
struct V_366 * V_367 = F_182 ( V_32 -> V_132 ) ;
if ( ( V_32 -> V_12 >> 9 ) > F_183 ( V_367 ) )
return 0 ;
F_184 ( V_367 , V_32 ) ;
if ( V_32 -> V_16 > F_185 ( V_367 ) )
return 0 ;
if ( V_367 -> V_377 )
return 0 ;
return 1 ;
}
static int F_186 ( struct V_48 * V_48 , struct V_9 * V_378 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
int V_268 ;
struct V_9 * V_379 ;
struct V_86 * V_87 ;
T_1 V_380 ;
if ( ! F_176 ( V_48 , V_378 ) ) {
F_30 ( L_52 ) ;
return 0 ;
}
V_379 = F_187 ( V_378 , V_238 , V_48 ) ;
if ( ! V_379 )
return 0 ;
V_379 -> V_114 = F_179 ;
V_379 -> V_239 = V_378 ;
V_379 -> V_13 = F_145 ( V_3 , V_378 -> V_13 ,
0 ,
& V_268 , NULL ) ;
V_380 = V_379 -> V_13 + ( V_379 -> V_12 >> 9 ) ;
F_50 () ;
V_87 = F_51 ( V_3 -> V_23 [ V_268 ] . V_117 ) ;
if ( ! V_87 || F_14 ( V_88 , & V_87 -> V_58 ) ||
V_87 -> V_320 < V_380 ) {
V_87 = F_51 ( V_3 -> V_23 [ V_268 ] . V_87 ) ;
if ( V_87 &&
( F_14 ( V_88 , & V_87 -> V_58 ) ||
! ( F_14 ( V_89 , & V_87 -> V_58 ) ||
V_87 -> V_320 >= V_380 ) ) )
V_87 = NULL ;
}
if ( V_87 ) {
T_1 V_121 ;
int V_122 ;
F_37 ( & V_87 -> V_119 ) ;
F_52 () ;
V_378 -> V_15 = ( void * ) V_87 ;
V_379 -> V_132 = V_87 -> V_130 ;
V_379 -> V_135 &= ~ ( 1 << V_381 ) ;
V_379 -> V_13 += V_87 -> V_134 ;
if ( ! F_181 ( V_379 ) ||
F_62 ( V_87 , V_379 -> V_13 , V_379 -> V_12 >> 9 ,
& V_121 , & V_122 ) ) {
F_180 ( V_379 ) ;
F_66 ( V_87 , V_48 ) ;
return 0 ;
}
F_55 ( & V_3 -> V_59 ) ;
F_56 ( V_3 -> V_55 ,
V_3 -> V_95 == 0 ,
V_3 -> V_59 , ) ;
F_37 ( & V_3 -> V_376 ) ;
F_58 ( & V_3 -> V_59 ) ;
F_68 ( V_379 ) ;
return 1 ;
} else {
F_52 () ;
F_180 ( V_379 ) ;
return 0 ;
}
}
static struct V_19 * F_188 ( struct V_2 * V_3 )
{
struct V_19 * V_20 ;
F_30 ( L_53 ,
V_133 ,
F_18 ( & V_3 -> V_47 ) ? L_54 : L_55 ,
F_18 ( & V_3 -> V_362 ) ? L_54 : L_55 ,
F_19 ( & V_3 -> V_301 ) , V_3 -> V_382 ) ;
if ( ! F_18 ( & V_3 -> V_47 ) ) {
V_20 = F_35 ( V_3 -> V_47 . V_64 , F_189 ( * V_20 ) , V_38 ) ;
if ( F_18 ( & V_3 -> V_362 ) )
V_3 -> V_382 = 0 ;
else if ( ! F_14 ( V_131 , & V_20 -> V_36 ) ) {
if ( V_3 -> V_362 . V_64 == V_3 -> V_383 )
V_3 -> V_382 ++ ;
else {
V_3 -> V_383 = V_3 -> V_362 . V_64 ;
V_3 -> V_382 -= V_3 -> V_384 ;
if ( V_3 -> V_382 < 0 )
V_3 -> V_382 = 0 ;
}
}
} else if ( ! F_18 ( & V_3 -> V_362 ) &&
( ( V_3 -> V_384 &&
V_3 -> V_382 > V_3 -> V_384 ) ||
F_19 ( & V_3 -> V_301 ) == 0 ) ) {
V_20 = F_35 ( V_3 -> V_362 . V_64 ,
F_189 ( * V_20 ) , V_38 ) ;
V_3 -> V_382 -= V_3 -> V_384 ;
if ( V_3 -> V_382 < 0 )
V_3 -> V_382 = 0 ;
} else
return NULL ;
F_36 ( & V_20 -> V_38 ) ;
F_37 ( & V_20 -> V_27 ) ;
F_17 ( F_19 ( & V_20 -> V_27 ) != 1 ) ;
return V_20 ;
}
static void F_190 ( struct V_48 * V_48 , struct V_9 * V_32 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
int V_268 ;
T_1 V_273 ;
T_1 V_385 , V_386 ;
struct V_19 * V_20 ;
const int V_100 = F_191 ( V_32 ) ;
int V_387 ;
int V_388 ;
if ( F_80 ( V_32 -> V_113 & V_389 ) ) {
F_192 ( V_48 , V_32 ) ;
return;
}
F_193 ( V_48 , V_32 ) ;
if ( V_100 == V_109 &&
V_48 -> V_90 == V_91 &&
F_186 ( V_48 , V_32 ) )
return;
V_385 = V_32 -> V_13 & ~ ( ( T_1 ) V_14 - 1 ) ;
V_386 = V_32 -> V_13 + ( V_32 -> V_12 >> 9 ) ;
V_32 -> V_15 = NULL ;
V_32 -> V_16 = 1 ;
V_388 = F_194 ( V_48 ) ;
for (; V_385 < V_386 ; V_385 += V_14 ) {
F_195 ( V_390 ) ;
int V_23 , V_279 ;
int V_72 ;
V_249:
V_72 = 0 ;
V_23 = V_3 -> V_25 ;
F_196 ( & V_3 -> V_217 , & V_390 , V_391 ) ;
if ( F_80 ( V_3 -> V_392 != V_91 ) ) {
F_55 ( & V_3 -> V_59 ) ;
if ( V_48 -> V_393 < 0
? V_385 < V_3 -> V_392
: V_385 >= V_3 -> V_392 ) {
V_23 = V_3 -> V_74 ;
V_72 = 1 ;
} else {
if ( V_48 -> V_393 < 0
? V_385 < V_3 -> V_394
: V_385 >= V_3 -> V_394 ) {
F_58 ( & V_3 -> V_59 ) ;
F_197 () ;
goto V_249;
}
}
F_58 ( & V_3 -> V_59 ) ;
}
V_279 = V_23 - V_3 -> V_92 ;
V_273 = F_145 ( V_3 , V_385 ,
V_72 ,
& V_268 , NULL ) ;
F_30 ( L_56 ,
( unsigned long long ) V_273 ,
( unsigned long long ) V_385 ) ;
V_20 = F_54 ( V_3 , V_273 , V_72 ,
( V_32 -> V_113 & V_395 ) , 0 ) ;
if ( V_20 ) {
if ( F_80 ( V_72 ) ) {
int V_396 = 0 ;
F_55 ( & V_3 -> V_59 ) ;
if ( V_48 -> V_393 < 0
? V_385 >= V_3 -> V_392
: V_385 < V_3 -> V_392 )
V_396 = 1 ;
F_58 ( & V_3 -> V_59 ) ;
if ( V_396 ) {
F_26 ( V_20 ) ;
F_197 () ;
goto V_249;
}
}
if ( V_100 == V_107 &&
V_385 >= V_48 -> V_397 &&
V_385 < V_48 -> V_398 ) {
F_26 ( V_20 ) ;
F_198 ( V_399 ) ;
F_196 ( & V_3 -> V_217 ,
& V_390 , V_400 ) ;
if ( V_385 >= V_48 -> V_397 &&
V_385 < V_48 -> V_398 )
F_197 () ;
goto V_249;
}
if ( F_14 ( V_53 , & V_20 -> V_36 ) ||
! F_148 ( V_20 , V_32 , V_268 , V_100 ) ) {
F_22 ( V_48 -> V_49 ) ;
F_26 ( V_20 ) ;
F_197 () ;
goto V_249;
}
F_199 ( & V_3 -> V_217 , & V_390 ) ;
F_63 ( V_40 , & V_20 -> V_36 ) ;
F_21 ( V_41 , & V_20 -> V_36 ) ;
if ( ( V_32 -> V_113 & V_401 ) &&
! F_142 ( V_50 , & V_20 -> V_36 ) )
F_37 ( & V_3 -> V_51 ) ;
F_26 ( V_20 ) ;
} else {
F_21 ( V_136 , & V_32 -> V_135 ) ;
F_199 ( & V_3 -> V_217 , & V_390 ) ;
break;
}
}
if ( ! V_388 )
F_22 ( V_48 -> V_49 ) ;
F_55 ( & V_3 -> V_59 ) ;
V_387 = F_5 ( V_32 ) ;
F_58 ( & V_3 -> V_59 ) ;
if ( V_387 == 0 ) {
if ( V_100 == V_107 )
F_152 ( V_48 ) ;
F_12 ( V_32 , 0 ) ;
}
}
static T_1 F_200 ( struct V_48 * V_48 , T_1 V_402 , int * V_403 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
struct V_19 * V_20 ;
T_1 V_404 , V_386 ;
int V_25 = V_3 -> V_74 ;
int V_279 = V_25 - V_3 -> V_92 ;
int V_405 = V_3 -> V_25 - V_3 -> V_92 ;
int V_67 ;
int V_268 ;
T_1 V_406 , V_407 , V_408 ;
T_1 V_409 ;
int V_410 ;
struct V_61 V_411 ;
if ( V_402 == 0 ) {
if ( V_48 -> V_393 < 0 &&
V_3 -> V_392 < F_201 ( V_48 , 0 , 0 ) ) {
V_402 = F_201 ( V_48 , 0 , 0 )
- V_3 -> V_392 ;
} else if ( V_48 -> V_393 >= 0 &&
V_3 -> V_392 > 0 )
V_402 = V_3 -> V_392 ;
F_146 ( V_402 , V_405 ) ;
if ( V_402 ) {
V_48 -> V_412 = V_402 ;
F_202 ( & V_48 -> V_413 , NULL , L_57 ) ;
* V_403 = 1 ;
return V_402 ;
}
}
if ( V_48 -> V_373 > V_48 -> V_278 )
V_410 = V_48 -> V_373 ;
else
V_410 = V_48 -> V_278 ;
V_406 = V_3 -> V_392 ;
F_146 ( V_406 , V_405 ) ;
V_407 = V_3 -> V_392 ;
F_146 ( V_407 , V_279 ) ;
V_408 = V_3 -> V_394 ;
F_146 ( V_408 , V_279 ) ;
if ( V_48 -> V_393 < 0 ) {
V_406 -= F_203 ( T_1 , V_410 , V_406 ) ;
V_407 += V_410 ;
V_408 += V_410 ;
} else {
V_406 += V_410 ;
V_407 -= F_203 ( T_1 , V_410 , V_407 ) ;
V_408 -= F_203 ( T_1 , V_410 , V_408 ) ;
}
if ( ( V_48 -> V_393 < 0
? ( V_408 > V_406 && V_407 < V_406 )
: ( V_408 < V_406 && V_407 > V_406 ) ) ||
F_204 ( V_414 , V_3 -> V_415 + 10 * V_416 ) ) {
F_108 ( V_3 -> V_217 ,
F_19 ( & V_3 -> V_360 ) == 0 ) ;
V_48 -> V_90 = V_3 -> V_392 ;
V_48 -> V_412 = V_402 ;
V_3 -> V_415 = V_414 ;
F_63 ( V_265 , & V_48 -> V_58 ) ;
F_22 ( V_48 -> V_49 ) ;
F_108 ( V_48 -> V_417 , V_48 -> V_58 == 0 ||
F_205 () ) ;
F_55 ( & V_3 -> V_59 ) ;
V_3 -> V_394 = V_48 -> V_90 ;
F_58 ( & V_3 -> V_59 ) ;
F_25 ( & V_3 -> V_217 ) ;
F_202 ( & V_48 -> V_413 , NULL , L_57 ) ;
}
if ( V_48 -> V_393 < 0 ) {
F_17 ( V_3 -> V_392 == 0 ) ;
V_409 = V_406 ;
F_17 ( ( V_48 -> V_418 &
~ ( ( T_1 ) V_410 - 1 ) )
- V_410 - V_409
!= V_402 ) ;
} else {
F_17 ( V_406 != V_402 + V_410 ) ;
V_409 = V_402 ;
}
F_117 ( & V_411 ) ;
for ( V_67 = 0 ; V_67 < V_410 ; V_67 += V_14 ) {
int V_337 ;
int V_419 = 0 ;
V_20 = F_54 ( V_3 , V_409 + V_67 , 0 , 0 , 1 ) ;
F_63 ( V_53 , & V_20 -> V_36 ) ;
F_37 ( & V_3 -> V_360 ) ;
for ( V_337 = V_20 -> V_23 ; V_337 -- ; ) {
T_1 V_99 ;
if ( V_337 == V_20 -> V_30 )
continue;
if ( V_3 -> V_205 == 6 &&
V_337 == V_20 -> V_22 )
continue;
V_99 = F_144 ( V_20 , V_337 , 0 ) ;
if ( V_99 < F_201 ( V_48 , 0 , 0 ) ) {
V_419 = 1 ;
continue;
}
memset ( F_206 ( V_20 -> V_70 [ V_337 ] . V_65 ) , 0 , V_140 ) ;
F_63 ( V_339 , & V_20 -> V_70 [ V_337 ] . V_58 ) ;
F_63 ( V_166 , & V_20 -> V_70 [ V_337 ] . V_58 ) ;
}
if ( ! V_419 ) {
F_63 ( V_340 , & V_20 -> V_36 ) ;
F_63 ( V_40 , & V_20 -> V_36 ) ;
}
F_126 ( & V_20 -> V_38 , & V_411 ) ;
}
F_55 ( & V_3 -> V_59 ) ;
if ( V_48 -> V_393 < 0 )
V_3 -> V_392 -= V_410 * V_405 ;
else
V_3 -> V_392 += V_410 * V_405 ;
F_58 ( & V_3 -> V_59 ) ;
V_404 =
F_145 ( V_3 , V_409 * ( V_405 ) ,
1 , & V_268 , NULL ) ;
V_386 =
F_145 ( V_3 , ( ( V_409 + V_410 )
* V_405 - 1 ) ,
1 , & V_268 , NULL ) ;
if ( V_386 >= V_48 -> V_418 )
V_386 = V_48 -> V_418 - 1 ;
while ( V_404 <= V_386 ) {
V_20 = F_54 ( V_3 , V_404 , 1 , 0 , 1 ) ;
F_63 ( V_336 , & V_20 -> V_36 ) ;
F_63 ( V_40 , & V_20 -> V_36 ) ;
F_26 ( V_20 ) ;
V_404 += V_14 ;
}
while ( ! F_18 ( & V_411 ) ) {
V_20 = F_35 ( V_411 . V_64 , struct V_19 , V_38 ) ;
F_36 ( & V_20 -> V_38 ) ;
F_26 ( V_20 ) ;
}
V_402 += V_410 ;
if ( ( V_402 - V_48 -> V_412 ) * 2
>= V_48 -> V_420 - V_48 -> V_412 ) {
F_108 ( V_3 -> V_217 ,
F_19 ( & V_3 -> V_360 ) == 0 ) ;
V_48 -> V_90 = V_3 -> V_392 ;
V_48 -> V_412 = V_402 ;
V_3 -> V_415 = V_414 ;
F_63 ( V_265 , & V_48 -> V_58 ) ;
F_22 ( V_48 -> V_49 ) ;
F_108 ( V_48 -> V_417 ,
! F_14 ( V_265 , & V_48 -> V_58 )
|| F_205 () ) ;
F_55 ( & V_3 -> V_59 ) ;
V_3 -> V_394 = V_48 -> V_90 ;
F_58 ( & V_3 -> V_59 ) ;
F_25 ( & V_3 -> V_217 ) ;
F_202 ( & V_48 -> V_413 , NULL , L_57 ) ;
}
return V_410 ;
}
static inline T_1 F_207 ( struct V_48 * V_48 , T_1 V_402 , int * V_403 , int V_421 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
struct V_19 * V_20 ;
T_1 V_422 = V_48 -> V_418 ;
T_1 V_423 ;
int V_424 = 0 ;
int V_67 ;
if ( V_402 >= V_422 ) {
if ( F_14 ( V_425 , & V_48 -> V_256 ) ) {
F_208 ( V_3 ) ;
return 0 ;
}
if ( V_48 -> V_426 < V_422 )
F_209 ( V_48 -> V_307 , V_48 -> V_426 ,
& V_423 , 1 ) ;
else
V_3 -> V_427 = 0 ;
F_210 ( V_48 -> V_307 ) ;
return 0 ;
}
F_108 ( V_3 -> V_217 , V_3 -> V_95 != 2 ) ;
if ( F_14 ( V_425 , & V_48 -> V_256 ) )
return F_200 ( V_48 , V_402 , V_403 ) ;
if ( V_48 -> V_84 >= V_3 -> V_92 &&
F_14 ( V_428 , & V_48 -> V_256 ) ) {
T_1 V_319 = V_48 -> V_418 - V_402 ;
* V_403 = 1 ;
return V_319 ;
}
if ( ! F_211 ( V_48 -> V_307 , V_402 , & V_423 , 1 ) &&
! F_14 ( V_429 , & V_48 -> V_256 ) &&
! V_3 -> V_427 && V_423 >= V_14 ) {
V_423 /= V_14 ;
* V_403 = 1 ;
return V_423 * V_14 ;
}
F_212 ( V_48 -> V_307 , V_402 ) ;
V_20 = F_54 ( V_3 , V_402 , 0 , 1 , 0 ) ;
if ( V_20 == NULL ) {
V_20 = F_54 ( V_3 , V_402 , 0 , 0 , 0 ) ;
F_213 ( 1 ) ;
}
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ )
if ( V_3 -> V_23 [ V_67 ] . V_87 == NULL )
V_424 = 1 ;
F_211 ( V_48 -> V_307 , V_402 , & V_423 , V_424 ) ;
F_63 ( V_353 , & V_20 -> V_36 ) ;
F_166 ( V_20 ) ;
F_26 ( V_20 ) ;
return V_14 ;
}
static int F_214 ( struct V_2 * V_3 , struct V_9 * V_378 )
{
struct V_19 * V_20 ;
int V_268 ;
T_1 V_10 , V_385 , V_386 ;
int V_430 = 0 ;
int V_387 ;
int V_431 = 0 ;
V_385 = V_378 -> V_13 & ~ ( ( T_1 ) V_14 - 1 ) ;
V_10 = F_145 ( V_3 , V_385 ,
0 , & V_268 , NULL ) ;
V_386 = V_378 -> V_13 + ( V_378 -> V_12 >> 9 ) ;
for (; V_385 < V_386 ;
V_385 += V_14 ,
V_10 += V_14 ,
V_430 ++ ) {
if ( V_430 < F_4 ( V_378 ) )
continue;
V_20 = F_54 ( V_3 , V_10 , 0 , 1 , 0 ) ;
if ( ! V_20 ) {
F_7 ( V_378 , V_430 ) ;
V_3 -> V_56 = V_378 ;
return V_431 ;
}
if ( ! F_148 ( V_20 , V_378 , V_268 , 0 ) ) {
F_26 ( V_20 ) ;
F_7 ( V_378 , V_430 ) ;
V_3 -> V_56 = V_378 ;
return V_431 ;
}
F_166 ( V_20 ) ;
F_26 ( V_20 ) ;
V_431 ++ ;
}
F_55 ( & V_3 -> V_59 ) ;
V_387 = F_5 ( V_378 ) ;
F_58 ( & V_3 -> V_59 ) ;
if ( V_387 == 0 )
F_12 ( V_378 , 0 ) ;
if ( F_16 ( & V_3 -> V_376 ) )
F_25 ( & V_3 -> V_55 ) ;
return V_431 ;
}
static void F_215 ( struct V_48 * V_48 )
{
struct V_19 * V_20 ;
struct V_2 * V_3 = V_48 -> V_262 ;
int V_431 ;
struct V_432 V_433 ;
F_30 ( L_58 ) ;
F_64 ( V_48 ) ;
F_216 ( & V_433 ) ;
V_431 = 0 ;
F_55 ( & V_3 -> V_59 ) ;
while ( 1 ) {
struct V_9 * V_9 ;
if ( F_19 ( & V_48 -> V_434 ) == 0 &&
! F_18 ( & V_3 -> V_46 ) ) {
V_3 -> V_308 ++ ;
F_58 ( & V_3 -> V_59 ) ;
F_217 ( V_48 -> V_307 ) ;
F_55 ( & V_3 -> V_59 ) ;
V_3 -> V_45 = V_3 -> V_308 ;
F_169 ( V_3 ) ;
}
if ( F_19 ( & V_48 -> V_434 ) == 0 )
F_168 ( V_3 ) ;
while ( ( V_9 = F_178 ( V_3 ) ) ) {
int V_435 ;
F_58 ( & V_3 -> V_59 ) ;
V_435 = F_214 ( V_3 , V_9 ) ;
F_55 ( & V_3 -> V_59 ) ;
if ( ! V_435 )
break;
V_431 ++ ;
}
V_20 = F_188 ( V_3 ) ;
if ( ! V_20 )
break;
F_58 ( & V_3 -> V_59 ) ;
V_431 ++ ;
F_166 ( V_20 ) ;
F_26 ( V_20 ) ;
F_218 () ;
if ( V_48 -> V_58 & ~ ( 1 << V_436 ) )
F_64 ( V_48 ) ;
F_55 ( & V_3 -> V_59 ) ;
}
F_30 ( L_59 , V_431 ) ;
F_58 ( & V_3 -> V_59 ) ;
F_219 () ;
F_220 ( & V_433 ) ;
F_30 ( L_60 ) ;
}
static T_5
F_221 ( struct V_48 * V_48 , char * V_65 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
if ( V_3 )
return sprintf ( V_65 , L_61 , V_3 -> V_97 ) ;
else
return 0 ;
}
int
F_222 ( struct V_48 * V_48 , int V_437 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
int V_236 ;
if ( V_437 <= 16 || V_437 > 32768 )
return - V_438 ;
while ( V_437 < V_3 -> V_97 ) {
if ( F_136 ( V_3 ) )
V_3 -> V_97 -- ;
else
break;
}
V_236 = F_125 ( V_48 ) ;
if ( V_236 )
return V_236 ;
while ( V_437 > V_3 -> V_97 ) {
if ( F_111 ( V_3 ) )
V_3 -> V_97 ++ ;
else break;
}
return 0 ;
}
static T_5
F_223 ( struct V_48 * V_48 , const char * V_65 , T_4 V_155 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
unsigned long V_439 ;
int V_236 ;
if ( V_155 >= V_440 )
return - V_438 ;
if ( ! V_3 )
return - V_441 ;
if ( F_224 ( V_65 , 10 , & V_439 ) )
return - V_438 ;
V_236 = F_222 ( V_48 , V_439 ) ;
if ( V_236 )
return V_236 ;
return V_155 ;
}
static T_5
F_225 ( struct V_48 * V_48 , char * V_65 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
if ( V_3 )
return sprintf ( V_65 , L_61 , V_3 -> V_384 ) ;
else
return 0 ;
}
static T_5
F_226 ( struct V_48 * V_48 , const char * V_65 , T_4 V_155 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
unsigned long V_439 ;
if ( V_155 >= V_440 )
return - V_438 ;
if ( ! V_3 )
return - V_441 ;
if ( F_224 ( V_65 , 10 , & V_439 ) )
return - V_438 ;
if ( V_439 > V_3 -> V_97 )
return - V_438 ;
V_3 -> V_384 = V_439 ;
return V_155 ;
}
static T_5
F_227 ( struct V_48 * V_48 , char * V_65 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
if ( V_3 )
return sprintf ( V_65 , L_61 , F_19 ( & V_3 -> V_39 ) ) ;
else
return 0 ;
}
static T_1
F_201 ( struct V_48 * V_48 , T_1 V_11 , int V_25 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
if ( ! V_11 )
V_11 = V_48 -> V_418 ;
if ( ! V_25 )
V_25 = F_228 ( V_3 -> V_25 , V_3 -> V_74 ) ;
V_11 &= ~ ( ( T_1 ) V_48 -> V_278 - 1 ) ;
V_11 &= ~ ( ( T_1 ) V_48 -> V_373 - 1 ) ;
return V_11 * ( V_25 - V_3 -> V_92 ) ;
}
static void F_229 ( struct V_2 * V_3 )
{
struct V_172 * V_173 ;
unsigned long V_206 ;
if ( ! V_3 -> V_173 )
return;
F_132 () ;
F_230 (cpu) {
V_173 = F_102 ( V_3 -> V_173 , V_206 ) ;
F_231 ( V_173 -> V_202 ) ;
F_131 ( V_173 -> V_174 ) ;
}
#ifdef F_232
F_233 ( & V_3 -> V_442 ) ;
#endif
F_135 () ;
F_234 ( V_3 -> V_173 ) ;
}
static void F_235 ( struct V_2 * V_3 )
{
F_137 ( V_3 ) ;
F_229 ( V_3 ) ;
F_131 ( V_3 -> V_23 ) ;
F_131 ( V_3 -> V_8 ) ;
F_131 ( V_3 ) ;
}
static int F_236 ( struct V_443 * V_444 , unsigned long V_445 ,
void * V_446 )
{
struct V_2 * V_3 = F_237 ( V_444 , struct V_2 , V_442 ) ;
long V_206 = ( long ) V_446 ;
struct V_172 * V_173 = F_102 ( V_3 -> V_173 , V_206 ) ;
switch ( V_445 ) {
case V_447 :
case V_448 :
if ( V_3 -> V_205 == 6 && ! V_173 -> V_202 )
V_173 -> V_202 = F_41 ( V_71 ) ;
if ( ! V_173 -> V_174 )
V_173 -> V_174 = F_134 ( V_3 -> F_122 , V_71 ) ;
if ( ! V_173 -> V_174 ||
( V_3 -> V_205 == 6 && ! V_173 -> V_202 ) ) {
F_231 ( V_173 -> V_202 ) ;
F_131 ( V_173 -> V_174 ) ;
F_238 ( L_62 ,
V_133 , V_206 ) ;
return F_239 ( - V_237 ) ;
}
break;
case V_449 :
case V_450 :
F_231 ( V_173 -> V_202 ) ;
F_131 ( V_173 -> V_174 ) ;
V_173 -> V_202 = NULL ;
V_173 -> V_174 = NULL ;
break;
default:
break;
}
return V_451 ;
}
static int F_240 ( struct V_2 * V_3 )
{
unsigned long V_206 ;
struct V_65 * V_202 ;
struct V_172 T_6 * V_452 ;
void * V_174 ;
int V_236 ;
V_452 = F_241 ( struct V_172 ) ;
if ( ! V_452 )
return - V_237 ;
V_3 -> V_173 = V_452 ;
F_132 () ;
V_236 = 0 ;
F_133 (cpu) {
if ( V_3 -> V_205 == 6 ) {
V_202 = F_41 ( V_71 ) ;
if ( ! V_202 ) {
V_236 = - V_237 ;
break;
}
F_102 ( V_3 -> V_173 , V_206 ) -> V_202 = V_202 ;
}
V_174 = F_134 ( V_3 -> F_122 , V_71 ) ;
if ( ! V_174 ) {
V_236 = - V_237 ;
break;
}
F_102 ( V_3 -> V_173 , V_206 ) -> V_174 = V_174 ;
}
#ifdef F_232
V_3 -> V_442 . V_453 = F_236 ;
V_3 -> V_442 . V_454 = 0 ;
if ( V_236 == 0 )
V_236 = F_242 ( & V_3 -> V_442 ) ;
#endif
F_135 () ;
return V_236 ;
}
static struct V_2 * F_243 ( struct V_48 * V_48 )
{
struct V_2 * V_3 ;
int V_455 , V_456 , V_457 ;
struct V_86 * V_87 ;
struct V_234 * V_24 ;
if ( V_48 -> V_458 != 5
&& V_48 -> V_458 != 4
&& V_48 -> V_458 != 6 ) {
F_44 ( V_81 L_63 ,
F_120 ( V_48 ) , V_48 -> V_458 ) ;
return F_244 ( - V_459 ) ;
}
if ( ( V_48 -> V_458 == 5
&& ! F_245 ( V_48 -> V_460 ) ) ||
( V_48 -> V_458 == 6
&& ! F_246 ( V_48 -> V_460 ) ) ) {
F_44 ( V_81 L_64 ,
F_120 ( V_48 ) , V_48 -> V_460 ) ;
return F_244 ( - V_459 ) ;
}
if ( V_48 -> V_458 == 6 && V_48 -> V_25 < 4 ) {
F_44 ( V_81 L_65 ,
F_120 ( V_48 ) , V_48 -> V_25 ) ;
return F_244 ( - V_438 ) ;
}
if ( ! V_48 -> V_373 ||
( V_48 -> V_373 << 9 ) % V_440 ||
! F_247 ( V_48 -> V_373 ) ) {
F_44 ( V_81 L_66 ,
F_120 ( V_48 ) , V_48 -> V_373 << 9 ) ;
return F_244 ( - V_438 ) ;
}
V_3 = F_130 ( sizeof( struct V_2 ) , V_71 ) ;
if ( V_3 == NULL )
goto abort;
F_248 ( & V_3 -> V_59 ) ;
F_114 ( & V_3 -> V_55 ) ;
F_114 ( & V_3 -> V_217 ) ;
F_117 ( & V_3 -> V_47 ) ;
F_117 ( & V_3 -> V_362 ) ;
F_117 ( & V_3 -> V_42 ) ;
F_117 ( & V_3 -> V_46 ) ;
F_117 ( & V_3 -> V_54 ) ;
F_116 ( & V_3 -> V_39 , 0 ) ;
F_116 ( & V_3 -> V_51 , 0 ) ;
F_116 ( & V_3 -> V_376 , 0 ) ;
V_3 -> V_384 = V_461 ;
V_3 -> V_317 = V_48 -> V_317 - 1 ;
V_3 -> V_25 = V_48 -> V_25 ;
if ( V_48 -> V_90 == V_91 )
V_3 -> V_74 = V_48 -> V_25 ;
else
V_3 -> V_74 = V_48 -> V_25 - V_48 -> V_393 ;
V_457 = F_119 ( V_3 -> V_25 , V_3 -> V_74 ) ;
V_3 -> F_122 = F_122 ( V_457 ) ;
V_3 -> V_23 = F_130 ( V_457 * sizeof( struct V_234 ) ,
V_71 ) ;
if ( ! V_3 -> V_23 )
goto abort;
V_3 -> V_48 = V_48 ;
if ( ( V_3 -> V_8 = F_130 ( V_440 , V_71 ) ) == NULL )
goto abort;
V_3 -> V_205 = V_48 -> V_458 ;
if ( F_240 ( V_3 ) != 0 )
goto abort;
F_30 ( L_67 , F_120 ( V_48 ) ) ;
F_129 (rdev, &mddev->disks, same_set) {
V_455 = V_87 -> V_455 ;
if ( V_455 >= V_457
|| V_455 < 0 )
continue;
V_24 = V_3 -> V_23 + V_455 ;
if ( F_14 ( V_462 , & V_87 -> V_58 ) ) {
if ( V_24 -> V_117 )
goto abort;
V_24 -> V_117 = V_87 ;
} else {
if ( V_24 -> V_87 )
goto abort;
V_24 -> V_87 = V_87 ;
}
if ( F_14 ( V_89 , & V_87 -> V_58 ) ) {
char V_241 [ V_242 ] ;
F_44 ( V_244 L_68
L_69 ,
F_120 ( V_48 ) , F_139 ( V_87 -> V_130 , V_241 ) , V_455 ) ;
} else if ( V_87 -> V_463 != V_455 )
V_3 -> V_427 = 1 ;
}
V_3 -> V_278 = V_48 -> V_373 ;
V_3 -> V_205 = V_48 -> V_458 ;
if ( V_3 -> V_205 == 6 )
V_3 -> V_92 = 2 ;
else
V_3 -> V_92 = 1 ;
V_3 -> V_274 = V_48 -> V_460 ;
V_3 -> V_97 = V_464 ;
V_3 -> V_392 = V_48 -> V_90 ;
if ( V_3 -> V_392 != V_91 ) {
V_3 -> V_277 = V_48 -> V_278 ;
V_3 -> V_275 = V_48 -> V_465 ;
}
V_456 = V_3 -> V_97 * ( sizeof( struct V_19 ) +
V_457 * ( ( sizeof( struct V_9 ) + V_440 ) ) ) / 1024 ;
if ( F_118 ( V_3 , V_3 -> V_97 ) ) {
F_44 ( V_81
L_70 ,
F_120 ( V_48 ) , V_456 ) ;
goto abort;
} else
F_44 ( V_244 L_71 ,
F_120 ( V_48 ) , V_456 ) ;
V_3 -> V_49 = F_249 ( F_215 , V_48 , NULL ) ;
if ( ! V_3 -> V_49 ) {
F_44 ( V_81
L_72 ,
F_120 ( V_48 ) ) ;
goto abort;
}
return V_3 ;
abort:
if ( V_3 ) {
F_235 ( V_3 ) ;
return F_244 ( - V_459 ) ;
} else
return F_244 ( - V_237 ) ;
}
static int F_250 ( int V_455 , int V_466 , int V_25 , int V_92 )
{
switch ( V_466 ) {
case V_284 :
if ( V_455 < V_92 )
return 1 ;
break;
case V_285 :
if ( V_455 >= V_25 - V_92 )
return 1 ;
break;
case V_293 :
if ( V_455 == 0 ||
V_455 == V_25 - 1 )
return 1 ;
break;
case V_289 :
case V_290 :
case V_291 :
case V_292 :
if ( V_455 == V_25 - 1 )
return 1 ;
}
return 0 ;
}
static int F_251 ( struct V_48 * V_48 )
{
struct V_2 * V_3 ;
int V_467 = 0 ;
int V_468 = 0 ;
struct V_86 * V_87 ;
T_1 V_469 = 0 ;
int V_67 ;
if ( V_48 -> V_321 != V_91 )
F_44 ( V_470 L_73
L_74 ,
F_120 ( V_48 ) ) ;
if ( V_48 -> V_90 != V_91 ) {
T_1 V_471 , V_472 ;
int V_473 ;
int V_92 = ( V_48 -> V_205 == 6 ? 2 : 1 ) ;
if ( V_48 -> V_458 != V_48 -> V_205 ) {
F_44 ( V_81 L_75
L_76 ,
F_120 ( V_48 ) ) ;
return - V_438 ;
}
V_473 = V_48 -> V_25 - V_48 -> V_393 ;
V_471 = V_48 -> V_90 ;
if ( F_146 ( V_471 , V_48 -> V_373 *
( V_48 -> V_25 - V_92 ) ) ) {
F_44 ( V_81 L_77
L_78 , F_120 ( V_48 ) ) ;
return - V_438 ;
}
V_469 = V_471 * V_48 -> V_373 ;
V_472 = V_48 -> V_90 ;
F_146 ( V_472 , V_48 -> V_278 *
( V_473 - V_92 ) ) ;
if ( V_48 -> V_393 == 0 ) {
if ( ( V_471 * V_48 -> V_373 !=
V_472 * V_48 -> V_278 ) ||
V_48 -> V_358 == 0 ) {
F_44 ( V_81 L_79
L_80 ,
F_120 ( V_48 ) ) ;
return - V_438 ;
}
} else if ( V_48 -> V_393 < 0
? ( V_471 * V_48 -> V_373 <=
V_472 * V_48 -> V_278 )
: ( V_471 * V_48 -> V_373 >=
V_472 * V_48 -> V_278 ) ) {
F_44 ( V_81 L_81
L_82 ,
F_120 ( V_48 ) ) ;
return - V_438 ;
}
F_44 ( V_244 L_83 ,
F_120 ( V_48 ) ) ;
} else {
F_17 ( V_48 -> V_205 != V_48 -> V_458 ) ;
F_17 ( V_48 -> V_465 != V_48 -> V_460 ) ;
F_17 ( V_48 -> V_278 != V_48 -> V_373 ) ;
F_17 ( V_48 -> V_393 != 0 ) ;
}
if ( V_48 -> V_262 == NULL )
V_3 = F_243 ( V_48 ) ;
else
V_3 = V_48 -> V_262 ;
if ( F_252 ( V_3 ) )
return F_253 ( V_3 ) ;
V_48 -> V_49 = V_3 -> V_49 ;
V_3 -> V_49 = NULL ;
V_48 -> V_262 = V_3 ;
for ( V_67 = 0 ; V_67 < V_3 -> V_25 && V_3 -> V_74 ;
V_67 ++ ) {
V_87 = V_3 -> V_23 [ V_67 ] . V_87 ;
if ( ! V_87 && V_3 -> V_23 [ V_67 ] . V_117 ) {
V_87 = V_3 -> V_23 [ V_67 ] . V_117 ;
V_3 -> V_23 [ V_67 ] . V_117 = NULL ;
F_21 ( V_462 , & V_87 -> V_58 ) ;
V_3 -> V_23 [ V_67 ] . V_87 = V_87 ;
}
if ( ! V_87 )
continue;
if ( V_3 -> V_23 [ V_67 ] . V_117 &&
V_3 -> V_392 != V_91 ) {
F_44 ( V_81 L_84
L_85 ) ;
goto abort;
}
if ( F_14 ( V_89 , & V_87 -> V_58 ) ) {
V_467 ++ ;
continue;
}
if ( V_48 -> V_474 == 0 &&
V_48 -> V_475 > 90 )
V_87 -> V_320 = V_469 ;
if ( V_87 -> V_320 < V_469 ) {
if ( ! F_250 ( V_87 -> V_455 ,
V_3 -> V_274 ,
V_3 -> V_25 ,
V_3 -> V_92 ) )
continue;
}
if ( ! F_250 ( V_87 -> V_455 ,
V_3 -> V_275 ,
V_3 -> V_74 ,
V_3 -> V_92 ) )
continue;
V_468 ++ ;
}
V_48 -> V_84 = F_49 ( V_3 ) ;
if ( F_53 ( V_3 ) ) {
F_44 ( V_81 L_86
L_87 ,
F_120 ( V_48 ) , V_48 -> V_84 , V_3 -> V_25 ) ;
goto abort;
}
V_48 -> V_418 &= ~ ( V_48 -> V_278 - 1 ) ;
V_48 -> V_476 = V_48 -> V_418 ;
if ( V_48 -> V_84 > V_468 &&
V_48 -> V_321 != V_91 ) {
if ( V_48 -> V_477 )
F_44 ( V_250
L_88
L_89 ,
F_120 ( V_48 ) ) ;
else {
F_44 ( V_81
L_90 ,
F_120 ( V_48 ) ) ;
goto abort;
}
}
if ( V_48 -> V_84 == 0 )
F_44 ( V_244 L_91
L_92 , F_120 ( V_48 ) , V_3 -> V_205 ,
V_48 -> V_25 - V_48 -> V_84 , V_48 -> V_25 ,
V_48 -> V_460 ) ;
else
F_44 ( V_266 L_93
L_94 ,
F_120 ( V_48 ) , V_3 -> V_205 ,
V_48 -> V_25 - V_48 -> V_84 ,
V_48 -> V_25 , V_48 -> V_460 ) ;
F_254 ( V_3 ) ;
if ( V_3 -> V_392 != V_91 ) {
V_3 -> V_394 = V_3 -> V_392 ;
F_116 ( & V_3 -> V_360 , 0 ) ;
F_21 ( V_428 , & V_48 -> V_256 ) ;
F_21 ( V_333 , & V_48 -> V_256 ) ;
F_63 ( V_425 , & V_48 -> V_256 ) ;
F_63 ( V_478 , & V_48 -> V_256 ) ;
V_48 -> V_479 = F_249 ( V_480 , V_48 ,
L_95 ) ;
}
if ( V_48 -> V_481 == & V_482 )
V_48 -> V_481 = NULL ;
else if ( V_48 -> V_413 . V_483 &&
F_255 ( & V_48 -> V_413 , & V_482 ) )
F_44 ( V_250
L_96 ,
F_120 ( V_48 ) ) ;
F_256 ( V_48 , F_201 ( V_48 , 0 , 0 ) ) ;
if ( V_48 -> V_484 ) {
int V_485 ;
int V_279 = V_3 -> V_74 - V_3 -> V_92 ;
int V_269 = V_279 *
( ( V_48 -> V_278 << 9 ) / V_440 ) ;
if ( V_48 -> V_484 -> V_486 . V_487 < 2 * V_269 )
V_48 -> V_484 -> V_486 . V_487 = 2 * V_269 ;
F_257 ( V_48 -> V_484 , F_174 ) ;
V_48 -> V_484 -> V_486 . V_488 = V_48 ;
V_48 -> V_484 -> V_486 . V_489 = F_172 ;
V_485 = V_48 -> V_278 << 9 ;
F_258 ( V_48 -> V_484 , V_485 ) ;
F_259 ( V_48 -> V_484 , V_485 *
( V_3 -> V_25 - V_3 -> V_92 ) ) ;
F_129 (rdev, &mddev->disks, same_set)
F_260 ( V_48 -> V_227 , V_87 -> V_130 ,
V_87 -> V_134 << 9 ) ;
}
return 0 ;
abort:
F_261 ( & V_48 -> V_49 ) ;
F_254 ( V_3 ) ;
F_235 ( V_3 ) ;
V_48 -> V_262 = NULL ;
F_44 ( V_266 L_97 , F_120 ( V_48 ) ) ;
return - V_459 ;
}
static int F_262 ( struct V_48 * V_48 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
F_261 ( & V_48 -> V_49 ) ;
if ( V_48 -> V_484 )
V_48 -> V_484 -> V_486 . V_489 = NULL ;
F_235 ( V_3 ) ;
V_48 -> V_262 = NULL ;
V_48 -> V_481 = & V_482 ;
return 0 ;
}
static void F_263 ( struct V_490 * V_491 , struct V_48 * V_48 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
int V_67 ;
F_264 ( V_491 , L_98 , V_48 -> V_205 ,
V_48 -> V_278 / 2 , V_48 -> V_465 ) ;
F_264 ( V_491 , L_99 , V_3 -> V_25 , V_3 -> V_25 - V_48 -> V_84 ) ;
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ )
F_264 ( V_491 , L_100 ,
V_3 -> V_23 [ V_67 ] . V_87 &&
F_14 ( V_89 , & V_3 -> V_23 [ V_67 ] . V_87 -> V_58 ) ? L_101 : L_102 ) ;
F_264 ( V_491 , L_103 ) ;
}
static void F_254 ( struct V_2 * V_3 )
{
int V_67 ;
struct V_234 * V_492 ;
F_44 ( V_493 L_104 ) ;
if ( ! V_3 ) {
F_44 ( L_105 ) ;
return;
}
F_44 ( V_493 L_106 , V_3 -> V_205 ,
V_3 -> V_25 ,
V_3 -> V_25 - V_3 -> V_48 -> V_84 ) ;
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ ) {
char V_241 [ V_242 ] ;
V_492 = V_3 -> V_23 + V_67 ;
if ( V_492 -> V_87 )
F_44 ( V_493 L_107 ,
V_67 , ! F_14 ( V_88 , & V_492 -> V_87 -> V_58 ) ,
F_139 ( V_492 -> V_87 -> V_130 , V_241 ) ) ;
}
}
static int F_265 ( struct V_48 * V_48 )
{
int V_67 ;
struct V_2 * V_3 = V_48 -> V_262 ;
struct V_234 * V_492 ;
int V_27 = 0 ;
unsigned long V_58 ;
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ ) {
V_492 = V_3 -> V_23 + V_67 ;
if ( V_492 -> V_117
&& V_492 -> V_117 -> V_320 == V_91
&& ! F_14 ( V_88 , & V_492 -> V_117 -> V_58 )
&& ! F_142 ( V_89 , & V_492 -> V_117 -> V_58 ) ) {
if ( ! V_492 -> V_87
|| ! F_23 ( V_89 , & V_492 -> V_87 -> V_58 ) )
V_27 ++ ;
if ( V_492 -> V_87 ) {
F_63 ( V_88 , & V_492 -> V_87 -> V_58 ) ;
F_266 (
V_492 -> V_87 -> V_494 ) ;
}
F_266 ( V_492 -> V_117 -> V_494 ) ;
} else if ( V_492 -> V_87
&& V_492 -> V_87 -> V_320 == V_91
&& ! F_14 ( V_88 , & V_492 -> V_87 -> V_58 )
&& ! F_142 ( V_89 , & V_492 -> V_87 -> V_58 ) ) {
V_27 ++ ;
F_266 ( V_492 -> V_87 -> V_494 ) ;
}
}
F_27 ( & V_3 -> V_59 , V_58 ) ;
V_48 -> V_84 = F_49 ( V_3 ) ;
F_28 ( & V_3 -> V_59 , V_58 ) ;
F_254 ( V_3 ) ;
return V_27 ;
}
static int F_267 ( struct V_48 * V_48 , struct V_86 * V_87 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
int V_236 = 0 ;
int V_495 = V_87 -> V_455 ;
struct V_86 * * V_496 ;
struct V_234 * V_66 = V_3 -> V_23 + V_495 ;
F_254 ( V_3 ) ;
if ( V_87 == V_66 -> V_87 )
V_496 = & V_66 -> V_87 ;
else if ( V_87 == V_66 -> V_117 )
V_496 = & V_66 -> V_117 ;
else
return 0 ;
if ( V_495 >= V_3 -> V_25 &&
V_3 -> V_392 == V_91 )
F_21 ( V_89 , & V_87 -> V_58 ) ;
if ( F_14 ( V_89 , & V_87 -> V_58 ) ||
F_19 ( & V_87 -> V_119 ) ) {
V_236 = - V_497 ;
goto abort;
}
if ( ! F_14 ( V_88 , & V_87 -> V_58 ) &&
V_48 -> V_317 != V_3 -> V_317 &&
! F_53 ( V_3 ) &&
( ! V_66 -> V_117 || V_66 -> V_117 == V_87 ) &&
V_495 < V_3 -> V_25 ) {
V_236 = - V_497 ;
goto abort;
}
* V_496 = NULL ;
F_268 () ;
if ( F_19 ( & V_87 -> V_119 ) ) {
V_236 = - V_497 ;
* V_496 = V_87 ;
} else if ( V_66 -> V_117 ) {
V_66 -> V_87 = V_66 -> V_117 ;
F_21 ( V_462 , & V_66 -> V_117 -> V_58 ) ;
F_61 () ;
V_66 -> V_117 = NULL ;
F_21 ( V_254 , & V_87 -> V_58 ) ;
} else
F_21 ( V_254 , & V_87 -> V_58 ) ;
abort:
F_254 ( V_3 ) ;
return V_236 ;
}
static int F_269 ( struct V_48 * V_48 , struct V_86 * V_87 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
int V_236 = - V_498 ;
int V_24 ;
struct V_234 * V_66 ;
int V_62 = 0 ;
int V_499 = V_3 -> V_25 - 1 ;
if ( V_48 -> V_317 == V_3 -> V_317 )
return - V_497 ;
if ( F_53 ( V_3 ) )
return - V_438 ;
if ( V_87 -> V_455 >= 0 )
V_62 = V_499 = V_87 -> V_455 ;
if ( V_87 -> V_463 >= 0 &&
V_87 -> V_463 >= V_62 &&
V_3 -> V_23 [ V_87 -> V_463 ] . V_87 == NULL )
V_24 = V_87 -> V_463 ;
else
V_24 = V_62 ;
for ( ; V_24 <= V_499 ; V_24 ++ ) {
V_66 = V_3 -> V_23 + V_24 ;
if ( V_66 -> V_87 == NULL ) {
F_21 ( V_89 , & V_87 -> V_58 ) ;
V_87 -> V_455 = V_24 ;
V_236 = 0 ;
if ( V_87 -> V_463 != V_24 )
V_3 -> V_427 = 1 ;
F_270 ( V_66 -> V_87 , V_87 ) ;
break;
}
if ( F_14 ( V_254 , & V_66 -> V_87 -> V_58 ) &&
V_66 -> V_117 == NULL ) {
F_21 ( V_89 , & V_87 -> V_58 ) ;
F_63 ( V_462 , & V_87 -> V_58 ) ;
V_87 -> V_455 = V_24 ;
V_236 = 0 ;
V_3 -> V_427 = 1 ;
F_270 ( V_66 -> V_117 , V_87 ) ;
break;
}
}
F_254 ( V_3 ) ;
return V_236 ;
}
static int F_271 ( struct V_48 * V_48 , T_1 V_11 )
{
V_11 &= ~ ( ( T_1 ) V_48 -> V_278 - 1 ) ;
F_256 ( V_48 , F_201 ( V_48 , V_11 ,
V_48 -> V_25 ) ) ;
if ( V_48 -> V_500 >
F_201 ( V_48 , V_11 , V_48 -> V_25 ) )
return - V_438 ;
F_272 ( V_48 -> V_227 , V_48 -> V_500 ) ;
F_273 ( V_48 -> V_227 ) ;
if ( V_11 > V_48 -> V_418 &&
V_48 -> V_321 > V_48 -> V_418 ) {
V_48 -> V_321 = V_48 -> V_418 ;
F_63 ( V_255 , & V_48 -> V_256 ) ;
}
V_48 -> V_418 = V_11 ;
V_48 -> V_476 = V_11 ;
return 0 ;
}
static int F_274 ( struct V_48 * V_48 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
if ( ( ( V_48 -> V_278 << 9 ) / V_140 ) * 4
> V_3 -> V_97 ||
( ( V_48 -> V_373 << 9 ) / V_140 ) * 4
> V_3 -> V_97 ) {
F_44 ( V_250 L_108 ,
F_120 ( V_48 ) ,
( ( F_119 ( V_48 -> V_278 , V_48 -> V_373 ) << 9 )
/ V_140 ) * 4 ) ;
return 0 ;
}
return 1 ;
}
static int F_275 ( struct V_48 * V_48 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
if ( V_48 -> V_393 == 0 &&
V_48 -> V_460 == V_48 -> V_465 &&
V_48 -> V_373 == V_48 -> V_278 )
return 0 ;
if ( V_48 -> V_307 )
return - V_497 ;
if ( F_53 ( V_3 ) )
return - V_438 ;
if ( V_48 -> V_393 < 0 ) {
int F_228 = 2 ;
if ( V_48 -> V_205 == 6 )
F_228 = 4 ;
if ( V_48 -> V_25 + V_48 -> V_393 < F_228 )
return - V_438 ;
}
if ( ! F_274 ( V_48 ) )
return - V_501 ;
return F_123 ( V_3 , V_3 -> V_25 + V_48 -> V_393 ) ;
}
static int F_276 ( struct V_48 * V_48 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
struct V_86 * V_87 ;
int V_502 = 0 ;
unsigned long V_58 ;
if ( F_14 ( V_478 , & V_48 -> V_256 ) )
return - V_497 ;
if ( ! F_274 ( V_48 ) )
return - V_501 ;
F_129 (rdev, &mddev->disks, same_set)
if ( ! F_14 ( V_89 , & V_87 -> V_58 )
&& ! F_14 ( V_88 , & V_87 -> V_58 ) )
V_502 ++ ;
if ( V_502 - V_48 -> V_84 < V_48 -> V_393 - V_3 -> V_92 )
return - V_438 ;
if ( F_201 ( V_48 , 0 , V_3 -> V_25 + V_48 -> V_393 )
< V_48 -> V_500 ) {
F_44 ( V_81 L_109
L_110 , F_120 ( V_48 ) ) ;
return - V_438 ;
}
F_116 ( & V_3 -> V_360 , 0 ) ;
F_55 ( & V_3 -> V_59 ) ;
V_3 -> V_74 = V_3 -> V_25 ;
V_3 -> V_25 += V_48 -> V_393 ;
V_3 -> V_277 = V_3 -> V_278 ;
V_3 -> V_278 = V_48 -> V_373 ;
V_3 -> V_275 = V_3 -> V_274 ;
V_3 -> V_274 = V_48 -> V_460 ;
if ( V_48 -> V_393 < 0 )
V_3 -> V_392 = F_201 ( V_48 , 0 , 0 ) ;
else
V_3 -> V_392 = 0 ;
V_3 -> V_394 = V_3 -> V_392 ;
V_3 -> V_73 ++ ;
F_58 ( & V_3 -> V_59 ) ;
if ( V_48 -> V_393 >= 0 ) {
int V_503 = 0 ;
F_129 (rdev, &mddev->disks, same_set)
if ( V_87 -> V_455 < 0 &&
! F_14 ( V_88 , & V_87 -> V_58 ) ) {
if ( F_269 ( V_48 , V_87 ) == 0 ) {
if ( V_87 -> V_455
>= V_3 -> V_74 ) {
F_63 ( V_89 , & V_87 -> V_58 ) ;
V_503 ++ ;
} else
V_87 -> V_320 = 0 ;
if ( F_277 ( V_48 , V_87 ) )
;
}
} else if ( V_87 -> V_455 >= V_3 -> V_74
&& ! F_14 ( V_88 , & V_87 -> V_58 ) ) {
F_63 ( V_89 , & V_87 -> V_58 ) ;
V_503 ++ ;
}
F_27 ( & V_3 -> V_59 , V_58 ) ;
V_48 -> V_84 = F_49 ( V_3 ) ;
F_28 ( & V_3 -> V_59 , V_58 ) ;
}
V_48 -> V_25 = V_3 -> V_25 ;
V_48 -> V_90 = V_3 -> V_392 ;
F_63 ( V_265 , & V_48 -> V_58 ) ;
F_21 ( V_428 , & V_48 -> V_256 ) ;
F_21 ( V_333 , & V_48 -> V_256 ) ;
F_63 ( V_425 , & V_48 -> V_256 ) ;
F_63 ( V_478 , & V_48 -> V_256 ) ;
V_48 -> V_479 = F_249 ( V_480 , V_48 ,
L_95 ) ;
if ( ! V_48 -> V_479 ) {
V_48 -> V_256 = 0 ;
F_55 ( & V_3 -> V_59 ) ;
V_48 -> V_25 = V_3 -> V_25 = V_3 -> V_74 ;
V_3 -> V_392 = V_91 ;
F_58 ( & V_3 -> V_59 ) ;
return - V_504 ;
}
V_3 -> V_415 = V_414 ;
F_22 ( V_48 -> V_479 ) ;
F_278 ( V_48 ) ;
return 0 ;
}
static void F_208 ( struct V_2 * V_3 )
{
if ( ! F_14 ( V_263 , & V_3 -> V_48 -> V_256 ) ) {
F_55 ( & V_3 -> V_59 ) ;
V_3 -> V_74 = V_3 -> V_25 ;
V_3 -> V_392 = V_91 ;
F_58 ( & V_3 -> V_59 ) ;
F_25 ( & V_3 -> V_217 ) ;
if ( V_3 -> V_48 -> V_484 ) {
int V_279 = V_3 -> V_25 - V_3 -> V_92 ;
int V_269 = V_279 * ( ( V_3 -> V_278 << 9 )
/ V_440 ) ;
if ( V_3 -> V_48 -> V_484 -> V_486 . V_487 < 2 * V_269 )
V_3 -> V_48 -> V_484 -> V_486 . V_487 = 2 * V_269 ;
}
}
}
static void F_279 ( struct V_48 * V_48 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
if ( ! F_14 ( V_263 , & V_48 -> V_256 ) ) {
if ( V_48 -> V_393 > 0 ) {
F_256 ( V_48 , F_201 ( V_48 , 0 , 0 ) ) ;
F_272 ( V_48 -> V_227 , V_48 -> V_500 ) ;
F_273 ( V_48 -> V_227 ) ;
} else {
int V_505 ;
F_55 ( & V_3 -> V_59 ) ;
V_48 -> V_84 = F_49 ( V_3 ) ;
F_58 ( & V_3 -> V_59 ) ;
for ( V_505 = V_3 -> V_25 ;
V_505 < V_3 -> V_25 - V_48 -> V_393 ;
V_505 ++ ) {
struct V_86 * V_87 = V_3 -> V_23 [ V_505 ] . V_87 ;
if ( V_87 &&
F_267 ( V_48 , V_87 ) == 0 ) {
F_280 ( V_48 , V_87 ) ;
V_87 -> V_455 = - 1 ;
}
}
}
V_48 -> V_465 = V_3 -> V_274 ;
V_48 -> V_278 = V_3 -> V_278 ;
V_48 -> V_90 = V_91 ;
V_48 -> V_393 = 0 ;
}
}
static void F_281 ( struct V_48 * V_48 , int V_36 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
switch( V_36 ) {
case 2 :
F_25 ( & V_3 -> V_217 ) ;
break;
case 1 :
F_55 ( & V_3 -> V_59 ) ;
V_3 -> V_95 = 2 ;
F_56 ( V_3 -> V_55 ,
F_19 ( & V_3 -> V_39 ) == 0 &&
F_19 ( & V_3 -> V_376 ) == 0 ,
V_3 -> V_59 , ) ;
V_3 -> V_95 = 1 ;
F_58 ( & V_3 -> V_59 ) ;
F_25 ( & V_3 -> V_217 ) ;
break;
case 0 :
F_55 ( & V_3 -> V_59 ) ;
V_3 -> V_95 = 0 ;
F_25 ( & V_3 -> V_55 ) ;
F_25 ( & V_3 -> V_217 ) ;
F_58 ( & V_3 -> V_59 ) ;
break;
}
}
static void * F_282 ( struct V_48 * V_48 , int V_205 )
{
struct V_506 * V_507 = V_48 -> V_262 ;
T_1 V_11 ;
if ( V_507 -> V_508 > 1 ) {
F_44 ( V_81 L_111 ,
F_120 ( V_48 ) ) ;
return F_244 ( - V_438 ) ;
}
V_11 = V_507 -> V_509 [ 0 ] . V_510 ;
F_146 ( V_11 , V_507 -> V_509 [ 0 ] . V_511 ) ;
V_48 -> V_418 = V_11 ;
V_48 -> V_458 = V_205 ;
V_48 -> V_460 = V_285 ;
V_48 -> V_373 = V_48 -> V_278 ;
V_48 -> V_25 += 1 ;
V_48 -> V_393 = 1 ;
V_48 -> V_321 = V_91 ;
return F_243 ( V_48 ) ;
}
static void * F_283 ( struct V_48 * V_48 )
{
int V_512 ;
if ( V_48 -> V_25 != 2 ||
V_48 -> V_84 > 1 )
return F_244 ( - V_438 ) ;
V_512 = 64 * 2 ;
while ( V_512 && ( V_48 -> V_500 & ( V_512 - 1 ) ) )
V_512 >>= 1 ;
if ( ( V_512 << 9 ) < V_140 )
return F_244 ( - V_438 ) ;
V_48 -> V_458 = 5 ;
V_48 -> V_460 = V_282 ;
V_48 -> V_373 = V_512 ;
return F_243 ( V_48 ) ;
}
static void * F_284 ( struct V_48 * V_48 )
{
int V_460 ;
switch ( V_48 -> V_465 ) {
case V_289 :
V_460 = V_280 ;
break;
case V_290 :
V_460 = V_281 ;
break;
case V_291 :
V_460 = V_282 ;
break;
case V_292 :
V_460 = V_283 ;
break;
case V_293 :
V_460 = V_284 ;
break;
case V_285 :
V_460 = V_285 ;
break;
default:
return F_244 ( - V_438 ) ;
}
V_48 -> V_458 = 5 ;
V_48 -> V_460 = V_460 ;
V_48 -> V_393 = - 1 ;
V_48 -> V_25 -= 1 ;
return F_243 ( V_48 ) ;
}
static int F_285 ( struct V_48 * V_48 )
{
struct V_2 * V_3 = V_48 -> V_262 ;
int V_513 = V_48 -> V_373 ;
if ( V_48 -> V_460 >= 0 && ! F_245 ( V_48 -> V_460 ) )
return - V_438 ;
if ( V_513 > 0 ) {
if ( ! F_247 ( V_513 ) )
return - V_438 ;
if ( V_513 < ( V_440 >> 9 ) )
return - V_438 ;
if ( V_48 -> V_500 & ( V_513 - 1 ) )
return - V_438 ;
}
if ( V_48 -> V_25 == 2 ) {
if ( V_48 -> V_460 >= 0 ) {
V_3 -> V_274 = V_48 -> V_460 ;
V_48 -> V_465 = V_48 -> V_460 ;
}
if ( V_513 > 0 ) {
V_3 -> V_278 = V_513 ;
V_48 -> V_278 = V_513 ;
}
F_63 ( V_265 , & V_48 -> V_58 ) ;
F_22 ( V_48 -> V_49 ) ;
}
return F_275 ( V_48 ) ;
}
static int F_286 ( struct V_48 * V_48 )
{
int V_513 = V_48 -> V_373 ;
if ( V_48 -> V_460 >= 0 && ! F_246 ( V_48 -> V_460 ) )
return - V_438 ;
if ( V_513 > 0 ) {
if ( ! F_247 ( V_513 ) )
return - V_438 ;
if ( V_513 < ( V_440 >> 9 ) )
return - V_438 ;
if ( V_48 -> V_500 & ( V_513 - 1 ) )
return - V_438 ;
}
return F_275 ( V_48 ) ;
}
static void * F_287 ( struct V_48 * V_48 )
{
if ( V_48 -> V_205 == 0 )
return F_282 ( V_48 , 5 ) ;
if ( V_48 -> V_205 == 1 )
return F_283 ( V_48 ) ;
if ( V_48 -> V_205 == 4 ) {
V_48 -> V_460 = V_285 ;
V_48 -> V_458 = 5 ;
return F_243 ( V_48 ) ;
}
if ( V_48 -> V_205 == 6 )
return F_284 ( V_48 ) ;
return F_244 ( - V_438 ) ;
}
static void * F_288 ( struct V_48 * V_48 )
{
if ( V_48 -> V_205 == 0 )
return F_282 ( V_48 , 4 ) ;
if ( V_48 -> V_205 == 5 &&
V_48 -> V_465 == V_285 ) {
V_48 -> V_460 = 0 ;
V_48 -> V_458 = 4 ;
return F_243 ( V_48 ) ;
}
return F_244 ( - V_438 ) ;
}
static void * F_289 ( struct V_48 * V_48 )
{
int V_460 ;
if ( V_48 -> V_514 != & V_515 )
return F_244 ( - V_438 ) ;
if ( V_48 -> V_84 > 1 )
return F_244 ( - V_438 ) ;
if ( V_48 -> V_25 > 253 )
return F_244 ( - V_438 ) ;
if ( V_48 -> V_25 < 3 )
return F_244 ( - V_438 ) ;
switch ( V_48 -> V_465 ) {
case V_280 :
V_460 = V_289 ;
break;
case V_281 :
V_460 = V_290 ;
break;
case V_282 :
V_460 = V_291 ;
break;
case V_283 :
V_460 = V_292 ;
break;
case V_284 :
V_460 = V_293 ;
break;
case V_285 :
V_460 = V_285 ;
break;
default:
return F_244 ( - V_438 ) ;
}
V_48 -> V_458 = 6 ;
V_48 -> V_460 = V_460 ;
V_48 -> V_393 = 1 ;
V_48 -> V_25 += 1 ;
return F_243 ( V_48 ) ;
}
static int T_7 F_290 ( void )
{
F_291 ( & V_516 ) ;
F_291 ( & V_515 ) ;
F_291 ( & V_517 ) ;
return 0 ;
}
static void F_292 ( void )
{
F_293 ( & V_516 ) ;
F_293 ( & V_515 ) ;
F_293 ( & V_517 ) ;
}
