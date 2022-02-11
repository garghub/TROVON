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
F_14 ( V_57 , V_36 -> V_58 ) ;
F_14 ( V_59 , V_36 -> V_60 ) ;
F_14 ( V_61 , V_36 -> V_62 ) ;
F_14 ( V_63 , V_36 -> V_64 ) ;
F_14 ( V_65 , F_16 ( V_14 ) ) ;
F_14 ( V_66 , ( T_1 ) ( unsigned long ) V_27 ) ;
F_14 ( V_67 , V_14 -> V_16 ) ;
if ( V_28 ) {
F_14 ( V_68 ,
( T_1 ) ( unsigned long ) V_25 ) ;
}
if ( V_30 ) {
F_14 ( V_69 ,
( T_1 ) ( unsigned long ) V_26 ) ;
}
if ( V_14 -> V_70 & V_71 ) {
F_14 ( V_72 , V_14 -> V_73 ) ;
}
#undef F_14
memset ( & V_34 [ V_35 ] , 0 ,
sizeof V_4 -> V_5 -> V_40 - V_35 * sizeof V_34 [ 0 ] ) ;
V_35 += 2 ;
V_24 = F_17 ( V_19 , V_35 ) ;
V_33 = ( V_20 + 1 ) + ( V_21 + 1 ) + 1 ;
V_14 -> V_19 = F_18 ( V_24 , V_33 ) ;
#ifdef F_19
V_24 = ( T_1 V_11 * ) V_14 -> V_19 - V_33 - V_35 ;
V_14 -> V_16 = ( unsigned long ) V_24 ;
#else
V_24 = ( T_1 V_11 * ) V_14 -> V_19 ;
#endif
V_38 = F_20 ( V_4 -> V_5 , V_14 -> V_19 ) ;
if ( ! V_38 )
return - V_12 ;
if ( F_21 ( V_20 , V_24 ++ ) )
return - V_12 ;
V_22 = V_24 ;
V_23 = V_22 + V_20 + 1 ;
V_19 = V_4 -> V_5 -> V_74 = V_4 -> V_5 -> V_75 ;
while ( V_20 -- > 0 ) {
T_2 V_39 ;
if ( F_21 ( ( T_1 ) V_19 , V_22 ++ ) )
return - V_12 ;
V_39 = F_22 ( ( void V_11 * ) V_19 , V_76 ) ;
if ( ! V_39 || V_39 > V_76 )
return - V_77 ;
V_19 += V_39 ;
}
if ( F_21 ( 0 , V_22 ) )
return - V_12 ;
V_4 -> V_5 -> V_74 = V_4 -> V_5 -> V_78 = V_19 ;
while ( V_21 -- > 0 ) {
T_2 V_39 ;
if ( F_21 ( ( T_1 ) V_19 , V_23 ++ ) )
return - V_12 ;
V_39 = F_22 ( ( void V_11 * ) V_19 , V_76 ) ;
if ( ! V_39 || V_39 > V_76 )
return - V_77 ;
V_19 += V_39 ;
}
if ( F_21 ( 0 , V_23 ) )
return - V_12 ;
V_4 -> V_5 -> V_79 = V_19 ;
V_24 = ( T_1 V_11 * ) V_23 + 1 ;
if ( F_23 ( V_24 , V_34 , V_35 * sizeof( T_1 ) ) )
return - V_12 ;
return 0 ;
}
static unsigned long F_24 ( struct V_80 * V_81 , unsigned long V_3 ,
struct V_50 * V_82 , int V_83 , int type ,
unsigned long V_84 )
{
unsigned long V_85 ;
unsigned long V_86 = V_82 -> V_87 + F_6 ( V_82 -> V_88 ) ;
unsigned long V_89 = V_82 -> V_90 - F_6 ( V_82 -> V_88 ) ;
V_3 = F_25 ( V_3 ) ;
V_86 = F_2 ( V_86 ) ;
if ( ! V_86 )
return V_3 ;
F_26 ( & V_4 -> V_5 -> V_91 ) ;
if ( V_84 ) {
V_84 = F_2 ( V_84 ) ;
V_85 = F_27 ( V_81 , V_3 , V_84 , V_83 , type , V_89 ) ;
if ( ! F_4 ( V_85 ) )
F_28 ( V_4 -> V_5 , V_85 + V_86 , V_84 - V_86 ) ;
} else
V_85 = F_27 ( V_81 , V_3 , V_86 , V_83 , type , V_89 ) ;
F_29 ( & V_4 -> V_5 -> V_91 ) ;
return ( V_85 ) ;
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
return V_92 [ V_96 ] . V_88 + V_92 [ V_96 ] . V_99 -
F_25 ( V_92 [ V_95 ] . V_88 ) ;
}
static unsigned long F_31 ( struct V_15 * V_100 ,
struct V_80 * V_101 , unsigned long * V_102 ,
unsigned long V_103 )
{
struct V_50 * V_104 ;
struct V_50 * V_82 ;
unsigned long V_17 = 0 ;
int V_105 = 0 ;
unsigned long V_106 = 0 , V_8 = 0 ;
unsigned long error = ~ 0UL ;
unsigned long V_84 ;
int V_107 , V_94 , V_86 ;
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
V_86 = sizeof( struct V_50 ) * V_100 -> V_52 ;
if ( V_86 > V_10 )
goto V_111;
V_104 = F_33 ( V_86 , V_115 ) ;
if ( ! V_104 )
goto V_111;
V_107 = F_34 ( V_101 , V_100 -> V_48 ,
( char * ) V_104 , V_86 ) ;
error = - V_116 ;
if ( V_107 != V_86 ) {
if ( V_107 < 0 )
error = V_107 ;
goto V_117;
}
V_84 = F_30 ( V_104 , V_100 -> V_52 ) ;
if ( ! V_84 ) {
error = - V_77 ;
goto V_117;
}
V_82 = V_104 ;
for ( V_94 = 0 ; V_94 < V_100 -> V_52 ; V_94 ++ , V_82 ++ ) {
if ( V_82 -> V_97 == V_98 ) {
int V_118 = V_119 | V_120 ;
int V_121 = 0 ;
unsigned long V_122 = 0 ;
unsigned long V_123 , V_85 ;
if ( V_82 -> V_124 & V_125 )
V_121 = V_126 ;
if ( V_82 -> V_124 & V_127 )
V_121 |= V_128 ;
if ( V_82 -> V_124 & V_129 )
V_121 |= V_130 ;
V_122 = V_82 -> V_88 ;
if ( V_100 -> V_108 == V_109 || V_105 )
V_118 |= V_131 ;
else if ( V_103 && V_100 -> V_108 == V_110 )
V_17 = - V_122 ;
V_85 = F_24 ( V_101 , V_17 + V_122 ,
V_82 , V_121 , V_118 , V_84 ) ;
V_84 = 0 ;
if ( ! * V_102 )
* V_102 = V_85 ;
error = V_85 ;
if ( F_4 ( V_85 ) )
goto V_117;
if ( ! V_105 &&
V_100 -> V_108 == V_110 ) {
V_17 = V_85 - F_25 ( V_122 ) ;
V_105 = 1 ;
}
V_123 = V_17 + V_82 -> V_88 ;
if ( F_4 ( V_123 ) ||
V_82 -> V_87 > V_82 -> V_99 ||
V_82 -> V_99 > V_132 ||
V_132 - V_82 -> V_99 < V_123 ) {
error = - V_133 ;
goto V_117;
}
V_123 = V_17 + V_82 -> V_88 + V_82 -> V_87 ;
if ( V_123 > V_8 )
V_8 = V_123 ;
V_123 = V_17 + V_82 -> V_99 + V_82 -> V_88 ;
if ( V_123 > V_106 )
V_106 = V_123 ;
}
}
if ( V_106 > V_8 ) {
if ( F_5 ( V_8 ) ) {
error = - V_12 ;
goto V_117;
}
V_8 = F_25 ( V_8 + V_10 - 1 ) ;
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
#ifdef F_19
return F_38 ( V_134 ) + V_135 ;
#else
return F_38 ( V_134 ) - V_135 ;
#endif
}
static int F_39 ( struct V_13 * V_14 , struct V_142 * V_143 )
{
struct V_80 * V_101 = NULL ;
unsigned long V_17 = 0 , V_144 = 0 ;
int V_105 = 0 ;
char * V_145 = NULL ;
unsigned long error ;
struct V_50 * V_146 , * V_104 ;
unsigned long V_8 , V_147 ;
int V_107 , V_94 ;
unsigned int V_86 ;
unsigned long V_148 ;
unsigned long V_18 = 0 ;
unsigned long V_149 , V_150 , V_151 , V_152 ;
unsigned long T_5 V_153 = 0 ;
int V_154 = V_155 ;
unsigned long V_156 = 0 ;
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
if ( ! V_14 -> V_80 -> V_112 || ! V_14 -> V_80 -> V_112 -> V_113 )
goto V_111;
if ( V_158 -> V_157 . V_114 != sizeof( struct V_50 ) )
goto V_111;
if ( V_158 -> V_157 . V_52 < 1 ||
V_158 -> V_157 . V_52 > 65536U / sizeof( struct V_50 ) )
goto V_111;
V_86 = V_158 -> V_157 . V_52 * sizeof( struct V_50 ) ;
V_107 = - V_133 ;
V_104 = F_33 ( V_86 , V_115 ) ;
if ( ! V_104 )
goto V_111;
V_107 = F_34 ( V_14 -> V_80 , V_158 -> V_157 . V_48 ,
( char * ) V_104 , V_86 ) ;
if ( V_107 != V_86 ) {
if ( V_107 >= 0 )
V_107 = - V_116 ;
goto V_165;
}
V_146 = V_104 ;
V_8 = 0 ;
V_147 = 0 ;
V_149 = ~ 0UL ;
V_150 = 0 ;
V_151 = 0 ;
V_152 = 0 ;
for ( V_94 = 0 ; V_94 < V_158 -> V_157 . V_52 ; V_94 ++ ) {
if ( V_146 -> V_97 == V_166 ) {
V_107 = - V_161 ;
if ( V_146 -> V_87 > V_167 ||
V_146 -> V_87 < 2 )
goto V_165;
V_107 = - V_133 ;
V_145 = F_33 ( V_146 -> V_87 ,
V_115 ) ;
if ( ! V_145 )
goto V_165;
V_107 = F_34 ( V_14 -> V_80 , V_146 -> V_90 ,
V_145 ,
V_146 -> V_87 ) ;
if ( V_107 != V_146 -> V_87 ) {
if ( V_107 >= 0 )
V_107 = - V_116 ;
goto V_168;
}
V_107 = - V_161 ;
if ( V_145 [ V_146 -> V_87 - 1 ] != '\0' )
goto V_168;
V_101 = F_40 ( V_145 ) ;
V_107 = F_41 ( V_101 ) ;
if ( F_42 ( V_101 ) )
goto V_168;
F_43 ( V_14 , V_101 ) ;
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
V_146 ++ ;
}
V_146 = V_104 ;
for ( V_94 = 0 ; V_94 < V_158 -> V_157 . V_52 ; V_94 ++ , V_146 ++ )
if ( V_146 -> V_97 == V_171 ) {
if ( V_146 -> V_124 & V_129 )
V_154 = V_172 ;
else
V_154 = V_173 ;
break;
}
if ( V_145 ) {
V_107 = - V_174 ;
if ( memcmp ( V_158 -> V_100 . V_162 , V_163 , V_164 ) != 0 )
goto V_170;
if ( ! F_32 ( & V_158 -> V_100 ) )
goto V_170;
}
V_107 = F_44 ( V_14 ) ;
if ( V_107 )
goto V_170;
V_4 -> V_5 -> V_156 = V_156 ;
F_45 ( V_158 -> V_157 ) ;
if ( F_46 ( V_158 -> V_157 , V_154 ) )
V_4 -> V_138 |= V_175 ;
if ( ! ( V_4 -> V_138 & V_139 ) && V_176 )
V_4 -> V_136 |= V_137 ;
F_47 ( V_14 ) ;
V_4 -> V_5 -> V_177 = V_4 -> V_5 -> V_178 ;
V_4 -> V_5 -> V_179 = 0 ;
V_107 = F_48 ( V_14 , F_36 ( V_180 ) ,
V_154 ) ;
if ( V_107 < 0 ) {
F_49 ( V_181 , V_4 , 0 ) ;
goto V_170;
}
V_4 -> V_5 -> V_182 = V_14 -> V_19 ;
for( V_94 = 0 , V_146 = V_104 ;
V_94 < V_158 -> V_157 . V_52 ; V_94 ++ , V_146 ++ ) {
int V_121 = 0 , V_183 ;
unsigned long V_123 , V_122 ;
if ( V_146 -> V_97 != V_98 )
continue;
if ( F_50 ( V_147 > V_8 ) ) {
unsigned long V_9 ;
V_107 = F_1 ( V_8 + V_144 ,
V_147 + V_144 ) ;
if ( V_107 ) {
F_49 ( V_181 , V_4 , 0 ) ;
goto V_170;
}
V_9 = F_6 ( V_8 ) ;
if ( V_9 ) {
V_9 = V_10 - V_9 ;
if ( V_9 > V_147 - V_8 )
V_9 = V_147 - V_8 ;
if ( F_7 ( ( void V_11 * ) V_8 +
V_144 , V_9 ) ) {
}
}
}
if ( V_146 -> V_124 & V_125 )
V_121 |= V_126 ;
if ( V_146 -> V_124 & V_127 )
V_121 |= V_128 ;
if ( V_146 -> V_124 & V_129 )
V_121 |= V_130 ;
V_183 = V_119 | V_120 | V_184 ;
V_122 = V_146 -> V_88 ;
if ( V_158 -> V_157 . V_108 == V_109 || V_105 ) {
V_183 |= V_131 ;
} else if ( V_158 -> V_157 . V_108 == V_110 ) {
#ifdef F_51
if ( V_4 -> V_136 & V_137 )
V_144 = 0 ;
else
V_144 = F_25 ( V_185 - V_122 ) ;
#else
V_144 = F_25 ( V_185 - V_122 ) ;
#endif
}
error = F_24 ( V_14 -> V_80 , V_144 + V_122 , V_146 ,
V_121 , V_183 , 0 ) ;
if ( F_4 ( error ) ) {
F_49 ( V_181 , V_4 , 0 ) ;
V_107 = F_42 ( ( void * ) error ) ?
F_41 ( ( void * ) error ) : - V_77 ;
goto V_170;
}
if ( ! V_105 ) {
V_105 = 1 ;
V_17 = ( V_146 -> V_88 - V_146 -> V_90 ) ;
if ( V_158 -> V_157 . V_108 == V_110 ) {
V_144 += error -
F_25 ( V_144 + V_122 ) ;
V_17 += V_144 ;
T_5 = V_144 ;
}
}
V_123 = V_146 -> V_88 ;
if ( V_123 < V_149 )
V_149 = V_123 ;
if ( V_151 < V_123 )
V_151 = V_123 ;
if ( F_4 ( V_123 ) || V_146 -> V_87 > V_146 -> V_99 ||
V_146 -> V_99 > V_132 ||
V_132 - V_146 -> V_99 < V_123 ) {
F_49 ( V_181 , V_4 , 0 ) ;
V_107 = - V_77 ;
goto V_170;
}
V_123 = V_146 -> V_88 + V_146 -> V_87 ;
if ( V_123 > V_8 )
V_8 = V_123 ;
if ( ( V_146 -> V_124 & V_129 ) && V_150 < V_123 )
V_150 = V_123 ;
if ( V_152 < V_123 )
V_152 = V_123 ;
V_123 = V_146 -> V_88 + V_146 -> V_99 ;
if ( V_123 > V_147 )
V_147 = V_123 ;
}
V_158 -> V_157 . V_56 += V_144 ;
V_8 += V_144 ;
V_147 += V_144 ;
V_149 += V_144 ;
V_150 += V_144 ;
V_151 += V_144 ;
V_152 += V_144 ;
V_107 = F_1 ( V_8 , V_147 ) ;
if ( V_107 ) {
F_49 ( V_181 , V_4 , 0 ) ;
goto V_170;
}
if ( F_52 ( V_8 != V_147 ) && F_50 ( F_5 ( V_8 ) ) ) {
F_49 ( V_186 , V_4 , 0 ) ;
V_107 = - V_12 ;
goto V_170;
}
if ( V_145 ) {
unsigned long V_187 ( V_102 ) ;
V_148 = F_31 ( & V_158 -> V_100 ,
V_101 ,
& V_102 ,
V_144 ) ;
if ( ! F_42 ( ( void * ) V_148 ) ) {
V_18 = V_148 ;
V_148 += V_158 -> V_100 . V_56 ;
}
if ( F_4 ( V_148 ) ) {
F_53 ( V_186 , V_4 ) ;
V_107 = F_42 ( ( void * ) V_148 ) ?
( int ) V_148 : - V_77 ;
goto V_170;
}
T_5 = V_18 ;
F_54 ( V_101 ) ;
F_55 ( V_101 ) ;
F_35 ( V_145 ) ;
} else {
V_148 = V_158 -> V_157 . V_56 ;
if ( F_4 ( V_148 ) ) {
F_53 ( V_186 , V_4 ) ;
V_107 = - V_77 ;
goto V_170;
}
}
F_35 ( V_104 ) ;
F_56 ( & V_188 ) ;
#ifdef F_57
V_107 = F_58 ( V_14 , ! ! V_145 ) ;
if ( V_107 < 0 ) {
F_49 ( V_181 , V_4 , 0 ) ;
goto V_111;
}
#endif
F_59 ( V_14 ) ;
V_107 = F_8 ( V_14 , & V_158 -> V_157 ,
V_17 , V_18 ) ;
if ( V_107 < 0 ) {
F_49 ( V_181 , V_4 , 0 ) ;
goto V_111;
}
V_4 -> V_5 -> V_150 = V_150 ;
V_4 -> V_5 -> V_149 = V_149 ;
V_4 -> V_5 -> V_151 = V_151 ;
V_4 -> V_5 -> V_152 = V_152 ;
V_4 -> V_5 -> V_182 = V_14 -> V_19 ;
#ifdef F_60
if ( ( V_4 -> V_136 & V_137 ) && ( V_176 > 1 ) ) {
V_4 -> V_5 -> V_7 = V_4 -> V_5 -> V_6 =
F_60 ( V_4 -> V_5 ) ;
#ifdef F_61
V_4 -> V_189 = 1 ;
#endif
}
#endif
if ( V_4 -> V_138 & V_190 ) {
error = F_62 ( NULL , 0 , V_191 , V_126 | V_130 ,
V_131 | V_119 , 0 ) ;
}
#ifdef F_63
F_63 ( V_143 , T_5 ) ;
#endif
F_64 ( V_143 , V_148 , V_14 -> V_19 ) ;
V_107 = 0 ;
V_111:
F_35 ( V_158 ) ;
V_159:
return V_107 ;
V_170:
F_54 ( V_101 ) ;
if ( V_101 )
F_55 ( V_101 ) ;
V_168:
F_35 ( V_145 ) ;
V_165:
F_35 ( V_104 ) ;
goto V_111;
}
static int F_65 ( struct V_80 * V_80 )
{
struct V_50 * V_104 ;
struct V_50 * V_82 ;
unsigned long V_8 , V_192 , V_39 ;
int V_107 , error , V_94 , V_193 ;
struct V_15 V_157 ;
error = - V_161 ;
V_107 = F_34 ( V_80 , 0 , ( char * ) & V_157 , sizeof( V_157 ) ) ;
if ( V_107 != sizeof( V_157 ) )
goto V_111;
if ( memcmp ( V_157 . V_162 , V_163 , V_164 ) != 0 )
goto V_111;
if ( V_157 . V_108 != V_109 || V_157 . V_52 > 2 ||
! F_32 ( & V_157 ) || ! V_80 -> V_112 || ! V_80 -> V_112 -> V_113 )
goto V_111;
V_193 = sizeof( struct V_50 ) * V_157 . V_52 ;
error = - V_133 ;
V_104 = F_33 ( V_193 , V_115 ) ;
if ( ! V_104 )
goto V_111;
V_82 = V_104 ;
error = - V_161 ;
V_107 = F_34 ( V_80 , V_157 . V_48 , ( char * ) V_82 , V_193 ) ;
if ( V_107 != V_193 )
goto V_165;
for ( V_193 = 0 , V_94 = 0 ; V_94 < V_157 . V_52 ; V_94 ++ )
if ( ( V_82 + V_94 ) -> V_97 == V_98 )
V_193 ++ ;
if ( V_193 != 1 )
goto V_165;
while ( V_82 -> V_97 != V_98 )
V_82 ++ ;
error = F_62 ( V_80 ,
F_25 ( V_82 -> V_88 ) ,
( V_82 -> V_87 +
F_6 ( V_82 -> V_88 ) ) ,
V_126 | V_128 | V_130 ,
V_131 | V_119 | V_120 ,
( V_82 -> V_90 -
F_6 ( V_82 -> V_88 ) ) ) ;
if ( error != F_25 ( V_82 -> V_88 ) )
goto V_165;
V_8 = V_82 -> V_88 + V_82 -> V_87 ;
if ( F_5 ( V_8 ) ) {
error = - V_12 ;
goto V_165;
}
V_39 = F_25 ( V_82 -> V_87 + V_82 -> V_88 +
V_10 - 1 ) ;
V_192 = V_82 -> V_99 + V_82 -> V_88 ;
if ( V_192 > V_39 )
F_3 ( V_39 , V_192 - V_39 ) ;
error = 0 ;
V_165:
F_35 ( V_104 ) ;
V_111:
return error ;
}
static bool F_66 ( struct V_37 * V_38 )
{
if ( V_38 == F_67 ( V_38 -> V_194 ) )
return true ;
if ( F_68 ( V_38 ) )
return true ;
return false ;
}
static unsigned long F_69 ( struct V_37 * V_38 ,
unsigned long V_195 )
{
#define F_70 ( type ) (mm_flags & (1UL << MMF_DUMP_##type))
if ( F_66 ( V_38 ) )
goto V_196;
if ( V_38 -> V_197 & V_198 )
return 0 ;
if ( V_38 -> V_197 & V_199 ) {
if ( ( V_38 -> V_197 & V_200 ) && F_70 ( V_201 ) )
goto V_196;
if ( ! ( V_38 -> V_197 & V_200 ) && F_70 ( V_202 ) )
goto V_196;
}
if ( V_38 -> V_197 & ( V_203 | V_204 ) )
return 0 ;
if ( V_38 -> V_197 & V_200 ) {
if ( V_38 -> V_205 -> V_206 . V_207 -> V_208 -> V_209 == 0 ?
F_70 ( V_210 ) : F_70 ( V_211 ) )
goto V_196;
return 0 ;
}
if ( V_38 -> V_212 && F_70 ( V_213 ) )
goto V_196;
if ( V_38 -> V_205 == NULL )
return 0 ;
if ( F_70 ( V_214 ) )
goto V_196;
if ( F_70 ( V_215 ) &&
V_38 -> V_216 == 0 && ( V_38 -> V_197 & V_217 ) ) {
T_6 V_11 * V_218 = ( T_6 V_11 * ) V_38 -> V_219 ;
T_6 V_220 ;
T_7 V_221 = F_71 () ;
union {
T_6 V_222 ;
char V_223 [ V_164 ] ;
} V_224 ;
F_72 ( V_164 != sizeof V_220 ) ;
V_224 . V_223 [ V_225 ] = V_226 ;
V_224 . V_223 [ V_227 ] = V_228 ;
V_224 . V_223 [ V_229 ] = V_230 ;
V_224 . V_223 [ V_231 ] = V_232 ;
F_73 ( V_233 ) ;
if ( F_50 ( F_74 ( V_220 , V_218 ) ) )
V_220 = 0 ;
F_73 ( V_221 ) ;
if ( V_220 == V_224 . V_222 )
return V_191 ;
}
#undef F_70
return 0 ;
V_196:
return V_38 -> V_234 - V_38 -> V_219 ;
}
static int F_75 ( struct V_235 * V_236 )
{
int V_237 ;
V_237 = sizeof( struct V_238 ) ;
V_237 += F_76 ( strlen ( V_236 -> V_239 ) + 1 , 4 ) ;
V_237 += F_76 ( V_236 -> V_240 , 4 ) ;
return V_237 ;
}
static int F_77 ( struct V_80 * V_80 , T_8 * V_241 )
{
static const char V_160 [ 4 ] = { 0 , } ;
F_78 ( V_160 , F_76 ( * V_241 , 4 ) - * V_241 , V_241 ) ;
return 1 ;
}
static int F_79 ( struct V_235 * V_242 , struct V_80 * V_80 ,
T_8 * V_241 )
{
struct V_238 V_236 ;
V_236 . V_243 = strlen ( V_242 -> V_239 ) + 1 ;
V_236 . V_244 = V_242 -> V_240 ;
V_236 . V_245 = V_242 -> type ;
F_78 ( & V_236 , sizeof( V_236 ) , V_241 ) ;
F_78 ( V_242 -> V_239 , V_236 . V_243 , V_241 ) ;
if ( ! F_77 ( V_80 , V_241 ) )
return 0 ;
F_78 ( V_242 -> V_246 , V_242 -> V_240 , V_241 ) ;
if ( ! F_77 ( V_80 , V_241 ) )
return 0 ;
return 1 ;
}
static void F_80 ( struct V_15 * V_247 , int V_248 ,
T_9 V_249 , T_6 V_136 , T_10 V_250 )
{
memset ( V_247 , 0 , sizeof( * V_247 ) ) ;
memcpy ( V_247 -> V_162 , V_163 , V_164 ) ;
V_247 -> V_162 [ V_251 ] = V_252 ;
V_247 -> V_162 [ V_253 ] = V_254 ;
V_247 -> V_162 [ V_255 ] = V_256 ;
V_247 -> V_162 [ V_257 ] = V_258 ;
V_247 -> V_108 = V_259 ;
V_247 -> V_260 = V_249 ;
V_247 -> V_261 = V_256 ;
V_247 -> V_48 = sizeof( struct V_15 ) ;
V_247 -> V_262 = V_136 ;
V_247 -> V_263 = sizeof( struct V_15 ) ;
V_247 -> V_114 = sizeof( struct V_50 ) ;
V_247 -> V_52 = V_248 ;
return;
}
static void F_81 ( struct V_50 * V_264 , int V_237 , T_8 V_265 )
{
V_264 -> V_97 = V_266 ;
V_264 -> V_90 = V_265 ;
V_264 -> V_88 = 0 ;
V_264 -> V_267 = 0 ;
V_264 -> V_87 = V_237 ;
V_264 -> V_99 = 0 ;
V_264 -> V_124 = 0 ;
V_264 -> V_268 = 0 ;
return;
}
static void F_82 ( struct V_235 * V_269 , const char * V_239 , int type ,
unsigned int V_237 , void * V_246 )
{
V_269 -> V_239 = V_239 ;
V_269 -> type = type ;
V_269 -> V_240 = V_237 ;
V_269 -> V_246 = V_246 ;
return;
}
static void F_83 ( struct V_270 * V_271 ,
struct V_272 * V_19 , long V_273 )
{
V_271 -> V_274 . V_275 = V_271 -> V_276 = V_273 ;
V_271 -> V_277 = V_19 -> V_278 . signal . V_279 [ 0 ] ;
V_271 -> V_280 = V_19 -> V_281 . V_279 [ 0 ] ;
F_84 () ;
V_271 -> V_282 = F_85 ( F_86 ( V_19 -> V_283 ) ) ;
F_87 () ;
V_271 -> V_284 = F_85 ( V_19 ) ;
V_271 -> V_285 = F_88 ( V_19 ) ;
V_271 -> V_286 = F_89 ( V_19 ) ;
if ( F_90 ( V_19 ) ) {
struct V_287 V_288 ;
F_91 ( V_19 , & V_288 ) ;
F_92 ( V_288 . V_289 , & V_271 -> V_290 ) ;
F_92 ( V_288 . V_291 , & V_271 -> V_292 ) ;
} else {
F_92 ( V_19 -> V_289 , & V_271 -> V_290 ) ;
F_92 ( V_19 -> V_291 , & V_271 -> V_292 ) ;
}
F_92 ( V_19 -> signal -> V_293 , & V_271 -> V_294 ) ;
F_92 ( V_19 -> signal -> V_295 , & V_271 -> V_296 ) ;
}
static int F_93 ( struct V_297 * V_298 , struct V_272 * V_19 ,
struct V_299 * V_5 )
{
const struct V_36 * V_36 ;
unsigned int V_94 , V_39 ;
memset ( V_298 , 0 , sizeof( struct V_297 ) ) ;
V_39 = V_5 -> V_74 - V_5 -> V_75 ;
if ( V_39 >= V_300 )
V_39 = V_300 - 1 ;
if ( F_94 ( & V_298 -> V_301 ,
( const char V_11 * ) V_5 -> V_75 , V_39 ) )
return - V_12 ;
for( V_94 = 0 ; V_94 < V_39 ; V_94 ++ )
if ( V_298 -> V_301 [ V_94 ] == 0 )
V_298 -> V_301 [ V_94 ] = ' ' ;
V_298 -> V_301 [ V_39 ] = 0 ;
F_84 () ;
V_298 -> V_282 = F_85 ( F_86 ( V_19 -> V_283 ) ) ;
F_87 () ;
V_298 -> V_284 = F_85 ( V_19 ) ;
V_298 -> V_285 = F_88 ( V_19 ) ;
V_298 -> V_286 = F_89 ( V_19 ) ;
V_94 = V_19 -> V_302 ? F_95 ( ~ V_19 -> V_302 ) + 1 : 0 ;
V_298 -> V_303 = V_94 ;
V_298 -> V_304 = ( V_94 > 5 ) ? '.' : L_1 [ V_94 ] ;
V_298 -> V_305 = V_298 -> V_304 == 'Z' ;
V_298 -> V_306 = F_96 ( V_19 ) ;
V_298 -> V_307 = V_19 -> V_136 ;
F_84 () ;
V_36 = F_97 ( V_19 ) ;
F_98 ( V_298 -> V_308 , V_36 -> V_58 ) ;
F_99 ( V_298 -> V_309 , V_36 -> V_62 ) ;
F_87 () ;
strncpy ( V_298 -> V_310 , V_19 -> V_311 , sizeof( V_298 -> V_310 ) ) ;
return 0 ;
}
static void F_100 ( struct V_235 * V_269 , struct V_299 * V_5 )
{
T_1 * V_312 = ( T_1 * ) V_5 -> V_40 ;
int V_94 = 0 ;
do
V_94 += 2 ;
while ( V_312 [ V_94 - 2 ] != V_313 );
F_82 ( V_269 , L_2 , V_314 , V_94 * sizeof( T_1 ) , V_312 ) ;
}
static void F_101 ( struct V_272 * V_315 ,
const struct V_316 * V_317 )
{
if ( V_317 -> V_318 )
V_317 -> V_318 ( V_315 , V_317 , 1 ) ;
}
static int F_102 ( struct V_319 * V_320 ,
const struct V_321 * V_322 ,
long V_273 , T_2 * V_323 )
{
unsigned int V_94 ;
F_83 ( & V_320 -> V_271 , V_320 -> V_315 , V_273 ) ;
( void ) V_322 -> V_324 [ 0 ] . F_103 ( V_320 -> V_315 , & V_322 -> V_324 [ 0 ] ,
0 , F_104 ( V_320 -> V_271 . V_325 ) ,
F_105 ( & V_320 -> V_271 ) , NULL ) ;
F_82 ( & V_320 -> V_326 [ 0 ] , L_2 , V_327 ,
F_106 ( V_320 -> V_271 ) , & V_320 -> V_271 ) ;
* V_323 += F_75 ( & V_320 -> V_326 [ 0 ] ) ;
F_101 ( V_320 -> V_315 , & V_322 -> V_324 [ 0 ] ) ;
for ( V_94 = 1 ; V_94 < V_322 -> V_328 ; ++ V_94 ) {
const struct V_316 * V_317 = & V_322 -> V_324 [ V_94 ] ;
F_101 ( V_320 -> V_315 , V_317 ) ;
if ( V_317 -> V_329 && V_317 -> F_103 &&
( ! V_317 -> V_330 || V_317 -> V_330 ( V_320 -> V_315 , V_317 ) ) ) {
int V_331 ;
T_2 V_86 = V_317 -> V_328 * V_317 -> V_86 ;
void * V_246 = F_33 ( V_86 , V_115 ) ;
if ( F_50 ( ! V_246 ) )
return 0 ;
V_331 = V_317 -> F_103 ( V_320 -> V_315 , V_317 ,
0 , V_86 , V_246 , NULL ) ;
if ( F_50 ( V_331 ) )
F_35 ( V_246 ) ;
else {
if ( V_317 -> V_329 != V_332 )
F_82 ( & V_320 -> V_326 [ V_94 ] , L_3 ,
V_317 -> V_329 ,
V_86 , V_246 ) ;
else {
F_107 ( & V_320 -> V_271 , 1 ) ;
F_82 ( & V_320 -> V_326 [ V_94 ] , L_2 ,
V_332 , V_86 , V_246 ) ;
}
* V_323 += F_75 ( & V_320 -> V_326 [ V_94 ] ) ;
}
}
}
return 1 ;
}
static int F_108 ( struct V_15 * V_247 , int V_333 ,
struct V_334 * V_335 ,
long V_273 , struct V_142 * V_143 )
{
struct V_272 * V_336 = V_4 ;
const struct V_321 * V_322 = F_109 ( V_336 ) ;
struct V_319 * V_320 ;
struct V_297 * V_298 ;
struct V_337 * V_338 ;
unsigned int V_94 ;
V_335 -> V_86 = 0 ;
V_335 -> V_339 = NULL ;
V_298 = F_33 ( sizeof( * V_298 ) , V_115 ) ;
if ( V_298 == NULL )
return 0 ;
F_82 ( & V_335 -> V_298 , L_2 , V_340 , sizeof( * V_298 ) , V_298 ) ;
V_335 -> V_341 = 0 ;
for ( V_94 = 0 ; V_94 < V_322 -> V_328 ; ++ V_94 )
if ( V_322 -> V_324 [ V_94 ] . V_329 != 0 )
++ V_335 -> V_341 ;
if ( F_50 ( V_335 -> V_341 == 0 ) ||
F_50 ( V_322 -> V_324 [ 0 ] . V_329 != V_327 ) ) {
F_110 ( 1 ) ;
return 0 ;
}
F_80 ( V_247 , V_333 ,
V_322 -> V_260 , V_322 -> V_262 , V_322 -> V_342 ) ;
for ( V_338 = & V_336 -> V_5 -> V_343 -> V_344 ; V_338 ; V_338 = V_338 -> V_345 ) {
V_320 = F_111 ( F_112 ( struct V_319 ,
V_326 [ V_335 -> V_341 ] ) ,
V_115 ) ;
if ( F_50 ( ! V_320 ) )
return 0 ;
V_320 -> V_315 = V_338 -> V_315 ;
if ( V_338 -> V_315 == V_336 || ! V_335 -> V_339 ) {
V_320 -> V_345 = V_335 -> V_339 ;
V_335 -> V_339 = V_320 ;
} else {
V_320 -> V_345 = V_335 -> V_339 -> V_345 ;
V_335 -> V_339 -> V_345 = V_320 ;
}
}
for ( V_320 = V_335 -> V_339 ; V_320 != NULL ; V_320 = V_320 -> V_345 )
if ( ! F_102 ( V_320 , V_322 , V_273 , & V_335 -> V_86 ) )
return 0 ;
F_93 ( V_298 , V_336 -> V_346 , V_336 -> V_5 ) ;
V_335 -> V_86 += F_75 ( & V_335 -> V_298 ) ;
F_100 ( & V_335 -> V_312 , V_4 -> V_5 ) ;
V_335 -> V_86 += F_75 ( & V_335 -> V_312 ) ;
return 1 ;
}
static T_2 F_113 ( struct V_334 * V_335 )
{
return V_335 -> V_86 ;
}
static int F_114 ( struct V_334 * V_335 ,
struct V_80 * V_80 , T_8 * V_241 )
{
bool V_347 = 1 ;
struct V_319 * V_320 = V_335 -> V_339 ;
do {
int V_94 ;
if ( ! F_79 ( & V_320 -> V_326 [ 0 ] , V_80 , V_241 ) )
return 0 ;
if ( V_347 && ! F_79 ( & V_335 -> V_298 , V_80 , V_241 ) )
return 0 ;
if ( V_347 && ! F_79 ( & V_335 -> V_312 , V_80 , V_241 ) )
return 0 ;
for ( V_94 = 1 ; V_94 < V_335 -> V_341 ; ++ V_94 )
if ( V_320 -> V_326 [ V_94 ] . V_246 &&
! F_79 ( & V_320 -> V_326 [ V_94 ] , V_80 , V_241 ) )
return 0 ;
V_347 = 0 ;
V_320 = V_320 -> V_345 ;
} while ( V_320 );
return 1 ;
}
static void F_115 ( struct V_334 * V_335 )
{
struct V_319 * V_348 = V_335 -> V_339 ;
while ( V_348 ) {
unsigned int V_94 ;
struct V_319 * V_320 = V_348 ;
V_348 = V_320 -> V_345 ;
F_110 ( V_320 -> V_326 [ 0 ] . V_246 && V_320 -> V_326 [ 0 ] . V_246 != & V_320 -> V_271 ) ;
for ( V_94 = 1 ; V_94 < V_335 -> V_341 ; ++ V_94 )
F_35 ( V_320 -> V_326 [ V_94 ] . V_246 ) ;
F_35 ( V_320 ) ;
}
F_35 ( V_335 -> V_298 . V_246 ) ;
}
static int F_116 ( long V_273 , struct V_349 * V_320 )
{
int V_237 = 0 ;
struct V_272 * V_19 = V_320 -> V_339 ;
V_320 -> V_350 = 0 ;
F_83 ( & V_320 -> V_271 , V_19 , V_273 ) ;
F_117 ( V_19 , & V_320 -> V_271 . V_325 ) ;
F_82 ( & V_320 -> V_326 [ 0 ] , L_2 , V_327 , sizeof( V_320 -> V_271 ) ,
& ( V_320 -> V_271 ) ) ;
V_320 -> V_350 ++ ;
V_237 += F_75 ( & V_320 -> V_326 [ 0 ] ) ;
if ( ( V_320 -> V_271 . V_351 = F_118 ( V_19 , NULL ,
& V_320 -> V_352 ) ) ) {
F_82 ( & V_320 -> V_326 [ 1 ] , L_2 , V_332 , sizeof( V_320 -> V_352 ) ,
& ( V_320 -> V_352 ) ) ;
V_320 -> V_350 ++ ;
V_237 += F_75 ( & V_320 -> V_326 [ 1 ] ) ;
}
#ifdef F_119
if ( F_120 ( V_19 , & V_320 -> V_353 ) ) {
F_82 ( & V_320 -> V_326 [ 2 ] , L_3 , V_354 ,
sizeof( V_320 -> V_353 ) , & V_320 -> V_353 ) ;
V_320 -> V_350 ++ ;
V_237 += F_75 ( & V_320 -> V_326 [ 2 ] ) ;
}
#endif
return V_237 ;
}
static int F_121 ( struct V_334 * V_335 )
{
memset ( V_335 , 0 , sizeof( * V_335 ) ) ;
F_122 ( & V_335 -> V_355 ) ;
V_335 -> V_326 = F_33 ( 6 * sizeof( struct V_235 ) , V_115 ) ;
if ( ! V_335 -> V_326 )
return 0 ;
V_335 -> V_298 = F_33 ( sizeof( * V_335 -> V_298 ) , V_115 ) ;
if ( ! V_335 -> V_298 )
goto V_356;
V_335 -> V_271 = F_33 ( sizeof( * V_335 -> V_271 ) , V_115 ) ;
if ( ! V_335 -> V_271 )
goto V_357;
V_335 -> V_352 = F_33 ( sizeof( * V_335 -> V_352 ) , V_115 ) ;
if ( ! V_335 -> V_352 )
goto V_358;
#ifdef F_119
V_335 -> V_353 = F_33 ( sizeof( * V_335 -> V_353 ) , V_115 ) ;
if ( ! V_335 -> V_353 )
goto V_359;
#endif
return 1 ;
#ifdef F_119
V_359:
F_35 ( V_335 -> V_352 ) ;
#endif
V_358:
F_35 ( V_335 -> V_271 ) ;
V_357:
F_35 ( V_335 -> V_298 ) ;
V_356:
F_35 ( V_335 -> V_326 ) ;
return 0 ;
}
static int F_108 ( struct V_15 * V_247 , int V_333 ,
struct V_334 * V_335 ,
long V_273 , struct V_142 * V_143 )
{
struct V_360 * V_320 ;
if ( ! F_121 ( V_335 ) )
return 0 ;
if ( V_273 ) {
struct V_337 * V_338 ;
struct V_349 * V_361 ;
for ( V_338 = V_4 -> V_5 -> V_343 -> V_344 . V_345 ;
V_338 ; V_338 = V_338 -> V_345 ) {
V_361 = F_111 ( sizeof( * V_361 ) , V_115 ) ;
if ( ! V_361 )
return 0 ;
V_361 -> V_339 = V_338 -> V_315 ;
F_123 ( & V_361 -> V_362 , & V_335 -> V_355 ) ;
}
F_124 (t, &info->thread_list) {
int V_237 ;
V_361 = F_125 ( V_320 , struct V_349 , V_362 ) ;
V_237 = F_116 ( V_273 , V_361 ) ;
V_335 -> V_363 += V_237 ;
}
}
memset ( V_335 -> V_271 , 0 , sizeof( * V_335 -> V_271 ) ) ;
F_83 ( V_335 -> V_271 , V_4 , V_273 ) ;
F_126 ( & V_335 -> V_271 -> V_325 , V_143 ) ;
F_80 ( V_247 , V_333 , V_364 , V_365 , V_258 ) ;
F_82 ( V_335 -> V_326 + 0 , L_2 , V_327 ,
sizeof( * V_335 -> V_271 ) , V_335 -> V_271 ) ;
F_93 ( V_335 -> V_298 , V_4 -> V_346 , V_4 -> V_5 ) ;
F_82 ( V_335 -> V_326 + 1 , L_2 , V_340 ,
sizeof( * V_335 -> V_298 ) , V_335 -> V_298 ) ;
V_335 -> V_366 = 2 ;
F_100 ( & V_335 -> V_326 [ V_335 -> V_366 ++ ] , V_4 -> V_5 ) ;
V_335 -> V_271 -> V_351 = F_118 ( V_4 , V_143 ,
V_335 -> V_352 ) ;
if ( V_335 -> V_271 -> V_351 )
F_82 ( V_335 -> V_326 + V_335 -> V_366 ++ ,
L_2 , V_332 , sizeof( * V_335 -> V_352 ) , V_335 -> V_352 ) ;
#ifdef F_119
if ( F_120 ( V_4 , V_335 -> V_353 ) )
F_82 ( V_335 -> V_326 + V_335 -> V_366 ++ ,
L_3 , V_354 ,
sizeof( * V_335 -> V_353 ) , V_335 -> V_353 ) ;
#endif
return 1 ;
}
static T_2 F_113 ( struct V_334 * V_335 )
{
int V_237 = 0 ;
int V_94 ;
for ( V_94 = 0 ; V_94 < V_335 -> V_366 ; V_94 ++ )
V_237 += F_75 ( V_335 -> V_326 + V_94 ) ;
V_237 += V_335 -> V_363 ;
return V_237 ;
}
static int F_114 ( struct V_334 * V_335 ,
struct V_80 * V_80 , T_8 * V_241 )
{
int V_94 ;
struct V_360 * V_320 ;
for ( V_94 = 0 ; V_94 < V_335 -> V_366 ; V_94 ++ )
if ( ! F_79 ( V_335 -> V_326 + V_94 , V_80 , V_241 ) )
return 0 ;
F_124 (t, &info->thread_list) {
struct V_349 * V_367 =
F_125 ( V_320 , struct V_349 , V_362 ) ;
for ( V_94 = 0 ; V_94 < V_367 -> V_350 ; V_94 ++ )
if ( ! F_79 ( & V_367 -> V_326 [ V_94 ] , V_80 , V_241 ) )
return 0 ;
}
return 1 ;
}
static void F_115 ( struct V_334 * V_335 )
{
while ( ! F_127 ( & V_335 -> V_355 ) ) {
struct V_360 * V_367 = V_335 -> V_355 . V_345 ;
F_128 ( V_367 ) ;
F_35 ( F_125 ( V_367 , struct V_349 , V_362 ) ) ;
}
F_35 ( V_335 -> V_271 ) ;
F_35 ( V_335 -> V_298 ) ;
F_35 ( V_335 -> V_326 ) ;
F_35 ( V_335 -> V_352 ) ;
#ifdef F_119
F_35 ( V_335 -> V_353 ) ;
#endif
}
static struct V_37 * F_129 ( struct V_272 * V_368 ,
struct V_37 * V_369 )
{
struct V_37 * V_331 = V_368 -> V_5 -> V_113 ;
if ( V_331 )
return V_331 ;
return V_369 ;
}
static struct V_37 * F_130 ( struct V_37 * V_370 ,
struct V_37 * V_369 )
{
struct V_37 * V_331 ;
V_331 = V_370 -> V_371 ;
if ( V_331 )
return V_331 ;
if ( V_370 == V_369 )
return NULL ;
return V_369 ;
}
static void F_131 ( struct V_15 * V_247 , struct V_372 * V_373 ,
T_1 V_374 , int V_248 )
{
V_247 -> V_374 = V_374 ;
V_247 -> V_375 = sizeof( * V_373 ) ;
V_247 -> V_376 = 1 ;
V_247 -> V_377 = V_378 ;
memset ( V_373 , 0 , sizeof( * V_373 ) ) ;
V_373 -> V_379 = V_380 ;
V_373 -> V_381 = V_247 -> V_376 ;
V_373 -> V_382 = V_247 -> V_377 ;
V_373 -> V_383 = V_248 ;
}
static T_2 F_132 ( struct V_37 * V_369 ,
unsigned long V_195 )
{
struct V_37 * V_38 ;
T_2 V_86 = 0 ;
for ( V_38 = F_129 ( V_4 , V_369 ) ; V_38 != NULL ;
V_38 = F_130 ( V_38 , V_369 ) )
V_86 += F_69 ( V_38 , V_195 ) ;
return V_86 ;
}
static int F_133 ( struct V_384 * V_385 )
{
int V_386 = 0 ;
T_7 V_221 ;
int V_248 ;
T_2 V_86 = 0 ;
struct V_37 * V_38 , * V_369 ;
struct V_15 * V_247 = NULL ;
T_8 V_265 = 0 , V_387 , V_241 ;
struct V_334 V_335 ;
struct V_50 * V_388 = NULL ;
struct V_372 * V_373 = NULL ;
T_11 V_52 ;
T_1 V_374 ;
V_247 = F_33 ( sizeof( * V_247 ) , V_115 ) ;
if ( ! V_247 )
goto V_111;
V_248 = V_4 -> V_5 -> V_389 ;
V_248 += F_134 () ;
V_369 = F_67 ( V_4 -> V_5 ) ;
if ( V_369 != NULL )
V_248 ++ ;
V_248 ++ ;
V_52 = V_248 > V_390 ? V_390 : V_248 ;
if ( ! F_108 ( V_247 , V_52 , & V_335 , V_385 -> V_273 , V_385 -> V_143 ) )
goto V_391;
V_386 = 1 ;
V_4 -> V_136 |= V_392 ;
V_221 = F_71 () ;
F_73 ( V_393 ) ;
V_265 += sizeof( * V_247 ) ;
V_265 += V_248 * sizeof( struct V_50 ) ;
V_241 = V_265 ;
{
T_2 V_237 = F_113 ( & V_335 ) ;
V_237 += F_135 () ;
V_388 = F_33 ( sizeof( * V_388 ) , V_115 ) ;
if ( ! V_388 )
goto V_394;
F_81 ( V_388 , V_237 , V_265 ) ;
V_265 += V_237 ;
}
V_387 = V_265 = F_76 ( V_265 , V_44 ) ;
V_265 += F_132 ( V_369 , V_385 -> V_195 ) ;
V_265 += F_136 () ;
V_374 = V_265 ;
if ( V_52 == V_390 ) {
V_373 = F_33 ( sizeof( * V_373 ) , V_115 ) ;
if ( ! V_373 )
goto V_394;
F_131 ( V_247 , V_373 , V_374 , V_248 ) ;
}
V_265 = V_387 ;
V_86 += sizeof( * V_247 ) ;
if ( V_86 > V_385 -> V_395 || ! F_137 ( V_385 -> V_80 , V_247 , sizeof( * V_247 ) ) )
goto V_394;
V_86 += sizeof( * V_388 ) ;
if ( V_86 > V_385 -> V_395
|| ! F_137 ( V_385 -> V_80 , V_388 , sizeof( * V_388 ) ) )
goto V_394;
for ( V_38 = F_129 ( V_4 , V_369 ) ; V_38 != NULL ;
V_38 = F_130 ( V_38 , V_369 ) ) {
struct V_50 V_264 ;
V_264 . V_97 = V_98 ;
V_264 . V_90 = V_265 ;
V_264 . V_88 = V_38 -> V_219 ;
V_264 . V_267 = 0 ;
V_264 . V_87 = F_69 ( V_38 , V_385 -> V_195 ) ;
V_264 . V_99 = V_38 -> V_234 - V_38 -> V_219 ;
V_265 += V_264 . V_87 ;
V_264 . V_124 = V_38 -> V_197 & V_217 ? V_125 : 0 ;
if ( V_38 -> V_197 & V_396 )
V_264 . V_124 |= V_127 ;
if ( V_38 -> V_197 & V_397 )
V_264 . V_124 |= V_129 ;
V_264 . V_268 = V_44 ;
V_86 += sizeof( V_264 ) ;
if ( V_86 > V_385 -> V_395
|| ! F_137 ( V_385 -> V_80 , & V_264 , sizeof( V_264 ) ) )
goto V_394;
}
if ( ! F_138 ( V_385 -> V_80 , V_265 , & V_86 , V_385 -> V_395 ) )
goto V_394;
if ( ! F_114 ( & V_335 , V_385 -> V_80 , & V_241 ) )
goto V_394;
if ( F_139 ( V_385 -> V_80 , & V_241 ) )
goto V_394;
if ( ! F_140 ( V_385 -> V_80 , V_387 - V_241 ) )
goto V_394;
for ( V_38 = F_129 ( V_4 , V_369 ) ; V_38 != NULL ;
V_38 = F_130 ( V_38 , V_369 ) ) {
unsigned long V_3 ;
unsigned long V_2 ;
V_2 = V_38 -> V_219 + F_69 ( V_38 , V_385 -> V_195 ) ;
for ( V_3 = V_38 -> V_219 ; V_3 < V_2 ; V_3 += V_191 ) {
struct V_398 * V_398 ;
int V_399 ;
V_398 = F_141 ( V_3 ) ;
if ( V_398 ) {
void * V_400 = F_142 ( V_398 ) ;
V_399 = ( ( V_86 += V_191 ) > V_385 -> V_395 ) ||
! F_137 ( V_385 -> V_80 , V_400 ,
V_191 ) ;
F_143 ( V_398 ) ;
F_144 ( V_398 ) ;
} else
V_399 = ! F_140 ( V_385 -> V_80 , V_191 ) ;
if ( V_399 )
goto V_394;
}
}
if ( ! F_145 ( V_385 -> V_80 , & V_86 , V_385 -> V_395 ) )
goto V_394;
if ( V_52 == V_390 ) {
V_86 += sizeof( * V_373 ) ;
if ( V_86 > V_385 -> V_395
|| ! F_137 ( V_385 -> V_80 , V_373 ,
sizeof( * V_373 ) ) )
goto V_394;
}
V_394:
F_73 ( V_221 ) ;
V_391:
F_115 ( & V_335 ) ;
F_35 ( V_373 ) ;
F_35 ( V_388 ) ;
F_35 ( V_247 ) ;
V_111:
return V_386 ;
}
static int T_12 F_146 ( void )
{
F_147 ( & V_188 ) ;
return 0 ;
}
static void T_13 F_148 ( void )
{
F_149 ( & V_188 ) ;
}
