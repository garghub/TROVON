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
if ( F_14 ( V_41 , & V_20 -> V_36 ) &&
! F_14 ( V_42 , & V_20 -> V_36 ) )
F_20 ( & V_20 -> V_38 , & V_3 -> V_43 ) ;
else if ( F_14 ( V_44 , & V_20 -> V_36 ) &&
V_20 -> V_45 - V_3 -> V_46 > 0 )
F_20 ( & V_20 -> V_38 , & V_3 -> V_47 ) ;
else {
F_21 ( V_41 , & V_20 -> V_36 ) ;
F_21 ( V_44 , & V_20 -> V_36 ) ;
F_20 ( & V_20 -> V_38 , & V_3 -> V_48 ) ;
}
F_22 ( V_3 -> V_49 -> V_50 ) ;
} else {
F_17 ( F_13 ( V_20 ) ) ;
if ( F_23 ( V_42 , & V_20 -> V_36 ) )
if ( F_24 ( & V_3 -> V_51 )
< V_52 )
F_22 ( V_3 -> V_49 -> V_50 ) ;
F_25 ( & V_3 -> V_39 ) ;
if ( ! F_14 ( V_53 , & V_20 -> V_36 ) ) {
F_20 ( & V_20 -> V_38 , & V_3 -> V_54 ) ;
F_26 ( & V_3 -> V_55 ) ;
if ( V_3 -> V_56 )
F_22 ( V_3 -> V_49 -> V_50 ) ;
}
}
}
}
static void F_27 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = V_20 -> V_57 ;
unsigned long V_58 ;
F_28 ( & V_3 -> V_59 , V_58 ) ;
F_15 ( V_3 , V_20 ) ;
F_29 ( & V_3 -> V_59 , V_58 ) ;
}
static inline void F_30 ( struct V_19 * V_20 )
{
F_31 ( L_1 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_32 ( & V_20 -> V_5 ) ;
}
static inline void F_33 ( struct V_2 * V_3 , struct V_19 * V_20 )
{
struct V_1 * V_60 = F_1 ( V_3 , V_20 -> V_10 ) ;
F_31 ( L_2 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_34 ( & V_20 -> V_5 , V_60 ) ;
}
static struct V_19 * F_35 ( struct V_2 * V_3 )
{
struct V_19 * V_20 = NULL ;
struct V_61 * V_62 ;
if ( F_18 ( & V_3 -> V_54 ) )
goto V_63;
V_62 = V_3 -> V_54 . V_64 ;
V_20 = F_36 ( V_62 , struct V_19 , V_38 ) ;
F_37 ( V_62 ) ;
F_30 ( V_20 ) ;
F_38 ( & V_3 -> V_39 ) ;
V_63:
return V_20 ;
}
static void F_39 ( struct V_19 * V_20 )
{
struct V_65 * V_66 ;
int V_67 ;
int V_68 = V_20 -> V_57 -> V_69 ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
V_66 = V_20 -> V_70 [ V_67 ] . V_65 ;
if ( ! V_66 )
continue;
V_20 -> V_70 [ V_67 ] . V_65 = NULL ;
F_40 ( V_66 ) ;
}
}
static int F_41 ( struct V_19 * V_20 )
{
int V_67 ;
int V_68 = V_20 -> V_57 -> V_69 ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
struct V_65 * V_65 ;
if ( ! ( V_65 = F_42 ( V_71 ) ) ) {
return 1 ;
}
V_20 -> V_70 [ V_67 ] . V_65 = V_65 ;
}
return 0 ;
}
static void F_43 ( struct V_19 * V_20 , T_1 V_10 , int V_72 )
{
struct V_2 * V_3 = V_20 -> V_57 ;
int V_67 ;
F_17 ( F_19 ( & V_20 -> V_27 ) != 0 ) ;
F_17 ( F_14 ( V_40 , & V_20 -> V_36 ) ) ;
F_17 ( F_13 ( V_20 ) ) ;
F_31 ( L_3 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_30 ( V_20 ) ;
V_20 -> V_73 = V_3 -> V_73 - V_72 ;
V_20 -> V_23 = V_72 ? V_3 -> V_74 : V_3 -> V_25 ;
V_20 -> V_10 = V_10 ;
F_44 ( V_10 , V_3 , V_72 , V_20 ) ;
V_20 -> V_36 = 0 ;
for ( V_67 = V_20 -> V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( V_70 -> V_76 || V_70 -> V_77 || V_70 -> V_78 || V_70 -> V_79 ||
F_14 ( V_80 , & V_70 -> V_58 ) ) {
F_45 ( V_81 L_4 ,
( unsigned long long ) V_20 -> V_10 , V_67 , V_70 -> V_76 ,
V_70 -> V_77 , V_70 -> V_78 , V_70 -> V_79 ,
F_14 ( V_80 , & V_70 -> V_58 ) ) ;
F_46 ( 1 ) ;
}
V_70 -> V_58 = 0 ;
F_47 ( V_20 , V_67 , V_72 ) ;
}
F_33 ( V_3 , V_20 ) ;
}
static struct V_19 * F_48 ( struct V_2 * V_3 , T_1 V_10 ,
short V_73 )
{
struct V_19 * V_20 ;
struct V_82 * V_83 ;
F_31 ( L_5 , ( unsigned long long ) V_10 ) ;
F_49 (sh, hn, stripe_hash(conf, sector), hash)
if ( V_20 -> V_10 == V_10 && V_20 -> V_73 == V_73 )
return V_20 ;
F_31 ( L_6 , ( unsigned long long ) V_10 ) ;
return NULL ;
}
static int F_50 ( struct V_2 * V_3 )
{
int V_84 , V_85 ;
int V_67 ;
F_51 () ;
V_84 = 0 ;
for ( V_67 = 0 ; V_67 < V_3 -> V_74 ; V_67 ++ ) {
struct V_86 * V_87 = F_52 ( V_3 -> V_23 [ V_67 ] . V_87 ) ;
if ( ! V_87 || F_14 ( V_88 , & V_87 -> V_58 ) )
V_84 ++ ;
else if ( F_14 ( V_89 , & V_87 -> V_58 ) )
;
else
if ( V_3 -> V_25 >= V_3 -> V_74 )
V_84 ++ ;
}
F_53 () ;
if ( V_3 -> V_25 == V_3 -> V_74 )
return V_84 ;
F_51 () ;
V_85 = 0 ;
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ ) {
struct V_86 * V_87 = F_52 ( V_3 -> V_23 [ V_67 ] . V_87 ) ;
if ( ! V_87 || F_14 ( V_88 , & V_87 -> V_58 ) )
V_85 ++ ;
else if ( F_14 ( V_89 , & V_87 -> V_58 ) )
;
else
if ( V_3 -> V_25 <= V_3 -> V_74 )
V_85 ++ ;
}
F_53 () ;
if ( V_85 > V_84 )
return V_85 ;
return V_84 ;
}
static int F_54 ( struct V_2 * V_3 )
{
int V_84 ;
if ( V_3 -> V_49 -> V_90 == V_91 )
return V_3 -> V_49 -> V_84 > V_3 -> V_92 ;
V_84 = F_50 ( V_3 ) ;
if ( V_84 > V_3 -> V_92 )
return 1 ;
return 0 ;
}
static struct V_19 *
F_55 ( struct V_2 * V_3 , T_1 V_10 ,
int V_72 , int V_93 , int V_94 )
{
struct V_19 * V_20 ;
F_31 ( L_7 , ( unsigned long long ) V_10 ) ;
F_56 ( & V_3 -> V_59 ) ;
do {
F_57 ( V_3 -> V_55 ,
V_3 -> V_95 == 0 || V_94 ,
V_3 -> V_59 , ) ;
V_20 = F_48 ( V_3 , V_10 , V_3 -> V_73 - V_72 ) ;
if ( ! V_20 ) {
if ( ! V_3 -> V_96 )
V_20 = F_35 ( V_3 ) ;
if ( V_93 && V_20 == NULL )
break;
if ( ! V_20 ) {
V_3 -> V_96 = 1 ;
F_57 ( V_3 -> V_55 ,
! F_18 ( & V_3 -> V_54 ) &&
( F_19 ( & V_3 -> V_39 )
< ( V_3 -> V_97 * 3 / 4 )
|| ! V_3 -> V_96 ) ,
V_3 -> V_59 ,
) ;
V_3 -> V_96 = 0 ;
} else
F_43 ( V_20 , V_10 , V_72 ) ;
} else {
if ( F_19 ( & V_20 -> V_27 ) ) {
F_17 ( ! F_18 ( & V_20 -> V_38 )
&& ! F_14 ( V_53 , & V_20 -> V_36 ) ) ;
} else {
if ( ! F_14 ( V_40 , & V_20 -> V_36 ) )
F_38 ( & V_3 -> V_39 ) ;
if ( F_18 ( & V_20 -> V_38 ) &&
! F_14 ( V_53 , & V_20 -> V_36 ) )
F_58 () ;
F_37 ( & V_20 -> V_38 ) ;
}
}
} while ( V_20 == NULL );
if ( V_20 )
F_38 ( & V_20 -> V_27 ) ;
F_59 ( & V_3 -> V_59 ) ;
return V_20 ;
}
static int F_60 ( struct V_2 * V_3 , struct V_19 * V_20 )
{
T_1 V_98 = V_3 -> V_99 ;
F_61 () ;
if ( V_98 == V_91 )
return 0 ;
if ( V_20 -> V_73 == V_3 -> V_73 - 1 )
return 0 ;
return 1 ;
}
static void F_62 ( struct V_19 * V_20 , struct V_100 * V_101 )
{
struct V_2 * V_3 = V_20 -> V_57 ;
int V_67 , V_23 = V_20 -> V_23 ;
F_63 () ;
for ( V_67 = V_23 ; V_67 -- ; ) {
int V_102 ;
int V_103 = 0 ;
struct V_9 * V_32 , * V_104 ;
struct V_86 * V_87 , * V_105 = NULL ;
if ( F_23 ( V_106 , & V_20 -> V_70 [ V_67 ] . V_58 ) ) {
if ( F_23 ( V_107 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
V_102 = V_108 ;
else
V_102 = V_109 ;
} else if ( F_23 ( V_110 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
V_102 = V_111 ;
else if ( F_23 ( V_112 ,
& V_20 -> V_70 [ V_67 ] . V_58 ) ) {
V_102 = V_109 ;
V_103 = 1 ;
} else
continue;
if ( F_23 ( V_113 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
V_102 |= V_114 ;
V_32 = & V_20 -> V_70 [ V_67 ] . V_115 ;
V_104 = & V_20 -> V_70 [ V_67 ] . V_116 ;
V_32 -> V_117 = V_102 ;
V_104 -> V_117 = V_102 ;
if ( V_102 & V_109 ) {
V_32 -> V_118 = V_119 ;
V_104 -> V_118 = V_119 ;
} else
V_32 -> V_118 = V_120 ;
F_51 () ;
V_105 = F_52 ( V_3 -> V_23 [ V_67 ] . V_121 ) ;
F_64 () ;
V_87 = F_52 ( V_3 -> V_23 [ V_67 ] . V_87 ) ;
if ( ! V_87 ) {
V_87 = V_105 ;
V_105 = NULL ;
}
if ( V_102 & V_109 ) {
if ( V_103 )
V_87 = NULL ;
if ( V_87 == V_105 )
V_105 = NULL ;
} else {
if ( F_14 ( V_122 , & V_20 -> V_70 [ V_67 ] . V_58 ) && V_105 )
V_87 = V_105 ;
V_105 = NULL ;
}
if ( V_87 && F_14 ( V_88 , & V_87 -> V_58 ) )
V_87 = NULL ;
if ( V_87 )
F_38 ( & V_87 -> V_123 ) ;
if ( V_105 && F_14 ( V_88 , & V_105 -> V_58 ) )
V_105 = NULL ;
if ( V_105 )
F_38 ( & V_105 -> V_123 ) ;
F_53 () ;
while ( ( V_102 & V_109 ) && V_87 &&
F_14 ( V_124 , & V_87 -> V_58 ) ) {
T_1 V_125 ;
int V_126 ;
int V_127 = F_65 ( V_87 , V_20 -> V_10 , V_14 ,
& V_125 , & V_126 ) ;
if ( ! V_127 )
break;
if ( V_127 < 0 ) {
F_66 ( V_128 , & V_87 -> V_58 ) ;
if ( ! V_3 -> V_49 -> V_129 &&
V_3 -> V_49 -> V_58 ) {
F_67 ( V_3 -> V_49 ) ;
}
F_38 ( & V_87 -> V_123 ) ;
F_68 ( V_87 , V_3 -> V_49 ) ;
} else {
F_69 ( V_87 , V_3 -> V_49 ) ;
V_87 = NULL ;
}
}
if ( V_87 ) {
if ( V_101 -> V_130 || V_101 -> V_131 || V_101 -> V_132
|| V_101 -> V_133 )
F_70 ( V_87 -> V_134 , V_14 ) ;
F_66 ( V_135 , & V_20 -> V_36 ) ;
V_32 -> V_136 = V_87 -> V_134 ;
F_31 ( L_8 ,
V_137 , ( unsigned long long ) V_20 -> V_10 ,
V_32 -> V_117 , V_67 ) ;
F_38 ( & V_20 -> V_27 ) ;
if ( F_60 ( V_3 , V_20 ) )
V_32 -> V_13 = ( V_20 -> V_10
+ V_87 -> V_138 ) ;
else
V_32 -> V_13 = ( V_20 -> V_10
+ V_87 -> V_139 ) ;
V_32 -> V_140 = 1 << V_141 ;
V_32 -> V_142 = 0 ;
V_32 -> V_143 [ 0 ] . V_144 = V_145 ;
V_32 -> V_143 [ 0 ] . V_146 = 0 ;
V_32 -> V_12 = V_145 ;
V_32 -> V_15 = NULL ;
if ( V_105 )
F_66 ( V_147 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_71 ( V_32 ) ;
}
if ( V_105 ) {
if ( V_101 -> V_130 || V_101 -> V_131 || V_101 -> V_132
|| V_101 -> V_133 )
F_70 ( V_105 -> V_134 , V_14 ) ;
F_66 ( V_135 , & V_20 -> V_36 ) ;
V_104 -> V_136 = V_105 -> V_134 ;
F_31 ( L_9
L_10 ,
V_137 , ( unsigned long long ) V_20 -> V_10 ,
V_104 -> V_117 , V_67 ) ;
F_38 ( & V_20 -> V_27 ) ;
if ( F_60 ( V_3 , V_20 ) )
V_104 -> V_13 = ( V_20 -> V_10
+ V_105 -> V_138 ) ;
else
V_104 -> V_13 = ( V_20 -> V_10
+ V_105 -> V_139 ) ;
V_104 -> V_140 = 1 << V_141 ;
V_104 -> V_142 = 0 ;
V_104 -> V_143 [ 0 ] . V_144 = V_145 ;
V_104 -> V_143 [ 0 ] . V_146 = 0 ;
V_104 -> V_12 = V_145 ;
V_104 -> V_15 = NULL ;
F_71 ( V_104 ) ;
}
if ( ! V_87 && ! V_105 ) {
if ( V_102 & V_109 )
F_66 ( V_148 , & V_20 -> V_36 ) ;
F_31 ( L_11 ,
V_32 -> V_117 , V_67 , ( unsigned long long ) V_20 -> V_10 ) ;
F_21 ( V_80 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_66 ( V_40 , & V_20 -> V_36 ) ;
}
}
}
static struct V_149 *
F_72 ( int V_150 , struct V_9 * V_9 , struct V_65 * V_65 ,
T_1 V_10 , struct V_149 * V_151 )
{
struct V_152 * V_153 ;
struct V_65 * V_154 ;
int V_67 ;
int V_155 ;
struct V_156 V_157 ;
enum V_158 V_58 = 0 ;
if ( V_9 -> V_13 >= V_10 )
V_155 = ( signed ) ( V_9 -> V_13 - V_10 ) * 512 ;
else
V_155 = ( signed ) ( V_10 - V_9 -> V_13 ) * - 512 ;
if ( V_150 )
V_58 |= V_159 ;
F_73 ( & V_157 , V_58 , V_151 , NULL , NULL , NULL ) ;
F_74 (bvl, bio, i) {
int V_160 = V_153 -> V_144 ;
int V_161 ;
int V_162 = 0 ;
if ( V_155 < 0 ) {
V_162 = - V_155 ;
V_155 += V_162 ;
V_160 -= V_162 ;
}
if ( V_160 > 0 && V_155 + V_160 > V_145 )
V_161 = V_145 - V_155 ;
else
V_161 = V_160 ;
if ( V_161 > 0 ) {
V_162 += V_153 -> V_146 ;
V_154 = V_153 -> V_163 ;
if ( V_150 )
V_151 = F_75 ( V_65 , V_154 , V_155 ,
V_162 , V_161 , & V_157 ) ;
else
V_151 = F_75 ( V_154 , V_65 , V_162 ,
V_155 , V_161 , & V_157 ) ;
}
V_157 . V_164 = V_151 ;
if ( V_161 < V_160 )
break;
V_155 += V_160 ;
}
return V_151 ;
}
static void F_76 ( void * V_165 )
{
struct V_19 * V_20 = V_165 ;
struct V_9 * V_31 = NULL ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_67 ;
F_31 ( L_12 , V_137 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_56 ( & V_3 -> V_59 ) ;
for ( V_67 = V_20 -> V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( F_23 ( V_166 , & V_70 -> V_58 ) ) {
struct V_9 * V_104 , * V_167 ;
F_17 ( ! V_70 -> V_77 ) ;
V_104 = V_70 -> V_77 ;
V_70 -> V_77 = NULL ;
while ( V_104 && V_104 -> V_13 <
V_70 -> V_10 + V_14 ) {
V_167 = F_2 ( V_104 , V_70 -> V_10 ) ;
if ( ! F_5 ( V_104 ) ) {
V_104 -> V_15 = V_31 ;
V_31 = V_104 ;
}
V_104 = V_167 ;
}
}
}
F_59 ( & V_3 -> V_59 ) ;
F_21 ( V_35 , & V_20 -> V_36 ) ;
F_11 ( V_31 ) ;
F_66 ( V_40 , & V_20 -> V_36 ) ;
F_27 ( V_20 ) ;
}
static void F_77 ( struct V_19 * V_20 )
{
struct V_149 * V_151 = NULL ;
struct V_2 * V_3 = V_20 -> V_57 ;
struct V_156 V_157 ;
int V_67 ;
F_31 ( L_12 , V_137 ,
( unsigned long long ) V_20 -> V_10 ) ;
for ( V_67 = V_20 -> V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( F_14 ( V_166 , & V_70 -> V_58 ) ) {
struct V_9 * V_104 ;
F_56 ( & V_3 -> V_59 ) ;
V_70 -> V_77 = V_104 = V_70 -> V_76 ;
V_70 -> V_76 = NULL ;
F_59 ( & V_3 -> V_59 ) ;
while ( V_104 && V_104 -> V_13 <
V_70 -> V_10 + V_14 ) {
V_151 = F_72 ( 0 , V_104 , V_70 -> V_65 ,
V_70 -> V_10 , V_151 ) ;
V_104 = F_2 ( V_104 , V_70 -> V_10 ) ;
}
}
}
F_38 ( & V_20 -> V_27 ) ;
F_73 ( & V_157 , V_168 , V_151 , F_76 , V_20 , NULL ) ;
F_78 ( & V_157 ) ;
}
static void F_79 ( struct V_19 * V_20 , int V_169 )
{
struct V_75 * V_170 ;
if ( V_169 < 0 )
return;
V_170 = & V_20 -> V_70 [ V_169 ] ;
F_66 ( V_171 , & V_170 -> V_58 ) ;
F_17 ( ! F_14 ( V_172 , & V_170 -> V_58 ) ) ;
F_21 ( V_172 , & V_170 -> V_58 ) ;
}
static void F_80 ( void * V_165 )
{
struct V_19 * V_20 = V_165 ;
F_31 ( L_12 , V_137 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_79 ( V_20 , V_20 -> V_173 . V_169 ) ;
F_79 ( V_20 , V_20 -> V_173 . V_174 ) ;
F_21 ( V_37 , & V_20 -> V_36 ) ;
if ( V_20 -> V_33 == V_175 )
V_20 -> V_33 = V_176 ;
F_66 ( V_40 , & V_20 -> V_36 ) ;
F_27 ( V_20 ) ;
}
static T_2 * F_81 ( struct V_19 * V_20 ,
struct V_177 * V_178 )
{
return V_178 -> V_179 + sizeof( struct V_65 * ) * ( V_20 -> V_23 + 2 ) ;
}
static struct V_149 *
F_82 ( struct V_19 * V_20 , struct V_177 * V_178 )
{
int V_23 = V_20 -> V_23 ;
struct V_65 * * V_180 = V_178 -> V_179 ;
int V_169 = V_20 -> V_173 . V_169 ;
struct V_75 * V_170 = & V_20 -> V_70 [ V_169 ] ;
struct V_65 * V_181 = V_170 -> V_65 ;
int V_27 = 0 ;
struct V_149 * V_151 ;
struct V_156 V_157 ;
int V_67 ;
F_31 ( L_13 ,
V_137 , ( unsigned long long ) V_20 -> V_10 , V_169 ) ;
F_17 ( ! F_14 ( V_172 , & V_170 -> V_58 ) ) ;
for ( V_67 = V_23 ; V_67 -- ; )
if ( V_67 != V_169 )
V_180 [ V_27 ++ ] = V_20 -> V_70 [ V_67 ] . V_65 ;
F_38 ( & V_20 -> V_27 ) ;
F_73 ( & V_157 , V_159 | V_182 , NULL ,
F_80 , V_20 , F_81 ( V_20 , V_178 ) ) ;
if ( F_83 ( V_27 == 1 ) )
V_151 = F_75 ( V_181 , V_180 [ 0 ] , 0 , 0 , V_145 , & V_157 ) ;
else
V_151 = F_84 ( V_181 , V_180 , 0 , V_27 , V_145 , & V_157 ) ;
return V_151 ;
}
static int F_85 ( struct V_65 * * V_183 , struct V_19 * V_20 )
{
int V_23 = V_20 -> V_23 ;
int V_28 = V_20 -> V_21 ? V_23 : ( V_23 - 2 ) ;
int V_184 = F_8 ( V_20 ) ;
int V_27 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_23 ; V_67 ++ )
V_183 [ V_67 ] = NULL ;
V_27 = 0 ;
V_67 = V_184 ;
do {
int V_29 = F_10 ( V_67 , V_20 , & V_27 , V_28 ) ;
V_183 [ V_29 ] = V_20 -> V_70 [ V_67 ] . V_65 ;
V_67 = F_9 ( V_67 , V_23 ) ;
} while ( V_67 != V_184 );
return V_28 ;
}
static struct V_149 *
F_86 ( struct V_19 * V_20 , struct V_177 * V_178 )
{
int V_23 = V_20 -> V_23 ;
struct V_65 * * V_185 = V_178 -> V_179 ;
int V_169 ;
int V_22 = V_20 -> V_22 ;
struct V_149 * V_151 ;
struct V_156 V_157 ;
struct V_75 * V_170 ;
struct V_65 * V_186 ;
int V_67 ;
int V_27 ;
if ( V_20 -> V_173 . V_169 < 0 )
V_169 = V_20 -> V_173 . V_174 ;
else if ( V_20 -> V_173 . V_174 < 0 )
V_169 = V_20 -> V_173 . V_169 ;
else
F_58 () ;
F_17 ( V_169 < 0 ) ;
F_31 ( L_13 ,
V_137 , ( unsigned long long ) V_20 -> V_10 , V_169 ) ;
V_170 = & V_20 -> V_70 [ V_169 ] ;
F_17 ( ! F_14 ( V_172 , & V_170 -> V_58 ) ) ;
V_186 = V_170 -> V_65 ;
F_38 ( & V_20 -> V_27 ) ;
if ( V_169 == V_22 ) {
V_27 = F_85 ( V_185 , V_20 ) ;
V_185 [ V_27 ] = NULL ;
F_17 ( V_185 [ V_27 + 1 ] != V_186 ) ;
F_73 ( & V_157 , V_159 , NULL ,
F_80 , V_20 ,
F_81 ( V_20 , V_178 ) ) ;
V_151 = F_87 ( V_185 , 0 , V_27 + 2 , V_145 , & V_157 ) ;
} else {
V_27 = 0 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
if ( V_67 == V_169 || V_67 == V_22 )
continue;
V_185 [ V_27 ++ ] = V_20 -> V_70 [ V_67 ] . V_65 ;
}
F_73 ( & V_157 , V_159 | V_182 ,
NULL , F_80 , V_20 ,
F_81 ( V_20 , V_178 ) ) ;
V_151 = F_84 ( V_186 , V_185 , 0 , V_27 , V_145 , & V_157 ) ;
}
return V_151 ;
}
static struct V_149 *
F_88 ( struct V_19 * V_20 , struct V_177 * V_178 )
{
int V_67 , V_27 , V_23 = V_20 -> V_23 ;
int V_28 = V_20 -> V_21 ? V_23 : V_23 - 2 ;
int V_184 = F_8 ( V_20 ) ;
int V_187 = - 1 , V_188 = - 1 ;
int V_169 = V_20 -> V_173 . V_169 ;
int V_174 = V_20 -> V_173 . V_174 ;
struct V_75 * V_170 = & V_20 -> V_70 [ V_169 ] ;
struct V_75 * V_189 = & V_20 -> V_70 [ V_174 ] ;
struct V_149 * V_151 ;
struct V_65 * * V_185 = V_178 -> V_179 ;
struct V_156 V_157 ;
F_31 ( L_14 ,
V_137 , ( unsigned long long ) V_20 -> V_10 , V_169 , V_174 ) ;
F_17 ( V_169 < 0 || V_174 < 0 ) ;
F_17 ( ! F_14 ( V_172 , & V_170 -> V_58 ) ) ;
F_17 ( ! F_14 ( V_172 , & V_189 -> V_58 ) ) ;
for ( V_67 = 0 ; V_67 < V_23 ; V_67 ++ )
V_185 [ V_67 ] = NULL ;
V_27 = 0 ;
V_67 = V_184 ;
do {
int V_29 = F_10 ( V_67 , V_20 , & V_27 , V_28 ) ;
V_185 [ V_29 ] = V_20 -> V_70 [ V_67 ] . V_65 ;
if ( V_67 == V_169 )
V_187 = V_29 ;
if ( V_67 == V_174 )
V_188 = V_29 ;
V_67 = F_9 ( V_67 , V_23 ) ;
} while ( V_67 != V_184 );
F_17 ( V_187 == V_188 ) ;
if ( V_188 < V_187 )
F_89 ( V_187 , V_188 ) ;
F_31 ( L_15 ,
V_137 , ( unsigned long long ) V_20 -> V_10 , V_187 , V_188 ) ;
F_38 ( & V_20 -> V_27 ) ;
if ( V_188 == V_28 + 1 ) {
if ( V_187 == V_28 ) {
F_73 ( & V_157 , V_159 , NULL ,
F_80 , V_20 ,
F_81 ( V_20 , V_178 ) ) ;
return F_87 ( V_185 , 0 , V_28 + 2 ,
V_145 , & V_157 ) ;
} else {
struct V_65 * V_186 ;
int V_190 ;
int V_22 = V_20 -> V_22 ;
if ( V_169 == V_22 )
V_190 = V_174 ;
else
V_190 = V_169 ;
V_27 = 0 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
if ( V_67 == V_190 || V_67 == V_22 )
continue;
V_185 [ V_27 ++ ] = V_20 -> V_70 [ V_67 ] . V_65 ;
}
V_186 = V_20 -> V_70 [ V_190 ] . V_65 ;
F_73 ( & V_157 ,
V_159 | V_182 ,
NULL , NULL , NULL ,
F_81 ( V_20 , V_178 ) ) ;
V_151 = F_84 ( V_186 , V_185 , 0 , V_27 , V_145 ,
& V_157 ) ;
V_27 = F_85 ( V_185 , V_20 ) ;
F_73 ( & V_157 , V_159 , V_151 ,
F_80 , V_20 ,
F_81 ( V_20 , V_178 ) ) ;
return F_87 ( V_185 , 0 , V_27 + 2 ,
V_145 , & V_157 ) ;
}
} else {
F_73 ( & V_157 , V_159 , NULL ,
F_80 , V_20 ,
F_81 ( V_20 , V_178 ) ) ;
if ( V_188 == V_28 ) {
return F_90 ( V_28 + 2 ,
V_145 , V_187 ,
V_185 , & V_157 ) ;
} else {
return F_91 ( V_28 + 2 ,
V_145 , V_187 , V_188 ,
V_185 , & V_157 ) ;
}
}
}
static void F_92 ( void * V_165 )
{
struct V_19 * V_20 = V_165 ;
F_31 ( L_12 , V_137 ,
( unsigned long long ) V_20 -> V_10 ) ;
}
static struct V_149 *
F_93 ( struct V_19 * V_20 , struct V_177 * V_178 ,
struct V_149 * V_151 )
{
int V_23 = V_20 -> V_23 ;
struct V_65 * * V_180 = V_178 -> V_179 ;
int V_27 = 0 , V_30 = V_20 -> V_30 , V_67 ;
struct V_156 V_157 ;
struct V_65 * V_181 = V_180 [ V_27 ++ ] = V_20 -> V_70 [ V_30 ] . V_65 ;
F_31 ( L_12 , V_137 ,
( unsigned long long ) V_20 -> V_10 ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( F_14 ( V_191 , & V_70 -> V_58 ) )
V_180 [ V_27 ++ ] = V_70 -> V_65 ;
}
F_73 ( & V_157 , V_159 | V_192 , V_151 ,
F_92 , V_20 , F_81 ( V_20 , V_178 ) ) ;
V_151 = F_84 ( V_181 , V_180 , 0 , V_27 , V_145 , & V_157 ) ;
return V_151 ;
}
static struct V_149 *
F_94 ( struct V_19 * V_20 , struct V_149 * V_151 )
{
int V_23 = V_20 -> V_23 ;
int V_67 ;
F_31 ( L_12 , V_137 ,
( unsigned long long ) V_20 -> V_10 ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
struct V_9 * V_193 ;
if ( F_23 ( V_191 , & V_70 -> V_58 ) ) {
struct V_9 * V_194 ;
F_56 ( & V_20 -> V_57 -> V_59 ) ;
V_193 = V_70 -> V_78 ;
V_70 -> V_78 = NULL ;
F_17 ( V_70 -> V_79 ) ;
V_194 = V_70 -> V_79 = V_193 ;
F_59 ( & V_20 -> V_57 -> V_59 ) ;
while ( V_194 && V_194 -> V_13 <
V_70 -> V_10 + V_14 ) {
if ( V_194 -> V_117 & V_195 )
F_66 ( V_107 , & V_70 -> V_58 ) ;
if ( V_194 -> V_117 & V_114 )
F_66 ( V_113 , & V_70 -> V_58 ) ;
V_151 = F_72 ( 1 , V_194 , V_70 -> V_65 ,
V_70 -> V_10 , V_151 ) ;
V_194 = F_2 ( V_194 , V_70 -> V_10 ) ;
}
}
}
return V_151 ;
}
static void F_95 ( void * V_165 )
{
struct V_19 * V_20 = V_165 ;
int V_23 = V_20 -> V_23 ;
int V_30 = V_20 -> V_30 ;
int V_22 = V_20 -> V_22 ;
int V_67 ;
bool V_196 = false , V_197 = false ;
F_31 ( L_12 , V_137 ,
( unsigned long long ) V_20 -> V_10 ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
V_196 |= F_14 ( V_107 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
V_197 |= F_14 ( V_113 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
}
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( V_70 -> V_79 || V_67 == V_30 || V_67 == V_22 ) {
F_66 ( V_171 , & V_70 -> V_58 ) ;
if ( V_196 )
F_66 ( V_107 , & V_70 -> V_58 ) ;
if ( V_197 )
F_66 ( V_113 , & V_70 -> V_58 ) ;
}
}
if ( V_20 -> V_34 == V_198 )
V_20 -> V_34 = V_199 ;
else if ( V_20 -> V_34 == V_200 )
V_20 -> V_34 = V_201 ;
else {
F_17 ( V_20 -> V_34 != V_202 ) ;
V_20 -> V_34 = V_203 ;
}
F_66 ( V_40 , & V_20 -> V_36 ) ;
F_27 ( V_20 ) ;
}
static void
F_96 ( struct V_19 * V_20 , struct V_177 * V_178 ,
struct V_149 * V_151 )
{
int V_23 = V_20 -> V_23 ;
struct V_65 * * V_180 = V_178 -> V_179 ;
struct V_156 V_157 ;
int V_27 = 0 , V_30 = V_20 -> V_30 , V_67 ;
struct V_65 * V_181 ;
int V_204 = 0 ;
unsigned long V_58 ;
F_31 ( L_12 , V_137 ,
( unsigned long long ) V_20 -> V_10 ) ;
if ( V_20 -> V_34 == V_200 ) {
V_204 = 1 ;
V_181 = V_180 [ V_27 ++ ] = V_20 -> V_70 [ V_30 ] . V_65 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( V_70 -> V_79 )
V_180 [ V_27 ++ ] = V_70 -> V_65 ;
}
} else {
V_181 = V_20 -> V_70 [ V_30 ] . V_65 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( V_67 != V_30 )
V_180 [ V_27 ++ ] = V_70 -> V_65 ;
}
}
V_58 = V_168 |
( V_204 ? V_192 : V_182 ) ;
F_38 ( & V_20 -> V_27 ) ;
F_73 ( & V_157 , V_58 , V_151 , F_95 , V_20 ,
F_81 ( V_20 , V_178 ) ) ;
if ( F_83 ( V_27 == 1 ) )
V_151 = F_75 ( V_181 , V_180 [ 0 ] , 0 , 0 , V_145 , & V_157 ) ;
else
V_151 = F_84 ( V_181 , V_180 , 0 , V_27 , V_145 , & V_157 ) ;
}
static void
F_97 ( struct V_19 * V_20 , struct V_177 * V_178 ,
struct V_149 * V_151 )
{
struct V_156 V_157 ;
struct V_65 * * V_185 = V_178 -> V_179 ;
int V_27 ;
F_31 ( L_12 , V_137 , ( unsigned long long ) V_20 -> V_10 ) ;
V_27 = F_85 ( V_185 , V_20 ) ;
F_38 ( & V_20 -> V_27 ) ;
F_73 ( & V_157 , V_168 , V_151 , F_95 ,
V_20 , F_81 ( V_20 , V_178 ) ) ;
F_87 ( V_185 , 0 , V_27 + 2 , V_145 , & V_157 ) ;
}
static void F_98 ( void * V_165 )
{
struct V_19 * V_20 = V_165 ;
F_31 ( L_12 , V_137 ,
( unsigned long long ) V_20 -> V_10 ) ;
V_20 -> V_33 = V_205 ;
F_66 ( V_40 , & V_20 -> V_36 ) ;
F_27 ( V_20 ) ;
}
static void F_99 ( struct V_19 * V_20 , struct V_177 * V_178 )
{
int V_23 = V_20 -> V_23 ;
int V_30 = V_20 -> V_30 ;
int V_22 = V_20 -> V_22 ;
struct V_65 * V_181 ;
struct V_65 * * V_180 = V_178 -> V_179 ;
struct V_149 * V_151 ;
struct V_156 V_157 ;
int V_27 ;
int V_67 ;
F_31 ( L_12 , V_137 ,
( unsigned long long ) V_20 -> V_10 ) ;
V_27 = 0 ;
V_181 = V_20 -> V_70 [ V_30 ] . V_65 ;
V_180 [ V_27 ++ ] = V_181 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
if ( V_67 == V_30 || V_67 == V_22 )
continue;
V_180 [ V_27 ++ ] = V_20 -> V_70 [ V_67 ] . V_65 ;
}
F_73 ( & V_157 , 0 , NULL , NULL , NULL ,
F_81 ( V_20 , V_178 ) ) ;
V_151 = F_100 ( V_181 , V_180 , 0 , V_27 , V_145 ,
& V_20 -> V_173 . V_206 , & V_157 ) ;
F_38 ( & V_20 -> V_27 ) ;
F_73 ( & V_157 , V_168 , V_151 , F_98 , V_20 , NULL ) ;
V_151 = F_78 ( & V_157 ) ;
}
static void F_101 ( struct V_19 * V_20 , struct V_177 * V_178 , int V_207 )
{
struct V_65 * * V_183 = V_178 -> V_179 ;
struct V_156 V_157 ;
int V_27 ;
F_31 ( L_16 , V_137 ,
( unsigned long long ) V_20 -> V_10 , V_207 ) ;
V_27 = F_85 ( V_183 , V_20 ) ;
if ( ! V_207 )
V_183 [ V_27 ] = NULL ;
F_38 ( & V_20 -> V_27 ) ;
F_73 ( & V_157 , V_168 , NULL , F_98 ,
V_20 , F_81 ( V_20 , V_178 ) ) ;
F_102 ( V_183 , 0 , V_27 + 2 , V_145 ,
& V_20 -> V_173 . V_206 , V_178 -> V_208 , & V_157 ) ;
}
static void F_103 ( struct V_19 * V_20 , unsigned long V_209 )
{
int V_210 = 0 , V_67 , V_23 = V_20 -> V_23 ;
struct V_149 * V_151 = NULL ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_211 = V_3 -> V_211 ;
struct V_177 * V_178 ;
unsigned long V_212 ;
V_212 = F_104 () ;
V_178 = F_105 ( V_3 -> V_178 , V_212 ) ;
if ( F_14 ( V_213 , & V_209 ) ) {
F_77 ( V_20 ) ;
V_210 ++ ;
}
if ( F_14 ( V_214 , & V_209 ) ) {
if ( V_211 < 6 )
V_151 = F_82 ( V_20 , V_178 ) ;
else {
if ( V_20 -> V_173 . V_174 < 0 || V_20 -> V_173 . V_169 < 0 )
V_151 = F_86 ( V_20 , V_178 ) ;
else
V_151 = F_88 ( V_20 , V_178 ) ;
}
if ( V_151 && ! F_14 ( V_215 , & V_209 ) )
F_106 ( V_151 ) ;
}
if ( F_14 ( V_216 , & V_209 ) )
V_151 = F_93 ( V_20 , V_178 , V_151 ) ;
if ( F_14 ( V_217 , & V_209 ) ) {
V_151 = F_94 ( V_20 , V_151 ) ;
V_210 ++ ;
}
if ( F_14 ( V_215 , & V_209 ) ) {
if ( V_211 < 6 )
F_96 ( V_20 , V_178 , V_151 ) ;
else
F_97 ( V_20 , V_178 , V_151 ) ;
}
if ( F_14 ( V_218 , & V_209 ) ) {
if ( V_20 -> V_33 == V_219 )
F_99 ( V_20 , V_178 ) ;
else if ( V_20 -> V_33 == V_220 )
F_101 ( V_20 , V_178 , 0 ) ;
else if ( V_20 -> V_33 == V_221 )
F_101 ( V_20 , V_178 , 1 ) ;
else
F_58 () ;
}
if ( V_210 )
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( F_23 ( V_222 , & V_70 -> V_58 ) )
F_26 ( & V_20 -> V_57 -> V_223 ) ;
}
F_107 () ;
}
static void F_108 ( void * V_224 , T_3 V_225 )
{
struct V_19 * V_20 = V_224 ;
unsigned long V_209 = V_20 -> V_173 . V_226 ;
F_109 ( V_227 , & V_20 -> V_36 ) ;
F_26 ( & V_20 -> V_173 . V_228 ) ;
F_103 ( V_20 , V_209 ) ;
F_27 ( V_20 ) ;
}
static void F_110 ( struct V_19 * V_20 , unsigned long V_209 )
{
F_111 ( V_20 -> V_173 . V_228 ,
! F_112 ( V_227 , & V_20 -> V_36 ) ) ;
V_20 -> V_173 . V_226 = V_209 ;
F_38 ( & V_20 -> V_27 ) ;
F_113 ( F_108 , V_20 ) ;
}
static int F_114 ( struct V_2 * V_3 )
{
struct V_19 * V_20 ;
V_20 = F_115 ( V_3 -> V_229 , V_71 ) ;
if ( ! V_20 )
return 0 ;
V_20 -> V_57 = V_3 ;
#ifdef F_116
F_117 ( & V_20 -> V_173 . V_228 ) ;
#endif
if ( F_41 ( V_20 ) ) {
F_39 ( V_20 ) ;
F_118 ( V_3 -> V_229 , V_20 ) ;
return 0 ;
}
F_119 ( & V_20 -> V_27 , 1 ) ;
F_38 ( & V_3 -> V_39 ) ;
F_120 ( & V_20 -> V_38 ) ;
F_27 ( V_20 ) ;
return 1 ;
}
static int F_121 ( struct V_2 * V_3 , int V_68 )
{
struct V_230 * V_231 ;
int V_232 = F_122 ( V_3 -> V_25 , V_3 -> V_74 ) ;
if ( V_3 -> V_49 -> V_233 )
sprintf ( V_3 -> V_234 [ 0 ] ,
L_17 , V_3 -> V_211 , F_123 ( V_3 -> V_49 ) ) ;
else
sprintf ( V_3 -> V_234 [ 0 ] ,
L_18 , V_3 -> V_211 , V_3 -> V_49 ) ;
sprintf ( V_3 -> V_234 [ 1 ] , L_19 , V_3 -> V_234 [ 0 ] ) ;
V_3 -> V_235 = 0 ;
V_231 = F_124 ( V_3 -> V_234 [ V_3 -> V_235 ] ,
sizeof( struct V_19 ) + ( V_232 - 1 ) * sizeof( struct V_75 ) ,
0 , 0 , NULL ) ;
if ( ! V_231 )
return 1 ;
V_3 -> V_229 = V_231 ;
V_3 -> V_69 = V_232 ;
while ( V_68 -- )
if ( ! F_114 ( V_3 ) )
return 1 ;
return 0 ;
}
static T_4 F_125 ( int V_68 )
{
T_4 V_160 ;
V_160 = sizeof( struct V_65 * ) * ( V_68 + 2 ) + sizeof( T_2 ) * ( V_68 + 2 ) ;
return V_160 ;
}
static int F_126 ( struct V_2 * V_3 , int V_236 )
{
struct V_19 * V_237 , * V_238 ;
F_127 ( V_239 ) ;
struct V_240 * V_241 ;
unsigned long V_212 ;
int V_242 ;
struct V_230 * V_231 ;
int V_67 ;
if ( V_236 <= V_3 -> V_69 )
return 0 ;
V_242 = F_128 ( V_3 -> V_49 ) ;
if ( V_242 )
return V_242 ;
V_231 = F_124 ( V_3 -> V_234 [ 1 - V_3 -> V_235 ] ,
sizeof( struct V_19 ) + ( V_236 - 1 ) * sizeof( struct V_75 ) ,
0 , 0 , NULL ) ;
if ( ! V_231 )
return - V_243 ;
for ( V_67 = V_3 -> V_97 ; V_67 ; V_67 -- ) {
V_238 = F_115 ( V_231 , V_71 ) ;
if ( ! V_238 )
break;
V_238 -> V_57 = V_3 ;
#ifdef F_116
F_117 ( & V_238 -> V_173 . V_228 ) ;
#endif
F_129 ( & V_238 -> V_38 , & V_239 ) ;
}
if ( V_67 ) {
while ( ! F_18 ( & V_239 ) ) {
V_238 = F_36 ( V_239 . V_64 , struct V_19 , V_38 ) ;
F_130 ( & V_238 -> V_38 ) ;
F_118 ( V_231 , V_238 ) ;
}
F_131 ( V_231 ) ;
return - V_243 ;
}
F_132 (nsh, &newstripes, lru) {
F_56 ( & V_3 -> V_59 ) ;
F_57 ( V_3 -> V_55 ,
! F_18 ( & V_3 -> V_54 ) ,
V_3 -> V_59 ,
) ;
V_237 = F_35 ( V_3 ) ;
F_59 ( & V_3 -> V_59 ) ;
F_119 ( & V_238 -> V_27 , 1 ) ;
for( V_67 = 0 ; V_67 < V_3 -> V_69 ; V_67 ++ )
V_238 -> V_70 [ V_67 ] . V_65 = V_237 -> V_70 [ V_67 ] . V_65 ;
for( ; V_67 < V_236 ; V_67 ++ )
V_238 -> V_70 [ V_67 ] . V_65 = NULL ;
F_118 ( V_3 -> V_229 , V_237 ) ;
}
F_131 ( V_3 -> V_229 ) ;
V_241 = F_133 ( V_236 * sizeof( struct V_240 ) , V_244 ) ;
if ( V_241 ) {
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ )
V_241 [ V_67 ] = V_3 -> V_23 [ V_67 ] ;
F_134 ( V_3 -> V_23 ) ;
V_3 -> V_23 = V_241 ;
} else
V_242 = - V_243 ;
F_135 () ;
V_3 -> F_125 = F_125 ( V_236 ) ;
F_136 (cpu) {
struct V_177 * V_178 ;
void * V_179 ;
V_178 = F_105 ( V_3 -> V_178 , V_212 ) ;
V_179 = F_137 ( V_3 -> F_125 , V_244 ) ;
if ( V_179 ) {
F_134 ( V_178 -> V_179 ) ;
V_178 -> V_179 = V_179 ;
} else {
V_242 = - V_243 ;
break;
}
}
F_138 () ;
while( ! F_18 ( & V_239 ) ) {
V_238 = F_36 ( V_239 . V_64 , struct V_19 , V_38 ) ;
F_37 ( & V_238 -> V_38 ) ;
for ( V_67 = V_3 -> V_25 ; V_67 < V_236 ; V_67 ++ )
if ( V_238 -> V_70 [ V_67 ] . V_65 == NULL ) {
struct V_65 * V_66 = F_42 ( V_244 ) ;
V_238 -> V_70 [ V_67 ] . V_65 = V_66 ;
if ( ! V_66 )
V_242 = - V_243 ;
}
F_27 ( V_238 ) ;
}
V_3 -> V_229 = V_231 ;
V_3 -> V_235 = 1 - V_3 -> V_235 ;
V_3 -> V_69 = V_236 ;
return V_242 ;
}
static int F_139 ( struct V_2 * V_3 )
{
struct V_19 * V_20 ;
F_56 ( & V_3 -> V_59 ) ;
V_20 = F_35 ( V_3 ) ;
F_59 ( & V_3 -> V_59 ) ;
if ( ! V_20 )
return 0 ;
F_17 ( F_19 ( & V_20 -> V_27 ) ) ;
F_39 ( V_20 ) ;
F_118 ( V_3 -> V_229 , V_20 ) ;
F_25 ( & V_3 -> V_39 ) ;
return 1 ;
}
static void F_140 ( struct V_2 * V_3 )
{
while ( F_139 ( V_3 ) )
;
if ( V_3 -> V_229 )
F_131 ( V_3 -> V_229 ) ;
V_3 -> V_229 = NULL ;
}
static void V_120 ( struct V_9 * V_32 , int error )
{
struct V_19 * V_20 = V_32 -> V_245 ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_23 = V_20 -> V_23 , V_67 ;
int V_246 = F_14 ( V_141 , & V_32 -> V_140 ) ;
char V_247 [ V_248 ] ;
struct V_86 * V_87 = NULL ;
T_1 V_101 ;
for ( V_67 = 0 ; V_67 < V_23 ; V_67 ++ )
if ( V_32 == & V_20 -> V_70 [ V_67 ] . V_115 )
break;
F_31 ( L_20 ,
( unsigned long long ) V_20 -> V_10 , V_67 , F_19 ( & V_20 -> V_27 ) ,
V_246 ) ;
if ( V_67 == V_23 ) {
F_58 () ;
return;
}
if ( F_14 ( V_122 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
V_87 = V_3 -> V_23 [ V_67 ] . V_121 ;
if ( ! V_87 )
V_87 = V_3 -> V_23 [ V_67 ] . V_87 ;
if ( F_60 ( V_3 , V_20 ) )
V_101 = V_20 -> V_10 + V_87 -> V_138 ;
else
V_101 = V_20 -> V_10 + V_87 -> V_139 ;
if ( V_246 ) {
F_66 ( V_171 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
if ( F_14 ( V_249 , & V_20 -> V_70 [ V_67 ] . V_58 ) ) {
F_141 (
V_250
L_21
L_22 ,
F_123 ( V_3 -> V_49 ) , V_14 ,
( unsigned long long ) V_101 ,
F_142 ( V_87 -> V_134 , V_247 ) ) ;
F_143 ( V_14 , & V_87 -> V_251 ) ;
F_21 ( V_249 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_21 ( V_252 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
}
if ( F_19 ( & V_87 -> V_253 ) )
F_119 ( & V_87 -> V_253 , 0 ) ;
} else {
const char * V_254 = F_142 ( V_87 -> V_134 , V_247 ) ;
int V_255 = 0 ;
int V_256 = 0 ;
F_21 ( V_171 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_38 ( & V_87 -> V_253 ) ;
if ( F_14 ( V_122 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
F_141 (
V_257
L_23
L_24 ,
F_123 ( V_3 -> V_49 ) ,
( unsigned long long ) V_101 ,
V_254 ) ;
else if ( V_3 -> V_49 -> V_84 >= V_3 -> V_92 ) {
V_256 = 1 ;
F_141 (
V_257
L_25
L_24 ,
F_123 ( V_3 -> V_49 ) ,
( unsigned long long ) V_101 ,
V_254 ) ;
} else if ( F_14 ( V_252 , & V_20 -> V_70 [ V_67 ] . V_58 ) ) {
V_256 = 1 ;
F_141 (
V_257
L_26
L_24 ,
F_123 ( V_3 -> V_49 ) ,
( unsigned long long ) V_101 ,
V_254 ) ;
} else if ( F_19 ( & V_87 -> V_253 )
> V_3 -> V_97 )
F_45 ( V_257
L_27 ,
F_123 ( V_3 -> V_49 ) , V_254 ) ;
else
V_255 = 1 ;
if ( V_255 )
F_66 ( V_249 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
else {
F_21 ( V_249 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_21 ( V_252 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
if ( ! ( V_256
&& F_14 ( V_89 , & V_87 -> V_58 )
&& F_144 (
V_87 , V_20 -> V_10 , V_14 , 0 ) ) )
F_145 ( V_3 -> V_49 , V_87 ) ;
}
}
F_69 ( V_87 , V_3 -> V_49 ) ;
F_21 ( V_80 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_66 ( V_40 , & V_20 -> V_36 ) ;
F_27 ( V_20 ) ;
}
static void V_119 ( struct V_9 * V_32 , int error )
{
struct V_19 * V_20 = V_32 -> V_245 ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_23 = V_20 -> V_23 , V_67 ;
struct V_86 * V_258 ( V_87 ) ;
int V_246 = F_14 ( V_141 , & V_32 -> V_140 ) ;
T_1 V_125 ;
int V_126 ;
int V_121 = 0 ;
for ( V_67 = 0 ; V_67 < V_23 ; V_67 ++ ) {
if ( V_32 == & V_20 -> V_70 [ V_67 ] . V_115 ) {
V_87 = V_3 -> V_23 [ V_67 ] . V_87 ;
break;
}
if ( V_32 == & V_20 -> V_70 [ V_67 ] . V_116 ) {
V_87 = V_3 -> V_23 [ V_67 ] . V_121 ;
if ( V_87 )
V_121 = 1 ;
else
V_87 = V_3 -> V_23 [ V_67 ] . V_87 ;
break;
}
}
F_31 ( L_28 ,
( unsigned long long ) V_20 -> V_10 , V_67 , F_19 ( & V_20 -> V_27 ) ,
V_246 ) ;
if ( V_67 == V_23 ) {
F_58 () ;
return;
}
if ( V_121 ) {
if ( ! V_246 )
F_145 ( V_3 -> V_49 , V_87 ) ;
else if ( F_65 ( V_87 , V_20 -> V_10 ,
V_14 ,
& V_125 , & V_126 ) )
F_66 ( V_259 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
} else {
if ( ! V_246 ) {
F_66 ( V_124 , & V_87 -> V_58 ) ;
F_66 ( V_260 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
if ( ! F_146 ( V_261 , & V_87 -> V_58 ) )
F_66 ( V_262 ,
& V_87 -> V_49 -> V_263 ) ;
} else if ( F_65 ( V_87 , V_20 -> V_10 ,
V_14 ,
& V_125 , & V_126 ) )
F_66 ( V_264 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
}
F_69 ( V_87 , V_3 -> V_49 ) ;
if ( ! F_23 ( V_147 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
F_21 ( V_80 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_66 ( V_40 , & V_20 -> V_36 ) ;
F_27 ( V_20 ) ;
}
static void F_47 ( struct V_19 * V_20 , int V_67 , int V_72 )
{
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
F_147 ( & V_70 -> V_115 ) ;
V_70 -> V_115 . V_143 = & V_70 -> V_265 ;
V_70 -> V_115 . V_266 ++ ;
V_70 -> V_115 . V_267 ++ ;
V_70 -> V_115 . V_245 = V_20 ;
V_70 -> V_265 . V_163 = V_70 -> V_65 ;
F_147 ( & V_70 -> V_116 ) ;
V_70 -> V_116 . V_143 = & V_70 -> V_268 ;
V_70 -> V_116 . V_266 ++ ;
V_70 -> V_116 . V_267 ++ ;
V_70 -> V_116 . V_245 = V_20 ;
V_70 -> V_268 . V_163 = V_70 -> V_65 ;
V_70 -> V_58 = 0 ;
V_70 -> V_10 = F_148 ( V_20 , V_67 , V_72 ) ;
}
static void error ( struct V_49 * V_49 , struct V_86 * V_87 )
{
char V_247 [ V_248 ] ;
struct V_2 * V_3 = V_49 -> V_269 ;
unsigned long V_58 ;
F_31 ( L_29 ) ;
F_28 ( & V_3 -> V_59 , V_58 ) ;
F_21 ( V_89 , & V_87 -> V_58 ) ;
V_49 -> V_84 = F_50 ( V_3 ) ;
F_29 ( & V_3 -> V_59 , V_58 ) ;
F_66 ( V_270 , & V_49 -> V_263 ) ;
F_66 ( V_271 , & V_87 -> V_58 ) ;
F_66 ( V_88 , & V_87 -> V_58 ) ;
F_66 ( V_272 , & V_49 -> V_58 ) ;
F_45 ( V_273
L_30
L_31 ,
F_123 ( V_49 ) ,
F_142 ( V_87 -> V_134 , V_247 ) ,
F_123 ( V_49 ) ,
V_3 -> V_25 - V_49 -> V_84 ) ;
}
static T_1 F_149 ( struct V_2 * V_3 , T_1 V_274 ,
int V_72 , int * V_275 ,
struct V_19 * V_20 )
{
T_1 V_276 , V_277 ;
T_1 V_278 ;
unsigned int V_279 ;
int V_30 , V_22 ;
int V_21 = 0 ;
T_1 V_280 ;
int V_281 = V_72 ? V_3 -> V_282
: V_3 -> V_281 ;
int V_283 = V_72 ? V_3 -> V_284
: V_3 -> V_285 ;
int V_25 = V_72 ? V_3 -> V_74
: V_3 -> V_25 ;
int V_286 = V_25 - V_3 -> V_92 ;
V_279 = F_150 ( V_274 , V_283 ) ;
V_278 = V_274 ;
V_276 = V_278 ;
* V_275 = F_150 ( V_276 , V_286 ) ;
V_277 = V_276 ;
V_30 = V_22 = - 1 ;
switch( V_3 -> V_211 ) {
case 4 :
V_30 = V_286 ;
break;
case 5 :
switch ( V_281 ) {
case V_287 :
V_30 = V_286 - F_150 ( V_277 , V_25 ) ;
if ( * V_275 >= V_30 )
( * V_275 ) ++ ;
break;
case V_288 :
V_30 = F_150 ( V_277 , V_25 ) ;
if ( * V_275 >= V_30 )
( * V_275 ) ++ ;
break;
case V_289 :
V_30 = V_286 - F_150 ( V_277 , V_25 ) ;
* V_275 = ( V_30 + 1 + * V_275 ) % V_25 ;
break;
case V_290 :
V_30 = F_150 ( V_277 , V_25 ) ;
* V_275 = ( V_30 + 1 + * V_275 ) % V_25 ;
break;
case V_291 :
V_30 = 0 ;
( * V_275 ) ++ ;
break;
case V_292 :
V_30 = V_286 ;
break;
default:
F_58 () ;
}
break;
case 6 :
switch ( V_281 ) {
case V_287 :
V_30 = V_25 - 1 - F_150 ( V_277 , V_25 ) ;
V_22 = V_30 + 1 ;
if ( V_30 == V_25 - 1 ) {
( * V_275 ) ++ ;
V_22 = 0 ;
} else if ( * V_275 >= V_30 )
( * V_275 ) += 2 ;
break;
case V_288 :
V_30 = F_150 ( V_277 , V_25 ) ;
V_22 = V_30 + 1 ;
if ( V_30 == V_25 - 1 ) {
( * V_275 ) ++ ;
V_22 = 0 ;
} else if ( * V_275 >= V_30 )
( * V_275 ) += 2 ;
break;
case V_289 :
V_30 = V_25 - 1 - F_150 ( V_277 , V_25 ) ;
V_22 = ( V_30 + 1 ) % V_25 ;
* V_275 = ( V_30 + 2 + * V_275 ) % V_25 ;
break;
case V_290 :
V_30 = F_150 ( V_277 , V_25 ) ;
V_22 = ( V_30 + 1 ) % V_25 ;
* V_275 = ( V_30 + 2 + * V_275 ) % V_25 ;
break;
case V_291 :
V_30 = 0 ;
V_22 = 1 ;
( * V_275 ) += 2 ;
break;
case V_292 :
V_30 = V_286 ;
V_22 = V_286 + 1 ;
break;
case V_293 :
V_30 = F_150 ( V_277 , V_25 ) ;
V_22 = V_30 + 1 ;
if ( V_30 == V_25 - 1 ) {
( * V_275 ) ++ ;
V_22 = 0 ;
} else if ( * V_275 >= V_30 )
( * V_275 ) += 2 ;
V_21 = 1 ;
break;
case V_294 :
V_277 += 1 ;
V_30 = V_25 - 1 - F_150 ( V_277 , V_25 ) ;
V_22 = V_30 + 1 ;
if ( V_30 == V_25 - 1 ) {
( * V_275 ) ++ ;
V_22 = 0 ;
} else if ( * V_275 >= V_30 )
( * V_275 ) += 2 ;
V_21 = 1 ;
break;
case V_295 :
V_30 = V_25 - 1 - F_150 ( V_277 , V_25 ) ;
V_22 = ( V_30 + V_25 - 1 ) % V_25 ;
* V_275 = ( V_30 + 1 + * V_275 ) % V_25 ;
V_21 = 1 ;
break;
case V_296 :
V_30 = V_286 - F_150 ( V_277 , V_25 - 1 ) ;
if ( * V_275 >= V_30 )
( * V_275 ) ++ ;
V_22 = V_25 - 1 ;
break;
case V_297 :
V_30 = F_150 ( V_277 , V_25 - 1 ) ;
if ( * V_275 >= V_30 )
( * V_275 ) ++ ;
V_22 = V_25 - 1 ;
break;
case V_298 :
V_30 = V_286 - F_150 ( V_277 , V_25 - 1 ) ;
* V_275 = ( V_30 + 1 + * V_275 ) % ( V_25 - 1 ) ;
V_22 = V_25 - 1 ;
break;
case V_299 :
V_30 = F_150 ( V_277 , V_25 - 1 ) ;
* V_275 = ( V_30 + 1 + * V_275 ) % ( V_25 - 1 ) ;
V_22 = V_25 - 1 ;
break;
case V_300 :
V_30 = 0 ;
( * V_275 ) ++ ;
V_22 = V_25 - 1 ;
break;
default:
F_58 () ;
}
break;
}
if ( V_20 ) {
V_20 -> V_30 = V_30 ;
V_20 -> V_22 = V_22 ;
V_20 -> V_21 = V_21 ;
}
V_280 = ( T_1 ) V_276 * V_283 + V_279 ;
return V_280 ;
}
static T_1 F_148 ( struct V_19 * V_20 , int V_67 , int V_72 )
{
struct V_2 * V_3 = V_20 -> V_57 ;
int V_25 = V_20 -> V_23 ;
int V_286 = V_25 - V_3 -> V_92 ;
T_1 V_280 = V_20 -> V_10 , V_301 ;
int V_283 = V_72 ? V_3 -> V_284
: V_3 -> V_285 ;
int V_281 = V_72 ? V_3 -> V_282
: V_3 -> V_281 ;
T_1 V_276 ;
int V_279 ;
T_1 V_278 ;
int V_302 , V_275 = V_67 ;
T_1 V_274 ;
struct V_19 V_303 ;
V_279 = F_150 ( V_280 , V_283 ) ;
V_276 = V_280 ;
if ( V_67 == V_20 -> V_30 )
return 0 ;
switch( V_3 -> V_211 ) {
case 4 : break;
case 5 :
switch ( V_281 ) {
case V_287 :
case V_288 :
if ( V_67 > V_20 -> V_30 )
V_67 -- ;
break;
case V_289 :
case V_290 :
if ( V_67 < V_20 -> V_30 )
V_67 += V_25 ;
V_67 -= ( V_20 -> V_30 + 1 ) ;
break;
case V_291 :
V_67 -= 1 ;
break;
case V_292 :
break;
default:
F_58 () ;
}
break;
case 6 :
if ( V_67 == V_20 -> V_22 )
return 0 ;
switch ( V_281 ) {
case V_287 :
case V_288 :
case V_293 :
case V_294 :
if ( V_20 -> V_30 == V_25 - 1 )
V_67 -- ;
else if ( V_67 > V_20 -> V_30 )
V_67 -= 2 ;
break;
case V_289 :
case V_290 :
if ( V_20 -> V_30 == V_25 - 1 )
V_67 -- ;
else {
if ( V_67 < V_20 -> V_30 )
V_67 += V_25 ;
V_67 -= ( V_20 -> V_30 + 2 ) ;
}
break;
case V_291 :
V_67 -= 2 ;
break;
case V_292 :
break;
case V_295 :
if ( V_20 -> V_30 == 0 )
V_67 -- ;
else {
if ( V_67 < V_20 -> V_30 )
V_67 += V_25 ;
V_67 -= ( V_20 -> V_30 + 1 ) ;
}
break;
case V_296 :
case V_297 :
if ( V_67 > V_20 -> V_30 )
V_67 -- ;
break;
case V_298 :
case V_299 :
if ( V_67 < V_20 -> V_30 )
V_67 += V_286 + 1 ;
V_67 -= ( V_20 -> V_30 + 1 ) ;
break;
case V_300 :
V_67 -= 1 ;
break;
default:
F_58 () ;
}
break;
}
V_278 = V_276 * V_286 + V_67 ;
V_274 = V_278 * V_283 + V_279 ;
V_301 = F_149 ( V_3 , V_274 ,
V_72 , & V_302 , & V_303 ) ;
if ( V_301 != V_20 -> V_10 || V_302 != V_275 || V_303 . V_30 != V_20 -> V_30
|| V_303 . V_22 != V_20 -> V_22 ) {
F_45 ( V_81 L_32 ,
F_123 ( V_3 -> V_49 ) ) ;
return 0 ;
}
return V_274 ;
}
static void
F_151 ( struct V_19 * V_20 , struct V_100 * V_101 ,
int V_304 , int V_305 )
{
int V_67 , V_30 = V_20 -> V_30 , V_23 = V_20 -> V_23 ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_211 = V_3 -> V_211 ;
if ( V_304 ) {
if ( ! V_305 ) {
V_20 -> V_34 = V_198 ;
F_66 ( V_217 , & V_101 -> V_209 ) ;
} else
V_20 -> V_34 = V_202 ;
F_66 ( V_215 , & V_101 -> V_209 ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( V_70 -> V_78 ) {
F_66 ( V_80 , & V_70 -> V_58 ) ;
F_66 ( V_191 , & V_70 -> V_58 ) ;
if ( ! V_305 )
F_21 ( V_171 , & V_70 -> V_58 ) ;
V_101 -> V_306 ++ ;
}
}
if ( V_101 -> V_306 + V_3 -> V_92 == V_23 )
if ( ! F_146 ( V_307 , & V_20 -> V_36 ) )
F_38 ( & V_3 -> V_308 ) ;
} else {
F_17 ( V_211 == 6 ) ;
F_17 ( ! ( F_14 ( V_171 , & V_20 -> V_70 [ V_30 ] . V_58 ) ||
F_14 ( V_172 , & V_20 -> V_70 [ V_30 ] . V_58 ) ) ) ;
V_20 -> V_34 = V_200 ;
F_66 ( V_216 , & V_101 -> V_209 ) ;
F_66 ( V_217 , & V_101 -> V_209 ) ;
F_66 ( V_215 , & V_101 -> V_209 ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( V_67 == V_30 )
continue;
if ( V_70 -> V_78 &&
( F_14 ( V_171 , & V_70 -> V_58 ) ||
F_14 ( V_172 , & V_70 -> V_58 ) ) ) {
F_66 ( V_191 , & V_70 -> V_58 ) ;
F_66 ( V_80 , & V_70 -> V_58 ) ;
F_21 ( V_171 , & V_70 -> V_58 ) ;
V_101 -> V_306 ++ ;
}
}
}
F_66 ( V_80 , & V_20 -> V_70 [ V_30 ] . V_58 ) ;
F_21 ( V_171 , & V_20 -> V_70 [ V_30 ] . V_58 ) ;
V_101 -> V_306 ++ ;
if ( V_211 == 6 ) {
int V_22 = V_20 -> V_22 ;
struct V_75 * V_70 = & V_20 -> V_70 [ V_22 ] ;
F_66 ( V_80 , & V_70 -> V_58 ) ;
F_21 ( V_171 , & V_70 -> V_58 ) ;
V_101 -> V_306 ++ ;
}
F_31 ( L_33 ,
V_137 , ( unsigned long long ) V_20 -> V_10 ,
V_101 -> V_306 , V_101 -> V_209 ) ;
}
static int F_152 ( struct V_19 * V_20 , struct V_9 * V_32 , int V_275 , int V_309 )
{
struct V_9 * * V_310 ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_311 = 0 ;
F_31 ( L_34 ,
( unsigned long long ) V_32 -> V_13 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_56 ( & V_3 -> V_59 ) ;
if ( V_309 ) {
V_310 = & V_20 -> V_70 [ V_275 ] . V_78 ;
if ( * V_310 == NULL && V_20 -> V_70 [ V_275 ] . V_79 == NULL )
V_311 = 1 ;
} else
V_310 = & V_20 -> V_70 [ V_275 ] . V_76 ;
while ( * V_310 && ( * V_310 ) -> V_13 < V_32 -> V_13 ) {
if ( ( * V_310 ) -> V_13 + ( ( * V_310 ) -> V_12 >> 9 ) > V_32 -> V_13 )
goto V_312;
V_310 = & ( * V_310 ) -> V_15 ;
}
if ( * V_310 && ( * V_310 ) -> V_13 < V_32 -> V_13 + ( ( V_32 -> V_12 ) >> 9 ) )
goto V_312;
F_17 ( * V_310 && V_32 -> V_15 && ( * V_310 ) != V_32 -> V_15 ) ;
if ( * V_310 )
V_32 -> V_15 = * V_310 ;
* V_310 = V_32 ;
V_32 -> V_16 ++ ;
if ( V_309 ) {
T_1 V_10 = V_20 -> V_70 [ V_275 ] . V_10 ;
for ( V_32 = V_20 -> V_70 [ V_275 ] . V_78 ;
V_10 < V_20 -> V_70 [ V_275 ] . V_10 + V_14 &&
V_32 && V_32 -> V_13 <= V_10 ;
V_32 = F_2 ( V_32 , V_20 -> V_70 [ V_275 ] . V_10 ) ) {
if ( V_32 -> V_13 + ( V_32 -> V_12 >> 9 ) >= V_10 )
V_10 = V_32 -> V_13 + ( V_32 -> V_12 >> 9 ) ;
}
if ( V_10 >= V_20 -> V_70 [ V_275 ] . V_10 + V_14 )
F_66 ( V_313 , & V_20 -> V_70 [ V_275 ] . V_58 ) ;
}
F_59 ( & V_3 -> V_59 ) ;
F_31 ( L_35 ,
( unsigned long long ) ( * V_310 ) -> V_13 ,
( unsigned long long ) V_20 -> V_10 , V_275 ) ;
if ( V_3 -> V_49 -> V_314 && V_311 ) {
F_153 ( V_3 -> V_49 -> V_314 , V_20 -> V_10 ,
V_14 , 0 ) ;
V_20 -> V_45 = V_3 -> V_315 + 1 ;
F_66 ( V_44 , & V_20 -> V_36 ) ;
}
return 1 ;
V_312:
F_66 ( V_222 , & V_20 -> V_70 [ V_275 ] . V_58 ) ;
F_59 ( & V_3 -> V_59 ) ;
return 0 ;
}
static void F_44 ( T_1 V_276 , struct V_2 * V_3 , int V_72 ,
struct V_19 * V_20 )
{
int V_283 =
V_72 ? V_3 -> V_284 : V_3 -> V_285 ;
int V_275 ;
int V_279 = F_150 ( V_276 , V_283 ) ;
int V_23 = V_72 ? V_3 -> V_74 : V_3 -> V_25 ;
F_149 ( V_3 ,
V_276 * ( V_23 - V_3 -> V_92 )
* V_283 + V_279 ,
V_72 ,
& V_275 , V_20 ) ;
}
static void
F_154 ( struct V_2 * V_3 , struct V_19 * V_20 ,
struct V_100 * V_101 , int V_23 ,
struct V_9 * * V_31 )
{
int V_67 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_9 * V_32 ;
int V_316 = 0 ;
if ( F_14 ( V_249 , & V_20 -> V_70 [ V_67 ] . V_58 ) ) {
struct V_86 * V_87 ;
F_51 () ;
V_87 = F_52 ( V_3 -> V_23 [ V_67 ] . V_87 ) ;
if ( V_87 && F_14 ( V_89 , & V_87 -> V_58 ) )
F_38 ( & V_87 -> V_123 ) ;
else
V_87 = NULL ;
F_53 () ;
if ( V_87 ) {
if ( ! F_144 (
V_87 ,
V_20 -> V_10 ,
V_14 , 0 ) )
F_145 ( V_3 -> V_49 , V_87 ) ;
F_69 ( V_87 , V_3 -> V_49 ) ;
}
}
F_56 ( & V_3 -> V_59 ) ;
V_32 = V_20 -> V_70 [ V_67 ] . V_78 ;
V_20 -> V_70 [ V_67 ] . V_78 = NULL ;
if ( V_32 ) {
V_101 -> V_317 -- ;
V_316 = 1 ;
}
if ( F_23 ( V_222 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
F_26 ( & V_3 -> V_223 ) ;
while ( V_32 && V_32 -> V_13 <
V_20 -> V_70 [ V_67 ] . V_10 + V_14 ) {
struct V_9 * V_318 = F_2 ( V_32 , V_20 -> V_70 [ V_67 ] . V_10 ) ;
F_21 ( V_141 , & V_32 -> V_140 ) ;
if ( ! F_5 ( V_32 ) ) {
F_155 ( V_3 -> V_49 ) ;
V_32 -> V_15 = * V_31 ;
* V_31 = V_32 ;
}
V_32 = V_318 ;
}
V_32 = V_20 -> V_70 [ V_67 ] . V_79 ;
V_20 -> V_70 [ V_67 ] . V_79 = NULL ;
if ( V_32 ) V_316 = 1 ;
while ( V_32 && V_32 -> V_13 <
V_20 -> V_70 [ V_67 ] . V_10 + V_14 ) {
struct V_9 * V_319 = F_2 ( V_32 , V_20 -> V_70 [ V_67 ] . V_10 ) ;
F_21 ( V_141 , & V_32 -> V_140 ) ;
if ( ! F_5 ( V_32 ) ) {
F_155 ( V_3 -> V_49 ) ;
V_32 -> V_15 = * V_31 ;
* V_31 = V_32 ;
}
V_32 = V_319 ;
}
if ( ! F_14 ( V_166 , & V_20 -> V_70 [ V_67 ] . V_58 ) &&
( ! F_14 ( V_320 , & V_20 -> V_70 [ V_67 ] . V_58 ) ||
F_14 ( V_249 , & V_20 -> V_70 [ V_67 ] . V_58 ) ) ) {
V_32 = V_20 -> V_70 [ V_67 ] . V_76 ;
V_20 -> V_70 [ V_67 ] . V_76 = NULL ;
if ( F_23 ( V_222 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
F_26 ( & V_3 -> V_223 ) ;
if ( V_32 ) V_101 -> V_321 -- ;
while ( V_32 && V_32 -> V_13 <
V_20 -> V_70 [ V_67 ] . V_10 + V_14 ) {
struct V_9 * V_318 =
F_2 ( V_32 , V_20 -> V_70 [ V_67 ] . V_10 ) ;
F_21 ( V_141 , & V_32 -> V_140 ) ;
if ( ! F_5 ( V_32 ) ) {
V_32 -> V_15 = * V_31 ;
* V_31 = V_32 ;
}
V_32 = V_318 ;
}
}
F_59 ( & V_3 -> V_59 ) ;
if ( V_316 )
F_156 ( V_3 -> V_49 -> V_314 , V_20 -> V_10 ,
V_14 , 0 , 0 ) ;
F_21 ( V_80 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
}
if ( F_23 ( V_307 , & V_20 -> V_36 ) )
if ( F_16 ( & V_3 -> V_308 ) )
F_22 ( V_3 -> V_49 -> V_50 ) ;
}
static void
F_157 ( struct V_2 * V_3 , struct V_19 * V_20 ,
struct V_100 * V_101 )
{
int abort = 0 ;
int V_67 ;
F_21 ( V_322 , & V_20 -> V_36 ) ;
V_101 -> V_130 = 0 ;
V_101 -> V_133 = 0 ;
if ( F_14 ( V_323 , & V_3 -> V_49 -> V_263 ) ) {
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ ) {
struct V_86 * V_87 = V_3 -> V_23 [ V_67 ] . V_87 ;
if ( V_87
&& ! F_14 ( V_88 , & V_87 -> V_58 )
&& ! F_14 ( V_89 , & V_87 -> V_58 )
&& ! F_144 ( V_87 , V_20 -> V_10 ,
V_14 , 0 ) )
abort = 1 ;
V_87 = V_3 -> V_23 [ V_67 ] . V_121 ;
if ( V_87
&& ! F_14 ( V_88 , & V_87 -> V_58 )
&& ! F_14 ( V_89 , & V_87 -> V_58 )
&& ! F_144 ( V_87 , V_20 -> V_10 ,
V_14 , 0 ) )
abort = 1 ;
}
if ( abort )
V_3 -> V_324 =
V_3 -> V_49 -> V_324 ;
}
F_158 ( V_3 -> V_49 , V_14 , ! abort ) ;
}
static int F_159 ( struct V_19 * V_20 , int V_325 )
{
struct V_86 * V_87 ;
int V_326 = 0 ;
V_87 = V_20 -> V_57 -> V_23 [ V_325 ] . V_121 ;
if ( V_87
&& ! F_14 ( V_88 , & V_87 -> V_58 )
&& ! F_14 ( V_89 , & V_87 -> V_58 )
&& ( V_87 -> V_327 <= V_20 -> V_10
|| V_87 -> V_49 -> V_328 <= V_20 -> V_10 ) )
V_326 = 1 ;
return V_326 ;
}
static int F_160 ( struct V_19 * V_20 , struct V_100 * V_101 ,
int V_325 , int V_23 )
{
struct V_75 * V_70 = & V_20 -> V_70 [ V_325 ] ;
struct V_75 * V_329 [ 2 ] = { & V_20 -> V_70 [ V_101 -> V_330 [ 0 ] ] ,
& V_20 -> V_70 [ V_101 -> V_330 [ 1 ] ] } ;
if ( ! F_14 ( V_80 , & V_70 -> V_58 ) &&
! F_14 ( V_171 , & V_70 -> V_58 ) &&
( V_70 -> V_76 ||
( V_70 -> V_78 && ! F_14 ( V_313 , & V_70 -> V_58 ) ) ||
V_101 -> V_130 || V_101 -> V_131 ||
( V_101 -> V_133 && F_159 ( V_20 , V_325 ) ) ||
( V_101 -> V_331 >= 1 && V_329 [ 0 ] -> V_76 ) ||
( V_101 -> V_331 >= 2 && V_329 [ 1 ] -> V_76 ) ||
( V_20 -> V_57 -> V_211 <= 5 && V_101 -> V_331 && V_329 [ 0 ] -> V_78 &&
! F_14 ( V_313 , & V_329 [ 0 ] -> V_58 ) ) ||
( V_20 -> V_57 -> V_211 == 6 && V_101 -> V_331 && V_101 -> V_317 ) ) ) {
F_17 ( F_14 ( V_172 , & V_70 -> V_58 ) ) ;
F_17 ( F_14 ( V_110 , & V_70 -> V_58 ) ) ;
if ( ( V_101 -> V_246 == V_23 - 1 ) &&
( V_101 -> V_331 && ( V_325 == V_101 -> V_330 [ 0 ] ||
V_325 == V_101 -> V_330 [ 1 ] ) ) ) {
F_31 ( L_36 ,
( unsigned long long ) V_20 -> V_10 , V_325 ) ;
F_66 ( V_37 , & V_20 -> V_36 ) ;
F_66 ( V_214 , & V_101 -> V_209 ) ;
F_66 ( V_172 , & V_70 -> V_58 ) ;
V_20 -> V_173 . V_169 = V_325 ;
V_20 -> V_173 . V_174 = - 1 ;
V_101 -> V_332 = 1 ;
V_101 -> V_246 ++ ;
return 1 ;
} else if ( V_101 -> V_246 == V_23 - 2 && V_101 -> V_331 >= 2 ) {
int V_333 ;
for ( V_333 = V_23 ; V_333 -- ; ) {
if ( V_333 == V_325 )
continue;
if ( ! F_14 ( V_171 ,
& V_20 -> V_70 [ V_333 ] . V_58 ) )
break;
}
F_17 ( V_333 < 0 ) ;
F_31 ( L_37 ,
( unsigned long long ) V_20 -> V_10 ,
V_325 , V_333 ) ;
F_66 ( V_37 , & V_20 -> V_36 ) ;
F_66 ( V_214 , & V_101 -> V_209 ) ;
F_66 ( V_172 , & V_20 -> V_70 [ V_325 ] . V_58 ) ;
F_66 ( V_172 , & V_20 -> V_70 [ V_333 ] . V_58 ) ;
V_20 -> V_173 . V_169 = V_325 ;
V_20 -> V_173 . V_174 = V_333 ;
V_101 -> V_246 += 2 ;
V_101 -> V_332 = 1 ;
return 1 ;
} else if ( F_14 ( V_320 , & V_70 -> V_58 ) ) {
F_66 ( V_80 , & V_70 -> V_58 ) ;
F_66 ( V_110 , & V_70 -> V_58 ) ;
V_101 -> V_306 ++ ;
F_31 ( L_38 ,
V_325 , V_101 -> V_130 ) ;
}
}
return 0 ;
}
static void F_161 ( struct V_19 * V_20 ,
struct V_100 * V_101 ,
int V_23 )
{
int V_67 ;
if ( ! F_14 ( V_37 , & V_20 -> V_36 ) && ! V_20 -> V_33 &&
! V_20 -> V_34 )
for ( V_67 = V_23 ; V_67 -- ; )
if ( F_160 ( V_20 , V_101 , V_67 , V_23 ) )
break;
F_66 ( V_40 , & V_20 -> V_36 ) ;
}
static void F_162 ( struct V_2 * V_3 ,
struct V_19 * V_20 , int V_23 , struct V_9 * * V_31 )
{
int V_67 ;
struct V_75 * V_70 ;
for ( V_67 = V_23 ; V_67 -- ; )
if ( V_20 -> V_70 [ V_67 ] . V_79 ) {
V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( ! F_14 ( V_80 , & V_70 -> V_58 ) &&
F_14 ( V_171 , & V_70 -> V_58 ) ) {
struct V_9 * V_194 , * V_334 ;
int V_316 = 0 ;
F_31 ( L_39 , V_67 ) ;
F_56 ( & V_3 -> V_59 ) ;
V_194 = V_70 -> V_79 ;
V_70 -> V_79 = NULL ;
while ( V_194 && V_194 -> V_13 <
V_70 -> V_10 + V_14 ) {
V_334 = F_2 ( V_194 , V_70 -> V_10 ) ;
if ( ! F_5 ( V_194 ) ) {
F_155 ( V_3 -> V_49 ) ;
V_194 -> V_15 = * V_31 ;
* V_31 = V_194 ;
}
V_194 = V_334 ;
}
if ( V_70 -> V_78 == NULL )
V_316 = 1 ;
F_59 ( & V_3 -> V_59 ) ;
if ( V_316 )
F_156 ( V_3 -> V_49 -> V_314 ,
V_20 -> V_10 ,
V_14 ,
! F_14 ( V_148 , & V_20 -> V_36 ) ,
0 ) ;
}
}
if ( F_23 ( V_307 , & V_20 -> V_36 ) )
if ( F_16 ( & V_3 -> V_308 ) )
F_22 ( V_3 -> V_49 -> V_50 ) ;
}
static void F_163 ( struct V_2 * V_3 ,
struct V_19 * V_20 ,
struct V_100 * V_101 ,
int V_23 )
{
int V_335 = 0 , V_304 = 0 , V_67 ;
if ( V_3 -> V_92 == 2 ) {
V_304 = 1 ; V_335 = 2 ;
} else for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( ( V_70 -> V_78 || V_67 == V_20 -> V_30 ) &&
! F_14 ( V_80 , & V_70 -> V_58 ) &&
! ( F_14 ( V_171 , & V_70 -> V_58 ) ||
F_14 ( V_172 , & V_70 -> V_58 ) ) ) {
if ( F_14 ( V_320 , & V_70 -> V_58 ) )
V_335 ++ ;
else
V_335 += 2 * V_23 ;
}
if ( ! F_14 ( V_313 , & V_70 -> V_58 ) && V_67 != V_20 -> V_30 &&
! F_14 ( V_80 , & V_70 -> V_58 ) &&
! ( F_14 ( V_171 , & V_70 -> V_58 ) ||
F_14 ( V_172 , & V_70 -> V_58 ) ) ) {
if ( F_14 ( V_320 , & V_70 -> V_58 ) ) V_304 ++ ;
else
V_304 += 2 * V_23 ;
}
}
F_31 ( L_40 ,
( unsigned long long ) V_20 -> V_10 , V_335 , V_304 ) ;
F_66 ( V_40 , & V_20 -> V_36 ) ;
if ( V_335 < V_304 && V_335 > 0 )
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( ( V_70 -> V_78 || V_67 == V_20 -> V_30 ) &&
! F_14 ( V_80 , & V_70 -> V_58 ) &&
! ( F_14 ( V_171 , & V_70 -> V_58 ) ||
F_14 ( V_172 , & V_70 -> V_58 ) ) &&
F_14 ( V_320 , & V_70 -> V_58 ) ) {
if (
F_14 ( V_42 , & V_20 -> V_36 ) ) {
F_31 ( L_41
L_42 , V_67 ) ;
F_66 ( V_80 , & V_70 -> V_58 ) ;
F_66 ( V_110 , & V_70 -> V_58 ) ;
V_101 -> V_306 ++ ;
} else {
F_66 ( V_41 , & V_20 -> V_36 ) ;
F_66 ( V_40 , & V_20 -> V_36 ) ;
}
}
}
if ( V_304 <= V_335 && V_304 > 0 ) {
V_304 = 0 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( ! F_14 ( V_313 , & V_70 -> V_58 ) &&
V_67 != V_20 -> V_30 && V_67 != V_20 -> V_22 &&
! F_14 ( V_80 , & V_70 -> V_58 ) &&
! ( F_14 ( V_171 , & V_70 -> V_58 ) ||
F_14 ( V_172 , & V_70 -> V_58 ) ) ) {
V_304 ++ ;
if ( ! F_14 ( V_320 , & V_70 -> V_58 ) )
continue;
if (
F_14 ( V_42 , & V_20 -> V_36 ) ) {
F_31 ( L_41
L_43 , V_67 ) ;
F_66 ( V_80 , & V_70 -> V_58 ) ;
F_66 ( V_110 , & V_70 -> V_58 ) ;
V_101 -> V_306 ++ ;
} else {
F_66 ( V_41 , & V_20 -> V_36 ) ;
F_66 ( V_40 , & V_20 -> V_36 ) ;
}
}
}
}
if ( ( V_101 -> V_332 || ! F_14 ( V_37 , & V_20 -> V_36 ) ) &&
( V_101 -> V_306 == 0 && ( V_304 == 0 || V_335 == 0 ) &&
! F_14 ( V_44 , & V_20 -> V_36 ) ) )
F_151 ( V_20 , V_101 , V_304 == 0 , 0 ) ;
}
static void F_164 ( struct V_2 * V_3 , struct V_19 * V_20 ,
struct V_100 * V_101 , int V_23 )
{
struct V_75 * V_70 = NULL ;
F_66 ( V_40 , & V_20 -> V_36 ) ;
switch ( V_20 -> V_33 ) {
case V_336 :
if ( V_101 -> V_331 == 0 ) {
F_17 ( V_101 -> V_246 != V_23 ) ;
V_20 -> V_33 = V_219 ;
F_66 ( V_218 , & V_101 -> V_209 ) ;
F_21 ( V_171 , & V_20 -> V_70 [ V_20 -> V_30 ] . V_58 ) ;
V_101 -> V_246 -- ;
break;
}
V_70 = & V_20 -> V_70 [ V_101 -> V_330 [ 0 ] ] ;
case V_176 :
V_20 -> V_33 = V_336 ;
if ( ! V_70 )
V_70 = & V_20 -> V_70 [ V_20 -> V_30 ] ;
if ( F_14 ( V_337 , & V_20 -> V_36 ) )
break;
F_17 ( ! F_14 ( V_171 , & V_70 -> V_58 ) ) ;
F_17 ( V_101 -> V_246 != V_23 ) ;
F_66 ( V_80 , & V_70 -> V_58 ) ;
V_101 -> V_306 ++ ;
F_66 ( V_106 , & V_70 -> V_58 ) ;
F_21 ( V_148 , & V_20 -> V_36 ) ;
F_66 ( V_337 , & V_20 -> V_36 ) ;
break;
case V_219 :
break;
case V_205 :
V_20 -> V_33 = V_336 ;
if ( V_101 -> V_331 )
break;
if ( ( V_20 -> V_173 . V_206 & V_338 ) == 0 )
F_66 ( V_337 , & V_20 -> V_36 ) ;
else {
V_3 -> V_49 -> V_339 += V_14 ;
if ( F_14 ( V_340 , & V_3 -> V_49 -> V_263 ) )
F_66 ( V_337 , & V_20 -> V_36 ) ;
else {
V_20 -> V_33 = V_175 ;
F_66 ( V_37 , & V_20 -> V_36 ) ;
F_66 ( V_214 , & V_101 -> V_209 ) ;
F_66 ( V_172 ,
& V_20 -> V_70 [ V_20 -> V_30 ] . V_58 ) ;
V_20 -> V_173 . V_169 = V_20 -> V_30 ;
V_20 -> V_173 . V_174 = - 1 ;
V_101 -> V_246 ++ ;
}
}
break;
case V_175 :
break;
default:
F_45 ( V_81 L_44 ,
V_137 , V_20 -> V_33 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_58 () ;
}
}
static void F_165 ( struct V_2 * V_3 , struct V_19 * V_20 ,
struct V_100 * V_101 ,
int V_23 )
{
int V_30 = V_20 -> V_30 ;
int V_22 = V_20 -> V_22 ;
struct V_75 * V_70 ;
F_66 ( V_40 , & V_20 -> V_36 ) ;
F_17 ( V_101 -> V_331 > 2 ) ;
switch ( V_20 -> V_33 ) {
case V_336 :
if ( V_101 -> V_331 == V_101 -> V_341 ) {
V_20 -> V_33 = V_219 ;
}
if ( ! V_101 -> V_341 && V_101 -> V_331 < 2 ) {
if ( V_20 -> V_33 == V_219 )
V_20 -> V_33 = V_221 ;
else
V_20 -> V_33 = V_220 ;
}
V_20 -> V_173 . V_206 = 0 ;
if ( V_20 -> V_33 == V_219 ) {
F_21 ( V_171 , & V_20 -> V_70 [ V_30 ] . V_58 ) ;
V_101 -> V_246 -- ;
}
if ( V_20 -> V_33 >= V_219 &&
V_20 -> V_33 <= V_221 ) {
F_66 ( V_218 , & V_101 -> V_209 ) ;
break;
}
F_17 ( V_101 -> V_331 != 2 ) ;
case V_176 :
V_20 -> V_33 = V_336 ;
if ( F_14 ( V_337 , & V_20 -> V_36 ) )
break;
F_17 ( V_101 -> V_246 < V_23 - 1 ) ;
if ( V_101 -> V_331 == 2 ) {
V_70 = & V_20 -> V_70 [ V_101 -> V_330 [ 1 ] ] ;
V_101 -> V_306 ++ ;
F_66 ( V_80 , & V_70 -> V_58 ) ;
F_66 ( V_106 , & V_70 -> V_58 ) ;
}
if ( V_101 -> V_331 >= 1 ) {
V_70 = & V_20 -> V_70 [ V_101 -> V_330 [ 0 ] ] ;
V_101 -> V_306 ++ ;
F_66 ( V_80 , & V_70 -> V_58 ) ;
F_66 ( V_106 , & V_70 -> V_58 ) ;
}
if ( V_20 -> V_173 . V_206 & V_338 ) {
V_70 = & V_20 -> V_70 [ V_30 ] ;
V_101 -> V_306 ++ ;
F_66 ( V_80 , & V_70 -> V_58 ) ;
F_66 ( V_106 , & V_70 -> V_58 ) ;
}
if ( V_20 -> V_173 . V_206 & V_342 ) {
V_70 = & V_20 -> V_70 [ V_22 ] ;
V_101 -> V_306 ++ ;
F_66 ( V_80 , & V_70 -> V_58 ) ;
F_66 ( V_106 , & V_70 -> V_58 ) ;
}
F_21 ( V_148 , & V_20 -> V_36 ) ;
F_66 ( V_337 , & V_20 -> V_36 ) ;
break;
case V_219 :
case V_220 :
case V_221 :
break;
case V_205 :
V_20 -> V_33 = V_336 ;
if ( V_20 -> V_173 . V_206 == 0 ) {
if ( ! V_101 -> V_331 )
F_66 ( V_337 , & V_20 -> V_36 ) ;
else {
V_20 -> V_33 = V_176 ;
}
} else {
V_3 -> V_49 -> V_339 += V_14 ;
if ( F_14 ( V_340 , & V_3 -> V_49 -> V_263 ) )
F_66 ( V_337 , & V_20 -> V_36 ) ;
else {
int * V_169 = & V_20 -> V_173 . V_169 ;
V_20 -> V_173 . V_169 = - 1 ;
V_20 -> V_173 . V_174 = - 1 ;
V_20 -> V_33 = V_175 ;
F_66 ( V_37 , & V_20 -> V_36 ) ;
F_66 ( V_214 , & V_101 -> V_209 ) ;
if ( V_20 -> V_173 . V_206 & V_338 ) {
F_66 ( V_172 ,
& V_20 -> V_70 [ V_30 ] . V_58 ) ;
* V_169 = V_30 ;
V_169 = & V_20 -> V_173 . V_174 ;
V_101 -> V_246 ++ ;
}
if ( V_20 -> V_173 . V_206 & V_342 ) {
F_66 ( V_172 ,
& V_20 -> V_70 [ V_22 ] . V_58 ) ;
* V_169 = V_22 ;
V_101 -> V_246 ++ ;
}
}
}
break;
case V_175 :
break;
default:
F_45 ( V_81 L_44 ,
V_137 , V_20 -> V_33 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_58 () ;
}
}
static void F_166 ( struct V_2 * V_3 , struct V_19 * V_20 )
{
int V_67 ;
struct V_149 * V_151 = NULL ;
F_21 ( V_343 , & V_20 -> V_36 ) ;
for ( V_67 = 0 ; V_67 < V_20 -> V_23 ; V_67 ++ )
if ( V_67 != V_20 -> V_30 && V_67 != V_20 -> V_22 ) {
int V_275 , V_344 ;
struct V_19 * V_303 ;
struct V_156 V_157 ;
T_1 V_345 = F_148 ( V_20 , V_67 , 1 ) ;
T_1 V_101 = F_149 ( V_3 , V_345 , 0 ,
& V_275 , NULL ) ;
V_303 = F_55 ( V_3 , V_101 , 0 , 1 , 1 ) ;
if ( V_303 == NULL )
continue;
if ( ! F_14 ( V_53 , & V_303 -> V_36 ) ||
F_14 ( V_346 , & V_303 -> V_70 [ V_275 ] . V_58 ) ) {
F_27 ( V_303 ) ;
continue;
}
F_73 ( & V_157 , 0 , V_151 , NULL , NULL , NULL ) ;
V_151 = F_75 ( V_303 -> V_70 [ V_275 ] . V_65 ,
V_20 -> V_70 [ V_67 ] . V_65 , 0 , 0 , V_145 ,
& V_157 ) ;
F_66 ( V_346 , & V_303 -> V_70 [ V_275 ] . V_58 ) ;
F_66 ( V_171 , & V_303 -> V_70 [ V_275 ] . V_58 ) ;
for ( V_344 = 0 ; V_344 < V_3 -> V_25 ; V_344 ++ )
if ( V_344 != V_303 -> V_30 &&
V_344 != V_303 -> V_22 &&
! F_14 ( V_346 , & V_303 -> V_70 [ V_344 ] . V_58 ) )
break;
if ( V_344 == V_3 -> V_25 ) {
F_66 ( V_347 , & V_303 -> V_36 ) ;
F_66 ( V_40 , & V_303 -> V_36 ) ;
}
F_27 ( V_303 ) ;
}
if ( V_151 ) {
F_106 ( V_151 ) ;
F_167 ( V_151 ) ;
}
}
static void F_168 ( struct V_19 * V_20 , struct V_100 * V_101 )
{
struct V_2 * V_3 = V_20 -> V_57 ;
int V_23 = V_20 -> V_23 ;
struct V_75 * V_70 ;
int V_67 ;
int V_348 = 0 ;
memset ( V_101 , 0 , sizeof( * V_101 ) ) ;
V_101 -> V_131 = F_14 ( V_343 , & V_20 -> V_36 ) ;
V_101 -> V_132 = F_14 ( V_347 , & V_20 -> V_36 ) ;
V_101 -> V_330 [ 0 ] = - 1 ;
V_101 -> V_330 [ 1 ] = - 1 ;
F_51 () ;
F_56 ( & V_3 -> V_59 ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_86 * V_87 ;
T_1 V_125 ;
int V_126 ;
int V_349 = 0 ;
V_70 = & V_20 -> V_70 [ V_67 ] ;
F_31 ( L_45 ,
V_67 , V_70 -> V_58 ,
V_70 -> V_76 , V_70 -> V_78 , V_70 -> V_79 ) ;
if ( F_14 ( V_171 , & V_70 -> V_58 ) && V_70 -> V_76 &&
! F_14 ( V_35 , & V_20 -> V_36 ) )
F_66 ( V_166 , & V_70 -> V_58 ) ;
if ( F_14 ( V_80 , & V_70 -> V_58 ) )
V_101 -> V_306 ++ ;
if ( F_14 ( V_171 , & V_70 -> V_58 ) )
V_101 -> V_246 ++ ;
if ( F_14 ( V_172 , & V_70 -> V_58 ) ) {
V_101 -> V_350 ++ ;
F_17 ( V_101 -> V_350 > 2 ) ;
}
if ( F_14 ( V_166 , & V_70 -> V_58 ) )
V_101 -> V_351 ++ ;
else if ( V_70 -> V_76 )
V_101 -> V_321 ++ ;
if ( V_70 -> V_78 ) {
V_101 -> V_317 ++ ;
if ( ! F_14 ( V_313 , & V_70 -> V_58 ) )
V_101 -> V_352 ++ ;
}
if ( V_70 -> V_79 )
V_101 -> V_79 ++ ;
V_87 = F_52 ( V_3 -> V_23 [ V_67 ] . V_121 ) ;
if ( V_87 && ! F_14 ( V_88 , & V_87 -> V_58 ) &&
V_87 -> V_327 >= V_20 -> V_10 + V_14 &&
! F_65 ( V_87 , V_20 -> V_10 , V_14 ,
& V_125 , & V_126 ) )
F_66 ( V_122 , & V_70 -> V_58 ) ;
else {
if ( V_87 )
F_66 ( V_353 , & V_70 -> V_58 ) ;
V_87 = F_52 ( V_3 -> V_23 [ V_67 ] . V_87 ) ;
F_21 ( V_122 , & V_70 -> V_58 ) ;
}
if ( V_87 && F_14 ( V_88 , & V_87 -> V_58 ) )
V_87 = NULL ;
if ( V_87 ) {
V_349 = F_65 ( V_87 , V_20 -> V_10 , V_14 ,
& V_125 , & V_126 ) ;
if ( V_101 -> V_354 == NULL
&& ( F_14 ( V_271 , & V_87 -> V_58 )
|| V_349 < 0 ) ) {
if ( V_349 < 0 )
F_66 ( V_128 ,
& V_87 -> V_58 ) ;
V_101 -> V_354 = V_87 ;
F_38 ( & V_87 -> V_123 ) ;
}
}
F_21 ( V_320 , & V_70 -> V_58 ) ;
if ( ! V_87 )
;
else if ( V_349 ) {
if ( ! F_14 ( V_124 , & V_87 -> V_58 ) &&
F_14 ( V_171 , & V_70 -> V_58 ) ) {
F_66 ( V_320 , & V_70 -> V_58 ) ;
F_66 ( V_249 , & V_70 -> V_58 ) ;
}
} else if ( F_14 ( V_89 , & V_87 -> V_58 ) )
F_66 ( V_320 , & V_70 -> V_58 ) ;
else if ( V_20 -> V_10 + V_14 <= V_87 -> V_327 )
F_66 ( V_320 , & V_70 -> V_58 ) ;
else if ( F_14 ( V_171 , & V_70 -> V_58 ) &&
F_14 ( V_346 , & V_70 -> V_58 ) )
F_66 ( V_320 , & V_70 -> V_58 ) ;
if ( V_87 && F_14 ( V_260 , & V_70 -> V_58 ) ) {
struct V_86 * V_355 = F_52 (
V_3 -> V_23 [ V_67 ] . V_87 ) ;
if ( V_355 == V_87 )
F_21 ( V_320 , & V_70 -> V_58 ) ;
if ( V_355 && ! F_14 ( V_88 , & V_355 -> V_58 ) ) {
V_101 -> V_356 = 1 ;
F_38 ( & V_355 -> V_123 ) ;
} else
F_21 ( V_260 , & V_70 -> V_58 ) ;
}
if ( V_87 && F_14 ( V_264 , & V_70 -> V_58 ) ) {
struct V_86 * V_355 = F_52 (
V_3 -> V_23 [ V_67 ] . V_87 ) ;
if ( V_355 && ! F_14 ( V_88 , & V_355 -> V_58 ) ) {
V_101 -> V_356 = 1 ;
F_38 ( & V_355 -> V_123 ) ;
} else
F_21 ( V_264 , & V_70 -> V_58 ) ;
}
if ( F_14 ( V_259 , & V_70 -> V_58 ) ) {
struct V_86 * V_355 = F_52 (
V_3 -> V_23 [ V_67 ] . V_121 ) ;
if ( V_355 && ! F_14 ( V_88 , & V_355 -> V_58 ) ) {
V_101 -> V_356 = 1 ;
F_38 ( & V_355 -> V_123 ) ;
} else
F_21 ( V_259 , & V_70 -> V_58 ) ;
}
if ( ! F_14 ( V_320 , & V_70 -> V_58 ) ) {
F_21 ( V_249 , & V_70 -> V_58 ) ;
F_21 ( V_252 , & V_70 -> V_58 ) ;
}
if ( F_14 ( V_249 , & V_70 -> V_58 ) )
F_21 ( V_320 , & V_70 -> V_58 ) ;
if ( ! F_14 ( V_320 , & V_70 -> V_58 ) ) {
if ( V_101 -> V_331 < 2 )
V_101 -> V_330 [ V_101 -> V_331 ] = V_67 ;
V_101 -> V_331 ++ ;
if ( V_87 && ! F_14 ( V_88 , & V_87 -> V_58 ) )
V_348 = 1 ;
}
}
F_59 ( & V_3 -> V_59 ) ;
if ( F_14 ( V_322 , & V_20 -> V_36 ) ) {
if ( V_348 ||
V_20 -> V_10 >= V_3 -> V_49 -> V_328 ||
F_14 ( V_357 , & ( V_3 -> V_49 -> V_263 ) ) )
V_101 -> V_130 = 1 ;
else
V_101 -> V_133 = 1 ;
}
F_53 () ;
}
static void F_169 ( struct V_19 * V_20 )
{
struct V_100 V_101 ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_67 ;
int V_204 ;
int V_23 = V_20 -> V_23 ;
struct V_75 * V_358 , * V_359 ;
F_21 ( V_40 , & V_20 -> V_36 ) ;
if ( F_112 ( V_360 , & V_20 -> V_36 ) ) {
F_66 ( V_40 , & V_20 -> V_36 ) ;
return;
}
if ( F_23 ( V_361 , & V_20 -> V_36 ) ) {
F_66 ( V_322 , & V_20 -> V_36 ) ;
F_21 ( V_337 , & V_20 -> V_36 ) ;
}
F_21 ( V_41 , & V_20 -> V_36 ) ;
F_31 ( L_46
L_47 ,
( unsigned long long ) V_20 -> V_10 , V_20 -> V_36 ,
F_19 ( & V_20 -> V_27 ) , V_20 -> V_30 , V_20 -> V_22 ,
V_20 -> V_33 , V_20 -> V_34 ) ;
F_168 ( V_20 , & V_101 ) ;
if ( V_101 . V_356 ) {
F_66 ( V_40 , & V_20 -> V_36 ) ;
goto V_362;
}
if ( F_83 ( V_101 . V_354 ) ) {
if ( V_101 . V_130 || V_101 . V_131 || V_101 . V_132 ||
V_101 . V_133 || V_101 . V_317 || V_101 . V_79 ) {
F_66 ( V_40 , & V_20 -> V_36 ) ;
goto V_362;
}
F_69 ( V_101 . V_354 , V_3 -> V_49 ) ;
V_101 . V_354 = NULL ;
}
if ( V_101 . V_351 && ! F_14 ( V_35 , & V_20 -> V_36 ) ) {
F_66 ( V_213 , & V_101 . V_209 ) ;
F_66 ( V_35 , & V_20 -> V_36 ) ;
}
F_31 ( L_48
L_49 ,
V_101 . V_306 , V_101 . V_246 , V_101 . V_321 , V_101 . V_317 , V_101 . V_331 ,
V_101 . V_330 [ 0 ] , V_101 . V_330 [ 1 ] ) ;
if ( V_101 . V_331 > V_3 -> V_92 ) {
V_20 -> V_33 = 0 ;
V_20 -> V_34 = 0 ;
if ( V_101 . V_321 + V_101 . V_317 + V_101 . V_79 )
F_154 ( V_3 , V_20 , & V_101 , V_23 , & V_101 . V_31 ) ;
if ( V_101 . V_130 + V_101 . V_133 )
F_157 ( V_3 , V_20 , & V_101 ) ;
}
V_358 = & V_20 -> V_70 [ V_20 -> V_30 ] ;
V_101 . V_363 = ( V_101 . V_331 >= 1 && V_101 . V_330 [ 0 ] == V_20 -> V_30 )
|| ( V_101 . V_331 >= 2 && V_101 . V_330 [ 1 ] == V_20 -> V_30 ) ;
V_359 = & V_20 -> V_70 [ V_20 -> V_22 ] ;
V_101 . V_341 = ( V_101 . V_331 >= 1 && V_101 . V_330 [ 0 ] == V_20 -> V_22 )
|| ( V_101 . V_331 >= 2 && V_101 . V_330 [ 1 ] == V_20 -> V_22 )
|| V_3 -> V_211 < 6 ;
if ( V_101 . V_79 &&
( V_101 . V_363 || ( ( F_14 ( V_320 , & V_358 -> V_58 )
&& ! F_14 ( V_80 , & V_358 -> V_58 )
&& F_14 ( V_171 , & V_358 -> V_58 ) ) ) ) &&
( V_101 . V_341 || ( ( F_14 ( V_320 , & V_359 -> V_58 )
&& ! F_14 ( V_80 , & V_359 -> V_58 )
&& F_14 ( V_171 , & V_359 -> V_58 ) ) ) ) )
F_162 ( V_3 , V_20 , V_23 , & V_101 . V_31 ) ;
if ( V_101 . V_321 || V_101 . V_352
|| ( V_3 -> V_211 == 6 && V_101 . V_317 && V_101 . V_331 )
|| ( V_101 . V_130 && ( V_101 . V_246 + V_101 . V_350 < V_23 ) )
|| V_101 . V_133
|| V_101 . V_131 )
F_161 ( V_20 , & V_101 , V_23 ) ;
V_204 = 0 ;
if ( V_20 -> V_34 == V_201 )
V_204 = 1 ;
if ( V_20 -> V_34 == V_199 ||
V_20 -> V_34 == V_201 ) {
V_20 -> V_34 = V_364 ;
F_17 ( ! F_14 ( V_171 , & V_20 -> V_70 [ V_20 -> V_30 ] . V_58 ) ) ;
F_17 ( V_20 -> V_22 >= 0 &&
! F_14 ( V_171 , & V_20 -> V_70 [ V_20 -> V_22 ] . V_58 ) ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( F_14 ( V_80 , & V_70 -> V_58 ) &&
( V_67 == V_20 -> V_30 || V_67 == V_20 -> V_22 ||
V_70 -> V_79 ) ) {
F_31 ( L_50 , V_67 ) ;
F_66 ( V_106 , & V_70 -> V_58 ) ;
if ( V_204 )
continue;
if ( ! F_14 ( V_320 , & V_70 -> V_58 ) ||
( ( V_67 == V_20 -> V_30 || V_67 == V_20 -> V_22 ) &&
V_101 . V_331 == 0 ) )
F_66 ( V_337 , & V_20 -> V_36 ) ;
}
}
if ( F_23 ( V_42 , & V_20 -> V_36 ) )
V_101 . V_365 = 1 ;
}
if ( V_101 . V_317 && ! V_20 -> V_34 && ! V_20 -> V_33 )
F_163 ( V_3 , V_20 , & V_101 , V_23 ) ;
if ( V_20 -> V_33 ||
( V_101 . V_130 && V_101 . V_306 == 0 &&
! F_14 ( V_37 , & V_20 -> V_36 ) &&
! F_14 ( V_337 , & V_20 -> V_36 ) ) ) {
if ( V_3 -> V_211 == 6 )
F_165 ( V_3 , V_20 , & V_101 , V_23 ) ;
else
F_164 ( V_3 , V_20 , & V_101 , V_23 ) ;
}
if ( V_101 . V_133 && V_101 . V_306 == 0
&& ! F_14 ( V_337 , & V_20 -> V_36 ) ) {
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ )
if ( F_14 ( V_171 , & V_20 -> V_70 [ V_67 ] . V_58 ) &&
F_14 ( V_353 , & V_20 -> V_70 [ V_67 ] . V_58 ) ) {
F_66 ( V_112 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_66 ( V_80 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
V_101 . V_306 ++ ;
}
F_66 ( V_337 , & V_20 -> V_36 ) ;
}
if ( ( V_101 . V_130 || V_101 . V_133 ) && V_101 . V_306 == 0 &&
F_14 ( V_337 , & V_20 -> V_36 ) ) {
F_158 ( V_3 -> V_49 , V_14 , 1 ) ;
F_21 ( V_322 , & V_20 -> V_36 ) ;
}
if ( V_101 . V_331 <= V_3 -> V_92 && ! V_3 -> V_49 -> V_366 )
for ( V_67 = 0 ; V_67 < V_101 . V_331 ; V_67 ++ ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_101 . V_330 [ V_67 ] ] ;
if ( F_14 ( V_249 , & V_70 -> V_58 )
&& ! F_14 ( V_80 , & V_70 -> V_58 )
&& F_14 ( V_171 , & V_70 -> V_58 )
) {
if ( ! F_14 ( V_252 , & V_70 -> V_58 ) ) {
F_66 ( V_106 , & V_70 -> V_58 ) ;
F_66 ( V_252 , & V_70 -> V_58 ) ;
F_66 ( V_80 , & V_70 -> V_58 ) ;
V_101 . V_306 ++ ;
} else {
F_66 ( V_110 , & V_70 -> V_58 ) ;
F_66 ( V_80 , & V_70 -> V_58 ) ;
V_101 . V_306 ++ ;
}
}
}
if ( V_20 -> V_34 == V_203 ) {
struct V_19 * V_367
= F_55 ( V_3 , V_20 -> V_10 , 1 , 1 , 1 ) ;
if ( V_367 && F_14 ( V_343 , & V_367 -> V_36 ) ) {
F_66 ( V_41 , & V_20 -> V_36 ) ;
F_66 ( V_40 , & V_20 -> V_36 ) ;
if ( ! F_146 ( V_42 ,
& V_367 -> V_36 ) )
F_38 ( & V_3 -> V_51 ) ;
F_27 ( V_367 ) ;
goto V_362;
}
if ( V_367 )
F_27 ( V_367 ) ;
V_20 -> V_34 = V_364 ;
F_21 ( V_53 , & V_20 -> V_36 ) ;
for ( V_67 = V_3 -> V_25 ; V_67 -- ; ) {
F_66 ( V_106 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_66 ( V_80 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
V_101 . V_306 ++ ;
}
}
if ( V_101 . V_132 && F_14 ( V_53 , & V_20 -> V_36 ) &&
! V_20 -> V_34 ) {
V_20 -> V_23 = V_3 -> V_25 ;
F_44 ( V_20 -> V_10 , V_3 , 0 , V_20 ) ;
F_151 ( V_20 , & V_101 , 1 , 1 ) ;
} else if ( V_101 . V_132 && ! V_20 -> V_34 && V_101 . V_306 == 0 ) {
F_21 ( V_347 , & V_20 -> V_36 ) ;
F_25 ( & V_3 -> V_368 ) ;
F_26 ( & V_3 -> V_223 ) ;
F_158 ( V_3 -> V_49 , V_14 , 1 ) ;
}
if ( V_101 . V_131 && V_101 . V_306 == 0 &&
! F_14 ( V_37 , & V_20 -> V_36 ) )
F_166 ( V_3 , V_20 ) ;
V_362:
if ( F_83 ( V_101 . V_354 ) ) {
if ( V_3 -> V_49 -> V_129 )
F_68 ( V_101 . V_354 ,
V_3 -> V_49 ) ;
else
F_69 ( V_101 . V_354 ,
V_3 -> V_49 ) ;
}
if ( V_101 . V_356 )
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_86 * V_87 ;
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( F_23 ( V_260 , & V_70 -> V_58 ) ) {
V_87 = V_3 -> V_23 [ V_67 ] . V_87 ;
if ( ! F_144 ( V_87 , V_20 -> V_10 ,
V_14 , 0 ) )
F_145 ( V_3 -> V_49 , V_87 ) ;
F_69 ( V_87 , V_3 -> V_49 ) ;
}
if ( F_23 ( V_264 , & V_70 -> V_58 ) ) {
V_87 = V_3 -> V_23 [ V_67 ] . V_87 ;
F_170 ( V_87 , V_20 -> V_10 ,
V_14 , 0 ) ;
F_69 ( V_87 , V_3 -> V_49 ) ;
}
if ( F_23 ( V_259 , & V_70 -> V_58 ) ) {
V_87 = V_3 -> V_23 [ V_67 ] . V_121 ;
if ( ! V_87 )
V_87 = V_3 -> V_23 [ V_67 ] . V_87 ;
F_170 ( V_87 , V_20 -> V_10 ,
V_14 , 0 ) ;
F_69 ( V_87 , V_3 -> V_49 ) ;
}
}
if ( V_101 . V_209 )
F_110 ( V_20 , V_101 . V_209 ) ;
F_62 ( V_20 , & V_101 ) ;
if ( V_101 . V_365 ) {
F_25 ( & V_3 -> V_51 ) ;
if ( F_19 ( & V_3 -> V_51 ) <
V_52 )
F_22 ( V_3 -> V_49 -> V_50 ) ;
}
F_11 ( V_101 . V_31 ) ;
F_109 ( V_360 , & V_20 -> V_36 ) ;
}
static void F_171 ( struct V_2 * V_3 )
{
if ( F_19 ( & V_3 -> V_51 ) < V_52 ) {
while ( ! F_18 ( & V_3 -> V_43 ) ) {
struct V_61 * V_369 = V_3 -> V_43 . V_64 ;
struct V_19 * V_20 ;
V_20 = F_36 ( V_369 , struct V_19 , V_38 ) ;
F_37 ( V_369 ) ;
F_21 ( V_41 , & V_20 -> V_36 ) ;
if ( ! F_146 ( V_42 , & V_20 -> V_36 ) )
F_38 ( & V_3 -> V_51 ) ;
F_20 ( & V_20 -> V_38 , & V_3 -> V_370 ) ;
}
}
}
static void F_172 ( struct V_2 * V_3 )
{
struct V_61 V_371 ;
F_129 ( & V_371 , & V_3 -> V_47 ) ;
F_37 ( & V_3 -> V_47 ) ;
while ( ! F_18 ( & V_371 ) ) {
struct V_19 * V_20 = F_36 ( V_371 . V_64 , struct V_19 , V_38 ) ;
F_37 ( & V_20 -> V_38 ) ;
F_38 ( & V_20 -> V_27 ) ;
F_15 ( V_3 , V_20 ) ;
}
}
int F_173 ( struct V_49 * V_49 , int V_372 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
if ( V_3 -> V_96 )
return 1 ;
if ( V_3 -> V_95 )
return 1 ;
if ( F_174 ( & V_3 -> V_54 ) )
return 1 ;
return 0 ;
}
static int F_175 ( void * V_373 , int V_372 )
{
struct V_49 * V_49 = V_373 ;
return F_176 ( V_49 , V_372 ) ||
F_173 ( V_49 , V_372 ) ;
}
static int F_177 ( struct V_374 * V_375 ,
struct V_376 * V_377 ,
struct V_152 * V_378 )
{
struct V_49 * V_49 = V_375 -> V_379 ;
T_1 V_10 = V_377 -> V_13 + F_178 ( V_377 -> V_136 ) ;
int F_122 ;
unsigned int V_285 = V_49 -> V_285 ;
unsigned int V_380 = V_377 -> V_12 >> 9 ;
if ( ( V_377 -> V_117 & 1 ) == V_109 )
return V_378 -> V_144 ;
if ( V_49 -> V_381 < V_49 -> V_285 )
V_285 = V_49 -> V_381 ;
F_122 = ( V_285 - ( ( V_10 & ( V_285 - 1 ) ) + V_380 ) ) << 9 ;
if ( F_122 < 0 ) F_122 = 0 ;
if ( F_122 <= V_378 -> V_144 && V_380 == 0 )
return V_378 -> V_144 ;
else
return F_122 ;
}
static int F_179 ( struct V_49 * V_49 , struct V_9 * V_9 )
{
T_1 V_10 = V_9 -> V_13 + F_178 ( V_9 -> V_136 ) ;
unsigned int V_285 = V_49 -> V_285 ;
unsigned int V_380 = V_9 -> V_12 >> 9 ;
if ( V_49 -> V_381 < V_49 -> V_285 )
V_285 = V_49 -> V_381 ;
return V_285 >=
( ( V_10 & ( V_285 - 1 ) ) + V_380 ) ;
}
static void F_180 ( struct V_9 * V_32 , struct V_2 * V_3 )
{
unsigned long V_58 ;
F_28 ( & V_3 -> V_59 , V_58 ) ;
V_32 -> V_15 = V_3 -> V_382 ;
V_3 -> V_382 = V_32 ;
F_29 ( & V_3 -> V_59 , V_58 ) ;
F_22 ( V_3 -> V_49 -> V_50 ) ;
}
static struct V_9 * F_181 ( struct V_2 * V_3 )
{
struct V_9 * V_32 ;
V_32 = V_3 -> V_56 ;
if ( V_32 ) {
V_3 -> V_56 = NULL ;
return V_32 ;
}
V_32 = V_3 -> V_382 ;
if( V_32 ) {
V_3 -> V_382 = V_32 -> V_15 ;
V_32 -> V_15 = NULL ;
V_32 -> V_16 = 1 ;
}
return V_32 ;
}
static void F_182 ( struct V_9 * V_32 , int error )
{
struct V_9 * V_383 = V_32 -> V_245 ;
struct V_49 * V_49 ;
struct V_2 * V_3 ;
int V_246 = F_14 ( V_141 , & V_32 -> V_140 ) ;
struct V_86 * V_87 ;
F_183 ( V_32 ) ;
V_87 = ( void * ) V_383 -> V_15 ;
V_383 -> V_15 = NULL ;
V_49 = V_87 -> V_49 ;
V_3 = V_49 -> V_269 ;
F_69 ( V_87 , V_3 -> V_49 ) ;
if ( ! error && V_246 ) {
F_12 ( V_383 , 0 ) ;
if ( F_16 ( & V_3 -> V_384 ) )
F_26 ( & V_3 -> V_55 ) ;
return;
}
F_31 ( L_51 ) ;
F_180 ( V_383 , V_3 ) ;
}
static int F_184 ( struct V_9 * V_32 )
{
struct V_374 * V_375 = F_185 ( V_32 -> V_136 ) ;
if ( ( V_32 -> V_12 >> 9 ) > F_186 ( V_375 ) )
return 0 ;
F_187 ( V_375 , V_32 ) ;
if ( V_32 -> V_16 > F_188 ( V_375 ) )
return 0 ;
if ( V_375 -> V_385 )
return 0 ;
return 1 ;
}
static int F_189 ( struct V_49 * V_49 , struct V_9 * V_386 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
int V_275 ;
struct V_9 * V_387 ;
struct V_86 * V_87 ;
T_1 V_388 ;
if ( ! F_179 ( V_49 , V_386 ) ) {
F_31 ( L_52 ) ;
return 0 ;
}
V_387 = F_190 ( V_386 , V_244 , V_49 ) ;
if ( ! V_387 )
return 0 ;
V_387 -> V_118 = F_182 ;
V_387 -> V_245 = V_386 ;
V_387 -> V_13 = F_149 ( V_3 , V_386 -> V_13 ,
0 ,
& V_275 , NULL ) ;
V_388 = V_387 -> V_13 + ( V_387 -> V_12 >> 9 ) ;
F_51 () ;
V_87 = F_52 ( V_3 -> V_23 [ V_275 ] . V_121 ) ;
if ( ! V_87 || F_14 ( V_88 , & V_87 -> V_58 ) ||
V_87 -> V_327 < V_388 ) {
V_87 = F_52 ( V_3 -> V_23 [ V_275 ] . V_87 ) ;
if ( V_87 &&
( F_14 ( V_88 , & V_87 -> V_58 ) ||
! ( F_14 ( V_89 , & V_87 -> V_58 ) ||
V_87 -> V_327 >= V_388 ) ) )
V_87 = NULL ;
}
if ( V_87 ) {
T_1 V_125 ;
int V_126 ;
F_38 ( & V_87 -> V_123 ) ;
F_53 () ;
V_386 -> V_15 = ( void * ) V_87 ;
V_387 -> V_136 = V_87 -> V_134 ;
V_387 -> V_140 &= ~ ( 1 << V_389 ) ;
if ( ! F_184 ( V_387 ) ||
F_65 ( V_87 , V_387 -> V_13 , V_387 -> V_12 >> 9 ,
& V_125 , & V_126 ) ) {
F_183 ( V_387 ) ;
F_69 ( V_87 , V_49 ) ;
return 0 ;
}
V_387 -> V_13 += V_87 -> V_139 ;
F_56 ( & V_3 -> V_59 ) ;
F_57 ( V_3 -> V_55 ,
V_3 -> V_95 == 0 ,
V_3 -> V_59 , ) ;
F_38 ( & V_3 -> V_384 ) ;
F_59 ( & V_3 -> V_59 ) ;
F_71 ( V_387 ) ;
return 1 ;
} else {
F_53 () ;
F_183 ( V_387 ) ;
return 0 ;
}
}
static struct V_19 * F_191 ( struct V_2 * V_3 )
{
struct V_19 * V_20 ;
F_31 ( L_53 ,
V_137 ,
F_18 ( & V_3 -> V_48 ) ? L_54 : L_55 ,
F_18 ( & V_3 -> V_370 ) ? L_54 : L_55 ,
F_19 ( & V_3 -> V_308 ) , V_3 -> V_390 ) ;
if ( ! F_18 ( & V_3 -> V_48 ) ) {
V_20 = F_36 ( V_3 -> V_48 . V_64 , F_192 ( * V_20 ) , V_38 ) ;
if ( F_18 ( & V_3 -> V_370 ) )
V_3 -> V_390 = 0 ;
else if ( ! F_14 ( V_135 , & V_20 -> V_36 ) ) {
if ( V_3 -> V_370 . V_64 == V_3 -> V_391 )
V_3 -> V_390 ++ ;
else {
V_3 -> V_391 = V_3 -> V_370 . V_64 ;
V_3 -> V_390 -= V_3 -> V_392 ;
if ( V_3 -> V_390 < 0 )
V_3 -> V_390 = 0 ;
}
}
} else if ( ! F_18 ( & V_3 -> V_370 ) &&
( ( V_3 -> V_392 &&
V_3 -> V_390 > V_3 -> V_392 ) ||
F_19 ( & V_3 -> V_308 ) == 0 ) ) {
V_20 = F_36 ( V_3 -> V_370 . V_64 ,
F_192 ( * V_20 ) , V_38 ) ;
V_3 -> V_390 -= V_3 -> V_392 ;
if ( V_3 -> V_390 < 0 )
V_3 -> V_390 = 0 ;
} else
return NULL ;
F_37 ( & V_20 -> V_38 ) ;
F_38 ( & V_20 -> V_27 ) ;
F_17 ( F_19 ( & V_20 -> V_27 ) != 1 ) ;
return V_20 ;
}
static void F_193 ( struct V_49 * V_49 , struct V_9 * V_32 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
int V_275 ;
T_1 V_280 ;
T_1 V_393 , V_394 ;
struct V_19 * V_20 ;
const int V_102 = F_194 ( V_32 ) ;
int V_395 ;
if ( F_83 ( V_32 -> V_117 & V_396 ) ) {
F_195 ( V_49 , V_32 ) ;
return;
}
F_196 ( V_49 , V_32 ) ;
if ( V_102 == V_111 &&
V_49 -> V_90 == V_91 &&
F_189 ( V_49 , V_32 ) )
return;
V_393 = V_32 -> V_13 & ~ ( ( T_1 ) V_14 - 1 ) ;
V_394 = V_32 -> V_13 + ( V_32 -> V_12 >> 9 ) ;
V_32 -> V_15 = NULL ;
V_32 -> V_16 = 1 ;
for (; V_393 < V_394 ; V_393 += V_14 ) {
F_197 ( V_397 ) ;
int V_72 ;
V_255:
V_72 = 0 ;
F_198 ( & V_3 -> V_223 , & V_397 , V_398 ) ;
if ( F_83 ( V_3 -> V_99 != V_91 ) ) {
F_56 ( & V_3 -> V_59 ) ;
if ( V_49 -> V_399
? V_393 < V_3 -> V_99
: V_393 >= V_3 -> V_99 ) {
V_72 = 1 ;
} else {
if ( V_49 -> V_399
? V_393 < V_3 -> V_400
: V_393 >= V_3 -> V_400 ) {
F_59 ( & V_3 -> V_59 ) ;
F_199 () ;
goto V_255;
}
}
F_59 ( & V_3 -> V_59 ) ;
}
V_280 = F_149 ( V_3 , V_393 ,
V_72 ,
& V_275 , NULL ) ;
F_31 ( L_56 ,
( unsigned long long ) V_280 ,
( unsigned long long ) V_393 ) ;
V_20 = F_55 ( V_3 , V_280 , V_72 ,
( V_32 -> V_117 & V_401 ) , 0 ) ;
if ( V_20 ) {
if ( F_83 ( V_72 ) ) {
int V_402 = 0 ;
F_56 ( & V_3 -> V_59 ) ;
if ( V_49 -> V_399
? V_393 >= V_3 -> V_99
: V_393 < V_3 -> V_99 )
V_402 = 1 ;
F_59 ( & V_3 -> V_59 ) ;
if ( V_402 ) {
F_27 ( V_20 ) ;
F_199 () ;
goto V_255;
}
}
if ( V_102 == V_109 &&
V_393 >= V_49 -> V_403 &&
V_393 < V_49 -> V_404 ) {
F_27 ( V_20 ) ;
F_200 ( V_405 ) ;
F_198 ( & V_3 -> V_223 ,
& V_397 , V_406 ) ;
if ( V_393 >= V_49 -> V_403 &&
V_393 < V_49 -> V_404 )
F_199 () ;
goto V_255;
}
if ( F_14 ( V_53 , & V_20 -> V_36 ) ||
! F_152 ( V_20 , V_32 , V_275 , V_102 ) ) {
F_22 ( V_49 -> V_50 ) ;
F_27 ( V_20 ) ;
F_199 () ;
goto V_255;
}
F_201 ( & V_3 -> V_223 , & V_397 ) ;
F_66 ( V_40 , & V_20 -> V_36 ) ;
F_21 ( V_41 , & V_20 -> V_36 ) ;
if ( ( V_32 -> V_117 & V_114 ) &&
! F_146 ( V_42 , & V_20 -> V_36 ) )
F_38 ( & V_3 -> V_51 ) ;
F_202 ( V_49 ) ;
F_27 ( V_20 ) ;
} else {
F_21 ( V_141 , & V_32 -> V_140 ) ;
F_201 ( & V_3 -> V_223 , & V_397 ) ;
break;
}
}
F_56 ( & V_3 -> V_59 ) ;
V_395 = F_5 ( V_32 ) ;
F_59 ( & V_3 -> V_59 ) ;
if ( V_395 == 0 ) {
if ( V_102 == V_109 )
F_155 ( V_49 ) ;
F_12 ( V_32 , 0 ) ;
}
}
static T_1 F_203 ( struct V_49 * V_49 , T_1 V_407 , int * V_408 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
struct V_19 * V_20 ;
T_1 V_409 , V_394 ;
int V_25 = V_3 -> V_74 ;
int V_286 = V_25 - V_3 -> V_92 ;
int V_410 = V_3 -> V_25 - V_3 -> V_92 ;
int V_67 ;
int V_275 ;
T_1 V_411 , V_412 , V_413 ;
T_1 V_414 ;
int V_415 ;
struct V_61 V_416 ;
if ( V_407 == 0 ) {
if ( V_49 -> V_399 &&
V_3 -> V_99 < F_204 ( V_49 , 0 , 0 ) ) {
V_407 = F_204 ( V_49 , 0 , 0 )
- V_3 -> V_99 ;
} else if ( ! V_49 -> V_399 &&
V_3 -> V_99 > 0 )
V_407 = V_3 -> V_99 ;
F_150 ( V_407 , V_410 ) ;
if ( V_407 ) {
V_49 -> V_417 = V_407 ;
F_205 ( & V_49 -> V_418 , NULL , L_57 ) ;
* V_408 = 1 ;
return V_407 ;
}
}
if ( V_49 -> V_381 > V_49 -> V_285 )
V_415 = V_49 -> V_381 ;
else
V_415 = V_49 -> V_285 ;
V_411 = V_3 -> V_99 ;
F_150 ( V_411 , V_410 ) ;
V_412 = V_3 -> V_99 ;
F_150 ( V_412 , V_286 ) ;
V_413 = V_3 -> V_400 ;
F_150 ( V_413 , V_286 ) ;
if ( V_49 -> V_399 ) {
V_411 -= F_206 ( T_1 , V_415 , V_411 ) ;
V_412 += V_415 ;
V_413 += V_415 ;
} else {
V_411 += V_415 ;
V_412 -= F_206 ( T_1 , V_415 , V_412 ) ;
V_413 -= F_206 ( T_1 , V_415 , V_413 ) ;
}
if ( V_49 -> V_399 ) {
F_17 ( V_3 -> V_99 == 0 ) ;
V_414 = V_411 ;
F_17 ( ( V_49 -> V_419 &
~ ( ( T_1 ) V_415 - 1 ) )
- V_415 - V_414
!= V_407 ) ;
} else {
F_17 ( V_411 != V_407 + V_415 ) ;
V_414 = V_407 ;
}
if ( V_3 -> V_420 < 0 ) {
V_413 += - V_3 -> V_420 ;
V_412 += - V_3 -> V_420 ;
} else
V_411 += V_3 -> V_420 ;
if ( ( V_49 -> V_399
? ( V_413 > V_411 && V_412 < V_411 )
: ( V_413 < V_411 && V_412 > V_411 ) ) ||
F_207 ( V_421 , V_3 -> V_422 + 10 * V_423 ) ) {
F_111 ( V_3 -> V_223 ,
F_19 ( & V_3 -> V_368 ) == 0 ) ;
V_49 -> V_90 = V_3 -> V_99 ;
V_49 -> V_417 = V_407 ;
V_3 -> V_422 = V_421 ;
F_66 ( V_272 , & V_49 -> V_58 ) ;
F_22 ( V_49 -> V_50 ) ;
F_111 ( V_49 -> V_424 , V_49 -> V_58 == 0 ||
F_208 () ) ;
F_56 ( & V_3 -> V_59 ) ;
V_3 -> V_400 = V_49 -> V_90 ;
F_59 ( & V_3 -> V_59 ) ;
F_26 ( & V_3 -> V_223 ) ;
F_205 ( & V_49 -> V_418 , NULL , L_57 ) ;
}
F_120 ( & V_416 ) ;
for ( V_67 = 0 ; V_67 < V_415 ; V_67 += V_14 ) {
int V_344 ;
int V_425 = 0 ;
V_20 = F_55 ( V_3 , V_414 + V_67 , 0 , 0 , 1 ) ;
F_66 ( V_53 , & V_20 -> V_36 ) ;
F_38 ( & V_3 -> V_368 ) ;
for ( V_344 = V_20 -> V_23 ; V_344 -- ; ) {
T_1 V_101 ;
if ( V_344 == V_20 -> V_30 )
continue;
if ( V_3 -> V_211 == 6 &&
V_344 == V_20 -> V_22 )
continue;
V_101 = F_148 ( V_20 , V_344 , 0 ) ;
if ( V_101 < F_204 ( V_49 , 0 , 0 ) ) {
V_425 = 1 ;
continue;
}
memset ( F_209 ( V_20 -> V_70 [ V_344 ] . V_65 ) , 0 , V_145 ) ;
F_66 ( V_346 , & V_20 -> V_70 [ V_344 ] . V_58 ) ;
F_66 ( V_171 , & V_20 -> V_70 [ V_344 ] . V_58 ) ;
}
if ( ! V_425 ) {
F_66 ( V_347 , & V_20 -> V_36 ) ;
F_66 ( V_40 , & V_20 -> V_36 ) ;
}
F_129 ( & V_20 -> V_38 , & V_416 ) ;
}
F_56 ( & V_3 -> V_59 ) ;
if ( V_49 -> V_399 )
V_3 -> V_99 -= V_415 * V_410 ;
else
V_3 -> V_99 += V_415 * V_410 ;
F_59 ( & V_3 -> V_59 ) ;
V_409 =
F_149 ( V_3 , V_414 * ( V_410 ) ,
1 , & V_275 , NULL ) ;
V_394 =
F_149 ( V_3 , ( ( V_414 + V_415 )
* V_410 - 1 ) ,
1 , & V_275 , NULL ) ;
if ( V_394 >= V_49 -> V_419 )
V_394 = V_49 -> V_419 - 1 ;
while ( V_409 <= V_394 ) {
V_20 = F_55 ( V_3 , V_409 , 1 , 0 , 1 ) ;
F_66 ( V_343 , & V_20 -> V_36 ) ;
F_66 ( V_40 , & V_20 -> V_36 ) ;
F_27 ( V_20 ) ;
V_409 += V_14 ;
}
while ( ! F_18 ( & V_416 ) ) {
V_20 = F_36 ( V_416 . V_64 , struct V_19 , V_38 ) ;
F_37 ( & V_20 -> V_38 ) ;
F_27 ( V_20 ) ;
}
V_407 += V_415 ;
if ( ( V_407 - V_49 -> V_417 ) * 2
>= V_49 -> V_426 - V_49 -> V_417 ) {
F_111 ( V_3 -> V_223 ,
F_19 ( & V_3 -> V_368 ) == 0 ) ;
V_49 -> V_90 = V_3 -> V_99 ;
V_49 -> V_417 = V_407 ;
V_3 -> V_422 = V_421 ;
F_66 ( V_272 , & V_49 -> V_58 ) ;
F_22 ( V_49 -> V_50 ) ;
F_111 ( V_49 -> V_424 ,
! F_14 ( V_272 , & V_49 -> V_58 )
|| F_208 () ) ;
F_56 ( & V_3 -> V_59 ) ;
V_3 -> V_400 = V_49 -> V_90 ;
F_59 ( & V_3 -> V_59 ) ;
F_26 ( & V_3 -> V_223 ) ;
F_205 ( & V_49 -> V_418 , NULL , L_57 ) ;
}
return V_415 ;
}
static inline T_1 F_210 ( struct V_49 * V_49 , T_1 V_407 , int * V_408 , int V_427 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
struct V_19 * V_20 ;
T_1 V_428 = V_49 -> V_419 ;
T_1 V_429 ;
int V_430 = 0 ;
int V_67 ;
if ( V_407 >= V_428 ) {
if ( F_14 ( V_431 , & V_49 -> V_263 ) ) {
F_211 ( V_3 ) ;
return 0 ;
}
if ( V_49 -> V_432 < V_428 )
F_212 ( V_49 -> V_314 , V_49 -> V_432 ,
& V_429 , 1 ) ;
else
V_3 -> V_433 = 0 ;
F_213 ( V_49 -> V_314 ) ;
return 0 ;
}
F_111 ( V_3 -> V_223 , V_3 -> V_95 != 2 ) ;
if ( F_14 ( V_431 , & V_49 -> V_263 ) )
return F_203 ( V_49 , V_407 , V_408 ) ;
if ( V_49 -> V_84 >= V_3 -> V_92 &&
F_14 ( V_434 , & V_49 -> V_263 ) ) {
T_1 V_326 = V_49 -> V_419 - V_407 ;
* V_408 = 1 ;
return V_326 ;
}
if ( ! F_214 ( V_49 -> V_314 , V_407 , & V_429 , 1 ) &&
! F_14 ( V_357 , & V_49 -> V_263 ) &&
! V_3 -> V_433 && V_429 >= V_14 ) {
V_429 /= V_14 ;
* V_408 = 1 ;
return V_429 * V_14 ;
}
F_215 ( V_49 -> V_314 , V_407 ) ;
V_20 = F_55 ( V_3 , V_407 , 0 , 1 , 0 ) ;
if ( V_20 == NULL ) {
V_20 = F_55 ( V_3 , V_407 , 0 , 0 , 0 ) ;
F_216 ( 1 ) ;
}
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ )
if ( V_3 -> V_23 [ V_67 ] . V_87 == NULL )
V_430 = 1 ;
F_214 ( V_49 -> V_314 , V_407 , & V_429 , V_430 ) ;
F_66 ( V_361 , & V_20 -> V_36 ) ;
F_169 ( V_20 ) ;
F_27 ( V_20 ) ;
return V_14 ;
}
static int F_217 ( struct V_2 * V_3 , struct V_9 * V_386 )
{
struct V_19 * V_20 ;
int V_275 ;
T_1 V_10 , V_393 , V_394 ;
int V_435 = 0 ;
int V_395 ;
int V_436 = 0 ;
V_393 = V_386 -> V_13 & ~ ( ( T_1 ) V_14 - 1 ) ;
V_10 = F_149 ( V_3 , V_393 ,
0 , & V_275 , NULL ) ;
V_394 = V_386 -> V_13 + ( V_386 -> V_12 >> 9 ) ;
for (; V_393 < V_394 ;
V_393 += V_14 ,
V_10 += V_14 ,
V_435 ++ ) {
if ( V_435 < F_4 ( V_386 ) )
continue;
V_20 = F_55 ( V_3 , V_10 , 0 , 1 , 0 ) ;
if ( ! V_20 ) {
F_7 ( V_386 , V_435 ) ;
V_3 -> V_56 = V_386 ;
return V_436 ;
}
if ( ! F_152 ( V_20 , V_386 , V_275 , 0 ) ) {
F_27 ( V_20 ) ;
F_7 ( V_386 , V_435 ) ;
V_3 -> V_56 = V_386 ;
return V_436 ;
}
F_169 ( V_20 ) ;
F_27 ( V_20 ) ;
V_436 ++ ;
}
F_56 ( & V_3 -> V_59 ) ;
V_395 = F_5 ( V_386 ) ;
F_59 ( & V_3 -> V_59 ) ;
if ( V_395 == 0 )
F_12 ( V_386 , 0 ) ;
if ( F_16 ( & V_3 -> V_384 ) )
F_26 ( & V_3 -> V_55 ) ;
return V_436 ;
}
static void F_218 ( struct V_49 * V_49 )
{
struct V_19 * V_20 ;
struct V_2 * V_3 = V_49 -> V_269 ;
int V_436 ;
struct V_437 V_438 ;
F_31 ( L_58 ) ;
F_67 ( V_49 ) ;
F_219 ( & V_438 ) ;
V_436 = 0 ;
F_56 ( & V_3 -> V_59 ) ;
while ( 1 ) {
struct V_9 * V_9 ;
if ( F_19 ( & V_49 -> V_439 ) == 0 &&
! F_18 ( & V_3 -> V_47 ) ) {
V_3 -> V_315 ++ ;
F_59 ( & V_3 -> V_59 ) ;
F_220 ( V_49 -> V_314 ) ;
F_56 ( & V_3 -> V_59 ) ;
V_3 -> V_46 = V_3 -> V_315 ;
F_172 ( V_3 ) ;
}
if ( F_19 ( & V_49 -> V_439 ) == 0 )
F_171 ( V_3 ) ;
while ( ( V_9 = F_181 ( V_3 ) ) ) {
int V_440 ;
F_59 ( & V_3 -> V_59 ) ;
V_440 = F_217 ( V_3 , V_9 ) ;
F_56 ( & V_3 -> V_59 ) ;
if ( ! V_440 )
break;
V_436 ++ ;
}
V_20 = F_191 ( V_3 ) ;
if ( ! V_20 )
break;
F_59 ( & V_3 -> V_59 ) ;
V_436 ++ ;
F_169 ( V_20 ) ;
F_27 ( V_20 ) ;
F_221 () ;
if ( V_49 -> V_58 & ~ ( 1 << V_441 ) )
F_67 ( V_49 ) ;
F_56 ( & V_3 -> V_59 ) ;
}
F_31 ( L_59 , V_436 ) ;
F_59 ( & V_3 -> V_59 ) ;
F_222 () ;
F_223 ( & V_438 ) ;
F_31 ( L_60 ) ;
}
static T_5
F_224 ( struct V_49 * V_49 , char * V_65 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
if ( V_3 )
return sprintf ( V_65 , L_61 , V_3 -> V_97 ) ;
else
return 0 ;
}
int
F_225 ( struct V_49 * V_49 , int V_442 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
int V_242 ;
if ( V_442 <= 16 || V_442 > 32768 )
return - V_443 ;
while ( V_442 < V_3 -> V_97 ) {
if ( F_139 ( V_3 ) )
V_3 -> V_97 -- ;
else
break;
}
V_242 = F_128 ( V_49 ) ;
if ( V_242 )
return V_242 ;
while ( V_442 > V_3 -> V_97 ) {
if ( F_114 ( V_3 ) )
V_3 -> V_97 ++ ;
else break;
}
return 0 ;
}
static T_5
F_226 ( struct V_49 * V_49 , const char * V_65 , T_4 V_160 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
unsigned long V_444 ;
int V_242 ;
if ( V_160 >= V_445 )
return - V_443 ;
if ( ! V_3 )
return - V_446 ;
if ( F_227 ( V_65 , 10 , & V_444 ) )
return - V_443 ;
V_242 = F_225 ( V_49 , V_444 ) ;
if ( V_242 )
return V_242 ;
return V_160 ;
}
static T_5
F_228 ( struct V_49 * V_49 , char * V_65 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
if ( V_3 )
return sprintf ( V_65 , L_61 , V_3 -> V_392 ) ;
else
return 0 ;
}
static T_5
F_229 ( struct V_49 * V_49 , const char * V_65 , T_4 V_160 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
unsigned long V_444 ;
if ( V_160 >= V_445 )
return - V_443 ;
if ( ! V_3 )
return - V_446 ;
if ( F_227 ( V_65 , 10 , & V_444 ) )
return - V_443 ;
if ( V_444 > V_3 -> V_97 )
return - V_443 ;
V_3 -> V_392 = V_444 ;
return V_160 ;
}
static T_5
F_230 ( struct V_49 * V_49 , char * V_65 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
if ( V_3 )
return sprintf ( V_65 , L_61 , F_19 ( & V_3 -> V_39 ) ) ;
else
return 0 ;
}
static T_1
F_204 ( struct V_49 * V_49 , T_1 V_11 , int V_25 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
if ( ! V_11 )
V_11 = V_49 -> V_419 ;
if ( ! V_25 )
V_25 = F_231 ( V_3 -> V_25 , V_3 -> V_74 ) ;
V_11 &= ~ ( ( T_1 ) V_49 -> V_285 - 1 ) ;
V_11 &= ~ ( ( T_1 ) V_49 -> V_381 - 1 ) ;
return V_11 * ( V_25 - V_3 -> V_92 ) ;
}
static void F_232 ( struct V_2 * V_3 )
{
struct V_177 * V_178 ;
unsigned long V_212 ;
if ( ! V_3 -> V_178 )
return;
F_135 () ;
F_233 (cpu) {
V_178 = F_105 ( V_3 -> V_178 , V_212 ) ;
F_234 ( V_178 -> V_208 ) ;
F_134 ( V_178 -> V_179 ) ;
}
#ifdef F_235
F_236 ( & V_3 -> V_447 ) ;
#endif
F_138 () ;
F_237 ( V_3 -> V_178 ) ;
}
static void F_238 ( struct V_2 * V_3 )
{
F_140 ( V_3 ) ;
F_232 ( V_3 ) ;
F_134 ( V_3 -> V_23 ) ;
F_134 ( V_3 -> V_8 ) ;
F_134 ( V_3 ) ;
}
static int F_239 ( struct V_448 * V_449 , unsigned long V_450 ,
void * V_451 )
{
struct V_2 * V_3 = F_240 ( V_449 , struct V_2 , V_447 ) ;
long V_212 = ( long ) V_451 ;
struct V_177 * V_178 = F_105 ( V_3 -> V_178 , V_212 ) ;
switch ( V_450 ) {
case V_452 :
case V_453 :
if ( V_3 -> V_211 == 6 && ! V_178 -> V_208 )
V_178 -> V_208 = F_42 ( V_71 ) ;
if ( ! V_178 -> V_179 )
V_178 -> V_179 = F_137 ( V_3 -> F_125 , V_71 ) ;
if ( ! V_178 -> V_179 ||
( V_3 -> V_211 == 6 && ! V_178 -> V_208 ) ) {
F_234 ( V_178 -> V_208 ) ;
F_134 ( V_178 -> V_179 ) ;
F_241 ( L_62 ,
V_137 , V_212 ) ;
return F_242 ( - V_243 ) ;
}
break;
case V_454 :
case V_455 :
F_234 ( V_178 -> V_208 ) ;
F_134 ( V_178 -> V_179 ) ;
V_178 -> V_208 = NULL ;
V_178 -> V_179 = NULL ;
break;
default:
break;
}
return V_456 ;
}
static int F_243 ( struct V_2 * V_3 )
{
unsigned long V_212 ;
struct V_65 * V_208 ;
struct V_177 T_6 * V_457 ;
void * V_179 ;
int V_242 ;
V_457 = F_244 ( struct V_177 ) ;
if ( ! V_457 )
return - V_243 ;
V_3 -> V_178 = V_457 ;
F_135 () ;
V_242 = 0 ;
F_136 (cpu) {
if ( V_3 -> V_211 == 6 ) {
V_208 = F_42 ( V_71 ) ;
if ( ! V_208 ) {
V_242 = - V_243 ;
break;
}
F_105 ( V_3 -> V_178 , V_212 ) -> V_208 = V_208 ;
}
V_179 = F_137 ( V_3 -> F_125 , V_71 ) ;
if ( ! V_179 ) {
V_242 = - V_243 ;
break;
}
F_105 ( V_3 -> V_178 , V_212 ) -> V_179 = V_179 ;
}
#ifdef F_235
V_3 -> V_447 . V_458 = F_239 ;
V_3 -> V_447 . V_459 = 0 ;
if ( V_242 == 0 )
V_242 = F_245 ( & V_3 -> V_447 ) ;
#endif
F_138 () ;
return V_242 ;
}
static struct V_2 * F_246 ( struct V_49 * V_49 )
{
struct V_2 * V_3 ;
int V_460 , V_461 , V_462 ;
struct V_86 * V_87 ;
struct V_240 * V_24 ;
char V_463 [ 6 ] ;
if ( V_49 -> V_464 != 5
&& V_49 -> V_464 != 4
&& V_49 -> V_464 != 6 ) {
F_45 ( V_81 L_63 ,
F_123 ( V_49 ) , V_49 -> V_464 ) ;
return F_247 ( - V_465 ) ;
}
if ( ( V_49 -> V_464 == 5
&& ! F_248 ( V_49 -> V_466 ) ) ||
( V_49 -> V_464 == 6
&& ! F_249 ( V_49 -> V_466 ) ) ) {
F_45 ( V_81 L_64 ,
F_123 ( V_49 ) , V_49 -> V_466 ) ;
return F_247 ( - V_465 ) ;
}
if ( V_49 -> V_464 == 6 && V_49 -> V_25 < 4 ) {
F_45 ( V_81 L_65 ,
F_123 ( V_49 ) , V_49 -> V_25 ) ;
return F_247 ( - V_443 ) ;
}
if ( ! V_49 -> V_381 ||
( V_49 -> V_381 << 9 ) % V_445 ||
! F_250 ( V_49 -> V_381 ) ) {
F_45 ( V_81 L_66 ,
F_123 ( V_49 ) , V_49 -> V_381 << 9 ) ;
return F_247 ( - V_443 ) ;
}
V_3 = F_133 ( sizeof( struct V_2 ) , V_71 ) ;
if ( V_3 == NULL )
goto abort;
F_251 ( & V_3 -> V_59 ) ;
F_117 ( & V_3 -> V_55 ) ;
F_117 ( & V_3 -> V_223 ) ;
F_120 ( & V_3 -> V_48 ) ;
F_120 ( & V_3 -> V_370 ) ;
F_120 ( & V_3 -> V_43 ) ;
F_120 ( & V_3 -> V_47 ) ;
F_120 ( & V_3 -> V_54 ) ;
F_119 ( & V_3 -> V_39 , 0 ) ;
F_119 ( & V_3 -> V_51 , 0 ) ;
F_119 ( & V_3 -> V_384 , 0 ) ;
V_3 -> V_392 = V_467 ;
V_3 -> V_324 = V_49 -> V_324 - 1 ;
V_3 -> V_25 = V_49 -> V_25 ;
if ( V_49 -> V_90 == V_91 )
V_3 -> V_74 = V_49 -> V_25 ;
else
V_3 -> V_74 = V_49 -> V_25 - V_49 -> V_468 ;
V_462 = F_122 ( V_3 -> V_25 , V_3 -> V_74 ) ;
V_3 -> F_125 = F_125 ( V_462 ) ;
V_3 -> V_23 = F_133 ( V_462 * sizeof( struct V_240 ) ,
V_71 ) ;
if ( ! V_3 -> V_23 )
goto abort;
V_3 -> V_49 = V_49 ;
if ( ( V_3 -> V_8 = F_133 ( V_445 , V_71 ) ) == NULL )
goto abort;
V_3 -> V_211 = V_49 -> V_464 ;
if ( F_243 ( V_3 ) != 0 )
goto abort;
F_31 ( L_67 , F_123 ( V_49 ) ) ;
F_252 (rdev, mddev) {
V_460 = V_87 -> V_460 ;
if ( V_460 >= V_462
|| V_460 < 0 )
continue;
V_24 = V_3 -> V_23 + V_460 ;
if ( F_14 ( V_469 , & V_87 -> V_58 ) ) {
if ( V_24 -> V_121 )
goto abort;
V_24 -> V_121 = V_87 ;
} else {
if ( V_24 -> V_87 )
goto abort;
V_24 -> V_87 = V_87 ;
}
if ( F_14 ( V_89 , & V_87 -> V_58 ) ) {
char V_247 [ V_248 ] ;
F_45 ( V_250 L_68
L_69 ,
F_123 ( V_49 ) , F_142 ( V_87 -> V_134 , V_247 ) , V_460 ) ;
} else if ( V_87 -> V_470 != V_460 )
V_3 -> V_433 = 1 ;
}
V_3 -> V_285 = V_49 -> V_381 ;
V_3 -> V_211 = V_49 -> V_464 ;
if ( V_3 -> V_211 == 6 )
V_3 -> V_92 = 2 ;
else
V_3 -> V_92 = 1 ;
V_3 -> V_281 = V_49 -> V_466 ;
V_3 -> V_97 = V_471 ;
V_3 -> V_99 = V_49 -> V_90 ;
if ( V_3 -> V_99 != V_91 ) {
V_3 -> V_284 = V_49 -> V_285 ;
V_3 -> V_282 = V_49 -> V_472 ;
}
V_461 = V_3 -> V_97 * ( sizeof( struct V_19 ) +
V_462 * ( ( sizeof( struct V_9 ) + V_445 ) ) ) / 1024 ;
if ( F_121 ( V_3 , V_3 -> V_97 ) ) {
F_45 ( V_81
L_70 ,
F_123 ( V_49 ) , V_461 ) ;
goto abort;
} else
F_45 ( V_250 L_71 ,
F_123 ( V_49 ) , V_461 ) ;
sprintf ( V_463 , L_72 , V_49 -> V_464 ) ;
V_3 -> V_50 = F_253 ( F_218 , V_49 , V_463 ) ;
if ( ! V_3 -> V_50 ) {
F_45 ( V_81
L_73 ,
F_123 ( V_49 ) ) ;
goto abort;
}
return V_3 ;
abort:
if ( V_3 ) {
F_238 ( V_3 ) ;
return F_247 ( - V_465 ) ;
} else
return F_247 ( - V_243 ) ;
}
static int F_254 ( int V_460 , int V_473 , int V_25 , int V_92 )
{
switch ( V_473 ) {
case V_291 :
if ( V_460 < V_92 )
return 1 ;
break;
case V_292 :
if ( V_460 >= V_25 - V_92 )
return 1 ;
break;
case V_300 :
if ( V_460 == 0 ||
V_460 == V_25 - 1 )
return 1 ;
break;
case V_296 :
case V_297 :
case V_298 :
case V_299 :
if ( V_460 == V_25 - 1 )
return 1 ;
}
return 0 ;
}
static int F_255 ( struct V_49 * V_49 )
{
struct V_2 * V_3 ;
int V_474 = 0 ;
int V_475 = 0 ;
struct V_86 * V_87 ;
T_1 V_476 = 0 ;
int V_67 ;
long long V_420 = 0 ;
int V_62 = 1 ;
if ( V_49 -> V_328 != V_91 )
F_45 ( V_477 L_74
L_75 ,
F_123 ( V_49 ) ) ;
F_252 (rdev, mddev) {
long long V_478 ;
if ( V_87 -> V_460 < 0 )
continue;
V_478 = ( V_87 -> V_138 - V_87 -> V_139 ) ;
if ( V_62 ) {
V_420 = V_478 ;
V_62 = 0 ;
} else if ( V_49 -> V_399 &&
V_478 < V_420 )
V_420 = V_478 ;
else if ( ! V_49 -> V_399 &&
V_478 > V_420 )
V_420 = V_478 ;
}
if ( V_49 -> V_90 != V_91 ) {
T_1 V_479 , V_480 ;
int V_481 ;
int V_92 = ( V_49 -> V_211 == 6 ? 2 : 1 ) ;
if ( V_49 -> V_464 != V_49 -> V_211 ) {
F_45 ( V_81 L_76
L_77 ,
F_123 ( V_49 ) ) ;
return - V_443 ;
}
V_481 = V_49 -> V_25 - V_49 -> V_468 ;
V_479 = V_49 -> V_90 ;
if ( F_150 ( V_479 , V_49 -> V_381 *
( V_49 -> V_25 - V_92 ) ) ) {
F_45 ( V_81 L_78
L_79 , F_123 ( V_49 ) ) ;
return - V_443 ;
}
V_476 = V_479 * V_49 -> V_381 ;
V_480 = V_49 -> V_90 ;
F_150 ( V_480 , V_49 -> V_285 *
( V_481 - V_92 ) ) ;
if ( V_49 -> V_468 == 0 ) {
if ( ( V_479 * V_49 -> V_381 !=
V_480 * V_49 -> V_285 ) ) {
F_45 ( V_81 L_80
L_81 , F_123 ( V_49 ) ) ;
return - V_443 ;
}
if ( abs ( V_420 ) >= V_49 -> V_285 &&
abs ( V_420 ) >= V_49 -> V_381 )
;
else if ( V_49 -> V_366 == 0 ) {
F_45 ( V_81 L_82
L_83
L_84 ,
F_123 ( V_49 ) ) ;
return - V_443 ;
}
} else if ( V_49 -> V_399
? ( V_479 * V_49 -> V_381 + V_420 <=
V_480 * V_49 -> V_285 )
: ( V_479 * V_49 -> V_381 >=
V_480 * V_49 -> V_285 + ( - V_420 ) ) ) {
F_45 ( V_81 L_85
L_86 ,
F_123 ( V_49 ) ) ;
return - V_443 ;
}
F_45 ( V_250 L_87 ,
F_123 ( V_49 ) ) ;
} else {
F_17 ( V_49 -> V_211 != V_49 -> V_464 ) ;
F_17 ( V_49 -> V_472 != V_49 -> V_466 ) ;
F_17 ( V_49 -> V_285 != V_49 -> V_381 ) ;
F_17 ( V_49 -> V_468 != 0 ) ;
}
if ( V_49 -> V_269 == NULL )
V_3 = F_246 ( V_49 ) ;
else
V_3 = V_49 -> V_269 ;
if ( F_256 ( V_3 ) )
return F_257 ( V_3 ) ;
V_3 -> V_420 = V_420 ;
V_49 -> V_50 = V_3 -> V_50 ;
V_3 -> V_50 = NULL ;
V_49 -> V_269 = V_3 ;
for ( V_67 = 0 ; V_67 < V_3 -> V_25 && V_3 -> V_74 ;
V_67 ++ ) {
V_87 = V_3 -> V_23 [ V_67 ] . V_87 ;
if ( ! V_87 && V_3 -> V_23 [ V_67 ] . V_121 ) {
V_87 = V_3 -> V_23 [ V_67 ] . V_121 ;
V_3 -> V_23 [ V_67 ] . V_121 = NULL ;
F_21 ( V_469 , & V_87 -> V_58 ) ;
V_3 -> V_23 [ V_67 ] . V_87 = V_87 ;
}
if ( ! V_87 )
continue;
if ( V_3 -> V_23 [ V_67 ] . V_121 &&
V_3 -> V_99 != V_91 ) {
F_45 ( V_81 L_88
L_89 ) ;
goto abort;
}
if ( F_14 ( V_89 , & V_87 -> V_58 ) ) {
V_474 ++ ;
continue;
}
if ( V_49 -> V_482 == 0 &&
V_49 -> V_483 > 90 )
V_87 -> V_327 = V_476 ;
if ( V_87 -> V_327 < V_476 ) {
if ( ! F_254 ( V_87 -> V_460 ,
V_3 -> V_281 ,
V_3 -> V_25 ,
V_3 -> V_92 ) )
continue;
}
if ( ! F_254 ( V_87 -> V_460 ,
V_3 -> V_282 ,
V_3 -> V_74 ,
V_3 -> V_92 ) )
continue;
V_475 ++ ;
}
V_49 -> V_84 = F_50 ( V_3 ) ;
if ( F_54 ( V_3 ) ) {
F_45 ( V_81 L_90
L_91 ,
F_123 ( V_49 ) , V_49 -> V_84 , V_3 -> V_25 ) ;
goto abort;
}
V_49 -> V_419 &= ~ ( V_49 -> V_285 - 1 ) ;
V_49 -> V_484 = V_49 -> V_419 ;
if ( V_49 -> V_84 > V_475 &&
V_49 -> V_328 != V_91 ) {
if ( V_49 -> V_485 )
F_45 ( V_257
L_92
L_93 ,
F_123 ( V_49 ) ) ;
else {
F_45 ( V_81
L_94 ,
F_123 ( V_49 ) ) ;
goto abort;
}
}
if ( V_49 -> V_84 == 0 )
F_45 ( V_250 L_95
L_96 , F_123 ( V_49 ) , V_3 -> V_211 ,
V_49 -> V_25 - V_49 -> V_84 , V_49 -> V_25 ,
V_49 -> V_466 ) ;
else
F_45 ( V_273 L_97
L_98 ,
F_123 ( V_49 ) , V_3 -> V_211 ,
V_49 -> V_25 - V_49 -> V_84 ,
V_49 -> V_25 , V_49 -> V_466 ) ;
F_258 ( V_3 ) ;
if ( V_3 -> V_99 != V_91 ) {
V_3 -> V_400 = V_3 -> V_99 ;
F_119 ( & V_3 -> V_368 , 0 ) ;
F_21 ( V_434 , & V_49 -> V_263 ) ;
F_21 ( V_340 , & V_49 -> V_263 ) ;
F_66 ( V_431 , & V_49 -> V_263 ) ;
F_66 ( V_486 , & V_49 -> V_263 ) ;
V_49 -> V_487 = F_253 ( V_488 , V_49 ,
L_99 ) ;
}
if ( V_49 -> V_489 == & V_490 )
V_49 -> V_489 = NULL ;
else if ( V_49 -> V_418 . V_491 &&
F_259 ( & V_49 -> V_418 , & V_490 ) )
F_45 ( V_257
L_100 ,
F_123 ( V_49 ) ) ;
F_260 ( V_49 , F_204 ( V_49 , 0 , 0 ) ) ;
if ( V_49 -> V_492 ) {
int V_493 ;
int V_286 = V_3 -> V_74 - V_3 -> V_92 ;
int V_276 = V_286 *
( ( V_49 -> V_285 << 9 ) / V_445 ) ;
if ( V_49 -> V_492 -> V_494 . V_495 < 2 * V_276 )
V_49 -> V_492 -> V_494 . V_495 = 2 * V_276 ;
F_261 ( V_49 -> V_492 , F_177 ) ;
V_49 -> V_492 -> V_494 . V_496 = V_49 ;
V_49 -> V_492 -> V_494 . V_497 = F_175 ;
V_493 = V_49 -> V_285 << 9 ;
F_262 ( V_49 -> V_492 , V_493 ) ;
F_263 ( V_49 -> V_492 , V_493 *
( V_3 -> V_25 - V_3 -> V_92 ) ) ;
F_252 (rdev, mddev) {
F_264 ( V_49 -> V_233 , V_87 -> V_134 ,
V_87 -> V_139 << 9 ) ;
F_264 ( V_49 -> V_233 , V_87 -> V_134 ,
V_87 -> V_138 << 9 ) ;
}
}
return 0 ;
abort:
F_265 ( & V_49 -> V_50 ) ;
F_258 ( V_3 ) ;
F_238 ( V_3 ) ;
V_49 -> V_269 = NULL ;
F_45 ( V_273 L_101 , F_123 ( V_49 ) ) ;
return - V_465 ;
}
static int F_266 ( struct V_49 * V_49 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
F_265 ( & V_49 -> V_50 ) ;
if ( V_49 -> V_492 )
V_49 -> V_492 -> V_494 . V_497 = NULL ;
F_238 ( V_3 ) ;
V_49 -> V_269 = NULL ;
V_49 -> V_489 = & V_490 ;
return 0 ;
}
static void F_267 ( struct V_498 * V_499 , struct V_49 * V_49 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
int V_67 ;
F_268 ( V_499 , L_102 , V_49 -> V_211 ,
V_49 -> V_285 / 2 , V_49 -> V_472 ) ;
F_268 ( V_499 , L_103 , V_3 -> V_25 , V_3 -> V_25 - V_49 -> V_84 ) ;
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ )
F_268 ( V_499 , L_104 ,
V_3 -> V_23 [ V_67 ] . V_87 &&
F_14 ( V_89 , & V_3 -> V_23 [ V_67 ] . V_87 -> V_58 ) ? L_105 : L_106 ) ;
F_268 ( V_499 , L_107 ) ;
}
static void F_258 ( struct V_2 * V_3 )
{
int V_67 ;
struct V_240 * V_500 ;
F_45 ( V_501 L_108 ) ;
if ( ! V_3 ) {
F_45 ( L_109 ) ;
return;
}
F_45 ( V_501 L_110 , V_3 -> V_211 ,
V_3 -> V_25 ,
V_3 -> V_25 - V_3 -> V_49 -> V_84 ) ;
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ ) {
char V_247 [ V_248 ] ;
V_500 = V_3 -> V_23 + V_67 ;
if ( V_500 -> V_87 )
F_45 ( V_501 L_111 ,
V_67 , ! F_14 ( V_88 , & V_500 -> V_87 -> V_58 ) ,
F_142 ( V_500 -> V_87 -> V_134 , V_247 ) ) ;
}
}
static int F_269 ( struct V_49 * V_49 )
{
int V_67 ;
struct V_2 * V_3 = V_49 -> V_269 ;
struct V_240 * V_500 ;
int V_27 = 0 ;
unsigned long V_58 ;
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ ) {
V_500 = V_3 -> V_23 + V_67 ;
if ( V_500 -> V_121
&& V_500 -> V_121 -> V_327 == V_91
&& ! F_14 ( V_88 , & V_500 -> V_121 -> V_58 )
&& ! F_146 ( V_89 , & V_500 -> V_121 -> V_58 ) ) {
if ( ! V_500 -> V_87
|| ! F_23 ( V_89 , & V_500 -> V_87 -> V_58 ) )
V_27 ++ ;
if ( V_500 -> V_87 ) {
F_66 ( V_88 , & V_500 -> V_87 -> V_58 ) ;
F_270 (
V_500 -> V_87 -> V_502 ) ;
}
F_270 ( V_500 -> V_121 -> V_502 ) ;
} else if ( V_500 -> V_87
&& V_500 -> V_87 -> V_327 == V_91
&& ! F_14 ( V_88 , & V_500 -> V_87 -> V_58 )
&& ! F_146 ( V_89 , & V_500 -> V_87 -> V_58 ) ) {
V_27 ++ ;
F_270 ( V_500 -> V_87 -> V_502 ) ;
}
}
F_28 ( & V_3 -> V_59 , V_58 ) ;
V_49 -> V_84 = F_50 ( V_3 ) ;
F_29 ( & V_3 -> V_59 , V_58 ) ;
F_258 ( V_3 ) ;
return V_27 ;
}
static int F_271 ( struct V_49 * V_49 , struct V_86 * V_87 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
int V_242 = 0 ;
int V_503 = V_87 -> V_460 ;
struct V_86 * * V_504 ;
struct V_240 * V_66 = V_3 -> V_23 + V_503 ;
F_258 ( V_3 ) ;
if ( V_87 == V_66 -> V_87 )
V_504 = & V_66 -> V_87 ;
else if ( V_87 == V_66 -> V_121 )
V_504 = & V_66 -> V_121 ;
else
return 0 ;
if ( V_503 >= V_3 -> V_25 &&
V_3 -> V_99 == V_91 )
F_21 ( V_89 , & V_87 -> V_58 ) ;
if ( F_14 ( V_89 , & V_87 -> V_58 ) ||
F_19 ( & V_87 -> V_123 ) ) {
V_242 = - V_505 ;
goto abort;
}
if ( ! F_14 ( V_88 , & V_87 -> V_58 ) &&
V_49 -> V_324 != V_3 -> V_324 &&
! F_54 ( V_3 ) &&
( ! V_66 -> V_121 || V_66 -> V_121 == V_87 ) &&
V_503 < V_3 -> V_25 ) {
V_242 = - V_505 ;
goto abort;
}
* V_504 = NULL ;
F_272 () ;
if ( F_19 ( & V_87 -> V_123 ) ) {
V_242 = - V_505 ;
* V_504 = V_87 ;
} else if ( V_66 -> V_121 ) {
V_66 -> V_87 = V_66 -> V_121 ;
F_21 ( V_469 , & V_66 -> V_121 -> V_58 ) ;
F_64 () ;
V_66 -> V_121 = NULL ;
F_21 ( V_261 , & V_87 -> V_58 ) ;
} else
F_21 ( V_261 , & V_87 -> V_58 ) ;
abort:
F_258 ( V_3 ) ;
return V_242 ;
}
static int F_273 ( struct V_49 * V_49 , struct V_86 * V_87 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
int V_242 = - V_506 ;
int V_24 ;
struct V_240 * V_66 ;
int V_62 = 0 ;
int V_507 = V_3 -> V_25 - 1 ;
if ( V_49 -> V_324 == V_3 -> V_324 )
return - V_505 ;
if ( V_87 -> V_470 < 0 && F_54 ( V_3 ) )
return - V_443 ;
if ( V_87 -> V_460 >= 0 )
V_62 = V_507 = V_87 -> V_460 ;
if ( V_87 -> V_470 >= 0 &&
V_87 -> V_470 >= V_62 &&
V_3 -> V_23 [ V_87 -> V_470 ] . V_87 == NULL )
V_62 = V_87 -> V_470 ;
for ( V_24 = V_62 ; V_24 <= V_507 ; V_24 ++ ) {
V_66 = V_3 -> V_23 + V_24 ;
if ( V_66 -> V_87 == NULL ) {
F_21 ( V_89 , & V_87 -> V_58 ) ;
V_87 -> V_460 = V_24 ;
V_242 = 0 ;
if ( V_87 -> V_470 != V_24 )
V_3 -> V_433 = 1 ;
F_274 ( V_66 -> V_87 , V_87 ) ;
goto V_63;
}
}
for ( V_24 = V_62 ; V_24 <= V_507 ; V_24 ++ ) {
V_66 = V_3 -> V_23 + V_24 ;
if ( F_14 ( V_261 , & V_66 -> V_87 -> V_58 ) &&
V_66 -> V_121 == NULL ) {
F_21 ( V_89 , & V_87 -> V_58 ) ;
F_66 ( V_469 , & V_87 -> V_58 ) ;
V_87 -> V_460 = V_24 ;
V_242 = 0 ;
V_3 -> V_433 = 1 ;
F_274 ( V_66 -> V_121 , V_87 ) ;
break;
}
}
V_63:
F_258 ( V_3 ) ;
return V_242 ;
}
static int F_275 ( struct V_49 * V_49 , T_1 V_11 )
{
T_1 V_236 ;
V_11 &= ~ ( ( T_1 ) V_49 -> V_285 - 1 ) ;
V_236 = F_204 ( V_49 , V_11 , V_49 -> V_25 ) ;
if ( V_49 -> V_508 &&
V_49 -> V_509 > V_236 )
return - V_443 ;
if ( V_49 -> V_314 ) {
int V_510 = F_276 ( V_49 -> V_314 , V_11 , 0 , 0 ) ;
if ( V_510 )
return V_510 ;
}
F_260 ( V_49 , V_236 ) ;
F_277 ( V_49 -> V_233 , V_49 -> V_509 ) ;
F_278 ( V_49 -> V_233 ) ;
if ( V_11 > V_49 -> V_419 &&
V_49 -> V_328 > V_49 -> V_419 ) {
V_49 -> V_328 = V_49 -> V_419 ;
F_66 ( V_262 , & V_49 -> V_263 ) ;
}
V_49 -> V_419 = V_11 ;
V_49 -> V_484 = V_11 ;
return 0 ;
}
static int F_279 ( struct V_49 * V_49 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
if ( ( ( V_49 -> V_285 << 9 ) / V_145 ) * 4
> V_3 -> V_97 ||
( ( V_49 -> V_381 << 9 ) / V_145 ) * 4
> V_3 -> V_97 ) {
F_45 ( V_257 L_112 ,
F_123 ( V_49 ) ,
( ( F_122 ( V_49 -> V_285 , V_49 -> V_381 ) << 9 )
/ V_145 ) * 4 ) ;
return 0 ;
}
return 1 ;
}
static int F_280 ( struct V_49 * V_49 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
if ( V_49 -> V_468 == 0 &&
V_49 -> V_466 == V_49 -> V_472 &&
V_49 -> V_381 == V_49 -> V_285 )
return 0 ;
if ( F_54 ( V_3 ) )
return - V_443 ;
if ( V_49 -> V_468 < 0 ) {
int F_231 = 2 ;
if ( V_49 -> V_211 == 6 )
F_231 = 4 ;
if ( V_49 -> V_25 + V_49 -> V_468 < F_231 )
return - V_443 ;
}
if ( ! F_279 ( V_49 ) )
return - V_511 ;
return F_126 ( V_3 , V_3 -> V_25 + V_49 -> V_468 ) ;
}
static int F_281 ( struct V_49 * V_49 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
struct V_86 * V_87 ;
int V_512 = 0 ;
unsigned long V_58 ;
if ( F_14 ( V_486 , & V_49 -> V_263 ) )
return - V_505 ;
if ( ! F_279 ( V_49 ) )
return - V_511 ;
if ( F_54 ( V_3 ) )
return - V_443 ;
F_252 (rdev, mddev) {
if ( ! F_14 ( V_89 , & V_87 -> V_58 )
&& ! F_14 ( V_88 , & V_87 -> V_58 ) )
V_512 ++ ;
}
if ( V_512 - V_49 -> V_84 < V_49 -> V_468 - V_3 -> V_92 )
return - V_443 ;
if ( F_204 ( V_49 , 0 , V_3 -> V_25 + V_49 -> V_468 )
< V_49 -> V_509 ) {
F_45 ( V_81 L_113
L_114 , F_123 ( V_49 ) ) ;
return - V_443 ;
}
F_119 ( & V_3 -> V_368 , 0 ) ;
F_56 ( & V_3 -> V_59 ) ;
V_3 -> V_74 = V_3 -> V_25 ;
V_3 -> V_25 += V_49 -> V_468 ;
V_3 -> V_284 = V_3 -> V_285 ;
V_3 -> V_285 = V_49 -> V_381 ;
V_3 -> V_282 = V_3 -> V_281 ;
V_3 -> V_281 = V_49 -> V_466 ;
V_3 -> V_73 ++ ;
F_64 () ;
if ( V_49 -> V_399 )
V_3 -> V_99 = F_204 ( V_49 , 0 , 0 ) ;
else
V_3 -> V_99 = 0 ;
V_3 -> V_400 = V_3 -> V_99 ;
F_59 ( & V_3 -> V_59 ) ;
if ( V_49 -> V_468 >= 0 ) {
F_252 (rdev, mddev)
if ( V_87 -> V_460 < 0 &&
! F_14 ( V_88 , & V_87 -> V_58 ) ) {
if ( F_273 ( V_49 , V_87 ) == 0 ) {
if ( V_87 -> V_460
>= V_3 -> V_74 )
F_66 ( V_89 , & V_87 -> V_58 ) ;
else
V_87 -> V_327 = 0 ;
if ( F_282 ( V_49 , V_87 ) )
;
}
} else if ( V_87 -> V_460 >= V_3 -> V_74
&& ! F_14 ( V_88 , & V_87 -> V_58 ) ) {
F_66 ( V_89 , & V_87 -> V_58 ) ;
}
F_28 ( & V_3 -> V_59 , V_58 ) ;
V_49 -> V_84 = F_50 ( V_3 ) ;
F_29 ( & V_3 -> V_59 , V_58 ) ;
}
V_49 -> V_25 = V_3 -> V_25 ;
V_49 -> V_90 = V_3 -> V_99 ;
F_66 ( V_272 , & V_49 -> V_58 ) ;
F_21 ( V_434 , & V_49 -> V_263 ) ;
F_21 ( V_340 , & V_49 -> V_263 ) ;
F_66 ( V_431 , & V_49 -> V_263 ) ;
F_66 ( V_486 , & V_49 -> V_263 ) ;
V_49 -> V_487 = F_253 ( V_488 , V_49 ,
L_99 ) ;
if ( ! V_49 -> V_487 ) {
V_49 -> V_263 = 0 ;
F_56 ( & V_3 -> V_59 ) ;
V_49 -> V_25 = V_3 -> V_25 = V_3 -> V_74 ;
F_252 (rdev, mddev)
V_87 -> V_138 = V_87 -> V_139 ;
F_283 () ;
V_3 -> V_99 = V_91 ;
V_49 -> V_90 = V_91 ;
F_59 ( & V_3 -> V_59 ) ;
return - V_513 ;
}
V_3 -> V_422 = V_421 ;
F_22 ( V_49 -> V_487 ) ;
F_284 ( V_49 ) ;
return 0 ;
}
static void F_211 ( struct V_2 * V_3 )
{
if ( ! F_14 ( V_270 , & V_3 -> V_49 -> V_263 ) ) {
struct V_86 * V_87 ;
F_56 ( & V_3 -> V_59 ) ;
V_3 -> V_74 = V_3 -> V_25 ;
F_252 (rdev, conf->mddev)
V_87 -> V_139 = V_87 -> V_138 ;
F_283 () ;
V_3 -> V_99 = V_91 ;
F_59 ( & V_3 -> V_59 ) ;
F_26 ( & V_3 -> V_223 ) ;
if ( V_3 -> V_49 -> V_492 ) {
int V_286 = V_3 -> V_25 - V_3 -> V_92 ;
int V_276 = V_286 * ( ( V_3 -> V_285 << 9 )
/ V_445 ) ;
if ( V_3 -> V_49 -> V_492 -> V_494 . V_495 < 2 * V_276 )
V_3 -> V_49 -> V_492 -> V_494 . V_495 = 2 * V_276 ;
}
}
}
static void F_285 ( struct V_49 * V_49 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
if ( ! F_14 ( V_270 , & V_49 -> V_263 ) ) {
if ( V_49 -> V_468 > 0 ) {
F_260 ( V_49 , F_204 ( V_49 , 0 , 0 ) ) ;
F_277 ( V_49 -> V_233 , V_49 -> V_509 ) ;
F_278 ( V_49 -> V_233 ) ;
} else {
int V_514 ;
F_56 ( & V_3 -> V_59 ) ;
V_49 -> V_84 = F_50 ( V_3 ) ;
F_59 ( & V_3 -> V_59 ) ;
for ( V_514 = V_3 -> V_25 ;
V_514 < V_3 -> V_25 - V_49 -> V_468 ;
V_514 ++ ) {
struct V_86 * V_87 = V_3 -> V_23 [ V_514 ] . V_87 ;
if ( V_87 )
F_21 ( V_89 , & V_87 -> V_58 ) ;
V_87 = V_3 -> V_23 [ V_514 ] . V_121 ;
if ( V_87 )
F_21 ( V_89 , & V_87 -> V_58 ) ;
}
}
V_49 -> V_472 = V_3 -> V_281 ;
V_49 -> V_285 = V_3 -> V_285 ;
V_49 -> V_90 = V_91 ;
V_49 -> V_468 = 0 ;
V_49 -> V_399 = 0 ;
}
}
static void F_286 ( struct V_49 * V_49 , int V_36 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
switch( V_36 ) {
case 2 :
F_26 ( & V_3 -> V_223 ) ;
break;
case 1 :
F_56 ( & V_3 -> V_59 ) ;
V_3 -> V_95 = 2 ;
F_57 ( V_3 -> V_55 ,
F_19 ( & V_3 -> V_39 ) == 0 &&
F_19 ( & V_3 -> V_384 ) == 0 ,
V_3 -> V_59 , ) ;
V_3 -> V_95 = 1 ;
F_59 ( & V_3 -> V_59 ) ;
F_26 ( & V_3 -> V_223 ) ;
break;
case 0 :
F_56 ( & V_3 -> V_59 ) ;
V_3 -> V_95 = 0 ;
F_26 ( & V_3 -> V_55 ) ;
F_26 ( & V_3 -> V_223 ) ;
F_59 ( & V_3 -> V_59 ) ;
break;
}
}
static void * F_287 ( struct V_49 * V_49 , int V_211 )
{
struct V_515 * V_516 = V_49 -> V_269 ;
T_1 V_11 ;
if ( V_516 -> V_517 > 1 ) {
F_45 ( V_81 L_115 ,
F_123 ( V_49 ) ) ;
return F_247 ( - V_443 ) ;
}
V_11 = V_516 -> V_518 [ 0 ] . V_519 ;
F_150 ( V_11 , V_516 -> V_518 [ 0 ] . V_520 ) ;
V_49 -> V_419 = V_11 ;
V_49 -> V_464 = V_211 ;
V_49 -> V_466 = V_292 ;
V_49 -> V_381 = V_49 -> V_285 ;
V_49 -> V_25 += 1 ;
V_49 -> V_468 = 1 ;
V_49 -> V_328 = V_91 ;
return F_246 ( V_49 ) ;
}
static void * F_288 ( struct V_49 * V_49 )
{
int V_521 ;
if ( V_49 -> V_25 != 2 ||
V_49 -> V_84 > 1 )
return F_247 ( - V_443 ) ;
V_521 = 64 * 2 ;
while ( V_521 && ( V_49 -> V_509 & ( V_521 - 1 ) ) )
V_521 >>= 1 ;
if ( ( V_521 << 9 ) < V_145 )
return F_247 ( - V_443 ) ;
V_49 -> V_464 = 5 ;
V_49 -> V_466 = V_289 ;
V_49 -> V_381 = V_521 ;
return F_246 ( V_49 ) ;
}
static void * F_289 ( struct V_49 * V_49 )
{
int V_466 ;
switch ( V_49 -> V_472 ) {
case V_296 :
V_466 = V_287 ;
break;
case V_297 :
V_466 = V_288 ;
break;
case V_298 :
V_466 = V_289 ;
break;
case V_299 :
V_466 = V_290 ;
break;
case V_300 :
V_466 = V_291 ;
break;
case V_292 :
V_466 = V_292 ;
break;
default:
return F_247 ( - V_443 ) ;
}
V_49 -> V_464 = 5 ;
V_49 -> V_466 = V_466 ;
V_49 -> V_468 = - 1 ;
V_49 -> V_25 -= 1 ;
return F_246 ( V_49 ) ;
}
static int F_290 ( struct V_49 * V_49 )
{
struct V_2 * V_3 = V_49 -> V_269 ;
int V_522 = V_49 -> V_381 ;
if ( V_49 -> V_466 >= 0 && ! F_248 ( V_49 -> V_466 ) )
return - V_443 ;
if ( V_522 > 0 ) {
if ( ! F_250 ( V_522 ) )
return - V_443 ;
if ( V_522 < ( V_445 >> 9 ) )
return - V_443 ;
if ( V_49 -> V_509 & ( V_522 - 1 ) )
return - V_443 ;
}
if ( V_49 -> V_25 == 2 ) {
if ( V_49 -> V_466 >= 0 ) {
V_3 -> V_281 = V_49 -> V_466 ;
V_49 -> V_472 = V_49 -> V_466 ;
}
if ( V_522 > 0 ) {
V_3 -> V_285 = V_522 ;
V_49 -> V_285 = V_522 ;
}
F_66 ( V_272 , & V_49 -> V_58 ) ;
F_22 ( V_49 -> V_50 ) ;
}
return F_280 ( V_49 ) ;
}
static int F_291 ( struct V_49 * V_49 )
{
int V_522 = V_49 -> V_381 ;
if ( V_49 -> V_466 >= 0 && ! F_249 ( V_49 -> V_466 ) )
return - V_443 ;
if ( V_522 > 0 ) {
if ( ! F_250 ( V_522 ) )
return - V_443 ;
if ( V_522 < ( V_445 >> 9 ) )
return - V_443 ;
if ( V_49 -> V_509 & ( V_522 - 1 ) )
return - V_443 ;
}
return F_280 ( V_49 ) ;
}
static void * F_292 ( struct V_49 * V_49 )
{
if ( V_49 -> V_211 == 0 )
return F_287 ( V_49 , 5 ) ;
if ( V_49 -> V_211 == 1 )
return F_288 ( V_49 ) ;
if ( V_49 -> V_211 == 4 ) {
V_49 -> V_466 = V_292 ;
V_49 -> V_464 = 5 ;
return F_246 ( V_49 ) ;
}
if ( V_49 -> V_211 == 6 )
return F_289 ( V_49 ) ;
return F_247 ( - V_443 ) ;
}
static void * F_293 ( struct V_49 * V_49 )
{
if ( V_49 -> V_211 == 0 )
return F_287 ( V_49 , 4 ) ;
if ( V_49 -> V_211 == 5 &&
V_49 -> V_472 == V_292 ) {
V_49 -> V_466 = 0 ;
V_49 -> V_464 = 4 ;
return F_246 ( V_49 ) ;
}
return F_247 ( - V_443 ) ;
}
static void * F_294 ( struct V_49 * V_49 )
{
int V_466 ;
if ( V_49 -> V_523 != & V_524 )
return F_247 ( - V_443 ) ;
if ( V_49 -> V_84 > 1 )
return F_247 ( - V_443 ) ;
if ( V_49 -> V_25 > 253 )
return F_247 ( - V_443 ) ;
if ( V_49 -> V_25 < 3 )
return F_247 ( - V_443 ) ;
switch ( V_49 -> V_472 ) {
case V_287 :
V_466 = V_296 ;
break;
case V_288 :
V_466 = V_297 ;
break;
case V_289 :
V_466 = V_298 ;
break;
case V_290 :
V_466 = V_299 ;
break;
case V_291 :
V_466 = V_300 ;
break;
case V_292 :
V_466 = V_292 ;
break;
default:
return F_247 ( - V_443 ) ;
}
V_49 -> V_464 = 6 ;
V_49 -> V_466 = V_466 ;
V_49 -> V_468 = 1 ;
V_49 -> V_25 += 1 ;
return F_246 ( V_49 ) ;
}
static int T_7 F_295 ( void )
{
F_296 ( & V_525 ) ;
F_296 ( & V_524 ) ;
F_296 ( & V_526 ) ;
return 0 ;
}
static void F_297 ( void )
{
F_298 ( & V_525 ) ;
F_298 ( & V_524 ) ;
F_298 ( & V_526 ) ;
}
