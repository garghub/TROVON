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
V_12 = F_3 ( V_5 -> V_8 , V_13 , & V_7 ) ;
if ( V_12 )
return V_12 ;
if ( ( ( V_7 & V_14 ) != V_22 ) ) {
F_9 ( V_6 ,
L_1 , V_5 -> V_16 -> V_17 , V_7 ) ;
return - V_18 ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , int V_23 )
{
F_6 ( V_2 , V_24 ,
V_25 ,
V_23 ? 0 : V_25 ) ;
if ( V_23 )
F_13 ( 50 ) ;
}
static int F_14 ( struct V_11 * V_6 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
unsigned int V_7 = 0 ;
int V_12 ;
V_12 = F_5 ( V_5 -> V_8 , V_26 ,
V_27 ) ;
if ( V_12 )
return V_12 ;
F_3 ( V_5 -> V_8 , V_28 , & V_7 ) ;
F_5 ( V_5 -> V_8 , V_26 , V_29 ) ;
if ( ( ( V_7 & V_14 ) != V_30 ) ) {
F_9 ( V_6 ,
L_1 , V_5 -> V_16 -> V_17 , V_7 ) ;
return - V_18 ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 , int V_23 )
{
F_6 ( V_2 , V_31 ,
V_32 ,
V_23 ? 0 : V_32 ) ;
if ( V_23 )
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
F_25 ( V_2 -> V_6 ,
L_3 ,
V_2 -> line ) ;
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
if ( V_5 -> V_109 . V_110 > 1 ) {
do {
unsigned int V_7 = ~ 0 ;
F_41 ( F_3 ( V_5 -> V_8 ,
V_111 , & V_7 ) ) ;
V_7 = ( ( 1 << V_5 -> V_109 . V_110 ) - 1 ) & ~ V_7 ;
if ( ! V_7 )
break;
F_36 ( V_5 , F_42 ( V_7 ) - 1 ) ;
} while ( 1 );
} else
F_36 ( V_5 , 0 ) ;
return V_112 ;
}
static void F_43 ( struct V_113 * V_114 )
{
struct V_115 * V_116 = F_44 ( V_114 , struct V_115 , V_117 ) ;
struct V_4 * V_5 = F_2 ( V_116 -> V_2 . V_6 ) ;
F_38 ( & V_5 -> V_106 ) ;
F_30 ( & V_116 -> V_2 ) ;
F_39 ( & V_5 -> V_106 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_115 * V_116 = F_44 ( V_2 , struct V_115 , V_2 ) ;
if ( ! F_46 ( & V_116 -> V_117 ) )
F_47 ( & V_116 -> V_117 ) ;
}
static unsigned int F_48 ( struct V_1 * V_2 )
{
unsigned int V_118 , V_65 ;
V_118 = F_1 ( V_2 , V_37 ) ;
V_65 = F_1 ( V_2 , V_33 ) ;
return ( ( V_65 & V_105 ) && ! V_118 ) ? V_119 : 0 ;
}
static unsigned int F_49 ( struct V_1 * V_2 )
{
return V_120 | V_121 ;
}
static void F_50 ( struct V_113 * V_114 )
{
struct V_115 * V_116 = F_44 ( V_114 , struct V_115 , V_122 ) ;
F_6 ( & V_116 -> V_2 , V_123 ,
V_124 ,
( V_116 -> V_2 . V_125 & V_126 ) ?
V_124 : 0 ) ;
}
static void F_51 ( struct V_1 * V_2 , unsigned int V_125 )
{
struct V_115 * V_116 = F_44 ( V_2 , struct V_115 , V_2 ) ;
F_47 ( & V_116 -> V_122 ) ;
}
static void F_52 ( struct V_1 * V_2 , int V_127 )
{
F_6 ( V_2 , V_128 ,
V_129 ,
V_127 ? V_129 : 0 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_130 * V_131 ,
struct V_130 * V_132 )
{
unsigned int V_133 , V_134 = 0 ;
int V_44 ;
V_131 -> V_135 &= ~ V_136 ;
switch ( V_131 -> V_135 & V_137 ) {
case V_138 :
V_133 = V_139 ;
break;
case V_140 :
V_133 = V_141 ;
break;
case V_142 :
V_133 = V_143 ;
break;
case V_144 :
default:
V_133 = V_145 ;
break;
}
if ( V_131 -> V_135 & V_146 ) {
V_133 |= V_147 ;
if ( ! ( V_131 -> V_135 & V_148 ) )
V_133 |= V_149 ;
}
if ( V_131 -> V_135 & V_150 )
V_133 |= V_151 ;
F_4 ( V_2 , V_128 , V_133 ) ;
V_2 -> V_81 = V_73 ;
if ( V_131 -> V_152 & V_153 )
V_2 -> V_81 |= V_71 |
V_72 ;
if ( V_131 -> V_152 & ( V_154 | V_155 ) )
V_2 -> V_81 |= V_74 ;
V_2 -> V_86 = 0 ;
if ( V_131 -> V_152 & V_156 )
V_2 -> V_86 |= V_74 ;
if ( ! ( V_131 -> V_135 & V_157 ) )
V_2 -> V_86 |= V_71 |
V_73 |
V_72 |
V_74 ;
F_4 ( V_2 , V_158 , V_131 -> V_159 [ V_160 ] ) ;
F_4 ( V_2 , V_161 , V_131 -> V_159 [ V_162 ] ) ;
if ( V_131 -> V_135 & V_163 )
V_134 |= V_164 |
V_165 ;
if ( V_131 -> V_152 & V_166 )
V_134 |= V_167 |
V_168 ;
if ( V_131 -> V_152 & V_169 )
V_134 |= V_170 |
V_168 ;
F_4 ( V_2 , V_171 , V_134 ) ;
V_44 = F_54 ( V_2 , V_131 , V_132 ,
V_2 -> V_47 / 16 / 0xffff ,
V_2 -> V_47 / 4 ) ;
V_44 = F_19 ( V_2 , V_44 ) ;
F_55 ( V_2 , V_131 -> V_135 , V_44 ) ;
}
static int F_56 ( struct V_1 * V_2 , unsigned int V_172 ,
unsigned long V_173 )
{
#if F_57 ( V_174 ) && F_57 ( V_175 )
struct V_176 V_177 ;
unsigned int V_7 ;
switch ( V_172 ) {
case V_174 :
if ( F_58 ( & V_177 , ( void V_178 * ) V_173 , sizeof( V_177 ) ) )
return - V_179 ;
if ( V_177 . V_180 > 0x0f ||
V_177 . V_181 > 0x0f )
return - V_182 ;
V_7 = ( V_177 . V_180 << 4 ) |
V_177 . V_181 ;
F_4 ( V_2 , V_183 , V_7 ) ;
if ( V_177 . V_184 & V_185 ) {
F_6 ( V_2 , V_24 ,
V_186 ,
V_186 ) ;
F_6 ( V_2 , V_123 ,
V_187 ,
V_187 ) ;
} else {
F_6 ( V_2 , V_24 ,
V_186 , 0 ) ;
F_6 ( V_2 , V_123 ,
V_187 , 0 ) ;
}
return 0 ;
case V_175 :
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
V_7 = F_1 ( V_2 , V_24 ) ;
V_177 . V_184 = ( V_7 & V_186 ) ?
V_185 : 0 ;
V_177 . V_184 |= V_188 ;
V_7 = F_1 ( V_2 , V_183 ) ;
V_177 . V_180 = V_7 >> 4 ;
V_177 . V_181 = V_7 & 0x0f ;
if ( F_59 ( ( void V_178 * ) V_173 , & V_177 , sizeof( V_177 ) ) )
return - V_179 ;
return 0 ;
default:
break;
}
#endif
return - V_189 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_7 ;
V_5 -> V_16 -> V_190 ( V_2 , 1 ) ;
F_6 ( V_2 , V_24 ,
V_186 , 0 ) ;
V_7 = V_191 | V_192 ;
F_4 ( V_2 , V_123 , V_7 ) ;
F_6 ( V_2 , V_123 ,
V_192 , 0 ) ;
F_4 ( V_2 , V_193 ,
F_61 ( 48 ) | F_62 ( 96 ) ) ;
F_1 ( V_2 , V_33 ) ;
V_7 = V_194 | V_105 ;
F_4 ( V_2 , V_195 , V_7 | V_103 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
F_4 ( V_2 , V_195 , 0 ) ;
V_5 -> V_16 -> V_190 ( V_2 , 0 ) ;
}
static const char * F_64 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
return ( V_2 -> type == V_196 ) ? V_5 -> V_16 -> V_17 : NULL ;
}
static int F_65 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_66 ( struct V_1 * V_2 , int V_184 )
{
if ( V_184 & V_197 )
V_2 -> type = V_196 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_198 * V_5 )
{
if ( ( V_5 -> type != V_199 ) && ( V_5 -> type != V_196 ) )
return - V_200 ;
if ( V_5 -> V_107 != V_2 -> V_107 )
return - V_200 ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
}
static int T_3 F_69 ( struct V_11 * V_6 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
int V_201 ;
for ( V_201 = 0 ; V_201 < V_5 -> V_109 . V_110 ; V_201 ++ ) {
F_70 ( & V_5 -> V_109 , & V_5 -> V_100 [ V_201 ] . V_2 ) ;
V_5 -> V_16 -> V_190 ( & V_5 -> V_100 [ V_201 ] . V_2 , 0 ) ;
}
return 0 ;
}
static int T_3 F_71 ( struct V_11 * V_6 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
int V_201 ;
for ( V_201 = 0 ; V_201 < V_5 -> V_109 . V_110 ; V_201 ++ ) {
V_5 -> V_16 -> V_190 ( & V_5 -> V_100 [ V_201 ] . V_2 , 1 ) ;
F_72 ( & V_5 -> V_109 , & V_5 -> V_100 [ V_201 ] . V_2 ) ;
}
return 0 ;
}
static int F_73 ( struct V_202 * V_203 , unsigned V_204 )
{
unsigned int V_7 ;
struct V_4 * V_5 = F_44 ( V_203 , struct V_4 , V_205 ) ;
struct V_1 * V_2 = & V_5 -> V_100 [ V_204 / 4 ] . V_2 ;
V_7 = F_1 ( V_2 , V_40 ) ;
return ! ! ( ( V_7 >> 4 ) & ( 1 << ( V_204 % 4 ) ) ) ;
}
static void F_74 ( struct V_202 * V_203 , unsigned V_204 , int V_206 )
{
struct V_4 * V_5 = F_44 ( V_203 , struct V_4 , V_205 ) ;
struct V_1 * V_2 = & V_5 -> V_100 [ V_204 / 4 ] . V_2 ;
F_6 ( V_2 , V_40 , 1 << ( V_204 % 4 ) ,
V_206 ? 1 << ( V_204 % 4 ) : 0 ) ;
}
static int F_75 ( struct V_202 * V_203 , unsigned V_204 )
{
struct V_4 * V_5 = F_44 ( V_203 , struct V_4 , V_205 ) ;
struct V_1 * V_2 = & V_5 -> V_100 [ V_204 / 4 ] . V_2 ;
F_6 ( V_2 , V_207 , 1 << ( V_204 % 4 ) , 0 ) ;
return 0 ;
}
static int F_76 ( struct V_202 * V_203 ,
unsigned V_204 , int V_206 )
{
struct V_4 * V_5 = F_44 ( V_203 , struct V_4 , V_205 ) ;
struct V_1 * V_2 = & V_5 -> V_100 [ V_204 / 4 ] . V_2 ;
F_6 ( V_2 , V_40 , 1 << ( V_204 % 4 ) ,
V_206 ? 1 << ( V_204 % 4 ) : 0 ) ;
F_6 ( V_2 , V_207 , 1 << ( V_204 % 4 ) ,
1 << ( V_204 % 4 ) ) ;
return 0 ;
}
static int F_77 ( struct V_11 * V_6 , struct V_208 * V_16 ,
struct V_8 * V_8 , int V_107 , unsigned long V_184 )
{
int V_201 , V_12 , V_209 , V_210 , V_54 , V_47 ;
struct V_46 * V_211 , * V_212 ;
struct V_4 * V_5 ;
bool V_55 = false ;
if ( F_78 ( V_8 ) )
return F_79 ( V_8 ) ;
V_5 = F_80 ( V_6 , sizeof( * V_5 ) +
sizeof( struct V_115 ) * V_16 -> V_110 , V_213 ) ;
if ( ! V_5 ) {
F_9 ( V_6 , L_4 ) ;
return - V_214 ;
}
V_211 = F_81 ( V_6 , L_5 ) ;
V_212 = F_81 ( V_6 , L_6 ) ;
if ( ! F_78 ( V_211 ) ) {
V_5 -> V_46 = V_211 ;
V_209 = 500000 ;
V_210 = 35000000 ;
} else if ( ! F_78 ( V_212 ) ) {
V_5 -> V_46 = V_212 ;
V_209 = 1000000 ;
V_210 = 4000000 ;
V_55 = true ;
} else if ( F_79 ( V_211 ) == - V_215 ||
F_79 ( V_212 ) == - V_215 ) {
return - V_215 ;
} else {
F_9 ( V_6 , L_7 ) ;
return - V_200 ;
}
V_12 = F_82 ( V_5 -> V_46 ) ;
if ( V_12 )
return V_12 ;
V_54 = F_83 ( V_5 -> V_46 ) ;
if ( V_54 < V_209 || V_54 > V_210 ) {
V_12 = - V_182 ;
goto V_216;
}
V_5 -> V_8 = V_8 ;
V_5 -> V_16 = V_16 ;
F_84 ( V_6 , V_5 ) ;
V_12 = V_16 -> V_217 ( V_6 ) ;
if ( V_12 )
goto V_216;
for ( V_201 = 0 ; V_201 < V_16 -> V_110 ; V_201 ++ ) {
unsigned int V_218 = V_201 << 5 ;
F_5 ( V_5 -> V_8 , V_123 + V_218 ,
V_219 ) ;
F_5 ( V_5 -> V_8 , V_123 + V_218 , 0 ) ;
do {
F_3 ( V_5 -> V_8 ,
V_41 + V_218 , & V_12 ) ;
} while ( V_12 != 0x01 );
F_7 ( V_5 -> V_8 , V_24 + V_218 ,
V_220 ,
V_220 ) ;
}
V_47 = F_22 ( V_5 , V_54 , V_55 ) ;
F_85 ( V_6 , L_8 , V_47 ) ;
V_5 -> V_109 . V_221 = V_222 ;
V_5 -> V_109 . V_223 = L_9 ;
V_5 -> V_109 . V_224 = V_225 ;
V_5 -> V_109 . V_226 = V_227 ;
V_5 -> V_109 . V_110 = V_16 -> V_110 ;
V_12 = F_86 ( & V_5 -> V_109 ) ;
if ( V_12 ) {
F_9 ( V_6 , L_10 ) ;
goto V_216;
}
#ifdef F_87
V_5 -> V_205 . V_221 = V_222 ;
V_5 -> V_205 . V_6 = V_6 ;
V_5 -> V_205 . V_228 = V_223 ( V_6 ) ;
V_5 -> V_205 . V_229 = F_75 ;
V_5 -> V_205 . V_230 = F_73 ;
V_5 -> V_205 . V_231 = F_76 ;
V_5 -> V_205 . V_232 = F_74 ;
V_5 -> V_205 . V_233 = - 1 ;
V_5 -> V_205 . V_234 = V_16 -> V_110 * 4 ;
V_5 -> V_205 . V_235 = 1 ;
V_12 = F_88 ( & V_5 -> V_205 ) ;
if ( V_12 )
goto V_236;
#endif
F_89 ( & V_5 -> V_106 ) ;
for ( V_201 = 0 ; V_201 < V_16 -> V_110 ; V_201 ++ ) {
V_5 -> V_100 [ V_201 ] . V_2 . line = V_201 ;
V_5 -> V_100 [ V_201 ] . V_2 . V_6 = V_6 ;
V_5 -> V_100 [ V_201 ] . V_2 . V_107 = V_107 ;
V_5 -> V_100 [ V_201 ] . V_2 . type = V_196 ;
V_5 -> V_100 [ V_201 ] . V_2 . V_68 = V_237 ;
V_5 -> V_100 [ V_201 ] . V_2 . V_184 = V_238 | V_239 ;
V_5 -> V_100 [ V_201 ] . V_2 . V_240 = V_241 ;
V_5 -> V_100 [ V_201 ] . V_2 . V_9 = V_201 * 0x20 ;
V_5 -> V_100 [ V_201 ] . V_2 . V_242 = ( void V_243 * ) ~ 0 ;
V_5 -> V_100 [ V_201 ] . V_2 . V_47 = V_47 ;
V_5 -> V_100 [ V_201 ] . V_2 . V_244 = & V_245 ;
F_4 ( & V_5 -> V_100 [ V_201 ] . V_2 , V_195 , 0 ) ;
F_1 ( & V_5 -> V_100 [ V_201 ] . V_2 , V_33 ) ;
F_6 ( & V_5 -> V_100 [ V_201 ] . V_2 , V_24 ,
V_246 ,
V_246 ) ;
F_90 ( & V_5 -> V_100 [ V_201 ] . V_117 , F_43 ) ;
F_90 ( & V_5 -> V_100 [ V_201 ] . V_122 , F_50 ) ;
F_91 ( & V_5 -> V_109 , & V_5 -> V_100 [ V_201 ] . V_2 ) ;
V_16 -> V_190 ( & V_5 -> V_100 [ V_201 ] . V_2 , 0 ) ;
}
V_12 = F_92 ( V_6 , V_107 , NULL , F_40 ,
V_247 | V_184 , V_223 ( V_6 ) , V_5 ) ;
if ( ! V_12 )
return 0 ;
F_9 ( V_6 , L_11 , V_107 ) ;
F_93 ( & V_5 -> V_106 ) ;
#ifdef F_87
F_94 ( F_95 ( & V_5 -> V_205 ) ) ;
V_236:
#endif
F_96 ( & V_5 -> V_109 ) ;
V_216:
F_97 ( V_5 -> V_46 ) ;
return V_12 ;
}
static int F_98 ( struct V_11 * V_6 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
int V_201 , V_12 = 0 ;
#ifdef F_87
V_12 = F_95 ( & V_5 -> V_205 ) ;
if ( V_12 )
return V_12 ;
#endif
for ( V_201 = 0 ; V_201 < V_5 -> V_109 . V_110 ; V_201 ++ ) {
F_99 ( & V_5 -> V_100 [ V_201 ] . V_117 ) ;
F_99 ( & V_5 -> V_100 [ V_201 ] . V_122 ) ;
F_100 ( & V_5 -> V_109 , & V_5 -> V_100 [ V_201 ] . V_2 ) ;
V_5 -> V_16 -> V_190 ( & V_5 -> V_100 [ V_201 ] . V_2 , 0 ) ;
}
F_93 ( & V_5 -> V_106 ) ;
F_96 ( & V_5 -> V_109 ) ;
F_97 ( V_5 -> V_46 ) ;
return V_12 ;
}
static int F_101 ( struct V_248 * V_249 )
{
struct V_208 * V_16 ;
unsigned long V_184 = 0 ;
struct V_8 * V_8 ;
int V_12 ;
V_249 -> V_250 = 8 ;
V_249 -> V_45 = V_249 -> V_45 ? : V_251 ;
V_249 -> V_252 = V_249 -> V_252 ? : 26000000 ;
V_12 = F_102 ( V_249 ) ;
if ( V_12 )
return V_12 ;
if ( V_249 -> V_6 . V_253 ) {
const struct V_254 * V_255 =
F_103 ( V_256 , & V_249 -> V_6 ) ;
V_16 = (struct V_208 * ) V_255 -> V_257 ;
} else {
const struct V_258 * V_259 = F_104 ( V_249 ) ;
V_16 = (struct V_208 * ) V_259 -> V_260 ;
V_184 = V_261 ;
}
V_262 . V_263 = V_16 -> V_110 * 0x20 - 1 ;
V_8 = F_105 ( V_249 , & V_262 ) ;
return F_77 ( & V_249 -> V_6 , V_16 , V_8 , V_249 -> V_107 , V_184 ) ;
}
static int F_106 ( struct V_248 * V_249 )
{
return F_98 ( & V_249 -> V_6 ) ;
}
