static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
if ( ! V_2 -> V_6 )
return;
F_2 (fp, n, &subs->fmt_list, list) {
F_3 ( V_4 -> V_7 ) ;
F_3 ( V_4 -> V_8 ) ;
F_3 ( V_4 ) ;
}
F_3 ( V_2 -> V_9 . V_10 ) ;
}
static void F_4 ( struct V_11 * V_12 )
{
F_1 ( & V_12 -> V_13 [ 0 ] ) ;
F_1 ( & V_12 -> V_13 [ 1 ] ) ;
F_5 ( & V_12 -> V_10 ) ;
F_3 ( V_12 ) ;
}
static void F_6 ( struct V_14 * V_15 )
{
struct V_11 * V_12 = V_15 -> V_16 ;
if ( V_12 ) {
V_12 -> V_15 = NULL ;
F_4 ( V_12 ) ;
}
}
static void F_7 ( struct V_11 * V_17 ,
int V_12 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_17 -> V_13 [ V_12 ] ;
F_8 ( & V_2 -> V_18 ) ;
F_9 ( & V_2 -> V_19 ) ;
V_2 -> V_12 = V_17 ;
V_2 -> V_20 = V_12 ;
V_2 -> V_21 = V_17 -> V_22 -> V_21 ;
V_2 -> V_23 = V_17 -> V_22 -> V_23 ;
V_2 -> V_24 = V_17 -> V_22 -> V_24 ;
V_2 -> V_25 = F_10 ( V_2 -> V_21 ) ;
V_2 -> V_26 = 0 ;
F_11 ( V_17 -> V_15 , V_12 ) ;
F_12 ( & V_4 -> V_10 , & V_2 -> V_18 ) ;
V_2 -> V_27 |= V_4 -> V_27 ;
V_2 -> V_6 ++ ;
V_2 -> V_28 = V_4 -> V_28 ;
V_2 -> V_29 = V_4 -> V_30 ;
if ( V_4 -> V_31 > V_2 -> V_32 )
V_2 -> V_32 = V_4 -> V_31 ;
}
static int F_13 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 = F_14 ( V_34 ) ;
struct V_1 * V_2 = V_38 -> V_16 ;
V_36 -> type = V_39 ;
V_36 -> V_40 = V_2 -> V_32 ;
V_36 -> V_41 . integer . V_42 = 0 ;
V_36 -> V_41 . integer . V_43 = V_44 ;
return 0 ;
}
static bool F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_45 = V_4 ;
F_16 (prev, &subs->fmt_list, list) {
if ( V_45 -> V_8 &&
! memcmp ( V_45 -> V_8 , V_4 -> V_8 , sizeof( * V_4 -> V_8 ) ) )
return true ;
}
return false ;
}
static int F_17 ( struct V_33 * V_34 , int V_46 ,
unsigned int V_47 , unsigned int T_1 * V_48 )
{
struct V_37 * V_38 = F_14 ( V_34 ) ;
struct V_1 * V_2 = V_38 -> V_16 ;
struct V_3 * V_4 ;
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
if ( ! V_4 -> V_8 )
continue;
if ( F_15 ( V_2 , V_4 ) )
continue;
V_54 = V_4 -> V_8 -> V_31 * 4 ;
if ( V_47 < 8 + V_54 )
return - V_50 ;
if ( F_18 ( V_55 , V_49 ) ||
F_18 ( V_54 , V_49 + 1 ) )
return - V_52 ;
V_49 += 2 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_8 -> V_31 ; V_53 ++ , V_49 ++ ) {
if ( F_18 ( V_4 -> V_8 -> V_56 [ V_53 ] , V_49 ) )
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
struct V_37 * V_38 = F_14 ( V_34 ) ;
struct V_1 * V_2 = V_38 -> V_16 ;
struct V_59 * V_8 = NULL ;
int V_53 ;
memset ( V_58 -> V_41 . integer . V_41 , 0 ,
sizeof( V_58 -> V_41 . integer . V_41 ) ) ;
if ( V_2 -> V_60 )
V_8 = V_2 -> V_60 -> V_8 ;
if ( V_8 ) {
for ( V_53 = 0 ; V_53 < V_8 -> V_31 ; V_53 ++ )
V_58 -> V_41 . integer . V_41 [ V_53 ] = V_8 -> V_56 [ V_53 ] ;
}
return 0 ;
}
static int F_21 ( struct V_14 * V_15 , int V_12 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_37 * V_8 ;
struct V_33 * V_61 ;
int V_62 ;
F_19 (fp, &subs->fmt_list, list)
if ( V_4 -> V_8 )
goto V_63;
return 0 ;
V_63:
V_62 = F_22 ( V_15 , V_12 , NULL , 0 , 0 , & V_8 ) ;
if ( V_62 < 0 )
return V_62 ;
V_8 -> V_16 = V_2 ;
V_61 = V_8 -> V_61 ;
V_61 -> V_38 = F_13 ;
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
struct V_59 * V_8 ;
const unsigned int * V_97 ;
int V_65 ;
if ( V_31 > F_24 ( V_8 -> V_56 ) )
return NULL ;
V_8 = F_25 ( sizeof( * V_8 ) , V_98 ) ;
if ( ! V_8 )
return NULL ;
V_97 = V_67 == V_99 ? V_79 : V_68 ;
V_8 -> V_31 = V_31 ;
V_65 = 0 ;
if ( V_66 ) {
for (; V_66 && * V_97 ; V_97 ++ , V_66 >>= 1 )
if ( V_66 & 1 )
V_8 -> V_56 [ V_65 ++ ] = * V_97 ;
} else {
if ( V_31 == 1 )
V_8 -> V_56 [ V_65 ++ ] = V_100 ;
else
for (; V_65 < V_31 && * V_97 ; V_97 ++ )
V_8 -> V_56 [ V_65 ++ ] = * V_97 ;
}
for (; V_65 < V_31 ; V_65 ++ )
V_8 -> V_56 [ V_65 ] = V_101 ;
return V_8 ;
}
int F_26 ( struct V_102 * V_22 ,
int V_12 ,
struct V_3 * V_4 )
{
struct V_11 * V_17 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_62 ;
F_19 (as, &chip->pcm_list, list) {
if ( V_17 -> V_28 != V_4 -> V_28 )
continue;
V_2 = & V_17 -> V_13 [ V_12 ] ;
if ( V_2 -> V_29 == V_4 -> V_30 ) {
F_12 ( & V_4 -> V_10 , & V_2 -> V_18 ) ;
V_2 -> V_6 ++ ;
V_2 -> V_27 |= V_4 -> V_27 ;
return 0 ;
}
}
F_19 (as, &chip->pcm_list, list) {
if ( V_17 -> V_28 != V_4 -> V_28 )
continue;
V_2 = & V_17 -> V_13 [ V_12 ] ;
if ( V_2 -> V_29 )
continue;
V_62 = F_27 ( V_17 -> V_15 , V_12 , 1 ) ;
if ( V_62 < 0 )
return V_62 ;
F_7 ( V_17 , V_12 , V_4 ) ;
return F_21 ( V_17 -> V_15 , V_12 , V_2 ) ;
}
V_17 = F_25 ( sizeof( * V_17 ) , V_98 ) ;
if ( ! V_17 )
return - V_50 ;
V_17 -> V_103 = V_22 -> V_104 ;
V_17 -> V_22 = V_22 ;
V_17 -> V_28 = V_4 -> V_28 ;
V_62 = F_28 ( V_22 -> V_105 , L_1 , V_22 -> V_104 ,
V_12 == V_106 ? 1 : 0 ,
V_12 == V_106 ? 0 : 1 ,
& V_15 ) ;
if ( V_62 < 0 ) {
F_3 ( V_17 ) ;
return V_62 ;
}
V_17 -> V_15 = V_15 ;
V_15 -> V_16 = V_17 ;
V_15 -> V_107 = F_6 ;
V_15 -> V_108 = 0 ;
if ( V_22 -> V_104 > 0 )
sprintf ( V_15 -> V_109 , L_2 , V_22 -> V_104 ) ;
else
strcpy ( V_15 -> V_109 , L_1 ) ;
F_7 ( V_17 , V_12 , V_4 ) ;
if ( V_22 -> V_110 == F_29 ( 0x0763 , 0x2003 ) )
F_30 ( & V_17 -> V_10 , & V_22 -> V_111 ) ;
else
F_12 ( & V_17 -> V_10 , & V_22 -> V_111 ) ;
V_22 -> V_104 ++ ;
F_31 ( V_17 ) ;
return F_21 ( V_15 , V_12 , & V_17 -> V_13 [ V_12 ] ) ;
}
static int F_32 ( struct V_102 * V_22 ,
struct V_112 * V_113 ,
int V_67 , int V_114 )
{
struct V_115 * V_116 ;
struct V_117 * V_118 = F_33 ( V_113 ) ;
int V_119 = 0 ;
V_116 = F_34 ( V_113 -> V_30 [ 0 ] . V_120 , V_113 -> V_30 [ 0 ] . V_121 , NULL , V_122 ) ;
if ( ! V_116 && V_118 -> V_123 >= 2 )
V_116 = F_34 ( V_113 -> V_30 [ 1 ] . V_120 , V_113 -> V_30 [ 1 ] . V_121 , NULL , V_122 ) ;
if ( ! V_116 )
V_116 = F_34 ( V_113 -> V_120 , V_113 -> V_121 , NULL , V_122 ) ;
if ( ! V_116 || V_116 -> V_124 < 7 ||
V_116 -> V_125 != V_126 ) {
F_35 ( V_22 ,
L_3 ,
V_114 , V_118 -> V_127 ) ;
return 0 ;
}
if ( V_67 == V_128 ) {
V_119 = V_116 -> V_129 ;
} else {
struct V_130 * V_131 =
(struct V_130 * ) V_116 ;
V_119 = V_116 -> V_129 & V_132 ;
if ( V_131 -> V_133 & V_134 )
V_119 |= V_135 ;
}
return V_119 ;
}
static void *
F_36 ( struct V_112 * V_136 ,
int V_137 )
{
struct V_138 * V_139 = NULL ;
while ( ( V_139 = F_37 ( V_136 -> V_120 ,
V_136 -> V_121 ,
V_139 , V_140 ) ) ) {
if ( V_139 -> V_141 == V_137 )
return V_139 ;
}
return NULL ;
}
static struct V_142 *
F_38 ( struct V_112 * V_136 ,
int V_137 )
{
struct V_142 * V_139 = NULL ;
while ( ( V_139 = F_37 ( V_136 -> V_120 ,
V_136 -> V_121 ,
V_139 , V_143 ) ) ) {
if ( V_139 -> V_141 == V_137 )
return V_139 ;
}
return NULL ;
}
int F_39 ( struct V_102 * V_22 , int V_114 )
{
struct V_144 * V_21 ;
struct V_145 * V_146 ;
struct V_112 * V_113 ;
struct V_117 * V_118 ;
int V_53 , V_147 , V_62 , V_12 ;
unsigned int V_148 = 0 , V_149 = 0 ;
struct V_3 * V_4 = NULL ;
int V_150 , V_67 , clock = 0 ;
struct V_151 * V_152 ;
unsigned int V_153 ;
V_21 = V_22 -> V_21 ;
V_146 = F_40 ( V_21 , V_114 ) ;
V_150 = V_146 -> V_154 ;
if ( V_22 -> V_110 == F_29 ( 0x04fa , 0x4201 ) )
V_150 = 4 ;
for ( V_53 = 0 ; V_53 < V_150 ; V_53 ++ ) {
V_113 = & V_146 -> V_155 [ V_53 ] ;
V_118 = F_33 ( V_113 ) ;
V_67 = V_118 -> V_156 ;
if ( ( ( V_118 -> V_157 != V_158 ||
( V_118 -> V_159 != V_160 &&
V_118 -> V_159 != V_161 ) ) &&
V_118 -> V_157 != V_162 ) ||
V_118 -> V_123 < 1 ||
F_41 ( F_42 ( V_113 , 0 ) -> V_163 ) == 0 )
continue;
if ( ( F_42 ( V_113 , 0 ) -> V_129 & V_164 ) !=
V_165 )
continue;
V_12 = ( F_42 ( V_113 , 0 ) -> V_166 & V_167 ) ?
V_168 : V_106 ;
V_147 = V_118 -> V_127 ;
if ( F_43 ( V_22 , V_114 , V_147 ) )
continue;
if ( F_44 ( V_22 -> V_110 ) == 0x0582 &&
V_118 -> V_157 == V_162 &&
V_67 <= 2 )
V_67 = V_128 ;
V_153 = 0 ;
switch ( V_67 ) {
default:
F_45 ( & V_21 -> V_21 , L_4 ,
V_114 , V_147 , V_67 ) ;
V_67 = V_128 ;
case V_128 : {
struct V_169 * V_17 =
F_37 ( V_113 -> V_120 , V_113 -> V_121 , NULL , V_170 ) ;
struct V_171 * V_172 ;
if ( ! V_17 ) {
F_46 ( & V_21 -> V_21 ,
L_5 ,
V_114 , V_147 ) ;
continue;
}
if ( V_17 -> V_124 < sizeof( * V_17 ) ) {
F_46 ( & V_21 -> V_21 ,
L_6 ,
V_114 , V_147 ) ;
continue;
}
V_148 = F_41 ( V_17 -> V_173 ) ;
V_172 = F_36 ( V_22 -> V_174 ,
V_17 -> V_175 ) ;
if ( V_172 ) {
V_149 = V_172 -> V_176 ;
V_153 = F_41 ( V_172 -> V_177 ) ;
}
break;
}
case V_99 : {
struct V_138 * V_178 ;
struct V_142 * V_179 ;
struct V_180 * V_17 =
F_37 ( V_113 -> V_120 , V_113 -> V_121 , NULL , V_170 ) ;
if ( ! V_17 ) {
F_46 ( & V_21 -> V_21 ,
L_5 ,
V_114 , V_147 ) ;
continue;
}
if ( V_17 -> V_124 < sizeof( * V_17 ) ) {
F_46 ( & V_21 -> V_21 ,
L_6 ,
V_114 , V_147 ) ;
continue;
}
V_149 = V_17 -> V_176 ;
V_148 = F_47 ( V_17 -> V_181 ) ;
V_153 = F_47 ( V_17 -> V_182 ) ;
V_178 = F_36 ( V_22 -> V_174 ,
V_17 -> V_175 ) ;
if ( V_178 ) {
clock = V_178 -> V_183 ;
if ( ! V_153 && ( V_149 == V_178 -> V_176 ) )
V_153 = F_47 ( V_178 -> V_182 ) ;
break;
}
V_179 = F_38 ( V_22 -> V_174 ,
V_17 -> V_175 ) ;
if ( V_179 ) {
clock = V_179 -> V_183 ;
break;
}
F_46 ( & V_21 -> V_21 ,
L_7 ,
V_114 , V_147 , V_17 -> V_175 ) ;
continue;
}
}
V_152 = F_37 ( V_113 -> V_120 , V_113 -> V_121 , NULL , V_184 ) ;
if ( ! V_152 ) {
F_46 ( & V_21 -> V_21 ,
L_8 ,
V_114 , V_147 ) ;
continue;
}
if ( ( ( V_67 == V_128 ) && ( V_152 -> V_124 < 8 ) ) ||
( ( V_67 == V_99 ) && ( V_152 -> V_124 < 6 ) ) ) {
F_46 ( & V_21 -> V_21 ,
L_9 ,
V_114 , V_147 ) ;
continue;
}
if ( V_152 -> V_176 == 1 &&
V_152 -> V_185 == 2 &&
V_147 == 2 && V_150 == 3 &&
V_4 && V_4 -> V_155 == 1 && V_4 -> V_31 == 1 &&
V_4 -> V_27 == V_186 &&
V_67 == V_128 &&
F_41 ( F_42 ( V_113 , 0 ) -> V_163 ) ==
V_4 -> V_187 * 2 )
continue;
V_4 = F_25 ( sizeof( * V_4 ) , V_98 ) ;
if ( ! V_4 )
return - V_50 ;
V_4 -> V_146 = V_114 ;
V_4 -> V_155 = V_147 ;
V_4 -> V_188 = V_53 ;
V_4 -> V_30 = F_42 ( V_113 , 0 ) -> V_166 ;
V_4 -> V_189 = F_42 ( V_113 , 0 ) -> V_129 ;
V_4 -> V_190 = F_48 ( V_22 , V_113 ) ;
V_4 -> V_67 = V_67 ;
V_4 -> V_187 = F_41 ( F_42 ( V_113 , 0 ) -> V_163 ) ;
V_4 -> V_31 = V_149 ;
if ( F_10 ( V_21 ) == V_191 )
V_4 -> V_187 = ( ( ( V_4 -> V_187 >> 11 ) & 3 ) + 1 )
* ( V_4 -> V_187 & 0x7ff ) ;
V_4 -> V_119 = F_32 ( V_22 , V_113 , V_67 , V_114 ) ;
V_4 -> clock = clock ;
F_8 ( & V_4 -> V_10 ) ;
switch ( V_22 -> V_110 ) {
case F_29 ( 0x0a92 , 0x0053 ) :
V_4 -> V_119 &= ~ V_192 ;
break;
case F_29 ( 0x041e , 0x3020 ) :
case F_29 ( 0x0763 , 0x2003 ) :
V_4 -> V_119 |= V_192 ;
break;
case F_29 ( 0x0763 , 0x2001 ) :
case F_29 ( 0x0763 , 0x2012 ) :
case F_29 ( 0x047f , 0x0ca1 ) :
case F_29 ( 0x077d , 0x07af ) :
V_4 -> V_189 &= ~ V_193 ;
if ( V_12 == V_106 )
V_4 -> V_189 |= V_194 ;
else
V_4 -> V_189 |= V_195 ;
break;
}
if ( F_49 ( V_22 , V_4 , V_148 , V_152 , V_12 ) < 0 ) {
F_3 ( V_4 -> V_7 ) ;
F_3 ( V_4 ) ;
V_4 = NULL ;
continue;
}
if ( V_4 -> V_31 != V_149 )
V_153 = 0 ;
V_4 -> V_8 = F_23 ( V_4 -> V_31 , V_153 , V_67 ) ;
F_45 ( & V_21 -> V_21 , L_10 , V_114 , V_147 , V_4 -> V_30 ) ;
V_62 = F_26 ( V_22 , V_12 , V_4 ) ;
if ( V_62 < 0 ) {
F_5 ( & V_4 -> V_10 ) ;
F_3 ( V_4 -> V_7 ) ;
F_3 ( V_4 -> V_8 ) ;
F_3 ( V_4 ) ;
return V_62 ;
}
F_50 ( V_22 -> V_21 , V_114 , V_147 ) ;
F_51 ( V_22 , V_114 , V_113 , V_4 ) ;
F_52 ( V_22 , V_114 , V_113 , V_4 , V_4 -> V_196 ) ;
}
return 0 ;
}
