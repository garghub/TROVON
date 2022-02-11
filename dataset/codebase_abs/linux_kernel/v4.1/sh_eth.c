static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static bool F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_5 ;
}
static void F_3 ( struct V_6 * V_7 )
{
T_1 V_8 = 0x0 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
switch ( V_2 -> V_9 ) {
case V_10 :
V_8 = 0x2 ;
break;
case V_11 :
V_8 = 0x1 ;
break;
case V_12 :
V_8 = 0x0 ;
break;
default:
F_5 ( V_7 ,
L_1 ) ;
V_8 = 0x1 ;
break;
}
F_6 ( V_7 , V_8 , V_13 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
if ( V_2 -> V_14 )
F_6 ( V_7 , F_8 ( V_7 , V_15 ) | V_16 , V_15 ) ;
else
F_6 ( V_7 , F_8 ( V_7 , V_15 ) & ~ V_16 , V_15 ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
switch ( V_2 -> V_17 ) {
case 10 :
F_6 ( V_7 , F_8 ( V_7 , V_15 ) & ~ V_18 , V_15 ) ;
break;
case 100 :
F_6 ( V_7 , F_8 ( V_7 , V_15 ) | V_18 , V_15 ) ;
break;
default:
break;
}
}
static void F_10 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
switch ( V_2 -> V_17 ) {
case 10 :
F_6 ( V_7 , F_8 ( V_7 , V_15 ) & ~ V_19 , V_15 ) ;
break;
case 100 :
F_6 ( V_7 , F_8 ( V_7 , V_15 ) | V_19 , V_15 ) ;
break;
default:
break;
}
}
static void F_11 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
switch ( V_2 -> V_17 ) {
case 10 :
F_6 ( V_7 , 0 , V_20 ) ;
break;
case 100 :
F_6 ( V_7 , 1 , V_20 ) ;
break;
default:
break;
}
}
static void F_12 ( struct V_6 * V_7 )
{
int V_21 ;
T_1 V_22 [ 2 ] , V_23 [ 2 ] ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
V_23 [ V_21 ] = F_13 ( ( void * ) F_14 ( V_21 ) ) ;
V_22 [ V_21 ] = F_13 ( ( void * ) F_15 ( V_21 ) ) ;
}
F_16 ( V_24 , ( void * ) ( V_25 + 0x1800 ) ) ;
F_17 ( 1 ) ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
F_16 ( V_23 [ V_21 ] , ( void * ) F_14 ( V_21 ) ) ;
F_16 ( V_22 [ V_21 ] , ( void * ) F_15 ( V_21 ) ) ;
}
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
switch ( V_2 -> V_17 ) {
case 10 :
F_6 ( V_7 , 0x00000000 , V_26 ) ;
break;
case 100 :
F_6 ( V_7 , 0x00000010 , V_26 ) ;
break;
case 1000 :
F_6 ( V_7 , 0x00000020 , V_26 ) ;
break;
default:
break;
}
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_20 ( V_2 , V_24 , V_27 ) ;
F_17 ( 1 ) ;
}
static void F_21 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
switch ( V_2 -> V_17 ) {
case 10 :
F_6 ( V_7 , V_28 , V_26 ) ;
break;
case 100 :
F_6 ( V_7 , V_29 , V_26 ) ;
break;
case 1000 :
F_6 ( V_7 , V_30 , V_26 ) ;
break;
default:
break;
}
}
static void F_22 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_20 ( V_2 , V_24 , V_27 ) ;
F_17 ( 1 ) ;
F_3 ( V_7 ) ;
}
static void F_23 ( struct V_31 * V_32 )
{
if ( ! V_32 -> V_33 )
V_32 -> V_33 = V_34 ;
if ( ! V_32 -> V_35 )
V_32 -> V_35 = V_36 ;
if ( ! V_32 -> V_37 )
V_32 -> V_37 = V_38 |
V_39 ;
if ( ! V_32 -> V_40 )
V_32 -> V_40 = V_41 ;
if ( ! V_32 -> V_42 )
V_32 -> V_42 = V_43 ;
if ( ! V_32 -> V_44 )
V_32 -> V_44 = V_45 ;
if ( ! V_32 -> V_46 )
V_32 -> V_46 = V_47 ;
}
static int F_24 ( struct V_6 * V_7 )
{
int V_48 = 0 ;
int V_49 = 100 ;
while ( V_49 > 0 ) {
if ( ! ( F_8 ( V_7 , V_50 ) & 0x3 ) )
break;
F_17 ( 1 ) ;
V_49 -- ;
}
if ( V_49 <= 0 ) {
F_25 ( V_7 , L_2 ) ;
V_48 = - V_51 ;
}
return V_48 ;
}
static int F_26 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_48 = 0 ;
if ( F_1 ( V_2 ) || F_2 ( V_2 ) ) {
F_6 ( V_7 , V_52 , V_53 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_50 ) | V_54 ,
V_50 ) ;
V_48 = F_24 ( V_7 ) ;
if ( V_48 )
return V_48 ;
F_6 ( V_7 , 0x0 , V_55 ) ;
F_6 ( V_7 , 0x0 , V_56 ) ;
F_6 ( V_7 , 0x0 , V_57 ) ;
F_6 ( V_7 , 0x0 , V_58 ) ;
F_6 ( V_7 , 0x0 , V_59 ) ;
F_6 ( V_7 , 0x0 , V_60 ) ;
F_6 ( V_7 , 0x0 , V_61 ) ;
F_6 ( V_7 , 0x0 , V_62 ) ;
if ( V_2 -> V_32 -> V_63 )
F_6 ( V_7 , 0x0 , V_64 ) ;
if ( V_2 -> V_32 -> V_65 )
F_3 ( V_7 ) ;
} else {
F_6 ( V_7 , F_8 ( V_7 , V_50 ) | V_66 ,
V_50 ) ;
F_17 ( 3 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_50 ) & ~ V_66 ,
V_50 ) ;
}
return V_48 ;
}
static void F_27 ( struct V_67 * V_68 )
{
T_2 V_69 = ( T_2 ) V_68 -> V_70 & ( V_71 - 1 ) ;
if ( V_69 )
F_28 ( V_68 , V_71 - V_69 ) ;
}
static inline T_3 F_29 ( struct V_1 * V_2 , T_1 V_72 )
{
switch ( V_2 -> V_73 ) {
case V_74 :
return F_30 ( V_72 ) ;
case V_75 :
return F_31 ( V_72 ) ;
}
return V_72 ;
}
static inline T_3 F_32 ( struct V_1 * V_2 , T_1 V_72 )
{
switch ( V_2 -> V_73 ) {
case V_74 :
return F_33 ( V_72 ) ;
case V_75 :
return F_34 ( V_72 ) ;
}
return V_72 ;
}
static void F_35 ( struct V_6 * V_7 )
{
F_6 ( V_7 ,
( V_7 -> V_76 [ 0 ] << 24 ) | ( V_7 -> V_76 [ 1 ] << 16 ) |
( V_7 -> V_76 [ 2 ] << 8 ) | ( V_7 -> V_76 [ 3 ] ) , V_77 ) ;
F_6 ( V_7 ,
( V_7 -> V_76 [ 4 ] << 8 ) | ( V_7 -> V_76 [ 5 ] ) , V_78 ) ;
}
static void F_36 ( struct V_6 * V_7 , unsigned char * V_79 )
{
if ( V_79 [ 0 ] || V_79 [ 1 ] || V_79 [ 2 ] || V_79 [ 3 ] || V_79 [ 4 ] || V_79 [ 5 ] ) {
memcpy ( V_7 -> V_76 , V_79 , V_80 ) ;
} else {
V_7 -> V_76 [ 0 ] = ( F_8 ( V_7 , V_77 ) >> 24 ) ;
V_7 -> V_76 [ 1 ] = ( F_8 ( V_7 , V_77 ) >> 16 ) & 0xFF ;
V_7 -> V_76 [ 2 ] = ( F_8 ( V_7 , V_77 ) >> 8 ) & 0xFF ;
V_7 -> V_76 [ 3 ] = ( F_8 ( V_7 , V_77 ) & 0xFF ) ;
V_7 -> V_76 [ 4 ] = ( F_8 ( V_7 , V_78 ) >> 8 ) & 0xFF ;
V_7 -> V_76 [ 5 ] = ( F_8 ( V_7 , V_78 ) & 0xFF ) ;
}
}
static T_1 F_37 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) || F_2 ( V_2 ) )
return V_81 ;
else
return V_82 ;
}
static void F_38 ( void * V_83 , T_1 V_84 )
{
F_16 ( F_13 ( V_83 ) | V_84 , V_83 ) ;
}
static void F_39 ( void * V_83 , T_1 V_84 )
{
F_16 ( ( F_13 ( V_83 ) & ~ V_84 ) , V_83 ) ;
}
static int F_40 ( void * V_83 , T_1 V_84 )
{
return ( F_13 ( V_83 ) & V_84 ) != 0 ;
}
static void F_41 ( struct V_85 * V_86 , int V_87 )
{
struct V_88 * V_89 = F_42 ( V_86 , struct V_88 , V_86 ) ;
if ( V_89 -> V_90 )
V_89 -> V_90 ( V_89 -> V_83 ) ;
if ( V_87 )
F_38 ( V_89 -> V_83 , V_89 -> V_91 ) ;
else
F_39 ( V_89 -> V_83 , V_89 -> V_91 ) ;
}
static void F_43 ( struct V_85 * V_86 , int V_87 )
{
struct V_88 * V_89 = F_42 ( V_86 , struct V_88 , V_86 ) ;
if ( V_89 -> V_90 )
V_89 -> V_90 ( V_89 -> V_83 ) ;
if ( V_87 )
F_38 ( V_89 -> V_83 , V_89 -> V_92 ) ;
else
F_39 ( V_89 -> V_83 , V_89 -> V_92 ) ;
}
static int F_44 ( struct V_85 * V_86 )
{
struct V_88 * V_89 = F_42 ( V_86 , struct V_88 , V_86 ) ;
if ( V_89 -> V_90 )
V_89 -> V_90 ( V_89 -> V_83 ) ;
return F_40 ( V_89 -> V_83 , V_89 -> V_93 ) ;
}
static void F_45 ( struct V_85 * V_86 , int V_87 )
{
struct V_88 * V_89 = F_42 ( V_86 , struct V_88 , V_86 ) ;
if ( V_89 -> V_90 )
V_89 -> V_90 ( V_89 -> V_83 ) ;
if ( V_87 )
F_38 ( V_89 -> V_83 , V_89 -> V_94 ) ;
else
F_39 ( V_89 -> V_83 , V_89 -> V_94 ) ;
}
static void F_46 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 ;
if ( V_2 -> V_95 ) {
for ( V_21 = 0 ; V_21 < V_2 -> V_96 ; V_21 ++ )
F_47 ( V_2 -> V_95 [ V_21 ] ) ;
}
F_48 ( V_2 -> V_95 ) ;
V_2 -> V_95 = NULL ;
if ( V_2 -> V_97 ) {
for ( V_21 = 0 ; V_21 < V_2 -> V_98 ; V_21 ++ )
F_47 ( V_2 -> V_97 [ V_21 ] ) ;
}
F_48 ( V_2 -> V_97 ) ;
V_2 -> V_97 = NULL ;
}
static void F_49 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 ;
struct V_67 * V_68 ;
struct V_99 * V_100 = NULL ;
struct V_101 * V_102 = NULL ;
int V_103 = sizeof( * V_100 ) * V_2 -> V_96 ;
int V_104 = sizeof( * V_102 ) * V_2 -> V_98 ;
int V_105 = V_2 -> V_106 + V_71 - 1 ;
T_4 V_107 ;
V_2 -> V_108 = 0 ;
V_2 -> V_109 = 0 ;
V_2 -> V_110 = 0 ;
V_2 -> V_111 = 0 ;
memset ( V_2 -> V_112 , 0 , V_103 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_96 ; V_21 ++ ) {
V_2 -> V_95 [ V_21 ] = NULL ;
V_68 = F_50 ( V_7 , V_105 ) ;
if ( V_68 == NULL )
break;
F_27 ( V_68 ) ;
V_100 = & V_2 -> V_112 [ V_21 ] ;
V_100 -> V_113 = F_51 ( V_2 -> V_106 , 16 ) ;
V_107 = F_52 ( & V_7 -> V_114 , V_68 -> V_70 ,
V_100 -> V_113 ,
V_115 ) ;
if ( F_53 ( & V_7 -> V_114 , V_107 ) ) {
F_54 ( V_68 ) ;
break;
}
V_2 -> V_95 [ V_21 ] = V_68 ;
V_100 -> V_83 = V_107 ;
V_100 -> V_116 = F_29 ( V_2 , V_117 | V_118 ) ;
if ( V_21 == 0 ) {
F_6 ( V_7 , V_2 -> V_119 , V_59 ) ;
if ( F_1 ( V_2 ) ||
F_2 ( V_2 ) )
F_6 ( V_7 , V_2 -> V_119 , V_60 ) ;
}
}
V_2 -> V_110 = ( T_1 ) ( V_21 - V_2 -> V_96 ) ;
V_100 -> V_116 |= F_29 ( V_2 , V_120 ) ;
memset ( V_2 -> V_121 , 0 , V_104 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_98 ; V_21 ++ ) {
V_2 -> V_97 [ V_21 ] = NULL ;
V_102 = & V_2 -> V_121 [ V_21 ] ;
V_102 -> V_116 = F_29 ( V_2 , V_122 ) ;
V_102 -> V_113 = 0 ;
if ( V_21 == 0 ) {
F_6 ( V_7 , V_2 -> V_123 , V_55 ) ;
if ( F_1 ( V_2 ) ||
F_2 ( V_2 ) )
F_6 ( V_7 , V_2 -> V_123 , V_56 ) ;
}
}
V_102 -> V_116 |= F_29 ( V_2 , V_124 ) ;
}
static int F_55 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_103 , V_104 , V_48 = 0 ;
V_2 -> V_106 = ( V_7 -> V_125 <= 1492 ? V_126 :
( ( ( V_7 -> V_125 + 26 + 7 ) & ~ 7 ) + 2 + 16 ) ) ;
if ( V_2 -> V_32 -> V_127 )
V_2 -> V_106 += V_128 ;
V_2 -> V_95 = F_56 ( V_2 -> V_96 ,
sizeof( * V_2 -> V_95 ) , V_129 ) ;
if ( ! V_2 -> V_95 ) {
V_48 = - V_130 ;
return V_48 ;
}
V_2 -> V_97 = F_56 ( V_2 -> V_98 ,
sizeof( * V_2 -> V_97 ) , V_129 ) ;
if ( ! V_2 -> V_97 ) {
V_48 = - V_130 ;
goto V_131;
}
V_103 = sizeof( struct V_99 ) * V_2 -> V_96 ;
V_2 -> V_112 = F_57 ( NULL , V_103 , & V_2 -> V_119 ,
V_129 ) ;
if ( ! V_2 -> V_112 ) {
V_48 = - V_130 ;
goto V_132;
}
V_2 -> V_110 = 0 ;
V_104 = sizeof( struct V_101 ) * V_2 -> V_98 ;
V_2 -> V_121 = F_57 ( NULL , V_104 , & V_2 -> V_123 ,
V_129 ) ;
if ( ! V_2 -> V_121 ) {
V_48 = - V_130 ;
goto V_132;
}
return V_48 ;
V_132:
F_58 ( NULL , V_103 , V_2 -> V_112 , V_2 -> V_119 ) ;
V_131:
F_46 ( V_7 ) ;
V_2 -> V_121 = NULL ;
V_2 -> V_112 = NULL ;
return V_48 ;
}
static void F_59 ( struct V_1 * V_2 )
{
int V_133 ;
if ( V_2 -> V_112 ) {
V_133 = sizeof( struct V_99 ) * V_2 -> V_96 ;
F_58 ( NULL , V_133 , V_2 -> V_112 ,
V_2 -> V_119 ) ;
V_2 -> V_112 = NULL ;
}
if ( V_2 -> V_121 ) {
V_133 = sizeof( struct V_101 ) * V_2 -> V_98 ;
F_58 ( NULL , V_133 , V_2 -> V_121 ,
V_2 -> V_123 ) ;
V_2 -> V_121 = NULL ;
}
}
static int F_60 ( struct V_6 * V_7 , bool V_134 )
{
int V_48 = 0 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_135 ;
V_48 = F_26 ( V_7 ) ;
if ( V_48 )
return V_48 ;
if ( V_2 -> V_32 -> V_136 )
F_6 ( V_7 , 0x1 , V_137 ) ;
F_49 ( V_7 ) ;
if ( V_2 -> V_32 -> V_127 )
F_6 ( V_7 , V_2 -> V_32 -> V_138 , V_139 ) ;
F_6 ( V_7 , 0 , V_140 ) ;
#if F_61 ( V_141 )
if ( V_2 -> V_32 -> V_142 )
F_6 ( V_7 , V_143 , V_50 ) ;
else
#endif
F_6 ( V_7 , 0 , V_50 ) ;
F_6 ( V_7 , V_2 -> V_32 -> V_40 , V_144 ) ;
F_6 ( V_7 , 0 , V_145 ) ;
F_6 ( V_7 , V_146 , V_147 ) ;
F_6 ( V_7 , V_2 -> V_32 -> V_46 , V_148 ) ;
if ( V_2 -> V_32 -> V_149 )
F_6 ( V_7 , 0x800 , V_150 ) ;
F_6 ( V_7 , V_2 -> V_32 -> V_37 , V_151 ) ;
if ( ! V_2 -> V_32 -> V_152 )
F_6 ( V_7 , 0 , V_153 ) ;
F_6 ( V_7 , V_7 -> V_125 + V_154 + V_155 + V_156 ,
V_157 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_158 ) , V_158 ) ;
if ( V_134 ) {
V_2 -> V_159 = true ;
F_6 ( V_7 , V_2 -> V_32 -> V_160 , V_140 ) ;
}
V_135 = ( F_8 ( V_7 , V_15 ) & V_16 ) |
V_161 | ( V_2 -> V_14 ? V_16 : 0 ) | V_162 | V_163 ;
F_6 ( V_7 , V_135 , V_15 ) ;
if ( V_2 -> V_32 -> V_164 )
V_2 -> V_32 -> V_164 ( V_7 ) ;
F_6 ( V_7 , V_2 -> V_32 -> V_33 , V_165 ) ;
if ( V_134 )
F_6 ( V_7 , V_2 -> V_32 -> V_35 , V_166 ) ;
F_35 ( V_7 ) ;
if ( V_2 -> V_32 -> V_167 )
F_6 ( V_7 , V_168 , V_169 ) ;
if ( V_2 -> V_32 -> V_170 )
F_6 ( V_7 , V_171 , V_172 ) ;
if ( V_2 -> V_32 -> V_173 )
F_6 ( V_7 , V_174 , V_175 ) ;
if ( V_134 ) {
F_6 ( V_7 , V_176 , V_177 ) ;
F_62 ( V_7 ) ;
}
return V_48 ;
}
static void F_63 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_98 ; V_21 ++ )
V_2 -> V_121 [ V_21 ] . V_116 &= ~ F_29 ( V_2 , V_178 ) ;
F_64 ( V_7 ) ;
F_6 ( V_7 , 0 , V_177 ) ;
F_65 ( 2 ) ;
F_66 ( V_7 ) ;
F_26 ( V_7 ) ;
F_35 ( V_7 ) ;
}
static int F_67 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_101 * V_102 ;
int V_179 = 0 ;
int V_180 = 0 ;
for (; V_2 -> V_109 - V_2 -> V_111 > 0 ; V_2 -> V_111 ++ ) {
V_180 = V_2 -> V_111 % V_2 -> V_98 ;
V_102 = & V_2 -> V_121 [ V_180 ] ;
if ( V_102 -> V_116 & F_29 ( V_2 , V_178 ) )
break;
F_68 () ;
F_69 ( V_2 , V_181 , V_7 ,
L_3 ,
V_180 , F_32 ( V_2 , V_102 -> V_116 ) ) ;
if ( V_2 -> V_97 [ V_180 ] ) {
F_70 ( & V_7 -> V_114 , V_102 -> V_83 ,
V_102 -> V_113 , V_182 ) ;
F_71 ( V_2 -> V_97 [ V_180 ] ) ;
V_2 -> V_97 [ V_180 ] = NULL ;
V_179 ++ ;
}
V_102 -> V_116 = F_29 ( V_2 , V_122 ) ;
if ( V_180 >= V_2 -> V_98 - 1 )
V_102 -> V_116 |= F_29 ( V_2 , V_124 ) ;
V_7 -> V_183 . V_184 ++ ;
V_7 -> V_183 . V_185 += V_102 -> V_113 ;
}
return V_179 ;
}
static int F_72 ( struct V_6 * V_7 , T_1 V_186 , int * V_187 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_99 * V_100 ;
int V_180 = V_2 -> V_108 % V_2 -> V_96 ;
int V_188 = ( V_2 -> V_110 + V_2 -> V_96 ) - V_2 -> V_108 ;
int V_189 ;
struct V_67 * V_68 ;
T_5 V_190 = 0 ;
T_1 V_191 ;
int V_105 = V_2 -> V_106 + V_71 - 1 ;
T_4 V_107 ;
V_188 = F_73 ( V_188 , * V_187 ) ;
V_189 = V_188 ;
V_100 = & V_2 -> V_112 [ V_180 ] ;
while ( ! ( V_100 -> V_116 & F_29 ( V_2 , V_117 ) ) ) {
F_68 () ;
V_191 = F_32 ( V_2 , V_100 -> V_116 ) ;
V_190 = V_100 -> V_192 ;
if ( -- V_188 < 0 )
break;
F_69 ( V_2 , V_193 , V_7 ,
L_4 ,
V_180 , V_191 , V_190 ) ;
if ( ! ( V_191 & V_194 ) )
V_7 -> V_183 . V_195 ++ ;
if ( V_2 -> V_32 -> V_196 )
V_191 >>= 16 ;
if ( V_191 & ( V_197 | V_198 | V_199 | V_200 |
V_201 | V_202 | V_203 ) ) {
V_7 -> V_183 . V_204 ++ ;
if ( V_191 & V_197 )
V_7 -> V_183 . V_205 ++ ;
if ( V_191 & V_198 )
V_7 -> V_183 . V_206 ++ ;
if ( V_191 & V_199 )
V_7 -> V_183 . V_195 ++ ;
if ( V_191 & V_200 )
V_7 -> V_183 . V_195 ++ ;
if ( V_191 & V_202 )
V_7 -> V_183 . V_207 ++ ;
if ( V_191 & V_203 )
V_7 -> V_183 . V_208 ++ ;
} else {
if ( ! V_2 -> V_32 -> V_142 )
F_74 (
F_75 ( F_51 ( V_100 -> V_83 , 4 ) ) ,
V_190 + 2 ) ;
V_68 = V_2 -> V_95 [ V_180 ] ;
V_2 -> V_95 [ V_180 ] = NULL ;
if ( V_2 -> V_32 -> V_127 )
F_28 ( V_68 , V_128 ) ;
F_70 ( & V_7 -> V_114 , V_100 -> V_83 ,
F_51 ( V_2 -> V_106 , 16 ) ,
V_115 ) ;
F_76 ( V_68 , V_190 ) ;
V_68 -> V_209 = F_77 ( V_68 , V_7 ) ;
F_78 ( V_68 ) ;
V_7 -> V_183 . V_210 ++ ;
V_7 -> V_183 . V_211 += V_190 ;
if ( V_191 & V_212 )
V_7 -> V_183 . V_213 ++ ;
}
V_180 = ( ++ V_2 -> V_108 ) % V_2 -> V_96 ;
V_100 = & V_2 -> V_112 [ V_180 ] ;
}
for (; V_2 -> V_108 - V_2 -> V_110 > 0 ; V_2 -> V_110 ++ ) {
V_180 = V_2 -> V_110 % V_2 -> V_96 ;
V_100 = & V_2 -> V_112 [ V_180 ] ;
V_100 -> V_113 = F_51 ( V_2 -> V_106 , 16 ) ;
if ( V_2 -> V_95 [ V_180 ] == NULL ) {
V_68 = F_50 ( V_7 , V_105 ) ;
if ( V_68 == NULL )
break;
F_27 ( V_68 ) ;
V_107 = F_52 ( & V_7 -> V_114 , V_68 -> V_70 ,
V_100 -> V_113 ,
V_115 ) ;
if ( F_53 ( & V_7 -> V_114 , V_107 ) ) {
F_54 ( V_68 ) ;
break;
}
V_2 -> V_95 [ V_180 ] = V_68 ;
F_79 ( V_68 ) ;
V_100 -> V_83 = V_107 ;
}
F_80 () ;
if ( V_180 >= V_2 -> V_96 - 1 )
V_100 -> V_116 |=
F_29 ( V_2 , V_117 | V_118 | V_120 ) ;
else
V_100 -> V_116 |=
F_29 ( V_2 , V_117 | V_118 ) ;
}
if ( ! ( F_8 ( V_7 , V_177 ) & V_176 ) ) {
if ( V_186 & V_214 &&
V_2 -> V_3 [ V_60 ] != V_215 ) {
T_1 V_216 = ( F_8 ( V_7 , V_60 ) -
F_8 ( V_7 , V_59 ) ) >> 4 ;
V_2 -> V_108 = V_216 ;
V_2 -> V_110 = V_216 ;
}
F_6 ( V_7 , V_176 , V_177 ) ;
}
* V_187 -= V_189 - V_188 - 1 ;
return * V_187 <= 0 ;
}
static void F_64 ( struct V_6 * V_7 )
{
F_6 ( V_7 , F_8 ( V_7 , V_15 ) &
~ ( V_163 | V_162 ) , V_15 ) ;
}
static void F_81 ( struct V_6 * V_7 )
{
F_6 ( V_7 , F_8 ( V_7 , V_15 ) |
( V_163 | V_162 ) , V_15 ) ;
}
static void F_82 ( struct V_6 * V_7 , T_1 V_186 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_217 ;
T_1 V_218 ;
T_1 V_219 ;
if ( V_186 & V_220 ) {
V_217 = F_8 ( V_7 , V_165 ) ;
F_6 ( V_7 , V_217 , V_165 ) ;
if ( V_217 & V_221 )
V_7 -> V_183 . V_222 ++ ;
if ( V_217 & V_223 ) {
if ( V_2 -> V_32 -> V_224 || V_2 -> V_225 ) {
goto V_226;
} else {
V_218 = ( F_8 ( V_7 , V_227 ) ) ;
if ( V_2 -> V_228 )
V_218 = ~ V_218 ;
}
if ( ! ( V_218 & V_229 ) ) {
F_64 ( V_7 ) ;
} else {
F_6 ( V_7 , F_8 ( V_7 , V_140 ) &
~ V_230 , V_140 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_165 ) ,
V_165 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_140 ) |
V_230 , V_140 ) ;
F_81 ( V_7 ) ;
}
}
}
V_226:
if ( V_186 & V_231 ) {
if ( V_186 & V_232 ) {
V_7 -> V_183 . V_233 ++ ;
F_83 ( V_2 , V_234 , V_7 , L_5 ) ;
}
}
if ( V_186 & V_235 ) {
if ( V_186 & V_236 ) {
V_7 -> V_183 . V_206 ++ ;
}
}
if ( V_186 & V_237 ) {
V_7 -> V_183 . V_238 ++ ;
F_83 ( V_2 , V_234 , V_7 , L_6 ) ;
}
if ( V_186 & V_239 ) {
V_7 -> V_183 . V_238 ++ ;
F_83 ( V_2 , V_234 , V_7 , L_7 ) ;
}
if ( V_186 & V_214 ) {
V_7 -> V_183 . V_208 ++ ;
}
if ( V_186 & V_240 ) {
V_7 -> V_183 . V_241 ++ ;
}
if ( ! V_2 -> V_32 -> V_242 && ( V_186 & V_243 ) ) {
V_7 -> V_183 . V_238 ++ ;
F_83 ( V_2 , V_234 , V_7 , L_8 ) ;
}
V_219 = V_231 | V_232 | V_243 | V_237 | V_239 ;
if ( V_2 -> V_32 -> V_242 )
V_219 &= ~ V_243 ;
if ( V_186 & V_219 ) {
T_1 V_244 = F_8 ( V_7 , V_245 ) ;
F_25 ( V_7 , L_9 ,
V_186 , V_2 -> V_109 , V_2 -> V_111 ,
( T_1 ) V_7 -> V_246 , V_244 ) ;
F_67 ( V_7 ) ;
if ( V_244 ^ F_37 ( V_2 ) ) {
F_6 ( V_7 , F_37 ( V_2 ) , V_245 ) ;
}
F_84 ( V_7 ) ;
}
}
static T_6 F_85 ( int V_247 , void * V_248 )
{
struct V_6 * V_7 = V_248 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_31 * V_32 = V_2 -> V_32 ;
T_6 V_48 = V_249 ;
T_1 V_186 , V_250 ;
F_86 ( & V_2 -> V_251 ) ;
V_186 = F_8 ( V_7 , V_158 ) ;
V_250 = F_8 ( V_7 , V_140 ) ;
V_186 &= V_250 | V_230 ;
if ( V_186 & ( V_252 | V_32 -> V_42 | V_32 -> V_44 ) )
V_48 = V_253 ;
else
goto V_254;
if ( ! F_87 ( V_2 -> V_159 ) ) {
F_6 ( V_7 , 0 , V_140 ) ;
goto V_254;
}
if ( V_186 & V_252 ) {
if ( F_88 ( & V_2 -> V_255 ) ) {
F_6 ( V_7 , V_250 & ~ V_252 ,
V_140 ) ;
F_89 ( & V_2 -> V_255 ) ;
} else {
F_5 ( V_7 ,
L_10 ,
V_186 , V_250 ) ;
}
}
if ( V_186 & V_32 -> V_42 ) {
F_6 ( V_7 , V_186 & V_32 -> V_42 , V_158 ) ;
F_67 ( V_7 ) ;
F_84 ( V_7 ) ;
}
if ( V_186 & V_32 -> V_44 ) {
F_6 ( V_7 , V_186 & V_32 -> V_44 , V_158 ) ;
F_82 ( V_7 , V_186 ) ;
}
V_254:
F_90 ( & V_2 -> V_251 ) ;
return V_48 ;
}
static int F_91 ( struct V_256 * V_255 , int V_257 )
{
struct V_1 * V_2 = F_42 ( V_255 , struct V_1 ,
V_255 ) ;
struct V_6 * V_7 = V_255 -> V_114 ;
int V_187 = V_257 ;
T_1 V_186 ;
for (; ; ) {
V_186 = F_8 ( V_7 , V_158 ) ;
if ( ! ( V_186 & V_252 ) )
break;
F_6 ( V_7 , V_186 & V_252 , V_158 ) ;
if ( F_72 ( V_7 , V_186 , & V_187 ) )
goto V_254;
}
F_92 ( V_255 ) ;
if ( V_2 -> V_159 )
F_6 ( V_7 , V_2 -> V_32 -> V_160 , V_140 ) ;
V_254:
return V_257 - V_187 ;
}
static void F_93 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_258 * V_259 = V_2 -> V_259 ;
int V_260 = 0 ;
if ( V_259 -> V_261 ) {
if ( V_259 -> V_14 != V_2 -> V_14 ) {
V_260 = 1 ;
V_2 -> V_14 = V_259 -> V_14 ;
if ( V_2 -> V_32 -> V_262 )
V_2 -> V_32 -> V_262 ( V_7 ) ;
}
if ( V_259 -> V_17 != V_2 -> V_17 ) {
V_260 = 1 ;
V_2 -> V_17 = V_259 -> V_17 ;
if ( V_2 -> V_32 -> V_164 )
V_2 -> V_32 -> V_164 ( V_7 ) ;
}
if ( ! V_2 -> V_261 ) {
F_6 ( V_7 ,
F_8 ( V_7 , V_15 ) & ~ V_263 ,
V_15 ) ;
V_260 = 1 ;
V_2 -> V_261 = V_259 -> V_261 ;
if ( V_2 -> V_32 -> V_224 || V_2 -> V_225 )
F_81 ( V_7 ) ;
}
} else if ( V_2 -> V_261 ) {
V_260 = 1 ;
V_2 -> V_261 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_14 = - 1 ;
if ( V_2 -> V_32 -> V_224 || V_2 -> V_225 )
F_64 ( V_7 ) ;
}
if ( V_260 && F_94 ( V_2 ) )
F_95 ( V_259 ) ;
}
static int F_96 ( struct V_6 * V_7 )
{
struct V_264 * V_265 = V_7 -> V_114 . V_266 -> V_267 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_258 * V_259 = NULL ;
V_2 -> V_261 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_14 = - 1 ;
if ( V_265 ) {
struct V_264 * V_268 ;
V_268 = F_97 ( V_265 , L_11 , 0 ) ;
V_259 = F_98 ( V_7 , V_268 ,
F_93 , 0 ,
V_2 -> V_9 ) ;
if ( ! V_259 )
V_259 = F_99 ( - V_269 ) ;
} else {
char V_270 [ V_271 + 3 ] ;
snprintf ( V_270 , sizeof( V_270 ) , V_272 ,
V_2 -> V_273 -> V_274 , V_2 -> V_270 ) ;
V_259 = F_100 ( V_7 , V_270 , F_93 ,
V_2 -> V_9 ) ;
}
if ( F_101 ( V_259 ) ) {
F_25 ( V_7 , L_12 ) ;
return F_102 ( V_259 ) ;
}
F_103 ( V_7 , L_13 ,
V_259 -> V_83 , V_259 -> V_247 , V_259 -> V_275 -> V_276 ) ;
V_2 -> V_259 = V_259 ;
return 0 ;
}
static int F_104 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_48 ;
V_48 = F_96 ( V_7 ) ;
if ( V_48 )
return V_48 ;
F_105 ( V_2 -> V_259 ) ;
return 0 ;
}
static int F_106 ( struct V_6 * V_7 ,
struct V_277 * V_278 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
unsigned long V_279 ;
int V_48 ;
if ( ! V_2 -> V_259 )
return - V_280 ;
F_107 ( & V_2 -> V_251 , V_279 ) ;
V_48 = F_108 ( V_2 -> V_259 , V_278 ) ;
F_109 ( & V_2 -> V_251 , V_279 ) ;
return V_48 ;
}
static int F_110 ( struct V_6 * V_7 ,
struct V_277 * V_278 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
unsigned long V_279 ;
int V_48 ;
if ( ! V_2 -> V_259 )
return - V_280 ;
F_107 ( & V_2 -> V_251 , V_279 ) ;
F_64 ( V_7 ) ;
V_48 = F_111 ( V_2 -> V_259 , V_278 ) ;
if ( V_48 )
goto V_281;
if ( V_278 -> V_14 == V_282 )
V_2 -> V_14 = 1 ;
else
V_2 -> V_14 = 0 ;
if ( V_2 -> V_32 -> V_262 )
V_2 -> V_32 -> V_262 ( V_7 ) ;
V_281:
F_17 ( 1 ) ;
F_81 ( V_7 ) ;
F_109 ( & V_2 -> V_251 , V_279 ) ;
return V_48 ;
}
static T_7 F_112 ( struct V_6 * V_7 , T_1 * V_283 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_31 * V_32 = V_2 -> V_32 ;
T_1 * V_284 ;
T_7 V_285 ;
F_113 ( V_286 > V_287 ) ;
V_285 = F_114 ( V_287 , 32 ) ;
if ( V_283 ) {
V_284 = V_283 ;
V_283 += V_285 ;
} else {
V_284 = NULL ;
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
F_117 ( V_53 ) ;
F_117 ( V_50 ) ;
F_117 ( V_245 ) ;
F_117 ( V_177 ) ;
F_117 ( V_158 ) ;
F_117 ( V_140 ) ;
F_117 ( V_55 ) ;
F_117 ( V_56 ) ;
F_117 ( V_57 ) ;
F_117 ( V_58 ) ;
F_117 ( V_59 ) ;
F_117 ( V_60 ) ;
F_117 ( V_61 ) ;
F_117 ( V_62 ) ;
F_117 ( V_148 ) ;
F_117 ( V_288 ) ;
F_117 ( V_145 ) ;
F_117 ( V_144 ) ;
F_117 ( V_147 ) ;
F_117 ( V_289 ) ;
F_117 ( V_290 ) ;
if ( V_32 -> V_136 )
F_117 ( V_137 ) ;
F_117 ( V_151 ) ;
if ( V_32 -> V_127 )
F_117 ( V_139 ) ;
if ( ! V_32 -> V_152 )
F_117 ( V_153 ) ;
F_117 ( V_15 ) ;
F_117 ( V_165 ) ;
F_117 ( V_166 ) ;
F_117 ( V_291 ) ;
if ( ! V_32 -> V_224 )
F_117 ( V_227 ) ;
F_117 ( V_292 ) ;
F_117 ( V_157 ) ;
F_117 ( V_293 ) ;
if ( V_32 -> V_167 )
F_117 ( V_169 ) ;
if ( V_32 -> V_170 )
F_117 ( V_172 ) ;
F_117 ( V_294 ) ;
F_117 ( V_295 ) ;
if ( V_32 -> V_173 )
F_117 ( V_175 ) ;
F_117 ( V_296 ) ;
F_117 ( V_26 ) ;
if ( V_32 -> V_149 )
F_117 ( V_150 ) ;
F_117 ( V_77 ) ;
F_117 ( V_78 ) ;
F_117 ( V_297 ) ;
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
if ( V_32 -> V_308 )
F_117 ( V_20 ) ;
if ( V_32 -> V_63 )
F_117 ( V_64 ) ;
if ( V_32 -> V_65 )
F_117 ( V_13 ) ;
F_117 ( V_27 ) ;
if ( V_32 -> V_309 ) {
F_118 ( V_310 ) ;
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
if ( V_2 -> V_3 [ V_337 ] != V_215 ) {
if ( V_283 ) {
unsigned int V_21 ;
F_115 ( V_337 ) ;
for ( V_21 = 0 ; V_21 < V_338 * 2 ; V_21 ++ )
* V_283 ++ = F_13 (
V_2 -> V_339 +
V_2 -> V_3 [ V_337 ] +
V_21 * 4 ) ;
}
V_285 += V_338 * 2 ;
}
}
#undef F_115
#undef F_116
#undef F_117
#undef F_118
return V_285 * 4 ;
}
static int F_119 ( struct V_6 * V_7 )
{
return F_112 ( V_7 , NULL ) ;
}
static void F_120 ( struct V_6 * V_7 , struct V_340 * V_341 ,
void * V_283 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
V_341 -> V_342 = V_343 ;
F_121 ( & V_2 -> V_344 -> V_114 ) ;
F_112 ( V_7 , V_283 ) ;
F_122 ( & V_2 -> V_344 -> V_114 ) ;
}
static int F_123 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
unsigned long V_279 ;
int V_48 ;
if ( ! V_2 -> V_259 )
return - V_280 ;
F_107 ( & V_2 -> V_251 , V_279 ) ;
V_48 = F_124 ( V_2 -> V_259 ) ;
F_109 ( & V_2 -> V_251 , V_279 ) ;
return V_48 ;
}
static T_1 F_125 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
return V_2 -> V_345 ;
}
static void F_126 ( struct V_6 * V_7 , T_1 V_8 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
V_2 -> V_345 = V_8 ;
}
static int F_127 ( struct V_6 * V_248 , int V_346 )
{
switch ( V_346 ) {
case V_347 :
return V_348 ;
default:
return - V_349 ;
}
}
static void F_128 ( struct V_6 * V_7 ,
struct V_350 * V_183 , T_10 * V_70 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 = 0 ;
V_70 [ V_21 ++ ] = V_2 -> V_108 ;
V_70 [ V_21 ++ ] = V_2 -> V_109 ;
V_70 [ V_21 ++ ] = V_2 -> V_110 ;
V_70 [ V_21 ++ ] = V_2 -> V_111 ;
}
static void F_129 ( struct V_6 * V_7 , T_1 V_351 , T_11 * V_70 )
{
switch ( V_351 ) {
case V_347 :
memcpy ( V_70 , * V_352 ,
sizeof( V_352 ) ) ;
break;
}
}
static void F_130 ( struct V_6 * V_7 ,
struct V_353 * V_354 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
V_354 -> V_355 = V_356 ;
V_354 -> V_357 = V_358 ;
V_354 -> V_359 = V_2 -> V_96 ;
V_354 -> V_360 = V_2 -> V_98 ;
}
static int F_131 ( struct V_6 * V_7 ,
struct V_353 * V_354 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_48 ;
if ( V_354 -> V_360 > V_358 ||
V_354 -> V_359 > V_356 ||
V_354 -> V_360 < V_361 ||
V_354 -> V_359 < V_362 )
return - V_363 ;
if ( V_354 -> V_364 || V_354 -> V_365 )
return - V_363 ;
if ( F_132 ( V_7 ) ) {
F_133 ( V_7 ) ;
F_134 ( V_7 ) ;
V_2 -> V_159 = false ;
F_135 ( V_7 -> V_247 ) ;
F_136 ( & V_2 -> V_255 ) ;
F_6 ( V_7 , 0x0000 , V_140 ) ;
F_63 ( V_7 ) ;
F_46 ( V_7 ) ;
F_59 ( V_2 ) ;
}
V_2 -> V_96 = V_354 -> V_359 ;
V_2 -> V_98 = V_354 -> V_360 ;
if ( F_132 ( V_7 ) ) {
V_48 = F_55 ( V_7 ) ;
if ( V_48 < 0 ) {
F_25 ( V_7 , L_14 ,
V_366 ) ;
return V_48 ;
}
V_48 = F_60 ( V_7 , false ) ;
if ( V_48 < 0 ) {
F_25 ( V_7 , L_15 ,
V_366 ) ;
return V_48 ;
}
V_2 -> V_159 = true ;
F_6 ( V_7 , V_2 -> V_32 -> V_160 , V_140 ) ;
F_6 ( V_7 , V_176 , V_177 ) ;
F_137 ( V_7 ) ;
}
return 0 ;
}
static int F_138 ( struct V_6 * V_7 )
{
int V_48 = 0 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_121 ( & V_2 -> V_344 -> V_114 ) ;
F_139 ( & V_2 -> V_255 ) ;
V_48 = F_140 ( V_7 -> V_247 , F_85 ,
V_2 -> V_32 -> V_367 , V_7 -> V_276 , V_7 ) ;
if ( V_48 ) {
F_25 ( V_7 , L_16 ) ;
goto V_368;
}
V_48 = F_55 ( V_7 ) ;
if ( V_48 )
goto V_369;
V_48 = F_60 ( V_7 , true ) ;
if ( V_48 )
goto V_369;
V_48 = F_104 ( V_7 ) ;
if ( V_48 )
goto V_369;
V_2 -> V_370 = 1 ;
return V_48 ;
V_369:
F_141 ( V_7 -> V_247 , V_7 ) ;
V_368:
F_142 ( & V_2 -> V_255 ) ;
F_122 ( & V_2 -> V_344 -> V_114 ) ;
return V_48 ;
}
static void F_143 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_99 * V_100 ;
int V_21 ;
F_144 ( V_7 ) ;
F_83 ( V_2 , V_371 , V_7 ,
L_17 ,
F_8 ( V_7 , V_158 ) ) ;
V_7 -> V_183 . V_372 ++ ;
for ( V_21 = 0 ; V_21 < V_2 -> V_96 ; V_21 ++ ) {
V_100 = & V_2 -> V_112 [ V_21 ] ;
V_100 -> V_116 = 0 ;
V_100 -> V_83 = 0xBADF00D0 ;
F_47 ( V_2 -> V_95 [ V_21 ] ) ;
V_2 -> V_95 [ V_21 ] = NULL ;
}
for ( V_21 = 0 ; V_21 < V_2 -> V_98 ; V_21 ++ ) {
F_47 ( V_2 -> V_97 [ V_21 ] ) ;
V_2 -> V_97 [ V_21 ] = NULL ;
}
F_60 ( V_7 , true ) ;
}
static int F_145 ( struct V_67 * V_68 , struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_101 * V_102 ;
T_1 V_180 ;
unsigned long V_279 ;
F_107 ( & V_2 -> V_251 , V_279 ) ;
if ( ( V_2 -> V_109 - V_2 -> V_111 ) >= ( V_2 -> V_98 - 4 ) ) {
if ( ! F_67 ( V_7 ) ) {
F_146 ( V_2 , V_373 , V_7 , L_18 ) ;
F_144 ( V_7 ) ;
F_109 ( & V_2 -> V_251 , V_279 ) ;
return V_374 ;
}
}
F_109 ( & V_2 -> V_251 , V_279 ) ;
if ( F_147 ( V_68 , V_375 ) )
return V_376 ;
V_180 = V_2 -> V_109 % V_2 -> V_98 ;
V_2 -> V_97 [ V_180 ] = V_68 ;
V_102 = & V_2 -> V_121 [ V_180 ] ;
if ( ! V_2 -> V_32 -> V_142 )
F_74 ( F_75 ( F_51 ( V_102 -> V_83 , 4 ) ) ,
V_68 -> V_285 + 2 ) ;
V_102 -> V_83 = F_52 ( & V_7 -> V_114 , V_68 -> V_70 , V_68 -> V_285 ,
V_182 ) ;
if ( F_53 ( & V_7 -> V_114 , V_102 -> V_83 ) ) {
F_54 ( V_68 ) ;
return V_376 ;
}
V_102 -> V_113 = V_68 -> V_285 ;
F_80 () ;
if ( V_180 >= V_2 -> V_98 - 1 )
V_102 -> V_116 |= F_29 ( V_2 , V_178 | V_124 ) ;
else
V_102 -> V_116 |= F_29 ( V_2 , V_178 ) ;
V_2 -> V_109 ++ ;
if ( ! ( F_8 ( V_7 , V_245 ) & F_37 ( V_2 ) ) )
F_6 ( V_7 , F_37 ( V_2 ) , V_245 ) ;
return V_376 ;
}
static void
F_148 ( struct V_6 * V_7 , unsigned long * V_377 , int T_8 )
{
T_1 V_378 = F_8 ( V_7 , T_8 ) ;
if ( V_378 ) {
* V_377 += V_378 ;
F_6 ( V_7 , 0 , T_8 ) ;
}
}
static struct V_379 * F_66 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
if ( F_2 ( V_2 ) )
return & V_7 -> V_183 ;
if ( ! V_2 -> V_370 )
return & V_7 -> V_183 ;
F_148 ( V_7 , & V_7 -> V_183 . V_380 , V_297 ) ;
F_148 ( V_7 , & V_7 -> V_183 . V_381 , V_298 ) ;
F_148 ( V_7 , & V_7 -> V_183 . V_222 , V_299 ) ;
if ( F_1 ( V_2 ) ) {
F_148 ( V_7 , & V_7 -> V_183 . V_222 ,
V_305 ) ;
F_148 ( V_7 , & V_7 -> V_183 . V_222 ,
V_306 ) ;
} else {
F_148 ( V_7 , & V_7 -> V_183 . V_222 ,
V_300 ) ;
}
return & V_7 -> V_183 ;
}
static int F_149 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_144 ( V_7 ) ;
V_2 -> V_159 = false ;
F_135 ( V_7 -> V_247 ) ;
F_142 ( & V_2 -> V_255 ) ;
F_6 ( V_7 , 0x0000 , V_140 ) ;
F_63 ( V_7 ) ;
if ( V_2 -> V_259 ) {
F_150 ( V_2 -> V_259 ) ;
F_151 ( V_2 -> V_259 ) ;
V_2 -> V_259 = NULL ;
}
F_141 ( V_7 -> V_247 , V_7 ) ;
F_46 ( V_7 ) ;
F_59 ( V_2 ) ;
F_122 ( & V_2 -> V_344 -> V_114 ) ;
V_2 -> V_370 = 0 ;
return 0 ;
}
static int F_152 ( struct V_6 * V_7 , struct V_382 * V_383 , int V_384 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_258 * V_259 = V_2 -> V_259 ;
if ( ! F_132 ( V_7 ) )
return - V_363 ;
if ( ! V_259 )
return - V_280 ;
return F_153 ( V_259 , V_383 , V_384 ) ;
}
static void * F_154 ( struct V_1 * V_2 ,
int V_180 )
{
return F_155 ( V_2 , V_333 ) + ( V_180 / 8 * 4 ) ;
}
static T_1 F_156 ( int V_180 )
{
return 0x0f << ( 28 - ( ( V_180 % 8 ) * 4 ) ) ;
}
static T_1 F_157 ( struct V_1 * V_2 , int V_180 )
{
return ( 0x08 >> ( V_2 -> V_385 << 1 ) ) << ( 28 - ( ( V_180 % 8 ) * 4 ) ) ;
}
static void F_158 ( struct V_6 * V_7 ,
int V_180 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_386 ;
void * V_3 ;
V_3 = F_154 ( V_2 , V_180 ) ;
V_386 = F_13 ( V_3 ) ;
F_16 ( V_386 | F_157 ( V_2 , V_180 ) , V_3 ) ;
}
static bool F_159 ( struct V_6 * V_7 ,
int V_180 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_387 , V_388 , V_386 ;
void * V_3 ;
V_3 = F_154 ( V_2 , V_180 ) ;
V_387 = F_156 ( V_180 ) ;
V_388 = F_157 ( V_2 , V_180 ) & ~ V_387 ;
V_386 = F_13 ( V_3 ) ;
F_16 ( V_386 & ~ V_387 , V_3 ) ;
return V_386 & V_388 ;
}
static int F_160 ( struct V_6 * V_7 )
{
int V_389 = V_390 * 100 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
while ( ( F_161 ( V_2 , V_331 ) & V_391 ) ) {
F_162 ( 10 ) ;
V_389 -- ;
if ( V_389 <= 0 ) {
F_25 ( V_7 , L_19 , V_366 ) ;
return - V_51 ;
}
}
return 0 ;
}
static int F_163 ( struct V_6 * V_7 , void * T_8 ,
const T_11 * V_83 )
{
T_1 V_135 ;
V_135 = V_83 [ 0 ] << 24 | V_83 [ 1 ] << 16 | V_83 [ 2 ] << 8 | V_83 [ 3 ] ;
F_16 ( V_135 , T_8 ) ;
if ( F_160 ( V_7 ) < 0 )
return - V_392 ;
V_135 = V_83 [ 4 ] << 8 | V_83 [ 5 ] ;
F_16 ( V_135 , T_8 + 4 ) ;
if ( F_160 ( V_7 ) < 0 )
return - V_392 ;
return 0 ;
}
static void F_164 ( void * T_8 , T_11 * V_83 )
{
T_1 V_135 ;
V_135 = F_13 ( T_8 ) ;
V_83 [ 0 ] = ( V_135 >> 24 ) & 0xff ;
V_83 [ 1 ] = ( V_135 >> 16 ) & 0xff ;
V_83 [ 2 ] = ( V_135 >> 8 ) & 0xff ;
V_83 [ 3 ] = V_135 & 0xff ;
V_135 = F_13 ( T_8 + 4 ) ;
V_83 [ 4 ] = ( V_135 >> 8 ) & 0xff ;
V_83 [ 5 ] = V_135 & 0xff ;
}
static int F_165 ( struct V_6 * V_7 , const T_11 * V_83 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
void * V_3 = F_155 ( V_2 , V_337 ) ;
int V_21 ;
T_11 V_393 [ V_80 ] ;
for ( V_21 = 0 ; V_21 < V_338 ; V_21 ++ , V_3 += 8 ) {
F_164 ( V_3 , V_393 ) ;
if ( F_166 ( V_83 , V_393 ) )
return V_21 ;
}
return - V_269 ;
}
static int F_167 ( struct V_6 * V_7 )
{
T_11 V_394 [ V_80 ] ;
int V_180 ;
memset ( V_394 , 0 , sizeof( V_394 ) ) ;
V_180 = F_165 ( V_7 , V_394 ) ;
return ( V_180 < 0 ) ? - V_130 : V_180 ;
}
static int F_168 ( struct V_6 * V_7 ,
int V_180 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
void * V_3 = F_155 ( V_2 , V_337 ) ;
int V_48 ;
T_11 V_394 [ V_80 ] ;
F_20 ( V_2 , F_161 ( V_2 , V_332 ) &
~ ( 1 << ( 31 - V_180 ) ) , V_332 ) ;
memset ( V_394 , 0 , sizeof( V_394 ) ) ;
V_48 = F_163 ( V_7 , V_3 + V_180 * 8 , V_394 ) ;
if ( V_48 < 0 )
return V_48 ;
return 0 ;
}
static int F_169 ( struct V_6 * V_7 , const T_11 * V_83 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
void * V_3 = F_155 ( V_2 , V_337 ) ;
int V_21 , V_48 ;
if ( ! V_2 -> V_32 -> V_309 )
return 0 ;
V_21 = F_165 ( V_7 , V_83 ) ;
if ( V_21 < 0 ) {
V_21 = F_167 ( V_7 ) ;
if ( V_21 < 0 )
return - V_130 ;
V_48 = F_163 ( V_7 , V_3 + V_21 * 8 , V_83 ) ;
if ( V_48 < 0 )
return V_48 ;
F_20 ( V_2 , F_161 ( V_2 , V_332 ) |
( 1 << ( 31 - V_21 ) ) , V_332 ) ;
}
F_158 ( V_7 , V_21 ) ;
return 0 ;
}
static int F_170 ( struct V_6 * V_7 , const T_11 * V_83 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 , V_48 ;
if ( ! V_2 -> V_32 -> V_309 )
return 0 ;
V_21 = F_165 ( V_7 , V_83 ) ;
if ( V_21 ) {
if ( F_159 ( V_7 , V_21 ) )
goto V_395;
V_48 = F_168 ( V_7 , V_21 ) ;
if ( V_48 < 0 )
return V_48 ;
}
V_395:
return 0 ;
}
static int F_171 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 , V_48 ;
if ( ! V_2 -> V_32 -> V_309 )
return 0 ;
for ( V_21 = 0 ; V_21 < V_338 ; V_21 ++ ) {
if ( F_159 ( V_7 , V_21 ) )
continue;
V_48 = F_168 ( V_7 , V_21 ) ;
if ( V_48 < 0 )
return V_48 ;
}
return 0 ;
}
static void F_172 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_11 V_83 [ V_80 ] ;
void * V_3 = F_155 ( V_2 , V_337 ) ;
int V_21 ;
if ( ! V_2 -> V_32 -> V_309 )
return;
for ( V_21 = 0 ; V_21 < V_338 ; V_21 ++ , V_3 += 8 ) {
F_164 ( V_3 , V_83 ) ;
if ( F_173 ( V_83 ) )
F_170 ( V_7 , V_83 ) ;
}
}
static void F_174 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_396 ;
int V_397 = 0 ;
unsigned long V_279 ;
F_107 ( & V_2 -> V_251 , V_279 ) ;
V_396 = F_8 ( V_7 , V_15 ) & ~ V_398 ;
if ( V_2 -> V_32 -> V_309 )
V_396 |= V_399 ;
if ( ! ( V_7 -> V_279 & V_400 ) ) {
F_172 ( V_7 ) ;
V_397 = 1 ;
}
if ( V_7 -> V_279 & V_401 ) {
F_172 ( V_7 ) ;
V_396 &= ~ V_399 ;
V_397 = 1 ;
}
if ( V_7 -> V_279 & V_402 ) {
F_171 ( V_7 ) ;
V_396 = ( V_396 & ~ V_399 ) | V_398 ;
} else if ( V_2 -> V_32 -> V_309 ) {
struct V_403 * V_404 ;
F_175 (ha, ndev) {
if ( V_397 && F_173 ( V_404 -> V_83 ) )
continue;
if ( F_169 ( V_7 , V_404 -> V_83 ) < 0 ) {
if ( ! V_397 ) {
F_172 ( V_7 ) ;
V_396 &= ~ V_399 ;
V_397 = 1 ;
}
}
}
}
F_6 ( V_7 , V_396 , V_15 ) ;
F_109 ( & V_2 -> V_251 , V_279 ) ;
}
static int F_176 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_385 )
return V_329 ;
else
return V_330 ;
}
static int F_177 ( struct V_6 * V_7 ,
T_12 V_405 , T_5 V_406 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_407 = F_176 ( V_2 ) ;
if ( F_178 ( ! V_2 -> V_32 -> V_309 ) )
return - V_408 ;
if ( ! V_406 )
return 0 ;
V_2 -> V_409 ++ ;
if ( V_2 -> V_409 > 1 ) {
F_20 ( V_2 , 0 , V_407 ) ;
return 0 ;
}
F_20 ( V_2 , V_410 | ( V_406 & V_411 ) ,
V_407 ) ;
return 0 ;
}
static int F_179 ( struct V_6 * V_7 ,
T_12 V_405 , T_5 V_406 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_407 = F_176 ( V_2 ) ;
if ( F_178 ( ! V_2 -> V_32 -> V_309 ) )
return - V_408 ;
if ( ! V_406 )
return 0 ;
V_2 -> V_409 -- ;
F_20 ( V_2 , 0 , V_407 ) ;
return 0 ;
}
static void F_180 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
F_20 ( V_2 , 0 , V_332 ) ;
return;
}
F_20 ( V_2 , 0 , V_311 ) ;
F_20 ( V_2 , 0 , V_312 ) ;
F_20 ( V_2 , 0 , V_313 ) ;
F_20 ( V_2 , 0xc , V_314 ) ;
F_20 ( V_2 , 0xc , V_315 ) ;
F_20 ( V_2 , 0 , V_316 ) ;
F_20 ( V_2 , 0 , V_317 ) ;
F_20 ( V_2 , 0 , V_318 ) ;
F_20 ( V_2 , 0 , V_319 ) ;
F_20 ( V_2 , V_412 | V_413 , V_320 ) ;
if ( F_1 ( V_2 ) ) {
F_20 ( V_2 , 0 , V_321 ) ;
F_20 ( V_2 , 0 , V_322 ) ;
} else {
F_20 ( V_2 , 0 , V_323 ) ;
F_20 ( V_2 , 0 , V_324 ) ;
}
F_20 ( V_2 , 0 , V_325 ) ;
F_20 ( V_2 , 0 , V_326 ) ;
F_20 ( V_2 , 0 , V_332 ) ;
F_20 ( V_2 , 0 , V_333 ) ;
F_20 ( V_2 , 0 , V_334 ) ;
F_20 ( V_2 , 0 , V_335 ) ;
F_20 ( V_2 , 0 , V_336 ) ;
}
static int F_181 ( struct V_1 * V_2 )
{
F_182 ( V_2 -> V_273 ) ;
F_183 ( V_2 -> V_273 ) ;
return 0 ;
}
static int F_184 ( struct V_1 * V_2 ,
struct V_414 * V_415 )
{
int V_48 , V_21 ;
struct V_88 * V_89 ;
struct V_416 * V_344 = V_2 -> V_344 ;
struct V_417 * V_114 = & V_2 -> V_344 -> V_114 ;
V_89 = F_185 ( V_114 , sizeof( struct V_88 ) , V_129 ) ;
if ( ! V_89 )
return - V_130 ;
V_89 -> V_83 = V_2 -> V_83 + V_2 -> V_3 [ V_291 ] ;
V_89 -> V_90 = V_415 -> V_418 ;
V_89 -> V_93 = V_419 ;
V_89 -> V_92 = V_420 ;
V_89 -> V_91 = V_421 ;
V_89 -> V_94 = V_422 ;
V_89 -> V_86 . V_423 = & V_424 ;
V_2 -> V_273 = F_186 ( & V_89 -> V_86 ) ;
if ( ! V_2 -> V_273 )
return - V_130 ;
V_2 -> V_273 -> V_276 = L_20 ;
V_2 -> V_273 -> V_266 = V_114 ;
snprintf ( V_2 -> V_273 -> V_274 , V_271 , L_21 ,
V_344 -> V_276 , V_344 -> V_274 ) ;
V_2 -> V_273 -> V_247 = F_187 ( V_114 , V_425 , sizeof( int ) ,
V_129 ) ;
if ( ! V_2 -> V_273 -> V_247 ) {
V_48 = - V_130 ;
goto V_426;
}
if ( V_114 -> V_267 ) {
V_48 = F_188 ( V_2 -> V_273 , V_114 -> V_267 ) ;
} else {
for ( V_21 = 0 ; V_21 < V_425 ; V_21 ++ )
V_2 -> V_273 -> V_247 [ V_21 ] = V_427 ;
if ( V_415 -> V_428 > 0 )
V_2 -> V_273 -> V_247 [ V_415 -> V_429 ] = V_415 -> V_428 ;
V_48 = F_189 ( V_2 -> V_273 ) ;
}
if ( V_48 )
goto V_426;
return 0 ;
V_426:
F_183 ( V_2 -> V_273 ) ;
return V_48 ;
}
static const T_5 * F_190 ( int V_430 )
{
const T_5 * V_3 = NULL ;
switch ( V_430 ) {
case V_431 :
V_3 = V_4 ;
break;
case V_432 :
V_3 = V_5 ;
break;
case V_433 :
V_3 = V_434 ;
break;
case V_435 :
V_3 = V_436 ;
break;
case V_437 :
V_3 = V_438 ;
break;
default:
break;
}
return V_3 ;
}
static struct V_414 * F_191 ( struct V_417 * V_114 )
{
struct V_264 * V_265 = V_114 -> V_267 ;
struct V_414 * V_439 ;
const char * V_440 ;
V_439 = F_185 ( V_114 , sizeof( * V_439 ) , V_129 ) ;
if ( ! V_439 )
return NULL ;
V_439 -> V_9 = F_192 ( V_265 ) ;
V_440 = F_193 ( V_265 ) ;
if ( V_440 )
memcpy ( V_439 -> V_440 , V_440 , V_80 ) ;
V_439 -> V_225 =
F_194 ( V_265 , L_22 ) ;
V_439 -> V_228 =
F_194 ( V_265 , L_23 ) ;
return V_439 ;
}
static inline struct V_414 * F_191 ( struct V_417 * V_114 )
{
return NULL ;
}
static int F_195 ( struct V_416 * V_344 )
{
int V_48 , V_441 = 0 ;
struct V_442 * V_443 ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_414 * V_415 = F_196 ( & V_344 -> V_114 ) ;
const struct V_444 * V_274 = F_197 ( V_344 ) ;
V_443 = F_198 ( V_344 , V_445 , 0 ) ;
V_7 = F_199 ( sizeof( struct V_1 ) ) ;
if ( ! V_7 )
return - V_130 ;
F_200 ( & V_344 -> V_114 ) ;
F_121 ( & V_344 -> V_114 ) ;
V_441 = V_344 -> V_274 ;
if ( V_441 < 0 )
V_441 = 0 ;
V_7 -> V_446 = - 1 ;
V_48 = F_201 ( V_344 , 0 ) ;
if ( V_48 < 0 ) {
V_48 = - V_280 ;
goto V_447;
}
V_7 -> V_247 = V_48 ;
F_202 ( V_7 , & V_344 -> V_114 ) ;
V_2 = F_4 ( V_7 ) ;
V_2 -> V_98 = V_448 ;
V_2 -> V_96 = V_449 ;
V_2 -> V_83 = F_203 ( & V_344 -> V_114 , V_443 ) ;
if ( F_101 ( V_2 -> V_83 ) ) {
V_48 = F_102 ( V_2 -> V_83 ) ;
goto V_447;
}
V_7 -> V_450 = V_443 -> V_134 ;
F_204 ( & V_2 -> V_251 ) ;
V_2 -> V_344 = V_344 ;
if ( V_344 -> V_114 . V_267 )
V_415 = F_191 ( & V_344 -> V_114 ) ;
if ( ! V_415 ) {
F_205 ( & V_344 -> V_114 , L_24 ) ;
V_48 = - V_363 ;
goto V_447;
}
V_2 -> V_270 = V_415 -> V_429 ;
V_2 -> V_9 = V_415 -> V_9 ;
V_2 -> V_73 = V_415 -> V_73 ;
V_2 -> V_225 = V_415 -> V_225 ;
V_2 -> V_228 = V_415 -> V_228 ;
if ( V_274 ) {
V_2 -> V_32 = (struct V_31 * ) V_274 -> V_451 ;
} else {
const struct V_452 * V_453 ;
V_453 = F_206 ( F_207 ( V_454 ) ,
& V_344 -> V_114 ) ;
V_2 -> V_32 = (struct V_31 * ) V_453 -> V_70 ;
}
V_2 -> V_3 = F_190 ( V_2 -> V_32 -> V_430 ) ;
if ( ! V_2 -> V_3 ) {
F_205 ( & V_344 -> V_114 , L_25 ,
V_2 -> V_32 -> V_430 ) ;
V_48 = - V_363 ;
goto V_447;
}
F_23 ( V_2 -> V_32 ) ;
if ( V_2 -> V_32 -> V_309 )
V_7 -> V_455 = & V_456 ;
else
V_7 -> V_455 = & V_457 ;
V_7 -> V_458 = & V_459 ;
V_7 -> V_460 = V_461 ;
V_2 -> V_345 = V_462 ;
F_36 ( V_7 , V_415 -> V_440 ) ;
if ( ! F_208 ( V_7 -> V_76 ) ) {
F_209 ( & V_344 -> V_114 ,
L_26 ) ;
F_210 ( V_7 ) ;
}
if ( V_2 -> V_32 -> V_309 ) {
struct V_442 * V_463 ;
V_463 = F_198 ( V_344 , V_445 , 1 ) ;
V_2 -> V_339 = F_203 ( & V_344 -> V_114 , V_463 ) ;
if ( F_101 ( V_2 -> V_339 ) ) {
V_48 = F_102 ( V_2 -> V_339 ) ;
goto V_447;
}
V_2 -> V_385 = V_441 % 2 ;
V_7 -> V_464 = V_465 ;
}
if ( ! V_441 || V_415 -> V_466 ) {
if ( V_2 -> V_32 -> V_467 )
V_2 -> V_32 -> V_467 ( V_7 ) ;
if ( V_2 -> V_32 -> V_309 ) {
F_180 ( V_2 ) ;
}
}
if ( V_2 -> V_32 -> V_136 )
F_6 ( V_7 , 0x1 , V_137 ) ;
V_48 = F_184 ( V_2 , V_415 ) ;
if ( V_48 ) {
F_205 ( & V_7 -> V_114 , L_27 ) ;
goto V_447;
}
F_211 ( V_7 , & V_2 -> V_255 , F_91 , 64 ) ;
V_48 = F_212 ( V_7 ) ;
if ( V_48 )
goto V_468;
F_103 ( V_7 , L_28 ,
( T_1 ) V_7 -> V_450 , V_7 -> V_76 , V_7 -> V_247 ) ;
F_213 ( & V_344 -> V_114 ) ;
F_214 ( V_344 , V_7 ) ;
return V_48 ;
V_468:
F_215 ( & V_2 -> V_255 ) ;
F_181 ( V_2 ) ;
V_447:
if ( V_7 )
F_216 ( V_7 ) ;
F_213 ( & V_344 -> V_114 ) ;
F_217 ( & V_344 -> V_114 ) ;
return V_48 ;
}
static int F_218 ( struct V_416 * V_344 )
{
struct V_6 * V_7 = F_219 ( V_344 ) ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_220 ( V_7 ) ;
F_215 ( & V_2 -> V_255 ) ;
F_181 ( V_2 ) ;
F_217 ( & V_344 -> V_114 ) ;
F_216 ( V_7 ) ;
return 0 ;
}
static int F_221 ( struct V_417 * V_114 )
{
struct V_6 * V_7 = F_222 ( V_114 ) ;
int V_48 = 0 ;
if ( F_132 ( V_7 ) ) {
F_133 ( V_7 ) ;
V_48 = F_149 ( V_7 ) ;
}
return V_48 ;
}
static int F_223 ( struct V_417 * V_114 )
{
struct V_6 * V_7 = F_222 ( V_114 ) ;
int V_48 = 0 ;
if ( F_132 ( V_7 ) ) {
V_48 = F_138 ( V_7 ) ;
if ( V_48 < 0 )
return V_48 ;
F_137 ( V_7 ) ;
}
return V_48 ;
}
static int F_224 ( struct V_417 * V_114 )
{
return 0 ;
}
