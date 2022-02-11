static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
}
static T_1 * F_2 ( struct V_1 * V_2 , unsigned long V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
struct V_9 * V_10 ;
T_1 * V_11 = NULL ;
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
V_10 = V_8 -> V_10 ;
if ( V_10 ) {
T_1 * V_13 = F_4 ( V_6 ) ;
unsigned long V_14 , V_15 ;
V_11 = V_10 -> V_16 ;
if ( F_5 ( V_10 ) )
memcpy ( V_11 , V_13 , sizeof( T_1 ) * V_17 ) ;
V_15 = ( unsigned long ) V_11 ;
V_14 = F_6 ( & V_2 -> V_18 , V_6 , V_15 ) ;
if ( V_14 != V_6 ) {
V_11 = F_4 ( V_14 ) ;
if ( V_14 & V_19 )
V_11 = NULL ;
} else {
if ( V_8 -> V_20 ) {
F_7 ( V_8 -> V_20 ) ;
V_8 -> V_20 = NULL ;
}
}
}
return V_11 ;
}
static T_2 void F_8 ( void )
{
int V_21 ;
V_22 = F_9 ( sizeof( V_23 ) * V_24 ,
V_25 ) ;
if ( ! V_22 )
F_10 ( L_1 ) ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ )
F_11 ( & V_22 [ V_21 ] ) ;
}
static inline void F_8 ( void )
{
}
static inline unsigned int F_12 ( T_3 V_26 , T_3 V_27 , int V_28 ,
int V_29 )
{
return F_13 ( ( V_30 T_1 ) V_26 , ( V_30 T_1 ) V_27 ,
V_28 , V_29 )
& V_31 ;
}
static inline int F_14 ( struct V_32 * V_32 )
{
return F_15 ( & V_32 -> V_33 . F_14 ) ;
}
static struct V_7 * F_16 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_35 -> V_38 ;
struct V_7 * V_39 = NULL ;
for ( V_37 -> V_40 = V_31 ; V_37 -> V_40 >= 0 ; -- V_37 -> V_40 ) {
if ( ! F_17 ( V_41 [ V_37 -> V_40 ] . V_42 ) )
continue;
F_18 () ;
V_39 = F_19 ( V_41 [ V_37 -> V_40 ] . V_42 ) ;
while ( V_39 ) {
if ( F_20 ( V_39 -> V_2 . V_4 ) == F_21 ( V_35 ) &&
V_39 -> F_14 == V_37 -> V_29 )
return V_39 ;
V_39 = F_19 ( V_39 -> V_2 . V_43 ) ;
}
F_22 () ;
}
return V_39 ;
}
static struct V_7 * F_23 ( struct V_34 * V_35 ,
struct V_7 * V_39 )
{
struct V_36 * V_37 = V_35 -> V_38 ;
V_39 = F_19 ( V_39 -> V_2 . V_43 ) ;
while ( ! V_39 ) {
F_22 () ;
do {
if ( -- V_37 -> V_40 < 0 )
return NULL ;
} while ( ! F_17 ( V_41 [ V_37 -> V_40 ] . V_42 ) );
F_18 () ;
V_39 = F_19 ( V_41 [ V_37 -> V_40 ] . V_42 ) ;
}
return V_39 ;
}
static struct V_7 * F_24 ( struct V_34 * V_35 ,
struct V_7 * V_39 )
{
struct V_36 * V_37 = V_35 -> V_38 ;
while ( ( V_39 = F_23 ( V_35 , V_39 ) ) != NULL ) {
if ( F_20 ( V_39 -> V_2 . V_4 ) != F_21 ( V_35 ) )
continue;
if ( V_39 -> F_14 == V_37 -> V_29 )
break;
}
return V_39 ;
}
static struct V_7 * F_25 ( struct V_34 * V_35 , T_4 V_44 )
{
struct V_7 * V_39 = F_16 ( V_35 ) ;
if ( V_39 )
while ( V_44 && ( V_39 = F_24 ( V_35 , V_39 ) ) )
-- V_44 ;
return V_44 ? NULL : V_39 ;
}
static void * F_26 ( struct V_34 * V_35 , T_4 * V_44 )
{
struct V_36 * V_37 = V_35 -> V_38 ;
if ( * V_44 )
return F_25 ( V_35 , * V_44 - 1 ) ;
V_37 -> V_29 = F_14 ( F_21 ( V_35 ) ) ;
return V_45 ;
}
static void * F_27 ( struct V_34 * V_35 , void * V_46 , T_4 * V_44 )
{
struct V_7 * V_39 ;
if ( V_46 == V_45 )
V_39 = F_16 ( V_35 ) ;
else
V_39 = F_24 ( V_35 , V_46 ) ;
++ * V_44 ;
return V_39 ;
}
static void F_28 ( struct V_34 * V_35 , void * V_46 )
{
if ( V_46 && V_46 != V_45 )
F_22 () ;
}
static int F_29 ( struct V_34 * V_35 , void * V_46 )
{
if ( V_46 == V_45 )
F_30 ( V_35 , L_2 ,
L_3
L_4
L_5 ) ;
else {
struct V_7 * V_39 = V_46 ;
int V_47 ;
F_30 ( V_35 , L_6
L_7 ,
V_39 -> V_2 . V_4 ? V_39 -> V_2 . V_4 -> V_48 : L_8 ,
( V_30 T_1 ) V_39 -> V_12 ,
( V_30 T_1 ) V_39 -> V_49 ,
V_39 -> V_50 , F_15 ( & V_39 -> V_2 . V_51 ) ,
V_39 -> V_2 . V_52 , 0 , ( V_30 T_1 ) V_39 -> V_53 ,
F_31 ( & V_39 -> V_2 ) + 40 ,
F_32 ( & V_39 -> V_2 , V_54 ) ,
( int ) ( ( F_32 ( & V_39 -> V_2 , V_55 ) >> 3 ) +
F_32 ( & V_39 -> V_2 , V_56 ) ) ,
V_39 -> V_57 ,
V_39 -> V_2 . V_58 ? F_15 ( & V_39 -> V_2 . V_58 -> V_59 ) : - 1 ,
V_39 -> V_2 . V_58 ? ( V_39 -> V_2 . V_58 -> V_60 ==
V_61 ) : 0 ,
V_39 -> V_62 , & V_47 ) ;
F_30 ( V_35 , L_9 , 127 - V_47 , L_10 ) ;
}
return 0 ;
}
static int F_33 ( struct V_63 * V_63 , struct V_64 * V_64 )
{
return F_34 ( V_63 , V_64 , & V_65 ,
sizeof( struct V_36 ) ) ;
}
static void * F_35 ( struct V_34 * V_35 , T_4 * V_44 )
{
int V_66 ;
if ( * V_44 == 0 )
return V_45 ;
for ( V_66 = * V_44 - 1 ; V_66 < V_67 ; ++ V_66 ) {
if ( ! F_36 ( V_66 ) )
continue;
* V_44 = V_66 + 1 ;
return & F_37 ( V_68 , V_66 ) ;
}
return NULL ;
}
static void * F_38 ( struct V_34 * V_35 , void * V_46 , T_4 * V_44 )
{
int V_66 ;
for ( V_66 = * V_44 ; V_66 < V_67 ; ++ V_66 ) {
if ( ! F_36 ( V_66 ) )
continue;
* V_44 = V_66 + 1 ;
return & F_37 ( V_68 , V_66 ) ;
}
return NULL ;
}
static void F_39 ( struct V_34 * V_35 , void * V_46 )
{
}
static int F_40 ( struct V_34 * V_35 , void * V_46 )
{
struct V_68 * V_37 = V_46 ;
if ( V_46 == V_45 ) {
F_30 ( V_35 , L_11 ) ;
return 0 ;
}
F_30 ( V_35 , L_12
L_13 ,
F_41 ( & V_69 ) ,
V_37 -> V_70 ,
V_37 -> V_71 ,
V_37 -> V_72 ,
V_37 -> V_73 ,
V_37 -> V_74 ,
V_37 -> V_75 ,
V_37 -> V_76 ,
V_37 -> V_77 ,
V_37 -> V_78 ,
V_37 -> V_79 ,
V_37 -> V_80 ,
V_37 -> V_81 ,
V_37 -> V_82 ,
V_37 -> V_83 ,
V_37 -> V_84 ,
V_37 -> V_85
) ;
return 0 ;
}
static int F_42 ( struct V_63 * V_63 , struct V_64 * V_64 )
{
return F_43 ( V_64 , & V_86 ) ;
}
static int F_44 ( struct V_34 * V_87 , void * V_46 )
{
struct V_88 * V_2 , * V_89 ;
unsigned int V_21 , V_90 ;
V_2 = F_45 ( 256 , sizeof( struct V_88 ) , V_25 ) ;
if ( ! V_2 )
return - V_91 ;
F_46 (i) {
V_89 = (struct V_88 * ) F_47 ( V_88 , V_21 ) ;
for ( V_90 = 0 ; V_90 < 256 ; V_90 ++ ) {
V_2 [ V_90 ] . V_92 += V_89 [ V_90 ] . V_92 ;
V_2 [ V_90 ] . V_93 += V_89 [ V_90 ] . V_93 ;
V_2 [ V_90 ] . V_94 += V_89 [ V_90 ] . V_94 ;
V_2 [ V_90 ] . V_95 += V_89 [ V_90 ] . V_95 ;
}
}
F_48 ( V_87 , V_2 , 256 * sizeof( struct V_88 ) ) ;
F_49 ( V_2 ) ;
return 0 ;
}
static int F_50 ( struct V_63 * V_63 , struct V_64 * V_64 )
{
return F_51 ( V_64 , F_44 , NULL ) ;
}
static int T_5 F_52 ( struct V_32 * V_32 )
{
struct V_96 * V_97 ;
V_97 = F_53 ( V_32 , L_14 , V_98 ,
& V_99 ) ;
if ( ! V_97 )
goto V_100;
V_97 = F_54 ( L_14 , V_98 ,
V_32 -> V_101 , & V_102 ) ;
if ( ! V_97 )
goto V_103;
#ifdef F_55
V_97 = F_54 ( L_15 , 0 , V_32 -> V_104 , & V_105 ) ;
if ( ! V_97 )
goto V_106;
#endif
return 0 ;
#ifdef F_55
V_106:
F_56 ( L_14 , V_32 -> V_101 ) ;
#endif
V_103:
F_56 ( L_14 , V_32 -> V_104 ) ;
V_100:
return - V_91 ;
}
static void T_6 F_57 ( struct V_32 * V_32 )
{
F_56 ( L_14 , V_32 -> V_101 ) ;
F_56 ( L_14 , V_32 -> V_104 ) ;
#ifdef F_55
F_56 ( L_15 , V_32 -> V_104 ) ;
#endif
}
static int T_2 F_58 ( void )
{
return F_59 ( & V_107 ) ;
}
static inline int F_58 ( void )
{
return 0 ;
}
static inline void F_60 ( struct V_7 * V_8 )
{
F_61 ( & V_8 -> V_2 . V_108 , V_109 ) ;
}
static inline void F_62 ( struct V_7 * V_8 )
{
F_63 ( V_8 ) ;
F_61 ( & V_8 -> V_2 . V_108 , V_109 ) ;
}
static inline int F_64 ( struct V_7 * V_110 )
{
return ( V_110 -> V_50 & ( V_111 | V_112 ) ) &&
F_65 ( V_110 ) && V_110 -> V_2 . V_43 ;
}
static inline int F_66 ( struct V_7 * V_110 )
{
return ( V_110 -> V_50 & ( V_113 | V_114 ) ) ||
( V_110 -> V_10 && V_110 -> V_10 -> V_115 ) ;
}
static int F_67 ( struct V_7 * V_110 , unsigned long V_116 , unsigned long V_117 )
{
unsigned long V_118 ;
int V_119 = 0 ;
if ( F_15 ( & V_110 -> V_2 . V_51 ) )
goto V_120;
V_118 = V_121 - V_110 -> V_2 . V_122 ;
if ( ( V_118 <= V_116 && ! F_64 ( V_110 ) ) ||
( V_118 <= V_117 && F_66 ( V_110 ) ) )
goto V_120;
V_119 = 1 ;
V_120: return V_119 ;
}
static inline T_1 F_68 ( struct V_7 * V_8 )
{
T_1 V_123 = V_121 - V_8 -> V_2 . V_122 ;
V_123 = ~ V_123 & ~ ( 3 << 30 ) ;
if ( F_66 ( V_8 ) )
V_123 |= ( 1 << 31 ) ;
if ( F_69 ( V_8 ) ||
! ( V_8 -> V_50 & ( V_111 | V_112 | V_124 ) ) )
V_123 |= ( 1 << 30 ) ;
return V_123 ;
}
static inline bool F_70 ( const struct V_32 * V_32 )
{
return V_32 -> V_33 . V_125 <=
V_32 -> V_33 . V_126 ;
}
static inline bool F_71 ( const struct V_7 * V_127 ,
const struct V_7 * V_128 )
{
return ( ( ( ( V_30 T_1 ) V_127 -> V_129 ^ ( V_30 T_1 ) V_128 -> V_129 ) |
( ( V_30 T_1 ) V_127 -> V_130 ^ ( V_30 T_1 ) V_128 -> V_130 ) |
( V_127 -> V_131 ^ V_128 -> V_131 ) ) == 0 ) ;
}
static inline int F_72 ( struct V_7 * V_127 , struct V_7 * V_128 )
{
return ( ( ( V_30 T_1 ) V_127 -> V_129 ^ ( V_30 T_1 ) V_128 -> V_129 ) |
( ( V_30 T_1 ) V_127 -> V_130 ^ ( V_30 T_1 ) V_128 -> V_130 ) |
( V_127 -> V_132 ^ V_128 -> V_132 ) |
( V_127 -> V_57 ^ V_128 -> V_57 ) |
( V_127 -> V_133 ^ V_128 -> V_133 ) |
( V_127 -> V_131 ^ V_128 -> V_131 ) ) == 0 ;
}
static inline int F_73 ( struct V_7 * V_127 , struct V_7 * V_128 )
{
return F_74 ( F_20 ( V_127 -> V_2 . V_4 ) , F_20 ( V_128 -> V_2 . V_4 ) ) ;
}
static inline int F_75 ( struct V_7 * V_110 )
{
return V_110 -> F_14 != F_14 ( F_20 ( V_110 -> V_2 . V_4 ) ) ;
}
static void F_76 ( struct V_32 * V_32 , int V_134 )
{
unsigned int V_21 ;
struct V_7 * V_110 , * V_135 ;
for ( V_21 = 0 ; V_21 <= V_31 ; V_21 ++ ) {
struct V_7 T_7 * * V_136 ;
struct V_7 * V_137 ;
if ( V_134 && F_77 () )
F_78 () ;
V_110 = F_17 ( V_41 [ V_21 ] . V_42 ) ;
if ( ! V_110 )
continue;
F_79 ( F_80 ( V_21 ) ) ;
V_137 = NULL ;
V_136 = & V_41 [ V_21 ] . V_42 ;
V_110 = F_81 ( * V_136 ,
F_82 ( F_80 ( V_21 ) ) ) ;
while ( V_110 ) {
V_135 = F_81 ( V_110 -> V_2 . V_43 ,
F_82 ( F_80 ( V_21 ) ) ) ;
if ( ! V_32 ||
F_74 ( F_20 ( V_110 -> V_2 . V_4 ) , V_32 ) ) {
F_83 ( * V_136 , V_135 ) ;
F_83 ( V_110 -> V_2 . V_43 , V_137 ) ;
V_137 = V_110 ;
} else {
V_136 = & V_110 -> V_2 . V_43 ;
}
V_110 = V_135 ;
}
F_84 ( F_80 ( V_21 ) ) ;
for (; V_137 ; V_137 = V_135 ) {
V_135 = F_81 ( V_137 -> V_2 . V_43 , 1 ) ;
F_60 ( V_137 ) ;
}
}
}
static int F_85 ( const struct V_7 * V_138 , const struct V_7 * V_110 )
{
const struct V_7 * V_139 = V_138 ;
while ( V_139 != V_110 ) {
if ( F_71 ( V_139 , V_110 ) )
return 0 ;
V_139 = F_81 ( V_139 -> V_2 . V_43 , 1 ) ;
}
return V_140 ;
}
static void F_86 ( struct V_32 * V_32 )
{
unsigned char V_141 ;
F_87 ( & V_141 , sizeof( V_141 ) ) ;
F_88 ( V_141 + 1U , & V_32 -> V_33 . F_14 ) ;
}
void F_89 ( struct V_32 * V_32 , int V_142 )
{
F_86 ( V_32 ) ;
if ( V_142 >= 0 )
F_76 ( V_32 , ! F_90 () ) ;
}
void F_91 ( struct V_32 * V_32 )
{
F_76 ( V_32 , ! F_90 () ) ;
}
static void F_92 ( struct V_32 * V_32 )
{
if ( F_93 () )
F_94 ( V_143 L_16 ) ;
F_86 ( V_32 ) ;
}
static int F_95 ( struct V_144 * V_145 )
{
static unsigned long V_146 = V_147 ;
static unsigned long V_148 ;
static int V_149 ;
static int V_150 ;
struct V_7 * V_110 ;
struct V_7 T_7 * * V_151 ;
unsigned long V_152 = V_121 ;
int V_153 ;
int V_154 = F_96 ( & V_69 ) ;
F_97 ( V_80 ) ;
if ( V_152 - V_148 < V_155 &&
V_154 < V_156 ) {
F_97 ( V_81 ) ;
goto V_120;
}
V_154 = F_41 ( & V_69 ) ;
V_153 = V_154 - ( V_157 << V_158 ) ;
if ( V_153 <= 0 ) {
if ( V_150 < V_69 . V_159 )
V_150 = V_69 . V_159 ;
V_153 = V_154 - V_150 ;
if ( V_153 > 0 ) {
V_150 += F_98 (unsigned int, goal >> 1 , rt_hash_mask + 1 ) ;
V_153 = V_154 - V_150 ;
}
} else {
V_153 = F_99 (unsigned int, goal >> 1 , rt_hash_mask + 1 ) ;
V_150 = V_154 - V_153 ;
}
if ( V_152 - V_148 >= V_155 )
V_148 = V_152 ;
if ( V_153 <= 0 ) {
V_150 += V_153 ;
goto V_160;
}
do {
int V_21 , V_161 ;
for ( V_21 = V_31 , V_161 = V_149 ; V_21 >= 0 ; V_21 -- ) {
unsigned long V_162 = V_146 ;
V_161 = ( V_161 + 1 ) & V_31 ;
V_151 = & V_41 [ V_161 ] . V_42 ;
F_79 ( F_80 ( V_161 ) ) ;
while ( ( V_110 = F_81 ( * V_151 ,
F_82 ( F_80 ( V_161 ) ) ) ) != NULL ) {
if ( ! F_75 ( V_110 ) &&
! F_67 ( V_110 , V_162 , V_146 ) ) {
V_162 >>= 1 ;
V_151 = & V_110 -> V_2 . V_43 ;
continue;
}
* V_151 = V_110 -> V_2 . V_43 ;
F_60 ( V_110 ) ;
V_153 -- ;
}
F_84 ( F_80 ( V_161 ) ) ;
if ( V_153 <= 0 )
break;
}
V_149 = V_161 ;
if ( V_153 <= 0 )
goto V_160;
F_97 ( V_82 ) ;
if ( V_146 == 0 )
break;
V_146 >>= 1 ;
if ( F_96 ( & V_69 ) < V_156 )
goto V_120;
} while ( ! F_90 () && F_100 ( V_121 , V_152 ) );
if ( F_96 ( & V_69 ) < V_156 )
goto V_120;
if ( F_41 ( & V_69 ) < V_156 )
goto V_120;
if ( F_93 () )
F_94 ( V_143 L_17 ) ;
F_97 ( V_83 ) ;
return 1 ;
V_160:
V_146 += V_155 ;
if ( V_146 > V_163 ||
F_96 ( & V_69 ) < V_69 . V_159 ||
F_41 ( & V_69 ) < V_69 . V_159 )
V_146 = V_163 ;
V_120: return 0 ;
}
static int F_101 ( const struct V_7 * V_138 )
{
int V_164 = 0 ;
const struct V_7 * V_110 = V_138 ;
while ( V_110 ) {
V_164 += F_85 ( V_138 , V_110 ) ;
V_110 = F_81 ( V_110 -> V_2 . V_43 , 1 ) ;
}
return V_164 >> V_165 ;
}
static struct V_7 * F_102 ( unsigned V_166 , struct V_7 * V_8 ,
struct V_167 * V_168 , int V_169 )
{
struct V_7 * V_110 , * V_170 ;
struct V_7 T_7 * * V_151 , * * V_171 ;
unsigned long V_152 ;
T_1 V_172 ;
int V_173 ;
int V_174 = ! F_90 () ;
V_175:
V_173 = 0 ;
V_172 = ~ ( T_1 ) 0 ;
V_170 = NULL ;
V_171 = NULL ;
V_152 = V_121 ;
if ( ! F_70 ( F_20 ( V_8 -> V_2 . V_4 ) ) ) {
V_8 -> V_2 . V_176 |= V_177 ;
if ( V_8 -> V_178 == V_179 || F_69 ( V_8 ) ) {
int V_180 = F_103 ( & V_8 -> V_2 ) ;
if ( V_180 ) {
if ( F_93 () )
F_94 ( V_143
L_18 ) ;
F_63 ( V_8 ) ;
return F_104 ( V_180 ) ;
}
}
goto V_181;
}
V_151 = & V_41 [ V_166 ] . V_42 ;
F_79 ( F_80 ( V_166 ) ) ;
while ( ( V_110 = F_81 ( * V_151 ,
F_82 ( F_80 ( V_166 ) ) ) ) != NULL ) {
if ( F_75 ( V_110 ) ) {
* V_151 = V_110 -> V_2 . V_43 ;
F_60 ( V_110 ) ;
continue;
}
if ( F_72 ( V_110 , V_8 ) && F_73 ( V_110 , V_8 ) ) {
* V_151 = V_110 -> V_2 . V_43 ;
F_83 ( V_110 -> V_2 . V_43 ,
V_41 [ V_166 ] . V_42 ) ;
F_83 ( V_41 [ V_166 ] . V_42 , V_110 ) ;
F_105 ( & V_110 -> V_2 , V_152 ) ;
F_84 ( F_80 ( V_166 ) ) ;
F_62 ( V_8 ) ;
if ( V_168 )
F_106 ( V_168 , & V_110 -> V_2 ) ;
return V_110 ;
}
if ( ! F_15 ( & V_110 -> V_2 . V_51 ) ) {
T_1 V_123 = F_68 ( V_110 ) ;
if ( V_123 <= V_172 ) {
V_170 = V_110 ;
V_171 = V_151 ;
V_172 = V_123 ;
}
}
V_173 ++ ;
V_151 = & V_110 -> V_2 . V_43 ;
}
if ( V_170 ) {
if ( V_173 > V_157 ) {
* V_171 = V_170 -> V_2 . V_43 ;
F_60 ( V_170 ) ;
}
} else {
if ( V_173 > V_182 &&
F_101 ( V_41 [ V_166 ] . V_42 ) > V_182 ) {
struct V_32 * V_32 = F_20 ( V_8 -> V_2 . V_4 ) ;
int V_183 = ++ V_32 -> V_33 . V_125 ;
if ( ! F_70 ( V_32 ) ) {
F_94 ( V_143 L_19 ,
V_8 -> V_2 . V_4 -> V_48 , V_183 ) ;
}
F_92 ( V_32 ) ;
F_84 ( F_80 ( V_166 ) ) ;
V_166 = F_12 ( V_8 -> V_129 , V_8 -> V_130 ,
V_169 , F_14 ( V_32 ) ) ;
goto V_175;
}
}
if ( V_8 -> V_178 == V_179 || F_69 ( V_8 ) ) {
int V_180 = F_103 ( & V_8 -> V_2 ) ;
if ( V_180 ) {
F_84 ( F_80 ( V_166 ) ) ;
if ( V_180 != - V_184 ) {
F_62 ( V_8 ) ;
return F_104 ( V_180 ) ;
}
if ( V_174 -- > 0 ) {
int V_185 = V_157 ;
int V_186 = V_155 ;
V_157 = 1 ;
V_155 = 0 ;
F_95 ( & V_69 ) ;
V_155 = V_186 ;
V_157 = V_185 ;
goto V_175;
}
if ( F_93 () )
F_94 ( V_143 L_20 ) ;
F_62 ( V_8 ) ;
return F_104 ( - V_184 ) ;
}
}
V_8 -> V_2 . V_43 = V_41 [ V_166 ] . V_42 ;
F_83 ( V_41 [ V_166 ] . V_42 , V_8 ) ;
F_84 ( F_80 ( V_166 ) ) ;
V_181:
if ( V_168 )
F_106 ( V_168 , & V_8 -> V_2 ) ;
return V_8 ;
}
static T_1 F_107 ( void )
{
return F_15 ( & V_187 ) ;
}
void F_3 ( struct V_7 * V_8 , T_3 V_26 , int V_188 )
{
struct V_9 * V_10 ;
V_10 = F_108 ( V_26 , V_188 ) ;
if ( V_10 && F_6 ( & V_8 -> V_10 , NULL , V_10 ) != NULL )
F_109 ( V_10 ) ;
else
V_8 -> F_107 = F_107 () ;
}
static void F_110 ( struct V_189 * V_190 )
{
static F_111 ( V_191 ) ;
static T_1 V_192 ;
T_1 V_193 ;
F_79 ( & V_191 ) ;
V_193 = F_112 ( ( V_30 T_3 ) V_192 ^ V_190 -> V_26 ) ;
V_190 -> V_194 = F_113 ( V_193 & 0xFFFF ) ;
V_192 = V_193 ;
F_84 ( & V_191 ) ;
}
void F_114 ( struct V_189 * V_190 , struct V_1 * V_2 , int V_195 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
if ( V_8 ) {
if ( V_8 -> V_10 == NULL )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
if ( V_8 -> V_10 ) {
V_190 -> V_194 = F_113 ( F_115 ( V_8 -> V_10 , V_195 ) ) ;
return;
}
} else
F_94 ( V_196 L_21 ,
F_116 ( 0 ) ) ;
F_110 ( V_190 ) ;
}
static void F_117 ( unsigned V_166 , struct V_7 * V_8 )
{
struct V_7 T_7 * * V_151 ;
struct V_7 * V_139 ;
V_151 = & V_41 [ V_166 ] . V_42 ;
F_79 ( F_80 ( V_166 ) ) ;
F_63 ( V_8 ) ;
while ( ( V_139 = F_81 ( * V_151 ,
F_82 ( F_80 ( V_166 ) ) ) ) != NULL ) {
if ( V_139 == V_8 || F_75 ( V_139 ) ) {
* V_151 = V_139 -> V_2 . V_43 ;
F_60 ( V_139 ) ;
continue;
}
V_151 = & V_139 -> V_2 . V_43 ;
}
F_84 ( F_80 ( V_166 ) ) ;
}
void F_118 ( T_3 V_197 , T_3 V_26 , T_3 V_198 ,
T_3 V_27 , struct V_3 * V_4 )
{
struct V_199 * V_200 = F_119 ( V_4 ) ;
struct V_9 * V_10 ;
struct V_32 * V_32 ;
if ( ! V_200 )
return;
V_32 = F_20 ( V_4 ) ;
if ( V_198 == V_197 || ! F_120 ( V_200 ) ||
F_121 ( V_198 ) || F_122 ( V_198 ) ||
F_123 ( V_198 ) )
goto V_201;
if ( ! F_124 ( V_200 ) ) {
if ( ! F_125 ( V_200 , V_198 , V_197 ) )
goto V_201;
if ( F_126 ( V_200 ) && F_127 ( V_198 , V_4 ) )
goto V_201;
} else {
if ( F_128 ( V_32 , V_198 ) != V_179 )
goto V_201;
}
V_10 = F_108 ( V_26 , 1 ) ;
if ( V_10 ) {
V_10 -> V_202 . V_203 = V_198 ;
F_109 ( V_10 ) ;
F_129 ( & V_187 ) ;
}
return;
V_201:
#ifdef F_130
if ( F_131 ( V_200 ) && F_93 () )
F_94 ( V_204 L_22
L_23 ,
& V_197 , V_4 -> V_48 , & V_198 ,
& V_27 , & V_26 ) ;
#endif
;
}
static bool F_132 ( struct V_9 * V_10 )
{
unsigned long V_205 = F_133 ( V_10 -> V_115 ) ;
return V_205 &&
F_134 ( V_121 , V_205 ) &&
F_6 ( & V_10 -> V_115 , V_205 , 0 ) == V_205 ;
}
static bool F_135 ( struct V_9 * V_10 )
{
unsigned long V_205 = F_133 ( V_10 -> V_115 ) ;
return V_205 &&
F_6 ( & V_10 -> V_115 , V_205 , 0 ) == V_205 ;
}
static struct V_1 * F_136 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
struct V_1 * V_119 = V_2 ;
if ( V_8 ) {
if ( V_2 -> V_206 > 0 ) {
F_63 ( V_8 ) ;
V_119 = NULL ;
} else if ( V_8 -> V_50 & V_113 ) {
unsigned V_166 = F_12 ( V_8 -> V_129 , V_8 -> V_130 ,
V_8 -> V_133 ,
F_14 ( F_20 ( V_2 -> V_4 ) ) ) ;
F_117 ( V_166 , V_8 ) ;
V_119 = NULL ;
} else if ( V_8 -> V_10 && F_132 ( V_8 -> V_10 ) ) {
F_137 ( V_2 , V_207 , V_8 -> V_10 -> V_208 ) ;
}
}
return V_119 ;
}
void F_138 ( struct V_167 * V_168 )
{
struct V_7 * V_8 = F_139 ( V_168 ) ;
struct V_199 * V_200 ;
struct V_9 * V_10 ;
int V_209 ;
F_140 () ;
V_200 = F_119 ( V_8 -> V_2 . V_4 ) ;
if ( ! V_200 || ! F_141 ( V_200 ) ) {
F_142 () ;
return;
}
V_209 = F_131 ( V_200 ) ;
F_142 () ;
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
V_10 = V_8 -> V_10 ;
if ( ! V_10 ) {
F_143 ( V_168 , V_210 , V_211 , V_8 -> V_49 ) ;
return;
}
if ( F_144 ( V_121 , V_10 -> V_212 + V_213 ) )
V_10 -> V_214 = 0 ;
if ( V_10 -> V_214 >= V_215 ) {
V_10 -> V_212 = V_121 ;
return;
}
if ( V_10 -> V_214 == 0 ||
F_144 ( V_121 ,
( V_10 -> V_212 +
( V_216 << V_10 -> V_214 ) ) ) ) {
F_143 ( V_168 , V_210 , V_211 , V_8 -> V_49 ) ;
V_10 -> V_212 = V_121 ;
++ V_10 -> V_214 ;
#ifdef F_130
if ( V_209 &&
V_10 -> V_214 == V_215 &&
F_93 () )
F_94 ( V_143 L_24 ,
& F_145 ( V_168 ) -> V_27 , V_8 -> V_131 ,
& V_8 -> V_12 , & V_8 -> V_49 ) ;
#endif
}
}
static int F_146 ( struct V_167 * V_168 )
{
struct V_7 * V_8 = F_139 ( V_168 ) ;
struct V_9 * V_10 ;
unsigned long V_152 ;
bool V_217 ;
int V_218 ;
switch ( V_8 -> V_2 . error ) {
case V_219 :
default:
goto V_120;
case V_220 :
V_218 = V_221 ;
break;
case V_222 :
V_218 = V_223 ;
F_147 ( F_20 ( V_8 -> V_2 . V_4 ) ,
V_224 ) ;
break;
case V_225 :
V_218 = V_226 ;
break;
}
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
V_10 = V_8 -> V_10 ;
V_217 = true ;
if ( V_10 ) {
V_152 = V_121 ;
V_10 -> V_214 += V_152 - V_10 -> V_212 ;
if ( V_10 -> V_214 > V_227 )
V_10 -> V_214 = V_227 ;
V_10 -> V_212 = V_152 ;
if ( V_10 -> V_214 >= V_228 )
V_10 -> V_214 -= V_228 ;
else
V_217 = false ;
}
if ( V_217 )
F_143 ( V_168 , V_229 , V_218 , 0 ) ;
V_120: F_148 ( V_168 ) ;
return 0 ;
}
static inline unsigned short F_149 ( unsigned short V_230 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < F_150 ( V_231 ) ; V_21 ++ )
if ( V_230 > V_231 [ V_21 ] )
return V_231 [ V_21 ] ;
return 68 ;
}
unsigned short F_151 ( struct V_32 * V_32 , const struct V_189 * V_190 ,
unsigned short V_232 ,
struct V_3 * V_4 )
{
unsigned short V_230 = F_152 ( V_190 -> V_233 ) ;
unsigned short V_234 = 0 ;
struct V_9 * V_10 ;
V_10 = F_108 ( V_190 -> V_26 , 1 ) ;
if ( V_10 ) {
unsigned short V_235 = V_232 ;
if ( V_232 < 68 || V_232 >= V_230 ) {
if ( V_235 == 0 &&
V_230 >= 68 + ( V_190 -> V_236 << 2 ) )
V_230 -= V_190 -> V_236 << 2 ;
V_235 = F_149 ( V_230 ) ;
}
if ( V_235 < V_237 )
V_235 = V_237 ;
if ( ! V_10 -> V_115 || V_235 < V_10 -> V_238 ) {
unsigned long V_115 ;
V_115 = V_121 + V_239 ;
if ( ! V_115 )
V_115 = 1UL ;
V_234 = V_235 ;
V_10 -> V_238 = V_235 ;
V_10 -> V_115 = V_115 ;
}
F_109 ( V_10 ) ;
F_129 ( & V_187 ) ;
}
return V_234 ? : V_232 ;
}
static void F_153 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned long V_240 = F_133 ( V_10 -> V_115 ) ;
if ( ! V_240 )
return;
if ( F_154 ( V_121 , V_240 ) ) {
T_1 V_241 = F_155 ( V_2 ) ;
if ( V_10 -> V_238 < V_241 ) {
if ( ! V_10 -> V_208 )
V_10 -> V_208 = F_156 ( V_2 , V_207 ) ;
F_137 ( V_2 , V_207 , V_10 -> V_238 ) ;
}
} else if ( F_6 ( & V_10 -> V_115 , V_240 , 0 ) == V_240 )
F_137 ( V_2 , V_207 , V_10 -> V_208 ) ;
}
static void F_157 ( struct V_1 * V_2 , T_1 V_235 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
struct V_9 * V_10 ;
F_158 ( V_2 ) ;
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
V_10 = V_8 -> V_10 ;
if ( V_10 ) {
unsigned long V_115 = F_133 ( V_10 -> V_115 ) ;
if ( V_235 < V_237 )
V_235 = V_237 ;
if ( ! V_115 || V_235 < V_10 -> V_238 ) {
V_115 = V_121 + V_239 ;
if ( ! V_115 )
V_115 = 1UL ;
V_10 -> V_238 = V_235 ;
V_10 -> V_115 = V_115 ;
F_129 ( & V_187 ) ;
V_8 -> F_107 = F_107 () ;
}
F_153 ( V_2 , V_10 ) ;
}
}
static int F_159 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
T_3 V_242 = V_8 -> V_49 ;
F_158 ( & V_8 -> V_2 ) ;
F_160 ( V_8 -> V_2 . V_243 ) ;
V_8 -> V_2 . V_243 = NULL ;
V_8 -> V_49 = V_10 -> V_202 . V_203 ;
if ( F_103 ( & V_8 -> V_2 ) ||
! ( V_8 -> V_2 . V_243 -> V_244 & V_245 ) ) {
if ( V_8 -> V_2 . V_243 )
F_161 ( V_8 -> V_2 . V_243 , NULL ) ;
V_8 -> V_49 = V_242 ;
return - V_246 ;
} else {
V_8 -> V_50 |= V_113 ;
F_162 ( V_247 ,
V_8 -> V_2 . V_243 ) ;
}
return 0 ;
}
static struct V_1 * F_163 ( struct V_1 * V_2 , T_1 V_248 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
if ( F_75 ( V_8 ) )
return NULL ;
if ( V_8 -> F_107 != F_107 () ) {
struct V_9 * V_10 ;
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 0 ) ;
V_10 = V_8 -> V_10 ;
if ( V_10 ) {
F_153 ( V_2 , V_10 ) ;
if ( V_10 -> V_202 . V_203 &&
V_10 -> V_202 . V_203 != V_8 -> V_49 ) {
if ( F_159 ( V_2 , V_10 ) )
return NULL ;
}
}
V_8 -> F_107 = F_107 () ;
}
return V_2 ;
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
struct V_9 * V_10 = V_8 -> V_10 ;
if ( V_8 -> V_20 ) {
F_7 ( V_8 -> V_20 ) ;
V_8 -> V_20 = NULL ;
}
if ( V_10 ) {
V_8 -> V_10 = NULL ;
F_109 ( V_10 ) ;
}
}
static void F_165 ( struct V_167 * V_168 )
{
struct V_7 * V_8 ;
F_143 ( V_168 , V_229 , V_221 , 0 ) ;
V_8 = F_139 ( V_168 ) ;
if ( V_8 && V_8 -> V_10 && F_135 ( V_8 -> V_10 ) )
F_137 ( & V_8 -> V_2 , V_207 , V_8 -> V_10 -> V_208 ) ;
}
static int F_166 ( struct V_167 * V_168 )
{
F_94 ( V_196 L_25 ,
& F_145 ( V_168 ) -> V_27 , & F_145 ( V_168 ) -> V_26 ,
V_168 -> V_4 ? V_168 -> V_4 -> V_48 : L_26 ) ;
F_148 ( V_168 ) ;
F_167 ( 1 ) ;
return 0 ;
}
void F_168 ( T_8 * V_249 , struct V_167 * V_168 , struct V_7 * V_8 )
{
T_3 V_89 ;
if ( F_69 ( V_8 ) )
V_89 = F_145 ( V_168 ) -> V_27 ;
else {
struct V_250 V_251 ;
struct V_252 V_253 ;
struct V_189 * V_190 ;
V_190 = F_145 ( V_168 ) ;
memset ( & V_253 , 0 , sizeof( V_253 ) ) ;
V_253 . V_26 = V_190 -> V_26 ;
V_253 . V_27 = V_190 -> V_27 ;
V_253 . V_254 = V_190 -> V_255 ;
V_253 . V_256 = V_8 -> V_2 . V_4 -> V_169 ;
V_253 . V_257 = V_168 -> V_4 -> V_169 ;
V_253 . V_258 = V_168 -> V_259 ;
F_140 () ;
if ( F_169 ( F_20 ( V_8 -> V_2 . V_4 ) , & V_253 , & V_251 ) == 0 )
V_89 = F_170 ( F_20 ( V_8 -> V_2 . V_4 ) , V_251 ) ;
else
V_89 = F_171 ( V_8 -> V_2 . V_4 , V_8 -> V_49 ,
V_260 ) ;
F_142 () ;
}
memcpy ( V_249 , & V_89 , 4 ) ;
}
static void F_172 ( struct V_7 * V_8 , T_1 V_261 )
{
if ( ! ( V_8 -> V_2 . V_262 & 0xFFFF ) )
V_8 -> V_2 . V_262 |= V_261 & 0xFFFF ;
if ( ! ( V_8 -> V_2 . V_262 & 0xFFFF0000 ) )
V_8 -> V_2 . V_262 |= V_261 & 0xFFFF0000 ;
}
static unsigned int F_173 ( const struct V_1 * V_2 )
{
unsigned int V_263 = F_156 ( V_2 , V_264 ) ;
if ( V_263 == 0 ) {
V_263 = F_99 (unsigned int, dst->dev->mtu - 40 ,
ip_rt_min_advmss) ;
if ( V_263 > 65535 - 40 )
V_263 = 65535 - 40 ;
}
return V_263 ;
}
static unsigned int F_174 ( const struct V_1 * V_2 )
{
unsigned int V_235 = V_2 -> V_4 -> V_235 ;
if ( F_175 ( F_176 ( V_2 , V_207 ) ) ) {
const struct V_7 * V_8 = ( const struct V_7 * ) V_2 ;
if ( V_8 -> V_49 != V_8 -> V_12 && V_235 > 576 )
V_235 = 576 ;
}
if ( V_235 > V_265 )
V_235 = V_265 ;
return V_235 ;
}
static void F_177 ( struct V_7 * V_8 , const struct V_252 * V_253 ,
struct V_266 * V_20 )
{
struct V_9 * V_10 ;
int V_188 = 0 ;
if ( V_253 && ( V_253 -> V_267 & V_268 ) )
V_188 = 1 ;
V_8 -> V_10 = V_10 = F_108 ( V_8 -> V_12 , V_188 ) ;
if ( V_10 ) {
V_8 -> F_107 = F_107 () ;
if ( F_5 ( V_10 ) )
memcpy ( V_10 -> V_16 , V_20 -> V_269 ,
sizeof( T_1 ) * V_17 ) ;
F_178 ( & V_8 -> V_2 , V_10 -> V_16 , false ) ;
F_153 ( & V_8 -> V_2 , V_10 ) ;
if ( V_10 -> V_202 . V_203 &&
V_10 -> V_202 . V_203 != V_8 -> V_49 ) {
V_8 -> V_49 = V_10 -> V_202 . V_203 ;
V_8 -> V_50 |= V_113 ;
}
} else {
if ( V_20 -> V_269 != ( T_1 * ) V_270 ) {
V_8 -> V_20 = V_20 ;
F_129 ( & V_20 -> V_271 ) ;
}
F_178 ( & V_8 -> V_2 , V_20 -> V_269 , true ) ;
}
}
static void F_179 ( struct V_7 * V_8 , const struct V_252 * V_253 ,
const struct V_250 * V_251 ,
struct V_266 * V_20 , T_9 type , T_1 V_272 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
if ( V_20 ) {
if ( F_180 ( * V_251 ) &&
F_181 ( * V_251 ) . V_273 == V_274 )
V_8 -> V_49 = F_180 ( * V_251 ) ;
F_177 ( V_8 , V_253 , V_20 ) ;
#ifdef F_55
V_2 -> V_262 = F_181 ( * V_251 ) . V_275 ;
#endif
}
if ( F_155 ( V_2 ) > V_265 )
F_137 ( V_2 , V_207 , V_265 ) ;
if ( F_156 ( V_2 , V_264 ) > 65535 - 40 )
F_137 ( V_2 , V_264 , 65535 - 40 ) ;
#ifdef F_55
#ifdef F_182
F_172 ( V_8 , F_183 ( V_251 ) ) ;
#endif
F_172 ( V_8 , V_272 ) ;
#endif
}
static struct V_7 * F_184 ( struct V_3 * V_4 ,
bool V_276 , bool V_277 )
{
return F_185 ( & V_69 , V_4 , 1 , - 1 ,
V_278 |
( V_276 ? V_279 : 0 ) |
( V_277 ? V_280 : 0 ) ) ;
}
static int F_186 ( struct V_167 * V_168 , T_3 V_26 , T_3 V_27 ,
T_8 V_255 , struct V_3 * V_4 , int V_281 )
{
unsigned int V_166 ;
struct V_7 * V_110 ;
T_3 V_282 ;
struct V_199 * V_200 = F_119 ( V_4 ) ;
T_1 V_272 = 0 ;
int V_180 ;
if ( V_200 == NULL )
return - V_219 ;
if ( F_121 ( V_27 ) || F_122 ( V_27 ) ||
F_187 ( V_27 ) || V_168 -> V_283 != F_113 ( V_284 ) )
goto V_285;
if ( F_123 ( V_27 ) ) {
if ( ! F_188 ( V_26 ) )
goto V_285;
V_282 = F_171 ( V_4 , 0 , V_274 ) ;
} else {
V_180 = F_189 ( V_168 , V_27 , 0 , V_255 , 0 , V_4 , & V_282 ,
& V_272 ) ;
if ( V_180 < 0 )
goto V_286;
}
V_110 = F_184 ( V_287 . V_288 ,
F_190 ( V_200 , V_289 ) , false ) ;
if ( ! V_110 )
goto V_290;
#ifdef F_55
V_110 -> V_2 . V_262 = V_272 ;
#endif
V_110 -> V_2 . V_291 = F_166 ;
V_110 -> V_129 = V_26 ;
V_110 -> V_130 = V_27 ;
V_110 -> F_14 = F_14 ( F_20 ( V_4 ) ) ;
V_110 -> V_50 = V_112 ;
V_110 -> V_178 = V_292 ;
V_110 -> V_57 = V_255 ;
V_110 -> V_12 = V_26 ;
V_110 -> V_53 = V_27 ;
V_110 -> V_293 = V_4 -> V_169 ;
V_110 -> V_131 = V_4 -> V_169 ;
V_110 -> V_133 = 0 ;
V_110 -> V_132 = V_168 -> V_259 ;
V_110 -> V_49 = V_26 ;
V_110 -> V_62 = V_282 ;
V_110 -> F_107 = 0 ;
V_110 -> V_10 = NULL ;
V_110 -> V_20 = NULL ;
if ( V_281 ) {
V_110 -> V_2 . V_294 = V_295 ;
V_110 -> V_50 |= V_124 ;
}
#ifdef F_191
if ( ! F_188 ( V_26 ) && F_192 ( V_200 ) )
V_110 -> V_2 . V_294 = V_296 ;
#endif
F_97 ( V_72 ) ;
V_166 = F_12 ( V_26 , V_27 , V_4 -> V_169 , F_14 ( F_20 ( V_4 ) ) ) ;
V_110 = F_102 ( V_166 , V_110 , V_168 , V_4 -> V_169 ) ;
return F_193 ( V_110 ) ? F_194 ( V_110 ) : 0 ;
V_290:
return - V_184 ;
V_285:
return - V_219 ;
V_286:
return V_180 ;
}
static void F_195 ( struct V_3 * V_4 ,
struct V_199 * V_200 ,
struct V_167 * V_168 ,
T_3 V_26 ,
T_3 V_27 )
{
F_97 ( V_76 ) ;
#ifdef F_130
if ( F_131 ( V_200 ) && F_93 () ) {
F_94 ( V_143 L_27 ,
& V_26 , & V_27 , V_4 -> V_48 ) ;
if ( V_4 -> V_297 && F_196 ( V_168 ) ) {
int V_21 ;
const unsigned char * V_11 = F_197 ( V_168 ) ;
F_94 ( V_143 L_28 ) ;
for ( V_21 = 0 ; V_21 < V_4 -> V_297 ; V_21 ++ , V_11 ++ ) {
F_94 ( L_29 , * V_11 ) ;
if ( V_21 < ( V_4 -> V_297 - 1 ) )
F_94 ( L_30 ) ;
}
F_94 ( L_31 ) ;
}
}
#endif
}
static int F_198 ( struct V_167 * V_168 ,
const struct V_250 * V_251 ,
struct V_199 * V_200 ,
T_3 V_26 , T_3 V_27 , T_1 V_255 ,
struct V_7 * * V_298 )
{
struct V_7 * V_110 ;
int V_180 ;
struct V_199 * V_299 ;
unsigned int V_176 = 0 ;
T_3 V_282 ;
T_1 V_272 ;
V_299 = F_119 ( F_199 ( * V_251 ) ) ;
if ( V_299 == NULL ) {
if ( F_93 () )
F_94 ( V_300 L_32 \
L_33 ) ;
return - V_219 ;
}
V_180 = F_189 ( V_168 , V_27 , V_26 , V_255 , F_200 ( * V_251 ) ,
V_200 -> V_4 , & V_282 , & V_272 ) ;
if ( V_180 < 0 ) {
F_195 ( V_200 -> V_4 , V_200 , V_168 , V_26 ,
V_27 ) ;
goto V_301;
}
if ( V_180 )
V_176 |= V_302 ;
if ( V_299 == V_200 && V_180 &&
( F_124 ( V_299 ) ||
F_125 ( V_299 , V_27 , F_180 ( * V_251 ) ) ) )
V_176 |= V_303 ;
if ( V_168 -> V_283 != F_113 ( V_284 ) ) {
if ( V_299 == V_200 &&
F_201 ( V_200 ) == 0 ) {
V_180 = - V_219 ;
goto V_301;
}
}
V_110 = F_184 ( V_299 -> V_4 ,
F_190 ( V_200 , V_289 ) ,
F_190 ( V_299 , V_304 ) ) ;
if ( ! V_110 ) {
V_180 = - V_184 ;
goto V_301;
}
V_110 -> V_129 = V_26 ;
V_110 -> V_130 = V_27 ;
V_110 -> F_14 = F_14 ( F_20 ( V_110 -> V_2 . V_4 ) ) ;
V_110 -> V_50 = V_176 ;
V_110 -> V_178 = V_251 -> type ;
V_110 -> V_57 = V_255 ;
V_110 -> V_12 = V_26 ;
V_110 -> V_53 = V_27 ;
V_110 -> V_293 = V_200 -> V_4 -> V_169 ;
V_110 -> V_131 = V_200 -> V_4 -> V_169 ;
V_110 -> V_133 = 0 ;
V_110 -> V_132 = V_168 -> V_259 ;
V_110 -> V_49 = V_26 ;
V_110 -> V_62 = V_282 ;
V_110 -> F_107 = 0 ;
V_110 -> V_10 = NULL ;
V_110 -> V_20 = NULL ;
V_110 -> V_2 . V_294 = V_305 ;
V_110 -> V_2 . V_291 = V_306 ;
F_179 ( V_110 , NULL , V_251 , V_251 -> V_20 , V_251 -> type , V_272 ) ;
* V_298 = V_110 ;
V_180 = 0 ;
V_301:
return V_180 ;
}
static int F_202 ( struct V_167 * V_168 ,
struct V_250 * V_251 ,
const struct V_252 * V_253 ,
struct V_199 * V_200 ,
T_3 V_26 , T_3 V_27 , T_1 V_255 )
{
struct V_7 * V_110 = NULL ;
int V_180 ;
unsigned V_166 ;
#ifdef F_203
if ( V_251 -> V_20 && V_251 -> V_20 -> V_307 > 1 )
F_204 ( V_251 ) ;
#endif
V_180 = F_198 ( V_168 , V_251 , V_200 , V_26 , V_27 , V_255 , & V_110 ) ;
if ( V_180 )
return V_180 ;
V_166 = F_12 ( V_26 , V_27 , V_253 -> V_257 ,
F_14 ( F_20 ( V_110 -> V_2 . V_4 ) ) ) ;
V_110 = F_102 ( V_166 , V_110 , V_168 , V_253 -> V_257 ) ;
if ( F_193 ( V_110 ) )
return F_194 ( V_110 ) ;
return 0 ;
}
static int F_205 ( struct V_167 * V_168 , T_3 V_26 , T_3 V_27 ,
T_8 V_255 , struct V_3 * V_4 )
{
struct V_250 V_251 ;
struct V_199 * V_200 = F_119 ( V_4 ) ;
struct V_252 V_253 ;
unsigned V_176 = 0 ;
T_1 V_272 = 0 ;
struct V_7 * V_110 ;
unsigned V_166 ;
T_3 V_282 ;
int V_180 = - V_219 ;
struct V_32 * V_32 = F_20 ( V_4 ) ;
if ( ! V_200 )
goto V_120;
if ( F_121 ( V_27 ) || F_122 ( V_27 ) ||
F_187 ( V_27 ) )
goto V_308;
if ( F_122 ( V_26 ) || ( V_27 == 0 && V_26 == 0 ) )
goto V_309;
if ( F_123 ( V_27 ) )
goto V_308;
if ( F_123 ( V_26 ) || F_187 ( V_26 ) )
goto V_310;
V_253 . V_256 = 0 ;
V_253 . V_257 = V_4 -> V_169 ;
V_253 . V_258 = V_168 -> V_259 ;
V_253 . V_254 = V_255 ;
V_253 . V_311 = V_260 ;
V_253 . V_26 = V_26 ;
V_253 . V_27 = V_27 ;
V_180 = F_169 ( V_32 , & V_253 , & V_251 ) ;
if ( V_180 != 0 ) {
if ( ! F_206 ( V_200 ) )
goto V_312;
goto V_313;
}
F_97 ( V_71 ) ;
if ( V_251 . type == V_314 )
goto V_309;
if ( V_251 . type == V_315 ) {
V_180 = F_189 ( V_168 , V_27 , V_26 , V_255 ,
V_32 -> V_288 -> V_169 ,
V_4 , & V_282 , & V_272 ) ;
if ( V_180 < 0 )
goto V_316;
if ( V_180 )
V_176 |= V_302 ;
V_282 = V_26 ;
goto V_317;
}
if ( ! F_206 ( V_200 ) )
goto V_312;
if ( V_251 . type != V_179 )
goto V_310;
V_180 = F_202 ( V_168 , & V_251 , & V_253 , V_200 , V_26 , V_27 , V_255 ) ;
V_120: return V_180 ;
V_309:
if ( V_168 -> V_283 != F_113 ( V_284 ) )
goto V_285;
if ( F_123 ( V_27 ) )
V_282 = F_171 ( V_4 , 0 , V_274 ) ;
else {
V_180 = F_189 ( V_168 , V_27 , 0 , V_255 , 0 , V_4 , & V_282 ,
& V_272 ) ;
if ( V_180 < 0 )
goto V_316;
if ( V_180 )
V_176 |= V_302 ;
}
V_176 |= V_111 ;
V_251 . type = V_314 ;
F_97 ( V_74 ) ;
V_317:
V_110 = F_184 ( V_32 -> V_288 ,
F_190 ( V_200 , V_289 ) , false ) ;
if ( ! V_110 )
goto V_290;
V_110 -> V_2 . V_294 = V_295 ;
V_110 -> V_2 . V_291 = F_166 ;
#ifdef F_55
V_110 -> V_2 . V_262 = V_272 ;
#endif
V_110 -> V_129 = V_26 ;
V_110 -> V_130 = V_27 ;
V_110 -> F_14 = F_14 ( V_32 ) ;
V_110 -> V_50 = V_176 | V_124 ;
V_110 -> V_178 = V_251 . type ;
V_110 -> V_57 = V_255 ;
V_110 -> V_12 = V_26 ;
V_110 -> V_53 = V_27 ;
#ifdef F_55
V_110 -> V_2 . V_262 = V_272 ;
#endif
V_110 -> V_293 = V_4 -> V_169 ;
V_110 -> V_131 = V_4 -> V_169 ;
V_110 -> V_133 = 0 ;
V_110 -> V_132 = V_168 -> V_259 ;
V_110 -> V_49 = V_26 ;
V_110 -> V_62 = V_282 ;
V_110 -> F_107 = 0 ;
V_110 -> V_10 = NULL ;
V_110 -> V_20 = NULL ;
if ( V_251 . type == V_318 ) {
V_110 -> V_2 . V_294 = F_146 ;
V_110 -> V_2 . error = - V_180 ;
V_110 -> V_50 &= ~ V_124 ;
}
V_166 = F_12 ( V_26 , V_27 , V_253 . V_257 , F_14 ( V_32 ) ) ;
V_110 = F_102 ( V_166 , V_110 , V_168 , V_253 . V_257 ) ;
V_180 = 0 ;
if ( F_193 ( V_110 ) )
V_180 = F_194 ( V_110 ) ;
goto V_120;
V_313:
F_97 ( V_73 ) ;
V_282 = F_171 ( V_4 , 0 , V_260 ) ;
V_251 . type = V_318 ;
if ( V_180 == - V_319 )
V_180 = - V_222 ;
goto V_317;
V_310:
F_97 ( V_75 ) ;
#ifdef F_130
if ( F_131 ( V_200 ) && F_93 () )
F_94 ( V_143 L_34 ,
& V_26 , & V_27 , V_4 -> V_48 ) ;
#endif
V_312:
V_180 = - V_220 ;
goto V_120;
V_285:
V_180 = - V_219 ;
goto V_120;
V_290:
V_180 = - V_184 ;
goto V_120;
V_308:
V_180 = - V_219 ;
V_316:
F_195 ( V_4 , V_200 , V_168 , V_26 , V_27 ) ;
goto V_120;
}
int F_207 ( struct V_167 * V_168 , T_3 V_26 , T_3 V_27 ,
T_8 V_255 , struct V_3 * V_4 , bool V_320 )
{
struct V_7 * V_110 ;
unsigned V_166 ;
int V_321 = V_4 -> V_169 ;
struct V_32 * V_32 ;
int V_251 ;
V_32 = F_20 ( V_4 ) ;
F_140 () ;
if ( ! F_70 ( V_32 ) )
goto V_322;
V_255 &= V_323 ;
V_166 = F_12 ( V_26 , V_27 , V_321 , F_14 ( V_32 ) ) ;
for ( V_110 = F_208 ( V_41 [ V_166 ] . V_42 ) ; V_110 ;
V_110 = F_208 ( V_110 -> V_2 . V_43 ) ) {
if ( ( ( ( V_30 T_1 ) V_110 -> V_129 ^ ( V_30 T_1 ) V_26 ) |
( ( V_30 T_1 ) V_110 -> V_130 ^ ( V_30 T_1 ) V_27 ) |
( V_110 -> V_131 ^ V_321 ) |
V_110 -> V_133 |
( V_110 -> V_57 ^ V_255 ) ) == 0 &&
V_110 -> V_132 == V_168 -> V_259 &&
F_74 ( F_20 ( V_110 -> V_2 . V_4 ) , V_32 ) &&
! F_75 ( V_110 ) ) {
if ( V_320 ) {
F_209 ( & V_110 -> V_2 , V_121 ) ;
F_210 ( V_168 , & V_110 -> V_2 ) ;
} else {
F_105 ( & V_110 -> V_2 , V_121 ) ;
F_106 ( V_168 , & V_110 -> V_2 ) ;
}
F_97 ( V_70 ) ;
F_142 () ;
return 0 ;
}
F_97 ( V_84 ) ;
}
V_322:
if ( F_121 ( V_26 ) ) {
struct V_199 * V_200 = F_119 ( V_4 ) ;
if ( V_200 ) {
int V_281 = F_211 ( V_200 , V_26 , V_27 ,
F_145 ( V_168 ) -> V_283 ) ;
if ( V_281
#ifdef F_191
||
( ! F_188 ( V_26 ) &&
F_192 ( V_200 ) )
#endif
) {
int V_251 = F_186 ( V_168 , V_26 , V_27 ,
V_255 , V_4 , V_281 ) ;
F_142 () ;
return V_251 ;
}
}
F_142 () ;
return - V_219 ;
}
V_251 = F_205 ( V_168 , V_26 , V_27 , V_255 , V_4 ) ;
F_142 () ;
return V_251 ;
}
static struct V_7 * F_212 ( const struct V_250 * V_251 ,
const struct V_252 * V_253 ,
T_3 V_324 , T_3 V_325 ,
int V_326 , struct V_3 * V_327 ,
unsigned int V_176 )
{
struct V_266 * V_20 = V_251 -> V_20 ;
T_1 V_255 = F_213 ( V_253 ) ;
struct V_199 * V_200 ;
T_9 type = V_251 -> type ;
struct V_7 * V_110 ;
if ( F_187 ( V_253 -> V_27 ) && ! ( V_327 -> V_176 & V_328 ) )
return F_104 ( - V_219 ) ;
if ( F_122 ( V_253 -> V_26 ) )
type = V_314 ;
else if ( F_121 ( V_253 -> V_26 ) )
type = V_292 ;
else if ( F_123 ( V_253 -> V_26 ) )
return F_104 ( - V_219 ) ;
if ( V_327 -> V_176 & V_328 )
V_176 |= V_124 ;
V_200 = F_119 ( V_327 ) ;
if ( ! V_200 )
return F_104 ( - V_219 ) ;
if ( type == V_314 ) {
V_176 |= V_111 | V_124 ;
V_20 = NULL ;
} else if ( type == V_292 ) {
V_176 |= V_112 | V_124 ;
if ( ! F_211 ( V_200 , V_253 -> V_26 , V_253 -> V_27 ,
V_253 -> V_329 ) )
V_176 &= ~ V_124 ;
if ( V_20 && V_251 -> V_330 < 4 )
V_20 = NULL ;
}
V_110 = F_184 ( V_327 ,
F_190 ( V_200 , V_289 ) ,
F_190 ( V_200 , V_304 ) ) ;
if ( ! V_110 )
return F_104 ( - V_184 ) ;
V_110 -> V_2 . V_291 = V_306 ;
V_110 -> V_129 = V_324 ;
V_110 -> V_130 = V_325 ;
V_110 -> F_14 = F_14 ( F_20 ( V_327 ) ) ;
V_110 -> V_50 = V_176 ;
V_110 -> V_178 = type ;
V_110 -> V_57 = V_255 ;
V_110 -> V_12 = V_253 -> V_26 ;
V_110 -> V_53 = V_253 -> V_27 ;
V_110 -> V_293 = 0 ;
V_110 -> V_131 = V_326 ? : V_327 -> V_169 ;
V_110 -> V_133 = V_326 ;
V_110 -> V_132 = V_253 -> V_258 ;
V_110 -> V_49 = V_253 -> V_26 ;
V_110 -> V_62 = V_253 -> V_27 ;
V_110 -> F_107 = 0 ;
V_110 -> V_10 = NULL ;
V_110 -> V_20 = NULL ;
F_97 ( V_78 ) ;
if ( V_176 & V_124 ) {
V_110 -> V_2 . V_294 = V_295 ;
V_110 -> V_62 = V_253 -> V_26 ;
}
if ( V_176 & ( V_111 | V_112 ) ) {
V_110 -> V_62 = V_253 -> V_27 ;
if ( V_176 & V_124 &&
! ( V_327 -> V_176 & V_328 ) ) {
V_110 -> V_2 . V_291 = V_331 ;
F_97 ( V_79 ) ;
}
#ifdef F_191
if ( type == V_292 ) {
if ( F_192 ( V_200 ) &&
! F_188 ( V_253 -> V_26 ) ) {
V_110 -> V_2 . V_294 = V_296 ;
V_110 -> V_2 . V_291 = V_331 ;
}
}
#endif
}
F_179 ( V_110 , V_253 , V_251 , V_20 , type , 0 ) ;
return V_110 ;
}
static struct V_7 * F_214 ( struct V_32 * V_32 , struct V_252 * V_253 )
{
struct V_3 * V_327 = NULL ;
T_1 V_255 = F_213 ( V_253 ) ;
unsigned int V_176 = 0 ;
struct V_250 V_251 ;
struct V_7 * V_110 ;
T_3 V_324 ;
T_3 V_325 ;
int V_326 ;
V_251 . V_20 = NULL ;
#ifdef F_182
V_251 . V_39 = NULL ;
#endif
V_324 = V_253 -> V_26 ;
V_325 = V_253 -> V_27 ;
V_326 = V_253 -> V_256 ;
V_253 -> V_257 = V_32 -> V_288 -> V_169 ;
V_253 -> V_254 = V_255 & V_323 ;
V_253 -> V_311 = ( ( V_255 & V_332 ) ?
V_274 : V_260 ) ;
F_140 () ;
if ( V_253 -> V_27 ) {
V_110 = F_104 ( - V_219 ) ;
if ( F_121 ( V_253 -> V_27 ) ||
F_122 ( V_253 -> V_27 ) ||
F_123 ( V_253 -> V_27 ) )
goto V_120;
if ( V_253 -> V_256 == 0 &&
( F_121 ( V_253 -> V_26 ) ||
F_122 ( V_253 -> V_26 ) ) ) {
V_327 = F_215 ( V_32 , V_253 -> V_27 , false ) ;
if ( V_327 == NULL )
goto V_120;
V_253 -> V_256 = V_327 -> V_169 ;
goto V_333;
}
if ( ! ( V_253 -> V_267 & V_334 ) ) {
if ( ! F_215 ( V_32 , V_253 -> V_27 , false ) )
goto V_120;
}
}
if ( V_253 -> V_256 ) {
V_327 = F_216 ( V_32 , V_253 -> V_256 ) ;
V_110 = F_104 ( - V_335 ) ;
if ( V_327 == NULL )
goto V_120;
if ( ! ( V_327 -> V_176 & V_336 ) || ! F_119 ( V_327 ) ) {
V_110 = F_104 ( - V_222 ) ;
goto V_120;
}
if ( F_188 ( V_253 -> V_26 ) ||
F_122 ( V_253 -> V_26 ) ) {
if ( ! V_253 -> V_27 )
V_253 -> V_27 = F_171 ( V_327 , 0 ,
V_274 ) ;
goto V_333;
}
if ( V_253 -> V_27 ) {
if ( F_121 ( V_253 -> V_26 ) )
V_253 -> V_27 = F_171 ( V_327 , 0 ,
V_253 -> V_311 ) ;
else if ( ! V_253 -> V_26 )
V_253 -> V_27 = F_171 ( V_327 , 0 ,
V_337 ) ;
}
}
if ( ! V_253 -> V_26 ) {
V_253 -> V_26 = V_253 -> V_27 ;
if ( ! V_253 -> V_26 )
V_253 -> V_26 = V_253 -> V_27 = F_217 ( V_338 ) ;
V_327 = V_32 -> V_288 ;
V_253 -> V_256 = V_32 -> V_288 -> V_169 ;
V_251 . type = V_315 ;
V_176 |= V_124 ;
goto V_333;
}
if ( F_169 ( V_32 , V_253 , & V_251 ) ) {
V_251 . V_20 = NULL ;
if ( V_253 -> V_256 ) {
if ( V_253 -> V_27 == 0 )
V_253 -> V_27 = F_171 ( V_327 , 0 ,
V_274 ) ;
V_251 . type = V_179 ;
goto V_333;
}
V_110 = F_104 ( - V_222 ) ;
goto V_120;
}
if ( V_251 . type == V_315 ) {
if ( ! V_253 -> V_27 ) {
if ( V_251 . V_20 -> V_339 )
V_253 -> V_27 = V_251 . V_20 -> V_339 ;
else
V_253 -> V_27 = V_253 -> V_26 ;
}
V_327 = V_32 -> V_288 ;
V_253 -> V_256 = V_327 -> V_169 ;
V_251 . V_20 = NULL ;
V_176 |= V_124 ;
goto V_333;
}
#ifdef F_203
if ( V_251 . V_20 -> V_307 > 1 && V_253 -> V_256 == 0 )
F_204 ( & V_251 ) ;
else
#endif
if ( ! V_251 . V_330 &&
V_251 . V_340 -> V_341 > 1 &&
V_251 . type == V_179 && ! V_253 -> V_256 )
F_218 ( & V_251 ) ;
if ( ! V_253 -> V_27 )
V_253 -> V_27 = F_170 ( V_32 , V_251 ) ;
V_327 = F_199 ( V_251 ) ;
V_253 -> V_256 = V_327 -> V_169 ;
V_333:
V_110 = F_212 ( & V_251 , V_253 , V_324 , V_325 , V_326 ,
V_327 , V_176 ) ;
if ( ! F_193 ( V_110 ) ) {
unsigned int V_166 ;
V_166 = F_12 ( V_324 , V_325 , V_326 ,
F_14 ( F_20 ( V_327 ) ) ) ;
V_110 = F_102 ( V_166 , V_110 , NULL , V_326 ) ;
}
V_120:
F_142 () ;
return V_110 ;
}
struct V_7 * F_219 ( struct V_32 * V_32 , struct V_252 * V_342 )
{
struct V_7 * V_110 ;
unsigned int V_166 ;
if ( ! F_70 ( V_32 ) )
goto V_343;
V_166 = F_12 ( V_342 -> V_26 , V_342 -> V_27 , V_342 -> V_256 , F_14 ( V_32 ) ) ;
F_18 () ;
for ( V_110 = F_19 ( V_41 [ V_166 ] . V_42 ) ; V_110 ;
V_110 = F_19 ( V_110 -> V_2 . V_43 ) ) {
if ( V_110 -> V_129 == V_342 -> V_26 &&
V_110 -> V_130 == V_342 -> V_27 &&
F_69 ( V_110 ) &&
V_110 -> V_133 == V_342 -> V_256 &&
V_110 -> V_132 == V_342 -> V_258 &&
! ( ( V_110 -> V_57 ^ V_342 -> V_254 ) &
( V_323 | V_332 ) ) &&
F_74 ( F_20 ( V_110 -> V_2 . V_4 ) , V_32 ) &&
! F_75 ( V_110 ) ) {
F_105 ( & V_110 -> V_2 , V_121 ) ;
F_97 ( V_77 ) ;
F_22 () ;
if ( ! V_342 -> V_27 )
V_342 -> V_27 = V_110 -> V_53 ;
if ( ! V_342 -> V_26 )
V_342 -> V_26 = V_110 -> V_12 ;
return V_110 ;
}
F_97 ( V_85 ) ;
}
F_22 () ;
V_343:
return F_214 ( V_32 , V_342 ) ;
}
static struct V_1 * F_220 ( struct V_1 * V_2 , T_1 V_248 )
{
return NULL ;
}
static unsigned int F_221 ( const struct V_1 * V_2 )
{
return 0 ;
}
static void F_222 ( struct V_1 * V_2 , T_1 V_235 )
{
}
static T_1 * F_223 ( struct V_1 * V_2 ,
unsigned long V_6 )
{
return NULL ;
}
struct V_1 * F_224 ( struct V_32 * V_32 , struct V_1 * V_344 )
{
struct V_7 * V_8 = F_185 ( & V_345 , NULL , 1 , 0 , 0 ) ;
struct V_7 * V_346 = (struct V_7 * ) V_344 ;
if ( V_8 ) {
struct V_1 * V_15 = & V_8 -> V_2 ;
V_15 -> V_52 = 1 ;
V_15 -> V_294 = V_347 ;
V_15 -> V_291 = V_347 ;
F_225 ( V_15 , & V_346 -> V_2 ) ;
V_15 -> V_4 = V_346 -> V_2 . V_4 ;
if ( V_15 -> V_4 )
F_226 ( V_15 -> V_4 ) ;
V_8 -> V_129 = V_346 -> V_129 ;
V_8 -> V_130 = V_346 -> V_130 ;
V_8 -> V_57 = V_346 -> V_57 ;
V_8 -> V_293 = V_346 -> V_293 ;
V_8 -> V_131 = V_346 -> V_131 ;
V_8 -> V_133 = V_346 -> V_133 ;
V_8 -> V_132 = V_346 -> V_132 ;
V_8 -> F_14 = F_14 ( V_32 ) ;
V_8 -> V_50 = V_346 -> V_50 ;
V_8 -> V_178 = V_346 -> V_178 ;
V_8 -> V_12 = V_346 -> V_12 ;
V_8 -> V_53 = V_346 -> V_53 ;
V_8 -> V_49 = V_346 -> V_49 ;
V_8 -> V_62 = V_346 -> V_62 ;
V_8 -> V_10 = V_346 -> V_10 ;
if ( V_8 -> V_10 )
F_129 ( & V_8 -> V_10 -> V_348 ) ;
V_8 -> V_20 = V_346 -> V_20 ;
if ( V_8 -> V_20 )
F_129 ( & V_8 -> V_20 -> V_271 ) ;
F_227 ( V_15 ) ;
}
F_228 ( V_344 ) ;
return V_8 ? & V_8 -> V_2 : F_104 ( - V_91 ) ;
}
struct V_7 * F_229 ( struct V_32 * V_32 , struct V_252 * V_342 ,
struct V_349 * V_350 )
{
struct V_7 * V_8 = F_219 ( V_32 , V_342 ) ;
if ( F_193 ( V_8 ) )
return V_8 ;
if ( V_342 -> V_329 )
V_8 = (struct V_7 * ) F_230 ( V_32 , & V_8 -> V_2 ,
F_231 ( V_342 ) ,
V_350 , 0 ) ;
return V_8 ;
}
static int F_232 ( struct V_32 * V_32 ,
struct V_167 * V_168 , T_1 V_351 , T_1 V_35 , int V_352 ,
int V_353 , unsigned int V_176 )
{
struct V_7 * V_8 = F_139 ( V_168 ) ;
struct V_354 * V_39 ;
struct V_355 * V_356 ;
long V_240 = 0 ;
const struct V_9 * V_10 = V_8 -> V_10 ;
T_1 V_194 = 0 , V_357 = 0 , V_358 = 0 , error ;
V_356 = F_233 ( V_168 , V_351 , V_35 , V_352 , sizeof( * V_39 ) , V_176 ) ;
if ( V_356 == NULL )
return - V_359 ;
V_39 = F_234 ( V_356 ) ;
V_39 -> V_360 = V_361 ;
V_39 -> V_362 = 32 ;
V_39 -> V_363 = 0 ;
V_39 -> V_364 = V_8 -> V_57 ;
V_39 -> V_365 = V_366 ;
F_235 ( V_168 , V_367 , V_366 ) ;
V_39 -> V_368 = V_8 -> V_178 ;
V_39 -> V_369 = V_260 ;
V_39 -> V_370 = V_371 ;
V_39 -> V_372 = ( V_8 -> V_50 & ~ 0xFFFF ) | V_373 ;
if ( V_8 -> V_50 & V_114 )
V_39 -> V_372 |= V_374 ;
F_236 ( V_168 , V_375 , V_8 -> V_12 ) ;
if ( V_8 -> V_130 ) {
V_39 -> V_363 = 32 ;
F_236 ( V_168 , V_376 , V_8 -> V_130 ) ;
}
if ( V_8 -> V_2 . V_4 )
F_235 ( V_168 , V_377 , V_8 -> V_2 . V_4 -> V_169 ) ;
#ifdef F_55
if ( V_8 -> V_2 . V_262 )
F_235 ( V_168 , V_378 , V_8 -> V_2 . V_262 ) ;
#endif
if ( F_65 ( V_8 ) )
F_236 ( V_168 , V_379 , V_8 -> V_62 ) ;
else if ( V_8 -> V_53 != V_8 -> V_130 )
F_236 ( V_168 , V_379 , V_8 -> V_53 ) ;
if ( V_8 -> V_12 != V_8 -> V_49 )
F_236 ( V_168 , V_380 , V_8 -> V_49 ) ;
if ( F_237 ( V_168 , F_238 ( & V_8 -> V_2 ) ) < 0 )
goto V_381;
if ( V_8 -> V_132 )
F_236 ( V_168 , V_382 , V_8 -> V_132 ) ;
error = V_8 -> V_2 . error ;
if ( V_10 ) {
F_239 ( V_8 -> V_10 ) ;
V_194 = F_15 ( & V_10 -> V_383 ) & 0xffff ;
if ( V_10 -> V_384 ) {
V_357 = V_10 -> V_385 ;
V_358 = F_240 () - V_10 -> V_384 ;
}
V_240 = F_133 ( V_10 -> V_115 ) ;
if ( V_240 )
V_240 -= V_121 ;
}
if ( F_65 ( V_8 ) ) {
#ifdef F_191
T_3 V_2 = V_8 -> V_12 ;
if ( F_121 ( V_2 ) && ! F_188 ( V_2 ) &&
F_241 ( V_32 , V_386 ) ) {
int V_180 = F_242 ( V_32 , V_168 ,
V_8 -> V_53 , V_8 -> V_12 ,
V_39 , V_353 ) ;
if ( V_180 <= 0 ) {
if ( ! V_353 ) {
if ( V_180 == 0 )
return 0 ;
goto V_381;
} else {
if ( V_180 == - V_359 )
goto V_381;
error = V_180 ;
}
}
} else
#endif
F_235 ( V_168 , V_387 , V_8 -> V_131 ) ;
}
if ( F_243 ( V_168 , & V_8 -> V_2 , V_194 , V_357 , V_358 ,
V_240 , error ) < 0 )
goto V_381;
return F_244 ( V_168 , V_356 ) ;
V_381:
F_245 ( V_168 , V_356 ) ;
return - V_359 ;
}
static int F_246 ( struct V_167 * V_388 , struct V_355 * V_356 , void * V_389 )
{
struct V_32 * V_32 = F_247 ( V_388 -> V_350 ) ;
struct V_354 * V_390 ;
struct V_391 * V_392 [ V_393 + 1 ] ;
struct V_7 * V_8 = NULL ;
T_3 V_2 = 0 ;
T_3 V_89 = 0 ;
T_1 V_321 ;
int V_180 ;
int V_259 ;
struct V_167 * V_168 ;
V_180 = F_248 ( V_356 , sizeof( * V_390 ) , V_392 , V_393 , V_394 ) ;
if ( V_180 < 0 )
goto V_395;
V_390 = F_234 ( V_356 ) ;
V_168 = F_249 ( V_396 , V_25 ) ;
if ( V_168 == NULL ) {
V_180 = - V_184 ;
goto V_395;
}
F_250 ( V_168 ) ;
F_251 ( V_168 ) ;
F_145 ( V_168 ) -> V_283 = V_397 ;
F_252 ( V_168 , V_398 + sizeof( struct V_189 ) ) ;
V_89 = V_392 [ V_376 ] ? F_253 ( V_392 [ V_376 ] ) : 0 ;
V_2 = V_392 [ V_375 ] ? F_253 ( V_392 [ V_375 ] ) : 0 ;
V_321 = V_392 [ V_387 ] ? F_254 ( V_392 [ V_387 ] ) : 0 ;
V_259 = V_392 [ V_382 ] ? F_254 ( V_392 [ V_382 ] ) : 0 ;
if ( V_321 ) {
struct V_3 * V_4 ;
V_4 = F_255 ( V_32 , V_321 ) ;
if ( V_4 == NULL ) {
V_180 = - V_335 ;
goto V_399;
}
V_168 -> V_283 = F_113 ( V_284 ) ;
V_168 -> V_4 = V_4 ;
V_168 -> V_259 = V_259 ;
F_256 () ;
V_180 = F_257 ( V_168 , V_2 , V_89 , V_390 -> V_364 , V_4 ) ;
F_258 () ;
V_8 = F_139 ( V_168 ) ;
if ( V_180 == 0 && V_8 -> V_2 . error )
V_180 = - V_8 -> V_2 . error ;
} else {
struct V_252 V_253 = {
. V_26 = V_2 ,
. V_27 = V_89 ,
. V_254 = V_390 -> V_364 ,
. V_256 = V_392 [ V_377 ] ? F_254 ( V_392 [ V_377 ] ) : 0 ,
. V_258 = V_259 ,
} ;
V_8 = F_259 ( V_32 , & V_253 ) ;
V_180 = 0 ;
if ( F_193 ( V_8 ) )
V_180 = F_194 ( V_8 ) ;
}
if ( V_180 )
goto V_399;
F_106 ( V_168 , & V_8 -> V_2 ) ;
if ( V_390 -> V_372 & V_374 )
V_8 -> V_50 |= V_114 ;
V_180 = F_232 ( V_32 , V_168 , F_260 ( V_388 ) . V_351 , V_356 -> V_400 ,
V_401 , 0 , 0 ) ;
if ( V_180 <= 0 )
goto V_399;
V_180 = F_261 ( V_168 , V_32 , F_260 ( V_388 ) . V_351 ) ;
V_395:
return V_180 ;
V_399:
F_148 ( V_168 ) ;
goto V_395;
}
int F_262 ( struct V_167 * V_168 , struct V_402 * V_403 )
{
struct V_7 * V_8 ;
int V_404 , V_405 ;
int V_28 , V_406 ;
struct V_32 * V_32 ;
V_32 = F_247 ( V_168 -> V_350 ) ;
V_405 = V_403 -> args [ 0 ] ;
if ( V_405 < 0 )
V_405 = 0 ;
V_406 = V_28 = V_403 -> args [ 1 ] ;
for ( V_404 = V_405 ; V_404 <= V_31 ; V_404 ++ , V_406 = 0 ) {
if ( ! V_41 [ V_404 ] . V_42 )
continue;
F_18 () ;
for ( V_8 = F_19 ( V_41 [ V_404 ] . V_42 ) , V_28 = 0 ; V_8 ;
V_8 = F_19 ( V_8 -> V_2 . V_43 ) , V_28 ++ ) {
if ( ! F_74 ( F_20 ( V_8 -> V_2 . V_4 ) , V_32 ) || V_28 < V_406 )
continue;
if ( F_75 ( V_8 ) )
continue;
F_210 ( V_168 , & V_8 -> V_2 ) ;
if ( F_232 ( V_32 , V_168 , F_260 ( V_403 -> V_168 ) . V_351 ,
V_403 -> V_356 -> V_400 , V_401 ,
1 , V_407 ) <= 0 ) {
F_263 ( V_168 ) ;
F_22 () ;
goto V_408;
}
F_263 ( V_168 ) ;
}
F_22 () ;
}
V_408:
V_403 -> args [ 0 ] = V_404 ;
V_403 -> args [ 1 ] = V_28 ;
return V_168 -> V_47 ;
}
void F_264 ( struct V_199 * V_200 )
{
F_89 ( F_20 ( V_200 -> V_4 ) , 0 ) ;
}
static int F_265 ( T_10 * V_409 , int V_410 ,
void T_11 * V_411 ,
T_12 * V_412 , T_4 * V_413 )
{
if ( V_410 ) {
int V_414 ;
T_10 V_415 ;
struct V_32 * V_32 ;
memcpy ( & V_415 , V_409 , sizeof( V_415 ) ) ;
V_415 . V_416 = & V_414 ;
F_266 ( & V_415 , V_410 , V_411 , V_412 , V_413 ) ;
V_32 = (struct V_32 * ) V_409 -> V_417 ;
F_89 ( V_32 , V_414 ) ;
return 0 ;
}
return - V_219 ;
}
static T_5 int F_267 ( struct V_32 * V_32 )
{
struct T_10 * V_418 ;
V_418 = V_419 ;
if ( ! F_74 ( V_32 , & V_287 ) ) {
V_418 = F_268 ( V_418 , sizeof( V_419 ) , V_25 ) ;
if ( V_418 == NULL )
goto V_420;
}
V_418 [ 0 ] . V_417 = V_32 ;
V_32 -> V_33 . V_421 =
F_269 ( V_32 , V_422 , V_418 ) ;
if ( V_32 -> V_33 . V_421 == NULL )
goto V_423;
return 0 ;
V_423:
if ( V_418 != V_419 )
F_49 ( V_418 ) ;
V_420:
return - V_91 ;
}
static T_6 void F_270 ( struct V_32 * V_32 )
{
struct T_10 * V_418 ;
V_418 = V_32 -> V_33 . V_421 -> V_424 ;
F_271 ( V_32 -> V_33 . V_421 ) ;
F_272 ( V_418 == V_419 ) ;
F_49 ( V_418 ) ;
}
static T_5 int F_273 ( struct V_32 * V_32 )
{
F_87 ( & V_32 -> V_33 . F_14 ,
sizeof( V_32 -> V_33 . F_14 ) ) ;
F_87 ( & V_32 -> V_33 . V_425 ,
sizeof( V_32 -> V_33 . V_425 ) ) ;
return 0 ;
}
static int T_2 F_274 ( char * V_426 )
{
if ( ! V_426 )
return 0 ;
V_427 = F_275 ( V_426 , & V_426 , 0 ) ;
return 1 ;
}
int T_2 F_276 ( void )
{
int V_428 = 0 ;
#ifdef F_55
V_88 = F_277 ( 256 * sizeof( struct V_88 ) , F_278 ( struct V_88 ) ) ;
if ( ! V_88 )
F_10 ( L_35 ) ;
#endif
V_69 . V_429 =
F_279 ( L_36 , sizeof( struct V_7 ) , 0 ,
V_430 | V_431 , NULL ) ;
V_345 . V_429 = V_69 . V_429 ;
if ( F_280 ( & V_69 ) < 0 )
F_10 ( L_37 ) ;
if ( F_280 ( & V_345 ) < 0 )
F_10 ( L_38 ) ;
V_41 = (struct V_432 * )
F_281 ( L_39 ,
sizeof( struct V_432 ) ,
V_427 ,
( V_433 >= 128 * 1024 ) ?
15 : 17 ,
0 ,
& V_158 ,
& V_31 ,
V_427 ? 0 : 512 * 1024 ) ;
memset ( V_41 , 0 , ( V_31 + 1 ) * sizeof( struct V_432 ) ) ;
F_8 () ;
V_69 . V_159 = ( V_31 + 1 ) ;
V_156 = ( V_31 + 1 ) * 16 ;
F_282 () ;
F_283 () ;
if ( F_58 () )
F_94 ( V_434 L_40 ) ;
#ifdef F_284
F_285 () ;
F_286 ( V_156 ) ;
#endif
F_287 ( V_435 , V_436 , F_246 , NULL ) ;
#ifdef F_288
F_59 ( & V_437 ) ;
#endif
F_59 ( & V_438 ) ;
return V_428 ;
}
void T_2 F_289 ( void )
{
F_290 ( V_439 , V_440 ) ;
}
