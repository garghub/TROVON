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
F_45 ( 1 ) ;
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
F_56 () ;
F_36 ( & V_6 -> V_27 ) ;
}
}
} while ( V_6 == NULL );
if ( V_6 )
F_37 ( & V_6 -> V_13 ) ;
F_57 ( & V_26 -> V_48 ) ;
return V_6 ;
}
static void F_58 ( struct V_5 * V_6 , struct V_88 * V_89 )
{
T_1 * V_26 = V_6 -> V_46 ;
int V_59 , V_9 = V_6 -> V_9 ;
F_59 () ;
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
while ( ( V_90 & V_94 ) && V_80 &&
F_12 ( V_103 , & V_80 -> V_47 ) ) {
T_2 V_104 ;
int V_105 ;
int V_106 = F_60 ( V_80 , V_6 -> V_49 , V_107 ,
& V_104 , & V_105 ) ;
if ( ! V_106 )
break;
if ( V_106 < 0 ) {
F_61 ( V_108 , & V_80 -> V_47 ) ;
if ( ! V_26 -> V_37 -> V_109 &&
V_26 -> V_37 -> V_47 ) {
F_62 ( V_26 -> V_37 ) ;
}
F_63 ( V_80 , V_26 -> V_37 ) ;
} else {
F_64 ( V_80 , V_26 -> V_37 ) ;
V_80 = NULL ;
}
}
if ( V_80 ) {
if ( V_89 -> V_110 || V_89 -> V_111 || V_89 -> V_112 )
F_65 ( V_80 -> V_113 , V_107 ) ;
F_61 ( V_114 , & V_6 -> V_24 ) ;
V_18 -> V_115 = V_80 -> V_113 ;
F_28 ( L_8 ,
V_116 , ( unsigned long long ) V_6 -> V_49 ,
V_18 -> V_98 , V_59 ) ;
F_37 ( & V_6 -> V_13 ) ;
V_18 -> V_117 = V_6 -> V_49 + V_80 -> V_118 ;
V_18 -> V_119 = 1 << V_120 ;
V_18 -> V_121 = 1 ;
V_18 -> V_122 = 1 ;
V_18 -> V_123 = 0 ;
V_18 -> V_124 = & V_6 -> V_62 [ V_59 ] . V_125 ;
V_18 -> V_124 [ 0 ] . V_126 = V_127 ;
V_18 -> V_124 [ 0 ] . V_128 = 0 ;
V_18 -> V_20 = V_127 ;
V_18 -> V_19 = NULL ;
F_66 ( V_18 ) ;
} else {
if ( V_90 & V_94 )
F_61 ( V_129 , & V_6 -> V_24 ) ;
F_28 ( L_9 ,
V_18 -> V_98 , V_59 , ( unsigned long long ) V_6 -> V_49 ) ;
F_19 ( V_72 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
F_61 ( V_29 , & V_6 -> V_24 ) ;
}
}
}
static struct V_130 *
F_67 ( int V_131 , struct V_1 * V_1 , struct V_57 * V_57 ,
T_2 V_49 , struct V_130 * V_132 )
{
struct V_133 * V_134 ;
struct V_57 * V_135 ;
int V_59 ;
int V_136 ;
struct V_137 V_138 ;
enum V_139 V_47 = 0 ;
if ( V_1 -> V_117 >= V_49 )
V_136 = ( signed ) ( V_1 -> V_117 - V_49 ) * 512 ;
else
V_136 = ( signed ) ( V_49 - V_1 -> V_117 ) * - 512 ;
if ( V_131 )
V_47 |= V_140 ;
F_68 ( & V_138 , V_47 , V_132 , NULL , NULL , NULL ) ;
F_69 (bvl, bio, i) {
int V_141 = V_134 -> V_126 ;
int V_142 ;
int V_143 = 0 ;
if ( V_136 < 0 ) {
V_143 = - V_136 ;
V_136 += V_143 ;
V_141 -= V_143 ;
}
if ( V_141 > 0 && V_136 + V_141 > V_127 )
V_142 = V_127 - V_136 ;
else
V_142 = V_141 ;
if ( V_142 > 0 ) {
V_143 += V_134 -> V_128 ;
V_135 = V_134 -> V_144 ;
if ( V_131 )
V_132 = F_70 ( V_57 , V_135 , V_136 ,
V_143 , V_142 , & V_138 ) ;
else
V_132 = F_70 ( V_135 , V_57 , V_143 ,
V_136 , V_142 , & V_138 ) ;
}
V_138 . V_145 = V_132 ;
if ( V_142 < V_141 )
break;
V_136 += V_141 ;
}
return V_132 ;
}
static void F_71 ( void * V_146 )
{
struct V_5 * V_6 = V_146 ;
struct V_1 * V_17 = NULL ;
T_1 * V_26 = V_6 -> V_46 ;
int V_59 ;
F_28 ( L_10 , V_116 ,
( unsigned long long ) V_6 -> V_49 ) ;
F_54 ( & V_26 -> V_48 ) ;
for ( V_59 = V_6 -> V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( F_21 ( V_147 , & V_62 -> V_47 ) ) {
struct V_1 * V_148 , * V_149 ;
F_15 ( ! V_62 -> V_69 ) ;
V_148 = V_62 -> V_69 ;
V_62 -> V_69 = NULL ;
while ( V_148 && V_148 -> V_117 <
V_62 -> V_49 + V_107 ) {
V_149 = F_72 ( V_148 , V_62 -> V_49 ) ;
if ( ! F_3 ( V_148 ) ) {
V_148 -> V_19 = V_17 ;
V_17 = V_148 ;
}
V_148 = V_149 ;
}
}
}
F_57 ( & V_26 -> V_48 ) ;
F_19 ( V_23 , & V_6 -> V_24 ) ;
F_9 ( V_17 ) ;
F_61 ( V_29 , & V_6 -> V_24 ) ;
F_24 ( V_6 ) ;
}
static void F_73 ( struct V_5 * V_6 )
{
struct V_130 * V_132 = NULL ;
T_1 * V_26 = V_6 -> V_46 ;
struct V_137 V_138 ;
int V_59 ;
F_28 ( L_10 , V_116 ,
( unsigned long long ) V_6 -> V_49 ) ;
for ( V_59 = V_6 -> V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( F_12 ( V_147 , & V_62 -> V_47 ) ) {
struct V_1 * V_148 ;
F_54 ( & V_26 -> V_48 ) ;
V_62 -> V_69 = V_148 = V_62 -> V_68 ;
V_62 -> V_68 = NULL ;
F_57 ( & V_26 -> V_48 ) ;
while ( V_148 && V_148 -> V_117 <
V_62 -> V_49 + V_107 ) {
V_132 = F_67 ( 0 , V_148 , V_62 -> V_57 ,
V_62 -> V_49 , V_132 ) ;
V_148 = F_72 ( V_148 , V_62 -> V_49 ) ;
}
}
}
F_37 ( & V_6 -> V_13 ) ;
F_68 ( & V_138 , V_150 , V_132 , F_71 , V_6 , NULL ) ;
F_74 ( & V_138 ) ;
}
static void F_75 ( struct V_5 * V_6 , int V_151 )
{
struct V_67 * V_152 ;
if ( V_151 < 0 )
return;
V_152 = & V_6 -> V_62 [ V_151 ] ;
F_61 ( V_153 , & V_152 -> V_47 ) ;
F_15 ( ! F_12 ( V_154 , & V_152 -> V_47 ) ) ;
F_19 ( V_154 , & V_152 -> V_47 ) ;
}
static void F_76 ( void * V_146 )
{
struct V_5 * V_6 = V_146 ;
F_28 ( L_10 , V_116 ,
( unsigned long long ) V_6 -> V_49 ) ;
F_75 ( V_6 , V_6 -> V_155 . V_151 ) ;
F_75 ( V_6 , V_6 -> V_155 . V_156 ) ;
F_19 ( V_25 , & V_6 -> V_24 ) ;
if ( V_6 -> V_21 == V_157 )
V_6 -> V_21 = V_158 ;
F_61 ( V_29 , & V_6 -> V_24 ) ;
F_24 ( V_6 ) ;
}
static T_4 * F_77 ( struct V_5 * V_6 ,
struct V_159 * V_160 )
{
return V_160 -> V_161 + sizeof( struct V_57 * ) * ( V_6 -> V_9 + 2 ) ;
}
static struct V_130 *
F_78 ( struct V_5 * V_6 , struct V_159 * V_160 )
{
int V_9 = V_6 -> V_9 ;
struct V_57 * * V_162 = V_160 -> V_161 ;
int V_151 = V_6 -> V_155 . V_151 ;
struct V_67 * V_152 = & V_6 -> V_62 [ V_151 ] ;
struct V_57 * V_163 = V_152 -> V_57 ;
int V_13 = 0 ;
struct V_130 * V_132 ;
struct V_137 V_138 ;
int V_59 ;
F_28 ( L_11 ,
V_116 , ( unsigned long long ) V_6 -> V_49 , V_151 ) ;
F_15 ( ! F_12 ( V_154 , & V_152 -> V_47 ) ) ;
for ( V_59 = V_9 ; V_59 -- ; )
if ( V_59 != V_151 )
V_162 [ V_13 ++ ] = V_6 -> V_62 [ V_59 ] . V_57 ;
F_37 ( & V_6 -> V_13 ) ;
F_68 ( & V_138 , V_140 | V_164 , NULL ,
F_76 , V_6 , F_77 ( V_6 , V_160 ) ) ;
if ( F_79 ( V_13 == 1 ) )
V_132 = F_70 ( V_163 , V_162 [ 0 ] , 0 , 0 , V_127 , & V_138 ) ;
else
V_132 = F_80 ( V_163 , V_162 , 0 , V_13 , V_127 , & V_138 ) ;
return V_132 ;
}
static int F_81 ( struct V_57 * * V_165 , struct V_5 * V_6 )
{
int V_9 = V_6 -> V_9 ;
int V_14 = V_6 -> V_7 ? V_9 : ( V_9 - 2 ) ;
int V_166 = F_6 ( V_6 ) ;
int V_13 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_9 ; V_59 ++ )
V_165 [ V_59 ] = NULL ;
V_13 = 0 ;
V_59 = V_166 ;
do {
int V_15 = F_8 ( V_59 , V_6 , & V_13 , V_14 ) ;
V_165 [ V_15 ] = V_6 -> V_62 [ V_59 ] . V_57 ;
V_59 = F_7 ( V_59 , V_9 ) ;
} while ( V_59 != V_166 );
return V_14 ;
}
static struct V_130 *
F_82 ( struct V_5 * V_6 , struct V_159 * V_160 )
{
int V_9 = V_6 -> V_9 ;
struct V_57 * * V_167 = V_160 -> V_161 ;
int V_151 ;
int V_8 = V_6 -> V_8 ;
struct V_130 * V_132 ;
struct V_137 V_138 ;
struct V_67 * V_152 ;
struct V_57 * V_168 ;
int V_59 ;
int V_13 ;
if ( V_6 -> V_155 . V_151 < 0 )
V_151 = V_6 -> V_155 . V_156 ;
else if ( V_6 -> V_155 . V_156 < 0 )
V_151 = V_6 -> V_155 . V_151 ;
else
F_56 () ;
F_15 ( V_151 < 0 ) ;
F_28 ( L_11 ,
V_116 , ( unsigned long long ) V_6 -> V_49 , V_151 ) ;
V_152 = & V_6 -> V_62 [ V_151 ] ;
F_15 ( ! F_12 ( V_154 , & V_152 -> V_47 ) ) ;
V_168 = V_152 -> V_57 ;
F_37 ( & V_6 -> V_13 ) ;
if ( V_151 == V_8 ) {
V_13 = F_81 ( V_167 , V_6 ) ;
V_167 [ V_13 ] = NULL ;
F_15 ( V_167 [ V_13 + 1 ] != V_168 ) ;
F_68 ( & V_138 , V_140 , NULL ,
F_76 , V_6 ,
F_77 ( V_6 , V_160 ) ) ;
V_132 = F_83 ( V_167 , 0 , V_13 + 2 , V_127 , & V_138 ) ;
} else {
V_13 = 0 ;
for ( V_59 = V_9 ; V_59 -- ; ) {
if ( V_59 == V_151 || V_59 == V_8 )
continue;
V_167 [ V_13 ++ ] = V_6 -> V_62 [ V_59 ] . V_57 ;
}
F_68 ( & V_138 , V_140 | V_164 ,
NULL , F_76 , V_6 ,
F_77 ( V_6 , V_160 ) ) ;
V_132 = F_80 ( V_168 , V_167 , 0 , V_13 , V_127 , & V_138 ) ;
}
return V_132 ;
}
static struct V_130 *
F_84 ( struct V_5 * V_6 , struct V_159 * V_160 )
{
int V_59 , V_13 , V_9 = V_6 -> V_9 ;
int V_14 = V_6 -> V_7 ? V_9 : V_9 - 2 ;
int V_166 = F_6 ( V_6 ) ;
int V_169 = - 1 , V_170 = - 1 ;
int V_151 = V_6 -> V_155 . V_151 ;
int V_156 = V_6 -> V_155 . V_156 ;
struct V_67 * V_152 = & V_6 -> V_62 [ V_151 ] ;
struct V_67 * V_171 = & V_6 -> V_62 [ V_156 ] ;
struct V_130 * V_132 ;
struct V_57 * * V_167 = V_160 -> V_161 ;
struct V_137 V_138 ;
F_28 ( L_12 ,
V_116 , ( unsigned long long ) V_6 -> V_49 , V_151 , V_156 ) ;
F_15 ( V_151 < 0 || V_156 < 0 ) ;
F_15 ( ! F_12 ( V_154 , & V_152 -> V_47 ) ) ;
F_15 ( ! F_12 ( V_154 , & V_171 -> V_47 ) ) ;
for ( V_59 = 0 ; V_59 < V_9 ; V_59 ++ )
V_167 [ V_59 ] = NULL ;
V_13 = 0 ;
V_59 = V_166 ;
do {
int V_15 = F_8 ( V_59 , V_6 , & V_13 , V_14 ) ;
V_167 [ V_15 ] = V_6 -> V_62 [ V_59 ] . V_57 ;
if ( V_59 == V_151 )
V_169 = V_15 ;
if ( V_59 == V_156 )
V_170 = V_15 ;
V_59 = F_7 ( V_59 , V_9 ) ;
} while ( V_59 != V_166 );
F_15 ( V_169 == V_170 ) ;
if ( V_170 < V_169 )
F_85 ( V_169 , V_170 ) ;
F_28 ( L_13 ,
V_116 , ( unsigned long long ) V_6 -> V_49 , V_169 , V_170 ) ;
F_37 ( & V_6 -> V_13 ) ;
if ( V_170 == V_14 + 1 ) {
if ( V_169 == V_14 ) {
F_68 ( & V_138 , V_140 , NULL ,
F_76 , V_6 ,
F_77 ( V_6 , V_160 ) ) ;
return F_83 ( V_167 , 0 , V_14 + 2 ,
V_127 , & V_138 ) ;
} else {
struct V_57 * V_168 ;
int V_172 ;
int V_8 = V_6 -> V_8 ;
if ( V_151 == V_8 )
V_172 = V_156 ;
else
V_172 = V_151 ;
V_13 = 0 ;
for ( V_59 = V_9 ; V_59 -- ; ) {
if ( V_59 == V_172 || V_59 == V_8 )
continue;
V_167 [ V_13 ++ ] = V_6 -> V_62 [ V_59 ] . V_57 ;
}
V_168 = V_6 -> V_62 [ V_172 ] . V_57 ;
F_68 ( & V_138 ,
V_140 | V_164 ,
NULL , NULL , NULL ,
F_77 ( V_6 , V_160 ) ) ;
V_132 = F_80 ( V_168 , V_167 , 0 , V_13 , V_127 ,
& V_138 ) ;
V_13 = F_81 ( V_167 , V_6 ) ;
F_68 ( & V_138 , V_140 , V_132 ,
F_76 , V_6 ,
F_77 ( V_6 , V_160 ) ) ;
return F_83 ( V_167 , 0 , V_13 + 2 ,
V_127 , & V_138 ) ;
}
} else {
F_68 ( & V_138 , V_140 , NULL ,
F_76 , V_6 ,
F_77 ( V_6 , V_160 ) ) ;
if ( V_170 == V_14 ) {
return F_86 ( V_14 + 2 ,
V_127 , V_169 ,
V_167 , & V_138 ) ;
} else {
return F_87 ( V_14 + 2 ,
V_127 , V_169 , V_170 ,
V_167 , & V_138 ) ;
}
}
}
static void F_88 ( void * V_146 )
{
struct V_5 * V_6 = V_146 ;
F_28 ( L_10 , V_116 ,
( unsigned long long ) V_6 -> V_49 ) ;
}
static struct V_130 *
F_89 ( struct V_5 * V_6 , struct V_159 * V_160 ,
struct V_130 * V_132 )
{
int V_9 = V_6 -> V_9 ;
struct V_57 * * V_162 = V_160 -> V_161 ;
int V_13 = 0 , V_16 = V_6 -> V_16 , V_59 ;
struct V_137 V_138 ;
struct V_57 * V_163 = V_162 [ V_13 ++ ] = V_6 -> V_62 [ V_16 ] . V_57 ;
F_28 ( L_10 , V_116 ,
( unsigned long long ) V_6 -> V_49 ) ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( F_12 ( V_173 , & V_62 -> V_47 ) )
V_162 [ V_13 ++ ] = V_62 -> V_57 ;
}
F_68 ( & V_138 , V_140 | V_174 , V_132 ,
F_88 , V_6 , F_77 ( V_6 , V_160 ) ) ;
V_132 = F_80 ( V_163 , V_162 , 0 , V_13 , V_127 , & V_138 ) ;
return V_132 ;
}
static struct V_130 *
F_90 ( struct V_5 * V_6 , struct V_130 * V_132 )
{
int V_9 = V_6 -> V_9 ;
int V_59 ;
F_28 ( L_10 , V_116 ,
( unsigned long long ) V_6 -> V_49 ) ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
struct V_1 * V_175 ;
if ( F_21 ( V_173 , & V_62 -> V_47 ) ) {
struct V_1 * V_176 ;
F_54 ( & V_6 -> V_46 -> V_48 ) ;
V_175 = V_62 -> V_70 ;
V_62 -> V_70 = NULL ;
F_15 ( V_62 -> V_71 ) ;
V_176 = V_62 -> V_71 = V_175 ;
F_57 ( & V_6 -> V_46 -> V_48 ) ;
while ( V_176 && V_176 -> V_117 <
V_62 -> V_49 + V_107 ) {
if ( V_176 -> V_98 & V_177 )
F_61 ( V_92 , & V_62 -> V_47 ) ;
V_132 = F_67 ( 1 , V_176 , V_62 -> V_57 ,
V_62 -> V_49 , V_132 ) ;
V_176 = F_72 ( V_176 , V_62 -> V_49 ) ;
}
}
}
return V_132 ;
}
static void F_91 ( void * V_146 )
{
struct V_5 * V_6 = V_146 ;
int V_9 = V_6 -> V_9 ;
int V_16 = V_6 -> V_16 ;
int V_8 = V_6 -> V_8 ;
int V_59 ;
bool V_178 = false ;
F_28 ( L_10 , V_116 ,
( unsigned long long ) V_6 -> V_49 ) ;
for ( V_59 = V_9 ; V_59 -- ; )
V_178 |= F_12 ( V_92 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( V_62 -> V_71 || V_59 == V_16 || V_59 == V_8 ) {
F_61 ( V_153 , & V_62 -> V_47 ) ;
if ( V_178 )
F_61 ( V_92 , & V_62 -> V_47 ) ;
}
}
if ( V_6 -> V_22 == V_179 )
V_6 -> V_22 = V_180 ;
else if ( V_6 -> V_22 == V_181 )
V_6 -> V_22 = V_182 ;
else {
F_15 ( V_6 -> V_22 != V_183 ) ;
V_6 -> V_22 = V_184 ;
}
F_61 ( V_29 , & V_6 -> V_24 ) ;
F_24 ( V_6 ) ;
}
static void
F_92 ( struct V_5 * V_6 , struct V_159 * V_160 ,
struct V_130 * V_132 )
{
int V_9 = V_6 -> V_9 ;
struct V_57 * * V_162 = V_160 -> V_161 ;
struct V_137 V_138 ;
int V_13 = 0 , V_16 = V_6 -> V_16 , V_59 ;
struct V_57 * V_163 ;
int V_185 = 0 ;
unsigned long V_47 ;
F_28 ( L_10 , V_116 ,
( unsigned long long ) V_6 -> V_49 ) ;
if ( V_6 -> V_22 == V_181 ) {
V_185 = 1 ;
V_163 = V_162 [ V_13 ++ ] = V_6 -> V_62 [ V_16 ] . V_57 ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( V_62 -> V_71 )
V_162 [ V_13 ++ ] = V_62 -> V_57 ;
}
} else {
V_163 = V_6 -> V_62 [ V_16 ] . V_57 ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( V_59 != V_16 )
V_162 [ V_13 ++ ] = V_62 -> V_57 ;
}
}
V_47 = V_150 |
( V_185 ? V_174 : V_164 ) ;
F_37 ( & V_6 -> V_13 ) ;
F_68 ( & V_138 , V_47 , V_132 , F_91 , V_6 ,
F_77 ( V_6 , V_160 ) ) ;
if ( F_79 ( V_13 == 1 ) )
V_132 = F_70 ( V_163 , V_162 [ 0 ] , 0 , 0 , V_127 , & V_138 ) ;
else
V_132 = F_80 ( V_163 , V_162 , 0 , V_13 , V_127 , & V_138 ) ;
}
static void
F_93 ( struct V_5 * V_6 , struct V_159 * V_160 ,
struct V_130 * V_132 )
{
struct V_137 V_138 ;
struct V_57 * * V_167 = V_160 -> V_161 ;
int V_13 ;
F_28 ( L_10 , V_116 , ( unsigned long long ) V_6 -> V_49 ) ;
V_13 = F_81 ( V_167 , V_6 ) ;
F_37 ( & V_6 -> V_13 ) ;
F_68 ( & V_138 , V_150 , V_132 , F_91 ,
V_6 , F_77 ( V_6 , V_160 ) ) ;
F_83 ( V_167 , 0 , V_13 + 2 , V_127 , & V_138 ) ;
}
static void F_94 ( void * V_146 )
{
struct V_5 * V_6 = V_146 ;
F_28 ( L_10 , V_116 ,
( unsigned long long ) V_6 -> V_49 ) ;
V_6 -> V_21 = V_186 ;
F_61 ( V_29 , & V_6 -> V_24 ) ;
F_24 ( V_6 ) ;
}
static void F_95 ( struct V_5 * V_6 , struct V_159 * V_160 )
{
int V_9 = V_6 -> V_9 ;
int V_16 = V_6 -> V_16 ;
int V_8 = V_6 -> V_8 ;
struct V_57 * V_163 ;
struct V_57 * * V_162 = V_160 -> V_161 ;
struct V_130 * V_132 ;
struct V_137 V_138 ;
int V_13 ;
int V_59 ;
F_28 ( L_10 , V_116 ,
( unsigned long long ) V_6 -> V_49 ) ;
V_13 = 0 ;
V_163 = V_6 -> V_62 [ V_16 ] . V_57 ;
V_162 [ V_13 ++ ] = V_163 ;
for ( V_59 = V_9 ; V_59 -- ; ) {
if ( V_59 == V_16 || V_59 == V_8 )
continue;
V_162 [ V_13 ++ ] = V_6 -> V_62 [ V_59 ] . V_57 ;
}
F_68 ( & V_138 , 0 , NULL , NULL , NULL ,
F_77 ( V_6 , V_160 ) ) ;
V_132 = F_96 ( V_163 , V_162 , 0 , V_13 , V_127 ,
& V_6 -> V_155 . V_187 , & V_138 ) ;
F_37 ( & V_6 -> V_13 ) ;
F_68 ( & V_138 , V_150 , V_132 , F_94 , V_6 , NULL ) ;
V_132 = F_74 ( & V_138 ) ;
}
static void F_97 ( struct V_5 * V_6 , struct V_159 * V_160 , int V_188 )
{
struct V_57 * * V_165 = V_160 -> V_161 ;
struct V_137 V_138 ;
int V_13 ;
F_28 ( L_14 , V_116 ,
( unsigned long long ) V_6 -> V_49 , V_188 ) ;
V_13 = F_81 ( V_165 , V_6 ) ;
if ( ! V_188 )
V_165 [ V_13 ] = NULL ;
F_37 ( & V_6 -> V_13 ) ;
F_68 ( & V_138 , V_150 , NULL , F_94 ,
V_6 , F_77 ( V_6 , V_160 ) ) ;
F_98 ( V_165 , 0 , V_13 + 2 , V_127 ,
& V_6 -> V_155 . V_187 , V_160 -> V_189 , & V_138 ) ;
}
static void F_99 ( struct V_5 * V_6 , unsigned long V_190 )
{
int V_191 = 0 , V_59 , V_9 = V_6 -> V_9 ;
struct V_130 * V_132 = NULL ;
T_1 * V_26 = V_6 -> V_46 ;
int V_192 = V_26 -> V_192 ;
struct V_159 * V_160 ;
unsigned long V_193 ;
V_193 = F_100 () ;
V_160 = F_101 ( V_26 -> V_160 , V_193 ) ;
if ( F_12 ( V_194 , & V_190 ) ) {
F_73 ( V_6 ) ;
V_191 ++ ;
}
if ( F_12 ( V_195 , & V_190 ) ) {
if ( V_192 < 6 )
V_132 = F_78 ( V_6 , V_160 ) ;
else {
if ( V_6 -> V_155 . V_156 < 0 || V_6 -> V_155 . V_151 < 0 )
V_132 = F_82 ( V_6 , V_160 ) ;
else
V_132 = F_84 ( V_6 , V_160 ) ;
}
if ( V_132 && ! F_12 ( V_196 , & V_190 ) )
F_102 ( V_132 ) ;
}
if ( F_12 ( V_197 , & V_190 ) )
V_132 = F_89 ( V_6 , V_160 , V_132 ) ;
if ( F_12 ( V_198 , & V_190 ) ) {
V_132 = F_90 ( V_6 , V_132 ) ;
V_191 ++ ;
}
if ( F_12 ( V_196 , & V_190 ) ) {
if ( V_192 < 6 )
F_92 ( V_6 , V_160 , V_132 ) ;
else
F_93 ( V_6 , V_160 , V_132 ) ;
}
if ( F_12 ( V_199 , & V_190 ) ) {
if ( V_6 -> V_21 == V_200 )
F_95 ( V_6 , V_160 ) ;
else if ( V_6 -> V_21 == V_201 )
F_97 ( V_6 , V_160 , 0 ) ;
else if ( V_6 -> V_21 == V_202 )
F_97 ( V_6 , V_160 , 1 ) ;
else
F_56 () ;
}
if ( V_191 )
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( F_21 ( V_203 , & V_62 -> V_47 ) )
F_23 ( & V_6 -> V_46 -> V_204 ) ;
}
F_103 () ;
}
static void F_104 ( void * V_205 , T_5 V_206 )
{
struct V_5 * V_6 = V_205 ;
unsigned long V_190 = V_6 -> V_155 . V_207 ;
F_105 ( V_208 , & V_6 -> V_24 ) ;
F_23 ( & V_6 -> V_155 . V_209 ) ;
F_99 ( V_6 , V_190 ) ;
F_24 ( V_6 ) ;
}
static void F_106 ( struct V_5 * V_6 , unsigned long V_190 )
{
F_107 ( V_6 -> V_155 . V_209 ,
! F_108 ( V_208 , & V_6 -> V_24 ) ) ;
V_6 -> V_155 . V_207 = V_190 ;
F_37 ( & V_6 -> V_13 ) ;
F_109 ( F_104 , V_6 ) ;
}
static int F_110 ( T_1 * V_26 )
{
struct V_5 * V_6 ;
V_6 = F_111 ( V_26 -> V_210 , V_63 ) ;
if ( ! V_6 )
return 0 ;
V_6 -> V_46 = V_26 ;
#ifdef F_112
F_113 ( & V_6 -> V_155 . V_209 ) ;
#endif
if ( F_40 ( V_6 ) ) {
F_38 ( V_6 ) ;
F_114 ( V_26 -> V_210 , V_6 ) ;
return 0 ;
}
F_115 ( & V_6 -> V_13 , 1 ) ;
F_37 ( & V_26 -> V_28 ) ;
F_116 ( & V_6 -> V_27 ) ;
F_24 ( V_6 ) ;
return 1 ;
}
static int F_117 ( T_1 * V_26 , int V_60 )
{
struct V_211 * V_212 ;
int V_213 = F_118 ( V_26 -> V_11 , V_26 -> V_66 ) ;
if ( V_26 -> V_37 -> V_214 )
sprintf ( V_26 -> V_215 [ 0 ] ,
L_15 , V_26 -> V_192 , F_119 ( V_26 -> V_37 ) ) ;
else
sprintf ( V_26 -> V_215 [ 0 ] ,
L_16 , V_26 -> V_192 , V_26 -> V_37 ) ;
sprintf ( V_26 -> V_215 [ 1 ] , L_17 , V_26 -> V_215 [ 0 ] ) ;
V_26 -> V_216 = 0 ;
V_212 = F_120 ( V_26 -> V_215 [ V_26 -> V_216 ] ,
sizeof( struct V_5 ) + ( V_213 - 1 ) * sizeof( struct V_67 ) ,
0 , 0 , NULL ) ;
if ( ! V_212 )
return 1 ;
V_26 -> V_210 = V_212 ;
V_26 -> V_61 = V_213 ;
while ( V_60 -- )
if ( ! F_110 ( V_26 ) )
return 1 ;
return 0 ;
}
static T_6 F_121 ( int V_60 )
{
T_6 V_141 ;
V_141 = sizeof( struct V_57 * ) * ( V_60 + 2 ) + sizeof( T_4 ) * ( V_60 + 2 ) ;
return V_141 ;
}
static int F_122 ( T_1 * V_26 , int V_217 )
{
struct V_5 * V_218 , * V_219 ;
F_123 ( V_220 ) ;
struct V_221 * V_222 ;
unsigned long V_193 ;
int V_223 ;
struct V_211 * V_212 ;
int V_59 ;
if ( V_217 <= V_26 -> V_61 )
return 0 ;
V_223 = F_124 ( V_26 -> V_37 ) ;
if ( V_223 )
return V_223 ;
V_212 = F_120 ( V_26 -> V_215 [ 1 - V_26 -> V_216 ] ,
sizeof( struct V_5 ) + ( V_217 - 1 ) * sizeof( struct V_67 ) ,
0 , 0 , NULL ) ;
if ( ! V_212 )
return - V_224 ;
for ( V_59 = V_26 -> V_87 ; V_59 ; V_59 -- ) {
V_219 = F_111 ( V_212 , V_63 ) ;
if ( ! V_219 )
break;
V_219 -> V_46 = V_26 ;
#ifdef F_112
F_113 ( & V_219 -> V_155 . V_209 ) ;
#endif
F_125 ( & V_219 -> V_27 , & V_220 ) ;
}
if ( V_59 ) {
while ( ! F_16 ( & V_220 ) ) {
V_219 = F_35 ( V_220 . V_56 , struct V_5 , V_27 ) ;
F_126 ( & V_219 -> V_27 ) ;
F_114 ( V_212 , V_219 ) ;
}
F_127 ( V_212 ) ;
return - V_224 ;
}
F_128 (nsh, &newstripes, lru) {
F_54 ( & V_26 -> V_48 ) ;
F_55 ( V_26 -> V_44 ,
! F_16 ( & V_26 -> V_43 ) ,
V_26 -> V_48 ,
) ;
V_218 = F_34 ( V_26 ) ;
F_57 ( & V_26 -> V_48 ) ;
F_115 ( & V_219 -> V_13 , 1 ) ;
for( V_59 = 0 ; V_59 < V_26 -> V_61 ; V_59 ++ )
V_219 -> V_62 [ V_59 ] . V_57 = V_218 -> V_62 [ V_59 ] . V_57 ;
for( ; V_59 < V_217 ; V_59 ++ )
V_219 -> V_62 [ V_59 ] . V_57 = NULL ;
F_114 ( V_26 -> V_210 , V_218 ) ;
}
F_127 ( V_26 -> V_210 ) ;
V_222 = F_129 ( V_217 * sizeof( struct V_221 ) , V_225 ) ;
if ( V_222 ) {
for ( V_59 = 0 ; V_59 < V_26 -> V_11 ; V_59 ++ )
V_222 [ V_59 ] = V_26 -> V_9 [ V_59 ] ;
F_130 ( V_26 -> V_9 ) ;
V_26 -> V_9 = V_222 ;
} else
V_223 = - V_224 ;
F_131 () ;
V_26 -> F_121 = F_121 ( V_217 ) ;
F_132 (cpu) {
struct V_159 * V_160 ;
void * V_161 ;
V_160 = F_101 ( V_26 -> V_160 , V_193 ) ;
V_161 = F_133 ( V_26 -> F_121 , V_225 ) ;
if ( V_161 ) {
F_130 ( V_160 -> V_161 ) ;
V_160 -> V_161 = V_161 ;
} else {
V_223 = - V_224 ;
break;
}
}
F_134 () ;
while( ! F_16 ( & V_220 ) ) {
V_219 = F_35 ( V_220 . V_56 , struct V_5 , V_27 ) ;
F_36 ( & V_219 -> V_27 ) ;
for ( V_59 = V_26 -> V_11 ; V_59 < V_217 ; V_59 ++ )
if ( V_219 -> V_62 [ V_59 ] . V_57 == NULL ) {
struct V_57 * V_58 = F_41 ( V_225 ) ;
V_219 -> V_62 [ V_59 ] . V_57 = V_58 ;
if ( ! V_58 )
V_223 = - V_224 ;
}
F_24 ( V_219 ) ;
}
V_26 -> V_210 = V_212 ;
V_26 -> V_216 = 1 - V_26 -> V_216 ;
V_26 -> V_61 = V_217 ;
return V_223 ;
}
static int F_135 ( T_1 * V_26 )
{
struct V_5 * V_6 ;
F_54 ( & V_26 -> V_48 ) ;
V_6 = F_34 ( V_26 ) ;
F_57 ( & V_26 -> V_48 ) ;
if ( ! V_6 )
return 0 ;
F_15 ( F_17 ( & V_6 -> V_13 ) ) ;
F_38 ( V_6 ) ;
F_114 ( V_26 -> V_210 , V_6 ) ;
F_22 ( & V_26 -> V_28 ) ;
return 1 ;
}
static void F_136 ( T_1 * V_26 )
{
while ( F_135 ( V_26 ) )
;
if ( V_26 -> V_210 )
F_127 ( V_26 -> V_210 ) ;
V_26 -> V_210 = NULL ;
}
static void V_101 ( struct V_1 * V_18 , int error )
{
struct V_5 * V_6 = V_18 -> V_226 ;
T_1 * V_26 = V_6 -> V_46 ;
int V_9 = V_6 -> V_9 , V_59 ;
int V_227 = F_12 ( V_120 , & V_18 -> V_119 ) ;
char V_228 [ V_229 ] ;
T_3 * V_80 ;
for ( V_59 = 0 ; V_59 < V_9 ; V_59 ++ )
if ( V_18 == & V_6 -> V_62 [ V_59 ] . V_97 )
break;
F_28 ( L_18 ,
( unsigned long long ) V_6 -> V_49 , V_59 , F_17 ( & V_6 -> V_13 ) ,
V_227 ) ;
if ( V_59 == V_9 ) {
F_56 () ;
return;
}
if ( V_227 ) {
F_61 ( V_153 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
if ( F_12 ( V_230 , & V_6 -> V_62 [ V_59 ] . V_47 ) ) {
V_80 = V_26 -> V_9 [ V_59 ] . V_80 ;
F_137 (
V_231
L_19
L_20 ,
F_119 ( V_26 -> V_37 ) , V_107 ,
( unsigned long long ) ( V_6 -> V_49
+ V_80 -> V_118 ) ,
F_138 ( V_80 -> V_113 , V_228 ) ) ;
F_139 ( V_107 , & V_80 -> V_232 ) ;
F_19 ( V_230 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
F_19 ( V_233 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
}
if ( F_17 ( & V_26 -> V_9 [ V_59 ] . V_80 -> V_234 ) )
F_115 ( & V_26 -> V_9 [ V_59 ] . V_80 -> V_234 , 0 ) ;
} else {
const char * V_235 = F_138 ( V_26 -> V_9 [ V_59 ] . V_80 -> V_113 , V_228 ) ;
int V_236 = 0 ;
V_80 = V_26 -> V_9 [ V_59 ] . V_80 ;
F_19 ( V_153 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
F_37 ( & V_80 -> V_234 ) ;
if ( V_26 -> V_37 -> V_76 >= V_26 -> V_79 )
F_137 (
V_237
L_21
L_22 ,
F_119 ( V_26 -> V_37 ) ,
( unsigned long long ) ( V_6 -> V_49
+ V_80 -> V_118 ) ,
V_235 ) ;
else if ( F_12 ( V_233 , & V_6 -> V_62 [ V_59 ] . V_47 ) )
F_137 (
V_237
L_23
L_22 ,
F_119 ( V_26 -> V_37 ) ,
( unsigned long long ) ( V_6 -> V_49
+ V_80 -> V_118 ) ,
V_235 ) ;
else if ( F_17 ( & V_80 -> V_234 )
> V_26 -> V_87 )
F_44 ( V_237
L_24 ,
F_119 ( V_26 -> V_37 ) , V_235 ) ;
else
V_236 = 1 ;
if ( V_236 )
F_61 ( V_230 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
else {
F_19 ( V_230 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
F_19 ( V_233 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
F_140 ( V_26 -> V_37 , V_80 ) ;
}
}
F_64 ( V_26 -> V_9 [ V_59 ] . V_80 , V_26 -> V_37 ) ;
F_19 ( V_72 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
F_61 ( V_29 , & V_6 -> V_24 ) ;
F_24 ( V_6 ) ;
}
static void V_100 ( struct V_1 * V_18 , int error )
{
struct V_5 * V_6 = V_18 -> V_226 ;
T_1 * V_26 = V_6 -> V_46 ;
int V_9 = V_6 -> V_9 , V_59 ;
int V_227 = F_12 ( V_120 , & V_18 -> V_119 ) ;
T_2 V_104 ;
int V_105 ;
for ( V_59 = 0 ; V_59 < V_9 ; V_59 ++ )
if ( V_18 == & V_6 -> V_62 [ V_59 ] . V_97 )
break;
F_28 ( L_25 ,
( unsigned long long ) V_6 -> V_49 , V_59 , F_17 ( & V_6 -> V_13 ) ,
V_227 ) ;
if ( V_59 == V_9 ) {
F_56 () ;
return;
}
if ( ! V_227 ) {
F_61 ( V_103 , & V_26 -> V_9 [ V_59 ] . V_80 -> V_47 ) ;
F_61 ( V_238 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
} else if ( F_60 ( V_26 -> V_9 [ V_59 ] . V_80 , V_6 -> V_49 , V_107 ,
& V_104 , & V_105 ) )
F_61 ( V_239 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
F_64 ( V_26 -> V_9 [ V_59 ] . V_80 , V_26 -> V_37 ) ;
F_19 ( V_72 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
F_61 ( V_29 , & V_6 -> V_24 ) ;
F_24 ( V_6 ) ;
}
static void F_46 ( struct V_5 * V_6 , int V_59 , int V_64 )
{
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
F_141 ( & V_62 -> V_97 ) ;
V_62 -> V_97 . V_124 = & V_62 -> V_125 ;
V_62 -> V_97 . V_121 ++ ;
V_62 -> V_97 . V_122 ++ ;
V_62 -> V_125 . V_144 = V_62 -> V_57 ;
V_62 -> V_125 . V_126 = V_127 ;
V_62 -> V_125 . V_128 = 0 ;
V_62 -> V_97 . V_117 = V_6 -> V_49 ;
V_62 -> V_97 . V_226 = V_6 ;
V_62 -> V_47 = 0 ;
V_62 -> V_49 = F_142 ( V_6 , V_59 , V_64 ) ;
}
static void error ( T_7 * V_37 , T_3 * V_80 )
{
char V_228 [ V_229 ] ;
T_1 * V_26 = V_37 -> V_240 ;
F_28 ( L_26 ) ;
if ( F_21 ( V_82 , & V_80 -> V_47 ) ) {
unsigned long V_47 ;
F_25 ( & V_26 -> V_48 , V_47 ) ;
V_37 -> V_76 ++ ;
F_26 ( & V_26 -> V_48 , V_47 ) ;
F_61 ( V_241 , & V_37 -> V_242 ) ;
}
F_61 ( V_243 , & V_80 -> V_47 ) ;
F_61 ( V_81 , & V_80 -> V_47 ) ;
F_61 ( V_244 , & V_37 -> V_47 ) ;
F_44 ( V_245
L_27
L_28 ,
F_119 ( V_37 ) ,
F_138 ( V_80 -> V_113 , V_228 ) ,
F_119 ( V_37 ) ,
V_26 -> V_11 - V_37 -> V_76 ) ;
}
static T_2 F_143 ( T_1 * V_26 , T_2 V_246 ,
int V_64 , int * V_247 ,
struct V_5 * V_6 )
{
T_2 V_248 , V_249 ;
T_2 V_250 ;
unsigned int V_251 ;
int V_16 , V_8 ;
int V_7 = 0 ;
T_2 V_252 ;
int V_253 = V_64 ? V_26 -> V_254
: V_26 -> V_253 ;
int V_255 = V_64 ? V_26 -> V_256
: V_26 -> V_257 ;
int V_11 = V_64 ? V_26 -> V_66
: V_26 -> V_11 ;
int V_258 = V_11 - V_26 -> V_79 ;
V_251 = F_144 ( V_246 , V_255 ) ;
V_250 = V_246 ;
V_248 = V_250 ;
* V_247 = F_144 ( V_248 , V_258 ) ;
V_249 = V_248 ;
V_16 = V_8 = - 1 ;
switch( V_26 -> V_192 ) {
case 4 :
V_16 = V_258 ;
break;
case 5 :
switch ( V_253 ) {
case V_259 :
V_16 = V_258 - F_144 ( V_249 , V_11 ) ;
if ( * V_247 >= V_16 )
( * V_247 ) ++ ;
break;
case V_260 :
V_16 = F_144 ( V_249 , V_11 ) ;
if ( * V_247 >= V_16 )
( * V_247 ) ++ ;
break;
case V_261 :
V_16 = V_258 - F_144 ( V_249 , V_11 ) ;
* V_247 = ( V_16 + 1 + * V_247 ) % V_11 ;
break;
case V_262 :
V_16 = F_144 ( V_249 , V_11 ) ;
* V_247 = ( V_16 + 1 + * V_247 ) % V_11 ;
break;
case V_263 :
V_16 = 0 ;
( * V_247 ) ++ ;
break;
case V_264 :
V_16 = V_258 ;
break;
default:
F_56 () ;
}
break;
case 6 :
switch ( V_253 ) {
case V_259 :
V_16 = V_11 - 1 - F_144 ( V_249 , V_11 ) ;
V_8 = V_16 + 1 ;
if ( V_16 == V_11 - 1 ) {
( * V_247 ) ++ ;
V_8 = 0 ;
} else if ( * V_247 >= V_16 )
( * V_247 ) += 2 ;
break;
case V_260 :
V_16 = F_144 ( V_249 , V_11 ) ;
V_8 = V_16 + 1 ;
if ( V_16 == V_11 - 1 ) {
( * V_247 ) ++ ;
V_8 = 0 ;
} else if ( * V_247 >= V_16 )
( * V_247 ) += 2 ;
break;
case V_261 :
V_16 = V_11 - 1 - F_144 ( V_249 , V_11 ) ;
V_8 = ( V_16 + 1 ) % V_11 ;
* V_247 = ( V_16 + 2 + * V_247 ) % V_11 ;
break;
case V_262 :
V_16 = F_144 ( V_249 , V_11 ) ;
V_8 = ( V_16 + 1 ) % V_11 ;
* V_247 = ( V_16 + 2 + * V_247 ) % V_11 ;
break;
case V_263 :
V_16 = 0 ;
V_8 = 1 ;
( * V_247 ) += 2 ;
break;
case V_264 :
V_16 = V_258 ;
V_8 = V_258 + 1 ;
break;
case V_265 :
V_16 = F_144 ( V_249 , V_11 ) ;
V_8 = V_16 + 1 ;
if ( V_16 == V_11 - 1 ) {
( * V_247 ) ++ ;
V_8 = 0 ;
} else if ( * V_247 >= V_16 )
( * V_247 ) += 2 ;
V_7 = 1 ;
break;
case V_266 :
V_249 += 1 ;
V_16 = V_11 - 1 - F_144 ( V_249 , V_11 ) ;
V_8 = V_16 + 1 ;
if ( V_16 == V_11 - 1 ) {
( * V_247 ) ++ ;
V_8 = 0 ;
} else if ( * V_247 >= V_16 )
( * V_247 ) += 2 ;
V_7 = 1 ;
break;
case V_267 :
V_16 = V_11 - 1 - F_144 ( V_249 , V_11 ) ;
V_8 = ( V_16 + V_11 - 1 ) % V_11 ;
* V_247 = ( V_16 + 1 + * V_247 ) % V_11 ;
V_7 = 1 ;
break;
case V_268 :
V_16 = V_258 - F_144 ( V_249 , V_11 - 1 ) ;
if ( * V_247 >= V_16 )
( * V_247 ) ++ ;
V_8 = V_11 - 1 ;
break;
case V_269 :
V_16 = F_144 ( V_249 , V_11 - 1 ) ;
if ( * V_247 >= V_16 )
( * V_247 ) ++ ;
V_8 = V_11 - 1 ;
break;
case V_270 :
V_16 = V_258 - F_144 ( V_249 , V_11 - 1 ) ;
* V_247 = ( V_16 + 1 + * V_247 ) % ( V_11 - 1 ) ;
V_8 = V_11 - 1 ;
break;
case V_271 :
V_16 = F_144 ( V_249 , V_11 - 1 ) ;
* V_247 = ( V_16 + 1 + * V_247 ) % ( V_11 - 1 ) ;
V_8 = V_11 - 1 ;
break;
case V_272 :
V_16 = 0 ;
( * V_247 ) ++ ;
V_8 = V_11 - 1 ;
break;
default:
F_56 () ;
}
break;
}
if ( V_6 ) {
V_6 -> V_16 = V_16 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_7 = V_7 ;
}
V_252 = ( T_2 ) V_248 * V_255 + V_251 ;
return V_252 ;
}
static T_2 F_142 ( struct V_5 * V_6 , int V_59 , int V_64 )
{
T_1 * V_26 = V_6 -> V_46 ;
int V_11 = V_6 -> V_9 ;
int V_258 = V_11 - V_26 -> V_79 ;
T_2 V_252 = V_6 -> V_49 , V_273 ;
int V_255 = V_64 ? V_26 -> V_256
: V_26 -> V_257 ;
int V_253 = V_64 ? V_26 -> V_254
: V_26 -> V_253 ;
T_2 V_248 ;
int V_251 ;
T_2 V_250 ;
int V_274 , V_247 = V_59 ;
T_2 V_246 ;
struct V_5 V_275 ;
V_251 = F_144 ( V_252 , V_255 ) ;
V_248 = V_252 ;
if ( V_59 == V_6 -> V_16 )
return 0 ;
switch( V_26 -> V_192 ) {
case 4 : break;
case 5 :
switch ( V_253 ) {
case V_259 :
case V_260 :
if ( V_59 > V_6 -> V_16 )
V_59 -- ;
break;
case V_261 :
case V_262 :
if ( V_59 < V_6 -> V_16 )
V_59 += V_11 ;
V_59 -= ( V_6 -> V_16 + 1 ) ;
break;
case V_263 :
V_59 -= 1 ;
break;
case V_264 :
break;
default:
F_56 () ;
}
break;
case 6 :
if ( V_59 == V_6 -> V_8 )
return 0 ;
switch ( V_253 ) {
case V_259 :
case V_260 :
case V_265 :
case V_266 :
if ( V_6 -> V_16 == V_11 - 1 )
V_59 -- ;
else if ( V_59 > V_6 -> V_16 )
V_59 -= 2 ;
break;
case V_261 :
case V_262 :
if ( V_6 -> V_16 == V_11 - 1 )
V_59 -- ;
else {
if ( V_59 < V_6 -> V_16 )
V_59 += V_11 ;
V_59 -= ( V_6 -> V_16 + 2 ) ;
}
break;
case V_263 :
V_59 -= 2 ;
break;
case V_264 :
break;
case V_267 :
if ( V_6 -> V_16 == 0 )
V_59 -- ;
else {
if ( V_59 < V_6 -> V_16 )
V_59 += V_11 ;
V_59 -= ( V_6 -> V_16 + 1 ) ;
}
break;
case V_268 :
case V_269 :
if ( V_59 > V_6 -> V_16 )
V_59 -- ;
break;
case V_270 :
case V_271 :
if ( V_59 < V_6 -> V_16 )
V_59 += V_258 + 1 ;
V_59 -= ( V_6 -> V_16 + 1 ) ;
break;
case V_272 :
V_59 -= 1 ;
break;
default:
F_56 () ;
}
break;
}
V_250 = V_248 * V_258 + V_59 ;
V_246 = V_250 * V_255 + V_251 ;
V_273 = F_143 ( V_26 , V_246 ,
V_64 , & V_274 , & V_275 ) ;
if ( V_273 != V_6 -> V_49 || V_274 != V_247 || V_275 . V_16 != V_6 -> V_16
|| V_275 . V_8 != V_6 -> V_8 ) {
F_44 ( V_73 L_29 ,
F_119 ( V_26 -> V_37 ) ) ;
return 0 ;
}
return V_246 ;
}
static void
F_145 ( struct V_5 * V_6 , struct V_88 * V_89 ,
int V_276 , int V_277 )
{
int V_59 , V_16 = V_6 -> V_16 , V_9 = V_6 -> V_9 ;
T_1 * V_26 = V_6 -> V_46 ;
int V_192 = V_26 -> V_192 ;
if ( V_276 ) {
if ( ! V_277 ) {
V_6 -> V_22 = V_179 ;
F_61 ( V_198 , & V_89 -> V_190 ) ;
} else
V_6 -> V_22 = V_183 ;
F_61 ( V_196 , & V_89 -> V_190 ) ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( V_62 -> V_70 ) {
F_61 ( V_72 , & V_62 -> V_47 ) ;
F_61 ( V_173 , & V_62 -> V_47 ) ;
if ( ! V_277 )
F_19 ( V_153 , & V_62 -> V_47 ) ;
V_89 -> V_278 ++ ;
}
}
if ( V_89 -> V_278 + V_26 -> V_79 == V_9 )
if ( ! F_146 ( V_279 , & V_6 -> V_24 ) )
F_37 ( & V_26 -> V_280 ) ;
} else {
F_15 ( V_192 == 6 ) ;
F_15 ( ! ( F_12 ( V_153 , & V_6 -> V_62 [ V_16 ] . V_47 ) ||
F_12 ( V_154 , & V_6 -> V_62 [ V_16 ] . V_47 ) ) ) ;
V_6 -> V_22 = V_181 ;
F_61 ( V_197 , & V_89 -> V_190 ) ;
F_61 ( V_198 , & V_89 -> V_190 ) ;
F_61 ( V_196 , & V_89 -> V_190 ) ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( V_59 == V_16 )
continue;
if ( V_62 -> V_70 &&
( F_12 ( V_153 , & V_62 -> V_47 ) ||
F_12 ( V_154 , & V_62 -> V_47 ) ) ) {
F_61 ( V_173 , & V_62 -> V_47 ) ;
F_61 ( V_72 , & V_62 -> V_47 ) ;
F_19 ( V_153 , & V_62 -> V_47 ) ;
V_89 -> V_278 ++ ;
}
}
}
F_61 ( V_72 , & V_6 -> V_62 [ V_16 ] . V_47 ) ;
F_19 ( V_153 , & V_6 -> V_62 [ V_16 ] . V_47 ) ;
V_89 -> V_278 ++ ;
if ( V_192 == 6 ) {
int V_8 = V_6 -> V_8 ;
struct V_67 * V_62 = & V_6 -> V_62 [ V_8 ] ;
F_61 ( V_72 , & V_62 -> V_47 ) ;
F_19 ( V_153 , & V_62 -> V_47 ) ;
V_89 -> V_278 ++ ;
}
F_28 ( L_30 ,
V_116 , ( unsigned long long ) V_6 -> V_49 ,
V_89 -> V_278 , V_89 -> V_190 ) ;
}
static int F_147 ( struct V_5 * V_6 , struct V_1 * V_18 , int V_247 , int V_281 )
{
struct V_1 * * V_282 ;
T_1 * V_26 = V_6 -> V_46 ;
int V_283 = 0 ;
F_28 ( L_31 ,
( unsigned long long ) V_18 -> V_117 ,
( unsigned long long ) V_6 -> V_49 ) ;
F_54 ( & V_26 -> V_48 ) ;
if ( V_281 ) {
V_282 = & V_6 -> V_62 [ V_247 ] . V_70 ;
if ( * V_282 == NULL && V_6 -> V_62 [ V_247 ] . V_71 == NULL )
V_283 = 1 ;
} else
V_282 = & V_6 -> V_62 [ V_247 ] . V_68 ;
while ( * V_282 && ( * V_282 ) -> V_117 < V_18 -> V_117 ) {
if ( ( * V_282 ) -> V_117 + ( ( * V_282 ) -> V_20 >> 9 ) > V_18 -> V_117 )
goto V_284;
V_282 = & ( * V_282 ) -> V_19 ;
}
if ( * V_282 && ( * V_282 ) -> V_117 < V_18 -> V_117 + ( ( V_18 -> V_20 ) >> 9 ) )
goto V_284;
F_15 ( * V_282 && V_18 -> V_19 && ( * V_282 ) != V_18 -> V_19 ) ;
if ( * V_282 )
V_18 -> V_19 = * V_282 ;
* V_282 = V_18 ;
V_18 -> V_2 ++ ;
if ( V_281 ) {
T_2 V_49 = V_6 -> V_62 [ V_247 ] . V_49 ;
for ( V_18 = V_6 -> V_62 [ V_247 ] . V_70 ;
V_49 < V_6 -> V_62 [ V_247 ] . V_49 + V_107 &&
V_18 && V_18 -> V_117 <= V_49 ;
V_18 = F_72 ( V_18 , V_6 -> V_62 [ V_247 ] . V_49 ) ) {
if ( V_18 -> V_117 + ( V_18 -> V_20 >> 9 ) >= V_49 )
V_49 = V_18 -> V_117 + ( V_18 -> V_20 >> 9 ) ;
}
if ( V_49 >= V_6 -> V_62 [ V_247 ] . V_49 + V_107 )
F_61 ( V_285 , & V_6 -> V_62 [ V_247 ] . V_47 ) ;
}
F_57 ( & V_26 -> V_48 ) ;
F_28 ( L_32 ,
( unsigned long long ) ( * V_282 ) -> V_117 ,
( unsigned long long ) V_6 -> V_49 , V_247 ) ;
if ( V_26 -> V_37 -> V_286 && V_283 ) {
F_148 ( V_26 -> V_37 -> V_286 , V_6 -> V_49 ,
V_107 , 0 ) ;
V_6 -> V_33 = V_26 -> V_287 + 1 ;
F_61 ( V_32 , & V_6 -> V_24 ) ;
}
return 1 ;
V_284:
F_61 ( V_203 , & V_6 -> V_62 [ V_247 ] . V_47 ) ;
F_57 ( & V_26 -> V_48 ) ;
return 0 ;
}
static void F_43 ( T_2 V_248 , T_1 * V_26 , int V_64 ,
struct V_5 * V_6 )
{
int V_255 =
V_64 ? V_26 -> V_256 : V_26 -> V_257 ;
int V_247 ;
int V_251 = F_144 ( V_248 , V_255 ) ;
int V_9 = V_64 ? V_26 -> V_66 : V_26 -> V_11 ;
F_143 ( V_26 ,
V_248 * ( V_9 - V_26 -> V_79 )
* V_255 + V_251 ,
V_64 ,
& V_247 , V_6 ) ;
}
static void
F_149 ( T_1 * V_26 , struct V_5 * V_6 ,
struct V_88 * V_89 , int V_9 ,
struct V_1 * * V_17 )
{
int V_59 ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_1 * V_18 ;
int V_288 = 0 ;
if ( F_12 ( V_230 , & V_6 -> V_62 [ V_59 ] . V_47 ) ) {
T_3 * V_80 ;
F_50 () ;
V_80 = F_51 ( V_26 -> V_9 [ V_59 ] . V_80 ) ;
if ( V_80 && F_12 ( V_82 , & V_80 -> V_47 ) )
F_37 ( & V_80 -> V_102 ) ;
else
V_80 = NULL ;
F_52 () ;
if ( V_80 ) {
if ( ! F_150 (
V_80 ,
V_6 -> V_49 ,
V_107 , 0 ) )
F_140 ( V_26 -> V_37 , V_80 ) ;
F_64 ( V_80 , V_26 -> V_37 ) ;
}
}
F_54 ( & V_26 -> V_48 ) ;
V_18 = V_6 -> V_62 [ V_59 ] . V_70 ;
V_6 -> V_62 [ V_59 ] . V_70 = NULL ;
if ( V_18 ) {
V_89 -> V_289 -- ;
V_288 = 1 ;
}
if ( F_21 ( V_203 , & V_6 -> V_62 [ V_59 ] . V_47 ) )
F_23 ( & V_26 -> V_204 ) ;
while ( V_18 && V_18 -> V_117 <
V_6 -> V_62 [ V_59 ] . V_49 + V_107 ) {
struct V_1 * V_290 = F_72 ( V_18 , V_6 -> V_62 [ V_59 ] . V_49 ) ;
F_19 ( V_120 , & V_18 -> V_119 ) ;
if ( ! F_3 ( V_18 ) ) {
F_151 ( V_26 -> V_37 ) ;
V_18 -> V_19 = * V_17 ;
* V_17 = V_18 ;
}
V_18 = V_290 ;
}
V_18 = V_6 -> V_62 [ V_59 ] . V_71 ;
V_6 -> V_62 [ V_59 ] . V_71 = NULL ;
if ( V_18 ) V_288 = 1 ;
while ( V_18 && V_18 -> V_117 <
V_6 -> V_62 [ V_59 ] . V_49 + V_107 ) {
struct V_1 * V_291 = F_72 ( V_18 , V_6 -> V_62 [ V_59 ] . V_49 ) ;
F_19 ( V_120 , & V_18 -> V_119 ) ;
if ( ! F_3 ( V_18 ) ) {
F_151 ( V_26 -> V_37 ) ;
V_18 -> V_19 = * V_17 ;
* V_17 = V_18 ;
}
V_18 = V_291 ;
}
if ( ! F_12 ( V_147 , & V_6 -> V_62 [ V_59 ] . V_47 ) &&
( ! F_12 ( V_292 , & V_6 -> V_62 [ V_59 ] . V_47 ) ||
F_12 ( V_230 , & V_6 -> V_62 [ V_59 ] . V_47 ) ) ) {
V_18 = V_6 -> V_62 [ V_59 ] . V_68 ;
V_6 -> V_62 [ V_59 ] . V_68 = NULL ;
if ( F_21 ( V_203 , & V_6 -> V_62 [ V_59 ] . V_47 ) )
F_23 ( & V_26 -> V_204 ) ;
if ( V_18 ) V_89 -> V_293 -- ;
while ( V_18 && V_18 -> V_117 <
V_6 -> V_62 [ V_59 ] . V_49 + V_107 ) {
struct V_1 * V_290 =
F_72 ( V_18 , V_6 -> V_62 [ V_59 ] . V_49 ) ;
F_19 ( V_120 , & V_18 -> V_119 ) ;
if ( ! F_3 ( V_18 ) ) {
V_18 -> V_19 = * V_17 ;
* V_17 = V_18 ;
}
V_18 = V_290 ;
}
}
F_57 ( & V_26 -> V_48 ) ;
if ( V_288 )
F_152 ( V_26 -> V_37 -> V_286 , V_6 -> V_49 ,
V_107 , 0 , 0 ) ;
F_19 ( V_72 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
}
if ( F_21 ( V_279 , & V_6 -> V_24 ) )
if ( F_14 ( & V_26 -> V_280 ) )
F_20 ( V_26 -> V_37 -> V_38 ) ;
}
static void
F_153 ( T_1 * V_26 , struct V_5 * V_6 ,
struct V_88 * V_89 )
{
int abort = 0 ;
int V_59 ;
F_154 ( V_26 -> V_37 , V_107 , 0 ) ;
F_19 ( V_294 , & V_6 -> V_24 ) ;
V_89 -> V_110 = 0 ;
if ( ! F_12 ( V_295 , & V_26 -> V_37 -> V_242 ) )
return;
for ( V_59 = 0 ; V_59 < V_26 -> V_11 ; V_59 ++ ) {
T_3 * V_80 = V_26 -> V_9 [ V_59 ] . V_80 ;
if ( ! V_80
|| F_12 ( V_81 , & V_80 -> V_47 )
|| F_12 ( V_82 , & V_80 -> V_47 ) )
continue;
if ( ! F_150 ( V_80 , V_6 -> V_49 ,
V_107 , 0 ) )
abort = 1 ;
}
if ( abort ) {
V_26 -> V_296 = V_26 -> V_37 -> V_296 ;
F_61 ( V_241 , & V_26 -> V_37 -> V_242 ) ;
}
}
static int F_155 ( struct V_5 * V_6 , struct V_88 * V_89 ,
int V_297 , int V_9 )
{
struct V_67 * V_62 = & V_6 -> V_62 [ V_297 ] ;
struct V_67 * V_298 [ 2 ] = { & V_6 -> V_62 [ V_89 -> V_299 [ 0 ] ] ,
& V_6 -> V_62 [ V_89 -> V_299 [ 1 ] ] } ;
if ( ! F_12 ( V_72 , & V_62 -> V_47 ) &&
! F_12 ( V_153 , & V_62 -> V_47 ) &&
( V_62 -> V_68 ||
( V_62 -> V_70 && ! F_12 ( V_285 , & V_62 -> V_47 ) ) ||
V_89 -> V_110 || V_89 -> V_111 ||
( V_89 -> V_300 >= 1 && V_298 [ 0 ] -> V_68 ) ||
( V_89 -> V_300 >= 2 && V_298 [ 1 ] -> V_68 ) ||
( V_6 -> V_46 -> V_192 <= 5 && V_89 -> V_300 && V_298 [ 0 ] -> V_70 &&
! F_12 ( V_285 , & V_298 [ 0 ] -> V_47 ) ) ||
( V_6 -> V_46 -> V_192 == 6 && V_89 -> V_300 && V_89 -> V_289 ) ) ) {
F_15 ( F_12 ( V_154 , & V_62 -> V_47 ) ) ;
F_15 ( F_12 ( V_95 , & V_62 -> V_47 ) ) ;
if ( ( V_89 -> V_227 == V_9 - 1 ) &&
( V_89 -> V_300 && ( V_297 == V_89 -> V_299 [ 0 ] ||
V_297 == V_89 -> V_299 [ 1 ] ) ) ) {
F_28 ( L_33 ,
( unsigned long long ) V_6 -> V_49 , V_297 ) ;
F_61 ( V_25 , & V_6 -> V_24 ) ;
F_61 ( V_195 , & V_89 -> V_190 ) ;
F_61 ( V_154 , & V_62 -> V_47 ) ;
V_6 -> V_155 . V_151 = V_297 ;
V_6 -> V_155 . V_156 = - 1 ;
V_89 -> V_301 = 1 ;
V_89 -> V_227 ++ ;
return 1 ;
} else if ( V_89 -> V_227 == V_9 - 2 && V_89 -> V_300 >= 2 ) {
int V_302 ;
for ( V_302 = V_9 ; V_302 -- ; ) {
if ( V_302 == V_297 )
continue;
if ( ! F_12 ( V_153 ,
& V_6 -> V_62 [ V_302 ] . V_47 ) )
break;
}
F_15 ( V_302 < 0 ) ;
F_28 ( L_34 ,
( unsigned long long ) V_6 -> V_49 ,
V_297 , V_302 ) ;
F_61 ( V_25 , & V_6 -> V_24 ) ;
F_61 ( V_195 , & V_89 -> V_190 ) ;
F_61 ( V_154 , & V_6 -> V_62 [ V_297 ] . V_47 ) ;
F_61 ( V_154 , & V_6 -> V_62 [ V_302 ] . V_47 ) ;
V_6 -> V_155 . V_151 = V_297 ;
V_6 -> V_155 . V_156 = V_302 ;
V_89 -> V_227 += 2 ;
V_89 -> V_301 = 1 ;
return 1 ;
} else if ( F_12 ( V_292 , & V_62 -> V_47 ) ) {
F_61 ( V_72 , & V_62 -> V_47 ) ;
F_61 ( V_95 , & V_62 -> V_47 ) ;
V_89 -> V_278 ++ ;
F_28 ( L_35 ,
V_297 , V_89 -> V_110 ) ;
}
}
return 0 ;
}
static void F_156 ( struct V_5 * V_6 ,
struct V_88 * V_89 ,
int V_9 )
{
int V_59 ;
if ( ! F_12 ( V_25 , & V_6 -> V_24 ) && ! V_6 -> V_21 &&
! V_6 -> V_22 )
for ( V_59 = V_9 ; V_59 -- ; )
if ( F_155 ( V_6 , V_89 , V_59 , V_9 ) )
break;
F_61 ( V_29 , & V_6 -> V_24 ) ;
}
static void F_157 ( T_1 * V_26 ,
struct V_5 * V_6 , int V_9 , struct V_1 * * V_17 )
{
int V_59 ;
struct V_67 * V_62 ;
for ( V_59 = V_9 ; V_59 -- ; )
if ( V_6 -> V_62 [ V_59 ] . V_71 ) {
V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( ! F_12 ( V_72 , & V_62 -> V_47 ) &&
F_12 ( V_153 , & V_62 -> V_47 ) ) {
struct V_1 * V_176 , * V_303 ;
int V_288 = 0 ;
F_28 ( L_36 , V_59 ) ;
F_54 ( & V_26 -> V_48 ) ;
V_176 = V_62 -> V_71 ;
V_62 -> V_71 = NULL ;
while ( V_176 && V_176 -> V_117 <
V_62 -> V_49 + V_107 ) {
V_303 = F_72 ( V_176 , V_62 -> V_49 ) ;
if ( ! F_3 ( V_176 ) ) {
F_151 ( V_26 -> V_37 ) ;
V_176 -> V_19 = * V_17 ;
* V_17 = V_176 ;
}
V_176 = V_303 ;
}
if ( V_62 -> V_70 == NULL )
V_288 = 1 ;
F_57 ( & V_26 -> V_48 ) ;
if ( V_288 )
F_152 ( V_26 -> V_37 -> V_286 ,
V_6 -> V_49 ,
V_107 ,
! F_12 ( V_129 , & V_6 -> V_24 ) ,
0 ) ;
}
}
if ( F_21 ( V_279 , & V_6 -> V_24 ) )
if ( F_14 ( & V_26 -> V_280 ) )
F_20 ( V_26 -> V_37 -> V_38 ) ;
}
static void F_158 ( T_1 * V_26 ,
struct V_5 * V_6 ,
struct V_88 * V_89 ,
int V_9 )
{
int V_304 = 0 , V_276 = 0 , V_59 ;
if ( V_26 -> V_79 == 2 ) {
V_276 = 1 ; V_304 = 2 ;
} else for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( ( V_62 -> V_70 || V_59 == V_6 -> V_16 ) &&
! F_12 ( V_72 , & V_62 -> V_47 ) &&
! ( F_12 ( V_153 , & V_62 -> V_47 ) ||
F_12 ( V_154 , & V_62 -> V_47 ) ) ) {
if ( F_12 ( V_292 , & V_62 -> V_47 ) )
V_304 ++ ;
else
V_304 += 2 * V_9 ;
}
if ( ! F_12 ( V_285 , & V_62 -> V_47 ) && V_59 != V_6 -> V_16 &&
! F_12 ( V_72 , & V_62 -> V_47 ) &&
! ( F_12 ( V_153 , & V_62 -> V_47 ) ||
F_12 ( V_154 , & V_62 -> V_47 ) ) ) {
if ( F_12 ( V_292 , & V_62 -> V_47 ) ) V_276 ++ ;
else
V_276 += 2 * V_9 ;
}
}
F_28 ( L_37 ,
( unsigned long long ) V_6 -> V_49 , V_304 , V_276 ) ;
F_61 ( V_29 , & V_6 -> V_24 ) ;
if ( V_304 < V_276 && V_304 > 0 )
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( ( V_62 -> V_70 || V_59 == V_6 -> V_16 ) &&
! F_12 ( V_72 , & V_62 -> V_47 ) &&
! ( F_12 ( V_153 , & V_62 -> V_47 ) ||
F_12 ( V_154 , & V_62 -> V_47 ) ) &&
F_12 ( V_292 , & V_62 -> V_47 ) ) {
if (
F_12 ( V_39 , & V_6 -> V_24 ) ) {
F_28 ( L_38
L_39 , V_59 ) ;
F_61 ( V_72 , & V_62 -> V_47 ) ;
F_61 ( V_95 , & V_62 -> V_47 ) ;
V_89 -> V_278 ++ ;
} else {
F_61 ( V_30 , & V_6 -> V_24 ) ;
F_61 ( V_29 , & V_6 -> V_24 ) ;
}
}
}
if ( V_276 <= V_304 && V_276 > 0 ) {
V_276 = 0 ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( ! F_12 ( V_285 , & V_62 -> V_47 ) &&
V_59 != V_6 -> V_16 && V_59 != V_6 -> V_8 &&
! F_12 ( V_72 , & V_62 -> V_47 ) &&
! ( F_12 ( V_153 , & V_62 -> V_47 ) ||
F_12 ( V_154 , & V_62 -> V_47 ) ) ) {
V_276 ++ ;
if ( ! F_12 ( V_292 , & V_62 -> V_47 ) )
continue;
if (
F_12 ( V_39 , & V_6 -> V_24 ) ) {
F_28 ( L_38
L_40 , V_59 ) ;
F_61 ( V_72 , & V_62 -> V_47 ) ;
F_61 ( V_95 , & V_62 -> V_47 ) ;
V_89 -> V_278 ++ ;
} else {
F_61 ( V_30 , & V_6 -> V_24 ) ;
F_61 ( V_29 , & V_6 -> V_24 ) ;
}
}
}
}
if ( ( V_89 -> V_301 || ! F_12 ( V_25 , & V_6 -> V_24 ) ) &&
( V_89 -> V_278 == 0 && ( V_276 == 0 || V_304 == 0 ) &&
! F_12 ( V_32 , & V_6 -> V_24 ) ) )
F_145 ( V_6 , V_89 , V_276 == 0 , 0 ) ;
}
static void F_159 ( T_1 * V_26 , struct V_5 * V_6 ,
struct V_88 * V_89 , int V_9 )
{
struct V_67 * V_62 = NULL ;
F_61 ( V_29 , & V_6 -> V_24 ) ;
switch ( V_6 -> V_21 ) {
case V_305 :
if ( V_89 -> V_300 == 0 ) {
F_15 ( V_89 -> V_227 != V_9 ) ;
V_6 -> V_21 = V_200 ;
F_61 ( V_199 , & V_89 -> V_190 ) ;
F_19 ( V_153 , & V_6 -> V_62 [ V_6 -> V_16 ] . V_47 ) ;
V_89 -> V_227 -- ;
break;
}
V_62 = & V_6 -> V_62 [ V_89 -> V_299 [ 0 ] ] ;
case V_158 :
V_6 -> V_21 = V_305 ;
if ( ! V_62 )
V_62 = & V_6 -> V_62 [ V_6 -> V_16 ] ;
if ( F_12 ( V_306 , & V_6 -> V_24 ) )
break;
F_15 ( ! F_12 ( V_153 , & V_62 -> V_47 ) ) ;
F_15 ( V_89 -> V_227 != V_9 ) ;
F_61 ( V_72 , & V_62 -> V_47 ) ;
V_89 -> V_278 ++ ;
F_61 ( V_91 , & V_62 -> V_47 ) ;
F_19 ( V_129 , & V_6 -> V_24 ) ;
F_61 ( V_306 , & V_6 -> V_24 ) ;
break;
case V_200 :
break;
case V_186 :
V_6 -> V_21 = V_305 ;
if ( V_89 -> V_300 )
break;
if ( ( V_6 -> V_155 . V_187 & V_307 ) == 0 )
F_61 ( V_306 , & V_6 -> V_24 ) ;
else {
V_26 -> V_37 -> V_308 += V_107 ;
if ( F_12 ( V_309 , & V_26 -> V_37 -> V_242 ) )
F_61 ( V_306 , & V_6 -> V_24 ) ;
else {
V_6 -> V_21 = V_157 ;
F_61 ( V_25 , & V_6 -> V_24 ) ;
F_61 ( V_195 , & V_89 -> V_190 ) ;
F_61 ( V_154 ,
& V_6 -> V_62 [ V_6 -> V_16 ] . V_47 ) ;
V_6 -> V_155 . V_151 = V_6 -> V_16 ;
V_6 -> V_155 . V_156 = - 1 ;
V_89 -> V_227 ++ ;
}
}
break;
case V_157 :
break;
default:
F_44 ( V_73 L_41 ,
V_116 , V_6 -> V_21 ,
( unsigned long long ) V_6 -> V_49 ) ;
F_56 () ;
}
}
static void F_160 ( T_1 * V_26 , struct V_5 * V_6 ,
struct V_88 * V_89 ,
int V_9 )
{
int V_16 = V_6 -> V_16 ;
int V_8 = V_6 -> V_8 ;
struct V_67 * V_62 ;
F_61 ( V_29 , & V_6 -> V_24 ) ;
F_15 ( V_89 -> V_300 > 2 ) ;
switch ( V_6 -> V_21 ) {
case V_305 :
if ( V_89 -> V_300 == V_89 -> V_310 ) {
V_6 -> V_21 = V_200 ;
}
if ( ! V_89 -> V_310 && V_89 -> V_300 < 2 ) {
if ( V_6 -> V_21 == V_200 )
V_6 -> V_21 = V_202 ;
else
V_6 -> V_21 = V_201 ;
}
V_6 -> V_155 . V_187 = 0 ;
if ( V_6 -> V_21 == V_200 ) {
F_19 ( V_153 , & V_6 -> V_62 [ V_16 ] . V_47 ) ;
V_89 -> V_227 -- ;
}
if ( V_6 -> V_21 >= V_200 &&
V_6 -> V_21 <= V_202 ) {
F_61 ( V_199 , & V_89 -> V_190 ) ;
break;
}
F_15 ( V_89 -> V_300 != 2 ) ;
case V_158 :
V_6 -> V_21 = V_305 ;
if ( F_12 ( V_306 , & V_6 -> V_24 ) )
break;
F_15 ( V_89 -> V_227 < V_9 - 1 ) ;
if ( V_89 -> V_300 == 2 ) {
V_62 = & V_6 -> V_62 [ V_89 -> V_299 [ 1 ] ] ;
V_89 -> V_278 ++ ;
F_61 ( V_72 , & V_62 -> V_47 ) ;
F_61 ( V_91 , & V_62 -> V_47 ) ;
}
if ( V_89 -> V_300 >= 1 ) {
V_62 = & V_6 -> V_62 [ V_89 -> V_299 [ 0 ] ] ;
V_89 -> V_278 ++ ;
F_61 ( V_72 , & V_62 -> V_47 ) ;
F_61 ( V_91 , & V_62 -> V_47 ) ;
}
if ( V_6 -> V_155 . V_187 & V_307 ) {
V_62 = & V_6 -> V_62 [ V_16 ] ;
V_89 -> V_278 ++ ;
F_61 ( V_72 , & V_62 -> V_47 ) ;
F_61 ( V_91 , & V_62 -> V_47 ) ;
}
if ( V_6 -> V_155 . V_187 & V_311 ) {
V_62 = & V_6 -> V_62 [ V_8 ] ;
V_89 -> V_278 ++ ;
F_61 ( V_72 , & V_62 -> V_47 ) ;
F_61 ( V_91 , & V_62 -> V_47 ) ;
}
F_19 ( V_129 , & V_6 -> V_24 ) ;
F_61 ( V_306 , & V_6 -> V_24 ) ;
break;
case V_200 :
case V_201 :
case V_202 :
break;
case V_186 :
V_6 -> V_21 = V_305 ;
if ( V_6 -> V_155 . V_187 == 0 ) {
if ( ! V_89 -> V_300 )
F_61 ( V_306 , & V_6 -> V_24 ) ;
else {
V_6 -> V_21 = V_158 ;
}
} else {
V_26 -> V_37 -> V_308 += V_107 ;
if ( F_12 ( V_309 , & V_26 -> V_37 -> V_242 ) )
F_61 ( V_306 , & V_6 -> V_24 ) ;
else {
int * V_151 = & V_6 -> V_155 . V_151 ;
V_6 -> V_155 . V_151 = - 1 ;
V_6 -> V_155 . V_156 = - 1 ;
V_6 -> V_21 = V_157 ;
F_61 ( V_25 , & V_6 -> V_24 ) ;
F_61 ( V_195 , & V_89 -> V_190 ) ;
if ( V_6 -> V_155 . V_187 & V_307 ) {
F_61 ( V_154 ,
& V_6 -> V_62 [ V_16 ] . V_47 ) ;
* V_151 = V_16 ;
V_151 = & V_6 -> V_155 . V_156 ;
V_89 -> V_227 ++ ;
}
if ( V_6 -> V_155 . V_187 & V_311 ) {
F_61 ( V_154 ,
& V_6 -> V_62 [ V_8 ] . V_47 ) ;
* V_151 = V_8 ;
V_89 -> V_227 ++ ;
}
}
}
break;
case V_157 :
break;
default:
F_44 ( V_73 L_41 ,
V_116 , V_6 -> V_21 ,
( unsigned long long ) V_6 -> V_49 ) ;
F_56 () ;
}
}
static void F_161 ( T_1 * V_26 , struct V_5 * V_6 )
{
int V_59 ;
struct V_130 * V_132 = NULL ;
F_19 ( V_312 , & V_6 -> V_24 ) ;
for ( V_59 = 0 ; V_59 < V_6 -> V_9 ; V_59 ++ )
if ( V_59 != V_6 -> V_16 && V_59 != V_6 -> V_8 ) {
int V_247 , V_313 ;
struct V_5 * V_275 ;
struct V_137 V_138 ;
T_2 V_314 = F_142 ( V_6 , V_59 , 1 ) ;
T_2 V_89 = F_143 ( V_26 , V_314 , 0 ,
& V_247 , NULL ) ;
V_275 = F_53 ( V_26 , V_89 , 0 , 1 , 1 ) ;
if ( V_275 == NULL )
continue;
if ( ! F_12 ( V_42 , & V_275 -> V_24 ) ||
F_12 ( V_315 , & V_275 -> V_62 [ V_247 ] . V_47 ) ) {
F_24 ( V_275 ) ;
continue;
}
F_68 ( & V_138 , 0 , V_132 , NULL , NULL , NULL ) ;
V_132 = F_70 ( V_275 -> V_62 [ V_247 ] . V_57 ,
V_6 -> V_62 [ V_59 ] . V_57 , 0 , 0 , V_127 ,
& V_138 ) ;
F_61 ( V_315 , & V_275 -> V_62 [ V_247 ] . V_47 ) ;
F_61 ( V_153 , & V_275 -> V_62 [ V_247 ] . V_47 ) ;
for ( V_313 = 0 ; V_313 < V_26 -> V_11 ; V_313 ++ )
if ( V_313 != V_275 -> V_16 &&
V_313 != V_275 -> V_8 &&
! F_12 ( V_315 , & V_275 -> V_62 [ V_313 ] . V_47 ) )
break;
if ( V_313 == V_26 -> V_11 ) {
F_61 ( V_316 , & V_275 -> V_24 ) ;
F_61 ( V_29 , & V_275 -> V_24 ) ;
}
F_24 ( V_275 ) ;
}
if ( V_132 ) {
F_102 ( V_132 ) ;
F_162 ( V_132 ) ;
}
}
static void F_163 ( struct V_5 * V_6 , struct V_88 * V_89 )
{
T_1 * V_26 = V_6 -> V_46 ;
int V_9 = V_6 -> V_9 ;
struct V_67 * V_62 ;
int V_59 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_110 = F_12 ( V_294 , & V_6 -> V_24 ) ;
V_89 -> V_111 = F_12 ( V_312 , & V_6 -> V_24 ) ;
V_89 -> V_112 = F_12 ( V_316 , & V_6 -> V_24 ) ;
V_89 -> V_299 [ 0 ] = - 1 ;
V_89 -> V_299 [ 1 ] = - 1 ;
F_50 () ;
F_54 ( & V_26 -> V_48 ) ;
for ( V_59 = V_9 ; V_59 -- ; ) {
T_3 * V_80 ;
T_2 V_104 ;
int V_105 ;
int V_317 = 0 ;
V_62 = & V_6 -> V_62 [ V_59 ] ;
F_28 ( L_42 ,
V_59 , V_62 -> V_47 , V_62 -> V_68 , V_62 -> V_70 , V_62 -> V_71 ) ;
if ( F_12 ( V_153 , & V_62 -> V_47 ) && V_62 -> V_68 &&
! F_12 ( V_23 , & V_6 -> V_24 ) )
F_61 ( V_147 , & V_62 -> V_47 ) ;
if ( F_12 ( V_72 , & V_62 -> V_47 ) )
V_89 -> V_278 ++ ;
if ( F_12 ( V_153 , & V_62 -> V_47 ) )
V_89 -> V_227 ++ ;
if ( F_12 ( V_154 , & V_62 -> V_47 ) ) {
V_89 -> V_318 ++ ;
F_15 ( V_89 -> V_318 > 2 ) ;
}
if ( F_12 ( V_147 , & V_62 -> V_47 ) )
V_89 -> V_319 ++ ;
else if ( V_62 -> V_68 )
V_89 -> V_293 ++ ;
if ( V_62 -> V_70 ) {
V_89 -> V_289 ++ ;
if ( ! F_12 ( V_285 , & V_62 -> V_47 ) )
V_89 -> V_320 ++ ;
}
if ( V_62 -> V_71 )
V_89 -> V_71 ++ ;
V_80 = F_51 ( V_26 -> V_9 [ V_59 ] . V_80 ) ;
if ( V_80 ) {
V_317 = F_60 ( V_80 , V_6 -> V_49 , V_107 ,
& V_104 , & V_105 ) ;
if ( V_89 -> V_321 == NULL
&& ( F_12 ( V_243 , & V_80 -> V_47 )
|| V_317 < 0 ) ) {
if ( V_317 < 0 )
F_61 ( V_108 ,
& V_80 -> V_47 ) ;
V_89 -> V_321 = V_80 ;
F_37 ( & V_80 -> V_102 ) ;
}
}
F_19 ( V_292 , & V_62 -> V_47 ) ;
if ( ! V_80 )
;
else if ( V_317 ) {
if ( ! F_12 ( V_103 , & V_80 -> V_47 ) ) {
F_61 ( V_292 , & V_62 -> V_47 ) ;
F_61 ( V_230 , & V_62 -> V_47 ) ;
}
} else if ( F_12 ( V_82 , & V_80 -> V_47 ) )
F_61 ( V_292 , & V_62 -> V_47 ) ;
else {
if ( V_6 -> V_49 + V_107 <= V_80 -> V_322 )
F_61 ( V_292 , & V_62 -> V_47 ) ;
}
if ( F_12 ( V_238 , & V_62 -> V_47 ) ) {
F_19 ( V_292 , & V_62 -> V_47 ) ;
if ( ! F_12 ( V_81 , & V_80 -> V_47 ) ) {
V_89 -> V_323 = 1 ;
F_37 ( & V_80 -> V_102 ) ;
} else
F_19 ( V_238 , & V_62 -> V_47 ) ;
}
if ( F_12 ( V_239 , & V_62 -> V_47 ) ) {
if ( ! F_12 ( V_81 , & V_80 -> V_47 ) ) {
V_89 -> V_323 = 1 ;
F_37 ( & V_80 -> V_102 ) ;
} else
F_19 ( V_239 , & V_62 -> V_47 ) ;
}
if ( ! F_12 ( V_292 , & V_62 -> V_47 ) ) {
F_19 ( V_230 , & V_62 -> V_47 ) ;
F_19 ( V_233 , & V_62 -> V_47 ) ;
}
if ( F_12 ( V_230 , & V_62 -> V_47 ) )
F_19 ( V_292 , & V_62 -> V_47 ) ;
if ( ! F_12 ( V_292 , & V_62 -> V_47 ) ) {
if ( V_89 -> V_300 < 2 )
V_89 -> V_299 [ V_89 -> V_300 ] = V_59 ;
V_89 -> V_300 ++ ;
}
}
F_57 ( & V_26 -> V_48 ) ;
F_52 () ;
}
static void F_164 ( struct V_5 * V_6 )
{
struct V_88 V_89 ;
T_1 * V_26 = V_6 -> V_46 ;
int V_59 ;
int V_185 ;
int V_9 = V_6 -> V_9 ;
struct V_67 * V_324 , * V_325 ;
F_19 ( V_29 , & V_6 -> V_24 ) ;
if ( F_146 ( V_326 , & V_6 -> V_24 ) ) {
F_61 ( V_29 , & V_6 -> V_24 ) ;
return;
}
if ( F_21 ( V_327 , & V_6 -> V_24 ) ) {
F_61 ( V_294 , & V_6 -> V_24 ) ;
F_19 ( V_306 , & V_6 -> V_24 ) ;
}
F_19 ( V_30 , & V_6 -> V_24 ) ;
F_28 ( L_43
L_44 ,
( unsigned long long ) V_6 -> V_49 , V_6 -> V_24 ,
F_17 ( & V_6 -> V_13 ) , V_6 -> V_16 , V_6 -> V_8 ,
V_6 -> V_21 , V_6 -> V_22 ) ;
F_163 ( V_6 , & V_89 ) ;
if ( V_89 . V_323 ) {
F_61 ( V_29 , & V_6 -> V_24 ) ;
goto V_328;
}
if ( F_79 ( V_89 . V_321 ) ) {
if ( V_89 . V_110 || V_89 . V_111 || V_89 . V_112 ||
V_89 . V_289 || V_89 . V_71 ) {
F_61 ( V_29 , & V_6 -> V_24 ) ;
goto V_328;
}
F_64 ( V_89 . V_321 , V_26 -> V_37 ) ;
V_89 . V_321 = NULL ;
}
if ( V_89 . V_319 && ! F_12 ( V_23 , & V_6 -> V_24 ) ) {
F_61 ( V_194 , & V_89 . V_190 ) ;
F_61 ( V_23 , & V_6 -> V_24 ) ;
}
F_28 ( L_45
L_46 ,
V_89 . V_278 , V_89 . V_227 , V_89 . V_293 , V_89 . V_289 , V_89 . V_300 ,
V_89 . V_299 [ 0 ] , V_89 . V_299 [ 1 ] ) ;
if ( V_89 . V_300 > V_26 -> V_79 && V_89 . V_293 + V_89 . V_289 + V_89 . V_71 )
F_149 ( V_26 , V_6 , & V_89 , V_9 , & V_89 . V_17 ) ;
if ( V_89 . V_300 > V_26 -> V_79 && V_89 . V_110 )
F_153 ( V_26 , V_6 , & V_89 ) ;
V_324 = & V_6 -> V_62 [ V_6 -> V_16 ] ;
V_89 . V_329 = ( V_89 . V_300 >= 1 && V_89 . V_299 [ 0 ] == V_6 -> V_16 )
|| ( V_89 . V_300 >= 2 && V_89 . V_299 [ 1 ] == V_6 -> V_16 ) ;
V_325 = & V_6 -> V_62 [ V_6 -> V_8 ] ;
V_89 . V_310 = ( V_89 . V_300 >= 1 && V_89 . V_299 [ 0 ] == V_6 -> V_8 )
|| ( V_89 . V_300 >= 2 && V_89 . V_299 [ 1 ] == V_6 -> V_8 )
|| V_26 -> V_192 < 6 ;
if ( V_89 . V_71 &&
( V_89 . V_329 || ( ( F_12 ( V_292 , & V_324 -> V_47 )
&& ! F_12 ( V_72 , & V_324 -> V_47 )
&& F_12 ( V_153 , & V_324 -> V_47 ) ) ) ) &&
( V_89 . V_310 || ( ( F_12 ( V_292 , & V_325 -> V_47 )
&& ! F_12 ( V_72 , & V_325 -> V_47 )
&& F_12 ( V_153 , & V_325 -> V_47 ) ) ) ) )
F_157 ( V_26 , V_6 , V_9 , & V_89 . V_17 ) ;
if ( V_89 . V_293 || V_89 . V_320
|| ( V_26 -> V_192 == 6 && V_89 . V_289 && V_89 . V_300 )
|| ( V_89 . V_110 && ( V_89 . V_227 + V_89 . V_318 < V_9 ) ) || V_89 . V_111 )
F_156 ( V_6 , & V_89 , V_9 ) ;
V_185 = 0 ;
if ( V_6 -> V_22 == V_182 )
V_185 = 1 ;
if ( V_6 -> V_22 == V_180 ||
V_6 -> V_22 == V_182 ) {
V_6 -> V_22 = V_330 ;
F_15 ( ! F_12 ( V_153 , & V_6 -> V_62 [ V_6 -> V_16 ] . V_47 ) ) ;
F_15 ( V_6 -> V_8 >= 0 &&
! F_12 ( V_153 , & V_6 -> V_62 [ V_6 -> V_8 ] . V_47 ) ) ;
for ( V_59 = V_9 ; V_59 -- ; ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( F_12 ( V_72 , & V_62 -> V_47 ) &&
( V_59 == V_6 -> V_16 || V_59 == V_6 -> V_8 ||
V_62 -> V_71 ) ) {
F_28 ( L_47 , V_59 ) ;
F_61 ( V_91 , & V_62 -> V_47 ) ;
if ( V_185 )
continue;
if ( ! F_12 ( V_292 , & V_62 -> V_47 ) ||
( ( V_59 == V_6 -> V_16 || V_59 == V_6 -> V_8 ) &&
V_89 . V_300 == 0 ) )
F_61 ( V_306 , & V_6 -> V_24 ) ;
}
}
if ( F_21 ( V_39 , & V_6 -> V_24 ) )
V_89 . V_331 = 1 ;
}
if ( V_89 . V_289 && ! V_6 -> V_22 && ! V_6 -> V_21 )
F_158 ( V_26 , V_6 , & V_89 , V_9 ) ;
if ( V_6 -> V_21 ||
( V_89 . V_110 && V_89 . V_278 == 0 &&
! F_12 ( V_25 , & V_6 -> V_24 ) &&
! F_12 ( V_306 , & V_6 -> V_24 ) ) ) {
if ( V_26 -> V_192 == 6 )
F_160 ( V_26 , V_6 , & V_89 , V_9 ) ;
else
F_159 ( V_26 , V_6 , & V_89 , V_9 ) ;
}
if ( V_89 . V_110 && V_89 . V_278 == 0 && F_12 ( V_306 , & V_6 -> V_24 ) ) {
F_154 ( V_26 -> V_37 , V_107 , 1 ) ;
F_19 ( V_294 , & V_6 -> V_24 ) ;
}
if ( V_89 . V_300 <= V_26 -> V_79 && ! V_26 -> V_37 -> V_332 )
for ( V_59 = 0 ; V_59 < V_89 . V_300 ; V_59 ++ ) {
struct V_67 * V_62 = & V_6 -> V_62 [ V_89 . V_299 [ V_59 ] ] ;
if ( F_12 ( V_230 , & V_62 -> V_47 )
&& ! F_12 ( V_72 , & V_62 -> V_47 )
&& F_12 ( V_153 , & V_62 -> V_47 )
) {
if ( ! F_12 ( V_233 , & V_62 -> V_47 ) ) {
F_61 ( V_91 , & V_62 -> V_47 ) ;
F_61 ( V_233 , & V_62 -> V_47 ) ;
F_61 ( V_72 , & V_62 -> V_47 ) ;
V_89 . V_278 ++ ;
} else {
F_61 ( V_95 , & V_62 -> V_47 ) ;
F_61 ( V_72 , & V_62 -> V_47 ) ;
V_89 . V_278 ++ ;
}
}
}
if ( V_6 -> V_22 == V_184 ) {
struct V_5 * V_333
= F_53 ( V_26 , V_6 -> V_49 , 1 , 1 , 1 ) ;
if ( V_333 && F_12 ( V_312 , & V_333 -> V_24 ) ) {
F_61 ( V_30 , & V_6 -> V_24 ) ;
F_61 ( V_29 , & V_6 -> V_24 ) ;
if ( ! F_146 ( V_39 ,
& V_333 -> V_24 ) )
F_37 ( & V_26 -> V_40 ) ;
F_24 ( V_333 ) ;
goto V_328;
}
if ( V_333 )
F_24 ( V_333 ) ;
V_6 -> V_22 = V_330 ;
F_19 ( V_42 , & V_6 -> V_24 ) ;
for ( V_59 = V_26 -> V_11 ; V_59 -- ; ) {
F_61 ( V_91 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
F_61 ( V_72 , & V_6 -> V_62 [ V_59 ] . V_47 ) ;
V_89 . V_278 ++ ;
}
}
if ( V_89 . V_112 && F_12 ( V_42 , & V_6 -> V_24 ) &&
! V_6 -> V_22 ) {
V_6 -> V_9 = V_26 -> V_11 ;
F_43 ( V_6 -> V_49 , V_26 , 0 , V_6 ) ;
F_145 ( V_6 , & V_89 , 1 , 1 ) ;
} else if ( V_89 . V_112 && ! V_6 -> V_22 && V_89 . V_278 == 0 ) {
F_19 ( V_316 , & V_6 -> V_24 ) ;
F_22 ( & V_26 -> V_334 ) ;
F_23 ( & V_26 -> V_204 ) ;
F_154 ( V_26 -> V_37 , V_107 , 1 ) ;
}
if ( V_89 . V_111 && V_89 . V_278 == 0 &&
! F_12 ( V_25 , & V_6 -> V_24 ) )
F_161 ( V_26 , V_6 ) ;
V_328:
if ( V_26 -> V_37 -> V_109 && F_79 ( V_89 . V_321 ) )
F_63 ( V_89 . V_321 , V_26 -> V_37 ) ;
if ( V_89 . V_323 )
for ( V_59 = V_9 ; V_59 -- ; ) {
T_3 * V_80 ;
struct V_67 * V_62 = & V_6 -> V_62 [ V_59 ] ;
if ( F_21 ( V_238 , & V_62 -> V_47 ) ) {
V_80 = V_26 -> V_9 [ V_59 ] . V_80 ;
if ( ! F_150 ( V_80 , V_6 -> V_49 ,
V_107 , 0 ) )
F_140 ( V_26 -> V_37 , V_80 ) ;
F_64 ( V_80 , V_26 -> V_37 ) ;
}
if ( F_21 ( V_239 , & V_62 -> V_47 ) ) {
V_80 = V_26 -> V_9 [ V_59 ] . V_80 ;
F_165 ( V_80 , V_6 -> V_49 ,
V_107 ) ;
F_64 ( V_80 , V_26 -> V_37 ) ;
}
}
if ( V_89 . V_190 )
F_106 ( V_6 , V_89 . V_190 ) ;
F_58 ( V_6 , & V_89 ) ;
if ( V_89 . V_331 ) {
F_22 ( & V_26 -> V_40 ) ;
if ( F_17 ( & V_26 -> V_40 ) <
V_41 )
F_20 ( V_26 -> V_37 -> V_38 ) ;
}
F_9 ( V_89 . V_17 ) ;
F_19 ( V_326 , & V_6 -> V_24 ) ;
}
static void F_166 ( T_1 * V_26 )
{
if ( F_17 ( & V_26 -> V_40 ) < V_41 ) {
while ( ! F_16 ( & V_26 -> V_31 ) ) {
struct V_53 * V_335 = V_26 -> V_31 . V_56 ;
struct V_5 * V_6 ;
V_6 = F_35 ( V_335 , struct V_5 , V_27 ) ;
F_36 ( V_335 ) ;
F_19 ( V_30 , & V_6 -> V_24 ) ;
if ( ! F_146 ( V_39 , & V_6 -> V_24 ) )
F_37 ( & V_26 -> V_40 ) ;
F_18 ( & V_6 -> V_27 , & V_26 -> V_336 ) ;
}
}
}
static void F_167 ( T_1 * V_26 )
{
struct V_53 V_337 ;
F_125 ( & V_337 , & V_26 -> V_35 ) ;
F_36 ( & V_26 -> V_35 ) ;
while ( ! F_16 ( & V_337 ) ) {
struct V_5 * V_6 = F_35 ( V_337 . V_56 , struct V_5 , V_27 ) ;
F_36 ( & V_6 -> V_27 ) ;
F_37 ( & V_6 -> V_13 ) ;
F_13 ( V_26 , V_6 ) ;
}
}
int F_168 ( T_7 * V_37 , int V_338 )
{
T_1 * V_26 = V_37 -> V_240 ;
if ( V_26 -> V_86 )
return 1 ;
if ( V_26 -> V_85 )
return 1 ;
if ( F_169 ( & V_26 -> V_43 ) )
return 1 ;
return 0 ;
}
static int F_170 ( void * V_339 , int V_338 )
{
T_7 * V_37 = V_339 ;
return F_171 ( V_37 , V_338 ) ||
F_168 ( V_37 , V_338 ) ;
}
static int F_172 ( struct V_340 * V_341 ,
struct V_342 * V_343 ,
struct V_133 * V_344 )
{
T_7 * V_37 = V_341 -> V_345 ;
T_2 V_49 = V_343 -> V_117 + F_173 ( V_343 -> V_115 ) ;
int F_118 ;
unsigned int V_257 = V_37 -> V_257 ;
unsigned int V_346 = V_343 -> V_20 >> 9 ;
if ( ( V_343 -> V_98 & 1 ) == V_94 )
return V_344 -> V_126 ;
if ( V_37 -> V_347 < V_37 -> V_257 )
V_257 = V_37 -> V_347 ;
F_118 = ( V_257 - ( ( V_49 & ( V_257 - 1 ) ) + V_346 ) ) << 9 ;
if ( F_118 < 0 ) F_118 = 0 ;
if ( F_118 <= V_344 -> V_126 && V_346 == 0 )
return V_344 -> V_126 ;
else
return F_118 ;
}
static int F_174 ( T_7 * V_37 , struct V_1 * V_1 )
{
T_2 V_49 = V_1 -> V_117 + F_173 ( V_1 -> V_115 ) ;
unsigned int V_257 = V_37 -> V_257 ;
unsigned int V_346 = V_1 -> V_20 >> 9 ;
if ( V_37 -> V_347 < V_37 -> V_257 )
V_257 = V_37 -> V_347 ;
return V_257 >=
( ( V_49 & ( V_257 - 1 ) ) + V_346 ) ;
}
static void F_175 ( struct V_1 * V_18 , T_1 * V_26 )
{
unsigned long V_47 ;
F_25 ( & V_26 -> V_48 , V_47 ) ;
V_18 -> V_19 = V_26 -> V_348 ;
V_26 -> V_348 = V_18 ;
F_26 ( & V_26 -> V_48 , V_47 ) ;
F_20 ( V_26 -> V_37 -> V_38 ) ;
}
static struct V_1 * F_176 ( T_1 * V_26 )
{
struct V_1 * V_18 ;
V_18 = V_26 -> V_45 ;
if ( V_18 ) {
V_26 -> V_45 = NULL ;
return V_18 ;
}
V_18 = V_26 -> V_348 ;
if( V_18 ) {
V_26 -> V_348 = V_18 -> V_19 ;
V_18 -> V_19 = NULL ;
V_18 -> V_2 = 1 ;
}
return V_18 ;
}
static void F_177 ( struct V_1 * V_18 , int error )
{
struct V_1 * V_349 = V_18 -> V_226 ;
T_7 * V_37 ;
T_1 * V_26 ;
int V_227 = F_12 ( V_120 , & V_18 -> V_119 ) ;
T_3 * V_80 ;
F_178 ( V_18 ) ;
V_80 = ( void * ) V_349 -> V_19 ;
V_349 -> V_19 = NULL ;
V_37 = V_80 -> V_37 ;
V_26 = V_37 -> V_240 ;
F_64 ( V_80 , V_26 -> V_37 ) ;
if ( ! error && V_227 ) {
F_10 ( V_349 , 0 ) ;
if ( F_14 ( & V_26 -> V_350 ) )
F_23 ( & V_26 -> V_44 ) ;
return;
}
F_28 ( L_48 ) ;
F_175 ( V_349 , V_26 ) ;
}
static int F_179 ( struct V_1 * V_18 )
{
struct V_340 * V_341 = F_180 ( V_18 -> V_115 ) ;
if ( ( V_18 -> V_20 >> 9 ) > F_181 ( V_341 ) )
return 0 ;
F_182 ( V_341 , V_18 ) ;
if ( V_18 -> V_2 > F_183 ( V_341 ) )
return 0 ;
if ( V_341 -> V_351 )
return 0 ;
return 1 ;
}
static int F_184 ( T_7 * V_37 , struct V_1 * V_352 )
{
T_1 * V_26 = V_37 -> V_240 ;
int V_247 ;
struct V_1 * V_353 ;
T_3 * V_80 ;
if ( ! F_174 ( V_37 , V_352 ) ) {
F_28 ( L_49 ) ;
return 0 ;
}
V_353 = F_185 ( V_352 , V_225 , V_37 ) ;
if ( ! V_353 )
return 0 ;
V_353 -> V_99 = F_177 ;
V_353 -> V_226 = V_352 ;
V_353 -> V_117 = F_143 ( V_26 , V_352 -> V_117 ,
0 ,
& V_247 , NULL ) ;
F_50 () ;
V_80 = F_51 ( V_26 -> V_9 [ V_247 ] . V_80 ) ;
if ( V_80 && F_12 ( V_82 , & V_80 -> V_47 ) ) {
T_2 V_104 ;
int V_105 ;
F_37 ( & V_80 -> V_102 ) ;
F_52 () ;
V_352 -> V_19 = ( void * ) V_80 ;
V_353 -> V_115 = V_80 -> V_113 ;
V_353 -> V_119 &= ~ ( 1 << V_354 ) ;
V_353 -> V_117 += V_80 -> V_118 ;
if ( ! F_179 ( V_353 ) ||
F_60 ( V_80 , V_353 -> V_117 , V_353 -> V_20 >> 9 ,
& V_104 , & V_105 ) ) {
F_178 ( V_353 ) ;
F_64 ( V_80 , V_37 ) ;
return 0 ;
}
F_54 ( & V_26 -> V_48 ) ;
F_55 ( V_26 -> V_44 ,
V_26 -> V_85 == 0 ,
V_26 -> V_48 , ) ;
F_37 ( & V_26 -> V_350 ) ;
F_57 ( & V_26 -> V_48 ) ;
F_66 ( V_353 ) ;
return 1 ;
} else {
F_52 () ;
F_178 ( V_353 ) ;
return 0 ;
}
}
static struct V_5 * F_186 ( T_1 * V_26 )
{
struct V_5 * V_6 ;
F_28 ( L_50 ,
V_116 ,
F_16 ( & V_26 -> V_36 ) ? L_51 : L_52 ,
F_16 ( & V_26 -> V_336 ) ? L_51 : L_52 ,
F_17 ( & V_26 -> V_280 ) , V_26 -> V_355 ) ;
if ( ! F_16 ( & V_26 -> V_36 ) ) {
V_6 = F_35 ( V_26 -> V_36 . V_56 , F_187 ( * V_6 ) , V_27 ) ;
if ( F_16 ( & V_26 -> V_336 ) )
V_26 -> V_355 = 0 ;
else if ( ! F_12 ( V_114 , & V_6 -> V_24 ) ) {
if ( V_26 -> V_336 . V_56 == V_26 -> V_356 )
V_26 -> V_355 ++ ;
else {
V_26 -> V_356 = V_26 -> V_336 . V_56 ;
V_26 -> V_355 -= V_26 -> V_357 ;
if ( V_26 -> V_355 < 0 )
V_26 -> V_355 = 0 ;
}
}
} else if ( ! F_16 ( & V_26 -> V_336 ) &&
( ( V_26 -> V_357 &&
V_26 -> V_355 > V_26 -> V_357 ) ||
F_17 ( & V_26 -> V_280 ) == 0 ) ) {
V_6 = F_35 ( V_26 -> V_336 . V_56 ,
F_187 ( * V_6 ) , V_27 ) ;
V_26 -> V_355 -= V_26 -> V_357 ;
if ( V_26 -> V_355 < 0 )
V_26 -> V_355 = 0 ;
} else
return NULL ;
F_36 ( & V_6 -> V_27 ) ;
F_37 ( & V_6 -> V_13 ) ;
F_15 ( F_17 ( & V_6 -> V_13 ) != 1 ) ;
return V_6 ;
}
static int F_188 ( T_7 * V_37 , struct V_1 * V_18 )
{
T_1 * V_26 = V_37 -> V_240 ;
int V_247 ;
T_2 V_252 ;
T_2 V_358 , V_359 ;
struct V_5 * V_6 ;
const int V_90 = F_189 ( V_18 ) ;
int V_360 ;
int V_361 ;
if ( F_79 ( V_18 -> V_98 & V_362 ) ) {
F_190 ( V_37 , V_18 ) ;
return 0 ;
}
F_191 ( V_37 , V_18 ) ;
if ( V_90 == V_96 &&
V_37 -> V_77 == V_78 &&
F_184 ( V_37 , V_18 ) )
return 0 ;
V_358 = V_18 -> V_117 & ~ ( ( T_2 ) V_107 - 1 ) ;
V_359 = V_18 -> V_117 + ( V_18 -> V_20 >> 9 ) ;
V_18 -> V_19 = NULL ;
V_18 -> V_2 = 1 ;
V_361 = F_192 ( V_37 ) ;
for (; V_358 < V_359 ; V_358 += V_107 ) {
F_193 ( V_363 ) ;
int V_9 , V_258 ;
int V_64 ;
V_236:
V_64 = 0 ;
V_9 = V_26 -> V_11 ;
F_194 ( & V_26 -> V_204 , & V_363 , V_364 ) ;
if ( F_79 ( V_26 -> V_365 != V_78 ) ) {
F_54 ( & V_26 -> V_48 ) ;
if ( V_37 -> V_366 < 0
? V_358 < V_26 -> V_365
: V_358 >= V_26 -> V_365 ) {
V_9 = V_26 -> V_66 ;
V_64 = 1 ;
} else {
if ( V_37 -> V_366 < 0
? V_358 < V_26 -> V_367
: V_358 >= V_26 -> V_367 ) {
F_57 ( & V_26 -> V_48 ) ;
F_195 () ;
goto V_236;
}
}
F_57 ( & V_26 -> V_48 ) ;
}
V_258 = V_9 - V_26 -> V_79 ;
V_252 = F_143 ( V_26 , V_358 ,
V_64 ,
& V_247 , NULL ) ;
F_28 ( L_53 ,
( unsigned long long ) V_252 ,
( unsigned long long ) V_358 ) ;
V_6 = F_53 ( V_26 , V_252 , V_64 ,
( V_18 -> V_98 & V_368 ) , 0 ) ;
if ( V_6 ) {
if ( F_79 ( V_64 ) ) {
int V_369 = 0 ;
F_54 ( & V_26 -> V_48 ) ;
if ( V_37 -> V_366 < 0
? V_358 >= V_26 -> V_365
: V_358 < V_26 -> V_365 )
V_369 = 1 ;
F_57 ( & V_26 -> V_48 ) ;
if ( V_369 ) {
F_24 ( V_6 ) ;
F_195 () ;
goto V_236;
}
}
if ( V_90 == V_94 &&
V_358 >= V_37 -> V_370 &&
V_358 < V_37 -> V_371 ) {
F_24 ( V_6 ) ;
F_196 ( V_372 ) ;
F_194 ( & V_26 -> V_204 ,
& V_363 , V_373 ) ;
if ( V_358 >= V_37 -> V_370 &&
V_358 < V_37 -> V_371 )
F_195 () ;
goto V_236;
}
if ( F_12 ( V_42 , & V_6 -> V_24 ) ||
! F_147 ( V_6 , V_18 , V_247 , V_90 ) ) {
F_20 ( V_37 -> V_38 ) ;
F_24 ( V_6 ) ;
F_195 () ;
goto V_236;
}
F_197 ( & V_26 -> V_204 , & V_363 ) ;
F_61 ( V_29 , & V_6 -> V_24 ) ;
F_19 ( V_30 , & V_6 -> V_24 ) ;
if ( ( V_18 -> V_98 & V_374 ) &&
! F_146 ( V_39 , & V_6 -> V_24 ) )
F_37 ( & V_26 -> V_40 ) ;
F_24 ( V_6 ) ;
} else {
F_19 ( V_120 , & V_18 -> V_119 ) ;
F_197 ( & V_26 -> V_204 , & V_363 ) ;
break;
}
}
if ( ! V_361 )
F_20 ( V_37 -> V_38 ) ;
F_54 ( & V_26 -> V_48 ) ;
V_360 = F_3 ( V_18 ) ;
F_57 ( & V_26 -> V_48 ) ;
if ( V_360 == 0 ) {
if ( V_90 == V_94 )
F_151 ( V_37 ) ;
F_10 ( V_18 , 0 ) ;
}
return 0 ;
}
static T_2 F_198 ( T_7 * V_37 , T_2 V_375 , int * V_376 )
{
T_1 * V_26 = V_37 -> V_240 ;
struct V_5 * V_6 ;
T_2 V_377 , V_359 ;
int V_11 = V_26 -> V_66 ;
int V_258 = V_11 - V_26 -> V_79 ;
int V_378 = V_26 -> V_11 - V_26 -> V_79 ;
int V_59 ;
int V_247 ;
T_2 V_379 , V_380 , V_381 ;
T_2 V_382 ;
int V_383 ;
struct V_53 V_384 ;
if ( V_375 == 0 ) {
if ( V_37 -> V_366 < 0 &&
V_26 -> V_365 < F_199 ( V_37 , 0 , 0 ) ) {
V_375 = F_199 ( V_37 , 0 , 0 )
- V_26 -> V_365 ;
} else if ( V_37 -> V_366 >= 0 &&
V_26 -> V_365 > 0 )
V_375 = V_26 -> V_365 ;
F_144 ( V_375 , V_378 ) ;
if ( V_375 ) {
V_37 -> V_385 = V_375 ;
F_200 ( & V_37 -> V_386 , NULL , L_54 ) ;
* V_376 = 1 ;
return V_375 ;
}
}
if ( V_37 -> V_347 > V_37 -> V_257 )
V_383 = V_37 -> V_347 ;
else
V_383 = V_37 -> V_257 ;
V_379 = V_26 -> V_365 ;
F_144 ( V_379 , V_378 ) ;
V_380 = V_26 -> V_365 ;
F_144 ( V_380 , V_258 ) ;
V_381 = V_26 -> V_367 ;
F_144 ( V_381 , V_258 ) ;
if ( V_37 -> V_366 < 0 ) {
V_379 -= F_201 ( T_2 , V_383 , V_379 ) ;
V_380 += V_383 ;
V_381 += V_383 ;
} else {
V_379 += V_383 ;
V_380 -= F_201 ( T_2 , V_383 , V_380 ) ;
V_381 -= F_201 ( T_2 , V_383 , V_381 ) ;
}
if ( ( V_37 -> V_366 < 0
? ( V_381 > V_379 && V_380 < V_379 )
: ( V_381 < V_379 && V_380 > V_379 ) ) ||
F_202 ( V_387 , V_26 -> V_388 + 10 * V_389 ) ) {
F_107 ( V_26 -> V_204 ,
F_17 ( & V_26 -> V_334 ) == 0 ) ;
V_37 -> V_77 = V_26 -> V_365 ;
V_37 -> V_385 = V_375 ;
V_26 -> V_388 = V_387 ;
F_61 ( V_244 , & V_37 -> V_47 ) ;
F_20 ( V_37 -> V_38 ) ;
F_107 ( V_37 -> V_390 , V_37 -> V_47 == 0 ||
F_203 () ) ;
F_54 ( & V_26 -> V_48 ) ;
V_26 -> V_367 = V_37 -> V_77 ;
F_57 ( & V_26 -> V_48 ) ;
F_23 ( & V_26 -> V_204 ) ;
F_200 ( & V_37 -> V_386 , NULL , L_54 ) ;
}
if ( V_37 -> V_366 < 0 ) {
F_15 ( V_26 -> V_365 == 0 ) ;
V_382 = V_379 ;
F_15 ( ( V_37 -> V_391 &
~ ( ( T_2 ) V_383 - 1 ) )
- V_383 - V_382
!= V_375 ) ;
} else {
F_15 ( V_379 != V_375 + V_383 ) ;
V_382 = V_375 ;
}
F_116 ( & V_384 ) ;
for ( V_59 = 0 ; V_59 < V_383 ; V_59 += V_107 ) {
int V_313 ;
int V_392 = 0 ;
V_6 = F_53 ( V_26 , V_382 + V_59 , 0 , 0 , 1 ) ;
F_61 ( V_42 , & V_6 -> V_24 ) ;
F_37 ( & V_26 -> V_334 ) ;
for ( V_313 = V_6 -> V_9 ; V_313 -- ; ) {
T_2 V_89 ;
if ( V_313 == V_6 -> V_16 )
continue;
if ( V_26 -> V_192 == 6 &&
V_313 == V_6 -> V_8 )
continue;
V_89 = F_142 ( V_6 , V_313 , 0 ) ;
if ( V_89 < F_199 ( V_37 , 0 , 0 ) ) {
V_392 = 1 ;
continue;
}
memset ( F_204 ( V_6 -> V_62 [ V_313 ] . V_57 ) , 0 , V_127 ) ;
F_61 ( V_315 , & V_6 -> V_62 [ V_313 ] . V_47 ) ;
F_61 ( V_153 , & V_6 -> V_62 [ V_313 ] . V_47 ) ;
}
if ( ! V_392 ) {
F_61 ( V_316 , & V_6 -> V_24 ) ;
F_61 ( V_29 , & V_6 -> V_24 ) ;
}
F_125 ( & V_6 -> V_27 , & V_384 ) ;
}
F_54 ( & V_26 -> V_48 ) ;
if ( V_37 -> V_366 < 0 )
V_26 -> V_365 -= V_383 * V_378 ;
else
V_26 -> V_365 += V_383 * V_378 ;
F_57 ( & V_26 -> V_48 ) ;
V_377 =
F_143 ( V_26 , V_382 * ( V_378 ) ,
1 , & V_247 , NULL ) ;
V_359 =
F_143 ( V_26 , ( ( V_382 + V_383 )
* V_378 - 1 ) ,
1 , & V_247 , NULL ) ;
if ( V_359 >= V_37 -> V_391 )
V_359 = V_37 -> V_391 - 1 ;
while ( V_377 <= V_359 ) {
V_6 = F_53 ( V_26 , V_377 , 1 , 0 , 1 ) ;
F_61 ( V_312 , & V_6 -> V_24 ) ;
F_61 ( V_29 , & V_6 -> V_24 ) ;
F_24 ( V_6 ) ;
V_377 += V_107 ;
}
while ( ! F_16 ( & V_384 ) ) {
V_6 = F_35 ( V_384 . V_56 , struct V_5 , V_27 ) ;
F_36 ( & V_6 -> V_27 ) ;
F_24 ( V_6 ) ;
}
V_375 += V_383 ;
if ( ( V_375 - V_37 -> V_385 ) * 2
>= V_37 -> V_393 - V_37 -> V_385 ) {
F_107 ( V_26 -> V_204 ,
F_17 ( & V_26 -> V_334 ) == 0 ) ;
V_37 -> V_77 = V_26 -> V_365 ;
V_37 -> V_385 = V_375 ;
V_26 -> V_388 = V_387 ;
F_61 ( V_244 , & V_37 -> V_47 ) ;
F_20 ( V_37 -> V_38 ) ;
F_107 ( V_37 -> V_390 ,
! F_12 ( V_244 , & V_37 -> V_47 )
|| F_203 () ) ;
F_54 ( & V_26 -> V_48 ) ;
V_26 -> V_367 = V_37 -> V_77 ;
F_57 ( & V_26 -> V_48 ) ;
F_23 ( & V_26 -> V_204 ) ;
F_200 ( & V_37 -> V_386 , NULL , L_54 ) ;
}
return V_383 ;
}
static inline T_2 F_205 ( T_7 * V_37 , T_2 V_375 , int * V_376 , int V_394 )
{
T_1 * V_26 = V_37 -> V_240 ;
struct V_5 * V_6 ;
T_2 V_395 = V_37 -> V_391 ;
T_2 V_396 ;
int V_397 = 0 ;
int V_59 ;
if ( V_375 >= V_395 ) {
if ( F_12 ( V_398 , & V_37 -> V_242 ) ) {
F_206 ( V_26 ) ;
return 0 ;
}
if ( V_37 -> V_399 < V_395 )
F_207 ( V_37 -> V_286 , V_37 -> V_399 ,
& V_396 , 1 ) ;
else
V_26 -> V_400 = 0 ;
F_208 ( V_37 -> V_286 ) ;
return 0 ;
}
F_107 ( V_26 -> V_204 , V_26 -> V_85 != 2 ) ;
if ( F_12 ( V_398 , & V_37 -> V_242 ) )
return F_198 ( V_37 , V_375 , V_376 ) ;
if ( V_37 -> V_76 >= V_26 -> V_79 &&
F_12 ( V_401 , & V_37 -> V_242 ) ) {
T_2 V_402 = V_37 -> V_391 - V_375 ;
* V_376 = 1 ;
return V_402 ;
}
if ( ! F_209 ( V_37 -> V_286 , V_375 , & V_396 , 1 ) &&
! F_12 ( V_403 , & V_37 -> V_242 ) &&
! V_26 -> V_400 && V_396 >= V_107 ) {
V_396 /= V_107 ;
* V_376 = 1 ;
return V_396 * V_107 ;
}
F_210 ( V_37 -> V_286 , V_375 ) ;
V_6 = F_53 ( V_26 , V_375 , 0 , 1 , 0 ) ;
if ( V_6 == NULL ) {
V_6 = F_53 ( V_26 , V_375 , 0 , 0 , 0 ) ;
F_211 ( 1 ) ;
}
for ( V_59 = 0 ; V_59 < V_26 -> V_11 ; V_59 ++ )
if ( V_26 -> V_9 [ V_59 ] . V_80 == NULL )
V_397 = 1 ;
F_209 ( V_37 -> V_286 , V_375 , & V_396 , V_397 ) ;
F_61 ( V_327 , & V_6 -> V_24 ) ;
F_164 ( V_6 ) ;
F_24 ( V_6 ) ;
return V_107 ;
}
static int F_212 ( T_1 * V_26 , struct V_1 * V_352 )
{
struct V_5 * V_6 ;
int V_247 ;
T_2 V_49 , V_358 , V_359 ;
int V_404 = 0 ;
int V_360 ;
int V_405 = 0 ;
V_358 = V_352 -> V_117 & ~ ( ( T_2 ) V_107 - 1 ) ;
V_49 = F_143 ( V_26 , V_358 ,
0 , & V_247 , NULL ) ;
V_359 = V_352 -> V_117 + ( V_352 -> V_20 >> 9 ) ;
for (; V_358 < V_359 ;
V_358 += V_107 ,
V_49 += V_107 ,
V_404 ++ ) {
if ( V_404 < F_2 ( V_352 ) )
continue;
V_6 = F_53 ( V_26 , V_49 , 0 , 1 , 0 ) ;
if ( ! V_6 ) {
F_5 ( V_352 , V_404 ) ;
V_26 -> V_45 = V_352 ;
return V_405 ;
}
F_61 ( V_230 , & V_6 -> V_62 [ V_247 ] . V_47 ) ;
if ( ! F_147 ( V_6 , V_352 , V_247 , 0 ) ) {
F_24 ( V_6 ) ;
F_5 ( V_352 , V_404 ) ;
V_26 -> V_45 = V_352 ;
return V_405 ;
}
F_164 ( V_6 ) ;
F_24 ( V_6 ) ;
V_405 ++ ;
}
F_54 ( & V_26 -> V_48 ) ;
V_360 = F_3 ( V_352 ) ;
F_57 ( & V_26 -> V_48 ) ;
if ( V_360 == 0 )
F_10 ( V_352 , 0 ) ;
if ( F_14 ( & V_26 -> V_350 ) )
F_23 ( & V_26 -> V_44 ) ;
return V_405 ;
}
static void F_213 ( T_7 * V_37 )
{
struct V_5 * V_6 ;
T_1 * V_26 = V_37 -> V_240 ;
int V_405 ;
struct V_406 V_407 ;
F_28 ( L_55 ) ;
F_62 ( V_37 ) ;
F_214 ( & V_407 ) ;
V_405 = 0 ;
F_54 ( & V_26 -> V_48 ) ;
while ( 1 ) {
struct V_1 * V_1 ;
if ( F_17 ( & V_37 -> V_408 ) == 0 &&
! F_16 ( & V_26 -> V_35 ) ) {
V_26 -> V_287 ++ ;
F_57 ( & V_26 -> V_48 ) ;
F_215 ( V_37 -> V_286 ) ;
F_54 ( & V_26 -> V_48 ) ;
V_26 -> V_34 = V_26 -> V_287 ;
F_167 ( V_26 ) ;
}
if ( F_17 ( & V_37 -> V_408 ) == 0 )
F_166 ( V_26 ) ;
while ( ( V_1 = F_176 ( V_26 ) ) ) {
int V_409 ;
F_57 ( & V_26 -> V_48 ) ;
V_409 = F_212 ( V_26 , V_1 ) ;
F_54 ( & V_26 -> V_48 ) ;
if ( ! V_409 )
break;
V_405 ++ ;
}
V_6 = F_186 ( V_26 ) ;
if ( ! V_6 )
break;
F_57 ( & V_26 -> V_48 ) ;
V_405 ++ ;
F_164 ( V_6 ) ;
F_24 ( V_6 ) ;
F_216 () ;
if ( V_37 -> V_47 & ~ ( 1 << V_410 ) )
F_62 ( V_37 ) ;
F_54 ( & V_26 -> V_48 ) ;
}
F_28 ( L_56 , V_405 ) ;
F_57 ( & V_26 -> V_48 ) ;
F_217 () ;
F_218 ( & V_407 ) ;
F_28 ( L_57 ) ;
}
static T_8
F_219 ( T_7 * V_37 , char * V_57 )
{
T_1 * V_26 = V_37 -> V_240 ;
if ( V_26 )
return sprintf ( V_57 , L_58 , V_26 -> V_87 ) ;
else
return 0 ;
}
int
F_220 ( T_7 * V_37 , int V_411 )
{
T_1 * V_26 = V_37 -> V_240 ;
int V_223 ;
if ( V_411 <= 16 || V_411 > 32768 )
return - V_412 ;
while ( V_411 < V_26 -> V_87 ) {
if ( F_135 ( V_26 ) )
V_26 -> V_87 -- ;
else
break;
}
V_223 = F_124 ( V_37 ) ;
if ( V_223 )
return V_223 ;
while ( V_411 > V_26 -> V_87 ) {
if ( F_110 ( V_26 ) )
V_26 -> V_87 ++ ;
else break;
}
return 0 ;
}
static T_8
F_221 ( T_7 * V_37 , const char * V_57 , T_6 V_141 )
{
T_1 * V_26 = V_37 -> V_240 ;
unsigned long V_413 ;
int V_223 ;
if ( V_141 >= V_414 )
return - V_412 ;
if ( ! V_26 )
return - V_415 ;
if ( F_222 ( V_57 , 10 , & V_413 ) )
return - V_412 ;
V_223 = F_220 ( V_37 , V_413 ) ;
if ( V_223 )
return V_223 ;
return V_141 ;
}
static T_8
F_223 ( T_7 * V_37 , char * V_57 )
{
T_1 * V_26 = V_37 -> V_240 ;
if ( V_26 )
return sprintf ( V_57 , L_58 , V_26 -> V_357 ) ;
else
return 0 ;
}
static T_8
F_224 ( T_7 * V_37 , const char * V_57 , T_6 V_141 )
{
T_1 * V_26 = V_37 -> V_240 ;
unsigned long V_413 ;
if ( V_141 >= V_414 )
return - V_412 ;
if ( ! V_26 )
return - V_415 ;
if ( F_222 ( V_57 , 10 , & V_413 ) )
return - V_412 ;
if ( V_413 > V_26 -> V_87 )
return - V_412 ;
V_26 -> V_357 = V_413 ;
return V_141 ;
}
static T_8
F_225 ( T_7 * V_37 , char * V_57 )
{
T_1 * V_26 = V_37 -> V_240 ;
if ( V_26 )
return sprintf ( V_57 , L_58 , F_17 ( & V_26 -> V_28 ) ) ;
else
return 0 ;
}
static T_2
F_199 ( T_7 * V_37 , T_2 V_416 , int V_11 )
{
T_1 * V_26 = V_37 -> V_240 ;
if ( ! V_416 )
V_416 = V_37 -> V_391 ;
if ( ! V_11 )
V_11 = F_226 ( V_26 -> V_11 , V_26 -> V_66 ) ;
V_416 &= ~ ( ( T_2 ) V_37 -> V_257 - 1 ) ;
V_416 &= ~ ( ( T_2 ) V_37 -> V_347 - 1 ) ;
return V_416 * ( V_11 - V_26 -> V_79 ) ;
}
static void F_227 ( T_1 * V_26 )
{
struct V_159 * V_160 ;
unsigned long V_193 ;
if ( ! V_26 -> V_160 )
return;
F_131 () ;
F_228 (cpu) {
V_160 = F_101 ( V_26 -> V_160 , V_193 ) ;
F_229 ( V_160 -> V_189 ) ;
F_130 ( V_160 -> V_161 ) ;
}
#ifdef F_230
F_231 ( & V_26 -> V_417 ) ;
#endif
F_134 () ;
F_232 ( V_26 -> V_160 ) ;
}
static void F_233 ( T_1 * V_26 )
{
F_136 ( V_26 ) ;
F_227 ( V_26 ) ;
F_130 ( V_26 -> V_9 ) ;
F_130 ( V_26 -> V_418 ) ;
F_130 ( V_26 ) ;
}
static int F_234 ( struct V_419 * V_420 , unsigned long V_421 ,
void * V_422 )
{
T_1 * V_26 = F_235 ( V_420 , T_1 , V_417 ) ;
long V_193 = ( long ) V_422 ;
struct V_159 * V_160 = F_101 ( V_26 -> V_160 , V_193 ) ;
switch ( V_421 ) {
case V_423 :
case V_424 :
if ( V_26 -> V_192 == 6 && ! V_160 -> V_189 )
V_160 -> V_189 = F_41 ( V_63 ) ;
if ( ! V_160 -> V_161 )
V_160 -> V_161 = F_133 ( V_26 -> F_121 , V_63 ) ;
if ( ! V_160 -> V_161 ||
( V_26 -> V_192 == 6 && ! V_160 -> V_189 ) ) {
F_229 ( V_160 -> V_189 ) ;
F_130 ( V_160 -> V_161 ) ;
F_236 ( L_59 ,
V_116 , V_193 ) ;
return F_237 ( - V_224 ) ;
}
break;
case V_425 :
case V_426 :
F_229 ( V_160 -> V_189 ) ;
F_130 ( V_160 -> V_161 ) ;
V_160 -> V_189 = NULL ;
V_160 -> V_161 = NULL ;
break;
default:
break;
}
return V_427 ;
}
static int F_238 ( T_1 * V_26 )
{
unsigned long V_193 ;
struct V_57 * V_189 ;
struct V_159 T_9 * V_428 ;
void * V_161 ;
int V_223 ;
V_428 = F_239 ( struct V_159 ) ;
if ( ! V_428 )
return - V_224 ;
V_26 -> V_160 = V_428 ;
F_131 () ;
V_223 = 0 ;
F_132 (cpu) {
if ( V_26 -> V_192 == 6 ) {
V_189 = F_41 ( V_63 ) ;
if ( ! V_189 ) {
V_223 = - V_224 ;
break;
}
F_101 ( V_26 -> V_160 , V_193 ) -> V_189 = V_189 ;
}
V_161 = F_133 ( V_26 -> F_121 , V_63 ) ;
if ( ! V_161 ) {
V_223 = - V_224 ;
break;
}
F_101 ( V_26 -> V_160 , V_193 ) -> V_161 = V_161 ;
}
#ifdef F_230
V_26 -> V_417 . V_429 = F_234 ;
V_26 -> V_417 . V_430 = 0 ;
if ( V_223 == 0 )
V_223 = F_240 ( & V_26 -> V_417 ) ;
#endif
F_134 () ;
return V_223 ;
}
static T_1 * F_241 ( T_7 * V_37 )
{
T_1 * V_26 ;
int V_431 , V_432 , V_433 ;
T_3 * V_80 ;
struct V_221 * V_10 ;
if ( V_37 -> V_434 != 5
&& V_37 -> V_434 != 4
&& V_37 -> V_434 != 6 ) {
F_44 ( V_73 L_60 ,
F_119 ( V_37 ) , V_37 -> V_434 ) ;
return F_242 ( - V_435 ) ;
}
if ( ( V_37 -> V_434 == 5
&& ! F_243 ( V_37 -> V_436 ) ) ||
( V_37 -> V_434 == 6
&& ! F_244 ( V_37 -> V_436 ) ) ) {
F_44 ( V_73 L_61 ,
F_119 ( V_37 ) , V_37 -> V_436 ) ;
return F_242 ( - V_435 ) ;
}
if ( V_37 -> V_434 == 6 && V_37 -> V_11 < 4 ) {
F_44 ( V_73 L_62 ,
F_119 ( V_37 ) , V_37 -> V_11 ) ;
return F_242 ( - V_412 ) ;
}
if ( ! V_37 -> V_347 ||
( V_37 -> V_347 << 9 ) % V_414 ||
! F_245 ( V_37 -> V_347 ) ) {
F_44 ( V_73 L_63 ,
F_119 ( V_37 ) , V_37 -> V_347 << 9 ) ;
return F_242 ( - V_412 ) ;
}
V_26 = F_129 ( sizeof( T_1 ) , V_63 ) ;
if ( V_26 == NULL )
goto abort;
F_246 ( & V_26 -> V_48 ) ;
F_113 ( & V_26 -> V_44 ) ;
F_113 ( & V_26 -> V_204 ) ;
F_116 ( & V_26 -> V_36 ) ;
F_116 ( & V_26 -> V_336 ) ;
F_116 ( & V_26 -> V_31 ) ;
F_116 ( & V_26 -> V_35 ) ;
F_116 ( & V_26 -> V_43 ) ;
F_115 ( & V_26 -> V_28 , 0 ) ;
F_115 ( & V_26 -> V_40 , 0 ) ;
F_115 ( & V_26 -> V_350 , 0 ) ;
V_26 -> V_357 = V_437 ;
V_26 -> V_11 = V_37 -> V_11 ;
if ( V_37 -> V_77 == V_78 )
V_26 -> V_66 = V_37 -> V_11 ;
else
V_26 -> V_66 = V_37 -> V_11 - V_37 -> V_366 ;
V_433 = F_118 ( V_26 -> V_11 , V_26 -> V_66 ) ;
V_26 -> F_121 = F_121 ( V_433 ) ;
V_26 -> V_9 = F_129 ( V_433 * sizeof( struct V_221 ) ,
V_63 ) ;
if ( ! V_26 -> V_9 )
goto abort;
V_26 -> V_37 = V_37 ;
if ( ( V_26 -> V_418 = F_129 ( V_414 , V_63 ) ) == NULL )
goto abort;
V_26 -> V_192 = V_37 -> V_434 ;
if ( F_238 ( V_26 ) != 0 )
goto abort;
F_28 ( L_64 , F_119 ( V_37 ) ) ;
F_128 (rdev, &mddev->disks, same_set) {
V_431 = V_80 -> V_431 ;
if ( V_431 >= V_433
|| V_431 < 0 )
continue;
V_10 = V_26 -> V_9 + V_431 ;
V_10 -> V_80 = V_80 ;
if ( F_12 ( V_82 , & V_80 -> V_47 ) ) {
char V_228 [ V_229 ] ;
F_44 ( V_231 L_65
L_66 ,
F_119 ( V_37 ) , F_138 ( V_80 -> V_113 , V_228 ) , V_431 ) ;
} else if ( V_80 -> V_438 != V_431 )
V_26 -> V_400 = 1 ;
}
V_26 -> V_257 = V_37 -> V_347 ;
V_26 -> V_192 = V_37 -> V_434 ;
if ( V_26 -> V_192 == 6 )
V_26 -> V_79 = 2 ;
else
V_26 -> V_79 = 1 ;
V_26 -> V_253 = V_37 -> V_436 ;
V_26 -> V_87 = V_439 ;
V_26 -> V_365 = V_37 -> V_77 ;
if ( V_26 -> V_365 != V_78 ) {
V_26 -> V_256 = V_37 -> V_257 ;
V_26 -> V_254 = V_37 -> V_440 ;
}
V_432 = V_26 -> V_87 * ( sizeof( struct V_5 ) +
V_433 * ( ( sizeof( struct V_1 ) + V_414 ) ) ) / 1024 ;
if ( F_117 ( V_26 , V_26 -> V_87 ) ) {
F_44 ( V_73
L_67 ,
F_119 ( V_37 ) , V_432 ) ;
goto abort;
} else
F_44 ( V_231 L_68 ,
F_119 ( V_37 ) , V_432 ) ;
V_26 -> V_38 = F_247 ( F_213 , V_37 , NULL ) ;
if ( ! V_26 -> V_38 ) {
F_44 ( V_73
L_69 ,
F_119 ( V_37 ) ) ;
goto abort;
}
return V_26 ;
abort:
if ( V_26 ) {
F_233 ( V_26 ) ;
return F_242 ( - V_435 ) ;
} else
return F_242 ( - V_224 ) ;
}
static int F_248 ( int V_431 , int V_441 , int V_11 , int V_79 )
{
switch ( V_441 ) {
case V_263 :
if ( V_431 < V_79 )
return 1 ;
break;
case V_264 :
if ( V_431 >= V_11 - V_79 )
return 1 ;
break;
case V_272 :
if ( V_431 == 0 ||
V_431 == V_11 - 1 )
return 1 ;
break;
case V_268 :
case V_269 :
case V_270 :
case V_271 :
if ( V_431 == V_11 - 1 )
return 1 ;
}
return 0 ;
}
static int F_249 ( T_7 * V_37 )
{
T_1 * V_26 ;
int V_442 = 0 ;
int V_443 = 0 ;
T_3 * V_80 ;
T_2 V_444 = 0 ;
if ( V_37 -> V_445 != V_78 )
F_44 ( V_446 L_70
L_71 ,
F_119 ( V_37 ) ) ;
if ( V_37 -> V_77 != V_78 ) {
T_2 V_447 , V_448 ;
int V_449 ;
int V_79 = ( V_37 -> V_192 == 6 ? 2 : 1 ) ;
if ( V_37 -> V_434 != V_37 -> V_192 ) {
F_44 ( V_73 L_72
L_73 ,
F_119 ( V_37 ) ) ;
return - V_412 ;
}
V_449 = V_37 -> V_11 - V_37 -> V_366 ;
V_447 = V_37 -> V_77 ;
if ( F_144 ( V_447 , V_37 -> V_347 *
( V_37 -> V_11 - V_79 ) ) ) {
F_44 ( V_73 L_74
L_75 , F_119 ( V_37 ) ) ;
return - V_412 ;
}
V_444 = V_447 * V_37 -> V_347 ;
V_448 = V_37 -> V_77 ;
F_144 ( V_448 , V_37 -> V_257 *
( V_449 - V_79 ) ) ;
if ( V_37 -> V_366 == 0 ) {
if ( ( V_447 * V_37 -> V_347 !=
V_448 * V_37 -> V_257 ) ||
V_37 -> V_332 == 0 ) {
F_44 ( V_73 L_76
L_77 ,
F_119 ( V_37 ) ) ;
return - V_412 ;
}
} else if ( V_37 -> V_366 < 0
? ( V_447 * V_37 -> V_347 <=
V_448 * V_37 -> V_257 )
: ( V_447 * V_37 -> V_347 >=
V_448 * V_37 -> V_257 ) ) {
F_44 ( V_73 L_78
L_79 ,
F_119 ( V_37 ) ) ;
return - V_412 ;
}
F_44 ( V_231 L_80 ,
F_119 ( V_37 ) ) ;
} else {
F_15 ( V_37 -> V_192 != V_37 -> V_434 ) ;
F_15 ( V_37 -> V_440 != V_37 -> V_436 ) ;
F_15 ( V_37 -> V_257 != V_37 -> V_347 ) ;
F_15 ( V_37 -> V_366 != 0 ) ;
}
if ( V_37 -> V_240 == NULL )
V_26 = F_241 ( V_37 ) ;
else
V_26 = V_37 -> V_240 ;
if ( F_250 ( V_26 ) )
return F_251 ( V_26 ) ;
V_37 -> V_38 = V_26 -> V_38 ;
V_26 -> V_38 = NULL ;
V_37 -> V_240 = V_26 ;
F_128 (rdev, &mddev->disks, same_set) {
if ( V_80 -> V_431 < 0 )
continue;
if ( F_12 ( V_82 , & V_80 -> V_47 ) ) {
V_442 ++ ;
continue;
}
if ( V_37 -> V_450 == 0 &&
V_37 -> V_451 > 90 )
V_80 -> V_322 = V_444 ;
if ( V_80 -> V_322 < V_444 ) {
if ( ! F_248 ( V_80 -> V_431 ,
V_26 -> V_253 ,
V_26 -> V_11 ,
V_26 -> V_79 ) )
continue;
}
if ( ! F_248 ( V_80 -> V_431 ,
V_26 -> V_254 ,
V_26 -> V_66 ,
V_26 -> V_79 ) )
continue;
V_443 ++ ;
}
V_37 -> V_76 = ( F_118 ( V_26 -> V_11 , V_26 -> V_66 )
- V_442 ) ;
if ( F_49 ( V_26 ) ) {
F_44 ( V_73 L_81
L_82 ,
F_119 ( V_37 ) , V_37 -> V_76 , V_26 -> V_11 ) ;
goto abort;
}
V_37 -> V_391 &= ~ ( V_37 -> V_257 - 1 ) ;
V_37 -> V_452 = V_37 -> V_391 ;
if ( V_37 -> V_76 > V_443 &&
V_37 -> V_445 != V_78 ) {
if ( V_37 -> V_453 )
F_44 ( V_237
L_83
L_84 ,
F_119 ( V_37 ) ) ;
else {
F_44 ( V_73
L_85 ,
F_119 ( V_37 ) ) ;
goto abort;
}
}
if ( V_37 -> V_76 == 0 )
F_44 ( V_231 L_86
L_87 , F_119 ( V_37 ) , V_26 -> V_192 ,
V_37 -> V_11 - V_37 -> V_76 , V_37 -> V_11 ,
V_37 -> V_436 ) ;
else
F_44 ( V_245 L_88
L_89 ,
F_119 ( V_37 ) , V_26 -> V_192 ,
V_37 -> V_11 - V_37 -> V_76 ,
V_37 -> V_11 , V_37 -> V_436 ) ;
F_252 ( V_26 ) ;
if ( V_26 -> V_365 != V_78 ) {
V_26 -> V_367 = V_26 -> V_365 ;
F_115 ( & V_26 -> V_334 , 0 ) ;
F_19 ( V_401 , & V_37 -> V_242 ) ;
F_19 ( V_309 , & V_37 -> V_242 ) ;
F_61 ( V_398 , & V_37 -> V_242 ) ;
F_61 ( V_454 , & V_37 -> V_242 ) ;
V_37 -> V_455 = F_247 ( V_456 , V_37 ,
L_90 ) ;
}
if ( V_37 -> V_457 == & V_458 )
V_37 -> V_457 = NULL ;
else if ( V_37 -> V_386 . V_459 &&
F_253 ( & V_37 -> V_386 , & V_458 ) )
F_44 ( V_237
L_91 ,
F_119 ( V_37 ) ) ;
F_254 ( V_37 , F_199 ( V_37 , 0 , 0 ) ) ;
if ( V_37 -> V_460 ) {
int V_461 ;
int V_258 = V_26 -> V_66 - V_26 -> V_79 ;
int V_248 = V_258 *
( ( V_37 -> V_257 << 9 ) / V_414 ) ;
if ( V_37 -> V_460 -> V_462 . V_463 < 2 * V_248 )
V_37 -> V_460 -> V_462 . V_463 = 2 * V_248 ;
F_255 ( V_37 -> V_460 , F_172 ) ;
V_37 -> V_460 -> V_462 . V_464 = V_37 ;
V_37 -> V_460 -> V_462 . V_465 = F_170 ;
V_461 = V_37 -> V_257 << 9 ;
F_256 ( V_37 -> V_460 , V_461 ) ;
F_257 ( V_37 -> V_460 , V_461 *
( V_26 -> V_11 - V_26 -> V_79 ) ) ;
F_128 (rdev, &mddev->disks, same_set)
F_258 ( V_37 -> V_214 , V_80 -> V_113 ,
V_80 -> V_118 << 9 ) ;
}
return 0 ;
abort:
F_259 ( & V_37 -> V_38 ) ;
if ( V_26 ) {
F_252 ( V_26 ) ;
F_233 ( V_26 ) ;
}
V_37 -> V_240 = NULL ;
F_44 ( V_245 L_92 , F_119 ( V_37 ) ) ;
return - V_435 ;
}
static int F_260 ( T_7 * V_37 )
{
T_1 * V_26 = V_37 -> V_240 ;
F_259 ( & V_37 -> V_38 ) ;
if ( V_37 -> V_460 )
V_37 -> V_460 -> V_462 . V_465 = NULL ;
F_233 ( V_26 ) ;
V_37 -> V_240 = NULL ;
V_37 -> V_457 = & V_458 ;
return 0 ;
}
static void F_261 ( struct V_466 * V_467 , struct V_5 * V_6 )
{
int V_59 ;
F_262 ( V_467 , L_93 ,
( unsigned long long ) V_6 -> V_49 , V_6 -> V_16 , V_6 -> V_24 ) ;
F_262 ( V_467 , L_94 ,
( unsigned long long ) V_6 -> V_49 , F_17 ( & V_6 -> V_13 ) ) ;
F_262 ( V_467 , L_95 , ( unsigned long long ) V_6 -> V_49 ) ;
for ( V_59 = 0 ; V_59 < V_6 -> V_9 ; V_59 ++ ) {
F_262 ( V_467 , L_96 ,
V_59 , V_6 -> V_62 [ V_59 ] . V_57 , V_6 -> V_62 [ V_59 ] . V_47 ) ;
}
F_262 ( V_467 , L_97 ) ;
}
static void F_263 ( struct V_466 * V_467 , T_1 * V_26 )
{
struct V_5 * V_6 ;
struct V_74 * V_75 ;
int V_59 ;
F_54 ( & V_26 -> V_48 ) ;
for ( V_59 = 0 ; V_59 < V_468 ; V_59 ++ ) {
F_48 (sh, hn, &conf->stripe_hashtbl[i], hash) {
if ( V_6 -> V_46 != V_26 )
continue;
F_261 ( V_467 , V_6 ) ;
}
}
F_57 ( & V_26 -> V_48 ) ;
}
static void F_264 ( struct V_466 * V_467 , T_7 * V_37 )
{
T_1 * V_26 = V_37 -> V_240 ;
int V_59 ;
F_262 ( V_467 , L_98 , V_37 -> V_192 ,
V_37 -> V_257 / 2 , V_37 -> V_440 ) ;
F_262 ( V_467 , L_99 , V_26 -> V_11 , V_26 -> V_11 - V_37 -> V_76 ) ;
for ( V_59 = 0 ; V_59 < V_26 -> V_11 ; V_59 ++ )
F_262 ( V_467 , L_100 ,
V_26 -> V_9 [ V_59 ] . V_80 &&
F_12 ( V_82 , & V_26 -> V_9 [ V_59 ] . V_80 -> V_47 ) ? L_101 : L_102 ) ;
F_262 ( V_467 , L_103 ) ;
#ifdef F_265
F_262 ( V_467 , L_97 ) ;
F_263 ( V_467 , V_26 ) ;
#endif
}
static void F_252 ( T_1 * V_26 )
{
int V_59 ;
struct V_221 * V_469 ;
F_44 ( V_470 L_104 ) ;
if ( ! V_26 ) {
F_44 ( L_105 ) ;
return;
}
F_44 ( V_470 L_106 , V_26 -> V_192 ,
V_26 -> V_11 ,
V_26 -> V_11 - V_26 -> V_37 -> V_76 ) ;
for ( V_59 = 0 ; V_59 < V_26 -> V_11 ; V_59 ++ ) {
char V_228 [ V_229 ] ;
V_469 = V_26 -> V_9 + V_59 ;
if ( V_469 -> V_80 )
F_44 ( V_470 L_107 ,
V_59 , ! F_12 ( V_81 , & V_469 -> V_80 -> V_47 ) ,
F_138 ( V_469 -> V_80 -> V_113 , V_228 ) ) ;
}
}
static int F_266 ( T_7 * V_37 )
{
int V_59 ;
T_1 * V_26 = V_37 -> V_240 ;
struct V_221 * V_469 ;
int V_13 = 0 ;
unsigned long V_47 ;
for ( V_59 = 0 ; V_59 < V_26 -> V_11 ; V_59 ++ ) {
V_469 = V_26 -> V_9 + V_59 ;
if ( V_469 -> V_80
&& V_469 -> V_80 -> V_322 == V_78
&& ! F_12 ( V_81 , & V_469 -> V_80 -> V_47 )
&& ! F_146 ( V_82 , & V_469 -> V_80 -> V_47 ) ) {
V_13 ++ ;
F_267 ( V_469 -> V_80 -> V_471 ) ;
}
}
F_25 ( & V_26 -> V_48 , V_47 ) ;
V_37 -> V_76 -= V_13 ;
F_26 ( & V_26 -> V_48 , V_47 ) ;
F_252 ( V_26 ) ;
return V_13 ;
}
static int F_268 ( T_7 * V_37 , int V_472 )
{
T_1 * V_26 = V_37 -> V_240 ;
int V_223 = 0 ;
T_3 * V_80 ;
struct V_221 * V_58 = V_26 -> V_9 + V_472 ;
F_252 ( V_26 ) ;
V_80 = V_58 -> V_80 ;
if ( V_80 ) {
if ( V_472 >= V_26 -> V_11 &&
V_26 -> V_365 == V_78 )
F_19 ( V_82 , & V_80 -> V_47 ) ;
if ( F_12 ( V_82 , & V_80 -> V_47 ) ||
F_17 ( & V_80 -> V_102 ) ) {
V_223 = - V_473 ;
goto abort;
}
if ( ! F_12 ( V_81 , & V_80 -> V_47 ) &&
V_37 -> V_296 != V_26 -> V_296 &&
! F_49 ( V_26 ) &&
V_472 < V_26 -> V_11 ) {
V_223 = - V_473 ;
goto abort;
}
V_58 -> V_80 = NULL ;
F_269 () ;
if ( F_17 ( & V_80 -> V_102 ) ) {
V_223 = - V_473 ;
V_58 -> V_80 = V_80 ;
}
}
abort:
F_252 ( V_26 ) ;
return V_223 ;
}
static int F_270 ( T_7 * V_37 , T_3 * V_80 )
{
T_1 * V_26 = V_37 -> V_240 ;
int V_223 = - V_474 ;
int V_10 ;
struct V_221 * V_58 ;
int V_54 = 0 ;
int V_475 = V_26 -> V_11 - 1 ;
if ( V_37 -> V_296 == V_26 -> V_296 )
return - V_473 ;
if ( F_49 ( V_26 ) )
return - V_412 ;
if ( V_80 -> V_431 >= 0 )
V_54 = V_475 = V_80 -> V_431 ;
if ( V_80 -> V_438 >= 0 &&
V_80 -> V_438 >= V_54 &&
V_26 -> V_9 [ V_80 -> V_438 ] . V_80 == NULL )
V_10 = V_80 -> V_438 ;
else
V_10 = V_54 ;
for ( ; V_10 <= V_475 ; V_10 ++ )
if ( ( V_58 = V_26 -> V_9 + V_10 ) -> V_80 == NULL ) {
F_19 ( V_82 , & V_80 -> V_47 ) ;
V_80 -> V_431 = V_10 ;
V_223 = 0 ;
if ( V_80 -> V_438 != V_10 )
V_26 -> V_400 = 1 ;
F_271 ( V_58 -> V_80 , V_80 ) ;
break;
}
F_252 ( V_26 ) ;
return V_223 ;
}
static int F_272 ( T_7 * V_37 , T_2 V_416 )
{
V_416 &= ~ ( ( T_2 ) V_37 -> V_257 - 1 ) ;
F_254 ( V_37 , F_199 ( V_37 , V_416 ,
V_37 -> V_11 ) ) ;
if ( V_37 -> V_476 >
F_199 ( V_37 , V_416 , V_37 -> V_11 ) )
return - V_412 ;
F_273 ( V_37 -> V_214 , V_37 -> V_476 ) ;
F_274 ( V_37 -> V_214 ) ;
if ( V_416 > V_37 -> V_391 &&
V_37 -> V_445 > V_37 -> V_391 ) {
V_37 -> V_445 = V_37 -> V_391 ;
F_61 ( V_477 , & V_37 -> V_242 ) ;
}
V_37 -> V_391 = V_416 ;
V_37 -> V_452 = V_416 ;
return 0 ;
}
static int F_275 ( T_7 * V_37 )
{
T_1 * V_26 = V_37 -> V_240 ;
if ( ( ( V_37 -> V_257 << 9 ) / V_127 ) * 4
> V_26 -> V_87 ||
( ( V_37 -> V_347 << 9 ) / V_127 ) * 4
> V_26 -> V_87 ) {
F_44 ( V_237 L_108 ,
F_119 ( V_37 ) ,
( ( F_118 ( V_37 -> V_257 , V_37 -> V_347 ) << 9 )
/ V_127 ) * 4 ) ;
return 0 ;
}
return 1 ;
}
static int F_276 ( T_7 * V_37 )
{
T_1 * V_26 = V_37 -> V_240 ;
if ( V_37 -> V_366 == 0 &&
V_37 -> V_436 == V_37 -> V_440 &&
V_37 -> V_347 == V_37 -> V_257 )
return 0 ;
if ( V_37 -> V_286 )
return - V_473 ;
if ( F_49 ( V_26 ) )
return - V_412 ;
if ( V_37 -> V_366 < 0 ) {
int F_226 = 2 ;
if ( V_37 -> V_192 == 6 )
F_226 = 4 ;
if ( V_37 -> V_11 + V_37 -> V_366 < F_226 )
return - V_412 ;
}
if ( ! F_275 ( V_37 ) )
return - V_478 ;
return F_122 ( V_26 , V_26 -> V_11 + V_37 -> V_366 ) ;
}
static int F_277 ( T_7 * V_37 )
{
T_1 * V_26 = V_37 -> V_240 ;
T_3 * V_80 ;
int V_479 = 0 ;
unsigned long V_47 ;
if ( F_12 ( V_454 , & V_37 -> V_242 ) )
return - V_473 ;
if ( ! F_275 ( V_37 ) )
return - V_478 ;
F_128 (rdev, &mddev->disks, same_set)
if ( ! F_12 ( V_82 , & V_80 -> V_47 )
&& ! F_12 ( V_81 , & V_80 -> V_47 ) )
V_479 ++ ;
if ( V_479 - V_37 -> V_76 < V_37 -> V_366 - V_26 -> V_79 )
return - V_412 ;
if ( F_199 ( V_37 , 0 , V_26 -> V_11 + V_37 -> V_366 )
< V_37 -> V_476 ) {
F_44 ( V_73 L_109
L_110 , F_119 ( V_37 ) ) ;
return - V_412 ;
}
F_115 ( & V_26 -> V_334 , 0 ) ;
F_54 ( & V_26 -> V_48 ) ;
V_26 -> V_66 = V_26 -> V_11 ;
V_26 -> V_11 += V_37 -> V_366 ;
V_26 -> V_256 = V_26 -> V_257 ;
V_26 -> V_257 = V_37 -> V_347 ;
V_26 -> V_254 = V_26 -> V_253 ;
V_26 -> V_253 = V_37 -> V_436 ;
if ( V_37 -> V_366 < 0 )
V_26 -> V_365 = F_199 ( V_37 , 0 , 0 ) ;
else
V_26 -> V_365 = 0 ;
V_26 -> V_367 = V_26 -> V_365 ;
V_26 -> V_65 ++ ;
F_57 ( & V_26 -> V_48 ) ;
if ( V_37 -> V_366 >= 0 ) {
int V_480 = 0 ;
F_128 (rdev, &mddev->disks, same_set)
if ( V_80 -> V_431 < 0 &&
! F_12 ( V_81 , & V_80 -> V_47 ) ) {
if ( F_270 ( V_37 , V_80 ) == 0 ) {
if ( V_80 -> V_431
>= V_26 -> V_66 ) {
F_61 ( V_82 , & V_80 -> V_47 ) ;
V_480 ++ ;
} else
V_80 -> V_322 = 0 ;
if ( F_278 ( V_37 , V_80 ) )
;
}
} else if ( V_80 -> V_431 >= V_26 -> V_66
&& ! F_12 ( V_81 , & V_80 -> V_47 ) ) {
F_61 ( V_82 , & V_80 -> V_47 ) ;
V_480 ++ ;
}
F_25 ( & V_26 -> V_48 , V_47 ) ;
V_37 -> V_76 += ( V_26 -> V_11 - V_26 -> V_66 )
- V_480 ;
F_26 ( & V_26 -> V_48 , V_47 ) ;
}
V_37 -> V_11 = V_26 -> V_11 ;
V_37 -> V_77 = V_26 -> V_365 ;
F_61 ( V_244 , & V_37 -> V_47 ) ;
F_19 ( V_401 , & V_37 -> V_242 ) ;
F_19 ( V_309 , & V_37 -> V_242 ) ;
F_61 ( V_398 , & V_37 -> V_242 ) ;
F_61 ( V_454 , & V_37 -> V_242 ) ;
V_37 -> V_455 = F_247 ( V_456 , V_37 ,
L_90 ) ;
if ( ! V_37 -> V_455 ) {
V_37 -> V_242 = 0 ;
F_54 ( & V_26 -> V_48 ) ;
V_37 -> V_11 = V_26 -> V_11 = V_26 -> V_66 ;
V_26 -> V_365 = V_78 ;
F_57 ( & V_26 -> V_48 ) ;
return - V_481 ;
}
V_26 -> V_388 = V_387 ;
F_20 ( V_37 -> V_455 ) ;
F_279 ( V_37 ) ;
return 0 ;
}
static void F_206 ( T_1 * V_26 )
{
if ( ! F_12 ( V_241 , & V_26 -> V_37 -> V_242 ) ) {
F_54 ( & V_26 -> V_48 ) ;
V_26 -> V_66 = V_26 -> V_11 ;
V_26 -> V_365 = V_78 ;
F_57 ( & V_26 -> V_48 ) ;
F_23 ( & V_26 -> V_204 ) ;
if ( V_26 -> V_37 -> V_460 ) {
int V_258 = V_26 -> V_11 - V_26 -> V_79 ;
int V_248 = V_258 * ( ( V_26 -> V_257 << 9 )
/ V_414 ) ;
if ( V_26 -> V_37 -> V_460 -> V_462 . V_463 < 2 * V_248 )
V_26 -> V_37 -> V_460 -> V_462 . V_463 = 2 * V_248 ;
}
}
}
static void F_280 ( T_7 * V_37 )
{
T_1 * V_26 = V_37 -> V_240 ;
if ( ! F_12 ( V_241 , & V_37 -> V_242 ) ) {
if ( V_37 -> V_366 > 0 ) {
F_254 ( V_37 , F_199 ( V_37 , 0 , 0 ) ) ;
F_273 ( V_37 -> V_214 , V_37 -> V_476 ) ;
F_274 ( V_37 -> V_214 ) ;
} else {
int V_482 ;
V_37 -> V_76 = V_26 -> V_11 ;
for ( V_482 = 0 ; V_482 < V_26 -> V_11 ; V_482 ++ )
if ( V_26 -> V_9 [ V_482 ] . V_80 &&
F_12 ( V_82 ,
& V_26 -> V_9 [ V_482 ] . V_80 -> V_47 ) )
V_37 -> V_76 -- ;
for ( V_482 = V_26 -> V_11 ;
V_482 < V_26 -> V_11 - V_37 -> V_366 ;
V_482 ++ ) {
T_3 * V_80 = V_26 -> V_9 [ V_482 ] . V_80 ;
if ( V_80 && F_268 ( V_37 , V_482 ) == 0 ) {
F_281 ( V_37 , V_80 ) ;
V_80 -> V_431 = - 1 ;
}
}
}
V_37 -> V_440 = V_26 -> V_253 ;
V_37 -> V_257 = V_26 -> V_257 ;
V_37 -> V_77 = V_78 ;
V_37 -> V_366 = 0 ;
}
}
static void F_282 ( T_7 * V_37 , int V_24 )
{
T_1 * V_26 = V_37 -> V_240 ;
switch( V_24 ) {
case 2 :
F_23 ( & V_26 -> V_204 ) ;
break;
case 1 :
F_54 ( & V_26 -> V_48 ) ;
V_26 -> V_85 = 2 ;
F_55 ( V_26 -> V_44 ,
F_17 ( & V_26 -> V_28 ) == 0 &&
F_17 ( & V_26 -> V_350 ) == 0 ,
V_26 -> V_48 , ) ;
V_26 -> V_85 = 1 ;
F_57 ( & V_26 -> V_48 ) ;
F_23 ( & V_26 -> V_204 ) ;
break;
case 0 :
F_54 ( & V_26 -> V_48 ) ;
V_26 -> V_85 = 0 ;
F_23 ( & V_26 -> V_44 ) ;
F_23 ( & V_26 -> V_204 ) ;
F_57 ( & V_26 -> V_48 ) ;
break;
}
}
static void * F_283 ( T_7 * V_37 , int V_192 )
{
struct V_483 * V_484 = V_37 -> V_240 ;
T_2 V_416 ;
if ( V_484 -> V_485 > 1 ) {
F_44 ( V_73 L_111 ,
F_119 ( V_37 ) ) ;
return F_242 ( - V_412 ) ;
}
V_416 = V_484 -> V_486 [ 0 ] . V_487 ;
F_144 ( V_416 , V_484 -> V_486 [ 0 ] . V_488 ) ;
V_37 -> V_391 = V_416 ;
V_37 -> V_434 = V_192 ;
V_37 -> V_436 = V_264 ;
V_37 -> V_347 = V_37 -> V_257 ;
V_37 -> V_11 += 1 ;
V_37 -> V_366 = 1 ;
V_37 -> V_445 = V_78 ;
return F_241 ( V_37 ) ;
}
static void * F_284 ( T_7 * V_37 )
{
int V_489 ;
if ( V_37 -> V_11 != 2 ||
V_37 -> V_76 > 1 )
return F_242 ( - V_412 ) ;
V_489 = 64 * 2 ;
while ( V_489 && ( V_37 -> V_476 & ( V_489 - 1 ) ) )
V_489 >>= 1 ;
if ( ( V_489 << 9 ) < V_127 )
return F_242 ( - V_412 ) ;
V_37 -> V_434 = 5 ;
V_37 -> V_436 = V_261 ;
V_37 -> V_347 = V_489 ;
return F_241 ( V_37 ) ;
}
static void * F_285 ( T_7 * V_37 )
{
int V_436 ;
switch ( V_37 -> V_440 ) {
case V_268 :
V_436 = V_259 ;
break;
case V_269 :
V_436 = V_260 ;
break;
case V_270 :
V_436 = V_261 ;
break;
case V_271 :
V_436 = V_262 ;
break;
case V_272 :
V_436 = V_263 ;
break;
case V_264 :
V_436 = V_264 ;
break;
default:
return F_242 ( - V_412 ) ;
}
V_37 -> V_434 = 5 ;
V_37 -> V_436 = V_436 ;
V_37 -> V_366 = - 1 ;
V_37 -> V_11 -= 1 ;
return F_241 ( V_37 ) ;
}
static int F_286 ( T_7 * V_37 )
{
T_1 * V_26 = V_37 -> V_240 ;
int V_490 = V_37 -> V_347 ;
if ( V_37 -> V_436 >= 0 && ! F_243 ( V_37 -> V_436 ) )
return - V_412 ;
if ( V_490 > 0 ) {
if ( ! F_245 ( V_490 ) )
return - V_412 ;
if ( V_490 < ( V_414 >> 9 ) )
return - V_412 ;
if ( V_37 -> V_476 & ( V_490 - 1 ) )
return - V_412 ;
}
if ( V_37 -> V_11 == 2 ) {
if ( V_37 -> V_436 >= 0 ) {
V_26 -> V_253 = V_37 -> V_436 ;
V_37 -> V_440 = V_37 -> V_436 ;
}
if ( V_490 > 0 ) {
V_26 -> V_257 = V_490 ;
V_37 -> V_257 = V_490 ;
}
F_61 ( V_244 , & V_37 -> V_47 ) ;
F_20 ( V_37 -> V_38 ) ;
}
return F_276 ( V_37 ) ;
}
static int F_287 ( T_7 * V_37 )
{
int V_490 = V_37 -> V_347 ;
if ( V_37 -> V_436 >= 0 && ! F_244 ( V_37 -> V_436 ) )
return - V_412 ;
if ( V_490 > 0 ) {
if ( ! F_245 ( V_490 ) )
return - V_412 ;
if ( V_490 < ( V_414 >> 9 ) )
return - V_412 ;
if ( V_37 -> V_476 & ( V_490 - 1 ) )
return - V_412 ;
}
return F_276 ( V_37 ) ;
}
static void * F_288 ( T_7 * V_37 )
{
if ( V_37 -> V_192 == 0 )
return F_283 ( V_37 , 5 ) ;
if ( V_37 -> V_192 == 1 )
return F_284 ( V_37 ) ;
if ( V_37 -> V_192 == 4 ) {
V_37 -> V_436 = V_264 ;
V_37 -> V_434 = 5 ;
return F_241 ( V_37 ) ;
}
if ( V_37 -> V_192 == 6 )
return F_285 ( V_37 ) ;
return F_242 ( - V_412 ) ;
}
static void * F_289 ( T_7 * V_37 )
{
if ( V_37 -> V_192 == 0 )
return F_283 ( V_37 , 4 ) ;
if ( V_37 -> V_192 == 5 &&
V_37 -> V_440 == V_264 ) {
V_37 -> V_436 = 0 ;
V_37 -> V_434 = 4 ;
return F_241 ( V_37 ) ;
}
return F_242 ( - V_412 ) ;
}
static void * F_290 ( T_7 * V_37 )
{
int V_436 ;
if ( V_37 -> V_491 != & V_492 )
return F_242 ( - V_412 ) ;
if ( V_37 -> V_76 > 1 )
return F_242 ( - V_412 ) ;
if ( V_37 -> V_11 > 253 )
return F_242 ( - V_412 ) ;
if ( V_37 -> V_11 < 3 )
return F_242 ( - V_412 ) ;
switch ( V_37 -> V_440 ) {
case V_259 :
V_436 = V_268 ;
break;
case V_260 :
V_436 = V_269 ;
break;
case V_261 :
V_436 = V_270 ;
break;
case V_262 :
V_436 = V_271 ;
break;
case V_263 :
V_436 = V_272 ;
break;
case V_264 :
V_436 = V_264 ;
break;
default:
return F_242 ( - V_412 ) ;
}
V_37 -> V_434 = 6 ;
V_37 -> V_436 = V_436 ;
V_37 -> V_366 = 1 ;
V_37 -> V_11 += 1 ;
return F_241 ( V_37 ) ;
}
static int T_10 F_291 ( void )
{
F_292 ( & V_493 ) ;
F_292 ( & V_492 ) ;
F_292 ( & V_494 ) ;
return 0 ;
}
static void F_293 ( void )
{
F_294 ( & V_493 ) ;
F_294 ( & V_492 ) ;
F_294 ( & V_494 ) ;
}
