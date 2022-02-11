static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_7 = 0 ;
F_3 ( V_5 -> V_8 ,
( V_3 << V_9 ) | V_2 -> line , & V_7 ) ;
return V_7 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
F_5 ( V_5 -> V_8 ,
( V_3 << V_9 ) | V_2 -> line , V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned int V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
T_1 V_11 = ( V_12 << V_9 ) | V_2 -> line ;
F_7 ( V_5 -> V_8 , true ) ;
F_8 ( V_5 -> V_8 , V_11 , V_5 -> V_13 , V_10 ) ;
F_7 ( V_5 -> V_8 , false ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
T_1 V_11 = ( V_15 << V_9 ) | V_2 -> line ;
F_7 ( V_5 -> V_8 , true ) ;
F_10 ( V_5 -> V_8 , V_11 , V_5 -> V_13 , V_14 ) ;
F_7 ( V_5 -> V_8 , false ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_16 , T_1 V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
F_12 ( V_5 -> V_8 ,
( V_3 << V_9 ) | V_2 -> line ,
V_16 , V_7 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_17 )
{
F_11 ( V_2 , V_18 ,
V_19 ,
V_17 ? 0 : V_19 ) ;
}
static bool F_14 ( struct V_20 * V_6 , unsigned int V_3 )
{
switch ( V_3 >> V_9 ) {
case V_12 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
return true ;
default:
break;
}
return false ;
}
static bool F_15 ( struct V_20 * V_6 , unsigned int V_3 )
{
switch ( V_3 >> V_9 ) {
case V_12 :
return true ;
default:
break;
}
return false ;
}
static int F_16 ( struct V_1 * V_2 , int V_27 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
T_1 V_28 ;
T_1 V_29 = 0 ;
unsigned long V_30 = V_2 -> V_31 , div = V_30 / 16 / V_27 ;
if ( div > 0xffff ) {
V_29 = V_32 ;
div /= 4 ;
}
V_28 = F_1 ( V_2 , V_33 ) ;
F_4 ( V_2 , V_33 ,
V_34 ) ;
F_7 ( V_5 -> V_8 , true ) ;
F_4 ( V_2 , V_35 ,
V_36 ) ;
F_7 ( V_5 -> V_8 , false ) ;
F_4 ( V_2 , V_33 , V_28 ) ;
F_11 ( V_2 , V_37 ,
V_32 ,
V_29 ) ;
F_4 ( V_2 , V_33 ,
V_38 ) ;
F_7 ( V_5 -> V_8 , true ) ;
F_4 ( V_2 , V_39 , div / 256 ) ;
F_4 ( V_2 , V_40 , div % 256 ) ;
F_7 ( V_5 -> V_8 , false ) ;
F_4 ( V_2 , V_33 , V_28 ) ;
return F_17 ( V_30 / 16 , div ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned int V_10 ,
unsigned int V_41 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_42 = 0 , V_43 , V_44 , V_45 , V_46 ;
bool V_47 = ( V_41 == V_48 ) ? true : false ;
if ( F_19 ( V_10 >= sizeof( V_5 -> V_13 ) ) ) {
F_20 ( V_2 -> V_6 ,
L_1 ,
V_2 -> line , V_10 ) ;
V_2 -> V_49 . V_50 ++ ;
V_10 = sizeof( V_5 -> V_13 ) ;
}
while ( V_10 ) {
if ( V_47 ) {
V_42 = F_1 ( V_2 , V_22 ) ;
if ( ! ( V_42 & V_51 ) )
V_47 = false ;
} else
V_42 = 0 ;
if ( V_47 ) {
V_5 -> V_13 [ 0 ] = F_1 ( V_2 , V_12 ) ;
V_45 = 1 ;
} else {
F_6 ( V_2 , V_10 ) ;
V_45 = V_10 ;
}
V_42 &= V_52 ;
V_2 -> V_49 . V_53 ++ ;
V_44 = V_54 ;
if ( F_19 ( V_42 ) ) {
if ( V_42 & V_55 ) {
V_2 -> V_49 . V_56 ++ ;
if ( F_21 ( V_2 ) )
continue;
} else if ( V_42 & V_57 )
V_2 -> V_49 . V_58 ++ ;
else if ( V_42 & V_59 )
V_2 -> V_49 . V_60 ++ ;
else if ( V_42 & V_61 )
V_2 -> V_49 . V_62 ++ ;
V_42 &= V_2 -> V_63 ;
if ( V_42 & V_55 )
V_44 = V_64 ;
else if ( V_42 & V_57 )
V_44 = V_65 ;
else if ( V_42 & V_59 )
V_44 = V_66 ;
else if ( V_42 & V_61 )
V_44 = V_67 ;
}
for ( V_46 = 0 ; V_46 < V_45 ; ++ V_46 ) {
V_43 = V_5 -> V_13 [ V_46 ] ;
if ( F_22 ( V_2 , V_43 ) )
continue;
if ( V_42 & V_2 -> V_68 )
continue;
F_23 ( V_2 , V_42 , V_61 , V_43 ,
V_44 ) ;
}
V_10 -= V_45 ;
}
F_24 ( & V_2 -> V_69 -> V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_70 * V_71 = & V_2 -> V_69 -> V_71 ;
unsigned int V_72 , V_14 , V_46 ;
if ( F_19 ( V_2 -> V_73 ) ) {
F_4 ( V_2 , V_15 , V_2 -> V_73 ) ;
V_2 -> V_49 . V_74 ++ ;
V_2 -> V_73 = 0 ;
return;
}
if ( F_26 ( V_71 ) || F_27 ( V_2 ) )
return;
V_14 = F_28 ( V_71 ) ;
if ( F_29 ( V_14 ) ) {
V_72 = F_1 ( V_2 , V_24 ) ;
V_14 = ( V_14 > V_72 ) ? V_72 : V_14 ;
V_2 -> V_49 . V_74 += V_14 ;
for ( V_46 = 0 ; V_46 < V_14 ; ++ V_46 ) {
V_5 -> V_13 [ V_46 ] = V_71 -> V_13 [ V_71 -> V_75 ] ;
V_71 -> V_75 = ( V_71 -> V_75 + 1 ) & ( V_76 - 1 ) ;
}
F_9 ( V_2 , V_14 ) ;
}
if ( F_28 ( V_71 ) < V_77 )
F_30 ( V_2 ) ;
}
static void F_31 ( struct V_4 * V_5 , int V_78 )
{
struct V_1 * V_2 = & V_5 -> V_79 [ V_78 ] . V_2 ;
do {
unsigned int V_41 , V_80 , V_10 ;
V_41 = F_1 ( V_2 , V_21 ) ;
if ( V_41 & V_81 )
break;
V_41 &= V_82 ;
switch ( V_41 ) {
case V_83 :
case V_48 :
case V_84 :
case V_85 :
V_10 = F_1 ( V_2 , V_25 ) ;
if ( V_10 )
F_18 ( V_2 , V_10 , V_41 ) ;
break;
case V_86 :
V_80 = F_1 ( V_2 , V_23 ) ;
F_32 ( V_2 ,
! ! ( V_80 & V_87 ) ) ;
break;
case V_88 :
F_25 ( V_2 ) ;
break;
default:
F_33 ( V_2 -> V_6 ,
L_2 ,
V_2 -> line , V_41 ) ;
break;
}
} while ( 1 );
}
static void F_34 ( struct V_89 * V_90 )
{
struct V_4 * V_5 = F_35 ( V_90 , V_91 ) ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_5 -> V_92 . V_93 ; ++ V_46 )
F_31 ( V_5 , V_46 ) ;
}
static T_2 F_36 ( int V_94 , void * V_95 )
{
struct V_4 * V_5 = (struct V_4 * ) V_95 ;
F_37 ( & V_5 -> V_96 , & V_5 -> V_91 ) ;
return V_97 ;
}
static void F_38 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = & ( F_39 ( V_90 , V_98 ) -> V_2 ) ;
if ( ( V_2 -> V_99 . V_100 & V_101 ) &&
( V_2 -> V_99 . V_102 > 0 ) )
F_40 ( V_2 -> V_99 . V_102 ) ;
F_25 ( V_2 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
const T_3 V_16 = V_103 |
V_104 ;
T_3 V_105 = 0 ;
struct V_106 * V_99 = & V_2 -> V_99 ;
unsigned long V_107 ;
F_42 ( & V_2 -> V_108 , V_107 ) ;
if ( V_99 -> V_100 & V_101 ) {
V_105 |= V_103 ;
if ( V_99 -> V_100 & V_109 )
V_105 |= V_104 ;
}
F_43 ( & V_2 -> V_108 , V_107 ) ;
F_11 ( V_2 , V_110 , V_16 , V_105 ) ;
}
static void F_44 ( struct V_89 * V_90 )
{
struct V_111 * V_112 = F_39 ( V_90 , V_113 ) ;
struct V_114 V_115 ;
unsigned long V_107 ;
F_42 ( & V_112 -> V_2 . V_108 , V_107 ) ;
V_115 = V_112 -> V_115 ;
memset ( & V_112 -> V_115 , 0 , sizeof( V_112 -> V_115 ) ) ;
F_43 ( & V_112 -> V_2 . V_108 , V_107 ) ;
if ( V_115 . V_100 & V_116 )
F_11 ( & V_112 -> V_2 , V_37 ,
V_117 ,
( V_112 -> V_2 . V_118 & V_119 ) ?
V_117 : 0 ) ;
if ( V_115 . V_100 & V_120 )
F_11 ( & V_112 -> V_2 , V_18 ,
V_115 . V_121 , 0 ) ;
if ( V_115 . V_100 & V_122 )
F_41 ( & V_112 -> V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 , T_1 V_123 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_111 * V_112 = F_39 ( V_2 , V_2 ) ;
V_112 -> V_115 . V_100 |= V_120 ;
V_112 -> V_115 . V_121 |= V_123 ;
F_37 ( & V_5 -> V_96 , & V_112 -> V_113 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_45 ( V_2 , V_124 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_45 ( V_2 , V_125 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_111 * V_112 = F_39 ( V_2 , V_2 ) ;
F_37 ( & V_5 -> V_96 , & V_112 -> V_98 ) ;
}
static unsigned int F_49 ( struct V_1 * V_2 )
{
unsigned int V_42 ;
V_42 = F_1 ( V_2 , V_22 ) ;
return ( V_42 & V_126 ) ? V_127 : 0 ;
}
static unsigned int F_50 ( struct V_1 * V_2 )
{
return V_128 | V_129 ;
}
static void F_51 ( struct V_1 * V_2 , unsigned int V_118 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_111 * V_112 = F_39 ( V_2 , V_2 ) ;
V_112 -> V_115 . V_100 |= V_116 ;
F_37 ( & V_5 -> V_96 , & V_112 -> V_113 ) ;
}
static void F_52 ( struct V_1 * V_2 , int V_130 )
{
F_11 ( V_2 , V_33 ,
V_131 ,
V_130 ? V_131 : 0 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_132 * V_133 ,
struct V_132 * V_134 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_28 , V_135 = 0 ;
int V_27 ;
V_133 -> V_136 &= ~ V_137 ;
switch ( V_133 -> V_136 & V_138 ) {
case V_139 :
V_28 = V_140 ;
break;
case V_141 :
V_28 = V_142 ;
break;
case V_143 :
V_28 = V_144 ;
break;
case V_145 :
V_28 = V_146 ;
break;
default:
V_28 = V_146 ;
V_133 -> V_136 &= ~ V_138 ;
V_133 -> V_136 |= V_145 ;
break;
}
if ( V_133 -> V_136 & V_147 ) {
V_28 |= V_148 ;
if ( ! ( V_133 -> V_136 & V_149 ) )
V_28 |= V_150 ;
}
if ( V_133 -> V_136 & V_151 )
V_28 |= V_152 ;
V_2 -> V_63 = V_61 ;
if ( V_133 -> V_153 & V_154 )
V_2 -> V_63 |= V_57 |
V_59 ;
if ( V_133 -> V_153 & ( V_155 | V_156 ) )
V_2 -> V_63 |= V_55 ;
V_2 -> V_68 = 0 ;
if ( V_133 -> V_153 & V_157 )
V_2 -> V_68 |= V_55 ;
if ( ! ( V_133 -> V_136 & V_158 ) )
V_2 -> V_68 |= V_52 ;
F_4 ( V_2 , V_33 ,
V_34 ) ;
F_7 ( V_5 -> V_8 , true ) ;
F_4 ( V_2 , V_159 , V_133 -> V_160 [ V_161 ] ) ;
F_4 ( V_2 , V_162 , V_133 -> V_160 [ V_163 ] ) ;
if ( V_133 -> V_136 & V_164 )
V_135 |= V_165 |
V_166 ;
if ( V_133 -> V_153 & V_167 )
V_135 |= V_168 ;
if ( V_133 -> V_153 & V_169 )
V_135 |= V_170 ;
F_4 ( V_2 , V_35 , V_135 ) ;
F_7 ( V_5 -> V_8 , false ) ;
F_4 ( V_2 , V_33 , V_28 ) ;
V_27 = F_54 ( V_2 , V_133 , V_134 ,
V_2 -> V_31 / 16 / 4 / 0xffff ,
V_2 -> V_31 / 16 ) ;
V_27 = F_16 ( V_2 , V_27 ) ;
F_55 ( V_2 , V_133 -> V_136 , V_27 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_106 * V_99 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_111 * V_112 = F_39 ( V_2 , V_2 ) ;
if ( V_99 -> V_100 & V_101 ) {
bool V_171 , V_172 ;
V_171 = V_99 -> V_100 & V_109 ;
V_172 = V_99 -> V_100 & V_173 ;
if ( V_171 == V_172 )
F_57 ( V_2 -> V_6 ,
L_3 ,
V_172 , V_171 ) ;
if ( V_99 -> V_174 )
return - V_175 ;
}
V_2 -> V_99 = * V_99 ;
V_112 -> V_115 . V_100 |= V_122 ;
F_37 ( & V_5 -> V_96 , & V_112 -> V_113 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_7 ;
F_13 ( V_2 , 1 ) ;
V_7 = V_176 | V_177 ;
F_4 ( V_2 , V_178 , V_7 ) ;
F_59 ( 5 ) ;
F_4 ( V_2 , V_178 ,
V_179 ) ;
F_4 ( V_2 , V_33 ,
V_34 ) ;
F_7 ( V_5 -> V_8 , true ) ;
F_4 ( V_2 , V_35 ,
V_36 ) ;
F_11 ( V_2 , V_37 ,
V_180 ,
V_180 ) ;
F_4 ( V_2 , V_181 ,
F_60 ( 24 ) |
F_61 ( 48 ) ) ;
F_7 ( V_5 -> V_8 , false ) ;
F_4 ( V_2 , V_33 , V_146 ) ;
F_11 ( V_2 , V_110 ,
V_182 |
V_183 ,
0 ) ;
V_7 = V_125 | V_124 |
V_184 ;
F_4 ( V_2 , V_18 , V_7 ) ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
F_4 ( V_2 , V_18 , 0 ) ;
F_11 ( V_2 , V_110 ,
V_182 |
V_183 ,
V_182 |
V_183 ) ;
F_13 ( V_2 , 0 ) ;
F_63 ( & V_5 -> V_96 ) ;
}
static const char * F_64 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
return ( V_2 -> type == V_185 ) ? V_5 -> V_186 -> V_187 : NULL ;
}
static int F_65 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_66 ( struct V_1 * V_2 , int V_100 )
{
if ( V_100 & V_188 )
V_2 -> type = V_185 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_189 * V_5 )
{
if ( ( V_5 -> type != V_190 ) && ( V_5 -> type != V_185 ) )
return - V_175 ;
if ( V_5 -> V_94 != V_2 -> V_94 )
return - V_175 ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 , unsigned int V_69 ,
unsigned int V_191 )
{
F_13 ( V_2 , ( V_69 == V_192 ) ? 1 : 0 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
}
static int F_70 ( struct V_193 * V_194 , unsigned V_195 )
{
unsigned int V_7 ;
struct V_4 * V_5 = F_71 ( V_194 , struct V_4 ,
V_196 ) ;
struct V_1 * V_2 = & V_5 -> V_79 [ 0 ] . V_2 ;
V_7 = F_1 ( V_2 , V_26 ) ;
return ! ! ( V_7 & F_72 ( V_195 ) ) ;
}
static void F_73 ( struct V_193 * V_194 , unsigned V_195 , int V_7 )
{
struct V_4 * V_5 = F_71 ( V_194 , struct V_4 ,
V_196 ) ;
struct V_1 * V_2 = & V_5 -> V_79 [ 0 ] . V_2 ;
F_11 ( V_2 , V_26 , F_72 ( V_195 ) ,
V_7 ? F_72 ( V_195 ) : 0 ) ;
}
static int F_74 ( struct V_193 * V_194 ,
unsigned V_195 )
{
struct V_4 * V_5 = F_71 ( V_194 , struct V_4 ,
V_196 ) ;
struct V_1 * V_2 = & V_5 -> V_79 [ 0 ] . V_2 ;
F_11 ( V_2 , V_197 , F_72 ( V_195 ) , 0 ) ;
return 0 ;
}
static int F_75 ( struct V_193 * V_194 ,
unsigned V_195 , int V_7 )
{
struct V_4 * V_5 = F_71 ( V_194 , struct V_4 ,
V_196 ) ;
struct V_1 * V_2 = & V_5 -> V_79 [ 0 ] . V_2 ;
F_11 ( V_2 , V_26 , F_72 ( V_195 ) ,
V_7 ? F_72 ( V_195 ) : 0 ) ;
F_11 ( V_2 , V_197 , F_72 ( V_195 ) ,
F_72 ( V_195 ) ) ;
return 0 ;
}
static int F_76 ( struct V_20 * V_6 ,
struct V_198 * V_186 ,
struct V_8 * V_8 , int V_94 , unsigned long V_100 )
{
struct V_199 V_199 = { . V_200 = V_201 / 2 } ;
unsigned long V_202 , * V_203 = F_77 ( V_6 ) ;
int V_46 , V_204 ;
struct V_4 * V_5 ;
if ( F_78 ( V_8 ) )
return F_79 ( V_8 ) ;
V_5 = F_80 ( V_6 , sizeof( * V_5 ) +
sizeof( struct V_111 ) * V_186 -> V_205 ,
V_206 ) ;
if ( ! V_5 ) {
F_57 ( V_6 , L_4 ) ;
return - V_207 ;
}
V_5 -> V_30 = F_81 ( V_6 , NULL ) ;
if ( F_78 ( V_5 -> V_30 ) ) {
if ( V_203 )
V_202 = * V_203 ;
else
return F_79 ( V_5 -> V_30 ) ;
} else {
F_82 ( V_5 -> V_30 ) ;
V_202 = F_83 ( V_5 -> V_30 ) ;
}
V_5 -> V_8 = V_8 ;
V_5 -> V_186 = V_186 ;
F_84 ( V_6 , V_5 ) ;
V_5 -> V_92 . V_208 = V_209 ;
V_5 -> V_92 . V_210 = L_5 ;
V_5 -> V_92 . V_93 = V_186 -> V_205 ;
V_204 = F_85 ( & V_5 -> V_92 ) ;
if ( V_204 ) {
F_57 ( V_6 , L_6 ) ;
goto V_211;
}
F_86 ( & V_5 -> V_96 ) ;
F_87 ( & V_5 -> V_91 , F_34 ) ;
V_5 -> V_212 = F_88 ( V_213 , & V_5 -> V_96 ,
L_7 ) ;
if ( F_78 ( V_5 -> V_212 ) ) {
V_204 = F_79 ( V_5 -> V_212 ) ;
goto V_214;
}
F_89 ( V_5 -> V_212 , V_215 , & V_199 ) ;
#ifdef F_90
if ( V_186 -> V_216 ) {
V_5 -> V_196 . V_208 = V_209 ;
V_5 -> V_196 . V_6 = V_6 ;
V_5 -> V_196 . V_217 = V_210 ( V_6 ) ;
V_5 -> V_196 . V_218 = F_74 ;
V_5 -> V_196 . V_219 = F_70 ;
V_5 -> V_196 . V_220 = F_75 ;
V_5 -> V_196 . V_221 = F_73 ;
V_5 -> V_196 . V_222 = - 1 ;
V_5 -> V_196 . V_223 = V_186 -> V_216 ;
V_5 -> V_196 . V_224 = 1 ;
V_204 = F_91 ( & V_5 -> V_196 ) ;
if ( V_204 )
goto V_225;
}
#endif
for ( V_46 = 0 ; V_46 < V_186 -> V_205 ; ++ V_46 ) {
V_5 -> V_79 [ V_46 ] . V_2 . line = V_46 ;
V_5 -> V_79 [ V_46 ] . V_2 . V_6 = V_6 ;
V_5 -> V_79 [ V_46 ] . V_2 . V_94 = V_94 ;
V_5 -> V_79 [ V_46 ] . V_2 . type = V_185 ;
V_5 -> V_79 [ V_46 ] . V_2 . V_226 = V_227 ;
V_5 -> V_79 [ V_46 ] . V_2 . V_100 = V_228 | V_229 ;
V_5 -> V_79 [ V_46 ] . V_2 . V_230 = V_231 ;
V_5 -> V_79 [ V_46 ] . V_2 . V_31 = V_202 ;
V_5 -> V_79 [ V_46 ] . V_2 . V_232 = F_56 ;
V_5 -> V_79 [ V_46 ] . V_2 . V_233 = & V_234 ;
F_4 ( & V_5 -> V_79 [ V_46 ] . V_2 , V_18 , 0 ) ;
F_4 ( & V_5 -> V_79 [ V_46 ] . V_2 , V_110 ,
V_182 |
V_183 ) ;
F_87 ( & V_5 -> V_79 [ V_46 ] . V_98 , F_38 ) ;
F_87 ( & V_5 -> V_79 [ V_46 ] . V_113 , F_44 ) ;
F_92 ( & V_5 -> V_92 , & V_5 -> V_79 [ V_46 ] . V_2 ) ;
F_13 ( & V_5 -> V_79 [ V_46 ] . V_2 , 0 ) ;
}
V_204 = F_93 ( V_6 , V_94 , F_36 ,
V_235 | V_100 , V_210 ( V_6 ) , V_5 ) ;
if ( ! V_204 )
return 0 ;
for ( V_46 = 0 ; V_46 < V_5 -> V_92 . V_93 ; V_46 ++ )
F_94 ( & V_5 -> V_92 , & V_5 -> V_79 [ V_46 ] . V_2 ) ;
#ifdef F_90
if ( V_186 -> V_216 )
F_95 ( & V_5 -> V_196 ) ;
V_225:
#endif
F_96 ( V_5 -> V_212 ) ;
V_214:
F_97 ( & V_5 -> V_92 ) ;
V_211:
if ( ! F_78 ( V_5 -> V_30 ) )
F_98 ( V_5 -> V_30 ) ;
return V_204 ;
}
static int F_99 ( struct V_20 * V_6 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
int V_46 ;
#ifdef F_90
if ( V_5 -> V_186 -> V_216 )
F_95 ( & V_5 -> V_196 ) ;
#endif
for ( V_46 = 0 ; V_46 < V_5 -> V_92 . V_93 ; V_46 ++ ) {
F_94 ( & V_5 -> V_92 , & V_5 -> V_79 [ V_46 ] . V_2 ) ;
F_13 ( & V_5 -> V_79 [ V_46 ] . V_2 , 0 ) ;
}
F_63 ( & V_5 -> V_96 ) ;
F_96 ( V_5 -> V_212 ) ;
F_97 ( & V_5 -> V_92 ) ;
if ( ! F_78 ( V_5 -> V_30 ) )
F_98 ( V_5 -> V_30 ) ;
return 0 ;
}
static int F_100 ( struct V_236 * V_237 )
{
struct V_198 * V_186 ;
unsigned long V_100 = 0 ;
struct V_8 * V_8 ;
int V_204 ;
V_237 -> V_238 = 8 ;
V_237 -> V_239 = V_237 -> V_239 ? : V_240 ;
V_237 -> V_241 = V_237 -> V_241 ? : 15000000 ;
V_204 = F_101 ( V_237 ) ;
if ( V_204 )
return V_204 ;
if ( V_237 -> V_6 . V_242 ) {
const struct V_243 * V_244 =
F_102 ( V_245 , & V_237 -> V_6 ) ;
V_186 = (struct V_198 * ) V_244 -> V_246 ;
} else {
const struct V_247 * V_248 = F_103 ( V_237 ) ;
V_186 = (struct V_198 * ) V_248 -> V_249 ;
V_100 = V_250 ;
}
V_251 . V_252 = ( 0xf << V_9 ) |
( V_186 -> V_205 - 1 ) ;
V_8 = F_104 ( V_237 , & V_251 ) ;
return F_76 ( & V_237 -> V_6 , V_186 , V_8 , V_237 -> V_94 , V_100 ) ;
}
static int F_105 ( struct V_236 * V_237 )
{
return F_99 ( & V_237 -> V_6 ) ;
}
static int F_106 ( struct V_253 * V_254 ,
const struct V_255 * V_256 )
{
struct V_198 * V_186 ;
unsigned long V_100 = 0 ;
struct V_8 * V_8 ;
if ( V_254 -> V_6 . V_242 ) {
const struct V_243 * V_244 =
F_102 ( V_245 , & V_254 -> V_6 ) ;
V_186 = (struct V_198 * ) V_244 -> V_246 ;
} else {
V_186 = (struct V_198 * ) V_256 -> V_249 ;
V_100 = V_250 ;
}
V_251 . V_252 = ( 0xf << V_9 ) |
( V_186 -> V_205 - 1 ) ;
V_8 = F_107 ( V_254 , & V_251 ) ;
return F_76 ( & V_254 -> V_6 , V_186 , V_8 , V_254 -> V_94 , V_100 ) ;
}
static int F_108 ( struct V_253 * V_257 )
{
return F_99 ( & V_257 -> V_6 ) ;
}
static int T_4 F_109 ( void )
{
int V_204 = 0 ;
#ifdef F_110
V_204 = F_111 ( & V_258 ) ;
if ( V_204 < 0 ) {
F_112 ( L_8 , V_204 ) ;
return V_204 ;
}
#endif
#ifdef F_113
V_204 = F_114 ( & V_259 ) ;
if ( V_204 < 0 ) {
F_112 ( L_9 , V_204 ) ;
return V_204 ;
}
#endif
return V_204 ;
}
static void T_5 F_115 ( void )
{
#ifdef F_110
F_116 ( & V_258 ) ;
#endif
#ifdef F_113
F_117 ( & V_259 ) ;
#endif
}
