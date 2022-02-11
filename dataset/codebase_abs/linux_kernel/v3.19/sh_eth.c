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
unsigned long V_22 [ 2 ] , V_23 [ 2 ] ;
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
static unsigned long F_37 ( struct V_1 * V_2 )
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
if ( V_2 -> V_97 [ V_180 ] ) {
F_68 ( & V_7 -> V_114 , V_102 -> V_83 ,
V_102 -> V_113 , V_181 ) ;
F_69 ( V_2 -> V_97 [ V_180 ] ) ;
V_2 -> V_97 [ V_180 ] = NULL ;
V_179 ++ ;
}
V_102 -> V_116 = F_29 ( V_2 , V_122 ) ;
if ( V_180 >= V_2 -> V_98 - 1 )
V_102 -> V_116 |= F_29 ( V_2 , V_124 ) ;
V_7 -> V_182 . V_183 ++ ;
V_7 -> V_182 . V_184 += V_102 -> V_113 ;
}
return V_179 ;
}
static int F_70 ( struct V_6 * V_7 , T_1 V_185 , int * V_186 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_99 * V_100 ;
int V_180 = V_2 -> V_108 % V_2 -> V_96 ;
int V_187 = ( V_2 -> V_110 + V_2 -> V_96 ) - V_2 -> V_108 ;
int V_188 ;
struct V_67 * V_68 ;
T_5 V_189 = 0 ;
T_1 V_190 ;
int V_105 = V_2 -> V_106 + V_71 - 1 ;
T_4 V_107 ;
V_187 = F_71 ( V_187 , * V_186 ) ;
V_188 = V_187 ;
V_100 = & V_2 -> V_112 [ V_180 ] ;
while ( ! ( V_100 -> V_116 & F_29 ( V_2 , V_117 ) ) ) {
V_190 = F_32 ( V_2 , V_100 -> V_116 ) ;
V_189 = V_100 -> V_191 ;
if ( -- V_187 < 0 )
break;
if ( ! ( V_190 & V_192 ) )
V_7 -> V_182 . V_193 ++ ;
if ( V_2 -> V_32 -> V_194 )
V_190 >>= 16 ;
if ( V_190 & ( V_195 | V_196 | V_197 | V_198 |
V_199 | V_200 | V_201 ) ) {
V_7 -> V_182 . V_202 ++ ;
if ( V_190 & V_195 )
V_7 -> V_182 . V_203 ++ ;
if ( V_190 & V_196 )
V_7 -> V_182 . V_204 ++ ;
if ( V_190 & V_197 )
V_7 -> V_182 . V_193 ++ ;
if ( V_190 & V_198 )
V_7 -> V_182 . V_193 ++ ;
if ( V_190 & V_200 )
V_7 -> V_182 . V_205 ++ ;
if ( V_190 & V_201 )
V_7 -> V_182 . V_206 ++ ;
} else {
if ( ! V_2 -> V_32 -> V_142 )
F_72 (
F_73 ( F_51 ( V_100 -> V_83 , 4 ) ) ,
V_189 + 2 ) ;
V_68 = V_2 -> V_95 [ V_180 ] ;
V_2 -> V_95 [ V_180 ] = NULL ;
if ( V_2 -> V_32 -> V_127 )
F_28 ( V_68 , V_128 ) ;
F_68 ( & V_7 -> V_114 , V_100 -> V_83 ,
F_51 ( V_2 -> V_106 , 16 ) ,
V_115 ) ;
F_74 ( V_68 , V_189 ) ;
V_68 -> V_207 = F_75 ( V_68 , V_7 ) ;
F_76 ( V_68 ) ;
V_7 -> V_182 . V_208 ++ ;
V_7 -> V_182 . V_209 += V_189 ;
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
F_77 ( V_68 ) ;
V_100 -> V_83 = V_107 ;
}
if ( V_180 >= V_2 -> V_96 - 1 )
V_100 -> V_116 |=
F_29 ( V_2 , V_117 | V_118 | V_120 ) ;
else
V_100 -> V_116 |=
F_29 ( V_2 , V_117 | V_118 ) ;
}
if ( ! ( F_8 ( V_7 , V_177 ) & V_176 ) ) {
if ( V_185 & V_210 ) {
T_1 V_211 = ( F_8 ( V_7 , V_60 ) -
F_8 ( V_7 , V_59 ) ) >> 4 ;
V_2 -> V_108 = V_211 ;
V_2 -> V_110 = V_211 ;
}
F_6 ( V_7 , V_176 , V_177 ) ;
}
* V_186 -= V_188 - V_187 - 1 ;
return * V_186 <= 0 ;
}
static void F_64 ( struct V_6 * V_7 )
{
F_6 ( V_7 , F_8 ( V_7 , V_15 ) &
~ ( V_163 | V_162 ) , V_15 ) ;
}
static void F_78 ( struct V_6 * V_7 )
{
F_6 ( V_7 , F_8 ( V_7 , V_15 ) |
( V_163 | V_162 ) , V_15 ) ;
}
static void F_79 ( struct V_6 * V_7 , int V_185 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_212 ;
T_1 V_213 ;
T_1 V_214 ;
if ( V_185 & V_215 ) {
V_212 = F_8 ( V_7 , V_165 ) ;
F_6 ( V_7 , V_212 , V_165 ) ;
if ( V_212 & V_216 )
V_7 -> V_182 . V_217 ++ ;
if ( V_212 & V_218 ) {
if ( V_2 -> V_32 -> V_219 || V_2 -> V_220 ) {
goto V_221;
} else {
V_213 = ( F_8 ( V_7 , V_222 ) ) ;
if ( V_2 -> V_223 )
V_213 = ~ V_213 ;
}
if ( ! ( V_213 & V_224 ) ) {
F_64 ( V_7 ) ;
} else {
F_6 ( V_7 , F_8 ( V_7 , V_140 ) &
~ V_225 , V_140 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_165 ) ,
V_165 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_140 ) |
V_225 , V_140 ) ;
F_78 ( V_7 ) ;
}
}
}
V_221:
if ( V_185 & V_226 ) {
if ( V_185 & V_227 ) {
V_7 -> V_182 . V_228 ++ ;
F_80 ( V_2 , V_229 , V_7 , L_3 ) ;
}
}
if ( V_185 & V_230 ) {
if ( V_185 & V_231 ) {
V_7 -> V_182 . V_204 ++ ;
}
}
if ( V_185 & V_232 ) {
V_7 -> V_182 . V_233 ++ ;
F_80 ( V_2 , V_229 , V_7 , L_4 ) ;
}
if ( V_185 & V_234 ) {
V_7 -> V_182 . V_233 ++ ;
F_80 ( V_2 , V_229 , V_7 , L_5 ) ;
}
if ( V_185 & V_210 ) {
V_7 -> V_182 . V_206 ++ ;
}
if ( V_185 & V_235 ) {
V_7 -> V_182 . V_236 ++ ;
}
if ( ! V_2 -> V_32 -> V_237 && ( V_185 & V_238 ) ) {
V_7 -> V_182 . V_233 ++ ;
F_80 ( V_2 , V_229 , V_7 , L_6 ) ;
}
V_214 = V_226 | V_227 | V_238 | V_232 | V_234 ;
if ( V_2 -> V_32 -> V_237 )
V_214 &= ~ V_238 ;
if ( V_185 & V_214 ) {
T_1 V_239 = F_8 ( V_7 , V_240 ) ;
F_25 ( V_7 , L_7 ,
V_185 , V_2 -> V_109 , V_2 -> V_111 ,
( T_1 ) V_7 -> V_241 , V_239 ) ;
F_67 ( V_7 ) ;
if ( V_239 ^ F_37 ( V_2 ) ) {
F_6 ( V_7 , F_37 ( V_2 ) , V_240 ) ;
}
F_81 ( V_7 ) ;
}
}
static T_6 F_82 ( int V_242 , void * V_243 )
{
struct V_6 * V_7 = V_243 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_31 * V_32 = V_2 -> V_32 ;
T_6 V_48 = V_244 ;
unsigned long V_185 , V_245 ;
F_83 ( & V_2 -> V_246 ) ;
V_185 = F_8 ( V_7 , V_158 ) ;
V_245 = F_8 ( V_7 , V_140 ) ;
V_185 &= V_245 | V_225 ;
if ( V_185 & ( V_247 | V_32 -> V_42 | V_32 -> V_44 ) )
V_48 = V_248 ;
else
goto V_249;
if ( ! F_84 ( V_2 -> V_159 ) ) {
F_6 ( V_7 , 0 , V_140 ) ;
goto V_249;
}
if ( V_185 & V_247 ) {
if ( F_85 ( & V_2 -> V_250 ) ) {
F_6 ( V_7 , V_245 & ~ V_247 ,
V_140 ) ;
F_86 ( & V_2 -> V_250 ) ;
} else {
F_5 ( V_7 ,
L_8 ,
V_185 , V_245 ) ;
}
}
if ( V_185 & V_32 -> V_42 ) {
F_6 ( V_7 , V_185 & V_32 -> V_42 , V_158 ) ;
F_67 ( V_7 ) ;
F_81 ( V_7 ) ;
}
if ( V_185 & V_32 -> V_44 ) {
F_6 ( V_7 , V_185 & V_32 -> V_44 , V_158 ) ;
F_79 ( V_7 , V_185 ) ;
}
V_249:
F_87 ( & V_2 -> V_246 ) ;
return V_48 ;
}
static int F_88 ( struct V_251 * V_250 , int V_252 )
{
struct V_1 * V_2 = F_42 ( V_250 , struct V_1 ,
V_250 ) ;
struct V_6 * V_7 = V_250 -> V_114 ;
int V_186 = V_252 ;
unsigned long V_185 ;
for (; ; ) {
V_185 = F_8 ( V_7 , V_158 ) ;
if ( ! ( V_185 & V_247 ) )
break;
F_6 ( V_7 , V_185 & V_247 , V_158 ) ;
if ( F_70 ( V_7 , V_185 , & V_186 ) )
goto V_249;
}
F_89 ( V_250 ) ;
if ( V_2 -> V_159 )
F_6 ( V_7 , V_2 -> V_32 -> V_160 , V_140 ) ;
V_249:
return V_252 - V_186 ;
}
static void F_90 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_253 * V_254 = V_2 -> V_254 ;
int V_255 = 0 ;
if ( V_254 -> V_256 ) {
if ( V_254 -> V_14 != V_2 -> V_14 ) {
V_255 = 1 ;
V_2 -> V_14 = V_254 -> V_14 ;
if ( V_2 -> V_32 -> V_257 )
V_2 -> V_32 -> V_257 ( V_7 ) ;
}
if ( V_254 -> V_17 != V_2 -> V_17 ) {
V_255 = 1 ;
V_2 -> V_17 = V_254 -> V_17 ;
if ( V_2 -> V_32 -> V_164 )
V_2 -> V_32 -> V_164 ( V_7 ) ;
}
if ( ! V_2 -> V_256 ) {
F_6 ( V_7 ,
F_8 ( V_7 , V_15 ) & ~ V_258 ,
V_15 ) ;
V_255 = 1 ;
V_2 -> V_256 = V_254 -> V_256 ;
if ( V_2 -> V_32 -> V_219 || V_2 -> V_220 )
F_78 ( V_7 ) ;
}
} else if ( V_2 -> V_256 ) {
V_255 = 1 ;
V_2 -> V_256 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_14 = - 1 ;
if ( V_2 -> V_32 -> V_219 || V_2 -> V_220 )
F_64 ( V_7 ) ;
}
if ( V_255 && F_91 ( V_2 ) )
F_92 ( V_254 ) ;
}
static int F_93 ( struct V_6 * V_7 )
{
struct V_259 * V_260 = V_7 -> V_114 . V_261 -> V_262 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_253 * V_254 = NULL ;
V_2 -> V_256 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_14 = - 1 ;
if ( V_260 ) {
struct V_259 * V_263 ;
V_263 = F_94 ( V_260 , L_9 , 0 ) ;
V_254 = F_95 ( V_7 , V_263 ,
F_90 , 0 ,
V_2 -> V_9 ) ;
if ( ! V_254 )
V_254 = F_96 ( - V_264 ) ;
} else {
char V_265 [ V_266 + 3 ] ;
snprintf ( V_265 , sizeof( V_265 ) , V_267 ,
V_2 -> V_268 -> V_269 , V_2 -> V_265 ) ;
V_254 = F_97 ( V_7 , V_265 , F_90 ,
V_2 -> V_9 ) ;
}
if ( F_98 ( V_254 ) ) {
F_25 ( V_7 , L_10 ) ;
return F_99 ( V_254 ) ;
}
F_100 ( V_7 , L_11 ,
V_254 -> V_83 , V_254 -> V_242 , V_254 -> V_270 -> V_271 ) ;
V_2 -> V_254 = V_254 ;
return 0 ;
}
static int F_101 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_48 ;
V_48 = F_93 ( V_7 ) ;
if ( V_48 )
return V_48 ;
F_102 ( V_2 -> V_254 ) ;
return 0 ;
}
static int F_103 ( struct V_6 * V_7 ,
struct V_272 * V_273 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
unsigned long V_274 ;
int V_48 ;
if ( ! V_2 -> V_254 )
return - V_275 ;
F_104 ( & V_2 -> V_246 , V_274 ) ;
V_48 = F_105 ( V_2 -> V_254 , V_273 ) ;
F_106 ( & V_2 -> V_246 , V_274 ) ;
return V_48 ;
}
static int F_107 ( struct V_6 * V_7 ,
struct V_272 * V_273 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
unsigned long V_274 ;
int V_48 ;
if ( ! V_2 -> V_254 )
return - V_275 ;
F_104 ( & V_2 -> V_246 , V_274 ) ;
F_64 ( V_7 ) ;
V_48 = F_108 ( V_2 -> V_254 , V_273 ) ;
if ( V_48 )
goto V_276;
if ( V_273 -> V_14 == V_277 )
V_2 -> V_14 = 1 ;
else
V_2 -> V_14 = 0 ;
if ( V_2 -> V_32 -> V_257 )
V_2 -> V_32 -> V_257 ( V_7 ) ;
V_276:
F_17 ( 1 ) ;
F_78 ( V_7 ) ;
F_106 ( & V_2 -> V_246 , V_274 ) ;
return V_48 ;
}
static int F_109 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
unsigned long V_274 ;
int V_48 ;
if ( ! V_2 -> V_254 )
return - V_275 ;
F_104 ( & V_2 -> V_246 , V_274 ) ;
V_48 = F_110 ( V_2 -> V_254 ) ;
F_106 ( & V_2 -> V_246 , V_274 ) ;
return V_48 ;
}
static T_1 F_111 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
return V_2 -> V_278 ;
}
static void F_112 ( struct V_6 * V_7 , T_1 V_8 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
V_2 -> V_278 = V_8 ;
}
static int F_113 ( struct V_6 * V_243 , int V_279 )
{
switch ( V_279 ) {
case V_280 :
return V_281 ;
default:
return - V_282 ;
}
}
static void F_114 ( struct V_6 * V_7 ,
struct V_283 * V_182 , T_7 * V_70 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 = 0 ;
V_70 [ V_21 ++ ] = V_2 -> V_108 ;
V_70 [ V_21 ++ ] = V_2 -> V_109 ;
V_70 [ V_21 ++ ] = V_2 -> V_110 ;
V_70 [ V_21 ++ ] = V_2 -> V_111 ;
}
static void F_115 ( struct V_6 * V_7 , T_1 V_284 , T_8 * V_70 )
{
switch ( V_284 ) {
case V_280 :
memcpy ( V_70 , * V_285 ,
sizeof( V_285 ) ) ;
break;
}
}
static void F_116 ( struct V_6 * V_7 ,
struct V_286 * V_287 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
V_287 -> V_288 = V_289 ;
V_287 -> V_290 = V_291 ;
V_287 -> V_292 = V_2 -> V_96 ;
V_287 -> V_293 = V_2 -> V_98 ;
}
static int F_117 ( struct V_6 * V_7 ,
struct V_286 * V_287 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_48 ;
if ( V_287 -> V_293 > V_291 ||
V_287 -> V_292 > V_289 ||
V_287 -> V_293 < V_294 ||
V_287 -> V_292 < V_295 )
return - V_296 ;
if ( V_287 -> V_297 || V_287 -> V_298 )
return - V_296 ;
if ( F_118 ( V_7 ) ) {
F_119 ( V_7 ) ;
F_120 ( V_7 ) ;
V_2 -> V_159 = false ;
F_121 ( V_7 -> V_242 ) ;
F_122 ( & V_2 -> V_250 ) ;
F_6 ( V_7 , 0x0000 , V_140 ) ;
F_63 ( V_7 ) ;
F_46 ( V_7 ) ;
F_59 ( V_2 ) ;
}
V_2 -> V_96 = V_287 -> V_292 ;
V_2 -> V_98 = V_287 -> V_293 ;
if ( F_118 ( V_7 ) ) {
V_48 = F_55 ( V_7 ) ;
if ( V_48 < 0 ) {
F_25 ( V_7 , L_12 ,
V_299 ) ;
return V_48 ;
}
V_48 = F_60 ( V_7 , false ) ;
if ( V_48 < 0 ) {
F_25 ( V_7 , L_13 ,
V_299 ) ;
return V_48 ;
}
V_2 -> V_159 = true ;
F_6 ( V_7 , V_2 -> V_32 -> V_160 , V_140 ) ;
F_6 ( V_7 , V_176 , V_177 ) ;
F_123 ( V_7 ) ;
}
return 0 ;
}
static int F_124 ( struct V_6 * V_7 )
{
int V_48 = 0 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_125 ( & V_2 -> V_300 -> V_114 ) ;
F_126 ( & V_2 -> V_250 ) ;
V_48 = F_127 ( V_7 -> V_242 , F_82 ,
V_2 -> V_32 -> V_301 , V_7 -> V_271 , V_7 ) ;
if ( V_48 ) {
F_25 ( V_7 , L_14 ) ;
goto V_302;
}
V_48 = F_55 ( V_7 ) ;
if ( V_48 )
goto V_303;
V_48 = F_60 ( V_7 , true ) ;
if ( V_48 )
goto V_303;
V_48 = F_101 ( V_7 ) ;
if ( V_48 )
goto V_303;
V_2 -> V_304 = 1 ;
return V_48 ;
V_303:
F_128 ( V_7 -> V_242 , V_7 ) ;
V_302:
F_129 ( & V_2 -> V_250 ) ;
F_130 ( & V_2 -> V_300 -> V_114 ) ;
return V_48 ;
}
static void F_131 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_99 * V_100 ;
int V_21 ;
F_132 ( V_7 ) ;
F_80 ( V_2 , V_305 , V_7 ,
L_15 ,
( int ) F_8 ( V_7 , V_158 ) ) ;
V_7 -> V_182 . V_306 ++ ;
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
static int F_133 ( struct V_67 * V_68 , struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_101 * V_102 ;
T_1 V_180 ;
unsigned long V_274 ;
F_104 ( & V_2 -> V_246 , V_274 ) ;
if ( ( V_2 -> V_109 - V_2 -> V_111 ) >= ( V_2 -> V_98 - 4 ) ) {
if ( ! F_67 ( V_7 ) ) {
F_134 ( V_2 , V_307 , V_7 , L_16 ) ;
F_132 ( V_7 ) ;
F_106 ( & V_2 -> V_246 , V_274 ) ;
return V_308 ;
}
}
F_106 ( & V_2 -> V_246 , V_274 ) ;
if ( F_135 ( V_68 , V_309 ) )
return V_310 ;
V_180 = V_2 -> V_109 % V_2 -> V_98 ;
V_2 -> V_97 [ V_180 ] = V_68 ;
V_102 = & V_2 -> V_121 [ V_180 ] ;
if ( ! V_2 -> V_32 -> V_142 )
F_72 ( F_73 ( F_51 ( V_102 -> V_83 , 4 ) ) ,
V_68 -> V_311 + 2 ) ;
V_102 -> V_83 = F_52 ( & V_7 -> V_114 , V_68 -> V_70 , V_68 -> V_311 ,
V_181 ) ;
if ( F_53 ( & V_7 -> V_114 , V_102 -> V_83 ) ) {
F_54 ( V_68 ) ;
return V_310 ;
}
V_102 -> V_113 = V_68 -> V_311 ;
if ( V_180 >= V_2 -> V_98 - 1 )
V_102 -> V_116 |= F_29 ( V_2 , V_178 | V_124 ) ;
else
V_102 -> V_116 |= F_29 ( V_2 , V_178 ) ;
V_2 -> V_109 ++ ;
if ( ! ( F_8 ( V_7 , V_240 ) & F_37 ( V_2 ) ) )
F_6 ( V_7 , F_37 ( V_2 ) , V_240 ) ;
return V_310 ;
}
static struct V_312 * F_66 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
if ( F_2 ( V_2 ) )
return & V_7 -> V_182 ;
if ( ! V_2 -> V_304 )
return & V_7 -> V_182 ;
V_7 -> V_182 . V_313 += F_8 ( V_7 , V_314 ) ;
F_6 ( V_7 , 0 , V_314 ) ;
V_7 -> V_182 . V_315 += F_8 ( V_7 , V_316 ) ;
F_6 ( V_7 , 0 , V_316 ) ;
V_7 -> V_182 . V_217 += F_8 ( V_7 , V_317 ) ;
F_6 ( V_7 , 0 , V_317 ) ;
if ( F_1 ( V_2 ) ) {
V_7 -> V_182 . V_217 += F_8 ( V_7 , V_318 ) ;
F_6 ( V_7 , 0 , V_318 ) ;
V_7 -> V_182 . V_217 += F_8 ( V_7 , V_319 ) ;
F_6 ( V_7 , 0 , V_319 ) ;
} else {
V_7 -> V_182 . V_217 += F_8 ( V_7 , V_320 ) ;
F_6 ( V_7 , 0 , V_320 ) ;
}
return & V_7 -> V_182 ;
}
static int F_136 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_132 ( V_7 ) ;
V_2 -> V_159 = false ;
F_121 ( V_7 -> V_242 ) ;
F_129 ( & V_2 -> V_250 ) ;
F_6 ( V_7 , 0x0000 , V_140 ) ;
F_63 ( V_7 ) ;
if ( V_2 -> V_254 ) {
F_137 ( V_2 -> V_254 ) ;
F_138 ( V_2 -> V_254 ) ;
V_2 -> V_254 = NULL ;
}
F_128 ( V_7 -> V_242 , V_7 ) ;
F_46 ( V_7 ) ;
F_59 ( V_2 ) ;
F_130 ( & V_2 -> V_300 -> V_114 ) ;
V_2 -> V_304 = 0 ;
return 0 ;
}
static int F_139 ( struct V_6 * V_7 , struct V_321 * V_322 , int V_323 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_253 * V_254 = V_2 -> V_254 ;
if ( ! F_118 ( V_7 ) )
return - V_296 ;
if ( ! V_254 )
return - V_275 ;
return F_140 ( V_254 , V_322 , V_323 ) ;
}
static void * F_141 ( struct V_1 * V_2 ,
int V_180 )
{
return F_142 ( V_2 , V_324 ) + ( V_180 / 8 * 4 ) ;
}
static T_1 F_143 ( int V_180 )
{
return 0x0f << ( 28 - ( ( V_180 % 8 ) * 4 ) ) ;
}
static T_1 F_144 ( struct V_1 * V_2 , int V_180 )
{
return ( 0x08 >> ( V_2 -> V_325 << 1 ) ) << ( 28 - ( ( V_180 % 8 ) * 4 ) ) ;
}
static void F_145 ( struct V_6 * V_7 ,
int V_180 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_326 ;
void * V_3 ;
V_3 = F_141 ( V_2 , V_180 ) ;
V_326 = F_13 ( V_3 ) ;
F_16 ( V_326 | F_144 ( V_2 , V_180 ) , V_3 ) ;
}
static bool F_146 ( struct V_6 * V_7 ,
int V_180 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_327 , V_328 , V_326 ;
void * V_3 ;
V_3 = F_141 ( V_2 , V_180 ) ;
V_327 = F_143 ( V_180 ) ;
V_328 = F_144 ( V_2 , V_180 ) & ~ V_327 ;
V_326 = F_13 ( V_3 ) ;
F_16 ( V_326 & ~ V_327 , V_3 ) ;
return V_326 & V_328 ;
}
static int F_147 ( struct V_6 * V_7 )
{
int V_329 = V_330 * 100 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
while ( ( F_148 ( V_2 , V_331 ) & V_332 ) ) {
F_149 ( 10 ) ;
V_329 -- ;
if ( V_329 <= 0 ) {
F_25 ( V_7 , L_17 , V_299 ) ;
return - V_51 ;
}
}
return 0 ;
}
static int F_150 ( struct V_6 * V_7 , void * V_333 ,
const T_8 * V_83 )
{
T_1 V_135 ;
V_135 = V_83 [ 0 ] << 24 | V_83 [ 1 ] << 16 | V_83 [ 2 ] << 8 | V_83 [ 3 ] ;
F_16 ( V_135 , V_333 ) ;
if ( F_147 ( V_7 ) < 0 )
return - V_334 ;
V_135 = V_83 [ 4 ] << 8 | V_83 [ 5 ] ;
F_16 ( V_135 , V_333 + 4 ) ;
if ( F_147 ( V_7 ) < 0 )
return - V_334 ;
return 0 ;
}
static void F_151 ( void * V_333 , T_8 * V_83 )
{
T_1 V_135 ;
V_135 = F_13 ( V_333 ) ;
V_83 [ 0 ] = ( V_135 >> 24 ) & 0xff ;
V_83 [ 1 ] = ( V_135 >> 16 ) & 0xff ;
V_83 [ 2 ] = ( V_135 >> 8 ) & 0xff ;
V_83 [ 3 ] = V_135 & 0xff ;
V_135 = F_13 ( V_333 + 4 ) ;
V_83 [ 4 ] = ( V_135 >> 8 ) & 0xff ;
V_83 [ 5 ] = V_135 & 0xff ;
}
static int F_152 ( struct V_6 * V_7 , const T_8 * V_83 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
void * V_3 = F_142 ( V_2 , V_335 ) ;
int V_21 ;
T_8 V_336 [ V_80 ] ;
for ( V_21 = 0 ; V_21 < V_337 ; V_21 ++ , V_3 += 8 ) {
F_151 ( V_3 , V_336 ) ;
if ( F_153 ( V_83 , V_336 ) )
return V_21 ;
}
return - V_264 ;
}
static int F_154 ( struct V_6 * V_7 )
{
T_8 V_338 [ V_80 ] ;
int V_180 ;
memset ( V_338 , 0 , sizeof( V_338 ) ) ;
V_180 = F_152 ( V_7 , V_338 ) ;
return ( V_180 < 0 ) ? - V_130 : V_180 ;
}
static int F_155 ( struct V_6 * V_7 ,
int V_180 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
void * V_3 = F_142 ( V_2 , V_335 ) ;
int V_48 ;
T_8 V_338 [ V_80 ] ;
F_20 ( V_2 , F_148 ( V_2 , V_339 ) &
~ ( 1 << ( 31 - V_180 ) ) , V_339 ) ;
memset ( V_338 , 0 , sizeof( V_338 ) ) ;
V_48 = F_150 ( V_7 , V_3 + V_180 * 8 , V_338 ) ;
if ( V_48 < 0 )
return V_48 ;
return 0 ;
}
static int F_156 ( struct V_6 * V_7 , const T_8 * V_83 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
void * V_3 = F_142 ( V_2 , V_335 ) ;
int V_21 , V_48 ;
if ( ! V_2 -> V_32 -> V_340 )
return 0 ;
V_21 = F_152 ( V_7 , V_83 ) ;
if ( V_21 < 0 ) {
V_21 = F_154 ( V_7 ) ;
if ( V_21 < 0 )
return - V_130 ;
V_48 = F_150 ( V_7 , V_3 + V_21 * 8 , V_83 ) ;
if ( V_48 < 0 )
return V_48 ;
F_20 ( V_2 , F_148 ( V_2 , V_339 ) |
( 1 << ( 31 - V_21 ) ) , V_339 ) ;
}
F_145 ( V_7 , V_21 ) ;
return 0 ;
}
static int F_157 ( struct V_6 * V_7 , const T_8 * V_83 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 , V_48 ;
if ( ! V_2 -> V_32 -> V_340 )
return 0 ;
V_21 = F_152 ( V_7 , V_83 ) ;
if ( V_21 ) {
if ( F_146 ( V_7 , V_21 ) )
goto V_341;
V_48 = F_155 ( V_7 , V_21 ) ;
if ( V_48 < 0 )
return V_48 ;
}
V_341:
return 0 ;
}
static int F_158 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 , V_48 ;
if ( ! V_2 -> V_32 -> V_340 )
return 0 ;
for ( V_21 = 0 ; V_21 < V_337 ; V_21 ++ ) {
if ( F_146 ( V_7 , V_21 ) )
continue;
V_48 = F_155 ( V_7 , V_21 ) ;
if ( V_48 < 0 )
return V_48 ;
}
return 0 ;
}
static void F_159 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_8 V_83 [ V_80 ] ;
void * V_3 = F_142 ( V_2 , V_335 ) ;
int V_21 ;
if ( ! V_2 -> V_32 -> V_340 )
return;
for ( V_21 = 0 ; V_21 < V_337 ; V_21 ++ , V_3 += 8 ) {
F_151 ( V_3 , V_83 ) ;
if ( F_160 ( V_83 ) )
F_157 ( V_7 , V_83 ) ;
}
}
static void F_161 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_342 ;
int V_343 = 0 ;
unsigned long V_274 ;
F_104 ( & V_2 -> V_246 , V_274 ) ;
V_342 = F_8 ( V_7 , V_15 ) & ~ V_344 ;
if ( V_2 -> V_32 -> V_340 )
V_342 |= V_345 ;
if ( ! ( V_7 -> V_274 & V_346 ) ) {
F_159 ( V_7 ) ;
V_343 = 1 ;
}
if ( V_7 -> V_274 & V_347 ) {
F_159 ( V_7 ) ;
V_342 &= ~ V_345 ;
V_343 = 1 ;
}
if ( V_7 -> V_274 & V_348 ) {
F_158 ( V_7 ) ;
V_342 = ( V_342 & ~ V_345 ) | V_344 ;
} else if ( V_2 -> V_32 -> V_340 ) {
struct V_349 * V_350 ;
F_162 (ha, ndev) {
if ( V_343 && F_160 ( V_350 -> V_83 ) )
continue;
if ( F_156 ( V_7 , V_350 -> V_83 ) < 0 ) {
if ( ! V_343 ) {
F_159 ( V_7 ) ;
V_342 &= ~ V_345 ;
V_343 = 1 ;
}
}
}
}
F_6 ( V_7 , V_342 , V_15 ) ;
F_106 ( & V_2 -> V_246 , V_274 ) ;
}
static int F_163 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_325 )
return V_351 ;
else
return V_352 ;
}
static int F_164 ( struct V_6 * V_7 ,
T_9 V_353 , T_5 V_354 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_355 = F_163 ( V_2 ) ;
if ( F_165 ( ! V_2 -> V_32 -> V_340 ) )
return - V_356 ;
if ( ! V_354 )
return 0 ;
V_2 -> V_357 ++ ;
if ( V_2 -> V_357 > 1 ) {
F_20 ( V_2 , 0 , V_355 ) ;
return 0 ;
}
F_20 ( V_2 , V_358 | ( V_354 & V_359 ) ,
V_355 ) ;
return 0 ;
}
static int F_166 ( struct V_6 * V_7 ,
T_9 V_353 , T_5 V_354 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_355 = F_163 ( V_2 ) ;
if ( F_165 ( ! V_2 -> V_32 -> V_340 ) )
return - V_356 ;
if ( ! V_354 )
return 0 ;
V_2 -> V_357 -- ;
F_20 ( V_2 , 0 , V_355 ) ;
return 0 ;
}
static void F_167 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
F_20 ( V_2 , 0 , V_339 ) ;
return;
}
F_20 ( V_2 , 0 , V_360 ) ;
F_20 ( V_2 , 0 , V_361 ) ;
F_20 ( V_2 , 0 , V_362 ) ;
F_20 ( V_2 , 0xc , V_363 ) ;
F_20 ( V_2 , 0xc , V_364 ) ;
F_20 ( V_2 , 0 , V_365 ) ;
F_20 ( V_2 , 0 , V_366 ) ;
F_20 ( V_2 , 0 , V_367 ) ;
F_20 ( V_2 , 0 , V_368 ) ;
F_20 ( V_2 , V_369 | V_370 , V_371 ) ;
if ( F_1 ( V_2 ) ) {
F_20 ( V_2 , 0 , V_372 ) ;
F_20 ( V_2 , 0 , V_373 ) ;
} else {
F_20 ( V_2 , 0 , V_374 ) ;
F_20 ( V_2 , 0 , V_375 ) ;
}
F_20 ( V_2 , 0 , V_376 ) ;
F_20 ( V_2 , 0 , V_377 ) ;
F_20 ( V_2 , 0 , V_339 ) ;
F_20 ( V_2 , 0 , V_324 ) ;
F_20 ( V_2 , 0 , V_378 ) ;
F_20 ( V_2 , 0 , V_379 ) ;
F_20 ( V_2 , 0 , V_380 ) ;
}
static int F_168 ( struct V_1 * V_2 )
{
F_169 ( V_2 -> V_268 ) ;
F_170 ( V_2 -> V_268 ) ;
return 0 ;
}
static int F_171 ( struct V_1 * V_2 ,
struct V_381 * V_382 )
{
int V_48 , V_21 ;
struct V_88 * V_89 ;
struct V_383 * V_300 = V_2 -> V_300 ;
struct V_384 * V_114 = & V_2 -> V_300 -> V_114 ;
V_89 = F_172 ( V_114 , sizeof( struct V_88 ) , V_129 ) ;
if ( ! V_89 )
return - V_130 ;
V_89 -> V_83 = V_2 -> V_83 + V_2 -> V_3 [ V_385 ] ;
V_89 -> V_90 = V_382 -> V_386 ;
V_89 -> V_93 = V_387 ;
V_89 -> V_92 = V_388 ;
V_89 -> V_91 = V_389 ;
V_89 -> V_94 = V_390 ;
V_89 -> V_86 . V_391 = & V_392 ;
V_2 -> V_268 = F_173 ( & V_89 -> V_86 ) ;
if ( ! V_2 -> V_268 )
return - V_130 ;
V_2 -> V_268 -> V_271 = L_18 ;
V_2 -> V_268 -> V_261 = V_114 ;
snprintf ( V_2 -> V_268 -> V_269 , V_266 , L_19 ,
V_300 -> V_271 , V_300 -> V_269 ) ;
V_2 -> V_268 -> V_242 = F_174 ( V_114 , V_393 , sizeof( int ) ,
V_129 ) ;
if ( ! V_2 -> V_268 -> V_242 ) {
V_48 = - V_130 ;
goto V_394;
}
if ( V_114 -> V_262 ) {
V_48 = F_175 ( V_2 -> V_268 , V_114 -> V_262 ) ;
} else {
for ( V_21 = 0 ; V_21 < V_393 ; V_21 ++ )
V_2 -> V_268 -> V_242 [ V_21 ] = V_395 ;
if ( V_382 -> V_396 > 0 )
V_2 -> V_268 -> V_242 [ V_382 -> V_397 ] = V_382 -> V_396 ;
V_48 = F_176 ( V_2 -> V_268 ) ;
}
if ( V_48 )
goto V_394;
return 0 ;
V_394:
F_170 ( V_2 -> V_268 ) ;
return V_48 ;
}
static const T_5 * F_177 ( int V_398 )
{
const T_5 * V_3 = NULL ;
switch ( V_398 ) {
case V_399 :
V_3 = V_4 ;
break;
case V_400 :
V_3 = V_5 ;
break;
case V_401 :
V_3 = V_402 ;
break;
case V_403 :
V_3 = V_404 ;
break;
case V_405 :
V_3 = V_406 ;
break;
default:
break;
}
return V_3 ;
}
static struct V_381 * F_178 ( struct V_384 * V_114 )
{
struct V_259 * V_260 = V_114 -> V_262 ;
struct V_381 * V_407 ;
const char * V_408 ;
V_407 = F_172 ( V_114 , sizeof( * V_407 ) , V_129 ) ;
if ( ! V_407 )
return NULL ;
V_407 -> V_9 = F_179 ( V_260 ) ;
V_408 = F_180 ( V_260 ) ;
if ( V_408 )
memcpy ( V_407 -> V_408 , V_408 , V_80 ) ;
V_407 -> V_220 =
F_181 ( V_260 , L_20 ) ;
V_407 -> V_223 =
F_181 ( V_260 , L_21 ) ;
return V_407 ;
}
static inline struct V_381 * F_178 ( struct V_384 * V_114 )
{
return NULL ;
}
static int F_182 ( struct V_383 * V_300 )
{
int V_48 , V_409 = 0 ;
struct V_410 * V_411 ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_381 * V_382 = F_183 ( & V_300 -> V_114 ) ;
const struct V_412 * V_269 = F_184 ( V_300 ) ;
V_411 = F_185 ( V_300 , V_413 , 0 ) ;
V_7 = F_186 ( sizeof( struct V_1 ) ) ;
if ( ! V_7 )
return - V_130 ;
F_187 ( & V_300 -> V_114 ) ;
F_125 ( & V_300 -> V_114 ) ;
V_409 = V_300 -> V_269 ;
if ( V_409 < 0 )
V_409 = 0 ;
V_7 -> V_414 = - 1 ;
V_48 = F_188 ( V_300 , 0 ) ;
if ( V_48 < 0 ) {
V_48 = - V_275 ;
goto V_415;
}
V_7 -> V_242 = V_48 ;
F_189 ( V_7 , & V_300 -> V_114 ) ;
V_2 = F_4 ( V_7 ) ;
V_2 -> V_98 = V_416 ;
V_2 -> V_96 = V_417 ;
V_2 -> V_83 = F_190 ( & V_300 -> V_114 , V_411 ) ;
if ( F_98 ( V_2 -> V_83 ) ) {
V_48 = F_99 ( V_2 -> V_83 ) ;
goto V_415;
}
V_7 -> V_418 = V_411 -> V_134 ;
F_191 ( & V_2 -> V_246 ) ;
V_2 -> V_300 = V_300 ;
if ( V_300 -> V_114 . V_262 )
V_382 = F_178 ( & V_300 -> V_114 ) ;
if ( ! V_382 ) {
F_192 ( & V_300 -> V_114 , L_22 ) ;
V_48 = - V_296 ;
goto V_415;
}
V_2 -> V_265 = V_382 -> V_397 ;
V_2 -> V_9 = V_382 -> V_9 ;
V_2 -> V_73 = V_382 -> V_73 ;
V_2 -> V_220 = V_382 -> V_220 ;
V_2 -> V_223 = V_382 -> V_223 ;
if ( V_269 ) {
V_2 -> V_32 = (struct V_31 * ) V_269 -> V_419 ;
} else {
const struct V_420 * V_421 ;
V_421 = F_193 ( F_194 ( V_422 ) ,
& V_300 -> V_114 ) ;
V_2 -> V_32 = (struct V_31 * ) V_421 -> V_70 ;
}
V_2 -> V_3 = F_177 ( V_2 -> V_32 -> V_398 ) ;
if ( ! V_2 -> V_3 ) {
F_192 ( & V_300 -> V_114 , L_23 ,
V_2 -> V_32 -> V_398 ) ;
V_48 = - V_296 ;
goto V_415;
}
F_23 ( V_2 -> V_32 ) ;
if ( V_2 -> V_32 -> V_340 )
V_7 -> V_423 = & V_424 ;
else
V_7 -> V_423 = & V_425 ;
V_7 -> V_426 = & V_427 ;
V_7 -> V_428 = V_429 ;
V_2 -> V_278 = V_430 ;
F_36 ( V_7 , V_382 -> V_408 ) ;
if ( ! F_195 ( V_7 -> V_76 ) ) {
F_196 ( & V_300 -> V_114 ,
L_24 ) ;
F_197 ( V_7 ) ;
}
if ( V_2 -> V_32 -> V_340 ) {
struct V_410 * V_431 ;
V_431 = F_185 ( V_300 , V_413 , 1 ) ;
V_2 -> V_432 = F_190 ( & V_300 -> V_114 , V_431 ) ;
if ( F_98 ( V_2 -> V_432 ) ) {
V_48 = F_99 ( V_2 -> V_432 ) ;
goto V_415;
}
V_2 -> V_325 = V_409 % 2 ;
V_7 -> V_433 = V_434 ;
}
if ( ! V_409 || V_382 -> V_435 ) {
if ( V_2 -> V_32 -> V_436 )
V_2 -> V_32 -> V_436 ( V_7 ) ;
if ( V_2 -> V_32 -> V_340 ) {
F_167 ( V_2 ) ;
}
}
if ( V_2 -> V_32 -> V_136 )
F_6 ( V_7 , 0x1 , V_137 ) ;
V_48 = F_171 ( V_2 , V_382 ) ;
if ( V_48 ) {
F_192 ( & V_7 -> V_114 , L_25 ) ;
goto V_415;
}
F_198 ( V_7 , & V_2 -> V_250 , F_88 , 64 ) ;
V_48 = F_199 ( V_7 ) ;
if ( V_48 )
goto V_437;
F_100 ( V_7 , L_26 ,
( T_1 ) V_7 -> V_418 , V_7 -> V_76 , V_7 -> V_242 ) ;
F_200 ( & V_300 -> V_114 ) ;
F_201 ( V_300 , V_7 ) ;
return V_48 ;
V_437:
F_202 ( & V_2 -> V_250 ) ;
F_168 ( V_2 ) ;
V_415:
if ( V_7 )
F_203 ( V_7 ) ;
F_200 ( & V_300 -> V_114 ) ;
F_204 ( & V_300 -> V_114 ) ;
return V_48 ;
}
static int F_205 ( struct V_383 * V_300 )
{
struct V_6 * V_7 = F_206 ( V_300 ) ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_207 ( V_7 ) ;
F_202 ( & V_2 -> V_250 ) ;
F_168 ( V_2 ) ;
F_204 ( & V_300 -> V_114 ) ;
F_203 ( V_7 ) ;
return 0 ;
}
static int F_208 ( struct V_384 * V_114 )
{
return 0 ;
}
