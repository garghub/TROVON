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
static unsigned long F_52 ( struct V_32 * V_32 ,
unsigned long V_66 , unsigned long V_81 , unsigned long V_82 ,
unsigned long V_83 )
{
struct V_34 * V_35 = V_34 ( V_32 ) ;
return V_35 -> V_32 -> V_71 -> V_84 ( V_35 -> V_32 , V_66 , V_81 ,
V_82 , V_83 ) ;
}
int F_53 ( struct V_32 * V_32 )
{
return V_32 -> V_71 == & V_85 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_86 * V_87 )
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
return - V_80 ;
if ( V_2 -> V_10 + V_92 > V_2 -> V_5 )
return - V_96 ;
V_14 = F_55 ( sizeof( * V_14 ) ) ;
if ( ! V_14 )
return - V_97 ;
V_14 -> V_15 . V_19 = V_19 ;
V_14 -> V_15 . V_17 = ( V_88 & V_98 ) ;
V_14 -> V_43 = NULL ;
V_14 -> V_15 . V_99 = NULL ;
error = F_56 ( V_14 ) ;
if ( error ) {
F_33 ( V_14 ) ;
return error ;
}
sprintf ( V_93 , L_4 , V_19 ) ;
if ( V_88 & V_100 ) {
if ( V_88 & V_101 )
V_94 = V_102 ;
V_32 = F_57 ( V_93 , V_90 , V_94 ,
& V_14 -> V_43 , V_103 ) ;
} else {
if ( ( V_88 & V_101 ) &&
V_104 != V_105 )
V_94 = V_102 ;
V_32 = F_58 ( V_93 , V_90 , V_94 ) ;
}
error = F_59 ( V_32 ) ;
if ( F_16 ( V_32 ) )
goto V_106;
V_27 = F_60 ( & F_3 ( V_2 ) , & V_14 -> V_15 , V_2 -> V_7 ) ;
if ( V_27 < 0 ) {
error = V_27 ;
goto V_107;
}
V_14 -> V_108 = F_27 ( V_38 ) ;
V_14 -> V_37 = 0 ;
V_14 -> V_36 = V_14 -> V_49 = 0 ;
V_14 -> V_109 = F_26 () ;
V_14 -> V_39 = V_90 ;
V_14 -> V_16 = 0 ;
V_14 -> V_42 = V_32 ;
V_14 -> V_52 = V_38 ;
V_32 -> V_110 -> V_46 -> V_111 = V_14 -> V_15 . V_27 ;
V_2 -> V_10 += V_92 ;
error = V_14 -> V_15 . V_27 ;
F_6 ( V_14 ) ;
return error ;
V_107:
if ( F_28 ( V_32 ) && V_14 -> V_43 )
F_30 ( V_90 , V_14 -> V_43 ) ;
F_31 ( V_32 ) ;
V_106:
F_32 ( V_14 ) ;
F_33 ( V_14 ) ;
return error ;
}
static inline int F_61 ( struct V_11 * V_12 , int V_88 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
return F_62 ( V_14 , V_88 ) ;
}
static inline int F_63 ( struct V_11 * V_12 ,
struct V_86 * V_87 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
if ( V_14 -> V_39 < V_87 -> V_91 . V_90 )
return - V_80 ;
return 0 ;
}
static inline unsigned long F_64 ( void T_6 * V_112 , struct V_113 * V_114 , int V_115 )
{
switch( V_115 ) {
case V_116 :
return F_65 ( V_112 , V_114 , sizeof( * V_114 ) ) ;
case V_117 :
{
struct V_118 V_119 ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
F_66 ( & V_114 -> V_15 , & V_119 . V_15 ) ;
V_119 . V_39 = V_114 -> V_39 ;
V_119 . V_120 = V_114 -> V_120 ;
V_119 . V_121 = V_114 -> V_121 ;
V_119 . V_122 = V_114 -> V_122 ;
V_119 . V_123 = V_114 -> V_123 ;
V_119 . V_124 = V_114 -> V_124 ;
V_119 . V_16 = V_114 -> V_16 ;
return F_65 ( V_112 , & V_119 , sizeof( V_119 ) ) ;
}
default:
return - V_80 ;
}
}
static inline unsigned long
F_67 ( struct V_113 * V_119 , void T_6 * V_112 , int V_115 )
{
switch( V_115 ) {
case V_116 :
if ( F_68 ( V_119 , V_112 , sizeof( * V_119 ) ) )
return - V_125 ;
return 0 ;
case V_117 :
{
struct V_118 V_126 ;
if ( F_68 ( & V_126 , V_112 , sizeof( V_126 ) ) )
return - V_125 ;
V_119 -> V_15 . V_127 = V_126 . V_15 . V_127 ;
V_119 -> V_15 . V_128 = V_126 . V_15 . V_128 ;
V_119 -> V_15 . V_17 = V_126 . V_15 . V_17 ;
return 0 ;
}
default:
return - V_80 ;
}
}
static inline unsigned long F_69 ( void T_6 * V_112 , struct V_129 * V_114 , int V_115 )
{
switch( V_115 ) {
case V_116 :
return F_65 ( V_112 , V_114 , sizeof( * V_114 ) ) ;
case V_117 :
{
struct V_130 V_119 ;
if( V_114 -> V_131 > V_132 )
V_119 . V_131 = V_132 ;
else
V_119 . V_131 = ( int ) V_114 -> V_131 ;
V_119 . V_133 = V_114 -> V_133 ;
V_119 . V_134 = V_114 -> V_134 ;
V_119 . V_135 = V_114 -> V_135 ;
V_119 . V_136 = V_114 -> V_136 ;
return F_65 ( V_112 , & V_119 , sizeof( V_119 ) ) ;
}
default:
return - V_80 ;
}
}
static void F_70 ( struct V_13 * V_14 ,
unsigned long * V_137 , unsigned long * V_138 )
{
struct V_74 * V_74 ;
V_74 = V_14 -> V_42 -> V_44 . V_45 -> V_46 ;
if ( F_28 ( V_14 -> V_42 ) ) {
struct V_139 * V_140 = V_74 -> V_141 ;
struct V_142 * V_143 = F_71 ( V_14 -> V_42 ) ;
* V_137 += F_72 ( V_143 ) * V_140 -> V_144 ;
} else {
#ifdef F_73
struct V_145 * V_146 = F_74 ( V_74 ) ;
F_19 ( & V_146 -> V_28 ) ;
* V_137 += V_74 -> V_141 -> V_144 ;
* V_138 += V_146 -> V_147 ;
F_75 ( & V_146 -> V_28 ) ;
#else
* V_137 += V_74 -> V_141 -> V_144 ;
#endif
}
}
static void F_76 ( struct V_1 * V_2 , unsigned long * V_148 ,
unsigned long * V_149 )
{
int V_150 ;
int V_151 , V_53 ;
* V_148 = 0 ;
* V_149 = 0 ;
V_53 = F_3 ( V_2 ) . V_53 ;
for ( V_151 = 0 , V_150 = 0 ; V_151 < V_53 ; V_150 ++ ) {
struct V_11 * V_152 ;
struct V_13 * V_14 ;
V_152 = F_77 ( & F_3 ( V_2 ) . V_23 , V_150 ) ;
if ( V_152 == NULL )
continue;
V_14 = F_5 ( V_152 , struct V_13 , V_15 ) ;
F_70 ( V_14 , V_148 , V_149 ) ;
V_151 ++ ;
}
}
static int F_78 ( struct V_1 * V_2 , int V_153 , int V_154 ,
struct V_118 T_6 * V_112 , int V_115 )
{
struct V_11 * V_12 ;
struct V_113 V_155 ;
struct V_13 * V_14 ;
int V_64 ;
if ( V_154 == V_156 ) {
if ( F_67 ( & V_155 , V_112 , V_115 ) )
return - V_125 ;
}
V_12 = F_79 ( V_2 , & F_3 ( V_2 ) , V_153 , V_154 ,
& V_155 . V_15 , 0 ) ;
if ( F_16 ( V_12 ) )
return F_59 ( V_12 ) ;
V_14 = F_5 ( V_12 , struct V_13 , V_15 ) ;
V_64 = F_80 ( V_14 , V_154 ) ;
if ( V_64 )
goto V_157;
switch ( V_154 ) {
case V_158 :
F_4 ( V_2 , V_12 ) ;
goto V_159;
case V_156 :
F_81 ( & V_155 . V_15 , V_12 ) ;
V_14 -> V_109 = F_26 () ;
break;
default:
V_64 = - V_80 ;
}
V_157:
F_6 ( V_14 ) ;
V_159:
F_37 ( & F_3 ( V_2 ) . V_48 ) ;
return V_64 ;
}
long F_82 ( int V_153 , char T_6 * V_160 , int V_88 , T_7 * V_161 )
{
struct V_13 * V_14 ;
unsigned long V_66 ;
unsigned long V_90 ;
struct V_32 * V_32 ;
int V_64 ;
unsigned long V_83 ;
unsigned long V_162 ;
int V_163 ;
unsigned long V_164 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
struct V_165 V_165 ;
T_8 V_166 ;
V_64 = - V_80 ;
if ( V_153 < 0 )
goto V_119;
else if ( ( V_66 = ( T_7 ) V_160 ) ) {
if ( V_66 & ( V_167 - 1 ) ) {
if ( V_88 & V_168 )
V_66 &= ~ ( V_167 - 1 ) ;
else
#ifndef F_83
if ( V_66 & ~ V_169 )
#endif
goto V_119;
}
V_83 = V_170 | V_171 ;
} else {
if ( ( V_88 & V_172 ) )
goto V_119;
V_83 = V_170 ;
}
if ( V_88 & V_173 ) {
V_162 = V_174 ;
V_163 = V_175 ;
V_166 = V_176 ;
} else {
V_162 = V_174 | V_177 ;
V_163 = V_175 | V_178 ;
V_166 = V_176 | V_179 ;
}
if ( V_88 & V_180 ) {
V_162 |= V_181 ;
V_163 |= V_182 ;
}
V_2 = V_38 -> V_56 -> V_57 ;
V_14 = F_20 ( V_2 , V_153 ) ;
if ( F_16 ( V_14 ) ) {
V_64 = F_59 ( V_14 ) ;
goto V_119;
}
V_64 = - V_183 ;
if ( F_84 ( V_2 , & V_14 -> V_15 , V_163 ) )
goto V_157;
V_64 = F_85 ( V_14 , V_160 , V_88 ) ;
if ( V_64 )
goto V_157;
V_165 = V_14 -> V_42 -> V_44 ;
F_86 ( & V_165 ) ;
V_14 -> V_16 ++ ;
V_90 = F_87 ( V_165 . V_45 -> V_46 ) ;
F_6 ( V_14 ) ;
V_64 = - V_97 ;
V_35 = F_88 ( sizeof( * V_35 ) , V_184 ) ;
if ( ! V_35 )
goto V_185;
V_32 = F_89 ( & V_165 , V_166 ,
F_28 ( V_14 -> V_42 ) ?
& V_85 :
& V_186 ) ;
if ( ! V_32 )
goto V_187;
V_32 -> V_188 = V_35 ;
V_32 -> V_189 = V_14 -> V_42 -> V_189 ;
V_35 -> V_27 = V_14 -> V_15 . V_27 ;
V_35 -> V_2 = F_90 ( V_2 ) ;
V_35 -> V_32 = V_14 -> V_42 ;
V_35 -> V_60 = NULL ;
F_36 ( & V_38 -> V_190 -> V_191 ) ;
if ( V_66 && ! ( V_88 & V_172 ) ) {
V_64 = - V_80 ;
if ( F_91 ( V_38 -> V_190 , V_66 , V_66 + V_90 ) )
goto V_192;
if ( V_66 < V_38 -> V_190 -> V_193 &&
V_66 > V_38 -> V_190 -> V_193 - V_90 - V_40 * 5 )
goto V_192;
}
V_164 = F_92 ( V_32 , V_66 , V_90 , V_162 , V_83 , 0 ) ;
* V_161 = V_164 ;
V_64 = 0 ;
if ( F_93 ( V_164 ) )
V_64 = ( long ) V_164 ;
V_192:
F_37 ( & V_38 -> V_190 -> V_191 ) ;
F_31 ( V_32 ) ;
V_194:
F_36 ( & F_3 ( V_2 ) . V_48 ) ;
V_14 = F_14 ( V_2 , V_153 ) ;
F_25 ( F_16 ( V_14 ) ) ;
V_14 -> V_16 -- ;
if ( F_34 ( V_2 , V_14 ) )
F_7 ( V_2 , V_14 ) ;
else
F_6 ( V_14 ) ;
F_37 ( & F_3 ( V_2 ) . V_48 ) ;
V_119:
return V_64 ;
V_157:
F_6 ( V_14 ) ;
goto V_119;
V_187:
F_50 ( V_35 ) ;
V_185:
F_94 ( & V_165 ) ;
goto V_194;
}
static int V_26 ( struct V_195 * V_29 , void * V_196 )
{
struct V_13 * V_14 = V_196 ;
unsigned long V_148 = 0 , V_149 = 0 ;
F_70 ( V_14 , & V_148 , & V_149 ) ;
#if V_25 <= 32
#define F_95 "%10lu"
#else
#define F_95 "%21lu"
#endif
return F_96 ( V_29 ,
L_5 F_95 L_6
L_7
F_95 L_8 F_95 L_9 ,
V_14 -> V_15 . V_19 ,
V_14 -> V_15 . V_27 ,
V_14 -> V_15 . V_17 ,
V_14 -> V_39 ,
V_14 -> V_108 ,
V_14 -> V_37 ,
V_14 -> V_16 ,
V_14 -> V_15 . V_127 ,
V_14 -> V_15 . V_128 ,
V_14 -> V_15 . V_197 ,
V_14 -> V_15 . V_198 ,
V_14 -> V_36 ,
V_14 -> V_49 ,
V_14 -> V_109 ,
V_148 * V_40 ,
V_149 * V_40 ) ;
}
