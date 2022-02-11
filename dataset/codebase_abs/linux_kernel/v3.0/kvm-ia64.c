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
V_53 = F_29 () ;
break;
default:
V_53 = 0 ;
}
return V_53 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_60 * V_60 )
{
V_60 -> V_61 = V_62 ;
V_60 -> V_63 . V_64 = 1 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_60 * V_60 )
{
struct V_65 * V_66 ;
struct V_67 * V_68 ;
int V_53 ;
V_66 = F_32 ( V_2 ) ;
if ( ( V_66 -> V_18 & V_69 ) == V_70 )
goto V_71;
V_2 -> V_72 = 1 ;
V_2 -> V_73 = V_60 -> V_71 . V_74 = V_66 -> V_18 ;
V_2 -> V_75 = V_60 -> V_71 . V_10 = V_66 -> V_76 ;
V_2 -> V_77 = V_60 -> V_71 . V_78 = ! V_66 -> V_79 ;
if ( V_2 -> V_77 )
memcpy ( V_2 -> V_80 , & V_66 -> V_81 , V_66 -> V_76 ) ;
memcpy ( V_60 -> V_71 . V_81 , & V_66 -> V_81 , V_66 -> V_76 ) ;
V_60 -> V_61 = V_82 ;
return 0 ;
V_71:
if ( V_66 -> V_79 )
V_53 = F_33 ( V_2 -> V_5 , V_83 , V_66 -> V_18 ,
V_66 -> V_76 , & V_66 -> V_81 ) ;
else
V_53 = F_34 ( V_2 -> V_5 , V_83 , V_66 -> V_18 ,
V_66 -> V_76 , & V_66 -> V_81 ) ;
if ( V_53 )
F_23 ( V_84 L_4 , V_66 -> V_18 ) ;
V_66 -> V_85 = V_86 ;
return 1 ;
}
static int F_35 ( struct V_1 * V_2 , struct V_60 * V_60 )
{
struct V_87 * V_66 ;
V_66 = F_36 ( V_2 ) ;
if ( V_66 -> V_61 == V_88 )
return F_37 ( V_2 , V_60 ) ;
else {
V_60 -> V_61 = V_62 ;
V_60 -> V_63 . V_64 = 2 ;
return 0 ;
}
}
static int F_38 ( struct V_1 * V_2 , struct V_60 * V_60 )
{
struct V_87 * V_66 ;
V_66 = F_36 ( V_2 ) ;
if ( V_66 -> V_61 == V_89 ) {
F_39 ( V_2 ) ;
return 1 ;
} else {
V_60 -> V_61 = V_62 ;
V_60 -> V_63 . V_64 = 3 ;
return 0 ;
}
}
static int F_40 ( struct V_1 * V_2 , T_2 V_90 )
{
struct V_24 * V_24 = F_41 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
if ( ! F_42 ( V_90 , & V_24 -> V_91 [ 0 ] ) ) {
V_2 -> V_6 . V_92 = 1 ;
F_43 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static void F_44 ( struct V_1 * V_2 , T_2 V_93 ,
T_2 V_90 )
{
switch ( V_93 ) {
case V_94 :
break;
case V_95 :
V_90 = 2 ;
break;
case V_96 :
V_90 = 0 ;
break;
case V_97 :
case V_98 :
default:
F_23 ( V_84 L_5 ) ;
return;
}
F_40 ( V_2 , V_90 ) ;
}
static struct V_1 * F_45 ( struct V_5 * V_5 , unsigned long V_99 ,
unsigned long V_100 )
{
union V_101 V_102 ;
int V_12 ;
struct V_1 * V_2 ;
F_46 (i, vcpu, kvm) {
V_102 . V_103 = F_47 ( V_2 ) ;
if ( V_102 . V_99 == V_99 && V_102 . V_100 == V_100 )
return V_2 ;
}
return NULL ;
}
static int F_48 ( struct V_1 * V_2 , struct V_60 * V_60 )
{
struct V_87 * V_66 = F_36 ( V_2 ) ;
struct V_1 * V_104 ;
struct V_105 * V_106 ;
union V_107 V_18 = V_66 -> V_108 . V_109 . V_18 ;
union V_110 V_81 = V_66 -> V_108 . V_109 . V_81 ;
V_104 = F_45 ( V_2 -> V_5 , V_18 . V_99 , V_18 . V_100 ) ;
if ( ! V_104 )
return F_30 ( V_2 , V_60 ) ;
if ( ! V_104 -> V_6 . V_111 ) {
V_106 = F_49 ( V_104 ) ;
V_106 -> V_112 = V_2 -> V_5 -> V_6 . V_113 . V_114 ;
V_106 -> V_115 = V_2 -> V_5 -> V_6 . V_113 . V_116 ;
V_104 -> V_6 . V_117 = V_118 ;
if ( F_50 ( & V_104 -> V_119 ) )
F_51 ( & V_104 -> V_119 ) ;
} else {
F_44 ( V_104 , V_81 . V_93 , V_81 . V_90 ) ;
if ( V_104 != V_2 )
F_43 ( V_104 ) ;
}
return 1 ;
}
static void F_52 ( void * V_120 )
{
struct V_121 * V_66 = (struct V_121 * ) V_120 ;
struct V_1 * V_2 = V_66 -> V_2 ;
if ( F_53 ( V_122 , & V_2 -> V_123 ) )
return;
F_54 ( V_124 , & V_2 -> V_123 ) ;
if ( V_2 -> V_6 . V_125 < V_126 ) {
V_2 -> V_6 . V_127 [ V_2 -> V_6 . V_125 ++ ] =
V_66 -> V_127 ;
} else {
F_55 ( V_124 , & V_2 -> V_123 ) ;
V_2 -> V_6 . V_125 = 0 ;
F_54 ( V_122 , & V_2 -> V_123 ) ;
}
}
static int F_56 ( struct V_1 * V_2 , struct V_60 * V_60 )
{
struct V_87 * V_66 = F_36 ( V_2 ) ;
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_121 V_121 ;
int V_12 ;
struct V_1 * V_128 ;
V_121 . V_127 = V_66 -> V_108 . V_127 ;
F_46 (i, vcpui, kvm) {
if ( V_128 -> V_6 . V_117 == V_129 ||
V_2 == V_128 )
continue;
if ( F_50 ( & V_128 -> V_119 ) )
F_51 ( & V_128 -> V_119 ) ;
if ( V_128 -> V_130 != - 1 ) {
V_121 . V_2 = V_128 ;
F_57 ( V_128 -> V_130 ,
F_52 , & V_121 , 1 ) ;
} else
F_23 ( V_47 L_6 ) ;
}
return 1 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_60 * V_60 )
{
return 1 ;
}
static int F_59 ( struct V_1 * V_2 )
{
unsigned long V_33 , V_131 , V_132 ;
int V_35 ;
V_132 = V_38 + ( 1UL << V_39 ) ;
V_131 = V_133 | V_134 ;
V_33 = F_16 ( F_17 ( V_131 , V_135 ) ) ;
V_35 = F_19 ( 0x3 , V_132 , V_33 , V_136 ) ;
V_2 -> V_6 . V_137 = V_35 ;
if ( V_35 < 0 ) {
F_23 ( V_84 L_7 ) ;
V_35 = 0 ;
}
return V_35 ;
}
int F_60 ( struct V_1 * V_2 )
{
T_3 V_138 ;
long V_139 ;
unsigned long V_140 ;
unsigned long V_141 ;
struct V_142 * V_143 = & V_2 -> V_6 . V_144 ;
unsigned long V_145 = V_20 -> V_145 ;
struct V_24 * V_24 = F_41 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
if ( F_61 ( V_2 -> V_5 ) ) {
V_140 = F_1 ( V_2 ) + V_2 -> V_6 . V_146 ;
if ( F_62 ( V_140 , V_24 -> V_147 ) ) {
V_2 -> V_6 . V_148 = 1 ;
return 1 ;
}
V_139 = V_24 -> V_147 - V_140 ;
if ( V_139 < 0 )
V_139 = - V_139 ;
V_141 = F_63 ( V_139 , V_145 ) ;
V_138 = F_64 ( 0 , 1000 * V_141 ) ;
V_2 -> V_6 . V_149 = 1 ;
F_65 ( V_143 , V_138 , V_150 ) ;
V_2 -> V_6 . V_117 = V_151 ;
F_66 ( V_2 ) ;
F_67 ( V_143 ) ;
V_2 -> V_6 . V_149 = 0 ;
if ( F_68 ( V_152 , & V_2 -> V_123 ) ||
F_69 ( V_2 ) )
if ( V_2 -> V_6 . V_117 == V_151 )
V_2 -> V_6 . V_117 = V_118 ;
if ( V_2 -> V_6 . V_117 != V_118 )
return - V_153 ;
return 1 ;
} else {
F_23 ( V_84 L_8 ) ;
return 0 ;
}
}
static int F_70 ( struct V_1 * V_2 ,
struct V_60 * V_60 )
{
V_60 -> V_61 = V_154 ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_60 * V_60 )
{
return 1 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_60 * V_60 )
{
F_23 ( L_9 , V_2 -> V_6 . V_155 ) ;
return 1 ;
}
static T_4 F_73 ( struct V_1 * V_2 )
{
struct V_87 * V_156 ;
V_156 = F_36 ( V_2 ) ;
return V_156 -> V_61 ;
}
static int F_74 ( struct V_60 * V_60 , struct V_1 * V_2 )
{
T_5 V_61 = F_73 ( V_2 ) ;
V_2 -> V_6 . V_157 = V_61 ;
if ( V_61 < V_158
&& V_159 [ V_61 ] )
return V_159 [ V_61 ] ( V_2 , V_60 ) ;
else {
V_60 -> V_61 = V_62 ;
V_60 -> V_63 . V_64 = V_61 ;
}
return 0 ;
}
static inline void F_75 ( unsigned long V_160 )
{
F_76 ( V_161 , V_160 ) ;
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
goto V_162;
V_2 -> V_6 . V_163 = V_53 ;
V_33 = F_16 ( F_17 ( F_18 ( V_5 -> V_6 . V_164 ) , V_37 ) ) ;
V_53 = F_19 ( 0x3 , V_165 ,
V_33 , V_166 ) ;
if ( V_53 < 0 )
goto V_162;
V_2 -> V_6 . V_167 = V_53 ;
#if F_2 ( V_3 ) || F_2 ( V_4 )
if ( V_5 -> V_6 . V_7 ) {
V_53 = F_59 ( V_2 ) ;
if ( V_53 < 0 )
goto V_162;
}
#endif
V_53 = 0 ;
V_162:
return V_53 ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
F_24 ( 0x3 , V_2 -> V_6 . V_163 ) ;
F_24 ( 0x3 , V_2 -> V_6 . V_167 ) ;
#if F_2 ( V_3 ) || F_2 ( V_4 )
if ( V_5 -> V_6 . V_7 )
F_24 ( 0x3 , V_2 -> V_6 . V_137 ) ;
#endif
}
static int F_79 ( struct V_1 * V_2 )
{
unsigned long V_168 ;
int V_53 ;
int V_130 = F_80 () ;
if ( V_2 -> V_6 . V_169 != V_130 ||
F_81 ( V_170 , V_130 ) != V_2 ) {
F_81 ( V_170 , V_130 ) = V_2 ;
V_2 -> V_6 . V_169 = V_130 ;
F_9 () ;
}
V_2 -> V_6 . V_171 = F_82 ( V_161 ) ;
F_75 ( V_2 -> V_6 . V_172 ) ;
F_10 ( V_168 ) ;
V_53 = F_77 ( V_2 ) ;
F_12 ( V_168 ) ;
return V_53 ;
}
static void F_83 ( struct V_1 * V_2 )
{
F_78 ( V_2 ) ;
F_75 ( V_2 -> V_6 . V_171 ) ;
}
static int F_84 ( struct V_1 * V_2 , struct V_60 * V_60 )
{
union V_173 * V_174 , * V_175 ;
int V_53 , V_176 ;
V_176 = F_85 ( & V_2 -> V_5 -> V_177 ) ;
V_178:
if ( F_86 ( V_179 ) ) {
V_53 = - V_153 ;
V_60 -> V_61 = V_180 ;
goto V_162;
}
F_87 () ;
F_88 () ;
V_174 = F_89 ( V_2 ) ;
V_175 = F_90 ( V_2 ) ;
F_55 ( V_181 , & V_2 -> V_123 ) ;
V_53 = F_79 ( V_2 ) ;
if ( V_53 < 0 )
goto V_182;
F_91 ( & V_2 -> V_5 -> V_177 , V_176 ) ;
V_2 -> V_183 = V_184 ;
F_92 () ;
V_185 -> V_186 ( V_174 , V_175 ) ;
F_83 ( V_2 ) ;
V_2 -> V_6 . V_111 = 1 ;
F_54 ( V_181 , & V_2 -> V_123 ) ;
F_93 () ;
F_94 () ;
F_95 () ;
V_2 -> V_183 = V_187 ;
F_96 () ;
V_176 = F_85 ( & V_2 -> V_5 -> V_177 ) ;
V_53 = F_74 ( V_60 , V_2 ) ;
if ( V_53 > 0 ) {
if ( ! F_97 () )
goto V_178;
}
V_162:
F_91 ( & V_2 -> V_5 -> V_177 , V_176 ) ;
if ( V_53 > 0 ) {
F_98 ( V_2 ) ;
V_176 = F_85 ( & V_2 -> V_5 -> V_177 ) ;
goto V_178;
}
return V_53 ;
V_182:
F_93 () ;
F_96 () ;
V_60 -> V_61 = V_188 ;
goto V_162;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = F_32 ( V_2 ) ;
if ( ! V_2 -> V_77 )
memcpy ( & V_66 -> V_81 , V_2 -> V_80 , 8 ) ;
V_66 -> V_85 = V_86 ;
}
int F_100 ( struct V_1 * V_2 , struct V_60 * V_60 )
{
int V_53 ;
T_6 V_189 ;
if ( V_2 -> V_190 )
F_101 ( V_191 , & V_2 -> V_192 , & V_189 ) ;
if ( F_102 ( V_2 -> V_6 . V_117 == V_129 ) ) {
F_66 ( V_2 ) ;
F_55 ( V_152 , & V_2 -> V_123 ) ;
V_53 = - V_193 ;
goto V_162;
}
if ( V_2 -> V_72 ) {
memcpy ( V_2 -> V_80 , V_60 -> V_71 . V_81 , 8 ) ;
F_99 ( V_2 ) ;
V_2 -> V_194 = 1 ;
V_2 -> V_72 = 0 ;
}
V_53 = F_84 ( V_2 , V_60 ) ;
V_162:
if ( V_2 -> V_190 )
F_101 ( V_191 , & V_189 , NULL ) ;
return V_53 ;
}
struct V_5 * F_103 ( void )
{
struct V_5 * V_5 ;
T_2 V_164 ;
F_104 ( sizeof( struct V_5 ) > V_195 ) ;
V_164 = F_105 ( V_196 , F_106 ( V_197 ) ) ;
if ( ! V_164 )
return NULL ;
memset ( ( void * ) V_164 , 0 , V_197 ) ;
V_5 = (struct V_5 * ) ( V_164 +
F_107 ( struct V_198 , V_199 ) ) ;
V_5 -> V_6 . V_164 = V_164 ;
F_23 ( V_50 L_10 , V_164 ) ;
return V_5 ;
}
static void F_108 ( struct V_5 * V_5 )
{
unsigned long V_12 , V_13 ;
for ( V_12 = 0 ; V_12 < ( sizeof( V_200 ) / sizeof( struct V_201 ) ) ;
V_12 ++ ) {
for ( V_13 = V_200 [ V_12 ] . V_9 ;
V_13 < V_200 [ V_12 ] . V_9 + V_200 [ V_12 ] . V_76 ;
V_13 += V_202 )
F_109 ( V_5 , V_13 >> V_136 ,
V_200 [ V_12 ] . type , 0 ) ;
}
}
int F_110 ( struct V_5 * V_5 )
{
F_104 ( ! V_5 ) ;
V_5 -> V_6 . V_7 = F_111 ( L_11 ) ;
V_5 -> V_6 . V_203 = V_204 ;
V_5 -> V_6 . V_205 = V_206 ;
V_5 -> V_6 . V_207 = V_208 ;
F_108 ( V_5 ) ;
F_112 ( & V_5 -> V_6 . V_209 ) ;
F_54 ( V_210 , & V_5 -> V_6 . V_211 ) ;
return 0 ;
}
static int F_113 ( struct V_5 * V_5 ,
struct V_212 * V_213 )
{
int V_53 ;
V_53 = 0 ;
switch ( V_213 -> V_214 ) {
case V_215 :
V_53 = F_114 ( V_5 , & V_213 -> V_213 . V_216 ) ;
break;
default:
V_53 = - V_40 ;
break;
}
return V_53 ;
}
static int F_115 ( struct V_5 * V_5 , struct V_212 * V_213 )
{
int V_53 ;
V_53 = 0 ;
switch ( V_213 -> V_214 ) {
case V_215 :
V_53 = F_116 ( V_5 , & V_213 -> V_213 . V_216 ) ;
break;
default:
V_53 = - V_40 ;
break;
}
return V_53 ;
}
int F_117 ( struct V_1 * V_2 , struct V_217 * V_106 )
{
struct V_24 * V_24 = F_41 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
V_24 -> V_218 [ V_12 ] = V_106 -> V_24 . V_218 [ V_12 ] ;
V_24 -> V_219 [ V_12 ] = V_106 -> V_24 . V_219 [ V_12 ] ;
}
for ( V_12 = 0 ; V_12 < 128 ; V_12 ++ )
V_24 -> V_220 [ V_12 ] = V_106 -> V_24 . V_220 [ V_12 ] ;
V_24 -> V_221 = V_106 -> V_24 . V_221 ;
V_24 -> V_222 = V_106 -> V_24 . V_222 ;
V_24 -> V_223 = V_106 -> V_24 . V_223 ;
V_24 -> V_224 = V_106 -> V_24 . V_224 ;
V_24 -> V_225 = V_106 -> V_24 . V_225 ;
memcpy ( & V_2 -> V_6 . V_226 , & V_106 -> V_227 , sizeof( union V_173 ) ) ;
F_118 ( V_117 ) ;
F_118 ( V_172 ) ;
memcpy ( V_2 -> V_6 . V_228 , V_106 -> V_228 , sizeof( struct V_229 ) * V_230 ) ;
memcpy ( V_2 -> V_6 . V_231 , V_106 -> V_231 , sizeof( struct V_229 ) * V_232 ) ;
F_118 ( V_233 ) ;
F_118 ( V_234 ) ;
F_118 ( V_235 ) ;
F_118 ( V_236 ) ;
F_118 ( V_237 ) ;
F_118 ( V_148 ) ;
F_118 ( V_238 ) ;
F_118 ( V_239 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_2 -> V_6 . V_240 [ V_12 ] = V_106 -> V_240 [ V_12 ] ;
V_2 -> V_6 . V_241 [ V_12 ] = V_106 -> V_241 [ V_12 ] ;
V_2 -> V_6 . V_242 [ V_12 ] = V_106 -> V_242 [ V_12 ] ;
}
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ )
V_2 -> V_6 . V_243 [ V_12 ] = V_106 -> V_243 [ V_12 ] ;
F_118 ( V_244 ) ;
F_118 ( V_203 ) ;
F_118 ( V_205 ) ;
F_118 ( V_245 ) ;
F_118 ( V_246 ) ;
F_118 ( V_247 ) ;
F_118 ( V_248 ) ;
V_2 -> V_6 . V_92 = 1 ;
V_2 -> V_6 . V_146 = V_106 -> V_249 - F_1 ( V_2 ) ;
F_54 ( V_250 , & V_2 -> V_123 ) ;
return 0 ;
}
long F_119 ( struct V_251 * V_252 ,
unsigned int V_253 , unsigned long V_254 )
{
struct V_5 * V_5 = V_252 -> V_255 ;
void T_7 * V_256 = ( void T_7 * ) V_254 ;
int V_53 = - V_257 ;
switch ( V_253 ) {
case V_258 : {
struct V_259 V_260 ;
struct V_261 V_262 ;
V_53 = - V_263 ;
if ( F_120 ( & V_260 , V_256 , sizeof V_260 ) )
goto V_162;
V_262 . V_35 = V_260 . V_35 ;
V_262 . V_19 = V_260 . V_19 ;
V_262 . V_264 =
V_260 . V_264 ;
V_262 . V_265 = V_260 . V_265 ;
V_53 = F_121 ( V_5 ,
& V_262 , 0 ) ;
if ( V_53 )
goto V_162;
break;
}
case V_266 :
V_53 = - V_263 ;
V_53 = F_122 ( V_5 ) ;
if ( V_53 )
goto V_162;
V_53 = F_123 ( V_5 ) ;
if ( V_53 ) {
F_124 ( & V_5 -> V_267 ) ;
F_125 ( V_5 ) ;
F_126 ( & V_5 -> V_267 ) ;
goto V_162;
}
break;
case V_268 :
case V_269 : {
struct V_270 V_271 ;
V_53 = - V_263 ;
if ( F_120 ( & V_271 , V_256 , sizeof V_271 ) )
goto V_162;
V_53 = - V_272 ;
if ( F_61 ( V_5 ) ) {
T_8 V_30 ;
V_30 = F_127 ( V_5 , V_210 ,
V_271 . V_273 , V_271 . V_274 ) ;
if ( V_253 == V_268 ) {
V_53 = - V_263 ;
V_271 . V_30 = V_30 ;
if ( F_128 ( V_256 , & V_271 ,
sizeof V_271 ) )
goto V_162;
}
V_53 = 0 ;
}
break;
}
case V_275 : {
struct V_212 V_213 ;
V_53 = - V_263 ;
if ( F_120 ( & V_213 , V_256 , sizeof V_213 ) )
goto V_162;
V_53 = - V_272 ;
if ( ! F_61 ( V_5 ) )
goto V_162;
V_53 = F_113 ( V_5 , & V_213 ) ;
if ( V_53 )
goto V_162;
V_53 = - V_263 ;
if ( F_128 ( V_256 , & V_213 , sizeof V_213 ) )
goto V_162;
V_53 = 0 ;
break;
}
case V_276 : {
struct V_212 V_213 ;
V_53 = - V_263 ;
if ( F_120 ( & V_213 , V_256 , sizeof V_213 ) )
goto V_162;
V_53 = - V_272 ;
if ( ! F_61 ( V_5 ) )
goto V_162;
V_53 = F_115 ( V_5 , & V_213 ) ;
if ( V_53 )
goto V_162;
V_53 = 0 ;
break;
}
default:
;
}
V_162:
return V_53 ;
}
int F_129 ( struct V_1 * V_2 ,
struct V_277 * V_278 )
{
return - V_40 ;
}
int F_130 ( struct V_1 * V_2 ,
struct V_277 * V_278 )
{
return - V_40 ;
}
int F_131 ( struct V_1 * V_2 ,
struct V_279 * V_280 )
{
return - V_40 ;
}
static int F_132 ( void )
{
if ( ! V_36 && ( V_281 < V_282 ) ) {
V_36 = F_105 ( V_196 ,
F_106 ( V_283 ) ) ;
if ( ! V_36 )
return - V_284 ;
memset ( ( void * ) V_36 , 0 , V_283 ) ;
V_45 = V_36 + V_285 ;
F_23 ( V_50 L_12 ,
V_36 , V_45 ) ;
}
return 0 ;
}
static void F_133 ( void )
{
if ( V_36 ) {
memset ( ( void * ) V_36 , 0 , V_283 ) ;
F_134 ( V_36 , F_106 ( V_283 ) ) ;
V_36 = 0 ;
V_45 = 0 ;
V_42 = 0 ;
}
}
static int F_135 ( struct V_1 * V_2 )
{
int V_12 ;
union V_286 V_287 ;
struct V_24 * V_24 = F_41 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
if ( F_136 ( V_24 ) )
return F_137 ( V_24 ) ;
for ( V_12 = 0 ; V_12 < 5 ; V_12 ++ )
V_24 -> V_288 [ V_12 ] = F_138 ( V_12 ) ;
V_287 . V_289 = V_24 -> V_288 [ 3 ] ;
V_287 . V_290 = 4 ;
V_24 -> V_288 [ 3 ] = V_287 . V_289 ;
V_24 -> V_291 . V_292 = 1 ;
V_24 -> V_291 . V_293 = 1 ;
V_24 -> V_291 . V_294 = 1 ;
V_24 -> V_291 . V_295 = 1 ;
V_24 -> V_291 . V_296 = 1 ;
V_24 -> V_291 . V_297 = 1 ;
V_24 -> V_291 . V_298 = 1 ;
V_24 -> V_299 . V_300 = 1 ;
V_24 -> V_301 = V_46 ;
return 0 ;
}
static int F_139 ( struct V_1 * V_2 )
{
long V_302 ;
struct V_24 * V_24 = V_2 -> V_6 . V_24 ;
unsigned long V_303 ;
V_303 = V_185 -> V_303 ;
F_23 ( V_50 L_13 , V_2 , V_303 ) ;
V_302 = F_13 ( ( T_1 * ) V_24 , ( T_1 * ) V_303 , 0 ) ;
if ( V_302 ) {
F_23 ( V_84 L_14 ) ;
return - V_40 ;
}
return 0 ;
}
static void F_140 ( struct V_1 * V_2 )
{
T_9 V_304 = { 0 } ;
F_141 ( & V_304 ) ;
V_2 -> V_6 . V_21 = V_304 . V_305 ;
V_2 -> V_6 . V_22 [ 0 ] = V_304 . V_306 [ 0 ] ;
V_2 -> V_6 . V_22 [ 1 ] = V_304 . V_306 [ 1 ] ;
V_2 -> V_6 . V_23 [ 0 ] = V_304 . V_307 [ 0 ] ;
V_2 -> V_6 . V_23 [ 1 ] = V_304 . V_307 [ 1 ] ;
}
static void F_142 ( struct V_1 * V_2 )
{
struct V_142 * V_143 = & V_2 -> V_6 . V_144 ;
if ( F_67 ( V_143 ) )
F_143 ( V_143 , V_150 ) ;
}
static enum V_308 F_144 ( struct V_142 * V_81 )
{
struct V_1 * V_2 ;
T_10 * V_309 ;
V_2 = F_145 ( V_81 , struct V_1 , V_6 . V_144 ) ;
V_309 = & V_2 -> V_119 ;
if ( V_2 -> V_6 . V_117 != V_151 )
goto V_162;
if ( F_50 ( V_309 ) )
F_51 ( V_309 ) ;
V_162:
V_2 -> V_6 . V_310 = 1 ;
V_2 -> V_6 . V_148 = 1 ;
return V_311 ;
}
int F_146 ( struct V_1 * V_2 )
{
struct V_1 * V_312 ;
int V_53 ;
int V_12 ;
long V_146 ;
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_105 * V_106 = F_49 ( V_2 ) ;
union V_173 * V_313 = & V_2 -> V_6 . V_226 ;
struct V_1 * V_314 = F_147 ( V_2 -> V_5 , V_2 ) ;
if ( F_136 ( V_314 ) )
return F_137 ( V_314 ) ;
if ( F_148 ( V_2 ) ) {
V_2 -> V_6 . V_117 = V_118 ;
V_106 -> V_112 = V_315 ;
V_146 = 0UL - F_1 ( V_2 ) ;
for ( V_12 = 0 ; V_12 < V_316 ; V_12 ++ ) {
V_312 = (struct V_1 * ) ( ( char * ) V_2 +
sizeof( struct V_317 ) * V_12 ) ;
V_312 -> V_6 . V_146 = V_146 ;
V_312 -> V_6 . V_239 = 0 ;
}
} else
V_2 -> V_6 . V_117 = V_129 ;
V_53 = - V_284 ;
V_2 -> V_6 . V_318 = F_149 ( sizeof( struct V_319 ) , V_196 ) ;
if ( ! V_2 -> V_6 . V_318 )
goto V_162;
V_2 -> V_6 . V_318 -> V_2 = V_2 ;
V_313 -> V_320 [ 1 ] = 0 ;
V_313 -> V_320 [ 12 ] = ( unsigned long ) ( ( char * ) V_314 + V_321 ) ;
V_313 -> V_320 [ 13 ] = ( unsigned long ) V_314 ;
V_313 -> V_168 = 0x1008522000UL ;
V_313 -> V_322 [ 40 ] = V_323 ;
V_313 -> V_324 = 0 ;
V_313 -> V_325 = 0x0 ;
V_313 -> V_322 [ 36 ] = 0x0 ;
V_313 -> V_322 [ 19 ] = 0x0 ;
V_313 -> V_322 [ 18 ] = ( unsigned long ) V_314 +
( ( sizeof( struct V_1 ) + 15 ) & ~ 15 ) ;
V_313 -> V_322 [ 64 ] = 0x0 ;
V_313 -> V_326 [ 0 ] = 0x7e04UL ;
V_313 -> V_326 [ 2 ] = ( unsigned long ) V_185 -> V_303 ;
V_313 -> V_326 [ 8 ] = 0x3c ;
V_313 -> V_327 [ 0 ] = 0x30 ;
V_313 -> V_327 [ 1 ] = 0x30 ;
V_313 -> V_327 [ 2 ] = 0x30 ;
V_313 -> V_327 [ 3 ] = 0x30 ;
V_313 -> V_327 [ 4 ] = 0x30 ;
V_313 -> V_327 [ 5 ] = 0x30 ;
V_313 -> V_327 [ 7 ] = 0x30 ;
V_313 -> V_328 [ 0 ] = * ( unsigned long * ) V_185 -> V_329 ;
V_2 -> V_6 . V_172 = V_5 -> V_6 . V_207 ;
V_2 -> V_6 . V_203 = V_5 -> V_6 . V_203 ;
V_2 -> V_6 . V_205 = V_5 -> V_6 . V_205 ;
F_150 ( & V_2 -> V_6 . V_144 , V_330 , V_150 ) ;
V_2 -> V_6 . V_144 . V_331 = F_144 ;
V_2 -> V_6 . V_169 = - 1 ;
V_2 -> V_6 . V_24 = (struct V_24 * ) F_151 ( V_2 -> V_332 ) ;
V_2 -> V_6 . V_333 = V_42 ;
V_2 -> V_6 . V_334 = V_335 ;
V_2 -> V_6 . V_336 = F_18 ( & V_5 -> V_6 . V_337 ) ;
V_2 -> V_6 . V_338 . V_339 = (struct V_229 * ) F_152 ( V_2 -> V_332 ) ;
V_2 -> V_6 . V_340 . V_339 = (struct V_229 * ) F_153 ( V_2 -> V_332 ) ;
F_140 ( V_2 ) ;
V_53 = 0 ;
V_162:
return V_53 ;
}
static int F_154 ( struct V_1 * V_2 , int V_99 )
{
unsigned long V_168 ;
int V_53 ;
F_10 ( V_168 ) ;
V_53 = F_77 ( V_2 ) ;
F_12 ( V_168 ) ;
if ( V_53 )
goto V_341;
V_53 = F_155 ( V_2 , V_2 -> V_5 , V_99 ) ;
if ( V_53 )
goto V_341;
V_53 = F_135 ( V_2 ) ;
if ( V_53 ) {
F_23 ( V_50 L_15 ) ;
goto V_342;
}
V_53 = F_139 ( V_2 ) ;
if ( V_53 )
goto V_342;
F_78 ( V_2 ) ;
return 0 ;
V_342:
F_156 ( V_2 ) ;
V_341:
return V_53 ;
}
struct V_1 * F_157 ( struct V_5 * V_5 ,
unsigned int V_99 )
{
struct V_1 * V_2 ;
unsigned long V_164 = V_5 -> V_6 . V_164 ;
int V_53 ;
int V_130 ;
F_104 ( sizeof( struct V_1 ) > V_343 / 2 ) ;
V_53 = - V_40 ;
if ( V_99 >= V_316 ) {
F_23 ( V_84 L_16 ,
V_316 ) ;
goto V_341;
}
V_53 = - V_284 ;
if ( ! V_164 ) {
F_23 ( V_84 L_17 , V_99 ) ;
goto V_341;
}
V_2 = (struct V_1 * ) ( V_164 + F_107 ( struct V_198 ,
V_344 [ V_99 ] . V_345 ) ) ;
V_2 -> V_5 = V_5 ;
V_130 = F_158 () ;
V_53 = F_154 ( V_2 , V_99 ) ;
F_159 () ;
if ( V_53 ) {
F_23 ( V_50 L_18 ) ;
goto V_341;
}
return V_2 ;
V_341:
return F_160 ( V_53 ) ;
}
int F_161 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_162 ( struct V_1 * V_2 , struct V_346 * V_347 )
{
return - V_40 ;
}
int F_163 ( struct V_1 * V_2 , struct V_346 * V_347 )
{
return - V_40 ;
}
int F_164 ( struct V_1 * V_2 ,
struct V_348 * V_349 )
{
return - V_40 ;
}
void F_165 ( struct V_5 * V_5 )
{
unsigned long V_164 = V_5 -> V_6 . V_164 ;
if ( V_164 ) {
memset ( ( void * ) V_164 , 0 , V_197 ) ;
F_134 ( V_164 , F_106 ( V_197 ) ) ;
}
}
static void F_166 ( struct V_5 * V_5 )
{
struct V_350 * V_351 ;
struct V_352 * V_353 ;
int V_12 , V_13 ;
unsigned long V_354 ;
V_351 = V_350 ( V_5 ) ;
for ( V_12 = 0 ; V_12 < V_351 -> V_355 ; V_12 ++ ) {
V_353 = & V_351 -> V_356 [ V_12 ] ;
V_354 = V_353 -> V_354 ;
for ( V_13 = 0 ; V_13 < V_353 -> V_357 ; V_13 ++ ) {
if ( V_353 -> V_358 [ V_13 ] )
F_167 ( (struct V_359 * ) V_353 -> V_358 [ V_13 ] ) ;
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
F_173 ( V_5 -> V_6 . V_360 ) ;
F_166 ( V_5 ) ;
}
void F_174 ( struct V_1 * V_2 )
{
}
void F_175 ( struct V_1 * V_2 , int V_130 )
{
if ( V_130 != V_2 -> V_130 ) {
V_2 -> V_130 = V_130 ;
if ( V_2 -> V_6 . V_149 )
F_142 ( V_2 ) ;
}
}
int F_176 ( struct V_1 * V_2 , struct V_217 * V_106 )
{
struct V_24 * V_24 = F_41 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
int V_12 ;
F_177 ( V_2 ) ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
V_106 -> V_24 . V_218 [ V_12 ] = V_24 -> V_218 [ V_12 ] ;
V_106 -> V_24 . V_219 [ V_12 ] = V_24 -> V_219 [ V_12 ] ;
}
for ( V_12 = 0 ; V_12 < 128 ; V_12 ++ )
V_106 -> V_24 . V_220 [ V_12 ] = V_24 -> V_220 [ V_12 ] ;
V_106 -> V_24 . V_221 = V_24 -> V_221 ;
V_106 -> V_24 . V_222 = V_24 -> V_222 ;
V_106 -> V_24 . V_223 = V_24 -> V_223 ;
V_106 -> V_24 . V_224 = V_24 -> V_224 ;
V_106 -> V_24 . V_225 = V_24 -> V_225 ;
memcpy ( & V_106 -> V_227 , & V_2 -> V_6 . V_226 , sizeof( union V_173 ) ) ;
F_178 ( V_117 ) ;
F_178 ( V_172 ) ;
memcpy ( V_106 -> V_228 , V_2 -> V_6 . V_228 , sizeof( struct V_229 ) * V_230 ) ;
memcpy ( V_106 -> V_231 , V_2 -> V_6 . V_231 , sizeof( struct V_229 ) * V_232 ) ;
F_178 ( V_233 ) ;
F_178 ( V_234 ) ;
F_178 ( V_235 ) ;
F_178 ( V_236 ) ;
F_178 ( V_237 ) ;
F_178 ( V_148 ) ;
F_178 ( V_238 ) ;
F_178 ( V_239 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_106 -> V_240 [ V_12 ] = V_2 -> V_6 . V_240 [ V_12 ] ;
V_106 -> V_241 [ V_12 ] = V_2 -> V_6 . V_241 [ V_12 ] ;
V_106 -> V_242 [ V_12 ] = V_2 -> V_6 . V_242 [ V_12 ] ;
}
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ )
V_106 -> V_243 [ V_12 ] = V_2 -> V_6 . V_243 [ V_12 ] ;
V_106 -> V_249 = V_2 -> V_6 . V_146 + F_1 ( V_2 ) ;
F_178 ( V_244 ) ;
F_178 ( V_203 ) ;
F_178 ( V_205 ) ;
F_178 ( V_245 ) ;
F_178 ( V_246 ) ;
F_178 ( V_247 ) ;
F_178 ( V_248 ) ;
F_179 ( V_2 ) ;
return 0 ;
}
int F_180 ( struct V_1 * V_2 ,
struct V_361 * V_362 )
{
memcpy ( V_362 , V_2 , sizeof( struct V_361 ) ) ;
return 0 ;
}
int F_181 ( struct V_1 * V_2 ,
struct V_361 * V_362 )
{
memcpy ( V_2 + 1 , & V_362 -> V_362 [ 0 ] + sizeof( struct V_1 ) ,
sizeof( struct V_361 ) - sizeof( struct V_1 ) ) ;
V_2 -> V_6 . V_363 = ( (struct V_1 * ) V_362 ) -> V_6 . V_363 ;
return 0 ;
}
void F_182 ( struct V_1 * V_2 )
{
F_67 ( & V_2 -> V_6 . V_144 ) ;
F_173 ( V_2 -> V_6 . V_318 ) ;
}
long F_183 ( struct V_251 * V_252 ,
unsigned int V_253 , unsigned long V_254 )
{
struct V_1 * V_2 = V_252 -> V_255 ;
void T_7 * V_256 = ( void T_7 * ) V_254 ;
struct V_361 * V_362 = NULL ;
long V_53 ;
switch ( V_253 ) {
case V_364 : {
struct V_361 T_7 * V_365 ;
void T_7 * V_366 = V_256 ;
V_53 = - V_263 ;
if ( F_120 ( & V_365 , V_366 , sizeof( void * ) ) )
goto V_162;
if ( ! F_184 ( V_367 , V_365 ,
sizeof( struct V_361 ) ) ) {
F_23 ( V_48 L_19
L_20 ) ;
goto V_162;
}
V_362 = F_149 ( sizeof( struct V_361 ) , V_196 ) ;
if ( ! V_362 ) {
V_53 = - V_284 ;
goto V_162;
}
V_53 = F_180 ( V_2 , V_362 ) ;
if ( V_53 )
goto V_162;
if ( F_128 ( V_365 , V_362 ,
sizeof( struct V_361 ) ) ) {
V_53 = - V_263 ;
goto V_162;
}
break;
}
case V_368 : {
struct V_361 T_7 * V_365 ;
void T_7 * V_366 = V_256 ;
V_53 = - V_263 ;
if ( F_120 ( & V_365 , V_366 , sizeof( void * ) ) )
goto V_162;
if ( ! F_184 ( V_369 , V_365 ,
sizeof( struct V_361 ) ) ) {
F_23 ( V_48 L_21
L_22 ) ;
goto V_162;
}
V_362 = F_185 ( sizeof( struct V_361 ) , V_196 ) ;
if ( ! V_362 ) {
V_53 = - V_284 ;
goto V_162;
}
if ( F_120 ( V_362 , V_365 ,
sizeof( struct V_361 ) ) )
goto V_162;
V_53 = F_181 ( V_2 , V_362 ) ;
break;
}
default:
V_53 = - V_40 ;
}
V_162:
F_173 ( V_362 ) ;
return V_53 ;
}
int F_186 ( struct V_5 * V_5 ,
struct V_352 * V_353 ,
struct V_352 V_370 ,
struct V_261 * V_371 ,
int V_372 )
{
unsigned long V_12 ;
unsigned long V_373 ;
int V_357 = V_353 -> V_357 ;
unsigned long V_354 = V_353 -> V_354 ;
if ( V_354 + V_357 > ( V_374 >> V_136 ) )
return - V_284 ;
for ( V_12 = 0 ; V_12 < V_357 ; V_12 ++ ) {
V_373 = F_187 ( V_5 , V_354 + V_12 ) ;
if ( ! F_188 ( V_373 ) ) {
F_109 ( V_5 , V_354 + V_12 ,
V_373 << V_136 ,
V_375 | V_376 ) ;
V_353 -> V_358 [ V_12 ] = ( unsigned long ) F_189 ( V_373 ) ;
} else {
F_109 ( V_5 , V_354 + V_12 ,
V_377 | ( V_373 << V_136 ) ,
V_378 ) ;
V_353 -> V_358 [ V_12 ] = 0 ;
}
}
return 0 ;
}
void F_190 ( struct V_5 * V_5 ,
struct V_261 * V_371 ,
struct V_352 V_370 ,
int V_372 )
{
return;
}
void F_191 ( struct V_5 * V_5 )
{
F_192 ( V_5 ) ;
}
long F_193 ( struct V_251 * V_252 ,
unsigned int V_253 , unsigned long V_254 )
{
return - V_40 ;
}
void F_194 ( struct V_1 * V_2 )
{
F_156 ( V_2 ) ;
}
static int F_195 ( void )
{
long V_379 = 1 , V_30 = 1 , V_380 = 1 ;
long V_302 ;
V_302 = F_196 ( & V_379 , & V_30 , & V_380 , 0 ) ;
if ( V_302 )
goto V_162;
if ( ! ( V_379 & V_381 ) )
goto V_162;
F_23 ( V_50 L_23 ) ;
V_302 = F_197 ( & V_281 , & V_382 ) ;
if ( V_302 )
goto V_162;
F_23 ( V_50 L_24 , V_281 ) ;
if ( ! ( V_382 & V_383 ) ) {
F_23 ( V_47 L_25
L_26 , V_382 ) ;
}
return 1 ;
V_162:
return 0 ;
}
static void F_198 ( struct V_185 * V_384 ,
struct V_385 * V_385 )
{
unsigned long V_386 , V_387 ;
unsigned long V_388 ;
if ( ! F_111 ( L_11 ) )
return;
V_388 = ( unsigned long ) V_385 -> V_389 ;
V_386 = V_36 + V_384 -> V_390 - V_388 ;
V_387 = V_36 + V_384 -> V_391 - V_388 ;
F_23 ( V_48 L_27
L_28 ) ;
memcpy ( ( void * ) V_386 , ( void * ) V_387 , 0x60 ) ;
}
static int F_199 ( struct V_185 * V_384 ,
struct V_385 * V_385 )
{
unsigned long V_388 ;
unsigned long V_392 ;
unsigned long V_393 , V_394 , V_395 ;
struct V_396 * V_397 ;
F_104 ( ! V_385 ) ;
if ( ! V_36 ) {
F_23 ( L_29 ) ;
return - V_263 ;
}
V_388 = ( unsigned long ) V_385 -> V_389 ;
V_392 = V_385 -> V_398 ;
if ( F_102 ( V_392 > V_283 ) )
return - V_263 ;
memcpy ( ( void * ) V_36 , ( void * ) V_388 , V_392 ) ;
F_198 ( V_384 , V_385 ) ;
F_5 ( V_36 , V_392 ) ;
V_393 = V_384 -> V_303 - V_388 ;
V_185 -> V_303 = V_38 + V_393 ;
F_23 ( V_50 L_30 ,
V_185 -> V_303 ) ;
V_395 = ( unsigned long ) V_384 -> V_329 - V_388 ;
V_185 -> V_329 = ( V_399 * ) ( V_38 +
V_395 ) ;
V_394 = * ( unsigned long * ) V_384 -> V_329 - V_388 ;
V_397 = (struct V_396 * ) ( V_36 + V_395 ) ;
V_397 -> V_400 = V_38 + V_394 ;
V_397 -> V_401 = V_38 + ( V_397 -> V_401 - V_388 ) ;
F_23 ( V_50 L_31 ,
V_38 + V_394 ) ;
V_395 = ( unsigned long ) V_384 -> V_186 - V_388 ;
V_185 -> V_186 = ( V_402 * ) ( V_38 +
V_395 ) ;
V_394 = * ( unsigned long * ) V_384 -> V_186 - V_388 ;
V_397 = (struct V_396 * ) ( V_36 + V_395 ) ;
V_397 -> V_400 = V_38 + V_394 ;
V_397 -> V_401 = V_38 + ( V_397 -> V_401 - V_388 ) ;
V_335 = V_397 -> V_401 ;
F_23 ( V_50 L_32 ,
V_185 -> V_329 ) ;
F_23 ( V_50 L_33 ,
V_38 + V_394 ) ;
return 0 ;
}
int F_200 ( void * V_403 )
{
int V_53 ;
struct V_185 * V_384 = (struct V_185 * ) V_403 ;
if ( ! F_195 () ) {
F_23 ( V_84 L_34 ) ;
V_53 = - V_404 ;
goto V_162;
}
if ( V_185 ) {
F_23 ( V_84 L_35 ) ;
V_53 = - V_405 ;
goto V_162;
}
V_53 = - V_284 ;
V_185 = F_149 ( sizeof( struct V_185 ) , V_196 ) ;
if ( ! V_185 )
goto V_162;
if ( F_132 () )
goto V_406;
V_53 = F_199 ( V_384 , V_384 -> V_385 ) ;
if ( V_53 )
goto V_407;
return 0 ;
V_407:
F_133 () ;
V_406:
F_173 ( V_185 ) ;
V_162:
return V_53 ;
}
void F_201 ( void )
{
F_133 () ;
F_173 ( V_185 ) ;
V_185 = NULL ;
}
static void F_202 ( struct V_5 * V_5 ,
struct V_352 * V_353 )
{
int V_12 ;
long V_305 ;
unsigned long V_408 ;
unsigned long * V_409 = ( unsigned long * ) ( V_5 -> V_6 . V_164 +
F_107 ( struct V_198 , V_410 ) ) ;
V_408 = F_203 ( V_353 ) ;
V_305 = V_353 -> V_354 / V_411 ;
F_20 ( & V_5 -> V_6 . V_337 ) ;
for ( V_12 = 0 ; V_12 < V_408 / sizeof( long ) ; ++ V_12 ) {
V_353 -> V_409 [ V_12 ] = V_409 [ V_305 + V_12 ] ;
V_409 [ V_305 + V_12 ] = 0 ;
}
F_22 ( & V_5 -> V_6 . V_337 ) ;
}
int F_204 ( struct V_5 * V_5 ,
struct V_412 * log )
{
int V_53 ;
unsigned long V_408 ;
struct V_352 * V_353 ;
int V_413 = 0 ;
F_124 ( & V_5 -> V_267 ) ;
V_53 = - V_40 ;
if ( log -> V_35 >= V_414 )
goto V_162;
V_353 = & V_5 -> V_356 -> V_356 [ log -> V_35 ] ;
V_53 = - V_415 ;
if ( ! V_353 -> V_409 )
goto V_162;
F_202 ( V_5 , V_353 ) ;
V_53 = F_205 ( V_5 , log , & V_413 ) ;
if ( V_53 )
goto V_162;
if ( V_413 ) {
F_192 ( V_5 ) ;
V_408 = F_203 ( V_353 ) ;
memset ( V_353 -> V_409 , 0 , V_408 ) ;
}
V_53 = 0 ;
V_162:
F_126 ( & V_5 -> V_267 ) ;
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
int V_416 ;
int V_130 = V_2 -> V_130 ;
if ( F_50 ( & V_2 -> V_119 ) )
F_51 ( & V_2 -> V_119 ) ;
V_416 = F_158 () ;
if ( V_130 != V_416 && ( unsigned ) V_130 < V_417 && F_208 ( V_130 ) )
if ( ! F_42 ( V_181 , & V_2 -> V_123 ) )
F_209 ( V_130 ) ;
F_159 () ;
}
int F_210 ( struct V_1 * V_2 , struct V_418 * V_273 )
{
return F_40 ( V_2 , V_273 -> V_90 ) ;
}
int F_211 ( struct V_319 * V_318 , T_11 V_419 )
{
return V_318 -> V_2 -> V_332 == V_419 ;
}
int F_212 ( struct V_319 * V_318 , T_12 V_420 )
{
return 0 ;
}
int F_213 ( struct V_1 * V_421 , struct V_1 * V_422 )
{
return V_421 -> V_6 . V_244 - V_422 -> V_6 . V_244 ;
}
int F_214 ( struct V_1 * V_2 , struct V_319 * V_423 ,
int V_424 , int V_419 , int V_425 )
{
struct V_319 * V_426 = V_2 -> V_6 . V_318 ;
return ( V_425 == 0 ) ?
F_211 ( V_426 , V_419 ) :
F_212 ( V_426 , V_419 ) ;
}
static int F_215 ( int * V_427 )
{
T_5 V_428 , V_429 ;
int V_12 ;
for ( V_12 = 7 ; V_12 >= 0 ; V_12 -- ) {
V_428 = V_427 [ V_12 ] ;
if ( V_428 ) {
V_429 = F_216 ( V_428 ) ;
return V_12 * 32 + V_429 - 1 ;
}
}
return - 1 ;
}
int F_217 ( struct V_1 * V_2 )
{
struct V_24 * V_24 = F_41 ( V_2 -> V_5 , V_2 -> V_6 . V_24 ) ;
if ( V_24 -> V_91 [ 0 ] & ( 1UL << V_430 ) )
return V_430 ;
if ( V_24 -> V_91 [ 0 ] & ( 1UL << V_431 ) )
return V_431 ;
return F_215 ( ( int * ) & V_24 -> V_91 [ 0 ] ) ;
}
int F_69 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_310 ;
}
int F_218 ( struct V_1 * V_2 )
{
return ( V_2 -> V_6 . V_117 == V_118 ) ||
( F_217 ( V_2 ) != - 1 ) ;
}
int F_219 ( struct V_1 * V_2 ,
struct V_432 * V_117 )
{
V_117 -> V_117 = V_2 -> V_6 . V_117 ;
return 0 ;
}
static int F_220 ( struct V_1 * V_2 )
{
int V_53 ;
long V_168 ;
F_10 ( V_168 ) ;
V_53 = F_77 ( V_2 ) ;
F_12 ( V_168 ) ;
if ( V_53 )
goto V_341;
V_2 -> V_6 . V_111 = 0 ;
F_182 ( V_2 ) ;
V_53 = F_146 ( V_2 ) ;
if ( V_53 )
goto V_341;
F_78 ( V_2 ) ;
V_53 = 0 ;
V_341:
return V_53 ;
}
int F_221 ( struct V_1 * V_2 ,
struct V_432 * V_117 )
{
int V_53 = 0 ;
V_2 -> V_6 . V_117 = V_117 -> V_117 ;
if ( V_2 -> V_6 . V_117 == V_129 )
V_53 = F_220 ( V_2 ) ;
return V_53 ;
}
