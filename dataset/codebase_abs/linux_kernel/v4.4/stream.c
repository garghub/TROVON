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
struct V_45 * V_46 ;
for ( V_46 = V_4 -> V_10 . V_47 ; V_46 != & V_2 -> V_18 ; V_46 = V_46 -> V_47 ) {
struct V_3 * V_47 ;
V_47 = F_16 ( V_46 , struct V_3 , V_10 ) ;
if ( V_47 -> V_8 &&
! memcmp ( V_47 -> V_8 , V_4 -> V_8 , sizeof( * V_4 -> V_8 ) ) )
return true ;
}
return false ;
}
static int F_17 ( struct V_33 * V_34 , int V_48 ,
unsigned int V_49 , unsigned int T_1 * V_50 )
{
struct V_37 * V_38 = F_14 ( V_34 ) ;
struct V_1 * V_2 = V_38 -> V_16 ;
struct V_3 * V_4 ;
unsigned int T_1 * V_51 ;
int V_40 = 0 ;
if ( V_49 < 8 )
return - V_52 ;
if ( F_18 ( V_53 , V_50 ) )
return - V_54 ;
V_49 -= 8 ;
V_51 = V_50 + 2 ;
F_19 (fp, &subs->fmt_list, list) {
int V_55 , V_56 ;
if ( ! V_4 -> V_8 )
continue;
if ( F_15 ( V_2 , V_4 ) )
continue;
V_56 = V_4 -> V_8 -> V_31 * 4 ;
if ( V_49 < 8 + V_56 )
return - V_52 ;
if ( F_18 ( V_57 , V_51 ) ||
F_18 ( V_56 , V_51 + 1 ) )
return - V_54 ;
V_51 += 2 ;
for ( V_55 = 0 ; V_55 < V_4 -> V_8 -> V_31 ; V_55 ++ , V_51 ++ ) {
if ( F_18 ( V_4 -> V_8 -> V_58 [ V_55 ] , V_51 ) )
return - V_54 ;
}
V_40 += 8 + V_56 ;
V_49 -= 8 + V_56 ;
}
if ( F_18 ( V_40 , V_50 + 1 ) )
return - V_54 ;
return 0 ;
}
static int F_20 ( struct V_33 * V_34 ,
struct V_59 * V_60 )
{
struct V_37 * V_38 = F_14 ( V_34 ) ;
struct V_1 * V_2 = V_38 -> V_16 ;
struct V_61 * V_8 = NULL ;
int V_55 ;
memset ( V_60 -> V_41 . integer . V_41 , 0 ,
sizeof( V_60 -> V_41 . integer . V_41 ) ) ;
if ( V_2 -> V_62 )
V_8 = V_2 -> V_62 -> V_8 ;
if ( V_8 ) {
for ( V_55 = 0 ; V_55 < V_8 -> V_31 ; V_55 ++ )
V_60 -> V_41 . integer . V_41 [ V_55 ] = V_8 -> V_58 [ V_55 ] ;
}
return 0 ;
}
static int F_21 ( struct V_14 * V_15 , int V_12 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_37 * V_8 ;
struct V_33 * V_63 ;
int V_64 ;
F_19 (fp, &subs->fmt_list, list)
if ( V_4 -> V_8 )
goto V_65;
return 0 ;
V_65:
V_64 = F_22 ( V_15 , V_12 , NULL , 0 , 0 , & V_8 ) ;
if ( V_64 < 0 )
return V_64 ;
V_8 -> V_16 = V_2 ;
V_63 = V_8 -> V_63 ;
V_63 -> V_38 = F_13 ;
V_63 -> V_66 = F_20 ;
V_63 -> V_50 . V_67 = F_17 ;
return 0 ;
}
static struct V_61 * F_23 ( int V_31 , unsigned int V_68 ,
int V_69 )
{
static unsigned int V_70 [] = {
V_71 ,
V_72 ,
V_73 ,
V_74 ,
V_75 ,
V_76 ,
V_77 ,
V_78 ,
V_79 ,
V_75 ,
V_76 ,
V_80 ,
0
} ;
static unsigned int V_81 [] = {
V_71 ,
V_72 ,
V_73 ,
V_74 ,
V_82 ,
V_83 ,
V_77 ,
V_78 ,
V_79 ,
V_75 ,
V_76 ,
V_80 ,
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
V_98 ,
0
} ;
struct V_61 * V_8 ;
const unsigned int * V_99 ;
int V_67 ;
if ( V_31 > F_24 ( V_8 -> V_58 ) )
return NULL ;
V_8 = F_25 ( sizeof( * V_8 ) , V_100 ) ;
if ( ! V_8 )
return NULL ;
V_99 = V_69 == V_101 ? V_81 : V_70 ;
V_8 -> V_31 = V_31 ;
V_67 = 0 ;
if ( V_68 ) {
for (; V_68 && * V_99 ; V_99 ++ , V_68 >>= 1 )
if ( V_68 & 1 )
V_8 -> V_58 [ V_67 ++ ] = * V_99 ;
} else {
if ( V_31 == 1 )
V_8 -> V_58 [ V_67 ++ ] = V_102 ;
else
for (; V_67 < V_31 && * V_99 ; V_99 ++ )
V_8 -> V_58 [ V_67 ++ ] = * V_99 ;
}
for (; V_67 < V_31 ; V_67 ++ )
V_8 -> V_58 [ V_67 ] = V_103 ;
return V_8 ;
}
int F_26 ( struct V_104 * V_22 ,
int V_12 ,
struct V_3 * V_4 )
{
struct V_11 * V_17 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_64 ;
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
V_64 = F_27 ( V_17 -> V_15 , V_12 , 1 ) ;
if ( V_64 < 0 )
return V_64 ;
F_7 ( V_17 , V_12 , V_4 ) ;
return F_21 ( V_17 -> V_15 , V_12 , V_2 ) ;
}
V_17 = F_25 ( sizeof( * V_17 ) , V_100 ) ;
if ( ! V_17 )
return - V_52 ;
V_17 -> V_105 = V_22 -> V_106 ;
V_17 -> V_22 = V_22 ;
V_17 -> V_28 = V_4 -> V_28 ;
V_64 = F_28 ( V_22 -> V_107 , L_1 , V_22 -> V_106 ,
V_12 == V_108 ? 1 : 0 ,
V_12 == V_108 ? 0 : 1 ,
& V_15 ) ;
if ( V_64 < 0 ) {
F_3 ( V_17 ) ;
return V_64 ;
}
V_17 -> V_15 = V_15 ;
V_15 -> V_16 = V_17 ;
V_15 -> V_109 = F_6 ;
V_15 -> V_110 = 0 ;
if ( V_22 -> V_106 > 0 )
sprintf ( V_15 -> V_111 , L_2 , V_22 -> V_106 ) ;
else
strcpy ( V_15 -> V_111 , L_1 ) ;
F_7 ( V_17 , V_12 , V_4 ) ;
if ( V_22 -> V_112 == F_29 ( 0x0763 , 0x2003 ) )
F_30 ( & V_17 -> V_10 , & V_22 -> V_113 ) ;
else
F_12 ( & V_17 -> V_10 , & V_22 -> V_113 ) ;
V_22 -> V_106 ++ ;
F_31 ( V_17 ) ;
return F_21 ( V_15 , V_12 , & V_17 -> V_13 [ V_12 ] ) ;
}
static int F_32 ( struct V_104 * V_22 ,
struct V_114 * V_115 ,
int V_69 , int V_116 )
{
struct V_117 * V_118 ;
struct V_119 * V_120 = F_33 ( V_115 ) ;
int V_121 = 0 ;
V_118 = F_34 ( V_115 -> V_30 [ 0 ] . V_122 , V_115 -> V_30 [ 0 ] . V_123 , NULL , V_124 ) ;
if ( ! V_118 && V_120 -> V_125 >= 2 )
V_118 = F_34 ( V_115 -> V_30 [ 1 ] . V_122 , V_115 -> V_30 [ 1 ] . V_123 , NULL , V_124 ) ;
if ( ! V_118 )
V_118 = F_34 ( V_115 -> V_122 , V_115 -> V_123 , NULL , V_124 ) ;
if ( ! V_118 || V_118 -> V_126 < 7 ||
V_118 -> V_127 != V_128 ) {
F_35 ( V_22 ,
L_3 ,
V_116 , V_120 -> V_129 ) ;
return 0 ;
}
if ( V_69 == V_130 ) {
V_121 = V_118 -> V_131 ;
} else {
struct V_132 * V_133 =
(struct V_132 * ) V_118 ;
V_121 = V_118 -> V_131 & V_134 ;
if ( V_133 -> V_135 & V_136 )
V_121 |= V_137 ;
}
return V_121 ;
}
static void *
F_36 ( struct V_114 * V_138 ,
int V_139 )
{
struct V_140 * V_141 = NULL ;
while ( ( V_141 = F_37 ( V_138 -> V_122 ,
V_138 -> V_123 ,
V_141 , V_142 ) ) ) {
if ( V_141 -> V_143 == V_139 )
return V_141 ;
}
return NULL ;
}
static struct V_144 *
F_38 ( struct V_114 * V_138 ,
int V_139 )
{
struct V_144 * V_141 = NULL ;
while ( ( V_141 = F_37 ( V_138 -> V_122 ,
V_138 -> V_123 ,
V_141 , V_145 ) ) ) {
if ( V_141 -> V_143 == V_139 )
return V_141 ;
}
return NULL ;
}
int F_39 ( struct V_104 * V_22 , int V_116 )
{
struct V_146 * V_21 ;
struct V_147 * V_148 ;
struct V_114 * V_115 ;
struct V_119 * V_120 ;
int V_55 , V_149 , V_64 , V_12 ;
unsigned int V_150 = 0 , V_151 = 0 ;
struct V_3 * V_4 = NULL ;
int V_152 , V_69 , clock = 0 ;
struct V_153 * V_154 ;
unsigned int V_155 ;
V_21 = V_22 -> V_21 ;
V_148 = F_40 ( V_21 , V_116 ) ;
V_152 = V_148 -> V_156 ;
if ( V_22 -> V_112 == F_29 ( 0x04fa , 0x4201 ) )
V_152 = 4 ;
for ( V_55 = 0 ; V_55 < V_152 ; V_55 ++ ) {
V_115 = & V_148 -> V_157 [ V_55 ] ;
V_120 = F_33 ( V_115 ) ;
V_69 = V_120 -> V_158 ;
if ( ( ( V_120 -> V_159 != V_160 ||
( V_120 -> V_161 != V_162 &&
V_120 -> V_161 != V_163 ) ) &&
V_120 -> V_159 != V_164 ) ||
V_120 -> V_125 < 1 ||
F_41 ( F_42 ( V_115 , 0 ) -> V_165 ) == 0 )
continue;
if ( ( F_42 ( V_115 , 0 ) -> V_131 & V_166 ) !=
V_167 )
continue;
V_12 = ( F_42 ( V_115 , 0 ) -> V_168 & V_169 ) ?
V_170 : V_108 ;
V_149 = V_120 -> V_129 ;
if ( F_43 ( V_22 , V_116 , V_149 ) )
continue;
if ( F_44 ( V_22 -> V_112 ) == 0x0582 &&
V_120 -> V_159 == V_164 &&
V_69 <= 2 )
V_69 = V_130 ;
V_155 = 0 ;
switch ( V_69 ) {
default:
F_45 ( & V_21 -> V_21 , L_4 ,
V_116 , V_149 , V_69 ) ;
V_69 = V_130 ;
case V_130 : {
struct V_171 * V_17 =
F_37 ( V_115 -> V_122 , V_115 -> V_123 , NULL , V_172 ) ;
struct V_173 * V_174 ;
if ( ! V_17 ) {
F_46 ( & V_21 -> V_21 ,
L_5 ,
V_116 , V_149 ) ;
continue;
}
if ( V_17 -> V_126 < sizeof( * V_17 ) ) {
F_46 ( & V_21 -> V_21 ,
L_6 ,
V_116 , V_149 ) ;
continue;
}
V_150 = F_41 ( V_17 -> V_175 ) ;
V_174 = F_36 ( V_22 -> V_176 ,
V_17 -> V_177 ) ;
if ( V_174 ) {
V_151 = V_174 -> V_178 ;
V_155 = F_41 ( V_174 -> V_179 ) ;
}
break;
}
case V_101 : {
struct V_140 * V_180 ;
struct V_144 * V_181 ;
struct V_182 * V_17 =
F_37 ( V_115 -> V_122 , V_115 -> V_123 , NULL , V_172 ) ;
if ( ! V_17 ) {
F_46 ( & V_21 -> V_21 ,
L_5 ,
V_116 , V_149 ) ;
continue;
}
if ( V_17 -> V_126 < sizeof( * V_17 ) ) {
F_46 ( & V_21 -> V_21 ,
L_6 ,
V_116 , V_149 ) ;
continue;
}
V_151 = V_17 -> V_178 ;
V_150 = F_47 ( V_17 -> V_183 ) ;
V_155 = F_47 ( V_17 -> V_184 ) ;
V_180 = F_36 ( V_22 -> V_176 ,
V_17 -> V_177 ) ;
if ( V_180 ) {
clock = V_180 -> V_185 ;
if ( ! V_155 && ( V_151 == V_180 -> V_178 ) )
V_155 = F_47 ( V_180 -> V_184 ) ;
break;
}
V_181 = F_38 ( V_22 -> V_176 ,
V_17 -> V_177 ) ;
if ( V_181 ) {
clock = V_181 -> V_185 ;
break;
}
F_46 ( & V_21 -> V_21 ,
L_7 ,
V_116 , V_149 , V_17 -> V_177 ) ;
continue;
}
}
V_154 = F_37 ( V_115 -> V_122 , V_115 -> V_123 , NULL , V_186 ) ;
if ( ! V_154 ) {
F_46 ( & V_21 -> V_21 ,
L_8 ,
V_116 , V_149 ) ;
continue;
}
if ( ( ( V_69 == V_130 ) && ( V_154 -> V_126 < 8 ) ) ||
( ( V_69 == V_101 ) && ( V_154 -> V_126 < 6 ) ) ) {
F_46 ( & V_21 -> V_21 ,
L_9 ,
V_116 , V_149 ) ;
continue;
}
if ( V_154 -> V_178 == 1 &&
V_154 -> V_187 == 2 &&
V_149 == 2 && V_152 == 3 &&
V_4 && V_4 -> V_157 == 1 && V_4 -> V_31 == 1 &&
V_4 -> V_27 == V_188 &&
V_69 == V_130 &&
F_41 ( F_42 ( V_115 , 0 ) -> V_165 ) ==
V_4 -> V_189 * 2 )
continue;
V_4 = F_25 ( sizeof( * V_4 ) , V_100 ) ;
if ( ! V_4 ) {
F_46 ( & V_21 -> V_21 , L_10 ) ;
return - V_52 ;
}
V_4 -> V_148 = V_116 ;
V_4 -> V_157 = V_149 ;
V_4 -> V_190 = V_55 ;
V_4 -> V_30 = F_42 ( V_115 , 0 ) -> V_168 ;
V_4 -> V_191 = F_42 ( V_115 , 0 ) -> V_131 ;
V_4 -> V_192 = F_48 ( V_22 , V_115 ) ;
V_4 -> V_69 = V_69 ;
V_4 -> V_189 = F_41 ( F_42 ( V_115 , 0 ) -> V_165 ) ;
V_4 -> V_31 = V_151 ;
if ( F_10 ( V_21 ) == V_193 )
V_4 -> V_189 = ( ( ( V_4 -> V_189 >> 11 ) & 3 ) + 1 )
* ( V_4 -> V_189 & 0x7ff ) ;
V_4 -> V_121 = F_32 ( V_22 , V_115 , V_69 , V_116 ) ;
V_4 -> clock = clock ;
switch ( V_22 -> V_112 ) {
case F_29 ( 0x0a92 , 0x0053 ) :
V_4 -> V_121 &= ~ V_194 ;
break;
case F_29 ( 0x041e , 0x3020 ) :
case F_29 ( 0x0763 , 0x2003 ) :
V_4 -> V_121 |= V_194 ;
break;
case F_29 ( 0x0763 , 0x2001 ) :
case F_29 ( 0x0763 , 0x2012 ) :
case F_29 ( 0x047f , 0x0ca1 ) :
case F_29 ( 0x077d , 0x07af ) :
V_4 -> V_191 &= ~ V_195 ;
if ( V_12 == V_108 )
V_4 -> V_191 |= V_196 ;
else
V_4 -> V_191 |= V_197 ;
break;
}
if ( F_49 ( V_22 , V_4 , V_150 , V_154 , V_12 ) < 0 ) {
F_3 ( V_4 -> V_7 ) ;
F_3 ( V_4 ) ;
V_4 = NULL ;
continue;
}
if ( V_4 -> V_31 != V_151 )
V_155 = 0 ;
V_4 -> V_8 = F_23 ( V_4 -> V_31 , V_155 , V_69 ) ;
F_45 ( & V_21 -> V_21 , L_11 , V_116 , V_149 , V_4 -> V_30 ) ;
V_64 = F_26 ( V_22 , V_12 , V_4 ) ;
if ( V_64 < 0 ) {
F_3 ( V_4 -> V_7 ) ;
F_3 ( V_4 -> V_8 ) ;
F_3 ( V_4 ) ;
return V_64 ;
}
F_50 ( V_22 -> V_21 , V_116 , V_149 ) ;
F_51 ( V_22 , V_116 , V_115 , V_4 ) ;
F_52 ( V_22 , V_116 , V_115 , V_4 , V_4 -> V_198 ) ;
}
return 0 ;
}
