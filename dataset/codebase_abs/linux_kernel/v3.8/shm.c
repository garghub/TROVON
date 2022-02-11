void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
F_2 ( & F_3 ( V_2 ) ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_16 ) {
V_14 -> V_15 . V_17 |= V_18 ;
V_14 -> V_15 . V_19 = V_20 ;
F_6 ( V_14 ) ;
} else
F_7 ( V_2 , V_14 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 , & F_3 ( V_2 ) , F_4 ) ;
F_10 ( & V_2 -> V_21 [ V_22 ] . V_23 ) ;
}
static int T_1 F_11 ( void )
{
F_1 ( & V_24 ) ;
return 0 ;
}
void T_1 F_12 ( void )
{
F_13 ( L_1 ,
#if V_25 <= 32
L_2 ,
#else
L_3 ,
#endif
V_22 , V_26 ) ;
}
static inline struct V_13 * F_14 ( struct V_1 * V_2 , int V_27 )
{
struct V_11 * V_12 = F_15 ( & F_3 ( V_2 ) , V_27 ) ;
if ( F_16 ( V_12 ) )
return (struct V_13 * ) V_12 ;
return F_5 ( V_12 , struct V_13 , V_15 ) ;
}
static inline void F_17 ( struct V_13 * V_12 )
{
F_18 () ;
F_19 ( & V_12 -> V_15 . V_28 ) ;
}
static inline struct V_13 * F_20 ( struct V_1 * V_2 ,
int V_27 )
{
struct V_11 * V_12 = F_21 ( & F_3 ( V_2 ) , V_27 ) ;
if ( F_16 ( V_12 ) )
return (struct V_13 * ) V_12 ;
return F_5 ( V_12 , struct V_13 , V_15 ) ;
}
static inline void F_22 ( struct V_1 * V_2 , struct V_13 * V_29 )
{
F_23 ( & F_3 ( V_2 ) , & V_29 -> V_15 ) ;
}
static void F_24 ( struct V_30 * V_31 )
{
struct V_32 * V_32 = V_31 -> V_33 ;
struct V_34 * V_35 = V_34 ( V_32 ) ;
struct V_13 * V_14 ;
V_14 = F_14 ( V_35 -> V_2 , V_35 -> V_27 ) ;
F_25 ( F_16 ( V_14 ) ) ;
V_14 -> V_36 = F_26 () ;
V_14 -> V_37 = F_27 ( V_38 ) ;
V_14 -> V_16 ++ ;
F_6 ( V_14 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
V_2 -> V_10 -= ( V_14 -> V_39 + V_40 - 1 ) >> V_41 ;
F_22 ( V_2 , V_14 ) ;
F_6 ( V_14 ) ;
if ( ! F_28 ( V_14 -> V_42 ) )
F_29 ( V_14 -> V_42 , 0 , V_14 -> V_43 ) ;
else if ( V_14 -> V_43 )
F_30 ( V_14 -> V_42 -> V_44 . V_45 -> V_46 -> V_47 ,
V_14 -> V_43 ) ;
F_31 ( V_14 -> V_42 ) ;
F_32 ( V_14 ) ;
F_33 ( V_14 ) ;
}
static bool F_34 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
return ( V_14 -> V_16 == 0 ) &&
( V_2 -> V_9 ||
( V_14 -> V_15 . V_17 & V_18 ) ) ;
}
static void F_35 ( struct V_30 * V_31 )
{
struct V_32 * V_32 = V_31 -> V_33 ;
struct V_34 * V_35 = V_34 ( V_32 ) ;
struct V_13 * V_14 ;
struct V_1 * V_2 = V_35 -> V_2 ;
F_36 ( & F_3 ( V_2 ) . V_48 ) ;
V_14 = F_14 ( V_2 , V_35 -> V_27 ) ;
F_25 ( F_16 ( V_14 ) ) ;
V_14 -> V_37 = F_27 ( V_38 ) ;
V_14 -> V_49 = F_26 () ;
V_14 -> V_16 -- ;
if ( F_34 ( V_2 , V_14 ) )
F_7 ( V_2 , V_14 ) ;
else
F_6 ( V_14 ) ;
F_37 ( & F_3 ( V_2 ) . V_48 ) ;
}
static int F_38 ( int V_27 , void * V_50 , void * V_51 )
{
struct V_1 * V_2 = V_51 ;
struct V_11 * V_12 = V_50 ;
struct V_13 * V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_52 != V_38 )
return 0 ;
V_14 -> V_52 = NULL ;
if ( ! V_2 -> V_9 )
return 0 ;
if ( F_34 ( V_2 , V_14 ) ) {
F_17 ( V_14 ) ;
F_7 ( V_2 , V_14 ) ;
}
return 0 ;
}
static int F_39 ( int V_27 , void * V_50 , void * V_51 )
{
struct V_1 * V_2 = V_51 ;
struct V_11 * V_12 = V_50 ;
struct V_13 * V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_52 != NULL )
return 0 ;
if ( F_34 ( V_2 , V_14 ) ) {
F_17 ( V_14 ) ;
F_7 ( V_2 , V_14 ) ;
}
return 0 ;
}
void F_40 ( struct V_1 * V_2 )
{
F_36 ( & F_3 ( V_2 ) . V_48 ) ;
if ( F_3 ( V_2 ) . V_53 )
F_41 ( & F_3 ( V_2 ) . V_23 , & F_39 , V_2 ) ;
F_37 ( & F_3 ( V_2 ) . V_48 ) ;
}
void F_42 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = V_55 -> V_56 -> V_57 ;
if ( F_3 ( V_2 ) . V_53 == 0 )
return;
F_36 ( & F_3 ( V_2 ) . V_48 ) ;
if ( F_3 ( V_2 ) . V_53 )
F_41 ( & F_3 ( V_2 ) . V_23 , & F_38 , V_2 ) ;
F_37 ( & F_3 ( V_2 ) . V_48 ) ;
}
static int F_43 ( struct V_30 * V_31 , struct V_58 * V_59 )
{
struct V_32 * V_32 = V_31 -> V_33 ;
struct V_34 * V_35 = V_34 ( V_32 ) ;
return V_35 -> V_60 -> V_61 ( V_31 , V_59 ) ;
}
static int F_44 ( struct V_30 * V_31 , struct V_62 * V_63 )
{
struct V_32 * V_32 = V_31 -> V_33 ;
struct V_34 * V_35 = V_34 ( V_32 ) ;
int V_64 = 0 ;
if ( V_35 -> V_60 -> V_65 )
V_64 = V_35 -> V_60 -> V_65 ( V_31 , V_63 ) ;
return V_64 ;
}
static struct V_62 * F_45 ( struct V_30 * V_31 ,
unsigned long V_66 )
{
struct V_32 * V_32 = V_31 -> V_33 ;
struct V_34 * V_35 = V_34 ( V_32 ) ;
struct V_62 * V_67 = NULL ;
if ( V_35 -> V_60 -> V_68 )
V_67 = V_35 -> V_60 -> V_68 ( V_31 , V_66 ) ;
else if ( V_31 -> V_69 )
V_67 = V_31 -> V_69 ;
return V_67 ;
}
static int F_46 ( struct V_32 * V_32 , struct V_30 * V_31 )
{
struct V_34 * V_35 = V_34 ( V_32 ) ;
int V_70 ;
V_70 = V_35 -> V_32 -> V_71 -> V_72 ( V_35 -> V_32 , V_31 ) ;
if ( V_70 != 0 )
return V_70 ;
V_35 -> V_60 = V_31 -> V_60 ;
#ifdef F_47
F_25 ( ! V_35 -> V_60 -> V_61 ) ;
#endif
V_31 -> V_60 = & V_73 ;
F_24 ( V_31 ) ;
return V_70 ;
}
static int F_48 ( struct V_74 * V_75 , struct V_32 * V_32 )
{
struct V_34 * V_35 = V_34 ( V_32 ) ;
F_49 ( V_35 -> V_2 ) ;
V_34 ( V_32 ) = NULL ;
F_50 ( V_35 ) ;
return 0 ;
}
static int F_51 ( struct V_32 * V_32 , T_2 V_76 , T_2 V_77 , int V_78 )
{
struct V_34 * V_35 = V_34 ( V_32 ) ;
if ( ! V_35 -> V_32 -> V_71 -> V_79 )
return - V_80 ;
return V_35 -> V_32 -> V_71 -> V_79 ( V_35 -> V_32 , V_76 , V_77 , V_78 ) ;
}
static long F_52 ( struct V_32 * V_32 , int V_17 , T_2 V_81 ,
T_2 V_82 )
{
struct V_34 * V_35 = V_34 ( V_32 ) ;
if ( ! V_35 -> V_32 -> V_71 -> V_83 )
return - V_84 ;
return V_35 -> V_32 -> V_71 -> V_83 ( V_32 , V_17 , V_81 , V_82 ) ;
}
static unsigned long F_53 ( struct V_32 * V_32 ,
unsigned long V_66 , unsigned long V_82 , unsigned long V_85 ,
unsigned long V_86 )
{
struct V_34 * V_35 = V_34 ( V_32 ) ;
return V_35 -> V_32 -> V_71 -> V_87 ( V_35 -> V_32 , V_66 , V_82 ,
V_85 , V_86 ) ;
}
int F_54 ( struct V_32 * V_32 )
{
return V_32 -> V_71 == & V_88 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_89 * V_90 )
{
T_3 V_19 = V_90 -> V_19 ;
int V_91 = V_90 -> V_92 ;
T_4 V_93 = V_90 -> V_94 . V_93 ;
int error ;
struct V_13 * V_14 ;
int V_95 = ( V_93 + V_40 - 1 ) >> V_41 ;
struct V_32 * V_32 ;
char V_96 [ 13 ] ;
int V_27 ;
T_5 V_97 = 0 ;
if ( V_93 < V_98 || V_93 > V_2 -> V_3 )
return - V_80 ;
if ( V_2 -> V_10 + V_95 > V_2 -> V_5 )
return - V_99 ;
V_14 = F_56 ( sizeof( * V_14 ) ) ;
if ( ! V_14 )
return - V_100 ;
V_14 -> V_15 . V_19 = V_19 ;
V_14 -> V_15 . V_17 = ( V_91 & V_101 ) ;
V_14 -> V_43 = NULL ;
V_14 -> V_15 . V_102 = NULL ;
error = F_57 ( V_14 ) ;
if ( error ) {
F_33 ( V_14 ) ;
return error ;
}
sprintf ( V_96 , L_4 , V_19 ) ;
if ( V_91 & V_103 ) {
if ( V_91 & V_104 )
V_97 = V_105 ;
V_32 = F_58 ( V_96 , 0 , V_93 , V_97 ,
& V_14 -> V_43 , V_106 ,
( V_91 >> V_107 ) & V_108 ) ;
} else {
if ( ( V_91 & V_104 ) &&
V_109 != V_110 )
V_97 = V_105 ;
V_32 = F_59 ( V_96 , V_93 , V_97 ) ;
}
error = F_60 ( V_32 ) ;
if ( F_16 ( V_32 ) )
goto V_111;
V_27 = F_61 ( & F_3 ( V_2 ) , & V_14 -> V_15 , V_2 -> V_7 ) ;
if ( V_27 < 0 ) {
error = V_27 ;
goto V_112;
}
V_14 -> V_113 = F_27 ( V_38 ) ;
V_14 -> V_37 = 0 ;
V_14 -> V_36 = V_14 -> V_49 = 0 ;
V_14 -> V_114 = F_26 () ;
V_14 -> V_39 = V_93 ;
V_14 -> V_16 = 0 ;
V_14 -> V_42 = V_32 ;
V_14 -> V_52 = V_38 ;
V_32 -> V_115 -> V_46 -> V_116 = V_14 -> V_15 . V_27 ;
V_2 -> V_10 += V_95 ;
error = V_14 -> V_15 . V_27 ;
F_6 ( V_14 ) ;
return error ;
V_112:
if ( F_28 ( V_32 ) && V_14 -> V_43 )
F_30 ( V_93 , V_14 -> V_43 ) ;
F_31 ( V_32 ) ;
V_111:
F_32 ( V_14 ) ;
F_33 ( V_14 ) ;
return error ;
}
static inline int F_62 ( struct V_11 * V_12 , int V_91 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
return F_63 ( V_14 , V_91 ) ;
}
static inline int F_64 ( struct V_11 * V_12 ,
struct V_89 * V_90 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_39 < V_90 -> V_94 . V_93 )
return - V_80 ;
return 0 ;
}
static inline unsigned long F_65 ( void T_6 * V_117 , struct V_118 * V_119 , int V_120 )
{
switch( V_120 ) {
case V_121 :
return F_66 ( V_117 , V_119 , sizeof( * V_119 ) ) ;
case V_122 :
{
struct V_123 V_124 ;
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
F_67 ( & V_119 -> V_15 , & V_124 . V_15 ) ;
V_124 . V_39 = V_119 -> V_39 ;
V_124 . V_125 = V_119 -> V_125 ;
V_124 . V_126 = V_119 -> V_126 ;
V_124 . V_127 = V_119 -> V_127 ;
V_124 . V_128 = V_119 -> V_128 ;
V_124 . V_129 = V_119 -> V_129 ;
V_124 . V_16 = V_119 -> V_16 ;
return F_66 ( V_117 , & V_124 , sizeof( V_124 ) ) ;
}
default:
return - V_80 ;
}
}
static inline unsigned long
F_68 ( struct V_118 * V_124 , void T_6 * V_117 , int V_120 )
{
switch( V_120 ) {
case V_121 :
if ( F_69 ( V_124 , V_117 , sizeof( * V_124 ) ) )
return - V_130 ;
return 0 ;
case V_122 :
{
struct V_123 V_131 ;
if ( F_69 ( & V_131 , V_117 , sizeof( V_131 ) ) )
return - V_130 ;
V_124 -> V_15 . V_132 = V_131 . V_15 . V_132 ;
V_124 -> V_15 . V_133 = V_131 . V_15 . V_133 ;
V_124 -> V_15 . V_17 = V_131 . V_15 . V_17 ;
return 0 ;
}
default:
return - V_80 ;
}
}
static inline unsigned long F_70 ( void T_6 * V_117 , struct V_134 * V_119 , int V_120 )
{
switch( V_120 ) {
case V_121 :
return F_66 ( V_117 , V_119 , sizeof( * V_119 ) ) ;
case V_122 :
{
struct V_135 V_124 ;
if( V_119 -> V_136 > V_137 )
V_124 . V_136 = V_137 ;
else
V_124 . V_136 = ( int ) V_119 -> V_136 ;
V_124 . V_138 = V_119 -> V_138 ;
V_124 . V_139 = V_119 -> V_139 ;
V_124 . V_140 = V_119 -> V_140 ;
V_124 . V_141 = V_119 -> V_141 ;
return F_66 ( V_117 , & V_124 , sizeof( V_124 ) ) ;
}
default:
return - V_80 ;
}
}
static void F_71 ( struct V_13 * V_14 ,
unsigned long * V_142 , unsigned long * V_143 )
{
struct V_74 * V_74 ;
V_74 = V_14 -> V_42 -> V_44 . V_45 -> V_46 ;
if ( F_28 ( V_14 -> V_42 ) ) {
struct V_144 * V_145 = V_74 -> V_146 ;
struct V_147 * V_148 = F_72 ( V_14 -> V_42 ) ;
* V_142 += F_73 ( V_148 ) * V_145 -> V_149 ;
} else {
#ifdef F_74
struct V_150 * V_151 = F_75 ( V_74 ) ;
F_19 ( & V_151 -> V_28 ) ;
* V_142 += V_74 -> V_146 -> V_149 ;
* V_143 += V_151 -> V_152 ;
F_76 ( & V_151 -> V_28 ) ;
#else
* V_142 += V_74 -> V_146 -> V_149 ;
#endif
}
}
static void F_77 ( struct V_1 * V_2 , unsigned long * V_153 ,
unsigned long * V_154 )
{
int V_155 ;
int V_156 , V_53 ;
* V_153 = 0 ;
* V_154 = 0 ;
V_53 = F_3 ( V_2 ) . V_53 ;
for ( V_156 = 0 , V_155 = 0 ; V_156 < V_53 ; V_155 ++ ) {
struct V_11 * V_157 ;
struct V_13 * V_14 ;
V_157 = F_78 ( & F_3 ( V_2 ) . V_23 , V_155 ) ;
if ( V_157 == NULL )
continue;
V_14 = F_5 ( V_157 , struct V_13 , V_15 ) ;
F_71 ( V_14 , V_153 , V_154 ) ;
V_156 ++ ;
}
}
static int F_79 ( struct V_1 * V_2 , int V_158 , int V_159 ,
struct V_123 T_6 * V_117 , int V_120 )
{
struct V_11 * V_12 ;
struct V_118 V_160 ;
struct V_13 * V_14 ;
int V_64 ;
if ( V_159 == V_161 ) {
if ( F_68 ( & V_160 , V_117 , V_120 ) )
return - V_130 ;
}
V_12 = F_80 ( V_2 , & F_3 ( V_2 ) , V_158 , V_159 ,
& V_160 . V_15 , 0 ) ;
if ( F_16 ( V_12 ) )
return F_60 ( V_12 ) ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
V_64 = F_81 ( V_14 , V_159 ) ;
if ( V_64 )
goto V_162;
switch ( V_159 ) {
case V_163 :
F_4 ( V_2 , V_12 ) ;
goto V_164;
case V_161 :
V_64 = F_82 ( & V_160 . V_15 , V_12 ) ;
if ( V_64 )
goto V_162;
V_14 -> V_114 = F_26 () ;
break;
default:
V_64 = - V_80 ;
}
V_162:
F_6 ( V_14 ) ;
V_164:
F_37 ( & F_3 ( V_2 ) . V_48 ) ;
return V_64 ;
}
long F_83 ( int V_158 , char T_6 * V_165 , int V_91 , T_7 * V_166 ,
unsigned long V_167 )
{
struct V_13 * V_14 ;
unsigned long V_66 ;
unsigned long V_93 ;
struct V_32 * V_32 ;
int V_64 ;
unsigned long V_86 ;
unsigned long V_168 ;
int V_169 ;
unsigned long V_170 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
struct V_171 V_171 ;
T_8 V_172 ;
V_64 = - V_80 ;
if ( V_158 < 0 )
goto V_124;
else if ( ( V_66 = ( T_7 ) V_165 ) ) {
if ( V_66 & ( V_167 - 1 ) ) {
if ( V_91 & V_173 )
V_66 &= ~ ( V_167 - 1 ) ;
else
#ifndef F_84
if ( V_66 & ~ V_174 )
#endif
goto V_124;
}
V_86 = V_175 | V_176 ;
} else {
if ( ( V_91 & V_177 ) )
goto V_124;
V_86 = V_175 ;
}
if ( V_91 & V_178 ) {
V_168 = V_179 ;
V_169 = V_180 ;
V_172 = V_181 ;
} else {
V_168 = V_179 | V_182 ;
V_169 = V_180 | V_183 ;
V_172 = V_181 | V_184 ;
}
if ( V_91 & V_185 ) {
V_168 |= V_186 ;
V_169 |= V_187 ;
}
V_2 = V_38 -> V_56 -> V_57 ;
V_14 = F_20 ( V_2 , V_158 ) ;
if ( F_16 ( V_14 ) ) {
V_64 = F_60 ( V_14 ) ;
goto V_124;
}
V_64 = - V_188 ;
if ( F_85 ( V_2 , & V_14 -> V_15 , V_169 ) )
goto V_162;
V_64 = F_86 ( V_14 , V_165 , V_91 ) ;
if ( V_64 )
goto V_162;
V_171 = V_14 -> V_42 -> V_44 ;
F_87 ( & V_171 ) ;
V_14 -> V_16 ++ ;
V_93 = F_88 ( V_171 . V_45 -> V_46 ) ;
F_6 ( V_14 ) ;
V_64 = - V_100 ;
V_35 = F_89 ( sizeof( * V_35 ) , V_189 ) ;
if ( ! V_35 )
goto V_190;
V_32 = F_90 ( & V_171 , V_172 ,
F_28 ( V_14 -> V_42 ) ?
& V_88 :
& V_191 ) ;
if ( ! V_32 )
goto V_192;
V_32 -> V_193 = V_35 ;
V_32 -> V_194 = V_14 -> V_42 -> V_194 ;
V_35 -> V_27 = V_14 -> V_15 . V_27 ;
V_35 -> V_2 = F_91 ( V_2 ) ;
V_35 -> V_32 = V_14 -> V_42 ;
V_35 -> V_60 = NULL ;
V_64 = F_92 ( V_32 , V_168 , V_86 ) ;
if ( V_64 )
goto V_195;
F_36 ( & V_38 -> V_196 -> V_197 ) ;
if ( V_66 && ! ( V_91 & V_177 ) ) {
V_64 = - V_80 ;
if ( F_93 ( V_38 -> V_196 , V_66 , V_66 + V_93 ) )
goto V_198;
if ( V_66 < V_38 -> V_196 -> V_199 &&
V_66 > V_38 -> V_196 -> V_199 - V_93 - V_40 * 5 )
goto V_198;
}
V_170 = F_94 ( V_32 , V_66 , V_93 , V_168 , V_86 , 0 ) ;
* V_166 = V_170 ;
V_64 = 0 ;
if ( F_95 ( V_170 ) )
V_64 = ( long ) V_170 ;
V_198:
F_37 ( & V_38 -> V_196 -> V_197 ) ;
V_195:
F_31 ( V_32 ) ;
V_200:
F_36 ( & F_3 ( V_2 ) . V_48 ) ;
V_14 = F_14 ( V_2 , V_158 ) ;
F_25 ( F_16 ( V_14 ) ) ;
V_14 -> V_16 -- ;
if ( F_34 ( V_2 , V_14 ) )
F_7 ( V_2 , V_14 ) ;
else
F_6 ( V_14 ) ;
F_37 ( & F_3 ( V_2 ) . V_48 ) ;
V_124:
return V_64 ;
V_162:
F_6 ( V_14 ) ;
goto V_124;
V_192:
F_50 ( V_35 ) ;
V_190:
F_96 ( & V_171 ) ;
goto V_200;
}
static int V_26 ( struct V_201 * V_29 , void * V_202 )
{
struct V_203 * V_204 = F_97 ( V_29 ) ;
struct V_13 * V_14 = V_202 ;
unsigned long V_153 = 0 , V_154 = 0 ;
F_71 ( V_14 , & V_153 , & V_154 ) ;
#if V_25 <= 32
#define F_98 "%10lu"
#else
#define F_98 "%21lu"
#endif
return F_99 ( V_29 ,
L_5 F_98 L_6
L_7
F_98 L_8 F_98 L_9 ,
V_14 -> V_15 . V_19 ,
V_14 -> V_15 . V_27 ,
V_14 -> V_15 . V_17 ,
V_14 -> V_39 ,
V_14 -> V_113 ,
V_14 -> V_37 ,
V_14 -> V_16 ,
F_100 ( V_204 , V_14 -> V_15 . V_132 ) ,
F_101 ( V_204 , V_14 -> V_15 . V_133 ) ,
F_100 ( V_204 , V_14 -> V_15 . V_205 ) ,
F_101 ( V_204 , V_14 -> V_15 . V_206 ) ,
V_14 -> V_36 ,
V_14 -> V_49 ,
V_14 -> V_114 ,
V_153 * V_40 ,
V_154 * V_40 ) ;
}
