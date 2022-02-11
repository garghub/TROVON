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
F_107 ( V_167 L_16 ) ;
F_98 ( V_32 ) ;
}
static int F_108 ( struct V_168 * V_169 )
{
static unsigned long V_170 = V_171 ;
static unsigned long V_172 ;
static int V_142 ;
static int V_173 ;
struct V_7 * V_111 ;
struct V_7 T_7 * * V_144 ;
unsigned long V_174 = V_122 ;
int V_143 ;
int V_175 = F_109 ( & V_70 ) ;
F_110 ( V_81 ) ;
if ( V_174 - V_172 < V_176 &&
V_175 < V_177 ) {
F_110 ( V_82 ) ;
goto V_121;
}
V_175 = F_44 ( & V_70 ) ;
V_143 = V_175 - ( V_178 << V_151 ) ;
if ( V_143 <= 0 ) {
if ( V_173 < V_70 . V_179 )
V_173 = V_70 . V_179 ;
V_143 = V_175 - V_173 ;
if ( V_143 > 0 ) {
V_173 += F_111 (unsigned int, goal >> 1 , rt_hash_mask + 1 ) ;
V_143 = V_175 - V_173 ;
}
} else {
V_143 = F_95 (unsigned int, goal >> 1 , rt_hash_mask + 1 ) ;
V_173 = V_175 - V_143 ;
}
if ( V_174 - V_172 >= V_176 )
V_172 = V_174 ;
if ( V_143 <= 0 ) {
V_173 += V_143 ;
goto V_180;
}
do {
int V_21 , V_181 ;
for ( V_21 = V_31 , V_181 = V_142 ; V_21 >= 0 ; V_21 -- ) {
unsigned long V_153 = V_170 ;
V_181 = ( V_181 + 1 ) & V_31 ;
V_144 = & V_41 [ V_181 ] . V_42 ;
F_82 ( F_83 ( V_181 ) ) ;
while ( ( V_111 = F_84 ( * V_144 ,
F_85 ( F_83 ( V_181 ) ) ) ) != NULL ) {
if ( ! F_78 ( V_111 ) &&
! F_70 ( V_111 , V_153 , V_170 ) ) {
V_153 >>= 1 ;
V_144 = & V_111 -> V_2 . V_43 ;
continue;
}
* V_144 = V_111 -> V_2 . V_43 ;
F_63 ( V_111 ) ;
V_143 -- ;
}
F_87 ( F_83 ( V_181 ) ) ;
if ( V_143 <= 0 )
break;
}
V_142 = V_181 ;
if ( V_143 <= 0 )
goto V_180;
F_110 ( V_83 ) ;
if ( V_170 == 0 )
break;
V_170 >>= 1 ;
if ( F_109 ( & V_70 ) < V_177 )
goto V_121;
} while ( ! F_103 () && F_93 ( V_122 , V_174 ) );
if ( F_109 ( & V_70 ) < V_177 )
goto V_121;
if ( F_44 ( & V_70 ) < V_177 )
goto V_121;
if ( F_106 () )
F_107 ( V_167 L_17 ) ;
F_110 ( V_84 ) ;
return 1 ;
V_180:
V_170 += V_176 ;
if ( V_170 > V_152 ||
F_109 ( & V_70 ) < V_70 . V_179 ||
F_44 ( & V_70 ) < V_70 . V_179 )
V_170 = V_152 ;
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
return V_154 >> V_182 ;
}
static struct V_47 * F_113 ( const struct V_1 * V_2 , const void * V_26 )
{
static const T_3 V_183 = 0 ;
struct V_3 * V_4 = V_2 -> V_4 ;
const T_3 * V_184 = V_26 ;
struct V_47 * V_48 ;
if ( V_4 -> V_185 & ( V_186 | V_187 ) )
V_184 = & V_183 ;
V_48 = F_114 ( & V_188 , V_4 , * ( V_30 T_1 * ) V_184 ) ;
if ( V_48 )
return V_48 ;
return F_115 ( & V_188 , V_184 , V_4 ) ;
}
static int F_116 ( struct V_7 * V_8 )
{
struct V_47 * V_48 = F_113 ( & V_8 -> V_2 , & V_8 -> V_54 ) ;
if ( F_117 ( V_48 ) )
return F_118 ( V_48 ) ;
F_119 ( & V_8 -> V_2 , V_48 ) ;
return 0 ;
}
static struct V_7 * F_120 ( unsigned V_189 , struct V_7 * V_8 ,
struct V_190 * V_191 , int V_192 )
{
struct V_7 * V_111 , * V_193 ;
struct V_7 T_7 * * V_144 , * * V_194 ;
unsigned long V_174 ;
T_1 V_195 ;
int V_196 ;
int V_197 = ! F_103 () ;
V_198:
V_196 = 0 ;
V_195 = ~ ( T_1 ) 0 ;
V_193 = NULL ;
V_194 = NULL ;
V_174 = V_122 ;
if ( ! F_73 ( F_20 ( V_8 -> V_2 . V_4 ) ) ) {
V_8 -> V_2 . V_185 |= V_199 ;
if ( V_8 -> V_200 == V_201 || F_72 ( V_8 ) ) {
int V_202 = F_116 ( V_8 ) ;
if ( V_202 ) {
if ( F_106 () )
F_107 ( V_167
L_18 ) ;
F_66 ( V_8 ) ;
return F_121 ( V_202 ) ;
}
}
goto V_203;
}
V_144 = & V_41 [ V_189 ] . V_42 ;
F_82 ( F_83 ( V_189 ) ) ;
while ( ( V_111 = F_84 ( * V_144 ,
F_85 ( F_83 ( V_189 ) ) ) ) != NULL ) {
if ( F_78 ( V_111 ) ) {
* V_144 = V_111 -> V_2 . V_43 ;
F_63 ( V_111 ) ;
continue;
}
if ( F_75 ( V_111 , V_8 ) && F_76 ( V_111 , V_8 ) ) {
* V_144 = V_111 -> V_2 . V_43 ;
F_86 ( V_111 -> V_2 . V_43 ,
V_41 [ V_189 ] . V_42 ) ;
F_86 ( V_41 [ V_189 ] . V_42 , V_111 ) ;
F_122 ( & V_111 -> V_2 , V_174 ) ;
F_87 ( F_83 ( V_189 ) ) ;
F_65 ( V_8 ) ;
if ( V_191 )
F_123 ( V_191 , & V_111 -> V_2 ) ;
return V_111 ;
}
if ( ! F_15 ( & V_111 -> V_2 . V_56 ) ) {
T_1 V_124 = F_71 ( V_111 ) ;
if ( V_124 <= V_195 ) {
V_193 = V_111 ;
V_194 = V_144 ;
V_195 = V_124 ;
}
}
V_196 ++ ;
V_144 = & V_111 -> V_2 . V_43 ;
}
if ( V_193 ) {
if ( V_196 > V_178 ) {
* V_194 = V_193 -> V_2 . V_43 ;
F_63 ( V_193 ) ;
}
} else {
if ( V_196 > V_159 &&
F_112 ( V_41 [ V_189 ] . V_42 ) > V_159 ) {
struct V_32 * V_32 = F_20 ( V_8 -> V_2 . V_4 ) ;
int V_204 = ++ V_32 -> V_33 . V_126 ;
if ( ! F_73 ( V_32 ) ) {
F_107 ( V_167 L_19 ,
V_8 -> V_2 . V_4 -> V_53 , V_204 ) ;
}
F_105 ( V_32 ) ;
F_87 ( F_83 ( V_189 ) ) ;
V_189 = F_12 ( V_8 -> V_130 , V_8 -> V_131 ,
V_192 , F_14 ( V_32 ) ) ;
goto V_198;
}
}
if ( V_8 -> V_200 == V_201 || F_72 ( V_8 ) ) {
int V_202 = F_116 ( V_8 ) ;
if ( V_202 ) {
F_87 ( F_83 ( V_189 ) ) ;
if ( V_202 != - V_205 ) {
F_65 ( V_8 ) ;
return F_121 ( V_202 ) ;
}
if ( V_197 -- > 0 ) {
int V_206 = V_178 ;
int V_207 = V_176 ;
V_178 = 1 ;
V_176 = 0 ;
F_108 ( & V_70 ) ;
V_176 = V_207 ;
V_178 = V_206 ;
goto V_198;
}
if ( F_106 () )
F_107 ( V_167 L_20 ) ;
F_65 ( V_8 ) ;
return F_121 ( - V_205 ) ;
}
}
V_8 -> V_2 . V_43 = V_41 [ V_189 ] . V_42 ;
F_86 ( V_41 [ V_189 ] . V_42 , V_8 ) ;
F_87 ( F_83 ( V_189 ) ) ;
V_203:
if ( V_191 )
F_123 ( V_191 , & V_8 -> V_2 ) ;
return V_8 ;
}
static T_1 F_124 ( void )
{
return F_15 ( & V_208 ) ;
}
void F_3 ( struct V_7 * V_8 , T_3 V_26 , int V_209 )
{
struct V_9 * V_10 ;
V_10 = F_125 ( V_26 , V_209 ) ;
if ( V_10 && F_6 ( & V_8 -> V_10 , NULL , V_10 ) != NULL )
F_126 ( V_10 ) ;
else
V_8 -> F_124 = F_124 () ;
}
static void F_127 ( struct V_210 * V_211 )
{
static F_128 ( V_212 ) ;
static T_1 V_213 ;
T_1 V_214 ;
F_82 ( & V_212 ) ;
V_214 = F_129 ( ( V_30 T_3 ) V_213 ^ V_211 -> V_26 ) ;
V_211 -> V_215 = F_130 ( V_214 & 0xFFFF ) ;
V_213 = V_214 ;
F_87 ( & V_212 ) ;
}
void F_131 ( struct V_210 * V_211 , struct V_1 * V_2 , int V_216 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
if ( V_8 && ! ( V_8 -> V_2 . V_185 & V_217 ) ) {
if ( V_8 -> V_10 == NULL )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
if ( V_8 -> V_10 ) {
V_211 -> V_215 = F_130 ( F_132 ( V_8 -> V_10 , V_216 ) ) ;
return;
}
} else if ( ! V_8 )
F_107 ( V_218 L_21 ,
F_133 ( 0 ) ) ;
F_127 ( V_211 ) ;
}
static void F_134 ( unsigned V_189 , struct V_7 * V_8 )
{
struct V_7 T_7 * * V_144 ;
struct V_7 * V_140 ;
V_144 = & V_41 [ V_189 ] . V_42 ;
F_82 ( F_83 ( V_189 ) ) ;
F_66 ( V_8 ) ;
while ( ( V_140 = F_84 ( * V_144 ,
F_85 ( F_83 ( V_189 ) ) ) ) != NULL ) {
if ( V_140 == V_8 || F_78 ( V_140 ) ) {
* V_144 = V_140 -> V_2 . V_43 ;
F_63 ( V_140 ) ;
continue;
}
V_144 = & V_140 -> V_2 . V_43 ;
}
F_87 ( F_83 ( V_189 ) ) ;
}
static void F_135 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
T_3 V_219 = V_8 -> V_54 ;
struct V_47 * V_48 , * V_220 ;
F_136 ( & V_8 -> V_2 ) ;
V_8 -> V_54 = V_10 -> V_221 . V_222 ;
V_48 = F_113 ( & V_8 -> V_2 , & V_8 -> V_54 ) ;
if ( F_117 ( V_48 ) ) {
V_8 -> V_54 = V_219 ;
return;
}
V_220 = F_137 ( & V_8 -> V_2 . V_223 , V_48 ) ;
if ( V_220 )
F_138 ( V_220 ) ;
if ( ! ( V_48 -> V_51 & V_224 ) ) {
F_139 ( V_48 , NULL ) ;
} else {
V_8 -> V_55 |= V_114 ;
F_140 ( V_225 , V_48 ) ;
}
}
void F_141 ( T_3 V_226 , T_3 V_26 , T_3 V_227 ,
T_3 V_27 , struct V_3 * V_4 )
{
int V_228 , V_21 ;
struct V_229 * V_230 = F_142 ( V_4 ) ;
T_3 V_231 [ 2 ] = { V_27 , 0 } ;
int V_232 [ 2 ] = { V_4 -> V_192 , 0 } ;
struct V_9 * V_10 ;
struct V_32 * V_32 ;
if ( ! V_230 )
return;
V_32 = F_20 ( V_4 ) ;
if ( V_227 == V_226 || ! F_143 ( V_230 ) ||
F_144 ( V_227 ) || F_145 ( V_227 ) ||
F_146 ( V_227 ) )
goto V_233;
if ( ! F_147 ( V_230 ) ) {
if ( ! F_148 ( V_230 , V_227 , V_226 ) )
goto V_233;
if ( F_149 ( V_230 ) && F_150 ( V_227 , V_4 ) )
goto V_233;
} else {
if ( F_151 ( V_32 , V_227 ) != V_201 )
goto V_233;
}
for ( V_228 = 0 ; V_228 < 2 ; V_228 ++ ) {
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
unsigned int V_189 ;
struct V_7 T_7 * * V_144 ;
struct V_7 * V_8 ;
V_189 = F_12 ( V_26 , V_231 [ V_228 ] , V_232 [ V_21 ] , F_14 ( V_32 ) ) ;
V_144 = & V_41 [ V_189 ] . V_42 ;
while ( ( V_8 = F_152 ( * V_144 ) ) != NULL ) {
V_144 = & V_8 -> V_2 . V_43 ;
if ( V_8 -> V_130 != V_26 ||
V_8 -> V_131 != V_231 [ V_228 ] ||
V_8 -> V_134 != V_232 [ V_21 ] ||
F_68 ( V_8 ) ||
F_78 ( V_8 ) ||
! F_77 ( F_20 ( V_8 -> V_2 . V_4 ) , V_32 ) ||
V_8 -> V_2 . error ||
V_8 -> V_2 . V_4 != V_4 ||
V_8 -> V_54 != V_226 )
continue;
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
V_10 = V_8 -> V_10 ;
if ( V_10 ) {
if ( V_10 -> V_221 . V_222 != V_227 ) {
V_10 -> V_221 . V_222 = V_227 ;
F_153 ( & V_208 ) ;
}
F_135 ( & V_8 -> V_2 , V_10 ) ;
}
}
}
}
return;
V_233:
#ifdef F_154
if ( F_155 ( V_230 ) && F_106 () )
F_107 ( V_234 L_22
L_23 ,
& V_226 , V_4 -> V_53 , & V_227 ,
& V_27 , & V_26 ) ;
#endif
;
}
static bool F_156 ( struct V_9 * V_10 )
{
unsigned long V_235 = F_157 ( V_10 -> V_116 ) ;
return V_235 &&
F_158 ( V_122 , V_235 ) &&
F_6 ( & V_10 -> V_116 , V_235 , 0 ) == V_235 ;
}
static bool F_159 ( struct V_9 * V_10 )
{
unsigned long V_235 = F_157 ( V_10 -> V_116 ) ;
return V_235 &&
F_6 ( & V_10 -> V_116 , V_235 , 0 ) == V_235 ;
}
static struct V_1 * F_160 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
struct V_1 * V_120 = V_2 ;
if ( V_8 ) {
if ( V_2 -> V_236 > 0 ) {
F_66 ( V_8 ) ;
V_120 = NULL ;
} else if ( V_8 -> V_55 & V_114 ) {
unsigned V_189 = F_12 ( V_8 -> V_130 , V_8 -> V_131 ,
V_8 -> V_134 ,
F_14 ( F_20 ( V_2 -> V_4 ) ) ) ;
F_134 ( V_189 , V_8 ) ;
V_120 = NULL ;
} else if ( V_8 -> V_10 && F_156 ( V_8 -> V_10 ) ) {
F_161 ( V_2 , V_237 , V_8 -> V_10 -> V_238 ) ;
}
}
return V_120 ;
}
void F_162 ( struct V_190 * V_191 )
{
struct V_7 * V_8 = F_163 ( V_191 ) ;
struct V_229 * V_230 ;
struct V_9 * V_10 ;
int V_239 ;
F_31 () ;
V_230 = F_142 ( V_8 -> V_2 . V_4 ) ;
if ( ! V_230 || ! F_164 ( V_230 ) ) {
F_33 () ;
return;
}
V_239 = F_155 ( V_230 ) ;
F_33 () ;
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
V_10 = V_8 -> V_10 ;
if ( ! V_10 ) {
F_165 ( V_191 , V_240 , V_241 , V_8 -> V_54 ) ;
return;
}
if ( F_166 ( V_122 , V_10 -> V_242 + V_243 ) )
V_10 -> V_244 = 0 ;
if ( V_10 -> V_244 >= V_245 ) {
V_10 -> V_242 = V_122 ;
return;
}
if ( V_10 -> V_244 == 0 ||
F_166 ( V_122 ,
( V_10 -> V_242 +
( V_246 << V_10 -> V_244 ) ) ) ) {
F_165 ( V_191 , V_240 , V_241 , V_8 -> V_54 ) ;
V_10 -> V_242 = V_122 ;
++ V_10 -> V_244 ;
#ifdef F_154
if ( V_239 &&
V_10 -> V_244 == V_245 &&
F_106 () )
F_107 ( V_167 L_24 ,
& F_167 ( V_191 ) -> V_27 , V_8 -> V_247 ,
& V_8 -> V_12 , & V_8 -> V_54 ) ;
#endif
}
}
static int F_168 ( struct V_190 * V_191 )
{
struct V_7 * V_8 = F_163 ( V_191 ) ;
struct V_9 * V_10 ;
unsigned long V_174 ;
bool V_248 ;
int V_249 ;
switch ( V_8 -> V_2 . error ) {
case V_250 :
default:
goto V_121;
case V_251 :
V_249 = V_252 ;
break;
case V_253 :
V_249 = V_254 ;
F_169 ( F_20 ( V_8 -> V_2 . V_4 ) ,
V_255 ) ;
break;
case V_256 :
V_249 = V_257 ;
break;
}
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
V_10 = V_8 -> V_10 ;
V_248 = true ;
if ( V_10 ) {
V_174 = V_122 ;
V_10 -> V_244 += V_174 - V_10 -> V_242 ;
if ( V_10 -> V_244 > V_258 )
V_10 -> V_244 = V_258 ;
V_10 -> V_242 = V_174 ;
if ( V_10 -> V_244 >= V_259 )
V_10 -> V_244 -= V_259 ;
else
V_248 = false ;
}
if ( V_248 )
F_165 ( V_191 , V_260 , V_249 , 0 ) ;
V_121: F_170 ( V_191 ) ;
return 0 ;
}
static inline unsigned short F_171 ( unsigned short V_261 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < F_172 ( V_262 ) ; V_21 ++ )
if ( V_261 > V_262 [ V_21 ] )
return V_262 [ V_21 ] ;
return 68 ;
}
unsigned short F_173 ( struct V_32 * V_32 , const struct V_210 * V_211 ,
unsigned short V_263 ,
struct V_3 * V_4 )
{
unsigned short V_261 = F_174 ( V_211 -> V_264 ) ;
unsigned short V_265 = 0 ;
struct V_9 * V_10 ;
V_10 = F_125 ( V_211 -> V_26 , 1 ) ;
if ( V_10 ) {
unsigned short V_266 = V_263 ;
if ( V_263 < 68 || V_263 >= V_261 ) {
if ( V_266 == 0 &&
V_261 >= 68 + ( V_211 -> V_267 << 2 ) )
V_261 -= V_211 -> V_267 << 2 ;
V_266 = F_171 ( V_261 ) ;
}
if ( V_266 < V_268 )
V_266 = V_268 ;
if ( ! V_10 -> V_116 || V_266 < V_10 -> V_269 ) {
unsigned long V_116 ;
V_116 = V_122 + V_270 ;
if ( ! V_116 )
V_116 = 1UL ;
V_265 = V_266 ;
V_10 -> V_269 = V_266 ;
V_10 -> V_116 = V_116 ;
F_153 ( & V_208 ) ;
}
F_126 ( V_10 ) ;
}
return V_265 ? : V_263 ;
}
static void F_175 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned long V_155 = F_157 ( V_10 -> V_116 ) ;
if ( ! V_155 )
return;
if ( F_176 ( V_122 , V_155 ) ) {
T_1 V_271 = F_177 ( V_2 ) ;
if ( V_10 -> V_269 < V_271 ) {
if ( ! V_10 -> V_238 )
V_10 -> V_238 = F_178 ( V_2 , V_237 ) ;
F_161 ( V_2 , V_237 , V_10 -> V_269 ) ;
}
} else if ( F_6 ( & V_10 -> V_116 , V_155 , 0 ) == V_155 )
F_161 ( V_2 , V_237 , V_10 -> V_238 ) ;
}
static void F_179 ( struct V_1 * V_2 , T_1 V_266 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
struct V_9 * V_10 ;
F_136 ( V_2 ) ;
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
V_10 = V_8 -> V_10 ;
if ( V_10 ) {
unsigned long V_116 = F_157 ( V_10 -> V_116 ) ;
if ( V_266 < V_268 )
V_266 = V_268 ;
if ( ! V_116 || V_266 < V_10 -> V_269 ) {
V_116 = V_122 + V_270 ;
if ( ! V_116 )
V_116 = 1UL ;
V_10 -> V_269 = V_266 ;
V_10 -> V_116 = V_116 ;
F_153 ( & V_208 ) ;
V_8 -> F_124 = F_124 () ;
}
F_175 ( V_2 , V_10 ) ;
}
}
static void F_180 ( struct V_7 * V_8 )
{
if ( V_8 -> F_124 != F_124 () ) {
struct V_9 * V_10 ;
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 0 ) ;
V_10 = V_8 -> V_10 ;
if ( V_10 ) {
F_175 ( & V_8 -> V_2 , V_10 ) ;
if ( V_10 -> V_221 . V_222 &&
V_10 -> V_221 . V_222 != V_8 -> V_54 )
F_135 ( & V_8 -> V_2 , V_10 ) ;
}
V_8 -> F_124 = F_124 () ;
}
}
static struct V_1 * F_181 ( struct V_1 * V_2 , T_1 V_272 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
if ( F_78 ( V_8 ) )
return NULL ;
F_180 ( V_8 ) ;
return V_2 ;
}
static void F_182 ( struct V_1 * V_2 )
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
static void F_183 ( struct V_190 * V_191 )
{
struct V_7 * V_8 ;
F_165 ( V_191 , V_260 , V_252 , 0 ) ;
V_8 = F_163 ( V_191 ) ;
if ( V_8 && V_8 -> V_10 && F_159 ( V_8 -> V_10 ) )
F_161 ( & V_8 -> V_2 , V_237 , V_8 -> V_10 -> V_238 ) ;
}
static int F_184 ( struct V_190 * V_191 )
{
F_107 ( V_218 L_25 ,
& F_167 ( V_191 ) -> V_27 , & F_167 ( V_191 ) -> V_26 ,
V_191 -> V_4 ? V_191 -> V_4 -> V_53 : L_26 ) ;
F_170 ( V_191 ) ;
F_185 ( 1 ) ;
return 0 ;
}
void F_186 ( T_9 * V_273 , struct V_190 * V_191 , struct V_7 * V_8 )
{
T_3 V_90 ;
if ( F_72 ( V_8 ) )
V_90 = F_167 ( V_191 ) -> V_27 ;
else {
struct V_274 V_275 ;
struct V_276 V_277 ;
struct V_210 * V_211 ;
V_211 = F_167 ( V_191 ) ;
memset ( & V_277 , 0 , sizeof( V_277 ) ) ;
V_277 . V_26 = V_211 -> V_26 ;
V_277 . V_27 = V_211 -> V_27 ;
V_277 . V_278 = F_187 ( V_211 -> V_279 ) ;
V_277 . V_280 = V_8 -> V_2 . V_4 -> V_192 ;
V_277 . V_281 = V_191 -> V_4 -> V_192 ;
V_277 . V_282 = V_191 -> V_283 ;
F_31 () ;
if ( F_188 ( F_20 ( V_8 -> V_2 . V_4 ) , & V_277 , & V_275 ) == 0 )
V_90 = F_189 ( F_20 ( V_8 -> V_2 . V_4 ) , V_275 ) ;
else
V_90 = F_190 ( V_8 -> V_2 . V_4 , V_8 -> V_54 ,
V_284 ) ;
F_33 () ;
}
memcpy ( V_273 , & V_90 , 4 ) ;
}
static void F_191 ( struct V_7 * V_8 , T_1 V_285 )
{
if ( ! ( V_8 -> V_2 . V_286 & 0xFFFF ) )
V_8 -> V_2 . V_286 |= V_285 & 0xFFFF ;
if ( ! ( V_8 -> V_2 . V_286 & 0xFFFF0000 ) )
V_8 -> V_2 . V_286 |= V_285 & 0xFFFF0000 ;
}
static unsigned int F_192 ( const struct V_1 * V_2 )
{
unsigned int V_287 = F_178 ( V_2 , V_288 ) ;
if ( V_287 == 0 ) {
V_287 = F_95 (unsigned int, dst->dev->mtu - 40 ,
ip_rt_min_advmss) ;
if ( V_287 > 65535 - 40 )
V_287 = 65535 - 40 ;
}
return V_287 ;
}
static unsigned int F_193 ( const struct V_1 * V_2 )
{
const struct V_7 * V_8 = ( const struct V_7 * ) V_2 ;
unsigned int V_266 = F_178 ( V_2 , V_237 ) ;
if ( V_266 && F_72 ( V_8 ) )
return V_266 ;
V_266 = V_2 -> V_4 -> V_266 ;
if ( F_194 ( F_195 ( V_2 , V_237 ) ) ) {
if ( V_8 -> V_54 != V_8 -> V_12 && V_266 > 576 )
V_266 = 576 ;
}
if ( V_266 > V_289 )
V_266 = V_289 ;
return V_266 ;
}
static void F_196 ( struct V_7 * V_8 , const struct V_276 * V_277 ,
struct V_290 * V_20 )
{
struct V_9 * V_10 ;
int V_209 = 0 ;
if ( V_277 && ( V_277 -> V_291 & V_292 ) )
V_209 = 1 ;
V_8 -> V_10 = V_10 = F_125 ( V_8 -> V_12 , V_209 ) ;
if ( V_10 ) {
V_8 -> F_124 = F_124 () ;
if ( F_5 ( V_10 ) )
memcpy ( V_10 -> V_16 , V_20 -> V_293 ,
sizeof( T_1 ) * V_17 ) ;
F_197 ( & V_8 -> V_2 , V_10 -> V_16 , false ) ;
F_175 ( & V_8 -> V_2 , V_10 ) ;
if ( V_10 -> V_221 . V_222 &&
V_10 -> V_221 . V_222 != V_8 -> V_54 ) {
V_8 -> V_54 = V_10 -> V_221 . V_222 ;
V_8 -> V_55 |= V_114 ;
}
} else {
if ( V_20 -> V_293 != ( T_1 * ) V_294 ) {
V_8 -> V_20 = V_20 ;
F_153 ( & V_20 -> V_295 ) ;
}
F_197 ( & V_8 -> V_2 , V_20 -> V_293 , true ) ;
}
}
static void F_198 ( struct V_7 * V_8 , const struct V_276 * V_277 ,
const struct V_274 * V_275 ,
struct V_290 * V_20 , T_10 type , T_1 V_296 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
if ( V_20 ) {
if ( F_199 ( * V_275 ) &&
F_200 ( * V_275 ) . V_297 == V_298 )
V_8 -> V_54 = F_199 ( * V_275 ) ;
F_196 ( V_8 , V_277 , V_20 ) ;
#ifdef F_58
V_2 -> V_286 = F_200 ( * V_275 ) . V_299 ;
#endif
}
if ( F_177 ( V_2 ) > V_289 )
F_161 ( V_2 , V_237 , V_289 ) ;
if ( F_178 ( V_2 , V_288 ) > 65535 - 40 )
F_161 ( V_2 , V_288 , 65535 - 40 ) ;
#ifdef F_58
#ifdef F_201
F_191 ( V_8 , F_202 ( V_275 ) ) ;
#endif
F_191 ( V_8 , V_296 ) ;
#endif
}
static struct V_7 * F_203 ( struct V_3 * V_4 ,
bool V_300 , bool V_301 )
{
return F_204 ( & V_70 , V_4 , 1 , - 1 ,
V_302 |
( V_300 ? V_303 : 0 ) |
( V_301 ? V_304 : 0 ) ) ;
}
static int F_205 ( struct V_190 * V_191 , T_3 V_26 , T_3 V_27 ,
T_9 V_279 , struct V_3 * V_4 , int V_305 )
{
unsigned int V_189 ;
struct V_7 * V_111 ;
T_3 V_306 ;
struct V_229 * V_230 = F_142 ( V_4 ) ;
T_1 V_296 = 0 ;
int V_202 ;
if ( V_230 == NULL )
return - V_250 ;
if ( F_144 ( V_27 ) || F_145 ( V_27 ) ||
F_206 ( V_27 ) || V_191 -> V_307 != F_130 ( V_308 ) )
goto V_309;
if ( F_146 ( V_27 ) ) {
if ( ! F_207 ( V_26 ) )
goto V_309;
V_306 = F_190 ( V_4 , 0 , V_298 ) ;
} else {
V_202 = F_208 ( V_191 , V_27 , 0 , V_279 , 0 , V_4 , & V_306 ,
& V_296 ) ;
if ( V_202 < 0 )
goto V_310;
}
V_111 = F_203 ( V_311 . V_312 ,
F_209 ( V_230 , V_313 ) , false ) ;
if ( ! V_111 )
goto V_314;
#ifdef F_58
V_111 -> V_2 . V_286 = V_296 ;
#endif
V_111 -> V_2 . V_315 = F_184 ;
V_111 -> V_130 = V_26 ;
V_111 -> V_131 = V_27 ;
V_111 -> F_14 = F_14 ( F_20 ( V_4 ) ) ;
V_111 -> V_55 = V_113 ;
V_111 -> V_200 = V_316 ;
V_111 -> V_62 = V_279 ;
V_111 -> V_12 = V_26 ;
V_111 -> V_58 = V_27 ;
V_111 -> V_132 = V_4 -> V_192 ;
V_111 -> V_247 = V_4 -> V_192 ;
V_111 -> V_134 = 0 ;
V_111 -> V_133 = V_191 -> V_283 ;
V_111 -> V_54 = V_26 ;
V_111 -> V_63 = V_306 ;
V_111 -> F_124 = 0 ;
V_111 -> V_10 = NULL ;
V_111 -> V_20 = NULL ;
if ( V_305 ) {
V_111 -> V_2 . V_317 = V_318 ;
V_111 -> V_55 |= V_125 ;
}
#ifdef F_210
if ( ! F_207 ( V_26 ) && F_211 ( V_230 ) )
V_111 -> V_2 . V_317 = V_319 ;
#endif
F_110 ( V_73 ) ;
V_189 = F_12 ( V_26 , V_27 , V_4 -> V_192 , F_14 ( F_20 ( V_4 ) ) ) ;
V_111 = F_120 ( V_189 , V_111 , V_191 , V_4 -> V_192 ) ;
return F_117 ( V_111 ) ? F_118 ( V_111 ) : 0 ;
V_314:
return - V_205 ;
V_309:
return - V_250 ;
V_310:
return V_202 ;
}
static void F_212 ( struct V_3 * V_4 ,
struct V_229 * V_230 ,
struct V_190 * V_191 ,
T_3 V_26 ,
T_3 V_27 )
{
F_110 ( V_77 ) ;
#ifdef F_154
if ( F_155 ( V_230 ) && F_106 () ) {
F_107 ( V_167 L_27 ,
& V_26 , & V_27 , V_4 -> V_53 ) ;
if ( V_4 -> V_320 && F_213 ( V_191 ) ) {
int V_21 ;
const unsigned char * V_11 = F_214 ( V_191 ) ;
F_107 ( V_167 L_28 ) ;
for ( V_21 = 0 ; V_21 < V_4 -> V_320 ; V_21 ++ , V_11 ++ ) {
F_107 ( L_29 , * V_11 ) ;
if ( V_21 < ( V_4 -> V_320 - 1 ) )
F_107 ( L_30 ) ;
}
F_107 ( L_31 ) ;
}
}
#endif
}
static int F_215 ( struct V_190 * V_191 ,
const struct V_274 * V_275 ,
struct V_229 * V_230 ,
T_3 V_26 , T_3 V_27 , T_1 V_279 ,
struct V_7 * * V_321 )
{
struct V_7 * V_111 ;
int V_202 ;
struct V_229 * V_322 ;
unsigned int V_185 = 0 ;
T_3 V_306 ;
T_1 V_296 ;
V_322 = F_142 ( F_216 ( * V_275 ) ) ;
if ( V_322 == NULL ) {
if ( F_106 () )
F_107 ( V_323 L_32 \
L_33 ) ;
return - V_250 ;
}
V_202 = F_208 ( V_191 , V_27 , V_26 , V_279 , F_217 ( * V_275 ) ,
V_230 -> V_4 , & V_306 , & V_296 ) ;
if ( V_202 < 0 ) {
F_212 ( V_230 -> V_4 , V_230 , V_191 , V_26 ,
V_27 ) ;
goto V_324;
}
if ( V_202 )
V_185 |= V_325 ;
if ( V_322 == V_230 && V_202 &&
( F_147 ( V_322 ) ||
F_148 ( V_322 , V_27 , F_199 ( * V_275 ) ) ) )
V_185 |= V_326 ;
if ( V_191 -> V_307 != F_130 ( V_308 ) ) {
if ( V_322 == V_230 &&
F_218 ( V_230 ) == 0 ) {
V_202 = - V_250 ;
goto V_324;
}
}
V_111 = F_203 ( V_322 -> V_4 ,
F_209 ( V_230 , V_313 ) ,
F_209 ( V_322 , V_327 ) ) ;
if ( ! V_111 ) {
V_202 = - V_205 ;
goto V_324;
}
V_111 -> V_130 = V_26 ;
V_111 -> V_131 = V_27 ;
V_111 -> F_14 = F_14 ( F_20 ( V_111 -> V_2 . V_4 ) ) ;
V_111 -> V_55 = V_185 ;
V_111 -> V_200 = V_275 -> type ;
V_111 -> V_62 = V_279 ;
V_111 -> V_12 = V_26 ;
V_111 -> V_58 = V_27 ;
V_111 -> V_132 = V_230 -> V_4 -> V_192 ;
V_111 -> V_247 = V_230 -> V_4 -> V_192 ;
V_111 -> V_134 = 0 ;
V_111 -> V_133 = V_191 -> V_283 ;
V_111 -> V_54 = V_26 ;
V_111 -> V_63 = V_306 ;
V_111 -> F_124 = 0 ;
V_111 -> V_10 = NULL ;
V_111 -> V_20 = NULL ;
V_111 -> V_2 . V_317 = V_328 ;
V_111 -> V_2 . V_315 = V_329 ;
F_198 ( V_111 , NULL , V_275 , V_275 -> V_20 , V_275 -> type , V_296 ) ;
* V_321 = V_111 ;
V_202 = 0 ;
V_324:
return V_202 ;
}
static int F_219 ( struct V_190 * V_191 ,
struct V_274 * V_275 ,
const struct V_276 * V_277 ,
struct V_229 * V_230 ,
T_3 V_26 , T_3 V_27 , T_1 V_279 )
{
struct V_7 * V_111 = NULL ;
int V_202 ;
unsigned V_189 ;
#ifdef F_220
if ( V_275 -> V_20 && V_275 -> V_20 -> V_330 > 1 )
F_221 ( V_275 ) ;
#endif
V_202 = F_215 ( V_191 , V_275 , V_230 , V_26 , V_27 , V_279 , & V_111 ) ;
if ( V_202 )
return V_202 ;
V_189 = F_12 ( V_26 , V_27 , V_277 -> V_281 ,
F_14 ( F_20 ( V_111 -> V_2 . V_4 ) ) ) ;
V_111 = F_120 ( V_189 , V_111 , V_191 , V_277 -> V_281 ) ;
if ( F_117 ( V_111 ) )
return F_118 ( V_111 ) ;
return 0 ;
}
static int F_222 ( struct V_190 * V_191 , T_3 V_26 , T_3 V_27 ,
T_9 V_279 , struct V_3 * V_4 )
{
struct V_274 V_275 ;
struct V_229 * V_230 = F_142 ( V_4 ) ;
struct V_276 V_277 ;
unsigned V_185 = 0 ;
T_1 V_296 = 0 ;
struct V_7 * V_111 ;
unsigned V_189 ;
T_3 V_306 ;
int V_202 = - V_250 ;
struct V_32 * V_32 = F_20 ( V_4 ) ;
if ( ! V_230 )
goto V_121;
if ( F_144 ( V_27 ) || F_145 ( V_27 ) ||
F_206 ( V_27 ) )
goto V_331;
if ( F_145 ( V_26 ) || ( V_27 == 0 && V_26 == 0 ) )
goto V_332;
if ( F_146 ( V_27 ) )
goto V_331;
if ( F_146 ( V_26 ) || F_206 ( V_26 ) )
goto V_333;
V_277 . V_280 = 0 ;
V_277 . V_281 = V_4 -> V_192 ;
V_277 . V_282 = V_191 -> V_283 ;
V_277 . V_278 = V_279 ;
V_277 . V_334 = V_284 ;
V_277 . V_26 = V_26 ;
V_277 . V_27 = V_27 ;
V_202 = F_188 ( V_32 , & V_277 , & V_275 ) ;
if ( V_202 != 0 ) {
if ( ! F_223 ( V_230 ) )
goto V_335;
goto V_336;
}
F_110 ( V_72 ) ;
if ( V_275 . type == V_337 )
goto V_332;
if ( V_275 . type == V_338 ) {
V_202 = F_208 ( V_191 , V_27 , V_26 , V_279 ,
V_32 -> V_312 -> V_192 ,
V_4 , & V_306 , & V_296 ) ;
if ( V_202 < 0 )
goto V_339;
if ( V_202 )
V_185 |= V_325 ;
V_306 = V_26 ;
goto V_340;
}
if ( ! F_223 ( V_230 ) )
goto V_335;
if ( V_275 . type != V_201 )
goto V_333;
V_202 = F_219 ( V_191 , & V_275 , & V_277 , V_230 , V_26 , V_27 , V_279 ) ;
V_121: return V_202 ;
V_332:
if ( V_191 -> V_307 != F_130 ( V_308 ) )
goto V_309;
if ( F_146 ( V_27 ) )
V_306 = F_190 ( V_4 , 0 , V_298 ) ;
else {
V_202 = F_208 ( V_191 , V_27 , 0 , V_279 , 0 , V_4 , & V_306 ,
& V_296 ) ;
if ( V_202 < 0 )
goto V_339;
if ( V_202 )
V_185 |= V_325 ;
}
V_185 |= V_112 ;
V_275 . type = V_337 ;
F_110 ( V_75 ) ;
V_340:
V_111 = F_203 ( V_32 -> V_312 ,
F_209 ( V_230 , V_313 ) , false ) ;
if ( ! V_111 )
goto V_314;
V_111 -> V_2 . V_317 = V_318 ;
V_111 -> V_2 . V_315 = F_184 ;
#ifdef F_58
V_111 -> V_2 . V_286 = V_296 ;
#endif
V_111 -> V_130 = V_26 ;
V_111 -> V_131 = V_27 ;
V_111 -> F_14 = F_14 ( V_32 ) ;
V_111 -> V_55 = V_185 | V_125 ;
V_111 -> V_200 = V_275 . type ;
V_111 -> V_62 = V_279 ;
V_111 -> V_12 = V_26 ;
V_111 -> V_58 = V_27 ;
#ifdef F_58
V_111 -> V_2 . V_286 = V_296 ;
#endif
V_111 -> V_132 = V_4 -> V_192 ;
V_111 -> V_247 = V_4 -> V_192 ;
V_111 -> V_134 = 0 ;
V_111 -> V_133 = V_191 -> V_283 ;
V_111 -> V_54 = V_26 ;
V_111 -> V_63 = V_306 ;
V_111 -> F_124 = 0 ;
V_111 -> V_10 = NULL ;
V_111 -> V_20 = NULL ;
if ( V_275 . type == V_341 ) {
V_111 -> V_2 . V_317 = F_168 ;
V_111 -> V_2 . error = - V_202 ;
V_111 -> V_55 &= ~ V_125 ;
}
V_189 = F_12 ( V_26 , V_27 , V_277 . V_281 , F_14 ( V_32 ) ) ;
V_111 = F_120 ( V_189 , V_111 , V_191 , V_277 . V_281 ) ;
V_202 = 0 ;
if ( F_117 ( V_111 ) )
V_202 = F_118 ( V_111 ) ;
goto V_121;
V_336:
F_110 ( V_74 ) ;
V_306 = F_190 ( V_4 , 0 , V_284 ) ;
V_275 . type = V_341 ;
if ( V_202 == - V_342 )
V_202 = - V_253 ;
goto V_340;
V_333:
F_110 ( V_76 ) ;
#ifdef F_154
if ( F_155 ( V_230 ) && F_106 () )
F_107 ( V_167 L_34 ,
& V_26 , & V_27 , V_4 -> V_53 ) ;
#endif
V_335:
V_202 = - V_251 ;
goto V_121;
V_309:
V_202 = - V_250 ;
goto V_121;
V_314:
V_202 = - V_205 ;
goto V_121;
V_331:
V_202 = - V_250 ;
V_339:
F_212 ( V_4 , V_230 , V_191 , V_26 , V_27 ) ;
goto V_121;
}
int F_224 ( struct V_190 * V_191 , T_3 V_26 , T_3 V_27 ,
T_9 V_279 , struct V_3 * V_4 , bool V_343 )
{
struct V_7 * V_111 ;
unsigned V_189 ;
int V_344 = V_4 -> V_192 ;
struct V_32 * V_32 ;
int V_275 ;
V_32 = F_20 ( V_4 ) ;
F_31 () ;
if ( ! F_73 ( V_32 ) )
goto V_345;
V_279 &= V_346 ;
V_189 = F_12 ( V_26 , V_27 , V_344 , F_14 ( V_32 ) ) ;
for ( V_111 = F_152 ( V_41 [ V_189 ] . V_42 ) ; V_111 ;
V_111 = F_152 ( V_111 -> V_2 . V_43 ) ) {
if ( ( ( ( V_30 T_1 ) V_111 -> V_130 ^ ( V_30 T_1 ) V_26 ) |
( ( V_30 T_1 ) V_111 -> V_131 ^ ( V_30 T_1 ) V_27 ) |
( V_111 -> V_132 ^ V_344 ) |
( V_111 -> V_62 ^ V_279 ) ) == 0 &&
V_111 -> V_133 == V_191 -> V_283 &&
F_77 ( F_20 ( V_111 -> V_2 . V_4 ) , V_32 ) &&
! F_78 ( V_111 ) ) {
F_180 ( V_111 ) ;
if ( V_343 ) {
F_225 ( & V_111 -> V_2 , V_122 ) ;
F_226 ( V_191 , & V_111 -> V_2 ) ;
} else {
F_122 ( & V_111 -> V_2 , V_122 ) ;
F_123 ( V_191 , & V_111 -> V_2 ) ;
}
F_110 ( V_71 ) ;
F_33 () ;
return 0 ;
}
F_110 ( V_85 ) ;
}
V_345:
if ( F_144 ( V_26 ) ) {
struct V_229 * V_230 = F_142 ( V_4 ) ;
if ( V_230 ) {
int V_305 = F_227 ( V_230 , V_26 , V_27 ,
F_167 ( V_191 ) -> V_307 ) ;
if ( V_305
#ifdef F_210
||
( ! F_207 ( V_26 ) &&
F_211 ( V_230 ) )
#endif
) {
int V_275 = F_205 ( V_191 , V_26 , V_27 ,
V_279 , V_4 , V_305 ) ;
F_33 () ;
return V_275 ;
}
}
F_33 () ;
return - V_250 ;
}
V_275 = F_222 ( V_191 , V_26 , V_27 , V_279 , V_4 ) ;
F_33 () ;
return V_275 ;
}
static struct V_7 * F_228 ( const struct V_274 * V_275 ,
const struct V_276 * V_277 ,
T_3 V_347 , T_3 V_348 ,
int V_349 , T_11 V_350 ,
struct V_3 * V_351 ,
unsigned int V_185 )
{
struct V_290 * V_20 = V_275 -> V_20 ;
struct V_229 * V_230 ;
T_10 type = V_275 -> type ;
struct V_7 * V_111 ;
if ( F_206 ( V_277 -> V_27 ) && ! ( V_351 -> V_185 & V_186 ) )
return F_121 ( - V_250 ) ;
if ( F_145 ( V_277 -> V_26 ) )
type = V_337 ;
else if ( F_144 ( V_277 -> V_26 ) )
type = V_316 ;
else if ( F_146 ( V_277 -> V_26 ) )
return F_121 ( - V_250 ) ;
if ( V_351 -> V_185 & V_186 )
V_185 |= V_125 ;
V_230 = F_142 ( V_351 ) ;
if ( ! V_230 )
return F_121 ( - V_250 ) ;
if ( type == V_337 ) {
V_185 |= V_112 | V_125 ;
V_20 = NULL ;
} else if ( type == V_316 ) {
V_185 |= V_113 | V_125 ;
if ( ! F_227 ( V_230 , V_277 -> V_26 , V_277 -> V_27 ,
V_277 -> V_352 ) )
V_185 &= ~ V_125 ;
if ( V_20 && V_275 -> V_353 < 4 )
V_20 = NULL ;
}
V_111 = F_203 ( V_351 ,
F_209 ( V_230 , V_313 ) ,
F_209 ( V_230 , V_327 ) ) ;
if ( ! V_111 )
return F_121 ( - V_205 ) ;
V_111 -> V_2 . V_315 = V_329 ;
V_111 -> V_130 = V_347 ;
V_111 -> V_131 = V_348 ;
V_111 -> F_14 = F_14 ( F_20 ( V_351 ) ) ;
V_111 -> V_55 = V_185 ;
V_111 -> V_200 = type ;
V_111 -> V_62 = V_350 ;
V_111 -> V_12 = V_277 -> V_26 ;
V_111 -> V_58 = V_277 -> V_27 ;
V_111 -> V_132 = 0 ;
V_111 -> V_247 = V_349 ? : V_351 -> V_192 ;
V_111 -> V_134 = V_349 ;
V_111 -> V_133 = V_277 -> V_282 ;
V_111 -> V_54 = V_277 -> V_26 ;
V_111 -> V_63 = V_277 -> V_27 ;
V_111 -> F_124 = 0 ;
V_111 -> V_10 = NULL ;
V_111 -> V_20 = NULL ;
F_110 ( V_79 ) ;
if ( V_185 & V_125 ) {
V_111 -> V_2 . V_317 = V_318 ;
V_111 -> V_63 = V_277 -> V_26 ;
}
if ( V_185 & ( V_112 | V_113 ) ) {
V_111 -> V_63 = V_277 -> V_27 ;
if ( V_185 & V_125 &&
! ( V_351 -> V_185 & V_186 ) ) {
V_111 -> V_2 . V_315 = V_354 ;
F_110 ( V_80 ) ;
}
#ifdef F_210
if ( type == V_316 ) {
if ( F_211 ( V_230 ) &&
! F_207 ( V_277 -> V_26 ) ) {
V_111 -> V_2 . V_317 = V_319 ;
V_111 -> V_2 . V_315 = V_354 ;
}
}
#endif
}
F_198 ( V_111 , V_277 , V_275 , V_20 , type , 0 ) ;
return V_111 ;
}
static struct V_7 * F_229 ( struct V_32 * V_32 , struct V_276 * V_277 )
{
struct V_3 * V_351 = NULL ;
T_11 V_279 = F_230 ( V_277 ) ;
unsigned int V_185 = 0 ;
struct V_274 V_275 ;
struct V_7 * V_111 ;
T_3 V_347 ;
T_3 V_348 ;
int V_349 ;
V_275 . V_20 = NULL ;
#ifdef F_201
V_275 . V_39 = NULL ;
#endif
V_347 = V_277 -> V_26 ;
V_348 = V_277 -> V_27 ;
V_349 = V_277 -> V_280 ;
V_277 -> V_281 = V_32 -> V_312 -> V_192 ;
V_277 -> V_278 = V_279 & V_346 ;
V_277 -> V_334 = ( ( V_279 & V_355 ) ?
V_298 : V_284 ) ;
F_31 () ;
if ( V_277 -> V_27 ) {
V_111 = F_121 ( - V_250 ) ;
if ( F_144 ( V_277 -> V_27 ) ||
F_145 ( V_277 -> V_27 ) ||
F_146 ( V_277 -> V_27 ) )
goto V_121;
if ( V_277 -> V_280 == 0 &&
( F_144 ( V_277 -> V_26 ) ||
F_145 ( V_277 -> V_26 ) ) ) {
V_351 = F_231 ( V_32 , V_277 -> V_27 , false ) ;
if ( V_351 == NULL )
goto V_121;
V_277 -> V_280 = V_351 -> V_192 ;
goto V_356;
}
if ( ! ( V_277 -> V_291 & V_357 ) ) {
if ( ! F_231 ( V_32 , V_277 -> V_27 , false ) )
goto V_121;
}
}
if ( V_277 -> V_280 ) {
V_351 = F_232 ( V_32 , V_277 -> V_280 ) ;
V_111 = F_121 ( - V_358 ) ;
if ( V_351 == NULL )
goto V_121;
if ( ! ( V_351 -> V_185 & V_359 ) || ! F_142 ( V_351 ) ) {
V_111 = F_121 ( - V_253 ) ;
goto V_121;
}
if ( F_207 ( V_277 -> V_26 ) ||
F_145 ( V_277 -> V_26 ) ) {
if ( ! V_277 -> V_27 )
V_277 -> V_27 = F_190 ( V_351 , 0 ,
V_298 ) ;
goto V_356;
}
if ( V_277 -> V_27 ) {
if ( F_144 ( V_277 -> V_26 ) )
V_277 -> V_27 = F_190 ( V_351 , 0 ,
V_277 -> V_334 ) ;
else if ( ! V_277 -> V_26 )
V_277 -> V_27 = F_190 ( V_351 , 0 ,
V_360 ) ;
}
}
if ( ! V_277 -> V_26 ) {
V_277 -> V_26 = V_277 -> V_27 ;
if ( ! V_277 -> V_26 )
V_277 -> V_26 = V_277 -> V_27 = F_233 ( V_361 ) ;
V_351 = V_32 -> V_312 ;
V_277 -> V_280 = V_32 -> V_312 -> V_192 ;
V_275 . type = V_338 ;
V_185 |= V_125 ;
goto V_356;
}
if ( F_188 ( V_32 , V_277 , & V_275 ) ) {
V_275 . V_20 = NULL ;
if ( V_277 -> V_280 ) {
if ( V_277 -> V_27 == 0 )
V_277 -> V_27 = F_190 ( V_351 , 0 ,
V_298 ) ;
V_275 . type = V_201 ;
goto V_356;
}
V_111 = F_121 ( - V_253 ) ;
goto V_121;
}
if ( V_275 . type == V_338 ) {
if ( ! V_277 -> V_27 ) {
if ( V_275 . V_20 -> V_362 )
V_277 -> V_27 = V_275 . V_20 -> V_362 ;
else
V_277 -> V_27 = V_277 -> V_26 ;
}
V_351 = V_32 -> V_312 ;
V_277 -> V_280 = V_351 -> V_192 ;
V_275 . V_20 = NULL ;
V_185 |= V_125 ;
goto V_356;
}
#ifdef F_220
if ( V_275 . V_20 -> V_330 > 1 && V_277 -> V_280 == 0 )
F_221 ( & V_275 ) ;
else
#endif
if ( ! V_275 . V_353 &&
V_275 . V_363 -> V_364 > 1 &&
V_275 . type == V_201 && ! V_277 -> V_280 )
F_234 ( & V_275 ) ;
if ( ! V_277 -> V_27 )
V_277 -> V_27 = F_189 ( V_32 , V_275 ) ;
V_351 = F_216 ( V_275 ) ;
V_277 -> V_280 = V_351 -> V_192 ;
V_356:
V_111 = F_228 ( & V_275 , V_277 , V_347 , V_348 , V_349 ,
V_279 , V_351 , V_185 ) ;
if ( ! F_117 ( V_111 ) ) {
unsigned int V_189 ;
V_189 = F_12 ( V_347 , V_348 , V_349 ,
F_14 ( F_20 ( V_351 ) ) ) ;
V_111 = F_120 ( V_189 , V_111 , NULL , V_349 ) ;
}
V_121:
F_33 () ;
return V_111 ;
}
struct V_7 * F_235 ( struct V_32 * V_32 , struct V_276 * V_365 )
{
struct V_7 * V_111 ;
unsigned int V_189 ;
if ( ! F_73 ( V_32 ) )
goto V_366;
V_189 = F_12 ( V_365 -> V_26 , V_365 -> V_27 , V_365 -> V_280 , F_14 ( V_32 ) ) ;
F_18 () ;
for ( V_111 = F_19 ( V_41 [ V_189 ] . V_42 ) ; V_111 ;
V_111 = F_19 ( V_111 -> V_2 . V_43 ) ) {
if ( V_111 -> V_130 == V_365 -> V_26 &&
V_111 -> V_131 == V_365 -> V_27 &&
F_72 ( V_111 ) &&
V_111 -> V_134 == V_365 -> V_280 &&
V_111 -> V_133 == V_365 -> V_282 &&
! ( ( V_111 -> V_62 ^ V_365 -> V_278 ) &
( V_346 | V_355 ) ) &&
F_77 ( F_20 ( V_111 -> V_2 . V_4 ) , V_32 ) &&
! F_78 ( V_111 ) ) {
F_180 ( V_111 ) ;
F_122 ( & V_111 -> V_2 , V_122 ) ;
F_110 ( V_78 ) ;
F_22 () ;
if ( ! V_365 -> V_27 )
V_365 -> V_27 = V_111 -> V_58 ;
if ( ! V_365 -> V_26 )
V_365 -> V_26 = V_111 -> V_12 ;
return V_111 ;
}
F_110 ( V_86 ) ;
}
F_22 () ;
V_366:
return F_229 ( V_32 , V_365 ) ;
}
static struct V_1 * F_236 ( struct V_1 * V_2 , T_1 V_272 )
{
return NULL ;
}
static unsigned int F_237 ( const struct V_1 * V_2 )
{
unsigned int V_266 = F_178 ( V_2 , V_237 ) ;
return V_266 ? : V_2 -> V_4 -> V_266 ;
}
static void F_238 ( struct V_1 * V_2 , T_1 V_266 )
{
}
static T_1 * F_239 ( struct V_1 * V_2 ,
unsigned long V_6 )
{
return NULL ;
}
struct V_1 * F_240 ( struct V_32 * V_32 , struct V_1 * V_367 )
{
struct V_7 * V_8 = F_204 ( & V_368 , NULL , 1 , 0 , 0 ) ;
struct V_7 * V_369 = (struct V_7 * ) V_367 ;
if ( V_8 ) {
struct V_1 * V_15 = & V_8 -> V_2 ;
V_15 -> V_57 = 1 ;
V_15 -> V_317 = V_370 ;
V_15 -> V_315 = V_370 ;
F_241 ( V_15 , & V_369 -> V_2 ) ;
V_15 -> V_4 = V_369 -> V_2 . V_4 ;
if ( V_15 -> V_4 )
F_242 ( V_15 -> V_4 ) ;
V_8 -> V_130 = V_369 -> V_130 ;
V_8 -> V_131 = V_369 -> V_131 ;
V_8 -> V_62 = V_369 -> V_62 ;
V_8 -> V_132 = V_369 -> V_132 ;
V_8 -> V_247 = V_369 -> V_247 ;
V_8 -> V_134 = V_369 -> V_134 ;
V_8 -> V_133 = V_369 -> V_133 ;
V_8 -> F_14 = F_14 ( V_32 ) ;
V_8 -> V_55 = V_369 -> V_55 ;
V_8 -> V_200 = V_369 -> V_200 ;
V_8 -> V_12 = V_369 -> V_12 ;
V_8 -> V_58 = V_369 -> V_58 ;
V_8 -> V_54 = V_369 -> V_54 ;
V_8 -> V_63 = V_369 -> V_63 ;
V_8 -> V_10 = V_369 -> V_10 ;
if ( V_8 -> V_10 )
F_153 ( & V_8 -> V_10 -> V_371 ) ;
V_8 -> V_20 = V_369 -> V_20 ;
if ( V_8 -> V_20 )
F_153 ( & V_8 -> V_20 -> V_295 ) ;
F_243 ( V_15 ) ;
}
F_244 ( V_367 ) ;
return V_8 ? & V_8 -> V_2 : F_121 ( - V_92 ) ;
}
struct V_7 * F_245 ( struct V_32 * V_32 , struct V_276 * V_365 ,
struct V_372 * V_373 )
{
struct V_7 * V_8 = F_235 ( V_32 , V_365 ) ;
if ( F_117 ( V_8 ) )
return V_8 ;
if ( V_365 -> V_352 )
V_8 = (struct V_7 * ) F_246 ( V_32 , & V_8 -> V_2 ,
F_247 ( V_365 ) ,
V_373 , 0 ) ;
return V_8 ;
}
static int F_248 ( struct V_32 * V_32 ,
struct V_190 * V_191 , T_1 V_374 , T_1 V_35 , int V_375 ,
int V_376 , unsigned int V_185 )
{
struct V_7 * V_8 = F_163 ( V_191 ) ;
struct V_377 * V_39 ;
struct V_378 * V_379 ;
unsigned long V_155 = 0 ;
const struct V_9 * V_10 = V_8 -> V_10 ;
T_1 V_215 = 0 , V_380 = 0 , V_381 = 0 , error ;
V_379 = F_249 ( V_191 , V_374 , V_35 , V_375 , sizeof( * V_39 ) , V_185 ) ;
if ( V_379 == NULL )
return - V_382 ;
V_39 = F_250 ( V_379 ) ;
V_39 -> V_383 = V_165 ;
V_39 -> V_384 = 32 ;
V_39 -> V_385 = 0 ;
V_39 -> V_386 = V_8 -> V_62 ;
V_39 -> V_387 = V_388 ;
F_251 ( V_191 , V_389 , V_388 ) ;
V_39 -> V_390 = V_8 -> V_200 ;
V_39 -> V_391 = V_284 ;
V_39 -> V_392 = V_393 ;
V_39 -> V_394 = ( V_8 -> V_55 & ~ 0xFFFF ) | V_395 ;
if ( V_8 -> V_55 & V_115 )
V_39 -> V_394 |= V_396 ;
F_252 ( V_191 , V_397 , V_8 -> V_12 ) ;
if ( V_8 -> V_131 ) {
V_39 -> V_385 = 32 ;
F_252 ( V_191 , V_398 , V_8 -> V_131 ) ;
}
if ( V_8 -> V_2 . V_4 )
F_251 ( V_191 , V_399 , V_8 -> V_2 . V_4 -> V_192 ) ;
#ifdef F_58
if ( V_8 -> V_2 . V_286 )
F_251 ( V_191 , V_400 , V_8 -> V_2 . V_286 ) ;
#endif
if ( F_68 ( V_8 ) )
F_252 ( V_191 , V_401 , V_8 -> V_63 ) ;
else if ( V_8 -> V_58 != V_8 -> V_131 )
F_252 ( V_191 , V_401 , V_8 -> V_58 ) ;
if ( V_8 -> V_12 != V_8 -> V_54 )
F_252 ( V_191 , V_402 , V_8 -> V_54 ) ;
if ( F_253 ( V_191 , F_254 ( & V_8 -> V_2 ) ) < 0 )
goto V_403;
if ( V_8 -> V_133 )
F_252 ( V_191 , V_404 , V_8 -> V_133 ) ;
error = V_8 -> V_2 . error ;
if ( V_10 ) {
F_255 ( V_8 -> V_10 ) ;
V_215 = F_15 ( & V_10 -> V_405 ) & 0xffff ;
if ( V_10 -> V_406 ) {
V_380 = V_10 -> V_407 ;
V_381 = F_256 () - V_10 -> V_406 ;
}
V_155 = F_157 ( V_10 -> V_116 ) ;
if ( V_155 ) {
if ( F_176 ( V_122 , V_155 ) )
V_155 -= V_122 ;
else
V_155 = 0 ;
}
}
if ( F_68 ( V_8 ) ) {
#ifdef F_210
T_3 V_2 = V_8 -> V_12 ;
if ( F_144 ( V_2 ) && ! F_207 ( V_2 ) &&
F_257 ( V_32 , V_408 ) ) {
int V_202 = F_258 ( V_32 , V_191 ,
V_8 -> V_58 , V_8 -> V_12 ,
V_39 , V_376 ) ;
if ( V_202 <= 0 ) {
if ( ! V_376 ) {
if ( V_202 == 0 )
return 0 ;
goto V_403;
} else {
if ( V_202 == - V_382 )
goto V_403;
error = V_202 ;
}
}
} else
#endif
F_251 ( V_191 , V_409 , V_8 -> V_247 ) ;
}
if ( F_259 ( V_191 , & V_8 -> V_2 , V_215 , V_380 , V_381 ,
V_155 , error ) < 0 )
goto V_403;
return F_260 ( V_191 , V_379 ) ;
V_403:
F_261 ( V_191 , V_379 ) ;
return - V_382 ;
}
static int F_262 ( struct V_190 * V_410 , struct V_378 * V_379 , void * V_411 )
{
struct V_32 * V_32 = F_263 ( V_410 -> V_373 ) ;
struct V_377 * V_412 ;
struct V_413 * V_414 [ V_415 + 1 ] ;
struct V_7 * V_8 = NULL ;
T_3 V_2 = 0 ;
T_3 V_90 = 0 ;
T_1 V_344 ;
int V_202 ;
int V_283 ;
struct V_190 * V_191 ;
V_202 = F_264 ( V_379 , sizeof( * V_412 ) , V_414 , V_415 , V_416 ) ;
if ( V_202 < 0 )
goto V_417;
V_412 = F_250 ( V_379 ) ;
V_191 = F_265 ( V_418 , V_25 ) ;
if ( V_191 == NULL ) {
V_202 = - V_205 ;
goto V_417;
}
F_266 ( V_191 ) ;
F_267 ( V_191 ) ;
F_167 ( V_191 ) -> V_307 = V_419 ;
F_268 ( V_191 , V_420 + sizeof( struct V_210 ) ) ;
V_90 = V_414 [ V_398 ] ? F_269 ( V_414 [ V_398 ] ) : 0 ;
V_2 = V_414 [ V_397 ] ? F_269 ( V_414 [ V_397 ] ) : 0 ;
V_344 = V_414 [ V_409 ] ? F_270 ( V_414 [ V_409 ] ) : 0 ;
V_283 = V_414 [ V_404 ] ? F_270 ( V_414 [ V_404 ] ) : 0 ;
if ( V_344 ) {
struct V_3 * V_4 ;
V_4 = F_271 ( V_32 , V_344 ) ;
if ( V_4 == NULL ) {
V_202 = - V_358 ;
goto V_421;
}
V_191 -> V_307 = F_130 ( V_308 ) ;
V_191 -> V_4 = V_4 ;
V_191 -> V_283 = V_283 ;
F_272 () ;
V_202 = F_273 ( V_191 , V_2 , V_90 , V_412 -> V_386 , V_4 ) ;
F_274 () ;
V_8 = F_163 ( V_191 ) ;
if ( V_202 == 0 && V_8 -> V_2 . error )
V_202 = - V_8 -> V_2 . error ;
} else {
struct V_276 V_277 = {
. V_26 = V_2 ,
. V_27 = V_90 ,
. V_278 = V_412 -> V_386 ,
. V_280 = V_414 [ V_399 ] ? F_270 ( V_414 [ V_399 ] ) : 0 ,
. V_282 = V_283 ,
} ;
V_8 = F_275 ( V_32 , & V_277 ) ;
V_202 = 0 ;
if ( F_117 ( V_8 ) )
V_202 = F_118 ( V_8 ) ;
}
if ( V_202 )
goto V_421;
F_123 ( V_191 , & V_8 -> V_2 ) ;
if ( V_412 -> V_394 & V_396 )
V_8 -> V_55 |= V_115 ;
V_202 = F_248 ( V_32 , V_191 , F_276 ( V_410 ) . V_374 , V_379 -> V_422 ,
V_423 , 0 , 0 ) ;
if ( V_202 <= 0 )
goto V_421;
V_202 = F_277 ( V_191 , V_32 , F_276 ( V_410 ) . V_374 ) ;
V_417:
return V_202 ;
V_421:
F_170 ( V_191 ) ;
goto V_417;
}
int F_278 ( struct V_190 * V_191 , struct V_424 * V_425 )
{
struct V_7 * V_8 ;
int V_426 , V_427 ;
int V_28 , V_428 ;
struct V_32 * V_32 ;
V_32 = F_263 ( V_191 -> V_373 ) ;
V_427 = V_425 -> args [ 0 ] ;
if ( V_427 < 0 )
V_427 = 0 ;
V_428 = V_28 = V_425 -> args [ 1 ] ;
for ( V_426 = V_427 ; V_426 <= V_31 ; V_426 ++ , V_428 = 0 ) {
if ( ! V_41 [ V_426 ] . V_42 )
continue;
F_18 () ;
for ( V_8 = F_19 ( V_41 [ V_426 ] . V_42 ) , V_28 = 0 ; V_8 ;
V_8 = F_19 ( V_8 -> V_2 . V_43 ) , V_28 ++ ) {
if ( ! F_77 ( F_20 ( V_8 -> V_2 . V_4 ) , V_32 ) || V_28 < V_428 )
continue;
if ( F_78 ( V_8 ) )
continue;
F_226 ( V_191 , & V_8 -> V_2 ) ;
if ( F_248 ( V_32 , V_191 , F_276 ( V_425 -> V_191 ) . V_374 ,
V_425 -> V_379 -> V_422 , V_423 ,
1 , V_429 ) <= 0 ) {
F_279 ( V_191 ) ;
F_22 () ;
goto V_430;
}
F_279 ( V_191 ) ;
}
F_22 () ;
}
V_430:
V_425 -> args [ 0 ] = V_426 ;
V_425 -> args [ 1 ] = V_28 ;
return V_191 -> V_49 ;
}
void F_280 ( struct V_229 * V_230 )
{
F_102 ( F_20 ( V_230 -> V_4 ) , 0 ) ;
}
static int F_281 ( T_12 * V_431 , int V_432 ,
void T_13 * V_433 ,
T_14 * V_434 , T_4 * V_435 )
{
if ( V_432 ) {
int V_436 ;
T_12 V_437 ;
struct V_32 * V_32 ;
memcpy ( & V_437 , V_431 , sizeof( V_437 ) ) ;
V_437 . V_438 = & V_436 ;
F_282 ( & V_437 , V_432 , V_433 , V_434 , V_435 ) ;
V_32 = (struct V_32 * ) V_431 -> V_439 ;
F_102 ( V_32 , V_436 ) ;
return 0 ;
}
return - V_250 ;
}
static T_5 int F_283 ( struct V_32 * V_32 )
{
struct T_12 * V_440 ;
V_440 = V_441 ;
if ( ! F_77 ( V_32 , & V_311 ) ) {
V_440 = F_284 ( V_440 , sizeof( V_441 ) , V_25 ) ;
if ( V_440 == NULL )
goto V_442;
}
V_440 [ 0 ] . V_439 = V_32 ;
V_32 -> V_33 . V_443 =
F_285 ( V_32 , V_444 , V_440 ) ;
if ( V_32 -> V_33 . V_443 == NULL )
goto V_445;
return 0 ;
V_445:
if ( V_440 != V_441 )
F_52 ( V_440 ) ;
V_442:
return - V_92 ;
}
static T_6 void F_286 ( struct V_32 * V_32 )
{
struct T_12 * V_440 ;
V_440 = V_32 -> V_33 . V_443 -> V_446 ;
F_287 ( V_32 -> V_33 . V_443 ) ;
F_288 ( V_440 == V_441 ) ;
F_52 ( V_440 ) ;
}
static T_5 int F_289 ( struct V_32 * V_32 )
{
F_99 ( & V_32 -> V_33 . F_14 ,
sizeof( V_32 -> V_33 . F_14 ) ) ;
F_99 ( & V_32 -> V_33 . V_447 ,
sizeof( V_32 -> V_33 . V_447 ) ) ;
return 0 ;
}
static int T_2 F_290 ( char * V_448 )
{
if ( ! V_448 )
return 0 ;
V_449 = F_291 ( V_448 , & V_448 , 0 ) ;
return 1 ;
}
int T_2 F_292 ( void )
{
int V_450 = 0 ;
#ifdef F_58
V_89 = F_293 ( 256 * sizeof( struct V_89 ) , F_294 ( struct V_89 ) ) ;
if ( ! V_89 )
F_10 ( L_35 ) ;
#endif
V_70 . V_451 =
F_295 ( L_36 , sizeof( struct V_7 ) , 0 ,
V_452 | V_453 , NULL ) ;
V_368 . V_451 = V_70 . V_451 ;
if ( F_296 ( & V_70 ) < 0 )
F_10 ( L_37 ) ;
if ( F_296 ( & V_368 ) < 0 )
F_10 ( L_38 ) ;
V_41 = (struct V_454 * )
F_297 ( L_39 ,
sizeof( struct V_454 ) ,
V_449 ,
( V_455 >= 128 * 1024 ) ?
15 : 17 ,
0 ,
& V_151 ,
& V_31 ,
V_449 ? 0 : 512 * 1024 ) ;
memset ( V_41 , 0 , ( V_31 + 1 ) * sizeof( struct V_454 ) ) ;
F_8 () ;
V_70 . V_179 = ( V_31 + 1 ) ;
V_177 = ( V_31 + 1 ) * 16 ;
F_298 () ;
F_299 () ;
F_300 ( & V_162 , F_96 ) ;
V_150 = V_122 ;
F_97 ( & V_162 ,
F_301 () % V_163 + V_163 ) ;
if ( F_61 () )
F_107 ( V_456 L_40 ) ;
#ifdef F_302
F_303 () ;
F_304 ( V_177 ) ;
#endif
F_305 ( V_457 , V_458 , F_262 , NULL , NULL ) ;
#ifdef F_306
F_62 ( & V_459 ) ;
#endif
F_62 ( & V_460 ) ;
return V_450 ;
}
void T_2 F_307 ( void )
{
F_308 ( V_461 , V_462 ) ;
}
