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
V_2 -> V_24 = F_10 ( V_2 -> V_21 ) ;
V_2 -> V_25 = 0 ;
F_11 ( V_17 -> V_15 , V_12 ) ;
F_12 ( & V_4 -> V_10 , & V_2 -> V_18 ) ;
V_2 -> V_26 |= V_4 -> V_26 ;
V_2 -> V_6 ++ ;
V_2 -> V_27 = V_4 -> V_27 ;
V_2 -> V_28 = V_4 -> V_29 ;
if ( V_4 -> V_30 > V_2 -> V_31 )
V_2 -> V_31 = V_4 -> V_30 ;
}
static int F_13 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_36 * V_37 = F_14 ( V_33 ) ;
struct V_1 * V_2 = V_37 -> V_16 ;
V_35 -> type = V_38 ;
V_35 -> V_39 = V_2 -> V_31 ;
V_35 -> V_40 . integer . V_41 = 0 ;
V_35 -> V_40 . integer . V_42 = V_43 ;
return 0 ;
}
static bool F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_44 * V_45 ;
for ( V_45 = V_4 -> V_10 . V_46 ; V_45 != & V_2 -> V_18 ; V_45 = V_45 -> V_46 ) {
struct V_3 * V_46 ;
V_46 = F_16 ( V_45 , struct V_3 , V_10 ) ;
if ( V_46 -> V_8 &&
! memcmp ( V_46 -> V_8 , V_4 -> V_8 , sizeof( * V_4 -> V_8 ) ) )
return true ;
}
return false ;
}
static int F_17 ( struct V_32 * V_33 , int V_47 ,
unsigned int V_48 , unsigned int T_1 * V_49 )
{
struct V_36 * V_37 = F_14 ( V_33 ) ;
struct V_1 * V_2 = V_37 -> V_16 ;
struct V_3 * V_4 ;
unsigned int T_1 * V_50 ;
int V_39 = 0 ;
if ( V_48 < 8 )
return - V_51 ;
if ( F_18 ( V_52 , V_49 ) )
return - V_53 ;
V_48 -= 8 ;
V_50 = V_49 + 2 ;
F_19 (fp, &subs->fmt_list, list) {
int V_54 , V_55 ;
if ( ! V_4 -> V_8 )
continue;
if ( F_15 ( V_2 , V_4 ) )
continue;
V_55 = V_4 -> V_8 -> V_30 * 4 ;
if ( V_48 < 8 + V_55 )
return - V_51 ;
if ( F_18 ( V_56 , V_50 ) ||
F_18 ( V_55 , V_50 + 1 ) )
return - V_53 ;
V_50 += 2 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_8 -> V_30 ; V_54 ++ , V_50 ++ ) {
if ( F_18 ( V_4 -> V_8 -> V_57 [ V_54 ] , V_50 ) )
return - V_53 ;
}
V_39 += 8 + V_55 ;
V_48 -= 8 + V_55 ;
}
if ( F_18 ( V_39 , V_49 + 1 ) )
return - V_53 ;
return 0 ;
}
static int F_20 ( struct V_32 * V_33 ,
struct V_58 * V_59 )
{
struct V_36 * V_37 = F_14 ( V_33 ) ;
struct V_1 * V_2 = V_37 -> V_16 ;
struct V_60 * V_8 = NULL ;
int V_54 ;
memset ( V_59 -> V_40 . integer . V_40 , 0 ,
sizeof( V_59 -> V_40 . integer . V_40 ) ) ;
if ( V_2 -> V_61 )
V_8 = V_2 -> V_61 -> V_8 ;
if ( V_8 ) {
for ( V_54 = 0 ; V_54 < V_8 -> V_30 ; V_54 ++ )
V_59 -> V_40 . integer . V_40 [ V_54 ] = V_8 -> V_57 [ V_54 ] ;
}
return 0 ;
}
static int F_21 ( struct V_14 * V_15 , int V_12 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_36 * V_8 ;
struct V_32 * V_62 ;
int V_63 ;
F_19 (fp, &subs->fmt_list, list)
if ( V_4 -> V_8 )
goto V_64;
return 0 ;
V_64:
V_63 = F_22 ( V_15 , V_12 , NULL , 0 , 0 , & V_8 ) ;
if ( V_63 < 0 )
return V_63 ;
V_8 -> V_16 = V_2 ;
V_62 = V_8 -> V_62 ;
V_62 -> V_37 = F_13 ;
V_62 -> V_65 = F_20 ;
V_62 -> V_49 . V_66 = F_17 ;
return 0 ;
}
static struct V_60 * F_23 ( int V_30 , unsigned int V_67 ,
int V_68 )
{
static unsigned int V_69 [] = {
V_70 ,
V_71 ,
V_72 ,
V_73 ,
V_74 ,
V_75 ,
V_76 ,
V_77 ,
V_78 ,
V_74 ,
V_75 ,
V_79 ,
0
} ;
static unsigned int V_80 [] = {
V_70 ,
V_71 ,
V_72 ,
V_73 ,
V_81 ,
V_82 ,
V_76 ,
V_77 ,
V_78 ,
V_74 ,
V_75 ,
V_79 ,
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
V_97 ,
0
} ;
struct V_60 * V_8 ;
const unsigned int * V_98 ;
int V_66 ;
if ( V_30 > F_24 ( V_8 -> V_57 ) )
return NULL ;
V_8 = F_25 ( sizeof( * V_8 ) , V_99 ) ;
if ( ! V_8 )
return NULL ;
V_98 = V_68 == V_100 ? V_80 : V_69 ;
V_8 -> V_30 = V_30 ;
V_66 = 0 ;
if ( V_67 ) {
for (; V_67 && * V_98 ; V_98 ++ , V_67 >>= 1 )
if ( V_67 & 1 )
V_8 -> V_57 [ V_66 ++ ] = * V_98 ;
} else {
if ( V_30 == 1 )
V_8 -> V_57 [ V_66 ++ ] = V_101 ;
else
for (; V_66 < V_30 && * V_98 ; V_98 ++ )
V_8 -> V_57 [ V_66 ++ ] = * V_98 ;
}
for (; V_66 < V_30 ; V_66 ++ )
V_8 -> V_57 [ V_66 ] = V_102 ;
return V_8 ;
}
int F_26 ( struct V_103 * V_22 ,
int V_12 ,
struct V_3 * V_4 )
{
struct V_11 * V_17 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_63 ;
F_19 (as, &chip->pcm_list, list) {
if ( V_17 -> V_27 != V_4 -> V_27 )
continue;
V_2 = & V_17 -> V_13 [ V_12 ] ;
if ( V_2 -> V_28 == V_4 -> V_29 ) {
F_12 ( & V_4 -> V_10 , & V_2 -> V_18 ) ;
V_2 -> V_6 ++ ;
V_2 -> V_26 |= V_4 -> V_26 ;
return 0 ;
}
}
F_19 (as, &chip->pcm_list, list) {
if ( V_17 -> V_27 != V_4 -> V_27 )
continue;
V_2 = & V_17 -> V_13 [ V_12 ] ;
if ( V_2 -> V_28 )
continue;
V_63 = F_27 ( V_17 -> V_15 , V_12 , 1 ) ;
if ( V_63 < 0 )
return V_63 ;
F_7 ( V_17 , V_12 , V_4 ) ;
return F_21 ( V_17 -> V_15 , V_12 , V_2 ) ;
}
V_17 = F_25 ( sizeof( * V_17 ) , V_99 ) ;
if ( ! V_17 )
return - V_51 ;
V_17 -> V_104 = V_22 -> V_105 ;
V_17 -> V_22 = V_22 ;
V_17 -> V_27 = V_4 -> V_27 ;
V_63 = F_28 ( V_22 -> V_106 , L_1 , V_22 -> V_105 ,
V_12 == V_107 ? 1 : 0 ,
V_12 == V_107 ? 0 : 1 ,
& V_15 ) ;
if ( V_63 < 0 ) {
F_3 ( V_17 ) ;
return V_63 ;
}
V_17 -> V_15 = V_15 ;
V_15 -> V_16 = V_17 ;
V_15 -> V_108 = F_6 ;
V_15 -> V_109 = 0 ;
if ( V_22 -> V_105 > 0 )
sprintf ( V_15 -> V_110 , L_2 , V_22 -> V_105 ) ;
else
strcpy ( V_15 -> V_110 , L_1 ) ;
F_7 ( V_17 , V_12 , V_4 ) ;
F_29 ( & V_17 -> V_10 , & V_22 -> V_111 ) ;
V_22 -> V_105 ++ ;
F_30 ( V_17 ) ;
return F_21 ( V_15 , V_12 , & V_17 -> V_13 [ V_12 ] ) ;
}
static int F_31 ( struct V_103 * V_22 ,
struct V_112 * V_113 ,
int V_68 , int V_114 )
{
struct V_115 * V_116 ;
struct V_117 * V_118 = F_32 ( V_113 ) ;
int V_119 = 0 ;
V_116 = F_33 ( V_113 -> V_29 [ 0 ] . V_120 , V_113 -> V_29 [ 0 ] . V_121 , NULL , V_122 ) ;
if ( ! V_116 && V_118 -> V_123 >= 2 )
V_116 = F_33 ( V_113 -> V_29 [ 1 ] . V_120 , V_113 -> V_29 [ 1 ] . V_121 , NULL , V_122 ) ;
if ( ! V_116 )
V_116 = F_33 ( V_113 -> V_120 , V_113 -> V_121 , NULL , V_122 ) ;
if ( ! V_116 || V_116 -> V_124 < 7 ||
V_116 -> V_125 != V_126 ) {
F_34 ( V_22 ,
L_3 ,
V_114 , V_118 -> V_127 ) ;
return 0 ;
}
if ( V_68 == V_128 ) {
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
F_35 ( struct V_112 * V_136 ,
int V_137 )
{
struct V_138 * V_139 = NULL ;
while ( ( V_139 = F_36 ( V_136 -> V_120 ,
V_136 -> V_121 ,
V_139 , V_140 ) ) ) {
if ( V_139 -> V_141 == V_137 )
return V_139 ;
}
return NULL ;
}
static struct V_142 *
F_37 ( struct V_112 * V_136 ,
int V_137 )
{
struct V_142 * V_139 = NULL ;
while ( ( V_139 = F_36 ( V_136 -> V_120 ,
V_136 -> V_121 ,
V_139 , V_143 ) ) ) {
if ( V_139 -> V_141 == V_137 )
return V_139 ;
}
return NULL ;
}
int F_38 ( struct V_103 * V_22 , int V_114 )
{
struct V_144 * V_21 ;
struct V_145 * V_146 ;
struct V_112 * V_113 ;
struct V_117 * V_118 ;
int V_54 , V_147 , V_63 , V_12 ;
unsigned int V_148 = 0 , V_149 = 0 ;
struct V_3 * V_4 = NULL ;
int V_150 , V_68 , clock = 0 ;
struct V_151 * V_152 ;
unsigned int V_153 ;
V_21 = V_22 -> V_21 ;
V_146 = F_39 ( V_21 , V_114 ) ;
V_150 = V_146 -> V_154 ;
if ( V_22 -> V_155 == F_40 ( 0x04fa , 0x4201 ) )
V_150 = 4 ;
for ( V_54 = 0 ; V_54 < V_150 ; V_54 ++ ) {
V_113 = & V_146 -> V_156 [ V_54 ] ;
V_118 = F_32 ( V_113 ) ;
V_68 = V_118 -> V_157 ;
if ( ( ( V_118 -> V_158 != V_159 ||
( V_118 -> V_160 != V_161 &&
V_118 -> V_160 != V_162 ) ) &&
V_118 -> V_158 != V_163 ) ||
V_118 -> V_123 < 1 ||
F_41 ( F_42 ( V_113 , 0 ) -> V_164 ) == 0 )
continue;
if ( ( F_42 ( V_113 , 0 ) -> V_129 & V_165 ) !=
V_166 )
continue;
V_12 = ( F_42 ( V_113 , 0 ) -> V_167 & V_168 ) ?
V_169 : V_107 ;
V_147 = V_118 -> V_127 ;
if ( F_43 ( V_22 , V_114 , V_147 ) )
continue;
if ( F_44 ( V_22 -> V_155 ) == 0x0582 &&
V_118 -> V_158 == V_163 &&
V_68 <= 2 )
V_68 = V_128 ;
V_153 = 0 ;
switch ( V_68 ) {
default:
F_45 ( & V_21 -> V_21 , L_4 ,
V_114 , V_147 , V_68 ) ;
V_68 = V_128 ;
case V_128 : {
struct V_170 * V_17 =
F_36 ( V_113 -> V_120 , V_113 -> V_121 , NULL , V_171 ) ;
struct V_172 * V_173 ;
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
V_148 = F_41 ( V_17 -> V_174 ) ;
V_173 = F_35 ( V_22 -> V_175 ,
V_17 -> V_176 ) ;
if ( V_173 ) {
V_149 = V_173 -> V_177 ;
V_153 = F_41 ( V_173 -> V_178 ) ;
}
break;
}
case V_100 : {
struct V_138 * V_179 ;
struct V_142 * V_180 ;
struct V_181 * V_17 =
F_36 ( V_113 -> V_120 , V_113 -> V_121 , NULL , V_171 ) ;
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
V_149 = V_17 -> V_177 ;
V_148 = F_47 ( V_17 -> V_182 ) ;
V_153 = F_47 ( V_17 -> V_183 ) ;
V_179 = F_35 ( V_22 -> V_175 ,
V_17 -> V_176 ) ;
if ( V_179 ) {
clock = V_179 -> V_184 ;
if ( ! V_153 && ( V_149 == V_179 -> V_177 ) )
V_153 = F_47 ( V_179 -> V_183 ) ;
break;
}
V_180 = F_37 ( V_22 -> V_175 ,
V_17 -> V_176 ) ;
if ( V_180 ) {
clock = V_180 -> V_184 ;
break;
}
F_46 ( & V_21 -> V_21 ,
L_7 ,
V_114 , V_147 , V_17 -> V_176 ) ;
continue;
}
}
V_152 = F_36 ( V_113 -> V_120 , V_113 -> V_121 , NULL , V_185 ) ;
if ( ! V_152 ) {
F_46 ( & V_21 -> V_21 ,
L_8 ,
V_114 , V_147 ) ;
continue;
}
if ( ( ( V_68 == V_128 ) && ( V_152 -> V_124 < 8 ) ) ||
( ( V_68 == V_100 ) && ( V_152 -> V_124 < 6 ) ) ) {
F_46 ( & V_21 -> V_21 ,
L_9 ,
V_114 , V_147 ) ;
continue;
}
if ( V_152 -> V_177 == 1 &&
V_152 -> V_186 == 2 &&
V_147 == 2 && V_150 == 3 &&
V_4 && V_4 -> V_156 == 1 && V_4 -> V_30 == 1 &&
V_4 -> V_26 == V_187 &&
V_68 == V_128 &&
F_41 ( F_42 ( V_113 , 0 ) -> V_164 ) ==
V_4 -> V_188 * 2 )
continue;
V_4 = F_25 ( sizeof( * V_4 ) , V_99 ) ;
if ( ! V_4 ) {
F_46 ( & V_21 -> V_21 , L_10 ) ;
return - V_51 ;
}
V_4 -> V_146 = V_114 ;
V_4 -> V_156 = V_147 ;
V_4 -> V_189 = V_54 ;
V_4 -> V_29 = F_42 ( V_113 , 0 ) -> V_167 ;
V_4 -> V_190 = F_42 ( V_113 , 0 ) -> V_129 ;
V_4 -> V_191 = F_48 ( V_22 , V_113 ) ;
V_4 -> V_68 = V_68 ;
V_4 -> V_188 = F_41 ( F_42 ( V_113 , 0 ) -> V_164 ) ;
V_4 -> V_30 = V_149 ;
if ( F_10 ( V_21 ) == V_192 )
V_4 -> V_188 = ( ( ( V_4 -> V_188 >> 11 ) & 3 ) + 1 )
* ( V_4 -> V_188 & 0x7ff ) ;
V_4 -> V_119 = F_31 ( V_22 , V_113 , V_68 , V_114 ) ;
V_4 -> clock = clock ;
switch ( V_22 -> V_155 ) {
case F_40 ( 0x0a92 , 0x0053 ) :
V_4 -> V_119 &= ~ V_193 ;
break;
case F_40 ( 0x041e , 0x3020 ) :
case F_40 ( 0x0763 , 0x2003 ) :
V_4 -> V_119 |= V_193 ;
break;
case F_40 ( 0x0763 , 0x2001 ) :
case F_40 ( 0x0763 , 0x2012 ) :
case F_40 ( 0x047f , 0x0ca1 ) :
case F_40 ( 0x077d , 0x07af ) :
V_4 -> V_190 &= ~ V_194 ;
if ( V_12 == V_107 )
V_4 -> V_190 |= V_195 ;
else
V_4 -> V_190 |= V_196 ;
break;
}
if ( F_49 ( V_22 , V_4 , V_148 , V_152 , V_12 ) < 0 ) {
F_3 ( V_4 -> V_7 ) ;
F_3 ( V_4 ) ;
V_4 = NULL ;
continue;
}
if ( V_4 -> V_30 != V_149 )
V_153 = 0 ;
V_4 -> V_8 = F_23 ( V_4 -> V_30 , V_153 , V_68 ) ;
F_45 ( & V_21 -> V_21 , L_11 , V_114 , V_147 , V_4 -> V_29 ) ;
V_63 = F_26 ( V_22 , V_12 , V_4 ) ;
if ( V_63 < 0 ) {
F_3 ( V_4 -> V_7 ) ;
F_3 ( V_4 -> V_8 ) ;
F_3 ( V_4 ) ;
return V_63 ;
}
F_50 ( V_22 -> V_21 , V_114 , V_147 ) ;
F_51 ( V_22 , V_114 , V_113 , V_4 ) ;
F_52 ( V_22 , V_114 , V_113 , V_4 , V_4 -> V_197 ) ;
}
return 0 ;
}
