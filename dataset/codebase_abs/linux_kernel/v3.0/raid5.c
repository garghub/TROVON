static inline int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 & 0xffff ;
}
static inline int F_2 ( struct V_1 * V_1 )
{
return ( V_1 -> V_2 >> 16 ) & 0xffff ;
}
static inline int F_3 ( struct V_1 * V_1 )
{
-- V_1 -> V_2 ;
return F_1 ( V_1 ) ;
}
static inline int F_4 ( struct V_1 * V_1 )
{
unsigned short V_3 = F_2 ( V_1 ) ;
-- V_3 ;
V_1 -> V_2 = ( V_3 << 16 ) | F_1 ( V_1 ) ;
return V_3 ;
}
static inline void F_5 ( struct V_1 * V_1 , unsigned int V_4 )
{
V_1 -> V_2 = F_1 ( V_1 ) | ( V_4 << 16 ) ;
}
static inline int F_6 ( struct V_5 * V_6 )
{
if ( V_6 -> V_7 )
return 0 ;
if ( V_6 -> V_8 == V_6 -> V_9 - 1 )
return 0 ;
else
return V_6 -> V_8 + 1 ;
}
static inline int F_7 ( int V_10 , int V_11 )
{
V_10 ++ ;
return ( V_10 < V_11 ) ? V_10 : 0 ;
}
static int F_8 ( int V_12 , struct V_5 * V_6 ,
int * V_13 , int V_14 )
{
int V_15 = * V_13 ;
if ( V_6 -> V_7 )
( * V_13 ) ++ ;
if ( V_12 == V_6 -> V_16 )
return V_14 ;
if ( V_12 == V_6 -> V_8 )
return V_14 + 1 ;
if ( ! V_6 -> V_7 )
( * V_13 ) ++ ;
return V_15 ;
}
static void F_9 ( struct V_1 * V_17 )
{
struct V_1 * V_18 = V_17 ;
while ( V_18 ) {
V_17 = V_18 -> V_19 ;
V_18 -> V_19 = NULL ;
V_18 -> V_20 = 0 ;
F_10 ( V_18 , 0 ) ;
V_18 = V_17 ;
}
}
static int F_11 ( struct V_5 * V_6 )
{
return V_6 -> V_21 || V_6 -> V_22 ||
F_12 ( V_23 , & V_6 -> V_24 ) ||
F_12 ( V_25 , & V_6 -> V_24 ) ;
}
static void F_13 ( T_1 * V_26 , struct V_5 * V_6 )
{
if ( F_14 ( & V_6 -> V_13 ) ) {
F_15 ( ! F_16 ( & V_6 -> V_27 ) ) ;
F_15 ( F_17 ( & V_26 -> V_28 ) == 0 ) ;
if ( F_12 ( V_29 , & V_6 -> V_24 ) ) {
if ( F_12 ( V_30 , & V_6 -> V_24 ) )
F_18 ( & V_6 -> V_27 , & V_26 -> V_31 ) ;
else if ( F_12 ( V_32 , & V_6 -> V_24 ) &&
V_6 -> V_33 - V_26 -> V_34 > 0 )
F_18 ( & V_6 -> V_27 , & V_26 -> V_35 ) ;
else {
F_19 ( V_32 , & V_6 -> V_24 ) ;
F_18 ( & V_6 -> V_27 , & V_26 -> V_36 ) ;
}
F_20 ( V_26 -> V_37 -> V_38 ) ;
} else {
F_15 ( F_11 ( V_6 ) ) ;
if ( F_21 ( V_39 , & V_6 -> V_24 ) ) {
F_22 ( & V_26 -> V_40 ) ;
if ( F_17 ( & V_26 -> V_40 ) < V_41 )
F_20 ( V_26 -> V_37 -> V_38 ) ;
}
F_22 ( & V_26 -> V_28 ) ;
if ( ! F_12 ( V_42 , & V_6 -> V_24 ) ) {
F_18 ( & V_6 -> V_27 , & V_26 -> V_43 ) ;
F_23 ( & V_26 -> V_44 ) ;
if ( V_26 -> V_45 )
F_20 ( V_26 -> V_37 -> V_38 ) ;
}
}
}
}
static void F_24 ( struct V_5 * V_6 )
{
T_1 * V_26 = V_6 -> V_46 ;
unsigned long V_47 ;
F_25 ( & V_26 -> V_48 , V_47 ) ;
F_13 ( V_26 , V_6 ) ;
F_26 ( & V_26 -> V_48 , V_47 ) ;
}
static inline void F_27 ( struct V_5 * V_6 )
{
F_28 ( L_1 ,
( unsigned long long ) V_6 -> V_49 ) ;
F_29 ( & V_6 -> V_50 ) ;
}
static inline void F_30 ( T_1 * V_26 , struct V_5 * V_6 )
{
struct V_51 * V_52 = F_31 ( V_26 , V_6 -> V_49 ) ;
F_28 ( L_2 ,
( unsigned long long ) V_6 -> V_49 ) ;
F_32 () ;
F_33 ( & V_6 -> V_50 , V_52 ) ;
}
static struct V_5 * F_34 ( T_1 * V_26 )
{
struct V_5 * V_6 = NULL ;
struct V_53 * V_54 ;
F_32 () ;
if ( F_16 ( & V_26 -> V_43 ) )
goto V_55;
V_54 = V_26 -> V_43 . V_56 ;
V_6 = F_35 ( V_54 , struct V_5 , V_27 ) ;
F_36 ( V_54 ) ;
F_27 ( V_6 ) ;
F_37 ( & V_26 -> V_28 ) ;
V_55:
return V_6 ;
}
static void F_38 ( struct V_5 * V_6 )
{
struct V_57 * V_58 ;
int V_59 ;
int V_60 = V_6 -> V_46 -> V_61 ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
V_58 = V_6 -> V_62 [ V_59 ] . V_57 ;
if ( ! V_58 )
continue;
V_6 -> V_62 [ V_59 ] . V_57 = NULL ;
F_39 ( V_58 ) ;
}
}
static int F_40 ( struct V_5 * V_6 )
{
int V_59 ;
int V_60 = V_6 -> V_46 -> V_61 ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
struct V_57 * V_57 ;
if ( ! ( V_57 = F_41 ( V_63 ) ) ) {
return 1 ;
}
V_6 -> V_62 [ V_59 ] . V_57 = V_57 ;
}
return 0 ;
}
static void F_42 ( struct V_5 * V_6 , T_2 V_49 , int V_64 )
{
T_1 * V_26 = V_6 -> V_46 ;
int V_59 ;
F_15 ( F_17 ( & V_6 -> V_13 ) != 0 ) ;
F_15 ( F_12 ( V_29 , & V_6 -> V_24 ) ) ;
F_15 ( F_11 ( V_6 ) ) ;
F_32 () ;
F_28 ( L_3 ,
( unsigned long long ) V_6 -> V_49 ) ;
F_27 ( V_6 ) ;
V_6 -> V_65 = V_26 -> V_65 - V_64 ;
V_6 -> V_9 = V_64 ? V_26 -> V_66 : V_26 -> V_11 ;
V_6 -> V_49 = V_49 ;
F_43 ( V_49 , V_26 , V_64 , V_6 ) ;
V_6 -> V_24 = 0 ;
for ( V_59 = V_6 -> V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( V_62 -> V_68 || V_62 -> V_69 || V_62 -> V_70 || V_62 -> V_71 ||
F_12 ( V_72 , & V_62 -> V_47 ) ) {
F_44 ( V_73 L_4 ,
( unsigned long long ) V_6 -> V_49 , V_59 , V_62 -> V_68 ,
V_62 -> V_69 , V_62 -> V_70 , V_62 -> V_71 ,
F_12 ( V_72 , & V_62 -> V_47 ) ) ;
F_45 () ;
}
V_62 -> V_47 = 0 ;
F_46 ( V_6 , V_59 , V_64 ) ;
}
F_30 ( V_26 , V_6 ) ;
}
static struct V_5 * F_47 ( T_1 * V_26 , T_2 V_49 ,
short V_65 )
{
struct V_5 * V_6 ;
struct V_74 * V_75 ;
F_32 () ;
F_28 ( L_5 , ( unsigned long long ) V_49 ) ;
F_48 (sh, hn, stripe_hash(conf, sector), hash)
if ( V_6 -> V_49 == V_49 && V_6 -> V_65 == V_65 )
return V_6 ;
F_28 ( L_6 , ( unsigned long long ) V_49 ) ;
return NULL ;
}
static int F_49 ( T_1 * V_26 )
{
int V_76 ;
int V_59 ;
if ( V_26 -> V_37 -> V_77 == V_78 )
return V_26 -> V_37 -> V_76 > V_26 -> V_79 ;
F_50 () ;
V_76 = 0 ;
for ( V_59 = 0 ; V_59 < V_26 -> V_66 ; V_59 ++ ) {
T_3 * V_80 = F_51 ( V_26 -> V_9 [ V_59 ] . V_80 ) ;
if ( ! V_80 || F_12 ( V_81 , & V_80 -> V_47 ) )
V_76 ++ ;
else if ( F_12 ( V_82 , & V_80 -> V_47 ) )
;
else
if ( V_26 -> V_11 >= V_26 -> V_66 )
V_76 ++ ;
}
F_52 () ;
if ( V_76 > V_26 -> V_79 )
return 1 ;
F_50 () ;
V_76 = 0 ;
for ( V_59 = 0 ; V_59 < V_26 -> V_11 ; V_59 ++ ) {
T_3 * V_80 = F_51 ( V_26 -> V_9 [ V_59 ] . V_80 ) ;
if ( ! V_80 || F_12 ( V_81 , & V_80 -> V_47 ) )
V_76 ++ ;
else if ( F_12 ( V_82 , & V_80 -> V_47 ) )
;
else
if ( V_26 -> V_11 <= V_26 -> V_66 )
V_76 ++ ;
}
F_52 () ;
if ( V_76 > V_26 -> V_79 )
return 1 ;
return 0 ;
}
static struct V_5 *
F_53 ( T_1 * V_26 , T_2 V_49 ,
int V_64 , int V_83 , int V_84 )
{
struct V_5 * V_6 ;
F_28 ( L_7 , ( unsigned long long ) V_49 ) ;
F_54 ( & V_26 -> V_48 ) ;
do {
F_55 ( V_26 -> V_44 ,
V_26 -> V_85 == 0 || V_84 ,
V_26 -> V_48 , ) ;
V_6 = F_47 ( V_26 , V_49 , V_26 -> V_65 - V_64 ) ;
if ( ! V_6 ) {
if ( ! V_26 -> V_86 )
V_6 = F_34 ( V_26 ) ;
if ( V_83 && V_6 == NULL )
break;
if ( ! V_6 ) {
V_26 -> V_86 = 1 ;
F_55 ( V_26 -> V_44 ,
! F_16 ( & V_26 -> V_43 ) &&
( F_17 ( & V_26 -> V_28 )
< ( V_26 -> V_87 * 3 / 4 )
|| ! V_26 -> V_86 ) ,
V_26 -> V_48 ,
) ;
V_26 -> V_86 = 0 ;
} else
F_42 ( V_6 , V_49 , V_64 ) ;
} else {
if ( F_17 ( & V_6 -> V_13 ) ) {
F_15 ( ! F_16 ( & V_6 -> V_27 )
&& ! F_12 ( V_42 , & V_6 -> V_24 ) ) ;
} else {
if ( ! F_12 ( V_29 , & V_6 -> V_24 ) )
F_37 ( & V_26 -> V_28 ) ;
if ( F_16 ( & V_6 -> V_27 ) &&
! F_12 ( V_42 , & V_6 -> V_24 ) )
F_45 () ;
F_36 ( & V_6 -> V_27 ) ;
}
}
} while ( V_6 == NULL );
if ( V_6 )
F_37 ( & V_6 -> V_13 ) ;
F_56 ( & V_26 -> V_48 ) ;
return V_6 ;
}
static void F_57 ( struct V_5 * V_6 , struct V_88 * V_89 )
{
T_1 * V_26 = V_6 -> V_46 ;
int V_59 , V_9 = V_6 -> V_9 ;
F_58 () ;
for ( V_59 = V_9 ; V_59 -- ; ) {
int V_90 ;
struct V_1 * V_18 ;
T_3 * V_80 ;
if ( F_21 ( V_91 , & V_6 -> V_62 [ V_59 ] . V_47 ) ) {
if ( F_21 ( V_92 , & V_6 -> V_62 [ V_59 ] . V_47 ) )
V_90 = V_93 ;
else
V_90 = V_94 ;
} else if ( F_21 ( V_95 , & V_6 -> V_62 [ V_59 ] . V_47 ) )
V_90 = V_96 ;
else
continue;
V_18 = & V_6 -> V_62 [ V_59 ] . V_97 ;
V_18 -> V_98 = V_90 ;
if ( V_90 & V_94 )
V_18 -> V_99 = V_100 ;
else
V_18 -> V_99 = V_101 ;
F_50 () ;
V_80 = F_51 ( V_26 -> V_9 [ V_59 ] . V_80 ) ;
if ( V_80 && F_12 ( V_81 , & V_80 -> V_47 ) )
V_80 = NULL ;
if ( V_80 )
F_37 ( & V_80 -> V_102 ) ;
F_52 () ;
if ( V_80 ) {
if ( V_89 -> V_103 || V_89 -> V_104 || V_89 -> V_105 )
F_59 ( V_80 -> V_106 , V_107 ) ;
F_60 ( V_108 , & V_6 -> V_24 ) ;
V_18 -> V_109 = V_80 -> V_106 ;
F_28 ( L_8 ,
V_110 , ( unsigned long long ) V_6 -> V_49 ,
V_18 -> V_98 , V_59 ) ;
F_37 ( & V_6 -> V_13 ) ;
V_18 -> V_111 = V_6 -> V_49 + V_80 -> V_112 ;
V_18 -> V_113 = 1 << V_114 ;
V_18 -> V_115 = 1 ;
V_18 -> V_116 = 1 ;
V_18 -> V_117 = 0 ;
V_18 -> V_118 = & V_6 -> V_62 [ V_59 ] . V_119 ;
V_18 -> V_118 [ 0 ] . V_120 = V_121 ;
V_18 -> V_118 [ 0 ] . V_122 = 0 ;
V_18 -> V_20 = V_121 ;
V_18 -> V_19 = NULL ;
if ( ( V_90 & V_94 ) &&
F_12 ( V_123 , & V_6 -> V_62 [ V_59 ] . V_47 ) )
F_61 ( V_107 ,
& V_80 -> V_124 ) ;
F_62 ( V_18 ) ;
} else {
if ( V_90 & V_94 )
F_60 ( V_125 , & V_6 -> V_24 ) ;
F_28 ( L_9 ,
V_18 -> V_98 , V_59 , ( unsigned long long ) V_6 -> V_49 ) ;
F_19 ( V_72 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
F_60 ( V_29 , & V_6 -> V_24 ) ;
}
}
}
static struct V_126 *
F_63 ( int V_127 , struct V_1 * V_1 , struct V_57 * V_57 ,
T_2 V_49 , struct V_126 * V_128 )
{
struct V_129 * V_130 ;
struct V_57 * V_131 ;
int V_59 ;
int V_132 ;
struct V_133 V_134 ;
enum V_135 V_47 = 0 ;
if ( V_1 -> V_111 >= V_49 )
V_132 = ( signed ) ( V_1 -> V_111 - V_49 ) * 512 ;
else
V_132 = ( signed ) ( V_49 - V_1 -> V_111 ) * - 512 ;
if ( V_127 )
V_47 |= V_136 ;
F_64 ( & V_134 , V_47 , V_128 , NULL , NULL , NULL ) ;
F_65 (bvl, bio, i) {
int V_137 = V_130 -> V_120 ;
int V_138 ;
int V_139 = 0 ;
if ( V_132 < 0 ) {
V_139 = - V_132 ;
V_132 += V_139 ;
V_137 -= V_139 ;
}
if ( V_137 > 0 && V_132 + V_137 > V_121 )
V_138 = V_121 - V_132 ;
else
V_138 = V_137 ;
if ( V_138 > 0 ) {
V_139 += V_130 -> V_122 ;
V_131 = V_130 -> V_140 ;
if ( V_127 )
V_128 = F_66 ( V_57 , V_131 , V_132 ,
V_139 , V_138 , & V_134 ) ;
else
V_128 = F_66 ( V_131 , V_57 , V_139 ,
V_132 , V_138 , & V_134 ) ;
}
V_134 . V_141 = V_128 ;
if ( V_138 < V_137 )
break;
V_132 += V_137 ;
}
return V_128 ;
}
static void F_67 ( void * V_142 )
{
struct V_5 * V_6 = V_142 ;
struct V_1 * V_17 = NULL ;
T_1 * V_26 = V_6 -> V_46 ;
int V_59 ;
F_28 ( L_10 , V_110 ,
( unsigned long long ) V_6 -> V_49 ) ;
F_54 ( & V_26 -> V_48 ) ;
for ( V_59 = V_6 -> V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( F_21 ( V_143 , & V_62 -> V_47 ) ) {
struct V_1 * V_144 , * V_145 ;
F_15 ( ! V_62 -> V_69 ) ;
V_144 = V_62 -> V_69 ;
V_62 -> V_69 = NULL ;
while ( V_144 && V_144 -> V_111 <
V_62 -> V_49 + V_107 ) {
V_145 = F_68 ( V_144 , V_62 -> V_49 ) ;
if ( ! F_3 ( V_144 ) ) {
V_144 -> V_19 = V_17 ;
V_17 = V_144 ;
}
V_144 = V_145 ;
}
}
}
F_56 ( & V_26 -> V_48 ) ;
F_19 ( V_23 , & V_6 -> V_24 ) ;
F_9 ( V_17 ) ;
F_60 ( V_29 , & V_6 -> V_24 ) ;
F_24 ( V_6 ) ;
}
static void F_69 ( struct V_5 * V_6 )
{
struct V_126 * V_128 = NULL ;
T_1 * V_26 = V_6 -> V_46 ;
struct V_133 V_134 ;
int V_59 ;
F_28 ( L_10 , V_110 ,
( unsigned long long ) V_6 -> V_49 ) ;
for ( V_59 = V_6 -> V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( F_12 ( V_143 , & V_62 -> V_47 ) ) {
struct V_1 * V_144 ;
F_54 ( & V_26 -> V_48 ) ;
V_62 -> V_69 = V_144 = V_62 -> V_68 ;
V_62 -> V_68 = NULL ;
F_56 ( & V_26 -> V_48 ) ;
while ( V_144 && V_144 -> V_111 <
V_62 -> V_49 + V_107 ) {
V_128 = F_63 ( 0 , V_144 , V_62 -> V_57 ,
V_62 -> V_49 , V_128 ) ;
V_144 = F_68 ( V_144 , V_62 -> V_49 ) ;
}
}
}
F_37 ( & V_6 -> V_13 ) ;
F_64 ( & V_134 , V_146 , V_128 , F_67 , V_6 , NULL ) ;
F_70 ( & V_134 ) ;
}
static void F_71 ( struct V_5 * V_6 , int V_147 )
{
struct V_67 * V_148 ;
if ( V_147 < 0 )
return;
V_148 = & V_6 -> V_62 [ V_147 ] ;
F_60 ( V_149 , & V_148 -> V_47 ) ;
F_15 ( ! F_12 ( V_150 , & V_148 -> V_47 ) ) ;
F_19 ( V_150 , & V_148 -> V_47 ) ;
}
static void F_72 ( void * V_142 )
{
struct V_5 * V_6 = V_142 ;
F_28 ( L_10 , V_110 ,
( unsigned long long ) V_6 -> V_49 ) ;
F_71 ( V_6 , V_6 -> V_151 . V_147 ) ;
F_71 ( V_6 , V_6 -> V_151 . V_152 ) ;
F_19 ( V_25 , & V_6 -> V_24 ) ;
if ( V_6 -> V_21 == V_153 )
V_6 -> V_21 = V_154 ;
F_60 ( V_29 , & V_6 -> V_24 ) ;
F_24 ( V_6 ) ;
}
static T_4 * F_73 ( struct V_5 * V_6 ,
struct V_155 * V_156 )
{
return V_156 -> V_157 + sizeof( struct V_57 * ) * ( V_6 -> V_9 + 2 ) ;
}
static struct V_126 *
F_74 ( struct V_5 * V_6 , struct V_155 * V_156 )
{
int V_9 = V_6 -> V_9 ;
struct V_57 * * V_158 = V_156 -> V_157 ;
int V_147 = V_6 -> V_151 . V_147 ;
struct V_67 * V_148 = & V_6 -> V_62 [ V_147 ] ;
struct V_57 * V_159 = V_148 -> V_57 ;
int V_13 = 0 ;
struct V_126 * V_128 ;
struct V_133 V_134 ;
int V_59 ;
F_28 ( L_11 ,
V_110 , ( unsigned long long ) V_6 -> V_49 , V_147 ) ;
F_15 ( ! F_12 ( V_150 , & V_148 -> V_47 ) ) ;
for ( V_59 = V_9 ; V_59 -- ; )
if ( V_59 != V_147 )
V_158 [ V_13 ++ ] = V_6 -> V_62 [ V_59 ] . V_57 ;
F_37 ( & V_6 -> V_13 ) ;
F_64 ( & V_134 , V_136 | V_160 , NULL ,
F_72 , V_6 , F_73 ( V_6 , V_156 ) ) ;
if ( F_75 ( V_13 == 1 ) )
V_128 = F_66 ( V_159 , V_158 [ 0 ] , 0 , 0 , V_121 , & V_134 ) ;
else
V_128 = F_76 ( V_159 , V_158 , 0 , V_13 , V_121 , & V_134 ) ;
return V_128 ;
}
static int F_77 ( struct V_57 * * V_161 , struct V_5 * V_6 )
{
int V_9 = V_6 -> V_9 ;
int V_14 = V_6 -> V_7 ? V_9 : ( V_9 - 2 ) ;
int V_162 = F_6 ( V_6 ) ;
int V_13 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_9 ; V_59 ++ )
V_161 [ V_59 ] = NULL ;
V_13 = 0 ;
V_59 = V_162 ;
do {
int V_15 = F_8 ( V_59 , V_6 , & V_13 , V_14 ) ;
V_161 [ V_15 ] = V_6 -> V_62 [ V_59 ] . V_57 ;
V_59 = F_7 ( V_59 , V_9 ) ;
} while ( V_59 != V_162 );
return V_14 ;
}
static struct V_126 *
F_78 ( struct V_5 * V_6 , struct V_155 * V_156 )
{
int V_9 = V_6 -> V_9 ;
struct V_57 * * V_163 = V_156 -> V_157 ;
int V_147 ;
int V_8 = V_6 -> V_8 ;
struct V_126 * V_128 ;
struct V_133 V_134 ;
struct V_67 * V_148 ;
struct V_57 * V_164 ;
int V_59 ;
int V_13 ;
if ( V_6 -> V_151 . V_147 < 0 )
V_147 = V_6 -> V_151 . V_152 ;
else if ( V_6 -> V_151 . V_152 < 0 )
V_147 = V_6 -> V_151 . V_147 ;
else
F_45 () ;
F_15 ( V_147 < 0 ) ;
F_28 ( L_11 ,
V_110 , ( unsigned long long ) V_6 -> V_49 , V_147 ) ;
V_148 = & V_6 -> V_62 [ V_147 ] ;
F_15 ( ! F_12 ( V_150 , & V_148 -> V_47 ) ) ;
V_164 = V_148 -> V_57 ;
F_37 ( & V_6 -> V_13 ) ;
if ( V_147 == V_8 ) {
V_13 = F_77 ( V_163 , V_6 ) ;
V_163 [ V_13 ] = NULL ;
F_15 ( V_163 [ V_13 + 1 ] != V_164 ) ;
F_64 ( & V_134 , V_136 , NULL ,
F_72 , V_6 ,
F_73 ( V_6 , V_156 ) ) ;
V_128 = F_79 ( V_163 , 0 , V_13 + 2 , V_121 , & V_134 ) ;
} else {
V_13 = 0 ;
for ( V_59 = V_9 ; V_59 -- ; ) {
if ( V_59 == V_147 || V_59 == V_8 )
continue;
V_163 [ V_13 ++ ] = V_6 -> V_62 [ V_59 ] . V_57 ;
}
F_64 ( & V_134 , V_136 | V_160 ,
NULL , F_72 , V_6 ,
F_73 ( V_6 , V_156 ) ) ;
V_128 = F_76 ( V_164 , V_163 , 0 , V_13 , V_121 , & V_134 ) ;
}
return V_128 ;
}
static struct V_126 *
F_80 ( struct V_5 * V_6 , struct V_155 * V_156 )
{
int V_59 , V_13 , V_9 = V_6 -> V_9 ;
int V_14 = V_6 -> V_7 ? V_9 : V_9 - 2 ;
int V_162 = F_6 ( V_6 ) ;
int V_165 = - 1 , V_166 = - 1 ;
int V_147 = V_6 -> V_151 . V_147 ;
int V_152 = V_6 -> V_151 . V_152 ;
struct V_67 * V_148 = & V_6 -> V_62 [ V_147 ] ;
struct V_67 * V_167 = & V_6 -> V_62 [ V_152 ] ;
struct V_126 * V_128 ;
struct V_57 * * V_163 = V_156 -> V_157 ;
struct V_133 V_134 ;
F_28 ( L_12 ,
V_110 , ( unsigned long long ) V_6 -> V_49 , V_147 , V_152 ) ;
F_15 ( V_147 < 0 || V_152 < 0 ) ;
F_15 ( ! F_12 ( V_150 , & V_148 -> V_47 ) ) ;
F_15 ( ! F_12 ( V_150 , & V_167 -> V_47 ) ) ;
for ( V_59 = 0 ; V_59 < V_9 ; V_59 ++ )
V_163 [ V_59 ] = NULL ;
V_13 = 0 ;
V_59 = V_162 ;
do {
int V_15 = F_8 ( V_59 , V_6 , & V_13 , V_14 ) ;
V_163 [ V_15 ] = V_6 -> V_62 [ V_59 ] . V_57 ;
if ( V_59 == V_147 )
V_165 = V_15 ;
if ( V_59 == V_152 )
V_166 = V_15 ;
V_59 = F_7 ( V_59 , V_9 ) ;
} while ( V_59 != V_162 );
F_15 ( V_165 == V_166 ) ;
if ( V_166 < V_165 )
F_81 ( V_165 , V_166 ) ;
F_28 ( L_13 ,
V_110 , ( unsigned long long ) V_6 -> V_49 , V_165 , V_166 ) ;
F_37 ( & V_6 -> V_13 ) ;
if ( V_166 == V_14 + 1 ) {
if ( V_165 == V_14 ) {
F_64 ( & V_134 , V_136 , NULL ,
F_72 , V_6 ,
F_73 ( V_6 , V_156 ) ) ;
return F_79 ( V_163 , 0 , V_14 + 2 ,
V_121 , & V_134 ) ;
} else {
struct V_57 * V_164 ;
int V_168 ;
int V_8 = V_6 -> V_8 ;
if ( V_147 == V_8 )
V_168 = V_152 ;
else
V_168 = V_147 ;
V_13 = 0 ;
for ( V_59 = V_9 ; V_59 -- ; ) {
if ( V_59 == V_168 || V_59 == V_8 )
continue;
V_163 [ V_13 ++ ] = V_6 -> V_62 [ V_59 ] . V_57 ;
}
V_164 = V_6 -> V_62 [ V_168 ] . V_57 ;
F_64 ( & V_134 ,
V_136 | V_160 ,
NULL , NULL , NULL ,
F_73 ( V_6 , V_156 ) ) ;
V_128 = F_76 ( V_164 , V_163 , 0 , V_13 , V_121 ,
& V_134 ) ;
V_13 = F_77 ( V_163 , V_6 ) ;
F_64 ( & V_134 , V_136 , V_128 ,
F_72 , V_6 ,
F_73 ( V_6 , V_156 ) ) ;
return F_79 ( V_163 , 0 , V_13 + 2 ,
V_121 , & V_134 ) ;
}
} else {
F_64 ( & V_134 , V_136 , NULL ,
F_72 , V_6 ,
F_73 ( V_6 , V_156 ) ) ;
if ( V_166 == V_14 ) {
return F_82 ( V_14 + 2 ,
V_121 , V_165 ,
V_163 , & V_134 ) ;
} else {
return F_83 ( V_14 + 2 ,
V_121 , V_165 , V_166 ,
V_163 , & V_134 ) ;
}
}
}
static void F_84 ( void * V_142 )
{
struct V_5 * V_6 = V_142 ;
F_28 ( L_10 , V_110 ,
( unsigned long long ) V_6 -> V_49 ) ;
}
static struct V_126 *
F_85 ( struct V_5 * V_6 , struct V_155 * V_156 ,
struct V_126 * V_128 )
{
int V_9 = V_6 -> V_9 ;
struct V_57 * * V_158 = V_156 -> V_157 ;
int V_13 = 0 , V_16 = V_6 -> V_16 , V_59 ;
struct V_133 V_134 ;
struct V_57 * V_159 = V_158 [ V_13 ++ ] = V_6 -> V_62 [ V_16 ] . V_57 ;
F_28 ( L_10 , V_110 ,
( unsigned long long ) V_6 -> V_49 ) ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( F_12 ( V_169 , & V_62 -> V_47 ) )
V_158 [ V_13 ++ ] = V_62 -> V_57 ;
}
F_64 ( & V_134 , V_136 | V_170 , V_128 ,
F_84 , V_6 , F_73 ( V_6 , V_156 ) ) ;
V_128 = F_76 ( V_159 , V_158 , 0 , V_13 , V_121 , & V_134 ) ;
return V_128 ;
}
static struct V_126 *
F_86 ( struct V_5 * V_6 , struct V_126 * V_128 )
{
int V_9 = V_6 -> V_9 ;
int V_59 ;
F_28 ( L_10 , V_110 ,
( unsigned long long ) V_6 -> V_49 ) ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
struct V_1 * V_171 ;
if ( F_21 ( V_169 , & V_62 -> V_47 ) ) {
struct V_1 * V_172 ;
F_87 ( & V_6 -> V_173 ) ;
V_171 = V_62 -> V_70 ;
V_62 -> V_70 = NULL ;
F_15 ( V_62 -> V_71 ) ;
V_172 = V_62 -> V_71 = V_171 ;
F_88 ( & V_6 -> V_173 ) ;
while ( V_172 && V_172 -> V_111 <
V_62 -> V_49 + V_107 ) {
if ( V_172 -> V_98 & V_174 )
F_60 ( V_92 , & V_62 -> V_47 ) ;
V_128 = F_63 ( 1 , V_172 , V_62 -> V_57 ,
V_62 -> V_49 , V_128 ) ;
V_172 = F_68 ( V_172 , V_62 -> V_49 ) ;
}
}
}
return V_128 ;
}
static void F_89 ( void * V_142 )
{
struct V_5 * V_6 = V_142 ;
int V_9 = V_6 -> V_9 ;
int V_16 = V_6 -> V_16 ;
int V_8 = V_6 -> V_8 ;
int V_59 ;
bool V_175 = false ;
F_28 ( L_10 , V_110 ,
( unsigned long long ) V_6 -> V_49 ) ;
for ( V_59 = V_9 ; V_59 -- ; )
V_175 |= F_12 ( V_92 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( V_62 -> V_71 || V_59 == V_16 || V_59 == V_8 ) {
F_60 ( V_149 , & V_62 -> V_47 ) ;
if ( V_175 )
F_60 ( V_92 , & V_62 -> V_47 ) ;
}
}
if ( V_6 -> V_22 == V_176 )
V_6 -> V_22 = V_177 ;
else if ( V_6 -> V_22 == V_178 )
V_6 -> V_22 = V_179 ;
else {
F_15 ( V_6 -> V_22 != V_180 ) ;
V_6 -> V_22 = V_181 ;
}
F_60 ( V_29 , & V_6 -> V_24 ) ;
F_24 ( V_6 ) ;
}
static void
F_90 ( struct V_5 * V_6 , struct V_155 * V_156 ,
struct V_126 * V_128 )
{
int V_9 = V_6 -> V_9 ;
struct V_57 * * V_158 = V_156 -> V_157 ;
struct V_133 V_134 ;
int V_13 = 0 , V_16 = V_6 -> V_16 , V_59 ;
struct V_57 * V_159 ;
int V_182 = 0 ;
unsigned long V_47 ;
F_28 ( L_10 , V_110 ,
( unsigned long long ) V_6 -> V_49 ) ;
if ( V_6 -> V_22 == V_178 ) {
V_182 = 1 ;
V_159 = V_158 [ V_13 ++ ] = V_6 -> V_62 [ V_16 ] . V_57 ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( V_62 -> V_71 )
V_158 [ V_13 ++ ] = V_62 -> V_57 ;
}
} else {
V_159 = V_6 -> V_62 [ V_16 ] . V_57 ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( V_59 != V_16 )
V_158 [ V_13 ++ ] = V_62 -> V_57 ;
}
}
V_47 = V_146 |
( V_182 ? V_170 : V_160 ) ;
F_37 ( & V_6 -> V_13 ) ;
F_64 ( & V_134 , V_47 , V_128 , F_89 , V_6 ,
F_73 ( V_6 , V_156 ) ) ;
if ( F_75 ( V_13 == 1 ) )
V_128 = F_66 ( V_159 , V_158 [ 0 ] , 0 , 0 , V_121 , & V_134 ) ;
else
V_128 = F_76 ( V_159 , V_158 , 0 , V_13 , V_121 , & V_134 ) ;
}
static void
F_91 ( struct V_5 * V_6 , struct V_155 * V_156 ,
struct V_126 * V_128 )
{
struct V_133 V_134 ;
struct V_57 * * V_163 = V_156 -> V_157 ;
int V_13 ;
F_28 ( L_10 , V_110 , ( unsigned long long ) V_6 -> V_49 ) ;
V_13 = F_77 ( V_163 , V_6 ) ;
F_37 ( & V_6 -> V_13 ) ;
F_64 ( & V_134 , V_146 , V_128 , F_89 ,
V_6 , F_73 ( V_6 , V_156 ) ) ;
F_79 ( V_163 , 0 , V_13 + 2 , V_121 , & V_134 ) ;
}
static void F_92 ( void * V_142 )
{
struct V_5 * V_6 = V_142 ;
F_28 ( L_10 , V_110 ,
( unsigned long long ) V_6 -> V_49 ) ;
V_6 -> V_21 = V_183 ;
F_60 ( V_29 , & V_6 -> V_24 ) ;
F_24 ( V_6 ) ;
}
static void F_93 ( struct V_5 * V_6 , struct V_155 * V_156 )
{
int V_9 = V_6 -> V_9 ;
int V_16 = V_6 -> V_16 ;
int V_8 = V_6 -> V_8 ;
struct V_57 * V_159 ;
struct V_57 * * V_158 = V_156 -> V_157 ;
struct V_126 * V_128 ;
struct V_133 V_134 ;
int V_13 ;
int V_59 ;
F_28 ( L_10 , V_110 ,
( unsigned long long ) V_6 -> V_49 ) ;
V_13 = 0 ;
V_159 = V_6 -> V_62 [ V_16 ] . V_57 ;
V_158 [ V_13 ++ ] = V_159 ;
for ( V_59 = V_9 ; V_59 -- ; ) {
if ( V_59 == V_16 || V_59 == V_8 )
continue;
V_158 [ V_13 ++ ] = V_6 -> V_62 [ V_59 ] . V_57 ;
}
F_64 ( & V_134 , 0 , NULL , NULL , NULL ,
F_73 ( V_6 , V_156 ) ) ;
V_128 = F_94 ( V_159 , V_158 , 0 , V_13 , V_121 ,
& V_6 -> V_151 . V_184 , & V_134 ) ;
F_37 ( & V_6 -> V_13 ) ;
F_64 ( & V_134 , V_146 , V_128 , F_92 , V_6 , NULL ) ;
V_128 = F_70 ( & V_134 ) ;
}
static void F_95 ( struct V_5 * V_6 , struct V_155 * V_156 , int V_185 )
{
struct V_57 * * V_161 = V_156 -> V_157 ;
struct V_133 V_134 ;
int V_13 ;
F_28 ( L_14 , V_110 ,
( unsigned long long ) V_6 -> V_49 , V_185 ) ;
V_13 = F_77 ( V_161 , V_6 ) ;
if ( ! V_185 )
V_161 [ V_13 ] = NULL ;
F_37 ( & V_6 -> V_13 ) ;
F_64 ( & V_134 , V_146 , NULL , F_92 ,
V_6 , F_73 ( V_6 , V_156 ) ) ;
F_96 ( V_161 , 0 , V_13 + 2 , V_121 ,
& V_6 -> V_151 . V_184 , V_156 -> V_186 , & V_134 ) ;
}
static void F_97 ( struct V_5 * V_6 , unsigned long V_187 )
{
int V_188 = 0 , V_59 , V_9 = V_6 -> V_9 ;
struct V_126 * V_128 = NULL ;
T_1 * V_26 = V_6 -> V_46 ;
int V_189 = V_26 -> V_189 ;
struct V_155 * V_156 ;
unsigned long V_190 ;
V_190 = F_98 () ;
V_156 = F_99 ( V_26 -> V_156 , V_190 ) ;
if ( F_12 ( V_191 , & V_187 ) ) {
F_69 ( V_6 ) ;
V_188 ++ ;
}
if ( F_12 ( V_192 , & V_187 ) ) {
if ( V_189 < 6 )
V_128 = F_74 ( V_6 , V_156 ) ;
else {
if ( V_6 -> V_151 . V_152 < 0 || V_6 -> V_151 . V_147 < 0 )
V_128 = F_78 ( V_6 , V_156 ) ;
else
V_128 = F_80 ( V_6 , V_156 ) ;
}
if ( V_128 && ! F_12 ( V_193 , & V_187 ) )
F_100 ( V_128 ) ;
}
if ( F_12 ( V_194 , & V_187 ) )
V_128 = F_85 ( V_6 , V_156 , V_128 ) ;
if ( F_12 ( V_195 , & V_187 ) ) {
V_128 = F_86 ( V_6 , V_128 ) ;
V_188 ++ ;
}
if ( F_12 ( V_193 , & V_187 ) ) {
if ( V_189 < 6 )
F_90 ( V_6 , V_156 , V_128 ) ;
else
F_91 ( V_6 , V_156 , V_128 ) ;
}
if ( F_12 ( V_196 , & V_187 ) ) {
if ( V_6 -> V_21 == V_197 )
F_93 ( V_6 , V_156 ) ;
else if ( V_6 -> V_21 == V_198 )
F_95 ( V_6 , V_156 , 0 ) ;
else if ( V_6 -> V_21 == V_199 )
F_95 ( V_6 , V_156 , 1 ) ;
else
F_45 () ;
}
if ( V_188 )
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( F_21 ( V_200 , & V_62 -> V_47 ) )
F_23 ( & V_6 -> V_46 -> V_201 ) ;
}
F_101 () ;
}
static void F_102 ( void * V_202 , T_5 V_203 )
{
struct V_5 * V_6 = V_202 ;
unsigned long V_187 = V_6 -> V_151 . V_204 ;
F_103 ( V_205 , & V_6 -> V_24 ) ;
F_23 ( & V_6 -> V_151 . V_206 ) ;
F_97 ( V_6 , V_187 ) ;
F_24 ( V_6 ) ;
}
static void F_104 ( struct V_5 * V_6 , unsigned long V_187 )
{
F_105 ( V_6 -> V_151 . V_206 ,
! F_106 ( V_205 , & V_6 -> V_24 ) ) ;
V_6 -> V_151 . V_204 = V_187 ;
F_37 ( & V_6 -> V_13 ) ;
F_107 ( F_102 , V_6 ) ;
}
static int F_108 ( T_1 * V_26 )
{
struct V_5 * V_6 ;
V_6 = F_109 ( V_26 -> V_207 , V_63 ) ;
if ( ! V_6 )
return 0 ;
memset ( V_6 , 0 , sizeof( * V_6 ) + ( V_26 -> V_61 - 1 ) * sizeof( struct V_67 ) ) ;
V_6 -> V_46 = V_26 ;
F_110 ( & V_6 -> V_173 ) ;
#ifdef F_111
F_112 ( & V_6 -> V_151 . V_206 ) ;
#endif
if ( F_40 ( V_6 ) ) {
F_38 ( V_6 ) ;
F_113 ( V_26 -> V_207 , V_6 ) ;
return 0 ;
}
F_114 ( & V_6 -> V_13 , 1 ) ;
F_37 ( & V_26 -> V_28 ) ;
F_115 ( & V_6 -> V_27 ) ;
F_24 ( V_6 ) ;
return 1 ;
}
static int F_116 ( T_1 * V_26 , int V_60 )
{
struct V_208 * V_209 ;
int V_210 = F_117 ( V_26 -> V_11 , V_26 -> V_66 ) ;
if ( V_26 -> V_37 -> V_211 )
sprintf ( V_26 -> V_212 [ 0 ] ,
L_15 , V_26 -> V_189 , F_118 ( V_26 -> V_37 ) ) ;
else
sprintf ( V_26 -> V_212 [ 0 ] ,
L_16 , V_26 -> V_189 , V_26 -> V_37 ) ;
sprintf ( V_26 -> V_212 [ 1 ] , L_17 , V_26 -> V_212 [ 0 ] ) ;
V_26 -> V_213 = 0 ;
V_209 = F_119 ( V_26 -> V_212 [ V_26 -> V_213 ] ,
sizeof( struct V_5 ) + ( V_210 - 1 ) * sizeof( struct V_67 ) ,
0 , 0 , NULL ) ;
if ( ! V_209 )
return 1 ;
V_26 -> V_207 = V_209 ;
V_26 -> V_61 = V_210 ;
while ( V_60 -- )
if ( ! F_108 ( V_26 ) )
return 1 ;
return 0 ;
}
static T_6 F_120 ( int V_60 )
{
T_6 V_137 ;
V_137 = sizeof( struct V_57 * ) * ( V_60 + 2 ) + sizeof( T_4 ) * ( V_60 + 2 ) ;
return V_137 ;
}
static int F_121 ( T_1 * V_26 , int V_214 )
{
struct V_5 * V_215 , * V_216 ;
F_122 ( V_217 ) ;
struct V_218 * V_219 ;
unsigned long V_190 ;
int V_220 ;
struct V_208 * V_209 ;
int V_59 ;
if ( V_214 <= V_26 -> V_61 )
return 0 ;
V_220 = F_123 ( V_26 -> V_37 ) ;
if ( V_220 )
return V_220 ;
V_209 = F_119 ( V_26 -> V_212 [ 1 - V_26 -> V_213 ] ,
sizeof( struct V_5 ) + ( V_214 - 1 ) * sizeof( struct V_67 ) ,
0 , 0 , NULL ) ;
if ( ! V_209 )
return - V_221 ;
for ( V_59 = V_26 -> V_87 ; V_59 ; V_59 -- ) {
V_216 = F_109 ( V_209 , V_63 ) ;
if ( ! V_216 )
break;
memset ( V_216 , 0 , sizeof( * V_216 ) + ( V_214 - 1 ) * sizeof( struct V_67 ) ) ;
V_216 -> V_46 = V_26 ;
F_110 ( & V_216 -> V_173 ) ;
#ifdef F_111
F_112 ( & V_216 -> V_151 . V_206 ) ;
#endif
F_124 ( & V_216 -> V_27 , & V_217 ) ;
}
if ( V_59 ) {
while ( ! F_16 ( & V_217 ) ) {
V_216 = F_35 ( V_217 . V_56 , struct V_5 , V_27 ) ;
F_125 ( & V_216 -> V_27 ) ;
F_113 ( V_209 , V_216 ) ;
}
F_126 ( V_209 ) ;
return - V_221 ;
}
F_127 (nsh, &newstripes, lru) {
F_54 ( & V_26 -> V_48 ) ;
F_55 ( V_26 -> V_44 ,
! F_16 ( & V_26 -> V_43 ) ,
V_26 -> V_48 ,
) ;
V_215 = F_34 ( V_26 ) ;
F_56 ( & V_26 -> V_48 ) ;
F_114 ( & V_216 -> V_13 , 1 ) ;
for( V_59 = 0 ; V_59 < V_26 -> V_61 ; V_59 ++ )
V_216 -> V_62 [ V_59 ] . V_57 = V_215 -> V_62 [ V_59 ] . V_57 ;
for( ; V_59 < V_214 ; V_59 ++ )
V_216 -> V_62 [ V_59 ] . V_57 = NULL ;
F_113 ( V_26 -> V_207 , V_215 ) ;
}
F_126 ( V_26 -> V_207 ) ;
V_219 = F_128 ( V_214 * sizeof( struct V_218 ) , V_222 ) ;
if ( V_219 ) {
for ( V_59 = 0 ; V_59 < V_26 -> V_11 ; V_59 ++ )
V_219 [ V_59 ] = V_26 -> V_9 [ V_59 ] ;
F_129 ( V_26 -> V_9 ) ;
V_26 -> V_9 = V_219 ;
} else
V_220 = - V_221 ;
F_130 () ;
V_26 -> F_120 = F_120 ( V_214 ) ;
F_131 (cpu) {
struct V_155 * V_156 ;
void * V_157 ;
V_156 = F_99 ( V_26 -> V_156 , V_190 ) ;
V_157 = F_132 ( V_26 -> F_120 , V_222 ) ;
if ( V_157 ) {
F_129 ( V_156 -> V_157 ) ;
V_156 -> V_157 = V_157 ;
} else {
V_220 = - V_221 ;
break;
}
}
F_133 () ;
while( ! F_16 ( & V_217 ) ) {
V_216 = F_35 ( V_217 . V_56 , struct V_5 , V_27 ) ;
F_36 ( & V_216 -> V_27 ) ;
for ( V_59 = V_26 -> V_11 ; V_59 < V_214 ; V_59 ++ )
if ( V_216 -> V_62 [ V_59 ] . V_57 == NULL ) {
struct V_57 * V_58 = F_41 ( V_222 ) ;
V_216 -> V_62 [ V_59 ] . V_57 = V_58 ;
if ( ! V_58 )
V_220 = - V_221 ;
}
F_24 ( V_216 ) ;
}
V_26 -> V_207 = V_209 ;
V_26 -> V_213 = 1 - V_26 -> V_213 ;
V_26 -> V_61 = V_214 ;
return V_220 ;
}
static int F_134 ( T_1 * V_26 )
{
struct V_5 * V_6 ;
F_54 ( & V_26 -> V_48 ) ;
V_6 = F_34 ( V_26 ) ;
F_56 ( & V_26 -> V_48 ) ;
if ( ! V_6 )
return 0 ;
F_15 ( F_17 ( & V_6 -> V_13 ) ) ;
F_38 ( V_6 ) ;
F_113 ( V_26 -> V_207 , V_6 ) ;
F_22 ( & V_26 -> V_28 ) ;
return 1 ;
}
static void F_135 ( T_1 * V_26 )
{
while ( F_134 ( V_26 ) )
;
if ( V_26 -> V_207 )
F_126 ( V_26 -> V_207 ) ;
V_26 -> V_207 = NULL ;
}
static void V_101 ( struct V_1 * V_18 , int error )
{
struct V_5 * V_6 = V_18 -> V_223 ;
T_1 * V_26 = V_6 -> V_46 ;
int V_9 = V_6 -> V_9 , V_59 ;
int V_224 = F_12 ( V_114 , & V_18 -> V_113 ) ;
char V_225 [ V_226 ] ;
T_3 * V_80 ;
for ( V_59 = 0 ; V_59 < V_9 ; V_59 ++ )
if ( V_18 == & V_6 -> V_62 [ V_59 ] . V_97 )
break;
F_28 ( L_18 ,
( unsigned long long ) V_6 -> V_49 , V_59 , F_17 ( & V_6 -> V_13 ) ,
V_224 ) ;
if ( V_59 == V_9 ) {
F_45 () ;
return;
}
if ( V_224 ) {
F_60 ( V_149 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
if ( F_12 ( V_227 , & V_6 -> V_62 [ V_59 ] . V_47 ) ) {
V_80 = V_26 -> V_9 [ V_59 ] . V_80 ;
F_136 ( V_228 L_19
L_20 ,
F_118 ( V_26 -> V_37 ) , V_107 ,
( unsigned long long ) ( V_6 -> V_49
+ V_80 -> V_112 ) ,
F_137 ( V_80 -> V_106 , V_225 ) ) ;
F_19 ( V_227 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
F_19 ( V_123 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
}
if ( F_17 ( & V_26 -> V_9 [ V_59 ] . V_80 -> V_229 ) )
F_114 ( & V_26 -> V_9 [ V_59 ] . V_80 -> V_229 , 0 ) ;
} else {
const char * V_230 = F_137 ( V_26 -> V_9 [ V_59 ] . V_80 -> V_106 , V_225 ) ;
int V_231 = 0 ;
V_80 = V_26 -> V_9 [ V_59 ] . V_80 ;
F_19 ( V_149 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
F_37 ( & V_80 -> V_229 ) ;
if ( V_26 -> V_37 -> V_76 >= V_26 -> V_79 )
F_136 ( V_232
L_21
L_22 ,
F_118 ( V_26 -> V_37 ) ,
( unsigned long long ) ( V_6 -> V_49
+ V_80 -> V_112 ) ,
V_230 ) ;
else if ( F_12 ( V_123 , & V_6 -> V_62 [ V_59 ] . V_47 ) )
F_136 ( V_232
L_23
L_22 ,
F_118 ( V_26 -> V_37 ) ,
( unsigned long long ) ( V_6 -> V_49
+ V_80 -> V_112 ) ,
V_230 ) ;
else if ( F_17 ( & V_80 -> V_229 )
> V_26 -> V_87 )
F_44 ( V_232
L_24 ,
F_118 ( V_26 -> V_37 ) , V_230 ) ;
else
V_231 = 1 ;
if ( V_231 )
F_60 ( V_227 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
else {
F_19 ( V_227 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
F_19 ( V_123 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
F_138 ( V_26 -> V_37 , V_80 ) ;
}
}
F_139 ( V_26 -> V_9 [ V_59 ] . V_80 , V_26 -> V_37 ) ;
F_19 ( V_72 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
F_60 ( V_29 , & V_6 -> V_24 ) ;
F_24 ( V_6 ) ;
}
static void V_100 ( struct V_1 * V_18 , int error )
{
struct V_5 * V_6 = V_18 -> V_223 ;
T_1 * V_26 = V_6 -> V_46 ;
int V_9 = V_6 -> V_9 , V_59 ;
int V_224 = F_12 ( V_114 , & V_18 -> V_113 ) ;
for ( V_59 = 0 ; V_59 < V_9 ; V_59 ++ )
if ( V_18 == & V_6 -> V_62 [ V_59 ] . V_97 )
break;
F_28 ( L_25 ,
( unsigned long long ) V_6 -> V_49 , V_59 , F_17 ( & V_6 -> V_13 ) ,
V_224 ) ;
if ( V_59 == V_9 ) {
F_45 () ;
return;
}
if ( ! V_224 )
F_138 ( V_26 -> V_37 , V_26 -> V_9 [ V_59 ] . V_80 ) ;
F_139 ( V_26 -> V_9 [ V_59 ] . V_80 , V_26 -> V_37 ) ;
F_19 ( V_72 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
F_60 ( V_29 , & V_6 -> V_24 ) ;
F_24 ( V_6 ) ;
}
static void F_46 ( struct V_5 * V_6 , int V_59 , int V_64 )
{
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
F_140 ( & V_62 -> V_97 ) ;
V_62 -> V_97 . V_118 = & V_62 -> V_119 ;
V_62 -> V_97 . V_115 ++ ;
V_62 -> V_97 . V_116 ++ ;
V_62 -> V_119 . V_140 = V_62 -> V_57 ;
V_62 -> V_119 . V_120 = V_121 ;
V_62 -> V_119 . V_122 = 0 ;
V_62 -> V_97 . V_111 = V_6 -> V_49 ;
V_62 -> V_97 . V_223 = V_6 ;
V_62 -> V_47 = 0 ;
V_62 -> V_49 = F_141 ( V_6 , V_59 , V_64 ) ;
}
static void error ( T_7 * V_37 , T_3 * V_80 )
{
char V_225 [ V_226 ] ;
T_1 * V_26 = V_37 -> V_233 ;
F_28 ( L_26 ) ;
if ( F_21 ( V_82 , & V_80 -> V_47 ) ) {
unsigned long V_47 ;
F_25 ( & V_26 -> V_48 , V_47 ) ;
V_37 -> V_76 ++ ;
F_26 ( & V_26 -> V_48 , V_47 ) ;
F_60 ( V_234 , & V_37 -> V_235 ) ;
}
F_60 ( V_81 , & V_80 -> V_47 ) ;
F_60 ( V_236 , & V_37 -> V_47 ) ;
F_44 ( V_237
L_27
L_28 ,
F_118 ( V_37 ) ,
F_137 ( V_80 -> V_106 , V_225 ) ,
F_118 ( V_37 ) ,
V_26 -> V_11 - V_37 -> V_76 ) ;
}
static T_2 F_142 ( T_1 * V_26 , T_2 V_238 ,
int V_64 , int * V_239 ,
struct V_5 * V_6 )
{
T_2 V_240 , V_241 ;
T_2 V_242 ;
unsigned int V_243 ;
int V_16 , V_8 ;
int V_7 = 0 ;
T_2 V_244 ;
int V_245 = V_64 ? V_26 -> V_246
: V_26 -> V_245 ;
int V_247 = V_64 ? V_26 -> V_248
: V_26 -> V_249 ;
int V_11 = V_64 ? V_26 -> V_66
: V_26 -> V_11 ;
int V_250 = V_11 - V_26 -> V_79 ;
V_243 = F_143 ( V_238 , V_247 ) ;
V_242 = V_238 ;
V_240 = V_242 ;
* V_239 = F_143 ( V_240 , V_250 ) ;
V_241 = V_240 ;
V_16 = V_8 = ~ 0 ;
switch( V_26 -> V_189 ) {
case 4 :
V_16 = V_250 ;
break;
case 5 :
switch ( V_245 ) {
case V_251 :
V_16 = V_250 - F_143 ( V_241 , V_11 ) ;
if ( * V_239 >= V_16 )
( * V_239 ) ++ ;
break;
case V_252 :
V_16 = F_143 ( V_241 , V_11 ) ;
if ( * V_239 >= V_16 )
( * V_239 ) ++ ;
break;
case V_253 :
V_16 = V_250 - F_143 ( V_241 , V_11 ) ;
* V_239 = ( V_16 + 1 + * V_239 ) % V_11 ;
break;
case V_254 :
V_16 = F_143 ( V_241 , V_11 ) ;
* V_239 = ( V_16 + 1 + * V_239 ) % V_11 ;
break;
case V_255 :
V_16 = 0 ;
( * V_239 ) ++ ;
break;
case V_256 :
V_16 = V_250 ;
break;
default:
F_45 () ;
}
break;
case 6 :
switch ( V_245 ) {
case V_251 :
V_16 = V_11 - 1 - F_143 ( V_241 , V_11 ) ;
V_8 = V_16 + 1 ;
if ( V_16 == V_11 - 1 ) {
( * V_239 ) ++ ;
V_8 = 0 ;
} else if ( * V_239 >= V_16 )
( * V_239 ) += 2 ;
break;
case V_252 :
V_16 = F_143 ( V_241 , V_11 ) ;
V_8 = V_16 + 1 ;
if ( V_16 == V_11 - 1 ) {
( * V_239 ) ++ ;
V_8 = 0 ;
} else if ( * V_239 >= V_16 )
( * V_239 ) += 2 ;
break;
case V_253 :
V_16 = V_11 - 1 - F_143 ( V_241 , V_11 ) ;
V_8 = ( V_16 + 1 ) % V_11 ;
* V_239 = ( V_16 + 2 + * V_239 ) % V_11 ;
break;
case V_254 :
V_16 = F_143 ( V_241 , V_11 ) ;
V_8 = ( V_16 + 1 ) % V_11 ;
* V_239 = ( V_16 + 2 + * V_239 ) % V_11 ;
break;
case V_255 :
V_16 = 0 ;
V_8 = 1 ;
( * V_239 ) += 2 ;
break;
case V_256 :
V_16 = V_250 ;
V_8 = V_250 + 1 ;
break;
case V_257 :
V_16 = F_143 ( V_241 , V_11 ) ;
V_8 = V_16 + 1 ;
if ( V_16 == V_11 - 1 ) {
( * V_239 ) ++ ;
V_8 = 0 ;
} else if ( * V_239 >= V_16 )
( * V_239 ) += 2 ;
V_7 = 1 ;
break;
case V_258 :
V_241 += 1 ;
V_16 = V_11 - 1 - F_143 ( V_241 , V_11 ) ;
V_8 = V_16 + 1 ;
if ( V_16 == V_11 - 1 ) {
( * V_239 ) ++ ;
V_8 = 0 ;
} else if ( * V_239 >= V_16 )
( * V_239 ) += 2 ;
V_7 = 1 ;
break;
case V_259 :
V_16 = V_11 - 1 - F_143 ( V_241 , V_11 ) ;
V_8 = ( V_16 + V_11 - 1 ) % V_11 ;
* V_239 = ( V_16 + 1 + * V_239 ) % V_11 ;
V_7 = 1 ;
break;
case V_260 :
V_16 = V_250 - F_143 ( V_241 , V_11 - 1 ) ;
if ( * V_239 >= V_16 )
( * V_239 ) ++ ;
V_8 = V_11 - 1 ;
break;
case V_261 :
V_16 = F_143 ( V_241 , V_11 - 1 ) ;
if ( * V_239 >= V_16 )
( * V_239 ) ++ ;
V_8 = V_11 - 1 ;
break;
case V_262 :
V_16 = V_250 - F_143 ( V_241 , V_11 - 1 ) ;
* V_239 = ( V_16 + 1 + * V_239 ) % ( V_11 - 1 ) ;
V_8 = V_11 - 1 ;
break;
case V_263 :
V_16 = F_143 ( V_241 , V_11 - 1 ) ;
* V_239 = ( V_16 + 1 + * V_239 ) % ( V_11 - 1 ) ;
V_8 = V_11 - 1 ;
break;
case V_264 :
V_16 = 0 ;
( * V_239 ) ++ ;
V_8 = V_11 - 1 ;
break;
default:
F_45 () ;
}
break;
}
if ( V_6 ) {
V_6 -> V_16 = V_16 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_7 = V_7 ;
}
V_244 = ( T_2 ) V_240 * V_247 + V_243 ;
return V_244 ;
}
static T_2 F_141 ( struct V_5 * V_6 , int V_59 , int V_64 )
{
T_1 * V_26 = V_6 -> V_46 ;
int V_11 = V_6 -> V_9 ;
int V_250 = V_11 - V_26 -> V_79 ;
T_2 V_244 = V_6 -> V_49 , V_265 ;
int V_247 = V_64 ? V_26 -> V_248
: V_26 -> V_249 ;
int V_245 = V_64 ? V_26 -> V_246
: V_26 -> V_245 ;
T_2 V_240 ;
int V_243 ;
T_2 V_242 ;
int V_266 , V_239 = V_59 ;
T_2 V_238 ;
struct V_5 V_267 ;
V_243 = F_143 ( V_244 , V_247 ) ;
V_240 = V_244 ;
if ( V_59 == V_6 -> V_16 )
return 0 ;
switch( V_26 -> V_189 ) {
case 4 : break;
case 5 :
switch ( V_245 ) {
case V_251 :
case V_252 :
if ( V_59 > V_6 -> V_16 )
V_59 -- ;
break;
case V_253 :
case V_254 :
if ( V_59 < V_6 -> V_16 )
V_59 += V_11 ;
V_59 -= ( V_6 -> V_16 + 1 ) ;
break;
case V_255 :
V_59 -= 1 ;
break;
case V_256 :
break;
default:
F_45 () ;
}
break;
case 6 :
if ( V_59 == V_6 -> V_8 )
return 0 ;
switch ( V_245 ) {
case V_251 :
case V_252 :
case V_257 :
case V_258 :
if ( V_6 -> V_16 == V_11 - 1 )
V_59 -- ;
else if ( V_59 > V_6 -> V_16 )
V_59 -= 2 ;
break;
case V_253 :
case V_254 :
if ( V_6 -> V_16 == V_11 - 1 )
V_59 -- ;
else {
if ( V_59 < V_6 -> V_16 )
V_59 += V_11 ;
V_59 -= ( V_6 -> V_16 + 2 ) ;
}
break;
case V_255 :
V_59 -= 2 ;
break;
case V_256 :
break;
case V_259 :
if ( V_6 -> V_16 == 0 )
V_59 -- ;
else {
if ( V_59 < V_6 -> V_16 )
V_59 += V_11 ;
V_59 -= ( V_6 -> V_16 + 1 ) ;
}
break;
case V_260 :
case V_261 :
if ( V_59 > V_6 -> V_16 )
V_59 -- ;
break;
case V_262 :
case V_263 :
if ( V_59 < V_6 -> V_16 )
V_59 += V_250 + 1 ;
V_59 -= ( V_6 -> V_16 + 1 ) ;
break;
case V_264 :
V_59 -= 1 ;
break;
default:
F_45 () ;
}
break;
}
V_242 = V_240 * V_250 + V_59 ;
V_238 = V_242 * V_247 + V_243 ;
V_265 = F_142 ( V_26 , V_238 ,
V_64 , & V_266 , & V_267 ) ;
if ( V_265 != V_6 -> V_49 || V_266 != V_239 || V_267 . V_16 != V_6 -> V_16
|| V_267 . V_8 != V_6 -> V_8 ) {
F_44 ( V_73 L_29 ,
F_118 ( V_26 -> V_37 ) ) ;
return 0 ;
}
return V_238 ;
}
static void
F_144 ( struct V_5 * V_6 , struct V_88 * V_89 ,
int V_268 , int V_269 )
{
int V_59 , V_16 = V_6 -> V_16 , V_9 = V_6 -> V_9 ;
T_1 * V_26 = V_6 -> V_46 ;
int V_189 = V_26 -> V_189 ;
if ( V_268 ) {
if ( ! V_269 ) {
V_6 -> V_22 = V_176 ;
F_60 ( V_195 , & V_89 -> V_187 ) ;
} else
V_6 -> V_22 = V_180 ;
F_60 ( V_193 , & V_89 -> V_187 ) ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( V_62 -> V_70 ) {
F_60 ( V_72 , & V_62 -> V_47 ) ;
F_60 ( V_169 , & V_62 -> V_47 ) ;
if ( ! V_269 )
F_19 ( V_149 , & V_62 -> V_47 ) ;
V_89 -> V_270 ++ ;
}
}
if ( V_89 -> V_270 + V_26 -> V_79 == V_9 )
if ( ! F_145 ( V_271 , & V_6 -> V_24 ) )
F_37 ( & V_26 -> V_272 ) ;
} else {
F_15 ( V_189 == 6 ) ;
F_15 ( ! ( F_12 ( V_149 , & V_6 -> V_62 [ V_16 ] . V_47 ) ||
F_12 ( V_150 , & V_6 -> V_62 [ V_16 ] . V_47 ) ) ) ;
V_6 -> V_22 = V_178 ;
F_60 ( V_194 , & V_89 -> V_187 ) ;
F_60 ( V_195 , & V_89 -> V_187 ) ;
F_60 ( V_193 , & V_89 -> V_187 ) ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( V_59 == V_16 )
continue;
if ( V_62 -> V_70 &&
( F_12 ( V_149 , & V_62 -> V_47 ) ||
F_12 ( V_150 , & V_62 -> V_47 ) ) ) {
F_60 ( V_169 , & V_62 -> V_47 ) ;
F_60 ( V_72 , & V_62 -> V_47 ) ;
F_19 ( V_149 , & V_62 -> V_47 ) ;
V_89 -> V_270 ++ ;
}
}
}
F_60 ( V_72 , & V_6 -> V_62 [ V_16 ] . V_47 ) ;
F_19 ( V_149 , & V_6 -> V_62 [ V_16 ] . V_47 ) ;
V_89 -> V_270 ++ ;
if ( V_189 == 6 ) {
int V_8 = V_6 -> V_8 ;
struct V_67 * V_62 = & V_6 -> V_62 [ V_8 ] ;
F_60 ( V_72 , & V_62 -> V_47 ) ;
F_19 ( V_149 , & V_62 -> V_47 ) ;
V_89 -> V_270 ++ ;
}
F_28 ( L_30 ,
V_110 , ( unsigned long long ) V_6 -> V_49 ,
V_89 -> V_270 , V_89 -> V_187 ) ;
}
static int F_146 ( struct V_5 * V_6 , struct V_1 * V_18 , int V_239 , int V_273 )
{
struct V_1 * * V_274 ;
T_1 * V_26 = V_6 -> V_46 ;
int V_275 = 0 ;
F_28 ( L_31 ,
( unsigned long long ) V_18 -> V_111 ,
( unsigned long long ) V_6 -> V_49 ) ;
F_87 ( & V_6 -> V_173 ) ;
F_54 ( & V_26 -> V_48 ) ;
if ( V_273 ) {
V_274 = & V_6 -> V_62 [ V_239 ] . V_70 ;
if ( * V_274 == NULL && V_6 -> V_62 [ V_239 ] . V_71 == NULL )
V_275 = 1 ;
} else
V_274 = & V_6 -> V_62 [ V_239 ] . V_68 ;
while ( * V_274 && ( * V_274 ) -> V_111 < V_18 -> V_111 ) {
if ( ( * V_274 ) -> V_111 + ( ( * V_274 ) -> V_20 >> 9 ) > V_18 -> V_111 )
goto V_276;
V_274 = & ( * V_274 ) -> V_19 ;
}
if ( * V_274 && ( * V_274 ) -> V_111 < V_18 -> V_111 + ( ( V_18 -> V_20 ) >> 9 ) )
goto V_276;
F_15 ( * V_274 && V_18 -> V_19 && ( * V_274 ) != V_18 -> V_19 ) ;
if ( * V_274 )
V_18 -> V_19 = * V_274 ;
* V_274 = V_18 ;
V_18 -> V_2 ++ ;
F_56 ( & V_26 -> V_48 ) ;
F_88 ( & V_6 -> V_173 ) ;
F_28 ( L_32 ,
( unsigned long long ) V_18 -> V_111 ,
( unsigned long long ) V_6 -> V_49 , V_239 ) ;
if ( V_26 -> V_37 -> V_277 && V_275 ) {
F_147 ( V_26 -> V_37 -> V_277 , V_6 -> V_49 ,
V_107 , 0 ) ;
V_6 -> V_33 = V_26 -> V_278 + 1 ;
F_60 ( V_32 , & V_6 -> V_24 ) ;
}
if ( V_273 ) {
T_2 V_49 = V_6 -> V_62 [ V_239 ] . V_49 ;
for ( V_18 = V_6 -> V_62 [ V_239 ] . V_70 ;
V_49 < V_6 -> V_62 [ V_239 ] . V_49 + V_107 &&
V_18 && V_18 -> V_111 <= V_49 ;
V_18 = F_68 ( V_18 , V_6 -> V_62 [ V_239 ] . V_49 ) ) {
if ( V_18 -> V_111 + ( V_18 -> V_20 >> 9 ) >= V_49 )
V_49 = V_18 -> V_111 + ( V_18 -> V_20 >> 9 ) ;
}
if ( V_49 >= V_6 -> V_62 [ V_239 ] . V_49 + V_107 )
F_60 ( V_279 , & V_6 -> V_62 [ V_239 ] . V_47 ) ;
}
return 1 ;
V_276:
F_60 ( V_200 , & V_6 -> V_62 [ V_239 ] . V_47 ) ;
F_56 ( & V_26 -> V_48 ) ;
F_88 ( & V_6 -> V_173 ) ;
return 0 ;
}
static void F_43 ( T_2 V_240 , T_1 * V_26 , int V_64 ,
struct V_5 * V_6 )
{
int V_247 =
V_64 ? V_26 -> V_248 : V_26 -> V_249 ;
int V_239 ;
int V_243 = F_143 ( V_240 , V_247 ) ;
int V_9 = V_64 ? V_26 -> V_66 : V_26 -> V_11 ;
F_142 ( V_26 ,
V_240 * ( V_9 - V_26 -> V_79 )
* V_247 + V_243 ,
V_64 ,
& V_239 , V_6 ) ;
}
static void
F_148 ( T_1 * V_26 , struct V_5 * V_6 ,
struct V_88 * V_89 , int V_9 ,
struct V_1 * * V_17 )
{
int V_59 ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_1 * V_18 ;
int V_280 = 0 ;
if ( F_12 ( V_227 , & V_6 -> V_62 [ V_59 ] . V_47 ) ) {
T_3 * V_80 ;
F_50 () ;
V_80 = F_51 ( V_26 -> V_9 [ V_59 ] . V_80 ) ;
if ( V_80 && F_12 ( V_82 , & V_80 -> V_47 ) )
F_138 ( V_26 -> V_37 , V_80 ) ;
F_52 () ;
}
F_54 ( & V_26 -> V_48 ) ;
V_18 = V_6 -> V_62 [ V_59 ] . V_70 ;
V_6 -> V_62 [ V_59 ] . V_70 = NULL ;
if ( V_18 ) {
V_89 -> V_281 -- ;
V_280 = 1 ;
}
if ( F_21 ( V_200 , & V_6 -> V_62 [ V_59 ] . V_47 ) )
F_23 ( & V_26 -> V_201 ) ;
while ( V_18 && V_18 -> V_111 <
V_6 -> V_62 [ V_59 ] . V_49 + V_107 ) {
struct V_1 * V_282 = F_68 ( V_18 , V_6 -> V_62 [ V_59 ] . V_49 ) ;
F_19 ( V_114 , & V_18 -> V_113 ) ;
if ( ! F_3 ( V_18 ) ) {
F_149 ( V_26 -> V_37 ) ;
V_18 -> V_19 = * V_17 ;
* V_17 = V_18 ;
}
V_18 = V_282 ;
}
V_18 = V_6 -> V_62 [ V_59 ] . V_71 ;
V_6 -> V_62 [ V_59 ] . V_71 = NULL ;
if ( V_18 ) V_280 = 1 ;
while ( V_18 && V_18 -> V_111 <
V_6 -> V_62 [ V_59 ] . V_49 + V_107 ) {
struct V_1 * V_283 = F_68 ( V_18 , V_6 -> V_62 [ V_59 ] . V_49 ) ;
F_19 ( V_114 , & V_18 -> V_113 ) ;
if ( ! F_3 ( V_18 ) ) {
F_149 ( V_26 -> V_37 ) ;
V_18 -> V_19 = * V_17 ;
* V_17 = V_18 ;
}
V_18 = V_283 ;
}
if ( ! F_12 ( V_143 , & V_6 -> V_62 [ V_59 ] . V_47 ) &&
( ! F_12 ( V_284 , & V_6 -> V_62 [ V_59 ] . V_47 ) ||
F_12 ( V_227 , & V_6 -> V_62 [ V_59 ] . V_47 ) ) ) {
V_18 = V_6 -> V_62 [ V_59 ] . V_68 ;
V_6 -> V_62 [ V_59 ] . V_68 = NULL ;
if ( F_21 ( V_200 , & V_6 -> V_62 [ V_59 ] . V_47 ) )
F_23 ( & V_26 -> V_201 ) ;
if ( V_18 ) V_89 -> V_285 -- ;
while ( V_18 && V_18 -> V_111 <
V_6 -> V_62 [ V_59 ] . V_49 + V_107 ) {
struct V_1 * V_282 =
F_68 ( V_18 , V_6 -> V_62 [ V_59 ] . V_49 ) ;
F_19 ( V_114 , & V_18 -> V_113 ) ;
if ( ! F_3 ( V_18 ) ) {
V_18 -> V_19 = * V_17 ;
* V_17 = V_18 ;
}
V_18 = V_282 ;
}
}
F_56 ( & V_26 -> V_48 ) ;
if ( V_280 )
F_150 ( V_26 -> V_37 -> V_277 , V_6 -> V_49 ,
V_107 , 0 , 0 ) ;
}
if ( F_21 ( V_271 , & V_6 -> V_24 ) )
if ( F_14 ( & V_26 -> V_272 ) )
F_20 ( V_26 -> V_37 -> V_38 ) ;
}
static int F_151 ( struct V_5 * V_6 , struct V_88 * V_89 ,
int V_286 , int V_9 )
{
struct V_67 * V_62 = & V_6 -> V_62 [ V_286 ] ;
struct V_67 * V_287 = & V_6 -> V_62 [ V_89 -> V_288 ] ;
if ( ! F_12 ( V_72 , & V_62 -> V_47 ) &&
! F_12 ( V_149 , & V_62 -> V_47 ) &&
( V_62 -> V_68 ||
( V_62 -> V_70 && ! F_12 ( V_279 , & V_62 -> V_47 ) ) ||
V_89 -> V_103 || V_89 -> V_104 ||
( V_89 -> V_289 &&
( V_287 -> V_68 ||
( V_287 -> V_70 &&
! F_12 ( V_279 , & V_287 -> V_47 ) ) ) ) ) ) {
if ( ( V_89 -> V_224 == V_9 - 1 ) &&
( V_89 -> V_289 && V_286 == V_89 -> V_288 ) ) {
F_60 ( V_25 , & V_6 -> V_24 ) ;
F_60 ( V_192 , & V_89 -> V_187 ) ;
F_60 ( V_150 , & V_62 -> V_47 ) ;
V_6 -> V_151 . V_147 = V_286 ;
V_6 -> V_151 . V_152 = - 1 ;
V_89 -> V_290 = 1 ;
V_89 -> V_224 ++ ;
return 1 ;
} else if ( F_12 ( V_284 , & V_62 -> V_47 ) ) {
F_60 ( V_72 , & V_62 -> V_47 ) ;
F_60 ( V_95 , & V_62 -> V_47 ) ;
V_89 -> V_270 ++ ;
F_28 ( L_33 , V_286 ,
V_89 -> V_103 ) ;
}
}
return 0 ;
}
static void F_152 ( struct V_5 * V_6 ,
struct V_88 * V_89 , int V_9 )
{
int V_59 ;
if ( ! F_12 ( V_25 , & V_6 -> V_24 ) && ! V_6 -> V_21 &&
! V_6 -> V_22 )
for ( V_59 = V_9 ; V_59 -- ; )
if ( F_151 ( V_6 , V_89 , V_59 , V_9 ) )
break;
F_60 ( V_29 , & V_6 -> V_24 ) ;
}
static int F_153 ( struct V_5 * V_6 , struct V_88 * V_89 ,
struct V_291 * V_292 , int V_286 , int V_9 )
{
struct V_67 * V_62 = & V_6 -> V_62 [ V_286 ] ;
struct V_67 * V_293 [ 2 ] = { & V_6 -> V_62 [ V_292 -> V_288 [ 0 ] ] ,
& V_6 -> V_62 [ V_292 -> V_288 [ 1 ] ] } ;
if ( ! F_12 ( V_72 , & V_62 -> V_47 ) &&
! F_12 ( V_149 , & V_62 -> V_47 ) &&
( V_62 -> V_68 ||
( V_62 -> V_70 && ! F_12 ( V_279 , & V_62 -> V_47 ) ) ||
V_89 -> V_103 || V_89 -> V_104 ||
( V_89 -> V_289 >= 1 &&
( V_293 [ 0 ] -> V_68 || V_89 -> V_281 ) ) ||
( V_89 -> V_289 >= 2 &&
( V_293 [ 1 ] -> V_68 || V_89 -> V_281 ) ) ) ) {
F_15 ( F_12 ( V_150 , & V_62 -> V_47 ) ) ;
F_15 ( F_12 ( V_95 , & V_62 -> V_47 ) ) ;
if ( ( V_89 -> V_224 == V_9 - 1 ) &&
( V_89 -> V_289 && ( V_286 == V_292 -> V_288 [ 0 ] ||
V_286 == V_292 -> V_288 [ 1 ] ) ) ) {
F_28 ( L_34 ,
( unsigned long long ) V_6 -> V_49 , V_286 ) ;
F_60 ( V_25 , & V_6 -> V_24 ) ;
F_60 ( V_192 , & V_89 -> V_187 ) ;
F_60 ( V_150 , & V_62 -> V_47 ) ;
V_6 -> V_151 . V_147 = V_286 ;
V_6 -> V_151 . V_152 = - 1 ;
V_89 -> V_290 = 1 ;
V_89 -> V_224 ++ ;
return 1 ;
} else if ( V_89 -> V_224 == V_9 - 2 && V_89 -> V_289 >= 2 ) {
int V_294 ;
for ( V_294 = V_9 ; V_294 -- ; ) {
if ( V_294 == V_286 )
continue;
if ( ! F_12 ( V_149 ,
& V_6 -> V_62 [ V_294 ] . V_47 ) )
break;
}
F_15 ( V_294 < 0 ) ;
F_28 ( L_35 ,
( unsigned long long ) V_6 -> V_49 ,
V_286 , V_294 ) ;
F_60 ( V_25 , & V_6 -> V_24 ) ;
F_60 ( V_192 , & V_89 -> V_187 ) ;
F_60 ( V_150 , & V_6 -> V_62 [ V_286 ] . V_47 ) ;
F_60 ( V_150 , & V_6 -> V_62 [ V_294 ] . V_47 ) ;
V_6 -> V_151 . V_147 = V_286 ;
V_6 -> V_151 . V_152 = V_294 ;
V_89 -> V_224 += 2 ;
V_89 -> V_290 = 1 ;
return 1 ;
} else if ( F_12 ( V_284 , & V_62 -> V_47 ) ) {
F_60 ( V_72 , & V_62 -> V_47 ) ;
F_60 ( V_95 , & V_62 -> V_47 ) ;
V_89 -> V_270 ++ ;
F_28 ( L_33 ,
V_286 , V_89 -> V_103 ) ;
}
}
return 0 ;
}
static void F_154 ( struct V_5 * V_6 ,
struct V_88 * V_89 , struct V_291 * V_292 ,
int V_9 )
{
int V_59 ;
if ( ! F_12 ( V_25 , & V_6 -> V_24 ) && ! V_6 -> V_21 &&
! V_6 -> V_22 )
for ( V_59 = V_9 ; V_59 -- ; )
if ( F_153 ( V_6 , V_89 , V_292 , V_59 , V_9 ) )
break;
F_60 ( V_29 , & V_6 -> V_24 ) ;
}
static void F_155 ( T_1 * V_26 ,
struct V_5 * V_6 , int V_9 , struct V_1 * * V_17 )
{
int V_59 ;
struct V_67 * V_62 ;
for ( V_59 = V_9 ; V_59 -- ; )
if ( V_6 -> V_62 [ V_59 ] . V_71 ) {
V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( ! F_12 ( V_72 , & V_62 -> V_47 ) &&
F_12 ( V_149 , & V_62 -> V_47 ) ) {
struct V_1 * V_172 , * V_295 ;
int V_280 = 0 ;
F_28 ( L_36 , V_59 ) ;
F_54 ( & V_26 -> V_48 ) ;
V_172 = V_62 -> V_71 ;
V_62 -> V_71 = NULL ;
while ( V_172 && V_172 -> V_111 <
V_62 -> V_49 + V_107 ) {
V_295 = F_68 ( V_172 , V_62 -> V_49 ) ;
if ( ! F_3 ( V_172 ) ) {
F_149 ( V_26 -> V_37 ) ;
V_172 -> V_19 = * V_17 ;
* V_17 = V_172 ;
}
V_172 = V_295 ;
}
if ( V_62 -> V_70 == NULL )
V_280 = 1 ;
F_56 ( & V_26 -> V_48 ) ;
if ( V_280 )
F_150 ( V_26 -> V_37 -> V_277 ,
V_6 -> V_49 ,
V_107 ,
! F_12 ( V_125 , & V_6 -> V_24 ) ,
0 ) ;
}
}
if ( F_21 ( V_271 , & V_6 -> V_24 ) )
if ( F_14 ( & V_26 -> V_272 ) )
F_20 ( V_26 -> V_37 -> V_38 ) ;
}
static void F_156 ( T_1 * V_26 ,
struct V_5 * V_6 , struct V_88 * V_89 , int V_9 )
{
int V_296 = 0 , V_268 = 0 , V_59 ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( ( V_62 -> V_70 || V_59 == V_6 -> V_16 ) &&
! F_12 ( V_72 , & V_62 -> V_47 ) &&
! ( F_12 ( V_149 , & V_62 -> V_47 ) ||
F_12 ( V_150 , & V_62 -> V_47 ) ) ) {
if ( F_12 ( V_284 , & V_62 -> V_47 ) )
V_296 ++ ;
else
V_296 += 2 * V_9 ;
}
if ( ! F_12 ( V_279 , & V_62 -> V_47 ) && V_59 != V_6 -> V_16 &&
! F_12 ( V_72 , & V_62 -> V_47 ) &&
! ( F_12 ( V_149 , & V_62 -> V_47 ) ||
F_12 ( V_150 , & V_62 -> V_47 ) ) ) {
if ( F_12 ( V_284 , & V_62 -> V_47 ) ) V_268 ++ ;
else
V_268 += 2 * V_9 ;
}
}
F_28 ( L_37 ,
( unsigned long long ) V_6 -> V_49 , V_296 , V_268 ) ;
F_60 ( V_29 , & V_6 -> V_24 ) ;
if ( V_296 < V_268 && V_296 > 0 )
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( ( V_62 -> V_70 || V_59 == V_6 -> V_16 ) &&
! F_12 ( V_72 , & V_62 -> V_47 ) &&
! ( F_12 ( V_149 , & V_62 -> V_47 ) ||
F_12 ( V_150 , & V_62 -> V_47 ) ) &&
F_12 ( V_284 , & V_62 -> V_47 ) ) {
if (
F_12 ( V_39 , & V_6 -> V_24 ) ) {
F_28 ( L_38
L_39 , V_59 ) ;
F_60 ( V_72 , & V_62 -> V_47 ) ;
F_60 ( V_95 , & V_62 -> V_47 ) ;
V_89 -> V_270 ++ ;
} else {
F_60 ( V_30 , & V_6 -> V_24 ) ;
F_60 ( V_29 , & V_6 -> V_24 ) ;
}
}
}
if ( V_268 <= V_296 && V_268 > 0 )
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( ! F_12 ( V_279 , & V_62 -> V_47 ) &&
V_59 != V_6 -> V_16 &&
! F_12 ( V_72 , & V_62 -> V_47 ) &&
! ( F_12 ( V_149 , & V_62 -> V_47 ) ||
F_12 ( V_150 , & V_62 -> V_47 ) ) &&
F_12 ( V_284 , & V_62 -> V_47 ) ) {
if (
F_12 ( V_39 , & V_6 -> V_24 ) ) {
F_28 ( L_38
L_40 , V_59 ) ;
F_60 ( V_72 , & V_62 -> V_47 ) ;
F_60 ( V_95 , & V_62 -> V_47 ) ;
V_89 -> V_270 ++ ;
} else {
F_60 ( V_30 , & V_6 -> V_24 ) ;
F_60 ( V_29 , & V_6 -> V_24 ) ;
}
}
}
if ( ( V_89 -> V_290 || ! F_12 ( V_25 , & V_6 -> V_24 ) ) &&
( V_89 -> V_270 == 0 && ( V_268 == 0 || V_296 == 0 ) &&
! F_12 ( V_32 , & V_6 -> V_24 ) ) )
F_144 ( V_6 , V_89 , V_268 == 0 , 0 ) ;
}
static void F_157 ( T_1 * V_26 ,
struct V_5 * V_6 , struct V_88 * V_89 ,
struct V_291 * V_292 , int V_9 )
{
int V_268 = 0 , V_16 = V_6 -> V_16 , V_59 ;
int V_8 = V_6 -> V_8 ;
F_60 ( V_29 , & V_6 -> V_24 ) ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( ! F_12 ( V_279 , & V_62 -> V_47 ) &&
V_59 != V_16 && V_59 != V_8 &&
! F_12 ( V_72 , & V_62 -> V_47 ) &&
! ( F_12 ( V_149 , & V_62 -> V_47 ) ||
F_12 ( V_150 , & V_62 -> V_47 ) ) ) {
V_268 ++ ;
if ( ! F_12 ( V_284 , & V_62 -> V_47 ) )
continue;
if (
F_12 ( V_39 , & V_6 -> V_24 ) ) {
F_28 ( L_41
L_42 ,
( unsigned long long ) V_6 -> V_49 , V_59 ) ;
F_60 ( V_72 , & V_62 -> V_47 ) ;
F_60 ( V_95 , & V_62 -> V_47 ) ;
V_89 -> V_270 ++ ;
} else {
F_28 ( L_43
L_42 ,
( unsigned long long ) V_6 -> V_49 , V_59 ) ;
F_60 ( V_30 , & V_6 -> V_24 ) ;
F_60 ( V_29 , & V_6 -> V_24 ) ;
}
}
}
if ( ( V_89 -> V_290 || ! F_12 ( V_25 , & V_6 -> V_24 ) ) &&
V_89 -> V_270 == 0 && V_268 == 0 &&
! F_12 ( V_32 , & V_6 -> V_24 ) ) {
F_144 ( V_6 , V_89 , 1 , 0 ) ;
}
}
static void F_158 ( T_1 * V_26 , struct V_5 * V_6 ,
struct V_88 * V_89 , int V_9 )
{
struct V_67 * V_62 = NULL ;
F_60 ( V_29 , & V_6 -> V_24 ) ;
switch ( V_6 -> V_21 ) {
case V_297 :
if ( V_89 -> V_289 == 0 ) {
F_15 ( V_89 -> V_224 != V_9 ) ;
V_6 -> V_21 = V_197 ;
F_60 ( V_196 , & V_89 -> V_187 ) ;
F_19 ( V_149 , & V_6 -> V_62 [ V_6 -> V_16 ] . V_47 ) ;
V_89 -> V_224 -- ;
break;
}
V_62 = & V_6 -> V_62 [ V_89 -> V_288 ] ;
case V_154 :
V_6 -> V_21 = V_297 ;
if ( ! V_62 )
V_62 = & V_6 -> V_62 [ V_6 -> V_16 ] ;
if ( F_12 ( V_298 , & V_6 -> V_24 ) )
break;
F_15 ( ! F_12 ( V_149 , & V_62 -> V_47 ) ) ;
F_15 ( V_89 -> V_224 != V_9 ) ;
F_60 ( V_72 , & V_62 -> V_47 ) ;
V_89 -> V_270 ++ ;
F_60 ( V_91 , & V_62 -> V_47 ) ;
F_19 ( V_125 , & V_6 -> V_24 ) ;
F_60 ( V_298 , & V_6 -> V_24 ) ;
break;
case V_197 :
break;
case V_183 :
V_6 -> V_21 = V_297 ;
if ( V_89 -> V_289 )
break;
if ( ( V_6 -> V_151 . V_184 & V_299 ) == 0 )
F_60 ( V_298 , & V_6 -> V_24 ) ;
else {
V_26 -> V_37 -> V_300 += V_107 ;
if ( F_12 ( V_301 , & V_26 -> V_37 -> V_235 ) )
F_60 ( V_298 , & V_6 -> V_24 ) ;
else {
V_6 -> V_21 = V_153 ;
F_60 ( V_25 , & V_6 -> V_24 ) ;
F_60 ( V_192 , & V_89 -> V_187 ) ;
F_60 ( V_150 ,
& V_6 -> V_62 [ V_6 -> V_16 ] . V_47 ) ;
V_6 -> V_151 . V_147 = V_6 -> V_16 ;
V_6 -> V_151 . V_152 = - 1 ;
V_89 -> V_224 ++ ;
}
}
break;
case V_153 :
break;
default:
F_44 ( V_73 L_44 ,
V_110 , V_6 -> V_21 ,
( unsigned long long ) V_6 -> V_49 ) ;
F_45 () ;
}
}
static void F_159 ( T_1 * V_26 , struct V_5 * V_6 ,
struct V_88 * V_89 ,
struct V_291 * V_292 , int V_9 )
{
int V_16 = V_6 -> V_16 ;
int V_8 = V_6 -> V_8 ;
struct V_67 * V_62 ;
F_60 ( V_29 , & V_6 -> V_24 ) ;
F_15 ( V_89 -> V_289 > 2 ) ;
switch ( V_6 -> V_21 ) {
case V_297 :
if ( V_89 -> V_289 == V_292 -> V_302 ) {
V_6 -> V_21 = V_197 ;
}
if ( ! V_292 -> V_302 && V_89 -> V_289 < 2 ) {
if ( V_6 -> V_21 == V_197 )
V_6 -> V_21 = V_199 ;
else
V_6 -> V_21 = V_198 ;
}
V_6 -> V_151 . V_184 = 0 ;
if ( V_6 -> V_21 == V_197 ) {
F_19 ( V_149 , & V_6 -> V_62 [ V_16 ] . V_47 ) ;
V_89 -> V_224 -- ;
}
if ( V_6 -> V_21 >= V_197 &&
V_6 -> V_21 <= V_199 ) {
F_60 ( V_196 , & V_89 -> V_187 ) ;
break;
}
F_15 ( V_89 -> V_289 != 2 ) ;
case V_154 :
V_6 -> V_21 = V_297 ;
if ( F_12 ( V_298 , & V_6 -> V_24 ) )
break;
F_15 ( V_89 -> V_224 < V_9 - 1 ) ;
if ( V_89 -> V_289 == 2 ) {
V_62 = & V_6 -> V_62 [ V_292 -> V_288 [ 1 ] ] ;
V_89 -> V_270 ++ ;
F_60 ( V_72 , & V_62 -> V_47 ) ;
F_60 ( V_91 , & V_62 -> V_47 ) ;
}
if ( V_89 -> V_289 >= 1 ) {
V_62 = & V_6 -> V_62 [ V_292 -> V_288 [ 0 ] ] ;
V_89 -> V_270 ++ ;
F_60 ( V_72 , & V_62 -> V_47 ) ;
F_60 ( V_91 , & V_62 -> V_47 ) ;
}
if ( V_6 -> V_151 . V_184 & V_299 ) {
V_62 = & V_6 -> V_62 [ V_16 ] ;
V_89 -> V_270 ++ ;
F_60 ( V_72 , & V_62 -> V_47 ) ;
F_60 ( V_91 , & V_62 -> V_47 ) ;
}
if ( V_6 -> V_151 . V_184 & V_303 ) {
V_62 = & V_6 -> V_62 [ V_8 ] ;
V_89 -> V_270 ++ ;
F_60 ( V_72 , & V_62 -> V_47 ) ;
F_60 ( V_91 , & V_62 -> V_47 ) ;
}
F_19 ( V_125 , & V_6 -> V_24 ) ;
F_60 ( V_298 , & V_6 -> V_24 ) ;
break;
case V_197 :
case V_198 :
case V_199 :
break;
case V_183 :
V_6 -> V_21 = V_297 ;
if ( V_6 -> V_151 . V_184 == 0 ) {
if ( ! V_89 -> V_289 )
F_60 ( V_298 , & V_6 -> V_24 ) ;
else {
V_6 -> V_21 = V_154 ;
}
} else {
V_26 -> V_37 -> V_300 += V_107 ;
if ( F_12 ( V_301 , & V_26 -> V_37 -> V_235 ) )
F_60 ( V_298 , & V_6 -> V_24 ) ;
else {
int * V_147 = & V_6 -> V_151 . V_147 ;
V_6 -> V_151 . V_147 = - 1 ;
V_6 -> V_151 . V_152 = - 1 ;
V_6 -> V_21 = V_153 ;
F_60 ( V_25 , & V_6 -> V_24 ) ;
F_60 ( V_192 , & V_89 -> V_187 ) ;
if ( V_6 -> V_151 . V_184 & V_299 ) {
F_60 ( V_150 ,
& V_6 -> V_62 [ V_16 ] . V_47 ) ;
* V_147 = V_16 ;
V_147 = & V_6 -> V_151 . V_152 ;
V_89 -> V_224 ++ ;
}
if ( V_6 -> V_151 . V_184 & V_303 ) {
F_60 ( V_150 ,
& V_6 -> V_62 [ V_8 ] . V_47 ) ;
* V_147 = V_8 ;
V_89 -> V_224 ++ ;
}
}
}
break;
case V_153 :
break;
default:
F_44 ( V_73 L_44 ,
V_110 , V_6 -> V_21 ,
( unsigned long long ) V_6 -> V_49 ) ;
F_45 () ;
}
}
static void F_160 ( T_1 * V_26 , struct V_5 * V_6 ,
struct V_291 * V_292 )
{
int V_59 ;
struct V_126 * V_128 = NULL ;
F_19 ( V_304 , & V_6 -> V_24 ) ;
for ( V_59 = 0 ; V_59 < V_6 -> V_9 ; V_59 ++ )
if ( V_59 != V_6 -> V_16 && V_59 != V_6 -> V_8 ) {
int V_239 , V_305 ;
struct V_5 * V_267 ;
struct V_133 V_134 ;
T_2 V_306 = F_141 ( V_6 , V_59 , 1 ) ;
T_2 V_89 = F_142 ( V_26 , V_306 , 0 ,
& V_239 , NULL ) ;
V_267 = F_53 ( V_26 , V_89 , 0 , 1 , 1 ) ;
if ( V_267 == NULL )
continue;
if ( ! F_12 ( V_42 , & V_267 -> V_24 ) ||
F_12 ( V_307 , & V_267 -> V_62 [ V_239 ] . V_47 ) ) {
F_24 ( V_267 ) ;
continue;
}
F_64 ( & V_134 , 0 , V_128 , NULL , NULL , NULL ) ;
V_128 = F_66 ( V_267 -> V_62 [ V_239 ] . V_57 ,
V_6 -> V_62 [ V_59 ] . V_57 , 0 , 0 , V_121 ,
& V_134 ) ;
F_60 ( V_307 , & V_267 -> V_62 [ V_239 ] . V_47 ) ;
F_60 ( V_149 , & V_267 -> V_62 [ V_239 ] . V_47 ) ;
for ( V_305 = 0 ; V_305 < V_26 -> V_11 ; V_305 ++ )
if ( V_305 != V_267 -> V_16 &&
( ! V_292 || V_305 != V_267 -> V_8 ) &&
! F_12 ( V_307 , & V_267 -> V_62 [ V_305 ] . V_47 ) )
break;
if ( V_305 == V_26 -> V_11 ) {
F_60 ( V_308 , & V_267 -> V_24 ) ;
F_60 ( V_29 , & V_267 -> V_24 ) ;
}
F_24 ( V_267 ) ;
}
if ( V_128 ) {
F_100 ( V_128 ) ;
F_161 ( V_128 ) ;
}
}
static void F_162 ( struct V_5 * V_6 )
{
T_1 * V_26 = V_6 -> V_46 ;
int V_9 = V_6 -> V_9 , V_59 ;
struct V_1 * V_17 = NULL ;
struct V_88 V_89 ;
struct V_67 * V_62 ;
T_3 * V_309 = NULL ;
int V_182 ;
int V_310 = 0 ;
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
F_28 ( L_45
L_46 , ( unsigned long long ) V_6 -> V_49 , V_6 -> V_24 ,
F_17 ( & V_6 -> V_13 ) , V_6 -> V_16 , V_6 -> V_21 ,
V_6 -> V_22 ) ;
F_87 ( & V_6 -> V_173 ) ;
F_19 ( V_29 , & V_6 -> V_24 ) ;
F_19 ( V_30 , & V_6 -> V_24 ) ;
V_89 . V_103 = F_12 ( V_311 , & V_6 -> V_24 ) ;
V_89 . V_104 = F_12 ( V_304 , & V_6 -> V_24 ) ;
V_89 . V_105 = F_12 ( V_308 , & V_6 -> V_24 ) ;
F_50 () ;
for ( V_59 = V_9 ; V_59 -- ; ) {
T_3 * V_80 ;
V_62 = & V_6 -> V_62 [ V_59 ] ;
F_28 ( L_47
L_48 , V_59 , V_62 -> V_47 , V_62 -> V_68 , V_62 -> V_69 ,
V_62 -> V_70 , V_62 -> V_71 ) ;
if ( F_12 ( V_149 , & V_62 -> V_47 ) && V_62 -> V_68 &&
! F_12 ( V_23 , & V_6 -> V_24 ) )
F_60 ( V_143 , & V_62 -> V_47 ) ;
if ( F_12 ( V_72 , & V_62 -> V_47 ) ) V_89 . V_270 ++ ;
if ( F_12 ( V_149 , & V_62 -> V_47 ) ) V_89 . V_224 ++ ;
if ( F_12 ( V_150 , & V_62 -> V_47 ) ) V_89 . V_312 ++ ;
if ( F_12 ( V_143 , & V_62 -> V_47 ) )
V_89 . V_313 ++ ;
else if ( V_62 -> V_68 )
V_89 . V_285 ++ ;
if ( V_62 -> V_70 ) {
V_89 . V_281 ++ ;
if ( ! F_12 ( V_279 , & V_62 -> V_47 ) )
V_89 . V_314 ++ ;
}
if ( V_62 -> V_71 )
V_89 . V_71 ++ ;
V_80 = F_51 ( V_26 -> V_9 [ V_59 ] . V_80 ) ;
if ( V_309 == NULL &&
V_80 && F_75 ( F_12 ( V_315 , & V_80 -> V_47 ) ) ) {
V_309 = V_80 ;
F_37 ( & V_80 -> V_102 ) ;
}
F_19 ( V_284 , & V_62 -> V_47 ) ;
if ( ! V_80 )
;
else if ( F_12 ( V_82 , & V_80 -> V_47 ) )
F_60 ( V_284 , & V_62 -> V_47 ) ;
else {
if ( V_6 -> V_49 + V_107 <= V_80 -> V_316 )
F_60 ( V_284 , & V_62 -> V_47 ) ;
}
if ( ! F_12 ( V_284 , & V_62 -> V_47 ) ) {
F_19 ( V_227 , & V_62 -> V_47 ) ;
F_19 ( V_123 , & V_62 -> V_47 ) ;
}
if ( F_12 ( V_227 , & V_62 -> V_47 ) )
F_19 ( V_284 , & V_62 -> V_47 ) ;
if ( ! F_12 ( V_284 , & V_62 -> V_47 ) ) {
V_89 . V_289 ++ ;
V_89 . V_288 = V_59 ;
}
}
F_52 () ;
if ( F_75 ( V_309 ) ) {
if ( V_89 . V_103 || V_89 . V_104 || V_89 . V_105 ||
V_89 . V_281 || V_89 . V_71 ) {
F_60 ( V_29 , & V_6 -> V_24 ) ;
goto V_317;
}
F_139 ( V_309 , V_26 -> V_37 ) ;
V_309 = NULL ;
}
if ( V_89 . V_313 && ! F_12 ( V_23 , & V_6 -> V_24 ) ) {
F_60 ( V_191 , & V_89 . V_187 ) ;
F_60 ( V_23 , & V_6 -> V_24 ) ;
}
F_28 ( L_49
L_50 ,
V_89 . V_270 , V_89 . V_224 , V_89 . V_285 , V_89 . V_281 ,
V_89 . V_289 , V_89 . V_288 ) ;
if ( V_89 . V_289 > 1 && V_89 . V_285 + V_89 . V_281 + V_89 . V_71 )
F_148 ( V_26 , V_6 , & V_89 , V_9 , & V_17 ) ;
if ( V_89 . V_289 > 1 && V_89 . V_103 ) {
F_163 ( V_26 -> V_37 , V_107 , 0 ) ;
F_19 ( V_311 , & V_6 -> V_24 ) ;
V_89 . V_103 = 0 ;
}
V_62 = & V_6 -> V_62 [ V_6 -> V_16 ] ;
if ( V_89 . V_71 &&
( ( F_12 ( V_284 , & V_62 -> V_47 ) &&
! F_12 ( V_72 , & V_62 -> V_47 ) &&
F_12 ( V_149 , & V_62 -> V_47 ) ) ||
( V_89 . V_289 == 1 && V_89 . V_288 == V_6 -> V_16 ) ) )
F_155 ( V_26 , V_6 , V_9 , & V_17 ) ;
if ( V_89 . V_285 || V_89 . V_314 ||
( V_89 . V_103 && ( V_89 . V_224 + V_89 . V_312 < V_9 ) ) || V_89 . V_104 )
F_152 ( V_6 , & V_89 , V_9 ) ;
V_182 = 0 ;
if ( V_6 -> V_22 == V_179 )
V_182 = 1 ;
if ( V_6 -> V_22 == V_177 ||
V_6 -> V_22 == V_179 ) {
V_6 -> V_22 = V_318 ;
F_15 ( ! F_12 ( V_149 , & V_6 -> V_62 [ V_6 -> V_16 ] . V_47 ) ) ;
for ( V_59 = V_9 ; V_59 -- ; ) {
V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( F_12 ( V_72 , & V_62 -> V_47 ) &&
( V_59 == V_6 -> V_16 || V_62 -> V_71 ) ) {
F_28 ( L_51 , V_59 ) ;
F_60 ( V_91 , & V_62 -> V_47 ) ;
if ( V_182 )
continue;
if ( ! F_12 ( V_284 , & V_62 -> V_47 ) ||
( V_59 == V_6 -> V_16 && V_89 . V_289 == 0 ) )
F_60 ( V_298 , & V_6 -> V_24 ) ;
}
}
if ( F_21 ( V_39 , & V_6 -> V_24 ) )
V_310 = 1 ;
}
if ( V_89 . V_281 && ! V_6 -> V_22 && ! V_6 -> V_21 )
F_156 ( V_26 , V_6 , & V_89 , V_9 ) ;
if ( V_6 -> V_21 ||
( V_89 . V_103 && V_89 . V_270 == 0 &&
! F_12 ( V_25 , & V_6 -> V_24 ) &&
! F_12 ( V_298 , & V_6 -> V_24 ) ) )
F_158 ( V_26 , V_6 , & V_89 , V_9 ) ;
if ( V_89 . V_103 && V_89 . V_270 == 0 && F_12 ( V_298 , & V_6 -> V_24 ) ) {
F_163 ( V_26 -> V_37 , V_107 , 1 ) ;
F_19 ( V_311 , & V_6 -> V_24 ) ;
}
if ( V_89 . V_289 == 1 && ! V_26 -> V_37 -> V_319 &&
F_12 ( V_227 , & V_6 -> V_62 [ V_89 . V_288 ] . V_47 )
&& ! F_12 ( V_72 , & V_6 -> V_62 [ V_89 . V_288 ] . V_47 )
&& F_12 ( V_149 , & V_6 -> V_62 [ V_89 . V_288 ] . V_47 )
) {
V_62 = & V_6 -> V_62 [ V_89 . V_288 ] ;
if ( ! F_12 ( V_123 , & V_62 -> V_47 ) ) {
F_60 ( V_91 , & V_62 -> V_47 ) ;
F_60 ( V_123 , & V_62 -> V_47 ) ;
F_60 ( V_72 , & V_62 -> V_47 ) ;
V_89 . V_270 ++ ;
} else {
F_60 ( V_95 , & V_62 -> V_47 ) ;
F_60 ( V_72 , & V_62 -> V_47 ) ;
V_89 . V_270 ++ ;
}
}
if ( V_6 -> V_22 == V_181 ) {
struct V_5 * V_267
= F_53 ( V_26 , V_6 -> V_49 , 1 , 1 , 1 ) ;
if ( V_267 && F_12 ( V_304 , & V_267 -> V_24 ) ) {
F_60 ( V_30 , & V_6 -> V_24 ) ;
F_60 ( V_29 , & V_6 -> V_24 ) ;
if ( ! F_145 ( V_39 ,
& V_267 -> V_24 ) )
F_37 ( & V_26 -> V_40 ) ;
F_24 ( V_267 ) ;
goto V_317;
}
if ( V_267 )
F_24 ( V_267 ) ;
V_6 -> V_22 = V_318 ;
F_19 ( V_42 , & V_6 -> V_24 ) ;
for ( V_59 = V_26 -> V_11 ; V_59 -- ; ) {
F_60 ( V_91 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
F_60 ( V_72 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
V_89 . V_270 ++ ;
}
}
if ( V_89 . V_105 && F_12 ( V_42 , & V_6 -> V_24 ) &&
! V_6 -> V_22 ) {
V_6 -> V_9 = V_26 -> V_11 ;
F_43 ( V_6 -> V_49 , V_26 , 0 , V_6 ) ;
F_144 ( V_6 , & V_89 , 1 , 1 ) ;
} else if ( V_89 . V_105 && ! V_6 -> V_22 && V_89 . V_270 == 0 ) {
F_19 ( V_308 , & V_6 -> V_24 ) ;
F_22 ( & V_26 -> V_320 ) ;
F_23 ( & V_26 -> V_201 ) ;
F_163 ( V_26 -> V_37 , V_107 , 1 ) ;
}
if ( V_89 . V_104 && V_89 . V_270 == 0 &&
! F_12 ( V_25 , & V_6 -> V_24 ) )
F_160 ( V_26 , V_6 , NULL ) ;
V_317:
F_88 ( & V_6 -> V_173 ) ;
if ( F_75 ( V_309 ) )
F_164 ( V_309 , V_26 -> V_37 ) ;
if ( V_89 . V_187 )
F_104 ( V_6 , V_89 . V_187 ) ;
F_57 ( V_6 , & V_89 ) ;
if ( V_310 ) {
F_22 ( & V_26 -> V_40 ) ;
if ( F_17 ( & V_26 -> V_40 ) <
V_41 )
F_20 ( V_26 -> V_37 -> V_38 ) ;
}
F_9 ( V_17 ) ;
}
static void F_165 ( struct V_5 * V_6 )
{
T_1 * V_26 = V_6 -> V_46 ;
int V_9 = V_6 -> V_9 ;
struct V_1 * V_17 = NULL ;
int V_59 , V_16 = V_6 -> V_16 , V_8 = V_6 -> V_8 ;
struct V_88 V_89 ;
struct V_291 V_292 ;
struct V_67 * V_62 , * V_321 , * V_322 ;
T_3 * V_309 = NULL ;
int V_310 = 0 ;
F_28 ( L_52
L_53 ,
( unsigned long long ) V_6 -> V_49 , V_6 -> V_24 ,
F_17 ( & V_6 -> V_13 ) , V_16 , V_8 ,
V_6 -> V_21 , V_6 -> V_22 ) ;
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
F_87 ( & V_6 -> V_173 ) ;
F_19 ( V_29 , & V_6 -> V_24 ) ;
F_19 ( V_30 , & V_6 -> V_24 ) ;
V_89 . V_103 = F_12 ( V_311 , & V_6 -> V_24 ) ;
V_89 . V_104 = F_12 ( V_304 , & V_6 -> V_24 ) ;
V_89 . V_105 = F_12 ( V_308 , & V_6 -> V_24 ) ;
F_50 () ;
for ( V_59 = V_9 ; V_59 -- ; ) {
T_3 * V_80 ;
V_62 = & V_6 -> V_62 [ V_59 ] ;
F_28 ( L_54 ,
V_59 , V_62 -> V_47 , V_62 -> V_68 , V_62 -> V_70 , V_62 -> V_71 ) ;
if ( F_12 ( V_149 , & V_62 -> V_47 ) && V_62 -> V_68 &&
! F_12 ( V_23 , & V_6 -> V_24 ) )
F_60 ( V_143 , & V_62 -> V_47 ) ;
if ( F_12 ( V_72 , & V_62 -> V_47 ) ) V_89 . V_270 ++ ;
if ( F_12 ( V_149 , & V_62 -> V_47 ) ) V_89 . V_224 ++ ;
if ( F_12 ( V_150 , & V_62 -> V_47 ) ) {
V_89 . V_312 ++ ;
F_15 ( V_89 . V_312 > 2 ) ;
}
if ( F_12 ( V_143 , & V_62 -> V_47 ) ) {
V_89 . V_313 ++ ;
} else if ( V_62 -> V_68 )
V_89 . V_285 ++ ;
if ( V_62 -> V_70 ) {
V_89 . V_281 ++ ;
if ( ! F_12 ( V_279 , & V_62 -> V_47 ) )
V_89 . V_314 ++ ;
}
if ( V_62 -> V_71 )
V_89 . V_71 ++ ;
V_80 = F_51 ( V_26 -> V_9 [ V_59 ] . V_80 ) ;
if ( V_309 == NULL &&
V_80 && F_75 ( F_12 ( V_315 , & V_80 -> V_47 ) ) ) {
V_309 = V_80 ;
F_37 ( & V_80 -> V_102 ) ;
}
F_19 ( V_284 , & V_62 -> V_47 ) ;
if ( ! V_80 )
;
else if ( F_12 ( V_82 , & V_80 -> V_47 ) )
F_60 ( V_284 , & V_62 -> V_47 ) ;
else {
if ( V_6 -> V_49 + V_107 <= V_80 -> V_316 )
F_60 ( V_284 , & V_62 -> V_47 ) ;
}
if ( ! F_12 ( V_284 , & V_62 -> V_47 ) ) {
F_19 ( V_227 , & V_62 -> V_47 ) ;
F_19 ( V_123 , & V_62 -> V_47 ) ;
}
if ( F_12 ( V_227 , & V_62 -> V_47 ) )
F_19 ( V_284 , & V_62 -> V_47 ) ;
if ( ! F_12 ( V_284 , & V_62 -> V_47 ) ) {
if ( V_89 . V_289 < 2 )
V_292 . V_288 [ V_89 . V_289 ] = V_59 ;
V_89 . V_289 ++ ;
}
}
F_52 () ;
if ( F_75 ( V_309 ) ) {
if ( V_89 . V_103 || V_89 . V_104 || V_89 . V_105 ||
V_89 . V_281 || V_89 . V_71 ) {
F_60 ( V_29 , & V_6 -> V_24 ) ;
goto V_317;
}
F_139 ( V_309 , V_26 -> V_37 ) ;
V_309 = NULL ;
}
if ( V_89 . V_313 && ! F_12 ( V_23 , & V_6 -> V_24 ) ) {
F_60 ( V_191 , & V_89 . V_187 ) ;
F_60 ( V_23 , & V_6 -> V_24 ) ;
}
F_28 ( L_49
L_55 ,
V_89 . V_270 , V_89 . V_224 , V_89 . V_285 , V_89 . V_281 , V_89 . V_289 ,
V_292 . V_288 [ 0 ] , V_292 . V_288 [ 1 ] ) ;
if ( V_89 . V_289 > 2 && V_89 . V_285 + V_89 . V_281 + V_89 . V_71 )
F_148 ( V_26 , V_6 , & V_89 , V_9 , & V_17 ) ;
if ( V_89 . V_289 > 2 && V_89 . V_103 ) {
F_163 ( V_26 -> V_37 , V_107 , 0 ) ;
F_19 ( V_311 , & V_6 -> V_24 ) ;
V_89 . V_103 = 0 ;
}
V_321 = & V_6 -> V_62 [ V_16 ] ;
V_292 . V_323 = ( V_89 . V_289 >= 1 && V_292 . V_288 [ 0 ] == V_16 )
|| ( V_89 . V_289 >= 2 && V_292 . V_288 [ 1 ] == V_16 ) ;
V_322 = & V_6 -> V_62 [ V_8 ] ;
V_292 . V_302 = ( V_89 . V_289 >= 1 && V_292 . V_288 [ 0 ] == V_8 )
|| ( V_89 . V_289 >= 2 && V_292 . V_288 [ 1 ] == V_8 ) ;
if ( V_89 . V_71 &&
( V_292 . V_323 || ( ( F_12 ( V_284 , & V_321 -> V_47 )
&& ! F_12 ( V_72 , & V_321 -> V_47 )
&& F_12 ( V_149 , & V_321 -> V_47 ) ) ) ) &&
( V_292 . V_302 || ( ( F_12 ( V_284 , & V_322 -> V_47 )
&& ! F_12 ( V_72 , & V_322 -> V_47 )
&& F_12 ( V_149 , & V_322 -> V_47 ) ) ) ) )
F_155 ( V_26 , V_6 , V_9 , & V_17 ) ;
if ( V_89 . V_285 || V_89 . V_314 || ( V_89 . V_281 && V_89 . V_289 ) ||
( V_89 . V_103 && ( V_89 . V_224 + V_89 . V_312 < V_9 ) ) || V_89 . V_104 )
F_154 ( V_6 , & V_89 , & V_292 , V_9 ) ;
if ( V_6 -> V_22 == V_177 ) {
V_6 -> V_22 = V_318 ;
F_15 ( ! F_12 ( V_149 , & V_6 -> V_62 [ V_6 -> V_16 ] . V_47 ) ) ;
F_15 ( ! F_12 ( V_149 , & V_6 -> V_62 [ V_8 ] . V_47 ) ) ;
for ( V_59 = V_9 ; V_59 -- ; ) {
V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( F_12 ( V_72 , & V_62 -> V_47 ) &&
( V_59 == V_6 -> V_16 || V_59 == V_8 ||
V_62 -> V_71 ) ) {
F_28 ( L_51 , V_59 ) ;
F_15 ( ! F_12 ( V_149 , & V_62 -> V_47 ) ) ;
F_60 ( V_91 , & V_62 -> V_47 ) ;
if ( ! F_12 ( V_284 , & V_62 -> V_47 ) ||
( ( V_59 == V_6 -> V_16 || V_59 == V_8 ) &&
V_89 . V_289 == 0 ) )
F_60 ( V_298 , & V_6 -> V_24 ) ;
}
}
if ( F_21 ( V_39 , & V_6 -> V_24 ) )
V_310 = 1 ;
}
if ( V_89 . V_281 && ! V_6 -> V_22 && ! V_6 -> V_21 )
F_157 ( V_26 , V_6 , & V_89 , & V_292 , V_9 ) ;
if ( V_6 -> V_21 ||
( V_89 . V_103 && V_89 . V_270 == 0 &&
! F_12 ( V_25 , & V_6 -> V_24 ) &&
! F_12 ( V_298 , & V_6 -> V_24 ) ) )
F_159 ( V_26 , V_6 , & V_89 , & V_292 , V_9 ) ;
if ( V_89 . V_103 && V_89 . V_270 == 0 && F_12 ( V_298 , & V_6 -> V_24 ) ) {
F_163 ( V_26 -> V_37 , V_107 , 1 ) ;
F_19 ( V_311 , & V_6 -> V_24 ) ;
}
if ( V_89 . V_289 <= 2 && ! V_26 -> V_37 -> V_319 )
for ( V_59 = 0 ; V_59 < V_89 . V_289 ; V_59 ++ ) {
V_62 = & V_6 -> V_62 [ V_292 . V_288 [ V_59 ] ] ;
if ( F_12 ( V_227 , & V_62 -> V_47 )
&& ! F_12 ( V_72 , & V_62 -> V_47 )
&& F_12 ( V_149 , & V_62 -> V_47 )
) {
if ( ! F_12 ( V_123 , & V_62 -> V_47 ) ) {
F_60 ( V_91 , & V_62 -> V_47 ) ;
F_60 ( V_123 , & V_62 -> V_47 ) ;
F_60 ( V_72 , & V_62 -> V_47 ) ;
V_89 . V_270 ++ ;
} else {
F_60 ( V_95 , & V_62 -> V_47 ) ;
F_60 ( V_72 , & V_62 -> V_47 ) ;
V_89 . V_270 ++ ;
}
}
}
if ( V_6 -> V_22 == V_181 ) {
V_6 -> V_22 = V_318 ;
F_19 ( V_42 , & V_6 -> V_24 ) ;
for ( V_59 = V_26 -> V_11 ; V_59 -- ; ) {
F_60 ( V_91 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
F_60 ( V_72 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
V_89 . V_270 ++ ;
}
}
if ( V_89 . V_105 && F_12 ( V_42 , & V_6 -> V_24 ) &&
! V_6 -> V_22 ) {
struct V_5 * V_267
= F_53 ( V_26 , V_6 -> V_49 , 1 , 1 , 1 ) ;
if ( V_267 && F_12 ( V_304 , & V_267 -> V_24 ) ) {
F_60 ( V_30 , & V_6 -> V_24 ) ;
F_60 ( V_29 , & V_6 -> V_24 ) ;
if ( ! F_145 ( V_39 ,
& V_267 -> V_24 ) )
F_37 ( & V_26 -> V_40 ) ;
F_24 ( V_267 ) ;
goto V_317;
}
if ( V_267 )
F_24 ( V_267 ) ;
V_6 -> V_9 = V_26 -> V_11 ;
F_43 ( V_6 -> V_49 , V_26 , 0 , V_6 ) ;
F_144 ( V_6 , & V_89 , 1 , 1 ) ;
} else if ( V_89 . V_105 && ! V_6 -> V_22 && V_89 . V_270 == 0 ) {
F_19 ( V_308 , & V_6 -> V_24 ) ;
F_22 ( & V_26 -> V_320 ) ;
F_23 ( & V_26 -> V_201 ) ;
F_163 ( V_26 -> V_37 , V_107 , 1 ) ;
}
if ( V_89 . V_104 && V_89 . V_270 == 0 &&
! F_12 ( V_25 , & V_6 -> V_24 ) )
F_160 ( V_26 , V_6 , & V_292 ) ;
V_317:
F_88 ( & V_6 -> V_173 ) ;
if ( F_75 ( V_309 ) )
F_164 ( V_309 , V_26 -> V_37 ) ;
if ( V_89 . V_187 )
F_104 ( V_6 , V_89 . V_187 ) ;
F_57 ( V_6 , & V_89 ) ;
if ( V_310 ) {
F_22 ( & V_26 -> V_40 ) ;
if ( F_17 ( & V_26 -> V_40 ) <
V_41 )
F_20 ( V_26 -> V_37 -> V_38 ) ;
}
F_9 ( V_17 ) ;
}
static void F_166 ( struct V_5 * V_6 )
{
if ( V_6 -> V_46 -> V_189 == 6 )
F_165 ( V_6 ) ;
else
F_162 ( V_6 ) ;
}
static void F_167 ( T_1 * V_26 )
{
if ( F_17 ( & V_26 -> V_40 ) < V_41 ) {
while ( ! F_16 ( & V_26 -> V_31 ) ) {
struct V_53 * V_324 = V_26 -> V_31 . V_56 ;
struct V_5 * V_6 ;
V_6 = F_35 ( V_324 , struct V_5 , V_27 ) ;
F_36 ( V_324 ) ;
F_19 ( V_30 , & V_6 -> V_24 ) ;
if ( ! F_145 ( V_39 , & V_6 -> V_24 ) )
F_37 ( & V_26 -> V_40 ) ;
F_18 ( & V_6 -> V_27 , & V_26 -> V_325 ) ;
}
}
}
static void F_168 ( T_1 * V_26 )
{
struct V_53 V_326 ;
F_124 ( & V_326 , & V_26 -> V_35 ) ;
F_36 ( & V_26 -> V_35 ) ;
while ( ! F_16 ( & V_326 ) ) {
struct V_5 * V_6 = F_35 ( V_326 . V_56 , struct V_5 , V_27 ) ;
F_36 ( & V_6 -> V_27 ) ;
F_37 ( & V_6 -> V_13 ) ;
F_13 ( V_26 , V_6 ) ;
}
}
int F_169 ( T_7 * V_37 , int V_327 )
{
T_1 * V_26 = V_37 -> V_233 ;
if ( V_26 -> V_86 )
return 1 ;
if ( V_26 -> V_85 )
return 1 ;
if ( F_170 ( & V_26 -> V_43 ) )
return 1 ;
return 0 ;
}
static int F_171 ( void * V_328 , int V_327 )
{
T_7 * V_37 = V_328 ;
return F_172 ( V_37 , V_327 ) ||
F_169 ( V_37 , V_327 ) ;
}
static int F_173 ( struct V_329 * V_330 ,
struct V_331 * V_332 ,
struct V_129 * V_333 )
{
T_7 * V_37 = V_330 -> V_334 ;
T_2 V_49 = V_332 -> V_111 + F_174 ( V_332 -> V_109 ) ;
int F_117 ;
unsigned int V_249 = V_37 -> V_249 ;
unsigned int V_335 = V_332 -> V_20 >> 9 ;
if ( ( V_332 -> V_98 & 1 ) == V_94 )
return V_333 -> V_120 ;
if ( V_37 -> V_336 < V_37 -> V_249 )
V_249 = V_37 -> V_336 ;
F_117 = ( V_249 - ( ( V_49 & ( V_249 - 1 ) ) + V_335 ) ) << 9 ;
if ( F_117 < 0 ) F_117 = 0 ;
if ( F_117 <= V_333 -> V_120 && V_335 == 0 )
return V_333 -> V_120 ;
else
return F_117 ;
}
static int F_175 ( T_7 * V_37 , struct V_1 * V_1 )
{
T_2 V_49 = V_1 -> V_111 + F_174 ( V_1 -> V_109 ) ;
unsigned int V_249 = V_37 -> V_249 ;
unsigned int V_335 = V_1 -> V_20 >> 9 ;
if ( V_37 -> V_336 < V_37 -> V_249 )
V_249 = V_37 -> V_336 ;
return V_249 >=
( ( V_49 & ( V_249 - 1 ) ) + V_335 ) ;
}
static void F_176 ( struct V_1 * V_18 , T_1 * V_26 )
{
unsigned long V_47 ;
F_25 ( & V_26 -> V_48 , V_47 ) ;
V_18 -> V_19 = V_26 -> V_337 ;
V_26 -> V_337 = V_18 ;
F_26 ( & V_26 -> V_48 , V_47 ) ;
F_20 ( V_26 -> V_37 -> V_38 ) ;
}
static struct V_1 * F_177 ( T_1 * V_26 )
{
struct V_1 * V_18 ;
V_18 = V_26 -> V_45 ;
if ( V_18 ) {
V_26 -> V_45 = NULL ;
return V_18 ;
}
V_18 = V_26 -> V_337 ;
if( V_18 ) {
V_26 -> V_337 = V_18 -> V_19 ;
V_18 -> V_19 = NULL ;
V_18 -> V_2 = 1 ;
}
return V_18 ;
}
static void F_178 ( struct V_1 * V_18 , int error )
{
struct V_1 * V_338 = V_18 -> V_223 ;
T_7 * V_37 ;
T_1 * V_26 ;
int V_224 = F_12 ( V_114 , & V_18 -> V_113 ) ;
T_3 * V_80 ;
F_179 ( V_18 ) ;
V_80 = ( void * ) V_338 -> V_19 ;
V_338 -> V_19 = NULL ;
V_37 = V_80 -> V_37 ;
V_26 = V_37 -> V_233 ;
F_139 ( V_80 , V_26 -> V_37 ) ;
if ( ! error && V_224 ) {
F_10 ( V_338 , 0 ) ;
if ( F_14 ( & V_26 -> V_339 ) )
F_23 ( & V_26 -> V_44 ) ;
return;
}
F_28 ( L_56 ) ;
F_176 ( V_338 , V_26 ) ;
}
static int F_180 ( struct V_1 * V_18 )
{
struct V_329 * V_330 = F_181 ( V_18 -> V_109 ) ;
if ( ( V_18 -> V_20 >> 9 ) > F_182 ( V_330 ) )
return 0 ;
F_183 ( V_330 , V_18 ) ;
if ( V_18 -> V_2 > F_184 ( V_330 ) )
return 0 ;
if ( V_330 -> V_340 )
return 0 ;
return 1 ;
}
static int F_185 ( T_7 * V_37 , struct V_1 * V_341 )
{
T_1 * V_26 = V_37 -> V_233 ;
int V_239 ;
struct V_1 * V_342 ;
T_3 * V_80 ;
if ( ! F_175 ( V_37 , V_341 ) ) {
F_28 ( L_57 ) ;
return 0 ;
}
V_342 = F_186 ( V_341 , V_222 , V_37 ) ;
if ( ! V_342 )
return 0 ;
V_342 -> V_99 = F_178 ;
V_342 -> V_223 = V_341 ;
V_342 -> V_111 = F_142 ( V_26 , V_341 -> V_111 ,
0 ,
& V_239 , NULL ) ;
F_50 () ;
V_80 = F_51 ( V_26 -> V_9 [ V_239 ] . V_80 ) ;
if ( V_80 && F_12 ( V_82 , & V_80 -> V_47 ) ) {
F_37 ( & V_80 -> V_102 ) ;
F_52 () ;
V_341 -> V_19 = ( void * ) V_80 ;
V_342 -> V_109 = V_80 -> V_106 ;
V_342 -> V_113 &= ~ ( 1 << V_343 ) ;
V_342 -> V_111 += V_80 -> V_112 ;
if ( ! F_180 ( V_342 ) ) {
F_179 ( V_342 ) ;
F_139 ( V_80 , V_37 ) ;
return 0 ;
}
F_54 ( & V_26 -> V_48 ) ;
F_55 ( V_26 -> V_44 ,
V_26 -> V_85 == 0 ,
V_26 -> V_48 , ) ;
F_37 ( & V_26 -> V_339 ) ;
F_56 ( & V_26 -> V_48 ) ;
F_62 ( V_342 ) ;
return 1 ;
} else {
F_52 () ;
F_179 ( V_342 ) ;
return 0 ;
}
}
static struct V_5 * F_187 ( T_1 * V_26 )
{
struct V_5 * V_6 ;
F_28 ( L_58 ,
V_110 ,
F_16 ( & V_26 -> V_36 ) ? L_59 : L_60 ,
F_16 ( & V_26 -> V_325 ) ? L_59 : L_60 ,
F_17 ( & V_26 -> V_272 ) , V_26 -> V_344 ) ;
if ( ! F_16 ( & V_26 -> V_36 ) ) {
V_6 = F_35 ( V_26 -> V_36 . V_56 , F_188 ( * V_6 ) , V_27 ) ;
if ( F_16 ( & V_26 -> V_325 ) )
V_26 -> V_344 = 0 ;
else if ( ! F_12 ( V_108 , & V_6 -> V_24 ) ) {
if ( V_26 -> V_325 . V_56 == V_26 -> V_345 )
V_26 -> V_344 ++ ;
else {
V_26 -> V_345 = V_26 -> V_325 . V_56 ;
V_26 -> V_344 -= V_26 -> V_346 ;
if ( V_26 -> V_344 < 0 )
V_26 -> V_344 = 0 ;
}
}
} else if ( ! F_16 ( & V_26 -> V_325 ) &&
( ( V_26 -> V_346 &&
V_26 -> V_344 > V_26 -> V_346 ) ||
F_17 ( & V_26 -> V_272 ) == 0 ) ) {
V_6 = F_35 ( V_26 -> V_325 . V_56 ,
F_188 ( * V_6 ) , V_27 ) ;
V_26 -> V_344 -= V_26 -> V_346 ;
if ( V_26 -> V_344 < 0 )
V_26 -> V_344 = 0 ;
} else
return NULL ;
F_36 ( & V_6 -> V_27 ) ;
F_37 ( & V_6 -> V_13 ) ;
F_15 ( F_17 ( & V_6 -> V_13 ) != 1 ) ;
return V_6 ;
}
static int F_189 ( T_7 * V_37 , struct V_1 * V_18 )
{
T_1 * V_26 = V_37 -> V_233 ;
int V_239 ;
T_2 V_244 ;
T_2 V_347 , V_348 ;
struct V_5 * V_6 ;
const int V_90 = F_190 ( V_18 ) ;
int V_349 ;
int V_350 ;
if ( F_75 ( V_18 -> V_98 & V_351 ) ) {
F_191 ( V_37 , V_18 ) ;
return 0 ;
}
F_192 ( V_37 , V_18 ) ;
if ( V_90 == V_96 &&
V_37 -> V_77 == V_78 &&
F_185 ( V_37 , V_18 ) )
return 0 ;
V_347 = V_18 -> V_111 & ~ ( ( T_2 ) V_107 - 1 ) ;
V_348 = V_18 -> V_111 + ( V_18 -> V_20 >> 9 ) ;
V_18 -> V_19 = NULL ;
V_18 -> V_2 = 1 ;
V_350 = F_193 ( V_37 ) ;
for (; V_347 < V_348 ; V_347 += V_107 ) {
F_194 ( V_352 ) ;
int V_9 , V_250 ;
int V_64 ;
V_231:
V_64 = 0 ;
V_9 = V_26 -> V_11 ;
F_195 ( & V_26 -> V_201 , & V_352 , V_353 ) ;
if ( F_75 ( V_26 -> V_354 != V_78 ) ) {
F_54 ( & V_26 -> V_48 ) ;
if ( V_37 -> V_355 < 0
? V_347 < V_26 -> V_354
: V_347 >= V_26 -> V_354 ) {
V_9 = V_26 -> V_66 ;
V_64 = 1 ;
} else {
if ( V_37 -> V_355 < 0
? V_347 < V_26 -> V_356
: V_347 >= V_26 -> V_356 ) {
F_56 ( & V_26 -> V_48 ) ;
F_196 () ;
goto V_231;
}
}
F_56 ( & V_26 -> V_48 ) ;
}
V_250 = V_9 - V_26 -> V_79 ;
V_244 = F_142 ( V_26 , V_347 ,
V_64 ,
& V_239 , NULL ) ;
F_28 ( L_61 ,
( unsigned long long ) V_244 ,
( unsigned long long ) V_347 ) ;
V_6 = F_53 ( V_26 , V_244 , V_64 ,
( V_18 -> V_98 & V_357 ) , 0 ) ;
if ( V_6 ) {
if ( F_75 ( V_64 ) ) {
int V_358 = 0 ;
F_54 ( & V_26 -> V_48 ) ;
if ( V_37 -> V_355 < 0
? V_347 >= V_26 -> V_354
: V_347 < V_26 -> V_354 )
V_358 = 1 ;
F_56 ( & V_26 -> V_48 ) ;
if ( V_358 ) {
F_24 ( V_6 ) ;
F_196 () ;
goto V_231;
}
}
if ( F_190 ( V_18 ) == V_94 &&
V_347 >= V_37 -> V_359 &&
V_347 < V_37 -> V_360 ) {
F_24 ( V_6 ) ;
F_197 ( V_361 ) ;
F_195 ( & V_26 -> V_201 ,
& V_352 , V_362 ) ;
if ( V_347 >= V_37 -> V_359 &&
V_347 < V_37 -> V_360 )
F_196 () ;
goto V_231;
}
if ( F_12 ( V_42 , & V_6 -> V_24 ) ||
! F_146 ( V_6 , V_18 , V_239 , ( V_18 -> V_98 & V_363 ) ) ) {
F_20 ( V_37 -> V_38 ) ;
F_24 ( V_6 ) ;
F_196 () ;
goto V_231;
}
F_198 ( & V_26 -> V_201 , & V_352 ) ;
F_60 ( V_29 , & V_6 -> V_24 ) ;
F_19 ( V_30 , & V_6 -> V_24 ) ;
if ( ( V_18 -> V_98 & V_364 ) &&
! F_145 ( V_39 , & V_6 -> V_24 ) )
F_37 ( & V_26 -> V_40 ) ;
F_24 ( V_6 ) ;
} else {
F_19 ( V_114 , & V_18 -> V_113 ) ;
F_198 ( & V_26 -> V_201 , & V_352 ) ;
break;
}
}
if ( ! V_350 )
F_20 ( V_37 -> V_38 ) ;
F_54 ( & V_26 -> V_48 ) ;
V_349 = F_3 ( V_18 ) ;
F_56 ( & V_26 -> V_48 ) ;
if ( V_349 == 0 ) {
if ( V_90 == V_94 )
F_149 ( V_37 ) ;
F_10 ( V_18 , 0 ) ;
}
return 0 ;
}
static T_2 F_199 ( T_7 * V_37 , T_2 V_365 , int * V_366 )
{
T_1 * V_26 = V_37 -> V_233 ;
struct V_5 * V_6 ;
T_2 V_367 , V_348 ;
int V_11 = V_26 -> V_66 ;
int V_250 = V_11 - V_26 -> V_79 ;
int V_368 = V_26 -> V_11 - V_26 -> V_79 ;
int V_59 ;
int V_239 ;
T_2 V_369 , V_370 , V_371 ;
T_2 V_372 ;
int V_373 ;
struct V_53 V_374 ;
if ( V_365 == 0 ) {
if ( V_37 -> V_355 < 0 &&
V_26 -> V_354 < F_200 ( V_37 , 0 , 0 ) ) {
V_365 = F_200 ( V_37 , 0 , 0 )
- V_26 -> V_354 ;
} else if ( V_37 -> V_355 >= 0 &&
V_26 -> V_354 > 0 )
V_365 = V_26 -> V_354 ;
F_143 ( V_365 , V_368 ) ;
if ( V_365 ) {
V_37 -> V_375 = V_365 ;
F_201 ( & V_37 -> V_376 , NULL , L_62 ) ;
* V_366 = 1 ;
return V_365 ;
}
}
if ( V_37 -> V_336 > V_37 -> V_249 )
V_373 = V_37 -> V_336 ;
else
V_373 = V_37 -> V_249 ;
V_369 = V_26 -> V_354 ;
F_143 ( V_369 , V_368 ) ;
V_370 = V_26 -> V_354 ;
F_143 ( V_370 , V_250 ) ;
V_371 = V_26 -> V_356 ;
F_143 ( V_371 , V_250 ) ;
if ( V_37 -> V_355 < 0 ) {
V_369 -= F_202 ( T_2 , V_373 , V_369 ) ;
V_370 += V_373 ;
V_371 += V_373 ;
} else {
V_369 += V_373 ;
V_370 -= F_202 ( T_2 , V_373 , V_370 ) ;
V_371 -= F_202 ( T_2 , V_373 , V_371 ) ;
}
if ( ( V_37 -> V_355 < 0
? ( V_371 > V_369 && V_370 < V_369 )
: ( V_371 < V_369 && V_370 > V_369 ) ) ||
F_203 ( V_377 , V_26 -> V_378 + 10 * V_379 ) ) {
F_105 ( V_26 -> V_201 ,
F_17 ( & V_26 -> V_320 ) == 0 ) ;
V_37 -> V_77 = V_26 -> V_354 ;
V_37 -> V_375 = V_365 ;
V_26 -> V_378 = V_377 ;
F_60 ( V_236 , & V_37 -> V_47 ) ;
F_20 ( V_37 -> V_38 ) ;
F_105 ( V_37 -> V_380 , V_37 -> V_47 == 0 ||
F_204 () ) ;
F_54 ( & V_26 -> V_48 ) ;
V_26 -> V_356 = V_37 -> V_77 ;
F_56 ( & V_26 -> V_48 ) ;
F_23 ( & V_26 -> V_201 ) ;
F_201 ( & V_37 -> V_376 , NULL , L_62 ) ;
}
if ( V_37 -> V_355 < 0 ) {
F_15 ( V_26 -> V_354 == 0 ) ;
V_372 = V_369 ;
F_15 ( ( V_37 -> V_381 &
~ ( ( T_2 ) V_373 - 1 ) )
- V_373 - V_372
!= V_365 ) ;
} else {
F_15 ( V_369 != V_365 + V_373 ) ;
V_372 = V_365 ;
}
F_115 ( & V_374 ) ;
for ( V_59 = 0 ; V_59 < V_373 ; V_59 += V_107 ) {
int V_305 ;
int V_382 = 0 ;
V_6 = F_53 ( V_26 , V_372 + V_59 , 0 , 0 , 1 ) ;
F_60 ( V_42 , & V_6 -> V_24 ) ;
F_37 ( & V_26 -> V_320 ) ;
for ( V_305 = V_6 -> V_9 ; V_305 -- ; ) {
T_2 V_89 ;
if ( V_305 == V_6 -> V_16 )
continue;
if ( V_26 -> V_189 == 6 &&
V_305 == V_6 -> V_8 )
continue;
V_89 = F_141 ( V_6 , V_305 , 0 ) ;
if ( V_89 < F_200 ( V_37 , 0 , 0 ) ) {
V_382 = 1 ;
continue;
}
memset ( F_205 ( V_6 -> V_62 [ V_305 ] . V_57 ) , 0 , V_121 ) ;
F_60 ( V_307 , & V_6 -> V_62 [ V_305 ] . V_47 ) ;
F_60 ( V_149 , & V_6 -> V_62 [ V_305 ] . V_47 ) ;
}
if ( ! V_382 ) {
F_60 ( V_308 , & V_6 -> V_24 ) ;
F_60 ( V_29 , & V_6 -> V_24 ) ;
}
F_124 ( & V_6 -> V_27 , & V_374 ) ;
}
F_54 ( & V_26 -> V_48 ) ;
if ( V_37 -> V_355 < 0 )
V_26 -> V_354 -= V_373 * V_368 ;
else
V_26 -> V_354 += V_373 * V_368 ;
F_56 ( & V_26 -> V_48 ) ;
V_367 =
F_142 ( V_26 , V_372 * ( V_368 ) ,
1 , & V_239 , NULL ) ;
V_348 =
F_142 ( V_26 , ( ( V_372 + V_373 )
* V_368 - 1 ) ,
1 , & V_239 , NULL ) ;
if ( V_348 >= V_37 -> V_381 )
V_348 = V_37 -> V_381 - 1 ;
while ( V_367 <= V_348 ) {
V_6 = F_53 ( V_26 , V_367 , 1 , 0 , 1 ) ;
F_60 ( V_304 , & V_6 -> V_24 ) ;
F_60 ( V_29 , & V_6 -> V_24 ) ;
F_24 ( V_6 ) ;
V_367 += V_107 ;
}
while ( ! F_16 ( & V_374 ) ) {
V_6 = F_35 ( V_374 . V_56 , struct V_5 , V_27 ) ;
F_36 ( & V_6 -> V_27 ) ;
F_24 ( V_6 ) ;
}
V_365 += V_373 ;
if ( ( V_365 - V_37 -> V_375 ) * 2
>= V_37 -> V_383 - V_37 -> V_375 ) {
F_105 ( V_26 -> V_201 ,
F_17 ( & V_26 -> V_320 ) == 0 ) ;
V_37 -> V_77 = V_26 -> V_354 ;
V_37 -> V_375 = V_365 ;
V_26 -> V_378 = V_377 ;
F_60 ( V_236 , & V_37 -> V_47 ) ;
F_20 ( V_37 -> V_38 ) ;
F_105 ( V_37 -> V_380 ,
! F_12 ( V_236 , & V_37 -> V_47 )
|| F_204 () ) ;
F_54 ( & V_26 -> V_48 ) ;
V_26 -> V_356 = V_37 -> V_77 ;
F_56 ( & V_26 -> V_48 ) ;
F_23 ( & V_26 -> V_201 ) ;
F_201 ( & V_37 -> V_376 , NULL , L_62 ) ;
}
return V_373 ;
}
static inline T_2 F_206 ( T_7 * V_37 , T_2 V_365 , int * V_366 , int V_384 )
{
T_1 * V_26 = V_37 -> V_233 ;
struct V_5 * V_6 ;
T_2 V_385 = V_37 -> V_381 ;
T_2 V_386 ;
int V_387 = 0 ;
int V_59 ;
if ( V_365 >= V_385 ) {
if ( F_12 ( V_388 , & V_37 -> V_235 ) ) {
F_207 ( V_26 ) ;
return 0 ;
}
if ( V_37 -> V_389 < V_385 )
F_208 ( V_37 -> V_277 , V_37 -> V_389 ,
& V_386 , 1 ) ;
else
V_26 -> V_390 = 0 ;
F_209 ( V_37 -> V_277 ) ;
return 0 ;
}
F_105 ( V_26 -> V_201 , V_26 -> V_85 != 2 ) ;
if ( F_12 ( V_388 , & V_37 -> V_235 ) )
return F_199 ( V_37 , V_365 , V_366 ) ;
if ( V_37 -> V_76 >= V_26 -> V_79 &&
F_12 ( V_391 , & V_37 -> V_235 ) ) {
T_2 V_392 = V_37 -> V_381 - V_365 ;
* V_366 = 1 ;
return V_392 ;
}
if ( ! F_210 ( V_37 -> V_277 , V_365 , & V_386 , 1 ) &&
! F_12 ( V_393 , & V_37 -> V_235 ) &&
! V_26 -> V_390 && V_386 >= V_107 ) {
V_386 /= V_107 ;
* V_366 = 1 ;
return V_386 * V_107 ;
}
F_211 ( V_37 -> V_277 , V_365 ) ;
V_6 = F_53 ( V_26 , V_365 , 0 , 1 , 0 ) ;
if ( V_6 == NULL ) {
V_6 = F_53 ( V_26 , V_365 , 0 , 0 , 0 ) ;
F_212 ( 1 ) ;
}
for ( V_59 = 0 ; V_59 < V_26 -> V_11 ; V_59 ++ )
if ( V_26 -> V_9 [ V_59 ] . V_80 == NULL )
V_387 = 1 ;
F_210 ( V_37 -> V_277 , V_365 , & V_386 , V_387 ) ;
F_87 ( & V_6 -> V_173 ) ;
F_60 ( V_311 , & V_6 -> V_24 ) ;
F_19 ( V_298 , & V_6 -> V_24 ) ;
F_88 ( & V_6 -> V_173 ) ;
F_166 ( V_6 ) ;
F_24 ( V_6 ) ;
return V_107 ;
}
static int F_213 ( T_1 * V_26 , struct V_1 * V_341 )
{
struct V_5 * V_6 ;
int V_239 ;
T_2 V_49 , V_347 , V_348 ;
int V_394 = 0 ;
int V_349 ;
int V_395 = 0 ;
V_347 = V_341 -> V_111 & ~ ( ( T_2 ) V_107 - 1 ) ;
V_49 = F_142 ( V_26 , V_347 ,
0 , & V_239 , NULL ) ;
V_348 = V_341 -> V_111 + ( V_341 -> V_20 >> 9 ) ;
for (; V_347 < V_348 ;
V_347 += V_107 ,
V_49 += V_107 ,
V_394 ++ ) {
if ( V_394 < F_2 ( V_341 ) )
continue;
V_6 = F_53 ( V_26 , V_49 , 0 , 1 , 0 ) ;
if ( ! V_6 ) {
F_5 ( V_341 , V_394 ) ;
V_26 -> V_45 = V_341 ;
return V_395 ;
}
F_60 ( V_227 , & V_6 -> V_62 [ V_239 ] . V_47 ) ;
if ( ! F_146 ( V_6 , V_341 , V_239 , 0 ) ) {
F_24 ( V_6 ) ;
F_5 ( V_341 , V_394 ) ;
V_26 -> V_45 = V_341 ;
return V_395 ;
}
F_166 ( V_6 ) ;
F_24 ( V_6 ) ;
V_395 ++ ;
}
F_54 ( & V_26 -> V_48 ) ;
V_349 = F_3 ( V_341 ) ;
F_56 ( & V_26 -> V_48 ) ;
if ( V_349 == 0 )
F_10 ( V_341 , 0 ) ;
if ( F_14 ( & V_26 -> V_339 ) )
F_23 ( & V_26 -> V_44 ) ;
return V_395 ;
}
static void F_214 ( T_7 * V_37 )
{
struct V_5 * V_6 ;
T_1 * V_26 = V_37 -> V_233 ;
int V_395 ;
struct V_396 V_397 ;
F_28 ( L_63 ) ;
F_215 ( V_37 ) ;
F_216 ( & V_397 ) ;
V_395 = 0 ;
F_54 ( & V_26 -> V_48 ) ;
while ( 1 ) {
struct V_1 * V_1 ;
if ( F_17 ( & V_37 -> V_398 ) == 0 &&
! F_16 ( & V_26 -> V_35 ) ) {
V_26 -> V_278 ++ ;
F_56 ( & V_26 -> V_48 ) ;
F_217 ( V_37 -> V_277 ) ;
F_54 ( & V_26 -> V_48 ) ;
V_26 -> V_34 = V_26 -> V_278 ;
F_168 ( V_26 ) ;
}
if ( F_17 ( & V_37 -> V_398 ) == 0 )
F_167 ( V_26 ) ;
while ( ( V_1 = F_177 ( V_26 ) ) ) {
int V_399 ;
F_56 ( & V_26 -> V_48 ) ;
V_399 = F_213 ( V_26 , V_1 ) ;
F_54 ( & V_26 -> V_48 ) ;
if ( ! V_399 )
break;
V_395 ++ ;
}
V_6 = F_187 ( V_26 ) ;
if ( ! V_6 )
break;
F_56 ( & V_26 -> V_48 ) ;
V_395 ++ ;
F_166 ( V_6 ) ;
F_24 ( V_6 ) ;
F_218 () ;
F_54 ( & V_26 -> V_48 ) ;
}
F_28 ( L_64 , V_395 ) ;
F_56 ( & V_26 -> V_48 ) ;
F_219 () ;
F_220 ( & V_397 ) ;
F_28 ( L_65 ) ;
}
static T_8
F_221 ( T_7 * V_37 , char * V_57 )
{
T_1 * V_26 = V_37 -> V_233 ;
if ( V_26 )
return sprintf ( V_57 , L_66 , V_26 -> V_87 ) ;
else
return 0 ;
}
int
F_222 ( T_7 * V_37 , int V_400 )
{
T_1 * V_26 = V_37 -> V_233 ;
int V_220 ;
if ( V_400 <= 16 || V_400 > 32768 )
return - V_401 ;
while ( V_400 < V_26 -> V_87 ) {
if ( F_134 ( V_26 ) )
V_26 -> V_87 -- ;
else
break;
}
V_220 = F_123 ( V_37 ) ;
if ( V_220 )
return V_220 ;
while ( V_400 > V_26 -> V_87 ) {
if ( F_108 ( V_26 ) )
V_26 -> V_87 ++ ;
else break;
}
return 0 ;
}
static T_8
F_223 ( T_7 * V_37 , const char * V_57 , T_6 V_137 )
{
T_1 * V_26 = V_37 -> V_233 ;
unsigned long V_402 ;
int V_220 ;
if ( V_137 >= V_403 )
return - V_401 ;
if ( ! V_26 )
return - V_404 ;
if ( F_224 ( V_57 , 10 , & V_402 ) )
return - V_401 ;
V_220 = F_222 ( V_37 , V_402 ) ;
if ( V_220 )
return V_220 ;
return V_137 ;
}
static T_8
F_225 ( T_7 * V_37 , char * V_57 )
{
T_1 * V_26 = V_37 -> V_233 ;
if ( V_26 )
return sprintf ( V_57 , L_66 , V_26 -> V_346 ) ;
else
return 0 ;
}
static T_8
F_226 ( T_7 * V_37 , const char * V_57 , T_6 V_137 )
{
T_1 * V_26 = V_37 -> V_233 ;
unsigned long V_402 ;
if ( V_137 >= V_403 )
return - V_401 ;
if ( ! V_26 )
return - V_404 ;
if ( F_224 ( V_57 , 10 , & V_402 ) )
return - V_401 ;
if ( V_402 > V_26 -> V_87 )
return - V_401 ;
V_26 -> V_346 = V_402 ;
return V_137 ;
}
static T_8
F_227 ( T_7 * V_37 , char * V_57 )
{
T_1 * V_26 = V_37 -> V_233 ;
if ( V_26 )
return sprintf ( V_57 , L_66 , F_17 ( & V_26 -> V_28 ) ) ;
else
return 0 ;
}
static T_2
F_200 ( T_7 * V_37 , T_2 V_405 , int V_11 )
{
T_1 * V_26 = V_37 -> V_233 ;
if ( ! V_405 )
V_405 = V_37 -> V_381 ;
if ( ! V_11 )
V_11 = F_228 ( V_26 -> V_11 , V_26 -> V_66 ) ;
V_405 &= ~ ( ( T_2 ) V_37 -> V_249 - 1 ) ;
V_405 &= ~ ( ( T_2 ) V_37 -> V_336 - 1 ) ;
return V_405 * ( V_11 - V_26 -> V_79 ) ;
}
static void F_229 ( T_1 * V_26 )
{
struct V_155 * V_156 ;
unsigned long V_190 ;
if ( ! V_26 -> V_156 )
return;
F_130 () ;
F_230 (cpu) {
V_156 = F_99 ( V_26 -> V_156 , V_190 ) ;
F_231 ( V_156 -> V_186 ) ;
F_129 ( V_156 -> V_157 ) ;
}
#ifdef F_232
F_233 ( & V_26 -> V_406 ) ;
#endif
F_133 () ;
F_234 ( V_26 -> V_156 ) ;
}
static void F_235 ( T_1 * V_26 )
{
F_135 ( V_26 ) ;
F_229 ( V_26 ) ;
F_129 ( V_26 -> V_9 ) ;
F_129 ( V_26 -> V_407 ) ;
F_129 ( V_26 ) ;
}
static int F_236 ( struct V_408 * V_409 , unsigned long V_410 ,
void * V_411 )
{
T_1 * V_26 = F_237 ( V_409 , T_1 , V_406 ) ;
long V_190 = ( long ) V_411 ;
struct V_155 * V_156 = F_99 ( V_26 -> V_156 , V_190 ) ;
switch ( V_410 ) {
case V_412 :
case V_413 :
if ( V_26 -> V_189 == 6 && ! V_156 -> V_186 )
V_156 -> V_186 = F_41 ( V_63 ) ;
if ( ! V_156 -> V_157 )
V_156 -> V_157 = F_132 ( V_26 -> F_120 , V_63 ) ;
if ( ! V_156 -> V_157 ||
( V_26 -> V_189 == 6 && ! V_156 -> V_186 ) ) {
F_231 ( V_156 -> V_186 ) ;
F_129 ( V_156 -> V_157 ) ;
F_238 ( L_67 ,
V_110 , V_190 ) ;
return F_239 ( - V_221 ) ;
}
break;
case V_414 :
case V_415 :
F_231 ( V_156 -> V_186 ) ;
F_129 ( V_156 -> V_157 ) ;
V_156 -> V_186 = NULL ;
V_156 -> V_157 = NULL ;
break;
default:
break;
}
return V_416 ;
}
static int F_240 ( T_1 * V_26 )
{
unsigned long V_190 ;
struct V_57 * V_186 ;
struct V_155 T_9 * V_417 ;
void * V_157 ;
int V_220 ;
V_417 = F_241 ( struct V_155 ) ;
if ( ! V_417 )
return - V_221 ;
V_26 -> V_156 = V_417 ;
F_130 () ;
V_220 = 0 ;
F_131 (cpu) {
if ( V_26 -> V_189 == 6 ) {
V_186 = F_41 ( V_63 ) ;
if ( ! V_186 ) {
V_220 = - V_221 ;
break;
}
F_99 ( V_26 -> V_156 , V_190 ) -> V_186 = V_186 ;
}
V_157 = F_132 ( V_26 -> F_120 , V_63 ) ;
if ( ! V_157 ) {
V_220 = - V_221 ;
break;
}
F_99 ( V_26 -> V_156 , V_190 ) -> V_157 = V_157 ;
}
#ifdef F_232
V_26 -> V_406 . V_418 = F_236 ;
V_26 -> V_406 . V_419 = 0 ;
if ( V_220 == 0 )
V_220 = F_242 ( & V_26 -> V_406 ) ;
#endif
F_133 () ;
return V_220 ;
}
static T_1 * F_243 ( T_7 * V_37 )
{
T_1 * V_26 ;
int V_420 , V_421 , V_422 ;
T_3 * V_80 ;
struct V_218 * V_10 ;
if ( V_37 -> V_423 != 5
&& V_37 -> V_423 != 4
&& V_37 -> V_423 != 6 ) {
F_44 ( V_73 L_68 ,
F_118 ( V_37 ) , V_37 -> V_423 ) ;
return F_244 ( - V_424 ) ;
}
if ( ( V_37 -> V_423 == 5
&& ! F_245 ( V_37 -> V_425 ) ) ||
( V_37 -> V_423 == 6
&& ! F_246 ( V_37 -> V_425 ) ) ) {
F_44 ( V_73 L_69 ,
F_118 ( V_37 ) , V_37 -> V_425 ) ;
return F_244 ( - V_424 ) ;
}
if ( V_37 -> V_423 == 6 && V_37 -> V_11 < 4 ) {
F_44 ( V_73 L_70 ,
F_118 ( V_37 ) , V_37 -> V_11 ) ;
return F_244 ( - V_401 ) ;
}
if ( ! V_37 -> V_336 ||
( V_37 -> V_336 << 9 ) % V_403 ||
! F_247 ( V_37 -> V_336 ) ) {
F_44 ( V_73 L_71 ,
F_118 ( V_37 ) , V_37 -> V_336 << 9 ) ;
return F_244 ( - V_401 ) ;
}
V_26 = F_128 ( sizeof( T_1 ) , V_63 ) ;
if ( V_26 == NULL )
goto abort;
F_110 ( & V_26 -> V_48 ) ;
F_112 ( & V_26 -> V_44 ) ;
F_112 ( & V_26 -> V_201 ) ;
F_115 ( & V_26 -> V_36 ) ;
F_115 ( & V_26 -> V_325 ) ;
F_115 ( & V_26 -> V_31 ) ;
F_115 ( & V_26 -> V_35 ) ;
F_115 ( & V_26 -> V_43 ) ;
F_114 ( & V_26 -> V_28 , 0 ) ;
F_114 ( & V_26 -> V_40 , 0 ) ;
F_114 ( & V_26 -> V_339 , 0 ) ;
V_26 -> V_346 = V_426 ;
V_26 -> V_11 = V_37 -> V_11 ;
if ( V_37 -> V_77 == V_78 )
V_26 -> V_66 = V_37 -> V_11 ;
else
V_26 -> V_66 = V_37 -> V_11 - V_37 -> V_355 ;
V_422 = F_117 ( V_26 -> V_11 , V_26 -> V_66 ) ;
V_26 -> F_120 = F_120 ( V_422 ) ;
V_26 -> V_9 = F_128 ( V_422 * sizeof( struct V_218 ) ,
V_63 ) ;
if ( ! V_26 -> V_9 )
goto abort;
V_26 -> V_37 = V_37 ;
if ( ( V_26 -> V_407 = F_128 ( V_403 , V_63 ) ) == NULL )
goto abort;
V_26 -> V_189 = V_37 -> V_423 ;
if ( F_240 ( V_26 ) != 0 )
goto abort;
F_28 ( L_72 , F_118 ( V_37 ) ) ;
F_127 (rdev, &mddev->disks, same_set) {
V_420 = V_80 -> V_420 ;
if ( V_420 >= V_422
|| V_420 < 0 )
continue;
V_10 = V_26 -> V_9 + V_420 ;
V_10 -> V_80 = V_80 ;
if ( F_12 ( V_82 , & V_80 -> V_47 ) ) {
char V_225 [ V_226 ] ;
F_44 ( V_228 L_73
L_74 ,
F_118 ( V_37 ) , F_137 ( V_80 -> V_106 , V_225 ) , V_420 ) ;
} else if ( V_80 -> V_427 != V_420 )
V_26 -> V_390 = 1 ;
}
V_26 -> V_249 = V_37 -> V_336 ;
V_26 -> V_189 = V_37 -> V_423 ;
if ( V_26 -> V_189 == 6 )
V_26 -> V_79 = 2 ;
else
V_26 -> V_79 = 1 ;
V_26 -> V_245 = V_37 -> V_425 ;
V_26 -> V_87 = V_428 ;
V_26 -> V_354 = V_37 -> V_77 ;
if ( V_26 -> V_354 != V_78 ) {
V_26 -> V_248 = V_37 -> V_249 ;
V_26 -> V_246 = V_37 -> V_429 ;
}
V_421 = V_26 -> V_87 * ( sizeof( struct V_5 ) +
V_422 * ( ( sizeof( struct V_1 ) + V_403 ) ) ) / 1024 ;
if ( F_116 ( V_26 , V_26 -> V_87 ) ) {
F_44 ( V_73
L_75 ,
F_118 ( V_37 ) , V_421 ) ;
goto abort;
} else
F_44 ( V_228 L_76 ,
F_118 ( V_37 ) , V_421 ) ;
V_26 -> V_38 = F_248 ( F_214 , V_37 , NULL ) ;
if ( ! V_26 -> V_38 ) {
F_44 ( V_73
L_77 ,
F_118 ( V_37 ) ) ;
goto abort;
}
return V_26 ;
abort:
if ( V_26 ) {
F_235 ( V_26 ) ;
return F_244 ( - V_424 ) ;
} else
return F_244 ( - V_221 ) ;
}
static int F_249 ( int V_420 , int V_430 , int V_11 , int V_79 )
{
switch ( V_430 ) {
case V_255 :
if ( V_420 < V_79 )
return 1 ;
break;
case V_256 :
if ( V_420 >= V_11 - V_79 )
return 1 ;
break;
case V_264 :
if ( V_420 == 0 ||
V_420 == V_11 - 1 )
return 1 ;
break;
case V_260 :
case V_261 :
case V_262 :
case V_263 :
if ( V_420 == V_11 - 1 )
return 1 ;
}
return 0 ;
}
static int F_250 ( T_7 * V_37 )
{
T_1 * V_26 ;
int V_431 = 0 ;
int V_432 = 0 ;
T_3 * V_80 ;
T_2 V_433 = 0 ;
if ( V_37 -> V_434 != V_78 )
F_44 ( V_435 L_78
L_79 ,
F_118 ( V_37 ) ) ;
if ( V_37 -> V_77 != V_78 ) {
T_2 V_436 , V_437 ;
int V_438 ;
int V_79 = ( V_37 -> V_189 == 6 ? 2 : 1 ) ;
if ( V_37 -> V_423 != V_37 -> V_189 ) {
F_44 ( V_73 L_80
L_81 ,
F_118 ( V_37 ) ) ;
return - V_401 ;
}
V_438 = V_37 -> V_11 - V_37 -> V_355 ;
V_436 = V_37 -> V_77 ;
if ( F_143 ( V_436 , V_37 -> V_336 *
( V_37 -> V_11 - V_79 ) ) ) {
F_44 ( V_73 L_82
L_83 , F_118 ( V_37 ) ) ;
return - V_401 ;
}
V_433 = V_436 * V_37 -> V_336 ;
V_437 = V_37 -> V_77 ;
F_143 ( V_437 , V_37 -> V_249 *
( V_438 - V_79 ) ) ;
if ( V_37 -> V_355 == 0 ) {
if ( ( V_436 * V_37 -> V_336 !=
V_437 * V_37 -> V_249 ) ||
V_37 -> V_319 == 0 ) {
F_44 ( V_73 L_84
L_85 ,
F_118 ( V_37 ) ) ;
return - V_401 ;
}
} else if ( V_37 -> V_355 < 0
? ( V_436 * V_37 -> V_336 <=
V_437 * V_37 -> V_249 )
: ( V_436 * V_37 -> V_336 >=
V_437 * V_37 -> V_249 ) ) {
F_44 ( V_73 L_86
L_87 ,
F_118 ( V_37 ) ) ;
return - V_401 ;
}
F_44 ( V_228 L_88 ,
F_118 ( V_37 ) ) ;
} else {
F_15 ( V_37 -> V_189 != V_37 -> V_423 ) ;
F_15 ( V_37 -> V_429 != V_37 -> V_425 ) ;
F_15 ( V_37 -> V_249 != V_37 -> V_336 ) ;
F_15 ( V_37 -> V_355 != 0 ) ;
}
if ( V_37 -> V_233 == NULL )
V_26 = F_243 ( V_37 ) ;
else
V_26 = V_37 -> V_233 ;
if ( F_251 ( V_26 ) )
return F_252 ( V_26 ) ;
V_37 -> V_38 = V_26 -> V_38 ;
V_26 -> V_38 = NULL ;
V_37 -> V_233 = V_26 ;
F_127 (rdev, &mddev->disks, same_set) {
if ( V_80 -> V_420 < 0 )
continue;
if ( F_12 ( V_82 , & V_80 -> V_47 ) ) {
V_431 ++ ;
continue;
}
if ( V_37 -> V_439 == 0 &&
V_37 -> V_440 > 90 )
V_80 -> V_316 = V_433 ;
if ( V_80 -> V_316 < V_433 ) {
if ( ! F_249 ( V_80 -> V_420 ,
V_26 -> V_245 ,
V_26 -> V_11 ,
V_26 -> V_79 ) )
continue;
}
if ( ! F_249 ( V_80 -> V_420 ,
V_26 -> V_246 ,
V_26 -> V_66 ,
V_26 -> V_79 ) )
continue;
V_432 ++ ;
}
V_37 -> V_76 = ( F_117 ( V_26 -> V_11 , V_26 -> V_66 )
- V_431 ) ;
if ( F_49 ( V_26 ) ) {
F_44 ( V_73 L_89
L_90 ,
F_118 ( V_37 ) , V_37 -> V_76 , V_26 -> V_11 ) ;
goto abort;
}
V_37 -> V_381 &= ~ ( V_37 -> V_249 - 1 ) ;
V_37 -> V_441 = V_37 -> V_381 ;
if ( V_37 -> V_76 > V_432 &&
V_37 -> V_434 != V_78 ) {
if ( V_37 -> V_442 )
F_44 ( V_232
L_91
L_92 ,
F_118 ( V_37 ) ) ;
else {
F_44 ( V_73
L_93 ,
F_118 ( V_37 ) ) ;
goto abort;
}
}
if ( V_37 -> V_76 == 0 )
F_44 ( V_228 L_94
L_95 , F_118 ( V_37 ) , V_26 -> V_189 ,
V_37 -> V_11 - V_37 -> V_76 , V_37 -> V_11 ,
V_37 -> V_425 ) ;
else
F_44 ( V_237 L_96
L_97 ,
F_118 ( V_37 ) , V_26 -> V_189 ,
V_37 -> V_11 - V_37 -> V_76 ,
V_37 -> V_11 , V_37 -> V_425 ) ;
F_253 ( V_26 ) ;
if ( V_26 -> V_354 != V_78 ) {
V_26 -> V_356 = V_26 -> V_354 ;
F_114 ( & V_26 -> V_320 , 0 ) ;
F_19 ( V_391 , & V_37 -> V_235 ) ;
F_19 ( V_301 , & V_37 -> V_235 ) ;
F_60 ( V_388 , & V_37 -> V_235 ) ;
F_60 ( V_443 , & V_37 -> V_235 ) ;
V_37 -> V_444 = F_248 ( V_445 , V_37 ,
L_98 ) ;
}
if ( V_37 -> V_446 == & V_447 )
V_37 -> V_446 = NULL ;
else if ( V_37 -> V_376 . V_448 &&
F_254 ( & V_37 -> V_376 , & V_447 ) )
F_44 ( V_232
L_99 ,
F_118 ( V_37 ) ) ;
F_255 ( V_37 , F_200 ( V_37 , 0 , 0 ) ) ;
if ( V_37 -> V_449 ) {
int V_450 ;
int V_250 = V_26 -> V_66 - V_26 -> V_79 ;
int V_240 = V_250 *
( ( V_37 -> V_249 << 9 ) / V_403 ) ;
if ( V_37 -> V_449 -> V_451 . V_452 < 2 * V_240 )
V_37 -> V_449 -> V_451 . V_452 = 2 * V_240 ;
F_256 ( V_37 -> V_449 , F_173 ) ;
V_37 -> V_449 -> V_451 . V_453 = V_37 ;
V_37 -> V_449 -> V_451 . V_454 = F_171 ;
V_450 = V_37 -> V_249 << 9 ;
F_257 ( V_37 -> V_449 , V_450 ) ;
F_258 ( V_37 -> V_449 , V_450 *
( V_26 -> V_11 - V_26 -> V_79 ) ) ;
F_127 (rdev, &mddev->disks, same_set)
F_259 ( V_37 -> V_211 , V_80 -> V_106 ,
V_80 -> V_112 << 9 ) ;
}
return 0 ;
abort:
F_260 ( V_37 -> V_38 ) ;
V_37 -> V_38 = NULL ;
if ( V_26 ) {
F_253 ( V_26 ) ;
F_235 ( V_26 ) ;
}
V_37 -> V_233 = NULL ;
F_44 ( V_237 L_100 , F_118 ( V_37 ) ) ;
return - V_424 ;
}
static int F_261 ( T_7 * V_37 )
{
T_1 * V_26 = V_37 -> V_233 ;
F_260 ( V_37 -> V_38 ) ;
V_37 -> V_38 = NULL ;
if ( V_37 -> V_449 )
V_37 -> V_449 -> V_451 . V_454 = NULL ;
F_235 ( V_26 ) ;
V_37 -> V_233 = NULL ;
V_37 -> V_446 = & V_447 ;
return 0 ;
}
static void F_262 ( struct V_455 * V_456 , struct V_5 * V_6 )
{
int V_59 ;
F_263 ( V_456 , L_101 ,
( unsigned long long ) V_6 -> V_49 , V_6 -> V_16 , V_6 -> V_24 ) ;
F_263 ( V_456 , L_102 ,
( unsigned long long ) V_6 -> V_49 , F_17 ( & V_6 -> V_13 ) ) ;
F_263 ( V_456 , L_103 , ( unsigned long long ) V_6 -> V_49 ) ;
for ( V_59 = 0 ; V_59 < V_6 -> V_9 ; V_59 ++ ) {
F_263 ( V_456 , L_104 ,
V_59 , V_6 -> V_62 [ V_59 ] . V_57 , V_6 -> V_62 [ V_59 ] . V_47 ) ;
}
F_263 ( V_456 , L_105 ) ;
}
static void F_264 ( struct V_455 * V_456 , T_1 * V_26 )
{
struct V_5 * V_6 ;
struct V_74 * V_75 ;
int V_59 ;
F_54 ( & V_26 -> V_48 ) ;
for ( V_59 = 0 ; V_59 < V_457 ; V_59 ++ ) {
F_48 (sh, hn, &conf->stripe_hashtbl[i], hash) {
if ( V_6 -> V_46 != V_26 )
continue;
F_262 ( V_456 , V_6 ) ;
}
}
F_56 ( & V_26 -> V_48 ) ;
}
static void F_265 ( struct V_455 * V_456 , T_7 * V_37 )
{
T_1 * V_26 = V_37 -> V_233 ;
int V_59 ;
F_263 ( V_456 , L_106 , V_37 -> V_189 ,
V_37 -> V_249 / 2 , V_37 -> V_429 ) ;
F_263 ( V_456 , L_107 , V_26 -> V_11 , V_26 -> V_11 - V_37 -> V_76 ) ;
for ( V_59 = 0 ; V_59 < V_26 -> V_11 ; V_59 ++ )
F_263 ( V_456 , L_108 ,
V_26 -> V_9 [ V_59 ] . V_80 &&
F_12 ( V_82 , & V_26 -> V_9 [ V_59 ] . V_80 -> V_47 ) ? L_109 : L_110 ) ;
F_263 ( V_456 , L_111 ) ;
#ifdef F_266
F_263 ( V_456 , L_105 ) ;
F_264 ( V_456 , V_26 ) ;
#endif
}
static void F_253 ( T_1 * V_26 )
{
int V_59 ;
struct V_218 * V_458 ;
F_44 ( V_459 L_112 ) ;
if ( ! V_26 ) {
F_44 ( L_113 ) ;
return;
}
F_44 ( V_459 L_114 , V_26 -> V_189 ,
V_26 -> V_11 ,
V_26 -> V_11 - V_26 -> V_37 -> V_76 ) ;
for ( V_59 = 0 ; V_59 < V_26 -> V_11 ; V_59 ++ ) {
char V_225 [ V_226 ] ;
V_458 = V_26 -> V_9 + V_59 ;
if ( V_458 -> V_80 )
F_44 ( V_459 L_115 ,
V_59 , ! F_12 ( V_81 , & V_458 -> V_80 -> V_47 ) ,
F_137 ( V_458 -> V_80 -> V_106 , V_225 ) ) ;
}
}
static int F_267 ( T_7 * V_37 )
{
int V_59 ;
T_1 * V_26 = V_37 -> V_233 ;
struct V_218 * V_458 ;
int V_13 = 0 ;
unsigned long V_47 ;
for ( V_59 = 0 ; V_59 < V_26 -> V_11 ; V_59 ++ ) {
V_458 = V_26 -> V_9 + V_59 ;
if ( V_458 -> V_80
&& V_458 -> V_80 -> V_316 == V_78
&& ! F_12 ( V_81 , & V_458 -> V_80 -> V_47 )
&& ! F_145 ( V_82 , & V_458 -> V_80 -> V_47 ) ) {
V_13 ++ ;
F_268 ( V_458 -> V_80 -> V_460 ) ;
}
}
F_25 ( & V_26 -> V_48 , V_47 ) ;
V_37 -> V_76 -= V_13 ;
F_26 ( & V_26 -> V_48 , V_47 ) ;
F_253 ( V_26 ) ;
return V_13 ;
}
static int F_269 ( T_7 * V_37 , int V_461 )
{
T_1 * V_26 = V_37 -> V_233 ;
int V_220 = 0 ;
T_3 * V_80 ;
struct V_218 * V_58 = V_26 -> V_9 + V_461 ;
F_253 ( V_26 ) ;
V_80 = V_58 -> V_80 ;
if ( V_80 ) {
if ( V_461 >= V_26 -> V_11 &&
V_26 -> V_354 == V_78 )
F_19 ( V_82 , & V_80 -> V_47 ) ;
if ( F_12 ( V_82 , & V_80 -> V_47 ) ||
F_17 ( & V_80 -> V_102 ) ) {
V_220 = - V_462 ;
goto abort;
}
if ( ! F_12 ( V_81 , & V_80 -> V_47 ) &&
! F_49 ( V_26 ) &&
V_461 < V_26 -> V_11 ) {
V_220 = - V_462 ;
goto abort;
}
V_58 -> V_80 = NULL ;
F_270 () ;
if ( F_17 ( & V_80 -> V_102 ) ) {
V_220 = - V_462 ;
V_58 -> V_80 = V_80 ;
}
}
abort:
F_253 ( V_26 ) ;
return V_220 ;
}
static int F_271 ( T_7 * V_37 , T_3 * V_80 )
{
T_1 * V_26 = V_37 -> V_233 ;
int V_220 = - V_463 ;
int V_10 ;
struct V_218 * V_58 ;
int V_54 = 0 ;
int V_464 = V_26 -> V_11 - 1 ;
if ( F_49 ( V_26 ) )
return - V_401 ;
if ( V_80 -> V_420 >= 0 )
V_54 = V_464 = V_80 -> V_420 ;
if ( V_80 -> V_427 >= 0 &&
V_80 -> V_427 >= V_54 &&
V_26 -> V_9 [ V_80 -> V_427 ] . V_80 == NULL )
V_10 = V_80 -> V_427 ;
else
V_10 = V_54 ;
for ( ; V_10 <= V_464 ; V_10 ++ )
if ( ( V_58 = V_26 -> V_9 + V_10 ) -> V_80 == NULL ) {
F_19 ( V_82 , & V_80 -> V_47 ) ;
V_80 -> V_420 = V_10 ;
V_220 = 0 ;
if ( V_80 -> V_427 != V_10 )
V_26 -> V_390 = 1 ;
F_272 ( V_58 -> V_80 , V_80 ) ;
break;
}
F_253 ( V_26 ) ;
return V_220 ;
}
static int F_273 ( T_7 * V_37 , T_2 V_405 )
{
V_405 &= ~ ( ( T_2 ) V_37 -> V_249 - 1 ) ;
F_255 ( V_37 , F_200 ( V_37 , V_405 ,
V_37 -> V_11 ) ) ;
if ( V_37 -> V_465 >
F_200 ( V_37 , V_405 , V_37 -> V_11 ) )
return - V_401 ;
F_274 ( V_37 -> V_211 , V_37 -> V_465 ) ;
F_275 ( V_37 -> V_211 ) ;
if ( V_405 > V_37 -> V_381 &&
V_37 -> V_434 > V_37 -> V_381 ) {
V_37 -> V_434 = V_37 -> V_381 ;
F_60 ( V_466 , & V_37 -> V_235 ) ;
}
V_37 -> V_381 = V_405 ;
V_37 -> V_441 = V_405 ;
return 0 ;
}
static int F_276 ( T_7 * V_37 )
{
T_1 * V_26 = V_37 -> V_233 ;
if ( ( ( V_37 -> V_249 << 9 ) / V_121 ) * 4
> V_26 -> V_87 ||
( ( V_37 -> V_336 << 9 ) / V_121 ) * 4
> V_26 -> V_87 ) {
F_44 ( V_232 L_116 ,
F_118 ( V_37 ) ,
( ( F_117 ( V_37 -> V_249 , V_37 -> V_336 ) << 9 )
/ V_121 ) * 4 ) ;
return 0 ;
}
return 1 ;
}
static int F_277 ( T_7 * V_37 )
{
T_1 * V_26 = V_37 -> V_233 ;
if ( V_37 -> V_355 == 0 &&
V_37 -> V_425 == V_37 -> V_429 &&
V_37 -> V_336 == V_37 -> V_249 )
return 0 ;
if ( V_37 -> V_277 )
return - V_462 ;
if ( F_49 ( V_26 ) )
return - V_401 ;
if ( V_37 -> V_355 < 0 ) {
int F_228 = 2 ;
if ( V_37 -> V_189 == 6 )
F_228 = 4 ;
if ( V_37 -> V_11 + V_37 -> V_355 < F_228 )
return - V_401 ;
}
if ( ! F_276 ( V_37 ) )
return - V_467 ;
return F_121 ( V_26 , V_26 -> V_11 + V_37 -> V_355 ) ;
}
static int F_278 ( T_7 * V_37 )
{
T_1 * V_26 = V_37 -> V_233 ;
T_3 * V_80 ;
int V_468 = 0 ;
unsigned long V_47 ;
if ( F_12 ( V_443 , & V_37 -> V_235 ) )
return - V_462 ;
if ( ! F_276 ( V_37 ) )
return - V_467 ;
F_127 (rdev, &mddev->disks, same_set)
if ( ! F_12 ( V_82 , & V_80 -> V_47 )
&& ! F_12 ( V_81 , & V_80 -> V_47 ) )
V_468 ++ ;
if ( V_468 - V_37 -> V_76 < V_37 -> V_355 - V_26 -> V_79 )
return - V_401 ;
if ( F_200 ( V_37 , 0 , V_26 -> V_11 + V_37 -> V_355 )
< V_37 -> V_465 ) {
F_44 ( V_73 L_117
L_118 , F_118 ( V_37 ) ) ;
return - V_401 ;
}
F_114 ( & V_26 -> V_320 , 0 ) ;
F_54 ( & V_26 -> V_48 ) ;
V_26 -> V_66 = V_26 -> V_11 ;
V_26 -> V_11 += V_37 -> V_355 ;
V_26 -> V_248 = V_26 -> V_249 ;
V_26 -> V_249 = V_37 -> V_336 ;
V_26 -> V_246 = V_26 -> V_245 ;
V_26 -> V_245 = V_37 -> V_425 ;
if ( V_37 -> V_355 < 0 )
V_26 -> V_354 = F_200 ( V_37 , 0 , 0 ) ;
else
V_26 -> V_354 = 0 ;
V_26 -> V_356 = V_26 -> V_354 ;
V_26 -> V_65 ++ ;
F_56 ( & V_26 -> V_48 ) ;
if ( V_37 -> V_355 >= 0 ) {
int V_469 = 0 ;
F_127 (rdev, &mddev->disks, same_set)
if ( V_80 -> V_420 < 0 &&
! F_12 ( V_81 , & V_80 -> V_47 ) ) {
if ( F_271 ( V_37 , V_80 ) == 0 ) {
char V_470 [ 20 ] ;
if ( V_80 -> V_420
>= V_26 -> V_66 ) {
F_60 ( V_82 , & V_80 -> V_47 ) ;
V_469 ++ ;
} else
V_80 -> V_316 = 0 ;
sprintf ( V_470 , L_119 , V_80 -> V_420 ) ;
if ( F_279 ( & V_37 -> V_376 ,
& V_80 -> V_376 , V_470 ) )
;
}
} else if ( V_80 -> V_420 >= V_26 -> V_66
&& ! F_12 ( V_81 , & V_80 -> V_47 ) ) {
F_60 ( V_82 , & V_80 -> V_47 ) ;
V_469 ++ ;
}
F_25 ( & V_26 -> V_48 , V_47 ) ;
V_37 -> V_76 += ( V_26 -> V_11 - V_26 -> V_66 )
- V_469 ;
F_26 ( & V_26 -> V_48 , V_47 ) ;
}
V_37 -> V_11 = V_26 -> V_11 ;
V_37 -> V_77 = V_26 -> V_354 ;
F_60 ( V_236 , & V_37 -> V_47 ) ;
F_19 ( V_391 , & V_37 -> V_235 ) ;
F_19 ( V_301 , & V_37 -> V_235 ) ;
F_60 ( V_388 , & V_37 -> V_235 ) ;
F_60 ( V_443 , & V_37 -> V_235 ) ;
V_37 -> V_444 = F_248 ( V_445 , V_37 ,
L_98 ) ;
if ( ! V_37 -> V_444 ) {
V_37 -> V_235 = 0 ;
F_54 ( & V_26 -> V_48 ) ;
V_37 -> V_11 = V_26 -> V_11 = V_26 -> V_66 ;
V_26 -> V_354 = V_78 ;
F_56 ( & V_26 -> V_48 ) ;
return - V_471 ;
}
V_26 -> V_378 = V_377 ;
F_20 ( V_37 -> V_444 ) ;
F_280 ( V_37 ) ;
return 0 ;
}
static void F_207 ( T_1 * V_26 )
{
if ( ! F_12 ( V_234 , & V_26 -> V_37 -> V_235 ) ) {
F_54 ( & V_26 -> V_48 ) ;
V_26 -> V_66 = V_26 -> V_11 ;
V_26 -> V_354 = V_78 ;
F_56 ( & V_26 -> V_48 ) ;
F_23 ( & V_26 -> V_201 ) ;
if ( V_26 -> V_37 -> V_449 ) {
int V_250 = V_26 -> V_11 - V_26 -> V_79 ;
int V_240 = V_250 * ( ( V_26 -> V_249 << 9 )
/ V_403 ) ;
if ( V_26 -> V_37 -> V_449 -> V_451 . V_452 < 2 * V_240 )
V_26 -> V_37 -> V_449 -> V_451 . V_452 = 2 * V_240 ;
}
}
}
static void F_281 ( T_7 * V_37 )
{
T_1 * V_26 = V_37 -> V_233 ;
if ( ! F_12 ( V_234 , & V_37 -> V_235 ) ) {
if ( V_37 -> V_355 > 0 ) {
F_255 ( V_37 , F_200 ( V_37 , 0 , 0 ) ) ;
F_274 ( V_37 -> V_211 , V_37 -> V_465 ) ;
F_275 ( V_37 -> V_211 ) ;
} else {
int V_472 ;
V_37 -> V_76 = V_26 -> V_11 ;
for ( V_472 = 0 ; V_472 < V_26 -> V_11 ; V_472 ++ )
if ( V_26 -> V_9 [ V_472 ] . V_80 &&
F_12 ( V_82 ,
& V_26 -> V_9 [ V_472 ] . V_80 -> V_47 ) )
V_37 -> V_76 -- ;
for ( V_472 = V_26 -> V_11 ;
V_472 < V_26 -> V_11 - V_37 -> V_355 ;
V_472 ++ ) {
T_3 * V_80 = V_26 -> V_9 [ V_472 ] . V_80 ;
if ( V_80 && F_269 ( V_37 , V_472 ) == 0 ) {
char V_470 [ 20 ] ;
sprintf ( V_470 , L_119 , V_80 -> V_420 ) ;
F_282 ( & V_37 -> V_376 , V_470 ) ;
V_80 -> V_420 = - 1 ;
}
}
}
V_37 -> V_429 = V_26 -> V_245 ;
V_37 -> V_249 = V_26 -> V_249 ;
V_37 -> V_77 = V_78 ;
V_37 -> V_355 = 0 ;
}
}
static void F_283 ( T_7 * V_37 , int V_24 )
{
T_1 * V_26 = V_37 -> V_233 ;
switch( V_24 ) {
case 2 :
F_23 ( & V_26 -> V_201 ) ;
break;
case 1 :
F_54 ( & V_26 -> V_48 ) ;
V_26 -> V_85 = 2 ;
F_55 ( V_26 -> V_44 ,
F_17 ( & V_26 -> V_28 ) == 0 &&
F_17 ( & V_26 -> V_339 ) == 0 ,
V_26 -> V_48 , ) ;
V_26 -> V_85 = 1 ;
F_56 ( & V_26 -> V_48 ) ;
F_23 ( & V_26 -> V_201 ) ;
break;
case 0 :
F_54 ( & V_26 -> V_48 ) ;
V_26 -> V_85 = 0 ;
F_23 ( & V_26 -> V_44 ) ;
F_23 ( & V_26 -> V_201 ) ;
F_56 ( & V_26 -> V_48 ) ;
break;
}
}
static void * F_284 ( T_7 * V_37 , int V_189 )
{
struct V_473 * V_474 = V_37 -> V_233 ;
T_2 V_405 ;
if ( V_474 -> V_475 > 1 ) {
F_44 ( V_73 L_120 ,
F_118 ( V_37 ) ) ;
return F_244 ( - V_401 ) ;
}
V_405 = V_474 -> V_476 [ 0 ] . V_477 ;
F_143 ( V_405 , V_474 -> V_476 [ 0 ] . V_478 ) ;
V_37 -> V_381 = V_405 ;
V_37 -> V_423 = V_189 ;
V_37 -> V_425 = V_256 ;
V_37 -> V_336 = V_37 -> V_249 ;
V_37 -> V_11 += 1 ;
V_37 -> V_355 = 1 ;
V_37 -> V_434 = V_78 ;
return F_243 ( V_37 ) ;
}
static void * F_285 ( T_7 * V_37 )
{
int V_479 ;
if ( V_37 -> V_11 != 2 ||
V_37 -> V_76 > 1 )
return F_244 ( - V_401 ) ;
V_479 = 64 * 2 ;
while ( V_479 && ( V_37 -> V_465 & ( V_479 - 1 ) ) )
V_479 >>= 1 ;
if ( ( V_479 << 9 ) < V_121 )
return F_244 ( - V_401 ) ;
V_37 -> V_423 = 5 ;
V_37 -> V_425 = V_253 ;
V_37 -> V_336 = V_479 ;
return F_243 ( V_37 ) ;
}
static void * F_286 ( T_7 * V_37 )
{
int V_425 ;
switch ( V_37 -> V_429 ) {
case V_260 :
V_425 = V_251 ;
break;
case V_261 :
V_425 = V_252 ;
break;
case V_262 :
V_425 = V_253 ;
break;
case V_263 :
V_425 = V_254 ;
break;
case V_264 :
V_425 = V_255 ;
break;
case V_256 :
V_425 = V_256 ;
break;
default:
return F_244 ( - V_401 ) ;
}
V_37 -> V_423 = 5 ;
V_37 -> V_425 = V_425 ;
V_37 -> V_355 = - 1 ;
V_37 -> V_11 -= 1 ;
return F_243 ( V_37 ) ;
}
static int F_287 ( T_7 * V_37 )
{
T_1 * V_26 = V_37 -> V_233 ;
int V_480 = V_37 -> V_336 ;
if ( V_37 -> V_425 >= 0 && ! F_245 ( V_37 -> V_425 ) )
return - V_401 ;
if ( V_480 > 0 ) {
if ( ! F_247 ( V_480 ) )
return - V_401 ;
if ( V_480 < ( V_403 >> 9 ) )
return - V_401 ;
if ( V_37 -> V_465 & ( V_480 - 1 ) )
return - V_401 ;
}
if ( V_37 -> V_11 == 2 ) {
if ( V_37 -> V_425 >= 0 ) {
V_26 -> V_245 = V_37 -> V_425 ;
V_37 -> V_429 = V_37 -> V_425 ;
}
if ( V_480 > 0 ) {
V_26 -> V_249 = V_480 ;
V_37 -> V_249 = V_480 ;
}
F_60 ( V_236 , & V_37 -> V_47 ) ;
F_20 ( V_37 -> V_38 ) ;
}
return F_277 ( V_37 ) ;
}
static int F_288 ( T_7 * V_37 )
{
int V_480 = V_37 -> V_336 ;
if ( V_37 -> V_425 >= 0 && ! F_246 ( V_37 -> V_425 ) )
return - V_401 ;
if ( V_480 > 0 ) {
if ( ! F_247 ( V_480 ) )
return - V_401 ;
if ( V_480 < ( V_403 >> 9 ) )
return - V_401 ;
if ( V_37 -> V_465 & ( V_480 - 1 ) )
return - V_401 ;
}
return F_277 ( V_37 ) ;
}
static void * F_289 ( T_7 * V_37 )
{
if ( V_37 -> V_189 == 0 )
return F_284 ( V_37 , 5 ) ;
if ( V_37 -> V_189 == 1 )
return F_285 ( V_37 ) ;
if ( V_37 -> V_189 == 4 ) {
V_37 -> V_425 = V_256 ;
V_37 -> V_423 = 5 ;
return F_243 ( V_37 ) ;
}
if ( V_37 -> V_189 == 6 )
return F_286 ( V_37 ) ;
return F_244 ( - V_401 ) ;
}
static void * F_290 ( T_7 * V_37 )
{
if ( V_37 -> V_189 == 0 )
return F_284 ( V_37 , 4 ) ;
if ( V_37 -> V_189 == 5 &&
V_37 -> V_429 == V_256 ) {
V_37 -> V_425 = 0 ;
V_37 -> V_423 = 4 ;
return F_243 ( V_37 ) ;
}
return F_244 ( - V_401 ) ;
}
static void * F_291 ( T_7 * V_37 )
{
int V_425 ;
if ( V_37 -> V_481 != & V_482 )
return F_244 ( - V_401 ) ;
if ( V_37 -> V_76 > 1 )
return F_244 ( - V_401 ) ;
if ( V_37 -> V_11 > 253 )
return F_244 ( - V_401 ) ;
if ( V_37 -> V_11 < 3 )
return F_244 ( - V_401 ) ;
switch ( V_37 -> V_429 ) {
case V_251 :
V_425 = V_260 ;
break;
case V_252 :
V_425 = V_261 ;
break;
case V_253 :
V_425 = V_262 ;
break;
case V_254 :
V_425 = V_263 ;
break;
case V_255 :
V_425 = V_264 ;
break;
case V_256 :
V_425 = V_256 ;
break;
default:
return F_244 ( - V_401 ) ;
}
V_37 -> V_423 = 6 ;
V_37 -> V_425 = V_425 ;
V_37 -> V_355 = 1 ;
V_37 -> V_11 += 1 ;
return F_243 ( V_37 ) ;
}
static int T_10 F_292 ( void )
{
F_293 ( & V_483 ) ;
F_293 ( & V_482 ) ;
F_293 ( & V_484 ) ;
return 0 ;
}
static void F_294 ( void )
{
F_295 ( & V_483 ) ;
F_295 ( & V_482 ) ;
F_295 ( & V_484 ) ;
}
