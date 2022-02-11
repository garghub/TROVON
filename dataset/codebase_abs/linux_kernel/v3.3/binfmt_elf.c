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
F_43 ( V_15 , V_101 ) ;
V_107 = F_34 ( V_101 , 0 , V_15 -> V_160 ,
V_169 ) ;
if ( V_107 != V_169 ) {
if ( V_107 >= 0 )
V_107 = - V_116 ;
goto V_170;
}
V_158 -> V_100 = * ( (struct V_16 * ) V_15 -> V_160 ) ;
break;
}
V_146 ++ ;
}
V_146 = V_104 ;
for ( V_94 = 0 ; V_94 < V_158 -> V_157 . V_53 ; V_94 ++ , V_146 ++ )
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
V_107 = F_44 ( V_15 ) ;
if ( V_107 )
goto V_170;
V_4 -> V_136 &= ~ V_175 ;
V_4 -> V_5 -> V_156 = V_156 ;
F_45 ( V_158 -> V_157 ) ;
if ( F_46 ( V_158 -> V_157 , V_154 ) )
V_4 -> V_138 |= V_176 ;
if ( ! ( V_4 -> V_138 & V_139 ) && V_177 )
V_4 -> V_136 |= V_137 ;
F_47 ( V_15 ) ;
V_4 -> V_5 -> V_178 = V_4 -> V_5 -> V_179 ;
V_4 -> V_5 -> V_180 = 0 ;
V_107 = F_48 ( V_15 , F_36 ( V_181 ) ,
V_154 ) ;
if ( V_107 < 0 ) {
F_49 ( V_182 , V_4 , 0 ) ;
goto V_170;
}
V_4 -> V_5 -> V_183 = V_15 -> V_20 ;
for( V_94 = 0 , V_146 = V_104 ;
V_94 < V_158 -> V_157 . V_53 ; V_94 ++ , V_146 ++ ) {
int V_121 = 0 , V_184 ;
unsigned long V_123 , V_122 ;
if ( V_146 -> V_97 != V_98 )
continue;
if ( F_50 ( V_147 > V_9 ) ) {
unsigned long V_10 ;
V_107 = F_1 ( V_9 + V_144 ,
V_147 + V_144 ) ;
if ( V_107 ) {
F_49 ( V_182 , V_4 , 0 ) ;
goto V_170;
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
V_184 = V_119 | V_120 | V_185 ;
V_122 = V_146 -> V_89 ;
if ( V_158 -> V_157 . V_108 == V_109 || V_105 ) {
V_184 |= V_131 ;
} else if ( V_158 -> V_157 . V_108 == V_110 ) {
#ifdef F_51
if ( V_4 -> V_136 & V_137 )
V_144 = 0 ;
else
V_144 = F_27 ( V_186 - V_122 ) ;
#else
V_144 = F_27 ( V_186 - V_122 ) ;
#endif
}
error = F_26 ( V_15 -> V_81 , V_144 + V_122 , V_146 ,
V_121 , V_184 , 0 ) ;
if ( F_6 ( error ) ) {
F_49 ( V_182 , V_4 , 0 ) ;
V_107 = F_42 ( ( void * ) error ) ?
F_41 ( ( void * ) error ) : - V_78 ;
goto V_170;
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
F_49 ( V_182 , V_4 , 0 ) ;
V_107 = - V_78 ;
goto V_170;
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
F_49 ( V_182 , V_4 , 0 ) ;
goto V_170;
}
if ( F_52 ( V_9 != V_147 ) && F_50 ( F_7 ( V_9 ) ) ) {
F_49 ( V_187 , V_4 , 0 ) ;
V_107 = - V_13 ;
goto V_170;
}
if ( V_145 ) {
unsigned long V_188 ( V_102 ) ;
V_148 = F_31 ( & V_158 -> V_100 ,
V_101 ,
& V_102 ,
V_144 ) ;
if ( ! F_42 ( ( void * ) V_148 ) ) {
V_19 = V_148 ;
V_148 += V_158 -> V_100 . V_57 ;
}
if ( F_6 ( V_148 ) ) {
F_53 ( V_187 , V_4 ) ;
V_107 = F_42 ( ( void * ) V_148 ) ?
( int ) V_148 : - V_78 ;
goto V_170;
}
T_5 = V_19 ;
F_54 ( V_101 ) ;
F_55 ( V_101 ) ;
F_35 ( V_145 ) ;
} else {
V_148 = V_158 -> V_157 . V_57 ;
if ( F_6 ( V_148 ) ) {
F_53 ( V_187 , V_4 ) ;
V_107 = - V_78 ;
goto V_170;
}
}
F_35 ( V_104 ) ;
F_56 ( & V_189 ) ;
#ifdef F_57
V_107 = F_58 ( V_15 , ! ! V_145 ) ;
if ( V_107 < 0 ) {
F_49 ( V_182 , V_4 , 0 ) ;
goto V_111;
}
#endif
F_59 ( V_15 ) ;
V_4 -> V_136 &= ~ V_175 ;
V_107 = F_10 ( V_15 , & V_158 -> V_157 ,
V_18 , V_19 ) ;
if ( V_107 < 0 ) {
F_49 ( V_182 , V_4 , 0 ) ;
goto V_111;
}
V_4 -> V_5 -> V_150 = V_150 ;
V_4 -> V_5 -> V_149 = V_149 ;
V_4 -> V_5 -> V_151 = V_151 ;
V_4 -> V_5 -> V_152 = V_152 ;
V_4 -> V_5 -> V_183 = V_15 -> V_20 ;
#ifdef F_60
if ( ( V_4 -> V_136 & V_137 ) && ( V_177 > 1 ) ) {
V_4 -> V_5 -> V_8 = V_4 -> V_5 -> V_7 =
F_60 ( V_4 -> V_5 ) ;
#ifdef F_61
V_4 -> V_190 = 1 ;
#endif
}
#endif
if ( V_4 -> V_138 & V_191 ) {
F_3 ( & V_4 -> V_5 -> V_6 ) ;
error = F_28 ( NULL , 0 , V_192 , V_126 | V_130 ,
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
struct V_51 * V_104 ;
struct V_51 * V_83 ;
unsigned long V_9 , V_193 , V_40 ;
int V_107 , error , V_94 , V_194 ;
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
V_194 = sizeof( struct V_51 ) * V_157 . V_53 ;
error = - V_133 ;
V_104 = F_33 ( V_194 , V_115 ) ;
if ( ! V_104 )
goto V_111;
V_83 = V_104 ;
error = - V_161 ;
V_107 = F_34 ( V_81 , V_157 . V_49 , ( char * ) V_83 , V_194 ) ;
if ( V_107 != V_194 )
goto V_165;
for ( V_194 = 0 , V_94 = 0 ; V_94 < V_157 . V_53 ; V_94 ++ )
if ( ( V_83 + V_94 ) -> V_97 == V_98 )
V_194 ++ ;
if ( V_194 != 1 )
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
V_193 = V_83 -> V_99 + V_83 -> V_89 ;
if ( V_193 > V_40 ) {
F_3 ( & V_4 -> V_5 -> V_6 ) ;
F_4 ( V_40 , V_193 - V_40 ) ;
F_5 ( & V_4 -> V_5 -> V_6 ) ;
}
error = 0 ;
V_165:
F_35 ( V_104 ) ;
V_111:
return error ;
}
static unsigned long F_65 ( struct V_38 * V_39 ,
unsigned long V_195 )
{
#define F_66 ( type ) (mm_flags & (1UL << MMF_DUMP_##type))
if ( V_39 -> V_196 & V_197 )
goto V_198;
if ( V_39 -> V_196 & V_199 ) {
if ( ( V_39 -> V_196 & V_200 ) && F_66 ( V_201 ) )
goto V_198;
if ( ! ( V_39 -> V_196 & V_200 ) && F_66 ( V_202 ) )
goto V_198;
}
if ( V_39 -> V_196 & ( V_203 | V_204 ) )
return 0 ;
if ( V_39 -> V_196 & V_200 ) {
if ( V_39 -> V_205 -> V_206 . V_207 -> V_208 -> V_209 == 0 ?
F_66 ( V_210 ) : F_66 ( V_211 ) )
goto V_198;
return 0 ;
}
if ( V_39 -> V_212 && F_66 ( V_213 ) )
goto V_198;
if ( V_39 -> V_205 == NULL )
return 0 ;
if ( F_66 ( V_214 ) )
goto V_198;
if ( F_66 ( V_215 ) &&
V_39 -> V_216 == 0 && ( V_39 -> V_196 & V_217 ) ) {
T_6 V_12 * V_218 = ( T_6 V_12 * ) V_39 -> V_219 ;
T_6 V_220 ;
T_7 V_221 = F_67 () ;
union {
T_6 V_222 ;
char V_223 [ V_164 ] ;
} V_224 ;
F_68 ( V_164 != sizeof V_220 ) ;
V_224 . V_223 [ V_225 ] = V_226 ;
V_224 . V_223 [ V_227 ] = V_228 ;
V_224 . V_223 [ V_229 ] = V_230 ;
V_224 . V_223 [ V_231 ] = V_232 ;
F_69 ( V_233 ) ;
if ( F_50 ( F_70 ( V_220 , V_218 ) ) )
V_220 = 0 ;
F_69 ( V_221 ) ;
if ( V_220 == V_224 . V_222 )
return V_192 ;
}
#undef F_66
return 0 ;
V_198:
return V_39 -> V_234 - V_39 -> V_219 ;
}
static int F_71 ( struct V_235 * V_236 )
{
int V_237 ;
V_237 = sizeof( struct V_238 ) ;
V_237 += F_72 ( strlen ( V_236 -> V_239 ) + 1 , 4 ) ;
V_237 += F_72 ( V_236 -> V_240 , 4 ) ;
return V_237 ;
}
static int F_73 ( struct V_81 * V_81 , T_8 * V_241 )
{
static const char V_160 [ 4 ] = { 0 , } ;
F_74 ( V_160 , F_72 ( * V_241 , 4 ) - * V_241 , V_241 ) ;
return 1 ;
}
static int F_75 ( struct V_235 * V_242 , struct V_81 * V_81 ,
T_8 * V_241 )
{
struct V_238 V_236 ;
V_236 . V_243 = strlen ( V_242 -> V_239 ) + 1 ;
V_236 . V_244 = V_242 -> V_240 ;
V_236 . V_245 = V_242 -> type ;
F_74 ( & V_236 , sizeof( V_236 ) , V_241 ) ;
F_74 ( V_242 -> V_239 , V_236 . V_243 , V_241 ) ;
if ( ! F_73 ( V_81 , V_241 ) )
return 0 ;
F_74 ( V_242 -> V_246 , V_242 -> V_240 , V_241 ) ;
if ( ! F_73 ( V_81 , V_241 ) )
return 0 ;
return 1 ;
}
static void F_76 ( struct V_16 * V_247 , int V_248 ,
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
V_247 -> V_49 = sizeof( struct V_16 ) ;
V_247 -> V_262 = V_136 ;
V_247 -> V_263 = sizeof( struct V_16 ) ;
V_247 -> V_114 = sizeof( struct V_51 ) ;
V_247 -> V_53 = V_248 ;
return;
}
static void F_77 ( struct V_51 * V_264 , int V_237 , T_8 V_265 )
{
V_264 -> V_97 = V_266 ;
V_264 -> V_91 = V_265 ;
V_264 -> V_89 = 0 ;
V_264 -> V_267 = 0 ;
V_264 -> V_88 = V_237 ;
V_264 -> V_99 = 0 ;
V_264 -> V_124 = 0 ;
V_264 -> V_268 = 0 ;
return;
}
static void F_78 ( struct V_235 * V_269 , const char * V_239 , int type ,
unsigned int V_237 , void * V_246 )
{
V_269 -> V_239 = V_239 ;
V_269 -> type = type ;
V_269 -> V_240 = V_237 ;
V_269 -> V_246 = V_246 ;
return;
}
static void F_79 ( struct V_270 * V_271 ,
struct V_272 * V_20 , long V_273 )
{
V_271 -> V_274 . V_275 = V_271 -> V_276 = V_273 ;
V_271 -> V_277 = V_20 -> V_278 . signal . V_279 [ 0 ] ;
V_271 -> V_280 = V_20 -> V_281 . V_279 [ 0 ] ;
F_80 () ;
V_271 -> V_282 = F_81 ( F_82 ( V_20 -> V_283 ) ) ;
F_83 () ;
V_271 -> V_284 = F_81 ( V_20 ) ;
V_271 -> V_285 = F_84 ( V_20 ) ;
V_271 -> V_286 = F_85 ( V_20 ) ;
if ( F_86 ( V_20 ) ) {
struct V_287 V_288 ;
F_87 ( V_20 , & V_288 ) ;
F_88 ( V_288 . V_289 , & V_271 -> V_290 ) ;
F_88 ( V_288 . V_291 , & V_271 -> V_292 ) ;
} else {
F_88 ( V_20 -> V_289 , & V_271 -> V_290 ) ;
F_88 ( V_20 -> V_291 , & V_271 -> V_292 ) ;
}
F_88 ( V_20 -> signal -> V_293 , & V_271 -> V_294 ) ;
F_88 ( V_20 -> signal -> V_295 , & V_271 -> V_296 ) ;
}
static int F_89 ( struct V_297 * V_298 , struct V_272 * V_20 ,
struct V_299 * V_5 )
{
const struct V_37 * V_37 ;
unsigned int V_94 , V_40 ;
memset ( V_298 , 0 , sizeof( struct V_297 ) ) ;
V_40 = V_5 -> V_75 - V_5 -> V_76 ;
if ( V_40 >= V_300 )
V_40 = V_300 - 1 ;
if ( F_90 ( & V_298 -> V_301 ,
( const char V_12 * ) V_5 -> V_76 , V_40 ) )
return - V_13 ;
for( V_94 = 0 ; V_94 < V_40 ; V_94 ++ )
if ( V_298 -> V_301 [ V_94 ] == 0 )
V_298 -> V_301 [ V_94 ] = ' ' ;
V_298 -> V_301 [ V_40 ] = 0 ;
F_80 () ;
V_298 -> V_282 = F_81 ( F_82 ( V_20 -> V_283 ) ) ;
F_83 () ;
V_298 -> V_284 = F_81 ( V_20 ) ;
V_298 -> V_285 = F_84 ( V_20 ) ;
V_298 -> V_286 = F_85 ( V_20 ) ;
V_94 = V_20 -> V_302 ? F_91 ( ~ V_20 -> V_302 ) + 1 : 0 ;
V_298 -> V_303 = V_94 ;
V_298 -> V_304 = ( V_94 > 5 ) ? '.' : L_1 [ V_94 ] ;
V_298 -> V_305 = V_298 -> V_304 == 'Z' ;
V_298 -> V_306 = F_92 ( V_20 ) ;
V_298 -> V_307 = V_20 -> V_136 ;
F_80 () ;
V_37 = F_93 ( V_20 ) ;
F_94 ( V_298 -> V_308 , V_37 -> V_59 ) ;
F_95 ( V_298 -> V_309 , V_37 -> V_63 ) ;
F_83 () ;
strncpy ( V_298 -> V_310 , V_20 -> V_311 , sizeof( V_298 -> V_310 ) ) ;
return 0 ;
}
static void F_96 ( struct V_235 * V_269 , struct V_299 * V_5 )
{
T_1 * V_312 = ( T_1 * ) V_5 -> V_41 ;
int V_94 = 0 ;
do
V_94 += 2 ;
while ( V_312 [ V_94 - 2 ] != V_313 );
F_78 ( V_269 , L_2 , V_314 , V_94 * sizeof( T_1 ) , V_312 ) ;
}
static void F_97 ( struct V_272 * V_315 ,
const struct V_316 * V_317 )
{
if ( V_317 -> V_318 )
V_317 -> V_318 ( V_315 , V_317 , 1 ) ;
}
static int F_98 ( struct V_319 * V_320 ,
const struct V_321 * V_322 ,
long V_273 , T_2 * V_323 )
{
unsigned int V_94 ;
F_79 ( & V_320 -> V_271 , V_320 -> V_315 , V_273 ) ;
( void ) V_322 -> V_324 [ 0 ] . F_99 ( V_320 -> V_315 , & V_322 -> V_324 [ 0 ] ,
0 , sizeof( V_320 -> V_271 . V_325 ) ,
& V_320 -> V_271 . V_325 , NULL ) ;
F_78 ( & V_320 -> V_326 [ 0 ] , L_2 , V_327 ,
sizeof( V_320 -> V_271 ) , & V_320 -> V_271 ) ;
* V_323 += F_71 ( & V_320 -> V_326 [ 0 ] ) ;
F_97 ( V_320 -> V_315 , & V_322 -> V_324 [ 0 ] ) ;
for ( V_94 = 1 ; V_94 < V_322 -> V_328 ; ++ V_94 ) {
const struct V_316 * V_317 = & V_322 -> V_324 [ V_94 ] ;
F_97 ( V_320 -> V_315 , V_317 ) ;
if ( V_317 -> V_329 && V_317 -> F_99 &&
( ! V_317 -> V_330 || V_317 -> V_330 ( V_320 -> V_315 , V_317 ) ) ) {
int V_331 ;
T_2 V_87 = V_317 -> V_328 * V_317 -> V_87 ;
void * V_246 = F_33 ( V_87 , V_115 ) ;
if ( F_50 ( ! V_246 ) )
return 0 ;
V_331 = V_317 -> F_99 ( V_320 -> V_315 , V_317 ,
0 , V_87 , V_246 , NULL ) ;
if ( F_50 ( V_331 ) )
F_35 ( V_246 ) ;
else {
if ( V_317 -> V_329 != V_332 )
F_78 ( & V_320 -> V_326 [ V_94 ] , L_3 ,
V_317 -> V_329 ,
V_87 , V_246 ) ;
else {
V_320 -> V_271 . V_333 = 1 ;
F_78 ( & V_320 -> V_326 [ V_94 ] , L_2 ,
V_332 , V_87 , V_246 ) ;
}
* V_323 += F_71 ( & V_320 -> V_326 [ V_94 ] ) ;
}
}
}
return 1 ;
}
static int F_100 ( struct V_16 * V_247 , int V_334 ,
struct V_335 * V_336 ,
long V_273 , struct V_142 * V_143 )
{
struct V_272 * V_337 = V_4 ;
const struct V_321 * V_322 = F_101 ( V_337 ) ;
struct V_319 * V_320 ;
struct V_297 * V_298 ;
struct V_338 * V_339 ;
unsigned int V_94 ;
V_336 -> V_87 = 0 ;
V_336 -> V_340 = NULL ;
V_298 = F_33 ( sizeof( * V_298 ) , V_115 ) ;
if ( V_298 == NULL )
return 0 ;
F_78 ( & V_336 -> V_298 , L_2 , V_341 , sizeof( * V_298 ) , V_298 ) ;
V_336 -> V_342 = 0 ;
for ( V_94 = 0 ; V_94 < V_322 -> V_328 ; ++ V_94 )
if ( V_322 -> V_324 [ V_94 ] . V_329 != 0 )
++ V_336 -> V_342 ;
if ( F_50 ( V_336 -> V_342 == 0 ) ||
F_50 ( V_322 -> V_324 [ 0 ] . V_329 != V_327 ) ) {
F_102 ( 1 ) ;
return 0 ;
}
F_76 ( V_247 , V_334 ,
V_322 -> V_260 , V_322 -> V_262 , V_322 -> V_343 ) ;
for ( V_339 = & V_337 -> V_5 -> V_344 -> V_345 ; V_339 ; V_339 = V_339 -> V_346 ) {
V_320 = F_103 ( F_104 ( struct V_319 ,
V_326 [ V_336 -> V_342 ] ) ,
V_115 ) ;
if ( F_50 ( ! V_320 ) )
return 0 ;
V_320 -> V_315 = V_339 -> V_315 ;
if ( V_339 -> V_315 == V_337 || ! V_336 -> V_340 ) {
V_320 -> V_346 = V_336 -> V_340 ;
V_336 -> V_340 = V_320 ;
} else {
V_320 -> V_346 = V_336 -> V_340 -> V_346 ;
V_336 -> V_340 -> V_346 = V_320 ;
}
}
for ( V_320 = V_336 -> V_340 ; V_320 != NULL ; V_320 = V_320 -> V_346 )
if ( ! F_98 ( V_320 , V_322 , V_273 , & V_336 -> V_87 ) )
return 0 ;
F_89 ( V_298 , V_337 -> V_347 , V_337 -> V_5 ) ;
V_336 -> V_87 += F_71 ( & V_336 -> V_298 ) ;
F_96 ( & V_336 -> V_312 , V_4 -> V_5 ) ;
V_336 -> V_87 += F_71 ( & V_336 -> V_312 ) ;
return 1 ;
}
static T_2 F_105 ( struct V_335 * V_336 )
{
return V_336 -> V_87 ;
}
static int F_106 ( struct V_335 * V_336 ,
struct V_81 * V_81 , T_8 * V_241 )
{
bool V_348 = 1 ;
struct V_319 * V_320 = V_336 -> V_340 ;
do {
int V_94 ;
if ( ! F_75 ( & V_320 -> V_326 [ 0 ] , V_81 , V_241 ) )
return 0 ;
if ( V_348 && ! F_75 ( & V_336 -> V_298 , V_81 , V_241 ) )
return 0 ;
if ( V_348 && ! F_75 ( & V_336 -> V_312 , V_81 , V_241 ) )
return 0 ;
for ( V_94 = 1 ; V_94 < V_336 -> V_342 ; ++ V_94 )
if ( V_320 -> V_326 [ V_94 ] . V_246 &&
! F_75 ( & V_320 -> V_326 [ V_94 ] , V_81 , V_241 ) )
return 0 ;
V_348 = 0 ;
V_320 = V_320 -> V_346 ;
} while ( V_320 );
return 1 ;
}
static void F_107 ( struct V_335 * V_336 )
{
struct V_319 * V_349 = V_336 -> V_340 ;
while ( V_349 ) {
unsigned int V_94 ;
struct V_319 * V_320 = V_349 ;
V_349 = V_320 -> V_346 ;
F_102 ( V_320 -> V_326 [ 0 ] . V_246 && V_320 -> V_326 [ 0 ] . V_246 != & V_320 -> V_271 ) ;
for ( V_94 = 1 ; V_94 < V_336 -> V_342 ; ++ V_94 )
F_35 ( V_320 -> V_326 [ V_94 ] . V_246 ) ;
F_35 ( V_320 ) ;
}
F_35 ( V_336 -> V_298 . V_246 ) ;
}
static int F_108 ( long V_273 , struct V_350 * V_320 )
{
int V_237 = 0 ;
struct V_272 * V_20 = V_320 -> V_340 ;
V_320 -> V_351 = 0 ;
F_79 ( & V_320 -> V_271 , V_20 , V_273 ) ;
F_109 ( V_20 , & V_320 -> V_271 . V_325 ) ;
F_78 ( & V_320 -> V_326 [ 0 ] , L_2 , V_327 , sizeof( V_320 -> V_271 ) ,
& ( V_320 -> V_271 ) ) ;
V_320 -> V_351 ++ ;
V_237 += F_71 ( & V_320 -> V_326 [ 0 ] ) ;
if ( ( V_320 -> V_271 . V_333 = F_110 ( V_20 , NULL ,
& V_320 -> V_352 ) ) ) {
F_78 ( & V_320 -> V_326 [ 1 ] , L_2 , V_332 , sizeof( V_320 -> V_352 ) ,
& ( V_320 -> V_352 ) ) ;
V_320 -> V_351 ++ ;
V_237 += F_71 ( & V_320 -> V_326 [ 1 ] ) ;
}
#ifdef F_111
if ( F_112 ( V_20 , & V_320 -> V_353 ) ) {
F_78 ( & V_320 -> V_326 [ 2 ] , L_3 , V_354 ,
sizeof( V_320 -> V_353 ) , & V_320 -> V_353 ) ;
V_320 -> V_351 ++ ;
V_237 += F_71 ( & V_320 -> V_326 [ 2 ] ) ;
}
#endif
return V_237 ;
}
static int F_113 ( struct V_335 * V_336 )
{
memset ( V_336 , 0 , sizeof( * V_336 ) ) ;
F_114 ( & V_336 -> V_355 ) ;
V_336 -> V_326 = F_33 ( 6 * sizeof( struct V_235 ) , V_115 ) ;
if ( ! V_336 -> V_326 )
return 0 ;
V_336 -> V_298 = F_33 ( sizeof( * V_336 -> V_298 ) , V_115 ) ;
if ( ! V_336 -> V_298 )
goto V_356;
V_336 -> V_271 = F_33 ( sizeof( * V_336 -> V_271 ) , V_115 ) ;
if ( ! V_336 -> V_271 )
goto V_357;
V_336 -> V_352 = F_33 ( sizeof( * V_336 -> V_352 ) , V_115 ) ;
if ( ! V_336 -> V_352 )
goto V_358;
#ifdef F_111
V_336 -> V_353 = F_33 ( sizeof( * V_336 -> V_353 ) , V_115 ) ;
if ( ! V_336 -> V_353 )
goto V_359;
#endif
return 1 ;
#ifdef F_111
V_359:
F_35 ( V_336 -> V_352 ) ;
#endif
V_358:
F_35 ( V_336 -> V_271 ) ;
V_357:
F_35 ( V_336 -> V_298 ) ;
V_356:
F_35 ( V_336 -> V_326 ) ;
return 0 ;
}
static int F_100 ( struct V_16 * V_247 , int V_334 ,
struct V_335 * V_336 ,
long V_273 , struct V_142 * V_143 )
{
struct V_360 * V_320 ;
if ( ! F_113 ( V_336 ) )
return 0 ;
if ( V_273 ) {
struct V_338 * V_339 ;
struct V_350 * V_361 ;
for ( V_339 = V_4 -> V_5 -> V_344 -> V_345 . V_346 ;
V_339 ; V_339 = V_339 -> V_346 ) {
V_361 = F_103 ( sizeof( * V_361 ) , V_115 ) ;
if ( ! V_361 )
return 0 ;
V_361 -> V_340 = V_339 -> V_315 ;
F_115 ( & V_361 -> V_362 , & V_336 -> V_355 ) ;
}
F_116 (t, &info->thread_list) {
int V_237 ;
V_361 = F_117 ( V_320 , struct V_350 , V_362 ) ;
V_237 = F_108 ( V_273 , V_361 ) ;
V_336 -> V_363 += V_237 ;
}
}
memset ( V_336 -> V_271 , 0 , sizeof( * V_336 -> V_271 ) ) ;
F_79 ( V_336 -> V_271 , V_4 , V_273 ) ;
F_118 ( & V_336 -> V_271 -> V_325 , V_143 ) ;
F_76 ( V_247 , V_334 , V_364 , V_365 , V_258 ) ;
F_78 ( V_336 -> V_326 + 0 , L_2 , V_327 ,
sizeof( * V_336 -> V_271 ) , V_336 -> V_271 ) ;
F_89 ( V_336 -> V_298 , V_4 -> V_347 , V_4 -> V_5 ) ;
F_78 ( V_336 -> V_326 + 1 , L_2 , V_341 ,
sizeof( * V_336 -> V_298 ) , V_336 -> V_298 ) ;
V_336 -> V_366 = 2 ;
F_96 ( & V_336 -> V_326 [ V_336 -> V_366 ++ ] , V_4 -> V_5 ) ;
V_336 -> V_271 -> V_333 = F_110 ( V_4 , V_143 ,
V_336 -> V_352 ) ;
if ( V_336 -> V_271 -> V_333 )
F_78 ( V_336 -> V_326 + V_336 -> V_366 ++ ,
L_2 , V_332 , sizeof( * V_336 -> V_352 ) , V_336 -> V_352 ) ;
#ifdef F_111
if ( F_112 ( V_4 , V_336 -> V_353 ) )
F_78 ( V_336 -> V_326 + V_336 -> V_366 ++ ,
L_3 , V_354 ,
sizeof( * V_336 -> V_353 ) , V_336 -> V_353 ) ;
#endif
return 1 ;
}
static T_2 F_105 ( struct V_335 * V_336 )
{
int V_237 = 0 ;
int V_94 ;
for ( V_94 = 0 ; V_94 < V_336 -> V_366 ; V_94 ++ )
V_237 += F_71 ( V_336 -> V_326 + V_94 ) ;
V_237 += V_336 -> V_363 ;
return V_237 ;
}
static int F_106 ( struct V_335 * V_336 ,
struct V_81 * V_81 , T_8 * V_241 )
{
int V_94 ;
struct V_360 * V_320 ;
for ( V_94 = 0 ; V_94 < V_336 -> V_366 ; V_94 ++ )
if ( ! F_75 ( V_336 -> V_326 + V_94 , V_81 , V_241 ) )
return 0 ;
F_116 (t, &info->thread_list) {
struct V_350 * V_367 =
F_117 ( V_320 , struct V_350 , V_362 ) ;
for ( V_94 = 0 ; V_94 < V_367 -> V_351 ; V_94 ++ )
if ( ! F_75 ( & V_367 -> V_326 [ V_94 ] , V_81 , V_241 ) )
return 0 ;
}
return 1 ;
}
static void F_107 ( struct V_335 * V_336 )
{
while ( ! F_119 ( & V_336 -> V_355 ) ) {
struct V_360 * V_367 = V_336 -> V_355 . V_346 ;
F_120 ( V_367 ) ;
F_35 ( F_117 ( V_367 , struct V_350 , V_362 ) ) ;
}
F_35 ( V_336 -> V_271 ) ;
F_35 ( V_336 -> V_298 ) ;
F_35 ( V_336 -> V_326 ) ;
F_35 ( V_336 -> V_352 ) ;
#ifdef F_111
F_35 ( V_336 -> V_353 ) ;
#endif
}
static struct V_38 * F_121 ( struct V_272 * V_368 ,
struct V_38 * V_369 )
{
struct V_38 * V_331 = V_368 -> V_5 -> V_113 ;
if ( V_331 )
return V_331 ;
return V_369 ;
}
static struct V_38 * F_122 ( struct V_38 * V_370 ,
struct V_38 * V_369 )
{
struct V_38 * V_331 ;
V_331 = V_370 -> V_371 ;
if ( V_331 )
return V_331 ;
if ( V_370 == V_369 )
return NULL ;
return V_369 ;
}
static void F_123 ( struct V_16 * V_247 , struct V_372 * V_373 ,
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
static T_2 F_124 ( struct V_38 * V_369 ,
unsigned long V_195 )
{
struct V_38 * V_39 ;
T_2 V_87 = 0 ;
for ( V_39 = F_121 ( V_4 , V_369 ) ; V_39 != NULL ;
V_39 = F_122 ( V_39 , V_369 ) )
V_87 += F_65 ( V_39 , V_195 ) ;
return V_87 ;
}
static int F_125 ( struct V_384 * V_385 )
{
int V_386 = 0 ;
T_7 V_221 ;
int V_248 ;
T_2 V_87 = 0 ;
struct V_38 * V_39 , * V_369 ;
struct V_16 * V_247 = NULL ;
T_8 V_265 = 0 , V_387 , V_241 ;
struct V_335 V_336 ;
struct V_51 * V_388 = NULL ;
struct V_372 * V_373 = NULL ;
T_11 V_53 ;
T_1 V_374 ;
V_247 = F_33 ( sizeof( * V_247 ) , V_115 ) ;
if ( ! V_247 )
goto V_111;
V_248 = V_4 -> V_5 -> V_389 ;
V_248 += F_126 () ;
V_369 = F_127 ( V_4 -> V_5 ) ;
if ( V_369 != NULL )
V_248 ++ ;
V_248 ++ ;
V_53 = V_248 > V_390 ? V_390 : V_248 ;
if ( ! F_100 ( V_247 , V_53 , & V_336 , V_385 -> V_273 , V_385 -> V_143 ) )
goto V_391;
V_386 = 1 ;
V_4 -> V_136 |= V_392 ;
V_221 = F_67 () ;
F_69 ( V_393 ) ;
V_265 += sizeof( * V_247 ) ;
V_265 += V_248 * sizeof( struct V_51 ) ;
V_241 = V_265 ;
{
T_2 V_237 = F_105 ( & V_336 ) ;
V_237 += F_128 () ;
V_388 = F_33 ( sizeof( * V_388 ) , V_115 ) ;
if ( ! V_388 )
goto V_394;
F_77 ( V_388 , V_237 , V_265 ) ;
V_265 += V_237 ;
}
V_387 = V_265 = F_72 ( V_265 , V_45 ) ;
V_265 += F_124 ( V_369 , V_385 -> V_195 ) ;
V_265 += F_129 () ;
V_374 = V_265 ;
if ( V_53 == V_390 ) {
V_373 = F_33 ( sizeof( * V_373 ) , V_115 ) ;
if ( ! V_373 )
goto V_394;
F_123 ( V_247 , V_373 , V_374 , V_248 ) ;
}
V_265 = V_387 ;
V_87 += sizeof( * V_247 ) ;
if ( V_87 > V_385 -> V_395 || ! F_130 ( V_385 -> V_81 , V_247 , sizeof( * V_247 ) ) )
goto V_394;
V_87 += sizeof( * V_388 ) ;
if ( V_87 > V_385 -> V_395
|| ! F_130 ( V_385 -> V_81 , V_388 , sizeof( * V_388 ) ) )
goto V_394;
for ( V_39 = F_121 ( V_4 , V_369 ) ; V_39 != NULL ;
V_39 = F_122 ( V_39 , V_369 ) ) {
struct V_51 V_264 ;
V_264 . V_97 = V_98 ;
V_264 . V_91 = V_265 ;
V_264 . V_89 = V_39 -> V_219 ;
V_264 . V_267 = 0 ;
V_264 . V_88 = F_65 ( V_39 , V_385 -> V_195 ) ;
V_264 . V_99 = V_39 -> V_234 - V_39 -> V_219 ;
V_265 += V_264 . V_88 ;
V_264 . V_124 = V_39 -> V_196 & V_217 ? V_125 : 0 ;
if ( V_39 -> V_196 & V_396 )
V_264 . V_124 |= V_127 ;
if ( V_39 -> V_196 & V_397 )
V_264 . V_124 |= V_129 ;
V_264 . V_268 = V_45 ;
V_87 += sizeof( V_264 ) ;
if ( V_87 > V_385 -> V_395
|| ! F_130 ( V_385 -> V_81 , & V_264 , sizeof( V_264 ) ) )
goto V_394;
}
if ( ! F_131 ( V_385 -> V_81 , V_265 , & V_87 , V_385 -> V_395 ) )
goto V_394;
if ( ! F_106 ( & V_336 , V_385 -> V_81 , & V_241 ) )
goto V_394;
if ( F_132 ( V_385 -> V_81 , & V_241 ) )
goto V_394;
if ( ! F_133 ( V_385 -> V_81 , V_387 - V_241 ) )
goto V_394;
for ( V_39 = F_121 ( V_4 , V_369 ) ; V_39 != NULL ;
V_39 = F_122 ( V_39 , V_369 ) ) {
unsigned long V_3 ;
unsigned long V_2 ;
V_2 = V_39 -> V_219 + F_65 ( V_39 , V_385 -> V_195 ) ;
for ( V_3 = V_39 -> V_219 ; V_3 < V_2 ; V_3 += V_192 ) {
struct V_398 * V_398 ;
int V_399 ;
V_398 = F_134 ( V_3 ) ;
if ( V_398 ) {
void * V_400 = F_135 ( V_398 ) ;
V_399 = ( ( V_87 += V_192 ) > V_385 -> V_395 ) ||
! F_130 ( V_385 -> V_81 , V_400 ,
V_192 ) ;
F_136 ( V_398 ) ;
F_137 ( V_398 ) ;
} else
V_399 = ! F_133 ( V_385 -> V_81 , V_192 ) ;
if ( V_399 )
goto V_394;
}
}
if ( ! F_138 ( V_385 -> V_81 , & V_87 , V_385 -> V_395 ) )
goto V_394;
if ( V_53 == V_390 ) {
V_87 += sizeof( * V_373 ) ;
if ( V_87 > V_385 -> V_395
|| ! F_130 ( V_385 -> V_81 , V_373 ,
sizeof( * V_373 ) ) )
goto V_394;
}
V_394:
F_69 ( V_221 ) ;
V_391:
F_107 ( & V_336 ) ;
F_35 ( V_373 ) ;
F_35 ( V_388 ) ;
F_35 ( V_247 ) ;
V_111:
return V_386 ;
}
static int T_12 F_139 ( void )
{
return F_140 ( & V_189 ) ;
}
static void T_13 F_141 ( void )
{
F_142 ( & V_189 ) ;
}
