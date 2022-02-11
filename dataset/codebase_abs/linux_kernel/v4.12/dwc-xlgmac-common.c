static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
memcpy ( V_2 -> V_5 , V_6 , V_4 -> V_7 ) ;
}
static void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_8 = V_9 ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = V_13 ;
V_2 -> V_14 = V_15 ;
V_2 -> V_16 = V_17 ;
V_2 -> V_18 = V_17 ;
V_2 -> V_19 = V_20 ;
V_2 -> V_21 = V_22 ;
V_2 -> V_23 = 1 ;
V_2 -> V_24 = 1 ;
V_2 -> V_25 = V_26 ;
V_2 -> V_27 = V_28 ;
F_3 ( V_2 -> V_29 , V_30 , sizeof( V_2 -> V_29 ) ) ;
F_3 ( V_2 -> V_31 , V_32 , sizeof( V_2 -> V_31 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_33 ) ;
F_6 ( & V_2 -> V_34 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_35 * V_34 = & V_2 -> V_34 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_36 ;
int V_37 ;
F_2 ( V_2 ) ;
V_4 -> V_38 = V_2 -> V_39 ;
V_4 -> V_40 = ( unsigned long ) V_2 -> V_41 ;
F_1 ( V_2 ) ;
memcpy ( V_4 -> V_6 , V_2 -> V_5 , V_4 -> V_7 ) ;
F_4 ( V_2 ) ;
V_34 -> exit ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
V_37 = F_10 ( V_2 -> V_42 ,
F_11 ( V_2 -> V_43 . V_44 ) ) ;
if ( V_37 ) {
F_12 ( V_2 -> V_42 , L_1 ) ;
return V_37 ;
}
F_13 ( V_45 ) ;
V_2 -> V_46 = V_45 ;
if ( V_2 -> V_46 & ( V_2 -> V_46 - 1 ) ) {
F_12 ( V_2 -> V_42 , L_2 ,
V_2 -> V_46 ) ;
V_37 = - V_47 ;
return V_37 ;
}
F_13 ( V_48 ) ;
V_2 -> V_49 = V_48 ;
if ( V_2 -> V_49 & ( V_2 -> V_49 - 1 ) ) {
F_12 ( V_2 -> V_42 , L_3 ,
V_2 -> V_49 ) ;
V_37 = - V_47 ;
return V_37 ;
}
V_2 -> V_50 = F_14 (unsigned int, num_online_cpus(),
pdata->hw_feat.tx_ch_cnt) ;
V_2 -> V_50 = F_14 (unsigned int, pdata->tx_ring_count,
pdata->hw_feat.tx_q_cnt) ;
V_2 -> V_51 = V_2 -> V_50 ;
V_37 = F_15 ( V_4 , V_2 -> V_51 ) ;
if ( V_37 ) {
F_12 ( V_2 -> V_42 , L_4 ) ;
return V_37 ;
}
V_2 -> V_52 = F_14 (unsigned int,
netif_get_num_default_rss_queues(),
pdata->hw_feat.rx_ch_cnt) ;
V_2 -> V_52 = F_14 (unsigned int, pdata->rx_ring_count,
pdata->hw_feat.rx_q_cnt) ;
V_2 -> V_53 = V_2 -> V_52 ;
V_37 = F_16 ( V_4 , V_2 -> V_53 ) ;
if ( V_37 ) {
F_12 ( V_2 -> V_42 , L_5 ) ;
return V_37 ;
}
V_2 -> V_54 =
F_17 (unsigned int, pdata->tx_ring_count, pdata->rx_ring_count) ;
F_18 ( V_2 -> V_55 , sizeof( V_2 -> V_55 ) ) ;
for ( V_36 = 0 ; V_36 < V_56 ; V_36 ++ )
V_2 -> V_57 [ V_36 ] = F_19 (
V_2 -> V_57 [ V_36 ] ,
V_58 ,
V_59 ,
V_36 % V_2 -> V_52 ) ;
V_2 -> V_60 = F_19 (
V_2 -> V_60 ,
V_61 ,
V_62 , 1 ) ;
V_2 -> V_60 = F_19 (
V_2 -> V_60 ,
V_63 ,
V_64 , 1 ) ;
V_2 -> V_60 = F_19 (
V_2 -> V_60 ,
V_65 ,
V_66 , 1 ) ;
V_4 -> V_67 = F_20 () ;
V_4 -> V_68 = F_21 () ;
if ( V_2 -> V_43 . V_69 ) {
V_4 -> V_70 = V_71 ;
V_4 -> V_70 |= V_72 ;
V_4 -> V_70 |= V_73 ;
V_4 -> V_70 |= V_74 ;
V_4 -> V_70 |= V_75 ;
} else if ( V_2 -> V_43 . V_76 ) {
V_4 -> V_70 = V_74 ;
V_4 -> V_70 |= V_75 ;
}
if ( V_2 -> V_43 . V_77 ) {
V_4 -> V_70 |= V_78 ;
V_4 -> V_70 |= V_79 ;
}
if ( V_2 -> V_43 . V_80 )
V_4 -> V_70 |= V_81 ;
V_4 -> V_82 |= V_4 -> V_70 ;
V_4 -> V_70 |= V_83 ;
if ( V_2 -> V_43 . V_84 )
V_4 -> V_70 |= V_85 ;
if ( V_2 -> V_43 . V_86 )
V_4 -> V_70 |= V_87 ;
V_4 -> V_88 |= V_4 -> V_70 ;
V_2 -> V_89 = V_4 -> V_88 ;
V_4 -> V_90 |= V_91 ;
V_4 -> V_92 = 0 ;
V_2 -> V_93 = V_94 ;
V_2 -> V_95 = V_96 ;
V_2 -> V_97 = V_34 -> V_98 ( V_2 , V_99 ) ;
V_2 -> V_100 = V_99 ;
V_2 -> V_101 = V_102 ;
return 0 ;
}
int F_22 ( struct V_103 * V_42 , struct V_104 * V_105 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_37 ;
V_4 = F_23 ( sizeof( struct V_1 ) ,
V_106 ) ;
if ( ! V_4 ) {
F_12 ( V_42 , L_6 ) ;
return - V_107 ;
}
F_24 ( V_4 , V_42 ) ;
F_25 ( V_42 , V_4 ) ;
V_2 = F_26 ( V_4 ) ;
V_2 -> V_42 = V_42 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_39 = V_105 -> V_38 ;
V_2 -> V_41 = V_105 -> V_108 ;
F_27 ( & V_2 -> V_109 ) ;
V_2 -> V_110 = F_28 ( V_111 , V_112 ) ;
V_37 = F_7 ( V_2 ) ;
if ( V_37 ) {
F_12 ( V_42 , L_7 ) ;
goto V_113;
}
V_37 = F_29 ( V_4 ) ;
if ( V_37 ) {
F_12 ( V_42 , L_8 ) ;
goto V_113;
}
return 0 ;
V_113:
F_30 ( V_4 ) ;
return V_37 ;
}
int F_31 ( struct V_103 * V_42 )
{
struct V_3 * V_4 = F_32 ( V_42 ) ;
F_33 ( V_4 ) ;
F_30 ( V_4 ) ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 ,
struct V_114 * V_115 ,
unsigned int V_116 ,
unsigned int V_117 ,
unsigned int V_118 )
{
struct V_119 * V_120 ;
struct V_121 * V_122 ;
while ( V_117 -- ) {
V_120 = F_35 ( V_115 , V_116 ) ;
V_122 = V_120 -> V_122 ;
F_36 ( V_2 -> V_4 , L_9 ,
V_120 -> V_122 , & V_120 -> V_123 ) ;
F_36 ( V_2 -> V_4 ,
L_10 , V_116 ,
( V_118 == 1 ) ? L_11 : L_12 ,
F_37 ( V_122 -> V_124 ) ,
F_37 ( V_122 -> V_125 ) ,
F_37 ( V_122 -> V_126 ) ,
F_37 ( V_122 -> V_127 ) ) ;
V_116 ++ ;
}
}
void F_38 ( struct V_1 * V_2 ,
struct V_114 * V_115 ,
unsigned int V_116 )
{
struct V_119 * V_120 ;
struct V_121 * V_122 ;
V_120 = F_35 ( V_115 , V_116 ) ;
V_122 = V_120 -> V_122 ;
F_36 ( V_2 -> V_4 , L_13 ,
V_120 -> V_122 , & V_120 -> V_123 ) ;
F_36 ( V_2 -> V_4 ,
L_14 ,
V_116 ,
F_37 ( V_122 -> V_124 ) ,
F_37 ( V_122 -> V_125 ) ,
F_37 ( V_122 -> V_126 ) ,
F_37 ( V_122 -> V_127 ) ) ;
}
void F_39 ( struct V_3 * V_4 ,
struct V_128 * V_129 , bool V_130 )
{
struct V_131 * V_132 = (struct V_131 * ) V_129 -> V_133 ;
unsigned char * V_134 = V_129 -> V_133 ;
unsigned char V_135 [ 128 ] ;
unsigned int V_36 , V_136 ;
F_36 ( V_4 , L_15 ) ;
F_36 ( V_4 , L_16 ,
( V_130 ? L_17 : L_18 ) , V_129 -> V_137 ) ;
F_36 ( V_4 , L_19 , V_132 -> V_138 ) ;
F_36 ( V_4 , L_20 , V_132 -> V_139 ) ;
F_36 ( V_4 , L_21 , F_40 ( V_132 -> V_140 ) ) ;
for ( V_36 = 0 , V_136 = 0 ; V_36 < V_129 -> V_137 ; ) {
V_136 += snprintf ( V_135 + V_136 , sizeof( V_135 ) - V_136 , L_22 ,
V_134 [ V_36 ++ ] ) ;
if ( ( V_36 % 32 ) == 0 ) {
F_36 ( V_4 , L_23 , V_36 - 32 , V_135 ) ;
V_136 = 0 ;
} else if ( ( V_36 % 16 ) == 0 ) {
V_135 [ V_136 ++ ] = ' ' ;
V_135 [ V_136 ++ ] = ' ' ;
} else if ( ( V_36 % 4 ) == 0 ) {
V_135 [ V_136 ++ ] = ' ' ;
}
}
if ( V_36 % 32 )
F_36 ( V_4 , L_23 , V_36 - ( V_36 % 32 ) , V_135 ) ;
F_36 ( V_4 , L_15 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_141 * V_43 = & V_2 -> V_43 ;
unsigned int V_142 , V_143 , V_144 ;
V_142 = F_41 ( V_2 -> V_41 + V_145 ) ;
V_143 = F_41 ( V_2 -> V_41 + V_146 ) ;
V_144 = F_41 ( V_2 -> V_41 + V_147 ) ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
V_43 -> V_148 = F_41 ( V_2 -> V_41 + V_149 ) ;
V_43 -> V_150 = F_42 ( V_142 ,
V_151 ,
V_152 ) ;
V_43 -> V_86 = F_42 ( V_142 ,
V_153 ,
V_154 ) ;
V_43 -> V_155 = F_42 ( V_142 ,
V_156 ,
V_157 ) ;
V_43 -> V_158 = F_42 ( V_142 ,
V_159 ,
V_160 ) ;
V_43 -> V_161 = F_42 ( V_142 ,
V_162 ,
V_163 ) ;
V_43 -> V_164 = F_42 ( V_142 ,
V_165 ,
V_166 ) ;
V_43 -> V_167 = F_42 ( V_142 ,
V_168 ,
V_169 ) ;
V_43 -> V_170 = F_42 ( V_142 ,
V_171 ,
V_172 ) ;
V_43 -> V_173 = F_42 ( V_142 ,
V_174 ,
V_175 ) ;
V_43 -> V_76 = F_42 ( V_142 ,
V_176 ,
V_177 ) ;
V_43 -> V_77 = F_42 ( V_142 ,
V_178 ,
V_179 ) ;
V_43 -> V_180 = F_42 ( V_142 ,
V_181 ,
V_182 ) ;
V_43 -> V_183 = F_42 ( V_142 ,
V_184 ,
V_185 ) ;
V_43 -> V_84 = F_42 ( V_142 ,
V_186 ,
V_187 ) ;
V_43 -> V_188 = F_42 ( V_143 ,
V_189 ,
V_190 ) ;
V_43 -> V_191 = F_42 ( V_143 ,
V_192 ,
V_193 ) ;
V_43 -> V_194 = F_42 ( V_143 ,
V_195 ,
V_196 ) ;
V_43 -> V_44 = F_42 ( V_143 ,
V_197 ,
V_198 ) ;
V_43 -> V_199 = F_42 ( V_143 ,
V_200 ,
V_201 ) ;
V_43 -> V_202 = F_42 ( V_143 ,
V_203 ,
V_204 ) ;
V_43 -> V_69 = F_42 ( V_143 ,
V_205 ,
V_206 ) ;
V_43 -> V_207 = F_42 ( V_143 ,
V_208 ,
V_209 ) ;
V_43 -> V_80 = F_42 ( V_143 ,
V_210 ,
V_211 ) ;
V_43 -> V_212 = F_42 ( V_143 ,
V_213 ,
V_214 ) ;
V_43 -> V_215 = F_42 ( V_143 ,
V_216 ,
V_217 ) ;
V_43 -> V_218 = F_42 ( V_143 ,
V_219 ,
V_220 ) ;
V_43 -> V_221 = F_42 ( V_144 ,
V_222 ,
V_223 ) ;
V_43 -> V_224 = F_42 ( V_144 ,
V_225 ,
V_226 ) ;
V_43 -> V_227 = F_42 ( V_144 ,
V_228 ,
V_229 ) ;
V_43 -> V_230 = F_42 ( V_144 ,
V_231 ,
V_232 ) ;
V_43 -> V_233 = F_42 ( V_144 ,
V_234 ,
V_235 ) ;
V_43 -> V_236 = F_42 ( V_144 ,
V_237 ,
V_238 ) ;
switch ( V_43 -> V_215 ) {
case 0 :
break;
case 1 :
V_43 -> V_215 = 64 ;
break;
case 2 :
V_43 -> V_215 = 128 ;
break;
case 3 :
V_43 -> V_215 = 256 ;
break;
}
switch ( V_43 -> V_44 ) {
case 0 :
V_43 -> V_44 = 32 ;
break;
case 1 :
V_43 -> V_44 = 40 ;
break;
case 2 :
V_43 -> V_44 = 48 ;
break;
default:
V_43 -> V_44 = 32 ;
}
V_43 -> V_221 ++ ;
V_43 -> V_224 ++ ;
V_43 -> V_227 ++ ;
V_43 -> V_230 ++ ;
V_43 -> V_212 ++ ;
}
void F_9 ( struct V_1 * V_2 )
{
char * V_239 = NULL ;
F_43 ( L_24 ) ;
F_43 ( L_25 ) ;
F_43 ( L_24 ) ;
F_43 ( L_26 ) ;
F_43 ( L_24 ) ;
F_43 ( L_27 ,
V_2 -> V_43 . V_86 ? L_28 : L_29 ) ;
F_43 ( L_30 ,
V_2 -> V_43 . V_155 ? L_28 : L_29 ) ;
F_43 ( L_31 ,
V_2 -> V_43 . V_158 ? L_28 : L_29 ) ;
F_43 ( L_32 ,
V_2 -> V_43 . V_161 ? L_28 : L_29 ) ;
F_43 ( L_33 ,
V_2 -> V_43 . V_164 ? L_28 : L_29 ) ;
F_43 ( L_34 ,
V_2 -> V_43 . V_167 ? L_28 : L_29 ) ;
F_43 ( L_35 ,
V_2 -> V_43 . V_170 ? L_28 : L_29 ) ;
F_43 ( L_36 ,
V_2 -> V_43 . V_173 ? L_28 : L_29 ) ;
F_43 ( L_37 ,
V_2 -> V_43 . V_76 ? L_28 : L_29 ) ;
F_43 ( L_38 ,
V_2 -> V_43 . V_77 ? L_28 : L_29 ) ;
F_43 ( L_39 ,
V_2 -> V_43 . V_180 ? L_28 : L_29 ) ;
switch ( V_2 -> V_43 . V_183 ) {
case 0 :
V_239 = L_40 ;
break;
case 1 :
V_239 = L_41 ;
break;
case 2 :
V_239 = L_42 ;
break;
case 3 :
V_239 = L_43 ;
break;
}
F_43 ( L_44 , V_239 ) ;
F_43 ( L_45 ,
V_2 -> V_43 . V_84 ? L_28 : L_29 ) ;
switch ( V_2 -> V_43 . V_188 ) {
case 0 :
V_239 = L_46 ;
break;
case 1 :
V_239 = L_47 ;
break;
case 2 :
V_239 = L_48 ;
break;
case 3 :
V_239 = L_49 ;
break;
case 4 :
V_239 = L_50 ;
break;
case 5 :
V_239 = L_51 ;
break;
case 6 :
V_239 = L_52 ;
break;
case 7 :
V_239 = L_53 ;
break;
case 8 :
V_239 = L_54 ;
break;
case 9 :
V_239 = L_55 ;
break;
case 10 :
V_239 = L_56 ;
break;
case 11 :
V_239 = L_57 ;
break;
default:
V_239 = L_40 ;
}
F_43 ( L_58 , V_239 ) ;
switch ( V_2 -> V_43 . V_191 ) {
case 0 :
V_239 = L_46 ;
break;
case 1 :
V_239 = L_47 ;
break;
case 2 :
V_239 = L_48 ;
break;
case 3 :
V_239 = L_49 ;
break;
case 4 :
V_239 = L_50 ;
break;
case 5 :
V_239 = L_51 ;
break;
case 6 :
V_239 = L_52 ;
break;
case 7 :
V_239 = L_53 ;
break;
case 8 :
V_239 = L_54 ;
break;
case 9 :
V_239 = L_55 ;
break;
case 10 :
V_239 = L_56 ;
break;
case 11 :
V_239 = L_57 ;
break;
default:
V_239 = L_40 ;
}
F_43 ( L_59 , V_239 ) ;
F_43 ( L_60 ,
V_2 -> V_43 . V_194 ? L_28 : L_29 ) ;
F_43 ( L_61 ,
V_2 -> V_43 . V_44 ) ;
F_43 ( L_62 ,
V_2 -> V_43 . V_199 ? L_28 : L_29 ) ;
F_43 ( L_63 ,
V_2 -> V_43 . V_202 ? L_28 : L_29 ) ;
F_43 ( L_64 ,
V_2 -> V_43 . V_69 ? L_28 : L_29 ) ;
F_43 ( L_65 ,
V_2 -> V_43 . V_207 ? L_28 : L_29 ) ;
F_43 ( L_66 ,
V_2 -> V_43 . V_80 ? L_28 : L_29 ) ;
F_43 ( L_67 ,
( V_2 -> V_43 . V_212 ) ) ;
F_43 ( L_68 ,
V_2 -> V_43 . V_215 ) ;
F_43 ( L_69 ,
V_2 -> V_43 . V_218 ) ;
F_43 ( L_70 ,
V_2 -> V_43 . V_221 ) ;
F_43 ( L_71 ,
V_2 -> V_43 . V_224 ) ;
F_43 ( L_72 ,
V_2 -> V_43 . V_227 ) ;
F_43 ( L_73 ,
V_2 -> V_43 . V_230 ) ;
switch ( V_2 -> V_43 . V_233 ) {
case 0 :
V_239 = L_74 ;
break;
case 1 :
V_239 = L_75 ;
break;
case 2 :
V_239 = L_76 ;
break;
case 3 :
V_239 = L_77 ;
break;
case 4 :
V_239 = L_78 ;
break;
default:
V_239 = L_40 ;
}
F_43 ( L_79 , V_239 ) ;
switch ( V_2 -> V_43 . V_236 ) {
case 0 :
V_239 = L_80 ;
break;
case 1 :
V_239 = L_81 ;
break;
case 2 :
V_239 = L_82 ;
break;
case 3 :
V_239 = L_83 ;
break;
case 4 :
V_239 = L_84 ;
break;
default:
V_239 = L_40 ;
}
F_43 ( L_85 , V_239 ) ;
F_43 ( L_24 ) ;
F_43 ( L_25 ) ;
F_43 ( L_24 ) ;
}
