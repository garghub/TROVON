static int F_1 ( unsigned long V_1 , unsigned long V_2 )
{
V_1 = F_2 ( V_1 ) ;
V_2 = F_2 ( V_2 ) ;
if ( V_2 > V_1 ) {
unsigned long V_3 ;
V_3 = F_3 ( V_1 , V_2 - V_1 ) ;
if ( F_4 ( V_3 ) )
return V_3 ;
}
V_4 -> V_5 -> V_6 = V_4 -> V_5 -> V_7 = V_2 ;
return 0 ;
}
static int F_5 ( unsigned long V_8 )
{
unsigned long V_9 ;
V_9 = F_6 ( V_8 ) ;
if ( V_9 ) {
V_9 = V_10 - V_9 ;
if ( F_7 ( ( void V_11 * ) V_8 , V_9 ) )
return - V_12 ;
}
return 0 ;
}
static int
F_8 ( struct V_13 * V_14 , struct V_15 * V_16 ,
unsigned long V_17 , unsigned long V_18 )
{
unsigned long V_19 = V_14 -> V_19 ;
int V_20 = V_14 -> V_20 ;
int V_21 = V_14 -> V_21 ;
T_1 V_11 * V_22 ;
T_1 V_11 * V_23 ;
T_1 V_11 * V_24 ;
T_1 V_11 * V_25 ;
T_1 V_11 * V_26 ;
T_1 V_11 * V_27 ;
const char * V_28 = V_29 ;
const char * V_30 = V_31 ;
unsigned char V_32 [ 16 ] ;
int V_33 ;
T_1 * V_34 ;
int V_35 = 0 ;
const struct V_36 * V_36 = F_9 () ;
struct V_37 * V_38 ;
V_19 = F_10 ( V_19 ) ;
V_25 = NULL ;
if ( V_28 ) {
T_2 V_39 = strlen ( V_28 ) + 1 ;
V_25 = ( T_1 V_11 * ) F_11 ( V_19 , V_39 ) ;
if ( F_12 ( V_25 , V_28 , V_39 ) )
return - V_12 ;
}
V_26 = NULL ;
if ( V_30 ) {
T_2 V_39 = strlen ( V_30 ) + 1 ;
V_26 = ( T_1 V_11 * ) F_11 ( V_19 , V_39 ) ;
if ( F_12 ( V_26 , V_30 , V_39 ) )
return - V_12 ;
}
F_13 ( V_32 , sizeof( V_32 ) ) ;
V_27 = ( T_1 V_11 * )
F_11 ( V_19 , sizeof( V_32 ) ) ;
if ( F_12 ( V_27 , V_32 , sizeof( V_32 ) ) )
return - V_12 ;
V_34 = ( T_1 * ) V_4 -> V_5 -> V_40 ;
#define F_14 ( T_3 , T_4 ) \
do { \
elf_info[ei_index++] = id; \
elf_info[ei_index++] = val; \
} while (0)
#ifdef F_15
F_15 ;
#endif
F_14 ( V_41 , V_42 ) ;
F_14 ( V_43 , V_44 ) ;
F_14 ( V_45 , V_46 ) ;
F_14 ( V_47 , V_17 + V_16 -> V_48 ) ;
F_14 ( V_49 , sizeof( struct V_50 ) ) ;
F_14 ( V_51 , V_16 -> V_52 ) ;
F_14 ( V_53 , V_18 ) ;
F_14 ( V_54 , 0 ) ;
F_14 ( V_55 , V_16 -> V_56 ) ;
F_14 ( V_57 , F_16 ( V_36 -> V_58 , V_36 -> V_59 ) ) ;
F_14 ( V_60 , F_16 ( V_36 -> V_58 , V_36 -> V_61 ) ) ;
F_14 ( V_62 , F_17 ( V_36 -> V_58 , V_36 -> V_63 ) ) ;
F_14 ( V_64 , F_17 ( V_36 -> V_58 , V_36 -> V_65 ) ) ;
F_14 ( V_66 , F_18 ( V_14 ) ) ;
F_14 ( V_67 , ( T_1 ) ( unsigned long ) V_27 ) ;
#ifdef F_19
F_14 ( V_68 , F_19 ) ;
#endif
F_14 ( V_69 , V_14 -> V_16 ) ;
if ( V_28 ) {
F_14 ( V_70 ,
( T_1 ) ( unsigned long ) V_25 ) ;
}
if ( V_30 ) {
F_14 ( V_71 ,
( T_1 ) ( unsigned long ) V_26 ) ;
}
if ( V_14 -> V_72 & V_73 ) {
F_14 ( V_74 , V_14 -> V_75 ) ;
}
#undef F_14
memset ( & V_34 [ V_35 ] , 0 ,
sizeof V_4 -> V_5 -> V_40 - V_35 * sizeof V_34 [ 0 ] ) ;
V_35 += 2 ;
V_24 = F_20 ( V_19 , V_35 ) ;
V_33 = ( V_20 + 1 ) + ( V_21 + 1 ) + 1 ;
V_14 -> V_19 = F_21 ( V_24 , V_33 ) ;
#ifdef F_22
V_24 = ( T_1 V_11 * ) V_14 -> V_19 - V_33 - V_35 ;
V_14 -> V_16 = ( unsigned long ) V_24 ;
#else
V_24 = ( T_1 V_11 * ) V_14 -> V_19 ;
#endif
V_38 = F_23 ( V_4 -> V_5 , V_14 -> V_19 ) ;
if ( ! V_38 )
return - V_12 ;
if ( F_24 ( V_20 , V_24 ++ ) )
return - V_12 ;
V_22 = V_24 ;
V_23 = V_22 + V_20 + 1 ;
V_19 = V_4 -> V_5 -> V_76 = V_4 -> V_5 -> V_77 ;
while ( V_20 -- > 0 ) {
T_2 V_39 ;
if ( F_24 ( ( T_1 ) V_19 , V_22 ++ ) )
return - V_12 ;
V_39 = F_25 ( ( void V_11 * ) V_19 , V_78 ) ;
if ( ! V_39 || V_39 > V_78 )
return - V_79 ;
V_19 += V_39 ;
}
if ( F_24 ( 0 , V_22 ) )
return - V_12 ;
V_4 -> V_5 -> V_76 = V_4 -> V_5 -> V_80 = V_19 ;
while ( V_21 -- > 0 ) {
T_2 V_39 ;
if ( F_24 ( ( T_1 ) V_19 , V_23 ++ ) )
return - V_12 ;
V_39 = F_25 ( ( void V_11 * ) V_19 , V_78 ) ;
if ( ! V_39 || V_39 > V_78 )
return - V_79 ;
V_19 += V_39 ;
}
if ( F_24 ( 0 , V_23 ) )
return - V_12 ;
V_4 -> V_5 -> V_81 = V_19 ;
V_24 = ( T_1 V_11 * ) V_23 + 1 ;
if ( F_26 ( V_24 , V_34 , V_35 * sizeof( T_1 ) ) )
return - V_12 ;
return 0 ;
}
static unsigned long F_27 ( struct V_82 * V_83 , unsigned long V_3 ,
struct V_50 * V_84 , int V_85 , int type ,
unsigned long V_86 )
{
unsigned long V_87 ;
unsigned long V_88 = V_84 -> V_89 + F_6 ( V_84 -> V_90 ) ;
unsigned long V_91 = V_84 -> V_92 - F_6 ( V_84 -> V_90 ) ;
V_3 = F_28 ( V_3 ) ;
V_88 = F_2 ( V_88 ) ;
if ( ! V_88 )
return V_3 ;
if ( V_86 ) {
V_86 = F_2 ( V_86 ) ;
V_87 = F_29 ( V_83 , V_3 , V_86 , V_85 , type , V_91 ) ;
if ( ! F_4 ( V_87 ) )
F_30 ( V_87 + V_88 , V_86 - V_88 ) ;
} else
V_87 = F_29 ( V_83 , V_3 , V_88 , V_85 , type , V_91 ) ;
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
F_28 ( V_93 [ V_96 ] . V_90 ) ;
}
static struct V_50 * F_32 ( struct V_15 * V_101 ,
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
if ( V_88 > V_10 )
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
static inline int F_36 ( struct V_15 * V_110 ,
struct V_50 * V_111 ,
struct V_82 * V_112 , bool V_113 ,
struct V_114 * V_115 )
{
return 0 ;
}
static inline int F_37 ( struct V_15 * V_110 , bool V_116 ,
struct V_114 * V_115 )
{
return 0 ;
}
static unsigned long F_38 ( struct V_15 * V_117 ,
struct V_82 * V_118 , unsigned long * V_119 ,
unsigned long V_120 , struct V_50 * V_121 )
{
struct V_50 * V_84 ;
unsigned long V_17 = 0 ;
int V_122 = 0 ;
unsigned long V_123 = 0 , V_8 = 0 ;
unsigned long error = ~ 0UL ;
unsigned long V_86 ;
int V_95 ;
if ( V_117 -> V_124 != V_125 &&
V_117 -> V_124 != V_126 )
goto V_107;
if ( ! F_39 ( V_117 ) )
goto V_107;
if ( ! V_118 -> V_127 -> V_128 )
goto V_107;
V_86 = F_31 ( V_121 ,
V_117 -> V_52 ) ;
if ( ! V_86 ) {
error = - V_79 ;
goto V_107;
}
V_84 = V_121 ;
for ( V_95 = 0 ; V_95 < V_117 -> V_52 ; V_95 ++ , V_84 ++ ) {
if ( V_84 -> V_98 == V_99 ) {
int V_129 = V_130 | V_131 ;
int V_132 = 0 ;
unsigned long V_133 = 0 ;
unsigned long V_134 , V_87 ;
if ( V_84 -> V_135 & V_136 )
V_132 = V_137 ;
if ( V_84 -> V_135 & V_138 )
V_132 |= V_139 ;
if ( V_84 -> V_135 & V_140 )
V_132 |= V_141 ;
V_133 = V_84 -> V_90 ;
if ( V_117 -> V_124 == V_125 || V_122 )
V_129 |= V_142 ;
else if ( V_120 && V_117 -> V_124 == V_126 )
V_17 = - V_133 ;
V_87 = F_27 ( V_118 , V_17 + V_133 ,
V_84 , V_132 , V_129 , V_86 ) ;
V_86 = 0 ;
if ( ! * V_119 )
* V_119 = V_87 ;
error = V_87 ;
if ( F_4 ( V_87 ) )
goto V_107;
if ( ! V_122 &&
V_117 -> V_124 == V_126 ) {
V_17 = V_87 - F_28 ( V_133 ) ;
V_122 = 1 ;
}
V_134 = V_17 + V_84 -> V_90 ;
if ( F_4 ( V_134 ) ||
V_84 -> V_89 > V_84 -> V_100 ||
V_84 -> V_100 > V_143 ||
V_143 - V_84 -> V_100 < V_134 ) {
error = - V_144 ;
goto V_107;
}
V_134 = V_17 + V_84 -> V_90 + V_84 -> V_89 ;
if ( V_134 > V_8 )
V_8 = V_134 ;
V_134 = V_17 + V_84 -> V_100 + V_84 -> V_90 ;
if ( V_134 > V_123 )
V_123 = V_134 ;
}
}
if ( V_123 > V_8 ) {
if ( F_5 ( V_8 ) ) {
error = - V_12 ;
goto V_107;
}
V_8 = F_28 ( V_8 + V_10 - 1 ) ;
error = F_3 ( V_8 , V_123 - V_8 ) ;
if ( F_4 ( error ) )
goto V_107;
}
error = V_17 ;
V_107:
return error ;
}
static unsigned long F_40 ( unsigned long V_145 )
{
unsigned long V_146 = 0 ;
if ( ( V_4 -> V_147 & V_148 ) &&
! ( V_4 -> V_149 & V_150 ) ) {
V_146 = ( unsigned long ) F_41 () ;
V_146 &= V_151 ;
V_146 <<= V_152 ;
}
#ifdef F_22
return F_42 ( V_145 ) + V_146 ;
#else
return F_42 ( V_145 ) - V_146 ;
#endif
}
static int F_43 ( struct V_13 * V_14 )
{
struct V_82 * V_118 = NULL ;
unsigned long V_17 = 0 , V_153 = 0 ;
int V_122 = 0 ;
char * V_154 = NULL ;
unsigned long error ;
struct V_50 * V_155 , * V_103 , * V_121 = NULL ;
unsigned long V_8 , V_156 ;
int V_104 , V_95 ;
unsigned long V_157 ;
unsigned long V_18 = 0 ;
unsigned long V_158 , V_159 , V_160 , V_161 ;
unsigned long T_5 V_162 = 0 ;
int V_163 = V_164 ;
struct V_165 * V_166 = F_44 () ;
struct {
struct V_15 V_101 ;
struct V_15 V_117 ;
} * V_167 ;
struct V_114 V_168 = V_169 ;
V_167 = F_33 ( sizeof( * V_167 ) , V_108 ) ;
if ( ! V_167 ) {
V_104 = - V_144 ;
goto V_170;
}
V_167 -> V_101 = * ( (struct V_15 * ) V_14 -> V_171 ) ;
V_104 = - V_172 ;
if ( memcmp ( V_167 -> V_101 . V_173 , V_174 , V_175 ) != 0 )
goto V_107;
if ( V_167 -> V_101 . V_124 != V_125 && V_167 -> V_101 . V_124 != V_126 )
goto V_107;
if ( ! F_39 ( & V_167 -> V_101 ) )
goto V_107;
if ( ! V_14 -> V_82 -> V_127 -> V_128 )
goto V_107;
V_103 = F_32 ( & V_167 -> V_101 , V_14 -> V_82 ) ;
if ( ! V_103 )
goto V_107;
V_155 = V_103 ;
V_8 = 0 ;
V_156 = 0 ;
V_158 = ~ 0UL ;
V_159 = 0 ;
V_160 = 0 ;
V_161 = 0 ;
for ( V_95 = 0 ; V_95 < V_167 -> V_101 . V_52 ; V_95 ++ ) {
if ( V_155 -> V_98 == V_176 ) {
V_104 = - V_172 ;
if ( V_155 -> V_89 > V_177 ||
V_155 -> V_89 < 2 )
goto V_178;
V_104 = - V_144 ;
V_154 = F_33 ( V_155 -> V_89 ,
V_108 ) ;
if ( ! V_154 )
goto V_178;
V_104 = F_34 ( V_14 -> V_82 , V_155 -> V_92 ,
V_154 ,
V_155 -> V_89 ) ;
if ( V_104 != V_155 -> V_89 ) {
if ( V_104 >= 0 )
V_104 = - V_109 ;
goto V_179;
}
V_104 = - V_172 ;
if ( V_154 [ V_155 -> V_89 - 1 ] != '\0' )
goto V_179;
V_118 = F_45 ( V_154 ) ;
V_104 = F_46 ( V_118 ) ;
if ( F_47 ( V_118 ) )
goto V_179;
F_48 ( V_14 , V_118 ) ;
V_104 = F_34 ( V_118 , 0 ,
( void * ) & V_167 -> V_117 ,
sizeof( V_167 -> V_117 ) ) ;
if ( V_104 != sizeof( V_167 -> V_117 ) ) {
if ( V_104 >= 0 )
V_104 = - V_109 ;
goto V_180;
}
break;
}
V_155 ++ ;
}
V_155 = V_103 ;
for ( V_95 = 0 ; V_95 < V_167 -> V_101 . V_52 ; V_95 ++ , V_155 ++ )
switch ( V_155 -> V_98 ) {
case V_181 :
if ( V_155 -> V_135 & V_140 )
V_163 = V_182 ;
else
V_163 = V_183 ;
break;
case V_184 ... V_185 :
V_104 = F_36 ( & V_167 -> V_101 , V_155 ,
V_14 -> V_82 , false ,
& V_168 ) ;
if ( V_104 )
goto V_180;
break;
}
if ( V_154 ) {
V_104 = - V_186 ;
if ( memcmp ( V_167 -> V_117 . V_173 , V_174 , V_175 ) != 0 )
goto V_180;
if ( ! F_39 ( & V_167 -> V_117 ) )
goto V_180;
V_121 = F_32 ( & V_167 -> V_117 ,
V_118 ) ;
if ( ! V_121 )
goto V_180;
V_155 = V_121 ;
for ( V_95 = 0 ; V_95 < V_167 -> V_117 . V_52 ; V_95 ++ , V_155 ++ )
switch ( V_155 -> V_98 ) {
case V_184 ... V_185 :
V_104 = F_36 ( & V_167 -> V_117 ,
V_155 , V_118 ,
true , & V_168 ) ;
if ( V_104 )
goto V_180;
break;
}
}
V_104 = F_37 ( & V_167 -> V_101 , ! ! V_118 , & V_168 ) ;
if ( V_104 )
goto V_180;
V_104 = F_49 ( V_14 ) ;
if ( V_104 )
goto V_180;
F_50 ( V_167 -> V_101 , & V_168 ) ;
if ( F_51 ( V_167 -> V_101 , V_163 ) )
V_4 -> V_149 |= V_187 ;
if ( ! ( V_4 -> V_149 & V_150 ) && V_188 )
V_4 -> V_147 |= V_148 ;
F_52 ( V_14 ) ;
V_104 = F_53 ( V_14 , F_40 ( V_189 ) ,
V_163 ) ;
if ( V_104 < 0 )
goto V_180;
V_4 -> V_5 -> V_190 = V_14 -> V_19 ;
for( V_95 = 0 , V_155 = V_103 ;
V_95 < V_167 -> V_101 . V_52 ; V_95 ++ , V_155 ++ ) {
int V_132 = 0 , V_191 ;
unsigned long V_134 , V_133 ;
unsigned long V_86 = 0 ;
if ( V_155 -> V_98 != V_99 )
continue;
if ( F_54 ( V_156 > V_8 ) ) {
unsigned long V_9 ;
V_104 = F_1 ( V_8 + V_153 ,
V_156 + V_153 ) ;
if ( V_104 )
goto V_180;
V_9 = F_6 ( V_8 ) ;
if ( V_9 ) {
V_9 = V_10 - V_9 ;
if ( V_9 > V_156 - V_8 )
V_9 = V_156 - V_8 ;
if ( F_7 ( ( void V_11 * ) V_8 +
V_153 , V_9 ) ) {
}
}
}
if ( V_155 -> V_135 & V_136 )
V_132 |= V_137 ;
if ( V_155 -> V_135 & V_138 )
V_132 |= V_139 ;
if ( V_155 -> V_135 & V_140 )
V_132 |= V_141 ;
V_191 = V_130 | V_131 | V_192 ;
V_133 = V_155 -> V_90 ;
if ( V_167 -> V_101 . V_124 == V_125 || V_122 ) {
V_191 |= V_142 ;
} else if ( V_167 -> V_101 . V_124 == V_126 ) {
V_153 = V_193 - V_133 ;
if ( V_4 -> V_147 & V_148 )
V_153 += F_55 () ;
V_153 = F_28 ( V_153 ) ;
V_86 = F_31 ( V_103 ,
V_167 -> V_101 . V_52 ) ;
if ( ! V_86 ) {
V_104 = - V_79 ;
goto V_180;
}
}
error = F_27 ( V_14 -> V_82 , V_153 + V_133 , V_155 ,
V_132 , V_191 , V_86 ) ;
if ( F_4 ( error ) ) {
V_104 = F_47 ( ( void * ) error ) ?
F_46 ( ( void * ) error ) : - V_79 ;
goto V_180;
}
if ( ! V_122 ) {
V_122 = 1 ;
V_17 = ( V_155 -> V_90 - V_155 -> V_92 ) ;
if ( V_167 -> V_101 . V_124 == V_126 ) {
V_153 += error -
F_28 ( V_153 + V_133 ) ;
V_17 += V_153 ;
T_5 = V_153 ;
}
}
V_134 = V_155 -> V_90 ;
if ( V_134 < V_158 )
V_158 = V_134 ;
if ( V_160 < V_134 )
V_160 = V_134 ;
if ( F_4 ( V_134 ) || V_155 -> V_89 > V_155 -> V_100 ||
V_155 -> V_100 > V_143 ||
V_143 - V_155 -> V_100 < V_134 ) {
V_104 = - V_79 ;
goto V_180;
}
V_134 = V_155 -> V_90 + V_155 -> V_89 ;
if ( V_134 > V_8 )
V_8 = V_134 ;
if ( ( V_155 -> V_135 & V_140 ) && V_159 < V_134 )
V_159 = V_134 ;
if ( V_161 < V_134 )
V_161 = V_134 ;
V_134 = V_155 -> V_90 + V_155 -> V_100 ;
if ( V_134 > V_156 )
V_156 = V_134 ;
}
V_167 -> V_101 . V_56 += V_153 ;
V_8 += V_153 ;
V_156 += V_153 ;
V_158 += V_153 ;
V_159 += V_153 ;
V_160 += V_153 ;
V_161 += V_153 ;
V_104 = F_1 ( V_8 , V_156 ) ;
if ( V_104 )
goto V_180;
if ( F_56 ( V_8 != V_156 ) && F_54 ( F_5 ( V_8 ) ) ) {
V_104 = - V_12 ;
goto V_180;
}
if ( V_154 ) {
unsigned long V_119 = 0 ;
V_157 = F_38 ( & V_167 -> V_117 ,
V_118 ,
& V_119 ,
V_153 , V_121 ) ;
if ( ! F_47 ( ( void * ) V_157 ) ) {
V_18 = V_157 ;
V_157 += V_167 -> V_117 . V_56 ;
}
if ( F_4 ( V_157 ) ) {
V_104 = F_47 ( ( void * ) V_157 ) ?
( int ) V_157 : - V_79 ;
goto V_180;
}
T_5 = V_18 ;
F_57 ( V_118 ) ;
F_58 ( V_118 ) ;
F_35 ( V_154 ) ;
} else {
V_157 = V_167 -> V_101 . V_56 ;
if ( F_4 ( V_157 ) ) {
V_104 = - V_79 ;
goto V_180;
}
}
F_35 ( V_121 ) ;
F_35 ( V_103 ) ;
F_59 ( & V_194 ) ;
#ifdef F_60
V_104 = F_61 ( V_14 , ! ! V_154 ) ;
if ( V_104 < 0 )
goto V_107;
#endif
F_62 ( V_14 ) ;
V_104 = F_8 ( V_14 , & V_167 -> V_101 ,
V_17 , V_18 ) ;
if ( V_104 < 0 )
goto V_107;
V_4 -> V_5 -> V_159 = V_159 ;
V_4 -> V_5 -> V_158 = V_158 ;
V_4 -> V_5 -> V_160 = V_160 ;
V_4 -> V_5 -> V_161 = V_161 ;
V_4 -> V_5 -> V_190 = V_14 -> V_19 ;
if ( ( V_4 -> V_147 & V_148 ) && ( V_188 > 1 ) ) {
V_4 -> V_5 -> V_7 = V_4 -> V_5 -> V_6 =
F_63 ( V_4 -> V_5 ) ;
#ifdef F_64
V_4 -> V_195 = 1 ;
#endif
}
if ( V_4 -> V_149 & V_196 ) {
error = F_29 ( NULL , 0 , V_197 , V_137 | V_141 ,
V_142 | V_130 , 0 ) ;
}
#ifdef F_65
F_65 ( V_166 , T_5 ) ;
#endif
F_66 ( V_166 , V_157 , V_14 -> V_19 ) ;
V_104 = 0 ;
V_107:
F_35 ( V_167 ) ;
V_170:
return V_104 ;
V_180:
F_35 ( V_121 ) ;
F_57 ( V_118 ) ;
if ( V_118 )
F_58 ( V_118 ) ;
V_179:
F_35 ( V_154 ) ;
V_178:
F_35 ( V_103 ) ;
goto V_107;
}
static int F_67 ( struct V_82 * V_82 )
{
struct V_50 * V_103 ;
struct V_50 * V_84 ;
unsigned long V_8 , V_198 , V_39 ;
int V_104 , error , V_95 , V_199 ;
struct V_15 V_101 ;
error = - V_172 ;
V_104 = F_34 ( V_82 , 0 , ( char * ) & V_101 , sizeof( V_101 ) ) ;
if ( V_104 != sizeof( V_101 ) )
goto V_107;
if ( memcmp ( V_101 . V_173 , V_174 , V_175 ) != 0 )
goto V_107;
if ( V_101 . V_124 != V_125 || V_101 . V_52 > 2 ||
! F_39 ( & V_101 ) || ! V_82 -> V_127 -> V_128 )
goto V_107;
V_199 = sizeof( struct V_50 ) * V_101 . V_52 ;
error = - V_144 ;
V_103 = F_33 ( V_199 , V_108 ) ;
if ( ! V_103 )
goto V_107;
V_84 = V_103 ;
error = - V_172 ;
V_104 = F_34 ( V_82 , V_101 . V_48 , ( char * ) V_84 , V_199 ) ;
if ( V_104 != V_199 )
goto V_178;
for ( V_199 = 0 , V_95 = 0 ; V_95 < V_101 . V_52 ; V_95 ++ )
if ( ( V_84 + V_95 ) -> V_98 == V_99 )
V_199 ++ ;
if ( V_199 != 1 )
goto V_178;
while ( V_84 -> V_98 != V_99 )
V_84 ++ ;
error = F_29 ( V_82 ,
F_28 ( V_84 -> V_90 ) ,
( V_84 -> V_89 +
F_6 ( V_84 -> V_90 ) ) ,
V_137 | V_139 | V_141 ,
V_142 | V_130 | V_131 ,
( V_84 -> V_92 -
F_6 ( V_84 -> V_90 ) ) ) ;
if ( error != F_28 ( V_84 -> V_90 ) )
goto V_178;
V_8 = V_84 -> V_90 + V_84 -> V_89 ;
if ( F_5 ( V_8 ) ) {
error = - V_12 ;
goto V_178;
}
V_39 = F_28 ( V_84 -> V_89 + V_84 -> V_90 +
V_10 - 1 ) ;
V_198 = V_84 -> V_100 + V_84 -> V_90 ;
if ( V_198 > V_39 )
F_3 ( V_39 , V_198 - V_39 ) ;
error = 0 ;
V_178:
F_35 ( V_103 ) ;
V_107:
return error ;
}
static bool F_68 ( struct V_37 * V_38 )
{
if ( V_38 == F_69 ( V_38 -> V_200 ) )
return true ;
if ( V_38 -> V_201 && V_38 -> V_201 -> V_202 && V_38 -> V_201 -> V_202 ( V_38 ) )
return true ;
if ( F_70 ( V_38 ) )
return true ;
return false ;
}
static unsigned long F_71 ( struct V_37 * V_38 ,
unsigned long V_203 )
{
#define F_72 ( type ) (mm_flags & (1UL << MMF_DUMP_##type))
if ( F_68 ( V_38 ) )
goto V_204;
if ( V_38 -> V_205 & V_206 )
return 0 ;
if ( F_73 ( V_38 ) ) {
if ( ( V_38 -> V_205 & V_207 ) && F_72 ( V_208 ) )
goto V_204;
if ( ! ( V_38 -> V_205 & V_207 ) && F_72 ( V_209 ) )
goto V_204;
return 0 ;
}
if ( V_38 -> V_205 & V_210 ) {
if ( ( V_38 -> V_205 & V_207 ) && F_72 ( V_211 ) )
goto V_204;
if ( ! ( V_38 -> V_205 & V_207 ) && F_72 ( V_212 ) )
goto V_204;
return 0 ;
}
if ( V_38 -> V_205 & V_213 )
return 0 ;
if ( V_38 -> V_205 & V_207 ) {
if ( F_74 ( V_38 -> V_214 ) -> V_215 == 0 ?
F_72 ( V_216 ) : F_72 ( V_217 ) )
goto V_204;
return 0 ;
}
if ( V_38 -> V_218 && F_72 ( V_219 ) )
goto V_204;
if ( V_38 -> V_214 == NULL )
return 0 ;
if ( F_72 ( V_220 ) )
goto V_204;
if ( F_72 ( V_221 ) &&
V_38 -> V_222 == 0 && ( V_38 -> V_205 & V_223 ) ) {
T_6 V_11 * V_224 = ( T_6 V_11 * ) V_38 -> V_225 ;
T_6 V_226 ;
T_7 V_227 = F_75 () ;
union {
T_6 V_228 ;
char V_229 [ V_175 ] ;
} V_230 ;
F_76 ( V_175 != sizeof V_226 ) ;
V_230 . V_229 [ V_231 ] = V_232 ;
V_230 . V_229 [ V_233 ] = V_234 ;
V_230 . V_229 [ V_235 ] = V_236 ;
V_230 . V_229 [ V_237 ] = V_238 ;
F_77 ( V_239 ) ;
if ( F_54 ( F_78 ( V_226 , V_224 ) ) )
V_226 = 0 ;
F_77 ( V_227 ) ;
if ( V_226 == V_230 . V_228 )
return V_197 ;
}
#undef F_72
return 0 ;
V_204:
return V_38 -> V_240 - V_38 -> V_225 ;
}
static int F_79 ( struct V_241 * V_242 )
{
int V_243 ;
V_243 = sizeof( struct V_244 ) ;
V_243 += F_80 ( strlen ( V_242 -> V_202 ) + 1 , 4 ) ;
V_243 += F_80 ( V_242 -> V_245 , 4 ) ;
return V_243 ;
}
static int F_81 ( struct V_241 * V_246 , struct V_247 * V_248 )
{
struct V_244 V_242 ;
V_242 . V_249 = strlen ( V_246 -> V_202 ) + 1 ;
V_242 . V_250 = V_246 -> V_245 ;
V_242 . V_251 = V_246 -> type ;
return F_82 ( V_248 , & V_242 , sizeof( V_242 ) ) &&
F_82 ( V_248 , V_246 -> V_202 , V_242 . V_249 ) && F_83 ( V_248 , 4 ) &&
F_82 ( V_248 , V_246 -> V_252 , V_246 -> V_245 ) && F_83 ( V_248 , 4 ) ;
}
static void F_84 ( struct V_15 * V_112 , int V_253 ,
T_8 V_254 , T_6 V_147 )
{
memset ( V_112 , 0 , sizeof( * V_112 ) ) ;
memcpy ( V_112 -> V_173 , V_174 , V_175 ) ;
V_112 -> V_173 [ V_255 ] = V_256 ;
V_112 -> V_173 [ V_257 ] = V_258 ;
V_112 -> V_173 [ V_259 ] = V_260 ;
V_112 -> V_173 [ V_261 ] = V_262 ;
V_112 -> V_124 = V_263 ;
V_112 -> V_264 = V_254 ;
V_112 -> V_265 = V_260 ;
V_112 -> V_48 = sizeof( struct V_15 ) ;
V_112 -> V_266 = V_147 ;
V_112 -> V_267 = sizeof( struct V_15 ) ;
V_112 -> V_106 = sizeof( struct V_50 ) ;
V_112 -> V_52 = V_253 ;
return;
}
static void F_85 ( struct V_50 * V_111 , int V_243 , T_9 V_268 )
{
V_111 -> V_98 = V_269 ;
V_111 -> V_92 = V_268 ;
V_111 -> V_90 = 0 ;
V_111 -> V_270 = 0 ;
V_111 -> V_89 = V_243 ;
V_111 -> V_100 = 0 ;
V_111 -> V_135 = 0 ;
V_111 -> V_271 = 0 ;
return;
}
static void F_86 ( struct V_241 * V_272 , const char * V_202 , int type ,
unsigned int V_243 , void * V_252 )
{
V_272 -> V_202 = V_202 ;
V_272 -> type = type ;
V_272 -> V_245 = V_243 ;
V_272 -> V_252 = V_252 ;
return;
}
static void F_87 ( struct V_273 * V_274 ,
struct V_275 * V_19 , long V_276 )
{
V_274 -> V_277 . V_278 = V_274 -> V_279 = V_276 ;
V_274 -> V_280 = V_19 -> V_281 . signal . V_282 [ 0 ] ;
V_274 -> V_283 = V_19 -> V_284 . V_282 [ 0 ] ;
F_88 () ;
V_274 -> V_285 = F_89 ( F_90 ( V_19 -> V_286 ) ) ;
F_91 () ;
V_274 -> V_287 = F_89 ( V_19 ) ;
V_274 -> V_288 = F_92 ( V_19 ) ;
V_274 -> V_289 = F_93 ( V_19 ) ;
if ( F_94 ( V_19 ) ) {
struct V_290 V_291 ;
F_95 ( V_19 , & V_291 ) ;
F_96 ( V_291 . V_292 , & V_274 -> V_293 ) ;
F_96 ( V_291 . V_294 , & V_274 -> V_295 ) ;
} else {
T_10 V_292 , V_294 ;
V_290 ( V_19 , & V_292 , & V_294 ) ;
F_96 ( V_292 , & V_274 -> V_293 ) ;
F_96 ( V_294 , & V_274 -> V_295 ) ;
}
F_96 ( V_19 -> signal -> V_296 , & V_274 -> V_297 ) ;
F_96 ( V_19 -> signal -> V_298 , & V_274 -> V_299 ) ;
}
static int F_97 ( struct V_300 * V_301 , struct V_275 * V_19 ,
struct V_302 * V_5 )
{
const struct V_36 * V_36 ;
unsigned int V_95 , V_39 ;
memset ( V_301 , 0 , sizeof( struct V_300 ) ) ;
V_39 = V_5 -> V_76 - V_5 -> V_77 ;
if ( V_39 >= V_303 )
V_39 = V_303 - 1 ;
if ( F_98 ( & V_301 -> V_304 ,
( const char V_11 * ) V_5 -> V_77 , V_39 ) )
return - V_12 ;
for( V_95 = 0 ; V_95 < V_39 ; V_95 ++ )
if ( V_301 -> V_304 [ V_95 ] == 0 )
V_301 -> V_304 [ V_95 ] = ' ' ;
V_301 -> V_304 [ V_39 ] = 0 ;
F_88 () ;
V_301 -> V_285 = F_89 ( F_90 ( V_19 -> V_286 ) ) ;
F_91 () ;
V_301 -> V_287 = F_89 ( V_19 ) ;
V_301 -> V_288 = F_92 ( V_19 ) ;
V_301 -> V_289 = F_93 ( V_19 ) ;
V_95 = V_19 -> V_115 ? F_99 ( ~ V_19 -> V_115 ) + 1 : 0 ;
V_301 -> V_305 = V_95 ;
V_301 -> V_306 = ( V_95 > 5 ) ? '.' : L_1 [ V_95 ] ;
V_301 -> V_307 = V_301 -> V_306 == 'Z' ;
V_301 -> V_308 = F_100 ( V_19 ) ;
V_301 -> V_309 = V_19 -> V_147 ;
F_88 () ;
V_36 = F_101 ( V_19 ) ;
F_102 ( V_301 -> V_310 , F_16 ( V_36 -> V_58 , V_36 -> V_59 ) ) ;
F_103 ( V_301 -> V_311 , F_17 ( V_36 -> V_58 , V_36 -> V_63 ) ) ;
F_91 () ;
strncpy ( V_301 -> V_312 , V_19 -> V_313 , sizeof( V_301 -> V_312 ) ) ;
return 0 ;
}
static void F_104 ( struct V_241 * V_272 , struct V_302 * V_5 )
{
T_1 * V_314 = ( T_1 * ) V_5 -> V_40 ;
int V_95 = 0 ;
do
V_95 += 2 ;
while ( V_314 [ V_95 - 2 ] != V_315 );
F_86 ( V_272 , L_2 , V_316 , V_95 * sizeof( T_1 ) , V_314 ) ;
}
static void F_105 ( struct V_241 * V_272 , T_11 * V_317 ,
const T_12 * V_318 )
{
T_7 V_319 = F_75 () ;
F_77 ( V_320 ) ;
F_106 ( ( T_11 V_11 * ) V_317 , V_318 ) ;
F_77 ( V_319 ) ;
F_86 ( V_272 , L_2 , V_321 , sizeof( * V_317 ) , V_317 ) ;
}
static int F_107 ( struct V_241 * V_272 )
{
struct V_37 * V_38 ;
unsigned V_322 , V_88 , V_323 , V_324 , V_325 ;
T_13 * V_252 ;
T_13 * V_326 ;
char * V_327 , * V_328 ;
V_322 = V_4 -> V_5 -> V_329 ;
V_88 = V_322 * 64 ;
V_323 = ( 2 + 3 * V_322 ) * sizeof( V_252 [ 0 ] ) ;
V_330:
if ( V_88 >= V_331 )
return - V_79 ;
V_88 = F_108 ( V_88 , V_197 ) ;
V_252 = F_109 ( V_88 ) ;
if ( ! V_252 )
return - V_144 ;
V_326 = V_252 + 2 ;
V_327 = V_328 = ( ( char * ) V_252 ) + V_323 ;
V_324 = V_88 - V_323 ;
V_322 = 0 ;
for ( V_38 = V_4 -> V_5 -> V_128 ; V_38 != NULL ; V_38 = V_38 -> V_332 ) {
struct V_82 * V_82 ;
const char * V_333 ;
V_82 = V_38 -> V_214 ;
if ( ! V_82 )
continue;
V_333 = F_110 ( V_82 , V_328 , V_324 ) ;
if ( F_47 ( V_333 ) ) {
if ( F_46 ( V_333 ) == - V_334 ) {
F_111 ( V_252 ) ;
V_88 = V_88 * 5 / 4 ;
goto V_330;
}
continue;
}
V_325 = ( V_328 + V_324 ) - V_333 ;
V_324 = V_333 - V_328 ;
memmove ( V_328 , V_333 , V_325 ) ;
V_328 += V_325 ;
* V_326 ++ = V_38 -> V_225 ;
* V_326 ++ = V_38 -> V_240 ;
* V_326 ++ = V_38 -> V_222 ;
V_322 ++ ;
}
V_252 [ 0 ] = V_322 ;
V_252 [ 1 ] = V_197 ;
V_325 = V_4 -> V_5 -> V_329 - V_322 ;
if ( V_325 != 0 ) {
unsigned V_335 = V_325 * 3 * sizeof( V_252 [ 0 ] ) ;
memmove ( V_327 - V_335 , V_327 ,
V_328 - V_327 ) ;
V_328 -= V_335 ;
}
V_88 = V_328 - ( char * ) V_252 ;
F_86 ( V_272 , L_2 , V_336 , V_88 , V_252 ) ;
return 0 ;
}
static void F_112 ( struct V_275 * V_337 ,
const struct V_338 * V_339 )
{
if ( V_339 -> V_340 )
V_339 -> V_340 ( V_337 , V_339 , 1 ) ;
}
static int F_113 ( struct V_341 * V_342 ,
const struct V_343 * V_344 ,
long V_276 , T_2 * V_345 )
{
unsigned int V_95 ;
F_87 ( & V_342 -> V_274 , V_342 -> V_337 , V_276 ) ;
( void ) V_344 -> V_346 [ 0 ] . F_114 ( V_342 -> V_337 , & V_344 -> V_346 [ 0 ] ,
0 , F_115 ( V_342 -> V_274 . V_347 ) ,
F_116 ( & V_342 -> V_274 ) , NULL ) ;
F_86 ( & V_342 -> V_348 [ 0 ] , L_2 , V_349 ,
F_117 ( V_342 -> V_274 ) , & V_342 -> V_274 ) ;
* V_345 += F_79 ( & V_342 -> V_348 [ 0 ] ) ;
F_112 ( V_342 -> V_337 , & V_344 -> V_346 [ 0 ] ) ;
for ( V_95 = 1 ; V_95 < V_344 -> V_325 ; ++ V_95 ) {
const struct V_338 * V_339 = & V_344 -> V_346 [ V_95 ] ;
F_112 ( V_342 -> V_337 , V_339 ) ;
if ( V_339 -> V_350 && V_339 -> F_114 &&
( ! V_339 -> V_351 || V_339 -> V_351 ( V_342 -> V_337 , V_339 ) ) ) {
int V_352 ;
T_2 V_88 = V_339 -> V_325 * V_339 -> V_88 ;
void * V_252 = F_33 ( V_88 , V_108 ) ;
if ( F_54 ( ! V_252 ) )
return 0 ;
V_352 = V_339 -> F_114 ( V_342 -> V_337 , V_339 ,
0 , V_88 , V_252 , NULL ) ;
if ( F_54 ( V_352 ) )
F_35 ( V_252 ) ;
else {
if ( V_339 -> V_350 != V_353 )
F_86 ( & V_342 -> V_348 [ V_95 ] , L_3 ,
V_339 -> V_350 ,
V_88 , V_252 ) ;
else {
F_118 ( & V_342 -> V_274 , 1 ) ;
F_86 ( & V_342 -> V_348 [ V_95 ] , L_2 ,
V_353 , V_88 , V_252 ) ;
}
* V_345 += F_79 ( & V_342 -> V_348 [ V_95 ] ) ;
}
}
}
return 1 ;
}
static int F_119 ( struct V_15 * V_112 , int V_354 ,
struct V_355 * V_356 ,
const T_12 * V_318 , struct V_165 * V_166 )
{
struct V_275 * V_357 = V_4 ;
const struct V_343 * V_344 = F_120 ( V_357 ) ;
struct V_341 * V_342 ;
struct V_300 * V_301 ;
struct V_358 * V_359 ;
unsigned int V_95 ;
V_356 -> V_88 = 0 ;
V_356 -> V_360 = NULL ;
V_301 = F_33 ( sizeof( * V_301 ) , V_108 ) ;
if ( V_301 == NULL ) {
V_356 -> V_301 . V_252 = NULL ;
return 0 ;
}
F_86 ( & V_356 -> V_301 , L_2 , V_361 , sizeof( * V_301 ) , V_301 ) ;
V_356 -> V_362 = 0 ;
for ( V_95 = 0 ; V_95 < V_344 -> V_325 ; ++ V_95 )
if ( V_344 -> V_346 [ V_95 ] . V_350 != 0 )
++ V_356 -> V_362 ;
if ( F_54 ( V_356 -> V_362 == 0 ) ||
F_54 ( V_344 -> V_346 [ 0 ] . V_350 != V_349 ) ) {
F_121 ( 1 ) ;
return 0 ;
}
F_84 ( V_112 , V_354 ,
V_344 -> V_264 , V_344 -> V_266 ) ;
for ( V_359 = & V_357 -> V_5 -> V_363 -> V_364 ; V_359 ; V_359 = V_359 -> V_365 ) {
V_342 = F_122 ( F_123 ( struct V_341 ,
V_348 [ V_356 -> V_362 ] ) ,
V_108 ) ;
if ( F_54 ( ! V_342 ) )
return 0 ;
V_342 -> V_337 = V_359 -> V_337 ;
if ( V_359 -> V_337 == V_357 || ! V_356 -> V_360 ) {
V_342 -> V_365 = V_356 -> V_360 ;
V_356 -> V_360 = V_342 ;
} else {
V_342 -> V_365 = V_356 -> V_360 -> V_365 ;
V_356 -> V_360 -> V_365 = V_342 ;
}
}
for ( V_342 = V_356 -> V_360 ; V_342 != NULL ; V_342 = V_342 -> V_365 )
if ( ! F_113 ( V_342 , V_344 , V_318 -> V_278 , & V_356 -> V_88 ) )
return 0 ;
F_97 ( V_301 , V_357 -> V_366 , V_357 -> V_5 ) ;
V_356 -> V_88 += F_79 ( & V_356 -> V_301 ) ;
F_105 ( & V_356 -> V_367 , & V_356 -> V_317 , V_318 ) ;
V_356 -> V_88 += F_79 ( & V_356 -> V_367 ) ;
F_104 ( & V_356 -> V_314 , V_4 -> V_5 ) ;
V_356 -> V_88 += F_79 ( & V_356 -> V_314 ) ;
if ( F_107 ( & V_356 -> V_368 ) == 0 )
V_356 -> V_88 += F_79 ( & V_356 -> V_368 ) ;
return 1 ;
}
static T_2 F_124 ( struct V_355 * V_356 )
{
return V_356 -> V_88 ;
}
static int F_125 ( struct V_355 * V_356 ,
struct V_247 * V_248 )
{
bool V_369 = true ;
struct V_341 * V_342 = V_356 -> V_360 ;
do {
int V_95 ;
if ( ! F_81 ( & V_342 -> V_348 [ 0 ] , V_248 ) )
return 0 ;
if ( V_369 && ! F_81 ( & V_356 -> V_301 , V_248 ) )
return 0 ;
if ( V_369 && ! F_81 ( & V_356 -> V_367 , V_248 ) )
return 0 ;
if ( V_369 && ! F_81 ( & V_356 -> V_314 , V_248 ) )
return 0 ;
if ( V_369 && V_356 -> V_368 . V_252 &&
! F_81 ( & V_356 -> V_368 , V_248 ) )
return 0 ;
for ( V_95 = 1 ; V_95 < V_356 -> V_362 ; ++ V_95 )
if ( V_342 -> V_348 [ V_95 ] . V_252 &&
! F_81 ( & V_342 -> V_348 [ V_95 ] , V_248 ) )
return 0 ;
V_369 = false ;
V_342 = V_342 -> V_365 ;
} while ( V_342 );
return 1 ;
}
static void F_126 ( struct V_355 * V_356 )
{
struct V_341 * V_370 = V_356 -> V_360 ;
while ( V_370 ) {
unsigned int V_95 ;
struct V_341 * V_342 = V_370 ;
V_370 = V_342 -> V_365 ;
F_121 ( V_342 -> V_348 [ 0 ] . V_252 && V_342 -> V_348 [ 0 ] . V_252 != & V_342 -> V_274 ) ;
for ( V_95 = 1 ; V_95 < V_356 -> V_362 ; ++ V_95 )
F_35 ( V_342 -> V_348 [ V_95 ] . V_252 ) ;
F_35 ( V_342 ) ;
}
F_35 ( V_356 -> V_301 . V_252 ) ;
F_111 ( V_356 -> V_368 . V_252 ) ;
}
static int F_127 ( long V_276 , struct V_371 * V_342 )
{
int V_243 = 0 ;
struct V_275 * V_19 = V_342 -> V_360 ;
V_342 -> V_372 = 0 ;
F_87 ( & V_342 -> V_274 , V_19 , V_276 ) ;
F_128 ( V_19 , & V_342 -> V_274 . V_347 ) ;
F_86 ( & V_342 -> V_348 [ 0 ] , L_2 , V_349 , sizeof( V_342 -> V_274 ) ,
& ( V_342 -> V_274 ) ) ;
V_342 -> V_372 ++ ;
V_243 += F_79 ( & V_342 -> V_348 [ 0 ] ) ;
if ( ( V_342 -> V_274 . V_373 = F_129 ( V_19 , NULL ,
& V_342 -> V_374 ) ) ) {
F_86 ( & V_342 -> V_348 [ 1 ] , L_2 , V_353 , sizeof( V_342 -> V_374 ) ,
& ( V_342 -> V_374 ) ) ;
V_342 -> V_372 ++ ;
V_243 += F_79 ( & V_342 -> V_348 [ 1 ] ) ;
}
#ifdef F_130
if ( F_131 ( V_19 , & V_342 -> V_375 ) ) {
F_86 ( & V_342 -> V_348 [ 2 ] , L_3 , V_376 ,
sizeof( V_342 -> V_375 ) , & V_342 -> V_375 ) ;
V_342 -> V_372 ++ ;
V_243 += F_79 ( & V_342 -> V_348 [ 2 ] ) ;
}
#endif
return V_243 ;
}
static int F_132 ( struct V_355 * V_356 )
{
memset ( V_356 , 0 , sizeof( * V_356 ) ) ;
F_133 ( & V_356 -> V_377 ) ;
V_356 -> V_348 = F_33 ( 8 * sizeof( struct V_241 ) , V_108 ) ;
if ( ! V_356 -> V_348 )
return 0 ;
V_356 -> V_301 = F_33 ( sizeof( * V_356 -> V_301 ) , V_108 ) ;
if ( ! V_356 -> V_301 )
return 0 ;
V_356 -> V_274 = F_33 ( sizeof( * V_356 -> V_274 ) , V_108 ) ;
if ( ! V_356 -> V_274 )
return 0 ;
V_356 -> V_374 = F_33 ( sizeof( * V_356 -> V_374 ) , V_108 ) ;
if ( ! V_356 -> V_374 )
return 0 ;
#ifdef F_130
V_356 -> V_375 = F_33 ( sizeof( * V_356 -> V_375 ) , V_108 ) ;
if ( ! V_356 -> V_375 )
return 0 ;
#endif
return 1 ;
}
static int F_119 ( struct V_15 * V_112 , int V_354 ,
struct V_355 * V_356 ,
const T_12 * V_318 , struct V_165 * V_166 )
{
struct V_378 * V_342 ;
struct V_358 * V_359 ;
struct V_371 * V_379 ;
if ( ! F_132 ( V_356 ) )
return 0 ;
for ( V_359 = V_4 -> V_5 -> V_363 -> V_364 . V_365 ;
V_359 ; V_359 = V_359 -> V_365 ) {
V_379 = F_122 ( sizeof( * V_379 ) , V_108 ) ;
if ( ! V_379 )
return 0 ;
V_379 -> V_360 = V_359 -> V_337 ;
F_134 ( & V_379 -> V_380 , & V_356 -> V_377 ) ;
}
F_135 (t, &info->thread_list) {
int V_243 ;
V_379 = F_136 ( V_342 , struct V_371 , V_380 ) ;
V_243 = F_127 ( V_318 -> V_278 , V_379 ) ;
V_356 -> V_381 += V_243 ;
}
memset ( V_356 -> V_274 , 0 , sizeof( * V_356 -> V_274 ) ) ;
F_87 ( V_356 -> V_274 , V_4 , V_318 -> V_278 ) ;
F_137 ( & V_356 -> V_274 -> V_347 , V_166 ) ;
F_84 ( V_112 , V_354 , V_382 , V_383 ) ;
F_86 ( V_356 -> V_348 + 0 , L_2 , V_349 ,
sizeof( * V_356 -> V_274 ) , V_356 -> V_274 ) ;
F_97 ( V_356 -> V_301 , V_4 -> V_366 , V_4 -> V_5 ) ;
F_86 ( V_356 -> V_348 + 1 , L_2 , V_361 ,
sizeof( * V_356 -> V_301 ) , V_356 -> V_301 ) ;
F_105 ( V_356 -> V_348 + 2 , & V_356 -> V_317 , V_318 ) ;
F_104 ( V_356 -> V_348 + 3 , V_4 -> V_5 ) ;
V_356 -> V_384 = 4 ;
if ( F_107 ( V_356 -> V_348 + V_356 -> V_384 ) == 0 ) {
V_356 -> V_385 = V_356 -> V_348 + V_356 -> V_384 ;
V_356 -> V_384 ++ ;
}
V_356 -> V_274 -> V_373 = F_129 ( V_4 , V_166 ,
V_356 -> V_374 ) ;
if ( V_356 -> V_274 -> V_373 )
F_86 ( V_356 -> V_348 + V_356 -> V_384 ++ ,
L_2 , V_353 , sizeof( * V_356 -> V_374 ) , V_356 -> V_374 ) ;
#ifdef F_130
if ( F_131 ( V_4 , V_356 -> V_375 ) )
F_86 ( V_356 -> V_348 + V_356 -> V_384 ++ ,
L_3 , V_376 ,
sizeof( * V_356 -> V_375 ) , V_356 -> V_375 ) ;
#endif
return 1 ;
}
static T_2 F_124 ( struct V_355 * V_356 )
{
int V_243 = 0 ;
int V_95 ;
for ( V_95 = 0 ; V_95 < V_356 -> V_384 ; V_95 ++ )
V_243 += F_79 ( V_356 -> V_348 + V_95 ) ;
V_243 += V_356 -> V_381 ;
return V_243 ;
}
static int F_125 ( struct V_355 * V_356 ,
struct V_247 * V_248 )
{
int V_95 ;
struct V_378 * V_342 ;
for ( V_95 = 0 ; V_95 < V_356 -> V_384 ; V_95 ++ )
if ( ! F_81 ( V_356 -> V_348 + V_95 , V_248 ) )
return 0 ;
F_135 (t, &info->thread_list) {
struct V_371 * V_386 =
F_136 ( V_342 , struct V_371 , V_380 ) ;
for ( V_95 = 0 ; V_95 < V_386 -> V_372 ; V_95 ++ )
if ( ! F_81 ( & V_386 -> V_348 [ V_95 ] , V_248 ) )
return 0 ;
}
return 1 ;
}
static void F_126 ( struct V_355 * V_356 )
{
while ( ! F_138 ( & V_356 -> V_377 ) ) {
struct V_378 * V_386 = V_356 -> V_377 . V_365 ;
F_139 ( V_386 ) ;
F_35 ( F_136 ( V_386 , struct V_371 , V_380 ) ) ;
}
if ( V_356 -> V_385 )
F_111 ( V_356 -> V_385 -> V_252 ) ;
F_35 ( V_356 -> V_274 ) ;
F_35 ( V_356 -> V_301 ) ;
F_35 ( V_356 -> V_348 ) ;
F_35 ( V_356 -> V_374 ) ;
#ifdef F_130
F_35 ( V_356 -> V_375 ) ;
#endif
}
static struct V_37 * F_140 ( struct V_275 * V_387 ,
struct V_37 * V_388 )
{
struct V_37 * V_352 = V_387 -> V_5 -> V_128 ;
if ( V_352 )
return V_352 ;
return V_388 ;
}
static struct V_37 * F_141 ( struct V_37 * V_389 ,
struct V_37 * V_388 )
{
struct V_37 * V_352 ;
V_352 = V_389 -> V_332 ;
if ( V_352 )
return V_352 ;
if ( V_389 == V_388 )
return NULL ;
return V_388 ;
}
static void F_142 ( struct V_15 * V_112 , struct V_390 * V_391 ,
T_1 V_392 , int V_253 )
{
V_112 -> V_392 = V_392 ;
V_112 -> V_393 = sizeof( * V_391 ) ;
V_112 -> V_394 = 1 ;
V_112 -> V_395 = V_396 ;
memset ( V_391 , 0 , sizeof( * V_391 ) ) ;
V_391 -> V_397 = V_398 ;
V_391 -> V_399 = V_112 -> V_394 ;
V_391 -> V_400 = V_112 -> V_395 ;
V_391 -> V_401 = V_253 ;
}
static int F_143 ( struct V_247 * V_248 )
{
int V_402 = 0 ;
T_7 V_227 ;
int V_253 , V_95 ;
T_2 V_403 = 0 ;
struct V_37 * V_38 , * V_388 ;
struct V_15 * V_112 = NULL ;
T_9 V_268 = 0 , V_404 ;
struct V_355 V_356 = { } ;
struct V_50 * V_405 = NULL ;
struct V_390 * V_391 = NULL ;
T_14 V_52 ;
T_1 V_392 ;
T_1 * V_406 = NULL ;
V_112 = F_33 ( sizeof( * V_112 ) , V_108 ) ;
if ( ! V_112 )
goto V_107;
V_253 = V_4 -> V_5 -> V_329 ;
V_253 += F_144 () ;
V_388 = F_69 ( V_4 -> V_5 ) ;
if ( V_388 != NULL )
V_253 ++ ;
V_253 ++ ;
V_52 = V_253 > V_407 ? V_407 : V_253 ;
if ( ! F_119 ( V_112 , V_52 , & V_356 , V_248 -> V_318 , V_248 -> V_166 ) )
goto V_408;
V_402 = 1 ;
V_227 = F_75 () ;
F_77 ( V_320 ) ;
V_268 += sizeof( * V_112 ) ;
V_268 += V_253 * sizeof( struct V_50 ) ;
{
T_2 V_243 = F_124 ( & V_356 ) ;
V_243 += F_145 () ;
V_405 = F_33 ( sizeof( * V_405 ) , V_108 ) ;
if ( ! V_405 )
goto V_409;
F_85 ( V_405 , V_243 , V_268 ) ;
V_268 += V_243 ;
}
V_404 = V_268 = F_80 ( V_268 , V_44 ) ;
V_406 = F_146 ( V_253 - 1 , sizeof( * V_406 ) , V_108 ) ;
if ( ! V_406 )
goto V_409;
for ( V_95 = 0 , V_38 = F_140 ( V_4 , V_388 ) ; V_38 != NULL ;
V_38 = F_141 ( V_38 , V_388 ) ) {
unsigned long V_410 ;
V_410 = F_71 ( V_38 , V_248 -> V_203 ) ;
V_406 [ V_95 ++ ] = V_410 ;
V_403 += V_410 ;
}
V_268 += V_403 ;
V_268 += F_147 () ;
V_392 = V_268 ;
if ( V_52 == V_407 ) {
V_391 = F_33 ( sizeof( * V_391 ) , V_108 ) ;
if ( ! V_391 )
goto V_409;
F_142 ( V_112 , V_391 , V_392 , V_253 ) ;
}
V_268 = V_404 ;
if ( ! F_82 ( V_248 , V_112 , sizeof( * V_112 ) ) )
goto V_409;
if ( ! F_82 ( V_248 , V_405 , sizeof( * V_405 ) ) )
goto V_409;
for ( V_95 = 0 , V_38 = F_140 ( V_4 , V_388 ) ; V_38 != NULL ;
V_38 = F_141 ( V_38 , V_388 ) ) {
struct V_50 V_111 ;
V_111 . V_98 = V_99 ;
V_111 . V_92 = V_268 ;
V_111 . V_90 = V_38 -> V_225 ;
V_111 . V_270 = 0 ;
V_111 . V_89 = V_406 [ V_95 ++ ] ;
V_111 . V_100 = V_38 -> V_240 - V_38 -> V_225 ;
V_268 += V_111 . V_89 ;
V_111 . V_135 = V_38 -> V_205 & V_223 ? V_136 : 0 ;
if ( V_38 -> V_205 & V_411 )
V_111 . V_135 |= V_138 ;
if ( V_38 -> V_205 & V_412 )
V_111 . V_135 |= V_140 ;
V_111 . V_271 = V_44 ;
if ( ! F_82 ( V_248 , & V_111 , sizeof( V_111 ) ) )
goto V_409;
}
if ( ! F_148 ( V_248 , V_268 ) )
goto V_409;
if ( ! F_125 ( & V_356 , V_248 ) )
goto V_409;
if ( F_149 ( V_248 ) )
goto V_409;
if ( ! F_150 ( V_248 , V_404 - V_248 -> V_413 ) )
goto V_409;
for ( V_95 = 0 , V_38 = F_140 ( V_4 , V_388 ) ; V_38 != NULL ;
V_38 = F_141 ( V_38 , V_388 ) ) {
unsigned long V_3 ;
unsigned long V_2 ;
V_2 = V_38 -> V_225 + V_406 [ V_95 ++ ] ;
for ( V_3 = V_38 -> V_225 ; V_3 < V_2 ; V_3 += V_197 ) {
struct V_414 * V_414 ;
int V_415 ;
V_414 = F_151 ( V_3 ) ;
if ( V_414 ) {
void * V_416 = F_152 ( V_414 ) ;
V_415 = ! F_82 ( V_248 , V_416 , V_197 ) ;
F_153 ( V_414 ) ;
F_154 ( V_414 ) ;
} else
V_415 = ! F_150 ( V_248 , V_197 ) ;
if ( V_415 )
goto V_409;
}
}
if ( ! F_155 ( V_248 ) )
goto V_409;
if ( V_52 == V_407 ) {
if ( ! F_82 ( V_248 , V_391 , sizeof( * V_391 ) ) )
goto V_409;
}
V_409:
F_77 ( V_227 ) ;
V_408:
F_126 ( & V_356 ) ;
F_35 ( V_391 ) ;
F_35 ( V_406 ) ;
F_35 ( V_405 ) ;
F_35 ( V_112 ) ;
V_107:
return V_402 ;
}
static int T_15 F_156 ( void )
{
F_157 ( & V_194 ) ;
return 0 ;
}
static void T_16 F_158 ( void )
{
F_159 ( & V_194 ) ;
}
