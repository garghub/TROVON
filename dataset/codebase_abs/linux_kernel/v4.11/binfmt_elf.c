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
T_1 V_13 * V_28 ;
T_1 V_13 * V_29 ;
const char * V_30 = V_31 ;
const char * V_32 = V_33 ;
unsigned char V_34 [ 16 ] ;
int V_35 ;
T_1 * V_36 ;
int V_37 = 0 ;
const struct V_38 * V_38 = F_8 () ;
struct V_39 * V_40 ;
V_21 = F_9 ( V_21 ) ;
V_27 = NULL ;
if ( V_30 ) {
T_2 V_41 = strlen ( V_30 ) + 1 ;
V_27 = ( T_1 V_13 * ) F_10 ( V_21 , V_41 ) ;
if ( F_11 ( V_27 , V_30 , V_41 ) )
return - V_14 ;
}
V_28 = NULL ;
if ( V_32 ) {
T_2 V_41 = strlen ( V_32 ) + 1 ;
V_28 = ( T_1 V_13 * ) F_10 ( V_21 , V_41 ) ;
if ( F_11 ( V_28 , V_32 , V_41 ) )
return - V_14 ;
}
F_12 ( V_34 , sizeof( V_34 ) ) ;
V_29 = ( T_1 V_13 * )
F_10 ( V_21 , sizeof( V_34 ) ) ;
if ( F_11 ( V_29 , V_34 , sizeof( V_34 ) ) )
return - V_14 ;
V_36 = ( T_1 * ) V_6 -> V_7 -> V_42 ;
#define F_13 ( T_3 , T_4 ) \
do { \
elf_info[ei_index++] = id; \
elf_info[ei_index++] = val; \
} while (0)
#ifdef F_14
F_14 ;
#endif
F_13 ( V_43 , V_44 ) ;
F_13 ( V_45 , V_46 ) ;
F_13 ( V_47 , V_48 ) ;
F_13 ( V_49 , V_19 + V_18 -> V_50 ) ;
F_13 ( V_51 , sizeof( struct V_52 ) ) ;
F_13 ( V_53 , V_18 -> V_54 ) ;
F_13 ( V_55 , V_20 ) ;
F_13 ( V_56 , 0 ) ;
F_13 ( V_57 , V_18 -> V_58 ) ;
F_13 ( V_59 , F_15 ( V_38 -> V_60 , V_38 -> V_61 ) ) ;
F_13 ( V_62 , F_15 ( V_38 -> V_60 , V_38 -> V_63 ) ) ;
F_13 ( V_64 , F_16 ( V_38 -> V_60 , V_38 -> V_65 ) ) ;
F_13 ( V_66 , F_16 ( V_38 -> V_60 , V_38 -> V_67 ) ) ;
F_13 ( V_68 , F_17 ( V_16 ) ) ;
F_13 ( V_69 , ( T_1 ) ( unsigned long ) V_29 ) ;
#ifdef F_18
F_13 ( V_70 , F_18 ) ;
#endif
F_13 ( V_71 , V_16 -> V_18 ) ;
if ( V_30 ) {
F_13 ( V_72 ,
( T_1 ) ( unsigned long ) V_27 ) ;
}
if ( V_32 ) {
F_13 ( V_73 ,
( T_1 ) ( unsigned long ) V_28 ) ;
}
if ( V_16 -> V_74 & V_75 ) {
F_13 ( V_76 , V_16 -> V_77 ) ;
}
#undef F_13
memset ( & V_36 [ V_37 ] , 0 ,
sizeof V_6 -> V_7 -> V_42 - V_37 * sizeof V_36 [ 0 ] ) ;
V_37 += 2 ;
V_26 = F_19 ( V_21 , V_37 ) ;
V_35 = ( V_22 + 1 ) + ( V_23 + 1 ) + 1 ;
V_16 -> V_21 = F_20 ( V_26 , V_35 ) ;
#ifdef F_21
V_26 = ( T_1 V_13 * ) V_16 -> V_21 - V_35 - V_37 ;
V_16 -> V_18 = ( unsigned long ) V_26 ;
#else
V_26 = ( T_1 V_13 * ) V_16 -> V_21 ;
#endif
V_40 = F_22 ( V_6 -> V_7 , V_16 -> V_21 ) ;
if ( ! V_40 )
return - V_14 ;
if ( F_23 ( V_22 , V_26 ++ ) )
return - V_14 ;
V_24 = V_26 ;
V_25 = V_24 + V_22 + 1 ;
V_21 = V_6 -> V_7 -> V_78 = V_6 -> V_7 -> V_79 ;
while ( V_22 -- > 0 ) {
T_2 V_41 ;
if ( F_23 ( ( T_1 ) V_21 , V_24 ++ ) )
return - V_14 ;
V_41 = F_24 ( ( void V_13 * ) V_21 , V_80 ) ;
if ( ! V_41 || V_41 > V_80 )
return - V_81 ;
V_21 += V_41 ;
}
if ( F_23 ( 0 , V_24 ) )
return - V_14 ;
V_6 -> V_7 -> V_78 = V_6 -> V_7 -> V_82 = V_21 ;
while ( V_23 -- > 0 ) {
T_2 V_41 ;
if ( F_23 ( ( T_1 ) V_21 , V_25 ++ ) )
return - V_14 ;
V_41 = F_24 ( ( void V_13 * ) V_21 , V_80 ) ;
if ( ! V_41 || V_41 > V_80 )
return - V_81 ;
V_21 += V_41 ;
}
if ( F_23 ( 0 , V_25 ) )
return - V_14 ;
V_6 -> V_7 -> V_83 = V_21 ;
V_26 = ( T_1 V_13 * ) V_25 + 1 ;
if ( F_25 ( V_26 , V_36 , V_37 * sizeof( T_1 ) ) )
return - V_14 ;
return 0 ;
}
static unsigned long F_26 ( struct V_84 * V_85 , unsigned long V_86 ,
struct V_52 * V_87 , int V_3 , int type ,
unsigned long V_88 )
{
unsigned long V_89 ;
unsigned long V_90 = V_87 -> V_91 + F_5 ( V_87 -> V_92 ) ;
unsigned long V_93 = V_87 -> V_94 - F_5 ( V_87 -> V_92 ) ;
V_86 = F_27 ( V_86 ) ;
V_90 = F_2 ( V_90 ) ;
if ( ! V_90 )
return V_86 ;
if ( V_88 ) {
V_88 = F_2 ( V_88 ) ;
V_89 = F_28 ( V_85 , V_86 , V_88 , V_3 , type , V_93 ) ;
if ( ! F_29 ( V_89 ) )
F_30 ( V_89 + V_90 , V_88 - V_90 ) ;
} else
V_89 = F_28 ( V_85 , V_86 , V_90 , V_3 , type , V_93 ) ;
return ( V_89 ) ;
}
static unsigned long F_31 ( struct V_52 * V_95 , int V_96 )
{
int V_97 , V_98 = - 1 , V_99 = - 1 ;
for ( V_97 = 0 ; V_97 < V_96 ; V_97 ++ ) {
if ( V_95 [ V_97 ] . V_100 == V_101 ) {
V_99 = V_97 ;
if ( V_98 == - 1 )
V_98 = V_97 ;
}
}
if ( V_98 == - 1 )
return 0 ;
return V_95 [ V_99 ] . V_92 + V_95 [ V_99 ] . V_102 -
F_27 ( V_95 [ V_98 ] . V_92 ) ;
}
static struct V_52 * F_32 ( struct V_17 * V_103 ,
struct V_84 * V_104 )
{
struct V_52 * V_105 = NULL ;
int V_106 , V_90 , V_107 = - 1 ;
if ( V_103 -> V_108 != sizeof( struct V_52 ) )
goto V_109;
if ( V_103 -> V_54 < 1 ||
V_103 -> V_54 > 65536U / sizeof( struct V_52 ) )
goto V_109;
V_90 = sizeof( struct V_52 ) * V_103 -> V_54 ;
if ( V_90 > V_12 )
goto V_109;
V_105 = F_33 ( V_90 , V_110 ) ;
if ( ! V_105 )
goto V_109;
V_106 = F_34 ( V_104 , V_103 -> V_50 ,
( char * ) V_105 , V_90 ) ;
if ( V_106 != V_90 ) {
V_107 = ( V_106 < 0 ) ? V_106 : - V_111 ;
goto V_109;
}
V_107 = 0 ;
V_109:
if ( V_107 ) {
F_35 ( V_105 ) ;
V_105 = NULL ;
}
return V_105 ;
}
static inline int F_36 ( struct V_17 * V_112 ,
struct V_52 * V_113 ,
struct V_84 * V_114 , bool V_115 ,
struct V_116 * V_117 )
{
return 0 ;
}
static inline int F_37 ( struct V_17 * V_112 , bool V_118 ,
struct V_17 * V_119 ,
struct V_116 * V_117 )
{
return 0 ;
}
static unsigned long F_38 ( struct V_17 * V_120 ,
struct V_84 * V_121 , unsigned long * V_122 ,
unsigned long V_123 , struct V_52 * V_124 )
{
struct V_52 * V_87 ;
unsigned long V_19 = 0 ;
int V_125 = 0 ;
unsigned long V_126 = 0 , V_10 = 0 ;
int V_127 = 0 ;
unsigned long error = ~ 0UL ;
unsigned long V_88 ;
int V_97 ;
if ( V_120 -> V_128 != V_129 &&
V_120 -> V_128 != V_130 )
goto V_109;
if ( ! F_39 ( V_120 ) )
goto V_109;
if ( ! V_121 -> V_131 -> V_132 )
goto V_109;
V_88 = F_31 ( V_124 ,
V_120 -> V_54 ) ;
if ( ! V_88 ) {
error = - V_81 ;
goto V_109;
}
V_87 = V_124 ;
for ( V_97 = 0 ; V_97 < V_120 -> V_54 ; V_97 ++ , V_87 ++ ) {
if ( V_87 -> V_100 == V_101 ) {
int V_133 = V_134 | V_135 ;
int V_136 = 0 ;
unsigned long V_137 = 0 ;
unsigned long V_138 , V_89 ;
if ( V_87 -> V_139 & V_140 )
V_136 = V_141 ;
if ( V_87 -> V_139 & V_142 )
V_136 |= V_143 ;
if ( V_87 -> V_139 & V_144 )
V_136 |= V_4 ;
V_137 = V_87 -> V_92 ;
if ( V_120 -> V_128 == V_129 || V_125 )
V_133 |= V_145 ;
else if ( V_123 && V_120 -> V_128 == V_130 )
V_19 = - V_137 ;
V_89 = F_26 ( V_121 , V_19 + V_137 ,
V_87 , V_136 , V_133 , V_88 ) ;
V_88 = 0 ;
if ( ! * V_122 )
* V_122 = V_89 ;
error = V_89 ;
if ( F_29 ( V_89 ) )
goto V_109;
if ( ! V_125 &&
V_120 -> V_128 == V_130 ) {
V_19 = V_89 - F_27 ( V_137 ) ;
V_125 = 1 ;
}
V_138 = V_19 + V_87 -> V_92 ;
if ( F_29 ( V_138 ) ||
V_87 -> V_91 > V_87 -> V_102 ||
V_87 -> V_102 > V_146 ||
V_146 - V_87 -> V_102 < V_138 ) {
error = - V_147 ;
goto V_109;
}
V_138 = V_19 + V_87 -> V_92 + V_87 -> V_91 ;
if ( V_138 > V_10 )
V_10 = V_138 ;
V_138 = V_19 + V_87 -> V_92 + V_87 -> V_102 ;
if ( V_138 > V_126 ) {
V_126 = V_138 ;
V_127 = V_136 ;
}
}
}
if ( F_4 ( V_10 ) ) {
error = - V_14 ;
goto V_109;
}
V_10 = F_2 ( V_10 ) ;
V_126 = F_2 ( V_126 ) ;
if ( V_126 > V_10 ) {
error = F_3 ( V_10 , V_126 - V_10 ,
V_127 & V_4 ? V_5 : 0 ) ;
if ( error )
goto V_109;
}
error = V_19 ;
V_109:
return error ;
}
static unsigned long F_40 ( unsigned long V_148 )
{
unsigned long V_149 = 0 ;
if ( ( V_6 -> V_150 & V_151 ) &&
! ( V_6 -> V_152 & V_153 ) ) {
V_149 = F_41 () ;
V_149 &= V_154 ;
V_149 <<= V_155 ;
}
#ifdef F_21
return F_42 ( V_148 ) + V_149 ;
#else
return F_42 ( V_148 ) - V_149 ;
#endif
}
static int F_43 ( struct V_15 * V_16 )
{
struct V_84 * V_121 = NULL ;
unsigned long V_19 = 0 , V_156 = 0 ;
int V_125 = 0 ;
char * V_157 = NULL ;
unsigned long error ;
struct V_52 * V_158 , * V_105 , * V_124 = NULL ;
unsigned long V_10 , V_159 ;
int V_127 = 0 ;
int V_106 , V_97 ;
unsigned long V_160 ;
unsigned long V_20 = 0 ;
unsigned long V_161 , V_162 , V_163 , V_164 ;
unsigned long T_5 V_165 = 0 ;
int V_166 = V_167 ;
struct V_168 * V_169 = F_44 () ;
struct {
struct V_17 V_103 ;
struct V_17 V_120 ;
} * V_170 ;
struct V_116 V_171 = V_172 ;
V_170 = F_33 ( sizeof( * V_170 ) , V_110 ) ;
if ( ! V_170 ) {
V_106 = - V_147 ;
goto V_173;
}
V_170 -> V_103 = * ( (struct V_17 * ) V_16 -> V_174 ) ;
V_106 = - V_175 ;
if ( memcmp ( V_170 -> V_103 . V_176 , V_177 , V_178 ) != 0 )
goto V_109;
if ( V_170 -> V_103 . V_128 != V_129 && V_170 -> V_103 . V_128 != V_130 )
goto V_109;
if ( ! F_39 ( & V_170 -> V_103 ) )
goto V_109;
if ( ! V_16 -> V_84 -> V_131 -> V_132 )
goto V_109;
V_105 = F_32 ( & V_170 -> V_103 , V_16 -> V_84 ) ;
if ( ! V_105 )
goto V_109;
V_158 = V_105 ;
V_10 = 0 ;
V_159 = 0 ;
V_161 = ~ 0UL ;
V_162 = 0 ;
V_163 = 0 ;
V_164 = 0 ;
for ( V_97 = 0 ; V_97 < V_170 -> V_103 . V_54 ; V_97 ++ ) {
if ( V_158 -> V_100 == V_179 ) {
V_106 = - V_175 ;
if ( V_158 -> V_91 > V_180 ||
V_158 -> V_91 < 2 )
goto V_181;
V_106 = - V_147 ;
V_157 = F_33 ( V_158 -> V_91 ,
V_110 ) ;
if ( ! V_157 )
goto V_181;
V_106 = F_34 ( V_16 -> V_84 , V_158 -> V_94 ,
V_157 ,
V_158 -> V_91 ) ;
if ( V_106 != V_158 -> V_91 ) {
if ( V_106 >= 0 )
V_106 = - V_111 ;
goto V_182;
}
V_106 = - V_175 ;
if ( V_157 [ V_158 -> V_91 - 1 ] != '\0' )
goto V_182;
V_121 = F_45 ( V_157 ) ;
V_106 = F_46 ( V_121 ) ;
if ( F_47 ( V_121 ) )
goto V_182;
F_48 ( V_16 , V_121 ) ;
V_106 = F_34 ( V_121 , 0 ,
( void * ) & V_170 -> V_120 ,
sizeof( V_170 -> V_120 ) ) ;
if ( V_106 != sizeof( V_170 -> V_120 ) ) {
if ( V_106 >= 0 )
V_106 = - V_111 ;
goto V_183;
}
break;
}
V_158 ++ ;
}
V_158 = V_105 ;
for ( V_97 = 0 ; V_97 < V_170 -> V_103 . V_54 ; V_97 ++ , V_158 ++ )
switch ( V_158 -> V_100 ) {
case V_184 :
if ( V_158 -> V_139 & V_144 )
V_166 = V_185 ;
else
V_166 = V_186 ;
break;
case V_187 ... V_188 :
V_106 = F_36 ( & V_170 -> V_103 , V_158 ,
V_16 -> V_84 , false ,
& V_171 ) ;
if ( V_106 )
goto V_183;
break;
}
if ( V_157 ) {
V_106 = - V_189 ;
if ( memcmp ( V_170 -> V_120 . V_176 , V_177 , V_178 ) != 0 )
goto V_183;
if ( ! F_39 ( & V_170 -> V_120 ) )
goto V_183;
V_124 = F_32 ( & V_170 -> V_120 ,
V_121 ) ;
if ( ! V_124 )
goto V_183;
V_158 = V_124 ;
for ( V_97 = 0 ; V_97 < V_170 -> V_120 . V_54 ; V_97 ++ , V_158 ++ )
switch ( V_158 -> V_100 ) {
case V_187 ... V_188 :
V_106 = F_36 ( & V_170 -> V_120 ,
V_158 , V_121 ,
true , & V_171 ) ;
if ( V_106 )
goto V_183;
break;
}
}
V_106 = F_37 ( & V_170 -> V_103 ,
! ! V_121 , & V_170 -> V_120 ,
& V_171 ) ;
if ( V_106 )
goto V_183;
V_106 = F_49 ( V_16 ) ;
if ( V_106 )
goto V_183;
F_50 ( V_170 -> V_103 , & V_171 ) ;
if ( F_51 ( V_170 -> V_103 , V_166 ) )
V_6 -> V_152 |= V_190 ;
if ( ! ( V_6 -> V_152 & V_153 ) && V_191 )
V_6 -> V_150 |= V_151 ;
F_52 ( V_16 ) ;
F_53 ( V_16 ) ;
V_106 = F_54 ( V_16 , F_40 ( V_192 ) ,
V_166 ) ;
if ( V_106 < 0 )
goto V_183;
V_6 -> V_7 -> V_193 = V_16 -> V_21 ;
for( V_97 = 0 , V_158 = V_105 ;
V_97 < V_170 -> V_103 . V_54 ; V_97 ++ , V_158 ++ ) {
int V_136 = 0 , V_194 ;
unsigned long V_138 , V_137 ;
unsigned long V_88 = 0 ;
if ( V_158 -> V_100 != V_101 )
continue;
if ( F_55 ( V_159 > V_10 ) ) {
unsigned long V_11 ;
V_106 = F_1 ( V_10 + V_156 ,
V_159 + V_156 ,
V_127 ) ;
if ( V_106 )
goto V_183;
V_11 = F_5 ( V_10 ) ;
if ( V_11 ) {
V_11 = V_12 - V_11 ;
if ( V_11 > V_159 - V_10 )
V_11 = V_159 - V_10 ;
if ( F_6 ( ( void V_13 * ) V_10 +
V_156 , V_11 ) ) {
}
}
}
if ( V_158 -> V_139 & V_140 )
V_136 |= V_141 ;
if ( V_158 -> V_139 & V_142 )
V_136 |= V_143 ;
if ( V_158 -> V_139 & V_144 )
V_136 |= V_4 ;
V_194 = V_134 | V_135 | V_195 ;
V_137 = V_158 -> V_92 ;
if ( V_170 -> V_103 . V_128 == V_129 || V_125 ) {
V_194 |= V_145 ;
} else if ( V_170 -> V_103 . V_128 == V_130 ) {
V_156 = V_196 - V_137 ;
if ( V_6 -> V_150 & V_151 )
V_156 += F_56 () ;
V_156 = F_27 ( V_156 ) ;
V_88 = F_31 ( V_105 ,
V_170 -> V_103 . V_54 ) ;
if ( ! V_88 ) {
V_106 = - V_81 ;
goto V_183;
}
}
error = F_26 ( V_16 -> V_84 , V_156 + V_137 , V_158 ,
V_136 , V_194 , V_88 ) ;
if ( F_29 ( error ) ) {
V_106 = F_47 ( ( void * ) error ) ?
F_46 ( ( void * ) error ) : - V_81 ;
goto V_183;
}
if ( ! V_125 ) {
V_125 = 1 ;
V_19 = ( V_158 -> V_92 - V_158 -> V_94 ) ;
if ( V_170 -> V_103 . V_128 == V_130 ) {
V_156 += error -
F_27 ( V_156 + V_137 ) ;
V_19 += V_156 ;
T_5 = V_156 ;
}
}
V_138 = V_158 -> V_92 ;
if ( V_138 < V_161 )
V_161 = V_138 ;
if ( V_163 < V_138 )
V_163 = V_138 ;
if ( F_29 ( V_138 ) || V_158 -> V_91 > V_158 -> V_102 ||
V_158 -> V_102 > V_146 ||
V_146 - V_158 -> V_102 < V_138 ) {
V_106 = - V_81 ;
goto V_183;
}
V_138 = V_158 -> V_92 + V_158 -> V_91 ;
if ( V_138 > V_10 )
V_10 = V_138 ;
if ( ( V_158 -> V_139 & V_144 ) && V_162 < V_138 )
V_162 = V_138 ;
if ( V_164 < V_138 )
V_164 = V_138 ;
V_138 = V_158 -> V_92 + V_158 -> V_102 ;
if ( V_138 > V_159 ) {
V_127 = V_136 ;
V_159 = V_138 ;
}
}
V_170 -> V_103 . V_58 += V_156 ;
V_10 += V_156 ;
V_159 += V_156 ;
V_161 += V_156 ;
V_162 += V_156 ;
V_163 += V_156 ;
V_164 += V_156 ;
V_106 = F_1 ( V_10 , V_159 , V_127 ) ;
if ( V_106 )
goto V_183;
if ( F_57 ( V_10 != V_159 ) && F_55 ( F_4 ( V_10 ) ) ) {
V_106 = - V_14 ;
goto V_183;
}
if ( V_157 ) {
unsigned long V_122 = 0 ;
V_160 = F_38 ( & V_170 -> V_120 ,
V_121 ,
& V_122 ,
V_156 , V_124 ) ;
if ( ! F_47 ( ( void * ) V_160 ) ) {
V_20 = V_160 ;
V_160 += V_170 -> V_120 . V_58 ;
}
if ( F_29 ( V_160 ) ) {
V_106 = F_47 ( ( void * ) V_160 ) ?
( int ) V_160 : - V_81 ;
goto V_183;
}
T_5 = V_20 ;
F_58 ( V_121 ) ;
F_59 ( V_121 ) ;
F_35 ( V_157 ) ;
} else {
V_160 = V_170 -> V_103 . V_58 ;
if ( F_29 ( V_160 ) ) {
V_106 = - V_81 ;
goto V_183;
}
}
F_35 ( V_124 ) ;
F_35 ( V_105 ) ;
F_60 ( & V_197 ) ;
#ifdef F_61
V_106 = F_62 ( V_16 , ! ! V_157 ) ;
if ( V_106 < 0 )
goto V_109;
#endif
V_106 = F_7 ( V_16 , & V_170 -> V_103 ,
V_19 , V_20 ) ;
if ( V_106 < 0 )
goto V_109;
V_6 -> V_7 -> V_162 = V_162 ;
V_6 -> V_7 -> V_161 = V_161 ;
V_6 -> V_7 -> V_163 = V_163 ;
V_6 -> V_7 -> V_164 = V_164 ;
V_6 -> V_7 -> V_193 = V_16 -> V_21 ;
if ( ( V_6 -> V_150 & V_151 ) && ( V_191 > 1 ) ) {
V_6 -> V_7 -> V_9 = V_6 -> V_7 -> V_8 =
F_63 ( V_6 -> V_7 ) ;
#ifdef F_64
V_6 -> V_198 = 1 ;
#endif
}
if ( V_6 -> V_152 & V_199 ) {
error = F_28 ( NULL , 0 , V_200 , V_141 | V_4 ,
V_145 | V_134 , 0 ) ;
}
#ifdef F_65
F_65 ( V_169 , T_5 ) ;
#endif
F_66 ( V_169 , V_160 , V_16 -> V_21 ) ;
V_106 = 0 ;
V_109:
F_35 ( V_170 ) ;
V_173:
return V_106 ;
V_183:
F_35 ( V_124 ) ;
F_58 ( V_121 ) ;
if ( V_121 )
F_59 ( V_121 ) ;
V_182:
F_35 ( V_157 ) ;
V_181:
F_35 ( V_105 ) ;
goto V_109;
}
static int F_67 ( struct V_84 * V_84 )
{
struct V_52 * V_105 ;
struct V_52 * V_87 ;
unsigned long V_10 , V_201 , V_41 ;
int V_106 , error , V_97 , V_202 ;
struct V_17 V_103 ;
error = - V_175 ;
V_106 = F_34 ( V_84 , 0 , ( char * ) & V_103 , sizeof( V_103 ) ) ;
if ( V_106 != sizeof( V_103 ) )
goto V_109;
if ( memcmp ( V_103 . V_176 , V_177 , V_178 ) != 0 )
goto V_109;
if ( V_103 . V_128 != V_129 || V_103 . V_54 > 2 ||
! F_39 ( & V_103 ) || ! V_84 -> V_131 -> V_132 )
goto V_109;
V_202 = sizeof( struct V_52 ) * V_103 . V_54 ;
error = - V_147 ;
V_105 = F_33 ( V_202 , V_110 ) ;
if ( ! V_105 )
goto V_109;
V_87 = V_105 ;
error = - V_175 ;
V_106 = F_34 ( V_84 , V_103 . V_50 , ( char * ) V_87 , V_202 ) ;
if ( V_106 != V_202 )
goto V_181;
for ( V_202 = 0 , V_97 = 0 ; V_97 < V_103 . V_54 ; V_97 ++ )
if ( ( V_87 + V_97 ) -> V_100 == V_101 )
V_202 ++ ;
if ( V_202 != 1 )
goto V_181;
while ( V_87 -> V_100 != V_101 )
V_87 ++ ;
error = F_28 ( V_84 ,
F_27 ( V_87 -> V_92 ) ,
( V_87 -> V_91 +
F_5 ( V_87 -> V_92 ) ) ,
V_141 | V_143 | V_4 ,
V_145 | V_134 | V_135 ,
( V_87 -> V_94 -
F_5 ( V_87 -> V_92 ) ) ) ;
if ( error != F_27 ( V_87 -> V_92 ) )
goto V_181;
V_10 = V_87 -> V_92 + V_87 -> V_91 ;
if ( F_4 ( V_10 ) ) {
error = - V_14 ;
goto V_181;
}
V_41 = F_27 ( V_87 -> V_91 + V_87 -> V_92 +
V_12 - 1 ) ;
V_201 = V_87 -> V_102 + V_87 -> V_92 ;
if ( V_201 > V_41 ) {
error = F_68 ( V_41 , V_201 - V_41 ) ;
if ( error )
goto V_181;
}
error = 0 ;
V_181:
F_35 ( V_105 ) ;
V_109:
return error ;
}
static bool F_69 ( struct V_39 * V_40 )
{
if ( V_40 == F_70 ( V_40 -> V_203 ) )
return true ;
if ( V_40 -> V_204 && V_40 -> V_204 -> V_205 && V_40 -> V_204 -> V_205 ( V_40 ) )
return true ;
if ( F_71 ( V_40 ) )
return true ;
return false ;
}
static unsigned long F_72 ( struct V_39 * V_40 ,
unsigned long V_206 )
{
#define F_73 ( type ) (mm_flags & (1UL << MMF_DUMP_##type))
if ( F_69 ( V_40 ) )
goto V_207;
if ( V_40 -> V_208 & V_209 )
return 0 ;
if ( F_74 ( V_40 ) ) {
if ( ( V_40 -> V_208 & V_210 ) && F_73 ( V_211 ) )
goto V_207;
if ( ! ( V_40 -> V_208 & V_210 ) && F_73 ( V_212 ) )
goto V_207;
return 0 ;
}
if ( V_40 -> V_208 & V_213 ) {
if ( ( V_40 -> V_208 & V_210 ) && F_73 ( V_214 ) )
goto V_207;
if ( ! ( V_40 -> V_208 & V_210 ) && F_73 ( V_215 ) )
goto V_207;
return 0 ;
}
if ( V_40 -> V_208 & V_216 )
return 0 ;
if ( V_40 -> V_208 & V_210 ) {
if ( F_75 ( V_40 -> V_217 ) -> V_218 == 0 ?
F_73 ( V_219 ) : F_73 ( V_220 ) )
goto V_207;
return 0 ;
}
if ( V_40 -> V_221 && F_73 ( V_222 ) )
goto V_207;
if ( V_40 -> V_217 == NULL )
return 0 ;
if ( F_73 ( V_223 ) )
goto V_207;
if ( F_73 ( V_224 ) &&
V_40 -> V_225 == 0 && ( V_40 -> V_208 & V_226 ) ) {
T_6 V_13 * V_227 = ( T_6 V_13 * ) V_40 -> V_228 ;
T_6 V_229 ;
T_7 V_230 = F_76 () ;
union {
T_6 V_231 ;
char V_232 [ V_178 ] ;
} V_233 ;
F_77 ( V_178 != sizeof V_229 ) ;
V_233 . V_232 [ V_234 ] = V_235 ;
V_233 . V_232 [ V_236 ] = V_237 ;
V_233 . V_232 [ V_238 ] = V_239 ;
V_233 . V_232 [ V_240 ] = V_241 ;
F_78 ( V_242 ) ;
if ( F_55 ( F_79 ( V_229 , V_227 ) ) )
V_229 = 0 ;
F_78 ( V_230 ) ;
if ( V_229 == V_233 . V_231 )
return V_200 ;
}
#undef F_73
return 0 ;
V_207:
return V_40 -> V_243 - V_40 -> V_228 ;
}
static int F_80 ( struct V_244 * V_245 )
{
int V_246 ;
V_246 = sizeof( struct V_247 ) ;
V_246 += F_81 ( strlen ( V_245 -> V_205 ) + 1 , 4 ) ;
V_246 += F_81 ( V_245 -> V_248 , 4 ) ;
return V_246 ;
}
static int F_82 ( struct V_244 * V_249 , struct V_250 * V_251 )
{
struct V_247 V_245 ;
V_245 . V_252 = strlen ( V_249 -> V_205 ) + 1 ;
V_245 . V_253 = V_249 -> V_248 ;
V_245 . V_254 = V_249 -> type ;
return F_83 ( V_251 , & V_245 , sizeof( V_245 ) ) &&
F_83 ( V_251 , V_249 -> V_205 , V_245 . V_252 ) && F_84 ( V_251 , 4 ) &&
F_83 ( V_251 , V_249 -> V_255 , V_249 -> V_248 ) && F_84 ( V_251 , 4 ) ;
}
static void F_85 ( struct V_17 * V_114 , int V_256 ,
T_8 V_257 , T_6 V_150 )
{
memset ( V_114 , 0 , sizeof( * V_114 ) ) ;
memcpy ( V_114 -> V_176 , V_177 , V_178 ) ;
V_114 -> V_176 [ V_258 ] = V_259 ;
V_114 -> V_176 [ V_260 ] = V_261 ;
V_114 -> V_176 [ V_262 ] = V_263 ;
V_114 -> V_176 [ V_264 ] = V_265 ;
V_114 -> V_128 = V_266 ;
V_114 -> V_267 = V_257 ;
V_114 -> V_268 = V_263 ;
V_114 -> V_50 = sizeof( struct V_17 ) ;
V_114 -> V_269 = V_150 ;
V_114 -> V_270 = sizeof( struct V_17 ) ;
V_114 -> V_108 = sizeof( struct V_52 ) ;
V_114 -> V_54 = V_256 ;
return;
}
static void F_86 ( struct V_52 * V_113 , int V_246 , T_9 V_271 )
{
V_113 -> V_100 = V_272 ;
V_113 -> V_94 = V_271 ;
V_113 -> V_92 = 0 ;
V_113 -> V_273 = 0 ;
V_113 -> V_91 = V_246 ;
V_113 -> V_102 = 0 ;
V_113 -> V_139 = 0 ;
V_113 -> V_274 = 0 ;
return;
}
static void F_87 ( struct V_244 * V_275 , const char * V_205 , int type ,
unsigned int V_246 , void * V_255 )
{
V_275 -> V_205 = V_205 ;
V_275 -> type = type ;
V_275 -> V_248 = V_246 ;
V_275 -> V_255 = V_255 ;
return;
}
static void F_88 ( struct V_276 * V_277 ,
struct V_278 * V_21 , long V_279 )
{
V_277 -> V_280 . V_281 = V_277 -> V_282 = V_279 ;
V_277 -> V_283 = V_21 -> V_284 . signal . V_285 [ 0 ] ;
V_277 -> V_286 = V_21 -> V_287 . V_285 [ 0 ] ;
F_89 () ;
V_277 -> V_288 = F_90 ( F_91 ( V_21 -> V_289 ) ) ;
F_92 () ;
V_277 -> V_290 = F_90 ( V_21 ) ;
V_277 -> V_291 = F_93 ( V_21 ) ;
V_277 -> V_292 = F_94 ( V_21 ) ;
if ( F_95 ( V_21 ) ) {
struct V_293 V_294 ;
F_96 ( V_21 , & V_294 ) ;
V_277 -> V_295 = F_97 ( V_294 . V_296 ) ;
V_277 -> V_297 = F_97 ( V_294 . V_298 ) ;
} else {
T_10 V_296 , V_298 ;
V_293 ( V_21 , & V_296 , & V_298 ) ;
V_277 -> V_295 = F_97 ( V_296 ) ;
V_277 -> V_297 = F_97 ( V_298 ) ;
}
V_277 -> V_299 = F_97 ( V_21 -> signal -> V_300 ) ;
V_277 -> V_301 = F_97 ( V_21 -> signal -> V_302 ) ;
}
static int F_98 ( struct V_303 * V_304 , struct V_278 * V_21 ,
struct V_305 * V_7 )
{
const struct V_38 * V_38 ;
unsigned int V_97 , V_41 ;
memset ( V_304 , 0 , sizeof( struct V_303 ) ) ;
V_41 = V_7 -> V_78 - V_7 -> V_79 ;
if ( V_41 >= V_306 )
V_41 = V_306 - 1 ;
if ( F_99 ( & V_304 -> V_307 ,
( const char V_13 * ) V_7 -> V_79 , V_41 ) )
return - V_14 ;
for( V_97 = 0 ; V_97 < V_41 ; V_97 ++ )
if ( V_304 -> V_307 [ V_97 ] == 0 )
V_304 -> V_307 [ V_97 ] = ' ' ;
V_304 -> V_307 [ V_41 ] = 0 ;
F_89 () ;
V_304 -> V_288 = F_90 ( F_91 ( V_21 -> V_289 ) ) ;
F_92 () ;
V_304 -> V_290 = F_90 ( V_21 ) ;
V_304 -> V_291 = F_93 ( V_21 ) ;
V_304 -> V_292 = F_94 ( V_21 ) ;
V_97 = V_21 -> V_117 ? F_100 ( ~ V_21 -> V_117 ) + 1 : 0 ;
V_304 -> V_308 = V_97 ;
V_304 -> V_309 = ( V_97 > 5 ) ? '.' : L_1 [ V_97 ] ;
V_304 -> V_310 = V_304 -> V_309 == 'Z' ;
V_304 -> V_311 = F_101 ( V_21 ) ;
V_304 -> V_312 = V_21 -> V_150 ;
F_89 () ;
V_38 = F_102 ( V_21 ) ;
F_103 ( V_304 -> V_313 , F_15 ( V_38 -> V_60 , V_38 -> V_61 ) ) ;
F_104 ( V_304 -> V_314 , F_16 ( V_38 -> V_60 , V_38 -> V_65 ) ) ;
F_92 () ;
strncpy ( V_304 -> V_315 , V_21 -> V_316 , sizeof( V_304 -> V_315 ) ) ;
return 0 ;
}
static void F_105 ( struct V_244 * V_275 , struct V_305 * V_7 )
{
T_1 * V_317 = ( T_1 * ) V_7 -> V_42 ;
int V_97 = 0 ;
do
V_97 += 2 ;
while ( V_317 [ V_97 - 2 ] != V_318 );
F_87 ( V_275 , L_2 , V_319 , V_97 * sizeof( T_1 ) , V_317 ) ;
}
static void F_106 ( struct V_244 * V_275 , T_11 * V_320 ,
const T_12 * V_321 )
{
T_7 V_322 = F_76 () ;
F_78 ( V_323 ) ;
F_107 ( ( T_11 V_13 * ) V_320 , V_321 ) ;
F_78 ( V_322 ) ;
F_87 ( V_275 , L_2 , V_324 , sizeof( * V_320 ) , V_320 ) ;
}
static int F_108 ( struct V_244 * V_275 )
{
struct V_39 * V_40 ;
unsigned V_325 , V_90 , V_326 , V_327 , V_328 ;
T_13 * V_255 ;
T_13 * V_329 ;
char * V_330 , * V_331 ;
V_325 = V_6 -> V_7 -> V_332 ;
V_90 = V_325 * 64 ;
V_326 = ( 2 + 3 * V_325 ) * sizeof( V_255 [ 0 ] ) ;
V_333:
if ( V_90 >= V_334 )
return - V_81 ;
V_90 = F_109 ( V_90 , V_200 ) ;
V_255 = F_110 ( V_90 ) ;
if ( ! V_255 )
return - V_147 ;
V_329 = V_255 + 2 ;
V_330 = V_331 = ( ( char * ) V_255 ) + V_326 ;
V_327 = V_90 - V_326 ;
V_325 = 0 ;
for ( V_40 = V_6 -> V_7 -> V_132 ; V_40 != NULL ; V_40 = V_40 -> V_335 ) {
struct V_84 * V_84 ;
const char * V_336 ;
V_84 = V_40 -> V_217 ;
if ( ! V_84 )
continue;
V_336 = F_111 ( V_84 , V_331 , V_327 ) ;
if ( F_47 ( V_336 ) ) {
if ( F_46 ( V_336 ) == - V_337 ) {
F_112 ( V_255 ) ;
V_90 = V_90 * 5 / 4 ;
goto V_333;
}
continue;
}
V_328 = ( V_331 + V_327 ) - V_336 ;
V_327 = V_336 - V_331 ;
memmove ( V_331 , V_336 , V_328 ) ;
V_331 += V_328 ;
* V_329 ++ = V_40 -> V_228 ;
* V_329 ++ = V_40 -> V_243 ;
* V_329 ++ = V_40 -> V_225 ;
V_325 ++ ;
}
V_255 [ 0 ] = V_325 ;
V_255 [ 1 ] = V_200 ;
V_328 = V_6 -> V_7 -> V_332 - V_325 ;
if ( V_328 != 0 ) {
unsigned V_338 = V_328 * 3 * sizeof( V_255 [ 0 ] ) ;
memmove ( V_330 - V_338 , V_330 ,
V_331 - V_330 ) ;
V_331 -= V_338 ;
}
V_90 = V_331 - ( char * ) V_255 ;
F_87 ( V_275 , L_2 , V_339 , V_90 , V_255 ) ;
return 0 ;
}
static void F_113 ( struct V_278 * V_340 ,
const struct V_341 * V_342 )
{
if ( V_342 -> V_343 )
V_342 -> V_343 ( V_340 , V_342 , 1 ) ;
}
static int F_114 ( struct V_344 * V_345 ,
const struct V_346 * V_347 ,
long V_279 , T_2 * V_348 )
{
unsigned int V_97 ;
unsigned int V_349 = V_347 -> V_350 [ 0 ] . V_328 * V_347 -> V_350 [ 0 ] . V_90 ;
F_88 ( & V_345 -> V_277 , V_345 -> V_340 , V_279 ) ;
( void ) V_347 -> V_350 [ 0 ] . F_115 ( V_345 -> V_340 , & V_347 -> V_350 [ 0 ] , 0 , V_349 ,
& V_345 -> V_277 . V_351 , NULL ) ;
F_87 ( & V_345 -> V_352 [ 0 ] , L_2 , V_353 ,
F_116 ( V_345 -> V_277 , V_349 ) , & V_345 -> V_277 ) ;
* V_348 += F_80 ( & V_345 -> V_352 [ 0 ] ) ;
F_113 ( V_345 -> V_340 , & V_347 -> V_350 [ 0 ] ) ;
for ( V_97 = 1 ; V_97 < V_347 -> V_328 ; ++ V_97 ) {
const struct V_341 * V_342 = & V_347 -> V_350 [ V_97 ] ;
F_113 ( V_345 -> V_340 , V_342 ) ;
if ( V_342 -> V_354 && V_342 -> F_115 &&
( ! V_342 -> V_355 || V_342 -> V_355 ( V_345 -> V_340 , V_342 ) ) ) {
int V_356 ;
T_2 V_90 = V_342 -> V_328 * V_342 -> V_90 ;
void * V_255 = F_33 ( V_90 , V_110 ) ;
if ( F_55 ( ! V_255 ) )
return 0 ;
V_356 = V_342 -> F_115 ( V_345 -> V_340 , V_342 ,
0 , V_90 , V_255 , NULL ) ;
if ( F_55 ( V_356 ) )
F_35 ( V_255 ) ;
else {
if ( V_342 -> V_354 != V_357 )
F_87 ( & V_345 -> V_352 [ V_97 ] , L_3 ,
V_342 -> V_354 ,
V_90 , V_255 ) ;
else {
F_117 ( & V_345 -> V_277 ,
1 , V_349 ) ;
F_87 ( & V_345 -> V_352 [ V_97 ] , L_2 ,
V_357 , V_90 , V_255 ) ;
}
* V_348 += F_80 ( & V_345 -> V_352 [ V_97 ] ) ;
}
}
}
return 1 ;
}
static int F_118 ( struct V_17 * V_114 , int V_358 ,
struct V_359 * V_360 ,
const T_12 * V_321 , struct V_168 * V_169 )
{
struct V_278 * V_361 = V_6 ;
const struct V_346 * V_347 = F_119 ( V_361 ) ;
struct V_344 * V_345 ;
struct V_303 * V_304 ;
struct V_362 * V_363 ;
unsigned int V_97 ;
V_360 -> V_90 = 0 ;
V_360 -> V_364 = NULL ;
V_304 = F_33 ( sizeof( * V_304 ) , V_110 ) ;
if ( V_304 == NULL ) {
V_360 -> V_304 . V_255 = NULL ;
return 0 ;
}
F_87 ( & V_360 -> V_304 , L_2 , V_365 , sizeof( * V_304 ) , V_304 ) ;
V_360 -> V_366 = 0 ;
for ( V_97 = 0 ; V_97 < V_347 -> V_328 ; ++ V_97 )
if ( V_347 -> V_350 [ V_97 ] . V_354 != 0 )
++ V_360 -> V_366 ;
if ( F_55 ( V_360 -> V_366 == 0 ) ||
F_55 ( V_347 -> V_350 [ 0 ] . V_354 != V_353 ) ) {
F_120 ( 1 ) ;
return 0 ;
}
F_85 ( V_114 , V_358 ,
V_347 -> V_267 , V_347 -> V_269 ) ;
for ( V_363 = & V_361 -> V_7 -> V_367 -> V_368 ; V_363 ; V_363 = V_363 -> V_369 ) {
V_345 = F_121 ( F_122 ( struct V_344 ,
V_352 [ V_360 -> V_366 ] ) ,
V_110 ) ;
if ( F_55 ( ! V_345 ) )
return 0 ;
V_345 -> V_340 = V_363 -> V_340 ;
if ( V_363 -> V_340 == V_361 || ! V_360 -> V_364 ) {
V_345 -> V_369 = V_360 -> V_364 ;
V_360 -> V_364 = V_345 ;
} else {
V_345 -> V_369 = V_360 -> V_364 -> V_369 ;
V_360 -> V_364 -> V_369 = V_345 ;
}
}
for ( V_345 = V_360 -> V_364 ; V_345 != NULL ; V_345 = V_345 -> V_369 )
if ( ! F_114 ( V_345 , V_347 , V_321 -> V_281 , & V_360 -> V_90 ) )
return 0 ;
F_98 ( V_304 , V_361 -> V_370 , V_361 -> V_7 ) ;
V_360 -> V_90 += F_80 ( & V_360 -> V_304 ) ;
F_106 ( & V_360 -> V_371 , & V_360 -> V_320 , V_321 ) ;
V_360 -> V_90 += F_80 ( & V_360 -> V_371 ) ;
F_105 ( & V_360 -> V_317 , V_6 -> V_7 ) ;
V_360 -> V_90 += F_80 ( & V_360 -> V_317 ) ;
if ( F_108 ( & V_360 -> V_372 ) == 0 )
V_360 -> V_90 += F_80 ( & V_360 -> V_372 ) ;
return 1 ;
}
static T_2 F_123 ( struct V_359 * V_360 )
{
return V_360 -> V_90 ;
}
static int F_124 ( struct V_359 * V_360 ,
struct V_250 * V_251 )
{
bool V_373 = true ;
struct V_344 * V_345 = V_360 -> V_364 ;
do {
int V_97 ;
if ( ! F_82 ( & V_345 -> V_352 [ 0 ] , V_251 ) )
return 0 ;
if ( V_373 && ! F_82 ( & V_360 -> V_304 , V_251 ) )
return 0 ;
if ( V_373 && ! F_82 ( & V_360 -> V_371 , V_251 ) )
return 0 ;
if ( V_373 && ! F_82 ( & V_360 -> V_317 , V_251 ) )
return 0 ;
if ( V_373 && V_360 -> V_372 . V_255 &&
! F_82 ( & V_360 -> V_372 , V_251 ) )
return 0 ;
for ( V_97 = 1 ; V_97 < V_360 -> V_366 ; ++ V_97 )
if ( V_345 -> V_352 [ V_97 ] . V_255 &&
! F_82 ( & V_345 -> V_352 [ V_97 ] , V_251 ) )
return 0 ;
V_373 = false ;
V_345 = V_345 -> V_369 ;
} while ( V_345 );
return 1 ;
}
static void F_125 ( struct V_359 * V_360 )
{
struct V_344 * V_374 = V_360 -> V_364 ;
while ( V_374 ) {
unsigned int V_97 ;
struct V_344 * V_345 = V_374 ;
V_374 = V_345 -> V_369 ;
F_120 ( V_345 -> V_352 [ 0 ] . V_255 && V_345 -> V_352 [ 0 ] . V_255 != & V_345 -> V_277 ) ;
for ( V_97 = 1 ; V_97 < V_360 -> V_366 ; ++ V_97 )
F_35 ( V_345 -> V_352 [ V_97 ] . V_255 ) ;
F_35 ( V_345 ) ;
}
F_35 ( V_360 -> V_304 . V_255 ) ;
F_112 ( V_360 -> V_372 . V_255 ) ;
}
static int F_126 ( long V_279 , struct V_375 * V_345 )
{
int V_246 = 0 ;
struct V_278 * V_21 = V_345 -> V_364 ;
V_345 -> V_376 = 0 ;
F_88 ( & V_345 -> V_277 , V_21 , V_279 ) ;
F_127 ( V_21 , & V_345 -> V_277 . V_351 ) ;
F_87 ( & V_345 -> V_352 [ 0 ] , L_2 , V_353 , sizeof( V_345 -> V_277 ) ,
& ( V_345 -> V_277 ) ) ;
V_345 -> V_376 ++ ;
V_246 += F_80 ( & V_345 -> V_352 [ 0 ] ) ;
if ( ( V_345 -> V_277 . V_377 = F_128 ( V_21 , NULL ,
& V_345 -> V_378 ) ) ) {
F_87 ( & V_345 -> V_352 [ 1 ] , L_2 , V_357 , sizeof( V_345 -> V_378 ) ,
& ( V_345 -> V_378 ) ) ;
V_345 -> V_376 ++ ;
V_246 += F_80 ( & V_345 -> V_352 [ 1 ] ) ;
}
#ifdef F_129
if ( F_130 ( V_21 , & V_345 -> V_379 ) ) {
F_87 ( & V_345 -> V_352 [ 2 ] , L_3 , V_380 ,
sizeof( V_345 -> V_379 ) , & V_345 -> V_379 ) ;
V_345 -> V_376 ++ ;
V_246 += F_80 ( & V_345 -> V_352 [ 2 ] ) ;
}
#endif
return V_246 ;
}
static int F_131 ( struct V_359 * V_360 )
{
memset ( V_360 , 0 , sizeof( * V_360 ) ) ;
F_132 ( & V_360 -> V_381 ) ;
V_360 -> V_352 = F_33 ( 8 * sizeof( struct V_244 ) , V_110 ) ;
if ( ! V_360 -> V_352 )
return 0 ;
V_360 -> V_304 = F_33 ( sizeof( * V_360 -> V_304 ) , V_110 ) ;
if ( ! V_360 -> V_304 )
return 0 ;
V_360 -> V_277 = F_33 ( sizeof( * V_360 -> V_277 ) , V_110 ) ;
if ( ! V_360 -> V_277 )
return 0 ;
V_360 -> V_378 = F_33 ( sizeof( * V_360 -> V_378 ) , V_110 ) ;
if ( ! V_360 -> V_378 )
return 0 ;
#ifdef F_129
V_360 -> V_379 = F_33 ( sizeof( * V_360 -> V_379 ) , V_110 ) ;
if ( ! V_360 -> V_379 )
return 0 ;
#endif
return 1 ;
}
static int F_118 ( struct V_17 * V_114 , int V_358 ,
struct V_359 * V_360 ,
const T_12 * V_321 , struct V_168 * V_169 )
{
struct V_382 * V_345 ;
struct V_362 * V_363 ;
struct V_375 * V_383 ;
if ( ! F_131 ( V_360 ) )
return 0 ;
for ( V_363 = V_6 -> V_7 -> V_367 -> V_368 . V_369 ;
V_363 ; V_363 = V_363 -> V_369 ) {
V_383 = F_121 ( sizeof( * V_383 ) , V_110 ) ;
if ( ! V_383 )
return 0 ;
V_383 -> V_364 = V_363 -> V_340 ;
F_133 ( & V_383 -> V_384 , & V_360 -> V_381 ) ;
}
F_134 (t, &info->thread_list) {
int V_246 ;
V_383 = F_135 ( V_345 , struct V_375 , V_384 ) ;
V_246 = F_126 ( V_321 -> V_281 , V_383 ) ;
V_360 -> V_385 += V_246 ;
}
memset ( V_360 -> V_277 , 0 , sizeof( * V_360 -> V_277 ) ) ;
F_88 ( V_360 -> V_277 , V_6 , V_321 -> V_281 ) ;
F_136 ( & V_360 -> V_277 -> V_351 , V_169 ) ;
F_85 ( V_114 , V_358 , V_386 , V_387 ) ;
F_87 ( V_360 -> V_352 + 0 , L_2 , V_353 ,
sizeof( * V_360 -> V_277 ) , V_360 -> V_277 ) ;
F_98 ( V_360 -> V_304 , V_6 -> V_370 , V_6 -> V_7 ) ;
F_87 ( V_360 -> V_352 + 1 , L_2 , V_365 ,
sizeof( * V_360 -> V_304 ) , V_360 -> V_304 ) ;
F_106 ( V_360 -> V_352 + 2 , & V_360 -> V_320 , V_321 ) ;
F_105 ( V_360 -> V_352 + 3 , V_6 -> V_7 ) ;
V_360 -> V_388 = 4 ;
if ( F_108 ( V_360 -> V_352 + V_360 -> V_388 ) == 0 ) {
V_360 -> V_389 = V_360 -> V_352 + V_360 -> V_388 ;
V_360 -> V_388 ++ ;
}
V_360 -> V_277 -> V_377 = F_128 ( V_6 , V_169 ,
V_360 -> V_378 ) ;
if ( V_360 -> V_277 -> V_377 )
F_87 ( V_360 -> V_352 + V_360 -> V_388 ++ ,
L_2 , V_357 , sizeof( * V_360 -> V_378 ) , V_360 -> V_378 ) ;
#ifdef F_129
if ( F_130 ( V_6 , V_360 -> V_379 ) )
F_87 ( V_360 -> V_352 + V_360 -> V_388 ++ ,
L_3 , V_380 ,
sizeof( * V_360 -> V_379 ) , V_360 -> V_379 ) ;
#endif
return 1 ;
}
static T_2 F_123 ( struct V_359 * V_360 )
{
int V_246 = 0 ;
int V_97 ;
for ( V_97 = 0 ; V_97 < V_360 -> V_388 ; V_97 ++ )
V_246 += F_80 ( V_360 -> V_352 + V_97 ) ;
V_246 += V_360 -> V_385 ;
return V_246 ;
}
static int F_124 ( struct V_359 * V_360 ,
struct V_250 * V_251 )
{
int V_97 ;
struct V_382 * V_345 ;
for ( V_97 = 0 ; V_97 < V_360 -> V_388 ; V_97 ++ )
if ( ! F_82 ( V_360 -> V_352 + V_97 , V_251 ) )
return 0 ;
F_134 (t, &info->thread_list) {
struct V_375 * V_390 =
F_135 ( V_345 , struct V_375 , V_384 ) ;
for ( V_97 = 0 ; V_97 < V_390 -> V_376 ; V_97 ++ )
if ( ! F_82 ( & V_390 -> V_352 [ V_97 ] , V_251 ) )
return 0 ;
}
return 1 ;
}
static void F_125 ( struct V_359 * V_360 )
{
while ( ! F_137 ( & V_360 -> V_381 ) ) {
struct V_382 * V_390 = V_360 -> V_381 . V_369 ;
F_138 ( V_390 ) ;
F_35 ( F_135 ( V_390 , struct V_375 , V_384 ) ) ;
}
if ( V_360 -> V_389 )
F_112 ( V_360 -> V_389 -> V_255 ) ;
F_35 ( V_360 -> V_277 ) ;
F_35 ( V_360 -> V_304 ) ;
F_35 ( V_360 -> V_352 ) ;
F_35 ( V_360 -> V_378 ) ;
#ifdef F_129
F_35 ( V_360 -> V_379 ) ;
#endif
}
static struct V_39 * F_139 ( struct V_278 * V_391 ,
struct V_39 * V_392 )
{
struct V_39 * V_356 = V_391 -> V_7 -> V_132 ;
if ( V_356 )
return V_356 ;
return V_392 ;
}
static struct V_39 * F_140 ( struct V_39 * V_393 ,
struct V_39 * V_392 )
{
struct V_39 * V_356 ;
V_356 = V_393 -> V_335 ;
if ( V_356 )
return V_356 ;
if ( V_393 == V_392 )
return NULL ;
return V_392 ;
}
static void F_141 ( struct V_17 * V_114 , struct V_394 * V_395 ,
T_1 V_396 , int V_256 )
{
V_114 -> V_396 = V_396 ;
V_114 -> V_397 = sizeof( * V_395 ) ;
V_114 -> V_398 = 1 ;
V_114 -> V_399 = V_400 ;
memset ( V_395 , 0 , sizeof( * V_395 ) ) ;
V_395 -> V_401 = V_402 ;
V_395 -> V_403 = V_114 -> V_398 ;
V_395 -> V_404 = V_114 -> V_399 ;
V_395 -> V_405 = V_256 ;
}
static int F_142 ( struct V_250 * V_251 )
{
int V_406 = 0 ;
T_7 V_230 ;
int V_256 , V_97 ;
T_2 V_407 = 0 ;
struct V_39 * V_40 , * V_392 ;
struct V_17 * V_114 = NULL ;
T_9 V_271 = 0 , V_408 ;
struct V_359 V_360 = { } ;
struct V_52 * V_409 = NULL ;
struct V_394 * V_395 = NULL ;
T_14 V_54 ;
T_1 V_396 ;
T_1 * V_410 = NULL ;
V_114 = F_33 ( sizeof( * V_114 ) , V_110 ) ;
if ( ! V_114 )
goto V_109;
V_256 = V_6 -> V_7 -> V_332 ;
V_256 += F_143 () ;
V_392 = F_70 ( V_6 -> V_7 ) ;
if ( V_392 != NULL )
V_256 ++ ;
V_256 ++ ;
V_54 = V_256 > V_411 ? V_411 : V_256 ;
if ( ! F_118 ( V_114 , V_54 , & V_360 , V_251 -> V_321 , V_251 -> V_169 ) )
goto V_412;
V_406 = 1 ;
V_230 = F_76 () ;
F_78 ( V_323 ) ;
V_271 += sizeof( * V_114 ) ;
V_271 += V_256 * sizeof( struct V_52 ) ;
{
T_2 V_246 = F_123 ( & V_360 ) ;
V_246 += F_144 () ;
V_409 = F_33 ( sizeof( * V_409 ) , V_110 ) ;
if ( ! V_409 )
goto V_413;
F_86 ( V_409 , V_246 , V_271 ) ;
V_271 += V_246 ;
}
V_408 = V_271 = F_81 ( V_271 , V_46 ) ;
if ( V_256 - 1 > V_414 / sizeof( * V_410 ) )
goto V_413;
V_410 = F_110 ( ( V_256 - 1 ) * sizeof( * V_410 ) ) ;
if ( ! V_410 )
goto V_413;
for ( V_97 = 0 , V_40 = F_139 ( V_6 , V_392 ) ; V_40 != NULL ;
V_40 = F_140 ( V_40 , V_392 ) ) {
unsigned long V_415 ;
V_415 = F_72 ( V_40 , V_251 -> V_206 ) ;
V_410 [ V_97 ++ ] = V_415 ;
V_407 += V_415 ;
}
V_271 += V_407 ;
V_271 += F_145 () ;
V_396 = V_271 ;
if ( V_54 == V_411 ) {
V_395 = F_33 ( sizeof( * V_395 ) , V_110 ) ;
if ( ! V_395 )
goto V_413;
F_141 ( V_114 , V_395 , V_396 , V_256 ) ;
}
V_271 = V_408 ;
if ( ! F_83 ( V_251 , V_114 , sizeof( * V_114 ) ) )
goto V_413;
if ( ! F_83 ( V_251 , V_409 , sizeof( * V_409 ) ) )
goto V_413;
for ( V_97 = 0 , V_40 = F_139 ( V_6 , V_392 ) ; V_40 != NULL ;
V_40 = F_140 ( V_40 , V_392 ) ) {
struct V_52 V_113 ;
V_113 . V_100 = V_101 ;
V_113 . V_94 = V_271 ;
V_113 . V_92 = V_40 -> V_228 ;
V_113 . V_273 = 0 ;
V_113 . V_91 = V_410 [ V_97 ++ ] ;
V_113 . V_102 = V_40 -> V_243 - V_40 -> V_228 ;
V_271 += V_113 . V_91 ;
V_113 . V_139 = V_40 -> V_208 & V_226 ? V_140 : 0 ;
if ( V_40 -> V_208 & V_416 )
V_113 . V_139 |= V_142 ;
if ( V_40 -> V_208 & V_5 )
V_113 . V_139 |= V_144 ;
V_113 . V_274 = V_46 ;
if ( ! F_83 ( V_251 , & V_113 , sizeof( V_113 ) ) )
goto V_413;
}
if ( ! F_146 ( V_251 , V_271 ) )
goto V_413;
if ( ! F_124 ( & V_360 , V_251 ) )
goto V_413;
if ( F_147 ( V_251 ) )
goto V_413;
if ( ! F_148 ( V_251 , V_408 - V_251 -> V_417 ) )
goto V_413;
for ( V_97 = 0 , V_40 = F_139 ( V_6 , V_392 ) ; V_40 != NULL ;
V_40 = F_140 ( V_40 , V_392 ) ) {
unsigned long V_86 ;
unsigned long V_2 ;
V_2 = V_40 -> V_228 + V_410 [ V_97 ++ ] ;
for ( V_86 = V_40 -> V_228 ; V_86 < V_2 ; V_86 += V_200 ) {
struct V_418 * V_418 ;
int V_419 ;
V_418 = F_149 ( V_86 ) ;
if ( V_418 ) {
void * V_420 = F_150 ( V_418 ) ;
V_419 = ! F_83 ( V_251 , V_420 , V_200 ) ;
F_151 ( V_418 ) ;
F_152 ( V_418 ) ;
} else
V_419 = ! F_148 ( V_251 , V_200 ) ;
if ( V_419 )
goto V_413;
}
}
F_153 ( V_251 ) ;
if ( ! F_154 ( V_251 ) )
goto V_413;
if ( V_54 == V_411 ) {
if ( ! F_83 ( V_251 , V_395 , sizeof( * V_395 ) ) )
goto V_413;
}
V_413:
F_78 ( V_230 ) ;
V_412:
F_125 ( & V_360 ) ;
F_35 ( V_395 ) ;
F_112 ( V_410 ) ;
F_35 ( V_409 ) ;
F_35 ( V_114 ) ;
V_109:
return V_406 ;
}
static int T_15 F_155 ( void )
{
F_156 ( & V_197 ) ;
return 0 ;
}
static void T_16 F_157 ( void )
{
F_158 ( & V_197 ) ;
}
