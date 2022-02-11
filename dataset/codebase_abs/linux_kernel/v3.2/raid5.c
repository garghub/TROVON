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
int V_84 ;
int V_67 ;
if ( V_3 -> V_48 -> V_85 == V_86 )
return V_3 -> V_48 -> V_84 > V_3 -> V_87 ;
F_50 () ;
V_84 = 0 ;
for ( V_67 = 0 ; V_67 < V_3 -> V_74 ; V_67 ++ ) {
struct V_88 * V_89 = F_51 ( V_3 -> V_23 [ V_67 ] . V_89 ) ;
if ( ! V_89 || F_14 ( V_90 , & V_89 -> V_58 ) )
V_84 ++ ;
else if ( F_14 ( V_91 , & V_89 -> V_58 ) )
;
else
if ( V_3 -> V_25 >= V_3 -> V_74 )
V_84 ++ ;
}
F_52 () ;
if ( V_84 > V_3 -> V_87 )
return 1 ;
F_50 () ;
V_84 = 0 ;
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ ) {
struct V_88 * V_89 = F_51 ( V_3 -> V_23 [ V_67 ] . V_89 ) ;
if ( ! V_89 || F_14 ( V_90 , & V_89 -> V_58 ) )
V_84 ++ ;
else if ( F_14 ( V_91 , & V_89 -> V_58 ) )
;
else
if ( V_3 -> V_25 <= V_3 -> V_74 )
V_84 ++ ;
}
F_52 () ;
if ( V_84 > V_3 -> V_87 )
return 1 ;
return 0 ;
}
static struct V_19 *
F_53 ( struct V_2 * V_3 , T_1 V_10 ,
int V_72 , int V_92 , int V_93 )
{
struct V_19 * V_20 ;
F_30 ( L_7 , ( unsigned long long ) V_10 ) ;
F_54 ( & V_3 -> V_59 ) ;
do {
F_55 ( V_3 -> V_55 ,
V_3 -> V_94 == 0 || V_93 ,
V_3 -> V_59 , ) ;
V_20 = F_47 ( V_3 , V_10 , V_3 -> V_73 - V_72 ) ;
if ( ! V_20 ) {
if ( ! V_3 -> V_95 )
V_20 = F_34 ( V_3 ) ;
if ( V_92 && V_20 == NULL )
break;
if ( ! V_20 ) {
V_3 -> V_95 = 1 ;
F_55 ( V_3 -> V_55 ,
! F_18 ( & V_3 -> V_54 ) &&
( F_19 ( & V_3 -> V_39 )
< ( V_3 -> V_96 * 3 / 4 )
|| ! V_3 -> V_95 ) ,
V_3 -> V_59 ,
) ;
V_3 -> V_95 = 0 ;
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
F_56 () ;
F_36 ( & V_20 -> V_38 ) ;
}
}
} while ( V_20 == NULL );
if ( V_20 )
F_37 ( & V_20 -> V_27 ) ;
F_57 ( & V_3 -> V_59 ) ;
return V_20 ;
}
static void F_58 ( struct V_19 * V_20 , struct V_97 * V_98 )
{
struct V_2 * V_3 = V_20 -> V_57 ;
int V_67 , V_23 = V_20 -> V_23 ;
F_59 () ;
for ( V_67 = V_23 ; V_67 -- ; ) {
int V_99 ;
struct V_9 * V_32 ;
struct V_88 * V_89 ;
if ( F_23 ( V_100 , & V_20 -> V_70 [ V_67 ] . V_58 ) ) {
if ( F_23 ( V_101 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
V_99 = V_102 ;
else
V_99 = V_103 ;
} else if ( F_23 ( V_104 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
V_99 = V_105 ;
else
continue;
V_32 = & V_20 -> V_70 [ V_67 ] . V_106 ;
V_32 -> V_107 = V_99 ;
if ( V_99 & V_103 )
V_32 -> V_108 = V_109 ;
else
V_32 -> V_108 = V_110 ;
F_50 () ;
V_89 = F_51 ( V_3 -> V_23 [ V_67 ] . V_89 ) ;
if ( V_89 && F_14 ( V_90 , & V_89 -> V_58 ) )
V_89 = NULL ;
if ( V_89 )
F_37 ( & V_89 -> V_111 ) ;
F_52 () ;
while ( ( V_99 & V_103 ) && V_89 &&
F_14 ( V_112 , & V_89 -> V_58 ) ) {
T_1 V_113 ;
int V_114 ;
int V_115 = F_60 ( V_89 , V_20 -> V_10 , V_14 ,
& V_113 , & V_114 ) ;
if ( ! V_115 )
break;
if ( V_115 < 0 ) {
F_61 ( V_116 , & V_89 -> V_58 ) ;
if ( ! V_3 -> V_48 -> V_117 &&
V_3 -> V_48 -> V_58 ) {
F_62 ( V_3 -> V_48 ) ;
}
F_63 ( V_89 , V_3 -> V_48 ) ;
} else {
F_64 ( V_89 , V_3 -> V_48 ) ;
V_89 = NULL ;
}
}
if ( V_89 ) {
if ( V_98 -> V_118 || V_98 -> V_119 || V_98 -> V_120 )
F_65 ( V_89 -> V_121 , V_14 ) ;
F_61 ( V_122 , & V_20 -> V_36 ) ;
V_32 -> V_123 = V_89 -> V_121 ;
F_30 ( L_8 ,
V_124 , ( unsigned long long ) V_20 -> V_10 ,
V_32 -> V_107 , V_67 ) ;
F_37 ( & V_20 -> V_27 ) ;
V_32 -> V_13 = V_20 -> V_10 + V_89 -> V_125 ;
V_32 -> V_126 = 1 << V_127 ;
V_32 -> V_128 = 1 ;
V_32 -> V_129 = 1 ;
V_32 -> V_130 = 0 ;
V_32 -> V_131 = & V_20 -> V_70 [ V_67 ] . V_132 ;
V_32 -> V_131 [ 0 ] . V_133 = V_134 ;
V_32 -> V_131 [ 0 ] . V_135 = 0 ;
V_32 -> V_12 = V_134 ;
V_32 -> V_15 = NULL ;
F_66 ( V_32 ) ;
} else {
if ( V_99 & V_103 )
F_61 ( V_136 , & V_20 -> V_36 ) ;
F_30 ( L_9 ,
V_32 -> V_107 , V_67 , ( unsigned long long ) V_20 -> V_10 ) ;
F_21 ( V_80 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_61 ( V_40 , & V_20 -> V_36 ) ;
}
}
}
static struct V_137 *
F_67 ( int V_138 , struct V_9 * V_9 , struct V_65 * V_65 ,
T_1 V_10 , struct V_137 * V_139 )
{
struct V_140 * V_141 ;
struct V_65 * V_142 ;
int V_67 ;
int V_143 ;
struct V_144 V_145 ;
enum V_146 V_58 = 0 ;
if ( V_9 -> V_13 >= V_10 )
V_143 = ( signed ) ( V_9 -> V_13 - V_10 ) * 512 ;
else
V_143 = ( signed ) ( V_10 - V_9 -> V_13 ) * - 512 ;
if ( V_138 )
V_58 |= V_147 ;
F_68 ( & V_145 , V_58 , V_139 , NULL , NULL , NULL ) ;
F_69 (bvl, bio, i) {
int V_148 = V_141 -> V_133 ;
int V_149 ;
int V_150 = 0 ;
if ( V_143 < 0 ) {
V_150 = - V_143 ;
V_143 += V_150 ;
V_148 -= V_150 ;
}
if ( V_148 > 0 && V_143 + V_148 > V_134 )
V_149 = V_134 - V_143 ;
else
V_149 = V_148 ;
if ( V_149 > 0 ) {
V_150 += V_141 -> V_135 ;
V_142 = V_141 -> V_151 ;
if ( V_138 )
V_139 = F_70 ( V_65 , V_142 , V_143 ,
V_150 , V_149 , & V_145 ) ;
else
V_139 = F_70 ( V_142 , V_65 , V_150 ,
V_143 , V_149 , & V_145 ) ;
}
V_145 . V_152 = V_139 ;
if ( V_149 < V_148 )
break;
V_143 += V_148 ;
}
return V_139 ;
}
static void F_71 ( void * V_153 )
{
struct V_19 * V_20 = V_153 ;
struct V_9 * V_31 = NULL ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_67 ;
F_30 ( L_10 , V_124 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_54 ( & V_3 -> V_59 ) ;
for ( V_67 = V_20 -> V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( F_23 ( V_154 , & V_70 -> V_58 ) ) {
struct V_9 * V_155 , * V_156 ;
F_17 ( ! V_70 -> V_77 ) ;
V_155 = V_70 -> V_77 ;
V_70 -> V_77 = NULL ;
while ( V_155 && V_155 -> V_13 <
V_70 -> V_10 + V_14 ) {
V_156 = F_2 ( V_155 , V_70 -> V_10 ) ;
if ( ! F_5 ( V_155 ) ) {
V_155 -> V_15 = V_31 ;
V_31 = V_155 ;
}
V_155 = V_156 ;
}
}
}
F_57 ( & V_3 -> V_59 ) ;
F_21 ( V_35 , & V_20 -> V_36 ) ;
F_11 ( V_31 ) ;
F_61 ( V_40 , & V_20 -> V_36 ) ;
F_26 ( V_20 ) ;
}
static void F_72 ( struct V_19 * V_20 )
{
struct V_137 * V_139 = NULL ;
struct V_2 * V_3 = V_20 -> V_57 ;
struct V_144 V_145 ;
int V_67 ;
F_30 ( L_10 , V_124 ,
( unsigned long long ) V_20 -> V_10 ) ;
for ( V_67 = V_20 -> V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( F_14 ( V_154 , & V_70 -> V_58 ) ) {
struct V_9 * V_155 ;
F_54 ( & V_3 -> V_59 ) ;
V_70 -> V_77 = V_155 = V_70 -> V_76 ;
V_70 -> V_76 = NULL ;
F_57 ( & V_3 -> V_59 ) ;
while ( V_155 && V_155 -> V_13 <
V_70 -> V_10 + V_14 ) {
V_139 = F_67 ( 0 , V_155 , V_70 -> V_65 ,
V_70 -> V_10 , V_139 ) ;
V_155 = F_2 ( V_155 , V_70 -> V_10 ) ;
}
}
}
F_37 ( & V_20 -> V_27 ) ;
F_68 ( & V_145 , V_157 , V_139 , F_71 , V_20 , NULL ) ;
F_73 ( & V_145 ) ;
}
static void F_74 ( struct V_19 * V_20 , int V_158 )
{
struct V_75 * V_159 ;
if ( V_158 < 0 )
return;
V_159 = & V_20 -> V_70 [ V_158 ] ;
F_61 ( V_160 , & V_159 -> V_58 ) ;
F_17 ( ! F_14 ( V_161 , & V_159 -> V_58 ) ) ;
F_21 ( V_161 , & V_159 -> V_58 ) ;
}
static void F_75 ( void * V_153 )
{
struct V_19 * V_20 = V_153 ;
F_30 ( L_10 , V_124 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_74 ( V_20 , V_20 -> V_162 . V_158 ) ;
F_74 ( V_20 , V_20 -> V_162 . V_163 ) ;
F_21 ( V_37 , & V_20 -> V_36 ) ;
if ( V_20 -> V_33 == V_164 )
V_20 -> V_33 = V_165 ;
F_61 ( V_40 , & V_20 -> V_36 ) ;
F_26 ( V_20 ) ;
}
static T_2 * F_76 ( struct V_19 * V_20 ,
struct V_166 * V_167 )
{
return V_167 -> V_168 + sizeof( struct V_65 * ) * ( V_20 -> V_23 + 2 ) ;
}
static struct V_137 *
F_77 ( struct V_19 * V_20 , struct V_166 * V_167 )
{
int V_23 = V_20 -> V_23 ;
struct V_65 * * V_169 = V_167 -> V_168 ;
int V_158 = V_20 -> V_162 . V_158 ;
struct V_75 * V_159 = & V_20 -> V_70 [ V_158 ] ;
struct V_65 * V_170 = V_159 -> V_65 ;
int V_27 = 0 ;
struct V_137 * V_139 ;
struct V_144 V_145 ;
int V_67 ;
F_30 ( L_11 ,
V_124 , ( unsigned long long ) V_20 -> V_10 , V_158 ) ;
F_17 ( ! F_14 ( V_161 , & V_159 -> V_58 ) ) ;
for ( V_67 = V_23 ; V_67 -- ; )
if ( V_67 != V_158 )
V_169 [ V_27 ++ ] = V_20 -> V_70 [ V_67 ] . V_65 ;
F_37 ( & V_20 -> V_27 ) ;
F_68 ( & V_145 , V_147 | V_171 , NULL ,
F_75 , V_20 , F_76 ( V_20 , V_167 ) ) ;
if ( F_78 ( V_27 == 1 ) )
V_139 = F_70 ( V_170 , V_169 [ 0 ] , 0 , 0 , V_134 , & V_145 ) ;
else
V_139 = F_79 ( V_170 , V_169 , 0 , V_27 , V_134 , & V_145 ) ;
return V_139 ;
}
static int F_80 ( struct V_65 * * V_172 , struct V_19 * V_20 )
{
int V_23 = V_20 -> V_23 ;
int V_28 = V_20 -> V_21 ? V_23 : ( V_23 - 2 ) ;
int V_173 = F_8 ( V_20 ) ;
int V_27 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_23 ; V_67 ++ )
V_172 [ V_67 ] = NULL ;
V_27 = 0 ;
V_67 = V_173 ;
do {
int V_29 = F_10 ( V_67 , V_20 , & V_27 , V_28 ) ;
V_172 [ V_29 ] = V_20 -> V_70 [ V_67 ] . V_65 ;
V_67 = F_9 ( V_67 , V_23 ) ;
} while ( V_67 != V_173 );
return V_28 ;
}
static struct V_137 *
F_81 ( struct V_19 * V_20 , struct V_166 * V_167 )
{
int V_23 = V_20 -> V_23 ;
struct V_65 * * V_174 = V_167 -> V_168 ;
int V_158 ;
int V_22 = V_20 -> V_22 ;
struct V_137 * V_139 ;
struct V_144 V_145 ;
struct V_75 * V_159 ;
struct V_65 * V_175 ;
int V_67 ;
int V_27 ;
if ( V_20 -> V_162 . V_158 < 0 )
V_158 = V_20 -> V_162 . V_163 ;
else if ( V_20 -> V_162 . V_163 < 0 )
V_158 = V_20 -> V_162 . V_158 ;
else
F_56 () ;
F_17 ( V_158 < 0 ) ;
F_30 ( L_11 ,
V_124 , ( unsigned long long ) V_20 -> V_10 , V_158 ) ;
V_159 = & V_20 -> V_70 [ V_158 ] ;
F_17 ( ! F_14 ( V_161 , & V_159 -> V_58 ) ) ;
V_175 = V_159 -> V_65 ;
F_37 ( & V_20 -> V_27 ) ;
if ( V_158 == V_22 ) {
V_27 = F_80 ( V_174 , V_20 ) ;
V_174 [ V_27 ] = NULL ;
F_17 ( V_174 [ V_27 + 1 ] != V_175 ) ;
F_68 ( & V_145 , V_147 , NULL ,
F_75 , V_20 ,
F_76 ( V_20 , V_167 ) ) ;
V_139 = F_82 ( V_174 , 0 , V_27 + 2 , V_134 , & V_145 ) ;
} else {
V_27 = 0 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
if ( V_67 == V_158 || V_67 == V_22 )
continue;
V_174 [ V_27 ++ ] = V_20 -> V_70 [ V_67 ] . V_65 ;
}
F_68 ( & V_145 , V_147 | V_171 ,
NULL , F_75 , V_20 ,
F_76 ( V_20 , V_167 ) ) ;
V_139 = F_79 ( V_175 , V_174 , 0 , V_27 , V_134 , & V_145 ) ;
}
return V_139 ;
}
static struct V_137 *
F_83 ( struct V_19 * V_20 , struct V_166 * V_167 )
{
int V_67 , V_27 , V_23 = V_20 -> V_23 ;
int V_28 = V_20 -> V_21 ? V_23 : V_23 - 2 ;
int V_173 = F_8 ( V_20 ) ;
int V_176 = - 1 , V_177 = - 1 ;
int V_158 = V_20 -> V_162 . V_158 ;
int V_163 = V_20 -> V_162 . V_163 ;
struct V_75 * V_159 = & V_20 -> V_70 [ V_158 ] ;
struct V_75 * V_178 = & V_20 -> V_70 [ V_163 ] ;
struct V_137 * V_139 ;
struct V_65 * * V_174 = V_167 -> V_168 ;
struct V_144 V_145 ;
F_30 ( L_12 ,
V_124 , ( unsigned long long ) V_20 -> V_10 , V_158 , V_163 ) ;
F_17 ( V_158 < 0 || V_163 < 0 ) ;
F_17 ( ! F_14 ( V_161 , & V_159 -> V_58 ) ) ;
F_17 ( ! F_14 ( V_161 , & V_178 -> V_58 ) ) ;
for ( V_67 = 0 ; V_67 < V_23 ; V_67 ++ )
V_174 [ V_67 ] = NULL ;
V_27 = 0 ;
V_67 = V_173 ;
do {
int V_29 = F_10 ( V_67 , V_20 , & V_27 , V_28 ) ;
V_174 [ V_29 ] = V_20 -> V_70 [ V_67 ] . V_65 ;
if ( V_67 == V_158 )
V_176 = V_29 ;
if ( V_67 == V_163 )
V_177 = V_29 ;
V_67 = F_9 ( V_67 , V_23 ) ;
} while ( V_67 != V_173 );
F_17 ( V_176 == V_177 ) ;
if ( V_177 < V_176 )
F_84 ( V_176 , V_177 ) ;
F_30 ( L_13 ,
V_124 , ( unsigned long long ) V_20 -> V_10 , V_176 , V_177 ) ;
F_37 ( & V_20 -> V_27 ) ;
if ( V_177 == V_28 + 1 ) {
if ( V_176 == V_28 ) {
F_68 ( & V_145 , V_147 , NULL ,
F_75 , V_20 ,
F_76 ( V_20 , V_167 ) ) ;
return F_82 ( V_174 , 0 , V_28 + 2 ,
V_134 , & V_145 ) ;
} else {
struct V_65 * V_175 ;
int V_179 ;
int V_22 = V_20 -> V_22 ;
if ( V_158 == V_22 )
V_179 = V_163 ;
else
V_179 = V_158 ;
V_27 = 0 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
if ( V_67 == V_179 || V_67 == V_22 )
continue;
V_174 [ V_27 ++ ] = V_20 -> V_70 [ V_67 ] . V_65 ;
}
V_175 = V_20 -> V_70 [ V_179 ] . V_65 ;
F_68 ( & V_145 ,
V_147 | V_171 ,
NULL , NULL , NULL ,
F_76 ( V_20 , V_167 ) ) ;
V_139 = F_79 ( V_175 , V_174 , 0 , V_27 , V_134 ,
& V_145 ) ;
V_27 = F_80 ( V_174 , V_20 ) ;
F_68 ( & V_145 , V_147 , V_139 ,
F_75 , V_20 ,
F_76 ( V_20 , V_167 ) ) ;
return F_82 ( V_174 , 0 , V_27 + 2 ,
V_134 , & V_145 ) ;
}
} else {
F_68 ( & V_145 , V_147 , NULL ,
F_75 , V_20 ,
F_76 ( V_20 , V_167 ) ) ;
if ( V_177 == V_28 ) {
return F_85 ( V_28 + 2 ,
V_134 , V_176 ,
V_174 , & V_145 ) ;
} else {
return F_86 ( V_28 + 2 ,
V_134 , V_176 , V_177 ,
V_174 , & V_145 ) ;
}
}
}
static void F_87 ( void * V_153 )
{
struct V_19 * V_20 = V_153 ;
F_30 ( L_10 , V_124 ,
( unsigned long long ) V_20 -> V_10 ) ;
}
static struct V_137 *
F_88 ( struct V_19 * V_20 , struct V_166 * V_167 ,
struct V_137 * V_139 )
{
int V_23 = V_20 -> V_23 ;
struct V_65 * * V_169 = V_167 -> V_168 ;
int V_27 = 0 , V_30 = V_20 -> V_30 , V_67 ;
struct V_144 V_145 ;
struct V_65 * V_170 = V_169 [ V_27 ++ ] = V_20 -> V_70 [ V_30 ] . V_65 ;
F_30 ( L_10 , V_124 ,
( unsigned long long ) V_20 -> V_10 ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( F_14 ( V_180 , & V_70 -> V_58 ) )
V_169 [ V_27 ++ ] = V_70 -> V_65 ;
}
F_68 ( & V_145 , V_147 | V_181 , V_139 ,
F_87 , V_20 , F_76 ( V_20 , V_167 ) ) ;
V_139 = F_79 ( V_170 , V_169 , 0 , V_27 , V_134 , & V_145 ) ;
return V_139 ;
}
static struct V_137 *
F_89 ( struct V_19 * V_20 , struct V_137 * V_139 )
{
int V_23 = V_20 -> V_23 ;
int V_67 ;
F_30 ( L_10 , V_124 ,
( unsigned long long ) V_20 -> V_10 ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
struct V_9 * V_182 ;
if ( F_23 ( V_180 , & V_70 -> V_58 ) ) {
struct V_9 * V_183 ;
F_54 ( & V_20 -> V_57 -> V_59 ) ;
V_182 = V_70 -> V_78 ;
V_70 -> V_78 = NULL ;
F_17 ( V_70 -> V_79 ) ;
V_183 = V_70 -> V_79 = V_182 ;
F_57 ( & V_20 -> V_57 -> V_59 ) ;
while ( V_183 && V_183 -> V_13 <
V_70 -> V_10 + V_14 ) {
if ( V_183 -> V_107 & V_184 )
F_61 ( V_101 , & V_70 -> V_58 ) ;
V_139 = F_67 ( 1 , V_183 , V_70 -> V_65 ,
V_70 -> V_10 , V_139 ) ;
V_183 = F_2 ( V_183 , V_70 -> V_10 ) ;
}
}
}
return V_139 ;
}
static void F_90 ( void * V_153 )
{
struct V_19 * V_20 = V_153 ;
int V_23 = V_20 -> V_23 ;
int V_30 = V_20 -> V_30 ;
int V_22 = V_20 -> V_22 ;
int V_67 ;
bool V_185 = false ;
F_30 ( L_10 , V_124 ,
( unsigned long long ) V_20 -> V_10 ) ;
for ( V_67 = V_23 ; V_67 -- ; )
V_185 |= F_14 ( V_101 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( V_70 -> V_79 || V_67 == V_30 || V_67 == V_22 ) {
F_61 ( V_160 , & V_70 -> V_58 ) ;
if ( V_185 )
F_61 ( V_101 , & V_70 -> V_58 ) ;
}
}
if ( V_20 -> V_34 == V_186 )
V_20 -> V_34 = V_187 ;
else if ( V_20 -> V_34 == V_188 )
V_20 -> V_34 = V_189 ;
else {
F_17 ( V_20 -> V_34 != V_190 ) ;
V_20 -> V_34 = V_191 ;
}
F_61 ( V_40 , & V_20 -> V_36 ) ;
F_26 ( V_20 ) ;
}
static void
F_91 ( struct V_19 * V_20 , struct V_166 * V_167 ,
struct V_137 * V_139 )
{
int V_23 = V_20 -> V_23 ;
struct V_65 * * V_169 = V_167 -> V_168 ;
struct V_144 V_145 ;
int V_27 = 0 , V_30 = V_20 -> V_30 , V_67 ;
struct V_65 * V_170 ;
int V_192 = 0 ;
unsigned long V_58 ;
F_30 ( L_10 , V_124 ,
( unsigned long long ) V_20 -> V_10 ) ;
if ( V_20 -> V_34 == V_188 ) {
V_192 = 1 ;
V_170 = V_169 [ V_27 ++ ] = V_20 -> V_70 [ V_30 ] . V_65 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( V_70 -> V_79 )
V_169 [ V_27 ++ ] = V_70 -> V_65 ;
}
} else {
V_170 = V_20 -> V_70 [ V_30 ] . V_65 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( V_67 != V_30 )
V_169 [ V_27 ++ ] = V_70 -> V_65 ;
}
}
V_58 = V_157 |
( V_192 ? V_181 : V_171 ) ;
F_37 ( & V_20 -> V_27 ) ;
F_68 ( & V_145 , V_58 , V_139 , F_90 , V_20 ,
F_76 ( V_20 , V_167 ) ) ;
if ( F_78 ( V_27 == 1 ) )
V_139 = F_70 ( V_170 , V_169 [ 0 ] , 0 , 0 , V_134 , & V_145 ) ;
else
V_139 = F_79 ( V_170 , V_169 , 0 , V_27 , V_134 , & V_145 ) ;
}
static void
F_92 ( struct V_19 * V_20 , struct V_166 * V_167 ,
struct V_137 * V_139 )
{
struct V_144 V_145 ;
struct V_65 * * V_174 = V_167 -> V_168 ;
int V_27 ;
F_30 ( L_10 , V_124 , ( unsigned long long ) V_20 -> V_10 ) ;
V_27 = F_80 ( V_174 , V_20 ) ;
F_37 ( & V_20 -> V_27 ) ;
F_68 ( & V_145 , V_157 , V_139 , F_90 ,
V_20 , F_76 ( V_20 , V_167 ) ) ;
F_82 ( V_174 , 0 , V_27 + 2 , V_134 , & V_145 ) ;
}
static void F_93 ( void * V_153 )
{
struct V_19 * V_20 = V_153 ;
F_30 ( L_10 , V_124 ,
( unsigned long long ) V_20 -> V_10 ) ;
V_20 -> V_33 = V_193 ;
F_61 ( V_40 , & V_20 -> V_36 ) ;
F_26 ( V_20 ) ;
}
static void F_94 ( struct V_19 * V_20 , struct V_166 * V_167 )
{
int V_23 = V_20 -> V_23 ;
int V_30 = V_20 -> V_30 ;
int V_22 = V_20 -> V_22 ;
struct V_65 * V_170 ;
struct V_65 * * V_169 = V_167 -> V_168 ;
struct V_137 * V_139 ;
struct V_144 V_145 ;
int V_27 ;
int V_67 ;
F_30 ( L_10 , V_124 ,
( unsigned long long ) V_20 -> V_10 ) ;
V_27 = 0 ;
V_170 = V_20 -> V_70 [ V_30 ] . V_65 ;
V_169 [ V_27 ++ ] = V_170 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
if ( V_67 == V_30 || V_67 == V_22 )
continue;
V_169 [ V_27 ++ ] = V_20 -> V_70 [ V_67 ] . V_65 ;
}
F_68 ( & V_145 , 0 , NULL , NULL , NULL ,
F_76 ( V_20 , V_167 ) ) ;
V_139 = F_95 ( V_170 , V_169 , 0 , V_27 , V_134 ,
& V_20 -> V_162 . V_194 , & V_145 ) ;
F_37 ( & V_20 -> V_27 ) ;
F_68 ( & V_145 , V_157 , V_139 , F_93 , V_20 , NULL ) ;
V_139 = F_73 ( & V_145 ) ;
}
static void F_96 ( struct V_19 * V_20 , struct V_166 * V_167 , int V_195 )
{
struct V_65 * * V_172 = V_167 -> V_168 ;
struct V_144 V_145 ;
int V_27 ;
F_30 ( L_14 , V_124 ,
( unsigned long long ) V_20 -> V_10 , V_195 ) ;
V_27 = F_80 ( V_172 , V_20 ) ;
if ( ! V_195 )
V_172 [ V_27 ] = NULL ;
F_37 ( & V_20 -> V_27 ) ;
F_68 ( & V_145 , V_157 , NULL , F_93 ,
V_20 , F_76 ( V_20 , V_167 ) ) ;
F_97 ( V_172 , 0 , V_27 + 2 , V_134 ,
& V_20 -> V_162 . V_194 , V_167 -> V_196 , & V_145 ) ;
}
static void F_98 ( struct V_19 * V_20 , unsigned long V_197 )
{
int V_198 = 0 , V_67 , V_23 = V_20 -> V_23 ;
struct V_137 * V_139 = NULL ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_199 = V_3 -> V_199 ;
struct V_166 * V_167 ;
unsigned long V_200 ;
V_200 = F_99 () ;
V_167 = F_100 ( V_3 -> V_167 , V_200 ) ;
if ( F_14 ( V_201 , & V_197 ) ) {
F_72 ( V_20 ) ;
V_198 ++ ;
}
if ( F_14 ( V_202 , & V_197 ) ) {
if ( V_199 < 6 )
V_139 = F_77 ( V_20 , V_167 ) ;
else {
if ( V_20 -> V_162 . V_163 < 0 || V_20 -> V_162 . V_158 < 0 )
V_139 = F_81 ( V_20 , V_167 ) ;
else
V_139 = F_83 ( V_20 , V_167 ) ;
}
if ( V_139 && ! F_14 ( V_203 , & V_197 ) )
F_101 ( V_139 ) ;
}
if ( F_14 ( V_204 , & V_197 ) )
V_139 = F_88 ( V_20 , V_167 , V_139 ) ;
if ( F_14 ( V_205 , & V_197 ) ) {
V_139 = F_89 ( V_20 , V_139 ) ;
V_198 ++ ;
}
if ( F_14 ( V_203 , & V_197 ) ) {
if ( V_199 < 6 )
F_91 ( V_20 , V_167 , V_139 ) ;
else
F_92 ( V_20 , V_167 , V_139 ) ;
}
if ( F_14 ( V_206 , & V_197 ) ) {
if ( V_20 -> V_33 == V_207 )
F_94 ( V_20 , V_167 ) ;
else if ( V_20 -> V_33 == V_208 )
F_96 ( V_20 , V_167 , 0 ) ;
else if ( V_20 -> V_33 == V_209 )
F_96 ( V_20 , V_167 , 1 ) ;
else
F_56 () ;
}
if ( V_198 )
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( F_23 ( V_210 , & V_70 -> V_58 ) )
F_25 ( & V_20 -> V_57 -> V_211 ) ;
}
F_102 () ;
}
static void F_103 ( void * V_212 , T_3 V_213 )
{
struct V_19 * V_20 = V_212 ;
unsigned long V_197 = V_20 -> V_162 . V_214 ;
F_104 ( V_215 , & V_20 -> V_36 ) ;
F_25 ( & V_20 -> V_162 . V_216 ) ;
F_98 ( V_20 , V_197 ) ;
F_26 ( V_20 ) ;
}
static void F_105 ( struct V_19 * V_20 , unsigned long V_197 )
{
F_106 ( V_20 -> V_162 . V_216 ,
! F_107 ( V_215 , & V_20 -> V_36 ) ) ;
V_20 -> V_162 . V_214 = V_197 ;
F_37 ( & V_20 -> V_27 ) ;
F_108 ( F_103 , V_20 ) ;
}
static int F_109 ( struct V_2 * V_3 )
{
struct V_19 * V_20 ;
V_20 = F_110 ( V_3 -> V_217 , V_71 ) ;
if ( ! V_20 )
return 0 ;
V_20 -> V_57 = V_3 ;
#ifdef F_111
F_112 ( & V_20 -> V_162 . V_216 ) ;
#endif
if ( F_40 ( V_20 ) ) {
F_38 ( V_20 ) ;
F_113 ( V_3 -> V_217 , V_20 ) ;
return 0 ;
}
F_114 ( & V_20 -> V_27 , 1 ) ;
F_37 ( & V_3 -> V_39 ) ;
F_115 ( & V_20 -> V_38 ) ;
F_26 ( V_20 ) ;
return 1 ;
}
static int F_116 ( struct V_2 * V_3 , int V_68 )
{
struct V_218 * V_219 ;
int V_220 = F_117 ( V_3 -> V_25 , V_3 -> V_74 ) ;
if ( V_3 -> V_48 -> V_221 )
sprintf ( V_3 -> V_222 [ 0 ] ,
L_15 , V_3 -> V_199 , F_118 ( V_3 -> V_48 ) ) ;
else
sprintf ( V_3 -> V_222 [ 0 ] ,
L_16 , V_3 -> V_199 , V_3 -> V_48 ) ;
sprintf ( V_3 -> V_222 [ 1 ] , L_17 , V_3 -> V_222 [ 0 ] ) ;
V_3 -> V_223 = 0 ;
V_219 = F_119 ( V_3 -> V_222 [ V_3 -> V_223 ] ,
sizeof( struct V_19 ) + ( V_220 - 1 ) * sizeof( struct V_75 ) ,
0 , 0 , NULL ) ;
if ( ! V_219 )
return 1 ;
V_3 -> V_217 = V_219 ;
V_3 -> V_69 = V_220 ;
while ( V_68 -- )
if ( ! F_109 ( V_3 ) )
return 1 ;
return 0 ;
}
static T_4 F_120 ( int V_68 )
{
T_4 V_148 ;
V_148 = sizeof( struct V_65 * ) * ( V_68 + 2 ) + sizeof( T_2 ) * ( V_68 + 2 ) ;
return V_148 ;
}
static int F_121 ( struct V_2 * V_3 , int V_224 )
{
struct V_19 * V_225 , * V_226 ;
F_122 ( V_227 ) ;
struct V_228 * V_229 ;
unsigned long V_200 ;
int V_230 ;
struct V_218 * V_219 ;
int V_67 ;
if ( V_224 <= V_3 -> V_69 )
return 0 ;
V_230 = F_123 ( V_3 -> V_48 ) ;
if ( V_230 )
return V_230 ;
V_219 = F_119 ( V_3 -> V_222 [ 1 - V_3 -> V_223 ] ,
sizeof( struct V_19 ) + ( V_224 - 1 ) * sizeof( struct V_75 ) ,
0 , 0 , NULL ) ;
if ( ! V_219 )
return - V_231 ;
for ( V_67 = V_3 -> V_96 ; V_67 ; V_67 -- ) {
V_226 = F_110 ( V_219 , V_71 ) ;
if ( ! V_226 )
break;
V_226 -> V_57 = V_3 ;
#ifdef F_111
F_112 ( & V_226 -> V_162 . V_216 ) ;
#endif
F_124 ( & V_226 -> V_38 , & V_227 ) ;
}
if ( V_67 ) {
while ( ! F_18 ( & V_227 ) ) {
V_226 = F_35 ( V_227 . V_64 , struct V_19 , V_38 ) ;
F_125 ( & V_226 -> V_38 ) ;
F_113 ( V_219 , V_226 ) ;
}
F_126 ( V_219 ) ;
return - V_231 ;
}
F_127 (nsh, &newstripes, lru) {
F_54 ( & V_3 -> V_59 ) ;
F_55 ( V_3 -> V_55 ,
! F_18 ( & V_3 -> V_54 ) ,
V_3 -> V_59 ,
) ;
V_225 = F_34 ( V_3 ) ;
F_57 ( & V_3 -> V_59 ) ;
F_114 ( & V_226 -> V_27 , 1 ) ;
for( V_67 = 0 ; V_67 < V_3 -> V_69 ; V_67 ++ )
V_226 -> V_70 [ V_67 ] . V_65 = V_225 -> V_70 [ V_67 ] . V_65 ;
for( ; V_67 < V_224 ; V_67 ++ )
V_226 -> V_70 [ V_67 ] . V_65 = NULL ;
F_113 ( V_3 -> V_217 , V_225 ) ;
}
F_126 ( V_3 -> V_217 ) ;
V_229 = F_128 ( V_224 * sizeof( struct V_228 ) , V_232 ) ;
if ( V_229 ) {
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ )
V_229 [ V_67 ] = V_3 -> V_23 [ V_67 ] ;
F_129 ( V_3 -> V_23 ) ;
V_3 -> V_23 = V_229 ;
} else
V_230 = - V_231 ;
F_130 () ;
V_3 -> F_120 = F_120 ( V_224 ) ;
F_131 (cpu) {
struct V_166 * V_167 ;
void * V_168 ;
V_167 = F_100 ( V_3 -> V_167 , V_200 ) ;
V_168 = F_132 ( V_3 -> F_120 , V_232 ) ;
if ( V_168 ) {
F_129 ( V_167 -> V_168 ) ;
V_167 -> V_168 = V_168 ;
} else {
V_230 = - V_231 ;
break;
}
}
F_133 () ;
while( ! F_18 ( & V_227 ) ) {
V_226 = F_35 ( V_227 . V_64 , struct V_19 , V_38 ) ;
F_36 ( & V_226 -> V_38 ) ;
for ( V_67 = V_3 -> V_25 ; V_67 < V_224 ; V_67 ++ )
if ( V_226 -> V_70 [ V_67 ] . V_65 == NULL ) {
struct V_65 * V_66 = F_41 ( V_232 ) ;
V_226 -> V_70 [ V_67 ] . V_65 = V_66 ;
if ( ! V_66 )
V_230 = - V_231 ;
}
F_26 ( V_226 ) ;
}
V_3 -> V_217 = V_219 ;
V_3 -> V_223 = 1 - V_3 -> V_223 ;
V_3 -> V_69 = V_224 ;
return V_230 ;
}
static int F_134 ( struct V_2 * V_3 )
{
struct V_19 * V_20 ;
F_54 ( & V_3 -> V_59 ) ;
V_20 = F_34 ( V_3 ) ;
F_57 ( & V_3 -> V_59 ) ;
if ( ! V_20 )
return 0 ;
F_17 ( F_19 ( & V_20 -> V_27 ) ) ;
F_38 ( V_20 ) ;
F_113 ( V_3 -> V_217 , V_20 ) ;
F_24 ( & V_3 -> V_39 ) ;
return 1 ;
}
static void F_135 ( struct V_2 * V_3 )
{
while ( F_134 ( V_3 ) )
;
if ( V_3 -> V_217 )
F_126 ( V_3 -> V_217 ) ;
V_3 -> V_217 = NULL ;
}
static void V_110 ( struct V_9 * V_32 , int error )
{
struct V_19 * V_20 = V_32 -> V_233 ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_23 = V_20 -> V_23 , V_67 ;
int V_234 = F_14 ( V_127 , & V_32 -> V_126 ) ;
char V_235 [ V_236 ] ;
struct V_88 * V_89 ;
for ( V_67 = 0 ; V_67 < V_23 ; V_67 ++ )
if ( V_32 == & V_20 -> V_70 [ V_67 ] . V_106 )
break;
F_30 ( L_18 ,
( unsigned long long ) V_20 -> V_10 , V_67 , F_19 ( & V_20 -> V_27 ) ,
V_234 ) ;
if ( V_67 == V_23 ) {
F_56 () ;
return;
}
if ( V_234 ) {
F_61 ( V_160 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
if ( F_14 ( V_237 , & V_20 -> V_70 [ V_67 ] . V_58 ) ) {
V_89 = V_3 -> V_23 [ V_67 ] . V_89 ;
F_136 (
V_238
L_19
L_20 ,
F_118 ( V_3 -> V_48 ) , V_14 ,
( unsigned long long ) ( V_20 -> V_10
+ V_89 -> V_125 ) ,
F_137 ( V_89 -> V_121 , V_235 ) ) ;
F_138 ( V_14 , & V_89 -> V_239 ) ;
F_21 ( V_237 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_21 ( V_240 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
}
if ( F_19 ( & V_3 -> V_23 [ V_67 ] . V_89 -> V_241 ) )
F_114 ( & V_3 -> V_23 [ V_67 ] . V_89 -> V_241 , 0 ) ;
} else {
const char * V_242 = F_137 ( V_3 -> V_23 [ V_67 ] . V_89 -> V_121 , V_235 ) ;
int V_243 = 0 ;
V_89 = V_3 -> V_23 [ V_67 ] . V_89 ;
F_21 ( V_160 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_37 ( & V_89 -> V_241 ) ;
if ( V_3 -> V_48 -> V_84 >= V_3 -> V_87 )
F_136 (
V_244
L_21
L_22 ,
F_118 ( V_3 -> V_48 ) ,
( unsigned long long ) ( V_20 -> V_10
+ V_89 -> V_125 ) ,
V_242 ) ;
else if ( F_14 ( V_240 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
F_136 (
V_244
L_23
L_22 ,
F_118 ( V_3 -> V_48 ) ,
( unsigned long long ) ( V_20 -> V_10
+ V_89 -> V_125 ) ,
V_242 ) ;
else if ( F_19 ( & V_89 -> V_241 )
> V_3 -> V_96 )
F_44 ( V_244
L_24 ,
F_118 ( V_3 -> V_48 ) , V_242 ) ;
else
V_243 = 1 ;
if ( V_243 )
F_61 ( V_237 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
else {
F_21 ( V_237 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_21 ( V_240 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_139 ( V_3 -> V_48 , V_89 ) ;
}
}
F_64 ( V_3 -> V_23 [ V_67 ] . V_89 , V_3 -> V_48 ) ;
F_21 ( V_80 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_61 ( V_40 , & V_20 -> V_36 ) ;
F_26 ( V_20 ) ;
}
static void V_109 ( struct V_9 * V_32 , int error )
{
struct V_19 * V_20 = V_32 -> V_233 ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_23 = V_20 -> V_23 , V_67 ;
int V_234 = F_14 ( V_127 , & V_32 -> V_126 ) ;
T_1 V_113 ;
int V_114 ;
for ( V_67 = 0 ; V_67 < V_23 ; V_67 ++ )
if ( V_32 == & V_20 -> V_70 [ V_67 ] . V_106 )
break;
F_30 ( L_25 ,
( unsigned long long ) V_20 -> V_10 , V_67 , F_19 ( & V_20 -> V_27 ) ,
V_234 ) ;
if ( V_67 == V_23 ) {
F_56 () ;
return;
}
if ( ! V_234 ) {
F_61 ( V_112 , & V_3 -> V_23 [ V_67 ] . V_89 -> V_58 ) ;
F_61 ( V_245 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
} else if ( F_60 ( V_3 -> V_23 [ V_67 ] . V_89 , V_20 -> V_10 , V_14 ,
& V_113 , & V_114 ) )
F_61 ( V_246 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_64 ( V_3 -> V_23 [ V_67 ] . V_89 , V_3 -> V_48 ) ;
F_21 ( V_80 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_61 ( V_40 , & V_20 -> V_36 ) ;
F_26 ( V_20 ) ;
}
static void F_46 ( struct V_19 * V_20 , int V_67 , int V_72 )
{
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
F_140 ( & V_70 -> V_106 ) ;
V_70 -> V_106 . V_131 = & V_70 -> V_132 ;
V_70 -> V_106 . V_128 ++ ;
V_70 -> V_106 . V_129 ++ ;
V_70 -> V_132 . V_151 = V_70 -> V_65 ;
V_70 -> V_132 . V_133 = V_134 ;
V_70 -> V_132 . V_135 = 0 ;
V_70 -> V_106 . V_13 = V_20 -> V_10 ;
V_70 -> V_106 . V_233 = V_20 ;
V_70 -> V_58 = 0 ;
V_70 -> V_10 = F_141 ( V_20 , V_67 , V_72 ) ;
}
static void error ( struct V_48 * V_48 , struct V_88 * V_89 )
{
char V_235 [ V_236 ] ;
struct V_2 * V_3 = V_48 -> V_247 ;
F_30 ( L_26 ) ;
if ( F_23 ( V_91 , & V_89 -> V_58 ) ) {
unsigned long V_58 ;
F_27 ( & V_3 -> V_59 , V_58 ) ;
V_48 -> V_84 ++ ;
F_28 ( & V_3 -> V_59 , V_58 ) ;
F_61 ( V_248 , & V_48 -> V_249 ) ;
}
F_61 ( V_250 , & V_89 -> V_58 ) ;
F_61 ( V_90 , & V_89 -> V_58 ) ;
F_61 ( V_251 , & V_48 -> V_58 ) ;
F_44 ( V_252
L_27
L_28 ,
F_118 ( V_48 ) ,
F_137 ( V_89 -> V_121 , V_235 ) ,
F_118 ( V_48 ) ,
V_3 -> V_25 - V_48 -> V_84 ) ;
}
static T_1 F_142 ( struct V_2 * V_3 , T_1 V_253 ,
int V_72 , int * V_254 ,
struct V_19 * V_20 )
{
T_1 V_255 , V_256 ;
T_1 V_257 ;
unsigned int V_258 ;
int V_30 , V_22 ;
int V_21 = 0 ;
T_1 V_259 ;
int V_260 = V_72 ? V_3 -> V_261
: V_3 -> V_260 ;
int V_262 = V_72 ? V_3 -> V_263
: V_3 -> V_264 ;
int V_25 = V_72 ? V_3 -> V_74
: V_3 -> V_25 ;
int V_265 = V_25 - V_3 -> V_87 ;
V_258 = F_143 ( V_253 , V_262 ) ;
V_257 = V_253 ;
V_255 = V_257 ;
* V_254 = F_143 ( V_255 , V_265 ) ;
V_256 = V_255 ;
V_30 = V_22 = - 1 ;
switch( V_3 -> V_199 ) {
case 4 :
V_30 = V_265 ;
break;
case 5 :
switch ( V_260 ) {
case V_266 :
V_30 = V_265 - F_143 ( V_256 , V_25 ) ;
if ( * V_254 >= V_30 )
( * V_254 ) ++ ;
break;
case V_267 :
V_30 = F_143 ( V_256 , V_25 ) ;
if ( * V_254 >= V_30 )
( * V_254 ) ++ ;
break;
case V_268 :
V_30 = V_265 - F_143 ( V_256 , V_25 ) ;
* V_254 = ( V_30 + 1 + * V_254 ) % V_25 ;
break;
case V_269 :
V_30 = F_143 ( V_256 , V_25 ) ;
* V_254 = ( V_30 + 1 + * V_254 ) % V_25 ;
break;
case V_270 :
V_30 = 0 ;
( * V_254 ) ++ ;
break;
case V_271 :
V_30 = V_265 ;
break;
default:
F_56 () ;
}
break;
case 6 :
switch ( V_260 ) {
case V_266 :
V_30 = V_25 - 1 - F_143 ( V_256 , V_25 ) ;
V_22 = V_30 + 1 ;
if ( V_30 == V_25 - 1 ) {
( * V_254 ) ++ ;
V_22 = 0 ;
} else if ( * V_254 >= V_30 )
( * V_254 ) += 2 ;
break;
case V_267 :
V_30 = F_143 ( V_256 , V_25 ) ;
V_22 = V_30 + 1 ;
if ( V_30 == V_25 - 1 ) {
( * V_254 ) ++ ;
V_22 = 0 ;
} else if ( * V_254 >= V_30 )
( * V_254 ) += 2 ;
break;
case V_268 :
V_30 = V_25 - 1 - F_143 ( V_256 , V_25 ) ;
V_22 = ( V_30 + 1 ) % V_25 ;
* V_254 = ( V_30 + 2 + * V_254 ) % V_25 ;
break;
case V_269 :
V_30 = F_143 ( V_256 , V_25 ) ;
V_22 = ( V_30 + 1 ) % V_25 ;
* V_254 = ( V_30 + 2 + * V_254 ) % V_25 ;
break;
case V_270 :
V_30 = 0 ;
V_22 = 1 ;
( * V_254 ) += 2 ;
break;
case V_271 :
V_30 = V_265 ;
V_22 = V_265 + 1 ;
break;
case V_272 :
V_30 = F_143 ( V_256 , V_25 ) ;
V_22 = V_30 + 1 ;
if ( V_30 == V_25 - 1 ) {
( * V_254 ) ++ ;
V_22 = 0 ;
} else if ( * V_254 >= V_30 )
( * V_254 ) += 2 ;
V_21 = 1 ;
break;
case V_273 :
V_256 += 1 ;
V_30 = V_25 - 1 - F_143 ( V_256 , V_25 ) ;
V_22 = V_30 + 1 ;
if ( V_30 == V_25 - 1 ) {
( * V_254 ) ++ ;
V_22 = 0 ;
} else if ( * V_254 >= V_30 )
( * V_254 ) += 2 ;
V_21 = 1 ;
break;
case V_274 :
V_30 = V_25 - 1 - F_143 ( V_256 , V_25 ) ;
V_22 = ( V_30 + V_25 - 1 ) % V_25 ;
* V_254 = ( V_30 + 1 + * V_254 ) % V_25 ;
V_21 = 1 ;
break;
case V_275 :
V_30 = V_265 - F_143 ( V_256 , V_25 - 1 ) ;
if ( * V_254 >= V_30 )
( * V_254 ) ++ ;
V_22 = V_25 - 1 ;
break;
case V_276 :
V_30 = F_143 ( V_256 , V_25 - 1 ) ;
if ( * V_254 >= V_30 )
( * V_254 ) ++ ;
V_22 = V_25 - 1 ;
break;
case V_277 :
V_30 = V_265 - F_143 ( V_256 , V_25 - 1 ) ;
* V_254 = ( V_30 + 1 + * V_254 ) % ( V_25 - 1 ) ;
V_22 = V_25 - 1 ;
break;
case V_278 :
V_30 = F_143 ( V_256 , V_25 - 1 ) ;
* V_254 = ( V_30 + 1 + * V_254 ) % ( V_25 - 1 ) ;
V_22 = V_25 - 1 ;
break;
case V_279 :
V_30 = 0 ;
( * V_254 ) ++ ;
V_22 = V_25 - 1 ;
break;
default:
F_56 () ;
}
break;
}
if ( V_20 ) {
V_20 -> V_30 = V_30 ;
V_20 -> V_22 = V_22 ;
V_20 -> V_21 = V_21 ;
}
V_259 = ( T_1 ) V_255 * V_262 + V_258 ;
return V_259 ;
}
static T_1 F_141 ( struct V_19 * V_20 , int V_67 , int V_72 )
{
struct V_2 * V_3 = V_20 -> V_57 ;
int V_25 = V_20 -> V_23 ;
int V_265 = V_25 - V_3 -> V_87 ;
T_1 V_259 = V_20 -> V_10 , V_280 ;
int V_262 = V_72 ? V_3 -> V_263
: V_3 -> V_264 ;
int V_260 = V_72 ? V_3 -> V_261
: V_3 -> V_260 ;
T_1 V_255 ;
int V_258 ;
T_1 V_257 ;
int V_281 , V_254 = V_67 ;
T_1 V_253 ;
struct V_19 V_282 ;
V_258 = F_143 ( V_259 , V_262 ) ;
V_255 = V_259 ;
if ( V_67 == V_20 -> V_30 )
return 0 ;
switch( V_3 -> V_199 ) {
case 4 : break;
case 5 :
switch ( V_260 ) {
case V_266 :
case V_267 :
if ( V_67 > V_20 -> V_30 )
V_67 -- ;
break;
case V_268 :
case V_269 :
if ( V_67 < V_20 -> V_30 )
V_67 += V_25 ;
V_67 -= ( V_20 -> V_30 + 1 ) ;
break;
case V_270 :
V_67 -= 1 ;
break;
case V_271 :
break;
default:
F_56 () ;
}
break;
case 6 :
if ( V_67 == V_20 -> V_22 )
return 0 ;
switch ( V_260 ) {
case V_266 :
case V_267 :
case V_272 :
case V_273 :
if ( V_20 -> V_30 == V_25 - 1 )
V_67 -- ;
else if ( V_67 > V_20 -> V_30 )
V_67 -= 2 ;
break;
case V_268 :
case V_269 :
if ( V_20 -> V_30 == V_25 - 1 )
V_67 -- ;
else {
if ( V_67 < V_20 -> V_30 )
V_67 += V_25 ;
V_67 -= ( V_20 -> V_30 + 2 ) ;
}
break;
case V_270 :
V_67 -= 2 ;
break;
case V_271 :
break;
case V_274 :
if ( V_20 -> V_30 == 0 )
V_67 -- ;
else {
if ( V_67 < V_20 -> V_30 )
V_67 += V_25 ;
V_67 -= ( V_20 -> V_30 + 1 ) ;
}
break;
case V_275 :
case V_276 :
if ( V_67 > V_20 -> V_30 )
V_67 -- ;
break;
case V_277 :
case V_278 :
if ( V_67 < V_20 -> V_30 )
V_67 += V_265 + 1 ;
V_67 -= ( V_20 -> V_30 + 1 ) ;
break;
case V_279 :
V_67 -= 1 ;
break;
default:
F_56 () ;
}
break;
}
V_257 = V_255 * V_265 + V_67 ;
V_253 = V_257 * V_262 + V_258 ;
V_280 = F_142 ( V_3 , V_253 ,
V_72 , & V_281 , & V_282 ) ;
if ( V_280 != V_20 -> V_10 || V_281 != V_254 || V_282 . V_30 != V_20 -> V_30
|| V_282 . V_22 != V_20 -> V_22 ) {
F_44 ( V_81 L_29 ,
F_118 ( V_3 -> V_48 ) ) ;
return 0 ;
}
return V_253 ;
}
static void
F_144 ( struct V_19 * V_20 , struct V_97 * V_98 ,
int V_283 , int V_284 )
{
int V_67 , V_30 = V_20 -> V_30 , V_23 = V_20 -> V_23 ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_199 = V_3 -> V_199 ;
if ( V_283 ) {
if ( ! V_284 ) {
V_20 -> V_34 = V_186 ;
F_61 ( V_205 , & V_98 -> V_197 ) ;
} else
V_20 -> V_34 = V_190 ;
F_61 ( V_203 , & V_98 -> V_197 ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( V_70 -> V_78 ) {
F_61 ( V_80 , & V_70 -> V_58 ) ;
F_61 ( V_180 , & V_70 -> V_58 ) ;
if ( ! V_284 )
F_21 ( V_160 , & V_70 -> V_58 ) ;
V_98 -> V_285 ++ ;
}
}
if ( V_98 -> V_285 + V_3 -> V_87 == V_23 )
if ( ! F_145 ( V_286 , & V_20 -> V_36 ) )
F_37 ( & V_3 -> V_287 ) ;
} else {
F_17 ( V_199 == 6 ) ;
F_17 ( ! ( F_14 ( V_160 , & V_20 -> V_70 [ V_30 ] . V_58 ) ||
F_14 ( V_161 , & V_20 -> V_70 [ V_30 ] . V_58 ) ) ) ;
V_20 -> V_34 = V_188 ;
F_61 ( V_204 , & V_98 -> V_197 ) ;
F_61 ( V_205 , & V_98 -> V_197 ) ;
F_61 ( V_203 , & V_98 -> V_197 ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( V_67 == V_30 )
continue;
if ( V_70 -> V_78 &&
( F_14 ( V_160 , & V_70 -> V_58 ) ||
F_14 ( V_161 , & V_70 -> V_58 ) ) ) {
F_61 ( V_180 , & V_70 -> V_58 ) ;
F_61 ( V_80 , & V_70 -> V_58 ) ;
F_21 ( V_160 , & V_70 -> V_58 ) ;
V_98 -> V_285 ++ ;
}
}
}
F_61 ( V_80 , & V_20 -> V_70 [ V_30 ] . V_58 ) ;
F_21 ( V_160 , & V_20 -> V_70 [ V_30 ] . V_58 ) ;
V_98 -> V_285 ++ ;
if ( V_199 == 6 ) {
int V_22 = V_20 -> V_22 ;
struct V_75 * V_70 = & V_20 -> V_70 [ V_22 ] ;
F_61 ( V_80 , & V_70 -> V_58 ) ;
F_21 ( V_160 , & V_70 -> V_58 ) ;
V_98 -> V_285 ++ ;
}
F_30 ( L_30 ,
V_124 , ( unsigned long long ) V_20 -> V_10 ,
V_98 -> V_285 , V_98 -> V_197 ) ;
}
static int F_146 ( struct V_19 * V_20 , struct V_9 * V_32 , int V_254 , int V_288 )
{
struct V_9 * * V_289 ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_290 = 0 ;
F_30 ( L_31 ,
( unsigned long long ) V_32 -> V_13 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_54 ( & V_3 -> V_59 ) ;
if ( V_288 ) {
V_289 = & V_20 -> V_70 [ V_254 ] . V_78 ;
if ( * V_289 == NULL && V_20 -> V_70 [ V_254 ] . V_79 == NULL )
V_290 = 1 ;
} else
V_289 = & V_20 -> V_70 [ V_254 ] . V_76 ;
while ( * V_289 && ( * V_289 ) -> V_13 < V_32 -> V_13 ) {
if ( ( * V_289 ) -> V_13 + ( ( * V_289 ) -> V_12 >> 9 ) > V_32 -> V_13 )
goto V_291;
V_289 = & ( * V_289 ) -> V_15 ;
}
if ( * V_289 && ( * V_289 ) -> V_13 < V_32 -> V_13 + ( ( V_32 -> V_12 ) >> 9 ) )
goto V_291;
F_17 ( * V_289 && V_32 -> V_15 && ( * V_289 ) != V_32 -> V_15 ) ;
if ( * V_289 )
V_32 -> V_15 = * V_289 ;
* V_289 = V_32 ;
V_32 -> V_16 ++ ;
if ( V_288 ) {
T_1 V_10 = V_20 -> V_70 [ V_254 ] . V_10 ;
for ( V_32 = V_20 -> V_70 [ V_254 ] . V_78 ;
V_10 < V_20 -> V_70 [ V_254 ] . V_10 + V_14 &&
V_32 && V_32 -> V_13 <= V_10 ;
V_32 = F_2 ( V_32 , V_20 -> V_70 [ V_254 ] . V_10 ) ) {
if ( V_32 -> V_13 + ( V_32 -> V_12 >> 9 ) >= V_10 )
V_10 = V_32 -> V_13 + ( V_32 -> V_12 >> 9 ) ;
}
if ( V_10 >= V_20 -> V_70 [ V_254 ] . V_10 + V_14 )
F_61 ( V_292 , & V_20 -> V_70 [ V_254 ] . V_58 ) ;
}
F_57 ( & V_3 -> V_59 ) ;
F_30 ( L_32 ,
( unsigned long long ) ( * V_289 ) -> V_13 ,
( unsigned long long ) V_20 -> V_10 , V_254 ) ;
if ( V_3 -> V_48 -> V_293 && V_290 ) {
F_147 ( V_3 -> V_48 -> V_293 , V_20 -> V_10 ,
V_14 , 0 ) ;
V_20 -> V_44 = V_3 -> V_294 + 1 ;
F_61 ( V_43 , & V_20 -> V_36 ) ;
}
return 1 ;
V_291:
F_61 ( V_210 , & V_20 -> V_70 [ V_254 ] . V_58 ) ;
F_57 ( & V_3 -> V_59 ) ;
return 0 ;
}
static void F_43 ( T_1 V_255 , struct V_2 * V_3 , int V_72 ,
struct V_19 * V_20 )
{
int V_262 =
V_72 ? V_3 -> V_263 : V_3 -> V_264 ;
int V_254 ;
int V_258 = F_143 ( V_255 , V_262 ) ;
int V_23 = V_72 ? V_3 -> V_74 : V_3 -> V_25 ;
F_142 ( V_3 ,
V_255 * ( V_23 - V_3 -> V_87 )
* V_262 + V_258 ,
V_72 ,
& V_254 , V_20 ) ;
}
static void
F_148 ( struct V_2 * V_3 , struct V_19 * V_20 ,
struct V_97 * V_98 , int V_23 ,
struct V_9 * * V_31 )
{
int V_67 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_9 * V_32 ;
int V_295 = 0 ;
if ( F_14 ( V_237 , & V_20 -> V_70 [ V_67 ] . V_58 ) ) {
struct V_88 * V_89 ;
F_50 () ;
V_89 = F_51 ( V_3 -> V_23 [ V_67 ] . V_89 ) ;
if ( V_89 && F_14 ( V_91 , & V_89 -> V_58 ) )
F_37 ( & V_89 -> V_111 ) ;
else
V_89 = NULL ;
F_52 () ;
if ( V_89 ) {
if ( ! F_149 (
V_89 ,
V_20 -> V_10 ,
V_14 , 0 ) )
F_139 ( V_3 -> V_48 , V_89 ) ;
F_64 ( V_89 , V_3 -> V_48 ) ;
}
}
F_54 ( & V_3 -> V_59 ) ;
V_32 = V_20 -> V_70 [ V_67 ] . V_78 ;
V_20 -> V_70 [ V_67 ] . V_78 = NULL ;
if ( V_32 ) {
V_98 -> V_296 -- ;
V_295 = 1 ;
}
if ( F_23 ( V_210 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
F_25 ( & V_3 -> V_211 ) ;
while ( V_32 && V_32 -> V_13 <
V_20 -> V_70 [ V_67 ] . V_10 + V_14 ) {
struct V_9 * V_297 = F_2 ( V_32 , V_20 -> V_70 [ V_67 ] . V_10 ) ;
F_21 ( V_127 , & V_32 -> V_126 ) ;
if ( ! F_5 ( V_32 ) ) {
F_150 ( V_3 -> V_48 ) ;
V_32 -> V_15 = * V_31 ;
* V_31 = V_32 ;
}
V_32 = V_297 ;
}
V_32 = V_20 -> V_70 [ V_67 ] . V_79 ;
V_20 -> V_70 [ V_67 ] . V_79 = NULL ;
if ( V_32 ) V_295 = 1 ;
while ( V_32 && V_32 -> V_13 <
V_20 -> V_70 [ V_67 ] . V_10 + V_14 ) {
struct V_9 * V_298 = F_2 ( V_32 , V_20 -> V_70 [ V_67 ] . V_10 ) ;
F_21 ( V_127 , & V_32 -> V_126 ) ;
if ( ! F_5 ( V_32 ) ) {
F_150 ( V_3 -> V_48 ) ;
V_32 -> V_15 = * V_31 ;
* V_31 = V_32 ;
}
V_32 = V_298 ;
}
if ( ! F_14 ( V_154 , & V_20 -> V_70 [ V_67 ] . V_58 ) &&
( ! F_14 ( V_299 , & V_20 -> V_70 [ V_67 ] . V_58 ) ||
F_14 ( V_237 , & V_20 -> V_70 [ V_67 ] . V_58 ) ) ) {
V_32 = V_20 -> V_70 [ V_67 ] . V_76 ;
V_20 -> V_70 [ V_67 ] . V_76 = NULL ;
if ( F_23 ( V_210 , & V_20 -> V_70 [ V_67 ] . V_58 ) )
F_25 ( & V_3 -> V_211 ) ;
if ( V_32 ) V_98 -> V_300 -- ;
while ( V_32 && V_32 -> V_13 <
V_20 -> V_70 [ V_67 ] . V_10 + V_14 ) {
struct V_9 * V_297 =
F_2 ( V_32 , V_20 -> V_70 [ V_67 ] . V_10 ) ;
F_21 ( V_127 , & V_32 -> V_126 ) ;
if ( ! F_5 ( V_32 ) ) {
V_32 -> V_15 = * V_31 ;
* V_31 = V_32 ;
}
V_32 = V_297 ;
}
}
F_57 ( & V_3 -> V_59 ) ;
if ( V_295 )
F_151 ( V_3 -> V_48 -> V_293 , V_20 -> V_10 ,
V_14 , 0 , 0 ) ;
F_21 ( V_80 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
}
if ( F_23 ( V_286 , & V_20 -> V_36 ) )
if ( F_16 ( & V_3 -> V_287 ) )
F_22 ( V_3 -> V_48 -> V_49 ) ;
}
static void
F_152 ( struct V_2 * V_3 , struct V_19 * V_20 ,
struct V_97 * V_98 )
{
int abort = 0 ;
int V_67 ;
F_153 ( V_3 -> V_48 , V_14 , 0 ) ;
F_21 ( V_301 , & V_20 -> V_36 ) ;
V_98 -> V_118 = 0 ;
if ( ! F_14 ( V_302 , & V_3 -> V_48 -> V_249 ) )
return;
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ ) {
struct V_88 * V_89 = V_3 -> V_23 [ V_67 ] . V_89 ;
if ( ! V_89
|| F_14 ( V_90 , & V_89 -> V_58 )
|| F_14 ( V_91 , & V_89 -> V_58 ) )
continue;
if ( ! F_149 ( V_89 , V_20 -> V_10 ,
V_14 , 0 ) )
abort = 1 ;
}
if ( abort ) {
V_3 -> V_303 = V_3 -> V_48 -> V_303 ;
F_61 ( V_248 , & V_3 -> V_48 -> V_249 ) ;
}
}
static int F_154 ( struct V_19 * V_20 , struct V_97 * V_98 ,
int V_304 , int V_23 )
{
struct V_75 * V_70 = & V_20 -> V_70 [ V_304 ] ;
struct V_75 * V_305 [ 2 ] = { & V_20 -> V_70 [ V_98 -> V_306 [ 0 ] ] ,
& V_20 -> V_70 [ V_98 -> V_306 [ 1 ] ] } ;
if ( ! F_14 ( V_80 , & V_70 -> V_58 ) &&
! F_14 ( V_160 , & V_70 -> V_58 ) &&
( V_70 -> V_76 ||
( V_70 -> V_78 && ! F_14 ( V_292 , & V_70 -> V_58 ) ) ||
V_98 -> V_118 || V_98 -> V_119 ||
( V_98 -> V_307 >= 1 && V_305 [ 0 ] -> V_76 ) ||
( V_98 -> V_307 >= 2 && V_305 [ 1 ] -> V_76 ) ||
( V_20 -> V_57 -> V_199 <= 5 && V_98 -> V_307 && V_305 [ 0 ] -> V_78 &&
! F_14 ( V_292 , & V_305 [ 0 ] -> V_58 ) ) ||
( V_20 -> V_57 -> V_199 == 6 && V_98 -> V_307 && V_98 -> V_296 ) ) ) {
F_17 ( F_14 ( V_161 , & V_70 -> V_58 ) ) ;
F_17 ( F_14 ( V_104 , & V_70 -> V_58 ) ) ;
if ( ( V_98 -> V_234 == V_23 - 1 ) &&
( V_98 -> V_307 && ( V_304 == V_98 -> V_306 [ 0 ] ||
V_304 == V_98 -> V_306 [ 1 ] ) ) ) {
F_30 ( L_33 ,
( unsigned long long ) V_20 -> V_10 , V_304 ) ;
F_61 ( V_37 , & V_20 -> V_36 ) ;
F_61 ( V_202 , & V_98 -> V_197 ) ;
F_61 ( V_161 , & V_70 -> V_58 ) ;
V_20 -> V_162 . V_158 = V_304 ;
V_20 -> V_162 . V_163 = - 1 ;
V_98 -> V_308 = 1 ;
V_98 -> V_234 ++ ;
return 1 ;
} else if ( V_98 -> V_234 == V_23 - 2 && V_98 -> V_307 >= 2 ) {
int V_309 ;
for ( V_309 = V_23 ; V_309 -- ; ) {
if ( V_309 == V_304 )
continue;
if ( ! F_14 ( V_160 ,
& V_20 -> V_70 [ V_309 ] . V_58 ) )
break;
}
F_17 ( V_309 < 0 ) ;
F_30 ( L_34 ,
( unsigned long long ) V_20 -> V_10 ,
V_304 , V_309 ) ;
F_61 ( V_37 , & V_20 -> V_36 ) ;
F_61 ( V_202 , & V_98 -> V_197 ) ;
F_61 ( V_161 , & V_20 -> V_70 [ V_304 ] . V_58 ) ;
F_61 ( V_161 , & V_20 -> V_70 [ V_309 ] . V_58 ) ;
V_20 -> V_162 . V_158 = V_304 ;
V_20 -> V_162 . V_163 = V_309 ;
V_98 -> V_234 += 2 ;
V_98 -> V_308 = 1 ;
return 1 ;
} else if ( F_14 ( V_299 , & V_70 -> V_58 ) ) {
F_61 ( V_80 , & V_70 -> V_58 ) ;
F_61 ( V_104 , & V_70 -> V_58 ) ;
V_98 -> V_285 ++ ;
F_30 ( L_35 ,
V_304 , V_98 -> V_118 ) ;
}
}
return 0 ;
}
static void F_155 ( struct V_19 * V_20 ,
struct V_97 * V_98 ,
int V_23 )
{
int V_67 ;
if ( ! F_14 ( V_37 , & V_20 -> V_36 ) && ! V_20 -> V_33 &&
! V_20 -> V_34 )
for ( V_67 = V_23 ; V_67 -- ; )
if ( F_154 ( V_20 , V_98 , V_67 , V_23 ) )
break;
F_61 ( V_40 , & V_20 -> V_36 ) ;
}
static void F_156 ( struct V_2 * V_3 ,
struct V_19 * V_20 , int V_23 , struct V_9 * * V_31 )
{
int V_67 ;
struct V_75 * V_70 ;
for ( V_67 = V_23 ; V_67 -- ; )
if ( V_20 -> V_70 [ V_67 ] . V_79 ) {
V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( ! F_14 ( V_80 , & V_70 -> V_58 ) &&
F_14 ( V_160 , & V_70 -> V_58 ) ) {
struct V_9 * V_183 , * V_310 ;
int V_295 = 0 ;
F_30 ( L_36 , V_67 ) ;
F_54 ( & V_3 -> V_59 ) ;
V_183 = V_70 -> V_79 ;
V_70 -> V_79 = NULL ;
while ( V_183 && V_183 -> V_13 <
V_70 -> V_10 + V_14 ) {
V_310 = F_2 ( V_183 , V_70 -> V_10 ) ;
if ( ! F_5 ( V_183 ) ) {
F_150 ( V_3 -> V_48 ) ;
V_183 -> V_15 = * V_31 ;
* V_31 = V_183 ;
}
V_183 = V_310 ;
}
if ( V_70 -> V_78 == NULL )
V_295 = 1 ;
F_57 ( & V_3 -> V_59 ) ;
if ( V_295 )
F_151 ( V_3 -> V_48 -> V_293 ,
V_20 -> V_10 ,
V_14 ,
! F_14 ( V_136 , & V_20 -> V_36 ) ,
0 ) ;
}
}
if ( F_23 ( V_286 , & V_20 -> V_36 ) )
if ( F_16 ( & V_3 -> V_287 ) )
F_22 ( V_3 -> V_48 -> V_49 ) ;
}
static void F_157 ( struct V_2 * V_3 ,
struct V_19 * V_20 ,
struct V_97 * V_98 ,
int V_23 )
{
int V_311 = 0 , V_283 = 0 , V_67 ;
if ( V_3 -> V_87 == 2 ) {
V_283 = 1 ; V_311 = 2 ;
} else for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( ( V_70 -> V_78 || V_67 == V_20 -> V_30 ) &&
! F_14 ( V_80 , & V_70 -> V_58 ) &&
! ( F_14 ( V_160 , & V_70 -> V_58 ) ||
F_14 ( V_161 , & V_70 -> V_58 ) ) ) {
if ( F_14 ( V_299 , & V_70 -> V_58 ) )
V_311 ++ ;
else
V_311 += 2 * V_23 ;
}
if ( ! F_14 ( V_292 , & V_70 -> V_58 ) && V_67 != V_20 -> V_30 &&
! F_14 ( V_80 , & V_70 -> V_58 ) &&
! ( F_14 ( V_160 , & V_70 -> V_58 ) ||
F_14 ( V_161 , & V_70 -> V_58 ) ) ) {
if ( F_14 ( V_299 , & V_70 -> V_58 ) ) V_283 ++ ;
else
V_283 += 2 * V_23 ;
}
}
F_30 ( L_37 ,
( unsigned long long ) V_20 -> V_10 , V_311 , V_283 ) ;
F_61 ( V_40 , & V_20 -> V_36 ) ;
if ( V_311 < V_283 && V_311 > 0 )
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( ( V_70 -> V_78 || V_67 == V_20 -> V_30 ) &&
! F_14 ( V_80 , & V_70 -> V_58 ) &&
! ( F_14 ( V_160 , & V_70 -> V_58 ) ||
F_14 ( V_161 , & V_70 -> V_58 ) ) &&
F_14 ( V_299 , & V_70 -> V_58 ) ) {
if (
F_14 ( V_50 , & V_20 -> V_36 ) ) {
F_30 ( L_38
L_39 , V_67 ) ;
F_61 ( V_80 , & V_70 -> V_58 ) ;
F_61 ( V_104 , & V_70 -> V_58 ) ;
V_98 -> V_285 ++ ;
} else {
F_61 ( V_41 , & V_20 -> V_36 ) ;
F_61 ( V_40 , & V_20 -> V_36 ) ;
}
}
}
if ( V_283 <= V_311 && V_283 > 0 ) {
V_283 = 0 ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( ! F_14 ( V_292 , & V_70 -> V_58 ) &&
V_67 != V_20 -> V_30 && V_67 != V_20 -> V_22 &&
! F_14 ( V_80 , & V_70 -> V_58 ) &&
! ( F_14 ( V_160 , & V_70 -> V_58 ) ||
F_14 ( V_161 , & V_70 -> V_58 ) ) ) {
V_283 ++ ;
if ( ! F_14 ( V_299 , & V_70 -> V_58 ) )
continue;
if (
F_14 ( V_50 , & V_20 -> V_36 ) ) {
F_30 ( L_38
L_40 , V_67 ) ;
F_61 ( V_80 , & V_70 -> V_58 ) ;
F_61 ( V_104 , & V_70 -> V_58 ) ;
V_98 -> V_285 ++ ;
} else {
F_61 ( V_41 , & V_20 -> V_36 ) ;
F_61 ( V_40 , & V_20 -> V_36 ) ;
}
}
}
}
if ( ( V_98 -> V_308 || ! F_14 ( V_37 , & V_20 -> V_36 ) ) &&
( V_98 -> V_285 == 0 && ( V_283 == 0 || V_311 == 0 ) &&
! F_14 ( V_43 , & V_20 -> V_36 ) ) )
F_144 ( V_20 , V_98 , V_283 == 0 , 0 ) ;
}
static void F_158 ( struct V_2 * V_3 , struct V_19 * V_20 ,
struct V_97 * V_98 , int V_23 )
{
struct V_75 * V_70 = NULL ;
F_61 ( V_40 , & V_20 -> V_36 ) ;
switch ( V_20 -> V_33 ) {
case V_312 :
if ( V_98 -> V_307 == 0 ) {
F_17 ( V_98 -> V_234 != V_23 ) ;
V_20 -> V_33 = V_207 ;
F_61 ( V_206 , & V_98 -> V_197 ) ;
F_21 ( V_160 , & V_20 -> V_70 [ V_20 -> V_30 ] . V_58 ) ;
V_98 -> V_234 -- ;
break;
}
V_70 = & V_20 -> V_70 [ V_98 -> V_306 [ 0 ] ] ;
case V_165 :
V_20 -> V_33 = V_312 ;
if ( ! V_70 )
V_70 = & V_20 -> V_70 [ V_20 -> V_30 ] ;
if ( F_14 ( V_313 , & V_20 -> V_36 ) )
break;
F_17 ( ! F_14 ( V_160 , & V_70 -> V_58 ) ) ;
F_17 ( V_98 -> V_234 != V_23 ) ;
F_61 ( V_80 , & V_70 -> V_58 ) ;
V_98 -> V_285 ++ ;
F_61 ( V_100 , & V_70 -> V_58 ) ;
F_21 ( V_136 , & V_20 -> V_36 ) ;
F_61 ( V_313 , & V_20 -> V_36 ) ;
break;
case V_207 :
break;
case V_193 :
V_20 -> V_33 = V_312 ;
if ( V_98 -> V_307 )
break;
if ( ( V_20 -> V_162 . V_194 & V_314 ) == 0 )
F_61 ( V_313 , & V_20 -> V_36 ) ;
else {
V_3 -> V_48 -> V_315 += V_14 ;
if ( F_14 ( V_316 , & V_3 -> V_48 -> V_249 ) )
F_61 ( V_313 , & V_20 -> V_36 ) ;
else {
V_20 -> V_33 = V_164 ;
F_61 ( V_37 , & V_20 -> V_36 ) ;
F_61 ( V_202 , & V_98 -> V_197 ) ;
F_61 ( V_161 ,
& V_20 -> V_70 [ V_20 -> V_30 ] . V_58 ) ;
V_20 -> V_162 . V_158 = V_20 -> V_30 ;
V_20 -> V_162 . V_163 = - 1 ;
V_98 -> V_234 ++ ;
}
}
break;
case V_164 :
break;
default:
F_44 ( V_81 L_41 ,
V_124 , V_20 -> V_33 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_56 () ;
}
}
static void F_159 ( struct V_2 * V_3 , struct V_19 * V_20 ,
struct V_97 * V_98 ,
int V_23 )
{
int V_30 = V_20 -> V_30 ;
int V_22 = V_20 -> V_22 ;
struct V_75 * V_70 ;
F_61 ( V_40 , & V_20 -> V_36 ) ;
F_17 ( V_98 -> V_307 > 2 ) ;
switch ( V_20 -> V_33 ) {
case V_312 :
if ( V_98 -> V_307 == V_98 -> V_317 ) {
V_20 -> V_33 = V_207 ;
}
if ( ! V_98 -> V_317 && V_98 -> V_307 < 2 ) {
if ( V_20 -> V_33 == V_207 )
V_20 -> V_33 = V_209 ;
else
V_20 -> V_33 = V_208 ;
}
V_20 -> V_162 . V_194 = 0 ;
if ( V_20 -> V_33 == V_207 ) {
F_21 ( V_160 , & V_20 -> V_70 [ V_30 ] . V_58 ) ;
V_98 -> V_234 -- ;
}
if ( V_20 -> V_33 >= V_207 &&
V_20 -> V_33 <= V_209 ) {
F_61 ( V_206 , & V_98 -> V_197 ) ;
break;
}
F_17 ( V_98 -> V_307 != 2 ) ;
case V_165 :
V_20 -> V_33 = V_312 ;
if ( F_14 ( V_313 , & V_20 -> V_36 ) )
break;
F_17 ( V_98 -> V_234 < V_23 - 1 ) ;
if ( V_98 -> V_307 == 2 ) {
V_70 = & V_20 -> V_70 [ V_98 -> V_306 [ 1 ] ] ;
V_98 -> V_285 ++ ;
F_61 ( V_80 , & V_70 -> V_58 ) ;
F_61 ( V_100 , & V_70 -> V_58 ) ;
}
if ( V_98 -> V_307 >= 1 ) {
V_70 = & V_20 -> V_70 [ V_98 -> V_306 [ 0 ] ] ;
V_98 -> V_285 ++ ;
F_61 ( V_80 , & V_70 -> V_58 ) ;
F_61 ( V_100 , & V_70 -> V_58 ) ;
}
if ( V_20 -> V_162 . V_194 & V_314 ) {
V_70 = & V_20 -> V_70 [ V_30 ] ;
V_98 -> V_285 ++ ;
F_61 ( V_80 , & V_70 -> V_58 ) ;
F_61 ( V_100 , & V_70 -> V_58 ) ;
}
if ( V_20 -> V_162 . V_194 & V_318 ) {
V_70 = & V_20 -> V_70 [ V_22 ] ;
V_98 -> V_285 ++ ;
F_61 ( V_80 , & V_70 -> V_58 ) ;
F_61 ( V_100 , & V_70 -> V_58 ) ;
}
F_21 ( V_136 , & V_20 -> V_36 ) ;
F_61 ( V_313 , & V_20 -> V_36 ) ;
break;
case V_207 :
case V_208 :
case V_209 :
break;
case V_193 :
V_20 -> V_33 = V_312 ;
if ( V_20 -> V_162 . V_194 == 0 ) {
if ( ! V_98 -> V_307 )
F_61 ( V_313 , & V_20 -> V_36 ) ;
else {
V_20 -> V_33 = V_165 ;
}
} else {
V_3 -> V_48 -> V_315 += V_14 ;
if ( F_14 ( V_316 , & V_3 -> V_48 -> V_249 ) )
F_61 ( V_313 , & V_20 -> V_36 ) ;
else {
int * V_158 = & V_20 -> V_162 . V_158 ;
V_20 -> V_162 . V_158 = - 1 ;
V_20 -> V_162 . V_163 = - 1 ;
V_20 -> V_33 = V_164 ;
F_61 ( V_37 , & V_20 -> V_36 ) ;
F_61 ( V_202 , & V_98 -> V_197 ) ;
if ( V_20 -> V_162 . V_194 & V_314 ) {
F_61 ( V_161 ,
& V_20 -> V_70 [ V_30 ] . V_58 ) ;
* V_158 = V_30 ;
V_158 = & V_20 -> V_162 . V_163 ;
V_98 -> V_234 ++ ;
}
if ( V_20 -> V_162 . V_194 & V_318 ) {
F_61 ( V_161 ,
& V_20 -> V_70 [ V_22 ] . V_58 ) ;
* V_158 = V_22 ;
V_98 -> V_234 ++ ;
}
}
}
break;
case V_164 :
break;
default:
F_44 ( V_81 L_41 ,
V_124 , V_20 -> V_33 ,
( unsigned long long ) V_20 -> V_10 ) ;
F_56 () ;
}
}
static void F_160 ( struct V_2 * V_3 , struct V_19 * V_20 )
{
int V_67 ;
struct V_137 * V_139 = NULL ;
F_21 ( V_319 , & V_20 -> V_36 ) ;
for ( V_67 = 0 ; V_67 < V_20 -> V_23 ; V_67 ++ )
if ( V_67 != V_20 -> V_30 && V_67 != V_20 -> V_22 ) {
int V_254 , V_320 ;
struct V_19 * V_282 ;
struct V_144 V_145 ;
T_1 V_321 = F_141 ( V_20 , V_67 , 1 ) ;
T_1 V_98 = F_142 ( V_3 , V_321 , 0 ,
& V_254 , NULL ) ;
V_282 = F_53 ( V_3 , V_98 , 0 , 1 , 1 ) ;
if ( V_282 == NULL )
continue;
if ( ! F_14 ( V_53 , & V_282 -> V_36 ) ||
F_14 ( V_322 , & V_282 -> V_70 [ V_254 ] . V_58 ) ) {
F_26 ( V_282 ) ;
continue;
}
F_68 ( & V_145 , 0 , V_139 , NULL , NULL , NULL ) ;
V_139 = F_70 ( V_282 -> V_70 [ V_254 ] . V_65 ,
V_20 -> V_70 [ V_67 ] . V_65 , 0 , 0 , V_134 ,
& V_145 ) ;
F_61 ( V_322 , & V_282 -> V_70 [ V_254 ] . V_58 ) ;
F_61 ( V_160 , & V_282 -> V_70 [ V_254 ] . V_58 ) ;
for ( V_320 = 0 ; V_320 < V_3 -> V_25 ; V_320 ++ )
if ( V_320 != V_282 -> V_30 &&
V_320 != V_282 -> V_22 &&
! F_14 ( V_322 , & V_282 -> V_70 [ V_320 ] . V_58 ) )
break;
if ( V_320 == V_3 -> V_25 ) {
F_61 ( V_323 , & V_282 -> V_36 ) ;
F_61 ( V_40 , & V_282 -> V_36 ) ;
}
F_26 ( V_282 ) ;
}
if ( V_139 ) {
F_101 ( V_139 ) ;
F_161 ( V_139 ) ;
}
}
static void F_162 ( struct V_19 * V_20 , struct V_97 * V_98 )
{
struct V_2 * V_3 = V_20 -> V_57 ;
int V_23 = V_20 -> V_23 ;
struct V_75 * V_70 ;
int V_67 ;
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
V_98 -> V_118 = F_14 ( V_301 , & V_20 -> V_36 ) ;
V_98 -> V_119 = F_14 ( V_319 , & V_20 -> V_36 ) ;
V_98 -> V_120 = F_14 ( V_323 , & V_20 -> V_36 ) ;
V_98 -> V_306 [ 0 ] = - 1 ;
V_98 -> V_306 [ 1 ] = - 1 ;
F_50 () ;
F_54 ( & V_3 -> V_59 ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_88 * V_89 ;
T_1 V_113 ;
int V_114 ;
int V_324 = 0 ;
V_70 = & V_20 -> V_70 [ V_67 ] ;
F_30 ( L_42 ,
V_67 , V_70 -> V_58 , V_70 -> V_76 , V_70 -> V_78 , V_70 -> V_79 ) ;
if ( F_14 ( V_160 , & V_70 -> V_58 ) && V_70 -> V_76 &&
! F_14 ( V_35 , & V_20 -> V_36 ) )
F_61 ( V_154 , & V_70 -> V_58 ) ;
if ( F_14 ( V_80 , & V_70 -> V_58 ) )
V_98 -> V_285 ++ ;
if ( F_14 ( V_160 , & V_70 -> V_58 ) )
V_98 -> V_234 ++ ;
if ( F_14 ( V_161 , & V_70 -> V_58 ) ) {
V_98 -> V_325 ++ ;
F_17 ( V_98 -> V_325 > 2 ) ;
}
if ( F_14 ( V_154 , & V_70 -> V_58 ) )
V_98 -> V_326 ++ ;
else if ( V_70 -> V_76 )
V_98 -> V_300 ++ ;
if ( V_70 -> V_78 ) {
V_98 -> V_296 ++ ;
if ( ! F_14 ( V_292 , & V_70 -> V_58 ) )
V_98 -> V_327 ++ ;
}
if ( V_70 -> V_79 )
V_98 -> V_79 ++ ;
V_89 = F_51 ( V_3 -> V_23 [ V_67 ] . V_89 ) ;
if ( V_89 && F_14 ( V_90 , & V_89 -> V_58 ) )
V_89 = NULL ;
if ( V_89 ) {
V_324 = F_60 ( V_89 , V_20 -> V_10 , V_14 ,
& V_113 , & V_114 ) ;
if ( V_98 -> V_328 == NULL
&& ( F_14 ( V_250 , & V_89 -> V_58 )
|| V_324 < 0 ) ) {
if ( V_324 < 0 )
F_61 ( V_116 ,
& V_89 -> V_58 ) ;
V_98 -> V_328 = V_89 ;
F_37 ( & V_89 -> V_111 ) ;
}
}
F_21 ( V_299 , & V_70 -> V_58 ) ;
if ( ! V_89 )
;
else if ( V_324 ) {
if ( ! F_14 ( V_112 , & V_89 -> V_58 ) ) {
F_61 ( V_299 , & V_70 -> V_58 ) ;
F_61 ( V_237 , & V_70 -> V_58 ) ;
}
} else if ( F_14 ( V_91 , & V_89 -> V_58 ) )
F_61 ( V_299 , & V_70 -> V_58 ) ;
else if ( V_20 -> V_10 + V_14 <= V_89 -> V_329 )
F_61 ( V_299 , & V_70 -> V_58 ) ;
else if ( F_14 ( V_160 , & V_70 -> V_58 ) &&
F_14 ( V_322 , & V_70 -> V_58 ) )
F_61 ( V_299 , & V_70 -> V_58 ) ;
if ( V_89 && F_14 ( V_245 , & V_70 -> V_58 ) ) {
F_21 ( V_299 , & V_70 -> V_58 ) ;
if ( ! F_14 ( V_90 , & V_89 -> V_58 ) ) {
V_98 -> V_330 = 1 ;
F_37 ( & V_89 -> V_111 ) ;
} else
F_21 ( V_245 , & V_70 -> V_58 ) ;
}
if ( V_89 && F_14 ( V_246 , & V_70 -> V_58 ) ) {
if ( ! F_14 ( V_90 , & V_89 -> V_58 ) ) {
V_98 -> V_330 = 1 ;
F_37 ( & V_89 -> V_111 ) ;
} else
F_21 ( V_246 , & V_70 -> V_58 ) ;
}
if ( ! F_14 ( V_299 , & V_70 -> V_58 ) ) {
F_21 ( V_237 , & V_70 -> V_58 ) ;
F_21 ( V_240 , & V_70 -> V_58 ) ;
}
if ( F_14 ( V_237 , & V_70 -> V_58 ) )
F_21 ( V_299 , & V_70 -> V_58 ) ;
if ( ! F_14 ( V_299 , & V_70 -> V_58 ) ) {
if ( V_98 -> V_307 < 2 )
V_98 -> V_306 [ V_98 -> V_307 ] = V_67 ;
V_98 -> V_307 ++ ;
}
}
F_57 ( & V_3 -> V_59 ) ;
F_52 () ;
}
static void F_163 ( struct V_19 * V_20 )
{
struct V_97 V_98 ;
struct V_2 * V_3 = V_20 -> V_57 ;
int V_67 ;
int V_192 ;
int V_23 = V_20 -> V_23 ;
struct V_75 * V_331 , * V_332 ;
F_21 ( V_40 , & V_20 -> V_36 ) ;
if ( F_107 ( V_333 , & V_20 -> V_36 ) ) {
F_61 ( V_40 , & V_20 -> V_36 ) ;
return;
}
if ( F_23 ( V_334 , & V_20 -> V_36 ) ) {
F_61 ( V_301 , & V_20 -> V_36 ) ;
F_21 ( V_313 , & V_20 -> V_36 ) ;
}
F_21 ( V_41 , & V_20 -> V_36 ) ;
F_30 ( L_43
L_44 ,
( unsigned long long ) V_20 -> V_10 , V_20 -> V_36 ,
F_19 ( & V_20 -> V_27 ) , V_20 -> V_30 , V_20 -> V_22 ,
V_20 -> V_33 , V_20 -> V_34 ) ;
F_162 ( V_20 , & V_98 ) ;
if ( V_98 . V_330 ) {
F_61 ( V_40 , & V_20 -> V_36 ) ;
goto V_335;
}
if ( F_78 ( V_98 . V_328 ) ) {
if ( V_98 . V_118 || V_98 . V_119 || V_98 . V_120 ||
V_98 . V_296 || V_98 . V_79 ) {
F_61 ( V_40 , & V_20 -> V_36 ) ;
goto V_335;
}
F_64 ( V_98 . V_328 , V_3 -> V_48 ) ;
V_98 . V_328 = NULL ;
}
if ( V_98 . V_326 && ! F_14 ( V_35 , & V_20 -> V_36 ) ) {
F_61 ( V_201 , & V_98 . V_197 ) ;
F_61 ( V_35 , & V_20 -> V_36 ) ;
}
F_30 ( L_45
L_46 ,
V_98 . V_285 , V_98 . V_234 , V_98 . V_300 , V_98 . V_296 , V_98 . V_307 ,
V_98 . V_306 [ 0 ] , V_98 . V_306 [ 1 ] ) ;
if ( V_98 . V_307 > V_3 -> V_87 ) {
V_20 -> V_33 = 0 ;
V_20 -> V_34 = 0 ;
if ( V_98 . V_300 + V_98 . V_296 + V_98 . V_79 )
F_148 ( V_3 , V_20 , & V_98 , V_23 , & V_98 . V_31 ) ;
if ( V_98 . V_118 )
F_152 ( V_3 , V_20 , & V_98 ) ;
}
V_331 = & V_20 -> V_70 [ V_20 -> V_30 ] ;
V_98 . V_336 = ( V_98 . V_307 >= 1 && V_98 . V_306 [ 0 ] == V_20 -> V_30 )
|| ( V_98 . V_307 >= 2 && V_98 . V_306 [ 1 ] == V_20 -> V_30 ) ;
V_332 = & V_20 -> V_70 [ V_20 -> V_22 ] ;
V_98 . V_317 = ( V_98 . V_307 >= 1 && V_98 . V_306 [ 0 ] == V_20 -> V_22 )
|| ( V_98 . V_307 >= 2 && V_98 . V_306 [ 1 ] == V_20 -> V_22 )
|| V_3 -> V_199 < 6 ;
if ( V_98 . V_79 &&
( V_98 . V_336 || ( ( F_14 ( V_299 , & V_331 -> V_58 )
&& ! F_14 ( V_80 , & V_331 -> V_58 )
&& F_14 ( V_160 , & V_331 -> V_58 ) ) ) ) &&
( V_98 . V_317 || ( ( F_14 ( V_299 , & V_332 -> V_58 )
&& ! F_14 ( V_80 , & V_332 -> V_58 )
&& F_14 ( V_160 , & V_332 -> V_58 ) ) ) ) )
F_156 ( V_3 , V_20 , V_23 , & V_98 . V_31 ) ;
if ( V_98 . V_300 || V_98 . V_327
|| ( V_3 -> V_199 == 6 && V_98 . V_296 && V_98 . V_307 )
|| ( V_98 . V_118 && ( V_98 . V_234 + V_98 . V_325 < V_23 ) ) || V_98 . V_119 )
F_155 ( V_20 , & V_98 , V_23 ) ;
V_192 = 0 ;
if ( V_20 -> V_34 == V_189 )
V_192 = 1 ;
if ( V_20 -> V_34 == V_187 ||
V_20 -> V_34 == V_189 ) {
V_20 -> V_34 = V_337 ;
F_17 ( ! F_14 ( V_160 , & V_20 -> V_70 [ V_20 -> V_30 ] . V_58 ) ) ;
F_17 ( V_20 -> V_22 >= 0 &&
! F_14 ( V_160 , & V_20 -> V_70 [ V_20 -> V_22 ] . V_58 ) ) ;
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( F_14 ( V_80 , & V_70 -> V_58 ) &&
( V_67 == V_20 -> V_30 || V_67 == V_20 -> V_22 ||
V_70 -> V_79 ) ) {
F_30 ( L_47 , V_67 ) ;
F_61 ( V_100 , & V_70 -> V_58 ) ;
if ( V_192 )
continue;
if ( ! F_14 ( V_299 , & V_70 -> V_58 ) ||
( ( V_67 == V_20 -> V_30 || V_67 == V_20 -> V_22 ) &&
V_98 . V_307 == 0 ) )
F_61 ( V_313 , & V_20 -> V_36 ) ;
}
}
if ( F_23 ( V_50 , & V_20 -> V_36 ) )
V_98 . V_338 = 1 ;
}
if ( V_98 . V_296 && ! V_20 -> V_34 && ! V_20 -> V_33 )
F_157 ( V_3 , V_20 , & V_98 , V_23 ) ;
if ( V_20 -> V_33 ||
( V_98 . V_118 && V_98 . V_285 == 0 &&
! F_14 ( V_37 , & V_20 -> V_36 ) &&
! F_14 ( V_313 , & V_20 -> V_36 ) ) ) {
if ( V_3 -> V_199 == 6 )
F_159 ( V_3 , V_20 , & V_98 , V_23 ) ;
else
F_158 ( V_3 , V_20 , & V_98 , V_23 ) ;
}
if ( V_98 . V_118 && V_98 . V_285 == 0 && F_14 ( V_313 , & V_20 -> V_36 ) ) {
F_153 ( V_3 -> V_48 , V_14 , 1 ) ;
F_21 ( V_301 , & V_20 -> V_36 ) ;
}
if ( V_98 . V_307 <= V_3 -> V_87 && ! V_3 -> V_48 -> V_339 )
for ( V_67 = 0 ; V_67 < V_98 . V_307 ; V_67 ++ ) {
struct V_75 * V_70 = & V_20 -> V_70 [ V_98 . V_306 [ V_67 ] ] ;
if ( F_14 ( V_237 , & V_70 -> V_58 )
&& ! F_14 ( V_80 , & V_70 -> V_58 )
&& F_14 ( V_160 , & V_70 -> V_58 )
) {
if ( ! F_14 ( V_240 , & V_70 -> V_58 ) ) {
F_61 ( V_100 , & V_70 -> V_58 ) ;
F_61 ( V_240 , & V_70 -> V_58 ) ;
F_61 ( V_80 , & V_70 -> V_58 ) ;
V_98 . V_285 ++ ;
} else {
F_61 ( V_104 , & V_70 -> V_58 ) ;
F_61 ( V_80 , & V_70 -> V_58 ) ;
V_98 . V_285 ++ ;
}
}
}
if ( V_20 -> V_34 == V_191 ) {
struct V_19 * V_340
= F_53 ( V_3 , V_20 -> V_10 , 1 , 1 , 1 ) ;
if ( V_340 && F_14 ( V_319 , & V_340 -> V_36 ) ) {
F_61 ( V_41 , & V_20 -> V_36 ) ;
F_61 ( V_40 , & V_20 -> V_36 ) ;
if ( ! F_145 ( V_50 ,
& V_340 -> V_36 ) )
F_37 ( & V_3 -> V_51 ) ;
F_26 ( V_340 ) ;
goto V_335;
}
if ( V_340 )
F_26 ( V_340 ) ;
V_20 -> V_34 = V_337 ;
F_21 ( V_53 , & V_20 -> V_36 ) ;
for ( V_67 = V_3 -> V_25 ; V_67 -- ; ) {
F_61 ( V_100 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
F_61 ( V_80 , & V_20 -> V_70 [ V_67 ] . V_58 ) ;
V_98 . V_285 ++ ;
}
}
if ( V_98 . V_120 && F_14 ( V_53 , & V_20 -> V_36 ) &&
! V_20 -> V_34 ) {
V_20 -> V_23 = V_3 -> V_25 ;
F_43 ( V_20 -> V_10 , V_3 , 0 , V_20 ) ;
F_144 ( V_20 , & V_98 , 1 , 1 ) ;
} else if ( V_98 . V_120 && ! V_20 -> V_34 && V_98 . V_285 == 0 ) {
F_21 ( V_323 , & V_20 -> V_36 ) ;
F_24 ( & V_3 -> V_341 ) ;
F_25 ( & V_3 -> V_211 ) ;
F_153 ( V_3 -> V_48 , V_14 , 1 ) ;
}
if ( V_98 . V_119 && V_98 . V_285 == 0 &&
! F_14 ( V_37 , & V_20 -> V_36 ) )
F_160 ( V_3 , V_20 ) ;
V_335:
if ( V_3 -> V_48 -> V_117 && F_78 ( V_98 . V_328 ) )
F_63 ( V_98 . V_328 , V_3 -> V_48 ) ;
if ( V_98 . V_330 )
for ( V_67 = V_23 ; V_67 -- ; ) {
struct V_88 * V_89 ;
struct V_75 * V_70 = & V_20 -> V_70 [ V_67 ] ;
if ( F_23 ( V_245 , & V_70 -> V_58 ) ) {
V_89 = V_3 -> V_23 [ V_67 ] . V_89 ;
if ( ! F_149 ( V_89 , V_20 -> V_10 ,
V_14 , 0 ) )
F_139 ( V_3 -> V_48 , V_89 ) ;
F_64 ( V_89 , V_3 -> V_48 ) ;
}
if ( F_23 ( V_246 , & V_70 -> V_58 ) ) {
V_89 = V_3 -> V_23 [ V_67 ] . V_89 ;
F_164 ( V_89 , V_20 -> V_10 ,
V_14 ) ;
F_64 ( V_89 , V_3 -> V_48 ) ;
}
}
if ( V_98 . V_197 )
F_105 ( V_20 , V_98 . V_197 ) ;
F_58 ( V_20 , & V_98 ) ;
if ( V_98 . V_338 ) {
F_24 ( & V_3 -> V_51 ) ;
if ( F_19 ( & V_3 -> V_51 ) <
V_52 )
F_22 ( V_3 -> V_48 -> V_49 ) ;
}
F_11 ( V_98 . V_31 ) ;
F_104 ( V_333 , & V_20 -> V_36 ) ;
}
static void F_165 ( struct V_2 * V_3 )
{
if ( F_19 ( & V_3 -> V_51 ) < V_52 ) {
while ( ! F_18 ( & V_3 -> V_42 ) ) {
struct V_61 * V_342 = V_3 -> V_42 . V_64 ;
struct V_19 * V_20 ;
V_20 = F_35 ( V_342 , struct V_19 , V_38 ) ;
F_36 ( V_342 ) ;
F_21 ( V_41 , & V_20 -> V_36 ) ;
if ( ! F_145 ( V_50 , & V_20 -> V_36 ) )
F_37 ( & V_3 -> V_51 ) ;
F_20 ( & V_20 -> V_38 , & V_3 -> V_343 ) ;
}
}
}
static void F_166 ( struct V_2 * V_3 )
{
struct V_61 V_344 ;
F_124 ( & V_344 , & V_3 -> V_46 ) ;
F_36 ( & V_3 -> V_46 ) ;
while ( ! F_18 ( & V_344 ) ) {
struct V_19 * V_20 = F_35 ( V_344 . V_64 , struct V_19 , V_38 ) ;
F_36 ( & V_20 -> V_38 ) ;
F_37 ( & V_20 -> V_27 ) ;
F_15 ( V_3 , V_20 ) ;
}
}
int F_167 ( struct V_48 * V_48 , int V_345 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
if ( V_3 -> V_95 )
return 1 ;
if ( V_3 -> V_94 )
return 1 ;
if ( F_168 ( & V_3 -> V_54 ) )
return 1 ;
return 0 ;
}
static int F_169 ( void * V_346 , int V_345 )
{
struct V_48 * V_48 = V_346 ;
return F_170 ( V_48 , V_345 ) ||
F_167 ( V_48 , V_345 ) ;
}
static int F_171 ( struct V_347 * V_348 ,
struct V_349 * V_350 ,
struct V_140 * V_351 )
{
struct V_48 * V_48 = V_348 -> V_352 ;
T_1 V_10 = V_350 -> V_13 + F_172 ( V_350 -> V_123 ) ;
int F_117 ;
unsigned int V_264 = V_48 -> V_264 ;
unsigned int V_353 = V_350 -> V_12 >> 9 ;
if ( ( V_350 -> V_107 & 1 ) == V_103 )
return V_351 -> V_133 ;
if ( V_48 -> V_354 < V_48 -> V_264 )
V_264 = V_48 -> V_354 ;
F_117 = ( V_264 - ( ( V_10 & ( V_264 - 1 ) ) + V_353 ) ) << 9 ;
if ( F_117 < 0 ) F_117 = 0 ;
if ( F_117 <= V_351 -> V_133 && V_353 == 0 )
return V_351 -> V_133 ;
else
return F_117 ;
}
static int F_173 ( struct V_48 * V_48 , struct V_9 * V_9 )
{
T_1 V_10 = V_9 -> V_13 + F_172 ( V_9 -> V_123 ) ;
unsigned int V_264 = V_48 -> V_264 ;
unsigned int V_353 = V_9 -> V_12 >> 9 ;
if ( V_48 -> V_354 < V_48 -> V_264 )
V_264 = V_48 -> V_354 ;
return V_264 >=
( ( V_10 & ( V_264 - 1 ) ) + V_353 ) ;
}
static void F_174 ( struct V_9 * V_32 , struct V_2 * V_3 )
{
unsigned long V_58 ;
F_27 ( & V_3 -> V_59 , V_58 ) ;
V_32 -> V_15 = V_3 -> V_355 ;
V_3 -> V_355 = V_32 ;
F_28 ( & V_3 -> V_59 , V_58 ) ;
F_22 ( V_3 -> V_48 -> V_49 ) ;
}
static struct V_9 * F_175 ( struct V_2 * V_3 )
{
struct V_9 * V_32 ;
V_32 = V_3 -> V_56 ;
if ( V_32 ) {
V_3 -> V_56 = NULL ;
return V_32 ;
}
V_32 = V_3 -> V_355 ;
if( V_32 ) {
V_3 -> V_355 = V_32 -> V_15 ;
V_32 -> V_15 = NULL ;
V_32 -> V_16 = 1 ;
}
return V_32 ;
}
static void F_176 ( struct V_9 * V_32 , int error )
{
struct V_9 * V_356 = V_32 -> V_233 ;
struct V_48 * V_48 ;
struct V_2 * V_3 ;
int V_234 = F_14 ( V_127 , & V_32 -> V_126 ) ;
struct V_88 * V_89 ;
F_177 ( V_32 ) ;
V_89 = ( void * ) V_356 -> V_15 ;
V_356 -> V_15 = NULL ;
V_48 = V_89 -> V_48 ;
V_3 = V_48 -> V_247 ;
F_64 ( V_89 , V_3 -> V_48 ) ;
if ( ! error && V_234 ) {
F_12 ( V_356 , 0 ) ;
if ( F_16 ( & V_3 -> V_357 ) )
F_25 ( & V_3 -> V_55 ) ;
return;
}
F_30 ( L_48 ) ;
F_174 ( V_356 , V_3 ) ;
}
static int F_178 ( struct V_9 * V_32 )
{
struct V_347 * V_348 = F_179 ( V_32 -> V_123 ) ;
if ( ( V_32 -> V_12 >> 9 ) > F_180 ( V_348 ) )
return 0 ;
F_181 ( V_348 , V_32 ) ;
if ( V_32 -> V_16 > F_182 ( V_348 ) )
return 0 ;
if ( V_348 -> V_358 )
return 0 ;
return 1 ;
}
static int F_183 ( struct V_48 * V_48 , struct V_9 * V_359 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
int V_254 ;
struct V_9 * V_360 ;
struct V_88 * V_89 ;
if ( ! F_173 ( V_48 , V_359 ) ) {
F_30 ( L_49 ) ;
return 0 ;
}
V_360 = F_184 ( V_359 , V_232 , V_48 ) ;
if ( ! V_360 )
return 0 ;
V_360 -> V_108 = F_176 ;
V_360 -> V_233 = V_359 ;
V_360 -> V_13 = F_142 ( V_3 , V_359 -> V_13 ,
0 ,
& V_254 , NULL ) ;
F_50 () ;
V_89 = F_51 ( V_3 -> V_23 [ V_254 ] . V_89 ) ;
if ( V_89 && F_14 ( V_91 , & V_89 -> V_58 ) ) {
T_1 V_113 ;
int V_114 ;
F_37 ( & V_89 -> V_111 ) ;
F_52 () ;
V_359 -> V_15 = ( void * ) V_89 ;
V_360 -> V_123 = V_89 -> V_121 ;
V_360 -> V_126 &= ~ ( 1 << V_361 ) ;
V_360 -> V_13 += V_89 -> V_125 ;
if ( ! F_178 ( V_360 ) ||
F_60 ( V_89 , V_360 -> V_13 , V_360 -> V_12 >> 9 ,
& V_113 , & V_114 ) ) {
F_177 ( V_360 ) ;
F_64 ( V_89 , V_48 ) ;
return 0 ;
}
F_54 ( & V_3 -> V_59 ) ;
F_55 ( V_3 -> V_55 ,
V_3 -> V_94 == 0 ,
V_3 -> V_59 , ) ;
F_37 ( & V_3 -> V_357 ) ;
F_57 ( & V_3 -> V_59 ) ;
F_66 ( V_360 ) ;
return 1 ;
} else {
F_52 () ;
F_177 ( V_360 ) ;
return 0 ;
}
}
static struct V_19 * F_185 ( struct V_2 * V_3 )
{
struct V_19 * V_20 ;
F_30 ( L_50 ,
V_124 ,
F_18 ( & V_3 -> V_47 ) ? L_51 : L_52 ,
F_18 ( & V_3 -> V_343 ) ? L_51 : L_52 ,
F_19 ( & V_3 -> V_287 ) , V_3 -> V_362 ) ;
if ( ! F_18 ( & V_3 -> V_47 ) ) {
V_20 = F_35 ( V_3 -> V_47 . V_64 , F_186 ( * V_20 ) , V_38 ) ;
if ( F_18 ( & V_3 -> V_343 ) )
V_3 -> V_362 = 0 ;
else if ( ! F_14 ( V_122 , & V_20 -> V_36 ) ) {
if ( V_3 -> V_343 . V_64 == V_3 -> V_363 )
V_3 -> V_362 ++ ;
else {
V_3 -> V_363 = V_3 -> V_343 . V_64 ;
V_3 -> V_362 -= V_3 -> V_364 ;
if ( V_3 -> V_362 < 0 )
V_3 -> V_362 = 0 ;
}
}
} else if ( ! F_18 ( & V_3 -> V_343 ) &&
( ( V_3 -> V_364 &&
V_3 -> V_362 > V_3 -> V_364 ) ||
F_19 ( & V_3 -> V_287 ) == 0 ) ) {
V_20 = F_35 ( V_3 -> V_343 . V_64 ,
F_186 ( * V_20 ) , V_38 ) ;
V_3 -> V_362 -= V_3 -> V_364 ;
if ( V_3 -> V_362 < 0 )
V_3 -> V_362 = 0 ;
} else
return NULL ;
F_36 ( & V_20 -> V_38 ) ;
F_37 ( & V_20 -> V_27 ) ;
F_17 ( F_19 ( & V_20 -> V_27 ) != 1 ) ;
return V_20 ;
}
static void F_187 ( struct V_48 * V_48 , struct V_9 * V_32 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
int V_254 ;
T_1 V_259 ;
T_1 V_365 , V_366 ;
struct V_19 * V_20 ;
const int V_99 = F_188 ( V_32 ) ;
int V_367 ;
int V_368 ;
if ( F_78 ( V_32 -> V_107 & V_369 ) ) {
F_189 ( V_48 , V_32 ) ;
return;
}
F_190 ( V_48 , V_32 ) ;
if ( V_99 == V_105 &&
V_48 -> V_85 == V_86 &&
F_183 ( V_48 , V_32 ) )
return;
V_365 = V_32 -> V_13 & ~ ( ( T_1 ) V_14 - 1 ) ;
V_366 = V_32 -> V_13 + ( V_32 -> V_12 >> 9 ) ;
V_32 -> V_15 = NULL ;
V_32 -> V_16 = 1 ;
V_368 = F_191 ( V_48 ) ;
for (; V_365 < V_366 ; V_365 += V_14 ) {
F_192 ( V_370 ) ;
int V_23 , V_265 ;
int V_72 ;
V_243:
V_72 = 0 ;
V_23 = V_3 -> V_25 ;
F_193 ( & V_3 -> V_211 , & V_370 , V_371 ) ;
if ( F_78 ( V_3 -> V_372 != V_86 ) ) {
F_54 ( & V_3 -> V_59 ) ;
if ( V_48 -> V_373 < 0
? V_365 < V_3 -> V_372
: V_365 >= V_3 -> V_372 ) {
V_23 = V_3 -> V_74 ;
V_72 = 1 ;
} else {
if ( V_48 -> V_373 < 0
? V_365 < V_3 -> V_374
: V_365 >= V_3 -> V_374 ) {
F_57 ( & V_3 -> V_59 ) ;
F_194 () ;
goto V_243;
}
}
F_57 ( & V_3 -> V_59 ) ;
}
V_265 = V_23 - V_3 -> V_87 ;
V_259 = F_142 ( V_3 , V_365 ,
V_72 ,
& V_254 , NULL ) ;
F_30 ( L_53 ,
( unsigned long long ) V_259 ,
( unsigned long long ) V_365 ) ;
V_20 = F_53 ( V_3 , V_259 , V_72 ,
( V_32 -> V_107 & V_375 ) , 0 ) ;
if ( V_20 ) {
if ( F_78 ( V_72 ) ) {
int V_376 = 0 ;
F_54 ( & V_3 -> V_59 ) ;
if ( V_48 -> V_373 < 0
? V_365 >= V_3 -> V_372
: V_365 < V_3 -> V_372 )
V_376 = 1 ;
F_57 ( & V_3 -> V_59 ) ;
if ( V_376 ) {
F_26 ( V_20 ) ;
F_194 () ;
goto V_243;
}
}
if ( V_99 == V_103 &&
V_365 >= V_48 -> V_377 &&
V_365 < V_48 -> V_378 ) {
F_26 ( V_20 ) ;
F_195 ( V_379 ) ;
F_193 ( & V_3 -> V_211 ,
& V_370 , V_380 ) ;
if ( V_365 >= V_48 -> V_377 &&
V_365 < V_48 -> V_378 )
F_194 () ;
goto V_243;
}
if ( F_14 ( V_53 , & V_20 -> V_36 ) ||
! F_146 ( V_20 , V_32 , V_254 , V_99 ) ) {
F_22 ( V_48 -> V_49 ) ;
F_26 ( V_20 ) ;
F_194 () ;
goto V_243;
}
F_196 ( & V_3 -> V_211 , & V_370 ) ;
F_61 ( V_40 , & V_20 -> V_36 ) ;
F_21 ( V_41 , & V_20 -> V_36 ) ;
if ( ( V_32 -> V_107 & V_381 ) &&
! F_145 ( V_50 , & V_20 -> V_36 ) )
F_37 ( & V_3 -> V_51 ) ;
F_26 ( V_20 ) ;
} else {
F_21 ( V_127 , & V_32 -> V_126 ) ;
F_196 ( & V_3 -> V_211 , & V_370 ) ;
break;
}
}
if ( ! V_368 )
F_22 ( V_48 -> V_49 ) ;
F_54 ( & V_3 -> V_59 ) ;
V_367 = F_5 ( V_32 ) ;
F_57 ( & V_3 -> V_59 ) ;
if ( V_367 == 0 ) {
if ( V_99 == V_103 )
F_150 ( V_48 ) ;
F_12 ( V_32 , 0 ) ;
}
}
static T_1 F_197 ( struct V_48 * V_48 , T_1 V_382 , int * V_383 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
struct V_19 * V_20 ;
T_1 V_384 , V_366 ;
int V_25 = V_3 -> V_74 ;
int V_265 = V_25 - V_3 -> V_87 ;
int V_385 = V_3 -> V_25 - V_3 -> V_87 ;
int V_67 ;
int V_254 ;
T_1 V_386 , V_387 , V_388 ;
T_1 V_389 ;
int V_390 ;
struct V_61 V_391 ;
if ( V_382 == 0 ) {
if ( V_48 -> V_373 < 0 &&
V_3 -> V_372 < F_198 ( V_48 , 0 , 0 ) ) {
V_382 = F_198 ( V_48 , 0 , 0 )
- V_3 -> V_372 ;
} else if ( V_48 -> V_373 >= 0 &&
V_3 -> V_372 > 0 )
V_382 = V_3 -> V_372 ;
F_143 ( V_382 , V_385 ) ;
if ( V_382 ) {
V_48 -> V_392 = V_382 ;
F_199 ( & V_48 -> V_393 , NULL , L_54 ) ;
* V_383 = 1 ;
return V_382 ;
}
}
if ( V_48 -> V_354 > V_48 -> V_264 )
V_390 = V_48 -> V_354 ;
else
V_390 = V_48 -> V_264 ;
V_386 = V_3 -> V_372 ;
F_143 ( V_386 , V_385 ) ;
V_387 = V_3 -> V_372 ;
F_143 ( V_387 , V_265 ) ;
V_388 = V_3 -> V_374 ;
F_143 ( V_388 , V_265 ) ;
if ( V_48 -> V_373 < 0 ) {
V_386 -= F_200 ( T_1 , V_390 , V_386 ) ;
V_387 += V_390 ;
V_388 += V_390 ;
} else {
V_386 += V_390 ;
V_387 -= F_200 ( T_1 , V_390 , V_387 ) ;
V_388 -= F_200 ( T_1 , V_390 , V_388 ) ;
}
if ( ( V_48 -> V_373 < 0
? ( V_388 > V_386 && V_387 < V_386 )
: ( V_388 < V_386 && V_387 > V_386 ) ) ||
F_201 ( V_394 , V_3 -> V_395 + 10 * V_396 ) ) {
F_106 ( V_3 -> V_211 ,
F_19 ( & V_3 -> V_341 ) == 0 ) ;
V_48 -> V_85 = V_3 -> V_372 ;
V_48 -> V_392 = V_382 ;
V_3 -> V_395 = V_394 ;
F_61 ( V_251 , & V_48 -> V_58 ) ;
F_22 ( V_48 -> V_49 ) ;
F_106 ( V_48 -> V_397 , V_48 -> V_58 == 0 ||
F_202 () ) ;
F_54 ( & V_3 -> V_59 ) ;
V_3 -> V_374 = V_48 -> V_85 ;
F_57 ( & V_3 -> V_59 ) ;
F_25 ( & V_3 -> V_211 ) ;
F_199 ( & V_48 -> V_393 , NULL , L_54 ) ;
}
if ( V_48 -> V_373 < 0 ) {
F_17 ( V_3 -> V_372 == 0 ) ;
V_389 = V_386 ;
F_17 ( ( V_48 -> V_398 &
~ ( ( T_1 ) V_390 - 1 ) )
- V_390 - V_389
!= V_382 ) ;
} else {
F_17 ( V_386 != V_382 + V_390 ) ;
V_389 = V_382 ;
}
F_115 ( & V_391 ) ;
for ( V_67 = 0 ; V_67 < V_390 ; V_67 += V_14 ) {
int V_320 ;
int V_399 = 0 ;
V_20 = F_53 ( V_3 , V_389 + V_67 , 0 , 0 , 1 ) ;
F_61 ( V_53 , & V_20 -> V_36 ) ;
F_37 ( & V_3 -> V_341 ) ;
for ( V_320 = V_20 -> V_23 ; V_320 -- ; ) {
T_1 V_98 ;
if ( V_320 == V_20 -> V_30 )
continue;
if ( V_3 -> V_199 == 6 &&
V_320 == V_20 -> V_22 )
continue;
V_98 = F_141 ( V_20 , V_320 , 0 ) ;
if ( V_98 < F_198 ( V_48 , 0 , 0 ) ) {
V_399 = 1 ;
continue;
}
memset ( F_203 ( V_20 -> V_70 [ V_320 ] . V_65 ) , 0 , V_134 ) ;
F_61 ( V_322 , & V_20 -> V_70 [ V_320 ] . V_58 ) ;
F_61 ( V_160 , & V_20 -> V_70 [ V_320 ] . V_58 ) ;
}
if ( ! V_399 ) {
F_61 ( V_323 , & V_20 -> V_36 ) ;
F_61 ( V_40 , & V_20 -> V_36 ) ;
}
F_124 ( & V_20 -> V_38 , & V_391 ) ;
}
F_54 ( & V_3 -> V_59 ) ;
if ( V_48 -> V_373 < 0 )
V_3 -> V_372 -= V_390 * V_385 ;
else
V_3 -> V_372 += V_390 * V_385 ;
F_57 ( & V_3 -> V_59 ) ;
V_384 =
F_142 ( V_3 , V_389 * ( V_385 ) ,
1 , & V_254 , NULL ) ;
V_366 =
F_142 ( V_3 , ( ( V_389 + V_390 )
* V_385 - 1 ) ,
1 , & V_254 , NULL ) ;
if ( V_366 >= V_48 -> V_398 )
V_366 = V_48 -> V_398 - 1 ;
while ( V_384 <= V_366 ) {
V_20 = F_53 ( V_3 , V_384 , 1 , 0 , 1 ) ;
F_61 ( V_319 , & V_20 -> V_36 ) ;
F_61 ( V_40 , & V_20 -> V_36 ) ;
F_26 ( V_20 ) ;
V_384 += V_14 ;
}
while ( ! F_18 ( & V_391 ) ) {
V_20 = F_35 ( V_391 . V_64 , struct V_19 , V_38 ) ;
F_36 ( & V_20 -> V_38 ) ;
F_26 ( V_20 ) ;
}
V_382 += V_390 ;
if ( ( V_382 - V_48 -> V_392 ) * 2
>= V_48 -> V_400 - V_48 -> V_392 ) {
F_106 ( V_3 -> V_211 ,
F_19 ( & V_3 -> V_341 ) == 0 ) ;
V_48 -> V_85 = V_3 -> V_372 ;
V_48 -> V_392 = V_382 ;
V_3 -> V_395 = V_394 ;
F_61 ( V_251 , & V_48 -> V_58 ) ;
F_22 ( V_48 -> V_49 ) ;
F_106 ( V_48 -> V_397 ,
! F_14 ( V_251 , & V_48 -> V_58 )
|| F_202 () ) ;
F_54 ( & V_3 -> V_59 ) ;
V_3 -> V_374 = V_48 -> V_85 ;
F_57 ( & V_3 -> V_59 ) ;
F_25 ( & V_3 -> V_211 ) ;
F_199 ( & V_48 -> V_393 , NULL , L_54 ) ;
}
return V_390 ;
}
static inline T_1 F_204 ( struct V_48 * V_48 , T_1 V_382 , int * V_383 , int V_401 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
struct V_19 * V_20 ;
T_1 V_402 = V_48 -> V_398 ;
T_1 V_403 ;
int V_404 = 0 ;
int V_67 ;
if ( V_382 >= V_402 ) {
if ( F_14 ( V_405 , & V_48 -> V_249 ) ) {
F_205 ( V_3 ) ;
return 0 ;
}
if ( V_48 -> V_406 < V_402 )
F_206 ( V_48 -> V_293 , V_48 -> V_406 ,
& V_403 , 1 ) ;
else
V_3 -> V_407 = 0 ;
F_207 ( V_48 -> V_293 ) ;
return 0 ;
}
F_106 ( V_3 -> V_211 , V_3 -> V_94 != 2 ) ;
if ( F_14 ( V_405 , & V_48 -> V_249 ) )
return F_197 ( V_48 , V_382 , V_383 ) ;
if ( V_48 -> V_84 >= V_3 -> V_87 &&
F_14 ( V_408 , & V_48 -> V_249 ) ) {
T_1 V_409 = V_48 -> V_398 - V_382 ;
* V_383 = 1 ;
return V_409 ;
}
if ( ! F_208 ( V_48 -> V_293 , V_382 , & V_403 , 1 ) &&
! F_14 ( V_410 , & V_48 -> V_249 ) &&
! V_3 -> V_407 && V_403 >= V_14 ) {
V_403 /= V_14 ;
* V_383 = 1 ;
return V_403 * V_14 ;
}
F_209 ( V_48 -> V_293 , V_382 ) ;
V_20 = F_53 ( V_3 , V_382 , 0 , 1 , 0 ) ;
if ( V_20 == NULL ) {
V_20 = F_53 ( V_3 , V_382 , 0 , 0 , 0 ) ;
F_210 ( 1 ) ;
}
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ )
if ( V_3 -> V_23 [ V_67 ] . V_89 == NULL )
V_404 = 1 ;
F_208 ( V_48 -> V_293 , V_382 , & V_403 , V_404 ) ;
F_61 ( V_334 , & V_20 -> V_36 ) ;
F_163 ( V_20 ) ;
F_26 ( V_20 ) ;
return V_14 ;
}
static int F_211 ( struct V_2 * V_3 , struct V_9 * V_359 )
{
struct V_19 * V_20 ;
int V_254 ;
T_1 V_10 , V_365 , V_366 ;
int V_411 = 0 ;
int V_367 ;
int V_412 = 0 ;
V_365 = V_359 -> V_13 & ~ ( ( T_1 ) V_14 - 1 ) ;
V_10 = F_142 ( V_3 , V_365 ,
0 , & V_254 , NULL ) ;
V_366 = V_359 -> V_13 + ( V_359 -> V_12 >> 9 ) ;
for (; V_365 < V_366 ;
V_365 += V_14 ,
V_10 += V_14 ,
V_411 ++ ) {
if ( V_411 < F_4 ( V_359 ) )
continue;
V_20 = F_53 ( V_3 , V_10 , 0 , 1 , 0 ) ;
if ( ! V_20 ) {
F_7 ( V_359 , V_411 ) ;
V_3 -> V_56 = V_359 ;
return V_412 ;
}
F_61 ( V_237 , & V_20 -> V_70 [ V_254 ] . V_58 ) ;
if ( ! F_146 ( V_20 , V_359 , V_254 , 0 ) ) {
F_26 ( V_20 ) ;
F_7 ( V_359 , V_411 ) ;
V_3 -> V_56 = V_359 ;
return V_412 ;
}
F_163 ( V_20 ) ;
F_26 ( V_20 ) ;
V_412 ++ ;
}
F_54 ( & V_3 -> V_59 ) ;
V_367 = F_5 ( V_359 ) ;
F_57 ( & V_3 -> V_59 ) ;
if ( V_367 == 0 )
F_12 ( V_359 , 0 ) ;
if ( F_16 ( & V_3 -> V_357 ) )
F_25 ( & V_3 -> V_55 ) ;
return V_412 ;
}
static void F_212 ( struct V_48 * V_48 )
{
struct V_19 * V_20 ;
struct V_2 * V_3 = V_48 -> V_247 ;
int V_412 ;
struct V_413 V_414 ;
F_30 ( L_55 ) ;
F_62 ( V_48 ) ;
F_213 ( & V_414 ) ;
V_412 = 0 ;
F_54 ( & V_3 -> V_59 ) ;
while ( 1 ) {
struct V_9 * V_9 ;
if ( F_19 ( & V_48 -> V_415 ) == 0 &&
! F_18 ( & V_3 -> V_46 ) ) {
V_3 -> V_294 ++ ;
F_57 ( & V_3 -> V_59 ) ;
F_214 ( V_48 -> V_293 ) ;
F_54 ( & V_3 -> V_59 ) ;
V_3 -> V_45 = V_3 -> V_294 ;
F_166 ( V_3 ) ;
}
if ( F_19 ( & V_48 -> V_415 ) == 0 )
F_165 ( V_3 ) ;
while ( ( V_9 = F_175 ( V_3 ) ) ) {
int V_416 ;
F_57 ( & V_3 -> V_59 ) ;
V_416 = F_211 ( V_3 , V_9 ) ;
F_54 ( & V_3 -> V_59 ) ;
if ( ! V_416 )
break;
V_412 ++ ;
}
V_20 = F_185 ( V_3 ) ;
if ( ! V_20 )
break;
F_57 ( & V_3 -> V_59 ) ;
V_412 ++ ;
F_163 ( V_20 ) ;
F_26 ( V_20 ) ;
F_215 () ;
if ( V_48 -> V_58 & ~ ( 1 << V_417 ) )
F_62 ( V_48 ) ;
F_54 ( & V_3 -> V_59 ) ;
}
F_30 ( L_56 , V_412 ) ;
F_57 ( & V_3 -> V_59 ) ;
F_216 () ;
F_217 ( & V_414 ) ;
F_30 ( L_57 ) ;
}
static T_5
F_218 ( struct V_48 * V_48 , char * V_65 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
if ( V_3 )
return sprintf ( V_65 , L_58 , V_3 -> V_96 ) ;
else
return 0 ;
}
int
F_219 ( struct V_48 * V_48 , int V_418 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
int V_230 ;
if ( V_418 <= 16 || V_418 > 32768 )
return - V_419 ;
while ( V_418 < V_3 -> V_96 ) {
if ( F_134 ( V_3 ) )
V_3 -> V_96 -- ;
else
break;
}
V_230 = F_123 ( V_48 ) ;
if ( V_230 )
return V_230 ;
while ( V_418 > V_3 -> V_96 ) {
if ( F_109 ( V_3 ) )
V_3 -> V_96 ++ ;
else break;
}
return 0 ;
}
static T_5
F_220 ( struct V_48 * V_48 , const char * V_65 , T_4 V_148 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
unsigned long V_420 ;
int V_230 ;
if ( V_148 >= V_421 )
return - V_419 ;
if ( ! V_3 )
return - V_422 ;
if ( F_221 ( V_65 , 10 , & V_420 ) )
return - V_419 ;
V_230 = F_219 ( V_48 , V_420 ) ;
if ( V_230 )
return V_230 ;
return V_148 ;
}
static T_5
F_222 ( struct V_48 * V_48 , char * V_65 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
if ( V_3 )
return sprintf ( V_65 , L_58 , V_3 -> V_364 ) ;
else
return 0 ;
}
static T_5
F_223 ( struct V_48 * V_48 , const char * V_65 , T_4 V_148 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
unsigned long V_420 ;
if ( V_148 >= V_421 )
return - V_419 ;
if ( ! V_3 )
return - V_422 ;
if ( F_221 ( V_65 , 10 , & V_420 ) )
return - V_419 ;
if ( V_420 > V_3 -> V_96 )
return - V_419 ;
V_3 -> V_364 = V_420 ;
return V_148 ;
}
static T_5
F_224 ( struct V_48 * V_48 , char * V_65 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
if ( V_3 )
return sprintf ( V_65 , L_58 , F_19 ( & V_3 -> V_39 ) ) ;
else
return 0 ;
}
static T_1
F_198 ( struct V_48 * V_48 , T_1 V_11 , int V_25 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
if ( ! V_11 )
V_11 = V_48 -> V_398 ;
if ( ! V_25 )
V_25 = F_225 ( V_3 -> V_25 , V_3 -> V_74 ) ;
V_11 &= ~ ( ( T_1 ) V_48 -> V_264 - 1 ) ;
V_11 &= ~ ( ( T_1 ) V_48 -> V_354 - 1 ) ;
return V_11 * ( V_25 - V_3 -> V_87 ) ;
}
static void F_226 ( struct V_2 * V_3 )
{
struct V_166 * V_167 ;
unsigned long V_200 ;
if ( ! V_3 -> V_167 )
return;
F_130 () ;
F_227 (cpu) {
V_167 = F_100 ( V_3 -> V_167 , V_200 ) ;
F_228 ( V_167 -> V_196 ) ;
F_129 ( V_167 -> V_168 ) ;
}
#ifdef F_229
F_230 ( & V_3 -> V_423 ) ;
#endif
F_133 () ;
F_231 ( V_3 -> V_167 ) ;
}
static void F_232 ( struct V_2 * V_3 )
{
F_135 ( V_3 ) ;
F_226 ( V_3 ) ;
F_129 ( V_3 -> V_23 ) ;
F_129 ( V_3 -> V_8 ) ;
F_129 ( V_3 ) ;
}
static int F_233 ( struct V_424 * V_425 , unsigned long V_426 ,
void * V_427 )
{
struct V_2 * V_3 = F_234 ( V_425 , struct V_2 , V_423 ) ;
long V_200 = ( long ) V_427 ;
struct V_166 * V_167 = F_100 ( V_3 -> V_167 , V_200 ) ;
switch ( V_426 ) {
case V_428 :
case V_429 :
if ( V_3 -> V_199 == 6 && ! V_167 -> V_196 )
V_167 -> V_196 = F_41 ( V_71 ) ;
if ( ! V_167 -> V_168 )
V_167 -> V_168 = F_132 ( V_3 -> F_120 , V_71 ) ;
if ( ! V_167 -> V_168 ||
( V_3 -> V_199 == 6 && ! V_167 -> V_196 ) ) {
F_228 ( V_167 -> V_196 ) ;
F_129 ( V_167 -> V_168 ) ;
F_235 ( L_59 ,
V_124 , V_200 ) ;
return F_236 ( - V_231 ) ;
}
break;
case V_430 :
case V_431 :
F_228 ( V_167 -> V_196 ) ;
F_129 ( V_167 -> V_168 ) ;
V_167 -> V_196 = NULL ;
V_167 -> V_168 = NULL ;
break;
default:
break;
}
return V_432 ;
}
static int F_237 ( struct V_2 * V_3 )
{
unsigned long V_200 ;
struct V_65 * V_196 ;
struct V_166 T_6 * V_433 ;
void * V_168 ;
int V_230 ;
V_433 = F_238 ( struct V_166 ) ;
if ( ! V_433 )
return - V_231 ;
V_3 -> V_167 = V_433 ;
F_130 () ;
V_230 = 0 ;
F_131 (cpu) {
if ( V_3 -> V_199 == 6 ) {
V_196 = F_41 ( V_71 ) ;
if ( ! V_196 ) {
V_230 = - V_231 ;
break;
}
F_100 ( V_3 -> V_167 , V_200 ) -> V_196 = V_196 ;
}
V_168 = F_132 ( V_3 -> F_120 , V_71 ) ;
if ( ! V_168 ) {
V_230 = - V_231 ;
break;
}
F_100 ( V_3 -> V_167 , V_200 ) -> V_168 = V_168 ;
}
#ifdef F_229
V_3 -> V_423 . V_434 = F_233 ;
V_3 -> V_423 . V_435 = 0 ;
if ( V_230 == 0 )
V_230 = F_239 ( & V_3 -> V_423 ) ;
#endif
F_133 () ;
return V_230 ;
}
static struct V_2 * F_240 ( struct V_48 * V_48 )
{
struct V_2 * V_3 ;
int V_436 , V_437 , V_438 ;
struct V_88 * V_89 ;
struct V_228 * V_24 ;
if ( V_48 -> V_439 != 5
&& V_48 -> V_439 != 4
&& V_48 -> V_439 != 6 ) {
F_44 ( V_81 L_60 ,
F_118 ( V_48 ) , V_48 -> V_439 ) ;
return F_241 ( - V_440 ) ;
}
if ( ( V_48 -> V_439 == 5
&& ! F_242 ( V_48 -> V_441 ) ) ||
( V_48 -> V_439 == 6
&& ! F_243 ( V_48 -> V_441 ) ) ) {
F_44 ( V_81 L_61 ,
F_118 ( V_48 ) , V_48 -> V_441 ) ;
return F_241 ( - V_440 ) ;
}
if ( V_48 -> V_439 == 6 && V_48 -> V_25 < 4 ) {
F_44 ( V_81 L_62 ,
F_118 ( V_48 ) , V_48 -> V_25 ) ;
return F_241 ( - V_419 ) ;
}
if ( ! V_48 -> V_354 ||
( V_48 -> V_354 << 9 ) % V_421 ||
! F_244 ( V_48 -> V_354 ) ) {
F_44 ( V_81 L_63 ,
F_118 ( V_48 ) , V_48 -> V_354 << 9 ) ;
return F_241 ( - V_419 ) ;
}
V_3 = F_128 ( sizeof( struct V_2 ) , V_71 ) ;
if ( V_3 == NULL )
goto abort;
F_245 ( & V_3 -> V_59 ) ;
F_112 ( & V_3 -> V_55 ) ;
F_112 ( & V_3 -> V_211 ) ;
F_115 ( & V_3 -> V_47 ) ;
F_115 ( & V_3 -> V_343 ) ;
F_115 ( & V_3 -> V_42 ) ;
F_115 ( & V_3 -> V_46 ) ;
F_115 ( & V_3 -> V_54 ) ;
F_114 ( & V_3 -> V_39 , 0 ) ;
F_114 ( & V_3 -> V_51 , 0 ) ;
F_114 ( & V_3 -> V_357 , 0 ) ;
V_3 -> V_364 = V_442 ;
V_3 -> V_303 = V_48 -> V_303 - 1 ;
V_3 -> V_25 = V_48 -> V_25 ;
if ( V_48 -> V_85 == V_86 )
V_3 -> V_74 = V_48 -> V_25 ;
else
V_3 -> V_74 = V_48 -> V_25 - V_48 -> V_373 ;
V_438 = F_117 ( V_3 -> V_25 , V_3 -> V_74 ) ;
V_3 -> F_120 = F_120 ( V_438 ) ;
V_3 -> V_23 = F_128 ( V_438 * sizeof( struct V_228 ) ,
V_71 ) ;
if ( ! V_3 -> V_23 )
goto abort;
V_3 -> V_48 = V_48 ;
if ( ( V_3 -> V_8 = F_128 ( V_421 , V_71 ) ) == NULL )
goto abort;
V_3 -> V_199 = V_48 -> V_439 ;
if ( F_237 ( V_3 ) != 0 )
goto abort;
F_30 ( L_64 , F_118 ( V_48 ) ) ;
F_127 (rdev, &mddev->disks, same_set) {
V_436 = V_89 -> V_436 ;
if ( V_436 >= V_438
|| V_436 < 0 )
continue;
V_24 = V_3 -> V_23 + V_436 ;
V_24 -> V_89 = V_89 ;
if ( F_14 ( V_91 , & V_89 -> V_58 ) ) {
char V_235 [ V_236 ] ;
F_44 ( V_238 L_65
L_66 ,
F_118 ( V_48 ) , F_137 ( V_89 -> V_121 , V_235 ) , V_436 ) ;
} else if ( V_89 -> V_443 != V_436 )
V_3 -> V_407 = 1 ;
}
V_3 -> V_264 = V_48 -> V_354 ;
V_3 -> V_199 = V_48 -> V_439 ;
if ( V_3 -> V_199 == 6 )
V_3 -> V_87 = 2 ;
else
V_3 -> V_87 = 1 ;
V_3 -> V_260 = V_48 -> V_441 ;
V_3 -> V_96 = V_444 ;
V_3 -> V_372 = V_48 -> V_85 ;
if ( V_3 -> V_372 != V_86 ) {
V_3 -> V_263 = V_48 -> V_264 ;
V_3 -> V_261 = V_48 -> V_445 ;
}
V_437 = V_3 -> V_96 * ( sizeof( struct V_19 ) +
V_438 * ( ( sizeof( struct V_9 ) + V_421 ) ) ) / 1024 ;
if ( F_116 ( V_3 , V_3 -> V_96 ) ) {
F_44 ( V_81
L_67 ,
F_118 ( V_48 ) , V_437 ) ;
goto abort;
} else
F_44 ( V_238 L_68 ,
F_118 ( V_48 ) , V_437 ) ;
V_3 -> V_49 = F_246 ( F_212 , V_48 , NULL ) ;
if ( ! V_3 -> V_49 ) {
F_44 ( V_81
L_69 ,
F_118 ( V_48 ) ) ;
goto abort;
}
return V_3 ;
abort:
if ( V_3 ) {
F_232 ( V_3 ) ;
return F_241 ( - V_440 ) ;
} else
return F_241 ( - V_231 ) ;
}
static int F_247 ( int V_436 , int V_446 , int V_25 , int V_87 )
{
switch ( V_446 ) {
case V_270 :
if ( V_436 < V_87 )
return 1 ;
break;
case V_271 :
if ( V_436 >= V_25 - V_87 )
return 1 ;
break;
case V_279 :
if ( V_436 == 0 ||
V_436 == V_25 - 1 )
return 1 ;
break;
case V_275 :
case V_276 :
case V_277 :
case V_278 :
if ( V_436 == V_25 - 1 )
return 1 ;
}
return 0 ;
}
static int F_248 ( struct V_48 * V_48 )
{
struct V_2 * V_3 ;
int V_447 = 0 ;
int V_448 = 0 ;
struct V_88 * V_89 ;
T_1 V_449 = 0 ;
if ( V_48 -> V_450 != V_86 )
F_44 ( V_451 L_70
L_71 ,
F_118 ( V_48 ) ) ;
if ( V_48 -> V_85 != V_86 ) {
T_1 V_452 , V_453 ;
int V_454 ;
int V_87 = ( V_48 -> V_199 == 6 ? 2 : 1 ) ;
if ( V_48 -> V_439 != V_48 -> V_199 ) {
F_44 ( V_81 L_72
L_73 ,
F_118 ( V_48 ) ) ;
return - V_419 ;
}
V_454 = V_48 -> V_25 - V_48 -> V_373 ;
V_452 = V_48 -> V_85 ;
if ( F_143 ( V_452 , V_48 -> V_354 *
( V_48 -> V_25 - V_87 ) ) ) {
F_44 ( V_81 L_74
L_75 , F_118 ( V_48 ) ) ;
return - V_419 ;
}
V_449 = V_452 * V_48 -> V_354 ;
V_453 = V_48 -> V_85 ;
F_143 ( V_453 , V_48 -> V_264 *
( V_454 - V_87 ) ) ;
if ( V_48 -> V_373 == 0 ) {
if ( ( V_452 * V_48 -> V_354 !=
V_453 * V_48 -> V_264 ) ||
V_48 -> V_339 == 0 ) {
F_44 ( V_81 L_76
L_77 ,
F_118 ( V_48 ) ) ;
return - V_419 ;
}
} else if ( V_48 -> V_373 < 0
? ( V_452 * V_48 -> V_354 <=
V_453 * V_48 -> V_264 )
: ( V_452 * V_48 -> V_354 >=
V_453 * V_48 -> V_264 ) ) {
F_44 ( V_81 L_78
L_79 ,
F_118 ( V_48 ) ) ;
return - V_419 ;
}
F_44 ( V_238 L_80 ,
F_118 ( V_48 ) ) ;
} else {
F_17 ( V_48 -> V_199 != V_48 -> V_439 ) ;
F_17 ( V_48 -> V_445 != V_48 -> V_441 ) ;
F_17 ( V_48 -> V_264 != V_48 -> V_354 ) ;
F_17 ( V_48 -> V_373 != 0 ) ;
}
if ( V_48 -> V_247 == NULL )
V_3 = F_240 ( V_48 ) ;
else
V_3 = V_48 -> V_247 ;
if ( F_249 ( V_3 ) )
return F_250 ( V_3 ) ;
V_48 -> V_49 = V_3 -> V_49 ;
V_3 -> V_49 = NULL ;
V_48 -> V_247 = V_3 ;
F_127 (rdev, &mddev->disks, same_set) {
if ( V_89 -> V_436 < 0 )
continue;
if ( F_14 ( V_91 , & V_89 -> V_58 ) ) {
V_447 ++ ;
continue;
}
if ( V_48 -> V_455 == 0 &&
V_48 -> V_456 > 90 )
V_89 -> V_329 = V_449 ;
if ( V_89 -> V_329 < V_449 ) {
if ( ! F_247 ( V_89 -> V_436 ,
V_3 -> V_260 ,
V_3 -> V_25 ,
V_3 -> V_87 ) )
continue;
}
if ( ! F_247 ( V_89 -> V_436 ,
V_3 -> V_261 ,
V_3 -> V_74 ,
V_3 -> V_87 ) )
continue;
V_448 ++ ;
}
V_48 -> V_84 = ( F_117 ( V_3 -> V_25 , V_3 -> V_74 )
- V_447 ) ;
if ( F_49 ( V_3 ) ) {
F_44 ( V_81 L_81
L_82 ,
F_118 ( V_48 ) , V_48 -> V_84 , V_3 -> V_25 ) ;
goto abort;
}
V_48 -> V_398 &= ~ ( V_48 -> V_264 - 1 ) ;
V_48 -> V_457 = V_48 -> V_398 ;
if ( V_48 -> V_84 > V_448 &&
V_48 -> V_450 != V_86 ) {
if ( V_48 -> V_458 )
F_44 ( V_244
L_83
L_84 ,
F_118 ( V_48 ) ) ;
else {
F_44 ( V_81
L_85 ,
F_118 ( V_48 ) ) ;
goto abort;
}
}
if ( V_48 -> V_84 == 0 )
F_44 ( V_238 L_86
L_87 , F_118 ( V_48 ) , V_3 -> V_199 ,
V_48 -> V_25 - V_48 -> V_84 , V_48 -> V_25 ,
V_48 -> V_441 ) ;
else
F_44 ( V_252 L_88
L_89 ,
F_118 ( V_48 ) , V_3 -> V_199 ,
V_48 -> V_25 - V_48 -> V_84 ,
V_48 -> V_25 , V_48 -> V_441 ) ;
F_251 ( V_3 ) ;
if ( V_3 -> V_372 != V_86 ) {
V_3 -> V_374 = V_3 -> V_372 ;
F_114 ( & V_3 -> V_341 , 0 ) ;
F_21 ( V_408 , & V_48 -> V_249 ) ;
F_21 ( V_316 , & V_48 -> V_249 ) ;
F_61 ( V_405 , & V_48 -> V_249 ) ;
F_61 ( V_459 , & V_48 -> V_249 ) ;
V_48 -> V_460 = F_246 ( V_461 , V_48 ,
L_90 ) ;
}
if ( V_48 -> V_462 == & V_463 )
V_48 -> V_462 = NULL ;
else if ( V_48 -> V_393 . V_464 &&
F_252 ( & V_48 -> V_393 , & V_463 ) )
F_44 ( V_244
L_91 ,
F_118 ( V_48 ) ) ;
F_253 ( V_48 , F_198 ( V_48 , 0 , 0 ) ) ;
if ( V_48 -> V_465 ) {
int V_466 ;
int V_265 = V_3 -> V_74 - V_3 -> V_87 ;
int V_255 = V_265 *
( ( V_48 -> V_264 << 9 ) / V_421 ) ;
if ( V_48 -> V_465 -> V_467 . V_468 < 2 * V_255 )
V_48 -> V_465 -> V_467 . V_468 = 2 * V_255 ;
F_254 ( V_48 -> V_465 , F_171 ) ;
V_48 -> V_465 -> V_467 . V_469 = V_48 ;
V_48 -> V_465 -> V_467 . V_470 = F_169 ;
V_466 = V_48 -> V_264 << 9 ;
F_255 ( V_48 -> V_465 , V_466 ) ;
F_256 ( V_48 -> V_465 , V_466 *
( V_3 -> V_25 - V_3 -> V_87 ) ) ;
F_127 (rdev, &mddev->disks, same_set)
F_257 ( V_48 -> V_221 , V_89 -> V_121 ,
V_89 -> V_125 << 9 ) ;
}
return 0 ;
abort:
F_258 ( & V_48 -> V_49 ) ;
F_251 ( V_3 ) ;
F_232 ( V_3 ) ;
V_48 -> V_247 = NULL ;
F_44 ( V_252 L_92 , F_118 ( V_48 ) ) ;
return - V_440 ;
}
static int F_259 ( struct V_48 * V_48 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
F_258 ( & V_48 -> V_49 ) ;
if ( V_48 -> V_465 )
V_48 -> V_465 -> V_467 . V_470 = NULL ;
F_232 ( V_3 ) ;
V_48 -> V_247 = NULL ;
V_48 -> V_462 = & V_463 ;
return 0 ;
}
static void F_260 ( struct V_471 * V_472 , struct V_48 * V_48 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
int V_67 ;
F_261 ( V_472 , L_93 , V_48 -> V_199 ,
V_48 -> V_264 / 2 , V_48 -> V_445 ) ;
F_261 ( V_472 , L_94 , V_3 -> V_25 , V_3 -> V_25 - V_48 -> V_84 ) ;
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ )
F_261 ( V_472 , L_95 ,
V_3 -> V_23 [ V_67 ] . V_89 &&
F_14 ( V_91 , & V_3 -> V_23 [ V_67 ] . V_89 -> V_58 ) ? L_96 : L_97 ) ;
F_261 ( V_472 , L_98 ) ;
}
static void F_251 ( struct V_2 * V_3 )
{
int V_67 ;
struct V_228 * V_473 ;
F_44 ( V_474 L_99 ) ;
if ( ! V_3 ) {
F_44 ( L_100 ) ;
return;
}
F_44 ( V_474 L_101 , V_3 -> V_199 ,
V_3 -> V_25 ,
V_3 -> V_25 - V_3 -> V_48 -> V_84 ) ;
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ ) {
char V_235 [ V_236 ] ;
V_473 = V_3 -> V_23 + V_67 ;
if ( V_473 -> V_89 )
F_44 ( V_474 L_102 ,
V_67 , ! F_14 ( V_90 , & V_473 -> V_89 -> V_58 ) ,
F_137 ( V_473 -> V_89 -> V_121 , V_235 ) ) ;
}
}
static int F_262 ( struct V_48 * V_48 )
{
int V_67 ;
struct V_2 * V_3 = V_48 -> V_247 ;
struct V_228 * V_473 ;
int V_27 = 0 ;
unsigned long V_58 ;
for ( V_67 = 0 ; V_67 < V_3 -> V_25 ; V_67 ++ ) {
V_473 = V_3 -> V_23 + V_67 ;
if ( V_473 -> V_89
&& V_473 -> V_89 -> V_329 == V_86
&& ! F_14 ( V_90 , & V_473 -> V_89 -> V_58 )
&& ! F_145 ( V_91 , & V_473 -> V_89 -> V_58 ) ) {
V_27 ++ ;
F_263 ( V_473 -> V_89 -> V_475 ) ;
}
}
F_27 ( & V_3 -> V_59 , V_58 ) ;
V_48 -> V_84 -= V_27 ;
F_28 ( & V_3 -> V_59 , V_58 ) ;
F_251 ( V_3 ) ;
return V_27 ;
}
static int F_264 ( struct V_48 * V_48 , int V_476 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
int V_230 = 0 ;
struct V_88 * V_89 ;
struct V_228 * V_66 = V_3 -> V_23 + V_476 ;
F_251 ( V_3 ) ;
V_89 = V_66 -> V_89 ;
if ( V_89 ) {
if ( V_476 >= V_3 -> V_25 &&
V_3 -> V_372 == V_86 )
F_21 ( V_91 , & V_89 -> V_58 ) ;
if ( F_14 ( V_91 , & V_89 -> V_58 ) ||
F_19 ( & V_89 -> V_111 ) ) {
V_230 = - V_477 ;
goto abort;
}
if ( ! F_14 ( V_90 , & V_89 -> V_58 ) &&
V_48 -> V_303 != V_3 -> V_303 &&
! F_49 ( V_3 ) &&
V_476 < V_3 -> V_25 ) {
V_230 = - V_477 ;
goto abort;
}
V_66 -> V_89 = NULL ;
F_265 () ;
if ( F_19 ( & V_89 -> V_111 ) ) {
V_230 = - V_477 ;
V_66 -> V_89 = V_89 ;
}
}
abort:
F_251 ( V_3 ) ;
return V_230 ;
}
static int F_266 ( struct V_48 * V_48 , struct V_88 * V_89 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
int V_230 = - V_478 ;
int V_24 ;
struct V_228 * V_66 ;
int V_62 = 0 ;
int V_479 = V_3 -> V_25 - 1 ;
if ( V_48 -> V_303 == V_3 -> V_303 )
return - V_477 ;
if ( F_49 ( V_3 ) )
return - V_419 ;
if ( V_89 -> V_436 >= 0 )
V_62 = V_479 = V_89 -> V_436 ;
if ( V_89 -> V_443 >= 0 &&
V_89 -> V_443 >= V_62 &&
V_3 -> V_23 [ V_89 -> V_443 ] . V_89 == NULL )
V_24 = V_89 -> V_443 ;
else
V_24 = V_62 ;
for ( ; V_24 <= V_479 ; V_24 ++ )
if ( ( V_66 = V_3 -> V_23 + V_24 ) -> V_89 == NULL ) {
F_21 ( V_91 , & V_89 -> V_58 ) ;
V_89 -> V_436 = V_24 ;
V_230 = 0 ;
if ( V_89 -> V_443 != V_24 )
V_3 -> V_407 = 1 ;
F_267 ( V_66 -> V_89 , V_89 ) ;
break;
}
F_251 ( V_3 ) ;
return V_230 ;
}
static int F_268 ( struct V_48 * V_48 , T_1 V_11 )
{
V_11 &= ~ ( ( T_1 ) V_48 -> V_264 - 1 ) ;
F_253 ( V_48 , F_198 ( V_48 , V_11 ,
V_48 -> V_25 ) ) ;
if ( V_48 -> V_480 >
F_198 ( V_48 , V_11 , V_48 -> V_25 ) )
return - V_419 ;
F_269 ( V_48 -> V_221 , V_48 -> V_480 ) ;
F_270 ( V_48 -> V_221 ) ;
if ( V_11 > V_48 -> V_398 &&
V_48 -> V_450 > V_48 -> V_398 ) {
V_48 -> V_450 = V_48 -> V_398 ;
F_61 ( V_481 , & V_48 -> V_249 ) ;
}
V_48 -> V_398 = V_11 ;
V_48 -> V_457 = V_11 ;
return 0 ;
}
static int F_271 ( struct V_48 * V_48 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
if ( ( ( V_48 -> V_264 << 9 ) / V_134 ) * 4
> V_3 -> V_96 ||
( ( V_48 -> V_354 << 9 ) / V_134 ) * 4
> V_3 -> V_96 ) {
F_44 ( V_244 L_103 ,
F_118 ( V_48 ) ,
( ( F_117 ( V_48 -> V_264 , V_48 -> V_354 ) << 9 )
/ V_134 ) * 4 ) ;
return 0 ;
}
return 1 ;
}
static int F_272 ( struct V_48 * V_48 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
if ( V_48 -> V_373 == 0 &&
V_48 -> V_441 == V_48 -> V_445 &&
V_48 -> V_354 == V_48 -> V_264 )
return 0 ;
if ( V_48 -> V_293 )
return - V_477 ;
if ( F_49 ( V_3 ) )
return - V_419 ;
if ( V_48 -> V_373 < 0 ) {
int F_225 = 2 ;
if ( V_48 -> V_199 == 6 )
F_225 = 4 ;
if ( V_48 -> V_25 + V_48 -> V_373 < F_225 )
return - V_419 ;
}
if ( ! F_271 ( V_48 ) )
return - V_482 ;
return F_121 ( V_3 , V_3 -> V_25 + V_48 -> V_373 ) ;
}
static int F_273 ( struct V_48 * V_48 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
struct V_88 * V_89 ;
int V_483 = 0 ;
unsigned long V_58 ;
if ( F_14 ( V_459 , & V_48 -> V_249 ) )
return - V_477 ;
if ( ! F_271 ( V_48 ) )
return - V_482 ;
F_127 (rdev, &mddev->disks, same_set)
if ( ! F_14 ( V_91 , & V_89 -> V_58 )
&& ! F_14 ( V_90 , & V_89 -> V_58 ) )
V_483 ++ ;
if ( V_483 - V_48 -> V_84 < V_48 -> V_373 - V_3 -> V_87 )
return - V_419 ;
if ( F_198 ( V_48 , 0 , V_3 -> V_25 + V_48 -> V_373 )
< V_48 -> V_480 ) {
F_44 ( V_81 L_104
L_105 , F_118 ( V_48 ) ) ;
return - V_419 ;
}
F_114 ( & V_3 -> V_341 , 0 ) ;
F_54 ( & V_3 -> V_59 ) ;
V_3 -> V_74 = V_3 -> V_25 ;
V_3 -> V_25 += V_48 -> V_373 ;
V_3 -> V_263 = V_3 -> V_264 ;
V_3 -> V_264 = V_48 -> V_354 ;
V_3 -> V_261 = V_3 -> V_260 ;
V_3 -> V_260 = V_48 -> V_441 ;
if ( V_48 -> V_373 < 0 )
V_3 -> V_372 = F_198 ( V_48 , 0 , 0 ) ;
else
V_3 -> V_372 = 0 ;
V_3 -> V_374 = V_3 -> V_372 ;
V_3 -> V_73 ++ ;
F_57 ( & V_3 -> V_59 ) ;
if ( V_48 -> V_373 >= 0 ) {
int V_484 = 0 ;
F_127 (rdev, &mddev->disks, same_set)
if ( V_89 -> V_436 < 0 &&
! F_14 ( V_90 , & V_89 -> V_58 ) ) {
if ( F_266 ( V_48 , V_89 ) == 0 ) {
if ( V_89 -> V_436
>= V_3 -> V_74 ) {
F_61 ( V_91 , & V_89 -> V_58 ) ;
V_484 ++ ;
} else
V_89 -> V_329 = 0 ;
if ( F_274 ( V_48 , V_89 ) )
;
}
} else if ( V_89 -> V_436 >= V_3 -> V_74
&& ! F_14 ( V_90 , & V_89 -> V_58 ) ) {
F_61 ( V_91 , & V_89 -> V_58 ) ;
V_484 ++ ;
}
F_27 ( & V_3 -> V_59 , V_58 ) ;
V_48 -> V_84 += ( V_3 -> V_25 - V_3 -> V_74 )
- V_484 ;
F_28 ( & V_3 -> V_59 , V_58 ) ;
}
V_48 -> V_25 = V_3 -> V_25 ;
V_48 -> V_85 = V_3 -> V_372 ;
F_61 ( V_251 , & V_48 -> V_58 ) ;
F_21 ( V_408 , & V_48 -> V_249 ) ;
F_21 ( V_316 , & V_48 -> V_249 ) ;
F_61 ( V_405 , & V_48 -> V_249 ) ;
F_61 ( V_459 , & V_48 -> V_249 ) ;
V_48 -> V_460 = F_246 ( V_461 , V_48 ,
L_90 ) ;
if ( ! V_48 -> V_460 ) {
V_48 -> V_249 = 0 ;
F_54 ( & V_3 -> V_59 ) ;
V_48 -> V_25 = V_3 -> V_25 = V_3 -> V_74 ;
V_3 -> V_372 = V_86 ;
F_57 ( & V_3 -> V_59 ) ;
return - V_485 ;
}
V_3 -> V_395 = V_394 ;
F_22 ( V_48 -> V_460 ) ;
F_275 ( V_48 ) ;
return 0 ;
}
static void F_205 ( struct V_2 * V_3 )
{
if ( ! F_14 ( V_248 , & V_3 -> V_48 -> V_249 ) ) {
F_54 ( & V_3 -> V_59 ) ;
V_3 -> V_74 = V_3 -> V_25 ;
V_3 -> V_372 = V_86 ;
F_57 ( & V_3 -> V_59 ) ;
F_25 ( & V_3 -> V_211 ) ;
if ( V_3 -> V_48 -> V_465 ) {
int V_265 = V_3 -> V_25 - V_3 -> V_87 ;
int V_255 = V_265 * ( ( V_3 -> V_264 << 9 )
/ V_421 ) ;
if ( V_3 -> V_48 -> V_465 -> V_467 . V_468 < 2 * V_255 )
V_3 -> V_48 -> V_465 -> V_467 . V_468 = 2 * V_255 ;
}
}
}
static void F_276 ( struct V_48 * V_48 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
if ( ! F_14 ( V_248 , & V_48 -> V_249 ) ) {
if ( V_48 -> V_373 > 0 ) {
F_253 ( V_48 , F_198 ( V_48 , 0 , 0 ) ) ;
F_269 ( V_48 -> V_221 , V_48 -> V_480 ) ;
F_270 ( V_48 -> V_221 ) ;
} else {
int V_486 ;
V_48 -> V_84 = V_3 -> V_25 ;
for ( V_486 = 0 ; V_486 < V_3 -> V_25 ; V_486 ++ )
if ( V_3 -> V_23 [ V_486 ] . V_89 &&
F_14 ( V_91 ,
& V_3 -> V_23 [ V_486 ] . V_89 -> V_58 ) )
V_48 -> V_84 -- ;
for ( V_486 = V_3 -> V_25 ;
V_486 < V_3 -> V_25 - V_48 -> V_373 ;
V_486 ++ ) {
struct V_88 * V_89 = V_3 -> V_23 [ V_486 ] . V_89 ;
if ( V_89 && F_264 ( V_48 , V_486 ) == 0 ) {
F_277 ( V_48 , V_89 ) ;
V_89 -> V_436 = - 1 ;
}
}
}
V_48 -> V_445 = V_3 -> V_260 ;
V_48 -> V_264 = V_3 -> V_264 ;
V_48 -> V_85 = V_86 ;
V_48 -> V_373 = 0 ;
}
}
static void F_278 ( struct V_48 * V_48 , int V_36 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
switch( V_36 ) {
case 2 :
F_25 ( & V_3 -> V_211 ) ;
break;
case 1 :
F_54 ( & V_3 -> V_59 ) ;
V_3 -> V_94 = 2 ;
F_55 ( V_3 -> V_55 ,
F_19 ( & V_3 -> V_39 ) == 0 &&
F_19 ( & V_3 -> V_357 ) == 0 ,
V_3 -> V_59 , ) ;
V_3 -> V_94 = 1 ;
F_57 ( & V_3 -> V_59 ) ;
F_25 ( & V_3 -> V_211 ) ;
break;
case 0 :
F_54 ( & V_3 -> V_59 ) ;
V_3 -> V_94 = 0 ;
F_25 ( & V_3 -> V_55 ) ;
F_25 ( & V_3 -> V_211 ) ;
F_57 ( & V_3 -> V_59 ) ;
break;
}
}
static void * F_279 ( struct V_48 * V_48 , int V_199 )
{
struct V_487 * V_488 = V_48 -> V_247 ;
T_1 V_11 ;
if ( V_488 -> V_489 > 1 ) {
F_44 ( V_81 L_106 ,
F_118 ( V_48 ) ) ;
return F_241 ( - V_419 ) ;
}
V_11 = V_488 -> V_490 [ 0 ] . V_491 ;
F_143 ( V_11 , V_488 -> V_490 [ 0 ] . V_492 ) ;
V_48 -> V_398 = V_11 ;
V_48 -> V_439 = V_199 ;
V_48 -> V_441 = V_271 ;
V_48 -> V_354 = V_48 -> V_264 ;
V_48 -> V_25 += 1 ;
V_48 -> V_373 = 1 ;
V_48 -> V_450 = V_86 ;
return F_240 ( V_48 ) ;
}
static void * F_280 ( struct V_48 * V_48 )
{
int V_493 ;
if ( V_48 -> V_25 != 2 ||
V_48 -> V_84 > 1 )
return F_241 ( - V_419 ) ;
V_493 = 64 * 2 ;
while ( V_493 && ( V_48 -> V_480 & ( V_493 - 1 ) ) )
V_493 >>= 1 ;
if ( ( V_493 << 9 ) < V_134 )
return F_241 ( - V_419 ) ;
V_48 -> V_439 = 5 ;
V_48 -> V_441 = V_268 ;
V_48 -> V_354 = V_493 ;
return F_240 ( V_48 ) ;
}
static void * F_281 ( struct V_48 * V_48 )
{
int V_441 ;
switch ( V_48 -> V_445 ) {
case V_275 :
V_441 = V_266 ;
break;
case V_276 :
V_441 = V_267 ;
break;
case V_277 :
V_441 = V_268 ;
break;
case V_278 :
V_441 = V_269 ;
break;
case V_279 :
V_441 = V_270 ;
break;
case V_271 :
V_441 = V_271 ;
break;
default:
return F_241 ( - V_419 ) ;
}
V_48 -> V_439 = 5 ;
V_48 -> V_441 = V_441 ;
V_48 -> V_373 = - 1 ;
V_48 -> V_25 -= 1 ;
return F_240 ( V_48 ) ;
}
static int F_282 ( struct V_48 * V_48 )
{
struct V_2 * V_3 = V_48 -> V_247 ;
int V_494 = V_48 -> V_354 ;
if ( V_48 -> V_441 >= 0 && ! F_242 ( V_48 -> V_441 ) )
return - V_419 ;
if ( V_494 > 0 ) {
if ( ! F_244 ( V_494 ) )
return - V_419 ;
if ( V_494 < ( V_421 >> 9 ) )
return - V_419 ;
if ( V_48 -> V_480 & ( V_494 - 1 ) )
return - V_419 ;
}
if ( V_48 -> V_25 == 2 ) {
if ( V_48 -> V_441 >= 0 ) {
V_3 -> V_260 = V_48 -> V_441 ;
V_48 -> V_445 = V_48 -> V_441 ;
}
if ( V_494 > 0 ) {
V_3 -> V_264 = V_494 ;
V_48 -> V_264 = V_494 ;
}
F_61 ( V_251 , & V_48 -> V_58 ) ;
F_22 ( V_48 -> V_49 ) ;
}
return F_272 ( V_48 ) ;
}
static int F_283 ( struct V_48 * V_48 )
{
int V_494 = V_48 -> V_354 ;
if ( V_48 -> V_441 >= 0 && ! F_243 ( V_48 -> V_441 ) )
return - V_419 ;
if ( V_494 > 0 ) {
if ( ! F_244 ( V_494 ) )
return - V_419 ;
if ( V_494 < ( V_421 >> 9 ) )
return - V_419 ;
if ( V_48 -> V_480 & ( V_494 - 1 ) )
return - V_419 ;
}
return F_272 ( V_48 ) ;
}
static void * F_284 ( struct V_48 * V_48 )
{
if ( V_48 -> V_199 == 0 )
return F_279 ( V_48 , 5 ) ;
if ( V_48 -> V_199 == 1 )
return F_280 ( V_48 ) ;
if ( V_48 -> V_199 == 4 ) {
V_48 -> V_441 = V_271 ;
V_48 -> V_439 = 5 ;
return F_240 ( V_48 ) ;
}
if ( V_48 -> V_199 == 6 )
return F_281 ( V_48 ) ;
return F_241 ( - V_419 ) ;
}
static void * F_285 ( struct V_48 * V_48 )
{
if ( V_48 -> V_199 == 0 )
return F_279 ( V_48 , 4 ) ;
if ( V_48 -> V_199 == 5 &&
V_48 -> V_445 == V_271 ) {
V_48 -> V_441 = 0 ;
V_48 -> V_439 = 4 ;
return F_240 ( V_48 ) ;
}
return F_241 ( - V_419 ) ;
}
static void * F_286 ( struct V_48 * V_48 )
{
int V_441 ;
if ( V_48 -> V_495 != & V_496 )
return F_241 ( - V_419 ) ;
if ( V_48 -> V_84 > 1 )
return F_241 ( - V_419 ) ;
if ( V_48 -> V_25 > 253 )
return F_241 ( - V_419 ) ;
if ( V_48 -> V_25 < 3 )
return F_241 ( - V_419 ) ;
switch ( V_48 -> V_445 ) {
case V_266 :
V_441 = V_275 ;
break;
case V_267 :
V_441 = V_276 ;
break;
case V_268 :
V_441 = V_277 ;
break;
case V_269 :
V_441 = V_278 ;
break;
case V_270 :
V_441 = V_279 ;
break;
case V_271 :
V_441 = V_271 ;
break;
default:
return F_241 ( - V_419 ) ;
}
V_48 -> V_439 = 6 ;
V_48 -> V_441 = V_441 ;
V_48 -> V_373 = 1 ;
V_48 -> V_25 += 1 ;
return F_240 ( V_48 ) ;
}
static int T_7 F_287 ( void )
{
F_288 ( & V_497 ) ;
F_288 ( & V_496 ) ;
F_288 ( & V_498 ) ;
return 0 ;
}
static void F_289 ( void )
{
F_290 ( & V_497 ) ;
F_290 ( & V_496 ) ;
F_290 ( & V_498 ) ;
}
