static int F_1 ( unsigned long V_1 , unsigned long V_2 )
{
V_1 = F_2 ( V_1 ) ;
V_2 = F_2 ( V_2 ) ;
if ( V_2 > V_1 ) {
unsigned long V_3 ;
F_3 ( & V_4 -> V_5 -> V_6 ) ;
V_3 = F_4 ( V_1 , V_2 - V_1 ) ;
F_5 ( & V_4 -> V_5 -> V_6 ) ;
if ( F_6 ( V_3 ) )
return V_3 ;
}
V_4 -> V_5 -> V_7 = V_4 -> V_5 -> V_8 = V_2 ;
return 0 ;
}
static int F_7 ( unsigned long V_9 )
{
unsigned long V_10 ;
V_10 = F_8 ( V_9 ) ;
if ( V_10 ) {
V_10 = V_11 - V_10 ;
if ( F_9 ( ( void V_12 * ) V_9 , V_10 ) )
return - V_13 ;
}
return 0 ;
}
static int
F_10 ( struct V_14 * V_15 , struct V_16 * V_17 ,
unsigned long V_18 , unsigned long V_19 )
{
unsigned long V_20 = V_15 -> V_20 ;
int V_21 = V_15 -> V_21 ;
int V_22 = V_15 -> V_22 ;
T_1 V_12 * V_23 ;
T_1 V_12 * V_24 ;
T_1 V_12 * V_25 ;
T_1 V_12 * V_26 ;
T_1 V_12 * V_27 ;
T_1 V_12 * V_28 ;
const char * V_29 = V_30 ;
const char * V_31 = V_32 ;
unsigned char V_33 [ 16 ] ;
int V_34 ;
T_1 * V_35 ;
int V_36 = 0 ;
const struct V_37 * V_37 = F_11 () ;
struct V_38 * V_39 ;
V_20 = F_12 ( V_20 ) ;
V_26 = NULL ;
if ( V_29 ) {
T_2 V_40 = strlen ( V_29 ) + 1 ;
V_26 = ( T_1 V_12 * ) F_13 ( V_20 , V_40 ) ;
if ( F_14 ( V_26 , V_29 , V_40 ) )
return - V_13 ;
}
V_27 = NULL ;
if ( V_31 ) {
T_2 V_40 = strlen ( V_31 ) + 1 ;
V_27 = ( T_1 V_12 * ) F_13 ( V_20 , V_40 ) ;
if ( F_14 ( V_27 , V_31 , V_40 ) )
return - V_13 ;
}
F_15 ( V_33 , sizeof( V_33 ) ) ;
V_28 = ( T_1 V_12 * )
F_13 ( V_20 , sizeof( V_33 ) ) ;
if ( F_14 ( V_28 , V_33 , sizeof( V_33 ) ) )
return - V_13 ;
V_35 = ( T_1 * ) V_4 -> V_5 -> V_41 ;
#define F_16 ( T_3 , T_4 ) \
do { \
elf_info[ei_index++] = id; \
elf_info[ei_index++] = val; \
} while (0)
#ifdef F_17
F_17 ;
#endif
F_16 ( V_42 , V_43 ) ;
F_16 ( V_44 , V_45 ) ;
F_16 ( V_46 , V_47 ) ;
F_16 ( V_48 , V_18 + V_17 -> V_49 ) ;
F_16 ( V_50 , sizeof( struct V_51 ) ) ;
F_16 ( V_52 , V_17 -> V_53 ) ;
F_16 ( V_54 , V_19 ) ;
F_16 ( V_55 , 0 ) ;
F_16 ( V_56 , V_17 -> V_57 ) ;
F_16 ( V_58 , V_37 -> V_59 ) ;
F_16 ( V_60 , V_37 -> V_61 ) ;
F_16 ( V_62 , V_37 -> V_63 ) ;
F_16 ( V_64 , V_37 -> V_65 ) ;
F_16 ( V_66 , F_18 ( V_15 ) ) ;
F_16 ( V_67 , ( T_1 ) ( unsigned long ) V_28 ) ;
F_16 ( V_68 , V_15 -> V_17 ) ;
if ( V_29 ) {
F_16 ( V_69 ,
( T_1 ) ( unsigned long ) V_26 ) ;
}
if ( V_31 ) {
F_16 ( V_70 ,
( T_1 ) ( unsigned long ) V_27 ) ;
}
if ( V_15 -> V_71 & V_72 ) {
F_16 ( V_73 , V_15 -> V_74 ) ;
}
#undef F_16
memset ( & V_35 [ V_36 ] , 0 ,
sizeof V_4 -> V_5 -> V_41 - V_36 * sizeof V_35 [ 0 ] ) ;
V_36 += 2 ;
V_25 = F_19 ( V_20 , V_36 ) ;
V_34 = ( V_21 + 1 ) + ( V_22 + 1 ) + 1 ;
V_15 -> V_20 = F_20 ( V_25 , V_34 ) ;
#ifdef F_21
V_25 = ( T_1 V_12 * ) V_15 -> V_20 - V_34 - V_36 ;
V_15 -> V_17 = ( unsigned long ) V_25 ;
#else
V_25 = ( T_1 V_12 * ) V_15 -> V_20 ;
#endif
V_39 = F_22 ( V_4 -> V_5 , V_15 -> V_20 ) ;
if ( ! V_39 )
return - V_13 ;
if ( F_23 ( V_21 , V_25 ++ ) )
return - V_13 ;
V_23 = V_25 ;
V_24 = V_23 + V_21 + 1 ;
V_20 = V_4 -> V_5 -> V_75 = V_4 -> V_5 -> V_76 ;
while ( V_21 -- > 0 ) {
T_2 V_40 ;
if ( F_23 ( ( T_1 ) V_20 , V_23 ++ ) )
return - V_13 ;
V_40 = F_24 ( ( void V_12 * ) V_20 , V_77 ) ;
if ( ! V_40 || V_40 > V_77 )
return - V_78 ;
V_20 += V_40 ;
}
if ( F_23 ( 0 , V_23 ) )
return - V_13 ;
V_4 -> V_5 -> V_75 = V_4 -> V_5 -> V_79 = V_20 ;
while ( V_22 -- > 0 ) {
T_2 V_40 ;
if ( F_23 ( ( T_1 ) V_20 , V_24 ++ ) )
return - V_13 ;
V_40 = F_24 ( ( void V_12 * ) V_20 , V_77 ) ;
if ( ! V_40 || V_40 > V_77 )
return - V_78 ;
V_20 += V_40 ;
}
if ( F_23 ( 0 , V_24 ) )
return - V_13 ;
V_4 -> V_5 -> V_80 = V_20 ;
V_25 = ( T_1 V_12 * ) V_24 + 1 ;
if ( F_25 ( V_25 , V_35 , V_36 * sizeof( T_1 ) ) )
return - V_13 ;
return 0 ;
}
static unsigned long F_26 ( struct V_81 * V_82 , unsigned long V_3 ,
struct V_51 * V_83 , int V_84 , int type ,
unsigned long V_85 )
{
unsigned long V_86 ;
unsigned long V_87 = V_83 -> V_88 + F_8 ( V_83 -> V_89 ) ;
unsigned long V_90 = V_83 -> V_91 - F_8 ( V_83 -> V_89 ) ;
V_3 = F_27 ( V_3 ) ;
V_87 = F_2 ( V_87 ) ;
if ( ! V_87 )
return V_3 ;
F_3 ( & V_4 -> V_5 -> V_6 ) ;
if ( V_85 ) {
V_85 = F_2 ( V_85 ) ;
V_86 = F_28 ( V_82 , V_3 , V_85 , V_84 , type , V_90 ) ;
if ( ! F_6 ( V_86 ) )
F_29 ( V_4 -> V_5 , V_86 + V_87 , V_85 - V_87 ) ;
} else
V_86 = F_28 ( V_82 , V_3 , V_87 , V_84 , type , V_90 ) ;
F_5 ( & V_4 -> V_5 -> V_6 ) ;
return ( V_86 ) ;
}
static unsigned long F_30 ( struct V_51 * V_92 , int V_93 )
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
static unsigned long F_31 ( struct V_16 * V_100 ,
struct V_81 * V_101 , unsigned long * V_102 ,
unsigned long V_103 )
{
struct V_51 * V_104 ;
struct V_51 * V_83 ;
unsigned long V_18 = 0 ;
int V_105 = 0 ;
unsigned long V_106 = 0 , V_9 = 0 ;
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
if ( V_100 -> V_114 != sizeof( struct V_51 ) )
goto V_111;
if ( V_100 -> V_53 < 1 ||
V_100 -> V_53 > 65536U / sizeof( struct V_51 ) )
goto V_111;
V_87 = sizeof( struct V_51 ) * V_100 -> V_53 ;
if ( V_87 > V_11 )
goto V_111;
V_104 = F_33 ( V_87 , V_115 ) ;
if ( ! V_104 )
goto V_111;
V_107 = F_34 ( V_101 , V_100 -> V_49 ,
( char * ) V_104 , V_87 ) ;
error = - V_116 ;
if ( V_107 != V_87 ) {
if ( V_107 < 0 )
error = V_107 ;
goto V_117;
}
V_85 = F_30 ( V_104 , V_100 -> V_53 ) ;
if ( ! V_85 ) {
error = - V_78 ;
goto V_117;
}
V_83 = V_104 ;
for ( V_94 = 0 ; V_94 < V_100 -> V_53 ; V_94 ++ , V_83 ++ ) {
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
V_18 = - V_122 ;
V_86 = F_26 ( V_101 , V_18 + V_122 ,
V_83 , V_121 , V_118 , V_85 ) ;
V_85 = 0 ;
if ( ! * V_102 )
* V_102 = V_86 ;
error = V_86 ;
if ( F_6 ( V_86 ) )
goto V_117;
if ( ! V_105 &&
V_100 -> V_108 == V_110 ) {
V_18 = V_86 - F_27 ( V_122 ) ;
V_105 = 1 ;
}
V_123 = V_18 + V_83 -> V_89 ;
if ( F_6 ( V_123 ) ||
V_83 -> V_88 > V_83 -> V_99 ||
V_83 -> V_99 > V_132 ||
V_132 - V_83 -> V_99 < V_123 ) {
error = - V_133 ;
goto V_117;
}
V_123 = V_18 + V_83 -> V_89 + V_83 -> V_88 ;
if ( V_123 > V_9 )
V_9 = V_123 ;
V_123 = V_18 + V_83 -> V_99 + V_83 -> V_89 ;
if ( V_123 > V_106 )
V_106 = V_123 ;
}
}
if ( V_106 > V_9 ) {
if ( F_7 ( V_9 ) ) {
error = - V_13 ;
goto V_117;
}
V_9 = F_27 ( V_9 + V_11 - 1 ) ;
F_3 ( & V_4 -> V_5 -> V_6 ) ;
error = F_4 ( V_9 , V_106 - V_9 ) ;
F_5 ( & V_4 -> V_5 -> V_6 ) ;
if ( F_6 ( error ) )
goto V_117;
}
error = V_18 ;
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
static int F_39 ( struct V_14 * V_15 , struct V_142 * V_143 )
{
struct V_81 * V_101 = NULL ;
unsigned long V_18 = 0 , V_144 = 0 ;
int V_105 = 0 ;
char * V_145 = NULL ;
unsigned long error ;
struct V_51 * V_146 , * V_104 ;
unsigned long V_9 , V_147 ;
int V_107 , V_94 ;
unsigned int V_87 ;
unsigned long V_148 ;
unsigned long V_19 = 0 ;
unsigned long V_149 , V_150 , V_151 , V_152 ;
unsigned long T_5 V_153 = 0 ;
int V_154 = V_155 ;
unsigned long V_156 = 0 ;
struct {
struct V_16 V_157 ;
struct V_16 V_100 ;
} * V_158 ;
V_158 = F_33 ( sizeof( * V_158 ) , V_115 ) ;
if ( ! V_158 ) {
V_107 = - V_133 ;
goto V_159;
}
V_158 -> V_157 = * ( (struct V_16 * ) V_15 -> V_160 ) ;
V_107 = - V_161 ;
if ( memcmp ( V_158 -> V_157 . V_162 , V_163 , V_164 ) != 0 )
goto V_111;
if ( V_158 -> V_157 . V_108 != V_109 && V_158 -> V_157 . V_108 != V_110 )
goto V_111;
if ( ! F_32 ( & V_158 -> V_157 ) )
goto V_111;
if ( ! V_15 -> V_81 -> V_112 || ! V_15 -> V_81 -> V_112 -> V_113 )
goto V_111;
if ( V_158 -> V_157 . V_114 != sizeof( struct V_51 ) )
goto V_111;
if ( V_158 -> V_157 . V_53 < 1 ||
V_158 -> V_157 . V_53 > 65536U / sizeof( struct V_51 ) )
goto V_111;
V_87 = V_158 -> V_157 . V_53 * sizeof( struct V_51 ) ;
V_107 = - V_133 ;
V_104 = F_33 ( V_87 , V_115 ) ;
if ( ! V_104 )
goto V_111;
V_107 = F_34 ( V_15 -> V_81 , V_158 -> V_157 . V_49 ,
( char * ) V_104 , V_87 ) ;
if ( V_107 != V_87 ) {
if ( V_107 >= 0 )
V_107 = - V_116 ;
goto V_165;
}
V_146 = V_104 ;
V_9 = 0 ;
V_147 = 0 ;
V_149 = ~ 0UL ;
V_150 = 0 ;
V_151 = 0 ;
V_152 = 0 ;
for ( V_94 = 0 ; V_94 < V_158 -> V_157 . V_53 ; V_94 ++ ) {
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
V_107 = F_34 ( V_15 -> V_81 , V_146 -> V_91 ,
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
if ( F_43 ( V_101 , V_169 ) < 0 )
V_15 -> V_71 |= V_170 ;
V_107 = F_34 ( V_101 , 0 , V_15 -> V_160 ,
V_171 ) ;
if ( V_107 != V_171 ) {
if ( V_107 >= 0 )
V_107 = - V_116 ;
goto V_172;
}
V_158 -> V_100 = * ( (struct V_16 * ) V_15 -> V_160 ) ;
break;
}
V_146 ++ ;
}
V_146 = V_104 ;
for ( V_94 = 0 ; V_94 < V_158 -> V_157 . V_53 ; V_94 ++ , V_146 ++ )
if ( V_146 -> V_97 == V_173 ) {
if ( V_146 -> V_124 & V_129 )
V_154 = V_174 ;
else
V_154 = V_175 ;
break;
}
if ( V_145 ) {
V_107 = - V_176 ;
if ( memcmp ( V_158 -> V_100 . V_162 , V_163 , V_164 ) != 0 )
goto V_172;
if ( ! F_32 ( & V_158 -> V_100 ) )
goto V_172;
}
V_107 = F_44 ( V_15 ) ;
if ( V_107 )
goto V_172;
V_4 -> V_136 &= ~ V_177 ;
V_4 -> V_5 -> V_156 = V_156 ;
F_45 ( V_158 -> V_157 ) ;
if ( F_46 ( V_158 -> V_157 , V_154 ) )
V_4 -> V_138 |= V_178 ;
if ( ! ( V_4 -> V_138 & V_139 ) && V_179 )
V_4 -> V_136 |= V_137 ;
F_47 ( V_15 ) ;
V_4 -> V_5 -> V_180 = V_4 -> V_5 -> V_181 ;
V_4 -> V_5 -> V_182 = 0 ;
V_107 = F_48 ( V_15 , F_36 ( V_183 ) ,
V_154 ) ;
if ( V_107 < 0 ) {
F_49 ( V_184 , V_4 , 0 ) ;
goto V_172;
}
V_4 -> V_5 -> V_185 = V_15 -> V_20 ;
for( V_94 = 0 , V_146 = V_104 ;
V_94 < V_158 -> V_157 . V_53 ; V_94 ++ , V_146 ++ ) {
int V_121 = 0 , V_186 ;
unsigned long V_123 , V_122 ;
if ( V_146 -> V_97 != V_98 )
continue;
if ( F_50 ( V_147 > V_9 ) ) {
unsigned long V_10 ;
V_107 = F_1 ( V_9 + V_144 ,
V_147 + V_144 ) ;
if ( V_107 ) {
F_49 ( V_184 , V_4 , 0 ) ;
goto V_172;
}
V_10 = F_8 ( V_9 ) ;
if ( V_10 ) {
V_10 = V_11 - V_10 ;
if ( V_10 > V_147 - V_9 )
V_10 = V_147 - V_9 ;
if ( F_9 ( ( void V_12 * ) V_9 +
V_144 , V_10 ) ) {
}
}
}
if ( V_146 -> V_124 & V_125 )
V_121 |= V_126 ;
if ( V_146 -> V_124 & V_127 )
V_121 |= V_128 ;
if ( V_146 -> V_124 & V_129 )
V_121 |= V_130 ;
V_186 = V_119 | V_120 | V_187 ;
V_122 = V_146 -> V_89 ;
if ( V_158 -> V_157 . V_108 == V_109 || V_105 ) {
V_186 |= V_131 ;
} else if ( V_158 -> V_157 . V_108 == V_110 ) {
#if F_51 ( V_188 ) || F_51 ( V_189 )
V_144 = 0 ;
#else
V_144 = F_27 ( V_190 - V_122 ) ;
#endif
}
error = F_26 ( V_15 -> V_81 , V_144 + V_122 , V_146 ,
V_121 , V_186 , 0 ) ;
if ( F_6 ( error ) ) {
F_49 ( V_184 , V_4 , 0 ) ;
V_107 = F_42 ( ( void * ) error ) ?
F_41 ( ( void * ) error ) : - V_78 ;
goto V_172;
}
if ( ! V_105 ) {
V_105 = 1 ;
V_18 = ( V_146 -> V_89 - V_146 -> V_91 ) ;
if ( V_158 -> V_157 . V_108 == V_110 ) {
V_144 += error -
F_27 ( V_144 + V_122 ) ;
V_18 += V_144 ;
T_5 = V_144 ;
}
}
V_123 = V_146 -> V_89 ;
if ( V_123 < V_149 )
V_149 = V_123 ;
if ( V_151 < V_123 )
V_151 = V_123 ;
if ( F_6 ( V_123 ) || V_146 -> V_88 > V_146 -> V_99 ||
V_146 -> V_99 > V_132 ||
V_132 - V_146 -> V_99 < V_123 ) {
F_49 ( V_184 , V_4 , 0 ) ;
V_107 = - V_78 ;
goto V_172;
}
V_123 = V_146 -> V_89 + V_146 -> V_88 ;
if ( V_123 > V_9 )
V_9 = V_123 ;
if ( ( V_146 -> V_124 & V_129 ) && V_150 < V_123 )
V_150 = V_123 ;
if ( V_152 < V_123 )
V_152 = V_123 ;
V_123 = V_146 -> V_89 + V_146 -> V_99 ;
if ( V_123 > V_147 )
V_147 = V_123 ;
}
V_158 -> V_157 . V_57 += V_144 ;
V_9 += V_144 ;
V_147 += V_144 ;
V_149 += V_144 ;
V_150 += V_144 ;
V_151 += V_144 ;
V_152 += V_144 ;
V_107 = F_1 ( V_9 , V_147 ) ;
if ( V_107 ) {
F_49 ( V_184 , V_4 , 0 ) ;
goto V_172;
}
if ( F_52 ( V_9 != V_147 ) && F_50 ( F_7 ( V_9 ) ) ) {
F_49 ( V_191 , V_4 , 0 ) ;
V_107 = - V_13 ;
goto V_172;
}
if ( V_145 ) {
unsigned long V_192 ( V_102 ) ;
V_148 = F_31 ( & V_158 -> V_100 ,
V_101 ,
& V_102 ,
V_144 ) ;
if ( ! F_42 ( ( void * ) V_148 ) ) {
V_19 = V_148 ;
V_148 += V_158 -> V_100 . V_57 ;
}
if ( F_6 ( V_148 ) ) {
F_53 ( V_191 , V_4 ) ;
V_107 = F_42 ( ( void * ) V_148 ) ?
( int ) V_148 : - V_78 ;
goto V_172;
}
T_5 = V_19 ;
F_54 ( V_101 ) ;
F_55 ( V_101 ) ;
F_35 ( V_145 ) ;
} else {
V_148 = V_158 -> V_157 . V_57 ;
if ( F_6 ( V_148 ) ) {
F_53 ( V_191 , V_4 ) ;
V_107 = - V_78 ;
goto V_172;
}
}
F_35 ( V_104 ) ;
F_56 ( & V_193 ) ;
#ifdef F_57
V_107 = F_58 ( V_15 , ! ! V_145 ) ;
if ( V_107 < 0 ) {
F_49 ( V_184 , V_4 , 0 ) ;
goto V_111;
}
#endif
F_59 ( V_15 ) ;
V_4 -> V_136 &= ~ V_177 ;
V_107 = F_10 ( V_15 , & V_158 -> V_157 ,
V_18 , V_19 ) ;
if ( V_107 < 0 ) {
F_49 ( V_184 , V_4 , 0 ) ;
goto V_111;
}
V_4 -> V_5 -> V_150 = V_150 ;
V_4 -> V_5 -> V_149 = V_149 ;
V_4 -> V_5 -> V_151 = V_151 ;
V_4 -> V_5 -> V_152 = V_152 ;
V_4 -> V_5 -> V_185 = V_15 -> V_20 ;
#ifdef F_60
if ( ( V_4 -> V_136 & V_137 ) && ( V_179 > 1 ) ) {
V_4 -> V_5 -> V_8 = V_4 -> V_5 -> V_7 =
F_60 ( V_4 -> V_5 ) ;
#ifdef F_61
V_4 -> V_194 = 1 ;
#endif
}
#endif
if ( V_4 -> V_138 & V_195 ) {
F_3 ( & V_4 -> V_5 -> V_6 ) ;
error = F_28 ( NULL , 0 , V_196 , V_126 | V_130 ,
V_131 | V_119 , 0 ) ;
F_5 ( & V_4 -> V_5 -> V_6 ) ;
}
#ifdef F_62
F_62 ( V_143 , T_5 ) ;
#endif
F_63 ( V_143 , V_148 , V_15 -> V_20 ) ;
V_107 = 0 ;
V_111:
F_35 ( V_158 ) ;
V_159:
return V_107 ;
V_172:
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
struct V_51 * V_104 ;
struct V_51 * V_83 ;
unsigned long V_9 , V_197 , V_40 ;
int V_107 , error , V_94 , V_198 ;
struct V_16 V_157 ;
error = - V_161 ;
V_107 = F_34 ( V_81 , 0 , ( char * ) & V_157 , sizeof( V_157 ) ) ;
if ( V_107 != sizeof( V_157 ) )
goto V_111;
if ( memcmp ( V_157 . V_162 , V_163 , V_164 ) != 0 )
goto V_111;
if ( V_157 . V_108 != V_109 || V_157 . V_53 > 2 ||
! F_32 ( & V_157 ) || ! V_81 -> V_112 || ! V_81 -> V_112 -> V_113 )
goto V_111;
V_198 = sizeof( struct V_51 ) * V_157 . V_53 ;
error = - V_133 ;
V_104 = F_33 ( V_198 , V_115 ) ;
if ( ! V_104 )
goto V_111;
V_83 = V_104 ;
error = - V_161 ;
V_107 = F_34 ( V_81 , V_157 . V_49 , ( char * ) V_83 , V_198 ) ;
if ( V_107 != V_198 )
goto V_165;
for ( V_198 = 0 , V_94 = 0 ; V_94 < V_157 . V_53 ; V_94 ++ )
if ( ( V_83 + V_94 ) -> V_97 == V_98 )
V_198 ++ ;
if ( V_198 != 1 )
goto V_165;
while ( V_83 -> V_97 != V_98 )
V_83 ++ ;
F_3 ( & V_4 -> V_5 -> V_6 ) ;
error = F_28 ( V_81 ,
F_27 ( V_83 -> V_89 ) ,
( V_83 -> V_88 +
F_8 ( V_83 -> V_89 ) ) ,
V_126 | V_128 | V_130 ,
V_131 | V_119 | V_120 ,
( V_83 -> V_91 -
F_8 ( V_83 -> V_89 ) ) ) ;
F_5 ( & V_4 -> V_5 -> V_6 ) ;
if ( error != F_27 ( V_83 -> V_89 ) )
goto V_165;
V_9 = V_83 -> V_89 + V_83 -> V_88 ;
if ( F_7 ( V_9 ) ) {
error = - V_13 ;
goto V_165;
}
V_40 = F_27 ( V_83 -> V_88 + V_83 -> V_89 +
V_11 - 1 ) ;
V_197 = V_83 -> V_99 + V_83 -> V_89 ;
if ( V_197 > V_40 ) {
F_3 ( & V_4 -> V_5 -> V_6 ) ;
F_4 ( V_40 , V_197 - V_40 ) ;
F_5 ( & V_4 -> V_5 -> V_6 ) ;
}
error = 0 ;
V_165:
F_35 ( V_104 ) ;
V_111:
return error ;
}
static unsigned long F_65 ( struct V_38 * V_39 ,
unsigned long V_199 )
{
#define F_66 ( type ) (mm_flags & (1UL << MMF_DUMP_##type))
if ( V_39 -> V_200 & V_201 )
goto V_202;
if ( V_39 -> V_200 & V_203 ) {
if ( ( V_39 -> V_200 & V_204 ) && F_66 ( V_205 ) )
goto V_202;
if ( ! ( V_39 -> V_200 & V_204 ) && F_66 ( V_206 ) )
goto V_202;
}
if ( V_39 -> V_200 & ( V_207 | V_208 ) )
return 0 ;
if ( V_39 -> V_200 & V_204 ) {
if ( V_39 -> V_209 -> V_210 . V_211 -> V_212 -> V_213 == 0 ?
F_66 ( V_214 ) : F_66 ( V_215 ) )
goto V_202;
return 0 ;
}
if ( V_39 -> V_216 && F_66 ( V_217 ) )
goto V_202;
if ( V_39 -> V_209 == NULL )
return 0 ;
if ( F_66 ( V_218 ) )
goto V_202;
if ( F_66 ( V_219 ) &&
V_39 -> V_220 == 0 && ( V_39 -> V_200 & V_221 ) ) {
T_6 V_12 * V_222 = ( T_6 V_12 * ) V_39 -> V_223 ;
T_6 V_224 ;
T_7 V_225 = F_67 () ;
union {
T_6 V_226 ;
char V_227 [ V_164 ] ;
} V_228 ;
F_68 ( V_164 != sizeof V_224 ) ;
V_228 . V_227 [ V_229 ] = V_230 ;
V_228 . V_227 [ V_231 ] = V_232 ;
V_228 . V_227 [ V_233 ] = V_234 ;
V_228 . V_227 [ V_235 ] = V_236 ;
F_69 ( V_237 ) ;
if ( F_50 ( F_70 ( V_224 , V_222 ) ) )
V_224 = 0 ;
F_69 ( V_225 ) ;
if ( V_224 == V_228 . V_226 )
return V_196 ;
}
#undef F_66
return 0 ;
V_202:
return V_39 -> V_238 - V_39 -> V_223 ;
}
static int F_71 ( struct V_239 * V_240 )
{
int V_241 ;
V_241 = sizeof( struct V_242 ) ;
V_241 += F_72 ( strlen ( V_240 -> V_243 ) + 1 , 4 ) ;
V_241 += F_72 ( V_240 -> V_244 , 4 ) ;
return V_241 ;
}
static int F_73 ( struct V_81 * V_81 , T_8 * V_245 )
{
static const char V_160 [ 4 ] = { 0 , } ;
F_74 ( V_160 , F_72 ( * V_245 , 4 ) - * V_245 , V_245 ) ;
return 1 ;
}
static int F_75 ( struct V_239 * V_246 , struct V_81 * V_81 ,
T_8 * V_245 )
{
struct V_242 V_240 ;
V_240 . V_247 = strlen ( V_246 -> V_243 ) + 1 ;
V_240 . V_248 = V_246 -> V_244 ;
V_240 . V_249 = V_246 -> type ;
F_74 ( & V_240 , sizeof( V_240 ) , V_245 ) ;
F_74 ( V_246 -> V_243 , V_240 . V_247 , V_245 ) ;
if ( ! F_73 ( V_81 , V_245 ) )
return 0 ;
F_74 ( V_246 -> V_250 , V_246 -> V_244 , V_245 ) ;
if ( ! F_73 ( V_81 , V_245 ) )
return 0 ;
return 1 ;
}
static void F_76 ( struct V_16 * V_251 , int V_252 ,
T_9 V_253 , T_6 V_136 , T_10 V_254 )
{
memset ( V_251 , 0 , sizeof( * V_251 ) ) ;
memcpy ( V_251 -> V_162 , V_163 , V_164 ) ;
V_251 -> V_162 [ V_255 ] = V_256 ;
V_251 -> V_162 [ V_257 ] = V_258 ;
V_251 -> V_162 [ V_259 ] = V_260 ;
V_251 -> V_162 [ V_261 ] = V_262 ;
V_251 -> V_108 = V_263 ;
V_251 -> V_264 = V_253 ;
V_251 -> V_265 = V_260 ;
V_251 -> V_49 = sizeof( struct V_16 ) ;
V_251 -> V_266 = V_136 ;
V_251 -> V_267 = sizeof( struct V_16 ) ;
V_251 -> V_114 = sizeof( struct V_51 ) ;
V_251 -> V_53 = V_252 ;
return;
}
static void F_77 ( struct V_51 * V_268 , int V_241 , T_8 V_269 )
{
V_268 -> V_97 = V_270 ;
V_268 -> V_91 = V_269 ;
V_268 -> V_89 = 0 ;
V_268 -> V_271 = 0 ;
V_268 -> V_88 = V_241 ;
V_268 -> V_99 = 0 ;
V_268 -> V_124 = 0 ;
V_268 -> V_272 = 0 ;
return;
}
static void F_78 ( struct V_239 * V_273 , const char * V_243 , int type ,
unsigned int V_241 , void * V_250 )
{
V_273 -> V_243 = V_243 ;
V_273 -> type = type ;
V_273 -> V_244 = V_241 ;
V_273 -> V_250 = V_250 ;
return;
}
static void F_79 ( struct V_274 * V_275 ,
struct V_276 * V_20 , long V_277 )
{
V_275 -> V_278 . V_279 = V_275 -> V_280 = V_277 ;
V_275 -> V_281 = V_20 -> V_282 . signal . V_283 [ 0 ] ;
V_275 -> V_284 = V_20 -> V_285 . V_283 [ 0 ] ;
F_80 () ;
V_275 -> V_286 = F_81 ( F_82 ( V_20 -> V_287 ) ) ;
F_83 () ;
V_275 -> V_288 = F_81 ( V_20 ) ;
V_275 -> V_289 = F_84 ( V_20 ) ;
V_275 -> V_290 = F_85 ( V_20 ) ;
if ( F_86 ( V_20 ) ) {
struct V_291 V_292 ;
F_87 ( V_20 , & V_292 ) ;
F_88 ( V_292 . V_293 , & V_275 -> V_294 ) ;
F_88 ( V_292 . V_295 , & V_275 -> V_296 ) ;
} else {
F_88 ( V_20 -> V_293 , & V_275 -> V_294 ) ;
F_88 ( V_20 -> V_295 , & V_275 -> V_296 ) ;
}
F_88 ( V_20 -> signal -> V_297 , & V_275 -> V_298 ) ;
F_88 ( V_20 -> signal -> V_299 , & V_275 -> V_300 ) ;
}
static int F_89 ( struct V_301 * V_302 , struct V_276 * V_20 ,
struct V_303 * V_5 )
{
const struct V_37 * V_37 ;
unsigned int V_94 , V_40 ;
memset ( V_302 , 0 , sizeof( struct V_301 ) ) ;
V_40 = V_5 -> V_75 - V_5 -> V_76 ;
if ( V_40 >= V_304 )
V_40 = V_304 - 1 ;
if ( F_90 ( & V_302 -> V_305 ,
( const char V_12 * ) V_5 -> V_76 , V_40 ) )
return - V_13 ;
for( V_94 = 0 ; V_94 < V_40 ; V_94 ++ )
if ( V_302 -> V_305 [ V_94 ] == 0 )
V_302 -> V_305 [ V_94 ] = ' ' ;
V_302 -> V_305 [ V_40 ] = 0 ;
F_80 () ;
V_302 -> V_286 = F_81 ( F_82 ( V_20 -> V_287 ) ) ;
F_83 () ;
V_302 -> V_288 = F_81 ( V_20 ) ;
V_302 -> V_289 = F_84 ( V_20 ) ;
V_302 -> V_290 = F_85 ( V_20 ) ;
V_94 = V_20 -> V_306 ? F_91 ( ~ V_20 -> V_306 ) + 1 : 0 ;
V_302 -> V_307 = V_94 ;
V_302 -> V_308 = ( V_94 > 5 ) ? '.' : L_1 [ V_94 ] ;
V_302 -> V_309 = V_302 -> V_308 == 'Z' ;
V_302 -> V_310 = F_92 ( V_20 ) ;
V_302 -> V_311 = V_20 -> V_136 ;
F_80 () ;
V_37 = F_93 ( V_20 ) ;
F_94 ( V_302 -> V_312 , V_37 -> V_59 ) ;
F_95 ( V_302 -> V_313 , V_37 -> V_63 ) ;
F_83 () ;
strncpy ( V_302 -> V_314 , V_20 -> V_315 , sizeof( V_302 -> V_314 ) ) ;
return 0 ;
}
static void F_96 ( struct V_239 * V_273 , struct V_303 * V_5 )
{
T_1 * V_316 = ( T_1 * ) V_5 -> V_41 ;
int V_94 = 0 ;
do
V_94 += 2 ;
while ( V_316 [ V_94 - 2 ] != V_317 );
F_78 ( V_273 , L_2 , V_318 , V_94 * sizeof( T_1 ) , V_316 ) ;
}
static void F_97 ( struct V_276 * V_319 ,
const struct V_320 * V_321 )
{
if ( V_321 -> V_322 )
V_321 -> V_322 ( V_319 , V_321 , 1 ) ;
}
static int F_98 ( struct V_323 * V_324 ,
const struct V_325 * V_326 ,
long V_277 , T_2 * V_327 )
{
unsigned int V_94 ;
F_79 ( & V_324 -> V_275 , V_324 -> V_319 , V_277 ) ;
( void ) V_326 -> V_328 [ 0 ] . F_99 ( V_324 -> V_319 , & V_326 -> V_328 [ 0 ] ,
0 , sizeof( V_324 -> V_275 . V_329 ) ,
& V_324 -> V_275 . V_329 , NULL ) ;
F_78 ( & V_324 -> V_330 [ 0 ] , L_2 , V_331 ,
sizeof( V_324 -> V_275 ) , & V_324 -> V_275 ) ;
* V_327 += F_71 ( & V_324 -> V_330 [ 0 ] ) ;
F_97 ( V_324 -> V_319 , & V_326 -> V_328 [ 0 ] ) ;
for ( V_94 = 1 ; V_94 < V_326 -> V_332 ; ++ V_94 ) {
const struct V_320 * V_321 = & V_326 -> V_328 [ V_94 ] ;
F_97 ( V_324 -> V_319 , V_321 ) ;
if ( V_321 -> V_333 &&
( ! V_321 -> V_334 || V_321 -> V_334 ( V_324 -> V_319 , V_321 ) ) ) {
int V_335 ;
T_2 V_87 = V_321 -> V_332 * V_321 -> V_87 ;
void * V_250 = F_33 ( V_87 , V_115 ) ;
if ( F_50 ( ! V_250 ) )
return 0 ;
V_335 = V_321 -> F_99 ( V_324 -> V_319 , V_321 ,
0 , V_87 , V_250 , NULL ) ;
if ( F_50 ( V_335 ) )
F_35 ( V_250 ) ;
else {
if ( V_321 -> V_333 != V_336 )
F_78 ( & V_324 -> V_330 [ V_94 ] , L_3 ,
V_321 -> V_333 ,
V_87 , V_250 ) ;
else {
V_324 -> V_275 . V_337 = 1 ;
F_78 ( & V_324 -> V_330 [ V_94 ] , L_2 ,
V_336 , V_87 , V_250 ) ;
}
* V_327 += F_71 ( & V_324 -> V_330 [ V_94 ] ) ;
}
}
}
return 1 ;
}
static int F_100 ( struct V_16 * V_251 , int V_338 ,
struct V_339 * V_340 ,
long V_277 , struct V_142 * V_143 )
{
struct V_276 * V_341 = V_4 ;
const struct V_325 * V_326 = F_101 ( V_341 ) ;
struct V_323 * V_324 ;
struct V_301 * V_302 ;
struct V_342 * V_343 ;
unsigned int V_94 ;
V_340 -> V_87 = 0 ;
V_340 -> V_344 = NULL ;
V_302 = F_33 ( sizeof( * V_302 ) , V_115 ) ;
if ( V_302 == NULL )
return 0 ;
F_78 ( & V_340 -> V_302 , L_2 , V_345 , sizeof( * V_302 ) , V_302 ) ;
V_340 -> V_346 = 0 ;
for ( V_94 = 0 ; V_94 < V_326 -> V_332 ; ++ V_94 )
if ( V_326 -> V_328 [ V_94 ] . V_333 != 0 )
++ V_340 -> V_346 ;
if ( F_50 ( V_340 -> V_346 == 0 ) ||
F_50 ( V_326 -> V_328 [ 0 ] . V_333 != V_331 ) ) {
F_102 ( 1 ) ;
return 0 ;
}
F_76 ( V_251 , V_338 ,
V_326 -> V_264 , V_326 -> V_266 , V_326 -> V_347 ) ;
for ( V_343 = & V_341 -> V_5 -> V_348 -> V_349 ; V_343 ; V_343 = V_343 -> V_350 ) {
V_324 = F_103 ( F_104 ( struct V_323 ,
V_330 [ V_340 -> V_346 ] ) ,
V_115 ) ;
if ( F_50 ( ! V_324 ) )
return 0 ;
V_324 -> V_319 = V_343 -> V_319 ;
if ( V_343 -> V_319 == V_341 || ! V_340 -> V_344 ) {
V_324 -> V_350 = V_340 -> V_344 ;
V_340 -> V_344 = V_324 ;
} else {
V_324 -> V_350 = V_340 -> V_344 -> V_350 ;
V_340 -> V_344 -> V_350 = V_324 ;
}
}
for ( V_324 = V_340 -> V_344 ; V_324 != NULL ; V_324 = V_324 -> V_350 )
if ( ! F_98 ( V_324 , V_326 , V_277 , & V_340 -> V_87 ) )
return 0 ;
F_89 ( V_302 , V_341 -> V_351 , V_341 -> V_5 ) ;
V_340 -> V_87 += F_71 ( & V_340 -> V_302 ) ;
F_96 ( & V_340 -> V_316 , V_4 -> V_5 ) ;
V_340 -> V_87 += F_71 ( & V_340 -> V_316 ) ;
return 1 ;
}
static T_2 F_105 ( struct V_339 * V_340 )
{
return V_340 -> V_87 ;
}
static int F_106 ( struct V_339 * V_340 ,
struct V_81 * V_81 , T_8 * V_245 )
{
bool V_352 = 1 ;
struct V_323 * V_324 = V_340 -> V_344 ;
do {
int V_94 ;
if ( ! F_75 ( & V_324 -> V_330 [ 0 ] , V_81 , V_245 ) )
return 0 ;
if ( V_352 && ! F_75 ( & V_340 -> V_302 , V_81 , V_245 ) )
return 0 ;
if ( V_352 && ! F_75 ( & V_340 -> V_316 , V_81 , V_245 ) )
return 0 ;
for ( V_94 = 1 ; V_94 < V_340 -> V_346 ; ++ V_94 )
if ( V_324 -> V_330 [ V_94 ] . V_250 &&
! F_75 ( & V_324 -> V_330 [ V_94 ] , V_81 , V_245 ) )
return 0 ;
V_352 = 0 ;
V_324 = V_324 -> V_350 ;
} while ( V_324 );
return 1 ;
}
static void F_107 ( struct V_339 * V_340 )
{
struct V_323 * V_353 = V_340 -> V_344 ;
while ( V_353 ) {
unsigned int V_94 ;
struct V_323 * V_324 = V_353 ;
V_353 = V_324 -> V_350 ;
F_102 ( V_324 -> V_330 [ 0 ] . V_250 && V_324 -> V_330 [ 0 ] . V_250 != & V_324 -> V_275 ) ;
for ( V_94 = 1 ; V_94 < V_340 -> V_346 ; ++ V_94 )
F_35 ( V_324 -> V_330 [ V_94 ] . V_250 ) ;
F_35 ( V_324 ) ;
}
F_35 ( V_340 -> V_302 . V_250 ) ;
}
static int F_108 ( long V_277 , struct V_354 * V_324 )
{
int V_241 = 0 ;
struct V_276 * V_20 = V_324 -> V_344 ;
V_324 -> V_355 = 0 ;
F_79 ( & V_324 -> V_275 , V_20 , V_277 ) ;
F_109 ( V_20 , & V_324 -> V_275 . V_329 ) ;
F_78 ( & V_324 -> V_330 [ 0 ] , L_2 , V_331 , sizeof( V_324 -> V_275 ) ,
& ( V_324 -> V_275 ) ) ;
V_324 -> V_355 ++ ;
V_241 += F_71 ( & V_324 -> V_330 [ 0 ] ) ;
if ( ( V_324 -> V_275 . V_337 = F_110 ( V_20 , NULL ,
& V_324 -> V_356 ) ) ) {
F_78 ( & V_324 -> V_330 [ 1 ] , L_2 , V_336 , sizeof( V_324 -> V_356 ) ,
& ( V_324 -> V_356 ) ) ;
V_324 -> V_355 ++ ;
V_241 += F_71 ( & V_324 -> V_330 [ 1 ] ) ;
}
#ifdef F_111
if ( F_112 ( V_20 , & V_324 -> V_357 ) ) {
F_78 ( & V_324 -> V_330 [ 2 ] , L_3 , V_358 ,
sizeof( V_324 -> V_357 ) , & V_324 -> V_357 ) ;
V_324 -> V_355 ++ ;
V_241 += F_71 ( & V_324 -> V_330 [ 2 ] ) ;
}
#endif
return V_241 ;
}
static int F_113 ( struct V_339 * V_340 )
{
memset ( V_340 , 0 , sizeof( * V_340 ) ) ;
F_114 ( & V_340 -> V_359 ) ;
V_340 -> V_330 = F_33 ( 6 * sizeof( struct V_239 ) , V_115 ) ;
if ( ! V_340 -> V_330 )
return 0 ;
V_340 -> V_302 = F_33 ( sizeof( * V_340 -> V_302 ) , V_115 ) ;
if ( ! V_340 -> V_302 )
goto V_360;
V_340 -> V_275 = F_33 ( sizeof( * V_340 -> V_275 ) , V_115 ) ;
if ( ! V_340 -> V_275 )
goto V_361;
V_340 -> V_356 = F_33 ( sizeof( * V_340 -> V_356 ) , V_115 ) ;
if ( ! V_340 -> V_356 )
goto V_362;
#ifdef F_111
V_340 -> V_357 = F_33 ( sizeof( * V_340 -> V_357 ) , V_115 ) ;
if ( ! V_340 -> V_357 )
goto V_363;
#endif
return 1 ;
#ifdef F_111
V_363:
F_35 ( V_340 -> V_356 ) ;
#endif
V_362:
F_35 ( V_340 -> V_275 ) ;
V_361:
F_35 ( V_340 -> V_302 ) ;
V_360:
F_35 ( V_340 -> V_330 ) ;
return 0 ;
}
static int F_100 ( struct V_16 * V_251 , int V_338 ,
struct V_339 * V_340 ,
long V_277 , struct V_142 * V_143 )
{
struct V_364 * V_324 ;
if ( ! F_113 ( V_340 ) )
return 0 ;
if ( V_277 ) {
struct V_342 * V_343 ;
struct V_354 * V_365 ;
for ( V_343 = V_4 -> V_5 -> V_348 -> V_349 . V_350 ;
V_343 ; V_343 = V_343 -> V_350 ) {
V_365 = F_103 ( sizeof( * V_365 ) , V_115 ) ;
if ( ! V_365 )
return 0 ;
V_365 -> V_344 = V_343 -> V_319 ;
F_115 ( & V_365 -> V_366 , & V_340 -> V_359 ) ;
}
F_116 (t, &info->thread_list) {
int V_241 ;
V_365 = F_117 ( V_324 , struct V_354 , V_366 ) ;
V_241 = F_108 ( V_277 , V_365 ) ;
V_340 -> V_367 += V_241 ;
}
}
memset ( V_340 -> V_275 , 0 , sizeof( * V_340 -> V_275 ) ) ;
F_79 ( V_340 -> V_275 , V_4 , V_277 ) ;
F_118 ( & V_340 -> V_275 -> V_329 , V_143 ) ;
F_76 ( V_251 , V_338 , V_368 , V_369 , V_262 ) ;
F_78 ( V_340 -> V_330 + 0 , L_2 , V_331 ,
sizeof( * V_340 -> V_275 ) , V_340 -> V_275 ) ;
F_89 ( V_340 -> V_302 , V_4 -> V_351 , V_4 -> V_5 ) ;
F_78 ( V_340 -> V_330 + 1 , L_2 , V_345 ,
sizeof( * V_340 -> V_302 ) , V_340 -> V_302 ) ;
V_340 -> V_370 = 2 ;
F_96 ( & V_340 -> V_330 [ V_340 -> V_370 ++ ] , V_4 -> V_5 ) ;
V_340 -> V_275 -> V_337 = F_110 ( V_4 , V_143 ,
V_340 -> V_356 ) ;
if ( V_340 -> V_275 -> V_337 )
F_78 ( V_340 -> V_330 + V_340 -> V_370 ++ ,
L_2 , V_336 , sizeof( * V_340 -> V_356 ) , V_340 -> V_356 ) ;
#ifdef F_111
if ( F_112 ( V_4 , V_340 -> V_357 ) )
F_78 ( V_340 -> V_330 + V_340 -> V_370 ++ ,
L_3 , V_358 ,
sizeof( * V_340 -> V_357 ) , V_340 -> V_357 ) ;
#endif
return 1 ;
}
static T_2 F_105 ( struct V_339 * V_340 )
{
int V_241 = 0 ;
int V_94 ;
for ( V_94 = 0 ; V_94 < V_340 -> V_370 ; V_94 ++ )
V_241 += F_71 ( V_340 -> V_330 + V_94 ) ;
V_241 += V_340 -> V_367 ;
return V_241 ;
}
static int F_106 ( struct V_339 * V_340 ,
struct V_81 * V_81 , T_8 * V_245 )
{
int V_94 ;
struct V_364 * V_324 ;
for ( V_94 = 0 ; V_94 < V_340 -> V_370 ; V_94 ++ )
if ( ! F_75 ( V_340 -> V_330 + V_94 , V_81 , V_245 ) )
return 0 ;
F_116 (t, &info->thread_list) {
struct V_354 * V_371 =
F_117 ( V_324 , struct V_354 , V_366 ) ;
for ( V_94 = 0 ; V_94 < V_371 -> V_355 ; V_94 ++ )
if ( ! F_75 ( & V_371 -> V_330 [ V_94 ] , V_81 , V_245 ) )
return 0 ;
}
return 1 ;
}
static void F_107 ( struct V_339 * V_340 )
{
while ( ! F_119 ( & V_340 -> V_359 ) ) {
struct V_364 * V_371 = V_340 -> V_359 . V_350 ;
F_120 ( V_371 ) ;
F_35 ( F_117 ( V_371 , struct V_354 , V_366 ) ) ;
}
F_35 ( V_340 -> V_275 ) ;
F_35 ( V_340 -> V_302 ) ;
F_35 ( V_340 -> V_330 ) ;
F_35 ( V_340 -> V_356 ) ;
#ifdef F_111
F_35 ( V_340 -> V_357 ) ;
#endif
}
static struct V_38 * F_121 ( struct V_276 * V_372 ,
struct V_38 * V_373 )
{
struct V_38 * V_335 = V_372 -> V_5 -> V_113 ;
if ( V_335 )
return V_335 ;
return V_373 ;
}
static struct V_38 * F_122 ( struct V_38 * V_374 ,
struct V_38 * V_373 )
{
struct V_38 * V_335 ;
V_335 = V_374 -> V_375 ;
if ( V_335 )
return V_335 ;
if ( V_374 == V_373 )
return NULL ;
return V_373 ;
}
static void F_123 ( struct V_16 * V_251 , struct V_376 * V_377 ,
T_1 V_378 , int V_252 )
{
V_251 -> V_378 = V_378 ;
V_251 -> V_379 = sizeof( * V_377 ) ;
V_251 -> V_380 = 1 ;
V_251 -> V_381 = V_382 ;
memset ( V_377 , 0 , sizeof( * V_377 ) ) ;
V_377 -> V_383 = V_384 ;
V_377 -> V_385 = V_251 -> V_380 ;
V_377 -> V_386 = V_251 -> V_381 ;
V_377 -> V_387 = V_252 ;
}
static T_2 F_124 ( struct V_38 * V_373 ,
unsigned long V_199 )
{
struct V_38 * V_39 ;
T_2 V_87 = 0 ;
for ( V_39 = F_121 ( V_4 , V_373 ) ; V_39 != NULL ;
V_39 = F_122 ( V_39 , V_373 ) )
V_87 += F_65 ( V_39 , V_199 ) ;
return V_87 ;
}
static int F_125 ( struct V_388 * V_389 )
{
int V_390 = 0 ;
T_7 V_225 ;
int V_252 ;
T_2 V_87 = 0 ;
struct V_38 * V_39 , * V_373 ;
struct V_16 * V_251 = NULL ;
T_8 V_269 = 0 , V_391 , V_245 ;
struct V_339 V_340 ;
struct V_51 * V_392 = NULL ;
struct V_376 * V_377 = NULL ;
T_11 V_53 ;
T_1 V_378 ;
V_251 = F_33 ( sizeof( * V_251 ) , V_115 ) ;
if ( ! V_251 )
goto V_111;
V_252 = V_4 -> V_5 -> V_393 ;
V_252 += F_126 () ;
V_373 = F_127 ( V_4 -> V_5 ) ;
if ( V_373 != NULL )
V_252 ++ ;
V_252 ++ ;
V_53 = V_252 > V_394 ? V_394 : V_252 ;
if ( ! F_100 ( V_251 , V_53 , & V_340 , V_389 -> V_277 , V_389 -> V_143 ) )
goto V_395;
V_390 = 1 ;
V_4 -> V_136 |= V_396 ;
V_225 = F_67 () ;
F_69 ( V_397 ) ;
V_269 += sizeof( * V_251 ) ;
V_269 += V_252 * sizeof( struct V_51 ) ;
V_245 = V_269 ;
{
T_2 V_241 = F_105 ( & V_340 ) ;
V_241 += F_128 () ;
V_392 = F_33 ( sizeof( * V_392 ) , V_115 ) ;
if ( ! V_392 )
goto V_398;
F_77 ( V_392 , V_241 , V_269 ) ;
V_269 += V_241 ;
}
V_391 = V_269 = F_72 ( V_269 , V_45 ) ;
V_269 += F_124 ( V_373 , V_389 -> V_199 ) ;
V_269 += F_129 () ;
V_378 = V_269 ;
if ( V_53 == V_394 ) {
V_377 = F_33 ( sizeof( * V_377 ) , V_115 ) ;
if ( ! V_377 )
goto V_398;
F_123 ( V_251 , V_377 , V_378 , V_252 ) ;
}
V_269 = V_391 ;
V_87 += sizeof( * V_251 ) ;
if ( V_87 > V_389 -> V_399 || ! F_130 ( V_389 -> V_81 , V_251 , sizeof( * V_251 ) ) )
goto V_398;
V_87 += sizeof( * V_392 ) ;
if ( V_87 > V_389 -> V_399
|| ! F_130 ( V_389 -> V_81 , V_392 , sizeof( * V_392 ) ) )
goto V_398;
for ( V_39 = F_121 ( V_4 , V_373 ) ; V_39 != NULL ;
V_39 = F_122 ( V_39 , V_373 ) ) {
struct V_51 V_268 ;
V_268 . V_97 = V_98 ;
V_268 . V_91 = V_269 ;
V_268 . V_89 = V_39 -> V_223 ;
V_268 . V_271 = 0 ;
V_268 . V_88 = F_65 ( V_39 , V_389 -> V_199 ) ;
V_268 . V_99 = V_39 -> V_238 - V_39 -> V_223 ;
V_269 += V_268 . V_88 ;
V_268 . V_124 = V_39 -> V_200 & V_221 ? V_125 : 0 ;
if ( V_39 -> V_200 & V_400 )
V_268 . V_124 |= V_127 ;
if ( V_39 -> V_200 & V_401 )
V_268 . V_124 |= V_129 ;
V_268 . V_272 = V_45 ;
V_87 += sizeof( V_268 ) ;
if ( V_87 > V_389 -> V_399
|| ! F_130 ( V_389 -> V_81 , & V_268 , sizeof( V_268 ) ) )
goto V_398;
}
if ( ! F_131 ( V_389 -> V_81 , V_269 , & V_87 , V_389 -> V_399 ) )
goto V_398;
if ( ! F_106 ( & V_340 , V_389 -> V_81 , & V_245 ) )
goto V_398;
if ( F_132 ( V_389 -> V_81 , & V_245 ) )
goto V_398;
if ( ! F_133 ( V_389 -> V_81 , V_391 - V_245 ) )
goto V_398;
for ( V_39 = F_121 ( V_4 , V_373 ) ; V_39 != NULL ;
V_39 = F_122 ( V_39 , V_373 ) ) {
unsigned long V_3 ;
unsigned long V_2 ;
V_2 = V_39 -> V_223 + F_65 ( V_39 , V_389 -> V_199 ) ;
for ( V_3 = V_39 -> V_223 ; V_3 < V_2 ; V_3 += V_196 ) {
struct V_402 * V_402 ;
int V_403 ;
V_402 = F_134 ( V_3 ) ;
if ( V_402 ) {
void * V_404 = F_135 ( V_402 ) ;
V_403 = ( ( V_87 += V_196 ) > V_389 -> V_399 ) ||
! F_130 ( V_389 -> V_81 , V_404 ,
V_196 ) ;
F_136 ( V_402 ) ;
F_137 ( V_402 ) ;
} else
V_403 = ! F_133 ( V_389 -> V_81 , V_196 ) ;
if ( V_403 )
goto V_398;
}
}
if ( ! F_138 ( V_389 -> V_81 , & V_87 , V_389 -> V_399 ) )
goto V_398;
if ( V_53 == V_394 ) {
V_87 += sizeof( * V_377 ) ;
if ( V_87 > V_389 -> V_399
|| ! F_130 ( V_389 -> V_81 , V_377 ,
sizeof( * V_377 ) ) )
goto V_398;
}
V_398:
F_69 ( V_225 ) ;
V_395:
F_107 ( & V_340 ) ;
F_35 ( V_377 ) ;
F_35 ( V_392 ) ;
F_35 ( V_251 ) ;
V_111:
return V_390 ;
}
static int T_12 F_139 ( void )
{
return F_140 ( & V_193 ) ;
}
static void T_13 F_141 ( void )
{
F_142 ( & V_193 ) ;
}
