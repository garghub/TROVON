static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_7 = V_6 -> V_8 [ V_4 ] ;
if ( F_3 ( V_7 == V_9 ) )
return;
F_4 ( V_3 , V_6 -> V_10 + V_7 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_7 = V_6 -> V_8 [ V_4 ] ;
if ( F_3 ( V_7 == V_9 ) )
return ~ 0U ;
return F_6 ( V_6 -> V_10 + V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_4 , T_1 V_11 ,
T_1 V_12 )
{
F_1 ( V_2 , ( F_5 ( V_2 , V_4 ) & ~ V_11 ) | V_12 ,
V_4 ) ;
}
static bool F_8 ( struct V_5 * V_6 )
{
return V_6 -> V_8 == V_13 ;
}
static bool F_9 ( struct V_5 * V_6 )
{
return V_6 -> V_8 == V_14 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_15 ;
switch ( V_6 -> V_16 ) {
case V_17 :
V_15 = 0x2 ;
break;
case V_18 :
V_15 = 0x1 ;
break;
case V_19 :
V_15 = 0x0 ;
break;
default:
F_11 ( V_2 ,
L_1 ) ;
V_15 = 0x1 ;
break;
}
F_1 ( V_2 , V_15 , V_20 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_7 ( V_2 , V_21 , V_22 , V_6 -> V_23 ? V_22 : 0 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_14 ( V_6 , V_24 , V_25 ) ;
F_15 ( 1 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_26 ) {
case 10 :
F_1 ( V_2 , V_27 , V_28 ) ;
break;
case 100 :
F_1 ( V_2 , V_29 , V_28 ) ;
break;
case 1000 :
F_1 ( V_2 , V_30 , V_28 ) ;
break;
}
}
static void F_17 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
F_10 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_26 ) {
case 10 :
F_7 ( V_2 , V_21 , V_31 , 0 ) ;
break;
case 100 :
F_7 ( V_2 , V_21 , V_31 , V_31 ) ;
break;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_26 ) {
case 10 :
F_7 ( V_2 , V_21 , V_32 , 0 ) ;
break;
case 100 :
F_7 ( V_2 , V_21 , V_32 , V_32 ) ;
break;
}
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_26 ) {
case 10 :
F_1 ( V_2 , 0 , V_33 ) ;
break;
case 100 :
F_1 ( V_2 , 1 , V_33 ) ;
break;
}
}
static void F_21 ( struct V_1 * V_2 )
{
T_1 V_34 [ 2 ] , V_35 [ 2 ] ;
int V_36 ;
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ ) {
V_35 [ V_36 ] = F_6 ( ( void * ) F_22 ( V_36 ) ) ;
V_34 [ V_36 ] = F_6 ( ( void * ) F_23 ( V_36 ) ) ;
}
F_13 ( V_2 ) ;
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ ) {
F_4 ( V_35 [ V_36 ] , ( void * ) F_22 ( V_36 ) ) ;
F_4 ( V_34 [ V_36 ] , ( void * ) F_23 ( V_36 ) ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_26 ) {
case 10 :
F_1 ( V_2 , 0x00000000 , V_28 ) ;
break;
case 100 :
F_1 ( V_2 , 0x00000010 , V_28 ) ;
break;
case 1000 :
F_1 ( V_2 , 0x00000020 , V_28 ) ;
break;
}
}
static void F_25 ( struct V_37 * V_38 )
{
if ( ! V_38 -> V_39 )
V_38 -> V_39 = V_40 ;
if ( ! V_38 -> V_41 )
V_38 -> V_41 = V_42 ;
if ( ! V_38 -> V_43 )
V_38 -> V_43 = V_44 |
V_45 ;
if ( ! V_38 -> V_46 )
V_38 -> V_46 = V_47 ;
if ( ! V_38 -> V_48 )
V_38 -> V_48 = V_49 ;
if ( ! V_38 -> V_50 )
V_38 -> V_50 = V_51 ;
if ( ! V_38 -> V_52 )
V_38 -> V_52 = V_53 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_54 = 0 ;
int V_55 = 100 ;
while ( V_55 > 0 ) {
if ( ! ( F_5 ( V_2 , V_56 ) & V_57 ) )
break;
F_15 ( 1 ) ;
V_55 -- ;
}
if ( V_55 <= 0 ) {
F_27 ( V_2 , L_2 ) ;
V_54 = - V_58 ;
}
return V_54 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_54 = 0 ;
if ( F_8 ( V_6 ) || F_9 ( V_6 ) ) {
F_1 ( V_2 , V_59 , V_60 ) ;
F_7 ( V_2 , V_56 , V_57 , V_57 ) ;
V_54 = F_26 ( V_2 ) ;
if ( V_54 )
return V_54 ;
F_1 ( V_2 , 0x0 , V_61 ) ;
F_1 ( V_2 , 0x0 , V_62 ) ;
F_1 ( V_2 , 0x0 , V_63 ) ;
F_1 ( V_2 , 0x0 , V_64 ) ;
F_1 ( V_2 , 0x0 , V_65 ) ;
F_1 ( V_2 , 0x0 , V_66 ) ;
F_1 ( V_2 , 0x0 , V_67 ) ;
F_1 ( V_2 , 0x0 , V_68 ) ;
if ( V_6 -> V_38 -> V_69 )
F_1 ( V_2 , 0x0 , V_70 ) ;
if ( V_6 -> V_38 -> V_71 )
F_10 ( V_2 ) ;
} else {
F_7 ( V_2 , V_56 , V_72 , V_72 ) ;
F_15 ( 3 ) ;
F_7 ( V_2 , V_56 , V_72 , 0 ) ;
}
return V_54 ;
}
static void F_29 ( struct V_73 * V_74 )
{
T_3 V_75 = ( T_3 ) V_74 -> V_3 & ( V_76 - 1 ) ;
if ( V_75 )
F_30 ( V_74 , V_76 - V_75 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_1 ( V_2 ,
( V_2 -> V_77 [ 0 ] << 24 ) | ( V_2 -> V_77 [ 1 ] << 16 ) |
( V_2 -> V_77 [ 2 ] << 8 ) | ( V_2 -> V_77 [ 3 ] ) , V_78 ) ;
F_1 ( V_2 ,
( V_2 -> V_77 [ 4 ] << 8 ) | ( V_2 -> V_77 [ 5 ] ) , V_79 ) ;
}
static void F_32 ( struct V_1 * V_2 , unsigned char * V_80 )
{
if ( V_80 [ 0 ] || V_80 [ 1 ] || V_80 [ 2 ] || V_80 [ 3 ] || V_80 [ 4 ] || V_80 [ 5 ] ) {
memcpy ( V_2 -> V_77 , V_80 , V_81 ) ;
} else {
T_1 V_34 = F_5 ( V_2 , V_78 ) ;
T_1 V_35 = F_5 ( V_2 , V_79 ) ;
V_2 -> V_77 [ 0 ] = ( V_34 >> 24 ) & 0xFF ;
V_2 -> V_77 [ 1 ] = ( V_34 >> 16 ) & 0xFF ;
V_2 -> V_77 [ 2 ] = ( V_34 >> 8 ) & 0xFF ;
V_2 -> V_77 [ 3 ] = ( V_34 >> 0 ) & 0xFF ;
V_2 -> V_77 [ 4 ] = ( V_35 >> 8 ) & 0xFF ;
V_2 -> V_77 [ 5 ] = ( V_35 >> 0 ) & 0xFF ;
}
}
static T_1 F_33 ( struct V_5 * V_6 )
{
if ( F_8 ( V_6 ) || F_9 ( V_6 ) )
return V_82 ;
else
return V_83 ;
}
static void F_34 ( struct V_84 * V_85 , T_1 V_86 , int V_12 )
{
struct V_87 * V_88 = F_35 ( V_85 , struct V_87 , V_85 ) ;
T_1 V_89 ;
if ( V_88 -> V_90 )
V_88 -> V_90 ( V_88 -> V_10 ) ;
V_89 = F_6 ( V_88 -> V_10 ) ;
if ( V_12 )
V_89 |= V_86 ;
else
V_89 &= ~ V_86 ;
F_4 ( V_89 , V_88 -> V_10 ) ;
}
static void F_36 ( struct V_84 * V_85 , int V_91 )
{
F_34 ( V_85 , V_92 , V_91 ) ;
}
static void F_37 ( struct V_84 * V_85 , int V_91 )
{
F_34 ( V_85 , V_93 , V_91 ) ;
}
static int F_38 ( struct V_84 * V_85 )
{
struct V_87 * V_88 = F_35 ( V_85 , struct V_87 , V_85 ) ;
if ( V_88 -> V_90 )
V_88 -> V_90 ( V_88 -> V_10 ) ;
return ( F_6 ( V_88 -> V_10 ) & V_94 ) != 0 ;
}
static void F_39 ( struct V_84 * V_85 , int V_91 )
{
F_34 ( V_85 , V_95 , V_91 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_96 , V_36 ;
if ( V_6 -> V_97 ) {
for ( V_36 = 0 ; V_36 < V_6 -> V_98 ; V_36 ++ )
F_41 ( V_6 -> V_97 [ V_36 ] ) ;
}
F_42 ( V_6 -> V_97 ) ;
V_6 -> V_97 = NULL ;
if ( V_6 -> V_99 ) {
for ( V_36 = 0 ; V_36 < V_6 -> V_100 ; V_36 ++ )
F_41 ( V_6 -> V_99 [ V_36 ] ) ;
}
F_42 ( V_6 -> V_99 ) ;
V_6 -> V_99 = NULL ;
if ( V_6 -> V_101 ) {
V_96 = sizeof( struct V_102 ) * V_6 -> V_98 ;
F_43 ( NULL , V_96 , V_6 -> V_101 ,
V_6 -> V_103 ) ;
V_6 -> V_101 = NULL ;
}
if ( V_6 -> V_104 ) {
V_96 = sizeof( struct V_105 ) * V_6 -> V_100 ;
F_43 ( NULL , V_96 , V_6 -> V_104 ,
V_6 -> V_106 ) ;
V_6 -> V_104 = NULL ;
}
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_36 ;
struct V_73 * V_74 ;
struct V_102 * V_107 = NULL ;
struct V_105 * V_108 = NULL ;
int V_109 = sizeof( * V_107 ) * V_6 -> V_98 ;
int V_110 = sizeof( * V_108 ) * V_6 -> V_100 ;
int V_111 = V_6 -> V_112 + V_76 + 32 - 1 ;
T_4 V_113 ;
T_1 V_114 ;
V_6 -> V_115 = 0 ;
V_6 -> V_116 = 0 ;
V_6 -> V_117 = 0 ;
V_6 -> V_118 = 0 ;
memset ( V_6 -> V_101 , 0 , V_109 ) ;
for ( V_36 = 0 ; V_36 < V_6 -> V_98 ; V_36 ++ ) {
V_6 -> V_97 [ V_36 ] = NULL ;
V_74 = F_45 ( V_2 , V_111 ) ;
if ( V_74 == NULL )
break;
F_29 ( V_74 ) ;
V_114 = F_46 ( V_6 -> V_112 , 32 ) ;
V_113 = F_47 ( & V_2 -> V_119 , V_74 -> V_3 , V_114 ,
V_120 ) ;
if ( F_48 ( & V_2 -> V_119 , V_113 ) ) {
F_49 ( V_74 ) ;
break;
}
V_6 -> V_97 [ V_36 ] = V_74 ;
V_107 = & V_6 -> V_101 [ V_36 ] ;
V_107 -> V_121 = F_50 ( V_114 << 16 ) ;
V_107 -> V_10 = F_50 ( V_113 ) ;
V_107 -> V_122 = F_50 ( V_123 | V_124 ) ;
if ( V_36 == 0 ) {
F_1 ( V_2 , V_6 -> V_103 , V_65 ) ;
if ( F_8 ( V_6 ) ||
F_9 ( V_6 ) )
F_1 ( V_2 , V_6 -> V_103 , V_66 ) ;
}
}
V_6 -> V_117 = ( T_1 ) ( V_36 - V_6 -> V_98 ) ;
if ( V_107 )
V_107 -> V_122 |= F_50 ( V_125 ) ;
memset ( V_6 -> V_104 , 0 , V_110 ) ;
for ( V_36 = 0 ; V_36 < V_6 -> V_100 ; V_36 ++ ) {
V_6 -> V_99 [ V_36 ] = NULL ;
V_108 = & V_6 -> V_104 [ V_36 ] ;
V_108 -> V_122 = F_50 ( V_126 ) ;
V_108 -> V_121 = F_50 ( 0 ) ;
if ( V_36 == 0 ) {
F_1 ( V_2 , V_6 -> V_106 , V_61 ) ;
if ( F_8 ( V_6 ) ||
F_9 ( V_6 ) )
F_1 ( V_2 , V_6 -> V_106 , V_62 ) ;
}
}
V_108 -> V_122 |= F_50 ( V_127 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_109 , V_110 ;
V_6 -> V_112 = ( V_2 -> V_128 <= 1492 ? V_129 :
( ( ( V_2 -> V_128 + 26 + 7 ) & ~ 7 ) + 2 + 16 ) ) ;
if ( V_6 -> V_38 -> V_130 )
V_6 -> V_112 += V_131 ;
V_6 -> V_97 = F_52 ( V_6 -> V_98 , sizeof( * V_6 -> V_97 ) ,
V_132 ) ;
if ( ! V_6 -> V_97 )
return - V_133 ;
V_6 -> V_99 = F_52 ( V_6 -> V_100 , sizeof( * V_6 -> V_99 ) ,
V_132 ) ;
if ( ! V_6 -> V_99 )
goto V_134;
V_109 = sizeof( struct V_102 ) * V_6 -> V_98 ;
V_6 -> V_101 = F_53 ( NULL , V_109 , & V_6 -> V_103 ,
V_132 ) ;
if ( ! V_6 -> V_101 )
goto V_134;
V_6 -> V_117 = 0 ;
V_110 = sizeof( struct V_105 ) * V_6 -> V_100 ;
V_6 -> V_104 = F_53 ( NULL , V_110 , & V_6 -> V_106 ,
V_132 ) ;
if ( ! V_6 -> V_104 )
goto V_134;
return 0 ;
V_134:
F_40 ( V_2 ) ;
return - V_133 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_54 ;
V_54 = F_28 ( V_2 ) ;
if ( V_54 )
return V_54 ;
if ( V_6 -> V_38 -> V_135 )
F_1 ( V_2 , 0x1 , V_136 ) ;
F_44 ( V_2 ) ;
if ( V_6 -> V_38 -> V_130 )
F_1 ( V_2 , V_6 -> V_38 -> V_137 , V_138 ) ;
F_1 ( V_2 , 0 , V_139 ) ;
#if F_55 ( V_140 )
if ( V_6 -> V_38 -> V_141 )
F_1 ( V_2 , V_142 , V_56 ) ;
else
#endif
F_1 ( V_2 , 0 , V_56 ) ;
F_1 ( V_2 , V_6 -> V_38 -> V_46 , V_143 ) ;
F_1 ( V_2 , 0 , V_144 ) ;
F_1 ( V_2 , V_145 , V_146 ) ;
F_1 ( V_2 , V_6 -> V_38 -> V_52 , V_147 ) ;
if ( V_6 -> V_38 -> V_148 )
F_1 ( V_2 , 0x800 , V_149 ) ;
F_1 ( V_2 , V_6 -> V_38 -> V_43 , V_150 ) ;
if ( ! V_6 -> V_38 -> V_151 )
F_1 ( V_2 , 0 , V_152 ) ;
F_1 ( V_2 , V_2 -> V_128 + V_153 + V_154 + V_155 ,
V_156 ) ;
F_7 ( V_2 , V_157 , 0 , 0 ) ;
V_6 -> V_158 = true ;
F_1 ( V_2 , V_6 -> V_38 -> V_159 , V_139 ) ;
F_1 ( V_2 , V_160 | ( V_6 -> V_23 ? V_22 : 0 ) |
V_161 | V_162 , V_21 ) ;
if ( V_6 -> V_38 -> V_163 )
V_6 -> V_38 -> V_163 ( V_2 ) ;
F_1 ( V_2 , V_6 -> V_38 -> V_39 , V_164 ) ;
F_1 ( V_2 , V_6 -> V_38 -> V_41 , V_165 ) ;
F_31 ( V_2 ) ;
if ( V_6 -> V_38 -> V_166 )
F_1 ( V_2 , V_167 , V_168 ) ;
if ( V_6 -> V_38 -> V_169 )
F_1 ( V_2 , V_170 , V_171 ) ;
if ( V_6 -> V_38 -> V_172 )
F_1 ( V_2 , V_173 , V_174 ) ;
F_1 ( V_2 , V_175 , V_176 ) ;
return V_54 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_6 -> V_100 ; V_36 ++ )
V_6 -> V_104 [ V_36 ] . V_122 &= ~ F_50 ( V_177 ) ;
F_57 ( V_2 ) ;
F_1 ( V_2 , 0 , V_176 ) ;
F_58 ( 2 ) ;
F_59 ( V_2 ) ;
F_28 ( V_2 ) ;
F_31 ( V_2 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_105 * V_108 ;
int V_178 = 0 ;
int V_179 ;
for (; V_6 -> V_116 - V_6 -> V_118 > 0 ; V_6 -> V_118 ++ ) {
V_179 = V_6 -> V_118 % V_6 -> V_100 ;
V_108 = & V_6 -> V_104 [ V_179 ] ;
if ( V_108 -> V_122 & F_50 ( V_177 ) )
break;
F_61 () ;
F_62 ( V_6 , V_180 , V_2 ,
L_3 ,
V_179 , F_63 ( V_108 -> V_122 ) ) ;
if ( V_6 -> V_99 [ V_179 ] ) {
F_64 ( & V_2 -> V_119 , F_63 ( V_108 -> V_10 ) ,
F_63 ( V_108 -> V_121 ) >> 16 ,
V_181 ) ;
F_65 ( V_6 -> V_99 [ V_179 ] ) ;
V_6 -> V_99 [ V_179 ] = NULL ;
V_178 ++ ;
}
V_108 -> V_122 = F_50 ( V_126 ) ;
if ( V_179 >= V_6 -> V_100 - 1 )
V_108 -> V_122 |= F_50 ( V_127 ) ;
V_2 -> V_182 . V_183 ++ ;
V_2 -> V_182 . V_184 += F_63 ( V_108 -> V_121 ) >> 16 ;
}
return V_178 ;
}
static int F_66 ( struct V_1 * V_2 , T_1 V_185 , int * V_186 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_102 * V_107 ;
int V_179 = V_6 -> V_115 % V_6 -> V_98 ;
int V_187 = ( V_6 -> V_117 + V_6 -> V_98 ) - V_6 -> V_115 ;
int V_188 ;
struct V_73 * V_74 ;
T_1 V_189 ;
int V_111 = V_6 -> V_112 + V_76 + 32 - 1 ;
T_4 V_113 ;
T_2 V_190 ;
T_1 V_114 ;
V_187 = F_67 ( V_187 , * V_186 ) ;
V_188 = V_187 ;
V_107 = & V_6 -> V_101 [ V_179 ] ;
while ( ! ( V_107 -> V_122 & F_50 ( V_123 ) ) ) {
F_61 () ;
V_189 = F_63 ( V_107 -> V_122 ) ;
V_190 = F_63 ( V_107 -> V_121 ) & V_191 ;
if ( -- V_187 < 0 )
break;
F_62 ( V_6 , V_192 , V_2 ,
L_4 ,
V_179 , V_189 , V_190 ) ;
if ( ! ( V_189 & V_193 ) )
V_2 -> V_182 . V_194 ++ ;
if ( V_6 -> V_38 -> V_195 )
V_189 >>= 16 ;
V_74 = V_6 -> V_97 [ V_179 ] ;
if ( V_189 & ( V_196 | V_197 | V_198 | V_199 |
V_200 | V_201 | V_202 ) ) {
V_2 -> V_182 . V_203 ++ ;
if ( V_189 & V_196 )
V_2 -> V_182 . V_204 ++ ;
if ( V_189 & V_197 )
V_2 -> V_182 . V_205 ++ ;
if ( V_189 & V_198 )
V_2 -> V_182 . V_194 ++ ;
if ( V_189 & V_199 )
V_2 -> V_182 . V_194 ++ ;
if ( V_189 & V_201 )
V_2 -> V_182 . V_206 ++ ;
if ( V_189 & V_202 )
V_2 -> V_182 . V_207 ++ ;
} else if ( V_74 ) {
V_113 = F_63 ( V_107 -> V_10 ) ;
if ( ! V_6 -> V_38 -> V_141 )
F_68 (
F_69 ( F_46 ( V_113 , 4 ) ) ,
V_190 + 2 ) ;
V_6 -> V_97 [ V_179 ] = NULL ;
if ( V_6 -> V_38 -> V_130 )
F_30 ( V_74 , V_131 ) ;
F_64 ( & V_2 -> V_119 , V_113 ,
F_46 ( V_6 -> V_112 , 32 ) ,
V_120 ) ;
F_70 ( V_74 , V_190 ) ;
V_74 -> V_208 = F_71 ( V_74 , V_2 ) ;
F_72 ( V_74 ) ;
V_2 -> V_182 . V_209 ++ ;
V_2 -> V_182 . V_210 += V_190 ;
if ( V_189 & V_211 )
V_2 -> V_182 . V_212 ++ ;
}
V_179 = ( ++ V_6 -> V_115 ) % V_6 -> V_98 ;
V_107 = & V_6 -> V_101 [ V_179 ] ;
}
for (; V_6 -> V_115 - V_6 -> V_117 > 0 ; V_6 -> V_117 ++ ) {
V_179 = V_6 -> V_117 % V_6 -> V_98 ;
V_107 = & V_6 -> V_101 [ V_179 ] ;
V_114 = F_46 ( V_6 -> V_112 , 32 ) ;
V_107 -> V_121 = F_50 ( V_114 << 16 ) ;
if ( V_6 -> V_97 [ V_179 ] == NULL ) {
V_74 = F_45 ( V_2 , V_111 ) ;
if ( V_74 == NULL )
break;
F_29 ( V_74 ) ;
V_113 = F_47 ( & V_2 -> V_119 , V_74 -> V_3 ,
V_114 , V_120 ) ;
if ( F_48 ( & V_2 -> V_119 , V_113 ) ) {
F_49 ( V_74 ) ;
break;
}
V_6 -> V_97 [ V_179 ] = V_74 ;
F_73 ( V_74 ) ;
V_107 -> V_10 = F_50 ( V_113 ) ;
}
F_74 () ;
if ( V_179 >= V_6 -> V_98 - 1 )
V_107 -> V_122 |=
F_50 ( V_123 | V_124 | V_125 ) ;
else
V_107 -> V_122 |= F_50 ( V_123 | V_124 ) ;
}
if ( ! ( F_5 ( V_2 , V_176 ) & V_175 ) ) {
if ( V_185 & V_213 &&
V_6 -> V_8 [ V_66 ] != V_9 ) {
T_1 V_214 = ( F_5 ( V_2 , V_66 ) -
F_5 ( V_2 , V_65 ) ) >> 4 ;
V_6 -> V_115 = V_214 ;
V_6 -> V_117 = V_214 ;
}
F_1 ( V_2 , V_175 , V_176 ) ;
}
* V_186 -= V_188 - V_187 - 1 ;
return * V_186 <= 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_21 , V_162 | V_161 , 0 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_21 , V_162 | V_161 , V_162 | V_161 ) ;
}
static void F_76 ( struct V_1 * V_2 , T_1 V_185 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_215 ;
T_1 V_216 ;
T_1 V_86 ;
if ( V_185 & V_217 ) {
V_215 = F_5 ( V_2 , V_164 ) ;
F_1 ( V_2 , V_215 , V_164 ) ;
if ( V_215 & V_218 )
V_2 -> V_182 . V_219 ++ ;
if ( V_215 & V_220 ) {
if ( V_6 -> V_38 -> V_221 || V_6 -> V_222 ) {
goto V_223;
} else {
V_216 = ( F_5 ( V_2 , V_224 ) ) ;
if ( V_6 -> V_225 )
V_216 = ~ V_216 ;
}
if ( ! ( V_216 & V_226 ) ) {
F_57 ( V_2 ) ;
} else {
F_7 ( V_2 , V_139 , V_227 , 0 ) ;
F_7 ( V_2 , V_164 , 0 , 0 ) ;
F_7 ( V_2 , V_139 , V_227 ,
V_227 ) ;
F_75 ( V_2 ) ;
}
}
}
V_223:
if ( V_185 & V_228 ) {
if ( V_185 & V_229 ) {
V_2 -> V_182 . V_230 ++ ;
F_77 ( V_6 , V_231 , V_2 , L_5 ) ;
}
}
if ( V_185 & V_232 ) {
if ( V_185 & V_233 ) {
V_2 -> V_182 . V_205 ++ ;
}
}
if ( V_185 & V_234 ) {
V_2 -> V_182 . V_235 ++ ;
F_77 ( V_6 , V_231 , V_2 , L_6 ) ;
}
if ( V_185 & V_236 ) {
V_2 -> V_182 . V_235 ++ ;
F_77 ( V_6 , V_231 , V_2 , L_7 ) ;
}
if ( V_185 & V_213 ) {
V_2 -> V_182 . V_207 ++ ;
}
if ( V_185 & V_237 ) {
V_2 -> V_182 . V_238 ++ ;
}
if ( ! V_6 -> V_38 -> V_239 && ( V_185 & V_240 ) ) {
V_2 -> V_182 . V_235 ++ ;
F_77 ( V_6 , V_231 , V_2 , L_8 ) ;
}
V_86 = V_228 | V_229 | V_240 | V_234 | V_236 ;
if ( V_6 -> V_38 -> V_239 )
V_86 &= ~ V_240 ;
if ( V_185 & V_86 ) {
T_1 V_241 = F_5 ( V_2 , V_242 ) ;
F_27 ( V_2 , L_9 ,
V_185 , V_6 -> V_116 , V_6 -> V_118 ,
( T_1 ) V_2 -> V_243 , V_241 ) ;
F_60 ( V_2 ) ;
if ( V_241 ^ F_33 ( V_6 ) ) {
F_1 ( V_2 , F_33 ( V_6 ) , V_242 ) ;
}
F_78 ( V_2 ) ;
}
}
static T_5 F_79 ( int V_244 , void * V_245 )
{
struct V_1 * V_2 = V_245 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_37 * V_38 = V_6 -> V_38 ;
T_5 V_54 = V_246 ;
T_1 V_185 , V_247 ;
F_80 ( & V_6 -> V_248 ) ;
V_185 = F_5 ( V_2 , V_157 ) ;
V_247 = F_5 ( V_2 , V_139 ) ;
V_185 &= V_247 | V_227 ;
if ( V_185 & ( V_249 | V_38 -> V_48 | V_38 -> V_50 ) )
V_54 = V_250 ;
else
goto V_251;
if ( F_81 ( ! V_6 -> V_158 ) ) {
F_1 ( V_2 , 0 , V_139 ) ;
goto V_251;
}
if ( V_185 & V_249 ) {
if ( F_82 ( & V_6 -> V_252 ) ) {
F_1 ( V_2 , V_247 & ~ V_249 ,
V_139 ) ;
F_83 ( & V_6 -> V_252 ) ;
} else {
F_11 ( V_2 ,
L_10 ,
V_185 , V_247 ) ;
}
}
if ( V_185 & V_38 -> V_48 ) {
F_1 ( V_2 , V_185 & V_38 -> V_48 , V_157 ) ;
F_60 ( V_2 ) ;
F_78 ( V_2 ) ;
}
if ( V_185 & V_38 -> V_50 ) {
F_1 ( V_2 , V_185 & V_38 -> V_50 , V_157 ) ;
F_76 ( V_2 , V_185 ) ;
}
V_251:
F_84 ( & V_6 -> V_248 ) ;
return V_54 ;
}
static int F_85 ( struct V_253 * V_252 , int V_254 )
{
struct V_5 * V_6 = F_35 ( V_252 , struct V_5 ,
V_252 ) ;
struct V_1 * V_2 = V_252 -> V_119 ;
int V_186 = V_254 ;
T_1 V_185 ;
for (; ; ) {
V_185 = F_5 ( V_2 , V_157 ) ;
if ( ! ( V_185 & V_249 ) )
break;
F_1 ( V_2 , V_185 & V_249 , V_157 ) ;
if ( F_66 ( V_2 , V_185 , & V_186 ) )
goto V_251;
}
F_86 ( V_252 ) ;
if ( V_6 -> V_158 )
F_1 ( V_2 , V_6 -> V_38 -> V_159 , V_139 ) ;
V_251:
return V_254 - V_186 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_255 * V_256 = V_2 -> V_256 ;
int V_257 = 0 ;
if ( V_256 -> V_258 ) {
if ( V_256 -> V_23 != V_6 -> V_23 ) {
V_257 = 1 ;
V_6 -> V_23 = V_256 -> V_23 ;
if ( V_6 -> V_38 -> V_259 )
V_6 -> V_38 -> V_259 ( V_2 ) ;
}
if ( V_256 -> V_26 != V_6 -> V_26 ) {
V_257 = 1 ;
V_6 -> V_26 = V_256 -> V_26 ;
if ( V_6 -> V_38 -> V_163 )
V_6 -> V_38 -> V_163 ( V_2 ) ;
}
if ( ! V_6 -> V_258 ) {
F_7 ( V_2 , V_21 , V_260 , 0 ) ;
V_257 = 1 ;
V_6 -> V_258 = V_256 -> V_258 ;
if ( V_6 -> V_38 -> V_221 || V_6 -> V_222 )
F_75 ( V_2 ) ;
}
} else if ( V_6 -> V_258 ) {
V_257 = 1 ;
V_6 -> V_258 = 0 ;
V_6 -> V_26 = 0 ;
V_6 -> V_23 = - 1 ;
if ( V_6 -> V_38 -> V_221 || V_6 -> V_222 )
F_57 ( V_2 ) ;
}
if ( V_257 && F_88 ( V_6 ) )
F_89 ( V_256 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_261 * V_262 = V_2 -> V_119 . V_263 -> V_264 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_255 * V_256 ;
V_6 -> V_258 = 0 ;
V_6 -> V_26 = 0 ;
V_6 -> V_23 = - 1 ;
if ( V_262 ) {
struct V_261 * V_265 ;
V_265 = F_91 ( V_262 , L_11 , 0 ) ;
V_256 = F_92 ( V_2 , V_265 ,
F_87 , 0 ,
V_6 -> V_16 ) ;
F_93 ( V_265 ) ;
if ( ! V_256 )
V_256 = F_94 ( - V_266 ) ;
} else {
char V_267 [ V_268 + 3 ] ;
snprintf ( V_267 , sizeof( V_267 ) , V_269 ,
V_6 -> V_270 -> V_271 , V_6 -> V_267 ) ;
V_256 = F_95 ( V_2 , V_267 , F_87 ,
V_6 -> V_16 ) ;
}
if ( F_96 ( V_256 ) ) {
F_27 ( V_2 , L_12 ) ;
return F_97 ( V_256 ) ;
}
F_98 ( V_256 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_54 ;
V_54 = F_90 ( V_2 ) ;
if ( V_54 )
return V_54 ;
F_100 ( V_2 -> V_256 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_272 * V_273 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_274 ;
int V_54 ;
if ( ! V_2 -> V_256 )
return - V_275 ;
F_102 ( & V_6 -> V_248 , V_274 ) ;
V_54 = F_103 ( V_2 -> V_256 , V_273 ) ;
F_104 ( & V_6 -> V_248 , V_274 ) ;
return V_54 ;
}
static int F_105 ( struct V_1 * V_2 ,
const struct V_272 * V_273 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_274 ;
int V_54 ;
if ( ! V_2 -> V_256 )
return - V_275 ;
F_102 ( & V_6 -> V_248 , V_274 ) ;
F_57 ( V_2 ) ;
V_54 = F_106 ( V_2 -> V_256 , V_273 ) ;
if ( V_54 )
goto V_276;
if ( V_273 -> V_277 . V_23 == V_278 )
V_6 -> V_23 = 1 ;
else
V_6 -> V_23 = 0 ;
if ( V_6 -> V_38 -> V_259 )
V_6 -> V_38 -> V_259 ( V_2 ) ;
V_276:
F_15 ( 1 ) ;
F_75 ( V_2 ) ;
F_104 ( & V_6 -> V_248 , V_274 ) ;
return V_54 ;
}
static T_6 F_107 ( struct V_1 * V_2 , T_1 * V_279 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_37 * V_38 = V_6 -> V_38 ;
T_1 * V_280 ;
T_6 V_121 ;
F_108 ( V_281 > V_282 ) ;
V_121 = F_109 ( V_282 , 32 ) ;
if ( V_279 ) {
V_280 = V_279 ;
V_279 += V_121 ;
} else {
V_280 = NULL ;
}
#define F_110 ( T_7 ) valid_map[reg / 32] |= 1U << (reg % 32)
#define F_111 ( T_7 , T_8 ) do { \
if (mdp->reg_offset[reg] != SH_ETH_OFFSET_INVALID) { \
if (buf) { \
mark_reg_valid(reg); \
*buf++ = read_expr; \
} \
++len; \
} \
} while (0)
#define F_112 ( T_7 ) add_reg_from(reg, sh_eth_read(ndev, reg))
#define F_113 ( T_7 ) add_reg_from(reg, sh_eth_tsu_read(mdp, reg))
F_112 ( V_60 ) ;
F_112 ( V_56 ) ;
F_112 ( V_242 ) ;
F_112 ( V_176 ) ;
F_112 ( V_157 ) ;
F_112 ( V_139 ) ;
F_112 ( V_61 ) ;
F_112 ( V_62 ) ;
F_112 ( V_63 ) ;
F_112 ( V_64 ) ;
F_112 ( V_65 ) ;
F_112 ( V_66 ) ;
F_112 ( V_67 ) ;
F_112 ( V_68 ) ;
F_112 ( V_147 ) ;
F_112 ( V_283 ) ;
F_112 ( V_144 ) ;
F_112 ( V_143 ) ;
F_112 ( V_146 ) ;
F_112 ( V_284 ) ;
F_112 ( V_285 ) ;
if ( V_38 -> V_135 )
F_112 ( V_136 ) ;
F_112 ( V_150 ) ;
if ( V_38 -> V_130 )
F_112 ( V_138 ) ;
if ( ! V_38 -> V_151 )
F_112 ( V_152 ) ;
F_112 ( V_21 ) ;
F_112 ( V_164 ) ;
F_112 ( V_165 ) ;
F_112 ( V_286 ) ;
if ( ! V_38 -> V_221 )
F_112 ( V_224 ) ;
F_112 ( V_287 ) ;
F_112 ( V_156 ) ;
F_112 ( V_288 ) ;
if ( V_38 -> V_166 )
F_112 ( V_168 ) ;
if ( V_38 -> V_169 )
F_112 ( V_171 ) ;
F_112 ( V_289 ) ;
F_112 ( V_290 ) ;
if ( V_38 -> V_172 )
F_112 ( V_174 ) ;
F_112 ( V_291 ) ;
F_112 ( V_28 ) ;
if ( V_38 -> V_148 )
F_112 ( V_149 ) ;
F_112 ( V_78 ) ;
F_112 ( V_79 ) ;
F_112 ( V_292 ) ;
F_112 ( V_293 ) ;
F_112 ( V_294 ) ;
F_112 ( V_295 ) ;
F_112 ( V_296 ) ;
F_112 ( V_297 ) ;
F_112 ( V_298 ) ;
F_112 ( V_299 ) ;
F_112 ( V_300 ) ;
F_112 ( V_301 ) ;
F_112 ( V_302 ) ;
if ( V_38 -> V_303 )
F_112 ( V_33 ) ;
if ( V_38 -> V_69 )
F_112 ( V_70 ) ;
if ( V_38 -> V_71 )
F_112 ( V_20 ) ;
F_112 ( V_25 ) ;
if ( V_38 -> V_304 ) {
F_113 ( V_305 ) ;
F_113 ( V_306 ) ;
F_113 ( V_307 ) ;
F_113 ( V_308 ) ;
F_113 ( V_309 ) ;
F_113 ( V_310 ) ;
F_113 ( V_311 ) ;
F_113 ( V_312 ) ;
F_113 ( V_313 ) ;
F_113 ( V_314 ) ;
F_113 ( V_315 ) ;
F_113 ( V_316 ) ;
F_113 ( V_317 ) ;
F_113 ( V_318 ) ;
F_113 ( V_319 ) ;
F_113 ( V_320 ) ;
F_113 ( V_321 ) ;
F_113 ( V_322 ) ;
F_113 ( V_323 ) ;
F_113 ( V_324 ) ;
F_113 ( V_325 ) ;
F_113 ( V_326 ) ;
F_113 ( V_327 ) ;
F_113 ( V_328 ) ;
F_113 ( V_329 ) ;
F_113 ( V_330 ) ;
F_113 ( V_331 ) ;
if ( V_6 -> V_8 [ V_332 ] != V_9 ) {
if ( V_279 ) {
unsigned int V_36 ;
F_110 ( V_332 ) ;
for ( V_36 = 0 ; V_36 < V_333 * 2 ; V_36 ++ )
* V_279 ++ = F_6 (
V_6 -> V_334 +
V_6 -> V_8 [ V_332 ] +
V_36 * 4 ) ;
}
V_121 += V_333 * 2 ;
}
}
#undef F_110
#undef F_111
#undef F_112
#undef F_113
return V_121 * 4 ;
}
static int F_114 ( struct V_1 * V_2 )
{
return F_107 ( V_2 , NULL ) ;
}
static void F_115 ( struct V_1 * V_2 , struct V_335 * V_336 ,
void * V_279 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_336 -> V_337 = V_338 ;
F_116 ( & V_6 -> V_339 -> V_119 ) ;
F_107 ( V_2 , V_279 ) ;
F_117 ( & V_6 -> V_339 -> V_119 ) ;
}
static int F_118 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_274 ;
int V_54 ;
if ( ! V_2 -> V_256 )
return - V_275 ;
F_102 ( & V_6 -> V_248 , V_274 ) ;
V_54 = F_119 ( V_2 -> V_256 ) ;
F_104 ( & V_6 -> V_248 , V_274 ) ;
return V_54 ;
}
static T_1 F_120 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_340 ;
}
static void F_121 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_340 = V_15 ;
}
static int F_122 ( struct V_1 * V_245 , int V_341 )
{
switch ( V_341 ) {
case V_342 :
return V_343 ;
default:
return - V_344 ;
}
}
static void F_123 ( struct V_1 * V_2 ,
struct V_345 * V_182 , T_9 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_36 = 0 ;
V_3 [ V_36 ++ ] = V_6 -> V_115 ;
V_3 [ V_36 ++ ] = V_6 -> V_116 ;
V_3 [ V_36 ++ ] = V_6 -> V_117 ;
V_3 [ V_36 ++ ] = V_6 -> V_118 ;
}
static void F_124 ( struct V_1 * V_2 , T_1 V_346 , T_10 * V_3 )
{
switch ( V_346 ) {
case V_342 :
memcpy ( V_3 , * V_347 ,
sizeof( V_347 ) ) ;
break;
}
}
static void F_125 ( struct V_1 * V_2 ,
struct V_348 * V_349 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_349 -> V_350 = V_351 ;
V_349 -> V_352 = V_353 ;
V_349 -> V_354 = V_6 -> V_98 ;
V_349 -> V_355 = V_6 -> V_100 ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_348 * V_349 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_54 ;
if ( V_349 -> V_355 > V_353 ||
V_349 -> V_354 > V_351 ||
V_349 -> V_355 < V_356 ||
V_349 -> V_354 < V_357 )
return - V_358 ;
if ( V_349 -> V_359 || V_349 -> V_360 )
return - V_358 ;
if ( F_127 ( V_2 ) ) {
F_128 ( V_2 ) ;
F_129 ( V_2 ) ;
V_6 -> V_158 = false ;
F_130 ( V_2 -> V_244 ) ;
F_131 ( & V_6 -> V_252 ) ;
F_1 ( V_2 , 0x0000 , V_139 ) ;
F_56 ( V_2 ) ;
F_40 ( V_2 ) ;
}
V_6 -> V_98 = V_349 -> V_354 ;
V_6 -> V_100 = V_349 -> V_355 ;
if ( F_127 ( V_2 ) ) {
V_54 = F_51 ( V_2 ) ;
if ( V_54 < 0 ) {
F_27 ( V_2 , L_13 ,
V_361 ) ;
return V_54 ;
}
V_54 = F_54 ( V_2 ) ;
if ( V_54 < 0 ) {
F_27 ( V_2 , L_14 ,
V_361 ) ;
return V_54 ;
}
F_132 ( V_2 ) ;
}
return 0 ;
}
static int F_133 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_54 ;
F_116 ( & V_6 -> V_339 -> V_119 ) ;
F_134 ( & V_6 -> V_252 ) ;
V_54 = F_135 ( V_2 -> V_244 , F_79 ,
V_6 -> V_38 -> V_362 , V_2 -> V_363 , V_2 ) ;
if ( V_54 ) {
F_27 ( V_2 , L_15 ) ;
goto V_364;
}
V_54 = F_51 ( V_2 ) ;
if ( V_54 )
goto V_365;
V_54 = F_54 ( V_2 ) ;
if ( V_54 )
goto V_365;
V_54 = F_99 ( V_2 ) ;
if ( V_54 )
goto V_365;
F_136 ( V_2 ) ;
V_6 -> V_366 = 1 ;
return V_54 ;
V_365:
F_137 ( V_2 -> V_244 , V_2 ) ;
V_364:
F_138 ( & V_6 -> V_252 ) ;
F_117 ( & V_6 -> V_339 -> V_119 ) ;
return V_54 ;
}
static void F_139 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_102 * V_107 ;
int V_36 ;
F_140 ( V_2 ) ;
F_77 ( V_6 , V_367 , V_2 ,
L_16 ,
F_5 ( V_2 , V_157 ) ) ;
V_2 -> V_182 . V_368 ++ ;
for ( V_36 = 0 ; V_36 < V_6 -> V_98 ; V_36 ++ ) {
V_107 = & V_6 -> V_101 [ V_36 ] ;
V_107 -> V_122 = F_50 ( 0 ) ;
V_107 -> V_10 = F_50 ( 0xBADF00D0 ) ;
F_41 ( V_6 -> V_97 [ V_36 ] ) ;
V_6 -> V_97 [ V_36 ] = NULL ;
}
for ( V_36 = 0 ; V_36 < V_6 -> V_100 ; V_36 ++ ) {
F_41 ( V_6 -> V_99 [ V_36 ] ) ;
V_6 -> V_99 [ V_36 ] = NULL ;
}
F_54 ( V_2 ) ;
F_136 ( V_2 ) ;
}
static int F_141 ( struct V_73 * V_74 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_105 * V_108 ;
T_4 V_113 ;
T_1 V_179 ;
unsigned long V_274 ;
F_102 ( & V_6 -> V_248 , V_274 ) ;
if ( ( V_6 -> V_116 - V_6 -> V_118 ) >= ( V_6 -> V_100 - 4 ) ) {
if ( ! F_60 ( V_2 ) ) {
F_142 ( V_6 , V_369 , V_2 , L_17 ) ;
F_140 ( V_2 ) ;
F_104 ( & V_6 -> V_248 , V_274 ) ;
return V_370 ;
}
}
F_104 ( & V_6 -> V_248 , V_274 ) ;
if ( F_143 ( V_74 , V_371 ) )
return V_372 ;
V_179 = V_6 -> V_116 % V_6 -> V_100 ;
V_6 -> V_99 [ V_179 ] = V_74 ;
V_108 = & V_6 -> V_104 [ V_179 ] ;
if ( ! V_6 -> V_38 -> V_141 )
F_68 ( F_144 ( V_74 -> V_3 , 4 ) , V_74 -> V_121 + 2 ) ;
V_113 = F_47 ( & V_2 -> V_119 , V_74 -> V_3 , V_74 -> V_121 ,
V_181 ) ;
if ( F_48 ( & V_2 -> V_119 , V_113 ) ) {
F_49 ( V_74 ) ;
return V_372 ;
}
V_108 -> V_10 = F_50 ( V_113 ) ;
V_108 -> V_121 = F_50 ( V_74 -> V_121 << 16 ) ;
F_74 () ;
if ( V_179 >= V_6 -> V_100 - 1 )
V_108 -> V_122 |= F_50 ( V_177 | V_127 ) ;
else
V_108 -> V_122 |= F_50 ( V_177 ) ;
V_6 -> V_116 ++ ;
if ( ! ( F_5 ( V_2 , V_242 ) & F_33 ( V_6 ) ) )
F_1 ( V_2 , F_33 ( V_6 ) , V_242 ) ;
return V_372 ;
}
static void
F_145 ( struct V_1 * V_2 , unsigned long * V_373 , int T_7 )
{
T_1 V_374 = F_5 ( V_2 , T_7 ) ;
if ( V_374 ) {
* V_373 += V_374 ;
F_1 ( V_2 , 0 , T_7 ) ;
}
}
static struct V_375 * F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_9 ( V_6 ) )
return & V_2 -> V_182 ;
if ( ! V_6 -> V_366 )
return & V_2 -> V_182 ;
F_145 ( V_2 , & V_2 -> V_182 . V_376 , V_292 ) ;
F_145 ( V_2 , & V_2 -> V_182 . V_377 , V_293 ) ;
F_145 ( V_2 , & V_2 -> V_182 . V_219 , V_294 ) ;
if ( F_8 ( V_6 ) ) {
F_145 ( V_2 , & V_2 -> V_182 . V_219 ,
V_300 ) ;
F_145 ( V_2 , & V_2 -> V_182 . V_219 ,
V_301 ) ;
} else {
F_145 ( V_2 , & V_2 -> V_182 . V_219 ,
V_295 ) ;
}
return & V_2 -> V_182 ;
}
static int F_146 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_140 ( V_2 ) ;
V_6 -> V_158 = false ;
F_130 ( V_2 -> V_244 ) ;
F_138 ( & V_6 -> V_252 ) ;
F_1 ( V_2 , 0x0000 , V_139 ) ;
F_56 ( V_2 ) ;
if ( V_2 -> V_256 ) {
F_147 ( V_2 -> V_256 ) ;
F_148 ( V_2 -> V_256 ) ;
}
F_137 ( V_2 -> V_244 , V_2 ) ;
F_40 ( V_2 ) ;
F_117 ( & V_6 -> V_339 -> V_119 ) ;
V_6 -> V_366 = 0 ;
return 0 ;
}
static int F_149 ( struct V_1 * V_2 , struct V_378 * V_379 , int V_273 )
{
struct V_255 * V_256 = V_2 -> V_256 ;
if ( ! F_127 ( V_2 ) )
return - V_358 ;
if ( ! V_256 )
return - V_275 ;
return F_150 ( V_256 , V_379 , V_273 ) ;
}
static void * F_151 ( struct V_5 * V_6 ,
int V_179 )
{
return F_152 ( V_6 , V_328 ) + ( V_179 / 8 * 4 ) ;
}
static T_1 F_153 ( int V_179 )
{
return 0x0f << ( 28 - ( ( V_179 % 8 ) * 4 ) ) ;
}
static T_1 F_154 ( struct V_5 * V_6 , int V_179 )
{
return ( 0x08 >> ( V_6 -> V_380 << 1 ) ) << ( 28 - ( ( V_179 % 8 ) * 4 ) ) ;
}
static void F_155 ( struct V_1 * V_2 ,
int V_179 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_381 ;
void * V_8 ;
V_8 = F_151 ( V_6 , V_179 ) ;
V_381 = F_6 ( V_8 ) ;
F_4 ( V_381 | F_154 ( V_6 , V_179 ) , V_8 ) ;
}
static bool F_156 ( struct V_1 * V_2 ,
int V_179 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_382 , V_383 , V_381 ;
void * V_8 ;
V_8 = F_151 ( V_6 , V_179 ) ;
V_382 = F_153 ( V_179 ) ;
V_383 = F_154 ( V_6 , V_179 ) & ~ V_382 ;
V_381 = F_6 ( V_8 ) ;
F_4 ( V_381 & ~ V_382 , V_8 ) ;
return V_381 & V_383 ;
}
static int F_157 ( struct V_1 * V_2 )
{
int V_384 = V_385 * 100 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
while ( ( F_158 ( V_6 , V_326 ) & V_386 ) ) {
F_159 ( 10 ) ;
V_384 -- ;
if ( V_384 <= 0 ) {
F_27 ( V_2 , L_18 , V_361 ) ;
return - V_58 ;
}
}
return 0 ;
}
static int F_160 ( struct V_1 * V_2 , void * T_7 ,
const T_10 * V_10 )
{
T_1 V_387 ;
V_387 = V_10 [ 0 ] << 24 | V_10 [ 1 ] << 16 | V_10 [ 2 ] << 8 | V_10 [ 3 ] ;
F_4 ( V_387 , T_7 ) ;
if ( F_157 ( V_2 ) < 0 )
return - V_388 ;
V_387 = V_10 [ 4 ] << 8 | V_10 [ 5 ] ;
F_4 ( V_387 , T_7 + 4 ) ;
if ( F_157 ( V_2 ) < 0 )
return - V_388 ;
return 0 ;
}
static void F_161 ( void * T_7 , T_10 * V_10 )
{
T_1 V_387 ;
V_387 = F_6 ( T_7 ) ;
V_10 [ 0 ] = ( V_387 >> 24 ) & 0xff ;
V_10 [ 1 ] = ( V_387 >> 16 ) & 0xff ;
V_10 [ 2 ] = ( V_387 >> 8 ) & 0xff ;
V_10 [ 3 ] = V_387 & 0xff ;
V_387 = F_6 ( T_7 + 4 ) ;
V_10 [ 4 ] = ( V_387 >> 8 ) & 0xff ;
V_10 [ 5 ] = V_387 & 0xff ;
}
static int F_162 ( struct V_1 * V_2 , const T_10 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void * V_8 = F_152 ( V_6 , V_332 ) ;
int V_36 ;
T_10 V_389 [ V_81 ] ;
for ( V_36 = 0 ; V_36 < V_333 ; V_36 ++ , V_8 += 8 ) {
F_161 ( V_8 , V_389 ) ;
if ( F_163 ( V_10 , V_389 ) )
return V_36 ;
}
return - V_266 ;
}
static int F_164 ( struct V_1 * V_2 )
{
T_10 V_390 [ V_81 ] ;
int V_179 ;
memset ( V_390 , 0 , sizeof( V_390 ) ) ;
V_179 = F_162 ( V_2 , V_390 ) ;
return ( V_179 < 0 ) ? - V_133 : V_179 ;
}
static int F_165 ( struct V_1 * V_2 ,
int V_179 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void * V_8 = F_152 ( V_6 , V_332 ) ;
int V_54 ;
T_10 V_390 [ V_81 ] ;
F_14 ( V_6 , F_158 ( V_6 , V_327 ) &
~ ( 1 << ( 31 - V_179 ) ) , V_327 ) ;
memset ( V_390 , 0 , sizeof( V_390 ) ) ;
V_54 = F_160 ( V_2 , V_8 + V_179 * 8 , V_390 ) ;
if ( V_54 < 0 )
return V_54 ;
return 0 ;
}
static int F_166 ( struct V_1 * V_2 , const T_10 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void * V_8 = F_152 ( V_6 , V_332 ) ;
int V_36 , V_54 ;
if ( ! V_6 -> V_38 -> V_304 )
return 0 ;
V_36 = F_162 ( V_2 , V_10 ) ;
if ( V_36 < 0 ) {
V_36 = F_164 ( V_2 ) ;
if ( V_36 < 0 )
return - V_133 ;
V_54 = F_160 ( V_2 , V_8 + V_36 * 8 , V_10 ) ;
if ( V_54 < 0 )
return V_54 ;
F_14 ( V_6 , F_158 ( V_6 , V_327 ) |
( 1 << ( 31 - V_36 ) ) , V_327 ) ;
}
F_155 ( V_2 , V_36 ) ;
return 0 ;
}
static int F_167 ( struct V_1 * V_2 , const T_10 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_36 , V_54 ;
if ( ! V_6 -> V_38 -> V_304 )
return 0 ;
V_36 = F_162 ( V_2 , V_10 ) ;
if ( V_36 ) {
if ( F_156 ( V_2 , V_36 ) )
goto V_391;
V_54 = F_165 ( V_2 , V_36 ) ;
if ( V_54 < 0 )
return V_54 ;
}
V_391:
return 0 ;
}
static int F_168 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_36 , V_54 ;
if ( ! V_6 -> V_38 -> V_304 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_333 ; V_36 ++ ) {
if ( F_156 ( V_2 , V_36 ) )
continue;
V_54 = F_165 ( V_2 , V_36 ) ;
if ( V_54 < 0 )
return V_54 ;
}
return 0 ;
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_10 V_10 [ V_81 ] ;
void * V_8 = F_152 ( V_6 , V_332 ) ;
int V_36 ;
if ( ! V_6 -> V_38 -> V_304 )
return;
for ( V_36 = 0 ; V_36 < V_333 ; V_36 ++ , V_8 += 8 ) {
F_161 ( V_8 , V_10 ) ;
if ( F_170 ( V_10 ) )
F_167 ( V_2 , V_10 ) ;
}
}
static void F_171 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_392 ;
int V_393 = 0 ;
unsigned long V_274 ;
F_102 ( & V_6 -> V_248 , V_274 ) ;
V_392 = F_5 ( V_2 , V_21 ) & ~ V_394 ;
if ( V_6 -> V_38 -> V_304 )
V_392 |= V_395 ;
if ( ! ( V_2 -> V_274 & V_396 ) ) {
F_169 ( V_2 ) ;
V_393 = 1 ;
}
if ( V_2 -> V_274 & V_397 ) {
F_169 ( V_2 ) ;
V_392 &= ~ V_395 ;
V_393 = 1 ;
}
if ( V_2 -> V_274 & V_398 ) {
F_168 ( V_2 ) ;
V_392 = ( V_392 & ~ V_395 ) | V_394 ;
} else if ( V_6 -> V_38 -> V_304 ) {
struct V_399 * V_400 ;
F_172 (ha, ndev) {
if ( V_393 && F_170 ( V_400 -> V_10 ) )
continue;
if ( F_166 ( V_2 , V_400 -> V_10 ) < 0 ) {
if ( ! V_393 ) {
F_169 ( V_2 ) ;
V_392 &= ~ V_395 ;
V_393 = 1 ;
}
}
}
}
F_1 ( V_2 , V_392 , V_21 ) ;
F_104 ( & V_6 -> V_248 , V_274 ) ;
}
static int F_173 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_380 )
return V_324 ;
else
return V_325 ;
}
static int F_174 ( struct V_1 * V_2 ,
T_11 V_401 , T_2 V_402 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_403 = F_173 ( V_6 ) ;
if ( F_81 ( ! V_6 -> V_38 -> V_304 ) )
return - V_404 ;
if ( ! V_402 )
return 0 ;
V_6 -> V_405 ++ ;
if ( V_6 -> V_405 > 1 ) {
F_14 ( V_6 , 0 , V_403 ) ;
return 0 ;
}
F_14 ( V_6 , V_406 | ( V_402 & V_407 ) ,
V_403 ) ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 ,
T_11 V_401 , T_2 V_402 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_403 = F_173 ( V_6 ) ;
if ( F_81 ( ! V_6 -> V_38 -> V_304 ) )
return - V_404 ;
if ( ! V_402 )
return 0 ;
V_6 -> V_405 -- ;
F_14 ( V_6 , 0 , V_403 ) ;
return 0 ;
}
static void F_176 ( struct V_5 * V_6 )
{
if ( F_9 ( V_6 ) ) {
F_14 ( V_6 , 0 , V_327 ) ;
F_14 ( V_6 , V_408 | V_409 ,
V_315 ) ;
return;
}
F_14 ( V_6 , 0 , V_306 ) ;
F_14 ( V_6 , 0 , V_307 ) ;
F_14 ( V_6 , 0 , V_308 ) ;
F_14 ( V_6 , 0xc , V_309 ) ;
F_14 ( V_6 , 0xc , V_310 ) ;
F_14 ( V_6 , 0 , V_311 ) ;
F_14 ( V_6 , 0 , V_312 ) ;
F_14 ( V_6 , 0 , V_313 ) ;
F_14 ( V_6 , 0 , V_314 ) ;
F_14 ( V_6 , V_408 | V_409 , V_315 ) ;
if ( F_8 ( V_6 ) ) {
F_14 ( V_6 , 0 , V_316 ) ;
F_14 ( V_6 , 0 , V_317 ) ;
} else {
F_14 ( V_6 , 0 , V_318 ) ;
F_14 ( V_6 , 0 , V_319 ) ;
}
F_14 ( V_6 , 0 , V_320 ) ;
F_14 ( V_6 , 0 , V_321 ) ;
F_14 ( V_6 , 0 , V_327 ) ;
F_14 ( V_6 , 0 , V_328 ) ;
F_14 ( V_6 , 0 , V_329 ) ;
F_14 ( V_6 , 0 , V_330 ) ;
F_14 ( V_6 , 0 , V_331 ) ;
}
static int F_177 ( struct V_5 * V_6 )
{
F_178 ( V_6 -> V_270 ) ;
F_179 ( V_6 -> V_270 ) ;
return 0 ;
}
static int F_180 ( struct V_5 * V_6 ,
struct V_410 * V_411 )
{
int V_54 ;
struct V_87 * V_88 ;
struct V_412 * V_339 = V_6 -> V_339 ;
struct V_413 * V_119 = & V_6 -> V_339 -> V_119 ;
V_88 = F_181 ( V_119 , sizeof( struct V_87 ) , V_132 ) ;
if ( ! V_88 )
return - V_133 ;
V_88 -> V_10 = V_6 -> V_10 + V_6 -> V_8 [ V_286 ] ;
V_88 -> V_90 = V_411 -> V_414 ;
V_88 -> V_85 . V_415 = & V_416 ;
V_6 -> V_270 = F_182 ( & V_88 -> V_85 ) ;
if ( ! V_6 -> V_270 )
return - V_133 ;
V_6 -> V_270 -> V_363 = L_19 ;
V_6 -> V_270 -> V_263 = V_119 ;
snprintf ( V_6 -> V_270 -> V_271 , V_268 , L_20 ,
V_339 -> V_363 , V_339 -> V_271 ) ;
if ( V_119 -> V_264 ) {
V_54 = F_183 ( V_6 -> V_270 , V_119 -> V_264 ) ;
} else {
if ( V_411 -> V_417 > 0 )
V_6 -> V_270 -> V_244 [ V_411 -> V_418 ] = V_411 -> V_417 ;
V_54 = F_184 ( V_6 -> V_270 ) ;
}
if ( V_54 )
goto V_419;
return 0 ;
V_419:
F_179 ( V_6 -> V_270 ) ;
return V_54 ;
}
static const T_2 * F_185 ( int V_420 )
{
const T_2 * V_8 = NULL ;
switch ( V_420 ) {
case V_421 :
V_8 = V_13 ;
break;
case V_422 :
V_8 = V_14 ;
break;
case V_423 :
V_8 = V_424 ;
break;
case V_425 :
V_8 = V_426 ;
break;
case V_427 :
V_8 = V_428 ;
break;
}
return V_8 ;
}
static struct V_410 * F_186 ( struct V_413 * V_119 )
{
struct V_261 * V_262 = V_119 -> V_264 ;
struct V_410 * V_429 ;
const char * V_430 ;
V_429 = F_181 ( V_119 , sizeof( * V_429 ) , V_132 ) ;
if ( ! V_429 )
return NULL ;
V_429 -> V_16 = F_187 ( V_262 ) ;
V_430 = F_188 ( V_262 ) ;
if ( V_430 )
memcpy ( V_429 -> V_430 , V_430 , V_81 ) ;
V_429 -> V_222 =
F_189 ( V_262 , L_21 ) ;
V_429 -> V_225 =
F_189 ( V_262 , L_22 ) ;
return V_429 ;
}
static inline struct V_410 * F_186 ( struct V_413 * V_119 )
{
return NULL ;
}
static int F_190 ( struct V_412 * V_339 )
{
struct V_431 * V_432 ;
struct V_410 * V_411 = F_191 ( & V_339 -> V_119 ) ;
const struct V_433 * V_271 = F_192 ( V_339 ) ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_54 , V_434 ;
V_432 = F_193 ( V_339 , V_435 , 0 ) ;
V_2 = F_194 ( sizeof( struct V_5 ) ) ;
if ( ! V_2 )
return - V_133 ;
F_195 ( & V_339 -> V_119 ) ;
F_116 ( & V_339 -> V_119 ) ;
V_434 = V_339 -> V_271 ;
if ( V_434 < 0 )
V_434 = 0 ;
V_54 = F_196 ( V_339 , 0 ) ;
if ( V_54 < 0 )
goto V_436;
V_2 -> V_244 = V_54 ;
F_197 ( V_2 , & V_339 -> V_119 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_100 = V_437 ;
V_6 -> V_98 = V_438 ;
V_6 -> V_10 = F_198 ( & V_339 -> V_119 , V_432 ) ;
if ( F_96 ( V_6 -> V_10 ) ) {
V_54 = F_97 ( V_6 -> V_10 ) ;
goto V_436;
}
V_2 -> V_439 = V_432 -> V_440 ;
F_199 ( & V_6 -> V_248 ) ;
V_6 -> V_339 = V_339 ;
if ( V_339 -> V_119 . V_264 )
V_411 = F_186 ( & V_339 -> V_119 ) ;
if ( ! V_411 ) {
F_200 ( & V_339 -> V_119 , L_23 ) ;
V_54 = - V_358 ;
goto V_436;
}
V_6 -> V_267 = V_411 -> V_418 ;
V_6 -> V_16 = V_411 -> V_16 ;
V_6 -> V_222 = V_411 -> V_222 ;
V_6 -> V_225 = V_411 -> V_225 ;
if ( V_271 )
V_6 -> V_38 = (struct V_37 * ) V_271 -> V_441 ;
else
V_6 -> V_38 = (struct V_37 * ) F_201 ( & V_339 -> V_119 ) ;
V_6 -> V_8 = F_185 ( V_6 -> V_38 -> V_420 ) ;
if ( ! V_6 -> V_8 ) {
F_200 ( & V_339 -> V_119 , L_24 ,
V_6 -> V_38 -> V_420 ) ;
V_54 = - V_358 ;
goto V_436;
}
F_25 ( V_6 -> V_38 ) ;
if ( V_6 -> V_38 -> V_304 )
V_2 -> V_442 = & V_443 ;
else
V_2 -> V_442 = & V_444 ;
V_2 -> V_445 = & V_446 ;
V_2 -> V_447 = V_448 ;
V_6 -> V_340 = V_449 ;
F_32 ( V_2 , V_411 -> V_430 ) ;
if ( ! F_202 ( V_2 -> V_77 ) ) {
F_203 ( & V_339 -> V_119 ,
L_25 ) ;
F_204 ( V_2 ) ;
}
if ( V_6 -> V_38 -> V_304 ) {
struct V_431 * V_450 ;
V_450 = F_193 ( V_339 , V_435 , 1 ) ;
V_6 -> V_334 = F_198 ( & V_339 -> V_119 , V_450 ) ;
if ( F_96 ( V_6 -> V_334 ) ) {
V_54 = F_97 ( V_6 -> V_334 ) ;
goto V_436;
}
V_6 -> V_380 = V_434 % 2 ;
V_2 -> V_451 = V_452 ;
}
if ( ! V_434 || V_411 -> V_453 ) {
if ( V_6 -> V_38 -> V_454 )
V_6 -> V_38 -> V_454 ( V_2 ) ;
if ( V_6 -> V_38 -> V_304 ) {
F_176 ( V_6 ) ;
}
}
if ( V_6 -> V_38 -> V_135 )
F_1 ( V_2 , 0x1 , V_136 ) ;
V_54 = F_180 ( V_6 , V_411 ) ;
if ( V_54 ) {
F_200 ( & V_2 -> V_119 , L_26 ) ;
goto V_436;
}
F_205 ( V_2 , & V_6 -> V_252 , F_85 , 64 ) ;
V_54 = F_206 ( V_2 ) ;
if ( V_54 )
goto V_455;
F_207 ( V_2 , L_27 ,
( T_1 ) V_2 -> V_439 , V_2 -> V_77 , V_2 -> V_244 ) ;
F_208 ( & V_339 -> V_119 ) ;
F_209 ( V_339 , V_2 ) ;
return V_54 ;
V_455:
F_210 ( & V_6 -> V_252 ) ;
F_177 ( V_6 ) ;
V_436:
if ( V_2 )
F_211 ( V_2 ) ;
F_208 ( & V_339 -> V_119 ) ;
F_212 ( & V_339 -> V_119 ) ;
return V_54 ;
}
static int F_213 ( struct V_412 * V_339 )
{
struct V_1 * V_2 = F_214 ( V_339 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_215 ( V_2 ) ;
F_210 ( & V_6 -> V_252 ) ;
F_177 ( V_6 ) ;
F_212 ( & V_339 -> V_119 ) ;
F_211 ( V_2 ) ;
return 0 ;
}
static int F_216 ( struct V_413 * V_119 )
{
struct V_1 * V_2 = F_217 ( V_119 ) ;
int V_54 = 0 ;
if ( F_127 ( V_2 ) ) {
F_128 ( V_2 ) ;
V_54 = F_146 ( V_2 ) ;
}
return V_54 ;
}
static int F_218 ( struct V_413 * V_119 )
{
struct V_1 * V_2 = F_217 ( V_119 ) ;
int V_54 = 0 ;
if ( F_127 ( V_2 ) ) {
V_54 = F_133 ( V_2 ) ;
if ( V_54 < 0 )
return V_54 ;
F_132 ( V_2 ) ;
}
return V_54 ;
}
static int F_219 ( struct V_413 * V_119 )
{
return 0 ;
}
