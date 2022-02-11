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
if ( ! V_102 -> V_113 -> V_114 )
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
struct V_155 * V_156 = F_41 () ;
struct {
struct V_15 V_157 ;
struct V_15 V_101 ;
} * V_158 ;
V_158 = F_34 ( sizeof( * V_158 ) , V_116 ) ;
if ( ! V_158 ) {
V_108 = - V_134 ;
goto V_159;
}
V_158 -> V_157 = * ( (struct V_15 * ) V_14 -> V_160 ) ;
V_108 = - V_161 ;
if ( memcmp ( V_158 -> V_157 . V_162 , V_163 , V_164 ) != 0 )
goto V_112;
if ( V_158 -> V_157 . V_109 != V_110 && V_158 -> V_157 . V_109 != V_111 )
goto V_112;
if ( ! F_33 ( & V_158 -> V_157 ) )
goto V_112;
if ( ! V_14 -> V_82 -> V_113 -> V_114 )
goto V_112;
if ( V_158 -> V_157 . V_115 != sizeof( struct V_50 ) )
goto V_112;
if ( V_158 -> V_157 . V_52 < 1 ||
V_158 -> V_157 . V_52 > 65536U / sizeof( struct V_50 ) )
goto V_112;
V_88 = V_158 -> V_157 . V_52 * sizeof( struct V_50 ) ;
V_108 = - V_134 ;
V_105 = F_34 ( V_88 , V_116 ) ;
if ( ! V_105 )
goto V_112;
V_108 = F_35 ( V_14 -> V_82 , V_158 -> V_157 . V_48 ,
( char * ) V_105 , V_88 ) ;
if ( V_108 != V_88 ) {
if ( V_108 >= 0 )
V_108 = - V_117 ;
goto V_165;
}
V_145 = V_105 ;
V_8 = 0 ;
V_146 = 0 ;
V_148 = ~ 0UL ;
V_149 = 0 ;
V_150 = 0 ;
V_151 = 0 ;
for ( V_95 = 0 ; V_95 < V_158 -> V_157 . V_52 ; V_95 ++ ) {
if ( V_145 -> V_98 == V_166 ) {
V_108 = - V_161 ;
if ( V_145 -> V_89 > V_167 ||
V_145 -> V_89 < 2 )
goto V_165;
V_108 = - V_134 ;
V_144 = F_34 ( V_145 -> V_89 ,
V_116 ) ;
if ( ! V_144 )
goto V_165;
V_108 = F_35 ( V_14 -> V_82 , V_145 -> V_92 ,
V_144 ,
V_145 -> V_89 ) ;
if ( V_108 != V_145 -> V_89 ) {
if ( V_108 >= 0 )
V_108 = - V_117 ;
goto V_168;
}
V_108 = - V_161 ;
if ( V_144 [ V_145 -> V_89 - 1 ] != '\0' )
goto V_168;
V_102 = F_42 ( V_144 ) ;
V_108 = F_43 ( V_102 ) ;
if ( F_44 ( V_102 ) )
goto V_168;
F_45 ( V_14 , V_102 ) ;
V_108 = F_35 ( V_102 , 0 , V_14 -> V_160 ,
V_169 ) ;
if ( V_108 != V_169 ) {
if ( V_108 >= 0 )
V_108 = - V_117 ;
goto V_170;
}
V_158 -> V_101 = * ( (struct V_15 * ) V_14 -> V_160 ) ;
break;
}
V_145 ++ ;
}
V_145 = V_105 ;
for ( V_95 = 0 ; V_95 < V_158 -> V_157 . V_52 ; V_95 ++ , V_145 ++ )
if ( V_145 -> V_98 == V_171 ) {
if ( V_145 -> V_125 & V_130 )
V_153 = V_172 ;
else
V_153 = V_173 ;
break;
}
if ( V_144 ) {
V_108 = - V_174 ;
if ( memcmp ( V_158 -> V_101 . V_162 , V_163 , V_164 ) != 0 )
goto V_170;
if ( ! F_33 ( & V_158 -> V_101 ) )
goto V_170;
}
V_108 = F_46 ( V_14 ) ;
if ( V_108 )
goto V_170;
F_47 ( V_158 -> V_157 ) ;
if ( F_48 ( V_158 -> V_157 , V_153 ) )
V_4 -> V_139 |= V_175 ;
if ( ! ( V_4 -> V_139 & V_140 ) && V_176 )
V_4 -> V_137 |= V_138 ;
F_49 ( V_14 ) ;
V_108 = F_50 ( V_14 , F_37 ( V_177 ) ,
V_153 ) ;
if ( V_108 < 0 ) {
F_51 ( V_178 , V_4 , 0 ) ;
goto V_170;
}
V_4 -> V_5 -> V_179 = V_14 -> V_19 ;
for( V_95 = 0 , V_145 = V_105 ;
V_95 < V_158 -> V_157 . V_52 ; V_95 ++ , V_145 ++ ) {
int V_122 = 0 , V_180 ;
unsigned long V_124 , V_123 ;
if ( V_145 -> V_98 != V_99 )
continue;
if ( F_52 ( V_146 > V_8 ) ) {
unsigned long V_9 ;
V_108 = F_1 ( V_8 + V_143 ,
V_146 + V_143 ) ;
if ( V_108 ) {
F_51 ( V_178 , V_4 , 0 ) ;
goto V_170;
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
V_180 = V_120 | V_121 | V_181 ;
V_123 = V_145 -> V_90 ;
if ( V_158 -> V_157 . V_109 == V_110 || V_106 ) {
V_180 |= V_132 ;
} else if ( V_158 -> V_157 . V_109 == V_111 ) {
#ifdef F_53
if ( V_4 -> V_137 & V_138 )
V_143 = 0 ;
else
V_143 = F_28 ( V_182 - V_123 ) ;
#else
V_143 = F_28 ( V_182 - V_123 ) ;
#endif
}
error = F_27 ( V_14 -> V_82 , V_143 + V_123 , V_145 ,
V_122 , V_180 , 0 ) ;
if ( F_4 ( error ) ) {
F_51 ( V_178 , V_4 , 0 ) ;
V_108 = F_44 ( ( void * ) error ) ?
F_43 ( ( void * ) error ) : - V_79 ;
goto V_170;
}
if ( ! V_106 ) {
V_106 = 1 ;
V_17 = ( V_145 -> V_90 - V_145 -> V_92 ) ;
if ( V_158 -> V_157 . V_109 == V_111 ) {
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
F_51 ( V_178 , V_4 , 0 ) ;
V_108 = - V_79 ;
goto V_170;
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
V_158 -> V_157 . V_56 += V_143 ;
V_8 += V_143 ;
V_146 += V_143 ;
V_148 += V_143 ;
V_149 += V_143 ;
V_150 += V_143 ;
V_151 += V_143 ;
V_108 = F_1 ( V_8 , V_146 ) ;
if ( V_108 ) {
F_51 ( V_178 , V_4 , 0 ) ;
goto V_170;
}
if ( F_54 ( V_8 != V_146 ) && F_52 ( F_5 ( V_8 ) ) ) {
F_51 ( V_183 , V_4 , 0 ) ;
V_108 = - V_12 ;
goto V_170;
}
if ( V_144 ) {
unsigned long V_103 = 0 ;
V_147 = F_32 ( & V_158 -> V_101 ,
V_102 ,
& V_103 ,
V_143 ) ;
if ( ! F_44 ( ( void * ) V_147 ) ) {
V_18 = V_147 ;
V_147 += V_158 -> V_101 . V_56 ;
}
if ( F_4 ( V_147 ) ) {
F_55 ( V_183 , V_4 ) ;
V_108 = F_44 ( ( void * ) V_147 ) ?
( int ) V_147 : - V_79 ;
goto V_170;
}
T_5 = V_18 ;
F_56 ( V_102 ) ;
F_57 ( V_102 ) ;
F_36 ( V_144 ) ;
} else {
V_147 = V_158 -> V_157 . V_56 ;
if ( F_4 ( V_147 ) ) {
F_55 ( V_183 , V_4 ) ;
V_108 = - V_79 ;
goto V_170;
}
}
F_36 ( V_105 ) ;
F_58 ( & V_184 ) ;
#ifdef F_59
V_108 = F_60 ( V_14 , ! ! V_144 ) ;
if ( V_108 < 0 ) {
F_51 ( V_178 , V_4 , 0 ) ;
goto V_112;
}
#endif
F_61 ( V_14 ) ;
V_108 = F_8 ( V_14 , & V_158 -> V_157 ,
V_17 , V_18 ) ;
if ( V_108 < 0 ) {
F_51 ( V_178 , V_4 , 0 ) ;
goto V_112;
}
V_4 -> V_5 -> V_149 = V_149 ;
V_4 -> V_5 -> V_148 = V_148 ;
V_4 -> V_5 -> V_150 = V_150 ;
V_4 -> V_5 -> V_151 = V_151 ;
V_4 -> V_5 -> V_179 = V_14 -> V_19 ;
#ifdef F_62
if ( ( V_4 -> V_137 & V_138 ) && ( V_176 > 1 ) ) {
V_4 -> V_5 -> V_7 = V_4 -> V_5 -> V_6 =
F_62 ( V_4 -> V_5 ) ;
#ifdef F_63
V_4 -> V_185 = 1 ;
#endif
}
#endif
if ( V_4 -> V_139 & V_186 ) {
error = F_29 ( NULL , 0 , V_187 , V_127 | V_131 ,
V_132 | V_120 , 0 ) ;
}
#ifdef F_64
F_64 ( V_156 , T_5 ) ;
#endif
F_65 ( V_156 , V_147 , V_14 -> V_19 ) ;
V_108 = 0 ;
V_112:
F_36 ( V_158 ) ;
V_159:
return V_108 ;
V_170:
F_56 ( V_102 ) ;
if ( V_102 )
F_57 ( V_102 ) ;
V_168:
F_36 ( V_144 ) ;
V_165:
F_36 ( V_105 ) ;
goto V_112;
}
static int F_66 ( struct V_82 * V_82 )
{
struct V_50 * V_105 ;
struct V_50 * V_84 ;
unsigned long V_8 , V_188 , V_39 ;
int V_108 , error , V_95 , V_189 ;
struct V_15 V_157 ;
error = - V_161 ;
V_108 = F_35 ( V_82 , 0 , ( char * ) & V_157 , sizeof( V_157 ) ) ;
if ( V_108 != sizeof( V_157 ) )
goto V_112;
if ( memcmp ( V_157 . V_162 , V_163 , V_164 ) != 0 )
goto V_112;
if ( V_157 . V_109 != V_110 || V_157 . V_52 > 2 ||
! F_33 ( & V_157 ) || ! V_82 -> V_113 -> V_114 )
goto V_112;
V_189 = sizeof( struct V_50 ) * V_157 . V_52 ;
error = - V_134 ;
V_105 = F_34 ( V_189 , V_116 ) ;
if ( ! V_105 )
goto V_112;
V_84 = V_105 ;
error = - V_161 ;
V_108 = F_35 ( V_82 , V_157 . V_48 , ( char * ) V_84 , V_189 ) ;
if ( V_108 != V_189 )
goto V_165;
for ( V_189 = 0 , V_95 = 0 ; V_95 < V_157 . V_52 ; V_95 ++ )
if ( ( V_84 + V_95 ) -> V_98 == V_99 )
V_189 ++ ;
if ( V_189 != 1 )
goto V_165;
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
goto V_165;
V_8 = V_84 -> V_90 + V_84 -> V_89 ;
if ( F_5 ( V_8 ) ) {
error = - V_12 ;
goto V_165;
}
V_39 = F_28 ( V_84 -> V_89 + V_84 -> V_90 +
V_10 - 1 ) ;
V_188 = V_84 -> V_100 + V_84 -> V_90 ;
if ( V_188 > V_39 )
F_3 ( V_39 , V_188 - V_39 ) ;
error = 0 ;
V_165:
F_36 ( V_105 ) ;
V_112:
return error ;
}
static bool F_67 ( struct V_37 * V_38 )
{
if ( V_38 == F_68 ( V_38 -> V_190 ) )
return true ;
if ( V_38 -> V_191 && V_38 -> V_191 -> V_192 && V_38 -> V_191 -> V_192 ( V_38 ) )
return true ;
if ( F_69 ( V_38 ) )
return true ;
return false ;
}
static unsigned long F_70 ( struct V_37 * V_38 ,
unsigned long V_193 )
{
#define F_71 ( type ) (mm_flags & (1UL << MMF_DUMP_##type))
if ( F_67 ( V_38 ) )
goto V_194;
if ( V_38 -> V_195 & V_196 )
return 0 ;
if ( V_38 -> V_195 & V_197 ) {
if ( ( V_38 -> V_195 & V_198 ) && F_71 ( V_199 ) )
goto V_194;
if ( ! ( V_38 -> V_195 & V_198 ) && F_71 ( V_200 ) )
goto V_194;
return 0 ;
}
if ( V_38 -> V_195 & V_201 )
return 0 ;
if ( V_38 -> V_195 & V_198 ) {
if ( F_72 ( V_38 -> V_202 ) -> V_203 == 0 ?
F_71 ( V_204 ) : F_71 ( V_205 ) )
goto V_194;
return 0 ;
}
if ( V_38 -> V_206 && F_71 ( V_207 ) )
goto V_194;
if ( V_38 -> V_202 == NULL )
return 0 ;
if ( F_71 ( V_208 ) )
goto V_194;
if ( F_71 ( V_209 ) &&
V_38 -> V_210 == 0 && ( V_38 -> V_195 & V_211 ) ) {
T_6 V_11 * V_212 = ( T_6 V_11 * ) V_38 -> V_213 ;
T_6 V_214 ;
T_7 V_215 = F_73 () ;
union {
T_6 V_216 ;
char V_217 [ V_164 ] ;
} V_218 ;
F_74 ( V_164 != sizeof V_214 ) ;
V_218 . V_217 [ V_219 ] = V_220 ;
V_218 . V_217 [ V_221 ] = V_222 ;
V_218 . V_217 [ V_223 ] = V_224 ;
V_218 . V_217 [ V_225 ] = V_226 ;
F_75 ( V_227 ) ;
if ( F_52 ( F_76 ( V_214 , V_212 ) ) )
V_214 = 0 ;
F_75 ( V_215 ) ;
if ( V_214 == V_218 . V_216 )
return V_187 ;
}
#undef F_71
return 0 ;
V_194:
return V_38 -> V_228 - V_38 -> V_213 ;
}
static int F_77 ( struct V_229 * V_230 )
{
int V_231 ;
V_231 = sizeof( struct V_232 ) ;
V_231 += F_78 ( strlen ( V_230 -> V_192 ) + 1 , 4 ) ;
V_231 += F_78 ( V_230 -> V_233 , 4 ) ;
return V_231 ;
}
static int F_79 ( struct V_229 * V_234 , struct V_235 * V_236 )
{
struct V_232 V_230 ;
V_230 . V_237 = strlen ( V_234 -> V_192 ) + 1 ;
V_230 . V_238 = V_234 -> V_233 ;
V_230 . V_239 = V_234 -> type ;
return F_80 ( V_236 , & V_230 , sizeof( V_230 ) ) &&
F_80 ( V_236 , V_234 -> V_192 , V_230 . V_237 ) && F_81 ( V_236 , 4 ) &&
F_80 ( V_236 , V_234 -> V_240 , V_234 -> V_233 ) && F_81 ( V_236 , 4 ) ;
}
static void F_82 ( struct V_15 * V_241 , int V_242 ,
T_8 V_243 , T_6 V_137 )
{
memset ( V_241 , 0 , sizeof( * V_241 ) ) ;
memcpy ( V_241 -> V_162 , V_163 , V_164 ) ;
V_241 -> V_162 [ V_244 ] = V_245 ;
V_241 -> V_162 [ V_246 ] = V_247 ;
V_241 -> V_162 [ V_248 ] = V_249 ;
V_241 -> V_162 [ V_250 ] = V_251 ;
V_241 -> V_109 = V_252 ;
V_241 -> V_253 = V_243 ;
V_241 -> V_254 = V_249 ;
V_241 -> V_48 = sizeof( struct V_15 ) ;
V_241 -> V_255 = V_137 ;
V_241 -> V_256 = sizeof( struct V_15 ) ;
V_241 -> V_115 = sizeof( struct V_50 ) ;
V_241 -> V_52 = V_242 ;
return;
}
static void F_83 ( struct V_50 * V_257 , int V_231 , T_9 V_258 )
{
V_257 -> V_98 = V_259 ;
V_257 -> V_92 = V_258 ;
V_257 -> V_90 = 0 ;
V_257 -> V_260 = 0 ;
V_257 -> V_89 = V_231 ;
V_257 -> V_100 = 0 ;
V_257 -> V_125 = 0 ;
V_257 -> V_261 = 0 ;
return;
}
static void F_84 ( struct V_229 * V_262 , const char * V_192 , int type ,
unsigned int V_231 , void * V_240 )
{
V_262 -> V_192 = V_192 ;
V_262 -> type = type ;
V_262 -> V_233 = V_231 ;
V_262 -> V_240 = V_240 ;
return;
}
static void F_85 ( struct V_263 * V_264 ,
struct V_265 * V_19 , long V_266 )
{
V_264 -> V_267 . V_268 = V_264 -> V_269 = V_266 ;
V_264 -> V_270 = V_19 -> V_271 . signal . V_272 [ 0 ] ;
V_264 -> V_273 = V_19 -> V_274 . V_272 [ 0 ] ;
F_86 () ;
V_264 -> V_275 = F_87 ( F_88 ( V_19 -> V_276 ) ) ;
F_89 () ;
V_264 -> V_277 = F_87 ( V_19 ) ;
V_264 -> V_278 = F_90 ( V_19 ) ;
V_264 -> V_279 = F_91 ( V_19 ) ;
if ( F_92 ( V_19 ) ) {
struct V_280 V_281 ;
F_93 ( V_19 , & V_281 ) ;
F_94 ( V_281 . V_282 , & V_264 -> V_283 ) ;
F_94 ( V_281 . V_284 , & V_264 -> V_285 ) ;
} else {
T_10 V_282 , V_284 ;
V_280 ( V_19 , & V_282 , & V_284 ) ;
F_94 ( V_282 , & V_264 -> V_283 ) ;
F_94 ( V_284 , & V_264 -> V_285 ) ;
}
F_94 ( V_19 -> signal -> V_286 , & V_264 -> V_287 ) ;
F_94 ( V_19 -> signal -> V_288 , & V_264 -> V_289 ) ;
}
static int F_95 ( struct V_290 * V_291 , struct V_265 * V_19 ,
struct V_292 * V_5 )
{
const struct V_36 * V_36 ;
unsigned int V_95 , V_39 ;
memset ( V_291 , 0 , sizeof( struct V_290 ) ) ;
V_39 = V_5 -> V_76 - V_5 -> V_77 ;
if ( V_39 >= V_293 )
V_39 = V_293 - 1 ;
if ( F_96 ( & V_291 -> V_294 ,
( const char V_11 * ) V_5 -> V_77 , V_39 ) )
return - V_12 ;
for( V_95 = 0 ; V_95 < V_39 ; V_95 ++ )
if ( V_291 -> V_294 [ V_95 ] == 0 )
V_291 -> V_294 [ V_95 ] = ' ' ;
V_291 -> V_294 [ V_39 ] = 0 ;
F_86 () ;
V_291 -> V_275 = F_87 ( F_88 ( V_19 -> V_276 ) ) ;
F_89 () ;
V_291 -> V_277 = F_87 ( V_19 ) ;
V_291 -> V_278 = F_90 ( V_19 ) ;
V_291 -> V_279 = F_91 ( V_19 ) ;
V_95 = V_19 -> V_295 ? F_97 ( ~ V_19 -> V_295 ) + 1 : 0 ;
V_291 -> V_296 = V_95 ;
V_291 -> V_297 = ( V_95 > 5 ) ? '.' : L_1 [ V_95 ] ;
V_291 -> V_298 = V_291 -> V_297 == 'Z' ;
V_291 -> V_299 = F_98 ( V_19 ) ;
V_291 -> V_300 = V_19 -> V_137 ;
F_86 () ;
V_36 = F_99 ( V_19 ) ;
F_100 ( V_291 -> V_301 , F_16 ( V_36 -> V_58 , V_36 -> V_59 ) ) ;
F_101 ( V_291 -> V_302 , F_17 ( V_36 -> V_58 , V_36 -> V_63 ) ) ;
F_89 () ;
strncpy ( V_291 -> V_303 , V_19 -> V_304 , sizeof( V_291 -> V_303 ) ) ;
return 0 ;
}
static void F_102 ( struct V_229 * V_262 , struct V_292 * V_5 )
{
T_1 * V_305 = ( T_1 * ) V_5 -> V_40 ;
int V_95 = 0 ;
do
V_95 += 2 ;
while ( V_305 [ V_95 - 2 ] != V_306 );
F_84 ( V_262 , L_2 , V_307 , V_95 * sizeof( T_1 ) , V_305 ) ;
}
static void F_103 ( struct V_229 * V_262 , T_11 * V_308 ,
const T_12 * V_309 )
{
T_7 V_310 = F_73 () ;
F_75 ( V_311 ) ;
F_104 ( ( T_11 V_11 * ) V_308 , V_309 ) ;
F_75 ( V_310 ) ;
F_84 ( V_262 , L_2 , V_312 , sizeof( * V_308 ) , V_308 ) ;
}
static int F_105 ( struct V_229 * V_262 )
{
struct V_37 * V_38 ;
unsigned V_313 , V_88 , V_314 , V_315 , V_316 ;
T_13 * V_240 ;
T_13 * V_317 ;
char * V_318 , * V_319 ;
V_313 = V_4 -> V_5 -> V_320 ;
V_88 = V_313 * 64 ;
V_314 = ( 2 + 3 * V_313 ) * sizeof( V_240 [ 0 ] ) ;
V_321:
if ( V_88 >= V_322 )
return - V_79 ;
V_88 = F_106 ( V_88 , V_187 ) ;
V_240 = F_107 ( V_88 ) ;
if ( ! V_240 )
return - V_134 ;
V_317 = V_240 + 2 ;
V_318 = V_319 = ( ( char * ) V_240 ) + V_314 ;
V_315 = V_88 - V_314 ;
V_313 = 0 ;
for ( V_38 = V_4 -> V_5 -> V_114 ; V_38 != NULL ; V_38 = V_38 -> V_323 ) {
struct V_82 * V_82 ;
const char * V_324 ;
V_82 = V_38 -> V_202 ;
if ( ! V_82 )
continue;
V_324 = F_108 ( & V_82 -> V_325 , V_319 , V_315 ) ;
if ( F_44 ( V_324 ) ) {
if ( F_43 ( V_324 ) == - V_326 ) {
F_109 ( V_240 ) ;
V_88 = V_88 * 5 / 4 ;
goto V_321;
}
continue;
}
V_316 = ( V_319 + V_315 ) - V_324 ;
V_315 = V_324 - V_319 ;
memmove ( V_319 , V_324 , V_316 ) ;
V_319 += V_316 ;
* V_317 ++ = V_38 -> V_213 ;
* V_317 ++ = V_38 -> V_228 ;
* V_317 ++ = V_38 -> V_210 ;
V_313 ++ ;
}
V_240 [ 0 ] = V_313 ;
V_240 [ 1 ] = V_187 ;
V_316 = V_4 -> V_5 -> V_320 - V_313 ;
if ( V_316 != 0 ) {
unsigned V_327 = V_316 * 3 * sizeof( V_240 [ 0 ] ) ;
memmove ( V_318 - V_327 , V_318 ,
V_319 - V_318 ) ;
V_319 -= V_327 ;
}
V_88 = V_319 - ( char * ) V_240 ;
F_84 ( V_262 , L_2 , V_328 , V_88 , V_240 ) ;
return 0 ;
}
static void F_110 ( struct V_265 * V_329 ,
const struct V_330 * V_331 )
{
if ( V_331 -> V_332 )
V_331 -> V_332 ( V_329 , V_331 , 1 ) ;
}
static int F_111 ( struct V_333 * V_334 ,
const struct V_335 * V_336 ,
long V_266 , T_2 * V_337 )
{
unsigned int V_95 ;
F_85 ( & V_334 -> V_264 , V_334 -> V_329 , V_266 ) ;
( void ) V_336 -> V_338 [ 0 ] . F_112 ( V_334 -> V_329 , & V_336 -> V_338 [ 0 ] ,
0 , F_113 ( V_334 -> V_264 . V_339 ) ,
F_114 ( & V_334 -> V_264 ) , NULL ) ;
F_84 ( & V_334 -> V_340 [ 0 ] , L_2 , V_341 ,
F_115 ( V_334 -> V_264 ) , & V_334 -> V_264 ) ;
* V_337 += F_77 ( & V_334 -> V_340 [ 0 ] ) ;
F_110 ( V_334 -> V_329 , & V_336 -> V_338 [ 0 ] ) ;
for ( V_95 = 1 ; V_95 < V_336 -> V_316 ; ++ V_95 ) {
const struct V_330 * V_331 = & V_336 -> V_338 [ V_95 ] ;
F_110 ( V_334 -> V_329 , V_331 ) ;
if ( V_331 -> V_342 && V_331 -> F_112 &&
( ! V_331 -> V_343 || V_331 -> V_343 ( V_334 -> V_329 , V_331 ) ) ) {
int V_344 ;
T_2 V_88 = V_331 -> V_316 * V_331 -> V_88 ;
void * V_240 = F_34 ( V_88 , V_116 ) ;
if ( F_52 ( ! V_240 ) )
return 0 ;
V_344 = V_331 -> F_112 ( V_334 -> V_329 , V_331 ,
0 , V_88 , V_240 , NULL ) ;
if ( F_52 ( V_344 ) )
F_36 ( V_240 ) ;
else {
if ( V_331 -> V_342 != V_345 )
F_84 ( & V_334 -> V_340 [ V_95 ] , L_3 ,
V_331 -> V_342 ,
V_88 , V_240 ) ;
else {
F_116 ( & V_334 -> V_264 , 1 ) ;
F_84 ( & V_334 -> V_340 [ V_95 ] , L_2 ,
V_345 , V_88 , V_240 ) ;
}
* V_337 += F_77 ( & V_334 -> V_340 [ V_95 ] ) ;
}
}
}
return 1 ;
}
static int F_117 ( struct V_15 * V_241 , int V_346 ,
struct V_347 * V_348 ,
const T_12 * V_309 , struct V_155 * V_156 )
{
struct V_265 * V_349 = V_4 ;
const struct V_335 * V_336 = F_118 ( V_349 ) ;
struct V_333 * V_334 ;
struct V_290 * V_291 ;
struct V_350 * V_351 ;
unsigned int V_95 ;
V_348 -> V_88 = 0 ;
V_348 -> V_352 = NULL ;
V_291 = F_34 ( sizeof( * V_291 ) , V_116 ) ;
if ( V_291 == NULL ) {
V_348 -> V_291 . V_240 = NULL ;
return 0 ;
}
F_84 ( & V_348 -> V_291 , L_2 , V_353 , sizeof( * V_291 ) , V_291 ) ;
V_348 -> V_354 = 0 ;
for ( V_95 = 0 ; V_95 < V_336 -> V_316 ; ++ V_95 )
if ( V_336 -> V_338 [ V_95 ] . V_342 != 0 )
++ V_348 -> V_354 ;
if ( F_52 ( V_348 -> V_354 == 0 ) ||
F_52 ( V_336 -> V_338 [ 0 ] . V_342 != V_341 ) ) {
F_119 ( 1 ) ;
return 0 ;
}
F_82 ( V_241 , V_346 ,
V_336 -> V_253 , V_336 -> V_255 ) ;
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
if ( ! F_111 ( V_334 , V_336 , V_309 -> V_268 , & V_348 -> V_88 ) )
return 0 ;
F_95 ( V_291 , V_349 -> V_358 , V_349 -> V_5 ) ;
V_348 -> V_88 += F_77 ( & V_348 -> V_291 ) ;
F_103 ( & V_348 -> V_359 , & V_348 -> V_308 , V_309 ) ;
V_348 -> V_88 += F_77 ( & V_348 -> V_359 ) ;
F_102 ( & V_348 -> V_305 , V_4 -> V_5 ) ;
V_348 -> V_88 += F_77 ( & V_348 -> V_305 ) ;
if ( F_105 ( & V_348 -> V_360 ) == 0 )
V_348 -> V_88 += F_77 ( & V_348 -> V_360 ) ;
return 1 ;
}
static T_2 F_122 ( struct V_347 * V_348 )
{
return V_348 -> V_88 ;
}
static int F_123 ( struct V_347 * V_348 ,
struct V_235 * V_236 )
{
bool V_361 = true ;
struct V_333 * V_334 = V_348 -> V_352 ;
do {
int V_95 ;
if ( ! F_79 ( & V_334 -> V_340 [ 0 ] , V_236 ) )
return 0 ;
if ( V_361 && ! F_79 ( & V_348 -> V_291 , V_236 ) )
return 0 ;
if ( V_361 && ! F_79 ( & V_348 -> V_359 , V_236 ) )
return 0 ;
if ( V_361 && ! F_79 ( & V_348 -> V_305 , V_236 ) )
return 0 ;
if ( V_361 && V_348 -> V_360 . V_240 &&
! F_79 ( & V_348 -> V_360 , V_236 ) )
return 0 ;
for ( V_95 = 1 ; V_95 < V_348 -> V_354 ; ++ V_95 )
if ( V_334 -> V_340 [ V_95 ] . V_240 &&
! F_79 ( & V_334 -> V_340 [ V_95 ] , V_236 ) )
return 0 ;
V_361 = false ;
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
F_119 ( V_334 -> V_340 [ 0 ] . V_240 && V_334 -> V_340 [ 0 ] . V_240 != & V_334 -> V_264 ) ;
for ( V_95 = 1 ; V_95 < V_348 -> V_354 ; ++ V_95 )
F_36 ( V_334 -> V_340 [ V_95 ] . V_240 ) ;
F_36 ( V_334 ) ;
}
F_36 ( V_348 -> V_291 . V_240 ) ;
F_109 ( V_348 -> V_360 . V_240 ) ;
}
static int F_125 ( long V_266 , struct V_363 * V_334 )
{
int V_231 = 0 ;
struct V_265 * V_19 = V_334 -> V_352 ;
V_334 -> V_364 = 0 ;
F_85 ( & V_334 -> V_264 , V_19 , V_266 ) ;
F_126 ( V_19 , & V_334 -> V_264 . V_339 ) ;
F_84 ( & V_334 -> V_340 [ 0 ] , L_2 , V_341 , sizeof( V_334 -> V_264 ) ,
& ( V_334 -> V_264 ) ) ;
V_334 -> V_364 ++ ;
V_231 += F_77 ( & V_334 -> V_340 [ 0 ] ) ;
if ( ( V_334 -> V_264 . V_365 = F_127 ( V_19 , NULL ,
& V_334 -> V_366 ) ) ) {
F_84 ( & V_334 -> V_340 [ 1 ] , L_2 , V_345 , sizeof( V_334 -> V_366 ) ,
& ( V_334 -> V_366 ) ) ;
V_334 -> V_364 ++ ;
V_231 += F_77 ( & V_334 -> V_340 [ 1 ] ) ;
}
#ifdef F_128
if ( F_129 ( V_19 , & V_334 -> V_367 ) ) {
F_84 ( & V_334 -> V_340 [ 2 ] , L_3 , V_368 ,
sizeof( V_334 -> V_367 ) , & V_334 -> V_367 ) ;
V_334 -> V_364 ++ ;
V_231 += F_77 ( & V_334 -> V_340 [ 2 ] ) ;
}
#endif
return V_231 ;
}
static int F_130 ( struct V_347 * V_348 )
{
memset ( V_348 , 0 , sizeof( * V_348 ) ) ;
F_131 ( & V_348 -> V_369 ) ;
V_348 -> V_340 = F_34 ( 8 * sizeof( struct V_229 ) , V_116 ) ;
if ( ! V_348 -> V_340 )
return 0 ;
V_348 -> V_291 = F_34 ( sizeof( * V_348 -> V_291 ) , V_116 ) ;
if ( ! V_348 -> V_291 )
return 0 ;
V_348 -> V_264 = F_34 ( sizeof( * V_348 -> V_264 ) , V_116 ) ;
if ( ! V_348 -> V_264 )
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
static int F_117 ( struct V_15 * V_241 , int V_346 ,
struct V_347 * V_348 ,
const T_12 * V_309 , struct V_155 * V_156 )
{
struct V_370 * V_334 ;
struct V_350 * V_351 ;
struct V_363 * V_371 ;
if ( ! F_130 ( V_348 ) )
return 0 ;
for ( V_351 = V_4 -> V_5 -> V_355 -> V_356 . V_357 ;
V_351 ; V_351 = V_351 -> V_357 ) {
V_371 = F_120 ( sizeof( * V_371 ) , V_116 ) ;
if ( ! V_371 )
return 0 ;
V_371 -> V_352 = V_351 -> V_329 ;
F_132 ( & V_371 -> V_372 , & V_348 -> V_369 ) ;
}
F_133 (t, &info->thread_list) {
int V_231 ;
V_371 = F_134 ( V_334 , struct V_363 , V_372 ) ;
V_231 = F_125 ( V_309 -> V_268 , V_371 ) ;
V_348 -> V_373 += V_231 ;
}
memset ( V_348 -> V_264 , 0 , sizeof( * V_348 -> V_264 ) ) ;
F_85 ( V_348 -> V_264 , V_4 , V_309 -> V_268 ) ;
F_135 ( & V_348 -> V_264 -> V_339 , V_156 ) ;
F_82 ( V_241 , V_346 , V_374 , V_375 ) ;
F_84 ( V_348 -> V_340 + 0 , L_2 , V_341 ,
sizeof( * V_348 -> V_264 ) , V_348 -> V_264 ) ;
F_95 ( V_348 -> V_291 , V_4 -> V_358 , V_4 -> V_5 ) ;
F_84 ( V_348 -> V_340 + 1 , L_2 , V_353 ,
sizeof( * V_348 -> V_291 ) , V_348 -> V_291 ) ;
F_103 ( V_348 -> V_340 + 2 , & V_348 -> V_308 , V_309 ) ;
F_102 ( V_348 -> V_340 + 3 , V_4 -> V_5 ) ;
V_348 -> V_376 = 4 ;
if ( F_105 ( V_348 -> V_340 + V_348 -> V_376 ) == 0 ) {
V_348 -> V_377 = V_348 -> V_340 + V_348 -> V_376 ;
V_348 -> V_376 ++ ;
}
V_348 -> V_264 -> V_365 = F_127 ( V_4 , V_156 ,
V_348 -> V_366 ) ;
if ( V_348 -> V_264 -> V_365 )
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
int V_231 = 0 ;
int V_95 ;
for ( V_95 = 0 ; V_95 < V_348 -> V_376 ; V_95 ++ )
V_231 += F_77 ( V_348 -> V_340 + V_95 ) ;
V_231 += V_348 -> V_373 ;
return V_231 ;
}
static int F_123 ( struct V_347 * V_348 ,
struct V_235 * V_236 )
{
int V_95 ;
struct V_370 * V_334 ;
for ( V_95 = 0 ; V_95 < V_348 -> V_376 ; V_95 ++ )
if ( ! F_79 ( V_348 -> V_340 + V_95 , V_236 ) )
return 0 ;
F_133 (t, &info->thread_list) {
struct V_363 * V_378 =
F_134 ( V_334 , struct V_363 , V_372 ) ;
for ( V_95 = 0 ; V_95 < V_378 -> V_364 ; V_95 ++ )
if ( ! F_79 ( & V_378 -> V_340 [ V_95 ] , V_236 ) )
return 0 ;
}
return 1 ;
}
static void F_124 ( struct V_347 * V_348 )
{
while ( ! F_136 ( & V_348 -> V_369 ) ) {
struct V_370 * V_378 = V_348 -> V_369 . V_357 ;
F_137 ( V_378 ) ;
F_36 ( F_134 ( V_378 , struct V_363 , V_372 ) ) ;
}
if ( V_348 -> V_377 )
F_109 ( V_348 -> V_377 -> V_240 ) ;
F_36 ( V_348 -> V_264 ) ;
F_36 ( V_348 -> V_291 ) ;
F_36 ( V_348 -> V_340 ) ;
F_36 ( V_348 -> V_366 ) ;
#ifdef F_128
F_36 ( V_348 -> V_367 ) ;
#endif
}
static struct V_37 * F_138 ( struct V_265 * V_379 ,
struct V_37 * V_380 )
{
struct V_37 * V_344 = V_379 -> V_5 -> V_114 ;
if ( V_344 )
return V_344 ;
return V_380 ;
}
static struct V_37 * F_139 ( struct V_37 * V_381 ,
struct V_37 * V_380 )
{
struct V_37 * V_344 ;
V_344 = V_381 -> V_323 ;
if ( V_344 )
return V_344 ;
if ( V_381 == V_380 )
return NULL ;
return V_380 ;
}
static void F_140 ( struct V_15 * V_241 , struct V_382 * V_383 ,
T_1 V_384 , int V_242 )
{
V_241 -> V_384 = V_384 ;
V_241 -> V_385 = sizeof( * V_383 ) ;
V_241 -> V_386 = 1 ;
V_241 -> V_387 = V_388 ;
memset ( V_383 , 0 , sizeof( * V_383 ) ) ;
V_383 -> V_389 = V_390 ;
V_383 -> V_391 = V_241 -> V_386 ;
V_383 -> V_392 = V_241 -> V_387 ;
V_383 -> V_393 = V_242 ;
}
static T_2 F_141 ( struct V_37 * V_380 ,
unsigned long V_193 )
{
struct V_37 * V_38 ;
T_2 V_88 = 0 ;
for ( V_38 = F_138 ( V_4 , V_380 ) ; V_38 != NULL ;
V_38 = F_139 ( V_38 , V_380 ) )
V_88 += F_70 ( V_38 , V_193 ) ;
return V_88 ;
}
static int F_142 ( struct V_235 * V_236 )
{
int V_394 = 0 ;
T_7 V_215 ;
int V_242 ;
struct V_37 * V_38 , * V_380 ;
struct V_15 * V_241 = NULL ;
T_9 V_258 = 0 , V_395 ;
struct V_347 V_348 = { } ;
struct V_50 * V_396 = NULL ;
struct V_382 * V_383 = NULL ;
T_14 V_52 ;
T_1 V_384 ;
V_241 = F_34 ( sizeof( * V_241 ) , V_116 ) ;
if ( ! V_241 )
goto V_112;
V_242 = V_4 -> V_5 -> V_320 ;
V_242 += F_143 () ;
V_380 = F_68 ( V_4 -> V_5 ) ;
if ( V_380 != NULL )
V_242 ++ ;
V_242 ++ ;
V_52 = V_242 > V_397 ? V_397 : V_242 ;
if ( ! F_117 ( V_241 , V_52 , & V_348 , V_236 -> V_309 , V_236 -> V_156 ) )
goto V_398;
V_394 = 1 ;
V_215 = F_73 () ;
F_75 ( V_311 ) ;
V_258 += sizeof( * V_241 ) ;
V_258 += V_242 * sizeof( struct V_50 ) ;
{
T_2 V_231 = F_122 ( & V_348 ) ;
V_231 += F_144 () ;
V_396 = F_34 ( sizeof( * V_396 ) , V_116 ) ;
if ( ! V_396 )
goto V_399;
F_83 ( V_396 , V_231 , V_258 ) ;
V_258 += V_231 ;
}
V_395 = V_258 = F_78 ( V_258 , V_44 ) ;
V_258 += F_141 ( V_380 , V_236 -> V_193 ) ;
V_258 += F_145 () ;
V_384 = V_258 ;
if ( V_52 == V_397 ) {
V_383 = F_34 ( sizeof( * V_383 ) , V_116 ) ;
if ( ! V_383 )
goto V_399;
F_140 ( V_241 , V_383 , V_384 , V_242 ) ;
}
V_258 = V_395 ;
if ( ! F_80 ( V_236 , V_241 , sizeof( * V_241 ) ) )
goto V_399;
if ( ! F_80 ( V_236 , V_396 , sizeof( * V_396 ) ) )
goto V_399;
for ( V_38 = F_138 ( V_4 , V_380 ) ; V_38 != NULL ;
V_38 = F_139 ( V_38 , V_380 ) ) {
struct V_50 V_257 ;
V_257 . V_98 = V_99 ;
V_257 . V_92 = V_258 ;
V_257 . V_90 = V_38 -> V_213 ;
V_257 . V_260 = 0 ;
V_257 . V_89 = F_70 ( V_38 , V_236 -> V_193 ) ;
V_257 . V_100 = V_38 -> V_228 - V_38 -> V_213 ;
V_258 += V_257 . V_89 ;
V_257 . V_125 = V_38 -> V_195 & V_211 ? V_126 : 0 ;
if ( V_38 -> V_195 & V_400 )
V_257 . V_125 |= V_128 ;
if ( V_38 -> V_195 & V_401 )
V_257 . V_125 |= V_130 ;
V_257 . V_261 = V_44 ;
if ( ! F_80 ( V_236 , & V_257 , sizeof( V_257 ) ) )
goto V_399;
}
if ( ! F_146 ( V_236 , V_258 ) )
goto V_399;
if ( ! F_123 ( & V_348 , V_236 ) )
goto V_399;
if ( F_147 ( V_236 ) )
goto V_399;
if ( ! F_148 ( V_236 , V_395 - V_236 -> V_402 ) )
goto V_399;
for ( V_38 = F_138 ( V_4 , V_380 ) ; V_38 != NULL ;
V_38 = F_139 ( V_38 , V_380 ) ) {
unsigned long V_3 ;
unsigned long V_2 ;
V_2 = V_38 -> V_213 + F_70 ( V_38 , V_236 -> V_193 ) ;
for ( V_3 = V_38 -> V_213 ; V_3 < V_2 ; V_3 += V_187 ) {
struct V_403 * V_403 ;
int V_404 ;
V_403 = F_149 ( V_3 ) ;
if ( V_403 ) {
void * V_405 = F_150 ( V_403 ) ;
V_404 = ! F_80 ( V_236 , V_405 , V_187 ) ;
F_151 ( V_403 ) ;
F_152 ( V_403 ) ;
} else
V_404 = ! F_148 ( V_236 , V_187 ) ;
if ( V_404 )
goto V_399;
}
}
if ( ! F_153 ( V_236 ) )
goto V_399;
if ( V_52 == V_397 ) {
if ( ! F_80 ( V_236 , V_383 , sizeof( * V_383 ) ) )
goto V_399;
}
V_399:
F_75 ( V_215 ) ;
V_398:
F_124 ( & V_348 ) ;
F_36 ( V_383 ) ;
F_36 ( V_396 ) ;
F_36 ( V_241 ) ;
V_112:
return V_394 ;
}
static int T_15 F_154 ( void )
{
F_155 ( & V_184 ) ;
return 0 ;
}
static void T_16 F_156 ( void )
{
F_157 ( & V_184 ) ;
}
