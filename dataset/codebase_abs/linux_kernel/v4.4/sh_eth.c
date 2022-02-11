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
switch ( V_6 -> V_22 ) {
case 10 :
F_1 ( V_2 , F_5 ( V_2 , V_20 ) & ~ V_23 , V_20 ) ;
break;
case 100 :
F_1 ( V_2 , F_5 ( V_2 , V_20 ) | V_23 , V_20 ) ;
break;
default:
break;
}
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_22 ) {
case 10 :
F_1 ( V_2 , F_5 ( V_2 , V_20 ) & ~ V_24 , V_20 ) ;
break;
case 100 :
F_1 ( V_2 , F_5 ( V_2 , V_20 ) | V_24 , V_20 ) ;
break;
default:
break;
}
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_22 ) {
case 10 :
F_1 ( V_2 , 0 , V_25 ) ;
break;
case 100 :
F_1 ( V_2 , 1 , V_25 ) ;
break;
default:
break;
}
}
static void F_15 ( struct V_1 * V_2 )
{
int V_26 ;
T_1 V_27 [ 2 ] , V_28 [ 2 ] ;
for ( V_26 = 0 ; V_26 < 2 ; V_26 ++ ) {
V_28 [ V_26 ] = F_6 ( ( void * ) F_16 ( V_26 ) ) ;
V_27 [ V_26 ] = F_6 ( ( void * ) F_17 ( V_26 ) ) ;
}
F_4 ( V_29 , ( void * ) ( V_30 + 0x1800 ) ) ;
F_18 ( 1 ) ;
for ( V_26 = 0 ; V_26 < 2 ; V_26 ++ ) {
F_4 ( V_28 [ V_26 ] , ( void * ) F_16 ( V_26 ) ) ;
F_4 ( V_27 [ V_26 ] , ( void * ) F_17 ( V_26 ) ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_22 ) {
case 10 :
F_1 ( V_2 , 0x00000000 , V_31 ) ;
break;
case 100 :
F_1 ( V_2 , 0x00000010 , V_31 ) ;
break;
case 1000 :
F_1 ( V_2 , 0x00000020 , V_31 ) ;
break;
default:
break;
}
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_21 ( V_6 , V_29 , V_32 ) ;
F_18 ( 1 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_6 -> V_22 ) {
case 10 :
F_1 ( V_2 , V_33 , V_31 ) ;
break;
case 100 :
F_1 ( V_2 , V_34 , V_31 ) ;
break;
case 1000 :
F_1 ( V_2 , V_35 , V_31 ) ;
break;
default:
break;
}
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_21 ( V_6 , V_29 , V_32 ) ;
F_18 ( 1 ) ;
F_9 ( V_2 ) ;
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
F_18 ( 1 ) ;
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
F_18 ( 3 ) ;
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
static inline T_4 F_30 ( struct V_5 * V_6 , T_1 V_76 )
{
switch ( V_6 -> V_77 ) {
case V_78 :
return F_31 ( V_76 ) ;
case V_79 :
return F_32 ( V_76 ) ;
}
return V_76 ;
}
static inline T_4 F_33 ( struct V_5 * V_6 , T_1 V_76 )
{
switch ( V_6 -> V_77 ) {
case V_78 :
return F_34 ( V_76 ) ;
case V_79 :
return F_35 ( V_76 ) ;
}
return V_76 ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_1 ( V_2 ,
( V_2 -> V_80 [ 0 ] << 24 ) | ( V_2 -> V_80 [ 1 ] << 16 ) |
( V_2 -> V_80 [ 2 ] << 8 ) | ( V_2 -> V_80 [ 3 ] ) , V_81 ) ;
F_1 ( V_2 ,
( V_2 -> V_80 [ 4 ] << 8 ) | ( V_2 -> V_80 [ 5 ] ) , V_82 ) ;
}
static void F_37 ( struct V_1 * V_2 , unsigned char * V_83 )
{
if ( V_83 [ 0 ] || V_83 [ 1 ] || V_83 [ 2 ] || V_83 [ 3 ] || V_83 [ 4 ] || V_83 [ 5 ] ) {
memcpy ( V_2 -> V_80 , V_83 , V_84 ) ;
} else {
V_2 -> V_80 [ 0 ] = ( F_5 ( V_2 , V_81 ) >> 24 ) ;
V_2 -> V_80 [ 1 ] = ( F_5 ( V_2 , V_81 ) >> 16 ) & 0xFF ;
V_2 -> V_80 [ 2 ] = ( F_5 ( V_2 , V_81 ) >> 8 ) & 0xFF ;
V_2 -> V_80 [ 3 ] = ( F_5 ( V_2 , V_81 ) & 0xFF ) ;
V_2 -> V_80 [ 4 ] = ( F_5 ( V_2 , V_82 ) >> 8 ) & 0xFF ;
V_2 -> V_80 [ 5 ] = ( F_5 ( V_2 , V_82 ) & 0xFF ) ;
}
}
static T_1 F_38 ( struct V_5 * V_6 )
{
if ( F_7 ( V_6 ) || F_8 ( V_6 ) )
return V_85 ;
else
return V_86 ;
}
static void F_39 ( void * V_10 , T_1 V_87 )
{
F_4 ( F_6 ( V_10 ) | V_87 , V_10 ) ;
}
static void F_40 ( void * V_10 , T_1 V_87 )
{
F_4 ( ( F_6 ( V_10 ) & ~ V_87 ) , V_10 ) ;
}
static int F_41 ( void * V_10 , T_1 V_87 )
{
return ( F_6 ( V_10 ) & V_87 ) != 0 ;
}
static void F_42 ( struct V_88 * V_89 , int V_90 )
{
struct V_91 * V_92 = F_43 ( V_89 , struct V_91 , V_89 ) ;
if ( V_92 -> V_93 )
V_92 -> V_93 ( V_92 -> V_10 ) ;
if ( V_90 )
F_39 ( V_92 -> V_10 , V_92 -> V_94 ) ;
else
F_40 ( V_92 -> V_10 , V_92 -> V_94 ) ;
}
static void F_44 ( struct V_88 * V_89 , int V_90 )
{
struct V_91 * V_92 = F_43 ( V_89 , struct V_91 , V_89 ) ;
if ( V_92 -> V_93 )
V_92 -> V_93 ( V_92 -> V_10 ) ;
if ( V_90 )
F_39 ( V_92 -> V_10 , V_92 -> V_95 ) ;
else
F_40 ( V_92 -> V_10 , V_92 -> V_95 ) ;
}
static int F_45 ( struct V_88 * V_89 )
{
struct V_91 * V_92 = F_43 ( V_89 , struct V_91 , V_89 ) ;
if ( V_92 -> V_93 )
V_92 -> V_93 ( V_92 -> V_10 ) ;
return F_41 ( V_92 -> V_10 , V_92 -> V_96 ) ;
}
static void F_46 ( struct V_88 * V_89 , int V_90 )
{
struct V_91 * V_92 = F_43 ( V_89 , struct V_91 , V_89 ) ;
if ( V_92 -> V_93 )
V_92 -> V_93 ( V_92 -> V_10 ) ;
if ( V_90 )
F_39 ( V_92 -> V_10 , V_92 -> V_97 ) ;
else
F_40 ( V_92 -> V_10 , V_92 -> V_97 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_98 , V_26 ;
if ( V_6 -> V_99 ) {
for ( V_26 = 0 ; V_26 < V_6 -> V_100 ; V_26 ++ )
F_48 ( V_6 -> V_99 [ V_26 ] ) ;
}
F_49 ( V_6 -> V_99 ) ;
V_6 -> V_99 = NULL ;
if ( V_6 -> V_101 ) {
for ( V_26 = 0 ; V_26 < V_6 -> V_102 ; V_26 ++ )
F_48 ( V_6 -> V_101 [ V_26 ] ) ;
}
F_49 ( V_6 -> V_101 ) ;
V_6 -> V_101 = NULL ;
if ( V_6 -> V_103 ) {
V_98 = sizeof( struct V_104 ) * V_6 -> V_100 ;
F_50 ( NULL , V_98 , V_6 -> V_103 ,
V_6 -> V_105 ) ;
V_6 -> V_103 = NULL ;
}
if ( V_6 -> V_106 ) {
V_98 = sizeof( struct V_107 ) * V_6 -> V_102 ;
F_50 ( NULL , V_98 , V_6 -> V_106 ,
V_6 -> V_108 ) ;
V_6 -> V_106 = NULL ;
}
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
struct V_72 * V_73 ;
struct V_104 * V_109 = NULL ;
struct V_107 * V_110 = NULL ;
int V_111 = sizeof( * V_109 ) * V_6 -> V_100 ;
int V_112 = sizeof( * V_110 ) * V_6 -> V_102 ;
int V_113 = V_6 -> V_114 + V_75 + 32 - 1 ;
T_5 V_115 ;
T_1 V_116 ;
V_6 -> V_117 = 0 ;
V_6 -> V_118 = 0 ;
V_6 -> V_119 = 0 ;
V_6 -> V_120 = 0 ;
memset ( V_6 -> V_103 , 0 , V_111 ) ;
for ( V_26 = 0 ; V_26 < V_6 -> V_100 ; V_26 ++ ) {
V_6 -> V_99 [ V_26 ] = NULL ;
V_73 = F_52 ( V_2 , V_113 ) ;
if ( V_73 == NULL )
break;
F_28 ( V_73 ) ;
V_109 = & V_6 -> V_103 [ V_26 ] ;
V_116 = F_53 ( V_6 -> V_114 , 32 ) ;
V_109 -> V_121 = F_30 ( V_6 , V_116 << 16 ) ;
V_115 = F_54 ( & V_2 -> V_122 , V_73 -> V_3 , V_116 ,
V_123 ) ;
if ( F_55 ( & V_2 -> V_122 , V_115 ) ) {
F_56 ( V_73 ) ;
break;
}
V_6 -> V_99 [ V_26 ] = V_73 ;
V_109 -> V_10 = F_30 ( V_6 , V_115 ) ;
V_109 -> V_124 = F_30 ( V_6 , V_125 | V_126 ) ;
if ( V_26 == 0 ) {
F_1 ( V_2 , V_6 -> V_105 , V_64 ) ;
if ( F_7 ( V_6 ) ||
F_8 ( V_6 ) )
F_1 ( V_2 , V_6 -> V_105 , V_65 ) ;
}
}
V_6 -> V_119 = ( T_1 ) ( V_26 - V_6 -> V_100 ) ;
V_109 -> V_124 |= F_30 ( V_6 , V_127 ) ;
memset ( V_6 -> V_106 , 0 , V_112 ) ;
for ( V_26 = 0 ; V_26 < V_6 -> V_102 ; V_26 ++ ) {
V_6 -> V_101 [ V_26 ] = NULL ;
V_110 = & V_6 -> V_106 [ V_26 ] ;
V_110 -> V_124 = F_30 ( V_6 , V_128 ) ;
V_110 -> V_121 = F_30 ( V_6 , 0 ) ;
if ( V_26 == 0 ) {
F_1 ( V_2 , V_6 -> V_108 , V_60 ) ;
if ( F_7 ( V_6 ) ||
F_8 ( V_6 ) )
F_1 ( V_2 , V_6 -> V_108 , V_61 ) ;
}
}
V_110 -> V_124 |= F_30 ( V_6 , V_129 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_111 , V_112 ;
V_6 -> V_114 = ( V_2 -> V_130 <= 1492 ? V_131 :
( ( ( V_2 -> V_130 + 26 + 7 ) & ~ 7 ) + 2 + 16 ) ) ;
if ( V_6 -> V_37 -> V_132 )
V_6 -> V_114 += V_133 ;
V_6 -> V_99 = F_58 ( V_6 -> V_100 , sizeof( * V_6 -> V_99 ) ,
V_134 ) ;
if ( ! V_6 -> V_99 )
return - V_135 ;
V_6 -> V_101 = F_58 ( V_6 -> V_102 , sizeof( * V_6 -> V_101 ) ,
V_134 ) ;
if ( ! V_6 -> V_101 )
goto V_136;
V_111 = sizeof( struct V_104 ) * V_6 -> V_100 ;
V_6 -> V_103 = F_59 ( NULL , V_111 , & V_6 -> V_105 ,
V_134 ) ;
if ( ! V_6 -> V_103 )
goto V_136;
V_6 -> V_119 = 0 ;
V_112 = sizeof( struct V_107 ) * V_6 -> V_102 ;
V_6 -> V_106 = F_59 ( NULL , V_112 , & V_6 -> V_108 ,
V_134 ) ;
if ( ! V_6 -> V_106 )
goto V_136;
return 0 ;
V_136:
F_47 ( V_2 ) ;
return - V_135 ;
}
static int F_60 ( struct V_1 * V_2 , bool V_137 )
{
int V_53 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_138 ;
V_53 = F_27 ( V_2 ) ;
if ( V_53 )
return V_53 ;
if ( V_6 -> V_37 -> V_139 )
F_1 ( V_2 , 0x1 , V_140 ) ;
F_51 ( V_2 ) ;
if ( V_6 -> V_37 -> V_132 )
F_1 ( V_2 , V_6 -> V_37 -> V_141 , V_142 ) ;
F_1 ( V_2 , 0 , V_143 ) ;
#if F_61 ( V_144 )
if ( V_6 -> V_37 -> V_145 )
F_1 ( V_2 , V_146 , V_55 ) ;
else
#endif
F_1 ( V_2 , 0 , V_55 ) ;
F_1 ( V_2 , V_6 -> V_37 -> V_45 , V_147 ) ;
F_1 ( V_2 , 0 , V_148 ) ;
F_1 ( V_2 , V_149 , V_150 ) ;
F_1 ( V_2 , V_6 -> V_37 -> V_51 , V_151 ) ;
if ( V_6 -> V_37 -> V_152 )
F_1 ( V_2 , 0x800 , V_153 ) ;
F_1 ( V_2 , V_6 -> V_37 -> V_42 , V_154 ) ;
if ( ! V_6 -> V_37 -> V_155 )
F_1 ( V_2 , 0 , V_156 ) ;
F_1 ( V_2 , V_2 -> V_130 + V_157 + V_158 + V_159 ,
V_160 ) ;
F_1 ( V_2 , F_5 ( V_2 , V_161 ) , V_161 ) ;
if ( V_137 ) {
V_6 -> V_162 = true ;
F_1 ( V_2 , V_6 -> V_37 -> V_163 , V_143 ) ;
}
V_138 = ( F_5 ( V_2 , V_20 ) & V_21 ) |
V_164 | ( V_6 -> V_19 ? V_21 : 0 ) | V_165 | V_166 ;
F_1 ( V_2 , V_138 , V_20 ) ;
if ( V_6 -> V_37 -> V_167 )
V_6 -> V_37 -> V_167 ( V_2 ) ;
F_1 ( V_2 , V_6 -> V_37 -> V_38 , V_168 ) ;
if ( V_137 )
F_1 ( V_2 , V_6 -> V_37 -> V_40 , V_169 ) ;
F_36 ( V_2 ) ;
if ( V_6 -> V_37 -> V_170 )
F_1 ( V_2 , V_171 , V_172 ) ;
if ( V_6 -> V_37 -> V_173 )
F_1 ( V_2 , V_174 , V_175 ) ;
if ( V_6 -> V_37 -> V_176 )
F_1 ( V_2 , V_177 , V_178 ) ;
if ( V_137 ) {
F_1 ( V_2 , V_179 , V_180 ) ;
F_62 ( V_2 ) ;
}
return V_53 ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_6 -> V_102 ; V_26 ++ )
V_6 -> V_106 [ V_26 ] . V_124 &= ~ F_30 ( V_6 , V_181 ) ;
F_64 ( V_2 ) ;
F_1 ( V_2 , 0 , V_180 ) ;
F_65 ( 2 ) ;
F_66 ( V_2 ) ;
F_27 ( V_2 ) ;
F_36 ( V_2 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_107 * V_110 ;
int V_182 = 0 ;
int V_183 = 0 ;
for (; V_6 -> V_118 - V_6 -> V_120 > 0 ; V_6 -> V_120 ++ ) {
V_183 = V_6 -> V_120 % V_6 -> V_102 ;
V_110 = & V_6 -> V_106 [ V_183 ] ;
if ( V_110 -> V_124 & F_30 ( V_6 , V_181 ) )
break;
F_68 () ;
F_69 ( V_6 , V_184 , V_2 ,
L_3 ,
V_183 , F_33 ( V_6 , V_110 -> V_124 ) ) ;
if ( V_6 -> V_101 [ V_183 ] ) {
F_70 ( & V_2 -> V_122 ,
F_33 ( V_6 , V_110 -> V_10 ) ,
F_33 ( V_6 , V_110 -> V_121 ) >> 16 ,
V_185 ) ;
F_71 ( V_6 -> V_101 [ V_183 ] ) ;
V_6 -> V_101 [ V_183 ] = NULL ;
V_182 ++ ;
}
V_110 -> V_124 = F_30 ( V_6 , V_128 ) ;
if ( V_183 >= V_6 -> V_102 - 1 )
V_110 -> V_124 |= F_30 ( V_6 , V_129 ) ;
V_2 -> V_186 . V_187 ++ ;
V_2 -> V_186 . V_188 += F_33 ( V_6 , V_110 -> V_121 ) >> 16 ;
}
return V_182 ;
}
static int F_72 ( struct V_1 * V_2 , T_1 V_189 , int * V_190 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_104 * V_109 ;
int V_183 = V_6 -> V_117 % V_6 -> V_100 ;
int V_191 = ( V_6 -> V_119 + V_6 -> V_100 ) - V_6 -> V_117 ;
int V_192 ;
struct V_72 * V_73 ;
T_2 V_193 = 0 ;
T_1 V_194 ;
int V_113 = V_6 -> V_114 + V_75 + 32 - 1 ;
T_5 V_115 ;
T_1 V_116 ;
V_191 = F_73 ( V_191 , * V_190 ) ;
V_192 = V_191 ;
V_109 = & V_6 -> V_103 [ V_183 ] ;
while ( ! ( V_109 -> V_124 & F_30 ( V_6 , V_125 ) ) ) {
F_68 () ;
V_194 = F_33 ( V_6 , V_109 -> V_124 ) ;
V_193 = F_33 ( V_6 , V_109 -> V_121 ) & V_195 ;
if ( -- V_191 < 0 )
break;
F_69 ( V_6 , V_196 , V_2 ,
L_4 ,
V_183 , V_194 , V_193 ) ;
if ( ! ( V_194 & V_197 ) )
V_2 -> V_186 . V_198 ++ ;
if ( V_6 -> V_37 -> V_199 )
V_194 >>= 16 ;
V_73 = V_6 -> V_99 [ V_183 ] ;
if ( V_194 & ( V_200 | V_201 | V_202 | V_203 |
V_204 | V_205 | V_206 ) ) {
V_2 -> V_186 . V_207 ++ ;
if ( V_194 & V_200 )
V_2 -> V_186 . V_208 ++ ;
if ( V_194 & V_201 )
V_2 -> V_186 . V_209 ++ ;
if ( V_194 & V_202 )
V_2 -> V_186 . V_198 ++ ;
if ( V_194 & V_203 )
V_2 -> V_186 . V_198 ++ ;
if ( V_194 & V_205 )
V_2 -> V_186 . V_210 ++ ;
if ( V_194 & V_206 )
V_2 -> V_186 . V_211 ++ ;
} else if ( V_73 ) {
V_115 = F_33 ( V_6 , V_109 -> V_10 ) ;
if ( ! V_6 -> V_37 -> V_145 )
F_74 (
F_75 ( F_53 ( V_115 , 4 ) ) ,
V_193 + 2 ) ;
V_6 -> V_99 [ V_183 ] = NULL ;
if ( V_6 -> V_37 -> V_132 )
F_29 ( V_73 , V_133 ) ;
F_70 ( & V_2 -> V_122 , V_115 ,
F_53 ( V_6 -> V_114 , 32 ) ,
V_123 ) ;
F_76 ( V_73 , V_193 ) ;
V_73 -> V_212 = F_77 ( V_73 , V_2 ) ;
F_78 ( V_73 ) ;
V_2 -> V_186 . V_213 ++ ;
V_2 -> V_186 . V_214 += V_193 ;
if ( V_194 & V_215 )
V_2 -> V_186 . V_216 ++ ;
}
V_183 = ( ++ V_6 -> V_117 ) % V_6 -> V_100 ;
V_109 = & V_6 -> V_103 [ V_183 ] ;
}
for (; V_6 -> V_117 - V_6 -> V_119 > 0 ; V_6 -> V_119 ++ ) {
V_183 = V_6 -> V_119 % V_6 -> V_100 ;
V_109 = & V_6 -> V_103 [ V_183 ] ;
V_116 = F_53 ( V_6 -> V_114 , 32 ) ;
V_109 -> V_121 = F_30 ( V_6 , V_116 << 16 ) ;
if ( V_6 -> V_99 [ V_183 ] == NULL ) {
V_73 = F_52 ( V_2 , V_113 ) ;
if ( V_73 == NULL )
break;
F_28 ( V_73 ) ;
V_115 = F_54 ( & V_2 -> V_122 , V_73 -> V_3 ,
V_116 , V_123 ) ;
if ( F_55 ( & V_2 -> V_122 , V_115 ) ) {
F_56 ( V_73 ) ;
break;
}
V_6 -> V_99 [ V_183 ] = V_73 ;
F_79 ( V_73 ) ;
V_109 -> V_10 = F_30 ( V_6 , V_115 ) ;
}
F_80 () ;
if ( V_183 >= V_6 -> V_100 - 1 )
V_109 -> V_124 |=
F_30 ( V_6 , V_125 | V_126 | V_127 ) ;
else
V_109 -> V_124 |=
F_30 ( V_6 , V_125 | V_126 ) ;
}
if ( ! ( F_5 ( V_2 , V_180 ) & V_179 ) ) {
if ( V_189 & V_217 &&
V_6 -> V_8 [ V_65 ] != V_9 ) {
T_1 V_218 = ( F_5 ( V_2 , V_65 ) -
F_5 ( V_2 , V_64 ) ) >> 4 ;
V_6 -> V_117 = V_218 ;
V_6 -> V_119 = V_218 ;
}
F_1 ( V_2 , V_179 , V_180 ) ;
}
* V_190 -= V_192 - V_191 - 1 ;
return * V_190 <= 0 ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_1 ( V_2 , F_5 ( V_2 , V_20 ) &
~ ( V_166 | V_165 ) , V_20 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
F_1 ( V_2 , F_5 ( V_2 , V_20 ) |
( V_166 | V_165 ) , V_20 ) ;
}
static void F_82 ( struct V_1 * V_2 , T_1 V_189 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_219 ;
T_1 V_220 ;
T_1 V_221 ;
if ( V_189 & V_222 ) {
V_219 = F_5 ( V_2 , V_168 ) ;
F_1 ( V_2 , V_219 , V_168 ) ;
if ( V_219 & V_223 )
V_2 -> V_186 . V_224 ++ ;
if ( V_219 & V_225 ) {
if ( V_6 -> V_37 -> V_226 || V_6 -> V_227 ) {
goto V_228;
} else {
V_220 = ( F_5 ( V_2 , V_229 ) ) ;
if ( V_6 -> V_230 )
V_220 = ~ V_220 ;
}
if ( ! ( V_220 & V_231 ) ) {
F_64 ( V_2 ) ;
} else {
F_1 ( V_2 , F_5 ( V_2 , V_143 ) &
~ V_232 , V_143 ) ;
F_1 ( V_2 , F_5 ( V_2 , V_168 ) ,
V_168 ) ;
F_1 ( V_2 , F_5 ( V_2 , V_143 ) |
V_232 , V_143 ) ;
F_81 ( V_2 ) ;
}
}
}
V_228:
if ( V_189 & V_233 ) {
if ( V_189 & V_234 ) {
V_2 -> V_186 . V_235 ++ ;
F_83 ( V_6 , V_236 , V_2 , L_5 ) ;
}
}
if ( V_189 & V_237 ) {
if ( V_189 & V_238 ) {
V_2 -> V_186 . V_209 ++ ;
}
}
if ( V_189 & V_239 ) {
V_2 -> V_186 . V_240 ++ ;
F_83 ( V_6 , V_236 , V_2 , L_6 ) ;
}
if ( V_189 & V_241 ) {
V_2 -> V_186 . V_240 ++ ;
F_83 ( V_6 , V_236 , V_2 , L_7 ) ;
}
if ( V_189 & V_217 ) {
V_2 -> V_186 . V_211 ++ ;
}
if ( V_189 & V_242 ) {
V_2 -> V_186 . V_243 ++ ;
}
if ( ! V_6 -> V_37 -> V_244 && ( V_189 & V_245 ) ) {
V_2 -> V_186 . V_240 ++ ;
F_83 ( V_6 , V_236 , V_2 , L_8 ) ;
}
V_221 = V_233 | V_234 | V_245 | V_239 | V_241 ;
if ( V_6 -> V_37 -> V_244 )
V_221 &= ~ V_245 ;
if ( V_189 & V_221 ) {
T_1 V_246 = F_5 ( V_2 , V_247 ) ;
F_26 ( V_2 , L_9 ,
V_189 , V_6 -> V_118 , V_6 -> V_120 ,
( T_1 ) V_2 -> V_248 , V_246 ) ;
F_67 ( V_2 ) ;
if ( V_246 ^ F_38 ( V_6 ) ) {
F_1 ( V_2 , F_38 ( V_6 ) , V_247 ) ;
}
F_84 ( V_2 ) ;
}
}
static T_6 F_85 ( int V_249 , void * V_250 )
{
struct V_1 * V_2 = V_250 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_36 * V_37 = V_6 -> V_37 ;
T_6 V_53 = V_251 ;
T_1 V_189 , V_252 ;
F_86 ( & V_6 -> V_253 ) ;
V_189 = F_5 ( V_2 , V_161 ) ;
V_252 = F_5 ( V_2 , V_143 ) ;
V_189 &= V_252 | V_232 ;
if ( V_189 & ( V_254 | V_37 -> V_47 | V_37 -> V_49 ) )
V_53 = V_255 ;
else
goto V_256;
if ( ! F_87 ( V_6 -> V_162 ) ) {
F_1 ( V_2 , 0 , V_143 ) ;
goto V_256;
}
if ( V_189 & V_254 ) {
if ( F_88 ( & V_6 -> V_257 ) ) {
F_1 ( V_2 , V_252 & ~ V_254 ,
V_143 ) ;
F_89 ( & V_6 -> V_257 ) ;
} else {
F_10 ( V_2 ,
L_10 ,
V_189 , V_252 ) ;
}
}
if ( V_189 & V_37 -> V_47 ) {
F_1 ( V_2 , V_189 & V_37 -> V_47 , V_161 ) ;
F_67 ( V_2 ) ;
F_84 ( V_2 ) ;
}
if ( V_189 & V_37 -> V_49 ) {
F_1 ( V_2 , V_189 & V_37 -> V_49 , V_161 ) ;
F_82 ( V_2 , V_189 ) ;
}
V_256:
F_90 ( & V_6 -> V_253 ) ;
return V_53 ;
}
static int F_91 ( struct V_258 * V_257 , int V_259 )
{
struct V_5 * V_6 = F_43 ( V_257 , struct V_5 ,
V_257 ) ;
struct V_1 * V_2 = V_257 -> V_122 ;
int V_190 = V_259 ;
T_1 V_189 ;
for (; ; ) {
V_189 = F_5 ( V_2 , V_161 ) ;
if ( ! ( V_189 & V_254 ) )
break;
F_1 ( V_2 , V_189 & V_254 , V_161 ) ;
if ( F_72 ( V_2 , V_189 , & V_190 ) )
goto V_256;
}
F_92 ( V_257 ) ;
if ( V_6 -> V_162 )
F_1 ( V_2 , V_6 -> V_37 -> V_163 , V_143 ) ;
V_256:
return V_259 - V_190 ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_260 * V_261 = V_6 -> V_261 ;
int V_262 = 0 ;
if ( V_261 -> V_263 ) {
if ( V_261 -> V_19 != V_6 -> V_19 ) {
V_262 = 1 ;
V_6 -> V_19 = V_261 -> V_19 ;
if ( V_6 -> V_37 -> V_264 )
V_6 -> V_37 -> V_264 ( V_2 ) ;
}
if ( V_261 -> V_22 != V_6 -> V_22 ) {
V_262 = 1 ;
V_6 -> V_22 = V_261 -> V_22 ;
if ( V_6 -> V_37 -> V_167 )
V_6 -> V_37 -> V_167 ( V_2 ) ;
}
if ( ! V_6 -> V_263 ) {
F_1 ( V_2 ,
F_5 ( V_2 , V_20 ) & ~ V_265 ,
V_20 ) ;
V_262 = 1 ;
V_6 -> V_263 = V_261 -> V_263 ;
if ( V_6 -> V_37 -> V_226 || V_6 -> V_227 )
F_81 ( V_2 ) ;
}
} else if ( V_6 -> V_263 ) {
V_262 = 1 ;
V_6 -> V_263 = 0 ;
V_6 -> V_22 = 0 ;
V_6 -> V_19 = - 1 ;
if ( V_6 -> V_37 -> V_226 || V_6 -> V_227 )
F_64 ( V_2 ) ;
}
if ( V_262 && F_94 ( V_6 ) )
F_95 ( V_261 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_266 * V_267 = V_2 -> V_122 . V_268 -> V_269 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_260 * V_261 = NULL ;
V_6 -> V_263 = 0 ;
V_6 -> V_22 = 0 ;
V_6 -> V_19 = - 1 ;
if ( V_267 ) {
struct V_266 * V_270 ;
V_270 = F_97 ( V_267 , L_11 , 0 ) ;
V_261 = F_98 ( V_2 , V_270 ,
F_93 , 0 ,
V_6 -> V_14 ) ;
if ( ! V_261 )
V_261 = F_99 ( - V_271 ) ;
} else {
char V_272 [ V_273 + 3 ] ;
snprintf ( V_272 , sizeof( V_272 ) , V_274 ,
V_6 -> V_275 -> V_276 , V_6 -> V_272 ) ;
V_261 = F_100 ( V_2 , V_272 , F_93 ,
V_6 -> V_14 ) ;
}
if ( F_101 ( V_261 ) ) {
F_26 ( V_2 , L_12 ) ;
return F_102 ( V_261 ) ;
}
F_103 ( V_2 , L_13 ,
V_261 -> V_10 , V_261 -> V_249 , V_261 -> V_277 -> V_278 ) ;
V_6 -> V_261 = V_261 ;
return 0 ;
}
static int F_104 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_53 ;
V_53 = F_96 ( V_2 ) ;
if ( V_53 )
return V_53 ;
F_105 ( V_6 -> V_261 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_279 * V_280 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_281 ;
int V_53 ;
if ( ! V_6 -> V_261 )
return - V_282 ;
F_107 ( & V_6 -> V_253 , V_281 ) ;
V_53 = F_108 ( V_6 -> V_261 , V_280 ) ;
F_109 ( & V_6 -> V_253 , V_281 ) ;
return V_53 ;
}
static int F_110 ( struct V_1 * V_2 ,
struct V_279 * V_280 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_281 ;
int V_53 ;
if ( ! V_6 -> V_261 )
return - V_282 ;
F_107 ( & V_6 -> V_253 , V_281 ) ;
F_64 ( V_2 ) ;
V_53 = F_111 ( V_6 -> V_261 , V_280 ) ;
if ( V_53 )
goto V_283;
if ( V_280 -> V_19 == V_284 )
V_6 -> V_19 = 1 ;
else
V_6 -> V_19 = 0 ;
if ( V_6 -> V_37 -> V_264 )
V_6 -> V_37 -> V_264 ( V_2 ) ;
V_283:
F_18 ( 1 ) ;
F_81 ( V_2 ) ;
F_109 ( & V_6 -> V_253 , V_281 ) ;
return V_53 ;
}
static T_7 F_112 ( struct V_1 * V_2 , T_1 * V_285 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_36 * V_37 = V_6 -> V_37 ;
T_1 * V_286 ;
T_7 V_121 ;
F_113 ( V_287 > V_288 ) ;
V_121 = F_114 ( V_288 , 32 ) ;
if ( V_285 ) {
V_286 = V_285 ;
V_285 += V_121 ;
} else {
V_286 = NULL ;
}
#define F_115 ( T_8 ) valid_map[reg / 32] |= 1U << (reg % 32)
#define F_116 ( T_8 , T_9 ) do { \
if (mdp->reg_offset[reg] != SH_ETH_OFFSET_INVALID) { \
if (buf) { \
mark_reg_valid(reg); \
*buf++ = read_expr; \
} \
++len; \
} \
} while (0)
#define F_117 ( T_8 ) add_reg_from(reg, sh_eth_read(ndev, reg))
#define F_118 ( T_8 ) add_reg_from(reg, sh_eth_tsu_read(mdp, reg))
F_117 ( V_58 ) ;
F_117 ( V_55 ) ;
F_117 ( V_247 ) ;
F_117 ( V_180 ) ;
F_117 ( V_161 ) ;
F_117 ( V_143 ) ;
F_117 ( V_60 ) ;
F_117 ( V_61 ) ;
F_117 ( V_62 ) ;
F_117 ( V_63 ) ;
F_117 ( V_64 ) ;
F_117 ( V_65 ) ;
F_117 ( V_66 ) ;
F_117 ( V_67 ) ;
F_117 ( V_151 ) ;
F_117 ( V_289 ) ;
F_117 ( V_148 ) ;
F_117 ( V_147 ) ;
F_117 ( V_150 ) ;
F_117 ( V_290 ) ;
F_117 ( V_291 ) ;
if ( V_37 -> V_139 )
F_117 ( V_140 ) ;
F_117 ( V_154 ) ;
if ( V_37 -> V_132 )
F_117 ( V_142 ) ;
if ( ! V_37 -> V_155 )
F_117 ( V_156 ) ;
F_117 ( V_20 ) ;
F_117 ( V_168 ) ;
F_117 ( V_169 ) ;
F_117 ( V_292 ) ;
if ( ! V_37 -> V_226 )
F_117 ( V_229 ) ;
F_117 ( V_293 ) ;
F_117 ( V_160 ) ;
F_117 ( V_294 ) ;
if ( V_37 -> V_170 )
F_117 ( V_172 ) ;
if ( V_37 -> V_173 )
F_117 ( V_175 ) ;
F_117 ( V_295 ) ;
F_117 ( V_296 ) ;
if ( V_37 -> V_176 )
F_117 ( V_178 ) ;
F_117 ( V_297 ) ;
F_117 ( V_31 ) ;
if ( V_37 -> V_152 )
F_117 ( V_153 ) ;
F_117 ( V_81 ) ;
F_117 ( V_82 ) ;
F_117 ( V_298 ) ;
F_117 ( V_299 ) ;
F_117 ( V_300 ) ;
F_117 ( V_301 ) ;
F_117 ( V_302 ) ;
F_117 ( V_303 ) ;
F_117 ( V_304 ) ;
F_117 ( V_305 ) ;
F_117 ( V_306 ) ;
F_117 ( V_307 ) ;
F_117 ( V_308 ) ;
if ( V_37 -> V_309 )
F_117 ( V_25 ) ;
if ( V_37 -> V_68 )
F_117 ( V_69 ) ;
if ( V_37 -> V_70 )
F_117 ( V_18 ) ;
F_117 ( V_32 ) ;
if ( V_37 -> V_310 ) {
F_118 ( V_311 ) ;
F_118 ( V_312 ) ;
F_118 ( V_313 ) ;
F_118 ( V_314 ) ;
F_118 ( V_315 ) ;
F_118 ( V_316 ) ;
F_118 ( V_317 ) ;
F_118 ( V_318 ) ;
F_118 ( V_319 ) ;
F_118 ( V_320 ) ;
F_118 ( V_321 ) ;
F_118 ( V_322 ) ;
F_118 ( V_323 ) ;
F_118 ( V_324 ) ;
F_118 ( V_325 ) ;
F_118 ( V_326 ) ;
F_118 ( V_327 ) ;
F_118 ( V_328 ) ;
F_118 ( V_329 ) ;
F_118 ( V_330 ) ;
F_118 ( V_331 ) ;
F_118 ( V_332 ) ;
F_118 ( V_333 ) ;
F_118 ( V_334 ) ;
F_118 ( V_335 ) ;
F_118 ( V_336 ) ;
F_118 ( V_337 ) ;
if ( V_6 -> V_8 [ V_338 ] != V_9 ) {
if ( V_285 ) {
unsigned int V_26 ;
F_115 ( V_338 ) ;
for ( V_26 = 0 ; V_26 < V_339 * 2 ; V_26 ++ )
* V_285 ++ = F_6 (
V_6 -> V_340 +
V_6 -> V_8 [ V_338 ] +
V_26 * 4 ) ;
}
V_121 += V_339 * 2 ;
}
}
#undef F_115
#undef F_116
#undef F_117
#undef F_118
return V_121 * 4 ;
}
static int F_119 ( struct V_1 * V_2 )
{
return F_112 ( V_2 , NULL ) ;
}
static void F_120 ( struct V_1 * V_2 , struct V_341 * V_342 ,
void * V_285 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_342 -> V_343 = V_344 ;
F_121 ( & V_6 -> V_345 -> V_122 ) ;
F_112 ( V_2 , V_285 ) ;
F_122 ( & V_6 -> V_345 -> V_122 ) ;
}
static int F_123 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_281 ;
int V_53 ;
if ( ! V_6 -> V_261 )
return - V_282 ;
F_107 ( & V_6 -> V_253 , V_281 ) ;
V_53 = F_124 ( V_6 -> V_261 ) ;
F_109 ( & V_6 -> V_253 , V_281 ) ;
return V_53 ;
}
static T_1 F_125 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_346 ;
}
static void F_126 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_346 = V_13 ;
}
static int F_127 ( struct V_1 * V_250 , int V_347 )
{
switch ( V_347 ) {
case V_348 :
return V_349 ;
default:
return - V_350 ;
}
}
static void F_128 ( struct V_1 * V_2 ,
struct V_351 * V_186 , T_10 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 = 0 ;
V_3 [ V_26 ++ ] = V_6 -> V_117 ;
V_3 [ V_26 ++ ] = V_6 -> V_118 ;
V_3 [ V_26 ++ ] = V_6 -> V_119 ;
V_3 [ V_26 ++ ] = V_6 -> V_120 ;
}
static void F_129 ( struct V_1 * V_2 , T_1 V_352 , T_11 * V_3 )
{
switch ( V_352 ) {
case V_348 :
memcpy ( V_3 , * V_353 ,
sizeof( V_353 ) ) ;
break;
}
}
static void F_130 ( struct V_1 * V_2 ,
struct V_354 * V_355 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_355 -> V_356 = V_357 ;
V_355 -> V_358 = V_359 ;
V_355 -> V_360 = V_6 -> V_100 ;
V_355 -> V_361 = V_6 -> V_102 ;
}
static int F_131 ( struct V_1 * V_2 ,
struct V_354 * V_355 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_53 ;
if ( V_355 -> V_361 > V_359 ||
V_355 -> V_360 > V_357 ||
V_355 -> V_361 < V_362 ||
V_355 -> V_360 < V_363 )
return - V_364 ;
if ( V_355 -> V_365 || V_355 -> V_366 )
return - V_364 ;
if ( F_132 ( V_2 ) ) {
F_133 ( V_2 ) ;
F_134 ( V_2 ) ;
V_6 -> V_162 = false ;
F_135 ( V_2 -> V_249 ) ;
F_136 ( & V_6 -> V_257 ) ;
F_1 ( V_2 , 0x0000 , V_143 ) ;
F_63 ( V_2 ) ;
F_47 ( V_2 ) ;
}
V_6 -> V_100 = V_355 -> V_360 ;
V_6 -> V_102 = V_355 -> V_361 ;
if ( F_132 ( V_2 ) ) {
V_53 = F_57 ( V_2 ) ;
if ( V_53 < 0 ) {
F_26 ( V_2 , L_14 ,
V_367 ) ;
return V_53 ;
}
V_53 = F_60 ( V_2 , false ) ;
if ( V_53 < 0 ) {
F_26 ( V_2 , L_15 ,
V_367 ) ;
return V_53 ;
}
V_6 -> V_162 = true ;
F_1 ( V_2 , V_6 -> V_37 -> V_163 , V_143 ) ;
F_1 ( V_2 , V_179 , V_180 ) ;
F_137 ( V_2 ) ;
}
return 0 ;
}
static int F_138 ( struct V_1 * V_2 )
{
int V_53 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_121 ( & V_6 -> V_345 -> V_122 ) ;
F_139 ( & V_6 -> V_257 ) ;
V_53 = F_140 ( V_2 -> V_249 , F_85 ,
V_6 -> V_37 -> V_368 , V_2 -> V_278 , V_2 ) ;
if ( V_53 ) {
F_26 ( V_2 , L_16 ) ;
goto V_369;
}
V_53 = F_57 ( V_2 ) ;
if ( V_53 )
goto V_370;
V_53 = F_60 ( V_2 , true ) ;
if ( V_53 )
goto V_370;
V_53 = F_104 ( V_2 ) ;
if ( V_53 )
goto V_370;
V_6 -> V_371 = 1 ;
return V_53 ;
V_370:
F_141 ( V_2 -> V_249 , V_2 ) ;
V_369:
F_142 ( & V_6 -> V_257 ) ;
F_122 ( & V_6 -> V_345 -> V_122 ) ;
return V_53 ;
}
static void F_143 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_104 * V_109 ;
int V_26 ;
F_144 ( V_2 ) ;
F_83 ( V_6 , V_372 , V_2 ,
L_17 ,
F_5 ( V_2 , V_161 ) ) ;
V_2 -> V_186 . V_373 ++ ;
for ( V_26 = 0 ; V_26 < V_6 -> V_100 ; V_26 ++ ) {
V_109 = & V_6 -> V_103 [ V_26 ] ;
V_109 -> V_124 = F_30 ( V_6 , 0 ) ;
V_109 -> V_10 = F_30 ( V_6 , 0xBADF00D0 ) ;
F_48 ( V_6 -> V_99 [ V_26 ] ) ;
V_6 -> V_99 [ V_26 ] = NULL ;
}
for ( V_26 = 0 ; V_26 < V_6 -> V_102 ; V_26 ++ ) {
F_48 ( V_6 -> V_101 [ V_26 ] ) ;
V_6 -> V_101 [ V_26 ] = NULL ;
}
F_60 ( V_2 , true ) ;
}
static int F_145 ( struct V_72 * V_73 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_107 * V_110 ;
T_5 V_115 ;
T_1 V_183 ;
unsigned long V_281 ;
F_107 ( & V_6 -> V_253 , V_281 ) ;
if ( ( V_6 -> V_118 - V_6 -> V_120 ) >= ( V_6 -> V_102 - 4 ) ) {
if ( ! F_67 ( V_2 ) ) {
F_146 ( V_6 , V_374 , V_2 , L_18 ) ;
F_144 ( V_2 ) ;
F_109 ( & V_6 -> V_253 , V_281 ) ;
return V_375 ;
}
}
F_109 ( & V_6 -> V_253 , V_281 ) ;
if ( F_147 ( V_73 , V_376 ) )
return V_377 ;
V_183 = V_6 -> V_118 % V_6 -> V_102 ;
V_6 -> V_101 [ V_183 ] = V_73 ;
V_110 = & V_6 -> V_106 [ V_183 ] ;
if ( ! V_6 -> V_37 -> V_145 )
F_74 ( F_148 ( V_73 -> V_3 , 4 ) , V_73 -> V_121 + 2 ) ;
V_115 = F_54 ( & V_2 -> V_122 , V_73 -> V_3 , V_73 -> V_121 ,
V_185 ) ;
if ( F_55 ( & V_2 -> V_122 , V_115 ) ) {
F_56 ( V_73 ) ;
return V_377 ;
}
V_110 -> V_10 = F_30 ( V_6 , V_115 ) ;
V_110 -> V_121 = F_30 ( V_6 , V_73 -> V_121 << 16 ) ;
F_80 () ;
if ( V_183 >= V_6 -> V_102 - 1 )
V_110 -> V_124 |= F_30 ( V_6 , V_181 | V_129 ) ;
else
V_110 -> V_124 |= F_30 ( V_6 , V_181 ) ;
V_6 -> V_118 ++ ;
if ( ! ( F_5 ( V_2 , V_247 ) & F_38 ( V_6 ) ) )
F_1 ( V_2 , F_38 ( V_6 ) , V_247 ) ;
return V_377 ;
}
static void
F_149 ( struct V_1 * V_2 , unsigned long * V_378 , int T_8 )
{
T_1 V_379 = F_5 ( V_2 , T_8 ) ;
if ( V_379 ) {
* V_378 += V_379 ;
F_1 ( V_2 , 0 , T_8 ) ;
}
}
static struct V_380 * F_66 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_8 ( V_6 ) )
return & V_2 -> V_186 ;
if ( ! V_6 -> V_371 )
return & V_2 -> V_186 ;
F_149 ( V_2 , & V_2 -> V_186 . V_381 , V_298 ) ;
F_149 ( V_2 , & V_2 -> V_186 . V_382 , V_299 ) ;
F_149 ( V_2 , & V_2 -> V_186 . V_224 , V_300 ) ;
if ( F_7 ( V_6 ) ) {
F_149 ( V_2 , & V_2 -> V_186 . V_224 ,
V_306 ) ;
F_149 ( V_2 , & V_2 -> V_186 . V_224 ,
V_307 ) ;
} else {
F_149 ( V_2 , & V_2 -> V_186 . V_224 ,
V_301 ) ;
}
return & V_2 -> V_186 ;
}
static int F_150 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_144 ( V_2 ) ;
V_6 -> V_162 = false ;
F_135 ( V_2 -> V_249 ) ;
F_142 ( & V_6 -> V_257 ) ;
F_1 ( V_2 , 0x0000 , V_143 ) ;
F_63 ( V_2 ) ;
if ( V_6 -> V_261 ) {
F_151 ( V_6 -> V_261 ) ;
F_152 ( V_6 -> V_261 ) ;
V_6 -> V_261 = NULL ;
}
F_141 ( V_2 -> V_249 , V_2 ) ;
F_47 ( V_2 ) ;
F_122 ( & V_6 -> V_345 -> V_122 ) ;
V_6 -> V_371 = 0 ;
return 0 ;
}
static int F_153 ( struct V_1 * V_2 , struct V_383 * V_384 , int V_385 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_260 * V_261 = V_6 -> V_261 ;
if ( ! F_132 ( V_2 ) )
return - V_364 ;
if ( ! V_261 )
return - V_282 ;
return F_154 ( V_261 , V_384 , V_385 ) ;
}
static void * F_155 ( struct V_5 * V_6 ,
int V_183 )
{
return F_156 ( V_6 , V_334 ) + ( V_183 / 8 * 4 ) ;
}
static T_1 F_157 ( int V_183 )
{
return 0x0f << ( 28 - ( ( V_183 % 8 ) * 4 ) ) ;
}
static T_1 F_158 ( struct V_5 * V_6 , int V_183 )
{
return ( 0x08 >> ( V_6 -> V_386 << 1 ) ) << ( 28 - ( ( V_183 % 8 ) * 4 ) ) ;
}
static void F_159 ( struct V_1 * V_2 ,
int V_183 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_387 ;
void * V_8 ;
V_8 = F_155 ( V_6 , V_183 ) ;
V_387 = F_6 ( V_8 ) ;
F_4 ( V_387 | F_158 ( V_6 , V_183 ) , V_8 ) ;
}
static bool F_160 ( struct V_1 * V_2 ,
int V_183 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_388 , V_389 , V_387 ;
void * V_8 ;
V_8 = F_155 ( V_6 , V_183 ) ;
V_388 = F_157 ( V_183 ) ;
V_389 = F_158 ( V_6 , V_183 ) & ~ V_388 ;
V_387 = F_6 ( V_8 ) ;
F_4 ( V_387 & ~ V_388 , V_8 ) ;
return V_387 & V_389 ;
}
static int F_161 ( struct V_1 * V_2 )
{
int V_390 = V_391 * 100 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
while ( ( F_162 ( V_6 , V_332 ) & V_392 ) ) {
F_163 ( 10 ) ;
V_390 -- ;
if ( V_390 <= 0 ) {
F_26 ( V_2 , L_19 , V_367 ) ;
return - V_56 ;
}
}
return 0 ;
}
static int F_164 ( struct V_1 * V_2 , void * T_8 ,
const T_11 * V_10 )
{
T_1 V_138 ;
V_138 = V_10 [ 0 ] << 24 | V_10 [ 1 ] << 16 | V_10 [ 2 ] << 8 | V_10 [ 3 ] ;
F_4 ( V_138 , T_8 ) ;
if ( F_161 ( V_2 ) < 0 )
return - V_393 ;
V_138 = V_10 [ 4 ] << 8 | V_10 [ 5 ] ;
F_4 ( V_138 , T_8 + 4 ) ;
if ( F_161 ( V_2 ) < 0 )
return - V_393 ;
return 0 ;
}
static void F_165 ( void * T_8 , T_11 * V_10 )
{
T_1 V_138 ;
V_138 = F_6 ( T_8 ) ;
V_10 [ 0 ] = ( V_138 >> 24 ) & 0xff ;
V_10 [ 1 ] = ( V_138 >> 16 ) & 0xff ;
V_10 [ 2 ] = ( V_138 >> 8 ) & 0xff ;
V_10 [ 3 ] = V_138 & 0xff ;
V_138 = F_6 ( T_8 + 4 ) ;
V_10 [ 4 ] = ( V_138 >> 8 ) & 0xff ;
V_10 [ 5 ] = V_138 & 0xff ;
}
static int F_166 ( struct V_1 * V_2 , const T_11 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void * V_8 = F_156 ( V_6 , V_338 ) ;
int V_26 ;
T_11 V_394 [ V_84 ] ;
for ( V_26 = 0 ; V_26 < V_339 ; V_26 ++ , V_8 += 8 ) {
F_165 ( V_8 , V_394 ) ;
if ( F_167 ( V_10 , V_394 ) )
return V_26 ;
}
return - V_271 ;
}
static int F_168 ( struct V_1 * V_2 )
{
T_11 V_395 [ V_84 ] ;
int V_183 ;
memset ( V_395 , 0 , sizeof( V_395 ) ) ;
V_183 = F_166 ( V_2 , V_395 ) ;
return ( V_183 < 0 ) ? - V_135 : V_183 ;
}
static int F_169 ( struct V_1 * V_2 ,
int V_183 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void * V_8 = F_156 ( V_6 , V_338 ) ;
int V_53 ;
T_11 V_395 [ V_84 ] ;
F_21 ( V_6 , F_162 ( V_6 , V_333 ) &
~ ( 1 << ( 31 - V_183 ) ) , V_333 ) ;
memset ( V_395 , 0 , sizeof( V_395 ) ) ;
V_53 = F_164 ( V_2 , V_8 + V_183 * 8 , V_395 ) ;
if ( V_53 < 0 )
return V_53 ;
return 0 ;
}
static int F_170 ( struct V_1 * V_2 , const T_11 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void * V_8 = F_156 ( V_6 , V_338 ) ;
int V_26 , V_53 ;
if ( ! V_6 -> V_37 -> V_310 )
return 0 ;
V_26 = F_166 ( V_2 , V_10 ) ;
if ( V_26 < 0 ) {
V_26 = F_168 ( V_2 ) ;
if ( V_26 < 0 )
return - V_135 ;
V_53 = F_164 ( V_2 , V_8 + V_26 * 8 , V_10 ) ;
if ( V_53 < 0 )
return V_53 ;
F_21 ( V_6 , F_162 ( V_6 , V_333 ) |
( 1 << ( 31 - V_26 ) ) , V_333 ) ;
}
F_159 ( V_2 , V_26 ) ;
return 0 ;
}
static int F_171 ( struct V_1 * V_2 , const T_11 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 , V_53 ;
if ( ! V_6 -> V_37 -> V_310 )
return 0 ;
V_26 = F_166 ( V_2 , V_10 ) ;
if ( V_26 ) {
if ( F_160 ( V_2 , V_26 ) )
goto V_396;
V_53 = F_169 ( V_2 , V_26 ) ;
if ( V_53 < 0 )
return V_53 ;
}
V_396:
return 0 ;
}
static int F_172 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 , V_53 ;
if ( ! V_6 -> V_37 -> V_310 )
return 0 ;
for ( V_26 = 0 ; V_26 < V_339 ; V_26 ++ ) {
if ( F_160 ( V_2 , V_26 ) )
continue;
V_53 = F_169 ( V_2 , V_26 ) ;
if ( V_53 < 0 )
return V_53 ;
}
return 0 ;
}
static void F_173 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_11 V_10 [ V_84 ] ;
void * V_8 = F_156 ( V_6 , V_338 ) ;
int V_26 ;
if ( ! V_6 -> V_37 -> V_310 )
return;
for ( V_26 = 0 ; V_26 < V_339 ; V_26 ++ , V_8 += 8 ) {
F_165 ( V_8 , V_10 ) ;
if ( F_174 ( V_10 ) )
F_171 ( V_2 , V_10 ) ;
}
}
static void F_175 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_397 ;
int V_398 = 0 ;
unsigned long V_281 ;
F_107 ( & V_6 -> V_253 , V_281 ) ;
V_397 = F_5 ( V_2 , V_20 ) & ~ V_399 ;
if ( V_6 -> V_37 -> V_310 )
V_397 |= V_400 ;
if ( ! ( V_2 -> V_281 & V_401 ) ) {
F_173 ( V_2 ) ;
V_398 = 1 ;
}
if ( V_2 -> V_281 & V_402 ) {
F_173 ( V_2 ) ;
V_397 &= ~ V_400 ;
V_398 = 1 ;
}
if ( V_2 -> V_281 & V_403 ) {
F_172 ( V_2 ) ;
V_397 = ( V_397 & ~ V_400 ) | V_399 ;
} else if ( V_6 -> V_37 -> V_310 ) {
struct V_404 * V_405 ;
F_176 (ha, ndev) {
if ( V_398 && F_174 ( V_405 -> V_10 ) )
continue;
if ( F_170 ( V_2 , V_405 -> V_10 ) < 0 ) {
if ( ! V_398 ) {
F_173 ( V_2 ) ;
V_397 &= ~ V_400 ;
V_398 = 1 ;
}
}
}
}
F_1 ( V_2 , V_397 , V_20 ) ;
F_109 ( & V_6 -> V_253 , V_281 ) ;
}
static int F_177 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_386 )
return V_330 ;
else
return V_331 ;
}
static int F_178 ( struct V_1 * V_2 ,
T_12 V_406 , T_2 V_407 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_408 = F_177 ( V_6 ) ;
if ( F_179 ( ! V_6 -> V_37 -> V_310 ) )
return - V_409 ;
if ( ! V_407 )
return 0 ;
V_6 -> V_410 ++ ;
if ( V_6 -> V_410 > 1 ) {
F_21 ( V_6 , 0 , V_408 ) ;
return 0 ;
}
F_21 ( V_6 , V_411 | ( V_407 & V_412 ) ,
V_408 ) ;
return 0 ;
}
static int F_180 ( struct V_1 * V_2 ,
T_12 V_406 , T_2 V_407 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_408 = F_177 ( V_6 ) ;
if ( F_179 ( ! V_6 -> V_37 -> V_310 ) )
return - V_409 ;
if ( ! V_407 )
return 0 ;
V_6 -> V_410 -- ;
F_21 ( V_6 , 0 , V_408 ) ;
return 0 ;
}
static void F_181 ( struct V_5 * V_6 )
{
if ( F_8 ( V_6 ) ) {
F_21 ( V_6 , 0 , V_333 ) ;
return;
}
F_21 ( V_6 , 0 , V_312 ) ;
F_21 ( V_6 , 0 , V_313 ) ;
F_21 ( V_6 , 0 , V_314 ) ;
F_21 ( V_6 , 0xc , V_315 ) ;
F_21 ( V_6 , 0xc , V_316 ) ;
F_21 ( V_6 , 0 , V_317 ) ;
F_21 ( V_6 , 0 , V_318 ) ;
F_21 ( V_6 , 0 , V_319 ) ;
F_21 ( V_6 , 0 , V_320 ) ;
F_21 ( V_6 , V_413 | V_414 , V_321 ) ;
if ( F_7 ( V_6 ) ) {
F_21 ( V_6 , 0 , V_322 ) ;
F_21 ( V_6 , 0 , V_323 ) ;
} else {
F_21 ( V_6 , 0 , V_324 ) ;
F_21 ( V_6 , 0 , V_325 ) ;
}
F_21 ( V_6 , 0 , V_326 ) ;
F_21 ( V_6 , 0 , V_327 ) ;
F_21 ( V_6 , 0 , V_333 ) ;
F_21 ( V_6 , 0 , V_334 ) ;
F_21 ( V_6 , 0 , V_335 ) ;
F_21 ( V_6 , 0 , V_336 ) ;
F_21 ( V_6 , 0 , V_337 ) ;
}
static int F_182 ( struct V_5 * V_6 )
{
F_183 ( V_6 -> V_275 ) ;
F_184 ( V_6 -> V_275 ) ;
return 0 ;
}
static int F_185 ( struct V_5 * V_6 ,
struct V_415 * V_416 )
{
int V_53 , V_26 ;
struct V_91 * V_92 ;
struct V_417 * V_345 = V_6 -> V_345 ;
struct V_418 * V_122 = & V_6 -> V_345 -> V_122 ;
V_92 = F_186 ( V_122 , sizeof( struct V_91 ) , V_134 ) ;
if ( ! V_92 )
return - V_135 ;
V_92 -> V_10 = V_6 -> V_10 + V_6 -> V_8 [ V_292 ] ;
V_92 -> V_93 = V_416 -> V_419 ;
V_92 -> V_96 = V_420 ;
V_92 -> V_95 = V_421 ;
V_92 -> V_94 = V_422 ;
V_92 -> V_97 = V_423 ;
V_92 -> V_89 . V_424 = & V_425 ;
V_6 -> V_275 = F_187 ( & V_92 -> V_89 ) ;
if ( ! V_6 -> V_275 )
return - V_135 ;
V_6 -> V_275 -> V_278 = L_20 ;
V_6 -> V_275 -> V_268 = V_122 ;
snprintf ( V_6 -> V_275 -> V_276 , V_273 , L_21 ,
V_345 -> V_278 , V_345 -> V_276 ) ;
V_6 -> V_275 -> V_249 = F_188 ( V_122 , V_426 , sizeof( int ) ,
V_134 ) ;
if ( ! V_6 -> V_275 -> V_249 ) {
V_53 = - V_135 ;
goto V_427;
}
if ( V_122 -> V_269 ) {
V_53 = F_189 ( V_6 -> V_275 , V_122 -> V_269 ) ;
} else {
for ( V_26 = 0 ; V_26 < V_426 ; V_26 ++ )
V_6 -> V_275 -> V_249 [ V_26 ] = V_428 ;
if ( V_416 -> V_429 > 0 )
V_6 -> V_275 -> V_249 [ V_416 -> V_430 ] = V_416 -> V_429 ;
V_53 = F_190 ( V_6 -> V_275 ) ;
}
if ( V_53 )
goto V_427;
return 0 ;
V_427:
F_184 ( V_6 -> V_275 ) ;
return V_53 ;
}
static const T_2 * F_191 ( int V_431 )
{
const T_2 * V_8 = NULL ;
switch ( V_431 ) {
case V_432 :
V_8 = V_11 ;
break;
case V_433 :
V_8 = V_12 ;
break;
case V_434 :
V_8 = V_435 ;
break;
case V_436 :
V_8 = V_437 ;
break;
case V_438 :
V_8 = V_439 ;
break;
default:
break;
}
return V_8 ;
}
static struct V_415 * F_192 ( struct V_418 * V_122 )
{
struct V_266 * V_267 = V_122 -> V_269 ;
struct V_415 * V_440 ;
const char * V_441 ;
V_440 = F_186 ( V_122 , sizeof( * V_440 ) , V_134 ) ;
if ( ! V_440 )
return NULL ;
V_440 -> V_14 = F_193 ( V_267 ) ;
V_441 = F_194 ( V_267 ) ;
if ( V_441 )
memcpy ( V_440 -> V_441 , V_441 , V_84 ) ;
V_440 -> V_227 =
F_195 ( V_267 , L_22 ) ;
V_440 -> V_230 =
F_195 ( V_267 , L_23 ) ;
return V_440 ;
}
static inline struct V_415 * F_192 ( struct V_418 * V_122 )
{
return NULL ;
}
static int F_196 ( struct V_417 * V_345 )
{
int V_53 , V_442 = 0 ;
struct V_443 * V_444 ;
struct V_1 * V_2 = NULL ;
struct V_5 * V_6 = NULL ;
struct V_415 * V_416 = F_197 ( & V_345 -> V_122 ) ;
const struct V_445 * V_276 = F_198 ( V_345 ) ;
V_444 = F_199 ( V_345 , V_446 , 0 ) ;
V_2 = F_200 ( sizeof( struct V_5 ) ) ;
if ( ! V_2 )
return - V_135 ;
F_201 ( & V_345 -> V_122 ) ;
F_121 ( & V_345 -> V_122 ) ;
V_442 = V_345 -> V_276 ;
if ( V_442 < 0 )
V_442 = 0 ;
V_2 -> V_447 = - 1 ;
V_53 = F_202 ( V_345 , 0 ) ;
if ( V_53 < 0 )
goto V_448;
V_2 -> V_249 = V_53 ;
F_203 ( V_2 , & V_345 -> V_122 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_102 = V_449 ;
V_6 -> V_100 = V_450 ;
V_6 -> V_10 = F_204 ( & V_345 -> V_122 , V_444 ) ;
if ( F_101 ( V_6 -> V_10 ) ) {
V_53 = F_102 ( V_6 -> V_10 ) ;
goto V_448;
}
V_2 -> V_451 = V_444 -> V_137 ;
F_205 ( & V_6 -> V_253 ) ;
V_6 -> V_345 = V_345 ;
if ( V_345 -> V_122 . V_269 )
V_416 = F_192 ( & V_345 -> V_122 ) ;
if ( ! V_416 ) {
F_206 ( & V_345 -> V_122 , L_24 ) ;
V_53 = - V_364 ;
goto V_448;
}
V_6 -> V_272 = V_416 -> V_430 ;
V_6 -> V_14 = V_416 -> V_14 ;
V_6 -> V_77 = V_416 -> V_77 ;
V_6 -> V_227 = V_416 -> V_227 ;
V_6 -> V_230 = V_416 -> V_230 ;
if ( V_276 ) {
V_6 -> V_37 = (struct V_36 * ) V_276 -> V_452 ;
} else {
const struct V_453 * V_454 ;
V_454 = F_207 ( F_208 ( V_455 ) ,
& V_345 -> V_122 ) ;
V_6 -> V_37 = (struct V_36 * ) V_454 -> V_3 ;
}
V_6 -> V_8 = F_191 ( V_6 -> V_37 -> V_431 ) ;
if ( ! V_6 -> V_8 ) {
F_206 ( & V_345 -> V_122 , L_25 ,
V_6 -> V_37 -> V_431 ) ;
V_53 = - V_364 ;
goto V_448;
}
F_24 ( V_6 -> V_37 ) ;
if ( V_6 -> V_37 -> V_310 )
V_2 -> V_456 = & V_457 ;
else
V_2 -> V_456 = & V_458 ;
V_2 -> V_459 = & V_460 ;
V_2 -> V_461 = V_462 ;
V_6 -> V_346 = V_463 ;
F_37 ( V_2 , V_416 -> V_441 ) ;
if ( ! F_209 ( V_2 -> V_80 ) ) {
F_210 ( & V_345 -> V_122 ,
L_26 ) ;
F_211 ( V_2 ) ;
}
if ( V_6 -> V_37 -> V_310 ) {
struct V_443 * V_464 ;
V_464 = F_199 ( V_345 , V_446 , 1 ) ;
V_6 -> V_340 = F_204 ( & V_345 -> V_122 , V_464 ) ;
if ( F_101 ( V_6 -> V_340 ) ) {
V_53 = F_102 ( V_6 -> V_340 ) ;
goto V_448;
}
V_6 -> V_386 = V_442 % 2 ;
V_2 -> V_465 = V_466 ;
}
if ( ! V_442 || V_416 -> V_467 ) {
if ( V_6 -> V_37 -> V_468 )
V_6 -> V_37 -> V_468 ( V_2 ) ;
if ( V_6 -> V_37 -> V_310 ) {
F_181 ( V_6 ) ;
}
}
if ( V_6 -> V_37 -> V_139 )
F_1 ( V_2 , 0x1 , V_140 ) ;
V_53 = F_185 ( V_6 , V_416 ) ;
if ( V_53 ) {
F_206 ( & V_2 -> V_122 , L_27 ) ;
goto V_448;
}
F_212 ( V_2 , & V_6 -> V_257 , F_91 , 64 ) ;
V_53 = F_213 ( V_2 ) ;
if ( V_53 )
goto V_469;
F_103 ( V_2 , L_28 ,
( T_1 ) V_2 -> V_451 , V_2 -> V_80 , V_2 -> V_249 ) ;
F_214 ( & V_345 -> V_122 ) ;
F_215 ( V_345 , V_2 ) ;
return V_53 ;
V_469:
F_216 ( & V_6 -> V_257 ) ;
F_182 ( V_6 ) ;
V_448:
if ( V_2 )
F_217 ( V_2 ) ;
F_214 ( & V_345 -> V_122 ) ;
F_218 ( & V_345 -> V_122 ) ;
return V_53 ;
}
static int F_219 ( struct V_417 * V_345 )
{
struct V_1 * V_2 = F_220 ( V_345 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_221 ( V_2 ) ;
F_216 ( & V_6 -> V_257 ) ;
F_182 ( V_6 ) ;
F_218 ( & V_345 -> V_122 ) ;
F_217 ( V_2 ) ;
return 0 ;
}
static int F_222 ( struct V_418 * V_122 )
{
struct V_1 * V_2 = F_223 ( V_122 ) ;
int V_53 = 0 ;
if ( F_132 ( V_2 ) ) {
F_133 ( V_2 ) ;
V_53 = F_150 ( V_2 ) ;
}
return V_53 ;
}
static int F_224 ( struct V_418 * V_122 )
{
struct V_1 * V_2 = F_223 ( V_122 ) ;
int V_53 = 0 ;
if ( F_132 ( V_2 ) ) {
V_53 = F_138 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
F_137 ( V_2 ) ;
}
return V_53 ;
}
static int F_225 ( struct V_418 * V_122 )
{
return 0 ;
}
