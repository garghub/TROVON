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
static int F_39 ( struct V_13 * V_14 , struct V_142 * V_143 )
{
struct V_81 * V_101 = NULL ;
unsigned long V_17 = 0 , V_144 = 0 ;
int V_105 = 0 ;
char * V_145 = NULL ;
unsigned long error ;
struct V_50 * V_146 , * V_104 ;
unsigned long V_8 , V_147 ;
int V_107 , V_94 ;
unsigned int V_87 ;
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
if ( V_146 -> V_88 > V_167 ||
V_146 -> V_88 < 2 )
goto V_165;
V_107 = - V_133 ;
V_145 = F_33 ( V_146 -> V_88 ,
V_115 ) ;
if ( ! V_145 )
goto V_165;
V_107 = F_34 ( V_14 -> V_81 , V_146 -> V_91 ,
V_145 ,
V_146 -> V_88 ) ;
if ( V_107 != V_146 -> V_88 ) {
if ( V_107 >= 0 )
V_107 = - V_116 ;
goto V_168;
}
V_107 = - V_161 ;
if ( V_145 [ V_146 -> V_88 - 1 ] != '\0' )
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
V_122 = V_146 -> V_89 ;
if ( V_158 -> V_157 . V_108 == V_109 || V_105 ) {
V_183 |= V_131 ;
} else if ( V_158 -> V_157 . V_108 == V_110 ) {
#ifdef F_51
if ( V_4 -> V_136 & V_137 )
V_144 = 0 ;
else
V_144 = F_27 ( V_185 - V_122 ) ;
#else
V_144 = F_27 ( V_185 - V_122 ) ;
#endif
}
error = F_26 ( V_14 -> V_81 , V_144 + V_122 , V_146 ,
V_121 , V_183 , 0 ) ;
if ( F_4 ( error ) ) {
F_49 ( V_181 , V_4 , 0 ) ;
V_107 = F_42 ( ( void * ) error ) ?
F_41 ( ( void * ) error ) : - V_78 ;
goto V_170;
}
if ( ! V_105 ) {
V_105 = 1 ;
V_17 = ( V_146 -> V_89 - V_146 -> V_91 ) ;
if ( V_158 -> V_157 . V_108 == V_110 ) {
V_144 += error -
F_27 ( V_144 + V_122 ) ;
V_17 += V_144 ;
T_5 = V_144 ;
}
}
V_123 = V_146 -> V_89 ;
if ( V_123 < V_149 )
V_149 = V_123 ;
if ( V_151 < V_123 )
V_151 = V_123 ;
if ( F_4 ( V_123 ) || V_146 -> V_88 > V_146 -> V_99 ||
V_146 -> V_99 > V_132 ||
V_132 - V_146 -> V_99 < V_123 ) {
F_49 ( V_181 , V_4 , 0 ) ;
V_107 = - V_78 ;
goto V_170;
}
V_123 = V_146 -> V_89 + V_146 -> V_88 ;
if ( V_123 > V_8 )
V_8 = V_123 ;
if ( ( V_146 -> V_124 & V_129 ) && V_150 < V_123 )
V_150 = V_123 ;
if ( V_152 < V_123 )
V_152 = V_123 ;
V_123 = V_146 -> V_89 + V_146 -> V_99 ;
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
unsigned long V_102 = 0 ;
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
( int ) V_148 : - V_78 ;
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
V_107 = - V_78 ;
goto V_170;
}
}
F_35 ( V_104 ) ;
F_56 ( & V_187 ) ;
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
V_4 -> V_188 = 1 ;
#endif
}
#endif
if ( V_4 -> V_138 & V_189 ) {
error = F_28 ( NULL , 0 , V_190 , V_126 | V_130 ,
V_131 | V_119 , 0 ) ;
}
#ifdef F_62
F_62 ( V_143 , T_5 ) ;
#endif
F_63 ( V_143 , V_148 , V_14 -> V_19 ) ;
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
static int F_64 ( struct V_81 * V_81 )
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
static bool F_65 ( struct V_37 * V_38 )
{
if ( V_38 == F_66 ( V_38 -> V_193 ) )
return true ;
if ( F_67 ( V_38 ) )
return true ;
return false ;
}
static unsigned long F_68 ( struct V_37 * V_38 ,
unsigned long V_194 )
{
#define F_69 ( type ) (mm_flags & (1UL << MMF_DUMP_##type))
if ( F_65 ( V_38 ) )
goto V_195;
if ( V_38 -> V_196 & V_197 )
return 0 ;
if ( V_38 -> V_196 & V_198 ) {
if ( ( V_38 -> V_196 & V_199 ) && F_69 ( V_200 ) )
goto V_195;
if ( ! ( V_38 -> V_196 & V_199 ) && F_69 ( V_201 ) )
goto V_195;
}
if ( V_38 -> V_196 & V_202 )
return 0 ;
if ( V_38 -> V_196 & V_199 ) {
if ( V_38 -> V_203 -> V_204 . V_205 -> V_206 -> V_207 == 0 ?
F_69 ( V_208 ) : F_69 ( V_209 ) )
goto V_195;
return 0 ;
}
if ( V_38 -> V_210 && F_69 ( V_211 ) )
goto V_195;
if ( V_38 -> V_203 == NULL )
return 0 ;
if ( F_69 ( V_212 ) )
goto V_195;
if ( F_69 ( V_213 ) &&
V_38 -> V_214 == 0 && ( V_38 -> V_196 & V_215 ) ) {
T_6 V_11 * V_216 = ( T_6 V_11 * ) V_38 -> V_217 ;
T_6 V_218 ;
T_7 V_219 = F_70 () ;
union {
T_6 V_220 ;
char V_221 [ V_164 ] ;
} V_222 ;
F_71 ( V_164 != sizeof V_218 ) ;
V_222 . V_221 [ V_223 ] = V_224 ;
V_222 . V_221 [ V_225 ] = V_226 ;
V_222 . V_221 [ V_227 ] = V_228 ;
V_222 . V_221 [ V_229 ] = V_230 ;
F_72 ( V_231 ) ;
if ( F_50 ( F_73 ( V_218 , V_216 ) ) )
V_218 = 0 ;
F_72 ( V_219 ) ;
if ( V_218 == V_222 . V_220 )
return V_190 ;
}
#undef F_69
return 0 ;
V_195:
return V_38 -> V_232 - V_38 -> V_217 ;
}
static int F_74 ( struct V_233 * V_234 )
{
int V_235 ;
V_235 = sizeof( struct V_236 ) ;
V_235 += F_75 ( strlen ( V_234 -> V_237 ) + 1 , 4 ) ;
V_235 += F_75 ( V_234 -> V_238 , 4 ) ;
return V_235 ;
}
static int F_76 ( struct V_81 * V_81 , T_8 * V_239 )
{
static const char V_160 [ 4 ] = { 0 , } ;
F_77 ( V_160 , F_75 ( * V_239 , 4 ) - * V_239 , V_239 ) ;
return 1 ;
}
static int F_78 ( struct V_233 * V_240 , struct V_81 * V_81 ,
T_8 * V_239 )
{
struct V_236 V_234 ;
V_234 . V_241 = strlen ( V_240 -> V_237 ) + 1 ;
V_234 . V_242 = V_240 -> V_238 ;
V_234 . V_243 = V_240 -> type ;
F_77 ( & V_234 , sizeof( V_234 ) , V_239 ) ;
F_77 ( V_240 -> V_237 , V_234 . V_241 , V_239 ) ;
if ( ! F_76 ( V_81 , V_239 ) )
return 0 ;
F_77 ( V_240 -> V_244 , V_240 -> V_238 , V_239 ) ;
if ( ! F_76 ( V_81 , V_239 ) )
return 0 ;
return 1 ;
}
static void F_79 ( struct V_15 * V_245 , int V_246 ,
T_9 V_247 , T_6 V_136 , T_10 V_248 )
{
memset ( V_245 , 0 , sizeof( * V_245 ) ) ;
memcpy ( V_245 -> V_162 , V_163 , V_164 ) ;
V_245 -> V_162 [ V_249 ] = V_250 ;
V_245 -> V_162 [ V_251 ] = V_252 ;
V_245 -> V_162 [ V_253 ] = V_254 ;
V_245 -> V_162 [ V_255 ] = V_256 ;
V_245 -> V_108 = V_257 ;
V_245 -> V_258 = V_247 ;
V_245 -> V_259 = V_254 ;
V_245 -> V_48 = sizeof( struct V_15 ) ;
V_245 -> V_260 = V_136 ;
V_245 -> V_261 = sizeof( struct V_15 ) ;
V_245 -> V_114 = sizeof( struct V_50 ) ;
V_245 -> V_52 = V_246 ;
return;
}
static void F_80 ( struct V_50 * V_262 , int V_235 , T_8 V_263 )
{
V_262 -> V_97 = V_264 ;
V_262 -> V_91 = V_263 ;
V_262 -> V_89 = 0 ;
V_262 -> V_265 = 0 ;
V_262 -> V_88 = V_235 ;
V_262 -> V_99 = 0 ;
V_262 -> V_124 = 0 ;
V_262 -> V_266 = 0 ;
return;
}
static void F_81 ( struct V_233 * V_267 , const char * V_237 , int type ,
unsigned int V_235 , void * V_244 )
{
V_267 -> V_237 = V_237 ;
V_267 -> type = type ;
V_267 -> V_238 = V_235 ;
V_267 -> V_244 = V_244 ;
return;
}
static void F_82 ( struct V_268 * V_269 ,
struct V_270 * V_19 , long V_271 )
{
V_269 -> V_272 . V_273 = V_269 -> V_274 = V_271 ;
V_269 -> V_275 = V_19 -> V_276 . signal . V_277 [ 0 ] ;
V_269 -> V_278 = V_19 -> V_279 . V_277 [ 0 ] ;
F_83 () ;
V_269 -> V_280 = F_84 ( F_85 ( V_19 -> V_281 ) ) ;
F_86 () ;
V_269 -> V_282 = F_84 ( V_19 ) ;
V_269 -> V_283 = F_87 ( V_19 ) ;
V_269 -> V_284 = F_88 ( V_19 ) ;
if ( F_89 ( V_19 ) ) {
struct V_285 V_286 ;
F_90 ( V_19 , & V_286 ) ;
F_91 ( V_286 . V_287 , & V_269 -> V_288 ) ;
F_91 ( V_286 . V_289 , & V_269 -> V_290 ) ;
} else {
F_91 ( V_19 -> V_287 , & V_269 -> V_288 ) ;
F_91 ( V_19 -> V_289 , & V_269 -> V_290 ) ;
}
F_91 ( V_19 -> signal -> V_291 , & V_269 -> V_292 ) ;
F_91 ( V_19 -> signal -> V_293 , & V_269 -> V_294 ) ;
}
static int F_92 ( struct V_295 * V_296 , struct V_270 * V_19 ,
struct V_297 * V_5 )
{
const struct V_36 * V_36 ;
unsigned int V_94 , V_39 ;
memset ( V_296 , 0 , sizeof( struct V_295 ) ) ;
V_39 = V_5 -> V_75 - V_5 -> V_76 ;
if ( V_39 >= V_298 )
V_39 = V_298 - 1 ;
if ( F_93 ( & V_296 -> V_299 ,
( const char V_11 * ) V_5 -> V_76 , V_39 ) )
return - V_12 ;
for( V_94 = 0 ; V_94 < V_39 ; V_94 ++ )
if ( V_296 -> V_299 [ V_94 ] == 0 )
V_296 -> V_299 [ V_94 ] = ' ' ;
V_296 -> V_299 [ V_39 ] = 0 ;
F_83 () ;
V_296 -> V_280 = F_84 ( F_85 ( V_19 -> V_281 ) ) ;
F_86 () ;
V_296 -> V_282 = F_84 ( V_19 ) ;
V_296 -> V_283 = F_87 ( V_19 ) ;
V_296 -> V_284 = F_88 ( V_19 ) ;
V_94 = V_19 -> V_300 ? F_94 ( ~ V_19 -> V_300 ) + 1 : 0 ;
V_296 -> V_301 = V_94 ;
V_296 -> V_302 = ( V_94 > 5 ) ? '.' : L_1 [ V_94 ] ;
V_296 -> V_303 = V_296 -> V_302 == 'Z' ;
V_296 -> V_304 = F_95 ( V_19 ) ;
V_296 -> V_305 = V_19 -> V_136 ;
F_83 () ;
V_36 = F_96 ( V_19 ) ;
F_97 ( V_296 -> V_306 , F_16 ( V_36 -> V_58 , V_36 -> V_59 ) ) ;
F_98 ( V_296 -> V_307 , F_17 ( V_36 -> V_58 , V_36 -> V_63 ) ) ;
F_86 () ;
strncpy ( V_296 -> V_308 , V_19 -> V_309 , sizeof( V_296 -> V_308 ) ) ;
return 0 ;
}
static void F_99 ( struct V_233 * V_267 , struct V_297 * V_5 )
{
T_1 * V_310 = ( T_1 * ) V_5 -> V_40 ;
int V_94 = 0 ;
do
V_94 += 2 ;
while ( V_310 [ V_94 - 2 ] != V_311 );
F_81 ( V_267 , L_2 , V_312 , V_94 * sizeof( T_1 ) , V_310 ) ;
}
static void F_100 ( struct V_233 * V_267 , T_11 * V_313 ,
T_12 * V_314 )
{
T_7 V_315 = F_70 () ;
F_72 ( V_316 ) ;
F_101 ( ( T_11 V_11 * ) V_313 , V_314 ) ;
F_72 ( V_315 ) ;
F_81 ( V_267 , L_2 , V_317 , sizeof( * V_313 ) , V_313 ) ;
}
static void F_102 ( struct V_233 * V_267 )
{
struct V_37 * V_38 ;
unsigned V_318 , V_87 , V_319 , V_320 , V_321 ;
T_13 * V_244 ;
T_13 * V_322 ;
char * V_323 , * V_324 ;
V_318 = V_4 -> V_5 -> V_325 ;
V_87 = V_318 * 64 ;
V_319 = ( 2 + 3 * V_318 ) * sizeof( V_244 [ 0 ] ) ;
V_326:
if ( V_87 >= V_327 )
goto V_328;
V_87 = F_103 ( V_87 , V_190 ) ;
V_244 = F_104 ( V_87 ) ;
if ( ! V_244 )
goto V_328;
V_322 = V_244 + 2 ;
V_323 = V_324 = ( ( char * ) V_244 ) + V_319 ;
V_320 = V_87 - V_319 ;
V_318 = 0 ;
for ( V_38 = V_4 -> V_5 -> V_113 ; V_38 != NULL ; V_38 = V_38 -> V_329 ) {
struct V_81 * V_81 ;
const char * V_330 ;
V_81 = V_38 -> V_203 ;
if ( ! V_81 )
continue;
V_330 = F_105 ( & V_81 -> V_204 , V_324 , V_320 ) ;
if ( F_42 ( V_330 ) ) {
if ( F_41 ( V_330 ) == - V_331 ) {
F_106 ( V_244 ) ;
V_87 = V_87 * 5 / 4 ;
goto V_326;
}
continue;
}
V_321 = ( V_324 + V_320 ) - V_330 ;
V_320 = V_330 - V_324 ;
memmove ( V_324 , V_330 , V_321 ) ;
V_324 += V_321 ;
* V_322 ++ = V_38 -> V_217 ;
* V_322 ++ = V_38 -> V_232 ;
* V_322 ++ = V_38 -> V_214 ;
V_318 ++ ;
}
V_244 [ 0 ] = V_318 ;
V_244 [ 1 ] = V_190 ;
V_321 = V_4 -> V_5 -> V_325 - V_318 ;
if ( V_321 != 0 ) {
unsigned V_332 = V_321 * 3 * sizeof( V_244 [ 0 ] ) ;
memmove ( V_323 - V_332 , V_323 ,
V_324 - V_323 ) ;
V_324 -= V_332 ;
}
V_87 = V_324 - ( char * ) V_244 ;
F_81 ( V_267 , L_2 , V_333 , V_87 , V_244 ) ;
V_328: ;
}
static void F_107 ( struct V_270 * V_334 ,
const struct V_335 * V_336 )
{
if ( V_336 -> V_337 )
V_336 -> V_337 ( V_334 , V_336 , 1 ) ;
}
static int F_108 ( struct V_338 * V_339 ,
const struct V_340 * V_341 ,
long V_271 , T_2 * V_342 )
{
unsigned int V_94 ;
F_82 ( & V_339 -> V_269 , V_339 -> V_334 , V_271 ) ;
( void ) V_341 -> V_343 [ 0 ] . F_109 ( V_339 -> V_334 , & V_341 -> V_343 [ 0 ] ,
0 , F_110 ( V_339 -> V_269 . V_344 ) ,
F_111 ( & V_339 -> V_269 ) , NULL ) ;
F_81 ( & V_339 -> V_345 [ 0 ] , L_2 , V_346 ,
F_112 ( V_339 -> V_269 ) , & V_339 -> V_269 ) ;
* V_342 += F_74 ( & V_339 -> V_345 [ 0 ] ) ;
F_107 ( V_339 -> V_334 , & V_341 -> V_343 [ 0 ] ) ;
for ( V_94 = 1 ; V_94 < V_341 -> V_321 ; ++ V_94 ) {
const struct V_335 * V_336 = & V_341 -> V_343 [ V_94 ] ;
F_107 ( V_339 -> V_334 , V_336 ) ;
if ( V_336 -> V_347 && V_336 -> F_109 &&
( ! V_336 -> V_348 || V_336 -> V_348 ( V_339 -> V_334 , V_336 ) ) ) {
int V_349 ;
T_2 V_87 = V_336 -> V_321 * V_336 -> V_87 ;
void * V_244 = F_33 ( V_87 , V_115 ) ;
if ( F_50 ( ! V_244 ) )
return 0 ;
V_349 = V_336 -> F_109 ( V_339 -> V_334 , V_336 ,
0 , V_87 , V_244 , NULL ) ;
if ( F_50 ( V_349 ) )
F_35 ( V_244 ) ;
else {
if ( V_336 -> V_347 != V_350 )
F_81 ( & V_339 -> V_345 [ V_94 ] , L_3 ,
V_336 -> V_347 ,
V_87 , V_244 ) ;
else {
F_113 ( & V_339 -> V_269 , 1 ) ;
F_81 ( & V_339 -> V_345 [ V_94 ] , L_2 ,
V_350 , V_87 , V_244 ) ;
}
* V_342 += F_74 ( & V_339 -> V_345 [ V_94 ] ) ;
}
}
}
return 1 ;
}
static int F_114 ( struct V_15 * V_245 , int V_351 ,
struct V_352 * V_353 ,
T_12 * V_314 , struct V_142 * V_143 )
{
struct V_270 * V_354 = V_4 ;
const struct V_340 * V_341 = F_115 ( V_354 ) ;
struct V_338 * V_339 ;
struct V_295 * V_296 ;
struct V_355 * V_356 ;
unsigned int V_94 ;
V_353 -> V_87 = 0 ;
V_353 -> V_357 = NULL ;
V_296 = F_33 ( sizeof( * V_296 ) , V_115 ) ;
if ( V_296 == NULL )
return 0 ;
F_81 ( & V_353 -> V_296 , L_2 , V_358 , sizeof( * V_296 ) , V_296 ) ;
V_353 -> V_359 = 0 ;
for ( V_94 = 0 ; V_94 < V_341 -> V_321 ; ++ V_94 )
if ( V_341 -> V_343 [ V_94 ] . V_347 != 0 )
++ V_353 -> V_359 ;
if ( F_50 ( V_353 -> V_359 == 0 ) ||
F_50 ( V_341 -> V_343 [ 0 ] . V_347 != V_346 ) ) {
F_116 ( 1 ) ;
return 0 ;
}
F_79 ( V_245 , V_351 ,
V_341 -> V_258 , V_341 -> V_260 , V_341 -> V_360 ) ;
for ( V_356 = & V_354 -> V_5 -> V_361 -> V_362 ; V_356 ; V_356 = V_356 -> V_363 ) {
V_339 = F_117 ( F_118 ( struct V_338 ,
V_345 [ V_353 -> V_359 ] ) ,
V_115 ) ;
if ( F_50 ( ! V_339 ) )
return 0 ;
V_339 -> V_334 = V_356 -> V_334 ;
if ( V_356 -> V_334 == V_354 || ! V_353 -> V_357 ) {
V_339 -> V_363 = V_353 -> V_357 ;
V_353 -> V_357 = V_339 ;
} else {
V_339 -> V_363 = V_353 -> V_357 -> V_363 ;
V_353 -> V_357 -> V_363 = V_339 ;
}
}
for ( V_339 = V_353 -> V_357 ; V_339 != NULL ; V_339 = V_339 -> V_363 )
if ( ! F_108 ( V_339 , V_341 , V_314 -> V_273 , & V_353 -> V_87 ) )
return 0 ;
F_92 ( V_296 , V_354 -> V_364 , V_354 -> V_5 ) ;
V_353 -> V_87 += F_74 ( & V_353 -> V_296 ) ;
F_100 ( & V_353 -> V_365 , & V_353 -> V_313 , V_314 ) ;
V_353 -> V_87 += F_74 ( & V_353 -> V_365 ) ;
F_99 ( & V_353 -> V_310 , V_4 -> V_5 ) ;
V_353 -> V_87 += F_74 ( & V_353 -> V_310 ) ;
F_102 ( & V_353 -> V_366 ) ;
V_353 -> V_87 += F_74 ( & V_353 -> V_366 ) ;
return 1 ;
}
static T_2 F_119 ( struct V_352 * V_353 )
{
return V_353 -> V_87 ;
}
static int F_120 ( struct V_352 * V_353 ,
struct V_81 * V_81 , T_8 * V_239 )
{
bool V_367 = 1 ;
struct V_338 * V_339 = V_353 -> V_357 ;
do {
int V_94 ;
if ( ! F_78 ( & V_339 -> V_345 [ 0 ] , V_81 , V_239 ) )
return 0 ;
if ( V_367 && ! F_78 ( & V_353 -> V_296 , V_81 , V_239 ) )
return 0 ;
if ( V_367 && ! F_78 ( & V_353 -> V_365 , V_81 , V_239 ) )
return 0 ;
if ( V_367 && ! F_78 ( & V_353 -> V_310 , V_81 , V_239 ) )
return 0 ;
if ( V_367 && ! F_78 ( & V_353 -> V_366 , V_81 , V_239 ) )
return 0 ;
for ( V_94 = 1 ; V_94 < V_353 -> V_359 ; ++ V_94 )
if ( V_339 -> V_345 [ V_94 ] . V_244 &&
! F_78 ( & V_339 -> V_345 [ V_94 ] , V_81 , V_239 ) )
return 0 ;
V_367 = 0 ;
V_339 = V_339 -> V_363 ;
} while ( V_339 );
return 1 ;
}
static void F_121 ( struct V_352 * V_353 )
{
struct V_338 * V_368 = V_353 -> V_357 ;
while ( V_368 ) {
unsigned int V_94 ;
struct V_338 * V_339 = V_368 ;
V_368 = V_339 -> V_363 ;
F_116 ( V_339 -> V_345 [ 0 ] . V_244 && V_339 -> V_345 [ 0 ] . V_244 != & V_339 -> V_269 ) ;
for ( V_94 = 1 ; V_94 < V_353 -> V_359 ; ++ V_94 )
F_35 ( V_339 -> V_345 [ V_94 ] . V_244 ) ;
F_35 ( V_339 ) ;
}
F_35 ( V_353 -> V_296 . V_244 ) ;
F_106 ( V_353 -> V_366 . V_244 ) ;
}
static int F_122 ( long V_271 , struct V_369 * V_339 )
{
int V_235 = 0 ;
struct V_270 * V_19 = V_339 -> V_357 ;
V_339 -> V_370 = 0 ;
F_82 ( & V_339 -> V_269 , V_19 , V_271 ) ;
F_123 ( V_19 , & V_339 -> V_269 . V_344 ) ;
F_81 ( & V_339 -> V_345 [ 0 ] , L_2 , V_346 , sizeof( V_339 -> V_269 ) ,
& ( V_339 -> V_269 ) ) ;
V_339 -> V_370 ++ ;
V_235 += F_74 ( & V_339 -> V_345 [ 0 ] ) ;
if ( ( V_339 -> V_269 . V_371 = F_124 ( V_19 , NULL ,
& V_339 -> V_372 ) ) ) {
F_81 ( & V_339 -> V_345 [ 1 ] , L_2 , V_350 , sizeof( V_339 -> V_372 ) ,
& ( V_339 -> V_372 ) ) ;
V_339 -> V_370 ++ ;
V_235 += F_74 ( & V_339 -> V_345 [ 1 ] ) ;
}
#ifdef F_125
if ( F_126 ( V_19 , & V_339 -> V_373 ) ) {
F_81 ( & V_339 -> V_345 [ 2 ] , L_3 , V_374 ,
sizeof( V_339 -> V_373 ) , & V_339 -> V_373 ) ;
V_339 -> V_370 ++ ;
V_235 += F_74 ( & V_339 -> V_345 [ 2 ] ) ;
}
#endif
return V_235 ;
}
static int F_127 ( struct V_352 * V_353 )
{
memset ( V_353 , 0 , sizeof( * V_353 ) ) ;
F_128 ( & V_353 -> V_375 ) ;
V_353 -> V_345 = F_33 ( 8 * sizeof( struct V_233 ) , V_115 ) ;
if ( ! V_353 -> V_345 )
return 0 ;
V_353 -> V_296 = F_33 ( sizeof( * V_353 -> V_296 ) , V_115 ) ;
if ( ! V_353 -> V_296 )
return 0 ;
V_353 -> V_269 = F_33 ( sizeof( * V_353 -> V_269 ) , V_115 ) ;
if ( ! V_353 -> V_269 )
return 0 ;
V_353 -> V_372 = F_33 ( sizeof( * V_353 -> V_372 ) , V_115 ) ;
if ( ! V_353 -> V_372 )
return 0 ;
#ifdef F_125
V_353 -> V_373 = F_33 ( sizeof( * V_353 -> V_373 ) , V_115 ) ;
if ( ! V_353 -> V_373 )
return 0 ;
#endif
return 1 ;
}
static int F_114 ( struct V_15 * V_245 , int V_351 ,
struct V_352 * V_353 ,
T_12 * V_314 , struct V_142 * V_143 )
{
struct V_376 * V_339 ;
if ( ! F_127 ( V_353 ) )
return 0 ;
if ( V_314 -> V_273 ) {
struct V_355 * V_356 ;
struct V_369 * V_377 ;
for ( V_356 = V_4 -> V_5 -> V_361 -> V_362 . V_363 ;
V_356 ; V_356 = V_356 -> V_363 ) {
V_377 = F_117 ( sizeof( * V_377 ) , V_115 ) ;
if ( ! V_377 )
return 0 ;
V_377 -> V_357 = V_356 -> V_334 ;
F_129 ( & V_377 -> V_378 , & V_353 -> V_375 ) ;
}
F_130 (t, &info->thread_list) {
int V_235 ;
V_377 = F_131 ( V_339 , struct V_369 , V_378 ) ;
V_235 = F_122 ( V_314 -> V_273 , V_377 ) ;
V_353 -> V_379 += V_235 ;
}
}
memset ( V_353 -> V_269 , 0 , sizeof( * V_353 -> V_269 ) ) ;
F_82 ( V_353 -> V_269 , V_4 , V_314 -> V_273 ) ;
F_132 ( & V_353 -> V_269 -> V_344 , V_143 ) ;
F_79 ( V_245 , V_351 , V_380 , V_381 , V_256 ) ;
F_81 ( V_353 -> V_345 + 0 , L_2 , V_346 ,
sizeof( * V_353 -> V_269 ) , V_353 -> V_269 ) ;
F_92 ( V_353 -> V_296 , V_4 -> V_364 , V_4 -> V_5 ) ;
F_81 ( V_353 -> V_345 + 1 , L_2 , V_358 ,
sizeof( * V_353 -> V_296 ) , V_353 -> V_296 ) ;
F_100 ( V_353 -> V_345 + 2 , & V_353 -> V_313 , V_314 ) ;
F_99 ( V_353 -> V_345 + 3 , V_4 -> V_5 ) ;
F_102 ( V_353 -> V_345 + 4 ) ;
V_353 -> V_382 = 5 ;
V_353 -> V_269 -> V_371 = F_124 ( V_4 , V_143 ,
V_353 -> V_372 ) ;
if ( V_353 -> V_269 -> V_371 )
F_81 ( V_353 -> V_345 + V_353 -> V_382 ++ ,
L_2 , V_350 , sizeof( * V_353 -> V_372 ) , V_353 -> V_372 ) ;
#ifdef F_125
if ( F_126 ( V_4 , V_353 -> V_373 ) )
F_81 ( V_353 -> V_345 + V_353 -> V_382 ++ ,
L_3 , V_374 ,
sizeof( * V_353 -> V_373 ) , V_353 -> V_373 ) ;
#endif
return 1 ;
}
static T_2 F_119 ( struct V_352 * V_353 )
{
int V_235 = 0 ;
int V_94 ;
for ( V_94 = 0 ; V_94 < V_353 -> V_382 ; V_94 ++ )
V_235 += F_74 ( V_353 -> V_345 + V_94 ) ;
V_235 += V_353 -> V_379 ;
return V_235 ;
}
static int F_120 ( struct V_352 * V_353 ,
struct V_81 * V_81 , T_8 * V_239 )
{
int V_94 ;
struct V_376 * V_339 ;
for ( V_94 = 0 ; V_94 < V_353 -> V_382 ; V_94 ++ )
if ( ! F_78 ( V_353 -> V_345 + V_94 , V_81 , V_239 ) )
return 0 ;
F_130 (t, &info->thread_list) {
struct V_369 * V_383 =
F_131 ( V_339 , struct V_369 , V_378 ) ;
for ( V_94 = 0 ; V_94 < V_383 -> V_370 ; V_94 ++ )
if ( ! F_78 ( & V_383 -> V_345 [ V_94 ] , V_81 , V_239 ) )
return 0 ;
}
return 1 ;
}
static void F_121 ( struct V_352 * V_353 )
{
while ( ! F_133 ( & V_353 -> V_375 ) ) {
struct V_376 * V_383 = V_353 -> V_375 . V_363 ;
F_134 ( V_383 ) ;
F_35 ( F_131 ( V_383 , struct V_369 , V_378 ) ) ;
}
F_106 ( V_353 -> V_345 [ 4 ] . V_244 ) ;
F_35 ( V_353 -> V_269 ) ;
F_35 ( V_353 -> V_296 ) ;
F_35 ( V_353 -> V_345 ) ;
F_35 ( V_353 -> V_372 ) ;
#ifdef F_125
F_35 ( V_353 -> V_373 ) ;
#endif
}
static struct V_37 * F_135 ( struct V_270 * V_384 ,
struct V_37 * V_385 )
{
struct V_37 * V_349 = V_384 -> V_5 -> V_113 ;
if ( V_349 )
return V_349 ;
return V_385 ;
}
static struct V_37 * F_136 ( struct V_37 * V_386 ,
struct V_37 * V_385 )
{
struct V_37 * V_349 ;
V_349 = V_386 -> V_329 ;
if ( V_349 )
return V_349 ;
if ( V_386 == V_385 )
return NULL ;
return V_385 ;
}
static void F_137 ( struct V_15 * V_245 , struct V_387 * V_388 ,
T_1 V_389 , int V_246 )
{
V_245 -> V_389 = V_389 ;
V_245 -> V_390 = sizeof( * V_388 ) ;
V_245 -> V_391 = 1 ;
V_245 -> V_392 = V_393 ;
memset ( V_388 , 0 , sizeof( * V_388 ) ) ;
V_388 -> V_394 = V_395 ;
V_388 -> V_396 = V_245 -> V_391 ;
V_388 -> V_397 = V_245 -> V_392 ;
V_388 -> V_398 = V_246 ;
}
static T_2 F_138 ( struct V_37 * V_385 ,
unsigned long V_194 )
{
struct V_37 * V_38 ;
T_2 V_87 = 0 ;
for ( V_38 = F_135 ( V_4 , V_385 ) ; V_38 != NULL ;
V_38 = F_136 ( V_38 , V_385 ) )
V_87 += F_68 ( V_38 , V_194 ) ;
return V_87 ;
}
static int F_139 ( struct V_399 * V_400 )
{
int V_401 = 0 ;
T_7 V_219 ;
int V_246 ;
T_2 V_87 = 0 ;
struct V_37 * V_38 , * V_385 ;
struct V_15 * V_245 = NULL ;
T_8 V_263 = 0 , V_402 , V_239 ;
struct V_352 V_353 ;
struct V_50 * V_403 = NULL ;
struct V_387 * V_388 = NULL ;
T_14 V_52 ;
T_1 V_389 ;
V_245 = F_33 ( sizeof( * V_245 ) , V_115 ) ;
if ( ! V_245 )
goto V_111;
V_246 = V_4 -> V_5 -> V_325 ;
V_246 += F_140 () ;
V_385 = F_66 ( V_4 -> V_5 ) ;
if ( V_385 != NULL )
V_246 ++ ;
V_246 ++ ;
V_52 = V_246 > V_404 ? V_404 : V_246 ;
if ( ! F_114 ( V_245 , V_52 , & V_353 , V_400 -> V_314 , V_400 -> V_143 ) )
goto V_405;
V_401 = 1 ;
V_4 -> V_136 |= V_406 ;
V_219 = F_70 () ;
F_72 ( V_316 ) ;
V_263 += sizeof( * V_245 ) ;
V_263 += V_246 * sizeof( struct V_50 ) ;
V_239 = V_263 ;
{
T_2 V_235 = F_119 ( & V_353 ) ;
V_235 += F_141 () ;
V_403 = F_33 ( sizeof( * V_403 ) , V_115 ) ;
if ( ! V_403 )
goto V_407;
F_80 ( V_403 , V_235 , V_263 ) ;
V_263 += V_235 ;
}
V_402 = V_263 = F_75 ( V_263 , V_44 ) ;
V_263 += F_138 ( V_385 , V_400 -> V_194 ) ;
V_263 += F_142 () ;
V_389 = V_263 ;
if ( V_52 == V_404 ) {
V_388 = F_33 ( sizeof( * V_388 ) , V_115 ) ;
if ( ! V_388 )
goto V_407;
F_137 ( V_245 , V_388 , V_389 , V_246 ) ;
}
V_263 = V_402 ;
V_87 += sizeof( * V_245 ) ;
if ( V_87 > V_400 -> V_408 || ! F_143 ( V_400 -> V_81 , V_245 , sizeof( * V_245 ) ) )
goto V_407;
V_87 += sizeof( * V_403 ) ;
if ( V_87 > V_400 -> V_408
|| ! F_143 ( V_400 -> V_81 , V_403 , sizeof( * V_403 ) ) )
goto V_407;
for ( V_38 = F_135 ( V_4 , V_385 ) ; V_38 != NULL ;
V_38 = F_136 ( V_38 , V_385 ) ) {
struct V_50 V_262 ;
V_262 . V_97 = V_98 ;
V_262 . V_91 = V_263 ;
V_262 . V_89 = V_38 -> V_217 ;
V_262 . V_265 = 0 ;
V_262 . V_88 = F_68 ( V_38 , V_400 -> V_194 ) ;
V_262 . V_99 = V_38 -> V_232 - V_38 -> V_217 ;
V_263 += V_262 . V_88 ;
V_262 . V_124 = V_38 -> V_196 & V_215 ? V_125 : 0 ;
if ( V_38 -> V_196 & V_409 )
V_262 . V_124 |= V_127 ;
if ( V_38 -> V_196 & V_410 )
V_262 . V_124 |= V_129 ;
V_262 . V_266 = V_44 ;
V_87 += sizeof( V_262 ) ;
if ( V_87 > V_400 -> V_408
|| ! F_143 ( V_400 -> V_81 , & V_262 , sizeof( V_262 ) ) )
goto V_407;
}
if ( ! F_144 ( V_400 -> V_81 , V_263 , & V_87 , V_400 -> V_408 ) )
goto V_407;
if ( ! F_120 ( & V_353 , V_400 -> V_81 , & V_239 ) )
goto V_407;
if ( F_145 ( V_400 -> V_81 , & V_239 ) )
goto V_407;
if ( ! F_146 ( V_400 -> V_81 , V_402 - V_239 ) )
goto V_407;
for ( V_38 = F_135 ( V_4 , V_385 ) ; V_38 != NULL ;
V_38 = F_136 ( V_38 , V_385 ) ) {
unsigned long V_3 ;
unsigned long V_2 ;
V_2 = V_38 -> V_217 + F_68 ( V_38 , V_400 -> V_194 ) ;
for ( V_3 = V_38 -> V_217 ; V_3 < V_2 ; V_3 += V_190 ) {
struct V_411 * V_411 ;
int V_412 ;
V_411 = F_147 ( V_3 ) ;
if ( V_411 ) {
void * V_413 = F_148 ( V_411 ) ;
V_412 = ( ( V_87 += V_190 ) > V_400 -> V_408 ) ||
! F_143 ( V_400 -> V_81 , V_413 ,
V_190 ) ;
F_149 ( V_411 ) ;
F_150 ( V_411 ) ;
} else
V_412 = ! F_146 ( V_400 -> V_81 , V_190 ) ;
if ( V_412 )
goto V_407;
}
}
if ( ! F_151 ( V_400 -> V_81 , & V_87 , V_400 -> V_408 ) )
goto V_407;
if ( V_52 == V_404 ) {
V_87 += sizeof( * V_388 ) ;
if ( V_87 > V_400 -> V_408
|| ! F_143 ( V_400 -> V_81 , V_388 ,
sizeof( * V_388 ) ) )
goto V_407;
}
V_407:
F_72 ( V_219 ) ;
V_405:
F_121 ( & V_353 ) ;
F_35 ( V_388 ) ;
F_35 ( V_403 ) ;
F_35 ( V_245 ) ;
V_111:
return V_401 ;
}
static int T_15 F_152 ( void )
{
F_153 ( & V_187 ) ;
return 0 ;
}
static void T_16 F_154 ( void )
{
F_155 ( & V_187 ) ;
}
