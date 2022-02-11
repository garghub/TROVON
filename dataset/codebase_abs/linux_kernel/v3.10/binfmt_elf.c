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
static unsigned long F_32 ( struct V_15 * V_101 ,
struct V_82 * V_102 , unsigned long * V_103 ,
unsigned long V_104 )
{
struct V_50 * V_105 ;
struct V_50 * V_84 ;
unsigned long V_17 = 0 ;
int V_106 = 0 ;
unsigned long V_107 = 0 , V_8 = 0 ;
unsigned long error = ~ 0UL ;
unsigned long V_86 ;
int V_108 , V_95 , V_88 ;
if ( V_101 -> V_109 != V_110 &&
V_101 -> V_109 != V_111 )
goto V_112;
if ( ! F_33 ( V_101 ) )
goto V_112;
if ( ! V_102 -> V_113 || ! V_102 -> V_113 -> V_114 )
goto V_112;
if ( V_101 -> V_115 != sizeof( struct V_50 ) )
goto V_112;
if ( V_101 -> V_52 < 1 ||
V_101 -> V_52 > 65536U / sizeof( struct V_50 ) )
goto V_112;
V_88 = sizeof( struct V_50 ) * V_101 -> V_52 ;
if ( V_88 > V_10 )
goto V_112;
V_105 = F_34 ( V_88 , V_116 ) ;
if ( ! V_105 )
goto V_112;
V_108 = F_35 ( V_102 , V_101 -> V_48 ,
( char * ) V_105 , V_88 ) ;
error = - V_117 ;
if ( V_108 != V_88 ) {
if ( V_108 < 0 )
error = V_108 ;
goto V_118;
}
V_86 = F_31 ( V_105 , V_101 -> V_52 ) ;
if ( ! V_86 ) {
error = - V_79 ;
goto V_118;
}
V_84 = V_105 ;
for ( V_95 = 0 ; V_95 < V_101 -> V_52 ; V_95 ++ , V_84 ++ ) {
if ( V_84 -> V_98 == V_99 ) {
int V_119 = V_120 | V_121 ;
int V_122 = 0 ;
unsigned long V_123 = 0 ;
unsigned long V_124 , V_87 ;
if ( V_84 -> V_125 & V_126 )
V_122 = V_127 ;
if ( V_84 -> V_125 & V_128 )
V_122 |= V_129 ;
if ( V_84 -> V_125 & V_130 )
V_122 |= V_131 ;
V_123 = V_84 -> V_90 ;
if ( V_101 -> V_109 == V_110 || V_106 )
V_119 |= V_132 ;
else if ( V_104 && V_101 -> V_109 == V_111 )
V_17 = - V_123 ;
V_87 = F_27 ( V_102 , V_17 + V_123 ,
V_84 , V_122 , V_119 , V_86 ) ;
V_86 = 0 ;
if ( ! * V_103 )
* V_103 = V_87 ;
error = V_87 ;
if ( F_4 ( V_87 ) )
goto V_118;
if ( ! V_106 &&
V_101 -> V_109 == V_111 ) {
V_17 = V_87 - F_28 ( V_123 ) ;
V_106 = 1 ;
}
V_124 = V_17 + V_84 -> V_90 ;
if ( F_4 ( V_124 ) ||
V_84 -> V_89 > V_84 -> V_100 ||
V_84 -> V_100 > V_133 ||
V_133 - V_84 -> V_100 < V_124 ) {
error = - V_134 ;
goto V_118;
}
V_124 = V_17 + V_84 -> V_90 + V_84 -> V_89 ;
if ( V_124 > V_8 )
V_8 = V_124 ;
V_124 = V_17 + V_84 -> V_100 + V_84 -> V_90 ;
if ( V_124 > V_107 )
V_107 = V_124 ;
}
}
if ( V_107 > V_8 ) {
if ( F_5 ( V_8 ) ) {
error = - V_12 ;
goto V_118;
}
V_8 = F_28 ( V_8 + V_10 - 1 ) ;
error = F_3 ( V_8 , V_107 - V_8 ) ;
if ( F_4 ( error ) )
goto V_118;
}
error = V_17 ;
V_118:
F_36 ( V_105 ) ;
V_112:
return error ;
}
static unsigned long F_37 ( unsigned long V_135 )
{
unsigned int V_136 = 0 ;
if ( ( V_4 -> V_137 & V_138 ) &&
! ( V_4 -> V_139 & V_140 ) ) {
V_136 = F_38 () & V_141 ;
V_136 <<= V_142 ;
}
#ifdef F_22
return F_39 ( V_135 ) + V_136 ;
#else
return F_39 ( V_135 ) - V_136 ;
#endif
}
static int F_40 ( struct V_13 * V_14 )
{
struct V_82 * V_102 = NULL ;
unsigned long V_17 = 0 , V_143 = 0 ;
int V_106 = 0 ;
char * V_144 = NULL ;
unsigned long error ;
struct V_50 * V_145 , * V_105 ;
unsigned long V_8 , V_146 ;
int V_108 , V_95 ;
unsigned int V_88 ;
unsigned long V_147 ;
unsigned long V_18 = 0 ;
unsigned long V_148 , V_149 , V_150 , V_151 ;
unsigned long T_5 V_152 = 0 ;
int V_153 = V_154 ;
unsigned long V_155 = 0 ;
struct V_156 * V_157 = F_41 () ;
struct {
struct V_15 V_158 ;
struct V_15 V_101 ;
} * V_159 ;
V_159 = F_34 ( sizeof( * V_159 ) , V_116 ) ;
if ( ! V_159 ) {
V_108 = - V_134 ;
goto V_160;
}
V_159 -> V_158 = * ( (struct V_15 * ) V_14 -> V_161 ) ;
V_108 = - V_162 ;
if ( memcmp ( V_159 -> V_158 . V_163 , V_164 , V_165 ) != 0 )
goto V_112;
if ( V_159 -> V_158 . V_109 != V_110 && V_159 -> V_158 . V_109 != V_111 )
goto V_112;
if ( ! F_33 ( & V_159 -> V_158 ) )
goto V_112;
if ( ! V_14 -> V_82 -> V_113 || ! V_14 -> V_82 -> V_113 -> V_114 )
goto V_112;
if ( V_159 -> V_158 . V_115 != sizeof( struct V_50 ) )
goto V_112;
if ( V_159 -> V_158 . V_52 < 1 ||
V_159 -> V_158 . V_52 > 65536U / sizeof( struct V_50 ) )
goto V_112;
V_88 = V_159 -> V_158 . V_52 * sizeof( struct V_50 ) ;
V_108 = - V_134 ;
V_105 = F_34 ( V_88 , V_116 ) ;
if ( ! V_105 )
goto V_112;
V_108 = F_35 ( V_14 -> V_82 , V_159 -> V_158 . V_48 ,
( char * ) V_105 , V_88 ) ;
if ( V_108 != V_88 ) {
if ( V_108 >= 0 )
V_108 = - V_117 ;
goto V_166;
}
V_145 = V_105 ;
V_8 = 0 ;
V_146 = 0 ;
V_148 = ~ 0UL ;
V_149 = 0 ;
V_150 = 0 ;
V_151 = 0 ;
for ( V_95 = 0 ; V_95 < V_159 -> V_158 . V_52 ; V_95 ++ ) {
if ( V_145 -> V_98 == V_167 ) {
V_108 = - V_162 ;
if ( V_145 -> V_89 > V_168 ||
V_145 -> V_89 < 2 )
goto V_166;
V_108 = - V_134 ;
V_144 = F_34 ( V_145 -> V_89 ,
V_116 ) ;
if ( ! V_144 )
goto V_166;
V_108 = F_35 ( V_14 -> V_82 , V_145 -> V_92 ,
V_144 ,
V_145 -> V_89 ) ;
if ( V_108 != V_145 -> V_89 ) {
if ( V_108 >= 0 )
V_108 = - V_117 ;
goto V_169;
}
V_108 = - V_162 ;
if ( V_144 [ V_145 -> V_89 - 1 ] != '\0' )
goto V_169;
V_102 = F_42 ( V_144 ) ;
V_108 = F_43 ( V_102 ) ;
if ( F_44 ( V_102 ) )
goto V_169;
F_45 ( V_14 , V_102 ) ;
V_108 = F_35 ( V_102 , 0 , V_14 -> V_161 ,
V_170 ) ;
if ( V_108 != V_170 ) {
if ( V_108 >= 0 )
V_108 = - V_117 ;
goto V_171;
}
V_159 -> V_101 = * ( (struct V_15 * ) V_14 -> V_161 ) ;
break;
}
V_145 ++ ;
}
V_145 = V_105 ;
for ( V_95 = 0 ; V_95 < V_159 -> V_158 . V_52 ; V_95 ++ , V_145 ++ )
if ( V_145 -> V_98 == V_172 ) {
if ( V_145 -> V_125 & V_130 )
V_153 = V_173 ;
else
V_153 = V_174 ;
break;
}
if ( V_144 ) {
V_108 = - V_175 ;
if ( memcmp ( V_159 -> V_101 . V_163 , V_164 , V_165 ) != 0 )
goto V_171;
if ( ! F_33 ( & V_159 -> V_101 ) )
goto V_171;
}
V_108 = F_46 ( V_14 ) ;
if ( V_108 )
goto V_171;
V_4 -> V_5 -> V_155 = V_155 ;
F_47 ( V_159 -> V_158 ) ;
if ( F_48 ( V_159 -> V_158 , V_153 ) )
V_4 -> V_139 |= V_176 ;
if ( ! ( V_4 -> V_139 & V_140 ) && V_177 )
V_4 -> V_137 |= V_138 ;
F_49 ( V_14 ) ;
V_4 -> V_5 -> V_178 = V_4 -> V_5 -> V_179 ;
V_4 -> V_5 -> V_180 = 0 ;
V_108 = F_50 ( V_14 , F_37 ( V_181 ) ,
V_153 ) ;
if ( V_108 < 0 ) {
F_51 ( V_182 , V_4 , 0 ) ;
goto V_171;
}
V_4 -> V_5 -> V_183 = V_14 -> V_19 ;
for( V_95 = 0 , V_145 = V_105 ;
V_95 < V_159 -> V_158 . V_52 ; V_95 ++ , V_145 ++ ) {
int V_122 = 0 , V_184 ;
unsigned long V_124 , V_123 ;
if ( V_145 -> V_98 != V_99 )
continue;
if ( F_52 ( V_146 > V_8 ) ) {
unsigned long V_9 ;
V_108 = F_1 ( V_8 + V_143 ,
V_146 + V_143 ) ;
if ( V_108 ) {
F_51 ( V_182 , V_4 , 0 ) ;
goto V_171;
}
V_9 = F_6 ( V_8 ) ;
if ( V_9 ) {
V_9 = V_10 - V_9 ;
if ( V_9 > V_146 - V_8 )
V_9 = V_146 - V_8 ;
if ( F_7 ( ( void V_11 * ) V_8 +
V_143 , V_9 ) ) {
}
}
}
if ( V_145 -> V_125 & V_126 )
V_122 |= V_127 ;
if ( V_145 -> V_125 & V_128 )
V_122 |= V_129 ;
if ( V_145 -> V_125 & V_130 )
V_122 |= V_131 ;
V_184 = V_120 | V_121 | V_185 ;
V_123 = V_145 -> V_90 ;
if ( V_159 -> V_158 . V_109 == V_110 || V_106 ) {
V_184 |= V_132 ;
} else if ( V_159 -> V_158 . V_109 == V_111 ) {
#ifdef F_53
if ( V_4 -> V_137 & V_138 )
V_143 = 0 ;
else
V_143 = F_28 ( V_186 - V_123 ) ;
#else
V_143 = F_28 ( V_186 - V_123 ) ;
#endif
}
error = F_27 ( V_14 -> V_82 , V_143 + V_123 , V_145 ,
V_122 , V_184 , 0 ) ;
if ( F_4 ( error ) ) {
F_51 ( V_182 , V_4 , 0 ) ;
V_108 = F_44 ( ( void * ) error ) ?
F_43 ( ( void * ) error ) : - V_79 ;
goto V_171;
}
if ( ! V_106 ) {
V_106 = 1 ;
V_17 = ( V_145 -> V_90 - V_145 -> V_92 ) ;
if ( V_159 -> V_158 . V_109 == V_111 ) {
V_143 += error -
F_28 ( V_143 + V_123 ) ;
V_17 += V_143 ;
T_5 = V_143 ;
}
}
V_124 = V_145 -> V_90 ;
if ( V_124 < V_148 )
V_148 = V_124 ;
if ( V_150 < V_124 )
V_150 = V_124 ;
if ( F_4 ( V_124 ) || V_145 -> V_89 > V_145 -> V_100 ||
V_145 -> V_100 > V_133 ||
V_133 - V_145 -> V_100 < V_124 ) {
F_51 ( V_182 , V_4 , 0 ) ;
V_108 = - V_79 ;
goto V_171;
}
V_124 = V_145 -> V_90 + V_145 -> V_89 ;
if ( V_124 > V_8 )
V_8 = V_124 ;
if ( ( V_145 -> V_125 & V_130 ) && V_149 < V_124 )
V_149 = V_124 ;
if ( V_151 < V_124 )
V_151 = V_124 ;
V_124 = V_145 -> V_90 + V_145 -> V_100 ;
if ( V_124 > V_146 )
V_146 = V_124 ;
}
V_159 -> V_158 . V_56 += V_143 ;
V_8 += V_143 ;
V_146 += V_143 ;
V_148 += V_143 ;
V_149 += V_143 ;
V_150 += V_143 ;
V_151 += V_143 ;
V_108 = F_1 ( V_8 , V_146 ) ;
if ( V_108 ) {
F_51 ( V_182 , V_4 , 0 ) ;
goto V_171;
}
if ( F_54 ( V_8 != V_146 ) && F_52 ( F_5 ( V_8 ) ) ) {
F_51 ( V_187 , V_4 , 0 ) ;
V_108 = - V_12 ;
goto V_171;
}
if ( V_144 ) {
unsigned long V_103 = 0 ;
V_147 = F_32 ( & V_159 -> V_101 ,
V_102 ,
& V_103 ,
V_143 ) ;
if ( ! F_44 ( ( void * ) V_147 ) ) {
V_18 = V_147 ;
V_147 += V_159 -> V_101 . V_56 ;
}
if ( F_4 ( V_147 ) ) {
F_55 ( V_187 , V_4 ) ;
V_108 = F_44 ( ( void * ) V_147 ) ?
( int ) V_147 : - V_79 ;
goto V_171;
}
T_5 = V_18 ;
F_56 ( V_102 ) ;
F_57 ( V_102 ) ;
F_36 ( V_144 ) ;
} else {
V_147 = V_159 -> V_158 . V_56 ;
if ( F_4 ( V_147 ) ) {
F_55 ( V_187 , V_4 ) ;
V_108 = - V_79 ;
goto V_171;
}
}
F_36 ( V_105 ) ;
F_58 ( & V_188 ) ;
#ifdef F_59
V_108 = F_60 ( V_14 , ! ! V_144 ) ;
if ( V_108 < 0 ) {
F_51 ( V_182 , V_4 , 0 ) ;
goto V_112;
}
#endif
F_61 ( V_14 ) ;
V_108 = F_8 ( V_14 , & V_159 -> V_158 ,
V_17 , V_18 ) ;
if ( V_108 < 0 ) {
F_51 ( V_182 , V_4 , 0 ) ;
goto V_112;
}
V_4 -> V_5 -> V_149 = V_149 ;
V_4 -> V_5 -> V_148 = V_148 ;
V_4 -> V_5 -> V_150 = V_150 ;
V_4 -> V_5 -> V_151 = V_151 ;
V_4 -> V_5 -> V_183 = V_14 -> V_19 ;
#ifdef F_62
if ( ( V_4 -> V_137 & V_138 ) && ( V_177 > 1 ) ) {
V_4 -> V_5 -> V_7 = V_4 -> V_5 -> V_6 =
F_62 ( V_4 -> V_5 ) ;
#ifdef F_63
V_4 -> V_189 = 1 ;
#endif
}
#endif
if ( V_4 -> V_139 & V_190 ) {
error = F_29 ( NULL , 0 , V_191 , V_127 | V_131 ,
V_132 | V_120 , 0 ) ;
}
#ifdef F_64
F_64 ( V_157 , T_5 ) ;
#endif
F_65 ( V_157 , V_147 , V_14 -> V_19 ) ;
V_108 = 0 ;
V_112:
F_36 ( V_159 ) ;
V_160:
return V_108 ;
V_171:
F_56 ( V_102 ) ;
if ( V_102 )
F_57 ( V_102 ) ;
V_169:
F_36 ( V_144 ) ;
V_166:
F_36 ( V_105 ) ;
goto V_112;
}
static int F_66 ( struct V_82 * V_82 )
{
struct V_50 * V_105 ;
struct V_50 * V_84 ;
unsigned long V_8 , V_192 , V_39 ;
int V_108 , error , V_95 , V_193 ;
struct V_15 V_158 ;
error = - V_162 ;
V_108 = F_35 ( V_82 , 0 , ( char * ) & V_158 , sizeof( V_158 ) ) ;
if ( V_108 != sizeof( V_158 ) )
goto V_112;
if ( memcmp ( V_158 . V_163 , V_164 , V_165 ) != 0 )
goto V_112;
if ( V_158 . V_109 != V_110 || V_158 . V_52 > 2 ||
! F_33 ( & V_158 ) || ! V_82 -> V_113 || ! V_82 -> V_113 -> V_114 )
goto V_112;
V_193 = sizeof( struct V_50 ) * V_158 . V_52 ;
error = - V_134 ;
V_105 = F_34 ( V_193 , V_116 ) ;
if ( ! V_105 )
goto V_112;
V_84 = V_105 ;
error = - V_162 ;
V_108 = F_35 ( V_82 , V_158 . V_48 , ( char * ) V_84 , V_193 ) ;
if ( V_108 != V_193 )
goto V_166;
for ( V_193 = 0 , V_95 = 0 ; V_95 < V_158 . V_52 ; V_95 ++ )
if ( ( V_84 + V_95 ) -> V_98 == V_99 )
V_193 ++ ;
if ( V_193 != 1 )
goto V_166;
while ( V_84 -> V_98 != V_99 )
V_84 ++ ;
error = F_29 ( V_82 ,
F_28 ( V_84 -> V_90 ) ,
( V_84 -> V_89 +
F_6 ( V_84 -> V_90 ) ) ,
V_127 | V_129 | V_131 ,
V_132 | V_120 | V_121 ,
( V_84 -> V_92 -
F_6 ( V_84 -> V_90 ) ) ) ;
if ( error != F_28 ( V_84 -> V_90 ) )
goto V_166;
V_8 = V_84 -> V_90 + V_84 -> V_89 ;
if ( F_5 ( V_8 ) ) {
error = - V_12 ;
goto V_166;
}
V_39 = F_28 ( V_84 -> V_89 + V_84 -> V_90 +
V_10 - 1 ) ;
V_192 = V_84 -> V_100 + V_84 -> V_90 ;
if ( V_192 > V_39 )
F_3 ( V_39 , V_192 - V_39 ) ;
error = 0 ;
V_166:
F_36 ( V_105 ) ;
V_112:
return error ;
}
static bool F_67 ( struct V_37 * V_38 )
{
if ( V_38 == F_68 ( V_38 -> V_194 ) )
return true ;
if ( F_69 ( V_38 ) )
return true ;
return false ;
}
static unsigned long F_70 ( struct V_37 * V_38 ,
unsigned long V_195 )
{
#define F_71 ( type ) (mm_flags & (1UL << MMF_DUMP_##type))
if ( F_67 ( V_38 ) )
goto V_196;
if ( V_38 -> V_197 & V_198 )
return 0 ;
if ( V_38 -> V_197 & V_199 ) {
if ( ( V_38 -> V_197 & V_200 ) && F_71 ( V_201 ) )
goto V_196;
if ( ! ( V_38 -> V_197 & V_200 ) && F_71 ( V_202 ) )
goto V_196;
return 0 ;
}
if ( V_38 -> V_197 & V_203 )
return 0 ;
if ( V_38 -> V_197 & V_200 ) {
if ( F_72 ( V_38 -> V_204 ) -> V_205 == 0 ?
F_71 ( V_206 ) : F_71 ( V_207 ) )
goto V_196;
return 0 ;
}
if ( V_38 -> V_208 && F_71 ( V_209 ) )
goto V_196;
if ( V_38 -> V_204 == NULL )
return 0 ;
if ( F_71 ( V_210 ) )
goto V_196;
if ( F_71 ( V_211 ) &&
V_38 -> V_212 == 0 && ( V_38 -> V_197 & V_213 ) ) {
T_6 V_11 * V_214 = ( T_6 V_11 * ) V_38 -> V_215 ;
T_6 V_216 ;
T_7 V_217 = F_73 () ;
union {
T_6 V_218 ;
char V_219 [ V_165 ] ;
} V_220 ;
F_74 ( V_165 != sizeof V_216 ) ;
V_220 . V_219 [ V_221 ] = V_222 ;
V_220 . V_219 [ V_223 ] = V_224 ;
V_220 . V_219 [ V_225 ] = V_226 ;
V_220 . V_219 [ V_227 ] = V_228 ;
F_75 ( V_229 ) ;
if ( F_52 ( F_76 ( V_216 , V_214 ) ) )
V_216 = 0 ;
F_75 ( V_217 ) ;
if ( V_216 == V_220 . V_218 )
return V_191 ;
}
#undef F_71
return 0 ;
V_196:
return V_38 -> V_230 - V_38 -> V_215 ;
}
static int F_77 ( struct V_231 * V_232 )
{
int V_233 ;
V_233 = sizeof( struct V_234 ) ;
V_233 += F_78 ( strlen ( V_232 -> V_235 ) + 1 , 4 ) ;
V_233 += F_78 ( V_232 -> V_236 , 4 ) ;
return V_233 ;
}
static int F_79 ( struct V_82 * V_82 , T_8 * V_237 )
{
static const char V_161 [ 4 ] = { 0 , } ;
F_80 ( V_161 , F_78 ( * V_237 , 4 ) - * V_237 , V_237 ) ;
return 1 ;
}
static int F_81 ( struct V_231 * V_238 , struct V_82 * V_82 ,
T_8 * V_237 )
{
struct V_234 V_232 ;
V_232 . V_239 = strlen ( V_238 -> V_235 ) + 1 ;
V_232 . V_240 = V_238 -> V_236 ;
V_232 . V_241 = V_238 -> type ;
F_80 ( & V_232 , sizeof( V_232 ) , V_237 ) ;
F_80 ( V_238 -> V_235 , V_232 . V_239 , V_237 ) ;
if ( ! F_79 ( V_82 , V_237 ) )
return 0 ;
F_80 ( V_238 -> V_242 , V_238 -> V_236 , V_237 ) ;
if ( ! F_79 ( V_82 , V_237 ) )
return 0 ;
return 1 ;
}
static void F_82 ( struct V_15 * V_243 , int V_244 ,
T_9 V_245 , T_6 V_137 )
{
memset ( V_243 , 0 , sizeof( * V_243 ) ) ;
memcpy ( V_243 -> V_163 , V_164 , V_165 ) ;
V_243 -> V_163 [ V_246 ] = V_247 ;
V_243 -> V_163 [ V_248 ] = V_249 ;
V_243 -> V_163 [ V_250 ] = V_251 ;
V_243 -> V_163 [ V_252 ] = V_253 ;
V_243 -> V_109 = V_254 ;
V_243 -> V_255 = V_245 ;
V_243 -> V_256 = V_251 ;
V_243 -> V_48 = sizeof( struct V_15 ) ;
V_243 -> V_257 = V_137 ;
V_243 -> V_258 = sizeof( struct V_15 ) ;
V_243 -> V_115 = sizeof( struct V_50 ) ;
V_243 -> V_52 = V_244 ;
return;
}
static void F_83 ( struct V_50 * V_259 , int V_233 , T_8 V_260 )
{
V_259 -> V_98 = V_261 ;
V_259 -> V_92 = V_260 ;
V_259 -> V_90 = 0 ;
V_259 -> V_262 = 0 ;
V_259 -> V_89 = V_233 ;
V_259 -> V_100 = 0 ;
V_259 -> V_125 = 0 ;
V_259 -> V_263 = 0 ;
return;
}
static void F_84 ( struct V_231 * V_264 , const char * V_235 , int type ,
unsigned int V_233 , void * V_242 )
{
V_264 -> V_235 = V_235 ;
V_264 -> type = type ;
V_264 -> V_236 = V_233 ;
V_264 -> V_242 = V_242 ;
return;
}
static void F_85 ( struct V_265 * V_266 ,
struct V_267 * V_19 , long V_268 )
{
V_266 -> V_269 . V_270 = V_266 -> V_271 = V_268 ;
V_266 -> V_272 = V_19 -> V_273 . signal . V_274 [ 0 ] ;
V_266 -> V_275 = V_19 -> V_276 . V_274 [ 0 ] ;
F_86 () ;
V_266 -> V_277 = F_87 ( F_88 ( V_19 -> V_278 ) ) ;
F_89 () ;
V_266 -> V_279 = F_87 ( V_19 ) ;
V_266 -> V_280 = F_90 ( V_19 ) ;
V_266 -> V_281 = F_91 ( V_19 ) ;
if ( F_92 ( V_19 ) ) {
struct V_282 V_283 ;
F_93 ( V_19 , & V_283 ) ;
F_94 ( V_283 . V_284 , & V_266 -> V_285 ) ;
F_94 ( V_283 . V_286 , & V_266 -> V_287 ) ;
} else {
T_10 V_284 , V_286 ;
V_282 ( V_19 , & V_284 , & V_286 ) ;
F_94 ( V_284 , & V_266 -> V_285 ) ;
F_94 ( V_286 , & V_266 -> V_287 ) ;
}
F_94 ( V_19 -> signal -> V_288 , & V_266 -> V_289 ) ;
F_94 ( V_19 -> signal -> V_290 , & V_266 -> V_291 ) ;
}
static int F_95 ( struct V_292 * V_293 , struct V_267 * V_19 ,
struct V_294 * V_5 )
{
const struct V_36 * V_36 ;
unsigned int V_95 , V_39 ;
memset ( V_293 , 0 , sizeof( struct V_292 ) ) ;
V_39 = V_5 -> V_76 - V_5 -> V_77 ;
if ( V_39 >= V_295 )
V_39 = V_295 - 1 ;
if ( F_96 ( & V_293 -> V_296 ,
( const char V_11 * ) V_5 -> V_77 , V_39 ) )
return - V_12 ;
for( V_95 = 0 ; V_95 < V_39 ; V_95 ++ )
if ( V_293 -> V_296 [ V_95 ] == 0 )
V_293 -> V_296 [ V_95 ] = ' ' ;
V_293 -> V_296 [ V_39 ] = 0 ;
F_86 () ;
V_293 -> V_277 = F_87 ( F_88 ( V_19 -> V_278 ) ) ;
F_89 () ;
V_293 -> V_279 = F_87 ( V_19 ) ;
V_293 -> V_280 = F_90 ( V_19 ) ;
V_293 -> V_281 = F_91 ( V_19 ) ;
V_95 = V_19 -> V_297 ? F_97 ( ~ V_19 -> V_297 ) + 1 : 0 ;
V_293 -> V_298 = V_95 ;
V_293 -> V_299 = ( V_95 > 5 ) ? '.' : L_1 [ V_95 ] ;
V_293 -> V_300 = V_293 -> V_299 == 'Z' ;
V_293 -> V_301 = F_98 ( V_19 ) ;
V_293 -> V_302 = V_19 -> V_137 ;
F_86 () ;
V_36 = F_99 ( V_19 ) ;
F_100 ( V_293 -> V_303 , F_16 ( V_36 -> V_58 , V_36 -> V_59 ) ) ;
F_101 ( V_293 -> V_304 , F_17 ( V_36 -> V_58 , V_36 -> V_63 ) ) ;
F_89 () ;
strncpy ( V_293 -> V_305 , V_19 -> V_306 , sizeof( V_293 -> V_305 ) ) ;
return 0 ;
}
static void F_102 ( struct V_231 * V_264 , struct V_294 * V_5 )
{
T_1 * V_307 = ( T_1 * ) V_5 -> V_40 ;
int V_95 = 0 ;
do
V_95 += 2 ;
while ( V_307 [ V_95 - 2 ] != V_308 );
F_84 ( V_264 , L_2 , V_309 , V_95 * sizeof( T_1 ) , V_307 ) ;
}
static void F_103 ( struct V_231 * V_264 , T_11 * V_310 ,
T_12 * V_311 )
{
T_7 V_312 = F_73 () ;
F_75 ( V_313 ) ;
F_104 ( ( T_11 V_11 * ) V_310 , V_311 ) ;
F_75 ( V_312 ) ;
F_84 ( V_264 , L_2 , V_314 , sizeof( * V_310 ) , V_310 ) ;
}
static void F_105 ( struct V_231 * V_264 )
{
struct V_37 * V_38 ;
unsigned V_315 , V_88 , V_316 , V_317 , V_318 ;
T_13 * V_242 ;
T_13 * V_319 ;
char * V_320 , * V_321 ;
V_315 = V_4 -> V_5 -> V_322 ;
V_88 = V_315 * 64 ;
V_316 = ( 2 + 3 * V_315 ) * sizeof( V_242 [ 0 ] ) ;
V_323:
if ( V_88 >= V_324 )
goto V_325;
V_88 = F_106 ( V_88 , V_191 ) ;
V_242 = F_107 ( V_88 ) ;
if ( ! V_242 )
goto V_325;
V_319 = V_242 + 2 ;
V_320 = V_321 = ( ( char * ) V_242 ) + V_316 ;
V_317 = V_88 - V_316 ;
V_315 = 0 ;
for ( V_38 = V_4 -> V_5 -> V_114 ; V_38 != NULL ; V_38 = V_38 -> V_326 ) {
struct V_82 * V_82 ;
const char * V_327 ;
V_82 = V_38 -> V_204 ;
if ( ! V_82 )
continue;
V_327 = F_108 ( & V_82 -> V_328 , V_321 , V_317 ) ;
if ( F_44 ( V_327 ) ) {
if ( F_43 ( V_327 ) == - V_329 ) {
F_109 ( V_242 ) ;
V_88 = V_88 * 5 / 4 ;
goto V_323;
}
continue;
}
V_318 = ( V_321 + V_317 ) - V_327 ;
V_317 = V_327 - V_321 ;
memmove ( V_321 , V_327 , V_318 ) ;
V_321 += V_318 ;
* V_319 ++ = V_38 -> V_215 ;
* V_319 ++ = V_38 -> V_230 ;
* V_319 ++ = V_38 -> V_212 ;
V_315 ++ ;
}
V_242 [ 0 ] = V_315 ;
V_242 [ 1 ] = V_191 ;
V_318 = V_4 -> V_5 -> V_322 - V_315 ;
if ( V_318 != 0 ) {
unsigned V_330 = V_318 * 3 * sizeof( V_242 [ 0 ] ) ;
memmove ( V_320 - V_330 , V_320 ,
V_321 - V_320 ) ;
V_321 -= V_330 ;
}
V_88 = V_321 - ( char * ) V_242 ;
F_84 ( V_264 , L_2 , V_331 , V_88 , V_242 ) ;
V_325: ;
}
static void F_110 ( struct V_267 * V_332 ,
const struct V_333 * V_334 )
{
if ( V_334 -> V_335 )
V_334 -> V_335 ( V_332 , V_334 , 1 ) ;
}
static int F_111 ( struct V_336 * V_337 ,
const struct V_338 * V_339 ,
long V_268 , T_2 * V_340 )
{
unsigned int V_95 ;
F_85 ( & V_337 -> V_266 , V_337 -> V_332 , V_268 ) ;
( void ) V_339 -> V_341 [ 0 ] . F_112 ( V_337 -> V_332 , & V_339 -> V_341 [ 0 ] ,
0 , F_113 ( V_337 -> V_266 . V_342 ) ,
F_114 ( & V_337 -> V_266 ) , NULL ) ;
F_84 ( & V_337 -> V_343 [ 0 ] , L_2 , V_344 ,
F_115 ( V_337 -> V_266 ) , & V_337 -> V_266 ) ;
* V_340 += F_77 ( & V_337 -> V_343 [ 0 ] ) ;
F_110 ( V_337 -> V_332 , & V_339 -> V_341 [ 0 ] ) ;
for ( V_95 = 1 ; V_95 < V_339 -> V_318 ; ++ V_95 ) {
const struct V_333 * V_334 = & V_339 -> V_341 [ V_95 ] ;
F_110 ( V_337 -> V_332 , V_334 ) ;
if ( V_334 -> V_345 && V_334 -> F_112 &&
( ! V_334 -> V_346 || V_334 -> V_346 ( V_337 -> V_332 , V_334 ) ) ) {
int V_347 ;
T_2 V_88 = V_334 -> V_318 * V_334 -> V_88 ;
void * V_242 = F_34 ( V_88 , V_116 ) ;
if ( F_52 ( ! V_242 ) )
return 0 ;
V_347 = V_334 -> F_112 ( V_337 -> V_332 , V_334 ,
0 , V_88 , V_242 , NULL ) ;
if ( F_52 ( V_347 ) )
F_36 ( V_242 ) ;
else {
if ( V_334 -> V_345 != V_348 )
F_84 ( & V_337 -> V_343 [ V_95 ] , L_3 ,
V_334 -> V_345 ,
V_88 , V_242 ) ;
else {
F_116 ( & V_337 -> V_266 , 1 ) ;
F_84 ( & V_337 -> V_343 [ V_95 ] , L_2 ,
V_348 , V_88 , V_242 ) ;
}
* V_340 += F_77 ( & V_337 -> V_343 [ V_95 ] ) ;
}
}
}
return 1 ;
}
static int F_117 ( struct V_15 * V_243 , int V_349 ,
struct V_350 * V_351 ,
T_12 * V_311 , struct V_156 * V_157 )
{
struct V_267 * V_352 = V_4 ;
const struct V_338 * V_339 = F_118 ( V_352 ) ;
struct V_336 * V_337 ;
struct V_292 * V_293 ;
struct V_353 * V_354 ;
unsigned int V_95 ;
V_351 -> V_88 = 0 ;
V_351 -> V_355 = NULL ;
V_293 = F_34 ( sizeof( * V_293 ) , V_116 ) ;
if ( V_293 == NULL ) {
V_351 -> V_293 . V_242 = NULL ;
return 0 ;
}
F_84 ( & V_351 -> V_293 , L_2 , V_356 , sizeof( * V_293 ) , V_293 ) ;
V_351 -> V_357 = 0 ;
for ( V_95 = 0 ; V_95 < V_339 -> V_318 ; ++ V_95 )
if ( V_339 -> V_341 [ V_95 ] . V_345 != 0 )
++ V_351 -> V_357 ;
if ( F_52 ( V_351 -> V_357 == 0 ) ||
F_52 ( V_339 -> V_341 [ 0 ] . V_345 != V_344 ) ) {
F_119 ( 1 ) ;
return 0 ;
}
F_82 ( V_243 , V_349 ,
V_339 -> V_255 , V_339 -> V_257 ) ;
for ( V_354 = & V_352 -> V_5 -> V_358 -> V_359 ; V_354 ; V_354 = V_354 -> V_360 ) {
V_337 = F_120 ( F_121 ( struct V_336 ,
V_343 [ V_351 -> V_357 ] ) ,
V_116 ) ;
if ( F_52 ( ! V_337 ) )
return 0 ;
V_337 -> V_332 = V_354 -> V_332 ;
if ( V_354 -> V_332 == V_352 || ! V_351 -> V_355 ) {
V_337 -> V_360 = V_351 -> V_355 ;
V_351 -> V_355 = V_337 ;
} else {
V_337 -> V_360 = V_351 -> V_355 -> V_360 ;
V_351 -> V_355 -> V_360 = V_337 ;
}
}
for ( V_337 = V_351 -> V_355 ; V_337 != NULL ; V_337 = V_337 -> V_360 )
if ( ! F_111 ( V_337 , V_339 , V_311 -> V_270 , & V_351 -> V_88 ) )
return 0 ;
F_95 ( V_293 , V_352 -> V_361 , V_352 -> V_5 ) ;
V_351 -> V_88 += F_77 ( & V_351 -> V_293 ) ;
F_103 ( & V_351 -> V_362 , & V_351 -> V_310 , V_311 ) ;
V_351 -> V_88 += F_77 ( & V_351 -> V_362 ) ;
F_102 ( & V_351 -> V_307 , V_4 -> V_5 ) ;
V_351 -> V_88 += F_77 ( & V_351 -> V_307 ) ;
F_105 ( & V_351 -> V_363 ) ;
V_351 -> V_88 += F_77 ( & V_351 -> V_363 ) ;
return 1 ;
}
static T_2 F_122 ( struct V_350 * V_351 )
{
return V_351 -> V_88 ;
}
static int F_123 ( struct V_350 * V_351 ,
struct V_82 * V_82 , T_8 * V_237 )
{
bool V_364 = 1 ;
struct V_336 * V_337 = V_351 -> V_355 ;
do {
int V_95 ;
if ( ! F_81 ( & V_337 -> V_343 [ 0 ] , V_82 , V_237 ) )
return 0 ;
if ( V_364 && ! F_81 ( & V_351 -> V_293 , V_82 , V_237 ) )
return 0 ;
if ( V_364 && ! F_81 ( & V_351 -> V_362 , V_82 , V_237 ) )
return 0 ;
if ( V_364 && ! F_81 ( & V_351 -> V_307 , V_82 , V_237 ) )
return 0 ;
if ( V_364 && ! F_81 ( & V_351 -> V_363 , V_82 , V_237 ) )
return 0 ;
for ( V_95 = 1 ; V_95 < V_351 -> V_357 ; ++ V_95 )
if ( V_337 -> V_343 [ V_95 ] . V_242 &&
! F_81 ( & V_337 -> V_343 [ V_95 ] , V_82 , V_237 ) )
return 0 ;
V_364 = 0 ;
V_337 = V_337 -> V_360 ;
} while ( V_337 );
return 1 ;
}
static void F_124 ( struct V_350 * V_351 )
{
struct V_336 * V_365 = V_351 -> V_355 ;
while ( V_365 ) {
unsigned int V_95 ;
struct V_336 * V_337 = V_365 ;
V_365 = V_337 -> V_360 ;
F_119 ( V_337 -> V_343 [ 0 ] . V_242 && V_337 -> V_343 [ 0 ] . V_242 != & V_337 -> V_266 ) ;
for ( V_95 = 1 ; V_95 < V_351 -> V_357 ; ++ V_95 )
F_36 ( V_337 -> V_343 [ V_95 ] . V_242 ) ;
F_36 ( V_337 ) ;
}
F_36 ( V_351 -> V_293 . V_242 ) ;
F_109 ( V_351 -> V_363 . V_242 ) ;
}
static int F_125 ( long V_268 , struct V_366 * V_337 )
{
int V_233 = 0 ;
struct V_267 * V_19 = V_337 -> V_355 ;
V_337 -> V_367 = 0 ;
F_85 ( & V_337 -> V_266 , V_19 , V_268 ) ;
F_126 ( V_19 , & V_337 -> V_266 . V_342 ) ;
F_84 ( & V_337 -> V_343 [ 0 ] , L_2 , V_344 , sizeof( V_337 -> V_266 ) ,
& ( V_337 -> V_266 ) ) ;
V_337 -> V_367 ++ ;
V_233 += F_77 ( & V_337 -> V_343 [ 0 ] ) ;
if ( ( V_337 -> V_266 . V_368 = F_127 ( V_19 , NULL ,
& V_337 -> V_369 ) ) ) {
F_84 ( & V_337 -> V_343 [ 1 ] , L_2 , V_348 , sizeof( V_337 -> V_369 ) ,
& ( V_337 -> V_369 ) ) ;
V_337 -> V_367 ++ ;
V_233 += F_77 ( & V_337 -> V_343 [ 1 ] ) ;
}
#ifdef F_128
if ( F_129 ( V_19 , & V_337 -> V_370 ) ) {
F_84 ( & V_337 -> V_343 [ 2 ] , L_3 , V_371 ,
sizeof( V_337 -> V_370 ) , & V_337 -> V_370 ) ;
V_337 -> V_367 ++ ;
V_233 += F_77 ( & V_337 -> V_343 [ 2 ] ) ;
}
#endif
return V_233 ;
}
static int F_130 ( struct V_350 * V_351 )
{
memset ( V_351 , 0 , sizeof( * V_351 ) ) ;
F_131 ( & V_351 -> V_372 ) ;
V_351 -> V_343 = F_34 ( 8 * sizeof( struct V_231 ) , V_116 ) ;
if ( ! V_351 -> V_343 )
return 0 ;
V_351 -> V_293 = F_34 ( sizeof( * V_351 -> V_293 ) , V_116 ) ;
if ( ! V_351 -> V_293 )
return 0 ;
V_351 -> V_266 = F_34 ( sizeof( * V_351 -> V_266 ) , V_116 ) ;
if ( ! V_351 -> V_266 )
return 0 ;
V_351 -> V_369 = F_34 ( sizeof( * V_351 -> V_369 ) , V_116 ) ;
if ( ! V_351 -> V_369 )
return 0 ;
#ifdef F_128
V_351 -> V_370 = F_34 ( sizeof( * V_351 -> V_370 ) , V_116 ) ;
if ( ! V_351 -> V_370 )
return 0 ;
#endif
return 1 ;
}
static int F_117 ( struct V_15 * V_243 , int V_349 ,
struct V_350 * V_351 ,
T_12 * V_311 , struct V_156 * V_157 )
{
struct V_373 * V_337 ;
if ( ! F_130 ( V_351 ) )
return 0 ;
if ( V_311 -> V_270 ) {
struct V_353 * V_354 ;
struct V_366 * V_374 ;
for ( V_354 = V_4 -> V_5 -> V_358 -> V_359 . V_360 ;
V_354 ; V_354 = V_354 -> V_360 ) {
V_374 = F_120 ( sizeof( * V_374 ) , V_116 ) ;
if ( ! V_374 )
return 0 ;
V_374 -> V_355 = V_354 -> V_332 ;
F_132 ( & V_374 -> V_375 , & V_351 -> V_372 ) ;
}
F_133 (t, &info->thread_list) {
int V_233 ;
V_374 = F_134 ( V_337 , struct V_366 , V_375 ) ;
V_233 = F_125 ( V_311 -> V_270 , V_374 ) ;
V_351 -> V_376 += V_233 ;
}
}
memset ( V_351 -> V_266 , 0 , sizeof( * V_351 -> V_266 ) ) ;
F_85 ( V_351 -> V_266 , V_4 , V_311 -> V_270 ) ;
F_135 ( & V_351 -> V_266 -> V_342 , V_157 ) ;
F_82 ( V_243 , V_349 , V_377 , V_378 ) ;
F_84 ( V_351 -> V_343 + 0 , L_2 , V_344 ,
sizeof( * V_351 -> V_266 ) , V_351 -> V_266 ) ;
F_95 ( V_351 -> V_293 , V_4 -> V_361 , V_4 -> V_5 ) ;
F_84 ( V_351 -> V_343 + 1 , L_2 , V_356 ,
sizeof( * V_351 -> V_293 ) , V_351 -> V_293 ) ;
F_103 ( V_351 -> V_343 + 2 , & V_351 -> V_310 , V_311 ) ;
F_102 ( V_351 -> V_343 + 3 , V_4 -> V_5 ) ;
F_105 ( V_351 -> V_343 + 4 ) ;
V_351 -> V_379 = 5 ;
V_351 -> V_266 -> V_368 = F_127 ( V_4 , V_157 ,
V_351 -> V_369 ) ;
if ( V_351 -> V_266 -> V_368 )
F_84 ( V_351 -> V_343 + V_351 -> V_379 ++ ,
L_2 , V_348 , sizeof( * V_351 -> V_369 ) , V_351 -> V_369 ) ;
#ifdef F_128
if ( F_129 ( V_4 , V_351 -> V_370 ) )
F_84 ( V_351 -> V_343 + V_351 -> V_379 ++ ,
L_3 , V_371 ,
sizeof( * V_351 -> V_370 ) , V_351 -> V_370 ) ;
#endif
return 1 ;
}
static T_2 F_122 ( struct V_350 * V_351 )
{
int V_233 = 0 ;
int V_95 ;
for ( V_95 = 0 ; V_95 < V_351 -> V_379 ; V_95 ++ )
V_233 += F_77 ( V_351 -> V_343 + V_95 ) ;
V_233 += V_351 -> V_376 ;
return V_233 ;
}
static int F_123 ( struct V_350 * V_351 ,
struct V_82 * V_82 , T_8 * V_237 )
{
int V_95 ;
struct V_373 * V_337 ;
for ( V_95 = 0 ; V_95 < V_351 -> V_379 ; V_95 ++ )
if ( ! F_81 ( V_351 -> V_343 + V_95 , V_82 , V_237 ) )
return 0 ;
F_133 (t, &info->thread_list) {
struct V_366 * V_380 =
F_134 ( V_337 , struct V_366 , V_375 ) ;
for ( V_95 = 0 ; V_95 < V_380 -> V_367 ; V_95 ++ )
if ( ! F_81 ( & V_380 -> V_343 [ V_95 ] , V_82 , V_237 ) )
return 0 ;
}
return 1 ;
}
static void F_124 ( struct V_350 * V_351 )
{
while ( ! F_136 ( & V_351 -> V_372 ) ) {
struct V_373 * V_380 = V_351 -> V_372 . V_360 ;
F_137 ( V_380 ) ;
F_36 ( F_134 ( V_380 , struct V_366 , V_375 ) ) ;
}
F_109 ( V_351 -> V_343 [ 4 ] . V_242 ) ;
F_36 ( V_351 -> V_266 ) ;
F_36 ( V_351 -> V_293 ) ;
F_36 ( V_351 -> V_343 ) ;
F_36 ( V_351 -> V_369 ) ;
#ifdef F_128
F_36 ( V_351 -> V_370 ) ;
#endif
}
static struct V_37 * F_138 ( struct V_267 * V_381 ,
struct V_37 * V_382 )
{
struct V_37 * V_347 = V_381 -> V_5 -> V_114 ;
if ( V_347 )
return V_347 ;
return V_382 ;
}
static struct V_37 * F_139 ( struct V_37 * V_383 ,
struct V_37 * V_382 )
{
struct V_37 * V_347 ;
V_347 = V_383 -> V_326 ;
if ( V_347 )
return V_347 ;
if ( V_383 == V_382 )
return NULL ;
return V_382 ;
}
static void F_140 ( struct V_15 * V_243 , struct V_384 * V_385 ,
T_1 V_386 , int V_244 )
{
V_243 -> V_386 = V_386 ;
V_243 -> V_387 = sizeof( * V_385 ) ;
V_243 -> V_388 = 1 ;
V_243 -> V_389 = V_390 ;
memset ( V_385 , 0 , sizeof( * V_385 ) ) ;
V_385 -> V_391 = V_392 ;
V_385 -> V_393 = V_243 -> V_388 ;
V_385 -> V_394 = V_243 -> V_389 ;
V_385 -> V_395 = V_244 ;
}
static T_2 F_141 ( struct V_37 * V_382 ,
unsigned long V_195 )
{
struct V_37 * V_38 ;
T_2 V_88 = 0 ;
for ( V_38 = F_138 ( V_4 , V_382 ) ; V_38 != NULL ;
V_38 = F_139 ( V_38 , V_382 ) )
V_88 += F_70 ( V_38 , V_195 ) ;
return V_88 ;
}
static int F_142 ( struct V_396 * V_397 )
{
int V_398 = 0 ;
T_7 V_217 ;
int V_244 ;
T_2 V_88 = 0 ;
struct V_37 * V_38 , * V_382 ;
struct V_15 * V_243 = NULL ;
T_8 V_260 = 0 , V_399 , V_237 ;
struct V_350 V_351 ;
struct V_50 * V_400 = NULL ;
struct V_384 * V_385 = NULL ;
T_14 V_52 ;
T_1 V_386 ;
V_243 = F_34 ( sizeof( * V_243 ) , V_116 ) ;
if ( ! V_243 )
goto V_112;
V_244 = V_4 -> V_5 -> V_322 ;
V_244 += F_143 () ;
V_382 = F_68 ( V_4 -> V_5 ) ;
if ( V_382 != NULL )
V_244 ++ ;
V_244 ++ ;
V_52 = V_244 > V_401 ? V_401 : V_244 ;
if ( ! F_117 ( V_243 , V_52 , & V_351 , V_397 -> V_311 , V_397 -> V_157 ) )
goto V_402;
V_398 = 1 ;
V_217 = F_73 () ;
F_75 ( V_313 ) ;
V_260 += sizeof( * V_243 ) ;
V_260 += V_244 * sizeof( struct V_50 ) ;
V_237 = V_260 ;
{
T_2 V_233 = F_122 ( & V_351 ) ;
V_233 += F_144 () ;
V_400 = F_34 ( sizeof( * V_400 ) , V_116 ) ;
if ( ! V_400 )
goto V_403;
F_83 ( V_400 , V_233 , V_260 ) ;
V_260 += V_233 ;
}
V_399 = V_260 = F_78 ( V_260 , V_44 ) ;
V_260 += F_141 ( V_382 , V_397 -> V_195 ) ;
V_260 += F_145 () ;
V_386 = V_260 ;
if ( V_52 == V_401 ) {
V_385 = F_34 ( sizeof( * V_385 ) , V_116 ) ;
if ( ! V_385 )
goto V_403;
F_140 ( V_243 , V_385 , V_386 , V_244 ) ;
}
V_260 = V_399 ;
V_88 += sizeof( * V_243 ) ;
if ( V_88 > V_397 -> V_404 || ! F_146 ( V_397 -> V_82 , V_243 , sizeof( * V_243 ) ) )
goto V_403;
V_88 += sizeof( * V_400 ) ;
if ( V_88 > V_397 -> V_404
|| ! F_146 ( V_397 -> V_82 , V_400 , sizeof( * V_400 ) ) )
goto V_403;
for ( V_38 = F_138 ( V_4 , V_382 ) ; V_38 != NULL ;
V_38 = F_139 ( V_38 , V_382 ) ) {
struct V_50 V_259 ;
V_259 . V_98 = V_99 ;
V_259 . V_92 = V_260 ;
V_259 . V_90 = V_38 -> V_215 ;
V_259 . V_262 = 0 ;
V_259 . V_89 = F_70 ( V_38 , V_397 -> V_195 ) ;
V_259 . V_100 = V_38 -> V_230 - V_38 -> V_215 ;
V_260 += V_259 . V_89 ;
V_259 . V_125 = V_38 -> V_197 & V_213 ? V_126 : 0 ;
if ( V_38 -> V_197 & V_405 )
V_259 . V_125 |= V_128 ;
if ( V_38 -> V_197 & V_406 )
V_259 . V_125 |= V_130 ;
V_259 . V_263 = V_44 ;
V_88 += sizeof( V_259 ) ;
if ( V_88 > V_397 -> V_404
|| ! F_146 ( V_397 -> V_82 , & V_259 , sizeof( V_259 ) ) )
goto V_403;
}
if ( ! F_147 ( V_397 -> V_82 , V_260 , & V_88 , V_397 -> V_404 ) )
goto V_403;
if ( ! F_123 ( & V_351 , V_397 -> V_82 , & V_237 ) )
goto V_403;
if ( F_148 ( V_397 -> V_82 , & V_237 ) )
goto V_403;
if ( ! F_149 ( V_397 -> V_82 , V_399 - V_237 ) )
goto V_403;
for ( V_38 = F_138 ( V_4 , V_382 ) ; V_38 != NULL ;
V_38 = F_139 ( V_38 , V_382 ) ) {
unsigned long V_3 ;
unsigned long V_2 ;
V_2 = V_38 -> V_215 + F_70 ( V_38 , V_397 -> V_195 ) ;
for ( V_3 = V_38 -> V_215 ; V_3 < V_2 ; V_3 += V_191 ) {
struct V_407 * V_407 ;
int V_408 ;
V_407 = F_150 ( V_3 ) ;
if ( V_407 ) {
void * V_409 = F_151 ( V_407 ) ;
V_408 = ( ( V_88 += V_191 ) > V_397 -> V_404 ) ||
! F_146 ( V_397 -> V_82 , V_409 ,
V_191 ) ;
F_152 ( V_407 ) ;
F_153 ( V_407 ) ;
} else
V_408 = ! F_149 ( V_397 -> V_82 , V_191 ) ;
if ( V_408 )
goto V_403;
}
}
if ( ! F_154 ( V_397 -> V_82 , & V_88 , V_397 -> V_404 ) )
goto V_403;
if ( V_52 == V_401 ) {
V_88 += sizeof( * V_385 ) ;
if ( V_88 > V_397 -> V_404
|| ! F_146 ( V_397 -> V_82 , V_385 ,
sizeof( * V_385 ) ) )
goto V_403;
}
V_403:
F_75 ( V_217 ) ;
V_402:
F_124 ( & V_351 ) ;
F_36 ( V_385 ) ;
F_36 ( V_400 ) ;
F_36 ( V_243 ) ;
V_112:
return V_398 ;
}
static int T_15 F_155 ( void )
{
F_156 ( & V_188 ) ;
return 0 ;
}
static void T_16 F_157 ( void )
{
F_158 ( & V_188 ) ;
}
