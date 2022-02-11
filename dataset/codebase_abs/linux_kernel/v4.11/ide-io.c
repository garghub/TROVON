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
if ( V_3 && F_8 ( V_3 ) ) {
struct V_8 * V_32 = V_3 -> V_33 ;
if ( V_9 -> V_25 & V_34 )
F_9 ( V_32 ) ;
else
memcpy ( V_32 , V_9 , sizeof( * V_9 ) ) ;
}
}
int F_10 ( T_1 * V_1 , int error , unsigned int V_4 )
{
T_3 * V_14 = V_1 -> V_14 ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_35 ;
if ( F_11 ( V_3 ) && error <= 0 )
V_4 = F_12 ( V_3 ) << 9 ;
V_35 = F_1 ( V_1 , V_3 , error , V_4 ) ;
if ( V_35 == 0 )
V_14 -> V_3 = NULL ;
return V_35 ;
}
void F_13 ( T_1 * V_1 , struct V_2 * V_3 )
{
T_2 V_36 = F_14 ( V_3 ) && V_3 -> V_37 ;
T_2 V_38 = V_1 -> V_38 ;
V_1 -> V_39 = NULL ;
if ( ( V_38 == V_40 || V_38 == V_41 ) && V_36 ) {
V_3 -> V_42 = 0 ;
} else {
if ( V_38 == V_41 )
V_3 -> V_42 = V_43 ;
else if ( F_15 ( V_3 ) && V_3 -> V_42 == 0 )
V_3 -> V_42 = - V_44 ;
}
F_10 ( V_1 , - V_44 , F_16 ( V_3 ) ) ;
}
static void F_17 ( T_1 * V_1 , struct V_15 * V_16 )
{
V_16 -> V_45 = V_1 -> V_46 ;
V_16 -> V_28 = V_1 -> V_46 ;
V_16 -> V_47 = V_1 -> V_48 ;
V_16 -> V_49 = V_1 -> V_48 >> 8 ;
V_16 -> V_50 = ( V_1 -> V_51 - 1 ) | V_1 -> V_52 ;
V_16 -> V_18 = V_53 ;
}
static void F_18 ( T_1 * V_1 , struct V_15 * V_16 )
{
V_16 -> V_45 = V_1 -> V_46 ;
V_16 -> V_18 = V_54 ;
}
static void F_19 ( T_1 * V_1 , struct V_15 * V_16 )
{
V_16 -> V_45 = V_1 -> V_55 ;
V_16 -> V_18 = V_56 ;
}
static T_4 F_20 ( T_1 * V_1 )
{
struct V_8 V_9 ;
#ifdef F_21
F_6 ( V_57 L_2 , V_1 -> V_30 , V_58 ,
V_1 -> V_59 ) ;
#endif
if ( V_1 -> V_38 != V_60 ) {
V_1 -> V_59 = 0 ;
V_1 -> V_55 = 0 ;
return V_61 ;
}
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_62 = V_63 ;
if ( V_1 -> V_59 & V_64 ) {
V_1 -> V_59 &= ~ V_64 ;
F_17 ( V_1 , & V_9 . V_16 ) ;
} else if ( V_1 -> V_59 & V_65 ) {
V_1 -> V_59 &= ~ V_65 ;
F_18 ( V_1 , & V_9 . V_16 ) ;
} else if ( V_1 -> V_59 & V_66 ) {
V_1 -> V_59 &= ~ V_66 ;
F_19 ( V_1 , & V_9 . V_16 ) ;
} else
F_22 () ;
V_9 . V_67 . V_68 . V_16 = V_69 | V_70 ;
V_9 . V_67 . V_71 . V_16 = V_72 | V_70 ;
V_9 . V_25 = V_26 ;
F_23 ( V_1 , & V_9 ) ;
return V_73 ;
}
void F_24 ( T_1 * V_1 , struct V_8 * V_9 )
{
T_3 * V_14 = V_1 -> V_14 ;
struct V_74 * V_75 = V_14 -> V_76 ;
struct V_2 * V_3 = V_9 -> V_3 ;
V_9 -> V_77 = F_25 ( V_1 -> V_78 , V_3 , V_75 ) ;
}
void F_26 ( struct V_8 * V_9 , unsigned int V_4 )
{
V_9 -> V_79 = V_9 -> V_80 = V_4 ;
V_9 -> V_81 = 0 ;
V_9 -> V_82 = NULL ;
}
static T_4 F_27 ( T_1 * V_1 ,
struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_33 ;
if ( V_9 ) {
if ( V_9 -> V_62 == V_83 ) {
F_26 ( V_9 , F_12 ( V_3 ) << 9 ) ;
F_24 ( V_1 , V_9 ) ;
}
return F_23 ( V_1 , V_9 ) ;
}
#ifdef F_21
F_6 ( L_3 , V_1 -> V_30 ) ;
#endif
V_3 -> V_42 = 0 ;
F_10 ( V_1 , 0 , F_16 ( V_3 ) ) ;
return V_61 ;
}
static T_4 F_28 ( T_1 * V_1 , struct V_2 * V_3 )
{
T_2 V_9 = F_29 ( V_3 ) -> V_9 [ 0 ] ;
switch ( V_9 ) {
case V_84 :
case V_85 :
return F_30 ( V_1 , V_3 ) ;
case V_86 :
return F_31 ( V_1 , V_3 ) ;
case V_87 :
return F_32 ( V_1 ) ;
default:
F_22 () ;
}
}
static T_4 F_33 ( T_1 * V_1 , struct V_2 * V_3 )
{
T_4 V_88 ;
F_34 ( ! ( V_3 -> V_89 & V_90 ) ) ;
#ifdef F_21
F_6 ( L_4 ,
V_1 -> V_14 -> V_30 , ( unsigned long ) V_3 ) ;
#endif
if ( V_1 -> V_91 && ( V_1 -> V_92 > V_1 -> V_91 ) ) {
V_3 -> V_89 |= V_93 ;
goto V_94;
}
if ( F_35 ( V_3 ) )
F_36 ( V_1 , V_3 ) ;
V_1 -> V_14 -> V_13 -> V_95 ( V_1 ) ;
if ( F_37 ( & V_88 , V_1 , V_1 -> V_96 ,
V_97 | V_98 , V_99 ) ) {
F_6 ( V_29 L_5 , V_1 -> V_30 ) ;
return V_88 ;
}
if ( V_1 -> V_59 == 0 ) {
struct V_100 * V_101 ;
if ( V_1 -> V_102 == 0xff )
F_38 ( V_1 , V_1 -> V_103 ) ;
if ( F_8 ( V_3 ) )
return F_27 ( V_1 , V_3 ) ;
else if ( F_35 ( V_3 ) ) {
struct V_104 * V_105 = V_3 -> V_33 ;
#ifdef F_39
F_6 ( L_6 ,
V_1 -> V_30 , V_105 -> V_106 ) ;
#endif
V_88 = F_40 ( V_1 , V_3 ) ;
if ( V_88 == V_61 &&
V_105 -> V_106 == V_107 )
F_41 ( V_1 , V_3 ) ;
return V_88 ;
} else if ( ! V_3 -> V_37 && F_14 ( V_3 ) )
return F_28 ( V_1 , V_3 ) ;
V_101 = * (struct V_100 * * ) V_3 -> V_37 -> V_108 ;
return V_101 -> V_109 ( V_1 , V_3 , F_42 ( V_3 ) ) ;
}
return F_20 ( V_1 ) ;
V_94:
F_13 ( V_1 , V_3 ) ;
return V_61 ;
}
void F_43 ( T_1 * V_1 , unsigned long V_110 )
{
if ( V_110 > V_111 )
V_110 = V_111 ;
V_1 -> V_112 = V_110 + V_113 ;
V_1 -> V_5 |= V_114 ;
}
static inline int F_44 ( T_3 * V_14 )
{
if ( V_14 -> V_115 )
return 1 ;
V_14 -> V_115 = 1 ;
return 0 ;
}
static inline void F_45 ( T_3 * V_14 )
{
V_14 -> V_115 = 0 ;
}
static inline int F_46 ( struct V_116 * V_117 , T_3 * V_14 )
{
int V_35 = 0 ;
if ( V_117 -> V_118 & V_119 ) {
V_35 = F_47 ( V_120 , & V_117 -> V_121 ) ;
if ( V_35 == 0 ) {
if ( V_117 -> V_122 )
V_117 -> V_122 ( V_123 , V_14 ) ;
}
}
return V_35 ;
}
static inline void F_48 ( struct V_116 * V_117 )
{
if ( V_117 -> V_118 & V_119 ) {
if ( V_117 -> V_124 )
V_117 -> V_124 () ;
F_49 ( V_120 , & V_117 -> V_121 ) ;
}
}
static void F_50 ( struct V_125 * V_126 , struct V_2 * V_3 )
{
if ( V_3 )
F_51 ( V_126 , V_3 ) ;
if ( V_3 || F_52 ( V_126 ) ) {
F_53 ( V_126 , 3 ) ;
}
}
void F_54 ( T_1 * V_1 , struct V_2 * V_3 )
{
struct V_125 * V_126 = V_1 -> V_78 ;
unsigned long V_127 ;
F_55 ( V_126 -> V_128 , V_127 ) ;
F_50 ( V_126 , V_3 ) ;
F_56 ( V_126 -> V_128 , V_127 ) ;
}
void F_57 ( struct V_125 * V_126 )
{
T_1 * V_1 = V_126 -> V_129 ;
T_3 * V_14 = V_1 -> V_14 ;
struct V_116 * V_117 = V_14 -> V_117 ;
struct V_2 * V_3 = NULL ;
T_4 V_88 ;
unsigned long V_130 = 3 ;
F_58 ( V_126 -> V_128 ) ;
F_59 () ;
if ( F_46 ( V_117 , V_14 ) )
goto V_131;
F_60 ( & V_14 -> V_132 ) ;
if ( ! F_44 ( V_14 ) ) {
T_3 * V_133 ;
F_61 ( V_14 -> V_3 ) ;
V_134:
V_133 = V_14 -> V_117 -> V_135 ;
if ( V_1 -> V_5 & V_114 &&
F_62 ( V_1 -> V_112 , V_113 ) ) {
unsigned long V_136 = V_113 - V_1 -> V_112 ;
V_130 = F_63 ( V_136 + 1 ) ;
F_45 ( V_14 ) ;
goto V_137;
}
if ( ( V_14 -> V_117 -> V_118 & V_119 ) &&
V_14 != V_133 ) {
T_1 * V_138 =
V_133 ? V_133 -> V_138 : NULL ;
if ( V_138 &&
( V_138 -> V_5 & V_139 ) == 0 )
V_133 -> V_13 -> V_140 ( V_133 ,
V_141 |
V_142 ) ;
V_14 -> V_117 -> V_135 = V_14 ;
}
V_14 -> V_138 = V_1 ;
V_1 -> V_5 &= ~ ( V_114 | V_31 ) ;
F_58 ( & V_14 -> V_132 ) ;
F_60 ( V_126 -> V_128 ) ;
if ( ! V_3 )
V_3 = F_64 ( V_1 -> V_78 ) ;
F_58 ( V_126 -> V_128 ) ;
F_60 ( & V_14 -> V_132 ) ;
if ( ! V_3 ) {
F_45 ( V_14 ) ;
goto V_68;
}
if ( ( V_1 -> V_5 & V_143 ) &&
F_35 ( V_3 ) == 0 &&
( V_3 -> V_89 & V_144 ) == 0 ) {
F_45 ( V_14 ) ;
goto V_137;
}
F_29 ( V_3 ) -> V_145 = F_16 ( V_3 ) ;
V_14 -> V_3 = V_3 ;
F_58 ( & V_14 -> V_132 ) ;
V_88 = F_33 ( V_1 , V_3 ) ;
F_60 ( & V_14 -> V_132 ) ;
if ( V_88 == V_61 ) {
V_3 = V_14 -> V_3 ;
V_14 -> V_3 = NULL ;
goto V_134;
}
} else
goto V_137;
V_68:
F_58 ( & V_14 -> V_132 ) ;
if ( V_3 == NULL )
F_48 ( V_117 ) ;
F_60 ( V_126 -> V_128 ) ;
return;
V_137:
F_58 ( & V_14 -> V_132 ) ;
F_48 ( V_117 ) ;
V_131:
F_60 ( V_126 -> V_128 ) ;
F_50 ( V_126 , V_3 ) ;
}
static int F_65 ( T_1 * V_1 )
{
T_3 * V_14 = V_1 -> V_14 ;
T_2 V_10 = 0 ;
if ( V_1 -> V_146 )
return V_14 -> V_147 -> V_148 ( V_1 ) ;
if ( V_14 -> V_149 . V_150 &&
( V_14 -> V_118 & V_151 ) == 0 )
V_10 = V_14 -> V_13 -> V_152 ( V_14 ) ;
else
V_10 = V_14 -> V_13 -> V_153 ( V_14 ) ;
if ( V_10 & V_97 )
return 0 ;
return 1 ;
}
void F_66 ( unsigned long V_22 )
{
T_3 * V_14 = ( T_3 * ) V_22 ;
T_1 * V_154 ( V_1 ) ;
T_5 * V_155 ;
unsigned long V_127 ;
int V_156 = - 1 ;
int V_137 = 0 ;
struct V_2 * V_154 ( V_157 ) ;
F_55 ( & V_14 -> V_132 , V_127 ) ;
V_155 = V_14 -> V_155 ;
if ( V_155 == NULL || V_14 -> V_158 != V_14 -> V_159 ) {
} else {
T_6 * V_160 = V_14 -> V_160 ;
T_4 V_88 = V_61 ;
V_1 = V_14 -> V_138 ;
if ( V_160 ) {
V_156 = V_160 ( V_1 ) ;
if ( V_156 > 0 ) {
V_14 -> V_161 . V_162 = V_113 + V_156 ;
V_14 -> V_159 = V_14 -> V_158 ;
F_67 ( & V_14 -> V_161 ) ;
F_56 ( & V_14 -> V_132 , V_127 ) ;
return;
}
}
V_14 -> V_155 = NULL ;
V_14 -> V_160 = NULL ;
F_68 ( & V_14 -> V_132 ) ;
F_69 ( V_14 -> V_163 ) ;
F_70 () ;
if ( V_14 -> V_164 ) {
V_88 = V_155 ( V_1 ) ;
} else if ( F_65 ( V_1 ) ) {
if ( V_1 -> V_146 )
V_14 -> V_147 -> V_165 ( V_1 ) ;
if ( V_14 -> V_166 && V_14 -> V_166 -> V_167 )
V_14 -> V_166 -> V_167 ( V_1 ) ;
F_6 ( V_168 L_7 ,
V_1 -> V_30 ) ;
V_88 = V_155 ( V_1 ) ;
} else {
if ( V_1 -> V_146 )
V_88 = F_71 ( V_1 , V_156 ) ;
else
V_88 = F_72 ( V_1 , L_8 ,
V_14 -> V_13 -> V_153 ( V_14 ) ) ;
}
F_60 ( & V_14 -> V_132 ) ;
F_73 ( V_14 -> V_163 ) ;
if ( V_88 == V_61 && V_14 -> V_164 == 0 ) {
V_157 = V_14 -> V_3 ;
V_14 -> V_3 = NULL ;
F_45 ( V_14 ) ;
V_137 = 1 ;
}
}
F_56 ( & V_14 -> V_132 , V_127 ) ;
if ( V_137 ) {
F_48 ( V_14 -> V_117 ) ;
F_54 ( V_1 , V_157 ) ;
}
}
static void F_74 ( int V_163 , T_3 * V_14 )
{
T_2 V_10 = V_14 -> V_13 -> V_153 ( V_14 ) ;
if ( ! F_75 ( V_10 , V_169 , V_170 ) ) {
static unsigned long V_171 , V_172 ;
++ V_172 ;
if ( F_62 ( V_113 , V_171 + V_173 ) ) {
V_171 = V_113 ;
F_6 ( V_29 L_9
L_10 ,
V_14 -> V_30 , V_10 , V_172 ) ;
}
}
}
T_7 V_123 ( int V_163 , void * V_174 )
{
T_3 * V_14 = ( T_3 * ) V_174 ;
struct V_116 * V_117 = V_14 -> V_117 ;
T_1 * V_154 ( V_1 ) ;
T_5 * V_155 ;
unsigned long V_127 ;
T_4 V_88 ;
T_7 V_175 = V_176 ;
int V_137 = 0 ;
struct V_2 * V_154 ( V_157 ) ;
if ( V_117 -> V_118 & V_119 ) {
if ( V_14 != V_117 -> V_135 )
goto V_177;
}
F_55 ( & V_14 -> V_132 , V_127 ) ;
if ( V_14 -> V_166 && V_14 -> V_166 -> V_178 &&
V_14 -> V_166 -> V_178 ( V_14 ) == 0 )
goto V_68;
V_155 = V_14 -> V_155 ;
if ( V_155 == NULL || V_14 -> V_164 ) {
if ( ( V_117 -> V_179 & V_180 ) == 0 ) {
F_74 ( V_163 , V_14 ) ;
} else {
( void ) V_14 -> V_13 -> V_153 ( V_14 ) ;
}
goto V_68;
}
V_1 = V_14 -> V_138 ;
if ( ! F_65 ( V_1 ) )
goto V_68;
V_14 -> V_155 = NULL ;
V_14 -> V_160 = NULL ;
V_14 -> V_158 ++ ;
F_76 ( & V_14 -> V_161 ) ;
F_68 ( & V_14 -> V_132 ) ;
if ( V_14 -> V_166 && V_14 -> V_166 -> V_167 )
V_14 -> V_166 -> V_167 ( V_1 ) ;
if ( V_1 -> V_5 & V_181 )
F_77 () ;
V_88 = V_155 ( V_1 ) ;
F_60 ( & V_14 -> V_132 ) ;
if ( V_88 == V_61 && V_14 -> V_164 == 0 ) {
F_34 ( V_14 -> V_155 ) ;
V_157 = V_14 -> V_3 ;
V_14 -> V_3 = NULL ;
F_45 ( V_14 ) ;
V_137 = 1 ;
}
V_175 = V_182 ;
V_68:
F_56 ( & V_14 -> V_132 , V_127 ) ;
V_177:
if ( V_137 ) {
F_48 ( V_14 -> V_117 ) ;
F_54 ( V_1 , V_157 ) ;
}
return V_175 ;
}
void F_78 ( T_1 * V_1 , int V_183 , int V_184 )
{
T_3 * V_14 = V_1 -> V_14 ;
T_2 V_185 [ 4 ] = { 0 } ;
while ( V_184 > 0 ) {
if ( V_183 )
V_14 -> V_13 -> V_186 ( V_1 , NULL , V_185 , F_79 ( 4 , V_184 ) ) ;
else
V_14 -> V_13 -> V_23 ( V_1 , NULL , V_185 , F_79 ( 4 , V_184 ) ) ;
V_184 -= 4 ;
}
}
