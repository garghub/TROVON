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
F_40 ( L_5 , ( unsigned long long ) V_10 ) ;
F_57 (sh, stripe_hash(conf, sector), hash)
if ( V_22 -> V_10 == V_10 && V_22 -> V_76 == V_76 )
return V_22 ;
F_40 ( L_6 , ( unsigned long long ) V_10 ) ;
return NULL ;
}
static int F_58 ( struct V_2 * V_3 )
{
int V_85 , V_86 ;
int V_70 ;
F_59 () ;
V_85 = 0 ;
for ( V_70 = 0 ; V_70 < V_3 -> V_77 ; V_70 ++ ) {
struct V_87 * V_88 = F_60 ( V_3 -> V_25 [ V_70 ] . V_88 ) ;
if ( V_88 && F_21 ( V_89 , & V_88 -> V_61 ) )
V_88 = F_60 ( V_3 -> V_25 [ V_70 ] . V_90 ) ;
if ( ! V_88 || F_21 ( V_89 , & V_88 -> V_61 ) )
V_85 ++ ;
else if ( F_21 ( V_91 , & V_88 -> V_61 ) )
;
else
if ( V_3 -> V_27 >= V_3 -> V_77 )
V_85 ++ ;
}
F_61 () ;
if ( V_3 -> V_27 == V_3 -> V_77 )
return V_85 ;
F_59 () ;
V_86 = 0 ;
for ( V_70 = 0 ; V_70 < V_3 -> V_27 ; V_70 ++ ) {
struct V_87 * V_88 = F_60 ( V_3 -> V_25 [ V_70 ] . V_88 ) ;
if ( V_88 && F_21 ( V_89 , & V_88 -> V_61 ) )
V_88 = F_60 ( V_3 -> V_25 [ V_70 ] . V_90 ) ;
if ( ! V_88 || F_21 ( V_89 , & V_88 -> V_61 ) )
V_86 ++ ;
else if ( F_21 ( V_91 , & V_88 -> V_61 ) )
;
else
if ( V_3 -> V_27 <= V_3 -> V_77 )
V_86 ++ ;
}
F_61 () ;
if ( V_86 > V_85 )
return V_86 ;
return V_85 ;
}
static int F_62 ( struct V_2 * V_3 )
{
int V_85 ;
if ( V_3 -> V_52 -> V_92 == V_93 )
return V_3 -> V_52 -> V_85 > V_3 -> V_94 ;
V_85 = F_58 ( V_3 ) ;
if ( V_85 > V_3 -> V_94 )
return 1 ;
return 0 ;
}
static struct V_21 *
F_63 ( struct V_2 * V_3 , T_1 V_10 ,
int V_75 , int V_95 , int V_96 )
{
struct V_21 * V_22 ;
F_40 ( L_7 , ( unsigned long long ) V_10 ) ;
F_64 ( & V_3 -> V_62 ) ;
do {
F_65 ( V_3 -> V_58 ,
V_3 -> V_97 == 0 || V_96 ,
V_3 -> V_62 ) ;
V_22 = F_56 ( V_3 , V_10 , V_3 -> V_76 - V_75 ) ;
if ( ! V_22 ) {
if ( ! V_3 -> V_98 )
V_22 = F_44 ( V_3 ) ;
if ( V_95 && V_22 == NULL )
break;
if ( ! V_22 ) {
V_3 -> V_98 = 1 ;
F_65 ( V_3 -> V_58 ,
! F_24 ( & V_3 -> V_57 ) &&
( F_4 ( & V_3 -> V_42 )
< ( V_3 -> V_99 * 3 / 4 )
|| ! V_3 -> V_98 ) ,
V_3 -> V_62 ) ;
V_3 -> V_98 = 0 ;
} else
F_51 ( V_22 , V_10 , V_75 ) ;
} else {
if ( F_4 ( & V_22 -> V_29 ) ) {
F_23 ( ! F_24 ( & V_22 -> V_41 )
&& ! F_21 ( V_56 , & V_22 -> V_39 )
&& ! F_21 ( V_100 , & V_22 -> V_39 ) ) ;
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
T_1 V_101 = V_3 -> V_102 ;
F_69 () ;
if ( V_101 == V_93 )
return 0 ;
if ( V_22 -> V_76 == V_3 -> V_76 - 1 )
return 0 ;
return 1 ;
}
static void F_70 ( struct V_21 * V_22 , struct V_103 * V_104 )
{
struct V_2 * V_3 = V_22 -> V_60 ;
int V_70 , V_25 = V_22 -> V_25 ;
F_71 () ;
for ( V_70 = V_25 ; V_70 -- ; ) {
int V_105 ;
int V_106 = 0 ;
struct V_9 * V_34 , * V_107 ;
struct V_87 * V_88 , * V_108 = NULL ;
if ( F_28 ( V_109 , & V_22 -> V_73 [ V_70 ] . V_61 ) ) {
if ( F_28 ( V_110 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
V_105 = V_111 ;
else
V_105 = V_112 ;
if ( F_21 ( V_113 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
V_105 |= V_114 ;
} else if ( F_28 ( V_115 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
V_105 = V_116 ;
else if ( F_28 ( V_117 ,
& V_22 -> V_73 [ V_70 ] . V_61 ) ) {
V_105 = V_112 ;
V_106 = 1 ;
} else
continue;
if ( F_28 ( V_118 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
V_105 |= V_119 ;
V_34 = & V_22 -> V_73 [ V_70 ] . V_120 ;
V_107 = & V_22 -> V_73 [ V_70 ] . V_121 ;
V_34 -> V_122 = V_105 ;
V_107 -> V_122 = V_105 ;
if ( V_105 & V_112 ) {
V_34 -> V_123 = V_124 ;
V_107 -> V_123 = V_124 ;
} else
V_34 -> V_123 = V_125 ;
F_59 () ;
V_108 = F_60 ( V_3 -> V_25 [ V_70 ] . V_90 ) ;
F_72 () ;
V_88 = F_60 ( V_3 -> V_25 [ V_70 ] . V_88 ) ;
if ( ! V_88 ) {
V_88 = V_108 ;
V_108 = NULL ;
}
if ( V_105 & V_112 ) {
if ( V_106 )
V_88 = NULL ;
if ( V_88 == V_108 )
V_108 = NULL ;
} else {
if ( F_21 ( V_126 , & V_22 -> V_73 [ V_70 ] . V_61 ) && V_108 )
V_88 = V_108 ;
V_108 = NULL ;
}
if ( V_88 && F_21 ( V_89 , & V_88 -> V_61 ) )
V_88 = NULL ;
if ( V_88 )
F_8 ( & V_88 -> V_127 ) ;
if ( V_108 && F_21 ( V_89 , & V_108 -> V_61 ) )
V_108 = NULL ;
if ( V_108 )
F_8 ( & V_108 -> V_127 ) ;
F_61 () ;
while ( ( V_105 & V_112 ) && V_88 &&
F_21 ( V_128 , & V_88 -> V_61 ) ) {
T_1 V_129 ;
int V_130 ;
int V_131 = F_73 ( V_88 , V_22 -> V_10 , V_14 ,
& V_129 , & V_130 ) ;
if ( ! V_131 )
break;
if ( V_131 < 0 ) {
F_74 ( V_132 , & V_88 -> V_61 ) ;
if ( ! V_3 -> V_52 -> V_133 &&
V_3 -> V_52 -> V_61 ) {
F_75 ( V_3 -> V_52 ) ;
}
F_8 ( & V_88 -> V_127 ) ;
F_76 ( V_88 , V_3 -> V_52 ) ;
} else {
F_77 ( V_88 , V_3 -> V_52 ) ;
V_88 = NULL ;
}
}
if ( V_88 ) {
if ( V_104 -> V_134 || V_104 -> V_135 || V_104 -> V_136
|| V_104 -> V_137 )
F_78 ( V_88 -> V_138 , V_14 ) ;
F_74 ( V_139 , & V_22 -> V_39 ) ;
V_34 -> V_35 = V_88 -> V_138 ;
F_40 ( L_8 ,
V_140 , ( unsigned long long ) V_22 -> V_10 ,
V_34 -> V_122 , V_70 ) ;
F_8 ( & V_22 -> V_29 ) ;
if ( F_68 ( V_3 , V_22 ) )
V_34 -> V_13 = ( V_22 -> V_10
+ V_88 -> V_141 ) ;
else
V_34 -> V_13 = ( V_22 -> V_10
+ V_88 -> V_142 ) ;
if ( F_21 ( V_143 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
V_34 -> V_122 |= V_144 ;
V_34 -> V_145 = 1 << V_146 ;
V_34 -> V_147 = 0 ;
V_34 -> V_148 [ 0 ] . V_149 = V_150 ;
V_34 -> V_148 [ 0 ] . V_151 = 0 ;
V_34 -> V_12 = V_150 ;
V_34 -> V_15 = NULL ;
if ( V_108 )
F_74 ( V_152 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
if ( V_3 -> V_52 -> V_153 )
F_79 ( F_18 ( V_34 -> V_35 ) ,
V_34 , F_80 ( V_3 -> V_52 -> V_153 ) ,
V_22 -> V_73 [ V_70 ] . V_10 ) ;
F_81 ( V_34 ) ;
}
if ( V_108 ) {
if ( V_104 -> V_134 || V_104 -> V_135 || V_104 -> V_136
|| V_104 -> V_137 )
F_78 ( V_108 -> V_138 , V_14 ) ;
F_74 ( V_139 , & V_22 -> V_39 ) ;
V_107 -> V_35 = V_108 -> V_138 ;
F_40 ( L_9
L_10 ,
V_140 , ( unsigned long long ) V_22 -> V_10 ,
V_107 -> V_122 , V_70 ) ;
F_8 ( & V_22 -> V_29 ) ;
if ( F_68 ( V_3 , V_22 ) )
V_107 -> V_13 = ( V_22 -> V_10
+ V_108 -> V_141 ) ;
else
V_107 -> V_13 = ( V_22 -> V_10
+ V_108 -> V_142 ) ;
V_107 -> V_145 = 1 << V_146 ;
V_107 -> V_147 = 0 ;
V_107 -> V_148 [ 0 ] . V_149 = V_150 ;
V_107 -> V_148 [ 0 ] . V_151 = 0 ;
V_107 -> V_12 = V_150 ;
V_107 -> V_15 = NULL ;
if ( V_3 -> V_52 -> V_153 )
F_79 ( F_18 ( V_107 -> V_35 ) ,
V_107 , F_80 ( V_3 -> V_52 -> V_153 ) ,
V_22 -> V_73 [ V_70 ] . V_10 ) ;
F_81 ( V_107 ) ;
}
if ( ! V_88 && ! V_108 ) {
if ( V_105 & V_112 )
F_74 ( V_154 , & V_22 -> V_39 ) ;
F_40 ( L_11 ,
V_34 -> V_122 , V_70 , ( unsigned long long ) V_22 -> V_10 ) ;
F_26 ( V_83 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
}
}
}
static struct V_155 *
F_82 ( int V_156 , struct V_9 * V_9 , struct V_68 * V_68 ,
T_1 V_10 , struct V_155 * V_157 )
{
struct V_158 * V_159 ;
struct V_68 * V_160 ;
int V_70 ;
int V_161 ;
struct V_162 V_163 ;
enum V_164 V_61 = 0 ;
if ( V_9 -> V_13 >= V_10 )
V_161 = ( signed ) ( V_9 -> V_13 - V_10 ) * 512 ;
else
V_161 = ( signed ) ( V_10 - V_9 -> V_13 ) * - 512 ;
if ( V_156 )
V_61 |= V_165 ;
F_83 ( & V_163 , V_61 , V_157 , NULL , NULL , NULL ) ;
F_84 (bvl, bio, i) {
int V_166 = V_159 -> V_149 ;
int V_167 ;
int V_168 = 0 ;
if ( V_161 < 0 ) {
V_168 = - V_161 ;
V_161 += V_168 ;
V_166 -= V_168 ;
}
if ( V_166 > 0 && V_161 + V_166 > V_150 )
V_167 = V_150 - V_161 ;
else
V_167 = V_166 ;
if ( V_167 > 0 ) {
V_168 += V_159 -> V_151 ;
V_160 = V_159 -> V_169 ;
if ( V_156 )
V_157 = F_85 ( V_68 , V_160 , V_161 ,
V_168 , V_167 , & V_163 ) ;
else
V_157 = F_85 ( V_160 , V_68 , V_168 ,
V_161 , V_167 , & V_163 ) ;
}
V_163 . V_170 = V_157 ;
if ( V_167 < V_166 )
break;
V_161 += V_166 ;
}
return V_157 ;
}
static void F_86 ( void * V_171 )
{
struct V_21 * V_22 = V_171 ;
struct V_9 * V_33 = NULL ;
int V_70 ;
F_40 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_70 = V_22 -> V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( F_28 ( V_172 , & V_73 -> V_61 ) ) {
struct V_9 * V_107 , * V_173 ;
F_23 ( ! V_73 -> V_80 ) ;
V_107 = V_73 -> V_80 ;
V_73 -> V_80 = NULL ;
while ( V_107 && V_107 -> V_13 <
V_73 -> V_10 + V_14 ) {
V_173 = F_2 ( V_107 , V_73 -> V_10 ) ;
if ( ! F_5 ( V_107 ) ) {
V_107 -> V_15 = V_33 ;
V_33 = V_107 ;
}
V_107 = V_173 ;
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
struct V_155 * V_157 = NULL ;
struct V_162 V_163 ;
int V_70 ;
F_40 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_70 = V_22 -> V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( F_21 ( V_172 , & V_73 -> V_61 ) ) {
struct V_9 * V_107 ;
F_64 ( & V_22 -> V_174 ) ;
V_73 -> V_80 = V_107 = V_73 -> V_79 ;
V_73 -> V_79 = NULL ;
F_67 ( & V_22 -> V_174 ) ;
while ( V_107 && V_107 -> V_13 <
V_73 -> V_10 + V_14 ) {
V_157 = F_82 ( 0 , V_107 , V_73 -> V_68 ,
V_73 -> V_10 , V_157 ) ;
V_107 = F_2 ( V_107 , V_73 -> V_10 ) ;
}
}
}
F_8 ( & V_22 -> V_29 ) ;
F_83 ( & V_163 , V_175 , V_157 , F_86 , V_22 , NULL ) ;
F_88 ( & V_163 ) ;
}
static void F_89 ( struct V_21 * V_22 , int V_176 )
{
struct V_78 * V_177 ;
if ( V_176 < 0 )
return;
V_177 = & V_22 -> V_73 [ V_176 ] ;
F_74 ( V_178 , & V_177 -> V_61 ) ;
F_23 ( ! F_21 ( V_179 , & V_177 -> V_61 ) ) ;
F_26 ( V_179 , & V_177 -> V_61 ) ;
}
static void F_90 ( void * V_171 )
{
struct V_21 * V_22 = V_171 ;
F_40 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_89 ( V_22 , V_22 -> V_180 . V_176 ) ;
F_89 ( V_22 , V_22 -> V_180 . V_181 ) ;
F_26 ( V_40 , & V_22 -> V_39 ) ;
if ( V_22 -> V_36 == V_182 )
V_22 -> V_36 = V_183 ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_34 ( V_22 ) ;
}
static T_3 * F_91 ( struct V_21 * V_22 ,
struct V_184 * V_185 )
{
return V_185 -> V_186 + sizeof( struct V_68 * ) * ( V_22 -> V_25 + 2 ) ;
}
static struct V_155 *
F_92 ( struct V_21 * V_22 , struct V_184 * V_185 )
{
int V_25 = V_22 -> V_25 ;
struct V_68 * * V_187 = V_185 -> V_186 ;
int V_176 = V_22 -> V_180 . V_176 ;
struct V_78 * V_177 = & V_22 -> V_73 [ V_176 ] ;
struct V_68 * V_188 = V_177 -> V_68 ;
int V_29 = 0 ;
struct V_155 * V_157 ;
struct V_162 V_163 ;
int V_70 ;
F_40 ( L_13 ,
V_140 , ( unsigned long long ) V_22 -> V_10 , V_176 ) ;
F_23 ( ! F_21 ( V_179 , & V_177 -> V_61 ) ) ;
for ( V_70 = V_25 ; V_70 -- ; )
if ( V_70 != V_176 )
V_187 [ V_29 ++ ] = V_22 -> V_73 [ V_70 ] . V_68 ;
F_8 ( & V_22 -> V_29 ) ;
F_83 ( & V_163 , V_165 | V_189 , NULL ,
F_90 , V_22 , F_91 ( V_22 , V_185 ) ) ;
if ( F_93 ( V_29 == 1 ) )
V_157 = F_85 ( V_188 , V_187 [ 0 ] , 0 , 0 , V_150 , & V_163 ) ;
else
V_157 = F_94 ( V_188 , V_187 , 0 , V_29 , V_150 , & V_163 ) ;
return V_157 ;
}
static int F_95 ( struct V_68 * * V_190 , struct V_21 * V_22 )
{
int V_25 = V_22 -> V_25 ;
int V_30 = V_22 -> V_23 ? V_25 : ( V_25 - 2 ) ;
int V_191 = F_13 ( V_22 ) ;
int V_29 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_25 ; V_70 ++ )
V_190 [ V_70 ] = NULL ;
V_29 = 0 ;
V_70 = V_191 ;
do {
int V_31 = F_15 ( V_70 , V_22 , & V_29 , V_30 ) ;
V_190 [ V_31 ] = V_22 -> V_73 [ V_70 ] . V_68 ;
V_70 = F_14 ( V_70 , V_25 ) ;
} while ( V_70 != V_191 );
return V_30 ;
}
static struct V_155 *
F_96 ( struct V_21 * V_22 , struct V_184 * V_185 )
{
int V_25 = V_22 -> V_25 ;
struct V_68 * * V_192 = V_185 -> V_186 ;
int V_176 ;
int V_24 = V_22 -> V_24 ;
struct V_155 * V_157 ;
struct V_162 V_163 ;
struct V_78 * V_177 ;
struct V_68 * V_193 ;
int V_70 ;
int V_29 ;
if ( V_22 -> V_180 . V_176 < 0 )
V_176 = V_22 -> V_180 . V_181 ;
else if ( V_22 -> V_180 . V_181 < 0 )
V_176 = V_22 -> V_180 . V_176 ;
else
F_66 () ;
F_23 ( V_176 < 0 ) ;
F_40 ( L_13 ,
V_140 , ( unsigned long long ) V_22 -> V_10 , V_176 ) ;
V_177 = & V_22 -> V_73 [ V_176 ] ;
F_23 ( ! F_21 ( V_179 , & V_177 -> V_61 ) ) ;
V_193 = V_177 -> V_68 ;
F_8 ( & V_22 -> V_29 ) ;
if ( V_176 == V_24 ) {
V_29 = F_95 ( V_192 , V_22 ) ;
V_192 [ V_29 ] = NULL ;
F_23 ( V_192 [ V_29 + 1 ] != V_193 ) ;
F_83 ( & V_163 , V_165 , NULL ,
F_90 , V_22 ,
F_91 ( V_22 , V_185 ) ) ;
V_157 = F_97 ( V_192 , 0 , V_29 + 2 , V_150 , & V_163 ) ;
} else {
V_29 = 0 ;
for ( V_70 = V_25 ; V_70 -- ; ) {
if ( V_70 == V_176 || V_70 == V_24 )
continue;
V_192 [ V_29 ++ ] = V_22 -> V_73 [ V_70 ] . V_68 ;
}
F_83 ( & V_163 , V_165 | V_189 ,
NULL , F_90 , V_22 ,
F_91 ( V_22 , V_185 ) ) ;
V_157 = F_94 ( V_193 , V_192 , 0 , V_29 , V_150 , & V_163 ) ;
}
return V_157 ;
}
static struct V_155 *
F_98 ( struct V_21 * V_22 , struct V_184 * V_185 )
{
int V_70 , V_29 , V_25 = V_22 -> V_25 ;
int V_30 = V_22 -> V_23 ? V_25 : V_25 - 2 ;
int V_191 = F_13 ( V_22 ) ;
int V_194 = - 1 , V_195 = - 1 ;
int V_176 = V_22 -> V_180 . V_176 ;
int V_181 = V_22 -> V_180 . V_181 ;
struct V_78 * V_177 = & V_22 -> V_73 [ V_176 ] ;
struct V_78 * V_196 = & V_22 -> V_73 [ V_181 ] ;
struct V_155 * V_157 ;
struct V_68 * * V_192 = V_185 -> V_186 ;
struct V_162 V_163 ;
F_40 ( L_14 ,
V_140 , ( unsigned long long ) V_22 -> V_10 , V_176 , V_181 ) ;
F_23 ( V_176 < 0 || V_181 < 0 ) ;
F_23 ( ! F_21 ( V_179 , & V_177 -> V_61 ) ) ;
F_23 ( ! F_21 ( V_179 , & V_196 -> V_61 ) ) ;
for ( V_70 = 0 ; V_70 < V_25 ; V_70 ++ )
V_192 [ V_70 ] = NULL ;
V_29 = 0 ;
V_70 = V_191 ;
do {
int V_31 = F_15 ( V_70 , V_22 , & V_29 , V_30 ) ;
V_192 [ V_31 ] = V_22 -> V_73 [ V_70 ] . V_68 ;
if ( V_70 == V_176 )
V_194 = V_31 ;
if ( V_70 == V_181 )
V_195 = V_31 ;
V_70 = F_14 ( V_70 , V_25 ) ;
} while ( V_70 != V_191 );
F_23 ( V_194 == V_195 ) ;
if ( V_195 < V_194 )
F_99 ( V_194 , V_195 ) ;
F_40 ( L_15 ,
V_140 , ( unsigned long long ) V_22 -> V_10 , V_194 , V_195 ) ;
F_8 ( & V_22 -> V_29 ) ;
if ( V_195 == V_30 + 1 ) {
if ( V_194 == V_30 ) {
F_83 ( & V_163 , V_165 , NULL ,
F_90 , V_22 ,
F_91 ( V_22 , V_185 ) ) ;
return F_97 ( V_192 , 0 , V_30 + 2 ,
V_150 , & V_163 ) ;
} else {
struct V_68 * V_193 ;
int V_197 ;
int V_24 = V_22 -> V_24 ;
if ( V_176 == V_24 )
V_197 = V_181 ;
else
V_197 = V_176 ;
V_29 = 0 ;
for ( V_70 = V_25 ; V_70 -- ; ) {
if ( V_70 == V_197 || V_70 == V_24 )
continue;
V_192 [ V_29 ++ ] = V_22 -> V_73 [ V_70 ] . V_68 ;
}
V_193 = V_22 -> V_73 [ V_197 ] . V_68 ;
F_83 ( & V_163 ,
V_165 | V_189 ,
NULL , NULL , NULL ,
F_91 ( V_22 , V_185 ) ) ;
V_157 = F_94 ( V_193 , V_192 , 0 , V_29 , V_150 ,
& V_163 ) ;
V_29 = F_95 ( V_192 , V_22 ) ;
F_83 ( & V_163 , V_165 , V_157 ,
F_90 , V_22 ,
F_91 ( V_22 , V_185 ) ) ;
return F_97 ( V_192 , 0 , V_29 + 2 ,
V_150 , & V_163 ) ;
}
} else {
F_83 ( & V_163 , V_165 , NULL ,
F_90 , V_22 ,
F_91 ( V_22 , V_185 ) ) ;
if ( V_195 == V_30 ) {
return F_100 ( V_30 + 2 ,
V_150 , V_194 ,
V_192 , & V_163 ) ;
} else {
return F_101 ( V_30 + 2 ,
V_150 , V_194 , V_195 ,
V_192 , & V_163 ) ;
}
}
}
static void F_102 ( void * V_171 )
{
struct V_21 * V_22 = V_171 ;
F_40 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
}
static struct V_155 *
F_103 ( struct V_21 * V_22 , struct V_184 * V_185 ,
struct V_155 * V_157 )
{
int V_25 = V_22 -> V_25 ;
struct V_68 * * V_187 = V_185 -> V_186 ;
int V_29 = 0 , V_32 = V_22 -> V_32 , V_70 ;
struct V_162 V_163 ;
struct V_68 * V_188 = V_187 [ V_29 ++ ] = V_22 -> V_73 [ V_32 ] . V_68 ;
F_40 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( F_21 ( V_198 , & V_73 -> V_61 ) )
V_187 [ V_29 ++ ] = V_73 -> V_68 ;
}
F_83 ( & V_163 , V_165 | V_199 , V_157 ,
F_102 , V_22 , F_91 ( V_22 , V_185 ) ) ;
V_157 = F_94 ( V_188 , V_187 , 0 , V_29 , V_150 , & V_163 ) ;
return V_157 ;
}
static struct V_155 *
F_104 ( struct V_21 * V_22 , struct V_155 * V_157 )
{
int V_25 = V_22 -> V_25 ;
int V_70 ;
F_40 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
struct V_9 * V_200 ;
if ( F_28 ( V_198 , & V_73 -> V_61 ) ) {
struct V_9 * V_201 ;
F_64 ( & V_22 -> V_174 ) ;
V_200 = V_73 -> V_81 ;
V_73 -> V_81 = NULL ;
F_23 ( V_73 -> V_82 ) ;
V_201 = V_73 -> V_82 = V_200 ;
F_67 ( & V_22 -> V_174 ) ;
while ( V_201 && V_201 -> V_13 <
V_73 -> V_10 + V_14 ) {
if ( V_201 -> V_122 & V_202 )
F_74 ( V_110 , & V_73 -> V_61 ) ;
if ( V_201 -> V_122 & V_119 )
F_74 ( V_118 , & V_73 -> V_61 ) ;
if ( V_201 -> V_122 & V_114 )
F_74 ( V_113 , & V_73 -> V_61 ) ;
else
V_157 = F_82 ( 1 , V_201 , V_73 -> V_68 ,
V_73 -> V_10 , V_157 ) ;
V_201 = F_2 ( V_201 , V_73 -> V_10 ) ;
}
}
}
return V_157 ;
}
static void F_105 ( void * V_171 )
{
struct V_21 * V_22 = V_171 ;
int V_25 = V_22 -> V_25 ;
int V_32 = V_22 -> V_32 ;
int V_24 = V_22 -> V_24 ;
int V_70 ;
bool V_203 = false , V_204 = false , V_205 = false ;
F_40 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_70 = V_25 ; V_70 -- ; ) {
V_203 |= F_21 ( V_110 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
V_204 |= F_21 ( V_118 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
V_205 |= F_21 ( V_113 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
}
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( V_73 -> V_82 || V_70 == V_32 || V_70 == V_24 ) {
if ( ! V_205 )
F_74 ( V_178 , & V_73 -> V_61 ) ;
if ( V_203 )
F_74 ( V_110 , & V_73 -> V_61 ) ;
if ( V_204 )
F_74 ( V_118 , & V_73 -> V_61 ) ;
}
}
if ( V_22 -> V_37 == V_206 )
V_22 -> V_37 = V_207 ;
else if ( V_22 -> V_37 == V_208 )
V_22 -> V_37 = V_209 ;
else {
F_23 ( V_22 -> V_37 != V_210 ) ;
V_22 -> V_37 = V_211 ;
}
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_34 ( V_22 ) ;
}
static void
F_106 ( struct V_21 * V_22 , struct V_184 * V_185 ,
struct V_155 * V_157 )
{
int V_25 = V_22 -> V_25 ;
struct V_68 * * V_187 = V_185 -> V_186 ;
struct V_162 V_163 ;
int V_29 = 0 , V_32 = V_22 -> V_32 , V_70 ;
struct V_68 * V_188 ;
int V_212 = 0 ;
unsigned long V_61 ;
F_40 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
for ( V_70 = 0 ; V_70 < V_22 -> V_25 ; V_70 ++ ) {
if ( V_32 == V_70 )
continue;
if ( ! F_21 ( V_113 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
break;
}
if ( V_70 >= V_22 -> V_25 ) {
F_8 ( & V_22 -> V_29 ) ;
F_74 ( V_113 , & V_22 -> V_73 [ V_32 ] . V_61 ) ;
F_105 ( V_22 ) ;
return;
}
if ( V_22 -> V_37 == V_208 ) {
V_212 = 1 ;
V_188 = V_187 [ V_29 ++ ] = V_22 -> V_73 [ V_32 ] . V_68 ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( V_73 -> V_82 )
V_187 [ V_29 ++ ] = V_73 -> V_68 ;
}
} else {
V_188 = V_22 -> V_73 [ V_32 ] . V_68 ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( V_70 != V_32 )
V_187 [ V_29 ++ ] = V_73 -> V_68 ;
}
}
V_61 = V_175 |
( V_212 ? V_199 : V_189 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_83 ( & V_163 , V_61 , V_157 , F_105 , V_22 ,
F_91 ( V_22 , V_185 ) ) ;
if ( F_93 ( V_29 == 1 ) )
V_157 = F_85 ( V_188 , V_187 [ 0 ] , 0 , 0 , V_150 , & V_163 ) ;
else
V_157 = F_94 ( V_188 , V_187 , 0 , V_29 , V_150 , & V_163 ) ;
}
static void
F_107 ( struct V_21 * V_22 , struct V_184 * V_185 ,
struct V_155 * V_157 )
{
struct V_162 V_163 ;
struct V_68 * * V_192 = V_185 -> V_186 ;
int V_29 , V_70 ;
F_40 ( L_12 , V_140 , ( unsigned long long ) V_22 -> V_10 ) ;
for ( V_70 = 0 ; V_70 < V_22 -> V_25 ; V_70 ++ ) {
if ( V_22 -> V_32 == V_70 || V_22 -> V_24 == V_70 )
continue;
if ( ! F_21 ( V_113 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
break;
}
if ( V_70 >= V_22 -> V_25 ) {
F_8 ( & V_22 -> V_29 ) ;
F_74 ( V_113 , & V_22 -> V_73 [ V_22 -> V_32 ] . V_61 ) ;
F_74 ( V_113 , & V_22 -> V_73 [ V_22 -> V_24 ] . V_61 ) ;
F_105 ( V_22 ) ;
return;
}
V_29 = F_95 ( V_192 , V_22 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_83 ( & V_163 , V_175 , V_157 , F_105 ,
V_22 , F_91 ( V_22 , V_185 ) ) ;
F_97 ( V_192 , 0 , V_29 + 2 , V_150 , & V_163 ) ;
}
static void F_108 ( void * V_171 )
{
struct V_21 * V_22 = V_171 ;
F_40 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
V_22 -> V_36 = V_213 ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_34 ( V_22 ) ;
}
static void F_109 ( struct V_21 * V_22 , struct V_184 * V_185 )
{
int V_25 = V_22 -> V_25 ;
int V_32 = V_22 -> V_32 ;
int V_24 = V_22 -> V_24 ;
struct V_68 * V_188 ;
struct V_68 * * V_187 = V_185 -> V_186 ;
struct V_155 * V_157 ;
struct V_162 V_163 ;
int V_29 ;
int V_70 ;
F_40 ( L_12 , V_140 ,
( unsigned long long ) V_22 -> V_10 ) ;
V_29 = 0 ;
V_188 = V_22 -> V_73 [ V_32 ] . V_68 ;
V_187 [ V_29 ++ ] = V_188 ;
for ( V_70 = V_25 ; V_70 -- ; ) {
if ( V_70 == V_32 || V_70 == V_24 )
continue;
V_187 [ V_29 ++ ] = V_22 -> V_73 [ V_70 ] . V_68 ;
}
F_83 ( & V_163 , 0 , NULL , NULL , NULL ,
F_91 ( V_22 , V_185 ) ) ;
V_157 = F_110 ( V_188 , V_187 , 0 , V_29 , V_150 ,
& V_22 -> V_180 . V_214 , & V_163 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_83 ( & V_163 , V_175 , V_157 , F_108 , V_22 , NULL ) ;
V_157 = F_88 ( & V_163 ) ;
}
static void F_111 ( struct V_21 * V_22 , struct V_184 * V_185 , int V_215 )
{
struct V_68 * * V_190 = V_185 -> V_186 ;
struct V_162 V_163 ;
int V_29 ;
F_40 ( L_16 , V_140 ,
( unsigned long long ) V_22 -> V_10 , V_215 ) ;
V_29 = F_95 ( V_190 , V_22 ) ;
if ( ! V_215 )
V_190 [ V_29 ] = NULL ;
F_8 ( & V_22 -> V_29 ) ;
F_83 ( & V_163 , V_175 , NULL , F_108 ,
V_22 , F_91 ( V_22 , V_185 ) ) ;
F_112 ( V_190 , 0 , V_29 + 2 , V_150 ,
& V_22 -> V_180 . V_214 , V_185 -> V_216 , & V_163 ) ;
}
static void F_113 ( struct V_21 * V_22 , unsigned long V_217 )
{
int V_218 = 0 , V_70 , V_25 = V_22 -> V_25 ;
struct V_155 * V_157 = NULL ;
struct V_2 * V_3 = V_22 -> V_60 ;
int V_219 = V_3 -> V_219 ;
struct V_184 * V_185 ;
unsigned long V_220 ;
V_220 = F_114 () ;
V_185 = F_115 ( V_3 -> V_185 , V_220 ) ;
if ( F_21 ( V_221 , & V_217 ) ) {
F_87 ( V_22 ) ;
V_218 ++ ;
}
if ( F_21 ( V_222 , & V_217 ) ) {
if ( V_219 < 6 )
V_157 = F_92 ( V_22 , V_185 ) ;
else {
if ( V_22 -> V_180 . V_181 < 0 || V_22 -> V_180 . V_176 < 0 )
V_157 = F_96 ( V_22 , V_185 ) ;
else
V_157 = F_98 ( V_22 , V_185 ) ;
}
if ( V_157 && ! F_21 ( V_223 , & V_217 ) )
F_116 ( V_157 ) ;
}
if ( F_21 ( V_224 , & V_217 ) )
V_157 = F_103 ( V_22 , V_185 , V_157 ) ;
if ( F_21 ( V_225 , & V_217 ) ) {
V_157 = F_104 ( V_22 , V_157 ) ;
V_218 ++ ;
}
if ( F_21 ( V_223 , & V_217 ) ) {
if ( V_219 < 6 )
F_106 ( V_22 , V_185 , V_157 ) ;
else
F_107 ( V_22 , V_185 , V_157 ) ;
}
if ( F_21 ( V_226 , & V_217 ) ) {
if ( V_22 -> V_36 == V_227 )
F_109 ( V_22 , V_185 ) ;
else if ( V_22 -> V_36 == V_228 )
F_111 ( V_22 , V_185 , 0 ) ;
else if ( V_22 -> V_36 == V_229 )
F_111 ( V_22 , V_185 , 1 ) ;
else
F_66 () ;
}
if ( V_218 )
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( F_28 ( V_230 , & V_73 -> V_61 ) )
F_31 ( & V_22 -> V_60 -> V_231 ) ;
}
F_117 () ;
}
static int F_118 ( struct V_2 * V_3 )
{
struct V_21 * V_22 ;
V_22 = F_119 ( V_3 -> V_232 , V_74 ) ;
if ( ! V_22 )
return 0 ;
V_22 -> V_60 = V_3 ;
F_120 ( & V_22 -> V_174 ) ;
if ( F_49 ( V_22 ) ) {
F_47 ( V_22 ) ;
F_121 ( V_3 -> V_232 , V_22 ) ;
return 0 ;
}
F_12 ( & V_22 -> V_29 , 1 ) ;
F_8 ( & V_3 -> V_42 ) ;
F_122 ( & V_22 -> V_41 ) ;
F_34 ( V_22 ) ;
return 1 ;
}
static int F_123 ( struct V_2 * V_3 , int V_71 )
{
struct V_233 * V_234 ;
int V_235 = F_124 ( V_3 -> V_27 , V_3 -> V_77 ) ;
if ( V_3 -> V_52 -> V_153 )
sprintf ( V_3 -> V_236 [ 0 ] ,
L_17 , V_3 -> V_219 , F_125 ( V_3 -> V_52 ) ) ;
else
sprintf ( V_3 -> V_236 [ 0 ] ,
L_18 , V_3 -> V_219 , V_3 -> V_52 ) ;
sprintf ( V_3 -> V_236 [ 1 ] , L_19 , V_3 -> V_236 [ 0 ] ) ;
V_3 -> V_237 = 0 ;
V_234 = F_126 ( V_3 -> V_236 [ V_3 -> V_237 ] ,
sizeof( struct V_21 ) + ( V_235 - 1 ) * sizeof( struct V_78 ) ,
0 , 0 , NULL ) ;
if ( ! V_234 )
return 1 ;
V_3 -> V_232 = V_234 ;
V_3 -> V_72 = V_235 ;
while ( V_71 -- )
if ( ! F_118 ( V_3 ) )
return 1 ;
return 0 ;
}
static T_4 F_127 ( int V_71 )
{
T_4 V_166 ;
V_166 = sizeof( struct V_68 * ) * ( V_71 + 2 ) + sizeof( T_3 ) * ( V_71 + 2 ) ;
return V_166 ;
}
static int F_128 ( struct V_2 * V_3 , int V_238 )
{
struct V_21 * V_239 , * V_240 ;
F_129 ( V_241 ) ;
struct V_242 * V_243 ;
unsigned long V_220 ;
int V_244 ;
struct V_233 * V_234 ;
int V_70 ;
if ( V_238 <= V_3 -> V_72 )
return 0 ;
V_244 = F_130 ( V_3 -> V_52 ) ;
if ( V_244 )
return V_244 ;
V_234 = F_126 ( V_3 -> V_236 [ 1 - V_3 -> V_237 ] ,
sizeof( struct V_21 ) + ( V_238 - 1 ) * sizeof( struct V_78 ) ,
0 , 0 , NULL ) ;
if ( ! V_234 )
return - V_245 ;
for ( V_70 = V_3 -> V_99 ; V_70 ; V_70 -- ) {
V_240 = F_119 ( V_234 , V_74 ) ;
if ( ! V_240 )
break;
V_240 -> V_60 = V_3 ;
F_120 ( & V_240 -> V_174 ) ;
F_131 ( & V_240 -> V_41 , & V_241 ) ;
}
if ( V_70 ) {
while ( ! F_24 ( & V_241 ) ) {
V_240 = F_45 ( V_241 . V_67 , struct V_21 , V_41 ) ;
F_132 ( & V_240 -> V_41 ) ;
F_121 ( V_234 , V_240 ) ;
}
F_133 ( V_234 ) ;
return - V_245 ;
}
F_134 (nsh, &newstripes, lru) {
F_64 ( & V_3 -> V_62 ) ;
F_65 ( V_3 -> V_58 ,
! F_24 ( & V_3 -> V_57 ) ,
V_3 -> V_62 ) ;
V_239 = F_44 ( V_3 ) ;
F_67 ( & V_3 -> V_62 ) ;
F_12 ( & V_240 -> V_29 , 1 ) ;
for( V_70 = 0 ; V_70 < V_3 -> V_72 ; V_70 ++ )
V_240 -> V_73 [ V_70 ] . V_68 = V_239 -> V_73 [ V_70 ] . V_68 ;
for( ; V_70 < V_238 ; V_70 ++ )
V_240 -> V_73 [ V_70 ] . V_68 = NULL ;
F_121 ( V_3 -> V_232 , V_239 ) ;
}
F_133 ( V_3 -> V_232 ) ;
V_243 = F_135 ( V_238 * sizeof( struct V_242 ) , V_246 ) ;
if ( V_243 ) {
for ( V_70 = 0 ; V_70 < V_3 -> V_27 ; V_70 ++ )
V_243 [ V_70 ] = V_3 -> V_25 [ V_70 ] ;
F_136 ( V_3 -> V_25 ) ;
V_3 -> V_25 = V_243 ;
} else
V_244 = - V_245 ;
F_137 () ;
V_3 -> F_127 = F_127 ( V_238 ) ;
F_138 (cpu) {
struct V_184 * V_185 ;
void * V_186 ;
V_185 = F_115 ( V_3 -> V_185 , V_220 ) ;
V_186 = F_139 ( V_3 -> F_127 , V_246 ) ;
if ( V_186 ) {
F_136 ( V_185 -> V_186 ) ;
V_185 -> V_186 = V_186 ;
} else {
V_244 = - V_245 ;
break;
}
}
F_140 () ;
while( ! F_24 ( & V_241 ) ) {
V_240 = F_45 ( V_241 . V_67 , struct V_21 , V_41 ) ;
F_46 ( & V_240 -> V_41 ) ;
for ( V_70 = V_3 -> V_27 ; V_70 < V_238 ; V_70 ++ )
if ( V_240 -> V_73 [ V_70 ] . V_68 == NULL ) {
struct V_68 * V_69 = F_50 ( V_246 ) ;
V_240 -> V_73 [ V_70 ] . V_68 = V_69 ;
if ( ! V_69 )
V_244 = - V_245 ;
}
F_34 ( V_240 ) ;
}
V_3 -> V_232 = V_234 ;
V_3 -> V_237 = 1 - V_3 -> V_237 ;
V_3 -> V_72 = V_238 ;
return V_244 ;
}
static int F_141 ( struct V_2 * V_3 )
{
struct V_21 * V_22 ;
F_64 ( & V_3 -> V_62 ) ;
V_22 = F_44 ( V_3 ) ;
F_67 ( & V_3 -> V_62 ) ;
if ( ! V_22 )
return 0 ;
F_23 ( F_4 ( & V_22 -> V_29 ) ) ;
F_47 ( V_22 ) ;
F_121 ( V_3 -> V_232 , V_22 ) ;
F_30 ( & V_3 -> V_42 ) ;
return 1 ;
}
static void F_142 ( struct V_2 * V_3 )
{
while ( F_141 ( V_3 ) )
;
if ( V_3 -> V_232 )
F_133 ( V_3 -> V_232 ) ;
V_3 -> V_232 = NULL ;
}
static void V_125 ( struct V_9 * V_34 , int error )
{
struct V_21 * V_22 = V_34 -> V_247 ;
struct V_2 * V_3 = V_22 -> V_60 ;
int V_25 = V_22 -> V_25 , V_70 ;
int V_248 = F_21 ( V_146 , & V_34 -> V_145 ) ;
char V_249 [ V_250 ] ;
struct V_87 * V_88 = NULL ;
T_1 V_104 ;
for ( V_70 = 0 ; V_70 < V_25 ; V_70 ++ )
if ( V_34 == & V_22 -> V_73 [ V_70 ] . V_120 )
break;
F_40 ( L_20 ,
( unsigned long long ) V_22 -> V_10 , V_70 , F_4 ( & V_22 -> V_29 ) ,
V_248 ) ;
if ( V_70 == V_25 ) {
F_66 () ;
return;
}
if ( F_21 ( V_126 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
V_88 = V_3 -> V_25 [ V_70 ] . V_90 ;
if ( ! V_88 )
V_88 = V_3 -> V_25 [ V_70 ] . V_88 ;
if ( F_68 ( V_3 , V_22 ) )
V_104 = V_22 -> V_10 + V_88 -> V_141 ;
else
V_104 = V_22 -> V_10 + V_88 -> V_142 ;
if ( V_248 ) {
F_74 ( V_178 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
if ( F_21 ( V_251 , & V_22 -> V_73 [ V_70 ] . V_61 ) ) {
F_143 (
V_252
L_21
L_22 ,
F_125 ( V_3 -> V_52 ) , V_14 ,
( unsigned long long ) V_104 ,
F_144 ( V_88 -> V_138 , V_249 ) ) ;
F_145 ( V_14 , & V_88 -> V_253 ) ;
F_26 ( V_251 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_26 ( V_254 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
} else if ( F_21 ( V_143 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
F_26 ( V_143 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
if ( F_4 ( & V_88 -> V_255 ) )
F_12 ( & V_88 -> V_255 , 0 ) ;
} else {
const char * V_256 = F_144 ( V_88 -> V_138 , V_249 ) ;
int V_257 = 0 ;
int V_258 = 0 ;
F_26 ( V_178 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_8 ( & V_88 -> V_255 ) ;
if ( F_21 ( V_126 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
F_143 (
V_259
L_23
L_24 ,
F_125 ( V_3 -> V_52 ) ,
( unsigned long long ) V_104 ,
V_256 ) ;
else if ( V_3 -> V_52 -> V_85 >= V_3 -> V_94 ) {
V_258 = 1 ;
F_143 (
V_259
L_25
L_24 ,
F_125 ( V_3 -> V_52 ) ,
( unsigned long long ) V_104 ,
V_256 ) ;
} else if ( F_21 ( V_254 , & V_22 -> V_73 [ V_70 ] . V_61 ) ) {
V_258 = 1 ;
F_143 (
V_259
L_26
L_24 ,
F_125 ( V_3 -> V_52 ) ,
( unsigned long long ) V_104 ,
V_256 ) ;
} else if ( F_4 ( & V_88 -> V_255 )
> V_3 -> V_99 )
F_53 ( V_259
L_27 ,
F_125 ( V_3 -> V_52 ) , V_256 ) ;
else
V_257 = 1 ;
if ( V_257 )
if ( F_21 ( V_143 , & V_22 -> V_73 [ V_70 ] . V_61 ) ) {
F_74 ( V_251 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_26 ( V_143 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
} else
F_74 ( V_143 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
else {
F_26 ( V_251 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_26 ( V_254 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
if ( ! ( V_258
&& F_21 ( V_91 , & V_88 -> V_61 )
&& F_146 (
V_88 , V_22 -> V_10 , V_14 , 0 ) ) )
F_147 ( V_3 -> V_52 , V_88 ) ;
}
}
F_77 ( V_88 , V_3 -> V_52 ) ;
F_26 ( V_83 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_34 ( V_22 ) ;
}
static void V_124 ( struct V_9 * V_34 , int error )
{
struct V_21 * V_22 = V_34 -> V_247 ;
struct V_2 * V_3 = V_22 -> V_60 ;
int V_25 = V_22 -> V_25 , V_70 ;
struct V_87 * V_260 ( V_88 ) ;
int V_248 = F_21 ( V_146 , & V_34 -> V_145 ) ;
T_1 V_129 ;
int V_130 ;
int V_90 = 0 ;
for ( V_70 = 0 ; V_70 < V_25 ; V_70 ++ ) {
if ( V_34 == & V_22 -> V_73 [ V_70 ] . V_120 ) {
V_88 = V_3 -> V_25 [ V_70 ] . V_88 ;
break;
}
if ( V_34 == & V_22 -> V_73 [ V_70 ] . V_121 ) {
V_88 = V_3 -> V_25 [ V_70 ] . V_90 ;
if ( V_88 )
V_90 = 1 ;
else
V_88 = V_3 -> V_25 [ V_70 ] . V_88 ;
break;
}
}
F_40 ( L_28 ,
( unsigned long long ) V_22 -> V_10 , V_70 , F_4 ( & V_22 -> V_29 ) ,
V_248 ) ;
if ( V_70 == V_25 ) {
F_66 () ;
return;
}
if ( V_90 ) {
if ( ! V_248 )
F_147 ( V_3 -> V_52 , V_88 ) ;
else if ( F_73 ( V_88 , V_22 -> V_10 ,
V_14 ,
& V_129 , & V_130 ) )
F_74 ( V_261 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
} else {
if ( ! V_248 ) {
F_74 ( V_128 , & V_88 -> V_61 ) ;
F_74 ( V_262 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
if ( ! F_148 ( V_263 , & V_88 -> V_61 ) )
F_74 ( V_264 ,
& V_88 -> V_52 -> V_265 ) ;
} else if ( F_73 ( V_88 , V_22 -> V_10 ,
V_14 ,
& V_129 , & V_130 ) )
F_74 ( V_266 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
}
F_77 ( V_88 , V_3 -> V_52 ) ;
if ( ! F_28 ( V_152 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
F_26 ( V_83 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_34 ( V_22 ) ;
}
static void F_55 ( struct V_21 * V_22 , int V_70 , int V_75 )
{
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
F_149 ( & V_73 -> V_120 ) ;
V_73 -> V_120 . V_148 = & V_73 -> V_267 ;
V_73 -> V_120 . V_268 ++ ;
V_73 -> V_120 . V_269 ++ ;
V_73 -> V_120 . V_247 = V_22 ;
V_73 -> V_267 . V_169 = V_73 -> V_68 ;
F_149 ( & V_73 -> V_121 ) ;
V_73 -> V_121 . V_148 = & V_73 -> V_270 ;
V_73 -> V_121 . V_268 ++ ;
V_73 -> V_121 . V_269 ++ ;
V_73 -> V_121 . V_247 = V_22 ;
V_73 -> V_270 . V_169 = V_73 -> V_68 ;
V_73 -> V_61 = 0 ;
V_73 -> V_10 = F_150 ( V_22 , V_70 , V_75 ) ;
}
static void error ( struct V_52 * V_52 , struct V_87 * V_88 )
{
char V_249 [ V_250 ] ;
struct V_2 * V_3 = V_52 -> V_271 ;
unsigned long V_61 ;
F_40 ( L_29 ) ;
F_151 ( & V_3 -> V_62 , V_61 ) ;
F_26 ( V_91 , & V_88 -> V_61 ) ;
V_52 -> V_85 = F_58 ( V_3 ) ;
F_152 ( & V_3 -> V_62 , V_61 ) ;
F_74 ( V_272 , & V_52 -> V_265 ) ;
F_74 ( V_273 , & V_88 -> V_61 ) ;
F_74 ( V_89 , & V_88 -> V_61 ) ;
F_74 ( V_274 , & V_52 -> V_61 ) ;
F_53 ( V_275
L_30
L_31 ,
F_125 ( V_52 ) ,
F_144 ( V_88 -> V_138 , V_249 ) ,
F_125 ( V_52 ) ,
V_3 -> V_27 - V_52 -> V_85 ) ;
}
static T_1 F_153 ( struct V_2 * V_3 , T_1 V_276 ,
int V_75 , int * V_277 ,
struct V_21 * V_22 )
{
T_1 V_278 , V_279 ;
T_1 V_280 ;
unsigned int V_281 ;
int V_32 , V_24 ;
int V_23 = 0 ;
T_1 V_282 ;
int V_283 = V_75 ? V_3 -> V_284
: V_3 -> V_283 ;
int V_285 = V_75 ? V_3 -> V_286
: V_3 -> V_287 ;
int V_27 = V_75 ? V_3 -> V_77
: V_3 -> V_27 ;
int V_288 = V_27 - V_3 -> V_94 ;
V_281 = F_154 ( V_276 , V_285 ) ;
V_280 = V_276 ;
V_278 = V_280 ;
* V_277 = F_154 ( V_278 , V_288 ) ;
V_279 = V_278 ;
V_32 = V_24 = - 1 ;
switch( V_3 -> V_219 ) {
case 4 :
V_32 = V_288 ;
break;
case 5 :
switch ( V_283 ) {
case V_289 :
V_32 = V_288 - F_154 ( V_279 , V_27 ) ;
if ( * V_277 >= V_32 )
( * V_277 ) ++ ;
break;
case V_290 :
V_32 = F_154 ( V_279 , V_27 ) ;
if ( * V_277 >= V_32 )
( * V_277 ) ++ ;
break;
case V_291 :
V_32 = V_288 - F_154 ( V_279 , V_27 ) ;
* V_277 = ( V_32 + 1 + * V_277 ) % V_27 ;
break;
case V_292 :
V_32 = F_154 ( V_279 , V_27 ) ;
* V_277 = ( V_32 + 1 + * V_277 ) % V_27 ;
break;
case V_293 :
V_32 = 0 ;
( * V_277 ) ++ ;
break;
case V_294 :
V_32 = V_288 ;
break;
default:
F_66 () ;
}
break;
case 6 :
switch ( V_283 ) {
case V_289 :
V_32 = V_27 - 1 - F_154 ( V_279 , V_27 ) ;
V_24 = V_32 + 1 ;
if ( V_32 == V_27 - 1 ) {
( * V_277 ) ++ ;
V_24 = 0 ;
} else if ( * V_277 >= V_32 )
( * V_277 ) += 2 ;
break;
case V_290 :
V_32 = F_154 ( V_279 , V_27 ) ;
V_24 = V_32 + 1 ;
if ( V_32 == V_27 - 1 ) {
( * V_277 ) ++ ;
V_24 = 0 ;
} else if ( * V_277 >= V_32 )
( * V_277 ) += 2 ;
break;
case V_291 :
V_32 = V_27 - 1 - F_154 ( V_279 , V_27 ) ;
V_24 = ( V_32 + 1 ) % V_27 ;
* V_277 = ( V_32 + 2 + * V_277 ) % V_27 ;
break;
case V_292 :
V_32 = F_154 ( V_279 , V_27 ) ;
V_24 = ( V_32 + 1 ) % V_27 ;
* V_277 = ( V_32 + 2 + * V_277 ) % V_27 ;
break;
case V_293 :
V_32 = 0 ;
V_24 = 1 ;
( * V_277 ) += 2 ;
break;
case V_294 :
V_32 = V_288 ;
V_24 = V_288 + 1 ;
break;
case V_295 :
V_32 = F_154 ( V_279 , V_27 ) ;
V_24 = V_32 + 1 ;
if ( V_32 == V_27 - 1 ) {
( * V_277 ) ++ ;
V_24 = 0 ;
} else if ( * V_277 >= V_32 )
( * V_277 ) += 2 ;
V_23 = 1 ;
break;
case V_296 :
V_279 += 1 ;
V_32 = V_27 - 1 - F_154 ( V_279 , V_27 ) ;
V_24 = V_32 + 1 ;
if ( V_32 == V_27 - 1 ) {
( * V_277 ) ++ ;
V_24 = 0 ;
} else if ( * V_277 >= V_32 )
( * V_277 ) += 2 ;
V_23 = 1 ;
break;
case V_297 :
V_32 = V_27 - 1 - F_154 ( V_279 , V_27 ) ;
V_24 = ( V_32 + V_27 - 1 ) % V_27 ;
* V_277 = ( V_32 + 1 + * V_277 ) % V_27 ;
V_23 = 1 ;
break;
case V_298 :
V_32 = V_288 - F_154 ( V_279 , V_27 - 1 ) ;
if ( * V_277 >= V_32 )
( * V_277 ) ++ ;
V_24 = V_27 - 1 ;
break;
case V_299 :
V_32 = F_154 ( V_279 , V_27 - 1 ) ;
if ( * V_277 >= V_32 )
( * V_277 ) ++ ;
V_24 = V_27 - 1 ;
break;
case V_300 :
V_32 = V_288 - F_154 ( V_279 , V_27 - 1 ) ;
* V_277 = ( V_32 + 1 + * V_277 ) % ( V_27 - 1 ) ;
V_24 = V_27 - 1 ;
break;
case V_301 :
V_32 = F_154 ( V_279 , V_27 - 1 ) ;
* V_277 = ( V_32 + 1 + * V_277 ) % ( V_27 - 1 ) ;
V_24 = V_27 - 1 ;
break;
case V_302 :
V_32 = 0 ;
( * V_277 ) ++ ;
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
V_282 = ( T_1 ) V_278 * V_285 + V_281 ;
return V_282 ;
}
static T_1 F_150 ( struct V_21 * V_22 , int V_70 , int V_75 )
{
struct V_2 * V_3 = V_22 -> V_60 ;
int V_27 = V_22 -> V_25 ;
int V_288 = V_27 - V_3 -> V_94 ;
T_1 V_282 = V_22 -> V_10 , V_303 ;
int V_285 = V_75 ? V_3 -> V_286
: V_3 -> V_287 ;
int V_283 = V_75 ? V_3 -> V_284
: V_3 -> V_283 ;
T_1 V_278 ;
int V_281 ;
T_1 V_280 ;
int V_304 , V_277 = V_70 ;
T_1 V_276 ;
struct V_21 V_305 ;
V_281 = F_154 ( V_282 , V_285 ) ;
V_278 = V_282 ;
if ( V_70 == V_22 -> V_32 )
return 0 ;
switch( V_3 -> V_219 ) {
case 4 : break;
case 5 :
switch ( V_283 ) {
case V_289 :
case V_290 :
if ( V_70 > V_22 -> V_32 )
V_70 -- ;
break;
case V_291 :
case V_292 :
if ( V_70 < V_22 -> V_32 )
V_70 += V_27 ;
V_70 -= ( V_22 -> V_32 + 1 ) ;
break;
case V_293 :
V_70 -= 1 ;
break;
case V_294 :
break;
default:
F_66 () ;
}
break;
case 6 :
if ( V_70 == V_22 -> V_24 )
return 0 ;
switch ( V_283 ) {
case V_289 :
case V_290 :
case V_295 :
case V_296 :
if ( V_22 -> V_32 == V_27 - 1 )
V_70 -- ;
else if ( V_70 > V_22 -> V_32 )
V_70 -= 2 ;
break;
case V_291 :
case V_292 :
if ( V_22 -> V_32 == V_27 - 1 )
V_70 -- ;
else {
if ( V_70 < V_22 -> V_32 )
V_70 += V_27 ;
V_70 -= ( V_22 -> V_32 + 2 ) ;
}
break;
case V_293 :
V_70 -= 2 ;
break;
case V_294 :
break;
case V_297 :
if ( V_22 -> V_32 == 0 )
V_70 -- ;
else {
if ( V_70 < V_22 -> V_32 )
V_70 += V_27 ;
V_70 -= ( V_22 -> V_32 + 1 ) ;
}
break;
case V_298 :
case V_299 :
if ( V_70 > V_22 -> V_32 )
V_70 -- ;
break;
case V_300 :
case V_301 :
if ( V_70 < V_22 -> V_32 )
V_70 += V_288 + 1 ;
V_70 -= ( V_22 -> V_32 + 1 ) ;
break;
case V_302 :
V_70 -= 1 ;
break;
default:
F_66 () ;
}
break;
}
V_280 = V_278 * V_288 + V_70 ;
V_276 = V_280 * V_285 + V_281 ;
V_303 = F_153 ( V_3 , V_276 ,
V_75 , & V_304 , & V_305 ) ;
if ( V_303 != V_22 -> V_10 || V_304 != V_277 || V_305 . V_32 != V_22 -> V_32
|| V_305 . V_24 != V_22 -> V_24 ) {
F_53 ( V_84 L_32 ,
F_125 ( V_3 -> V_52 ) ) ;
return 0 ;
}
return V_276 ;
}
static void
F_155 ( struct V_21 * V_22 , struct V_103 * V_104 ,
int V_306 , int V_307 )
{
int V_70 , V_32 = V_22 -> V_32 , V_25 = V_22 -> V_25 ;
struct V_2 * V_3 = V_22 -> V_60 ;
int V_219 = V_3 -> V_219 ;
if ( V_306 ) {
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( V_73 -> V_81 ) {
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_74 ( V_198 , & V_73 -> V_61 ) ;
if ( ! V_307 )
F_26 ( V_178 , & V_73 -> V_61 ) ;
V_104 -> V_308 ++ ;
}
}
if ( ! V_307 ) {
if ( ! V_104 -> V_308 )
return;
V_22 -> V_37 = V_206 ;
F_74 ( V_225 , & V_104 -> V_217 ) ;
} else
V_22 -> V_37 = V_210 ;
F_74 ( V_223 , & V_104 -> V_217 ) ;
if ( V_104 -> V_308 + V_3 -> V_94 == V_25 )
if ( ! F_148 ( V_309 , & V_22 -> V_39 ) )
F_8 ( & V_3 -> V_310 ) ;
} else {
F_23 ( V_219 == 6 ) ;
F_23 ( ! ( F_21 ( V_178 , & V_22 -> V_73 [ V_32 ] . V_61 ) ||
F_21 ( V_179 , & V_22 -> V_73 [ V_32 ] . V_61 ) ) ) ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( V_70 == V_32 )
continue;
if ( V_73 -> V_81 &&
( F_21 ( V_178 , & V_73 -> V_61 ) ||
F_21 ( V_179 , & V_73 -> V_61 ) ) ) {
F_74 ( V_198 , & V_73 -> V_61 ) ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_26 ( V_178 , & V_73 -> V_61 ) ;
V_104 -> V_308 ++ ;
}
}
if ( ! V_104 -> V_308 )
return;
V_22 -> V_37 = V_208 ;
F_74 ( V_224 , & V_104 -> V_217 ) ;
F_74 ( V_225 , & V_104 -> V_217 ) ;
F_74 ( V_223 , & V_104 -> V_217 ) ;
}
F_74 ( V_83 , & V_22 -> V_73 [ V_32 ] . V_61 ) ;
F_26 ( V_178 , & V_22 -> V_73 [ V_32 ] . V_61 ) ;
V_104 -> V_308 ++ ;
if ( V_219 == 6 ) {
int V_24 = V_22 -> V_24 ;
struct V_78 * V_73 = & V_22 -> V_73 [ V_24 ] ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_26 ( V_178 , & V_73 -> V_61 ) ;
V_104 -> V_308 ++ ;
}
F_40 ( L_33 ,
V_140 , ( unsigned long long ) V_22 -> V_10 ,
V_104 -> V_308 , V_104 -> V_217 ) ;
}
static int F_156 ( struct V_21 * V_22 , struct V_9 * V_34 , int V_277 , int V_311 )
{
struct V_9 * * V_312 ;
struct V_2 * V_3 = V_22 -> V_60 ;
int V_313 = 0 ;
F_40 ( L_34 ,
( unsigned long long ) V_34 -> V_13 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_64 ( & V_22 -> V_174 ) ;
if ( V_311 ) {
V_312 = & V_22 -> V_73 [ V_277 ] . V_81 ;
if ( * V_312 == NULL )
V_313 = 1 ;
} else
V_312 = & V_22 -> V_73 [ V_277 ] . V_79 ;
while ( * V_312 && ( * V_312 ) -> V_13 < V_34 -> V_13 ) {
if ( ( * V_312 ) -> V_13 + ( ( * V_312 ) -> V_12 >> 9 ) > V_34 -> V_13 )
goto V_314;
V_312 = & ( * V_312 ) -> V_15 ;
}
if ( * V_312 && ( * V_312 ) -> V_13 < V_34 -> V_13 + ( ( V_34 -> V_12 ) >> 9 ) )
goto V_314;
F_23 ( * V_312 && V_34 -> V_15 && ( * V_312 ) != V_34 -> V_15 ) ;
if ( * V_312 )
V_34 -> V_15 = * V_312 ;
* V_312 = V_34 ;
F_7 ( V_34 ) ;
if ( V_311 ) {
T_1 V_10 = V_22 -> V_73 [ V_277 ] . V_10 ;
for ( V_34 = V_22 -> V_73 [ V_277 ] . V_81 ;
V_10 < V_22 -> V_73 [ V_277 ] . V_10 + V_14 &&
V_34 && V_34 -> V_13 <= V_10 ;
V_34 = F_2 ( V_34 , V_22 -> V_73 [ V_277 ] . V_10 ) ) {
if ( V_34 -> V_13 + ( V_34 -> V_12 >> 9 ) >= V_10 )
V_10 = V_34 -> V_13 + ( V_34 -> V_12 >> 9 ) ;
}
if ( V_10 >= V_22 -> V_73 [ V_277 ] . V_10 + V_14 )
F_74 ( V_315 , & V_22 -> V_73 [ V_277 ] . V_61 ) ;
}
F_40 ( L_35 ,
( unsigned long long ) ( * V_312 ) -> V_13 ,
( unsigned long long ) V_22 -> V_10 , V_277 ) ;
F_67 ( & V_22 -> V_174 ) ;
if ( V_3 -> V_52 -> V_316 && V_313 ) {
F_157 ( V_3 -> V_52 -> V_316 , V_22 -> V_10 ,
V_14 , 0 ) ;
V_22 -> V_48 = V_3 -> V_317 + 1 ;
F_74 ( V_47 , & V_22 -> V_39 ) ;
}
return 1 ;
V_314:
F_74 ( V_230 , & V_22 -> V_73 [ V_277 ] . V_61 ) ;
F_67 ( & V_22 -> V_174 ) ;
return 0 ;
}
static void F_52 ( T_1 V_278 , struct V_2 * V_3 , int V_75 ,
struct V_21 * V_22 )
{
int V_285 =
V_75 ? V_3 -> V_286 : V_3 -> V_287 ;
int V_277 ;
int V_281 = F_154 ( V_278 , V_285 ) ;
int V_25 = V_75 ? V_3 -> V_77 : V_3 -> V_27 ;
F_153 ( V_3 ,
V_278 * ( V_25 - V_3 -> V_94 )
* V_285 + V_281 ,
V_75 ,
& V_277 , V_22 ) ;
}
static void
F_158 ( struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_103 * V_104 , int V_25 ,
struct V_9 * * V_33 )
{
int V_70 ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_9 * V_34 ;
int V_318 = 0 ;
if ( F_21 ( V_251 , & V_22 -> V_73 [ V_70 ] . V_61 ) ) {
struct V_87 * V_88 ;
F_59 () ;
V_88 = F_60 ( V_3 -> V_25 [ V_70 ] . V_88 ) ;
if ( V_88 && F_21 ( V_91 , & V_88 -> V_61 ) )
F_8 ( & V_88 -> V_127 ) ;
else
V_88 = NULL ;
F_61 () ;
if ( V_88 ) {
if ( ! F_146 (
V_88 ,
V_22 -> V_10 ,
V_14 , 0 ) )
F_147 ( V_3 -> V_52 , V_88 ) ;
F_77 ( V_88 , V_3 -> V_52 ) ;
}
}
F_64 ( & V_22 -> V_174 ) ;
V_34 = V_22 -> V_73 [ V_70 ] . V_81 ;
V_22 -> V_73 [ V_70 ] . V_81 = NULL ;
F_67 ( & V_22 -> V_174 ) ;
if ( V_34 )
V_318 = 1 ;
if ( F_28 ( V_230 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
F_31 ( & V_3 -> V_231 ) ;
while ( V_34 && V_34 -> V_13 <
V_22 -> V_73 [ V_70 ] . V_10 + V_14 ) {
struct V_9 * V_319 = F_2 ( V_34 , V_22 -> V_73 [ V_70 ] . V_10 ) ;
F_26 ( V_146 , & V_34 -> V_145 ) ;
if ( ! F_5 ( V_34 ) ) {
F_159 ( V_3 -> V_52 ) ;
V_34 -> V_15 = * V_33 ;
* V_33 = V_34 ;
}
V_34 = V_319 ;
}
if ( V_318 )
F_160 ( V_3 -> V_52 -> V_316 , V_22 -> V_10 ,
V_14 , 0 , 0 ) ;
V_318 = 0 ;
V_34 = V_22 -> V_73 [ V_70 ] . V_82 ;
V_22 -> V_73 [ V_70 ] . V_82 = NULL ;
if ( V_34 ) V_318 = 1 ;
while ( V_34 && V_34 -> V_13 <
V_22 -> V_73 [ V_70 ] . V_10 + V_14 ) {
struct V_9 * V_320 = F_2 ( V_34 , V_22 -> V_73 [ V_70 ] . V_10 ) ;
F_26 ( V_146 , & V_34 -> V_145 ) ;
if ( ! F_5 ( V_34 ) ) {
F_159 ( V_3 -> V_52 ) ;
V_34 -> V_15 = * V_33 ;
* V_33 = V_34 ;
}
V_34 = V_320 ;
}
if ( ! F_21 ( V_172 , & V_22 -> V_73 [ V_70 ] . V_61 ) &&
( ! F_21 ( V_321 , & V_22 -> V_73 [ V_70 ] . V_61 ) ||
F_21 ( V_251 , & V_22 -> V_73 [ V_70 ] . V_61 ) ) ) {
F_64 ( & V_22 -> V_174 ) ;
V_34 = V_22 -> V_73 [ V_70 ] . V_79 ;
V_22 -> V_73 [ V_70 ] . V_79 = NULL ;
F_67 ( & V_22 -> V_174 ) ;
if ( F_28 ( V_230 , & V_22 -> V_73 [ V_70 ] . V_61 ) )
F_31 ( & V_3 -> V_231 ) ;
while ( V_34 && V_34 -> V_13 <
V_22 -> V_73 [ V_70 ] . V_10 + V_14 ) {
struct V_9 * V_319 =
F_2 ( V_34 , V_22 -> V_73 [ V_70 ] . V_10 ) ;
F_26 ( V_146 , & V_34 -> V_145 ) ;
if ( ! F_5 ( V_34 ) ) {
V_34 -> V_15 = * V_33 ;
* V_33 = V_34 ;
}
V_34 = V_319 ;
}
}
if ( V_318 )
F_160 ( V_3 -> V_52 -> V_316 , V_22 -> V_10 ,
V_14 , 0 , 0 ) ;
F_26 ( V_83 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
}
if ( F_28 ( V_309 , & V_22 -> V_39 ) )
if ( F_33 ( & V_3 -> V_310 ) )
F_27 ( V_3 -> V_52 -> V_53 ) ;
}
static void
F_161 ( struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_103 * V_104 )
{
int abort = 0 ;
int V_70 ;
F_26 ( V_322 , & V_22 -> V_39 ) ;
if ( F_28 ( V_230 , & V_22 -> V_73 [ V_22 -> V_32 ] . V_61 ) )
F_31 ( & V_3 -> V_231 ) ;
V_104 -> V_134 = 0 ;
V_104 -> V_137 = 0 ;
if ( F_21 ( V_323 , & V_3 -> V_52 -> V_265 ) ) {
for ( V_70 = 0 ; V_70 < V_3 -> V_27 ; V_70 ++ ) {
struct V_87 * V_88 = V_3 -> V_25 [ V_70 ] . V_88 ;
if ( V_88
&& ! F_21 ( V_89 , & V_88 -> V_61 )
&& ! F_21 ( V_91 , & V_88 -> V_61 )
&& ! F_146 ( V_88 , V_22 -> V_10 ,
V_14 , 0 ) )
abort = 1 ;
V_88 = V_3 -> V_25 [ V_70 ] . V_90 ;
if ( V_88
&& ! F_21 ( V_89 , & V_88 -> V_61 )
&& ! F_21 ( V_91 , & V_88 -> V_61 )
&& ! F_146 ( V_88 , V_22 -> V_10 ,
V_14 , 0 ) )
abort = 1 ;
}
if ( abort )
V_3 -> V_324 =
V_3 -> V_52 -> V_324 ;
}
F_162 ( V_3 -> V_52 , V_14 , ! abort ) ;
}
static int F_163 ( struct V_21 * V_22 , int V_325 )
{
struct V_87 * V_88 ;
int V_326 = 0 ;
V_88 = V_22 -> V_60 -> V_25 [ V_325 ] . V_90 ;
if ( V_88
&& ! F_21 ( V_89 , & V_88 -> V_61 )
&& ! F_21 ( V_91 , & V_88 -> V_61 )
&& ( V_88 -> V_327 <= V_22 -> V_10
|| V_88 -> V_52 -> V_328 <= V_22 -> V_10 ) )
V_326 = 1 ;
return V_326 ;
}
static int F_164 ( struct V_21 * V_22 , struct V_103 * V_104 ,
int V_325 , int V_25 )
{
struct V_78 * V_73 = & V_22 -> V_73 [ V_325 ] ;
struct V_78 * V_329 [ 2 ] = { & V_22 -> V_73 [ V_104 -> V_330 [ 0 ] ] ,
& V_22 -> V_73 [ V_104 -> V_330 [ 1 ] ] } ;
if ( ! F_21 ( V_83 , & V_73 -> V_61 ) &&
! F_21 ( V_178 , & V_73 -> V_61 ) &&
( V_73 -> V_79 ||
( V_73 -> V_81 && ! F_21 ( V_315 , & V_73 -> V_61 ) ) ||
V_104 -> V_134 || V_104 -> V_135 ||
( V_104 -> V_137 && F_163 ( V_22 , V_325 ) ) ||
( V_104 -> V_331 >= 1 && V_329 [ 0 ] -> V_79 ) ||
( V_104 -> V_331 >= 2 && V_329 [ 1 ] -> V_79 ) ||
( V_22 -> V_60 -> V_219 <= 5 && V_104 -> V_331 && V_329 [ 0 ] -> V_81 &&
! F_21 ( V_315 , & V_329 [ 0 ] -> V_61 ) ) ||
( V_22 -> V_60 -> V_219 == 6 && V_104 -> V_331 && V_104 -> V_332 ) ) ) {
F_23 ( F_21 ( V_179 , & V_73 -> V_61 ) ) ;
F_23 ( F_21 ( V_115 , & V_73 -> V_61 ) ) ;
if ( ( V_104 -> V_248 == V_25 - 1 ) &&
( V_104 -> V_331 && ( V_325 == V_104 -> V_330 [ 0 ] ||
V_325 == V_104 -> V_330 [ 1 ] ) ) ) {
F_40 ( L_36 ,
( unsigned long long ) V_22 -> V_10 , V_325 ) ;
F_74 ( V_40 , & V_22 -> V_39 ) ;
F_74 ( V_222 , & V_104 -> V_217 ) ;
F_74 ( V_179 , & V_73 -> V_61 ) ;
V_22 -> V_180 . V_176 = V_325 ;
V_22 -> V_180 . V_181 = - 1 ;
V_104 -> V_333 = 1 ;
V_104 -> V_248 ++ ;
return 1 ;
} else if ( V_104 -> V_248 == V_25 - 2 && V_104 -> V_331 >= 2 ) {
int V_334 ;
for ( V_334 = V_25 ; V_334 -- ; ) {
if ( V_334 == V_325 )
continue;
if ( ! F_21 ( V_178 ,
& V_22 -> V_73 [ V_334 ] . V_61 ) )
break;
}
F_23 ( V_334 < 0 ) ;
F_40 ( L_37 ,
( unsigned long long ) V_22 -> V_10 ,
V_325 , V_334 ) ;
F_74 ( V_40 , & V_22 -> V_39 ) ;
F_74 ( V_222 , & V_104 -> V_217 ) ;
F_74 ( V_179 , & V_22 -> V_73 [ V_325 ] . V_61 ) ;
F_74 ( V_179 , & V_22 -> V_73 [ V_334 ] . V_61 ) ;
V_22 -> V_180 . V_176 = V_325 ;
V_22 -> V_180 . V_181 = V_334 ;
V_104 -> V_248 += 2 ;
V_104 -> V_333 = 1 ;
return 1 ;
} else if ( F_21 ( V_321 , & V_73 -> V_61 ) ) {
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_74 ( V_115 , & V_73 -> V_61 ) ;
V_104 -> V_308 ++ ;
F_40 ( L_38 ,
V_325 , V_104 -> V_134 ) ;
}
}
return 0 ;
}
static void F_165 ( struct V_21 * V_22 ,
struct V_103 * V_104 ,
int V_25 )
{
int V_70 ;
if ( ! F_21 ( V_40 , & V_22 -> V_39 ) && ! V_22 -> V_36 &&
! V_22 -> V_37 )
for ( V_70 = V_25 ; V_70 -- ; )
if ( F_164 ( V_22 , V_104 , V_70 , V_25 ) )
break;
F_74 ( V_43 , & V_22 -> V_39 ) ;
}
static void F_166 ( struct V_2 * V_3 ,
struct V_21 * V_22 , int V_25 , struct V_9 * * V_33 )
{
int V_70 ;
struct V_78 * V_73 ;
int V_335 = 0 ;
for ( V_70 = V_25 ; V_70 -- ; )
if ( V_22 -> V_73 [ V_70 ] . V_82 ) {
V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( ! F_21 ( V_83 , & V_73 -> V_61 ) &&
( F_21 ( V_178 , & V_73 -> V_61 ) ||
F_21 ( V_113 , & V_73 -> V_61 ) ) ) {
struct V_9 * V_201 , * V_336 ;
F_40 ( L_39 , V_70 ) ;
if ( F_28 ( V_113 , & V_73 -> V_61 ) )
F_26 ( V_178 , & V_73 -> V_61 ) ;
V_201 = V_73 -> V_82 ;
V_73 -> V_82 = NULL ;
while ( V_201 && V_201 -> V_13 <
V_73 -> V_10 + V_14 ) {
V_336 = F_2 ( V_201 , V_73 -> V_10 ) ;
if ( ! F_5 ( V_201 ) ) {
F_159 ( V_3 -> V_52 ) ;
V_201 -> V_15 = * V_33 ;
* V_33 = V_201 ;
}
V_201 = V_336 ;
}
F_160 ( V_3 -> V_52 -> V_316 , V_22 -> V_10 ,
V_14 ,
! F_21 ( V_154 , & V_22 -> V_39 ) ,
0 ) ;
} else if ( F_21 ( V_113 , & V_73 -> V_61 ) )
V_335 = 1 ;
}
if ( ! V_335 &&
F_21 ( V_113 , & V_22 -> V_73 [ V_22 -> V_32 ] . V_61 ) ) {
F_26 ( V_113 , & V_22 -> V_73 [ V_22 -> V_32 ] . V_61 ) ;
F_26 ( V_178 , & V_22 -> V_73 [ V_22 -> V_32 ] . V_61 ) ;
if ( V_22 -> V_24 >= 0 ) {
F_26 ( V_113 , & V_22 -> V_73 [ V_22 -> V_24 ] . V_61 ) ;
F_26 ( V_178 , & V_22 -> V_73 [ V_22 -> V_24 ] . V_61 ) ;
}
F_26 ( V_337 , & V_22 -> V_39 ) ;
if ( F_21 ( V_338 , & V_22 -> V_39 ) )
F_74 ( V_43 , & V_22 -> V_39 ) ;
}
if ( F_28 ( V_309 , & V_22 -> V_39 ) )
if ( F_33 ( & V_3 -> V_310 ) )
F_27 ( V_3 -> V_52 -> V_53 ) ;
}
static void F_167 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
struct V_103 * V_104 ,
int V_25 )
{
int V_339 = 0 , V_306 = 0 , V_70 ;
T_1 V_328 = V_3 -> V_52 -> V_328 ;
if ( V_3 -> V_94 == 2 ||
( V_328 < V_93 && V_22 -> V_10 >= V_328 ) ) {
V_306 = 1 ; V_339 = 2 ;
F_40 ( L_40 ,
V_3 -> V_94 , ( unsigned long long ) V_328 ,
( unsigned long long ) V_22 -> V_10 ) ;
} else for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( ( V_73 -> V_81 || V_70 == V_22 -> V_32 ) &&
! F_21 ( V_83 , & V_73 -> V_61 ) &&
! ( F_21 ( V_178 , & V_73 -> V_61 ) ||
F_21 ( V_179 , & V_73 -> V_61 ) ) ) {
if ( F_21 ( V_321 , & V_73 -> V_61 ) )
V_339 ++ ;
else
V_339 += 2 * V_25 ;
}
if ( ! F_21 ( V_315 , & V_73 -> V_61 ) && V_70 != V_22 -> V_32 &&
! F_21 ( V_83 , & V_73 -> V_61 ) &&
! ( F_21 ( V_178 , & V_73 -> V_61 ) ||
F_21 ( V_179 , & V_73 -> V_61 ) ) ) {
if ( F_21 ( V_321 , & V_73 -> V_61 ) ) V_306 ++ ;
else
V_306 += 2 * V_25 ;
}
}
F_40 ( L_41 ,
( unsigned long long ) V_22 -> V_10 , V_339 , V_306 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
if ( V_339 < V_306 && V_339 > 0 ) {
if ( V_3 -> V_52 -> V_340 )
F_168 ( V_3 -> V_52 -> V_340 ,
L_42 ,
( unsigned long long ) V_22 -> V_10 , V_339 ) ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( ( V_73 -> V_81 || V_70 == V_22 -> V_32 ) &&
! F_21 ( V_83 , & V_73 -> V_61 ) &&
! ( F_21 ( V_178 , & V_73 -> V_61 ) ||
F_21 ( V_179 , & V_73 -> V_61 ) ) &&
F_21 ( V_321 , & V_73 -> V_61 ) ) {
if (
F_21 ( V_45 , & V_22 -> V_39 ) ) {
F_40 ( L_43
L_44 , V_70 ) ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_74 ( V_115 , & V_73 -> V_61 ) ;
V_104 -> V_308 ++ ;
} else {
F_74 ( V_44 , & V_22 -> V_39 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
}
}
}
}
if ( V_306 <= V_339 && V_306 > 0 ) {
int V_341 = 0 ;
V_306 = 0 ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( ! F_21 ( V_315 , & V_73 -> V_61 ) &&
V_70 != V_22 -> V_32 && V_70 != V_22 -> V_24 &&
! F_21 ( V_83 , & V_73 -> V_61 ) &&
! ( F_21 ( V_178 , & V_73 -> V_61 ) ||
F_21 ( V_179 , & V_73 -> V_61 ) ) ) {
V_306 ++ ;
if ( ! F_21 ( V_321 , & V_73 -> V_61 ) )
continue;
if (
F_21 ( V_45 , & V_22 -> V_39 ) ) {
F_40 ( L_43
L_45 , V_70 ) ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_74 ( V_115 , & V_73 -> V_61 ) ;
V_104 -> V_308 ++ ;
V_341 ++ ;
} else {
F_74 ( V_44 , & V_22 -> V_39 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
}
}
}
if ( V_306 && V_3 -> V_52 -> V_340 )
F_168 ( V_3 -> V_52 -> V_340 , L_46 ,
( unsigned long long ) V_22 -> V_10 ,
V_306 , V_341 , F_21 ( V_44 , & V_22 -> V_39 ) ) ;
}
if ( ( V_104 -> V_333 || ! F_21 ( V_40 , & V_22 -> V_39 ) ) &&
( V_104 -> V_308 == 0 && ( V_306 == 0 || V_339 == 0 ) &&
! F_21 ( V_47 , & V_22 -> V_39 ) ) )
F_155 ( V_22 , V_104 , V_306 == 0 , 0 ) ;
}
static void F_169 ( struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_103 * V_104 , int V_25 )
{
struct V_78 * V_73 = NULL ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
switch ( V_22 -> V_36 ) {
case V_342 :
if ( V_104 -> V_331 == 0 ) {
F_23 ( V_104 -> V_248 != V_25 ) ;
V_22 -> V_36 = V_227 ;
F_74 ( V_226 , & V_104 -> V_217 ) ;
F_26 ( V_178 , & V_22 -> V_73 [ V_22 -> V_32 ] . V_61 ) ;
V_104 -> V_248 -- ;
break;
}
V_73 = & V_22 -> V_73 [ V_104 -> V_330 [ 0 ] ] ;
case V_183 :
V_22 -> V_36 = V_342 ;
if ( ! V_73 )
V_73 = & V_22 -> V_73 [ V_22 -> V_32 ] ;
if ( F_21 ( V_343 , & V_22 -> V_39 ) )
break;
F_23 ( ! F_21 ( V_178 , & V_73 -> V_61 ) ) ;
F_23 ( V_104 -> V_248 != V_25 ) ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
V_104 -> V_308 ++ ;
F_74 ( V_109 , & V_73 -> V_61 ) ;
F_26 ( V_154 , & V_22 -> V_39 ) ;
F_74 ( V_343 , & V_22 -> V_39 ) ;
break;
case V_227 :
break;
case V_213 :
V_22 -> V_36 = V_342 ;
if ( V_104 -> V_331 )
break;
if ( ( V_22 -> V_180 . V_214 & V_344 ) == 0 )
F_74 ( V_343 , & V_22 -> V_39 ) ;
else {
F_170 ( V_14 , & V_3 -> V_52 -> V_345 ) ;
if ( F_21 ( V_346 , & V_3 -> V_52 -> V_265 ) )
F_74 ( V_343 , & V_22 -> V_39 ) ;
else {
V_22 -> V_36 = V_182 ;
F_74 ( V_40 , & V_22 -> V_39 ) ;
F_74 ( V_222 , & V_104 -> V_217 ) ;
F_74 ( V_179 ,
& V_22 -> V_73 [ V_22 -> V_32 ] . V_61 ) ;
V_22 -> V_180 . V_176 = V_22 -> V_32 ;
V_22 -> V_180 . V_181 = - 1 ;
V_104 -> V_248 ++ ;
}
}
break;
case V_182 :
break;
default:
F_53 ( V_84 L_47 ,
V_140 , V_22 -> V_36 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_66 () ;
}
}
static void F_171 ( struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_103 * V_104 ,
int V_25 )
{
int V_32 = V_22 -> V_32 ;
int V_24 = V_22 -> V_24 ;
struct V_78 * V_73 ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_23 ( V_104 -> V_331 > 2 ) ;
switch ( V_22 -> V_36 ) {
case V_342 :
if ( V_104 -> V_331 == V_104 -> V_347 ) {
V_22 -> V_36 = V_227 ;
}
if ( ! V_104 -> V_347 && V_104 -> V_331 < 2 ) {
if ( V_22 -> V_36 == V_227 )
V_22 -> V_36 = V_229 ;
else
V_22 -> V_36 = V_228 ;
}
V_22 -> V_180 . V_214 = 0 ;
if ( V_22 -> V_36 == V_227 ) {
F_26 ( V_178 , & V_22 -> V_73 [ V_32 ] . V_61 ) ;
V_104 -> V_248 -- ;
}
if ( V_22 -> V_36 >= V_227 &&
V_22 -> V_36 <= V_229 ) {
F_74 ( V_226 , & V_104 -> V_217 ) ;
break;
}
F_23 ( V_104 -> V_331 != 2 ) ;
case V_183 :
V_22 -> V_36 = V_342 ;
if ( F_21 ( V_343 , & V_22 -> V_39 ) )
break;
F_23 ( V_104 -> V_248 < V_25 - 1 ) ;
if ( V_104 -> V_331 == 2 ) {
V_73 = & V_22 -> V_73 [ V_104 -> V_330 [ 1 ] ] ;
V_104 -> V_308 ++ ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_74 ( V_109 , & V_73 -> V_61 ) ;
}
if ( V_104 -> V_331 >= 1 ) {
V_73 = & V_22 -> V_73 [ V_104 -> V_330 [ 0 ] ] ;
V_104 -> V_308 ++ ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_74 ( V_109 , & V_73 -> V_61 ) ;
}
if ( V_22 -> V_180 . V_214 & V_344 ) {
V_73 = & V_22 -> V_73 [ V_32 ] ;
V_104 -> V_308 ++ ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_74 ( V_109 , & V_73 -> V_61 ) ;
}
if ( V_22 -> V_180 . V_214 & V_348 ) {
V_73 = & V_22 -> V_73 [ V_24 ] ;
V_104 -> V_308 ++ ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
F_74 ( V_109 , & V_73 -> V_61 ) ;
}
F_26 ( V_154 , & V_22 -> V_39 ) ;
F_74 ( V_343 , & V_22 -> V_39 ) ;
break;
case V_227 :
case V_228 :
case V_229 :
break;
case V_213 :
V_22 -> V_36 = V_342 ;
if ( V_22 -> V_180 . V_214 == 0 ) {
if ( ! V_104 -> V_331 )
F_74 ( V_343 , & V_22 -> V_39 ) ;
else {
V_22 -> V_36 = V_183 ;
}
} else {
F_170 ( V_14 , & V_3 -> V_52 -> V_345 ) ;
if ( F_21 ( V_346 , & V_3 -> V_52 -> V_265 ) )
F_74 ( V_343 , & V_22 -> V_39 ) ;
else {
int * V_176 = & V_22 -> V_180 . V_176 ;
V_22 -> V_180 . V_176 = - 1 ;
V_22 -> V_180 . V_181 = - 1 ;
V_22 -> V_36 = V_182 ;
F_74 ( V_40 , & V_22 -> V_39 ) ;
F_74 ( V_222 , & V_104 -> V_217 ) ;
if ( V_22 -> V_180 . V_214 & V_344 ) {
F_74 ( V_179 ,
& V_22 -> V_73 [ V_32 ] . V_61 ) ;
* V_176 = V_32 ;
V_176 = & V_22 -> V_180 . V_181 ;
V_104 -> V_248 ++ ;
}
if ( V_22 -> V_180 . V_214 & V_348 ) {
F_74 ( V_179 ,
& V_22 -> V_73 [ V_24 ] . V_61 ) ;
* V_176 = V_24 ;
V_104 -> V_248 ++ ;
}
}
}
break;
case V_182 :
break;
default:
F_53 ( V_84 L_47 ,
V_140 , V_22 -> V_36 ,
( unsigned long long ) V_22 -> V_10 ) ;
F_66 () ;
}
}
static void F_172 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
int V_70 ;
struct V_155 * V_157 = NULL ;
F_26 ( V_349 , & V_22 -> V_39 ) ;
for ( V_70 = 0 ; V_70 < V_22 -> V_25 ; V_70 ++ )
if ( V_70 != V_22 -> V_32 && V_70 != V_22 -> V_24 ) {
int V_277 , V_350 ;
struct V_21 * V_305 ;
struct V_162 V_163 ;
T_1 V_351 = F_150 ( V_22 , V_70 , 1 ) ;
T_1 V_104 = F_153 ( V_3 , V_351 , 0 ,
& V_277 , NULL ) ;
V_305 = F_63 ( V_3 , V_104 , 0 , 1 , 1 ) ;
if ( V_305 == NULL )
continue;
if ( ! F_21 ( V_56 , & V_305 -> V_39 ) ||
F_21 ( V_352 , & V_305 -> V_73 [ V_277 ] . V_61 ) ) {
F_34 ( V_305 ) ;
continue;
}
F_83 ( & V_163 , 0 , V_157 , NULL , NULL , NULL ) ;
V_157 = F_85 ( V_305 -> V_73 [ V_277 ] . V_68 ,
V_22 -> V_73 [ V_70 ] . V_68 , 0 , 0 , V_150 ,
& V_163 ) ;
F_74 ( V_352 , & V_305 -> V_73 [ V_277 ] . V_61 ) ;
F_74 ( V_178 , & V_305 -> V_73 [ V_277 ] . V_61 ) ;
for ( V_350 = 0 ; V_350 < V_3 -> V_27 ; V_350 ++ )
if ( V_350 != V_305 -> V_32 &&
V_350 != V_305 -> V_24 &&
! F_21 ( V_352 , & V_305 -> V_73 [ V_350 ] . V_61 ) )
break;
if ( V_350 == V_3 -> V_27 ) {
F_74 ( V_353 , & V_305 -> V_39 ) ;
F_74 ( V_43 , & V_305 -> V_39 ) ;
}
F_34 ( V_305 ) ;
}
F_173 ( & V_157 ) ;
}
static void F_174 ( struct V_21 * V_22 , struct V_103 * V_104 )
{
struct V_2 * V_3 = V_22 -> V_60 ;
int V_25 = V_22 -> V_25 ;
struct V_78 * V_73 ;
int V_70 ;
int V_354 = 0 ;
memset ( V_104 , 0 , sizeof( * V_104 ) ) ;
V_104 -> V_135 = F_21 ( V_349 , & V_22 -> V_39 ) ;
V_104 -> V_136 = F_21 ( V_353 , & V_22 -> V_39 ) ;
V_104 -> V_330 [ 0 ] = - 1 ;
V_104 -> V_330 [ 1 ] = - 1 ;
F_59 () ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_87 * V_88 ;
T_1 V_129 ;
int V_130 ;
int V_355 = 0 ;
V_73 = & V_22 -> V_73 [ V_70 ] ;
F_40 ( L_48 ,
V_70 , V_73 -> V_61 ,
V_73 -> V_79 , V_73 -> V_81 , V_73 -> V_82 ) ;
if ( F_21 ( V_178 , & V_73 -> V_61 ) && V_73 -> V_79 &&
! F_21 ( V_38 , & V_22 -> V_39 ) )
F_74 ( V_172 , & V_73 -> V_61 ) ;
if ( F_21 ( V_83 , & V_73 -> V_61 ) )
V_104 -> V_308 ++ ;
if ( F_21 ( V_178 , & V_73 -> V_61 ) )
V_104 -> V_248 ++ ;
if ( F_21 ( V_179 , & V_73 -> V_61 ) ) {
V_104 -> V_356 ++ ;
F_23 ( V_104 -> V_356 > 2 ) ;
}
if ( F_21 ( V_172 , & V_73 -> V_61 ) )
V_104 -> V_357 ++ ;
else if ( V_73 -> V_79 )
V_104 -> V_358 ++ ;
if ( V_73 -> V_81 ) {
V_104 -> V_332 ++ ;
if ( ! F_21 ( V_315 , & V_73 -> V_61 ) )
V_104 -> V_359 ++ ;
}
if ( V_73 -> V_82 )
V_104 -> V_82 ++ ;
V_88 = F_60 ( V_3 -> V_25 [ V_70 ] . V_90 ) ;
if ( V_88 && ! F_21 ( V_89 , & V_88 -> V_61 ) &&
V_88 -> V_327 >= V_22 -> V_10 + V_14 &&
! F_73 ( V_88 , V_22 -> V_10 , V_14 ,
& V_129 , & V_130 ) )
F_74 ( V_126 , & V_73 -> V_61 ) ;
else {
if ( V_88 )
F_74 ( V_360 , & V_73 -> V_61 ) ;
V_88 = F_60 ( V_3 -> V_25 [ V_70 ] . V_88 ) ;
F_26 ( V_126 , & V_73 -> V_61 ) ;
}
if ( V_88 && F_21 ( V_89 , & V_88 -> V_61 ) )
V_88 = NULL ;
if ( V_88 ) {
V_355 = F_73 ( V_88 , V_22 -> V_10 , V_14 ,
& V_129 , & V_130 ) ;
if ( V_104 -> V_361 == NULL
&& ( F_21 ( V_273 , & V_88 -> V_61 )
|| V_355 < 0 ) ) {
if ( V_355 < 0 )
F_74 ( V_132 ,
& V_88 -> V_61 ) ;
V_104 -> V_361 = V_88 ;
F_8 ( & V_88 -> V_127 ) ;
}
}
F_26 ( V_321 , & V_73 -> V_61 ) ;
if ( ! V_88 )
;
else if ( V_355 ) {
if ( ! F_21 ( V_128 , & V_88 -> V_61 ) &&
F_21 ( V_178 , & V_73 -> V_61 ) ) {
F_74 ( V_321 , & V_73 -> V_61 ) ;
F_74 ( V_251 , & V_73 -> V_61 ) ;
}
} else if ( F_21 ( V_91 , & V_88 -> V_61 ) )
F_74 ( V_321 , & V_73 -> V_61 ) ;
else if ( V_22 -> V_10 + V_14 <= V_88 -> V_327 )
F_74 ( V_321 , & V_73 -> V_61 ) ;
else if ( F_21 ( V_178 , & V_73 -> V_61 ) &&
F_21 ( V_352 , & V_73 -> V_61 ) )
F_74 ( V_321 , & V_73 -> V_61 ) ;
if ( V_88 && F_21 ( V_262 , & V_73 -> V_61 ) ) {
struct V_87 * V_362 = F_60 (
V_3 -> V_25 [ V_70 ] . V_88 ) ;
if ( V_362 == V_88 )
F_26 ( V_321 , & V_73 -> V_61 ) ;
if ( V_362 && ! F_21 ( V_89 , & V_362 -> V_61 ) ) {
V_104 -> V_363 = 1 ;
F_8 ( & V_362 -> V_127 ) ;
} else
F_26 ( V_262 , & V_73 -> V_61 ) ;
}
if ( V_88 && F_21 ( V_266 , & V_73 -> V_61 ) ) {
struct V_87 * V_362 = F_60 (
V_3 -> V_25 [ V_70 ] . V_88 ) ;
if ( V_362 && ! F_21 ( V_89 , & V_362 -> V_61 ) ) {
V_104 -> V_363 = 1 ;
F_8 ( & V_362 -> V_127 ) ;
} else
F_26 ( V_266 , & V_73 -> V_61 ) ;
}
if ( F_21 ( V_261 , & V_73 -> V_61 ) ) {
struct V_87 * V_362 = F_60 (
V_3 -> V_25 [ V_70 ] . V_90 ) ;
if ( V_362 && ! F_21 ( V_89 , & V_362 -> V_61 ) ) {
V_104 -> V_363 = 1 ;
F_8 ( & V_362 -> V_127 ) ;
} else
F_26 ( V_261 , & V_73 -> V_61 ) ;
}
if ( ! F_21 ( V_321 , & V_73 -> V_61 ) ) {
F_26 ( V_251 , & V_73 -> V_61 ) ;
F_26 ( V_254 , & V_73 -> V_61 ) ;
}
if ( F_21 ( V_251 , & V_73 -> V_61 ) )
F_26 ( V_321 , & V_73 -> V_61 ) ;
if ( ! F_21 ( V_321 , & V_73 -> V_61 ) ) {
if ( V_104 -> V_331 < 2 )
V_104 -> V_330 [ V_104 -> V_331 ] = V_70 ;
V_104 -> V_331 ++ ;
if ( V_88 && ! F_21 ( V_89 , & V_88 -> V_61 ) )
V_354 = 1 ;
}
}
if ( F_21 ( V_322 , & V_22 -> V_39 ) ) {
if ( V_354 ||
V_22 -> V_10 >= V_3 -> V_52 -> V_328 ||
F_21 ( V_364 , & ( V_3 -> V_52 -> V_265 ) ) )
V_104 -> V_134 = 1 ;
else
V_104 -> V_137 = 1 ;
}
F_61 () ;
}
static void F_175 ( struct V_21 * V_22 )
{
struct V_103 V_104 ;
struct V_2 * V_3 = V_22 -> V_60 ;
int V_70 ;
int V_212 ;
int V_25 = V_22 -> V_25 ;
struct V_78 * V_365 , * V_366 ;
F_26 ( V_43 , & V_22 -> V_39 ) ;
if ( F_176 ( V_367 , & V_22 -> V_39 ) ) {
F_74 ( V_43 , & V_22 -> V_39 ) ;
return;
}
if ( F_21 ( V_338 , & V_22 -> V_39 ) ) {
F_177 ( & V_22 -> V_174 ) ;
if ( ! F_21 ( V_337 , & V_22 -> V_39 ) &&
F_28 ( V_338 , & V_22 -> V_39 ) ) {
F_74 ( V_322 , & V_22 -> V_39 ) ;
F_26 ( V_343 , & V_22 -> V_39 ) ;
}
F_37 ( & V_22 -> V_174 ) ;
}
F_26 ( V_44 , & V_22 -> V_39 ) ;
F_40 ( L_49
L_50 ,
( unsigned long long ) V_22 -> V_10 , V_22 -> V_39 ,
F_4 ( & V_22 -> V_29 ) , V_22 -> V_32 , V_22 -> V_24 ,
V_22 -> V_36 , V_22 -> V_37 ) ;
F_174 ( V_22 , & V_104 ) ;
if ( V_104 . V_363 ) {
F_74 ( V_43 , & V_22 -> V_39 ) ;
goto V_368;
}
if ( F_93 ( V_104 . V_361 ) ) {
if ( V_104 . V_134 || V_104 . V_135 || V_104 . V_136 ||
V_104 . V_137 || V_104 . V_332 || V_104 . V_82 ) {
F_74 ( V_43 , & V_22 -> V_39 ) ;
goto V_368;
}
F_77 ( V_104 . V_361 , V_3 -> V_52 ) ;
V_104 . V_361 = NULL ;
}
if ( V_104 . V_357 && ! F_21 ( V_38 , & V_22 -> V_39 ) ) {
F_74 ( V_221 , & V_104 . V_217 ) ;
F_74 ( V_38 , & V_22 -> V_39 ) ;
}
F_40 ( L_51
L_52 ,
V_104 . V_308 , V_104 . V_248 , V_104 . V_358 , V_104 . V_332 , V_104 . V_331 ,
V_104 . V_330 [ 0 ] , V_104 . V_330 [ 1 ] ) ;
if ( V_104 . V_331 > V_3 -> V_94 ) {
V_22 -> V_36 = 0 ;
V_22 -> V_37 = 0 ;
if ( V_104 . V_358 + V_104 . V_332 + V_104 . V_82 )
F_158 ( V_3 , V_22 , & V_104 , V_25 , & V_104 . V_33 ) ;
if ( V_104 . V_134 + V_104 . V_137 )
F_161 ( V_3 , V_22 , & V_104 ) ;
}
V_212 = 0 ;
if ( V_22 -> V_37 == V_209 )
V_212 = 1 ;
if ( V_22 -> V_37 == V_207 ||
V_22 -> V_37 == V_209 ) {
V_22 -> V_37 = V_369 ;
F_23 ( ! F_21 ( V_178 , & V_22 -> V_73 [ V_22 -> V_32 ] . V_61 ) &&
! F_21 ( V_113 , & V_22 -> V_73 [ V_22 -> V_32 ] . V_61 ) ) ;
F_23 ( V_22 -> V_24 >= 0 &&
! F_21 ( V_178 , & V_22 -> V_73 [ V_22 -> V_24 ] . V_61 ) &&
! F_21 ( V_113 , & V_22 -> V_73 [ V_22 -> V_24 ] . V_61 ) ) ;
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( F_21 ( V_83 , & V_73 -> V_61 ) &&
( V_70 == V_22 -> V_32 || V_70 == V_22 -> V_24 ||
V_73 -> V_82 ) ) {
F_40 ( L_53 , V_70 ) ;
F_74 ( V_109 , & V_73 -> V_61 ) ;
if ( V_212 )
continue;
if ( ! F_21 ( V_321 , & V_73 -> V_61 ) ||
( ( V_70 == V_22 -> V_32 || V_70 == V_22 -> V_24 ) &&
V_104 . V_331 == 0 ) )
F_74 ( V_343 , & V_22 -> V_39 ) ;
}
}
if ( F_28 ( V_45 , & V_22 -> V_39 ) )
V_104 . V_370 = 1 ;
}
V_365 = & V_22 -> V_73 [ V_22 -> V_32 ] ;
V_104 . V_371 = ( V_104 . V_331 >= 1 && V_104 . V_330 [ 0 ] == V_22 -> V_32 )
|| ( V_104 . V_331 >= 2 && V_104 . V_330 [ 1 ] == V_22 -> V_32 ) ;
V_366 = & V_22 -> V_73 [ V_22 -> V_24 ] ;
V_104 . V_347 = ( V_104 . V_331 >= 1 && V_104 . V_330 [ 0 ] == V_22 -> V_24 )
|| ( V_104 . V_331 >= 2 && V_104 . V_330 [ 1 ] == V_22 -> V_24 )
|| V_3 -> V_219 < 6 ;
if ( V_104 . V_82 &&
( V_104 . V_371 || ( ( F_21 ( V_321 , & V_365 -> V_61 )
&& ! F_21 ( V_83 , & V_365 -> V_61 )
&& ( F_21 ( V_178 , & V_365 -> V_61 ) ||
F_21 ( V_113 , & V_365 -> V_61 ) ) ) ) ) &&
( V_104 . V_347 || ( ( F_21 ( V_321 , & V_366 -> V_61 )
&& ! F_21 ( V_83 , & V_366 -> V_61 )
&& ( F_21 ( V_178 , & V_366 -> V_61 ) ||
F_21 ( V_113 , & V_366 -> V_61 ) ) ) ) ) )
F_166 ( V_3 , V_22 , V_25 , & V_104 . V_33 ) ;
if ( V_104 . V_358 || V_104 . V_359
|| ( V_3 -> V_219 == 6 && V_104 . V_332 && V_104 . V_331 )
|| ( V_104 . V_134 && ( V_104 . V_248 + V_104 . V_356 < V_25 ) )
|| V_104 . V_137
|| V_104 . V_135 )
F_165 ( V_22 , & V_104 , V_25 ) ;
if ( V_104 . V_332 && ! V_22 -> V_37 && ! V_22 -> V_36 )
F_167 ( V_3 , V_22 , & V_104 , V_25 ) ;
if ( V_22 -> V_36 ||
( V_104 . V_134 && V_104 . V_308 == 0 &&
! F_21 ( V_40 , & V_22 -> V_39 ) &&
! F_21 ( V_343 , & V_22 -> V_39 ) ) ) {
if ( V_3 -> V_219 == 6 )
F_171 ( V_3 , V_22 , & V_104 , V_25 ) ;
else
F_169 ( V_3 , V_22 , & V_104 , V_25 ) ;
}
if ( V_104 . V_137 && V_104 . V_308 == 0
&& ! F_21 ( V_343 , & V_22 -> V_39 ) ) {
for ( V_70 = 0 ; V_70 < V_3 -> V_27 ; V_70 ++ )
if ( F_21 ( V_178 , & V_22 -> V_73 [ V_70 ] . V_61 ) &&
F_21 ( V_360 , & V_22 -> V_73 [ V_70 ] . V_61 ) ) {
F_74 ( V_117 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_74 ( V_83 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
V_104 . V_308 ++ ;
}
F_74 ( V_343 , & V_22 -> V_39 ) ;
}
if ( ( V_104 . V_134 || V_104 . V_137 ) && V_104 . V_308 == 0 &&
F_21 ( V_343 , & V_22 -> V_39 ) ) {
F_162 ( V_3 -> V_52 , V_14 , 1 ) ;
F_26 ( V_322 , & V_22 -> V_39 ) ;
if ( F_28 ( V_230 , & V_22 -> V_73 [ V_22 -> V_32 ] . V_61 ) )
F_31 ( & V_3 -> V_231 ) ;
}
if ( V_104 . V_331 <= V_3 -> V_94 && ! V_3 -> V_52 -> V_372 )
for ( V_70 = 0 ; V_70 < V_104 . V_331 ; V_70 ++ ) {
struct V_78 * V_73 = & V_22 -> V_73 [ V_104 . V_330 [ V_70 ] ] ;
if ( F_21 ( V_251 , & V_73 -> V_61 )
&& ! F_21 ( V_83 , & V_73 -> V_61 )
&& F_21 ( V_178 , & V_73 -> V_61 )
) {
if ( ! F_21 ( V_254 , & V_73 -> V_61 ) ) {
F_74 ( V_109 , & V_73 -> V_61 ) ;
F_74 ( V_254 , & V_73 -> V_61 ) ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
V_104 . V_308 ++ ;
} else {
F_74 ( V_115 , & V_73 -> V_61 ) ;
F_74 ( V_83 , & V_73 -> V_61 ) ;
V_104 . V_308 ++ ;
}
}
}
if ( V_22 -> V_37 == V_211 ) {
struct V_21 * V_373
= F_63 ( V_3 , V_22 -> V_10 , 1 , 1 , 1 ) ;
if ( V_373 && F_21 ( V_349 , & V_373 -> V_39 ) ) {
F_74 ( V_44 , & V_22 -> V_39 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
if ( ! F_148 ( V_45 ,
& V_373 -> V_39 ) )
F_8 ( & V_3 -> V_54 ) ;
F_34 ( V_373 ) ;
goto V_368;
}
if ( V_373 )
F_34 ( V_373 ) ;
V_22 -> V_37 = V_369 ;
F_26 ( V_56 , & V_22 -> V_39 ) ;
for ( V_70 = V_3 -> V_27 ; V_70 -- ; ) {
F_74 ( V_109 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
F_74 ( V_83 , & V_22 -> V_73 [ V_70 ] . V_61 ) ;
V_104 . V_308 ++ ;
}
}
if ( V_104 . V_136 && F_21 ( V_56 , & V_22 -> V_39 ) &&
! V_22 -> V_37 ) {
V_22 -> V_25 = V_3 -> V_27 ;
F_52 ( V_22 -> V_10 , V_3 , 0 , V_22 ) ;
F_155 ( V_22 , & V_104 , 1 , 1 ) ;
} else if ( V_104 . V_136 && ! V_22 -> V_37 && V_104 . V_308 == 0 ) {
F_26 ( V_353 , & V_22 -> V_39 ) ;
F_30 ( & V_3 -> V_374 ) ;
F_31 ( & V_3 -> V_231 ) ;
F_162 ( V_3 -> V_52 , V_14 , 1 ) ;
}
if ( V_104 . V_135 && V_104 . V_308 == 0 &&
! F_21 ( V_40 , & V_22 -> V_39 ) )
F_172 ( V_3 , V_22 ) ;
V_368:
if ( F_93 ( V_104 . V_361 ) ) {
if ( V_3 -> V_52 -> V_133 )
F_76 ( V_104 . V_361 ,
V_3 -> V_52 ) ;
else
F_77 ( V_104 . V_361 ,
V_3 -> V_52 ) ;
}
if ( V_104 . V_363 )
for ( V_70 = V_25 ; V_70 -- ; ) {
struct V_87 * V_88 ;
struct V_78 * V_73 = & V_22 -> V_73 [ V_70 ] ;
if ( F_28 ( V_262 , & V_73 -> V_61 ) ) {
V_88 = V_3 -> V_25 [ V_70 ] . V_88 ;
if ( ! F_146 ( V_88 , V_22 -> V_10 ,
V_14 , 0 ) )
F_147 ( V_3 -> V_52 , V_88 ) ;
F_77 ( V_88 , V_3 -> V_52 ) ;
}
if ( F_28 ( V_266 , & V_73 -> V_61 ) ) {
V_88 = V_3 -> V_25 [ V_70 ] . V_88 ;
F_178 ( V_88 , V_22 -> V_10 ,
V_14 , 0 ) ;
F_77 ( V_88 , V_3 -> V_52 ) ;
}
if ( F_28 ( V_261 , & V_73 -> V_61 ) ) {
V_88 = V_3 -> V_25 [ V_70 ] . V_90 ;
if ( ! V_88 )
V_88 = V_3 -> V_25 [ V_70 ] . V_88 ;
F_178 ( V_88 , V_22 -> V_10 ,
V_14 , 0 ) ;
F_77 ( V_88 , V_3 -> V_52 ) ;
}
}
if ( V_104 . V_217 )
F_113 ( V_22 , V_104 . V_217 ) ;
F_70 ( V_22 , & V_104 ) ;
if ( V_104 . V_370 ) {
F_30 ( & V_3 -> V_54 ) ;
if ( F_4 ( & V_3 -> V_54 ) <
V_55 )
F_27 ( V_3 -> V_52 -> V_53 ) ;
}
F_16 ( V_104 . V_33 ) ;
F_179 ( V_367 , & V_22 -> V_39 ) ;
}
static void F_180 ( struct V_2 * V_3 )
{
if ( F_4 ( & V_3 -> V_54 ) < V_55 ) {
while ( ! F_24 ( & V_3 -> V_46 ) ) {
struct V_64 * V_375 = V_3 -> V_46 . V_67 ;
struct V_21 * V_22 ;
V_22 = F_45 ( V_375 , struct V_21 , V_41 ) ;
F_46 ( V_375 ) ;
F_26 ( V_44 , & V_22 -> V_39 ) ;
if ( ! F_148 ( V_45 , & V_22 -> V_39 ) )
F_8 ( & V_3 -> V_54 ) ;
F_25 ( & V_22 -> V_41 , & V_3 -> V_376 ) ;
}
}
}
static void F_181 ( struct V_2 * V_3 )
{
struct V_64 V_377 ;
F_131 ( & V_377 , & V_3 -> V_50 ) ;
F_46 ( & V_3 -> V_50 ) ;
while ( ! F_24 ( & V_377 ) ) {
struct V_21 * V_22 = F_45 ( V_377 . V_67 , struct V_21 , V_41 ) ;
F_46 ( & V_22 -> V_41 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_32 ( V_3 , V_22 ) ;
}
}
int F_182 ( struct V_52 * V_52 , int V_378 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
if ( V_3 -> V_98 )
return 1 ;
if ( V_3 -> V_97 )
return 1 ;
if ( F_183 ( & V_3 -> V_57 ) )
return 1 ;
return 0 ;
}
static int F_184 ( void * V_379 , int V_378 )
{
struct V_52 * V_52 = V_379 ;
return F_185 ( V_52 , V_378 ) ||
F_182 ( V_52 , V_378 ) ;
}
static int F_186 ( struct V_380 * V_381 ,
struct V_382 * V_383 ,
struct V_158 * V_384 )
{
struct V_52 * V_52 = V_381 -> V_385 ;
T_1 V_10 = V_383 -> V_13 + F_187 ( V_383 -> V_35 ) ;
int F_124 ;
unsigned int V_287 = V_52 -> V_287 ;
unsigned int V_386 = V_383 -> V_12 >> 9 ;
if ( ( V_383 -> V_122 & 1 ) == V_112 )
return V_384 -> V_149 ;
if ( V_52 -> V_387 < V_52 -> V_287 )
V_287 = V_52 -> V_387 ;
F_124 = ( V_287 - ( ( V_10 & ( V_287 - 1 ) ) + V_386 ) ) << 9 ;
if ( F_124 < 0 ) F_124 = 0 ;
if ( F_124 <= V_384 -> V_149 && V_386 == 0 )
return V_384 -> V_149 ;
else
return F_124 ;
}
static int F_188 ( struct V_52 * V_52 , struct V_9 * V_9 )
{
T_1 V_10 = V_9 -> V_13 + F_187 ( V_9 -> V_35 ) ;
unsigned int V_287 = V_52 -> V_287 ;
unsigned int V_386 = V_9 -> V_12 >> 9 ;
if ( V_52 -> V_387 < V_52 -> V_287 )
V_287 = V_52 -> V_387 ;
return V_287 >=
( ( V_10 & ( V_287 - 1 ) ) + V_386 ) ;
}
static void F_189 ( struct V_9 * V_34 , struct V_2 * V_3 )
{
unsigned long V_61 ;
F_151 ( & V_3 -> V_62 , V_61 ) ;
V_34 -> V_15 = V_3 -> V_388 ;
V_3 -> V_388 = V_34 ;
F_152 ( & V_3 -> V_62 , V_61 ) ;
F_27 ( V_3 -> V_52 -> V_53 ) ;
}
static struct V_9 * F_190 ( struct V_2 * V_3 )
{
struct V_9 * V_34 ;
V_34 = V_3 -> V_59 ;
if ( V_34 ) {
V_3 -> V_59 = NULL ;
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
static void F_191 ( struct V_9 * V_34 , int error )
{
struct V_9 * V_389 = V_34 -> V_247 ;
struct V_52 * V_52 ;
struct V_2 * V_3 ;
int V_248 = F_21 ( V_146 , & V_34 -> V_145 ) ;
struct V_87 * V_88 ;
F_192 ( V_34 ) ;
V_88 = ( void * ) V_389 -> V_15 ;
V_389 -> V_15 = NULL ;
V_52 = V_88 -> V_52 ;
V_3 = V_52 -> V_271 ;
F_77 ( V_88 , V_3 -> V_52 ) ;
if ( ! error && V_248 ) {
F_17 ( F_18 ( V_389 -> V_35 ) ,
V_389 , 0 ) ;
F_19 ( V_389 , 0 ) ;
if ( F_33 ( & V_3 -> V_390 ) )
F_31 ( & V_3 -> V_58 ) ;
return;
}
F_40 ( L_54 ) ;
F_189 ( V_389 , V_3 ) ;
}
static int F_193 ( struct V_9 * V_34 )
{
struct V_380 * V_381 = F_18 ( V_34 -> V_35 ) ;
if ( ( V_34 -> V_12 >> 9 ) > F_194 ( V_381 ) )
return 0 ;
F_195 ( V_381 , V_34 ) ;
if ( V_34 -> V_17 > F_196 ( V_381 ) )
return 0 ;
if ( V_381 -> V_391 )
return 0 ;
return 1 ;
}
static int F_197 ( struct V_52 * V_52 , struct V_9 * V_392 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
int V_277 ;
struct V_9 * V_393 ;
struct V_87 * V_88 ;
T_1 V_394 ;
if ( ! F_188 ( V_52 , V_392 ) ) {
F_40 ( L_55 ) ;
return 0 ;
}
V_393 = F_198 ( V_392 , V_246 , V_52 ) ;
if ( ! V_393 )
return 0 ;
V_393 -> V_123 = F_191 ;
V_393 -> V_247 = V_392 ;
V_393 -> V_13 = F_153 ( V_3 , V_392 -> V_13 ,
0 ,
& V_277 , NULL ) ;
V_394 = V_393 -> V_13 + ( V_393 -> V_12 >> 9 ) ;
F_59 () ;
V_88 = F_60 ( V_3 -> V_25 [ V_277 ] . V_90 ) ;
if ( ! V_88 || F_21 ( V_89 , & V_88 -> V_61 ) ||
V_88 -> V_327 < V_394 ) {
V_88 = F_60 ( V_3 -> V_25 [ V_277 ] . V_88 ) ;
if ( V_88 &&
( F_21 ( V_89 , & V_88 -> V_61 ) ||
! ( F_21 ( V_91 , & V_88 -> V_61 ) ||
V_88 -> V_327 >= V_394 ) ) )
V_88 = NULL ;
}
if ( V_88 ) {
T_1 V_129 ;
int V_130 ;
F_8 ( & V_88 -> V_127 ) ;
F_61 () ;
V_392 -> V_15 = ( void * ) V_88 ;
V_393 -> V_35 = V_88 -> V_138 ;
V_393 -> V_145 &= ~ ( 1 << V_395 ) ;
if ( ! F_193 ( V_393 ) ||
F_73 ( V_88 , V_393 -> V_13 , V_393 -> V_12 >> 9 ,
& V_129 , & V_130 ) ) {
F_192 ( V_393 ) ;
F_77 ( V_88 , V_52 ) ;
return 0 ;
}
V_393 -> V_13 += V_88 -> V_142 ;
F_64 ( & V_3 -> V_62 ) ;
F_65 ( V_3 -> V_58 ,
V_3 -> V_97 == 0 ,
V_3 -> V_62 ) ;
F_8 ( & V_3 -> V_390 ) ;
F_67 ( & V_3 -> V_62 ) ;
if ( V_52 -> V_153 )
F_79 ( F_18 ( V_393 -> V_35 ) ,
V_393 , F_80 ( V_52 -> V_153 ) ,
V_392 -> V_13 ) ;
F_81 ( V_393 ) ;
return 1 ;
} else {
F_61 () ;
F_192 ( V_393 ) ;
return 0 ;
}
}
static struct V_21 * F_199 ( struct V_2 * V_3 )
{
struct V_21 * V_22 ;
F_40 ( L_56 ,
V_140 ,
F_24 ( & V_3 -> V_51 ) ? L_57 : L_58 ,
F_24 ( & V_3 -> V_376 ) ? L_57 : L_58 ,
F_4 ( & V_3 -> V_310 ) , V_3 -> V_396 ) ;
if ( ! F_24 ( & V_3 -> V_51 ) ) {
V_22 = F_45 ( V_3 -> V_51 . V_67 , F_200 ( * V_22 ) , V_41 ) ;
if ( F_24 ( & V_3 -> V_376 ) )
V_3 -> V_396 = 0 ;
else if ( ! F_21 ( V_139 , & V_22 -> V_39 ) ) {
if ( V_3 -> V_376 . V_67 == V_3 -> V_397 )
V_3 -> V_396 ++ ;
else {
V_3 -> V_397 = V_3 -> V_376 . V_67 ;
V_3 -> V_396 -= V_3 -> V_398 ;
if ( V_3 -> V_396 < 0 )
V_3 -> V_396 = 0 ;
}
}
} else if ( ! F_24 ( & V_3 -> V_376 ) &&
( ( V_3 -> V_398 &&
V_3 -> V_396 > V_3 -> V_398 ) ||
F_4 ( & V_3 -> V_310 ) == 0 ) ) {
V_22 = F_45 ( V_3 -> V_376 . V_67 ,
F_200 ( * V_22 ) , V_41 ) ;
V_3 -> V_396 -= V_3 -> V_398 ;
if ( V_3 -> V_396 < 0 )
V_3 -> V_396 = 0 ;
} else
return NULL ;
F_46 ( & V_22 -> V_41 ) ;
F_8 ( & V_22 -> V_29 ) ;
F_23 ( F_4 ( & V_22 -> V_29 ) != 1 ) ;
return V_22 ;
}
static void F_201 ( struct V_399 * V_400 , bool V_401 )
{
struct V_402 * V_403 = F_202 (
V_400 , struct V_402 , V_403 ) ;
struct V_21 * V_22 ;
struct V_52 * V_52 = V_403 -> V_403 . V_379 ;
struct V_2 * V_3 = V_52 -> V_271 ;
int V_18 = 0 ;
if ( V_403 -> V_404 . V_67 && ! F_24 ( & V_403 -> V_404 ) ) {
F_64 ( & V_3 -> V_62 ) ;
while ( ! F_24 ( & V_403 -> V_404 ) ) {
V_22 = F_203 ( & V_403 -> V_404 , struct V_21 , V_41 ) ;
F_46 ( & V_22 -> V_41 ) ;
F_204 () ;
F_26 ( V_100 , & V_22 -> V_39 ) ;
F_32 ( V_3 , V_22 ) ;
V_18 ++ ;
}
F_67 ( & V_3 -> V_62 ) ;
}
if ( V_52 -> V_340 )
F_205 ( V_52 -> V_340 , V_18 , ! V_401 ) ;
F_136 ( V_403 ) ;
}
static void F_206 ( struct V_52 * V_52 ,
struct V_21 * V_22 )
{
struct V_399 * V_400 = F_207 (
F_201 , V_52 ,
sizeof( struct V_402 ) ) ;
struct V_402 * V_403 ;
if ( ! V_400 ) {
F_34 ( V_22 ) ;
return;
}
V_403 = F_202 ( V_400 , struct V_402 , V_403 ) ;
if ( V_403 -> V_404 . V_67 == NULL )
F_122 ( & V_403 -> V_404 ) ;
if ( ! F_148 ( V_100 , & V_22 -> V_39 ) )
F_25 ( & V_22 -> V_41 , & V_403 -> V_404 ) ;
else
F_34 ( V_22 ) ;
}
static void F_208 ( struct V_52 * V_52 , struct V_9 * V_34 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
T_1 V_405 , V_406 ;
struct V_21 * V_22 ;
int V_407 ;
int V_408 ;
if ( V_52 -> V_92 != V_93 )
return;
V_405 = V_34 -> V_13 & ~ ( ( T_1 ) V_14 - 1 ) ;
V_406 = V_34 -> V_13 + ( V_34 -> V_12 >> 9 ) ;
V_34 -> V_15 = NULL ;
V_34 -> V_17 = 1 ;
V_408 = V_3 -> V_287 *
( V_3 -> V_27 - V_3 -> V_94 ) ;
V_405 = F_209 ( V_405 ,
V_408 ) ;
F_154 ( V_406 , V_408 ) ;
V_405 *= V_3 -> V_287 ;
V_406 *= V_3 -> V_287 ;
for (; V_405 < V_406 ;
V_405 += V_14 ) {
F_210 ( V_409 ) ;
int V_410 ;
V_411:
V_22 = F_63 ( V_3 , V_405 , 0 , 0 , 0 ) ;
F_211 ( & V_3 -> V_231 , & V_409 ,
V_412 ) ;
F_74 ( V_230 , & V_22 -> V_73 [ V_22 -> V_32 ] . V_61 ) ;
if ( F_21 ( V_322 , & V_22 -> V_39 ) ) {
F_34 ( V_22 ) ;
F_212 () ;
goto V_411;
}
F_26 ( V_230 , & V_22 -> V_73 [ V_22 -> V_32 ] . V_61 ) ;
F_64 ( & V_22 -> V_174 ) ;
for ( V_410 = 0 ; V_410 < V_3 -> V_27 ; V_410 ++ ) {
if ( V_410 == V_22 -> V_32 || V_410 == V_22 -> V_24 )
continue;
if ( V_22 -> V_73 [ V_410 ] . V_81 || V_22 -> V_73 [ V_410 ] . V_79 ) {
F_74 ( V_230 , & V_22 -> V_73 [ V_410 ] . V_61 ) ;
F_67 ( & V_22 -> V_174 ) ;
F_34 ( V_22 ) ;
F_212 () ;
goto V_411;
}
}
F_74 ( V_337 , & V_22 -> V_39 ) ;
F_213 ( & V_3 -> V_231 , & V_409 ) ;
for ( V_410 = 0 ; V_410 < V_3 -> V_27 ; V_410 ++ ) {
if ( V_410 == V_22 -> V_32 || V_410 == V_22 -> V_24 )
continue;
V_22 -> V_73 [ V_410 ] . V_81 = V_34 ;
F_74 ( V_315 , & V_22 -> V_73 [ V_410 ] . V_61 ) ;
F_7 ( V_34 ) ;
}
F_67 ( & V_22 -> V_174 ) ;
if ( V_3 -> V_52 -> V_316 ) {
for ( V_410 = 0 ;
V_410 < V_3 -> V_27 - V_3 -> V_94 ;
V_410 ++ )
F_157 ( V_52 -> V_316 ,
V_22 -> V_10 ,
V_14 ,
0 ) ;
V_22 -> V_48 = V_3 -> V_317 + 1 ;
F_74 ( V_47 , & V_22 -> V_39 ) ;
}
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_26 ( V_44 , & V_22 -> V_39 ) ;
if ( ! F_148 ( V_45 , & V_22 -> V_39 ) )
F_8 ( & V_3 -> V_54 ) ;
F_206 ( V_52 , V_22 ) ;
}
V_407 = F_5 ( V_34 ) ;
if ( V_407 == 0 ) {
F_159 ( V_52 ) ;
F_19 ( V_34 , 0 ) ;
}
}
static void F_214 ( struct V_52 * V_52 , struct V_9 * V_34 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
int V_277 ;
T_1 V_282 ;
T_1 V_405 , V_406 ;
struct V_21 * V_22 ;
const int V_105 = F_215 ( V_34 ) ;
int V_407 ;
if ( F_93 ( V_34 -> V_122 & V_144 ) ) {
F_216 ( V_52 , V_34 ) ;
return;
}
F_217 ( V_52 , V_34 ) ;
if ( V_105 == V_116 &&
V_52 -> V_92 == V_93 &&
F_197 ( V_52 , V_34 ) )
return;
if ( F_93 ( V_34 -> V_122 & V_114 ) ) {
F_208 ( V_52 , V_34 ) ;
return;
}
V_405 = V_34 -> V_13 & ~ ( ( T_1 ) V_14 - 1 ) ;
V_406 = V_34 -> V_13 + ( V_34 -> V_12 >> 9 ) ;
V_34 -> V_15 = NULL ;
V_34 -> V_17 = 1 ;
for (; V_405 < V_406 ; V_405 += V_14 ) {
F_210 ( V_409 ) ;
int V_75 ;
V_257:
V_75 = 0 ;
F_211 ( & V_3 -> V_231 , & V_409 , V_412 ) ;
if ( F_93 ( V_3 -> V_102 != V_93 ) ) {
F_64 ( & V_3 -> V_62 ) ;
if ( V_52 -> V_413
? V_405 < V_3 -> V_102
: V_405 >= V_3 -> V_102 ) {
V_75 = 1 ;
} else {
if ( V_52 -> V_413
? V_405 < V_3 -> V_414
: V_405 >= V_3 -> V_414 ) {
F_67 ( & V_3 -> V_62 ) ;
F_212 () ;
goto V_257;
}
}
F_67 ( & V_3 -> V_62 ) ;
}
V_282 = F_153 ( V_3 , V_405 ,
V_75 ,
& V_277 , NULL ) ;
F_40 ( L_59 ,
( unsigned long long ) V_282 ,
( unsigned long long ) V_405 ) ;
V_22 = F_63 ( V_3 , V_282 , V_75 ,
( V_34 -> V_122 & V_415 ) , 0 ) ;
if ( V_22 ) {
if ( F_93 ( V_75 ) ) {
int V_416 = 0 ;
F_64 ( & V_3 -> V_62 ) ;
if ( V_52 -> V_413
? V_405 >= V_3 -> V_102
: V_405 < V_3 -> V_102 )
V_416 = 1 ;
F_67 ( & V_3 -> V_62 ) ;
if ( V_416 ) {
F_34 ( V_22 ) ;
F_212 () ;
goto V_257;
}
}
if ( V_105 == V_112 &&
V_405 >= V_52 -> V_417 &&
V_405 < V_52 -> V_418 ) {
F_34 ( V_22 ) ;
F_218 ( V_419 ) ;
F_211 ( & V_3 -> V_231 ,
& V_409 , V_420 ) ;
if ( V_405 >= V_52 -> V_417 &&
V_405 < V_52 -> V_418 )
F_212 () ;
goto V_257;
}
if ( F_21 ( V_56 , & V_22 -> V_39 ) ||
! F_156 ( V_22 , V_34 , V_277 , V_105 ) ) {
F_27 ( V_52 -> V_53 ) ;
F_34 ( V_22 ) ;
F_212 () ;
goto V_257;
}
F_213 ( & V_3 -> V_231 , & V_409 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_26 ( V_44 , & V_22 -> V_39 ) ;
if ( ( V_34 -> V_122 & V_119 ) &&
! F_148 ( V_45 , & V_22 -> V_39 ) )
F_8 ( & V_3 -> V_54 ) ;
F_206 ( V_52 , V_22 ) ;
} else {
F_26 ( V_146 , & V_34 -> V_145 ) ;
F_213 ( & V_3 -> V_231 , & V_409 ) ;
break;
}
}
V_407 = F_5 ( V_34 ) ;
if ( V_407 == 0 ) {
if ( V_105 == V_112 )
F_159 ( V_52 ) ;
F_17 ( F_18 ( V_34 -> V_35 ) ,
V_34 , 0 ) ;
F_19 ( V_34 , 0 ) ;
}
}
static T_1 F_219 ( struct V_52 * V_52 , T_1 V_421 , int * V_422 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
struct V_21 * V_22 ;
T_1 V_423 , V_406 ;
int V_27 = V_3 -> V_77 ;
int V_288 = V_27 - V_3 -> V_94 ;
int V_424 = V_3 -> V_27 - V_3 -> V_94 ;
int V_70 ;
int V_277 ;
T_1 V_425 , V_426 , V_427 ;
T_1 V_428 ;
int V_429 ;
struct V_64 V_430 ;
if ( V_421 == 0 ) {
if ( V_52 -> V_413 &&
V_3 -> V_102 < F_220 ( V_52 , 0 , 0 ) ) {
V_421 = F_220 ( V_52 , 0 , 0 )
- V_3 -> V_102 ;
} else if ( ! V_52 -> V_413 &&
V_3 -> V_102 > 0 )
V_421 = V_3 -> V_102 ;
F_154 ( V_421 , V_424 ) ;
if ( V_421 ) {
V_52 -> V_431 = V_421 ;
F_221 ( & V_52 -> V_432 , NULL , L_60 ) ;
* V_422 = 1 ;
return V_421 ;
}
}
if ( V_52 -> V_387 > V_52 -> V_287 )
V_429 = V_52 -> V_387 ;
else
V_429 = V_52 -> V_287 ;
V_425 = V_3 -> V_102 ;
F_154 ( V_425 , V_424 ) ;
V_426 = V_3 -> V_102 ;
F_154 ( V_426 , V_288 ) ;
V_427 = V_3 -> V_414 ;
F_154 ( V_427 , V_288 ) ;
if ( V_52 -> V_413 ) {
V_425 -= F_222 ( T_1 , V_429 , V_425 ) ;
V_426 += V_429 ;
V_427 += V_429 ;
} else {
V_425 += V_429 ;
V_426 -= F_222 ( T_1 , V_429 , V_426 ) ;
V_427 -= F_222 ( T_1 , V_429 , V_427 ) ;
}
if ( V_52 -> V_413 ) {
F_23 ( V_3 -> V_102 == 0 ) ;
V_428 = V_425 ;
F_23 ( ( V_52 -> V_433 &
~ ( ( T_1 ) V_429 - 1 ) )
- V_429 - V_428
!= V_421 ) ;
} else {
F_23 ( V_425 != V_421 + V_429 ) ;
V_428 = V_421 ;
}
if ( V_3 -> V_434 < 0 ) {
V_427 += - V_3 -> V_434 ;
V_426 += - V_3 -> V_434 ;
} else
V_425 += V_3 -> V_434 ;
if ( ( V_52 -> V_413
? ( V_427 > V_425 && V_426 < V_425 )
: ( V_427 < V_425 && V_426 > V_425 ) ) ||
F_223 ( V_435 , V_3 -> V_436 + 10 * V_437 ) ) {
F_224 ( V_3 -> V_231 ,
F_4 ( & V_3 -> V_374 ) == 0 ) ;
V_52 -> V_92 = V_3 -> V_102 ;
V_52 -> V_431 = V_421 ;
V_3 -> V_436 = V_435 ;
F_74 ( V_274 , & V_52 -> V_61 ) ;
F_27 ( V_52 -> V_53 ) ;
F_224 ( V_52 -> V_438 , V_52 -> V_61 == 0 ||
F_225 () ) ;
F_64 ( & V_3 -> V_62 ) ;
V_3 -> V_414 = V_52 -> V_92 ;
F_67 ( & V_3 -> V_62 ) ;
F_31 ( & V_3 -> V_231 ) ;
F_221 ( & V_52 -> V_432 , NULL , L_60 ) ;
}
F_122 ( & V_430 ) ;
for ( V_70 = 0 ; V_70 < V_429 ; V_70 += V_14 ) {
int V_350 ;
int V_439 = 0 ;
V_22 = F_63 ( V_3 , V_428 + V_70 , 0 , 0 , 1 ) ;
F_74 ( V_56 , & V_22 -> V_39 ) ;
F_8 ( & V_3 -> V_374 ) ;
for ( V_350 = V_22 -> V_25 ; V_350 -- ; ) {
T_1 V_104 ;
if ( V_350 == V_22 -> V_32 )
continue;
if ( V_3 -> V_219 == 6 &&
V_350 == V_22 -> V_24 )
continue;
V_104 = F_150 ( V_22 , V_350 , 0 ) ;
if ( V_104 < F_220 ( V_52 , 0 , 0 ) ) {
V_439 = 1 ;
continue;
}
memset ( F_226 ( V_22 -> V_73 [ V_350 ] . V_68 ) , 0 , V_150 ) ;
F_74 ( V_352 , & V_22 -> V_73 [ V_350 ] . V_61 ) ;
F_74 ( V_178 , & V_22 -> V_73 [ V_350 ] . V_61 ) ;
}
if ( ! V_439 ) {
F_74 ( V_353 , & V_22 -> V_39 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
}
F_131 ( & V_22 -> V_41 , & V_430 ) ;
}
F_64 ( & V_3 -> V_62 ) ;
if ( V_52 -> V_413 )
V_3 -> V_102 -= V_429 * V_424 ;
else
V_3 -> V_102 += V_429 * V_424 ;
F_67 ( & V_3 -> V_62 ) ;
V_423 =
F_153 ( V_3 , V_428 * ( V_424 ) ,
1 , & V_277 , NULL ) ;
V_406 =
F_153 ( V_3 , ( ( V_428 + V_429 )
* V_424 - 1 ) ,
1 , & V_277 , NULL ) ;
if ( V_406 >= V_52 -> V_433 )
V_406 = V_52 -> V_433 - 1 ;
while ( V_423 <= V_406 ) {
V_22 = F_63 ( V_3 , V_423 , 1 , 0 , 1 ) ;
F_74 ( V_349 , & V_22 -> V_39 ) ;
F_74 ( V_43 , & V_22 -> V_39 ) ;
F_34 ( V_22 ) ;
V_423 += V_14 ;
}
while ( ! F_24 ( & V_430 ) ) {
V_22 = F_45 ( V_430 . V_67 , struct V_21 , V_41 ) ;
F_46 ( & V_22 -> V_41 ) ;
F_34 ( V_22 ) ;
}
V_421 += V_429 ;
if ( ( V_421 - V_52 -> V_431 ) * 2
>= V_52 -> V_440 - V_52 -> V_431 ) {
F_224 ( V_3 -> V_231 ,
F_4 ( & V_3 -> V_374 ) == 0 ) ;
V_52 -> V_92 = V_3 -> V_102 ;
V_52 -> V_431 = V_421 ;
V_3 -> V_436 = V_435 ;
F_74 ( V_274 , & V_52 -> V_61 ) ;
F_27 ( V_52 -> V_53 ) ;
F_224 ( V_52 -> V_438 ,
! F_21 ( V_274 , & V_52 -> V_61 )
|| F_225 () ) ;
F_64 ( & V_3 -> V_62 ) ;
V_3 -> V_414 = V_52 -> V_92 ;
F_67 ( & V_3 -> V_62 ) ;
F_31 ( & V_3 -> V_231 ) ;
F_221 ( & V_52 -> V_432 , NULL , L_60 ) ;
}
return V_429 ;
}
static inline T_1 F_227 ( struct V_52 * V_52 , T_1 V_421 , int * V_422 , int V_441 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
struct V_21 * V_22 ;
T_1 V_442 = V_52 -> V_433 ;
T_1 V_443 ;
int V_444 = 0 ;
int V_70 ;
if ( V_421 >= V_442 ) {
if ( F_21 ( V_445 , & V_52 -> V_265 ) ) {
F_228 ( V_3 ) ;
return 0 ;
}
if ( V_52 -> V_446 < V_442 )
F_229 ( V_52 -> V_316 , V_52 -> V_446 ,
& V_443 , 1 ) ;
else
V_3 -> V_447 = 0 ;
F_230 ( V_52 -> V_316 ) ;
return 0 ;
}
F_224 ( V_3 -> V_231 , V_3 -> V_97 != 2 ) ;
if ( F_21 ( V_445 , & V_52 -> V_265 ) )
return F_219 ( V_52 , V_421 , V_422 ) ;
if ( V_52 -> V_85 >= V_3 -> V_94 &&
F_21 ( V_448 , & V_52 -> V_265 ) ) {
T_1 V_326 = V_52 -> V_433 - V_421 ;
* V_422 = 1 ;
return V_326 ;
}
if ( ! F_231 ( V_52 -> V_316 , V_421 , & V_443 , 1 ) &&
! F_21 ( V_364 , & V_52 -> V_265 ) &&
! V_3 -> V_447 && V_443 >= V_14 ) {
V_443 /= V_14 ;
* V_422 = 1 ;
return V_443 * V_14 ;
}
F_232 ( V_52 -> V_316 , V_421 ) ;
V_22 = F_63 ( V_3 , V_421 , 0 , 1 , 0 ) ;
if ( V_22 == NULL ) {
V_22 = F_63 ( V_3 , V_421 , 0 , 0 , 0 ) ;
F_233 ( 1 ) ;
}
for ( V_70 = 0 ; V_70 < V_3 -> V_27 ; V_70 ++ )
if ( V_3 -> V_25 [ V_70 ] . V_88 == NULL )
V_444 = 1 ;
F_231 ( V_52 -> V_316 , V_421 , & V_443 , V_444 ) ;
F_74 ( V_338 , & V_22 -> V_39 ) ;
F_175 ( V_22 ) ;
F_34 ( V_22 ) ;
return V_14 ;
}
static int F_234 ( struct V_2 * V_3 , struct V_9 * V_392 )
{
struct V_21 * V_22 ;
int V_277 ;
T_1 V_10 , V_405 , V_406 ;
int V_449 = 0 ;
int V_407 ;
int V_450 = 0 ;
V_405 = V_392 -> V_13 & ~ ( ( T_1 ) V_14 - 1 ) ;
V_10 = F_153 ( V_3 , V_405 ,
0 , & V_277 , NULL ) ;
V_406 = V_392 -> V_13 + ( V_392 -> V_12 >> 9 ) ;
for (; V_405 < V_406 ;
V_405 += V_14 ,
V_10 += V_14 ,
V_449 ++ ) {
if ( V_449 < F_3 ( V_392 ) )
continue;
V_22 = F_63 ( V_3 , V_10 , 0 , 1 , 0 ) ;
if ( ! V_22 ) {
F_9 ( V_392 , V_449 ) ;
V_3 -> V_59 = V_392 ;
return V_450 ;
}
if ( ! F_156 ( V_22 , V_392 , V_277 , 0 ) ) {
F_34 ( V_22 ) ;
F_9 ( V_392 , V_449 ) ;
V_3 -> V_59 = V_392 ;
return V_450 ;
}
F_74 ( V_143 , & V_22 -> V_73 [ V_277 ] . V_61 ) ;
F_175 ( V_22 ) ;
F_34 ( V_22 ) ;
V_450 ++ ;
}
V_407 = F_5 ( V_392 ) ;
if ( V_407 == 0 ) {
F_17 ( F_18 ( V_392 -> V_35 ) ,
V_392 , 0 ) ;
F_19 ( V_392 , 0 ) ;
}
if ( F_33 ( & V_3 -> V_390 ) )
F_31 ( & V_3 -> V_58 ) ;
return V_450 ;
}
static int F_235 ( struct V_2 * V_3 )
{
struct V_21 * V_451 [ V_452 ] , * V_22 ;
int V_70 , V_453 = 0 ;
while ( V_453 < V_452 &&
( V_22 = F_199 ( V_3 ) ) != NULL )
V_451 [ V_453 ++ ] = V_22 ;
if ( V_453 == 0 )
return V_453 ;
F_67 ( & V_3 -> V_62 ) ;
for ( V_70 = 0 ; V_70 < V_453 ; V_70 ++ )
F_175 ( V_451 [ V_70 ] ) ;
F_236 () ;
F_64 ( & V_3 -> V_62 ) ;
for ( V_70 = 0 ; V_70 < V_453 ; V_70 ++ )
F_32 ( V_3 , V_451 [ V_70 ] ) ;
return V_453 ;
}
static void F_237 ( struct V_454 * V_53 )
{
struct V_52 * V_52 = V_53 -> V_52 ;
struct V_2 * V_3 = V_52 -> V_271 ;
int V_450 ;
struct V_455 V_456 ;
F_40 ( L_61 ) ;
F_75 ( V_52 ) ;
F_238 ( & V_456 ) ;
V_450 = 0 ;
F_64 ( & V_3 -> V_62 ) ;
while ( 1 ) {
struct V_9 * V_9 ;
int V_453 ;
if (
! F_24 ( & V_3 -> V_50 ) ) {
V_3 -> V_317 ++ ;
F_67 ( & V_3 -> V_62 ) ;
F_239 ( V_52 -> V_316 ) ;
F_64 ( & V_3 -> V_62 ) ;
V_3 -> V_49 = V_3 -> V_317 ;
F_181 ( V_3 ) ;
}
F_180 ( V_3 ) ;
while ( ( V_9 = F_190 ( V_3 ) ) ) {
int V_457 ;
F_67 ( & V_3 -> V_62 ) ;
V_457 = F_234 ( V_3 , V_9 ) ;
F_64 ( & V_3 -> V_62 ) ;
if ( ! V_457 )
break;
V_450 ++ ;
}
V_453 = F_235 ( V_3 ) ;
if ( ! V_453 )
break;
V_450 += V_453 ;
if ( V_52 -> V_61 & ~ ( 1 << V_458 ) ) {
F_67 ( & V_3 -> V_62 ) ;
F_75 ( V_52 ) ;
F_64 ( & V_3 -> V_62 ) ;
}
}
F_40 ( L_62 , V_450 ) ;
F_67 ( & V_3 -> V_62 ) ;
F_240 () ;
F_241 ( & V_456 ) ;
F_40 ( L_63 ) ;
}
static T_5
F_242 ( struct V_52 * V_52 , char * V_68 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
if ( V_3 )
return sprintf ( V_68 , L_64 , V_3 -> V_99 ) ;
else
return 0 ;
}
int
F_243 ( struct V_52 * V_52 , int V_459 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
int V_244 ;
if ( V_459 <= 16 || V_459 > 32768 )
return - V_460 ;
while ( V_459 < V_3 -> V_99 ) {
if ( F_141 ( V_3 ) )
V_3 -> V_99 -- ;
else
break;
}
V_244 = F_130 ( V_52 ) ;
if ( V_244 )
return V_244 ;
while ( V_459 > V_3 -> V_99 ) {
if ( F_118 ( V_3 ) )
V_3 -> V_99 ++ ;
else break;
}
return 0 ;
}
static T_5
F_244 ( struct V_52 * V_52 , const char * V_68 , T_4 V_166 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
unsigned long V_20 ;
int V_244 ;
if ( V_166 >= V_461 )
return - V_460 ;
if ( ! V_3 )
return - V_462 ;
if ( F_245 ( V_68 , 10 , & V_20 ) )
return - V_460 ;
V_244 = F_243 ( V_52 , V_20 ) ;
if ( V_244 )
return V_244 ;
return V_166 ;
}
static T_5
F_246 ( struct V_52 * V_52 , char * V_68 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
if ( V_3 )
return sprintf ( V_68 , L_64 , V_3 -> V_398 ) ;
else
return 0 ;
}
static T_5
F_247 ( struct V_52 * V_52 , const char * V_68 , T_4 V_166 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
unsigned long V_20 ;
if ( V_166 >= V_461 )
return - V_460 ;
if ( ! V_3 )
return - V_462 ;
if ( F_245 ( V_68 , 10 , & V_20 ) )
return - V_460 ;
if ( V_20 > V_3 -> V_99 )
return - V_460 ;
V_3 -> V_398 = V_20 ;
return V_166 ;
}
static T_5
F_248 ( struct V_52 * V_52 , char * V_68 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
if ( V_3 )
return sprintf ( V_68 , L_64 , F_4 ( & V_3 -> V_42 ) ) ;
else
return 0 ;
}
static T_1
F_220 ( struct V_52 * V_52 , T_1 V_11 , int V_27 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
if ( ! V_11 )
V_11 = V_52 -> V_433 ;
if ( ! V_27 )
V_27 = F_249 ( V_3 -> V_27 , V_3 -> V_77 ) ;
V_11 &= ~ ( ( T_1 ) V_52 -> V_287 - 1 ) ;
V_11 &= ~ ( ( T_1 ) V_52 -> V_387 - 1 ) ;
return V_11 * ( V_27 - V_3 -> V_94 ) ;
}
static void F_250 ( struct V_2 * V_3 )
{
struct V_184 * V_185 ;
unsigned long V_220 ;
if ( ! V_3 -> V_185 )
return;
F_137 () ;
F_251 (cpu) {
V_185 = F_115 ( V_3 -> V_185 , V_220 ) ;
F_252 ( V_185 -> V_216 ) ;
F_136 ( V_185 -> V_186 ) ;
}
#ifdef F_253
F_254 ( & V_3 -> V_463 ) ;
#endif
F_140 () ;
F_255 ( V_3 -> V_185 ) ;
}
static void F_256 ( struct V_2 * V_3 )
{
F_142 ( V_3 ) ;
F_250 ( V_3 ) ;
F_136 ( V_3 -> V_25 ) ;
F_136 ( V_3 -> V_8 ) ;
F_136 ( V_3 ) ;
}
static int F_257 ( struct V_464 * V_465 , unsigned long V_466 ,
void * V_467 )
{
struct V_2 * V_3 = F_202 ( V_465 , struct V_2 , V_463 ) ;
long V_220 = ( long ) V_467 ;
struct V_184 * V_185 = F_115 ( V_3 -> V_185 , V_220 ) ;
switch ( V_466 ) {
case V_468 :
case V_469 :
if ( V_3 -> V_219 == 6 && ! V_185 -> V_216 )
V_185 -> V_216 = F_50 ( V_74 ) ;
if ( ! V_185 -> V_186 )
V_185 -> V_186 = F_139 ( V_3 -> F_127 , V_74 ) ;
if ( ! V_185 -> V_186 ||
( V_3 -> V_219 == 6 && ! V_185 -> V_216 ) ) {
F_252 ( V_185 -> V_216 ) ;
F_136 ( V_185 -> V_186 ) ;
F_258 ( L_65 ,
V_140 , V_220 ) ;
return F_259 ( - V_245 ) ;
}
break;
case V_470 :
case V_471 :
F_252 ( V_185 -> V_216 ) ;
F_136 ( V_185 -> V_186 ) ;
V_185 -> V_216 = NULL ;
V_185 -> V_186 = NULL ;
break;
default:
break;
}
return V_472 ;
}
static int F_260 ( struct V_2 * V_3 )
{
unsigned long V_220 ;
struct V_68 * V_216 ;
struct V_184 T_6 * V_473 ;
void * V_186 ;
int V_244 ;
V_473 = F_261 ( struct V_184 ) ;
if ( ! V_473 )
return - V_245 ;
V_3 -> V_185 = V_473 ;
F_137 () ;
V_244 = 0 ;
F_138 (cpu) {
if ( V_3 -> V_219 == 6 ) {
V_216 = F_50 ( V_74 ) ;
if ( ! V_216 ) {
V_244 = - V_245 ;
break;
}
F_115 ( V_3 -> V_185 , V_220 ) -> V_216 = V_216 ;
}
V_186 = F_139 ( V_3 -> F_127 , V_74 ) ;
if ( ! V_186 ) {
V_244 = - V_245 ;
break;
}
F_115 ( V_3 -> V_185 , V_220 ) -> V_186 = V_186 ;
}
#ifdef F_253
V_3 -> V_463 . V_474 = F_257 ;
V_3 -> V_463 . V_475 = 0 ;
if ( V_244 == 0 )
V_244 = F_262 ( & V_3 -> V_463 ) ;
#endif
F_140 () ;
return V_244 ;
}
static struct V_2 * F_263 ( struct V_52 * V_52 )
{
struct V_2 * V_3 ;
int V_476 , V_477 , V_478 ;
struct V_87 * V_88 ;
struct V_242 * V_26 ;
char V_479 [ 6 ] ;
if ( V_52 -> V_480 != 5
&& V_52 -> V_480 != 4
&& V_52 -> V_480 != 6 ) {
F_53 ( V_84 L_66 ,
F_125 ( V_52 ) , V_52 -> V_480 ) ;
return F_264 ( - V_481 ) ;
}
if ( ( V_52 -> V_480 == 5
&& ! F_265 ( V_52 -> V_482 ) ) ||
( V_52 -> V_480 == 6
&& ! F_266 ( V_52 -> V_482 ) ) ) {
F_53 ( V_84 L_67 ,
F_125 ( V_52 ) , V_52 -> V_482 ) ;
return F_264 ( - V_481 ) ;
}
if ( V_52 -> V_480 == 6 && V_52 -> V_27 < 4 ) {
F_53 ( V_84 L_68 ,
F_125 ( V_52 ) , V_52 -> V_27 ) ;
return F_264 ( - V_460 ) ;
}
if ( ! V_52 -> V_387 ||
( V_52 -> V_387 << 9 ) % V_461 ||
! F_267 ( V_52 -> V_387 ) ) {
F_53 ( V_84 L_69 ,
F_125 ( V_52 ) , V_52 -> V_387 << 9 ) ;
return F_264 ( - V_460 ) ;
}
V_3 = F_135 ( sizeof( struct V_2 ) , V_74 ) ;
if ( V_3 == NULL )
goto abort;
F_120 ( & V_3 -> V_62 ) ;
F_268 ( & V_3 -> V_58 ) ;
F_268 ( & V_3 -> V_231 ) ;
F_122 ( & V_3 -> V_51 ) ;
F_122 ( & V_3 -> V_376 ) ;
F_122 ( & V_3 -> V_46 ) ;
F_122 ( & V_3 -> V_50 ) ;
F_122 ( & V_3 -> V_57 ) ;
F_12 ( & V_3 -> V_42 , 0 ) ;
F_12 ( & V_3 -> V_54 , 0 ) ;
F_12 ( & V_3 -> V_390 , 0 ) ;
V_3 -> V_398 = V_483 ;
V_3 -> V_324 = V_52 -> V_324 - 1 ;
V_3 -> V_27 = V_52 -> V_27 ;
if ( V_52 -> V_92 == V_93 )
V_3 -> V_77 = V_52 -> V_27 ;
else
V_3 -> V_77 = V_52 -> V_27 - V_52 -> V_484 ;
V_478 = F_124 ( V_3 -> V_27 , V_3 -> V_77 ) ;
V_3 -> F_127 = F_127 ( V_478 ) ;
V_3 -> V_25 = F_135 ( V_478 * sizeof( struct V_242 ) ,
V_74 ) ;
if ( ! V_3 -> V_25 )
goto abort;
V_3 -> V_52 = V_52 ;
if ( ( V_3 -> V_8 = F_135 ( V_461 , V_74 ) ) == NULL )
goto abort;
V_3 -> V_219 = V_52 -> V_480 ;
if ( F_260 ( V_3 ) != 0 )
goto abort;
F_40 ( L_70 , F_125 ( V_52 ) ) ;
F_269 (rdev, mddev) {
V_476 = V_88 -> V_476 ;
if ( V_476 >= V_478
|| V_476 < 0 )
continue;
V_26 = V_3 -> V_25 + V_476 ;
if ( F_21 ( V_485 , & V_88 -> V_61 ) ) {
if ( V_26 -> V_90 )
goto abort;
V_26 -> V_90 = V_88 ;
} else {
if ( V_26 -> V_88 )
goto abort;
V_26 -> V_88 = V_88 ;
}
if ( F_21 ( V_91 , & V_88 -> V_61 ) ) {
char V_249 [ V_250 ] ;
F_53 ( V_252 L_71
L_72 ,
F_125 ( V_52 ) , F_144 ( V_88 -> V_138 , V_249 ) , V_476 ) ;
} else if ( V_88 -> V_486 != V_476 )
V_3 -> V_447 = 1 ;
}
V_3 -> V_287 = V_52 -> V_387 ;
V_3 -> V_219 = V_52 -> V_480 ;
if ( V_3 -> V_219 == 6 )
V_3 -> V_94 = 2 ;
else
V_3 -> V_94 = 1 ;
V_3 -> V_283 = V_52 -> V_482 ;
V_3 -> V_99 = V_487 ;
V_3 -> V_102 = V_52 -> V_92 ;
if ( V_3 -> V_102 != V_93 ) {
V_3 -> V_286 = V_52 -> V_287 ;
V_3 -> V_284 = V_52 -> V_488 ;
}
V_477 = V_3 -> V_99 * ( sizeof( struct V_21 ) +
V_478 * ( ( sizeof( struct V_9 ) + V_461 ) ) ) / 1024 ;
if ( F_123 ( V_3 , V_3 -> V_99 ) ) {
F_53 ( V_84
L_73 ,
F_125 ( V_52 ) , V_477 ) ;
goto abort;
} else
F_53 ( V_252 L_74 ,
F_125 ( V_52 ) , V_477 ) ;
sprintf ( V_479 , L_75 , V_52 -> V_480 ) ;
V_3 -> V_53 = F_270 ( F_237 , V_52 , V_479 ) ;
if ( ! V_3 -> V_53 ) {
F_53 ( V_84
L_76 ,
F_125 ( V_52 ) ) ;
goto abort;
}
return V_3 ;
abort:
if ( V_3 ) {
F_256 ( V_3 ) ;
return F_264 ( - V_481 ) ;
} else
return F_264 ( - V_245 ) ;
}
static int F_271 ( int V_476 , int V_489 , int V_27 , int V_94 )
{
switch ( V_489 ) {
case V_293 :
if ( V_476 < V_94 )
return 1 ;
break;
case V_294 :
if ( V_476 >= V_27 - V_94 )
return 1 ;
break;
case V_302 :
if ( V_476 == 0 ||
V_476 == V_27 - 1 )
return 1 ;
break;
case V_298 :
case V_299 :
case V_300 :
case V_301 :
if ( V_476 == V_27 - 1 )
return 1 ;
}
return 0 ;
}
static int F_272 ( struct V_52 * V_52 )
{
struct V_2 * V_3 ;
int V_490 = 0 ;
int V_491 = 0 ;
struct V_87 * V_88 ;
T_1 V_492 = 0 ;
int V_70 ;
long long V_434 = 0 ;
int V_65 = 1 ;
if ( V_52 -> V_328 != V_93 )
F_53 ( V_493 L_77
L_78 ,
F_125 ( V_52 ) ) ;
F_269 (rdev, mddev) {
long long V_494 ;
if ( V_88 -> V_476 < 0 )
continue;
V_494 = ( V_88 -> V_141 - V_88 -> V_142 ) ;
if ( V_65 ) {
V_434 = V_494 ;
V_65 = 0 ;
} else if ( V_52 -> V_413 &&
V_494 < V_434 )
V_434 = V_494 ;
else if ( ! V_52 -> V_413 &&
V_494 > V_434 )
V_434 = V_494 ;
}
if ( V_52 -> V_92 != V_93 ) {
T_1 V_495 , V_496 ;
int V_497 ;
int V_94 = ( V_52 -> V_219 == 6 ? 2 : 1 ) ;
if ( V_52 -> V_480 != V_52 -> V_219 ) {
F_53 ( V_84 L_79
L_80 ,
F_125 ( V_52 ) ) ;
return - V_460 ;
}
V_497 = V_52 -> V_27 - V_52 -> V_484 ;
V_495 = V_52 -> V_92 ;
if ( F_154 ( V_495 , V_52 -> V_387 *
( V_52 -> V_27 - V_94 ) ) ) {
F_53 ( V_84 L_81
L_82 , F_125 ( V_52 ) ) ;
return - V_460 ;
}
V_492 = V_495 * V_52 -> V_387 ;
V_496 = V_52 -> V_92 ;
F_154 ( V_496 , V_52 -> V_287 *
( V_497 - V_94 ) ) ;
if ( V_52 -> V_484 == 0 ) {
if ( ( V_495 * V_52 -> V_387 !=
V_496 * V_52 -> V_287 ) ) {
F_53 ( V_84 L_83
L_84 , F_125 ( V_52 ) ) ;
return - V_460 ;
}
if ( abs ( V_434 ) >= V_52 -> V_287 &&
abs ( V_434 ) >= V_52 -> V_387 )
;
else if ( V_52 -> V_372 == 0 ) {
F_53 ( V_84 L_85
L_86
L_87 ,
F_125 ( V_52 ) ) ;
return - V_460 ;
}
} else if ( V_52 -> V_413
? ( V_495 * V_52 -> V_387 + V_434 <=
V_496 * V_52 -> V_287 )
: ( V_495 * V_52 -> V_387 >=
V_496 * V_52 -> V_287 + ( - V_434 ) ) ) {
F_53 ( V_84 L_88
L_89 ,
F_125 ( V_52 ) ) ;
return - V_460 ;
}
F_53 ( V_252 L_90 ,
F_125 ( V_52 ) ) ;
} else {
F_23 ( V_52 -> V_219 != V_52 -> V_480 ) ;
F_23 ( V_52 -> V_488 != V_52 -> V_482 ) ;
F_23 ( V_52 -> V_287 != V_52 -> V_387 ) ;
F_23 ( V_52 -> V_484 != 0 ) ;
}
if ( V_52 -> V_271 == NULL )
V_3 = F_263 ( V_52 ) ;
else
V_3 = V_52 -> V_271 ;
if ( F_273 ( V_3 ) )
return F_274 ( V_3 ) ;
V_3 -> V_434 = V_434 ;
V_52 -> V_53 = V_3 -> V_53 ;
V_3 -> V_53 = NULL ;
V_52 -> V_271 = V_3 ;
for ( V_70 = 0 ; V_70 < V_3 -> V_27 && V_3 -> V_77 ;
V_70 ++ ) {
V_88 = V_3 -> V_25 [ V_70 ] . V_88 ;
if ( ! V_88 && V_3 -> V_25 [ V_70 ] . V_90 ) {
V_88 = V_3 -> V_25 [ V_70 ] . V_90 ;
V_3 -> V_25 [ V_70 ] . V_90 = NULL ;
F_26 ( V_485 , & V_88 -> V_61 ) ;
V_3 -> V_25 [ V_70 ] . V_88 = V_88 ;
}
if ( ! V_88 )
continue;
if ( V_3 -> V_25 [ V_70 ] . V_90 &&
V_3 -> V_102 != V_93 ) {
F_53 ( V_84 L_91
L_92 ) ;
goto abort;
}
if ( F_21 ( V_91 , & V_88 -> V_61 ) ) {
V_490 ++ ;
continue;
}
if ( V_52 -> V_498 == 0 &&
V_52 -> V_499 > 90 )
V_88 -> V_327 = V_492 ;
if ( V_88 -> V_327 < V_492 ) {
if ( ! F_271 ( V_88 -> V_476 ,
V_3 -> V_283 ,
V_3 -> V_27 ,
V_3 -> V_94 ) )
continue;
}
if ( ! F_271 ( V_88 -> V_476 ,
V_3 -> V_284 ,
V_3 -> V_77 ,
V_3 -> V_94 ) )
continue;
V_491 ++ ;
}
V_52 -> V_85 = F_58 ( V_3 ) ;
if ( F_62 ( V_3 ) ) {
F_53 ( V_84 L_93
L_94 ,
F_125 ( V_52 ) , V_52 -> V_85 , V_3 -> V_27 ) ;
goto abort;
}
V_52 -> V_433 &= ~ ( V_52 -> V_287 - 1 ) ;
V_52 -> V_500 = V_52 -> V_433 ;
if ( V_52 -> V_85 > V_491 &&
V_52 -> V_328 != V_93 ) {
if ( V_52 -> V_501 )
F_53 ( V_259
L_95
L_96 ,
F_125 ( V_52 ) ) ;
else {
F_53 ( V_84
L_97 ,
F_125 ( V_52 ) ) ;
goto abort;
}
}
if ( V_52 -> V_85 == 0 )
F_53 ( V_252 L_98
L_99 , F_125 ( V_52 ) , V_3 -> V_219 ,
V_52 -> V_27 - V_52 -> V_85 , V_52 -> V_27 ,
V_52 -> V_482 ) ;
else
F_53 ( V_275 L_100
L_101 ,
F_125 ( V_52 ) , V_3 -> V_219 ,
V_52 -> V_27 - V_52 -> V_85 ,
V_52 -> V_27 , V_52 -> V_482 ) ;
F_275 ( V_3 ) ;
if ( V_3 -> V_102 != V_93 ) {
V_3 -> V_414 = V_3 -> V_102 ;
F_12 ( & V_3 -> V_374 , 0 ) ;
F_26 ( V_448 , & V_52 -> V_265 ) ;
F_26 ( V_346 , & V_52 -> V_265 ) ;
F_74 ( V_445 , & V_52 -> V_265 ) ;
F_74 ( V_502 , & V_52 -> V_265 ) ;
V_52 -> V_503 = F_270 ( V_504 , V_52 ,
L_102 ) ;
}
if ( V_52 -> V_505 == & V_506 )
V_52 -> V_505 = NULL ;
else if ( V_52 -> V_432 . V_507 &&
F_276 ( & V_52 -> V_432 , & V_506 ) )
F_53 ( V_259
L_103 ,
F_125 ( V_52 ) ) ;
F_277 ( V_52 , F_220 ( V_52 , 0 , 0 ) ) ;
if ( V_52 -> V_340 ) {
int V_508 ;
bool V_509 = true ;
int V_288 = V_3 -> V_77 - V_3 -> V_94 ;
int V_278 = V_288 *
( ( V_52 -> V_287 << 9 ) / V_461 ) ;
if ( V_52 -> V_340 -> V_510 . V_511 < 2 * V_278 )
V_52 -> V_340 -> V_510 . V_511 = 2 * V_278 ;
F_278 ( V_52 -> V_340 , F_186 ) ;
V_52 -> V_340 -> V_510 . V_512 = V_52 ;
V_52 -> V_340 -> V_510 . V_513 = F_184 ;
V_508 = V_52 -> V_287 << 9 ;
F_279 ( V_52 -> V_340 , V_508 ) ;
F_280 ( V_52 -> V_340 , V_508 *
( V_3 -> V_27 - V_3 -> V_94 ) ) ;
V_278 = V_278 * V_461 ;
while ( ( V_278 - 1 ) & V_278 )
V_278 = ( V_278 | ( V_278 - 1 ) ) + 1 ;
V_52 -> V_340 -> V_514 . V_515 = V_278 ;
V_52 -> V_340 -> V_514 . V_516 = V_278 ;
V_52 -> V_340 -> V_514 . V_517 = 0 ;
F_269 (rdev, mddev) {
F_281 ( V_52 -> V_153 , V_88 -> V_138 ,
V_88 -> V_142 << 9 ) ;
F_281 ( V_52 -> V_153 , V_88 -> V_138 ,
V_88 -> V_141 << 9 ) ;
if ( ! F_282 ( F_18 ( V_88 -> V_138 ) ) ||
! F_18 ( V_88 -> V_138 ) ->
V_514 . V_517 )
V_509 = false ;
}
if ( V_509 &&
V_52 -> V_340 -> V_514 . V_518 >= V_278 &&
V_52 -> V_340 -> V_514 . V_516 >= V_278 )
F_283 ( V_519 ,
V_52 -> V_340 ) ;
else
F_284 ( V_519 ,
V_52 -> V_340 ) ;
}
return 0 ;
abort:
F_285 ( & V_52 -> V_53 ) ;
F_275 ( V_3 ) ;
F_256 ( V_3 ) ;
V_52 -> V_271 = NULL ;
F_53 ( V_275 L_104 , F_125 ( V_52 ) ) ;
return - V_481 ;
}
static int F_286 ( struct V_52 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
F_285 ( & V_52 -> V_53 ) ;
if ( V_52 -> V_340 )
V_52 -> V_340 -> V_510 . V_513 = NULL ;
F_256 ( V_3 ) ;
V_52 -> V_271 = NULL ;
V_52 -> V_505 = & V_506 ;
return 0 ;
}
static void F_287 ( struct V_520 * V_521 , struct V_52 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
int V_70 ;
F_288 ( V_521 , L_105 , V_52 -> V_219 ,
V_52 -> V_287 / 2 , V_52 -> V_488 ) ;
F_288 ( V_521 , L_106 , V_3 -> V_27 , V_3 -> V_27 - V_52 -> V_85 ) ;
for ( V_70 = 0 ; V_70 < V_3 -> V_27 ; V_70 ++ )
F_288 ( V_521 , L_107 ,
V_3 -> V_25 [ V_70 ] . V_88 &&
F_21 ( V_91 , & V_3 -> V_25 [ V_70 ] . V_88 -> V_61 ) ? L_108 : L_109 ) ;
F_288 ( V_521 , L_110 ) ;
}
static void F_275 ( struct V_2 * V_3 )
{
int V_70 ;
struct V_242 * V_522 ;
F_53 ( V_523 L_111 ) ;
if ( ! V_3 ) {
F_53 ( L_112 ) ;
return;
}
F_53 ( V_523 L_113 , V_3 -> V_219 ,
V_3 -> V_27 ,
V_3 -> V_27 - V_3 -> V_52 -> V_85 ) ;
for ( V_70 = 0 ; V_70 < V_3 -> V_27 ; V_70 ++ ) {
char V_249 [ V_250 ] ;
V_522 = V_3 -> V_25 + V_70 ;
if ( V_522 -> V_88 )
F_53 ( V_523 L_114 ,
V_70 , ! F_21 ( V_89 , & V_522 -> V_88 -> V_61 ) ,
F_144 ( V_522 -> V_88 -> V_138 , V_249 ) ) ;
}
}
static int F_289 ( struct V_52 * V_52 )
{
int V_70 ;
struct V_2 * V_3 = V_52 -> V_271 ;
struct V_242 * V_522 ;
int V_29 = 0 ;
unsigned long V_61 ;
for ( V_70 = 0 ; V_70 < V_3 -> V_27 ; V_70 ++ ) {
V_522 = V_3 -> V_25 + V_70 ;
if ( V_522 -> V_90
&& V_522 -> V_90 -> V_327 == V_93
&& ! F_21 ( V_89 , & V_522 -> V_90 -> V_61 )
&& ! F_148 ( V_91 , & V_522 -> V_90 -> V_61 ) ) {
if ( ! V_522 -> V_88
|| ! F_28 ( V_91 , & V_522 -> V_88 -> V_61 ) )
V_29 ++ ;
if ( V_522 -> V_88 ) {
F_74 ( V_89 , & V_522 -> V_88 -> V_61 ) ;
F_290 (
V_522 -> V_88 -> V_524 ) ;
}
F_290 ( V_522 -> V_90 -> V_524 ) ;
} else if ( V_522 -> V_88
&& V_522 -> V_88 -> V_327 == V_93
&& ! F_21 ( V_89 , & V_522 -> V_88 -> V_61 )
&& ! F_148 ( V_91 , & V_522 -> V_88 -> V_61 ) ) {
V_29 ++ ;
F_290 ( V_522 -> V_88 -> V_524 ) ;
}
}
F_151 ( & V_3 -> V_62 , V_61 ) ;
V_52 -> V_85 = F_58 ( V_3 ) ;
F_152 ( & V_3 -> V_62 , V_61 ) ;
F_275 ( V_3 ) ;
return V_29 ;
}
static int F_291 ( struct V_52 * V_52 , struct V_87 * V_88 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
int V_244 = 0 ;
int V_525 = V_88 -> V_476 ;
struct V_87 * * V_526 ;
struct V_242 * V_69 = V_3 -> V_25 + V_525 ;
F_275 ( V_3 ) ;
if ( V_88 == V_69 -> V_88 )
V_526 = & V_69 -> V_88 ;
else if ( V_88 == V_69 -> V_90 )
V_526 = & V_69 -> V_90 ;
else
return 0 ;
if ( V_525 >= V_3 -> V_27 &&
V_3 -> V_102 == V_93 )
F_26 ( V_91 , & V_88 -> V_61 ) ;
if ( F_21 ( V_91 , & V_88 -> V_61 ) ||
F_4 ( & V_88 -> V_127 ) ) {
V_244 = - V_527 ;
goto abort;
}
if ( ! F_21 ( V_89 , & V_88 -> V_61 ) &&
V_52 -> V_324 != V_3 -> V_324 &&
! F_62 ( V_3 ) &&
( ! V_69 -> V_90 || V_69 -> V_90 == V_88 ) &&
V_525 < V_3 -> V_27 ) {
V_244 = - V_527 ;
goto abort;
}
* V_526 = NULL ;
F_292 () ;
if ( F_4 ( & V_88 -> V_127 ) ) {
V_244 = - V_527 ;
* V_526 = V_88 ;
} else if ( V_69 -> V_90 ) {
V_69 -> V_88 = V_69 -> V_90 ;
F_26 ( V_485 , & V_69 -> V_90 -> V_61 ) ;
F_72 () ;
V_69 -> V_90 = NULL ;
F_26 ( V_263 , & V_88 -> V_61 ) ;
} else
F_26 ( V_263 , & V_88 -> V_61 ) ;
abort:
F_275 ( V_3 ) ;
return V_244 ;
}
static int F_293 ( struct V_52 * V_52 , struct V_87 * V_88 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
int V_244 = - V_528 ;
int V_26 ;
struct V_242 * V_69 ;
int V_65 = 0 ;
int V_529 = V_3 -> V_27 - 1 ;
if ( V_52 -> V_324 == V_3 -> V_324 )
return - V_527 ;
if ( V_88 -> V_486 < 0 && F_62 ( V_3 ) )
return - V_460 ;
if ( V_88 -> V_476 >= 0 )
V_65 = V_529 = V_88 -> V_476 ;
if ( V_88 -> V_486 >= 0 &&
V_88 -> V_486 >= V_65 &&
V_3 -> V_25 [ V_88 -> V_486 ] . V_88 == NULL )
V_65 = V_88 -> V_486 ;
for ( V_26 = V_65 ; V_26 <= V_529 ; V_26 ++ ) {
V_69 = V_3 -> V_25 + V_26 ;
if ( V_69 -> V_88 == NULL ) {
F_26 ( V_91 , & V_88 -> V_61 ) ;
V_88 -> V_476 = V_26 ;
V_244 = 0 ;
if ( V_88 -> V_486 != V_26 )
V_3 -> V_447 = 1 ;
F_294 ( V_69 -> V_88 , V_88 ) ;
goto V_66;
}
}
for ( V_26 = V_65 ; V_26 <= V_529 ; V_26 ++ ) {
V_69 = V_3 -> V_25 + V_26 ;
if ( F_21 ( V_263 , & V_69 -> V_88 -> V_61 ) &&
V_69 -> V_90 == NULL ) {
F_26 ( V_91 , & V_88 -> V_61 ) ;
F_74 ( V_485 , & V_88 -> V_61 ) ;
V_88 -> V_476 = V_26 ;
V_244 = 0 ;
V_3 -> V_447 = 1 ;
F_294 ( V_69 -> V_90 , V_88 ) ;
break;
}
}
V_66:
F_275 ( V_3 ) ;
return V_244 ;
}
static int F_295 ( struct V_52 * V_52 , T_1 V_11 )
{
T_1 V_238 ;
V_11 &= ~ ( ( T_1 ) V_52 -> V_287 - 1 ) ;
V_238 = F_220 ( V_52 , V_11 , V_52 -> V_27 ) ;
if ( V_52 -> V_530 &&
V_52 -> V_531 > V_238 )
return - V_460 ;
if ( V_52 -> V_316 ) {
int V_532 = F_296 ( V_52 -> V_316 , V_11 , 0 , 0 ) ;
if ( V_532 )
return V_532 ;
}
F_277 ( V_52 , V_238 ) ;
F_297 ( V_52 -> V_153 , V_52 -> V_531 ) ;
F_298 ( V_52 -> V_153 ) ;
if ( V_11 > V_52 -> V_433 &&
V_52 -> V_328 > V_52 -> V_433 ) {
V_52 -> V_328 = V_52 -> V_433 ;
F_74 ( V_264 , & V_52 -> V_265 ) ;
}
V_52 -> V_433 = V_11 ;
V_52 -> V_500 = V_11 ;
return 0 ;
}
static int F_299 ( struct V_52 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
if ( ( ( V_52 -> V_287 << 9 ) / V_150 ) * 4
> V_3 -> V_99 ||
( ( V_52 -> V_387 << 9 ) / V_150 ) * 4
> V_3 -> V_99 ) {
F_53 ( V_259 L_115 ,
F_125 ( V_52 ) ,
( ( F_124 ( V_52 -> V_287 , V_52 -> V_387 ) << 9 )
/ V_150 ) * 4 ) ;
return 0 ;
}
return 1 ;
}
static int F_300 ( struct V_52 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
if ( V_52 -> V_484 == 0 &&
V_52 -> V_482 == V_52 -> V_488 &&
V_52 -> V_387 == V_52 -> V_287 )
return 0 ;
if ( F_62 ( V_3 ) )
return - V_460 ;
if ( V_52 -> V_484 < 0 ) {
int F_249 = 2 ;
if ( V_52 -> V_219 == 6 )
F_249 = 4 ;
if ( V_52 -> V_27 + V_52 -> V_484 < F_249 )
return - V_460 ;
}
if ( ! F_299 ( V_52 ) )
return - V_533 ;
return F_128 ( V_3 , ( V_3 -> V_77
+ V_52 -> V_484 ) ) ;
}
static int F_301 ( struct V_52 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
struct V_87 * V_88 ;
int V_534 = 0 ;
unsigned long V_61 ;
if ( F_21 ( V_502 , & V_52 -> V_265 ) )
return - V_527 ;
if ( ! F_299 ( V_52 ) )
return - V_533 ;
if ( F_62 ( V_3 ) )
return - V_460 ;
F_269 (rdev, mddev) {
if ( ! F_21 ( V_91 , & V_88 -> V_61 )
&& ! F_21 ( V_89 , & V_88 -> V_61 ) )
V_534 ++ ;
}
if ( V_534 - V_52 -> V_85 < V_52 -> V_484 - V_3 -> V_94 )
return - V_460 ;
if ( F_220 ( V_52 , 0 , V_3 -> V_27 + V_52 -> V_484 )
< V_52 -> V_531 ) {
F_53 ( V_84 L_116
L_117 , F_125 ( V_52 ) ) ;
return - V_460 ;
}
F_12 ( & V_3 -> V_374 , 0 ) ;
F_64 ( & V_3 -> V_62 ) ;
V_3 -> V_77 = V_3 -> V_27 ;
V_3 -> V_27 += V_52 -> V_484 ;
V_3 -> V_286 = V_3 -> V_287 ;
V_3 -> V_287 = V_52 -> V_387 ;
V_3 -> V_284 = V_3 -> V_283 ;
V_3 -> V_283 = V_52 -> V_482 ;
V_3 -> V_76 ++ ;
F_72 () ;
if ( V_52 -> V_413 )
V_3 -> V_102 = F_220 ( V_52 , 0 , 0 ) ;
else
V_3 -> V_102 = 0 ;
V_3 -> V_414 = V_3 -> V_102 ;
F_67 ( & V_3 -> V_62 ) ;
if ( V_52 -> V_484 >= 0 ) {
F_269 (rdev, mddev)
if ( V_88 -> V_476 < 0 &&
! F_21 ( V_89 , & V_88 -> V_61 ) ) {
if ( F_293 ( V_52 , V_88 ) == 0 ) {
if ( V_88 -> V_476
>= V_3 -> V_77 )
F_74 ( V_91 , & V_88 -> V_61 ) ;
else
V_88 -> V_327 = 0 ;
if ( F_302 ( V_52 , V_88 ) )
;
}
} else if ( V_88 -> V_476 >= V_3 -> V_77
&& ! F_21 ( V_89 , & V_88 -> V_61 ) ) {
F_74 ( V_91 , & V_88 -> V_61 ) ;
}
F_151 ( & V_3 -> V_62 , V_61 ) ;
V_52 -> V_85 = F_58 ( V_3 ) ;
F_152 ( & V_3 -> V_62 , V_61 ) ;
}
V_52 -> V_27 = V_3 -> V_27 ;
V_52 -> V_92 = V_3 -> V_102 ;
F_74 ( V_274 , & V_52 -> V_61 ) ;
F_26 ( V_448 , & V_52 -> V_265 ) ;
F_26 ( V_346 , & V_52 -> V_265 ) ;
F_74 ( V_445 , & V_52 -> V_265 ) ;
F_74 ( V_502 , & V_52 -> V_265 ) ;
V_52 -> V_503 = F_270 ( V_504 , V_52 ,
L_102 ) ;
if ( ! V_52 -> V_503 ) {
V_52 -> V_265 = 0 ;
F_64 ( & V_3 -> V_62 ) ;
V_52 -> V_27 = V_3 -> V_27 = V_3 -> V_77 ;
F_269 (rdev, mddev)
V_88 -> V_141 = V_88 -> V_142 ;
F_303 () ;
V_3 -> V_102 = V_93 ;
V_52 -> V_92 = V_93 ;
F_67 ( & V_3 -> V_62 ) ;
return - V_535 ;
}
V_3 -> V_436 = V_435 ;
F_27 ( V_52 -> V_503 ) ;
F_304 ( V_52 ) ;
return 0 ;
}
static void F_228 ( struct V_2 * V_3 )
{
if ( ! F_21 ( V_272 , & V_3 -> V_52 -> V_265 ) ) {
struct V_87 * V_88 ;
F_64 ( & V_3 -> V_62 ) ;
V_3 -> V_77 = V_3 -> V_27 ;
F_269 (rdev, conf->mddev)
V_88 -> V_142 = V_88 -> V_141 ;
F_303 () ;
V_3 -> V_102 = V_93 ;
F_67 ( & V_3 -> V_62 ) ;
F_31 ( & V_3 -> V_231 ) ;
if ( V_3 -> V_52 -> V_340 ) {
int V_288 = V_3 -> V_27 - V_3 -> V_94 ;
int V_278 = V_288 * ( ( V_3 -> V_287 << 9 )
/ V_461 ) ;
if ( V_3 -> V_52 -> V_340 -> V_510 . V_511 < 2 * V_278 )
V_3 -> V_52 -> V_340 -> V_510 . V_511 = 2 * V_278 ;
}
}
}
static void F_305 ( struct V_52 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
if ( ! F_21 ( V_272 , & V_52 -> V_265 ) ) {
if ( V_52 -> V_484 > 0 ) {
F_277 ( V_52 , F_220 ( V_52 , 0 , 0 ) ) ;
F_297 ( V_52 -> V_153 , V_52 -> V_531 ) ;
F_298 ( V_52 -> V_153 ) ;
} else {
int V_410 ;
F_64 ( & V_3 -> V_62 ) ;
V_52 -> V_85 = F_58 ( V_3 ) ;
F_67 ( & V_3 -> V_62 ) ;
for ( V_410 = V_3 -> V_27 ;
V_410 < V_3 -> V_27 - V_52 -> V_484 ;
V_410 ++ ) {
struct V_87 * V_88 = V_3 -> V_25 [ V_410 ] . V_88 ;
if ( V_88 )
F_26 ( V_91 , & V_88 -> V_61 ) ;
V_88 = V_3 -> V_25 [ V_410 ] . V_90 ;
if ( V_88 )
F_26 ( V_91 , & V_88 -> V_61 ) ;
}
}
V_52 -> V_488 = V_3 -> V_283 ;
V_52 -> V_287 = V_3 -> V_287 ;
V_52 -> V_92 = V_93 ;
V_52 -> V_484 = 0 ;
V_52 -> V_413 = 0 ;
}
}
static void F_306 ( struct V_52 * V_52 , int V_39 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
switch( V_39 ) {
case 2 :
F_31 ( & V_3 -> V_231 ) ;
break;
case 1 :
F_64 ( & V_3 -> V_62 ) ;
V_3 -> V_97 = 2 ;
F_65 ( V_3 -> V_58 ,
F_4 ( & V_3 -> V_42 ) == 0 &&
F_4 ( & V_3 -> V_390 ) == 0 ,
V_3 -> V_62 ) ;
V_3 -> V_97 = 1 ;
F_67 ( & V_3 -> V_62 ) ;
F_31 ( & V_3 -> V_231 ) ;
break;
case 0 :
F_64 ( & V_3 -> V_62 ) ;
V_3 -> V_97 = 0 ;
F_31 ( & V_3 -> V_58 ) ;
F_31 ( & V_3 -> V_231 ) ;
F_67 ( & V_3 -> V_62 ) ;
break;
}
}
static void * F_307 ( struct V_52 * V_52 , int V_219 )
{
struct V_536 * V_537 = V_52 -> V_271 ;
T_1 V_11 ;
if ( V_537 -> V_538 > 1 ) {
F_53 ( V_84 L_118 ,
F_125 ( V_52 ) ) ;
return F_264 ( - V_460 ) ;
}
V_11 = V_537 -> V_539 [ 0 ] . V_540 ;
F_154 ( V_11 , V_537 -> V_539 [ 0 ] . V_541 ) ;
V_52 -> V_433 = V_11 ;
V_52 -> V_480 = V_219 ;
V_52 -> V_482 = V_294 ;
V_52 -> V_387 = V_52 -> V_287 ;
V_52 -> V_27 += 1 ;
V_52 -> V_484 = 1 ;
V_52 -> V_328 = V_93 ;
return F_263 ( V_52 ) ;
}
static void * F_308 ( struct V_52 * V_52 )
{
int V_542 ;
if ( V_52 -> V_27 != 2 ||
V_52 -> V_85 > 1 )
return F_264 ( - V_460 ) ;
V_542 = 64 * 2 ;
while ( V_542 && ( V_52 -> V_531 & ( V_542 - 1 ) ) )
V_542 >>= 1 ;
if ( ( V_542 << 9 ) < V_150 )
return F_264 ( - V_460 ) ;
V_52 -> V_480 = 5 ;
V_52 -> V_482 = V_291 ;
V_52 -> V_387 = V_542 ;
return F_263 ( V_52 ) ;
}
static void * F_309 ( struct V_52 * V_52 )
{
int V_482 ;
switch ( V_52 -> V_488 ) {
case V_298 :
V_482 = V_289 ;
break;
case V_299 :
V_482 = V_290 ;
break;
case V_300 :
V_482 = V_291 ;
break;
case V_301 :
V_482 = V_292 ;
break;
case V_302 :
V_482 = V_293 ;
break;
case V_294 :
V_482 = V_294 ;
break;
default:
return F_264 ( - V_460 ) ;
}
V_52 -> V_480 = 5 ;
V_52 -> V_482 = V_482 ;
V_52 -> V_484 = - 1 ;
V_52 -> V_27 -= 1 ;
return F_263 ( V_52 ) ;
}
static int F_310 ( struct V_52 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_271 ;
int V_543 = V_52 -> V_387 ;
if ( V_52 -> V_482 >= 0 && ! F_265 ( V_52 -> V_482 ) )
return - V_460 ;
if ( V_543 > 0 ) {
if ( ! F_267 ( V_543 ) )
return - V_460 ;
if ( V_543 < ( V_461 >> 9 ) )
return - V_460 ;
if ( V_52 -> V_531 & ( V_543 - 1 ) )
return - V_460 ;
}
if ( V_52 -> V_27 == 2 ) {
if ( V_52 -> V_482 >= 0 ) {
V_3 -> V_283 = V_52 -> V_482 ;
V_52 -> V_488 = V_52 -> V_482 ;
}
if ( V_543 > 0 ) {
V_3 -> V_287 = V_543 ;
V_52 -> V_287 = V_543 ;
}
F_74 ( V_274 , & V_52 -> V_61 ) ;
F_27 ( V_52 -> V_53 ) ;
}
return F_300 ( V_52 ) ;
}
static int F_311 ( struct V_52 * V_52 )
{
int V_543 = V_52 -> V_387 ;
if ( V_52 -> V_482 >= 0 && ! F_266 ( V_52 -> V_482 ) )
return - V_460 ;
if ( V_543 > 0 ) {
if ( ! F_267 ( V_543 ) )
return - V_460 ;
if ( V_543 < ( V_461 >> 9 ) )
return - V_460 ;
if ( V_52 -> V_531 & ( V_543 - 1 ) )
return - V_460 ;
}
return F_300 ( V_52 ) ;
}
static void * F_312 ( struct V_52 * V_52 )
{
if ( V_52 -> V_219 == 0 )
return F_307 ( V_52 , 5 ) ;
if ( V_52 -> V_219 == 1 )
return F_308 ( V_52 ) ;
if ( V_52 -> V_219 == 4 ) {
V_52 -> V_482 = V_294 ;
V_52 -> V_480 = 5 ;
return F_263 ( V_52 ) ;
}
if ( V_52 -> V_219 == 6 )
return F_309 ( V_52 ) ;
return F_264 ( - V_460 ) ;
}
static void * F_313 ( struct V_52 * V_52 )
{
if ( V_52 -> V_219 == 0 )
return F_307 ( V_52 , 4 ) ;
if ( V_52 -> V_219 == 5 &&
V_52 -> V_488 == V_294 ) {
V_52 -> V_482 = 0 ;
V_52 -> V_480 = 4 ;
return F_263 ( V_52 ) ;
}
return F_264 ( - V_460 ) ;
}
static void * F_314 ( struct V_52 * V_52 )
{
int V_482 ;
if ( V_52 -> V_544 != & V_545 )
return F_264 ( - V_460 ) ;
if ( V_52 -> V_85 > 1 )
return F_264 ( - V_460 ) ;
if ( V_52 -> V_27 > 253 )
return F_264 ( - V_460 ) ;
if ( V_52 -> V_27 < 3 )
return F_264 ( - V_460 ) ;
switch ( V_52 -> V_488 ) {
case V_289 :
V_482 = V_298 ;
break;
case V_290 :
V_482 = V_299 ;
break;
case V_291 :
V_482 = V_300 ;
break;
case V_292 :
V_482 = V_301 ;
break;
case V_293 :
V_482 = V_302 ;
break;
case V_294 :
V_482 = V_294 ;
break;
default:
return F_264 ( - V_460 ) ;
}
V_52 -> V_480 = 6 ;
V_52 -> V_482 = V_482 ;
V_52 -> V_484 = 1 ;
V_52 -> V_27 += 1 ;
return F_263 ( V_52 ) ;
}
static int T_7 F_315 ( void )
{
F_316 ( & V_546 ) ;
F_316 ( & V_545 ) ;
F_316 ( & V_547 ) ;
return 0 ;
}
static void F_317 ( void )
{
F_318 ( & V_546 ) ;
F_318 ( & V_545 ) ;
F_318 ( & V_547 ) ;
}
