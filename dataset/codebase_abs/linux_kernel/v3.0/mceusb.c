static int F_1 ( T_1 V_1 , T_1 V_2 )
{
int V_3 = 0 ;
switch ( V_1 ) {
case V_4 :
if ( V_2 == V_5 )
V_3 = 1 ;
break;
case V_5 :
switch ( V_2 ) {
case V_6 :
V_3 = 2 ;
break;
}
case V_7 :
switch ( V_2 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
V_3 = 2 ;
break;
case V_12 :
case V_13 :
case V_14 :
V_3 = 1 ;
break;
}
}
return V_3 ;
}
static void F_2 ( struct V_15 * V_16 , char * V_17 ,
int V_18 , int V_19 , bool V_20 )
{
char V_21 [ V_22 * 3 + 1 ] ;
char V_23 [ 9 ] ;
T_1 V_1 , V_2 , V_24 , V_25 ;
struct V_26 * V_27 = V_16 -> V_27 ;
int V_28 , V_29 , V_30 = 0 ;
if ( ! V_31 )
return;
if ( V_16 -> V_32 . V_33 && ! V_20 && ! V_18 )
V_30 = 2 ;
if ( V_19 <= V_30 )
return;
for ( V_28 = 0 ; V_28 < V_19 && V_28 < V_22 ; V_28 ++ )
snprintf ( V_21 + V_28 * 3 , 4 , L_1 , V_17 [ V_28 + V_18 ] & 0xff ) ;
F_3 ( V_27 , L_2 ,
( V_20 ? L_3 : L_4 ) , V_21 , V_19 ) ;
if ( V_20 )
strcpy ( V_23 , L_5 ) ;
else
strcpy ( V_23 , L_6 ) ;
V_29 = V_18 + V_30 ;
V_1 = V_17 [ V_29 ] & 0xff ;
V_2 = V_17 [ V_29 + 1 ] & 0xff ;
V_24 = V_17 [ V_29 + 2 ] & 0xff ;
V_25 = V_17 [ V_29 + 3 ] & 0xff ;
switch ( V_1 ) {
case V_4 :
if ( ( V_2 == V_5 ) &&
( V_24 == V_34 ) )
F_3 ( V_27 , L_7 ) ;
else
F_3 ( V_27 , L_8 ,
V_1 , V_2 ) ;
break;
case V_5 :
switch ( V_2 ) {
case V_6 :
if ( V_19 == 2 )
F_3 ( V_27 , L_9 ) ;
else
F_3 ( V_27 , L_10
L_11 , V_24 , V_25 ,
V_17 [ V_29 + 4 ] , V_17 [ V_29 + 5 ] ) ;
break;
case V_34 :
F_3 ( V_27 , L_7 ) ;
break;
case V_35 :
F_3 ( V_27 , L_12 ) ;
break;
case V_36 :
case V_37 :
default:
F_3 ( V_27 , L_8 ,
V_1 , V_2 ) ;
break;
}
break;
case V_7 :
switch ( V_2 ) {
case V_12 :
F_3 ( V_27 , L_13 ) ;
break;
case V_38 :
F_3 ( V_27 , L_14 ) ;
break;
case V_8 :
F_3 ( V_27 , L_15 ,
V_24 , V_25 ) ;
break;
case V_9 :
F_3 ( V_27 , L_16
L_11 , V_23 , V_24 , V_25 ) ;
break;
case V_39 :
F_3 ( V_27 , L_17 ) ;
break;
case V_13 :
F_3 ( V_27 , L_18 ,
V_23 , V_24 ) ;
break;
case V_10 :
F_3 ( V_27 , L_19 ,
V_23 ,
( ( V_24 << 8 ) | V_25 ) * V_40 / 1000 ) ;
break;
case V_41 :
F_3 ( V_27 , L_20 ) ;
break;
case V_42 :
F_3 ( V_27 , L_21 ) ;
break;
case V_14 :
F_3 ( V_27 , L_22 ,
V_23 , V_24 == 0x02 ? L_23 : L_24 ) ;
break;
case V_43 :
if ( V_20 )
F_3 ( V_27 , L_25 ) ;
else if ( V_16 -> V_44 )
F_3 ( V_27 , L_26 ,
( ( V_24 << 8 ) | V_25 ) ) ;
break;
case V_35 :
F_3 ( V_27 , L_27 ) ;
break;
case V_45 :
case V_46 :
case V_47 :
default:
F_3 ( V_27 , L_8 ,
V_1 , V_2 ) ;
break;
}
break;
default:
break;
}
if ( V_1 == V_48 )
F_3 ( V_27 , L_28 ) ;
else if ( ( V_1 != V_7 ) &&
( ( V_1 & V_49 ) == V_50 ) )
F_3 ( V_27 , L_29 , V_16 -> V_51 ) ;
}
static void F_4 ( struct V_52 * V_52 , struct V_53 * V_54 )
{
struct V_15 * V_16 ;
int V_19 ;
if ( ! V_52 )
return;
V_16 = V_52 -> V_55 ;
if ( V_16 ) {
V_19 = V_52 -> V_56 ;
F_5 ( V_16 -> V_27 , L_30 ,
V_52 -> V_57 , V_19 ) ;
F_2 ( V_16 , V_52 -> V_58 , 0 , V_19 , true ) ;
}
F_6 ( V_52 -> V_58 ) ;
F_7 ( V_52 ) ;
}
static void F_8 ( struct V_15 * V_16 , unsigned char * V_59 ,
int V_60 , int V_61 )
{
int V_62 , V_63 ;
struct V_52 * V_64 ;
struct V_26 * V_27 = V_16 -> V_27 ;
unsigned char * V_65 ;
if ( V_61 == V_66 ) {
V_64 = F_9 ( 0 , V_67 ) ;
if ( F_10 ( ! V_64 ) ) {
F_11 ( V_27 , L_31 ) ;
return;
}
V_65 = F_12 ( V_60 , V_67 ) ;
if ( ! V_65 ) {
F_11 ( V_27 , L_32 ) ;
F_7 ( V_64 ) ;
return;
}
V_63 = F_13 ( V_16 -> V_68 ,
V_16 -> V_69 -> V_70 ) ;
F_14 ( V_64 , V_16 -> V_68 , V_63 ,
V_65 , V_60 , ( V_71 ) F_4 ,
V_16 , V_16 -> V_69 -> V_72 ) ;
memcpy ( V_65 , V_59 , V_60 ) ;
} else if ( V_61 == V_73 ) {
V_64 = V_16 -> V_74 ;
V_16 -> V_75 = V_76 ;
} else {
F_11 ( V_27 , L_33 , V_61 ) ;
return;
}
F_5 ( V_27 , L_34 , V_60 ) ;
V_64 -> V_77 = V_60 ;
V_64 -> V_27 = V_16 -> V_68 ;
V_62 = F_15 ( V_64 , V_78 ) ;
if ( V_62 ) {
F_5 ( V_27 , L_35 , V_62 ) ;
return;
}
F_5 ( V_27 , L_36 , V_62 ) ;
}
static void F_16 ( struct V_15 * V_16 , unsigned char * V_59 , int V_60 )
{
F_8 ( V_16 , V_59 , V_60 , V_66 ) ;
}
static void F_17 ( struct V_15 * V_16 , int V_60 )
{
F_8 ( V_16 , NULL , V_60 , V_73 ) ;
}
static int F_18 ( struct V_79 * V_27 , int * V_80 , T_2 V_81 )
{
struct V_15 * V_16 = V_27 -> V_82 ;
int V_28 , V_83 = 0 ;
int V_84 , V_85 = 0 ;
unsigned char * V_86 ;
long V_87 = 0 ;
struct V_88 V_89 , V_90 ;
F_19 ( & V_89 ) ;
V_84 = V_81 / sizeof( int ) ;
V_86 = F_12 ( sizeof( int ) * V_91 , V_67 ) ;
if ( ! V_86 )
return - V_92 ;
V_86 [ V_85 ++ ] = V_7 ;
V_86 [ V_85 ++ ] = V_13 ;
V_86 [ V_85 ++ ] = V_16 -> V_93 ;
for ( V_28 = 0 ; ( V_28 < V_84 ) && ( V_85 < V_91 ) ; V_28 ++ ) {
V_87 += V_80 [ V_28 ] ;
V_80 [ V_28 ] = V_80 [ V_28 ] / V_40 ;
do {
if ( ( V_85 < V_91 ) &&
( V_85 - V_94 ) %
V_95 == 0 )
V_86 [ V_85 ++ ] = V_96 ;
if ( V_85 < V_91 )
V_86 [ V_85 ++ ] =
( V_80 [ V_28 ] < V_97 ?
V_80 [ V_28 ] : V_98 ) |
( V_28 & 1 ? 0x00 : V_97 ) ;
else {
V_83 = - V_99 ;
goto V_20;
}
} while ( ( V_80 [ V_28 ] > V_98 ) &&
( V_80 [ V_28 ] -= V_98 ) );
}
V_86 [ V_85 - ( V_85 - V_94 ) % V_95 ] =
V_50 + ( V_85 - V_94 ) %
V_95 - 1 ;
if ( V_85 >= V_91 ) {
V_83 = - V_99 ;
goto V_20;
}
V_86 [ V_85 ++ ] = V_48 ;
F_16 ( V_16 , V_86 , V_85 ) ;
F_19 ( & V_90 ) ;
V_87 -= ( V_90 . V_100 - V_89 . V_100 ) +
( V_90 . V_101 - V_89 . V_101 ) * 1000000 ;
F_20 ( V_102 ) ;
F_21 ( F_22 ( V_87 ) ) ;
V_20:
F_6 ( V_86 ) ;
return V_83 ? V_83 : V_81 ;
}
static int F_23 ( struct V_79 * V_27 , T_2 V_103 )
{
struct V_15 * V_16 = V_27 -> V_82 ;
if ( V_16 -> V_32 . V_104 )
V_16 -> V_93 = V_103 ;
else
V_16 -> V_93 = ( V_103 != V_105 ?
V_103 ^ V_105 : V_103 ) << 1 ;
return 0 ;
}
static int F_24 ( struct V_79 * V_27 , T_2 V_106 )
{
struct V_15 * V_16 = V_27 -> V_82 ;
int V_107 = 10000000 ;
int V_108 = 0 , V_109 = 0 ;
unsigned char V_86 [ 4 ] = { V_7 ,
V_9 , 0x00 , 0x00 } ;
if ( V_16 -> V_106 != V_106 ) {
if ( V_106 == 0 ) {
V_16 -> V_106 = V_106 ;
V_86 [ 2 ] = V_12 ;
V_86 [ 3 ] = V_48 ;
F_5 ( V_16 -> V_27 , L_37
L_38 , V_110 ) ;
F_16 ( V_16 , V_86 , sizeof( V_86 ) ) ;
return V_106 ;
}
for ( V_108 = 0 ; V_108 < 4 ; ++ V_108 ) {
V_109 = ( V_107 >> ( 2 * V_108 ) ) / V_106 ;
if ( V_109 <= 0xff ) {
V_16 -> V_106 = V_106 ;
V_86 [ 2 ] = V_108 ;
V_86 [ 3 ] = V_109 ;
F_5 ( V_16 -> V_27 , L_39
L_40 , V_110 , V_106 ) ;
F_16 ( V_16 , V_86 , sizeof( V_86 ) ) ;
return V_106 ;
}
}
return - V_99 ;
}
return V_106 ;
}
static void F_25 ( struct V_15 * V_16 , int V_111 )
{
T_1 V_112 = V_16 -> V_113 [ V_111 + 1 ] & 0xff ;
T_1 V_114 = V_16 -> V_113 [ V_111 + 2 ] & 0xff ;
switch ( V_16 -> V_113 [ V_111 ] ) {
case V_10 :
V_16 -> V_115 -> V_116 = F_26 ( ( V_112 << 8 | V_114 ) * V_40 ) ;
break;
case V_13 :
V_16 -> V_93 = V_112 ;
break;
case V_14 :
V_16 -> V_44 = ( V_112 == 0x02 ) ;
break;
default:
break;
}
}
static void F_27 ( struct V_15 * V_16 , int V_117 )
{
F_28 ( V_118 ) ;
int V_28 = 0 ;
if ( V_16 -> V_32 . V_33 )
V_28 = 2 ;
if ( V_117 <= V_28 )
return;
for (; V_28 < V_117 ; V_28 ++ ) {
switch ( V_16 -> V_119 ) {
case V_120 :
V_16 -> V_51 = F_1 ( V_16 -> V_1 , V_16 -> V_113 [ V_28 ] ) ;
F_2 ( V_16 , V_16 -> V_113 , V_28 - 1 ,
V_16 -> V_51 + 2 , false ) ;
F_25 ( V_16 , V_28 ) ;
V_16 -> V_119 = V_121 ;
break;
case V_122 :
V_16 -> V_51 -- ;
F_29 ( & V_118 ) ;
V_118 . V_123 = ( ( V_16 -> V_113 [ V_28 ] & V_97 ) != 0 ) ;
V_118 . V_124 = ( V_16 -> V_113 [ V_28 ] & V_125 )
* F_26 ( V_40 ) ;
F_5 ( V_16 -> V_27 , L_41 ,
V_118 . V_123 ? L_42 : L_43 ,
V_118 . V_124 ) ;
F_30 ( V_16 -> V_115 , & V_118 ) ;
break;
case V_121 :
V_16 -> V_51 -- ;
break;
case V_126 :
V_16 -> V_1 = V_16 -> V_113 [ V_28 ] ;
if ( ( V_16 -> V_1 == V_7 ) ||
( ( V_16 -> V_1 & V_49 ) !=
V_50 ) ) {
V_16 -> V_119 = V_120 ;
continue;
}
V_16 -> V_51 = ( V_16 -> V_1 & V_127 ) ;
F_2 ( V_16 , V_16 -> V_113 ,
V_28 , V_16 -> V_51 + 1 , false ) ;
if ( V_16 -> V_51 )
V_16 -> V_119 = V_122 ;
else
F_31 ( V_16 -> V_115 ) ;
break;
}
if ( V_16 -> V_119 != V_126 && ! V_16 -> V_51 )
V_16 -> V_119 = V_126 ;
}
F_5 ( V_16 -> V_27 , L_44 ) ;
F_32 ( V_16 -> V_115 ) ;
}
static void F_33 ( struct V_52 * V_52 , struct V_53 * V_54 )
{
struct V_15 * V_16 ;
int V_117 ;
if ( ! V_52 )
return;
V_16 = V_52 -> V_55 ;
if ( ! V_16 ) {
F_34 ( V_52 ) ;
return;
}
V_117 = V_52 -> V_56 ;
if ( V_16 -> V_75 == V_76 ) {
V_16 -> V_75 = V_128 ;
F_5 ( V_16 -> V_27 , L_45 ,
V_117 ) ;
}
switch ( V_52 -> V_57 ) {
case 0 :
F_27 ( V_16 , V_117 ) ;
break;
case - V_129 :
case - V_130 :
case - V_131 :
F_34 ( V_52 ) ;
return;
case - V_132 :
default:
F_5 ( V_16 -> V_27 , L_46 , V_52 -> V_57 ) ;
break;
}
F_15 ( V_52 , V_78 ) ;
}
static void F_35 ( struct V_15 * V_16 )
{
int V_83 ;
struct V_26 * V_27 = V_16 -> V_27 ;
char * V_59 ;
V_59 = F_12 ( V_133 , V_67 ) ;
if ( ! V_59 ) {
F_11 ( V_27 , L_47 , V_110 ) ;
return;
}
V_83 = F_36 ( V_16 -> V_68 , F_37 ( V_16 -> V_68 , 0 ) ,
V_134 , V_135 , 0 , 0 ,
V_59 , V_133 , V_136 * 3 ) ;
F_5 ( V_27 , L_48 , V_110 , V_83 ) ;
F_5 ( V_27 , L_49 ,
V_110 , V_59 [ 0 ] , V_59 [ 1 ] ) ;
V_83 = F_36 ( V_16 -> V_68 , F_38 ( V_16 -> V_68 , 0 ) ,
V_137 , V_135 ,
0xc04e , 0x0000 , NULL , 0 , V_136 * 3 ) ;
F_5 ( V_27 , L_48 , V_110 , V_83 ) ;
V_83 = F_36 ( V_16 -> V_68 , F_38 ( V_16 -> V_68 , 0 ) ,
4 , V_135 ,
0x0808 , 0x0000 , NULL , 0 , V_136 * 3 ) ;
F_5 ( V_27 , L_50 , V_110 , V_83 ) ;
V_83 = F_36 ( V_16 -> V_68 , F_38 ( V_16 -> V_68 , 0 ) ,
2 , V_135 ,
0x0000 , 0x0100 , NULL , 0 , V_136 * 3 ) ;
F_5 ( V_27 , L_51 , V_110 , V_83 ) ;
F_16 ( V_16 , V_138 , sizeof( V_138 ) ) ;
F_16 ( V_16 , V_139 , sizeof( V_139 ) ) ;
F_6 ( V_59 ) ;
}
static void F_39 ( struct V_15 * V_16 )
{
F_16 ( V_16 , V_138 , sizeof( V_138 ) ) ;
F_16 ( V_16 , V_139 , sizeof( V_139 ) ) ;
F_16 ( V_16 , V_140 , sizeof( V_140 ) ) ;
F_16 ( V_16 , V_141 , sizeof( V_141 ) ) ;
}
static void F_40 ( struct V_15 * V_16 )
{
F_16 ( V_16 , V_142 , sizeof( V_142 ) ) ;
if ( ! V_16 -> V_32 . V_143 )
F_16 ( V_16 , V_144 , sizeof( V_144 ) ) ;
F_16 ( V_16 , V_145 , sizeof( V_145 ) ) ;
F_16 ( V_16 , V_146 , sizeof( V_146 ) ) ;
}
static struct V_79 * F_41 ( struct V_15 * V_16 )
{
struct V_26 * V_27 = V_16 -> V_27 ;
struct V_79 * V_115 ;
int V_83 ;
V_115 = F_42 () ;
if ( ! V_115 ) {
F_11 ( V_27 , L_52 ) ;
goto V_20;
}
snprintf ( V_16 -> V_147 , sizeof( V_16 -> V_147 ) , L_53 ,
V_148 [ V_16 -> V_149 ] . V_147 ?
V_148 [ V_16 -> V_149 ] . V_147 :
L_54 ,
F_43 ( V_16 -> V_68 -> V_150 . V_151 ) ,
F_43 ( V_16 -> V_68 -> V_150 . V_152 ) ) ;
F_44 ( V_16 -> V_68 , V_16 -> V_153 , sizeof( V_16 -> V_153 ) ) ;
V_115 -> V_154 = V_16 -> V_147 ;
V_115 -> V_155 = V_16 -> V_153 ;
F_45 ( V_16 -> V_68 , & V_115 -> V_156 ) ;
V_115 -> V_27 . V_157 = V_27 ;
V_115 -> V_82 = V_16 ;
V_115 -> V_158 = V_159 ;
V_115 -> V_160 = V_161 ;
V_115 -> V_116 = F_46 ( 100 ) ;
if ( ! V_16 -> V_32 . V_143 ) {
V_115 -> V_162 = F_23 ;
V_115 -> V_163 = F_24 ;
V_115 -> V_164 = F_18 ;
}
V_115 -> V_165 = V_166 ;
V_115 -> V_167 = V_148 [ V_16 -> V_149 ] . V_168 ?
V_148 [ V_16 -> V_149 ] . V_168 : V_169 ;
V_83 = F_47 ( V_115 ) ;
if ( V_83 < 0 ) {
F_11 ( V_27 , L_55 ) ;
goto V_20;
}
return V_115 ;
V_20:
F_48 ( V_115 ) ;
return NULL ;
}
static int T_3 F_49 ( struct V_170 * V_171 ,
const struct V_172 * V_173 )
{
struct V_174 * V_27 = F_50 ( V_171 ) ;
struct V_175 * V_176 ;
struct V_177 * V_178 = NULL ;
struct V_177 * V_179 = NULL ;
struct V_177 * V_180 = NULL ;
struct V_15 * V_16 = NULL ;
int V_63 , V_181 , V_28 ;
char V_17 [ 63 ] , V_147 [ 128 ] = L_56 ;
enum V_182 V_149 = V_173 -> V_183 ;
bool V_184 ;
bool V_185 ;
bool V_104 ;
int V_186 ;
F_5 ( & V_171 -> V_27 , L_57 , V_110 ) ;
V_176 = V_171 -> V_187 ;
V_184 = V_148 [ V_149 ] . V_188 ;
V_185 = V_148 [ V_149 ] . V_189 ;
V_104 = V_148 [ V_149 ] . V_104 ;
V_186 = V_148 [ V_149 ] . V_186 ;
if ( V_176 -> V_190 . V_191 != V_186 )
return - V_192 ;
for ( V_28 = 0 ; V_28 < V_176 -> V_190 . V_193 ; ++ V_28 ) {
V_178 = & V_176 -> V_194 [ V_28 ] . V_190 ;
if ( ( V_179 == NULL )
&& ( ( V_178 -> V_70 & V_195 )
== V_196 )
&& ( ( ( V_178 -> V_197 & V_198 )
== V_199 )
|| ( ( V_178 -> V_197 & V_198 )
== V_200 ) ) ) {
V_179 = V_178 ;
V_179 -> V_197 = V_200 ;
V_179 -> V_72 = 1 ;
F_5 ( & V_171 -> V_27 , L_58
L_59 ) ;
}
if ( ( V_180 == NULL )
&& ( ( V_178 -> V_70 & V_195 )
== V_201 )
&& ( ( ( V_178 -> V_197 & V_198 )
== V_199 )
|| ( ( V_178 -> V_197 & V_198 )
== V_200 ) ) ) {
V_180 = V_178 ;
V_180 -> V_197 = V_200 ;
V_180 -> V_72 = 1 ;
F_5 ( & V_171 -> V_27 , L_60
L_59 ) ;
}
}
if ( V_179 == NULL ) {
F_5 ( & V_171 -> V_27 , L_61 ) ;
return - V_192 ;
}
V_63 = F_51 ( V_27 , V_179 -> V_70 ) ;
V_181 = F_52 ( V_27 , V_63 , F_53 ( V_63 ) ) ;
V_16 = F_12 ( sizeof( struct V_15 ) , V_67 ) ;
if ( ! V_16 )
goto V_202;
V_16 -> V_113 = F_54 ( V_27 , V_181 , V_78 , & V_16 -> V_203 ) ;
if ( ! V_16 -> V_113 )
goto V_204;
V_16 -> V_74 = F_9 ( 0 , V_67 ) ;
if ( ! V_16 -> V_74 )
goto V_205;
V_16 -> V_68 = V_27 ;
V_16 -> V_27 = & V_171 -> V_27 ;
V_16 -> V_206 = V_181 ;
V_16 -> V_32 . V_33 = V_185 ;
V_16 -> V_32 . V_104 = V_104 ;
V_16 -> V_32 . V_143 = V_148 [ V_149 ] . V_143 ;
V_16 -> V_149 = V_149 ;
V_16 -> V_207 = V_179 ;
V_16 -> V_69 = V_180 ;
if ( V_27 -> V_150 . V_208
&& F_55 ( V_27 , V_27 -> V_150 . V_208 ,
V_17 , sizeof( V_17 ) ) > 0 )
F_56 ( V_147 , V_17 , sizeof( V_147 ) ) ;
if ( V_27 -> V_150 . V_209
&& F_55 ( V_27 , V_27 -> V_150 . V_209 ,
V_17 , sizeof( V_17 ) ) > 0 )
snprintf ( V_147 + strlen ( V_147 ) , sizeof( V_147 ) - strlen ( V_147 ) ,
L_62 , V_17 ) ;
V_16 -> V_115 = F_41 ( V_16 ) ;
if ( ! V_16 -> V_115 )
goto V_210;
F_14 ( V_16 -> V_74 , V_27 , V_63 , V_16 -> V_113 ,
V_181 , ( V_71 ) F_33 , V_16 , V_179 -> V_72 ) ;
V_16 -> V_74 -> V_211 = V_16 -> V_203 ;
V_16 -> V_74 -> V_212 |= V_213 ;
F_5 ( & V_171 -> V_27 , L_63 ) ;
F_17 ( V_16 , V_181 ) ;
if ( V_16 -> V_32 . V_33 )
F_35 ( V_16 ) ;
else if ( ! V_184 )
F_39 ( V_16 ) ;
F_40 ( V_16 ) ;
if ( ! V_16 -> V_32 . V_143 )
F_23 ( V_16 -> V_115 , V_105 ) ;
F_57 ( V_171 , V_16 ) ;
F_3 ( & V_171 -> V_27 , L_64 , V_147 ,
V_27 -> V_214 -> V_215 , V_27 -> V_216 ) ;
return 0 ;
V_210:
F_7 ( V_16 -> V_74 ) ;
V_205:
F_58 ( V_27 , V_181 , V_16 -> V_113 , V_16 -> V_203 ) ;
V_204:
F_6 ( V_16 ) ;
V_202:
F_11 ( & V_171 -> V_27 , L_65 , V_110 ) ;
return - V_92 ;
}
static void T_4 F_59 ( struct V_170 * V_171 )
{
struct V_174 * V_27 = F_50 ( V_171 ) ;
struct V_15 * V_16 = F_60 ( V_171 ) ;
F_57 ( V_171 , NULL ) ;
if ( ! V_16 )
return;
V_16 -> V_68 = NULL ;
F_61 ( V_16 -> V_115 ) ;
F_62 ( V_16 -> V_74 ) ;
F_7 ( V_16 -> V_74 ) ;
F_58 ( V_27 , V_16 -> V_206 , V_16 -> V_113 , V_16 -> V_203 ) ;
F_6 ( V_16 ) ;
}
static int F_63 ( struct V_170 * V_171 , T_5 V_217 )
{
struct V_15 * V_16 = F_60 ( V_171 ) ;
F_3 ( V_16 -> V_27 , L_66 ) ;
F_62 ( V_16 -> V_74 ) ;
return 0 ;
}
static int F_64 ( struct V_170 * V_171 )
{
struct V_15 * V_16 = F_60 ( V_171 ) ;
F_3 ( V_16 -> V_27 , L_67 ) ;
if ( F_15 ( V_16 -> V_74 , V_78 ) )
return - V_218 ;
return 0 ;
}
static int T_6 F_65 ( void )
{
int V_83 ;
V_83 = F_66 ( & V_219 ) ;
if ( V_83 < 0 )
F_67 (KERN_ERR DRIVER_NAME
L_68 , ret) ;
return V_83 ;
}
static void T_7 F_68 ( void )
{
F_69 ( & V_219 ) ;
}
