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
F_30 ( F_31 ( V_14 -> V_42 ) -> V_44 ,
V_14 -> V_43 ) ;
F_32 ( V_14 -> V_42 ) ;
F_33 ( V_14 ) ;
F_34 ( V_14 ) ;
}
static bool F_35 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
return ( V_14 -> V_16 == 0 ) &&
( V_2 -> V_9 ||
( V_14 -> V_15 . V_17 & V_18 ) ) ;
}
static void F_36 ( struct V_30 * V_31 )
{
struct V_32 * V_32 = V_31 -> V_33 ;
struct V_34 * V_35 = V_34 ( V_32 ) ;
struct V_13 * V_14 ;
struct V_1 * V_2 = V_35 -> V_2 ;
F_37 ( & F_3 ( V_2 ) . V_45 ) ;
V_14 = F_14 ( V_2 , V_35 -> V_27 ) ;
F_25 ( F_16 ( V_14 ) ) ;
V_14 -> V_37 = F_27 ( V_38 ) ;
V_14 -> V_46 = F_26 () ;
V_14 -> V_16 -- ;
if ( F_35 ( V_2 , V_14 ) )
F_7 ( V_2 , V_14 ) ;
else
F_6 ( V_14 ) ;
F_38 ( & F_3 ( V_2 ) . V_45 ) ;
}
static int F_39 ( int V_27 , void * V_47 , void * V_48 )
{
struct V_1 * V_2 = V_48 ;
struct V_11 * V_12 = V_47 ;
struct V_13 * V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_49 != V_38 )
return 0 ;
V_14 -> V_49 = NULL ;
if ( ! V_2 -> V_9 )
return 0 ;
if ( F_35 ( V_2 , V_14 ) ) {
F_17 ( V_14 ) ;
F_7 ( V_2 , V_14 ) ;
}
return 0 ;
}
static int F_40 ( int V_27 , void * V_47 , void * V_48 )
{
struct V_1 * V_2 = V_48 ;
struct V_11 * V_12 = V_47 ;
struct V_13 * V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_49 != NULL )
return 0 ;
if ( F_35 ( V_2 , V_14 ) ) {
F_17 ( V_14 ) ;
F_7 ( V_2 , V_14 ) ;
}
return 0 ;
}
void F_41 ( struct V_1 * V_2 )
{
F_37 ( & F_3 ( V_2 ) . V_45 ) ;
if ( F_3 ( V_2 ) . V_50 )
F_42 ( & F_3 ( V_2 ) . V_23 , & F_40 , V_2 ) ;
F_38 ( & F_3 ( V_2 ) . V_45 ) ;
}
void F_43 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_53 -> V_54 ;
if ( F_3 ( V_2 ) . V_50 == 0 )
return;
F_37 ( & F_3 ( V_2 ) . V_45 ) ;
if ( F_3 ( V_2 ) . V_50 )
F_42 ( & F_3 ( V_2 ) . V_23 , & F_39 , V_2 ) ;
F_38 ( & F_3 ( V_2 ) . V_45 ) ;
}
static int F_44 ( struct V_30 * V_31 , struct V_55 * V_56 )
{
struct V_32 * V_32 = V_31 -> V_33 ;
struct V_34 * V_35 = V_34 ( V_32 ) ;
return V_35 -> V_57 -> V_58 ( V_31 , V_56 ) ;
}
static int F_45 ( struct V_30 * V_31 , struct V_59 * V_60 )
{
struct V_32 * V_32 = V_31 -> V_33 ;
struct V_34 * V_35 = V_34 ( V_32 ) ;
int V_61 = 0 ;
if ( V_35 -> V_57 -> V_62 )
V_61 = V_35 -> V_57 -> V_62 ( V_31 , V_60 ) ;
return V_61 ;
}
static struct V_59 * F_46 ( struct V_30 * V_31 ,
unsigned long V_63 )
{
struct V_32 * V_32 = V_31 -> V_33 ;
struct V_34 * V_35 = V_34 ( V_32 ) ;
struct V_59 * V_64 = NULL ;
if ( V_35 -> V_57 -> V_65 )
V_64 = V_35 -> V_57 -> V_65 ( V_31 , V_63 ) ;
else if ( V_31 -> V_66 )
V_64 = V_31 -> V_66 ;
return V_64 ;
}
static int F_47 ( struct V_32 * V_32 , struct V_30 * V_31 )
{
struct V_34 * V_35 = V_34 ( V_32 ) ;
int V_67 ;
V_67 = V_35 -> V_32 -> V_68 -> V_69 ( V_35 -> V_32 , V_31 ) ;
if ( V_67 != 0 )
return V_67 ;
V_35 -> V_57 = V_31 -> V_57 ;
#ifdef F_48
F_25 ( ! V_35 -> V_57 -> V_58 ) ;
#endif
V_31 -> V_57 = & V_70 ;
F_24 ( V_31 ) ;
return V_67 ;
}
static int F_49 ( struct V_71 * V_72 , struct V_32 * V_32 )
{
struct V_34 * V_35 = V_34 ( V_32 ) ;
F_50 ( V_35 -> V_2 ) ;
V_34 ( V_32 ) = NULL ;
F_51 ( V_35 ) ;
return 0 ;
}
static int F_52 ( struct V_32 * V_32 , T_2 V_73 , T_2 V_74 , int V_75 )
{
struct V_34 * V_35 = V_34 ( V_32 ) ;
if ( ! V_35 -> V_32 -> V_68 -> V_76 )
return - V_77 ;
return V_35 -> V_32 -> V_68 -> V_76 ( V_35 -> V_32 , V_73 , V_74 , V_75 ) ;
}
static long F_53 ( struct V_32 * V_32 , int V_17 , T_2 V_78 ,
T_2 V_79 )
{
struct V_34 * V_35 = V_34 ( V_32 ) ;
if ( ! V_35 -> V_32 -> V_68 -> V_80 )
return - V_81 ;
return V_35 -> V_32 -> V_68 -> V_80 ( V_32 , V_17 , V_78 , V_79 ) ;
}
static unsigned long F_54 ( struct V_32 * V_32 ,
unsigned long V_63 , unsigned long V_79 , unsigned long V_82 ,
unsigned long V_83 )
{
struct V_34 * V_35 = V_34 ( V_32 ) ;
return V_35 -> V_32 -> V_68 -> V_84 ( V_35 -> V_32 , V_63 , V_79 ,
V_82 , V_83 ) ;
}
int F_55 ( struct V_32 * V_32 )
{
return V_32 -> V_68 == & V_85 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
T_3 V_19 = V_87 -> V_19 ;
int V_88 = V_87 -> V_89 ;
T_4 V_90 = V_87 -> V_91 . V_90 ;
int error ;
struct V_13 * V_14 ;
int V_92 = ( V_90 + V_40 - 1 ) >> V_41 ;
struct V_32 * V_32 ;
char V_93 [ 13 ] ;
int V_27 ;
T_5 V_94 = 0 ;
if ( V_90 < V_95 || V_90 > V_2 -> V_3 )
return - V_77 ;
if ( V_2 -> V_10 + V_92 > V_2 -> V_5 )
return - V_96 ;
V_14 = F_57 ( sizeof( * V_14 ) ) ;
if ( ! V_14 )
return - V_97 ;
V_14 -> V_15 . V_19 = V_19 ;
V_14 -> V_15 . V_17 = ( V_88 & V_98 ) ;
V_14 -> V_43 = NULL ;
V_14 -> V_15 . V_99 = NULL ;
error = F_58 ( V_14 ) ;
if ( error ) {
F_34 ( V_14 ) ;
return error ;
}
sprintf ( V_93 , L_4 , V_19 ) ;
if ( V_88 & V_100 ) {
if ( V_88 & V_101 )
V_94 = V_102 ;
V_32 = F_59 ( V_93 , 0 , V_90 , V_94 ,
& V_14 -> V_43 , V_103 ,
( V_88 >> V_104 ) & V_105 ) ;
} else {
if ( ( V_88 & V_101 ) &&
V_106 != V_107 )
V_94 = V_102 ;
V_32 = F_60 ( V_93 , V_90 , V_94 ) ;
}
error = F_61 ( V_32 ) ;
if ( F_16 ( V_32 ) )
goto V_108;
V_27 = F_62 ( & F_3 ( V_2 ) , & V_14 -> V_15 , V_2 -> V_7 ) ;
if ( V_27 < 0 ) {
error = V_27 ;
goto V_109;
}
V_14 -> V_110 = F_27 ( V_38 ) ;
V_14 -> V_37 = 0 ;
V_14 -> V_36 = V_14 -> V_46 = 0 ;
V_14 -> V_111 = F_26 () ;
V_14 -> V_39 = V_90 ;
V_14 -> V_16 = 0 ;
V_14 -> V_42 = V_32 ;
V_14 -> V_49 = V_38 ;
F_31 ( V_32 ) -> V_112 = V_14 -> V_15 . V_27 ;
V_2 -> V_10 += V_92 ;
error = V_14 -> V_15 . V_27 ;
F_6 ( V_14 ) ;
return error ;
V_109:
if ( F_28 ( V_32 ) && V_14 -> V_43 )
F_30 ( V_90 , V_14 -> V_43 ) ;
F_32 ( V_32 ) ;
V_108:
F_33 ( V_14 ) ;
F_34 ( V_14 ) ;
return error ;
}
static inline int F_63 ( struct V_11 * V_12 , int V_88 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
return F_64 ( V_14 , V_88 ) ;
}
static inline int F_65 ( struct V_11 * V_12 ,
struct V_86 * V_87 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_39 < V_87 -> V_91 . V_90 )
return - V_77 ;
return 0 ;
}
static inline unsigned long F_66 ( void T_6 * V_113 , struct V_114 * V_115 , int V_116 )
{
switch( V_116 ) {
case V_117 :
return F_67 ( V_113 , V_115 , sizeof( * V_115 ) ) ;
case V_118 :
{
struct V_119 V_120 ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
F_68 ( & V_115 -> V_15 , & V_120 . V_15 ) ;
V_120 . V_39 = V_115 -> V_39 ;
V_120 . V_121 = V_115 -> V_121 ;
V_120 . V_122 = V_115 -> V_122 ;
V_120 . V_123 = V_115 -> V_123 ;
V_120 . V_124 = V_115 -> V_124 ;
V_120 . V_125 = V_115 -> V_125 ;
V_120 . V_16 = V_115 -> V_16 ;
return F_67 ( V_113 , & V_120 , sizeof( V_120 ) ) ;
}
default:
return - V_77 ;
}
}
static inline unsigned long
F_69 ( struct V_114 * V_120 , void T_6 * V_113 , int V_116 )
{
switch( V_116 ) {
case V_117 :
if ( F_70 ( V_120 , V_113 , sizeof( * V_120 ) ) )
return - V_126 ;
return 0 ;
case V_118 :
{
struct V_119 V_127 ;
if ( F_70 ( & V_127 , V_113 , sizeof( V_127 ) ) )
return - V_126 ;
V_120 -> V_15 . V_128 = V_127 . V_15 . V_128 ;
V_120 -> V_15 . V_129 = V_127 . V_15 . V_129 ;
V_120 -> V_15 . V_17 = V_127 . V_15 . V_17 ;
return 0 ;
}
default:
return - V_77 ;
}
}
static inline unsigned long F_71 ( void T_6 * V_113 , struct V_130 * V_115 , int V_116 )
{
switch( V_116 ) {
case V_117 :
return F_67 ( V_113 , V_115 , sizeof( * V_115 ) ) ;
case V_118 :
{
struct V_131 V_120 ;
if( V_115 -> V_132 > V_133 )
V_120 . V_132 = V_133 ;
else
V_120 . V_132 = ( int ) V_115 -> V_132 ;
V_120 . V_134 = V_115 -> V_134 ;
V_120 . V_135 = V_115 -> V_135 ;
V_120 . V_136 = V_115 -> V_136 ;
V_120 . V_137 = V_115 -> V_137 ;
return F_67 ( V_113 , & V_120 , sizeof( V_120 ) ) ;
}
default:
return - V_77 ;
}
}
static void F_72 ( struct V_13 * V_14 ,
unsigned long * V_138 , unsigned long * V_139 )
{
struct V_71 * V_71 ;
V_71 = F_31 ( V_14 -> V_42 ) ;
if ( F_28 ( V_14 -> V_42 ) ) {
struct V_140 * V_141 = V_71 -> V_142 ;
struct V_143 * V_144 = F_73 ( V_14 -> V_42 ) ;
* V_138 += F_74 ( V_144 ) * V_141 -> V_145 ;
} else {
#ifdef F_75
struct V_146 * V_147 = F_76 ( V_71 ) ;
F_19 ( & V_147 -> V_28 ) ;
* V_138 += V_71 -> V_142 -> V_145 ;
* V_139 += V_147 -> V_148 ;
F_77 ( & V_147 -> V_28 ) ;
#else
* V_138 += V_71 -> V_142 -> V_145 ;
#endif
}
}
static void F_78 ( struct V_1 * V_2 , unsigned long * V_149 ,
unsigned long * V_150 )
{
int V_151 ;
int V_152 , V_50 ;
* V_149 = 0 ;
* V_150 = 0 ;
V_50 = F_3 ( V_2 ) . V_50 ;
for ( V_152 = 0 , V_151 = 0 ; V_152 < V_50 ; V_151 ++ ) {
struct V_11 * V_153 ;
struct V_13 * V_14 ;
V_153 = F_79 ( & F_3 ( V_2 ) . V_23 , V_151 ) ;
if ( V_153 == NULL )
continue;
V_14 = F_5 ( V_153 , struct V_13 , V_15 ) ;
F_72 ( V_14 , V_149 , V_150 ) ;
V_152 ++ ;
}
}
static int F_80 ( struct V_1 * V_2 , int V_154 , int V_155 ,
struct V_119 T_6 * V_113 , int V_116 )
{
struct V_11 * V_12 ;
struct V_114 V_156 ;
struct V_13 * V_14 ;
int V_61 ;
if ( V_155 == V_157 ) {
if ( F_69 ( & V_156 , V_113 , V_116 ) )
return - V_126 ;
}
V_12 = F_81 ( V_2 , & F_3 ( V_2 ) , V_154 , V_155 ,
& V_156 . V_15 , 0 ) ;
if ( F_16 ( V_12 ) )
return F_61 ( V_12 ) ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
V_61 = F_82 ( V_14 , V_155 ) ;
if ( V_61 )
goto V_158;
switch ( V_155 ) {
case V_159 :
F_4 ( V_2 , V_12 ) ;
goto V_160;
case V_157 :
V_61 = F_83 ( & V_156 . V_15 , V_12 ) ;
if ( V_61 )
goto V_158;
V_14 -> V_111 = F_26 () ;
break;
default:
V_61 = - V_77 ;
}
V_158:
F_6 ( V_14 ) ;
V_160:
F_38 ( & F_3 ( V_2 ) . V_45 ) ;
return V_61 ;
}
long F_84 ( int V_154 , char T_6 * V_161 , int V_88 , T_7 * V_162 ,
unsigned long V_163 )
{
struct V_13 * V_14 ;
unsigned long V_63 ;
unsigned long V_90 ;
struct V_32 * V_32 ;
int V_61 ;
unsigned long V_83 ;
unsigned long V_164 ;
int V_165 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
struct V_166 V_166 ;
T_8 V_167 ;
unsigned long V_168 = 0 ;
V_61 = - V_77 ;
if ( V_154 < 0 )
goto V_120;
else if ( ( V_63 = ( T_7 ) V_161 ) ) {
if ( V_63 & ( V_163 - 1 ) ) {
if ( V_88 & V_169 )
V_63 &= ~ ( V_163 - 1 ) ;
else
#ifndef F_85
if ( V_63 & ~ V_170 )
#endif
goto V_120;
}
V_83 = V_171 | V_172 ;
} else {
if ( ( V_88 & V_173 ) )
goto V_120;
V_83 = V_171 ;
}
if ( V_88 & V_174 ) {
V_164 = V_175 ;
V_165 = V_176 ;
V_167 = V_177 ;
} else {
V_164 = V_175 | V_178 ;
V_165 = V_176 | V_179 ;
V_167 = V_177 | V_180 ;
}
if ( V_88 & V_181 ) {
V_164 |= V_182 ;
V_165 |= V_183 ;
}
V_2 = V_38 -> V_53 -> V_54 ;
V_14 = F_20 ( V_2 , V_154 ) ;
if ( F_16 ( V_14 ) ) {
V_61 = F_61 ( V_14 ) ;
goto V_120;
}
V_61 = - V_184 ;
if ( F_86 ( V_2 , & V_14 -> V_15 , V_165 ) )
goto V_158;
V_61 = F_87 ( V_14 , V_161 , V_88 ) ;
if ( V_61 )
goto V_158;
V_166 = V_14 -> V_42 -> V_185 ;
F_88 ( & V_166 ) ;
V_14 -> V_16 ++ ;
V_90 = F_89 ( V_166 . V_186 -> V_187 ) ;
F_6 ( V_14 ) ;
V_61 = - V_97 ;
V_35 = F_90 ( sizeof( * V_35 ) , V_188 ) ;
if ( ! V_35 )
goto V_189;
V_32 = F_91 ( & V_166 , V_167 ,
F_28 ( V_14 -> V_42 ) ?
& V_85 :
& V_190 ) ;
V_61 = F_61 ( V_32 ) ;
if ( F_16 ( V_32 ) )
goto V_191;
V_32 -> V_192 = V_35 ;
V_32 -> V_193 = V_14 -> V_42 -> V_193 ;
V_35 -> V_27 = V_14 -> V_15 . V_27 ;
V_35 -> V_2 = F_92 ( V_2 ) ;
V_35 -> V_32 = V_14 -> V_42 ;
V_35 -> V_57 = NULL ;
V_61 = F_93 ( V_32 , V_164 , V_83 ) ;
if ( V_61 )
goto V_194;
F_37 ( & V_38 -> V_195 -> V_196 ) ;
if ( V_63 && ! ( V_88 & V_173 ) ) {
V_61 = - V_77 ;
if ( F_94 ( V_38 -> V_195 , V_63 , V_63 + V_90 ) )
goto V_197;
if ( V_63 < V_38 -> V_195 -> V_198 &&
V_63 > V_38 -> V_195 -> V_198 - V_90 - V_40 * 5 )
goto V_197;
}
V_63 = F_95 ( V_32 , V_63 , V_90 , V_164 , V_83 , 0 , & V_168 ) ;
* V_162 = V_63 ;
V_61 = 0 ;
if ( F_96 ( V_63 ) )
V_61 = ( long ) V_63 ;
V_197:
F_38 ( & V_38 -> V_195 -> V_196 ) ;
if ( V_168 )
F_97 ( V_63 , V_168 ) ;
V_194:
F_32 ( V_32 ) ;
V_199:
F_37 ( & F_3 ( V_2 ) . V_45 ) ;
V_14 = F_14 ( V_2 , V_154 ) ;
F_25 ( F_16 ( V_14 ) ) ;
V_14 -> V_16 -- ;
if ( F_35 ( V_2 , V_14 ) )
F_7 ( V_2 , V_14 ) ;
else
F_6 ( V_14 ) ;
F_38 ( & F_3 ( V_2 ) . V_45 ) ;
V_120:
return V_61 ;
V_158:
F_6 ( V_14 ) ;
goto V_120;
V_191:
F_51 ( V_35 ) ;
V_189:
F_98 ( & V_166 ) ;
goto V_199;
}
static int V_26 ( struct V_200 * V_29 , void * V_201 )
{
struct V_202 * V_203 = F_99 ( V_29 ) ;
struct V_13 * V_14 = V_201 ;
unsigned long V_149 = 0 , V_150 = 0 ;
F_72 ( V_14 , & V_149 , & V_150 ) ;
#if V_25 <= 32
#define F_100 "%10lu"
#else
#define F_100 "%21lu"
#endif
return F_101 ( V_29 ,
L_5 F_100 L_6
L_7
F_100 L_8 F_100 L_9 ,
V_14 -> V_15 . V_19 ,
V_14 -> V_15 . V_27 ,
V_14 -> V_15 . V_17 ,
V_14 -> V_39 ,
V_14 -> V_110 ,
V_14 -> V_37 ,
V_14 -> V_16 ,
F_102 ( V_203 , V_14 -> V_15 . V_128 ) ,
F_103 ( V_203 , V_14 -> V_15 . V_129 ) ,
F_102 ( V_203 , V_14 -> V_15 . V_204 ) ,
F_103 ( V_203 , V_14 -> V_15 . V_205 ) ,
V_14 -> V_36 ,
V_14 -> V_46 ,
V_14 -> V_111 ,
V_149 * V_40 ,
V_150 * V_40 ) ;
}
