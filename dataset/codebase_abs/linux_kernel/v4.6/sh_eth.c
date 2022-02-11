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
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_14 ( V_6 , V_24 , V_25 ) ;
F_15 ( 1 ) ;
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
int V_34 ;
T_1 V_35 [ 2 ] , V_36 [ 2 ] ;
for ( V_34 = 0 ; V_34 < 2 ; V_34 ++ ) {
V_36 [ V_34 ] = F_6 ( ( void * ) F_22 ( V_34 ) ) ;
V_35 [ V_34 ] = F_6 ( ( void * ) F_23 ( V_34 ) ) ;
}
F_4 ( V_24 , ( void * ) ( V_37 + 0x1800 ) ) ;
F_15 ( 1 ) ;
for ( V_34 = 0 ; V_34 < 2 ; V_34 ++ ) {
F_4 ( V_36 [ V_34 ] , ( void * ) F_22 ( V_34 ) ) ;
F_4 ( V_35 [ V_34 ] , ( void * ) F_23 ( V_34 ) ) ;
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
static void F_25 ( struct V_38 * V_39 )
{
if ( ! V_39 -> V_40 )
V_39 -> V_40 = V_41 ;
if ( ! V_39 -> V_42 )
V_39 -> V_42 = V_43 ;
if ( ! V_39 -> V_44 )
V_39 -> V_44 = V_45 |
V_46 ;
if ( ! V_39 -> V_47 )
V_39 -> V_47 = V_48 ;
if ( ! V_39 -> V_49 )
V_39 -> V_49 = V_50 ;
if ( ! V_39 -> V_51 )
V_39 -> V_51 = V_52 ;
if ( ! V_39 -> V_53 )
V_39 -> V_53 = V_54 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_55 = 0 ;
int V_56 = 100 ;
while ( V_56 > 0 ) {
if ( ! ( F_5 ( V_2 , V_57 ) & 0x3 ) )
break;
F_15 ( 1 ) ;
V_56 -- ;
}
if ( V_56 <= 0 ) {
F_27 ( V_2 , L_2 ) ;
V_55 = - V_58 ;
}
return V_55 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_55 = 0 ;
if ( F_8 ( V_6 ) || F_9 ( V_6 ) ) {
F_1 ( V_2 , V_59 , V_60 ) ;
F_7 ( V_2 , V_57 , V_61 , V_61 ) ;
V_55 = F_26 ( V_2 ) ;
if ( V_55 )
return V_55 ;
F_1 ( V_2 , 0x0 , V_62 ) ;
F_1 ( V_2 , 0x0 , V_63 ) ;
F_1 ( V_2 , 0x0 , V_64 ) ;
F_1 ( V_2 , 0x0 , V_65 ) ;
F_1 ( V_2 , 0x0 , V_66 ) ;
F_1 ( V_2 , 0x0 , V_67 ) ;
F_1 ( V_2 , 0x0 , V_68 ) ;
F_1 ( V_2 , 0x0 , V_69 ) ;
if ( V_6 -> V_39 -> V_70 )
F_1 ( V_2 , 0x0 , V_71 ) ;
if ( V_6 -> V_39 -> V_72 )
F_10 ( V_2 ) ;
} else {
F_7 ( V_2 , V_57 , V_73 , V_73 ) ;
F_15 ( 3 ) ;
F_7 ( V_2 , V_57 , V_73 , 0 ) ;
}
return V_55 ;
}
static void F_29 ( struct V_74 * V_75 )
{
T_3 V_76 = ( T_3 ) V_75 -> V_3 & ( V_77 - 1 ) ;
if ( V_76 )
F_30 ( V_75 , V_77 - V_76 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_1 ( V_2 ,
( V_2 -> V_78 [ 0 ] << 24 ) | ( V_2 -> V_78 [ 1 ] << 16 ) |
( V_2 -> V_78 [ 2 ] << 8 ) | ( V_2 -> V_78 [ 3 ] ) , V_79 ) ;
F_1 ( V_2 ,
( V_2 -> V_78 [ 4 ] << 8 ) | ( V_2 -> V_78 [ 5 ] ) , V_80 ) ;
}
static void F_32 ( struct V_1 * V_2 , unsigned char * V_81 )
{
if ( V_81 [ 0 ] || V_81 [ 1 ] || V_81 [ 2 ] || V_81 [ 3 ] || V_81 [ 4 ] || V_81 [ 5 ] ) {
memcpy ( V_2 -> V_78 , V_81 , V_82 ) ;
} else {
T_1 V_35 = F_5 ( V_2 , V_79 ) ;
T_1 V_36 = F_5 ( V_2 , V_80 ) ;
V_2 -> V_78 [ 0 ] = ( V_35 >> 24 ) & 0xFF ;
V_2 -> V_78 [ 1 ] = ( V_35 >> 16 ) & 0xFF ;
V_2 -> V_78 [ 2 ] = ( V_35 >> 8 ) & 0xFF ;
V_2 -> V_78 [ 3 ] = ( V_35 >> 0 ) & 0xFF ;
V_2 -> V_78 [ 4 ] = ( V_36 >> 8 ) & 0xFF ;
V_2 -> V_78 [ 5 ] = ( V_36 >> 0 ) & 0xFF ;
}
}
static T_1 F_33 ( struct V_5 * V_6 )
{
if ( F_8 ( V_6 ) || F_9 ( V_6 ) )
return V_83 ;
else
return V_84 ;
}
static void F_34 ( struct V_85 * V_86 , T_1 V_87 , int V_12 )
{
struct V_88 * V_89 = F_35 ( V_86 , struct V_88 , V_86 ) ;
T_1 V_90 ;
if ( V_89 -> V_91 )
V_89 -> V_91 ( V_89 -> V_10 ) ;
V_90 = F_6 ( V_89 -> V_10 ) ;
if ( V_12 )
V_90 |= V_87 ;
else
V_90 &= ~ V_87 ;
F_4 ( V_90 , V_89 -> V_10 ) ;
}
static void F_36 ( struct V_85 * V_86 , int V_92 )
{
F_34 ( V_86 , V_93 , V_92 ) ;
}
static void F_37 ( struct V_85 * V_86 , int V_92 )
{
F_34 ( V_86 , V_94 , V_92 ) ;
}
static int F_38 ( struct V_85 * V_86 )
{
struct V_88 * V_89 = F_35 ( V_86 , struct V_88 , V_86 ) ;
if ( V_89 -> V_91 )
V_89 -> V_91 ( V_89 -> V_10 ) ;
return ( F_6 ( V_89 -> V_10 ) & V_95 ) != 0 ;
}
static void F_39 ( struct V_85 * V_86 , int V_92 )
{
F_34 ( V_86 , V_96 , V_92 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_97 , V_34 ;
if ( V_6 -> V_98 ) {
for ( V_34 = 0 ; V_34 < V_6 -> V_99 ; V_34 ++ )
F_41 ( V_6 -> V_98 [ V_34 ] ) ;
}
F_42 ( V_6 -> V_98 ) ;
V_6 -> V_98 = NULL ;
if ( V_6 -> V_100 ) {
for ( V_34 = 0 ; V_34 < V_6 -> V_101 ; V_34 ++ )
F_41 ( V_6 -> V_100 [ V_34 ] ) ;
}
F_42 ( V_6 -> V_100 ) ;
V_6 -> V_100 = NULL ;
if ( V_6 -> V_102 ) {
V_97 = sizeof( struct V_103 ) * V_6 -> V_99 ;
F_43 ( NULL , V_97 , V_6 -> V_102 ,
V_6 -> V_104 ) ;
V_6 -> V_102 = NULL ;
}
if ( V_6 -> V_105 ) {
V_97 = sizeof( struct V_106 ) * V_6 -> V_101 ;
F_43 ( NULL , V_97 , V_6 -> V_105 ,
V_6 -> V_107 ) ;
V_6 -> V_105 = NULL ;
}
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_34 ;
struct V_74 * V_75 ;
struct V_103 * V_108 = NULL ;
struct V_106 * V_109 = NULL ;
int V_110 = sizeof( * V_108 ) * V_6 -> V_99 ;
int V_111 = sizeof( * V_109 ) * V_6 -> V_101 ;
int V_112 = V_6 -> V_113 + V_77 + 32 - 1 ;
T_4 V_114 ;
T_1 V_115 ;
V_6 -> V_116 = 0 ;
V_6 -> V_117 = 0 ;
V_6 -> V_118 = 0 ;
V_6 -> V_119 = 0 ;
memset ( V_6 -> V_102 , 0 , V_110 ) ;
for ( V_34 = 0 ; V_34 < V_6 -> V_99 ; V_34 ++ ) {
V_6 -> V_98 [ V_34 ] = NULL ;
V_75 = F_45 ( V_2 , V_112 ) ;
if ( V_75 == NULL )
break;
F_29 ( V_75 ) ;
V_115 = F_46 ( V_6 -> V_113 , 32 ) ;
V_114 = F_47 ( & V_2 -> V_120 , V_75 -> V_3 , V_115 ,
V_121 ) ;
if ( F_48 ( & V_2 -> V_120 , V_114 ) ) {
F_49 ( V_75 ) ;
break;
}
V_6 -> V_98 [ V_34 ] = V_75 ;
V_108 = & V_6 -> V_102 [ V_34 ] ;
V_108 -> V_122 = F_50 ( V_115 << 16 ) ;
V_108 -> V_10 = F_50 ( V_114 ) ;
V_108 -> V_123 = F_50 ( V_124 | V_125 ) ;
if ( V_34 == 0 ) {
F_1 ( V_2 , V_6 -> V_104 , V_66 ) ;
if ( F_8 ( V_6 ) ||
F_9 ( V_6 ) )
F_1 ( V_2 , V_6 -> V_104 , V_67 ) ;
}
}
V_6 -> V_118 = ( T_1 ) ( V_34 - V_6 -> V_99 ) ;
if ( V_108 )
V_108 -> V_123 |= F_50 ( V_126 ) ;
memset ( V_6 -> V_105 , 0 , V_111 ) ;
for ( V_34 = 0 ; V_34 < V_6 -> V_101 ; V_34 ++ ) {
V_6 -> V_100 [ V_34 ] = NULL ;
V_109 = & V_6 -> V_105 [ V_34 ] ;
V_109 -> V_123 = F_50 ( V_127 ) ;
V_109 -> V_122 = F_50 ( 0 ) ;
if ( V_34 == 0 ) {
F_1 ( V_2 , V_6 -> V_107 , V_62 ) ;
if ( F_8 ( V_6 ) ||
F_9 ( V_6 ) )
F_1 ( V_2 , V_6 -> V_107 , V_63 ) ;
}
}
V_109 -> V_123 |= F_50 ( V_128 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_110 , V_111 ;
V_6 -> V_113 = ( V_2 -> V_129 <= 1492 ? V_130 :
( ( ( V_2 -> V_129 + 26 + 7 ) & ~ 7 ) + 2 + 16 ) ) ;
if ( V_6 -> V_39 -> V_131 )
V_6 -> V_113 += V_132 ;
V_6 -> V_98 = F_52 ( V_6 -> V_99 , sizeof( * V_6 -> V_98 ) ,
V_133 ) ;
if ( ! V_6 -> V_98 )
return - V_134 ;
V_6 -> V_100 = F_52 ( V_6 -> V_101 , sizeof( * V_6 -> V_100 ) ,
V_133 ) ;
if ( ! V_6 -> V_100 )
goto V_135;
V_110 = sizeof( struct V_103 ) * V_6 -> V_99 ;
V_6 -> V_102 = F_53 ( NULL , V_110 , & V_6 -> V_104 ,
V_133 ) ;
if ( ! V_6 -> V_102 )
goto V_135;
V_6 -> V_118 = 0 ;
V_111 = sizeof( struct V_106 ) * V_6 -> V_101 ;
V_6 -> V_105 = F_53 ( NULL , V_111 , & V_6 -> V_107 ,
V_133 ) ;
if ( ! V_6 -> V_105 )
goto V_135;
return 0 ;
V_135:
F_40 ( V_2 ) ;
return - V_134 ;
}
static int F_54 ( struct V_1 * V_2 , bool V_136 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_55 ;
V_55 = F_28 ( V_2 ) ;
if ( V_55 )
return V_55 ;
if ( V_6 -> V_39 -> V_137 )
F_1 ( V_2 , 0x1 , V_138 ) ;
F_44 ( V_2 ) ;
if ( V_6 -> V_39 -> V_131 )
F_1 ( V_2 , V_6 -> V_39 -> V_139 , V_140 ) ;
F_1 ( V_2 , 0 , V_141 ) ;
#if F_55 ( V_142 )
if ( V_6 -> V_39 -> V_143 )
F_1 ( V_2 , V_144 , V_57 ) ;
else
#endif
F_1 ( V_2 , 0 , V_57 ) ;
F_1 ( V_2 , V_6 -> V_39 -> V_47 , V_145 ) ;
F_1 ( V_2 , 0 , V_146 ) ;
F_1 ( V_2 , V_147 , V_148 ) ;
F_1 ( V_2 , V_6 -> V_39 -> V_53 , V_149 ) ;
if ( V_6 -> V_39 -> V_150 )
F_1 ( V_2 , 0x800 , V_151 ) ;
F_1 ( V_2 , V_6 -> V_39 -> V_44 , V_152 ) ;
if ( ! V_6 -> V_39 -> V_153 )
F_1 ( V_2 , 0 , V_154 ) ;
F_1 ( V_2 , V_2 -> V_129 + V_155 + V_156 + V_157 ,
V_158 ) ;
F_7 ( V_2 , V_159 , 0 , 0 ) ;
if ( V_136 ) {
V_6 -> V_160 = true ;
F_1 ( V_2 , V_6 -> V_39 -> V_161 , V_141 ) ;
}
F_1 ( V_2 , V_162 | ( V_6 -> V_23 ? V_22 : 0 ) |
V_163 | V_164 , V_21 ) ;
if ( V_6 -> V_39 -> V_165 )
V_6 -> V_39 -> V_165 ( V_2 ) ;
F_1 ( V_2 , V_6 -> V_39 -> V_40 , V_166 ) ;
if ( V_136 )
F_1 ( V_2 , V_6 -> V_39 -> V_42 , V_167 ) ;
F_31 ( V_2 ) ;
if ( V_6 -> V_39 -> V_168 )
F_1 ( V_2 , V_169 , V_170 ) ;
if ( V_6 -> V_39 -> V_171 )
F_1 ( V_2 , V_172 , V_173 ) ;
if ( V_6 -> V_39 -> V_174 )
F_1 ( V_2 , V_175 , V_176 ) ;
if ( V_136 ) {
F_1 ( V_2 , V_177 , V_178 ) ;
}
return V_55 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_6 -> V_101 ; V_34 ++ )
V_6 -> V_105 [ V_34 ] . V_123 &= ~ F_50 ( V_179 ) ;
F_57 ( V_2 ) ;
F_1 ( V_2 , 0 , V_178 ) ;
F_58 ( 2 ) ;
F_59 ( V_2 ) ;
F_28 ( V_2 ) ;
F_31 ( V_2 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_106 * V_109 ;
int V_180 = 0 ;
int V_181 ;
for (; V_6 -> V_117 - V_6 -> V_119 > 0 ; V_6 -> V_119 ++ ) {
V_181 = V_6 -> V_119 % V_6 -> V_101 ;
V_109 = & V_6 -> V_105 [ V_181 ] ;
if ( V_109 -> V_123 & F_50 ( V_179 ) )
break;
F_61 () ;
F_62 ( V_6 , V_182 , V_2 ,
L_3 ,
V_181 , F_63 ( V_109 -> V_123 ) ) ;
if ( V_6 -> V_100 [ V_181 ] ) {
F_64 ( & V_2 -> V_120 , F_63 ( V_109 -> V_10 ) ,
F_63 ( V_109 -> V_122 ) >> 16 ,
V_183 ) ;
F_65 ( V_6 -> V_100 [ V_181 ] ) ;
V_6 -> V_100 [ V_181 ] = NULL ;
V_180 ++ ;
}
V_109 -> V_123 = F_50 ( V_127 ) ;
if ( V_181 >= V_6 -> V_101 - 1 )
V_109 -> V_123 |= F_50 ( V_128 ) ;
V_2 -> V_184 . V_185 ++ ;
V_2 -> V_184 . V_186 += F_63 ( V_109 -> V_122 ) >> 16 ;
}
return V_180 ;
}
static int F_66 ( struct V_1 * V_2 , T_1 V_187 , int * V_188 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_103 * V_108 ;
int V_181 = V_6 -> V_116 % V_6 -> V_99 ;
int V_189 = ( V_6 -> V_118 + V_6 -> V_99 ) - V_6 -> V_116 ;
int V_190 ;
struct V_74 * V_75 ;
T_1 V_191 ;
int V_112 = V_6 -> V_113 + V_77 + 32 - 1 ;
T_4 V_114 ;
T_2 V_192 ;
T_1 V_115 ;
V_189 = F_67 ( V_189 , * V_188 ) ;
V_190 = V_189 ;
V_108 = & V_6 -> V_102 [ V_181 ] ;
while ( ! ( V_108 -> V_123 & F_50 ( V_124 ) ) ) {
F_61 () ;
V_191 = F_63 ( V_108 -> V_123 ) ;
V_192 = F_63 ( V_108 -> V_122 ) & V_193 ;
if ( -- V_189 < 0 )
break;
F_62 ( V_6 , V_194 , V_2 ,
L_4 ,
V_181 , V_191 , V_192 ) ;
if ( ! ( V_191 & V_195 ) )
V_2 -> V_184 . V_196 ++ ;
if ( V_6 -> V_39 -> V_197 )
V_191 >>= 16 ;
V_75 = V_6 -> V_98 [ V_181 ] ;
if ( V_191 & ( V_198 | V_199 | V_200 | V_201 |
V_202 | V_203 | V_204 ) ) {
V_2 -> V_184 . V_205 ++ ;
if ( V_191 & V_198 )
V_2 -> V_184 . V_206 ++ ;
if ( V_191 & V_199 )
V_2 -> V_184 . V_207 ++ ;
if ( V_191 & V_200 )
V_2 -> V_184 . V_196 ++ ;
if ( V_191 & V_201 )
V_2 -> V_184 . V_196 ++ ;
if ( V_191 & V_203 )
V_2 -> V_184 . V_208 ++ ;
if ( V_191 & V_204 )
V_2 -> V_184 . V_209 ++ ;
} else if ( V_75 ) {
V_114 = F_63 ( V_108 -> V_10 ) ;
if ( ! V_6 -> V_39 -> V_143 )
F_68 (
F_69 ( F_46 ( V_114 , 4 ) ) ,
V_192 + 2 ) ;
V_6 -> V_98 [ V_181 ] = NULL ;
if ( V_6 -> V_39 -> V_131 )
F_30 ( V_75 , V_132 ) ;
F_64 ( & V_2 -> V_120 , V_114 ,
F_46 ( V_6 -> V_113 , 32 ) ,
V_121 ) ;
F_70 ( V_75 , V_192 ) ;
V_75 -> V_210 = F_71 ( V_75 , V_2 ) ;
F_72 ( V_75 ) ;
V_2 -> V_184 . V_211 ++ ;
V_2 -> V_184 . V_212 += V_192 ;
if ( V_191 & V_213 )
V_2 -> V_184 . V_214 ++ ;
}
V_181 = ( ++ V_6 -> V_116 ) % V_6 -> V_99 ;
V_108 = & V_6 -> V_102 [ V_181 ] ;
}
for (; V_6 -> V_116 - V_6 -> V_118 > 0 ; V_6 -> V_118 ++ ) {
V_181 = V_6 -> V_118 % V_6 -> V_99 ;
V_108 = & V_6 -> V_102 [ V_181 ] ;
V_115 = F_46 ( V_6 -> V_113 , 32 ) ;
V_108 -> V_122 = F_50 ( V_115 << 16 ) ;
if ( V_6 -> V_98 [ V_181 ] == NULL ) {
V_75 = F_45 ( V_2 , V_112 ) ;
if ( V_75 == NULL )
break;
F_29 ( V_75 ) ;
V_114 = F_47 ( & V_2 -> V_120 , V_75 -> V_3 ,
V_115 , V_121 ) ;
if ( F_48 ( & V_2 -> V_120 , V_114 ) ) {
F_49 ( V_75 ) ;
break;
}
V_6 -> V_98 [ V_181 ] = V_75 ;
F_73 ( V_75 ) ;
V_108 -> V_10 = F_50 ( V_114 ) ;
}
F_74 () ;
if ( V_181 >= V_6 -> V_99 - 1 )
V_108 -> V_123 |=
F_50 ( V_124 | V_125 | V_126 ) ;
else
V_108 -> V_123 |= F_50 ( V_124 | V_125 ) ;
}
if ( ! ( F_5 ( V_2 , V_178 ) & V_177 ) ) {
if ( V_187 & V_215 &&
V_6 -> V_8 [ V_67 ] != V_9 ) {
T_1 V_216 = ( F_5 ( V_2 , V_67 ) -
F_5 ( V_2 , V_66 ) ) >> 4 ;
V_6 -> V_116 = V_216 ;
V_6 -> V_118 = V_216 ;
}
F_1 ( V_2 , V_177 , V_178 ) ;
}
* V_188 -= V_190 - V_189 - 1 ;
return * V_188 <= 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_21 , V_164 | V_163 , 0 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_21 , V_164 | V_163 , V_164 | V_163 ) ;
}
static void F_76 ( struct V_1 * V_2 , T_1 V_187 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_217 ;
T_1 V_218 ;
T_1 V_87 ;
if ( V_187 & V_219 ) {
V_217 = F_5 ( V_2 , V_166 ) ;
F_1 ( V_2 , V_217 , V_166 ) ;
if ( V_217 & V_220 )
V_2 -> V_184 . V_221 ++ ;
if ( V_217 & V_222 ) {
if ( V_6 -> V_39 -> V_223 || V_6 -> V_224 ) {
goto V_225;
} else {
V_218 = ( F_5 ( V_2 , V_226 ) ) ;
if ( V_6 -> V_227 )
V_218 = ~ V_218 ;
}
if ( ! ( V_218 & V_228 ) ) {
F_57 ( V_2 ) ;
} else {
F_7 ( V_2 , V_141 , V_229 , 0 ) ;
F_7 ( V_2 , V_166 , 0 , 0 ) ;
F_7 ( V_2 , V_141 , V_229 ,
V_229 ) ;
F_75 ( V_2 ) ;
}
}
}
V_225:
if ( V_187 & V_230 ) {
if ( V_187 & V_231 ) {
V_2 -> V_184 . V_232 ++ ;
F_77 ( V_6 , V_233 , V_2 , L_5 ) ;
}
}
if ( V_187 & V_234 ) {
if ( V_187 & V_235 ) {
V_2 -> V_184 . V_207 ++ ;
}
}
if ( V_187 & V_236 ) {
V_2 -> V_184 . V_237 ++ ;
F_77 ( V_6 , V_233 , V_2 , L_6 ) ;
}
if ( V_187 & V_238 ) {
V_2 -> V_184 . V_237 ++ ;
F_77 ( V_6 , V_233 , V_2 , L_7 ) ;
}
if ( V_187 & V_215 ) {
V_2 -> V_184 . V_209 ++ ;
}
if ( V_187 & V_239 ) {
V_2 -> V_184 . V_240 ++ ;
}
if ( ! V_6 -> V_39 -> V_241 && ( V_187 & V_242 ) ) {
V_2 -> V_184 . V_237 ++ ;
F_77 ( V_6 , V_233 , V_2 , L_8 ) ;
}
V_87 = V_230 | V_231 | V_242 | V_236 | V_238 ;
if ( V_6 -> V_39 -> V_241 )
V_87 &= ~ V_242 ;
if ( V_187 & V_87 ) {
T_1 V_243 = F_5 ( V_2 , V_244 ) ;
F_27 ( V_2 , L_9 ,
V_187 , V_6 -> V_117 , V_6 -> V_119 ,
( T_1 ) V_2 -> V_245 , V_243 ) ;
F_60 ( V_2 ) ;
if ( V_243 ^ F_33 ( V_6 ) ) {
F_1 ( V_2 , F_33 ( V_6 ) , V_244 ) ;
}
F_78 ( V_2 ) ;
}
}
static T_5 F_79 ( int V_246 , void * V_247 )
{
struct V_1 * V_2 = V_247 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_38 * V_39 = V_6 -> V_39 ;
T_5 V_55 = V_248 ;
T_1 V_187 , V_249 ;
F_80 ( & V_6 -> V_250 ) ;
V_187 = F_5 ( V_2 , V_159 ) ;
V_249 = F_5 ( V_2 , V_141 ) ;
V_187 &= V_249 | V_229 ;
if ( V_187 & ( V_251 | V_39 -> V_49 | V_39 -> V_51 ) )
V_55 = V_252 ;
else
goto V_253;
if ( ! F_81 ( V_6 -> V_160 ) ) {
F_1 ( V_2 , 0 , V_141 ) ;
goto V_253;
}
if ( V_187 & V_251 ) {
if ( F_82 ( & V_6 -> V_254 ) ) {
F_1 ( V_2 , V_249 & ~ V_251 ,
V_141 ) ;
F_83 ( & V_6 -> V_254 ) ;
} else {
F_11 ( V_2 ,
L_10 ,
V_187 , V_249 ) ;
}
}
if ( V_187 & V_39 -> V_49 ) {
F_1 ( V_2 , V_187 & V_39 -> V_49 , V_159 ) ;
F_60 ( V_2 ) ;
F_78 ( V_2 ) ;
}
if ( V_187 & V_39 -> V_51 ) {
F_1 ( V_2 , V_187 & V_39 -> V_51 , V_159 ) ;
F_76 ( V_2 , V_187 ) ;
}
V_253:
F_84 ( & V_6 -> V_250 ) ;
return V_55 ;
}
static int F_85 ( struct V_255 * V_254 , int V_256 )
{
struct V_5 * V_6 = F_35 ( V_254 , struct V_5 ,
V_254 ) ;
struct V_1 * V_2 = V_254 -> V_120 ;
int V_188 = V_256 ;
T_1 V_187 ;
for (; ; ) {
V_187 = F_5 ( V_2 , V_159 ) ;
if ( ! ( V_187 & V_251 ) )
break;
F_1 ( V_2 , V_187 & V_251 , V_159 ) ;
if ( F_66 ( V_2 , V_187 , & V_188 ) )
goto V_253;
}
F_86 ( V_254 ) ;
if ( V_6 -> V_160 )
F_1 ( V_2 , V_6 -> V_39 -> V_161 , V_141 ) ;
V_253:
return V_256 - V_188 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_257 * V_258 = V_6 -> V_258 ;
int V_259 = 0 ;
if ( V_258 -> V_260 ) {
if ( V_258 -> V_23 != V_6 -> V_23 ) {
V_259 = 1 ;
V_6 -> V_23 = V_258 -> V_23 ;
if ( V_6 -> V_39 -> V_261 )
V_6 -> V_39 -> V_261 ( V_2 ) ;
}
if ( V_258 -> V_26 != V_6 -> V_26 ) {
V_259 = 1 ;
V_6 -> V_26 = V_258 -> V_26 ;
if ( V_6 -> V_39 -> V_165 )
V_6 -> V_39 -> V_165 ( V_2 ) ;
}
if ( ! V_6 -> V_260 ) {
F_7 ( V_2 , V_21 , V_262 , 0 ) ;
V_259 = 1 ;
V_6 -> V_260 = V_258 -> V_260 ;
if ( V_6 -> V_39 -> V_223 || V_6 -> V_224 )
F_75 ( V_2 ) ;
}
} else if ( V_6 -> V_260 ) {
V_259 = 1 ;
V_6 -> V_260 = 0 ;
V_6 -> V_26 = 0 ;
V_6 -> V_23 = - 1 ;
if ( V_6 -> V_39 -> V_223 || V_6 -> V_224 )
F_57 ( V_2 ) ;
}
if ( V_259 && F_88 ( V_6 ) )
F_89 ( V_258 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_263 * V_264 = V_2 -> V_120 . V_265 -> V_266 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_257 * V_258 ;
V_6 -> V_260 = 0 ;
V_6 -> V_26 = 0 ;
V_6 -> V_23 = - 1 ;
if ( V_264 ) {
struct V_263 * V_267 ;
V_267 = F_91 ( V_264 , L_11 , 0 ) ;
V_258 = F_92 ( V_2 , V_267 ,
F_87 , 0 ,
V_6 -> V_16 ) ;
if ( ! V_258 )
V_258 = F_93 ( - V_268 ) ;
} else {
char V_269 [ V_270 + 3 ] ;
snprintf ( V_269 , sizeof( V_269 ) , V_271 ,
V_6 -> V_272 -> V_273 , V_6 -> V_269 ) ;
V_258 = F_94 ( V_2 , V_269 , F_87 ,
V_6 -> V_16 ) ;
}
if ( F_95 ( V_258 ) ) {
F_27 ( V_2 , L_12 ) ;
return F_96 ( V_258 ) ;
}
F_97 ( V_258 ) ;
V_6 -> V_258 = V_258 ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_55 ;
V_55 = F_90 ( V_2 ) ;
if ( V_55 )
return V_55 ;
F_99 ( V_6 -> V_258 ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_274 * V_275 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_276 ;
int V_55 ;
if ( ! V_6 -> V_258 )
return - V_277 ;
F_101 ( & V_6 -> V_250 , V_276 ) ;
V_55 = F_102 ( V_6 -> V_258 , V_275 ) ;
F_103 ( & V_6 -> V_250 , V_276 ) ;
return V_55 ;
}
static int F_104 ( struct V_1 * V_2 ,
struct V_274 * V_275 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_276 ;
int V_55 ;
if ( ! V_6 -> V_258 )
return - V_277 ;
F_101 ( & V_6 -> V_250 , V_276 ) ;
F_57 ( V_2 ) ;
V_55 = F_105 ( V_6 -> V_258 , V_275 ) ;
if ( V_55 )
goto V_278;
if ( V_275 -> V_23 == V_279 )
V_6 -> V_23 = 1 ;
else
V_6 -> V_23 = 0 ;
if ( V_6 -> V_39 -> V_261 )
V_6 -> V_39 -> V_261 ( V_2 ) ;
V_278:
F_15 ( 1 ) ;
F_75 ( V_2 ) ;
F_103 ( & V_6 -> V_250 , V_276 ) ;
return V_55 ;
}
static T_6 F_106 ( struct V_1 * V_2 , T_1 * V_280 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_38 * V_39 = V_6 -> V_39 ;
T_1 * V_281 ;
T_6 V_122 ;
F_107 ( V_282 > V_283 ) ;
V_122 = F_108 ( V_283 , 32 ) ;
if ( V_280 ) {
V_281 = V_280 ;
V_280 += V_122 ;
} else {
V_281 = NULL ;
}
#define F_109 ( T_7 ) valid_map[reg / 32] |= 1U << (reg % 32)
#define F_110 ( T_7 , T_8 ) do { \
if (mdp->reg_offset[reg] != SH_ETH_OFFSET_INVALID) { \
if (buf) { \
mark_reg_valid(reg); \
*buf++ = read_expr; \
} \
++len; \
} \
} while (0)
#define F_111 ( T_7 ) add_reg_from(reg, sh_eth_read(ndev, reg))
#define F_112 ( T_7 ) add_reg_from(reg, sh_eth_tsu_read(mdp, reg))
F_111 ( V_60 ) ;
F_111 ( V_57 ) ;
F_111 ( V_244 ) ;
F_111 ( V_178 ) ;
F_111 ( V_159 ) ;
F_111 ( V_141 ) ;
F_111 ( V_62 ) ;
F_111 ( V_63 ) ;
F_111 ( V_64 ) ;
F_111 ( V_65 ) ;
F_111 ( V_66 ) ;
F_111 ( V_67 ) ;
F_111 ( V_68 ) ;
F_111 ( V_69 ) ;
F_111 ( V_149 ) ;
F_111 ( V_284 ) ;
F_111 ( V_146 ) ;
F_111 ( V_145 ) ;
F_111 ( V_148 ) ;
F_111 ( V_285 ) ;
F_111 ( V_286 ) ;
if ( V_39 -> V_137 )
F_111 ( V_138 ) ;
F_111 ( V_152 ) ;
if ( V_39 -> V_131 )
F_111 ( V_140 ) ;
if ( ! V_39 -> V_153 )
F_111 ( V_154 ) ;
F_111 ( V_21 ) ;
F_111 ( V_166 ) ;
F_111 ( V_167 ) ;
F_111 ( V_287 ) ;
if ( ! V_39 -> V_223 )
F_111 ( V_226 ) ;
F_111 ( V_288 ) ;
F_111 ( V_158 ) ;
F_111 ( V_289 ) ;
if ( V_39 -> V_168 )
F_111 ( V_170 ) ;
if ( V_39 -> V_171 )
F_111 ( V_173 ) ;
F_111 ( V_290 ) ;
F_111 ( V_291 ) ;
if ( V_39 -> V_174 )
F_111 ( V_176 ) ;
F_111 ( V_292 ) ;
F_111 ( V_28 ) ;
if ( V_39 -> V_150 )
F_111 ( V_151 ) ;
F_111 ( V_79 ) ;
F_111 ( V_80 ) ;
F_111 ( V_293 ) ;
F_111 ( V_294 ) ;
F_111 ( V_295 ) ;
F_111 ( V_296 ) ;
F_111 ( V_297 ) ;
F_111 ( V_298 ) ;
F_111 ( V_299 ) ;
F_111 ( V_300 ) ;
F_111 ( V_301 ) ;
F_111 ( V_302 ) ;
F_111 ( V_303 ) ;
if ( V_39 -> V_304 )
F_111 ( V_33 ) ;
if ( V_39 -> V_70 )
F_111 ( V_71 ) ;
if ( V_39 -> V_72 )
F_111 ( V_20 ) ;
F_111 ( V_25 ) ;
if ( V_39 -> V_305 ) {
F_112 ( V_306 ) ;
F_112 ( V_307 ) ;
F_112 ( V_308 ) ;
F_112 ( V_309 ) ;
F_112 ( V_310 ) ;
F_112 ( V_311 ) ;
F_112 ( V_312 ) ;
F_112 ( V_313 ) ;
F_112 ( V_314 ) ;
F_112 ( V_315 ) ;
F_112 ( V_316 ) ;
F_112 ( V_317 ) ;
F_112 ( V_318 ) ;
F_112 ( V_319 ) ;
F_112 ( V_320 ) ;
F_112 ( V_321 ) ;
F_112 ( V_322 ) ;
F_112 ( V_323 ) ;
F_112 ( V_324 ) ;
F_112 ( V_325 ) ;
F_112 ( V_326 ) ;
F_112 ( V_327 ) ;
F_112 ( V_328 ) ;
F_112 ( V_329 ) ;
F_112 ( V_330 ) ;
F_112 ( V_331 ) ;
F_112 ( V_332 ) ;
if ( V_6 -> V_8 [ V_333 ] != V_9 ) {
if ( V_280 ) {
unsigned int V_34 ;
F_109 ( V_333 ) ;
for ( V_34 = 0 ; V_34 < V_334 * 2 ; V_34 ++ )
* V_280 ++ = F_6 (
V_6 -> V_335 +
V_6 -> V_8 [ V_333 ] +
V_34 * 4 ) ;
}
V_122 += V_334 * 2 ;
}
}
#undef F_109
#undef F_110
#undef F_111
#undef F_112
return V_122 * 4 ;
}
static int F_113 ( struct V_1 * V_2 )
{
return F_106 ( V_2 , NULL ) ;
}
static void F_114 ( struct V_1 * V_2 , struct V_336 * V_337 ,
void * V_280 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_337 -> V_338 = V_339 ;
F_115 ( & V_6 -> V_340 -> V_120 ) ;
F_106 ( V_2 , V_280 ) ;
F_116 ( & V_6 -> V_340 -> V_120 ) ;
}
static int F_117 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_276 ;
int V_55 ;
if ( ! V_6 -> V_258 )
return - V_277 ;
F_101 ( & V_6 -> V_250 , V_276 ) ;
V_55 = F_118 ( V_6 -> V_258 ) ;
F_103 ( & V_6 -> V_250 , V_276 ) ;
return V_55 ;
}
static T_1 F_119 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_341 ;
}
static void F_120 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_341 = V_15 ;
}
static int F_121 ( struct V_1 * V_247 , int V_342 )
{
switch ( V_342 ) {
case V_343 :
return V_344 ;
default:
return - V_345 ;
}
}
static void F_122 ( struct V_1 * V_2 ,
struct V_346 * V_184 , T_9 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_34 = 0 ;
V_3 [ V_34 ++ ] = V_6 -> V_116 ;
V_3 [ V_34 ++ ] = V_6 -> V_117 ;
V_3 [ V_34 ++ ] = V_6 -> V_118 ;
V_3 [ V_34 ++ ] = V_6 -> V_119 ;
}
static void F_123 ( struct V_1 * V_2 , T_1 V_347 , T_10 * V_3 )
{
switch ( V_347 ) {
case V_343 :
memcpy ( V_3 , * V_348 ,
sizeof( V_348 ) ) ;
break;
}
}
static void F_124 ( struct V_1 * V_2 ,
struct V_349 * V_350 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_350 -> V_351 = V_352 ;
V_350 -> V_353 = V_354 ;
V_350 -> V_355 = V_6 -> V_99 ;
V_350 -> V_356 = V_6 -> V_101 ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_349 * V_350 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_55 ;
if ( V_350 -> V_356 > V_354 ||
V_350 -> V_355 > V_352 ||
V_350 -> V_356 < V_357 ||
V_350 -> V_355 < V_358 )
return - V_359 ;
if ( V_350 -> V_360 || V_350 -> V_361 )
return - V_359 ;
if ( F_126 ( V_2 ) ) {
F_127 ( V_2 ) ;
F_128 ( V_2 ) ;
V_6 -> V_160 = false ;
F_129 ( V_2 -> V_246 ) ;
F_130 ( & V_6 -> V_254 ) ;
F_1 ( V_2 , 0x0000 , V_141 ) ;
F_56 ( V_2 ) ;
F_40 ( V_2 ) ;
}
V_6 -> V_99 = V_350 -> V_355 ;
V_6 -> V_101 = V_350 -> V_356 ;
if ( F_126 ( V_2 ) ) {
V_55 = F_51 ( V_2 ) ;
if ( V_55 < 0 ) {
F_27 ( V_2 , L_13 ,
V_362 ) ;
return V_55 ;
}
V_55 = F_54 ( V_2 , true ) ;
if ( V_55 < 0 ) {
F_27 ( V_2 , L_14 ,
V_362 ) ;
return V_55 ;
}
F_131 ( V_2 ) ;
}
return 0 ;
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_55 ;
F_115 ( & V_6 -> V_340 -> V_120 ) ;
F_133 ( & V_6 -> V_254 ) ;
V_55 = F_134 ( V_2 -> V_246 , F_79 ,
V_6 -> V_39 -> V_363 , V_2 -> V_364 , V_2 ) ;
if ( V_55 ) {
F_27 ( V_2 , L_15 ) ;
goto V_365;
}
V_55 = F_51 ( V_2 ) ;
if ( V_55 )
goto V_366;
V_55 = F_54 ( V_2 , true ) ;
if ( V_55 )
goto V_366;
V_55 = F_98 ( V_2 ) ;
if ( V_55 )
goto V_366;
F_135 ( V_2 ) ;
V_6 -> V_367 = 1 ;
return V_55 ;
V_366:
F_136 ( V_2 -> V_246 , V_2 ) ;
V_365:
F_137 ( & V_6 -> V_254 ) ;
F_116 ( & V_6 -> V_340 -> V_120 ) ;
return V_55 ;
}
static void F_138 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_103 * V_108 ;
int V_34 ;
F_139 ( V_2 ) ;
F_77 ( V_6 , V_368 , V_2 ,
L_16 ,
F_5 ( V_2 , V_159 ) ) ;
V_2 -> V_184 . V_369 ++ ;
for ( V_34 = 0 ; V_34 < V_6 -> V_99 ; V_34 ++ ) {
V_108 = & V_6 -> V_102 [ V_34 ] ;
V_108 -> V_123 = F_50 ( 0 ) ;
V_108 -> V_10 = F_50 ( 0xBADF00D0 ) ;
F_41 ( V_6 -> V_98 [ V_34 ] ) ;
V_6 -> V_98 [ V_34 ] = NULL ;
}
for ( V_34 = 0 ; V_34 < V_6 -> V_101 ; V_34 ++ ) {
F_41 ( V_6 -> V_100 [ V_34 ] ) ;
V_6 -> V_100 [ V_34 ] = NULL ;
}
F_54 ( V_2 , true ) ;
F_135 ( V_2 ) ;
}
static int F_140 ( struct V_74 * V_75 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_106 * V_109 ;
T_4 V_114 ;
T_1 V_181 ;
unsigned long V_276 ;
F_101 ( & V_6 -> V_250 , V_276 ) ;
if ( ( V_6 -> V_117 - V_6 -> V_119 ) >= ( V_6 -> V_101 - 4 ) ) {
if ( ! F_60 ( V_2 ) ) {
F_141 ( V_6 , V_370 , V_2 , L_17 ) ;
F_139 ( V_2 ) ;
F_103 ( & V_6 -> V_250 , V_276 ) ;
return V_371 ;
}
}
F_103 ( & V_6 -> V_250 , V_276 ) ;
if ( F_142 ( V_75 , V_372 ) )
return V_373 ;
V_181 = V_6 -> V_117 % V_6 -> V_101 ;
V_6 -> V_100 [ V_181 ] = V_75 ;
V_109 = & V_6 -> V_105 [ V_181 ] ;
if ( ! V_6 -> V_39 -> V_143 )
F_68 ( F_143 ( V_75 -> V_3 , 4 ) , V_75 -> V_122 + 2 ) ;
V_114 = F_47 ( & V_2 -> V_120 , V_75 -> V_3 , V_75 -> V_122 ,
V_183 ) ;
if ( F_48 ( & V_2 -> V_120 , V_114 ) ) {
F_49 ( V_75 ) ;
return V_373 ;
}
V_109 -> V_10 = F_50 ( V_114 ) ;
V_109 -> V_122 = F_50 ( V_75 -> V_122 << 16 ) ;
F_74 () ;
if ( V_181 >= V_6 -> V_101 - 1 )
V_109 -> V_123 |= F_50 ( V_179 | V_128 ) ;
else
V_109 -> V_123 |= F_50 ( V_179 ) ;
V_6 -> V_117 ++ ;
if ( ! ( F_5 ( V_2 , V_244 ) & F_33 ( V_6 ) ) )
F_1 ( V_2 , F_33 ( V_6 ) , V_244 ) ;
return V_373 ;
}
static void
F_144 ( struct V_1 * V_2 , unsigned long * V_374 , int T_7 )
{
T_1 V_375 = F_5 ( V_2 , T_7 ) ;
if ( V_375 ) {
* V_374 += V_375 ;
F_1 ( V_2 , 0 , T_7 ) ;
}
}
static struct V_376 * F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_9 ( V_6 ) )
return & V_2 -> V_184 ;
if ( ! V_6 -> V_367 )
return & V_2 -> V_184 ;
F_144 ( V_2 , & V_2 -> V_184 . V_377 , V_293 ) ;
F_144 ( V_2 , & V_2 -> V_184 . V_378 , V_294 ) ;
F_144 ( V_2 , & V_2 -> V_184 . V_221 , V_295 ) ;
if ( F_8 ( V_6 ) ) {
F_144 ( V_2 , & V_2 -> V_184 . V_221 ,
V_301 ) ;
F_144 ( V_2 , & V_2 -> V_184 . V_221 ,
V_302 ) ;
} else {
F_144 ( V_2 , & V_2 -> V_184 . V_221 ,
V_296 ) ;
}
return & V_2 -> V_184 ;
}
static int F_145 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_139 ( V_2 ) ;
V_6 -> V_160 = false ;
F_129 ( V_2 -> V_246 ) ;
F_137 ( & V_6 -> V_254 ) ;
F_1 ( V_2 , 0x0000 , V_141 ) ;
F_56 ( V_2 ) ;
if ( V_6 -> V_258 ) {
F_146 ( V_6 -> V_258 ) ;
F_147 ( V_6 -> V_258 ) ;
V_6 -> V_258 = NULL ;
}
F_136 ( V_2 -> V_246 , V_2 ) ;
F_40 ( V_2 ) ;
F_116 ( & V_6 -> V_340 -> V_120 ) ;
V_6 -> V_367 = 0 ;
return 0 ;
}
static int F_148 ( struct V_1 * V_2 , struct V_379 * V_380 , int V_381 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_257 * V_258 = V_6 -> V_258 ;
if ( ! F_126 ( V_2 ) )
return - V_359 ;
if ( ! V_258 )
return - V_277 ;
return F_149 ( V_258 , V_380 , V_381 ) ;
}
static void * F_150 ( struct V_5 * V_6 ,
int V_181 )
{
return F_151 ( V_6 , V_329 ) + ( V_181 / 8 * 4 ) ;
}
static T_1 F_152 ( int V_181 )
{
return 0x0f << ( 28 - ( ( V_181 % 8 ) * 4 ) ) ;
}
static T_1 F_153 ( struct V_5 * V_6 , int V_181 )
{
return ( 0x08 >> ( V_6 -> V_382 << 1 ) ) << ( 28 - ( ( V_181 % 8 ) * 4 ) ) ;
}
static void F_154 ( struct V_1 * V_2 ,
int V_181 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_383 ;
void * V_8 ;
V_8 = F_150 ( V_6 , V_181 ) ;
V_383 = F_6 ( V_8 ) ;
F_4 ( V_383 | F_153 ( V_6 , V_181 ) , V_8 ) ;
}
static bool F_155 ( struct V_1 * V_2 ,
int V_181 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_384 , V_385 , V_383 ;
void * V_8 ;
V_8 = F_150 ( V_6 , V_181 ) ;
V_384 = F_152 ( V_181 ) ;
V_385 = F_153 ( V_6 , V_181 ) & ~ V_384 ;
V_383 = F_6 ( V_8 ) ;
F_4 ( V_383 & ~ V_384 , V_8 ) ;
return V_383 & V_385 ;
}
static int F_156 ( struct V_1 * V_2 )
{
int V_386 = V_387 * 100 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
while ( ( F_157 ( V_6 , V_327 ) & V_388 ) ) {
F_158 ( 10 ) ;
V_386 -- ;
if ( V_386 <= 0 ) {
F_27 ( V_2 , L_18 , V_362 ) ;
return - V_58 ;
}
}
return 0 ;
}
static int F_159 ( struct V_1 * V_2 , void * T_7 ,
const T_10 * V_10 )
{
T_1 V_389 ;
V_389 = V_10 [ 0 ] << 24 | V_10 [ 1 ] << 16 | V_10 [ 2 ] << 8 | V_10 [ 3 ] ;
F_4 ( V_389 , T_7 ) ;
if ( F_156 ( V_2 ) < 0 )
return - V_390 ;
V_389 = V_10 [ 4 ] << 8 | V_10 [ 5 ] ;
F_4 ( V_389 , T_7 + 4 ) ;
if ( F_156 ( V_2 ) < 0 )
return - V_390 ;
return 0 ;
}
static void F_160 ( void * T_7 , T_10 * V_10 )
{
T_1 V_389 ;
V_389 = F_6 ( T_7 ) ;
V_10 [ 0 ] = ( V_389 >> 24 ) & 0xff ;
V_10 [ 1 ] = ( V_389 >> 16 ) & 0xff ;
V_10 [ 2 ] = ( V_389 >> 8 ) & 0xff ;
V_10 [ 3 ] = V_389 & 0xff ;
V_389 = F_6 ( T_7 + 4 ) ;
V_10 [ 4 ] = ( V_389 >> 8 ) & 0xff ;
V_10 [ 5 ] = V_389 & 0xff ;
}
static int F_161 ( struct V_1 * V_2 , const T_10 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void * V_8 = F_151 ( V_6 , V_333 ) ;
int V_34 ;
T_10 V_391 [ V_82 ] ;
for ( V_34 = 0 ; V_34 < V_334 ; V_34 ++ , V_8 += 8 ) {
F_160 ( V_8 , V_391 ) ;
if ( F_162 ( V_10 , V_391 ) )
return V_34 ;
}
return - V_268 ;
}
static int F_163 ( struct V_1 * V_2 )
{
T_10 V_392 [ V_82 ] ;
int V_181 ;
memset ( V_392 , 0 , sizeof( V_392 ) ) ;
V_181 = F_161 ( V_2 , V_392 ) ;
return ( V_181 < 0 ) ? - V_134 : V_181 ;
}
static int F_164 ( struct V_1 * V_2 ,
int V_181 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void * V_8 = F_151 ( V_6 , V_333 ) ;
int V_55 ;
T_10 V_392 [ V_82 ] ;
F_14 ( V_6 , F_157 ( V_6 , V_328 ) &
~ ( 1 << ( 31 - V_181 ) ) , V_328 ) ;
memset ( V_392 , 0 , sizeof( V_392 ) ) ;
V_55 = F_159 ( V_2 , V_8 + V_181 * 8 , V_392 ) ;
if ( V_55 < 0 )
return V_55 ;
return 0 ;
}
static int F_165 ( struct V_1 * V_2 , const T_10 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void * V_8 = F_151 ( V_6 , V_333 ) ;
int V_34 , V_55 ;
if ( ! V_6 -> V_39 -> V_305 )
return 0 ;
V_34 = F_161 ( V_2 , V_10 ) ;
if ( V_34 < 0 ) {
V_34 = F_163 ( V_2 ) ;
if ( V_34 < 0 )
return - V_134 ;
V_55 = F_159 ( V_2 , V_8 + V_34 * 8 , V_10 ) ;
if ( V_55 < 0 )
return V_55 ;
F_14 ( V_6 , F_157 ( V_6 , V_328 ) |
( 1 << ( 31 - V_34 ) ) , V_328 ) ;
}
F_154 ( V_2 , V_34 ) ;
return 0 ;
}
static int F_166 ( struct V_1 * V_2 , const T_10 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_34 , V_55 ;
if ( ! V_6 -> V_39 -> V_305 )
return 0 ;
V_34 = F_161 ( V_2 , V_10 ) ;
if ( V_34 ) {
if ( F_155 ( V_2 , V_34 ) )
goto V_393;
V_55 = F_164 ( V_2 , V_34 ) ;
if ( V_55 < 0 )
return V_55 ;
}
V_393:
return 0 ;
}
static int F_167 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_34 , V_55 ;
if ( ! V_6 -> V_39 -> V_305 )
return 0 ;
for ( V_34 = 0 ; V_34 < V_334 ; V_34 ++ ) {
if ( F_155 ( V_2 , V_34 ) )
continue;
V_55 = F_164 ( V_2 , V_34 ) ;
if ( V_55 < 0 )
return V_55 ;
}
return 0 ;
}
static void F_168 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_10 V_10 [ V_82 ] ;
void * V_8 = F_151 ( V_6 , V_333 ) ;
int V_34 ;
if ( ! V_6 -> V_39 -> V_305 )
return;
for ( V_34 = 0 ; V_34 < V_334 ; V_34 ++ , V_8 += 8 ) {
F_160 ( V_8 , V_10 ) ;
if ( F_169 ( V_10 ) )
F_166 ( V_2 , V_10 ) ;
}
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_394 ;
int V_395 = 0 ;
unsigned long V_276 ;
F_101 ( & V_6 -> V_250 , V_276 ) ;
V_394 = F_5 ( V_2 , V_21 ) & ~ V_396 ;
if ( V_6 -> V_39 -> V_305 )
V_394 |= V_397 ;
if ( ! ( V_2 -> V_276 & V_398 ) ) {
F_168 ( V_2 ) ;
V_395 = 1 ;
}
if ( V_2 -> V_276 & V_399 ) {
F_168 ( V_2 ) ;
V_394 &= ~ V_397 ;
V_395 = 1 ;
}
if ( V_2 -> V_276 & V_400 ) {
F_167 ( V_2 ) ;
V_394 = ( V_394 & ~ V_397 ) | V_396 ;
} else if ( V_6 -> V_39 -> V_305 ) {
struct V_401 * V_402 ;
F_171 (ha, ndev) {
if ( V_395 && F_169 ( V_402 -> V_10 ) )
continue;
if ( F_165 ( V_2 , V_402 -> V_10 ) < 0 ) {
if ( ! V_395 ) {
F_168 ( V_2 ) ;
V_394 &= ~ V_397 ;
V_395 = 1 ;
}
}
}
}
F_1 ( V_2 , V_394 , V_21 ) ;
F_103 ( & V_6 -> V_250 , V_276 ) ;
}
static int F_172 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_382 )
return V_325 ;
else
return V_326 ;
}
static int F_173 ( struct V_1 * V_2 ,
T_11 V_403 , T_2 V_404 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_405 = F_172 ( V_6 ) ;
if ( F_174 ( ! V_6 -> V_39 -> V_305 ) )
return - V_406 ;
if ( ! V_404 )
return 0 ;
V_6 -> V_407 ++ ;
if ( V_6 -> V_407 > 1 ) {
F_14 ( V_6 , 0 , V_405 ) ;
return 0 ;
}
F_14 ( V_6 , V_408 | ( V_404 & V_409 ) ,
V_405 ) ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 ,
T_11 V_403 , T_2 V_404 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_405 = F_172 ( V_6 ) ;
if ( F_174 ( ! V_6 -> V_39 -> V_305 ) )
return - V_406 ;
if ( ! V_404 )
return 0 ;
V_6 -> V_407 -- ;
F_14 ( V_6 , 0 , V_405 ) ;
return 0 ;
}
static void F_176 ( struct V_5 * V_6 )
{
if ( F_9 ( V_6 ) ) {
F_14 ( V_6 , 0 , V_328 ) ;
return;
}
F_14 ( V_6 , 0 , V_307 ) ;
F_14 ( V_6 , 0 , V_308 ) ;
F_14 ( V_6 , 0 , V_309 ) ;
F_14 ( V_6 , 0xc , V_310 ) ;
F_14 ( V_6 , 0xc , V_311 ) ;
F_14 ( V_6 , 0 , V_312 ) ;
F_14 ( V_6 , 0 , V_313 ) ;
F_14 ( V_6 , 0 , V_314 ) ;
F_14 ( V_6 , 0 , V_315 ) ;
F_14 ( V_6 , V_410 | V_411 , V_316 ) ;
if ( F_8 ( V_6 ) ) {
F_14 ( V_6 , 0 , V_317 ) ;
F_14 ( V_6 , 0 , V_318 ) ;
} else {
F_14 ( V_6 , 0 , V_319 ) ;
F_14 ( V_6 , 0 , V_320 ) ;
}
F_14 ( V_6 , 0 , V_321 ) ;
F_14 ( V_6 , 0 , V_322 ) ;
F_14 ( V_6 , 0 , V_328 ) ;
F_14 ( V_6 , 0 , V_329 ) ;
F_14 ( V_6 , 0 , V_330 ) ;
F_14 ( V_6 , 0 , V_331 ) ;
F_14 ( V_6 , 0 , V_332 ) ;
}
static int F_177 ( struct V_5 * V_6 )
{
F_178 ( V_6 -> V_272 ) ;
F_179 ( V_6 -> V_272 ) ;
return 0 ;
}
static int F_180 ( struct V_5 * V_6 ,
struct V_412 * V_413 )
{
int V_55 ;
struct V_88 * V_89 ;
struct V_414 * V_340 = V_6 -> V_340 ;
struct V_415 * V_120 = & V_6 -> V_340 -> V_120 ;
V_89 = F_181 ( V_120 , sizeof( struct V_88 ) , V_133 ) ;
if ( ! V_89 )
return - V_134 ;
V_89 -> V_10 = V_6 -> V_10 + V_6 -> V_8 [ V_287 ] ;
V_89 -> V_91 = V_413 -> V_416 ;
V_89 -> V_86 . V_417 = & V_418 ;
V_6 -> V_272 = F_182 ( & V_89 -> V_86 ) ;
if ( ! V_6 -> V_272 )
return - V_134 ;
V_6 -> V_272 -> V_364 = L_19 ;
V_6 -> V_272 -> V_265 = V_120 ;
snprintf ( V_6 -> V_272 -> V_273 , V_270 , L_20 ,
V_340 -> V_364 , V_340 -> V_273 ) ;
if ( V_120 -> V_266 ) {
V_55 = F_183 ( V_6 -> V_272 , V_120 -> V_266 ) ;
} else {
if ( V_413 -> V_419 > 0 )
V_6 -> V_272 -> V_246 [ V_413 -> V_420 ] = V_413 -> V_419 ;
V_55 = F_184 ( V_6 -> V_272 ) ;
}
if ( V_55 )
goto V_421;
return 0 ;
V_421:
F_179 ( V_6 -> V_272 ) ;
return V_55 ;
}
static const T_2 * F_185 ( int V_422 )
{
const T_2 * V_8 = NULL ;
switch ( V_422 ) {
case V_423 :
V_8 = V_13 ;
break;
case V_424 :
V_8 = V_14 ;
break;
case V_425 :
V_8 = V_426 ;
break;
case V_427 :
V_8 = V_428 ;
break;
case V_429 :
V_8 = V_430 ;
break;
}
return V_8 ;
}
static struct V_412 * F_186 ( struct V_415 * V_120 )
{
struct V_263 * V_264 = V_120 -> V_266 ;
struct V_412 * V_431 ;
const char * V_432 ;
V_431 = F_181 ( V_120 , sizeof( * V_431 ) , V_133 ) ;
if ( ! V_431 )
return NULL ;
V_431 -> V_16 = F_187 ( V_264 ) ;
V_432 = F_188 ( V_264 ) ;
if ( V_432 )
memcpy ( V_431 -> V_432 , V_432 , V_82 ) ;
V_431 -> V_224 =
F_189 ( V_264 , L_21 ) ;
V_431 -> V_227 =
F_189 ( V_264 , L_22 ) ;
return V_431 ;
}
static inline struct V_412 * F_186 ( struct V_415 * V_120 )
{
return NULL ;
}
static int F_190 ( struct V_414 * V_340 )
{
struct V_433 * V_434 ;
struct V_412 * V_413 = F_191 ( & V_340 -> V_120 ) ;
const struct V_435 * V_273 = F_192 ( V_340 ) ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_55 , V_436 ;
V_434 = F_193 ( V_340 , V_437 , 0 ) ;
V_2 = F_194 ( sizeof( struct V_5 ) ) ;
if ( ! V_2 )
return - V_134 ;
F_195 ( & V_340 -> V_120 ) ;
F_115 ( & V_340 -> V_120 ) ;
V_436 = V_340 -> V_273 ;
if ( V_436 < 0 )
V_436 = 0 ;
V_2 -> V_438 = - 1 ;
V_55 = F_196 ( V_340 , 0 ) ;
if ( V_55 < 0 )
goto V_439;
V_2 -> V_246 = V_55 ;
F_197 ( V_2 , & V_340 -> V_120 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_101 = V_440 ;
V_6 -> V_99 = V_441 ;
V_6 -> V_10 = F_198 ( & V_340 -> V_120 , V_434 ) ;
if ( F_95 ( V_6 -> V_10 ) ) {
V_55 = F_96 ( V_6 -> V_10 ) ;
goto V_439;
}
V_2 -> V_442 = V_434 -> V_136 ;
F_199 ( & V_6 -> V_250 ) ;
V_6 -> V_340 = V_340 ;
if ( V_340 -> V_120 . V_266 )
V_413 = F_186 ( & V_340 -> V_120 ) ;
if ( ! V_413 ) {
F_200 ( & V_340 -> V_120 , L_23 ) ;
V_55 = - V_359 ;
goto V_439;
}
V_6 -> V_269 = V_413 -> V_420 ;
V_6 -> V_16 = V_413 -> V_16 ;
V_6 -> V_224 = V_413 -> V_224 ;
V_6 -> V_227 = V_413 -> V_227 ;
if ( V_273 )
V_6 -> V_39 = (struct V_38 * ) V_273 -> V_443 ;
else
V_6 -> V_39 = (struct V_38 * ) F_201 ( & V_340 -> V_120 ) ;
V_6 -> V_8 = F_185 ( V_6 -> V_39 -> V_422 ) ;
if ( ! V_6 -> V_8 ) {
F_200 ( & V_340 -> V_120 , L_24 ,
V_6 -> V_39 -> V_422 ) ;
V_55 = - V_359 ;
goto V_439;
}
F_25 ( V_6 -> V_39 ) ;
if ( V_6 -> V_39 -> V_305 )
V_2 -> V_444 = & V_445 ;
else
V_2 -> V_444 = & V_446 ;
V_2 -> V_447 = & V_448 ;
V_2 -> V_449 = V_450 ;
V_6 -> V_341 = V_451 ;
F_32 ( V_2 , V_413 -> V_432 ) ;
if ( ! F_202 ( V_2 -> V_78 ) ) {
F_203 ( & V_340 -> V_120 ,
L_25 ) ;
F_204 ( V_2 ) ;
}
if ( V_6 -> V_39 -> V_305 ) {
struct V_433 * V_452 ;
V_452 = F_193 ( V_340 , V_437 , 1 ) ;
V_6 -> V_335 = F_198 ( & V_340 -> V_120 , V_452 ) ;
if ( F_95 ( V_6 -> V_335 ) ) {
V_55 = F_96 ( V_6 -> V_335 ) ;
goto V_439;
}
V_6 -> V_382 = V_436 % 2 ;
V_2 -> V_453 = V_454 ;
}
if ( ! V_436 || V_413 -> V_455 ) {
if ( V_6 -> V_39 -> V_456 )
V_6 -> V_39 -> V_456 ( V_2 ) ;
if ( V_6 -> V_39 -> V_305 ) {
F_176 ( V_6 ) ;
}
}
if ( V_6 -> V_39 -> V_137 )
F_1 ( V_2 , 0x1 , V_138 ) ;
V_55 = F_180 ( V_6 , V_413 ) ;
if ( V_55 ) {
F_200 ( & V_2 -> V_120 , L_26 ) ;
goto V_439;
}
F_205 ( V_2 , & V_6 -> V_254 , F_85 , 64 ) ;
V_55 = F_206 ( V_2 ) ;
if ( V_55 )
goto V_457;
F_207 ( V_2 , L_27 ,
( T_1 ) V_2 -> V_442 , V_2 -> V_78 , V_2 -> V_246 ) ;
F_208 ( & V_340 -> V_120 ) ;
F_209 ( V_340 , V_2 ) ;
return V_55 ;
V_457:
F_210 ( & V_6 -> V_254 ) ;
F_177 ( V_6 ) ;
V_439:
if ( V_2 )
F_211 ( V_2 ) ;
F_208 ( & V_340 -> V_120 ) ;
F_212 ( & V_340 -> V_120 ) ;
return V_55 ;
}
static int F_213 ( struct V_414 * V_340 )
{
struct V_1 * V_2 = F_214 ( V_340 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_215 ( V_2 ) ;
F_210 ( & V_6 -> V_254 ) ;
F_177 ( V_6 ) ;
F_212 ( & V_340 -> V_120 ) ;
F_211 ( V_2 ) ;
return 0 ;
}
static int F_216 ( struct V_415 * V_120 )
{
struct V_1 * V_2 = F_217 ( V_120 ) ;
int V_55 = 0 ;
if ( F_126 ( V_2 ) ) {
F_127 ( V_2 ) ;
V_55 = F_145 ( V_2 ) ;
}
return V_55 ;
}
static int F_218 ( struct V_415 * V_120 )
{
struct V_1 * V_2 = F_217 ( V_120 ) ;
int V_55 = 0 ;
if ( F_126 ( V_2 ) ) {
V_55 = F_132 ( V_2 ) ;
if ( V_55 < 0 )
return V_55 ;
F_131 ( V_2 ) ;
}
return V_55 ;
}
static int F_219 ( struct V_415 * V_120 )
{
return 0 ;
}
