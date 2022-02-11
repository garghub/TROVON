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
struct V_40 * V_41 ;
V_41 = F_18 ( & V_3 -> V_42 -> V_3 ) ;
if ( ! V_41 )
return - V_43 ;
while ( ! ( F_4 ( V_3 , V_44 ) &
F_5 ( V_3 ) ) ) {
V_38 = F_4 ( V_3 , V_45 ) | V_46 ;
if ( F_19 ( F_20 ( V_3 , V_38 ) ) )
continue;
F_21 ( V_3 , 0 , 0 , V_38 , V_47 ) ;
V_39 ++ ;
if ( V_39 >= V_37 )
break;
}
V_3 -> V_48 . V_49 += V_39 ;
F_22 ( V_41 ) ;
F_23 ( V_41 ) ;
return V_39 ;
}
static unsigned int
F_11 ( struct V_1 * V_7 , int V_50 )
{
struct V_2 * V_3 = & V_7 -> V_3 ;
struct V_51 * V_52 = & V_3 -> V_42 -> V_52 ;
unsigned int V_53 = 0 ;
while ( ! F_24 ( V_52 ) &&
! ( F_4 ( V_3 , V_5 ) &
F_25 ( V_3 ) ) &&
V_50 -- ) {
F_8 ( V_3 , V_54 , V_52 -> V_55 [ V_52 -> V_56 ] ) ;
V_52 -> V_56 = ( V_52 -> V_56 + 1 ) & ( V_57 - 1 ) ;
V_3 -> V_48 . V_58 ++ ;
V_53 ++ ;
}
if ( F_26 ( V_52 ) < V_59 )
F_27 ( V_3 ) ;
return V_53 ;
}
static T_1 F_28 ( int V_60 , void * V_61 )
{
unsigned long V_62 ;
unsigned long V_63 ;
unsigned long V_64 = V_47 ;
struct V_1 * V_7 = (struct V_1 * ) V_61 ;
struct V_2 * V_3 = & V_7 -> V_3 ;
struct V_65 * V_42 = V_3 -> V_42 ;
struct V_51 * V_52 = & V_3 -> V_42 -> V_52 ;
V_62 = F_4 ( V_3 , V_66 ) ;
F_8 ( V_3 , V_66 , V_62 ) ;
V_62 &= F_4 ( V_3 , V_23 ) ;
if ( F_19 ( V_62 & ( V_67 ) ) ) {
if ( V_62 & V_68 ) {
if ( F_29 ( V_3 ) )
goto V_69;
F_21 ( V_3 , V_62 ,
V_70 , 0 , V_71 ) ;
return V_72 ;
}
if ( V_62 & V_70 )
V_3 -> V_48 . V_73 ++ ;
if ( V_62 & V_74 ) {
V_3 -> V_48 . V_75 ++ ;
V_64 = V_76 ;
}
if ( V_62 & V_77 )
V_64 = V_78 ;
F_8 ( V_3 , V_27 , V_79 ) ;
F_8 ( V_3 , V_27 , 0 ) ;
F_8 ( V_3 , V_27 , V_80 ) ;
V_62 &= V_3 -> V_81 ;
F_21 ( V_3 , V_62 ,
V_82 , 0 , V_64 ) ;
}
V_69:
if ( V_62 & V_29 ) {
V_63 = ! ( F_4 ( V_3 , V_11 ) &
V_12 ) ;
if ( V_63 != 0 ) {
F_15 ( V_3 , 1 ) ;
} else {
F_15 ( V_3 , 0 ) ;
F_30 ( & V_42 -> V_3 . V_83 ) ;
}
}
if ( V_62 & V_28 )
F_17 ( V_3 , V_84 ) ;
if ( V_62 & V_24 ) {
if ( F_24 ( V_52 ) || F_31 ( V_3 ) ) {
return V_72 ;
} else {
F_11 ( V_7 ,
V_85 ) ;
if ( ( F_24 ( V_52 ) ) &&
( F_4 ( V_3 , V_5 ) &
F_5 ( V_3 ) ) )
F_9 ( V_3 ) ;
}
}
return V_72 ;
}
static void F_32 ( struct V_2 * V_3 )
{
unsigned long V_22 ;
V_22 = F_4 ( V_3 , V_23 ) ;
F_8 ( V_3 , V_23 , V_22 | V_28 ) ;
F_8 ( V_3 , V_27 , V_79 ) ;
F_8 ( V_3 , V_27 , 0 ) ;
F_8 ( V_3 , V_27 , V_80 ) ;
}
static unsigned int
F_33 ( unsigned long V_86 ,
unsigned long V_87 , unsigned long * V_88 )
{
unsigned long V_89 = ~ 0UL ;
unsigned short V_90 ;
unsigned int V_22 = 0 ;
unsigned long V_91 ;
unsigned long V_92 ;
int V_93 ;
for ( V_90 = V_94 ;
V_90 <= V_95 ; V_90 ++ ) {
V_91 = ( V_87 / ( V_86 * ( V_90 + 1 ) ) ) - 1 ;
if ( V_91 > V_96 )
continue;
V_92 = V_87 / ( ( V_91 + 1 ) * ( V_90 + 1 ) ) ;
V_93 = V_92 - V_86 ;
V_93 = ( V_93 > 0 ) ? V_93 : - V_93 ;
if ( V_93 < V_89 ) {
V_22 = V_22 & ( ~ V_97 ) ;
V_22 = V_22 | V_91 ;
V_22 = V_22 & ( ~ V_98 ) ;
V_22 = V_22 | ( V_90 << V_99 ) ;
V_89 = V_93 ;
* V_88 = V_92 ;
}
}
return V_22 ;
}
static void F_34 ( struct V_2 * V_3 ,
struct V_100 * V_101 ,
struct V_100 * V_102 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_87 ;
unsigned long V_103 = 0 ;
unsigned long V_86 ;
unsigned long V_88 ;
unsigned long V_104 ;
unsigned long V_105 ;
unsigned int V_106 = 0 ;
unsigned long V_107 ;
unsigned long V_108 ;
int V_109 ;
int V_110 ;
V_87 = 150000000 ;
switch ( V_101 -> V_111 & V_112 ) {
default:
case V_113 :
V_103 |= V_114 ;
break;
case V_115 :
V_103 |= V_116 ;
break;
case V_117 :
V_103 |= V_118 ;
break;
case V_119 :
V_103 |= V_120 ;
break;
}
if ( V_101 -> V_111 & V_121 )
V_103 |= V_122 ;
V_86 = F_35 ( V_3 , V_101 , V_102 , 0 , 4000000 ) ;
F_36 ( & V_3 -> V_123 , V_104 ) ;
V_3 -> V_81 = V_82 ;
V_3 -> V_124 = 0 ;
if ( V_101 -> V_125 & V_126 )
V_3 -> V_81 |=
V_127 | V_128 ;
if ( V_101 -> V_125 & ( V_129 | V_130 ) )
V_3 -> V_81 |= V_131 ;
if ( V_101 -> V_125 & V_132 )
V_3 -> V_124 |=
V_127 | V_128 ;
if ( ( V_101 -> V_111 & V_133 ) == 0 )
V_3 -> V_124 |= V_46 ;
if ( V_101 -> V_111 & V_134 ) {
if ( V_101 -> V_111 & V_135 ) {
if ( V_101 -> V_111 & V_136 )
V_103 |= V_137 ;
else
V_103 |= V_138 ;
} else if ( V_101 -> V_111 & V_136 ) {
V_103 |= V_139 ;
} else {
V_103 |= V_140 ;
}
}
if ( F_37 ( V_3 , V_101 -> V_111 ) ) {
if ( ! V_7 -> V_8 )
F_14 ( V_3 ) ;
} else {
if ( V_7 -> V_8 )
F_13 ( V_3 ) ;
}
for ( V_105 = 0 ; V_105 < V_141 ; V_105 ++ )
if ( V_86 == V_142 [ V_105 ] . V_86 )
V_106 = V_142 [ V_105 ] . V_143 ;
V_88 = V_86 ;
if ( F_19 ( V_106 == 0 ) )
V_106 = F_33 ( V_86 , V_87 ,
& V_88 ) ;
F_8 ( V_3 , V_144 , V_106 ) ;
if ( F_38 ( V_101 ) )
F_39 ( V_101 , V_88 , V_88 ) ;
V_108 = F_40 ( V_86 , 20000 ) ;
V_108 = ( V_108 > 0xFFFF ) ? 0xFFFF : V_108 ;
V_103 |= F_41 ( V_108 ) ;
V_107 = F_4 ( V_3 , V_25 ) ;
F_8 ( V_3 , V_27 , 0 ) ;
F_8 ( V_3 , V_25 ,
V_107 & ~ V_26 ) ;
F_8 ( V_3 , V_145 , V_146 ) ;
F_8 ( V_3 , V_147 , V_148 ) ;
F_8 ( V_3 , V_35 , V_103 ) ;
if ( V_86 < 1000000 )
V_109 = 1 ;
else
V_109 = 2 ;
V_110 = V_3 -> line == 1 ? 16 : 64 ;
F_8 ( V_3 , V_149 , V_110 / V_109 ) ;
F_8 ( V_3 , V_150 , V_110 / V_109 ) ;
V_107 |= V_26 ;
F_8 ( V_3 , V_25 , V_107 ) ;
F_42 ( V_3 , V_101 -> V_111 , V_86 ) ;
F_32 ( V_3 ) ;
F_8 ( V_3 , V_151 , V_152 | V_153 ) ;
F_43 ( & V_3 -> V_123 , V_104 ) ;
}
static void F_44 ( struct V_2 * V_3 )
{
unsigned long V_154 ;
int V_110 ;
V_154 = F_4 ( V_3 , V_145 ) ;
F_8 ( V_3 , V_145 , V_154 | V_146 ) ;
V_154 = F_4 ( V_3 , V_147 ) ;
F_8 ( V_3 , V_147 , V_154 | V_148 ) ;
F_8 ( V_3 , V_155 , 0 ) ;
F_8 ( V_3 , V_156 , 0 ) ;
F_8 ( V_3 , V_151 , V_153 | V_152 ) ;
F_8 ( V_3 , V_25 , V_157 ) ;
F_8 ( V_3 , V_25 , 0 ) ;
F_8 ( V_3 , V_27 , V_79 ) ;
F_8 ( V_3 , V_27 , 0 ) ;
V_110 = V_3 -> line == 1 ? 16 : 64 ;
F_8 ( V_3 , V_149 , V_110 ) ;
F_8 ( V_3 , V_150 , V_110 ) ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_158 = V_3 -> line ;
int V_159 ;
F_46 ( V_3 -> V_60 , V_160 | V_161 ) ;
V_159 = F_47 ( V_3 -> V_60 ,
F_28 ,
0 ,
V_162 ,
V_7 ) ;
if ( V_159 != 0 ) {
F_48 ( V_3 -> V_163 , L_1 ,
V_158 , V_3 -> V_60 ) ;
goto V_164;
}
F_44 ( V_3 ) ;
F_49 ( V_3 -> V_60 ) ;
V_164:
return V_159 ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_8 ( V_3 , V_23 , 0 ) ;
F_51 ( V_3 -> V_60 , V_7 ) ;
if ( V_7 -> V_8 ) {
F_13 ( V_3 ) ;
V_7 -> V_8 = 0 ;
}
}
static const char * F_52 ( struct V_2 * V_3 )
{
return V_3 -> type == V_165 ? V_162 : NULL ;
}
static int F_53 ( struct V_2 * V_3 )
{
void * V_159 ;
V_159 = F_54 ( V_3 -> V_166 ,
V_167 , V_162 ) ;
return V_159 ? 0 : - V_168 ;
}
static void F_55 ( struct V_2 * V_3 )
{
F_56 ( V_3 -> V_166 , V_167 ) ;
}
static void F_57 ( struct V_2 * V_3 , int V_104 )
{
if ( V_104 & V_169 ) {
V_3 -> type = V_165 ;
F_53 ( V_3 ) ;
}
}
static int T_2 F_58 ( struct V_170 * V_171 , char * V_172 )
{
unsigned int V_173 = 115200 ;
unsigned int V_174 = 8 ;
unsigned int V_175 = 'n' ;
unsigned int V_176 = 'n' ;
struct V_2 * V_3 = & V_177 [ V_171 -> V_158 ] . V_3 ;
if ( V_171 -> V_158 < 0 || V_171 -> V_158 >= V_178 )
return - V_179 ;
if ( ! V_3 -> V_166 )
return - V_43 ;
if ( V_172 )
F_59 ( V_172 , & V_173 , & V_175 , & V_174 , & V_176 ) ;
V_3 -> V_180 = V_171 ;
return F_60 ( V_3 , V_171 , V_173 , V_175 , V_174 , V_176 ) ;
}
static void F_61 ( struct V_2 * V_3 , int V_38 )
{
while ( F_4 ( V_3 ,
V_5 ) & F_25 ( V_3 ) )
F_62 () ;
F_63 ( V_3 , V_54 , V_38 ) ;
}
static void F_64 ( struct V_170 * V_171 , const char * V_181 ,
unsigned int V_50 )
{
struct V_2 * V_3 = & V_177 [ V_171 -> V_158 ] . V_3 ;
F_65 ( V_3 , V_181 , V_50 , F_61 ) ;
}
static int T_2 F_66 ( void )
{
F_67 ( & V_182 ) ;
return 0 ;
}
int F_68 ( struct V_183 * V_184 )
{
struct V_1 * V_7 ;
struct V_2 * V_3 ;
struct V_185 * V_186 ;
int V_159 ;
if ( F_69 ( V_184 -> V_163 . V_187 , L_2 , & V_184 -> V_188 ) ) {
F_48 ( & V_184 -> V_163 ,
L_3 ) ;
V_159 = - V_189 ;
goto V_190;
}
V_7 = & V_177 [ V_184 -> V_188 ] ;
V_3 = & V_7 -> V_3 ;
V_3 -> V_163 = & V_184 -> V_163 ;
V_3 -> V_191 = V_7 ;
if ( F_70 ( V_184 -> V_163 . V_187 , L_4 , NULL ) )
V_7 -> V_10 = 1 ;
if ( F_69 ( V_184 -> V_163 . V_187 ,
L_5 ,
& V_3 -> V_192 ) ) {
F_48 ( & V_184 -> V_163 ,
L_6 ) ;
V_159 = - V_189 ;
goto V_190;
}
V_186 = F_71 ( V_184 , V_193 , 0 ) ;
if ( V_186 == NULL ) {
F_48 ( & V_184 -> V_163 , L_7 ) ;
V_159 = - V_189 ;
goto V_190;
}
V_3 -> V_166 = V_186 -> V_194 ;
V_3 -> V_195 = F_72 ( & V_184 -> V_163 , V_186 -> V_194 , F_73 ( V_186 ) ) ;
if ( ! V_3 -> V_195 ) {
F_48 ( & V_184 -> V_163 , L_8 ) ;
V_159 = - V_196 ;
goto V_190;
}
V_186 = F_71 ( V_184 , V_197 , 0 ) ;
if ( V_186 == NULL ) {
F_48 ( & V_184 -> V_163 , L_7 ) ;
V_159 = - V_189 ;
goto V_164;
}
V_3 -> V_60 = V_186 -> V_194 ;
if ( V_7 -> V_10 ) {
V_7 -> V_198 = F_74 ( & V_184 -> V_163 , NULL ) ;
V_159 = F_75 ( V_7 -> V_198 ) ;
if ( V_159 )
goto V_199;
F_76 ( V_7 -> V_198 ) ;
}
V_3 -> V_200 = & V_201 ;
F_77 ( & V_3 -> V_123 ) ;
F_78 ( V_184 , V_7 ) ;
V_159 = F_79 ( & V_202 , V_3 ) ;
if ( V_159 != 0 ) {
F_48 ( & V_184 -> V_163 , L_9 , V_184 -> V_188 ) ;
goto V_203;
}
return 0 ;
V_203:
F_78 ( V_184 , NULL ) ;
if ( V_7 -> V_10 ) {
F_80 ( V_7 -> V_198 ) ;
F_81 ( V_7 -> V_198 ) ;
}
V_199:
V_164:
F_82 ( & V_184 -> V_163 , V_3 -> V_195 ) ;
V_190:
return V_159 ;
}
static int F_83 ( struct V_183 * V_184 )
{
struct V_1 * V_7 = F_84 ( V_184 ) ;
struct V_2 * V_3 = & V_7 -> V_3 ;
F_78 ( V_184 , NULL ) ;
if ( V_7 -> V_10 ) {
F_80 ( V_7 -> V_198 ) ;
F_81 ( V_7 -> V_198 ) ;
}
F_82 ( & V_184 -> V_163 , V_3 -> V_195 ) ;
F_85 ( & V_202 , V_3 ) ;
return 0 ;
}
static int
F_86 ( struct V_183 * V_184 , T_3 V_42 )
{
struct V_1 * V_7 = F_84 ( V_184 ) ;
struct V_2 * V_3 = & V_7 -> V_3 ;
F_87 ( & V_202 , V_3 ) ;
return 0 ;
}
static int F_88 ( struct V_183 * V_184 )
{
struct V_1 * V_7 = F_84 ( V_184 ) ;
struct V_2 * V_3 = & V_7 -> V_3 ;
F_89 ( & V_202 , V_3 ) ;
return 0 ;
}
static int T_2 F_90 ( void )
{
int V_159 = 0 ;
V_159 = F_91 ( & V_202 ) ;
if ( V_159 )
goto V_204;
V_159 = F_92 ( & V_205 ) ;
if ( V_159 )
F_93 ( & V_202 ) ;
V_204:
return V_159 ;
}
static void T_4 F_94 ( void )
{
F_95 ( & V_205 ) ;
F_93 ( & V_202 ) ;
}
