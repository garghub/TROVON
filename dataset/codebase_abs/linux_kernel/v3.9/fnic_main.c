static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( F_3 ( V_2 ) ) ;
V_2 -> V_5 = 1 ;
if ( ! V_4 || F_4 ( V_4 ) )
return - V_6 ;
F_5 ( V_2 , V_7 ) ;
return 0 ;
}
static void
F_6 ( struct V_3 * V_4 , T_1 V_8 )
{
if ( V_8 )
V_4 -> V_9 = V_8 ;
else
V_4 -> V_9 = 1 ;
}
static void F_7 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_8 ( V_11 ) ;
struct V_14 * V_14 = F_9 ( V_13 ) ;
T_1 V_15 = F_10 ( V_14 -> V_16 ) ;
switch ( V_15 ) {
case 10000 :
F_11 ( V_11 ) = V_17 ;
break;
default:
F_11 ( V_11 ) = V_17 ;
break;
}
}
static struct V_18 * F_12 ( struct V_10 * V_19 )
{
int V_20 ;
struct V_12 * V_13 = F_8 ( V_19 ) ;
struct V_14 * V_14 = F_9 ( V_13 ) ;
struct V_18 * V_21 = & V_13 -> V_22 ;
struct V_23 * V_24 ;
unsigned long V_25 ;
if ( F_13 ( V_26 , V_14 -> V_27 + V_28 / V_29 ) )
return V_21 ;
V_14 -> V_27 = V_26 ;
F_14 ( & V_14 -> V_30 , V_25 ) ;
V_20 = F_15 ( V_14 -> V_16 , & V_14 -> V_21 ) ;
F_16 ( & V_14 -> V_30 , V_25 ) ;
if ( V_20 ) {
F_17 ( V_31 , V_14 -> V_32 -> V_19 ,
L_1
L_2 , V_20 ) ;
return V_21 ;
}
V_24 = V_14 -> V_21 ;
V_21 -> V_33 = V_24 -> V_34 . V_35 ;
V_21 -> V_36 = V_24 -> V_34 . V_37 / 4 ;
V_21 -> V_38 = V_24 -> V_39 . V_40 ;
V_21 -> V_41 = V_24 -> V_39 . V_42 / 4 ;
V_21 -> V_43 = V_24 -> V_34 . V_44 + V_24 -> V_39 . V_45 ;
V_21 -> V_46 = V_24 -> V_34 . V_47 + V_24 -> V_39 . V_48 ;
V_21 -> V_49 = V_24 -> V_39 . V_50 ;
V_21 -> V_51 = ( V_26 - V_13 -> V_52 ) / V_28 ;
V_21 -> V_53 = F_18 ( V_14 -> V_54 , 1000000 ) ;
V_21 -> V_55 = F_18 ( V_14 -> V_56 , 1000000 ) ;
return V_21 ;
}
void F_19 ( struct V_14 * V_14 )
{
unsigned int V_57 ;
T_1 V_58 ;
for ( V_57 = 0 ; V_57 < V_14 -> V_59 ; V_57 ++ ) {
V_58 = F_20 ( & V_14 -> V_60 [ V_57 ] . V_61 -> V_58 ) ;
if ( V_58 )
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_3
L_4 , V_57 , V_58 ) ;
}
for ( V_57 = 0 ; V_57 < V_14 -> V_63 ; V_57 ++ ) {
V_58 = F_20 ( & V_14 -> V_64 [ V_57 ] . V_61 -> V_58 ) ;
if ( V_58 )
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_5
L_4 , V_57 , V_58 ) ;
}
for ( V_57 = 0 ; V_57 < V_14 -> V_65 ; V_57 ++ ) {
V_58 = F_20 ( & V_14 -> V_66 [ V_57 ] . V_61 -> V_58 ) ;
if ( V_58 )
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_6
L_4 , V_57 , V_58 ) ;
}
}
void F_22 ( struct V_14 * V_14 )
{
unsigned long V_25 ;
F_14 ( & V_14 -> V_30 , V_25 ) ;
if ( V_14 -> V_67 ) {
F_16 ( & V_14 -> V_30 , V_25 ) ;
return;
}
F_16 ( & V_14 -> V_30 , V_25 ) ;
F_23 ( V_68 , & V_14 -> V_69 ) ;
}
static int F_24 ( struct V_14 * V_14 )
{
int V_70 ;
switch ( F_25 ( V_14 -> V_16 ) ) {
case V_71 :
V_70 = F_26 ( V_14 -> V_16 , V_72 ) ;
break;
case V_73 :
V_70 = F_26 ( V_14 -> V_16 , - 1 ) ;
break;
case V_74 :
V_70 = F_26 ( V_14 -> V_16 , V_75 ) ;
break;
default:
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_7
L_8 ,
F_25 ( V_14 -> V_16 ) ) ;
V_70 = - 1 ;
break;
}
return V_70 ;
}
static void F_27 ( unsigned long V_76 )
{
struct V_14 * V_14 = (struct V_14 * ) V_76 ;
F_22 ( V_14 ) ;
F_28 ( & V_14 -> V_77 ,
F_29 ( V_26 + V_78 ) ) ;
}
static void F_30 ( struct V_14 * V_14 )
{
switch ( F_25 ( V_14 -> V_16 ) ) {
case V_73 :
F_28 ( & V_14 -> V_77 , V_26 ) ;
break;
default:
break;
} ;
}
static int F_31 ( struct V_79 * V_16 ,
int (* F_32)( struct V_79 * , int ) ,
int (* F_33)( struct V_79 * , int * ) ,
int V_80 )
{
unsigned long time ;
int V_81 ;
int V_70 ;
V_70 = F_32 ( V_16 , V_80 ) ;
if ( V_70 )
return V_70 ;
time = V_26 + ( V_28 * 2 ) ;
do {
V_70 = F_33 ( V_16 , & V_81 ) ;
if ( V_70 )
return V_70 ;
if ( V_81 )
return 0 ;
F_34 ( V_28 / 10 ) ;
} while ( F_35 ( time , V_26 ) );
return - V_82 ;
}
static int F_36 ( struct V_14 * V_14 )
{
unsigned int V_57 ;
int V_70 ;
F_37 ( V_14 -> V_16 ) ;
for ( V_57 = 0 ; V_57 < V_14 -> V_83 ; V_57 ++ )
F_38 ( & V_14 -> V_84 [ V_57 ] ) ;
for ( V_57 = 0 ; V_57 < V_14 -> V_63 ; V_57 ++ ) {
V_70 = F_39 ( & V_14 -> V_64 [ V_57 ] ) ;
if ( V_70 )
return V_70 ;
}
for ( V_57 = 0 ; V_57 < V_14 -> V_59 ; V_57 ++ ) {
V_70 = F_40 ( & V_14 -> V_60 [ V_57 ] ) ;
if ( V_70 )
return V_70 ;
}
for ( V_57 = 0 ; V_57 < V_14 -> V_65 ; V_57 ++ ) {
V_70 = F_41 ( & V_14 -> V_66 [ V_57 ] ) ;
if ( V_70 )
return V_70 ;
}
F_42 ( V_14 , - 1 ) ;
F_43 ( V_14 , - 1 ) ;
F_44 ( V_14 , - 1 ) ;
for ( V_57 = 0 ; V_57 < V_14 -> V_59 ; V_57 ++ )
F_45 ( & V_14 -> V_60 [ V_57 ] , V_85 ) ;
for ( V_57 = 0 ; V_57 < V_14 -> V_63 ; V_57 ++ )
F_46 ( & V_14 -> V_64 [ V_57 ] , V_86 ) ;
for ( V_57 = 0 ; V_57 < V_14 -> V_65 ; V_57 ++ )
F_47 ( & V_14 -> V_66 [ V_57 ] ,
V_87 ) ;
for ( V_57 = 0 ; V_57 < V_14 -> V_88 ; V_57 ++ )
F_48 ( & V_14 -> V_89 [ V_57 ] ) ;
for ( V_57 = 0 ; V_57 < V_14 -> V_83 ; V_57 ++ )
F_49 ( & V_14 -> V_84 [ V_57 ] ) ;
F_50 ( V_14 -> V_90 ) ;
for ( V_57 = 0 ; V_57 < V_91 ; V_57 ++ )
F_50 ( V_14 -> V_92 [ V_57 ] ) ;
return 0 ;
}
static void F_51 ( struct V_14 * V_14 )
{
if ( V_14 -> V_93 . V_94 )
F_52 ( V_14 -> V_93 . V_94 ) ;
}
static T_2 * F_53 ( struct V_12 * V_32 )
{
struct V_14 * V_14 = F_9 ( V_32 ) ;
return V_14 -> V_95 ;
}
static int F_54 ( struct V_96 * V_97 , const struct V_98 * V_99 )
{
struct V_10 * V_19 ;
struct V_12 * V_13 ;
struct V_14 * V_14 ;
T_3 * V_100 ;
int V_70 ;
int V_57 ;
unsigned long V_25 ;
V_13 = F_55 ( & V_101 , sizeof( struct V_14 ) ) ;
if ( ! V_13 ) {
F_56 (KERN_ERR PFX L_9 ) ;
V_70 = - V_102 ;
goto V_103;
}
V_19 = V_13 -> V_19 ;
V_14 = F_9 ( V_13 ) ;
V_14 -> V_32 = V_13 ;
V_14 -> V_104 . V_13 = V_13 ;
snprintf ( V_14 -> V_105 , sizeof( V_14 -> V_105 ) - 1 , L_10 , V_106 ,
V_19 -> V_107 ) ;
V_19 -> V_108 = V_109 ;
V_70 = F_57 ( V_19 , V_110 ) ;
if ( V_70 ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_11 ) ;
goto V_111;
}
F_58 ( V_97 , V_14 ) ;
V_14 -> V_97 = V_97 ;
V_70 = F_59 ( V_97 ) ;
if ( V_70 ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_12 ) ;
goto V_111;
}
V_70 = F_60 ( V_97 , V_106 ) ;
if ( V_70 ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_13 ) ;
goto V_112;
}
F_61 ( V_97 ) ;
V_70 = F_62 ( V_97 , F_63 ( 40 ) ) ;
if ( V_70 ) {
V_70 = F_62 ( V_97 , F_63 ( 32 ) ) ;
if ( V_70 ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_14
L_15 ) ;
goto V_113;
}
V_70 = F_64 ( V_97 , F_63 ( 32 ) ) ;
if ( V_70 ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_16
L_17 ) ;
goto V_113;
}
} else {
V_70 = F_64 ( V_97 , F_63 ( 40 ) ) ;
if ( V_70 ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_18
L_17 ) ;
goto V_113;
}
}
if ( ! ( F_65 ( V_97 , 0 ) & V_114 ) ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_19 ) ;
V_70 = - V_115 ;
goto V_113;
}
V_14 -> V_93 . V_94 = F_66 ( V_97 , 0 , 0 ) ;
V_14 -> V_93 . V_116 = F_67 ( V_97 , 0 ) ;
V_14 -> V_93 . V_117 = F_68 ( V_97 , 0 ) ;
if ( ! V_14 -> V_93 . V_94 ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_20
L_21 ) ;
V_70 = - V_115 ;
goto V_113;
}
V_14 -> V_16 = F_69 ( NULL , V_14 , V_97 , & V_14 -> V_93 ) ;
if ( ! V_14 -> V_16 ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_22
L_21 ) ;
V_70 = - V_115 ;
goto V_118;
}
V_70 = F_31 ( V_14 -> V_16 , V_119 ,
V_120 , 0 ) ;
if ( V_70 ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_23 ) ;
goto V_121;
}
V_70 = F_70 ( V_14 -> V_16 , 0 ) ;
if ( V_70 ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_24 ) ;
goto V_122;
}
V_70 = F_71 ( V_14 -> V_16 , V_14 -> V_104 . V_123 ) ;
if ( V_70 ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_25 ) ;
goto V_122;
}
memcpy ( V_14 -> V_95 , V_14 -> V_104 . V_123 , V_124 ) ;
V_70 = F_72 ( V_14 ) ;
if ( V_70 ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_26
L_21 ) ;
goto V_122;
}
V_19 -> V_125 = V_14 -> V_126 . V_127 ;
V_19 -> V_128 = V_129 ;
V_19 -> V_130 = V_131 ;
F_73 ( V_14 ) ;
V_70 = F_74 ( V_14 ) ;
if ( V_70 ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_27
L_21 ) ;
goto V_122;
}
V_70 = F_75 ( V_14 ) ;
if ( V_70 ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_28
L_21 ) ;
goto V_132;
}
F_76 ( & V_14 -> V_30 ) ;
for ( V_57 = 0 ; V_57 < V_133 ; V_57 ++ )
F_76 ( & V_14 -> V_134 [ V_57 ] ) ;
for ( V_57 = 0 ; V_57 < V_135 ; V_57 ++ ) {
F_76 ( & V_14 -> V_136 [ V_57 ] ) ;
V_14 -> V_137 [ V_57 ] = V_138 ;
V_14 -> V_139 [ V_57 ] = 0 ;
V_14 -> V_140 [ V_57 ] = - 1 ;
}
for ( V_57 = 0 ; V_57 < V_141 ; V_57 ++ )
F_76 ( & V_14 -> V_142 [ V_57 ] ) ;
V_14 -> V_90 = F_77 ( 2 , V_143 ) ;
if ( ! V_14 -> V_90 )
goto V_144;
V_100 = F_77 ( 2 , V_145 [ V_146 ] ) ;
if ( ! V_100 )
goto V_147;
V_14 -> V_92 [ V_146 ] = V_100 ;
V_100 = F_77 ( 2 , V_145 [ V_148 ] ) ;
if ( ! V_100 )
goto V_149;
V_14 -> V_92 [ V_148 ] = V_100 ;
V_14 -> V_150 = 1 ;
V_14 -> V_151 = 0 ;
V_14 -> V_104 . V_152 = V_153 ;
V_14 -> V_104 . V_154 = V_155 ;
V_14 -> V_104 . V_156 = F_53 ;
if ( V_14 -> V_126 . V_25 & V_157 ) {
F_21 ( V_158 , V_14 -> V_32 -> V_19 ,
L_29 ) ;
F_78 ( V_14 -> V_16 , 1 , 1 , 0 , 0 , 0 ) ;
F_79 ( V_14 -> V_16 , V_159 ) ;
F_79 ( V_14 -> V_16 , V_14 -> V_104 . V_123 ) ;
F_80 ( & V_14 -> V_104 , V_160 ) ;
} else {
F_21 ( V_158 , V_14 -> V_32 -> V_19 ,
L_30 ) ;
F_80 ( & V_14 -> V_104 , V_161 ) ;
}
V_14 -> V_162 = V_163 ;
F_81 ( & V_14 -> V_164 , 0 ) ;
V_14 -> V_165 = V_166 ;
F_82 ( V_14 , 0 , 0 , 0 , 0 , 0 , 0 , 1 ) ;
V_70 = F_24 ( V_14 ) ;
if ( V_70 ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_31 ) ;
goto V_167;
}
if ( F_25 ( V_14 -> V_16 ) == V_73 )
F_83 ( & V_14 -> V_77 ,
F_27 , ( unsigned long ) V_14 ) ;
for ( V_57 = 0 ; V_57 < V_14 -> V_63 ; V_57 ++ ) {
V_70 = F_84 ( & V_14 -> V_64 [ V_57 ] , V_168 ) ;
if ( V_70 ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_32
L_33 ) ;
goto V_169;
}
}
V_70 = F_85 ( V_13 -> V_19 , & V_97 -> V_170 ) ;
if ( V_70 ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_34 ) ;
goto V_169;
}
V_13 -> V_171 = 0 ;
V_13 -> V_172 = V_14 -> V_126 . V_173 ;
V_13 -> V_174 = V_14 -> V_126 . V_175 ;
V_13 -> V_176 = ( V_177 | V_178 |
V_179 ) ;
if ( V_14 -> V_126 . V_25 & V_180 )
V_13 -> V_176 |= V_181 ;
V_13 -> V_52 = V_26 ;
V_13 -> V_182 = V_14 -> V_126 . V_183 ;
V_13 -> V_184 = V_14 -> V_126 . V_185 ;
V_13 -> V_186 = V_17 ;
F_86 ( V_13 , V_14 -> V_126 . V_187 ) ;
F_87 ( V_13 , V_14 -> V_126 . V_188 ) ;
F_88 ( V_13 , & V_14 -> V_104 , & V_189 , 0 ) ;
if ( ! F_89 ( V_13 , V_190 , V_191 ,
V_192 , NULL ) ) {
V_70 = - V_102 ;
goto V_193;
}
F_90 ( V_13 ) ;
F_91 ( V_13 ) ;
if ( F_92 ( V_13 , V_14 -> V_126 . V_194 +
sizeof( struct V_195 ) ) ) {
V_70 = - V_196 ;
goto V_197;
}
F_93 ( V_13 -> V_19 ) = V_13 -> V_198 ;
F_94 ( V_13 -> V_19 ) = V_14 -> V_126 . V_199 / 1000 ;
sprintf ( F_95 ( V_13 -> V_19 ) ,
V_106 L_35 V_200 L_36 , V_14 -> V_105 ) ;
F_14 ( & V_201 , V_25 ) ;
F_96 ( & V_14 -> V_202 , & V_203 ) ;
F_16 ( & V_201 , V_25 ) ;
F_97 ( & V_14 -> V_69 , V_204 ) ;
F_97 ( & V_14 -> V_205 , V_206 ) ;
F_98 ( & V_14 -> V_207 ) ;
F_98 ( & V_14 -> V_208 ) ;
for ( V_57 = 0 ; V_57 < V_14 -> V_59 ; V_57 ++ )
F_99 ( & V_14 -> V_60 [ V_57 ] ) ;
for ( V_57 = 0 ; V_57 < V_14 -> V_63 ; V_57 ++ )
F_100 ( & V_14 -> V_64 [ V_57 ] ) ;
for ( V_57 = 0 ; V_57 < V_14 -> V_65 ; V_57 ++ )
F_101 ( & V_14 -> V_66 [ V_57 ] ) ;
F_102 ( V_13 ) ;
F_103 ( V_14 -> V_16 ) ;
V_70 = F_104 ( V_14 ) ;
if ( V_70 ) {
F_21 ( V_62 , V_14 -> V_32 -> V_19 ,
L_37 ) ;
goto V_197;
}
for ( V_57 = 0 ; V_57 < V_14 -> V_83 ; V_57 ++ )
F_105 ( & V_14 -> V_84 [ V_57 ] ) ;
F_30 ( V_14 ) ;
return 0 ;
V_197:
F_106 ( V_13 ) ;
V_193:
F_107 ( V_13 -> V_19 ) ;
F_108 ( V_13 -> V_19 ) ;
V_169:
for ( V_57 = 0 ; V_57 < V_14 -> V_63 ; V_57 ++ )
F_46 ( & V_14 -> V_64 [ V_57 ] , V_86 ) ;
F_109 ( V_14 -> V_16 ) ;
V_167:
F_50 ( V_14 -> V_92 [ V_148 ] ) ;
V_149:
F_50 ( V_14 -> V_92 [ V_146 ] ) ;
V_147:
F_50 ( V_14 -> V_90 ) ;
V_144:
F_110 ( V_14 ) ;
V_132:
F_111 ( V_14 ) ;
V_122:
F_112 ( V_14 -> V_16 ) ;
V_121:
F_113 ( V_14 -> V_16 ) ;
V_118:
F_51 ( V_14 ) ;
V_113:
F_114 ( V_97 ) ;
V_112:
F_115 ( V_97 ) ;
V_111:
F_116 ( V_13 -> V_19 ) ;
V_103:
return V_70 ;
}
static void F_117 ( struct V_96 * V_97 )
{
struct V_14 * V_14 = F_118 ( V_97 ) ;
struct V_12 * V_13 = V_14 -> V_32 ;
unsigned long V_25 ;
F_14 ( & V_14 -> V_30 , V_25 ) ;
V_14 -> V_67 = 1 ;
F_16 ( & V_14 -> V_30 , V_25 ) ;
if ( F_25 ( V_14 -> V_16 ) == V_73 )
F_119 ( & V_14 -> V_77 ) ;
F_120 ( V_68 ) ;
F_121 ( & V_14 -> V_207 ) ;
F_121 ( & V_14 -> V_208 ) ;
F_122 ( V_14 -> V_32 ) ;
F_14 ( & V_14 -> V_30 , V_25 ) ;
V_14 -> V_209 = 1 ;
F_16 ( & V_14 -> V_30 , V_25 ) ;
F_123 ( & V_14 -> V_104 ) ;
F_124 ( V_13 ) ;
F_36 ( V_14 ) ;
F_125 ( ! F_126 ( & V_14 -> V_207 ) ) ;
F_125 ( ! F_126 ( & V_14 -> V_208 ) ) ;
F_14 ( & V_201 , V_25 ) ;
F_127 ( & V_14 -> V_202 ) ;
F_16 ( & V_201 , V_25 ) ;
F_107 ( V_14 -> V_32 -> V_19 ) ;
F_108 ( V_14 -> V_32 -> V_19 ) ;
F_106 ( V_14 -> V_32 ) ;
F_109 ( V_14 -> V_16 ) ;
F_128 ( V_14 ) ;
F_110 ( V_14 ) ;
F_111 ( V_14 ) ;
F_112 ( V_14 -> V_16 ) ;
F_113 ( V_14 -> V_16 ) ;
F_51 ( V_14 ) ;
F_114 ( V_97 ) ;
F_115 ( V_97 ) ;
F_58 ( V_97 , NULL ) ;
F_116 ( V_13 -> V_19 ) ;
}
static int T_4 F_129 ( void )
{
T_5 V_117 ;
int V_70 = 0 ;
F_56 (KERN_INFO PFX L_38 , DRV_DESCRIPTION, DRV_VERSION) ;
V_70 = F_130 () ;
if ( V_70 < 0 ) {
F_56 (KERN_ERR PFX L_39
L_40 ) ;
F_131 () ;
}
V_117 = sizeof( struct V_210 ) ;
V_145 [ V_146 ] = F_132
( L_41 , V_117 + V_211 , V_211 ,
V_212 ,
NULL ) ;
if ( ! V_145 [ V_146 ] ) {
F_56 (KERN_ERR PFX L_42 ) ;
V_70 = - V_102 ;
goto V_213;
}
V_117 = sizeof( struct V_214 ) ;
V_145 [ V_148 ] = F_132
( L_43 , V_117 + V_211 , V_211 ,
V_212 ,
NULL ) ;
if ( ! V_145 [ V_148 ] ) {
F_56 (KERN_ERR PFX L_44 ) ;
V_70 = - V_102 ;
goto V_215;
}
V_143 = F_132 ( L_45 ,
sizeof( struct V_216 ) ,
0 , V_212 , NULL ) ;
if ( ! V_143 ) {
F_56 (KERN_ERR PFX L_46 ) ;
V_70 = - V_102 ;
goto V_217;
}
V_68 = F_133 ( L_47 ) ;
if ( ! V_68 ) {
F_56 (KERN_ERR PFX L_48 ) ;
V_70 = - V_102 ;
goto V_218;
}
F_76 ( & V_201 ) ;
F_134 ( & V_203 ) ;
V_109 = F_135 ( & V_219 ) ;
if ( ! V_109 ) {
F_56 (KERN_ERR PFX L_49 ) ;
V_70 = - V_102 ;
goto V_220;
}
V_70 = F_136 ( & V_221 ) ;
if ( V_70 < 0 ) {
F_56 (KERN_ERR PFX L_50 ) ;
goto V_222;
}
return V_70 ;
V_222:
F_137 ( V_109 ) ;
V_220:
F_138 ( V_68 ) ;
V_218:
F_139 ( V_143 ) ;
V_217:
F_139 ( V_145 [ V_148 ] ) ;
V_215:
F_139 ( V_145 [ V_146 ] ) ;
V_213:
F_131 () ;
return V_70 ;
}
static void T_6 F_140 ( void )
{
F_141 ( & V_221 ) ;
F_138 ( V_68 ) ;
F_139 ( V_145 [ V_148 ] ) ;
F_139 ( V_145 [ V_146 ] ) ;
F_139 ( V_143 ) ;
F_137 ( V_109 ) ;
F_131 () ;
}
