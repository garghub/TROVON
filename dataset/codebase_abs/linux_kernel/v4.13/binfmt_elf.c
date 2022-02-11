static int F_1 ( unsigned long V_1 , unsigned long V_2 , int V_3 )
{
V_1 = F_2 ( V_1 ) ;
V_2 = F_2 ( V_2 ) ;
if ( V_2 > V_1 ) {
int error = F_3 ( V_1 , V_2 - V_1 ,
V_3 & V_4 ? V_5 : 0 ) ;
if ( error )
return error ;
}
V_6 -> V_7 -> V_8 = V_6 -> V_7 -> V_9 = V_2 ;
return 0 ;
}
static int F_4 ( unsigned long V_10 )
{
unsigned long V_11 ;
V_11 = F_5 ( V_10 ) ;
if ( V_11 ) {
V_11 = V_12 - V_11 ;
if ( F_6 ( ( void V_13 * ) V_10 , V_11 ) )
return - V_14 ;
}
return 0 ;
}
static int
F_7 ( struct V_15 * V_16 , struct V_17 * V_18 ,
unsigned long V_19 , unsigned long V_20 )
{
unsigned long V_21 = V_16 -> V_21 ;
int V_22 = V_16 -> V_22 ;
int V_23 = V_16 -> V_23 ;
T_1 V_13 * V_24 ;
T_1 V_13 * V_25 ;
T_1 V_13 * V_26 ;
T_1 V_13 * V_27 ;
const char * V_28 = V_29 ;
const char * V_30 = V_31 ;
unsigned char V_32 [ 16 ] ;
int V_33 ;
T_1 * V_34 ;
int V_35 = 0 ;
const struct V_36 * V_36 = F_8 () ;
struct V_37 * V_38 ;
V_21 = F_9 ( V_21 ) ;
V_25 = NULL ;
if ( V_28 ) {
T_2 V_39 = strlen ( V_28 ) + 1 ;
V_25 = ( T_1 V_13 * ) F_10 ( V_21 , V_39 ) ;
if ( F_11 ( V_25 , V_28 , V_39 ) )
return - V_14 ;
}
V_26 = NULL ;
if ( V_30 ) {
T_2 V_39 = strlen ( V_30 ) + 1 ;
V_26 = ( T_1 V_13 * ) F_10 ( V_21 , V_39 ) ;
if ( F_11 ( V_26 , V_30 , V_39 ) )
return - V_14 ;
}
F_12 ( V_32 , sizeof( V_32 ) ) ;
V_27 = ( T_1 V_13 * )
F_10 ( V_21 , sizeof( V_32 ) ) ;
if ( F_11 ( V_27 , V_32 , sizeof( V_32 ) ) )
return - V_14 ;
V_34 = ( T_1 * ) V_6 -> V_7 -> V_40 ;
#define F_13 ( T_3 , T_4 ) \
do { \
elf_info[ei_index++] = id; \
elf_info[ei_index++] = val; \
} while (0)
#ifdef F_14
F_14 ;
#endif
F_13 ( V_41 , V_42 ) ;
F_13 ( V_43 , V_44 ) ;
F_13 ( V_45 , V_46 ) ;
F_13 ( V_47 , V_19 + V_18 -> V_48 ) ;
F_13 ( V_49 , sizeof( struct V_50 ) ) ;
F_13 ( V_51 , V_18 -> V_52 ) ;
F_13 ( V_53 , V_20 ) ;
F_13 ( V_54 , 0 ) ;
F_13 ( V_55 , V_18 -> V_56 ) ;
F_13 ( V_57 , F_15 ( V_36 -> V_58 , V_36 -> V_59 ) ) ;
F_13 ( V_60 , F_15 ( V_36 -> V_58 , V_36 -> V_61 ) ) ;
F_13 ( V_62 , F_16 ( V_36 -> V_58 , V_36 -> V_63 ) ) ;
F_13 ( V_64 , F_16 ( V_36 -> V_58 , V_36 -> V_65 ) ) ;
F_13 ( V_66 , F_17 ( V_16 ) ) ;
F_13 ( V_67 , ( T_1 ) ( unsigned long ) V_27 ) ;
#ifdef F_18
F_13 ( V_68 , F_18 ) ;
#endif
F_13 ( V_69 , V_16 -> V_18 ) ;
if ( V_28 ) {
F_13 ( V_70 ,
( T_1 ) ( unsigned long ) V_25 ) ;
}
if ( V_30 ) {
F_13 ( V_71 ,
( T_1 ) ( unsigned long ) V_26 ) ;
}
if ( V_16 -> V_72 & V_73 ) {
F_13 ( V_74 , V_16 -> V_75 ) ;
}
#undef F_13
memset ( & V_34 [ V_35 ] , 0 ,
sizeof V_6 -> V_7 -> V_40 - V_35 * sizeof V_34 [ 0 ] ) ;
V_35 += 2 ;
V_24 = F_19 ( V_21 , V_35 ) ;
V_33 = ( V_22 + 1 ) + ( V_23 + 1 ) + 1 ;
V_16 -> V_21 = F_20 ( V_24 , V_33 ) ;
#ifdef F_21
V_24 = ( T_1 V_13 * ) V_16 -> V_21 - V_33 - V_35 ;
V_16 -> V_18 = ( unsigned long ) V_24 ;
#else
V_24 = ( T_1 V_13 * ) V_16 -> V_21 ;
#endif
V_38 = F_22 ( V_6 -> V_7 , V_16 -> V_21 ) ;
if ( ! V_38 )
return - V_14 ;
if ( F_23 ( V_22 , V_24 ++ ) )
return - V_14 ;
V_21 = V_6 -> V_7 -> V_76 = V_6 -> V_7 -> V_77 ;
while ( V_22 -- > 0 ) {
T_2 V_39 ;
if ( F_23 ( ( T_1 ) V_21 , V_24 ++ ) )
return - V_14 ;
V_39 = F_24 ( ( void V_13 * ) V_21 , V_78 ) ;
if ( ! V_39 || V_39 > V_78 )
return - V_79 ;
V_21 += V_39 ;
}
if ( F_23 ( 0 , V_24 ++ ) )
return - V_14 ;
V_6 -> V_7 -> V_76 = V_21 ;
V_6 -> V_7 -> V_80 = V_6 -> V_7 -> V_81 = V_21 ;
while ( V_23 -- > 0 ) {
T_2 V_39 ;
if ( F_23 ( ( T_1 ) V_21 , V_24 ++ ) )
return - V_14 ;
V_39 = F_24 ( ( void V_13 * ) V_21 , V_78 ) ;
if ( ! V_39 || V_39 > V_78 )
return - V_79 ;
V_21 += V_39 ;
}
if ( F_23 ( 0 , V_24 ++ ) )
return - V_14 ;
V_6 -> V_7 -> V_80 = V_21 ;
if ( F_25 ( V_24 , V_34 , V_35 * sizeof( T_1 ) ) )
return - V_14 ;
return 0 ;
}
static unsigned long F_26 ( struct V_82 * V_83 , unsigned long V_84 ,
struct V_50 * V_85 , int V_3 , int type ,
unsigned long V_86 )
{
unsigned long V_87 ;
unsigned long V_88 = V_85 -> V_89 + F_5 ( V_85 -> V_90 ) ;
unsigned long V_91 = V_85 -> V_92 - F_5 ( V_85 -> V_90 ) ;
V_84 = F_27 ( V_84 ) ;
V_88 = F_2 ( V_88 ) ;
if ( ! V_88 )
return V_84 ;
if ( V_86 ) {
V_86 = F_2 ( V_86 ) ;
V_87 = F_28 ( V_83 , V_84 , V_86 , V_3 , type , V_91 ) ;
if ( ! F_29 ( V_87 ) )
F_30 ( V_87 + V_88 , V_86 - V_88 ) ;
} else
V_87 = F_28 ( V_83 , V_84 , V_88 , V_3 , type , V_91 ) ;
return ( V_87 ) ;
}
static unsigned long F_31 ( struct V_50 * V_93 , int V_94 )
{
int V_95 , V_96 = - 1 , V_97 = - 1 ;
for ( V_95 = 0 ; V_95 < V_94 ; V_95 ++ ) {
if ( V_93 [ V_95 ] . V_98 == V_99 ) {
V_97 = V_95 ;
if ( V_96 == - 1 )
V_96 = V_95 ;
}
}
if ( V_96 == - 1 )
return 0 ;
return V_93 [ V_97 ] . V_90 + V_93 [ V_97 ] . V_100 -
F_27 ( V_93 [ V_96 ] . V_90 ) ;
}
static struct V_50 * F_32 ( struct V_17 * V_101 ,
struct V_82 * V_102 )
{
struct V_50 * V_103 = NULL ;
int V_104 , V_88 , V_105 = - 1 ;
if ( V_101 -> V_106 != sizeof( struct V_50 ) )
goto V_107;
if ( V_101 -> V_52 < 1 ||
V_101 -> V_52 > 65536U / sizeof( struct V_50 ) )
goto V_107;
V_88 = sizeof( struct V_50 ) * V_101 -> V_52 ;
if ( V_88 > V_12 )
goto V_107;
V_103 = F_33 ( V_88 , V_108 ) ;
if ( ! V_103 )
goto V_107;
V_104 = F_34 ( V_102 , V_101 -> V_48 ,
( char * ) V_103 , V_88 ) ;
if ( V_104 != V_88 ) {
V_105 = ( V_104 < 0 ) ? V_104 : - V_109 ;
goto V_107;
}
V_105 = 0 ;
V_107:
if ( V_105 ) {
F_35 ( V_103 ) ;
V_103 = NULL ;
}
return V_103 ;
}
static inline int F_36 ( struct V_17 * V_110 ,
struct V_50 * V_111 ,
struct V_82 * V_112 , bool V_113 ,
struct V_114 * V_115 )
{
return 0 ;
}
static inline int F_37 ( struct V_17 * V_110 , bool V_116 ,
struct V_17 * V_117 ,
struct V_114 * V_115 )
{
return 0 ;
}
static unsigned long F_38 ( struct V_17 * V_118 ,
struct V_82 * V_119 , unsigned long * V_120 ,
unsigned long V_121 , struct V_50 * V_122 )
{
struct V_50 * V_85 ;
unsigned long V_19 = 0 ;
int V_123 = 0 ;
unsigned long V_124 = 0 , V_10 = 0 ;
int V_125 = 0 ;
unsigned long error = ~ 0UL ;
unsigned long V_86 ;
int V_95 ;
if ( V_118 -> V_126 != V_127 &&
V_118 -> V_126 != V_128 )
goto V_107;
if ( ! F_39 ( V_118 ) )
goto V_107;
if ( ! V_119 -> V_129 -> V_130 )
goto V_107;
V_86 = F_31 ( V_122 ,
V_118 -> V_52 ) ;
if ( ! V_86 ) {
error = - V_79 ;
goto V_107;
}
V_85 = V_122 ;
for ( V_95 = 0 ; V_95 < V_118 -> V_52 ; V_95 ++ , V_85 ++ ) {
if ( V_85 -> V_98 == V_99 ) {
int V_131 = V_132 | V_133 ;
int V_134 = 0 ;
unsigned long V_135 = 0 ;
unsigned long V_136 , V_87 ;
if ( V_85 -> V_137 & V_138 )
V_134 = V_139 ;
if ( V_85 -> V_137 & V_140 )
V_134 |= V_141 ;
if ( V_85 -> V_137 & V_142 )
V_134 |= V_4 ;
V_135 = V_85 -> V_90 ;
if ( V_118 -> V_126 == V_127 || V_123 )
V_131 |= V_143 ;
else if ( V_121 && V_118 -> V_126 == V_128 )
V_19 = - V_135 ;
V_87 = F_26 ( V_119 , V_19 + V_135 ,
V_85 , V_134 , V_131 , V_86 ) ;
V_86 = 0 ;
if ( ! * V_120 )
* V_120 = V_87 ;
error = V_87 ;
if ( F_29 ( V_87 ) )
goto V_107;
if ( ! V_123 &&
V_118 -> V_126 == V_128 ) {
V_19 = V_87 - F_27 ( V_135 ) ;
V_123 = 1 ;
}
V_136 = V_19 + V_85 -> V_90 ;
if ( F_29 ( V_136 ) ||
V_85 -> V_89 > V_85 -> V_100 ||
V_85 -> V_100 > V_144 ||
V_144 - V_85 -> V_100 < V_136 ) {
error = - V_145 ;
goto V_107;
}
V_136 = V_19 + V_85 -> V_90 + V_85 -> V_89 ;
if ( V_136 > V_10 )
V_10 = V_136 ;
V_136 = V_19 + V_85 -> V_90 + V_85 -> V_100 ;
if ( V_136 > V_124 ) {
V_124 = V_136 ;
V_125 = V_134 ;
}
}
}
if ( F_4 ( V_10 ) ) {
error = - V_14 ;
goto V_107;
}
V_10 = F_2 ( V_10 ) ;
V_124 = F_2 ( V_124 ) ;
if ( V_124 > V_10 ) {
error = F_3 ( V_10 , V_124 - V_10 ,
V_125 & V_4 ? V_5 : 0 ) ;
if ( error )
goto V_107;
}
error = V_19 ;
V_107:
return error ;
}
static unsigned long F_40 ( unsigned long V_146 )
{
unsigned long V_147 = 0 ;
if ( V_6 -> V_148 & V_149 ) {
V_147 = F_41 () ;
V_147 &= V_150 ;
V_147 <<= V_151 ;
}
#ifdef F_21
return F_42 ( V_146 ) + V_147 ;
#else
return F_42 ( V_146 ) - V_147 ;
#endif
}
static int F_43 ( struct V_15 * V_16 )
{
struct V_82 * V_119 = NULL ;
unsigned long V_19 = 0 , V_152 = 0 ;
int V_123 = 0 ;
char * V_153 = NULL ;
unsigned long error ;
struct V_50 * V_154 , * V_103 , * V_122 = NULL ;
unsigned long V_10 , V_155 ;
int V_125 = 0 ;
int V_104 , V_95 ;
unsigned long V_156 ;
unsigned long V_20 = 0 ;
unsigned long V_157 , V_158 , V_159 , V_160 ;
unsigned long T_5 V_161 = 0 ;
int V_162 = V_163 ;
struct V_164 * V_165 = F_44 () ;
struct {
struct V_17 V_101 ;
struct V_17 V_118 ;
} * V_166 ;
struct V_114 V_167 = V_168 ;
V_166 = F_33 ( sizeof( * V_166 ) , V_108 ) ;
if ( ! V_166 ) {
V_104 = - V_145 ;
goto V_169;
}
V_166 -> V_101 = * ( (struct V_17 * ) V_16 -> V_170 ) ;
V_104 = - V_171 ;
if ( memcmp ( V_166 -> V_101 . V_172 , V_173 , V_174 ) != 0 )
goto V_107;
if ( V_166 -> V_101 . V_126 != V_127 && V_166 -> V_101 . V_126 != V_128 )
goto V_107;
if ( ! F_39 ( & V_166 -> V_101 ) )
goto V_107;
if ( ! V_16 -> V_82 -> V_129 -> V_130 )
goto V_107;
V_103 = F_32 ( & V_166 -> V_101 , V_16 -> V_82 ) ;
if ( ! V_103 )
goto V_107;
V_154 = V_103 ;
V_10 = 0 ;
V_155 = 0 ;
V_157 = ~ 0UL ;
V_158 = 0 ;
V_159 = 0 ;
V_160 = 0 ;
for ( V_95 = 0 ; V_95 < V_166 -> V_101 . V_52 ; V_95 ++ ) {
if ( V_154 -> V_98 == V_175 ) {
V_104 = - V_171 ;
if ( V_154 -> V_89 > V_176 ||
V_154 -> V_89 < 2 )
goto V_177;
V_104 = - V_145 ;
V_153 = F_33 ( V_154 -> V_89 ,
V_108 ) ;
if ( ! V_153 )
goto V_177;
V_104 = F_34 ( V_16 -> V_82 , V_154 -> V_92 ,
V_153 ,
V_154 -> V_89 ) ;
if ( V_104 != V_154 -> V_89 ) {
if ( V_104 >= 0 )
V_104 = - V_109 ;
goto V_178;
}
V_104 = - V_171 ;
if ( V_153 [ V_154 -> V_89 - 1 ] != '\0' )
goto V_178;
V_119 = F_45 ( V_153 ) ;
V_104 = F_46 ( V_119 ) ;
if ( F_47 ( V_119 ) )
goto V_178;
F_48 ( V_16 , V_119 ) ;
V_104 = F_34 ( V_119 , 0 ,
( void * ) & V_166 -> V_118 ,
sizeof( V_166 -> V_118 ) ) ;
if ( V_104 != sizeof( V_166 -> V_118 ) ) {
if ( V_104 >= 0 )
V_104 = - V_109 ;
goto V_179;
}
break;
}
V_154 ++ ;
}
V_154 = V_103 ;
for ( V_95 = 0 ; V_95 < V_166 -> V_101 . V_52 ; V_95 ++ , V_154 ++ )
switch ( V_154 -> V_98 ) {
case V_180 :
if ( V_154 -> V_137 & V_142 )
V_162 = V_181 ;
else
V_162 = V_182 ;
break;
case V_183 ... V_184 :
V_104 = F_36 ( & V_166 -> V_101 , V_154 ,
V_16 -> V_82 , false ,
& V_167 ) ;
if ( V_104 )
goto V_179;
break;
}
if ( V_153 ) {
V_104 = - V_185 ;
if ( memcmp ( V_166 -> V_118 . V_172 , V_173 , V_174 ) != 0 )
goto V_179;
if ( ! F_39 ( & V_166 -> V_118 ) )
goto V_179;
V_122 = F_32 ( & V_166 -> V_118 ,
V_119 ) ;
if ( ! V_122 )
goto V_179;
V_154 = V_122 ;
for ( V_95 = 0 ; V_95 < V_166 -> V_118 . V_52 ; V_95 ++ , V_154 ++ )
switch ( V_154 -> V_98 ) {
case V_183 ... V_184 :
V_104 = F_36 ( & V_166 -> V_118 ,
V_154 , V_119 ,
true , & V_167 ) ;
if ( V_104 )
goto V_179;
break;
}
}
V_104 = F_37 ( & V_166 -> V_101 ,
! ! V_119 , & V_166 -> V_118 ,
& V_167 ) ;
if ( V_104 )
goto V_179;
V_104 = F_49 ( V_16 ) ;
if ( V_104 )
goto V_179;
F_50 ( V_166 -> V_101 , & V_167 ) ;
if ( F_51 ( V_166 -> V_101 , V_162 ) )
V_6 -> V_186 |= V_187 ;
if ( ! ( V_6 -> V_186 & V_188 ) && V_189 )
V_6 -> V_148 |= V_149 ;
F_52 ( V_16 ) ;
F_53 ( V_16 ) ;
V_104 = F_54 ( V_16 , F_40 ( V_190 ) ,
V_162 ) ;
if ( V_104 < 0 )
goto V_179;
V_6 -> V_7 -> V_191 = V_16 -> V_21 ;
for( V_95 = 0 , V_154 = V_103 ;
V_95 < V_166 -> V_101 . V_52 ; V_95 ++ , V_154 ++ ) {
int V_134 = 0 , V_192 ;
unsigned long V_136 , V_135 ;
unsigned long V_86 = 0 ;
if ( V_154 -> V_98 != V_99 )
continue;
if ( F_55 ( V_155 > V_10 ) ) {
unsigned long V_11 ;
V_104 = F_1 ( V_10 + V_152 ,
V_155 + V_152 ,
V_125 ) ;
if ( V_104 )
goto V_179;
V_11 = F_5 ( V_10 ) ;
if ( V_11 ) {
V_11 = V_12 - V_11 ;
if ( V_11 > V_155 - V_10 )
V_11 = V_155 - V_10 ;
if ( F_6 ( ( void V_13 * ) V_10 +
V_152 , V_11 ) ) {
}
}
}
if ( V_154 -> V_137 & V_138 )
V_134 |= V_139 ;
if ( V_154 -> V_137 & V_140 )
V_134 |= V_141 ;
if ( V_154 -> V_137 & V_142 )
V_134 |= V_4 ;
V_192 = V_132 | V_133 | V_193 ;
V_135 = V_154 -> V_90 ;
if ( V_166 -> V_101 . V_126 == V_127 || V_123 ) {
V_192 |= V_143 ;
} else if ( V_166 -> V_101 . V_126 == V_128 ) {
if ( V_153 ) {
V_152 = V_194 ;
if ( V_6 -> V_148 & V_149 )
V_152 += F_56 () ;
V_192 |= V_143 ;
} else
V_152 = 0 ;
V_152 = F_27 ( V_152 - V_135 ) ;
V_86 = F_31 ( V_103 ,
V_166 -> V_101 . V_52 ) ;
if ( ! V_86 ) {
V_104 = - V_79 ;
goto V_179;
}
}
error = F_26 ( V_16 -> V_82 , V_152 + V_135 , V_154 ,
V_134 , V_192 , V_86 ) ;
if ( F_29 ( error ) ) {
V_104 = F_47 ( ( void * ) error ) ?
F_46 ( ( void * ) error ) : - V_79 ;
goto V_179;
}
if ( ! V_123 ) {
V_123 = 1 ;
V_19 = ( V_154 -> V_90 - V_154 -> V_92 ) ;
if ( V_166 -> V_101 . V_126 == V_128 ) {
V_152 += error -
F_27 ( V_152 + V_135 ) ;
V_19 += V_152 ;
T_5 = V_152 ;
}
}
V_136 = V_154 -> V_90 ;
if ( V_136 < V_157 )
V_157 = V_136 ;
if ( V_159 < V_136 )
V_159 = V_136 ;
if ( F_29 ( V_136 ) || V_154 -> V_89 > V_154 -> V_100 ||
V_154 -> V_100 > V_144 ||
V_144 - V_154 -> V_100 < V_136 ) {
V_104 = - V_79 ;
goto V_179;
}
V_136 = V_154 -> V_90 + V_154 -> V_89 ;
if ( V_136 > V_10 )
V_10 = V_136 ;
if ( ( V_154 -> V_137 & V_142 ) && V_158 < V_136 )
V_158 = V_136 ;
if ( V_160 < V_136 )
V_160 = V_136 ;
V_136 = V_154 -> V_90 + V_154 -> V_100 ;
if ( V_136 > V_155 ) {
V_125 = V_134 ;
V_155 = V_136 ;
}
}
V_166 -> V_101 . V_56 += V_152 ;
V_10 += V_152 ;
V_155 += V_152 ;
V_157 += V_152 ;
V_158 += V_152 ;
V_159 += V_152 ;
V_160 += V_152 ;
V_104 = F_1 ( V_10 , V_155 , V_125 ) ;
if ( V_104 )
goto V_179;
if ( F_57 ( V_10 != V_155 ) && F_55 ( F_4 ( V_10 ) ) ) {
V_104 = - V_14 ;
goto V_179;
}
if ( V_153 ) {
unsigned long V_120 = 0 ;
V_156 = F_38 ( & V_166 -> V_118 ,
V_119 ,
& V_120 ,
V_152 , V_122 ) ;
if ( ! F_47 ( ( void * ) V_156 ) ) {
V_20 = V_156 ;
V_156 += V_166 -> V_118 . V_56 ;
}
if ( F_29 ( V_156 ) ) {
V_104 = F_47 ( ( void * ) V_156 ) ?
( int ) V_156 : - V_79 ;
goto V_179;
}
T_5 = V_20 ;
F_58 ( V_119 ) ;
F_59 ( V_119 ) ;
F_35 ( V_153 ) ;
} else {
V_156 = V_166 -> V_101 . V_56 ;
if ( F_29 ( V_156 ) ) {
V_104 = - V_79 ;
goto V_179;
}
}
F_35 ( V_122 ) ;
F_35 ( V_103 ) ;
F_60 ( & V_195 ) ;
#ifdef F_61
V_104 = F_62 ( V_16 , ! ! V_153 ) ;
if ( V_104 < 0 )
goto V_107;
#endif
V_104 = F_7 ( V_16 , & V_166 -> V_101 ,
V_19 , V_20 ) ;
if ( V_104 < 0 )
goto V_107;
V_6 -> V_7 -> V_158 = V_158 ;
V_6 -> V_7 -> V_157 = V_157 ;
V_6 -> V_7 -> V_159 = V_159 ;
V_6 -> V_7 -> V_160 = V_160 ;
V_6 -> V_7 -> V_191 = V_16 -> V_21 ;
if ( ( V_6 -> V_148 & V_149 ) && ( V_189 > 1 ) ) {
V_6 -> V_7 -> V_9 = V_6 -> V_7 -> V_8 =
F_63 ( V_6 -> V_7 ) ;
#ifdef F_64
V_6 -> V_196 = 1 ;
#endif
}
if ( V_6 -> V_186 & V_197 ) {
error = F_28 ( NULL , 0 , V_198 , V_139 | V_4 ,
V_143 | V_132 , 0 ) ;
}
#ifdef F_65
F_65 ( V_165 , T_5 ) ;
#endif
F_66 ( V_165 , V_156 , V_16 -> V_21 ) ;
V_104 = 0 ;
V_107:
F_35 ( V_166 ) ;
V_169:
return V_104 ;
V_179:
F_35 ( V_122 ) ;
F_58 ( V_119 ) ;
if ( V_119 )
F_59 ( V_119 ) ;
V_178:
F_35 ( V_153 ) ;
V_177:
F_35 ( V_103 ) ;
goto V_107;
}
static int F_67 ( struct V_82 * V_82 )
{
struct V_50 * V_103 ;
struct V_50 * V_85 ;
unsigned long V_10 , V_199 , V_39 ;
int V_104 , error , V_95 , V_200 ;
struct V_17 V_101 ;
error = - V_171 ;
V_104 = F_34 ( V_82 , 0 , ( char * ) & V_101 , sizeof( V_101 ) ) ;
if ( V_104 != sizeof( V_101 ) )
goto V_107;
if ( memcmp ( V_101 . V_172 , V_173 , V_174 ) != 0 )
goto V_107;
if ( V_101 . V_126 != V_127 || V_101 . V_52 > 2 ||
! F_39 ( & V_101 ) || ! V_82 -> V_129 -> V_130 )
goto V_107;
V_200 = sizeof( struct V_50 ) * V_101 . V_52 ;
error = - V_145 ;
V_103 = F_33 ( V_200 , V_108 ) ;
if ( ! V_103 )
goto V_107;
V_85 = V_103 ;
error = - V_171 ;
V_104 = F_34 ( V_82 , V_101 . V_48 , ( char * ) V_85 , V_200 ) ;
if ( V_104 != V_200 )
goto V_177;
for ( V_200 = 0 , V_95 = 0 ; V_95 < V_101 . V_52 ; V_95 ++ )
if ( ( V_85 + V_95 ) -> V_98 == V_99 )
V_200 ++ ;
if ( V_200 != 1 )
goto V_177;
while ( V_85 -> V_98 != V_99 )
V_85 ++ ;
error = F_28 ( V_82 ,
F_27 ( V_85 -> V_90 ) ,
( V_85 -> V_89 +
F_5 ( V_85 -> V_90 ) ) ,
V_139 | V_141 | V_4 ,
V_143 | V_132 | V_133 ,
( V_85 -> V_92 -
F_5 ( V_85 -> V_90 ) ) ) ;
if ( error != F_27 ( V_85 -> V_90 ) )
goto V_177;
V_10 = V_85 -> V_90 + V_85 -> V_89 ;
if ( F_4 ( V_10 ) ) {
error = - V_14 ;
goto V_177;
}
V_39 = F_27 ( V_85 -> V_89 + V_85 -> V_90 +
V_12 - 1 ) ;
V_199 = V_85 -> V_100 + V_85 -> V_90 ;
if ( V_199 > V_39 ) {
error = F_68 ( V_39 , V_199 - V_39 ) ;
if ( error )
goto V_177;
}
error = 0 ;
V_177:
F_35 ( V_103 ) ;
V_107:
return error ;
}
static bool F_69 ( struct V_37 * V_38 )
{
if ( V_38 == F_70 ( V_38 -> V_201 ) )
return true ;
if ( V_38 -> V_202 && V_38 -> V_202 -> V_203 && V_38 -> V_202 -> V_203 ( V_38 ) )
return true ;
if ( F_71 ( V_38 ) )
return true ;
return false ;
}
static unsigned long F_72 ( struct V_37 * V_38 ,
unsigned long V_204 )
{
#define F_73 ( type ) (mm_flags & (1UL << MMF_DUMP_##type))
if ( F_69 ( V_38 ) )
goto V_205;
if ( V_38 -> V_206 & V_207 )
return 0 ;
if ( F_74 ( V_38 ) ) {
if ( ( V_38 -> V_206 & V_208 ) && F_73 ( V_209 ) )
goto V_205;
if ( ! ( V_38 -> V_206 & V_208 ) && F_73 ( V_210 ) )
goto V_205;
return 0 ;
}
if ( V_38 -> V_206 & V_211 ) {
if ( ( V_38 -> V_206 & V_208 ) && F_73 ( V_212 ) )
goto V_205;
if ( ! ( V_38 -> V_206 & V_208 ) && F_73 ( V_213 ) )
goto V_205;
return 0 ;
}
if ( V_38 -> V_206 & V_214 )
return 0 ;
if ( V_38 -> V_206 & V_208 ) {
if ( F_75 ( V_38 -> V_215 ) -> V_216 == 0 ?
F_73 ( V_217 ) : F_73 ( V_218 ) )
goto V_205;
return 0 ;
}
if ( V_38 -> V_219 && F_73 ( V_220 ) )
goto V_205;
if ( V_38 -> V_215 == NULL )
return 0 ;
if ( F_73 ( V_221 ) )
goto V_205;
if ( F_73 ( V_222 ) &&
V_38 -> V_223 == 0 && ( V_38 -> V_206 & V_224 ) ) {
T_6 V_13 * V_225 = ( T_6 V_13 * ) V_38 -> V_226 ;
T_6 V_227 ;
T_7 V_228 = F_76 () ;
union {
T_6 V_229 ;
char V_230 [ V_174 ] ;
} V_231 ;
F_77 ( V_174 != sizeof V_227 ) ;
V_231 . V_230 [ V_232 ] = V_233 ;
V_231 . V_230 [ V_234 ] = V_235 ;
V_231 . V_230 [ V_236 ] = V_237 ;
V_231 . V_230 [ V_238 ] = V_239 ;
F_78 ( V_240 ) ;
if ( F_55 ( F_79 ( V_227 , V_225 ) ) )
V_227 = 0 ;
F_78 ( V_228 ) ;
if ( V_227 == V_231 . V_229 )
return V_198 ;
}
#undef F_73
return 0 ;
V_205:
return V_38 -> V_241 - V_38 -> V_226 ;
}
static int F_80 ( struct V_242 * V_243 )
{
int V_244 ;
V_244 = sizeof( struct V_245 ) ;
V_244 += F_81 ( strlen ( V_243 -> V_203 ) + 1 , 4 ) ;
V_244 += F_81 ( V_243 -> V_246 , 4 ) ;
return V_244 ;
}
static int F_82 ( struct V_242 * V_247 , struct V_248 * V_249 )
{
struct V_245 V_243 ;
V_243 . V_250 = strlen ( V_247 -> V_203 ) + 1 ;
V_243 . V_251 = V_247 -> V_246 ;
V_243 . V_252 = V_247 -> type ;
return F_83 ( V_249 , & V_243 , sizeof( V_243 ) ) &&
F_83 ( V_249 , V_247 -> V_203 , V_243 . V_250 ) && F_84 ( V_249 , 4 ) &&
F_83 ( V_249 , V_247 -> V_253 , V_247 -> V_246 ) && F_84 ( V_249 , 4 ) ;
}
static void F_85 ( struct V_17 * V_112 , int V_254 ,
T_8 V_255 , T_6 V_148 )
{
memset ( V_112 , 0 , sizeof( * V_112 ) ) ;
memcpy ( V_112 -> V_172 , V_173 , V_174 ) ;
V_112 -> V_172 [ V_256 ] = V_257 ;
V_112 -> V_172 [ V_258 ] = V_259 ;
V_112 -> V_172 [ V_260 ] = V_261 ;
V_112 -> V_172 [ V_262 ] = V_263 ;
V_112 -> V_126 = V_264 ;
V_112 -> V_265 = V_255 ;
V_112 -> V_266 = V_261 ;
V_112 -> V_48 = sizeof( struct V_17 ) ;
V_112 -> V_267 = V_148 ;
V_112 -> V_268 = sizeof( struct V_17 ) ;
V_112 -> V_106 = sizeof( struct V_50 ) ;
V_112 -> V_52 = V_254 ;
return;
}
static void F_86 ( struct V_50 * V_111 , int V_244 , T_9 V_269 )
{
V_111 -> V_98 = V_270 ;
V_111 -> V_92 = V_269 ;
V_111 -> V_90 = 0 ;
V_111 -> V_271 = 0 ;
V_111 -> V_89 = V_244 ;
V_111 -> V_100 = 0 ;
V_111 -> V_137 = 0 ;
V_111 -> V_272 = 0 ;
return;
}
static void F_87 ( struct V_242 * V_273 , const char * V_203 , int type ,
unsigned int V_244 , void * V_253 )
{
V_273 -> V_203 = V_203 ;
V_273 -> type = type ;
V_273 -> V_246 = V_244 ;
V_273 -> V_253 = V_253 ;
return;
}
static void F_88 ( struct V_274 * V_275 ,
struct V_276 * V_21 , long V_277 )
{
V_275 -> V_278 . V_279 = V_275 -> V_280 = V_277 ;
V_275 -> V_281 = V_21 -> V_282 . signal . V_283 [ 0 ] ;
V_275 -> V_284 = V_21 -> V_285 . V_283 [ 0 ] ;
F_89 () ;
V_275 -> V_286 = F_90 ( F_91 ( V_21 -> V_287 ) ) ;
F_92 () ;
V_275 -> V_288 = F_90 ( V_21 ) ;
V_275 -> V_289 = F_93 ( V_21 ) ;
V_275 -> V_290 = F_94 ( V_21 ) ;
if ( F_95 ( V_21 ) ) {
struct V_291 V_292 ;
F_96 ( V_21 , & V_292 ) ;
V_275 -> V_293 = F_97 ( V_292 . V_294 ) ;
V_275 -> V_295 = F_97 ( V_292 . V_296 ) ;
} else {
T_10 V_294 , V_296 ;
V_291 ( V_21 , & V_294 , & V_296 ) ;
V_275 -> V_293 = F_97 ( V_294 ) ;
V_275 -> V_295 = F_97 ( V_296 ) ;
}
V_275 -> V_297 = F_97 ( V_21 -> signal -> V_298 ) ;
V_275 -> V_299 = F_97 ( V_21 -> signal -> V_300 ) ;
}
static int F_98 ( struct V_301 * V_302 , struct V_276 * V_21 ,
struct V_303 * V_7 )
{
const struct V_36 * V_36 ;
unsigned int V_95 , V_39 ;
memset ( V_302 , 0 , sizeof( struct V_301 ) ) ;
V_39 = V_7 -> V_76 - V_7 -> V_77 ;
if ( V_39 >= V_304 )
V_39 = V_304 - 1 ;
if ( F_99 ( & V_302 -> V_305 ,
( const char V_13 * ) V_7 -> V_77 , V_39 ) )
return - V_14 ;
for( V_95 = 0 ; V_95 < V_39 ; V_95 ++ )
if ( V_302 -> V_305 [ V_95 ] == 0 )
V_302 -> V_305 [ V_95 ] = ' ' ;
V_302 -> V_305 [ V_39 ] = 0 ;
F_89 () ;
V_302 -> V_286 = F_90 ( F_91 ( V_21 -> V_287 ) ) ;
F_92 () ;
V_302 -> V_288 = F_90 ( V_21 ) ;
V_302 -> V_289 = F_93 ( V_21 ) ;
V_302 -> V_290 = F_94 ( V_21 ) ;
V_95 = V_21 -> V_115 ? F_100 ( ~ V_21 -> V_115 ) + 1 : 0 ;
V_302 -> V_306 = V_95 ;
V_302 -> V_307 = ( V_95 > 5 ) ? '.' : L_1 [ V_95 ] ;
V_302 -> V_308 = V_302 -> V_307 == 'Z' ;
V_302 -> V_309 = F_101 ( V_21 ) ;
V_302 -> V_310 = V_21 -> V_148 ;
F_89 () ;
V_36 = F_102 ( V_21 ) ;
F_103 ( V_302 -> V_311 , F_15 ( V_36 -> V_58 , V_36 -> V_59 ) ) ;
F_104 ( V_302 -> V_312 , F_16 ( V_36 -> V_58 , V_36 -> V_63 ) ) ;
F_92 () ;
strncpy ( V_302 -> V_313 , V_21 -> V_314 , sizeof( V_302 -> V_313 ) ) ;
return 0 ;
}
static void F_105 ( struct V_242 * V_273 , struct V_303 * V_7 )
{
T_1 * V_315 = ( T_1 * ) V_7 -> V_40 ;
int V_95 = 0 ;
do
V_95 += 2 ;
while ( V_315 [ V_95 - 2 ] != V_316 );
F_87 ( V_273 , L_2 , V_317 , V_95 * sizeof( T_1 ) , V_315 ) ;
}
static void F_106 ( struct V_242 * V_273 , T_11 * V_318 ,
const T_12 * V_319 )
{
T_7 V_320 = F_76 () ;
F_78 ( V_321 ) ;
F_107 ( ( T_11 V_13 * ) V_318 , V_319 ) ;
F_78 ( V_320 ) ;
F_87 ( V_273 , L_2 , V_322 , sizeof( * V_318 ) , V_318 ) ;
}
static int F_108 ( struct V_242 * V_273 )
{
struct V_37 * V_38 ;
unsigned V_323 , V_88 , V_324 , V_325 , V_326 ;
T_13 * V_253 ;
T_13 * V_327 ;
char * V_328 , * V_329 ;
V_323 = V_6 -> V_7 -> V_330 ;
V_88 = V_323 * 64 ;
V_324 = ( 2 + 3 * V_323 ) * sizeof( V_253 [ 0 ] ) ;
V_331:
if ( V_88 >= V_332 )
return - V_79 ;
V_88 = F_109 ( V_88 , V_198 ) ;
V_253 = F_110 ( V_88 ) ;
if ( ! V_253 )
return - V_145 ;
V_327 = V_253 + 2 ;
V_328 = V_329 = ( ( char * ) V_253 ) + V_324 ;
V_325 = V_88 - V_324 ;
V_323 = 0 ;
for ( V_38 = V_6 -> V_7 -> V_130 ; V_38 != NULL ; V_38 = V_38 -> V_333 ) {
struct V_82 * V_82 ;
const char * V_334 ;
V_82 = V_38 -> V_215 ;
if ( ! V_82 )
continue;
V_334 = F_111 ( V_82 , V_329 , V_325 ) ;
if ( F_47 ( V_334 ) ) {
if ( F_46 ( V_334 ) == - V_335 ) {
F_112 ( V_253 ) ;
V_88 = V_88 * 5 / 4 ;
goto V_331;
}
continue;
}
V_326 = ( V_329 + V_325 ) - V_334 ;
V_325 = V_334 - V_329 ;
memmove ( V_329 , V_334 , V_326 ) ;
V_329 += V_326 ;
* V_327 ++ = V_38 -> V_226 ;
* V_327 ++ = V_38 -> V_241 ;
* V_327 ++ = V_38 -> V_223 ;
V_323 ++ ;
}
V_253 [ 0 ] = V_323 ;
V_253 [ 1 ] = V_198 ;
V_326 = V_6 -> V_7 -> V_330 - V_323 ;
if ( V_326 != 0 ) {
unsigned V_336 = V_326 * 3 * sizeof( V_253 [ 0 ] ) ;
memmove ( V_328 - V_336 , V_328 ,
V_329 - V_328 ) ;
V_329 -= V_336 ;
}
V_88 = V_329 - ( char * ) V_253 ;
F_87 ( V_273 , L_2 , V_337 , V_88 , V_253 ) ;
return 0 ;
}
static void F_113 ( struct V_276 * V_338 ,
const struct V_339 * V_340 )
{
if ( V_340 -> V_341 )
V_340 -> V_341 ( V_338 , V_340 , 1 ) ;
}
static int F_114 ( struct V_342 * V_343 ,
const struct V_344 * V_345 ,
long V_277 , T_2 * V_346 )
{
unsigned int V_95 ;
unsigned int V_347 = V_345 -> V_348 [ 0 ] . V_326 * V_345 -> V_348 [ 0 ] . V_88 ;
F_88 ( & V_343 -> V_275 , V_343 -> V_338 , V_277 ) ;
( void ) V_345 -> V_348 [ 0 ] . F_115 ( V_343 -> V_338 , & V_345 -> V_348 [ 0 ] , 0 , V_347 ,
& V_343 -> V_275 . V_349 , NULL ) ;
F_87 ( & V_343 -> V_350 [ 0 ] , L_2 , V_351 ,
F_116 ( V_343 -> V_275 , V_347 ) , & V_343 -> V_275 ) ;
* V_346 += F_80 ( & V_343 -> V_350 [ 0 ] ) ;
F_113 ( V_343 -> V_338 , & V_345 -> V_348 [ 0 ] ) ;
for ( V_95 = 1 ; V_95 < V_345 -> V_326 ; ++ V_95 ) {
const struct V_339 * V_340 = & V_345 -> V_348 [ V_95 ] ;
F_113 ( V_343 -> V_338 , V_340 ) ;
if ( V_340 -> V_352 && V_340 -> F_115 &&
( ! V_340 -> V_353 || V_340 -> V_353 ( V_343 -> V_338 , V_340 ) ) ) {
int V_354 ;
T_2 V_88 = V_340 -> V_326 * V_340 -> V_88 ;
void * V_253 = F_33 ( V_88 , V_108 ) ;
if ( F_55 ( ! V_253 ) )
return 0 ;
V_354 = V_340 -> F_115 ( V_343 -> V_338 , V_340 ,
0 , V_88 , V_253 , NULL ) ;
if ( F_55 ( V_354 ) )
F_35 ( V_253 ) ;
else {
if ( V_340 -> V_352 != V_355 )
F_87 ( & V_343 -> V_350 [ V_95 ] , L_3 ,
V_340 -> V_352 ,
V_88 , V_253 ) ;
else {
F_117 ( & V_343 -> V_275 ,
1 , V_347 ) ;
F_87 ( & V_343 -> V_350 [ V_95 ] , L_2 ,
V_355 , V_88 , V_253 ) ;
}
* V_346 += F_80 ( & V_343 -> V_350 [ V_95 ] ) ;
}
}
}
return 1 ;
}
static int F_118 ( struct V_17 * V_112 , int V_356 ,
struct V_357 * V_358 ,
const T_12 * V_319 , struct V_164 * V_165 )
{
struct V_276 * V_359 = V_6 ;
const struct V_344 * V_345 = F_119 ( V_359 ) ;
struct V_342 * V_343 ;
struct V_301 * V_302 ;
struct V_360 * V_361 ;
unsigned int V_95 ;
V_358 -> V_88 = 0 ;
V_358 -> V_362 = NULL ;
V_302 = F_33 ( sizeof( * V_302 ) , V_108 ) ;
if ( V_302 == NULL ) {
V_358 -> V_302 . V_253 = NULL ;
return 0 ;
}
F_87 ( & V_358 -> V_302 , L_2 , V_363 , sizeof( * V_302 ) , V_302 ) ;
V_358 -> V_364 = 0 ;
for ( V_95 = 0 ; V_95 < V_345 -> V_326 ; ++ V_95 )
if ( V_345 -> V_348 [ V_95 ] . V_352 != 0 )
++ V_358 -> V_364 ;
if ( F_55 ( V_358 -> V_364 == 0 ) ||
F_55 ( V_345 -> V_348 [ 0 ] . V_352 != V_351 ) ) {
F_120 ( 1 ) ;
return 0 ;
}
F_85 ( V_112 , V_356 ,
V_345 -> V_265 , V_345 -> V_267 ) ;
for ( V_361 = & V_359 -> V_7 -> V_365 -> V_366 ; V_361 ; V_361 = V_361 -> V_367 ) {
V_343 = F_121 ( F_122 ( struct V_342 ,
V_350 [ V_358 -> V_364 ] ) ,
V_108 ) ;
if ( F_55 ( ! V_343 ) )
return 0 ;
V_343 -> V_338 = V_361 -> V_338 ;
if ( V_361 -> V_338 == V_359 || ! V_358 -> V_362 ) {
V_343 -> V_367 = V_358 -> V_362 ;
V_358 -> V_362 = V_343 ;
} else {
V_343 -> V_367 = V_358 -> V_362 -> V_367 ;
V_358 -> V_362 -> V_367 = V_343 ;
}
}
for ( V_343 = V_358 -> V_362 ; V_343 != NULL ; V_343 = V_343 -> V_367 )
if ( ! F_114 ( V_343 , V_345 , V_319 -> V_279 , & V_358 -> V_88 ) )
return 0 ;
F_98 ( V_302 , V_359 -> V_368 , V_359 -> V_7 ) ;
V_358 -> V_88 += F_80 ( & V_358 -> V_302 ) ;
F_106 ( & V_358 -> V_369 , & V_358 -> V_318 , V_319 ) ;
V_358 -> V_88 += F_80 ( & V_358 -> V_369 ) ;
F_105 ( & V_358 -> V_315 , V_6 -> V_7 ) ;
V_358 -> V_88 += F_80 ( & V_358 -> V_315 ) ;
if ( F_108 ( & V_358 -> V_370 ) == 0 )
V_358 -> V_88 += F_80 ( & V_358 -> V_370 ) ;
return 1 ;
}
static T_2 F_123 ( struct V_357 * V_358 )
{
return V_358 -> V_88 ;
}
static int F_124 ( struct V_357 * V_358 ,
struct V_248 * V_249 )
{
bool V_371 = true ;
struct V_342 * V_343 = V_358 -> V_362 ;
do {
int V_95 ;
if ( ! F_82 ( & V_343 -> V_350 [ 0 ] , V_249 ) )
return 0 ;
if ( V_371 && ! F_82 ( & V_358 -> V_302 , V_249 ) )
return 0 ;
if ( V_371 && ! F_82 ( & V_358 -> V_369 , V_249 ) )
return 0 ;
if ( V_371 && ! F_82 ( & V_358 -> V_315 , V_249 ) )
return 0 ;
if ( V_371 && V_358 -> V_370 . V_253 &&
! F_82 ( & V_358 -> V_370 , V_249 ) )
return 0 ;
for ( V_95 = 1 ; V_95 < V_358 -> V_364 ; ++ V_95 )
if ( V_343 -> V_350 [ V_95 ] . V_253 &&
! F_82 ( & V_343 -> V_350 [ V_95 ] , V_249 ) )
return 0 ;
V_371 = false ;
V_343 = V_343 -> V_367 ;
} while ( V_343 );
return 1 ;
}
static void F_125 ( struct V_357 * V_358 )
{
struct V_342 * V_372 = V_358 -> V_362 ;
while ( V_372 ) {
unsigned int V_95 ;
struct V_342 * V_343 = V_372 ;
V_372 = V_343 -> V_367 ;
F_120 ( V_343 -> V_350 [ 0 ] . V_253 && V_343 -> V_350 [ 0 ] . V_253 != & V_343 -> V_275 ) ;
for ( V_95 = 1 ; V_95 < V_358 -> V_364 ; ++ V_95 )
F_35 ( V_343 -> V_350 [ V_95 ] . V_253 ) ;
F_35 ( V_343 ) ;
}
F_35 ( V_358 -> V_302 . V_253 ) ;
F_112 ( V_358 -> V_370 . V_253 ) ;
}
static int F_126 ( long V_277 , struct V_373 * V_343 )
{
int V_244 = 0 ;
struct V_276 * V_21 = V_343 -> V_362 ;
V_343 -> V_374 = 0 ;
F_88 ( & V_343 -> V_275 , V_21 , V_277 ) ;
F_127 ( V_21 , & V_343 -> V_275 . V_349 ) ;
F_87 ( & V_343 -> V_350 [ 0 ] , L_2 , V_351 , sizeof( V_343 -> V_275 ) ,
& ( V_343 -> V_275 ) ) ;
V_343 -> V_374 ++ ;
V_244 += F_80 ( & V_343 -> V_350 [ 0 ] ) ;
if ( ( V_343 -> V_275 . V_375 = F_128 ( V_21 , NULL ,
& V_343 -> V_376 ) ) ) {
F_87 ( & V_343 -> V_350 [ 1 ] , L_2 , V_355 , sizeof( V_343 -> V_376 ) ,
& ( V_343 -> V_376 ) ) ;
V_343 -> V_374 ++ ;
V_244 += F_80 ( & V_343 -> V_350 [ 1 ] ) ;
}
#ifdef F_129
if ( F_130 ( V_21 , & V_343 -> V_377 ) ) {
F_87 ( & V_343 -> V_350 [ 2 ] , L_3 , V_378 ,
sizeof( V_343 -> V_377 ) , & V_343 -> V_377 ) ;
V_343 -> V_374 ++ ;
V_244 += F_80 ( & V_343 -> V_350 [ 2 ] ) ;
}
#endif
return V_244 ;
}
static int F_131 ( struct V_357 * V_358 )
{
memset ( V_358 , 0 , sizeof( * V_358 ) ) ;
F_132 ( & V_358 -> V_379 ) ;
V_358 -> V_350 = F_33 ( 8 * sizeof( struct V_242 ) , V_108 ) ;
if ( ! V_358 -> V_350 )
return 0 ;
V_358 -> V_302 = F_33 ( sizeof( * V_358 -> V_302 ) , V_108 ) ;
if ( ! V_358 -> V_302 )
return 0 ;
V_358 -> V_275 = F_33 ( sizeof( * V_358 -> V_275 ) , V_108 ) ;
if ( ! V_358 -> V_275 )
return 0 ;
V_358 -> V_376 = F_33 ( sizeof( * V_358 -> V_376 ) , V_108 ) ;
if ( ! V_358 -> V_376 )
return 0 ;
#ifdef F_129
V_358 -> V_377 = F_33 ( sizeof( * V_358 -> V_377 ) , V_108 ) ;
if ( ! V_358 -> V_377 )
return 0 ;
#endif
return 1 ;
}
static int F_118 ( struct V_17 * V_112 , int V_356 ,
struct V_357 * V_358 ,
const T_12 * V_319 , struct V_164 * V_165 )
{
struct V_380 * V_343 ;
struct V_360 * V_361 ;
struct V_373 * V_381 ;
if ( ! F_131 ( V_358 ) )
return 0 ;
for ( V_361 = V_6 -> V_7 -> V_365 -> V_366 . V_367 ;
V_361 ; V_361 = V_361 -> V_367 ) {
V_381 = F_121 ( sizeof( * V_381 ) , V_108 ) ;
if ( ! V_381 )
return 0 ;
V_381 -> V_362 = V_361 -> V_338 ;
F_133 ( & V_381 -> V_382 , & V_358 -> V_379 ) ;
}
F_134 (t, &info->thread_list) {
int V_244 ;
V_381 = F_135 ( V_343 , struct V_373 , V_382 ) ;
V_244 = F_126 ( V_319 -> V_279 , V_381 ) ;
V_358 -> V_383 += V_244 ;
}
memset ( V_358 -> V_275 , 0 , sizeof( * V_358 -> V_275 ) ) ;
F_88 ( V_358 -> V_275 , V_6 , V_319 -> V_279 ) ;
F_136 ( & V_358 -> V_275 -> V_349 , V_165 ) ;
F_85 ( V_112 , V_356 , V_384 , V_385 ) ;
F_87 ( V_358 -> V_350 + 0 , L_2 , V_351 ,
sizeof( * V_358 -> V_275 ) , V_358 -> V_275 ) ;
F_98 ( V_358 -> V_302 , V_6 -> V_368 , V_6 -> V_7 ) ;
F_87 ( V_358 -> V_350 + 1 , L_2 , V_363 ,
sizeof( * V_358 -> V_302 ) , V_358 -> V_302 ) ;
F_106 ( V_358 -> V_350 + 2 , & V_358 -> V_318 , V_319 ) ;
F_105 ( V_358 -> V_350 + 3 , V_6 -> V_7 ) ;
V_358 -> V_386 = 4 ;
if ( F_108 ( V_358 -> V_350 + V_358 -> V_386 ) == 0 ) {
V_358 -> V_387 = V_358 -> V_350 + V_358 -> V_386 ;
V_358 -> V_386 ++ ;
}
V_358 -> V_275 -> V_375 = F_128 ( V_6 , V_165 ,
V_358 -> V_376 ) ;
if ( V_358 -> V_275 -> V_375 )
F_87 ( V_358 -> V_350 + V_358 -> V_386 ++ ,
L_2 , V_355 , sizeof( * V_358 -> V_376 ) , V_358 -> V_376 ) ;
#ifdef F_129
if ( F_130 ( V_6 , V_358 -> V_377 ) )
F_87 ( V_358 -> V_350 + V_358 -> V_386 ++ ,
L_3 , V_378 ,
sizeof( * V_358 -> V_377 ) , V_358 -> V_377 ) ;
#endif
return 1 ;
}
static T_2 F_123 ( struct V_357 * V_358 )
{
int V_244 = 0 ;
int V_95 ;
for ( V_95 = 0 ; V_95 < V_358 -> V_386 ; V_95 ++ )
V_244 += F_80 ( V_358 -> V_350 + V_95 ) ;
V_244 += V_358 -> V_383 ;
return V_244 ;
}
static int F_124 ( struct V_357 * V_358 ,
struct V_248 * V_249 )
{
int V_95 ;
struct V_380 * V_343 ;
for ( V_95 = 0 ; V_95 < V_358 -> V_386 ; V_95 ++ )
if ( ! F_82 ( V_358 -> V_350 + V_95 , V_249 ) )
return 0 ;
F_134 (t, &info->thread_list) {
struct V_373 * V_388 =
F_135 ( V_343 , struct V_373 , V_382 ) ;
for ( V_95 = 0 ; V_95 < V_388 -> V_374 ; V_95 ++ )
if ( ! F_82 ( & V_388 -> V_350 [ V_95 ] , V_249 ) )
return 0 ;
}
return 1 ;
}
static void F_125 ( struct V_357 * V_358 )
{
while ( ! F_137 ( & V_358 -> V_379 ) ) {
struct V_380 * V_388 = V_358 -> V_379 . V_367 ;
F_138 ( V_388 ) ;
F_35 ( F_135 ( V_388 , struct V_373 , V_382 ) ) ;
}
if ( V_358 -> V_387 )
F_112 ( V_358 -> V_387 -> V_253 ) ;
F_35 ( V_358 -> V_275 ) ;
F_35 ( V_358 -> V_302 ) ;
F_35 ( V_358 -> V_350 ) ;
F_35 ( V_358 -> V_376 ) ;
#ifdef F_129
F_35 ( V_358 -> V_377 ) ;
#endif
}
static struct V_37 * F_139 ( struct V_276 * V_389 ,
struct V_37 * V_390 )
{
struct V_37 * V_354 = V_389 -> V_7 -> V_130 ;
if ( V_354 )
return V_354 ;
return V_390 ;
}
static struct V_37 * F_140 ( struct V_37 * V_391 ,
struct V_37 * V_390 )
{
struct V_37 * V_354 ;
V_354 = V_391 -> V_333 ;
if ( V_354 )
return V_354 ;
if ( V_391 == V_390 )
return NULL ;
return V_390 ;
}
static void F_141 ( struct V_17 * V_112 , struct V_392 * V_393 ,
T_1 V_394 , int V_254 )
{
V_112 -> V_394 = V_394 ;
V_112 -> V_395 = sizeof( * V_393 ) ;
V_112 -> V_396 = 1 ;
V_112 -> V_397 = V_398 ;
memset ( V_393 , 0 , sizeof( * V_393 ) ) ;
V_393 -> V_399 = V_400 ;
V_393 -> V_401 = V_112 -> V_396 ;
V_393 -> V_402 = V_112 -> V_397 ;
V_393 -> V_403 = V_254 ;
}
static int F_142 ( struct V_248 * V_249 )
{
int V_404 = 0 ;
T_7 V_228 ;
int V_254 , V_95 ;
T_2 V_405 = 0 ;
struct V_37 * V_38 , * V_390 ;
struct V_17 * V_112 = NULL ;
T_9 V_269 = 0 , V_406 ;
struct V_357 V_358 = { } ;
struct V_50 * V_407 = NULL ;
struct V_392 * V_393 = NULL ;
T_14 V_52 ;
T_1 V_394 ;
T_1 * V_408 = NULL ;
V_112 = F_33 ( sizeof( * V_112 ) , V_108 ) ;
if ( ! V_112 )
goto V_107;
V_254 = V_6 -> V_7 -> V_330 ;
V_254 += F_143 () ;
V_390 = F_70 ( V_6 -> V_7 ) ;
if ( V_390 != NULL )
V_254 ++ ;
V_254 ++ ;
V_52 = V_254 > V_409 ? V_409 : V_254 ;
if ( ! F_118 ( V_112 , V_52 , & V_358 , V_249 -> V_319 , V_249 -> V_165 ) )
goto V_410;
V_404 = 1 ;
V_228 = F_76 () ;
F_78 ( V_321 ) ;
V_269 += sizeof( * V_112 ) ;
V_269 += V_254 * sizeof( struct V_50 ) ;
{
T_2 V_244 = F_123 ( & V_358 ) ;
V_244 += F_144 () ;
V_407 = F_33 ( sizeof( * V_407 ) , V_108 ) ;
if ( ! V_407 )
goto V_411;
F_86 ( V_407 , V_244 , V_269 ) ;
V_269 += V_244 ;
}
V_406 = V_269 = F_81 ( V_269 , V_44 ) ;
if ( V_254 - 1 > V_412 / sizeof( * V_408 ) )
goto V_411;
V_408 = F_110 ( ( V_254 - 1 ) * sizeof( * V_408 ) ) ;
if ( ! V_408 )
goto V_411;
for ( V_95 = 0 , V_38 = F_139 ( V_6 , V_390 ) ; V_38 != NULL ;
V_38 = F_140 ( V_38 , V_390 ) ) {
unsigned long V_413 ;
V_413 = F_72 ( V_38 , V_249 -> V_204 ) ;
V_408 [ V_95 ++ ] = V_413 ;
V_405 += V_413 ;
}
V_269 += V_405 ;
V_269 += F_145 () ;
V_394 = V_269 ;
if ( V_52 == V_409 ) {
V_393 = F_33 ( sizeof( * V_393 ) , V_108 ) ;
if ( ! V_393 )
goto V_411;
F_141 ( V_112 , V_393 , V_394 , V_254 ) ;
}
V_269 = V_406 ;
if ( ! F_83 ( V_249 , V_112 , sizeof( * V_112 ) ) )
goto V_411;
if ( ! F_83 ( V_249 , V_407 , sizeof( * V_407 ) ) )
goto V_411;
for ( V_95 = 0 , V_38 = F_139 ( V_6 , V_390 ) ; V_38 != NULL ;
V_38 = F_140 ( V_38 , V_390 ) ) {
struct V_50 V_111 ;
V_111 . V_98 = V_99 ;
V_111 . V_92 = V_269 ;
V_111 . V_90 = V_38 -> V_226 ;
V_111 . V_271 = 0 ;
V_111 . V_89 = V_408 [ V_95 ++ ] ;
V_111 . V_100 = V_38 -> V_241 - V_38 -> V_226 ;
V_269 += V_111 . V_89 ;
V_111 . V_137 = V_38 -> V_206 & V_224 ? V_138 : 0 ;
if ( V_38 -> V_206 & V_414 )
V_111 . V_137 |= V_140 ;
if ( V_38 -> V_206 & V_5 )
V_111 . V_137 |= V_142 ;
V_111 . V_272 = V_44 ;
if ( ! F_83 ( V_249 , & V_111 , sizeof( V_111 ) ) )
goto V_411;
}
if ( ! F_146 ( V_249 , V_269 ) )
goto V_411;
if ( ! F_124 ( & V_358 , V_249 ) )
goto V_411;
if ( F_147 ( V_249 ) )
goto V_411;
if ( ! F_148 ( V_249 , V_406 - V_249 -> V_415 ) )
goto V_411;
for ( V_95 = 0 , V_38 = F_139 ( V_6 , V_390 ) ; V_38 != NULL ;
V_38 = F_140 ( V_38 , V_390 ) ) {
unsigned long V_84 ;
unsigned long V_2 ;
V_2 = V_38 -> V_226 + V_408 [ V_95 ++ ] ;
for ( V_84 = V_38 -> V_226 ; V_84 < V_2 ; V_84 += V_198 ) {
struct V_416 * V_416 ;
int V_417 ;
V_416 = F_149 ( V_84 ) ;
if ( V_416 ) {
void * V_418 = F_150 ( V_416 ) ;
V_417 = ! F_83 ( V_249 , V_418 , V_198 ) ;
F_151 ( V_416 ) ;
F_152 ( V_416 ) ;
} else
V_417 = ! F_148 ( V_249 , V_198 ) ;
if ( V_417 )
goto V_411;
}
}
F_153 ( V_249 ) ;
if ( ! F_154 ( V_249 ) )
goto V_411;
if ( V_52 == V_409 ) {
if ( ! F_83 ( V_249 , V_393 , sizeof( * V_393 ) ) )
goto V_411;
}
V_411:
F_78 ( V_228 ) ;
V_410:
F_125 ( & V_358 ) ;
F_35 ( V_393 ) ;
F_112 ( V_408 ) ;
F_35 ( V_407 ) ;
F_35 ( V_112 ) ;
V_107:
return V_404 ;
}
static int T_15 F_155 ( void )
{
F_156 ( & V_195 ) ;
return 0 ;
}
static void T_16 F_157 ( void )
{
F_158 ( & V_195 ) ;
}
