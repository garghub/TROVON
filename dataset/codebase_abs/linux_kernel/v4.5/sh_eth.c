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
static bool F_7 ( struct V_5 * V_6 )
{
return V_6 -> V_8 == V_11 ;
}
static bool F_8 ( struct V_5 * V_6 )
{
return V_6 -> V_8 == V_12 ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_13 = 0x0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_14 ) {
case V_15 :
V_13 = 0x2 ;
break;
case V_16 :
V_13 = 0x1 ;
break;
case V_17 :
V_13 = 0x0 ;
break;
default:
F_10 ( V_2 ,
L_1 ) ;
V_13 = 0x1 ;
break;
}
F_1 ( V_2 , V_13 , V_18 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_19 )
F_1 ( V_2 , F_5 ( V_2 , V_20 ) | V_21 , V_20 ) ;
else
F_1 ( V_2 , F_5 ( V_2 , V_20 ) & ~ V_21 , V_20 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_13 ( V_6 , V_22 , V_23 ) ;
F_14 ( 1 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_24 ) {
case 10 :
F_1 ( V_2 , V_25 , V_26 ) ;
break;
case 100 :
F_1 ( V_2 , V_27 , V_26 ) ;
break;
case 1000 :
F_1 ( V_2 , V_28 , V_26 ) ;
break;
default:
break;
}
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_13 ( V_6 , V_22 , V_23 ) ;
F_14 ( 1 ) ;
F_9 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_24 ) {
case 10 :
F_1 ( V_2 , F_5 ( V_2 , V_20 ) & ~ V_29 , V_20 ) ;
break;
case 100 :
F_1 ( V_2 , F_5 ( V_2 , V_20 ) | V_29 , V_20 ) ;
break;
default:
break;
}
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_24 ) {
case 10 :
F_1 ( V_2 , F_5 ( V_2 , V_20 ) & ~ V_30 , V_20 ) ;
break;
case 100 :
F_1 ( V_2 , F_5 ( V_2 , V_20 ) | V_30 , V_20 ) ;
break;
default:
break;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_24 ) {
case 10 :
F_1 ( V_2 , 0 , V_31 ) ;
break;
case 100 :
F_1 ( V_2 , 1 , V_31 ) ;
break;
default:
break;
}
}
static void F_20 ( struct V_1 * V_2 )
{
int V_32 ;
T_1 V_33 [ 2 ] , V_34 [ 2 ] ;
for ( V_32 = 0 ; V_32 < 2 ; V_32 ++ ) {
V_34 [ V_32 ] = F_6 ( ( void * ) F_21 ( V_32 ) ) ;
V_33 [ V_32 ] = F_6 ( ( void * ) F_22 ( V_32 ) ) ;
}
F_4 ( V_22 , ( void * ) ( V_35 + 0x1800 ) ) ;
F_14 ( 1 ) ;
for ( V_32 = 0 ; V_32 < 2 ; V_32 ++ ) {
F_4 ( V_34 [ V_32 ] , ( void * ) F_21 ( V_32 ) ) ;
F_4 ( V_33 [ V_32 ] , ( void * ) F_22 ( V_32 ) ) ;
}
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_24 ) {
case 10 :
F_1 ( V_2 , 0x00000000 , V_26 ) ;
break;
case 100 :
F_1 ( V_2 , 0x00000010 , V_26 ) ;
break;
case 1000 :
F_1 ( V_2 , 0x00000020 , V_26 ) ;
break;
default:
break;
}
}
static void F_24 ( struct V_36 * V_37 )
{
if ( ! V_37 -> V_38 )
V_37 -> V_38 = V_39 ;
if ( ! V_37 -> V_40 )
V_37 -> V_40 = V_41 ;
if ( ! V_37 -> V_42 )
V_37 -> V_42 = V_43 |
V_44 ;
if ( ! V_37 -> V_45 )
V_37 -> V_45 = V_46 ;
if ( ! V_37 -> V_47 )
V_37 -> V_47 = V_48 ;
if ( ! V_37 -> V_49 )
V_37 -> V_49 = V_50 ;
if ( ! V_37 -> V_51 )
V_37 -> V_51 = V_52 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_53 = 0 ;
int V_54 = 100 ;
while ( V_54 > 0 ) {
if ( ! ( F_5 ( V_2 , V_55 ) & 0x3 ) )
break;
F_14 ( 1 ) ;
V_54 -- ;
}
if ( V_54 <= 0 ) {
F_26 ( V_2 , L_2 ) ;
V_53 = - V_56 ;
}
return V_53 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_53 = 0 ;
if ( F_7 ( V_6 ) || F_8 ( V_6 ) ) {
F_1 ( V_2 , V_57 , V_58 ) ;
F_1 ( V_2 , F_5 ( V_2 , V_55 ) | V_59 ,
V_55 ) ;
V_53 = F_25 ( V_2 ) ;
if ( V_53 )
return V_53 ;
F_1 ( V_2 , 0x0 , V_60 ) ;
F_1 ( V_2 , 0x0 , V_61 ) ;
F_1 ( V_2 , 0x0 , V_62 ) ;
F_1 ( V_2 , 0x0 , V_63 ) ;
F_1 ( V_2 , 0x0 , V_64 ) ;
F_1 ( V_2 , 0x0 , V_65 ) ;
F_1 ( V_2 , 0x0 , V_66 ) ;
F_1 ( V_2 , 0x0 , V_67 ) ;
if ( V_6 -> V_37 -> V_68 )
F_1 ( V_2 , 0x0 , V_69 ) ;
if ( V_6 -> V_37 -> V_70 )
F_9 ( V_2 ) ;
} else {
F_1 ( V_2 , F_5 ( V_2 , V_55 ) | V_71 ,
V_55 ) ;
F_14 ( 3 ) ;
F_1 ( V_2 , F_5 ( V_2 , V_55 ) & ~ V_71 ,
V_55 ) ;
}
return V_53 ;
}
static void F_28 ( struct V_72 * V_73 )
{
T_3 V_74 = ( T_3 ) V_73 -> V_3 & ( V_75 - 1 ) ;
if ( V_74 )
F_29 ( V_73 , V_75 - V_74 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_1 ( V_2 ,
( V_2 -> V_76 [ 0 ] << 24 ) | ( V_2 -> V_76 [ 1 ] << 16 ) |
( V_2 -> V_76 [ 2 ] << 8 ) | ( V_2 -> V_76 [ 3 ] ) , V_77 ) ;
F_1 ( V_2 ,
( V_2 -> V_76 [ 4 ] << 8 ) | ( V_2 -> V_76 [ 5 ] ) , V_78 ) ;
}
static void F_31 ( struct V_1 * V_2 , unsigned char * V_79 )
{
if ( V_79 [ 0 ] || V_79 [ 1 ] || V_79 [ 2 ] || V_79 [ 3 ] || V_79 [ 4 ] || V_79 [ 5 ] ) {
memcpy ( V_2 -> V_76 , V_79 , V_80 ) ;
} else {
T_1 V_33 = F_5 ( V_2 , V_77 ) ;
T_1 V_34 = F_5 ( V_2 , V_78 ) ;
V_2 -> V_76 [ 0 ] = ( V_33 >> 24 ) & 0xFF ;
V_2 -> V_76 [ 1 ] = ( V_33 >> 16 ) & 0xFF ;
V_2 -> V_76 [ 2 ] = ( V_33 >> 8 ) & 0xFF ;
V_2 -> V_76 [ 3 ] = ( V_33 >> 0 ) & 0xFF ;
V_2 -> V_76 [ 4 ] = ( V_34 >> 8 ) & 0xFF ;
V_2 -> V_76 [ 5 ] = ( V_34 >> 0 ) & 0xFF ;
}
}
static T_1 F_32 ( struct V_5 * V_6 )
{
if ( F_7 ( V_6 ) || F_8 ( V_6 ) )
return V_81 ;
else
return V_82 ;
}
static void F_33 ( struct V_83 * V_84 , T_1 V_85 , int V_86 )
{
struct V_87 * V_88 = F_34 ( V_84 , struct V_87 , V_84 ) ;
T_1 V_89 ;
if ( V_88 -> V_90 )
V_88 -> V_90 ( V_88 -> V_10 ) ;
V_89 = F_6 ( V_88 -> V_10 ) ;
if ( V_86 )
V_89 |= V_85 ;
else
V_89 &= ~ V_85 ;
F_4 ( V_89 , V_88 -> V_10 ) ;
}
static void F_35 ( struct V_83 * V_84 , int V_91 )
{
F_33 ( V_84 , V_92 , V_91 ) ;
}
static void F_36 ( struct V_83 * V_84 , int V_91 )
{
F_33 ( V_84 , V_93 , V_91 ) ;
}
static int F_37 ( struct V_83 * V_84 )
{
struct V_87 * V_88 = F_34 ( V_84 , struct V_87 , V_84 ) ;
if ( V_88 -> V_90 )
V_88 -> V_90 ( V_88 -> V_10 ) ;
return ( F_6 ( V_88 -> V_10 ) & V_94 ) != 0 ;
}
static void F_38 ( struct V_83 * V_84 , int V_91 )
{
F_33 ( V_84 , V_95 , V_91 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_96 , V_32 ;
if ( V_6 -> V_97 ) {
for ( V_32 = 0 ; V_32 < V_6 -> V_98 ; V_32 ++ )
F_40 ( V_6 -> V_97 [ V_32 ] ) ;
}
F_41 ( V_6 -> V_97 ) ;
V_6 -> V_97 = NULL ;
if ( V_6 -> V_99 ) {
for ( V_32 = 0 ; V_32 < V_6 -> V_100 ; V_32 ++ )
F_40 ( V_6 -> V_99 [ V_32 ] ) ;
}
F_41 ( V_6 -> V_99 ) ;
V_6 -> V_99 = NULL ;
if ( V_6 -> V_101 ) {
V_96 = sizeof( struct V_102 ) * V_6 -> V_98 ;
F_42 ( NULL , V_96 , V_6 -> V_101 ,
V_6 -> V_103 ) ;
V_6 -> V_101 = NULL ;
}
if ( V_6 -> V_104 ) {
V_96 = sizeof( struct V_105 ) * V_6 -> V_100 ;
F_42 ( NULL , V_96 , V_6 -> V_104 ,
V_6 -> V_106 ) ;
V_6 -> V_104 = NULL ;
}
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 ;
struct V_72 * V_73 ;
struct V_102 * V_107 = NULL ;
struct V_105 * V_108 = NULL ;
int V_109 = sizeof( * V_107 ) * V_6 -> V_98 ;
int V_110 = sizeof( * V_108 ) * V_6 -> V_100 ;
int V_111 = V_6 -> V_112 + V_75 + 32 - 1 ;
T_4 V_113 ;
T_1 V_114 ;
V_6 -> V_115 = 0 ;
V_6 -> V_116 = 0 ;
V_6 -> V_117 = 0 ;
V_6 -> V_118 = 0 ;
memset ( V_6 -> V_101 , 0 , V_109 ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_98 ; V_32 ++ ) {
V_6 -> V_97 [ V_32 ] = NULL ;
V_73 = F_44 ( V_2 , V_111 ) ;
if ( V_73 == NULL )
break;
F_28 ( V_73 ) ;
V_107 = & V_6 -> V_101 [ V_32 ] ;
V_114 = F_45 ( V_6 -> V_112 , 32 ) ;
V_107 -> V_119 = F_46 ( V_114 << 16 ) ;
V_113 = F_47 ( & V_2 -> V_120 , V_73 -> V_3 , V_114 ,
V_121 ) ;
if ( F_48 ( & V_2 -> V_120 , V_113 ) ) {
F_49 ( V_73 ) ;
break;
}
V_6 -> V_97 [ V_32 ] = V_73 ;
V_107 -> V_10 = F_46 ( V_113 ) ;
V_107 -> V_122 = F_46 ( V_123 | V_124 ) ;
if ( V_32 == 0 ) {
F_1 ( V_2 , V_6 -> V_103 , V_64 ) ;
if ( F_7 ( V_6 ) ||
F_8 ( V_6 ) )
F_1 ( V_2 , V_6 -> V_103 , V_65 ) ;
}
}
V_6 -> V_117 = ( T_1 ) ( V_32 - V_6 -> V_98 ) ;
V_107 -> V_122 |= F_46 ( V_125 ) ;
memset ( V_6 -> V_104 , 0 , V_110 ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_100 ; V_32 ++ ) {
V_6 -> V_99 [ V_32 ] = NULL ;
V_108 = & V_6 -> V_104 [ V_32 ] ;
V_108 -> V_122 = F_46 ( V_126 ) ;
V_108 -> V_119 = F_46 ( 0 ) ;
if ( V_32 == 0 ) {
F_1 ( V_2 , V_6 -> V_106 , V_60 ) ;
if ( F_7 ( V_6 ) ||
F_8 ( V_6 ) )
F_1 ( V_2 , V_6 -> V_106 , V_61 ) ;
}
}
V_108 -> V_122 |= F_46 ( V_127 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_109 , V_110 ;
V_6 -> V_112 = ( V_2 -> V_128 <= 1492 ? V_129 :
( ( ( V_2 -> V_128 + 26 + 7 ) & ~ 7 ) + 2 + 16 ) ) ;
if ( V_6 -> V_37 -> V_130 )
V_6 -> V_112 += V_131 ;
V_6 -> V_97 = F_51 ( V_6 -> V_98 , sizeof( * V_6 -> V_97 ) ,
V_132 ) ;
if ( ! V_6 -> V_97 )
return - V_133 ;
V_6 -> V_99 = F_51 ( V_6 -> V_100 , sizeof( * V_6 -> V_99 ) ,
V_132 ) ;
if ( ! V_6 -> V_99 )
goto V_134;
V_109 = sizeof( struct V_102 ) * V_6 -> V_98 ;
V_6 -> V_101 = F_52 ( NULL , V_109 , & V_6 -> V_103 ,
V_132 ) ;
if ( ! V_6 -> V_101 )
goto V_134;
V_6 -> V_117 = 0 ;
V_110 = sizeof( struct V_105 ) * V_6 -> V_100 ;
V_6 -> V_104 = F_52 ( NULL , V_110 , & V_6 -> V_106 ,
V_132 ) ;
if ( ! V_6 -> V_104 )
goto V_134;
return 0 ;
V_134:
F_39 ( V_2 ) ;
return - V_133 ;
}
static int F_53 ( struct V_1 * V_2 , bool V_135 )
{
int V_53 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_53 = F_27 ( V_2 ) ;
if ( V_53 )
return V_53 ;
if ( V_6 -> V_37 -> V_136 )
F_1 ( V_2 , 0x1 , V_137 ) ;
F_43 ( V_2 ) ;
if ( V_6 -> V_37 -> V_130 )
F_1 ( V_2 , V_6 -> V_37 -> V_138 , V_139 ) ;
F_1 ( V_2 , 0 , V_140 ) ;
#if F_54 ( V_141 )
if ( V_6 -> V_37 -> V_142 )
F_1 ( V_2 , V_143 , V_55 ) ;
else
#endif
F_1 ( V_2 , 0 , V_55 ) ;
F_1 ( V_2 , V_6 -> V_37 -> V_45 , V_144 ) ;
F_1 ( V_2 , 0 , V_145 ) ;
F_1 ( V_2 , V_146 , V_147 ) ;
F_1 ( V_2 , V_6 -> V_37 -> V_51 , V_148 ) ;
if ( V_6 -> V_37 -> V_149 )
F_1 ( V_2 , 0x800 , V_150 ) ;
F_1 ( V_2 , V_6 -> V_37 -> V_42 , V_151 ) ;
if ( ! V_6 -> V_37 -> V_152 )
F_1 ( V_2 , 0 , V_153 ) ;
F_1 ( V_2 , V_2 -> V_128 + V_154 + V_155 + V_156 ,
V_157 ) ;
F_1 ( V_2 , F_5 ( V_2 , V_158 ) , V_158 ) ;
if ( V_135 ) {
V_6 -> V_159 = true ;
F_1 ( V_2 , V_6 -> V_37 -> V_160 , V_140 ) ;
}
F_1 ( V_2 , V_161 | ( V_6 -> V_19 ? V_21 : 0 ) |
V_162 | V_163 , V_20 ) ;
if ( V_6 -> V_37 -> V_164 )
V_6 -> V_37 -> V_164 ( V_2 ) ;
F_1 ( V_2 , V_6 -> V_37 -> V_38 , V_165 ) ;
if ( V_135 )
F_1 ( V_2 , V_6 -> V_37 -> V_40 , V_166 ) ;
F_30 ( V_2 ) ;
if ( V_6 -> V_37 -> V_167 )
F_1 ( V_2 , V_168 , V_169 ) ;
if ( V_6 -> V_37 -> V_170 )
F_1 ( V_2 , V_171 , V_172 ) ;
if ( V_6 -> V_37 -> V_173 )
F_1 ( V_2 , V_174 , V_175 ) ;
if ( V_135 ) {
F_1 ( V_2 , V_176 , V_177 ) ;
F_55 ( V_2 ) ;
}
return V_53 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_6 -> V_100 ; V_32 ++ )
V_6 -> V_104 [ V_32 ] . V_122 &= ~ F_46 ( V_178 ) ;
F_57 ( V_2 ) ;
F_1 ( V_2 , 0 , V_177 ) ;
F_58 ( 2 ) ;
F_59 ( V_2 ) ;
F_27 ( V_2 ) ;
F_30 ( V_2 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_105 * V_108 ;
int V_179 = 0 ;
int V_180 = 0 ;
for (; V_6 -> V_116 - V_6 -> V_118 > 0 ; V_6 -> V_118 ++ ) {
V_180 = V_6 -> V_118 % V_6 -> V_100 ;
V_108 = & V_6 -> V_104 [ V_180 ] ;
if ( V_108 -> V_122 & F_46 ( V_178 ) )
break;
F_61 () ;
F_62 ( V_6 , V_181 , V_2 ,
L_3 ,
V_180 , F_63 ( V_108 -> V_122 ) ) ;
if ( V_6 -> V_99 [ V_180 ] ) {
F_64 ( & V_2 -> V_120 , F_63 ( V_108 -> V_10 ) ,
F_63 ( V_108 -> V_119 ) >> 16 ,
V_182 ) ;
F_65 ( V_6 -> V_99 [ V_180 ] ) ;
V_6 -> V_99 [ V_180 ] = NULL ;
V_179 ++ ;
}
V_108 -> V_122 = F_46 ( V_126 ) ;
if ( V_180 >= V_6 -> V_100 - 1 )
V_108 -> V_122 |= F_46 ( V_127 ) ;
V_2 -> V_183 . V_184 ++ ;
V_2 -> V_183 . V_185 += F_63 ( V_108 -> V_119 ) >> 16 ;
}
return V_179 ;
}
static int F_66 ( struct V_1 * V_2 , T_1 V_186 , int * V_187 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_102 * V_107 ;
int V_180 = V_6 -> V_115 % V_6 -> V_98 ;
int V_188 = ( V_6 -> V_117 + V_6 -> V_98 ) - V_6 -> V_115 ;
int V_189 ;
struct V_72 * V_73 ;
T_2 V_190 = 0 ;
T_1 V_191 ;
int V_111 = V_6 -> V_112 + V_75 + 32 - 1 ;
T_4 V_113 ;
T_1 V_114 ;
V_188 = F_67 ( V_188 , * V_187 ) ;
V_189 = V_188 ;
V_107 = & V_6 -> V_101 [ V_180 ] ;
while ( ! ( V_107 -> V_122 & F_46 ( V_123 ) ) ) {
F_61 () ;
V_191 = F_63 ( V_107 -> V_122 ) ;
V_190 = F_63 ( V_107 -> V_119 ) & V_192 ;
if ( -- V_188 < 0 )
break;
F_62 ( V_6 , V_193 , V_2 ,
L_4 ,
V_180 , V_191 , V_190 ) ;
if ( ! ( V_191 & V_194 ) )
V_2 -> V_183 . V_195 ++ ;
if ( V_6 -> V_37 -> V_196 )
V_191 >>= 16 ;
V_73 = V_6 -> V_97 [ V_180 ] ;
if ( V_191 & ( V_197 | V_198 | V_199 | V_200 |
V_201 | V_202 | V_203 ) ) {
V_2 -> V_183 . V_204 ++ ;
if ( V_191 & V_197 )
V_2 -> V_183 . V_205 ++ ;
if ( V_191 & V_198 )
V_2 -> V_183 . V_206 ++ ;
if ( V_191 & V_199 )
V_2 -> V_183 . V_195 ++ ;
if ( V_191 & V_200 )
V_2 -> V_183 . V_195 ++ ;
if ( V_191 & V_202 )
V_2 -> V_183 . V_207 ++ ;
if ( V_191 & V_203 )
V_2 -> V_183 . V_208 ++ ;
} else if ( V_73 ) {
V_113 = F_63 ( V_107 -> V_10 ) ;
if ( ! V_6 -> V_37 -> V_142 )
F_68 (
F_69 ( F_45 ( V_113 , 4 ) ) ,
V_190 + 2 ) ;
V_6 -> V_97 [ V_180 ] = NULL ;
if ( V_6 -> V_37 -> V_130 )
F_29 ( V_73 , V_131 ) ;
F_64 ( & V_2 -> V_120 , V_113 ,
F_45 ( V_6 -> V_112 , 32 ) ,
V_121 ) ;
F_70 ( V_73 , V_190 ) ;
V_73 -> V_209 = F_71 ( V_73 , V_2 ) ;
F_72 ( V_73 ) ;
V_2 -> V_183 . V_210 ++ ;
V_2 -> V_183 . V_211 += V_190 ;
if ( V_191 & V_212 )
V_2 -> V_183 . V_213 ++ ;
}
V_180 = ( ++ V_6 -> V_115 ) % V_6 -> V_98 ;
V_107 = & V_6 -> V_101 [ V_180 ] ;
}
for (; V_6 -> V_115 - V_6 -> V_117 > 0 ; V_6 -> V_117 ++ ) {
V_180 = V_6 -> V_117 % V_6 -> V_98 ;
V_107 = & V_6 -> V_101 [ V_180 ] ;
V_114 = F_45 ( V_6 -> V_112 , 32 ) ;
V_107 -> V_119 = F_46 ( V_114 << 16 ) ;
if ( V_6 -> V_97 [ V_180 ] == NULL ) {
V_73 = F_44 ( V_2 , V_111 ) ;
if ( V_73 == NULL )
break;
F_28 ( V_73 ) ;
V_113 = F_47 ( & V_2 -> V_120 , V_73 -> V_3 ,
V_114 , V_121 ) ;
if ( F_48 ( & V_2 -> V_120 , V_113 ) ) {
F_49 ( V_73 ) ;
break;
}
V_6 -> V_97 [ V_180 ] = V_73 ;
F_73 ( V_73 ) ;
V_107 -> V_10 = F_46 ( V_113 ) ;
}
F_74 () ;
if ( V_180 >= V_6 -> V_98 - 1 )
V_107 -> V_122 |=
F_46 ( V_123 | V_124 | V_125 ) ;
else
V_107 -> V_122 |= F_46 ( V_123 | V_124 ) ;
}
if ( ! ( F_5 ( V_2 , V_177 ) & V_176 ) ) {
if ( V_186 & V_214 &&
V_6 -> V_8 [ V_65 ] != V_9 ) {
T_1 V_215 = ( F_5 ( V_2 , V_65 ) -
F_5 ( V_2 , V_64 ) ) >> 4 ;
V_6 -> V_115 = V_215 ;
V_6 -> V_117 = V_215 ;
}
F_1 ( V_2 , V_176 , V_177 ) ;
}
* V_187 -= V_189 - V_188 - 1 ;
return * V_187 <= 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_1 ( V_2 , F_5 ( V_2 , V_20 ) &
~ ( V_163 | V_162 ) , V_20 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
F_1 ( V_2 , F_5 ( V_2 , V_20 ) |
( V_163 | V_162 ) , V_20 ) ;
}
static void F_76 ( struct V_1 * V_2 , T_1 V_186 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_216 ;
T_1 V_217 ;
T_1 V_85 ;
if ( V_186 & V_218 ) {
V_216 = F_5 ( V_2 , V_165 ) ;
F_1 ( V_2 , V_216 , V_165 ) ;
if ( V_216 & V_219 )
V_2 -> V_183 . V_220 ++ ;
if ( V_216 & V_221 ) {
if ( V_6 -> V_37 -> V_222 || V_6 -> V_223 ) {
goto V_224;
} else {
V_217 = ( F_5 ( V_2 , V_225 ) ) ;
if ( V_6 -> V_226 )
V_217 = ~ V_217 ;
}
if ( ! ( V_217 & V_227 ) ) {
F_57 ( V_2 ) ;
} else {
F_1 ( V_2 , F_5 ( V_2 , V_140 ) &
~ V_228 , V_140 ) ;
F_1 ( V_2 , F_5 ( V_2 , V_165 ) ,
V_165 ) ;
F_1 ( V_2 , F_5 ( V_2 , V_140 ) |
V_228 , V_140 ) ;
F_75 ( V_2 ) ;
}
}
}
V_224:
if ( V_186 & V_229 ) {
if ( V_186 & V_230 ) {
V_2 -> V_183 . V_231 ++ ;
F_77 ( V_6 , V_232 , V_2 , L_5 ) ;
}
}
if ( V_186 & V_233 ) {
if ( V_186 & V_234 ) {
V_2 -> V_183 . V_206 ++ ;
}
}
if ( V_186 & V_235 ) {
V_2 -> V_183 . V_236 ++ ;
F_77 ( V_6 , V_232 , V_2 , L_6 ) ;
}
if ( V_186 & V_237 ) {
V_2 -> V_183 . V_236 ++ ;
F_77 ( V_6 , V_232 , V_2 , L_7 ) ;
}
if ( V_186 & V_214 ) {
V_2 -> V_183 . V_208 ++ ;
}
if ( V_186 & V_238 ) {
V_2 -> V_183 . V_239 ++ ;
}
if ( ! V_6 -> V_37 -> V_240 && ( V_186 & V_241 ) ) {
V_2 -> V_183 . V_236 ++ ;
F_77 ( V_6 , V_232 , V_2 , L_8 ) ;
}
V_85 = V_229 | V_230 | V_241 | V_235 | V_237 ;
if ( V_6 -> V_37 -> V_240 )
V_85 &= ~ V_241 ;
if ( V_186 & V_85 ) {
T_1 V_242 = F_5 ( V_2 , V_243 ) ;
F_26 ( V_2 , L_9 ,
V_186 , V_6 -> V_116 , V_6 -> V_118 ,
( T_1 ) V_2 -> V_244 , V_242 ) ;
F_60 ( V_2 ) ;
if ( V_242 ^ F_32 ( V_6 ) ) {
F_1 ( V_2 , F_32 ( V_6 ) , V_243 ) ;
}
F_78 ( V_2 ) ;
}
}
static T_5 F_79 ( int V_245 , void * V_246 )
{
struct V_1 * V_2 = V_246 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_36 * V_37 = V_6 -> V_37 ;
T_5 V_53 = V_247 ;
T_1 V_186 , V_248 ;
F_80 ( & V_6 -> V_249 ) ;
V_186 = F_5 ( V_2 , V_158 ) ;
V_248 = F_5 ( V_2 , V_140 ) ;
V_186 &= V_248 | V_228 ;
if ( V_186 & ( V_250 | V_37 -> V_47 | V_37 -> V_49 ) )
V_53 = V_251 ;
else
goto V_252;
if ( ! F_81 ( V_6 -> V_159 ) ) {
F_1 ( V_2 , 0 , V_140 ) ;
goto V_252;
}
if ( V_186 & V_250 ) {
if ( F_82 ( & V_6 -> V_253 ) ) {
F_1 ( V_2 , V_248 & ~ V_250 ,
V_140 ) ;
F_83 ( & V_6 -> V_253 ) ;
} else {
F_10 ( V_2 ,
L_10 ,
V_186 , V_248 ) ;
}
}
if ( V_186 & V_37 -> V_47 ) {
F_1 ( V_2 , V_186 & V_37 -> V_47 , V_158 ) ;
F_60 ( V_2 ) ;
F_78 ( V_2 ) ;
}
if ( V_186 & V_37 -> V_49 ) {
F_1 ( V_2 , V_186 & V_37 -> V_49 , V_158 ) ;
F_76 ( V_2 , V_186 ) ;
}
V_252:
F_84 ( & V_6 -> V_249 ) ;
return V_53 ;
}
static int F_85 ( struct V_254 * V_253 , int V_255 )
{
struct V_5 * V_6 = F_34 ( V_253 , struct V_5 ,
V_253 ) ;
struct V_1 * V_2 = V_253 -> V_120 ;
int V_187 = V_255 ;
T_1 V_186 ;
for (; ; ) {
V_186 = F_5 ( V_2 , V_158 ) ;
if ( ! ( V_186 & V_250 ) )
break;
F_1 ( V_2 , V_186 & V_250 , V_158 ) ;
if ( F_66 ( V_2 , V_186 , & V_187 ) )
goto V_252;
}
F_86 ( V_253 ) ;
if ( V_6 -> V_159 )
F_1 ( V_2 , V_6 -> V_37 -> V_160 , V_140 ) ;
V_252:
return V_255 - V_187 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_256 * V_257 = V_6 -> V_257 ;
int V_258 = 0 ;
if ( V_257 -> V_259 ) {
if ( V_257 -> V_19 != V_6 -> V_19 ) {
V_258 = 1 ;
V_6 -> V_19 = V_257 -> V_19 ;
if ( V_6 -> V_37 -> V_260 )
V_6 -> V_37 -> V_260 ( V_2 ) ;
}
if ( V_257 -> V_24 != V_6 -> V_24 ) {
V_258 = 1 ;
V_6 -> V_24 = V_257 -> V_24 ;
if ( V_6 -> V_37 -> V_164 )
V_6 -> V_37 -> V_164 ( V_2 ) ;
}
if ( ! V_6 -> V_259 ) {
F_1 ( V_2 ,
F_5 ( V_2 , V_20 ) & ~ V_261 ,
V_20 ) ;
V_258 = 1 ;
V_6 -> V_259 = V_257 -> V_259 ;
if ( V_6 -> V_37 -> V_222 || V_6 -> V_223 )
F_75 ( V_2 ) ;
}
} else if ( V_6 -> V_259 ) {
V_258 = 1 ;
V_6 -> V_259 = 0 ;
V_6 -> V_24 = 0 ;
V_6 -> V_19 = - 1 ;
if ( V_6 -> V_37 -> V_222 || V_6 -> V_223 )
F_57 ( V_2 ) ;
}
if ( V_258 && F_88 ( V_6 ) )
F_89 ( V_257 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_262 * V_263 = V_2 -> V_120 . V_264 -> V_265 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_256 * V_257 = NULL ;
V_6 -> V_259 = 0 ;
V_6 -> V_24 = 0 ;
V_6 -> V_19 = - 1 ;
if ( V_263 ) {
struct V_262 * V_266 ;
V_266 = F_91 ( V_263 , L_11 , 0 ) ;
V_257 = F_92 ( V_2 , V_266 ,
F_87 , 0 ,
V_6 -> V_14 ) ;
if ( ! V_257 )
V_257 = F_93 ( - V_267 ) ;
} else {
char V_268 [ V_269 + 3 ] ;
snprintf ( V_268 , sizeof( V_268 ) , V_270 ,
V_6 -> V_271 -> V_272 , V_6 -> V_268 ) ;
V_257 = F_94 ( V_2 , V_268 , F_87 ,
V_6 -> V_14 ) ;
}
if ( F_95 ( V_257 ) ) {
F_26 ( V_2 , L_12 ) ;
return F_96 ( V_257 ) ;
}
F_97 ( V_257 ) ;
V_6 -> V_257 = V_257 ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_53 ;
V_53 = F_90 ( V_2 ) ;
if ( V_53 )
return V_53 ;
F_99 ( V_6 -> V_257 ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_273 * V_274 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_275 ;
int V_53 ;
if ( ! V_6 -> V_257 )
return - V_276 ;
F_101 ( & V_6 -> V_249 , V_275 ) ;
V_53 = F_102 ( V_6 -> V_257 , V_274 ) ;
F_103 ( & V_6 -> V_249 , V_275 ) ;
return V_53 ;
}
static int F_104 ( struct V_1 * V_2 ,
struct V_273 * V_274 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_275 ;
int V_53 ;
if ( ! V_6 -> V_257 )
return - V_276 ;
F_101 ( & V_6 -> V_249 , V_275 ) ;
F_57 ( V_2 ) ;
V_53 = F_105 ( V_6 -> V_257 , V_274 ) ;
if ( V_53 )
goto V_277;
if ( V_274 -> V_19 == V_278 )
V_6 -> V_19 = 1 ;
else
V_6 -> V_19 = 0 ;
if ( V_6 -> V_37 -> V_260 )
V_6 -> V_37 -> V_260 ( V_2 ) ;
V_277:
F_14 ( 1 ) ;
F_75 ( V_2 ) ;
F_103 ( & V_6 -> V_249 , V_275 ) ;
return V_53 ;
}
static T_6 F_106 ( struct V_1 * V_2 , T_1 * V_279 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_36 * V_37 = V_6 -> V_37 ;
T_1 * V_280 ;
T_6 V_119 ;
F_107 ( V_281 > V_282 ) ;
V_119 = F_108 ( V_282 , 32 ) ;
if ( V_279 ) {
V_280 = V_279 ;
V_279 += V_119 ;
} else {
V_280 = NULL ;
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
F_111 ( V_58 ) ;
F_111 ( V_55 ) ;
F_111 ( V_243 ) ;
F_111 ( V_177 ) ;
F_111 ( V_158 ) ;
F_111 ( V_140 ) ;
F_111 ( V_60 ) ;
F_111 ( V_61 ) ;
F_111 ( V_62 ) ;
F_111 ( V_63 ) ;
F_111 ( V_64 ) ;
F_111 ( V_65 ) ;
F_111 ( V_66 ) ;
F_111 ( V_67 ) ;
F_111 ( V_148 ) ;
F_111 ( V_283 ) ;
F_111 ( V_145 ) ;
F_111 ( V_144 ) ;
F_111 ( V_147 ) ;
F_111 ( V_284 ) ;
F_111 ( V_285 ) ;
if ( V_37 -> V_136 )
F_111 ( V_137 ) ;
F_111 ( V_151 ) ;
if ( V_37 -> V_130 )
F_111 ( V_139 ) ;
if ( ! V_37 -> V_152 )
F_111 ( V_153 ) ;
F_111 ( V_20 ) ;
F_111 ( V_165 ) ;
F_111 ( V_166 ) ;
F_111 ( V_286 ) ;
if ( ! V_37 -> V_222 )
F_111 ( V_225 ) ;
F_111 ( V_287 ) ;
F_111 ( V_157 ) ;
F_111 ( V_288 ) ;
if ( V_37 -> V_167 )
F_111 ( V_169 ) ;
if ( V_37 -> V_170 )
F_111 ( V_172 ) ;
F_111 ( V_289 ) ;
F_111 ( V_290 ) ;
if ( V_37 -> V_173 )
F_111 ( V_175 ) ;
F_111 ( V_291 ) ;
F_111 ( V_26 ) ;
if ( V_37 -> V_149 )
F_111 ( V_150 ) ;
F_111 ( V_77 ) ;
F_111 ( V_78 ) ;
F_111 ( V_292 ) ;
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
if ( V_37 -> V_303 )
F_111 ( V_31 ) ;
if ( V_37 -> V_68 )
F_111 ( V_69 ) ;
if ( V_37 -> V_70 )
F_111 ( V_18 ) ;
F_111 ( V_23 ) ;
if ( V_37 -> V_304 ) {
F_112 ( V_305 ) ;
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
if ( V_6 -> V_8 [ V_332 ] != V_9 ) {
if ( V_279 ) {
unsigned int V_32 ;
F_109 ( V_332 ) ;
for ( V_32 = 0 ; V_32 < V_333 * 2 ; V_32 ++ )
* V_279 ++ = F_6 (
V_6 -> V_334 +
V_6 -> V_8 [ V_332 ] +
V_32 * 4 ) ;
}
V_119 += V_333 * 2 ;
}
}
#undef F_109
#undef F_110
#undef F_111
#undef F_112
return V_119 * 4 ;
}
static int F_113 ( struct V_1 * V_2 )
{
return F_106 ( V_2 , NULL ) ;
}
static void F_114 ( struct V_1 * V_2 , struct V_335 * V_336 ,
void * V_279 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_336 -> V_337 = V_338 ;
F_115 ( & V_6 -> V_339 -> V_120 ) ;
F_106 ( V_2 , V_279 ) ;
F_116 ( & V_6 -> V_339 -> V_120 ) ;
}
static int F_117 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_275 ;
int V_53 ;
if ( ! V_6 -> V_257 )
return - V_276 ;
F_101 ( & V_6 -> V_249 , V_275 ) ;
V_53 = F_118 ( V_6 -> V_257 ) ;
F_103 ( & V_6 -> V_249 , V_275 ) ;
return V_53 ;
}
static T_1 F_119 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_340 ;
}
static void F_120 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_340 = V_13 ;
}
static int F_121 ( struct V_1 * V_246 , int V_341 )
{
switch ( V_341 ) {
case V_342 :
return V_343 ;
default:
return - V_344 ;
}
}
static void F_122 ( struct V_1 * V_2 ,
struct V_345 * V_183 , T_9 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 = 0 ;
V_3 [ V_32 ++ ] = V_6 -> V_115 ;
V_3 [ V_32 ++ ] = V_6 -> V_116 ;
V_3 [ V_32 ++ ] = V_6 -> V_117 ;
V_3 [ V_32 ++ ] = V_6 -> V_118 ;
}
static void F_123 ( struct V_1 * V_2 , T_1 V_346 , T_10 * V_3 )
{
switch ( V_346 ) {
case V_342 :
memcpy ( V_3 , * V_347 ,
sizeof( V_347 ) ) ;
break;
}
}
static void F_124 ( struct V_1 * V_2 ,
struct V_348 * V_349 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_349 -> V_350 = V_351 ;
V_349 -> V_352 = V_353 ;
V_349 -> V_354 = V_6 -> V_98 ;
V_349 -> V_355 = V_6 -> V_100 ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_348 * V_349 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_53 ;
if ( V_349 -> V_355 > V_353 ||
V_349 -> V_354 > V_351 ||
V_349 -> V_355 < V_356 ||
V_349 -> V_354 < V_357 )
return - V_358 ;
if ( V_349 -> V_359 || V_349 -> V_360 )
return - V_358 ;
if ( F_126 ( V_2 ) ) {
F_127 ( V_2 ) ;
F_128 ( V_2 ) ;
V_6 -> V_159 = false ;
F_129 ( V_2 -> V_245 ) ;
F_130 ( & V_6 -> V_253 ) ;
F_1 ( V_2 , 0x0000 , V_140 ) ;
F_56 ( V_2 ) ;
F_39 ( V_2 ) ;
}
V_6 -> V_98 = V_349 -> V_354 ;
V_6 -> V_100 = V_349 -> V_355 ;
if ( F_126 ( V_2 ) ) {
V_53 = F_50 ( V_2 ) ;
if ( V_53 < 0 ) {
F_26 ( V_2 , L_13 ,
V_361 ) ;
return V_53 ;
}
V_53 = F_53 ( V_2 , false ) ;
if ( V_53 < 0 ) {
F_26 ( V_2 , L_14 ,
V_361 ) ;
return V_53 ;
}
V_6 -> V_159 = true ;
F_1 ( V_2 , V_6 -> V_37 -> V_160 , V_140 ) ;
F_1 ( V_2 , V_176 , V_177 ) ;
F_131 ( V_2 ) ;
}
return 0 ;
}
static int F_132 ( struct V_1 * V_2 )
{
int V_53 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_115 ( & V_6 -> V_339 -> V_120 ) ;
F_133 ( & V_6 -> V_253 ) ;
V_53 = F_134 ( V_2 -> V_245 , F_79 ,
V_6 -> V_37 -> V_362 , V_2 -> V_363 , V_2 ) ;
if ( V_53 ) {
F_26 ( V_2 , L_15 ) ;
goto V_364;
}
V_53 = F_50 ( V_2 ) ;
if ( V_53 )
goto V_365;
V_53 = F_53 ( V_2 , true ) ;
if ( V_53 )
goto V_365;
V_53 = F_98 ( V_2 ) ;
if ( V_53 )
goto V_365;
V_6 -> V_366 = 1 ;
return V_53 ;
V_365:
F_135 ( V_2 -> V_245 , V_2 ) ;
V_364:
F_136 ( & V_6 -> V_253 ) ;
F_116 ( & V_6 -> V_339 -> V_120 ) ;
return V_53 ;
}
static void F_137 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_102 * V_107 ;
int V_32 ;
F_138 ( V_2 ) ;
F_77 ( V_6 , V_367 , V_2 ,
L_16 ,
F_5 ( V_2 , V_158 ) ) ;
V_2 -> V_183 . V_368 ++ ;
for ( V_32 = 0 ; V_32 < V_6 -> V_98 ; V_32 ++ ) {
V_107 = & V_6 -> V_101 [ V_32 ] ;
V_107 -> V_122 = F_46 ( 0 ) ;
V_107 -> V_10 = F_46 ( 0xBADF00D0 ) ;
F_40 ( V_6 -> V_97 [ V_32 ] ) ;
V_6 -> V_97 [ V_32 ] = NULL ;
}
for ( V_32 = 0 ; V_32 < V_6 -> V_100 ; V_32 ++ ) {
F_40 ( V_6 -> V_99 [ V_32 ] ) ;
V_6 -> V_99 [ V_32 ] = NULL ;
}
F_53 ( V_2 , true ) ;
}
static int F_139 ( struct V_72 * V_73 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_105 * V_108 ;
T_4 V_113 ;
T_1 V_180 ;
unsigned long V_275 ;
F_101 ( & V_6 -> V_249 , V_275 ) ;
if ( ( V_6 -> V_116 - V_6 -> V_118 ) >= ( V_6 -> V_100 - 4 ) ) {
if ( ! F_60 ( V_2 ) ) {
F_140 ( V_6 , V_369 , V_2 , L_17 ) ;
F_138 ( V_2 ) ;
F_103 ( & V_6 -> V_249 , V_275 ) ;
return V_370 ;
}
}
F_103 ( & V_6 -> V_249 , V_275 ) ;
if ( F_141 ( V_73 , V_371 ) )
return V_372 ;
V_180 = V_6 -> V_116 % V_6 -> V_100 ;
V_6 -> V_99 [ V_180 ] = V_73 ;
V_108 = & V_6 -> V_104 [ V_180 ] ;
if ( ! V_6 -> V_37 -> V_142 )
F_68 ( F_142 ( V_73 -> V_3 , 4 ) , V_73 -> V_119 + 2 ) ;
V_113 = F_47 ( & V_2 -> V_120 , V_73 -> V_3 , V_73 -> V_119 ,
V_182 ) ;
if ( F_48 ( & V_2 -> V_120 , V_113 ) ) {
F_49 ( V_73 ) ;
return V_372 ;
}
V_108 -> V_10 = F_46 ( V_113 ) ;
V_108 -> V_119 = F_46 ( V_73 -> V_119 << 16 ) ;
F_74 () ;
if ( V_180 >= V_6 -> V_100 - 1 )
V_108 -> V_122 |= F_46 ( V_178 | V_127 ) ;
else
V_108 -> V_122 |= F_46 ( V_178 ) ;
V_6 -> V_116 ++ ;
if ( ! ( F_5 ( V_2 , V_243 ) & F_32 ( V_6 ) ) )
F_1 ( V_2 , F_32 ( V_6 ) , V_243 ) ;
return V_372 ;
}
static void
F_143 ( struct V_1 * V_2 , unsigned long * V_373 , int T_7 )
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
if ( F_8 ( V_6 ) )
return & V_2 -> V_183 ;
if ( ! V_6 -> V_366 )
return & V_2 -> V_183 ;
F_143 ( V_2 , & V_2 -> V_183 . V_376 , V_292 ) ;
F_143 ( V_2 , & V_2 -> V_183 . V_377 , V_293 ) ;
F_143 ( V_2 , & V_2 -> V_183 . V_220 , V_294 ) ;
if ( F_7 ( V_6 ) ) {
F_143 ( V_2 , & V_2 -> V_183 . V_220 ,
V_300 ) ;
F_143 ( V_2 , & V_2 -> V_183 . V_220 ,
V_301 ) ;
} else {
F_143 ( V_2 , & V_2 -> V_183 . V_220 ,
V_295 ) ;
}
return & V_2 -> V_183 ;
}
static int F_144 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_138 ( V_2 ) ;
V_6 -> V_159 = false ;
F_129 ( V_2 -> V_245 ) ;
F_136 ( & V_6 -> V_253 ) ;
F_1 ( V_2 , 0x0000 , V_140 ) ;
F_56 ( V_2 ) ;
if ( V_6 -> V_257 ) {
F_145 ( V_6 -> V_257 ) ;
F_146 ( V_6 -> V_257 ) ;
V_6 -> V_257 = NULL ;
}
F_135 ( V_2 -> V_245 , V_2 ) ;
F_39 ( V_2 ) ;
F_116 ( & V_6 -> V_339 -> V_120 ) ;
V_6 -> V_366 = 0 ;
return 0 ;
}
static int F_147 ( struct V_1 * V_2 , struct V_378 * V_379 , int V_380 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_256 * V_257 = V_6 -> V_257 ;
if ( ! F_126 ( V_2 ) )
return - V_358 ;
if ( ! V_257 )
return - V_276 ;
return F_148 ( V_257 , V_379 , V_380 ) ;
}
static void * F_149 ( struct V_5 * V_6 ,
int V_180 )
{
return F_150 ( V_6 , V_328 ) + ( V_180 / 8 * 4 ) ;
}
static T_1 F_151 ( int V_180 )
{
return 0x0f << ( 28 - ( ( V_180 % 8 ) * 4 ) ) ;
}
static T_1 F_152 ( struct V_5 * V_6 , int V_180 )
{
return ( 0x08 >> ( V_6 -> V_381 << 1 ) ) << ( 28 - ( ( V_180 % 8 ) * 4 ) ) ;
}
static void F_153 ( struct V_1 * V_2 ,
int V_180 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_382 ;
void * V_8 ;
V_8 = F_149 ( V_6 , V_180 ) ;
V_382 = F_6 ( V_8 ) ;
F_4 ( V_382 | F_152 ( V_6 , V_180 ) , V_8 ) ;
}
static bool F_154 ( struct V_1 * V_2 ,
int V_180 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_383 , V_384 , V_382 ;
void * V_8 ;
V_8 = F_149 ( V_6 , V_180 ) ;
V_383 = F_151 ( V_180 ) ;
V_384 = F_152 ( V_6 , V_180 ) & ~ V_383 ;
V_382 = F_6 ( V_8 ) ;
F_4 ( V_382 & ~ V_383 , V_8 ) ;
return V_382 & V_384 ;
}
static int F_155 ( struct V_1 * V_2 )
{
int V_385 = V_386 * 100 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
while ( ( F_156 ( V_6 , V_326 ) & V_387 ) ) {
F_157 ( 10 ) ;
V_385 -- ;
if ( V_385 <= 0 ) {
F_26 ( V_2 , L_18 , V_361 ) ;
return - V_56 ;
}
}
return 0 ;
}
static int F_158 ( struct V_1 * V_2 , void * T_7 ,
const T_10 * V_10 )
{
T_1 V_388 ;
V_388 = V_10 [ 0 ] << 24 | V_10 [ 1 ] << 16 | V_10 [ 2 ] << 8 | V_10 [ 3 ] ;
F_4 ( V_388 , T_7 ) ;
if ( F_155 ( V_2 ) < 0 )
return - V_389 ;
V_388 = V_10 [ 4 ] << 8 | V_10 [ 5 ] ;
F_4 ( V_388 , T_7 + 4 ) ;
if ( F_155 ( V_2 ) < 0 )
return - V_389 ;
return 0 ;
}
static void F_159 ( void * T_7 , T_10 * V_10 )
{
T_1 V_388 ;
V_388 = F_6 ( T_7 ) ;
V_10 [ 0 ] = ( V_388 >> 24 ) & 0xff ;
V_10 [ 1 ] = ( V_388 >> 16 ) & 0xff ;
V_10 [ 2 ] = ( V_388 >> 8 ) & 0xff ;
V_10 [ 3 ] = V_388 & 0xff ;
V_388 = F_6 ( T_7 + 4 ) ;
V_10 [ 4 ] = ( V_388 >> 8 ) & 0xff ;
V_10 [ 5 ] = V_388 & 0xff ;
}
static int F_160 ( struct V_1 * V_2 , const T_10 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void * V_8 = F_150 ( V_6 , V_332 ) ;
int V_32 ;
T_10 V_390 [ V_80 ] ;
for ( V_32 = 0 ; V_32 < V_333 ; V_32 ++ , V_8 += 8 ) {
F_159 ( V_8 , V_390 ) ;
if ( F_161 ( V_10 , V_390 ) )
return V_32 ;
}
return - V_267 ;
}
static int F_162 ( struct V_1 * V_2 )
{
T_10 V_391 [ V_80 ] ;
int V_180 ;
memset ( V_391 , 0 , sizeof( V_391 ) ) ;
V_180 = F_160 ( V_2 , V_391 ) ;
return ( V_180 < 0 ) ? - V_133 : V_180 ;
}
static int F_163 ( struct V_1 * V_2 ,
int V_180 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void * V_8 = F_150 ( V_6 , V_332 ) ;
int V_53 ;
T_10 V_391 [ V_80 ] ;
F_13 ( V_6 , F_156 ( V_6 , V_327 ) &
~ ( 1 << ( 31 - V_180 ) ) , V_327 ) ;
memset ( V_391 , 0 , sizeof( V_391 ) ) ;
V_53 = F_158 ( V_2 , V_8 + V_180 * 8 , V_391 ) ;
if ( V_53 < 0 )
return V_53 ;
return 0 ;
}
static int F_164 ( struct V_1 * V_2 , const T_10 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void * V_8 = F_150 ( V_6 , V_332 ) ;
int V_32 , V_53 ;
if ( ! V_6 -> V_37 -> V_304 )
return 0 ;
V_32 = F_160 ( V_2 , V_10 ) ;
if ( V_32 < 0 ) {
V_32 = F_162 ( V_2 ) ;
if ( V_32 < 0 )
return - V_133 ;
V_53 = F_158 ( V_2 , V_8 + V_32 * 8 , V_10 ) ;
if ( V_53 < 0 )
return V_53 ;
F_13 ( V_6 , F_156 ( V_6 , V_327 ) |
( 1 << ( 31 - V_32 ) ) , V_327 ) ;
}
F_153 ( V_2 , V_32 ) ;
return 0 ;
}
static int F_165 ( struct V_1 * V_2 , const T_10 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 , V_53 ;
if ( ! V_6 -> V_37 -> V_304 )
return 0 ;
V_32 = F_160 ( V_2 , V_10 ) ;
if ( V_32 ) {
if ( F_154 ( V_2 , V_32 ) )
goto V_392;
V_53 = F_163 ( V_2 , V_32 ) ;
if ( V_53 < 0 )
return V_53 ;
}
V_392:
return 0 ;
}
static int F_166 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 , V_53 ;
if ( ! V_6 -> V_37 -> V_304 )
return 0 ;
for ( V_32 = 0 ; V_32 < V_333 ; V_32 ++ ) {
if ( F_154 ( V_2 , V_32 ) )
continue;
V_53 = F_163 ( V_2 , V_32 ) ;
if ( V_53 < 0 )
return V_53 ;
}
return 0 ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_10 V_10 [ V_80 ] ;
void * V_8 = F_150 ( V_6 , V_332 ) ;
int V_32 ;
if ( ! V_6 -> V_37 -> V_304 )
return;
for ( V_32 = 0 ; V_32 < V_333 ; V_32 ++ , V_8 += 8 ) {
F_159 ( V_8 , V_10 ) ;
if ( F_168 ( V_10 ) )
F_165 ( V_2 , V_10 ) ;
}
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_393 ;
int V_394 = 0 ;
unsigned long V_275 ;
F_101 ( & V_6 -> V_249 , V_275 ) ;
V_393 = F_5 ( V_2 , V_20 ) & ~ V_395 ;
if ( V_6 -> V_37 -> V_304 )
V_393 |= V_396 ;
if ( ! ( V_2 -> V_275 & V_397 ) ) {
F_167 ( V_2 ) ;
V_394 = 1 ;
}
if ( V_2 -> V_275 & V_398 ) {
F_167 ( V_2 ) ;
V_393 &= ~ V_396 ;
V_394 = 1 ;
}
if ( V_2 -> V_275 & V_399 ) {
F_166 ( V_2 ) ;
V_393 = ( V_393 & ~ V_396 ) | V_395 ;
} else if ( V_6 -> V_37 -> V_304 ) {
struct V_400 * V_401 ;
F_170 (ha, ndev) {
if ( V_394 && F_168 ( V_401 -> V_10 ) )
continue;
if ( F_164 ( V_2 , V_401 -> V_10 ) < 0 ) {
if ( ! V_394 ) {
F_167 ( V_2 ) ;
V_393 &= ~ V_396 ;
V_394 = 1 ;
}
}
}
}
F_1 ( V_2 , V_393 , V_20 ) ;
F_103 ( & V_6 -> V_249 , V_275 ) ;
}
static int F_171 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_381 )
return V_324 ;
else
return V_325 ;
}
static int F_172 ( struct V_1 * V_2 ,
T_11 V_402 , T_2 V_403 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_404 = F_171 ( V_6 ) ;
if ( F_173 ( ! V_6 -> V_37 -> V_304 ) )
return - V_405 ;
if ( ! V_403 )
return 0 ;
V_6 -> V_406 ++ ;
if ( V_6 -> V_406 > 1 ) {
F_13 ( V_6 , 0 , V_404 ) ;
return 0 ;
}
F_13 ( V_6 , V_407 | ( V_403 & V_408 ) ,
V_404 ) ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 ,
T_11 V_402 , T_2 V_403 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_404 = F_171 ( V_6 ) ;
if ( F_173 ( ! V_6 -> V_37 -> V_304 ) )
return - V_405 ;
if ( ! V_403 )
return 0 ;
V_6 -> V_406 -- ;
F_13 ( V_6 , 0 , V_404 ) ;
return 0 ;
}
static void F_175 ( struct V_5 * V_6 )
{
if ( F_8 ( V_6 ) ) {
F_13 ( V_6 , 0 , V_327 ) ;
return;
}
F_13 ( V_6 , 0 , V_306 ) ;
F_13 ( V_6 , 0 , V_307 ) ;
F_13 ( V_6 , 0 , V_308 ) ;
F_13 ( V_6 , 0xc , V_309 ) ;
F_13 ( V_6 , 0xc , V_310 ) ;
F_13 ( V_6 , 0 , V_311 ) ;
F_13 ( V_6 , 0 , V_312 ) ;
F_13 ( V_6 , 0 , V_313 ) ;
F_13 ( V_6 , 0 , V_314 ) ;
F_13 ( V_6 , V_409 | V_410 , V_315 ) ;
if ( F_7 ( V_6 ) ) {
F_13 ( V_6 , 0 , V_316 ) ;
F_13 ( V_6 , 0 , V_317 ) ;
} else {
F_13 ( V_6 , 0 , V_318 ) ;
F_13 ( V_6 , 0 , V_319 ) ;
}
F_13 ( V_6 , 0 , V_320 ) ;
F_13 ( V_6 , 0 , V_321 ) ;
F_13 ( V_6 , 0 , V_327 ) ;
F_13 ( V_6 , 0 , V_328 ) ;
F_13 ( V_6 , 0 , V_329 ) ;
F_13 ( V_6 , 0 , V_330 ) ;
F_13 ( V_6 , 0 , V_331 ) ;
}
static int F_176 ( struct V_5 * V_6 )
{
F_177 ( V_6 -> V_271 ) ;
F_178 ( V_6 -> V_271 ) ;
return 0 ;
}
static int F_179 ( struct V_5 * V_6 ,
struct V_411 * V_412 )
{
int V_53 ;
struct V_87 * V_88 ;
struct V_413 * V_339 = V_6 -> V_339 ;
struct V_414 * V_120 = & V_6 -> V_339 -> V_120 ;
V_88 = F_180 ( V_120 , sizeof( struct V_87 ) , V_132 ) ;
if ( ! V_88 )
return - V_133 ;
V_88 -> V_10 = V_6 -> V_10 + V_6 -> V_8 [ V_286 ] ;
V_88 -> V_90 = V_412 -> V_415 ;
V_88 -> V_84 . V_416 = & V_417 ;
V_6 -> V_271 = F_181 ( & V_88 -> V_84 ) ;
if ( ! V_6 -> V_271 )
return - V_133 ;
V_6 -> V_271 -> V_363 = L_19 ;
V_6 -> V_271 -> V_264 = V_120 ;
snprintf ( V_6 -> V_271 -> V_272 , V_269 , L_20 ,
V_339 -> V_363 , V_339 -> V_272 ) ;
if ( V_120 -> V_265 ) {
V_53 = F_182 ( V_6 -> V_271 , V_120 -> V_265 ) ;
} else {
if ( V_412 -> V_418 > 0 )
V_6 -> V_271 -> V_245 [ V_412 -> V_419 ] = V_412 -> V_418 ;
V_53 = F_183 ( V_6 -> V_271 ) ;
}
if ( V_53 )
goto V_420;
return 0 ;
V_420:
F_178 ( V_6 -> V_271 ) ;
return V_53 ;
}
static const T_2 * F_184 ( int V_421 )
{
const T_2 * V_8 = NULL ;
switch ( V_421 ) {
case V_422 :
V_8 = V_11 ;
break;
case V_423 :
V_8 = V_12 ;
break;
case V_424 :
V_8 = V_425 ;
break;
case V_426 :
V_8 = V_427 ;
break;
case V_428 :
V_8 = V_429 ;
break;
default:
break;
}
return V_8 ;
}
static struct V_411 * F_185 ( struct V_414 * V_120 )
{
struct V_262 * V_263 = V_120 -> V_265 ;
struct V_411 * V_430 ;
const char * V_431 ;
V_430 = F_180 ( V_120 , sizeof( * V_430 ) , V_132 ) ;
if ( ! V_430 )
return NULL ;
V_430 -> V_14 = F_186 ( V_263 ) ;
V_431 = F_187 ( V_263 ) ;
if ( V_431 )
memcpy ( V_430 -> V_431 , V_431 , V_80 ) ;
V_430 -> V_223 =
F_188 ( V_263 , L_21 ) ;
V_430 -> V_226 =
F_188 ( V_263 , L_22 ) ;
return V_430 ;
}
static inline struct V_411 * F_185 ( struct V_414 * V_120 )
{
return NULL ;
}
static int F_189 ( struct V_413 * V_339 )
{
int V_53 , V_432 = 0 ;
struct V_433 * V_434 ;
struct V_1 * V_2 = NULL ;
struct V_5 * V_6 = NULL ;
struct V_411 * V_412 = F_190 ( & V_339 -> V_120 ) ;
const struct V_435 * V_272 = F_191 ( V_339 ) ;
V_434 = F_192 ( V_339 , V_436 , 0 ) ;
V_2 = F_193 ( sizeof( struct V_5 ) ) ;
if ( ! V_2 )
return - V_133 ;
F_194 ( & V_339 -> V_120 ) ;
F_115 ( & V_339 -> V_120 ) ;
V_432 = V_339 -> V_272 ;
if ( V_432 < 0 )
V_432 = 0 ;
V_2 -> V_437 = - 1 ;
V_53 = F_195 ( V_339 , 0 ) ;
if ( V_53 < 0 )
goto V_438;
V_2 -> V_245 = V_53 ;
F_196 ( V_2 , & V_339 -> V_120 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_100 = V_439 ;
V_6 -> V_98 = V_440 ;
V_6 -> V_10 = F_197 ( & V_339 -> V_120 , V_434 ) ;
if ( F_95 ( V_6 -> V_10 ) ) {
V_53 = F_96 ( V_6 -> V_10 ) ;
goto V_438;
}
V_2 -> V_441 = V_434 -> V_135 ;
F_198 ( & V_6 -> V_249 ) ;
V_6 -> V_339 = V_339 ;
if ( V_339 -> V_120 . V_265 )
V_412 = F_185 ( & V_339 -> V_120 ) ;
if ( ! V_412 ) {
F_199 ( & V_339 -> V_120 , L_23 ) ;
V_53 = - V_358 ;
goto V_438;
}
V_6 -> V_268 = V_412 -> V_419 ;
V_6 -> V_14 = V_412 -> V_14 ;
V_6 -> V_223 = V_412 -> V_223 ;
V_6 -> V_226 = V_412 -> V_226 ;
if ( V_272 )
V_6 -> V_37 = (struct V_36 * ) V_272 -> V_442 ;
else
V_6 -> V_37 = (struct V_36 * ) F_200 ( & V_339 -> V_120 ) ;
V_6 -> V_8 = F_184 ( V_6 -> V_37 -> V_421 ) ;
if ( ! V_6 -> V_8 ) {
F_199 ( & V_339 -> V_120 , L_24 ,
V_6 -> V_37 -> V_421 ) ;
V_53 = - V_358 ;
goto V_438;
}
F_24 ( V_6 -> V_37 ) ;
if ( V_6 -> V_37 -> V_304 )
V_2 -> V_443 = & V_444 ;
else
V_2 -> V_443 = & V_445 ;
V_2 -> V_446 = & V_447 ;
V_2 -> V_448 = V_449 ;
V_6 -> V_340 = V_450 ;
F_31 ( V_2 , V_412 -> V_431 ) ;
if ( ! F_201 ( V_2 -> V_76 ) ) {
F_202 ( & V_339 -> V_120 ,
L_25 ) ;
F_203 ( V_2 ) ;
}
if ( V_6 -> V_37 -> V_304 ) {
struct V_433 * V_451 ;
V_451 = F_192 ( V_339 , V_436 , 1 ) ;
V_6 -> V_334 = F_197 ( & V_339 -> V_120 , V_451 ) ;
if ( F_95 ( V_6 -> V_334 ) ) {
V_53 = F_96 ( V_6 -> V_334 ) ;
goto V_438;
}
V_6 -> V_381 = V_432 % 2 ;
V_2 -> V_452 = V_453 ;
}
if ( ! V_432 || V_412 -> V_454 ) {
if ( V_6 -> V_37 -> V_455 )
V_6 -> V_37 -> V_455 ( V_2 ) ;
if ( V_6 -> V_37 -> V_304 ) {
F_175 ( V_6 ) ;
}
}
if ( V_6 -> V_37 -> V_136 )
F_1 ( V_2 , 0x1 , V_137 ) ;
V_53 = F_179 ( V_6 , V_412 ) ;
if ( V_53 ) {
F_199 ( & V_2 -> V_120 , L_26 ) ;
goto V_438;
}
F_204 ( V_2 , & V_6 -> V_253 , F_85 , 64 ) ;
V_53 = F_205 ( V_2 ) ;
if ( V_53 )
goto V_456;
F_206 ( V_2 , L_27 ,
( T_1 ) V_2 -> V_441 , V_2 -> V_76 , V_2 -> V_245 ) ;
F_207 ( & V_339 -> V_120 ) ;
F_208 ( V_339 , V_2 ) ;
return V_53 ;
V_456:
F_209 ( & V_6 -> V_253 ) ;
F_176 ( V_6 ) ;
V_438:
if ( V_2 )
F_210 ( V_2 ) ;
F_207 ( & V_339 -> V_120 ) ;
F_211 ( & V_339 -> V_120 ) ;
return V_53 ;
}
static int F_212 ( struct V_413 * V_339 )
{
struct V_1 * V_2 = F_213 ( V_339 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_214 ( V_2 ) ;
F_209 ( & V_6 -> V_253 ) ;
F_176 ( V_6 ) ;
F_211 ( & V_339 -> V_120 ) ;
F_210 ( V_2 ) ;
return 0 ;
}
static int F_215 ( struct V_414 * V_120 )
{
struct V_1 * V_2 = F_216 ( V_120 ) ;
int V_53 = 0 ;
if ( F_126 ( V_2 ) ) {
F_127 ( V_2 ) ;
V_53 = F_144 ( V_2 ) ;
}
return V_53 ;
}
static int F_217 ( struct V_414 * V_120 )
{
struct V_1 * V_2 = F_216 ( V_120 ) ;
int V_53 = 0 ;
if ( F_126 ( V_2 ) ) {
V_53 = F_132 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
F_131 ( V_2 ) ;
}
return V_53 ;
}
static int F_218 ( struct V_414 * V_120 )
{
return 0 ;
}
