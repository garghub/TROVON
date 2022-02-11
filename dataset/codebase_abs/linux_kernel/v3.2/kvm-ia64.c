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
V_53 = 1 ;
break;
case V_57 :
V_53 = V_58 ;
break;
case V_59 :
V_53 = F_29 ( & V_60 ) ;
break;
default:
V_53 = 0 ;
}
return V_53 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
V_61 -> V_62 = V_63 ;
V_61 -> V_64 . V_65 = 1 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
struct V_66 * V_67 ;
struct V_68 * V_69 ;
int V_53 ;
V_67 = F_32 ( V_2 ) ;
if ( ( V_67 -> V_18 & V_70 ) == V_71 )
goto V_72;
V_2 -> V_73 = 1 ;
V_2 -> V_74 = V_61 -> V_72 . V_75 = V_67 -> V_18 ;
V_2 -> V_76 = V_61 -> V_72 . V_10 = V_67 -> V_77 ;
V_2 -> V_78 = V_61 -> V_72 . V_79 = ! V_67 -> V_80 ;
if ( V_2 -> V_78 )
memcpy ( V_2 -> V_81 , & V_67 -> V_82 , V_67 -> V_77 ) ;
memcpy ( V_61 -> V_72 . V_82 , & V_67 -> V_82 , V_67 -> V_77 ) ;
V_61 -> V_62 = V_83 ;
return 0 ;
V_72:
if ( V_67 -> V_80 )
V_53 = F_33 ( V_2 -> V_5 , V_84 , V_67 -> V_18 ,
V_67 -> V_77 , & V_67 -> V_82 ) ;
else
V_53 = F_34 ( V_2 -> V_5 , V_84 , V_67 -> V_18 ,
V_67 -> V_77 , & V_67 -> V_82 ) ;
if ( V_53 )
F_23 ( V_85 L_4 , V_67 -> V_18 ) ;
V_67 -> V_86 = V_87 ;
return 1 ;
}
static int F_35 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
struct V_88 * V_67 ;
V_67 = F_36 ( V_2 ) ;
if ( V_67 -> V_62 == V_89 )
return F_37 ( V_2 , V_61 ) ;
else {
V_61 -> V_62 = V_63 ;
V_61 -> V_64 . V_65 = 2 ;
return 0 ;
}
}
static int F_38 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
struct V_88 * V_67 ;
V_67 = F_36 ( V_2 ) ;
if ( V_67 -> V_62 == V_90 ) {
F_39 ( V_2 ) ;
return 1 ;
} else {
V_61 -> V_62 = V_63 ;
V_61 -> V_64 . V_65 = 3 ;
return 0 ;
}
}
static int F_40 ( struct V_1 * V_2 , T_2 V_91 )
{
struct V_24 * V_24 = F_41 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
if ( ! F_42 ( V_91 , & V_24 -> V_92 [ 0 ] ) ) {
V_2 -> V_6 . V_93 = 1 ;
F_43 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static void F_44 ( struct V_1 * V_2 , T_2 V_94 ,
T_2 V_91 )
{
switch ( V_94 ) {
case V_95 :
break;
case V_96 :
V_91 = 2 ;
break;
case V_97 :
V_91 = 0 ;
break;
case V_98 :
case V_99 :
default:
F_23 ( V_85 L_5 ) ;
return;
}
F_40 ( V_2 , V_91 ) ;
}
static struct V_1 * F_45 ( struct V_5 * V_5 , unsigned long V_100 ,
unsigned long V_101 )
{
union V_102 V_103 ;
int V_12 ;
struct V_1 * V_2 ;
F_46 (i, vcpu, kvm) {
V_103 . V_104 = F_47 ( V_2 ) ;
if ( V_103 . V_100 == V_100 && V_103 . V_101 == V_101 )
return V_2 ;
}
return NULL ;
}
static int F_48 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
struct V_88 * V_67 = F_36 ( V_2 ) ;
struct V_1 * V_105 ;
struct V_106 * V_107 ;
union V_108 V_18 = V_67 -> V_109 . V_110 . V_18 ;
union V_111 V_82 = V_67 -> V_109 . V_110 . V_82 ;
V_105 = F_45 ( V_2 -> V_5 , V_18 . V_100 , V_18 . V_101 ) ;
if ( ! V_105 )
return F_30 ( V_2 , V_61 ) ;
if ( ! V_105 -> V_6 . V_112 ) {
V_107 = F_49 ( V_105 ) ;
V_107 -> V_113 = V_2 -> V_5 -> V_6 . V_114 . V_115 ;
V_107 -> V_116 = V_2 -> V_5 -> V_6 . V_114 . V_117 ;
V_105 -> V_6 . V_118 = V_119 ;
if ( F_50 ( & V_105 -> V_120 ) )
F_51 ( & V_105 -> V_120 ) ;
} else {
F_44 ( V_105 , V_82 . V_94 , V_82 . V_91 ) ;
if ( V_105 != V_2 )
F_43 ( V_105 ) ;
}
return 1 ;
}
static void F_52 ( void * V_121 )
{
struct V_122 * V_67 = (struct V_122 * ) V_121 ;
struct V_1 * V_2 = V_67 -> V_2 ;
if ( F_53 ( V_123 , & V_2 -> V_124 ) )
return;
F_54 ( V_125 , & V_2 -> V_124 ) ;
if ( V_2 -> V_6 . V_126 < V_127 ) {
V_2 -> V_6 . V_128 [ V_2 -> V_6 . V_126 ++ ] =
V_67 -> V_128 ;
} else {
F_55 ( V_125 , & V_2 -> V_124 ) ;
V_2 -> V_6 . V_126 = 0 ;
F_54 ( V_123 , & V_2 -> V_124 ) ;
}
}
static int F_56 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
struct V_88 * V_67 = F_36 ( V_2 ) ;
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_122 V_122 ;
int V_12 ;
struct V_1 * V_129 ;
V_122 . V_128 = V_67 -> V_109 . V_128 ;
F_46 (i, vcpui, kvm) {
if ( V_129 -> V_6 . V_118 == V_130 ||
V_2 == V_129 )
continue;
if ( F_50 ( & V_129 -> V_120 ) )
F_51 ( & V_129 -> V_120 ) ;
if ( V_129 -> V_131 != - 1 ) {
V_122 . V_2 = V_129 ;
F_57 ( V_129 -> V_131 ,
F_52 , & V_122 , 1 ) ;
} else
F_23 ( V_47 L_6 ) ;
}
return 1 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
return 1 ;
}
static int F_59 ( struct V_1 * V_2 )
{
unsigned long V_33 , V_132 , V_133 ;
int V_35 ;
V_133 = V_38 + ( 1UL << V_39 ) ;
V_132 = V_134 | V_135 ;
V_33 = F_16 ( F_17 ( V_132 , V_136 ) ) ;
V_35 = F_19 ( 0x3 , V_133 , V_33 , V_137 ) ;
V_2 -> V_6 . V_138 = V_35 ;
if ( V_35 < 0 ) {
F_23 ( V_85 L_7 ) ;
V_35 = 0 ;
}
return V_35 ;
}
int F_60 ( struct V_1 * V_2 )
{
T_3 V_139 ;
long V_140 ;
unsigned long V_141 ;
unsigned long V_142 ;
struct V_143 * V_144 = & V_2 -> V_6 . V_145 ;
unsigned long V_146 = V_20 -> V_146 ;
struct V_24 * V_24 = F_41 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
if ( F_61 ( V_2 -> V_5 ) ) {
V_141 = F_1 ( V_2 ) + V_2 -> V_6 . V_147 ;
if ( F_62 ( V_141 , V_24 -> V_148 ) ) {
V_2 -> V_6 . V_149 = 1 ;
return 1 ;
}
V_140 = V_24 -> V_148 - V_141 ;
if ( V_140 < 0 )
V_140 = - V_140 ;
V_142 = F_63 ( V_140 , V_146 ) ;
V_139 = F_64 ( 0 , 1000 * V_142 ) ;
V_2 -> V_6 . V_150 = 1 ;
F_65 ( V_144 , V_139 , V_151 ) ;
V_2 -> V_6 . V_118 = V_152 ;
F_66 ( V_2 ) ;
F_67 ( V_144 ) ;
V_2 -> V_6 . V_150 = 0 ;
if ( F_68 ( V_153 , & V_2 -> V_124 ) ||
F_69 ( V_2 ) )
if ( V_2 -> V_6 . V_118 == V_152 )
V_2 -> V_6 . V_118 = V_119 ;
if ( V_2 -> V_6 . V_118 != V_119 )
return - V_154 ;
return 1 ;
} else {
F_23 ( V_85 L_8 ) ;
return 0 ;
}
}
static int F_70 ( struct V_1 * V_2 ,
struct V_61 * V_61 )
{
V_61 -> V_62 = V_155 ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_61 * V_61 )
{
return 1 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_61 * V_61 )
{
F_23 ( L_9 , V_2 -> V_6 . V_156 ) ;
return 1 ;
}
static T_4 F_73 ( struct V_1 * V_2 )
{
struct V_88 * V_157 ;
V_157 = F_36 ( V_2 ) ;
return V_157 -> V_62 ;
}
static int F_74 ( struct V_61 * V_61 , struct V_1 * V_2 )
{
T_5 V_62 = F_73 ( V_2 ) ;
V_2 -> V_6 . V_158 = V_62 ;
if ( V_62 < V_159
&& V_160 [ V_62 ] )
return V_160 [ V_62 ] ( V_2 , V_61 ) ;
else {
V_61 -> V_62 = V_63 ;
V_61 -> V_64 . V_65 = V_62 ;
}
return 0 ;
}
static inline void F_75 ( unsigned long V_161 )
{
F_76 ( V_162 , V_161 ) ;
F_8 () ;
}
static int F_77 ( struct V_1 * V_2 )
{
unsigned long V_33 ;
struct V_5 * V_5 = V_2 -> V_5 ;
int V_53 ;
V_33 = F_16 ( F_17 ( F_18 ( V_36 ) , V_37 ) ) ;
V_53 = F_19 ( 0x3 , V_38 , V_33 , V_39 ) ;
if ( V_53 < 0 )
goto V_163;
V_2 -> V_6 . V_164 = V_53 ;
V_33 = F_16 ( F_17 ( F_18 ( V_5 -> V_6 . V_165 ) , V_37 ) ) ;
V_53 = F_19 ( 0x3 , V_166 ,
V_33 , V_167 ) ;
if ( V_53 < 0 )
goto V_163;
V_2 -> V_6 . V_168 = V_53 ;
#if F_2 ( V_3 ) || F_2 ( V_4 )
if ( V_5 -> V_6 . V_7 ) {
V_53 = F_59 ( V_2 ) ;
if ( V_53 < 0 )
goto V_163;
}
#endif
V_53 = 0 ;
V_163:
return V_53 ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
F_24 ( 0x3 , V_2 -> V_6 . V_164 ) ;
F_24 ( 0x3 , V_2 -> V_6 . V_168 ) ;
#if F_2 ( V_3 ) || F_2 ( V_4 )
if ( V_5 -> V_6 . V_7 )
F_24 ( 0x3 , V_2 -> V_6 . V_138 ) ;
#endif
}
static int F_79 ( struct V_1 * V_2 )
{
unsigned long V_169 ;
int V_53 ;
int V_131 = F_80 () ;
if ( V_2 -> V_6 . V_170 != V_131 ||
F_81 ( V_171 , V_131 ) != V_2 ) {
F_81 ( V_171 , V_131 ) = V_2 ;
V_2 -> V_6 . V_170 = V_131 ;
F_9 () ;
}
V_2 -> V_6 . V_172 = F_82 ( V_162 ) ;
F_75 ( V_2 -> V_6 . V_173 ) ;
F_10 ( V_169 ) ;
V_53 = F_77 ( V_2 ) ;
F_12 ( V_169 ) ;
return V_53 ;
}
static void F_83 ( struct V_1 * V_2 )
{
F_78 ( V_2 ) ;
F_75 ( V_2 -> V_6 . V_172 ) ;
}
static int F_84 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
union V_174 * V_175 , * V_176 ;
int V_53 , V_177 ;
V_177 = F_85 ( & V_2 -> V_5 -> V_178 ) ;
V_179:
if ( F_86 ( V_180 ) ) {
V_53 = - V_154 ;
V_61 -> V_62 = V_181 ;
goto V_163;
}
F_87 () ;
F_88 () ;
V_175 = F_89 ( V_2 ) ;
V_176 = F_90 ( V_2 ) ;
F_55 ( V_182 , & V_2 -> V_124 ) ;
V_53 = F_79 ( V_2 ) ;
if ( V_53 < 0 )
goto V_183;
F_91 ( & V_2 -> V_5 -> V_178 , V_177 ) ;
V_2 -> V_184 = V_185 ;
F_92 () ;
V_186 -> V_187 ( V_175 , V_176 ) ;
F_83 ( V_2 ) ;
V_2 -> V_6 . V_112 = 1 ;
F_54 ( V_182 , & V_2 -> V_124 ) ;
F_93 () ;
F_94 () ;
F_95 () ;
V_2 -> V_184 = V_188 ;
F_96 () ;
V_177 = F_85 ( & V_2 -> V_5 -> V_178 ) ;
V_53 = F_74 ( V_61 , V_2 ) ;
if ( V_53 > 0 ) {
if ( ! F_97 () )
goto V_179;
}
V_163:
F_91 ( & V_2 -> V_5 -> V_178 , V_177 ) ;
if ( V_53 > 0 ) {
F_98 ( V_2 ) ;
V_177 = F_85 ( & V_2 -> V_5 -> V_178 ) ;
goto V_179;
}
return V_53 ;
V_183:
F_93 () ;
F_96 () ;
V_61 -> V_62 = V_189 ;
goto V_163;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = F_32 ( V_2 ) ;
if ( ! V_2 -> V_78 )
memcpy ( & V_67 -> V_82 , V_2 -> V_81 , 8 ) ;
V_67 -> V_86 = V_87 ;
}
int F_100 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
int V_53 ;
T_6 V_190 ;
if ( V_2 -> V_191 )
F_101 ( V_192 , & V_2 -> V_193 , & V_190 ) ;
if ( F_102 ( V_2 -> V_6 . V_118 == V_130 ) ) {
F_66 ( V_2 ) ;
F_55 ( V_153 , & V_2 -> V_124 ) ;
V_53 = - V_194 ;
goto V_163;
}
if ( V_2 -> V_73 ) {
memcpy ( V_2 -> V_81 , V_61 -> V_72 . V_82 , 8 ) ;
F_99 ( V_2 ) ;
V_2 -> V_195 = 1 ;
V_2 -> V_73 = 0 ;
}
V_53 = F_84 ( V_2 , V_61 ) ;
V_163:
if ( V_2 -> V_191 )
F_101 ( V_192 , & V_190 , NULL ) ;
return V_53 ;
}
struct V_5 * F_103 ( void )
{
struct V_5 * V_5 ;
T_2 V_165 ;
F_104 ( sizeof( struct V_5 ) > V_196 ) ;
V_165 = F_105 ( V_197 , F_106 ( V_198 ) ) ;
if ( ! V_165 )
return NULL ;
memset ( ( void * ) V_165 , 0 , V_198 ) ;
V_5 = (struct V_5 * ) ( V_165 +
F_107 ( struct V_199 , V_200 ) ) ;
V_5 -> V_6 . V_165 = V_165 ;
F_23 ( V_50 L_10 , V_165 ) ;
return V_5 ;
}
static void F_108 ( struct V_5 * V_5 )
{
unsigned long V_12 , V_13 ;
for ( V_12 = 0 ; V_12 < ( sizeof( V_201 ) / sizeof( struct V_202 ) ) ;
V_12 ++ ) {
for ( V_13 = V_201 [ V_12 ] . V_9 ;
V_13 < V_201 [ V_12 ] . V_9 + V_201 [ V_12 ] . V_77 ;
V_13 += V_203 )
F_109 ( V_5 , V_13 >> V_137 ,
V_201 [ V_12 ] . type , 0 ) ;
}
}
int F_110 ( struct V_5 * V_5 )
{
F_104 ( ! V_5 ) ;
V_5 -> V_6 . V_7 = F_111 ( L_11 ) ;
V_5 -> V_6 . V_204 = V_205 ;
V_5 -> V_6 . V_206 = V_207 ;
V_5 -> V_6 . V_208 = V_209 ;
F_108 ( V_5 ) ;
F_112 ( & V_5 -> V_6 . V_210 ) ;
F_54 ( V_211 , & V_5 -> V_6 . V_212 ) ;
return 0 ;
}
static int F_113 ( struct V_5 * V_5 ,
struct V_213 * V_214 )
{
int V_53 ;
V_53 = 0 ;
switch ( V_214 -> V_215 ) {
case V_216 :
V_53 = F_114 ( V_5 , & V_214 -> V_214 . V_217 ) ;
break;
default:
V_53 = - V_40 ;
break;
}
return V_53 ;
}
static int F_115 ( struct V_5 * V_5 , struct V_213 * V_214 )
{
int V_53 ;
V_53 = 0 ;
switch ( V_214 -> V_215 ) {
case V_216 :
V_53 = F_116 ( V_5 , & V_214 -> V_214 . V_217 ) ;
break;
default:
V_53 = - V_40 ;
break;
}
return V_53 ;
}
int F_117 ( struct V_1 * V_2 , struct V_218 * V_107 )
{
struct V_24 * V_24 = F_41 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
V_24 -> V_219 [ V_12 ] = V_107 -> V_24 . V_219 [ V_12 ] ;
V_24 -> V_220 [ V_12 ] = V_107 -> V_24 . V_220 [ V_12 ] ;
}
for ( V_12 = 0 ; V_12 < 128 ; V_12 ++ )
V_24 -> V_221 [ V_12 ] = V_107 -> V_24 . V_221 [ V_12 ] ;
V_24 -> V_222 = V_107 -> V_24 . V_222 ;
V_24 -> V_223 = V_107 -> V_24 . V_223 ;
V_24 -> V_224 = V_107 -> V_24 . V_224 ;
V_24 -> V_225 = V_107 -> V_24 . V_225 ;
V_24 -> V_226 = V_107 -> V_24 . V_226 ;
memcpy ( & V_2 -> V_6 . V_227 , & V_107 -> V_228 , sizeof( union V_174 ) ) ;
F_118 ( V_118 ) ;
F_118 ( V_173 ) ;
memcpy ( V_2 -> V_6 . V_229 , V_107 -> V_229 , sizeof( struct V_230 ) * V_231 ) ;
memcpy ( V_2 -> V_6 . V_232 , V_107 -> V_232 , sizeof( struct V_230 ) * V_233 ) ;
F_118 ( V_234 ) ;
F_118 ( V_235 ) ;
F_118 ( V_236 ) ;
F_118 ( V_237 ) ;
F_118 ( V_238 ) ;
F_118 ( V_149 ) ;
F_118 ( V_239 ) ;
F_118 ( V_240 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_2 -> V_6 . V_241 [ V_12 ] = V_107 -> V_241 [ V_12 ] ;
V_2 -> V_6 . V_242 [ V_12 ] = V_107 -> V_242 [ V_12 ] ;
V_2 -> V_6 . V_243 [ V_12 ] = V_107 -> V_243 [ V_12 ] ;
}
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ )
V_2 -> V_6 . V_244 [ V_12 ] = V_107 -> V_244 [ V_12 ] ;
F_118 ( V_245 ) ;
F_118 ( V_204 ) ;
F_118 ( V_206 ) ;
F_118 ( V_246 ) ;
F_118 ( V_247 ) ;
F_118 ( V_248 ) ;
F_118 ( V_249 ) ;
V_2 -> V_6 . V_93 = 1 ;
V_2 -> V_6 . V_147 = V_107 -> V_250 - F_1 ( V_2 ) ;
F_54 ( V_251 , & V_2 -> V_124 ) ;
return 0 ;
}
long F_119 ( struct V_252 * V_253 ,
unsigned int V_254 , unsigned long V_255 )
{
struct V_5 * V_5 = V_253 -> V_256 ;
void T_7 * V_257 = ( void T_7 * ) V_255 ;
int V_53 = - V_258 ;
switch ( V_254 ) {
case V_259 : {
struct V_260 V_261 ;
struct V_262 V_263 ;
V_53 = - V_264 ;
if ( F_120 ( & V_261 , V_257 , sizeof V_261 ) )
goto V_163;
V_263 . V_35 = V_261 . V_35 ;
V_263 . V_19 = V_261 . V_19 ;
V_263 . V_265 =
V_261 . V_265 ;
V_263 . V_266 = V_261 . V_266 ;
V_53 = F_121 ( V_5 ,
& V_263 , 0 ) ;
if ( V_53 )
goto V_163;
break;
}
case V_267 :
V_53 = - V_264 ;
V_53 = F_122 ( V_5 ) ;
if ( V_53 )
goto V_163;
V_53 = F_123 ( V_5 ) ;
if ( V_53 ) {
F_124 ( & V_5 -> V_268 ) ;
F_125 ( V_5 ) ;
F_126 ( & V_5 -> V_268 ) ;
goto V_163;
}
break;
case V_269 :
case V_270 : {
struct V_271 V_272 ;
V_53 = - V_264 ;
if ( F_120 ( & V_272 , V_257 , sizeof V_272 ) )
goto V_163;
V_53 = - V_273 ;
if ( F_61 ( V_5 ) ) {
T_8 V_30 ;
V_30 = F_127 ( V_5 , V_211 ,
V_272 . V_274 , V_272 . V_275 ) ;
if ( V_254 == V_269 ) {
V_53 = - V_264 ;
V_272 . V_30 = V_30 ;
if ( F_128 ( V_257 , & V_272 ,
sizeof V_272 ) )
goto V_163;
}
V_53 = 0 ;
}
break;
}
case V_276 : {
struct V_213 V_214 ;
V_53 = - V_264 ;
if ( F_120 ( & V_214 , V_257 , sizeof V_214 ) )
goto V_163;
V_53 = - V_273 ;
if ( ! F_61 ( V_5 ) )
goto V_163;
V_53 = F_113 ( V_5 , & V_214 ) ;
if ( V_53 )
goto V_163;
V_53 = - V_264 ;
if ( F_128 ( V_257 , & V_214 , sizeof V_214 ) )
goto V_163;
V_53 = 0 ;
break;
}
case V_277 : {
struct V_213 V_214 ;
V_53 = - V_264 ;
if ( F_120 ( & V_214 , V_257 , sizeof V_214 ) )
goto V_163;
V_53 = - V_273 ;
if ( ! F_61 ( V_5 ) )
goto V_163;
V_53 = F_115 ( V_5 , & V_214 ) ;
if ( V_53 )
goto V_163;
V_53 = 0 ;
break;
}
default:
;
}
V_163:
return V_53 ;
}
int F_129 ( struct V_1 * V_2 ,
struct V_278 * V_279 )
{
return - V_40 ;
}
int F_130 ( struct V_1 * V_2 ,
struct V_278 * V_279 )
{
return - V_40 ;
}
int F_131 ( struct V_1 * V_2 ,
struct V_280 * V_281 )
{
return - V_40 ;
}
static int F_132 ( void )
{
if ( ! V_36 && ( V_282 < V_283 ) ) {
V_36 = F_105 ( V_197 ,
F_106 ( V_284 ) ) ;
if ( ! V_36 )
return - V_285 ;
memset ( ( void * ) V_36 , 0 , V_284 ) ;
V_45 = V_36 + V_286 ;
F_23 ( V_50 L_12 ,
V_36 , V_45 ) ;
}
return 0 ;
}
static void F_133 ( void )
{
if ( V_36 ) {
memset ( ( void * ) V_36 , 0 , V_284 ) ;
F_134 ( V_36 , F_106 ( V_284 ) ) ;
V_36 = 0 ;
V_45 = 0 ;
V_42 = 0 ;
}
}
static int F_135 ( struct V_1 * V_2 )
{
int V_12 ;
union V_287 V_288 ;
struct V_24 * V_24 = F_41 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
if ( F_136 ( V_24 ) )
return F_137 ( V_24 ) ;
for ( V_12 = 0 ; V_12 < 5 ; V_12 ++ )
V_24 -> V_289 [ V_12 ] = F_138 ( V_12 ) ;
V_288 . V_290 = V_24 -> V_289 [ 3 ] ;
V_288 . V_291 = 4 ;
V_24 -> V_289 [ 3 ] = V_288 . V_290 ;
V_24 -> V_292 . V_293 = 1 ;
V_24 -> V_292 . V_294 = 1 ;
V_24 -> V_292 . V_295 = 1 ;
V_24 -> V_292 . V_296 = 1 ;
V_24 -> V_292 . V_297 = 1 ;
V_24 -> V_292 . V_298 = 1 ;
V_24 -> V_292 . V_299 = 1 ;
V_24 -> V_300 . V_301 = 1 ;
V_24 -> V_302 = V_46 ;
return 0 ;
}
static int F_139 ( struct V_1 * V_2 )
{
long V_303 ;
struct V_24 * V_24 = V_2 -> V_6 . V_24 ;
unsigned long V_304 ;
V_304 = V_186 -> V_304 ;
F_23 ( V_50 L_13 , V_2 , V_304 ) ;
V_303 = F_13 ( ( T_1 * ) V_24 , ( T_1 * ) V_304 , 0 ) ;
if ( V_303 ) {
F_23 ( V_85 L_14 ) ;
return - V_40 ;
}
return 0 ;
}
static void F_140 ( struct V_1 * V_2 )
{
T_9 V_305 = { 0 } ;
F_141 ( & V_305 ) ;
V_2 -> V_6 . V_21 = V_305 . V_306 ;
V_2 -> V_6 . V_22 [ 0 ] = V_305 . V_307 [ 0 ] ;
V_2 -> V_6 . V_22 [ 1 ] = V_305 . V_307 [ 1 ] ;
V_2 -> V_6 . V_23 [ 0 ] = V_305 . V_308 [ 0 ] ;
V_2 -> V_6 . V_23 [ 1 ] = V_305 . V_308 [ 1 ] ;
}
static void F_142 ( struct V_1 * V_2 )
{
struct V_143 * V_144 = & V_2 -> V_6 . V_145 ;
if ( F_67 ( V_144 ) )
F_143 ( V_144 , V_151 ) ;
}
static enum V_309 F_144 ( struct V_143 * V_82 )
{
struct V_1 * V_2 ;
T_10 * V_310 ;
V_2 = F_145 ( V_82 , struct V_1 , V_6 . V_145 ) ;
V_310 = & V_2 -> V_120 ;
if ( V_2 -> V_6 . V_118 != V_152 )
goto V_163;
if ( F_50 ( V_310 ) )
F_51 ( V_310 ) ;
V_163:
V_2 -> V_6 . V_311 = 1 ;
V_2 -> V_6 . V_149 = 1 ;
return V_312 ;
}
int F_146 ( struct V_1 * V_2 )
{
struct V_1 * V_313 ;
int V_53 ;
int V_12 ;
long V_147 ;
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_106 * V_107 = F_49 ( V_2 ) ;
union V_174 * V_314 = & V_2 -> V_6 . V_227 ;
struct V_1 * V_315 = F_147 ( V_2 -> V_5 , V_2 ) ;
if ( F_136 ( V_315 ) )
return F_137 ( V_315 ) ;
if ( F_148 ( V_2 ) ) {
V_2 -> V_6 . V_118 = V_119 ;
V_107 -> V_113 = V_316 ;
V_147 = 0UL - F_1 ( V_2 ) ;
for ( V_12 = 0 ; V_12 < V_317 ; V_12 ++ ) {
V_313 = (struct V_1 * ) ( ( char * ) V_2 +
sizeof( struct V_318 ) * V_12 ) ;
V_313 -> V_6 . V_147 = V_147 ;
V_313 -> V_6 . V_240 = 0 ;
}
} else
V_2 -> V_6 . V_118 = V_130 ;
V_53 = - V_285 ;
V_2 -> V_6 . V_319 = F_149 ( sizeof( struct V_320 ) , V_197 ) ;
if ( ! V_2 -> V_6 . V_319 )
goto V_163;
V_2 -> V_6 . V_319 -> V_2 = V_2 ;
V_314 -> V_321 [ 1 ] = 0 ;
V_314 -> V_321 [ 12 ] = ( unsigned long ) ( ( char * ) V_315 + V_322 ) ;
V_314 -> V_321 [ 13 ] = ( unsigned long ) V_315 ;
V_314 -> V_169 = 0x1008522000UL ;
V_314 -> V_323 [ 40 ] = V_324 ;
V_314 -> V_325 = 0 ;
V_314 -> V_326 = 0x0 ;
V_314 -> V_323 [ 36 ] = 0x0 ;
V_314 -> V_323 [ 19 ] = 0x0 ;
V_314 -> V_323 [ 18 ] = ( unsigned long ) V_315 +
( ( sizeof( struct V_1 ) + 15 ) & ~ 15 ) ;
V_314 -> V_323 [ 64 ] = 0x0 ;
V_314 -> V_327 [ 0 ] = 0x7e04UL ;
V_314 -> V_327 [ 2 ] = ( unsigned long ) V_186 -> V_304 ;
V_314 -> V_327 [ 8 ] = 0x3c ;
V_314 -> V_328 [ 0 ] = 0x30 ;
V_314 -> V_328 [ 1 ] = 0x30 ;
V_314 -> V_328 [ 2 ] = 0x30 ;
V_314 -> V_328 [ 3 ] = 0x30 ;
V_314 -> V_328 [ 4 ] = 0x30 ;
V_314 -> V_328 [ 5 ] = 0x30 ;
V_314 -> V_328 [ 7 ] = 0x30 ;
V_314 -> V_329 [ 0 ] = * ( unsigned long * ) V_186 -> V_330 ;
V_2 -> V_6 . V_173 = V_5 -> V_6 . V_208 ;
V_2 -> V_6 . V_204 = V_5 -> V_6 . V_204 ;
V_2 -> V_6 . V_206 = V_5 -> V_6 . V_206 ;
F_150 ( & V_2 -> V_6 . V_145 , V_331 , V_151 ) ;
V_2 -> V_6 . V_145 . V_332 = F_144 ;
V_2 -> V_6 . V_170 = - 1 ;
V_2 -> V_6 . V_24 = (struct V_24 * ) F_151 ( V_2 -> V_333 ) ;
V_2 -> V_6 . V_334 = V_42 ;
V_2 -> V_6 . V_335 = V_336 ;
V_2 -> V_6 . V_337 = F_18 ( & V_5 -> V_6 . V_338 ) ;
V_2 -> V_6 . V_339 . V_340 = (struct V_230 * ) F_152 ( V_2 -> V_333 ) ;
V_2 -> V_6 . V_341 . V_340 = (struct V_230 * ) F_153 ( V_2 -> V_333 ) ;
F_140 ( V_2 ) ;
V_53 = 0 ;
V_163:
return V_53 ;
}
static int F_154 ( struct V_1 * V_2 , int V_100 )
{
unsigned long V_169 ;
int V_53 ;
F_10 ( V_169 ) ;
V_53 = F_77 ( V_2 ) ;
F_12 ( V_169 ) ;
if ( V_53 )
goto V_342;
V_53 = F_155 ( V_2 , V_2 -> V_5 , V_100 ) ;
if ( V_53 )
goto V_342;
V_53 = F_135 ( V_2 ) ;
if ( V_53 ) {
F_23 ( V_50 L_15 ) ;
goto V_343;
}
V_53 = F_139 ( V_2 ) ;
if ( V_53 )
goto V_343;
F_78 ( V_2 ) ;
return 0 ;
V_343:
F_156 ( V_2 ) ;
V_342:
return V_53 ;
}
struct V_1 * F_157 ( struct V_5 * V_5 ,
unsigned int V_100 )
{
struct V_1 * V_2 ;
unsigned long V_165 = V_5 -> V_6 . V_165 ;
int V_53 ;
int V_131 ;
F_104 ( sizeof( struct V_1 ) > V_344 / 2 ) ;
V_53 = - V_40 ;
if ( V_100 >= V_317 ) {
F_23 ( V_85 L_16 ,
V_317 ) ;
goto V_342;
}
V_53 = - V_285 ;
if ( ! V_165 ) {
F_23 ( V_85 L_17 , V_100 ) ;
goto V_342;
}
V_2 = (struct V_1 * ) ( V_165 + F_107 ( struct V_199 ,
V_345 [ V_100 ] . V_346 ) ) ;
V_2 -> V_5 = V_5 ;
V_131 = F_158 () ;
V_53 = F_154 ( V_2 , V_100 ) ;
F_159 () ;
if ( V_53 ) {
F_23 ( V_50 L_18 ) ;
goto V_342;
}
return V_2 ;
V_342:
return F_160 ( V_53 ) ;
}
int F_161 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_162 ( struct V_1 * V_2 , struct V_347 * V_348 )
{
return - V_40 ;
}
int F_163 ( struct V_1 * V_2 , struct V_347 * V_348 )
{
return - V_40 ;
}
int F_164 ( struct V_1 * V_2 ,
struct V_349 * V_350 )
{
return - V_40 ;
}
void F_165 ( struct V_5 * V_5 )
{
unsigned long V_165 = V_5 -> V_6 . V_165 ;
if ( V_165 ) {
memset ( ( void * ) V_165 , 0 , V_198 ) ;
F_134 ( V_165 , F_106 ( V_198 ) ) ;
}
}
static void F_166 ( struct V_5 * V_5 )
{
struct V_351 * V_352 ;
struct V_353 * V_354 ;
int V_12 , V_13 ;
unsigned long V_355 ;
V_352 = V_351 ( V_5 ) ;
for ( V_12 = 0 ; V_12 < V_352 -> V_356 ; V_12 ++ ) {
V_354 = & V_352 -> V_357 [ V_12 ] ;
V_355 = V_354 -> V_355 ;
for ( V_13 = 0 ; V_13 < V_354 -> V_358 ; V_13 ++ ) {
if ( V_354 -> V_359 [ V_13 ] )
F_167 ( (struct V_360 * ) V_354 -> V_359 [ V_13 ] ) ;
}
}
}
void F_168 ( struct V_5 * V_5 )
{
}
void F_169 ( struct V_5 * V_5 )
{
F_170 ( V_5 ) ;
#ifdef F_171
F_172 ( V_5 ) ;
#endif
F_173 ( V_5 -> V_6 . V_361 ) ;
F_166 ( V_5 ) ;
}
void F_174 ( struct V_1 * V_2 )
{
}
void F_175 ( struct V_1 * V_2 , int V_131 )
{
if ( V_131 != V_2 -> V_131 ) {
V_2 -> V_131 = V_131 ;
if ( V_2 -> V_6 . V_150 )
F_142 ( V_2 ) ;
}
}
int F_176 ( struct V_1 * V_2 , struct V_218 * V_107 )
{
struct V_24 * V_24 = F_41 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
int V_12 ;
F_177 ( V_2 ) ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
V_107 -> V_24 . V_219 [ V_12 ] = V_24 -> V_219 [ V_12 ] ;
V_107 -> V_24 . V_220 [ V_12 ] = V_24 -> V_220 [ V_12 ] ;
}
for ( V_12 = 0 ; V_12 < 128 ; V_12 ++ )
V_107 -> V_24 . V_221 [ V_12 ] = V_24 -> V_221 [ V_12 ] ;
V_107 -> V_24 . V_222 = V_24 -> V_222 ;
V_107 -> V_24 . V_223 = V_24 -> V_223 ;
V_107 -> V_24 . V_224 = V_24 -> V_224 ;
V_107 -> V_24 . V_225 = V_24 -> V_225 ;
V_107 -> V_24 . V_226 = V_24 -> V_226 ;
memcpy ( & V_107 -> V_228 , & V_2 -> V_6 . V_227 , sizeof( union V_174 ) ) ;
F_178 ( V_118 ) ;
F_178 ( V_173 ) ;
memcpy ( V_107 -> V_229 , V_2 -> V_6 . V_229 , sizeof( struct V_230 ) * V_231 ) ;
memcpy ( V_107 -> V_232 , V_2 -> V_6 . V_232 , sizeof( struct V_230 ) * V_233 ) ;
F_178 ( V_234 ) ;
F_178 ( V_235 ) ;
F_178 ( V_236 ) ;
F_178 ( V_237 ) ;
F_178 ( V_238 ) ;
F_178 ( V_149 ) ;
F_178 ( V_239 ) ;
F_178 ( V_240 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_107 -> V_241 [ V_12 ] = V_2 -> V_6 . V_241 [ V_12 ] ;
V_107 -> V_242 [ V_12 ] = V_2 -> V_6 . V_242 [ V_12 ] ;
V_107 -> V_243 [ V_12 ] = V_2 -> V_6 . V_243 [ V_12 ] ;
}
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ )
V_107 -> V_244 [ V_12 ] = V_2 -> V_6 . V_244 [ V_12 ] ;
V_107 -> V_250 = V_2 -> V_6 . V_147 + F_1 ( V_2 ) ;
F_178 ( V_245 ) ;
F_178 ( V_204 ) ;
F_178 ( V_206 ) ;
F_178 ( V_246 ) ;
F_178 ( V_247 ) ;
F_178 ( V_248 ) ;
F_178 ( V_249 ) ;
F_179 ( V_2 ) ;
return 0 ;
}
int F_180 ( struct V_1 * V_2 ,
struct V_362 * V_363 )
{
memcpy ( V_363 , V_2 , sizeof( struct V_362 ) ) ;
return 0 ;
}
int F_181 ( struct V_1 * V_2 ,
struct V_362 * V_363 )
{
memcpy ( V_2 + 1 , & V_363 -> V_363 [ 0 ] + sizeof( struct V_1 ) ,
sizeof( struct V_362 ) - sizeof( struct V_1 ) ) ;
V_2 -> V_6 . V_364 = ( (struct V_1 * ) V_363 ) -> V_6 . V_364 ;
return 0 ;
}
void F_182 ( struct V_1 * V_2 )
{
F_67 ( & V_2 -> V_6 . V_145 ) ;
F_173 ( V_2 -> V_6 . V_319 ) ;
}
long F_183 ( struct V_252 * V_253 ,
unsigned int V_254 , unsigned long V_255 )
{
struct V_1 * V_2 = V_253 -> V_256 ;
void T_7 * V_257 = ( void T_7 * ) V_255 ;
struct V_362 * V_363 = NULL ;
long V_53 ;
switch ( V_254 ) {
case V_365 : {
struct V_362 T_7 * V_366 ;
void T_7 * V_367 = V_257 ;
V_53 = - V_264 ;
if ( F_120 ( & V_366 , V_367 , sizeof( void * ) ) )
goto V_163;
if ( ! F_184 ( V_368 , V_366 ,
sizeof( struct V_362 ) ) ) {
F_23 ( V_48 L_19
L_20 ) ;
goto V_163;
}
V_363 = F_149 ( sizeof( struct V_362 ) , V_197 ) ;
if ( ! V_363 ) {
V_53 = - V_285 ;
goto V_163;
}
V_53 = F_180 ( V_2 , V_363 ) ;
if ( V_53 )
goto V_163;
if ( F_128 ( V_366 , V_363 ,
sizeof( struct V_362 ) ) ) {
V_53 = - V_264 ;
goto V_163;
}
break;
}
case V_369 : {
struct V_362 T_7 * V_366 ;
void T_7 * V_367 = V_257 ;
V_53 = - V_264 ;
if ( F_120 ( & V_366 , V_367 , sizeof( void * ) ) )
goto V_163;
if ( ! F_184 ( V_370 , V_366 ,
sizeof( struct V_362 ) ) ) {
F_23 ( V_48 L_21
L_22 ) ;
goto V_163;
}
V_363 = F_185 ( sizeof( struct V_362 ) , V_197 ) ;
if ( ! V_363 ) {
V_53 = - V_285 ;
goto V_163;
}
if ( F_120 ( V_363 , V_366 ,
sizeof( struct V_362 ) ) )
goto V_163;
V_53 = F_181 ( V_2 , V_363 ) ;
break;
}
default:
V_53 = - V_40 ;
}
V_163:
F_173 ( V_363 ) ;
return V_53 ;
}
int F_186 ( struct V_5 * V_5 ,
struct V_353 * V_354 ,
struct V_353 V_371 ,
struct V_262 * V_372 ,
int V_373 )
{
unsigned long V_12 ;
unsigned long V_374 ;
int V_358 = V_354 -> V_358 ;
unsigned long V_355 = V_354 -> V_355 ;
if ( V_355 + V_358 > ( V_375 >> V_137 ) )
return - V_285 ;
for ( V_12 = 0 ; V_12 < V_358 ; V_12 ++ ) {
V_374 = F_187 ( V_5 , V_355 + V_12 ) ;
if ( ! F_188 ( V_374 ) ) {
F_109 ( V_5 , V_355 + V_12 ,
V_374 << V_137 ,
V_376 | V_377 ) ;
V_354 -> V_359 [ V_12 ] = ( unsigned long ) F_189 ( V_374 ) ;
} else {
F_109 ( V_5 , V_355 + V_12 ,
V_378 | ( V_374 << V_137 ) ,
V_379 ) ;
V_354 -> V_359 [ V_12 ] = 0 ;
}
}
return 0 ;
}
void F_190 ( struct V_5 * V_5 ,
struct V_262 * V_372 ,
struct V_353 V_371 ,
int V_373 )
{
return;
}
void F_191 ( struct V_5 * V_5 )
{
F_192 ( V_5 ) ;
}
long F_193 ( struct V_252 * V_253 ,
unsigned int V_254 , unsigned long V_255 )
{
return - V_40 ;
}
void F_194 ( struct V_1 * V_2 )
{
F_156 ( V_2 ) ;
}
static int F_195 ( void )
{
long V_380 = 1 , V_30 = 1 , V_381 = 1 ;
long V_303 ;
V_303 = F_196 ( & V_380 , & V_30 , & V_381 , 0 ) ;
if ( V_303 )
goto V_163;
if ( ! ( V_380 & V_382 ) )
goto V_163;
F_23 ( V_50 L_23 ) ;
V_303 = F_197 ( & V_282 , & V_383 ) ;
if ( V_303 )
goto V_163;
F_23 ( V_50 L_24 , V_282 ) ;
if ( ! ( V_383 & V_384 ) ) {
F_23 ( V_47 L_25
L_26 , V_383 ) ;
}
return 1 ;
V_163:
return 0 ;
}
static void F_198 ( struct V_186 * V_385 ,
struct V_386 * V_386 )
{
unsigned long V_387 , V_388 ;
unsigned long V_389 ;
if ( ! F_111 ( L_11 ) )
return;
V_389 = ( unsigned long ) V_386 -> V_390 ;
V_387 = V_36 + V_385 -> V_391 - V_389 ;
V_388 = V_36 + V_385 -> V_392 - V_389 ;
F_23 ( V_48 L_27
L_28 ) ;
memcpy ( ( void * ) V_387 , ( void * ) V_388 , 0x60 ) ;
}
static int F_199 ( struct V_186 * V_385 ,
struct V_386 * V_386 )
{
unsigned long V_389 ;
unsigned long V_393 ;
unsigned long V_394 , V_395 , V_396 ;
struct V_397 * V_398 ;
F_104 ( ! V_386 ) ;
if ( ! V_36 ) {
F_23 ( L_29 ) ;
return - V_264 ;
}
V_389 = ( unsigned long ) V_386 -> V_390 ;
V_393 = V_386 -> V_399 ;
if ( F_102 ( V_393 > V_284 ) )
return - V_264 ;
memcpy ( ( void * ) V_36 , ( void * ) V_389 , V_393 ) ;
F_198 ( V_385 , V_386 ) ;
F_5 ( V_36 , V_393 ) ;
V_394 = V_385 -> V_304 - V_389 ;
V_186 -> V_304 = V_38 + V_394 ;
F_23 ( V_50 L_30 ,
V_186 -> V_304 ) ;
V_396 = ( unsigned long ) V_385 -> V_330 - V_389 ;
V_186 -> V_330 = ( V_400 * ) ( V_38 +
V_396 ) ;
V_395 = * ( unsigned long * ) V_385 -> V_330 - V_389 ;
V_398 = (struct V_397 * ) ( V_36 + V_396 ) ;
V_398 -> V_401 = V_38 + V_395 ;
V_398 -> V_402 = V_38 + ( V_398 -> V_402 - V_389 ) ;
F_23 ( V_50 L_31 ,
V_38 + V_395 ) ;
V_396 = ( unsigned long ) V_385 -> V_187 - V_389 ;
V_186 -> V_187 = ( V_403 * ) ( V_38 +
V_396 ) ;
V_395 = * ( unsigned long * ) V_385 -> V_187 - V_389 ;
V_398 = (struct V_397 * ) ( V_36 + V_396 ) ;
V_398 -> V_401 = V_38 + V_395 ;
V_398 -> V_402 = V_38 + ( V_398 -> V_402 - V_389 ) ;
V_336 = V_398 -> V_402 ;
F_23 ( V_50 L_32 ,
V_186 -> V_330 ) ;
F_23 ( V_50 L_33 ,
V_38 + V_395 ) ;
return 0 ;
}
int F_200 ( void * V_404 )
{
int V_53 ;
struct V_186 * V_385 = (struct V_186 * ) V_404 ;
if ( ! F_195 () ) {
F_23 ( V_85 L_34 ) ;
V_53 = - V_405 ;
goto V_163;
}
if ( V_186 ) {
F_23 ( V_85 L_35 ) ;
V_53 = - V_406 ;
goto V_163;
}
V_53 = - V_285 ;
V_186 = F_149 ( sizeof( struct V_186 ) , V_197 ) ;
if ( ! V_186 )
goto V_163;
if ( F_132 () )
goto V_407;
V_53 = F_199 ( V_385 , V_385 -> V_386 ) ;
if ( V_53 )
goto V_408;
return 0 ;
V_408:
F_133 () ;
V_407:
F_173 ( V_186 ) ;
V_163:
return V_53 ;
}
void F_201 ( void )
{
F_133 () ;
F_173 ( V_186 ) ;
V_186 = NULL ;
}
static void F_202 ( struct V_5 * V_5 ,
struct V_353 * V_354 )
{
int V_12 ;
long V_306 ;
unsigned long V_409 ;
unsigned long * V_410 = ( unsigned long * ) ( V_5 -> V_6 . V_165 +
F_107 ( struct V_199 , V_411 ) ) ;
V_409 = F_203 ( V_354 ) ;
V_306 = V_354 -> V_355 / V_412 ;
F_20 ( & V_5 -> V_6 . V_338 ) ;
for ( V_12 = 0 ; V_12 < V_409 / sizeof( long ) ; ++ V_12 ) {
V_354 -> V_410 [ V_12 ] = V_410 [ V_306 + V_12 ] ;
V_410 [ V_306 + V_12 ] = 0 ;
}
F_22 ( & V_5 -> V_6 . V_338 ) ;
}
int F_204 ( struct V_5 * V_5 ,
struct V_413 * log )
{
int V_53 ;
unsigned long V_409 ;
struct V_353 * V_354 ;
int V_414 = 0 ;
F_124 ( & V_5 -> V_268 ) ;
V_53 = - V_40 ;
if ( log -> V_35 >= V_415 )
goto V_163;
V_354 = & V_5 -> V_357 -> V_357 [ log -> V_35 ] ;
V_53 = - V_416 ;
if ( ! V_354 -> V_410 )
goto V_163;
F_202 ( V_5 , V_354 ) ;
V_53 = F_205 ( V_5 , log , & V_414 ) ;
if ( V_53 )
goto V_163;
if ( V_414 ) {
F_192 ( V_5 ) ;
V_409 = F_203 ( V_354 ) ;
memset ( V_354 -> V_410 , 0 , V_409 ) ;
}
V_53 = 0 ;
V_163:
F_126 ( & V_5 -> V_268 ) ;
return V_53 ;
}
int F_206 ( void )
{
return 0 ;
}
void F_207 ( void )
{
}
void F_43 ( struct V_1 * V_2 )
{
int V_417 ;
int V_131 = V_2 -> V_131 ;
if ( F_50 ( & V_2 -> V_120 ) )
F_51 ( & V_2 -> V_120 ) ;
V_417 = F_158 () ;
if ( V_131 != V_417 && ( unsigned ) V_131 < V_418 && F_208 ( V_131 ) )
if ( ! F_42 ( V_182 , & V_2 -> V_124 ) )
F_209 ( V_131 ) ;
F_159 () ;
}
int F_210 ( struct V_1 * V_2 , struct V_419 * V_274 )
{
return F_40 ( V_2 , V_274 -> V_91 ) ;
}
int F_211 ( struct V_320 * V_319 , T_11 V_420 )
{
return V_319 -> V_2 -> V_333 == V_420 ;
}
int F_212 ( struct V_320 * V_319 , T_12 V_421 )
{
return 0 ;
}
int F_213 ( struct V_1 * V_422 , struct V_1 * V_423 )
{
return V_422 -> V_6 . V_245 - V_423 -> V_6 . V_245 ;
}
int F_214 ( struct V_1 * V_2 , struct V_320 * V_424 ,
int V_425 , int V_420 , int V_426 )
{
struct V_320 * V_427 = V_2 -> V_6 . V_319 ;
return ( V_426 == 0 ) ?
F_211 ( V_427 , V_420 ) :
F_212 ( V_427 , V_420 ) ;
}
static int F_215 ( int * V_428 )
{
T_5 V_429 , V_430 ;
int V_12 ;
for ( V_12 = 7 ; V_12 >= 0 ; V_12 -- ) {
V_429 = V_428 [ V_12 ] ;
if ( V_429 ) {
V_430 = F_216 ( V_429 ) ;
return V_12 * 32 + V_430 - 1 ;
}
}
return - 1 ;
}
int F_217 ( struct V_1 * V_2 )
{
struct V_24 * V_24 = F_41 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
if ( V_24 -> V_92 [ 0 ] & ( 1UL << V_431 ) )
return V_431 ;
if ( V_24 -> V_92 [ 0 ] & ( 1UL << V_432 ) )
return V_432 ;
return F_215 ( ( int * ) & V_24 -> V_92 [ 0 ] ) ;
}
int F_69 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_311 ;
}
int F_218 ( struct V_1 * V_2 )
{
return ( V_2 -> V_6 . V_118 == V_119 ) ||
( F_217 ( V_2 ) != - 1 ) ;
}
int F_219 ( struct V_1 * V_2 ,
struct V_433 * V_118 )
{
V_118 -> V_118 = V_2 -> V_6 . V_118 ;
return 0 ;
}
static int F_220 ( struct V_1 * V_2 )
{
int V_53 ;
long V_169 ;
F_10 ( V_169 ) ;
V_53 = F_77 ( V_2 ) ;
F_12 ( V_169 ) ;
if ( V_53 )
goto V_342;
V_2 -> V_6 . V_112 = 0 ;
F_182 ( V_2 ) ;
V_53 = F_146 ( V_2 ) ;
if ( V_53 )
goto V_342;
F_78 ( V_2 ) ;
V_53 = 0 ;
V_342:
return V_53 ;
}
int F_221 ( struct V_1 * V_2 ,
struct V_433 * V_118 )
{
int V_53 = 0 ;
V_2 -> V_6 . V_118 = V_118 -> V_118 ;
if ( V_2 -> V_6 . V_118 == V_130 )
V_53 = F_220 ( V_2 ) ;
return V_53 ;
}
