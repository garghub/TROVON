int F_1 ( T_1 * V_1 , struct V_2 * V_3 , int error ,
unsigned int V_4 )
{
if ( ( V_1 -> V_5 & V_6 ) &&
V_1 -> V_7 <= 3 ) {
V_1 -> V_5 &= ~ V_6 ;
F_2 ( V_1 ) ;
}
return F_3 ( V_3 , error , V_4 ) ;
}
void F_4 ( T_1 * V_1 , struct V_8 * V_9 , T_2 V_10 , T_2 V_11 )
{
const struct V_12 * V_13 = V_1 -> V_14 -> V_13 ;
struct V_15 * V_16 = & V_9 -> V_16 ;
struct V_2 * V_3 = V_9 -> V_3 ;
T_2 V_17 = V_16 -> V_18 ;
V_16 -> error = V_11 ;
V_16 -> V_19 = V_10 ;
if ( V_9 -> V_20 & V_21 ) {
T_2 V_22 [ 2 ] ;
V_13 -> V_23 ( V_1 , V_9 , V_22 , 2 ) ;
V_9 -> V_16 . V_22 = V_22 [ 0 ] ;
V_9 -> V_24 . V_22 = V_22 [ 1 ] ;
}
F_5 ( V_1 , V_9 ) ;
if ( ( V_9 -> V_25 & V_26 ) &&
V_17 == V_27 ) {
if ( V_16 -> V_28 != 0xc4 ) {
F_6 ( V_29 L_1 ,
V_1 -> V_30 ) ;
F_7 ( V_1 -> V_30 , V_9 ) ;
} else
V_1 -> V_5 |= V_31 ;
}
if ( V_3 && V_3 -> V_32 == V_33 ) {
struct V_8 * V_34 = V_3 -> V_35 ;
if ( V_9 -> V_25 & V_36 )
F_8 ( V_34 ) ;
else
memcpy ( V_34 , V_9 , sizeof( * V_9 ) ) ;
}
}
int F_9 ( T_1 * V_1 , int error , unsigned int V_4 )
{
T_3 * V_14 = V_1 -> V_14 ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_37 ;
if ( F_10 ( V_3 ) && error <= 0 )
V_4 = F_11 ( V_3 ) << 9 ;
V_37 = F_1 ( V_1 , V_3 , error , V_4 ) ;
if ( V_37 == 0 )
V_14 -> V_3 = NULL ;
return V_37 ;
}
void F_12 ( T_1 * V_1 , struct V_2 * V_3 )
{
T_2 V_38 = ( V_3 -> V_32 == V_39 ) && V_3 -> V_40 ;
T_2 V_41 = V_1 -> V_41 ;
V_1 -> V_42 = NULL ;
if ( ( V_41 == V_43 || V_41 == V_44 ) && V_38 ) {
V_3 -> V_45 = 0 ;
} else {
if ( V_41 == V_44 )
V_3 -> V_45 = V_46 ;
else if ( V_3 -> V_32 != V_47 && V_3 -> V_45 == 0 )
V_3 -> V_45 = - V_48 ;
}
F_9 ( V_1 , - V_48 , F_13 ( V_3 ) ) ;
}
static void F_14 ( T_1 * V_1 , struct V_15 * V_16 )
{
V_16 -> V_49 = V_1 -> V_50 ;
V_16 -> V_28 = V_1 -> V_50 ;
V_16 -> V_51 = V_1 -> V_52 ;
V_16 -> V_53 = V_1 -> V_52 >> 8 ;
V_16 -> V_54 = ( V_1 -> V_55 - 1 ) | V_1 -> V_56 ;
V_16 -> V_18 = V_57 ;
}
static void F_15 ( T_1 * V_1 , struct V_15 * V_16 )
{
V_16 -> V_49 = V_1 -> V_50 ;
V_16 -> V_18 = V_58 ;
}
static void F_16 ( T_1 * V_1 , struct V_15 * V_16 )
{
V_16 -> V_49 = V_1 -> V_59 ;
V_16 -> V_18 = V_60 ;
}
static T_4 F_17 ( T_1 * V_1 )
{
struct V_8 V_9 ;
#ifdef F_18
F_6 ( V_61 L_2 , V_1 -> V_30 , V_62 ,
V_1 -> V_63 ) ;
#endif
if ( V_1 -> V_41 != V_64 ) {
V_1 -> V_63 = 0 ;
V_1 -> V_59 = 0 ;
return V_65 ;
}
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_66 = V_67 ;
if ( V_1 -> V_63 & V_68 ) {
V_1 -> V_63 &= ~ V_68 ;
F_14 ( V_1 , & V_9 . V_16 ) ;
} else if ( V_1 -> V_63 & V_69 ) {
V_1 -> V_63 &= ~ V_69 ;
F_15 ( V_1 , & V_9 . V_16 ) ;
} else if ( V_1 -> V_63 & V_70 ) {
V_1 -> V_63 &= ~ V_70 ;
F_16 ( V_1 , & V_9 . V_16 ) ;
} else
F_19 () ;
V_9 . V_71 . V_72 . V_16 = V_73 | V_74 ;
V_9 . V_71 . V_75 . V_16 = V_76 | V_74 ;
V_9 . V_25 = V_26 ;
F_20 ( V_1 , & V_9 ) ;
return V_77 ;
}
void F_21 ( T_1 * V_1 , struct V_8 * V_9 )
{
T_3 * V_14 = V_1 -> V_14 ;
struct V_78 * V_79 = V_14 -> V_80 ;
struct V_2 * V_3 = V_9 -> V_3 ;
V_9 -> V_81 = F_22 ( V_1 -> V_82 , V_3 , V_79 ) ;
}
void F_23 ( struct V_8 * V_9 , unsigned int V_4 )
{
V_9 -> V_83 = V_9 -> V_84 = V_4 ;
V_9 -> V_85 = 0 ;
V_9 -> V_86 = NULL ;
}
static T_4 F_24 ( T_1 * V_1 ,
struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_35 ;
if ( V_9 ) {
if ( V_9 -> V_66 == V_87 ) {
F_23 ( V_9 , F_11 ( V_3 ) << 9 ) ;
F_21 ( V_1 , V_9 ) ;
}
return F_20 ( V_1 , V_9 ) ;
}
#ifdef F_18
F_6 ( L_3 , V_1 -> V_30 ) ;
#endif
V_3 -> V_45 = 0 ;
F_9 ( V_1 , 0 , F_13 ( V_3 ) ) ;
return V_65 ;
}
static T_4 F_25 ( T_1 * V_1 , struct V_2 * V_3 )
{
T_2 V_9 = V_3 -> V_9 [ 0 ] ;
switch ( V_9 ) {
case V_88 :
case V_89 :
return F_26 ( V_1 , V_3 ) ;
case V_90 :
return F_27 ( V_1 , V_3 ) ;
case V_91 :
return F_28 ( V_1 ) ;
default:
F_19 () ;
}
}
static T_4 F_29 ( T_1 * V_1 , struct V_2 * V_3 )
{
T_4 V_92 ;
F_30 ( ! ( V_3 -> V_93 & V_94 ) ) ;
#ifdef F_18
F_6 ( L_4 ,
V_1 -> V_14 -> V_30 , ( unsigned long ) V_3 ) ;
#endif
if ( V_1 -> V_95 && ( V_1 -> V_96 > V_1 -> V_95 ) ) {
V_3 -> V_93 |= V_97 ;
goto V_98;
}
if ( F_31 ( V_3 ) )
F_32 ( V_1 , V_3 ) ;
V_1 -> V_14 -> V_13 -> V_99 ( V_1 ) ;
if ( F_33 ( & V_92 , V_1 , V_1 -> V_100 ,
V_101 | V_102 , V_103 ) ) {
F_6 ( V_29 L_5 , V_1 -> V_30 ) ;
return V_92 ;
}
if ( V_1 -> V_63 == 0 ) {
struct V_104 * V_105 ;
if ( V_1 -> V_106 == 0xff )
F_34 ( V_1 , V_1 -> V_107 ) ;
if ( V_3 -> V_32 == V_33 )
return F_24 ( V_1 , V_3 ) ;
else if ( F_31 ( V_3 ) ) {
struct V_108 * V_109 = V_3 -> V_35 ;
#ifdef F_35
F_6 ( L_6 ,
V_1 -> V_30 , V_109 -> V_110 ) ;
#endif
V_92 = F_36 ( V_1 , V_3 ) ;
if ( V_92 == V_65 &&
V_109 -> V_110 == V_111 )
F_37 ( V_1 , V_3 ) ;
return V_92 ;
} else if ( ! V_3 -> V_40 && V_3 -> V_32 == V_39 )
return F_25 ( V_1 , V_3 ) ;
V_105 = * (struct V_104 * * ) V_3 -> V_40 -> V_112 ;
return V_105 -> V_113 ( V_1 , V_3 , F_38 ( V_3 ) ) ;
}
return F_17 ( V_1 ) ;
V_98:
F_12 ( V_1 , V_3 ) ;
return V_65 ;
}
void F_39 ( T_1 * V_1 , unsigned long V_114 )
{
if ( V_114 > V_115 )
V_114 = V_115 ;
V_1 -> V_116 = V_114 + V_117 ;
V_1 -> V_5 |= V_118 ;
}
static inline int F_40 ( T_3 * V_14 )
{
if ( V_14 -> V_119 )
return 1 ;
V_14 -> V_119 = 1 ;
return 0 ;
}
static inline void F_41 ( T_3 * V_14 )
{
V_14 -> V_119 = 0 ;
}
static inline int F_42 ( struct V_120 * V_121 , T_3 * V_14 )
{
int V_37 = 0 ;
if ( V_121 -> V_122 & V_123 ) {
V_37 = F_43 ( V_124 , & V_121 -> V_125 ) ;
if ( V_37 == 0 ) {
if ( V_121 -> V_126 )
V_121 -> V_126 ( V_127 , V_14 ) ;
}
}
return V_37 ;
}
static inline void F_44 ( struct V_120 * V_121 )
{
if ( V_121 -> V_122 & V_123 ) {
if ( V_121 -> V_128 )
V_121 -> V_128 () ;
F_45 ( V_124 , & V_121 -> V_125 ) ;
}
}
static void F_46 ( struct V_129 * V_130 , struct V_2 * V_3 )
{
if ( V_3 )
F_47 ( V_130 , V_3 ) ;
if ( V_3 || F_48 ( V_130 ) ) {
F_49 ( V_130 , 3 ) ;
}
}
void F_50 ( T_1 * V_1 , struct V_2 * V_3 )
{
struct V_129 * V_130 = V_1 -> V_82 ;
unsigned long V_131 ;
F_51 ( V_130 -> V_132 , V_131 ) ;
F_46 ( V_130 , V_3 ) ;
F_52 ( V_130 -> V_132 , V_131 ) ;
}
void F_53 ( struct V_129 * V_130 )
{
T_1 * V_1 = V_130 -> V_133 ;
T_3 * V_14 = V_1 -> V_14 ;
struct V_120 * V_121 = V_14 -> V_121 ;
struct V_2 * V_3 = NULL ;
T_4 V_92 ;
unsigned long V_134 = 3 ;
F_54 ( V_130 -> V_132 ) ;
F_55 () ;
if ( F_42 ( V_121 , V_14 ) )
goto V_135;
F_56 ( & V_14 -> V_136 ) ;
if ( ! F_40 ( V_14 ) ) {
T_3 * V_137 ;
F_57 ( V_14 -> V_3 ) ;
V_138:
V_137 = V_14 -> V_121 -> V_139 ;
if ( V_1 -> V_5 & V_118 &&
F_58 ( V_1 -> V_116 , V_117 ) ) {
unsigned long V_140 = V_117 - V_1 -> V_116 ;
V_134 = F_59 ( V_140 + 1 ) ;
F_41 ( V_14 ) ;
goto V_141;
}
if ( ( V_14 -> V_121 -> V_122 & V_123 ) &&
V_14 != V_137 ) {
T_1 * V_142 =
V_137 ? V_137 -> V_142 : NULL ;
if ( V_142 &&
( V_142 -> V_5 & V_143 ) == 0 )
V_137 -> V_13 -> V_144 ( V_137 ,
V_145 |
V_146 ) ;
V_14 -> V_121 -> V_139 = V_14 ;
}
V_14 -> V_142 = V_1 ;
V_1 -> V_5 &= ~ ( V_118 | V_31 ) ;
F_54 ( & V_14 -> V_136 ) ;
F_56 ( V_130 -> V_132 ) ;
if ( ! V_3 )
V_3 = F_60 ( V_1 -> V_82 ) ;
F_54 ( V_130 -> V_132 ) ;
F_56 ( & V_14 -> V_136 ) ;
if ( ! V_3 ) {
F_41 ( V_14 ) ;
goto V_72;
}
if ( ( V_1 -> V_5 & V_147 ) &&
F_31 ( V_3 ) == 0 &&
( V_3 -> V_93 & V_148 ) == 0 ) {
F_41 ( V_14 ) ;
goto V_141;
}
V_14 -> V_3 = V_3 ;
F_54 ( & V_14 -> V_136 ) ;
V_92 = F_29 ( V_1 , V_3 ) ;
F_56 ( & V_14 -> V_136 ) ;
if ( V_92 == V_65 ) {
V_3 = V_14 -> V_3 ;
V_14 -> V_3 = NULL ;
goto V_138;
}
} else
goto V_141;
V_72:
F_54 ( & V_14 -> V_136 ) ;
if ( V_3 == NULL )
F_44 ( V_121 ) ;
F_56 ( V_130 -> V_132 ) ;
return;
V_141:
F_54 ( & V_14 -> V_136 ) ;
F_44 ( V_121 ) ;
V_135:
F_56 ( V_130 -> V_132 ) ;
F_46 ( V_130 , V_3 ) ;
}
static int F_61 ( T_1 * V_1 )
{
T_3 * V_14 = V_1 -> V_14 ;
T_2 V_10 = 0 ;
if ( V_1 -> V_149 )
return V_14 -> V_150 -> V_151 ( V_1 ) ;
if ( V_14 -> V_152 . V_153 &&
( V_14 -> V_122 & V_154 ) == 0 )
V_10 = V_14 -> V_13 -> V_155 ( V_14 ) ;
else
V_10 = V_14 -> V_13 -> V_156 ( V_14 ) ;
if ( V_10 & V_101 )
return 0 ;
return 1 ;
}
void F_62 ( unsigned long V_22 )
{
T_3 * V_14 = ( T_3 * ) V_22 ;
T_1 * V_157 ( V_1 ) ;
T_5 * V_158 ;
unsigned long V_131 ;
int V_159 = - 1 ;
int V_141 = 0 ;
struct V_2 * V_157 ( V_160 ) ;
F_51 ( & V_14 -> V_136 , V_131 ) ;
V_158 = V_14 -> V_158 ;
if ( V_158 == NULL || V_14 -> V_161 != V_14 -> V_162 ) {
} else {
T_6 * V_163 = V_14 -> V_163 ;
T_4 V_92 = V_65 ;
V_1 = V_14 -> V_142 ;
if ( V_163 ) {
V_159 = V_163 ( V_1 ) ;
if ( V_159 > 0 ) {
V_14 -> V_164 . V_165 = V_117 + V_159 ;
V_14 -> V_162 = V_14 -> V_161 ;
F_63 ( & V_14 -> V_164 ) ;
F_52 ( & V_14 -> V_136 , V_131 ) ;
return;
}
}
V_14 -> V_158 = NULL ;
V_14 -> V_163 = NULL ;
F_64 ( & V_14 -> V_136 ) ;
F_65 ( V_14 -> V_166 ) ;
F_66 () ;
if ( V_14 -> V_167 ) {
V_92 = V_158 ( V_1 ) ;
} else if ( F_61 ( V_1 ) ) {
if ( V_1 -> V_149 )
V_14 -> V_150 -> V_168 ( V_1 ) ;
if ( V_14 -> V_169 && V_14 -> V_169 -> V_170 )
V_14 -> V_169 -> V_170 ( V_1 ) ;
F_6 ( V_171 L_7 ,
V_1 -> V_30 ) ;
V_92 = V_158 ( V_1 ) ;
} else {
if ( V_1 -> V_149 )
V_92 = F_67 ( V_1 , V_159 ) ;
else
V_92 = F_68 ( V_1 , L_8 ,
V_14 -> V_13 -> V_156 ( V_14 ) ) ;
}
F_56 ( & V_14 -> V_136 ) ;
F_69 ( V_14 -> V_166 ) ;
if ( V_92 == V_65 && V_14 -> V_167 == 0 ) {
V_160 = V_14 -> V_3 ;
V_14 -> V_3 = NULL ;
F_41 ( V_14 ) ;
V_141 = 1 ;
}
}
F_52 ( & V_14 -> V_136 , V_131 ) ;
if ( V_141 ) {
F_44 ( V_14 -> V_121 ) ;
F_50 ( V_1 , V_160 ) ;
}
}
static void F_70 ( int V_166 , T_3 * V_14 )
{
T_2 V_10 = V_14 -> V_13 -> V_156 ( V_14 ) ;
if ( ! F_71 ( V_10 , V_172 , V_173 ) ) {
static unsigned long V_174 , V_175 ;
++ V_175 ;
if ( F_58 ( V_117 , V_174 + V_176 ) ) {
V_174 = V_117 ;
F_6 ( V_29 L_9
L_10 ,
V_14 -> V_30 , V_10 , V_175 ) ;
}
}
}
T_7 V_127 ( int V_166 , void * V_177 )
{
T_3 * V_14 = ( T_3 * ) V_177 ;
struct V_120 * V_121 = V_14 -> V_121 ;
T_1 * V_157 ( V_1 ) ;
T_5 * V_158 ;
unsigned long V_131 ;
T_4 V_92 ;
T_7 V_178 = V_179 ;
int V_141 = 0 ;
struct V_2 * V_157 ( V_160 ) ;
if ( V_121 -> V_122 & V_123 ) {
if ( V_14 != V_121 -> V_139 )
goto V_180;
}
F_51 ( & V_14 -> V_136 , V_131 ) ;
if ( V_14 -> V_169 && V_14 -> V_169 -> V_181 &&
V_14 -> V_169 -> V_181 ( V_14 ) == 0 )
goto V_72;
V_158 = V_14 -> V_158 ;
if ( V_158 == NULL || V_14 -> V_167 ) {
if ( ( V_121 -> V_182 & V_183 ) == 0 ) {
F_70 ( V_166 , V_14 ) ;
} else {
( void ) V_14 -> V_13 -> V_156 ( V_14 ) ;
}
goto V_72;
}
V_1 = V_14 -> V_142 ;
if ( ! F_61 ( V_1 ) )
goto V_72;
V_14 -> V_158 = NULL ;
V_14 -> V_163 = NULL ;
V_14 -> V_161 ++ ;
F_72 ( & V_14 -> V_164 ) ;
F_64 ( & V_14 -> V_136 ) ;
if ( V_14 -> V_169 && V_14 -> V_169 -> V_170 )
V_14 -> V_169 -> V_170 ( V_1 ) ;
if ( V_1 -> V_5 & V_184 )
F_73 () ;
V_92 = V_158 ( V_1 ) ;
F_56 ( & V_14 -> V_136 ) ;
if ( V_92 == V_65 && V_14 -> V_167 == 0 ) {
F_30 ( V_14 -> V_158 ) ;
V_160 = V_14 -> V_3 ;
V_14 -> V_3 = NULL ;
F_41 ( V_14 ) ;
V_141 = 1 ;
}
V_178 = V_185 ;
V_72:
F_52 ( & V_14 -> V_136 , V_131 ) ;
V_180:
if ( V_141 ) {
F_44 ( V_14 -> V_121 ) ;
F_50 ( V_1 , V_160 ) ;
}
return V_178 ;
}
void F_74 ( T_1 * V_1 , int V_186 , int V_187 )
{
T_3 * V_14 = V_1 -> V_14 ;
T_2 V_188 [ 4 ] = { 0 } ;
while ( V_187 > 0 ) {
if ( V_186 )
V_14 -> V_13 -> V_189 ( V_1 , NULL , V_188 , F_75 ( 4 , V_187 ) ) ;
else
V_14 -> V_13 -> V_23 ( V_1 , NULL , V_188 , F_75 ( 4 , V_187 ) ) ;
V_187 -= 4 ;
}
}
