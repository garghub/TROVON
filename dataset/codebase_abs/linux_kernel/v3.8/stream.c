static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
if ( ! V_2 -> V_6 )
return;
F_2 (p, n, &subs->fmt_list) {
struct V_7 * V_8 = F_3 ( V_4 , struct V_7 , V_9 ) ;
F_4 ( V_8 -> V_10 ) ;
F_4 ( V_8 -> V_11 ) ;
F_4 ( V_8 ) ;
}
F_4 ( V_2 -> V_12 . V_9 ) ;
}
static void F_5 ( struct V_13 * V_14 )
{
F_1 ( & V_14 -> V_15 [ 0 ] ) ;
F_1 ( & V_14 -> V_15 [ 1 ] ) ;
F_6 ( & V_14 -> V_9 ) ;
F_4 ( V_14 ) ;
}
static void F_7 ( struct V_16 * V_17 )
{
struct V_13 * V_14 = V_17 -> V_18 ;
if ( V_14 ) {
V_14 -> V_17 = NULL ;
F_5 ( V_14 ) ;
}
}
static void F_8 ( struct V_13 * V_19 ,
int V_14 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_19 -> V_15 [ V_14 ] ;
F_9 ( & V_2 -> V_20 ) ;
F_10 ( & V_2 -> V_21 ) ;
V_2 -> V_14 = V_19 ;
V_2 -> V_22 = V_14 ;
V_2 -> V_23 = V_19 -> V_24 -> V_23 ;
V_2 -> V_25 = V_19 -> V_24 -> V_25 ;
V_2 -> V_26 = F_11 ( V_2 -> V_23 ) ;
F_12 ( V_19 -> V_17 , V_14 ) ;
F_13 ( & V_8 -> V_9 , & V_2 -> V_20 ) ;
V_2 -> V_27 |= V_8 -> V_27 ;
V_2 -> V_6 ++ ;
V_2 -> V_28 = V_8 -> V_28 ;
V_2 -> V_29 = V_8 -> V_30 ;
if ( V_8 -> V_31 > V_2 -> V_32 )
V_2 -> V_32 = V_8 -> V_31 ;
}
static int F_14 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 = F_15 ( V_34 ) ;
struct V_1 * V_2 = V_38 -> V_18 ;
V_36 -> type = V_39 ;
V_36 -> V_40 = V_2 -> V_32 ;
V_36 -> V_41 . integer . V_42 = 0 ;
V_36 -> V_41 . integer . V_43 = V_44 ;
return 0 ;
}
static bool F_16 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 ;
for ( V_4 = V_8 -> V_9 . V_45 ; V_4 != & V_2 -> V_20 ; V_4 = V_4 -> V_45 ) {
struct V_7 * V_45 ;
V_45 = F_3 ( V_4 , struct V_7 , V_9 ) ;
if ( V_45 -> V_11 &&
! memcmp ( V_45 -> V_11 , V_8 -> V_11 , sizeof( * V_8 -> V_11 ) ) )
return true ;
}
return false ;
}
static int F_17 ( struct V_33 * V_34 , int V_46 ,
unsigned int V_47 , unsigned int T_1 * V_48 )
{
struct V_37 * V_38 = F_15 ( V_34 ) ;
struct V_1 * V_2 = V_38 -> V_18 ;
struct V_7 * V_8 ;
unsigned int T_1 * V_49 ;
int V_40 = 0 ;
if ( V_47 < 8 )
return - V_50 ;
if ( F_18 ( V_51 , V_48 ) )
return - V_52 ;
V_47 -= 8 ;
V_49 = V_48 + 2 ;
F_19 (fp, &subs->fmt_list, list) {
int V_53 , V_54 ;
if ( ! V_8 -> V_11 )
continue;
if ( F_16 ( V_2 , V_8 ) )
continue;
V_54 = V_8 -> V_11 -> V_31 * 4 ;
if ( V_47 < 8 + V_54 )
return - V_50 ;
if ( F_18 ( V_55 , V_49 ) ||
F_18 ( V_54 , V_49 + 1 ) )
return - V_52 ;
V_49 += 2 ;
for ( V_53 = 0 ; V_53 < V_8 -> V_11 -> V_31 ; V_53 ++ , V_49 ++ ) {
if ( F_18 ( V_8 -> V_11 -> V_56 [ V_53 ] , V_49 ) )
return - V_52 ;
}
V_40 += 8 + V_54 ;
V_47 -= 8 + V_54 ;
}
if ( F_18 ( V_40 , V_48 + 1 ) )
return - V_52 ;
return 0 ;
}
static int F_20 ( struct V_33 * V_34 ,
struct V_57 * V_58 )
{
struct V_37 * V_38 = F_15 ( V_34 ) ;
struct V_1 * V_2 = V_38 -> V_18 ;
struct V_59 * V_11 = NULL ;
int V_53 ;
memset ( V_58 -> V_41 . integer . V_41 , 0 ,
sizeof( V_58 -> V_41 . integer . V_41 ) ) ;
if ( V_2 -> V_60 )
V_11 = V_2 -> V_60 -> V_11 ;
if ( V_11 ) {
for ( V_53 = 0 ; V_53 < V_11 -> V_31 ; V_53 ++ )
V_58 -> V_41 . integer . V_41 [ V_53 ] = V_11 -> V_56 [ V_53 ] ;
}
return 0 ;
}
static int F_21 ( struct V_16 * V_17 , int V_14 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_37 * V_11 ;
struct V_33 * V_61 ;
int V_62 ;
F_19 (fp, &subs->fmt_list, list)
if ( V_8 -> V_11 )
goto V_63;
return 0 ;
V_63:
V_62 = F_22 ( V_17 , V_14 , NULL , 0 , 0 , & V_11 ) ;
if ( V_62 < 0 )
return V_62 ;
V_11 -> V_18 = V_2 ;
V_61 = V_11 -> V_61 ;
V_61 -> V_38 = F_14 ;
V_61 -> V_64 = F_20 ;
V_61 -> V_48 . V_65 = F_17 ;
return 0 ;
}
static struct V_59 * F_23 ( int V_31 , unsigned int V_66 ,
int V_67 )
{
static unsigned int V_68 [] = {
V_69 ,
V_70 ,
V_71 ,
V_72 ,
V_73 ,
V_74 ,
V_75 ,
V_76 ,
V_77 ,
V_73 ,
V_74 ,
V_78 ,
0
} ;
static unsigned int V_79 [] = {
V_69 ,
V_70 ,
V_71 ,
V_72 ,
V_80 ,
V_81 ,
V_75 ,
V_76 ,
V_77 ,
V_73 ,
V_74 ,
V_78 ,
V_82 ,
V_83 ,
V_84 ,
V_85 ,
V_86 ,
V_87 ,
V_88 ,
V_89 ,
V_90 ,
V_91 ,
V_92 ,
V_93 ,
V_94 ,
V_95 ,
V_96 ,
0
} ;
struct V_59 * V_11 ;
const unsigned int * V_97 ;
int V_65 ;
if ( ! V_66 )
return NULL ;
if ( V_31 > F_24 ( V_11 -> V_56 ) )
return NULL ;
V_11 = F_25 ( sizeof( * V_11 ) , V_98 ) ;
if ( ! V_11 )
return NULL ;
V_97 = V_67 == V_99 ? V_79 : V_68 ;
V_11 -> V_31 = V_31 ;
V_65 = 0 ;
for (; V_66 && * V_97 ; V_97 ++ , V_66 >>= 1 ) {
if ( V_66 & 1 )
V_11 -> V_56 [ V_65 ++ ] = * V_97 ;
}
for (; V_65 < V_31 ; V_65 ++ )
V_11 -> V_56 [ V_65 ] = V_100 ;
return V_11 ;
}
int F_26 ( struct V_101 * V_24 ,
int V_14 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 ;
struct V_13 * V_19 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
int V_62 ;
F_27 (p, &chip->pcm_list) {
V_19 = F_3 ( V_4 , struct V_13 , V_9 ) ;
if ( V_19 -> V_28 != V_8 -> V_28 )
continue;
V_2 = & V_19 -> V_15 [ V_14 ] ;
if ( V_2 -> V_29 == V_8 -> V_30 ) {
F_13 ( & V_8 -> V_9 , & V_2 -> V_20 ) ;
V_2 -> V_6 ++ ;
V_2 -> V_27 |= V_8 -> V_27 ;
return 0 ;
}
}
F_27 (p, &chip->pcm_list) {
V_19 = F_3 ( V_4 , struct V_13 , V_9 ) ;
if ( V_19 -> V_28 != V_8 -> V_28 )
continue;
V_2 = & V_19 -> V_15 [ V_14 ] ;
if ( V_2 -> V_29 )
continue;
V_62 = F_28 ( V_19 -> V_17 , V_14 , 1 ) ;
if ( V_62 < 0 )
return V_62 ;
F_8 ( V_19 , V_14 , V_8 ) ;
return F_21 ( V_19 -> V_17 , V_14 , V_2 ) ;
}
V_19 = F_25 ( sizeof( * V_19 ) , V_98 ) ;
if ( ! V_19 )
return - V_50 ;
V_19 -> V_102 = V_24 -> V_103 ;
V_19 -> V_24 = V_24 ;
V_19 -> V_28 = V_8 -> V_28 ;
V_62 = F_29 ( V_24 -> V_104 , L_1 , V_24 -> V_103 ,
V_14 == V_105 ? 1 : 0 ,
V_14 == V_105 ? 0 : 1 ,
& V_17 ) ;
if ( V_62 < 0 ) {
F_4 ( V_19 ) ;
return V_62 ;
}
V_19 -> V_17 = V_17 ;
V_17 -> V_18 = V_19 ;
V_17 -> V_106 = F_7 ;
V_17 -> V_107 = 0 ;
if ( V_24 -> V_103 > 0 )
sprintf ( V_17 -> V_108 , L_2 , V_24 -> V_103 ) ;
else
strcpy ( V_17 -> V_108 , L_1 ) ;
F_8 ( V_19 , V_14 , V_8 ) ;
F_30 ( & V_19 -> V_9 , & V_24 -> V_109 ) ;
V_24 -> V_103 ++ ;
F_31 ( V_19 ) ;
return F_21 ( V_17 , V_14 , & V_19 -> V_15 [ V_14 ] ) ;
}
static int F_32 ( struct V_101 * V_24 ,
struct V_110 * V_111 ,
int V_67 , int V_112 )
{
struct V_113 * V_114 ;
struct V_115 * V_116 = F_33 ( V_111 ) ;
int V_117 = 0 ;
V_114 = F_34 ( V_111 -> V_30 [ 0 ] . V_118 , V_111 -> V_30 [ 0 ] . V_119 , NULL , V_120 ) ;
if ( ! V_114 && V_116 -> V_121 >= 2 )
V_114 = F_34 ( V_111 -> V_30 [ 1 ] . V_118 , V_111 -> V_30 [ 1 ] . V_119 , NULL , V_120 ) ;
if ( ! V_114 || V_114 -> V_122 < 7 ||
V_114 -> V_123 != V_124 ) {
F_35 ( V_125 L_3
L_4 ,
V_24 -> V_23 -> V_126 , V_112 ,
V_116 -> V_127 ) ;
return 0 ;
}
if ( V_67 == V_128 ) {
V_117 = V_114 -> V_129 ;
} else {
struct V_130 * V_131 =
(struct V_130 * ) V_114 ;
V_117 = V_114 -> V_129 & V_132 ;
if ( V_131 -> V_133 & V_134 )
V_117 |= V_135 ;
}
return V_117 ;
}
static void *
F_36 ( struct V_110 * V_136 ,
int V_137 )
{
struct V_138 * V_139 = NULL ;
while ( ( V_139 = F_37 ( V_136 -> V_118 ,
V_136 -> V_119 ,
V_139 , V_140 ) ) ) {
if ( V_139 -> V_141 == V_137 )
return V_139 ;
}
return NULL ;
}
static struct V_142 *
F_38 ( struct V_110 * V_136 ,
int V_137 )
{
struct V_142 * V_139 = NULL ;
while ( ( V_139 = F_37 ( V_136 -> V_118 ,
V_136 -> V_119 ,
V_139 , V_143 ) ) ) {
if ( V_139 -> V_141 == V_137 )
return V_139 ;
}
return NULL ;
}
int F_39 ( struct V_101 * V_24 , int V_112 )
{
struct V_144 * V_23 ;
struct V_145 * V_146 ;
struct V_110 * V_111 ;
struct V_115 * V_116 ;
int V_53 , V_147 , V_62 , V_14 ;
int V_148 = 0 , V_149 = 0 ;
struct V_7 * V_8 = NULL ;
int V_150 , V_67 , clock = 0 ;
struct V_151 * V_152 ;
unsigned int V_153 ;
V_23 = V_24 -> V_23 ;
V_146 = F_40 ( V_23 , V_112 ) ;
V_150 = V_146 -> V_154 ;
if ( V_24 -> V_155 == F_41 ( 0x04fa , 0x4201 ) )
V_150 = 4 ;
for ( V_53 = 0 ; V_53 < V_150 ; V_53 ++ ) {
V_111 = & V_146 -> V_156 [ V_53 ] ;
V_116 = F_33 ( V_111 ) ;
V_67 = V_116 -> V_157 ;
if ( ( V_116 -> V_158 != V_159 &&
V_116 -> V_158 != V_160 ) ||
( V_116 -> V_161 != V_162 &&
V_116 -> V_161 != V_163 ) ||
V_116 -> V_121 < 1 ||
F_42 ( F_43 ( V_111 , 0 ) -> V_164 ) == 0 )
continue;
if ( ( F_43 ( V_111 , 0 ) -> V_129 & V_165 ) !=
V_166 )
continue;
V_14 = ( F_43 ( V_111 , 0 ) -> V_167 & V_168 ) ?
V_169 : V_105 ;
V_147 = V_116 -> V_127 ;
if ( F_44 ( V_24 , V_112 , V_147 ) )
continue;
V_153 = 0 ;
switch ( V_67 ) {
default:
F_45 ( V_125 L_5 ,
V_23 -> V_126 , V_112 , V_147 , V_67 ) ;
V_67 = V_128 ;
case V_128 : {
struct V_170 * V_19 =
F_37 ( V_111 -> V_118 , V_111 -> V_119 , NULL , V_171 ) ;
struct V_172 * V_173 ;
if ( ! V_19 ) {
F_35 ( V_174 L_6 ,
V_23 -> V_126 , V_112 , V_147 ) ;
continue;
}
if ( V_19 -> V_122 < sizeof( * V_19 ) ) {
F_35 ( V_174 L_7 ,
V_23 -> V_126 , V_112 , V_147 ) ;
continue;
}
V_148 = F_42 ( V_19 -> V_175 ) ;
V_173 = F_36 ( V_24 -> V_176 ,
V_19 -> V_177 ) ;
if ( V_173 ) {
V_149 = V_173 -> V_178 ;
V_153 = F_42 ( V_173 -> V_179 ) ;
}
break;
}
case V_99 : {
struct V_138 * V_180 ;
struct V_142 * V_181 ;
struct V_182 * V_19 =
F_37 ( V_111 -> V_118 , V_111 -> V_119 , NULL , V_171 ) ;
if ( ! V_19 ) {
F_35 ( V_174 L_6 ,
V_23 -> V_126 , V_112 , V_147 ) ;
continue;
}
if ( V_19 -> V_122 < sizeof( * V_19 ) ) {
F_35 ( V_174 L_7 ,
V_23 -> V_126 , V_112 , V_147 ) ;
continue;
}
V_149 = V_19 -> V_178 ;
V_148 = F_46 ( V_19 -> V_183 ) ;
V_180 = F_36 ( V_24 -> V_176 ,
V_19 -> V_177 ) ;
if ( V_180 ) {
clock = V_180 -> V_184 ;
V_153 = F_46 ( V_180 -> V_185 ) ;
break;
}
V_181 = F_38 ( V_24 -> V_176 ,
V_19 -> V_177 ) ;
if ( V_181 ) {
clock = V_181 -> V_184 ;
break;
}
F_35 ( V_174 L_8 ,
V_23 -> V_126 , V_112 , V_147 , V_19 -> V_177 ) ;
continue;
}
}
V_152 = F_37 ( V_111 -> V_118 , V_111 -> V_119 , NULL , V_186 ) ;
if ( ! V_152 ) {
F_35 ( V_174 L_9 ,
V_23 -> V_126 , V_112 , V_147 ) ;
continue;
}
if ( ( ( V_67 == V_128 ) && ( V_152 -> V_122 < 8 ) ) ||
( ( V_67 == V_99 ) && ( V_152 -> V_122 < 6 ) ) ) {
F_35 ( V_174 L_10 ,
V_23 -> V_126 , V_112 , V_147 ) ;
continue;
}
if ( V_152 -> V_178 == 1 &&
V_152 -> V_187 == 2 &&
V_147 == 2 && V_150 == 3 &&
V_8 && V_8 -> V_156 == 1 && V_8 -> V_31 == 1 &&
V_8 -> V_27 == V_188 &&
V_67 == V_128 &&
F_42 ( F_43 ( V_111 , 0 ) -> V_164 ) ==
V_8 -> V_189 * 2 )
continue;
V_8 = F_25 ( sizeof( * V_8 ) , V_98 ) ;
if ( ! V_8 ) {
F_35 ( V_174 L_11 ) ;
return - V_50 ;
}
V_8 -> V_146 = V_112 ;
V_8 -> V_156 = V_147 ;
V_8 -> V_190 = V_53 ;
V_8 -> V_30 = F_43 ( V_111 , 0 ) -> V_167 ;
V_8 -> V_191 = F_43 ( V_111 , 0 ) -> V_129 ;
V_8 -> V_192 = F_47 ( V_24 , V_111 ) ;
V_8 -> V_189 = F_42 ( F_43 ( V_111 , 0 ) -> V_164 ) ;
V_8 -> V_31 = V_149 ;
if ( F_11 ( V_23 ) == V_193 )
V_8 -> V_189 = ( ( ( V_8 -> V_189 >> 11 ) & 3 ) + 1 )
* ( V_8 -> V_189 & 0x7ff ) ;
V_8 -> V_117 = F_32 ( V_24 , V_111 , V_67 , V_112 ) ;
V_8 -> clock = clock ;
V_8 -> V_11 = F_23 ( V_149 , V_153 , V_67 ) ;
switch ( V_24 -> V_155 ) {
case F_41 ( 0x0a92 , 0x0053 ) :
V_8 -> V_117 &= ~ V_194 ;
break;
case F_41 ( 0x041e , 0x3020 ) :
case F_41 ( 0x0763 , 0x2003 ) :
V_8 -> V_117 |= V_194 ;
break;
case F_41 ( 0x0763 , 0x2001 ) :
case F_41 ( 0x0763 , 0x2012 ) :
case F_41 ( 0x047f , 0x0ca1 ) :
case F_41 ( 0x077d , 0x07af ) :
V_8 -> V_191 &= ~ V_195 ;
if ( V_14 == V_105 )
V_8 -> V_191 |= V_196 ;
else
V_8 -> V_191 |= V_197 ;
break;
}
if ( F_48 ( V_24 , V_8 , V_148 , V_152 , V_14 , V_111 ) < 0 ) {
F_4 ( V_8 -> V_10 ) ;
F_4 ( V_8 -> V_11 ) ;
F_4 ( V_8 ) ;
V_8 = NULL ;
continue;
}
F_45 ( V_198 L_12 , V_23 -> V_126 , V_112 , V_147 , V_8 -> V_30 ) ;
V_62 = F_26 ( V_24 , V_14 , V_8 ) ;
if ( V_62 < 0 ) {
F_4 ( V_8 -> V_10 ) ;
F_4 ( V_8 -> V_11 ) ;
F_4 ( V_8 ) ;
return V_62 ;
}
F_49 ( V_24 -> V_23 , V_112 , V_147 ) ;
F_50 ( V_24 , V_112 , V_111 , V_8 ) ;
F_51 ( V_24 , V_112 , V_111 , V_8 , V_8 -> V_199 ) ;
}
return 0 ;
}
