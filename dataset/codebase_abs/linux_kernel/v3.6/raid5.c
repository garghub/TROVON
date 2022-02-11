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
T_2 * V_16 = ( T_2 * ) & V_9 -> V_17 ;
return ( F_4 ( V_16 ) >> 16 ) & 0xffff ;
}
static inline int F_5 ( struct V_9 * V_9 )
{
T_2 * V_16 = ( T_2 * ) & V_9 -> V_17 ;
return F_6 ( 1 , V_16 ) & 0xffff ;
}
static inline void F_7 ( struct V_9 * V_9 )
{
T_2 * V_16 = ( T_2 * ) & V_9 -> V_17 ;
F_8 ( V_16 ) ;
}
static inline void F_9 ( struct V_9 * V_9 ,
unsigned int V_18 )
{
T_2 * V_16 = ( T_2 * ) & V_9 -> V_17 ;
int V_19 , V_20 ;
do {
V_19 = F_4 ( V_16 ) ;
V_20 = ( V_19 & 0xffff ) | ( V_18 << 16 ) ;
} while ( F_10 ( V_16 , V_19 , V_20 ) != V_19 );
}
static inline void F_11 ( struct V_9 * V_9 , unsigned int V_18 )
{
T_2 * V_16 = ( T_2 * ) & V_9 -> V_17 ;
F_12 ( V_16 , V_18 ) ;
}
static inline int F_13 ( struct V_21 * V_22 )
{
if ( V_22 -> V_23 )
return 0 ;
if ( V_22 -> V_24 == V_22 -> V_25 - 1 )
return 0 ;
else
return V_22 -> V_24 + 1 ;
}
static inline int F_14 ( int V_26 , int V_27 )
{
V_26 ++ ;
return ( V_26 < V_27 ) ? V_26 : 0 ;
}
static int F_15 ( int V_28 , struct V_21 * V_22 ,
int * V_29 , int V_30 )
{
int V_31 = * V_29 ;
if ( V_22 -> V_23 )
( * V_29 ) ++ ;
if ( V_28 == V_22 -> V_32 )
return V_30 ;
if ( V_28 == V_22 -> V_24 )
return V_30 + 1 ;
if ( ! V_22 -> V_23 )
( * V_29 ) ++ ;
return V_31 ;
}
static void F_16 ( struct V_9 * V_33 )
{
struct V_9 * V_34 = V_33 ;
while ( V_34 ) {
V_33 = V_34 -> V_15 ;
V_34 -> V_15 = NULL ;
V_34 -> V_12 = 0 ;
F_17 ( V_34 , 0 ) ;
V_34 = V_33 ;
}
}
static int F_18 ( struct V_21 * V_22 )
{
return V_22 -> V_35 || V_22 -> V_36 ||
F_19 ( V_37 , & V_22 -> V_38 ) ||
F_19 ( V_39 , & V_22 -> V_38 ) ;
}
static void F_20 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
F_21 ( ! F_22 ( & V_22 -> V_40 ) ) ;
F_21 ( F_4 ( & V_3 -> V_41 ) == 0 ) ;
if ( F_19 ( V_42 , & V_22 -> V_38 ) ) {
if ( F_19 ( V_43 , & V_22 -> V_38 ) &&
! F_19 ( V_44 , & V_22 -> V_38 ) )
F_23 ( & V_22 -> V_40 , & V_3 -> V_45 ) ;
else if ( F_19 ( V_46 , & V_22 -> V_38 ) &&
V_22 -> V_47 - V_3 -> V_48 > 0 )
F_23 ( & V_22 -> V_40 , & V_3 -> V_49 ) ;
else {
F_24 ( V_43 , & V_22 -> V_38 ) ;
F_24 ( V_46 , & V_22 -> V_38 ) ;
F_23 ( & V_22 -> V_40 , & V_3 -> V_50 ) ;
}
F_25 ( V_3 -> V_51 -> V_52 ) ;
} else {
F_21 ( F_18 ( V_22 ) ) ;
if ( F_26 ( V_44 , & V_22 -> V_38 ) )
if ( F_27 ( & V_3 -> V_53 )
< V_54 )
F_25 ( V_3 -> V_51 -> V_52 ) ;
F_28 ( & V_3 -> V_41 ) ;
if ( ! F_19 ( V_55 , & V_22 -> V_38 ) ) {
F_23 ( & V_22 -> V_40 , & V_3 -> V_56 ) ;
F_29 ( & V_3 -> V_57 ) ;
if ( V_3 -> V_58 )
F_25 ( V_3 -> V_51 -> V_52 ) ;
}
}
}
static void F_30 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
if ( F_31 ( & V_22 -> V_29 ) )
F_20 ( V_3 , V_22 ) ;
}
static void F_32 ( struct V_21 * V_22 )
{
struct V_2 * V_3 = V_22 -> V_59 ;
unsigned long V_60 ;
F_33 ( V_60 ) ;
if ( F_34 ( & V_22 -> V_29 , & V_3 -> V_61 ) ) {
F_20 ( V_3 , V_22 ) ;
F_35 ( & V_3 -> V_61 ) ;
}
F_36 ( V_60 ) ;
}
static inline void F_37 ( struct V_21 * V_22 )
{
F_38 ( L_1 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_39 ( & V_22 -> V_5 ) ;
}
static inline void F_40 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
struct V_1 * V_62 = F_1 ( V_3 , V_22 -> V_10 ) ;
F_38 ( L_2 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_41 ( & V_22 -> V_5 , V_62 ) ;
}
static struct V_21 * F_42 ( struct V_2 * V_3 )
{
struct V_21 * V_22 = NULL ;
struct V_63 * V_64 ;
if ( F_22 ( & V_3 -> V_56 ) )
goto V_65;
V_64 = V_3 -> V_56 . V_66 ;
V_22 = F_43 ( V_64 , struct V_21 , V_40 ) ;
F_44 ( V_64 ) ;
F_37 ( V_22 ) ;
F_8 ( & V_3 -> V_41 ) ;
V_65:
return V_22 ;
}
static void F_45 ( struct V_21 * V_22 )
{
struct V_67 * V_68 ;
int V_69 ;
int V_70 = V_22 -> V_59 -> V_71 ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
V_68 = V_22 -> V_72 [ V_69 ] . V_67 ;
if ( ! V_68 )
continue;
V_22 -> V_72 [ V_69 ] . V_67 = NULL ;
F_46 ( V_68 ) ;
}
}
static int F_47 ( struct V_21 * V_22 )
{
int V_69 ;
int V_70 = V_22 -> V_59 -> V_71 ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
struct V_67 * V_67 ;
if ( ! ( V_67 = F_48 ( V_73 ) ) ) {
return 1 ;
}
V_22 -> V_72 [ V_69 ] . V_67 = V_67 ;
}
return 0 ;
}
static void F_49 ( struct V_21 * V_22 , T_1 V_10 , int V_74 )
{
struct V_2 * V_3 = V_22 -> V_59 ;
int V_69 ;
F_21 ( F_4 ( & V_22 -> V_29 ) != 0 ) ;
F_21 ( F_19 ( V_42 , & V_22 -> V_38 ) ) ;
F_21 ( F_18 ( V_22 ) ) ;
F_38 ( L_3 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_37 ( V_22 ) ;
V_22 -> V_75 = V_3 -> V_75 - V_74 ;
V_22 -> V_25 = V_74 ? V_3 -> V_76 : V_3 -> V_27 ;
V_22 -> V_10 = V_10 ;
F_50 ( V_10 , V_3 , V_74 , V_22 ) ;
V_22 -> V_38 = 0 ;
for ( V_69 = V_22 -> V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( V_72 -> V_78 || V_72 -> V_79 || V_72 -> V_80 || V_72 -> V_81 ||
F_19 ( V_82 , & V_72 -> V_60 ) ) {
F_51 ( V_83 L_4 ,
( unsigned long long ) V_22 -> V_10 , V_69 , V_72 -> V_78 ,
V_72 -> V_79 , V_72 -> V_80 , V_72 -> V_81 ,
F_19 ( V_82 , & V_72 -> V_60 ) ) ;
F_52 ( 1 ) ;
}
V_72 -> V_60 = 0 ;
F_53 ( V_22 , V_69 , V_74 ) ;
}
F_40 ( V_3 , V_22 ) ;
}
static struct V_21 * F_54 ( struct V_2 * V_3 , T_1 V_10 ,
short V_75 )
{
struct V_21 * V_22 ;
struct V_84 * V_85 ;
F_38 ( L_5 , ( unsigned long long ) V_10 ) ;
F_55 (sh, hn, stripe_hash(conf, sector), hash)
if ( V_22 -> V_10 == V_10 && V_22 -> V_75 == V_75 )
return V_22 ;
F_38 ( L_6 , ( unsigned long long ) V_10 ) ;
return NULL ;
}
static int F_56 ( struct V_2 * V_3 )
{
int V_86 , V_87 ;
int V_69 ;
F_57 () ;
V_86 = 0 ;
for ( V_69 = 0 ; V_69 < V_3 -> V_76 ; V_69 ++ ) {
struct V_88 * V_89 = F_58 ( V_3 -> V_25 [ V_69 ] . V_89 ) ;
if ( V_89 && F_19 ( V_90 , & V_89 -> V_60 ) )
V_89 = F_58 ( V_3 -> V_25 [ V_69 ] . V_91 ) ;
if ( ! V_89 || F_19 ( V_90 , & V_89 -> V_60 ) )
V_86 ++ ;
else if ( F_19 ( V_92 , & V_89 -> V_60 ) )
;
else
if ( V_3 -> V_27 >= V_3 -> V_76 )
V_86 ++ ;
}
F_59 () ;
if ( V_3 -> V_27 == V_3 -> V_76 )
return V_86 ;
F_57 () ;
V_87 = 0 ;
for ( V_69 = 0 ; V_69 < V_3 -> V_27 ; V_69 ++ ) {
struct V_88 * V_89 = F_58 ( V_3 -> V_25 [ V_69 ] . V_89 ) ;
if ( V_89 && F_19 ( V_90 , & V_89 -> V_60 ) )
V_89 = F_58 ( V_3 -> V_25 [ V_69 ] . V_91 ) ;
if ( ! V_89 || F_19 ( V_90 , & V_89 -> V_60 ) )
V_87 ++ ;
else if ( F_19 ( V_92 , & V_89 -> V_60 ) )
;
else
if ( V_3 -> V_27 <= V_3 -> V_76 )
V_87 ++ ;
}
F_59 () ;
if ( V_87 > V_86 )
return V_87 ;
return V_86 ;
}
static int F_60 ( struct V_2 * V_3 )
{
int V_86 ;
if ( V_3 -> V_51 -> V_93 == V_94 )
return V_3 -> V_51 -> V_86 > V_3 -> V_95 ;
V_86 = F_56 ( V_3 ) ;
if ( V_86 > V_3 -> V_95 )
return 1 ;
return 0 ;
}
static struct V_21 *
F_61 ( struct V_2 * V_3 , T_1 V_10 ,
int V_74 , int V_96 , int V_97 )
{
struct V_21 * V_22 ;
F_38 ( L_7 , ( unsigned long long ) V_10 ) ;
F_62 ( & V_3 -> V_61 ) ;
do {
F_63 ( V_3 -> V_57 ,
V_3 -> V_98 == 0 || V_97 ,
V_3 -> V_61 , ) ;
V_22 = F_54 ( V_3 , V_10 , V_3 -> V_75 - V_74 ) ;
if ( ! V_22 ) {
if ( ! V_3 -> V_99 )
V_22 = F_42 ( V_3 ) ;
if ( V_96 && V_22 == NULL )
break;
if ( ! V_22 ) {
V_3 -> V_99 = 1 ;
F_63 ( V_3 -> V_57 ,
! F_22 ( & V_3 -> V_56 ) &&
( F_4 ( & V_3 -> V_41 )
< ( V_3 -> V_100 * 3 / 4 )
|| ! V_3 -> V_99 ) ,
V_3 -> V_61 ,
) ;
V_3 -> V_99 = 0 ;
} else
F_49 ( V_22 , V_10 , V_74 ) ;
} else {
if ( F_4 ( & V_22 -> V_29 ) ) {
F_21 ( ! F_22 ( & V_22 -> V_40 )
&& ! F_19 ( V_55 , & V_22 -> V_38 )
&& ! F_19 ( V_101 , & V_22 -> V_38 ) ) ;
} else {
if ( ! F_19 ( V_42 , & V_22 -> V_38 ) )
F_8 ( & V_3 -> V_41 ) ;
if ( F_22 ( & V_22 -> V_40 ) &&
! F_19 ( V_55 , & V_22 -> V_38 ) )
F_64 () ;
F_44 ( & V_22 -> V_40 ) ;
}
}
} while ( V_22 == NULL );
if ( V_22 )
F_8 ( & V_22 -> V_29 ) ;
F_65 ( & V_3 -> V_61 ) ;
return V_22 ;
}
static int F_66 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
T_1 V_102 = V_3 -> V_103 ;
F_67 () ;
if ( V_102 == V_94 )
return 0 ;
if ( V_22 -> V_75 == V_3 -> V_75 - 1 )
return 0 ;
return 1 ;
}
static void F_68 ( struct V_21 * V_22 , struct V_104 * V_105 )
{
struct V_2 * V_3 = V_22 -> V_59 ;
int V_69 , V_25 = V_22 -> V_25 ;
F_69 () ;
for ( V_69 = V_25 ; V_69 -- ; ) {
int V_106 ;
int V_107 = 0 ;
struct V_9 * V_34 , * V_108 ;
struct V_88 * V_89 , * V_109 = NULL ;
if ( F_26 ( V_110 , & V_22 -> V_72 [ V_69 ] . V_60 ) ) {
if ( F_26 ( V_111 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
V_106 = V_112 ;
else
V_106 = V_113 ;
} else if ( F_26 ( V_114 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
V_106 = V_115 ;
else if ( F_26 ( V_116 ,
& V_22 -> V_72 [ V_69 ] . V_60 ) ) {
V_106 = V_113 ;
V_107 = 1 ;
} else
continue;
if ( F_26 ( V_117 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
V_106 |= V_118 ;
V_34 = & V_22 -> V_72 [ V_69 ] . V_119 ;
V_108 = & V_22 -> V_72 [ V_69 ] . V_120 ;
V_34 -> V_121 = V_106 ;
V_108 -> V_121 = V_106 ;
if ( V_106 & V_113 ) {
V_34 -> V_122 = V_123 ;
V_108 -> V_122 = V_123 ;
} else
V_34 -> V_122 = V_124 ;
F_57 () ;
V_109 = F_58 ( V_3 -> V_25 [ V_69 ] . V_91 ) ;
F_70 () ;
V_89 = F_58 ( V_3 -> V_25 [ V_69 ] . V_89 ) ;
if ( ! V_89 ) {
V_89 = V_109 ;
V_109 = NULL ;
}
if ( V_106 & V_113 ) {
if ( V_107 )
V_89 = NULL ;
if ( V_89 == V_109 )
V_109 = NULL ;
} else {
if ( F_19 ( V_125 , & V_22 -> V_72 [ V_69 ] . V_60 ) && V_109 )
V_89 = V_109 ;
V_109 = NULL ;
}
if ( V_89 && F_19 ( V_90 , & V_89 -> V_60 ) )
V_89 = NULL ;
if ( V_89 )
F_8 ( & V_89 -> V_126 ) ;
if ( V_109 && F_19 ( V_90 , & V_109 -> V_60 ) )
V_109 = NULL ;
if ( V_109 )
F_8 ( & V_109 -> V_126 ) ;
F_59 () ;
while ( ( V_106 & V_113 ) && V_89 &&
F_19 ( V_127 , & V_89 -> V_60 ) ) {
T_1 V_128 ;
int V_129 ;
int V_130 = F_71 ( V_89 , V_22 -> V_10 , V_14 ,
& V_128 , & V_129 ) ;
if ( ! V_130 )
break;
if ( V_130 < 0 ) {
F_72 ( V_131 , & V_89 -> V_60 ) ;
if ( ! V_3 -> V_51 -> V_132 &&
V_3 -> V_51 -> V_60 ) {
F_73 ( V_3 -> V_51 ) ;
}
F_8 ( & V_89 -> V_126 ) ;
F_74 ( V_89 , V_3 -> V_51 ) ;
} else {
F_75 ( V_89 , V_3 -> V_51 ) ;
V_89 = NULL ;
}
}
if ( V_89 ) {
if ( V_105 -> V_133 || V_105 -> V_134 || V_105 -> V_135
|| V_105 -> V_136 )
F_76 ( V_89 -> V_137 , V_14 ) ;
F_72 ( V_138 , & V_22 -> V_38 ) ;
V_34 -> V_139 = V_89 -> V_137 ;
F_38 ( L_8 ,
V_140 , ( unsigned long long ) V_22 -> V_10 ,
V_34 -> V_121 , V_69 ) ;
F_8 ( & V_22 -> V_29 ) ;
if ( F_66 ( V_3 , V_22 ) )
V_34 -> V_13 = ( V_22 -> V_10
+ V_89 -> V_141 ) ;
else
V_34 -> V_13 = ( V_22 -> V_10
+ V_89 -> V_142 ) ;
if ( F_19 ( V_143 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
V_34 -> V_121 |= V_144 ;
V_34 -> V_145 = 1 << V_146 ;
V_34 -> V_147 = 0 ;
V_34 -> V_148 [ 0 ] . V_149 = V_150 ;
V_34 -> V_148 [ 0 ] . V_151 = 0 ;
V_34 -> V_12 = V_150 ;
V_34 -> V_15 = NULL ;
if ( V_109 )
F_72 ( V_152 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_77 ( V_34 ) ;
}
if ( V_109 ) {
if ( V_105 -> V_133 || V_105 -> V_134 || V_105 -> V_135
|| V_105 -> V_136 )
F_76 ( V_109 -> V_137 , V_14 ) ;
F_72 ( V_138 , & V_22 -> V_38 ) ;
V_108 -> V_139 = V_109 -> V_137 ;
F_38 ( L_9
L_10 ,
V_140 , ( unsigned long long ) V_22 -> V_10 ,
V_108 -> V_121 , V_69 ) ;
F_8 ( & V_22 -> V_29 ) ;
if ( F_66 ( V_3 , V_22 ) )
V_108 -> V_13 = ( V_22 -> V_10
+ V_109 -> V_141 ) ;
else
V_108 -> V_13 = ( V_22 -> V_10
+ V_109 -> V_142 ) ;
V_108 -> V_145 = 1 << V_146 ;
V_108 -> V_147 = 0 ;
V_108 -> V_148 [ 0 ] . V_149 = V_150 ;
V_108 -> V_148 [ 0 ] . V_151 = 0 ;
V_108 -> V_12 = V_150 ;
V_108 -> V_15 = NULL ;
F_77 ( V_108 ) ;
}
if ( ! V_89 && ! V_109 ) {
if ( V_106 & V_113 )
F_72 ( V_153 , & V_22 -> V_38 ) ;
F_38 ( L_11 ,
V_34 -> V_121 , V_69 , ( unsigned long long ) V_22 -> V_10 ) ;
F_24 ( V_82 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
}
}
}
static struct V_154 *
F_78 ( int V_155 , struct V_9 * V_9 , struct V_67 * V_67 ,
T_1 V_10 , struct V_154 * V_156 )
{
struct V_157 * V_158 ;
struct V_67 * V_159 ;
int V_69 ;
int V_160 ;
struct V_161 V_162 ;
enum V_163 V_60 = 0 ;
if ( V_9 -> V_13 >= V_10 )
V_160 = ( signed ) ( V_9 -> V_13 - V_10 ) * 512 ;
else
V_160 = ( signed ) ( V_10 - V_9 -> V_13 ) * - 512 ;
if ( V_155 )
V_60 |= V_164 ;
F_79 ( & V_162 , V_60 , V_156 , NULL , NULL , NULL ) ;
F_80 (bvl, bio, i) {
int V_165 = V_158 -> V_149 ;
int V_166 ;
int V_167 = 0 ;
if ( V_160 < 0 ) {
V_167 = - V_160 ;
V_160 += V_167 ;
V_165 -= V_167 ;
}
if ( V_165 > 0 && V_160 + V_165 > V_150 )
V_166 = V_150 - V_160 ;
else
V_166 = V_165 ;
if ( V_166 > 0 ) {
V_167 += V_158 -> V_151 ;
V_159 = V_158 -> V_168 ;
if ( V_155 )
V_156 = F_81 ( V_67 , V_159 , V_160 ,
V_167 , V_166 , & V_162 ) ;
else
V_156 = F_81 ( V_159 , V_67 , V_167 ,
V_160 , V_166 , & V_162 ) ;
}
V_162 . V_169 = V_156 ;
if ( V_166 < V_165 )
break;
V_160 += V_165 ;
}
return V_156 ;
}
static void F_82 ( void * V_170 )
{
struct V_21 * V_22 = V_170 ;
struct V_9 * V_33 = NULL ;
int V_69 ;
F_38 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_69 = V_22 -> V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( F_26 ( V_171 , & V_72 -> V_60 ) ) {
struct V_9 * V_108 , * V_172 ;
F_21 ( ! V_72 -> V_79 ) ;
V_108 = V_72 -> V_79 ;
V_72 -> V_79 = NULL ;
while ( V_108 && V_108 -> V_13 <
V_72 -> V_10 + V_14 ) {
V_172 = F_2 ( V_108 , V_72 -> V_10 ) ;
if ( ! F_5 ( V_108 ) ) {
V_108 -> V_15 = V_33 ;
V_33 = V_108 ;
}
V_108 = V_172 ;
}
}
}
F_24 ( V_37 , & V_22 -> V_38 ) ;
F_16 ( V_33 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
F_32 ( V_22 ) ;
}
static void F_83 ( struct V_21 * V_22 )
{
struct V_154 * V_156 = NULL ;
struct V_161 V_162 ;
int V_69 ;
F_38 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_69 = V_22 -> V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( F_19 ( V_171 , & V_72 -> V_60 ) ) {
struct V_9 * V_108 ;
F_62 ( & V_22 -> V_173 ) ;
V_72 -> V_79 = V_108 = V_72 -> V_78 ;
V_72 -> V_78 = NULL ;
F_65 ( & V_22 -> V_173 ) ;
while ( V_108 && V_108 -> V_13 <
V_72 -> V_10 + V_14 ) {
V_156 = F_78 ( 0 , V_108 , V_72 -> V_67 ,
V_72 -> V_10 , V_156 ) ;
V_108 = F_2 ( V_108 , V_72 -> V_10 ) ;
}
}
}
F_8 ( & V_22 -> V_29 ) ;
F_79 ( & V_162 , V_174 , V_156 , F_82 , V_22 , NULL ) ;
F_84 ( & V_162 ) ;
}
static void F_85 ( struct V_21 * V_22 , int V_175 )
{
struct V_77 * V_176 ;
if ( V_175 < 0 )
return;
V_176 = & V_22 -> V_72 [ V_175 ] ;
F_72 ( V_177 , & V_176 -> V_60 ) ;
F_21 ( ! F_19 ( V_178 , & V_176 -> V_60 ) ) ;
F_24 ( V_178 , & V_176 -> V_60 ) ;
}
static void F_86 ( void * V_170 )
{
struct V_21 * V_22 = V_170 ;
F_38 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_85 ( V_22 , V_22 -> V_179 . V_175 ) ;
F_85 ( V_22 , V_22 -> V_179 . V_180 ) ;
F_24 ( V_39 , & V_22 -> V_38 ) ;
if ( V_22 -> V_35 == V_181 )
V_22 -> V_35 = V_182 ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
F_32 ( V_22 ) ;
}
static T_3 * F_87 ( struct V_21 * V_22 ,
struct V_183 * V_184 )
{
return V_184 -> V_185 + sizeof( struct V_67 * ) * ( V_22 -> V_25 + 2 ) ;
}
static struct V_154 *
F_88 ( struct V_21 * V_22 , struct V_183 * V_184 )
{
int V_25 = V_22 -> V_25 ;
struct V_67 * * V_186 = V_184 -> V_185 ;
int V_175 = V_22 -> V_179 . V_175 ;
struct V_77 * V_176 = & V_22 -> V_72 [ V_175 ] ;
struct V_67 * V_187 = V_176 -> V_67 ;
int V_29 = 0 ;
struct V_154 * V_156 ;
struct V_161 V_162 ;
int V_69 ;
F_38 ( L_13 ,
V_140 , ( unsigned long long ) V_22 -> V_10 , V_175 ) ;
F_21 ( ! F_19 ( V_178 , & V_176 -> V_60 ) ) ;
for ( V_69 = V_25 ; V_69 -- ; )
if ( V_69 != V_175 )
V_186 [ V_29 ++ ] = V_22 -> V_72 [ V_69 ] . V_67 ;
F_8 ( & V_22 -> V_29 ) ;
F_79 ( & V_162 , V_164 | V_188 , NULL ,
F_86 , V_22 , F_87 ( V_22 , V_184 ) ) ;
if ( F_89 ( V_29 == 1 ) )
V_156 = F_81 ( V_187 , V_186 [ 0 ] , 0 , 0 , V_150 , & V_162 ) ;
else
V_156 = F_90 ( V_187 , V_186 , 0 , V_29 , V_150 , & V_162 ) ;
return V_156 ;
}
static int F_91 ( struct V_67 * * V_189 , struct V_21 * V_22 )
{
int V_25 = V_22 -> V_25 ;
int V_30 = V_22 -> V_23 ? V_25 : ( V_25 - 2 ) ;
int V_190 = F_13 ( V_22 ) ;
int V_29 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_25 ; V_69 ++ )
V_189 [ V_69 ] = NULL ;
V_29 = 0 ;
V_69 = V_190 ;
do {
int V_31 = F_15 ( V_69 , V_22 , & V_29 , V_30 ) ;
V_189 [ V_31 ] = V_22 -> V_72 [ V_69 ] . V_67 ;
V_69 = F_14 ( V_69 , V_25 ) ;
} while ( V_69 != V_190 );
return V_30 ;
}
static struct V_154 *
F_92 ( struct V_21 * V_22 , struct V_183 * V_184 )
{
int V_25 = V_22 -> V_25 ;
struct V_67 * * V_191 = V_184 -> V_185 ;
int V_175 ;
int V_24 = V_22 -> V_24 ;
struct V_154 * V_156 ;
struct V_161 V_162 ;
struct V_77 * V_176 ;
struct V_67 * V_192 ;
int V_69 ;
int V_29 ;
if ( V_22 -> V_179 . V_175 < 0 )
V_175 = V_22 -> V_179 . V_180 ;
else if ( V_22 -> V_179 . V_180 < 0 )
V_175 = V_22 -> V_179 . V_175 ;
else
F_64 () ;
F_21 ( V_175 < 0 ) ;
F_38 ( L_13 ,
V_140 , ( unsigned long long ) V_22 -> V_10 , V_175 ) ;
V_176 = & V_22 -> V_72 [ V_175 ] ;
F_21 ( ! F_19 ( V_178 , & V_176 -> V_60 ) ) ;
V_192 = V_176 -> V_67 ;
F_8 ( & V_22 -> V_29 ) ;
if ( V_175 == V_24 ) {
V_29 = F_91 ( V_191 , V_22 ) ;
V_191 [ V_29 ] = NULL ;
F_21 ( V_191 [ V_29 + 1 ] != V_192 ) ;
F_79 ( & V_162 , V_164 , NULL ,
F_86 , V_22 ,
F_87 ( V_22 , V_184 ) ) ;
V_156 = F_93 ( V_191 , 0 , V_29 + 2 , V_150 , & V_162 ) ;
} else {
V_29 = 0 ;
for ( V_69 = V_25 ; V_69 -- ; ) {
if ( V_69 == V_175 || V_69 == V_24 )
continue;
V_191 [ V_29 ++ ] = V_22 -> V_72 [ V_69 ] . V_67 ;
}
F_79 ( & V_162 , V_164 | V_188 ,
NULL , F_86 , V_22 ,
F_87 ( V_22 , V_184 ) ) ;
V_156 = F_90 ( V_192 , V_191 , 0 , V_29 , V_150 , & V_162 ) ;
}
return V_156 ;
}
static struct V_154 *
F_94 ( struct V_21 * V_22 , struct V_183 * V_184 )
{
int V_69 , V_29 , V_25 = V_22 -> V_25 ;
int V_30 = V_22 -> V_23 ? V_25 : V_25 - 2 ;
int V_190 = F_13 ( V_22 ) ;
int V_193 = - 1 , V_194 = - 1 ;
int V_175 = V_22 -> V_179 . V_175 ;
int V_180 = V_22 -> V_179 . V_180 ;
struct V_77 * V_176 = & V_22 -> V_72 [ V_175 ] ;
struct V_77 * V_195 = & V_22 -> V_72 [ V_180 ] ;
struct V_154 * V_156 ;
struct V_67 * * V_191 = V_184 -> V_185 ;
struct V_161 V_162 ;
F_38 ( L_14 ,
V_140 , ( unsigned long long ) V_22 -> V_10 , V_175 , V_180 ) ;
F_21 ( V_175 < 0 || V_180 < 0 ) ;
F_21 ( ! F_19 ( V_178 , & V_176 -> V_60 ) ) ;
F_21 ( ! F_19 ( V_178 , & V_195 -> V_60 ) ) ;
for ( V_69 = 0 ; V_69 < V_25 ; V_69 ++ )
V_191 [ V_69 ] = NULL ;
V_29 = 0 ;
V_69 = V_190 ;
do {
int V_31 = F_15 ( V_69 , V_22 , & V_29 , V_30 ) ;
V_191 [ V_31 ] = V_22 -> V_72 [ V_69 ] . V_67 ;
if ( V_69 == V_175 )
V_193 = V_31 ;
if ( V_69 == V_180 )
V_194 = V_31 ;
V_69 = F_14 ( V_69 , V_25 ) ;
} while ( V_69 != V_190 );
F_21 ( V_193 == V_194 ) ;
if ( V_194 < V_193 )
F_95 ( V_193 , V_194 ) ;
F_38 ( L_15 ,
V_140 , ( unsigned long long ) V_22 -> V_10 , V_193 , V_194 ) ;
F_8 ( & V_22 -> V_29 ) ;
if ( V_194 == V_30 + 1 ) {
if ( V_193 == V_30 ) {
F_79 ( & V_162 , V_164 , NULL ,
F_86 , V_22 ,
F_87 ( V_22 , V_184 ) ) ;
return F_93 ( V_191 , 0 , V_30 + 2 ,
V_150 , & V_162 ) ;
} else {
struct V_67 * V_192 ;
int V_196 ;
int V_24 = V_22 -> V_24 ;
if ( V_175 == V_24 )
V_196 = V_180 ;
else
V_196 = V_175 ;
V_29 = 0 ;
for ( V_69 = V_25 ; V_69 -- ; ) {
if ( V_69 == V_196 || V_69 == V_24 )
continue;
V_191 [ V_29 ++ ] = V_22 -> V_72 [ V_69 ] . V_67 ;
}
V_192 = V_22 -> V_72 [ V_196 ] . V_67 ;
F_79 ( & V_162 ,
V_164 | V_188 ,
NULL , NULL , NULL ,
F_87 ( V_22 , V_184 ) ) ;
V_156 = F_90 ( V_192 , V_191 , 0 , V_29 , V_150 ,
& V_162 ) ;
V_29 = F_91 ( V_191 , V_22 ) ;
F_79 ( & V_162 , V_164 , V_156 ,
F_86 , V_22 ,
F_87 ( V_22 , V_184 ) ) ;
return F_93 ( V_191 , 0 , V_29 + 2 ,
V_150 , & V_162 ) ;
}
} else {
F_79 ( & V_162 , V_164 , NULL ,
F_86 , V_22 ,
F_87 ( V_22 , V_184 ) ) ;
if ( V_194 == V_30 ) {
return F_96 ( V_30 + 2 ,
V_150 , V_193 ,
V_191 , & V_162 ) ;
} else {
return F_97 ( V_30 + 2 ,
V_150 , V_193 , V_194 ,
V_191 , & V_162 ) ;
}
}
}
static void F_98 ( void * V_170 )
{
struct V_21 * V_22 = V_170 ;
F_38 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
}
static struct V_154 *
F_99 ( struct V_21 * V_22 , struct V_183 * V_184 ,
struct V_154 * V_156 )
{
int V_25 = V_22 -> V_25 ;
struct V_67 * * V_186 = V_184 -> V_185 ;
int V_29 = 0 , V_32 = V_22 -> V_32 , V_69 ;
struct V_161 V_162 ;
struct V_67 * V_187 = V_186 [ V_29 ++ ] = V_22 -> V_72 [ V_32 ] . V_67 ;
F_38 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( F_19 ( V_197 , & V_72 -> V_60 ) )
V_186 [ V_29 ++ ] = V_72 -> V_67 ;
}
F_79 ( & V_162 , V_164 | V_198 , V_156 ,
F_98 , V_22 , F_87 ( V_22 , V_184 ) ) ;
V_156 = F_90 ( V_187 , V_186 , 0 , V_29 , V_150 , & V_162 ) ;
return V_156 ;
}
static struct V_154 *
F_100 ( struct V_21 * V_22 , struct V_154 * V_156 )
{
int V_25 = V_22 -> V_25 ;
int V_69 ;
F_38 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
struct V_9 * V_199 ;
if ( F_26 ( V_197 , & V_72 -> V_60 ) ) {
struct V_9 * V_200 ;
F_62 ( & V_22 -> V_173 ) ;
V_199 = V_72 -> V_80 ;
V_72 -> V_80 = NULL ;
F_21 ( V_72 -> V_81 ) ;
V_200 = V_72 -> V_81 = V_199 ;
F_65 ( & V_22 -> V_173 ) ;
while ( V_200 && V_200 -> V_13 <
V_72 -> V_10 + V_14 ) {
if ( V_200 -> V_121 & V_201 )
F_72 ( V_111 , & V_72 -> V_60 ) ;
if ( V_200 -> V_121 & V_118 )
F_72 ( V_117 , & V_72 -> V_60 ) ;
V_156 = F_78 ( 1 , V_200 , V_72 -> V_67 ,
V_72 -> V_10 , V_156 ) ;
V_200 = F_2 ( V_200 , V_72 -> V_10 ) ;
}
}
}
return V_156 ;
}
static void F_101 ( void * V_170 )
{
struct V_21 * V_22 = V_170 ;
int V_25 = V_22 -> V_25 ;
int V_32 = V_22 -> V_32 ;
int V_24 = V_22 -> V_24 ;
int V_69 ;
bool V_202 = false , V_203 = false ;
F_38 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_69 = V_25 ; V_69 -- ; ) {
V_202 |= F_19 ( V_111 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
V_203 |= F_19 ( V_117 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
}
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( V_72 -> V_81 || V_69 == V_32 || V_69 == V_24 ) {
F_72 ( V_177 , & V_72 -> V_60 ) ;
if ( V_202 )
F_72 ( V_111 , & V_72 -> V_60 ) ;
if ( V_203 )
F_72 ( V_117 , & V_72 -> V_60 ) ;
}
}
if ( V_22 -> V_36 == V_204 )
V_22 -> V_36 = V_205 ;
else if ( V_22 -> V_36 == V_206 )
V_22 -> V_36 = V_207 ;
else {
F_21 ( V_22 -> V_36 != V_208 ) ;
V_22 -> V_36 = V_209 ;
}
F_72 ( V_42 , & V_22 -> V_38 ) ;
F_32 ( V_22 ) ;
}
static void
F_102 ( struct V_21 * V_22 , struct V_183 * V_184 ,
struct V_154 * V_156 )
{
int V_25 = V_22 -> V_25 ;
struct V_67 * * V_186 = V_184 -> V_185 ;
struct V_161 V_162 ;
int V_29 = 0 , V_32 = V_22 -> V_32 , V_69 ;
struct V_67 * V_187 ;
int V_210 = 0 ;
unsigned long V_60 ;
F_38 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
if ( V_22 -> V_36 == V_206 ) {
V_210 = 1 ;
V_187 = V_186 [ V_29 ++ ] = V_22 -> V_72 [ V_32 ] . V_67 ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( V_72 -> V_81 )
V_186 [ V_29 ++ ] = V_72 -> V_67 ;
}
} else {
V_187 = V_22 -> V_72 [ V_32 ] . V_67 ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( V_69 != V_32 )
V_186 [ V_29 ++ ] = V_72 -> V_67 ;
}
}
V_60 = V_174 |
( V_210 ? V_198 : V_188 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_79 ( & V_162 , V_60 , V_156 , F_101 , V_22 ,
F_87 ( V_22 , V_184 ) ) ;
if ( F_89 ( V_29 == 1 ) )
V_156 = F_81 ( V_187 , V_186 [ 0 ] , 0 , 0 , V_150 , & V_162 ) ;
else
V_156 = F_90 ( V_187 , V_186 , 0 , V_29 , V_150 , & V_162 ) ;
}
static void
F_103 ( struct V_21 * V_22 , struct V_183 * V_184 ,
struct V_154 * V_156 )
{
struct V_161 V_162 ;
struct V_67 * * V_191 = V_184 -> V_185 ;
int V_29 ;
F_38 ( L_12 , V_140 , ( unsigned long long ) V_22 -> V_10 ) ;
V_29 = F_91 ( V_191 , V_22 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_79 ( & V_162 , V_174 , V_156 , F_101 ,
V_22 , F_87 ( V_22 , V_184 ) ) ;
F_93 ( V_191 , 0 , V_29 + 2 , V_150 , & V_162 ) ;
}
static void F_104 ( void * V_170 )
{
struct V_21 * V_22 = V_170 ;
F_38 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
V_22 -> V_35 = V_211 ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
F_32 ( V_22 ) ;
}
static void F_105 ( struct V_21 * V_22 , struct V_183 * V_184 )
{
int V_25 = V_22 -> V_25 ;
int V_32 = V_22 -> V_32 ;
int V_24 = V_22 -> V_24 ;
struct V_67 * V_187 ;
struct V_67 * * V_186 = V_184 -> V_185 ;
struct V_154 * V_156 ;
struct V_161 V_162 ;
int V_29 ;
int V_69 ;
F_38 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
V_29 = 0 ;
V_187 = V_22 -> V_72 [ V_32 ] . V_67 ;
V_186 [ V_29 ++ ] = V_187 ;
for ( V_69 = V_25 ; V_69 -- ; ) {
if ( V_69 == V_32 || V_69 == V_24 )
continue;
V_186 [ V_29 ++ ] = V_22 -> V_72 [ V_69 ] . V_67 ;
}
F_79 ( & V_162 , 0 , NULL , NULL , NULL ,
F_87 ( V_22 , V_184 ) ) ;
V_156 = F_106 ( V_187 , V_186 , 0 , V_29 , V_150 ,
& V_22 -> V_179 . V_212 , & V_162 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_79 ( & V_162 , V_174 , V_156 , F_104 , V_22 , NULL ) ;
V_156 = F_84 ( & V_162 ) ;
}
static void F_107 ( struct V_21 * V_22 , struct V_183 * V_184 , int V_213 )
{
struct V_67 * * V_189 = V_184 -> V_185 ;
struct V_161 V_162 ;
int V_29 ;
F_38 ( L_16 , V_140 ,
( unsigned long long ) V_22 -> V_10 , V_213 ) ;
V_29 = F_91 ( V_189 , V_22 ) ;
if ( ! V_213 )
V_189 [ V_29 ] = NULL ;
F_8 ( & V_22 -> V_29 ) ;
F_79 ( & V_162 , V_174 , NULL , F_104 ,
V_22 , F_87 ( V_22 , V_184 ) ) ;
F_108 ( V_189 , 0 , V_29 + 2 , V_150 ,
& V_22 -> V_179 . V_212 , V_184 -> V_214 , & V_162 ) ;
}
static void F_109 ( struct V_21 * V_22 , unsigned long V_215 )
{
int V_216 = 0 , V_69 , V_25 = V_22 -> V_25 ;
struct V_154 * V_156 = NULL ;
struct V_2 * V_3 = V_22 -> V_59 ;
int V_217 = V_3 -> V_217 ;
struct V_183 * V_184 ;
unsigned long V_218 ;
V_218 = F_110 () ;
V_184 = F_111 ( V_3 -> V_184 , V_218 ) ;
if ( F_19 ( V_219 , & V_215 ) ) {
F_83 ( V_22 ) ;
V_216 ++ ;
}
if ( F_19 ( V_220 , & V_215 ) ) {
if ( V_217 < 6 )
V_156 = F_88 ( V_22 , V_184 ) ;
else {
if ( V_22 -> V_179 . V_180 < 0 || V_22 -> V_179 . V_175 < 0 )
V_156 = F_92 ( V_22 , V_184 ) ;
else
V_156 = F_94 ( V_22 , V_184 ) ;
}
if ( V_156 && ! F_19 ( V_221 , & V_215 ) )
F_112 ( V_156 ) ;
}
if ( F_19 ( V_222 , & V_215 ) )
V_156 = F_99 ( V_22 , V_184 , V_156 ) ;
if ( F_19 ( V_223 , & V_215 ) ) {
V_156 = F_100 ( V_22 , V_156 ) ;
V_216 ++ ;
}
if ( F_19 ( V_221 , & V_215 ) ) {
if ( V_217 < 6 )
F_102 ( V_22 , V_184 , V_156 ) ;
else
F_103 ( V_22 , V_184 , V_156 ) ;
}
if ( F_19 ( V_224 , & V_215 ) ) {
if ( V_22 -> V_35 == V_225 )
F_105 ( V_22 , V_184 ) ;
else if ( V_22 -> V_35 == V_226 )
F_107 ( V_22 , V_184 , 0 ) ;
else if ( V_22 -> V_35 == V_227 )
F_107 ( V_22 , V_184 , 1 ) ;
else
F_64 () ;
}
if ( V_216 )
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( F_26 ( V_228 , & V_72 -> V_60 ) )
F_29 ( & V_22 -> V_59 -> V_229 ) ;
}
F_113 () ;
}
static void F_114 ( void * V_230 , T_4 V_231 )
{
struct V_21 * V_22 = V_230 ;
unsigned long V_215 = V_22 -> V_179 . V_232 ;
F_115 ( V_233 , & V_22 -> V_38 ) ;
F_29 ( & V_22 -> V_179 . V_234 ) ;
F_109 ( V_22 , V_215 ) ;
F_32 ( V_22 ) ;
}
static void F_116 ( struct V_21 * V_22 , unsigned long V_215 )
{
F_117 ( V_22 -> V_179 . V_234 ,
! F_118 ( V_233 , & V_22 -> V_38 ) ) ;
V_22 -> V_179 . V_232 = V_215 ;
F_8 ( & V_22 -> V_29 ) ;
F_119 ( F_114 , V_22 ) ;
}
static int F_120 ( struct V_2 * V_3 )
{
struct V_21 * V_22 ;
V_22 = F_121 ( V_3 -> V_235 , V_73 ) ;
if ( ! V_22 )
return 0 ;
V_22 -> V_59 = V_3 ;
#ifdef F_122
F_123 ( & V_22 -> V_179 . V_234 ) ;
#endif
F_124 ( & V_22 -> V_173 ) ;
if ( F_47 ( V_22 ) ) {
F_45 ( V_22 ) ;
F_125 ( V_3 -> V_235 , V_22 ) ;
return 0 ;
}
F_12 ( & V_22 -> V_29 , 1 ) ;
F_8 ( & V_3 -> V_41 ) ;
F_126 ( & V_22 -> V_40 ) ;
F_32 ( V_22 ) ;
return 1 ;
}
static int F_127 ( struct V_2 * V_3 , int V_70 )
{
struct V_236 * V_237 ;
int V_238 = F_128 ( V_3 -> V_27 , V_3 -> V_76 ) ;
if ( V_3 -> V_51 -> V_239 )
sprintf ( V_3 -> V_240 [ 0 ] ,
L_17 , V_3 -> V_217 , F_129 ( V_3 -> V_51 ) ) ;
else
sprintf ( V_3 -> V_240 [ 0 ] ,
L_18 , V_3 -> V_217 , V_3 -> V_51 ) ;
sprintf ( V_3 -> V_240 [ 1 ] , L_19 , V_3 -> V_240 [ 0 ] ) ;
V_3 -> V_241 = 0 ;
V_237 = F_130 ( V_3 -> V_240 [ V_3 -> V_241 ] ,
sizeof( struct V_21 ) + ( V_238 - 1 ) * sizeof( struct V_77 ) ,
0 , 0 , NULL ) ;
if ( ! V_237 )
return 1 ;
V_3 -> V_235 = V_237 ;
V_3 -> V_71 = V_238 ;
while ( V_70 -- )
if ( ! F_120 ( V_3 ) )
return 1 ;
return 0 ;
}
static T_5 F_131 ( int V_70 )
{
T_5 V_165 ;
V_165 = sizeof( struct V_67 * ) * ( V_70 + 2 ) + sizeof( T_3 ) * ( V_70 + 2 ) ;
return V_165 ;
}
static int F_132 ( struct V_2 * V_3 , int V_242 )
{
struct V_21 * V_243 , * V_244 ;
F_133 ( V_245 ) ;
struct V_246 * V_247 ;
unsigned long V_218 ;
int V_248 ;
struct V_236 * V_237 ;
int V_69 ;
if ( V_242 <= V_3 -> V_71 )
return 0 ;
V_248 = F_134 ( V_3 -> V_51 ) ;
if ( V_248 )
return V_248 ;
V_237 = F_130 ( V_3 -> V_240 [ 1 - V_3 -> V_241 ] ,
sizeof( struct V_21 ) + ( V_242 - 1 ) * sizeof( struct V_77 ) ,
0 , 0 , NULL ) ;
if ( ! V_237 )
return - V_249 ;
for ( V_69 = V_3 -> V_100 ; V_69 ; V_69 -- ) {
V_244 = F_121 ( V_237 , V_73 ) ;
if ( ! V_244 )
break;
V_244 -> V_59 = V_3 ;
#ifdef F_122
F_123 ( & V_244 -> V_179 . V_234 ) ;
#endif
F_124 ( & V_244 -> V_173 ) ;
F_135 ( & V_244 -> V_40 , & V_245 ) ;
}
if ( V_69 ) {
while ( ! F_22 ( & V_245 ) ) {
V_244 = F_43 ( V_245 . V_66 , struct V_21 , V_40 ) ;
F_136 ( & V_244 -> V_40 ) ;
F_125 ( V_237 , V_244 ) ;
}
F_137 ( V_237 ) ;
return - V_249 ;
}
F_138 (nsh, &newstripes, lru) {
F_62 ( & V_3 -> V_61 ) ;
F_63 ( V_3 -> V_57 ,
! F_22 ( & V_3 -> V_56 ) ,
V_3 -> V_61 ,
) ;
V_243 = F_42 ( V_3 ) ;
F_65 ( & V_3 -> V_61 ) ;
F_12 ( & V_244 -> V_29 , 1 ) ;
for( V_69 = 0 ; V_69 < V_3 -> V_71 ; V_69 ++ )
V_244 -> V_72 [ V_69 ] . V_67 = V_243 -> V_72 [ V_69 ] . V_67 ;
for( ; V_69 < V_242 ; V_69 ++ )
V_244 -> V_72 [ V_69 ] . V_67 = NULL ;
F_125 ( V_3 -> V_235 , V_243 ) ;
}
F_137 ( V_3 -> V_235 ) ;
V_247 = F_139 ( V_242 * sizeof( struct V_246 ) , V_250 ) ;
if ( V_247 ) {
for ( V_69 = 0 ; V_69 < V_3 -> V_27 ; V_69 ++ )
V_247 [ V_69 ] = V_3 -> V_25 [ V_69 ] ;
F_140 ( V_3 -> V_25 ) ;
V_3 -> V_25 = V_247 ;
} else
V_248 = - V_249 ;
F_141 () ;
V_3 -> F_131 = F_131 ( V_242 ) ;
F_142 (cpu) {
struct V_183 * V_184 ;
void * V_185 ;
V_184 = F_111 ( V_3 -> V_184 , V_218 ) ;
V_185 = F_143 ( V_3 -> F_131 , V_250 ) ;
if ( V_185 ) {
F_140 ( V_184 -> V_185 ) ;
V_184 -> V_185 = V_185 ;
} else {
V_248 = - V_249 ;
break;
}
}
F_144 () ;
while( ! F_22 ( & V_245 ) ) {
V_244 = F_43 ( V_245 . V_66 , struct V_21 , V_40 ) ;
F_44 ( & V_244 -> V_40 ) ;
for ( V_69 = V_3 -> V_27 ; V_69 < V_242 ; V_69 ++ )
if ( V_244 -> V_72 [ V_69 ] . V_67 == NULL ) {
struct V_67 * V_68 = F_48 ( V_250 ) ;
V_244 -> V_72 [ V_69 ] . V_67 = V_68 ;
if ( ! V_68 )
V_248 = - V_249 ;
}
F_32 ( V_244 ) ;
}
V_3 -> V_235 = V_237 ;
V_3 -> V_241 = 1 - V_3 -> V_241 ;
V_3 -> V_71 = V_242 ;
return V_248 ;
}
static int F_145 ( struct V_2 * V_3 )
{
struct V_21 * V_22 ;
F_62 ( & V_3 -> V_61 ) ;
V_22 = F_42 ( V_3 ) ;
F_65 ( & V_3 -> V_61 ) ;
if ( ! V_22 )
return 0 ;
F_21 ( F_4 ( & V_22 -> V_29 ) ) ;
F_45 ( V_22 ) ;
F_125 ( V_3 -> V_235 , V_22 ) ;
F_28 ( & V_3 -> V_41 ) ;
return 1 ;
}
static void F_146 ( struct V_2 * V_3 )
{
while ( F_145 ( V_3 ) )
;
if ( V_3 -> V_235 )
F_137 ( V_3 -> V_235 ) ;
V_3 -> V_235 = NULL ;
}
static void V_124 ( struct V_9 * V_34 , int error )
{
struct V_21 * V_22 = V_34 -> V_251 ;
struct V_2 * V_3 = V_22 -> V_59 ;
int V_25 = V_22 -> V_25 , V_69 ;
int V_252 = F_19 ( V_146 , & V_34 -> V_145 ) ;
char V_253 [ V_254 ] ;
struct V_88 * V_89 = NULL ;
T_1 V_105 ;
for ( V_69 = 0 ; V_69 < V_25 ; V_69 ++ )
if ( V_34 == & V_22 -> V_72 [ V_69 ] . V_119 )
break;
F_38 ( L_20 ,
( unsigned long long ) V_22 -> V_10 , V_69 , F_4 ( & V_22 -> V_29 ) ,
V_252 ) ;
if ( V_69 == V_25 ) {
F_64 () ;
return;
}
if ( F_19 ( V_125 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
V_89 = V_3 -> V_25 [ V_69 ] . V_91 ;
if ( ! V_89 )
V_89 = V_3 -> V_25 [ V_69 ] . V_89 ;
if ( F_66 ( V_3 , V_22 ) )
V_105 = V_22 -> V_10 + V_89 -> V_141 ;
else
V_105 = V_22 -> V_10 + V_89 -> V_142 ;
if ( V_252 ) {
F_72 ( V_177 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
if ( F_19 ( V_255 , & V_22 -> V_72 [ V_69 ] . V_60 ) ) {
F_147 (
V_256
L_21
L_22 ,
F_129 ( V_3 -> V_51 ) , V_14 ,
( unsigned long long ) V_105 ,
F_148 ( V_89 -> V_137 , V_253 ) ) ;
F_149 ( V_14 , & V_89 -> V_257 ) ;
F_24 ( V_255 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_24 ( V_258 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
} else if ( F_19 ( V_143 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
F_24 ( V_143 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
if ( F_4 ( & V_89 -> V_259 ) )
F_12 ( & V_89 -> V_259 , 0 ) ;
} else {
const char * V_260 = F_148 ( V_89 -> V_137 , V_253 ) ;
int V_261 = 0 ;
int V_262 = 0 ;
F_24 ( V_177 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_8 ( & V_89 -> V_259 ) ;
if ( F_19 ( V_125 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
F_147 (
V_263
L_23
L_24 ,
F_129 ( V_3 -> V_51 ) ,
( unsigned long long ) V_105 ,
V_260 ) ;
else if ( V_3 -> V_51 -> V_86 >= V_3 -> V_95 ) {
V_262 = 1 ;
F_147 (
V_263
L_25
L_24 ,
F_129 ( V_3 -> V_51 ) ,
( unsigned long long ) V_105 ,
V_260 ) ;
} else if ( F_19 ( V_258 , & V_22 -> V_72 [ V_69 ] . V_60 ) ) {
V_262 = 1 ;
F_147 (
V_263
L_26
L_24 ,
F_129 ( V_3 -> V_51 ) ,
( unsigned long long ) V_105 ,
V_260 ) ;
} else if ( F_4 ( & V_89 -> V_259 )
> V_3 -> V_100 )
F_51 ( V_263
L_27 ,
F_129 ( V_3 -> V_51 ) , V_260 ) ;
else
V_261 = 1 ;
if ( V_261 )
if ( F_19 ( V_143 , & V_22 -> V_72 [ V_69 ] . V_60 ) ) {
F_72 ( V_255 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_24 ( V_143 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
} else
F_72 ( V_143 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
else {
F_24 ( V_255 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_24 ( V_258 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
if ( ! ( V_262
&& F_19 ( V_92 , & V_89 -> V_60 )
&& F_150 (
V_89 , V_22 -> V_10 , V_14 , 0 ) ) )
F_151 ( V_3 -> V_51 , V_89 ) ;
}
}
F_75 ( V_89 , V_3 -> V_51 ) ;
F_24 ( V_82 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
F_32 ( V_22 ) ;
}
static void V_123 ( struct V_9 * V_34 , int error )
{
struct V_21 * V_22 = V_34 -> V_251 ;
struct V_2 * V_3 = V_22 -> V_59 ;
int V_25 = V_22 -> V_25 , V_69 ;
struct V_88 * V_264 ( V_89 ) ;
int V_252 = F_19 ( V_146 , & V_34 -> V_145 ) ;
T_1 V_128 ;
int V_129 ;
int V_91 = 0 ;
for ( V_69 = 0 ; V_69 < V_25 ; V_69 ++ ) {
if ( V_34 == & V_22 -> V_72 [ V_69 ] . V_119 ) {
V_89 = V_3 -> V_25 [ V_69 ] . V_89 ;
break;
}
if ( V_34 == & V_22 -> V_72 [ V_69 ] . V_120 ) {
V_89 = V_3 -> V_25 [ V_69 ] . V_91 ;
if ( V_89 )
V_91 = 1 ;
else
V_89 = V_3 -> V_25 [ V_69 ] . V_89 ;
break;
}
}
F_38 ( L_28 ,
( unsigned long long ) V_22 -> V_10 , V_69 , F_4 ( & V_22 -> V_29 ) ,
V_252 ) ;
if ( V_69 == V_25 ) {
F_64 () ;
return;
}
if ( V_91 ) {
if ( ! V_252 )
F_151 ( V_3 -> V_51 , V_89 ) ;
else if ( F_71 ( V_89 , V_22 -> V_10 ,
V_14 ,
& V_128 , & V_129 ) )
F_72 ( V_265 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
} else {
if ( ! V_252 ) {
F_72 ( V_127 , & V_89 -> V_60 ) ;
F_72 ( V_266 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
if ( ! F_152 ( V_267 , & V_89 -> V_60 ) )
F_72 ( V_268 ,
& V_89 -> V_51 -> V_269 ) ;
} else if ( F_71 ( V_89 , V_22 -> V_10 ,
V_14 ,
& V_128 , & V_129 ) )
F_72 ( V_270 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
}
F_75 ( V_89 , V_3 -> V_51 ) ;
if ( ! F_26 ( V_152 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
F_24 ( V_82 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
F_32 ( V_22 ) ;
}
static void F_53 ( struct V_21 * V_22 , int V_69 , int V_74 )
{
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
F_153 ( & V_72 -> V_119 ) ;
V_72 -> V_119 . V_148 = & V_72 -> V_271 ;
V_72 -> V_119 . V_272 ++ ;
V_72 -> V_119 . V_273 ++ ;
V_72 -> V_119 . V_251 = V_22 ;
V_72 -> V_271 . V_168 = V_72 -> V_67 ;
F_153 ( & V_72 -> V_120 ) ;
V_72 -> V_120 . V_148 = & V_72 -> V_274 ;
V_72 -> V_120 . V_272 ++ ;
V_72 -> V_120 . V_273 ++ ;
V_72 -> V_120 . V_251 = V_22 ;
V_72 -> V_274 . V_168 = V_72 -> V_67 ;
V_72 -> V_60 = 0 ;
V_72 -> V_10 = F_154 ( V_22 , V_69 , V_74 ) ;
}
static void error ( struct V_51 * V_51 , struct V_88 * V_89 )
{
char V_253 [ V_254 ] ;
struct V_2 * V_3 = V_51 -> V_275 ;
unsigned long V_60 ;
F_38 ( L_29 ) ;
F_155 ( & V_3 -> V_61 , V_60 ) ;
F_24 ( V_92 , & V_89 -> V_60 ) ;
V_51 -> V_86 = F_56 ( V_3 ) ;
F_156 ( & V_3 -> V_61 , V_60 ) ;
F_72 ( V_276 , & V_51 -> V_269 ) ;
F_72 ( V_277 , & V_89 -> V_60 ) ;
F_72 ( V_90 , & V_89 -> V_60 ) ;
F_72 ( V_278 , & V_51 -> V_60 ) ;
F_51 ( V_279
L_30
L_31 ,
F_129 ( V_51 ) ,
F_148 ( V_89 -> V_137 , V_253 ) ,
F_129 ( V_51 ) ,
V_3 -> V_27 - V_51 -> V_86 ) ;
}
static T_1 F_157 ( struct V_2 * V_3 , T_1 V_280 ,
int V_74 , int * V_281 ,
struct V_21 * V_22 )
{
T_1 V_282 , V_283 ;
T_1 V_284 ;
unsigned int V_285 ;
int V_32 , V_24 ;
int V_23 = 0 ;
T_1 V_286 ;
int V_287 = V_74 ? V_3 -> V_288
: V_3 -> V_287 ;
int V_289 = V_74 ? V_3 -> V_290
: V_3 -> V_291 ;
int V_27 = V_74 ? V_3 -> V_76
: V_3 -> V_27 ;
int V_292 = V_27 - V_3 -> V_95 ;
V_285 = F_158 ( V_280 , V_289 ) ;
V_284 = V_280 ;
V_282 = V_284 ;
* V_281 = F_158 ( V_282 , V_292 ) ;
V_283 = V_282 ;
V_32 = V_24 = - 1 ;
switch( V_3 -> V_217 ) {
case 4 :
V_32 = V_292 ;
break;
case 5 :
switch ( V_287 ) {
case V_293 :
V_32 = V_292 - F_158 ( V_283 , V_27 ) ;
if ( * V_281 >= V_32 )
( * V_281 ) ++ ;
break;
case V_294 :
V_32 = F_158 ( V_283 , V_27 ) ;
if ( * V_281 >= V_32 )
( * V_281 ) ++ ;
break;
case V_295 :
V_32 = V_292 - F_158 ( V_283 , V_27 ) ;
* V_281 = ( V_32 + 1 + * V_281 ) % V_27 ;
break;
case V_296 :
V_32 = F_158 ( V_283 , V_27 ) ;
* V_281 = ( V_32 + 1 + * V_281 ) % V_27 ;
break;
case V_297 :
V_32 = 0 ;
( * V_281 ) ++ ;
break;
case V_298 :
V_32 = V_292 ;
break;
default:
F_64 () ;
}
break;
case 6 :
switch ( V_287 ) {
case V_293 :
V_32 = V_27 - 1 - F_158 ( V_283 , V_27 ) ;
V_24 = V_32 + 1 ;
if ( V_32 == V_27 - 1 ) {
( * V_281 ) ++ ;
V_24 = 0 ;
} else if ( * V_281 >= V_32 )
( * V_281 ) += 2 ;
break;
case V_294 :
V_32 = F_158 ( V_283 , V_27 ) ;
V_24 = V_32 + 1 ;
if ( V_32 == V_27 - 1 ) {
( * V_281 ) ++ ;
V_24 = 0 ;
} else if ( * V_281 >= V_32 )
( * V_281 ) += 2 ;
break;
case V_295 :
V_32 = V_27 - 1 - F_158 ( V_283 , V_27 ) ;
V_24 = ( V_32 + 1 ) % V_27 ;
* V_281 = ( V_32 + 2 + * V_281 ) % V_27 ;
break;
case V_296 :
V_32 = F_158 ( V_283 , V_27 ) ;
V_24 = ( V_32 + 1 ) % V_27 ;
* V_281 = ( V_32 + 2 + * V_281 ) % V_27 ;
break;
case V_297 :
V_32 = 0 ;
V_24 = 1 ;
( * V_281 ) += 2 ;
break;
case V_298 :
V_32 = V_292 ;
V_24 = V_292 + 1 ;
break;
case V_299 :
V_32 = F_158 ( V_283 , V_27 ) ;
V_24 = V_32 + 1 ;
if ( V_32 == V_27 - 1 ) {
( * V_281 ) ++ ;
V_24 = 0 ;
} else if ( * V_281 >= V_32 )
( * V_281 ) += 2 ;
V_23 = 1 ;
break;
case V_300 :
V_283 += 1 ;
V_32 = V_27 - 1 - F_158 ( V_283 , V_27 ) ;
V_24 = V_32 + 1 ;
if ( V_32 == V_27 - 1 ) {
( * V_281 ) ++ ;
V_24 = 0 ;
} else if ( * V_281 >= V_32 )
( * V_281 ) += 2 ;
V_23 = 1 ;
break;
case V_301 :
V_32 = V_27 - 1 - F_158 ( V_283 , V_27 ) ;
V_24 = ( V_32 + V_27 - 1 ) % V_27 ;
* V_281 = ( V_32 + 1 + * V_281 ) % V_27 ;
V_23 = 1 ;
break;
case V_302 :
V_32 = V_292 - F_158 ( V_283 , V_27 - 1 ) ;
if ( * V_281 >= V_32 )
( * V_281 ) ++ ;
V_24 = V_27 - 1 ;
break;
case V_303 :
V_32 = F_158 ( V_283 , V_27 - 1 ) ;
if ( * V_281 >= V_32 )
( * V_281 ) ++ ;
V_24 = V_27 - 1 ;
break;
case V_304 :
V_32 = V_292 - F_158 ( V_283 , V_27 - 1 ) ;
* V_281 = ( V_32 + 1 + * V_281 ) % ( V_27 - 1 ) ;
V_24 = V_27 - 1 ;
break;
case V_305 :
V_32 = F_158 ( V_283 , V_27 - 1 ) ;
* V_281 = ( V_32 + 1 + * V_281 ) % ( V_27 - 1 ) ;
V_24 = V_27 - 1 ;
break;
case V_306 :
V_32 = 0 ;
( * V_281 ) ++ ;
V_24 = V_27 - 1 ;
break;
default:
F_64 () ;
}
break;
}
if ( V_22 ) {
V_22 -> V_32 = V_32 ;
V_22 -> V_24 = V_24 ;
V_22 -> V_23 = V_23 ;
}
V_286 = ( T_1 ) V_282 * V_289 + V_285 ;
return V_286 ;
}
static T_1 F_154 ( struct V_21 * V_22 , int V_69 , int V_74 )
{
struct V_2 * V_3 = V_22 -> V_59 ;
int V_27 = V_22 -> V_25 ;
int V_292 = V_27 - V_3 -> V_95 ;
T_1 V_286 = V_22 -> V_10 , V_307 ;
int V_289 = V_74 ? V_3 -> V_290
: V_3 -> V_291 ;
int V_287 = V_74 ? V_3 -> V_288
: V_3 -> V_287 ;
T_1 V_282 ;
int V_285 ;
T_1 V_284 ;
int V_308 , V_281 = V_69 ;
T_1 V_280 ;
struct V_21 V_309 ;
V_285 = F_158 ( V_286 , V_289 ) ;
V_282 = V_286 ;
if ( V_69 == V_22 -> V_32 )
return 0 ;
switch( V_3 -> V_217 ) {
case 4 : break;
case 5 :
switch ( V_287 ) {
case V_293 :
case V_294 :
if ( V_69 > V_22 -> V_32 )
V_69 -- ;
break;
case V_295 :
case V_296 :
if ( V_69 < V_22 -> V_32 )
V_69 += V_27 ;
V_69 -= ( V_22 -> V_32 + 1 ) ;
break;
case V_297 :
V_69 -= 1 ;
break;
case V_298 :
break;
default:
F_64 () ;
}
break;
case 6 :
if ( V_69 == V_22 -> V_24 )
return 0 ;
switch ( V_287 ) {
case V_293 :
case V_294 :
case V_299 :
case V_300 :
if ( V_22 -> V_32 == V_27 - 1 )
V_69 -- ;
else if ( V_69 > V_22 -> V_32 )
V_69 -= 2 ;
break;
case V_295 :
case V_296 :
if ( V_22 -> V_32 == V_27 - 1 )
V_69 -- ;
else {
if ( V_69 < V_22 -> V_32 )
V_69 += V_27 ;
V_69 -= ( V_22 -> V_32 + 2 ) ;
}
break;
case V_297 :
V_69 -= 2 ;
break;
case V_298 :
break;
case V_301 :
if ( V_22 -> V_32 == 0 )
V_69 -- ;
else {
if ( V_69 < V_22 -> V_32 )
V_69 += V_27 ;
V_69 -= ( V_22 -> V_32 + 1 ) ;
}
break;
case V_302 :
case V_303 :
if ( V_69 > V_22 -> V_32 )
V_69 -- ;
break;
case V_304 :
case V_305 :
if ( V_69 < V_22 -> V_32 )
V_69 += V_292 + 1 ;
V_69 -= ( V_22 -> V_32 + 1 ) ;
break;
case V_306 :
V_69 -= 1 ;
break;
default:
F_64 () ;
}
break;
}
V_284 = V_282 * V_292 + V_69 ;
V_280 = V_284 * V_289 + V_285 ;
V_307 = F_157 ( V_3 , V_280 ,
V_74 , & V_308 , & V_309 ) ;
if ( V_307 != V_22 -> V_10 || V_308 != V_281 || V_309 . V_32 != V_22 -> V_32
|| V_309 . V_24 != V_22 -> V_24 ) {
F_51 ( V_83 L_32 ,
F_129 ( V_3 -> V_51 ) ) ;
return 0 ;
}
return V_280 ;
}
static void
F_159 ( struct V_21 * V_22 , struct V_104 * V_105 ,
int V_310 , int V_311 )
{
int V_69 , V_32 = V_22 -> V_32 , V_25 = V_22 -> V_25 ;
struct V_2 * V_3 = V_22 -> V_59 ;
int V_217 = V_3 -> V_217 ;
if ( V_310 ) {
if ( ! V_311 ) {
V_22 -> V_36 = V_204 ;
F_72 ( V_223 , & V_105 -> V_215 ) ;
} else
V_22 -> V_36 = V_208 ;
F_72 ( V_221 , & V_105 -> V_215 ) ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( V_72 -> V_80 ) {
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_72 ( V_197 , & V_72 -> V_60 ) ;
if ( ! V_311 )
F_24 ( V_177 , & V_72 -> V_60 ) ;
V_105 -> V_312 ++ ;
}
}
if ( V_105 -> V_312 + V_3 -> V_95 == V_25 )
if ( ! F_152 ( V_313 , & V_22 -> V_38 ) )
F_8 ( & V_3 -> V_314 ) ;
} else {
F_21 ( V_217 == 6 ) ;
F_21 ( ! ( F_19 ( V_177 , & V_22 -> V_72 [ V_32 ] . V_60 ) ||
F_19 ( V_178 , & V_22 -> V_72 [ V_32 ] . V_60 ) ) ) ;
V_22 -> V_36 = V_206 ;
F_72 ( V_222 , & V_105 -> V_215 ) ;
F_72 ( V_223 , & V_105 -> V_215 ) ;
F_72 ( V_221 , & V_105 -> V_215 ) ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( V_69 == V_32 )
continue;
if ( V_72 -> V_80 &&
( F_19 ( V_177 , & V_72 -> V_60 ) ||
F_19 ( V_178 , & V_72 -> V_60 ) ) ) {
F_72 ( V_197 , & V_72 -> V_60 ) ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_24 ( V_177 , & V_72 -> V_60 ) ;
V_105 -> V_312 ++ ;
}
}
}
F_72 ( V_82 , & V_22 -> V_72 [ V_32 ] . V_60 ) ;
F_24 ( V_177 , & V_22 -> V_72 [ V_32 ] . V_60 ) ;
V_105 -> V_312 ++ ;
if ( V_217 == 6 ) {
int V_24 = V_22 -> V_24 ;
struct V_77 * V_72 = & V_22 -> V_72 [ V_24 ] ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_24 ( V_177 , & V_72 -> V_60 ) ;
V_105 -> V_312 ++ ;
}
F_38 ( L_33 ,
V_140 , ( unsigned long long ) V_22 -> V_10 ,
V_105 -> V_312 , V_105 -> V_215 ) ;
}
static int F_160 ( struct V_21 * V_22 , struct V_9 * V_34 , int V_281 , int V_315 )
{
struct V_9 * * V_316 ;
struct V_2 * V_3 = V_22 -> V_59 ;
int V_317 = 0 ;
F_38 ( L_34 ,
( unsigned long long ) V_34 -> V_13 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_62 ( & V_22 -> V_173 ) ;
if ( V_315 ) {
V_316 = & V_22 -> V_72 [ V_281 ] . V_80 ;
if ( * V_316 == NULL )
V_317 = 1 ;
} else
V_316 = & V_22 -> V_72 [ V_281 ] . V_78 ;
while ( * V_316 && ( * V_316 ) -> V_13 < V_34 -> V_13 ) {
if ( ( * V_316 ) -> V_13 + ( ( * V_316 ) -> V_12 >> 9 ) > V_34 -> V_13 )
goto V_318;
V_316 = & ( * V_316 ) -> V_15 ;
}
if ( * V_316 && ( * V_316 ) -> V_13 < V_34 -> V_13 + ( ( V_34 -> V_12 ) >> 9 ) )
goto V_318;
F_21 ( * V_316 && V_34 -> V_15 && ( * V_316 ) != V_34 -> V_15 ) ;
if ( * V_316 )
V_34 -> V_15 = * V_316 ;
* V_316 = V_34 ;
F_7 ( V_34 ) ;
if ( V_315 ) {
T_1 V_10 = V_22 -> V_72 [ V_281 ] . V_10 ;
for ( V_34 = V_22 -> V_72 [ V_281 ] . V_80 ;
V_10 < V_22 -> V_72 [ V_281 ] . V_10 + V_14 &&
V_34 && V_34 -> V_13 <= V_10 ;
V_34 = F_2 ( V_34 , V_22 -> V_72 [ V_281 ] . V_10 ) ) {
if ( V_34 -> V_13 + ( V_34 -> V_12 >> 9 ) >= V_10 )
V_10 = V_34 -> V_13 + ( V_34 -> V_12 >> 9 ) ;
}
if ( V_10 >= V_22 -> V_72 [ V_281 ] . V_10 + V_14 )
F_72 ( V_319 , & V_22 -> V_72 [ V_281 ] . V_60 ) ;
}
F_65 ( & V_22 -> V_173 ) ;
F_38 ( L_35 ,
( unsigned long long ) ( * V_316 ) -> V_13 ,
( unsigned long long ) V_22 -> V_10 , V_281 ) ;
if ( V_3 -> V_51 -> V_320 && V_317 ) {
F_161 ( V_3 -> V_51 -> V_320 , V_22 -> V_10 ,
V_14 , 0 ) ;
V_22 -> V_47 = V_3 -> V_321 + 1 ;
F_72 ( V_46 , & V_22 -> V_38 ) ;
}
return 1 ;
V_318:
F_72 ( V_228 , & V_22 -> V_72 [ V_281 ] . V_60 ) ;
F_65 ( & V_22 -> V_173 ) ;
return 0 ;
}
static void F_50 ( T_1 V_282 , struct V_2 * V_3 , int V_74 ,
struct V_21 * V_22 )
{
int V_289 =
V_74 ? V_3 -> V_290 : V_3 -> V_291 ;
int V_281 ;
int V_285 = F_158 ( V_282 , V_289 ) ;
int V_25 = V_74 ? V_3 -> V_76 : V_3 -> V_27 ;
F_157 ( V_3 ,
V_282 * ( V_25 - V_3 -> V_95 )
* V_289 + V_285 ,
V_74 ,
& V_281 , V_22 ) ;
}
static void
F_162 ( struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_104 * V_105 , int V_25 ,
struct V_9 * * V_33 )
{
int V_69 ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_9 * V_34 ;
int V_322 = 0 ;
if ( F_19 ( V_255 , & V_22 -> V_72 [ V_69 ] . V_60 ) ) {
struct V_88 * V_89 ;
F_57 () ;
V_89 = F_58 ( V_3 -> V_25 [ V_69 ] . V_89 ) ;
if ( V_89 && F_19 ( V_92 , & V_89 -> V_60 ) )
F_8 ( & V_89 -> V_126 ) ;
else
V_89 = NULL ;
F_59 () ;
if ( V_89 ) {
if ( ! F_150 (
V_89 ,
V_22 -> V_10 ,
V_14 , 0 ) )
F_151 ( V_3 -> V_51 , V_89 ) ;
F_75 ( V_89 , V_3 -> V_51 ) ;
}
}
F_62 ( & V_22 -> V_173 ) ;
V_34 = V_22 -> V_72 [ V_69 ] . V_80 ;
V_22 -> V_72 [ V_69 ] . V_80 = NULL ;
F_65 ( & V_22 -> V_173 ) ;
if ( V_34 ) {
V_105 -> V_323 -- ;
V_322 = 1 ;
}
if ( F_26 ( V_228 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
F_29 ( & V_3 -> V_229 ) ;
while ( V_34 && V_34 -> V_13 <
V_22 -> V_72 [ V_69 ] . V_10 + V_14 ) {
struct V_9 * V_324 = F_2 ( V_34 , V_22 -> V_72 [ V_69 ] . V_10 ) ;
F_24 ( V_146 , & V_34 -> V_145 ) ;
if ( ! F_5 ( V_34 ) ) {
F_163 ( V_3 -> V_51 ) ;
V_34 -> V_15 = * V_33 ;
* V_33 = V_34 ;
}
V_34 = V_324 ;
}
if ( V_322 )
F_164 ( V_3 -> V_51 -> V_320 , V_22 -> V_10 ,
V_14 , 0 , 0 ) ;
V_322 = 0 ;
V_34 = V_22 -> V_72 [ V_69 ] . V_81 ;
V_22 -> V_72 [ V_69 ] . V_81 = NULL ;
if ( V_34 ) V_322 = 1 ;
while ( V_34 && V_34 -> V_13 <
V_22 -> V_72 [ V_69 ] . V_10 + V_14 ) {
struct V_9 * V_325 = F_2 ( V_34 , V_22 -> V_72 [ V_69 ] . V_10 ) ;
F_24 ( V_146 , & V_34 -> V_145 ) ;
if ( ! F_5 ( V_34 ) ) {
F_163 ( V_3 -> V_51 ) ;
V_34 -> V_15 = * V_33 ;
* V_33 = V_34 ;
}
V_34 = V_325 ;
}
if ( ! F_19 ( V_171 , & V_22 -> V_72 [ V_69 ] . V_60 ) &&
( ! F_19 ( V_326 , & V_22 -> V_72 [ V_69 ] . V_60 ) ||
F_19 ( V_255 , & V_22 -> V_72 [ V_69 ] . V_60 ) ) ) {
V_34 = V_22 -> V_72 [ V_69 ] . V_78 ;
V_22 -> V_72 [ V_69 ] . V_78 = NULL ;
if ( F_26 ( V_228 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
F_29 ( & V_3 -> V_229 ) ;
if ( V_34 ) V_105 -> V_327 -- ;
while ( V_34 && V_34 -> V_13 <
V_22 -> V_72 [ V_69 ] . V_10 + V_14 ) {
struct V_9 * V_324 =
F_2 ( V_34 , V_22 -> V_72 [ V_69 ] . V_10 ) ;
F_24 ( V_146 , & V_34 -> V_145 ) ;
if ( ! F_5 ( V_34 ) ) {
V_34 -> V_15 = * V_33 ;
* V_33 = V_34 ;
}
V_34 = V_324 ;
}
}
if ( V_322 )
F_164 ( V_3 -> V_51 -> V_320 , V_22 -> V_10 ,
V_14 , 0 , 0 ) ;
F_24 ( V_82 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
}
if ( F_26 ( V_313 , & V_22 -> V_38 ) )
if ( F_31 ( & V_3 -> V_314 ) )
F_25 ( V_3 -> V_51 -> V_52 ) ;
}
static void
F_165 ( struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_104 * V_105 )
{
int abort = 0 ;
int V_69 ;
F_24 ( V_328 , & V_22 -> V_38 ) ;
V_105 -> V_133 = 0 ;
V_105 -> V_136 = 0 ;
if ( F_19 ( V_329 , & V_3 -> V_51 -> V_269 ) ) {
for ( V_69 = 0 ; V_69 < V_3 -> V_27 ; V_69 ++ ) {
struct V_88 * V_89 = V_3 -> V_25 [ V_69 ] . V_89 ;
if ( V_89
&& ! F_19 ( V_90 , & V_89 -> V_60 )
&& ! F_19 ( V_92 , & V_89 -> V_60 )
&& ! F_150 ( V_89 , V_22 -> V_10 ,
V_14 , 0 ) )
abort = 1 ;
V_89 = V_3 -> V_25 [ V_69 ] . V_91 ;
if ( V_89
&& ! F_19 ( V_90 , & V_89 -> V_60 )
&& ! F_19 ( V_92 , & V_89 -> V_60 )
&& ! F_150 ( V_89 , V_22 -> V_10 ,
V_14 , 0 ) )
abort = 1 ;
}
if ( abort )
V_3 -> V_330 =
V_3 -> V_51 -> V_330 ;
}
F_166 ( V_3 -> V_51 , V_14 , ! abort ) ;
}
static int F_167 ( struct V_21 * V_22 , int V_331 )
{
struct V_88 * V_89 ;
int V_332 = 0 ;
V_89 = V_22 -> V_59 -> V_25 [ V_331 ] . V_91 ;
if ( V_89
&& ! F_19 ( V_90 , & V_89 -> V_60 )
&& ! F_19 ( V_92 , & V_89 -> V_60 )
&& ( V_89 -> V_333 <= V_22 -> V_10
|| V_89 -> V_51 -> V_334 <= V_22 -> V_10 ) )
V_332 = 1 ;
return V_332 ;
}
static int F_168 ( struct V_21 * V_22 , struct V_104 * V_105 ,
int V_331 , int V_25 )
{
struct V_77 * V_72 = & V_22 -> V_72 [ V_331 ] ;
struct V_77 * V_335 [ 2 ] = { & V_22 -> V_72 [ V_105 -> V_336 [ 0 ] ] ,
& V_22 -> V_72 [ V_105 -> V_336 [ 1 ] ] } ;
if ( ! F_19 ( V_82 , & V_72 -> V_60 ) &&
! F_19 ( V_177 , & V_72 -> V_60 ) &&
( V_72 -> V_78 ||
( V_72 -> V_80 && ! F_19 ( V_319 , & V_72 -> V_60 ) ) ||
V_105 -> V_133 || V_105 -> V_134 ||
( V_105 -> V_136 && F_167 ( V_22 , V_331 ) ) ||
( V_105 -> V_337 >= 1 && V_335 [ 0 ] -> V_78 ) ||
( V_105 -> V_337 >= 2 && V_335 [ 1 ] -> V_78 ) ||
( V_22 -> V_59 -> V_217 <= 5 && V_105 -> V_337 && V_335 [ 0 ] -> V_80 &&
! F_19 ( V_319 , & V_335 [ 0 ] -> V_60 ) ) ||
( V_22 -> V_59 -> V_217 == 6 && V_105 -> V_337 && V_105 -> V_323 ) ) ) {
F_21 ( F_19 ( V_178 , & V_72 -> V_60 ) ) ;
F_21 ( F_19 ( V_114 , & V_72 -> V_60 ) ) ;
if ( ( V_105 -> V_252 == V_25 - 1 ) &&
( V_105 -> V_337 && ( V_331 == V_105 -> V_336 [ 0 ] ||
V_331 == V_105 -> V_336 [ 1 ] ) ) ) {
F_38 ( L_36 ,
( unsigned long long ) V_22 -> V_10 , V_331 ) ;
F_72 ( V_39 , & V_22 -> V_38 ) ;
F_72 ( V_220 , & V_105 -> V_215 ) ;
F_72 ( V_178 , & V_72 -> V_60 ) ;
V_22 -> V_179 . V_175 = V_331 ;
V_22 -> V_179 . V_180 = - 1 ;
V_105 -> V_338 = 1 ;
V_105 -> V_252 ++ ;
return 1 ;
} else if ( V_105 -> V_252 == V_25 - 2 && V_105 -> V_337 >= 2 ) {
int V_339 ;
for ( V_339 = V_25 ; V_339 -- ; ) {
if ( V_339 == V_331 )
continue;
if ( ! F_19 ( V_177 ,
& V_22 -> V_72 [ V_339 ] . V_60 ) )
break;
}
F_21 ( V_339 < 0 ) ;
F_38 ( L_37 ,
( unsigned long long ) V_22 -> V_10 ,
V_331 , V_339 ) ;
F_72 ( V_39 , & V_22 -> V_38 ) ;
F_72 ( V_220 , & V_105 -> V_215 ) ;
F_72 ( V_178 , & V_22 -> V_72 [ V_331 ] . V_60 ) ;
F_72 ( V_178 , & V_22 -> V_72 [ V_339 ] . V_60 ) ;
V_22 -> V_179 . V_175 = V_331 ;
V_22 -> V_179 . V_180 = V_339 ;
V_105 -> V_252 += 2 ;
V_105 -> V_338 = 1 ;
return 1 ;
} else if ( F_19 ( V_326 , & V_72 -> V_60 ) ) {
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_72 ( V_114 , & V_72 -> V_60 ) ;
V_105 -> V_312 ++ ;
F_38 ( L_38 ,
V_331 , V_105 -> V_133 ) ;
}
}
return 0 ;
}
static void F_169 ( struct V_21 * V_22 ,
struct V_104 * V_105 ,
int V_25 )
{
int V_69 ;
if ( ! F_19 ( V_39 , & V_22 -> V_38 ) && ! V_22 -> V_35 &&
! V_22 -> V_36 )
for ( V_69 = V_25 ; V_69 -- ; )
if ( F_168 ( V_22 , V_105 , V_69 , V_25 ) )
break;
F_72 ( V_42 , & V_22 -> V_38 ) ;
}
static void F_170 ( struct V_2 * V_3 ,
struct V_21 * V_22 , int V_25 , struct V_9 * * V_33 )
{
int V_69 ;
struct V_77 * V_72 ;
for ( V_69 = V_25 ; V_69 -- ; )
if ( V_22 -> V_72 [ V_69 ] . V_81 ) {
V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( ! F_19 ( V_82 , & V_72 -> V_60 ) &&
F_19 ( V_177 , & V_72 -> V_60 ) ) {
struct V_9 * V_200 , * V_340 ;
F_38 ( L_39 , V_69 ) ;
V_200 = V_72 -> V_81 ;
V_72 -> V_81 = NULL ;
while ( V_200 && V_200 -> V_13 <
V_72 -> V_10 + V_14 ) {
V_340 = F_2 ( V_200 , V_72 -> V_10 ) ;
if ( ! F_5 ( V_200 ) ) {
F_163 ( V_3 -> V_51 ) ;
V_200 -> V_15 = * V_33 ;
* V_33 = V_200 ;
}
V_200 = V_340 ;
}
F_164 ( V_3 -> V_51 -> V_320 , V_22 -> V_10 ,
V_14 ,
! F_19 ( V_153 , & V_22 -> V_38 ) ,
0 ) ;
}
}
if ( F_26 ( V_313 , & V_22 -> V_38 ) )
if ( F_31 ( & V_3 -> V_314 ) )
F_25 ( V_3 -> V_51 -> V_52 ) ;
}
static void F_171 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
struct V_104 * V_105 ,
int V_25 )
{
int V_341 = 0 , V_310 = 0 , V_69 ;
if ( V_3 -> V_95 == 2 ) {
V_310 = 1 ; V_341 = 2 ;
} else for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( ( V_72 -> V_80 || V_69 == V_22 -> V_32 ) &&
! F_19 ( V_82 , & V_72 -> V_60 ) &&
! ( F_19 ( V_177 , & V_72 -> V_60 ) ||
F_19 ( V_178 , & V_72 -> V_60 ) ) ) {
if ( F_19 ( V_326 , & V_72 -> V_60 ) )
V_341 ++ ;
else
V_341 += 2 * V_25 ;
}
if ( ! F_19 ( V_319 , & V_72 -> V_60 ) && V_69 != V_22 -> V_32 &&
! F_19 ( V_82 , & V_72 -> V_60 ) &&
! ( F_19 ( V_177 , & V_72 -> V_60 ) ||
F_19 ( V_178 , & V_72 -> V_60 ) ) ) {
if ( F_19 ( V_326 , & V_72 -> V_60 ) ) V_310 ++ ;
else
V_310 += 2 * V_25 ;
}
}
F_38 ( L_40 ,
( unsigned long long ) V_22 -> V_10 , V_341 , V_310 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
if ( V_341 < V_310 && V_341 > 0 )
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( ( V_72 -> V_80 || V_69 == V_22 -> V_32 ) &&
! F_19 ( V_82 , & V_72 -> V_60 ) &&
! ( F_19 ( V_177 , & V_72 -> V_60 ) ||
F_19 ( V_178 , & V_72 -> V_60 ) ) &&
F_19 ( V_326 , & V_72 -> V_60 ) ) {
if (
F_19 ( V_44 , & V_22 -> V_38 ) ) {
F_38 ( L_41
L_42 , V_69 ) ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_72 ( V_114 , & V_72 -> V_60 ) ;
V_105 -> V_312 ++ ;
} else {
F_72 ( V_43 , & V_22 -> V_38 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
}
}
}
if ( V_310 <= V_341 && V_310 > 0 ) {
V_310 = 0 ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( ! F_19 ( V_319 , & V_72 -> V_60 ) &&
V_69 != V_22 -> V_32 && V_69 != V_22 -> V_24 &&
! F_19 ( V_82 , & V_72 -> V_60 ) &&
! ( F_19 ( V_177 , & V_72 -> V_60 ) ||
F_19 ( V_178 , & V_72 -> V_60 ) ) ) {
V_310 ++ ;
if ( ! F_19 ( V_326 , & V_72 -> V_60 ) )
continue;
if (
F_19 ( V_44 , & V_22 -> V_38 ) ) {
F_38 ( L_41
L_43 , V_69 ) ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_72 ( V_114 , & V_72 -> V_60 ) ;
V_105 -> V_312 ++ ;
} else {
F_72 ( V_43 , & V_22 -> V_38 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
}
}
}
}
if ( ( V_105 -> V_338 || ! F_19 ( V_39 , & V_22 -> V_38 ) ) &&
( V_105 -> V_312 == 0 && ( V_310 == 0 || V_341 == 0 ) &&
! F_19 ( V_46 , & V_22 -> V_38 ) ) )
F_159 ( V_22 , V_105 , V_310 == 0 , 0 ) ;
}
static void F_172 ( struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_104 * V_105 , int V_25 )
{
struct V_77 * V_72 = NULL ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
switch ( V_22 -> V_35 ) {
case V_342 :
if ( V_105 -> V_337 == 0 ) {
F_21 ( V_105 -> V_252 != V_25 ) ;
V_22 -> V_35 = V_225 ;
F_72 ( V_224 , & V_105 -> V_215 ) ;
F_24 ( V_177 , & V_22 -> V_72 [ V_22 -> V_32 ] . V_60 ) ;
V_105 -> V_252 -- ;
break;
}
V_72 = & V_22 -> V_72 [ V_105 -> V_336 [ 0 ] ] ;
case V_182 :
V_22 -> V_35 = V_342 ;
if ( ! V_72 )
V_72 = & V_22 -> V_72 [ V_22 -> V_32 ] ;
if ( F_19 ( V_343 , & V_22 -> V_38 ) )
break;
F_21 ( ! F_19 ( V_177 , & V_72 -> V_60 ) ) ;
F_21 ( V_105 -> V_252 != V_25 ) ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
V_105 -> V_312 ++ ;
F_72 ( V_110 , & V_72 -> V_60 ) ;
F_24 ( V_153 , & V_22 -> V_38 ) ;
F_72 ( V_343 , & V_22 -> V_38 ) ;
break;
case V_225 :
break;
case V_211 :
V_22 -> V_35 = V_342 ;
if ( V_105 -> V_337 )
break;
if ( ( V_22 -> V_179 . V_212 & V_344 ) == 0 )
F_72 ( V_343 , & V_22 -> V_38 ) ;
else {
V_3 -> V_51 -> V_345 += V_14 ;
if ( F_19 ( V_346 , & V_3 -> V_51 -> V_269 ) )
F_72 ( V_343 , & V_22 -> V_38 ) ;
else {
V_22 -> V_35 = V_181 ;
F_72 ( V_39 , & V_22 -> V_38 ) ;
F_72 ( V_220 , & V_105 -> V_215 ) ;
F_72 ( V_178 ,
& V_22 -> V_72 [ V_22 -> V_32 ] . V_60 ) ;
V_22 -> V_179 . V_175 = V_22 -> V_32 ;
V_22 -> V_179 . V_180 = - 1 ;
V_105 -> V_252 ++ ;
}
}
break;
case V_181 :
break;
default:
F_51 ( V_83 L_44 ,
V_140 , V_22 -> V_35 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_64 () ;
}
}
static void F_173 ( struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_104 * V_105 ,
int V_25 )
{
int V_32 = V_22 -> V_32 ;
int V_24 = V_22 -> V_24 ;
struct V_77 * V_72 ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
F_21 ( V_105 -> V_337 > 2 ) ;
switch ( V_22 -> V_35 ) {
case V_342 :
if ( V_105 -> V_337 == V_105 -> V_347 ) {
V_22 -> V_35 = V_225 ;
}
if ( ! V_105 -> V_347 && V_105 -> V_337 < 2 ) {
if ( V_22 -> V_35 == V_225 )
V_22 -> V_35 = V_227 ;
else
V_22 -> V_35 = V_226 ;
}
V_22 -> V_179 . V_212 = 0 ;
if ( V_22 -> V_35 == V_225 ) {
F_24 ( V_177 , & V_22 -> V_72 [ V_32 ] . V_60 ) ;
V_105 -> V_252 -- ;
}
if ( V_22 -> V_35 >= V_225 &&
V_22 -> V_35 <= V_227 ) {
F_72 ( V_224 , & V_105 -> V_215 ) ;
break;
}
F_21 ( V_105 -> V_337 != 2 ) ;
case V_182 :
V_22 -> V_35 = V_342 ;
if ( F_19 ( V_343 , & V_22 -> V_38 ) )
break;
F_21 ( V_105 -> V_252 < V_25 - 1 ) ;
if ( V_105 -> V_337 == 2 ) {
V_72 = & V_22 -> V_72 [ V_105 -> V_336 [ 1 ] ] ;
V_105 -> V_312 ++ ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_72 ( V_110 , & V_72 -> V_60 ) ;
}
if ( V_105 -> V_337 >= 1 ) {
V_72 = & V_22 -> V_72 [ V_105 -> V_336 [ 0 ] ] ;
V_105 -> V_312 ++ ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_72 ( V_110 , & V_72 -> V_60 ) ;
}
if ( V_22 -> V_179 . V_212 & V_344 ) {
V_72 = & V_22 -> V_72 [ V_32 ] ;
V_105 -> V_312 ++ ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_72 ( V_110 , & V_72 -> V_60 ) ;
}
if ( V_22 -> V_179 . V_212 & V_348 ) {
V_72 = & V_22 -> V_72 [ V_24 ] ;
V_105 -> V_312 ++ ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_72 ( V_110 , & V_72 -> V_60 ) ;
}
F_24 ( V_153 , & V_22 -> V_38 ) ;
F_72 ( V_343 , & V_22 -> V_38 ) ;
break;
case V_225 :
case V_226 :
case V_227 :
break;
case V_211 :
V_22 -> V_35 = V_342 ;
if ( V_22 -> V_179 . V_212 == 0 ) {
if ( ! V_105 -> V_337 )
F_72 ( V_343 , & V_22 -> V_38 ) ;
else {
V_22 -> V_35 = V_182 ;
}
} else {
V_3 -> V_51 -> V_345 += V_14 ;
if ( F_19 ( V_346 , & V_3 -> V_51 -> V_269 ) )
F_72 ( V_343 , & V_22 -> V_38 ) ;
else {
int * V_175 = & V_22 -> V_179 . V_175 ;
V_22 -> V_179 . V_175 = - 1 ;
V_22 -> V_179 . V_180 = - 1 ;
V_22 -> V_35 = V_181 ;
F_72 ( V_39 , & V_22 -> V_38 ) ;
F_72 ( V_220 , & V_105 -> V_215 ) ;
if ( V_22 -> V_179 . V_212 & V_344 ) {
F_72 ( V_178 ,
& V_22 -> V_72 [ V_32 ] . V_60 ) ;
* V_175 = V_32 ;
V_175 = & V_22 -> V_179 . V_180 ;
V_105 -> V_252 ++ ;
}
if ( V_22 -> V_179 . V_212 & V_348 ) {
F_72 ( V_178 ,
& V_22 -> V_72 [ V_24 ] . V_60 ) ;
* V_175 = V_24 ;
V_105 -> V_252 ++ ;
}
}
}
break;
case V_181 :
break;
default:
F_51 ( V_83 L_44 ,
V_140 , V_22 -> V_35 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_64 () ;
}
}
static void F_174 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
int V_69 ;
struct V_154 * V_156 = NULL ;
F_24 ( V_349 , & V_22 -> V_38 ) ;
for ( V_69 = 0 ; V_69 < V_22 -> V_25 ; V_69 ++ )
if ( V_69 != V_22 -> V_32 && V_69 != V_22 -> V_24 ) {
int V_281 , V_350 ;
struct V_21 * V_309 ;
struct V_161 V_162 ;
T_1 V_351 = F_154 ( V_22 , V_69 , 1 ) ;
T_1 V_105 = F_157 ( V_3 , V_351 , 0 ,
& V_281 , NULL ) ;
V_309 = F_61 ( V_3 , V_105 , 0 , 1 , 1 ) ;
if ( V_309 == NULL )
continue;
if ( ! F_19 ( V_55 , & V_309 -> V_38 ) ||
F_19 ( V_352 , & V_309 -> V_72 [ V_281 ] . V_60 ) ) {
F_32 ( V_309 ) ;
continue;
}
F_79 ( & V_162 , 0 , V_156 , NULL , NULL , NULL ) ;
V_156 = F_81 ( V_309 -> V_72 [ V_281 ] . V_67 ,
V_22 -> V_72 [ V_69 ] . V_67 , 0 , 0 , V_150 ,
& V_162 ) ;
F_72 ( V_352 , & V_309 -> V_72 [ V_281 ] . V_60 ) ;
F_72 ( V_177 , & V_309 -> V_72 [ V_281 ] . V_60 ) ;
for ( V_350 = 0 ; V_350 < V_3 -> V_27 ; V_350 ++ )
if ( V_350 != V_309 -> V_32 &&
V_350 != V_309 -> V_24 &&
! F_19 ( V_352 , & V_309 -> V_72 [ V_350 ] . V_60 ) )
break;
if ( V_350 == V_3 -> V_27 ) {
F_72 ( V_353 , & V_309 -> V_38 ) ;
F_72 ( V_42 , & V_309 -> V_38 ) ;
}
F_32 ( V_309 ) ;
}
if ( V_156 ) {
F_112 ( V_156 ) ;
F_175 ( V_156 ) ;
}
}
static void F_176 ( struct V_21 * V_22 , struct V_104 * V_105 )
{
struct V_2 * V_3 = V_22 -> V_59 ;
int V_25 = V_22 -> V_25 ;
struct V_77 * V_72 ;
int V_69 ;
int V_354 = 0 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_134 = F_19 ( V_349 , & V_22 -> V_38 ) ;
V_105 -> V_135 = F_19 ( V_353 , & V_22 -> V_38 ) ;
V_105 -> V_336 [ 0 ] = - 1 ;
V_105 -> V_336 [ 1 ] = - 1 ;
F_57 () ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_88 * V_89 ;
T_1 V_128 ;
int V_129 ;
int V_355 = 0 ;
V_72 = & V_22 -> V_72 [ V_69 ] ;
F_38 ( L_45 ,
V_69 , V_72 -> V_60 ,
V_72 -> V_78 , V_72 -> V_80 , V_72 -> V_81 ) ;
if ( F_19 ( V_177 , & V_72 -> V_60 ) && V_72 -> V_78 &&
! F_19 ( V_37 , & V_22 -> V_38 ) )
F_72 ( V_171 , & V_72 -> V_60 ) ;
if ( F_19 ( V_82 , & V_72 -> V_60 ) )
V_105 -> V_312 ++ ;
if ( F_19 ( V_177 , & V_72 -> V_60 ) )
V_105 -> V_252 ++ ;
if ( F_19 ( V_178 , & V_72 -> V_60 ) ) {
V_105 -> V_356 ++ ;
F_21 ( V_105 -> V_356 > 2 ) ;
}
if ( F_19 ( V_171 , & V_72 -> V_60 ) )
V_105 -> V_357 ++ ;
else if ( V_72 -> V_78 )
V_105 -> V_327 ++ ;
if ( V_72 -> V_80 ) {
V_105 -> V_323 ++ ;
if ( ! F_19 ( V_319 , & V_72 -> V_60 ) )
V_105 -> V_358 ++ ;
}
if ( V_72 -> V_81 )
V_105 -> V_81 ++ ;
V_89 = F_58 ( V_3 -> V_25 [ V_69 ] . V_91 ) ;
if ( V_89 && ! F_19 ( V_90 , & V_89 -> V_60 ) &&
V_89 -> V_333 >= V_22 -> V_10 + V_14 &&
! F_71 ( V_89 , V_22 -> V_10 , V_14 ,
& V_128 , & V_129 ) )
F_72 ( V_125 , & V_72 -> V_60 ) ;
else {
if ( V_89 )
F_72 ( V_359 , & V_72 -> V_60 ) ;
V_89 = F_58 ( V_3 -> V_25 [ V_69 ] . V_89 ) ;
F_24 ( V_125 , & V_72 -> V_60 ) ;
}
if ( V_89 && F_19 ( V_90 , & V_89 -> V_60 ) )
V_89 = NULL ;
if ( V_89 ) {
V_355 = F_71 ( V_89 , V_22 -> V_10 , V_14 ,
& V_128 , & V_129 ) ;
if ( V_105 -> V_360 == NULL
&& ( F_19 ( V_277 , & V_89 -> V_60 )
|| V_355 < 0 ) ) {
if ( V_355 < 0 )
F_72 ( V_131 ,
& V_89 -> V_60 ) ;
V_105 -> V_360 = V_89 ;
F_8 ( & V_89 -> V_126 ) ;
}
}
F_24 ( V_326 , & V_72 -> V_60 ) ;
if ( ! V_89 )
;
else if ( V_355 ) {
if ( ! F_19 ( V_127 , & V_89 -> V_60 ) &&
F_19 ( V_177 , & V_72 -> V_60 ) ) {
F_72 ( V_326 , & V_72 -> V_60 ) ;
F_72 ( V_255 , & V_72 -> V_60 ) ;
}
} else if ( F_19 ( V_92 , & V_89 -> V_60 ) )
F_72 ( V_326 , & V_72 -> V_60 ) ;
else if ( V_22 -> V_10 + V_14 <= V_89 -> V_333 )
F_72 ( V_326 , & V_72 -> V_60 ) ;
else if ( F_19 ( V_177 , & V_72 -> V_60 ) &&
F_19 ( V_352 , & V_72 -> V_60 ) )
F_72 ( V_326 , & V_72 -> V_60 ) ;
if ( V_89 && F_19 ( V_266 , & V_72 -> V_60 ) ) {
struct V_88 * V_361 = F_58 (
V_3 -> V_25 [ V_69 ] . V_89 ) ;
if ( V_361 == V_89 )
F_24 ( V_326 , & V_72 -> V_60 ) ;
if ( V_361 && ! F_19 ( V_90 , & V_361 -> V_60 ) ) {
V_105 -> V_362 = 1 ;
F_8 ( & V_361 -> V_126 ) ;
} else
F_24 ( V_266 , & V_72 -> V_60 ) ;
}
if ( V_89 && F_19 ( V_270 , & V_72 -> V_60 ) ) {
struct V_88 * V_361 = F_58 (
V_3 -> V_25 [ V_69 ] . V_89 ) ;
if ( V_361 && ! F_19 ( V_90 , & V_361 -> V_60 ) ) {
V_105 -> V_362 = 1 ;
F_8 ( & V_361 -> V_126 ) ;
} else
F_24 ( V_270 , & V_72 -> V_60 ) ;
}
if ( F_19 ( V_265 , & V_72 -> V_60 ) ) {
struct V_88 * V_361 = F_58 (
V_3 -> V_25 [ V_69 ] . V_91 ) ;
if ( V_361 && ! F_19 ( V_90 , & V_361 -> V_60 ) ) {
V_105 -> V_362 = 1 ;
F_8 ( & V_361 -> V_126 ) ;
} else
F_24 ( V_265 , & V_72 -> V_60 ) ;
}
if ( ! F_19 ( V_326 , & V_72 -> V_60 ) ) {
F_24 ( V_255 , & V_72 -> V_60 ) ;
F_24 ( V_258 , & V_72 -> V_60 ) ;
}
if ( F_19 ( V_255 , & V_72 -> V_60 ) )
F_24 ( V_326 , & V_72 -> V_60 ) ;
if ( ! F_19 ( V_326 , & V_72 -> V_60 ) ) {
if ( V_105 -> V_337 < 2 )
V_105 -> V_336 [ V_105 -> V_337 ] = V_69 ;
V_105 -> V_337 ++ ;
if ( V_89 && ! F_19 ( V_90 , & V_89 -> V_60 ) )
V_354 = 1 ;
}
}
if ( F_19 ( V_328 , & V_22 -> V_38 ) ) {
if ( V_354 ||
V_22 -> V_10 >= V_3 -> V_51 -> V_334 ||
F_19 ( V_363 , & ( V_3 -> V_51 -> V_269 ) ) )
V_105 -> V_133 = 1 ;
else
V_105 -> V_136 = 1 ;
}
F_59 () ;
}
static void F_177 ( struct V_21 * V_22 )
{
struct V_104 V_105 ;
struct V_2 * V_3 = V_22 -> V_59 ;
int V_69 ;
int V_210 ;
int V_25 = V_22 -> V_25 ;
struct V_77 * V_364 , * V_365 ;
F_24 ( V_42 , & V_22 -> V_38 ) ;
if ( F_118 ( V_366 , & V_22 -> V_38 ) ) {
F_72 ( V_42 , & V_22 -> V_38 ) ;
return;
}
if ( F_26 ( V_367 , & V_22 -> V_38 ) ) {
F_72 ( V_328 , & V_22 -> V_38 ) ;
F_24 ( V_343 , & V_22 -> V_38 ) ;
}
F_24 ( V_43 , & V_22 -> V_38 ) ;
F_38 ( L_46
L_47 ,
( unsigned long long ) V_22 -> V_10 , V_22 -> V_38 ,
F_4 ( & V_22 -> V_29 ) , V_22 -> V_32 , V_22 -> V_24 ,
V_22 -> V_35 , V_22 -> V_36 ) ;
F_176 ( V_22 , & V_105 ) ;
if ( V_105 . V_362 ) {
F_72 ( V_42 , & V_22 -> V_38 ) ;
goto V_368;
}
if ( F_89 ( V_105 . V_360 ) ) {
if ( V_105 . V_133 || V_105 . V_134 || V_105 . V_135 ||
V_105 . V_136 || V_105 . V_323 || V_105 . V_81 ) {
F_72 ( V_42 , & V_22 -> V_38 ) ;
goto V_368;
}
F_75 ( V_105 . V_360 , V_3 -> V_51 ) ;
V_105 . V_360 = NULL ;
}
if ( V_105 . V_357 && ! F_19 ( V_37 , & V_22 -> V_38 ) ) {
F_72 ( V_219 , & V_105 . V_215 ) ;
F_72 ( V_37 , & V_22 -> V_38 ) ;
}
F_38 ( L_48
L_49 ,
V_105 . V_312 , V_105 . V_252 , V_105 . V_327 , V_105 . V_323 , V_105 . V_337 ,
V_105 . V_336 [ 0 ] , V_105 . V_336 [ 1 ] ) ;
if ( V_105 . V_337 > V_3 -> V_95 ) {
V_22 -> V_35 = 0 ;
V_22 -> V_36 = 0 ;
if ( V_105 . V_327 + V_105 . V_323 + V_105 . V_81 )
F_162 ( V_3 , V_22 , & V_105 , V_25 , & V_105 . V_33 ) ;
if ( V_105 . V_133 + V_105 . V_136 )
F_165 ( V_3 , V_22 , & V_105 ) ;
}
V_364 = & V_22 -> V_72 [ V_22 -> V_32 ] ;
V_105 . V_369 = ( V_105 . V_337 >= 1 && V_105 . V_336 [ 0 ] == V_22 -> V_32 )
|| ( V_105 . V_337 >= 2 && V_105 . V_336 [ 1 ] == V_22 -> V_32 ) ;
V_365 = & V_22 -> V_72 [ V_22 -> V_24 ] ;
V_105 . V_347 = ( V_105 . V_337 >= 1 && V_105 . V_336 [ 0 ] == V_22 -> V_24 )
|| ( V_105 . V_337 >= 2 && V_105 . V_336 [ 1 ] == V_22 -> V_24 )
|| V_3 -> V_217 < 6 ;
if ( V_105 . V_81 &&
( V_105 . V_369 || ( ( F_19 ( V_326 , & V_364 -> V_60 )
&& ! F_19 ( V_82 , & V_364 -> V_60 )
&& F_19 ( V_177 , & V_364 -> V_60 ) ) ) ) &&
( V_105 . V_347 || ( ( F_19 ( V_326 , & V_365 -> V_60 )
&& ! F_19 ( V_82 , & V_365 -> V_60 )
&& F_19 ( V_177 , & V_365 -> V_60 ) ) ) ) )
F_170 ( V_3 , V_22 , V_25 , & V_105 . V_33 ) ;
if ( V_105 . V_327 || V_105 . V_358
|| ( V_3 -> V_217 == 6 && V_105 . V_323 && V_105 . V_337 )
|| ( V_105 . V_133 && ( V_105 . V_252 + V_105 . V_356 < V_25 ) )
|| V_105 . V_136
|| V_105 . V_134 )
F_169 ( V_22 , & V_105 , V_25 ) ;
V_210 = 0 ;
if ( V_22 -> V_36 == V_207 )
V_210 = 1 ;
if ( V_22 -> V_36 == V_205 ||
V_22 -> V_36 == V_207 ) {
V_22 -> V_36 = V_370 ;
F_21 ( ! F_19 ( V_177 , & V_22 -> V_72 [ V_22 -> V_32 ] . V_60 ) ) ;
F_21 ( V_22 -> V_24 >= 0 &&
! F_19 ( V_177 , & V_22 -> V_72 [ V_22 -> V_24 ] . V_60 ) ) ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( F_19 ( V_82 , & V_72 -> V_60 ) &&
( V_69 == V_22 -> V_32 || V_69 == V_22 -> V_24 ||
V_72 -> V_81 ) ) {
F_38 ( L_50 , V_69 ) ;
F_72 ( V_110 , & V_72 -> V_60 ) ;
if ( V_210 )
continue;
if ( ! F_19 ( V_326 , & V_72 -> V_60 ) ||
( ( V_69 == V_22 -> V_32 || V_69 == V_22 -> V_24 ) &&
V_105 . V_337 == 0 ) )
F_72 ( V_343 , & V_22 -> V_38 ) ;
}
}
if ( F_26 ( V_44 , & V_22 -> V_38 ) )
V_105 . V_371 = 1 ;
}
if ( V_105 . V_323 && ! V_22 -> V_36 && ! V_22 -> V_35 )
F_171 ( V_3 , V_22 , & V_105 , V_25 ) ;
if ( V_22 -> V_35 ||
( V_105 . V_133 && V_105 . V_312 == 0 &&
! F_19 ( V_39 , & V_22 -> V_38 ) &&
! F_19 ( V_343 , & V_22 -> V_38 ) ) ) {
if ( V_3 -> V_217 == 6 )
F_173 ( V_3 , V_22 , & V_105 , V_25 ) ;
else
F_172 ( V_3 , V_22 , & V_105 , V_25 ) ;
}
if ( V_105 . V_136 && V_105 . V_312 == 0
&& ! F_19 ( V_343 , & V_22 -> V_38 ) ) {
for ( V_69 = 0 ; V_69 < V_3 -> V_27 ; V_69 ++ )
if ( F_19 ( V_177 , & V_22 -> V_72 [ V_69 ] . V_60 ) &&
F_19 ( V_359 , & V_22 -> V_72 [ V_69 ] . V_60 ) ) {
F_72 ( V_116 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_72 ( V_82 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
V_105 . V_312 ++ ;
}
F_72 ( V_343 , & V_22 -> V_38 ) ;
}
if ( ( V_105 . V_133 || V_105 . V_136 ) && V_105 . V_312 == 0 &&
F_19 ( V_343 , & V_22 -> V_38 ) ) {
F_166 ( V_3 -> V_51 , V_14 , 1 ) ;
F_24 ( V_328 , & V_22 -> V_38 ) ;
}
if ( V_105 . V_337 <= V_3 -> V_95 && ! V_3 -> V_51 -> V_372 )
for ( V_69 = 0 ; V_69 < V_105 . V_337 ; V_69 ++ ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_105 . V_336 [ V_69 ] ] ;
if ( F_19 ( V_255 , & V_72 -> V_60 )
&& ! F_19 ( V_82 , & V_72 -> V_60 )
&& F_19 ( V_177 , & V_72 -> V_60 )
) {
if ( ! F_19 ( V_258 , & V_72 -> V_60 ) ) {
F_72 ( V_110 , & V_72 -> V_60 ) ;
F_72 ( V_258 , & V_72 -> V_60 ) ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
V_105 . V_312 ++ ;
} else {
F_72 ( V_114 , & V_72 -> V_60 ) ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
V_105 . V_312 ++ ;
}
}
}
if ( V_22 -> V_36 == V_209 ) {
struct V_21 * V_373
= F_61 ( V_3 , V_22 -> V_10 , 1 , 1 , 1 ) ;
if ( V_373 && F_19 ( V_349 , & V_373 -> V_38 ) ) {
F_72 ( V_43 , & V_22 -> V_38 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
if ( ! F_152 ( V_44 ,
& V_373 -> V_38 ) )
F_8 ( & V_3 -> V_53 ) ;
F_32 ( V_373 ) ;
goto V_368;
}
if ( V_373 )
F_32 ( V_373 ) ;
V_22 -> V_36 = V_370 ;
F_24 ( V_55 , & V_22 -> V_38 ) ;
for ( V_69 = V_3 -> V_27 ; V_69 -- ; ) {
F_72 ( V_110 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_72 ( V_82 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
V_105 . V_312 ++ ;
}
}
if ( V_105 . V_135 && F_19 ( V_55 , & V_22 -> V_38 ) &&
! V_22 -> V_36 ) {
V_22 -> V_25 = V_3 -> V_27 ;
F_50 ( V_22 -> V_10 , V_3 , 0 , V_22 ) ;
F_159 ( V_22 , & V_105 , 1 , 1 ) ;
} else if ( V_105 . V_135 && ! V_22 -> V_36 && V_105 . V_312 == 0 ) {
F_24 ( V_353 , & V_22 -> V_38 ) ;
F_28 ( & V_3 -> V_374 ) ;
F_29 ( & V_3 -> V_229 ) ;
F_166 ( V_3 -> V_51 , V_14 , 1 ) ;
}
if ( V_105 . V_134 && V_105 . V_312 == 0 &&
! F_19 ( V_39 , & V_22 -> V_38 ) )
F_174 ( V_3 , V_22 ) ;
V_368:
if ( F_89 ( V_105 . V_360 ) ) {
if ( V_3 -> V_51 -> V_132 )
F_74 ( V_105 . V_360 ,
V_3 -> V_51 ) ;
else
F_75 ( V_105 . V_360 ,
V_3 -> V_51 ) ;
}
if ( V_105 . V_362 )
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_88 * V_89 ;
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( F_26 ( V_266 , & V_72 -> V_60 ) ) {
V_89 = V_3 -> V_25 [ V_69 ] . V_89 ;
if ( ! F_150 ( V_89 , V_22 -> V_10 ,
V_14 , 0 ) )
F_151 ( V_3 -> V_51 , V_89 ) ;
F_75 ( V_89 , V_3 -> V_51 ) ;
}
if ( F_26 ( V_270 , & V_72 -> V_60 ) ) {
V_89 = V_3 -> V_25 [ V_69 ] . V_89 ;
F_178 ( V_89 , V_22 -> V_10 ,
V_14 , 0 ) ;
F_75 ( V_89 , V_3 -> V_51 ) ;
}
if ( F_26 ( V_265 , & V_72 -> V_60 ) ) {
V_89 = V_3 -> V_25 [ V_69 ] . V_91 ;
if ( ! V_89 )
V_89 = V_3 -> V_25 [ V_69 ] . V_89 ;
F_178 ( V_89 , V_22 -> V_10 ,
V_14 , 0 ) ;
F_75 ( V_89 , V_3 -> V_51 ) ;
}
}
if ( V_105 . V_215 )
F_116 ( V_22 , V_105 . V_215 ) ;
F_68 ( V_22 , & V_105 ) ;
if ( V_105 . V_371 ) {
F_28 ( & V_3 -> V_53 ) ;
if ( F_4 ( & V_3 -> V_53 ) <
V_54 )
F_25 ( V_3 -> V_51 -> V_52 ) ;
}
F_16 ( V_105 . V_33 ) ;
F_115 ( V_366 , & V_22 -> V_38 ) ;
}
static void F_179 ( struct V_2 * V_3 )
{
if ( F_4 ( & V_3 -> V_53 ) < V_54 ) {
while ( ! F_22 ( & V_3 -> V_45 ) ) {
struct V_63 * V_375 = V_3 -> V_45 . V_66 ;
struct V_21 * V_22 ;
V_22 = F_43 ( V_375 , struct V_21 , V_40 ) ;
F_44 ( V_375 ) ;
F_24 ( V_43 , & V_22 -> V_38 ) ;
if ( ! F_152 ( V_44 , & V_22 -> V_38 ) )
F_8 ( & V_3 -> V_53 ) ;
F_23 ( & V_22 -> V_40 , & V_3 -> V_376 ) ;
}
}
}
static void F_180 ( struct V_2 * V_3 )
{
struct V_63 V_377 ;
F_135 ( & V_377 , & V_3 -> V_49 ) ;
F_44 ( & V_3 -> V_49 ) ;
while ( ! F_22 ( & V_377 ) ) {
struct V_21 * V_22 = F_43 ( V_377 . V_66 , struct V_21 , V_40 ) ;
F_44 ( & V_22 -> V_40 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_30 ( V_3 , V_22 ) ;
}
}
int F_181 ( struct V_51 * V_51 , int V_378 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
if ( V_3 -> V_99 )
return 1 ;
if ( V_3 -> V_98 )
return 1 ;
if ( F_182 ( & V_3 -> V_56 ) )
return 1 ;
return 0 ;
}
static int F_183 ( void * V_379 , int V_378 )
{
struct V_51 * V_51 = V_379 ;
return F_184 ( V_51 , V_378 ) ||
F_181 ( V_51 , V_378 ) ;
}
static int F_185 ( struct V_380 * V_381 ,
struct V_382 * V_383 ,
struct V_157 * V_384 )
{
struct V_51 * V_51 = V_381 -> V_385 ;
T_1 V_10 = V_383 -> V_13 + F_186 ( V_383 -> V_139 ) ;
int F_128 ;
unsigned int V_291 = V_51 -> V_291 ;
unsigned int V_386 = V_383 -> V_12 >> 9 ;
if ( ( V_383 -> V_121 & 1 ) == V_113 )
return V_384 -> V_149 ;
if ( V_51 -> V_387 < V_51 -> V_291 )
V_291 = V_51 -> V_387 ;
F_128 = ( V_291 - ( ( V_10 & ( V_291 - 1 ) ) + V_386 ) ) << 9 ;
if ( F_128 < 0 ) F_128 = 0 ;
if ( F_128 <= V_384 -> V_149 && V_386 == 0 )
return V_384 -> V_149 ;
else
return F_128 ;
}
static int F_187 ( struct V_51 * V_51 , struct V_9 * V_9 )
{
T_1 V_10 = V_9 -> V_13 + F_186 ( V_9 -> V_139 ) ;
unsigned int V_291 = V_51 -> V_291 ;
unsigned int V_386 = V_9 -> V_12 >> 9 ;
if ( V_51 -> V_387 < V_51 -> V_291 )
V_291 = V_51 -> V_387 ;
return V_291 >=
( ( V_10 & ( V_291 - 1 ) ) + V_386 ) ;
}
static void F_188 ( struct V_9 * V_34 , struct V_2 * V_3 )
{
unsigned long V_60 ;
F_155 ( & V_3 -> V_61 , V_60 ) ;
V_34 -> V_15 = V_3 -> V_388 ;
V_3 -> V_388 = V_34 ;
F_156 ( & V_3 -> V_61 , V_60 ) ;
F_25 ( V_3 -> V_51 -> V_52 ) ;
}
static struct V_9 * F_189 ( struct V_2 * V_3 )
{
struct V_9 * V_34 ;
V_34 = V_3 -> V_58 ;
if ( V_34 ) {
V_3 -> V_58 = NULL ;
return V_34 ;
}
V_34 = V_3 -> V_388 ;
if( V_34 ) {
V_3 -> V_388 = V_34 -> V_15 ;
V_34 -> V_15 = NULL ;
F_11 ( V_34 , 1 ) ;
}
return V_34 ;
}
static void F_190 ( struct V_9 * V_34 , int error )
{
struct V_9 * V_389 = V_34 -> V_251 ;
struct V_51 * V_51 ;
struct V_2 * V_3 ;
int V_252 = F_19 ( V_146 , & V_34 -> V_145 ) ;
struct V_88 * V_89 ;
F_191 ( V_34 ) ;
V_89 = ( void * ) V_389 -> V_15 ;
V_389 -> V_15 = NULL ;
V_51 = V_89 -> V_51 ;
V_3 = V_51 -> V_275 ;
F_75 ( V_89 , V_3 -> V_51 ) ;
if ( ! error && V_252 ) {
F_17 ( V_389 , 0 ) ;
if ( F_31 ( & V_3 -> V_390 ) )
F_29 ( & V_3 -> V_57 ) ;
return;
}
F_38 ( L_51 ) ;
F_188 ( V_389 , V_3 ) ;
}
static int F_192 ( struct V_9 * V_34 )
{
struct V_380 * V_381 = F_193 ( V_34 -> V_139 ) ;
if ( ( V_34 -> V_12 >> 9 ) > F_194 ( V_381 ) )
return 0 ;
F_195 ( V_381 , V_34 ) ;
if ( V_34 -> V_17 > F_196 ( V_381 ) )
return 0 ;
if ( V_381 -> V_391 )
return 0 ;
return 1 ;
}
static int F_197 ( struct V_51 * V_51 , struct V_9 * V_392 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
int V_281 ;
struct V_9 * V_393 ;
struct V_88 * V_89 ;
T_1 V_394 ;
if ( ! F_187 ( V_51 , V_392 ) ) {
F_38 ( L_52 ) ;
return 0 ;
}
V_393 = F_198 ( V_392 , V_250 , V_51 ) ;
if ( ! V_393 )
return 0 ;
V_393 -> V_122 = F_190 ;
V_393 -> V_251 = V_392 ;
V_393 -> V_13 = F_157 ( V_3 , V_392 -> V_13 ,
0 ,
& V_281 , NULL ) ;
V_394 = V_393 -> V_13 + ( V_393 -> V_12 >> 9 ) ;
F_57 () ;
V_89 = F_58 ( V_3 -> V_25 [ V_281 ] . V_91 ) ;
if ( ! V_89 || F_19 ( V_90 , & V_89 -> V_60 ) ||
V_89 -> V_333 < V_394 ) {
V_89 = F_58 ( V_3 -> V_25 [ V_281 ] . V_89 ) ;
if ( V_89 &&
( F_19 ( V_90 , & V_89 -> V_60 ) ||
! ( F_19 ( V_92 , & V_89 -> V_60 ) ||
V_89 -> V_333 >= V_394 ) ) )
V_89 = NULL ;
}
if ( V_89 ) {
T_1 V_128 ;
int V_129 ;
F_8 ( & V_89 -> V_126 ) ;
F_59 () ;
V_392 -> V_15 = ( void * ) V_89 ;
V_393 -> V_139 = V_89 -> V_137 ;
V_393 -> V_145 &= ~ ( 1 << V_395 ) ;
if ( ! F_192 ( V_393 ) ||
F_71 ( V_89 , V_393 -> V_13 , V_393 -> V_12 >> 9 ,
& V_128 , & V_129 ) ) {
F_191 ( V_393 ) ;
F_75 ( V_89 , V_51 ) ;
return 0 ;
}
V_393 -> V_13 += V_89 -> V_142 ;
F_62 ( & V_3 -> V_61 ) ;
F_63 ( V_3 -> V_57 ,
V_3 -> V_98 == 0 ,
V_3 -> V_61 , ) ;
F_8 ( & V_3 -> V_390 ) ;
F_65 ( & V_3 -> V_61 ) ;
F_77 ( V_393 ) ;
return 1 ;
} else {
F_59 () ;
F_191 ( V_393 ) ;
return 0 ;
}
}
static struct V_21 * F_199 ( struct V_2 * V_3 )
{
struct V_21 * V_22 ;
F_38 ( L_53 ,
V_140 ,
F_22 ( & V_3 -> V_50 ) ? L_54 : L_55 ,
F_22 ( & V_3 -> V_376 ) ? L_54 : L_55 ,
F_4 ( & V_3 -> V_314 ) , V_3 -> V_396 ) ;
if ( ! F_22 ( & V_3 -> V_50 ) ) {
V_22 = F_43 ( V_3 -> V_50 . V_66 , F_200 ( * V_22 ) , V_40 ) ;
if ( F_22 ( & V_3 -> V_376 ) )
V_3 -> V_396 = 0 ;
else if ( ! F_19 ( V_138 , & V_22 -> V_38 ) ) {
if ( V_3 -> V_376 . V_66 == V_3 -> V_397 )
V_3 -> V_396 ++ ;
else {
V_3 -> V_397 = V_3 -> V_376 . V_66 ;
V_3 -> V_396 -= V_3 -> V_398 ;
if ( V_3 -> V_396 < 0 )
V_3 -> V_396 = 0 ;
}
}
} else if ( ! F_22 ( & V_3 -> V_376 ) &&
( ( V_3 -> V_398 &&
V_3 -> V_396 > V_3 -> V_398 ) ||
F_4 ( & V_3 -> V_314 ) == 0 ) ) {
V_22 = F_43 ( V_3 -> V_376 . V_66 ,
F_200 ( * V_22 ) , V_40 ) ;
V_3 -> V_396 -= V_3 -> V_398 ;
if ( V_3 -> V_396 < 0 )
V_3 -> V_396 = 0 ;
} else
return NULL ;
F_44 ( & V_22 -> V_40 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_21 ( F_4 ( & V_22 -> V_29 ) != 1 ) ;
return V_22 ;
}
static void F_201 ( struct V_399 * V_400 , bool V_401 )
{
struct V_402 * V_403 = F_202 (
V_400 , struct V_402 , V_403 ) ;
struct V_21 * V_22 ;
struct V_51 * V_51 = V_403 -> V_403 . V_379 ;
struct V_2 * V_3 = V_51 -> V_275 ;
if ( V_403 -> V_404 . V_66 && ! F_22 ( & V_403 -> V_404 ) ) {
F_62 ( & V_3 -> V_61 ) ;
while ( ! F_22 ( & V_403 -> V_404 ) ) {
V_22 = F_203 ( & V_403 -> V_404 , struct V_21 , V_40 ) ;
F_44 ( & V_22 -> V_40 ) ;
F_204 () ;
F_24 ( V_101 , & V_22 -> V_38 ) ;
F_30 ( V_3 , V_22 ) ;
}
F_65 ( & V_3 -> V_61 ) ;
}
F_140 ( V_403 ) ;
}
static void F_205 ( struct V_51 * V_51 ,
struct V_21 * V_22 )
{
struct V_399 * V_400 = F_206 (
F_201 , V_51 ,
sizeof( struct V_402 ) ) ;
struct V_402 * V_403 ;
if ( ! V_400 ) {
F_32 ( V_22 ) ;
return;
}
V_403 = F_202 ( V_400 , struct V_402 , V_403 ) ;
if ( V_403 -> V_404 . V_66 == NULL )
F_126 ( & V_403 -> V_404 ) ;
if ( ! F_152 ( V_101 , & V_22 -> V_38 ) )
F_23 ( & V_22 -> V_40 , & V_403 -> V_404 ) ;
else
F_32 ( V_22 ) ;
}
static void F_207 ( struct V_51 * V_51 , struct V_9 * V_34 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
int V_281 ;
T_1 V_286 ;
T_1 V_405 , V_406 ;
struct V_21 * V_22 ;
const int V_106 = F_208 ( V_34 ) ;
int V_407 ;
if ( F_89 ( V_34 -> V_121 & V_144 ) ) {
F_209 ( V_51 , V_34 ) ;
return;
}
F_210 ( V_51 , V_34 ) ;
if ( V_106 == V_115 &&
V_51 -> V_93 == V_94 &&
F_197 ( V_51 , V_34 ) )
return;
V_405 = V_34 -> V_13 & ~ ( ( T_1 ) V_14 - 1 ) ;
V_406 = V_34 -> V_13 + ( V_34 -> V_12 >> 9 ) ;
V_34 -> V_15 = NULL ;
V_34 -> V_17 = 1 ;
for (; V_405 < V_406 ; V_405 += V_14 ) {
F_211 ( V_408 ) ;
int V_74 ;
V_261:
V_74 = 0 ;
F_212 ( & V_3 -> V_229 , & V_408 , V_409 ) ;
if ( F_89 ( V_3 -> V_103 != V_94 ) ) {
F_62 ( & V_3 -> V_61 ) ;
if ( V_51 -> V_410
? V_405 < V_3 -> V_103
: V_405 >= V_3 -> V_103 ) {
V_74 = 1 ;
} else {
if ( V_51 -> V_410
? V_405 < V_3 -> V_411
: V_405 >= V_3 -> V_411 ) {
F_65 ( & V_3 -> V_61 ) ;
F_213 () ;
goto V_261;
}
}
F_65 ( & V_3 -> V_61 ) ;
}
V_286 = F_157 ( V_3 , V_405 ,
V_74 ,
& V_281 , NULL ) ;
F_38 ( L_56 ,
( unsigned long long ) V_286 ,
( unsigned long long ) V_405 ) ;
V_22 = F_61 ( V_3 , V_286 , V_74 ,
( V_34 -> V_121 & V_412 ) , 0 ) ;
if ( V_22 ) {
if ( F_89 ( V_74 ) ) {
int V_413 = 0 ;
F_62 ( & V_3 -> V_61 ) ;
if ( V_51 -> V_410
? V_405 >= V_3 -> V_103
: V_405 < V_3 -> V_103 )
V_413 = 1 ;
F_65 ( & V_3 -> V_61 ) ;
if ( V_413 ) {
F_32 ( V_22 ) ;
F_213 () ;
goto V_261;
}
}
if ( V_106 == V_113 &&
V_405 >= V_51 -> V_414 &&
V_405 < V_51 -> V_415 ) {
F_32 ( V_22 ) ;
F_214 ( V_416 ) ;
F_212 ( & V_3 -> V_229 ,
& V_408 , V_417 ) ;
if ( V_405 >= V_51 -> V_414 &&
V_405 < V_51 -> V_415 )
F_213 () ;
goto V_261;
}
if ( F_19 ( V_55 , & V_22 -> V_38 ) ||
! F_160 ( V_22 , V_34 , V_281 , V_106 ) ) {
F_25 ( V_51 -> V_52 ) ;
F_32 ( V_22 ) ;
F_213 () ;
goto V_261;
}
F_215 ( & V_3 -> V_229 , & V_408 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
F_24 ( V_43 , & V_22 -> V_38 ) ;
if ( ( V_34 -> V_121 & V_118 ) &&
! F_152 ( V_44 , & V_22 -> V_38 ) )
F_8 ( & V_3 -> V_53 ) ;
F_205 ( V_51 , V_22 ) ;
} else {
F_24 ( V_146 , & V_34 -> V_145 ) ;
F_215 ( & V_3 -> V_229 , & V_408 ) ;
break;
}
}
V_407 = F_5 ( V_34 ) ;
if ( V_407 == 0 ) {
if ( V_106 == V_113 )
F_163 ( V_51 ) ;
F_17 ( V_34 , 0 ) ;
}
}
static T_1 F_216 ( struct V_51 * V_51 , T_1 V_418 , int * V_419 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
struct V_21 * V_22 ;
T_1 V_420 , V_406 ;
int V_27 = V_3 -> V_76 ;
int V_292 = V_27 - V_3 -> V_95 ;
int V_421 = V_3 -> V_27 - V_3 -> V_95 ;
int V_69 ;
int V_281 ;
T_1 V_422 , V_423 , V_424 ;
T_1 V_425 ;
int V_426 ;
struct V_63 V_427 ;
if ( V_418 == 0 ) {
if ( V_51 -> V_410 &&
V_3 -> V_103 < F_217 ( V_51 , 0 , 0 ) ) {
V_418 = F_217 ( V_51 , 0 , 0 )
- V_3 -> V_103 ;
} else if ( ! V_51 -> V_410 &&
V_3 -> V_103 > 0 )
V_418 = V_3 -> V_103 ;
F_158 ( V_418 , V_421 ) ;
if ( V_418 ) {
V_51 -> V_428 = V_418 ;
F_218 ( & V_51 -> V_429 , NULL , L_57 ) ;
* V_419 = 1 ;
return V_418 ;
}
}
if ( V_51 -> V_387 > V_51 -> V_291 )
V_426 = V_51 -> V_387 ;
else
V_426 = V_51 -> V_291 ;
V_422 = V_3 -> V_103 ;
F_158 ( V_422 , V_421 ) ;
V_423 = V_3 -> V_103 ;
F_158 ( V_423 , V_292 ) ;
V_424 = V_3 -> V_411 ;
F_158 ( V_424 , V_292 ) ;
if ( V_51 -> V_410 ) {
V_422 -= F_219 ( T_1 , V_426 , V_422 ) ;
V_423 += V_426 ;
V_424 += V_426 ;
} else {
V_422 += V_426 ;
V_423 -= F_219 ( T_1 , V_426 , V_423 ) ;
V_424 -= F_219 ( T_1 , V_426 , V_424 ) ;
}
if ( V_51 -> V_410 ) {
F_21 ( V_3 -> V_103 == 0 ) ;
V_425 = V_422 ;
F_21 ( ( V_51 -> V_430 &
~ ( ( T_1 ) V_426 - 1 ) )
- V_426 - V_425
!= V_418 ) ;
} else {
F_21 ( V_422 != V_418 + V_426 ) ;
V_425 = V_418 ;
}
if ( V_3 -> V_431 < 0 ) {
V_424 += - V_3 -> V_431 ;
V_423 += - V_3 -> V_431 ;
} else
V_422 += V_3 -> V_431 ;
if ( ( V_51 -> V_410
? ( V_424 > V_422 && V_423 < V_422 )
: ( V_424 < V_422 && V_423 > V_422 ) ) ||
F_220 ( V_432 , V_3 -> V_433 + 10 * V_434 ) ) {
F_117 ( V_3 -> V_229 ,
F_4 ( & V_3 -> V_374 ) == 0 ) ;
V_51 -> V_93 = V_3 -> V_103 ;
V_51 -> V_428 = V_418 ;
V_3 -> V_433 = V_432 ;
F_72 ( V_278 , & V_51 -> V_60 ) ;
F_25 ( V_51 -> V_52 ) ;
F_117 ( V_51 -> V_435 , V_51 -> V_60 == 0 ||
F_221 () ) ;
F_62 ( & V_3 -> V_61 ) ;
V_3 -> V_411 = V_51 -> V_93 ;
F_65 ( & V_3 -> V_61 ) ;
F_29 ( & V_3 -> V_229 ) ;
F_218 ( & V_51 -> V_429 , NULL , L_57 ) ;
}
F_126 ( & V_427 ) ;
for ( V_69 = 0 ; V_69 < V_426 ; V_69 += V_14 ) {
int V_350 ;
int V_436 = 0 ;
V_22 = F_61 ( V_3 , V_425 + V_69 , 0 , 0 , 1 ) ;
F_72 ( V_55 , & V_22 -> V_38 ) ;
F_8 ( & V_3 -> V_374 ) ;
for ( V_350 = V_22 -> V_25 ; V_350 -- ; ) {
T_1 V_105 ;
if ( V_350 == V_22 -> V_32 )
continue;
if ( V_3 -> V_217 == 6 &&
V_350 == V_22 -> V_24 )
continue;
V_105 = F_154 ( V_22 , V_350 , 0 ) ;
if ( V_105 < F_217 ( V_51 , 0 , 0 ) ) {
V_436 = 1 ;
continue;
}
memset ( F_222 ( V_22 -> V_72 [ V_350 ] . V_67 ) , 0 , V_150 ) ;
F_72 ( V_352 , & V_22 -> V_72 [ V_350 ] . V_60 ) ;
F_72 ( V_177 , & V_22 -> V_72 [ V_350 ] . V_60 ) ;
}
if ( ! V_436 ) {
F_72 ( V_353 , & V_22 -> V_38 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
}
F_135 ( & V_22 -> V_40 , & V_427 ) ;
}
F_62 ( & V_3 -> V_61 ) ;
if ( V_51 -> V_410 )
V_3 -> V_103 -= V_426 * V_421 ;
else
V_3 -> V_103 += V_426 * V_421 ;
F_65 ( & V_3 -> V_61 ) ;
V_420 =
F_157 ( V_3 , V_425 * ( V_421 ) ,
1 , & V_281 , NULL ) ;
V_406 =
F_157 ( V_3 , ( ( V_425 + V_426 )
* V_421 - 1 ) ,
1 , & V_281 , NULL ) ;
if ( V_406 >= V_51 -> V_430 )
V_406 = V_51 -> V_430 - 1 ;
while ( V_420 <= V_406 ) {
V_22 = F_61 ( V_3 , V_420 , 1 , 0 , 1 ) ;
F_72 ( V_349 , & V_22 -> V_38 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
F_32 ( V_22 ) ;
V_420 += V_14 ;
}
while ( ! F_22 ( & V_427 ) ) {
V_22 = F_43 ( V_427 . V_66 , struct V_21 , V_40 ) ;
F_44 ( & V_22 -> V_40 ) ;
F_32 ( V_22 ) ;
}
V_418 += V_426 ;
if ( ( V_418 - V_51 -> V_428 ) * 2
>= V_51 -> V_437 - V_51 -> V_428 ) {
F_117 ( V_3 -> V_229 ,
F_4 ( & V_3 -> V_374 ) == 0 ) ;
V_51 -> V_93 = V_3 -> V_103 ;
V_51 -> V_428 = V_418 ;
V_3 -> V_433 = V_432 ;
F_72 ( V_278 , & V_51 -> V_60 ) ;
F_25 ( V_51 -> V_52 ) ;
F_117 ( V_51 -> V_435 ,
! F_19 ( V_278 , & V_51 -> V_60 )
|| F_221 () ) ;
F_62 ( & V_3 -> V_61 ) ;
V_3 -> V_411 = V_51 -> V_93 ;
F_65 ( & V_3 -> V_61 ) ;
F_29 ( & V_3 -> V_229 ) ;
F_218 ( & V_51 -> V_429 , NULL , L_57 ) ;
}
return V_426 ;
}
static inline T_1 F_223 ( struct V_51 * V_51 , T_1 V_418 , int * V_419 , int V_438 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
struct V_21 * V_22 ;
T_1 V_439 = V_51 -> V_430 ;
T_1 V_440 ;
int V_441 = 0 ;
int V_69 ;
if ( V_418 >= V_439 ) {
if ( F_19 ( V_442 , & V_51 -> V_269 ) ) {
F_224 ( V_3 ) ;
return 0 ;
}
if ( V_51 -> V_443 < V_439 )
F_225 ( V_51 -> V_320 , V_51 -> V_443 ,
& V_440 , 1 ) ;
else
V_3 -> V_444 = 0 ;
F_226 ( V_51 -> V_320 ) ;
return 0 ;
}
F_117 ( V_3 -> V_229 , V_3 -> V_98 != 2 ) ;
if ( F_19 ( V_442 , & V_51 -> V_269 ) )
return F_216 ( V_51 , V_418 , V_419 ) ;
if ( V_51 -> V_86 >= V_3 -> V_95 &&
F_19 ( V_445 , & V_51 -> V_269 ) ) {
T_1 V_332 = V_51 -> V_430 - V_418 ;
* V_419 = 1 ;
return V_332 ;
}
if ( ! F_227 ( V_51 -> V_320 , V_418 , & V_440 , 1 ) &&
! F_19 ( V_363 , & V_51 -> V_269 ) &&
! V_3 -> V_444 && V_440 >= V_14 ) {
V_440 /= V_14 ;
* V_419 = 1 ;
return V_440 * V_14 ;
}
F_228 ( V_51 -> V_320 , V_418 ) ;
V_22 = F_61 ( V_3 , V_418 , 0 , 1 , 0 ) ;
if ( V_22 == NULL ) {
V_22 = F_61 ( V_3 , V_418 , 0 , 0 , 0 ) ;
F_229 ( 1 ) ;
}
for ( V_69 = 0 ; V_69 < V_3 -> V_27 ; V_69 ++ )
if ( V_3 -> V_25 [ V_69 ] . V_89 == NULL )
V_441 = 1 ;
F_227 ( V_51 -> V_320 , V_418 , & V_440 , V_441 ) ;
F_72 ( V_367 , & V_22 -> V_38 ) ;
F_177 ( V_22 ) ;
F_32 ( V_22 ) ;
return V_14 ;
}
static int F_230 ( struct V_2 * V_3 , struct V_9 * V_392 )
{
struct V_21 * V_22 ;
int V_281 ;
T_1 V_10 , V_405 , V_406 ;
int V_446 = 0 ;
int V_407 ;
int V_447 = 0 ;
V_405 = V_392 -> V_13 & ~ ( ( T_1 ) V_14 - 1 ) ;
V_10 = F_157 ( V_3 , V_405 ,
0 , & V_281 , NULL ) ;
V_406 = V_392 -> V_13 + ( V_392 -> V_12 >> 9 ) ;
for (; V_405 < V_406 ;
V_405 += V_14 ,
V_10 += V_14 ,
V_446 ++ ) {
if ( V_446 < F_3 ( V_392 ) )
continue;
V_22 = F_61 ( V_3 , V_10 , 0 , 1 , 0 ) ;
if ( ! V_22 ) {
F_9 ( V_392 , V_446 ) ;
V_3 -> V_58 = V_392 ;
return V_447 ;
}
if ( ! F_160 ( V_22 , V_392 , V_281 , 0 ) ) {
F_32 ( V_22 ) ;
F_9 ( V_392 , V_446 ) ;
V_3 -> V_58 = V_392 ;
return V_447 ;
}
F_72 ( V_143 , & V_22 -> V_72 [ V_281 ] . V_60 ) ;
F_177 ( V_22 ) ;
F_32 ( V_22 ) ;
V_447 ++ ;
}
V_407 = F_5 ( V_392 ) ;
if ( V_407 == 0 )
F_17 ( V_392 , 0 ) ;
if ( F_31 ( & V_3 -> V_390 ) )
F_29 ( & V_3 -> V_57 ) ;
return V_447 ;
}
static int F_231 ( struct V_2 * V_3 )
{
struct V_21 * V_448 [ V_449 ] , * V_22 ;
int V_69 , V_450 = 0 ;
while ( V_450 < V_449 &&
( V_22 = F_199 ( V_3 ) ) != NULL )
V_448 [ V_450 ++ ] = V_22 ;
if ( V_450 == 0 )
return V_450 ;
F_65 ( & V_3 -> V_61 ) ;
for ( V_69 = 0 ; V_69 < V_450 ; V_69 ++ )
F_177 ( V_448 [ V_69 ] ) ;
F_232 () ;
F_62 ( & V_3 -> V_61 ) ;
for ( V_69 = 0 ; V_69 < V_450 ; V_69 ++ )
F_30 ( V_3 , V_448 [ V_69 ] ) ;
return V_450 ;
}
static void F_233 ( struct V_51 * V_51 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
int V_447 ;
struct V_451 V_452 ;
F_38 ( L_58 ) ;
F_73 ( V_51 ) ;
F_234 ( & V_452 ) ;
V_447 = 0 ;
F_62 ( & V_3 -> V_61 ) ;
while ( 1 ) {
struct V_9 * V_9 ;
int V_450 ;
if (
! F_22 ( & V_3 -> V_49 ) ) {
V_3 -> V_321 ++ ;
F_65 ( & V_3 -> V_61 ) ;
F_235 ( V_51 -> V_320 ) ;
F_62 ( & V_3 -> V_61 ) ;
V_3 -> V_48 = V_3 -> V_321 ;
F_180 ( V_3 ) ;
}
F_179 ( V_3 ) ;
while ( ( V_9 = F_189 ( V_3 ) ) ) {
int V_453 ;
F_65 ( & V_3 -> V_61 ) ;
V_453 = F_230 ( V_3 , V_9 ) ;
F_62 ( & V_3 -> V_61 ) ;
if ( ! V_453 )
break;
V_447 ++ ;
}
V_450 = F_231 ( V_3 ) ;
if ( ! V_450 )
break;
V_447 += V_450 ;
if ( V_51 -> V_60 & ~ ( 1 << V_454 ) ) {
F_65 ( & V_3 -> V_61 ) ;
F_73 ( V_51 ) ;
F_62 ( & V_3 -> V_61 ) ;
}
}
F_38 ( L_59 , V_447 ) ;
F_65 ( & V_3 -> V_61 ) ;
F_236 () ;
F_237 ( & V_452 ) ;
F_38 ( L_60 ) ;
}
static T_6
F_238 ( struct V_51 * V_51 , char * V_67 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
if ( V_3 )
return sprintf ( V_67 , L_61 , V_3 -> V_100 ) ;
else
return 0 ;
}
int
F_239 ( struct V_51 * V_51 , int V_455 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
int V_248 ;
if ( V_455 <= 16 || V_455 > 32768 )
return - V_456 ;
while ( V_455 < V_3 -> V_100 ) {
if ( F_145 ( V_3 ) )
V_3 -> V_100 -- ;
else
break;
}
V_248 = F_134 ( V_51 ) ;
if ( V_248 )
return V_248 ;
while ( V_455 > V_3 -> V_100 ) {
if ( F_120 ( V_3 ) )
V_3 -> V_100 ++ ;
else break;
}
return 0 ;
}
static T_6
F_240 ( struct V_51 * V_51 , const char * V_67 , T_5 V_165 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
unsigned long V_20 ;
int V_248 ;
if ( V_165 >= V_457 )
return - V_456 ;
if ( ! V_3 )
return - V_458 ;
if ( F_241 ( V_67 , 10 , & V_20 ) )
return - V_456 ;
V_248 = F_239 ( V_51 , V_20 ) ;
if ( V_248 )
return V_248 ;
return V_165 ;
}
static T_6
F_242 ( struct V_51 * V_51 , char * V_67 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
if ( V_3 )
return sprintf ( V_67 , L_61 , V_3 -> V_398 ) ;
else
return 0 ;
}
static T_6
F_243 ( struct V_51 * V_51 , const char * V_67 , T_5 V_165 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
unsigned long V_20 ;
if ( V_165 >= V_457 )
return - V_456 ;
if ( ! V_3 )
return - V_458 ;
if ( F_241 ( V_67 , 10 , & V_20 ) )
return - V_456 ;
if ( V_20 > V_3 -> V_100 )
return - V_456 ;
V_3 -> V_398 = V_20 ;
return V_165 ;
}
static T_6
F_244 ( struct V_51 * V_51 , char * V_67 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
if ( V_3 )
return sprintf ( V_67 , L_61 , F_4 ( & V_3 -> V_41 ) ) ;
else
return 0 ;
}
static T_1
F_217 ( struct V_51 * V_51 , T_1 V_11 , int V_27 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
if ( ! V_11 )
V_11 = V_51 -> V_430 ;
if ( ! V_27 )
V_27 = F_245 ( V_3 -> V_27 , V_3 -> V_76 ) ;
V_11 &= ~ ( ( T_1 ) V_51 -> V_291 - 1 ) ;
V_11 &= ~ ( ( T_1 ) V_51 -> V_387 - 1 ) ;
return V_11 * ( V_27 - V_3 -> V_95 ) ;
}
static void F_246 ( struct V_2 * V_3 )
{
struct V_183 * V_184 ;
unsigned long V_218 ;
if ( ! V_3 -> V_184 )
return;
F_141 () ;
F_247 (cpu) {
V_184 = F_111 ( V_3 -> V_184 , V_218 ) ;
F_248 ( V_184 -> V_214 ) ;
F_140 ( V_184 -> V_185 ) ;
}
#ifdef F_249
F_250 ( & V_3 -> V_459 ) ;
#endif
F_144 () ;
F_251 ( V_3 -> V_184 ) ;
}
static void F_252 ( struct V_2 * V_3 )
{
F_146 ( V_3 ) ;
F_246 ( V_3 ) ;
F_140 ( V_3 -> V_25 ) ;
F_140 ( V_3 -> V_8 ) ;
F_140 ( V_3 ) ;
}
static int F_253 ( struct V_460 * V_461 , unsigned long V_462 ,
void * V_463 )
{
struct V_2 * V_3 = F_202 ( V_461 , struct V_2 , V_459 ) ;
long V_218 = ( long ) V_463 ;
struct V_183 * V_184 = F_111 ( V_3 -> V_184 , V_218 ) ;
switch ( V_462 ) {
case V_464 :
case V_465 :
if ( V_3 -> V_217 == 6 && ! V_184 -> V_214 )
V_184 -> V_214 = F_48 ( V_73 ) ;
if ( ! V_184 -> V_185 )
V_184 -> V_185 = F_143 ( V_3 -> F_131 , V_73 ) ;
if ( ! V_184 -> V_185 ||
( V_3 -> V_217 == 6 && ! V_184 -> V_214 ) ) {
F_248 ( V_184 -> V_214 ) ;
F_140 ( V_184 -> V_185 ) ;
F_254 ( L_62 ,
V_140 , V_218 ) ;
return F_255 ( - V_249 ) ;
}
break;
case V_466 :
case V_467 :
F_248 ( V_184 -> V_214 ) ;
F_140 ( V_184 -> V_185 ) ;
V_184 -> V_214 = NULL ;
V_184 -> V_185 = NULL ;
break;
default:
break;
}
return V_468 ;
}
static int F_256 ( struct V_2 * V_3 )
{
unsigned long V_218 ;
struct V_67 * V_214 ;
struct V_183 T_7 * V_469 ;
void * V_185 ;
int V_248 ;
V_469 = F_257 ( struct V_183 ) ;
if ( ! V_469 )
return - V_249 ;
V_3 -> V_184 = V_469 ;
F_141 () ;
V_248 = 0 ;
F_142 (cpu) {
if ( V_3 -> V_217 == 6 ) {
V_214 = F_48 ( V_73 ) ;
if ( ! V_214 ) {
V_248 = - V_249 ;
break;
}
F_111 ( V_3 -> V_184 , V_218 ) -> V_214 = V_214 ;
}
V_185 = F_143 ( V_3 -> F_131 , V_73 ) ;
if ( ! V_185 ) {
V_248 = - V_249 ;
break;
}
F_111 ( V_3 -> V_184 , V_218 ) -> V_185 = V_185 ;
}
#ifdef F_249
V_3 -> V_459 . V_470 = F_253 ;
V_3 -> V_459 . V_471 = 0 ;
if ( V_248 == 0 )
V_248 = F_258 ( & V_3 -> V_459 ) ;
#endif
F_144 () ;
return V_248 ;
}
static struct V_2 * F_259 ( struct V_51 * V_51 )
{
struct V_2 * V_3 ;
int V_472 , V_473 , V_474 ;
struct V_88 * V_89 ;
struct V_246 * V_26 ;
char V_475 [ 6 ] ;
if ( V_51 -> V_476 != 5
&& V_51 -> V_476 != 4
&& V_51 -> V_476 != 6 ) {
F_51 ( V_83 L_63 ,
F_129 ( V_51 ) , V_51 -> V_476 ) ;
return F_260 ( - V_477 ) ;
}
if ( ( V_51 -> V_476 == 5
&& ! F_261 ( V_51 -> V_478 ) ) ||
( V_51 -> V_476 == 6
&& ! F_262 ( V_51 -> V_478 ) ) ) {
F_51 ( V_83 L_64 ,
F_129 ( V_51 ) , V_51 -> V_478 ) ;
return F_260 ( - V_477 ) ;
}
if ( V_51 -> V_476 == 6 && V_51 -> V_27 < 4 ) {
F_51 ( V_83 L_65 ,
F_129 ( V_51 ) , V_51 -> V_27 ) ;
return F_260 ( - V_456 ) ;
}
if ( ! V_51 -> V_387 ||
( V_51 -> V_387 << 9 ) % V_457 ||
! F_263 ( V_51 -> V_387 ) ) {
F_51 ( V_83 L_66 ,
F_129 ( V_51 ) , V_51 -> V_387 << 9 ) ;
return F_260 ( - V_456 ) ;
}
V_3 = F_139 ( sizeof( struct V_2 ) , V_73 ) ;
if ( V_3 == NULL )
goto abort;
F_124 ( & V_3 -> V_61 ) ;
F_123 ( & V_3 -> V_57 ) ;
F_123 ( & V_3 -> V_229 ) ;
F_126 ( & V_3 -> V_50 ) ;
F_126 ( & V_3 -> V_376 ) ;
F_126 ( & V_3 -> V_45 ) ;
F_126 ( & V_3 -> V_49 ) ;
F_126 ( & V_3 -> V_56 ) ;
F_12 ( & V_3 -> V_41 , 0 ) ;
F_12 ( & V_3 -> V_53 , 0 ) ;
F_12 ( & V_3 -> V_390 , 0 ) ;
V_3 -> V_398 = V_479 ;
V_3 -> V_330 = V_51 -> V_330 - 1 ;
V_3 -> V_27 = V_51 -> V_27 ;
if ( V_51 -> V_93 == V_94 )
V_3 -> V_76 = V_51 -> V_27 ;
else
V_3 -> V_76 = V_51 -> V_27 - V_51 -> V_480 ;
V_474 = F_128 ( V_3 -> V_27 , V_3 -> V_76 ) ;
V_3 -> F_131 = F_131 ( V_474 ) ;
V_3 -> V_25 = F_139 ( V_474 * sizeof( struct V_246 ) ,
V_73 ) ;
if ( ! V_3 -> V_25 )
goto abort;
V_3 -> V_51 = V_51 ;
if ( ( V_3 -> V_8 = F_139 ( V_457 , V_73 ) ) == NULL )
goto abort;
V_3 -> V_217 = V_51 -> V_476 ;
if ( F_256 ( V_3 ) != 0 )
goto abort;
F_38 ( L_67 , F_129 ( V_51 ) ) ;
F_264 (rdev, mddev) {
V_472 = V_89 -> V_472 ;
if ( V_472 >= V_474
|| V_472 < 0 )
continue;
V_26 = V_3 -> V_25 + V_472 ;
if ( F_19 ( V_481 , & V_89 -> V_60 ) ) {
if ( V_26 -> V_91 )
goto abort;
V_26 -> V_91 = V_89 ;
} else {
if ( V_26 -> V_89 )
goto abort;
V_26 -> V_89 = V_89 ;
}
if ( F_19 ( V_92 , & V_89 -> V_60 ) ) {
char V_253 [ V_254 ] ;
F_51 ( V_256 L_68
L_69 ,
F_129 ( V_51 ) , F_148 ( V_89 -> V_137 , V_253 ) , V_472 ) ;
} else if ( V_89 -> V_482 != V_472 )
V_3 -> V_444 = 1 ;
}
V_3 -> V_291 = V_51 -> V_387 ;
V_3 -> V_217 = V_51 -> V_476 ;
if ( V_3 -> V_217 == 6 )
V_3 -> V_95 = 2 ;
else
V_3 -> V_95 = 1 ;
V_3 -> V_287 = V_51 -> V_478 ;
V_3 -> V_100 = V_483 ;
V_3 -> V_103 = V_51 -> V_93 ;
if ( V_3 -> V_103 != V_94 ) {
V_3 -> V_290 = V_51 -> V_291 ;
V_3 -> V_288 = V_51 -> V_484 ;
}
V_473 = V_3 -> V_100 * ( sizeof( struct V_21 ) +
V_474 * ( ( sizeof( struct V_9 ) + V_457 ) ) ) / 1024 ;
if ( F_127 ( V_3 , V_3 -> V_100 ) ) {
F_51 ( V_83
L_70 ,
F_129 ( V_51 ) , V_473 ) ;
goto abort;
} else
F_51 ( V_256 L_71 ,
F_129 ( V_51 ) , V_473 ) ;
sprintf ( V_475 , L_72 , V_51 -> V_476 ) ;
V_3 -> V_52 = F_265 ( F_233 , V_51 , V_475 ) ;
if ( ! V_3 -> V_52 ) {
F_51 ( V_83
L_73 ,
F_129 ( V_51 ) ) ;
goto abort;
}
return V_3 ;
abort:
if ( V_3 ) {
F_252 ( V_3 ) ;
return F_260 ( - V_477 ) ;
} else
return F_260 ( - V_249 ) ;
}
static int F_266 ( int V_472 , int V_485 , int V_27 , int V_95 )
{
switch ( V_485 ) {
case V_297 :
if ( V_472 < V_95 )
return 1 ;
break;
case V_298 :
if ( V_472 >= V_27 - V_95 )
return 1 ;
break;
case V_306 :
if ( V_472 == 0 ||
V_472 == V_27 - 1 )
return 1 ;
break;
case V_302 :
case V_303 :
case V_304 :
case V_305 :
if ( V_472 == V_27 - 1 )
return 1 ;
}
return 0 ;
}
static int F_267 ( struct V_51 * V_51 )
{
struct V_2 * V_3 ;
int V_486 = 0 ;
int V_487 = 0 ;
struct V_88 * V_89 ;
T_1 V_488 = 0 ;
int V_69 ;
long long V_431 = 0 ;
int V_64 = 1 ;
if ( V_51 -> V_334 != V_94 )
F_51 ( V_489 L_74
L_75 ,
F_129 ( V_51 ) ) ;
F_264 (rdev, mddev) {
long long V_490 ;
if ( V_89 -> V_472 < 0 )
continue;
V_490 = ( V_89 -> V_141 - V_89 -> V_142 ) ;
if ( V_64 ) {
V_431 = V_490 ;
V_64 = 0 ;
} else if ( V_51 -> V_410 &&
V_490 < V_431 )
V_431 = V_490 ;
else if ( ! V_51 -> V_410 &&
V_490 > V_431 )
V_431 = V_490 ;
}
if ( V_51 -> V_93 != V_94 ) {
T_1 V_491 , V_492 ;
int V_493 ;
int V_95 = ( V_51 -> V_217 == 6 ? 2 : 1 ) ;
if ( V_51 -> V_476 != V_51 -> V_217 ) {
F_51 ( V_83 L_76
L_77 ,
F_129 ( V_51 ) ) ;
return - V_456 ;
}
V_493 = V_51 -> V_27 - V_51 -> V_480 ;
V_491 = V_51 -> V_93 ;
if ( F_158 ( V_491 , V_51 -> V_387 *
( V_51 -> V_27 - V_95 ) ) ) {
F_51 ( V_83 L_78
L_79 , F_129 ( V_51 ) ) ;
return - V_456 ;
}
V_488 = V_491 * V_51 -> V_387 ;
V_492 = V_51 -> V_93 ;
F_158 ( V_492 , V_51 -> V_291 *
( V_493 - V_95 ) ) ;
if ( V_51 -> V_480 == 0 ) {
if ( ( V_491 * V_51 -> V_387 !=
V_492 * V_51 -> V_291 ) ) {
F_51 ( V_83 L_80
L_81 , F_129 ( V_51 ) ) ;
return - V_456 ;
}
if ( abs ( V_431 ) >= V_51 -> V_291 &&
abs ( V_431 ) >= V_51 -> V_387 )
;
else if ( V_51 -> V_372 == 0 ) {
F_51 ( V_83 L_82
L_83
L_84 ,
F_129 ( V_51 ) ) ;
return - V_456 ;
}
} else if ( V_51 -> V_410
? ( V_491 * V_51 -> V_387 + V_431 <=
V_492 * V_51 -> V_291 )
: ( V_491 * V_51 -> V_387 >=
V_492 * V_51 -> V_291 + ( - V_431 ) ) ) {
F_51 ( V_83 L_85
L_86 ,
F_129 ( V_51 ) ) ;
return - V_456 ;
}
F_51 ( V_256 L_87 ,
F_129 ( V_51 ) ) ;
} else {
F_21 ( V_51 -> V_217 != V_51 -> V_476 ) ;
F_21 ( V_51 -> V_484 != V_51 -> V_478 ) ;
F_21 ( V_51 -> V_291 != V_51 -> V_387 ) ;
F_21 ( V_51 -> V_480 != 0 ) ;
}
if ( V_51 -> V_275 == NULL )
V_3 = F_259 ( V_51 ) ;
else
V_3 = V_51 -> V_275 ;
if ( F_268 ( V_3 ) )
return F_269 ( V_3 ) ;
V_3 -> V_431 = V_431 ;
V_51 -> V_52 = V_3 -> V_52 ;
V_3 -> V_52 = NULL ;
V_51 -> V_275 = V_3 ;
for ( V_69 = 0 ; V_69 < V_3 -> V_27 && V_3 -> V_76 ;
V_69 ++ ) {
V_89 = V_3 -> V_25 [ V_69 ] . V_89 ;
if ( ! V_89 && V_3 -> V_25 [ V_69 ] . V_91 ) {
V_89 = V_3 -> V_25 [ V_69 ] . V_91 ;
V_3 -> V_25 [ V_69 ] . V_91 = NULL ;
F_24 ( V_481 , & V_89 -> V_60 ) ;
V_3 -> V_25 [ V_69 ] . V_89 = V_89 ;
}
if ( ! V_89 )
continue;
if ( V_3 -> V_25 [ V_69 ] . V_91 &&
V_3 -> V_103 != V_94 ) {
F_51 ( V_83 L_88
L_89 ) ;
goto abort;
}
if ( F_19 ( V_92 , & V_89 -> V_60 ) ) {
V_486 ++ ;
continue;
}
if ( V_51 -> V_494 == 0 &&
V_51 -> V_495 > 90 )
V_89 -> V_333 = V_488 ;
if ( V_89 -> V_333 < V_488 ) {
if ( ! F_266 ( V_89 -> V_472 ,
V_3 -> V_287 ,
V_3 -> V_27 ,
V_3 -> V_95 ) )
continue;
}
if ( ! F_266 ( V_89 -> V_472 ,
V_3 -> V_288 ,
V_3 -> V_76 ,
V_3 -> V_95 ) )
continue;
V_487 ++ ;
}
V_51 -> V_86 = F_56 ( V_3 ) ;
if ( F_60 ( V_3 ) ) {
F_51 ( V_83 L_90
L_91 ,
F_129 ( V_51 ) , V_51 -> V_86 , V_3 -> V_27 ) ;
goto abort;
}
V_51 -> V_430 &= ~ ( V_51 -> V_291 - 1 ) ;
V_51 -> V_496 = V_51 -> V_430 ;
if ( V_51 -> V_86 > V_487 &&
V_51 -> V_334 != V_94 ) {
if ( V_51 -> V_497 )
F_51 ( V_263
L_92
L_93 ,
F_129 ( V_51 ) ) ;
else {
F_51 ( V_83
L_94 ,
F_129 ( V_51 ) ) ;
goto abort;
}
}
if ( V_51 -> V_86 == 0 )
F_51 ( V_256 L_95
L_96 , F_129 ( V_51 ) , V_3 -> V_217 ,
V_51 -> V_27 - V_51 -> V_86 , V_51 -> V_27 ,
V_51 -> V_478 ) ;
else
F_51 ( V_279 L_97
L_98 ,
F_129 ( V_51 ) , V_3 -> V_217 ,
V_51 -> V_27 - V_51 -> V_86 ,
V_51 -> V_27 , V_51 -> V_478 ) ;
F_270 ( V_3 ) ;
if ( V_3 -> V_103 != V_94 ) {
V_3 -> V_411 = V_3 -> V_103 ;
F_12 ( & V_3 -> V_374 , 0 ) ;
F_24 ( V_445 , & V_51 -> V_269 ) ;
F_24 ( V_346 , & V_51 -> V_269 ) ;
F_72 ( V_442 , & V_51 -> V_269 ) ;
F_72 ( V_498 , & V_51 -> V_269 ) ;
V_51 -> V_499 = F_265 ( V_500 , V_51 ,
L_99 ) ;
}
if ( V_51 -> V_501 == & V_502 )
V_51 -> V_501 = NULL ;
else if ( V_51 -> V_429 . V_503 &&
F_271 ( & V_51 -> V_429 , & V_502 ) )
F_51 ( V_263
L_100 ,
F_129 ( V_51 ) ) ;
F_272 ( V_51 , F_217 ( V_51 , 0 , 0 ) ) ;
if ( V_51 -> V_504 ) {
int V_505 ;
int V_292 = V_3 -> V_76 - V_3 -> V_95 ;
int V_282 = V_292 *
( ( V_51 -> V_291 << 9 ) / V_457 ) ;
if ( V_51 -> V_504 -> V_506 . V_507 < 2 * V_282 )
V_51 -> V_504 -> V_506 . V_507 = 2 * V_282 ;
F_273 ( V_51 -> V_504 , F_185 ) ;
V_51 -> V_504 -> V_506 . V_508 = V_51 ;
V_51 -> V_504 -> V_506 . V_509 = F_183 ;
V_505 = V_51 -> V_291 << 9 ;
F_274 ( V_51 -> V_504 , V_505 ) ;
F_275 ( V_51 -> V_504 , V_505 *
( V_3 -> V_27 - V_3 -> V_95 ) ) ;
F_264 (rdev, mddev) {
F_276 ( V_51 -> V_239 , V_89 -> V_137 ,
V_89 -> V_142 << 9 ) ;
F_276 ( V_51 -> V_239 , V_89 -> V_137 ,
V_89 -> V_141 << 9 ) ;
}
}
return 0 ;
abort:
F_277 ( & V_51 -> V_52 ) ;
F_270 ( V_3 ) ;
F_252 ( V_3 ) ;
V_51 -> V_275 = NULL ;
F_51 ( V_279 L_101 , F_129 ( V_51 ) ) ;
return - V_477 ;
}
static int F_278 ( struct V_51 * V_51 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
F_277 ( & V_51 -> V_52 ) ;
if ( V_51 -> V_504 )
V_51 -> V_504 -> V_506 . V_509 = NULL ;
F_252 ( V_3 ) ;
V_51 -> V_275 = NULL ;
V_51 -> V_501 = & V_502 ;
return 0 ;
}
static void F_279 ( struct V_510 * V_511 , struct V_51 * V_51 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
int V_69 ;
F_280 ( V_511 , L_102 , V_51 -> V_217 ,
V_51 -> V_291 / 2 , V_51 -> V_484 ) ;
F_280 ( V_511 , L_103 , V_3 -> V_27 , V_3 -> V_27 - V_51 -> V_86 ) ;
for ( V_69 = 0 ; V_69 < V_3 -> V_27 ; V_69 ++ )
F_280 ( V_511 , L_104 ,
V_3 -> V_25 [ V_69 ] . V_89 &&
F_19 ( V_92 , & V_3 -> V_25 [ V_69 ] . V_89 -> V_60 ) ? L_105 : L_106 ) ;
F_280 ( V_511 , L_107 ) ;
}
static void F_270 ( struct V_2 * V_3 )
{
int V_69 ;
struct V_246 * V_512 ;
F_51 ( V_513 L_108 ) ;
if ( ! V_3 ) {
F_51 ( L_109 ) ;
return;
}
F_51 ( V_513 L_110 , V_3 -> V_217 ,
V_3 -> V_27 ,
V_3 -> V_27 - V_3 -> V_51 -> V_86 ) ;
for ( V_69 = 0 ; V_69 < V_3 -> V_27 ; V_69 ++ ) {
char V_253 [ V_254 ] ;
V_512 = V_3 -> V_25 + V_69 ;
if ( V_512 -> V_89 )
F_51 ( V_513 L_111 ,
V_69 , ! F_19 ( V_90 , & V_512 -> V_89 -> V_60 ) ,
F_148 ( V_512 -> V_89 -> V_137 , V_253 ) ) ;
}
}
static int F_281 ( struct V_51 * V_51 )
{
int V_69 ;
struct V_2 * V_3 = V_51 -> V_275 ;
struct V_246 * V_512 ;
int V_29 = 0 ;
unsigned long V_60 ;
for ( V_69 = 0 ; V_69 < V_3 -> V_27 ; V_69 ++ ) {
V_512 = V_3 -> V_25 + V_69 ;
if ( V_512 -> V_91
&& V_512 -> V_91 -> V_333 == V_94
&& ! F_19 ( V_90 , & V_512 -> V_91 -> V_60 )
&& ! F_152 ( V_92 , & V_512 -> V_91 -> V_60 ) ) {
if ( ! V_512 -> V_89
|| ! F_26 ( V_92 , & V_512 -> V_89 -> V_60 ) )
V_29 ++ ;
if ( V_512 -> V_89 ) {
F_72 ( V_90 , & V_512 -> V_89 -> V_60 ) ;
F_282 (
V_512 -> V_89 -> V_514 ) ;
}
F_282 ( V_512 -> V_91 -> V_514 ) ;
} else if ( V_512 -> V_89
&& V_512 -> V_89 -> V_333 == V_94
&& ! F_19 ( V_90 , & V_512 -> V_89 -> V_60 )
&& ! F_152 ( V_92 , & V_512 -> V_89 -> V_60 ) ) {
V_29 ++ ;
F_282 ( V_512 -> V_89 -> V_514 ) ;
}
}
F_155 ( & V_3 -> V_61 , V_60 ) ;
V_51 -> V_86 = F_56 ( V_3 ) ;
F_156 ( & V_3 -> V_61 , V_60 ) ;
F_270 ( V_3 ) ;
return V_29 ;
}
static int F_283 ( struct V_51 * V_51 , struct V_88 * V_89 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
int V_248 = 0 ;
int V_515 = V_89 -> V_472 ;
struct V_88 * * V_516 ;
struct V_246 * V_68 = V_3 -> V_25 + V_515 ;
F_270 ( V_3 ) ;
if ( V_89 == V_68 -> V_89 )
V_516 = & V_68 -> V_89 ;
else if ( V_89 == V_68 -> V_91 )
V_516 = & V_68 -> V_91 ;
else
return 0 ;
if ( V_515 >= V_3 -> V_27 &&
V_3 -> V_103 == V_94 )
F_24 ( V_92 , & V_89 -> V_60 ) ;
if ( F_19 ( V_92 , & V_89 -> V_60 ) ||
F_4 ( & V_89 -> V_126 ) ) {
V_248 = - V_517 ;
goto abort;
}
if ( ! F_19 ( V_90 , & V_89 -> V_60 ) &&
V_51 -> V_330 != V_3 -> V_330 &&
! F_60 ( V_3 ) &&
( ! V_68 -> V_91 || V_68 -> V_91 == V_89 ) &&
V_515 < V_3 -> V_27 ) {
V_248 = - V_517 ;
goto abort;
}
* V_516 = NULL ;
F_284 () ;
if ( F_4 ( & V_89 -> V_126 ) ) {
V_248 = - V_517 ;
* V_516 = V_89 ;
} else if ( V_68 -> V_91 ) {
V_68 -> V_89 = V_68 -> V_91 ;
F_24 ( V_481 , & V_68 -> V_91 -> V_60 ) ;
F_70 () ;
V_68 -> V_91 = NULL ;
F_24 ( V_267 , & V_89 -> V_60 ) ;
} else
F_24 ( V_267 , & V_89 -> V_60 ) ;
abort:
F_270 ( V_3 ) ;
return V_248 ;
}
static int F_285 ( struct V_51 * V_51 , struct V_88 * V_89 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
int V_248 = - V_518 ;
int V_26 ;
struct V_246 * V_68 ;
int V_64 = 0 ;
int V_519 = V_3 -> V_27 - 1 ;
if ( V_51 -> V_330 == V_3 -> V_330 )
return - V_517 ;
if ( V_89 -> V_482 < 0 && F_60 ( V_3 ) )
return - V_456 ;
if ( V_89 -> V_472 >= 0 )
V_64 = V_519 = V_89 -> V_472 ;
if ( V_89 -> V_482 >= 0 &&
V_89 -> V_482 >= V_64 &&
V_3 -> V_25 [ V_89 -> V_482 ] . V_89 == NULL )
V_64 = V_89 -> V_482 ;
for ( V_26 = V_64 ; V_26 <= V_519 ; V_26 ++ ) {
V_68 = V_3 -> V_25 + V_26 ;
if ( V_68 -> V_89 == NULL ) {
F_24 ( V_92 , & V_89 -> V_60 ) ;
V_89 -> V_472 = V_26 ;
V_248 = 0 ;
if ( V_89 -> V_482 != V_26 )
V_3 -> V_444 = 1 ;
F_286 ( V_68 -> V_89 , V_89 ) ;
goto V_65;
}
}
for ( V_26 = V_64 ; V_26 <= V_519 ; V_26 ++ ) {
V_68 = V_3 -> V_25 + V_26 ;
if ( F_19 ( V_267 , & V_68 -> V_89 -> V_60 ) &&
V_68 -> V_91 == NULL ) {
F_24 ( V_92 , & V_89 -> V_60 ) ;
F_72 ( V_481 , & V_89 -> V_60 ) ;
V_89 -> V_472 = V_26 ;
V_248 = 0 ;
V_3 -> V_444 = 1 ;
F_286 ( V_68 -> V_91 , V_89 ) ;
break;
}
}
V_65:
F_270 ( V_3 ) ;
return V_248 ;
}
static int F_287 ( struct V_51 * V_51 , T_1 V_11 )
{
T_1 V_242 ;
V_11 &= ~ ( ( T_1 ) V_51 -> V_291 - 1 ) ;
V_242 = F_217 ( V_51 , V_11 , V_51 -> V_27 ) ;
if ( V_51 -> V_520 &&
V_51 -> V_521 > V_242 )
return - V_456 ;
if ( V_51 -> V_320 ) {
int V_522 = F_288 ( V_51 -> V_320 , V_11 , 0 , 0 ) ;
if ( V_522 )
return V_522 ;
}
F_272 ( V_51 , V_242 ) ;
F_289 ( V_51 -> V_239 , V_51 -> V_521 ) ;
F_290 ( V_51 -> V_239 ) ;
if ( V_11 > V_51 -> V_430 &&
V_51 -> V_334 > V_51 -> V_430 ) {
V_51 -> V_334 = V_51 -> V_430 ;
F_72 ( V_268 , & V_51 -> V_269 ) ;
}
V_51 -> V_430 = V_11 ;
V_51 -> V_496 = V_11 ;
return 0 ;
}
static int F_291 ( struct V_51 * V_51 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
if ( ( ( V_51 -> V_291 << 9 ) / V_150 ) * 4
> V_3 -> V_100 ||
( ( V_51 -> V_387 << 9 ) / V_150 ) * 4
> V_3 -> V_100 ) {
F_51 ( V_263 L_112 ,
F_129 ( V_51 ) ,
( ( F_128 ( V_51 -> V_291 , V_51 -> V_387 ) << 9 )
/ V_150 ) * 4 ) ;
return 0 ;
}
return 1 ;
}
static int F_292 ( struct V_51 * V_51 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
if ( V_51 -> V_480 == 0 &&
V_51 -> V_478 == V_51 -> V_484 &&
V_51 -> V_387 == V_51 -> V_291 )
return 0 ;
if ( F_60 ( V_3 ) )
return - V_456 ;
if ( V_51 -> V_480 < 0 ) {
int F_245 = 2 ;
if ( V_51 -> V_217 == 6 )
F_245 = 4 ;
if ( V_51 -> V_27 + V_51 -> V_480 < F_245 )
return - V_456 ;
}
if ( ! F_291 ( V_51 ) )
return - V_523 ;
return F_132 ( V_3 , V_3 -> V_27 + V_51 -> V_480 ) ;
}
static int F_293 ( struct V_51 * V_51 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
struct V_88 * V_89 ;
int V_524 = 0 ;
unsigned long V_60 ;
if ( F_19 ( V_498 , & V_51 -> V_269 ) )
return - V_517 ;
if ( ! F_291 ( V_51 ) )
return - V_523 ;
if ( F_60 ( V_3 ) )
return - V_456 ;
F_264 (rdev, mddev) {
if ( ! F_19 ( V_92 , & V_89 -> V_60 )
&& ! F_19 ( V_90 , & V_89 -> V_60 ) )
V_524 ++ ;
}
if ( V_524 - V_51 -> V_86 < V_51 -> V_480 - V_3 -> V_95 )
return - V_456 ;
if ( F_217 ( V_51 , 0 , V_3 -> V_27 + V_51 -> V_480 )
< V_51 -> V_521 ) {
F_51 ( V_83 L_113
L_114 , F_129 ( V_51 ) ) ;
return - V_456 ;
}
F_12 ( & V_3 -> V_374 , 0 ) ;
F_62 ( & V_3 -> V_61 ) ;
V_3 -> V_76 = V_3 -> V_27 ;
V_3 -> V_27 += V_51 -> V_480 ;
V_3 -> V_290 = V_3 -> V_291 ;
V_3 -> V_291 = V_51 -> V_387 ;
V_3 -> V_288 = V_3 -> V_287 ;
V_3 -> V_287 = V_51 -> V_478 ;
V_3 -> V_75 ++ ;
F_70 () ;
if ( V_51 -> V_410 )
V_3 -> V_103 = F_217 ( V_51 , 0 , 0 ) ;
else
V_3 -> V_103 = 0 ;
V_3 -> V_411 = V_3 -> V_103 ;
F_65 ( & V_3 -> V_61 ) ;
if ( V_51 -> V_480 >= 0 ) {
F_264 (rdev, mddev)
if ( V_89 -> V_472 < 0 &&
! F_19 ( V_90 , & V_89 -> V_60 ) ) {
if ( F_285 ( V_51 , V_89 ) == 0 ) {
if ( V_89 -> V_472
>= V_3 -> V_76 )
F_72 ( V_92 , & V_89 -> V_60 ) ;
else
V_89 -> V_333 = 0 ;
if ( F_294 ( V_51 , V_89 ) )
;
}
} else if ( V_89 -> V_472 >= V_3 -> V_76
&& ! F_19 ( V_90 , & V_89 -> V_60 ) ) {
F_72 ( V_92 , & V_89 -> V_60 ) ;
}
F_155 ( & V_3 -> V_61 , V_60 ) ;
V_51 -> V_86 = F_56 ( V_3 ) ;
F_156 ( & V_3 -> V_61 , V_60 ) ;
}
V_51 -> V_27 = V_3 -> V_27 ;
V_51 -> V_93 = V_3 -> V_103 ;
F_72 ( V_278 , & V_51 -> V_60 ) ;
F_24 ( V_445 , & V_51 -> V_269 ) ;
F_24 ( V_346 , & V_51 -> V_269 ) ;
F_72 ( V_442 , & V_51 -> V_269 ) ;
F_72 ( V_498 , & V_51 -> V_269 ) ;
V_51 -> V_499 = F_265 ( V_500 , V_51 ,
L_99 ) ;
if ( ! V_51 -> V_499 ) {
V_51 -> V_269 = 0 ;
F_62 ( & V_3 -> V_61 ) ;
V_51 -> V_27 = V_3 -> V_27 = V_3 -> V_76 ;
F_264 (rdev, mddev)
V_89 -> V_141 = V_89 -> V_142 ;
F_295 () ;
V_3 -> V_103 = V_94 ;
V_51 -> V_93 = V_94 ;
F_65 ( & V_3 -> V_61 ) ;
return - V_525 ;
}
V_3 -> V_433 = V_432 ;
F_25 ( V_51 -> V_499 ) ;
F_296 ( V_51 ) ;
return 0 ;
}
static void F_224 ( struct V_2 * V_3 )
{
if ( ! F_19 ( V_276 , & V_3 -> V_51 -> V_269 ) ) {
struct V_88 * V_89 ;
F_62 ( & V_3 -> V_61 ) ;
V_3 -> V_76 = V_3 -> V_27 ;
F_264 (rdev, conf->mddev)
V_89 -> V_142 = V_89 -> V_141 ;
F_295 () ;
V_3 -> V_103 = V_94 ;
F_65 ( & V_3 -> V_61 ) ;
F_29 ( & V_3 -> V_229 ) ;
if ( V_3 -> V_51 -> V_504 ) {
int V_292 = V_3 -> V_27 - V_3 -> V_95 ;
int V_282 = V_292 * ( ( V_3 -> V_291 << 9 )
/ V_457 ) ;
if ( V_3 -> V_51 -> V_504 -> V_506 . V_507 < 2 * V_282 )
V_3 -> V_51 -> V_504 -> V_506 . V_507 = 2 * V_282 ;
}
}
}
static void F_297 ( struct V_51 * V_51 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
if ( ! F_19 ( V_276 , & V_51 -> V_269 ) ) {
if ( V_51 -> V_480 > 0 ) {
F_272 ( V_51 , F_217 ( V_51 , 0 , 0 ) ) ;
F_289 ( V_51 -> V_239 , V_51 -> V_521 ) ;
F_290 ( V_51 -> V_239 ) ;
} else {
int V_526 ;
F_62 ( & V_3 -> V_61 ) ;
V_51 -> V_86 = F_56 ( V_3 ) ;
F_65 ( & V_3 -> V_61 ) ;
for ( V_526 = V_3 -> V_27 ;
V_526 < V_3 -> V_27 - V_51 -> V_480 ;
V_526 ++ ) {
struct V_88 * V_89 = V_3 -> V_25 [ V_526 ] . V_89 ;
if ( V_89 )
F_24 ( V_92 , & V_89 -> V_60 ) ;
V_89 = V_3 -> V_25 [ V_526 ] . V_91 ;
if ( V_89 )
F_24 ( V_92 , & V_89 -> V_60 ) ;
}
}
V_51 -> V_484 = V_3 -> V_287 ;
V_51 -> V_291 = V_3 -> V_291 ;
V_51 -> V_93 = V_94 ;
V_51 -> V_480 = 0 ;
V_51 -> V_410 = 0 ;
}
}
static void F_298 ( struct V_51 * V_51 , int V_38 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
switch( V_38 ) {
case 2 :
F_29 ( & V_3 -> V_229 ) ;
break;
case 1 :
F_62 ( & V_3 -> V_61 ) ;
V_3 -> V_98 = 2 ;
F_63 ( V_3 -> V_57 ,
F_4 ( & V_3 -> V_41 ) == 0 &&
F_4 ( & V_3 -> V_390 ) == 0 ,
V_3 -> V_61 , ) ;
V_3 -> V_98 = 1 ;
F_65 ( & V_3 -> V_61 ) ;
F_29 ( & V_3 -> V_229 ) ;
break;
case 0 :
F_62 ( & V_3 -> V_61 ) ;
V_3 -> V_98 = 0 ;
F_29 ( & V_3 -> V_57 ) ;
F_29 ( & V_3 -> V_229 ) ;
F_65 ( & V_3 -> V_61 ) ;
break;
}
}
static void * F_299 ( struct V_51 * V_51 , int V_217 )
{
struct V_527 * V_528 = V_51 -> V_275 ;
T_1 V_11 ;
if ( V_528 -> V_529 > 1 ) {
F_51 ( V_83 L_115 ,
F_129 ( V_51 ) ) ;
return F_260 ( - V_456 ) ;
}
V_11 = V_528 -> V_530 [ 0 ] . V_531 ;
F_158 ( V_11 , V_528 -> V_530 [ 0 ] . V_532 ) ;
V_51 -> V_430 = V_11 ;
V_51 -> V_476 = V_217 ;
V_51 -> V_478 = V_298 ;
V_51 -> V_387 = V_51 -> V_291 ;
V_51 -> V_27 += 1 ;
V_51 -> V_480 = 1 ;
V_51 -> V_334 = V_94 ;
return F_259 ( V_51 ) ;
}
static void * F_300 ( struct V_51 * V_51 )
{
int V_533 ;
if ( V_51 -> V_27 != 2 ||
V_51 -> V_86 > 1 )
return F_260 ( - V_456 ) ;
V_533 = 64 * 2 ;
while ( V_533 && ( V_51 -> V_521 & ( V_533 - 1 ) ) )
V_533 >>= 1 ;
if ( ( V_533 << 9 ) < V_150 )
return F_260 ( - V_456 ) ;
V_51 -> V_476 = 5 ;
V_51 -> V_478 = V_295 ;
V_51 -> V_387 = V_533 ;
return F_259 ( V_51 ) ;
}
static void * F_301 ( struct V_51 * V_51 )
{
int V_478 ;
switch ( V_51 -> V_484 ) {
case V_302 :
V_478 = V_293 ;
break;
case V_303 :
V_478 = V_294 ;
break;
case V_304 :
V_478 = V_295 ;
break;
case V_305 :
V_478 = V_296 ;
break;
case V_306 :
V_478 = V_297 ;
break;
case V_298 :
V_478 = V_298 ;
break;
default:
return F_260 ( - V_456 ) ;
}
V_51 -> V_476 = 5 ;
V_51 -> V_478 = V_478 ;
V_51 -> V_480 = - 1 ;
V_51 -> V_27 -= 1 ;
return F_259 ( V_51 ) ;
}
static int F_302 ( struct V_51 * V_51 )
{
struct V_2 * V_3 = V_51 -> V_275 ;
int V_534 = V_51 -> V_387 ;
if ( V_51 -> V_478 >= 0 && ! F_261 ( V_51 -> V_478 ) )
return - V_456 ;
if ( V_534 > 0 ) {
if ( ! F_263 ( V_534 ) )
return - V_456 ;
if ( V_534 < ( V_457 >> 9 ) )
return - V_456 ;
if ( V_51 -> V_521 & ( V_534 - 1 ) )
return - V_456 ;
}
if ( V_51 -> V_27 == 2 ) {
if ( V_51 -> V_478 >= 0 ) {
V_3 -> V_287 = V_51 -> V_478 ;
V_51 -> V_484 = V_51 -> V_478 ;
}
if ( V_534 > 0 ) {
V_3 -> V_291 = V_534 ;
V_51 -> V_291 = V_534 ;
}
F_72 ( V_278 , & V_51 -> V_60 ) ;
F_25 ( V_51 -> V_52 ) ;
}
return F_292 ( V_51 ) ;
}
static int F_303 ( struct V_51 * V_51 )
{
int V_534 = V_51 -> V_387 ;
if ( V_51 -> V_478 >= 0 && ! F_262 ( V_51 -> V_478 ) )
return - V_456 ;
if ( V_534 > 0 ) {
if ( ! F_263 ( V_534 ) )
return - V_456 ;
if ( V_534 < ( V_457 >> 9 ) )
return - V_456 ;
if ( V_51 -> V_521 & ( V_534 - 1 ) )
return - V_456 ;
}
return F_292 ( V_51 ) ;
}
static void * F_304 ( struct V_51 * V_51 )
{
if ( V_51 -> V_217 == 0 )
return F_299 ( V_51 , 5 ) ;
if ( V_51 -> V_217 == 1 )
return F_300 ( V_51 ) ;
if ( V_51 -> V_217 == 4 ) {
V_51 -> V_478 = V_298 ;
V_51 -> V_476 = 5 ;
return F_259 ( V_51 ) ;
}
if ( V_51 -> V_217 == 6 )
return F_301 ( V_51 ) ;
return F_260 ( - V_456 ) ;
}
static void * F_305 ( struct V_51 * V_51 )
{
if ( V_51 -> V_217 == 0 )
return F_299 ( V_51 , 4 ) ;
if ( V_51 -> V_217 == 5 &&
V_51 -> V_484 == V_298 ) {
V_51 -> V_478 = 0 ;
V_51 -> V_476 = 4 ;
return F_259 ( V_51 ) ;
}
return F_260 ( - V_456 ) ;
}
static void * F_306 ( struct V_51 * V_51 )
{
int V_478 ;
if ( V_51 -> V_535 != & V_536 )
return F_260 ( - V_456 ) ;
if ( V_51 -> V_86 > 1 )
return F_260 ( - V_456 ) ;
if ( V_51 -> V_27 > 253 )
return F_260 ( - V_456 ) ;
if ( V_51 -> V_27 < 3 )
return F_260 ( - V_456 ) ;
switch ( V_51 -> V_484 ) {
case V_293 :
V_478 = V_302 ;
break;
case V_294 :
V_478 = V_303 ;
break;
case V_295 :
V_478 = V_304 ;
break;
case V_296 :
V_478 = V_305 ;
break;
case V_297 :
V_478 = V_306 ;
break;
case V_298 :
V_478 = V_298 ;
break;
default:
return F_260 ( - V_456 ) ;
}
V_51 -> V_476 = 6 ;
V_51 -> V_478 = V_478 ;
V_51 -> V_480 = 1 ;
V_51 -> V_27 += 1 ;
return F_259 ( V_51 ) ;
}
static int T_8 F_307 ( void )
{
F_308 ( & V_537 ) ;
F_308 ( & V_536 ) ;
F_308 ( & V_538 ) ;
return 0 ;
}
static void F_309 ( void )
{
F_310 ( & V_537 ) ;
F_310 ( & V_536 ) ;
F_310 ( & V_538 ) ;
}
