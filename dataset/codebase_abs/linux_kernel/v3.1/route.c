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
int V_49 ;
V_48 = F_31 ( & V_39 -> V_2 ) ;
F_30 ( V_35 , L_6
L_7 ,
V_39 -> V_2 . V_4 ? V_39 -> V_2 . V_4 -> V_50 : L_8 ,
( V_30 T_1 ) V_39 -> V_12 ,
( V_30 T_1 ) V_39 -> V_51 ,
V_39 -> V_52 , F_15 ( & V_39 -> V_2 . V_53 ) ,
V_39 -> V_2 . V_54 , 0 , ( V_30 T_1 ) V_39 -> V_55 ,
F_32 ( & V_39 -> V_2 ) + 40 ,
F_33 ( & V_39 -> V_2 , V_56 ) ,
( int ) ( ( F_33 ( & V_39 -> V_2 , V_57 ) >> 3 ) +
F_33 ( & V_39 -> V_2 , V_58 ) ) ,
V_39 -> V_59 ,
- 1 ,
( V_48 && ( V_48 -> V_60 & V_61 ) ) ? 1 : 0 ,
V_39 -> V_62 , & V_49 ) ;
F_30 ( V_35 , L_9 , 127 - V_49 , L_10 ) ;
}
return 0 ;
}
static int F_34 ( struct V_63 * V_63 , struct V_64 * V_64 )
{
return F_35 ( V_63 , V_64 , & V_65 ,
sizeof( struct V_36 ) ) ;
}
static void * F_36 ( struct V_34 * V_35 , T_4 * V_44 )
{
int V_66 ;
if ( * V_44 == 0 )
return V_45 ;
for ( V_66 = * V_44 - 1 ; V_66 < V_67 ; ++ V_66 ) {
if ( ! F_37 ( V_66 ) )
continue;
* V_44 = V_66 + 1 ;
return & F_38 ( V_68 , V_66 ) ;
}
return NULL ;
}
static void * F_39 ( struct V_34 * V_35 , void * V_46 , T_4 * V_44 )
{
int V_66 ;
for ( V_66 = * V_44 ; V_66 < V_67 ; ++ V_66 ) {
if ( ! F_37 ( V_66 ) )
continue;
* V_44 = V_66 + 1 ;
return & F_38 ( V_68 , V_66 ) ;
}
return NULL ;
}
static void F_40 ( struct V_34 * V_35 , void * V_46 )
{
}
static int F_41 ( struct V_34 * V_35 , void * V_46 )
{
struct V_68 * V_37 = V_46 ;
if ( V_46 == V_45 ) {
F_30 ( V_35 , L_11 ) ;
return 0 ;
}
F_30 ( V_35 , L_12
L_13 ,
F_42 ( & V_69 ) ,
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
static int F_43 ( struct V_63 * V_63 , struct V_64 * V_64 )
{
return F_44 ( V_64 , & V_86 ) ;
}
static int F_45 ( struct V_34 * V_87 , void * V_46 )
{
struct V_88 * V_2 , * V_89 ;
unsigned int V_21 , V_90 ;
V_2 = F_46 ( 256 , sizeof( struct V_88 ) , V_25 ) ;
if ( ! V_2 )
return - V_91 ;
F_47 (i) {
V_89 = (struct V_88 * ) F_48 ( V_88 , V_21 ) ;
for ( V_90 = 0 ; V_90 < 256 ; V_90 ++ ) {
V_2 [ V_90 ] . V_92 += V_89 [ V_90 ] . V_92 ;
V_2 [ V_90 ] . V_93 += V_89 [ V_90 ] . V_93 ;
V_2 [ V_90 ] . V_94 += V_89 [ V_90 ] . V_94 ;
V_2 [ V_90 ] . V_95 += V_89 [ V_90 ] . V_95 ;
}
}
F_49 ( V_87 , V_2 , 256 * sizeof( struct V_88 ) ) ;
F_50 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_63 * V_63 , struct V_64 * V_64 )
{
return F_52 ( V_64 , F_45 , NULL ) ;
}
static int T_5 F_53 ( struct V_32 * V_32 )
{
struct V_96 * V_97 ;
V_97 = F_54 ( V_32 , L_14 , V_98 ,
& V_99 ) ;
if ( ! V_97 )
goto V_100;
V_97 = F_55 ( L_14 , V_98 ,
V_32 -> V_101 , & V_102 ) ;
if ( ! V_97 )
goto V_103;
#ifdef F_56
V_97 = F_55 ( L_15 , 0 , V_32 -> V_104 , & V_105 ) ;
if ( ! V_97 )
goto V_106;
#endif
return 0 ;
#ifdef F_56
V_106:
F_57 ( L_14 , V_32 -> V_101 ) ;
#endif
V_103:
F_57 ( L_14 , V_32 -> V_104 ) ;
V_100:
return - V_91 ;
}
static void T_6 F_58 ( struct V_32 * V_32 )
{
F_57 ( L_14 , V_32 -> V_101 ) ;
F_57 ( L_14 , V_32 -> V_104 ) ;
#ifdef F_56
F_57 ( L_15 , V_32 -> V_104 ) ;
#endif
}
static int T_2 F_59 ( void )
{
return F_60 ( & V_107 ) ;
}
static inline int F_59 ( void )
{
return 0 ;
}
static inline void F_61 ( struct V_7 * V_8 )
{
F_62 ( & V_8 -> V_2 . V_108 , V_109 ) ;
}
static inline void F_63 ( struct V_7 * V_8 )
{
F_64 ( V_8 ) ;
F_62 ( & V_8 -> V_2 . V_108 , V_109 ) ;
}
static inline int F_65 ( struct V_7 * V_110 )
{
return ( V_110 -> V_52 & ( V_111 | V_112 ) ) &&
F_66 ( V_110 ) && V_110 -> V_2 . V_43 ;
}
static inline int F_67 ( struct V_7 * V_110 )
{
return ( V_110 -> V_52 & ( V_113 | V_114 ) ) ||
( V_110 -> V_10 && V_110 -> V_10 -> V_115 ) ;
}
static int F_68 ( struct V_7 * V_110 , unsigned long V_116 , unsigned long V_117 )
{
unsigned long V_118 ;
int V_119 = 0 ;
if ( F_15 ( & V_110 -> V_2 . V_53 ) )
goto V_120;
V_118 = V_121 - V_110 -> V_2 . V_122 ;
if ( ( V_118 <= V_116 && ! F_65 ( V_110 ) ) ||
( V_118 <= V_117 && F_67 ( V_110 ) ) )
goto V_120;
V_119 = 1 ;
V_120: return V_119 ;
}
static inline T_1 F_69 ( struct V_7 * V_8 )
{
T_1 V_123 = V_121 - V_8 -> V_2 . V_122 ;
V_123 = ~ V_123 & ~ ( 3 << 30 ) ;
if ( F_67 ( V_8 ) )
V_123 |= ( 1 << 31 ) ;
if ( F_70 ( V_8 ) ||
! ( V_8 -> V_52 & ( V_111 | V_112 | V_124 ) ) )
V_123 |= ( 1 << 30 ) ;
return V_123 ;
}
static inline bool F_71 ( const struct V_32 * V_32 )
{
return V_32 -> V_33 . V_125 <=
V_32 -> V_33 . V_126 ;
}
static inline bool F_72 ( const struct V_7 * V_127 ,
const struct V_7 * V_128 )
{
return ( ( ( ( V_30 T_1 ) V_127 -> V_129 ^ ( V_30 T_1 ) V_128 -> V_129 ) |
( ( V_30 T_1 ) V_127 -> V_130 ^ ( V_30 T_1 ) V_128 -> V_130 ) |
( V_127 -> V_131 ^ V_128 -> V_131 ) ) == 0 ) ;
}
static inline int F_73 ( struct V_7 * V_127 , struct V_7 * V_128 )
{
return ( ( ( V_30 T_1 ) V_127 -> V_129 ^ ( V_30 T_1 ) V_128 -> V_129 ) |
( ( V_30 T_1 ) V_127 -> V_130 ^ ( V_30 T_1 ) V_128 -> V_130 ) |
( V_127 -> V_132 ^ V_128 -> V_132 ) |
( V_127 -> V_59 ^ V_128 -> V_59 ) |
( V_127 -> V_131 ^ V_128 -> V_131 ) |
( V_127 -> V_133 ^ V_128 -> V_133 ) ) == 0 ;
}
static inline int F_74 ( struct V_7 * V_127 , struct V_7 * V_128 )
{
return F_75 ( F_20 ( V_127 -> V_2 . V_4 ) , F_20 ( V_128 -> V_2 . V_4 ) ) ;
}
static inline int F_76 ( struct V_7 * V_110 )
{
return V_110 -> F_14 != F_14 ( F_20 ( V_110 -> V_2 . V_4 ) ) ;
}
static void F_77 ( struct V_32 * V_32 , int V_134 )
{
unsigned int V_21 ;
struct V_7 * V_110 , * V_135 ;
for ( V_21 = 0 ; V_21 <= V_31 ; V_21 ++ ) {
struct V_7 T_7 * * V_136 ;
struct V_7 * V_137 ;
if ( V_134 && F_78 () )
F_79 () ;
V_110 = F_17 ( V_41 [ V_21 ] . V_42 ) ;
if ( ! V_110 )
continue;
F_80 ( F_81 ( V_21 ) ) ;
V_137 = NULL ;
V_136 = & V_41 [ V_21 ] . V_42 ;
V_110 = F_82 ( * V_136 ,
F_83 ( F_81 ( V_21 ) ) ) ;
while ( V_110 ) {
V_135 = F_82 ( V_110 -> V_2 . V_43 ,
F_83 ( F_81 ( V_21 ) ) ) ;
if ( ! V_32 ||
F_75 ( F_20 ( V_110 -> V_2 . V_4 ) , V_32 ) ) {
F_84 ( * V_136 , V_135 ) ;
F_84 ( V_110 -> V_2 . V_43 , V_137 ) ;
V_137 = V_110 ;
} else {
V_136 = & V_110 -> V_2 . V_43 ;
}
V_110 = V_135 ;
}
F_85 ( F_81 ( V_21 ) ) ;
for (; V_137 ; V_137 = V_135 ) {
V_135 = F_82 ( V_137 -> V_2 . V_43 , 1 ) ;
F_61 ( V_137 ) ;
}
}
}
static int F_86 ( const struct V_7 * V_138 , const struct V_7 * V_110 )
{
const struct V_7 * V_139 = V_138 ;
while ( V_139 != V_110 ) {
if ( F_72 ( V_139 , V_110 ) )
return 0 ;
V_139 = F_82 ( V_139 -> V_2 . V_43 , 1 ) ;
}
return V_140 ;
}
static void F_87 ( struct V_32 * V_32 )
{
unsigned char V_141 ;
F_88 ( & V_141 , sizeof( V_141 ) ) ;
F_89 ( V_141 + 1U , & V_32 -> V_33 . F_14 ) ;
}
void F_90 ( struct V_32 * V_32 , int V_142 )
{
F_87 ( V_32 ) ;
if ( V_142 >= 0 )
F_77 ( V_32 , ! F_91 () ) ;
}
void F_92 ( struct V_32 * V_32 )
{
F_77 ( V_32 , ! F_91 () ) ;
}
static void F_93 ( struct V_32 * V_32 )
{
if ( F_94 () )
F_95 ( V_143 L_16 ) ;
F_87 ( V_32 ) ;
}
static int F_96 ( struct V_144 * V_145 )
{
static unsigned long V_146 = V_147 ;
static unsigned long V_148 ;
static int V_149 ;
static int V_150 ;
struct V_7 * V_110 ;
struct V_7 T_7 * * V_151 ;
unsigned long V_152 = V_121 ;
int V_153 ;
int V_154 = F_97 ( & V_69 ) ;
F_98 ( V_80 ) ;
if ( V_152 - V_148 < V_155 &&
V_154 < V_156 ) {
F_98 ( V_81 ) ;
goto V_120;
}
V_154 = F_42 ( & V_69 ) ;
V_153 = V_154 - ( V_157 << V_158 ) ;
if ( V_153 <= 0 ) {
if ( V_150 < V_69 . V_159 )
V_150 = V_69 . V_159 ;
V_153 = V_154 - V_150 ;
if ( V_153 > 0 ) {
V_150 += F_99 (unsigned int, goal >> 1 , rt_hash_mask + 1 ) ;
V_153 = V_154 - V_150 ;
}
} else {
V_153 = F_100 (unsigned int, goal >> 1 , rt_hash_mask + 1 ) ;
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
F_80 ( F_81 ( V_161 ) ) ;
while ( ( V_110 = F_82 ( * V_151 ,
F_83 ( F_81 ( V_161 ) ) ) ) != NULL ) {
if ( ! F_76 ( V_110 ) &&
! F_68 ( V_110 , V_162 , V_146 ) ) {
V_162 >>= 1 ;
V_151 = & V_110 -> V_2 . V_43 ;
continue;
}
* V_151 = V_110 -> V_2 . V_43 ;
F_61 ( V_110 ) ;
V_153 -- ;
}
F_85 ( F_81 ( V_161 ) ) ;
if ( V_153 <= 0 )
break;
}
V_149 = V_161 ;
if ( V_153 <= 0 )
goto V_160;
F_98 ( V_82 ) ;
if ( V_146 == 0 )
break;
V_146 >>= 1 ;
if ( F_97 ( & V_69 ) < V_156 )
goto V_120;
} while ( ! F_91 () && F_101 ( V_121 , V_152 ) );
if ( F_97 ( & V_69 ) < V_156 )
goto V_120;
if ( F_42 ( & V_69 ) < V_156 )
goto V_120;
if ( F_94 () )
F_95 ( V_143 L_17 ) ;
F_98 ( V_83 ) ;
return 1 ;
V_160:
V_146 += V_155 ;
if ( V_146 > V_163 ||
F_97 ( & V_69 ) < V_69 . V_159 ||
F_42 ( & V_69 ) < V_69 . V_159 )
V_146 = V_163 ;
V_120: return 0 ;
}
static int F_102 ( const struct V_7 * V_138 )
{
int V_164 = 0 ;
const struct V_7 * V_110 = V_138 ;
while ( V_110 ) {
V_164 += F_86 ( V_138 , V_110 ) ;
V_110 = F_82 ( V_110 -> V_2 . V_43 , 1 ) ;
}
return V_164 >> V_165 ;
}
static struct V_47 * F_103 ( const struct V_1 * V_2 , const void * V_26 )
{
struct V_166 * V_167 = & V_168 ;
static const T_3 V_169 = 0 ;
struct V_3 * V_4 = V_2 -> V_4 ;
const T_3 * V_170 = V_26 ;
struct V_47 * V_48 ;
#if F_104 ( V_171 ) || F_104 ( V_172 )
if ( V_4 -> type == V_173 )
V_167 = V_174 ;
#endif
if ( V_4 -> V_175 & ( V_176 | V_177 ) )
V_170 = & V_169 ;
V_48 = F_105 ( V_167 , V_4 , * ( V_30 T_1 * ) V_170 ) ;
if ( V_48 )
return V_48 ;
return F_106 ( V_167 , V_170 , V_4 ) ;
}
static int F_107 ( struct V_7 * V_8 )
{
struct V_47 * V_48 = F_103 ( & V_8 -> V_2 , & V_8 -> V_51 ) ;
if ( F_108 ( V_48 ) )
return F_109 ( V_48 ) ;
F_110 ( & V_8 -> V_2 , V_48 ) ;
return 0 ;
}
static struct V_7 * F_111 ( unsigned V_178 , struct V_7 * V_8 ,
struct V_179 * V_180 , int V_181 )
{
struct V_7 * V_110 , * V_182 ;
struct V_7 T_7 * * V_151 , * * V_183 ;
unsigned long V_152 ;
T_1 V_184 ;
int V_185 ;
int V_186 = ! F_91 () ;
V_187:
V_185 = 0 ;
V_184 = ~ ( T_1 ) 0 ;
V_182 = NULL ;
V_183 = NULL ;
V_152 = V_121 ;
if ( ! F_71 ( F_20 ( V_8 -> V_2 . V_4 ) ) ) {
V_8 -> V_2 . V_175 |= V_188 ;
if ( V_8 -> V_189 == V_190 || F_70 ( V_8 ) ) {
int V_191 = F_107 ( V_8 ) ;
if ( V_191 ) {
if ( F_94 () )
F_95 ( V_143
L_18 ) ;
F_64 ( V_8 ) ;
return F_112 ( V_191 ) ;
}
}
goto V_192;
}
V_151 = & V_41 [ V_178 ] . V_42 ;
F_80 ( F_81 ( V_178 ) ) ;
while ( ( V_110 = F_82 ( * V_151 ,
F_83 ( F_81 ( V_178 ) ) ) ) != NULL ) {
if ( F_76 ( V_110 ) ) {
* V_151 = V_110 -> V_2 . V_43 ;
F_61 ( V_110 ) ;
continue;
}
if ( F_73 ( V_110 , V_8 ) && F_74 ( V_110 , V_8 ) ) {
* V_151 = V_110 -> V_2 . V_43 ;
F_84 ( V_110 -> V_2 . V_43 ,
V_41 [ V_178 ] . V_42 ) ;
F_84 ( V_41 [ V_178 ] . V_42 , V_110 ) ;
F_113 ( & V_110 -> V_2 , V_152 ) ;
F_85 ( F_81 ( V_178 ) ) ;
F_63 ( V_8 ) ;
if ( V_180 )
F_114 ( V_180 , & V_110 -> V_2 ) ;
return V_110 ;
}
if ( ! F_15 ( & V_110 -> V_2 . V_53 ) ) {
T_1 V_123 = F_69 ( V_110 ) ;
if ( V_123 <= V_184 ) {
V_182 = V_110 ;
V_183 = V_151 ;
V_184 = V_123 ;
}
}
V_185 ++ ;
V_151 = & V_110 -> V_2 . V_43 ;
}
if ( V_182 ) {
if ( V_185 > V_157 ) {
* V_183 = V_182 -> V_2 . V_43 ;
F_61 ( V_182 ) ;
}
} else {
if ( V_185 > V_193 &&
F_102 ( V_41 [ V_178 ] . V_42 ) > V_193 ) {
struct V_32 * V_32 = F_20 ( V_8 -> V_2 . V_4 ) ;
int V_194 = ++ V_32 -> V_33 . V_125 ;
if ( ! F_71 ( V_32 ) ) {
F_95 ( V_143 L_19 ,
V_8 -> V_2 . V_4 -> V_50 , V_194 ) ;
}
F_93 ( V_32 ) ;
F_85 ( F_81 ( V_178 ) ) ;
V_178 = F_12 ( V_8 -> V_129 , V_8 -> V_130 ,
V_181 , F_14 ( V_32 ) ) ;
goto V_187;
}
}
if ( V_8 -> V_189 == V_190 || F_70 ( V_8 ) ) {
int V_191 = F_107 ( V_8 ) ;
if ( V_191 ) {
F_85 ( F_81 ( V_178 ) ) ;
if ( V_191 != - V_195 ) {
F_63 ( V_8 ) ;
return F_112 ( V_191 ) ;
}
if ( V_186 -- > 0 ) {
int V_196 = V_157 ;
int V_197 = V_155 ;
V_157 = 1 ;
V_155 = 0 ;
F_96 ( & V_69 ) ;
V_155 = V_197 ;
V_157 = V_196 ;
goto V_187;
}
if ( F_94 () )
F_95 ( V_143 L_20 ) ;
F_63 ( V_8 ) ;
return F_112 ( - V_195 ) ;
}
}
V_8 -> V_2 . V_43 = V_41 [ V_178 ] . V_42 ;
F_84 ( V_41 [ V_178 ] . V_42 , V_8 ) ;
F_85 ( F_81 ( V_178 ) ) ;
V_192:
if ( V_180 )
F_114 ( V_180 , & V_8 -> V_2 ) ;
return V_8 ;
}
static T_1 F_115 ( void )
{
return F_15 ( & V_198 ) ;
}
void F_3 ( struct V_7 * V_8 , T_3 V_26 , int V_199 )
{
struct V_9 * V_10 ;
V_10 = F_116 ( V_26 , V_199 ) ;
if ( V_10 && F_6 ( & V_8 -> V_10 , NULL , V_10 ) != NULL )
F_117 ( V_10 ) ;
else
V_8 -> F_115 = F_115 () ;
}
static void F_118 ( struct V_200 * V_201 )
{
static F_119 ( V_202 ) ;
static T_1 V_203 ;
T_1 V_204 ;
F_80 ( & V_202 ) ;
V_204 = F_120 ( ( V_30 T_3 ) V_203 ^ V_201 -> V_26 ) ;
V_201 -> V_205 = F_121 ( V_204 & 0xFFFF ) ;
V_203 = V_204 ;
F_85 ( & V_202 ) ;
}
void F_122 ( struct V_200 * V_201 , struct V_1 * V_2 , int V_206 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
if ( V_8 ) {
if ( V_8 -> V_10 == NULL )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
if ( V_8 -> V_10 ) {
V_201 -> V_205 = F_121 ( F_123 ( V_8 -> V_10 , V_206 ) ) ;
return;
}
} else
F_95 ( V_207 L_21 ,
F_124 ( 0 ) ) ;
F_118 ( V_201 ) ;
}
static void F_125 ( unsigned V_178 , struct V_7 * V_8 )
{
struct V_7 T_7 * * V_151 ;
struct V_7 * V_139 ;
V_151 = & V_41 [ V_178 ] . V_42 ;
F_80 ( F_81 ( V_178 ) ) ;
F_64 ( V_8 ) ;
while ( ( V_139 = F_82 ( * V_151 ,
F_83 ( F_81 ( V_178 ) ) ) ) != NULL ) {
if ( V_139 == V_8 || F_76 ( V_139 ) ) {
* V_151 = V_139 -> V_2 . V_43 ;
F_61 ( V_139 ) ;
continue;
}
V_151 = & V_139 -> V_2 . V_43 ;
}
F_85 ( F_81 ( V_178 ) ) ;
}
void F_126 ( T_3 V_208 , T_3 V_26 , T_3 V_209 ,
T_3 V_27 , struct V_3 * V_4 )
{
struct V_210 * V_211 = F_127 ( V_4 ) ;
struct V_9 * V_10 ;
struct V_32 * V_32 ;
if ( ! V_211 )
return;
V_32 = F_20 ( V_4 ) ;
if ( V_209 == V_208 || ! F_128 ( V_211 ) ||
F_129 ( V_209 ) || F_130 ( V_209 ) ||
F_131 ( V_209 ) )
goto V_212;
if ( ! F_132 ( V_211 ) ) {
if ( ! F_133 ( V_211 , V_209 , V_208 ) )
goto V_212;
if ( F_134 ( V_211 ) && F_135 ( V_209 , V_4 ) )
goto V_212;
} else {
if ( F_136 ( V_32 , V_209 ) != V_190 )
goto V_212;
}
V_10 = F_116 ( V_26 , 1 ) ;
if ( V_10 ) {
V_10 -> V_213 . V_214 = V_209 ;
F_117 ( V_10 ) ;
F_137 ( & V_198 ) ;
}
return;
V_212:
#ifdef F_138
if ( F_139 ( V_211 ) && F_94 () )
F_95 ( V_215 L_22
L_23 ,
& V_208 , V_4 -> V_50 , & V_209 ,
& V_27 , & V_26 ) ;
#endif
;
}
static bool F_140 ( struct V_9 * V_10 )
{
unsigned long V_216 = F_141 ( V_10 -> V_115 ) ;
return V_216 &&
F_142 ( V_121 , V_216 ) &&
F_6 ( & V_10 -> V_115 , V_216 , 0 ) == V_216 ;
}
static bool F_143 ( struct V_9 * V_10 )
{
unsigned long V_216 = F_141 ( V_10 -> V_115 ) ;
return V_216 &&
F_6 ( & V_10 -> V_115 , V_216 , 0 ) == V_216 ;
}
static struct V_1 * F_144 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
struct V_1 * V_119 = V_2 ;
if ( V_8 ) {
if ( V_2 -> V_217 > 0 ) {
F_64 ( V_8 ) ;
V_119 = NULL ;
} else if ( V_8 -> V_52 & V_113 ) {
unsigned V_178 = F_12 ( V_8 -> V_129 , V_8 -> V_130 ,
V_8 -> V_133 ,
F_14 ( F_20 ( V_2 -> V_4 ) ) ) ;
F_125 ( V_178 , V_8 ) ;
V_119 = NULL ;
} else if ( V_8 -> V_10 && F_140 ( V_8 -> V_10 ) ) {
F_145 ( V_2 , V_218 , V_8 -> V_10 -> V_219 ) ;
}
}
return V_119 ;
}
void F_146 ( struct V_179 * V_180 )
{
struct V_7 * V_8 = F_147 ( V_180 ) ;
struct V_210 * V_211 ;
struct V_9 * V_10 ;
int V_220 ;
F_148 () ;
V_211 = F_127 ( V_8 -> V_2 . V_4 ) ;
if ( ! V_211 || ! F_149 ( V_211 ) ) {
F_150 () ;
return;
}
V_220 = F_139 ( V_211 ) ;
F_150 () ;
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
V_10 = V_8 -> V_10 ;
if ( ! V_10 ) {
F_151 ( V_180 , V_221 , V_222 , V_8 -> V_51 ) ;
return;
}
if ( F_152 ( V_121 , V_10 -> V_223 + V_224 ) )
V_10 -> V_225 = 0 ;
if ( V_10 -> V_225 >= V_226 ) {
V_10 -> V_223 = V_121 ;
return;
}
if ( V_10 -> V_225 == 0 ||
F_152 ( V_121 ,
( V_10 -> V_223 +
( V_227 << V_10 -> V_225 ) ) ) ) {
F_151 ( V_180 , V_221 , V_222 , V_8 -> V_51 ) ;
V_10 -> V_223 = V_121 ;
++ V_10 -> V_225 ;
#ifdef F_138
if ( V_220 &&
V_10 -> V_225 == V_226 &&
F_94 () )
F_95 ( V_143 L_24 ,
& F_153 ( V_180 ) -> V_27 , V_8 -> V_228 ,
& V_8 -> V_12 , & V_8 -> V_51 ) ;
#endif
}
}
static int F_154 ( struct V_179 * V_180 )
{
struct V_7 * V_8 = F_147 ( V_180 ) ;
struct V_9 * V_10 ;
unsigned long V_152 ;
bool V_229 ;
int V_230 ;
switch ( V_8 -> V_2 . error ) {
case V_231 :
default:
goto V_120;
case V_232 :
V_230 = V_233 ;
break;
case V_234 :
V_230 = V_235 ;
F_155 ( F_20 ( V_8 -> V_2 . V_4 ) ,
V_236 ) ;
break;
case V_237 :
V_230 = V_238 ;
break;
}
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
V_10 = V_8 -> V_10 ;
V_229 = true ;
if ( V_10 ) {
V_152 = V_121 ;
V_10 -> V_225 += V_152 - V_10 -> V_223 ;
if ( V_10 -> V_225 > V_239 )
V_10 -> V_225 = V_239 ;
V_10 -> V_223 = V_152 ;
if ( V_10 -> V_225 >= V_240 )
V_10 -> V_225 -= V_240 ;
else
V_229 = false ;
}
if ( V_229 )
F_151 ( V_180 , V_241 , V_230 , 0 ) ;
V_120: F_156 ( V_180 ) ;
return 0 ;
}
static inline unsigned short F_157 ( unsigned short V_242 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < F_158 ( V_243 ) ; V_21 ++ )
if ( V_242 > V_243 [ V_21 ] )
return V_243 [ V_21 ] ;
return 68 ;
}
unsigned short F_159 ( struct V_32 * V_32 , const struct V_200 * V_201 ,
unsigned short V_244 ,
struct V_3 * V_4 )
{
unsigned short V_242 = F_160 ( V_201 -> V_245 ) ;
unsigned short V_246 = 0 ;
struct V_9 * V_10 ;
V_10 = F_116 ( V_201 -> V_26 , 1 ) ;
if ( V_10 ) {
unsigned short V_247 = V_244 ;
if ( V_244 < 68 || V_244 >= V_242 ) {
if ( V_247 == 0 &&
V_242 >= 68 + ( V_201 -> V_248 << 2 ) )
V_242 -= V_201 -> V_248 << 2 ;
V_247 = F_157 ( V_242 ) ;
}
if ( V_247 < V_249 )
V_247 = V_249 ;
if ( ! V_10 -> V_115 || V_247 < V_10 -> V_250 ) {
unsigned long V_115 ;
V_115 = V_121 + V_251 ;
if ( ! V_115 )
V_115 = 1UL ;
V_246 = V_247 ;
V_10 -> V_250 = V_247 ;
V_10 -> V_115 = V_115 ;
}
F_117 ( V_10 ) ;
F_137 ( & V_198 ) ;
}
return V_246 ? : V_244 ;
}
static void F_161 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned long V_252 = F_141 ( V_10 -> V_115 ) ;
if ( ! V_252 )
return;
if ( F_162 ( V_121 , V_252 ) ) {
T_1 V_253 = F_163 ( V_2 ) ;
if ( V_10 -> V_250 < V_253 ) {
if ( ! V_10 -> V_219 )
V_10 -> V_219 = F_164 ( V_2 , V_218 ) ;
F_145 ( V_2 , V_218 , V_10 -> V_250 ) ;
}
} else if ( F_6 ( & V_10 -> V_115 , V_252 , 0 ) == V_252 )
F_145 ( V_2 , V_218 , V_10 -> V_219 ) ;
}
static void F_165 ( struct V_1 * V_2 , T_1 V_247 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
struct V_9 * V_10 ;
F_166 ( V_2 ) ;
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 1 ) ;
V_10 = V_8 -> V_10 ;
if ( V_10 ) {
unsigned long V_115 = F_141 ( V_10 -> V_115 ) ;
if ( V_247 < V_249 )
V_247 = V_249 ;
if ( ! V_115 || V_247 < V_10 -> V_250 ) {
V_115 = V_121 + V_251 ;
if ( ! V_115 )
V_115 = 1UL ;
V_10 -> V_250 = V_247 ;
V_10 -> V_115 = V_115 ;
F_137 ( & V_198 ) ;
V_8 -> F_115 = F_115 () ;
}
F_161 ( V_2 , V_10 ) ;
}
}
static int F_167 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
T_3 V_254 = V_8 -> V_51 ;
struct V_47 * V_48 , * V_255 ;
F_166 ( & V_8 -> V_2 ) ;
V_8 -> V_51 = V_10 -> V_213 . V_214 ;
V_48 = F_103 ( & V_8 -> V_2 , & V_8 -> V_51 ) ;
if ( F_108 ( V_48 ) )
return F_109 ( V_48 ) ;
V_255 = F_168 ( & V_8 -> V_2 . V_256 , V_48 ) ;
if ( V_255 )
F_169 ( V_255 ) ;
if ( ! V_48 || ! ( V_48 -> V_60 & V_257 ) ) {
if ( V_48 )
F_170 ( V_48 , NULL ) ;
V_8 -> V_51 = V_254 ;
return - V_258 ;
} else {
V_8 -> V_52 |= V_113 ;
F_171 ( V_259 , V_48 ) ;
}
return 0 ;
}
static struct V_1 * F_172 ( struct V_1 * V_2 , T_1 V_260 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
if ( F_76 ( V_8 ) )
return NULL ;
if ( V_8 -> F_115 != F_115 () ) {
struct V_9 * V_10 ;
if ( ! V_8 -> V_10 )
F_3 ( V_8 , V_8 -> V_12 , 0 ) ;
V_10 = V_8 -> V_10 ;
if ( V_10 ) {
F_161 ( V_2 , V_10 ) ;
if ( V_10 -> V_213 . V_214 &&
V_10 -> V_213 . V_214 != V_8 -> V_51 ) {
if ( F_167 ( V_2 , V_10 ) )
return NULL ;
}
}
V_8 -> F_115 = F_115 () ;
}
return V_2 ;
}
static void F_173 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
struct V_9 * V_10 = V_8 -> V_10 ;
if ( V_8 -> V_20 ) {
F_7 ( V_8 -> V_20 ) ;
V_8 -> V_20 = NULL ;
}
if ( V_10 ) {
V_8 -> V_10 = NULL ;
F_117 ( V_10 ) ;
}
}
static void F_174 ( struct V_179 * V_180 )
{
struct V_7 * V_8 ;
F_151 ( V_180 , V_241 , V_233 , 0 ) ;
V_8 = F_147 ( V_180 ) ;
if ( V_8 && V_8 -> V_10 && F_143 ( V_8 -> V_10 ) )
F_145 ( & V_8 -> V_2 , V_218 , V_8 -> V_10 -> V_219 ) ;
}
static int F_175 ( struct V_179 * V_180 )
{
F_95 ( V_207 L_25 ,
& F_153 ( V_180 ) -> V_27 , & F_153 ( V_180 ) -> V_26 ,
V_180 -> V_4 ? V_180 -> V_4 -> V_50 : L_26 ) ;
F_156 ( V_180 ) ;
F_176 ( 1 ) ;
return 0 ;
}
void F_177 ( T_8 * V_261 , struct V_179 * V_180 , struct V_7 * V_8 )
{
T_3 V_89 ;
if ( F_70 ( V_8 ) )
V_89 = F_153 ( V_180 ) -> V_27 ;
else {
struct V_262 V_263 ;
struct V_264 V_265 ;
struct V_200 * V_201 ;
V_201 = F_153 ( V_180 ) ;
memset ( & V_265 , 0 , sizeof( V_265 ) ) ;
V_265 . V_26 = V_201 -> V_26 ;
V_265 . V_27 = V_201 -> V_27 ;
V_265 . V_266 = F_178 ( V_201 -> V_267 ) ;
V_265 . V_268 = V_8 -> V_2 . V_4 -> V_181 ;
V_265 . V_269 = V_180 -> V_4 -> V_181 ;
V_265 . V_270 = V_180 -> V_271 ;
F_148 () ;
if ( F_179 ( F_20 ( V_8 -> V_2 . V_4 ) , & V_265 , & V_263 ) == 0 )
V_89 = F_180 ( F_20 ( V_8 -> V_2 . V_4 ) , V_263 ) ;
else
V_89 = F_181 ( V_8 -> V_2 . V_4 , V_8 -> V_51 ,
V_272 ) ;
F_150 () ;
}
memcpy ( V_261 , & V_89 , 4 ) ;
}
static void F_182 ( struct V_7 * V_8 , T_1 V_273 )
{
if ( ! ( V_8 -> V_2 . V_274 & 0xFFFF ) )
V_8 -> V_2 . V_274 |= V_273 & 0xFFFF ;
if ( ! ( V_8 -> V_2 . V_274 & 0xFFFF0000 ) )
V_8 -> V_2 . V_274 |= V_273 & 0xFFFF0000 ;
}
static unsigned int F_183 ( const struct V_1 * V_2 )
{
unsigned int V_275 = F_164 ( V_2 , V_276 ) ;
if ( V_275 == 0 ) {
V_275 = F_100 (unsigned int, dst->dev->mtu - 40 ,
ip_rt_min_advmss) ;
if ( V_275 > 65535 - 40 )
V_275 = 65535 - 40 ;
}
return V_275 ;
}
static unsigned int F_184 ( const struct V_1 * V_2 )
{
unsigned int V_247 = V_2 -> V_4 -> V_247 ;
if ( F_185 ( F_186 ( V_2 , V_218 ) ) ) {
const struct V_7 * V_8 = ( const struct V_7 * ) V_2 ;
if ( V_8 -> V_51 != V_8 -> V_12 && V_247 > 576 )
V_247 = 576 ;
}
if ( V_247 > V_277 )
V_247 = V_277 ;
return V_247 ;
}
static void F_187 ( struct V_7 * V_8 , const struct V_264 * V_265 ,
struct V_278 * V_20 )
{
struct V_9 * V_10 ;
int V_199 = 0 ;
if ( V_265 && ( V_265 -> V_279 & V_280 ) )
V_199 = 1 ;
V_8 -> V_10 = V_10 = F_116 ( V_8 -> V_12 , V_199 ) ;
if ( V_10 ) {
V_8 -> F_115 = F_115 () ;
if ( F_5 ( V_10 ) )
memcpy ( V_10 -> V_16 , V_20 -> V_281 ,
sizeof( T_1 ) * V_17 ) ;
F_188 ( & V_8 -> V_2 , V_10 -> V_16 , false ) ;
F_161 ( & V_8 -> V_2 , V_10 ) ;
if ( V_10 -> V_213 . V_214 &&
V_10 -> V_213 . V_214 != V_8 -> V_51 ) {
V_8 -> V_51 = V_10 -> V_213 . V_214 ;
V_8 -> V_52 |= V_113 ;
}
} else {
if ( V_20 -> V_281 != ( T_1 * ) V_282 ) {
V_8 -> V_20 = V_20 ;
F_137 ( & V_20 -> V_283 ) ;
}
F_188 ( & V_8 -> V_2 , V_20 -> V_281 , true ) ;
}
}
static void F_189 ( struct V_7 * V_8 , const struct V_264 * V_265 ,
const struct V_262 * V_263 ,
struct V_278 * V_20 , T_9 type , T_1 V_284 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
if ( V_20 ) {
if ( F_190 ( * V_263 ) &&
F_191 ( * V_263 ) . V_285 == V_286 )
V_8 -> V_51 = F_190 ( * V_263 ) ;
F_187 ( V_8 , V_265 , V_20 ) ;
#ifdef F_56
V_2 -> V_274 = F_191 ( * V_263 ) . V_287 ;
#endif
}
if ( F_163 ( V_2 ) > V_277 )
F_145 ( V_2 , V_218 , V_277 ) ;
if ( F_164 ( V_2 , V_276 ) > 65535 - 40 )
F_145 ( V_2 , V_276 , 65535 - 40 ) ;
#ifdef F_56
#ifdef F_192
F_182 ( V_8 , F_193 ( V_263 ) ) ;
#endif
F_182 ( V_8 , V_284 ) ;
#endif
}
static struct V_7 * F_194 ( struct V_3 * V_4 ,
bool V_288 , bool V_289 )
{
return F_195 ( & V_69 , V_4 , 1 , - 1 ,
V_290 |
( V_288 ? V_291 : 0 ) |
( V_289 ? V_292 : 0 ) ) ;
}
static int F_196 ( struct V_179 * V_180 , T_3 V_26 , T_3 V_27 ,
T_8 V_267 , struct V_3 * V_4 , int V_293 )
{
unsigned int V_178 ;
struct V_7 * V_110 ;
T_3 V_294 ;
struct V_210 * V_211 = F_127 ( V_4 ) ;
T_1 V_284 = 0 ;
int V_191 ;
if ( V_211 == NULL )
return - V_231 ;
if ( F_129 ( V_27 ) || F_130 ( V_27 ) ||
F_197 ( V_27 ) || V_180 -> V_295 != F_121 ( V_296 ) )
goto V_297;
if ( F_131 ( V_27 ) ) {
if ( ! F_198 ( V_26 ) )
goto V_297;
V_294 = F_181 ( V_4 , 0 , V_286 ) ;
} else {
V_191 = F_199 ( V_180 , V_27 , 0 , V_267 , 0 , V_4 , & V_294 ,
& V_284 ) ;
if ( V_191 < 0 )
goto V_298;
}
V_110 = F_194 ( V_299 . V_300 ,
F_200 ( V_211 , V_301 ) , false ) ;
if ( ! V_110 )
goto V_302;
#ifdef F_56
V_110 -> V_2 . V_274 = V_284 ;
#endif
V_110 -> V_2 . V_303 = F_175 ;
V_110 -> V_129 = V_26 ;
V_110 -> V_130 = V_27 ;
V_110 -> F_14 = F_14 ( F_20 ( V_4 ) ) ;
V_110 -> V_52 = V_112 ;
V_110 -> V_189 = V_304 ;
V_110 -> V_59 = V_267 ;
V_110 -> V_12 = V_26 ;
V_110 -> V_55 = V_27 ;
V_110 -> V_131 = V_4 -> V_181 ;
V_110 -> V_228 = V_4 -> V_181 ;
V_110 -> V_133 = 0 ;
V_110 -> V_132 = V_180 -> V_271 ;
V_110 -> V_51 = V_26 ;
V_110 -> V_62 = V_294 ;
V_110 -> F_115 = 0 ;
V_110 -> V_10 = NULL ;
V_110 -> V_20 = NULL ;
if ( V_293 ) {
V_110 -> V_2 . V_305 = V_306 ;
V_110 -> V_52 |= V_124 ;
}
#ifdef F_201
if ( ! F_198 ( V_26 ) && F_202 ( V_211 ) )
V_110 -> V_2 . V_305 = V_307 ;
#endif
F_98 ( V_72 ) ;
V_178 = F_12 ( V_26 , V_27 , V_4 -> V_181 , F_14 ( F_20 ( V_4 ) ) ) ;
V_110 = F_111 ( V_178 , V_110 , V_180 , V_4 -> V_181 ) ;
return F_108 ( V_110 ) ? F_109 ( V_110 ) : 0 ;
V_302:
return - V_195 ;
V_297:
return - V_231 ;
V_298:
return V_191 ;
}
static void F_203 ( struct V_3 * V_4 ,
struct V_210 * V_211 ,
struct V_179 * V_180 ,
T_3 V_26 ,
T_3 V_27 )
{
F_98 ( V_76 ) ;
#ifdef F_138
if ( F_139 ( V_211 ) && F_94 () ) {
F_95 ( V_143 L_27 ,
& V_26 , & V_27 , V_4 -> V_50 ) ;
if ( V_4 -> V_308 && F_204 ( V_180 ) ) {
int V_21 ;
const unsigned char * V_11 = F_205 ( V_180 ) ;
F_95 ( V_143 L_28 ) ;
for ( V_21 = 0 ; V_21 < V_4 -> V_308 ; V_21 ++ , V_11 ++ ) {
F_95 ( L_29 , * V_11 ) ;
if ( V_21 < ( V_4 -> V_308 - 1 ) )
F_95 ( L_30 ) ;
}
F_95 ( L_31 ) ;
}
}
#endif
}
static int F_206 ( struct V_179 * V_180 ,
const struct V_262 * V_263 ,
struct V_210 * V_211 ,
T_3 V_26 , T_3 V_27 , T_1 V_267 ,
struct V_7 * * V_309 )
{
struct V_7 * V_110 ;
int V_191 ;
struct V_210 * V_310 ;
unsigned int V_175 = 0 ;
T_3 V_294 ;
T_1 V_284 ;
V_310 = F_127 ( F_207 ( * V_263 ) ) ;
if ( V_310 == NULL ) {
if ( F_94 () )
F_95 ( V_311 L_32 \
L_33 ) ;
return - V_231 ;
}
V_191 = F_199 ( V_180 , V_27 , V_26 , V_267 , F_208 ( * V_263 ) ,
V_211 -> V_4 , & V_294 , & V_284 ) ;
if ( V_191 < 0 ) {
F_203 ( V_211 -> V_4 , V_211 , V_180 , V_26 ,
V_27 ) ;
goto V_312;
}
if ( V_191 )
V_175 |= V_313 ;
if ( V_310 == V_211 && V_191 &&
( F_132 ( V_310 ) ||
F_133 ( V_310 , V_27 , F_190 ( * V_263 ) ) ) )
V_175 |= V_314 ;
if ( V_180 -> V_295 != F_121 ( V_296 ) ) {
if ( V_310 == V_211 &&
F_209 ( V_211 ) == 0 ) {
V_191 = - V_231 ;
goto V_312;
}
}
V_110 = F_194 ( V_310 -> V_4 ,
F_200 ( V_211 , V_301 ) ,
F_200 ( V_310 , V_315 ) ) ;
if ( ! V_110 ) {
V_191 = - V_195 ;
goto V_312;
}
V_110 -> V_129 = V_26 ;
V_110 -> V_130 = V_27 ;
V_110 -> F_14 = F_14 ( F_20 ( V_110 -> V_2 . V_4 ) ) ;
V_110 -> V_52 = V_175 ;
V_110 -> V_189 = V_263 -> type ;
V_110 -> V_59 = V_267 ;
V_110 -> V_12 = V_26 ;
V_110 -> V_55 = V_27 ;
V_110 -> V_131 = V_211 -> V_4 -> V_181 ;
V_110 -> V_228 = V_211 -> V_4 -> V_181 ;
V_110 -> V_133 = 0 ;
V_110 -> V_132 = V_180 -> V_271 ;
V_110 -> V_51 = V_26 ;
V_110 -> V_62 = V_294 ;
V_110 -> F_115 = 0 ;
V_110 -> V_10 = NULL ;
V_110 -> V_20 = NULL ;
V_110 -> V_2 . V_305 = V_316 ;
V_110 -> V_2 . V_303 = V_317 ;
F_189 ( V_110 , NULL , V_263 , V_263 -> V_20 , V_263 -> type , V_284 ) ;
* V_309 = V_110 ;
V_191 = 0 ;
V_312:
return V_191 ;
}
static int F_210 ( struct V_179 * V_180 ,
struct V_262 * V_263 ,
const struct V_264 * V_265 ,
struct V_210 * V_211 ,
T_3 V_26 , T_3 V_27 , T_1 V_267 )
{
struct V_7 * V_110 = NULL ;
int V_191 ;
unsigned V_178 ;
#ifdef F_211
if ( V_263 -> V_20 && V_263 -> V_20 -> V_318 > 1 )
F_212 ( V_263 ) ;
#endif
V_191 = F_206 ( V_180 , V_263 , V_211 , V_26 , V_27 , V_267 , & V_110 ) ;
if ( V_191 )
return V_191 ;
V_178 = F_12 ( V_26 , V_27 , V_265 -> V_269 ,
F_14 ( F_20 ( V_110 -> V_2 . V_4 ) ) ) ;
V_110 = F_111 ( V_178 , V_110 , V_180 , V_265 -> V_269 ) ;
if ( F_108 ( V_110 ) )
return F_109 ( V_110 ) ;
return 0 ;
}
static int F_213 ( struct V_179 * V_180 , T_3 V_26 , T_3 V_27 ,
T_8 V_267 , struct V_3 * V_4 )
{
struct V_262 V_263 ;
struct V_210 * V_211 = F_127 ( V_4 ) ;
struct V_264 V_265 ;
unsigned V_175 = 0 ;
T_1 V_284 = 0 ;
struct V_7 * V_110 ;
unsigned V_178 ;
T_3 V_294 ;
int V_191 = - V_231 ;
struct V_32 * V_32 = F_20 ( V_4 ) ;
if ( ! V_211 )
goto V_120;
if ( F_129 ( V_27 ) || F_130 ( V_27 ) ||
F_197 ( V_27 ) )
goto V_319;
if ( F_130 ( V_26 ) || ( V_27 == 0 && V_26 == 0 ) )
goto V_320;
if ( F_131 ( V_27 ) )
goto V_319;
if ( F_131 ( V_26 ) || F_197 ( V_26 ) )
goto V_321;
V_265 . V_268 = 0 ;
V_265 . V_269 = V_4 -> V_181 ;
V_265 . V_270 = V_180 -> V_271 ;
V_265 . V_266 = V_267 ;
V_265 . V_322 = V_272 ;
V_265 . V_26 = V_26 ;
V_265 . V_27 = V_27 ;
V_191 = F_179 ( V_32 , & V_265 , & V_263 ) ;
if ( V_191 != 0 ) {
if ( ! F_214 ( V_211 ) )
goto V_323;
goto V_324;
}
F_98 ( V_71 ) ;
if ( V_263 . type == V_325 )
goto V_320;
if ( V_263 . type == V_326 ) {
V_191 = F_199 ( V_180 , V_27 , V_26 , V_267 ,
V_32 -> V_300 -> V_181 ,
V_4 , & V_294 , & V_284 ) ;
if ( V_191 < 0 )
goto V_327;
if ( V_191 )
V_175 |= V_313 ;
V_294 = V_26 ;
goto V_328;
}
if ( ! F_214 ( V_211 ) )
goto V_323;
if ( V_263 . type != V_190 )
goto V_321;
V_191 = F_210 ( V_180 , & V_263 , & V_265 , V_211 , V_26 , V_27 , V_267 ) ;
V_120: return V_191 ;
V_320:
if ( V_180 -> V_295 != F_121 ( V_296 ) )
goto V_297;
if ( F_131 ( V_27 ) )
V_294 = F_181 ( V_4 , 0 , V_286 ) ;
else {
V_191 = F_199 ( V_180 , V_27 , 0 , V_267 , 0 , V_4 , & V_294 ,
& V_284 ) ;
if ( V_191 < 0 )
goto V_327;
if ( V_191 )
V_175 |= V_313 ;
}
V_175 |= V_111 ;
V_263 . type = V_325 ;
F_98 ( V_74 ) ;
V_328:
V_110 = F_194 ( V_32 -> V_300 ,
F_200 ( V_211 , V_301 ) , false ) ;
if ( ! V_110 )
goto V_302;
V_110 -> V_2 . V_305 = V_306 ;
V_110 -> V_2 . V_303 = F_175 ;
#ifdef F_56
V_110 -> V_2 . V_274 = V_284 ;
#endif
V_110 -> V_129 = V_26 ;
V_110 -> V_130 = V_27 ;
V_110 -> F_14 = F_14 ( V_32 ) ;
V_110 -> V_52 = V_175 | V_124 ;
V_110 -> V_189 = V_263 . type ;
V_110 -> V_59 = V_267 ;
V_110 -> V_12 = V_26 ;
V_110 -> V_55 = V_27 ;
#ifdef F_56
V_110 -> V_2 . V_274 = V_284 ;
#endif
V_110 -> V_131 = V_4 -> V_181 ;
V_110 -> V_228 = V_4 -> V_181 ;
V_110 -> V_133 = 0 ;
V_110 -> V_132 = V_180 -> V_271 ;
V_110 -> V_51 = V_26 ;
V_110 -> V_62 = V_294 ;
V_110 -> F_115 = 0 ;
V_110 -> V_10 = NULL ;
V_110 -> V_20 = NULL ;
if ( V_263 . type == V_329 ) {
V_110 -> V_2 . V_305 = F_154 ;
V_110 -> V_2 . error = - V_191 ;
V_110 -> V_52 &= ~ V_124 ;
}
V_178 = F_12 ( V_26 , V_27 , V_265 . V_269 , F_14 ( V_32 ) ) ;
V_110 = F_111 ( V_178 , V_110 , V_180 , V_265 . V_269 ) ;
V_191 = 0 ;
if ( F_108 ( V_110 ) )
V_191 = F_109 ( V_110 ) ;
goto V_120;
V_324:
F_98 ( V_73 ) ;
V_294 = F_181 ( V_4 , 0 , V_272 ) ;
V_263 . type = V_329 ;
if ( V_191 == - V_330 )
V_191 = - V_234 ;
goto V_328;
V_321:
F_98 ( V_75 ) ;
#ifdef F_138
if ( F_139 ( V_211 ) && F_94 () )
F_95 ( V_143 L_34 ,
& V_26 , & V_27 , V_4 -> V_50 ) ;
#endif
V_323:
V_191 = - V_232 ;
goto V_120;
V_297:
V_191 = - V_231 ;
goto V_120;
V_302:
V_191 = - V_195 ;
goto V_120;
V_319:
V_191 = - V_231 ;
V_327:
F_203 ( V_4 , V_211 , V_180 , V_26 , V_27 ) ;
goto V_120;
}
int F_215 ( struct V_179 * V_180 , T_3 V_26 , T_3 V_27 ,
T_8 V_267 , struct V_3 * V_4 , bool V_331 )
{
struct V_7 * V_110 ;
unsigned V_178 ;
int V_332 = V_4 -> V_181 ;
struct V_32 * V_32 ;
int V_263 ;
V_32 = F_20 ( V_4 ) ;
F_148 () ;
if ( ! F_71 ( V_32 ) )
goto V_333;
V_267 &= V_334 ;
V_178 = F_12 ( V_26 , V_27 , V_332 , F_14 ( V_32 ) ) ;
for ( V_110 = F_216 ( V_41 [ V_178 ] . V_42 ) ; V_110 ;
V_110 = F_216 ( V_110 -> V_2 . V_43 ) ) {
if ( ( ( ( V_30 T_1 ) V_110 -> V_129 ^ ( V_30 T_1 ) V_26 ) |
( ( V_30 T_1 ) V_110 -> V_130 ^ ( V_30 T_1 ) V_27 ) |
( V_110 -> V_131 ^ V_332 ) |
( V_110 -> V_59 ^ V_267 ) ) == 0 &&
V_110 -> V_132 == V_180 -> V_271 &&
F_75 ( F_20 ( V_110 -> V_2 . V_4 ) , V_32 ) &&
! F_76 ( V_110 ) ) {
if ( V_331 ) {
F_217 ( & V_110 -> V_2 , V_121 ) ;
F_218 ( V_180 , & V_110 -> V_2 ) ;
} else {
F_113 ( & V_110 -> V_2 , V_121 ) ;
F_114 ( V_180 , & V_110 -> V_2 ) ;
}
F_98 ( V_70 ) ;
F_150 () ;
return 0 ;
}
F_98 ( V_84 ) ;
}
V_333:
if ( F_129 ( V_26 ) ) {
struct V_210 * V_211 = F_127 ( V_4 ) ;
if ( V_211 ) {
int V_293 = F_219 ( V_211 , V_26 , V_27 ,
F_153 ( V_180 ) -> V_295 ) ;
if ( V_293
#ifdef F_201
||
( ! F_198 ( V_26 ) &&
F_202 ( V_211 ) )
#endif
) {
int V_263 = F_196 ( V_180 , V_26 , V_27 ,
V_267 , V_4 , V_293 ) ;
F_150 () ;
return V_263 ;
}
}
F_150 () ;
return - V_231 ;
}
V_263 = F_213 ( V_180 , V_26 , V_27 , V_267 , V_4 ) ;
F_150 () ;
return V_263 ;
}
static struct V_7 * F_220 ( const struct V_262 * V_263 ,
const struct V_264 * V_265 ,
T_3 V_335 , T_3 V_336 ,
int V_337 , struct V_3 * V_338 ,
unsigned int V_175 )
{
struct V_278 * V_20 = V_263 -> V_20 ;
T_1 V_267 = F_221 ( V_265 ) ;
struct V_210 * V_211 ;
T_9 type = V_263 -> type ;
struct V_7 * V_110 ;
if ( F_197 ( V_265 -> V_27 ) && ! ( V_338 -> V_175 & V_176 ) )
return F_112 ( - V_231 ) ;
if ( F_130 ( V_265 -> V_26 ) )
type = V_325 ;
else if ( F_129 ( V_265 -> V_26 ) )
type = V_304 ;
else if ( F_131 ( V_265 -> V_26 ) )
return F_112 ( - V_231 ) ;
if ( V_338 -> V_175 & V_176 )
V_175 |= V_124 ;
V_211 = F_127 ( V_338 ) ;
if ( ! V_211 )
return F_112 ( - V_231 ) ;
if ( type == V_325 ) {
V_175 |= V_111 | V_124 ;
V_20 = NULL ;
} else if ( type == V_304 ) {
V_175 |= V_112 | V_124 ;
if ( ! F_219 ( V_211 , V_265 -> V_26 , V_265 -> V_27 ,
V_265 -> V_339 ) )
V_175 &= ~ V_124 ;
if ( V_20 && V_263 -> V_340 < 4 )
V_20 = NULL ;
}
V_110 = F_194 ( V_338 ,
F_200 ( V_211 , V_301 ) ,
F_200 ( V_211 , V_315 ) ) ;
if ( ! V_110 )
return F_112 ( - V_195 ) ;
V_110 -> V_2 . V_303 = V_317 ;
V_110 -> V_129 = V_335 ;
V_110 -> V_130 = V_336 ;
V_110 -> F_14 = F_14 ( F_20 ( V_338 ) ) ;
V_110 -> V_52 = V_175 ;
V_110 -> V_189 = type ;
V_110 -> V_59 = V_267 ;
V_110 -> V_12 = V_265 -> V_26 ;
V_110 -> V_55 = V_265 -> V_27 ;
V_110 -> V_131 = 0 ;
V_110 -> V_228 = V_337 ? : V_338 -> V_181 ;
V_110 -> V_133 = V_337 ;
V_110 -> V_132 = V_265 -> V_270 ;
V_110 -> V_51 = V_265 -> V_26 ;
V_110 -> V_62 = V_265 -> V_27 ;
V_110 -> F_115 = 0 ;
V_110 -> V_10 = NULL ;
V_110 -> V_20 = NULL ;
F_98 ( V_78 ) ;
if ( V_175 & V_124 ) {
V_110 -> V_2 . V_305 = V_306 ;
V_110 -> V_62 = V_265 -> V_26 ;
}
if ( V_175 & ( V_111 | V_112 ) ) {
V_110 -> V_62 = V_265 -> V_27 ;
if ( V_175 & V_124 &&
! ( V_338 -> V_175 & V_176 ) ) {
V_110 -> V_2 . V_303 = V_341 ;
F_98 ( V_79 ) ;
}
#ifdef F_201
if ( type == V_304 ) {
if ( F_202 ( V_211 ) &&
! F_198 ( V_265 -> V_26 ) ) {
V_110 -> V_2 . V_305 = V_307 ;
V_110 -> V_2 . V_303 = V_341 ;
}
}
#endif
}
F_189 ( V_110 , V_265 , V_263 , V_20 , type , 0 ) ;
return V_110 ;
}
static struct V_7 * F_222 ( struct V_32 * V_32 , struct V_264 * V_265 )
{
struct V_3 * V_338 = NULL ;
T_1 V_267 = F_221 ( V_265 ) ;
unsigned int V_175 = 0 ;
struct V_262 V_263 ;
struct V_7 * V_110 ;
T_3 V_335 ;
T_3 V_336 ;
int V_337 ;
V_263 . V_20 = NULL ;
#ifdef F_192
V_263 . V_39 = NULL ;
#endif
V_335 = V_265 -> V_26 ;
V_336 = V_265 -> V_27 ;
V_337 = V_265 -> V_268 ;
V_265 -> V_269 = V_32 -> V_300 -> V_181 ;
V_265 -> V_266 = V_267 & V_334 ;
V_265 -> V_322 = ( ( V_267 & V_342 ) ?
V_286 : V_272 ) ;
F_148 () ;
if ( V_265 -> V_27 ) {
V_110 = F_112 ( - V_231 ) ;
if ( F_129 ( V_265 -> V_27 ) ||
F_130 ( V_265 -> V_27 ) ||
F_131 ( V_265 -> V_27 ) )
goto V_120;
if ( V_265 -> V_268 == 0 &&
( F_129 ( V_265 -> V_26 ) ||
F_130 ( V_265 -> V_26 ) ) ) {
V_338 = F_223 ( V_32 , V_265 -> V_27 , false ) ;
if ( V_338 == NULL )
goto V_120;
V_265 -> V_268 = V_338 -> V_181 ;
goto V_343;
}
if ( ! ( V_265 -> V_279 & V_344 ) ) {
if ( ! F_223 ( V_32 , V_265 -> V_27 , false ) )
goto V_120;
}
}
if ( V_265 -> V_268 ) {
V_338 = F_224 ( V_32 , V_265 -> V_268 ) ;
V_110 = F_112 ( - V_345 ) ;
if ( V_338 == NULL )
goto V_120;
if ( ! ( V_338 -> V_175 & V_346 ) || ! F_127 ( V_338 ) ) {
V_110 = F_112 ( - V_234 ) ;
goto V_120;
}
if ( F_198 ( V_265 -> V_26 ) ||
F_130 ( V_265 -> V_26 ) ) {
if ( ! V_265 -> V_27 )
V_265 -> V_27 = F_181 ( V_338 , 0 ,
V_286 ) ;
goto V_343;
}
if ( V_265 -> V_27 ) {
if ( F_129 ( V_265 -> V_26 ) )
V_265 -> V_27 = F_181 ( V_338 , 0 ,
V_265 -> V_322 ) ;
else if ( ! V_265 -> V_26 )
V_265 -> V_27 = F_181 ( V_338 , 0 ,
V_347 ) ;
}
}
if ( ! V_265 -> V_26 ) {
V_265 -> V_26 = V_265 -> V_27 ;
if ( ! V_265 -> V_26 )
V_265 -> V_26 = V_265 -> V_27 = F_225 ( V_348 ) ;
V_338 = V_32 -> V_300 ;
V_265 -> V_268 = V_32 -> V_300 -> V_181 ;
V_263 . type = V_326 ;
V_175 |= V_124 ;
goto V_343;
}
if ( F_179 ( V_32 , V_265 , & V_263 ) ) {
V_263 . V_20 = NULL ;
if ( V_265 -> V_268 ) {
if ( V_265 -> V_27 == 0 )
V_265 -> V_27 = F_181 ( V_338 , 0 ,
V_286 ) ;
V_263 . type = V_190 ;
goto V_343;
}
V_110 = F_112 ( - V_234 ) ;
goto V_120;
}
if ( V_263 . type == V_326 ) {
if ( ! V_265 -> V_27 ) {
if ( V_263 . V_20 -> V_349 )
V_265 -> V_27 = V_263 . V_20 -> V_349 ;
else
V_265 -> V_27 = V_265 -> V_26 ;
}
V_338 = V_32 -> V_300 ;
V_265 -> V_268 = V_338 -> V_181 ;
V_263 . V_20 = NULL ;
V_175 |= V_124 ;
goto V_343;
}
#ifdef F_211
if ( V_263 . V_20 -> V_318 > 1 && V_265 -> V_268 == 0 )
F_212 ( & V_263 ) ;
else
#endif
if ( ! V_263 . V_340 &&
V_263 . V_350 -> V_351 > 1 &&
V_263 . type == V_190 && ! V_265 -> V_268 )
F_226 ( & V_263 ) ;
if ( ! V_265 -> V_27 )
V_265 -> V_27 = F_180 ( V_32 , V_263 ) ;
V_338 = F_207 ( V_263 ) ;
V_265 -> V_268 = V_338 -> V_181 ;
V_343:
V_110 = F_220 ( & V_263 , V_265 , V_335 , V_336 , V_337 ,
V_338 , V_175 ) ;
if ( ! F_108 ( V_110 ) ) {
unsigned int V_178 ;
V_178 = F_12 ( V_335 , V_336 , V_337 ,
F_14 ( F_20 ( V_338 ) ) ) ;
V_110 = F_111 ( V_178 , V_110 , NULL , V_337 ) ;
}
V_120:
F_150 () ;
return V_110 ;
}
struct V_7 * F_227 ( struct V_32 * V_32 , struct V_264 * V_352 )
{
struct V_7 * V_110 ;
unsigned int V_178 ;
if ( ! F_71 ( V_32 ) )
goto V_353;
V_178 = F_12 ( V_352 -> V_26 , V_352 -> V_27 , V_352 -> V_268 , F_14 ( V_32 ) ) ;
F_18 () ;
for ( V_110 = F_19 ( V_41 [ V_178 ] . V_42 ) ; V_110 ;
V_110 = F_19 ( V_110 -> V_2 . V_43 ) ) {
if ( V_110 -> V_129 == V_352 -> V_26 &&
V_110 -> V_130 == V_352 -> V_27 &&
F_70 ( V_110 ) &&
V_110 -> V_133 == V_352 -> V_268 &&
V_110 -> V_132 == V_352 -> V_270 &&
! ( ( V_110 -> V_59 ^ V_352 -> V_266 ) &
( V_334 | V_342 ) ) &&
F_75 ( F_20 ( V_110 -> V_2 . V_4 ) , V_32 ) &&
! F_76 ( V_110 ) ) {
F_113 ( & V_110 -> V_2 , V_121 ) ;
F_98 ( V_77 ) ;
F_22 () ;
if ( ! V_352 -> V_27 )
V_352 -> V_27 = V_110 -> V_55 ;
if ( ! V_352 -> V_26 )
V_352 -> V_26 = V_110 -> V_12 ;
return V_110 ;
}
F_98 ( V_85 ) ;
}
F_22 () ;
V_353:
return F_222 ( V_32 , V_352 ) ;
}
static struct V_1 * F_228 ( struct V_1 * V_2 , T_1 V_260 )
{
return NULL ;
}
static unsigned int F_229 ( const struct V_1 * V_2 )
{
return 0 ;
}
static void F_230 ( struct V_1 * V_2 , T_1 V_247 )
{
}
static T_1 * F_231 ( struct V_1 * V_2 ,
unsigned long V_6 )
{
return NULL ;
}
struct V_1 * F_232 ( struct V_32 * V_32 , struct V_1 * V_354 )
{
struct V_7 * V_8 = F_195 ( & V_355 , NULL , 1 , 0 , 0 ) ;
struct V_7 * V_356 = (struct V_7 * ) V_354 ;
if ( V_8 ) {
struct V_1 * V_15 = & V_8 -> V_2 ;
V_15 -> V_54 = 1 ;
V_15 -> V_305 = V_357 ;
V_15 -> V_303 = V_357 ;
F_233 ( V_15 , & V_356 -> V_2 ) ;
V_15 -> V_4 = V_356 -> V_2 . V_4 ;
if ( V_15 -> V_4 )
F_234 ( V_15 -> V_4 ) ;
V_8 -> V_129 = V_356 -> V_129 ;
V_8 -> V_130 = V_356 -> V_130 ;
V_8 -> V_59 = V_356 -> V_59 ;
V_8 -> V_131 = V_356 -> V_131 ;
V_8 -> V_228 = V_356 -> V_228 ;
V_8 -> V_133 = V_356 -> V_133 ;
V_8 -> V_132 = V_356 -> V_132 ;
V_8 -> F_14 = F_14 ( V_32 ) ;
V_8 -> V_52 = V_356 -> V_52 ;
V_8 -> V_189 = V_356 -> V_189 ;
V_8 -> V_12 = V_356 -> V_12 ;
V_8 -> V_55 = V_356 -> V_55 ;
V_8 -> V_51 = V_356 -> V_51 ;
V_8 -> V_62 = V_356 -> V_62 ;
V_8 -> V_10 = V_356 -> V_10 ;
if ( V_8 -> V_10 )
F_137 ( & V_8 -> V_10 -> V_358 ) ;
V_8 -> V_20 = V_356 -> V_20 ;
if ( V_8 -> V_20 )
F_137 ( & V_8 -> V_20 -> V_283 ) ;
F_235 ( V_15 ) ;
}
F_236 ( V_354 ) ;
return V_8 ? & V_8 -> V_2 : F_112 ( - V_91 ) ;
}
struct V_7 * F_237 ( struct V_32 * V_32 , struct V_264 * V_352 ,
struct V_359 * V_360 )
{
struct V_7 * V_8 = F_227 ( V_32 , V_352 ) ;
if ( F_108 ( V_8 ) )
return V_8 ;
if ( V_352 -> V_339 )
V_8 = (struct V_7 * ) F_238 ( V_32 , & V_8 -> V_2 ,
F_239 ( V_352 ) ,
V_360 , 0 ) ;
return V_8 ;
}
static int F_240 ( struct V_32 * V_32 ,
struct V_179 * V_180 , T_1 V_361 , T_1 V_35 , int V_362 ,
int V_363 , unsigned int V_175 )
{
struct V_7 * V_8 = F_147 ( V_180 ) ;
struct V_364 * V_39 ;
struct V_365 * V_366 ;
long V_252 = 0 ;
const struct V_9 * V_10 = V_8 -> V_10 ;
T_1 V_205 = 0 , V_367 = 0 , V_368 = 0 , error ;
V_366 = F_241 ( V_180 , V_361 , V_35 , V_362 , sizeof( * V_39 ) , V_175 ) ;
if ( V_366 == NULL )
return - V_369 ;
V_39 = F_242 ( V_366 ) ;
V_39 -> V_370 = V_371 ;
V_39 -> V_372 = 32 ;
V_39 -> V_373 = 0 ;
V_39 -> V_374 = V_8 -> V_59 ;
V_39 -> V_375 = V_376 ;
F_243 ( V_180 , V_377 , V_376 ) ;
V_39 -> V_378 = V_8 -> V_189 ;
V_39 -> V_379 = V_272 ;
V_39 -> V_380 = V_381 ;
V_39 -> V_382 = ( V_8 -> V_52 & ~ 0xFFFF ) | V_383 ;
if ( V_8 -> V_52 & V_114 )
V_39 -> V_382 |= V_384 ;
F_244 ( V_180 , V_385 , V_8 -> V_12 ) ;
if ( V_8 -> V_130 ) {
V_39 -> V_373 = 32 ;
F_244 ( V_180 , V_386 , V_8 -> V_130 ) ;
}
if ( V_8 -> V_2 . V_4 )
F_243 ( V_180 , V_387 , V_8 -> V_2 . V_4 -> V_181 ) ;
#ifdef F_56
if ( V_8 -> V_2 . V_274 )
F_243 ( V_180 , V_388 , V_8 -> V_2 . V_274 ) ;
#endif
if ( F_66 ( V_8 ) )
F_244 ( V_180 , V_389 , V_8 -> V_62 ) ;
else if ( V_8 -> V_55 != V_8 -> V_130 )
F_244 ( V_180 , V_389 , V_8 -> V_55 ) ;
if ( V_8 -> V_12 != V_8 -> V_51 )
F_244 ( V_180 , V_390 , V_8 -> V_51 ) ;
if ( F_245 ( V_180 , F_246 ( & V_8 -> V_2 ) ) < 0 )
goto V_391;
if ( V_8 -> V_132 )
F_244 ( V_180 , V_392 , V_8 -> V_132 ) ;
error = V_8 -> V_2 . error ;
if ( V_10 ) {
F_247 ( V_8 -> V_10 ) ;
V_205 = F_15 ( & V_10 -> V_393 ) & 0xffff ;
if ( V_10 -> V_394 ) {
V_367 = V_10 -> V_395 ;
V_368 = F_248 () - V_10 -> V_394 ;
}
V_252 = F_141 ( V_10 -> V_115 ) ;
if ( V_252 )
V_252 -= V_121 ;
}
if ( F_66 ( V_8 ) ) {
#ifdef F_201
T_3 V_2 = V_8 -> V_12 ;
if ( F_129 ( V_2 ) && ! F_198 ( V_2 ) &&
F_249 ( V_32 , V_396 ) ) {
int V_191 = F_250 ( V_32 , V_180 ,
V_8 -> V_55 , V_8 -> V_12 ,
V_39 , V_363 ) ;
if ( V_191 <= 0 ) {
if ( ! V_363 ) {
if ( V_191 == 0 )
return 0 ;
goto V_391;
} else {
if ( V_191 == - V_369 )
goto V_391;
error = V_191 ;
}
}
} else
#endif
F_243 ( V_180 , V_397 , V_8 -> V_228 ) ;
}
if ( F_251 ( V_180 , & V_8 -> V_2 , V_205 , V_367 , V_368 ,
V_252 , error ) < 0 )
goto V_391;
return F_252 ( V_180 , V_366 ) ;
V_391:
F_253 ( V_180 , V_366 ) ;
return - V_369 ;
}
static int F_254 ( struct V_179 * V_398 , struct V_365 * V_366 , void * V_399 )
{
struct V_32 * V_32 = F_255 ( V_398 -> V_360 ) ;
struct V_364 * V_400 ;
struct V_401 * V_402 [ V_403 + 1 ] ;
struct V_7 * V_8 = NULL ;
T_3 V_2 = 0 ;
T_3 V_89 = 0 ;
T_1 V_332 ;
int V_191 ;
int V_271 ;
struct V_179 * V_180 ;
V_191 = F_256 ( V_366 , sizeof( * V_400 ) , V_402 , V_403 , V_404 ) ;
if ( V_191 < 0 )
goto V_405;
V_400 = F_242 ( V_366 ) ;
V_180 = F_257 ( V_406 , V_25 ) ;
if ( V_180 == NULL ) {
V_191 = - V_195 ;
goto V_405;
}
F_258 ( V_180 ) ;
F_259 ( V_180 ) ;
F_153 ( V_180 ) -> V_295 = V_407 ;
F_260 ( V_180 , V_408 + sizeof( struct V_200 ) ) ;
V_89 = V_402 [ V_386 ] ? F_261 ( V_402 [ V_386 ] ) : 0 ;
V_2 = V_402 [ V_385 ] ? F_261 ( V_402 [ V_385 ] ) : 0 ;
V_332 = V_402 [ V_397 ] ? F_262 ( V_402 [ V_397 ] ) : 0 ;
V_271 = V_402 [ V_392 ] ? F_262 ( V_402 [ V_392 ] ) : 0 ;
if ( V_332 ) {
struct V_3 * V_4 ;
V_4 = F_263 ( V_32 , V_332 ) ;
if ( V_4 == NULL ) {
V_191 = - V_345 ;
goto V_409;
}
V_180 -> V_295 = F_121 ( V_296 ) ;
V_180 -> V_4 = V_4 ;
V_180 -> V_271 = V_271 ;
F_264 () ;
V_191 = F_265 ( V_180 , V_2 , V_89 , V_400 -> V_374 , V_4 ) ;
F_266 () ;
V_8 = F_147 ( V_180 ) ;
if ( V_191 == 0 && V_8 -> V_2 . error )
V_191 = - V_8 -> V_2 . error ;
} else {
struct V_264 V_265 = {
. V_26 = V_2 ,
. V_27 = V_89 ,
. V_266 = V_400 -> V_374 ,
. V_268 = V_402 [ V_387 ] ? F_262 ( V_402 [ V_387 ] ) : 0 ,
. V_270 = V_271 ,
} ;
V_8 = F_267 ( V_32 , & V_265 ) ;
V_191 = 0 ;
if ( F_108 ( V_8 ) )
V_191 = F_109 ( V_8 ) ;
}
if ( V_191 )
goto V_409;
F_114 ( V_180 , & V_8 -> V_2 ) ;
if ( V_400 -> V_382 & V_384 )
V_8 -> V_52 |= V_114 ;
V_191 = F_240 ( V_32 , V_180 , F_268 ( V_398 ) . V_361 , V_366 -> V_410 ,
V_411 , 0 , 0 ) ;
if ( V_191 <= 0 )
goto V_409;
V_191 = F_269 ( V_180 , V_32 , F_268 ( V_398 ) . V_361 ) ;
V_405:
return V_191 ;
V_409:
F_156 ( V_180 ) ;
goto V_405;
}
int F_270 ( struct V_179 * V_180 , struct V_412 * V_413 )
{
struct V_7 * V_8 ;
int V_414 , V_415 ;
int V_28 , V_416 ;
struct V_32 * V_32 ;
V_32 = F_255 ( V_180 -> V_360 ) ;
V_415 = V_413 -> args [ 0 ] ;
if ( V_415 < 0 )
V_415 = 0 ;
V_416 = V_28 = V_413 -> args [ 1 ] ;
for ( V_414 = V_415 ; V_414 <= V_31 ; V_414 ++ , V_416 = 0 ) {
if ( ! V_41 [ V_414 ] . V_42 )
continue;
F_18 () ;
for ( V_8 = F_19 ( V_41 [ V_414 ] . V_42 ) , V_28 = 0 ; V_8 ;
V_8 = F_19 ( V_8 -> V_2 . V_43 ) , V_28 ++ ) {
if ( ! F_75 ( F_20 ( V_8 -> V_2 . V_4 ) , V_32 ) || V_28 < V_416 )
continue;
if ( F_76 ( V_8 ) )
continue;
F_218 ( V_180 , & V_8 -> V_2 ) ;
if ( F_240 ( V_32 , V_180 , F_268 ( V_413 -> V_180 ) . V_361 ,
V_413 -> V_366 -> V_410 , V_411 ,
1 , V_417 ) <= 0 ) {
F_271 ( V_180 ) ;
F_22 () ;
goto V_418;
}
F_271 ( V_180 ) ;
}
F_22 () ;
}
V_418:
V_413 -> args [ 0 ] = V_414 ;
V_413 -> args [ 1 ] = V_28 ;
return V_180 -> V_49 ;
}
void F_272 ( struct V_210 * V_211 )
{
F_90 ( F_20 ( V_211 -> V_4 ) , 0 ) ;
}
static int F_273 ( T_10 * V_419 , int V_420 ,
void T_11 * V_421 ,
T_12 * V_422 , T_4 * V_423 )
{
if ( V_420 ) {
int V_424 ;
T_10 V_425 ;
struct V_32 * V_32 ;
memcpy ( & V_425 , V_419 , sizeof( V_425 ) ) ;
V_425 . V_426 = & V_424 ;
F_274 ( & V_425 , V_420 , V_421 , V_422 , V_423 ) ;
V_32 = (struct V_32 * ) V_419 -> V_427 ;
F_90 ( V_32 , V_424 ) ;
return 0 ;
}
return - V_231 ;
}
static T_5 int F_275 ( struct V_32 * V_32 )
{
struct T_10 * V_167 ;
V_167 = V_428 ;
if ( ! F_75 ( V_32 , & V_299 ) ) {
V_167 = F_276 ( V_167 , sizeof( V_428 ) , V_25 ) ;
if ( V_167 == NULL )
goto V_429;
}
V_167 [ 0 ] . V_427 = V_32 ;
V_32 -> V_33 . V_430 =
F_277 ( V_32 , V_431 , V_167 ) ;
if ( V_32 -> V_33 . V_430 == NULL )
goto V_432;
return 0 ;
V_432:
if ( V_167 != V_428 )
F_50 ( V_167 ) ;
V_429:
return - V_91 ;
}
static T_6 void F_278 ( struct V_32 * V_32 )
{
struct T_10 * V_167 ;
V_167 = V_32 -> V_33 . V_430 -> V_433 ;
F_279 ( V_32 -> V_33 . V_430 ) ;
F_280 ( V_167 == V_428 ) ;
F_50 ( V_167 ) ;
}
static T_5 int F_281 ( struct V_32 * V_32 )
{
F_88 ( & V_32 -> V_33 . F_14 ,
sizeof( V_32 -> V_33 . F_14 ) ) ;
F_88 ( & V_32 -> V_33 . V_434 ,
sizeof( V_32 -> V_33 . V_434 ) ) ;
return 0 ;
}
static int T_2 F_282 ( char * V_435 )
{
if ( ! V_435 )
return 0 ;
V_436 = F_283 ( V_435 , & V_435 , 0 ) ;
return 1 ;
}
int T_2 F_284 ( void )
{
int V_437 = 0 ;
#ifdef F_56
V_88 = F_285 ( 256 * sizeof( struct V_88 ) , F_286 ( struct V_88 ) ) ;
if ( ! V_88 )
F_10 ( L_35 ) ;
#endif
V_69 . V_438 =
F_287 ( L_36 , sizeof( struct V_7 ) , 0 ,
V_439 | V_440 , NULL ) ;
V_355 . V_438 = V_69 . V_438 ;
if ( F_288 ( & V_69 ) < 0 )
F_10 ( L_37 ) ;
if ( F_288 ( & V_355 ) < 0 )
F_10 ( L_38 ) ;
V_41 = (struct V_441 * )
F_289 ( L_39 ,
sizeof( struct V_441 ) ,
V_436 ,
( V_442 >= 128 * 1024 ) ?
15 : 17 ,
0 ,
& V_158 ,
& V_31 ,
V_436 ? 0 : 512 * 1024 ) ;
memset ( V_41 , 0 , ( V_31 + 1 ) * sizeof( struct V_441 ) ) ;
F_8 () ;
V_69 . V_159 = ( V_31 + 1 ) ;
V_156 = ( V_31 + 1 ) * 16 ;
F_290 () ;
F_291 () ;
if ( F_59 () )
F_95 ( V_443 L_40 ) ;
#ifdef F_292
F_293 () ;
F_294 ( V_156 ) ;
#endif
F_295 ( V_444 , V_445 , F_254 , NULL , NULL ) ;
#ifdef F_296
F_60 ( & V_446 ) ;
#endif
F_60 ( & V_447 ) ;
return V_437 ;
}
void T_2 F_297 ( void )
{
F_298 ( V_448 , V_449 ) ;
}
