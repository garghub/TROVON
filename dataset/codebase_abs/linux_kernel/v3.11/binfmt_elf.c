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
V_108 = F_50 ( V_14 , F_37 ( V_178 ) ,
V_153 ) ;
if ( V_108 < 0 ) {
F_51 ( V_179 , V_4 , 0 ) ;
goto V_171;
}
V_4 -> V_5 -> V_180 = V_14 -> V_19 ;
for( V_95 = 0 , V_145 = V_105 ;
V_95 < V_159 -> V_158 . V_52 ; V_95 ++ , V_145 ++ ) {
int V_122 = 0 , V_181 ;
unsigned long V_124 , V_123 ;
if ( V_145 -> V_98 != V_99 )
continue;
if ( F_52 ( V_146 > V_8 ) ) {
unsigned long V_9 ;
V_108 = F_1 ( V_8 + V_143 ,
V_146 + V_143 ) ;
if ( V_108 ) {
F_51 ( V_179 , V_4 , 0 ) ;
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
V_181 = V_120 | V_121 | V_182 ;
V_123 = V_145 -> V_90 ;
if ( V_159 -> V_158 . V_109 == V_110 || V_106 ) {
V_181 |= V_132 ;
} else if ( V_159 -> V_158 . V_109 == V_111 ) {
#ifdef F_53
if ( V_4 -> V_137 & V_138 )
V_143 = 0 ;
else
V_143 = F_28 ( V_183 - V_123 ) ;
#else
V_143 = F_28 ( V_183 - V_123 ) ;
#endif
}
error = F_27 ( V_14 -> V_82 , V_143 + V_123 , V_145 ,
V_122 , V_181 , 0 ) ;
if ( F_4 ( error ) ) {
F_51 ( V_179 , V_4 , 0 ) ;
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
F_51 ( V_179 , V_4 , 0 ) ;
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
F_51 ( V_179 , V_4 , 0 ) ;
goto V_171;
}
if ( F_54 ( V_8 != V_146 ) && F_52 ( F_5 ( V_8 ) ) ) {
F_51 ( V_184 , V_4 , 0 ) ;
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
F_55 ( V_184 , V_4 ) ;
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
F_55 ( V_184 , V_4 ) ;
V_108 = - V_79 ;
goto V_171;
}
}
F_36 ( V_105 ) ;
F_58 ( & V_185 ) ;
#ifdef F_59
V_108 = F_60 ( V_14 , ! ! V_144 ) ;
if ( V_108 < 0 ) {
F_51 ( V_179 , V_4 , 0 ) ;
goto V_112;
}
#endif
F_61 ( V_14 ) ;
V_108 = F_8 ( V_14 , & V_159 -> V_158 ,
V_17 , V_18 ) ;
if ( V_108 < 0 ) {
F_51 ( V_179 , V_4 , 0 ) ;
goto V_112;
}
V_4 -> V_5 -> V_149 = V_149 ;
V_4 -> V_5 -> V_148 = V_148 ;
V_4 -> V_5 -> V_150 = V_150 ;
V_4 -> V_5 -> V_151 = V_151 ;
V_4 -> V_5 -> V_180 = V_14 -> V_19 ;
#ifdef F_62
if ( ( V_4 -> V_137 & V_138 ) && ( V_177 > 1 ) ) {
V_4 -> V_5 -> V_7 = V_4 -> V_5 -> V_6 =
F_62 ( V_4 -> V_5 ) ;
#ifdef F_63
V_4 -> V_186 = 1 ;
#endif
}
#endif
if ( V_4 -> V_139 & V_187 ) {
error = F_29 ( NULL , 0 , V_188 , V_127 | V_131 ,
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
unsigned long V_8 , V_189 , V_39 ;
int V_108 , error , V_95 , V_190 ;
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
V_190 = sizeof( struct V_50 ) * V_158 . V_52 ;
error = - V_134 ;
V_105 = F_34 ( V_190 , V_116 ) ;
if ( ! V_105 )
goto V_112;
V_84 = V_105 ;
error = - V_162 ;
V_108 = F_35 ( V_82 , V_158 . V_48 , ( char * ) V_84 , V_190 ) ;
if ( V_108 != V_190 )
goto V_166;
for ( V_190 = 0 , V_95 = 0 ; V_95 < V_158 . V_52 ; V_95 ++ )
if ( ( V_84 + V_95 ) -> V_98 == V_99 )
V_190 ++ ;
if ( V_190 != 1 )
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
V_189 = V_84 -> V_100 + V_84 -> V_90 ;
if ( V_189 > V_39 )
F_3 ( V_39 , V_189 - V_39 ) ;
error = 0 ;
V_166:
F_36 ( V_105 ) ;
V_112:
return error ;
}
static bool F_67 ( struct V_37 * V_38 )
{
if ( V_38 == F_68 ( V_38 -> V_191 ) )
return true ;
if ( F_69 ( V_38 ) )
return true ;
return false ;
}
static unsigned long F_70 ( struct V_37 * V_38 ,
unsigned long V_192 )
{
#define F_71 ( type ) (mm_flags & (1UL << MMF_DUMP_##type))
if ( F_67 ( V_38 ) )
goto V_193;
if ( V_38 -> V_194 & V_195 )
return 0 ;
if ( V_38 -> V_194 & V_196 ) {
if ( ( V_38 -> V_194 & V_197 ) && F_71 ( V_198 ) )
goto V_193;
if ( ! ( V_38 -> V_194 & V_197 ) && F_71 ( V_199 ) )
goto V_193;
return 0 ;
}
if ( V_38 -> V_194 & V_200 )
return 0 ;
if ( V_38 -> V_194 & V_197 ) {
if ( F_72 ( V_38 -> V_201 ) -> V_202 == 0 ?
F_71 ( V_203 ) : F_71 ( V_204 ) )
goto V_193;
return 0 ;
}
if ( V_38 -> V_205 && F_71 ( V_206 ) )
goto V_193;
if ( V_38 -> V_201 == NULL )
return 0 ;
if ( F_71 ( V_207 ) )
goto V_193;
if ( F_71 ( V_208 ) &&
V_38 -> V_209 == 0 && ( V_38 -> V_194 & V_210 ) ) {
T_6 V_11 * V_211 = ( T_6 V_11 * ) V_38 -> V_212 ;
T_6 V_213 ;
T_7 V_214 = F_73 () ;
union {
T_6 V_215 ;
char V_216 [ V_165 ] ;
} V_217 ;
F_74 ( V_165 != sizeof V_213 ) ;
V_217 . V_216 [ V_218 ] = V_219 ;
V_217 . V_216 [ V_220 ] = V_221 ;
V_217 . V_216 [ V_222 ] = V_223 ;
V_217 . V_216 [ V_224 ] = V_225 ;
F_75 ( V_226 ) ;
if ( F_52 ( F_76 ( V_213 , V_211 ) ) )
V_213 = 0 ;
F_75 ( V_214 ) ;
if ( V_213 == V_217 . V_215 )
return V_188 ;
}
#undef F_71
return 0 ;
V_193:
return V_38 -> V_227 - V_38 -> V_212 ;
}
static int F_77 ( struct V_228 * V_229 )
{
int V_230 ;
V_230 = sizeof( struct V_231 ) ;
V_230 += F_78 ( strlen ( V_229 -> V_232 ) + 1 , 4 ) ;
V_230 += F_78 ( V_229 -> V_233 , 4 ) ;
return V_230 ;
}
static int F_79 ( struct V_82 * V_82 , T_8 * V_234 )
{
static const char V_161 [ 4 ] = { 0 , } ;
F_80 ( V_161 , F_78 ( * V_234 , 4 ) - * V_234 , V_234 ) ;
return 1 ;
}
static int F_81 ( struct V_228 * V_235 , struct V_82 * V_82 ,
T_8 * V_234 )
{
struct V_231 V_229 ;
V_229 . V_236 = strlen ( V_235 -> V_232 ) + 1 ;
V_229 . V_237 = V_235 -> V_233 ;
V_229 . V_238 = V_235 -> type ;
F_80 ( & V_229 , sizeof( V_229 ) , V_234 ) ;
F_80 ( V_235 -> V_232 , V_229 . V_236 , V_234 ) ;
if ( ! F_79 ( V_82 , V_234 ) )
return 0 ;
F_80 ( V_235 -> V_239 , V_235 -> V_233 , V_234 ) ;
if ( ! F_79 ( V_82 , V_234 ) )
return 0 ;
return 1 ;
}
static void F_82 ( struct V_15 * V_240 , int V_241 ,
T_9 V_242 , T_6 V_137 )
{
memset ( V_240 , 0 , sizeof( * V_240 ) ) ;
memcpy ( V_240 -> V_163 , V_164 , V_165 ) ;
V_240 -> V_163 [ V_243 ] = V_244 ;
V_240 -> V_163 [ V_245 ] = V_246 ;
V_240 -> V_163 [ V_247 ] = V_248 ;
V_240 -> V_163 [ V_249 ] = V_250 ;
V_240 -> V_109 = V_251 ;
V_240 -> V_252 = V_242 ;
V_240 -> V_253 = V_248 ;
V_240 -> V_48 = sizeof( struct V_15 ) ;
V_240 -> V_254 = V_137 ;
V_240 -> V_255 = sizeof( struct V_15 ) ;
V_240 -> V_115 = sizeof( struct V_50 ) ;
V_240 -> V_52 = V_241 ;
return;
}
static void F_83 ( struct V_50 * V_256 , int V_230 , T_8 V_257 )
{
V_256 -> V_98 = V_258 ;
V_256 -> V_92 = V_257 ;
V_256 -> V_90 = 0 ;
V_256 -> V_259 = 0 ;
V_256 -> V_89 = V_230 ;
V_256 -> V_100 = 0 ;
V_256 -> V_125 = 0 ;
V_256 -> V_260 = 0 ;
return;
}
static void F_84 ( struct V_228 * V_261 , const char * V_232 , int type ,
unsigned int V_230 , void * V_239 )
{
V_261 -> V_232 = V_232 ;
V_261 -> type = type ;
V_261 -> V_233 = V_230 ;
V_261 -> V_239 = V_239 ;
return;
}
static void F_85 ( struct V_262 * V_263 ,
struct V_264 * V_19 , long V_265 )
{
V_263 -> V_266 . V_267 = V_263 -> V_268 = V_265 ;
V_263 -> V_269 = V_19 -> V_270 . signal . V_271 [ 0 ] ;
V_263 -> V_272 = V_19 -> V_273 . V_271 [ 0 ] ;
F_86 () ;
V_263 -> V_274 = F_87 ( F_88 ( V_19 -> V_275 ) ) ;
F_89 () ;
V_263 -> V_276 = F_87 ( V_19 ) ;
V_263 -> V_277 = F_90 ( V_19 ) ;
V_263 -> V_278 = F_91 ( V_19 ) ;
if ( F_92 ( V_19 ) ) {
struct V_279 V_280 ;
F_93 ( V_19 , & V_280 ) ;
F_94 ( V_280 . V_281 , & V_263 -> V_282 ) ;
F_94 ( V_280 . V_283 , & V_263 -> V_284 ) ;
} else {
T_10 V_281 , V_283 ;
V_279 ( V_19 , & V_281 , & V_283 ) ;
F_94 ( V_281 , & V_263 -> V_282 ) ;
F_94 ( V_283 , & V_263 -> V_284 ) ;
}
F_94 ( V_19 -> signal -> V_285 , & V_263 -> V_286 ) ;
F_94 ( V_19 -> signal -> V_287 , & V_263 -> V_288 ) ;
}
static int F_95 ( struct V_289 * V_290 , struct V_264 * V_19 ,
struct V_291 * V_5 )
{
const struct V_36 * V_36 ;
unsigned int V_95 , V_39 ;
memset ( V_290 , 0 , sizeof( struct V_289 ) ) ;
V_39 = V_5 -> V_76 - V_5 -> V_77 ;
if ( V_39 >= V_292 )
V_39 = V_292 - 1 ;
if ( F_96 ( & V_290 -> V_293 ,
( const char V_11 * ) V_5 -> V_77 , V_39 ) )
return - V_12 ;
for( V_95 = 0 ; V_95 < V_39 ; V_95 ++ )
if ( V_290 -> V_293 [ V_95 ] == 0 )
V_290 -> V_293 [ V_95 ] = ' ' ;
V_290 -> V_293 [ V_39 ] = 0 ;
F_86 () ;
V_290 -> V_274 = F_87 ( F_88 ( V_19 -> V_275 ) ) ;
F_89 () ;
V_290 -> V_276 = F_87 ( V_19 ) ;
V_290 -> V_277 = F_90 ( V_19 ) ;
V_290 -> V_278 = F_91 ( V_19 ) ;
V_95 = V_19 -> V_294 ? F_97 ( ~ V_19 -> V_294 ) + 1 : 0 ;
V_290 -> V_295 = V_95 ;
V_290 -> V_296 = ( V_95 > 5 ) ? '.' : L_1 [ V_95 ] ;
V_290 -> V_297 = V_290 -> V_296 == 'Z' ;
V_290 -> V_298 = F_98 ( V_19 ) ;
V_290 -> V_299 = V_19 -> V_137 ;
F_86 () ;
V_36 = F_99 ( V_19 ) ;
F_100 ( V_290 -> V_300 , F_16 ( V_36 -> V_58 , V_36 -> V_59 ) ) ;
F_101 ( V_290 -> V_301 , F_17 ( V_36 -> V_58 , V_36 -> V_63 ) ) ;
F_89 () ;
strncpy ( V_290 -> V_302 , V_19 -> V_303 , sizeof( V_290 -> V_302 ) ) ;
return 0 ;
}
static void F_102 ( struct V_228 * V_261 , struct V_291 * V_5 )
{
T_1 * V_304 = ( T_1 * ) V_5 -> V_40 ;
int V_95 = 0 ;
do
V_95 += 2 ;
while ( V_304 [ V_95 - 2 ] != V_305 );
F_84 ( V_261 , L_2 , V_306 , V_95 * sizeof( T_1 ) , V_304 ) ;
}
static void F_103 ( struct V_228 * V_261 , T_11 * V_307 ,
T_12 * V_308 )
{
T_7 V_309 = F_73 () ;
F_75 ( V_310 ) ;
F_104 ( ( T_11 V_11 * ) V_307 , V_308 ) ;
F_75 ( V_309 ) ;
F_84 ( V_261 , L_2 , V_311 , sizeof( * V_307 ) , V_307 ) ;
}
static void F_105 ( struct V_228 * V_261 )
{
struct V_37 * V_38 ;
unsigned V_312 , V_88 , V_313 , V_314 , V_315 ;
T_13 * V_239 ;
T_13 * V_316 ;
char * V_317 , * V_318 ;
V_312 = V_4 -> V_5 -> V_319 ;
V_88 = V_312 * 64 ;
V_313 = ( 2 + 3 * V_312 ) * sizeof( V_239 [ 0 ] ) ;
V_320:
if ( V_88 >= V_321 )
goto V_322;
V_88 = F_106 ( V_88 , V_188 ) ;
V_239 = F_107 ( V_88 ) ;
if ( ! V_239 )
goto V_322;
V_316 = V_239 + 2 ;
V_317 = V_318 = ( ( char * ) V_239 ) + V_313 ;
V_314 = V_88 - V_313 ;
V_312 = 0 ;
for ( V_38 = V_4 -> V_5 -> V_114 ; V_38 != NULL ; V_38 = V_38 -> V_323 ) {
struct V_82 * V_82 ;
const char * V_324 ;
V_82 = V_38 -> V_201 ;
if ( ! V_82 )
continue;
V_324 = F_108 ( & V_82 -> V_325 , V_318 , V_314 ) ;
if ( F_44 ( V_324 ) ) {
if ( F_43 ( V_324 ) == - V_326 ) {
F_109 ( V_239 ) ;
V_88 = V_88 * 5 / 4 ;
goto V_320;
}
continue;
}
V_315 = ( V_318 + V_314 ) - V_324 ;
V_314 = V_324 - V_318 ;
memmove ( V_318 , V_324 , V_315 ) ;
V_318 += V_315 ;
* V_316 ++ = V_38 -> V_212 ;
* V_316 ++ = V_38 -> V_227 ;
* V_316 ++ = V_38 -> V_209 ;
V_312 ++ ;
}
V_239 [ 0 ] = V_312 ;
V_239 [ 1 ] = V_188 ;
V_315 = V_4 -> V_5 -> V_319 - V_312 ;
if ( V_315 != 0 ) {
unsigned V_327 = V_315 * 3 * sizeof( V_239 [ 0 ] ) ;
memmove ( V_317 - V_327 , V_317 ,
V_318 - V_317 ) ;
V_318 -= V_327 ;
}
V_88 = V_318 - ( char * ) V_239 ;
F_84 ( V_261 , L_2 , V_328 , V_88 , V_239 ) ;
V_322: ;
}
static void F_110 ( struct V_264 * V_329 ,
const struct V_330 * V_331 )
{
if ( V_331 -> V_332 )
V_331 -> V_332 ( V_329 , V_331 , 1 ) ;
}
static int F_111 ( struct V_333 * V_334 ,
const struct V_335 * V_336 ,
long V_265 , T_2 * V_337 )
{
unsigned int V_95 ;
F_85 ( & V_334 -> V_263 , V_334 -> V_329 , V_265 ) ;
( void ) V_336 -> V_338 [ 0 ] . F_112 ( V_334 -> V_329 , & V_336 -> V_338 [ 0 ] ,
0 , F_113 ( V_334 -> V_263 . V_339 ) ,
F_114 ( & V_334 -> V_263 ) , NULL ) ;
F_84 ( & V_334 -> V_340 [ 0 ] , L_2 , V_341 ,
F_115 ( V_334 -> V_263 ) , & V_334 -> V_263 ) ;
* V_337 += F_77 ( & V_334 -> V_340 [ 0 ] ) ;
F_110 ( V_334 -> V_329 , & V_336 -> V_338 [ 0 ] ) ;
for ( V_95 = 1 ; V_95 < V_336 -> V_315 ; ++ V_95 ) {
const struct V_330 * V_331 = & V_336 -> V_338 [ V_95 ] ;
F_110 ( V_334 -> V_329 , V_331 ) ;
if ( V_331 -> V_342 && V_331 -> F_112 &&
( ! V_331 -> V_343 || V_331 -> V_343 ( V_334 -> V_329 , V_331 ) ) ) {
int V_344 ;
T_2 V_88 = V_331 -> V_315 * V_331 -> V_88 ;
void * V_239 = F_34 ( V_88 , V_116 ) ;
if ( F_52 ( ! V_239 ) )
return 0 ;
V_344 = V_331 -> F_112 ( V_334 -> V_329 , V_331 ,
0 , V_88 , V_239 , NULL ) ;
if ( F_52 ( V_344 ) )
F_36 ( V_239 ) ;
else {
if ( V_331 -> V_342 != V_345 )
F_84 ( & V_334 -> V_340 [ V_95 ] , L_3 ,
V_331 -> V_342 ,
V_88 , V_239 ) ;
else {
F_116 ( & V_334 -> V_263 , 1 ) ;
F_84 ( & V_334 -> V_340 [ V_95 ] , L_2 ,
V_345 , V_88 , V_239 ) ;
}
* V_337 += F_77 ( & V_334 -> V_340 [ V_95 ] ) ;
}
}
}
return 1 ;
}
static int F_117 ( struct V_15 * V_240 , int V_346 ,
struct V_347 * V_348 ,
T_12 * V_308 , struct V_156 * V_157 )
{
struct V_264 * V_349 = V_4 ;
const struct V_335 * V_336 = F_118 ( V_349 ) ;
struct V_333 * V_334 ;
struct V_289 * V_290 ;
struct V_350 * V_351 ;
unsigned int V_95 ;
V_348 -> V_88 = 0 ;
V_348 -> V_352 = NULL ;
V_290 = F_34 ( sizeof( * V_290 ) , V_116 ) ;
if ( V_290 == NULL ) {
V_348 -> V_290 . V_239 = NULL ;
return 0 ;
}
F_84 ( & V_348 -> V_290 , L_2 , V_353 , sizeof( * V_290 ) , V_290 ) ;
V_348 -> V_354 = 0 ;
for ( V_95 = 0 ; V_95 < V_336 -> V_315 ; ++ V_95 )
if ( V_336 -> V_338 [ V_95 ] . V_342 != 0 )
++ V_348 -> V_354 ;
if ( F_52 ( V_348 -> V_354 == 0 ) ||
F_52 ( V_336 -> V_338 [ 0 ] . V_342 != V_341 ) ) {
F_119 ( 1 ) ;
return 0 ;
}
F_82 ( V_240 , V_346 ,
V_336 -> V_252 , V_336 -> V_254 ) ;
for ( V_351 = & V_349 -> V_5 -> V_355 -> V_356 ; V_351 ; V_351 = V_351 -> V_357 ) {
V_334 = F_120 ( F_121 ( struct V_333 ,
V_340 [ V_348 -> V_354 ] ) ,
V_116 ) ;
if ( F_52 ( ! V_334 ) )
return 0 ;
V_334 -> V_329 = V_351 -> V_329 ;
if ( V_351 -> V_329 == V_349 || ! V_348 -> V_352 ) {
V_334 -> V_357 = V_348 -> V_352 ;
V_348 -> V_352 = V_334 ;
} else {
V_334 -> V_357 = V_348 -> V_352 -> V_357 ;
V_348 -> V_352 -> V_357 = V_334 ;
}
}
for ( V_334 = V_348 -> V_352 ; V_334 != NULL ; V_334 = V_334 -> V_357 )
if ( ! F_111 ( V_334 , V_336 , V_308 -> V_267 , & V_348 -> V_88 ) )
return 0 ;
F_95 ( V_290 , V_349 -> V_358 , V_349 -> V_5 ) ;
V_348 -> V_88 += F_77 ( & V_348 -> V_290 ) ;
F_103 ( & V_348 -> V_359 , & V_348 -> V_307 , V_308 ) ;
V_348 -> V_88 += F_77 ( & V_348 -> V_359 ) ;
F_102 ( & V_348 -> V_304 , V_4 -> V_5 ) ;
V_348 -> V_88 += F_77 ( & V_348 -> V_304 ) ;
F_105 ( & V_348 -> V_360 ) ;
V_348 -> V_88 += F_77 ( & V_348 -> V_360 ) ;
return 1 ;
}
static T_2 F_122 ( struct V_347 * V_348 )
{
return V_348 -> V_88 ;
}
static int F_123 ( struct V_347 * V_348 ,
struct V_82 * V_82 , T_8 * V_234 )
{
bool V_361 = 1 ;
struct V_333 * V_334 = V_348 -> V_352 ;
do {
int V_95 ;
if ( ! F_81 ( & V_334 -> V_340 [ 0 ] , V_82 , V_234 ) )
return 0 ;
if ( V_361 && ! F_81 ( & V_348 -> V_290 , V_82 , V_234 ) )
return 0 ;
if ( V_361 && ! F_81 ( & V_348 -> V_359 , V_82 , V_234 ) )
return 0 ;
if ( V_361 && ! F_81 ( & V_348 -> V_304 , V_82 , V_234 ) )
return 0 ;
if ( V_361 && ! F_81 ( & V_348 -> V_360 , V_82 , V_234 ) )
return 0 ;
for ( V_95 = 1 ; V_95 < V_348 -> V_354 ; ++ V_95 )
if ( V_334 -> V_340 [ V_95 ] . V_239 &&
! F_81 ( & V_334 -> V_340 [ V_95 ] , V_82 , V_234 ) )
return 0 ;
V_361 = 0 ;
V_334 = V_334 -> V_357 ;
} while ( V_334 );
return 1 ;
}
static void F_124 ( struct V_347 * V_348 )
{
struct V_333 * V_362 = V_348 -> V_352 ;
while ( V_362 ) {
unsigned int V_95 ;
struct V_333 * V_334 = V_362 ;
V_362 = V_334 -> V_357 ;
F_119 ( V_334 -> V_340 [ 0 ] . V_239 && V_334 -> V_340 [ 0 ] . V_239 != & V_334 -> V_263 ) ;
for ( V_95 = 1 ; V_95 < V_348 -> V_354 ; ++ V_95 )
F_36 ( V_334 -> V_340 [ V_95 ] . V_239 ) ;
F_36 ( V_334 ) ;
}
F_36 ( V_348 -> V_290 . V_239 ) ;
F_109 ( V_348 -> V_360 . V_239 ) ;
}
static int F_125 ( long V_265 , struct V_363 * V_334 )
{
int V_230 = 0 ;
struct V_264 * V_19 = V_334 -> V_352 ;
V_334 -> V_364 = 0 ;
F_85 ( & V_334 -> V_263 , V_19 , V_265 ) ;
F_126 ( V_19 , & V_334 -> V_263 . V_339 ) ;
F_84 ( & V_334 -> V_340 [ 0 ] , L_2 , V_341 , sizeof( V_334 -> V_263 ) ,
& ( V_334 -> V_263 ) ) ;
V_334 -> V_364 ++ ;
V_230 += F_77 ( & V_334 -> V_340 [ 0 ] ) ;
if ( ( V_334 -> V_263 . V_365 = F_127 ( V_19 , NULL ,
& V_334 -> V_366 ) ) ) {
F_84 ( & V_334 -> V_340 [ 1 ] , L_2 , V_345 , sizeof( V_334 -> V_366 ) ,
& ( V_334 -> V_366 ) ) ;
V_334 -> V_364 ++ ;
V_230 += F_77 ( & V_334 -> V_340 [ 1 ] ) ;
}
#ifdef F_128
if ( F_129 ( V_19 , & V_334 -> V_367 ) ) {
F_84 ( & V_334 -> V_340 [ 2 ] , L_3 , V_368 ,
sizeof( V_334 -> V_367 ) , & V_334 -> V_367 ) ;
V_334 -> V_364 ++ ;
V_230 += F_77 ( & V_334 -> V_340 [ 2 ] ) ;
}
#endif
return V_230 ;
}
static int F_130 ( struct V_347 * V_348 )
{
memset ( V_348 , 0 , sizeof( * V_348 ) ) ;
F_131 ( & V_348 -> V_369 ) ;
V_348 -> V_340 = F_34 ( 8 * sizeof( struct V_228 ) , V_116 ) ;
if ( ! V_348 -> V_340 )
return 0 ;
V_348 -> V_290 = F_34 ( sizeof( * V_348 -> V_290 ) , V_116 ) ;
if ( ! V_348 -> V_290 )
return 0 ;
V_348 -> V_263 = F_34 ( sizeof( * V_348 -> V_263 ) , V_116 ) ;
if ( ! V_348 -> V_263 )
return 0 ;
V_348 -> V_366 = F_34 ( sizeof( * V_348 -> V_366 ) , V_116 ) ;
if ( ! V_348 -> V_366 )
return 0 ;
#ifdef F_128
V_348 -> V_367 = F_34 ( sizeof( * V_348 -> V_367 ) , V_116 ) ;
if ( ! V_348 -> V_367 )
return 0 ;
#endif
return 1 ;
}
static int F_117 ( struct V_15 * V_240 , int V_346 ,
struct V_347 * V_348 ,
T_12 * V_308 , struct V_156 * V_157 )
{
struct V_370 * V_334 ;
if ( ! F_130 ( V_348 ) )
return 0 ;
if ( V_308 -> V_267 ) {
struct V_350 * V_351 ;
struct V_363 * V_371 ;
for ( V_351 = V_4 -> V_5 -> V_355 -> V_356 . V_357 ;
V_351 ; V_351 = V_351 -> V_357 ) {
V_371 = F_120 ( sizeof( * V_371 ) , V_116 ) ;
if ( ! V_371 )
return 0 ;
V_371 -> V_352 = V_351 -> V_329 ;
F_132 ( & V_371 -> V_372 , & V_348 -> V_369 ) ;
}
F_133 (t, &info->thread_list) {
int V_230 ;
V_371 = F_134 ( V_334 , struct V_363 , V_372 ) ;
V_230 = F_125 ( V_308 -> V_267 , V_371 ) ;
V_348 -> V_373 += V_230 ;
}
}
memset ( V_348 -> V_263 , 0 , sizeof( * V_348 -> V_263 ) ) ;
F_85 ( V_348 -> V_263 , V_4 , V_308 -> V_267 ) ;
F_135 ( & V_348 -> V_263 -> V_339 , V_157 ) ;
F_82 ( V_240 , V_346 , V_374 , V_375 ) ;
F_84 ( V_348 -> V_340 + 0 , L_2 , V_341 ,
sizeof( * V_348 -> V_263 ) , V_348 -> V_263 ) ;
F_95 ( V_348 -> V_290 , V_4 -> V_358 , V_4 -> V_5 ) ;
F_84 ( V_348 -> V_340 + 1 , L_2 , V_353 ,
sizeof( * V_348 -> V_290 ) , V_348 -> V_290 ) ;
F_103 ( V_348 -> V_340 + 2 , & V_348 -> V_307 , V_308 ) ;
F_102 ( V_348 -> V_340 + 3 , V_4 -> V_5 ) ;
F_105 ( V_348 -> V_340 + 4 ) ;
V_348 -> V_376 = 5 ;
V_348 -> V_263 -> V_365 = F_127 ( V_4 , V_157 ,
V_348 -> V_366 ) ;
if ( V_348 -> V_263 -> V_365 )
F_84 ( V_348 -> V_340 + V_348 -> V_376 ++ ,
L_2 , V_345 , sizeof( * V_348 -> V_366 ) , V_348 -> V_366 ) ;
#ifdef F_128
if ( F_129 ( V_4 , V_348 -> V_367 ) )
F_84 ( V_348 -> V_340 + V_348 -> V_376 ++ ,
L_3 , V_368 ,
sizeof( * V_348 -> V_367 ) , V_348 -> V_367 ) ;
#endif
return 1 ;
}
static T_2 F_122 ( struct V_347 * V_348 )
{
int V_230 = 0 ;
int V_95 ;
for ( V_95 = 0 ; V_95 < V_348 -> V_376 ; V_95 ++ )
V_230 += F_77 ( V_348 -> V_340 + V_95 ) ;
V_230 += V_348 -> V_373 ;
return V_230 ;
}
static int F_123 ( struct V_347 * V_348 ,
struct V_82 * V_82 , T_8 * V_234 )
{
int V_95 ;
struct V_370 * V_334 ;
for ( V_95 = 0 ; V_95 < V_348 -> V_376 ; V_95 ++ )
if ( ! F_81 ( V_348 -> V_340 + V_95 , V_82 , V_234 ) )
return 0 ;
F_133 (t, &info->thread_list) {
struct V_363 * V_377 =
F_134 ( V_334 , struct V_363 , V_372 ) ;
for ( V_95 = 0 ; V_95 < V_377 -> V_364 ; V_95 ++ )
if ( ! F_81 ( & V_377 -> V_340 [ V_95 ] , V_82 , V_234 ) )
return 0 ;
}
return 1 ;
}
static void F_124 ( struct V_347 * V_348 )
{
while ( ! F_136 ( & V_348 -> V_369 ) ) {
struct V_370 * V_377 = V_348 -> V_369 . V_357 ;
F_137 ( V_377 ) ;
F_36 ( F_134 ( V_377 , struct V_363 , V_372 ) ) ;
}
F_109 ( V_348 -> V_340 [ 4 ] . V_239 ) ;
F_36 ( V_348 -> V_263 ) ;
F_36 ( V_348 -> V_290 ) ;
F_36 ( V_348 -> V_340 ) ;
F_36 ( V_348 -> V_366 ) ;
#ifdef F_128
F_36 ( V_348 -> V_367 ) ;
#endif
}
static struct V_37 * F_138 ( struct V_264 * V_378 ,
struct V_37 * V_379 )
{
struct V_37 * V_344 = V_378 -> V_5 -> V_114 ;
if ( V_344 )
return V_344 ;
return V_379 ;
}
static struct V_37 * F_139 ( struct V_37 * V_380 ,
struct V_37 * V_379 )
{
struct V_37 * V_344 ;
V_344 = V_380 -> V_323 ;
if ( V_344 )
return V_344 ;
if ( V_380 == V_379 )
return NULL ;
return V_379 ;
}
static void F_140 ( struct V_15 * V_240 , struct V_381 * V_382 ,
T_1 V_383 , int V_241 )
{
V_240 -> V_383 = V_383 ;
V_240 -> V_384 = sizeof( * V_382 ) ;
V_240 -> V_385 = 1 ;
V_240 -> V_386 = V_387 ;
memset ( V_382 , 0 , sizeof( * V_382 ) ) ;
V_382 -> V_388 = V_389 ;
V_382 -> V_390 = V_240 -> V_385 ;
V_382 -> V_391 = V_240 -> V_386 ;
V_382 -> V_392 = V_241 ;
}
static T_2 F_141 ( struct V_37 * V_379 ,
unsigned long V_192 )
{
struct V_37 * V_38 ;
T_2 V_88 = 0 ;
for ( V_38 = F_138 ( V_4 , V_379 ) ; V_38 != NULL ;
V_38 = F_139 ( V_38 , V_379 ) )
V_88 += F_70 ( V_38 , V_192 ) ;
return V_88 ;
}
static int F_142 ( struct V_393 * V_394 )
{
int V_395 = 0 ;
T_7 V_214 ;
int V_241 ;
T_2 V_88 = 0 ;
struct V_37 * V_38 , * V_379 ;
struct V_15 * V_240 = NULL ;
T_8 V_257 = 0 , V_396 , V_234 ;
struct V_347 V_348 ;
struct V_50 * V_397 = NULL ;
struct V_381 * V_382 = NULL ;
T_14 V_52 ;
T_1 V_383 ;
V_240 = F_34 ( sizeof( * V_240 ) , V_116 ) ;
if ( ! V_240 )
goto V_112;
V_241 = V_4 -> V_5 -> V_319 ;
V_241 += F_143 () ;
V_379 = F_68 ( V_4 -> V_5 ) ;
if ( V_379 != NULL )
V_241 ++ ;
V_241 ++ ;
V_52 = V_241 > V_398 ? V_398 : V_241 ;
if ( ! F_117 ( V_240 , V_52 , & V_348 , V_394 -> V_308 , V_394 -> V_157 ) )
goto V_399;
V_395 = 1 ;
V_214 = F_73 () ;
F_75 ( V_310 ) ;
V_257 += sizeof( * V_240 ) ;
V_257 += V_241 * sizeof( struct V_50 ) ;
V_234 = V_257 ;
{
T_2 V_230 = F_122 ( & V_348 ) ;
V_230 += F_144 () ;
V_397 = F_34 ( sizeof( * V_397 ) , V_116 ) ;
if ( ! V_397 )
goto V_400;
F_83 ( V_397 , V_230 , V_257 ) ;
V_257 += V_230 ;
}
V_396 = V_257 = F_78 ( V_257 , V_44 ) ;
V_257 += F_141 ( V_379 , V_394 -> V_192 ) ;
V_257 += F_145 () ;
V_383 = V_257 ;
if ( V_52 == V_398 ) {
V_382 = F_34 ( sizeof( * V_382 ) , V_116 ) ;
if ( ! V_382 )
goto V_400;
F_140 ( V_240 , V_382 , V_383 , V_241 ) ;
}
V_257 = V_396 ;
V_88 += sizeof( * V_240 ) ;
if ( V_88 > V_394 -> V_401 || ! F_146 ( V_394 -> V_82 , V_240 , sizeof( * V_240 ) ) )
goto V_400;
V_88 += sizeof( * V_397 ) ;
if ( V_88 > V_394 -> V_401
|| ! F_146 ( V_394 -> V_82 , V_397 , sizeof( * V_397 ) ) )
goto V_400;
for ( V_38 = F_138 ( V_4 , V_379 ) ; V_38 != NULL ;
V_38 = F_139 ( V_38 , V_379 ) ) {
struct V_50 V_256 ;
V_256 . V_98 = V_99 ;
V_256 . V_92 = V_257 ;
V_256 . V_90 = V_38 -> V_212 ;
V_256 . V_259 = 0 ;
V_256 . V_89 = F_70 ( V_38 , V_394 -> V_192 ) ;
V_256 . V_100 = V_38 -> V_227 - V_38 -> V_212 ;
V_257 += V_256 . V_89 ;
V_256 . V_125 = V_38 -> V_194 & V_210 ? V_126 : 0 ;
if ( V_38 -> V_194 & V_402 )
V_256 . V_125 |= V_128 ;
if ( V_38 -> V_194 & V_403 )
V_256 . V_125 |= V_130 ;
V_256 . V_260 = V_44 ;
V_88 += sizeof( V_256 ) ;
if ( V_88 > V_394 -> V_401
|| ! F_146 ( V_394 -> V_82 , & V_256 , sizeof( V_256 ) ) )
goto V_400;
}
if ( ! F_147 ( V_394 -> V_82 , V_257 , & V_88 , V_394 -> V_401 ) )
goto V_400;
if ( ! F_123 ( & V_348 , V_394 -> V_82 , & V_234 ) )
goto V_400;
if ( F_148 ( V_394 -> V_82 , & V_234 ) )
goto V_400;
if ( ! F_149 ( V_394 -> V_82 , V_396 - V_234 ) )
goto V_400;
for ( V_38 = F_138 ( V_4 , V_379 ) ; V_38 != NULL ;
V_38 = F_139 ( V_38 , V_379 ) ) {
unsigned long V_3 ;
unsigned long V_2 ;
V_2 = V_38 -> V_212 + F_70 ( V_38 , V_394 -> V_192 ) ;
for ( V_3 = V_38 -> V_212 ; V_3 < V_2 ; V_3 += V_188 ) {
struct V_404 * V_404 ;
int V_405 ;
V_404 = F_150 ( V_3 ) ;
if ( V_404 ) {
void * V_406 = F_151 ( V_404 ) ;
V_405 = ( ( V_88 += V_188 ) > V_394 -> V_401 ) ||
! F_146 ( V_394 -> V_82 , V_406 ,
V_188 ) ;
F_152 ( V_404 ) ;
F_153 ( V_404 ) ;
} else
V_405 = ! F_149 ( V_394 -> V_82 , V_188 ) ;
if ( V_405 )
goto V_400;
}
}
if ( ! F_154 ( V_394 -> V_82 , & V_88 , V_394 -> V_401 ) )
goto V_400;
if ( V_52 == V_398 ) {
V_88 += sizeof( * V_382 ) ;
if ( V_88 > V_394 -> V_401
|| ! F_146 ( V_394 -> V_82 , V_382 ,
sizeof( * V_382 ) ) )
goto V_400;
}
V_400:
F_75 ( V_214 ) ;
V_399:
F_124 ( & V_348 ) ;
F_36 ( V_382 ) ;
F_36 ( V_397 ) ;
F_36 ( V_240 ) ;
V_112:
return V_395 ;
}
static int T_15 F_155 ( void )
{
F_156 ( & V_185 ) ;
return 0 ;
}
static void T_16 F_157 ( void )
{
F_158 ( & V_185 ) ;
}
