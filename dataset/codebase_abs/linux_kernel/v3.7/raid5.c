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
if ( F_19 ( V_114 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
V_106 |= V_115 ;
} else if ( F_26 ( V_116 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
V_106 = V_117 ;
else if ( F_26 ( V_118 ,
& V_22 -> V_72 [ V_69 ] . V_60 ) ) {
V_106 = V_113 ;
V_107 = 1 ;
} else
continue;
if ( F_26 ( V_119 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
V_106 |= V_120 ;
V_34 = & V_22 -> V_72 [ V_69 ] . V_121 ;
V_108 = & V_22 -> V_72 [ V_69 ] . V_122 ;
V_34 -> V_123 = V_106 ;
V_108 -> V_123 = V_106 ;
if ( V_106 & V_113 ) {
V_34 -> V_124 = V_125 ;
V_108 -> V_124 = V_125 ;
} else
V_34 -> V_124 = V_126 ;
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
if ( F_19 ( V_127 , & V_22 -> V_72 [ V_69 ] . V_60 ) && V_109 )
V_89 = V_109 ;
V_109 = NULL ;
}
if ( V_89 && F_19 ( V_90 , & V_89 -> V_60 ) )
V_89 = NULL ;
if ( V_89 )
F_8 ( & V_89 -> V_128 ) ;
if ( V_109 && F_19 ( V_90 , & V_109 -> V_60 ) )
V_109 = NULL ;
if ( V_109 )
F_8 ( & V_109 -> V_128 ) ;
F_59 () ;
while ( ( V_106 & V_113 ) && V_89 &&
F_19 ( V_129 , & V_89 -> V_60 ) ) {
T_1 V_130 ;
int V_131 ;
int V_132 = F_71 ( V_89 , V_22 -> V_10 , V_14 ,
& V_130 , & V_131 ) ;
if ( ! V_132 )
break;
if ( V_132 < 0 ) {
F_72 ( V_133 , & V_89 -> V_60 ) ;
if ( ! V_3 -> V_51 -> V_134 &&
V_3 -> V_51 -> V_60 ) {
F_73 ( V_3 -> V_51 ) ;
}
F_8 ( & V_89 -> V_128 ) ;
F_74 ( V_89 , V_3 -> V_51 ) ;
} else {
F_75 ( V_89 , V_3 -> V_51 ) ;
V_89 = NULL ;
}
}
if ( V_89 ) {
if ( V_105 -> V_135 || V_105 -> V_136 || V_105 -> V_137
|| V_105 -> V_138 )
F_76 ( V_89 -> V_139 , V_14 ) ;
F_72 ( V_140 , & V_22 -> V_38 ) ;
V_34 -> V_141 = V_89 -> V_139 ;
F_38 ( L_8 ,
V_142 , ( unsigned long long ) V_22 -> V_10 ,
V_34 -> V_123 , V_69 ) ;
F_8 ( & V_22 -> V_29 ) ;
if ( F_66 ( V_3 , V_22 ) )
V_34 -> V_13 = ( V_22 -> V_10
+ V_89 -> V_143 ) ;
else
V_34 -> V_13 = ( V_22 -> V_10
+ V_89 -> V_144 ) ;
if ( F_19 ( V_145 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
V_34 -> V_123 |= V_146 ;
V_34 -> V_147 = 1 << V_148 ;
V_34 -> V_149 = 0 ;
V_34 -> V_150 [ 0 ] . V_151 = V_152 ;
V_34 -> V_150 [ 0 ] . V_153 = 0 ;
V_34 -> V_12 = V_152 ;
V_34 -> V_15 = NULL ;
if ( V_109 )
F_72 ( V_154 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_77 ( V_34 ) ;
}
if ( V_109 ) {
if ( V_105 -> V_135 || V_105 -> V_136 || V_105 -> V_137
|| V_105 -> V_138 )
F_76 ( V_109 -> V_139 , V_14 ) ;
F_72 ( V_140 , & V_22 -> V_38 ) ;
V_108 -> V_141 = V_109 -> V_139 ;
F_38 ( L_9
L_10 ,
V_142 , ( unsigned long long ) V_22 -> V_10 ,
V_108 -> V_123 , V_69 ) ;
F_8 ( & V_22 -> V_29 ) ;
if ( F_66 ( V_3 , V_22 ) )
V_108 -> V_13 = ( V_22 -> V_10
+ V_109 -> V_143 ) ;
else
V_108 -> V_13 = ( V_22 -> V_10
+ V_109 -> V_144 ) ;
V_108 -> V_147 = 1 << V_148 ;
V_108 -> V_149 = 0 ;
V_108 -> V_150 [ 0 ] . V_151 = V_152 ;
V_108 -> V_150 [ 0 ] . V_153 = 0 ;
V_108 -> V_12 = V_152 ;
V_108 -> V_15 = NULL ;
F_77 ( V_108 ) ;
}
if ( ! V_89 && ! V_109 ) {
if ( V_106 & V_113 )
F_72 ( V_155 , & V_22 -> V_38 ) ;
F_38 ( L_11 ,
V_34 -> V_123 , V_69 , ( unsigned long long ) V_22 -> V_10 ) ;
F_24 ( V_82 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
}
}
}
static struct V_156 *
F_78 ( int V_157 , struct V_9 * V_9 , struct V_67 * V_67 ,
T_1 V_10 , struct V_156 * V_158 )
{
struct V_159 * V_160 ;
struct V_67 * V_161 ;
int V_69 ;
int V_162 ;
struct V_163 V_164 ;
enum V_165 V_60 = 0 ;
if ( V_9 -> V_13 >= V_10 )
V_162 = ( signed ) ( V_9 -> V_13 - V_10 ) * 512 ;
else
V_162 = ( signed ) ( V_10 - V_9 -> V_13 ) * - 512 ;
if ( V_157 )
V_60 |= V_166 ;
F_79 ( & V_164 , V_60 , V_158 , NULL , NULL , NULL ) ;
F_80 (bvl, bio, i) {
int V_167 = V_160 -> V_151 ;
int V_168 ;
int V_169 = 0 ;
if ( V_162 < 0 ) {
V_169 = - V_162 ;
V_162 += V_169 ;
V_167 -= V_169 ;
}
if ( V_167 > 0 && V_162 + V_167 > V_152 )
V_168 = V_152 - V_162 ;
else
V_168 = V_167 ;
if ( V_168 > 0 ) {
V_169 += V_160 -> V_153 ;
V_161 = V_160 -> V_170 ;
if ( V_157 )
V_158 = F_81 ( V_67 , V_161 , V_162 ,
V_169 , V_168 , & V_164 ) ;
else
V_158 = F_81 ( V_161 , V_67 , V_169 ,
V_162 , V_168 , & V_164 ) ;
}
V_164 . V_171 = V_158 ;
if ( V_168 < V_167 )
break;
V_162 += V_167 ;
}
return V_158 ;
}
static void F_82 ( void * V_172 )
{
struct V_21 * V_22 = V_172 ;
struct V_9 * V_33 = NULL ;
int V_69 ;
F_38 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_69 = V_22 -> V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( F_26 ( V_173 , & V_72 -> V_60 ) ) {
struct V_9 * V_108 , * V_174 ;
F_21 ( ! V_72 -> V_79 ) ;
V_108 = V_72 -> V_79 ;
V_72 -> V_79 = NULL ;
while ( V_108 && V_108 -> V_13 <
V_72 -> V_10 + V_14 ) {
V_174 = F_2 ( V_108 , V_72 -> V_10 ) ;
if ( ! F_5 ( V_108 ) ) {
V_108 -> V_15 = V_33 ;
V_33 = V_108 ;
}
V_108 = V_174 ;
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
struct V_156 * V_158 = NULL ;
struct V_163 V_164 ;
int V_69 ;
F_38 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_69 = V_22 -> V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( F_19 ( V_173 , & V_72 -> V_60 ) ) {
struct V_9 * V_108 ;
F_62 ( & V_22 -> V_175 ) ;
V_72 -> V_79 = V_108 = V_72 -> V_78 ;
V_72 -> V_78 = NULL ;
F_65 ( & V_22 -> V_175 ) ;
while ( V_108 && V_108 -> V_13 <
V_72 -> V_10 + V_14 ) {
V_158 = F_78 ( 0 , V_108 , V_72 -> V_67 ,
V_72 -> V_10 , V_158 ) ;
V_108 = F_2 ( V_108 , V_72 -> V_10 ) ;
}
}
}
F_8 ( & V_22 -> V_29 ) ;
F_79 ( & V_164 , V_176 , V_158 , F_82 , V_22 , NULL ) ;
F_84 ( & V_164 ) ;
}
static void F_85 ( struct V_21 * V_22 , int V_177 )
{
struct V_77 * V_178 ;
if ( V_177 < 0 )
return;
V_178 = & V_22 -> V_72 [ V_177 ] ;
F_72 ( V_179 , & V_178 -> V_60 ) ;
F_21 ( ! F_19 ( V_180 , & V_178 -> V_60 ) ) ;
F_24 ( V_180 , & V_178 -> V_60 ) ;
}
static void F_86 ( void * V_172 )
{
struct V_21 * V_22 = V_172 ;
F_38 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_85 ( V_22 , V_22 -> V_181 . V_177 ) ;
F_85 ( V_22 , V_22 -> V_181 . V_182 ) ;
F_24 ( V_39 , & V_22 -> V_38 ) ;
if ( V_22 -> V_35 == V_183 )
V_22 -> V_35 = V_184 ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
F_32 ( V_22 ) ;
}
static T_3 * F_87 ( struct V_21 * V_22 ,
struct V_185 * V_186 )
{
return V_186 -> V_187 + sizeof( struct V_67 * ) * ( V_22 -> V_25 + 2 ) ;
}
static struct V_156 *
F_88 ( struct V_21 * V_22 , struct V_185 * V_186 )
{
int V_25 = V_22 -> V_25 ;
struct V_67 * * V_188 = V_186 -> V_187 ;
int V_177 = V_22 -> V_181 . V_177 ;
struct V_77 * V_178 = & V_22 -> V_72 [ V_177 ] ;
struct V_67 * V_189 = V_178 -> V_67 ;
int V_29 = 0 ;
struct V_156 * V_158 ;
struct V_163 V_164 ;
int V_69 ;
F_38 ( L_13 ,
V_142 , ( unsigned long long ) V_22 -> V_10 , V_177 ) ;
F_21 ( ! F_19 ( V_180 , & V_178 -> V_60 ) ) ;
for ( V_69 = V_25 ; V_69 -- ; )
if ( V_69 != V_177 )
V_188 [ V_29 ++ ] = V_22 -> V_72 [ V_69 ] . V_67 ;
F_8 ( & V_22 -> V_29 ) ;
F_79 ( & V_164 , V_166 | V_190 , NULL ,
F_86 , V_22 , F_87 ( V_22 , V_186 ) ) ;
if ( F_89 ( V_29 == 1 ) )
V_158 = F_81 ( V_189 , V_188 [ 0 ] , 0 , 0 , V_152 , & V_164 ) ;
else
V_158 = F_90 ( V_189 , V_188 , 0 , V_29 , V_152 , & V_164 ) ;
return V_158 ;
}
static int F_91 ( struct V_67 * * V_191 , struct V_21 * V_22 )
{
int V_25 = V_22 -> V_25 ;
int V_30 = V_22 -> V_23 ? V_25 : ( V_25 - 2 ) ;
int V_192 = F_13 ( V_22 ) ;
int V_29 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_25 ; V_69 ++ )
V_191 [ V_69 ] = NULL ;
V_29 = 0 ;
V_69 = V_192 ;
do {
int V_31 = F_15 ( V_69 , V_22 , & V_29 , V_30 ) ;
V_191 [ V_31 ] = V_22 -> V_72 [ V_69 ] . V_67 ;
V_69 = F_14 ( V_69 , V_25 ) ;
} while ( V_69 != V_192 );
return V_30 ;
}
static struct V_156 *
F_92 ( struct V_21 * V_22 , struct V_185 * V_186 )
{
int V_25 = V_22 -> V_25 ;
struct V_67 * * V_193 = V_186 -> V_187 ;
int V_177 ;
int V_24 = V_22 -> V_24 ;
struct V_156 * V_158 ;
struct V_163 V_164 ;
struct V_77 * V_178 ;
struct V_67 * V_194 ;
int V_69 ;
int V_29 ;
if ( V_22 -> V_181 . V_177 < 0 )
V_177 = V_22 -> V_181 . V_182 ;
else if ( V_22 -> V_181 . V_182 < 0 )
V_177 = V_22 -> V_181 . V_177 ;
else
F_64 () ;
F_21 ( V_177 < 0 ) ;
F_38 ( L_13 ,
V_142 , ( unsigned long long ) V_22 -> V_10 , V_177 ) ;
V_178 = & V_22 -> V_72 [ V_177 ] ;
F_21 ( ! F_19 ( V_180 , & V_178 -> V_60 ) ) ;
V_194 = V_178 -> V_67 ;
F_8 ( & V_22 -> V_29 ) ;
if ( V_177 == V_24 ) {
V_29 = F_91 ( V_193 , V_22 ) ;
V_193 [ V_29 ] = NULL ;
F_21 ( V_193 [ V_29 + 1 ] != V_194 ) ;
F_79 ( & V_164 , V_166 , NULL ,
F_86 , V_22 ,
F_87 ( V_22 , V_186 ) ) ;
V_158 = F_93 ( V_193 , 0 , V_29 + 2 , V_152 , & V_164 ) ;
} else {
V_29 = 0 ;
for ( V_69 = V_25 ; V_69 -- ; ) {
if ( V_69 == V_177 || V_69 == V_24 )
continue;
V_193 [ V_29 ++ ] = V_22 -> V_72 [ V_69 ] . V_67 ;
}
F_79 ( & V_164 , V_166 | V_190 ,
NULL , F_86 , V_22 ,
F_87 ( V_22 , V_186 ) ) ;
V_158 = F_90 ( V_194 , V_193 , 0 , V_29 , V_152 , & V_164 ) ;
}
return V_158 ;
}
static struct V_156 *
F_94 ( struct V_21 * V_22 , struct V_185 * V_186 )
{
int V_69 , V_29 , V_25 = V_22 -> V_25 ;
int V_30 = V_22 -> V_23 ? V_25 : V_25 - 2 ;
int V_192 = F_13 ( V_22 ) ;
int V_195 = - 1 , V_196 = - 1 ;
int V_177 = V_22 -> V_181 . V_177 ;
int V_182 = V_22 -> V_181 . V_182 ;
struct V_77 * V_178 = & V_22 -> V_72 [ V_177 ] ;
struct V_77 * V_197 = & V_22 -> V_72 [ V_182 ] ;
struct V_156 * V_158 ;
struct V_67 * * V_193 = V_186 -> V_187 ;
struct V_163 V_164 ;
F_38 ( L_14 ,
V_142 , ( unsigned long long ) V_22 -> V_10 , V_177 , V_182 ) ;
F_21 ( V_177 < 0 || V_182 < 0 ) ;
F_21 ( ! F_19 ( V_180 , & V_178 -> V_60 ) ) ;
F_21 ( ! F_19 ( V_180 , & V_197 -> V_60 ) ) ;
for ( V_69 = 0 ; V_69 < V_25 ; V_69 ++ )
V_193 [ V_69 ] = NULL ;
V_29 = 0 ;
V_69 = V_192 ;
do {
int V_31 = F_15 ( V_69 , V_22 , & V_29 , V_30 ) ;
V_193 [ V_31 ] = V_22 -> V_72 [ V_69 ] . V_67 ;
if ( V_69 == V_177 )
V_195 = V_31 ;
if ( V_69 == V_182 )
V_196 = V_31 ;
V_69 = F_14 ( V_69 , V_25 ) ;
} while ( V_69 != V_192 );
F_21 ( V_195 == V_196 ) ;
if ( V_196 < V_195 )
F_95 ( V_195 , V_196 ) ;
F_38 ( L_15 ,
V_142 , ( unsigned long long ) V_22 -> V_10 , V_195 , V_196 ) ;
F_8 ( & V_22 -> V_29 ) ;
if ( V_196 == V_30 + 1 ) {
if ( V_195 == V_30 ) {
F_79 ( & V_164 , V_166 , NULL ,
F_86 , V_22 ,
F_87 ( V_22 , V_186 ) ) ;
return F_93 ( V_193 , 0 , V_30 + 2 ,
V_152 , & V_164 ) ;
} else {
struct V_67 * V_194 ;
int V_198 ;
int V_24 = V_22 -> V_24 ;
if ( V_177 == V_24 )
V_198 = V_182 ;
else
V_198 = V_177 ;
V_29 = 0 ;
for ( V_69 = V_25 ; V_69 -- ; ) {
if ( V_69 == V_198 || V_69 == V_24 )
continue;
V_193 [ V_29 ++ ] = V_22 -> V_72 [ V_69 ] . V_67 ;
}
V_194 = V_22 -> V_72 [ V_198 ] . V_67 ;
F_79 ( & V_164 ,
V_166 | V_190 ,
NULL , NULL , NULL ,
F_87 ( V_22 , V_186 ) ) ;
V_158 = F_90 ( V_194 , V_193 , 0 , V_29 , V_152 ,
& V_164 ) ;
V_29 = F_91 ( V_193 , V_22 ) ;
F_79 ( & V_164 , V_166 , V_158 ,
F_86 , V_22 ,
F_87 ( V_22 , V_186 ) ) ;
return F_93 ( V_193 , 0 , V_29 + 2 ,
V_152 , & V_164 ) ;
}
} else {
F_79 ( & V_164 , V_166 , NULL ,
F_86 , V_22 ,
F_87 ( V_22 , V_186 ) ) ;
if ( V_196 == V_30 ) {
return F_96 ( V_30 + 2 ,
V_152 , V_195 ,
V_193 , & V_164 ) ;
} else {
return F_97 ( V_30 + 2 ,
V_152 , V_195 , V_196 ,
V_193 , & V_164 ) ;
}
}
}
static void F_98 ( void * V_172 )
{
struct V_21 * V_22 = V_172 ;
F_38 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
}
static struct V_156 *
F_99 ( struct V_21 * V_22 , struct V_185 * V_186 ,
struct V_156 * V_158 )
{
int V_25 = V_22 -> V_25 ;
struct V_67 * * V_188 = V_186 -> V_187 ;
int V_29 = 0 , V_32 = V_22 -> V_32 , V_69 ;
struct V_163 V_164 ;
struct V_67 * V_189 = V_188 [ V_29 ++ ] = V_22 -> V_72 [ V_32 ] . V_67 ;
F_38 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( F_19 ( V_199 , & V_72 -> V_60 ) )
V_188 [ V_29 ++ ] = V_72 -> V_67 ;
}
F_79 ( & V_164 , V_166 | V_200 , V_158 ,
F_98 , V_22 , F_87 ( V_22 , V_186 ) ) ;
V_158 = F_90 ( V_189 , V_188 , 0 , V_29 , V_152 , & V_164 ) ;
return V_158 ;
}
static struct V_156 *
F_100 ( struct V_21 * V_22 , struct V_156 * V_158 )
{
int V_25 = V_22 -> V_25 ;
int V_69 ;
F_38 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
struct V_9 * V_201 ;
if ( F_26 ( V_199 , & V_72 -> V_60 ) ) {
struct V_9 * V_202 ;
F_62 ( & V_22 -> V_175 ) ;
V_201 = V_72 -> V_80 ;
V_72 -> V_80 = NULL ;
F_21 ( V_72 -> V_81 ) ;
V_202 = V_72 -> V_81 = V_201 ;
F_65 ( & V_22 -> V_175 ) ;
while ( V_202 && V_202 -> V_13 <
V_72 -> V_10 + V_14 ) {
if ( V_202 -> V_123 & V_203 )
F_72 ( V_111 , & V_72 -> V_60 ) ;
if ( V_202 -> V_123 & V_120 )
F_72 ( V_119 , & V_72 -> V_60 ) ;
if ( V_202 -> V_123 & V_115 )
F_72 ( V_114 , & V_72 -> V_60 ) ;
else
V_158 = F_78 ( 1 , V_202 , V_72 -> V_67 ,
V_72 -> V_10 , V_158 ) ;
V_202 = F_2 ( V_202 , V_72 -> V_10 ) ;
}
}
}
return V_158 ;
}
static void F_101 ( void * V_172 )
{
struct V_21 * V_22 = V_172 ;
int V_25 = V_22 -> V_25 ;
int V_32 = V_22 -> V_32 ;
int V_24 = V_22 -> V_24 ;
int V_69 ;
bool V_204 = false , V_205 = false , V_206 = false ;
F_38 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_69 = V_25 ; V_69 -- ; ) {
V_204 |= F_19 ( V_111 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
V_205 |= F_19 ( V_119 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
V_206 |= F_19 ( V_114 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
}
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( V_72 -> V_81 || V_69 == V_32 || V_69 == V_24 ) {
if ( ! V_206 )
F_72 ( V_179 , & V_72 -> V_60 ) ;
if ( V_204 )
F_72 ( V_111 , & V_72 -> V_60 ) ;
if ( V_205 )
F_72 ( V_119 , & V_72 -> V_60 ) ;
}
}
if ( V_22 -> V_36 == V_207 )
V_22 -> V_36 = V_208 ;
else if ( V_22 -> V_36 == V_209 )
V_22 -> V_36 = V_210 ;
else {
F_21 ( V_22 -> V_36 != V_211 ) ;
V_22 -> V_36 = V_212 ;
}
F_72 ( V_42 , & V_22 -> V_38 ) ;
F_32 ( V_22 ) ;
}
static void
F_102 ( struct V_21 * V_22 , struct V_185 * V_186 ,
struct V_156 * V_158 )
{
int V_25 = V_22 -> V_25 ;
struct V_67 * * V_188 = V_186 -> V_187 ;
struct V_163 V_164 ;
int V_29 = 0 , V_32 = V_22 -> V_32 , V_69 ;
struct V_67 * V_189 ;
int V_213 = 0 ;
unsigned long V_60 ;
F_38 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_69 = 0 ; V_69 < V_22 -> V_25 ; V_69 ++ ) {
if ( V_32 == V_69 )
continue;
if ( ! F_19 ( V_114 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
break;
}
if ( V_69 >= V_22 -> V_25 ) {
F_8 ( & V_22 -> V_29 ) ;
F_72 ( V_114 , & V_22 -> V_72 [ V_32 ] . V_60 ) ;
F_101 ( V_22 ) ;
return;
}
if ( V_22 -> V_36 == V_209 ) {
V_213 = 1 ;
V_189 = V_188 [ V_29 ++ ] = V_22 -> V_72 [ V_32 ] . V_67 ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( V_72 -> V_81 )
V_188 [ V_29 ++ ] = V_72 -> V_67 ;
}
} else {
V_189 = V_22 -> V_72 [ V_32 ] . V_67 ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( V_69 != V_32 )
V_188 [ V_29 ++ ] = V_72 -> V_67 ;
}
}
V_60 = V_176 |
( V_213 ? V_200 : V_190 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_79 ( & V_164 , V_60 , V_158 , F_101 , V_22 ,
F_87 ( V_22 , V_186 ) ) ;
if ( F_89 ( V_29 == 1 ) )
V_158 = F_81 ( V_189 , V_188 [ 0 ] , 0 , 0 , V_152 , & V_164 ) ;
else
V_158 = F_90 ( V_189 , V_188 , 0 , V_29 , V_152 , & V_164 ) ;
}
static void
F_103 ( struct V_21 * V_22 , struct V_185 * V_186 ,
struct V_156 * V_158 )
{
struct V_163 V_164 ;
struct V_67 * * V_193 = V_186 -> V_187 ;
int V_29 , V_69 ;
F_38 ( L_12 , V_142 , ( unsigned long long ) V_22 -> V_10 ) ;
for ( V_69 = 0 ; V_69 < V_22 -> V_25 ; V_69 ++ ) {
if ( V_22 -> V_32 == V_69 || V_22 -> V_24 == V_69 )
continue;
if ( ! F_19 ( V_114 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
break;
}
if ( V_69 >= V_22 -> V_25 ) {
F_8 ( & V_22 -> V_29 ) ;
F_72 ( V_114 , & V_22 -> V_72 [ V_22 -> V_32 ] . V_60 ) ;
F_72 ( V_114 , & V_22 -> V_72 [ V_22 -> V_24 ] . V_60 ) ;
F_101 ( V_22 ) ;
return;
}
V_29 = F_91 ( V_193 , V_22 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_79 ( & V_164 , V_176 , V_158 , F_101 ,
V_22 , F_87 ( V_22 , V_186 ) ) ;
F_93 ( V_193 , 0 , V_29 + 2 , V_152 , & V_164 ) ;
}
static void F_104 ( void * V_172 )
{
struct V_21 * V_22 = V_172 ;
F_38 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
V_22 -> V_35 = V_214 ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
F_32 ( V_22 ) ;
}
static void F_105 ( struct V_21 * V_22 , struct V_185 * V_186 )
{
int V_25 = V_22 -> V_25 ;
int V_32 = V_22 -> V_32 ;
int V_24 = V_22 -> V_24 ;
struct V_67 * V_189 ;
struct V_67 * * V_188 = V_186 -> V_187 ;
struct V_156 * V_158 ;
struct V_163 V_164 ;
int V_29 ;
int V_69 ;
F_38 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
V_29 = 0 ;
V_189 = V_22 -> V_72 [ V_32 ] . V_67 ;
V_188 [ V_29 ++ ] = V_189 ;
for ( V_69 = V_25 ; V_69 -- ; ) {
if ( V_69 == V_32 || V_69 == V_24 )
continue;
V_188 [ V_29 ++ ] = V_22 -> V_72 [ V_69 ] . V_67 ;
}
F_79 ( & V_164 , 0 , NULL , NULL , NULL ,
F_87 ( V_22 , V_186 ) ) ;
V_158 = F_106 ( V_189 , V_188 , 0 , V_29 , V_152 ,
& V_22 -> V_181 . V_215 , & V_164 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_79 ( & V_164 , V_176 , V_158 , F_104 , V_22 , NULL ) ;
V_158 = F_84 ( & V_164 ) ;
}
static void F_107 ( struct V_21 * V_22 , struct V_185 * V_186 , int V_216 )
{
struct V_67 * * V_191 = V_186 -> V_187 ;
struct V_163 V_164 ;
int V_29 ;
F_38 ( L_16 , V_142 ,
( unsigned long long ) V_22 -> V_10 , V_216 ) ;
V_29 = F_91 ( V_191 , V_22 ) ;
if ( ! V_216 )
V_191 [ V_29 ] = NULL ;
F_8 ( & V_22 -> V_29 ) ;
F_79 ( & V_164 , V_176 , NULL , F_104 ,
V_22 , F_87 ( V_22 , V_186 ) ) ;
F_108 ( V_191 , 0 , V_29 + 2 , V_152 ,
& V_22 -> V_181 . V_215 , V_186 -> V_217 , & V_164 ) ;
}
static void F_109 ( struct V_21 * V_22 , unsigned long V_218 )
{
int V_219 = 0 , V_69 , V_25 = V_22 -> V_25 ;
struct V_156 * V_158 = NULL ;
struct V_2 * V_3 = V_22 -> V_59 ;
int V_220 = V_3 -> V_220 ;
struct V_185 * V_186 ;
unsigned long V_221 ;
V_221 = F_110 () ;
V_186 = F_111 ( V_3 -> V_186 , V_221 ) ;
if ( F_19 ( V_222 , & V_218 ) ) {
F_83 ( V_22 ) ;
V_219 ++ ;
}
if ( F_19 ( V_223 , & V_218 ) ) {
if ( V_220 < 6 )
V_158 = F_88 ( V_22 , V_186 ) ;
else {
if ( V_22 -> V_181 . V_182 < 0 || V_22 -> V_181 . V_177 < 0 )
V_158 = F_92 ( V_22 , V_186 ) ;
else
V_158 = F_94 ( V_22 , V_186 ) ;
}
if ( V_158 && ! F_19 ( V_224 , & V_218 ) )
F_112 ( V_158 ) ;
}
if ( F_19 ( V_225 , & V_218 ) )
V_158 = F_99 ( V_22 , V_186 , V_158 ) ;
if ( F_19 ( V_226 , & V_218 ) ) {
V_158 = F_100 ( V_22 , V_158 ) ;
V_219 ++ ;
}
if ( F_19 ( V_224 , & V_218 ) ) {
if ( V_220 < 6 )
F_102 ( V_22 , V_186 , V_158 ) ;
else
F_103 ( V_22 , V_186 , V_158 ) ;
}
if ( F_19 ( V_227 , & V_218 ) ) {
if ( V_22 -> V_35 == V_228 )
F_105 ( V_22 , V_186 ) ;
else if ( V_22 -> V_35 == V_229 )
F_107 ( V_22 , V_186 , 0 ) ;
else if ( V_22 -> V_35 == V_230 )
F_107 ( V_22 , V_186 , 1 ) ;
else
F_64 () ;
}
if ( V_219 )
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( F_26 ( V_231 , & V_72 -> V_60 ) )
F_29 ( & V_22 -> V_59 -> V_232 ) ;
}
F_113 () ;
}
static void F_114 ( void * V_233 , T_4 V_234 )
{
struct V_21 * V_22 = V_233 ;
unsigned long V_218 = V_22 -> V_181 . V_235 ;
F_115 ( V_236 , & V_22 -> V_38 ) ;
F_29 ( & V_22 -> V_181 . V_237 ) ;
F_109 ( V_22 , V_218 ) ;
F_32 ( V_22 ) ;
}
static void F_116 ( struct V_21 * V_22 , unsigned long V_218 )
{
F_117 ( V_22 -> V_181 . V_237 ,
! F_118 ( V_236 , & V_22 -> V_38 ) ) ;
V_22 -> V_181 . V_235 = V_218 ;
F_8 ( & V_22 -> V_29 ) ;
F_119 ( F_114 , V_22 ) ;
}
static int F_120 ( struct V_2 * V_3 )
{
struct V_21 * V_22 ;
V_22 = F_121 ( V_3 -> V_238 , V_73 ) ;
if ( ! V_22 )
return 0 ;
V_22 -> V_59 = V_3 ;
#ifdef F_122
F_123 ( & V_22 -> V_181 . V_237 ) ;
#endif
F_124 ( & V_22 -> V_175 ) ;
if ( F_47 ( V_22 ) ) {
F_45 ( V_22 ) ;
F_125 ( V_3 -> V_238 , V_22 ) ;
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
struct V_239 * V_240 ;
int V_241 = F_128 ( V_3 -> V_27 , V_3 -> V_76 ) ;
if ( V_3 -> V_51 -> V_242 )
sprintf ( V_3 -> V_243 [ 0 ] ,
L_17 , V_3 -> V_220 , F_129 ( V_3 -> V_51 ) ) ;
else
sprintf ( V_3 -> V_243 [ 0 ] ,
L_18 , V_3 -> V_220 , V_3 -> V_51 ) ;
sprintf ( V_3 -> V_243 [ 1 ] , L_19 , V_3 -> V_243 [ 0 ] ) ;
V_3 -> V_244 = 0 ;
V_240 = F_130 ( V_3 -> V_243 [ V_3 -> V_244 ] ,
sizeof( struct V_21 ) + ( V_241 - 1 ) * sizeof( struct V_77 ) ,
0 , 0 , NULL ) ;
if ( ! V_240 )
return 1 ;
V_3 -> V_238 = V_240 ;
V_3 -> V_71 = V_241 ;
while ( V_70 -- )
if ( ! F_120 ( V_3 ) )
return 1 ;
return 0 ;
}
static T_5 F_131 ( int V_70 )
{
T_5 V_167 ;
V_167 = sizeof( struct V_67 * ) * ( V_70 + 2 ) + sizeof( T_3 ) * ( V_70 + 2 ) ;
return V_167 ;
}
static int F_132 ( struct V_2 * V_3 , int V_245 )
{
struct V_21 * V_246 , * V_247 ;
F_133 ( V_248 ) ;
struct V_249 * V_250 ;
unsigned long V_221 ;
int V_251 ;
struct V_239 * V_240 ;
int V_69 ;
if ( V_245 <= V_3 -> V_71 )
return 0 ;
V_251 = F_134 ( V_3 -> V_51 ) ;
if ( V_251 )
return V_251 ;
V_240 = F_130 ( V_3 -> V_243 [ 1 - V_3 -> V_244 ] ,
sizeof( struct V_21 ) + ( V_245 - 1 ) * sizeof( struct V_77 ) ,
0 , 0 , NULL ) ;
if ( ! V_240 )
return - V_252 ;
for ( V_69 = V_3 -> V_100 ; V_69 ; V_69 -- ) {
V_247 = F_121 ( V_240 , V_73 ) ;
if ( ! V_247 )
break;
V_247 -> V_59 = V_3 ;
#ifdef F_122
F_123 ( & V_247 -> V_181 . V_237 ) ;
#endif
F_124 ( & V_247 -> V_175 ) ;
F_135 ( & V_247 -> V_40 , & V_248 ) ;
}
if ( V_69 ) {
while ( ! F_22 ( & V_248 ) ) {
V_247 = F_43 ( V_248 . V_66 , struct V_21 , V_40 ) ;
F_136 ( & V_247 -> V_40 ) ;
F_125 ( V_240 , V_247 ) ;
}
F_137 ( V_240 ) ;
return - V_252 ;
}
F_138 (nsh, &newstripes, lru) {
F_62 ( & V_3 -> V_61 ) ;
F_63 ( V_3 -> V_57 ,
! F_22 ( & V_3 -> V_56 ) ,
V_3 -> V_61 ,
) ;
V_246 = F_42 ( V_3 ) ;
F_65 ( & V_3 -> V_61 ) ;
F_12 ( & V_247 -> V_29 , 1 ) ;
for( V_69 = 0 ; V_69 < V_3 -> V_71 ; V_69 ++ )
V_247 -> V_72 [ V_69 ] . V_67 = V_246 -> V_72 [ V_69 ] . V_67 ;
for( ; V_69 < V_245 ; V_69 ++ )
V_247 -> V_72 [ V_69 ] . V_67 = NULL ;
F_125 ( V_3 -> V_238 , V_246 ) ;
}
F_137 ( V_3 -> V_238 ) ;
V_250 = F_139 ( V_245 * sizeof( struct V_249 ) , V_253 ) ;
if ( V_250 ) {
for ( V_69 = 0 ; V_69 < V_3 -> V_27 ; V_69 ++ )
V_250 [ V_69 ] = V_3 -> V_25 [ V_69 ] ;
F_140 ( V_3 -> V_25 ) ;
V_3 -> V_25 = V_250 ;
} else
V_251 = - V_252 ;
F_141 () ;
V_3 -> F_131 = F_131 ( V_245 ) ;
F_142 (cpu) {
struct V_185 * V_186 ;
void * V_187 ;
V_186 = F_111 ( V_3 -> V_186 , V_221 ) ;
V_187 = F_143 ( V_3 -> F_131 , V_253 ) ;
if ( V_187 ) {
F_140 ( V_186 -> V_187 ) ;
V_186 -> V_187 = V_187 ;
} else {
V_251 = - V_252 ;
break;
}
}
F_144 () ;
while( ! F_22 ( & V_248 ) ) {
V_247 = F_43 ( V_248 . V_66 , struct V_21 , V_40 ) ;
F_44 ( & V_247 -> V_40 ) ;
for ( V_69 = V_3 -> V_27 ; V_69 < V_245 ; V_69 ++ )
if ( V_247 -> V_72 [ V_69 ] . V_67 == NULL ) {
struct V_67 * V_68 = F_48 ( V_253 ) ;
V_247 -> V_72 [ V_69 ] . V_67 = V_68 ;
if ( ! V_68 )
V_251 = - V_252 ;
}
F_32 ( V_247 ) ;
}
V_3 -> V_238 = V_240 ;
V_3 -> V_244 = 1 - V_3 -> V_244 ;
V_3 -> V_71 = V_245 ;
return V_251 ;
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
F_125 ( V_3 -> V_238 , V_22 ) ;
F_28 ( & V_3 -> V_41 ) ;
return 1 ;
}
static void F_146 ( struct V_2 * V_3 )
{
while ( F_145 ( V_3 ) )
;
if ( V_3 -> V_238 )
F_137 ( V_3 -> V_238 ) ;
V_3 -> V_238 = NULL ;
}
static void V_126 ( struct V_9 * V_34 , int error )
{
struct V_21 * V_22 = V_34 -> V_254 ;
struct V_2 * V_3 = V_22 -> V_59 ;
int V_25 = V_22 -> V_25 , V_69 ;
int V_255 = F_19 ( V_148 , & V_34 -> V_147 ) ;
char V_256 [ V_257 ] ;
struct V_88 * V_89 = NULL ;
T_1 V_105 ;
for ( V_69 = 0 ; V_69 < V_25 ; V_69 ++ )
if ( V_34 == & V_22 -> V_72 [ V_69 ] . V_121 )
break;
F_38 ( L_20 ,
( unsigned long long ) V_22 -> V_10 , V_69 , F_4 ( & V_22 -> V_29 ) ,
V_255 ) ;
if ( V_69 == V_25 ) {
F_64 () ;
return;
}
if ( F_19 ( V_127 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
V_89 = V_3 -> V_25 [ V_69 ] . V_91 ;
if ( ! V_89 )
V_89 = V_3 -> V_25 [ V_69 ] . V_89 ;
if ( F_66 ( V_3 , V_22 ) )
V_105 = V_22 -> V_10 + V_89 -> V_143 ;
else
V_105 = V_22 -> V_10 + V_89 -> V_144 ;
if ( V_255 ) {
F_72 ( V_179 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
if ( F_19 ( V_258 , & V_22 -> V_72 [ V_69 ] . V_60 ) ) {
F_147 (
V_259
L_21
L_22 ,
F_129 ( V_3 -> V_51 ) , V_14 ,
( unsigned long long ) V_105 ,
F_148 ( V_89 -> V_139 , V_256 ) ) ;
F_149 ( V_14 , & V_89 -> V_260 ) ;
F_24 ( V_258 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_24 ( V_261 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
} else if ( F_19 ( V_145 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
F_24 ( V_145 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
if ( F_4 ( & V_89 -> V_262 ) )
F_12 ( & V_89 -> V_262 , 0 ) ;
} else {
const char * V_263 = F_148 ( V_89 -> V_139 , V_256 ) ;
int V_264 = 0 ;
int V_265 = 0 ;
F_24 ( V_179 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_8 ( & V_89 -> V_262 ) ;
if ( F_19 ( V_127 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
F_147 (
V_266
L_23
L_24 ,
F_129 ( V_3 -> V_51 ) ,
( unsigned long long ) V_105 ,
V_263 ) ;
else if ( V_3 -> V_51 -> V_86 >= V_3 -> V_95 ) {
V_265 = 1 ;
F_147 (
V_266
L_25
L_24 ,
F_129 ( V_3 -> V_51 ) ,
( unsigned long long ) V_105 ,
V_263 ) ;
} else if ( F_19 ( V_261 , & V_22 -> V_72 [ V_69 ] . V_60 ) ) {
V_265 = 1 ;
F_147 (
V_266
L_26
L_24 ,
F_129 ( V_3 -> V_51 ) ,
( unsigned long long ) V_105 ,
V_263 ) ;
} else if ( F_4 ( & V_89 -> V_262 )
> V_3 -> V_100 )
F_51 ( V_266
L_27 ,
F_129 ( V_3 -> V_51 ) , V_263 ) ;
else
V_264 = 1 ;
if ( V_264 )
if ( F_19 ( V_145 , & V_22 -> V_72 [ V_69 ] . V_60 ) ) {
F_72 ( V_258 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_24 ( V_145 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
} else
F_72 ( V_145 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
else {
F_24 ( V_258 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_24 ( V_261 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
if ( ! ( V_265
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
static void V_125 ( struct V_9 * V_34 , int error )
{
struct V_21 * V_22 = V_34 -> V_254 ;
struct V_2 * V_3 = V_22 -> V_59 ;
int V_25 = V_22 -> V_25 , V_69 ;
struct V_88 * V_267 ( V_89 ) ;
int V_255 = F_19 ( V_148 , & V_34 -> V_147 ) ;
T_1 V_130 ;
int V_131 ;
int V_91 = 0 ;
for ( V_69 = 0 ; V_69 < V_25 ; V_69 ++ ) {
if ( V_34 == & V_22 -> V_72 [ V_69 ] . V_121 ) {
V_89 = V_3 -> V_25 [ V_69 ] . V_89 ;
break;
}
if ( V_34 == & V_22 -> V_72 [ V_69 ] . V_122 ) {
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
V_255 ) ;
if ( V_69 == V_25 ) {
F_64 () ;
return;
}
if ( V_91 ) {
if ( ! V_255 )
F_151 ( V_3 -> V_51 , V_89 ) ;
else if ( F_71 ( V_89 , V_22 -> V_10 ,
V_14 ,
& V_130 , & V_131 ) )
F_72 ( V_268 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
} else {
if ( ! V_255 ) {
F_72 ( V_129 , & V_89 -> V_60 ) ;
F_72 ( V_269 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
if ( ! F_152 ( V_270 , & V_89 -> V_60 ) )
F_72 ( V_271 ,
& V_89 -> V_51 -> V_272 ) ;
} else if ( F_71 ( V_89 , V_22 -> V_10 ,
V_14 ,
& V_130 , & V_131 ) )
F_72 ( V_273 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
}
F_75 ( V_89 , V_3 -> V_51 ) ;
if ( ! F_26 ( V_154 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
F_24 ( V_82 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
F_32 ( V_22 ) ;
}
static void F_53 ( struct V_21 * V_22 , int V_69 , int V_74 )
{
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
F_153 ( & V_72 -> V_121 ) ;
V_72 -> V_121 . V_150 = & V_72 -> V_274 ;
V_72 -> V_121 . V_275 ++ ;
V_72 -> V_121 . V_276 ++ ;
V_72 -> V_121 . V_254 = V_22 ;
V_72 -> V_274 . V_170 = V_72 -> V_67 ;
F_153 ( & V_72 -> V_122 ) ;
V_72 -> V_122 . V_150 = & V_72 -> V_277 ;
V_72 -> V_122 . V_275 ++ ;
V_72 -> V_122 . V_276 ++ ;
V_72 -> V_122 . V_254 = V_22 ;
V_72 -> V_277 . V_170 = V_72 -> V_67 ;
V_72 -> V_60 = 0 ;
V_72 -> V_10 = F_154 ( V_22 , V_69 , V_74 ) ;
}
static void error ( struct V_51 * V_51 , struct V_88 * V_89 )
{
char V_256 [ V_257 ] ;
struct V_2 * V_3 = V_51 -> V_278 ;
unsigned long V_60 ;
F_38 ( L_29 ) ;
F_155 ( & V_3 -> V_61 , V_60 ) ;
F_24 ( V_92 , & V_89 -> V_60 ) ;
V_51 -> V_86 = F_56 ( V_3 ) ;
F_156 ( & V_3 -> V_61 , V_60 ) ;
F_72 ( V_279 , & V_51 -> V_272 ) ;
F_72 ( V_280 , & V_89 -> V_60 ) ;
F_72 ( V_90 , & V_89 -> V_60 ) ;
F_72 ( V_281 , & V_51 -> V_60 ) ;
F_51 ( V_282
L_30
L_31 ,
F_129 ( V_51 ) ,
F_148 ( V_89 -> V_139 , V_256 ) ,
F_129 ( V_51 ) ,
V_3 -> V_27 - V_51 -> V_86 ) ;
}
static T_1 F_157 ( struct V_2 * V_3 , T_1 V_283 ,
int V_74 , int * V_284 ,
struct V_21 * V_22 )
{
T_1 V_285 , V_286 ;
T_1 V_287 ;
unsigned int V_288 ;
int V_32 , V_24 ;
int V_23 = 0 ;
T_1 V_289 ;
int V_290 = V_74 ? V_3 -> V_291
: V_3 -> V_290 ;
int V_292 = V_74 ? V_3 -> V_293
: V_3 -> V_294 ;
int V_27 = V_74 ? V_3 -> V_76
: V_3 -> V_27 ;
int V_295 = V_27 - V_3 -> V_95 ;
V_288 = F_158 ( V_283 , V_292 ) ;
V_287 = V_283 ;
V_285 = V_287 ;
* V_284 = F_158 ( V_285 , V_295 ) ;
V_286 = V_285 ;
V_32 = V_24 = - 1 ;
switch( V_3 -> V_220 ) {
case 4 :
V_32 = V_295 ;
break;
case 5 :
switch ( V_290 ) {
case V_296 :
V_32 = V_295 - F_158 ( V_286 , V_27 ) ;
if ( * V_284 >= V_32 )
( * V_284 ) ++ ;
break;
case V_297 :
V_32 = F_158 ( V_286 , V_27 ) ;
if ( * V_284 >= V_32 )
( * V_284 ) ++ ;
break;
case V_298 :
V_32 = V_295 - F_158 ( V_286 , V_27 ) ;
* V_284 = ( V_32 + 1 + * V_284 ) % V_27 ;
break;
case V_299 :
V_32 = F_158 ( V_286 , V_27 ) ;
* V_284 = ( V_32 + 1 + * V_284 ) % V_27 ;
break;
case V_300 :
V_32 = 0 ;
( * V_284 ) ++ ;
break;
case V_301 :
V_32 = V_295 ;
break;
default:
F_64 () ;
}
break;
case 6 :
switch ( V_290 ) {
case V_296 :
V_32 = V_27 - 1 - F_158 ( V_286 , V_27 ) ;
V_24 = V_32 + 1 ;
if ( V_32 == V_27 - 1 ) {
( * V_284 ) ++ ;
V_24 = 0 ;
} else if ( * V_284 >= V_32 )
( * V_284 ) += 2 ;
break;
case V_297 :
V_32 = F_158 ( V_286 , V_27 ) ;
V_24 = V_32 + 1 ;
if ( V_32 == V_27 - 1 ) {
( * V_284 ) ++ ;
V_24 = 0 ;
} else if ( * V_284 >= V_32 )
( * V_284 ) += 2 ;
break;
case V_298 :
V_32 = V_27 - 1 - F_158 ( V_286 , V_27 ) ;
V_24 = ( V_32 + 1 ) % V_27 ;
* V_284 = ( V_32 + 2 + * V_284 ) % V_27 ;
break;
case V_299 :
V_32 = F_158 ( V_286 , V_27 ) ;
V_24 = ( V_32 + 1 ) % V_27 ;
* V_284 = ( V_32 + 2 + * V_284 ) % V_27 ;
break;
case V_300 :
V_32 = 0 ;
V_24 = 1 ;
( * V_284 ) += 2 ;
break;
case V_301 :
V_32 = V_295 ;
V_24 = V_295 + 1 ;
break;
case V_302 :
V_32 = F_158 ( V_286 , V_27 ) ;
V_24 = V_32 + 1 ;
if ( V_32 == V_27 - 1 ) {
( * V_284 ) ++ ;
V_24 = 0 ;
} else if ( * V_284 >= V_32 )
( * V_284 ) += 2 ;
V_23 = 1 ;
break;
case V_303 :
V_286 += 1 ;
V_32 = V_27 - 1 - F_158 ( V_286 , V_27 ) ;
V_24 = V_32 + 1 ;
if ( V_32 == V_27 - 1 ) {
( * V_284 ) ++ ;
V_24 = 0 ;
} else if ( * V_284 >= V_32 )
( * V_284 ) += 2 ;
V_23 = 1 ;
break;
case V_304 :
V_32 = V_27 - 1 - F_158 ( V_286 , V_27 ) ;
V_24 = ( V_32 + V_27 - 1 ) % V_27 ;
* V_284 = ( V_32 + 1 + * V_284 ) % V_27 ;
V_23 = 1 ;
break;
case V_305 :
V_32 = V_295 - F_158 ( V_286 , V_27 - 1 ) ;
if ( * V_284 >= V_32 )
( * V_284 ) ++ ;
V_24 = V_27 - 1 ;
break;
case V_306 :
V_32 = F_158 ( V_286 , V_27 - 1 ) ;
if ( * V_284 >= V_32 )
( * V_284 ) ++ ;
V_24 = V_27 - 1 ;
break;
case V_307 :
V_32 = V_295 - F_158 ( V_286 , V_27 - 1 ) ;
* V_284 = ( V_32 + 1 + * V_284 ) % ( V_27 - 1 ) ;
V_24 = V_27 - 1 ;
break;
case V_308 :
V_32 = F_158 ( V_286 , V_27 - 1 ) ;
* V_284 = ( V_32 + 1 + * V_284 ) % ( V_27 - 1 ) ;
V_24 = V_27 - 1 ;
break;
case V_309 :
V_32 = 0 ;
( * V_284 ) ++ ;
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
V_289 = ( T_1 ) V_285 * V_292 + V_288 ;
return V_289 ;
}
static T_1 F_154 ( struct V_21 * V_22 , int V_69 , int V_74 )
{
struct V_2 * V_3 = V_22 -> V_59 ;
int V_27 = V_22 -> V_25 ;
int V_295 = V_27 - V_3 -> V_95 ;
T_1 V_289 = V_22 -> V_10 , V_310 ;
int V_292 = V_74 ? V_3 -> V_293
: V_3 -> V_294 ;
int V_290 = V_74 ? V_3 -> V_291
: V_3 -> V_290 ;
T_1 V_285 ;
int V_288 ;
T_1 V_287 ;
int V_311 , V_284 = V_69 ;
T_1 V_283 ;
struct V_21 V_312 ;
V_288 = F_158 ( V_289 , V_292 ) ;
V_285 = V_289 ;
if ( V_69 == V_22 -> V_32 )
return 0 ;
switch( V_3 -> V_220 ) {
case 4 : break;
case 5 :
switch ( V_290 ) {
case V_296 :
case V_297 :
if ( V_69 > V_22 -> V_32 )
V_69 -- ;
break;
case V_298 :
case V_299 :
if ( V_69 < V_22 -> V_32 )
V_69 += V_27 ;
V_69 -= ( V_22 -> V_32 + 1 ) ;
break;
case V_300 :
V_69 -= 1 ;
break;
case V_301 :
break;
default:
F_64 () ;
}
break;
case 6 :
if ( V_69 == V_22 -> V_24 )
return 0 ;
switch ( V_290 ) {
case V_296 :
case V_297 :
case V_302 :
case V_303 :
if ( V_22 -> V_32 == V_27 - 1 )
V_69 -- ;
else if ( V_69 > V_22 -> V_32 )
V_69 -= 2 ;
break;
case V_298 :
case V_299 :
if ( V_22 -> V_32 == V_27 - 1 )
V_69 -- ;
else {
if ( V_69 < V_22 -> V_32 )
V_69 += V_27 ;
V_69 -= ( V_22 -> V_32 + 2 ) ;
}
break;
case V_300 :
V_69 -= 2 ;
break;
case V_301 :
break;
case V_304 :
if ( V_22 -> V_32 == 0 )
V_69 -- ;
else {
if ( V_69 < V_22 -> V_32 )
V_69 += V_27 ;
V_69 -= ( V_22 -> V_32 + 1 ) ;
}
break;
case V_305 :
case V_306 :
if ( V_69 > V_22 -> V_32 )
V_69 -- ;
break;
case V_307 :
case V_308 :
if ( V_69 < V_22 -> V_32 )
V_69 += V_295 + 1 ;
V_69 -= ( V_22 -> V_32 + 1 ) ;
break;
case V_309 :
V_69 -= 1 ;
break;
default:
F_64 () ;
}
break;
}
V_287 = V_285 * V_295 + V_69 ;
V_283 = V_287 * V_292 + V_288 ;
V_310 = F_157 ( V_3 , V_283 ,
V_74 , & V_311 , & V_312 ) ;
if ( V_310 != V_22 -> V_10 || V_311 != V_284 || V_312 . V_32 != V_22 -> V_32
|| V_312 . V_24 != V_22 -> V_24 ) {
F_51 ( V_83 L_32 ,
F_129 ( V_3 -> V_51 ) ) ;
return 0 ;
}
return V_283 ;
}
static void
F_159 ( struct V_21 * V_22 , struct V_104 * V_105 ,
int V_313 , int V_314 )
{
int V_69 , V_32 = V_22 -> V_32 , V_25 = V_22 -> V_25 ;
struct V_2 * V_3 = V_22 -> V_59 ;
int V_220 = V_3 -> V_220 ;
if ( V_313 ) {
if ( ! V_314 ) {
V_22 -> V_36 = V_207 ;
F_72 ( V_226 , & V_105 -> V_218 ) ;
} else
V_22 -> V_36 = V_211 ;
F_72 ( V_224 , & V_105 -> V_218 ) ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( V_72 -> V_80 ) {
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_72 ( V_199 , & V_72 -> V_60 ) ;
if ( ! V_314 )
F_24 ( V_179 , & V_72 -> V_60 ) ;
V_105 -> V_315 ++ ;
}
}
if ( V_105 -> V_315 + V_3 -> V_95 == V_25 )
if ( ! F_152 ( V_316 , & V_22 -> V_38 ) )
F_8 ( & V_3 -> V_317 ) ;
} else {
F_21 ( V_220 == 6 ) ;
F_21 ( ! ( F_19 ( V_179 , & V_22 -> V_72 [ V_32 ] . V_60 ) ||
F_19 ( V_180 , & V_22 -> V_72 [ V_32 ] . V_60 ) ) ) ;
V_22 -> V_36 = V_209 ;
F_72 ( V_225 , & V_105 -> V_218 ) ;
F_72 ( V_226 , & V_105 -> V_218 ) ;
F_72 ( V_224 , & V_105 -> V_218 ) ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( V_69 == V_32 )
continue;
if ( V_72 -> V_80 &&
( F_19 ( V_179 , & V_72 -> V_60 ) ||
F_19 ( V_180 , & V_72 -> V_60 ) ) ) {
F_72 ( V_199 , & V_72 -> V_60 ) ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_24 ( V_179 , & V_72 -> V_60 ) ;
V_105 -> V_315 ++ ;
}
}
}
F_72 ( V_82 , & V_22 -> V_72 [ V_32 ] . V_60 ) ;
F_24 ( V_179 , & V_22 -> V_72 [ V_32 ] . V_60 ) ;
V_105 -> V_315 ++ ;
if ( V_220 == 6 ) {
int V_24 = V_22 -> V_24 ;
struct V_77 * V_72 = & V_22 -> V_72 [ V_24 ] ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_24 ( V_179 , & V_72 -> V_60 ) ;
V_105 -> V_315 ++ ;
}
F_38 ( L_33 ,
V_142 , ( unsigned long long ) V_22 -> V_10 ,
V_105 -> V_315 , V_105 -> V_218 ) ;
}
static int F_160 ( struct V_21 * V_22 , struct V_9 * V_34 , int V_284 , int V_318 )
{
struct V_9 * * V_319 ;
struct V_2 * V_3 = V_22 -> V_59 ;
int V_320 = 0 ;
F_38 ( L_34 ,
( unsigned long long ) V_34 -> V_13 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_62 ( & V_22 -> V_175 ) ;
if ( V_318 ) {
V_319 = & V_22 -> V_72 [ V_284 ] . V_80 ;
if ( * V_319 == NULL )
V_320 = 1 ;
} else
V_319 = & V_22 -> V_72 [ V_284 ] . V_78 ;
while ( * V_319 && ( * V_319 ) -> V_13 < V_34 -> V_13 ) {
if ( ( * V_319 ) -> V_13 + ( ( * V_319 ) -> V_12 >> 9 ) > V_34 -> V_13 )
goto V_321;
V_319 = & ( * V_319 ) -> V_15 ;
}
if ( * V_319 && ( * V_319 ) -> V_13 < V_34 -> V_13 + ( ( V_34 -> V_12 ) >> 9 ) )
goto V_321;
F_21 ( * V_319 && V_34 -> V_15 && ( * V_319 ) != V_34 -> V_15 ) ;
if ( * V_319 )
V_34 -> V_15 = * V_319 ;
* V_319 = V_34 ;
F_7 ( V_34 ) ;
if ( V_318 ) {
T_1 V_10 = V_22 -> V_72 [ V_284 ] . V_10 ;
for ( V_34 = V_22 -> V_72 [ V_284 ] . V_80 ;
V_10 < V_22 -> V_72 [ V_284 ] . V_10 + V_14 &&
V_34 && V_34 -> V_13 <= V_10 ;
V_34 = F_2 ( V_34 , V_22 -> V_72 [ V_284 ] . V_10 ) ) {
if ( V_34 -> V_13 + ( V_34 -> V_12 >> 9 ) >= V_10 )
V_10 = V_34 -> V_13 + ( V_34 -> V_12 >> 9 ) ;
}
if ( V_10 >= V_22 -> V_72 [ V_284 ] . V_10 + V_14 )
F_72 ( V_322 , & V_22 -> V_72 [ V_284 ] . V_60 ) ;
}
F_38 ( L_35 ,
( unsigned long long ) ( * V_319 ) -> V_13 ,
( unsigned long long ) V_22 -> V_10 , V_284 ) ;
F_65 ( & V_22 -> V_175 ) ;
if ( V_3 -> V_51 -> V_323 && V_320 ) {
F_161 ( V_3 -> V_51 -> V_323 , V_22 -> V_10 ,
V_14 , 0 ) ;
V_22 -> V_47 = V_3 -> V_324 + 1 ;
F_72 ( V_46 , & V_22 -> V_38 ) ;
}
return 1 ;
V_321:
F_72 ( V_231 , & V_22 -> V_72 [ V_284 ] . V_60 ) ;
F_65 ( & V_22 -> V_175 ) ;
return 0 ;
}
static void F_50 ( T_1 V_285 , struct V_2 * V_3 , int V_74 ,
struct V_21 * V_22 )
{
int V_292 =
V_74 ? V_3 -> V_293 : V_3 -> V_294 ;
int V_284 ;
int V_288 = F_158 ( V_285 , V_292 ) ;
int V_25 = V_74 ? V_3 -> V_76 : V_3 -> V_27 ;
F_157 ( V_3 ,
V_285 * ( V_25 - V_3 -> V_95 )
* V_292 + V_288 ,
V_74 ,
& V_284 , V_22 ) ;
}
static void
F_162 ( struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_104 * V_105 , int V_25 ,
struct V_9 * * V_33 )
{
int V_69 ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_9 * V_34 ;
int V_325 = 0 ;
if ( F_19 ( V_258 , & V_22 -> V_72 [ V_69 ] . V_60 ) ) {
struct V_88 * V_89 ;
F_57 () ;
V_89 = F_58 ( V_3 -> V_25 [ V_69 ] . V_89 ) ;
if ( V_89 && F_19 ( V_92 , & V_89 -> V_60 ) )
F_8 ( & V_89 -> V_128 ) ;
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
F_62 ( & V_22 -> V_175 ) ;
V_34 = V_22 -> V_72 [ V_69 ] . V_80 ;
V_22 -> V_72 [ V_69 ] . V_80 = NULL ;
F_65 ( & V_22 -> V_175 ) ;
if ( V_34 )
V_325 = 1 ;
if ( F_26 ( V_231 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
F_29 ( & V_3 -> V_232 ) ;
while ( V_34 && V_34 -> V_13 <
V_22 -> V_72 [ V_69 ] . V_10 + V_14 ) {
struct V_9 * V_326 = F_2 ( V_34 , V_22 -> V_72 [ V_69 ] . V_10 ) ;
F_24 ( V_148 , & V_34 -> V_147 ) ;
if ( ! F_5 ( V_34 ) ) {
F_163 ( V_3 -> V_51 ) ;
V_34 -> V_15 = * V_33 ;
* V_33 = V_34 ;
}
V_34 = V_326 ;
}
if ( V_325 )
F_164 ( V_3 -> V_51 -> V_323 , V_22 -> V_10 ,
V_14 , 0 , 0 ) ;
V_325 = 0 ;
V_34 = V_22 -> V_72 [ V_69 ] . V_81 ;
V_22 -> V_72 [ V_69 ] . V_81 = NULL ;
if ( V_34 ) V_325 = 1 ;
while ( V_34 && V_34 -> V_13 <
V_22 -> V_72 [ V_69 ] . V_10 + V_14 ) {
struct V_9 * V_327 = F_2 ( V_34 , V_22 -> V_72 [ V_69 ] . V_10 ) ;
F_24 ( V_148 , & V_34 -> V_147 ) ;
if ( ! F_5 ( V_34 ) ) {
F_163 ( V_3 -> V_51 ) ;
V_34 -> V_15 = * V_33 ;
* V_33 = V_34 ;
}
V_34 = V_327 ;
}
if ( ! F_19 ( V_173 , & V_22 -> V_72 [ V_69 ] . V_60 ) &&
( ! F_19 ( V_328 , & V_22 -> V_72 [ V_69 ] . V_60 ) ||
F_19 ( V_258 , & V_22 -> V_72 [ V_69 ] . V_60 ) ) ) {
F_62 ( & V_22 -> V_175 ) ;
V_34 = V_22 -> V_72 [ V_69 ] . V_78 ;
V_22 -> V_72 [ V_69 ] . V_78 = NULL ;
F_65 ( & V_22 -> V_175 ) ;
if ( F_26 ( V_231 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
F_29 ( & V_3 -> V_232 ) ;
while ( V_34 && V_34 -> V_13 <
V_22 -> V_72 [ V_69 ] . V_10 + V_14 ) {
struct V_9 * V_326 =
F_2 ( V_34 , V_22 -> V_72 [ V_69 ] . V_10 ) ;
F_24 ( V_148 , & V_34 -> V_147 ) ;
if ( ! F_5 ( V_34 ) ) {
V_34 -> V_15 = * V_33 ;
* V_33 = V_34 ;
}
V_34 = V_326 ;
}
}
if ( V_325 )
F_164 ( V_3 -> V_51 -> V_323 , V_22 -> V_10 ,
V_14 , 0 , 0 ) ;
F_24 ( V_82 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
}
if ( F_26 ( V_316 , & V_22 -> V_38 ) )
if ( F_31 ( & V_3 -> V_317 ) )
F_25 ( V_3 -> V_51 -> V_52 ) ;
}
static void
F_165 ( struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_104 * V_105 )
{
int abort = 0 ;
int V_69 ;
F_24 ( V_329 , & V_22 -> V_38 ) ;
V_105 -> V_135 = 0 ;
V_105 -> V_138 = 0 ;
if ( F_19 ( V_330 , & V_3 -> V_51 -> V_272 ) ) {
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
V_3 -> V_331 =
V_3 -> V_51 -> V_331 ;
}
F_166 ( V_3 -> V_51 , V_14 , ! abort ) ;
}
static int F_167 ( struct V_21 * V_22 , int V_332 )
{
struct V_88 * V_89 ;
int V_333 = 0 ;
V_89 = V_22 -> V_59 -> V_25 [ V_332 ] . V_91 ;
if ( V_89
&& ! F_19 ( V_90 , & V_89 -> V_60 )
&& ! F_19 ( V_92 , & V_89 -> V_60 )
&& ( V_89 -> V_334 <= V_22 -> V_10
|| V_89 -> V_51 -> V_335 <= V_22 -> V_10 ) )
V_333 = 1 ;
return V_333 ;
}
static int F_168 ( struct V_21 * V_22 , struct V_104 * V_105 ,
int V_332 , int V_25 )
{
struct V_77 * V_72 = & V_22 -> V_72 [ V_332 ] ;
struct V_77 * V_336 [ 2 ] = { & V_22 -> V_72 [ V_105 -> V_337 [ 0 ] ] ,
& V_22 -> V_72 [ V_105 -> V_337 [ 1 ] ] } ;
if ( ! F_19 ( V_82 , & V_72 -> V_60 ) &&
! F_19 ( V_179 , & V_72 -> V_60 ) &&
( V_72 -> V_78 ||
( V_72 -> V_80 && ! F_19 ( V_322 , & V_72 -> V_60 ) ) ||
V_105 -> V_135 || V_105 -> V_136 ||
( V_105 -> V_138 && F_167 ( V_22 , V_332 ) ) ||
( V_105 -> V_338 >= 1 && V_336 [ 0 ] -> V_78 ) ||
( V_105 -> V_338 >= 2 && V_336 [ 1 ] -> V_78 ) ||
( V_22 -> V_59 -> V_220 <= 5 && V_105 -> V_338 && V_336 [ 0 ] -> V_80 &&
! F_19 ( V_322 , & V_336 [ 0 ] -> V_60 ) ) ||
( V_22 -> V_59 -> V_220 == 6 && V_105 -> V_338 && V_105 -> V_339 ) ) ) {
F_21 ( F_19 ( V_180 , & V_72 -> V_60 ) ) ;
F_21 ( F_19 ( V_116 , & V_72 -> V_60 ) ) ;
if ( ( V_105 -> V_255 == V_25 - 1 ) &&
( V_105 -> V_338 && ( V_332 == V_105 -> V_337 [ 0 ] ||
V_332 == V_105 -> V_337 [ 1 ] ) ) ) {
F_38 ( L_36 ,
( unsigned long long ) V_22 -> V_10 , V_332 ) ;
F_72 ( V_39 , & V_22 -> V_38 ) ;
F_72 ( V_223 , & V_105 -> V_218 ) ;
F_72 ( V_180 , & V_72 -> V_60 ) ;
V_22 -> V_181 . V_177 = V_332 ;
V_22 -> V_181 . V_182 = - 1 ;
V_105 -> V_340 = 1 ;
V_105 -> V_255 ++ ;
return 1 ;
} else if ( V_105 -> V_255 == V_25 - 2 && V_105 -> V_338 >= 2 ) {
int V_341 ;
for ( V_341 = V_25 ; V_341 -- ; ) {
if ( V_341 == V_332 )
continue;
if ( ! F_19 ( V_179 ,
& V_22 -> V_72 [ V_341 ] . V_60 ) )
break;
}
F_21 ( V_341 < 0 ) ;
F_38 ( L_37 ,
( unsigned long long ) V_22 -> V_10 ,
V_332 , V_341 ) ;
F_72 ( V_39 , & V_22 -> V_38 ) ;
F_72 ( V_223 , & V_105 -> V_218 ) ;
F_72 ( V_180 , & V_22 -> V_72 [ V_332 ] . V_60 ) ;
F_72 ( V_180 , & V_22 -> V_72 [ V_341 ] . V_60 ) ;
V_22 -> V_181 . V_177 = V_332 ;
V_22 -> V_181 . V_182 = V_341 ;
V_105 -> V_255 += 2 ;
V_105 -> V_340 = 1 ;
return 1 ;
} else if ( F_19 ( V_328 , & V_72 -> V_60 ) ) {
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_72 ( V_116 , & V_72 -> V_60 ) ;
V_105 -> V_315 ++ ;
F_38 ( L_38 ,
V_332 , V_105 -> V_135 ) ;
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
( F_19 ( V_179 , & V_72 -> V_60 ) ||
F_19 ( V_114 , & V_72 -> V_60 ) ) ) {
struct V_9 * V_202 , * V_342 ;
F_38 ( L_39 , V_69 ) ;
if ( F_26 ( V_114 , & V_72 -> V_60 ) )
F_24 ( V_179 , & V_72 -> V_60 ) ;
V_202 = V_72 -> V_81 ;
V_72 -> V_81 = NULL ;
while ( V_202 && V_202 -> V_13 <
V_72 -> V_10 + V_14 ) {
V_342 = F_2 ( V_202 , V_72 -> V_10 ) ;
if ( ! F_5 ( V_202 ) ) {
F_163 ( V_3 -> V_51 ) ;
V_202 -> V_15 = * V_33 ;
* V_33 = V_202 ;
}
V_202 = V_342 ;
}
F_164 ( V_3 -> V_51 -> V_323 , V_22 -> V_10 ,
V_14 ,
! F_19 ( V_155 , & V_22 -> V_38 ) ,
0 ) ;
}
} else if ( F_19 ( V_114 , & V_22 -> V_72 [ V_69 ] . V_60 ) )
F_24 ( V_114 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
if ( F_26 ( V_316 , & V_22 -> V_38 ) )
if ( F_31 ( & V_3 -> V_317 ) )
F_25 ( V_3 -> V_51 -> V_52 ) ;
}
static void F_171 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
struct V_104 * V_105 ,
int V_25 )
{
int V_343 = 0 , V_313 = 0 , V_69 ;
T_1 V_335 = V_3 -> V_51 -> V_335 ;
if ( V_3 -> V_95 == 2 ||
( V_335 < V_94 && V_22 -> V_10 >= V_335 ) ) {
V_313 = 1 ; V_343 = 2 ;
F_38 ( L_40 ,
V_3 -> V_95 , ( unsigned long long ) V_335 ,
( unsigned long long ) V_22 -> V_10 ) ;
} else for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( ( V_72 -> V_80 || V_69 == V_22 -> V_32 ) &&
! F_19 ( V_82 , & V_72 -> V_60 ) &&
! ( F_19 ( V_179 , & V_72 -> V_60 ) ||
F_19 ( V_180 , & V_72 -> V_60 ) ) ) {
if ( F_19 ( V_328 , & V_72 -> V_60 ) )
V_343 ++ ;
else
V_343 += 2 * V_25 ;
}
if ( ! F_19 ( V_322 , & V_72 -> V_60 ) && V_69 != V_22 -> V_32 &&
! F_19 ( V_82 , & V_72 -> V_60 ) &&
! ( F_19 ( V_179 , & V_72 -> V_60 ) ||
F_19 ( V_180 , & V_72 -> V_60 ) ) ) {
if ( F_19 ( V_328 , & V_72 -> V_60 ) ) V_313 ++ ;
else
V_313 += 2 * V_25 ;
}
}
F_38 ( L_41 ,
( unsigned long long ) V_22 -> V_10 , V_343 , V_313 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
if ( V_343 < V_313 && V_343 > 0 )
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( ( V_72 -> V_80 || V_69 == V_22 -> V_32 ) &&
! F_19 ( V_82 , & V_72 -> V_60 ) &&
! ( F_19 ( V_179 , & V_72 -> V_60 ) ||
F_19 ( V_180 , & V_72 -> V_60 ) ) &&
F_19 ( V_328 , & V_72 -> V_60 ) ) {
if (
F_19 ( V_44 , & V_22 -> V_38 ) ) {
F_38 ( L_42
L_43 , V_69 ) ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_72 ( V_116 , & V_72 -> V_60 ) ;
V_105 -> V_315 ++ ;
} else {
F_72 ( V_43 , & V_22 -> V_38 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
}
}
}
if ( V_313 <= V_343 && V_313 > 0 ) {
V_313 = 0 ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( ! F_19 ( V_322 , & V_72 -> V_60 ) &&
V_69 != V_22 -> V_32 && V_69 != V_22 -> V_24 &&
! F_19 ( V_82 , & V_72 -> V_60 ) &&
! ( F_19 ( V_179 , & V_72 -> V_60 ) ||
F_19 ( V_180 , & V_72 -> V_60 ) ) ) {
V_313 ++ ;
if ( ! F_19 ( V_328 , & V_72 -> V_60 ) )
continue;
if (
F_19 ( V_44 , & V_22 -> V_38 ) ) {
F_38 ( L_42
L_44 , V_69 ) ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_72 ( V_116 , & V_72 -> V_60 ) ;
V_105 -> V_315 ++ ;
} else {
F_72 ( V_43 , & V_22 -> V_38 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
}
}
}
}
if ( ( V_105 -> V_340 || ! F_19 ( V_39 , & V_22 -> V_38 ) ) &&
( V_105 -> V_315 == 0 && ( V_313 == 0 || V_343 == 0 ) &&
! F_19 ( V_46 , & V_22 -> V_38 ) ) )
F_159 ( V_22 , V_105 , V_313 == 0 , 0 ) ;
}
static void F_172 ( struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_104 * V_105 , int V_25 )
{
struct V_77 * V_72 = NULL ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
switch ( V_22 -> V_35 ) {
case V_344 :
if ( V_105 -> V_338 == 0 ) {
F_21 ( V_105 -> V_255 != V_25 ) ;
V_22 -> V_35 = V_228 ;
F_72 ( V_227 , & V_105 -> V_218 ) ;
F_24 ( V_179 , & V_22 -> V_72 [ V_22 -> V_32 ] . V_60 ) ;
V_105 -> V_255 -- ;
break;
}
V_72 = & V_22 -> V_72 [ V_105 -> V_337 [ 0 ] ] ;
case V_184 :
V_22 -> V_35 = V_344 ;
if ( ! V_72 )
V_72 = & V_22 -> V_72 [ V_22 -> V_32 ] ;
if ( F_19 ( V_345 , & V_22 -> V_38 ) )
break;
F_21 ( ! F_19 ( V_179 , & V_72 -> V_60 ) ) ;
F_21 ( V_105 -> V_255 != V_25 ) ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
V_105 -> V_315 ++ ;
F_72 ( V_110 , & V_72 -> V_60 ) ;
F_24 ( V_155 , & V_22 -> V_38 ) ;
F_72 ( V_345 , & V_22 -> V_38 ) ;
break;
case V_228 :
break;
case V_214 :
V_22 -> V_35 = V_344 ;
if ( V_105 -> V_338 )
break;
if ( ( V_22 -> V_181 . V_215 & V_346 ) == 0 )
F_72 ( V_345 , & V_22 -> V_38 ) ;
else {
F_173 ( V_14 , & V_3 -> V_51 -> V_347 ) ;
if ( F_19 ( V_348 , & V_3 -> V_51 -> V_272 ) )
F_72 ( V_345 , & V_22 -> V_38 ) ;
else {
V_22 -> V_35 = V_183 ;
F_72 ( V_39 , & V_22 -> V_38 ) ;
F_72 ( V_223 , & V_105 -> V_218 ) ;
F_72 ( V_180 ,
& V_22 -> V_72 [ V_22 -> V_32 ] . V_60 ) ;
V_22 -> V_181 . V_177 = V_22 -> V_32 ;
V_22 -> V_181 . V_182 = - 1 ;
V_105 -> V_255 ++ ;
}
}
break;
case V_183 :
break;
default:
F_51 ( V_83 L_45 ,
V_142 , V_22 -> V_35 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_64 () ;
}
}
static void F_174 ( struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_104 * V_105 ,
int V_25 )
{
int V_32 = V_22 -> V_32 ;
int V_24 = V_22 -> V_24 ;
struct V_77 * V_72 ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
F_21 ( V_105 -> V_338 > 2 ) ;
switch ( V_22 -> V_35 ) {
case V_344 :
if ( V_105 -> V_338 == V_105 -> V_349 ) {
V_22 -> V_35 = V_228 ;
}
if ( ! V_105 -> V_349 && V_105 -> V_338 < 2 ) {
if ( V_22 -> V_35 == V_228 )
V_22 -> V_35 = V_230 ;
else
V_22 -> V_35 = V_229 ;
}
V_22 -> V_181 . V_215 = 0 ;
if ( V_22 -> V_35 == V_228 ) {
F_24 ( V_179 , & V_22 -> V_72 [ V_32 ] . V_60 ) ;
V_105 -> V_255 -- ;
}
if ( V_22 -> V_35 >= V_228 &&
V_22 -> V_35 <= V_230 ) {
F_72 ( V_227 , & V_105 -> V_218 ) ;
break;
}
F_21 ( V_105 -> V_338 != 2 ) ;
case V_184 :
V_22 -> V_35 = V_344 ;
if ( F_19 ( V_345 , & V_22 -> V_38 ) )
break;
F_21 ( V_105 -> V_255 < V_25 - 1 ) ;
if ( V_105 -> V_338 == 2 ) {
V_72 = & V_22 -> V_72 [ V_105 -> V_337 [ 1 ] ] ;
V_105 -> V_315 ++ ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_72 ( V_110 , & V_72 -> V_60 ) ;
}
if ( V_105 -> V_338 >= 1 ) {
V_72 = & V_22 -> V_72 [ V_105 -> V_337 [ 0 ] ] ;
V_105 -> V_315 ++ ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_72 ( V_110 , & V_72 -> V_60 ) ;
}
if ( V_22 -> V_181 . V_215 & V_346 ) {
V_72 = & V_22 -> V_72 [ V_32 ] ;
V_105 -> V_315 ++ ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_72 ( V_110 , & V_72 -> V_60 ) ;
}
if ( V_22 -> V_181 . V_215 & V_350 ) {
V_72 = & V_22 -> V_72 [ V_24 ] ;
V_105 -> V_315 ++ ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
F_72 ( V_110 , & V_72 -> V_60 ) ;
}
F_24 ( V_155 , & V_22 -> V_38 ) ;
F_72 ( V_345 , & V_22 -> V_38 ) ;
break;
case V_228 :
case V_229 :
case V_230 :
break;
case V_214 :
V_22 -> V_35 = V_344 ;
if ( V_22 -> V_181 . V_215 == 0 ) {
if ( ! V_105 -> V_338 )
F_72 ( V_345 , & V_22 -> V_38 ) ;
else {
V_22 -> V_35 = V_184 ;
}
} else {
F_173 ( V_14 , & V_3 -> V_51 -> V_347 ) ;
if ( F_19 ( V_348 , & V_3 -> V_51 -> V_272 ) )
F_72 ( V_345 , & V_22 -> V_38 ) ;
else {
int * V_177 = & V_22 -> V_181 . V_177 ;
V_22 -> V_181 . V_177 = - 1 ;
V_22 -> V_181 . V_182 = - 1 ;
V_22 -> V_35 = V_183 ;
F_72 ( V_39 , & V_22 -> V_38 ) ;
F_72 ( V_223 , & V_105 -> V_218 ) ;
if ( V_22 -> V_181 . V_215 & V_346 ) {
F_72 ( V_180 ,
& V_22 -> V_72 [ V_32 ] . V_60 ) ;
* V_177 = V_32 ;
V_177 = & V_22 -> V_181 . V_182 ;
V_105 -> V_255 ++ ;
}
if ( V_22 -> V_181 . V_215 & V_350 ) {
F_72 ( V_180 ,
& V_22 -> V_72 [ V_24 ] . V_60 ) ;
* V_177 = V_24 ;
V_105 -> V_255 ++ ;
}
}
}
break;
case V_183 :
break;
default:
F_51 ( V_83 L_45 ,
V_142 , V_22 -> V_35 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_64 () ;
}
}
static void F_175 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
int V_69 ;
struct V_156 * V_158 = NULL ;
F_24 ( V_351 , & V_22 -> V_38 ) ;
for ( V_69 = 0 ; V_69 < V_22 -> V_25 ; V_69 ++ )
if ( V_69 != V_22 -> V_32 && V_69 != V_22 -> V_24 ) {
int V_284 , V_352 ;
struct V_21 * V_312 ;
struct V_163 V_164 ;
T_1 V_353 = F_154 ( V_22 , V_69 , 1 ) ;
T_1 V_105 = F_157 ( V_3 , V_353 , 0 ,
& V_284 , NULL ) ;
V_312 = F_61 ( V_3 , V_105 , 0 , 1 , 1 ) ;
if ( V_312 == NULL )
continue;
if ( ! F_19 ( V_55 , & V_312 -> V_38 ) ||
F_19 ( V_354 , & V_312 -> V_72 [ V_284 ] . V_60 ) ) {
F_32 ( V_312 ) ;
continue;
}
F_79 ( & V_164 , 0 , V_158 , NULL , NULL , NULL ) ;
V_158 = F_81 ( V_312 -> V_72 [ V_284 ] . V_67 ,
V_22 -> V_72 [ V_69 ] . V_67 , 0 , 0 , V_152 ,
& V_164 ) ;
F_72 ( V_354 , & V_312 -> V_72 [ V_284 ] . V_60 ) ;
F_72 ( V_179 , & V_312 -> V_72 [ V_284 ] . V_60 ) ;
for ( V_352 = 0 ; V_352 < V_3 -> V_27 ; V_352 ++ )
if ( V_352 != V_312 -> V_32 &&
V_352 != V_312 -> V_24 &&
! F_19 ( V_354 , & V_312 -> V_72 [ V_352 ] . V_60 ) )
break;
if ( V_352 == V_3 -> V_27 ) {
F_72 ( V_355 , & V_312 -> V_38 ) ;
F_72 ( V_42 , & V_312 -> V_38 ) ;
}
F_32 ( V_312 ) ;
}
if ( V_158 ) {
F_112 ( V_158 ) ;
F_176 ( V_158 ) ;
}
}
static void F_177 ( struct V_21 * V_22 , struct V_104 * V_105 )
{
struct V_2 * V_3 = V_22 -> V_59 ;
int V_25 = V_22 -> V_25 ;
struct V_77 * V_72 ;
int V_69 ;
int V_356 = 0 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_136 = F_19 ( V_351 , & V_22 -> V_38 ) ;
V_105 -> V_137 = F_19 ( V_355 , & V_22 -> V_38 ) ;
V_105 -> V_337 [ 0 ] = - 1 ;
V_105 -> V_337 [ 1 ] = - 1 ;
F_57 () ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_88 * V_89 ;
T_1 V_130 ;
int V_131 ;
int V_357 = 0 ;
V_72 = & V_22 -> V_72 [ V_69 ] ;
F_38 ( L_46 ,
V_69 , V_72 -> V_60 ,
V_72 -> V_78 , V_72 -> V_80 , V_72 -> V_81 ) ;
if ( F_19 ( V_179 , & V_72 -> V_60 ) && V_72 -> V_78 &&
! F_19 ( V_37 , & V_22 -> V_38 ) )
F_72 ( V_173 , & V_72 -> V_60 ) ;
if ( F_19 ( V_82 , & V_72 -> V_60 ) )
V_105 -> V_315 ++ ;
if ( F_19 ( V_179 , & V_72 -> V_60 ) )
V_105 -> V_255 ++ ;
if ( F_19 ( V_180 , & V_72 -> V_60 ) ) {
V_105 -> V_358 ++ ;
F_21 ( V_105 -> V_358 > 2 ) ;
}
if ( F_19 ( V_173 , & V_72 -> V_60 ) )
V_105 -> V_359 ++ ;
else if ( V_72 -> V_78 )
V_105 -> V_360 ++ ;
if ( V_72 -> V_80 ) {
V_105 -> V_339 ++ ;
if ( ! F_19 ( V_322 , & V_72 -> V_60 ) )
V_105 -> V_361 ++ ;
}
if ( V_72 -> V_81 )
V_105 -> V_81 ++ ;
V_89 = F_58 ( V_3 -> V_25 [ V_69 ] . V_91 ) ;
if ( V_89 && ! F_19 ( V_90 , & V_89 -> V_60 ) &&
V_89 -> V_334 >= V_22 -> V_10 + V_14 &&
! F_71 ( V_89 , V_22 -> V_10 , V_14 ,
& V_130 , & V_131 ) )
F_72 ( V_127 , & V_72 -> V_60 ) ;
else {
if ( V_89 )
F_72 ( V_362 , & V_72 -> V_60 ) ;
V_89 = F_58 ( V_3 -> V_25 [ V_69 ] . V_89 ) ;
F_24 ( V_127 , & V_72 -> V_60 ) ;
}
if ( V_89 && F_19 ( V_90 , & V_89 -> V_60 ) )
V_89 = NULL ;
if ( V_89 ) {
V_357 = F_71 ( V_89 , V_22 -> V_10 , V_14 ,
& V_130 , & V_131 ) ;
if ( V_105 -> V_363 == NULL
&& ( F_19 ( V_280 , & V_89 -> V_60 )
|| V_357 < 0 ) ) {
if ( V_357 < 0 )
F_72 ( V_133 ,
& V_89 -> V_60 ) ;
V_105 -> V_363 = V_89 ;
F_8 ( & V_89 -> V_128 ) ;
}
}
F_24 ( V_328 , & V_72 -> V_60 ) ;
if ( ! V_89 )
;
else if ( V_357 ) {
if ( ! F_19 ( V_129 , & V_89 -> V_60 ) &&
F_19 ( V_179 , & V_72 -> V_60 ) ) {
F_72 ( V_328 , & V_72 -> V_60 ) ;
F_72 ( V_258 , & V_72 -> V_60 ) ;
}
} else if ( F_19 ( V_92 , & V_89 -> V_60 ) )
F_72 ( V_328 , & V_72 -> V_60 ) ;
else if ( V_22 -> V_10 + V_14 <= V_89 -> V_334 )
F_72 ( V_328 , & V_72 -> V_60 ) ;
else if ( F_19 ( V_179 , & V_72 -> V_60 ) &&
F_19 ( V_354 , & V_72 -> V_60 ) )
F_72 ( V_328 , & V_72 -> V_60 ) ;
if ( V_89 && F_19 ( V_269 , & V_72 -> V_60 ) ) {
struct V_88 * V_364 = F_58 (
V_3 -> V_25 [ V_69 ] . V_89 ) ;
if ( V_364 == V_89 )
F_24 ( V_328 , & V_72 -> V_60 ) ;
if ( V_364 && ! F_19 ( V_90 , & V_364 -> V_60 ) ) {
V_105 -> V_365 = 1 ;
F_8 ( & V_364 -> V_128 ) ;
} else
F_24 ( V_269 , & V_72 -> V_60 ) ;
}
if ( V_89 && F_19 ( V_273 , & V_72 -> V_60 ) ) {
struct V_88 * V_364 = F_58 (
V_3 -> V_25 [ V_69 ] . V_89 ) ;
if ( V_364 && ! F_19 ( V_90 , & V_364 -> V_60 ) ) {
V_105 -> V_365 = 1 ;
F_8 ( & V_364 -> V_128 ) ;
} else
F_24 ( V_273 , & V_72 -> V_60 ) ;
}
if ( F_19 ( V_268 , & V_72 -> V_60 ) ) {
struct V_88 * V_364 = F_58 (
V_3 -> V_25 [ V_69 ] . V_91 ) ;
if ( V_364 && ! F_19 ( V_90 , & V_364 -> V_60 ) ) {
V_105 -> V_365 = 1 ;
F_8 ( & V_364 -> V_128 ) ;
} else
F_24 ( V_268 , & V_72 -> V_60 ) ;
}
if ( ! F_19 ( V_328 , & V_72 -> V_60 ) ) {
F_24 ( V_258 , & V_72 -> V_60 ) ;
F_24 ( V_261 , & V_72 -> V_60 ) ;
}
if ( F_19 ( V_258 , & V_72 -> V_60 ) )
F_24 ( V_328 , & V_72 -> V_60 ) ;
if ( ! F_19 ( V_328 , & V_72 -> V_60 ) ) {
if ( V_105 -> V_338 < 2 )
V_105 -> V_337 [ V_105 -> V_338 ] = V_69 ;
V_105 -> V_338 ++ ;
if ( V_89 && ! F_19 ( V_90 , & V_89 -> V_60 ) )
V_356 = 1 ;
}
}
if ( F_19 ( V_329 , & V_22 -> V_38 ) ) {
if ( V_356 ||
V_22 -> V_10 >= V_3 -> V_51 -> V_335 ||
F_19 ( V_366 , & ( V_3 -> V_51 -> V_272 ) ) )
V_105 -> V_135 = 1 ;
else
V_105 -> V_138 = 1 ;
}
F_59 () ;
}
static void F_178 ( struct V_21 * V_22 )
{
struct V_104 V_105 ;
struct V_2 * V_3 = V_22 -> V_59 ;
int V_69 ;
int V_213 ;
int V_25 = V_22 -> V_25 ;
struct V_77 * V_367 , * V_368 ;
F_24 ( V_42 , & V_22 -> V_38 ) ;
if ( F_118 ( V_369 , & V_22 -> V_38 ) ) {
F_72 ( V_42 , & V_22 -> V_38 ) ;
return;
}
if ( F_26 ( V_370 , & V_22 -> V_38 ) ) {
F_72 ( V_329 , & V_22 -> V_38 ) ;
F_24 ( V_345 , & V_22 -> V_38 ) ;
}
F_24 ( V_43 , & V_22 -> V_38 ) ;
F_38 ( L_47
L_48 ,
( unsigned long long ) V_22 -> V_10 , V_22 -> V_38 ,
F_4 ( & V_22 -> V_29 ) , V_22 -> V_32 , V_22 -> V_24 ,
V_22 -> V_35 , V_22 -> V_36 ) ;
F_177 ( V_22 , & V_105 ) ;
if ( V_105 . V_365 ) {
F_72 ( V_42 , & V_22 -> V_38 ) ;
goto V_371;
}
if ( F_89 ( V_105 . V_363 ) ) {
if ( V_105 . V_135 || V_105 . V_136 || V_105 . V_137 ||
V_105 . V_138 || V_105 . V_339 || V_105 . V_81 ) {
F_72 ( V_42 , & V_22 -> V_38 ) ;
goto V_371;
}
F_75 ( V_105 . V_363 , V_3 -> V_51 ) ;
V_105 . V_363 = NULL ;
}
if ( V_105 . V_359 && ! F_19 ( V_37 , & V_22 -> V_38 ) ) {
F_72 ( V_222 , & V_105 . V_218 ) ;
F_72 ( V_37 , & V_22 -> V_38 ) ;
}
F_38 ( L_49
L_50 ,
V_105 . V_315 , V_105 . V_255 , V_105 . V_360 , V_105 . V_339 , V_105 . V_338 ,
V_105 . V_337 [ 0 ] , V_105 . V_337 [ 1 ] ) ;
if ( V_105 . V_338 > V_3 -> V_95 ) {
V_22 -> V_35 = 0 ;
V_22 -> V_36 = 0 ;
if ( V_105 . V_360 + V_105 . V_339 + V_105 . V_81 )
F_162 ( V_3 , V_22 , & V_105 , V_25 , & V_105 . V_33 ) ;
if ( V_105 . V_135 + V_105 . V_138 )
F_165 ( V_3 , V_22 , & V_105 ) ;
}
V_213 = 0 ;
if ( V_22 -> V_36 == V_210 )
V_213 = 1 ;
if ( V_22 -> V_36 == V_208 ||
V_22 -> V_36 == V_210 ) {
V_22 -> V_36 = V_372 ;
F_21 ( ! F_19 ( V_179 , & V_22 -> V_72 [ V_22 -> V_32 ] . V_60 ) &&
! F_19 ( V_114 , & V_22 -> V_72 [ V_22 -> V_32 ] . V_60 ) ) ;
F_21 ( V_22 -> V_24 >= 0 &&
! F_19 ( V_179 , & V_22 -> V_72 [ V_22 -> V_24 ] . V_60 ) &&
! F_19 ( V_114 , & V_22 -> V_72 [ V_22 -> V_24 ] . V_60 ) ) ;
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( F_19 ( V_82 , & V_72 -> V_60 ) &&
( V_69 == V_22 -> V_32 || V_69 == V_22 -> V_24 ||
V_72 -> V_81 ) ) {
F_38 ( L_51 , V_69 ) ;
F_72 ( V_110 , & V_72 -> V_60 ) ;
if ( V_213 )
continue;
if ( ! F_19 ( V_328 , & V_72 -> V_60 ) ||
( ( V_69 == V_22 -> V_32 || V_69 == V_22 -> V_24 ) &&
V_105 . V_338 == 0 ) )
F_72 ( V_345 , & V_22 -> V_38 ) ;
}
}
if ( F_26 ( V_44 , & V_22 -> V_38 ) )
V_105 . V_373 = 1 ;
}
V_367 = & V_22 -> V_72 [ V_22 -> V_32 ] ;
V_105 . V_374 = ( V_105 . V_338 >= 1 && V_105 . V_337 [ 0 ] == V_22 -> V_32 )
|| ( V_105 . V_338 >= 2 && V_105 . V_337 [ 1 ] == V_22 -> V_32 ) ;
V_368 = & V_22 -> V_72 [ V_22 -> V_24 ] ;
V_105 . V_349 = ( V_105 . V_338 >= 1 && V_105 . V_337 [ 0 ] == V_22 -> V_24 )
|| ( V_105 . V_338 >= 2 && V_105 . V_337 [ 1 ] == V_22 -> V_24 )
|| V_3 -> V_220 < 6 ;
if ( V_105 . V_81 &&
( V_105 . V_374 || ( ( F_19 ( V_328 , & V_367 -> V_60 )
&& ! F_19 ( V_82 , & V_367 -> V_60 )
&& ( F_19 ( V_179 , & V_367 -> V_60 ) ||
F_19 ( V_114 , & V_367 -> V_60 ) ) ) ) ) &&
( V_105 . V_349 || ( ( F_19 ( V_328 , & V_368 -> V_60 )
&& ! F_19 ( V_82 , & V_368 -> V_60 )
&& ( F_19 ( V_179 , & V_368 -> V_60 ) ||
F_19 ( V_114 , & V_368 -> V_60 ) ) ) ) ) )
F_170 ( V_3 , V_22 , V_25 , & V_105 . V_33 ) ;
if ( V_105 . V_360 || V_105 . V_361
|| ( V_3 -> V_220 == 6 && V_105 . V_339 && V_105 . V_338 )
|| ( V_105 . V_135 && ( V_105 . V_255 + V_105 . V_358 < V_25 ) )
|| V_105 . V_138
|| V_105 . V_136 )
F_169 ( V_22 , & V_105 , V_25 ) ;
if ( V_105 . V_339 && ! V_22 -> V_36 && ! V_22 -> V_35 )
F_171 ( V_3 , V_22 , & V_105 , V_25 ) ;
if ( V_22 -> V_35 ||
( V_105 . V_135 && V_105 . V_315 == 0 &&
! F_19 ( V_39 , & V_22 -> V_38 ) &&
! F_19 ( V_345 , & V_22 -> V_38 ) ) ) {
if ( V_3 -> V_220 == 6 )
F_174 ( V_3 , V_22 , & V_105 , V_25 ) ;
else
F_172 ( V_3 , V_22 , & V_105 , V_25 ) ;
}
if ( V_105 . V_138 && V_105 . V_315 == 0
&& ! F_19 ( V_345 , & V_22 -> V_38 ) ) {
for ( V_69 = 0 ; V_69 < V_3 -> V_27 ; V_69 ++ )
if ( F_19 ( V_179 , & V_22 -> V_72 [ V_69 ] . V_60 ) &&
F_19 ( V_362 , & V_22 -> V_72 [ V_69 ] . V_60 ) ) {
F_72 ( V_118 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_72 ( V_82 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
V_105 . V_315 ++ ;
}
F_72 ( V_345 , & V_22 -> V_38 ) ;
}
if ( ( V_105 . V_135 || V_105 . V_138 ) && V_105 . V_315 == 0 &&
F_19 ( V_345 , & V_22 -> V_38 ) ) {
F_166 ( V_3 -> V_51 , V_14 , 1 ) ;
F_24 ( V_329 , & V_22 -> V_38 ) ;
}
if ( V_105 . V_338 <= V_3 -> V_95 && ! V_3 -> V_51 -> V_375 )
for ( V_69 = 0 ; V_69 < V_105 . V_338 ; V_69 ++ ) {
struct V_77 * V_72 = & V_22 -> V_72 [ V_105 . V_337 [ V_69 ] ] ;
if ( F_19 ( V_258 , & V_72 -> V_60 )
&& ! F_19 ( V_82 , & V_72 -> V_60 )
&& F_19 ( V_179 , & V_72 -> V_60 )
) {
if ( ! F_19 ( V_261 , & V_72 -> V_60 ) ) {
F_72 ( V_110 , & V_72 -> V_60 ) ;
F_72 ( V_261 , & V_72 -> V_60 ) ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
V_105 . V_315 ++ ;
} else {
F_72 ( V_116 , & V_72 -> V_60 ) ;
F_72 ( V_82 , & V_72 -> V_60 ) ;
V_105 . V_315 ++ ;
}
}
}
if ( V_22 -> V_36 == V_212 ) {
struct V_21 * V_376
= F_61 ( V_3 , V_22 -> V_10 , 1 , 1 , 1 ) ;
if ( V_376 && F_19 ( V_351 , & V_376 -> V_38 ) ) {
F_72 ( V_43 , & V_22 -> V_38 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
if ( ! F_152 ( V_44 ,
& V_376 -> V_38 ) )
F_8 ( & V_3 -> V_53 ) ;
F_32 ( V_376 ) ;
goto V_371;
}
if ( V_376 )
F_32 ( V_376 ) ;
V_22 -> V_36 = V_372 ;
F_24 ( V_55 , & V_22 -> V_38 ) ;
for ( V_69 = V_3 -> V_27 ; V_69 -- ; ) {
F_72 ( V_110 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
F_72 ( V_82 , & V_22 -> V_72 [ V_69 ] . V_60 ) ;
V_105 . V_315 ++ ;
}
}
if ( V_105 . V_137 && F_19 ( V_55 , & V_22 -> V_38 ) &&
! V_22 -> V_36 ) {
V_22 -> V_25 = V_3 -> V_27 ;
F_50 ( V_22 -> V_10 , V_3 , 0 , V_22 ) ;
F_159 ( V_22 , & V_105 , 1 , 1 ) ;
} else if ( V_105 . V_137 && ! V_22 -> V_36 && V_105 . V_315 == 0 ) {
F_24 ( V_355 , & V_22 -> V_38 ) ;
F_28 ( & V_3 -> V_377 ) ;
F_29 ( & V_3 -> V_232 ) ;
F_166 ( V_3 -> V_51 , V_14 , 1 ) ;
}
if ( V_105 . V_136 && V_105 . V_315 == 0 &&
! F_19 ( V_39 , & V_22 -> V_38 ) )
F_175 ( V_3 , V_22 ) ;
V_371:
if ( F_89 ( V_105 . V_363 ) ) {
if ( V_3 -> V_51 -> V_134 )
F_74 ( V_105 . V_363 ,
V_3 -> V_51 ) ;
else
F_75 ( V_105 . V_363 ,
V_3 -> V_51 ) ;
}
if ( V_105 . V_365 )
for ( V_69 = V_25 ; V_69 -- ; ) {
struct V_88 * V_89 ;
struct V_77 * V_72 = & V_22 -> V_72 [ V_69 ] ;
if ( F_26 ( V_269 , & V_72 -> V_60 ) ) {
V_89 = V_3 -> V_25 [ V_69 ] . V_89 ;
if ( ! F_150 ( V_89 , V_22 -> V_10 ,
V_14 , 0 ) )
F_151 ( V_3 -> V_51 , V_89 ) ;
F_75 ( V_89 , V_3 -> V_51 ) ;
}
if ( F_26 ( V_273 , & V_72 -> V_60 ) ) {
V_89 = V_3 -> V_25 [ V_69 ] . V_89 ;
F_179 ( V_89 , V_22 -> V_10 ,
V_14 , 0 ) ;
F_75 ( V_89 , V_3 -> V_51 ) ;
}
if ( F_26 ( V_268 , & V_72 -> V_60 ) ) {
V_89 = V_3 -> V_25 [ V_69 ] . V_91 ;
if ( ! V_89 )
V_89 = V_3 -> V_25 [ V_69 ] . V_89 ;
F_179 ( V_89 , V_22 -> V_10 ,
V_14 , 0 ) ;
F_75 ( V_89 , V_3 -> V_51 ) ;
}
}
if ( V_105 . V_218 )
F_116 ( V_22 , V_105 . V_218 ) ;
F_68 ( V_22 , & V_105 ) ;
if ( V_105 . V_373 ) {
F_28 ( & V_3 -> V_53 ) ;
if ( F_4 ( & V_3 -> V_53 ) <
V_54 )
F_25 ( V_3 -> V_51 -> V_52 ) ;
}
F_16 ( V_105 . V_33 ) ;
F_115 ( V_369 , & V_22 -> V_38 ) ;
}
static void F_180 ( struct V_2 * V_3 )
{
if ( F_4 ( & V_3 -> V_53 ) < V_54 ) {
while ( ! F_22 ( & V_3 -> V_45 ) ) {
struct V_63 * V_378 = V_3 -> V_45 . V_66 ;
struct V_21 * V_22 ;
V_22 = F_43 ( V_378 , struct V_21 , V_40 ) ;
F_44 ( V_378 ) ;
F_24 ( V_43 , & V_22 -> V_38 ) ;
if ( ! F_152 ( V_44 , & V_22 -> V_38 ) )
F_8 ( & V_3 -> V_53 ) ;
F_23 ( & V_22 -> V_40 , & V_3 -> V_379 ) ;
}
}
}
static void F_181 ( struct V_2 * V_3 )
{
struct V_63 V_380 ;
F_135 ( & V_380 , & V_3 -> V_49 ) ;
F_44 ( & V_3 -> V_49 ) ;
while ( ! F_22 ( & V_380 ) ) {
struct V_21 * V_22 = F_43 ( V_380 . V_66 , struct V_21 , V_40 ) ;
F_44 ( & V_22 -> V_40 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_30 ( V_3 , V_22 ) ;
}
}
int F_182 ( struct V_51 * V_51 , int V_381 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
if ( V_3 -> V_99 )
return 1 ;
if ( V_3 -> V_98 )
return 1 ;
if ( F_183 ( & V_3 -> V_56 ) )
return 1 ;
return 0 ;
}
static int F_184 ( void * V_382 , int V_381 )
{
struct V_51 * V_51 = V_382 ;
return F_185 ( V_51 , V_381 ) ||
F_182 ( V_51 , V_381 ) ;
}
static int F_186 ( struct V_383 * V_384 ,
struct V_385 * V_386 ,
struct V_159 * V_387 )
{
struct V_51 * V_51 = V_384 -> V_388 ;
T_1 V_10 = V_386 -> V_13 + F_187 ( V_386 -> V_141 ) ;
int F_128 ;
unsigned int V_294 = V_51 -> V_294 ;
unsigned int V_389 = V_386 -> V_12 >> 9 ;
if ( ( V_386 -> V_123 & 1 ) == V_113 )
return V_387 -> V_151 ;
if ( V_51 -> V_390 < V_51 -> V_294 )
V_294 = V_51 -> V_390 ;
F_128 = ( V_294 - ( ( V_10 & ( V_294 - 1 ) ) + V_389 ) ) << 9 ;
if ( F_128 < 0 ) F_128 = 0 ;
if ( F_128 <= V_387 -> V_151 && V_389 == 0 )
return V_387 -> V_151 ;
else
return F_128 ;
}
static int F_188 ( struct V_51 * V_51 , struct V_9 * V_9 )
{
T_1 V_10 = V_9 -> V_13 + F_187 ( V_9 -> V_141 ) ;
unsigned int V_294 = V_51 -> V_294 ;
unsigned int V_389 = V_9 -> V_12 >> 9 ;
if ( V_51 -> V_390 < V_51 -> V_294 )
V_294 = V_51 -> V_390 ;
return V_294 >=
( ( V_10 & ( V_294 - 1 ) ) + V_389 ) ;
}
static void F_189 ( struct V_9 * V_34 , struct V_2 * V_3 )
{
unsigned long V_60 ;
F_155 ( & V_3 -> V_61 , V_60 ) ;
V_34 -> V_15 = V_3 -> V_391 ;
V_3 -> V_391 = V_34 ;
F_156 ( & V_3 -> V_61 , V_60 ) ;
F_25 ( V_3 -> V_51 -> V_52 ) ;
}
static struct V_9 * F_190 ( struct V_2 * V_3 )
{
struct V_9 * V_34 ;
V_34 = V_3 -> V_58 ;
if ( V_34 ) {
V_3 -> V_58 = NULL ;
return V_34 ;
}
V_34 = V_3 -> V_391 ;
if( V_34 ) {
V_3 -> V_391 = V_34 -> V_15 ;
V_34 -> V_15 = NULL ;
F_11 ( V_34 , 1 ) ;
}
return V_34 ;
}
static void F_191 ( struct V_9 * V_34 , int error )
{
struct V_9 * V_392 = V_34 -> V_254 ;
struct V_51 * V_51 ;
struct V_2 * V_3 ;
int V_255 = F_19 ( V_148 , & V_34 -> V_147 ) ;
struct V_88 * V_89 ;
F_192 ( V_34 ) ;
V_89 = ( void * ) V_392 -> V_15 ;
V_392 -> V_15 = NULL ;
V_51 = V_89 -> V_51 ;
V_3 = V_51 -> V_278 ;
F_75 ( V_89 , V_3 -> V_51 ) ;
if ( ! error && V_255 ) {
F_17 ( V_392 , 0 ) ;
if ( F_31 ( & V_3 -> V_393 ) )
F_29 ( & V_3 -> V_57 ) ;
return;
}
F_38 ( L_52 ) ;
F_189 ( V_392 , V_3 ) ;
}
static int F_193 ( struct V_9 * V_34 )
{
struct V_383 * V_384 = F_194 ( V_34 -> V_141 ) ;
if ( ( V_34 -> V_12 >> 9 ) > F_195 ( V_384 ) )
return 0 ;
F_196 ( V_384 , V_34 ) ;
if ( V_34 -> V_17 > F_197 ( V_384 ) )
return 0 ;
if ( V_384 -> V_394 )
return 0 ;
return 1 ;
}
static int F_198 ( struct V_51 * V_51 , struct V_9 * V_395 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
int V_284 ;
struct V_9 * V_396 ;
struct V_88 * V_89 ;
T_1 V_397 ;
if ( ! F_188 ( V_51 , V_395 ) ) {
F_38 ( L_53 ) ;
return 0 ;
}
V_396 = F_199 ( V_395 , V_253 , V_51 ) ;
if ( ! V_396 )
return 0 ;
V_396 -> V_124 = F_191 ;
V_396 -> V_254 = V_395 ;
V_396 -> V_13 = F_157 ( V_3 , V_395 -> V_13 ,
0 ,
& V_284 , NULL ) ;
V_397 = V_396 -> V_13 + ( V_396 -> V_12 >> 9 ) ;
F_57 () ;
V_89 = F_58 ( V_3 -> V_25 [ V_284 ] . V_91 ) ;
if ( ! V_89 || F_19 ( V_90 , & V_89 -> V_60 ) ||
V_89 -> V_334 < V_397 ) {
V_89 = F_58 ( V_3 -> V_25 [ V_284 ] . V_89 ) ;
if ( V_89 &&
( F_19 ( V_90 , & V_89 -> V_60 ) ||
! ( F_19 ( V_92 , & V_89 -> V_60 ) ||
V_89 -> V_334 >= V_397 ) ) )
V_89 = NULL ;
}
if ( V_89 ) {
T_1 V_130 ;
int V_131 ;
F_8 ( & V_89 -> V_128 ) ;
F_59 () ;
V_395 -> V_15 = ( void * ) V_89 ;
V_396 -> V_141 = V_89 -> V_139 ;
V_396 -> V_147 &= ~ ( 1 << V_398 ) ;
if ( ! F_193 ( V_396 ) ||
F_71 ( V_89 , V_396 -> V_13 , V_396 -> V_12 >> 9 ,
& V_130 , & V_131 ) ) {
F_192 ( V_396 ) ;
F_75 ( V_89 , V_51 ) ;
return 0 ;
}
V_396 -> V_13 += V_89 -> V_144 ;
F_62 ( & V_3 -> V_61 ) ;
F_63 ( V_3 -> V_57 ,
V_3 -> V_98 == 0 ,
V_3 -> V_61 , ) ;
F_8 ( & V_3 -> V_393 ) ;
F_65 ( & V_3 -> V_61 ) ;
F_77 ( V_396 ) ;
return 1 ;
} else {
F_59 () ;
F_192 ( V_396 ) ;
return 0 ;
}
}
static struct V_21 * F_200 ( struct V_2 * V_3 )
{
struct V_21 * V_22 ;
F_38 ( L_54 ,
V_142 ,
F_22 ( & V_3 -> V_50 ) ? L_55 : L_56 ,
F_22 ( & V_3 -> V_379 ) ? L_55 : L_56 ,
F_4 ( & V_3 -> V_317 ) , V_3 -> V_399 ) ;
if ( ! F_22 ( & V_3 -> V_50 ) ) {
V_22 = F_43 ( V_3 -> V_50 . V_66 , F_201 ( * V_22 ) , V_40 ) ;
if ( F_22 ( & V_3 -> V_379 ) )
V_3 -> V_399 = 0 ;
else if ( ! F_19 ( V_140 , & V_22 -> V_38 ) ) {
if ( V_3 -> V_379 . V_66 == V_3 -> V_400 )
V_3 -> V_399 ++ ;
else {
V_3 -> V_400 = V_3 -> V_379 . V_66 ;
V_3 -> V_399 -= V_3 -> V_401 ;
if ( V_3 -> V_399 < 0 )
V_3 -> V_399 = 0 ;
}
}
} else if ( ! F_22 ( & V_3 -> V_379 ) &&
( ( V_3 -> V_401 &&
V_3 -> V_399 > V_3 -> V_401 ) ||
F_4 ( & V_3 -> V_317 ) == 0 ) ) {
V_22 = F_43 ( V_3 -> V_379 . V_66 ,
F_201 ( * V_22 ) , V_40 ) ;
V_3 -> V_399 -= V_3 -> V_401 ;
if ( V_3 -> V_399 < 0 )
V_3 -> V_399 = 0 ;
} else
return NULL ;
F_44 ( & V_22 -> V_40 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_21 ( F_4 ( & V_22 -> V_29 ) != 1 ) ;
return V_22 ;
}
static void F_202 ( struct V_402 * V_403 , bool V_404 )
{
struct V_405 * V_406 = F_203 (
V_403 , struct V_405 , V_406 ) ;
struct V_21 * V_22 ;
struct V_51 * V_51 = V_406 -> V_406 . V_382 ;
struct V_2 * V_3 = V_51 -> V_278 ;
if ( V_406 -> V_407 . V_66 && ! F_22 ( & V_406 -> V_407 ) ) {
F_62 ( & V_3 -> V_61 ) ;
while ( ! F_22 ( & V_406 -> V_407 ) ) {
V_22 = F_204 ( & V_406 -> V_407 , struct V_21 , V_40 ) ;
F_44 ( & V_22 -> V_40 ) ;
F_205 () ;
F_24 ( V_101 , & V_22 -> V_38 ) ;
F_30 ( V_3 , V_22 ) ;
}
F_65 ( & V_3 -> V_61 ) ;
}
F_140 ( V_406 ) ;
}
static void F_206 ( struct V_51 * V_51 ,
struct V_21 * V_22 )
{
struct V_402 * V_403 = F_207 (
F_202 , V_51 ,
sizeof( struct V_405 ) ) ;
struct V_405 * V_406 ;
if ( ! V_403 ) {
F_32 ( V_22 ) ;
return;
}
V_406 = F_203 ( V_403 , struct V_405 , V_406 ) ;
if ( V_406 -> V_407 . V_66 == NULL )
F_126 ( & V_406 -> V_407 ) ;
if ( ! F_152 ( V_101 , & V_22 -> V_38 ) )
F_23 ( & V_22 -> V_40 , & V_406 -> V_407 ) ;
else
F_32 ( V_22 ) ;
}
static void F_208 ( struct V_51 * V_51 , struct V_9 * V_34 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
T_1 V_408 , V_409 ;
struct V_21 * V_22 ;
int V_410 ;
int V_411 ;
if ( V_51 -> V_93 != V_94 )
return;
V_408 = V_34 -> V_13 & ~ ( ( T_1 ) V_14 - 1 ) ;
V_409 = V_34 -> V_13 + ( V_34 -> V_12 >> 9 ) ;
V_34 -> V_15 = NULL ;
V_34 -> V_17 = 1 ;
V_411 = V_3 -> V_294 *
( V_3 -> V_27 - V_3 -> V_95 ) ;
V_408 = F_209 ( V_408 ,
V_411 ) ;
F_158 ( V_409 , V_411 ) ;
V_408 *= V_3 -> V_294 ;
V_409 *= V_3 -> V_294 ;
for (; V_408 < V_409 ;
V_408 += V_14 ) {
F_210 ( V_412 ) ;
int V_413 ;
V_414:
V_22 = F_61 ( V_3 , V_408 , 0 , 0 , 0 ) ;
F_211 ( & V_3 -> V_232 , & V_412 ,
V_415 ) ;
F_62 ( & V_22 -> V_175 ) ;
for ( V_413 = 0 ; V_413 < V_3 -> V_27 ; V_413 ++ ) {
if ( V_413 == V_22 -> V_32 || V_413 == V_22 -> V_24 )
continue;
if ( V_22 -> V_72 [ V_413 ] . V_80 || V_22 -> V_72 [ V_413 ] . V_78 ) {
F_72 ( V_231 , & V_22 -> V_72 [ V_413 ] . V_60 ) ;
F_65 ( & V_22 -> V_175 ) ;
F_32 ( V_22 ) ;
F_212 () ;
goto V_414;
}
}
F_213 ( & V_3 -> V_232 , & V_412 ) ;
for ( V_413 = 0 ; V_413 < V_3 -> V_27 ; V_413 ++ ) {
if ( V_413 == V_22 -> V_32 || V_413 == V_22 -> V_24 )
continue;
V_22 -> V_72 [ V_413 ] . V_80 = V_34 ;
F_72 ( V_322 , & V_22 -> V_72 [ V_413 ] . V_60 ) ;
F_7 ( V_34 ) ;
}
F_65 ( & V_22 -> V_175 ) ;
if ( V_3 -> V_51 -> V_323 ) {
for ( V_413 = 0 ;
V_413 < V_3 -> V_27 - V_3 -> V_95 ;
V_413 ++ )
F_161 ( V_51 -> V_323 ,
V_22 -> V_10 ,
V_14 ,
0 ) ;
V_22 -> V_47 = V_3 -> V_324 + 1 ;
F_72 ( V_46 , & V_22 -> V_38 ) ;
}
F_72 ( V_42 , & V_22 -> V_38 ) ;
F_24 ( V_43 , & V_22 -> V_38 ) ;
if ( ! F_152 ( V_44 , & V_22 -> V_38 ) )
F_8 ( & V_3 -> V_53 ) ;
F_206 ( V_51 , V_22 ) ;
}
V_410 = F_5 ( V_34 ) ;
if ( V_410 == 0 ) {
F_163 ( V_51 ) ;
F_17 ( V_34 , 0 ) ;
}
}
static void F_214 ( struct V_51 * V_51 , struct V_9 * V_34 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
int V_284 ;
T_1 V_289 ;
T_1 V_408 , V_409 ;
struct V_21 * V_22 ;
const int V_106 = F_215 ( V_34 ) ;
int V_410 ;
if ( F_89 ( V_34 -> V_123 & V_146 ) ) {
F_216 ( V_51 , V_34 ) ;
return;
}
F_217 ( V_51 , V_34 ) ;
if ( V_106 == V_117 &&
V_51 -> V_93 == V_94 &&
F_198 ( V_51 , V_34 ) )
return;
if ( F_89 ( V_34 -> V_123 & V_115 ) ) {
F_208 ( V_51 , V_34 ) ;
return;
}
V_408 = V_34 -> V_13 & ~ ( ( T_1 ) V_14 - 1 ) ;
V_409 = V_34 -> V_13 + ( V_34 -> V_12 >> 9 ) ;
V_34 -> V_15 = NULL ;
V_34 -> V_17 = 1 ;
for (; V_408 < V_409 ; V_408 += V_14 ) {
F_210 ( V_412 ) ;
int V_74 ;
V_264:
V_74 = 0 ;
F_211 ( & V_3 -> V_232 , & V_412 , V_415 ) ;
if ( F_89 ( V_3 -> V_103 != V_94 ) ) {
F_62 ( & V_3 -> V_61 ) ;
if ( V_51 -> V_416
? V_408 < V_3 -> V_103
: V_408 >= V_3 -> V_103 ) {
V_74 = 1 ;
} else {
if ( V_51 -> V_416
? V_408 < V_3 -> V_417
: V_408 >= V_3 -> V_417 ) {
F_65 ( & V_3 -> V_61 ) ;
F_212 () ;
goto V_264;
}
}
F_65 ( & V_3 -> V_61 ) ;
}
V_289 = F_157 ( V_3 , V_408 ,
V_74 ,
& V_284 , NULL ) ;
F_38 ( L_57 ,
( unsigned long long ) V_289 ,
( unsigned long long ) V_408 ) ;
V_22 = F_61 ( V_3 , V_289 , V_74 ,
( V_34 -> V_123 & V_418 ) , 0 ) ;
if ( V_22 ) {
if ( F_89 ( V_74 ) ) {
int V_419 = 0 ;
F_62 ( & V_3 -> V_61 ) ;
if ( V_51 -> V_416
? V_408 >= V_3 -> V_103
: V_408 < V_3 -> V_103 )
V_419 = 1 ;
F_65 ( & V_3 -> V_61 ) ;
if ( V_419 ) {
F_32 ( V_22 ) ;
F_212 () ;
goto V_264;
}
}
if ( V_106 == V_113 &&
V_408 >= V_51 -> V_420 &&
V_408 < V_51 -> V_421 ) {
F_32 ( V_22 ) ;
F_218 ( V_422 ) ;
F_211 ( & V_3 -> V_232 ,
& V_412 , V_423 ) ;
if ( V_408 >= V_51 -> V_420 &&
V_408 < V_51 -> V_421 )
F_212 () ;
goto V_264;
}
if ( F_19 ( V_55 , & V_22 -> V_38 ) ||
! F_160 ( V_22 , V_34 , V_284 , V_106 ) ) {
F_25 ( V_51 -> V_52 ) ;
F_32 ( V_22 ) ;
F_212 () ;
goto V_264;
}
F_213 ( & V_3 -> V_232 , & V_412 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
F_24 ( V_43 , & V_22 -> V_38 ) ;
if ( ( V_34 -> V_123 & V_120 ) &&
! F_152 ( V_44 , & V_22 -> V_38 ) )
F_8 ( & V_3 -> V_53 ) ;
F_206 ( V_51 , V_22 ) ;
} else {
F_24 ( V_148 , & V_34 -> V_147 ) ;
F_213 ( & V_3 -> V_232 , & V_412 ) ;
break;
}
}
V_410 = F_5 ( V_34 ) ;
if ( V_410 == 0 ) {
if ( V_106 == V_113 )
F_163 ( V_51 ) ;
F_17 ( V_34 , 0 ) ;
}
}
static T_1 F_219 ( struct V_51 * V_51 , T_1 V_424 , int * V_425 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
struct V_21 * V_22 ;
T_1 V_426 , V_409 ;
int V_27 = V_3 -> V_76 ;
int V_295 = V_27 - V_3 -> V_95 ;
int V_427 = V_3 -> V_27 - V_3 -> V_95 ;
int V_69 ;
int V_284 ;
T_1 V_428 , V_429 , V_430 ;
T_1 V_431 ;
int V_432 ;
struct V_63 V_433 ;
if ( V_424 == 0 ) {
if ( V_51 -> V_416 &&
V_3 -> V_103 < F_220 ( V_51 , 0 , 0 ) ) {
V_424 = F_220 ( V_51 , 0 , 0 )
- V_3 -> V_103 ;
} else if ( ! V_51 -> V_416 &&
V_3 -> V_103 > 0 )
V_424 = V_3 -> V_103 ;
F_158 ( V_424 , V_427 ) ;
if ( V_424 ) {
V_51 -> V_434 = V_424 ;
F_221 ( & V_51 -> V_435 , NULL , L_58 ) ;
* V_425 = 1 ;
return V_424 ;
}
}
if ( V_51 -> V_390 > V_51 -> V_294 )
V_432 = V_51 -> V_390 ;
else
V_432 = V_51 -> V_294 ;
V_428 = V_3 -> V_103 ;
F_158 ( V_428 , V_427 ) ;
V_429 = V_3 -> V_103 ;
F_158 ( V_429 , V_295 ) ;
V_430 = V_3 -> V_417 ;
F_158 ( V_430 , V_295 ) ;
if ( V_51 -> V_416 ) {
V_428 -= F_222 ( T_1 , V_432 , V_428 ) ;
V_429 += V_432 ;
V_430 += V_432 ;
} else {
V_428 += V_432 ;
V_429 -= F_222 ( T_1 , V_432 , V_429 ) ;
V_430 -= F_222 ( T_1 , V_432 , V_430 ) ;
}
if ( V_51 -> V_416 ) {
F_21 ( V_3 -> V_103 == 0 ) ;
V_431 = V_428 ;
F_21 ( ( V_51 -> V_436 &
~ ( ( T_1 ) V_432 - 1 ) )
- V_432 - V_431
!= V_424 ) ;
} else {
F_21 ( V_428 != V_424 + V_432 ) ;
V_431 = V_424 ;
}
if ( V_3 -> V_437 < 0 ) {
V_430 += - V_3 -> V_437 ;
V_429 += - V_3 -> V_437 ;
} else
V_428 += V_3 -> V_437 ;
if ( ( V_51 -> V_416
? ( V_430 > V_428 && V_429 < V_428 )
: ( V_430 < V_428 && V_429 > V_428 ) ) ||
F_223 ( V_438 , V_3 -> V_439 + 10 * V_440 ) ) {
F_117 ( V_3 -> V_232 ,
F_4 ( & V_3 -> V_377 ) == 0 ) ;
V_51 -> V_93 = V_3 -> V_103 ;
V_51 -> V_434 = V_424 ;
V_3 -> V_439 = V_438 ;
F_72 ( V_281 , & V_51 -> V_60 ) ;
F_25 ( V_51 -> V_52 ) ;
F_117 ( V_51 -> V_441 , V_51 -> V_60 == 0 ||
F_224 () ) ;
F_62 ( & V_3 -> V_61 ) ;
V_3 -> V_417 = V_51 -> V_93 ;
F_65 ( & V_3 -> V_61 ) ;
F_29 ( & V_3 -> V_232 ) ;
F_221 ( & V_51 -> V_435 , NULL , L_58 ) ;
}
F_126 ( & V_433 ) ;
for ( V_69 = 0 ; V_69 < V_432 ; V_69 += V_14 ) {
int V_352 ;
int V_442 = 0 ;
V_22 = F_61 ( V_3 , V_431 + V_69 , 0 , 0 , 1 ) ;
F_72 ( V_55 , & V_22 -> V_38 ) ;
F_8 ( & V_3 -> V_377 ) ;
for ( V_352 = V_22 -> V_25 ; V_352 -- ; ) {
T_1 V_105 ;
if ( V_352 == V_22 -> V_32 )
continue;
if ( V_3 -> V_220 == 6 &&
V_352 == V_22 -> V_24 )
continue;
V_105 = F_154 ( V_22 , V_352 , 0 ) ;
if ( V_105 < F_220 ( V_51 , 0 , 0 ) ) {
V_442 = 1 ;
continue;
}
memset ( F_225 ( V_22 -> V_72 [ V_352 ] . V_67 ) , 0 , V_152 ) ;
F_72 ( V_354 , & V_22 -> V_72 [ V_352 ] . V_60 ) ;
F_72 ( V_179 , & V_22 -> V_72 [ V_352 ] . V_60 ) ;
}
if ( ! V_442 ) {
F_72 ( V_355 , & V_22 -> V_38 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
}
F_135 ( & V_22 -> V_40 , & V_433 ) ;
}
F_62 ( & V_3 -> V_61 ) ;
if ( V_51 -> V_416 )
V_3 -> V_103 -= V_432 * V_427 ;
else
V_3 -> V_103 += V_432 * V_427 ;
F_65 ( & V_3 -> V_61 ) ;
V_426 =
F_157 ( V_3 , V_431 * ( V_427 ) ,
1 , & V_284 , NULL ) ;
V_409 =
F_157 ( V_3 , ( ( V_431 + V_432 )
* V_427 - 1 ) ,
1 , & V_284 , NULL ) ;
if ( V_409 >= V_51 -> V_436 )
V_409 = V_51 -> V_436 - 1 ;
while ( V_426 <= V_409 ) {
V_22 = F_61 ( V_3 , V_426 , 1 , 0 , 1 ) ;
F_72 ( V_351 , & V_22 -> V_38 ) ;
F_72 ( V_42 , & V_22 -> V_38 ) ;
F_32 ( V_22 ) ;
V_426 += V_14 ;
}
while ( ! F_22 ( & V_433 ) ) {
V_22 = F_43 ( V_433 . V_66 , struct V_21 , V_40 ) ;
F_44 ( & V_22 -> V_40 ) ;
F_32 ( V_22 ) ;
}
V_424 += V_432 ;
if ( ( V_424 - V_51 -> V_434 ) * 2
>= V_51 -> V_443 - V_51 -> V_434 ) {
F_117 ( V_3 -> V_232 ,
F_4 ( & V_3 -> V_377 ) == 0 ) ;
V_51 -> V_93 = V_3 -> V_103 ;
V_51 -> V_434 = V_424 ;
V_3 -> V_439 = V_438 ;
F_72 ( V_281 , & V_51 -> V_60 ) ;
F_25 ( V_51 -> V_52 ) ;
F_117 ( V_51 -> V_441 ,
! F_19 ( V_281 , & V_51 -> V_60 )
|| F_224 () ) ;
F_62 ( & V_3 -> V_61 ) ;
V_3 -> V_417 = V_51 -> V_93 ;
F_65 ( & V_3 -> V_61 ) ;
F_29 ( & V_3 -> V_232 ) ;
F_221 ( & V_51 -> V_435 , NULL , L_58 ) ;
}
return V_432 ;
}
static inline T_1 F_226 ( struct V_51 * V_51 , T_1 V_424 , int * V_425 , int V_444 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
struct V_21 * V_22 ;
T_1 V_445 = V_51 -> V_436 ;
T_1 V_446 ;
int V_447 = 0 ;
int V_69 ;
if ( V_424 >= V_445 ) {
if ( F_19 ( V_448 , & V_51 -> V_272 ) ) {
F_227 ( V_3 ) ;
return 0 ;
}
if ( V_51 -> V_449 < V_445 )
F_228 ( V_51 -> V_323 , V_51 -> V_449 ,
& V_446 , 1 ) ;
else
V_3 -> V_450 = 0 ;
F_229 ( V_51 -> V_323 ) ;
return 0 ;
}
F_117 ( V_3 -> V_232 , V_3 -> V_98 != 2 ) ;
if ( F_19 ( V_448 , & V_51 -> V_272 ) )
return F_219 ( V_51 , V_424 , V_425 ) ;
if ( V_51 -> V_86 >= V_3 -> V_95 &&
F_19 ( V_451 , & V_51 -> V_272 ) ) {
T_1 V_333 = V_51 -> V_436 - V_424 ;
* V_425 = 1 ;
return V_333 ;
}
if ( ! F_230 ( V_51 -> V_323 , V_424 , & V_446 , 1 ) &&
! F_19 ( V_366 , & V_51 -> V_272 ) &&
! V_3 -> V_450 && V_446 >= V_14 ) {
V_446 /= V_14 ;
* V_425 = 1 ;
return V_446 * V_14 ;
}
F_231 ( V_51 -> V_323 , V_424 ) ;
V_22 = F_61 ( V_3 , V_424 , 0 , 1 , 0 ) ;
if ( V_22 == NULL ) {
V_22 = F_61 ( V_3 , V_424 , 0 , 0 , 0 ) ;
F_232 ( 1 ) ;
}
for ( V_69 = 0 ; V_69 < V_3 -> V_27 ; V_69 ++ )
if ( V_3 -> V_25 [ V_69 ] . V_89 == NULL )
V_447 = 1 ;
F_230 ( V_51 -> V_323 , V_424 , & V_446 , V_447 ) ;
F_72 ( V_370 , & V_22 -> V_38 ) ;
F_178 ( V_22 ) ;
F_32 ( V_22 ) ;
return V_14 ;
}
static int F_233 ( struct V_2 * V_3 , struct V_9 * V_395 )
{
struct V_21 * V_22 ;
int V_284 ;
T_1 V_10 , V_408 , V_409 ;
int V_452 = 0 ;
int V_410 ;
int V_453 = 0 ;
V_408 = V_395 -> V_13 & ~ ( ( T_1 ) V_14 - 1 ) ;
V_10 = F_157 ( V_3 , V_408 ,
0 , & V_284 , NULL ) ;
V_409 = V_395 -> V_13 + ( V_395 -> V_12 >> 9 ) ;
for (; V_408 < V_409 ;
V_408 += V_14 ,
V_10 += V_14 ,
V_452 ++ ) {
if ( V_452 < F_3 ( V_395 ) )
continue;
V_22 = F_61 ( V_3 , V_10 , 0 , 1 , 0 ) ;
if ( ! V_22 ) {
F_9 ( V_395 , V_452 ) ;
V_3 -> V_58 = V_395 ;
return V_453 ;
}
if ( ! F_160 ( V_22 , V_395 , V_284 , 0 ) ) {
F_32 ( V_22 ) ;
F_9 ( V_395 , V_452 ) ;
V_3 -> V_58 = V_395 ;
return V_453 ;
}
F_72 ( V_145 , & V_22 -> V_72 [ V_284 ] . V_60 ) ;
F_178 ( V_22 ) ;
F_32 ( V_22 ) ;
V_453 ++ ;
}
V_410 = F_5 ( V_395 ) ;
if ( V_410 == 0 )
F_17 ( V_395 , 0 ) ;
if ( F_31 ( & V_3 -> V_393 ) )
F_29 ( & V_3 -> V_57 ) ;
return V_453 ;
}
static int F_234 ( struct V_2 * V_3 )
{
struct V_21 * V_454 [ V_455 ] , * V_22 ;
int V_69 , V_456 = 0 ;
while ( V_456 < V_455 &&
( V_22 = F_200 ( V_3 ) ) != NULL )
V_454 [ V_456 ++ ] = V_22 ;
if ( V_456 == 0 )
return V_456 ;
F_65 ( & V_3 -> V_61 ) ;
for ( V_69 = 0 ; V_69 < V_456 ; V_69 ++ )
F_178 ( V_454 [ V_69 ] ) ;
F_235 () ;
F_62 ( & V_3 -> V_61 ) ;
for ( V_69 = 0 ; V_69 < V_456 ; V_69 ++ )
F_30 ( V_3 , V_454 [ V_69 ] ) ;
return V_456 ;
}
static void F_236 ( struct V_457 * V_52 )
{
struct V_51 * V_51 = V_52 -> V_51 ;
struct V_2 * V_3 = V_51 -> V_278 ;
int V_453 ;
struct V_458 V_459 ;
F_38 ( L_59 ) ;
F_73 ( V_51 ) ;
F_237 ( & V_459 ) ;
V_453 = 0 ;
F_62 ( & V_3 -> V_61 ) ;
while ( 1 ) {
struct V_9 * V_9 ;
int V_456 ;
if (
! F_22 ( & V_3 -> V_49 ) ) {
V_3 -> V_324 ++ ;
F_65 ( & V_3 -> V_61 ) ;
F_238 ( V_51 -> V_323 ) ;
F_62 ( & V_3 -> V_61 ) ;
V_3 -> V_48 = V_3 -> V_324 ;
F_181 ( V_3 ) ;
}
F_180 ( V_3 ) ;
while ( ( V_9 = F_190 ( V_3 ) ) ) {
int V_460 ;
F_65 ( & V_3 -> V_61 ) ;
V_460 = F_233 ( V_3 , V_9 ) ;
F_62 ( & V_3 -> V_61 ) ;
if ( ! V_460 )
break;
V_453 ++ ;
}
V_456 = F_234 ( V_3 ) ;
if ( ! V_456 )
break;
V_453 += V_456 ;
if ( V_51 -> V_60 & ~ ( 1 << V_461 ) ) {
F_65 ( & V_3 -> V_61 ) ;
F_73 ( V_51 ) ;
F_62 ( & V_3 -> V_61 ) ;
}
}
F_38 ( L_60 , V_453 ) ;
F_65 ( & V_3 -> V_61 ) ;
F_239 () ;
F_240 ( & V_459 ) ;
F_38 ( L_61 ) ;
}
static T_6
F_241 ( struct V_51 * V_51 , char * V_67 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
if ( V_3 )
return sprintf ( V_67 , L_62 , V_3 -> V_100 ) ;
else
return 0 ;
}
int
F_242 ( struct V_51 * V_51 , int V_462 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
int V_251 ;
if ( V_462 <= 16 || V_462 > 32768 )
return - V_463 ;
while ( V_462 < V_3 -> V_100 ) {
if ( F_145 ( V_3 ) )
V_3 -> V_100 -- ;
else
break;
}
V_251 = F_134 ( V_51 ) ;
if ( V_251 )
return V_251 ;
while ( V_462 > V_3 -> V_100 ) {
if ( F_120 ( V_3 ) )
V_3 -> V_100 ++ ;
else break;
}
return 0 ;
}
static T_6
F_243 ( struct V_51 * V_51 , const char * V_67 , T_5 V_167 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
unsigned long V_20 ;
int V_251 ;
if ( V_167 >= V_464 )
return - V_463 ;
if ( ! V_3 )
return - V_465 ;
if ( F_244 ( V_67 , 10 , & V_20 ) )
return - V_463 ;
V_251 = F_242 ( V_51 , V_20 ) ;
if ( V_251 )
return V_251 ;
return V_167 ;
}
static T_6
F_245 ( struct V_51 * V_51 , char * V_67 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
if ( V_3 )
return sprintf ( V_67 , L_62 , V_3 -> V_401 ) ;
else
return 0 ;
}
static T_6
F_246 ( struct V_51 * V_51 , const char * V_67 , T_5 V_167 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
unsigned long V_20 ;
if ( V_167 >= V_464 )
return - V_463 ;
if ( ! V_3 )
return - V_465 ;
if ( F_244 ( V_67 , 10 , & V_20 ) )
return - V_463 ;
if ( V_20 > V_3 -> V_100 )
return - V_463 ;
V_3 -> V_401 = V_20 ;
return V_167 ;
}
static T_6
F_247 ( struct V_51 * V_51 , char * V_67 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
if ( V_3 )
return sprintf ( V_67 , L_62 , F_4 ( & V_3 -> V_41 ) ) ;
else
return 0 ;
}
static T_1
F_220 ( struct V_51 * V_51 , T_1 V_11 , int V_27 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
if ( ! V_11 )
V_11 = V_51 -> V_436 ;
if ( ! V_27 )
V_27 = F_248 ( V_3 -> V_27 , V_3 -> V_76 ) ;
V_11 &= ~ ( ( T_1 ) V_51 -> V_294 - 1 ) ;
V_11 &= ~ ( ( T_1 ) V_51 -> V_390 - 1 ) ;
return V_11 * ( V_27 - V_3 -> V_95 ) ;
}
static void F_249 ( struct V_2 * V_3 )
{
struct V_185 * V_186 ;
unsigned long V_221 ;
if ( ! V_3 -> V_186 )
return;
F_141 () ;
F_250 (cpu) {
V_186 = F_111 ( V_3 -> V_186 , V_221 ) ;
F_251 ( V_186 -> V_217 ) ;
F_140 ( V_186 -> V_187 ) ;
}
#ifdef F_252
F_253 ( & V_3 -> V_466 ) ;
#endif
F_144 () ;
F_254 ( V_3 -> V_186 ) ;
}
static void F_255 ( struct V_2 * V_3 )
{
F_146 ( V_3 ) ;
F_249 ( V_3 ) ;
F_140 ( V_3 -> V_25 ) ;
F_140 ( V_3 -> V_8 ) ;
F_140 ( V_3 ) ;
}
static int F_256 ( struct V_467 * V_468 , unsigned long V_469 ,
void * V_470 )
{
struct V_2 * V_3 = F_203 ( V_468 , struct V_2 , V_466 ) ;
long V_221 = ( long ) V_470 ;
struct V_185 * V_186 = F_111 ( V_3 -> V_186 , V_221 ) ;
switch ( V_469 ) {
case V_471 :
case V_472 :
if ( V_3 -> V_220 == 6 && ! V_186 -> V_217 )
V_186 -> V_217 = F_48 ( V_73 ) ;
if ( ! V_186 -> V_187 )
V_186 -> V_187 = F_143 ( V_3 -> F_131 , V_73 ) ;
if ( ! V_186 -> V_187 ||
( V_3 -> V_220 == 6 && ! V_186 -> V_217 ) ) {
F_251 ( V_186 -> V_217 ) ;
F_140 ( V_186 -> V_187 ) ;
F_257 ( L_63 ,
V_142 , V_221 ) ;
return F_258 ( - V_252 ) ;
}
break;
case V_473 :
case V_474 :
F_251 ( V_186 -> V_217 ) ;
F_140 ( V_186 -> V_187 ) ;
V_186 -> V_217 = NULL ;
V_186 -> V_187 = NULL ;
break;
default:
break;
}
return V_475 ;
}
static int F_259 ( struct V_2 * V_3 )
{
unsigned long V_221 ;
struct V_67 * V_217 ;
struct V_185 T_7 * V_476 ;
void * V_187 ;
int V_251 ;
V_476 = F_260 ( struct V_185 ) ;
if ( ! V_476 )
return - V_252 ;
V_3 -> V_186 = V_476 ;
F_141 () ;
V_251 = 0 ;
F_142 (cpu) {
if ( V_3 -> V_220 == 6 ) {
V_217 = F_48 ( V_73 ) ;
if ( ! V_217 ) {
V_251 = - V_252 ;
break;
}
F_111 ( V_3 -> V_186 , V_221 ) -> V_217 = V_217 ;
}
V_187 = F_143 ( V_3 -> F_131 , V_73 ) ;
if ( ! V_187 ) {
V_251 = - V_252 ;
break;
}
F_111 ( V_3 -> V_186 , V_221 ) -> V_187 = V_187 ;
}
#ifdef F_252
V_3 -> V_466 . V_477 = F_256 ;
V_3 -> V_466 . V_478 = 0 ;
if ( V_251 == 0 )
V_251 = F_261 ( & V_3 -> V_466 ) ;
#endif
F_144 () ;
return V_251 ;
}
static struct V_2 * F_262 ( struct V_51 * V_51 )
{
struct V_2 * V_3 ;
int V_479 , V_480 , V_481 ;
struct V_88 * V_89 ;
struct V_249 * V_26 ;
char V_482 [ 6 ] ;
if ( V_51 -> V_483 != 5
&& V_51 -> V_483 != 4
&& V_51 -> V_483 != 6 ) {
F_51 ( V_83 L_64 ,
F_129 ( V_51 ) , V_51 -> V_483 ) ;
return F_263 ( - V_484 ) ;
}
if ( ( V_51 -> V_483 == 5
&& ! F_264 ( V_51 -> V_485 ) ) ||
( V_51 -> V_483 == 6
&& ! F_265 ( V_51 -> V_485 ) ) ) {
F_51 ( V_83 L_65 ,
F_129 ( V_51 ) , V_51 -> V_485 ) ;
return F_263 ( - V_484 ) ;
}
if ( V_51 -> V_483 == 6 && V_51 -> V_27 < 4 ) {
F_51 ( V_83 L_66 ,
F_129 ( V_51 ) , V_51 -> V_27 ) ;
return F_263 ( - V_463 ) ;
}
if ( ! V_51 -> V_390 ||
( V_51 -> V_390 << 9 ) % V_464 ||
! F_266 ( V_51 -> V_390 ) ) {
F_51 ( V_83 L_67 ,
F_129 ( V_51 ) , V_51 -> V_390 << 9 ) ;
return F_263 ( - V_463 ) ;
}
V_3 = F_139 ( sizeof( struct V_2 ) , V_73 ) ;
if ( V_3 == NULL )
goto abort;
F_124 ( & V_3 -> V_61 ) ;
F_123 ( & V_3 -> V_57 ) ;
F_123 ( & V_3 -> V_232 ) ;
F_126 ( & V_3 -> V_50 ) ;
F_126 ( & V_3 -> V_379 ) ;
F_126 ( & V_3 -> V_45 ) ;
F_126 ( & V_3 -> V_49 ) ;
F_126 ( & V_3 -> V_56 ) ;
F_12 ( & V_3 -> V_41 , 0 ) ;
F_12 ( & V_3 -> V_53 , 0 ) ;
F_12 ( & V_3 -> V_393 , 0 ) ;
V_3 -> V_401 = V_486 ;
V_3 -> V_331 = V_51 -> V_331 - 1 ;
V_3 -> V_27 = V_51 -> V_27 ;
if ( V_51 -> V_93 == V_94 )
V_3 -> V_76 = V_51 -> V_27 ;
else
V_3 -> V_76 = V_51 -> V_27 - V_51 -> V_487 ;
V_481 = F_128 ( V_3 -> V_27 , V_3 -> V_76 ) ;
V_3 -> F_131 = F_131 ( V_481 ) ;
V_3 -> V_25 = F_139 ( V_481 * sizeof( struct V_249 ) ,
V_73 ) ;
if ( ! V_3 -> V_25 )
goto abort;
V_3 -> V_51 = V_51 ;
if ( ( V_3 -> V_8 = F_139 ( V_464 , V_73 ) ) == NULL )
goto abort;
V_3 -> V_220 = V_51 -> V_483 ;
if ( F_259 ( V_3 ) != 0 )
goto abort;
F_38 ( L_68 , F_129 ( V_51 ) ) ;
F_267 (rdev, mddev) {
V_479 = V_89 -> V_479 ;
if ( V_479 >= V_481
|| V_479 < 0 )
continue;
V_26 = V_3 -> V_25 + V_479 ;
if ( F_19 ( V_488 , & V_89 -> V_60 ) ) {
if ( V_26 -> V_91 )
goto abort;
V_26 -> V_91 = V_89 ;
} else {
if ( V_26 -> V_89 )
goto abort;
V_26 -> V_89 = V_89 ;
}
if ( F_19 ( V_92 , & V_89 -> V_60 ) ) {
char V_256 [ V_257 ] ;
F_51 ( V_259 L_69
L_70 ,
F_129 ( V_51 ) , F_148 ( V_89 -> V_139 , V_256 ) , V_479 ) ;
} else if ( V_89 -> V_489 != V_479 )
V_3 -> V_450 = 1 ;
}
V_3 -> V_294 = V_51 -> V_390 ;
V_3 -> V_220 = V_51 -> V_483 ;
if ( V_3 -> V_220 == 6 )
V_3 -> V_95 = 2 ;
else
V_3 -> V_95 = 1 ;
V_3 -> V_290 = V_51 -> V_485 ;
V_3 -> V_100 = V_490 ;
V_3 -> V_103 = V_51 -> V_93 ;
if ( V_3 -> V_103 != V_94 ) {
V_3 -> V_293 = V_51 -> V_294 ;
V_3 -> V_291 = V_51 -> V_491 ;
}
V_480 = V_3 -> V_100 * ( sizeof( struct V_21 ) +
V_481 * ( ( sizeof( struct V_9 ) + V_464 ) ) ) / 1024 ;
if ( F_127 ( V_3 , V_3 -> V_100 ) ) {
F_51 ( V_83
L_71 ,
F_129 ( V_51 ) , V_480 ) ;
goto abort;
} else
F_51 ( V_259 L_72 ,
F_129 ( V_51 ) , V_480 ) ;
sprintf ( V_482 , L_73 , V_51 -> V_483 ) ;
V_3 -> V_52 = F_268 ( F_236 , V_51 , V_482 ) ;
if ( ! V_3 -> V_52 ) {
F_51 ( V_83
L_74 ,
F_129 ( V_51 ) ) ;
goto abort;
}
return V_3 ;
abort:
if ( V_3 ) {
F_255 ( V_3 ) ;
return F_263 ( - V_484 ) ;
} else
return F_263 ( - V_252 ) ;
}
static int F_269 ( int V_479 , int V_492 , int V_27 , int V_95 )
{
switch ( V_492 ) {
case V_300 :
if ( V_479 < V_95 )
return 1 ;
break;
case V_301 :
if ( V_479 >= V_27 - V_95 )
return 1 ;
break;
case V_309 :
if ( V_479 == 0 ||
V_479 == V_27 - 1 )
return 1 ;
break;
case V_305 :
case V_306 :
case V_307 :
case V_308 :
if ( V_479 == V_27 - 1 )
return 1 ;
}
return 0 ;
}
static int F_270 ( struct V_51 * V_51 )
{
struct V_2 * V_3 ;
int V_493 = 0 ;
int V_494 = 0 ;
struct V_88 * V_89 ;
T_1 V_495 = 0 ;
int V_69 ;
long long V_437 = 0 ;
int V_64 = 1 ;
if ( V_51 -> V_335 != V_94 )
F_51 ( V_496 L_75
L_76 ,
F_129 ( V_51 ) ) ;
F_267 (rdev, mddev) {
long long V_497 ;
if ( V_89 -> V_479 < 0 )
continue;
V_497 = ( V_89 -> V_143 - V_89 -> V_144 ) ;
if ( V_64 ) {
V_437 = V_497 ;
V_64 = 0 ;
} else if ( V_51 -> V_416 &&
V_497 < V_437 )
V_437 = V_497 ;
else if ( ! V_51 -> V_416 &&
V_497 > V_437 )
V_437 = V_497 ;
}
if ( V_51 -> V_93 != V_94 ) {
T_1 V_498 , V_499 ;
int V_500 ;
int V_95 = ( V_51 -> V_220 == 6 ? 2 : 1 ) ;
if ( V_51 -> V_483 != V_51 -> V_220 ) {
F_51 ( V_83 L_77
L_78 ,
F_129 ( V_51 ) ) ;
return - V_463 ;
}
V_500 = V_51 -> V_27 - V_51 -> V_487 ;
V_498 = V_51 -> V_93 ;
if ( F_158 ( V_498 , V_51 -> V_390 *
( V_51 -> V_27 - V_95 ) ) ) {
F_51 ( V_83 L_79
L_80 , F_129 ( V_51 ) ) ;
return - V_463 ;
}
V_495 = V_498 * V_51 -> V_390 ;
V_499 = V_51 -> V_93 ;
F_158 ( V_499 , V_51 -> V_294 *
( V_500 - V_95 ) ) ;
if ( V_51 -> V_487 == 0 ) {
if ( ( V_498 * V_51 -> V_390 !=
V_499 * V_51 -> V_294 ) ) {
F_51 ( V_83 L_81
L_82 , F_129 ( V_51 ) ) ;
return - V_463 ;
}
if ( abs ( V_437 ) >= V_51 -> V_294 &&
abs ( V_437 ) >= V_51 -> V_390 )
;
else if ( V_51 -> V_375 == 0 ) {
F_51 ( V_83 L_83
L_84
L_85 ,
F_129 ( V_51 ) ) ;
return - V_463 ;
}
} else if ( V_51 -> V_416
? ( V_498 * V_51 -> V_390 + V_437 <=
V_499 * V_51 -> V_294 )
: ( V_498 * V_51 -> V_390 >=
V_499 * V_51 -> V_294 + ( - V_437 ) ) ) {
F_51 ( V_83 L_86
L_87 ,
F_129 ( V_51 ) ) ;
return - V_463 ;
}
F_51 ( V_259 L_88 ,
F_129 ( V_51 ) ) ;
} else {
F_21 ( V_51 -> V_220 != V_51 -> V_483 ) ;
F_21 ( V_51 -> V_491 != V_51 -> V_485 ) ;
F_21 ( V_51 -> V_294 != V_51 -> V_390 ) ;
F_21 ( V_51 -> V_487 != 0 ) ;
}
if ( V_51 -> V_278 == NULL )
V_3 = F_262 ( V_51 ) ;
else
V_3 = V_51 -> V_278 ;
if ( F_271 ( V_3 ) )
return F_272 ( V_3 ) ;
V_3 -> V_437 = V_437 ;
V_51 -> V_52 = V_3 -> V_52 ;
V_3 -> V_52 = NULL ;
V_51 -> V_278 = V_3 ;
for ( V_69 = 0 ; V_69 < V_3 -> V_27 && V_3 -> V_76 ;
V_69 ++ ) {
V_89 = V_3 -> V_25 [ V_69 ] . V_89 ;
if ( ! V_89 && V_3 -> V_25 [ V_69 ] . V_91 ) {
V_89 = V_3 -> V_25 [ V_69 ] . V_91 ;
V_3 -> V_25 [ V_69 ] . V_91 = NULL ;
F_24 ( V_488 , & V_89 -> V_60 ) ;
V_3 -> V_25 [ V_69 ] . V_89 = V_89 ;
}
if ( ! V_89 )
continue;
if ( V_3 -> V_25 [ V_69 ] . V_91 &&
V_3 -> V_103 != V_94 ) {
F_51 ( V_83 L_89
L_90 ) ;
goto abort;
}
if ( F_19 ( V_92 , & V_89 -> V_60 ) ) {
V_493 ++ ;
continue;
}
if ( V_51 -> V_501 == 0 &&
V_51 -> V_502 > 90 )
V_89 -> V_334 = V_495 ;
if ( V_89 -> V_334 < V_495 ) {
if ( ! F_269 ( V_89 -> V_479 ,
V_3 -> V_290 ,
V_3 -> V_27 ,
V_3 -> V_95 ) )
continue;
}
if ( ! F_269 ( V_89 -> V_479 ,
V_3 -> V_291 ,
V_3 -> V_76 ,
V_3 -> V_95 ) )
continue;
V_494 ++ ;
}
V_51 -> V_86 = F_56 ( V_3 ) ;
if ( F_60 ( V_3 ) ) {
F_51 ( V_83 L_91
L_92 ,
F_129 ( V_51 ) , V_51 -> V_86 , V_3 -> V_27 ) ;
goto abort;
}
V_51 -> V_436 &= ~ ( V_51 -> V_294 - 1 ) ;
V_51 -> V_503 = V_51 -> V_436 ;
if ( V_51 -> V_86 > V_494 &&
V_51 -> V_335 != V_94 ) {
if ( V_51 -> V_504 )
F_51 ( V_266
L_93
L_94 ,
F_129 ( V_51 ) ) ;
else {
F_51 ( V_83
L_95 ,
F_129 ( V_51 ) ) ;
goto abort;
}
}
if ( V_51 -> V_86 == 0 )
F_51 ( V_259 L_96
L_97 , F_129 ( V_51 ) , V_3 -> V_220 ,
V_51 -> V_27 - V_51 -> V_86 , V_51 -> V_27 ,
V_51 -> V_485 ) ;
else
F_51 ( V_282 L_98
L_99 ,
F_129 ( V_51 ) , V_3 -> V_220 ,
V_51 -> V_27 - V_51 -> V_86 ,
V_51 -> V_27 , V_51 -> V_485 ) ;
F_273 ( V_3 ) ;
if ( V_3 -> V_103 != V_94 ) {
V_3 -> V_417 = V_3 -> V_103 ;
F_12 ( & V_3 -> V_377 , 0 ) ;
F_24 ( V_451 , & V_51 -> V_272 ) ;
F_24 ( V_348 , & V_51 -> V_272 ) ;
F_72 ( V_448 , & V_51 -> V_272 ) ;
F_72 ( V_505 , & V_51 -> V_272 ) ;
V_51 -> V_506 = F_268 ( V_507 , V_51 ,
L_100 ) ;
}
if ( V_51 -> V_508 == & V_509 )
V_51 -> V_508 = NULL ;
else if ( V_51 -> V_435 . V_510 &&
F_274 ( & V_51 -> V_435 , & V_509 ) )
F_51 ( V_266
L_101 ,
F_129 ( V_51 ) ) ;
F_275 ( V_51 , F_220 ( V_51 , 0 , 0 ) ) ;
if ( V_51 -> V_511 ) {
int V_512 ;
bool V_513 = true ;
int V_295 = V_3 -> V_76 - V_3 -> V_95 ;
int V_285 = V_295 *
( ( V_51 -> V_294 << 9 ) / V_464 ) ;
if ( V_51 -> V_511 -> V_514 . V_515 < 2 * V_285 )
V_51 -> V_511 -> V_514 . V_515 = 2 * V_285 ;
F_276 ( V_51 -> V_511 , F_186 ) ;
V_51 -> V_511 -> V_514 . V_516 = V_51 ;
V_51 -> V_511 -> V_514 . V_517 = F_184 ;
V_512 = V_51 -> V_294 << 9 ;
F_277 ( V_51 -> V_511 , V_512 ) ;
F_278 ( V_51 -> V_511 , V_512 *
( V_3 -> V_27 - V_3 -> V_95 ) ) ;
V_285 = V_285 * V_464 ;
while ( ( V_285 - 1 ) & V_285 )
V_285 = ( V_285 | ( V_285 - 1 ) ) + 1 ;
V_51 -> V_511 -> V_518 . V_519 = V_285 ;
V_51 -> V_511 -> V_518 . V_520 = V_285 ;
V_51 -> V_511 -> V_518 . V_521 = 0 ;
F_267 (rdev, mddev) {
F_279 ( V_51 -> V_242 , V_89 -> V_139 ,
V_89 -> V_144 << 9 ) ;
F_279 ( V_51 -> V_242 , V_89 -> V_139 ,
V_89 -> V_143 << 9 ) ;
if ( ! F_280 ( F_194 ( V_89 -> V_139 ) ) ||
! F_194 ( V_89 -> V_139 ) ->
V_518 . V_521 )
V_513 = false ;
}
if ( V_513 &&
V_51 -> V_511 -> V_518 . V_522 >= V_285 &&
V_51 -> V_511 -> V_518 . V_520 >= V_285 )
F_281 ( V_523 ,
V_51 -> V_511 ) ;
else
F_282 ( V_523 ,
V_51 -> V_511 ) ;
}
return 0 ;
abort:
F_283 ( & V_51 -> V_52 ) ;
F_273 ( V_3 ) ;
F_255 ( V_3 ) ;
V_51 -> V_278 = NULL ;
F_51 ( V_282 L_102 , F_129 ( V_51 ) ) ;
return - V_484 ;
}
static int F_284 ( struct V_51 * V_51 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
F_283 ( & V_51 -> V_52 ) ;
if ( V_51 -> V_511 )
V_51 -> V_511 -> V_514 . V_517 = NULL ;
F_255 ( V_3 ) ;
V_51 -> V_278 = NULL ;
V_51 -> V_508 = & V_509 ;
return 0 ;
}
static void F_285 ( struct V_524 * V_525 , struct V_51 * V_51 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
int V_69 ;
F_286 ( V_525 , L_103 , V_51 -> V_220 ,
V_51 -> V_294 / 2 , V_51 -> V_491 ) ;
F_286 ( V_525 , L_104 , V_3 -> V_27 , V_3 -> V_27 - V_51 -> V_86 ) ;
for ( V_69 = 0 ; V_69 < V_3 -> V_27 ; V_69 ++ )
F_286 ( V_525 , L_105 ,
V_3 -> V_25 [ V_69 ] . V_89 &&
F_19 ( V_92 , & V_3 -> V_25 [ V_69 ] . V_89 -> V_60 ) ? L_106 : L_107 ) ;
F_286 ( V_525 , L_108 ) ;
}
static void F_273 ( struct V_2 * V_3 )
{
int V_69 ;
struct V_249 * V_526 ;
F_51 ( V_527 L_109 ) ;
if ( ! V_3 ) {
F_51 ( L_110 ) ;
return;
}
F_51 ( V_527 L_111 , V_3 -> V_220 ,
V_3 -> V_27 ,
V_3 -> V_27 - V_3 -> V_51 -> V_86 ) ;
for ( V_69 = 0 ; V_69 < V_3 -> V_27 ; V_69 ++ ) {
char V_256 [ V_257 ] ;
V_526 = V_3 -> V_25 + V_69 ;
if ( V_526 -> V_89 )
F_51 ( V_527 L_112 ,
V_69 , ! F_19 ( V_90 , & V_526 -> V_89 -> V_60 ) ,
F_148 ( V_526 -> V_89 -> V_139 , V_256 ) ) ;
}
}
static int F_287 ( struct V_51 * V_51 )
{
int V_69 ;
struct V_2 * V_3 = V_51 -> V_278 ;
struct V_249 * V_526 ;
int V_29 = 0 ;
unsigned long V_60 ;
for ( V_69 = 0 ; V_69 < V_3 -> V_27 ; V_69 ++ ) {
V_526 = V_3 -> V_25 + V_69 ;
if ( V_526 -> V_91
&& V_526 -> V_91 -> V_334 == V_94
&& ! F_19 ( V_90 , & V_526 -> V_91 -> V_60 )
&& ! F_152 ( V_92 , & V_526 -> V_91 -> V_60 ) ) {
if ( ! V_526 -> V_89
|| ! F_26 ( V_92 , & V_526 -> V_89 -> V_60 ) )
V_29 ++ ;
if ( V_526 -> V_89 ) {
F_72 ( V_90 , & V_526 -> V_89 -> V_60 ) ;
F_288 (
V_526 -> V_89 -> V_528 ) ;
}
F_288 ( V_526 -> V_91 -> V_528 ) ;
} else if ( V_526 -> V_89
&& V_526 -> V_89 -> V_334 == V_94
&& ! F_19 ( V_90 , & V_526 -> V_89 -> V_60 )
&& ! F_152 ( V_92 , & V_526 -> V_89 -> V_60 ) ) {
V_29 ++ ;
F_288 ( V_526 -> V_89 -> V_528 ) ;
}
}
F_155 ( & V_3 -> V_61 , V_60 ) ;
V_51 -> V_86 = F_56 ( V_3 ) ;
F_156 ( & V_3 -> V_61 , V_60 ) ;
F_273 ( V_3 ) ;
return V_29 ;
}
static int F_289 ( struct V_51 * V_51 , struct V_88 * V_89 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
int V_251 = 0 ;
int V_529 = V_89 -> V_479 ;
struct V_88 * * V_530 ;
struct V_249 * V_68 = V_3 -> V_25 + V_529 ;
F_273 ( V_3 ) ;
if ( V_89 == V_68 -> V_89 )
V_530 = & V_68 -> V_89 ;
else if ( V_89 == V_68 -> V_91 )
V_530 = & V_68 -> V_91 ;
else
return 0 ;
if ( V_529 >= V_3 -> V_27 &&
V_3 -> V_103 == V_94 )
F_24 ( V_92 , & V_89 -> V_60 ) ;
if ( F_19 ( V_92 , & V_89 -> V_60 ) ||
F_4 ( & V_89 -> V_128 ) ) {
V_251 = - V_531 ;
goto abort;
}
if ( ! F_19 ( V_90 , & V_89 -> V_60 ) &&
V_51 -> V_331 != V_3 -> V_331 &&
! F_60 ( V_3 ) &&
( ! V_68 -> V_91 || V_68 -> V_91 == V_89 ) &&
V_529 < V_3 -> V_27 ) {
V_251 = - V_531 ;
goto abort;
}
* V_530 = NULL ;
F_290 () ;
if ( F_4 ( & V_89 -> V_128 ) ) {
V_251 = - V_531 ;
* V_530 = V_89 ;
} else if ( V_68 -> V_91 ) {
V_68 -> V_89 = V_68 -> V_91 ;
F_24 ( V_488 , & V_68 -> V_91 -> V_60 ) ;
F_70 () ;
V_68 -> V_91 = NULL ;
F_24 ( V_270 , & V_89 -> V_60 ) ;
} else
F_24 ( V_270 , & V_89 -> V_60 ) ;
abort:
F_273 ( V_3 ) ;
return V_251 ;
}
static int F_291 ( struct V_51 * V_51 , struct V_88 * V_89 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
int V_251 = - V_532 ;
int V_26 ;
struct V_249 * V_68 ;
int V_64 = 0 ;
int V_533 = V_3 -> V_27 - 1 ;
if ( V_51 -> V_331 == V_3 -> V_331 )
return - V_531 ;
if ( V_89 -> V_489 < 0 && F_60 ( V_3 ) )
return - V_463 ;
if ( V_89 -> V_479 >= 0 )
V_64 = V_533 = V_89 -> V_479 ;
if ( V_89 -> V_489 >= 0 &&
V_89 -> V_489 >= V_64 &&
V_3 -> V_25 [ V_89 -> V_489 ] . V_89 == NULL )
V_64 = V_89 -> V_489 ;
for ( V_26 = V_64 ; V_26 <= V_533 ; V_26 ++ ) {
V_68 = V_3 -> V_25 + V_26 ;
if ( V_68 -> V_89 == NULL ) {
F_24 ( V_92 , & V_89 -> V_60 ) ;
V_89 -> V_479 = V_26 ;
V_251 = 0 ;
if ( V_89 -> V_489 != V_26 )
V_3 -> V_450 = 1 ;
F_292 ( V_68 -> V_89 , V_89 ) ;
goto V_65;
}
}
for ( V_26 = V_64 ; V_26 <= V_533 ; V_26 ++ ) {
V_68 = V_3 -> V_25 + V_26 ;
if ( F_19 ( V_270 , & V_68 -> V_89 -> V_60 ) &&
V_68 -> V_91 == NULL ) {
F_24 ( V_92 , & V_89 -> V_60 ) ;
F_72 ( V_488 , & V_89 -> V_60 ) ;
V_89 -> V_479 = V_26 ;
V_251 = 0 ;
V_3 -> V_450 = 1 ;
F_292 ( V_68 -> V_91 , V_89 ) ;
break;
}
}
V_65:
F_273 ( V_3 ) ;
return V_251 ;
}
static int F_293 ( struct V_51 * V_51 , T_1 V_11 )
{
T_1 V_245 ;
V_11 &= ~ ( ( T_1 ) V_51 -> V_294 - 1 ) ;
V_245 = F_220 ( V_51 , V_11 , V_51 -> V_27 ) ;
if ( V_51 -> V_534 &&
V_51 -> V_535 > V_245 )
return - V_463 ;
if ( V_51 -> V_323 ) {
int V_536 = F_294 ( V_51 -> V_323 , V_11 , 0 , 0 ) ;
if ( V_536 )
return V_536 ;
}
F_275 ( V_51 , V_245 ) ;
F_295 ( V_51 -> V_242 , V_51 -> V_535 ) ;
F_296 ( V_51 -> V_242 ) ;
if ( V_11 > V_51 -> V_436 &&
V_51 -> V_335 > V_51 -> V_436 ) {
V_51 -> V_335 = V_51 -> V_436 ;
F_72 ( V_271 , & V_51 -> V_272 ) ;
}
V_51 -> V_436 = V_11 ;
V_51 -> V_503 = V_11 ;
return 0 ;
}
static int F_297 ( struct V_51 * V_51 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
if ( ( ( V_51 -> V_294 << 9 ) / V_152 ) * 4
> V_3 -> V_100 ||
( ( V_51 -> V_390 << 9 ) / V_152 ) * 4
> V_3 -> V_100 ) {
F_51 ( V_266 L_113 ,
F_129 ( V_51 ) ,
( ( F_128 ( V_51 -> V_294 , V_51 -> V_390 ) << 9 )
/ V_152 ) * 4 ) ;
return 0 ;
}
return 1 ;
}
static int F_298 ( struct V_51 * V_51 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
if ( V_51 -> V_487 == 0 &&
V_51 -> V_485 == V_51 -> V_491 &&
V_51 -> V_390 == V_51 -> V_294 )
return 0 ;
if ( F_60 ( V_3 ) )
return - V_463 ;
if ( V_51 -> V_487 < 0 ) {
int F_248 = 2 ;
if ( V_51 -> V_220 == 6 )
F_248 = 4 ;
if ( V_51 -> V_27 + V_51 -> V_487 < F_248 )
return - V_463 ;
}
if ( ! F_297 ( V_51 ) )
return - V_537 ;
return F_132 ( V_3 , ( V_3 -> V_76
+ V_51 -> V_487 ) ) ;
}
static int F_299 ( struct V_51 * V_51 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
struct V_88 * V_89 ;
int V_538 = 0 ;
unsigned long V_60 ;
if ( F_19 ( V_505 , & V_51 -> V_272 ) )
return - V_531 ;
if ( ! F_297 ( V_51 ) )
return - V_537 ;
if ( F_60 ( V_3 ) )
return - V_463 ;
F_267 (rdev, mddev) {
if ( ! F_19 ( V_92 , & V_89 -> V_60 )
&& ! F_19 ( V_90 , & V_89 -> V_60 ) )
V_538 ++ ;
}
if ( V_538 - V_51 -> V_86 < V_51 -> V_487 - V_3 -> V_95 )
return - V_463 ;
if ( F_220 ( V_51 , 0 , V_3 -> V_27 + V_51 -> V_487 )
< V_51 -> V_535 ) {
F_51 ( V_83 L_114
L_115 , F_129 ( V_51 ) ) ;
return - V_463 ;
}
F_12 ( & V_3 -> V_377 , 0 ) ;
F_62 ( & V_3 -> V_61 ) ;
V_3 -> V_76 = V_3 -> V_27 ;
V_3 -> V_27 += V_51 -> V_487 ;
V_3 -> V_293 = V_3 -> V_294 ;
V_3 -> V_294 = V_51 -> V_390 ;
V_3 -> V_291 = V_3 -> V_290 ;
V_3 -> V_290 = V_51 -> V_485 ;
V_3 -> V_75 ++ ;
F_70 () ;
if ( V_51 -> V_416 )
V_3 -> V_103 = F_220 ( V_51 , 0 , 0 ) ;
else
V_3 -> V_103 = 0 ;
V_3 -> V_417 = V_3 -> V_103 ;
F_65 ( & V_3 -> V_61 ) ;
if ( V_51 -> V_487 >= 0 ) {
F_267 (rdev, mddev)
if ( V_89 -> V_479 < 0 &&
! F_19 ( V_90 , & V_89 -> V_60 ) ) {
if ( F_291 ( V_51 , V_89 ) == 0 ) {
if ( V_89 -> V_479
>= V_3 -> V_76 )
F_72 ( V_92 , & V_89 -> V_60 ) ;
else
V_89 -> V_334 = 0 ;
if ( F_300 ( V_51 , V_89 ) )
;
}
} else if ( V_89 -> V_479 >= V_3 -> V_76
&& ! F_19 ( V_90 , & V_89 -> V_60 ) ) {
F_72 ( V_92 , & V_89 -> V_60 ) ;
}
F_155 ( & V_3 -> V_61 , V_60 ) ;
V_51 -> V_86 = F_56 ( V_3 ) ;
F_156 ( & V_3 -> V_61 , V_60 ) ;
}
V_51 -> V_27 = V_3 -> V_27 ;
V_51 -> V_93 = V_3 -> V_103 ;
F_72 ( V_281 , & V_51 -> V_60 ) ;
F_24 ( V_451 , & V_51 -> V_272 ) ;
F_24 ( V_348 , & V_51 -> V_272 ) ;
F_72 ( V_448 , & V_51 -> V_272 ) ;
F_72 ( V_505 , & V_51 -> V_272 ) ;
V_51 -> V_506 = F_268 ( V_507 , V_51 ,
L_100 ) ;
if ( ! V_51 -> V_506 ) {
V_51 -> V_272 = 0 ;
F_62 ( & V_3 -> V_61 ) ;
V_51 -> V_27 = V_3 -> V_27 = V_3 -> V_76 ;
F_267 (rdev, mddev)
V_89 -> V_143 = V_89 -> V_144 ;
F_301 () ;
V_3 -> V_103 = V_94 ;
V_51 -> V_93 = V_94 ;
F_65 ( & V_3 -> V_61 ) ;
return - V_539 ;
}
V_3 -> V_439 = V_438 ;
F_25 ( V_51 -> V_506 ) ;
F_302 ( V_51 ) ;
return 0 ;
}
static void F_227 ( struct V_2 * V_3 )
{
if ( ! F_19 ( V_279 , & V_3 -> V_51 -> V_272 ) ) {
struct V_88 * V_89 ;
F_62 ( & V_3 -> V_61 ) ;
V_3 -> V_76 = V_3 -> V_27 ;
F_267 (rdev, conf->mddev)
V_89 -> V_144 = V_89 -> V_143 ;
F_301 () ;
V_3 -> V_103 = V_94 ;
F_65 ( & V_3 -> V_61 ) ;
F_29 ( & V_3 -> V_232 ) ;
if ( V_3 -> V_51 -> V_511 ) {
int V_295 = V_3 -> V_27 - V_3 -> V_95 ;
int V_285 = V_295 * ( ( V_3 -> V_294 << 9 )
/ V_464 ) ;
if ( V_3 -> V_51 -> V_511 -> V_514 . V_515 < 2 * V_285 )
V_3 -> V_51 -> V_511 -> V_514 . V_515 = 2 * V_285 ;
}
}
}
static void F_303 ( struct V_51 * V_51 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
if ( ! F_19 ( V_279 , & V_51 -> V_272 ) ) {
if ( V_51 -> V_487 > 0 ) {
F_275 ( V_51 , F_220 ( V_51 , 0 , 0 ) ) ;
F_295 ( V_51 -> V_242 , V_51 -> V_535 ) ;
F_296 ( V_51 -> V_242 ) ;
} else {
int V_413 ;
F_62 ( & V_3 -> V_61 ) ;
V_51 -> V_86 = F_56 ( V_3 ) ;
F_65 ( & V_3 -> V_61 ) ;
for ( V_413 = V_3 -> V_27 ;
V_413 < V_3 -> V_27 - V_51 -> V_487 ;
V_413 ++ ) {
struct V_88 * V_89 = V_3 -> V_25 [ V_413 ] . V_89 ;
if ( V_89 )
F_24 ( V_92 , & V_89 -> V_60 ) ;
V_89 = V_3 -> V_25 [ V_413 ] . V_91 ;
if ( V_89 )
F_24 ( V_92 , & V_89 -> V_60 ) ;
}
}
V_51 -> V_491 = V_3 -> V_290 ;
V_51 -> V_294 = V_3 -> V_294 ;
V_51 -> V_93 = V_94 ;
V_51 -> V_487 = 0 ;
V_51 -> V_416 = 0 ;
}
}
static void F_304 ( struct V_51 * V_51 , int V_38 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
switch( V_38 ) {
case 2 :
F_29 ( & V_3 -> V_232 ) ;
break;
case 1 :
F_62 ( & V_3 -> V_61 ) ;
V_3 -> V_98 = 2 ;
F_63 ( V_3 -> V_57 ,
F_4 ( & V_3 -> V_41 ) == 0 &&
F_4 ( & V_3 -> V_393 ) == 0 ,
V_3 -> V_61 , ) ;
V_3 -> V_98 = 1 ;
F_65 ( & V_3 -> V_61 ) ;
F_29 ( & V_3 -> V_232 ) ;
break;
case 0 :
F_62 ( & V_3 -> V_61 ) ;
V_3 -> V_98 = 0 ;
F_29 ( & V_3 -> V_57 ) ;
F_29 ( & V_3 -> V_232 ) ;
F_65 ( & V_3 -> V_61 ) ;
break;
}
}
static void * F_305 ( struct V_51 * V_51 , int V_220 )
{
struct V_540 * V_541 = V_51 -> V_278 ;
T_1 V_11 ;
if ( V_541 -> V_542 > 1 ) {
F_51 ( V_83 L_116 ,
F_129 ( V_51 ) ) ;
return F_263 ( - V_463 ) ;
}
V_11 = V_541 -> V_543 [ 0 ] . V_544 ;
F_158 ( V_11 , V_541 -> V_543 [ 0 ] . V_545 ) ;
V_51 -> V_436 = V_11 ;
V_51 -> V_483 = V_220 ;
V_51 -> V_485 = V_301 ;
V_51 -> V_390 = V_51 -> V_294 ;
V_51 -> V_27 += 1 ;
V_51 -> V_487 = 1 ;
V_51 -> V_335 = V_94 ;
return F_262 ( V_51 ) ;
}
static void * F_306 ( struct V_51 * V_51 )
{
int V_546 ;
if ( V_51 -> V_27 != 2 ||
V_51 -> V_86 > 1 )
return F_263 ( - V_463 ) ;
V_546 = 64 * 2 ;
while ( V_546 && ( V_51 -> V_535 & ( V_546 - 1 ) ) )
V_546 >>= 1 ;
if ( ( V_546 << 9 ) < V_152 )
return F_263 ( - V_463 ) ;
V_51 -> V_483 = 5 ;
V_51 -> V_485 = V_298 ;
V_51 -> V_390 = V_546 ;
return F_262 ( V_51 ) ;
}
static void * F_307 ( struct V_51 * V_51 )
{
int V_485 ;
switch ( V_51 -> V_491 ) {
case V_305 :
V_485 = V_296 ;
break;
case V_306 :
V_485 = V_297 ;
break;
case V_307 :
V_485 = V_298 ;
break;
case V_308 :
V_485 = V_299 ;
break;
case V_309 :
V_485 = V_300 ;
break;
case V_301 :
V_485 = V_301 ;
break;
default:
return F_263 ( - V_463 ) ;
}
V_51 -> V_483 = 5 ;
V_51 -> V_485 = V_485 ;
V_51 -> V_487 = - 1 ;
V_51 -> V_27 -= 1 ;
return F_262 ( V_51 ) ;
}
static int F_308 ( struct V_51 * V_51 )
{
struct V_2 * V_3 = V_51 -> V_278 ;
int V_547 = V_51 -> V_390 ;
if ( V_51 -> V_485 >= 0 && ! F_264 ( V_51 -> V_485 ) )
return - V_463 ;
if ( V_547 > 0 ) {
if ( ! F_266 ( V_547 ) )
return - V_463 ;
if ( V_547 < ( V_464 >> 9 ) )
return - V_463 ;
if ( V_51 -> V_535 & ( V_547 - 1 ) )
return - V_463 ;
}
if ( V_51 -> V_27 == 2 ) {
if ( V_51 -> V_485 >= 0 ) {
V_3 -> V_290 = V_51 -> V_485 ;
V_51 -> V_491 = V_51 -> V_485 ;
}
if ( V_547 > 0 ) {
V_3 -> V_294 = V_547 ;
V_51 -> V_294 = V_547 ;
}
F_72 ( V_281 , & V_51 -> V_60 ) ;
F_25 ( V_51 -> V_52 ) ;
}
return F_298 ( V_51 ) ;
}
static int F_309 ( struct V_51 * V_51 )
{
int V_547 = V_51 -> V_390 ;
if ( V_51 -> V_485 >= 0 && ! F_265 ( V_51 -> V_485 ) )
return - V_463 ;
if ( V_547 > 0 ) {
if ( ! F_266 ( V_547 ) )
return - V_463 ;
if ( V_547 < ( V_464 >> 9 ) )
return - V_463 ;
if ( V_51 -> V_535 & ( V_547 - 1 ) )
return - V_463 ;
}
return F_298 ( V_51 ) ;
}
static void * F_310 ( struct V_51 * V_51 )
{
if ( V_51 -> V_220 == 0 )
return F_305 ( V_51 , 5 ) ;
if ( V_51 -> V_220 == 1 )
return F_306 ( V_51 ) ;
if ( V_51 -> V_220 == 4 ) {
V_51 -> V_485 = V_301 ;
V_51 -> V_483 = 5 ;
return F_262 ( V_51 ) ;
}
if ( V_51 -> V_220 == 6 )
return F_307 ( V_51 ) ;
return F_263 ( - V_463 ) ;
}
static void * F_311 ( struct V_51 * V_51 )
{
if ( V_51 -> V_220 == 0 )
return F_305 ( V_51 , 4 ) ;
if ( V_51 -> V_220 == 5 &&
V_51 -> V_491 == V_301 ) {
V_51 -> V_485 = 0 ;
V_51 -> V_483 = 4 ;
return F_262 ( V_51 ) ;
}
return F_263 ( - V_463 ) ;
}
static void * F_312 ( struct V_51 * V_51 )
{
int V_485 ;
if ( V_51 -> V_548 != & V_549 )
return F_263 ( - V_463 ) ;
if ( V_51 -> V_86 > 1 )
return F_263 ( - V_463 ) ;
if ( V_51 -> V_27 > 253 )
return F_263 ( - V_463 ) ;
if ( V_51 -> V_27 < 3 )
return F_263 ( - V_463 ) ;
switch ( V_51 -> V_491 ) {
case V_296 :
V_485 = V_305 ;
break;
case V_297 :
V_485 = V_306 ;
break;
case V_298 :
V_485 = V_307 ;
break;
case V_299 :
V_485 = V_308 ;
break;
case V_300 :
V_485 = V_309 ;
break;
case V_301 :
V_485 = V_301 ;
break;
default:
return F_263 ( - V_463 ) ;
}
V_51 -> V_483 = 6 ;
V_51 -> V_485 = V_485 ;
V_51 -> V_487 = 1 ;
V_51 -> V_27 += 1 ;
return F_262 ( V_51 ) ;
}
static int T_8 F_313 ( void )
{
F_314 ( & V_550 ) ;
F_314 ( & V_549 ) ;
F_314 ( & V_551 ) ;
return 0 ;
}
static void F_315 ( void )
{
F_316 ( & V_550 ) ;
F_316 ( & V_549 ) ;
F_316 ( & V_551 ) ;
}
