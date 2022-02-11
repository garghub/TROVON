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
struct V_47 * V_48 ;
int V_49 , V_50 ;
F_31 () ;
V_48 = F_32 ( & V_39 -> V_2 ) ;
V_50 = ( V_48 && ( V_48 -> V_51 & V_52 ) ) ? 1 : 0 ;
F_33 () ;
F_30 ( V_35 , L_6
L_7 ,
V_39 -> V_2 . V_4 ? V_39 -> V_2 . V_4 -> V_53 : L_8 ,
( V_30 T_1 ) V_39 -> V_12 ,
( V_30 T_1 ) V_39 -> V_54 ,
V_39 -> V_55 , F_15 ( & V_39 -> V_2 . V_56 ) ,
V_39 -> V_2 . V_57 , 0 , ( V_30 T_1 ) V_39 -> V_58 ,
F_34 ( & V_39 -> V_2 ) + 40 ,
F_35 ( & V_39 -> V_2 , V_59 ) ,
( int ) ( ( F_35 ( & V_39 -> V_2 , V_60 ) >> 3 ) +
F_35 ( & V_39 -> V_2 , V_61 ) ) ,
V_39 -> V_62 ,
- 1 ,
V_50 ,
V_39 -> V_63 , & V_49 ) ;
F_30 ( V_35 , L_9 , 127 - V_49 , L_10 ) ;
}
return 0 ;
}
static int F_36 ( struct V_64 * V_64 , struct V_65 * V_65 )
{
return F_37 ( V_64 , V_65 , & V_66 ,
sizeof( struct V_36 ) ) ;
}
static void * F_38 ( struct V_34 * V_35 , T_4 * V_44 )
{
int V_67 ;
if ( * V_44 == 0 )
return V_45 ;
for ( V_67 = * V_44 - 1 ; V_67 < V_68 ; ++ V_67 ) {
if ( ! F_39 ( V_67 ) )
continue;
* V_44 = V_67 + 1 ;
return & F_40 ( V_69 , V_67 ) ;
}
return NULL ;
}
static void * F_41 ( struct V_34 * V_35 , void * V_46 , T_4 * V_44 )
{
int V_67 ;
for ( V_67 = * V_44 ; V_67 < V_68 ; ++ V_67 ) {
if ( ! F_39 ( V_67 ) )
continue;
* V_44 = V_67 + 1 ;
return & F_40 ( V_69 , V_67 ) ;
}
return NULL ;
}
static void F_42 ( struct V_34 * V_35 , void * V_46 )
{
}
static int F_43 ( struct V_34 * V_35 , void * V_46 )
{
struct V_69 * V_37 = V_46 ;
if ( V_46 == V_45 ) {
F_30 ( V_35 , L_11 ) ;
return 0 ;
}
F_30 ( V_35 , L_12
L_13 ,
F_44 ( & V_70 ) ,
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
V_37 -> V_85 ,
V_37 -> V_86
) ;
return 0 ;
}
static int F_45 ( struct V_64 * V_64 , struct V_65 * V_65 )
{
return F_46 ( V_65 , & V_87 ) ;
}
static int F_47 ( struct V_34 * V_88 , void * V_46 )
{
struct V_89 * V_2 , * V_90 ;
unsigned int V_21 , V_91 ;
V_2 = F_48 ( 256 , sizeof( struct V_89 ) , V_25 ) ;
if ( ! V_2 )
return - V_92 ;
F_49 (i) {
V_90 = (struct V_89 * ) F_50 ( V_89 , V_21 ) ;
for ( V_91 = 0 ; V_91 < 256 ; V_91 ++ ) {
V_2 [ V_91 ] . V_93 += V_90 [ V_91 ] . V_93 ;
V_2 [ V_91 ] . V_94 += V_90 [ V_91 ] . V_94 ;
V_2 [ V_91 ] . V_95 += V_90 [ V_91 ] . V_95 ;
V_2 [ V_91 ] . V_96 += V_90 [ V_91 ] . V_96 ;
}
}
F_51 ( V_88 , V_2 , 256 * sizeof( struct V_89 ) ) ;
F_52 ( V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_64 * V_64 , struct V_65 * V_65 )
{
return F_54 ( V_65 , F_47 , NULL ) ;
}
static int T_5 F_55 ( struct V_32 * V_32 )
{
struct V_97 * V_98 ;
V_98 = F_56 ( V_32 , L_14 , V_99 ,
& V_100 ) ;
if ( ! V_98 )
goto V_101;
V_98 = F_57 ( L_14 , V_99 ,
V_32 -> V_102 , & V_103 ) ;
if ( ! V_98 )
goto V_104;
#ifdef F_58
V_98 = F_57 ( L_15 , 0 , V_32 -> V_105 , & V_106 ) ;
if ( ! V_98 )
goto V_107;
#endif
return 0 ;
#ifdef F_58
V_107:
F_59 ( L_14 , V_32 -> V_102 ) ;
#endif
V_104:
F_59 ( L_14 , V_32 -> V_105 ) ;
V_101:
return - V_92 ;
}
static void T_6 F_60 ( struct V_32 * V_32 )
{
F_59 ( L_14 , V_32 -> V_102 ) ;
F_59 ( L_14 , V_32 -> V_105 ) ;
#ifdef F_58
F_59 ( L_15 , V_32 -> V_105 ) ;
#endif
}
static int T_2 F_61 ( void )
{
return F_62 ( & V_108 ) ;
}
static inline int F_61 ( void )
{
return 0 ;
}
static inline void F_63 ( struct V_7 * V_8 )
{
F_64 ( & V_8 -> V_2 . V_109 , V_110 ) ;
}
static inline void F_65 ( struct V_7 * V_8 )
{
F_66 ( V_8 ) ;
F_64 ( & V_8 -> V_2 . V_109 , V_110 ) ;
}
static inline int F_67 ( struct V_7 * V_111 )
{
return ( V_111 -> V_55 & ( V_112 | V_113 ) ) &&
F_68 ( V_111 ) && V_111 -> V_2 . V_43 ;
}
static inline int F_69 ( struct V_7 * V_111 )
{
return ( V_111 -> V_55 & ( V_114 | V_115 ) ) ||
( V_111 -> V_10 && V_111 -> V_10 -> V_116 ) ;
}
static int F_70 ( struct V_7 * V_111 , unsigned long V_117 , unsigned long V_118 )
{
unsigned long V_119 ;
int V_120 = 0 ;
if ( F_15 ( & V_111 -> V_2 . V_56 ) )
goto V_121;
V_119 = V_122 - V_111 -> V_2 . V_123 ;
if ( ( V_119 <= V_117 && ! F_67 ( V_111 ) ) ||
( V_119 <= V_118 && F_69 ( V_111 ) ) )
goto V_121;
V_120 = 1 ;
V_121: return V_120 ;
}
static inline T_1 F_71 ( struct V_7 * V_8 )
{
T_1 V_124 = V_122 - V_8 -> V_2 . V_123 ;
V_124 = ~ V_124 & ~ ( 3 << 30 ) ;
if ( F_69 ( V_8 ) )
V_124 |= ( 1 << 31 ) ;
if ( F_72 ( V_8 ) ||
! ( V_8 -> V_55 & ( V_112 | V_113 | V_125 ) ) )
V_124 |= ( 1 << 30 ) ;
return V_124 ;
}
static inline bool F_73 ( const struct V_32 * V_32 )
{
return V_32 -> V_33 . V_126 <=
V_32 -> V_33 . V_127 ;
}
static inline bool F_74 ( const struct V_7 * V_128 ,
const struct V_7 * V_129 )
{
return ( ( ( ( V_30 T_1 ) V_128 -> V_130 ^ ( V_30 T_1 ) V_129 -> V_130 ) |
( ( V_30 T_1 ) V_128 -> V_131 ^ ( V_30 T_1 ) V_129 -> V_131 ) |
( V_128 -> V_132 ^ V_129 -> V_132 ) ) == 0 ) ;
}
static inline int F_75 ( struct V_7 * V_128 , struct V_7 * V_129 )
{
return ( ( ( V_30 T_1 ) V_128 -> V_130 ^ ( V_30 T_1 ) V_129 -> V_130 ) |
( ( V_30 T_1 ) V_128 -> V_131 ^ ( V_30 T_1 ) V_129 -> V_131 ) |
( V_128 -> V_133 ^ V_129 -> V_133 ) |
( V_128 -> V_62 ^ V_129 -> V_62 ) |
( V_128 -> V_132 ^ V_129 -> V_132 ) |
( V_128 -> V_134 ^ V_129 -> V_134 ) ) == 0 ;
}
static inline int F_76 ( struct V_7 * V_128 , struct V_7 * V_129 )
{
return F_77 ( F_20 ( V_128 -> V_2 . V_4 ) , F_20 ( V_129 -> V_2 . V_4 ) ) ;
}
static inline int F_78 ( struct V_7 * V_111 )
{
return V_111 -> F_14 != F_14 ( F_20 ( V_111 -> V_2 . V_4 ) ) ;
}
static void F_79 ( struct V_32 * V_32 , int V_135 )
{
unsigned int V_21 ;
struct V_7 * V_111 , * V_136 ;
for ( V_21 = 0 ; V_21 <= V_31 ; V_21 ++ ) {
struct V_7 T_7 * * V_137 ;
struct V_7 * V_138 ;
if ( V_135 && F_80 () )
F_81 () ;
V_111 = F_17 ( V_41 [ V_21 ] . V_42 ) ;
if ( ! V_111 )
continue;
F_82 ( F_83 ( V_21 ) ) ;
V_138 = NULL ;
V_137 = & V_41 [ V_21 ] . V_42 ;
V_111 = F_84 ( * V_137 ,
F_85 ( F_83 ( V_21 ) ) ) ;
while ( V_111 ) {
V_136 = F_84 ( V_111 -> V_2 . V_43 ,
F_85 ( F_83 ( V_21 ) ) ) ;
if ( ! V_32 ||
F_77 ( F_20 ( V_111 -> V_2 . V_4 ) , V_32 ) ) {
F_86 ( * V_137 , V_136 ) ;
F_86 ( V_111 -> V_2 . V_43 , V_138 ) ;
V_138 = V_111 ;
} else {
V_137 = & V_111 -> V_2 . V_43 ;
}
V_111 = V_136 ;
}
F_87 ( F_83 ( V_21 ) ) ;
for (; V_138 ; V_138 = V_136 ) {
V_136 = F_84 ( V_138 -> V_2 . V_43 , 1 ) ;
F_63 ( V_138 ) ;
}
}
}
static int F_88 ( const struct V_7 * V_139 , const struct V_7 * V_111 )
{
const struct V_7 * V_140 = V_139 ;
while ( V_140 != V_111 ) {
if ( F_74 ( V_140 , V_111 ) )
return 0 ;
V_140 = F_84 ( V_140 -> V_2 . V_43 , 1 ) ;
}
return V_141 ;
}
static void F_89 ( void )
{
static unsigned int V_142 ;
unsigned int V_21 = V_142 , V_143 ;
struct V_7 * V_111 ;
struct V_7 T_7 * * V_144 ;
unsigned long V_145 = 0 ;
unsigned long V_146 = 0 , V_147 = 0 ;
unsigned long V_148 ;
T_8 V_149 ;
V_148 = V_122 - V_150 ;
V_150 = V_122 ;
V_149 = ( ( T_8 ) V_148 ) << V_151 ;
if ( V_152 > 1 )
F_90 ( V_149 , V_152 ) ;
V_143 = ( unsigned int ) V_149 ;
if ( V_143 > V_31 )
V_143 = V_31 + 1 ;
for (; V_143 > 0 ; V_143 -- ) {
unsigned long V_153 = V_152 ;
unsigned long V_154 ;
V_21 = ( V_21 + 1 ) & V_31 ;
V_144 = & V_41 [ V_21 ] . V_42 ;
if ( F_80 () )
F_81 () ;
V_145 ++ ;
if ( F_91 ( * V_144 ) == NULL )
continue;
V_154 = 0 ;
F_82 ( F_83 ( V_21 ) ) ;
while ( ( V_111 = F_84 ( * V_144 ,
F_85 ( F_83 ( V_21 ) ) ) ) != NULL ) {
F_92 ( V_111 -> V_2 . V_43 ) ;
if ( F_78 ( V_111 ) ) {
* V_144 = V_111 -> V_2 . V_43 ;
F_63 ( V_111 ) ;
continue;
}
if ( V_111 -> V_2 . V_155 ) {
if ( F_93 ( V_122 , V_111 -> V_2 . V_155 ) ) {
V_156:
V_153 >>= 1 ;
V_144 = & V_111 -> V_2 . V_43 ;
V_154 += F_88 ( V_41 [ V_21 ] . V_42 , V_111 ) ;
continue;
}
} else if ( ! F_70 ( V_111 , V_153 , V_152 ) )
goto V_156;
* V_144 = V_111 -> V_2 . V_43 ;
F_63 ( V_111 ) ;
}
F_87 ( F_83 ( V_21 ) ) ;
V_146 += V_154 ;
V_147 += V_154 * V_154 ;
}
if ( V_145 ) {
unsigned long V_157 = V_146 / V_145 ;
unsigned long V_158 = F_94 ( V_147 / V_145 - V_157 * V_157 ) ;
V_159 = F_95 (unsigned long,
ip_rt_gc_elasticity,
(avg + 4*sd) >> FRACT_BITS) ;
}
V_142 = V_21 ;
}
static void F_96 ( struct V_160 * V_161 )
{
F_89 () ;
F_97 ( & V_162 , V_163 ) ;
}
static void F_98 ( struct V_32 * V_32 )
{
unsigned char V_164 ;
F_99 ( & V_164 , sizeof( V_164 ) ) ;
F_100 ( V_164 + 1U , & V_32 -> V_33 . F_14 ) ;
F_101 ( V_165 ) ;
}
void F_102 ( struct V_32 * V_32 , int V_166 )
{
F_98 ( V_32 ) ;
if ( V_166 >= 0 )
F_79 ( V_32 , ! F_103 () ) ;
}
void F_104 ( struct V_32 * V_32 )
{
F_79 ( V_32 , ! F_103 () ) ;
}
static void F_105 ( struct V_32 * V_32 )
{
if ( F_106 () )
F_107 ( L_16 ) ;
F_98 ( V_32 ) ;
}
static int F_108 ( struct V_167 * V_168 )
{
static unsigned long V_169 = V_170 ;
static unsigned long V_171 ;
static int V_142 ;
static int V_172 ;
struct V_7 * V_111 ;
struct V_7 T_7 * * V_144 ;
unsigned long V_173 = V_122 ;
int V_143 ;
int V_174 = F_109 ( & V_70 ) ;
F_110 ( V_81 ) ;
if ( V_173 - V_171 < V_175 &&
V_174 < V_176 ) {
F_110 ( V_82 ) ;
goto V_121;
}
V_174 = F_44 ( & V_70 ) ;
V_143 = V_174 - ( V_177 << V_151 ) ;
if ( V_143 <= 0 ) {
if ( V_172 < V_70 . V_178 )
V_172 = V_70 . V_178 ;
V_143 = V_174 - V_172 ;
if ( V_143 > 0 ) {
V_172 += F_111 (unsigned int, goal >> 1 , rt_hash_mask + 1 ) ;
V_143 = V_174 - V_172 ;
}
} else {
V_143 = F_95 (unsigned int, goal >> 1 , rt_hash_mask + 1 ) ;
V_172 = V_174 - V_143 ;
}
if ( V_173 - V_171 >= V_175 )
V_171 = V_173 ;
if ( V_143 <= 0 ) {
V_172 += V_143 ;
goto V_179;
}
do {
int V_21 , V_180 ;
for ( V_21 = V_31 , V_180 = V_142 ; V_21 >= 0 ; V_21 -- ) {
unsigned long V_153 = V_169 ;
V_180 = ( V_180 + 1 ) & V_31 ;
V_144 = & V_41 [ V_180 ] . V_42 ;
F_82 ( F_83 ( V_180 ) ) ;
while ( ( V_111 = F_84 ( * V_144 ,
F_85 ( F_83 ( V_180 ) ) ) ) != NULL ) {
if ( ! F_78 ( V_111 ) &&
! F_70 ( V_111 , V_153 , V_169 ) ) {
V_153 >>= 1 ;
V_144 = & V_111 -> V_2 . V_43 ;
continue;
}
* V_144 = V_111 -> V_2 . V_43 ;
F_63 ( V_111 ) ;
V_143 -- ;
}
F_87 ( F_83 ( V_180 ) ) ;
if ( V_143 <= 0 )
break;
}
V_142 = V_180 ;
if ( V_143 <= 0 )
goto V_179;
F_110 ( V_83 ) ;
if ( V_169 == 0 )
break;
V_169 >>= 1 ;
if ( F_109 ( & V_70 ) < V_176 )
goto V_121;
} while ( ! F_103 () && F_93 ( V_122 , V_173 ) );
if ( F_109 ( & V_70 ) < V_176 )
goto V_121;
if ( F_44 ( & V_70 ) < V_176 )
goto V_121;
if ( F_106 () )
F_107 ( L_17 ) ;
F_110 ( V_84 ) ;
return 1 ;
V_179:
V_169 += V_175 ;
if ( V_169 > V_152 ||
F_109 ( & V_70 ) < V_70 . V_178 ||
F_44 ( & V_70 ) < V_70 . V_178 )
V_169 = V_152 ;
V_121: return 0 ;
}
static int F_112 ( const struct V_7 * V_139 )
{
int V_154 = 0 ;
const struct V_7 * V_111 = V_139 ;
while ( V_111 ) {
V_154 += F_88 ( V_139 , V_111 ) ;
V_111 = F_84 ( V_111 -> V_2 . V_43 , 1 ) ;
}
return V_154 >> V_181 ;
}
static struct V_47 * F_113 ( const struct V_1 * V_2 , const void * V_26 )
{
static const T_3 V_182 = 0 ;
struct V_3 * V_4 = V_2 -> V_4 ;
const T_3 * V_183 = V_26 ;
const struct V_7 * V_8 ;
struct V_47 * V_48 ;
V_8 = ( const struct V_7 * ) V_2 ;
if ( V_4 -> V_184 & ( V_185 | V_186 ) )
V_183 = & V_182 ;
else if ( V_8 -> V_54 )
V_183 = ( const T_3 * ) & V_8 -> V_54 ;
V_48 = F_114 ( V_4 , * ( V_30 T_1 * ) V_183 ) ;
if ( V_48 )
return V_48 ;
return F_115 ( & V_187 , V_183 , V_4 ) ;
}
static int F_116 ( struct V_7 * V_8 )
{
struct V_47 * V_48 = F_113 ( & V_8 -> V_2 , & V_8 -> V_54 ) ;
if ( F_117 ( V_48 ) )
return F_118 ( V_48 ) ;
F_119 ( & V_8 -> V_2 , V_48 ) ;
return 0 ;
}
static struct V_7 * F_120 ( unsigned V_188 , struct V_7 * V_8 ,
struct V_189 * V_190 , int V_191 )
{
struct V_7 * V_111 , * V_192 ;
struct V_7 T_7 * * V_144 , * * V_193 ;
unsigned long V_173 ;
T_1 V_194 ;
int V_195 ;
int V_196 = ! F_103 () ;
V_197:
V_195 = 0 ;
V_194 = ~ ( T_1 ) 0 ;
V_192 = NULL ;
V_193 = NULL ;
V_173 = V_122 ;
if ( ! F_73 ( F_20 ( V_8 -> V_2 . V_4 ) ) ) {
V_8 -> V_2 . V_184 |= V_198 ;
if ( V_8 -> V_199 == V_200 || F_72 ( V_8 ) ) {
int V_201 = F_116 ( V_8 ) ;
if ( V_201 ) {
if ( F_106 () )
F_107 ( L_18 ) ;
F_66 ( V_8 ) ;
return F_121 ( V_201 ) ;
}
}
goto V_202;
}
V_144 = & V_41 [ V_188 ] . V_42 ;
F_82 ( F_83 ( V_188 ) ) ;
while ( ( V_111 = F_84 ( * V_144 ,
F_85 ( F_83 ( V_188 ) ) ) ) != NULL ) {
if ( F_78 ( V_111 ) ) {
* V_144 = V_111 -> V_2 . V_43 ;
F_63 ( V_111 ) ;
continue;
}
if ( F_75 ( V_111 , V_8 ) && F_76 ( V_111 , V_8 ) ) {
* V_144 = V_111 -> V_2 . V_43 ;
F_86 ( V_111 -> V_2 . V_43 ,
V_41 [ V_188 ] . V_42 ) ;
F_86 ( V_41 [ V_188 ] . V_42 , V_111 ) ;
F_122 ( & V_111 -> V_2 , V_173 ) ;
F_87 ( F_83 ( V_188 ) ) ;
F_65 ( V_8 ) ;
if ( V_190 )
F_123 ( V_190 , & V_111 -> V_2 ) ;
return V_111 ;
}
if ( ! F_15 ( & V_111 -> V_2 . V_56 ) ) {
T_1 V_124 = F_71 ( V_111 ) ;
if ( V_124 <= V_194 ) {
V_192 = V_111 ;
V_193 = V_144 ;
V_194 = V_124 ;
}
}
V_195 ++ ;
V_144 = & V_111 -> V_2 . V_43 ;
}
if ( V_192 ) {
if ( V_195 > V_177 ) {
* V_193 = V_192 -> V_2 . V_43 ;
F_63 ( V_192 ) ;
}
} else {
if ( V_195 > V_159 &&
F_112 ( V_41 [ V_188 ] . V_42 ) > V_159 ) {
struct V_32 * V_32 = F_20 ( V_8 -> V_2 . V_4 ) ;
int V_203 = ++ V_32 -> V_33 . V_126 ;
if ( ! F_73 ( V_32 ) ) {
F_107 ( L_19 ,
V_8 -> V_2 . V_4 -> V_53 , V_203 ) ;
}
F_105 ( V_32 ) ;
F_87 ( F_83 ( V_188 ) ) ;
V_188 = F_12 ( V_8 -> V_130 , V_8 -> V_131 ,
V_191 , F_14 ( V_32 ) ) ;
goto V_197;
}
}
if ( V_8 -> V_199 == V_200 || F_72 ( V_8 ) ) {
int V_201 = F_116 ( V_8 ) ;
if ( V_201 ) {
F_87 ( F_83 ( V_188 ) ) ;
if ( V_201 != - V_204 ) {
F_65 ( V_8 ) ;
return F_121 ( V_201 ) ;
}
if ( V_196 -- > 0 ) {
int V_205 = V_177 ;
int V_206 = V_175 ;
V_177 = 1 ;
V_175 = 0 ;
F_108 ( & V_70 ) ;
V_175 = V_206 ;
V_177 = V_205 ;
goto V_197;
}
if ( F_106 () )
F_107 ( L_20 ) ;
F_65 ( V_8 ) ;
return F_121 ( - V_204 ) ;
}
}
V_8 -> V_2 . V_43 = V_41 [ V_188 ] . V_42 ;
F_86 ( V_41 [ V_188 ] . V_42 , V_8 ) ;
F_87 ( F_83 ( V_188 ) ) ;
V_202:
if ( V_190 )
F_123 ( V_190 , & V_8 -> V_2 ) ;
return V_8 ;
}
static T_1 F_124 ( void )
{
return F_15 ( & V_207 ) ;
}
void F_3 ( struct V_7 * V_8 , T_3 V_26 , int V_208 )
{
struct V_9 * V_10 ;
V_10 = F_125 ( V_26 , V_208 ) ;
if ( V_10 && F_6 ( & V_8 -> V_10 , NULL , V_10 ) != NULL )
F_126 ( V_10 ) ;
else
V_8 -> F_124 = F_124 () ;
}
static void F_127 ( struct V_209 * V_210 )
{
static F_128 ( V_211 ) ;
static T_1 V_212 ;
T_1 V_213 ;
F_82 ( & V_211 ) ;
V_213 = F_129 ( ( V_30 T_3 ) V_212 ^ V_210 -> V_26 ) ;
V_210 -> V_214 = F_130 ( V_213 & 0xFFFF ) ;
V_212 = V_213 ;
F_87 ( & V_211 ) ;
}
void F_131 ( struct V_209 * V_210 , struct V_1 * V_2 , int V_215 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
if ( V_8 && ! ( V_8 -> V_2 . V_184 & V_216 ) ) {
if ( V_8 -> V_10 == NULL )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
if ( V_8 -> V_10 ) {
V_210 -> V_214 = F_130 ( F_132 ( V_8 -> V_10 , V_215 ) ) ;
return;
}
} else if ( ! V_8 )
F_133 ( V_217 L_21 ,
F_134 ( 0 ) ) ;
F_127 ( V_210 ) ;
}
static void F_135 ( unsigned V_188 , struct V_7 * V_8 )
{
struct V_7 T_7 * * V_144 ;
struct V_7 * V_140 ;
V_144 = & V_41 [ V_188 ] . V_42 ;
F_82 ( F_83 ( V_188 ) ) ;
F_66 ( V_8 ) ;
while ( ( V_140 = F_84 ( * V_144 ,
F_85 ( F_83 ( V_188 ) ) ) ) != NULL ) {
if ( V_140 == V_8 || F_78 ( V_140 ) ) {
* V_144 = V_140 -> V_2 . V_43 ;
F_63 ( V_140 ) ;
continue;
}
V_144 = & V_140 -> V_2 . V_43 ;
}
F_87 ( F_83 ( V_188 ) ) ;
}
static void F_136 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
T_3 V_218 = V_8 -> V_54 ;
struct V_47 * V_48 , * V_219 ;
F_137 ( & V_8 -> V_2 ) ;
V_8 -> V_54 = V_10 -> V_220 . V_221 ;
V_48 = F_113 ( & V_8 -> V_2 , & V_8 -> V_54 ) ;
if ( F_117 ( V_48 ) ) {
V_8 -> V_54 = V_218 ;
return;
}
V_219 = F_138 ( & V_8 -> V_2 . V_222 , V_48 ) ;
if ( V_219 )
F_139 ( V_219 ) ;
if ( ! ( V_48 -> V_51 & V_223 ) ) {
F_140 ( V_48 , NULL ) ;
} else {
V_8 -> V_55 |= V_114 ;
F_141 ( V_224 , V_48 ) ;
}
}
void F_142 ( T_3 V_225 , T_3 V_26 , T_3 V_226 ,
T_3 V_27 , struct V_3 * V_4 )
{
int V_227 , V_21 ;
struct V_228 * V_229 = F_143 ( V_4 ) ;
T_3 V_230 [ 2 ] = { V_27 , 0 } ;
int V_231 [ 2 ] = { V_4 -> V_191 , 0 } ;
struct V_9 * V_10 ;
struct V_32 * V_32 ;
if ( ! V_229 )
return;
V_32 = F_20 ( V_4 ) ;
if ( V_226 == V_225 || ! F_144 ( V_229 ) ||
F_145 ( V_226 ) || F_146 ( V_226 ) ||
F_147 ( V_226 ) )
goto V_232;
if ( ! F_148 ( V_229 ) ) {
if ( ! F_149 ( V_229 , V_226 , V_225 ) )
goto V_232;
if ( F_150 ( V_229 ) && F_151 ( V_226 , V_4 ) )
goto V_232;
} else {
if ( F_152 ( V_32 , V_226 ) != V_200 )
goto V_232;
}
for ( V_227 = 0 ; V_227 < 2 ; V_227 ++ ) {
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
unsigned int V_188 ;
struct V_7 T_7 * * V_144 ;
struct V_7 * V_8 ;
V_188 = F_12 ( V_26 , V_230 [ V_227 ] , V_231 [ V_21 ] , F_14 ( V_32 ) ) ;
V_144 = & V_41 [ V_188 ] . V_42 ;
while ( ( V_8 = F_153 ( * V_144 ) ) != NULL ) {
V_144 = & V_8 -> V_2 . V_43 ;
if ( V_8 -> V_130 != V_26 ||
V_8 -> V_131 != V_230 [ V_227 ] ||
V_8 -> V_134 != V_231 [ V_21 ] ||
F_68 ( V_8 ) ||
F_78 ( V_8 ) ||
! F_77 ( F_20 ( V_8 -> V_2 . V_4 ) , V_32 ) ||
V_8 -> V_2 . error ||
V_8 -> V_2 . V_4 != V_4 ||
V_8 -> V_54 != V_225 )
continue;
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
V_10 = V_8 -> V_10 ;
if ( V_10 ) {
if ( V_10 -> V_220 . V_221 != V_226 ) {
V_10 -> V_220 . V_221 = V_226 ;
F_154 ( & V_207 ) ;
}
F_136 ( & V_8 -> V_2 , V_10 ) ;
}
}
}
}
return;
V_232:
#ifdef F_155
if ( F_156 ( V_229 ) && F_106 () )
F_157 ( L_22
L_23 ,
& V_225 , V_4 -> V_53 , & V_226 ,
& V_27 , & V_26 ) ;
#endif
;
}
static bool F_158 ( struct V_9 * V_10 )
{
unsigned long V_233 = F_159 ( V_10 -> V_116 ) ;
return V_233 &&
F_160 ( V_122 , V_233 ) &&
F_6 ( & V_10 -> V_116 , V_233 , 0 ) == V_233 ;
}
static bool F_161 ( struct V_9 * V_10 )
{
unsigned long V_233 = F_159 ( V_10 -> V_116 ) ;
return V_233 &&
F_6 ( & V_10 -> V_116 , V_233 , 0 ) == V_233 ;
}
static struct V_1 * F_162 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
struct V_1 * V_120 = V_2 ;
if ( V_8 ) {
if ( V_2 -> V_234 > 0 ) {
F_66 ( V_8 ) ;
V_120 = NULL ;
} else if ( V_8 -> V_55 & V_114 ) {
unsigned V_188 = F_12 ( V_8 -> V_130 , V_8 -> V_131 ,
V_8 -> V_134 ,
F_14 ( F_20 ( V_2 -> V_4 ) ) ) ;
F_135 ( V_188 , V_8 ) ;
V_120 = NULL ;
} else if ( V_8 -> V_10 && F_158 ( V_8 -> V_10 ) ) {
F_163 ( V_2 , V_235 , V_8 -> V_10 -> V_236 ) ;
}
}
return V_120 ;
}
void F_164 ( struct V_189 * V_190 )
{
struct V_7 * V_8 = F_165 ( V_190 ) ;
struct V_228 * V_229 ;
struct V_9 * V_10 ;
int V_237 ;
F_31 () ;
V_229 = F_143 ( V_8 -> V_2 . V_4 ) ;
if ( ! V_229 || ! F_166 ( V_229 ) ) {
F_33 () ;
return;
}
V_237 = F_156 ( V_229 ) ;
F_33 () ;
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
V_10 = V_8 -> V_10 ;
if ( ! V_10 ) {
F_167 ( V_190 , V_238 , V_239 , V_8 -> V_54 ) ;
return;
}
if ( F_168 ( V_122 , V_10 -> V_240 + V_241 ) )
V_10 -> V_242 = 0 ;
if ( V_10 -> V_242 >= V_243 ) {
V_10 -> V_240 = V_122 ;
return;
}
if ( V_10 -> V_242 == 0 ||
F_168 ( V_122 ,
( V_10 -> V_240 +
( V_244 << V_10 -> V_242 ) ) ) ) {
F_167 ( V_190 , V_238 , V_239 , V_8 -> V_54 ) ;
V_10 -> V_240 = V_122 ;
++ V_10 -> V_242 ;
#ifdef F_155
if ( V_237 &&
V_10 -> V_242 == V_243 &&
F_106 () )
F_107 ( L_24 ,
& F_169 ( V_190 ) -> V_27 , V_8 -> V_245 ,
& V_8 -> V_12 , & V_8 -> V_54 ) ;
#endif
}
}
static int F_170 ( struct V_189 * V_190 )
{
struct V_7 * V_8 = F_165 ( V_190 ) ;
struct V_9 * V_10 ;
unsigned long V_173 ;
bool V_246 ;
int V_247 ;
switch ( V_8 -> V_2 . error ) {
case V_248 :
default:
goto V_121;
case V_249 :
V_247 = V_250 ;
break;
case V_251 :
V_247 = V_252 ;
F_171 ( F_20 ( V_8 -> V_2 . V_4 ) ,
V_253 ) ;
break;
case V_254 :
V_247 = V_255 ;
break;
}
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
V_10 = V_8 -> V_10 ;
V_246 = true ;
if ( V_10 ) {
V_173 = V_122 ;
V_10 -> V_242 += V_173 - V_10 -> V_240 ;
if ( V_10 -> V_242 > V_256 )
V_10 -> V_242 = V_256 ;
V_10 -> V_240 = V_173 ;
if ( V_10 -> V_242 >= V_257 )
V_10 -> V_242 -= V_257 ;
else
V_246 = false ;
}
if ( V_246 )
F_167 ( V_190 , V_258 , V_247 , 0 ) ;
V_121: F_172 ( V_190 ) ;
return 0 ;
}
static inline unsigned short F_173 ( unsigned short V_259 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < F_174 ( V_260 ) ; V_21 ++ )
if ( V_259 > V_260 [ V_21 ] )
return V_260 [ V_21 ] ;
return 68 ;
}
unsigned short F_175 ( struct V_32 * V_32 , const struct V_209 * V_210 ,
unsigned short V_261 ,
struct V_3 * V_4 )
{
unsigned short V_259 = F_176 ( V_210 -> V_262 ) ;
unsigned short V_263 = 0 ;
struct V_9 * V_10 ;
V_10 = F_125 ( V_210 -> V_26 , 1 ) ;
if ( V_10 ) {
unsigned short V_264 = V_261 ;
if ( V_261 < 68 || V_261 >= V_259 ) {
if ( V_264 == 0 &&
V_259 >= 68 + ( V_210 -> V_265 << 2 ) )
V_259 -= V_210 -> V_265 << 2 ;
V_264 = F_173 ( V_259 ) ;
}
if ( V_264 < V_266 )
V_264 = V_266 ;
if ( ! V_10 -> V_116 || V_264 < V_10 -> V_267 ) {
unsigned long V_116 ;
V_116 = V_122 + V_268 ;
if ( ! V_116 )
V_116 = 1UL ;
V_263 = V_264 ;
V_10 -> V_267 = V_264 ;
V_10 -> V_116 = V_116 ;
F_154 ( & V_207 ) ;
}
F_126 ( V_10 ) ;
}
return V_263 ? : V_261 ;
}
static void F_177 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned long V_155 = F_159 ( V_10 -> V_116 ) ;
if ( ! V_155 )
return;
if ( F_178 ( V_122 , V_155 ) ) {
T_1 V_269 = F_179 ( V_2 ) ;
if ( V_10 -> V_267 < V_269 ) {
if ( ! V_10 -> V_236 )
V_10 -> V_236 = F_180 ( V_2 , V_235 ) ;
F_163 ( V_2 , V_235 , V_10 -> V_267 ) ;
}
} else if ( F_6 ( & V_10 -> V_116 , V_155 , 0 ) == V_155 )
F_163 ( V_2 , V_235 , V_10 -> V_236 ) ;
}
static void F_181 ( struct V_1 * V_2 , T_1 V_264 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
struct V_9 * V_10 ;
F_137 ( V_2 ) ;
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
V_10 = V_8 -> V_10 ;
if ( V_10 ) {
unsigned long V_116 = F_159 ( V_10 -> V_116 ) ;
if ( V_264 < V_266 )
V_264 = V_266 ;
if ( ! V_116 || V_264 < V_10 -> V_267 ) {
V_116 = V_122 + V_268 ;
if ( ! V_116 )
V_116 = 1UL ;
V_10 -> V_267 = V_264 ;
V_10 -> V_116 = V_116 ;
F_154 ( & V_207 ) ;
V_8 -> F_124 = F_124 () ;
}
F_177 ( V_2 , V_10 ) ;
}
}
static void F_182 ( struct V_7 * V_8 )
{
if ( V_8 -> F_124 != F_124 () ) {
struct V_9 * V_10 ;
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 0 ) ;
V_10 = V_8 -> V_10 ;
if ( V_10 ) {
F_177 ( & V_8 -> V_2 , V_10 ) ;
if ( V_10 -> V_220 . V_221 &&
V_10 -> V_220 . V_221 != V_8 -> V_54 )
F_136 ( & V_8 -> V_2 , V_10 ) ;
}
V_8 -> F_124 = F_124 () ;
}
}
static struct V_1 * F_183 ( struct V_1 * V_2 , T_1 V_270 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
if ( F_78 ( V_8 ) )
return NULL ;
F_182 ( V_8 ) ;
return V_2 ;
}
static void F_184 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
struct V_9 * V_10 = V_8 -> V_10 ;
if ( V_8 -> V_20 ) {
F_7 ( V_8 -> V_20 ) ;
V_8 -> V_20 = NULL ;
}
if ( V_10 ) {
V_8 -> V_10 = NULL ;
F_126 ( V_10 ) ;
}
}
static void F_185 ( struct V_189 * V_190 )
{
struct V_7 * V_8 ;
F_167 ( V_190 , V_258 , V_250 , 0 ) ;
V_8 = F_165 ( V_190 ) ;
if ( V_8 && V_8 -> V_10 && F_161 ( V_8 -> V_10 ) )
F_163 ( & V_8 -> V_2 , V_235 , V_8 -> V_10 -> V_236 ) ;
}
static int F_186 ( struct V_189 * V_190 )
{
F_133 ( V_217 L_25 ,
& F_169 ( V_190 ) -> V_27 , & F_169 ( V_190 ) -> V_26 ,
V_190 -> V_4 ? V_190 -> V_4 -> V_53 : L_26 ) ;
F_172 ( V_190 ) ;
F_187 ( 1 ) ;
return 0 ;
}
void F_188 ( T_9 * V_271 , struct V_189 * V_190 , struct V_7 * V_8 )
{
T_3 V_90 ;
if ( F_72 ( V_8 ) )
V_90 = F_169 ( V_190 ) -> V_27 ;
else {
struct V_272 V_273 ;
struct V_274 V_275 ;
struct V_209 * V_210 ;
V_210 = F_169 ( V_190 ) ;
memset ( & V_275 , 0 , sizeof( V_275 ) ) ;
V_275 . V_26 = V_210 -> V_26 ;
V_275 . V_27 = V_210 -> V_27 ;
V_275 . V_276 = F_189 ( V_210 -> V_277 ) ;
V_275 . V_278 = V_8 -> V_2 . V_4 -> V_191 ;
V_275 . V_279 = V_190 -> V_4 -> V_191 ;
V_275 . V_280 = V_190 -> V_281 ;
F_31 () ;
if ( F_190 ( F_20 ( V_8 -> V_2 . V_4 ) , & V_275 , & V_273 ) == 0 )
V_90 = F_191 ( F_20 ( V_8 -> V_2 . V_4 ) , V_273 ) ;
else
V_90 = F_192 ( V_8 -> V_2 . V_4 , V_8 -> V_54 ,
V_282 ) ;
F_33 () ;
}
memcpy ( V_271 , & V_90 , 4 ) ;
}
static void F_193 ( struct V_7 * V_8 , T_1 V_283 )
{
if ( ! ( V_8 -> V_2 . V_284 & 0xFFFF ) )
V_8 -> V_2 . V_284 |= V_283 & 0xFFFF ;
if ( ! ( V_8 -> V_2 . V_284 & 0xFFFF0000 ) )
V_8 -> V_2 . V_284 |= V_283 & 0xFFFF0000 ;
}
static unsigned int F_194 ( const struct V_1 * V_2 )
{
unsigned int V_285 = F_180 ( V_2 , V_286 ) ;
if ( V_285 == 0 ) {
V_285 = F_95 (unsigned int, dst->dev->mtu - 40 ,
ip_rt_min_advmss) ;
if ( V_285 > 65535 - 40 )
V_285 = 65535 - 40 ;
}
return V_285 ;
}
static unsigned int F_195 ( const struct V_1 * V_2 )
{
const struct V_7 * V_8 = ( const struct V_7 * ) V_2 ;
unsigned int V_264 = F_180 ( V_2 , V_235 ) ;
if ( V_264 && F_72 ( V_8 ) )
return V_264 ;
V_264 = V_2 -> V_4 -> V_264 ;
if ( F_196 ( F_197 ( V_2 , V_235 ) ) ) {
if ( V_8 -> V_54 != V_8 -> V_12 && V_264 > 576 )
V_264 = 576 ;
}
if ( V_264 > V_287 )
V_264 = V_287 ;
return V_264 ;
}
static void F_198 ( struct V_7 * V_8 , const struct V_274 * V_275 ,
struct V_288 * V_20 )
{
struct V_9 * V_10 ;
int V_208 = 0 ;
if ( V_275 && ( V_275 -> V_289 & V_290 ) )
V_208 = 1 ;
V_8 -> V_10 = V_10 = F_125 ( V_8 -> V_12 , V_208 ) ;
if ( V_10 ) {
V_8 -> F_124 = F_124 () ;
if ( F_5 ( V_10 ) )
memcpy ( V_10 -> V_16 , V_20 -> V_291 ,
sizeof( T_1 ) * V_17 ) ;
F_199 ( & V_8 -> V_2 , V_10 -> V_16 , false ) ;
F_177 ( & V_8 -> V_2 , V_10 ) ;
if ( V_10 -> V_220 . V_221 &&
V_10 -> V_220 . V_221 != V_8 -> V_54 ) {
V_8 -> V_54 = V_10 -> V_220 . V_221 ;
V_8 -> V_55 |= V_114 ;
}
} else {
if ( V_20 -> V_291 != ( T_1 * ) V_292 ) {
V_8 -> V_20 = V_20 ;
F_154 ( & V_20 -> V_293 ) ;
}
F_199 ( & V_8 -> V_2 , V_20 -> V_291 , true ) ;
}
}
static void F_200 ( struct V_7 * V_8 , const struct V_274 * V_275 ,
const struct V_272 * V_273 ,
struct V_288 * V_20 , T_10 type , T_1 V_294 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
if ( V_20 ) {
if ( F_201 ( * V_273 ) &&
F_202 ( * V_273 ) . V_295 == V_296 )
V_8 -> V_54 = F_201 ( * V_273 ) ;
F_198 ( V_8 , V_275 , V_20 ) ;
#ifdef F_58
V_2 -> V_284 = F_202 ( * V_273 ) . V_297 ;
#endif
}
if ( F_179 ( V_2 ) > V_287 )
F_163 ( V_2 , V_235 , V_287 ) ;
if ( F_180 ( V_2 , V_286 ) > 65535 - 40 )
F_163 ( V_2 , V_286 , 65535 - 40 ) ;
#ifdef F_58
#ifdef F_203
F_193 ( V_8 , F_204 ( V_273 ) ) ;
#endif
F_193 ( V_8 , V_294 ) ;
#endif
}
static struct V_7 * F_205 ( struct V_3 * V_4 ,
bool V_298 , bool V_299 )
{
return F_206 ( & V_70 , V_4 , 1 , - 1 ,
V_300 |
( V_298 ? V_301 : 0 ) |
( V_299 ? V_302 : 0 ) ) ;
}
static int F_207 ( struct V_189 * V_190 , T_3 V_26 , T_3 V_27 ,
T_9 V_277 , struct V_3 * V_4 , int V_303 )
{
unsigned int V_188 ;
struct V_7 * V_111 ;
T_3 V_304 ;
struct V_228 * V_229 = F_143 ( V_4 ) ;
T_1 V_294 = 0 ;
int V_201 ;
if ( V_229 == NULL )
return - V_248 ;
if ( F_145 ( V_27 ) || F_146 ( V_27 ) ||
F_208 ( V_27 ) || V_190 -> V_305 != F_130 ( V_306 ) )
goto V_307;
if ( F_147 ( V_27 ) ) {
if ( ! F_209 ( V_26 ) )
goto V_307;
V_304 = F_192 ( V_4 , 0 , V_296 ) ;
} else {
V_201 = F_210 ( V_190 , V_27 , 0 , V_277 , 0 , V_4 , & V_304 ,
& V_294 ) ;
if ( V_201 < 0 )
goto V_308;
}
V_111 = F_205 ( F_20 ( V_4 ) -> V_309 ,
F_211 ( V_229 , V_310 ) , false ) ;
if ( ! V_111 )
goto V_311;
#ifdef F_58
V_111 -> V_2 . V_284 = V_294 ;
#endif
V_111 -> V_2 . V_312 = F_186 ;
V_111 -> V_130 = V_26 ;
V_111 -> V_131 = V_27 ;
V_111 -> F_14 = F_14 ( F_20 ( V_4 ) ) ;
V_111 -> V_55 = V_113 ;
V_111 -> V_199 = V_313 ;
V_111 -> V_62 = V_277 ;
V_111 -> V_12 = V_26 ;
V_111 -> V_58 = V_27 ;
V_111 -> V_132 = V_4 -> V_191 ;
V_111 -> V_245 = V_4 -> V_191 ;
V_111 -> V_134 = 0 ;
V_111 -> V_133 = V_190 -> V_281 ;
V_111 -> V_54 = V_26 ;
V_111 -> V_63 = V_304 ;
V_111 -> F_124 = 0 ;
V_111 -> V_10 = NULL ;
V_111 -> V_20 = NULL ;
if ( V_303 ) {
V_111 -> V_2 . V_314 = V_315 ;
V_111 -> V_55 |= V_125 ;
}
#ifdef F_212
if ( ! F_209 ( V_26 ) && F_213 ( V_229 ) )
V_111 -> V_2 . V_314 = V_316 ;
#endif
F_110 ( V_73 ) ;
V_188 = F_12 ( V_26 , V_27 , V_4 -> V_191 , F_14 ( F_20 ( V_4 ) ) ) ;
V_111 = F_120 ( V_188 , V_111 , V_190 , V_4 -> V_191 ) ;
return F_117 ( V_111 ) ? F_118 ( V_111 ) : 0 ;
V_311:
return - V_204 ;
V_307:
return - V_248 ;
V_308:
return V_201 ;
}
static void F_214 ( struct V_3 * V_4 ,
struct V_228 * V_229 ,
struct V_189 * V_190 ,
T_3 V_26 ,
T_3 V_27 )
{
F_110 ( V_77 ) ;
#ifdef F_155
if ( F_156 ( V_229 ) && F_106 () ) {
F_107 ( L_27 ,
& V_26 , & V_27 , V_4 -> V_53 ) ;
if ( V_4 -> V_317 && F_215 ( V_190 ) ) {
F_216 ( V_318 , L_28 ,
V_319 , 16 , 1 ,
F_217 ( V_190 ) ,
V_4 -> V_317 , true ) ;
}
}
#endif
}
static int F_218 ( struct V_189 * V_190 ,
const struct V_272 * V_273 ,
struct V_228 * V_229 ,
T_3 V_26 , T_3 V_27 , T_1 V_277 ,
struct V_7 * * V_320 )
{
struct V_7 * V_111 ;
int V_201 ;
struct V_228 * V_321 ;
unsigned int V_184 = 0 ;
T_3 V_304 ;
T_1 V_294 ;
V_321 = F_143 ( F_219 ( * V_273 ) ) ;
if ( V_321 == NULL ) {
if ( F_106 () )
F_220 ( L_29 ) ;
return - V_248 ;
}
V_201 = F_210 ( V_190 , V_27 , V_26 , V_277 , F_221 ( * V_273 ) ,
V_229 -> V_4 , & V_304 , & V_294 ) ;
if ( V_201 < 0 ) {
F_214 ( V_229 -> V_4 , V_229 , V_190 , V_26 ,
V_27 ) ;
goto V_322;
}
if ( V_201 )
V_184 |= V_323 ;
if ( V_321 == V_229 && V_201 &&
( F_148 ( V_321 ) ||
F_149 ( V_321 , V_27 , F_201 ( * V_273 ) ) ) )
V_184 |= V_324 ;
if ( V_190 -> V_305 != F_130 ( V_306 ) ) {
if ( V_321 == V_229 &&
F_222 ( V_229 ) == 0 ) {
V_201 = - V_248 ;
goto V_322;
}
}
V_111 = F_205 ( V_321 -> V_4 ,
F_211 ( V_229 , V_310 ) ,
F_211 ( V_321 , V_325 ) ) ;
if ( ! V_111 ) {
V_201 = - V_204 ;
goto V_322;
}
V_111 -> V_130 = V_26 ;
V_111 -> V_131 = V_27 ;
V_111 -> F_14 = F_14 ( F_20 ( V_111 -> V_2 . V_4 ) ) ;
V_111 -> V_55 = V_184 ;
V_111 -> V_199 = V_273 -> type ;
V_111 -> V_62 = V_277 ;
V_111 -> V_12 = V_26 ;
V_111 -> V_58 = V_27 ;
V_111 -> V_132 = V_229 -> V_4 -> V_191 ;
V_111 -> V_245 = V_229 -> V_4 -> V_191 ;
V_111 -> V_134 = 0 ;
V_111 -> V_133 = V_190 -> V_281 ;
V_111 -> V_54 = V_26 ;
V_111 -> V_63 = V_304 ;
V_111 -> F_124 = 0 ;
V_111 -> V_10 = NULL ;
V_111 -> V_20 = NULL ;
V_111 -> V_2 . V_314 = V_326 ;
V_111 -> V_2 . V_312 = V_327 ;
F_200 ( V_111 , NULL , V_273 , V_273 -> V_20 , V_273 -> type , V_294 ) ;
* V_320 = V_111 ;
V_201 = 0 ;
V_322:
return V_201 ;
}
static int F_223 ( struct V_189 * V_190 ,
struct V_272 * V_273 ,
const struct V_274 * V_275 ,
struct V_228 * V_229 ,
T_3 V_26 , T_3 V_27 , T_1 V_277 )
{
struct V_7 * V_111 = NULL ;
int V_201 ;
unsigned V_188 ;
#ifdef F_224
if ( V_273 -> V_20 && V_273 -> V_20 -> V_328 > 1 )
F_225 ( V_273 ) ;
#endif
V_201 = F_218 ( V_190 , V_273 , V_229 , V_26 , V_27 , V_277 , & V_111 ) ;
if ( V_201 )
return V_201 ;
V_188 = F_12 ( V_26 , V_27 , V_275 -> V_279 ,
F_14 ( F_20 ( V_111 -> V_2 . V_4 ) ) ) ;
V_111 = F_120 ( V_188 , V_111 , V_190 , V_275 -> V_279 ) ;
if ( F_117 ( V_111 ) )
return F_118 ( V_111 ) ;
return 0 ;
}
static int F_226 ( struct V_189 * V_190 , T_3 V_26 , T_3 V_27 ,
T_9 V_277 , struct V_3 * V_4 )
{
struct V_272 V_273 ;
struct V_228 * V_229 = F_143 ( V_4 ) ;
struct V_274 V_275 ;
unsigned V_184 = 0 ;
T_1 V_294 = 0 ;
struct V_7 * V_111 ;
unsigned V_188 ;
T_3 V_304 ;
int V_201 = - V_248 ;
struct V_32 * V_32 = F_20 ( V_4 ) ;
if ( ! V_229 )
goto V_121;
if ( F_145 ( V_27 ) || F_146 ( V_27 ) ||
F_208 ( V_27 ) )
goto V_329;
if ( F_146 ( V_26 ) || ( V_27 == 0 && V_26 == 0 ) )
goto V_330;
if ( F_147 ( V_27 ) )
goto V_329;
if ( F_147 ( V_26 ) || F_208 ( V_26 ) )
goto V_331;
V_275 . V_278 = 0 ;
V_275 . V_279 = V_4 -> V_191 ;
V_275 . V_280 = V_190 -> V_281 ;
V_275 . V_276 = V_277 ;
V_275 . V_332 = V_282 ;
V_275 . V_26 = V_26 ;
V_275 . V_27 = V_27 ;
V_201 = F_190 ( V_32 , & V_275 , & V_273 ) ;
if ( V_201 != 0 ) {
if ( ! F_227 ( V_229 ) )
goto V_333;
goto V_334;
}
F_110 ( V_72 ) ;
if ( V_273 . type == V_335 )
goto V_330;
if ( V_273 . type == V_336 ) {
V_201 = F_210 ( V_190 , V_27 , V_26 , V_277 ,
V_32 -> V_309 -> V_191 ,
V_4 , & V_304 , & V_294 ) ;
if ( V_201 < 0 )
goto V_337;
if ( V_201 )
V_184 |= V_323 ;
V_304 = V_26 ;
goto V_338;
}
if ( ! F_227 ( V_229 ) )
goto V_333;
if ( V_273 . type != V_200 )
goto V_331;
V_201 = F_223 ( V_190 , & V_273 , & V_275 , V_229 , V_26 , V_27 , V_277 ) ;
V_121: return V_201 ;
V_330:
if ( V_190 -> V_305 != F_130 ( V_306 ) )
goto V_307;
if ( F_147 ( V_27 ) )
V_304 = F_192 ( V_4 , 0 , V_296 ) ;
else {
V_201 = F_210 ( V_190 , V_27 , 0 , V_277 , 0 , V_4 , & V_304 ,
& V_294 ) ;
if ( V_201 < 0 )
goto V_337;
if ( V_201 )
V_184 |= V_323 ;
}
V_184 |= V_112 ;
V_273 . type = V_335 ;
F_110 ( V_75 ) ;
V_338:
V_111 = F_205 ( V_32 -> V_309 ,
F_211 ( V_229 , V_310 ) , false ) ;
if ( ! V_111 )
goto V_311;
V_111 -> V_2 . V_314 = V_315 ;
V_111 -> V_2 . V_312 = F_186 ;
#ifdef F_58
V_111 -> V_2 . V_284 = V_294 ;
#endif
V_111 -> V_130 = V_26 ;
V_111 -> V_131 = V_27 ;
V_111 -> F_14 = F_14 ( V_32 ) ;
V_111 -> V_55 = V_184 | V_125 ;
V_111 -> V_199 = V_273 . type ;
V_111 -> V_62 = V_277 ;
V_111 -> V_12 = V_26 ;
V_111 -> V_58 = V_27 ;
#ifdef F_58
V_111 -> V_2 . V_284 = V_294 ;
#endif
V_111 -> V_132 = V_4 -> V_191 ;
V_111 -> V_245 = V_4 -> V_191 ;
V_111 -> V_134 = 0 ;
V_111 -> V_133 = V_190 -> V_281 ;
V_111 -> V_54 = V_26 ;
V_111 -> V_63 = V_304 ;
V_111 -> F_124 = 0 ;
V_111 -> V_10 = NULL ;
V_111 -> V_20 = NULL ;
if ( V_273 . type == V_339 ) {
V_111 -> V_2 . V_314 = F_170 ;
V_111 -> V_2 . error = - V_201 ;
V_111 -> V_55 &= ~ V_125 ;
}
V_188 = F_12 ( V_26 , V_27 , V_275 . V_279 , F_14 ( V_32 ) ) ;
V_111 = F_120 ( V_188 , V_111 , V_190 , V_275 . V_279 ) ;
V_201 = 0 ;
if ( F_117 ( V_111 ) )
V_201 = F_118 ( V_111 ) ;
goto V_121;
V_334:
F_110 ( V_74 ) ;
V_304 = F_192 ( V_4 , 0 , V_282 ) ;
V_273 . type = V_339 ;
if ( V_201 == - V_340 )
V_201 = - V_251 ;
goto V_338;
V_331:
F_110 ( V_76 ) ;
#ifdef F_155
if ( F_156 ( V_229 ) && F_106 () )
F_107 ( L_30 ,
& V_26 , & V_27 , V_4 -> V_53 ) ;
#endif
V_333:
V_201 = - V_249 ;
goto V_121;
V_307:
V_201 = - V_248 ;
goto V_121;
V_311:
V_201 = - V_204 ;
goto V_121;
V_329:
V_201 = - V_248 ;
V_337:
F_214 ( V_4 , V_229 , V_190 , V_26 , V_27 ) ;
goto V_121;
}
int F_228 ( struct V_189 * V_190 , T_3 V_26 , T_3 V_27 ,
T_9 V_277 , struct V_3 * V_4 , bool V_341 )
{
struct V_7 * V_111 ;
unsigned V_188 ;
int V_342 = V_4 -> V_191 ;
struct V_32 * V_32 ;
int V_273 ;
V_32 = F_20 ( V_4 ) ;
F_31 () ;
if ( ! F_73 ( V_32 ) )
goto V_343;
V_277 &= V_344 ;
V_188 = F_12 ( V_26 , V_27 , V_342 , F_14 ( V_32 ) ) ;
for ( V_111 = F_153 ( V_41 [ V_188 ] . V_42 ) ; V_111 ;
V_111 = F_153 ( V_111 -> V_2 . V_43 ) ) {
if ( ( ( ( V_30 T_1 ) V_111 -> V_130 ^ ( V_30 T_1 ) V_26 ) |
( ( V_30 T_1 ) V_111 -> V_131 ^ ( V_30 T_1 ) V_27 ) |
( V_111 -> V_132 ^ V_342 ) |
( V_111 -> V_62 ^ V_277 ) ) == 0 &&
V_111 -> V_133 == V_190 -> V_281 &&
F_77 ( F_20 ( V_111 -> V_2 . V_4 ) , V_32 ) &&
! F_78 ( V_111 ) ) {
F_182 ( V_111 ) ;
if ( V_341 ) {
F_229 ( & V_111 -> V_2 , V_122 ) ;
F_230 ( V_190 , & V_111 -> V_2 ) ;
} else {
F_122 ( & V_111 -> V_2 , V_122 ) ;
F_123 ( V_190 , & V_111 -> V_2 ) ;
}
F_110 ( V_71 ) ;
F_33 () ;
return 0 ;
}
F_110 ( V_85 ) ;
}
V_343:
if ( F_145 ( V_26 ) ) {
struct V_228 * V_229 = F_143 ( V_4 ) ;
if ( V_229 ) {
int V_303 = F_231 ( V_229 , V_26 , V_27 ,
F_169 ( V_190 ) -> V_305 ) ;
if ( V_303
#ifdef F_212
||
( ! F_209 ( V_26 ) &&
F_213 ( V_229 ) )
#endif
) {
int V_273 = F_207 ( V_190 , V_26 , V_27 ,
V_277 , V_4 , V_303 ) ;
F_33 () ;
return V_273 ;
}
}
F_33 () ;
return - V_248 ;
}
V_273 = F_226 ( V_190 , V_26 , V_27 , V_277 , V_4 ) ;
F_33 () ;
return V_273 ;
}
static struct V_7 * F_232 ( const struct V_272 * V_273 ,
const struct V_274 * V_275 ,
T_3 V_345 , T_3 V_346 ,
int V_347 , T_11 V_348 ,
struct V_3 * V_349 ,
unsigned int V_184 )
{
struct V_288 * V_20 = V_273 -> V_20 ;
struct V_228 * V_229 ;
T_10 type = V_273 -> type ;
struct V_7 * V_111 ;
if ( F_208 ( V_275 -> V_27 ) && ! ( V_349 -> V_184 & V_185 ) )
return F_121 ( - V_248 ) ;
if ( F_146 ( V_275 -> V_26 ) )
type = V_335 ;
else if ( F_145 ( V_275 -> V_26 ) )
type = V_313 ;
else if ( F_147 ( V_275 -> V_26 ) )
return F_121 ( - V_248 ) ;
if ( V_349 -> V_184 & V_185 )
V_184 |= V_125 ;
V_229 = F_143 ( V_349 ) ;
if ( ! V_229 )
return F_121 ( - V_248 ) ;
if ( type == V_335 ) {
V_184 |= V_112 | V_125 ;
V_20 = NULL ;
} else if ( type == V_313 ) {
V_184 |= V_113 | V_125 ;
if ( ! F_231 ( V_229 , V_275 -> V_26 , V_275 -> V_27 ,
V_275 -> V_350 ) )
V_184 &= ~ V_125 ;
if ( V_20 && V_273 -> V_351 < 4 )
V_20 = NULL ;
}
V_111 = F_205 ( V_349 ,
F_211 ( V_229 , V_310 ) ,
F_211 ( V_229 , V_325 ) ) ;
if ( ! V_111 )
return F_121 ( - V_204 ) ;
V_111 -> V_2 . V_312 = V_327 ;
V_111 -> V_130 = V_345 ;
V_111 -> V_131 = V_346 ;
V_111 -> F_14 = F_14 ( F_20 ( V_349 ) ) ;
V_111 -> V_55 = V_184 ;
V_111 -> V_199 = type ;
V_111 -> V_62 = V_348 ;
V_111 -> V_12 = V_275 -> V_26 ;
V_111 -> V_58 = V_275 -> V_27 ;
V_111 -> V_132 = 0 ;
V_111 -> V_245 = V_347 ? : V_349 -> V_191 ;
V_111 -> V_134 = V_347 ;
V_111 -> V_133 = V_275 -> V_280 ;
V_111 -> V_54 = V_275 -> V_26 ;
V_111 -> V_63 = V_275 -> V_27 ;
V_111 -> F_124 = 0 ;
V_111 -> V_10 = NULL ;
V_111 -> V_20 = NULL ;
F_110 ( V_79 ) ;
if ( V_184 & V_125 ) {
V_111 -> V_2 . V_314 = V_315 ;
V_111 -> V_63 = V_275 -> V_26 ;
}
if ( V_184 & ( V_112 | V_113 ) ) {
V_111 -> V_63 = V_275 -> V_27 ;
if ( V_184 & V_125 &&
! ( V_349 -> V_184 & V_185 ) ) {
V_111 -> V_2 . V_312 = V_352 ;
F_110 ( V_80 ) ;
}
#ifdef F_212
if ( type == V_313 ) {
if ( F_213 ( V_229 ) &&
! F_209 ( V_275 -> V_26 ) ) {
V_111 -> V_2 . V_314 = V_316 ;
V_111 -> V_2 . V_312 = V_352 ;
}
}
#endif
}
F_200 ( V_111 , V_275 , V_273 , V_20 , type , 0 ) ;
return V_111 ;
}
static struct V_7 * F_233 ( struct V_32 * V_32 , struct V_274 * V_275 )
{
struct V_3 * V_349 = NULL ;
T_11 V_277 = F_234 ( V_275 ) ;
unsigned int V_184 = 0 ;
struct V_272 V_273 ;
struct V_7 * V_111 ;
T_3 V_345 ;
T_3 V_346 ;
int V_347 ;
V_273 . V_20 = NULL ;
#ifdef F_203
V_273 . V_39 = NULL ;
#endif
V_345 = V_275 -> V_26 ;
V_346 = V_275 -> V_27 ;
V_347 = V_275 -> V_278 ;
V_275 -> V_279 = V_32 -> V_309 -> V_191 ;
V_275 -> V_276 = V_277 & V_344 ;
V_275 -> V_332 = ( ( V_277 & V_353 ) ?
V_296 : V_282 ) ;
F_31 () ;
if ( V_275 -> V_27 ) {
V_111 = F_121 ( - V_248 ) ;
if ( F_145 ( V_275 -> V_27 ) ||
F_146 ( V_275 -> V_27 ) ||
F_147 ( V_275 -> V_27 ) )
goto V_121;
if ( V_275 -> V_278 == 0 &&
( F_145 ( V_275 -> V_26 ) ||
F_146 ( V_275 -> V_26 ) ) ) {
V_349 = F_235 ( V_32 , V_275 -> V_27 , false ) ;
if ( V_349 == NULL )
goto V_121;
V_275 -> V_278 = V_349 -> V_191 ;
goto V_354;
}
if ( ! ( V_275 -> V_289 & V_355 ) ) {
if ( ! F_235 ( V_32 , V_275 -> V_27 , false ) )
goto V_121;
}
}
if ( V_275 -> V_278 ) {
V_349 = F_236 ( V_32 , V_275 -> V_278 ) ;
V_111 = F_121 ( - V_356 ) ;
if ( V_349 == NULL )
goto V_121;
if ( ! ( V_349 -> V_184 & V_357 ) || ! F_143 ( V_349 ) ) {
V_111 = F_121 ( - V_251 ) ;
goto V_121;
}
if ( F_209 ( V_275 -> V_26 ) ||
F_146 ( V_275 -> V_26 ) ) {
if ( ! V_275 -> V_27 )
V_275 -> V_27 = F_192 ( V_349 , 0 ,
V_296 ) ;
goto V_354;
}
if ( V_275 -> V_27 ) {
if ( F_145 ( V_275 -> V_26 ) )
V_275 -> V_27 = F_192 ( V_349 , 0 ,
V_275 -> V_332 ) ;
else if ( ! V_275 -> V_26 )
V_275 -> V_27 = F_192 ( V_349 , 0 ,
V_358 ) ;
}
}
if ( ! V_275 -> V_26 ) {
V_275 -> V_26 = V_275 -> V_27 ;
if ( ! V_275 -> V_26 )
V_275 -> V_26 = V_275 -> V_27 = F_237 ( V_359 ) ;
V_349 = V_32 -> V_309 ;
V_275 -> V_278 = V_32 -> V_309 -> V_191 ;
V_273 . type = V_336 ;
V_184 |= V_125 ;
goto V_354;
}
if ( F_190 ( V_32 , V_275 , & V_273 ) ) {
V_273 . V_20 = NULL ;
if ( V_275 -> V_278 ) {
if ( V_275 -> V_27 == 0 )
V_275 -> V_27 = F_192 ( V_349 , 0 ,
V_296 ) ;
V_273 . type = V_200 ;
goto V_354;
}
V_111 = F_121 ( - V_251 ) ;
goto V_121;
}
if ( V_273 . type == V_336 ) {
if ( ! V_275 -> V_27 ) {
if ( V_273 . V_20 -> V_360 )
V_275 -> V_27 = V_273 . V_20 -> V_360 ;
else
V_275 -> V_27 = V_275 -> V_26 ;
}
V_349 = V_32 -> V_309 ;
V_275 -> V_278 = V_349 -> V_191 ;
V_273 . V_20 = NULL ;
V_184 |= V_125 ;
goto V_354;
}
#ifdef F_224
if ( V_273 . V_20 -> V_328 > 1 && V_275 -> V_278 == 0 )
F_225 ( & V_273 ) ;
else
#endif
if ( ! V_273 . V_351 &&
V_273 . V_361 -> V_362 > 1 &&
V_273 . type == V_200 && ! V_275 -> V_278 )
F_238 ( & V_273 ) ;
if ( ! V_275 -> V_27 )
V_275 -> V_27 = F_191 ( V_32 , V_273 ) ;
V_349 = F_219 ( V_273 ) ;
V_275 -> V_278 = V_349 -> V_191 ;
V_354:
V_111 = F_232 ( & V_273 , V_275 , V_345 , V_346 , V_347 ,
V_277 , V_349 , V_184 ) ;
if ( ! F_117 ( V_111 ) ) {
unsigned int V_188 ;
V_188 = F_12 ( V_345 , V_346 , V_347 ,
F_14 ( F_20 ( V_349 ) ) ) ;
V_111 = F_120 ( V_188 , V_111 , NULL , V_347 ) ;
}
V_121:
F_33 () ;
return V_111 ;
}
struct V_7 * F_239 ( struct V_32 * V_32 , struct V_274 * V_363 )
{
struct V_7 * V_111 ;
unsigned int V_188 ;
if ( ! F_73 ( V_32 ) )
goto V_364;
V_188 = F_12 ( V_363 -> V_26 , V_363 -> V_27 , V_363 -> V_278 , F_14 ( V_32 ) ) ;
F_18 () ;
for ( V_111 = F_19 ( V_41 [ V_188 ] . V_42 ) ; V_111 ;
V_111 = F_19 ( V_111 -> V_2 . V_43 ) ) {
if ( V_111 -> V_130 == V_363 -> V_26 &&
V_111 -> V_131 == V_363 -> V_27 &&
F_72 ( V_111 ) &&
V_111 -> V_134 == V_363 -> V_278 &&
V_111 -> V_133 == V_363 -> V_280 &&
! ( ( V_111 -> V_62 ^ V_363 -> V_276 ) &
( V_344 | V_353 ) ) &&
F_77 ( F_20 ( V_111 -> V_2 . V_4 ) , V_32 ) &&
! F_78 ( V_111 ) ) {
F_182 ( V_111 ) ;
F_122 ( & V_111 -> V_2 , V_122 ) ;
F_110 ( V_78 ) ;
F_22 () ;
if ( ! V_363 -> V_27 )
V_363 -> V_27 = V_111 -> V_58 ;
if ( ! V_363 -> V_26 )
V_363 -> V_26 = V_111 -> V_12 ;
return V_111 ;
}
F_110 ( V_86 ) ;
}
F_22 () ;
V_364:
return F_233 ( V_32 , V_363 ) ;
}
static struct V_1 * F_240 ( struct V_1 * V_2 , T_1 V_270 )
{
return NULL ;
}
static unsigned int F_241 ( const struct V_1 * V_2 )
{
unsigned int V_264 = F_180 ( V_2 , V_235 ) ;
return V_264 ? : V_2 -> V_4 -> V_264 ;
}
static void F_242 ( struct V_1 * V_2 , T_1 V_264 )
{
}
static T_1 * F_243 ( struct V_1 * V_2 ,
unsigned long V_6 )
{
return NULL ;
}
struct V_1 * F_244 ( struct V_32 * V_32 , struct V_1 * V_365 )
{
struct V_7 * V_8 = F_206 ( & V_366 , NULL , 1 , 0 , 0 ) ;
struct V_7 * V_367 = (struct V_7 * ) V_365 ;
if ( V_8 ) {
struct V_1 * V_15 = & V_8 -> V_2 ;
V_15 -> V_57 = 1 ;
V_15 -> V_314 = V_368 ;
V_15 -> V_312 = V_368 ;
F_245 ( V_15 , & V_367 -> V_2 ) ;
V_15 -> V_4 = V_367 -> V_2 . V_4 ;
if ( V_15 -> V_4 )
F_246 ( V_15 -> V_4 ) ;
V_8 -> V_130 = V_367 -> V_130 ;
V_8 -> V_131 = V_367 -> V_131 ;
V_8 -> V_62 = V_367 -> V_62 ;
V_8 -> V_132 = V_367 -> V_132 ;
V_8 -> V_245 = V_367 -> V_245 ;
V_8 -> V_134 = V_367 -> V_134 ;
V_8 -> V_133 = V_367 -> V_133 ;
V_8 -> F_14 = F_14 ( V_32 ) ;
V_8 -> V_55 = V_367 -> V_55 ;
V_8 -> V_199 = V_367 -> V_199 ;
V_8 -> V_12 = V_367 -> V_12 ;
V_8 -> V_58 = V_367 -> V_58 ;
V_8 -> V_54 = V_367 -> V_54 ;
V_8 -> V_63 = V_367 -> V_63 ;
V_8 -> V_10 = V_367 -> V_10 ;
if ( V_8 -> V_10 )
F_154 ( & V_8 -> V_10 -> V_369 ) ;
V_8 -> V_20 = V_367 -> V_20 ;
if ( V_8 -> V_20 )
F_154 ( & V_8 -> V_20 -> V_293 ) ;
F_247 ( V_15 ) ;
}
F_248 ( V_365 ) ;
return V_8 ? & V_8 -> V_2 : F_121 ( - V_92 ) ;
}
struct V_7 * F_249 ( struct V_32 * V_32 , struct V_274 * V_363 ,
struct V_370 * V_371 )
{
struct V_7 * V_8 = F_239 ( V_32 , V_363 ) ;
if ( F_117 ( V_8 ) )
return V_8 ;
if ( V_363 -> V_350 )
V_8 = (struct V_7 * ) F_250 ( V_32 , & V_8 -> V_2 ,
F_251 ( V_363 ) ,
V_371 , 0 ) ;
return V_8 ;
}
static int F_252 ( struct V_32 * V_32 ,
struct V_189 * V_190 , T_1 V_372 , T_1 V_35 , int V_373 ,
int V_374 , unsigned int V_184 )
{
struct V_7 * V_8 = F_165 ( V_190 ) ;
struct V_375 * V_39 ;
struct V_376 * V_377 ;
unsigned long V_155 = 0 ;
const struct V_9 * V_10 = V_8 -> V_10 ;
T_1 V_214 = 0 , V_378 = 0 , V_379 = 0 , error ;
V_377 = F_253 ( V_190 , V_372 , V_35 , V_373 , sizeof( * V_39 ) , V_184 ) ;
if ( V_377 == NULL )
return - V_380 ;
V_39 = F_254 ( V_377 ) ;
V_39 -> V_381 = V_165 ;
V_39 -> V_382 = 32 ;
V_39 -> V_383 = 0 ;
V_39 -> V_384 = V_8 -> V_62 ;
V_39 -> V_385 = V_386 ;
F_255 ( V_190 , V_387 , V_386 ) ;
V_39 -> V_388 = V_8 -> V_199 ;
V_39 -> V_389 = V_282 ;
V_39 -> V_390 = V_391 ;
V_39 -> V_392 = ( V_8 -> V_55 & ~ 0xFFFF ) | V_393 ;
if ( V_8 -> V_55 & V_115 )
V_39 -> V_392 |= V_394 ;
F_256 ( V_190 , V_395 , V_8 -> V_12 ) ;
if ( V_8 -> V_131 ) {
V_39 -> V_383 = 32 ;
F_256 ( V_190 , V_396 , V_8 -> V_131 ) ;
}
if ( V_8 -> V_2 . V_4 )
F_255 ( V_190 , V_397 , V_8 -> V_2 . V_4 -> V_191 ) ;
#ifdef F_58
if ( V_8 -> V_2 . V_284 )
F_255 ( V_190 , V_398 , V_8 -> V_2 . V_284 ) ;
#endif
if ( F_68 ( V_8 ) )
F_256 ( V_190 , V_399 , V_8 -> V_63 ) ;
else if ( V_8 -> V_58 != V_8 -> V_131 )
F_256 ( V_190 , V_399 , V_8 -> V_58 ) ;
if ( V_8 -> V_12 != V_8 -> V_54 )
F_256 ( V_190 , V_400 , V_8 -> V_54 ) ;
if ( F_257 ( V_190 , F_258 ( & V_8 -> V_2 ) ) < 0 )
goto V_401;
if ( V_8 -> V_133 )
F_256 ( V_190 , V_402 , V_8 -> V_133 ) ;
error = V_8 -> V_2 . error ;
if ( V_10 ) {
F_259 ( V_8 -> V_10 ) ;
V_214 = F_15 ( & V_10 -> V_403 ) & 0xffff ;
if ( V_10 -> V_404 ) {
V_378 = V_10 -> V_405 ;
V_379 = F_260 () - V_10 -> V_404 ;
}
V_155 = F_159 ( V_10 -> V_116 ) ;
if ( V_155 ) {
if ( F_178 ( V_122 , V_155 ) )
V_155 -= V_122 ;
else
V_155 = 0 ;
}
}
if ( F_68 ( V_8 ) ) {
#ifdef F_212
T_3 V_2 = V_8 -> V_12 ;
if ( F_145 ( V_2 ) && ! F_209 ( V_2 ) &&
F_261 ( V_32 , V_406 ) ) {
int V_201 = F_262 ( V_32 , V_190 ,
V_8 -> V_58 , V_8 -> V_12 ,
V_39 , V_374 ) ;
if ( V_201 <= 0 ) {
if ( ! V_374 ) {
if ( V_201 == 0 )
return 0 ;
goto V_401;
} else {
if ( V_201 == - V_380 )
goto V_401;
error = V_201 ;
}
}
} else
#endif
F_255 ( V_190 , V_407 , V_8 -> V_245 ) ;
}
if ( F_263 ( V_190 , & V_8 -> V_2 , V_214 , V_378 , V_379 ,
V_155 , error ) < 0 )
goto V_401;
return F_264 ( V_190 , V_377 ) ;
V_401:
F_265 ( V_190 , V_377 ) ;
return - V_380 ;
}
static int F_266 ( struct V_189 * V_408 , struct V_376 * V_377 , void * V_409 )
{
struct V_32 * V_32 = F_267 ( V_408 -> V_371 ) ;
struct V_375 * V_410 ;
struct V_411 * V_412 [ V_413 + 1 ] ;
struct V_7 * V_8 = NULL ;
T_3 V_2 = 0 ;
T_3 V_90 = 0 ;
T_1 V_342 ;
int V_201 ;
int V_281 ;
struct V_189 * V_190 ;
V_201 = F_268 ( V_377 , sizeof( * V_410 ) , V_412 , V_413 , V_414 ) ;
if ( V_201 < 0 )
goto V_415;
V_410 = F_254 ( V_377 ) ;
V_190 = F_269 ( V_416 , V_25 ) ;
if ( V_190 == NULL ) {
V_201 = - V_204 ;
goto V_415;
}
F_270 ( V_190 ) ;
F_271 ( V_190 ) ;
F_169 ( V_190 ) -> V_305 = V_417 ;
F_272 ( V_190 , V_418 + sizeof( struct V_209 ) ) ;
V_90 = V_412 [ V_396 ] ? F_273 ( V_412 [ V_396 ] ) : 0 ;
V_2 = V_412 [ V_395 ] ? F_273 ( V_412 [ V_395 ] ) : 0 ;
V_342 = V_412 [ V_407 ] ? F_274 ( V_412 [ V_407 ] ) : 0 ;
V_281 = V_412 [ V_402 ] ? F_274 ( V_412 [ V_402 ] ) : 0 ;
if ( V_342 ) {
struct V_3 * V_4 ;
V_4 = F_275 ( V_32 , V_342 ) ;
if ( V_4 == NULL ) {
V_201 = - V_356 ;
goto V_419;
}
V_190 -> V_305 = F_130 ( V_306 ) ;
V_190 -> V_4 = V_4 ;
V_190 -> V_281 = V_281 ;
F_276 () ;
V_201 = F_277 ( V_190 , V_2 , V_90 , V_410 -> V_384 , V_4 ) ;
F_278 () ;
V_8 = F_165 ( V_190 ) ;
if ( V_201 == 0 && V_8 -> V_2 . error )
V_201 = - V_8 -> V_2 . error ;
} else {
struct V_274 V_275 = {
. V_26 = V_2 ,
. V_27 = V_90 ,
. V_276 = V_410 -> V_384 ,
. V_278 = V_412 [ V_397 ] ? F_274 ( V_412 [ V_397 ] ) : 0 ,
. V_280 = V_281 ,
} ;
V_8 = F_279 ( V_32 , & V_275 ) ;
V_201 = 0 ;
if ( F_117 ( V_8 ) )
V_201 = F_118 ( V_8 ) ;
}
if ( V_201 )
goto V_419;
F_123 ( V_190 , & V_8 -> V_2 ) ;
if ( V_410 -> V_392 & V_394 )
V_8 -> V_55 |= V_115 ;
V_201 = F_252 ( V_32 , V_190 , F_280 ( V_408 ) . V_372 , V_377 -> V_420 ,
V_421 , 0 , 0 ) ;
if ( V_201 <= 0 )
goto V_419;
V_201 = F_281 ( V_190 , V_32 , F_280 ( V_408 ) . V_372 ) ;
V_415:
return V_201 ;
V_419:
F_172 ( V_190 ) ;
goto V_415;
}
int F_282 ( struct V_189 * V_190 , struct V_422 * V_423 )
{
struct V_7 * V_8 ;
int V_424 , V_425 ;
int V_28 , V_426 ;
struct V_32 * V_32 ;
V_32 = F_267 ( V_190 -> V_371 ) ;
V_425 = V_423 -> args [ 0 ] ;
if ( V_425 < 0 )
V_425 = 0 ;
V_426 = V_28 = V_423 -> args [ 1 ] ;
for ( V_424 = V_425 ; V_424 <= V_31 ; V_424 ++ , V_426 = 0 ) {
if ( ! V_41 [ V_424 ] . V_42 )
continue;
F_18 () ;
for ( V_8 = F_19 ( V_41 [ V_424 ] . V_42 ) , V_28 = 0 ; V_8 ;
V_8 = F_19 ( V_8 -> V_2 . V_43 ) , V_28 ++ ) {
if ( ! F_77 ( F_20 ( V_8 -> V_2 . V_4 ) , V_32 ) || V_28 < V_426 )
continue;
if ( F_78 ( V_8 ) )
continue;
F_230 ( V_190 , & V_8 -> V_2 ) ;
if ( F_252 ( V_32 , V_190 , F_280 ( V_423 -> V_190 ) . V_372 ,
V_423 -> V_377 -> V_420 , V_421 ,
1 , V_427 ) <= 0 ) {
F_283 ( V_190 ) ;
F_22 () ;
goto V_428;
}
F_283 ( V_190 ) ;
}
F_22 () ;
}
V_428:
V_423 -> args [ 0 ] = V_424 ;
V_423 -> args [ 1 ] = V_28 ;
return V_190 -> V_49 ;
}
void F_284 ( struct V_228 * V_229 )
{
F_102 ( F_20 ( V_229 -> V_4 ) , 0 ) ;
}
static int F_285 ( T_12 * V_429 , int V_430 ,
void T_13 * V_431 ,
T_14 * V_432 , T_4 * V_433 )
{
if ( V_430 ) {
int V_434 ;
T_12 V_435 ;
struct V_32 * V_32 ;
memcpy ( & V_435 , V_429 , sizeof( V_435 ) ) ;
V_435 . V_436 = & V_434 ;
F_286 ( & V_435 , V_430 , V_431 , V_432 , V_433 ) ;
V_32 = (struct V_32 * ) V_429 -> V_437 ;
F_102 ( V_32 , V_434 ) ;
return 0 ;
}
return - V_248 ;
}
static T_5 int F_287 ( struct V_32 * V_32 )
{
struct T_12 * V_438 ;
V_438 = V_439 ;
if ( ! F_77 ( V_32 , & V_440 ) ) {
V_438 = F_288 ( V_438 , sizeof( V_439 ) , V_25 ) ;
if ( V_438 == NULL )
goto V_441;
}
V_438 [ 0 ] . V_437 = V_32 ;
V_32 -> V_33 . V_442 =
F_289 ( V_32 , V_443 , V_438 ) ;
if ( V_32 -> V_33 . V_442 == NULL )
goto V_444;
return 0 ;
V_444:
if ( V_438 != V_439 )
F_52 ( V_438 ) ;
V_441:
return - V_92 ;
}
static T_6 void F_290 ( struct V_32 * V_32 )
{
struct T_12 * V_438 ;
V_438 = V_32 -> V_33 . V_442 -> V_445 ;
F_291 ( V_32 -> V_33 . V_442 ) ;
F_292 ( V_438 == V_439 ) ;
F_52 ( V_438 ) ;
}
static T_5 int F_293 ( struct V_32 * V_32 )
{
F_99 ( & V_32 -> V_33 . F_14 ,
sizeof( V_32 -> V_33 . F_14 ) ) ;
F_99 ( & V_32 -> V_33 . V_446 ,
sizeof( V_32 -> V_33 . V_446 ) ) ;
return 0 ;
}
static int T_2 F_294 ( char * V_447 )
{
if ( ! V_447 )
return 0 ;
V_448 = F_295 ( V_447 , & V_447 , 0 ) ;
return 1 ;
}
int T_2 F_296 ( void )
{
int V_449 = 0 ;
#ifdef F_58
V_89 = F_297 ( 256 * sizeof( struct V_89 ) , F_298 ( struct V_89 ) ) ;
if ( ! V_89 )
F_10 ( L_31 ) ;
#endif
V_70 . V_450 =
F_299 ( L_32 , sizeof( struct V_7 ) , 0 ,
V_451 | V_452 , NULL ) ;
V_366 . V_450 = V_70 . V_450 ;
if ( F_300 ( & V_70 ) < 0 )
F_10 ( L_33 ) ;
if ( F_300 ( & V_366 ) < 0 )
F_10 ( L_34 ) ;
V_41 = (struct V_453 * )
F_301 ( L_35 ,
sizeof( struct V_453 ) ,
V_448 ,
( V_454 >= 128 * 1024 ) ?
15 : 17 ,
0 ,
& V_151 ,
& V_31 ,
V_448 ? 0 : 512 * 1024 ) ;
memset ( V_41 , 0 , ( V_31 + 1 ) * sizeof( struct V_453 ) ) ;
F_8 () ;
V_70 . V_178 = ( V_31 + 1 ) ;
V_176 = ( V_31 + 1 ) * 16 ;
F_302 () ;
F_303 () ;
F_304 ( & V_162 , F_96 ) ;
V_150 = V_122 ;
F_97 ( & V_162 ,
F_305 () % V_163 + V_163 ) ;
if ( F_61 () )
F_306 ( L_36 ) ;
#ifdef F_307
F_308 () ;
F_309 ( V_176 ) ;
#endif
F_310 ( V_455 , V_456 , F_266 , NULL , NULL ) ;
#ifdef F_311
F_62 ( & V_457 ) ;
#endif
F_62 ( & V_458 ) ;
return V_449 ;
}
void T_2 F_312 ( void )
{
F_313 ( V_459 , V_460 ) ;
}
