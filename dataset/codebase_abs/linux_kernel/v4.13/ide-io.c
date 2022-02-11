int F_1 ( T_1 * V_1 , struct V_2 * V_3 , T_2 error ,
unsigned int V_4 )
{
if ( ( V_1 -> V_5 & V_6 ) &&
V_1 -> V_7 <= 3 ) {
V_1 -> V_5 &= ~ V_6 ;
F_2 ( V_1 ) ;
}
return F_3 ( V_3 , error , V_4 ) ;
}
void F_4 ( T_1 * V_1 , struct V_8 * V_9 , T_3 V_10 , T_3 V_11 )
{
const struct V_12 * V_13 = V_1 -> V_14 -> V_13 ;
struct V_15 * V_16 = & V_9 -> V_16 ;
struct V_2 * V_3 = V_9 -> V_3 ;
T_3 V_17 = V_16 -> V_18 ;
V_16 -> error = V_11 ;
V_16 -> V_19 = V_10 ;
if ( V_9 -> V_20 & V_21 ) {
T_3 V_22 [ 2 ] ;
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
else if ( V_9 != V_32 )
memcpy ( V_32 , V_9 , sizeof( * V_9 ) ) ;
}
}
int F_10 ( T_1 * V_1 , T_2 error , unsigned int V_4 )
{
T_4 * V_14 = V_1 -> V_14 ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_35 ;
if ( F_11 ( V_3 ) && error )
V_4 = F_12 ( V_3 ) << 9 ;
V_35 = F_1 ( V_1 , V_3 , error , V_4 ) ;
if ( V_35 == 0 )
V_14 -> V_3 = NULL ;
return V_35 ;
}
void F_13 ( T_1 * V_1 , struct V_2 * V_3 )
{
T_3 V_36 = F_14 ( V_3 ) && V_3 -> V_37 ;
T_3 V_38 = V_1 -> V_38 ;
V_1 -> V_39 = NULL ;
if ( ( V_38 == V_40 || V_38 == V_41 ) && V_36 ) {
F_15 ( V_3 ) -> V_42 = 0 ;
} else {
if ( V_38 == V_41 )
F_15 ( V_3 ) -> V_42 = V_43 ;
else if ( F_16 ( V_3 ) && F_15 ( V_3 ) -> V_42 == 0 )
F_15 ( V_3 ) -> V_42 = - V_44 ;
}
F_10 ( V_1 , V_45 , F_17 ( V_3 ) ) ;
}
static void F_18 ( T_1 * V_1 , struct V_15 * V_16 )
{
V_16 -> V_46 = V_1 -> V_47 ;
V_16 -> V_28 = V_1 -> V_47 ;
V_16 -> V_48 = V_1 -> V_49 ;
V_16 -> V_50 = V_1 -> V_49 >> 8 ;
V_16 -> V_51 = ( V_1 -> V_52 - 1 ) | V_1 -> V_53 ;
V_16 -> V_18 = V_54 ;
}
static void F_19 ( T_1 * V_1 , struct V_15 * V_16 )
{
V_16 -> V_46 = V_1 -> V_47 ;
V_16 -> V_18 = V_55 ;
}
static void F_20 ( T_1 * V_1 , struct V_15 * V_16 )
{
V_16 -> V_46 = V_1 -> V_56 ;
V_16 -> V_18 = V_57 ;
}
static T_5 F_21 ( T_1 * V_1 )
{
struct V_8 V_9 ;
#ifdef F_22
F_6 ( V_58 L_2 , V_1 -> V_30 , V_59 ,
V_1 -> V_60 ) ;
#endif
if ( V_1 -> V_38 != V_61 ) {
V_1 -> V_60 = 0 ;
V_1 -> V_56 = 0 ;
return V_62 ;
}
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_63 = V_64 ;
if ( V_1 -> V_60 & V_65 ) {
V_1 -> V_60 &= ~ V_65 ;
F_18 ( V_1 , & V_9 . V_16 ) ;
} else if ( V_1 -> V_60 & V_66 ) {
V_1 -> V_60 &= ~ V_66 ;
F_19 ( V_1 , & V_9 . V_16 ) ;
} else if ( V_1 -> V_60 & V_67 ) {
V_1 -> V_60 &= ~ V_67 ;
F_20 ( V_1 , & V_9 . V_16 ) ;
} else
F_23 () ;
V_9 . V_68 . V_69 . V_16 = V_70 | V_71 ;
V_9 . V_68 . V_72 . V_16 = V_73 | V_71 ;
V_9 . V_25 = V_26 ;
F_24 ( V_1 , & V_9 ) ;
return V_74 ;
}
void F_25 ( T_1 * V_1 , struct V_8 * V_9 )
{
T_4 * V_14 = V_1 -> V_14 ;
struct V_75 * V_76 = V_14 -> V_77 ;
struct V_2 * V_3 = V_9 -> V_3 ;
V_9 -> V_78 = F_26 ( V_1 -> V_79 , V_3 , V_76 ) ;
}
void F_27 ( struct V_8 * V_9 , unsigned int V_4 )
{
V_9 -> V_80 = V_9 -> V_81 = V_4 ;
V_9 -> V_82 = 0 ;
V_9 -> V_83 = NULL ;
}
static T_5 F_28 ( T_1 * V_1 ,
struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_33 ;
if ( V_9 ) {
if ( V_9 -> V_63 == V_84 ) {
F_27 ( V_9 , F_12 ( V_3 ) << 9 ) ;
F_25 ( V_1 , V_9 ) ;
}
return F_24 ( V_1 , V_9 ) ;
}
#ifdef F_22
F_6 ( L_3 , V_1 -> V_30 ) ;
#endif
F_15 ( V_3 ) -> V_42 = 0 ;
F_10 ( V_1 , V_85 , F_17 ( V_3 ) ) ;
return V_62 ;
}
static T_5 F_29 ( T_1 * V_1 , struct V_2 * V_3 )
{
T_3 V_9 = F_15 ( V_3 ) -> V_9 [ 0 ] ;
switch ( V_9 ) {
case V_86 :
case V_87 :
return F_30 ( V_1 , V_3 ) ;
case V_88 :
return F_31 ( V_1 , V_3 ) ;
case V_89 :
return F_32 ( V_1 ) ;
default:
F_23 () ;
}
}
static T_5 F_33 ( T_1 * V_1 , struct V_2 * V_3 )
{
T_5 V_90 ;
F_34 ( ! ( V_3 -> V_91 & V_92 ) ) ;
#ifdef F_22
F_6 ( L_4 ,
V_1 -> V_14 -> V_30 , ( unsigned long ) V_3 ) ;
#endif
if ( V_1 -> V_93 && ( V_1 -> V_94 > V_1 -> V_93 ) ) {
V_3 -> V_91 |= V_95 ;
goto V_96;
}
if ( F_35 ( V_3 ) )
F_36 ( V_1 , V_3 ) ;
V_1 -> V_14 -> V_13 -> V_97 ( V_1 ) ;
if ( F_37 ( & V_90 , V_1 , V_1 -> V_98 ,
V_99 | V_100 , V_101 ) ) {
F_6 ( V_29 L_5 , V_1 -> V_30 ) ;
return V_90 ;
}
if ( V_1 -> V_60 == 0 ) {
struct V_102 * V_103 ;
if ( V_1 -> V_104 == 0xff )
F_38 ( V_1 , V_1 -> V_105 ) ;
if ( F_8 ( V_3 ) )
return F_28 ( V_1 , V_3 ) ;
else if ( F_35 ( V_3 ) ) {
struct V_106 * V_107 = V_3 -> V_33 ;
#ifdef F_39
F_6 ( L_6 ,
V_1 -> V_30 , V_107 -> V_108 ) ;
#endif
V_90 = F_40 ( V_1 , V_3 ) ;
if ( V_90 == V_62 &&
V_107 -> V_108 == V_109 )
F_41 ( V_1 , V_3 ) ;
return V_90 ;
} else if ( ! V_3 -> V_37 && F_14 ( V_3 ) )
return F_29 ( V_1 , V_3 ) ;
V_103 = * (struct V_102 * * ) V_3 -> V_37 -> V_110 ;
return V_103 -> V_111 ( V_1 , V_3 , F_42 ( V_3 ) ) ;
}
return F_21 ( V_1 ) ;
V_96:
F_13 ( V_1 , V_3 ) ;
return V_62 ;
}
void F_43 ( T_1 * V_1 , unsigned long V_112 )
{
if ( V_112 > V_113 )
V_112 = V_113 ;
V_1 -> V_114 = V_112 + V_115 ;
V_1 -> V_5 |= V_116 ;
}
static inline int F_44 ( T_4 * V_14 )
{
if ( V_14 -> V_117 )
return 1 ;
V_14 -> V_117 = 1 ;
return 0 ;
}
static inline void F_45 ( T_4 * V_14 )
{
V_14 -> V_117 = 0 ;
}
static inline int F_46 ( struct V_118 * V_119 , T_4 * V_14 )
{
int V_35 = 0 ;
if ( V_119 -> V_120 & V_121 ) {
V_35 = F_47 ( V_122 , & V_119 -> V_123 ) ;
if ( V_35 == 0 ) {
if ( V_119 -> V_124 )
V_119 -> V_124 ( V_125 , V_14 ) ;
}
}
return V_35 ;
}
static inline void F_48 ( struct V_118 * V_119 )
{
if ( V_119 -> V_120 & V_121 ) {
if ( V_119 -> V_126 )
V_119 -> V_126 () ;
F_49 ( V_122 , & V_119 -> V_123 ) ;
}
}
static void F_50 ( struct V_127 * V_128 , struct V_2 * V_3 )
{
if ( V_3 )
F_51 ( V_128 , V_3 ) ;
if ( V_3 || F_52 ( V_128 ) ) {
F_53 ( V_128 , 3 ) ;
}
}
void F_54 ( T_1 * V_1 , struct V_2 * V_3 )
{
struct V_127 * V_128 = V_1 -> V_79 ;
unsigned long V_129 ;
F_55 ( V_128 -> V_130 , V_129 ) ;
F_50 ( V_128 , V_3 ) ;
F_56 ( V_128 -> V_130 , V_129 ) ;
}
void F_57 ( struct V_127 * V_128 )
{
T_1 * V_1 = V_128 -> V_131 ;
T_4 * V_14 = V_1 -> V_14 ;
struct V_118 * V_119 = V_14 -> V_119 ;
struct V_2 * V_3 = NULL ;
T_5 V_90 ;
unsigned long V_132 = 3 ;
F_58 ( V_128 -> V_130 ) ;
F_59 () ;
if ( F_46 ( V_119 , V_14 ) )
goto V_133;
F_60 ( & V_14 -> V_134 ) ;
if ( ! F_44 ( V_14 ) ) {
T_4 * V_135 ;
F_61 ( V_14 -> V_3 ) ;
V_136:
V_135 = V_14 -> V_119 -> V_137 ;
if ( V_1 -> V_5 & V_116 &&
F_62 ( V_1 -> V_114 , V_115 ) ) {
unsigned long V_138 = V_115 - V_1 -> V_114 ;
V_132 = F_63 ( V_138 + 1 ) ;
F_45 ( V_14 ) ;
goto V_139;
}
if ( ( V_14 -> V_119 -> V_120 & V_121 ) &&
V_14 != V_135 ) {
T_1 * V_140 =
V_135 ? V_135 -> V_140 : NULL ;
if ( V_140 &&
( V_140 -> V_5 & V_141 ) == 0 )
V_135 -> V_13 -> V_142 ( V_135 ,
V_143 |
V_144 ) ;
V_14 -> V_119 -> V_137 = V_14 ;
}
V_14 -> V_140 = V_1 ;
V_1 -> V_5 &= ~ ( V_116 | V_31 ) ;
F_58 ( & V_14 -> V_134 ) ;
F_60 ( V_128 -> V_130 ) ;
if ( ! V_3 )
V_3 = F_64 ( V_1 -> V_79 ) ;
F_58 ( V_128 -> V_130 ) ;
F_60 ( & V_14 -> V_134 ) ;
if ( ! V_3 ) {
F_45 ( V_14 ) ;
goto V_69;
}
if ( ( V_1 -> V_5 & V_145 ) &&
F_35 ( V_3 ) == 0 &&
( V_3 -> V_91 & V_146 ) == 0 ) {
F_45 ( V_14 ) ;
goto V_139;
}
F_15 ( V_3 ) -> V_147 = F_17 ( V_3 ) ;
V_14 -> V_3 = V_3 ;
F_58 ( & V_14 -> V_134 ) ;
V_90 = F_33 ( V_1 , V_3 ) ;
F_60 ( & V_14 -> V_134 ) ;
if ( V_90 == V_62 ) {
V_3 = V_14 -> V_3 ;
V_14 -> V_3 = NULL ;
goto V_136;
}
} else
goto V_139;
V_69:
F_58 ( & V_14 -> V_134 ) ;
if ( V_3 == NULL )
F_48 ( V_119 ) ;
F_60 ( V_128 -> V_130 ) ;
return;
V_139:
F_58 ( & V_14 -> V_134 ) ;
F_48 ( V_119 ) ;
V_133:
F_60 ( V_128 -> V_130 ) ;
F_50 ( V_128 , V_3 ) ;
}
static int F_65 ( T_1 * V_1 )
{
T_4 * V_14 = V_1 -> V_14 ;
T_3 V_10 = 0 ;
if ( V_1 -> V_148 )
return V_14 -> V_149 -> V_150 ( V_1 ) ;
if ( V_14 -> V_151 . V_152 &&
( V_14 -> V_120 & V_153 ) == 0 )
V_10 = V_14 -> V_13 -> V_154 ( V_14 ) ;
else
V_10 = V_14 -> V_13 -> V_155 ( V_14 ) ;
if ( V_10 & V_99 )
return 0 ;
return 1 ;
}
void F_66 ( unsigned long V_22 )
{
T_4 * V_14 = ( T_4 * ) V_22 ;
T_1 * V_156 ( V_1 ) ;
T_6 * V_157 ;
unsigned long V_129 ;
int V_158 = - 1 ;
int V_139 = 0 ;
struct V_2 * V_156 ( V_159 ) ;
F_55 ( & V_14 -> V_134 , V_129 ) ;
V_157 = V_14 -> V_157 ;
if ( V_157 == NULL || V_14 -> V_160 != V_14 -> V_161 ) {
} else {
T_7 * V_162 = V_14 -> V_162 ;
T_5 V_90 = V_62 ;
V_1 = V_14 -> V_140 ;
if ( V_162 ) {
V_158 = V_162 ( V_1 ) ;
if ( V_158 > 0 ) {
V_14 -> V_163 . V_164 = V_115 + V_158 ;
V_14 -> V_161 = V_14 -> V_160 ;
F_67 ( & V_14 -> V_163 ) ;
F_56 ( & V_14 -> V_134 , V_129 ) ;
return;
}
}
V_14 -> V_157 = NULL ;
V_14 -> V_162 = NULL ;
F_68 ( & V_14 -> V_134 ) ;
F_69 ( V_14 -> V_165 ) ;
F_70 () ;
if ( V_14 -> V_166 ) {
V_90 = V_157 ( V_1 ) ;
} else if ( F_65 ( V_1 ) ) {
if ( V_1 -> V_148 )
V_14 -> V_149 -> V_167 ( V_1 ) ;
if ( V_14 -> V_168 && V_14 -> V_168 -> V_169 )
V_14 -> V_168 -> V_169 ( V_1 ) ;
F_6 ( V_170 L_7 ,
V_1 -> V_30 ) ;
V_90 = V_157 ( V_1 ) ;
} else {
if ( V_1 -> V_148 )
V_90 = F_71 ( V_1 , V_158 ) ;
else
V_90 = F_72 ( V_1 , L_8 ,
V_14 -> V_13 -> V_155 ( V_14 ) ) ;
}
F_60 ( & V_14 -> V_134 ) ;
F_73 ( V_14 -> V_165 ) ;
if ( V_90 == V_62 && V_14 -> V_166 == 0 ) {
V_159 = V_14 -> V_3 ;
V_14 -> V_3 = NULL ;
F_45 ( V_14 ) ;
V_139 = 1 ;
}
}
F_56 ( & V_14 -> V_134 , V_129 ) ;
if ( V_139 ) {
F_48 ( V_14 -> V_119 ) ;
F_54 ( V_1 , V_159 ) ;
}
}
static void F_74 ( int V_165 , T_4 * V_14 )
{
T_3 V_10 = V_14 -> V_13 -> V_155 ( V_14 ) ;
if ( ! F_75 ( V_10 , V_171 , V_172 ) ) {
static unsigned long V_173 , V_174 ;
++ V_174 ;
if ( F_62 ( V_115 , V_173 + V_175 ) ) {
V_173 = V_115 ;
F_6 ( V_29 L_9
L_10 ,
V_14 -> V_30 , V_10 , V_174 ) ;
}
}
}
T_8 V_125 ( int V_165 , void * V_176 )
{
T_4 * V_14 = ( T_4 * ) V_176 ;
struct V_118 * V_119 = V_14 -> V_119 ;
T_1 * V_156 ( V_1 ) ;
T_6 * V_157 ;
unsigned long V_129 ;
T_5 V_90 ;
T_8 V_177 = V_178 ;
int V_139 = 0 ;
struct V_2 * V_156 ( V_159 ) ;
if ( V_119 -> V_120 & V_121 ) {
if ( V_14 != V_119 -> V_137 )
goto V_179;
}
F_55 ( & V_14 -> V_134 , V_129 ) ;
if ( V_14 -> V_168 && V_14 -> V_168 -> V_180 &&
V_14 -> V_168 -> V_180 ( V_14 ) == 0 )
goto V_69;
V_157 = V_14 -> V_157 ;
if ( V_157 == NULL || V_14 -> V_166 ) {
if ( ( V_119 -> V_181 & V_182 ) == 0 ) {
F_74 ( V_165 , V_14 ) ;
} else {
( void ) V_14 -> V_13 -> V_155 ( V_14 ) ;
}
goto V_69;
}
V_1 = V_14 -> V_140 ;
if ( ! F_65 ( V_1 ) )
goto V_69;
V_14 -> V_157 = NULL ;
V_14 -> V_162 = NULL ;
V_14 -> V_160 ++ ;
F_76 ( & V_14 -> V_163 ) ;
F_68 ( & V_14 -> V_134 ) ;
if ( V_14 -> V_168 && V_14 -> V_168 -> V_169 )
V_14 -> V_168 -> V_169 ( V_1 ) ;
if ( V_1 -> V_5 & V_183 )
F_77 () ;
V_90 = V_157 ( V_1 ) ;
F_60 ( & V_14 -> V_134 ) ;
if ( V_90 == V_62 && V_14 -> V_166 == 0 ) {
F_34 ( V_14 -> V_157 ) ;
V_159 = V_14 -> V_3 ;
V_14 -> V_3 = NULL ;
F_45 ( V_14 ) ;
V_139 = 1 ;
}
V_177 = V_184 ;
V_69:
F_56 ( & V_14 -> V_134 , V_129 ) ;
V_179:
if ( V_139 ) {
F_48 ( V_14 -> V_119 ) ;
F_54 ( V_1 , V_159 ) ;
}
return V_177 ;
}
void F_78 ( T_1 * V_1 , int V_185 , int V_186 )
{
T_4 * V_14 = V_1 -> V_14 ;
T_3 V_187 [ 4 ] = { 0 } ;
while ( V_186 > 0 ) {
if ( V_185 )
V_14 -> V_13 -> V_188 ( V_1 , NULL , V_187 , F_79 ( 4 , V_186 ) ) ;
else
V_14 -> V_13 -> V_23 ( V_1 , NULL , V_187 , F_79 ( 4 , V_186 ) ) ;
V_186 -= 4 ;
}
}
