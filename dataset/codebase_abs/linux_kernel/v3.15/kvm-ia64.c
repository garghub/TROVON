static unsigned long F_1 ( struct V_1 * V_2 )
{
#if F_2 ( V_3 ) || F_2 ( V_4 )
if ( V_2 -> V_5 -> V_6 . V_7 )
return F_3 () ;
else
#endif
return F_4 ( V_8 ) ;
}
static void F_5 ( unsigned long V_9 , unsigned long V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < ( V_10 + 32 ) ; V_11 += 32 )
F_6 ( ( void * ) ( V_9 + V_11 ) ) ;
F_7 () ;
F_8 () ;
}
static void F_9 ( void )
{
unsigned long V_12 , V_13 , V_14 , V_15 , V_16 , V_17 , V_18 ;
long V_19 ;
V_18 = V_20 -> V_21 ;
V_14 = V_20 -> V_22 [ 0 ] ;
V_15 = V_20 -> V_22 [ 1 ] ;
V_16 = V_20 -> V_23 [ 0 ] ;
V_17 = V_20 -> V_23 [ 1 ] ;
F_10 ( V_19 ) ;
for ( V_12 = 0 ; V_12 < V_14 ; ++ V_12 ) {
for ( V_13 = 0 ; V_13 < V_15 ; ++ V_13 ) {
F_11 ( V_18 ) ;
V_18 += V_17 ;
}
V_18 += V_16 ;
}
F_12 ( V_19 ) ;
F_8 () ;
}
long F_13 ( T_1 * V_24 , T_1 * V_25 , T_1 * V_26 )
{
struct V_27 V_28 ;
F_14 ( V_28 , V_29 , ( T_1 ) V_24 , ( T_1 ) V_25 ,
( T_1 ) V_26 ) ;
return V_28 . V_30 ;
}
int F_15 ( void * V_31 )
{
long V_30 ;
long V_32 ;
unsigned long V_33 ;
unsigned long V_34 ;
int V_35 ;
V_33 = F_16 ( F_17 ( F_18 ( V_36 ) , V_37 ) ) ;
F_10 ( V_34 ) ;
V_35 = F_19 ( 0x3 , V_38 , V_33 , V_39 ) ;
F_12 ( V_34 ) ;
if ( V_35 < 0 )
return - V_40 ;
F_20 ( & V_41 ) ;
V_30 = F_21 ( V_42 ?
V_43 : V_44 ,
F_18 ( V_45 ) , V_46 , & V_32 ) ;
if ( V_30 != 0 ) {
F_22 ( & V_41 ) ;
F_23 ( V_47 L_1 ) ;
return - V_40 ;
}
if ( ! V_42 ) {
V_42 = V_32 ;
F_23 ( V_48 L_2 , V_42 ) ;
}
F_22 ( & V_41 ) ;
F_24 ( 0x3 , V_35 ) ;
return 0 ;
}
void F_25 ( void * V_31 )
{
long V_30 ;
int V_35 ;
unsigned long V_33 ;
unsigned long V_34 ;
unsigned long V_25 = F_4 ( V_49 ) ;
V_33 = F_16 ( F_17 ( F_18 ( V_36 ) ,
V_37 ) ) ;
F_10 ( V_34 ) ;
V_35 = F_19 ( 0x3 , V_38 , V_33 , V_39 ) ;
F_12 ( V_34 ) ;
if ( V_35 < 0 )
return;
V_30 = F_26 ( V_25 ) ;
if ( V_30 )
F_23 ( V_50 L_3 ,
V_30 ) ;
F_24 ( 0x3 , V_35 ) ;
}
void F_27 ( void * V_51 )
{
* ( int * ) V_51 = 0 ;
}
int F_28 ( long V_52 )
{
int V_53 ;
switch ( V_52 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
V_53 = 1 ;
break;
case V_58 :
V_53 = V_59 ;
break;
#ifdef F_29
case V_60 :
V_53 = F_30 ( & V_61 ) ;
break;
#endif
default:
V_53 = 0 ;
}
return V_53 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_62 * V_62 )
{
V_62 -> V_63 = V_64 ;
V_62 -> V_65 . V_66 = 1 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_62 * V_62 )
{
struct V_67 * V_68 ;
struct V_69 * V_70 ;
int V_53 ;
V_68 = F_33 ( V_2 ) ;
if ( ( V_68 -> V_18 & V_71 ) == V_72 )
goto V_73;
V_2 -> V_74 = 1 ;
V_2 -> V_75 [ 0 ] . V_76 = V_62 -> V_73 . V_77 = V_68 -> V_18 ;
V_2 -> V_75 [ 0 ] . V_10 = V_62 -> V_73 . V_10 = V_68 -> V_78 ;
V_2 -> V_79 = V_62 -> V_73 . V_80 = ! V_68 -> V_81 ;
if ( V_2 -> V_79 )
memcpy ( V_2 -> V_6 . V_82 , & V_68 -> V_83 , V_68 -> V_78 ) ;
memcpy ( V_62 -> V_73 . V_83 , & V_68 -> V_83 , V_68 -> V_78 ) ;
V_62 -> V_63 = V_84 ;
return 0 ;
V_73:
if ( V_68 -> V_81 )
V_53 = F_34 ( V_2 -> V_5 , V_85 , V_68 -> V_18 ,
V_68 -> V_78 , & V_68 -> V_83 ) ;
else
V_53 = F_35 ( V_2 -> V_5 , V_85 , V_68 -> V_18 ,
V_68 -> V_78 , & V_68 -> V_83 ) ;
if ( V_53 )
F_23 ( V_86 L_4 , V_68 -> V_18 ) ;
V_68 -> V_87 = V_88 ;
return 1 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_62 * V_62 )
{
struct V_89 * V_68 ;
V_68 = F_37 ( V_2 ) ;
if ( V_68 -> V_63 == V_90 )
return F_38 ( V_2 , V_62 ) ;
else {
V_62 -> V_63 = V_64 ;
V_62 -> V_65 . V_66 = 2 ;
return 0 ;
}
}
static int F_39 ( struct V_1 * V_2 , struct V_62 * V_62 )
{
struct V_89 * V_68 ;
V_68 = F_37 ( V_2 ) ;
if ( V_68 -> V_63 == V_91 ) {
F_40 ( V_2 ) ;
return 1 ;
} else {
V_62 -> V_63 = V_64 ;
V_62 -> V_65 . V_66 = 3 ;
return 0 ;
}
}
static int F_41 ( struct V_1 * V_2 , T_2 V_92 )
{
struct V_24 * V_24 = F_42 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
if ( ! F_43 ( V_92 , & V_24 -> V_93 [ 0 ] ) ) {
V_2 -> V_6 . V_94 = 1 ;
F_44 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static void F_45 ( struct V_1 * V_2 , T_2 V_95 ,
T_2 V_92 )
{
switch ( V_95 ) {
case V_96 :
break;
case V_97 :
V_92 = 2 ;
break;
case V_98 :
V_92 = 0 ;
break;
case V_99 :
case V_100 :
default:
F_23 ( V_86 L_5 ) ;
return;
}
F_41 ( V_2 , V_92 ) ;
}
static struct V_1 * F_46 ( struct V_5 * V_5 , unsigned long V_101 ,
unsigned long V_102 )
{
union V_103 V_104 ;
int V_12 ;
struct V_1 * V_2 ;
F_47 (i, vcpu, kvm) {
V_104 . V_105 = F_48 ( V_2 ) ;
if ( V_104 . V_101 == V_101 && V_104 . V_102 == V_102 )
return V_2 ;
}
return NULL ;
}
static int F_49 ( struct V_1 * V_2 , struct V_62 * V_62 )
{
struct V_89 * V_68 = F_37 ( V_2 ) ;
struct V_1 * V_106 ;
struct V_107 * V_108 ;
union V_109 V_18 = V_68 -> V_110 . V_111 . V_18 ;
union V_112 V_83 = V_68 -> V_110 . V_111 . V_83 ;
V_106 = F_46 ( V_2 -> V_5 , V_18 . V_101 , V_18 . V_102 ) ;
if ( ! V_106 )
return F_31 ( V_2 , V_62 ) ;
if ( ! V_106 -> V_6 . V_113 ) {
V_108 = F_50 ( V_106 ) ;
V_108 -> V_114 = V_2 -> V_5 -> V_6 . V_115 . V_116 ;
V_108 -> V_117 = V_2 -> V_5 -> V_6 . V_115 . V_118 ;
V_106 -> V_6 . V_119 = V_120 ;
if ( F_51 ( & V_106 -> V_121 ) )
F_52 ( & V_106 -> V_121 ) ;
} else {
F_45 ( V_106 , V_83 . V_95 , V_83 . V_92 ) ;
if ( V_106 != V_2 )
F_44 ( V_106 ) ;
}
return 1 ;
}
static void F_53 ( void * V_122 )
{
struct V_123 * V_68 = (struct V_123 * ) V_122 ;
struct V_1 * V_2 = V_68 -> V_2 ;
if ( F_54 ( V_124 , & V_2 -> V_125 ) )
return;
F_55 ( V_126 , & V_2 -> V_125 ) ;
if ( V_2 -> V_6 . V_127 < V_128 ) {
V_2 -> V_6 . V_129 [ V_2 -> V_6 . V_127 ++ ] =
V_68 -> V_129 ;
} else {
F_56 ( V_126 , & V_2 -> V_125 ) ;
V_2 -> V_6 . V_127 = 0 ;
F_55 ( V_124 , & V_2 -> V_125 ) ;
}
}
static int F_57 ( struct V_1 * V_2 , struct V_62 * V_62 )
{
struct V_89 * V_68 = F_37 ( V_2 ) ;
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_123 V_123 ;
int V_12 ;
struct V_1 * V_130 ;
V_123 . V_129 = V_68 -> V_110 . V_129 ;
F_47 (i, vcpui, kvm) {
if ( V_130 -> V_6 . V_119 == V_131 ||
V_2 == V_130 )
continue;
if ( F_51 ( & V_130 -> V_121 ) )
F_52 ( & V_130 -> V_121 ) ;
if ( V_130 -> V_132 != - 1 ) {
V_123 . V_2 = V_130 ;
F_58 ( V_130 -> V_132 ,
F_53 , & V_123 , 1 ) ;
} else
F_23 ( V_47 L_6 ) ;
}
return 1 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_62 * V_62 )
{
return 1 ;
}
static int F_60 ( struct V_1 * V_2 )
{
unsigned long V_33 , V_133 , V_134 ;
int V_35 ;
V_134 = V_38 + ( 1UL << V_39 ) ;
V_133 = V_135 | V_136 ;
V_33 = F_16 ( F_17 ( V_133 , V_137 ) ) ;
V_35 = F_19 ( 0x3 , V_134 , V_33 , V_138 ) ;
V_2 -> V_6 . V_139 = V_35 ;
if ( V_35 < 0 ) {
F_23 ( V_86 L_7 ) ;
V_35 = 0 ;
}
return V_35 ;
}
int F_61 ( struct V_1 * V_2 )
{
T_3 V_140 ;
long V_141 ;
unsigned long V_142 ;
unsigned long V_143 ;
struct V_144 * V_145 = & V_2 -> V_6 . V_146 ;
unsigned long V_147 = V_20 -> V_147 ;
struct V_24 * V_24 = F_42 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
if ( F_62 ( V_2 -> V_5 ) ) {
V_142 = F_1 ( V_2 ) + V_2 -> V_6 . V_148 ;
if ( F_63 ( V_142 , V_24 -> V_149 ) ) {
V_2 -> V_6 . V_150 = 1 ;
return 1 ;
}
V_141 = V_24 -> V_149 - V_142 ;
if ( V_141 < 0 )
V_141 = - V_141 ;
V_143 = F_64 ( V_141 , V_147 ) ;
V_140 = F_65 ( 0 , 1000 * V_143 ) ;
V_2 -> V_6 . V_151 = 1 ;
F_66 ( V_145 , V_140 , V_152 ) ;
V_2 -> V_6 . V_119 = V_153 ;
F_67 ( V_2 ) ;
F_68 ( V_145 ) ;
V_2 -> V_6 . V_151 = 0 ;
if ( F_69 ( V_154 , & V_2 -> V_125 ) ||
F_70 ( V_2 ) )
if ( V_2 -> V_6 . V_119 == V_153 )
V_2 -> V_6 . V_119 = V_120 ;
if ( V_2 -> V_6 . V_119 != V_120 )
return - V_155 ;
return 1 ;
} else {
F_23 ( V_86 L_8 ) ;
return 0 ;
}
}
static int F_71 ( struct V_1 * V_2 ,
struct V_62 * V_62 )
{
V_62 -> V_63 = V_156 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_62 * V_62 )
{
return 1 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_62 * V_62 )
{
F_23 ( L_9 , V_2 -> V_6 . V_157 ) ;
return 1 ;
}
static T_4 F_74 ( struct V_1 * V_2 )
{
struct V_89 * V_158 ;
V_158 = F_37 ( V_2 ) ;
return V_158 -> V_63 ;
}
static int F_75 ( struct V_62 * V_62 , struct V_1 * V_2 )
{
T_5 V_63 = F_74 ( V_2 ) ;
V_2 -> V_6 . V_159 = V_63 ;
if ( V_63 < V_160
&& V_161 [ V_63 ] )
return V_161 [ V_63 ] ( V_2 , V_62 ) ;
else {
V_62 -> V_63 = V_64 ;
V_62 -> V_65 . V_66 = V_63 ;
}
return 0 ;
}
static inline void F_76 ( unsigned long V_162 )
{
F_77 ( V_163 , V_162 ) ;
F_8 () ;
}
static int F_78 ( struct V_1 * V_2 )
{
unsigned long V_33 ;
struct V_5 * V_5 = V_2 -> V_5 ;
int V_53 ;
V_33 = F_16 ( F_17 ( F_18 ( V_36 ) , V_37 ) ) ;
V_53 = F_19 ( 0x3 , V_38 , V_33 , V_39 ) ;
if ( V_53 < 0 )
goto V_164;
V_2 -> V_6 . V_165 = V_53 ;
V_33 = F_16 ( F_17 ( F_18 ( V_5 -> V_6 . V_166 ) , V_37 ) ) ;
V_53 = F_19 ( 0x3 , V_167 ,
V_33 , V_168 ) ;
if ( V_53 < 0 )
goto V_164;
V_2 -> V_6 . V_169 = V_53 ;
#if F_2 ( V_3 ) || F_2 ( V_4 )
if ( V_5 -> V_6 . V_7 ) {
V_53 = F_60 ( V_2 ) ;
if ( V_53 < 0 )
goto V_164;
}
#endif
V_53 = 0 ;
V_164:
return V_53 ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
F_24 ( 0x3 , V_2 -> V_6 . V_165 ) ;
F_24 ( 0x3 , V_2 -> V_6 . V_169 ) ;
#if F_2 ( V_3 ) || F_2 ( V_4 )
if ( V_5 -> V_6 . V_7 )
F_24 ( 0x3 , V_2 -> V_6 . V_139 ) ;
#endif
}
static int F_80 ( struct V_1 * V_2 )
{
unsigned long V_170 ;
int V_53 ;
int V_132 = F_81 () ;
if ( V_2 -> V_6 . V_171 != V_132 ||
F_82 ( V_172 , V_132 ) != V_2 ) {
F_82 ( V_172 , V_132 ) = V_2 ;
V_2 -> V_6 . V_171 = V_132 ;
F_9 () ;
}
V_2 -> V_6 . V_173 = F_83 ( V_163 ) ;
F_76 ( V_2 -> V_6 . V_174 ) ;
F_10 ( V_170 ) ;
V_53 = F_78 ( V_2 ) ;
F_12 ( V_170 ) ;
return V_53 ;
}
static void F_84 ( struct V_1 * V_2 )
{
F_79 ( V_2 ) ;
F_76 ( V_2 -> V_6 . V_173 ) ;
}
static int F_85 ( struct V_1 * V_2 , struct V_62 * V_62 )
{
union V_175 * V_176 , * V_177 ;
int V_53 , V_178 ;
V_178 = F_86 ( & V_2 -> V_5 -> V_179 ) ;
V_180:
if ( F_87 ( V_181 ) ) {
V_53 = - V_155 ;
V_62 -> V_63 = V_182 ;
goto V_164;
}
F_88 () ;
F_89 () ;
V_176 = F_90 ( V_2 ) ;
V_177 = F_91 ( V_2 ) ;
F_56 ( V_183 , & V_2 -> V_125 ) ;
V_53 = F_80 ( V_2 ) ;
if ( V_53 < 0 )
goto V_184;
F_92 ( & V_2 -> V_5 -> V_179 , V_178 ) ;
V_2 -> V_185 = V_186 ;
F_93 () ;
V_187 -> V_188 ( V_176 , V_177 ) ;
F_84 ( V_2 ) ;
V_2 -> V_6 . V_113 = 1 ;
F_55 ( V_183 , & V_2 -> V_125 ) ;
F_94 () ;
F_95 () ;
F_96 () ;
V_2 -> V_185 = V_189 ;
F_97 () ;
V_178 = F_86 ( & V_2 -> V_5 -> V_179 ) ;
V_53 = F_75 ( V_62 , V_2 ) ;
if ( V_53 > 0 ) {
if ( ! F_98 () )
goto V_180;
}
V_164:
F_92 ( & V_2 -> V_5 -> V_179 , V_178 ) ;
if ( V_53 > 0 ) {
F_99 () ;
V_178 = F_86 ( & V_2 -> V_5 -> V_179 ) ;
goto V_180;
}
return V_53 ;
V_184:
F_94 () ;
F_97 () ;
V_62 -> V_63 = V_190 ;
goto V_164;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_67 * V_68 = F_33 ( V_2 ) ;
if ( ! V_2 -> V_79 )
memcpy ( & V_68 -> V_83 , V_2 -> V_6 . V_82 , 8 ) ;
V_68 -> V_87 = V_88 ;
}
int F_101 ( struct V_1 * V_2 , struct V_62 * V_62 )
{
int V_53 ;
T_6 V_191 ;
if ( V_2 -> V_192 )
F_102 ( V_193 , & V_2 -> V_194 , & V_191 ) ;
if ( F_103 ( V_2 -> V_6 . V_119 == V_131 ) ) {
F_67 ( V_2 ) ;
F_56 ( V_154 , & V_2 -> V_125 ) ;
V_53 = - V_195 ;
goto V_164;
}
if ( V_2 -> V_74 ) {
memcpy ( V_2 -> V_6 . V_82 , V_62 -> V_73 . V_83 , 8 ) ;
F_100 ( V_2 ) ;
V_2 -> V_196 = 1 ;
V_2 -> V_74 = 0 ;
}
V_53 = F_85 ( V_2 , V_62 ) ;
V_164:
if ( V_2 -> V_192 )
F_102 ( V_193 , & V_191 , NULL ) ;
return V_53 ;
}
struct V_5 * F_104 ( void )
{
struct V_5 * V_5 ;
T_2 V_166 ;
F_105 ( sizeof( struct V_5 ) > V_197 ) ;
V_166 = F_106 ( V_198 , F_107 ( V_199 ) ) ;
if ( ! V_166 )
return NULL ;
memset ( ( void * ) V_166 , 0 , V_199 ) ;
V_5 = (struct V_5 * ) ( V_166 +
F_108 ( struct V_200 , V_201 ) ) ;
V_5 -> V_6 . V_166 = V_166 ;
F_23 ( V_50 L_10 , V_166 ) ;
return V_5 ;
}
static void F_109 ( struct V_5 * V_5 )
{
unsigned long V_12 , V_13 ;
for ( V_12 = 0 ; V_12 < ( sizeof( V_202 ) / sizeof( struct V_203 ) ) ;
V_12 ++ ) {
for ( V_13 = V_202 [ V_12 ] . V_9 ;
V_13 < V_202 [ V_12 ] . V_9 + V_202 [ V_12 ] . V_78 ;
V_13 += V_204 )
F_110 ( V_5 , V_13 >> V_138 ,
V_202 [ V_12 ] . type , 0 ) ;
}
}
int F_111 ( struct V_5 * V_5 , unsigned long type )
{
F_105 ( ! V_5 ) ;
if ( type )
return - V_40 ;
V_5 -> V_6 . V_7 = F_112 ( L_11 ) ;
V_5 -> V_6 . V_205 = V_206 ;
V_5 -> V_6 . V_207 = V_208 ;
V_5 -> V_6 . V_209 = V_210 ;
F_109 ( V_5 ) ;
F_113 ( & V_5 -> V_6 . V_211 ) ;
F_55 ( V_212 , & V_5 -> V_6 . V_213 ) ;
return 0 ;
}
static int F_114 ( struct V_5 * V_5 ,
struct V_214 * V_215 )
{
int V_53 ;
V_53 = 0 ;
switch ( V_215 -> V_216 ) {
case V_217 :
V_53 = F_115 ( V_5 , & V_215 -> V_215 . V_218 ) ;
break;
default:
V_53 = - V_40 ;
break;
}
return V_53 ;
}
static int F_116 ( struct V_5 * V_5 , struct V_214 * V_215 )
{
int V_53 ;
V_53 = 0 ;
switch ( V_215 -> V_216 ) {
case V_217 :
V_53 = F_117 ( V_5 , & V_215 -> V_215 . V_218 ) ;
break;
default:
V_53 = - V_40 ;
break;
}
return V_53 ;
}
int F_118 ( struct V_1 * V_2 , struct V_219 * V_108 )
{
struct V_24 * V_24 = F_42 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
V_24 -> V_220 [ V_12 ] = V_108 -> V_24 . V_220 [ V_12 ] ;
V_24 -> V_221 [ V_12 ] = V_108 -> V_24 . V_221 [ V_12 ] ;
}
for ( V_12 = 0 ; V_12 < 128 ; V_12 ++ )
V_24 -> V_222 [ V_12 ] = V_108 -> V_24 . V_222 [ V_12 ] ;
V_24 -> V_223 = V_108 -> V_24 . V_223 ;
V_24 -> V_224 = V_108 -> V_24 . V_224 ;
V_24 -> V_225 = V_108 -> V_24 . V_225 ;
V_24 -> V_226 = V_108 -> V_24 . V_226 ;
V_24 -> V_227 = V_108 -> V_24 . V_227 ;
memcpy ( & V_2 -> V_6 . V_228 , & V_108 -> V_229 , sizeof( union V_175 ) ) ;
F_119 ( V_119 ) ;
F_119 ( V_174 ) ;
memcpy ( V_2 -> V_6 . V_230 , V_108 -> V_230 , sizeof( struct V_231 ) * V_232 ) ;
memcpy ( V_2 -> V_6 . V_233 , V_108 -> V_233 , sizeof( struct V_231 ) * V_234 ) ;
F_119 ( V_235 ) ;
F_119 ( V_236 ) ;
F_119 ( V_237 ) ;
F_119 ( V_238 ) ;
F_119 ( V_239 ) ;
F_119 ( V_150 ) ;
F_119 ( V_240 ) ;
F_119 ( V_241 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_2 -> V_6 . V_242 [ V_12 ] = V_108 -> V_242 [ V_12 ] ;
V_2 -> V_6 . V_243 [ V_12 ] = V_108 -> V_243 [ V_12 ] ;
V_2 -> V_6 . V_244 [ V_12 ] = V_108 -> V_244 [ V_12 ] ;
}
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ )
V_2 -> V_6 . V_245 [ V_12 ] = V_108 -> V_245 [ V_12 ] ;
F_119 ( V_246 ) ;
F_119 ( V_205 ) ;
F_119 ( V_207 ) ;
F_119 ( V_247 ) ;
F_119 ( V_248 ) ;
F_119 ( V_249 ) ;
F_119 ( V_250 ) ;
V_2 -> V_6 . V_94 = 1 ;
V_2 -> V_6 . V_148 = V_108 -> V_251 - F_1 ( V_2 ) ;
F_55 ( V_252 , & V_2 -> V_125 ) ;
return 0 ;
}
int F_120 ( struct V_5 * V_5 , struct V_253 * V_254 ,
bool V_255 )
{
if ( ! F_62 ( V_5 ) )
return - V_256 ;
V_254 -> V_30 = F_121 ( V_5 , V_212 ,
V_254 -> V_257 , V_254 -> V_258 ,
V_255 ) ;
return 0 ;
}
long F_122 ( struct V_259 * V_260 ,
unsigned int V_261 , unsigned long V_262 )
{
struct V_5 * V_5 = V_260 -> V_263 ;
void T_7 * V_264 = ( void T_7 * ) V_262 ;
int V_53 = - V_265 ;
switch ( V_261 ) {
case V_266 :
V_53 = - V_267 ;
V_53 = F_123 ( V_5 ) ;
if ( V_53 )
goto V_164;
V_53 = F_124 ( V_5 ) ;
if ( V_53 ) {
F_125 ( & V_5 -> V_268 ) ;
F_126 ( V_5 ) ;
F_127 ( & V_5 -> V_268 ) ;
goto V_164;
}
break;
case V_269 : {
struct V_214 V_215 ;
V_53 = - V_267 ;
if ( F_128 ( & V_215 , V_264 , sizeof V_215 ) )
goto V_164;
V_53 = - V_256 ;
if ( ! F_62 ( V_5 ) )
goto V_164;
V_53 = F_114 ( V_5 , & V_215 ) ;
if ( V_53 )
goto V_164;
V_53 = - V_267 ;
if ( F_129 ( V_264 , & V_215 , sizeof V_215 ) )
goto V_164;
V_53 = 0 ;
break;
}
case V_270 : {
struct V_214 V_215 ;
V_53 = - V_267 ;
if ( F_128 ( & V_215 , V_264 , sizeof V_215 ) )
goto V_164;
V_53 = - V_256 ;
if ( ! F_62 ( V_5 ) )
goto V_164;
V_53 = F_116 ( V_5 , & V_215 ) ;
if ( V_53 )
goto V_164;
V_53 = 0 ;
break;
}
default:
;
}
V_164:
return V_53 ;
}
int F_130 ( struct V_1 * V_2 ,
struct V_271 * V_272 )
{
return - V_40 ;
}
int F_131 ( struct V_1 * V_2 ,
struct V_271 * V_272 )
{
return - V_40 ;
}
int F_132 ( struct V_1 * V_2 ,
struct V_273 * V_274 )
{
return - V_40 ;
}
static int F_133 ( void )
{
if ( ! V_36 && ( V_275 < V_276 ) ) {
V_36 = F_106 ( V_198 ,
F_107 ( V_277 ) ) ;
if ( ! V_36 )
return - V_278 ;
memset ( ( void * ) V_36 , 0 , V_277 ) ;
V_45 = V_36 + V_279 ;
F_23 ( V_50 L_12 ,
V_36 , V_45 ) ;
}
return 0 ;
}
static void F_134 ( void )
{
if ( V_36 ) {
memset ( ( void * ) V_36 , 0 , V_277 ) ;
F_135 ( V_36 , F_107 ( V_277 ) ) ;
V_36 = 0 ;
V_45 = 0 ;
V_42 = 0 ;
}
}
static int F_136 ( struct V_1 * V_2 )
{
int V_12 ;
union V_280 V_281 ;
struct V_24 * V_24 = F_42 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
if ( F_137 ( V_24 ) )
return F_138 ( V_24 ) ;
for ( V_12 = 0 ; V_12 < 5 ; V_12 ++ )
V_24 -> V_282 [ V_12 ] = F_139 ( V_12 ) ;
V_281 . V_283 = V_24 -> V_282 [ 3 ] ;
V_281 . V_284 = 4 ;
V_24 -> V_282 [ 3 ] = V_281 . V_283 ;
V_24 -> V_285 . V_286 = 1 ;
V_24 -> V_285 . V_287 = 1 ;
V_24 -> V_285 . V_288 = 1 ;
V_24 -> V_285 . V_289 = 1 ;
V_24 -> V_285 . V_290 = 1 ;
V_24 -> V_285 . V_291 = 1 ;
V_24 -> V_285 . V_292 = 1 ;
V_24 -> V_293 . V_294 = 1 ;
V_24 -> V_295 = V_46 ;
return 0 ;
}
static int F_140 ( struct V_1 * V_2 )
{
long V_296 ;
struct V_24 * V_24 = V_2 -> V_6 . V_24 ;
unsigned long V_297 ;
V_297 = V_187 -> V_297 ;
F_23 ( V_50 L_13 , V_2 , V_297 ) ;
V_296 = F_13 ( ( T_1 * ) V_24 , ( T_1 * ) V_297 , 0 ) ;
if ( V_296 ) {
F_23 ( V_86 L_14 ) ;
return - V_40 ;
}
return 0 ;
}
static void F_141 ( struct V_1 * V_2 )
{
T_8 V_298 = { 0 } ;
F_142 ( & V_298 ) ;
V_2 -> V_6 . V_21 = V_298 . V_299 ;
V_2 -> V_6 . V_22 [ 0 ] = V_298 . V_300 [ 0 ] ;
V_2 -> V_6 . V_22 [ 1 ] = V_298 . V_300 [ 1 ] ;
V_2 -> V_6 . V_23 [ 0 ] = V_298 . V_301 [ 0 ] ;
V_2 -> V_6 . V_23 [ 1 ] = V_298 . V_301 [ 1 ] ;
}
static void F_143 ( struct V_1 * V_2 )
{
struct V_144 * V_145 = & V_2 -> V_6 . V_146 ;
if ( F_68 ( V_145 ) )
F_144 ( V_145 , V_152 ) ;
}
static enum V_302 F_145 ( struct V_144 * V_83 )
{
struct V_1 * V_2 ;
T_9 * V_303 ;
V_2 = F_146 ( V_83 , struct V_1 , V_6 . V_146 ) ;
V_303 = & V_2 -> V_121 ;
if ( V_2 -> V_6 . V_119 != V_153 )
goto V_164;
if ( F_51 ( V_303 ) )
F_52 ( V_303 ) ;
V_164:
V_2 -> V_6 . V_304 = 1 ;
V_2 -> V_6 . V_150 = 1 ;
return V_305 ;
}
bool F_147 ( struct V_1 * V_2 )
{
return F_62 ( V_2 -> V_5 ) == ( V_2 -> V_6 . V_306 != NULL ) ;
}
int F_148 ( struct V_1 * V_2 )
{
struct V_1 * V_307 ;
int V_53 ;
int V_12 ;
long V_148 ;
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_107 * V_108 = F_50 ( V_2 ) ;
union V_175 * V_308 = & V_2 -> V_6 . V_228 ;
struct V_1 * V_309 = F_149 ( V_2 -> V_5 , V_2 ) ;
if ( F_137 ( V_309 ) )
return F_138 ( V_309 ) ;
if ( F_150 ( V_2 ) ) {
V_2 -> V_6 . V_119 = V_120 ;
V_108 -> V_114 = V_310 ;
V_148 = 0UL - F_1 ( V_2 ) ;
for ( V_12 = 0 ; V_12 < V_311 ; V_12 ++ ) {
V_307 = (struct V_1 * ) ( ( char * ) V_2 +
sizeof( struct V_312 ) * V_12 ) ;
V_307 -> V_6 . V_148 = V_148 ;
V_307 -> V_6 . V_241 = 0 ;
}
} else
V_2 -> V_6 . V_119 = V_131 ;
V_53 = - V_278 ;
V_2 -> V_6 . V_306 = F_151 ( sizeof( struct V_313 ) , V_198 ) ;
if ( ! V_2 -> V_6 . V_306 )
goto V_164;
V_2 -> V_6 . V_306 -> V_2 = V_2 ;
V_308 -> V_314 [ 1 ] = 0 ;
V_308 -> V_314 [ 12 ] = ( unsigned long ) ( ( char * ) V_309 + V_315 ) ;
V_308 -> V_314 [ 13 ] = ( unsigned long ) V_309 ;
V_308 -> V_170 = 0x1008522000UL ;
V_308 -> V_316 [ 40 ] = V_317 ;
V_308 -> V_318 = 0 ;
V_308 -> V_319 = 0x0 ;
V_308 -> V_316 [ 36 ] = 0x0 ;
V_308 -> V_316 [ 19 ] = 0x0 ;
V_308 -> V_316 [ 18 ] = ( unsigned long ) V_309 +
( ( sizeof( struct V_1 ) + 15 ) & ~ 15 ) ;
V_308 -> V_316 [ 64 ] = 0x0 ;
V_308 -> V_320 [ 0 ] = 0x7e04UL ;
V_308 -> V_320 [ 2 ] = ( unsigned long ) V_187 -> V_297 ;
V_308 -> V_320 [ 8 ] = 0x3c ;
V_308 -> V_321 [ 0 ] = 0x30 ;
V_308 -> V_321 [ 1 ] = 0x30 ;
V_308 -> V_321 [ 2 ] = 0x30 ;
V_308 -> V_321 [ 3 ] = 0x30 ;
V_308 -> V_321 [ 4 ] = 0x30 ;
V_308 -> V_321 [ 5 ] = 0x30 ;
V_308 -> V_321 [ 7 ] = 0x30 ;
V_308 -> V_322 [ 0 ] = * ( unsigned long * ) V_187 -> V_323 ;
V_2 -> V_6 . V_174 = V_5 -> V_6 . V_209 ;
V_2 -> V_6 . V_205 = V_5 -> V_6 . V_205 ;
V_2 -> V_6 . V_207 = V_5 -> V_6 . V_207 ;
F_152 ( & V_2 -> V_6 . V_146 , V_324 , V_152 ) ;
V_2 -> V_6 . V_146 . V_325 = F_145 ;
V_2 -> V_6 . V_171 = - 1 ;
V_2 -> V_6 . V_24 = (struct V_24 * ) F_153 ( V_2 -> V_326 ) ;
V_2 -> V_6 . V_327 = V_42 ;
V_2 -> V_6 . V_328 = V_329 ;
V_2 -> V_6 . V_330 = F_18 ( & V_5 -> V_6 . V_331 ) ;
V_2 -> V_6 . V_332 . V_333 = (struct V_231 * ) F_154 ( V_2 -> V_326 ) ;
V_2 -> V_6 . V_334 . V_333 = (struct V_231 * ) F_155 ( V_2 -> V_326 ) ;
F_141 ( V_2 ) ;
V_53 = 0 ;
V_164:
return V_53 ;
}
static int F_156 ( struct V_1 * V_2 , int V_101 )
{
unsigned long V_170 ;
int V_53 ;
F_10 ( V_170 ) ;
V_53 = F_78 ( V_2 ) ;
F_12 ( V_170 ) ;
if ( V_53 )
goto V_335;
V_53 = F_157 ( V_2 , V_2 -> V_5 , V_101 ) ;
if ( V_53 )
goto V_335;
V_53 = F_136 ( V_2 ) ;
if ( V_53 ) {
F_23 ( V_50 L_15 ) ;
goto V_336;
}
V_53 = F_140 ( V_2 ) ;
if ( V_53 )
goto V_336;
F_79 ( V_2 ) ;
return 0 ;
V_336:
F_158 ( V_2 ) ;
V_335:
return V_53 ;
}
struct V_1 * F_159 ( struct V_5 * V_5 ,
unsigned int V_101 )
{
struct V_1 * V_2 ;
unsigned long V_166 = V_5 -> V_6 . V_166 ;
int V_53 ;
int V_132 ;
F_105 ( sizeof( struct V_1 ) > V_337 / 2 ) ;
V_53 = - V_40 ;
if ( V_101 >= V_311 ) {
F_23 ( V_86 L_16 ,
V_311 ) ;
goto V_335;
}
V_53 = - V_278 ;
if ( ! V_166 ) {
F_23 ( V_86 L_17 , V_101 ) ;
goto V_335;
}
V_2 = (struct V_1 * ) ( V_166 + F_108 ( struct V_200 ,
V_338 [ V_101 ] . V_339 ) ) ;
V_2 -> V_5 = V_5 ;
V_132 = F_160 () ;
V_53 = F_156 ( V_2 , V_101 ) ;
F_161 () ;
if ( V_53 ) {
F_23 ( V_50 L_18 ) ;
goto V_335;
}
return V_2 ;
V_335:
return F_162 ( V_53 ) ;
}
int F_163 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_164 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_165 ( struct V_1 * V_2 , struct V_340 * V_341 )
{
return - V_40 ;
}
int F_166 ( struct V_1 * V_2 , struct V_340 * V_341 )
{
return - V_40 ;
}
int F_167 ( struct V_1 * V_2 ,
struct V_342 * V_343 )
{
return - V_40 ;
}
void F_168 ( struct V_5 * V_5 )
{
unsigned long V_166 = V_5 -> V_6 . V_166 ;
if ( V_166 ) {
memset ( ( void * ) V_166 , 0 , V_199 ) ;
F_135 ( V_166 , F_107 ( V_199 ) ) ;
}
}
static void F_169 ( struct V_5 * V_5 )
{
struct V_344 * V_345 ;
struct V_346 * V_347 ;
int V_13 ;
V_345 = V_344 ( V_5 ) ;
F_170 (memslot, slots) {
for ( V_13 = 0 ; V_13 < V_347 -> V_348 ; V_13 ++ ) {
if ( V_347 -> V_349 [ V_13 ] )
F_171 ( (struct V_350 * ) V_347 -> V_349 [ V_13 ] ) ;
}
}
}
void F_172 ( struct V_5 * V_5 )
{
}
void F_173 ( struct V_5 * V_5 )
{
F_174 ( V_5 ) ;
F_175 ( V_5 ) ;
F_176 ( V_5 -> V_6 . V_351 ) ;
F_169 ( V_5 ) ;
}
void F_177 ( struct V_1 * V_2 )
{
}
void F_178 ( struct V_1 * V_2 , int V_132 )
{
if ( V_132 != V_2 -> V_132 ) {
V_2 -> V_132 = V_132 ;
if ( V_2 -> V_6 . V_151 )
F_143 ( V_2 ) ;
}
}
int F_179 ( struct V_1 * V_2 , struct V_219 * V_108 )
{
struct V_24 * V_24 = F_42 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
int V_12 ;
F_180 ( V_2 ) ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
V_108 -> V_24 . V_220 [ V_12 ] = V_24 -> V_220 [ V_12 ] ;
V_108 -> V_24 . V_221 [ V_12 ] = V_24 -> V_221 [ V_12 ] ;
}
for ( V_12 = 0 ; V_12 < 128 ; V_12 ++ )
V_108 -> V_24 . V_222 [ V_12 ] = V_24 -> V_222 [ V_12 ] ;
V_108 -> V_24 . V_223 = V_24 -> V_223 ;
V_108 -> V_24 . V_224 = V_24 -> V_224 ;
V_108 -> V_24 . V_225 = V_24 -> V_225 ;
V_108 -> V_24 . V_226 = V_24 -> V_226 ;
V_108 -> V_24 . V_227 = V_24 -> V_227 ;
memcpy ( & V_108 -> V_229 , & V_2 -> V_6 . V_228 , sizeof( union V_175 ) ) ;
F_181 ( V_119 ) ;
F_181 ( V_174 ) ;
memcpy ( V_108 -> V_230 , V_2 -> V_6 . V_230 , sizeof( struct V_231 ) * V_232 ) ;
memcpy ( V_108 -> V_233 , V_2 -> V_6 . V_233 , sizeof( struct V_231 ) * V_234 ) ;
F_181 ( V_235 ) ;
F_181 ( V_236 ) ;
F_181 ( V_237 ) ;
F_181 ( V_238 ) ;
F_181 ( V_239 ) ;
F_181 ( V_150 ) ;
F_181 ( V_240 ) ;
F_181 ( V_241 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_108 -> V_242 [ V_12 ] = V_2 -> V_6 . V_242 [ V_12 ] ;
V_108 -> V_243 [ V_12 ] = V_2 -> V_6 . V_243 [ V_12 ] ;
V_108 -> V_244 [ V_12 ] = V_2 -> V_6 . V_244 [ V_12 ] ;
}
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ )
V_108 -> V_245 [ V_12 ] = V_2 -> V_6 . V_245 [ V_12 ] ;
V_108 -> V_251 = V_2 -> V_6 . V_148 + F_1 ( V_2 ) ;
F_181 ( V_246 ) ;
F_181 ( V_205 ) ;
F_181 ( V_207 ) ;
F_181 ( V_247 ) ;
F_181 ( V_248 ) ;
F_181 ( V_249 ) ;
F_181 ( V_250 ) ;
F_182 ( V_2 ) ;
return 0 ;
}
int F_183 ( struct V_1 * V_2 ,
struct V_352 * V_353 )
{
memcpy ( V_353 , V_2 , sizeof( struct V_352 ) ) ;
return 0 ;
}
int F_184 ( struct V_1 * V_2 ,
struct V_352 * V_353 )
{
memcpy ( V_2 + 1 , & V_353 -> V_353 [ 0 ] + sizeof( struct V_1 ) ,
sizeof( struct V_352 ) - sizeof( struct V_1 ) ) ;
V_2 -> V_6 . V_354 = ( (struct V_1 * ) V_353 ) -> V_6 . V_354 ;
return 0 ;
}
void F_185 ( struct V_1 * V_2 )
{
F_68 ( & V_2 -> V_6 . V_146 ) ;
F_176 ( V_2 -> V_6 . V_306 ) ;
}
long F_186 ( struct V_259 * V_260 ,
unsigned int V_261 , unsigned long V_262 )
{
struct V_1 * V_2 = V_260 -> V_263 ;
void T_7 * V_264 = ( void T_7 * ) V_262 ;
struct V_352 * V_353 = NULL ;
long V_53 ;
switch ( V_261 ) {
case V_355 : {
struct V_352 T_7 * V_356 ;
void T_7 * V_357 = V_264 ;
V_53 = - V_267 ;
if ( F_128 ( & V_356 , V_357 , sizeof( void * ) ) )
goto V_164;
if ( ! F_187 ( V_358 , V_356 ,
sizeof( struct V_352 ) ) ) {
F_23 ( V_48 L_19
L_20 ) ;
goto V_164;
}
V_353 = F_151 ( sizeof( struct V_352 ) , V_198 ) ;
if ( ! V_353 ) {
V_53 = - V_278 ;
goto V_164;
}
V_53 = F_183 ( V_2 , V_353 ) ;
if ( V_53 )
goto V_164;
if ( F_129 ( V_356 , V_353 ,
sizeof( struct V_352 ) ) ) {
V_53 = - V_267 ;
goto V_164;
}
break;
}
case V_359 : {
struct V_352 T_7 * V_356 ;
void T_7 * V_357 = V_264 ;
V_53 = - V_267 ;
if ( F_128 ( & V_356 , V_357 , sizeof( void * ) ) )
goto V_164;
if ( ! F_187 ( V_360 , V_356 ,
sizeof( struct V_352 ) ) ) {
F_23 ( V_48 L_21
L_22 ) ;
goto V_164;
}
V_353 = F_188 ( sizeof( struct V_352 ) , V_198 ) ;
if ( ! V_353 ) {
V_53 = - V_278 ;
goto V_164;
}
if ( F_128 ( V_353 , V_356 ,
sizeof( struct V_352 ) ) )
goto V_164;
V_53 = F_184 ( V_2 , V_353 ) ;
break;
}
default:
V_53 = - V_40 ;
}
V_164:
F_176 ( V_353 ) ;
return V_53 ;
}
int F_189 ( struct V_1 * V_2 , struct V_361 * V_362 )
{
return V_363 ;
}
void F_190 ( struct V_5 * V_5 , struct V_346 * free ,
struct V_346 * V_364 )
{
}
int F_191 ( struct V_5 * V_5 , struct V_346 * V_35 ,
unsigned long V_348 )
{
return 0 ;
}
void F_192 ( struct V_5 * V_5 )
{
}
int F_193 ( struct V_5 * V_5 ,
struct V_346 * V_347 ,
struct V_365 * V_366 ,
enum V_367 V_368 )
{
unsigned long V_12 ;
unsigned long V_369 ;
int V_348 = V_347 -> V_348 ;
unsigned long V_370 = V_347 -> V_370 ;
if ( V_370 + V_348 > ( V_371 >> V_138 ) )
return - V_278 ;
for ( V_12 = 0 ; V_12 < V_348 ; V_12 ++ ) {
V_369 = F_194 ( V_5 , V_370 + V_12 ) ;
if ( ! F_195 ( V_369 ) ) {
F_110 ( V_5 , V_370 + V_12 ,
V_369 << V_138 ,
V_372 | V_373 ) ;
V_347 -> V_349 [ V_12 ] = ( unsigned long ) F_196 ( V_369 ) ;
} else {
F_110 ( V_5 , V_370 + V_12 ,
V_374 | ( V_369 << V_138 ) ,
V_375 ) ;
V_347 -> V_349 [ V_12 ] = 0 ;
}
}
return 0 ;
}
void F_197 ( struct V_5 * V_5 ,
struct V_365 * V_366 ,
const struct V_346 * V_376 ,
enum V_367 V_368 )
{
return;
}
void F_198 ( struct V_5 * V_5 )
{
F_199 ( V_5 ) ;
}
void F_200 ( struct V_5 * V_5 ,
struct V_346 * V_35 )
{
F_198 () ;
}
long F_201 ( struct V_259 * V_260 ,
unsigned int V_261 , unsigned long V_262 )
{
return - V_40 ;
}
void F_202 ( struct V_1 * V_2 )
{
F_158 ( V_2 ) ;
}
static int F_203 ( void )
{
long V_377 = 1 , V_30 = 1 , V_378 = 1 ;
long V_296 ;
V_296 = F_204 ( & V_377 , & V_30 , & V_378 , 0 ) ;
if ( V_296 )
goto V_164;
if ( ! ( V_377 & V_379 ) )
goto V_164;
F_23 ( V_50 L_23 ) ;
V_296 = F_205 ( & V_275 , & V_380 ) ;
if ( V_296 )
goto V_164;
F_23 ( V_50 L_24 , V_275 ) ;
if ( ! ( V_380 & V_381 ) ) {
F_23 ( V_47 L_25
L_26 , V_380 ) ;
}
return 1 ;
V_164:
return 0 ;
}
static void F_206 ( struct V_187 * V_382 ,
struct V_383 * V_383 )
{
unsigned long V_384 , V_385 ;
unsigned long V_386 ;
if ( ! F_112 ( L_11 ) )
return;
V_386 = ( unsigned long ) V_383 -> V_387 ;
V_384 = V_36 + V_382 -> V_388 - V_386 ;
V_385 = V_36 + V_382 -> V_389 - V_386 ;
F_23 ( V_48 L_27
L_28 ) ;
memcpy ( ( void * ) V_384 , ( void * ) V_385 , 0x60 ) ;
}
static int F_207 ( struct V_187 * V_382 ,
struct V_383 * V_383 )
{
unsigned long V_386 ;
unsigned long V_390 ;
unsigned long V_391 , V_392 , V_393 ;
struct V_394 * V_395 ;
F_105 ( ! V_383 ) ;
if ( ! V_36 ) {
F_23 ( L_29 ) ;
return - V_267 ;
}
V_386 = ( unsigned long ) V_383 -> V_387 ;
V_390 = V_383 -> V_396 ;
if ( F_103 ( V_390 > V_277 ) )
return - V_267 ;
memcpy ( ( void * ) V_36 , ( void * ) V_386 , V_390 ) ;
F_206 ( V_382 , V_383 ) ;
F_5 ( V_36 , V_390 ) ;
V_391 = V_382 -> V_297 - V_386 ;
V_187 -> V_297 = V_38 + V_391 ;
F_23 ( V_50 L_30 ,
V_187 -> V_297 ) ;
V_393 = ( unsigned long ) V_382 -> V_323 - V_386 ;
V_187 -> V_323 = ( V_397 * ) ( V_38 +
V_393 ) ;
V_392 = * ( unsigned long * ) V_382 -> V_323 - V_386 ;
V_395 = (struct V_394 * ) ( V_36 + V_393 ) ;
V_395 -> V_398 = V_38 + V_392 ;
V_395 -> V_399 = V_38 + ( V_395 -> V_399 - V_386 ) ;
F_23 ( V_50 L_31 ,
V_38 + V_392 ) ;
V_393 = ( unsigned long ) V_382 -> V_188 - V_386 ;
V_187 -> V_188 = ( V_400 * ) ( V_38 +
V_393 ) ;
V_392 = * ( unsigned long * ) V_382 -> V_188 - V_386 ;
V_395 = (struct V_394 * ) ( V_36 + V_393 ) ;
V_395 -> V_398 = V_38 + V_392 ;
V_395 -> V_399 = V_38 + ( V_395 -> V_399 - V_386 ) ;
V_329 = V_395 -> V_399 ;
F_23 ( V_50 L_32 ,
V_187 -> V_323 ) ;
F_23 ( V_50 L_33 ,
V_38 + V_392 ) ;
return 0 ;
}
int F_208 ( void * V_401 )
{
int V_53 ;
struct V_187 * V_382 = (struct V_187 * ) V_401 ;
if ( ! F_203 () ) {
F_23 ( V_86 L_34 ) ;
V_53 = - V_402 ;
goto V_164;
}
if ( V_187 ) {
F_23 ( V_86 L_35 ) ;
V_53 = - V_403 ;
goto V_164;
}
V_53 = - V_278 ;
V_187 = F_151 ( sizeof( struct V_187 ) , V_198 ) ;
if ( ! V_187 )
goto V_164;
if ( F_133 () )
goto V_404;
V_53 = F_207 ( V_382 , V_382 -> V_383 ) ;
if ( V_53 )
goto V_405;
return 0 ;
V_405:
F_134 () ;
V_404:
F_176 ( V_187 ) ;
V_164:
return V_53 ;
}
void F_209 ( void )
{
F_134 () ;
F_176 ( V_187 ) ;
V_187 = NULL ;
}
static void F_210 ( struct V_5 * V_5 ,
struct V_346 * V_347 )
{
int V_12 ;
long V_299 ;
unsigned long V_406 ;
unsigned long * V_407 = ( unsigned long * ) ( V_5 -> V_6 . V_166 +
F_108 ( struct V_200 , V_408 ) ) ;
V_406 = F_211 ( V_347 ) ;
V_299 = V_347 -> V_370 / V_409 ;
F_20 ( & V_5 -> V_6 . V_331 ) ;
for ( V_12 = 0 ; V_12 < V_406 / sizeof( long ) ; ++ V_12 ) {
V_347 -> V_407 [ V_12 ] = V_407 [ V_299 + V_12 ] ;
V_407 [ V_299 + V_12 ] = 0 ;
}
F_22 ( & V_5 -> V_6 . V_331 ) ;
}
int F_212 ( struct V_5 * V_5 ,
struct V_410 * log )
{
int V_53 ;
unsigned long V_406 ;
struct V_346 * V_347 ;
int V_411 = 0 ;
F_125 ( & V_5 -> V_268 ) ;
V_53 = - V_40 ;
if ( log -> V_35 >= V_412 )
goto V_164;
V_347 = F_213 ( V_5 -> V_413 , log -> V_35 ) ;
V_53 = - V_414 ;
if ( ! V_347 -> V_407 )
goto V_164;
F_210 ( V_5 , V_347 ) ;
V_53 = F_214 ( V_5 , log , & V_411 ) ;
if ( V_53 )
goto V_164;
if ( V_411 ) {
F_199 ( V_5 ) ;
V_406 = F_211 ( V_347 ) ;
memset ( V_347 -> V_407 , 0 , V_406 ) ;
}
V_53 = 0 ;
V_164:
F_127 ( & V_5 -> V_268 ) ;
return V_53 ;
}
int F_215 ( void )
{
return 0 ;
}
void F_216 ( void )
{
}
int F_217 ( struct V_1 * V_2 , struct V_415 * V_257 )
{
return F_41 ( V_2 , V_257 -> V_92 ) ;
}
int F_218 ( struct V_313 * V_306 , T_10 V_416 )
{
return V_306 -> V_2 -> V_326 == V_416 ;
}
int F_219 ( struct V_313 * V_306 , T_11 V_417 )
{
return 0 ;
}
int F_220 ( struct V_1 * V_418 , struct V_1 * V_419 )
{
return V_418 -> V_6 . V_246 - V_419 -> V_6 . V_246 ;
}
int F_221 ( struct V_1 * V_2 , struct V_313 * V_420 ,
int V_421 , int V_416 , int V_422 )
{
struct V_313 * V_423 = V_2 -> V_6 . V_306 ;
return ( V_422 == 0 ) ?
F_218 ( V_423 , V_416 ) :
F_219 ( V_423 , V_416 ) ;
}
static int F_222 ( int * V_424 )
{
T_5 V_425 , V_426 ;
int V_12 ;
for ( V_12 = 7 ; V_12 >= 0 ; V_12 -- ) {
V_425 = V_424 [ V_12 ] ;
if ( V_425 ) {
V_426 = F_223 ( V_425 ) ;
return V_12 * 32 + V_426 - 1 ;
}
}
return - 1 ;
}
int F_224 ( struct V_1 * V_2 )
{
struct V_24 * V_24 = F_42 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
if ( V_24 -> V_93 [ 0 ] & ( 1UL << V_427 ) )
return V_427 ;
if ( V_24 -> V_93 [ 0 ] & ( 1UL << V_428 ) )
return V_428 ;
return F_222 ( ( int * ) & V_24 -> V_93 [ 0 ] ) ;
}
int F_70 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_304 ;
}
int F_225 ( struct V_1 * V_2 )
{
return ( V_2 -> V_6 . V_119 == V_120 ) ||
( F_224 ( V_2 ) != - 1 ) ;
}
int F_226 ( struct V_1 * V_2 )
{
return ( ! F_43 ( V_183 , & V_2 -> V_125 ) ) ;
}
int F_227 ( struct V_1 * V_2 ,
struct V_429 * V_119 )
{
V_119 -> V_119 = V_2 -> V_6 . V_119 ;
return 0 ;
}
static int F_228 ( struct V_1 * V_2 )
{
int V_53 ;
long V_170 ;
F_10 ( V_170 ) ;
V_53 = F_78 ( V_2 ) ;
F_12 ( V_170 ) ;
if ( V_53 )
goto V_335;
V_2 -> V_6 . V_113 = 0 ;
F_185 ( V_2 ) ;
V_53 = F_148 ( V_2 ) ;
if ( V_53 )
goto V_335;
F_79 ( V_2 ) ;
V_53 = 0 ;
V_335:
return V_53 ;
}
int F_229 ( struct V_1 * V_2 ,
struct V_429 * V_119 )
{
int V_53 = 0 ;
V_2 -> V_6 . V_119 = V_119 -> V_119 ;
if ( V_2 -> V_6 . V_119 == V_131 )
V_53 = F_228 ( V_2 ) ;
return V_53 ;
}
