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
static int F_18 ( struct V_79 * V_27 , unsigned * V_80 , unsigned V_81 )
{
struct V_15 * V_16 = V_27 -> V_82 ;
int V_28 , V_83 = 0 ;
int V_84 = 0 ;
unsigned char * V_85 ;
long V_86 = 0 ;
struct V_87 V_88 , V_89 ;
F_19 ( & V_88 ) ;
V_85 = F_12 ( sizeof( unsigned ) * V_90 , V_67 ) ;
if ( ! V_85 )
return - V_91 ;
V_85 [ V_84 ++ ] = V_7 ;
V_85 [ V_84 ++ ] = V_13 ;
V_85 [ V_84 ++ ] = V_16 -> V_92 ;
for ( V_28 = 0 ; ( V_28 < V_81 ) && ( V_84 < V_90 ) ; V_28 ++ ) {
V_86 += V_80 [ V_28 ] ;
V_80 [ V_28 ] = V_80 [ V_28 ] / V_40 ;
do {
if ( ( V_84 < V_90 ) &&
( V_84 - V_93 ) %
V_94 == 0 )
V_85 [ V_84 ++ ] = V_95 ;
if ( V_84 < V_90 )
V_85 [ V_84 ++ ] =
( V_80 [ V_28 ] < V_96 ?
V_80 [ V_28 ] : V_97 ) |
( V_28 & 1 ? 0x00 : V_96 ) ;
else {
V_83 = - V_98 ;
goto V_20;
}
} while ( ( V_80 [ V_28 ] > V_97 ) &&
( V_80 [ V_28 ] -= V_97 ) );
}
V_85 [ V_84 - ( V_84 - V_93 ) % V_94 ] =
V_50 + ( V_84 - V_93 ) %
V_94 - 1 ;
if ( V_84 >= V_90 ) {
V_83 = - V_98 ;
goto V_20;
}
V_85 [ V_84 ++ ] = V_48 ;
F_16 ( V_16 , V_85 , V_84 ) ;
F_19 ( & V_89 ) ;
V_86 -= ( V_89 . V_99 - V_88 . V_99 ) +
( V_89 . V_100 - V_88 . V_100 ) * 1000000 ;
F_20 ( V_101 ) ;
F_21 ( F_22 ( V_86 ) ) ;
V_20:
F_6 ( V_85 ) ;
return V_83 ? V_83 : V_81 ;
}
static int F_23 ( struct V_79 * V_27 , T_2 V_102 )
{
struct V_15 * V_16 = V_27 -> V_82 ;
if ( V_16 -> V_32 . V_103 )
V_16 -> V_92 = V_102 ;
else
V_16 -> V_92 = ( V_102 != V_104 ?
V_102 ^ V_104 : V_102 ) << 1 ;
return 0 ;
}
static int F_24 ( struct V_79 * V_27 , T_2 V_105 )
{
struct V_15 * V_16 = V_27 -> V_82 ;
int V_106 = 10000000 ;
int V_107 = 0 , V_108 = 0 ;
unsigned char V_85 [ 4 ] = { V_7 ,
V_9 , 0x00 , 0x00 } ;
if ( V_16 -> V_105 != V_105 ) {
if ( V_105 == 0 ) {
V_16 -> V_105 = V_105 ;
V_85 [ 2 ] = V_12 ;
V_85 [ 3 ] = V_48 ;
F_5 ( V_16 -> V_27 , L_37
L_38 , V_109 ) ;
F_16 ( V_16 , V_85 , sizeof( V_85 ) ) ;
return V_105 ;
}
for ( V_107 = 0 ; V_107 < 4 ; ++ V_107 ) {
V_108 = ( V_106 >> ( 2 * V_107 ) ) / V_105 ;
if ( V_108 <= 0xff ) {
V_16 -> V_105 = V_105 ;
V_85 [ 2 ] = V_107 ;
V_85 [ 3 ] = V_108 ;
F_5 ( V_16 -> V_27 , L_39
L_40 , V_109 , V_105 ) ;
F_16 ( V_16 , V_85 , sizeof( V_85 ) ) ;
return V_105 ;
}
}
return - V_98 ;
}
return V_105 ;
}
static void F_25 ( struct V_15 * V_16 , int V_110 )
{
T_1 V_111 = V_16 -> V_112 [ V_110 + 1 ] & 0xff ;
T_1 V_113 = V_16 -> V_112 [ V_110 + 2 ] & 0xff ;
switch ( V_16 -> V_112 [ V_110 ] ) {
case V_10 :
V_16 -> V_114 -> V_115 = F_26 ( ( V_111 << 8 | V_113 ) * V_40 ) ;
break;
case V_13 :
V_16 -> V_92 = V_111 ;
break;
case V_14 :
V_16 -> V_44 = ( V_111 == 0x02 ) ;
break;
default:
break;
}
}
static void F_27 ( struct V_15 * V_16 , int V_116 )
{
F_28 ( V_117 ) ;
int V_28 = 0 ;
if ( V_16 -> V_32 . V_33 )
V_28 = 2 ;
if ( V_116 <= V_28 )
return;
for (; V_28 < V_116 ; V_28 ++ ) {
switch ( V_16 -> V_118 ) {
case V_119 :
V_16 -> V_51 = F_1 ( V_16 -> V_1 , V_16 -> V_112 [ V_28 ] ) ;
F_2 ( V_16 , V_16 -> V_112 , V_28 - 1 ,
V_16 -> V_51 + 2 , false ) ;
F_25 ( V_16 , V_28 ) ;
V_16 -> V_118 = V_120 ;
break;
case V_121 :
V_16 -> V_51 -- ;
F_29 ( & V_117 ) ;
V_117 . V_122 = ( ( V_16 -> V_112 [ V_28 ] & V_96 ) != 0 ) ;
V_117 . V_123 = ( V_16 -> V_112 [ V_28 ] & V_124 )
* F_26 ( V_40 ) ;
F_5 ( V_16 -> V_27 , L_41 ,
V_117 . V_122 ? L_42 : L_43 ,
V_117 . V_123 ) ;
F_30 ( V_16 -> V_114 , & V_117 ) ;
break;
case V_120 :
V_16 -> V_51 -- ;
break;
case V_125 :
V_16 -> V_1 = V_16 -> V_112 [ V_28 ] ;
if ( ( V_16 -> V_1 == V_7 ) ||
( ( V_16 -> V_1 & V_49 ) !=
V_50 ) ) {
V_16 -> V_118 = V_119 ;
continue;
}
V_16 -> V_51 = ( V_16 -> V_1 & V_126 ) ;
F_2 ( V_16 , V_16 -> V_112 ,
V_28 , V_16 -> V_51 + 1 , false ) ;
if ( V_16 -> V_51 )
V_16 -> V_118 = V_121 ;
else
F_31 ( V_16 -> V_114 ) ;
break;
}
if ( V_16 -> V_118 != V_125 && ! V_16 -> V_51 )
V_16 -> V_118 = V_125 ;
}
F_5 ( V_16 -> V_27 , L_44 ) ;
F_32 ( V_16 -> V_114 ) ;
}
static void F_33 ( struct V_52 * V_52 , struct V_53 * V_54 )
{
struct V_15 * V_16 ;
int V_116 ;
if ( ! V_52 )
return;
V_16 = V_52 -> V_55 ;
if ( ! V_16 ) {
F_34 ( V_52 ) ;
return;
}
V_116 = V_52 -> V_56 ;
if ( V_16 -> V_75 == V_76 ) {
V_16 -> V_75 = V_127 ;
F_5 ( V_16 -> V_27 , L_45 ,
V_116 ) ;
}
switch ( V_52 -> V_57 ) {
case 0 :
F_27 ( V_16 , V_116 ) ;
break;
case - V_128 :
case - V_129 :
case - V_130 :
F_34 ( V_52 ) ;
return;
case - V_131 :
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
V_59 = F_12 ( V_132 , V_67 ) ;
if ( ! V_59 ) {
F_11 ( V_27 , L_47 , V_109 ) ;
return;
}
V_83 = F_36 ( V_16 -> V_68 , F_37 ( V_16 -> V_68 , 0 ) ,
V_133 , V_134 , 0 , 0 ,
V_59 , V_132 , V_135 * 3 ) ;
F_5 ( V_27 , L_48 , V_109 , V_83 ) ;
F_5 ( V_27 , L_49 ,
V_109 , V_59 [ 0 ] , V_59 [ 1 ] ) ;
V_83 = F_36 ( V_16 -> V_68 , F_38 ( V_16 -> V_68 , 0 ) ,
V_136 , V_134 ,
0xc04e , 0x0000 , NULL , 0 , V_135 * 3 ) ;
F_5 ( V_27 , L_48 , V_109 , V_83 ) ;
V_83 = F_36 ( V_16 -> V_68 , F_38 ( V_16 -> V_68 , 0 ) ,
4 , V_134 ,
0x0808 , 0x0000 , NULL , 0 , V_135 * 3 ) ;
F_5 ( V_27 , L_50 , V_109 , V_83 ) ;
V_83 = F_36 ( V_16 -> V_68 , F_38 ( V_16 -> V_68 , 0 ) ,
2 , V_134 ,
0x0000 , 0x0100 , NULL , 0 , V_135 * 3 ) ;
F_5 ( V_27 , L_51 , V_109 , V_83 ) ;
F_16 ( V_16 , V_137 , sizeof( V_137 ) ) ;
F_16 ( V_16 , V_138 , sizeof( V_138 ) ) ;
F_6 ( V_59 ) ;
}
static void F_39 ( struct V_15 * V_16 )
{
F_16 ( V_16 , V_137 , sizeof( V_137 ) ) ;
F_16 ( V_16 , V_138 , sizeof( V_138 ) ) ;
F_16 ( V_16 , V_139 , sizeof( V_139 ) ) ;
F_16 ( V_16 , V_140 , sizeof( V_140 ) ) ;
}
static void F_40 ( struct V_15 * V_16 )
{
F_16 ( V_16 , V_141 , sizeof( V_141 ) ) ;
if ( ! V_16 -> V_32 . V_142 )
F_16 ( V_16 , V_143 , sizeof( V_143 ) ) ;
F_16 ( V_16 , V_144 , sizeof( V_144 ) ) ;
F_16 ( V_16 , V_145 , sizeof( V_145 ) ) ;
}
static struct V_79 * F_41 ( struct V_15 * V_16 )
{
struct V_26 * V_27 = V_16 -> V_27 ;
struct V_79 * V_114 ;
int V_83 ;
V_114 = F_42 () ;
if ( ! V_114 ) {
F_11 ( V_27 , L_52 ) ;
goto V_20;
}
snprintf ( V_16 -> V_146 , sizeof( V_16 -> V_146 ) , L_53 ,
V_147 [ V_16 -> V_148 ] . V_146 ?
V_147 [ V_16 -> V_148 ] . V_146 :
L_54 ,
F_43 ( V_16 -> V_68 -> V_149 . V_150 ) ,
F_43 ( V_16 -> V_68 -> V_149 . V_151 ) ) ;
F_44 ( V_16 -> V_68 , V_16 -> V_152 , sizeof( V_16 -> V_152 ) ) ;
V_114 -> V_153 = V_16 -> V_146 ;
V_114 -> V_154 = V_16 -> V_152 ;
F_45 ( V_16 -> V_68 , & V_114 -> V_155 ) ;
V_114 -> V_27 . V_156 = V_27 ;
V_114 -> V_82 = V_16 ;
V_114 -> V_157 = V_158 ;
V_114 -> V_159 = V_160 ;
V_114 -> V_115 = F_46 ( 100 ) ;
if ( ! V_16 -> V_32 . V_142 ) {
V_114 -> V_161 = F_23 ;
V_114 -> V_162 = F_24 ;
V_114 -> V_163 = F_18 ;
}
V_114 -> V_164 = V_165 ;
V_114 -> V_166 = V_147 [ V_16 -> V_148 ] . V_167 ?
V_147 [ V_16 -> V_148 ] . V_167 : V_168 ;
V_83 = F_47 ( V_114 ) ;
if ( V_83 < 0 ) {
F_11 ( V_27 , L_55 ) ;
goto V_20;
}
return V_114 ;
V_20:
F_48 ( V_114 ) ;
return NULL ;
}
static int T_3 F_49 ( struct V_169 * V_170 ,
const struct V_171 * V_172 )
{
struct V_173 * V_27 = F_50 ( V_170 ) ;
struct V_174 * V_175 ;
struct V_176 * V_177 = NULL ;
struct V_176 * V_178 = NULL ;
struct V_176 * V_179 = NULL ;
struct V_15 * V_16 = NULL ;
int V_63 , V_180 , V_28 ;
char V_17 [ 63 ] , V_146 [ 128 ] = L_56 ;
enum V_181 V_148 = V_172 -> V_182 ;
bool V_183 ;
bool V_184 ;
bool V_103 ;
int V_185 ;
F_5 ( & V_170 -> V_27 , L_57 , V_109 ) ;
V_175 = V_170 -> V_186 ;
V_183 = V_147 [ V_148 ] . V_187 ;
V_184 = V_147 [ V_148 ] . V_188 ;
V_103 = V_147 [ V_148 ] . V_103 ;
V_185 = V_147 [ V_148 ] . V_185 ;
if ( V_175 -> V_189 . V_190 != V_185 )
return - V_191 ;
for ( V_28 = 0 ; V_28 < V_175 -> V_189 . V_192 ; ++ V_28 ) {
V_177 = & V_175 -> V_193 [ V_28 ] . V_189 ;
if ( ( V_178 == NULL )
&& ( ( V_177 -> V_70 & V_194 )
== V_195 )
&& ( ( ( V_177 -> V_196 & V_197 )
== V_198 )
|| ( ( V_177 -> V_196 & V_197 )
== V_199 ) ) ) {
V_178 = V_177 ;
V_178 -> V_196 = V_199 ;
V_178 -> V_72 = 1 ;
F_5 ( & V_170 -> V_27 , L_58
L_59 ) ;
}
if ( ( V_179 == NULL )
&& ( ( V_177 -> V_70 & V_194 )
== V_200 )
&& ( ( ( V_177 -> V_196 & V_197 )
== V_198 )
|| ( ( V_177 -> V_196 & V_197 )
== V_199 ) ) ) {
V_179 = V_177 ;
V_179 -> V_196 = V_199 ;
V_179 -> V_72 = 1 ;
F_5 ( & V_170 -> V_27 , L_60
L_59 ) ;
}
}
if ( V_178 == NULL ) {
F_5 ( & V_170 -> V_27 , L_61 ) ;
return - V_191 ;
}
V_63 = F_51 ( V_27 , V_178 -> V_70 ) ;
V_180 = F_52 ( V_27 , V_63 , F_53 ( V_63 ) ) ;
V_16 = F_12 ( sizeof( struct V_15 ) , V_67 ) ;
if ( ! V_16 )
goto V_201;
V_16 -> V_112 = F_54 ( V_27 , V_180 , V_78 , & V_16 -> V_202 ) ;
if ( ! V_16 -> V_112 )
goto V_203;
V_16 -> V_74 = F_9 ( 0 , V_67 ) ;
if ( ! V_16 -> V_74 )
goto V_204;
V_16 -> V_68 = V_27 ;
V_16 -> V_27 = & V_170 -> V_27 ;
V_16 -> V_205 = V_180 ;
V_16 -> V_32 . V_33 = V_184 ;
V_16 -> V_32 . V_103 = V_103 ;
V_16 -> V_32 . V_142 = V_147 [ V_148 ] . V_142 ;
V_16 -> V_148 = V_148 ;
V_16 -> V_206 = V_178 ;
V_16 -> V_69 = V_179 ;
if ( V_27 -> V_149 . V_207
&& F_55 ( V_27 , V_27 -> V_149 . V_207 ,
V_17 , sizeof( V_17 ) ) > 0 )
F_56 ( V_146 , V_17 , sizeof( V_146 ) ) ;
if ( V_27 -> V_149 . V_208
&& F_55 ( V_27 , V_27 -> V_149 . V_208 ,
V_17 , sizeof( V_17 ) ) > 0 )
snprintf ( V_146 + strlen ( V_146 ) , sizeof( V_146 ) - strlen ( V_146 ) ,
L_62 , V_17 ) ;
V_16 -> V_114 = F_41 ( V_16 ) ;
if ( ! V_16 -> V_114 )
goto V_209;
F_14 ( V_16 -> V_74 , V_27 , V_63 , V_16 -> V_112 ,
V_180 , ( V_71 ) F_33 , V_16 , V_178 -> V_72 ) ;
V_16 -> V_74 -> V_210 = V_16 -> V_202 ;
V_16 -> V_74 -> V_211 |= V_212 ;
F_5 ( & V_170 -> V_27 , L_63 ) ;
F_17 ( V_16 , V_180 ) ;
if ( V_16 -> V_32 . V_33 )
F_35 ( V_16 ) ;
else if ( ! V_183 )
F_39 ( V_16 ) ;
F_40 ( V_16 ) ;
if ( ! V_16 -> V_32 . V_142 )
F_23 ( V_16 -> V_114 , V_104 ) ;
F_57 ( V_170 , V_16 ) ;
F_3 ( & V_170 -> V_27 , L_64 , V_146 ,
V_27 -> V_213 -> V_214 , V_27 -> V_215 ) ;
return 0 ;
V_209:
F_7 ( V_16 -> V_74 ) ;
V_204:
F_58 ( V_27 , V_180 , V_16 -> V_112 , V_16 -> V_202 ) ;
V_203:
F_6 ( V_16 ) ;
V_201:
F_11 ( & V_170 -> V_27 , L_65 , V_109 ) ;
return - V_91 ;
}
static void T_4 F_59 ( struct V_169 * V_170 )
{
struct V_173 * V_27 = F_50 ( V_170 ) ;
struct V_15 * V_16 = F_60 ( V_170 ) ;
F_57 ( V_170 , NULL ) ;
if ( ! V_16 )
return;
V_16 -> V_68 = NULL ;
F_61 ( V_16 -> V_114 ) ;
F_62 ( V_16 -> V_74 ) ;
F_7 ( V_16 -> V_74 ) ;
F_58 ( V_27 , V_16 -> V_205 , V_16 -> V_112 , V_16 -> V_202 ) ;
F_6 ( V_16 ) ;
}
static int F_63 ( struct V_169 * V_170 , T_5 V_216 )
{
struct V_15 * V_16 = F_60 ( V_170 ) ;
F_3 ( V_16 -> V_27 , L_66 ) ;
F_62 ( V_16 -> V_74 ) ;
return 0 ;
}
static int F_64 ( struct V_169 * V_170 )
{
struct V_15 * V_16 = F_60 ( V_170 ) ;
F_3 ( V_16 -> V_27 , L_67 ) ;
if ( F_15 ( V_16 -> V_74 , V_78 ) )
return - V_217 ;
return 0 ;
}
static int T_6 F_65 ( void )
{
int V_83 ;
V_83 = F_66 ( & V_218 ) ;
if ( V_83 < 0 )
F_67 (KERN_ERR DRIVER_NAME
L_68 , ret) ;
return V_83 ;
}
static void T_7 F_68 ( void )
{
F_69 ( & V_218 ) ;
}
