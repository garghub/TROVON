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
& V_14 -> V_43 , V_106 ) ;
} else {
if ( ( V_91 & V_104 ) &&
V_107 != V_108 )
V_97 = V_105 ;
V_32 = F_59 ( V_96 , V_93 , V_97 ) ;
}
error = F_60 ( V_32 ) ;
if ( F_16 ( V_32 ) )
goto V_109;
V_27 = F_61 ( & F_3 ( V_2 ) , & V_14 -> V_15 , V_2 -> V_7 ) ;
if ( V_27 < 0 ) {
error = V_27 ;
goto V_110;
}
V_14 -> V_111 = F_27 ( V_38 ) ;
V_14 -> V_37 = 0 ;
V_14 -> V_36 = V_14 -> V_49 = 0 ;
V_14 -> V_112 = F_26 () ;
V_14 -> V_39 = V_93 ;
V_14 -> V_16 = 0 ;
V_14 -> V_42 = V_32 ;
V_14 -> V_52 = V_38 ;
V_32 -> V_113 -> V_46 -> V_114 = V_14 -> V_15 . V_27 ;
V_2 -> V_10 += V_95 ;
error = V_14 -> V_15 . V_27 ;
F_6 ( V_14 ) ;
return error ;
V_110:
if ( F_28 ( V_32 ) && V_14 -> V_43 )
F_30 ( V_93 , V_14 -> V_43 ) ;
F_31 ( V_32 ) ;
V_109:
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
static inline unsigned long F_65 ( void T_6 * V_115 , struct V_116 * V_117 , int V_118 )
{
switch( V_118 ) {
case V_119 :
return F_66 ( V_115 , V_117 , sizeof( * V_117 ) ) ;
case V_120 :
{
struct V_121 V_122 ;
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
F_67 ( & V_117 -> V_15 , & V_122 . V_15 ) ;
V_122 . V_39 = V_117 -> V_39 ;
V_122 . V_123 = V_117 -> V_123 ;
V_122 . V_124 = V_117 -> V_124 ;
V_122 . V_125 = V_117 -> V_125 ;
V_122 . V_126 = V_117 -> V_126 ;
V_122 . V_127 = V_117 -> V_127 ;
V_122 . V_16 = V_117 -> V_16 ;
return F_66 ( V_115 , & V_122 , sizeof( V_122 ) ) ;
}
default:
return - V_80 ;
}
}
static inline unsigned long
F_68 ( struct V_116 * V_122 , void T_6 * V_115 , int V_118 )
{
switch( V_118 ) {
case V_119 :
if ( F_69 ( V_122 , V_115 , sizeof( * V_122 ) ) )
return - V_128 ;
return 0 ;
case V_120 :
{
struct V_121 V_129 ;
if ( F_69 ( & V_129 , V_115 , sizeof( V_129 ) ) )
return - V_128 ;
V_122 -> V_15 . V_130 = V_129 . V_15 . V_130 ;
V_122 -> V_15 . V_131 = V_129 . V_15 . V_131 ;
V_122 -> V_15 . V_17 = V_129 . V_15 . V_17 ;
return 0 ;
}
default:
return - V_80 ;
}
}
static inline unsigned long F_70 ( void T_6 * V_115 , struct V_132 * V_117 , int V_118 )
{
switch( V_118 ) {
case V_119 :
return F_66 ( V_115 , V_117 , sizeof( * V_117 ) ) ;
case V_120 :
{
struct V_133 V_122 ;
if( V_117 -> V_134 > V_135 )
V_122 . V_134 = V_135 ;
else
V_122 . V_134 = ( int ) V_117 -> V_134 ;
V_122 . V_136 = V_117 -> V_136 ;
V_122 . V_137 = V_117 -> V_137 ;
V_122 . V_138 = V_117 -> V_138 ;
V_122 . V_139 = V_117 -> V_139 ;
return F_66 ( V_115 , & V_122 , sizeof( V_122 ) ) ;
}
default:
return - V_80 ;
}
}
static void F_71 ( struct V_13 * V_14 ,
unsigned long * V_140 , unsigned long * V_141 )
{
struct V_74 * V_74 ;
V_74 = V_14 -> V_42 -> V_44 . V_45 -> V_46 ;
if ( F_28 ( V_14 -> V_42 ) ) {
struct V_142 * V_143 = V_74 -> V_144 ;
struct V_145 * V_146 = F_72 ( V_14 -> V_42 ) ;
* V_140 += F_73 ( V_146 ) * V_143 -> V_147 ;
} else {
#ifdef F_74
struct V_148 * V_149 = F_75 ( V_74 ) ;
F_19 ( & V_149 -> V_28 ) ;
* V_140 += V_74 -> V_144 -> V_147 ;
* V_141 += V_149 -> V_150 ;
F_76 ( & V_149 -> V_28 ) ;
#else
* V_140 += V_74 -> V_144 -> V_147 ;
#endif
}
}
static void F_77 ( struct V_1 * V_2 , unsigned long * V_151 ,
unsigned long * V_152 )
{
int V_153 ;
int V_154 , V_53 ;
* V_151 = 0 ;
* V_152 = 0 ;
V_53 = F_3 ( V_2 ) . V_53 ;
for ( V_154 = 0 , V_153 = 0 ; V_154 < V_53 ; V_153 ++ ) {
struct V_11 * V_155 ;
struct V_13 * V_14 ;
V_155 = F_78 ( & F_3 ( V_2 ) . V_23 , V_153 ) ;
if ( V_155 == NULL )
continue;
V_14 = F_5 ( V_155 , struct V_13 , V_15 ) ;
F_71 ( V_14 , V_151 , V_152 ) ;
V_154 ++ ;
}
}
static int F_79 ( struct V_1 * V_2 , int V_156 , int V_157 ,
struct V_121 T_6 * V_115 , int V_118 )
{
struct V_11 * V_12 ;
struct V_116 V_158 ;
struct V_13 * V_14 ;
int V_64 ;
if ( V_157 == V_159 ) {
if ( F_68 ( & V_158 , V_115 , V_118 ) )
return - V_128 ;
}
V_12 = F_80 ( V_2 , & F_3 ( V_2 ) , V_156 , V_157 ,
& V_158 . V_15 , 0 ) ;
if ( F_16 ( V_12 ) )
return F_60 ( V_12 ) ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
V_64 = F_81 ( V_14 , V_157 ) ;
if ( V_64 )
goto V_160;
switch ( V_157 ) {
case V_161 :
F_4 ( V_2 , V_12 ) ;
goto V_162;
case V_159 :
F_82 ( & V_158 . V_15 , V_12 ) ;
V_14 -> V_112 = F_26 () ;
break;
default:
V_64 = - V_80 ;
}
V_160:
F_6 ( V_14 ) ;
V_162:
F_37 ( & F_3 ( V_2 ) . V_48 ) ;
return V_64 ;
}
long F_83 ( int V_156 , char T_6 * V_163 , int V_91 , T_7 * V_164 )
{
struct V_13 * V_14 ;
unsigned long V_66 ;
unsigned long V_93 ;
struct V_32 * V_32 ;
int V_64 ;
unsigned long V_86 ;
unsigned long V_165 ;
int V_166 ;
unsigned long V_167 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
struct V_168 V_168 ;
T_8 V_169 ;
V_64 = - V_80 ;
if ( V_156 < 0 )
goto V_122;
else if ( ( V_66 = ( T_7 ) V_163 ) ) {
if ( V_66 & ( V_170 - 1 ) ) {
if ( V_91 & V_171 )
V_66 &= ~ ( V_170 - 1 ) ;
else
#ifndef F_84
if ( V_66 & ~ V_172 )
#endif
goto V_122;
}
V_86 = V_173 | V_174 ;
} else {
if ( ( V_91 & V_175 ) )
goto V_122;
V_86 = V_173 ;
}
if ( V_91 & V_176 ) {
V_165 = V_177 ;
V_166 = V_178 ;
V_169 = V_179 ;
} else {
V_165 = V_177 | V_180 ;
V_166 = V_178 | V_181 ;
V_169 = V_179 | V_182 ;
}
if ( V_91 & V_183 ) {
V_165 |= V_184 ;
V_166 |= V_185 ;
}
V_2 = V_38 -> V_56 -> V_57 ;
V_14 = F_20 ( V_2 , V_156 ) ;
if ( F_16 ( V_14 ) ) {
V_64 = F_60 ( V_14 ) ;
goto V_122;
}
V_64 = - V_186 ;
if ( F_85 ( V_2 , & V_14 -> V_15 , V_166 ) )
goto V_160;
V_64 = F_86 ( V_14 , V_163 , V_91 ) ;
if ( V_64 )
goto V_160;
V_168 = V_14 -> V_42 -> V_44 ;
F_87 ( & V_168 ) ;
V_14 -> V_16 ++ ;
V_93 = F_88 ( V_168 . V_45 -> V_46 ) ;
F_6 ( V_14 ) ;
V_64 = - V_100 ;
V_35 = F_89 ( sizeof( * V_35 ) , V_187 ) ;
if ( ! V_35 )
goto V_188;
V_32 = F_90 ( & V_168 , V_169 ,
F_28 ( V_14 -> V_42 ) ?
& V_88 :
& V_189 ) ;
if ( ! V_32 )
goto V_190;
V_32 -> V_191 = V_35 ;
V_32 -> V_192 = V_14 -> V_42 -> V_192 ;
V_35 -> V_27 = V_14 -> V_15 . V_27 ;
V_35 -> V_2 = F_91 ( V_2 ) ;
V_35 -> V_32 = V_14 -> V_42 ;
V_35 -> V_60 = NULL ;
V_64 = F_92 ( V_32 , V_165 , V_86 ) ;
if ( V_64 )
goto V_193;
F_36 ( & V_38 -> V_194 -> V_195 ) ;
if ( V_66 && ! ( V_91 & V_175 ) ) {
V_64 = - V_80 ;
if ( F_93 ( V_38 -> V_194 , V_66 , V_66 + V_93 ) )
goto V_196;
if ( V_66 < V_38 -> V_194 -> V_197 &&
V_66 > V_38 -> V_194 -> V_197 - V_93 - V_40 * 5 )
goto V_196;
}
V_167 = F_94 ( V_32 , V_66 , V_93 , V_165 , V_86 , 0 ) ;
* V_164 = V_167 ;
V_64 = 0 ;
if ( F_95 ( V_167 ) )
V_64 = ( long ) V_167 ;
V_196:
F_37 ( & V_38 -> V_194 -> V_195 ) ;
V_193:
F_31 ( V_32 ) ;
V_198:
F_36 ( & F_3 ( V_2 ) . V_48 ) ;
V_14 = F_14 ( V_2 , V_156 ) ;
F_25 ( F_16 ( V_14 ) ) ;
V_14 -> V_16 -- ;
if ( F_34 ( V_2 , V_14 ) )
F_7 ( V_2 , V_14 ) ;
else
F_6 ( V_14 ) ;
F_37 ( & F_3 ( V_2 ) . V_48 ) ;
V_122:
return V_64 ;
V_160:
F_6 ( V_14 ) ;
goto V_122;
V_190:
F_50 ( V_35 ) ;
V_188:
F_96 ( & V_168 ) ;
goto V_198;
}
static int V_26 ( struct V_199 * V_29 , void * V_200 )
{
struct V_13 * V_14 = V_200 ;
unsigned long V_151 = 0 , V_152 = 0 ;
F_71 ( V_14 , & V_151 , & V_152 ) ;
#if V_25 <= 32
#define F_97 "%10lu"
#else
#define F_97 "%21lu"
#endif
return F_98 ( V_29 ,
L_5 F_97 L_6
L_7
F_97 L_8 F_97 L_9 ,
V_14 -> V_15 . V_19 ,
V_14 -> V_15 . V_27 ,
V_14 -> V_15 . V_17 ,
V_14 -> V_39 ,
V_14 -> V_111 ,
V_14 -> V_37 ,
V_14 -> V_16 ,
V_14 -> V_15 . V_130 ,
V_14 -> V_15 . V_131 ,
V_14 -> V_15 . V_201 ,
V_14 -> V_15 . V_202 ,
V_14 -> V_36 ,
V_14 -> V_49 ,
V_14 -> V_112 ,
V_151 * V_40 ,
V_152 * V_40 ) ;
}
