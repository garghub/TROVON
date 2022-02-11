static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_7 = 0 ;
F_3 ( V_5 -> V_8 , V_2 -> V_9 + V_3 , & V_7 ) ;
return V_7 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
F_5 ( V_5 -> V_8 , V_2 -> V_9 + V_3 , V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_10 , T_1 V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
F_7 ( V_5 -> V_8 , V_2 -> V_9 + V_3 , V_10 , V_7 ) ;
}
static int F_8 ( struct V_11 * V_6 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
unsigned int V_7 = 0 ;
int V_12 ;
V_12 = F_3 ( V_5 -> V_8 , V_13 , & V_7 ) ;
if ( V_12 )
return V_12 ;
if ( ( ( V_7 & V_14 ) != V_15 ) ) {
F_9 ( V_6 ,
L_1 , V_5 -> V_16 -> V_17 , V_7 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_10 ( struct V_11 * V_6 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
unsigned int V_7 = 0 ;
int V_12 ;
V_12 = F_3 ( V_5 -> V_8 , V_19 , & V_7 ) ;
if ( V_12 )
return V_12 ;
if ( V_7 != ( V_20 | V_21 ) ) {
F_9 ( V_6 , L_2 , V_5 -> V_16 -> V_17 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_11 ( struct V_11 * V_6 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
unsigned int V_7 = 0 ;
int V_12 ;
V_12 = F_5 ( V_5 -> V_8 , V_22 ,
V_23 ) ;
if ( V_12 )
return V_12 ;
F_3 ( V_5 -> V_8 , V_24 , & V_7 ) ;
F_5 ( V_5 -> V_8 , V_22 , V_25 ) ;
if ( ( ( V_7 & V_14 ) != V_26 ) ) {
F_9 ( V_6 ,
L_1 , V_5 -> V_16 -> V_17 , V_7 ) ;
return - V_18 ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , int V_27 )
{
F_6 ( V_2 , V_28 ,
V_29 ,
V_27 ? 0 : V_29 ) ;
if ( V_27 )
F_13 ( 50 ) ;
}
static int F_14 ( struct V_11 * V_6 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
unsigned int V_7 = 0 ;
int V_12 ;
V_12 = F_5 ( V_5 -> V_8 , V_22 ,
V_23 ) ;
if ( V_12 )
return V_12 ;
F_3 ( V_5 -> V_8 , V_24 , & V_7 ) ;
F_5 ( V_5 -> V_8 , V_22 , V_25 ) ;
if ( ( ( V_7 & V_14 ) != V_30 ) ) {
F_9 ( V_6 ,
L_1 , V_5 -> V_16 -> V_17 , V_7 ) ;
return - V_18 ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 , int V_27 )
{
F_6 ( V_2 , V_31 ,
V_32 ,
V_27 ? 0 : V_32 ) ;
if ( V_27 )
F_13 ( 50 ) ;
}
static bool F_16 ( struct V_11 * V_6 , unsigned int V_3 )
{
switch ( V_3 & 0x1f ) {
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
return false ;
default:
break;
}
return true ;
}
static bool F_17 ( struct V_11 * V_6 , unsigned int V_3 )
{
switch ( V_3 & 0x1f ) {
case V_39 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
return true ;
default:
break;
}
return false ;
}
static bool F_18 ( struct V_11 * V_6 , unsigned int V_3 )
{
switch ( V_3 & 0x1f ) {
case V_39 :
case V_33 :
case V_35 :
case V_36 :
return true ;
default:
break;
}
return false ;
}
static int F_19 ( struct V_1 * V_2 , int V_44 )
{
unsigned int V_45 = 0 , V_46 = V_2 -> V_47 , div = V_46 / V_44 ;
if ( div < 16 )
div = 16 ;
if ( V_46 % V_44 && ( div / 16 ) < 0x8000 ) {
V_45 = V_48 ;
V_46 = V_2 -> V_47 * 2 ;
div = V_46 / V_44 ;
if ( V_46 % V_44 && ( div / 16 ) < 0x8000 ) {
V_45 = V_49 ;
V_46 = V_2 -> V_47 * 4 ;
div = V_46 / V_44 ;
}
}
F_4 ( V_2 , V_50 , ( div / 16 ) >> 8 ) ;
F_4 ( V_2 , V_41 , div / 16 ) ;
F_4 ( V_2 , V_31 , ( div % 16 ) | V_45 ) ;
return F_20 ( V_46 , div ) ;
}
static int F_21 ( unsigned long V_51 , long * V_52 )
{
long V_53 = V_51 % ( 115200 * 16 ) ;
if ( ( * V_52 < 0 ) || ( * V_52 > V_53 ) ) {
* V_52 = V_53 ;
return 0 ;
}
return 1 ;
}
static int F_22 ( struct V_4 * V_5 , unsigned long V_54 ,
bool V_55 )
{
unsigned int div , V_56 , V_57 = 0 ;
long V_52 = - 1 ;
unsigned long V_58 , V_59 , V_60 = V_54 ;
F_21 ( V_54 , & V_52 ) ;
for ( div = 1 ; ( div <= 63 ) && V_52 ; div ++ ) {
V_58 = F_20 ( V_54 , div ) ;
V_59 = V_58 * 6 ;
if ( ( V_58 >= 500000 ) && ( V_58 <= 800000 ) )
if ( ! F_21 ( V_59 , & V_52 ) ) {
V_57 = ( 0 << 6 ) | div ;
V_60 = V_59 ;
}
V_59 = V_58 * 48 ;
if ( ( V_58 >= 850000 ) && ( V_58 <= 1200000 ) )
if ( ! F_21 ( V_59 , & V_52 ) ) {
V_57 = ( 1 << 6 ) | div ;
V_60 = V_59 ;
}
V_59 = V_58 * 96 ;
if ( ( V_58 >= 425000 ) && ( V_58 <= 1000000 ) )
if ( ! F_21 ( V_59 , & V_52 ) ) {
V_57 = ( 2 << 6 ) | div ;
V_60 = V_59 ;
}
V_59 = V_58 * 144 ;
if ( ( V_58 >= 390000 ) && ( V_58 <= 667000 ) )
if ( ! F_21 ( V_59 , & V_52 ) ) {
V_57 = ( 3 << 6 ) | div ;
V_60 = V_59 ;
}
}
V_56 = V_55 ? V_61 : V_20 ;
if ( V_57 ) {
V_56 |= V_62 ;
F_5 ( V_5 -> V_8 , V_63 , V_57 ) ;
} else
V_56 |= V_21 ;
F_5 ( V_5 -> V_8 , V_19 , V_56 ) ;
if ( V_57 && V_55 )
F_13 ( 10 ) ;
return ( int ) V_60 ;
}
static void F_23 ( struct V_1 * V_2 , unsigned int V_64 )
{
unsigned int V_65 , V_66 , V_67 ;
if ( F_24 ( V_64 >= V_2 -> V_68 ) ) {
F_25 ( V_2 -> V_6 , L_3 ) ;
V_2 -> V_69 . V_70 ++ ;
V_64 = V_2 -> V_68 ;
}
while ( V_64 -- ) {
V_66 = F_1 ( V_2 , V_39 ) ;
V_65 = F_1 ( V_2 , V_34 ) ;
V_65 &= V_71 | V_72 |
V_73 | V_74 ;
V_2 -> V_69 . V_75 ++ ;
V_67 = V_76 ;
if ( F_24 ( V_65 ) ) {
if ( V_65 & V_74 ) {
V_2 -> V_69 . V_77 ++ ;
if ( F_26 ( V_2 ) )
continue;
} else if ( V_65 & V_71 )
V_2 -> V_69 . V_78 ++ ;
else if ( V_65 & V_72 )
V_2 -> V_69 . V_79 ++ ;
else if ( V_65 & V_73 )
V_2 -> V_69 . V_80 ++ ;
V_65 &= V_2 -> V_81 ;
if ( V_65 & V_74 )
V_67 = V_82 ;
else if ( V_65 & V_71 )
V_67 = V_83 ;
else if ( V_65 & V_72 )
V_67 = V_84 ;
else if ( V_65 & V_73 )
V_67 = V_85 ;
}
if ( F_27 ( V_2 , V_66 ) )
continue;
if ( V_65 & V_2 -> V_86 )
continue;
F_28 ( V_2 , V_65 , V_73 , V_66 , V_67 ) ;
}
F_29 ( & V_2 -> V_87 -> V_2 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = & V_2 -> V_87 -> V_89 ;
unsigned int V_90 , V_91 ;
if ( F_24 ( V_2 -> V_92 ) ) {
F_4 ( V_2 , V_93 , V_2 -> V_92 ) ;
V_2 -> V_69 . V_94 ++ ;
V_2 -> V_92 = 0 ;
return;
}
if ( F_31 ( V_89 ) || F_32 ( V_2 ) )
return;
V_91 = F_33 ( V_89 ) ;
if ( F_34 ( V_91 ) ) {
V_90 = F_1 ( V_2 , V_37 ) ;
V_90 = V_2 -> V_68 - V_90 ;
V_91 = ( V_91 > V_90 ) ? V_90 : V_91 ;
V_2 -> V_69 . V_94 += V_91 ;
while ( V_91 -- ) {
F_4 ( V_2 , V_93 ,
V_89 -> V_95 [ V_89 -> V_96 ] ) ;
V_89 -> V_96 = ( V_89 -> V_96 + 1 ) & ( V_97 - 1 ) ;
}
}
if ( F_33 ( V_89 ) < V_98 )
F_35 ( V_2 ) ;
}
static void F_36 ( struct V_4 * V_5 , int V_99 )
{
struct V_1 * V_2 = & V_5 -> V_100 [ V_99 ] . V_2 ;
do {
unsigned int V_101 , V_102 , V_64 ;
V_101 = F_1 ( V_2 , V_33 ) ;
V_64 = F_1 ( V_2 , V_38 ) ;
if ( ! V_101 && ! V_64 )
break;
if ( V_101 & V_103 ) {
V_102 = F_1 ( V_2 , V_34 ) ;
F_37 ( V_2 ,
! ! ( V_102 & V_104 ) ) ;
}
if ( V_64 )
F_23 ( V_2 , V_64 ) ;
if ( V_101 & V_105 ) {
F_38 ( & V_5 -> V_106 ) ;
F_30 ( V_2 ) ;
F_39 ( & V_5 -> V_106 ) ;
}
} while ( 1 );
}
static T_2 F_40 ( int V_107 , void * V_108 )
{
struct V_4 * V_5 = (struct V_4 * ) V_108 ;
if ( V_5 -> V_16 -> V_109 > 1 ) {
do {
unsigned int V_7 = ~ 0 ;
F_41 ( F_3 ( V_5 -> V_8 ,
V_110 , & V_7 ) ) ;
V_7 = ( ( 1 << V_5 -> V_16 -> V_109 ) - 1 ) & ~ V_7 ;
if ( ! V_7 )
break;
F_36 ( V_5 , F_42 ( V_7 ) - 1 ) ;
} while ( 1 );
} else
F_36 ( V_5 , 0 ) ;
return V_111 ;
}
static void F_43 ( struct V_112 * V_113 )
{
struct V_114 * V_115 = F_44 ( V_113 , struct V_114 , V_116 ) ;
struct V_4 * V_5 = F_2 ( V_115 -> V_2 . V_6 ) ;
F_38 ( & V_5 -> V_106 ) ;
F_30 ( & V_115 -> V_2 ) ;
F_39 ( & V_5 -> V_106 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_114 * V_115 = F_44 ( V_2 , struct V_114 , V_2 ) ;
if ( ! F_46 ( & V_115 -> V_116 ) )
F_47 ( & V_115 -> V_116 ) ;
}
static unsigned int F_48 ( struct V_1 * V_2 )
{
unsigned int V_117 , V_65 ;
V_117 = F_1 ( V_2 , V_37 ) ;
V_65 = F_1 ( V_2 , V_33 ) ;
return ( ( V_65 & V_105 ) && ! V_117 ) ? V_118 : 0 ;
}
static unsigned int F_49 ( struct V_1 * V_2 )
{
return V_119 | V_120 ;
}
static void F_50 ( struct V_112 * V_113 )
{
struct V_114 * V_115 = F_44 ( V_113 , struct V_114 , V_121 ) ;
F_6 ( & V_115 -> V_2 , V_122 ,
V_123 ,
( V_115 -> V_2 . V_124 & V_125 ) ?
V_123 : 0 ) ;
}
static void F_51 ( struct V_1 * V_2 , unsigned int V_124 )
{
struct V_114 * V_115 = F_44 ( V_2 , struct V_114 , V_2 ) ;
F_47 ( & V_115 -> V_121 ) ;
}
static void F_52 ( struct V_1 * V_2 , int V_126 )
{
F_6 ( V_2 , V_127 ,
V_128 ,
V_126 ? V_128 : 0 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_129 * V_130 ,
struct V_129 * V_131 )
{
unsigned int V_132 = 0 , V_133 = 0 ;
int V_44 ;
V_130 -> V_134 &= ~ V_135 ;
switch ( V_130 -> V_134 & V_136 ) {
case V_137 :
break;
case V_138 :
V_132 = V_139 ;
break;
case V_140 :
V_132 = V_141 ;
break;
case V_142 :
default:
V_132 = V_141 | V_139 ;
break;
}
if ( V_130 -> V_134 & V_143 ) {
V_132 |= V_144 ;
if ( ! ( V_130 -> V_134 & V_145 ) )
V_132 |= V_146 ;
}
if ( V_130 -> V_134 & V_147 )
V_132 |= V_148 ;
F_4 ( V_2 , V_127 , V_132 ) ;
V_2 -> V_81 = V_73 ;
if ( V_130 -> V_149 & V_150 )
V_2 -> V_81 |= V_71 |
V_72 ;
if ( V_130 -> V_149 & ( V_151 | V_152 | V_153 ) )
V_2 -> V_81 |= V_74 ;
V_2 -> V_86 = 0 ;
if ( V_130 -> V_149 & V_151 )
V_2 -> V_86 |= V_74 ;
if ( ! ( V_130 -> V_134 & V_154 ) )
V_2 -> V_86 |= V_71 |
V_73 |
V_72 |
V_74 ;
F_4 ( V_2 , V_155 , V_130 -> V_156 [ V_157 ] ) ;
F_4 ( V_2 , V_158 , V_130 -> V_156 [ V_159 ] ) ;
if ( V_130 -> V_134 & V_160 )
V_133 |= V_161 |
V_162 ;
if ( V_130 -> V_149 & V_163 )
V_133 |= V_164 |
V_165 ;
if ( V_130 -> V_149 & V_166 )
V_133 |= V_167 |
V_165 ;
F_4 ( V_2 , V_168 , V_133 ) ;
V_44 = F_54 ( V_2 , V_130 , V_131 ,
V_2 -> V_47 / 16 / 0xffff ,
V_2 -> V_47 / 4 ) ;
V_44 = F_19 ( V_2 , V_44 ) ;
F_55 ( V_2 , V_130 -> V_134 , V_44 ) ;
}
static void F_56 ( struct V_112 * V_113 )
{
struct V_114 * V_115 = F_44 ( V_113 , struct V_114 , V_169 ) ;
unsigned int V_7 ;
V_7 = ( V_115 -> V_2 . V_170 . V_171 << 4 ) |
V_115 -> V_2 . V_170 . V_172 ;
F_4 ( & V_115 -> V_2 , V_173 , V_7 ) ;
if ( V_115 -> V_2 . V_170 . V_174 & V_175 ) {
F_6 ( & V_115 -> V_2 , V_28 ,
V_176 ,
V_176 ) ;
F_6 ( & V_115 -> V_2 , V_122 ,
V_177 ,
V_177 ) ;
} else {
F_6 ( & V_115 -> V_2 , V_28 ,
V_176 , 0 ) ;
F_6 ( & V_115 -> V_2 , V_122 ,
V_177 , 0 ) ;
}
}
static int F_57 ( struct V_1 * V_2 ,
struct V_178 * V_170 )
{
struct V_114 * V_115 = F_44 ( V_2 , struct V_114 , V_2 ) ;
if ( ( V_170 -> V_171 > 0x0f ) ||
( V_170 -> V_172 > 0x0f ) )
return - V_179 ;
V_170 -> V_174 &= V_180 | V_175 ;
memset ( V_170 -> V_181 , 0 , sizeof( V_170 -> V_181 ) ) ;
V_2 -> V_170 = * V_170 ;
F_47 ( & V_115 -> V_169 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_7 ;
V_5 -> V_16 -> V_182 ( V_2 , 1 ) ;
F_6 ( V_2 , V_28 ,
V_176 , 0 ) ;
V_7 = V_183 | V_184 ;
F_4 ( V_2 , V_122 , V_7 ) ;
F_6 ( V_2 , V_122 ,
V_184 , 0 ) ;
F_4 ( V_2 , V_185 ,
F_59 ( 48 ) | F_60 ( 96 ) ) ;
F_1 ( V_2 , V_33 ) ;
V_7 = V_186 | V_105 ;
F_4 ( V_2 , V_187 , V_7 | V_103 ) ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
F_4 ( V_2 , V_187 , 0 ) ;
V_5 -> V_16 -> V_182 ( V_2 , 0 ) ;
}
static const char * F_62 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
return ( V_2 -> type == V_188 ) ? V_5 -> V_16 -> V_17 : NULL ;
}
static int F_63 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_64 ( struct V_1 * V_2 , int V_174 )
{
if ( V_174 & V_189 )
V_2 -> type = V_188 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_190 * V_5 )
{
if ( ( V_5 -> type != V_191 ) && ( V_5 -> type != V_188 ) )
return - V_192 ;
if ( V_5 -> V_107 != V_2 -> V_107 )
return - V_192 ;
return 0 ;
}
static void F_66 ( struct V_1 * V_2 )
{
}
static int T_3 F_67 ( struct V_11 * V_6 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
int V_193 ;
for ( V_193 = 0 ; V_193 < V_5 -> V_16 -> V_109 ; V_193 ++ ) {
F_68 ( & V_194 , & V_5 -> V_100 [ V_193 ] . V_2 ) ;
V_5 -> V_16 -> V_182 ( & V_5 -> V_100 [ V_193 ] . V_2 , 0 ) ;
}
return 0 ;
}
static int T_3 F_69 ( struct V_11 * V_6 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
int V_193 ;
for ( V_193 = 0 ; V_193 < V_5 -> V_16 -> V_109 ; V_193 ++ ) {
V_5 -> V_16 -> V_182 ( & V_5 -> V_100 [ V_193 ] . V_2 , 1 ) ;
F_70 ( & V_194 , & V_5 -> V_100 [ V_193 ] . V_2 ) ;
}
return 0 ;
}
static int F_71 ( struct V_195 * V_196 , unsigned V_197 )
{
unsigned int V_7 ;
struct V_4 * V_5 = F_72 ( V_196 ) ;
struct V_1 * V_2 = & V_5 -> V_100 [ V_197 / 4 ] . V_2 ;
V_7 = F_1 ( V_2 , V_40 ) ;
return ! ! ( ( V_7 >> 4 ) & ( 1 << ( V_197 % 4 ) ) ) ;
}
static void F_73 ( struct V_195 * V_196 , unsigned V_197 , int V_198 )
{
struct V_4 * V_5 = F_72 ( V_196 ) ;
struct V_1 * V_2 = & V_5 -> V_100 [ V_197 / 4 ] . V_2 ;
F_6 ( V_2 , V_40 , 1 << ( V_197 % 4 ) ,
V_198 ? 1 << ( V_197 % 4 ) : 0 ) ;
}
static int F_74 ( struct V_195 * V_196 , unsigned V_197 )
{
struct V_4 * V_5 = F_72 ( V_196 ) ;
struct V_1 * V_2 = & V_5 -> V_100 [ V_197 / 4 ] . V_2 ;
F_6 ( V_2 , V_199 , 1 << ( V_197 % 4 ) , 0 ) ;
return 0 ;
}
static int F_75 ( struct V_195 * V_196 ,
unsigned V_197 , int V_198 )
{
struct V_4 * V_5 = F_72 ( V_196 ) ;
struct V_1 * V_2 = & V_5 -> V_100 [ V_197 / 4 ] . V_2 ;
F_6 ( V_2 , V_40 , 1 << ( V_197 % 4 ) ,
V_198 ? 1 << ( V_197 % 4 ) : 0 ) ;
F_6 ( V_2 , V_199 , 1 << ( V_197 % 4 ) ,
1 << ( V_197 % 4 ) ) ;
return 0 ;
}
static int F_76 ( struct V_11 * V_6 , struct V_200 * V_16 ,
struct V_8 * V_8 , int V_107 , unsigned long V_174 )
{
int V_193 , V_12 , V_201 , V_202 , V_54 , V_47 ;
struct V_46 * V_203 , * V_204 ;
struct V_4 * V_5 ;
bool V_55 = false ;
if ( F_77 ( V_8 ) )
return F_78 ( V_8 ) ;
V_5 = F_79 ( V_6 , sizeof( * V_5 ) +
sizeof( struct V_114 ) * V_16 -> V_109 , V_205 ) ;
if ( ! V_5 ) {
F_9 ( V_6 , L_4 ) ;
return - V_206 ;
}
V_203 = F_80 ( V_6 , L_5 ) ;
V_204 = F_80 ( V_6 , L_6 ) ;
if ( ! F_77 ( V_203 ) ) {
V_5 -> V_46 = V_203 ;
V_201 = 500000 ;
V_202 = 35000000 ;
} else if ( ! F_77 ( V_204 ) ) {
V_5 -> V_46 = V_204 ;
V_201 = 1000000 ;
V_202 = 4000000 ;
V_55 = true ;
} else if ( F_78 ( V_203 ) == - V_207 ||
F_78 ( V_204 ) == - V_207 ) {
return - V_207 ;
} else {
F_9 ( V_6 , L_7 ) ;
return - V_192 ;
}
V_12 = F_81 ( V_5 -> V_46 ) ;
if ( V_12 )
return V_12 ;
V_54 = F_82 ( V_5 -> V_46 ) ;
if ( V_54 < V_201 || V_54 > V_202 ) {
V_12 = - V_179 ;
goto V_208;
}
V_5 -> V_8 = V_8 ;
V_5 -> V_16 = V_16 ;
F_83 ( V_6 , V_5 ) ;
V_12 = V_16 -> V_209 ( V_6 ) ;
if ( V_12 )
goto V_208;
for ( V_193 = 0 ; V_193 < V_16 -> V_109 ; V_193 ++ ) {
unsigned int V_210 = V_193 << 5 ;
F_5 ( V_5 -> V_8 , V_122 + V_210 ,
V_211 ) ;
F_5 ( V_5 -> V_8 , V_122 + V_210 , 0 ) ;
do {
F_3 ( V_5 -> V_8 ,
V_41 + V_210 , & V_12 ) ;
} while ( V_12 != 0x01 );
F_7 ( V_5 -> V_8 , V_28 + V_210 ,
V_212 ,
V_212 ) ;
}
V_47 = F_22 ( V_5 , V_54 , V_55 ) ;
F_84 ( V_6 , L_8 , V_47 ) ;
#ifdef F_85
V_5 -> V_213 . V_214 = V_215 ;
V_5 -> V_213 . V_216 = V_6 ;
V_5 -> V_213 . V_217 = F_86 ( V_6 ) ;
V_5 -> V_213 . V_218 = F_74 ;
V_5 -> V_213 . V_219 = F_71 ;
V_5 -> V_213 . V_220 = F_75 ;
V_5 -> V_213 . V_221 = F_73 ;
V_5 -> V_213 . V_222 = - 1 ;
V_5 -> V_213 . V_223 = V_16 -> V_109 * 4 ;
V_5 -> V_213 . V_224 = 1 ;
V_12 = F_87 ( V_6 , & V_5 -> V_213 , V_5 ) ;
if ( V_12 )
goto V_208;
#endif
F_88 ( & V_5 -> V_106 ) ;
for ( V_193 = 0 ; V_193 < V_16 -> V_109 ; V_193 ++ ) {
unsigned int line ;
line = F_89 ( V_225 , V_226 ) ;
if ( line == V_226 ) {
V_12 = - V_179 ;
goto V_227;
}
V_5 -> V_100 [ V_193 ] . V_2 . line = line ;
V_5 -> V_100 [ V_193 ] . V_2 . V_6 = V_6 ;
V_5 -> V_100 [ V_193 ] . V_2 . V_107 = V_107 ;
V_5 -> V_100 [ V_193 ] . V_2 . type = V_188 ;
V_5 -> V_100 [ V_193 ] . V_2 . V_68 = V_228 ;
V_5 -> V_100 [ V_193 ] . V_2 . V_174 = V_229 | V_230 ;
V_5 -> V_100 [ V_193 ] . V_2 . V_231 = V_232 ;
V_5 -> V_100 [ V_193 ] . V_2 . V_9 = V_193 * 0x20 ;
V_5 -> V_100 [ V_193 ] . V_2 . V_233 = ( void V_234 * ) ~ 0 ;
V_5 -> V_100 [ V_193 ] . V_2 . V_47 = V_47 ;
V_5 -> V_100 [ V_193 ] . V_2 . V_235 = F_57 ;
V_5 -> V_100 [ V_193 ] . V_2 . V_236 = & V_237 ;
F_4 ( & V_5 -> V_100 [ V_193 ] . V_2 , V_187 , 0 ) ;
F_1 ( & V_5 -> V_100 [ V_193 ] . V_2 , V_33 ) ;
F_6 ( & V_5 -> V_100 [ V_193 ] . V_2 , V_28 ,
V_238 ,
V_238 ) ;
F_90 ( & V_5 -> V_100 [ V_193 ] . V_116 , F_43 ) ;
F_90 ( & V_5 -> V_100 [ V_193 ] . V_121 , F_50 ) ;
F_90 ( & V_5 -> V_100 [ V_193 ] . V_169 , F_56 ) ;
V_12 = F_91 ( & V_194 , & V_5 -> V_100 [ V_193 ] . V_2 ) ;
if ( V_12 ) {
V_5 -> V_100 [ V_193 ] . V_2 . V_6 = NULL ;
goto V_227;
}
F_92 ( line , V_225 ) ;
V_16 -> V_182 ( & V_5 -> V_100 [ V_193 ] . V_2 , 0 ) ;
}
V_12 = F_93 ( V_6 , V_107 , NULL , F_40 ,
V_239 | V_174 , F_86 ( V_6 ) , V_5 ) ;
if ( ! V_12 )
return 0 ;
F_9 ( V_6 , L_9 , V_107 ) ;
V_227:
for ( V_193 = 0 ; V_193 < V_16 -> V_109 ; V_193 ++ ) {
if ( V_5 -> V_100 [ V_193 ] . V_2 . V_6 ) {
F_94 ( & V_194 , & V_5 -> V_100 [ V_193 ] . V_2 ) ;
F_95 ( V_5 -> V_100 [ V_193 ] . V_2 . line , V_225 ) ;
}
}
F_96 ( & V_5 -> V_106 ) ;
V_208:
F_97 ( V_5 -> V_46 ) ;
return V_12 ;
}
static int F_98 ( struct V_11 * V_6 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
int V_193 ;
for ( V_193 = 0 ; V_193 < V_5 -> V_16 -> V_109 ; V_193 ++ ) {
F_99 ( & V_5 -> V_100 [ V_193 ] . V_116 ) ;
F_99 ( & V_5 -> V_100 [ V_193 ] . V_121 ) ;
F_99 ( & V_5 -> V_100 [ V_193 ] . V_169 ) ;
F_94 ( & V_194 , & V_5 -> V_100 [ V_193 ] . V_2 ) ;
F_95 ( V_5 -> V_100 [ V_193 ] . V_2 . line , V_225 ) ;
V_5 -> V_16 -> V_182 ( & V_5 -> V_100 [ V_193 ] . V_2 , 0 ) ;
}
F_96 ( & V_5 -> V_106 ) ;
F_97 ( V_5 -> V_46 ) ;
return 0 ;
}
static int F_100 ( struct V_240 * V_241 )
{
struct V_200 * V_16 ;
unsigned long V_174 = 0 ;
struct V_8 * V_8 ;
int V_12 ;
V_241 -> V_242 = 8 ;
V_241 -> V_45 = V_241 -> V_45 ? : V_243 ;
V_241 -> V_244 = V_241 -> V_244 ? : 26000000 ;
V_12 = F_101 ( V_241 ) ;
if ( V_12 )
return V_12 ;
if ( V_241 -> V_6 . V_245 ) {
const struct V_246 * V_247 =
F_102 ( V_248 , & V_241 -> V_6 ) ;
V_16 = (struct V_200 * ) V_247 -> V_249 ;
} else {
const struct V_250 * V_251 = F_103 ( V_241 ) ;
V_16 = (struct V_200 * ) V_251 -> V_252 ;
}
V_174 = V_253 ;
V_254 . V_255 = V_16 -> V_109 * 0x20 - 1 ;
V_8 = F_104 ( V_241 , & V_254 ) ;
return F_76 ( & V_241 -> V_6 , V_16 , V_8 , V_241 -> V_107 , V_174 ) ;
}
static int F_105 ( struct V_240 * V_241 )
{
return F_98 ( & V_241 -> V_6 ) ;
}
static int T_4 F_106 ( void )
{
int V_12 ;
F_107 ( V_225 , V_226 ) ;
V_12 = F_108 ( & V_194 ) ;
if ( V_12 )
return V_12 ;
#ifdef F_109
F_110 ( & V_256 ) ;
#endif
return 0 ;
}
static void T_5 F_111 ( void )
{
#ifdef F_109
F_112 ( & V_256 ) ;
#endif
F_113 ( & V_194 ) ;
}
