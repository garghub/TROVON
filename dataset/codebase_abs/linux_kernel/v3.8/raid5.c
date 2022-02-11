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
F_17 ( F_18 ( V_34 -> V_35 ) ,
V_34 , 0 ) ;
F_19 ( V_34 , 0 ) ;
V_34 = V_33 ;
}
}
static int F_20 ( struct V_21 * V_22 )
{
return V_22 -> V_36 || V_22 -> V_37 ||
F_21 ( V_38 , & V_22 -> V_39 ) ||
F_21 ( V_40 , & V_22 -> V_39 ) ;
}
static void F_22 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
F_23 ( ! F_24 ( & V_22 -> V_41 ) ) ;
F_23 ( F_4 ( & V_3 -> V_42 ) == 0 ) ;
if ( F_21 ( V_43 , & V_22 -> V_39 ) ) {
if ( F_21 ( V_44 , & V_22 -> V_39 ) &&
! F_21 ( V_45 , & V_22 -> V_39 ) )
F_25 ( & V_22 -> V_41 , & V_3 -> V_46 ) ;
else if ( F_21 ( V_47 , & V_22 -> V_39 ) &&
V_22 -> V_48 - V_3 -> V_49 > 0 )
F_25 ( & V_22 -> V_41 , & V_3 -> V_50 ) ;
else {
F_26 ( V_44 , & V_22 -> V_39 ) ;
F_26 ( V_47 , & V_22 -> V_39 ) ;
F_25 ( & V_22 -> V_41 , & V_3 -> V_51 ) ;
}
F_27 ( V_3 -> V_52 -> V_53 ) ;
} else {
F_23 ( F_20 ( V_22 ) ) ;
if ( F_28 ( V_45 , & V_22 -> V_39 ) )
if ( F_29 ( & V_3 -> V_54 )
< V_55 )
F_27 ( V_3 -> V_52 -> V_53 ) ;
F_30 ( & V_3 -> V_42 ) ;
if ( ! F_21 ( V_56 , & V_22 -> V_39 ) ) {
F_25 ( & V_22 -> V_41 , & V_3 -> V_57 ) ;
F_31 ( & V_3 -> V_58 ) ;
if ( V_3 -> V_59 )
F_27 ( V_3 -> V_52 -> V_53 ) ;
}
}
}
static void F_32 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
if ( F_33 ( & V_22 -> V_29 ) )
F_22 ( V_3 , V_22 ) ;
}
static void F_34 ( struct V_21 * V_22 )
{
struct V_2 * V_3 = V_22 -> V_60 ;
unsigned long V_61 ;
F_35 ( V_61 ) ;
if ( F_36 ( & V_22 -> V_29 , & V_3 -> V_62 ) ) {
F_22 ( V_3 , V_22 ) ;
F_37 ( & V_3 -> V_62 ) ;
}
F_38 ( V_61 ) ;
}
static inline void F_39 ( struct V_21 * V_22 )
{
F_40 ( L_1 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_41 ( & V_22 -> V_5 ) ;
}
static inline void F_42 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
struct V_1 * V_63 = F_1 ( V_3 , V_22 -> V_10 ) ;
F_40 ( L_2 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_43 ( & V_22 -> V_5 , V_63 ) ;
}
static struct V_21 * F_44 ( struct V_2 * V_3 )
{
struct V_21 * V_22 = NULL ;
struct V_64 * V_65 ;
if ( F_24 ( & V_3 -> V_57 ) )
goto V_66;
V_65 = V_3 -> V_57 . V_67 ;
V_22 = F_45 ( V_65 , struct V_21 , V_41 ) ;
F_46 ( V_65 ) ;
F_39 ( V_22 ) ;
F_8 ( & V_3 -> V_42 ) ;
V_66:
return V_22 ;
}
static void F_47 ( struct V_21 * V_22 )
{
struct V_68 * V_69 ;
int V_70 ;
int V_71 = V_22 -> V_60 -> V_72 ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
V_69 = V_22 -> V_73 [ V_70 ] . V_68 ;
if ( ! V_69 )
continue;
V_22 -> V_73 [ V_70 ] . V_68 = NULL ;
F_48 ( V_69 ) ;
}
}
static int F_49 ( struct V_21 * V_22 )
{
int V_70 ;
int V_71 = V_22 -> V_60 -> V_72 ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
struct V_68 * V_68 ;
if ( ! ( V_68 = F_50 ( V_74 ) ) ) {
return 1 ;
}
V_22 -> V_73 [ V_70 ] . V_68 = V_68 ;
}
return 0 ;
}
static void F_51 ( struct V_21 * V_22 , T_1 V_10 , int V_75 )
{
struct V_2 * V_3 = V_22 -> V_60 ;
int V_70 ;
F_23 ( F_4 ( & V_22 -> V_29 ) != 0 ) ;
F_23 ( F_21 ( V_43 , & V_22 -> V_39 ) ) ;
F_23 ( F_20 ( V_22 ) ) ;
F_40 ( L_3 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_39 ( V_22 ) ;
V_22 -> V_76 = V_3 -> V_76 - V_75 ;
V_22 -> V_25 = V_75 ? V_3 -> V_77 : V_3 -> V_27 ;
V_22 -> V_10 = V_10 ;
F_52 ( V_10 , V_3 , V_75 , V_22 ) ;
V_22 -> V_39 = 0 ;
for ( V_70 = V_22 -> V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( V_73 -> V_79 || V_73 -> V_80 || V_73 -> V_81 || V_73 -> V_82 ||
F_21 ( V_83 , & V_73 -> V_61 ) ) {
F_53 ( V_84 L_4 ,
( unsigned long long ) V_22 -> V_10 , V_70 , V_73 -> V_79 ,
V_73 -> V_80 , V_73 -> V_81 , V_73 -> V_82 ,
F_21 ( V_83 , & V_73 -> V_61 ) ) ;
F_54 ( 1 ) ;
}
V_73 -> V_61 = 0 ;
F_55 ( V_22 , V_70 , V_75 ) ;
}
F_42 ( V_3 , V_22 ) ;
}
static struct V_21 * F_56 ( struct V_2 * V_3 , T_1 V_10 ,
short V_76 )
{
struct V_21 * V_22 ;
struct V_85 * V_86 ;
F_40 ( L_5 , ( unsigned long long ) V_10 ) ;
F_57 (sh, hn, stripe_hash(conf, sector), hash)
if ( V_22 -> V_10 == V_10 && V_22 -> V_76 == V_76 )
return V_22 ;
F_40 ( L_6 , ( unsigned long long ) V_10 ) ;
return NULL ;
}
static int F_58 ( struct V_2 * V_3 )
{
int V_87 , V_88 ;
int V_70 ;
F_59 () ;
V_87 = 0 ;
for ( V_70 = 0 ; V_70 < V_3 -> V_77 ; V_70 ++ ) {
struct V_89 * V_90 = F_60 ( V_3 -> V_25 [ V_70 ] . V_90 ) ;
if ( V_90 && F_21 ( V_91 , & V_90 -> V_61 ) )
V_90 = F_60 ( V_3 -> V_25 [ V_70 ] . V_92 ) ;
if ( ! V_90 || F_21 ( V_91 , & V_90 -> V_61 ) )
V_87 ++ ;
else if ( F_21 ( V_93 , & V_90 -> V_61 ) )
;
else
if ( V_3 -> V_27 >= V_3 -> V_77 )
V_87 ++ ;
}
F_61 () ;
if ( V_3 -> V_27 == V_3 -> V_77 )
return V_87 ;
F_59 () ;
V_88 = 0 ;
for ( V_70 = 0 ; V_70 < V_3 -> V_27 ; V_70 ++ ) {
struct V_89 * V_90 = F_60 ( V_3 -> V_25 [ V_70 ] . V_90 ) ;
if ( V_90 && F_21 ( V_91 , & V_90 -> V_61 ) )
V_90 = F_60 ( V_3 -> V_25 [ V_70 ] . V_92 ) ;
if ( ! V_90 || F_21 ( V_91 , & V_90 -> V_61 ) )
V_88 ++ ;
else if ( F_21 ( V_93 , & V_90 -> V_61 ) )
;
else
if ( V_3 -> V_27 <= V_3 -> V_77 )
V_88 ++ ;
}
F_61 () ;
if ( V_88 > V_87 )
return V_88 ;
return V_87 ;
}
static int F_62 ( struct V_2 * V_3 )
{
int V_87 ;
if ( V_3 -> V_52 -> V_94 == V_95 )
return V_3 -> V_52 -> V_87 > V_3 -> V_96 ;
V_87 = F_58 ( V_3 ) ;
if ( V_87 > V_3 -> V_96 )
return 1 ;
return 0 ;
}
static struct V_21 *
F_63 ( struct V_2 * V_3 , T_1 V_10 ,
int V_75 , int V_97 , int V_98 )
{
struct V_21 * V_22 ;
F_40 ( L_7 , ( unsigned long long ) V_10 ) ;
F_64 ( & V_3 -> V_62 ) ;
do {
F_65 ( V_3 -> V_58 ,
V_3 -> V_99 == 0 || V_98 ,
V_3 -> V_62 ) ;
V_22 = F_56 ( V_3 , V_10 , V_3 -> V_76 - V_75 ) ;
if ( ! V_22 ) {
if ( ! V_3 -> V_100 )
V_22 = F_44 ( V_3 ) ;
if ( V_97 && V_22 == NULL )
break;
if ( ! V_22 ) {
V_3 -> V_100 = 1 ;
F_65 ( V_3 -> V_58 ,
! F_24 ( & V_3 -> V_57 ) &&
( F_4 ( & V_3 -> V_42 )
< ( V_3 -> V_101 * 3 / 4 )
|| ! V_3 -> V_100 ) ,
V_3 -> V_62 ) ;
V_3 -> V_100 = 0 ;
} else
F_51 ( V_22 , V_10 , V_75 ) ;
} else {
if ( F_4 ( & V_22 -> V_29 ) ) {
F_23 ( ! F_24 ( & V_22 -> V_41 )
&& ! F_21 ( V_56 , & V_22 -> V_39 )
&& ! F_21 ( V_102 , & V_22 -> V_39 ) ) ;
} else {
if ( ! F_21 ( V_43 , & V_22 -> V_39 ) )
F_8 ( & V_3 -> V_42 ) ;
if ( F_24 ( & V_22 -> V_41 ) &&
! F_21 ( V_56 , & V_22 -> V_39 ) )
F_66 () ;
F_46 ( & V_22 -> V_41 ) ;
}
}
} while ( V_22 == NULL );
if ( V_22 )
F_8 ( & V_22 -> V_29 ) ;
F_67 ( & V_3 -> V_62 ) ;
return V_22 ;
}
static int F_68 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
T_1 V_103 = V_3 -> V_104 ;
F_69 () ;
if ( V_103 == V_95 )
return 0 ;
if ( V_22 -> V_76 == V_3 -> V_76 - 1 )
return 0 ;
return 1 ;
}
static void F_70 ( struct V_21 * V_22 , struct V_105 * V_106 )
{
struct V_2 * V_3 = V_22 -> V_60 ;
int V_70 , V_25 = V_22 -> V_25 ;
F_71 () ;
for ( V_70 = V_25 ; V_70 -- ; ) {
int V_107 ;
int V_108 = 0 ;
struct V_9 * V_34 , * V_109 ;
struct V_89 * V_90 , * V_110 = NULL ;
if ( F_28 ( V_111 , & V_22 -> V_73 [ V_70 ] . V_61 ) ) {
if ( F_28 ( V_112 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
V_107 = V_113 ;
else
V_107 = V_114 ;
if ( F_21 ( V_115 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
V_107 |= V_116 ;
} else if ( F_28 ( V_117 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
V_107 = V_118 ;
else if ( F_28 ( V_119 ,
& V_22 -> V_73 [ V_70 ] . V_61 ) ) {
V_107 = V_114 ;
V_108 = 1 ;
} else
continue;
if ( F_28 ( V_120 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
V_107 |= V_121 ;
V_34 = & V_22 -> V_73 [ V_70 ] . V_122 ;
V_109 = & V_22 -> V_73 [ V_70 ] . V_123 ;
V_34 -> V_124 = V_107 ;
V_109 -> V_124 = V_107 ;
if ( V_107 & V_114 ) {
V_34 -> V_125 = V_126 ;
V_109 -> V_125 = V_126 ;
} else
V_34 -> V_125 = V_127 ;
F_59 () ;
V_110 = F_60 ( V_3 -> V_25 [ V_70 ] . V_92 ) ;
F_72 () ;
V_90 = F_60 ( V_3 -> V_25 [ V_70 ] . V_90 ) ;
if ( ! V_90 ) {
V_90 = V_110 ;
V_110 = NULL ;
}
if ( V_107 & V_114 ) {
if ( V_108 )
V_90 = NULL ;
if ( V_90 == V_110 )
V_110 = NULL ;
} else {
if ( F_21 ( V_128 , & V_22 -> V_73 [ V_70 ] . V_61 ) && V_110 )
V_90 = V_110 ;
V_110 = NULL ;
}
if ( V_90 && F_21 ( V_91 , & V_90 -> V_61 ) )
V_90 = NULL ;
if ( V_90 )
F_8 ( & V_90 -> V_129 ) ;
if ( V_110 && F_21 ( V_91 , & V_110 -> V_61 ) )
V_110 = NULL ;
if ( V_110 )
F_8 ( & V_110 -> V_129 ) ;
F_61 () ;
while ( ( V_107 & V_114 ) && V_90 &&
F_21 ( V_130 , & V_90 -> V_61 ) ) {
T_1 V_131 ;
int V_132 ;
int V_133 = F_73 ( V_90 , V_22 -> V_10 , V_14 ,
& V_131 , & V_132 ) ;
if ( ! V_133 )
break;
if ( V_133 < 0 ) {
F_74 ( V_134 , & V_90 -> V_61 ) ;
if ( ! V_3 -> V_52 -> V_135 &&
V_3 -> V_52 -> V_61 ) {
F_75 ( V_3 -> V_52 ) ;
}
F_8 ( & V_90 -> V_129 ) ;
F_76 ( V_90 , V_3 -> V_52 ) ;
} else {
F_77 ( V_90 , V_3 -> V_52 ) ;
V_90 = NULL ;
}
}
if ( V_90 ) {
if ( V_106 -> V_136 || V_106 -> V_137 || V_106 -> V_138
|| V_106 -> V_139 )
F_78 ( V_90 -> V_140 , V_14 ) ;
F_74 ( V_141 , & V_22 -> V_39 ) ;
V_34 -> V_35 = V_90 -> V_140 ;
F_40 ( L_8 ,
V_142 , ( unsigned long long ) V_22 -> V_10 ,
V_34 -> V_124 , V_70 ) ;
F_8 ( & V_22 -> V_29 ) ;
if ( F_68 ( V_3 , V_22 ) )
V_34 -> V_13 = ( V_22 -> V_10
+ V_90 -> V_143 ) ;
else
V_34 -> V_13 = ( V_22 -> V_10
+ V_90 -> V_144 ) ;
if ( F_21 ( V_145 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
V_34 -> V_124 |= V_146 ;
V_34 -> V_147 = 1 << V_148 ;
V_34 -> V_149 = 0 ;
V_34 -> V_150 [ 0 ] . V_151 = V_152 ;
V_34 -> V_150 [ 0 ] . V_153 = 0 ;
V_34 -> V_12 = V_152 ;
V_34 -> V_15 = NULL ;
if ( V_110 )
F_74 ( V_154 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_79 ( F_18 ( V_34 -> V_35 ) ,
V_34 , F_80 ( V_3 -> V_52 -> V_155 ) ,
V_22 -> V_73 [ V_70 ] . V_10 ) ;
F_81 ( V_34 ) ;
}
if ( V_110 ) {
if ( V_106 -> V_136 || V_106 -> V_137 || V_106 -> V_138
|| V_106 -> V_139 )
F_78 ( V_110 -> V_140 , V_14 ) ;
F_74 ( V_141 , & V_22 -> V_39 ) ;
V_109 -> V_35 = V_110 -> V_140 ;
F_40 ( L_9
L_10 ,
V_142 , ( unsigned long long ) V_22 -> V_10 ,
V_109 -> V_124 , V_70 ) ;
F_8 ( & V_22 -> V_29 ) ;
if ( F_68 ( V_3 , V_22 ) )
V_109 -> V_13 = ( V_22 -> V_10
+ V_110 -> V_143 ) ;
else
V_109 -> V_13 = ( V_22 -> V_10
+ V_110 -> V_144 ) ;
V_109 -> V_147 = 1 << V_148 ;
V_109 -> V_149 = 0 ;
V_109 -> V_150 [ 0 ] . V_151 = V_152 ;
V_109 -> V_150 [ 0 ] . V_153 = 0 ;
V_109 -> V_12 = V_152 ;
V_109 -> V_15 = NULL ;
F_79 ( F_18 ( V_109 -> V_35 ) ,
V_109 , F_80 ( V_3 -> V_52 -> V_155 ) ,
V_22 -> V_73 [ V_70 ] . V_10 ) ;
F_81 ( V_109 ) ;
}
if ( ! V_90 && ! V_110 ) {
if ( V_107 & V_114 )
F_74 ( V_156 , & V_22 -> V_39 ) ;
F_40 ( L_11 ,
V_34 -> V_124 , V_70 , ( unsigned long long ) V_22 -> V_10 ) ;
F_26 ( V_83 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
}
}
}
static struct V_157 *
F_82 ( int V_158 , struct V_9 * V_9 , struct V_68 * V_68 ,
T_1 V_10 , struct V_157 * V_159 )
{
struct V_160 * V_161 ;
struct V_68 * V_162 ;
int V_70 ;
int V_163 ;
struct V_164 V_165 ;
enum V_166 V_61 = 0 ;
if ( V_9 -> V_13 >= V_10 )
V_163 = ( signed ) ( V_9 -> V_13 - V_10 ) * 512 ;
else
V_163 = ( signed ) ( V_10 - V_9 -> V_13 ) * - 512 ;
if ( V_158 )
V_61 |= V_167 ;
F_83 ( & V_165 , V_61 , V_159 , NULL , NULL , NULL ) ;
F_84 (bvl, bio, i) {
int V_168 = V_161 -> V_151 ;
int V_169 ;
int V_170 = 0 ;
if ( V_163 < 0 ) {
V_170 = - V_163 ;
V_163 += V_170 ;
V_168 -= V_170 ;
}
if ( V_168 > 0 && V_163 + V_168 > V_152 )
V_169 = V_152 - V_163 ;
else
V_169 = V_168 ;
if ( V_169 > 0 ) {
V_170 += V_161 -> V_153 ;
V_162 = V_161 -> V_171 ;
if ( V_158 )
V_159 = F_85 ( V_68 , V_162 , V_163 ,
V_170 , V_169 , & V_165 ) ;
else
V_159 = F_85 ( V_162 , V_68 , V_170 ,
V_163 , V_169 , & V_165 ) ;
}
V_165 . V_172 = V_159 ;
if ( V_169 < V_168 )
break;
V_163 += V_168 ;
}
return V_159 ;
}
static void F_86 ( void * V_173 )
{
struct V_21 * V_22 = V_173 ;
struct V_9 * V_33 = NULL ;
int V_70 ;
F_40 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_70 = V_22 -> V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( F_28 ( V_174 , & V_73 -> V_61 ) ) {
struct V_9 * V_109 , * V_175 ;
F_23 ( ! V_73 -> V_80 ) ;
V_109 = V_73 -> V_80 ;
V_73 -> V_80 = NULL ;
while ( V_109 && V_109 -> V_13 <
V_73 -> V_10 + V_14 ) {
V_175 = F_2 ( V_109 , V_73 -> V_10 ) ;
if ( ! F_5 ( V_109 ) ) {
V_109 -> V_15 = V_33 ;
V_33 = V_109 ;
}
V_109 = V_175 ;
}
}
}
F_26 ( V_38 , & V_22 -> V_39 ) ;
F_16 ( V_33 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_34 ( V_22 ) ;
}
static void F_87 ( struct V_21 * V_22 )
{
struct V_157 * V_159 = NULL ;
struct V_164 V_165 ;
int V_70 ;
F_40 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_70 = V_22 -> V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( F_21 ( V_174 , & V_73 -> V_61 ) ) {
struct V_9 * V_109 ;
F_64 ( & V_22 -> V_176 ) ;
V_73 -> V_80 = V_109 = V_73 -> V_79 ;
V_73 -> V_79 = NULL ;
F_67 ( & V_22 -> V_176 ) ;
while ( V_109 && V_109 -> V_13 <
V_73 -> V_10 + V_14 ) {
V_159 = F_82 ( 0 , V_109 , V_73 -> V_68 ,
V_73 -> V_10 , V_159 ) ;
V_109 = F_2 ( V_109 , V_73 -> V_10 ) ;
}
}
}
F_8 ( & V_22 -> V_29 ) ;
F_83 ( & V_165 , V_177 , V_159 , F_86 , V_22 , NULL ) ;
F_88 ( & V_165 ) ;
}
static void F_89 ( struct V_21 * V_22 , int V_178 )
{
struct V_78 * V_179 ;
if ( V_178 < 0 )
return;
V_179 = & V_22 -> V_73 [ V_178 ] ;
F_74 ( V_180 , & V_179 -> V_61 ) ;
F_23 ( ! F_21 ( V_181 , & V_179 -> V_61 ) ) ;
F_26 ( V_181 , & V_179 -> V_61 ) ;
}
static void F_90 ( void * V_173 )
{
struct V_21 * V_22 = V_173 ;
F_40 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_89 ( V_22 , V_22 -> V_182 . V_178 ) ;
F_89 ( V_22 , V_22 -> V_182 . V_183 ) ;
F_26 ( V_40 , & V_22 -> V_39 ) ;
if ( V_22 -> V_36 == V_184 )
V_22 -> V_36 = V_185 ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_34 ( V_22 ) ;
}
static T_3 * F_91 ( struct V_21 * V_22 ,
struct V_186 * V_187 )
{
return V_187 -> V_188 + sizeof( struct V_68 * ) * ( V_22 -> V_25 + 2 ) ;
}
static struct V_157 *
F_92 ( struct V_21 * V_22 , struct V_186 * V_187 )
{
int V_25 = V_22 -> V_25 ;
struct V_68 * * V_189 = V_187 -> V_188 ;
int V_178 = V_22 -> V_182 . V_178 ;
struct V_78 * V_179 = & V_22 -> V_73 [ V_178 ] ;
struct V_68 * V_190 = V_179 -> V_68 ;
int V_29 = 0 ;
struct V_157 * V_159 ;
struct V_164 V_165 ;
int V_70 ;
F_40 ( L_13 ,
V_142 , ( unsigned long long ) V_22 -> V_10 , V_178 ) ;
F_23 ( ! F_21 ( V_181 , & V_179 -> V_61 ) ) ;
for ( V_70 = V_25 ; V_70 -- ; )
if ( V_70 != V_178 )
V_189 [ V_29 ++ ] = V_22 -> V_73 [ V_70 ] . V_68 ;
F_8 ( & V_22 -> V_29 ) ;
F_83 ( & V_165 , V_167 | V_191 , NULL ,
F_90 , V_22 , F_91 ( V_22 , V_187 ) ) ;
if ( F_93 ( V_29 == 1 ) )
V_159 = F_85 ( V_190 , V_189 [ 0 ] , 0 , 0 , V_152 , & V_165 ) ;
else
V_159 = F_94 ( V_190 , V_189 , 0 , V_29 , V_152 , & V_165 ) ;
return V_159 ;
}
static int F_95 ( struct V_68 * * V_192 , struct V_21 * V_22 )
{
int V_25 = V_22 -> V_25 ;
int V_30 = V_22 -> V_23 ? V_25 : ( V_25 - 2 ) ;
int V_193 = F_13 ( V_22 ) ;
int V_29 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_25 ; V_70 ++ )
V_192 [ V_70 ] = NULL ;
V_29 = 0 ;
V_70 = V_193 ;
do {
int V_31 = F_15 ( V_70 , V_22 , & V_29 , V_30 ) ;
V_192 [ V_31 ] = V_22 -> V_73 [ V_70 ] . V_68 ;
V_70 = F_14 ( V_70 , V_25 ) ;
} while ( V_70 != V_193 );
return V_30 ;
}
static struct V_157 *
F_96 ( struct V_21 * V_22 , struct V_186 * V_187 )
{
int V_25 = V_22 -> V_25 ;
struct V_68 * * V_194 = V_187 -> V_188 ;
int V_178 ;
int V_24 = V_22 -> V_24 ;
struct V_157 * V_159 ;
struct V_164 V_165 ;
struct V_78 * V_179 ;
struct V_68 * V_195 ;
int V_70 ;
int V_29 ;
if ( V_22 -> V_182 . V_178 < 0 )
V_178 = V_22 -> V_182 . V_183 ;
else if ( V_22 -> V_182 . V_183 < 0 )
V_178 = V_22 -> V_182 . V_178 ;
else
F_66 () ;
F_23 ( V_178 < 0 ) ;
F_40 ( L_13 ,
V_142 , ( unsigned long long ) V_22 -> V_10 , V_178 ) ;
V_179 = & V_22 -> V_73 [ V_178 ] ;
F_23 ( ! F_21 ( V_181 , & V_179 -> V_61 ) ) ;
V_195 = V_179 -> V_68 ;
F_8 ( & V_22 -> V_29 ) ;
if ( V_178 == V_24 ) {
V_29 = F_95 ( V_194 , V_22 ) ;
V_194 [ V_29 ] = NULL ;
F_23 ( V_194 [ V_29 + 1 ] != V_195 ) ;
F_83 ( & V_165 , V_167 , NULL ,
F_90 , V_22 ,
F_91 ( V_22 , V_187 ) ) ;
V_159 = F_97 ( V_194 , 0 , V_29 + 2 , V_152 , & V_165 ) ;
} else {
V_29 = 0 ;
for ( V_70 = V_25 ; V_70 -- ; ) {
if ( V_70 == V_178 || V_70 == V_24 )
continue;
V_194 [ V_29 ++ ] = V_22 -> V_73 [ V_70 ] . V_68 ;
}
F_83 ( & V_165 , V_167 | V_191 ,
NULL , F_90 , V_22 ,
F_91 ( V_22 , V_187 ) ) ;
V_159 = F_94 ( V_195 , V_194 , 0 , V_29 , V_152 , & V_165 ) ;
}
return V_159 ;
}
static struct V_157 *
F_98 ( struct V_21 * V_22 , struct V_186 * V_187 )
{
int V_70 , V_29 , V_25 = V_22 -> V_25 ;
int V_30 = V_22 -> V_23 ? V_25 : V_25 - 2 ;
int V_193 = F_13 ( V_22 ) ;
int V_196 = - 1 , V_197 = - 1 ;
int V_178 = V_22 -> V_182 . V_178 ;
int V_183 = V_22 -> V_182 . V_183 ;
struct V_78 * V_179 = & V_22 -> V_73 [ V_178 ] ;
struct V_78 * V_198 = & V_22 -> V_73 [ V_183 ] ;
struct V_157 * V_159 ;
struct V_68 * * V_194 = V_187 -> V_188 ;
struct V_164 V_165 ;
F_40 ( L_14 ,
V_142 , ( unsigned long long ) V_22 -> V_10 , V_178 , V_183 ) ;
F_23 ( V_178 < 0 || V_183 < 0 ) ;
F_23 ( ! F_21 ( V_181 , & V_179 -> V_61 ) ) ;
F_23 ( ! F_21 ( V_181 , & V_198 -> V_61 ) ) ;
for ( V_70 = 0 ; V_70 < V_25 ; V_70 ++ )
V_194 [ V_70 ] = NULL ;
V_29 = 0 ;
V_70 = V_193 ;
do {
int V_31 = F_15 ( V_70 , V_22 , & V_29 , V_30 ) ;
V_194 [ V_31 ] = V_22 -> V_73 [ V_70 ] . V_68 ;
if ( V_70 == V_178 )
V_196 = V_31 ;
if ( V_70 == V_183 )
V_197 = V_31 ;
V_70 = F_14 ( V_70 , V_25 ) ;
} while ( V_70 != V_193 );
F_23 ( V_196 == V_197 ) ;
if ( V_197 < V_196 )
F_99 ( V_196 , V_197 ) ;
F_40 ( L_15 ,
V_142 , ( unsigned long long ) V_22 -> V_10 , V_196 , V_197 ) ;
F_8 ( & V_22 -> V_29 ) ;
if ( V_197 == V_30 + 1 ) {
if ( V_196 == V_30 ) {
F_83 ( & V_165 , V_167 , NULL ,
F_90 , V_22 ,
F_91 ( V_22 , V_187 ) ) ;
return F_97 ( V_194 , 0 , V_30 + 2 ,
V_152 , & V_165 ) ;
} else {
struct V_68 * V_195 ;
int V_199 ;
int V_24 = V_22 -> V_24 ;
if ( V_178 == V_24 )
V_199 = V_183 ;
else
V_199 = V_178 ;
V_29 = 0 ;
for ( V_70 = V_25 ; V_70 -- ; ) {
if ( V_70 == V_199 || V_70 == V_24 )
continue;
V_194 [ V_29 ++ ] = V_22 -> V_73 [ V_70 ] . V_68 ;
}
V_195 = V_22 -> V_73 [ V_199 ] . V_68 ;
F_83 ( & V_165 ,
V_167 | V_191 ,
NULL , NULL , NULL ,
F_91 ( V_22 , V_187 ) ) ;
V_159 = F_94 ( V_195 , V_194 , 0 , V_29 , V_152 ,
& V_165 ) ;
V_29 = F_95 ( V_194 , V_22 ) ;
F_83 ( & V_165 , V_167 , V_159 ,
F_90 , V_22 ,
F_91 ( V_22 , V_187 ) ) ;
return F_97 ( V_194 , 0 , V_29 + 2 ,
V_152 , & V_165 ) ;
}
} else {
F_83 ( & V_165 , V_167 , NULL ,
F_90 , V_22 ,
F_91 ( V_22 , V_187 ) ) ;
if ( V_197 == V_30 ) {
return F_100 ( V_30 + 2 ,
V_152 , V_196 ,
V_194 , & V_165 ) ;
} else {
return F_101 ( V_30 + 2 ,
V_152 , V_196 , V_197 ,
V_194 , & V_165 ) ;
}
}
}
static void F_102 ( void * V_173 )
{
struct V_21 * V_22 = V_173 ;
F_40 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
}
static struct V_157 *
F_103 ( struct V_21 * V_22 , struct V_186 * V_187 ,
struct V_157 * V_159 )
{
int V_25 = V_22 -> V_25 ;
struct V_68 * * V_189 = V_187 -> V_188 ;
int V_29 = 0 , V_32 = V_22 -> V_32 , V_70 ;
struct V_164 V_165 ;
struct V_68 * V_190 = V_189 [ V_29 ++ ] = V_22 -> V_73 [ V_32 ] . V_68 ;
F_40 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( F_21 ( V_200 , & V_73 -> V_61 ) )
V_189 [ V_29 ++ ] = V_73 -> V_68 ;
}
F_83 ( & V_165 , V_167 | V_201 , V_159 ,
F_102 , V_22 , F_91 ( V_22 , V_187 ) ) ;
V_159 = F_94 ( V_190 , V_189 , 0 , V_29 , V_152 , & V_165 ) ;
return V_159 ;
}
static struct V_157 *
F_104 ( struct V_21 * V_22 , struct V_157 * V_159 )
{
int V_25 = V_22 -> V_25 ;
int V_70 ;
F_40 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
struct V_9 * V_202 ;
if ( F_28 ( V_200 , & V_73 -> V_61 ) ) {
struct V_9 * V_203 ;
F_64 ( & V_22 -> V_176 ) ;
V_202 = V_73 -> V_81 ;
V_73 -> V_81 = NULL ;
F_23 ( V_73 -> V_82 ) ;
V_203 = V_73 -> V_82 = V_202 ;
F_67 ( & V_22 -> V_176 ) ;
while ( V_203 && V_203 -> V_13 <
V_73 -> V_10 + V_14 ) {
if ( V_203 -> V_124 & V_204 )
F_74 ( V_112 , & V_73 -> V_61 ) ;
if ( V_203 -> V_124 & V_121 )
F_74 ( V_120 , & V_73 -> V_61 ) ;
if ( V_203 -> V_124 & V_116 )
F_74 ( V_115 , & V_73 -> V_61 ) ;
else
V_159 = F_82 ( 1 , V_203 , V_73 -> V_68 ,
V_73 -> V_10 , V_159 ) ;
V_203 = F_2 ( V_203 , V_73 -> V_10 ) ;
}
}
}
return V_159 ;
}
static void F_105 ( void * V_173 )
{
struct V_21 * V_22 = V_173 ;
int V_25 = V_22 -> V_25 ;
int V_32 = V_22 -> V_32 ;
int V_24 = V_22 -> V_24 ;
int V_70 ;
bool V_205 = false , V_206 = false , V_207 = false ;
F_40 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_70 = V_25 ; V_70 -- ; ) {
V_205 |= F_21 ( V_112 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
V_206 |= F_21 ( V_120 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
V_207 |= F_21 ( V_115 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
}
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( V_73 -> V_82 || V_70 == V_32 || V_70 == V_24 ) {
if ( ! V_207 )
F_74 ( V_180 , & V_73 -> V_61 ) ;
if ( V_205 )
F_74 ( V_112 , & V_73 -> V_61 ) ;
if ( V_206 )
F_74 ( V_120 , & V_73 -> V_61 ) ;
}
}
if ( V_22 -> V_37 == V_208 )
V_22 -> V_37 = V_209 ;
else if ( V_22 -> V_37 == V_210 )
V_22 -> V_37 = V_211 ;
else {
F_23 ( V_22 -> V_37 != V_212 ) ;
V_22 -> V_37 = V_213 ;
}
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_34 ( V_22 ) ;
}
static void
F_106 ( struct V_21 * V_22 , struct V_186 * V_187 ,
struct V_157 * V_159 )
{
int V_25 = V_22 -> V_25 ;
struct V_68 * * V_189 = V_187 -> V_188 ;
struct V_164 V_165 ;
int V_29 = 0 , V_32 = V_22 -> V_32 , V_70 ;
struct V_68 * V_190 ;
int V_214 = 0 ;
unsigned long V_61 ;
F_40 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_70 = 0 ; V_70 < V_22 -> V_25 ; V_70 ++ ) {
if ( V_32 == V_70 )
continue;
if ( ! F_21 ( V_115 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
break;
}
if ( V_70 >= V_22 -> V_25 ) {
F_8 ( & V_22 -> V_29 ) ;
F_74 ( V_115 , & V_22 -> V_73 [ V_32 ] . V_61 ) ;
F_105 ( V_22 ) ;
return;
}
if ( V_22 -> V_37 == V_210 ) {
V_214 = 1 ;
V_190 = V_189 [ V_29 ++ ] = V_22 -> V_73 [ V_32 ] . V_68 ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( V_73 -> V_82 )
V_189 [ V_29 ++ ] = V_73 -> V_68 ;
}
} else {
V_190 = V_22 -> V_73 [ V_32 ] . V_68 ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( V_70 != V_32 )
V_189 [ V_29 ++ ] = V_73 -> V_68 ;
}
}
V_61 = V_177 |
( V_214 ? V_201 : V_191 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_83 ( & V_165 , V_61 , V_159 , F_105 , V_22 ,
F_91 ( V_22 , V_187 ) ) ;
if ( F_93 ( V_29 == 1 ) )
V_159 = F_85 ( V_190 , V_189 [ 0 ] , 0 , 0 , V_152 , & V_165 ) ;
else
V_159 = F_94 ( V_190 , V_189 , 0 , V_29 , V_152 , & V_165 ) ;
}
static void
F_107 ( struct V_21 * V_22 , struct V_186 * V_187 ,
struct V_157 * V_159 )
{
struct V_164 V_165 ;
struct V_68 * * V_194 = V_187 -> V_188 ;
int V_29 , V_70 ;
F_40 ( L_12 , V_142 , ( unsigned long long ) V_22 -> V_10 ) ;
for ( V_70 = 0 ; V_70 < V_22 -> V_25 ; V_70 ++ ) {
if ( V_22 -> V_32 == V_70 || V_22 -> V_24 == V_70 )
continue;
if ( ! F_21 ( V_115 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
break;
}
if ( V_70 >= V_22 -> V_25 ) {
F_8 ( & V_22 -> V_29 ) ;
F_74 ( V_115 , & V_22 -> V_73 [ V_22 -> V_32 ] . V_61 ) ;
F_74 ( V_115 , & V_22 -> V_73 [ V_22 -> V_24 ] . V_61 ) ;
F_105 ( V_22 ) ;
return;
}
V_29 = F_95 ( V_194 , V_22 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_83 ( & V_165 , V_177 , V_159 , F_105 ,
V_22 , F_91 ( V_22 , V_187 ) ) ;
F_97 ( V_194 , 0 , V_29 + 2 , V_152 , & V_165 ) ;
}
static void F_108 ( void * V_173 )
{
struct V_21 * V_22 = V_173 ;
F_40 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
V_22 -> V_36 = V_215 ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_34 ( V_22 ) ;
}
static void F_109 ( struct V_21 * V_22 , struct V_186 * V_187 )
{
int V_25 = V_22 -> V_25 ;
int V_32 = V_22 -> V_32 ;
int V_24 = V_22 -> V_24 ;
struct V_68 * V_190 ;
struct V_68 * * V_189 = V_187 -> V_188 ;
struct V_157 * V_159 ;
struct V_164 V_165 ;
int V_29 ;
int V_70 ;
F_40 ( L_12 , V_142 ,
( unsigned long long ) V_22 -> V_10 ) ;
V_29 = 0 ;
V_190 = V_22 -> V_73 [ V_32 ] . V_68 ;
V_189 [ V_29 ++ ] = V_190 ;
for ( V_70 = V_25 ; V_70 -- ; ) {
if ( V_70 == V_32 || V_70 == V_24 )
continue;
V_189 [ V_29 ++ ] = V_22 -> V_73 [ V_70 ] . V_68 ;
}
F_83 ( & V_165 , 0 , NULL , NULL , NULL ,
F_91 ( V_22 , V_187 ) ) ;
V_159 = F_110 ( V_190 , V_189 , 0 , V_29 , V_152 ,
& V_22 -> V_182 . V_216 , & V_165 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_83 ( & V_165 , V_177 , V_159 , F_108 , V_22 , NULL ) ;
V_159 = F_88 ( & V_165 ) ;
}
static void F_111 ( struct V_21 * V_22 , struct V_186 * V_187 , int V_217 )
{
struct V_68 * * V_192 = V_187 -> V_188 ;
struct V_164 V_165 ;
int V_29 ;
F_40 ( L_16 , V_142 ,
( unsigned long long ) V_22 -> V_10 , V_217 ) ;
V_29 = F_95 ( V_192 , V_22 ) ;
if ( ! V_217 )
V_192 [ V_29 ] = NULL ;
F_8 ( & V_22 -> V_29 ) ;
F_83 ( & V_165 , V_177 , NULL , F_108 ,
V_22 , F_91 ( V_22 , V_187 ) ) ;
F_112 ( V_192 , 0 , V_29 + 2 , V_152 ,
& V_22 -> V_182 . V_216 , V_187 -> V_218 , & V_165 ) ;
}
static void F_113 ( struct V_21 * V_22 , unsigned long V_219 )
{
int V_220 = 0 , V_70 , V_25 = V_22 -> V_25 ;
struct V_157 * V_159 = NULL ;
struct V_2 * V_3 = V_22 -> V_60 ;
int V_221 = V_3 -> V_221 ;
struct V_186 * V_187 ;
unsigned long V_222 ;
V_222 = F_114 () ;
V_187 = F_115 ( V_3 -> V_187 , V_222 ) ;
if ( F_21 ( V_223 , & V_219 ) ) {
F_87 ( V_22 ) ;
V_220 ++ ;
}
if ( F_21 ( V_224 , & V_219 ) ) {
if ( V_221 < 6 )
V_159 = F_92 ( V_22 , V_187 ) ;
else {
if ( V_22 -> V_182 . V_183 < 0 || V_22 -> V_182 . V_178 < 0 )
V_159 = F_96 ( V_22 , V_187 ) ;
else
V_159 = F_98 ( V_22 , V_187 ) ;
}
if ( V_159 && ! F_21 ( V_225 , & V_219 ) )
F_116 ( V_159 ) ;
}
if ( F_21 ( V_226 , & V_219 ) )
V_159 = F_103 ( V_22 , V_187 , V_159 ) ;
if ( F_21 ( V_227 , & V_219 ) ) {
V_159 = F_104 ( V_22 , V_159 ) ;
V_220 ++ ;
}
if ( F_21 ( V_225 , & V_219 ) ) {
if ( V_221 < 6 )
F_106 ( V_22 , V_187 , V_159 ) ;
else
F_107 ( V_22 , V_187 , V_159 ) ;
}
if ( F_21 ( V_228 , & V_219 ) ) {
if ( V_22 -> V_36 == V_229 )
F_109 ( V_22 , V_187 ) ;
else if ( V_22 -> V_36 == V_230 )
F_111 ( V_22 , V_187 , 0 ) ;
else if ( V_22 -> V_36 == V_231 )
F_111 ( V_22 , V_187 , 1 ) ;
else
F_66 () ;
}
if ( V_220 )
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( F_28 ( V_232 , & V_73 -> V_61 ) )
F_31 ( & V_22 -> V_60 -> V_233 ) ;
}
F_117 () ;
}
static void F_118 ( void * V_234 , T_4 V_235 )
{
struct V_21 * V_22 = V_234 ;
unsigned long V_219 = V_22 -> V_182 . V_236 ;
F_119 ( V_237 , & V_22 -> V_39 ) ;
F_31 ( & V_22 -> V_182 . V_238 ) ;
F_113 ( V_22 , V_219 ) ;
F_34 ( V_22 ) ;
}
static void F_120 ( struct V_21 * V_22 , unsigned long V_219 )
{
F_121 ( V_22 -> V_182 . V_238 ,
! F_122 ( V_237 , & V_22 -> V_39 ) ) ;
V_22 -> V_182 . V_236 = V_219 ;
F_8 ( & V_22 -> V_29 ) ;
F_123 ( F_118 , V_22 ) ;
}
static int F_124 ( struct V_2 * V_3 )
{
struct V_21 * V_22 ;
V_22 = F_125 ( V_3 -> V_239 , V_74 ) ;
if ( ! V_22 )
return 0 ;
V_22 -> V_60 = V_3 ;
#ifdef F_126
F_127 ( & V_22 -> V_182 . V_238 ) ;
#endif
F_128 ( & V_22 -> V_176 ) ;
if ( F_49 ( V_22 ) ) {
F_47 ( V_22 ) ;
F_129 ( V_3 -> V_239 , V_22 ) ;
return 0 ;
}
F_12 ( & V_22 -> V_29 , 1 ) ;
F_8 ( & V_3 -> V_42 ) ;
F_130 ( & V_22 -> V_41 ) ;
F_34 ( V_22 ) ;
return 1 ;
}
static int F_131 ( struct V_2 * V_3 , int V_71 )
{
struct V_240 * V_241 ;
int V_242 = F_132 ( V_3 -> V_27 , V_3 -> V_77 ) ;
if ( V_3 -> V_52 -> V_155 )
sprintf ( V_3 -> V_243 [ 0 ] ,
L_17 , V_3 -> V_221 , F_133 ( V_3 -> V_52 ) ) ;
else
sprintf ( V_3 -> V_243 [ 0 ] ,
L_18 , V_3 -> V_221 , V_3 -> V_52 ) ;
sprintf ( V_3 -> V_243 [ 1 ] , L_19 , V_3 -> V_243 [ 0 ] ) ;
V_3 -> V_244 = 0 ;
V_241 = F_134 ( V_3 -> V_243 [ V_3 -> V_244 ] ,
sizeof( struct V_21 ) + ( V_242 - 1 ) * sizeof( struct V_78 ) ,
0 , 0 , NULL ) ;
if ( ! V_241 )
return 1 ;
V_3 -> V_239 = V_241 ;
V_3 -> V_72 = V_242 ;
while ( V_71 -- )
if ( ! F_124 ( V_3 ) )
return 1 ;
return 0 ;
}
static T_5 F_135 ( int V_71 )
{
T_5 V_168 ;
V_168 = sizeof( struct V_68 * ) * ( V_71 + 2 ) + sizeof( T_3 ) * ( V_71 + 2 ) ;
return V_168 ;
}
static int F_136 ( struct V_2 * V_3 , int V_245 )
{
struct V_21 * V_246 , * V_247 ;
F_137 ( V_248 ) ;
struct V_249 * V_250 ;
unsigned long V_222 ;
int V_251 ;
struct V_240 * V_241 ;
int V_70 ;
if ( V_245 <= V_3 -> V_72 )
return 0 ;
V_251 = F_138 ( V_3 -> V_52 ) ;
if ( V_251 )
return V_251 ;
V_241 = F_134 ( V_3 -> V_243 [ 1 - V_3 -> V_244 ] ,
sizeof( struct V_21 ) + ( V_245 - 1 ) * sizeof( struct V_78 ) ,
0 , 0 , NULL ) ;
if ( ! V_241 )
return - V_252 ;
for ( V_70 = V_3 -> V_101 ; V_70 ; V_70 -- ) {
V_247 = F_125 ( V_241 , V_74 ) ;
if ( ! V_247 )
break;
V_247 -> V_60 = V_3 ;
#ifdef F_126
F_127 ( & V_247 -> V_182 . V_238 ) ;
#endif
F_128 ( & V_247 -> V_176 ) ;
F_139 ( & V_247 -> V_41 , & V_248 ) ;
}
if ( V_70 ) {
while ( ! F_24 ( & V_248 ) ) {
V_247 = F_45 ( V_248 . V_67 , struct V_21 , V_41 ) ;
F_140 ( & V_247 -> V_41 ) ;
F_129 ( V_241 , V_247 ) ;
}
F_141 ( V_241 ) ;
return - V_252 ;
}
F_142 (nsh, &newstripes, lru) {
F_64 ( & V_3 -> V_62 ) ;
F_65 ( V_3 -> V_58 ,
! F_24 ( & V_3 -> V_57 ) ,
V_3 -> V_62 ) ;
V_246 = F_44 ( V_3 ) ;
F_67 ( & V_3 -> V_62 ) ;
F_12 ( & V_247 -> V_29 , 1 ) ;
for( V_70 = 0 ; V_70 < V_3 -> V_72 ; V_70 ++ )
V_247 -> V_73 [ V_70 ] . V_68 = V_246 -> V_73 [ V_70 ] . V_68 ;
for( ; V_70 < V_245 ; V_70 ++ )
V_247 -> V_73 [ V_70 ] . V_68 = NULL ;
F_129 ( V_3 -> V_239 , V_246 ) ;
}
F_141 ( V_3 -> V_239 ) ;
V_250 = F_143 ( V_245 * sizeof( struct V_249 ) , V_253 ) ;
if ( V_250 ) {
for ( V_70 = 0 ; V_70 < V_3 -> V_27 ; V_70 ++ )
V_250 [ V_70 ] = V_3 -> V_25 [ V_70 ] ;
F_144 ( V_3 -> V_25 ) ;
V_3 -> V_25 = V_250 ;
} else
V_251 = - V_252 ;
F_145 () ;
V_3 -> F_135 = F_135 ( V_245 ) ;
F_146 (cpu) {
struct V_186 * V_187 ;
void * V_188 ;
V_187 = F_115 ( V_3 -> V_187 , V_222 ) ;
V_188 = F_147 ( V_3 -> F_135 , V_253 ) ;
if ( V_188 ) {
F_144 ( V_187 -> V_188 ) ;
V_187 -> V_188 = V_188 ;
} else {
V_251 = - V_252 ;
break;
}
}
F_148 () ;
while( ! F_24 ( & V_248 ) ) {
V_247 = F_45 ( V_248 . V_67 , struct V_21 , V_41 ) ;
F_46 ( & V_247 -> V_41 ) ;
for ( V_70 = V_3 -> V_27 ; V_70 < V_245 ; V_70 ++ )
if ( V_247 -> V_73 [ V_70 ] . V_68 == NULL ) {
struct V_68 * V_69 = F_50 ( V_253 ) ;
V_247 -> V_73 [ V_70 ] . V_68 = V_69 ;
if ( ! V_69 )
V_251 = - V_252 ;
}
F_34 ( V_247 ) ;
}
V_3 -> V_239 = V_241 ;
V_3 -> V_244 = 1 - V_3 -> V_244 ;
V_3 -> V_72 = V_245 ;
return V_251 ;
}
static int F_149 ( struct V_2 * V_3 )
{
struct V_21 * V_22 ;
F_64 ( & V_3 -> V_62 ) ;
V_22 = F_44 ( V_3 ) ;
F_67 ( & V_3 -> V_62 ) ;
if ( ! V_22 )
return 0 ;
F_23 ( F_4 ( & V_22 -> V_29 ) ) ;
F_47 ( V_22 ) ;
F_129 ( V_3 -> V_239 , V_22 ) ;
F_30 ( & V_3 -> V_42 ) ;
return 1 ;
}
static void F_150 ( struct V_2 * V_3 )
{
while ( F_149 ( V_3 ) )
;
if ( V_3 -> V_239 )
F_141 ( V_3 -> V_239 ) ;
V_3 -> V_239 = NULL ;
}
static void V_127 ( struct V_9 * V_34 , int error )
{
struct V_21 * V_22 = V_34 -> V_254 ;
struct V_2 * V_3 = V_22 -> V_60 ;
int V_25 = V_22 -> V_25 , V_70 ;
int V_255 = F_21 ( V_148 , & V_34 -> V_147 ) ;
char V_256 [ V_257 ] ;
struct V_89 * V_90 = NULL ;
T_1 V_106 ;
for ( V_70 = 0 ; V_70 < V_25 ; V_70 ++ )
if ( V_34 == & V_22 -> V_73 [ V_70 ] . V_122 )
break;
F_40 ( L_20 ,
( unsigned long long ) V_22 -> V_10 , V_70 , F_4 ( & V_22 -> V_29 ) ,
V_255 ) ;
if ( V_70 == V_25 ) {
F_66 () ;
return;
}
if ( F_21 ( V_128 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
V_90 = V_3 -> V_25 [ V_70 ] . V_92 ;
if ( ! V_90 )
V_90 = V_3 -> V_25 [ V_70 ] . V_90 ;
if ( F_68 ( V_3 , V_22 ) )
V_106 = V_22 -> V_10 + V_90 -> V_143 ;
else
V_106 = V_22 -> V_10 + V_90 -> V_144 ;
if ( V_255 ) {
F_74 ( V_180 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
if ( F_21 ( V_258 , & V_22 -> V_73 [ V_70 ] . V_61 ) ) {
F_151 (
V_259
L_21
L_22 ,
F_133 ( V_3 -> V_52 ) , V_14 ,
( unsigned long long ) V_106 ,
F_152 ( V_90 -> V_140 , V_256 ) ) ;
F_153 ( V_14 , & V_90 -> V_260 ) ;
F_26 ( V_258 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_26 ( V_261 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
} else if ( F_21 ( V_145 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
F_26 ( V_145 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
if ( F_4 ( & V_90 -> V_262 ) )
F_12 ( & V_90 -> V_262 , 0 ) ;
} else {
const char * V_263 = F_152 ( V_90 -> V_140 , V_256 ) ;
int V_264 = 0 ;
int V_265 = 0 ;
F_26 ( V_180 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_8 ( & V_90 -> V_262 ) ;
if ( F_21 ( V_128 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
F_151 (
V_266
L_23
L_24 ,
F_133 ( V_3 -> V_52 ) ,
( unsigned long long ) V_106 ,
V_263 ) ;
else if ( V_3 -> V_52 -> V_87 >= V_3 -> V_96 ) {
V_265 = 1 ;
F_151 (
V_266
L_25
L_24 ,
F_133 ( V_3 -> V_52 ) ,
( unsigned long long ) V_106 ,
V_263 ) ;
} else if ( F_21 ( V_261 , & V_22 -> V_73 [ V_70 ] . V_61 ) ) {
V_265 = 1 ;
F_151 (
V_266
L_26
L_24 ,
F_133 ( V_3 -> V_52 ) ,
( unsigned long long ) V_106 ,
V_263 ) ;
} else if ( F_4 ( & V_90 -> V_262 )
> V_3 -> V_101 )
F_53 ( V_266
L_27 ,
F_133 ( V_3 -> V_52 ) , V_263 ) ;
else
V_264 = 1 ;
if ( V_264 )
if ( F_21 ( V_145 , & V_22 -> V_73 [ V_70 ] . V_61 ) ) {
F_74 ( V_258 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_26 ( V_145 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
} else
F_74 ( V_145 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
else {
F_26 ( V_258 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_26 ( V_261 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
if ( ! ( V_265
&& F_21 ( V_93 , & V_90 -> V_61 )
&& F_154 (
V_90 , V_22 -> V_10 , V_14 , 0 ) ) )
F_155 ( V_3 -> V_52 , V_90 ) ;
}
}
F_77 ( V_90 , V_3 -> V_52 ) ;
F_26 ( V_83 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_34 ( V_22 ) ;
}
static void V_126 ( struct V_9 * V_34 , int error )
{
struct V_21 * V_22 = V_34 -> V_254 ;
struct V_2 * V_3 = V_22 -> V_60 ;
int V_25 = V_22 -> V_25 , V_70 ;
struct V_89 * V_267 ( V_90 ) ;
int V_255 = F_21 ( V_148 , & V_34 -> V_147 ) ;
T_1 V_131 ;
int V_132 ;
int V_92 = 0 ;
for ( V_70 = 0 ; V_70 < V_25 ; V_70 ++ ) {
if ( V_34 == & V_22 -> V_73 [ V_70 ] . V_122 ) {
V_90 = V_3 -> V_25 [ V_70 ] . V_90 ;
break;
}
if ( V_34 == & V_22 -> V_73 [ V_70 ] . V_123 ) {
V_90 = V_3 -> V_25 [ V_70 ] . V_92 ;
if ( V_90 )
V_92 = 1 ;
else
V_90 = V_3 -> V_25 [ V_70 ] . V_90 ;
break;
}
}
F_40 ( L_28 ,
( unsigned long long ) V_22 -> V_10 , V_70 , F_4 ( & V_22 -> V_29 ) ,
V_255 ) ;
if ( V_70 == V_25 ) {
F_66 () ;
return;
}
if ( V_92 ) {
if ( ! V_255 )
F_155 ( V_3 -> V_52 , V_90 ) ;
else if ( F_73 ( V_90 , V_22 -> V_10 ,
V_14 ,
& V_131 , & V_132 ) )
F_74 ( V_268 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
} else {
if ( ! V_255 ) {
F_74 ( V_130 , & V_90 -> V_61 ) ;
F_74 ( V_269 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
if ( ! F_156 ( V_270 , & V_90 -> V_61 ) )
F_74 ( V_271 ,
& V_90 -> V_52 -> V_272 ) ;
} else if ( F_73 ( V_90 , V_22 -> V_10 ,
V_14 ,
& V_131 , & V_132 ) )
F_74 ( V_273 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
}
F_77 ( V_90 , V_3 -> V_52 ) ;
if ( ! F_28 ( V_154 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
F_26 ( V_83 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_34 ( V_22 ) ;
}
static void F_55 ( struct V_21 * V_22 , int V_70 , int V_75 )
{
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
F_157 ( & V_73 -> V_122 ) ;
V_73 -> V_122 . V_150 = & V_73 -> V_274 ;
V_73 -> V_122 . V_275 ++ ;
V_73 -> V_122 . V_276 ++ ;
V_73 -> V_122 . V_254 = V_22 ;
V_73 -> V_274 . V_171 = V_73 -> V_68 ;
F_157 ( & V_73 -> V_123 ) ;
V_73 -> V_123 . V_150 = & V_73 -> V_277 ;
V_73 -> V_123 . V_275 ++ ;
V_73 -> V_123 . V_276 ++ ;
V_73 -> V_123 . V_254 = V_22 ;
V_73 -> V_277 . V_171 = V_73 -> V_68 ;
V_73 -> V_61 = 0 ;
V_73 -> V_10 = F_158 ( V_22 , V_70 , V_75 ) ;
}
static void error ( struct V_52 * V_52 , struct V_89 * V_90 )
{
char V_256 [ V_257 ] ;
struct V_2 * V_3 = V_52 -> V_278 ;
unsigned long V_61 ;
F_40 ( L_29 ) ;
F_159 ( & V_3 -> V_62 , V_61 ) ;
F_26 ( V_93 , & V_90 -> V_61 ) ;
V_52 -> V_87 = F_58 ( V_3 ) ;
F_160 ( & V_3 -> V_62 , V_61 ) ;
F_74 ( V_279 , & V_52 -> V_272 ) ;
F_74 ( V_280 , & V_90 -> V_61 ) ;
F_74 ( V_91 , & V_90 -> V_61 ) ;
F_74 ( V_281 , & V_52 -> V_61 ) ;
F_53 ( V_282
L_30
L_31 ,
F_133 ( V_52 ) ,
F_152 ( V_90 -> V_140 , V_256 ) ,
F_133 ( V_52 ) ,
V_3 -> V_27 - V_52 -> V_87 ) ;
}
static T_1 F_161 ( struct V_2 * V_3 , T_1 V_283 ,
int V_75 , int * V_284 ,
struct V_21 * V_22 )
{
T_1 V_285 , V_286 ;
T_1 V_287 ;
unsigned int V_288 ;
int V_32 , V_24 ;
int V_23 = 0 ;
T_1 V_289 ;
int V_290 = V_75 ? V_3 -> V_291
: V_3 -> V_290 ;
int V_292 = V_75 ? V_3 -> V_293
: V_3 -> V_294 ;
int V_27 = V_75 ? V_3 -> V_77
: V_3 -> V_27 ;
int V_295 = V_27 - V_3 -> V_96 ;
V_288 = F_162 ( V_283 , V_292 ) ;
V_287 = V_283 ;
V_285 = V_287 ;
* V_284 = F_162 ( V_285 , V_295 ) ;
V_286 = V_285 ;
V_32 = V_24 = - 1 ;
switch( V_3 -> V_221 ) {
case 4 :
V_32 = V_295 ;
break;
case 5 :
switch ( V_290 ) {
case V_296 :
V_32 = V_295 - F_162 ( V_286 , V_27 ) ;
if ( * V_284 >= V_32 )
( * V_284 ) ++ ;
break;
case V_297 :
V_32 = F_162 ( V_286 , V_27 ) ;
if ( * V_284 >= V_32 )
( * V_284 ) ++ ;
break;
case V_298 :
V_32 = V_295 - F_162 ( V_286 , V_27 ) ;
* V_284 = ( V_32 + 1 + * V_284 ) % V_27 ;
break;
case V_299 :
V_32 = F_162 ( V_286 , V_27 ) ;
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
F_66 () ;
}
break;
case 6 :
switch ( V_290 ) {
case V_296 :
V_32 = V_27 - 1 - F_162 ( V_286 , V_27 ) ;
V_24 = V_32 + 1 ;
if ( V_32 == V_27 - 1 ) {
( * V_284 ) ++ ;
V_24 = 0 ;
} else if ( * V_284 >= V_32 )
( * V_284 ) += 2 ;
break;
case V_297 :
V_32 = F_162 ( V_286 , V_27 ) ;
V_24 = V_32 + 1 ;
if ( V_32 == V_27 - 1 ) {
( * V_284 ) ++ ;
V_24 = 0 ;
} else if ( * V_284 >= V_32 )
( * V_284 ) += 2 ;
break;
case V_298 :
V_32 = V_27 - 1 - F_162 ( V_286 , V_27 ) ;
V_24 = ( V_32 + 1 ) % V_27 ;
* V_284 = ( V_32 + 2 + * V_284 ) % V_27 ;
break;
case V_299 :
V_32 = F_162 ( V_286 , V_27 ) ;
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
V_32 = F_162 ( V_286 , V_27 ) ;
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
V_32 = V_27 - 1 - F_162 ( V_286 , V_27 ) ;
V_24 = V_32 + 1 ;
if ( V_32 == V_27 - 1 ) {
( * V_284 ) ++ ;
V_24 = 0 ;
} else if ( * V_284 >= V_32 )
( * V_284 ) += 2 ;
V_23 = 1 ;
break;
case V_304 :
V_32 = V_27 - 1 - F_162 ( V_286 , V_27 ) ;
V_24 = ( V_32 + V_27 - 1 ) % V_27 ;
* V_284 = ( V_32 + 1 + * V_284 ) % V_27 ;
V_23 = 1 ;
break;
case V_305 :
V_32 = V_295 - F_162 ( V_286 , V_27 - 1 ) ;
if ( * V_284 >= V_32 )
( * V_284 ) ++ ;
V_24 = V_27 - 1 ;
break;
case V_306 :
V_32 = F_162 ( V_286 , V_27 - 1 ) ;
if ( * V_284 >= V_32 )
( * V_284 ) ++ ;
V_24 = V_27 - 1 ;
break;
case V_307 :
V_32 = V_295 - F_162 ( V_286 , V_27 - 1 ) ;
* V_284 = ( V_32 + 1 + * V_284 ) % ( V_27 - 1 ) ;
V_24 = V_27 - 1 ;
break;
case V_308 :
V_32 = F_162 ( V_286 , V_27 - 1 ) ;
* V_284 = ( V_32 + 1 + * V_284 ) % ( V_27 - 1 ) ;
V_24 = V_27 - 1 ;
break;
case V_309 :
V_32 = 0 ;
( * V_284 ) ++ ;
V_24 = V_27 - 1 ;
break;
default:
F_66 () ;
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
static T_1 F_158 ( struct V_21 * V_22 , int V_70 , int V_75 )
{
struct V_2 * V_3 = V_22 -> V_60 ;
int V_27 = V_22 -> V_25 ;
int V_295 = V_27 - V_3 -> V_96 ;
T_1 V_289 = V_22 -> V_10 , V_310 ;
int V_292 = V_75 ? V_3 -> V_293
: V_3 -> V_294 ;
int V_290 = V_75 ? V_3 -> V_291
: V_3 -> V_290 ;
T_1 V_285 ;
int V_288 ;
T_1 V_287 ;
int V_311 , V_284 = V_70 ;
T_1 V_283 ;
struct V_21 V_312 ;
V_288 = F_162 ( V_289 , V_292 ) ;
V_285 = V_289 ;
if ( V_70 == V_22 -> V_32 )
return 0 ;
switch( V_3 -> V_221 ) {
case 4 : break;
case 5 :
switch ( V_290 ) {
case V_296 :
case V_297 :
if ( V_70 > V_22 -> V_32 )
V_70 -- ;
break;
case V_298 :
case V_299 :
if ( V_70 < V_22 -> V_32 )
V_70 += V_27 ;
V_70 -= ( V_22 -> V_32 + 1 ) ;
break;
case V_300 :
V_70 -= 1 ;
break;
case V_301 :
break;
default:
F_66 () ;
}
break;
case 6 :
if ( V_70 == V_22 -> V_24 )
return 0 ;
switch ( V_290 ) {
case V_296 :
case V_297 :
case V_302 :
case V_303 :
if ( V_22 -> V_32 == V_27 - 1 )
V_70 -- ;
else if ( V_70 > V_22 -> V_32 )
V_70 -= 2 ;
break;
case V_298 :
case V_299 :
if ( V_22 -> V_32 == V_27 - 1 )
V_70 -- ;
else {
if ( V_70 < V_22 -> V_32 )
V_70 += V_27 ;
V_70 -= ( V_22 -> V_32 + 2 ) ;
}
break;
case V_300 :
V_70 -= 2 ;
break;
case V_301 :
break;
case V_304 :
if ( V_22 -> V_32 == 0 )
V_70 -- ;
else {
if ( V_70 < V_22 -> V_32 )
V_70 += V_27 ;
V_70 -= ( V_22 -> V_32 + 1 ) ;
}
break;
case V_305 :
case V_306 :
if ( V_70 > V_22 -> V_32 )
V_70 -- ;
break;
case V_307 :
case V_308 :
if ( V_70 < V_22 -> V_32 )
V_70 += V_295 + 1 ;
V_70 -= ( V_22 -> V_32 + 1 ) ;
break;
case V_309 :
V_70 -= 1 ;
break;
default:
F_66 () ;
}
break;
}
V_287 = V_285 * V_295 + V_70 ;
V_283 = V_287 * V_292 + V_288 ;
V_310 = F_161 ( V_3 , V_283 ,
V_75 , & V_311 , & V_312 ) ;
if ( V_310 != V_22 -> V_10 || V_311 != V_284 || V_312 . V_32 != V_22 -> V_32
|| V_312 . V_24 != V_22 -> V_24 ) {
F_53 ( V_84 L_32 ,
F_133 ( V_3 -> V_52 ) ) ;
return 0 ;
}
return V_283 ;
}
static void
F_163 ( struct V_21 * V_22 , struct V_105 * V_106 ,
int V_313 , int V_314 )
{
int V_70 , V_32 = V_22 -> V_32 , V_25 = V_22 -> V_25 ;
struct V_2 * V_3 = V_22 -> V_60 ;
int V_221 = V_3 -> V_221 ;
if ( V_313 ) {
if ( ! V_314 ) {
V_22 -> V_37 = V_208 ;
F_74 ( V_227 , & V_106 -> V_219 ) ;
} else
V_22 -> V_37 = V_212 ;
F_74 ( V_225 , & V_106 -> V_219 ) ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( V_73 -> V_81 ) {
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_74 ( V_200 , & V_73 -> V_61 ) ;
if ( ! V_314 )
F_26 ( V_180 , & V_73 -> V_61 ) ;
V_106 -> V_315 ++ ;
}
}
if ( V_106 -> V_315 + V_3 -> V_96 == V_25 )
if ( ! F_156 ( V_316 , & V_22 -> V_39 ) )
F_8 ( & V_3 -> V_317 ) ;
} else {
F_23 ( V_221 == 6 ) ;
F_23 ( ! ( F_21 ( V_180 , & V_22 -> V_73 [ V_32 ] . V_61 ) ||
F_21 ( V_181 , & V_22 -> V_73 [ V_32 ] . V_61 ) ) ) ;
V_22 -> V_37 = V_210 ;
F_74 ( V_226 , & V_106 -> V_219 ) ;
F_74 ( V_227 , & V_106 -> V_219 ) ;
F_74 ( V_225 , & V_106 -> V_219 ) ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( V_70 == V_32 )
continue;
if ( V_73 -> V_81 &&
( F_21 ( V_180 , & V_73 -> V_61 ) ||
F_21 ( V_181 , & V_73 -> V_61 ) ) ) {
F_74 ( V_200 , & V_73 -> V_61 ) ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_26 ( V_180 , & V_73 -> V_61 ) ;
V_106 -> V_315 ++ ;
}
}
}
F_74 ( V_83 , & V_22 -> V_73 [ V_32 ] . V_61 ) ;
F_26 ( V_180 , & V_22 -> V_73 [ V_32 ] . V_61 ) ;
V_106 -> V_315 ++ ;
if ( V_221 == 6 ) {
int V_24 = V_22 -> V_24 ;
struct V_78 * V_73 = & V_22 -> V_73 [ V_24 ] ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_26 ( V_180 , & V_73 -> V_61 ) ;
V_106 -> V_315 ++ ;
}
F_40 ( L_33 ,
V_142 , ( unsigned long long ) V_22 -> V_10 ,
V_106 -> V_315 , V_106 -> V_219 ) ;
}
static int F_164 ( struct V_21 * V_22 , struct V_9 * V_34 , int V_284 , int V_318 )
{
struct V_9 * * V_319 ;
struct V_2 * V_3 = V_22 -> V_60 ;
int V_320 = 0 ;
F_40 ( L_34 ,
( unsigned long long ) V_34 -> V_13 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_64 ( & V_22 -> V_176 ) ;
if ( V_318 ) {
V_319 = & V_22 -> V_73 [ V_284 ] . V_81 ;
if ( * V_319 == NULL )
V_320 = 1 ;
} else
V_319 = & V_22 -> V_73 [ V_284 ] . V_79 ;
while ( * V_319 && ( * V_319 ) -> V_13 < V_34 -> V_13 ) {
if ( ( * V_319 ) -> V_13 + ( ( * V_319 ) -> V_12 >> 9 ) > V_34 -> V_13 )
goto V_321;
V_319 = & ( * V_319 ) -> V_15 ;
}
if ( * V_319 && ( * V_319 ) -> V_13 < V_34 -> V_13 + ( ( V_34 -> V_12 ) >> 9 ) )
goto V_321;
F_23 ( * V_319 && V_34 -> V_15 && ( * V_319 ) != V_34 -> V_15 ) ;
if ( * V_319 )
V_34 -> V_15 = * V_319 ;
* V_319 = V_34 ;
F_7 ( V_34 ) ;
if ( V_318 ) {
T_1 V_10 = V_22 -> V_73 [ V_284 ] . V_10 ;
for ( V_34 = V_22 -> V_73 [ V_284 ] . V_81 ;
V_10 < V_22 -> V_73 [ V_284 ] . V_10 + V_14 &&
V_34 && V_34 -> V_13 <= V_10 ;
V_34 = F_2 ( V_34 , V_22 -> V_73 [ V_284 ] . V_10 ) ) {
if ( V_34 -> V_13 + ( V_34 -> V_12 >> 9 ) >= V_10 )
V_10 = V_34 -> V_13 + ( V_34 -> V_12 >> 9 ) ;
}
if ( V_10 >= V_22 -> V_73 [ V_284 ] . V_10 + V_14 )
F_74 ( V_322 , & V_22 -> V_73 [ V_284 ] . V_61 ) ;
}
F_40 ( L_35 ,
( unsigned long long ) ( * V_319 ) -> V_13 ,
( unsigned long long ) V_22 -> V_10 , V_284 ) ;
F_67 ( & V_22 -> V_176 ) ;
if ( V_3 -> V_52 -> V_323 && V_320 ) {
F_165 ( V_3 -> V_52 -> V_323 , V_22 -> V_10 ,
V_14 , 0 ) ;
V_22 -> V_48 = V_3 -> V_324 + 1 ;
F_74 ( V_47 , & V_22 -> V_39 ) ;
}
return 1 ;
V_321:
F_74 ( V_232 , & V_22 -> V_73 [ V_284 ] . V_61 ) ;
F_67 ( & V_22 -> V_176 ) ;
return 0 ;
}
static void F_52 ( T_1 V_285 , struct V_2 * V_3 , int V_75 ,
struct V_21 * V_22 )
{
int V_292 =
V_75 ? V_3 -> V_293 : V_3 -> V_294 ;
int V_284 ;
int V_288 = F_162 ( V_285 , V_292 ) ;
int V_25 = V_75 ? V_3 -> V_77 : V_3 -> V_27 ;
F_161 ( V_3 ,
V_285 * ( V_25 - V_3 -> V_96 )
* V_292 + V_288 ,
V_75 ,
& V_284 , V_22 ) ;
}
static void
F_166 ( struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_105 * V_106 , int V_25 ,
struct V_9 * * V_33 )
{
int V_70 ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_9 * V_34 ;
int V_325 = 0 ;
if ( F_21 ( V_258 , & V_22 -> V_73 [ V_70 ] . V_61 ) ) {
struct V_89 * V_90 ;
F_59 () ;
V_90 = F_60 ( V_3 -> V_25 [ V_70 ] . V_90 ) ;
if ( V_90 && F_21 ( V_93 , & V_90 -> V_61 ) )
F_8 ( & V_90 -> V_129 ) ;
else
V_90 = NULL ;
F_61 () ;
if ( V_90 ) {
if ( ! F_154 (
V_90 ,
V_22 -> V_10 ,
V_14 , 0 ) )
F_155 ( V_3 -> V_52 , V_90 ) ;
F_77 ( V_90 , V_3 -> V_52 ) ;
}
}
F_64 ( & V_22 -> V_176 ) ;
V_34 = V_22 -> V_73 [ V_70 ] . V_81 ;
V_22 -> V_73 [ V_70 ] . V_81 = NULL ;
F_67 ( & V_22 -> V_176 ) ;
if ( V_34 )
V_325 = 1 ;
if ( F_28 ( V_232 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
F_31 ( & V_3 -> V_233 ) ;
while ( V_34 && V_34 -> V_13 <
V_22 -> V_73 [ V_70 ] . V_10 + V_14 ) {
struct V_9 * V_326 = F_2 ( V_34 , V_22 -> V_73 [ V_70 ] . V_10 ) ;
F_26 ( V_148 , & V_34 -> V_147 ) ;
if ( ! F_5 ( V_34 ) ) {
F_167 ( V_3 -> V_52 ) ;
V_34 -> V_15 = * V_33 ;
* V_33 = V_34 ;
}
V_34 = V_326 ;
}
if ( V_325 )
F_168 ( V_3 -> V_52 -> V_323 , V_22 -> V_10 ,
V_14 , 0 , 0 ) ;
V_325 = 0 ;
V_34 = V_22 -> V_73 [ V_70 ] . V_82 ;
V_22 -> V_73 [ V_70 ] . V_82 = NULL ;
if ( V_34 ) V_325 = 1 ;
while ( V_34 && V_34 -> V_13 <
V_22 -> V_73 [ V_70 ] . V_10 + V_14 ) {
struct V_9 * V_327 = F_2 ( V_34 , V_22 -> V_73 [ V_70 ] . V_10 ) ;
F_26 ( V_148 , & V_34 -> V_147 ) ;
if ( ! F_5 ( V_34 ) ) {
F_167 ( V_3 -> V_52 ) ;
V_34 -> V_15 = * V_33 ;
* V_33 = V_34 ;
}
V_34 = V_327 ;
}
if ( ! F_21 ( V_174 , & V_22 -> V_73 [ V_70 ] . V_61 ) &&
( ! F_21 ( V_328 , & V_22 -> V_73 [ V_70 ] . V_61 ) ||
F_21 ( V_258 , & V_22 -> V_73 [ V_70 ] . V_61 ) ) ) {
F_64 ( & V_22 -> V_176 ) ;
V_34 = V_22 -> V_73 [ V_70 ] . V_79 ;
V_22 -> V_73 [ V_70 ] . V_79 = NULL ;
F_67 ( & V_22 -> V_176 ) ;
if ( F_28 ( V_232 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
F_31 ( & V_3 -> V_233 ) ;
while ( V_34 && V_34 -> V_13 <
V_22 -> V_73 [ V_70 ] . V_10 + V_14 ) {
struct V_9 * V_326 =
F_2 ( V_34 , V_22 -> V_73 [ V_70 ] . V_10 ) ;
F_26 ( V_148 , & V_34 -> V_147 ) ;
if ( ! F_5 ( V_34 ) ) {
V_34 -> V_15 = * V_33 ;
* V_33 = V_34 ;
}
V_34 = V_326 ;
}
}
if ( V_325 )
F_168 ( V_3 -> V_52 -> V_323 , V_22 -> V_10 ,
V_14 , 0 , 0 ) ;
F_26 ( V_83 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
}
if ( F_28 ( V_316 , & V_22 -> V_39 ) )
if ( F_33 ( & V_3 -> V_317 ) )
F_27 ( V_3 -> V_52 -> V_53 ) ;
}
static void
F_169 ( struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_105 * V_106 )
{
int abort = 0 ;
int V_70 ;
F_26 ( V_329 , & V_22 -> V_39 ) ;
V_106 -> V_136 = 0 ;
V_106 -> V_139 = 0 ;
if ( F_21 ( V_330 , & V_3 -> V_52 -> V_272 ) ) {
for ( V_70 = 0 ; V_70 < V_3 -> V_27 ; V_70 ++ ) {
struct V_89 * V_90 = V_3 -> V_25 [ V_70 ] . V_90 ;
if ( V_90
&& ! F_21 ( V_91 , & V_90 -> V_61 )
&& ! F_21 ( V_93 , & V_90 -> V_61 )
&& ! F_154 ( V_90 , V_22 -> V_10 ,
V_14 , 0 ) )
abort = 1 ;
V_90 = V_3 -> V_25 [ V_70 ] . V_92 ;
if ( V_90
&& ! F_21 ( V_91 , & V_90 -> V_61 )
&& ! F_21 ( V_93 , & V_90 -> V_61 )
&& ! F_154 ( V_90 , V_22 -> V_10 ,
V_14 , 0 ) )
abort = 1 ;
}
if ( abort )
V_3 -> V_331 =
V_3 -> V_52 -> V_331 ;
}
F_170 ( V_3 -> V_52 , V_14 , ! abort ) ;
}
static int F_171 ( struct V_21 * V_22 , int V_332 )
{
struct V_89 * V_90 ;
int V_333 = 0 ;
V_90 = V_22 -> V_60 -> V_25 [ V_332 ] . V_92 ;
if ( V_90
&& ! F_21 ( V_91 , & V_90 -> V_61 )
&& ! F_21 ( V_93 , & V_90 -> V_61 )
&& ( V_90 -> V_334 <= V_22 -> V_10
|| V_90 -> V_52 -> V_335 <= V_22 -> V_10 ) )
V_333 = 1 ;
return V_333 ;
}
static int F_172 ( struct V_21 * V_22 , struct V_105 * V_106 ,
int V_332 , int V_25 )
{
struct V_78 * V_73 = & V_22 -> V_73 [ V_332 ] ;
struct V_78 * V_336 [ 2 ] = { & V_22 -> V_73 [ V_106 -> V_337 [ 0 ] ] ,
& V_22 -> V_73 [ V_106 -> V_337 [ 1 ] ] } ;
if ( ! F_21 ( V_83 , & V_73 -> V_61 ) &&
! F_21 ( V_180 , & V_73 -> V_61 ) &&
( V_73 -> V_79 ||
( V_73 -> V_81 && ! F_21 ( V_322 , & V_73 -> V_61 ) ) ||
V_106 -> V_136 || V_106 -> V_137 ||
( V_106 -> V_139 && F_171 ( V_22 , V_332 ) ) ||
( V_106 -> V_338 >= 1 && V_336 [ 0 ] -> V_79 ) ||
( V_106 -> V_338 >= 2 && V_336 [ 1 ] -> V_79 ) ||
( V_22 -> V_60 -> V_221 <= 5 && V_106 -> V_338 && V_336 [ 0 ] -> V_81 &&
! F_21 ( V_322 , & V_336 [ 0 ] -> V_61 ) ) ||
( V_22 -> V_60 -> V_221 == 6 && V_106 -> V_338 && V_106 -> V_339 ) ) ) {
F_23 ( F_21 ( V_181 , & V_73 -> V_61 ) ) ;
F_23 ( F_21 ( V_117 , & V_73 -> V_61 ) ) ;
if ( ( V_106 -> V_255 == V_25 - 1 ) &&
( V_106 -> V_338 && ( V_332 == V_106 -> V_337 [ 0 ] ||
V_332 == V_106 -> V_337 [ 1 ] ) ) ) {
F_40 ( L_36 ,
( unsigned long long ) V_22 -> V_10 , V_332 ) ;
F_74 ( V_40 , & V_22 -> V_39 ) ;
F_74 ( V_224 , & V_106 -> V_219 ) ;
F_74 ( V_181 , & V_73 -> V_61 ) ;
V_22 -> V_182 . V_178 = V_332 ;
V_22 -> V_182 . V_183 = - 1 ;
V_106 -> V_340 = 1 ;
V_106 -> V_255 ++ ;
return 1 ;
} else if ( V_106 -> V_255 == V_25 - 2 && V_106 -> V_338 >= 2 ) {
int V_341 ;
for ( V_341 = V_25 ; V_341 -- ; ) {
if ( V_341 == V_332 )
continue;
if ( ! F_21 ( V_180 ,
& V_22 -> V_73 [ V_341 ] . V_61 ) )
break;
}
F_23 ( V_341 < 0 ) ;
F_40 ( L_37 ,
( unsigned long long ) V_22 -> V_10 ,
V_332 , V_341 ) ;
F_74 ( V_40 , & V_22 -> V_39 ) ;
F_74 ( V_224 , & V_106 -> V_219 ) ;
F_74 ( V_181 , & V_22 -> V_73 [ V_332 ] . V_61 ) ;
F_74 ( V_181 , & V_22 -> V_73 [ V_341 ] . V_61 ) ;
V_22 -> V_182 . V_178 = V_332 ;
V_22 -> V_182 . V_183 = V_341 ;
V_106 -> V_255 += 2 ;
V_106 -> V_340 = 1 ;
return 1 ;
} else if ( F_21 ( V_328 , & V_73 -> V_61 ) ) {
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_74 ( V_117 , & V_73 -> V_61 ) ;
V_106 -> V_315 ++ ;
F_40 ( L_38 ,
V_332 , V_106 -> V_136 ) ;
}
}
return 0 ;
}
static void F_173 ( struct V_21 * V_22 ,
struct V_105 * V_106 ,
int V_25 )
{
int V_70 ;
if ( ! F_21 ( V_40 , & V_22 -> V_39 ) && ! V_22 -> V_36 &&
! V_22 -> V_37 )
for ( V_70 = V_25 ; V_70 -- ; )
if ( F_172 ( V_22 , V_106 , V_70 , V_25 ) )
break;
F_74 ( V_43 , & V_22 -> V_39 ) ;
}
static void F_174 ( struct V_2 * V_3 ,
struct V_21 * V_22 , int V_25 , struct V_9 * * V_33 )
{
int V_70 ;
struct V_78 * V_73 ;
for ( V_70 = V_25 ; V_70 -- ; )
if ( V_22 -> V_73 [ V_70 ] . V_82 ) {
V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( ! F_21 ( V_83 , & V_73 -> V_61 ) &&
( F_21 ( V_180 , & V_73 -> V_61 ) ||
F_21 ( V_115 , & V_73 -> V_61 ) ) ) {
struct V_9 * V_203 , * V_342 ;
F_40 ( L_39 , V_70 ) ;
if ( F_28 ( V_115 , & V_73 -> V_61 ) )
F_26 ( V_180 , & V_73 -> V_61 ) ;
V_203 = V_73 -> V_82 ;
V_73 -> V_82 = NULL ;
while ( V_203 && V_203 -> V_13 <
V_73 -> V_10 + V_14 ) {
V_342 = F_2 ( V_203 , V_73 -> V_10 ) ;
if ( ! F_5 ( V_203 ) ) {
F_167 ( V_3 -> V_52 ) ;
V_203 -> V_15 = * V_33 ;
* V_33 = V_203 ;
}
V_203 = V_342 ;
}
F_168 ( V_3 -> V_52 -> V_323 , V_22 -> V_10 ,
V_14 ,
! F_21 ( V_156 , & V_22 -> V_39 ) ,
0 ) ;
}
} else if ( F_21 ( V_115 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
F_26 ( V_115 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
if ( F_28 ( V_316 , & V_22 -> V_39 ) )
if ( F_33 ( & V_3 -> V_317 ) )
F_27 ( V_3 -> V_52 -> V_53 ) ;
}
static void F_175 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
struct V_105 * V_106 ,
int V_25 )
{
int V_343 = 0 , V_313 = 0 , V_70 ;
T_1 V_335 = V_3 -> V_52 -> V_335 ;
if ( V_3 -> V_96 == 2 ||
( V_335 < V_95 && V_22 -> V_10 >= V_335 ) ) {
V_313 = 1 ; V_343 = 2 ;
F_40 ( L_40 ,
V_3 -> V_96 , ( unsigned long long ) V_335 ,
( unsigned long long ) V_22 -> V_10 ) ;
} else for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( ( V_73 -> V_81 || V_70 == V_22 -> V_32 ) &&
! F_21 ( V_83 , & V_73 -> V_61 ) &&
! ( F_21 ( V_180 , & V_73 -> V_61 ) ||
F_21 ( V_181 , & V_73 -> V_61 ) ) ) {
if ( F_21 ( V_328 , & V_73 -> V_61 ) )
V_343 ++ ;
else
V_343 += 2 * V_25 ;
}
if ( ! F_21 ( V_322 , & V_73 -> V_61 ) && V_70 != V_22 -> V_32 &&
! F_21 ( V_83 , & V_73 -> V_61 ) &&
! ( F_21 ( V_180 , & V_73 -> V_61 ) ||
F_21 ( V_181 , & V_73 -> V_61 ) ) ) {
if ( F_21 ( V_328 , & V_73 -> V_61 ) ) V_313 ++ ;
else
V_313 += 2 * V_25 ;
}
}
F_40 ( L_41 ,
( unsigned long long ) V_22 -> V_10 , V_343 , V_313 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
if ( V_343 < V_313 && V_343 > 0 ) {
F_176 ( V_3 -> V_52 -> V_344 , L_42 ,
( unsigned long long ) V_22 -> V_10 , V_343 ) ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( ( V_73 -> V_81 || V_70 == V_22 -> V_32 ) &&
! F_21 ( V_83 , & V_73 -> V_61 ) &&
! ( F_21 ( V_180 , & V_73 -> V_61 ) ||
F_21 ( V_181 , & V_73 -> V_61 ) ) &&
F_21 ( V_328 , & V_73 -> V_61 ) ) {
if (
F_21 ( V_45 , & V_22 -> V_39 ) ) {
F_40 ( L_43
L_44 , V_70 ) ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_74 ( V_117 , & V_73 -> V_61 ) ;
V_106 -> V_315 ++ ;
} else {
F_74 ( V_44 , & V_22 -> V_39 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
}
}
}
}
if ( V_313 <= V_343 && V_313 > 0 ) {
int V_345 = 0 ;
V_313 = 0 ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( ! F_21 ( V_322 , & V_73 -> V_61 ) &&
V_70 != V_22 -> V_32 && V_70 != V_22 -> V_24 &&
! F_21 ( V_83 , & V_73 -> V_61 ) &&
! ( F_21 ( V_180 , & V_73 -> V_61 ) ||
F_21 ( V_181 , & V_73 -> V_61 ) ) ) {
V_313 ++ ;
if ( ! F_21 ( V_328 , & V_73 -> V_61 ) )
continue;
if (
F_21 ( V_45 , & V_22 -> V_39 ) ) {
F_40 ( L_43
L_45 , V_70 ) ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_74 ( V_117 , & V_73 -> V_61 ) ;
V_106 -> V_315 ++ ;
V_345 ++ ;
} else {
F_74 ( V_44 , & V_22 -> V_39 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
}
}
}
if ( V_313 )
F_176 ( V_3 -> V_52 -> V_344 , L_46 ,
( unsigned long long ) V_22 -> V_10 ,
V_313 , V_345 , F_21 ( V_44 , & V_22 -> V_39 ) ) ;
}
if ( ( V_106 -> V_340 || ! F_21 ( V_40 , & V_22 -> V_39 ) ) &&
( V_106 -> V_315 == 0 && ( V_313 == 0 || V_343 == 0 ) &&
! F_21 ( V_47 , & V_22 -> V_39 ) ) )
F_163 ( V_22 , V_106 , V_313 == 0 , 0 ) ;
}
static void F_177 ( struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_105 * V_106 , int V_25 )
{
struct V_78 * V_73 = NULL ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
switch ( V_22 -> V_36 ) {
case V_346 :
if ( V_106 -> V_338 == 0 ) {
F_23 ( V_106 -> V_255 != V_25 ) ;
V_22 -> V_36 = V_229 ;
F_74 ( V_228 , & V_106 -> V_219 ) ;
F_26 ( V_180 , & V_22 -> V_73 [ V_22 -> V_32 ] . V_61 ) ;
V_106 -> V_255 -- ;
break;
}
V_73 = & V_22 -> V_73 [ V_106 -> V_337 [ 0 ] ] ;
case V_185 :
V_22 -> V_36 = V_346 ;
if ( ! V_73 )
V_73 = & V_22 -> V_73 [ V_22 -> V_32 ] ;
if ( F_21 ( V_347 , & V_22 -> V_39 ) )
break;
F_23 ( ! F_21 ( V_180 , & V_73 -> V_61 ) ) ;
F_23 ( V_106 -> V_255 != V_25 ) ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
V_106 -> V_315 ++ ;
F_74 ( V_111 , & V_73 -> V_61 ) ;
F_26 ( V_156 , & V_22 -> V_39 ) ;
F_74 ( V_347 , & V_22 -> V_39 ) ;
break;
case V_229 :
break;
case V_215 :
V_22 -> V_36 = V_346 ;
if ( V_106 -> V_338 )
break;
if ( ( V_22 -> V_182 . V_216 & V_348 ) == 0 )
F_74 ( V_347 , & V_22 -> V_39 ) ;
else {
F_178 ( V_14 , & V_3 -> V_52 -> V_349 ) ;
if ( F_21 ( V_350 , & V_3 -> V_52 -> V_272 ) )
F_74 ( V_347 , & V_22 -> V_39 ) ;
else {
V_22 -> V_36 = V_184 ;
F_74 ( V_40 , & V_22 -> V_39 ) ;
F_74 ( V_224 , & V_106 -> V_219 ) ;
F_74 ( V_181 ,
& V_22 -> V_73 [ V_22 -> V_32 ] . V_61 ) ;
V_22 -> V_182 . V_178 = V_22 -> V_32 ;
V_22 -> V_182 . V_183 = - 1 ;
V_106 -> V_255 ++ ;
}
}
break;
case V_184 :
break;
default:
F_53 ( V_84 L_47 ,
V_142 , V_22 -> V_36 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_66 () ;
}
}
static void F_179 ( struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_105 * V_106 ,
int V_25 )
{
int V_32 = V_22 -> V_32 ;
int V_24 = V_22 -> V_24 ;
struct V_78 * V_73 ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_23 ( V_106 -> V_338 > 2 ) ;
switch ( V_22 -> V_36 ) {
case V_346 :
if ( V_106 -> V_338 == V_106 -> V_351 ) {
V_22 -> V_36 = V_229 ;
}
if ( ! V_106 -> V_351 && V_106 -> V_338 < 2 ) {
if ( V_22 -> V_36 == V_229 )
V_22 -> V_36 = V_231 ;
else
V_22 -> V_36 = V_230 ;
}
V_22 -> V_182 . V_216 = 0 ;
if ( V_22 -> V_36 == V_229 ) {
F_26 ( V_180 , & V_22 -> V_73 [ V_32 ] . V_61 ) ;
V_106 -> V_255 -- ;
}
if ( V_22 -> V_36 >= V_229 &&
V_22 -> V_36 <= V_231 ) {
F_74 ( V_228 , & V_106 -> V_219 ) ;
break;
}
F_23 ( V_106 -> V_338 != 2 ) ;
case V_185 :
V_22 -> V_36 = V_346 ;
if ( F_21 ( V_347 , & V_22 -> V_39 ) )
break;
F_23 ( V_106 -> V_255 < V_25 - 1 ) ;
if ( V_106 -> V_338 == 2 ) {
V_73 = & V_22 -> V_73 [ V_106 -> V_337 [ 1 ] ] ;
V_106 -> V_315 ++ ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_74 ( V_111 , & V_73 -> V_61 ) ;
}
if ( V_106 -> V_338 >= 1 ) {
V_73 = & V_22 -> V_73 [ V_106 -> V_337 [ 0 ] ] ;
V_106 -> V_315 ++ ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_74 ( V_111 , & V_73 -> V_61 ) ;
}
if ( V_22 -> V_182 . V_216 & V_348 ) {
V_73 = & V_22 -> V_73 [ V_32 ] ;
V_106 -> V_315 ++ ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_74 ( V_111 , & V_73 -> V_61 ) ;
}
if ( V_22 -> V_182 . V_216 & V_352 ) {
V_73 = & V_22 -> V_73 [ V_24 ] ;
V_106 -> V_315 ++ ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_74 ( V_111 , & V_73 -> V_61 ) ;
}
F_26 ( V_156 , & V_22 -> V_39 ) ;
F_74 ( V_347 , & V_22 -> V_39 ) ;
break;
case V_229 :
case V_230 :
case V_231 :
break;
case V_215 :
V_22 -> V_36 = V_346 ;
if ( V_22 -> V_182 . V_216 == 0 ) {
if ( ! V_106 -> V_338 )
F_74 ( V_347 , & V_22 -> V_39 ) ;
else {
V_22 -> V_36 = V_185 ;
}
} else {
F_178 ( V_14 , & V_3 -> V_52 -> V_349 ) ;
if ( F_21 ( V_350 , & V_3 -> V_52 -> V_272 ) )
F_74 ( V_347 , & V_22 -> V_39 ) ;
else {
int * V_178 = & V_22 -> V_182 . V_178 ;
V_22 -> V_182 . V_178 = - 1 ;
V_22 -> V_182 . V_183 = - 1 ;
V_22 -> V_36 = V_184 ;
F_74 ( V_40 , & V_22 -> V_39 ) ;
F_74 ( V_224 , & V_106 -> V_219 ) ;
if ( V_22 -> V_182 . V_216 & V_348 ) {
F_74 ( V_181 ,
& V_22 -> V_73 [ V_32 ] . V_61 ) ;
* V_178 = V_32 ;
V_178 = & V_22 -> V_182 . V_183 ;
V_106 -> V_255 ++ ;
}
if ( V_22 -> V_182 . V_216 & V_352 ) {
F_74 ( V_181 ,
& V_22 -> V_73 [ V_24 ] . V_61 ) ;
* V_178 = V_24 ;
V_106 -> V_255 ++ ;
}
}
}
break;
case V_184 :
break;
default:
F_53 ( V_84 L_47 ,
V_142 , V_22 -> V_36 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_66 () ;
}
}
static void F_180 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
int V_70 ;
struct V_157 * V_159 = NULL ;
F_26 ( V_353 , & V_22 -> V_39 ) ;
for ( V_70 = 0 ; V_70 < V_22 -> V_25 ; V_70 ++ )
if ( V_70 != V_22 -> V_32 && V_70 != V_22 -> V_24 ) {
int V_284 , V_354 ;
struct V_21 * V_312 ;
struct V_164 V_165 ;
T_1 V_355 = F_158 ( V_22 , V_70 , 1 ) ;
T_1 V_106 = F_161 ( V_3 , V_355 , 0 ,
& V_284 , NULL ) ;
V_312 = F_63 ( V_3 , V_106 , 0 , 1 , 1 ) ;
if ( V_312 == NULL )
continue;
if ( ! F_21 ( V_56 , & V_312 -> V_39 ) ||
F_21 ( V_356 , & V_312 -> V_73 [ V_284 ] . V_61 ) ) {
F_34 ( V_312 ) ;
continue;
}
F_83 ( & V_165 , 0 , V_159 , NULL , NULL , NULL ) ;
V_159 = F_85 ( V_312 -> V_73 [ V_284 ] . V_68 ,
V_22 -> V_73 [ V_70 ] . V_68 , 0 , 0 , V_152 ,
& V_165 ) ;
F_74 ( V_356 , & V_312 -> V_73 [ V_284 ] . V_61 ) ;
F_74 ( V_180 , & V_312 -> V_73 [ V_284 ] . V_61 ) ;
for ( V_354 = 0 ; V_354 < V_3 -> V_27 ; V_354 ++ )
if ( V_354 != V_312 -> V_32 &&
V_354 != V_312 -> V_24 &&
! F_21 ( V_356 , & V_312 -> V_73 [ V_354 ] . V_61 ) )
break;
if ( V_354 == V_3 -> V_27 ) {
F_74 ( V_357 , & V_312 -> V_39 ) ;
F_74 ( V_43 , & V_312 -> V_39 ) ;
}
F_34 ( V_312 ) ;
}
F_181 ( & V_159 ) ;
}
static void F_182 ( struct V_21 * V_22 , struct V_105 * V_106 )
{
struct V_2 * V_3 = V_22 -> V_60 ;
int V_25 = V_22 -> V_25 ;
struct V_78 * V_73 ;
int V_70 ;
int V_358 = 0 ;
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
V_106 -> V_137 = F_21 ( V_353 , & V_22 -> V_39 ) ;
V_106 -> V_138 = F_21 ( V_357 , & V_22 -> V_39 ) ;
V_106 -> V_337 [ 0 ] = - 1 ;
V_106 -> V_337 [ 1 ] = - 1 ;
F_59 () ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_89 * V_90 ;
T_1 V_131 ;
int V_132 ;
int V_359 = 0 ;
V_73 = & V_22 -> V_73 [ V_70 ] ;
F_40 ( L_48 ,
V_70 , V_73 -> V_61 ,
V_73 -> V_79 , V_73 -> V_81 , V_73 -> V_82 ) ;
if ( F_21 ( V_180 , & V_73 -> V_61 ) && V_73 -> V_79 &&
! F_21 ( V_38 , & V_22 -> V_39 ) )
F_74 ( V_174 , & V_73 -> V_61 ) ;
if ( F_21 ( V_83 , & V_73 -> V_61 ) )
V_106 -> V_315 ++ ;
if ( F_21 ( V_180 , & V_73 -> V_61 ) )
V_106 -> V_255 ++ ;
if ( F_21 ( V_181 , & V_73 -> V_61 ) ) {
V_106 -> V_360 ++ ;
F_23 ( V_106 -> V_360 > 2 ) ;
}
if ( F_21 ( V_174 , & V_73 -> V_61 ) )
V_106 -> V_361 ++ ;
else if ( V_73 -> V_79 )
V_106 -> V_362 ++ ;
if ( V_73 -> V_81 ) {
V_106 -> V_339 ++ ;
if ( ! F_21 ( V_322 , & V_73 -> V_61 ) )
V_106 -> V_363 ++ ;
}
if ( V_73 -> V_82 )
V_106 -> V_82 ++ ;
V_90 = F_60 ( V_3 -> V_25 [ V_70 ] . V_92 ) ;
if ( V_90 && ! F_21 ( V_91 , & V_90 -> V_61 ) &&
V_90 -> V_334 >= V_22 -> V_10 + V_14 &&
! F_73 ( V_90 , V_22 -> V_10 , V_14 ,
& V_131 , & V_132 ) )
F_74 ( V_128 , & V_73 -> V_61 ) ;
else {
if ( V_90 )
F_74 ( V_364 , & V_73 -> V_61 ) ;
V_90 = F_60 ( V_3 -> V_25 [ V_70 ] . V_90 ) ;
F_26 ( V_128 , & V_73 -> V_61 ) ;
}
if ( V_90 && F_21 ( V_91 , & V_90 -> V_61 ) )
V_90 = NULL ;
if ( V_90 ) {
V_359 = F_73 ( V_90 , V_22 -> V_10 , V_14 ,
& V_131 , & V_132 ) ;
if ( V_106 -> V_365 == NULL
&& ( F_21 ( V_280 , & V_90 -> V_61 )
|| V_359 < 0 ) ) {
if ( V_359 < 0 )
F_74 ( V_134 ,
& V_90 -> V_61 ) ;
V_106 -> V_365 = V_90 ;
F_8 ( & V_90 -> V_129 ) ;
}
}
F_26 ( V_328 , & V_73 -> V_61 ) ;
if ( ! V_90 )
;
else if ( V_359 ) {
if ( ! F_21 ( V_130 , & V_90 -> V_61 ) &&
F_21 ( V_180 , & V_73 -> V_61 ) ) {
F_74 ( V_328 , & V_73 -> V_61 ) ;
F_74 ( V_258 , & V_73 -> V_61 ) ;
}
} else if ( F_21 ( V_93 , & V_90 -> V_61 ) )
F_74 ( V_328 , & V_73 -> V_61 ) ;
else if ( V_22 -> V_10 + V_14 <= V_90 -> V_334 )
F_74 ( V_328 , & V_73 -> V_61 ) ;
else if ( F_21 ( V_180 , & V_73 -> V_61 ) &&
F_21 ( V_356 , & V_73 -> V_61 ) )
F_74 ( V_328 , & V_73 -> V_61 ) ;
if ( V_90 && F_21 ( V_269 , & V_73 -> V_61 ) ) {
struct V_89 * V_366 = F_60 (
V_3 -> V_25 [ V_70 ] . V_90 ) ;
if ( V_366 == V_90 )
F_26 ( V_328 , & V_73 -> V_61 ) ;
if ( V_366 && ! F_21 ( V_91 , & V_366 -> V_61 ) ) {
V_106 -> V_367 = 1 ;
F_8 ( & V_366 -> V_129 ) ;
} else
F_26 ( V_269 , & V_73 -> V_61 ) ;
}
if ( V_90 && F_21 ( V_273 , & V_73 -> V_61 ) ) {
struct V_89 * V_366 = F_60 (
V_3 -> V_25 [ V_70 ] . V_90 ) ;
if ( V_366 && ! F_21 ( V_91 , & V_366 -> V_61 ) ) {
V_106 -> V_367 = 1 ;
F_8 ( & V_366 -> V_129 ) ;
} else
F_26 ( V_273 , & V_73 -> V_61 ) ;
}
if ( F_21 ( V_268 , & V_73 -> V_61 ) ) {
struct V_89 * V_366 = F_60 (
V_3 -> V_25 [ V_70 ] . V_92 ) ;
if ( V_366 && ! F_21 ( V_91 , & V_366 -> V_61 ) ) {
V_106 -> V_367 = 1 ;
F_8 ( & V_366 -> V_129 ) ;
} else
F_26 ( V_268 , & V_73 -> V_61 ) ;
}
if ( ! F_21 ( V_328 , & V_73 -> V_61 ) ) {
F_26 ( V_258 , & V_73 -> V_61 ) ;
F_26 ( V_261 , & V_73 -> V_61 ) ;
}
if ( F_21 ( V_258 , & V_73 -> V_61 ) )
F_26 ( V_328 , & V_73 -> V_61 ) ;
if ( ! F_21 ( V_328 , & V_73 -> V_61 ) ) {
if ( V_106 -> V_338 < 2 )
V_106 -> V_337 [ V_106 -> V_338 ] = V_70 ;
V_106 -> V_338 ++ ;
if ( V_90 && ! F_21 ( V_91 , & V_90 -> V_61 ) )
V_358 = 1 ;
}
}
if ( F_21 ( V_329 , & V_22 -> V_39 ) ) {
if ( V_358 ||
V_22 -> V_10 >= V_3 -> V_52 -> V_335 ||
F_21 ( V_368 , & ( V_3 -> V_52 -> V_272 ) ) )
V_106 -> V_136 = 1 ;
else
V_106 -> V_139 = 1 ;
}
F_61 () ;
}
static void F_183 ( struct V_21 * V_22 )
{
struct V_105 V_106 ;
struct V_2 * V_3 = V_22 -> V_60 ;
int V_70 ;
int V_214 ;
int V_25 = V_22 -> V_25 ;
struct V_78 * V_369 , * V_370 ;
F_26 ( V_43 , & V_22 -> V_39 ) ;
if ( F_122 ( V_371 , & V_22 -> V_39 ) ) {
F_74 ( V_43 , & V_22 -> V_39 ) ;
return;
}
if ( F_28 ( V_372 , & V_22 -> V_39 ) ) {
F_74 ( V_329 , & V_22 -> V_39 ) ;
F_26 ( V_347 , & V_22 -> V_39 ) ;
}
F_26 ( V_44 , & V_22 -> V_39 ) ;
F_40 ( L_49
L_50 ,
( unsigned long long ) V_22 -> V_10 , V_22 -> V_39 ,
F_4 ( & V_22 -> V_29 ) , V_22 -> V_32 , V_22 -> V_24 ,
V_22 -> V_36 , V_22 -> V_37 ) ;
F_182 ( V_22 , & V_106 ) ;
if ( V_106 . V_367 ) {
F_74 ( V_43 , & V_22 -> V_39 ) ;
goto V_373;
}
if ( F_93 ( V_106 . V_365 ) ) {
if ( V_106 . V_136 || V_106 . V_137 || V_106 . V_138 ||
V_106 . V_139 || V_106 . V_339 || V_106 . V_82 ) {
F_74 ( V_43 , & V_22 -> V_39 ) ;
goto V_373;
}
F_77 ( V_106 . V_365 , V_3 -> V_52 ) ;
V_106 . V_365 = NULL ;
}
if ( V_106 . V_361 && ! F_21 ( V_38 , & V_22 -> V_39 ) ) {
F_74 ( V_223 , & V_106 . V_219 ) ;
F_74 ( V_38 , & V_22 -> V_39 ) ;
}
F_40 ( L_51
L_52 ,
V_106 . V_315 , V_106 . V_255 , V_106 . V_362 , V_106 . V_339 , V_106 . V_338 ,
V_106 . V_337 [ 0 ] , V_106 . V_337 [ 1 ] ) ;
if ( V_106 . V_338 > V_3 -> V_96 ) {
V_22 -> V_36 = 0 ;
V_22 -> V_37 = 0 ;
if ( V_106 . V_362 + V_106 . V_339 + V_106 . V_82 )
F_166 ( V_3 , V_22 , & V_106 , V_25 , & V_106 . V_33 ) ;
if ( V_106 . V_136 + V_106 . V_139 )
F_169 ( V_3 , V_22 , & V_106 ) ;
}
V_214 = 0 ;
if ( V_22 -> V_37 == V_211 )
V_214 = 1 ;
if ( V_22 -> V_37 == V_209 ||
V_22 -> V_37 == V_211 ) {
V_22 -> V_37 = V_374 ;
F_23 ( ! F_21 ( V_180 , & V_22 -> V_73 [ V_22 -> V_32 ] . V_61 ) &&
! F_21 ( V_115 , & V_22 -> V_73 [ V_22 -> V_32 ] . V_61 ) ) ;
F_23 ( V_22 -> V_24 >= 0 &&
! F_21 ( V_180 , & V_22 -> V_73 [ V_22 -> V_24 ] . V_61 ) &&
! F_21 ( V_115 , & V_22 -> V_73 [ V_22 -> V_24 ] . V_61 ) ) ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( F_21 ( V_83 , & V_73 -> V_61 ) &&
( V_70 == V_22 -> V_32 || V_70 == V_22 -> V_24 ||
V_73 -> V_82 ) ) {
F_40 ( L_53 , V_70 ) ;
F_74 ( V_111 , & V_73 -> V_61 ) ;
if ( V_214 )
continue;
if ( ! F_21 ( V_328 , & V_73 -> V_61 ) ||
( ( V_70 == V_22 -> V_32 || V_70 == V_22 -> V_24 ) &&
V_106 . V_338 == 0 ) )
F_74 ( V_347 , & V_22 -> V_39 ) ;
}
}
if ( F_28 ( V_45 , & V_22 -> V_39 ) )
V_106 . V_375 = 1 ;
}
V_369 = & V_22 -> V_73 [ V_22 -> V_32 ] ;
V_106 . V_376 = ( V_106 . V_338 >= 1 && V_106 . V_337 [ 0 ] == V_22 -> V_32 )
|| ( V_106 . V_338 >= 2 && V_106 . V_337 [ 1 ] == V_22 -> V_32 ) ;
V_370 = & V_22 -> V_73 [ V_22 -> V_24 ] ;
V_106 . V_351 = ( V_106 . V_338 >= 1 && V_106 . V_337 [ 0 ] == V_22 -> V_24 )
|| ( V_106 . V_338 >= 2 && V_106 . V_337 [ 1 ] == V_22 -> V_24 )
|| V_3 -> V_221 < 6 ;
if ( V_106 . V_82 &&
( V_106 . V_376 || ( ( F_21 ( V_328 , & V_369 -> V_61 )
&& ! F_21 ( V_83 , & V_369 -> V_61 )
&& ( F_21 ( V_180 , & V_369 -> V_61 ) ||
F_21 ( V_115 , & V_369 -> V_61 ) ) ) ) ) &&
( V_106 . V_351 || ( ( F_21 ( V_328 , & V_370 -> V_61 )
&& ! F_21 ( V_83 , & V_370 -> V_61 )
&& ( F_21 ( V_180 , & V_370 -> V_61 ) ||
F_21 ( V_115 , & V_370 -> V_61 ) ) ) ) ) )
F_174 ( V_3 , V_22 , V_25 , & V_106 . V_33 ) ;
if ( V_106 . V_362 || V_106 . V_363
|| ( V_3 -> V_221 == 6 && V_106 . V_339 && V_106 . V_338 )
|| ( V_106 . V_136 && ( V_106 . V_255 + V_106 . V_360 < V_25 ) )
|| V_106 . V_139
|| V_106 . V_137 )
F_173 ( V_22 , & V_106 , V_25 ) ;
if ( V_106 . V_339 && ! V_22 -> V_37 && ! V_22 -> V_36 )
F_175 ( V_3 , V_22 , & V_106 , V_25 ) ;
if ( V_22 -> V_36 ||
( V_106 . V_136 && V_106 . V_315 == 0 &&
! F_21 ( V_40 , & V_22 -> V_39 ) &&
! F_21 ( V_347 , & V_22 -> V_39 ) ) ) {
if ( V_3 -> V_221 == 6 )
F_179 ( V_3 , V_22 , & V_106 , V_25 ) ;
else
F_177 ( V_3 , V_22 , & V_106 , V_25 ) ;
}
if ( V_106 . V_139 && V_106 . V_315 == 0
&& ! F_21 ( V_347 , & V_22 -> V_39 ) ) {
for ( V_70 = 0 ; V_70 < V_3 -> V_27 ; V_70 ++ )
if ( F_21 ( V_180 , & V_22 -> V_73 [ V_70 ] . V_61 ) &&
F_21 ( V_364 , & V_22 -> V_73 [ V_70 ] . V_61 ) ) {
F_74 ( V_119 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_74 ( V_83 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
V_106 . V_315 ++ ;
}
F_74 ( V_347 , & V_22 -> V_39 ) ;
}
if ( ( V_106 . V_136 || V_106 . V_139 ) && V_106 . V_315 == 0 &&
F_21 ( V_347 , & V_22 -> V_39 ) ) {
F_170 ( V_3 -> V_52 , V_14 , 1 ) ;
F_26 ( V_329 , & V_22 -> V_39 ) ;
}
if ( V_106 . V_338 <= V_3 -> V_96 && ! V_3 -> V_52 -> V_377 )
for ( V_70 = 0 ; V_70 < V_106 . V_338 ; V_70 ++ ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_106 . V_337 [ V_70 ] ] ;
if ( F_21 ( V_258 , & V_73 -> V_61 )
&& ! F_21 ( V_83 , & V_73 -> V_61 )
&& F_21 ( V_180 , & V_73 -> V_61 )
) {
if ( ! F_21 ( V_261 , & V_73 -> V_61 ) ) {
F_74 ( V_111 , & V_73 -> V_61 ) ;
F_74 ( V_261 , & V_73 -> V_61 ) ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
V_106 . V_315 ++ ;
} else {
F_74 ( V_117 , & V_73 -> V_61 ) ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
V_106 . V_315 ++ ;
}
}
}
if ( V_22 -> V_37 == V_213 ) {
struct V_21 * V_378
= F_63 ( V_3 , V_22 -> V_10 , 1 , 1 , 1 ) ;
if ( V_378 && F_21 ( V_353 , & V_378 -> V_39 ) ) {
F_74 ( V_44 , & V_22 -> V_39 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
if ( ! F_156 ( V_45 ,
& V_378 -> V_39 ) )
F_8 ( & V_3 -> V_54 ) ;
F_34 ( V_378 ) ;
goto V_373;
}
if ( V_378 )
F_34 ( V_378 ) ;
V_22 -> V_37 = V_374 ;
F_26 ( V_56 , & V_22 -> V_39 ) ;
for ( V_70 = V_3 -> V_27 ; V_70 -- ; ) {
F_74 ( V_111 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_74 ( V_83 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
V_106 . V_315 ++ ;
}
}
if ( V_106 . V_138 && F_21 ( V_56 , & V_22 -> V_39 ) &&
! V_22 -> V_37 ) {
V_22 -> V_25 = V_3 -> V_27 ;
F_52 ( V_22 -> V_10 , V_3 , 0 , V_22 ) ;
F_163 ( V_22 , & V_106 , 1 , 1 ) ;
} else if ( V_106 . V_138 && ! V_22 -> V_37 && V_106 . V_315 == 0 ) {
F_26 ( V_357 , & V_22 -> V_39 ) ;
F_30 ( & V_3 -> V_379 ) ;
F_31 ( & V_3 -> V_233 ) ;
F_170 ( V_3 -> V_52 , V_14 , 1 ) ;
}
if ( V_106 . V_137 && V_106 . V_315 == 0 &&
! F_21 ( V_40 , & V_22 -> V_39 ) )
F_180 ( V_3 , V_22 ) ;
V_373:
if ( F_93 ( V_106 . V_365 ) ) {
if ( V_3 -> V_52 -> V_135 )
F_76 ( V_106 . V_365 ,
V_3 -> V_52 ) ;
else
F_77 ( V_106 . V_365 ,
V_3 -> V_52 ) ;
}
if ( V_106 . V_367 )
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_89 * V_90 ;
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( F_28 ( V_269 , & V_73 -> V_61 ) ) {
V_90 = V_3 -> V_25 [ V_70 ] . V_90 ;
if ( ! F_154 ( V_90 , V_22 -> V_10 ,
V_14 , 0 ) )
F_155 ( V_3 -> V_52 , V_90 ) ;
F_77 ( V_90 , V_3 -> V_52 ) ;
}
if ( F_28 ( V_273 , & V_73 -> V_61 ) ) {
V_90 = V_3 -> V_25 [ V_70 ] . V_90 ;
F_184 ( V_90 , V_22 -> V_10 ,
V_14 , 0 ) ;
F_77 ( V_90 , V_3 -> V_52 ) ;
}
if ( F_28 ( V_268 , & V_73 -> V_61 ) ) {
V_90 = V_3 -> V_25 [ V_70 ] . V_92 ;
if ( ! V_90 )
V_90 = V_3 -> V_25 [ V_70 ] . V_90 ;
F_184 ( V_90 , V_22 -> V_10 ,
V_14 , 0 ) ;
F_77 ( V_90 , V_3 -> V_52 ) ;
}
}
if ( V_106 . V_219 )
F_120 ( V_22 , V_106 . V_219 ) ;
F_70 ( V_22 , & V_106 ) ;
if ( V_106 . V_375 ) {
F_30 ( & V_3 -> V_54 ) ;
if ( F_4 ( & V_3 -> V_54 ) <
V_55 )
F_27 ( V_3 -> V_52 -> V_53 ) ;
}
F_16 ( V_106 . V_33 ) ;
F_119 ( V_371 , & V_22 -> V_39 ) ;
}
static void F_185 ( struct V_2 * V_3 )
{
if ( F_4 ( & V_3 -> V_54 ) < V_55 ) {
while ( ! F_24 ( & V_3 -> V_46 ) ) {
struct V_64 * V_380 = V_3 -> V_46 . V_67 ;
struct V_21 * V_22 ;
V_22 = F_45 ( V_380 , struct V_21 , V_41 ) ;
F_46 ( V_380 ) ;
F_26 ( V_44 , & V_22 -> V_39 ) ;
if ( ! F_156 ( V_45 , & V_22 -> V_39 ) )
F_8 ( & V_3 -> V_54 ) ;
F_25 ( & V_22 -> V_41 , & V_3 -> V_381 ) ;
}
}
}
static void F_186 ( struct V_2 * V_3 )
{
struct V_64 V_382 ;
F_139 ( & V_382 , & V_3 -> V_50 ) ;
F_46 ( & V_3 -> V_50 ) ;
while ( ! F_24 ( & V_382 ) ) {
struct V_21 * V_22 = F_45 ( V_382 . V_67 , struct V_21 , V_41 ) ;
F_46 ( & V_22 -> V_41 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_32 ( V_3 , V_22 ) ;
}
}
int F_187 ( struct V_52 * V_52 , int V_383 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
if ( V_3 -> V_100 )
return 1 ;
if ( V_3 -> V_99 )
return 1 ;
if ( F_188 ( & V_3 -> V_57 ) )
return 1 ;
return 0 ;
}
static int F_189 ( void * V_384 , int V_383 )
{
struct V_52 * V_52 = V_384 ;
return F_190 ( V_52 , V_383 ) ||
F_187 ( V_52 , V_383 ) ;
}
static int F_191 ( struct V_385 * V_386 ,
struct V_387 * V_388 ,
struct V_160 * V_389 )
{
struct V_52 * V_52 = V_386 -> V_390 ;
T_1 V_10 = V_388 -> V_13 + F_192 ( V_388 -> V_35 ) ;
int F_132 ;
unsigned int V_294 = V_52 -> V_294 ;
unsigned int V_391 = V_388 -> V_12 >> 9 ;
if ( ( V_388 -> V_124 & 1 ) == V_114 )
return V_389 -> V_151 ;
if ( V_52 -> V_392 < V_52 -> V_294 )
V_294 = V_52 -> V_392 ;
F_132 = ( V_294 - ( ( V_10 & ( V_294 - 1 ) ) + V_391 ) ) << 9 ;
if ( F_132 < 0 ) F_132 = 0 ;
if ( F_132 <= V_389 -> V_151 && V_391 == 0 )
return V_389 -> V_151 ;
else
return F_132 ;
}
static int F_193 ( struct V_52 * V_52 , struct V_9 * V_9 )
{
T_1 V_10 = V_9 -> V_13 + F_192 ( V_9 -> V_35 ) ;
unsigned int V_294 = V_52 -> V_294 ;
unsigned int V_391 = V_9 -> V_12 >> 9 ;
if ( V_52 -> V_392 < V_52 -> V_294 )
V_294 = V_52 -> V_392 ;
return V_294 >=
( ( V_10 & ( V_294 - 1 ) ) + V_391 ) ;
}
static void F_194 ( struct V_9 * V_34 , struct V_2 * V_3 )
{
unsigned long V_61 ;
F_159 ( & V_3 -> V_62 , V_61 ) ;
V_34 -> V_15 = V_3 -> V_393 ;
V_3 -> V_393 = V_34 ;
F_160 ( & V_3 -> V_62 , V_61 ) ;
F_27 ( V_3 -> V_52 -> V_53 ) ;
}
static struct V_9 * F_195 ( struct V_2 * V_3 )
{
struct V_9 * V_34 ;
V_34 = V_3 -> V_59 ;
if ( V_34 ) {
V_3 -> V_59 = NULL ;
return V_34 ;
}
V_34 = V_3 -> V_393 ;
if( V_34 ) {
V_3 -> V_393 = V_34 -> V_15 ;
V_34 -> V_15 = NULL ;
F_11 ( V_34 , 1 ) ;
}
return V_34 ;
}
static void F_196 ( struct V_9 * V_34 , int error )
{
struct V_9 * V_394 = V_34 -> V_254 ;
struct V_52 * V_52 ;
struct V_2 * V_3 ;
int V_255 = F_21 ( V_148 , & V_34 -> V_147 ) ;
struct V_89 * V_90 ;
F_197 ( V_34 ) ;
V_90 = ( void * ) V_394 -> V_15 ;
V_394 -> V_15 = NULL ;
V_52 = V_90 -> V_52 ;
V_3 = V_52 -> V_278 ;
F_77 ( V_90 , V_3 -> V_52 ) ;
if ( ! error && V_255 ) {
F_17 ( F_18 ( V_394 -> V_35 ) ,
V_394 , 0 ) ;
F_19 ( V_394 , 0 ) ;
if ( F_33 ( & V_3 -> V_395 ) )
F_31 ( & V_3 -> V_58 ) ;
return;
}
F_40 ( L_54 ) ;
F_194 ( V_394 , V_3 ) ;
}
static int F_198 ( struct V_9 * V_34 )
{
struct V_385 * V_386 = F_18 ( V_34 -> V_35 ) ;
if ( ( V_34 -> V_12 >> 9 ) > F_199 ( V_386 ) )
return 0 ;
F_200 ( V_386 , V_34 ) ;
if ( V_34 -> V_17 > F_201 ( V_386 ) )
return 0 ;
if ( V_386 -> V_396 )
return 0 ;
return 1 ;
}
static int F_202 ( struct V_52 * V_52 , struct V_9 * V_397 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
int V_284 ;
struct V_9 * V_398 ;
struct V_89 * V_90 ;
T_1 V_399 ;
if ( ! F_193 ( V_52 , V_397 ) ) {
F_40 ( L_55 ) ;
return 0 ;
}
V_398 = F_203 ( V_397 , V_253 , V_52 ) ;
if ( ! V_398 )
return 0 ;
V_398 -> V_125 = F_196 ;
V_398 -> V_254 = V_397 ;
V_398 -> V_13 = F_161 ( V_3 , V_397 -> V_13 ,
0 ,
& V_284 , NULL ) ;
V_399 = V_398 -> V_13 + ( V_398 -> V_12 >> 9 ) ;
F_59 () ;
V_90 = F_60 ( V_3 -> V_25 [ V_284 ] . V_92 ) ;
if ( ! V_90 || F_21 ( V_91 , & V_90 -> V_61 ) ||
V_90 -> V_334 < V_399 ) {
V_90 = F_60 ( V_3 -> V_25 [ V_284 ] . V_90 ) ;
if ( V_90 &&
( F_21 ( V_91 , & V_90 -> V_61 ) ||
! ( F_21 ( V_93 , & V_90 -> V_61 ) ||
V_90 -> V_334 >= V_399 ) ) )
V_90 = NULL ;
}
if ( V_90 ) {
T_1 V_131 ;
int V_132 ;
F_8 ( & V_90 -> V_129 ) ;
F_61 () ;
V_397 -> V_15 = ( void * ) V_90 ;
V_398 -> V_35 = V_90 -> V_140 ;
V_398 -> V_147 &= ~ ( 1 << V_400 ) ;
if ( ! F_198 ( V_398 ) ||
F_73 ( V_90 , V_398 -> V_13 , V_398 -> V_12 >> 9 ,
& V_131 , & V_132 ) ) {
F_197 ( V_398 ) ;
F_77 ( V_90 , V_52 ) ;
return 0 ;
}
V_398 -> V_13 += V_90 -> V_144 ;
F_64 ( & V_3 -> V_62 ) ;
F_65 ( V_3 -> V_58 ,
V_3 -> V_99 == 0 ,
V_3 -> V_62 ) ;
F_8 ( & V_3 -> V_395 ) ;
F_67 ( & V_3 -> V_62 ) ;
F_79 ( F_18 ( V_398 -> V_35 ) ,
V_398 , F_80 ( V_52 -> V_155 ) ,
V_397 -> V_13 ) ;
F_81 ( V_398 ) ;
return 1 ;
} else {
F_61 () ;
F_197 ( V_398 ) ;
return 0 ;
}
}
static struct V_21 * F_204 ( struct V_2 * V_3 )
{
struct V_21 * V_22 ;
F_40 ( L_56 ,
V_142 ,
F_24 ( & V_3 -> V_51 ) ? L_57 : L_58 ,
F_24 ( & V_3 -> V_381 ) ? L_57 : L_58 ,
F_4 ( & V_3 -> V_317 ) , V_3 -> V_401 ) ;
if ( ! F_24 ( & V_3 -> V_51 ) ) {
V_22 = F_45 ( V_3 -> V_51 . V_67 , F_205 ( * V_22 ) , V_41 ) ;
if ( F_24 ( & V_3 -> V_381 ) )
V_3 -> V_401 = 0 ;
else if ( ! F_21 ( V_141 , & V_22 -> V_39 ) ) {
if ( V_3 -> V_381 . V_67 == V_3 -> V_402 )
V_3 -> V_401 ++ ;
else {
V_3 -> V_402 = V_3 -> V_381 . V_67 ;
V_3 -> V_401 -= V_3 -> V_403 ;
if ( V_3 -> V_401 < 0 )
V_3 -> V_401 = 0 ;
}
}
} else if ( ! F_24 ( & V_3 -> V_381 ) &&
( ( V_3 -> V_403 &&
V_3 -> V_401 > V_3 -> V_403 ) ||
F_4 ( & V_3 -> V_317 ) == 0 ) ) {
V_22 = F_45 ( V_3 -> V_381 . V_67 ,
F_205 ( * V_22 ) , V_41 ) ;
V_3 -> V_401 -= V_3 -> V_403 ;
if ( V_3 -> V_401 < 0 )
V_3 -> V_401 = 0 ;
} else
return NULL ;
F_46 ( & V_22 -> V_41 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_23 ( F_4 ( & V_22 -> V_29 ) != 1 ) ;
return V_22 ;
}
static void F_206 ( struct V_404 * V_405 , bool V_406 )
{
struct V_407 * V_408 = F_207 (
V_405 , struct V_407 , V_408 ) ;
struct V_21 * V_22 ;
struct V_52 * V_52 = V_408 -> V_408 . V_384 ;
struct V_2 * V_3 = V_52 -> V_278 ;
int V_18 = 0 ;
if ( V_408 -> V_409 . V_67 && ! F_24 ( & V_408 -> V_409 ) ) {
F_64 ( & V_3 -> V_62 ) ;
while ( ! F_24 ( & V_408 -> V_409 ) ) {
V_22 = F_208 ( & V_408 -> V_409 , struct V_21 , V_41 ) ;
F_46 ( & V_22 -> V_41 ) ;
F_209 () ;
F_26 ( V_102 , & V_22 -> V_39 ) ;
F_32 ( V_3 , V_22 ) ;
V_18 ++ ;
}
F_67 ( & V_3 -> V_62 ) ;
}
F_210 ( V_52 -> V_344 , V_18 , ! V_406 ) ;
F_144 ( V_408 ) ;
}
static void F_211 ( struct V_52 * V_52 ,
struct V_21 * V_22 )
{
struct V_404 * V_405 = F_212 (
F_206 , V_52 ,
sizeof( struct V_407 ) ) ;
struct V_407 * V_408 ;
if ( ! V_405 ) {
F_34 ( V_22 ) ;
return;
}
V_408 = F_207 ( V_405 , struct V_407 , V_408 ) ;
if ( V_408 -> V_409 . V_67 == NULL )
F_130 ( & V_408 -> V_409 ) ;
if ( ! F_156 ( V_102 , & V_22 -> V_39 ) )
F_25 ( & V_22 -> V_41 , & V_408 -> V_409 ) ;
else
F_34 ( V_22 ) ;
}
static void F_213 ( struct V_52 * V_52 , struct V_9 * V_34 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
T_1 V_410 , V_411 ;
struct V_21 * V_22 ;
int V_412 ;
int V_413 ;
if ( V_52 -> V_94 != V_95 )
return;
V_410 = V_34 -> V_13 & ~ ( ( T_1 ) V_14 - 1 ) ;
V_411 = V_34 -> V_13 + ( V_34 -> V_12 >> 9 ) ;
V_34 -> V_15 = NULL ;
V_34 -> V_17 = 1 ;
V_413 = V_3 -> V_294 *
( V_3 -> V_27 - V_3 -> V_96 ) ;
V_410 = F_214 ( V_410 ,
V_413 ) ;
F_162 ( V_411 , V_413 ) ;
V_410 *= V_3 -> V_294 ;
V_411 *= V_3 -> V_294 ;
for (; V_410 < V_411 ;
V_410 += V_14 ) {
F_215 ( V_414 ) ;
int V_415 ;
V_416:
V_22 = F_63 ( V_3 , V_410 , 0 , 0 , 0 ) ;
F_216 ( & V_3 -> V_233 , & V_414 ,
V_417 ) ;
F_64 ( & V_22 -> V_176 ) ;
for ( V_415 = 0 ; V_415 < V_3 -> V_27 ; V_415 ++ ) {
if ( V_415 == V_22 -> V_32 || V_415 == V_22 -> V_24 )
continue;
if ( V_22 -> V_73 [ V_415 ] . V_81 || V_22 -> V_73 [ V_415 ] . V_79 ) {
F_74 ( V_232 , & V_22 -> V_73 [ V_415 ] . V_61 ) ;
F_67 ( & V_22 -> V_176 ) ;
F_34 ( V_22 ) ;
F_217 () ;
goto V_416;
}
}
F_218 ( & V_3 -> V_233 , & V_414 ) ;
for ( V_415 = 0 ; V_415 < V_3 -> V_27 ; V_415 ++ ) {
if ( V_415 == V_22 -> V_32 || V_415 == V_22 -> V_24 )
continue;
V_22 -> V_73 [ V_415 ] . V_81 = V_34 ;
F_74 ( V_322 , & V_22 -> V_73 [ V_415 ] . V_61 ) ;
F_7 ( V_34 ) ;
}
F_67 ( & V_22 -> V_176 ) ;
if ( V_3 -> V_52 -> V_323 ) {
for ( V_415 = 0 ;
V_415 < V_3 -> V_27 - V_3 -> V_96 ;
V_415 ++ )
F_165 ( V_52 -> V_323 ,
V_22 -> V_10 ,
V_14 ,
0 ) ;
V_22 -> V_48 = V_3 -> V_324 + 1 ;
F_74 ( V_47 , & V_22 -> V_39 ) ;
}
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_26 ( V_44 , & V_22 -> V_39 ) ;
if ( ! F_156 ( V_45 , & V_22 -> V_39 ) )
F_8 ( & V_3 -> V_54 ) ;
F_211 ( V_52 , V_22 ) ;
}
V_412 = F_5 ( V_34 ) ;
if ( V_412 == 0 ) {
F_167 ( V_52 ) ;
F_19 ( V_34 , 0 ) ;
}
}
static void F_219 ( struct V_52 * V_52 , struct V_9 * V_34 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
int V_284 ;
T_1 V_289 ;
T_1 V_410 , V_411 ;
struct V_21 * V_22 ;
const int V_107 = F_220 ( V_34 ) ;
int V_412 ;
if ( F_93 ( V_34 -> V_124 & V_146 ) ) {
F_221 ( V_52 , V_34 ) ;
return;
}
F_222 ( V_52 , V_34 ) ;
if ( V_107 == V_118 &&
V_52 -> V_94 == V_95 &&
F_202 ( V_52 , V_34 ) )
return;
if ( F_93 ( V_34 -> V_124 & V_116 ) ) {
F_213 ( V_52 , V_34 ) ;
return;
}
V_410 = V_34 -> V_13 & ~ ( ( T_1 ) V_14 - 1 ) ;
V_411 = V_34 -> V_13 + ( V_34 -> V_12 >> 9 ) ;
V_34 -> V_15 = NULL ;
V_34 -> V_17 = 1 ;
for (; V_410 < V_411 ; V_410 += V_14 ) {
F_215 ( V_414 ) ;
int V_75 ;
V_264:
V_75 = 0 ;
F_216 ( & V_3 -> V_233 , & V_414 , V_417 ) ;
if ( F_93 ( V_3 -> V_104 != V_95 ) ) {
F_64 ( & V_3 -> V_62 ) ;
if ( V_52 -> V_418
? V_410 < V_3 -> V_104
: V_410 >= V_3 -> V_104 ) {
V_75 = 1 ;
} else {
if ( V_52 -> V_418
? V_410 < V_3 -> V_419
: V_410 >= V_3 -> V_419 ) {
F_67 ( & V_3 -> V_62 ) ;
F_217 () ;
goto V_264;
}
}
F_67 ( & V_3 -> V_62 ) ;
}
V_289 = F_161 ( V_3 , V_410 ,
V_75 ,
& V_284 , NULL ) ;
F_40 ( L_59 ,
( unsigned long long ) V_289 ,
( unsigned long long ) V_410 ) ;
V_22 = F_63 ( V_3 , V_289 , V_75 ,
( V_34 -> V_124 & V_420 ) , 0 ) ;
if ( V_22 ) {
if ( F_93 ( V_75 ) ) {
int V_421 = 0 ;
F_64 ( & V_3 -> V_62 ) ;
if ( V_52 -> V_418
? V_410 >= V_3 -> V_104
: V_410 < V_3 -> V_104 )
V_421 = 1 ;
F_67 ( & V_3 -> V_62 ) ;
if ( V_421 ) {
F_34 ( V_22 ) ;
F_217 () ;
goto V_264;
}
}
if ( V_107 == V_114 &&
V_410 >= V_52 -> V_422 &&
V_410 < V_52 -> V_423 ) {
F_34 ( V_22 ) ;
F_223 ( V_424 ) ;
F_216 ( & V_3 -> V_233 ,
& V_414 , V_425 ) ;
if ( V_410 >= V_52 -> V_422 &&
V_410 < V_52 -> V_423 )
F_217 () ;
goto V_264;
}
if ( F_21 ( V_56 , & V_22 -> V_39 ) ||
! F_164 ( V_22 , V_34 , V_284 , V_107 ) ) {
F_27 ( V_52 -> V_53 ) ;
F_34 ( V_22 ) ;
F_217 () ;
goto V_264;
}
F_218 ( & V_3 -> V_233 , & V_414 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_26 ( V_44 , & V_22 -> V_39 ) ;
if ( ( V_34 -> V_124 & V_121 ) &&
! F_156 ( V_45 , & V_22 -> V_39 ) )
F_8 ( & V_3 -> V_54 ) ;
F_211 ( V_52 , V_22 ) ;
} else {
F_26 ( V_148 , & V_34 -> V_147 ) ;
F_218 ( & V_3 -> V_233 , & V_414 ) ;
break;
}
}
V_412 = F_5 ( V_34 ) ;
if ( V_412 == 0 ) {
if ( V_107 == V_114 )
F_167 ( V_52 ) ;
F_17 ( F_18 ( V_34 -> V_35 ) ,
V_34 , 0 ) ;
F_19 ( V_34 , 0 ) ;
}
}
static T_1 F_224 ( struct V_52 * V_52 , T_1 V_426 , int * V_427 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
struct V_21 * V_22 ;
T_1 V_428 , V_411 ;
int V_27 = V_3 -> V_77 ;
int V_295 = V_27 - V_3 -> V_96 ;
int V_429 = V_3 -> V_27 - V_3 -> V_96 ;
int V_70 ;
int V_284 ;
T_1 V_430 , V_431 , V_432 ;
T_1 V_433 ;
int V_434 ;
struct V_64 V_435 ;
if ( V_426 == 0 ) {
if ( V_52 -> V_418 &&
V_3 -> V_104 < F_225 ( V_52 , 0 , 0 ) ) {
V_426 = F_225 ( V_52 , 0 , 0 )
- V_3 -> V_104 ;
} else if ( ! V_52 -> V_418 &&
V_3 -> V_104 > 0 )
V_426 = V_3 -> V_104 ;
F_162 ( V_426 , V_429 ) ;
if ( V_426 ) {
V_52 -> V_436 = V_426 ;
F_226 ( & V_52 -> V_437 , NULL , L_60 ) ;
* V_427 = 1 ;
return V_426 ;
}
}
if ( V_52 -> V_392 > V_52 -> V_294 )
V_434 = V_52 -> V_392 ;
else
V_434 = V_52 -> V_294 ;
V_430 = V_3 -> V_104 ;
F_162 ( V_430 , V_429 ) ;
V_431 = V_3 -> V_104 ;
F_162 ( V_431 , V_295 ) ;
V_432 = V_3 -> V_419 ;
F_162 ( V_432 , V_295 ) ;
if ( V_52 -> V_418 ) {
V_430 -= F_227 ( T_1 , V_434 , V_430 ) ;
V_431 += V_434 ;
V_432 += V_434 ;
} else {
V_430 += V_434 ;
V_431 -= F_227 ( T_1 , V_434 , V_431 ) ;
V_432 -= F_227 ( T_1 , V_434 , V_432 ) ;
}
if ( V_52 -> V_418 ) {
F_23 ( V_3 -> V_104 == 0 ) ;
V_433 = V_430 ;
F_23 ( ( V_52 -> V_438 &
~ ( ( T_1 ) V_434 - 1 ) )
- V_434 - V_433
!= V_426 ) ;
} else {
F_23 ( V_430 != V_426 + V_434 ) ;
V_433 = V_426 ;
}
if ( V_3 -> V_439 < 0 ) {
V_432 += - V_3 -> V_439 ;
V_431 += - V_3 -> V_439 ;
} else
V_430 += V_3 -> V_439 ;
if ( ( V_52 -> V_418
? ( V_432 > V_430 && V_431 < V_430 )
: ( V_432 < V_430 && V_431 > V_430 ) ) ||
F_228 ( V_440 , V_3 -> V_441 + 10 * V_442 ) ) {
F_121 ( V_3 -> V_233 ,
F_4 ( & V_3 -> V_379 ) == 0 ) ;
V_52 -> V_94 = V_3 -> V_104 ;
V_52 -> V_436 = V_426 ;
V_3 -> V_441 = V_440 ;
F_74 ( V_281 , & V_52 -> V_61 ) ;
F_27 ( V_52 -> V_53 ) ;
F_121 ( V_52 -> V_443 , V_52 -> V_61 == 0 ||
F_229 () ) ;
F_64 ( & V_3 -> V_62 ) ;
V_3 -> V_419 = V_52 -> V_94 ;
F_67 ( & V_3 -> V_62 ) ;
F_31 ( & V_3 -> V_233 ) ;
F_226 ( & V_52 -> V_437 , NULL , L_60 ) ;
}
F_130 ( & V_435 ) ;
for ( V_70 = 0 ; V_70 < V_434 ; V_70 += V_14 ) {
int V_354 ;
int V_444 = 0 ;
V_22 = F_63 ( V_3 , V_433 + V_70 , 0 , 0 , 1 ) ;
F_74 ( V_56 , & V_22 -> V_39 ) ;
F_8 ( & V_3 -> V_379 ) ;
for ( V_354 = V_22 -> V_25 ; V_354 -- ; ) {
T_1 V_106 ;
if ( V_354 == V_22 -> V_32 )
continue;
if ( V_3 -> V_221 == 6 &&
V_354 == V_22 -> V_24 )
continue;
V_106 = F_158 ( V_22 , V_354 , 0 ) ;
if ( V_106 < F_225 ( V_52 , 0 , 0 ) ) {
V_444 = 1 ;
continue;
}
memset ( F_230 ( V_22 -> V_73 [ V_354 ] . V_68 ) , 0 , V_152 ) ;
F_74 ( V_356 , & V_22 -> V_73 [ V_354 ] . V_61 ) ;
F_74 ( V_180 , & V_22 -> V_73 [ V_354 ] . V_61 ) ;
}
if ( ! V_444 ) {
F_74 ( V_357 , & V_22 -> V_39 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
}
F_139 ( & V_22 -> V_41 , & V_435 ) ;
}
F_64 ( & V_3 -> V_62 ) ;
if ( V_52 -> V_418 )
V_3 -> V_104 -= V_434 * V_429 ;
else
V_3 -> V_104 += V_434 * V_429 ;
F_67 ( & V_3 -> V_62 ) ;
V_428 =
F_161 ( V_3 , V_433 * ( V_429 ) ,
1 , & V_284 , NULL ) ;
V_411 =
F_161 ( V_3 , ( ( V_433 + V_434 )
* V_429 - 1 ) ,
1 , & V_284 , NULL ) ;
if ( V_411 >= V_52 -> V_438 )
V_411 = V_52 -> V_438 - 1 ;
while ( V_428 <= V_411 ) {
V_22 = F_63 ( V_3 , V_428 , 1 , 0 , 1 ) ;
F_74 ( V_353 , & V_22 -> V_39 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_34 ( V_22 ) ;
V_428 += V_14 ;
}
while ( ! F_24 ( & V_435 ) ) {
V_22 = F_45 ( V_435 . V_67 , struct V_21 , V_41 ) ;
F_46 ( & V_22 -> V_41 ) ;
F_34 ( V_22 ) ;
}
V_426 += V_434 ;
if ( ( V_426 - V_52 -> V_436 ) * 2
>= V_52 -> V_445 - V_52 -> V_436 ) {
F_121 ( V_3 -> V_233 ,
F_4 ( & V_3 -> V_379 ) == 0 ) ;
V_52 -> V_94 = V_3 -> V_104 ;
V_52 -> V_436 = V_426 ;
V_3 -> V_441 = V_440 ;
F_74 ( V_281 , & V_52 -> V_61 ) ;
F_27 ( V_52 -> V_53 ) ;
F_121 ( V_52 -> V_443 ,
! F_21 ( V_281 , & V_52 -> V_61 )
|| F_229 () ) ;
F_64 ( & V_3 -> V_62 ) ;
V_3 -> V_419 = V_52 -> V_94 ;
F_67 ( & V_3 -> V_62 ) ;
F_31 ( & V_3 -> V_233 ) ;
F_226 ( & V_52 -> V_437 , NULL , L_60 ) ;
}
return V_434 ;
}
static inline T_1 F_231 ( struct V_52 * V_52 , T_1 V_426 , int * V_427 , int V_446 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
struct V_21 * V_22 ;
T_1 V_447 = V_52 -> V_438 ;
T_1 V_448 ;
int V_449 = 0 ;
int V_70 ;
if ( V_426 >= V_447 ) {
if ( F_21 ( V_450 , & V_52 -> V_272 ) ) {
F_232 ( V_3 ) ;
return 0 ;
}
if ( V_52 -> V_451 < V_447 )
F_233 ( V_52 -> V_323 , V_52 -> V_451 ,
& V_448 , 1 ) ;
else
V_3 -> V_452 = 0 ;
F_234 ( V_52 -> V_323 ) ;
return 0 ;
}
F_121 ( V_3 -> V_233 , V_3 -> V_99 != 2 ) ;
if ( F_21 ( V_450 , & V_52 -> V_272 ) )
return F_224 ( V_52 , V_426 , V_427 ) ;
if ( V_52 -> V_87 >= V_3 -> V_96 &&
F_21 ( V_453 , & V_52 -> V_272 ) ) {
T_1 V_333 = V_52 -> V_438 - V_426 ;
* V_427 = 1 ;
return V_333 ;
}
if ( ! F_235 ( V_52 -> V_323 , V_426 , & V_448 , 1 ) &&
! F_21 ( V_368 , & V_52 -> V_272 ) &&
! V_3 -> V_452 && V_448 >= V_14 ) {
V_448 /= V_14 ;
* V_427 = 1 ;
return V_448 * V_14 ;
}
F_236 ( V_52 -> V_323 , V_426 ) ;
V_22 = F_63 ( V_3 , V_426 , 0 , 1 , 0 ) ;
if ( V_22 == NULL ) {
V_22 = F_63 ( V_3 , V_426 , 0 , 0 , 0 ) ;
F_237 ( 1 ) ;
}
for ( V_70 = 0 ; V_70 < V_3 -> V_27 ; V_70 ++ )
if ( V_3 -> V_25 [ V_70 ] . V_90 == NULL )
V_449 = 1 ;
F_235 ( V_52 -> V_323 , V_426 , & V_448 , V_449 ) ;
F_74 ( V_372 , & V_22 -> V_39 ) ;
F_183 ( V_22 ) ;
F_34 ( V_22 ) ;
return V_14 ;
}
static int F_238 ( struct V_2 * V_3 , struct V_9 * V_397 )
{
struct V_21 * V_22 ;
int V_284 ;
T_1 V_10 , V_410 , V_411 ;
int V_454 = 0 ;
int V_412 ;
int V_455 = 0 ;
V_410 = V_397 -> V_13 & ~ ( ( T_1 ) V_14 - 1 ) ;
V_10 = F_161 ( V_3 , V_410 ,
0 , & V_284 , NULL ) ;
V_411 = V_397 -> V_13 + ( V_397 -> V_12 >> 9 ) ;
for (; V_410 < V_411 ;
V_410 += V_14 ,
V_10 += V_14 ,
V_454 ++ ) {
if ( V_454 < F_3 ( V_397 ) )
continue;
V_22 = F_63 ( V_3 , V_10 , 0 , 1 , 0 ) ;
if ( ! V_22 ) {
F_9 ( V_397 , V_454 ) ;
V_3 -> V_59 = V_397 ;
return V_455 ;
}
if ( ! F_164 ( V_22 , V_397 , V_284 , 0 ) ) {
F_34 ( V_22 ) ;
F_9 ( V_397 , V_454 ) ;
V_3 -> V_59 = V_397 ;
return V_455 ;
}
F_74 ( V_145 , & V_22 -> V_73 [ V_284 ] . V_61 ) ;
F_183 ( V_22 ) ;
F_34 ( V_22 ) ;
V_455 ++ ;
}
V_412 = F_5 ( V_397 ) ;
if ( V_412 == 0 ) {
F_17 ( F_18 ( V_397 -> V_35 ) ,
V_397 , 0 ) ;
F_19 ( V_397 , 0 ) ;
}
if ( F_33 ( & V_3 -> V_395 ) )
F_31 ( & V_3 -> V_58 ) ;
return V_455 ;
}
static int F_239 ( struct V_2 * V_3 )
{
struct V_21 * V_456 [ V_457 ] , * V_22 ;
int V_70 , V_458 = 0 ;
while ( V_458 < V_457 &&
( V_22 = F_204 ( V_3 ) ) != NULL )
V_456 [ V_458 ++ ] = V_22 ;
if ( V_458 == 0 )
return V_458 ;
F_67 ( & V_3 -> V_62 ) ;
for ( V_70 = 0 ; V_70 < V_458 ; V_70 ++ )
F_183 ( V_456 [ V_70 ] ) ;
F_240 () ;
F_64 ( & V_3 -> V_62 ) ;
for ( V_70 = 0 ; V_70 < V_458 ; V_70 ++ )
F_32 ( V_3 , V_456 [ V_70 ] ) ;
return V_458 ;
}
static void F_241 ( struct V_459 * V_53 )
{
struct V_52 * V_52 = V_53 -> V_52 ;
struct V_2 * V_3 = V_52 -> V_278 ;
int V_455 ;
struct V_460 V_461 ;
F_40 ( L_61 ) ;
F_75 ( V_52 ) ;
F_242 ( & V_461 ) ;
V_455 = 0 ;
F_64 ( & V_3 -> V_62 ) ;
while ( 1 ) {
struct V_9 * V_9 ;
int V_458 ;
if (
! F_24 ( & V_3 -> V_50 ) ) {
V_3 -> V_324 ++ ;
F_67 ( & V_3 -> V_62 ) ;
F_243 ( V_52 -> V_323 ) ;
F_64 ( & V_3 -> V_62 ) ;
V_3 -> V_49 = V_3 -> V_324 ;
F_186 ( V_3 ) ;
}
F_185 ( V_3 ) ;
while ( ( V_9 = F_195 ( V_3 ) ) ) {
int V_462 ;
F_67 ( & V_3 -> V_62 ) ;
V_462 = F_238 ( V_3 , V_9 ) ;
F_64 ( & V_3 -> V_62 ) ;
if ( ! V_462 )
break;
V_455 ++ ;
}
V_458 = F_239 ( V_3 ) ;
if ( ! V_458 )
break;
V_455 += V_458 ;
if ( V_52 -> V_61 & ~ ( 1 << V_463 ) ) {
F_67 ( & V_3 -> V_62 ) ;
F_75 ( V_52 ) ;
F_64 ( & V_3 -> V_62 ) ;
}
}
F_40 ( L_62 , V_455 ) ;
F_67 ( & V_3 -> V_62 ) ;
F_244 () ;
F_245 ( & V_461 ) ;
F_40 ( L_63 ) ;
}
static T_6
F_246 ( struct V_52 * V_52 , char * V_68 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
if ( V_3 )
return sprintf ( V_68 , L_64 , V_3 -> V_101 ) ;
else
return 0 ;
}
int
F_247 ( struct V_52 * V_52 , int V_464 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
int V_251 ;
if ( V_464 <= 16 || V_464 > 32768 )
return - V_465 ;
while ( V_464 < V_3 -> V_101 ) {
if ( F_149 ( V_3 ) )
V_3 -> V_101 -- ;
else
break;
}
V_251 = F_138 ( V_52 ) ;
if ( V_251 )
return V_251 ;
while ( V_464 > V_3 -> V_101 ) {
if ( F_124 ( V_3 ) )
V_3 -> V_101 ++ ;
else break;
}
return 0 ;
}
static T_6
F_248 ( struct V_52 * V_52 , const char * V_68 , T_5 V_168 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
unsigned long V_20 ;
int V_251 ;
if ( V_168 >= V_466 )
return - V_465 ;
if ( ! V_3 )
return - V_467 ;
if ( F_249 ( V_68 , 10 , & V_20 ) )
return - V_465 ;
V_251 = F_247 ( V_52 , V_20 ) ;
if ( V_251 )
return V_251 ;
return V_168 ;
}
static T_6
F_250 ( struct V_52 * V_52 , char * V_68 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
if ( V_3 )
return sprintf ( V_68 , L_64 , V_3 -> V_403 ) ;
else
return 0 ;
}
static T_6
F_251 ( struct V_52 * V_52 , const char * V_68 , T_5 V_168 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
unsigned long V_20 ;
if ( V_168 >= V_466 )
return - V_465 ;
if ( ! V_3 )
return - V_467 ;
if ( F_249 ( V_68 , 10 , & V_20 ) )
return - V_465 ;
if ( V_20 > V_3 -> V_101 )
return - V_465 ;
V_3 -> V_403 = V_20 ;
return V_168 ;
}
static T_6
F_252 ( struct V_52 * V_52 , char * V_68 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
if ( V_3 )
return sprintf ( V_68 , L_64 , F_4 ( & V_3 -> V_42 ) ) ;
else
return 0 ;
}
static T_1
F_225 ( struct V_52 * V_52 , T_1 V_11 , int V_27 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
if ( ! V_11 )
V_11 = V_52 -> V_438 ;
if ( ! V_27 )
V_27 = F_253 ( V_3 -> V_27 , V_3 -> V_77 ) ;
V_11 &= ~ ( ( T_1 ) V_52 -> V_294 - 1 ) ;
V_11 &= ~ ( ( T_1 ) V_52 -> V_392 - 1 ) ;
return V_11 * ( V_27 - V_3 -> V_96 ) ;
}
static void F_254 ( struct V_2 * V_3 )
{
struct V_186 * V_187 ;
unsigned long V_222 ;
if ( ! V_3 -> V_187 )
return;
F_145 () ;
F_255 (cpu) {
V_187 = F_115 ( V_3 -> V_187 , V_222 ) ;
F_256 ( V_187 -> V_218 ) ;
F_144 ( V_187 -> V_188 ) ;
}
#ifdef F_257
F_258 ( & V_3 -> V_468 ) ;
#endif
F_148 () ;
F_259 ( V_3 -> V_187 ) ;
}
static void F_260 ( struct V_2 * V_3 )
{
F_150 ( V_3 ) ;
F_254 ( V_3 ) ;
F_144 ( V_3 -> V_25 ) ;
F_144 ( V_3 -> V_8 ) ;
F_144 ( V_3 ) ;
}
static int F_261 ( struct V_469 * V_470 , unsigned long V_471 ,
void * V_472 )
{
struct V_2 * V_3 = F_207 ( V_470 , struct V_2 , V_468 ) ;
long V_222 = ( long ) V_472 ;
struct V_186 * V_187 = F_115 ( V_3 -> V_187 , V_222 ) ;
switch ( V_471 ) {
case V_473 :
case V_474 :
if ( V_3 -> V_221 == 6 && ! V_187 -> V_218 )
V_187 -> V_218 = F_50 ( V_74 ) ;
if ( ! V_187 -> V_188 )
V_187 -> V_188 = F_147 ( V_3 -> F_135 , V_74 ) ;
if ( ! V_187 -> V_188 ||
( V_3 -> V_221 == 6 && ! V_187 -> V_218 ) ) {
F_256 ( V_187 -> V_218 ) ;
F_144 ( V_187 -> V_188 ) ;
F_262 ( L_65 ,
V_142 , V_222 ) ;
return F_263 ( - V_252 ) ;
}
break;
case V_475 :
case V_476 :
F_256 ( V_187 -> V_218 ) ;
F_144 ( V_187 -> V_188 ) ;
V_187 -> V_218 = NULL ;
V_187 -> V_188 = NULL ;
break;
default:
break;
}
return V_477 ;
}
static int F_264 ( struct V_2 * V_3 )
{
unsigned long V_222 ;
struct V_68 * V_218 ;
struct V_186 T_7 * V_478 ;
void * V_188 ;
int V_251 ;
V_478 = F_265 ( struct V_186 ) ;
if ( ! V_478 )
return - V_252 ;
V_3 -> V_187 = V_478 ;
F_145 () ;
V_251 = 0 ;
F_146 (cpu) {
if ( V_3 -> V_221 == 6 ) {
V_218 = F_50 ( V_74 ) ;
if ( ! V_218 ) {
V_251 = - V_252 ;
break;
}
F_115 ( V_3 -> V_187 , V_222 ) -> V_218 = V_218 ;
}
V_188 = F_147 ( V_3 -> F_135 , V_74 ) ;
if ( ! V_188 ) {
V_251 = - V_252 ;
break;
}
F_115 ( V_3 -> V_187 , V_222 ) -> V_188 = V_188 ;
}
#ifdef F_257
V_3 -> V_468 . V_479 = F_261 ;
V_3 -> V_468 . V_480 = 0 ;
if ( V_251 == 0 )
V_251 = F_266 ( & V_3 -> V_468 ) ;
#endif
F_148 () ;
return V_251 ;
}
static struct V_2 * F_267 ( struct V_52 * V_52 )
{
struct V_2 * V_3 ;
int V_481 , V_482 , V_483 ;
struct V_89 * V_90 ;
struct V_249 * V_26 ;
char V_484 [ 6 ] ;
if ( V_52 -> V_485 != 5
&& V_52 -> V_485 != 4
&& V_52 -> V_485 != 6 ) {
F_53 ( V_84 L_66 ,
F_133 ( V_52 ) , V_52 -> V_485 ) ;
return F_268 ( - V_486 ) ;
}
if ( ( V_52 -> V_485 == 5
&& ! F_269 ( V_52 -> V_487 ) ) ||
( V_52 -> V_485 == 6
&& ! F_270 ( V_52 -> V_487 ) ) ) {
F_53 ( V_84 L_67 ,
F_133 ( V_52 ) , V_52 -> V_487 ) ;
return F_268 ( - V_486 ) ;
}
if ( V_52 -> V_485 == 6 && V_52 -> V_27 < 4 ) {
F_53 ( V_84 L_68 ,
F_133 ( V_52 ) , V_52 -> V_27 ) ;
return F_268 ( - V_465 ) ;
}
if ( ! V_52 -> V_392 ||
( V_52 -> V_392 << 9 ) % V_466 ||
! F_271 ( V_52 -> V_392 ) ) {
F_53 ( V_84 L_69 ,
F_133 ( V_52 ) , V_52 -> V_392 << 9 ) ;
return F_268 ( - V_465 ) ;
}
V_3 = F_143 ( sizeof( struct V_2 ) , V_74 ) ;
if ( V_3 == NULL )
goto abort;
F_128 ( & V_3 -> V_62 ) ;
F_127 ( & V_3 -> V_58 ) ;
F_127 ( & V_3 -> V_233 ) ;
F_130 ( & V_3 -> V_51 ) ;
F_130 ( & V_3 -> V_381 ) ;
F_130 ( & V_3 -> V_46 ) ;
F_130 ( & V_3 -> V_50 ) ;
F_130 ( & V_3 -> V_57 ) ;
F_12 ( & V_3 -> V_42 , 0 ) ;
F_12 ( & V_3 -> V_54 , 0 ) ;
F_12 ( & V_3 -> V_395 , 0 ) ;
V_3 -> V_403 = V_488 ;
V_3 -> V_331 = V_52 -> V_331 - 1 ;
V_3 -> V_27 = V_52 -> V_27 ;
if ( V_52 -> V_94 == V_95 )
V_3 -> V_77 = V_52 -> V_27 ;
else
V_3 -> V_77 = V_52 -> V_27 - V_52 -> V_489 ;
V_483 = F_132 ( V_3 -> V_27 , V_3 -> V_77 ) ;
V_3 -> F_135 = F_135 ( V_483 ) ;
V_3 -> V_25 = F_143 ( V_483 * sizeof( struct V_249 ) ,
V_74 ) ;
if ( ! V_3 -> V_25 )
goto abort;
V_3 -> V_52 = V_52 ;
if ( ( V_3 -> V_8 = F_143 ( V_466 , V_74 ) ) == NULL )
goto abort;
V_3 -> V_221 = V_52 -> V_485 ;
if ( F_264 ( V_3 ) != 0 )
goto abort;
F_40 ( L_70 , F_133 ( V_52 ) ) ;
F_272 (rdev, mddev) {
V_481 = V_90 -> V_481 ;
if ( V_481 >= V_483
|| V_481 < 0 )
continue;
V_26 = V_3 -> V_25 + V_481 ;
if ( F_21 ( V_490 , & V_90 -> V_61 ) ) {
if ( V_26 -> V_92 )
goto abort;
V_26 -> V_92 = V_90 ;
} else {
if ( V_26 -> V_90 )
goto abort;
V_26 -> V_90 = V_90 ;
}
if ( F_21 ( V_93 , & V_90 -> V_61 ) ) {
char V_256 [ V_257 ] ;
F_53 ( V_259 L_71
L_72 ,
F_133 ( V_52 ) , F_152 ( V_90 -> V_140 , V_256 ) , V_481 ) ;
} else if ( V_90 -> V_491 != V_481 )
V_3 -> V_452 = 1 ;
}
V_3 -> V_294 = V_52 -> V_392 ;
V_3 -> V_221 = V_52 -> V_485 ;
if ( V_3 -> V_221 == 6 )
V_3 -> V_96 = 2 ;
else
V_3 -> V_96 = 1 ;
V_3 -> V_290 = V_52 -> V_487 ;
V_3 -> V_101 = V_492 ;
V_3 -> V_104 = V_52 -> V_94 ;
if ( V_3 -> V_104 != V_95 ) {
V_3 -> V_293 = V_52 -> V_294 ;
V_3 -> V_291 = V_52 -> V_493 ;
}
V_482 = V_3 -> V_101 * ( sizeof( struct V_21 ) +
V_483 * ( ( sizeof( struct V_9 ) + V_466 ) ) ) / 1024 ;
if ( F_131 ( V_3 , V_3 -> V_101 ) ) {
F_53 ( V_84
L_73 ,
F_133 ( V_52 ) , V_482 ) ;
goto abort;
} else
F_53 ( V_259 L_74 ,
F_133 ( V_52 ) , V_482 ) ;
sprintf ( V_484 , L_75 , V_52 -> V_485 ) ;
V_3 -> V_53 = F_273 ( F_241 , V_52 , V_484 ) ;
if ( ! V_3 -> V_53 ) {
F_53 ( V_84
L_76 ,
F_133 ( V_52 ) ) ;
goto abort;
}
return V_3 ;
abort:
if ( V_3 ) {
F_260 ( V_3 ) ;
return F_268 ( - V_486 ) ;
} else
return F_268 ( - V_252 ) ;
}
static int F_274 ( int V_481 , int V_494 , int V_27 , int V_96 )
{
switch ( V_494 ) {
case V_300 :
if ( V_481 < V_96 )
return 1 ;
break;
case V_301 :
if ( V_481 >= V_27 - V_96 )
return 1 ;
break;
case V_309 :
if ( V_481 == 0 ||
V_481 == V_27 - 1 )
return 1 ;
break;
case V_305 :
case V_306 :
case V_307 :
case V_308 :
if ( V_481 == V_27 - 1 )
return 1 ;
}
return 0 ;
}
static int F_275 ( struct V_52 * V_52 )
{
struct V_2 * V_3 ;
int V_495 = 0 ;
int V_496 = 0 ;
struct V_89 * V_90 ;
T_1 V_497 = 0 ;
int V_70 ;
long long V_439 = 0 ;
int V_65 = 1 ;
if ( V_52 -> V_335 != V_95 )
F_53 ( V_498 L_77
L_78 ,
F_133 ( V_52 ) ) ;
F_272 (rdev, mddev) {
long long V_499 ;
if ( V_90 -> V_481 < 0 )
continue;
V_499 = ( V_90 -> V_143 - V_90 -> V_144 ) ;
if ( V_65 ) {
V_439 = V_499 ;
V_65 = 0 ;
} else if ( V_52 -> V_418 &&
V_499 < V_439 )
V_439 = V_499 ;
else if ( ! V_52 -> V_418 &&
V_499 > V_439 )
V_439 = V_499 ;
}
if ( V_52 -> V_94 != V_95 ) {
T_1 V_500 , V_501 ;
int V_502 ;
int V_96 = ( V_52 -> V_221 == 6 ? 2 : 1 ) ;
if ( V_52 -> V_485 != V_52 -> V_221 ) {
F_53 ( V_84 L_79
L_80 ,
F_133 ( V_52 ) ) ;
return - V_465 ;
}
V_502 = V_52 -> V_27 - V_52 -> V_489 ;
V_500 = V_52 -> V_94 ;
if ( F_162 ( V_500 , V_52 -> V_392 *
( V_52 -> V_27 - V_96 ) ) ) {
F_53 ( V_84 L_81
L_82 , F_133 ( V_52 ) ) ;
return - V_465 ;
}
V_497 = V_500 * V_52 -> V_392 ;
V_501 = V_52 -> V_94 ;
F_162 ( V_501 , V_52 -> V_294 *
( V_502 - V_96 ) ) ;
if ( V_52 -> V_489 == 0 ) {
if ( ( V_500 * V_52 -> V_392 !=
V_501 * V_52 -> V_294 ) ) {
F_53 ( V_84 L_83
L_84 , F_133 ( V_52 ) ) ;
return - V_465 ;
}
if ( abs ( V_439 ) >= V_52 -> V_294 &&
abs ( V_439 ) >= V_52 -> V_392 )
;
else if ( V_52 -> V_377 == 0 ) {
F_53 ( V_84 L_85
L_86
L_87 ,
F_133 ( V_52 ) ) ;
return - V_465 ;
}
} else if ( V_52 -> V_418
? ( V_500 * V_52 -> V_392 + V_439 <=
V_501 * V_52 -> V_294 )
: ( V_500 * V_52 -> V_392 >=
V_501 * V_52 -> V_294 + ( - V_439 ) ) ) {
F_53 ( V_84 L_88
L_89 ,
F_133 ( V_52 ) ) ;
return - V_465 ;
}
F_53 ( V_259 L_90 ,
F_133 ( V_52 ) ) ;
} else {
F_23 ( V_52 -> V_221 != V_52 -> V_485 ) ;
F_23 ( V_52 -> V_493 != V_52 -> V_487 ) ;
F_23 ( V_52 -> V_294 != V_52 -> V_392 ) ;
F_23 ( V_52 -> V_489 != 0 ) ;
}
if ( V_52 -> V_278 == NULL )
V_3 = F_267 ( V_52 ) ;
else
V_3 = V_52 -> V_278 ;
if ( F_276 ( V_3 ) )
return F_277 ( V_3 ) ;
V_3 -> V_439 = V_439 ;
V_52 -> V_53 = V_3 -> V_53 ;
V_3 -> V_53 = NULL ;
V_52 -> V_278 = V_3 ;
for ( V_70 = 0 ; V_70 < V_3 -> V_27 && V_3 -> V_77 ;
V_70 ++ ) {
V_90 = V_3 -> V_25 [ V_70 ] . V_90 ;
if ( ! V_90 && V_3 -> V_25 [ V_70 ] . V_92 ) {
V_90 = V_3 -> V_25 [ V_70 ] . V_92 ;
V_3 -> V_25 [ V_70 ] . V_92 = NULL ;
F_26 ( V_490 , & V_90 -> V_61 ) ;
V_3 -> V_25 [ V_70 ] . V_90 = V_90 ;
}
if ( ! V_90 )
continue;
if ( V_3 -> V_25 [ V_70 ] . V_92 &&
V_3 -> V_104 != V_95 ) {
F_53 ( V_84 L_91
L_92 ) ;
goto abort;
}
if ( F_21 ( V_93 , & V_90 -> V_61 ) ) {
V_495 ++ ;
continue;
}
if ( V_52 -> V_503 == 0 &&
V_52 -> V_504 > 90 )
V_90 -> V_334 = V_497 ;
if ( V_90 -> V_334 < V_497 ) {
if ( ! F_274 ( V_90 -> V_481 ,
V_3 -> V_290 ,
V_3 -> V_27 ,
V_3 -> V_96 ) )
continue;
}
if ( ! F_274 ( V_90 -> V_481 ,
V_3 -> V_291 ,
V_3 -> V_77 ,
V_3 -> V_96 ) )
continue;
V_496 ++ ;
}
V_52 -> V_87 = F_58 ( V_3 ) ;
if ( F_62 ( V_3 ) ) {
F_53 ( V_84 L_93
L_94 ,
F_133 ( V_52 ) , V_52 -> V_87 , V_3 -> V_27 ) ;
goto abort;
}
V_52 -> V_438 &= ~ ( V_52 -> V_294 - 1 ) ;
V_52 -> V_505 = V_52 -> V_438 ;
if ( V_52 -> V_87 > V_496 &&
V_52 -> V_335 != V_95 ) {
if ( V_52 -> V_506 )
F_53 ( V_266
L_95
L_96 ,
F_133 ( V_52 ) ) ;
else {
F_53 ( V_84
L_97 ,
F_133 ( V_52 ) ) ;
goto abort;
}
}
if ( V_52 -> V_87 == 0 )
F_53 ( V_259 L_98
L_99 , F_133 ( V_52 ) , V_3 -> V_221 ,
V_52 -> V_27 - V_52 -> V_87 , V_52 -> V_27 ,
V_52 -> V_487 ) ;
else
F_53 ( V_282 L_100
L_101 ,
F_133 ( V_52 ) , V_3 -> V_221 ,
V_52 -> V_27 - V_52 -> V_87 ,
V_52 -> V_27 , V_52 -> V_487 ) ;
F_278 ( V_3 ) ;
if ( V_3 -> V_104 != V_95 ) {
V_3 -> V_419 = V_3 -> V_104 ;
F_12 ( & V_3 -> V_379 , 0 ) ;
F_26 ( V_453 , & V_52 -> V_272 ) ;
F_26 ( V_350 , & V_52 -> V_272 ) ;
F_74 ( V_450 , & V_52 -> V_272 ) ;
F_74 ( V_507 , & V_52 -> V_272 ) ;
V_52 -> V_508 = F_273 ( V_509 , V_52 ,
L_102 ) ;
}
if ( V_52 -> V_510 == & V_511 )
V_52 -> V_510 = NULL ;
else if ( V_52 -> V_437 . V_512 &&
F_279 ( & V_52 -> V_437 , & V_511 ) )
F_53 ( V_266
L_103 ,
F_133 ( V_52 ) ) ;
F_280 ( V_52 , F_225 ( V_52 , 0 , 0 ) ) ;
if ( V_52 -> V_344 ) {
int V_513 ;
bool V_514 = true ;
int V_295 = V_3 -> V_77 - V_3 -> V_96 ;
int V_285 = V_295 *
( ( V_52 -> V_294 << 9 ) / V_466 ) ;
if ( V_52 -> V_344 -> V_515 . V_516 < 2 * V_285 )
V_52 -> V_344 -> V_515 . V_516 = 2 * V_285 ;
F_281 ( V_52 -> V_344 , F_191 ) ;
V_52 -> V_344 -> V_515 . V_517 = V_52 ;
V_52 -> V_344 -> V_515 . V_518 = F_189 ;
V_513 = V_52 -> V_294 << 9 ;
F_282 ( V_52 -> V_344 , V_513 ) ;
F_283 ( V_52 -> V_344 , V_513 *
( V_3 -> V_27 - V_3 -> V_96 ) ) ;
V_285 = V_285 * V_466 ;
while ( ( V_285 - 1 ) & V_285 )
V_285 = ( V_285 | ( V_285 - 1 ) ) + 1 ;
V_52 -> V_344 -> V_519 . V_520 = V_285 ;
V_52 -> V_344 -> V_519 . V_521 = V_285 ;
V_52 -> V_344 -> V_519 . V_522 = 0 ;
F_272 (rdev, mddev) {
F_284 ( V_52 -> V_155 , V_90 -> V_140 ,
V_90 -> V_144 << 9 ) ;
F_284 ( V_52 -> V_155 , V_90 -> V_140 ,
V_90 -> V_143 << 9 ) ;
if ( ! F_285 ( F_18 ( V_90 -> V_140 ) ) ||
! F_18 ( V_90 -> V_140 ) ->
V_519 . V_522 )
V_514 = false ;
}
if ( V_514 &&
V_52 -> V_344 -> V_519 . V_523 >= V_285 &&
V_52 -> V_344 -> V_519 . V_521 >= V_285 )
F_286 ( V_524 ,
V_52 -> V_344 ) ;
else
F_287 ( V_524 ,
V_52 -> V_344 ) ;
}
return 0 ;
abort:
F_288 ( & V_52 -> V_53 ) ;
F_278 ( V_3 ) ;
F_260 ( V_3 ) ;
V_52 -> V_278 = NULL ;
F_53 ( V_282 L_104 , F_133 ( V_52 ) ) ;
return - V_486 ;
}
static int F_289 ( struct V_52 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
F_288 ( & V_52 -> V_53 ) ;
if ( V_52 -> V_344 )
V_52 -> V_344 -> V_515 . V_518 = NULL ;
F_260 ( V_3 ) ;
V_52 -> V_278 = NULL ;
V_52 -> V_510 = & V_511 ;
return 0 ;
}
static void F_290 ( struct V_525 * V_526 , struct V_52 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
int V_70 ;
F_291 ( V_526 , L_105 , V_52 -> V_221 ,
V_52 -> V_294 / 2 , V_52 -> V_493 ) ;
F_291 ( V_526 , L_106 , V_3 -> V_27 , V_3 -> V_27 - V_52 -> V_87 ) ;
for ( V_70 = 0 ; V_70 < V_3 -> V_27 ; V_70 ++ )
F_291 ( V_526 , L_107 ,
V_3 -> V_25 [ V_70 ] . V_90 &&
F_21 ( V_93 , & V_3 -> V_25 [ V_70 ] . V_90 -> V_61 ) ? L_108 : L_109 ) ;
F_291 ( V_526 , L_110 ) ;
}
static void F_278 ( struct V_2 * V_3 )
{
int V_70 ;
struct V_249 * V_527 ;
F_53 ( V_528 L_111 ) ;
if ( ! V_3 ) {
F_53 ( L_112 ) ;
return;
}
F_53 ( V_528 L_113 , V_3 -> V_221 ,
V_3 -> V_27 ,
V_3 -> V_27 - V_3 -> V_52 -> V_87 ) ;
for ( V_70 = 0 ; V_70 < V_3 -> V_27 ; V_70 ++ ) {
char V_256 [ V_257 ] ;
V_527 = V_3 -> V_25 + V_70 ;
if ( V_527 -> V_90 )
F_53 ( V_528 L_114 ,
V_70 , ! F_21 ( V_91 , & V_527 -> V_90 -> V_61 ) ,
F_152 ( V_527 -> V_90 -> V_140 , V_256 ) ) ;
}
}
static int F_292 ( struct V_52 * V_52 )
{
int V_70 ;
struct V_2 * V_3 = V_52 -> V_278 ;
struct V_249 * V_527 ;
int V_29 = 0 ;
unsigned long V_61 ;
for ( V_70 = 0 ; V_70 < V_3 -> V_27 ; V_70 ++ ) {
V_527 = V_3 -> V_25 + V_70 ;
if ( V_527 -> V_92
&& V_527 -> V_92 -> V_334 == V_95
&& ! F_21 ( V_91 , & V_527 -> V_92 -> V_61 )
&& ! F_156 ( V_93 , & V_527 -> V_92 -> V_61 ) ) {
if ( ! V_527 -> V_90
|| ! F_28 ( V_93 , & V_527 -> V_90 -> V_61 ) )
V_29 ++ ;
if ( V_527 -> V_90 ) {
F_74 ( V_91 , & V_527 -> V_90 -> V_61 ) ;
F_293 (
V_527 -> V_90 -> V_529 ) ;
}
F_293 ( V_527 -> V_92 -> V_529 ) ;
} else if ( V_527 -> V_90
&& V_527 -> V_90 -> V_334 == V_95
&& ! F_21 ( V_91 , & V_527 -> V_90 -> V_61 )
&& ! F_156 ( V_93 , & V_527 -> V_90 -> V_61 ) ) {
V_29 ++ ;
F_293 ( V_527 -> V_90 -> V_529 ) ;
}
}
F_159 ( & V_3 -> V_62 , V_61 ) ;
V_52 -> V_87 = F_58 ( V_3 ) ;
F_160 ( & V_3 -> V_62 , V_61 ) ;
F_278 ( V_3 ) ;
return V_29 ;
}
static int F_294 ( struct V_52 * V_52 , struct V_89 * V_90 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
int V_251 = 0 ;
int V_530 = V_90 -> V_481 ;
struct V_89 * * V_531 ;
struct V_249 * V_69 = V_3 -> V_25 + V_530 ;
F_278 ( V_3 ) ;
if ( V_90 == V_69 -> V_90 )
V_531 = & V_69 -> V_90 ;
else if ( V_90 == V_69 -> V_92 )
V_531 = & V_69 -> V_92 ;
else
return 0 ;
if ( V_530 >= V_3 -> V_27 &&
V_3 -> V_104 == V_95 )
F_26 ( V_93 , & V_90 -> V_61 ) ;
if ( F_21 ( V_93 , & V_90 -> V_61 ) ||
F_4 ( & V_90 -> V_129 ) ) {
V_251 = - V_532 ;
goto abort;
}
if ( ! F_21 ( V_91 , & V_90 -> V_61 ) &&
V_52 -> V_331 != V_3 -> V_331 &&
! F_62 ( V_3 ) &&
( ! V_69 -> V_92 || V_69 -> V_92 == V_90 ) &&
V_530 < V_3 -> V_27 ) {
V_251 = - V_532 ;
goto abort;
}
* V_531 = NULL ;
F_295 () ;
if ( F_4 ( & V_90 -> V_129 ) ) {
V_251 = - V_532 ;
* V_531 = V_90 ;
} else if ( V_69 -> V_92 ) {
V_69 -> V_90 = V_69 -> V_92 ;
F_26 ( V_490 , & V_69 -> V_92 -> V_61 ) ;
F_72 () ;
V_69 -> V_92 = NULL ;
F_26 ( V_270 , & V_90 -> V_61 ) ;
} else
F_26 ( V_270 , & V_90 -> V_61 ) ;
abort:
F_278 ( V_3 ) ;
return V_251 ;
}
static int F_296 ( struct V_52 * V_52 , struct V_89 * V_90 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
int V_251 = - V_533 ;
int V_26 ;
struct V_249 * V_69 ;
int V_65 = 0 ;
int V_534 = V_3 -> V_27 - 1 ;
if ( V_52 -> V_331 == V_3 -> V_331 )
return - V_532 ;
if ( V_90 -> V_491 < 0 && F_62 ( V_3 ) )
return - V_465 ;
if ( V_90 -> V_481 >= 0 )
V_65 = V_534 = V_90 -> V_481 ;
if ( V_90 -> V_491 >= 0 &&
V_90 -> V_491 >= V_65 &&
V_3 -> V_25 [ V_90 -> V_491 ] . V_90 == NULL )
V_65 = V_90 -> V_491 ;
for ( V_26 = V_65 ; V_26 <= V_534 ; V_26 ++ ) {
V_69 = V_3 -> V_25 + V_26 ;
if ( V_69 -> V_90 == NULL ) {
F_26 ( V_93 , & V_90 -> V_61 ) ;
V_90 -> V_481 = V_26 ;
V_251 = 0 ;
if ( V_90 -> V_491 != V_26 )
V_3 -> V_452 = 1 ;
F_297 ( V_69 -> V_90 , V_90 ) ;
goto V_66;
}
}
for ( V_26 = V_65 ; V_26 <= V_534 ; V_26 ++ ) {
V_69 = V_3 -> V_25 + V_26 ;
if ( F_21 ( V_270 , & V_69 -> V_90 -> V_61 ) &&
V_69 -> V_92 == NULL ) {
F_26 ( V_93 , & V_90 -> V_61 ) ;
F_74 ( V_490 , & V_90 -> V_61 ) ;
V_90 -> V_481 = V_26 ;
V_251 = 0 ;
V_3 -> V_452 = 1 ;
F_297 ( V_69 -> V_92 , V_90 ) ;
break;
}
}
V_66:
F_278 ( V_3 ) ;
return V_251 ;
}
static int F_298 ( struct V_52 * V_52 , T_1 V_11 )
{
T_1 V_245 ;
V_11 &= ~ ( ( T_1 ) V_52 -> V_294 - 1 ) ;
V_245 = F_225 ( V_52 , V_11 , V_52 -> V_27 ) ;
if ( V_52 -> V_535 &&
V_52 -> V_536 > V_245 )
return - V_465 ;
if ( V_52 -> V_323 ) {
int V_537 = F_299 ( V_52 -> V_323 , V_11 , 0 , 0 ) ;
if ( V_537 )
return V_537 ;
}
F_280 ( V_52 , V_245 ) ;
F_300 ( V_52 -> V_155 , V_52 -> V_536 ) ;
F_301 ( V_52 -> V_155 ) ;
if ( V_11 > V_52 -> V_438 &&
V_52 -> V_335 > V_52 -> V_438 ) {
V_52 -> V_335 = V_52 -> V_438 ;
F_74 ( V_271 , & V_52 -> V_272 ) ;
}
V_52 -> V_438 = V_11 ;
V_52 -> V_505 = V_11 ;
return 0 ;
}
static int F_302 ( struct V_52 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
if ( ( ( V_52 -> V_294 << 9 ) / V_152 ) * 4
> V_3 -> V_101 ||
( ( V_52 -> V_392 << 9 ) / V_152 ) * 4
> V_3 -> V_101 ) {
F_53 ( V_266 L_115 ,
F_133 ( V_52 ) ,
( ( F_132 ( V_52 -> V_294 , V_52 -> V_392 ) << 9 )
/ V_152 ) * 4 ) ;
return 0 ;
}
return 1 ;
}
static int F_303 ( struct V_52 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
if ( V_52 -> V_489 == 0 &&
V_52 -> V_487 == V_52 -> V_493 &&
V_52 -> V_392 == V_52 -> V_294 )
return 0 ;
if ( F_62 ( V_3 ) )
return - V_465 ;
if ( V_52 -> V_489 < 0 ) {
int F_253 = 2 ;
if ( V_52 -> V_221 == 6 )
F_253 = 4 ;
if ( V_52 -> V_27 + V_52 -> V_489 < F_253 )
return - V_465 ;
}
if ( ! F_302 ( V_52 ) )
return - V_538 ;
return F_136 ( V_3 , ( V_3 -> V_77
+ V_52 -> V_489 ) ) ;
}
static int F_304 ( struct V_52 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
struct V_89 * V_90 ;
int V_539 = 0 ;
unsigned long V_61 ;
if ( F_21 ( V_507 , & V_52 -> V_272 ) )
return - V_532 ;
if ( ! F_302 ( V_52 ) )
return - V_538 ;
if ( F_62 ( V_3 ) )
return - V_465 ;
F_272 (rdev, mddev) {
if ( ! F_21 ( V_93 , & V_90 -> V_61 )
&& ! F_21 ( V_91 , & V_90 -> V_61 ) )
V_539 ++ ;
}
if ( V_539 - V_52 -> V_87 < V_52 -> V_489 - V_3 -> V_96 )
return - V_465 ;
if ( F_225 ( V_52 , 0 , V_3 -> V_27 + V_52 -> V_489 )
< V_52 -> V_536 ) {
F_53 ( V_84 L_116
L_117 , F_133 ( V_52 ) ) ;
return - V_465 ;
}
F_12 ( & V_3 -> V_379 , 0 ) ;
F_64 ( & V_3 -> V_62 ) ;
V_3 -> V_77 = V_3 -> V_27 ;
V_3 -> V_27 += V_52 -> V_489 ;
V_3 -> V_293 = V_3 -> V_294 ;
V_3 -> V_294 = V_52 -> V_392 ;
V_3 -> V_291 = V_3 -> V_290 ;
V_3 -> V_290 = V_52 -> V_487 ;
V_3 -> V_76 ++ ;
F_72 () ;
if ( V_52 -> V_418 )
V_3 -> V_104 = F_225 ( V_52 , 0 , 0 ) ;
else
V_3 -> V_104 = 0 ;
V_3 -> V_419 = V_3 -> V_104 ;
F_67 ( & V_3 -> V_62 ) ;
if ( V_52 -> V_489 >= 0 ) {
F_272 (rdev, mddev)
if ( V_90 -> V_481 < 0 &&
! F_21 ( V_91 , & V_90 -> V_61 ) ) {
if ( F_296 ( V_52 , V_90 ) == 0 ) {
if ( V_90 -> V_481
>= V_3 -> V_77 )
F_74 ( V_93 , & V_90 -> V_61 ) ;
else
V_90 -> V_334 = 0 ;
if ( F_305 ( V_52 , V_90 ) )
;
}
} else if ( V_90 -> V_481 >= V_3 -> V_77
&& ! F_21 ( V_91 , & V_90 -> V_61 ) ) {
F_74 ( V_93 , & V_90 -> V_61 ) ;
}
F_159 ( & V_3 -> V_62 , V_61 ) ;
V_52 -> V_87 = F_58 ( V_3 ) ;
F_160 ( & V_3 -> V_62 , V_61 ) ;
}
V_52 -> V_27 = V_3 -> V_27 ;
V_52 -> V_94 = V_3 -> V_104 ;
F_74 ( V_281 , & V_52 -> V_61 ) ;
F_26 ( V_453 , & V_52 -> V_272 ) ;
F_26 ( V_350 , & V_52 -> V_272 ) ;
F_74 ( V_450 , & V_52 -> V_272 ) ;
F_74 ( V_507 , & V_52 -> V_272 ) ;
V_52 -> V_508 = F_273 ( V_509 , V_52 ,
L_102 ) ;
if ( ! V_52 -> V_508 ) {
V_52 -> V_272 = 0 ;
F_64 ( & V_3 -> V_62 ) ;
V_52 -> V_27 = V_3 -> V_27 = V_3 -> V_77 ;
F_272 (rdev, mddev)
V_90 -> V_143 = V_90 -> V_144 ;
F_306 () ;
V_3 -> V_104 = V_95 ;
V_52 -> V_94 = V_95 ;
F_67 ( & V_3 -> V_62 ) ;
return - V_540 ;
}
V_3 -> V_441 = V_440 ;
F_27 ( V_52 -> V_508 ) ;
F_307 ( V_52 ) ;
return 0 ;
}
static void F_232 ( struct V_2 * V_3 )
{
if ( ! F_21 ( V_279 , & V_3 -> V_52 -> V_272 ) ) {
struct V_89 * V_90 ;
F_64 ( & V_3 -> V_62 ) ;
V_3 -> V_77 = V_3 -> V_27 ;
F_272 (rdev, conf->mddev)
V_90 -> V_144 = V_90 -> V_143 ;
F_306 () ;
V_3 -> V_104 = V_95 ;
F_67 ( & V_3 -> V_62 ) ;
F_31 ( & V_3 -> V_233 ) ;
if ( V_3 -> V_52 -> V_344 ) {
int V_295 = V_3 -> V_27 - V_3 -> V_96 ;
int V_285 = V_295 * ( ( V_3 -> V_294 << 9 )
/ V_466 ) ;
if ( V_3 -> V_52 -> V_344 -> V_515 . V_516 < 2 * V_285 )
V_3 -> V_52 -> V_344 -> V_515 . V_516 = 2 * V_285 ;
}
}
}
static void F_308 ( struct V_52 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
if ( ! F_21 ( V_279 , & V_52 -> V_272 ) ) {
if ( V_52 -> V_489 > 0 ) {
F_280 ( V_52 , F_225 ( V_52 , 0 , 0 ) ) ;
F_300 ( V_52 -> V_155 , V_52 -> V_536 ) ;
F_301 ( V_52 -> V_155 ) ;
} else {
int V_415 ;
F_64 ( & V_3 -> V_62 ) ;
V_52 -> V_87 = F_58 ( V_3 ) ;
F_67 ( & V_3 -> V_62 ) ;
for ( V_415 = V_3 -> V_27 ;
V_415 < V_3 -> V_27 - V_52 -> V_489 ;
V_415 ++ ) {
struct V_89 * V_90 = V_3 -> V_25 [ V_415 ] . V_90 ;
if ( V_90 )
F_26 ( V_93 , & V_90 -> V_61 ) ;
V_90 = V_3 -> V_25 [ V_415 ] . V_92 ;
if ( V_90 )
F_26 ( V_93 , & V_90 -> V_61 ) ;
}
}
V_52 -> V_493 = V_3 -> V_290 ;
V_52 -> V_294 = V_3 -> V_294 ;
V_52 -> V_94 = V_95 ;
V_52 -> V_489 = 0 ;
V_52 -> V_418 = 0 ;
}
}
static void F_309 ( struct V_52 * V_52 , int V_39 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
switch( V_39 ) {
case 2 :
F_31 ( & V_3 -> V_233 ) ;
break;
case 1 :
F_64 ( & V_3 -> V_62 ) ;
V_3 -> V_99 = 2 ;
F_65 ( V_3 -> V_58 ,
F_4 ( & V_3 -> V_42 ) == 0 &&
F_4 ( & V_3 -> V_395 ) == 0 ,
V_3 -> V_62 ) ;
V_3 -> V_99 = 1 ;
F_67 ( & V_3 -> V_62 ) ;
F_31 ( & V_3 -> V_233 ) ;
break;
case 0 :
F_64 ( & V_3 -> V_62 ) ;
V_3 -> V_99 = 0 ;
F_31 ( & V_3 -> V_58 ) ;
F_31 ( & V_3 -> V_233 ) ;
F_67 ( & V_3 -> V_62 ) ;
break;
}
}
static void * F_310 ( struct V_52 * V_52 , int V_221 )
{
struct V_541 * V_542 = V_52 -> V_278 ;
T_1 V_11 ;
if ( V_542 -> V_543 > 1 ) {
F_53 ( V_84 L_118 ,
F_133 ( V_52 ) ) ;
return F_268 ( - V_465 ) ;
}
V_11 = V_542 -> V_544 [ 0 ] . V_545 ;
F_162 ( V_11 , V_542 -> V_544 [ 0 ] . V_546 ) ;
V_52 -> V_438 = V_11 ;
V_52 -> V_485 = V_221 ;
V_52 -> V_487 = V_301 ;
V_52 -> V_392 = V_52 -> V_294 ;
V_52 -> V_27 += 1 ;
V_52 -> V_489 = 1 ;
V_52 -> V_335 = V_95 ;
return F_267 ( V_52 ) ;
}
static void * F_311 ( struct V_52 * V_52 )
{
int V_547 ;
if ( V_52 -> V_27 != 2 ||
V_52 -> V_87 > 1 )
return F_268 ( - V_465 ) ;
V_547 = 64 * 2 ;
while ( V_547 && ( V_52 -> V_536 & ( V_547 - 1 ) ) )
V_547 >>= 1 ;
if ( ( V_547 << 9 ) < V_152 )
return F_268 ( - V_465 ) ;
V_52 -> V_485 = 5 ;
V_52 -> V_487 = V_298 ;
V_52 -> V_392 = V_547 ;
return F_267 ( V_52 ) ;
}
static void * F_312 ( struct V_52 * V_52 )
{
int V_487 ;
switch ( V_52 -> V_493 ) {
case V_305 :
V_487 = V_296 ;
break;
case V_306 :
V_487 = V_297 ;
break;
case V_307 :
V_487 = V_298 ;
break;
case V_308 :
V_487 = V_299 ;
break;
case V_309 :
V_487 = V_300 ;
break;
case V_301 :
V_487 = V_301 ;
break;
default:
return F_268 ( - V_465 ) ;
}
V_52 -> V_485 = 5 ;
V_52 -> V_487 = V_487 ;
V_52 -> V_489 = - 1 ;
V_52 -> V_27 -= 1 ;
return F_267 ( V_52 ) ;
}
static int F_313 ( struct V_52 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_278 ;
int V_548 = V_52 -> V_392 ;
if ( V_52 -> V_487 >= 0 && ! F_269 ( V_52 -> V_487 ) )
return - V_465 ;
if ( V_548 > 0 ) {
if ( ! F_271 ( V_548 ) )
return - V_465 ;
if ( V_548 < ( V_466 >> 9 ) )
return - V_465 ;
if ( V_52 -> V_536 & ( V_548 - 1 ) )
return - V_465 ;
}
if ( V_52 -> V_27 == 2 ) {
if ( V_52 -> V_487 >= 0 ) {
V_3 -> V_290 = V_52 -> V_487 ;
V_52 -> V_493 = V_52 -> V_487 ;
}
if ( V_548 > 0 ) {
V_3 -> V_294 = V_548 ;
V_52 -> V_294 = V_548 ;
}
F_74 ( V_281 , & V_52 -> V_61 ) ;
F_27 ( V_52 -> V_53 ) ;
}
return F_303 ( V_52 ) ;
}
static int F_314 ( struct V_52 * V_52 )
{
int V_548 = V_52 -> V_392 ;
if ( V_52 -> V_487 >= 0 && ! F_270 ( V_52 -> V_487 ) )
return - V_465 ;
if ( V_548 > 0 ) {
if ( ! F_271 ( V_548 ) )
return - V_465 ;
if ( V_548 < ( V_466 >> 9 ) )
return - V_465 ;
if ( V_52 -> V_536 & ( V_548 - 1 ) )
return - V_465 ;
}
return F_303 ( V_52 ) ;
}
static void * F_315 ( struct V_52 * V_52 )
{
if ( V_52 -> V_221 == 0 )
return F_310 ( V_52 , 5 ) ;
if ( V_52 -> V_221 == 1 )
return F_311 ( V_52 ) ;
if ( V_52 -> V_221 == 4 ) {
V_52 -> V_487 = V_301 ;
V_52 -> V_485 = 5 ;
return F_267 ( V_52 ) ;
}
if ( V_52 -> V_221 == 6 )
return F_312 ( V_52 ) ;
return F_268 ( - V_465 ) ;
}
static void * F_316 ( struct V_52 * V_52 )
{
if ( V_52 -> V_221 == 0 )
return F_310 ( V_52 , 4 ) ;
if ( V_52 -> V_221 == 5 &&
V_52 -> V_493 == V_301 ) {
V_52 -> V_487 = 0 ;
V_52 -> V_485 = 4 ;
return F_267 ( V_52 ) ;
}
return F_268 ( - V_465 ) ;
}
static void * F_317 ( struct V_52 * V_52 )
{
int V_487 ;
if ( V_52 -> V_549 != & V_550 )
return F_268 ( - V_465 ) ;
if ( V_52 -> V_87 > 1 )
return F_268 ( - V_465 ) ;
if ( V_52 -> V_27 > 253 )
return F_268 ( - V_465 ) ;
if ( V_52 -> V_27 < 3 )
return F_268 ( - V_465 ) ;
switch ( V_52 -> V_493 ) {
case V_296 :
V_487 = V_305 ;
break;
case V_297 :
V_487 = V_306 ;
break;
case V_298 :
V_487 = V_307 ;
break;
case V_299 :
V_487 = V_308 ;
break;
case V_300 :
V_487 = V_309 ;
break;
case V_301 :
V_487 = V_301 ;
break;
default:
return F_268 ( - V_465 ) ;
}
V_52 -> V_485 = 6 ;
V_52 -> V_487 = V_487 ;
V_52 -> V_489 = 1 ;
V_52 -> V_27 += 1 ;
return F_267 ( V_52 ) ;
}
static int T_8 F_318 ( void )
{
F_319 ( & V_551 ) ;
F_319 ( & V_550 ) ;
F_319 ( & V_552 ) ;
return 0 ;
}
static void F_320 ( void )
{
F_321 ( & V_551 ) ;
F_321 ( & V_550 ) ;
F_321 ( & V_552 ) ;
}
