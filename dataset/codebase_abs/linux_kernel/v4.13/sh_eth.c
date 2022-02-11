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
static int F_40 ( struct V_1 * V_2 , bool V_96 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_97 * V_98 ;
int V_99 = 0 ;
int V_100 ;
bool V_101 ;
for (; V_6 -> V_102 - V_6 -> V_103 > 0 ; V_6 -> V_103 ++ ) {
V_100 = V_6 -> V_103 % V_6 -> V_104 ;
V_98 = & V_6 -> V_105 [ V_100 ] ;
V_101 = ! ( V_98 -> V_106 & F_41 ( V_107 ) ) ;
if ( V_96 && ! V_101 )
break;
F_42 () ;
F_43 ( V_6 , V_108 , V_2 ,
L_3 ,
V_100 , F_44 ( V_98 -> V_106 ) ) ;
if ( V_6 -> V_109 [ V_100 ] ) {
F_45 ( & V_2 -> V_110 , F_44 ( V_98 -> V_10 ) ,
F_44 ( V_98 -> V_111 ) >> 16 ,
V_112 ) ;
F_46 ( V_6 -> V_109 [ V_100 ] ) ;
V_6 -> V_109 [ V_100 ] = NULL ;
V_99 ++ ;
}
V_98 -> V_106 = F_41 ( V_113 ) ;
if ( V_100 >= V_6 -> V_104 - 1 )
V_98 -> V_106 |= F_41 ( V_114 ) ;
if ( V_101 ) {
V_2 -> V_115 . V_116 ++ ;
V_2 -> V_115 . V_117 += F_44 ( V_98 -> V_111 ) >> 16 ;
}
}
return V_99 ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_118 , V_36 ;
if ( V_6 -> V_119 ) {
for ( V_36 = 0 ; V_36 < V_6 -> V_120 ; V_36 ++ ) {
if ( V_6 -> V_121 [ V_36 ] ) {
struct V_122 * V_123 = & V_6 -> V_119 [ V_36 ] ;
F_45 ( & V_2 -> V_110 ,
F_44 ( V_123 -> V_10 ) ,
F_48 ( V_6 -> V_124 , 32 ) ,
V_125 ) ;
}
}
V_118 = sizeof( struct V_122 ) * V_6 -> V_120 ;
F_49 ( NULL , V_118 , V_6 -> V_119 ,
V_6 -> V_126 ) ;
V_6 -> V_119 = NULL ;
}
if ( V_6 -> V_121 ) {
for ( V_36 = 0 ; V_36 < V_6 -> V_120 ; V_36 ++ )
F_50 ( V_6 -> V_121 [ V_36 ] ) ;
}
F_51 ( V_6 -> V_121 ) ;
V_6 -> V_121 = NULL ;
if ( V_6 -> V_105 ) {
F_40 ( V_2 , false ) ;
V_118 = sizeof( struct V_97 ) * V_6 -> V_104 ;
F_49 ( NULL , V_118 , V_6 -> V_105 ,
V_6 -> V_127 ) ;
V_6 -> V_105 = NULL ;
}
F_51 ( V_6 -> V_109 ) ;
V_6 -> V_109 = NULL ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_36 ;
struct V_73 * V_74 ;
struct V_122 * V_123 = NULL ;
struct V_97 * V_98 = NULL ;
int V_128 = sizeof( * V_123 ) * V_6 -> V_120 ;
int V_129 = sizeof( * V_98 ) * V_6 -> V_104 ;
int V_130 = V_6 -> V_124 + V_76 + 32 - 1 ;
T_4 V_131 ;
T_1 V_132 ;
V_6 -> V_133 = 0 ;
V_6 -> V_102 = 0 ;
V_6 -> V_134 = 0 ;
V_6 -> V_103 = 0 ;
memset ( V_6 -> V_119 , 0 , V_128 ) ;
for ( V_36 = 0 ; V_36 < V_6 -> V_120 ; V_36 ++ ) {
V_6 -> V_121 [ V_36 ] = NULL ;
V_74 = F_53 ( V_2 , V_130 ) ;
if ( V_74 == NULL )
break;
F_29 ( V_74 ) ;
V_132 = F_48 ( V_6 -> V_124 , 32 ) ;
V_131 = F_54 ( & V_2 -> V_110 , V_74 -> V_3 , V_132 ,
V_125 ) ;
if ( F_55 ( & V_2 -> V_110 , V_131 ) ) {
F_56 ( V_74 ) ;
break;
}
V_6 -> V_121 [ V_36 ] = V_74 ;
V_123 = & V_6 -> V_119 [ V_36 ] ;
V_123 -> V_111 = F_41 ( V_132 << 16 ) ;
V_123 -> V_10 = F_41 ( V_131 ) ;
V_123 -> V_106 = F_41 ( V_135 | V_136 ) ;
if ( V_36 == 0 ) {
F_1 ( V_2 , V_6 -> V_126 , V_65 ) ;
if ( F_8 ( V_6 ) ||
F_9 ( V_6 ) )
F_1 ( V_2 , V_6 -> V_126 , V_66 ) ;
}
}
V_6 -> V_134 = ( T_1 ) ( V_36 - V_6 -> V_120 ) ;
if ( V_123 )
V_123 -> V_106 |= F_41 ( V_137 ) ;
memset ( V_6 -> V_105 , 0 , V_129 ) ;
for ( V_36 = 0 ; V_36 < V_6 -> V_104 ; V_36 ++ ) {
V_6 -> V_109 [ V_36 ] = NULL ;
V_98 = & V_6 -> V_105 [ V_36 ] ;
V_98 -> V_106 = F_41 ( V_113 ) ;
V_98 -> V_111 = F_41 ( 0 ) ;
if ( V_36 == 0 ) {
F_1 ( V_2 , V_6 -> V_127 , V_61 ) ;
if ( F_8 ( V_6 ) ||
F_9 ( V_6 ) )
F_1 ( V_2 , V_6 -> V_127 , V_62 ) ;
}
}
V_98 -> V_106 |= F_41 ( V_114 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_128 , V_129 ;
V_6 -> V_124 = ( V_2 -> V_138 <= 1492 ? V_139 :
( ( ( V_2 -> V_138 + 26 + 7 ) & ~ 7 ) + 2 + 16 ) ) ;
if ( V_6 -> V_38 -> V_140 )
V_6 -> V_124 += V_141 ;
V_6 -> V_121 = F_58 ( V_6 -> V_120 , sizeof( * V_6 -> V_121 ) ,
V_142 ) ;
if ( ! V_6 -> V_121 )
return - V_143 ;
V_6 -> V_109 = F_58 ( V_6 -> V_104 , sizeof( * V_6 -> V_109 ) ,
V_142 ) ;
if ( ! V_6 -> V_109 )
goto V_144;
V_128 = sizeof( struct V_122 ) * V_6 -> V_120 ;
V_6 -> V_119 = F_59 ( NULL , V_128 , & V_6 -> V_126 ,
V_142 ) ;
if ( ! V_6 -> V_119 )
goto V_144;
V_6 -> V_134 = 0 ;
V_129 = sizeof( struct V_97 ) * V_6 -> V_104 ;
V_6 -> V_105 = F_59 ( NULL , V_129 , & V_6 -> V_127 ,
V_142 ) ;
if ( ! V_6 -> V_105 )
goto V_144;
return 0 ;
V_144:
F_47 ( V_2 ) ;
return - V_143 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_54 ;
V_54 = F_28 ( V_2 ) ;
if ( V_54 )
return V_54 ;
if ( V_6 -> V_38 -> V_145 )
F_1 ( V_2 , 0x1 , V_146 ) ;
F_52 ( V_2 ) ;
if ( V_6 -> V_38 -> V_140 )
F_1 ( V_2 , V_6 -> V_38 -> V_147 , V_148 ) ;
F_1 ( V_2 , 0 , V_149 ) ;
#if F_61 ( V_150 )
if ( V_6 -> V_38 -> V_151 )
F_1 ( V_2 , V_152 , V_56 ) ;
else
#endif
F_1 ( V_2 , 0 , V_56 ) ;
F_1 ( V_2 , V_6 -> V_38 -> V_46 , V_153 ) ;
F_1 ( V_2 , 0 , V_154 ) ;
F_1 ( V_2 , V_155 , V_156 ) ;
F_1 ( V_2 , V_6 -> V_38 -> V_52 , V_157 ) ;
if ( V_6 -> V_38 -> V_158 )
F_1 ( V_2 , 0x800 , V_159 ) ;
F_1 ( V_2 , V_6 -> V_38 -> V_43 , V_160 ) ;
if ( ! V_6 -> V_38 -> V_161 )
F_1 ( V_2 , 0 , V_162 ) ;
F_1 ( V_2 , V_2 -> V_138 + V_163 + V_164 + V_165 ,
V_166 ) ;
F_7 ( V_2 , V_167 , 0 , 0 ) ;
V_6 -> V_168 = true ;
F_1 ( V_2 , V_6 -> V_38 -> V_169 , V_149 ) ;
F_1 ( V_2 , V_170 | ( V_6 -> V_23 ? V_22 : 0 ) |
V_171 | V_172 , V_21 ) ;
if ( V_6 -> V_38 -> V_173 )
V_6 -> V_38 -> V_173 ( V_2 ) ;
F_1 ( V_2 , V_6 -> V_38 -> V_39 , V_174 ) ;
F_1 ( V_2 , V_6 -> V_38 -> V_41 , V_175 ) ;
F_31 ( V_2 ) ;
if ( V_6 -> V_38 -> V_176 )
F_1 ( V_2 , V_177 , V_178 ) ;
if ( V_6 -> V_38 -> V_179 )
F_1 ( V_2 , V_180 , V_181 ) ;
if ( V_6 -> V_38 -> V_182 )
F_1 ( V_2 , V_183 , V_184 ) ;
F_1 ( V_2 , V_185 , V_186 ) ;
return V_54 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_6 -> V_104 ; V_36 ++ )
V_6 -> V_105 [ V_36 ] . V_106 &= ~ F_41 ( V_107 ) ;
F_63 ( V_2 ) ;
F_1 ( V_2 , 0 , V_186 ) ;
F_64 ( 2 ) ;
F_65 ( V_2 ) ;
F_28 ( V_2 ) ;
F_31 ( V_2 ) ;
}
static int F_66 ( struct V_1 * V_2 , T_1 V_187 , int * V_188 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_122 * V_123 ;
int V_100 = V_6 -> V_133 % V_6 -> V_120 ;
int V_189 = ( V_6 -> V_134 + V_6 -> V_120 ) - V_6 -> V_133 ;
int V_190 ;
struct V_73 * V_74 ;
T_1 V_191 ;
int V_130 = V_6 -> V_124 + V_76 + 32 - 1 ;
T_4 V_131 ;
T_2 V_192 ;
T_1 V_132 ;
V_189 = F_67 ( V_189 , * V_188 ) ;
V_190 = V_189 ;
V_123 = & V_6 -> V_119 [ V_100 ] ;
while ( ! ( V_123 -> V_106 & F_41 ( V_135 ) ) ) {
F_42 () ;
V_191 = F_44 ( V_123 -> V_106 ) ;
V_192 = F_44 ( V_123 -> V_111 ) & V_193 ;
if ( -- V_189 < 0 )
break;
F_43 ( V_6 , V_194 , V_2 ,
L_4 ,
V_100 , V_191 , V_192 ) ;
if ( ! ( V_191 & V_195 ) )
V_2 -> V_115 . V_196 ++ ;
if ( V_6 -> V_38 -> V_69 )
V_191 >>= 16 ;
V_74 = V_6 -> V_121 [ V_100 ] ;
if ( V_191 & ( V_197 | V_198 | V_199 | V_200 |
V_201 | V_202 | V_203 ) ) {
V_2 -> V_115 . V_204 ++ ;
if ( V_191 & V_197 )
V_2 -> V_115 . V_205 ++ ;
if ( V_191 & V_198 )
V_2 -> V_115 . V_206 ++ ;
if ( V_191 & V_199 )
V_2 -> V_115 . V_196 ++ ;
if ( V_191 & V_200 )
V_2 -> V_115 . V_196 ++ ;
if ( V_191 & V_202 )
V_2 -> V_115 . V_207 ++ ;
if ( V_191 & V_203 )
V_2 -> V_115 . V_208 ++ ;
} else if ( V_74 ) {
V_131 = F_44 ( V_123 -> V_10 ) ;
if ( ! V_6 -> V_38 -> V_151 )
F_68 (
F_69 ( F_48 ( V_131 , 4 ) ) ,
V_192 + 2 ) ;
V_6 -> V_121 [ V_100 ] = NULL ;
if ( V_6 -> V_38 -> V_140 )
F_30 ( V_74 , V_141 ) ;
F_45 ( & V_2 -> V_110 , V_131 ,
F_48 ( V_6 -> V_124 , 32 ) ,
V_125 ) ;
F_70 ( V_74 , V_192 ) ;
V_74 -> V_209 = F_71 ( V_74 , V_2 ) ;
F_72 ( V_74 ) ;
V_2 -> V_115 . V_210 ++ ;
V_2 -> V_115 . V_211 += V_192 ;
if ( V_191 & V_212 )
V_2 -> V_115 . V_213 ++ ;
}
V_100 = ( ++ V_6 -> V_133 ) % V_6 -> V_120 ;
V_123 = & V_6 -> V_119 [ V_100 ] ;
}
for (; V_6 -> V_133 - V_6 -> V_134 > 0 ; V_6 -> V_134 ++ ) {
V_100 = V_6 -> V_134 % V_6 -> V_120 ;
V_123 = & V_6 -> V_119 [ V_100 ] ;
V_132 = F_48 ( V_6 -> V_124 , 32 ) ;
V_123 -> V_111 = F_41 ( V_132 << 16 ) ;
if ( V_6 -> V_121 [ V_100 ] == NULL ) {
V_74 = F_53 ( V_2 , V_130 ) ;
if ( V_74 == NULL )
break;
F_29 ( V_74 ) ;
V_131 = F_54 ( & V_2 -> V_110 , V_74 -> V_3 ,
V_132 , V_125 ) ;
if ( F_55 ( & V_2 -> V_110 , V_131 ) ) {
F_56 ( V_74 ) ;
break;
}
V_6 -> V_121 [ V_100 ] = V_74 ;
F_73 ( V_74 ) ;
V_123 -> V_10 = F_41 ( V_131 ) ;
}
F_74 () ;
if ( V_100 >= V_6 -> V_120 - 1 )
V_123 -> V_106 |=
F_41 ( V_135 | V_136 | V_137 ) ;
else
V_123 -> V_106 |= F_41 ( V_135 | V_136 ) ;
}
if ( ! ( F_5 ( V_2 , V_186 ) & V_185 ) ) {
if ( V_187 & V_214 &&
V_6 -> V_8 [ V_66 ] != V_9 ) {
T_1 V_215 = ( F_5 ( V_2 , V_66 ) -
F_5 ( V_2 , V_65 ) ) >> 4 ;
V_6 -> V_133 = V_215 ;
V_6 -> V_134 = V_215 ;
}
F_1 ( V_2 , V_185 , V_186 ) ;
}
* V_188 -= V_190 - V_189 - 1 ;
return * V_188 <= 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_21 , V_172 | V_171 , 0 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_21 , V_172 | V_171 , V_172 | V_171 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_216 ;
T_1 V_217 ;
V_216 = F_5 ( V_2 , V_174 ) & F_5 ( V_2 , V_175 ) ;
F_1 ( V_2 , V_216 , V_174 ) ;
if ( V_216 & V_218 )
V_2 -> V_115 . V_219 ++ ;
if ( V_216 & V_220 )
F_77 ( & V_6 -> V_221 -> V_110 , 0 ) ;
if ( V_216 & V_222 ) {
if ( V_6 -> V_38 -> V_223 || V_6 -> V_224 )
return;
V_217 = F_5 ( V_2 , V_225 ) ;
if ( V_6 -> V_226 )
V_217 = ~ V_217 ;
if ( ! ( V_217 & V_227 ) ) {
F_63 ( V_2 ) ;
} else {
F_7 ( V_2 , V_149 , V_228 , 0 ) ;
F_7 ( V_2 , V_174 , 0 , 0 ) ;
F_7 ( V_2 , V_149 , V_228 , V_228 ) ;
F_75 ( V_2 ) ;
}
}
}
static void F_78 ( struct V_1 * V_2 , T_1 V_187 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_86 ;
if ( V_187 & V_229 ) {
if ( V_187 & V_230 ) {
V_2 -> V_115 . V_231 ++ ;
F_79 ( V_6 , V_232 , V_2 , L_5 ) ;
}
}
if ( V_187 & V_233 ) {
if ( V_187 & V_234 ) {
V_2 -> V_115 . V_206 ++ ;
}
}
if ( V_187 & V_235 ) {
V_2 -> V_115 . V_236 ++ ;
F_79 ( V_6 , V_232 , V_2 , L_6 ) ;
}
if ( V_187 & V_237 ) {
V_2 -> V_115 . V_236 ++ ;
F_79 ( V_6 , V_232 , V_2 , L_7 ) ;
}
if ( V_187 & V_214 ) {
V_2 -> V_115 . V_208 ++ ;
}
if ( V_187 & V_238 ) {
V_2 -> V_115 . V_239 ++ ;
}
if ( ! V_6 -> V_38 -> V_240 && ( V_187 & V_241 ) ) {
V_2 -> V_115 . V_236 ++ ;
F_79 ( V_6 , V_232 , V_2 , L_8 ) ;
}
V_86 = V_229 | V_230 | V_241 | V_235 | V_237 ;
if ( V_6 -> V_38 -> V_240 )
V_86 &= ~ V_241 ;
if ( V_187 & V_86 ) {
T_1 V_242 = F_5 ( V_2 , V_243 ) ;
F_27 ( V_2 , L_9 ,
V_187 , V_6 -> V_102 , V_6 -> V_103 ,
( T_1 ) V_2 -> V_244 , V_242 ) ;
F_40 ( V_2 , true ) ;
if ( V_242 ^ F_33 ( V_6 ) ) {
F_1 ( V_2 , F_33 ( V_6 ) , V_243 ) ;
}
F_80 ( V_2 ) ;
}
}
static T_5 F_81 ( int V_245 , void * V_246 )
{
struct V_1 * V_2 = V_246 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_37 * V_38 = V_6 -> V_38 ;
T_5 V_54 = V_247 ;
T_1 V_187 , V_248 ;
F_82 ( & V_6 -> V_249 ) ;
V_187 = F_5 ( V_2 , V_167 ) ;
V_248 = F_5 ( V_2 , V_149 ) ;
V_187 &= V_248 | V_228 ;
if ( V_187 & ( V_250 | V_38 -> V_48 | V_251 |
V_38 -> V_50 ) )
V_54 = V_252 ;
else
goto V_253;
if ( F_83 ( ! V_6 -> V_168 ) ) {
F_1 ( V_2 , 0 , V_149 ) ;
goto V_253;
}
if ( V_187 & V_250 ) {
if ( F_84 ( & V_6 -> V_254 ) ) {
F_1 ( V_2 , V_248 & ~ V_250 ,
V_149 ) ;
F_85 ( & V_6 -> V_254 ) ;
} else {
F_11 ( V_2 ,
L_10 ,
V_187 , V_248 ) ;
}
}
if ( V_187 & V_38 -> V_48 ) {
F_1 ( V_2 , V_187 & V_38 -> V_48 , V_167 ) ;
F_40 ( V_2 , true ) ;
F_80 ( V_2 ) ;
}
if ( V_187 & V_251 )
F_76 ( V_2 ) ;
if ( V_187 & V_38 -> V_50 ) {
F_1 ( V_2 , V_187 & V_38 -> V_50 , V_167 ) ;
F_78 ( V_2 , V_187 ) ;
}
V_253:
F_86 ( & V_6 -> V_249 ) ;
return V_54 ;
}
static int F_87 ( struct V_255 * V_254 , int V_256 )
{
struct V_5 * V_6 = F_35 ( V_254 , struct V_5 ,
V_254 ) ;
struct V_1 * V_2 = V_254 -> V_110 ;
int V_188 = V_256 ;
T_1 V_187 ;
for (; ; ) {
V_187 = F_5 ( V_2 , V_167 ) ;
if ( ! ( V_187 & V_250 ) )
break;
F_1 ( V_2 , V_187 & V_250 , V_167 ) ;
if ( F_66 ( V_2 , V_187 , & V_188 ) )
goto V_253;
}
F_88 ( V_254 ) ;
if ( V_6 -> V_168 )
F_1 ( V_2 , V_6 -> V_38 -> V_169 , V_149 ) ;
V_253:
return V_256 - V_188 ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_257 * V_258 = V_2 -> V_258 ;
int V_259 = 0 ;
if ( V_258 -> V_260 ) {
if ( V_258 -> V_23 != V_6 -> V_23 ) {
V_259 = 1 ;
V_6 -> V_23 = V_258 -> V_23 ;
if ( V_6 -> V_38 -> V_261 )
V_6 -> V_38 -> V_261 ( V_2 ) ;
}
if ( V_258 -> V_26 != V_6 -> V_26 ) {
V_259 = 1 ;
V_6 -> V_26 = V_258 -> V_26 ;
if ( V_6 -> V_38 -> V_173 )
V_6 -> V_38 -> V_173 ( V_2 ) ;
}
if ( ! V_6 -> V_260 ) {
F_7 ( V_2 , V_21 , V_262 , 0 ) ;
V_259 = 1 ;
V_6 -> V_260 = V_258 -> V_260 ;
if ( V_6 -> V_38 -> V_223 || V_6 -> V_224 )
F_75 ( V_2 ) ;
}
} else if ( V_6 -> V_260 ) {
V_259 = 1 ;
V_6 -> V_260 = 0 ;
V_6 -> V_26 = 0 ;
V_6 -> V_23 = - 1 ;
if ( V_6 -> V_38 -> V_223 || V_6 -> V_224 )
F_63 ( V_2 ) ;
}
if ( V_259 && F_90 ( V_6 ) )
F_91 ( V_258 ) ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_263 * V_264 = V_2 -> V_110 . V_265 -> V_266 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_257 * V_258 ;
V_6 -> V_260 = 0 ;
V_6 -> V_26 = 0 ;
V_6 -> V_23 = - 1 ;
if ( V_264 ) {
struct V_263 * V_267 ;
V_267 = F_93 ( V_264 , L_11 , 0 ) ;
V_258 = F_94 ( V_2 , V_267 ,
F_89 , 0 ,
V_6 -> V_16 ) ;
F_95 ( V_267 ) ;
if ( ! V_258 )
V_258 = F_96 ( - V_268 ) ;
} else {
char V_269 [ V_270 + 3 ] ;
snprintf ( V_269 , sizeof( V_269 ) , V_271 ,
V_6 -> V_272 -> V_273 , V_6 -> V_269 ) ;
V_258 = F_97 ( V_2 , V_269 , F_89 ,
V_6 -> V_16 ) ;
}
if ( F_98 ( V_258 ) ) {
F_27 ( V_2 , L_12 ) ;
return F_99 ( V_258 ) ;
}
F_100 ( V_258 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
int V_54 ;
V_54 = F_92 ( V_2 ) ;
if ( V_54 )
return V_54 ;
F_102 ( V_2 -> V_258 ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_274 * V_275 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_276 ;
if ( ! V_2 -> V_258 )
return - V_277 ;
F_104 ( & V_6 -> V_249 , V_276 ) ;
F_105 ( V_2 -> V_258 , V_275 ) ;
F_106 ( & V_6 -> V_249 , V_276 ) ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 ,
const struct V_274 * V_275 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_276 ;
int V_54 ;
if ( ! V_2 -> V_258 )
return - V_277 ;
F_104 ( & V_6 -> V_249 , V_276 ) ;
F_63 ( V_2 ) ;
V_54 = F_108 ( V_2 -> V_258 , V_275 ) ;
if ( V_54 )
goto V_278;
if ( V_275 -> V_279 . V_23 == V_280 )
V_6 -> V_23 = 1 ;
else
V_6 -> V_23 = 0 ;
if ( V_6 -> V_38 -> V_261 )
V_6 -> V_38 -> V_261 ( V_2 ) ;
V_278:
F_15 ( 1 ) ;
F_75 ( V_2 ) ;
F_106 ( & V_6 -> V_249 , V_276 ) ;
return V_54 ;
}
static T_6 F_109 ( struct V_1 * V_2 , T_1 * V_281 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_37 * V_38 = V_6 -> V_38 ;
T_1 * V_282 ;
T_6 V_111 ;
F_110 ( V_283 > V_284 ) ;
V_111 = F_111 ( V_284 , 32 ) ;
if ( V_281 ) {
V_282 = V_281 ;
V_281 += V_111 ;
} else {
V_282 = NULL ;
}
#define F_112 ( T_7 ) valid_map[reg / 32] |= 1U << (reg % 32)
#define F_113 ( T_7 , T_8 ) do { \
if (mdp->reg_offset[reg] != SH_ETH_OFFSET_INVALID) { \
if (buf) { \
mark_reg_valid(reg); \
*buf++ = read_expr; \
} \
++len; \
} \
} while (0)
#define F_114 ( T_7 ) add_reg_from(reg, sh_eth_read(ndev, reg))
#define F_115 ( T_7 ) add_reg_from(reg, sh_eth_tsu_read(mdp, reg))
F_114 ( V_60 ) ;
F_114 ( V_56 ) ;
F_114 ( V_243 ) ;
F_114 ( V_186 ) ;
F_114 ( V_167 ) ;
F_114 ( V_149 ) ;
F_114 ( V_61 ) ;
F_114 ( V_62 ) ;
F_114 ( V_63 ) ;
F_114 ( V_64 ) ;
F_114 ( V_65 ) ;
F_114 ( V_66 ) ;
F_114 ( V_67 ) ;
F_114 ( V_68 ) ;
F_114 ( V_157 ) ;
F_114 ( V_285 ) ;
F_114 ( V_154 ) ;
F_114 ( V_153 ) ;
F_114 ( V_156 ) ;
F_114 ( V_286 ) ;
F_114 ( V_287 ) ;
if ( V_38 -> V_145 )
F_114 ( V_146 ) ;
F_114 ( V_160 ) ;
if ( V_38 -> V_140 )
F_114 ( V_148 ) ;
if ( ! V_38 -> V_161 )
F_114 ( V_162 ) ;
F_114 ( V_21 ) ;
F_114 ( V_174 ) ;
F_114 ( V_175 ) ;
F_114 ( V_288 ) ;
if ( ! V_38 -> V_223 )
F_114 ( V_225 ) ;
F_114 ( V_289 ) ;
F_114 ( V_166 ) ;
F_114 ( V_290 ) ;
if ( V_38 -> V_176 )
F_114 ( V_178 ) ;
if ( V_38 -> V_179 )
F_114 ( V_181 ) ;
F_114 ( V_291 ) ;
F_114 ( V_292 ) ;
if ( V_38 -> V_182 )
F_114 ( V_184 ) ;
F_114 ( V_293 ) ;
F_114 ( V_28 ) ;
if ( V_38 -> V_158 )
F_114 ( V_159 ) ;
F_114 ( V_78 ) ;
F_114 ( V_79 ) ;
F_114 ( V_294 ) ;
F_114 ( V_295 ) ;
F_114 ( V_296 ) ;
F_114 ( V_297 ) ;
F_114 ( V_298 ) ;
F_114 ( V_299 ) ;
F_114 ( V_300 ) ;
F_114 ( V_301 ) ;
F_114 ( V_302 ) ;
F_114 ( V_303 ) ;
F_114 ( V_304 ) ;
if ( V_38 -> V_305 )
F_114 ( V_33 ) ;
if ( V_38 -> V_69 )
F_114 ( V_70 ) ;
if ( V_38 -> V_71 )
F_114 ( V_20 ) ;
F_114 ( V_25 ) ;
if ( V_38 -> V_306 ) {
F_115 ( V_307 ) ;
F_115 ( V_308 ) ;
F_115 ( V_309 ) ;
F_115 ( V_310 ) ;
F_115 ( V_311 ) ;
F_115 ( V_312 ) ;
F_115 ( V_313 ) ;
F_115 ( V_314 ) ;
F_115 ( V_315 ) ;
F_115 ( V_316 ) ;
F_115 ( V_317 ) ;
F_115 ( V_318 ) ;
F_115 ( V_319 ) ;
F_115 ( V_320 ) ;
F_115 ( V_321 ) ;
F_115 ( V_322 ) ;
F_115 ( V_323 ) ;
F_115 ( V_324 ) ;
F_115 ( V_325 ) ;
F_115 ( V_326 ) ;
F_115 ( V_327 ) ;
F_115 ( V_328 ) ;
F_115 ( V_329 ) ;
F_115 ( V_330 ) ;
F_115 ( V_331 ) ;
F_115 ( V_332 ) ;
F_115 ( V_333 ) ;
if ( V_6 -> V_8 [ V_334 ] != V_9 ) {
if ( V_281 ) {
unsigned int V_36 ;
F_112 ( V_334 ) ;
for ( V_36 = 0 ; V_36 < V_335 * 2 ; V_36 ++ )
* V_281 ++ = F_6 (
V_6 -> V_336 +
V_6 -> V_8 [ V_334 ] +
V_36 * 4 ) ;
}
V_111 += V_335 * 2 ;
}
}
#undef F_112
#undef F_113
#undef F_114
#undef F_115
return V_111 * 4 ;
}
static int F_116 ( struct V_1 * V_2 )
{
return F_109 ( V_2 , NULL ) ;
}
static void F_117 ( struct V_1 * V_2 , struct V_337 * V_338 ,
void * V_281 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_338 -> V_339 = V_340 ;
F_118 ( & V_6 -> V_221 -> V_110 ) ;
F_109 ( V_2 , V_281 ) ;
F_119 ( & V_6 -> V_221 -> V_110 ) ;
}
static int F_120 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_276 ;
int V_54 ;
if ( ! V_2 -> V_258 )
return - V_277 ;
F_104 ( & V_6 -> V_249 , V_276 ) ;
V_54 = F_121 ( V_2 -> V_258 ) ;
F_106 ( & V_6 -> V_249 , V_276 ) ;
return V_54 ;
}
static T_1 F_122 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_341 ;
}
static void F_123 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_341 = V_15 ;
}
static int F_124 ( struct V_1 * V_246 , int V_342 )
{
switch ( V_342 ) {
case V_343 :
return V_344 ;
default:
return - V_345 ;
}
}
static void F_125 ( struct V_1 * V_2 ,
struct V_346 * V_115 , T_9 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_36 = 0 ;
V_3 [ V_36 ++ ] = V_6 -> V_133 ;
V_3 [ V_36 ++ ] = V_6 -> V_102 ;
V_3 [ V_36 ++ ] = V_6 -> V_134 ;
V_3 [ V_36 ++ ] = V_6 -> V_103 ;
}
static void F_126 ( struct V_1 * V_2 , T_1 V_347 , T_10 * V_3 )
{
switch ( V_347 ) {
case V_343 :
memcpy ( V_3 , * V_348 ,
sizeof( V_348 ) ) ;
break;
}
}
static void F_127 ( struct V_1 * V_2 ,
struct V_349 * V_350 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_350 -> V_351 = V_352 ;
V_350 -> V_353 = V_354 ;
V_350 -> V_355 = V_6 -> V_120 ;
V_350 -> V_356 = V_6 -> V_104 ;
}
static int F_128 ( struct V_1 * V_2 ,
struct V_349 * V_350 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_54 ;
if ( V_350 -> V_356 > V_354 ||
V_350 -> V_355 > V_352 ||
V_350 -> V_356 < V_357 ||
V_350 -> V_355 < V_358 )
return - V_359 ;
if ( V_350 -> V_360 || V_350 -> V_361 )
return - V_359 ;
if ( F_129 ( V_2 ) ) {
F_130 ( V_2 ) ;
F_131 ( V_2 ) ;
V_6 -> V_168 = false ;
F_132 ( V_2 -> V_245 ) ;
F_133 ( & V_6 -> V_254 ) ;
F_1 ( V_2 , 0x0000 , V_149 ) ;
F_62 ( V_2 ) ;
F_47 ( V_2 ) ;
}
V_6 -> V_120 = V_350 -> V_355 ;
V_6 -> V_104 = V_350 -> V_356 ;
if ( F_129 ( V_2 ) ) {
V_54 = F_57 ( V_2 ) ;
if ( V_54 < 0 ) {
F_27 ( V_2 , L_13 ,
V_362 ) ;
return V_54 ;
}
V_54 = F_60 ( V_2 ) ;
if ( V_54 < 0 ) {
F_27 ( V_2 , L_14 ,
V_362 ) ;
return V_54 ;
}
F_134 ( V_2 ) ;
}
return 0 ;
}
static void F_135 ( struct V_1 * V_2 , struct V_363 * V_364 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_364 -> V_365 = 0 ;
V_364 -> V_366 = 0 ;
if ( V_6 -> V_38 -> V_367 && V_6 -> V_368 ) {
V_364 -> V_365 = V_369 ;
V_364 -> V_366 = V_6 -> V_370 ? V_369 : 0 ;
}
}
static int F_136 ( struct V_1 * V_2 , struct V_363 * V_364 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_38 -> V_367 || ! V_6 -> V_368 || V_364 -> V_366 & ~ V_369 )
return - V_345 ;
V_6 -> V_370 = ! ! ( V_364 -> V_366 & V_369 ) ;
F_137 ( & V_6 -> V_221 -> V_110 , V_6 -> V_370 ) ;
return 0 ;
}
static int F_138 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_54 ;
F_118 ( & V_6 -> V_221 -> V_110 ) ;
F_139 ( & V_6 -> V_254 ) ;
V_54 = F_140 ( V_2 -> V_245 , F_81 ,
V_6 -> V_38 -> V_371 , V_2 -> V_372 , V_2 ) ;
if ( V_54 ) {
F_27 ( V_2 , L_15 ) ;
goto V_373;
}
V_54 = F_57 ( V_2 ) ;
if ( V_54 )
goto V_374;
V_54 = F_60 ( V_2 ) ;
if ( V_54 )
goto V_374;
V_54 = F_101 ( V_2 ) ;
if ( V_54 )
goto V_374;
F_141 ( V_2 ) ;
V_6 -> V_375 = 1 ;
return V_54 ;
V_374:
F_142 ( V_2 -> V_245 , V_2 ) ;
V_373:
F_143 ( & V_6 -> V_254 ) ;
F_119 ( & V_6 -> V_221 -> V_110 ) ;
return V_54 ;
}
static void F_144 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_122 * V_123 ;
int V_36 ;
F_145 ( V_2 ) ;
F_79 ( V_6 , V_376 , V_2 ,
L_16 ,
F_5 ( V_2 , V_167 ) ) ;
V_2 -> V_115 . V_377 ++ ;
for ( V_36 = 0 ; V_36 < V_6 -> V_120 ; V_36 ++ ) {
V_123 = & V_6 -> V_119 [ V_36 ] ;
V_123 -> V_106 = F_41 ( 0 ) ;
V_123 -> V_10 = F_41 ( 0xBADF00D0 ) ;
F_50 ( V_6 -> V_121 [ V_36 ] ) ;
V_6 -> V_121 [ V_36 ] = NULL ;
}
for ( V_36 = 0 ; V_36 < V_6 -> V_104 ; V_36 ++ ) {
F_50 ( V_6 -> V_109 [ V_36 ] ) ;
V_6 -> V_109 [ V_36 ] = NULL ;
}
F_60 ( V_2 ) ;
F_141 ( V_2 ) ;
}
static int F_146 ( struct V_73 * V_74 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_97 * V_98 ;
T_4 V_131 ;
T_1 V_100 ;
unsigned long V_276 ;
F_104 ( & V_6 -> V_249 , V_276 ) ;
if ( ( V_6 -> V_102 - V_6 -> V_103 ) >= ( V_6 -> V_104 - 4 ) ) {
if ( ! F_40 ( V_2 , true ) ) {
F_147 ( V_6 , V_378 , V_2 , L_17 ) ;
F_145 ( V_2 ) ;
F_106 ( & V_6 -> V_249 , V_276 ) ;
return V_379 ;
}
}
F_106 ( & V_6 -> V_249 , V_276 ) ;
if ( F_148 ( V_74 , V_380 ) )
return V_381 ;
V_100 = V_6 -> V_102 % V_6 -> V_104 ;
V_6 -> V_109 [ V_100 ] = V_74 ;
V_98 = & V_6 -> V_105 [ V_100 ] ;
if ( ! V_6 -> V_38 -> V_151 )
F_68 ( F_149 ( V_74 -> V_3 , 4 ) , V_74 -> V_111 + 2 ) ;
V_131 = F_54 ( & V_2 -> V_110 , V_74 -> V_3 , V_74 -> V_111 ,
V_112 ) ;
if ( F_55 ( & V_2 -> V_110 , V_131 ) ) {
F_56 ( V_74 ) ;
return V_381 ;
}
V_98 -> V_10 = F_41 ( V_131 ) ;
V_98 -> V_111 = F_41 ( V_74 -> V_111 << 16 ) ;
F_74 () ;
if ( V_100 >= V_6 -> V_104 - 1 )
V_98 -> V_106 |= F_41 ( V_107 | V_114 ) ;
else
V_98 -> V_106 |= F_41 ( V_107 ) ;
V_6 -> V_102 ++ ;
if ( ! ( F_5 ( V_2 , V_243 ) & F_33 ( V_6 ) ) )
F_1 ( V_2 , F_33 ( V_6 ) , V_243 ) ;
return V_381 ;
}
static void
F_150 ( struct V_1 * V_2 , unsigned long * V_382 , int T_7 )
{
T_1 V_383 = F_5 ( V_2 , T_7 ) ;
if ( V_383 ) {
* V_382 += V_383 ;
F_1 ( V_2 , 0 , T_7 ) ;
}
}
static struct V_384 * F_65 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_9 ( V_6 ) )
return & V_2 -> V_115 ;
if ( ! V_6 -> V_375 )
return & V_2 -> V_115 ;
F_150 ( V_2 , & V_2 -> V_115 . V_385 , V_294 ) ;
F_150 ( V_2 , & V_2 -> V_115 . V_386 , V_295 ) ;
F_150 ( V_2 , & V_2 -> V_115 . V_219 , V_296 ) ;
if ( F_8 ( V_6 ) ) {
F_150 ( V_2 , & V_2 -> V_115 . V_219 ,
V_302 ) ;
F_150 ( V_2 , & V_2 -> V_115 . V_219 ,
V_303 ) ;
} else {
F_150 ( V_2 , & V_2 -> V_115 . V_219 ,
V_297 ) ;
}
return & V_2 -> V_115 ;
}
static int F_151 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_145 ( V_2 ) ;
V_6 -> V_168 = false ;
F_132 ( V_2 -> V_245 ) ;
F_143 ( & V_6 -> V_254 ) ;
F_1 ( V_2 , 0x0000 , V_149 ) ;
F_62 ( V_2 ) ;
if ( V_2 -> V_258 ) {
F_152 ( V_2 -> V_258 ) ;
F_153 ( V_2 -> V_258 ) ;
}
F_142 ( V_2 -> V_245 , V_2 ) ;
F_47 ( V_2 ) ;
F_119 ( & V_6 -> V_221 -> V_110 ) ;
V_6 -> V_375 = 0 ;
return 0 ;
}
static int F_154 ( struct V_1 * V_2 , struct V_387 * V_388 , int V_275 )
{
struct V_257 * V_258 = V_2 -> V_258 ;
if ( ! F_129 ( V_2 ) )
return - V_359 ;
if ( ! V_258 )
return - V_277 ;
return F_155 ( V_258 , V_388 , V_275 ) ;
}
static int F_156 ( struct V_1 * V_2 , int V_389 )
{
if ( F_129 ( V_2 ) )
return - V_390 ;
V_2 -> V_138 = V_389 ;
F_157 ( V_2 ) ;
return 0 ;
}
static void * F_158 ( struct V_5 * V_6 ,
int V_100 )
{
return F_159 ( V_6 , V_330 ) + ( V_100 / 8 * 4 ) ;
}
static T_1 F_160 ( int V_100 )
{
return 0x0f << ( 28 - ( ( V_100 % 8 ) * 4 ) ) ;
}
static T_1 F_161 ( struct V_5 * V_6 , int V_100 )
{
return ( 0x08 >> ( V_6 -> V_391 << 1 ) ) << ( 28 - ( ( V_100 % 8 ) * 4 ) ) ;
}
static void F_162 ( struct V_1 * V_2 ,
int V_100 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_392 ;
void * V_8 ;
V_8 = F_158 ( V_6 , V_100 ) ;
V_392 = F_6 ( V_8 ) ;
F_4 ( V_392 | F_161 ( V_6 , V_100 ) , V_8 ) ;
}
static bool F_163 ( struct V_1 * V_2 ,
int V_100 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_393 , V_394 , V_392 ;
void * V_8 ;
V_8 = F_158 ( V_6 , V_100 ) ;
V_393 = F_160 ( V_100 ) ;
V_394 = F_161 ( V_6 , V_100 ) & ~ V_393 ;
V_392 = F_6 ( V_8 ) ;
F_4 ( V_392 & ~ V_393 , V_8 ) ;
return V_392 & V_394 ;
}
static int F_164 ( struct V_1 * V_2 )
{
int V_395 = V_396 * 100 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
while ( ( F_165 ( V_6 , V_328 ) & V_397 ) ) {
F_166 ( 10 ) ;
V_395 -- ;
if ( V_395 <= 0 ) {
F_27 ( V_2 , L_18 , V_362 ) ;
return - V_58 ;
}
}
return 0 ;
}
static int F_167 ( struct V_1 * V_2 , void * T_7 ,
const T_10 * V_10 )
{
T_1 V_398 ;
V_398 = V_10 [ 0 ] << 24 | V_10 [ 1 ] << 16 | V_10 [ 2 ] << 8 | V_10 [ 3 ] ;
F_4 ( V_398 , T_7 ) ;
if ( F_164 ( V_2 ) < 0 )
return - V_390 ;
V_398 = V_10 [ 4 ] << 8 | V_10 [ 5 ] ;
F_4 ( V_398 , T_7 + 4 ) ;
if ( F_164 ( V_2 ) < 0 )
return - V_390 ;
return 0 ;
}
static void F_168 ( void * T_7 , T_10 * V_10 )
{
T_1 V_398 ;
V_398 = F_6 ( T_7 ) ;
V_10 [ 0 ] = ( V_398 >> 24 ) & 0xff ;
V_10 [ 1 ] = ( V_398 >> 16 ) & 0xff ;
V_10 [ 2 ] = ( V_398 >> 8 ) & 0xff ;
V_10 [ 3 ] = V_398 & 0xff ;
V_398 = F_6 ( T_7 + 4 ) ;
V_10 [ 4 ] = ( V_398 >> 8 ) & 0xff ;
V_10 [ 5 ] = V_398 & 0xff ;
}
static int F_169 ( struct V_1 * V_2 , const T_10 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void * V_8 = F_159 ( V_6 , V_334 ) ;
int V_36 ;
T_10 V_399 [ V_81 ] ;
for ( V_36 = 0 ; V_36 < V_335 ; V_36 ++ , V_8 += 8 ) {
F_168 ( V_8 , V_399 ) ;
if ( F_170 ( V_10 , V_399 ) )
return V_36 ;
}
return - V_268 ;
}
static int F_171 ( struct V_1 * V_2 )
{
T_10 V_400 [ V_81 ] ;
int V_100 ;
memset ( V_400 , 0 , sizeof( V_400 ) ) ;
V_100 = F_169 ( V_2 , V_400 ) ;
return ( V_100 < 0 ) ? - V_143 : V_100 ;
}
static int F_172 ( struct V_1 * V_2 ,
int V_100 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void * V_8 = F_159 ( V_6 , V_334 ) ;
int V_54 ;
T_10 V_400 [ V_81 ] ;
F_14 ( V_6 , F_165 ( V_6 , V_329 ) &
~ ( 1 << ( 31 - V_100 ) ) , V_329 ) ;
memset ( V_400 , 0 , sizeof( V_400 ) ) ;
V_54 = F_167 ( V_2 , V_8 + V_100 * 8 , V_400 ) ;
if ( V_54 < 0 )
return V_54 ;
return 0 ;
}
static int F_173 ( struct V_1 * V_2 , const T_10 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void * V_8 = F_159 ( V_6 , V_334 ) ;
int V_36 , V_54 ;
if ( ! V_6 -> V_38 -> V_306 )
return 0 ;
V_36 = F_169 ( V_2 , V_10 ) ;
if ( V_36 < 0 ) {
V_36 = F_171 ( V_2 ) ;
if ( V_36 < 0 )
return - V_143 ;
V_54 = F_167 ( V_2 , V_8 + V_36 * 8 , V_10 ) ;
if ( V_54 < 0 )
return V_54 ;
F_14 ( V_6 , F_165 ( V_6 , V_329 ) |
( 1 << ( 31 - V_36 ) ) , V_329 ) ;
}
F_162 ( V_2 , V_36 ) ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 , const T_10 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_36 , V_54 ;
if ( ! V_6 -> V_38 -> V_306 )
return 0 ;
V_36 = F_169 ( V_2 , V_10 ) ;
if ( V_36 ) {
if ( F_163 ( V_2 , V_36 ) )
goto V_401;
V_54 = F_172 ( V_2 , V_36 ) ;
if ( V_54 < 0 )
return V_54 ;
}
V_401:
return 0 ;
}
static int F_175 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_36 , V_54 ;
if ( ! V_6 -> V_38 -> V_306 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_335 ; V_36 ++ ) {
if ( F_163 ( V_2 , V_36 ) )
continue;
V_54 = F_172 ( V_2 , V_36 ) ;
if ( V_54 < 0 )
return V_54 ;
}
return 0 ;
}
static void F_176 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_10 V_10 [ V_81 ] ;
void * V_8 = F_159 ( V_6 , V_334 ) ;
int V_36 ;
if ( ! V_6 -> V_38 -> V_306 )
return;
for ( V_36 = 0 ; V_36 < V_335 ; V_36 ++ , V_8 += 8 ) {
F_168 ( V_8 , V_10 ) ;
if ( F_177 ( V_10 ) )
F_174 ( V_2 , V_10 ) ;
}
}
static void F_178 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_402 ;
int V_403 = 0 ;
unsigned long V_276 ;
F_104 ( & V_6 -> V_249 , V_276 ) ;
V_402 = F_5 ( V_2 , V_21 ) & ~ V_404 ;
if ( V_6 -> V_38 -> V_306 )
V_402 |= V_405 ;
if ( ! ( V_2 -> V_276 & V_406 ) ) {
F_176 ( V_2 ) ;
V_403 = 1 ;
}
if ( V_2 -> V_276 & V_407 ) {
F_176 ( V_2 ) ;
V_402 &= ~ V_405 ;
V_403 = 1 ;
}
if ( V_2 -> V_276 & V_408 ) {
F_175 ( V_2 ) ;
V_402 = ( V_402 & ~ V_405 ) | V_404 ;
} else if ( V_6 -> V_38 -> V_306 ) {
struct V_409 * V_410 ;
F_179 (ha, ndev) {
if ( V_403 && F_177 ( V_410 -> V_10 ) )
continue;
if ( F_173 ( V_2 , V_410 -> V_10 ) < 0 ) {
if ( ! V_403 ) {
F_176 ( V_2 ) ;
V_402 &= ~ V_405 ;
V_403 = 1 ;
}
}
}
}
F_1 ( V_2 , V_402 , V_21 ) ;
F_106 ( & V_6 -> V_249 , V_276 ) ;
}
static int F_180 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_391 )
return V_326 ;
else
return V_327 ;
}
static int F_181 ( struct V_1 * V_2 ,
T_11 V_411 , T_2 V_412 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_413 = F_180 ( V_6 ) ;
if ( F_83 ( ! V_6 -> V_38 -> V_306 ) )
return - V_414 ;
if ( ! V_412 )
return 0 ;
V_6 -> V_415 ++ ;
if ( V_6 -> V_415 > 1 ) {
F_14 ( V_6 , 0 , V_413 ) ;
return 0 ;
}
F_14 ( V_6 , V_416 | ( V_412 & V_417 ) ,
V_413 ) ;
return 0 ;
}
static int F_182 ( struct V_1 * V_2 ,
T_11 V_411 , T_2 V_412 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_413 = F_180 ( V_6 ) ;
if ( F_83 ( ! V_6 -> V_38 -> V_306 ) )
return - V_414 ;
if ( ! V_412 )
return 0 ;
V_6 -> V_415 -- ;
F_14 ( V_6 , 0 , V_413 ) ;
return 0 ;
}
static void F_183 ( struct V_5 * V_6 )
{
if ( F_9 ( V_6 ) ) {
F_14 ( V_6 , 0 , V_329 ) ;
F_14 ( V_6 , V_418 | V_419 ,
V_317 ) ;
return;
}
F_14 ( V_6 , 0 , V_308 ) ;
F_14 ( V_6 , 0 , V_309 ) ;
F_14 ( V_6 , 0 , V_310 ) ;
F_14 ( V_6 , 0xc , V_311 ) ;
F_14 ( V_6 , 0xc , V_312 ) ;
F_14 ( V_6 , 0 , V_313 ) ;
F_14 ( V_6 , 0 , V_314 ) ;
F_14 ( V_6 , 0 , V_315 ) ;
F_14 ( V_6 , 0 , V_316 ) ;
F_14 ( V_6 , V_418 | V_419 , V_317 ) ;
if ( F_8 ( V_6 ) ) {
F_14 ( V_6 , 0 , V_318 ) ;
F_14 ( V_6 , 0 , V_319 ) ;
} else {
F_14 ( V_6 , 0 , V_320 ) ;
F_14 ( V_6 , 0 , V_321 ) ;
}
F_14 ( V_6 , 0 , V_322 ) ;
F_14 ( V_6 , 0 , V_323 ) ;
F_14 ( V_6 , 0 , V_329 ) ;
F_14 ( V_6 , 0 , V_330 ) ;
F_14 ( V_6 , 0 , V_331 ) ;
F_14 ( V_6 , 0 , V_332 ) ;
F_14 ( V_6 , 0 , V_333 ) ;
}
static int F_184 ( struct V_5 * V_6 )
{
F_185 ( V_6 -> V_272 ) ;
F_186 ( V_6 -> V_272 ) ;
return 0 ;
}
static int F_187 ( struct V_5 * V_6 ,
struct V_420 * V_421 )
{
int V_54 ;
struct V_87 * V_88 ;
struct V_422 * V_221 = V_6 -> V_221 ;
struct V_423 * V_110 = & V_6 -> V_221 -> V_110 ;
V_88 = F_188 ( V_110 , sizeof( struct V_87 ) , V_142 ) ;
if ( ! V_88 )
return - V_143 ;
V_88 -> V_10 = V_6 -> V_10 + V_6 -> V_8 [ V_288 ] ;
V_88 -> V_90 = V_421 -> V_424 ;
V_88 -> V_85 . V_425 = & V_426 ;
V_6 -> V_272 = F_189 ( & V_88 -> V_85 ) ;
if ( ! V_6 -> V_272 )
return - V_143 ;
V_6 -> V_272 -> V_372 = L_19 ;
V_6 -> V_272 -> V_265 = V_110 ;
snprintf ( V_6 -> V_272 -> V_273 , V_270 , L_20 ,
V_221 -> V_372 , V_221 -> V_273 ) ;
if ( V_110 -> V_266 ) {
V_54 = F_190 ( V_6 -> V_272 , V_110 -> V_266 ) ;
} else {
if ( V_421 -> V_427 > 0 )
V_6 -> V_272 -> V_245 [ V_421 -> V_428 ] = V_421 -> V_427 ;
V_54 = F_191 ( V_6 -> V_272 ) ;
}
if ( V_54 )
goto V_429;
return 0 ;
V_429:
F_186 ( V_6 -> V_272 ) ;
return V_54 ;
}
static const T_2 * F_192 ( int V_430 )
{
const T_2 * V_8 = NULL ;
switch ( V_430 ) {
case V_431 :
V_8 = V_13 ;
break;
case V_432 :
V_8 = V_14 ;
break;
case V_433 :
V_8 = V_434 ;
break;
case V_435 :
V_8 = V_436 ;
break;
case V_437 :
V_8 = V_438 ;
break;
}
return V_8 ;
}
static struct V_420 * F_193 ( struct V_423 * V_110 )
{
struct V_263 * V_264 = V_110 -> V_266 ;
struct V_420 * V_439 ;
const char * V_440 ;
V_439 = F_188 ( V_110 , sizeof( * V_439 ) , V_142 ) ;
if ( ! V_439 )
return NULL ;
V_439 -> V_16 = F_194 ( V_264 ) ;
V_440 = F_195 ( V_264 ) ;
if ( V_440 )
memcpy ( V_439 -> V_440 , V_440 , V_81 ) ;
V_439 -> V_224 =
F_196 ( V_264 , L_21 ) ;
V_439 -> V_226 =
F_196 ( V_264 , L_22 ) ;
return V_439 ;
}
static inline struct V_420 * F_193 ( struct V_423 * V_110 )
{
return NULL ;
}
static int F_197 ( struct V_422 * V_221 )
{
struct V_441 * V_442 ;
struct V_420 * V_421 = F_198 ( & V_221 -> V_110 ) ;
const struct V_443 * V_273 = F_199 ( V_221 ) ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_54 , V_444 ;
V_442 = F_200 ( V_221 , V_445 , 0 ) ;
V_2 = F_201 ( sizeof( struct V_5 ) ) ;
if ( ! V_2 )
return - V_143 ;
F_202 ( & V_221 -> V_110 ) ;
F_118 ( & V_221 -> V_110 ) ;
V_444 = V_221 -> V_273 ;
if ( V_444 < 0 )
V_444 = 0 ;
V_54 = F_203 ( V_221 , 0 ) ;
if ( V_54 < 0 )
goto V_446;
V_2 -> V_245 = V_54 ;
F_204 ( V_2 , & V_221 -> V_110 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_104 = V_447 ;
V_6 -> V_120 = V_448 ;
V_6 -> V_10 = F_205 ( & V_221 -> V_110 , V_442 ) ;
if ( F_98 ( V_6 -> V_10 ) ) {
V_54 = F_99 ( V_6 -> V_10 ) ;
goto V_446;
}
V_6 -> V_368 = F_206 ( & V_221 -> V_110 , NULL ) ;
if ( F_98 ( V_6 -> V_368 ) )
V_6 -> V_368 = NULL ;
V_2 -> V_449 = V_442 -> V_450 ;
F_207 ( & V_6 -> V_249 ) ;
V_6 -> V_221 = V_221 ;
if ( V_221 -> V_110 . V_266 )
V_421 = F_193 ( & V_221 -> V_110 ) ;
if ( ! V_421 ) {
F_208 ( & V_221 -> V_110 , L_23 ) ;
V_54 = - V_359 ;
goto V_446;
}
V_6 -> V_269 = V_421 -> V_428 ;
V_6 -> V_16 = V_421 -> V_16 ;
V_6 -> V_224 = V_421 -> V_224 ;
V_6 -> V_226 = V_421 -> V_226 ;
if ( V_273 )
V_6 -> V_38 = (struct V_37 * ) V_273 -> V_451 ;
else
V_6 -> V_38 = (struct V_37 * ) F_209 ( & V_221 -> V_110 ) ;
V_6 -> V_8 = F_192 ( V_6 -> V_38 -> V_430 ) ;
if ( ! V_6 -> V_8 ) {
F_208 ( & V_221 -> V_110 , L_24 ,
V_6 -> V_38 -> V_430 ) ;
V_54 = - V_359 ;
goto V_446;
}
F_25 ( V_6 -> V_38 ) ;
V_2 -> V_452 = 2000 - ( V_163 + V_164 + V_165 ) ;
V_2 -> V_453 = V_454 ;
if ( V_6 -> V_38 -> V_306 )
V_2 -> V_455 = & V_456 ;
else
V_2 -> V_455 = & V_457 ;
V_2 -> V_458 = & V_459 ;
V_2 -> V_460 = V_461 ;
V_6 -> V_341 = V_462 ;
F_32 ( V_2 , V_421 -> V_440 ) ;
if ( ! F_210 ( V_2 -> V_77 ) ) {
F_211 ( & V_221 -> V_110 ,
L_25 ) ;
F_212 ( V_2 ) ;
}
if ( V_6 -> V_38 -> V_306 ) {
struct V_441 * V_463 ;
V_463 = F_200 ( V_221 , V_445 , 1 ) ;
V_6 -> V_336 = F_205 ( & V_221 -> V_110 , V_463 ) ;
if ( F_98 ( V_6 -> V_336 ) ) {
V_54 = F_99 ( V_6 -> V_336 ) ;
goto V_446;
}
V_6 -> V_391 = V_444 % 2 ;
V_2 -> V_464 = V_465 ;
}
if ( ! V_444 || V_421 -> V_466 ) {
if ( V_6 -> V_38 -> V_467 )
V_6 -> V_38 -> V_467 ( V_2 ) ;
if ( V_6 -> V_38 -> V_306 ) {
F_183 ( V_6 ) ;
}
}
if ( V_6 -> V_38 -> V_145 )
F_1 ( V_2 , 0x1 , V_146 ) ;
V_54 = F_187 ( V_6 , V_421 ) ;
if ( V_54 ) {
if ( V_54 != - V_468 )
F_208 ( & V_221 -> V_110 , L_26 , V_54 ) ;
goto V_446;
}
F_213 ( V_2 , & V_6 -> V_254 , F_87 , 64 ) ;
V_54 = F_214 ( V_2 ) ;
if ( V_54 )
goto V_469;
if ( V_6 -> V_38 -> V_367 && V_6 -> V_368 )
F_215 ( & V_221 -> V_110 , 1 ) ;
F_216 ( V_2 , L_27 ,
( T_1 ) V_2 -> V_449 , V_2 -> V_77 , V_2 -> V_245 ) ;
F_217 ( & V_221 -> V_110 ) ;
F_218 ( V_221 , V_2 ) ;
return V_54 ;
V_469:
F_219 ( & V_6 -> V_254 ) ;
F_184 ( V_6 ) ;
V_446:
if ( V_2 )
F_220 ( V_2 ) ;
F_217 ( & V_221 -> V_110 ) ;
F_221 ( & V_221 -> V_110 ) ;
return V_54 ;
}
static int F_222 ( struct V_422 * V_221 )
{
struct V_1 * V_2 = F_223 ( V_221 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_224 ( V_2 ) ;
F_219 ( & V_6 -> V_254 ) ;
F_184 ( V_6 ) ;
F_221 ( & V_221 -> V_110 ) ;
F_220 ( V_2 ) ;
return 0 ;
}
static int F_225 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_132 ( V_2 -> V_245 ) ;
F_143 ( & V_6 -> V_254 ) ;
F_1 ( V_2 , V_228 , V_149 ) ;
F_7 ( V_2 , V_21 , V_470 , V_470 ) ;
F_226 ( V_6 -> V_368 ) ;
return F_227 ( V_2 -> V_245 ) ;
}
static int F_228 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_54 ;
F_139 ( & V_6 -> V_254 ) ;
F_7 ( V_2 , V_21 , V_470 , 0 ) ;
V_54 = F_151 ( V_2 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_138 ( V_2 ) ;
if ( V_54 < 0 )
return V_54 ;
F_229 ( V_6 -> V_368 ) ;
return F_230 ( V_2 -> V_245 ) ;
}
static int F_231 ( struct V_423 * V_110 )
{
struct V_1 * V_2 = F_232 ( V_110 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_54 = 0 ;
if ( ! F_129 ( V_2 ) )
return 0 ;
F_130 ( V_2 ) ;
if ( V_6 -> V_370 )
V_54 = F_225 ( V_2 ) ;
else
V_54 = F_151 ( V_2 ) ;
return V_54 ;
}
static int F_233 ( struct V_423 * V_110 )
{
struct V_1 * V_2 = F_232 ( V_110 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_54 = 0 ;
if ( ! F_129 ( V_2 ) )
return 0 ;
if ( V_6 -> V_370 )
V_54 = F_228 ( V_2 ) ;
else
V_54 = F_138 ( V_2 ) ;
if ( V_54 < 0 )
return V_54 ;
F_134 ( V_2 ) ;
return V_54 ;
}
static int F_234 ( struct V_423 * V_110 )
{
return 0 ;
}
