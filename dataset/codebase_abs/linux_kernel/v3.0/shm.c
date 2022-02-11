void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = 0 ;
F_2 ( & F_3 ( V_2 ) ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 ;
V_13 = F_5 ( V_11 , struct V_12 , V_14 ) ;
if ( V_13 -> V_15 ) {
V_13 -> V_14 . V_16 |= V_17 ;
V_13 -> V_14 . V_18 = V_19 ;
F_6 ( V_13 ) ;
} else
F_7 ( V_2 , V_13 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 , & F_3 ( V_2 ) , F_4 ) ;
F_10 ( & V_2 -> V_20 [ V_21 ] . V_22 ) ;
}
void T_1 F_11 ( void )
{
F_1 ( & V_23 ) ;
F_12 ( L_1 ,
#if V_24 <= 32
L_2 ,
#else
L_3 ,
#endif
V_21 , V_25 ) ;
}
static inline struct V_12 * F_13 ( struct V_1 * V_2 , int V_26 )
{
struct V_10 * V_11 = F_14 ( & F_3 ( V_2 ) , V_26 ) ;
if ( F_15 ( V_11 ) )
return (struct V_12 * ) V_11 ;
return F_5 ( V_11 , struct V_12 , V_14 ) ;
}
static inline struct V_12 * F_16 ( struct V_1 * V_2 ,
int V_26 )
{
struct V_10 * V_11 = F_17 ( & F_3 ( V_2 ) , V_26 ) ;
if ( F_15 ( V_11 ) )
return (struct V_12 * ) V_11 ;
return F_5 ( V_11 , struct V_12 , V_14 ) ;
}
static inline void F_18 ( struct V_1 * V_2 , struct V_12 * V_27 )
{
F_19 ( & F_3 ( V_2 ) , & V_27 -> V_14 ) ;
}
static void F_20 ( struct V_28 * V_29 )
{
struct V_30 * V_30 = V_29 -> V_31 ;
struct V_32 * V_33 = V_32 ( V_30 ) ;
struct V_12 * V_13 ;
V_13 = F_13 ( V_33 -> V_2 , V_33 -> V_26 ) ;
F_21 ( F_15 ( V_13 ) ) ;
V_13 -> V_34 = F_22 () ;
V_13 -> V_35 = F_23 ( V_36 ) ;
V_13 -> V_15 ++ ;
F_6 ( V_13 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
V_2 -> V_9 -= ( V_13 -> V_37 + V_38 - 1 ) >> V_39 ;
F_18 ( V_2 , V_13 ) ;
F_6 ( V_13 ) ;
if ( ! F_24 ( V_13 -> V_40 ) )
F_25 ( V_13 -> V_40 , 0 , V_13 -> V_41 ) ;
else if ( V_13 -> V_41 )
F_26 ( V_13 -> V_40 -> V_42 . V_43 -> V_44 -> V_45 ,
V_13 -> V_41 ) ;
F_27 ( V_13 -> V_40 ) ;
F_28 ( V_13 ) ;
F_29 ( V_13 ) ;
}
static void F_30 ( struct V_28 * V_29 )
{
struct V_30 * V_30 = V_29 -> V_31 ;
struct V_32 * V_33 = V_32 ( V_30 ) ;
struct V_12 * V_13 ;
struct V_1 * V_2 = V_33 -> V_2 ;
F_31 ( & F_3 ( V_2 ) . V_46 ) ;
V_13 = F_13 ( V_2 , V_33 -> V_26 ) ;
F_21 ( F_15 ( V_13 ) ) ;
V_13 -> V_35 = F_23 ( V_36 ) ;
V_13 -> V_47 = F_22 () ;
V_13 -> V_15 -- ;
if( V_13 -> V_15 == 0 &&
V_13 -> V_14 . V_16 & V_17 )
F_7 ( V_2 , V_13 ) ;
else
F_6 ( V_13 ) ;
F_32 ( & F_3 ( V_2 ) . V_46 ) ;
}
static int F_33 ( struct V_28 * V_29 , struct V_48 * V_49 )
{
struct V_30 * V_30 = V_29 -> V_31 ;
struct V_32 * V_33 = V_32 ( V_30 ) ;
return V_33 -> V_50 -> V_51 ( V_29 , V_49 ) ;
}
static int F_34 ( struct V_28 * V_29 , struct V_52 * V_53 )
{
struct V_30 * V_30 = V_29 -> V_31 ;
struct V_32 * V_33 = V_32 ( V_30 ) ;
int V_54 = 0 ;
if ( V_33 -> V_50 -> V_55 )
V_54 = V_33 -> V_50 -> V_55 ( V_29 , V_53 ) ;
return V_54 ;
}
static struct V_52 * F_35 ( struct V_28 * V_29 ,
unsigned long V_56 )
{
struct V_30 * V_30 = V_29 -> V_31 ;
struct V_32 * V_33 = V_32 ( V_30 ) ;
struct V_52 * V_57 = NULL ;
if ( V_33 -> V_50 -> V_58 )
V_57 = V_33 -> V_50 -> V_58 ( V_29 , V_56 ) ;
else if ( V_29 -> V_59 )
V_57 = V_29 -> V_59 ;
return V_57 ;
}
static int F_36 ( struct V_30 * V_30 , struct V_28 * V_29 )
{
struct V_32 * V_33 = V_32 ( V_30 ) ;
int V_60 ;
V_60 = V_33 -> V_30 -> V_61 -> V_62 ( V_33 -> V_30 , V_29 ) ;
if ( V_60 != 0 )
return V_60 ;
V_33 -> V_50 = V_29 -> V_50 ;
#ifdef F_37
F_21 ( ! V_33 -> V_50 -> V_51 ) ;
#endif
V_29 -> V_50 = & V_63 ;
F_20 ( V_29 ) ;
return V_60 ;
}
static int F_38 ( struct V_64 * V_65 , struct V_30 * V_30 )
{
struct V_32 * V_33 = V_32 ( V_30 ) ;
F_39 ( V_33 -> V_2 ) ;
V_32 ( V_30 ) = NULL ;
F_40 ( V_33 ) ;
return 0 ;
}
static int F_41 ( struct V_30 * V_30 , int V_66 )
{
struct V_32 * V_33 = V_32 ( V_30 ) ;
if ( ! V_33 -> V_30 -> V_61 -> V_67 )
return - V_68 ;
return V_33 -> V_30 -> V_61 -> V_67 ( V_33 -> V_30 , V_66 ) ;
}
static unsigned long F_42 ( struct V_30 * V_30 ,
unsigned long V_56 , unsigned long V_69 , unsigned long V_70 ,
unsigned long V_71 )
{
struct V_32 * V_33 = V_32 ( V_30 ) ;
return V_33 -> V_30 -> V_61 -> V_72 ( V_33 -> V_30 , V_56 , V_69 ,
V_70 , V_71 ) ;
}
int F_43 ( struct V_30 * V_30 )
{
return V_30 -> V_61 == & V_73 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
T_2 V_18 = V_75 -> V_18 ;
int V_76 = V_75 -> V_77 ;
T_3 V_78 = V_75 -> V_79 . V_78 ;
int error ;
struct V_12 * V_13 ;
int V_80 = ( V_78 + V_38 - 1 ) >> V_39 ;
struct V_30 * V_30 ;
char V_81 [ 13 ] ;
int V_26 ;
T_4 V_82 = 0 ;
if ( V_78 < V_83 || V_78 > V_2 -> V_3 )
return - V_68 ;
if ( V_2 -> V_9 + V_80 > V_2 -> V_5 )
return - V_84 ;
V_13 = F_45 ( sizeof( * V_13 ) ) ;
if ( ! V_13 )
return - V_85 ;
V_13 -> V_14 . V_18 = V_18 ;
V_13 -> V_14 . V_16 = ( V_76 & V_86 ) ;
V_13 -> V_41 = NULL ;
V_13 -> V_14 . V_87 = NULL ;
error = F_46 ( V_13 ) ;
if ( error ) {
F_29 ( V_13 ) ;
return error ;
}
sprintf ( V_81 , L_4 , V_18 ) ;
if ( V_76 & V_88 ) {
if ( V_76 & V_89 )
V_82 = V_90 ;
V_30 = F_47 ( V_81 , V_78 , V_82 ,
& V_13 -> V_41 , V_91 ) ;
} else {
if ( ( V_76 & V_89 ) &&
V_92 != V_93 )
V_82 = V_90 ;
V_30 = F_48 ( V_81 , V_78 , V_82 ) ;
}
error = F_49 ( V_30 ) ;
if ( F_15 ( V_30 ) )
goto V_94;
V_26 = F_50 ( & F_3 ( V_2 ) , & V_13 -> V_14 , V_2 -> V_7 ) ;
if ( V_26 < 0 ) {
error = V_26 ;
goto V_95;
}
V_13 -> V_96 = F_23 ( V_36 ) ;
V_13 -> V_35 = 0 ;
V_13 -> V_34 = V_13 -> V_47 = 0 ;
V_13 -> V_97 = F_22 () ;
V_13 -> V_37 = V_78 ;
V_13 -> V_15 = 0 ;
V_13 -> V_40 = V_30 ;
V_30 -> V_98 -> V_44 -> V_99 = V_13 -> V_14 . V_26 ;
V_2 -> V_9 += V_80 ;
error = V_13 -> V_14 . V_26 ;
F_6 ( V_13 ) ;
return error ;
V_95:
if ( F_24 ( V_30 ) && V_13 -> V_41 )
F_26 ( V_78 , V_13 -> V_41 ) ;
F_27 ( V_30 ) ;
V_94:
F_28 ( V_13 ) ;
F_29 ( V_13 ) ;
return error ;
}
static inline int F_51 ( struct V_10 * V_11 , int V_76 )
{
struct V_12 * V_13 ;
V_13 = F_5 ( V_11 , struct V_12 , V_14 ) ;
return F_52 ( V_13 , V_76 ) ;
}
static inline int F_53 ( struct V_10 * V_11 ,
struct V_74 * V_75 )
{
struct V_12 * V_13 ;
V_13 = F_5 ( V_11 , struct V_12 , V_14 ) ;
if ( V_13 -> V_37 < V_75 -> V_79 . V_78 )
return - V_68 ;
return 0 ;
}
static inline unsigned long F_54 ( void T_5 * V_100 , struct V_101 * V_102 , int V_103 )
{
switch( V_103 ) {
case V_104 :
return F_55 ( V_100 , V_102 , sizeof( * V_102 ) ) ;
case V_105 :
{
struct V_106 V_107 ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
F_56 ( & V_102 -> V_14 , & V_107 . V_14 ) ;
V_107 . V_37 = V_102 -> V_37 ;
V_107 . V_108 = V_102 -> V_108 ;
V_107 . V_109 = V_102 -> V_109 ;
V_107 . V_110 = V_102 -> V_110 ;
V_107 . V_111 = V_102 -> V_111 ;
V_107 . V_112 = V_102 -> V_112 ;
V_107 . V_15 = V_102 -> V_15 ;
return F_55 ( V_100 , & V_107 , sizeof( V_107 ) ) ;
}
default:
return - V_68 ;
}
}
static inline unsigned long
F_57 ( struct V_101 * V_107 , void T_5 * V_100 , int V_103 )
{
switch( V_103 ) {
case V_104 :
if ( F_58 ( V_107 , V_100 , sizeof( * V_107 ) ) )
return - V_113 ;
return 0 ;
case V_105 :
{
struct V_106 V_114 ;
if ( F_58 ( & V_114 , V_100 , sizeof( V_114 ) ) )
return - V_113 ;
V_107 -> V_14 . V_115 = V_114 . V_14 . V_115 ;
V_107 -> V_14 . V_116 = V_114 . V_14 . V_116 ;
V_107 -> V_14 . V_16 = V_114 . V_14 . V_16 ;
return 0 ;
}
default:
return - V_68 ;
}
}
static inline unsigned long F_59 ( void T_5 * V_100 , struct V_117 * V_102 , int V_103 )
{
switch( V_103 ) {
case V_104 :
return F_55 ( V_100 , V_102 , sizeof( * V_102 ) ) ;
case V_105 :
{
struct V_118 V_107 ;
if( V_102 -> V_119 > V_120 )
V_107 . V_119 = V_120 ;
else
V_107 . V_119 = ( int ) V_102 -> V_119 ;
V_107 . V_121 = V_102 -> V_121 ;
V_107 . V_122 = V_102 -> V_122 ;
V_107 . V_123 = V_102 -> V_123 ;
V_107 . V_124 = V_102 -> V_124 ;
return F_55 ( V_100 , & V_107 , sizeof( V_107 ) ) ;
}
default:
return - V_68 ;
}
}
static void F_60 ( struct V_12 * V_13 ,
unsigned long * V_125 , unsigned long * V_126 )
{
struct V_64 * V_64 ;
V_64 = V_13 -> V_40 -> V_42 . V_43 -> V_44 ;
if ( F_24 ( V_13 -> V_40 ) ) {
struct V_127 * V_128 = V_64 -> V_129 ;
struct V_130 * V_131 = F_61 ( V_13 -> V_40 ) ;
* V_125 += F_62 ( V_131 ) * V_128 -> V_132 ;
} else {
#ifdef F_63
struct V_133 * V_134 = F_64 ( V_64 ) ;
F_65 ( & V_134 -> V_135 ) ;
* V_125 += V_64 -> V_129 -> V_132 ;
* V_126 += V_134 -> V_136 ;
F_66 ( & V_134 -> V_135 ) ;
#else
* V_125 += V_64 -> V_129 -> V_132 ;
#endif
}
}
static void F_67 ( struct V_1 * V_2 , unsigned long * V_137 ,
unsigned long * V_138 )
{
int V_139 ;
int V_140 , V_141 ;
* V_137 = 0 ;
* V_138 = 0 ;
V_141 = F_3 ( V_2 ) . V_141 ;
for ( V_140 = 0 , V_139 = 0 ; V_140 < V_141 ; V_139 ++ ) {
struct V_10 * V_142 ;
struct V_12 * V_13 ;
V_142 = F_68 ( & F_3 ( V_2 ) . V_22 , V_139 ) ;
if ( V_142 == NULL )
continue;
V_13 = F_5 ( V_142 , struct V_12 , V_14 ) ;
F_60 ( V_13 , V_137 , V_138 ) ;
V_140 ++ ;
}
}
static int F_69 ( struct V_1 * V_2 , int V_143 , int V_144 ,
struct V_106 T_5 * V_100 , int V_103 )
{
struct V_10 * V_11 ;
struct V_101 V_145 ;
struct V_12 * V_13 ;
int V_54 ;
if ( V_144 == V_146 ) {
if ( F_57 ( & V_145 , V_100 , V_103 ) )
return - V_113 ;
}
V_11 = F_70 ( V_2 , & F_3 ( V_2 ) , V_143 , V_144 ,
& V_145 . V_14 , 0 ) ;
if ( F_15 ( V_11 ) )
return F_49 ( V_11 ) ;
V_13 = F_5 ( V_11 , struct V_12 , V_14 ) ;
V_54 = F_71 ( V_13 , V_144 ) ;
if ( V_54 )
goto V_147;
switch ( V_144 ) {
case V_148 :
F_4 ( V_2 , V_11 ) ;
goto V_149;
case V_146 :
F_72 ( & V_145 . V_14 , V_11 ) ;
V_13 -> V_97 = F_22 () ;
break;
default:
V_54 = - V_68 ;
}
V_147:
F_6 ( V_13 ) ;
V_149:
F_32 ( & F_3 ( V_2 ) . V_46 ) ;
return V_54 ;
}
long F_73 ( int V_143 , char T_5 * V_150 , int V_76 , T_6 * V_151 )
{
struct V_12 * V_13 ;
unsigned long V_56 ;
unsigned long V_78 ;
struct V_30 * V_30 ;
int V_54 ;
unsigned long V_71 ;
unsigned long V_152 ;
int V_153 ;
unsigned long V_154 ;
struct V_1 * V_2 ;
struct V_32 * V_33 ;
struct V_155 V_155 ;
T_7 V_156 ;
V_54 = - V_68 ;
if ( V_143 < 0 )
goto V_107;
else if ( ( V_56 = ( T_6 ) V_150 ) ) {
if ( V_56 & ( V_157 - 1 ) ) {
if ( V_76 & V_158 )
V_56 &= ~ ( V_157 - 1 ) ;
else
#ifndef F_74
if ( V_56 & ~ V_159 )
#endif
goto V_107;
}
V_71 = V_160 | V_161 ;
} else {
if ( ( V_76 & V_162 ) )
goto V_107;
V_71 = V_160 ;
}
if ( V_76 & V_163 ) {
V_152 = V_164 ;
V_153 = V_165 ;
V_156 = V_166 ;
} else {
V_152 = V_164 | V_167 ;
V_153 = V_165 | V_168 ;
V_156 = V_166 | V_169 ;
}
if ( V_76 & V_170 ) {
V_152 |= V_171 ;
V_153 |= V_172 ;
}
V_2 = V_36 -> V_173 -> V_174 ;
V_13 = F_16 ( V_2 , V_143 ) ;
if ( F_15 ( V_13 ) ) {
V_54 = F_49 ( V_13 ) ;
goto V_107;
}
V_54 = - V_175 ;
if ( F_75 ( V_2 , & V_13 -> V_14 , V_153 ) )
goto V_147;
V_54 = F_76 ( V_13 , V_150 , V_76 ) ;
if ( V_54 )
goto V_147;
V_155 = V_13 -> V_40 -> V_42 ;
F_77 ( & V_155 ) ;
V_13 -> V_15 ++ ;
V_78 = F_78 ( V_155 . V_43 -> V_44 ) ;
F_6 ( V_13 ) ;
V_54 = - V_85 ;
V_33 = F_79 ( sizeof( * V_33 ) , V_176 ) ;
if ( ! V_33 )
goto V_177;
V_30 = F_80 ( & V_155 , V_156 ,
F_24 ( V_13 -> V_40 ) ?
& V_73 :
& V_178 ) ;
if ( ! V_30 )
goto V_179;
V_30 -> V_180 = V_33 ;
V_30 -> V_181 = V_13 -> V_40 -> V_181 ;
V_33 -> V_26 = V_13 -> V_14 . V_26 ;
V_33 -> V_2 = F_81 ( V_2 ) ;
V_33 -> V_30 = V_13 -> V_40 ;
V_33 -> V_50 = NULL ;
F_31 ( & V_36 -> V_182 -> V_183 ) ;
if ( V_56 && ! ( V_76 & V_162 ) ) {
V_54 = - V_68 ;
if ( F_82 ( V_36 -> V_182 , V_56 , V_56 + V_78 ) )
goto V_184;
if ( V_56 < V_36 -> V_182 -> V_185 &&
V_56 > V_36 -> V_182 -> V_185 - V_78 - V_38 * 5 )
goto V_184;
}
V_154 = F_83 ( V_30 , V_56 , V_78 , V_152 , V_71 , 0 ) ;
* V_151 = V_154 ;
V_54 = 0 ;
if ( F_84 ( V_154 ) )
V_54 = ( long ) V_154 ;
V_184:
F_32 ( & V_36 -> V_182 -> V_183 ) ;
F_27 ( V_30 ) ;
V_186:
F_31 ( & F_3 ( V_2 ) . V_46 ) ;
V_13 = F_13 ( V_2 , V_143 ) ;
F_21 ( F_15 ( V_13 ) ) ;
V_13 -> V_15 -- ;
if( V_13 -> V_15 == 0 &&
V_13 -> V_14 . V_16 & V_17 )
F_7 ( V_2 , V_13 ) ;
else
F_6 ( V_13 ) ;
F_32 ( & F_3 ( V_2 ) . V_46 ) ;
V_107:
return V_54 ;
V_147:
F_6 ( V_13 ) ;
goto V_107;
V_179:
F_40 ( V_33 ) ;
V_177:
F_85 ( & V_155 ) ;
goto V_186;
}
static int V_25 ( struct V_187 * V_27 , void * V_188 )
{
struct V_12 * V_13 = V_188 ;
unsigned long V_137 = 0 , V_138 = 0 ;
F_60 ( V_13 , & V_137 , & V_138 ) ;
#if V_24 <= 32
#define F_86 "%10lu"
#else
#define F_86 "%21lu"
#endif
return F_87 ( V_27 ,
L_5 F_86 L_6
L_7
F_86 L_8 F_86 L_9 ,
V_13 -> V_14 . V_18 ,
V_13 -> V_14 . V_26 ,
V_13 -> V_14 . V_16 ,
V_13 -> V_37 ,
V_13 -> V_96 ,
V_13 -> V_35 ,
V_13 -> V_15 ,
V_13 -> V_14 . V_115 ,
V_13 -> V_14 . V_116 ,
V_13 -> V_14 . V_189 ,
V_13 -> V_14 . V_190 ,
V_13 -> V_34 ,
V_13 -> V_47 ,
V_13 -> V_97 ,
V_137 * V_38 ,
V_138 * V_38 ) ;
}
