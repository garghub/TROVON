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
#ifdef F_29
case V_59 :
V_53 = F_30 ( & V_60 ) ;
break;
#endif
default:
V_53 = 0 ;
}
return V_53 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
V_61 -> V_62 = V_63 ;
V_61 -> V_64 . V_65 = 1 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
struct V_66 * V_67 ;
struct V_68 * V_69 ;
int V_53 ;
V_67 = F_33 ( V_2 ) ;
if ( ( V_67 -> V_18 & V_70 ) == V_71 )
goto V_72;
V_2 -> V_73 = 1 ;
V_2 -> V_74 [ 0 ] . V_75 = V_61 -> V_72 . V_76 = V_67 -> V_18 ;
V_2 -> V_74 [ 0 ] . V_10 = V_61 -> V_72 . V_10 = V_67 -> V_77 ;
V_2 -> V_78 = V_61 -> V_72 . V_79 = ! V_67 -> V_80 ;
if ( V_2 -> V_78 )
memcpy ( V_2 -> V_6 . V_81 , & V_67 -> V_82 , V_67 -> V_77 ) ;
memcpy ( V_61 -> V_72 . V_82 , & V_67 -> V_82 , V_67 -> V_77 ) ;
V_61 -> V_62 = V_83 ;
return 0 ;
V_72:
if ( V_67 -> V_80 )
V_53 = F_34 ( V_2 -> V_5 , V_84 , V_67 -> V_18 ,
V_67 -> V_77 , & V_67 -> V_82 ) ;
else
V_53 = F_35 ( V_2 -> V_5 , V_84 , V_67 -> V_18 ,
V_67 -> V_77 , & V_67 -> V_82 ) ;
if ( V_53 )
F_23 ( V_85 L_4 , V_67 -> V_18 ) ;
V_67 -> V_86 = V_87 ;
return 1 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
struct V_88 * V_67 ;
V_67 = F_37 ( V_2 ) ;
if ( V_67 -> V_62 == V_89 )
return F_38 ( V_2 , V_61 ) ;
else {
V_61 -> V_62 = V_63 ;
V_61 -> V_64 . V_65 = 2 ;
return 0 ;
}
}
static int F_39 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
struct V_88 * V_67 ;
V_67 = F_37 ( V_2 ) ;
if ( V_67 -> V_62 == V_90 ) {
F_40 ( V_2 ) ;
return 1 ;
} else {
V_61 -> V_62 = V_63 ;
V_61 -> V_64 . V_65 = 3 ;
return 0 ;
}
}
static int F_41 ( struct V_1 * V_2 , T_2 V_91 )
{
struct V_24 * V_24 = F_42 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
if ( ! F_43 ( V_91 , & V_24 -> V_92 [ 0 ] ) ) {
V_2 -> V_6 . V_93 = 1 ;
F_44 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static void F_45 ( struct V_1 * V_2 , T_2 V_94 ,
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
F_41 ( V_2 , V_91 ) ;
}
static struct V_1 * F_46 ( struct V_5 * V_5 , unsigned long V_100 ,
unsigned long V_101 )
{
union V_102 V_103 ;
int V_12 ;
struct V_1 * V_2 ;
F_47 (i, vcpu, kvm) {
V_103 . V_104 = F_48 ( V_2 ) ;
if ( V_103 . V_100 == V_100 && V_103 . V_101 == V_101 )
return V_2 ;
}
return NULL ;
}
static int F_49 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
struct V_88 * V_67 = F_37 ( V_2 ) ;
struct V_1 * V_105 ;
struct V_106 * V_107 ;
union V_108 V_18 = V_67 -> V_109 . V_110 . V_18 ;
union V_111 V_82 = V_67 -> V_109 . V_110 . V_82 ;
V_105 = F_46 ( V_2 -> V_5 , V_18 . V_100 , V_18 . V_101 ) ;
if ( ! V_105 )
return F_31 ( V_2 , V_61 ) ;
if ( ! V_105 -> V_6 . V_112 ) {
V_107 = F_50 ( V_105 ) ;
V_107 -> V_113 = V_2 -> V_5 -> V_6 . V_114 . V_115 ;
V_107 -> V_116 = V_2 -> V_5 -> V_6 . V_114 . V_117 ;
V_105 -> V_6 . V_118 = V_119 ;
if ( F_51 ( & V_105 -> V_120 ) )
F_52 ( & V_105 -> V_120 ) ;
} else {
F_45 ( V_105 , V_82 . V_94 , V_82 . V_91 ) ;
if ( V_105 != V_2 )
F_44 ( V_105 ) ;
}
return 1 ;
}
static void F_53 ( void * V_121 )
{
struct V_122 * V_67 = (struct V_122 * ) V_121 ;
struct V_1 * V_2 = V_67 -> V_2 ;
if ( F_54 ( V_123 , & V_2 -> V_124 ) )
return;
F_55 ( V_125 , & V_2 -> V_124 ) ;
if ( V_2 -> V_6 . V_126 < V_127 ) {
V_2 -> V_6 . V_128 [ V_2 -> V_6 . V_126 ++ ] =
V_67 -> V_128 ;
} else {
F_56 ( V_125 , & V_2 -> V_124 ) ;
V_2 -> V_6 . V_126 = 0 ;
F_55 ( V_123 , & V_2 -> V_124 ) ;
}
}
static int F_57 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
struct V_88 * V_67 = F_37 ( V_2 ) ;
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_122 V_122 ;
int V_12 ;
struct V_1 * V_129 ;
V_122 . V_128 = V_67 -> V_109 . V_128 ;
F_47 (i, vcpui, kvm) {
if ( V_129 -> V_6 . V_118 == V_130 ||
V_2 == V_129 )
continue;
if ( F_51 ( & V_129 -> V_120 ) )
F_52 ( & V_129 -> V_120 ) ;
if ( V_129 -> V_131 != - 1 ) {
V_122 . V_2 = V_129 ;
F_58 ( V_129 -> V_131 ,
F_53 , & V_122 , 1 ) ;
} else
F_23 ( V_47 L_6 ) ;
}
return 1 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
return 1 ;
}
static int F_60 ( struct V_1 * V_2 )
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
int F_61 ( struct V_1 * V_2 )
{
T_3 V_139 ;
long V_140 ;
unsigned long V_141 ;
unsigned long V_142 ;
struct V_143 * V_144 = & V_2 -> V_6 . V_145 ;
unsigned long V_146 = V_20 -> V_146 ;
struct V_24 * V_24 = F_42 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
if ( F_62 ( V_2 -> V_5 ) ) {
V_141 = F_1 ( V_2 ) + V_2 -> V_6 . V_147 ;
if ( F_63 ( V_141 , V_24 -> V_148 ) ) {
V_2 -> V_6 . V_149 = 1 ;
return 1 ;
}
V_140 = V_24 -> V_148 - V_141 ;
if ( V_140 < 0 )
V_140 = - V_140 ;
V_142 = F_64 ( V_140 , V_146 ) ;
V_139 = F_65 ( 0 , 1000 * V_142 ) ;
V_2 -> V_6 . V_150 = 1 ;
F_66 ( V_144 , V_139 , V_151 ) ;
V_2 -> V_6 . V_118 = V_152 ;
F_67 ( V_2 ) ;
F_68 ( V_144 ) ;
V_2 -> V_6 . V_150 = 0 ;
if ( F_69 ( V_153 , & V_2 -> V_124 ) ||
F_70 ( V_2 ) )
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
static int F_71 ( struct V_1 * V_2 ,
struct V_61 * V_61 )
{
V_61 -> V_62 = V_155 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_61 * V_61 )
{
return 1 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_61 * V_61 )
{
F_23 ( L_9 , V_2 -> V_6 . V_156 ) ;
return 1 ;
}
static T_4 F_74 ( struct V_1 * V_2 )
{
struct V_88 * V_157 ;
V_157 = F_37 ( V_2 ) ;
return V_157 -> V_62 ;
}
static int F_75 ( struct V_61 * V_61 , struct V_1 * V_2 )
{
T_5 V_62 = F_74 ( V_2 ) ;
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
static inline void F_76 ( unsigned long V_161 )
{
F_77 ( V_162 , V_161 ) ;
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
V_53 = F_60 ( V_2 ) ;
if ( V_53 < 0 )
goto V_163;
}
#endif
V_53 = 0 ;
V_163:
return V_53 ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
F_24 ( 0x3 , V_2 -> V_6 . V_164 ) ;
F_24 ( 0x3 , V_2 -> V_6 . V_168 ) ;
#if F_2 ( V_3 ) || F_2 ( V_4 )
if ( V_5 -> V_6 . V_7 )
F_24 ( 0x3 , V_2 -> V_6 . V_138 ) ;
#endif
}
static int F_80 ( struct V_1 * V_2 )
{
unsigned long V_169 ;
int V_53 ;
int V_131 = F_81 () ;
if ( V_2 -> V_6 . V_170 != V_131 ||
F_82 ( V_171 , V_131 ) != V_2 ) {
F_82 ( V_171 , V_131 ) = V_2 ;
V_2 -> V_6 . V_170 = V_131 ;
F_9 () ;
}
V_2 -> V_6 . V_172 = F_83 ( V_162 ) ;
F_76 ( V_2 -> V_6 . V_173 ) ;
F_10 ( V_169 ) ;
V_53 = F_78 ( V_2 ) ;
F_12 ( V_169 ) ;
return V_53 ;
}
static void F_84 ( struct V_1 * V_2 )
{
F_79 ( V_2 ) ;
F_76 ( V_2 -> V_6 . V_172 ) ;
}
static int F_85 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
union V_174 * V_175 , * V_176 ;
int V_53 , V_177 ;
V_177 = F_86 ( & V_2 -> V_5 -> V_178 ) ;
V_179:
if ( F_87 ( V_180 ) ) {
V_53 = - V_154 ;
V_61 -> V_62 = V_181 ;
goto V_163;
}
F_88 () ;
F_89 () ;
V_175 = F_90 ( V_2 ) ;
V_176 = F_91 ( V_2 ) ;
F_56 ( V_182 , & V_2 -> V_124 ) ;
V_53 = F_80 ( V_2 ) ;
if ( V_53 < 0 )
goto V_183;
F_92 ( & V_2 -> V_5 -> V_178 , V_177 ) ;
V_2 -> V_184 = V_185 ;
F_93 () ;
V_186 -> V_187 ( V_175 , V_176 ) ;
F_84 ( V_2 ) ;
V_2 -> V_6 . V_112 = 1 ;
F_55 ( V_182 , & V_2 -> V_124 ) ;
F_94 () ;
F_95 () ;
F_96 () ;
V_2 -> V_184 = V_188 ;
F_97 () ;
V_177 = F_86 ( & V_2 -> V_5 -> V_178 ) ;
V_53 = F_75 ( V_61 , V_2 ) ;
if ( V_53 > 0 ) {
if ( ! F_98 () )
goto V_179;
}
V_163:
F_92 ( & V_2 -> V_5 -> V_178 , V_177 ) ;
if ( V_53 > 0 ) {
F_99 ( V_2 ) ;
V_177 = F_86 ( & V_2 -> V_5 -> V_178 ) ;
goto V_179;
}
return V_53 ;
V_183:
F_94 () ;
F_97 () ;
V_61 -> V_62 = V_189 ;
goto V_163;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = F_33 ( V_2 ) ;
if ( ! V_2 -> V_78 )
memcpy ( & V_67 -> V_82 , V_2 -> V_6 . V_81 , 8 ) ;
V_67 -> V_86 = V_87 ;
}
int F_101 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
int V_53 ;
T_6 V_190 ;
if ( V_2 -> V_191 )
F_102 ( V_192 , & V_2 -> V_193 , & V_190 ) ;
if ( F_103 ( V_2 -> V_6 . V_118 == V_130 ) ) {
F_67 ( V_2 ) ;
F_56 ( V_153 , & V_2 -> V_124 ) ;
V_53 = - V_194 ;
goto V_163;
}
if ( V_2 -> V_73 ) {
memcpy ( V_2 -> V_6 . V_81 , V_61 -> V_72 . V_82 , 8 ) ;
F_100 ( V_2 ) ;
V_2 -> V_195 = 1 ;
V_2 -> V_73 = 0 ;
}
V_53 = F_85 ( V_2 , V_61 ) ;
V_163:
if ( V_2 -> V_191 )
F_102 ( V_192 , & V_190 , NULL ) ;
return V_53 ;
}
struct V_5 * F_104 ( void )
{
struct V_5 * V_5 ;
T_2 V_165 ;
F_105 ( sizeof( struct V_5 ) > V_196 ) ;
V_165 = F_106 ( V_197 , F_107 ( V_198 ) ) ;
if ( ! V_165 )
return NULL ;
memset ( ( void * ) V_165 , 0 , V_198 ) ;
V_5 = (struct V_5 * ) ( V_165 +
F_108 ( struct V_199 , V_200 ) ) ;
V_5 -> V_6 . V_165 = V_165 ;
F_23 ( V_50 L_10 , V_165 ) ;
return V_5 ;
}
static void F_109 ( struct V_5 * V_5 )
{
unsigned long V_12 , V_13 ;
for ( V_12 = 0 ; V_12 < ( sizeof( V_201 ) / sizeof( struct V_202 ) ) ;
V_12 ++ ) {
for ( V_13 = V_201 [ V_12 ] . V_9 ;
V_13 < V_201 [ V_12 ] . V_9 + V_201 [ V_12 ] . V_77 ;
V_13 += V_203 )
F_110 ( V_5 , V_13 >> V_137 ,
V_201 [ V_12 ] . type , 0 ) ;
}
}
int F_111 ( struct V_5 * V_5 , unsigned long type )
{
F_105 ( ! V_5 ) ;
if ( type )
return - V_40 ;
V_5 -> V_6 . V_7 = F_112 ( L_11 ) ;
V_5 -> V_6 . V_204 = V_205 ;
V_5 -> V_6 . V_206 = V_207 ;
V_5 -> V_6 . V_208 = V_209 ;
F_109 ( V_5 ) ;
F_113 ( & V_5 -> V_6 . V_210 ) ;
F_55 ( V_211 , & V_5 -> V_6 . V_212 ) ;
return 0 ;
}
static int F_114 ( struct V_5 * V_5 ,
struct V_213 * V_214 )
{
int V_53 ;
V_53 = 0 ;
switch ( V_214 -> V_215 ) {
case V_216 :
V_53 = F_115 ( V_5 , & V_214 -> V_214 . V_217 ) ;
break;
default:
V_53 = - V_40 ;
break;
}
return V_53 ;
}
static int F_116 ( struct V_5 * V_5 , struct V_213 * V_214 )
{
int V_53 ;
V_53 = 0 ;
switch ( V_214 -> V_215 ) {
case V_216 :
V_53 = F_117 ( V_5 , & V_214 -> V_214 . V_217 ) ;
break;
default:
V_53 = - V_40 ;
break;
}
return V_53 ;
}
int F_118 ( struct V_1 * V_2 , struct V_218 * V_107 )
{
struct V_24 * V_24 = F_42 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
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
F_119 ( V_118 ) ;
F_119 ( V_173 ) ;
memcpy ( V_2 -> V_6 . V_229 , V_107 -> V_229 , sizeof( struct V_230 ) * V_231 ) ;
memcpy ( V_2 -> V_6 . V_232 , V_107 -> V_232 , sizeof( struct V_230 ) * V_233 ) ;
F_119 ( V_234 ) ;
F_119 ( V_235 ) ;
F_119 ( V_236 ) ;
F_119 ( V_237 ) ;
F_119 ( V_238 ) ;
F_119 ( V_149 ) ;
F_119 ( V_239 ) ;
F_119 ( V_240 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_2 -> V_6 . V_241 [ V_12 ] = V_107 -> V_241 [ V_12 ] ;
V_2 -> V_6 . V_242 [ V_12 ] = V_107 -> V_242 [ V_12 ] ;
V_2 -> V_6 . V_243 [ V_12 ] = V_107 -> V_243 [ V_12 ] ;
}
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ )
V_2 -> V_6 . V_244 [ V_12 ] = V_107 -> V_244 [ V_12 ] ;
F_119 ( V_245 ) ;
F_119 ( V_204 ) ;
F_119 ( V_206 ) ;
F_119 ( V_246 ) ;
F_119 ( V_247 ) ;
F_119 ( V_248 ) ;
F_119 ( V_249 ) ;
V_2 -> V_6 . V_93 = 1 ;
V_2 -> V_6 . V_147 = V_107 -> V_250 - F_1 ( V_2 ) ;
F_55 ( V_251 , & V_2 -> V_124 ) ;
return 0 ;
}
int F_120 ( struct V_5 * V_5 , struct V_252 * V_253 ,
bool V_254 )
{
if ( ! F_62 ( V_5 ) )
return - V_255 ;
V_253 -> V_30 = F_121 ( V_5 , V_211 ,
V_253 -> V_256 , V_253 -> V_257 ,
V_254 ) ;
return 0 ;
}
long F_122 ( struct V_258 * V_259 ,
unsigned int V_260 , unsigned long V_261 )
{
struct V_5 * V_5 = V_259 -> V_262 ;
void T_7 * V_263 = ( void T_7 * ) V_261 ;
int V_53 = - V_264 ;
switch ( V_260 ) {
case V_265 :
V_53 = - V_266 ;
V_53 = F_123 ( V_5 ) ;
if ( V_53 )
goto V_163;
V_53 = F_124 ( V_5 ) ;
if ( V_53 ) {
F_125 ( & V_5 -> V_267 ) ;
F_126 ( V_5 ) ;
F_127 ( & V_5 -> V_267 ) ;
goto V_163;
}
break;
case V_268 : {
struct V_213 V_214 ;
V_53 = - V_266 ;
if ( F_128 ( & V_214 , V_263 , sizeof V_214 ) )
goto V_163;
V_53 = - V_255 ;
if ( ! F_62 ( V_5 ) )
goto V_163;
V_53 = F_114 ( V_5 , & V_214 ) ;
if ( V_53 )
goto V_163;
V_53 = - V_266 ;
if ( F_129 ( V_263 , & V_214 , sizeof V_214 ) )
goto V_163;
V_53 = 0 ;
break;
}
case V_269 : {
struct V_213 V_214 ;
V_53 = - V_266 ;
if ( F_128 ( & V_214 , V_263 , sizeof V_214 ) )
goto V_163;
V_53 = - V_255 ;
if ( ! F_62 ( V_5 ) )
goto V_163;
V_53 = F_116 ( V_5 , & V_214 ) ;
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
int F_130 ( struct V_1 * V_2 ,
struct V_270 * V_271 )
{
return - V_40 ;
}
int F_131 ( struct V_1 * V_2 ,
struct V_270 * V_271 )
{
return - V_40 ;
}
int F_132 ( struct V_1 * V_2 ,
struct V_272 * V_273 )
{
return - V_40 ;
}
static int F_133 ( void )
{
if ( ! V_36 && ( V_274 < V_275 ) ) {
V_36 = F_106 ( V_197 ,
F_107 ( V_276 ) ) ;
if ( ! V_36 )
return - V_277 ;
memset ( ( void * ) V_36 , 0 , V_276 ) ;
V_45 = V_36 + V_278 ;
F_23 ( V_50 L_12 ,
V_36 , V_45 ) ;
}
return 0 ;
}
static void F_134 ( void )
{
if ( V_36 ) {
memset ( ( void * ) V_36 , 0 , V_276 ) ;
F_135 ( V_36 , F_107 ( V_276 ) ) ;
V_36 = 0 ;
V_45 = 0 ;
V_42 = 0 ;
}
}
static int F_136 ( struct V_1 * V_2 )
{
int V_12 ;
union V_279 V_280 ;
struct V_24 * V_24 = F_42 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
if ( F_137 ( V_24 ) )
return F_138 ( V_24 ) ;
for ( V_12 = 0 ; V_12 < 5 ; V_12 ++ )
V_24 -> V_281 [ V_12 ] = F_139 ( V_12 ) ;
V_280 . V_282 = V_24 -> V_281 [ 3 ] ;
V_280 . V_283 = 4 ;
V_24 -> V_281 [ 3 ] = V_280 . V_282 ;
V_24 -> V_284 . V_285 = 1 ;
V_24 -> V_284 . V_286 = 1 ;
V_24 -> V_284 . V_287 = 1 ;
V_24 -> V_284 . V_288 = 1 ;
V_24 -> V_284 . V_289 = 1 ;
V_24 -> V_284 . V_290 = 1 ;
V_24 -> V_284 . V_291 = 1 ;
V_24 -> V_292 . V_293 = 1 ;
V_24 -> V_294 = V_46 ;
return 0 ;
}
static int F_140 ( struct V_1 * V_2 )
{
long V_295 ;
struct V_24 * V_24 = V_2 -> V_6 . V_24 ;
unsigned long V_296 ;
V_296 = V_186 -> V_296 ;
F_23 ( V_50 L_13 , V_2 , V_296 ) ;
V_295 = F_13 ( ( T_1 * ) V_24 , ( T_1 * ) V_296 , 0 ) ;
if ( V_295 ) {
F_23 ( V_85 L_14 ) ;
return - V_40 ;
}
return 0 ;
}
static void F_141 ( struct V_1 * V_2 )
{
T_8 V_297 = { 0 } ;
F_142 ( & V_297 ) ;
V_2 -> V_6 . V_21 = V_297 . V_298 ;
V_2 -> V_6 . V_22 [ 0 ] = V_297 . V_299 [ 0 ] ;
V_2 -> V_6 . V_22 [ 1 ] = V_297 . V_299 [ 1 ] ;
V_2 -> V_6 . V_23 [ 0 ] = V_297 . V_300 [ 0 ] ;
V_2 -> V_6 . V_23 [ 1 ] = V_297 . V_300 [ 1 ] ;
}
static void F_143 ( struct V_1 * V_2 )
{
struct V_143 * V_144 = & V_2 -> V_6 . V_145 ;
if ( F_68 ( V_144 ) )
F_144 ( V_144 , V_151 ) ;
}
static enum V_301 F_145 ( struct V_143 * V_82 )
{
struct V_1 * V_2 ;
T_9 * V_302 ;
V_2 = F_146 ( V_82 , struct V_1 , V_6 . V_145 ) ;
V_302 = & V_2 -> V_120 ;
if ( V_2 -> V_6 . V_118 != V_152 )
goto V_163;
if ( F_51 ( V_302 ) )
F_52 ( V_302 ) ;
V_163:
V_2 -> V_6 . V_303 = 1 ;
V_2 -> V_6 . V_149 = 1 ;
return V_304 ;
}
bool F_147 ( struct V_1 * V_2 )
{
return F_62 ( V_2 -> V_5 ) == ( V_2 -> V_6 . V_305 != NULL ) ;
}
int F_148 ( struct V_1 * V_2 )
{
struct V_1 * V_306 ;
int V_53 ;
int V_12 ;
long V_147 ;
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_106 * V_107 = F_50 ( V_2 ) ;
union V_174 * V_307 = & V_2 -> V_6 . V_227 ;
struct V_1 * V_308 = F_149 ( V_2 -> V_5 , V_2 ) ;
if ( F_137 ( V_308 ) )
return F_138 ( V_308 ) ;
if ( F_150 ( V_2 ) ) {
V_2 -> V_6 . V_118 = V_119 ;
V_107 -> V_113 = V_309 ;
V_147 = 0UL - F_1 ( V_2 ) ;
for ( V_12 = 0 ; V_12 < V_310 ; V_12 ++ ) {
V_306 = (struct V_1 * ) ( ( char * ) V_2 +
sizeof( struct V_311 ) * V_12 ) ;
V_306 -> V_6 . V_147 = V_147 ;
V_306 -> V_6 . V_240 = 0 ;
}
} else
V_2 -> V_6 . V_118 = V_130 ;
V_53 = - V_277 ;
V_2 -> V_6 . V_305 = F_151 ( sizeof( struct V_312 ) , V_197 ) ;
if ( ! V_2 -> V_6 . V_305 )
goto V_163;
V_2 -> V_6 . V_305 -> V_2 = V_2 ;
V_307 -> V_313 [ 1 ] = 0 ;
V_307 -> V_313 [ 12 ] = ( unsigned long ) ( ( char * ) V_308 + V_314 ) ;
V_307 -> V_313 [ 13 ] = ( unsigned long ) V_308 ;
V_307 -> V_169 = 0x1008522000UL ;
V_307 -> V_315 [ 40 ] = V_316 ;
V_307 -> V_317 = 0 ;
V_307 -> V_318 = 0x0 ;
V_307 -> V_315 [ 36 ] = 0x0 ;
V_307 -> V_315 [ 19 ] = 0x0 ;
V_307 -> V_315 [ 18 ] = ( unsigned long ) V_308 +
( ( sizeof( struct V_1 ) + 15 ) & ~ 15 ) ;
V_307 -> V_315 [ 64 ] = 0x0 ;
V_307 -> V_319 [ 0 ] = 0x7e04UL ;
V_307 -> V_319 [ 2 ] = ( unsigned long ) V_186 -> V_296 ;
V_307 -> V_319 [ 8 ] = 0x3c ;
V_307 -> V_320 [ 0 ] = 0x30 ;
V_307 -> V_320 [ 1 ] = 0x30 ;
V_307 -> V_320 [ 2 ] = 0x30 ;
V_307 -> V_320 [ 3 ] = 0x30 ;
V_307 -> V_320 [ 4 ] = 0x30 ;
V_307 -> V_320 [ 5 ] = 0x30 ;
V_307 -> V_320 [ 7 ] = 0x30 ;
V_307 -> V_321 [ 0 ] = * ( unsigned long * ) V_186 -> V_322 ;
V_2 -> V_6 . V_173 = V_5 -> V_6 . V_208 ;
V_2 -> V_6 . V_204 = V_5 -> V_6 . V_204 ;
V_2 -> V_6 . V_206 = V_5 -> V_6 . V_206 ;
F_152 ( & V_2 -> V_6 . V_145 , V_323 , V_151 ) ;
V_2 -> V_6 . V_145 . V_324 = F_145 ;
V_2 -> V_6 . V_170 = - 1 ;
V_2 -> V_6 . V_24 = (struct V_24 * ) F_153 ( V_2 -> V_325 ) ;
V_2 -> V_6 . V_326 = V_42 ;
V_2 -> V_6 . V_327 = V_328 ;
V_2 -> V_6 . V_329 = F_18 ( & V_5 -> V_6 . V_330 ) ;
V_2 -> V_6 . V_331 . V_332 = (struct V_230 * ) F_154 ( V_2 -> V_325 ) ;
V_2 -> V_6 . V_333 . V_332 = (struct V_230 * ) F_155 ( V_2 -> V_325 ) ;
F_141 ( V_2 ) ;
V_53 = 0 ;
V_163:
return V_53 ;
}
static int F_156 ( struct V_1 * V_2 , int V_100 )
{
unsigned long V_169 ;
int V_53 ;
F_10 ( V_169 ) ;
V_53 = F_78 ( V_2 ) ;
F_12 ( V_169 ) ;
if ( V_53 )
goto V_334;
V_53 = F_157 ( V_2 , V_2 -> V_5 , V_100 ) ;
if ( V_53 )
goto V_334;
V_53 = F_136 ( V_2 ) ;
if ( V_53 ) {
F_23 ( V_50 L_15 ) ;
goto V_335;
}
V_53 = F_140 ( V_2 ) ;
if ( V_53 )
goto V_335;
F_79 ( V_2 ) ;
return 0 ;
V_335:
F_158 ( V_2 ) ;
V_334:
return V_53 ;
}
struct V_1 * F_159 ( struct V_5 * V_5 ,
unsigned int V_100 )
{
struct V_1 * V_2 ;
unsigned long V_165 = V_5 -> V_6 . V_165 ;
int V_53 ;
int V_131 ;
F_105 ( sizeof( struct V_1 ) > V_336 / 2 ) ;
V_53 = - V_40 ;
if ( V_100 >= V_310 ) {
F_23 ( V_85 L_16 ,
V_310 ) ;
goto V_334;
}
V_53 = - V_277 ;
if ( ! V_165 ) {
F_23 ( V_85 L_17 , V_100 ) ;
goto V_334;
}
V_2 = (struct V_1 * ) ( V_165 + F_108 ( struct V_199 ,
V_337 [ V_100 ] . V_338 ) ) ;
V_2 -> V_5 = V_5 ;
V_131 = F_160 () ;
V_53 = F_156 ( V_2 , V_100 ) ;
F_161 () ;
if ( V_53 ) {
F_23 ( V_50 L_18 ) ;
goto V_334;
}
return V_2 ;
V_334:
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
int F_165 ( struct V_1 * V_2 , struct V_339 * V_340 )
{
return - V_40 ;
}
int F_166 ( struct V_1 * V_2 , struct V_339 * V_340 )
{
return - V_40 ;
}
int F_167 ( struct V_1 * V_2 ,
struct V_341 * V_342 )
{
return - V_40 ;
}
void F_168 ( struct V_5 * V_5 )
{
unsigned long V_165 = V_5 -> V_6 . V_165 ;
if ( V_165 ) {
memset ( ( void * ) V_165 , 0 , V_198 ) ;
F_135 ( V_165 , F_107 ( V_198 ) ) ;
}
}
static void F_169 ( struct V_5 * V_5 )
{
struct V_343 * V_344 ;
struct V_345 * V_346 ;
int V_13 ;
V_344 = V_343 ( V_5 ) ;
F_170 (memslot, slots) {
for ( V_13 = 0 ; V_13 < V_346 -> V_347 ; V_13 ++ ) {
if ( V_346 -> V_348 [ V_13 ] )
F_171 ( (struct V_349 * ) V_346 -> V_348 [ V_13 ] ) ;
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
F_176 ( V_5 -> V_6 . V_350 ) ;
F_169 ( V_5 ) ;
}
void F_177 ( struct V_1 * V_2 )
{
}
void F_178 ( struct V_1 * V_2 , int V_131 )
{
if ( V_131 != V_2 -> V_131 ) {
V_2 -> V_131 = V_131 ;
if ( V_2 -> V_6 . V_150 )
F_143 ( V_2 ) ;
}
}
int F_179 ( struct V_1 * V_2 , struct V_218 * V_107 )
{
struct V_24 * V_24 = F_42 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
int V_12 ;
F_180 ( V_2 ) ;
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
F_181 ( V_118 ) ;
F_181 ( V_173 ) ;
memcpy ( V_107 -> V_229 , V_2 -> V_6 . V_229 , sizeof( struct V_230 ) * V_231 ) ;
memcpy ( V_107 -> V_232 , V_2 -> V_6 . V_232 , sizeof( struct V_230 ) * V_233 ) ;
F_181 ( V_234 ) ;
F_181 ( V_235 ) ;
F_181 ( V_236 ) ;
F_181 ( V_237 ) ;
F_181 ( V_238 ) ;
F_181 ( V_149 ) ;
F_181 ( V_239 ) ;
F_181 ( V_240 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_107 -> V_241 [ V_12 ] = V_2 -> V_6 . V_241 [ V_12 ] ;
V_107 -> V_242 [ V_12 ] = V_2 -> V_6 . V_242 [ V_12 ] ;
V_107 -> V_243 [ V_12 ] = V_2 -> V_6 . V_243 [ V_12 ] ;
}
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ )
V_107 -> V_244 [ V_12 ] = V_2 -> V_6 . V_244 [ V_12 ] ;
V_107 -> V_250 = V_2 -> V_6 . V_147 + F_1 ( V_2 ) ;
F_181 ( V_245 ) ;
F_181 ( V_204 ) ;
F_181 ( V_206 ) ;
F_181 ( V_246 ) ;
F_181 ( V_247 ) ;
F_181 ( V_248 ) ;
F_181 ( V_249 ) ;
F_182 ( V_2 ) ;
return 0 ;
}
int F_183 ( struct V_1 * V_2 ,
struct V_351 * V_352 )
{
memcpy ( V_352 , V_2 , sizeof( struct V_351 ) ) ;
return 0 ;
}
int F_184 ( struct V_1 * V_2 ,
struct V_351 * V_352 )
{
memcpy ( V_2 + 1 , & V_352 -> V_352 [ 0 ] + sizeof( struct V_1 ) ,
sizeof( struct V_351 ) - sizeof( struct V_1 ) ) ;
V_2 -> V_6 . V_353 = ( (struct V_1 * ) V_352 ) -> V_6 . V_353 ;
return 0 ;
}
void F_185 ( struct V_1 * V_2 )
{
F_68 ( & V_2 -> V_6 . V_145 ) ;
F_176 ( V_2 -> V_6 . V_305 ) ;
}
long F_186 ( struct V_258 * V_259 ,
unsigned int V_260 , unsigned long V_261 )
{
struct V_1 * V_2 = V_259 -> V_262 ;
void T_7 * V_263 = ( void T_7 * ) V_261 ;
struct V_351 * V_352 = NULL ;
long V_53 ;
switch ( V_260 ) {
case V_354 : {
struct V_351 T_7 * V_355 ;
void T_7 * V_356 = V_263 ;
V_53 = - V_266 ;
if ( F_128 ( & V_355 , V_356 , sizeof( void * ) ) )
goto V_163;
if ( ! F_187 ( V_357 , V_355 ,
sizeof( struct V_351 ) ) ) {
F_23 ( V_48 L_19
L_20 ) ;
goto V_163;
}
V_352 = F_151 ( sizeof( struct V_351 ) , V_197 ) ;
if ( ! V_352 ) {
V_53 = - V_277 ;
goto V_163;
}
V_53 = F_183 ( V_2 , V_352 ) ;
if ( V_53 )
goto V_163;
if ( F_129 ( V_355 , V_352 ,
sizeof( struct V_351 ) ) ) {
V_53 = - V_266 ;
goto V_163;
}
break;
}
case V_358 : {
struct V_351 T_7 * V_355 ;
void T_7 * V_356 = V_263 ;
V_53 = - V_266 ;
if ( F_128 ( & V_355 , V_356 , sizeof( void * ) ) )
goto V_163;
if ( ! F_187 ( V_359 , V_355 ,
sizeof( struct V_351 ) ) ) {
F_23 ( V_48 L_21
L_22 ) ;
goto V_163;
}
V_352 = F_188 ( sizeof( struct V_351 ) , V_197 ) ;
if ( ! V_352 ) {
V_53 = - V_277 ;
goto V_163;
}
if ( F_128 ( V_352 , V_355 ,
sizeof( struct V_351 ) ) )
goto V_163;
V_53 = F_184 ( V_2 , V_352 ) ;
break;
}
default:
V_53 = - V_40 ;
}
V_163:
F_176 ( V_352 ) ;
return V_53 ;
}
int F_189 ( struct V_1 * V_2 , struct V_360 * V_361 )
{
return V_362 ;
}
void F_190 ( struct V_5 * V_5 , struct V_345 * free ,
struct V_345 * V_363 )
{
}
int F_191 ( struct V_5 * V_5 , struct V_345 * V_35 ,
unsigned long V_347 )
{
return 0 ;
}
void F_192 ( struct V_5 * V_5 )
{
}
int F_193 ( struct V_5 * V_5 ,
struct V_345 * V_346 ,
struct V_364 * V_365 ,
enum V_366 V_367 )
{
unsigned long V_12 ;
unsigned long V_368 ;
int V_347 = V_346 -> V_347 ;
unsigned long V_369 = V_346 -> V_369 ;
if ( V_369 + V_347 > ( V_370 >> V_137 ) )
return - V_277 ;
for ( V_12 = 0 ; V_12 < V_347 ; V_12 ++ ) {
V_368 = F_194 ( V_5 , V_369 + V_12 ) ;
if ( ! F_195 ( V_368 ) ) {
F_110 ( V_5 , V_369 + V_12 ,
V_368 << V_137 ,
V_371 | V_372 ) ;
V_346 -> V_348 [ V_12 ] = ( unsigned long ) F_196 ( V_368 ) ;
} else {
F_110 ( V_5 , V_369 + V_12 ,
V_373 | ( V_368 << V_137 ) ,
V_374 ) ;
V_346 -> V_348 [ V_12 ] = 0 ;
}
}
return 0 ;
}
void F_197 ( struct V_5 * V_5 ,
struct V_364 * V_365 ,
const struct V_345 * V_375 ,
enum V_366 V_367 )
{
return;
}
void F_198 ( struct V_5 * V_5 )
{
F_199 ( V_5 ) ;
}
void F_200 ( struct V_5 * V_5 ,
struct V_345 * V_35 )
{
F_198 () ;
}
long F_201 ( struct V_258 * V_259 ,
unsigned int V_260 , unsigned long V_261 )
{
return - V_40 ;
}
void F_202 ( struct V_1 * V_2 )
{
F_158 ( V_2 ) ;
}
static int F_203 ( void )
{
long V_376 = 1 , V_30 = 1 , V_377 = 1 ;
long V_295 ;
V_295 = F_204 ( & V_376 , & V_30 , & V_377 , 0 ) ;
if ( V_295 )
goto V_163;
if ( ! ( V_376 & V_378 ) )
goto V_163;
F_23 ( V_50 L_23 ) ;
V_295 = F_205 ( & V_274 , & V_379 ) ;
if ( V_295 )
goto V_163;
F_23 ( V_50 L_24 , V_274 ) ;
if ( ! ( V_379 & V_380 ) ) {
F_23 ( V_47 L_25
L_26 , V_379 ) ;
}
return 1 ;
V_163:
return 0 ;
}
static void F_206 ( struct V_186 * V_381 ,
struct V_382 * V_382 )
{
unsigned long V_383 , V_384 ;
unsigned long V_385 ;
if ( ! F_112 ( L_11 ) )
return;
V_385 = ( unsigned long ) V_382 -> V_386 ;
V_383 = V_36 + V_381 -> V_387 - V_385 ;
V_384 = V_36 + V_381 -> V_388 - V_385 ;
F_23 ( V_48 L_27
L_28 ) ;
memcpy ( ( void * ) V_383 , ( void * ) V_384 , 0x60 ) ;
}
static int F_207 ( struct V_186 * V_381 ,
struct V_382 * V_382 )
{
unsigned long V_385 ;
unsigned long V_389 ;
unsigned long V_390 , V_391 , V_392 ;
struct V_393 * V_394 ;
F_105 ( ! V_382 ) ;
if ( ! V_36 ) {
F_23 ( L_29 ) ;
return - V_266 ;
}
V_385 = ( unsigned long ) V_382 -> V_386 ;
V_389 = V_382 -> V_395 ;
if ( F_103 ( V_389 > V_276 ) )
return - V_266 ;
memcpy ( ( void * ) V_36 , ( void * ) V_385 , V_389 ) ;
F_206 ( V_381 , V_382 ) ;
F_5 ( V_36 , V_389 ) ;
V_390 = V_381 -> V_296 - V_385 ;
V_186 -> V_296 = V_38 + V_390 ;
F_23 ( V_50 L_30 ,
V_186 -> V_296 ) ;
V_392 = ( unsigned long ) V_381 -> V_322 - V_385 ;
V_186 -> V_322 = ( V_396 * ) ( V_38 +
V_392 ) ;
V_391 = * ( unsigned long * ) V_381 -> V_322 - V_385 ;
V_394 = (struct V_393 * ) ( V_36 + V_392 ) ;
V_394 -> V_397 = V_38 + V_391 ;
V_394 -> V_398 = V_38 + ( V_394 -> V_398 - V_385 ) ;
F_23 ( V_50 L_31 ,
V_38 + V_391 ) ;
V_392 = ( unsigned long ) V_381 -> V_187 - V_385 ;
V_186 -> V_187 = ( V_399 * ) ( V_38 +
V_392 ) ;
V_391 = * ( unsigned long * ) V_381 -> V_187 - V_385 ;
V_394 = (struct V_393 * ) ( V_36 + V_392 ) ;
V_394 -> V_397 = V_38 + V_391 ;
V_394 -> V_398 = V_38 + ( V_394 -> V_398 - V_385 ) ;
V_328 = V_394 -> V_398 ;
F_23 ( V_50 L_32 ,
V_186 -> V_322 ) ;
F_23 ( V_50 L_33 ,
V_38 + V_391 ) ;
return 0 ;
}
int F_208 ( void * V_400 )
{
int V_53 ;
struct V_186 * V_381 = (struct V_186 * ) V_400 ;
if ( ! F_203 () ) {
F_23 ( V_85 L_34 ) ;
V_53 = - V_401 ;
goto V_163;
}
if ( V_186 ) {
F_23 ( V_85 L_35 ) ;
V_53 = - V_402 ;
goto V_163;
}
V_53 = - V_277 ;
V_186 = F_151 ( sizeof( struct V_186 ) , V_197 ) ;
if ( ! V_186 )
goto V_163;
if ( F_133 () )
goto V_403;
V_53 = F_207 ( V_381 , V_381 -> V_382 ) ;
if ( V_53 )
goto V_404;
return 0 ;
V_404:
F_134 () ;
V_403:
F_176 ( V_186 ) ;
V_163:
return V_53 ;
}
void F_209 ( void )
{
F_134 () ;
F_176 ( V_186 ) ;
V_186 = NULL ;
}
static void F_210 ( struct V_5 * V_5 ,
struct V_345 * V_346 )
{
int V_12 ;
long V_298 ;
unsigned long V_405 ;
unsigned long * V_406 = ( unsigned long * ) ( V_5 -> V_6 . V_165 +
F_108 ( struct V_199 , V_407 ) ) ;
V_405 = F_211 ( V_346 ) ;
V_298 = V_346 -> V_369 / V_408 ;
F_20 ( & V_5 -> V_6 . V_330 ) ;
for ( V_12 = 0 ; V_12 < V_405 / sizeof( long ) ; ++ V_12 ) {
V_346 -> V_406 [ V_12 ] = V_406 [ V_298 + V_12 ] ;
V_406 [ V_298 + V_12 ] = 0 ;
}
F_22 ( & V_5 -> V_6 . V_330 ) ;
}
int F_212 ( struct V_5 * V_5 ,
struct V_409 * log )
{
int V_53 ;
unsigned long V_405 ;
struct V_345 * V_346 ;
int V_410 = 0 ;
F_125 ( & V_5 -> V_267 ) ;
V_53 = - V_40 ;
if ( log -> V_35 >= V_411 )
goto V_163;
V_346 = F_213 ( V_5 -> V_412 , log -> V_35 ) ;
V_53 = - V_413 ;
if ( ! V_346 -> V_406 )
goto V_163;
F_210 ( V_5 , V_346 ) ;
V_53 = F_214 ( V_5 , log , & V_410 ) ;
if ( V_53 )
goto V_163;
if ( V_410 ) {
F_199 ( V_5 ) ;
V_405 = F_211 ( V_346 ) ;
memset ( V_346 -> V_406 , 0 , V_405 ) ;
}
V_53 = 0 ;
V_163:
F_127 ( & V_5 -> V_267 ) ;
return V_53 ;
}
int F_215 ( void )
{
return 0 ;
}
void F_216 ( void )
{
}
int F_217 ( struct V_1 * V_2 , struct V_414 * V_256 )
{
return F_41 ( V_2 , V_256 -> V_91 ) ;
}
int F_218 ( struct V_312 * V_305 , T_10 V_415 )
{
return V_305 -> V_2 -> V_325 == V_415 ;
}
int F_219 ( struct V_312 * V_305 , T_11 V_416 )
{
return 0 ;
}
int F_220 ( struct V_1 * V_417 , struct V_1 * V_418 )
{
return V_417 -> V_6 . V_245 - V_418 -> V_6 . V_245 ;
}
int F_221 ( struct V_1 * V_2 , struct V_312 * V_419 ,
int V_420 , int V_415 , int V_421 )
{
struct V_312 * V_422 = V_2 -> V_6 . V_305 ;
return ( V_421 == 0 ) ?
F_218 ( V_422 , V_415 ) :
F_219 ( V_422 , V_415 ) ;
}
static int F_222 ( int * V_423 )
{
T_5 V_424 , V_425 ;
int V_12 ;
for ( V_12 = 7 ; V_12 >= 0 ; V_12 -- ) {
V_424 = V_423 [ V_12 ] ;
if ( V_424 ) {
V_425 = F_223 ( V_424 ) ;
return V_12 * 32 + V_425 - 1 ;
}
}
return - 1 ;
}
int F_224 ( struct V_1 * V_2 )
{
struct V_24 * V_24 = F_42 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
if ( V_24 -> V_92 [ 0 ] & ( 1UL << V_426 ) )
return V_426 ;
if ( V_24 -> V_92 [ 0 ] & ( 1UL << V_427 ) )
return V_427 ;
return F_222 ( ( int * ) & V_24 -> V_92 [ 0 ] ) ;
}
int F_70 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_303 ;
}
int F_225 ( struct V_1 * V_2 )
{
return ( V_2 -> V_6 . V_118 == V_119 ) ||
( F_224 ( V_2 ) != - 1 ) ;
}
int F_226 ( struct V_1 * V_2 )
{
return ( ! F_43 ( V_182 , & V_2 -> V_124 ) ) ;
}
int F_227 ( struct V_1 * V_2 ,
struct V_428 * V_118 )
{
V_118 -> V_118 = V_2 -> V_6 . V_118 ;
return 0 ;
}
static int F_228 ( struct V_1 * V_2 )
{
int V_53 ;
long V_169 ;
F_10 ( V_169 ) ;
V_53 = F_78 ( V_2 ) ;
F_12 ( V_169 ) ;
if ( V_53 )
goto V_334;
V_2 -> V_6 . V_112 = 0 ;
F_185 ( V_2 ) ;
V_53 = F_148 ( V_2 ) ;
if ( V_53 )
goto V_334;
F_79 ( V_2 ) ;
V_53 = 0 ;
V_334:
return V_53 ;
}
int F_229 ( struct V_1 * V_2 ,
struct V_428 * V_118 )
{
int V_53 = 0 ;
V_2 -> V_6 . V_118 = V_118 -> V_118 ;
if ( V_2 -> V_6 . V_118 == V_130 )
V_53 = F_228 ( V_2 ) ;
return V_53 ;
}
