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
F_14 ( V_68 , V_14 -> V_16 ) ;
if ( V_28 ) {
F_14 ( V_69 ,
( T_1 ) ( unsigned long ) V_25 ) ;
}
if ( V_30 ) {
F_14 ( V_70 ,
( T_1 ) ( unsigned long ) V_26 ) ;
}
if ( V_14 -> V_71 & V_72 ) {
F_14 ( V_73 , V_14 -> V_74 ) ;
}
#undef F_14
memset ( & V_34 [ V_35 ] , 0 ,
sizeof V_4 -> V_5 -> V_40 - V_35 * sizeof V_34 [ 0 ] ) ;
V_35 += 2 ;
V_24 = F_19 ( V_19 , V_35 ) ;
V_33 = ( V_20 + 1 ) + ( V_21 + 1 ) + 1 ;
V_14 -> V_19 = F_20 ( V_24 , V_33 ) ;
#ifdef F_21
V_24 = ( T_1 V_11 * ) V_14 -> V_19 - V_33 - V_35 ;
V_14 -> V_16 = ( unsigned long ) V_24 ;
#else
V_24 = ( T_1 V_11 * ) V_14 -> V_19 ;
#endif
V_38 = F_22 ( V_4 -> V_5 , V_14 -> V_19 ) ;
if ( ! V_38 )
return - V_12 ;
if ( F_23 ( V_20 , V_24 ++ ) )
return - V_12 ;
V_22 = V_24 ;
V_23 = V_22 + V_20 + 1 ;
V_19 = V_4 -> V_5 -> V_75 = V_4 -> V_5 -> V_76 ;
while ( V_20 -- > 0 ) {
T_2 V_39 ;
if ( F_23 ( ( T_1 ) V_19 , V_22 ++ ) )
return - V_12 ;
V_39 = F_24 ( ( void V_11 * ) V_19 , V_77 ) ;
if ( ! V_39 || V_39 > V_77 )
return - V_78 ;
V_19 += V_39 ;
}
if ( F_23 ( 0 , V_22 ) )
return - V_12 ;
V_4 -> V_5 -> V_75 = V_4 -> V_5 -> V_79 = V_19 ;
while ( V_21 -- > 0 ) {
T_2 V_39 ;
if ( F_23 ( ( T_1 ) V_19 , V_23 ++ ) )
return - V_12 ;
V_39 = F_24 ( ( void V_11 * ) V_19 , V_77 ) ;
if ( ! V_39 || V_39 > V_77 )
return - V_78 ;
V_19 += V_39 ;
}
if ( F_23 ( 0 , V_23 ) )
return - V_12 ;
V_4 -> V_5 -> V_80 = V_19 ;
V_24 = ( T_1 V_11 * ) V_23 + 1 ;
if ( F_25 ( V_24 , V_34 , V_35 * sizeof( T_1 ) ) )
return - V_12 ;
return 0 ;
}
static unsigned long F_26 ( struct V_81 * V_82 , unsigned long V_3 ,
struct V_50 * V_83 , int V_84 , int type ,
unsigned long V_85 )
{
unsigned long V_86 ;
unsigned long V_87 = V_83 -> V_88 + F_6 ( V_83 -> V_89 ) ;
unsigned long V_90 = V_83 -> V_91 - F_6 ( V_83 -> V_89 ) ;
V_3 = F_27 ( V_3 ) ;
V_87 = F_2 ( V_87 ) ;
if ( ! V_87 )
return V_3 ;
if ( V_85 ) {
V_85 = F_2 ( V_85 ) ;
V_86 = F_28 ( V_82 , V_3 , V_85 , V_84 , type , V_90 ) ;
if ( ! F_4 ( V_86 ) )
F_29 ( V_86 + V_87 , V_85 - V_87 ) ;
} else
V_86 = F_28 ( V_82 , V_3 , V_87 , V_84 , type , V_90 ) ;
return ( V_86 ) ;
}
static unsigned long F_30 ( struct V_50 * V_92 , int V_93 )
{
int V_94 , V_95 = - 1 , V_96 = - 1 ;
for ( V_94 = 0 ; V_94 < V_93 ; V_94 ++ ) {
if ( V_92 [ V_94 ] . V_97 == V_98 ) {
V_96 = V_94 ;
if ( V_95 == - 1 )
V_95 = V_94 ;
}
}
if ( V_95 == - 1 )
return 0 ;
return V_92 [ V_96 ] . V_89 + V_92 [ V_96 ] . V_99 -
F_27 ( V_92 [ V_95 ] . V_89 ) ;
}
static unsigned long F_31 ( struct V_15 * V_100 ,
struct V_81 * V_101 , unsigned long * V_102 ,
unsigned long V_103 )
{
struct V_50 * V_104 ;
struct V_50 * V_83 ;
unsigned long V_17 = 0 ;
int V_105 = 0 ;
unsigned long V_106 = 0 , V_8 = 0 ;
unsigned long error = ~ 0UL ;
unsigned long V_85 ;
int V_107 , V_94 , V_87 ;
if ( V_100 -> V_108 != V_109 &&
V_100 -> V_108 != V_110 )
goto V_111;
if ( ! F_32 ( V_100 ) )
goto V_111;
if ( ! V_101 -> V_112 || ! V_101 -> V_112 -> V_113 )
goto V_111;
if ( V_100 -> V_114 != sizeof( struct V_50 ) )
goto V_111;
if ( V_100 -> V_52 < 1 ||
V_100 -> V_52 > 65536U / sizeof( struct V_50 ) )
goto V_111;
V_87 = sizeof( struct V_50 ) * V_100 -> V_52 ;
if ( V_87 > V_10 )
goto V_111;
V_104 = F_33 ( V_87 , V_115 ) ;
if ( ! V_104 )
goto V_111;
V_107 = F_34 ( V_101 , V_100 -> V_48 ,
( char * ) V_104 , V_87 ) ;
error = - V_116 ;
if ( V_107 != V_87 ) {
if ( V_107 < 0 )
error = V_107 ;
goto V_117;
}
V_85 = F_30 ( V_104 , V_100 -> V_52 ) ;
if ( ! V_85 ) {
error = - V_78 ;
goto V_117;
}
V_83 = V_104 ;
for ( V_94 = 0 ; V_94 < V_100 -> V_52 ; V_94 ++ , V_83 ++ ) {
if ( V_83 -> V_97 == V_98 ) {
int V_118 = V_119 | V_120 ;
int V_121 = 0 ;
unsigned long V_122 = 0 ;
unsigned long V_123 , V_86 ;
if ( V_83 -> V_124 & V_125 )
V_121 = V_126 ;
if ( V_83 -> V_124 & V_127 )
V_121 |= V_128 ;
if ( V_83 -> V_124 & V_129 )
V_121 |= V_130 ;
V_122 = V_83 -> V_89 ;
if ( V_100 -> V_108 == V_109 || V_105 )
V_118 |= V_131 ;
else if ( V_103 && V_100 -> V_108 == V_110 )
V_17 = - V_122 ;
V_86 = F_26 ( V_101 , V_17 + V_122 ,
V_83 , V_121 , V_118 , V_85 ) ;
V_85 = 0 ;
if ( ! * V_102 )
* V_102 = V_86 ;
error = V_86 ;
if ( F_4 ( V_86 ) )
goto V_117;
if ( ! V_105 &&
V_100 -> V_108 == V_110 ) {
V_17 = V_86 - F_27 ( V_122 ) ;
V_105 = 1 ;
}
V_123 = V_17 + V_83 -> V_89 ;
if ( F_4 ( V_123 ) ||
V_83 -> V_88 > V_83 -> V_99 ||
V_83 -> V_99 > V_132 ||
V_132 - V_83 -> V_99 < V_123 ) {
error = - V_133 ;
goto V_117;
}
V_123 = V_17 + V_83 -> V_89 + V_83 -> V_88 ;
if ( V_123 > V_8 )
V_8 = V_123 ;
V_123 = V_17 + V_83 -> V_99 + V_83 -> V_89 ;
if ( V_123 > V_106 )
V_106 = V_123 ;
}
}
if ( V_106 > V_8 ) {
if ( F_5 ( V_8 ) ) {
error = - V_12 ;
goto V_117;
}
V_8 = F_27 ( V_8 + V_10 - 1 ) ;
error = F_3 ( V_8 , V_106 - V_8 ) ;
if ( F_4 ( error ) )
goto V_117;
}
error = V_17 ;
V_117:
F_35 ( V_104 ) ;
V_111:
return error ;
}
static unsigned long F_36 ( unsigned long V_134 )
{
unsigned int V_135 = 0 ;
if ( ( V_4 -> V_136 & V_137 ) &&
! ( V_4 -> V_138 & V_139 ) ) {
V_135 = F_37 () & V_140 ;
V_135 <<= V_141 ;
}
#ifdef F_21
return F_38 ( V_134 ) + V_135 ;
#else
return F_38 ( V_134 ) - V_135 ;
#endif
}
static int F_39 ( struct V_13 * V_14 )
{
struct V_81 * V_101 = NULL ;
unsigned long V_17 = 0 , V_142 = 0 ;
int V_105 = 0 ;
char * V_143 = NULL ;
unsigned long error ;
struct V_50 * V_144 , * V_104 ;
unsigned long V_8 , V_145 ;
int V_107 , V_94 ;
unsigned int V_87 ;
unsigned long V_146 ;
unsigned long V_18 = 0 ;
unsigned long V_147 , V_148 , V_149 , V_150 ;
unsigned long T_5 V_151 = 0 ;
int V_152 = V_153 ;
unsigned long V_154 = 0 ;
struct V_155 * V_156 = F_40 () ;
struct {
struct V_15 V_157 ;
struct V_15 V_100 ;
} * V_158 ;
V_158 = F_33 ( sizeof( * V_158 ) , V_115 ) ;
if ( ! V_158 ) {
V_107 = - V_133 ;
goto V_159;
}
V_158 -> V_157 = * ( (struct V_15 * ) V_14 -> V_160 ) ;
V_107 = - V_161 ;
if ( memcmp ( V_158 -> V_157 . V_162 , V_163 , V_164 ) != 0 )
goto V_111;
if ( V_158 -> V_157 . V_108 != V_109 && V_158 -> V_157 . V_108 != V_110 )
goto V_111;
if ( ! F_32 ( & V_158 -> V_157 ) )
goto V_111;
if ( ! V_14 -> V_81 -> V_112 || ! V_14 -> V_81 -> V_112 -> V_113 )
goto V_111;
if ( V_158 -> V_157 . V_114 != sizeof( struct V_50 ) )
goto V_111;
if ( V_158 -> V_157 . V_52 < 1 ||
V_158 -> V_157 . V_52 > 65536U / sizeof( struct V_50 ) )
goto V_111;
V_87 = V_158 -> V_157 . V_52 * sizeof( struct V_50 ) ;
V_107 = - V_133 ;
V_104 = F_33 ( V_87 , V_115 ) ;
if ( ! V_104 )
goto V_111;
V_107 = F_34 ( V_14 -> V_81 , V_158 -> V_157 . V_48 ,
( char * ) V_104 , V_87 ) ;
if ( V_107 != V_87 ) {
if ( V_107 >= 0 )
V_107 = - V_116 ;
goto V_165;
}
V_144 = V_104 ;
V_8 = 0 ;
V_145 = 0 ;
V_147 = ~ 0UL ;
V_148 = 0 ;
V_149 = 0 ;
V_150 = 0 ;
for ( V_94 = 0 ; V_94 < V_158 -> V_157 . V_52 ; V_94 ++ ) {
if ( V_144 -> V_97 == V_166 ) {
V_107 = - V_161 ;
if ( V_144 -> V_88 > V_167 ||
V_144 -> V_88 < 2 )
goto V_165;
V_107 = - V_133 ;
V_143 = F_33 ( V_144 -> V_88 ,
V_115 ) ;
if ( ! V_143 )
goto V_165;
V_107 = F_34 ( V_14 -> V_81 , V_144 -> V_91 ,
V_143 ,
V_144 -> V_88 ) ;
if ( V_107 != V_144 -> V_88 ) {
if ( V_107 >= 0 )
V_107 = - V_116 ;
goto V_168;
}
V_107 = - V_161 ;
if ( V_143 [ V_144 -> V_88 - 1 ] != '\0' )
goto V_168;
V_101 = F_41 ( V_143 ) ;
V_107 = F_42 ( V_101 ) ;
if ( F_43 ( V_101 ) )
goto V_168;
F_44 ( V_14 , V_101 ) ;
V_107 = F_34 ( V_101 , 0 , V_14 -> V_160 ,
V_169 ) ;
if ( V_107 != V_169 ) {
if ( V_107 >= 0 )
V_107 = - V_116 ;
goto V_170;
}
V_158 -> V_100 = * ( (struct V_15 * ) V_14 -> V_160 ) ;
break;
}
V_144 ++ ;
}
V_144 = V_104 ;
for ( V_94 = 0 ; V_94 < V_158 -> V_157 . V_52 ; V_94 ++ , V_144 ++ )
if ( V_144 -> V_97 == V_171 ) {
if ( V_144 -> V_124 & V_129 )
V_152 = V_172 ;
else
V_152 = V_173 ;
break;
}
if ( V_143 ) {
V_107 = - V_174 ;
if ( memcmp ( V_158 -> V_100 . V_162 , V_163 , V_164 ) != 0 )
goto V_170;
if ( ! F_32 ( & V_158 -> V_100 ) )
goto V_170;
}
V_107 = F_45 ( V_14 ) ;
if ( V_107 )
goto V_170;
V_4 -> V_5 -> V_154 = V_154 ;
F_46 ( V_158 -> V_157 ) ;
if ( F_47 ( V_158 -> V_157 , V_152 ) )
V_4 -> V_138 |= V_175 ;
if ( ! ( V_4 -> V_138 & V_139 ) && V_176 )
V_4 -> V_136 |= V_137 ;
F_48 ( V_14 ) ;
V_4 -> V_5 -> V_177 = V_4 -> V_5 -> V_178 ;
V_4 -> V_5 -> V_179 = 0 ;
V_107 = F_49 ( V_14 , F_36 ( V_180 ) ,
V_152 ) ;
if ( V_107 < 0 ) {
F_50 ( V_181 , V_4 , 0 ) ;
goto V_170;
}
V_4 -> V_5 -> V_182 = V_14 -> V_19 ;
for( V_94 = 0 , V_144 = V_104 ;
V_94 < V_158 -> V_157 . V_52 ; V_94 ++ , V_144 ++ ) {
int V_121 = 0 , V_183 ;
unsigned long V_123 , V_122 ;
if ( V_144 -> V_97 != V_98 )
continue;
if ( F_51 ( V_145 > V_8 ) ) {
unsigned long V_9 ;
V_107 = F_1 ( V_8 + V_142 ,
V_145 + V_142 ) ;
if ( V_107 ) {
F_50 ( V_181 , V_4 , 0 ) ;
goto V_170;
}
V_9 = F_6 ( V_8 ) ;
if ( V_9 ) {
V_9 = V_10 - V_9 ;
if ( V_9 > V_145 - V_8 )
V_9 = V_145 - V_8 ;
if ( F_7 ( ( void V_11 * ) V_8 +
V_142 , V_9 ) ) {
}
}
}
if ( V_144 -> V_124 & V_125 )
V_121 |= V_126 ;
if ( V_144 -> V_124 & V_127 )
V_121 |= V_128 ;
if ( V_144 -> V_124 & V_129 )
V_121 |= V_130 ;
V_183 = V_119 | V_120 | V_184 ;
V_122 = V_144 -> V_89 ;
if ( V_158 -> V_157 . V_108 == V_109 || V_105 ) {
V_183 |= V_131 ;
} else if ( V_158 -> V_157 . V_108 == V_110 ) {
#ifdef F_52
if ( V_4 -> V_136 & V_137 )
V_142 = 0 ;
else
V_142 = F_27 ( V_185 - V_122 ) ;
#else
V_142 = F_27 ( V_185 - V_122 ) ;
#endif
}
error = F_26 ( V_14 -> V_81 , V_142 + V_122 , V_144 ,
V_121 , V_183 , 0 ) ;
if ( F_4 ( error ) ) {
F_50 ( V_181 , V_4 , 0 ) ;
V_107 = F_43 ( ( void * ) error ) ?
F_42 ( ( void * ) error ) : - V_78 ;
goto V_170;
}
if ( ! V_105 ) {
V_105 = 1 ;
V_17 = ( V_144 -> V_89 - V_144 -> V_91 ) ;
if ( V_158 -> V_157 . V_108 == V_110 ) {
V_142 += error -
F_27 ( V_142 + V_122 ) ;
V_17 += V_142 ;
T_5 = V_142 ;
}
}
V_123 = V_144 -> V_89 ;
if ( V_123 < V_147 )
V_147 = V_123 ;
if ( V_149 < V_123 )
V_149 = V_123 ;
if ( F_4 ( V_123 ) || V_144 -> V_88 > V_144 -> V_99 ||
V_144 -> V_99 > V_132 ||
V_132 - V_144 -> V_99 < V_123 ) {
F_50 ( V_181 , V_4 , 0 ) ;
V_107 = - V_78 ;
goto V_170;
}
V_123 = V_144 -> V_89 + V_144 -> V_88 ;
if ( V_123 > V_8 )
V_8 = V_123 ;
if ( ( V_144 -> V_124 & V_129 ) && V_148 < V_123 )
V_148 = V_123 ;
if ( V_150 < V_123 )
V_150 = V_123 ;
V_123 = V_144 -> V_89 + V_144 -> V_99 ;
if ( V_123 > V_145 )
V_145 = V_123 ;
}
V_158 -> V_157 . V_56 += V_142 ;
V_8 += V_142 ;
V_145 += V_142 ;
V_147 += V_142 ;
V_148 += V_142 ;
V_149 += V_142 ;
V_150 += V_142 ;
V_107 = F_1 ( V_8 , V_145 ) ;
if ( V_107 ) {
F_50 ( V_181 , V_4 , 0 ) ;
goto V_170;
}
if ( F_53 ( V_8 != V_145 ) && F_51 ( F_5 ( V_8 ) ) ) {
F_50 ( V_186 , V_4 , 0 ) ;
V_107 = - V_12 ;
goto V_170;
}
if ( V_143 ) {
unsigned long V_102 = 0 ;
V_146 = F_31 ( & V_158 -> V_100 ,
V_101 ,
& V_102 ,
V_142 ) ;
if ( ! F_43 ( ( void * ) V_146 ) ) {
V_18 = V_146 ;
V_146 += V_158 -> V_100 . V_56 ;
}
if ( F_4 ( V_146 ) ) {
F_54 ( V_186 , V_4 ) ;
V_107 = F_43 ( ( void * ) V_146 ) ?
( int ) V_146 : - V_78 ;
goto V_170;
}
T_5 = V_18 ;
F_55 ( V_101 ) ;
F_56 ( V_101 ) ;
F_35 ( V_143 ) ;
} else {
V_146 = V_158 -> V_157 . V_56 ;
if ( F_4 ( V_146 ) ) {
F_54 ( V_186 , V_4 ) ;
V_107 = - V_78 ;
goto V_170;
}
}
F_35 ( V_104 ) ;
F_57 ( & V_187 ) ;
#ifdef F_58
V_107 = F_59 ( V_14 , ! ! V_143 ) ;
if ( V_107 < 0 ) {
F_50 ( V_181 , V_4 , 0 ) ;
goto V_111;
}
#endif
F_60 ( V_14 ) ;
V_107 = F_8 ( V_14 , & V_158 -> V_157 ,
V_17 , V_18 ) ;
if ( V_107 < 0 ) {
F_50 ( V_181 , V_4 , 0 ) ;
goto V_111;
}
V_4 -> V_5 -> V_148 = V_148 ;
V_4 -> V_5 -> V_147 = V_147 ;
V_4 -> V_5 -> V_149 = V_149 ;
V_4 -> V_5 -> V_150 = V_150 ;
V_4 -> V_5 -> V_182 = V_14 -> V_19 ;
#ifdef F_61
if ( ( V_4 -> V_136 & V_137 ) && ( V_176 > 1 ) ) {
V_4 -> V_5 -> V_7 = V_4 -> V_5 -> V_6 =
F_61 ( V_4 -> V_5 ) ;
#ifdef F_62
V_4 -> V_188 = 1 ;
#endif
}
#endif
if ( V_4 -> V_138 & V_189 ) {
error = F_28 ( NULL , 0 , V_190 , V_126 | V_130 ,
V_131 | V_119 , 0 ) ;
}
#ifdef F_63
F_63 ( V_156 , T_5 ) ;
#endif
F_64 ( V_156 , V_146 , V_14 -> V_19 ) ;
V_107 = 0 ;
V_111:
F_35 ( V_158 ) ;
V_159:
return V_107 ;
V_170:
F_55 ( V_101 ) ;
if ( V_101 )
F_56 ( V_101 ) ;
V_168:
F_35 ( V_143 ) ;
V_165:
F_35 ( V_104 ) ;
goto V_111;
}
static int F_65 ( struct V_81 * V_81 )
{
struct V_50 * V_104 ;
struct V_50 * V_83 ;
unsigned long V_8 , V_191 , V_39 ;
int V_107 , error , V_94 , V_192 ;
struct V_15 V_157 ;
error = - V_161 ;
V_107 = F_34 ( V_81 , 0 , ( char * ) & V_157 , sizeof( V_157 ) ) ;
if ( V_107 != sizeof( V_157 ) )
goto V_111;
if ( memcmp ( V_157 . V_162 , V_163 , V_164 ) != 0 )
goto V_111;
if ( V_157 . V_108 != V_109 || V_157 . V_52 > 2 ||
! F_32 ( & V_157 ) || ! V_81 -> V_112 || ! V_81 -> V_112 -> V_113 )
goto V_111;
V_192 = sizeof( struct V_50 ) * V_157 . V_52 ;
error = - V_133 ;
V_104 = F_33 ( V_192 , V_115 ) ;
if ( ! V_104 )
goto V_111;
V_83 = V_104 ;
error = - V_161 ;
V_107 = F_34 ( V_81 , V_157 . V_48 , ( char * ) V_83 , V_192 ) ;
if ( V_107 != V_192 )
goto V_165;
for ( V_192 = 0 , V_94 = 0 ; V_94 < V_157 . V_52 ; V_94 ++ )
if ( ( V_83 + V_94 ) -> V_97 == V_98 )
V_192 ++ ;
if ( V_192 != 1 )
goto V_165;
while ( V_83 -> V_97 != V_98 )
V_83 ++ ;
error = F_28 ( V_81 ,
F_27 ( V_83 -> V_89 ) ,
( V_83 -> V_88 +
F_6 ( V_83 -> V_89 ) ) ,
V_126 | V_128 | V_130 ,
V_131 | V_119 | V_120 ,
( V_83 -> V_91 -
F_6 ( V_83 -> V_89 ) ) ) ;
if ( error != F_27 ( V_83 -> V_89 ) )
goto V_165;
V_8 = V_83 -> V_89 + V_83 -> V_88 ;
if ( F_5 ( V_8 ) ) {
error = - V_12 ;
goto V_165;
}
V_39 = F_27 ( V_83 -> V_88 + V_83 -> V_89 +
V_10 - 1 ) ;
V_191 = V_83 -> V_99 + V_83 -> V_89 ;
if ( V_191 > V_39 )
F_3 ( V_39 , V_191 - V_39 ) ;
error = 0 ;
V_165:
F_35 ( V_104 ) ;
V_111:
return error ;
}
static bool F_66 ( struct V_37 * V_38 )
{
if ( V_38 == F_67 ( V_38 -> V_193 ) )
return true ;
if ( F_68 ( V_38 ) )
return true ;
return false ;
}
static unsigned long F_69 ( struct V_37 * V_38 ,
unsigned long V_194 )
{
#define F_70 ( type ) (mm_flags & (1UL << MMF_DUMP_##type))
if ( F_66 ( V_38 ) )
goto V_195;
if ( V_38 -> V_196 & V_197 )
return 0 ;
if ( V_38 -> V_196 & V_198 ) {
if ( ( V_38 -> V_196 & V_199 ) && F_70 ( V_200 ) )
goto V_195;
if ( ! ( V_38 -> V_196 & V_199 ) && F_70 ( V_201 ) )
goto V_195;
return 0 ;
}
if ( V_38 -> V_196 & V_202 )
return 0 ;
if ( V_38 -> V_196 & V_199 ) {
if ( F_71 ( V_38 -> V_203 ) -> V_204 == 0 ?
F_70 ( V_205 ) : F_70 ( V_206 ) )
goto V_195;
return 0 ;
}
if ( V_38 -> V_207 && F_70 ( V_208 ) )
goto V_195;
if ( V_38 -> V_203 == NULL )
return 0 ;
if ( F_70 ( V_209 ) )
goto V_195;
if ( F_70 ( V_210 ) &&
V_38 -> V_211 == 0 && ( V_38 -> V_196 & V_212 ) ) {
T_6 V_11 * V_213 = ( T_6 V_11 * ) V_38 -> V_214 ;
T_6 V_215 ;
T_7 V_216 = F_72 () ;
union {
T_6 V_217 ;
char V_218 [ V_164 ] ;
} V_219 ;
F_73 ( V_164 != sizeof V_215 ) ;
V_219 . V_218 [ V_220 ] = V_221 ;
V_219 . V_218 [ V_222 ] = V_223 ;
V_219 . V_218 [ V_224 ] = V_225 ;
V_219 . V_218 [ V_226 ] = V_227 ;
F_74 ( V_228 ) ;
if ( F_51 ( F_75 ( V_215 , V_213 ) ) )
V_215 = 0 ;
F_74 ( V_216 ) ;
if ( V_215 == V_219 . V_217 )
return V_190 ;
}
#undef F_70
return 0 ;
V_195:
return V_38 -> V_229 - V_38 -> V_214 ;
}
static int F_76 ( struct V_230 * V_231 )
{
int V_232 ;
V_232 = sizeof( struct V_233 ) ;
V_232 += F_77 ( strlen ( V_231 -> V_234 ) + 1 , 4 ) ;
V_232 += F_77 ( V_231 -> V_235 , 4 ) ;
return V_232 ;
}
static int F_78 ( struct V_81 * V_81 , T_8 * V_236 )
{
static const char V_160 [ 4 ] = { 0 , } ;
F_79 ( V_160 , F_77 ( * V_236 , 4 ) - * V_236 , V_236 ) ;
return 1 ;
}
static int F_80 ( struct V_230 * V_237 , struct V_81 * V_81 ,
T_8 * V_236 )
{
struct V_233 V_231 ;
V_231 . V_238 = strlen ( V_237 -> V_234 ) + 1 ;
V_231 . V_239 = V_237 -> V_235 ;
V_231 . V_240 = V_237 -> type ;
F_79 ( & V_231 , sizeof( V_231 ) , V_236 ) ;
F_79 ( V_237 -> V_234 , V_231 . V_238 , V_236 ) ;
if ( ! F_78 ( V_81 , V_236 ) )
return 0 ;
F_79 ( V_237 -> V_241 , V_237 -> V_235 , V_236 ) ;
if ( ! F_78 ( V_81 , V_236 ) )
return 0 ;
return 1 ;
}
static void F_81 ( struct V_15 * V_242 , int V_243 ,
T_9 V_244 , T_6 V_136 )
{
memset ( V_242 , 0 , sizeof( * V_242 ) ) ;
memcpy ( V_242 -> V_162 , V_163 , V_164 ) ;
V_242 -> V_162 [ V_245 ] = V_246 ;
V_242 -> V_162 [ V_247 ] = V_248 ;
V_242 -> V_162 [ V_249 ] = V_250 ;
V_242 -> V_162 [ V_251 ] = V_252 ;
V_242 -> V_108 = V_253 ;
V_242 -> V_254 = V_244 ;
V_242 -> V_255 = V_250 ;
V_242 -> V_48 = sizeof( struct V_15 ) ;
V_242 -> V_256 = V_136 ;
V_242 -> V_257 = sizeof( struct V_15 ) ;
V_242 -> V_114 = sizeof( struct V_50 ) ;
V_242 -> V_52 = V_243 ;
return;
}
static void F_82 ( struct V_50 * V_258 , int V_232 , T_8 V_259 )
{
V_258 -> V_97 = V_260 ;
V_258 -> V_91 = V_259 ;
V_258 -> V_89 = 0 ;
V_258 -> V_261 = 0 ;
V_258 -> V_88 = V_232 ;
V_258 -> V_99 = 0 ;
V_258 -> V_124 = 0 ;
V_258 -> V_262 = 0 ;
return;
}
static void F_83 ( struct V_230 * V_263 , const char * V_234 , int type ,
unsigned int V_232 , void * V_241 )
{
V_263 -> V_234 = V_234 ;
V_263 -> type = type ;
V_263 -> V_235 = V_232 ;
V_263 -> V_241 = V_241 ;
return;
}
static void F_84 ( struct V_264 * V_265 ,
struct V_266 * V_19 , long V_267 )
{
V_265 -> V_268 . V_269 = V_265 -> V_270 = V_267 ;
V_265 -> V_271 = V_19 -> V_272 . signal . V_273 [ 0 ] ;
V_265 -> V_274 = V_19 -> V_275 . V_273 [ 0 ] ;
F_85 () ;
V_265 -> V_276 = F_86 ( F_87 ( V_19 -> V_277 ) ) ;
F_88 () ;
V_265 -> V_278 = F_86 ( V_19 ) ;
V_265 -> V_279 = F_89 ( V_19 ) ;
V_265 -> V_280 = F_90 ( V_19 ) ;
if ( F_91 ( V_19 ) ) {
struct V_281 V_282 ;
F_92 ( V_19 , & V_282 ) ;
F_93 ( V_282 . V_283 , & V_265 -> V_284 ) ;
F_93 ( V_282 . V_285 , & V_265 -> V_286 ) ;
} else {
T_10 V_283 , V_285 ;
V_281 ( V_19 , & V_283 , & V_285 ) ;
F_93 ( V_283 , & V_265 -> V_284 ) ;
F_93 ( V_285 , & V_265 -> V_286 ) ;
}
F_93 ( V_19 -> signal -> V_287 , & V_265 -> V_288 ) ;
F_93 ( V_19 -> signal -> V_289 , & V_265 -> V_290 ) ;
}
static int F_94 ( struct V_291 * V_292 , struct V_266 * V_19 ,
struct V_293 * V_5 )
{
const struct V_36 * V_36 ;
unsigned int V_94 , V_39 ;
memset ( V_292 , 0 , sizeof( struct V_291 ) ) ;
V_39 = V_5 -> V_75 - V_5 -> V_76 ;
if ( V_39 >= V_294 )
V_39 = V_294 - 1 ;
if ( F_95 ( & V_292 -> V_295 ,
( const char V_11 * ) V_5 -> V_76 , V_39 ) )
return - V_12 ;
for( V_94 = 0 ; V_94 < V_39 ; V_94 ++ )
if ( V_292 -> V_295 [ V_94 ] == 0 )
V_292 -> V_295 [ V_94 ] = ' ' ;
V_292 -> V_295 [ V_39 ] = 0 ;
F_85 () ;
V_292 -> V_276 = F_86 ( F_87 ( V_19 -> V_277 ) ) ;
F_88 () ;
V_292 -> V_278 = F_86 ( V_19 ) ;
V_292 -> V_279 = F_89 ( V_19 ) ;
V_292 -> V_280 = F_90 ( V_19 ) ;
V_94 = V_19 -> V_296 ? F_96 ( ~ V_19 -> V_296 ) + 1 : 0 ;
V_292 -> V_297 = V_94 ;
V_292 -> V_298 = ( V_94 > 5 ) ? '.' : L_1 [ V_94 ] ;
V_292 -> V_299 = V_292 -> V_298 == 'Z' ;
V_292 -> V_300 = F_97 ( V_19 ) ;
V_292 -> V_301 = V_19 -> V_136 ;
F_85 () ;
V_36 = F_98 ( V_19 ) ;
F_99 ( V_292 -> V_302 , F_16 ( V_36 -> V_58 , V_36 -> V_59 ) ) ;
F_100 ( V_292 -> V_303 , F_17 ( V_36 -> V_58 , V_36 -> V_63 ) ) ;
F_88 () ;
strncpy ( V_292 -> V_304 , V_19 -> V_305 , sizeof( V_292 -> V_304 ) ) ;
return 0 ;
}
static void F_101 ( struct V_230 * V_263 , struct V_293 * V_5 )
{
T_1 * V_306 = ( T_1 * ) V_5 -> V_40 ;
int V_94 = 0 ;
do
V_94 += 2 ;
while ( V_306 [ V_94 - 2 ] != V_307 );
F_83 ( V_263 , L_2 , V_308 , V_94 * sizeof( T_1 ) , V_306 ) ;
}
static void F_102 ( struct V_230 * V_263 , T_11 * V_309 ,
T_12 * V_310 )
{
T_7 V_311 = F_72 () ;
F_74 ( V_312 ) ;
F_103 ( ( T_11 V_11 * ) V_309 , V_310 ) ;
F_74 ( V_311 ) ;
F_83 ( V_263 , L_2 , V_313 , sizeof( * V_309 ) , V_309 ) ;
}
static void F_104 ( struct V_230 * V_263 )
{
struct V_37 * V_38 ;
unsigned V_314 , V_87 , V_315 , V_316 , V_317 ;
T_13 * V_241 ;
T_13 * V_318 ;
char * V_319 , * V_320 ;
V_314 = V_4 -> V_5 -> V_321 ;
V_87 = V_314 * 64 ;
V_315 = ( 2 + 3 * V_314 ) * sizeof( V_241 [ 0 ] ) ;
V_322:
if ( V_87 >= V_323 )
goto V_324;
V_87 = F_105 ( V_87 , V_190 ) ;
V_241 = F_106 ( V_87 ) ;
if ( ! V_241 )
goto V_324;
V_318 = V_241 + 2 ;
V_319 = V_320 = ( ( char * ) V_241 ) + V_315 ;
V_316 = V_87 - V_315 ;
V_314 = 0 ;
for ( V_38 = V_4 -> V_5 -> V_113 ; V_38 != NULL ; V_38 = V_38 -> V_325 ) {
struct V_81 * V_81 ;
const char * V_326 ;
V_81 = V_38 -> V_203 ;
if ( ! V_81 )
continue;
V_326 = F_107 ( & V_81 -> V_327 , V_320 , V_316 ) ;
if ( F_43 ( V_326 ) ) {
if ( F_42 ( V_326 ) == - V_328 ) {
F_108 ( V_241 ) ;
V_87 = V_87 * 5 / 4 ;
goto V_322;
}
continue;
}
V_317 = ( V_320 + V_316 ) - V_326 ;
V_316 = V_326 - V_320 ;
memmove ( V_320 , V_326 , V_317 ) ;
V_320 += V_317 ;
* V_318 ++ = V_38 -> V_214 ;
* V_318 ++ = V_38 -> V_229 ;
* V_318 ++ = V_38 -> V_211 ;
V_314 ++ ;
}
V_241 [ 0 ] = V_314 ;
V_241 [ 1 ] = V_190 ;
V_317 = V_4 -> V_5 -> V_321 - V_314 ;
if ( V_317 != 0 ) {
unsigned V_329 = V_317 * 3 * sizeof( V_241 [ 0 ] ) ;
memmove ( V_319 - V_329 , V_319 ,
V_320 - V_319 ) ;
V_320 -= V_329 ;
}
V_87 = V_320 - ( char * ) V_241 ;
F_83 ( V_263 , L_2 , V_330 , V_87 , V_241 ) ;
V_324: ;
}
static void F_109 ( struct V_266 * V_331 ,
const struct V_332 * V_333 )
{
if ( V_333 -> V_334 )
V_333 -> V_334 ( V_331 , V_333 , 1 ) ;
}
static int F_110 ( struct V_335 * V_336 ,
const struct V_337 * V_338 ,
long V_267 , T_2 * V_339 )
{
unsigned int V_94 ;
F_84 ( & V_336 -> V_265 , V_336 -> V_331 , V_267 ) ;
( void ) V_338 -> V_340 [ 0 ] . F_111 ( V_336 -> V_331 , & V_338 -> V_340 [ 0 ] ,
0 , F_112 ( V_336 -> V_265 . V_341 ) ,
F_113 ( & V_336 -> V_265 ) , NULL ) ;
F_83 ( & V_336 -> V_342 [ 0 ] , L_2 , V_343 ,
F_114 ( V_336 -> V_265 ) , & V_336 -> V_265 ) ;
* V_339 += F_76 ( & V_336 -> V_342 [ 0 ] ) ;
F_109 ( V_336 -> V_331 , & V_338 -> V_340 [ 0 ] ) ;
for ( V_94 = 1 ; V_94 < V_338 -> V_317 ; ++ V_94 ) {
const struct V_332 * V_333 = & V_338 -> V_340 [ V_94 ] ;
F_109 ( V_336 -> V_331 , V_333 ) ;
if ( V_333 -> V_344 && V_333 -> F_111 &&
( ! V_333 -> V_345 || V_333 -> V_345 ( V_336 -> V_331 , V_333 ) ) ) {
int V_346 ;
T_2 V_87 = V_333 -> V_317 * V_333 -> V_87 ;
void * V_241 = F_33 ( V_87 , V_115 ) ;
if ( F_51 ( ! V_241 ) )
return 0 ;
V_346 = V_333 -> F_111 ( V_336 -> V_331 , V_333 ,
0 , V_87 , V_241 , NULL ) ;
if ( F_51 ( V_346 ) )
F_35 ( V_241 ) ;
else {
if ( V_333 -> V_344 != V_347 )
F_83 ( & V_336 -> V_342 [ V_94 ] , L_3 ,
V_333 -> V_344 ,
V_87 , V_241 ) ;
else {
F_115 ( & V_336 -> V_265 , 1 ) ;
F_83 ( & V_336 -> V_342 [ V_94 ] , L_2 ,
V_347 , V_87 , V_241 ) ;
}
* V_339 += F_76 ( & V_336 -> V_342 [ V_94 ] ) ;
}
}
}
return 1 ;
}
static int F_116 ( struct V_15 * V_242 , int V_348 ,
struct V_349 * V_350 ,
T_12 * V_310 , struct V_155 * V_156 )
{
struct V_266 * V_351 = V_4 ;
const struct V_337 * V_338 = F_117 ( V_351 ) ;
struct V_335 * V_336 ;
struct V_291 * V_292 ;
struct V_352 * V_353 ;
unsigned int V_94 ;
V_350 -> V_87 = 0 ;
V_350 -> V_354 = NULL ;
V_292 = F_33 ( sizeof( * V_292 ) , V_115 ) ;
if ( V_292 == NULL ) {
V_350 -> V_292 . V_241 = NULL ;
return 0 ;
}
F_83 ( & V_350 -> V_292 , L_2 , V_355 , sizeof( * V_292 ) , V_292 ) ;
V_350 -> V_356 = 0 ;
for ( V_94 = 0 ; V_94 < V_338 -> V_317 ; ++ V_94 )
if ( V_338 -> V_340 [ V_94 ] . V_344 != 0 )
++ V_350 -> V_356 ;
if ( F_51 ( V_350 -> V_356 == 0 ) ||
F_51 ( V_338 -> V_340 [ 0 ] . V_344 != V_343 ) ) {
F_118 ( 1 ) ;
return 0 ;
}
F_81 ( V_242 , V_348 ,
V_338 -> V_254 , V_338 -> V_256 ) ;
for ( V_353 = & V_351 -> V_5 -> V_357 -> V_358 ; V_353 ; V_353 = V_353 -> V_359 ) {
V_336 = F_119 ( F_120 ( struct V_335 ,
V_342 [ V_350 -> V_356 ] ) ,
V_115 ) ;
if ( F_51 ( ! V_336 ) )
return 0 ;
V_336 -> V_331 = V_353 -> V_331 ;
if ( V_353 -> V_331 == V_351 || ! V_350 -> V_354 ) {
V_336 -> V_359 = V_350 -> V_354 ;
V_350 -> V_354 = V_336 ;
} else {
V_336 -> V_359 = V_350 -> V_354 -> V_359 ;
V_350 -> V_354 -> V_359 = V_336 ;
}
}
for ( V_336 = V_350 -> V_354 ; V_336 != NULL ; V_336 = V_336 -> V_359 )
if ( ! F_110 ( V_336 , V_338 , V_310 -> V_269 , & V_350 -> V_87 ) )
return 0 ;
F_94 ( V_292 , V_351 -> V_360 , V_351 -> V_5 ) ;
V_350 -> V_87 += F_76 ( & V_350 -> V_292 ) ;
F_102 ( & V_350 -> V_361 , & V_350 -> V_309 , V_310 ) ;
V_350 -> V_87 += F_76 ( & V_350 -> V_361 ) ;
F_101 ( & V_350 -> V_306 , V_4 -> V_5 ) ;
V_350 -> V_87 += F_76 ( & V_350 -> V_306 ) ;
F_104 ( & V_350 -> V_362 ) ;
V_350 -> V_87 += F_76 ( & V_350 -> V_362 ) ;
return 1 ;
}
static T_2 F_121 ( struct V_349 * V_350 )
{
return V_350 -> V_87 ;
}
static int F_122 ( struct V_349 * V_350 ,
struct V_81 * V_81 , T_8 * V_236 )
{
bool V_363 = 1 ;
struct V_335 * V_336 = V_350 -> V_354 ;
do {
int V_94 ;
if ( ! F_80 ( & V_336 -> V_342 [ 0 ] , V_81 , V_236 ) )
return 0 ;
if ( V_363 && ! F_80 ( & V_350 -> V_292 , V_81 , V_236 ) )
return 0 ;
if ( V_363 && ! F_80 ( & V_350 -> V_361 , V_81 , V_236 ) )
return 0 ;
if ( V_363 && ! F_80 ( & V_350 -> V_306 , V_81 , V_236 ) )
return 0 ;
if ( V_363 && ! F_80 ( & V_350 -> V_362 , V_81 , V_236 ) )
return 0 ;
for ( V_94 = 1 ; V_94 < V_350 -> V_356 ; ++ V_94 )
if ( V_336 -> V_342 [ V_94 ] . V_241 &&
! F_80 ( & V_336 -> V_342 [ V_94 ] , V_81 , V_236 ) )
return 0 ;
V_363 = 0 ;
V_336 = V_336 -> V_359 ;
} while ( V_336 );
return 1 ;
}
static void F_123 ( struct V_349 * V_350 )
{
struct V_335 * V_364 = V_350 -> V_354 ;
while ( V_364 ) {
unsigned int V_94 ;
struct V_335 * V_336 = V_364 ;
V_364 = V_336 -> V_359 ;
F_118 ( V_336 -> V_342 [ 0 ] . V_241 && V_336 -> V_342 [ 0 ] . V_241 != & V_336 -> V_265 ) ;
for ( V_94 = 1 ; V_94 < V_350 -> V_356 ; ++ V_94 )
F_35 ( V_336 -> V_342 [ V_94 ] . V_241 ) ;
F_35 ( V_336 ) ;
}
F_35 ( V_350 -> V_292 . V_241 ) ;
F_108 ( V_350 -> V_362 . V_241 ) ;
}
static int F_124 ( long V_267 , struct V_365 * V_336 )
{
int V_232 = 0 ;
struct V_266 * V_19 = V_336 -> V_354 ;
V_336 -> V_366 = 0 ;
F_84 ( & V_336 -> V_265 , V_19 , V_267 ) ;
F_125 ( V_19 , & V_336 -> V_265 . V_341 ) ;
F_83 ( & V_336 -> V_342 [ 0 ] , L_2 , V_343 , sizeof( V_336 -> V_265 ) ,
& ( V_336 -> V_265 ) ) ;
V_336 -> V_366 ++ ;
V_232 += F_76 ( & V_336 -> V_342 [ 0 ] ) ;
if ( ( V_336 -> V_265 . V_367 = F_126 ( V_19 , NULL ,
& V_336 -> V_368 ) ) ) {
F_83 ( & V_336 -> V_342 [ 1 ] , L_2 , V_347 , sizeof( V_336 -> V_368 ) ,
& ( V_336 -> V_368 ) ) ;
V_336 -> V_366 ++ ;
V_232 += F_76 ( & V_336 -> V_342 [ 1 ] ) ;
}
#ifdef F_127
if ( F_128 ( V_19 , & V_336 -> V_369 ) ) {
F_83 ( & V_336 -> V_342 [ 2 ] , L_3 , V_370 ,
sizeof( V_336 -> V_369 ) , & V_336 -> V_369 ) ;
V_336 -> V_366 ++ ;
V_232 += F_76 ( & V_336 -> V_342 [ 2 ] ) ;
}
#endif
return V_232 ;
}
static int F_129 ( struct V_349 * V_350 )
{
memset ( V_350 , 0 , sizeof( * V_350 ) ) ;
F_130 ( & V_350 -> V_371 ) ;
V_350 -> V_342 = F_33 ( 8 * sizeof( struct V_230 ) , V_115 ) ;
if ( ! V_350 -> V_342 )
return 0 ;
V_350 -> V_292 = F_33 ( sizeof( * V_350 -> V_292 ) , V_115 ) ;
if ( ! V_350 -> V_292 )
return 0 ;
V_350 -> V_265 = F_33 ( sizeof( * V_350 -> V_265 ) , V_115 ) ;
if ( ! V_350 -> V_265 )
return 0 ;
V_350 -> V_368 = F_33 ( sizeof( * V_350 -> V_368 ) , V_115 ) ;
if ( ! V_350 -> V_368 )
return 0 ;
#ifdef F_127
V_350 -> V_369 = F_33 ( sizeof( * V_350 -> V_369 ) , V_115 ) ;
if ( ! V_350 -> V_369 )
return 0 ;
#endif
return 1 ;
}
static int F_116 ( struct V_15 * V_242 , int V_348 ,
struct V_349 * V_350 ,
T_12 * V_310 , struct V_155 * V_156 )
{
struct V_372 * V_336 ;
if ( ! F_129 ( V_350 ) )
return 0 ;
if ( V_310 -> V_269 ) {
struct V_352 * V_353 ;
struct V_365 * V_373 ;
for ( V_353 = V_4 -> V_5 -> V_357 -> V_358 . V_359 ;
V_353 ; V_353 = V_353 -> V_359 ) {
V_373 = F_119 ( sizeof( * V_373 ) , V_115 ) ;
if ( ! V_373 )
return 0 ;
V_373 -> V_354 = V_353 -> V_331 ;
F_131 ( & V_373 -> V_374 , & V_350 -> V_371 ) ;
}
F_132 (t, &info->thread_list) {
int V_232 ;
V_373 = F_133 ( V_336 , struct V_365 , V_374 ) ;
V_232 = F_124 ( V_310 -> V_269 , V_373 ) ;
V_350 -> V_375 += V_232 ;
}
}
memset ( V_350 -> V_265 , 0 , sizeof( * V_350 -> V_265 ) ) ;
F_84 ( V_350 -> V_265 , V_4 , V_310 -> V_269 ) ;
F_134 ( & V_350 -> V_265 -> V_341 , V_156 ) ;
F_81 ( V_242 , V_348 , V_376 , V_377 ) ;
F_83 ( V_350 -> V_342 + 0 , L_2 , V_343 ,
sizeof( * V_350 -> V_265 ) , V_350 -> V_265 ) ;
F_94 ( V_350 -> V_292 , V_4 -> V_360 , V_4 -> V_5 ) ;
F_83 ( V_350 -> V_342 + 1 , L_2 , V_355 ,
sizeof( * V_350 -> V_292 ) , V_350 -> V_292 ) ;
F_102 ( V_350 -> V_342 + 2 , & V_350 -> V_309 , V_310 ) ;
F_101 ( V_350 -> V_342 + 3 , V_4 -> V_5 ) ;
F_104 ( V_350 -> V_342 + 4 ) ;
V_350 -> V_378 = 5 ;
V_350 -> V_265 -> V_367 = F_126 ( V_4 , V_156 ,
V_350 -> V_368 ) ;
if ( V_350 -> V_265 -> V_367 )
F_83 ( V_350 -> V_342 + V_350 -> V_378 ++ ,
L_2 , V_347 , sizeof( * V_350 -> V_368 ) , V_350 -> V_368 ) ;
#ifdef F_127
if ( F_128 ( V_4 , V_350 -> V_369 ) )
F_83 ( V_350 -> V_342 + V_350 -> V_378 ++ ,
L_3 , V_370 ,
sizeof( * V_350 -> V_369 ) , V_350 -> V_369 ) ;
#endif
return 1 ;
}
static T_2 F_121 ( struct V_349 * V_350 )
{
int V_232 = 0 ;
int V_94 ;
for ( V_94 = 0 ; V_94 < V_350 -> V_378 ; V_94 ++ )
V_232 += F_76 ( V_350 -> V_342 + V_94 ) ;
V_232 += V_350 -> V_375 ;
return V_232 ;
}
static int F_122 ( struct V_349 * V_350 ,
struct V_81 * V_81 , T_8 * V_236 )
{
int V_94 ;
struct V_372 * V_336 ;
for ( V_94 = 0 ; V_94 < V_350 -> V_378 ; V_94 ++ )
if ( ! F_80 ( V_350 -> V_342 + V_94 , V_81 , V_236 ) )
return 0 ;
F_132 (t, &info->thread_list) {
struct V_365 * V_379 =
F_133 ( V_336 , struct V_365 , V_374 ) ;
for ( V_94 = 0 ; V_94 < V_379 -> V_366 ; V_94 ++ )
if ( ! F_80 ( & V_379 -> V_342 [ V_94 ] , V_81 , V_236 ) )
return 0 ;
}
return 1 ;
}
static void F_123 ( struct V_349 * V_350 )
{
while ( ! F_135 ( & V_350 -> V_371 ) ) {
struct V_372 * V_379 = V_350 -> V_371 . V_359 ;
F_136 ( V_379 ) ;
F_35 ( F_133 ( V_379 , struct V_365 , V_374 ) ) ;
}
F_108 ( V_350 -> V_342 [ 4 ] . V_241 ) ;
F_35 ( V_350 -> V_265 ) ;
F_35 ( V_350 -> V_292 ) ;
F_35 ( V_350 -> V_342 ) ;
F_35 ( V_350 -> V_368 ) ;
#ifdef F_127
F_35 ( V_350 -> V_369 ) ;
#endif
}
static struct V_37 * F_137 ( struct V_266 * V_380 ,
struct V_37 * V_381 )
{
struct V_37 * V_346 = V_380 -> V_5 -> V_113 ;
if ( V_346 )
return V_346 ;
return V_381 ;
}
static struct V_37 * F_138 ( struct V_37 * V_382 ,
struct V_37 * V_381 )
{
struct V_37 * V_346 ;
V_346 = V_382 -> V_325 ;
if ( V_346 )
return V_346 ;
if ( V_382 == V_381 )
return NULL ;
return V_381 ;
}
static void F_139 ( struct V_15 * V_242 , struct V_383 * V_384 ,
T_1 V_385 , int V_243 )
{
V_242 -> V_385 = V_385 ;
V_242 -> V_386 = sizeof( * V_384 ) ;
V_242 -> V_387 = 1 ;
V_242 -> V_388 = V_389 ;
memset ( V_384 , 0 , sizeof( * V_384 ) ) ;
V_384 -> V_390 = V_391 ;
V_384 -> V_392 = V_242 -> V_387 ;
V_384 -> V_393 = V_242 -> V_388 ;
V_384 -> V_394 = V_243 ;
}
static T_2 F_140 ( struct V_37 * V_381 ,
unsigned long V_194 )
{
struct V_37 * V_38 ;
T_2 V_87 = 0 ;
for ( V_38 = F_137 ( V_4 , V_381 ) ; V_38 != NULL ;
V_38 = F_138 ( V_38 , V_381 ) )
V_87 += F_69 ( V_38 , V_194 ) ;
return V_87 ;
}
static int F_141 ( struct V_395 * V_396 )
{
int V_397 = 0 ;
T_7 V_216 ;
int V_243 ;
T_2 V_87 = 0 ;
struct V_37 * V_38 , * V_381 ;
struct V_15 * V_242 = NULL ;
T_8 V_259 = 0 , V_398 , V_236 ;
struct V_349 V_350 ;
struct V_50 * V_399 = NULL ;
struct V_383 * V_384 = NULL ;
T_14 V_52 ;
T_1 V_385 ;
V_242 = F_33 ( sizeof( * V_242 ) , V_115 ) ;
if ( ! V_242 )
goto V_111;
V_243 = V_4 -> V_5 -> V_321 ;
V_243 += F_142 () ;
V_381 = F_67 ( V_4 -> V_5 ) ;
if ( V_381 != NULL )
V_243 ++ ;
V_243 ++ ;
V_52 = V_243 > V_400 ? V_400 : V_243 ;
if ( ! F_116 ( V_242 , V_52 , & V_350 , V_396 -> V_310 , V_396 -> V_156 ) )
goto V_401;
V_397 = 1 ;
V_4 -> V_136 |= V_402 ;
V_216 = F_72 () ;
F_74 ( V_312 ) ;
V_259 += sizeof( * V_242 ) ;
V_259 += V_243 * sizeof( struct V_50 ) ;
V_236 = V_259 ;
{
T_2 V_232 = F_121 ( & V_350 ) ;
V_232 += F_143 () ;
V_399 = F_33 ( sizeof( * V_399 ) , V_115 ) ;
if ( ! V_399 )
goto V_403;
F_82 ( V_399 , V_232 , V_259 ) ;
V_259 += V_232 ;
}
V_398 = V_259 = F_77 ( V_259 , V_44 ) ;
V_259 += F_140 ( V_381 , V_396 -> V_194 ) ;
V_259 += F_144 () ;
V_385 = V_259 ;
if ( V_52 == V_400 ) {
V_384 = F_33 ( sizeof( * V_384 ) , V_115 ) ;
if ( ! V_384 )
goto V_403;
F_139 ( V_242 , V_384 , V_385 , V_243 ) ;
}
V_259 = V_398 ;
V_87 += sizeof( * V_242 ) ;
if ( V_87 > V_396 -> V_404 || ! F_145 ( V_396 -> V_81 , V_242 , sizeof( * V_242 ) ) )
goto V_403;
V_87 += sizeof( * V_399 ) ;
if ( V_87 > V_396 -> V_404
|| ! F_145 ( V_396 -> V_81 , V_399 , sizeof( * V_399 ) ) )
goto V_403;
for ( V_38 = F_137 ( V_4 , V_381 ) ; V_38 != NULL ;
V_38 = F_138 ( V_38 , V_381 ) ) {
struct V_50 V_258 ;
V_258 . V_97 = V_98 ;
V_258 . V_91 = V_259 ;
V_258 . V_89 = V_38 -> V_214 ;
V_258 . V_261 = 0 ;
V_258 . V_88 = F_69 ( V_38 , V_396 -> V_194 ) ;
V_258 . V_99 = V_38 -> V_229 - V_38 -> V_214 ;
V_259 += V_258 . V_88 ;
V_258 . V_124 = V_38 -> V_196 & V_212 ? V_125 : 0 ;
if ( V_38 -> V_196 & V_405 )
V_258 . V_124 |= V_127 ;
if ( V_38 -> V_196 & V_406 )
V_258 . V_124 |= V_129 ;
V_258 . V_262 = V_44 ;
V_87 += sizeof( V_258 ) ;
if ( V_87 > V_396 -> V_404
|| ! F_145 ( V_396 -> V_81 , & V_258 , sizeof( V_258 ) ) )
goto V_403;
}
if ( ! F_146 ( V_396 -> V_81 , V_259 , & V_87 , V_396 -> V_404 ) )
goto V_403;
if ( ! F_122 ( & V_350 , V_396 -> V_81 , & V_236 ) )
goto V_403;
if ( F_147 ( V_396 -> V_81 , & V_236 ) )
goto V_403;
if ( ! F_148 ( V_396 -> V_81 , V_398 - V_236 ) )
goto V_403;
for ( V_38 = F_137 ( V_4 , V_381 ) ; V_38 != NULL ;
V_38 = F_138 ( V_38 , V_381 ) ) {
unsigned long V_3 ;
unsigned long V_2 ;
V_2 = V_38 -> V_214 + F_69 ( V_38 , V_396 -> V_194 ) ;
for ( V_3 = V_38 -> V_214 ; V_3 < V_2 ; V_3 += V_190 ) {
struct V_407 * V_407 ;
int V_408 ;
V_407 = F_149 ( V_3 ) ;
if ( V_407 ) {
void * V_409 = F_150 ( V_407 ) ;
V_408 = ( ( V_87 += V_190 ) > V_396 -> V_404 ) ||
! F_145 ( V_396 -> V_81 , V_409 ,
V_190 ) ;
F_151 ( V_407 ) ;
F_152 ( V_407 ) ;
} else
V_408 = ! F_148 ( V_396 -> V_81 , V_190 ) ;
if ( V_408 )
goto V_403;
}
}
if ( ! F_153 ( V_396 -> V_81 , & V_87 , V_396 -> V_404 ) )
goto V_403;
if ( V_52 == V_400 ) {
V_87 += sizeof( * V_384 ) ;
if ( V_87 > V_396 -> V_404
|| ! F_145 ( V_396 -> V_81 , V_384 ,
sizeof( * V_384 ) ) )
goto V_403;
}
V_403:
F_74 ( V_216 ) ;
V_401:
F_123 ( & V_350 ) ;
F_35 ( V_384 ) ;
F_35 ( V_399 ) ;
F_35 ( V_242 ) ;
V_111:
return V_397 ;
}
static int T_15 F_154 ( void )
{
F_155 ( & V_187 ) ;
return 0 ;
}
static void T_16 F_156 ( void )
{
F_157 ( & V_187 ) ;
}
