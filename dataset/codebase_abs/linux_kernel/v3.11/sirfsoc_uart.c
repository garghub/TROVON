static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline unsigned int F_3 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
V_4 = F_4 ( V_3 , V_5 ) ;
if ( V_4 & F_5 ( V_3 ) )
return V_6 ;
else
return 0 ;
}
static unsigned int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( ! ( V_7 -> V_8 ) ) {
goto V_9;
} else if ( V_7 -> V_10 ) {
if ( ! ( F_4 ( V_3 , V_11 ) &
V_12 ) )
goto V_9;
else
goto V_13;
}
V_13:
return V_14 | V_15 ;
V_9:
return V_14 | V_15 | V_16 ;
}
static void F_7 ( struct V_2 * V_3 , unsigned int V_17 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int assert = V_17 & V_18 ;
unsigned int V_19 = assert ? V_20 : 0x0 ;
unsigned int V_21 ;
if ( V_7 -> V_10 ) {
V_21 = F_4 ( V_3 , V_11 ) & ~ 0xFF ;
V_19 |= V_21 ;
F_8 ( V_3 , V_11 , V_19 ) ;
}
}
static void F_9 ( struct V_2 * V_3 )
{
unsigned int V_22 ;
V_22 = F_4 ( V_3 , V_23 ) ;
F_8 ( V_3 , V_23 , V_22 & ~ V_24 ) ;
}
void F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_22 ;
F_11 ( V_7 , 1 ) ;
F_8 ( V_3 , V_25 , V_26 ) ;
V_22 = F_4 ( V_3 , V_23 ) ;
F_8 ( V_3 , V_23 , V_22 | V_24 ) ;
}
static void F_12 ( struct V_2 * V_3 )
{
unsigned long V_22 ;
F_8 ( V_3 , V_27 , 0 ) ;
V_22 = F_4 ( V_3 , V_23 ) ;
F_8 ( V_3 , V_23 , V_22 & ~ V_28 ) ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_4 ;
V_7 -> V_8 = 0 ;
if ( ! V_7 -> V_10 )
return;
V_4 = F_4 ( V_3 , V_11 ) ;
F_8 ( V_3 , V_11 , V_4 & ~ 0x3FF ) ;
V_4 = F_4 ( V_3 , V_23 ) ;
F_8 ( V_3 , V_23 , V_4 & ~ V_29 ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_4 ;
unsigned long V_30 ;
if ( ! V_7 -> V_10 )
return;
V_30 = V_31 | V_32 ;
V_4 = F_4 ( V_3 , V_11 ) ;
F_8 ( V_3 , V_11 , V_4 | V_30 ) ;
V_4 = F_4 ( V_3 , V_23 ) ;
F_8 ( V_3 , V_23 , V_4 | V_29 ) ;
F_15 ( V_3 ,
! ( F_4 ( V_3 , V_11 ) & V_12 ) ) ;
V_7 -> V_8 = 1 ;
}
static void F_16 ( struct V_2 * V_3 , int V_33 )
{
unsigned long V_34 = F_4 ( V_3 , V_35 ) ;
if ( V_33 )
V_34 |= V_36 ;
else
V_34 &= ~ V_36 ;
F_8 ( V_3 , V_35 , V_34 ) ;
}
static unsigned int
F_17 ( struct V_2 * V_3 , unsigned int V_37 )
{
unsigned int V_38 , V_39 = 0 ;
while ( ! ( F_4 ( V_3 , V_40 ) &
F_5 ( V_3 ) ) ) {
V_38 = F_4 ( V_3 , V_41 ) | V_42 ;
if ( F_18 ( F_19 ( V_3 , V_38 ) ) )
continue;
F_20 ( V_3 , 0 , 0 , V_38 , V_43 ) ;
V_39 ++ ;
if ( V_39 >= V_37 )
break;
}
V_3 -> V_44 . V_45 += V_39 ;
F_21 ( & V_3 -> V_46 -> V_3 ) ;
return V_39 ;
}
static unsigned int
F_11 ( struct V_1 * V_7 , int V_47 )
{
struct V_2 * V_3 = & V_7 -> V_3 ;
struct V_48 * V_49 = & V_3 -> V_46 -> V_49 ;
unsigned int V_50 = 0 ;
while ( ! F_22 ( V_49 ) &&
! ( F_4 ( V_3 , V_5 ) &
F_23 ( V_3 ) ) &&
V_47 -- ) {
F_8 ( V_3 , V_51 , V_49 -> V_52 [ V_49 -> V_53 ] ) ;
V_49 -> V_53 = ( V_49 -> V_53 + 1 ) & ( V_54 - 1 ) ;
V_3 -> V_44 . V_55 ++ ;
V_50 ++ ;
}
if ( F_24 ( V_49 ) < V_56 )
F_25 ( V_3 ) ;
return V_50 ;
}
static T_1 F_26 ( int V_57 , void * V_58 )
{
unsigned long V_59 ;
unsigned long V_60 ;
unsigned long V_61 = V_43 ;
struct V_1 * V_7 = (struct V_1 * ) V_58 ;
struct V_2 * V_3 = & V_7 -> V_3 ;
struct V_62 * V_46 = V_3 -> V_46 ;
struct V_48 * V_49 = & V_3 -> V_46 -> V_49 ;
F_27 ( & V_3 -> V_63 ) ;
V_59 = F_4 ( V_3 , V_64 ) ;
F_8 ( V_3 , V_64 , V_59 ) ;
V_59 &= F_4 ( V_3 , V_23 ) ;
if ( F_18 ( V_59 & ( V_65 ) ) ) {
if ( V_59 & V_66 ) {
if ( F_28 ( V_3 ) )
goto V_67;
F_20 ( V_3 , V_59 ,
V_68 , 0 , V_69 ) ;
F_29 ( & V_3 -> V_63 ) ;
return V_70 ;
}
if ( V_59 & V_68 )
V_3 -> V_44 . V_71 ++ ;
if ( V_59 & V_72 ) {
V_3 -> V_44 . V_73 ++ ;
V_61 = V_74 ;
}
if ( V_59 & V_75 )
V_61 = V_76 ;
F_8 ( V_3 , V_27 , V_77 ) ;
F_8 ( V_3 , V_27 , 0 ) ;
F_8 ( V_3 , V_27 , V_78 ) ;
V_59 &= V_3 -> V_79 ;
F_20 ( V_3 , V_59 ,
V_80 , 0 , V_61 ) ;
}
V_67:
if ( V_59 & V_29 ) {
V_60 = ! ( F_4 ( V_3 , V_11 ) &
V_12 ) ;
if ( V_60 != 0 ) {
F_15 ( V_3 , 1 ) ;
} else {
F_15 ( V_3 , 0 ) ;
F_30 ( & V_46 -> V_3 . V_81 ) ;
}
}
if ( V_59 & V_28 )
F_17 ( V_3 , V_82 ) ;
if ( V_59 & V_24 ) {
if ( F_22 ( V_49 ) || F_31 ( V_3 ) ) {
F_29 ( & V_3 -> V_63 ) ;
return V_70 ;
} else {
F_11 ( V_7 ,
V_83 ) ;
if ( ( F_22 ( V_49 ) ) &&
( F_4 ( V_3 , V_5 ) &
F_5 ( V_3 ) ) )
F_9 ( V_3 ) ;
}
}
F_29 ( & V_3 -> V_63 ) ;
return V_70 ;
}
static void F_32 ( struct V_2 * V_3 )
{
unsigned long V_22 ;
V_22 = F_4 ( V_3 , V_23 ) ;
F_8 ( V_3 , V_23 , V_22 | V_28 ) ;
F_8 ( V_3 , V_27 , V_77 ) ;
F_8 ( V_3 , V_27 , 0 ) ;
F_8 ( V_3 , V_27 , V_78 ) ;
}
static unsigned int
F_33 ( unsigned long V_84 ,
unsigned long V_85 , unsigned long * V_86 )
{
unsigned long V_87 = ~ 0UL ;
unsigned short V_88 ;
unsigned int V_22 = 0 ;
unsigned long V_89 ;
unsigned long V_90 ;
int V_91 ;
for ( V_88 = V_92 ;
V_88 <= V_93 ; V_88 ++ ) {
V_89 = ( V_85 / ( V_84 * ( V_88 + 1 ) ) ) - 1 ;
if ( V_89 > V_94 )
continue;
V_90 = V_85 / ( ( V_89 + 1 ) * ( V_88 + 1 ) ) ;
V_91 = V_90 - V_84 ;
V_91 = ( V_91 > 0 ) ? V_91 : - V_91 ;
if ( V_91 < V_87 ) {
V_22 = V_22 & ( ~ V_95 ) ;
V_22 = V_22 | V_89 ;
V_22 = V_22 & ( ~ V_96 ) ;
V_22 = V_22 | ( V_88 << V_97 ) ;
V_87 = V_91 ;
* V_86 = V_90 ;
}
}
return V_22 ;
}
static void F_34 ( struct V_2 * V_3 ,
struct V_98 * V_99 ,
struct V_98 * V_100 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_101 = 0 ;
unsigned long V_84 ;
unsigned long V_86 ;
unsigned long V_102 ;
unsigned long V_103 ;
unsigned int V_104 = 0 ;
unsigned long V_105 ;
unsigned long V_106 ;
int V_107 ;
int V_108 ;
switch ( V_99 -> V_109 & V_110 ) {
default:
case V_111 :
V_101 |= V_112 ;
break;
case V_113 :
V_101 |= V_114 ;
break;
case V_115 :
V_101 |= V_116 ;
break;
case V_117 :
V_101 |= V_118 ;
break;
}
if ( V_99 -> V_109 & V_119 )
V_101 |= V_120 ;
V_84 = F_35 ( V_3 , V_99 , V_100 , 0 , 4000000 ) ;
F_36 ( & V_3 -> V_63 , V_102 ) ;
V_3 -> V_79 = V_80 ;
V_3 -> V_121 = 0 ;
if ( V_99 -> V_122 & V_123 )
V_3 -> V_79 |=
V_124 | V_125 ;
if ( V_99 -> V_122 & ( V_126 | V_127 ) )
V_3 -> V_79 |= V_128 ;
if ( V_99 -> V_122 & V_129 )
V_3 -> V_121 |=
V_124 | V_125 ;
if ( ( V_99 -> V_109 & V_130 ) == 0 )
V_3 -> V_121 |= V_42 ;
if ( V_99 -> V_109 & V_131 ) {
if ( V_99 -> V_109 & V_132 ) {
if ( V_99 -> V_109 & V_133 )
V_101 |= V_134 ;
else
V_101 |= V_135 ;
} else if ( V_99 -> V_109 & V_133 ) {
V_101 |= V_136 ;
} else {
V_101 |= V_137 ;
}
}
if ( F_37 ( V_3 , V_99 -> V_109 ) ) {
if ( ! V_7 -> V_8 )
F_14 ( V_3 ) ;
} else {
if ( V_7 -> V_8 )
F_13 ( V_3 ) ;
}
if ( V_3 -> V_138 == 150000000 ) {
for ( V_103 = 0 ; V_103 < V_139 ; V_103 ++ )
if ( V_84 == V_140 [ V_103 ] . V_84 )
V_104 = V_140 [ V_103 ] . V_141 ;
}
V_86 = V_84 ;
if ( F_18 ( V_104 == 0 ) )
V_104 = F_33 ( V_84 , V_3 -> V_138 ,
& V_86 ) ;
F_8 ( V_3 , V_142 , V_104 ) ;
if ( F_38 ( V_99 ) )
F_39 ( V_99 , V_86 , V_86 ) ;
V_106 = F_40 ( V_84 , 20000 ) ;
V_106 = ( V_106 > 0xFFFF ) ? 0xFFFF : V_106 ;
V_101 |= F_41 ( V_106 ) ;
V_105 = F_4 ( V_3 , V_25 ) ;
F_8 ( V_3 , V_27 , 0 ) ;
F_8 ( V_3 , V_25 ,
V_105 & ~ V_26 ) ;
F_8 ( V_3 , V_143 , V_144 ) ;
F_8 ( V_3 , V_145 , V_146 ) ;
F_8 ( V_3 , V_35 , V_101 ) ;
if ( V_84 < 1000000 )
V_107 = 1 ;
else
V_107 = 2 ;
V_108 = V_3 -> line == 1 ? 16 : 64 ;
F_8 ( V_3 , V_147 , V_108 / V_107 ) ;
F_8 ( V_3 , V_148 , V_108 / V_107 ) ;
V_105 |= V_26 ;
F_8 ( V_3 , V_25 , V_105 ) ;
F_42 ( V_3 , V_99 -> V_109 , V_84 ) ;
F_32 ( V_3 ) ;
F_8 ( V_3 , V_149 , V_150 | V_151 ) ;
F_43 ( & V_3 -> V_63 , V_102 ) ;
}
static void F_44 ( struct V_2 * V_3 )
{
unsigned long V_152 ;
int V_108 ;
V_152 = F_4 ( V_3 , V_143 ) ;
F_8 ( V_3 , V_143 , V_152 | V_144 ) ;
V_152 = F_4 ( V_3 , V_145 ) ;
F_8 ( V_3 , V_145 , V_152 | V_146 ) ;
F_8 ( V_3 , V_153 , 0 ) ;
F_8 ( V_3 , V_154 , 0 ) ;
F_8 ( V_3 , V_149 , V_151 | V_150 ) ;
F_8 ( V_3 , V_25 , V_155 ) ;
F_8 ( V_3 , V_25 , 0 ) ;
F_8 ( V_3 , V_27 , V_77 ) ;
F_8 ( V_3 , V_27 , 0 ) ;
V_108 = V_3 -> line == 1 ? 16 : 64 ;
F_8 ( V_3 , V_147 , V_108 ) ;
F_8 ( V_3 , V_148 , V_108 ) ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_156 = V_3 -> line ;
int V_157 ;
F_46 ( V_3 -> V_57 , V_158 | V_159 ) ;
V_157 = F_47 ( V_3 -> V_57 ,
F_26 ,
0 ,
V_160 ,
V_7 ) ;
if ( V_157 != 0 ) {
F_48 ( V_3 -> V_161 , L_1 ,
V_156 , V_3 -> V_57 ) ;
goto V_162;
}
F_44 ( V_3 ) ;
F_49 ( V_3 -> V_57 ) ;
V_162:
return V_157 ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_8 ( V_3 , V_23 , 0 ) ;
F_51 ( V_3 -> V_57 , V_7 ) ;
if ( V_7 -> V_8 ) {
F_13 ( V_3 ) ;
V_7 -> V_8 = 0 ;
}
}
static const char * F_52 ( struct V_2 * V_3 )
{
return V_3 -> type == V_163 ? V_160 : NULL ;
}
static int F_53 ( struct V_2 * V_3 )
{
void * V_157 ;
V_157 = F_54 ( V_3 -> V_164 ,
V_165 , V_160 ) ;
return V_157 ? 0 : - V_166 ;
}
static void F_55 ( struct V_2 * V_3 )
{
F_56 ( V_3 -> V_164 , V_165 ) ;
}
static void F_57 ( struct V_2 * V_3 , int V_102 )
{
if ( V_102 & V_167 ) {
V_3 -> type = V_163 ;
F_53 ( V_3 ) ;
}
}
static int T_2 F_58 ( struct V_168 * V_169 , char * V_170 )
{
unsigned int V_171 = 115200 ;
unsigned int V_172 = 8 ;
unsigned int V_173 = 'n' ;
unsigned int V_174 = 'n' ;
struct V_2 * V_3 = & V_175 [ V_169 -> V_156 ] . V_3 ;
if ( V_169 -> V_156 < 0 || V_169 -> V_156 >= V_176 )
return - V_177 ;
if ( ! V_3 -> V_164 )
return - V_178 ;
if ( V_170 )
F_59 ( V_170 , & V_171 , & V_173 , & V_172 , & V_174 ) ;
V_3 -> V_179 = V_169 ;
return F_60 ( V_3 , V_169 , V_171 , V_173 , V_172 , V_174 ) ;
}
static void F_61 ( struct V_2 * V_3 , int V_38 )
{
while ( F_4 ( V_3 ,
V_5 ) & F_23 ( V_3 ) )
F_62 () ;
F_63 ( V_3 , V_51 , V_38 ) ;
}
static void F_64 ( struct V_168 * V_169 , const char * V_180 ,
unsigned int V_47 )
{
struct V_2 * V_3 = & V_175 [ V_169 -> V_156 ] . V_3 ;
F_65 ( V_3 , V_180 , V_47 , F_61 ) ;
}
static int T_2 F_66 ( void )
{
F_67 ( & V_181 ) ;
return 0 ;
}
int F_68 ( struct V_182 * V_183 )
{
struct V_1 * V_7 ;
struct V_2 * V_3 ;
struct V_184 * V_185 ;
int V_157 ;
if ( F_69 ( V_183 -> V_161 . V_186 , L_2 , & V_183 -> V_187 ) ) {
F_48 ( & V_183 -> V_161 ,
L_3 ) ;
V_157 = - V_188 ;
goto V_189;
}
V_7 = & V_175 [ V_183 -> V_187 ] ;
V_3 = & V_7 -> V_3 ;
V_3 -> V_161 = & V_183 -> V_161 ;
V_3 -> V_190 = V_7 ;
if ( F_70 ( V_183 -> V_161 . V_186 , L_4 , NULL ) )
V_7 -> V_10 = 1 ;
if ( F_69 ( V_183 -> V_161 . V_186 ,
L_5 ,
& V_3 -> V_191 ) ) {
F_48 ( & V_183 -> V_161 ,
L_6 ) ;
V_157 = - V_188 ;
goto V_189;
}
V_185 = F_71 ( V_183 , V_192 , 0 ) ;
if ( V_185 == NULL ) {
F_48 ( & V_183 -> V_161 , L_7 ) ;
V_157 = - V_188 ;
goto V_189;
}
V_3 -> V_164 = V_185 -> V_193 ;
V_3 -> V_194 = F_72 ( & V_183 -> V_161 , V_185 -> V_193 , F_73 ( V_185 ) ) ;
if ( ! V_3 -> V_194 ) {
F_48 ( & V_183 -> V_161 , L_8 ) ;
V_157 = - V_195 ;
goto V_189;
}
V_185 = F_71 ( V_183 , V_196 , 0 ) ;
if ( V_185 == NULL ) {
F_48 ( & V_183 -> V_161 , L_7 ) ;
V_157 = - V_188 ;
goto V_189;
}
V_3 -> V_57 = V_185 -> V_193 ;
if ( V_7 -> V_10 ) {
V_7 -> V_197 = F_74 ( & V_183 -> V_161 ) ;
if ( F_75 ( V_7 -> V_197 ) ) {
V_157 = F_76 ( V_7 -> V_197 ) ;
goto V_189;
}
}
V_7 -> V_198 = F_77 ( & V_183 -> V_161 , NULL ) ;
if ( F_75 ( V_7 -> V_198 ) ) {
V_157 = F_76 ( V_7 -> V_198 ) ;
goto V_199;
}
F_78 ( V_7 -> V_198 ) ;
V_3 -> V_138 = F_79 ( V_7 -> V_198 ) ;
V_3 -> V_200 = & V_201 ;
F_80 ( & V_3 -> V_63 ) ;
F_81 ( V_183 , V_7 ) ;
V_157 = F_82 ( & V_202 , V_3 ) ;
if ( V_157 != 0 ) {
F_48 ( & V_183 -> V_161 , L_9 , V_183 -> V_187 ) ;
goto V_203;
}
return 0 ;
V_203:
F_83 ( V_7 -> V_198 ) ;
F_84 ( V_7 -> V_198 ) ;
V_199:
F_81 ( V_183 , NULL ) ;
if ( V_7 -> V_10 )
F_85 ( V_7 -> V_197 ) ;
V_189:
return V_157 ;
}
static int F_86 ( struct V_182 * V_183 )
{
struct V_1 * V_7 = F_87 ( V_183 ) ;
struct V_2 * V_3 = & V_7 -> V_3 ;
F_81 ( V_183 , NULL ) ;
if ( V_7 -> V_10 )
F_85 ( V_7 -> V_197 ) ;
F_83 ( V_7 -> V_198 ) ;
F_84 ( V_7 -> V_198 ) ;
F_88 ( & V_202 , V_3 ) ;
return 0 ;
}
static int
F_89 ( struct V_182 * V_183 , T_3 V_46 )
{
struct V_1 * V_7 = F_87 ( V_183 ) ;
struct V_2 * V_3 = & V_7 -> V_3 ;
F_90 ( & V_202 , V_3 ) ;
return 0 ;
}
static int F_91 ( struct V_182 * V_183 )
{
struct V_1 * V_7 = F_87 ( V_183 ) ;
struct V_2 * V_3 = & V_7 -> V_3 ;
F_92 ( & V_202 , V_3 ) ;
return 0 ;
}
static int T_2 F_93 ( void )
{
int V_157 = 0 ;
V_157 = F_94 ( & V_202 ) ;
if ( V_157 )
goto V_204;
V_157 = F_95 ( & V_205 ) ;
if ( V_157 )
F_96 ( & V_202 ) ;
V_204:
return V_157 ;
}
static void T_4 F_97 ( void )
{
F_98 ( & V_205 ) ;
F_96 ( & V_202 ) ;
}
