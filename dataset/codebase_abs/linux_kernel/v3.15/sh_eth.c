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
int V_69 ;
V_69 = V_70 - ( ( T_1 ) V_68 -> V_71 & ( V_70 - 1 ) ) ;
if ( V_69 )
F_28 ( V_68 , V_69 ) ;
}
static void F_27 ( struct V_67 * V_68 )
{
F_28 ( V_68 , V_72 ) ;
}
static inline T_2 F_29 ( struct V_1 * V_2 , T_1 V_73 )
{
switch ( V_2 -> V_74 ) {
case V_75 :
return F_30 ( V_73 ) ;
case V_76 :
return F_31 ( V_73 ) ;
}
return V_73 ;
}
static inline T_2 F_32 ( struct V_1 * V_2 , T_1 V_73 )
{
switch ( V_2 -> V_74 ) {
case V_75 :
return F_33 ( V_73 ) ;
case V_76 :
return F_34 ( V_73 ) ;
}
return V_73 ;
}
static void F_35 ( struct V_6 * V_7 )
{
F_6 ( V_7 ,
( V_7 -> V_77 [ 0 ] << 24 ) | ( V_7 -> V_77 [ 1 ] << 16 ) |
( V_7 -> V_77 [ 2 ] << 8 ) | ( V_7 -> V_77 [ 3 ] ) , V_78 ) ;
F_6 ( V_7 ,
( V_7 -> V_77 [ 4 ] << 8 ) | ( V_7 -> V_77 [ 5 ] ) , V_79 ) ;
}
static void F_36 ( struct V_6 * V_7 , unsigned char * V_80 )
{
if ( V_80 [ 0 ] || V_80 [ 1 ] || V_80 [ 2 ] || V_80 [ 3 ] || V_80 [ 4 ] || V_80 [ 5 ] ) {
memcpy ( V_7 -> V_77 , V_80 , V_81 ) ;
} else {
V_7 -> V_77 [ 0 ] = ( F_8 ( V_7 , V_78 ) >> 24 ) ;
V_7 -> V_77 [ 1 ] = ( F_8 ( V_7 , V_78 ) >> 16 ) & 0xFF ;
V_7 -> V_77 [ 2 ] = ( F_8 ( V_7 , V_78 ) >> 8 ) & 0xFF ;
V_7 -> V_77 [ 3 ] = ( F_8 ( V_7 , V_78 ) & 0xFF ) ;
V_7 -> V_77 [ 4 ] = ( F_8 ( V_7 , V_79 ) >> 8 ) & 0xFF ;
V_7 -> V_77 [ 5 ] = ( F_8 ( V_7 , V_79 ) & 0xFF ) ;
}
}
static unsigned long F_37 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) || F_2 ( V_2 ) )
return V_82 ;
else
return V_83 ;
}
static void F_38 ( void * V_84 , T_1 V_85 )
{
F_16 ( F_13 ( V_84 ) | V_85 , V_84 ) ;
}
static void F_39 ( void * V_84 , T_1 V_85 )
{
F_16 ( ( F_13 ( V_84 ) & ~ V_85 ) , V_84 ) ;
}
static int F_40 ( void * V_84 , T_1 V_85 )
{
return ( F_13 ( V_84 ) & V_85 ) != 0 ;
}
static void F_41 ( struct V_86 * V_87 , int V_88 )
{
struct V_89 * V_90 = F_42 ( V_87 , struct V_89 , V_87 ) ;
if ( V_90 -> V_91 )
V_90 -> V_91 ( V_90 -> V_84 ) ;
if ( V_88 )
F_38 ( V_90 -> V_84 , V_90 -> V_92 ) ;
else
F_39 ( V_90 -> V_84 , V_90 -> V_92 ) ;
}
static void F_43 ( struct V_86 * V_87 , int V_88 )
{
struct V_89 * V_90 = F_42 ( V_87 , struct V_89 , V_87 ) ;
if ( V_90 -> V_91 )
V_90 -> V_91 ( V_90 -> V_84 ) ;
if ( V_88 )
F_38 ( V_90 -> V_84 , V_90 -> V_93 ) ;
else
F_39 ( V_90 -> V_84 , V_90 -> V_93 ) ;
}
static int F_44 ( struct V_86 * V_87 )
{
struct V_89 * V_90 = F_42 ( V_87 , struct V_89 , V_87 ) ;
if ( V_90 -> V_91 )
V_90 -> V_91 ( V_90 -> V_84 ) ;
return F_40 ( V_90 -> V_84 , V_90 -> V_94 ) ;
}
static void F_45 ( struct V_86 * V_87 , int V_88 )
{
struct V_89 * V_90 = F_42 ( V_87 , struct V_89 , V_87 ) ;
if ( V_90 -> V_91 )
V_90 -> V_91 ( V_90 -> V_84 ) ;
if ( V_88 )
F_38 ( V_90 -> V_84 , V_90 -> V_95 ) ;
else
F_39 ( V_90 -> V_84 , V_90 -> V_95 ) ;
}
static void F_46 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 ;
if ( V_2 -> V_96 ) {
for ( V_21 = 0 ; V_21 < V_2 -> V_97 ; V_21 ++ ) {
if ( V_2 -> V_96 [ V_21 ] )
F_47 ( V_2 -> V_96 [ V_21 ] ) ;
}
}
F_48 ( V_2 -> V_96 ) ;
V_2 -> V_96 = NULL ;
if ( V_2 -> V_98 ) {
for ( V_21 = 0 ; V_21 < V_2 -> V_99 ; V_21 ++ ) {
if ( V_2 -> V_98 [ V_21 ] )
F_47 ( V_2 -> V_98 [ V_21 ] ) ;
}
}
F_48 ( V_2 -> V_98 ) ;
V_2 -> V_98 = NULL ;
}
static void F_49 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 ;
struct V_67 * V_68 ;
struct V_100 * V_101 = NULL ;
struct V_102 * V_103 = NULL ;
int V_104 = sizeof( * V_101 ) * V_2 -> V_97 ;
int V_105 = sizeof( * V_103 ) * V_2 -> V_99 ;
V_2 -> V_106 = 0 ;
V_2 -> V_107 = 0 ;
V_2 -> V_108 = 0 ;
V_2 -> V_109 = 0 ;
memset ( V_2 -> V_110 , 0 , V_104 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_97 ; V_21 ++ ) {
V_2 -> V_96 [ V_21 ] = NULL ;
V_68 = F_50 ( V_7 , V_2 -> V_111 ) ;
V_2 -> V_96 [ V_21 ] = V_68 ;
if ( V_68 == NULL )
break;
F_51 ( & V_7 -> V_112 , V_68 -> V_71 , V_2 -> V_111 ,
V_113 ) ;
F_27 ( V_68 ) ;
V_101 = & V_2 -> V_110 [ V_21 ] ;
V_101 -> V_84 = F_52 ( F_53 ( V_68 -> V_71 , 4 ) ) ;
V_101 -> V_114 = F_29 ( V_2 , V_115 | V_116 ) ;
V_101 -> V_117 = F_54 ( V_2 -> V_111 , 16 ) ;
if ( V_21 == 0 ) {
F_6 ( V_7 , V_2 -> V_118 , V_59 ) ;
if ( F_1 ( V_2 ) ||
F_2 ( V_2 ) )
F_6 ( V_7 , V_2 -> V_118 , V_60 ) ;
}
}
V_2 -> V_108 = ( T_1 ) ( V_21 - V_2 -> V_97 ) ;
V_101 -> V_114 |= F_29 ( V_2 , V_119 ) ;
memset ( V_2 -> V_120 , 0 , V_105 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_99 ; V_21 ++ ) {
V_2 -> V_98 [ V_21 ] = NULL ;
V_103 = & V_2 -> V_120 [ V_21 ] ;
V_103 -> V_114 = F_29 ( V_2 , V_121 ) ;
V_103 -> V_117 = 0 ;
if ( V_21 == 0 ) {
F_6 ( V_7 , V_2 -> V_122 , V_55 ) ;
if ( F_1 ( V_2 ) ||
F_2 ( V_2 ) )
F_6 ( V_7 , V_2 -> V_122 , V_56 ) ;
}
}
V_103 -> V_114 |= F_29 ( V_2 , V_123 ) ;
}
static int F_55 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_104 , V_105 , V_48 = 0 ;
V_2 -> V_111 = ( V_7 -> V_124 <= 1492 ? V_125 :
( ( ( V_7 -> V_124 + 26 + 7 ) & ~ 7 ) + 2 + 16 ) ) ;
if ( V_2 -> V_32 -> V_126 )
V_2 -> V_111 += V_127 ;
V_2 -> V_96 = F_56 ( V_2 -> V_97 ,
sizeof( * V_2 -> V_96 ) , V_128 ) ;
if ( ! V_2 -> V_96 ) {
V_48 = - V_129 ;
return V_48 ;
}
V_2 -> V_98 = F_56 ( V_2 -> V_99 ,
sizeof( * V_2 -> V_98 ) , V_128 ) ;
if ( ! V_2 -> V_98 ) {
V_48 = - V_129 ;
goto V_130;
}
V_104 = sizeof( struct V_100 ) * V_2 -> V_97 ;
V_2 -> V_110 = F_57 ( NULL , V_104 , & V_2 -> V_118 ,
V_128 ) ;
if ( ! V_2 -> V_110 ) {
V_48 = - V_129 ;
goto V_131;
}
V_2 -> V_108 = 0 ;
V_105 = sizeof( struct V_102 ) * V_2 -> V_99 ;
V_2 -> V_120 = F_57 ( NULL , V_105 , & V_2 -> V_122 ,
V_128 ) ;
if ( ! V_2 -> V_120 ) {
V_48 = - V_129 ;
goto V_131;
}
return V_48 ;
V_131:
F_58 ( NULL , V_104 , V_2 -> V_110 , V_2 -> V_118 ) ;
V_130:
F_46 ( V_7 ) ;
V_2 -> V_120 = NULL ;
V_2 -> V_110 = NULL ;
return V_48 ;
}
static void F_59 ( struct V_1 * V_2 )
{
int V_132 ;
if ( V_2 -> V_110 ) {
V_132 = sizeof( struct V_100 ) * V_2 -> V_97 ;
F_58 ( NULL , V_132 , V_2 -> V_110 ,
V_2 -> V_118 ) ;
V_2 -> V_110 = NULL ;
}
if ( V_2 -> V_120 ) {
V_132 = sizeof( struct V_102 ) * V_2 -> V_99 ;
F_58 ( NULL , V_132 , V_2 -> V_120 ,
V_2 -> V_122 ) ;
V_2 -> V_120 = NULL ;
}
}
static int F_60 ( struct V_6 * V_7 , bool V_133 )
{
int V_48 = 0 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_134 ;
V_48 = F_26 ( V_7 ) ;
if ( V_48 )
return V_48 ;
if ( V_2 -> V_32 -> V_135 )
F_6 ( V_7 , 0x1 , V_136 ) ;
F_49 ( V_7 ) ;
if ( V_2 -> V_32 -> V_126 )
F_6 ( V_7 , V_2 -> V_32 -> V_137 , V_138 ) ;
F_6 ( V_7 , 0 , V_139 ) ;
#if F_61 ( V_140 )
if ( V_2 -> V_32 -> V_141 )
F_6 ( V_7 , V_142 , V_50 ) ;
else
#endif
F_6 ( V_7 , 0 , V_50 ) ;
F_6 ( V_7 , V_2 -> V_32 -> V_40 , V_143 ) ;
F_6 ( V_7 , 0 , V_144 ) ;
F_6 ( V_7 , V_2 -> V_32 -> V_42 , V_145 ) ;
F_6 ( V_7 , V_146 | V_147 | V_148 , V_149 ) ;
if ( V_2 -> V_32 -> V_150 )
F_6 ( V_7 , 0x800 , V_151 ) ;
F_6 ( V_7 , V_2 -> V_32 -> V_37 , V_152 ) ;
if ( ! V_2 -> V_32 -> V_153 )
F_6 ( V_7 , 0 , V_154 ) ;
F_6 ( V_7 , V_7 -> V_124 + V_155 + V_156 + V_157 ,
V_158 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_159 ) , V_159 ) ;
if ( V_133 )
F_6 ( V_7 , V_2 -> V_32 -> V_160 , V_139 ) ;
V_134 = ( F_8 ( V_7 , V_15 ) & V_16 ) |
V_161 | ( V_2 -> V_14 ? V_16 : 0 ) | V_162 | V_163 ;
F_6 ( V_7 , V_134 , V_15 ) ;
if ( V_2 -> V_32 -> V_164 )
V_2 -> V_32 -> V_164 ( V_7 ) ;
F_6 ( V_7 , V_2 -> V_32 -> V_33 , V_165 ) ;
if ( V_133 )
F_6 ( V_7 , V_2 -> V_32 -> V_35 , V_166 ) ;
F_35 ( V_7 ) ;
if ( V_2 -> V_32 -> V_167 )
F_6 ( V_7 , V_168 , V_169 ) ;
if ( V_2 -> V_32 -> V_170 )
F_6 ( V_7 , V_171 , V_172 ) ;
if ( V_2 -> V_32 -> V_173 )
F_6 ( V_7 , V_174 , V_175 ) ;
if ( V_133 ) {
F_6 ( V_7 , V_176 , V_177 ) ;
F_62 ( V_7 ) ;
}
return V_48 ;
}
static int F_63 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_102 * V_103 ;
int V_178 = 0 ;
int V_179 = 0 ;
for (; V_2 -> V_107 - V_2 -> V_109 > 0 ; V_2 -> V_109 ++ ) {
V_179 = V_2 -> V_109 % V_2 -> V_99 ;
V_103 = & V_2 -> V_120 [ V_179 ] ;
if ( V_103 -> V_114 & F_29 ( V_2 , V_180 ) )
break;
if ( V_2 -> V_98 [ V_179 ] ) {
F_64 ( & V_7 -> V_112 , V_103 -> V_84 ,
V_103 -> V_117 , V_181 ) ;
F_65 ( V_2 -> V_98 [ V_179 ] ) ;
V_2 -> V_98 [ V_179 ] = NULL ;
V_178 ++ ;
}
V_103 -> V_114 = F_29 ( V_2 , V_121 ) ;
if ( V_179 >= V_2 -> V_99 - 1 )
V_103 -> V_114 |= F_29 ( V_2 , V_123 ) ;
V_7 -> V_182 . V_183 ++ ;
V_7 -> V_182 . V_184 += V_103 -> V_117 ;
}
return V_178 ;
}
static int F_66 ( struct V_6 * V_7 , T_1 V_185 , int * V_186 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_100 * V_101 ;
int V_179 = V_2 -> V_106 % V_2 -> V_97 ;
int V_187 = ( V_2 -> V_108 + V_2 -> V_97 ) - V_2 -> V_106 ;
struct V_67 * V_68 ;
int V_188 = 0 ;
T_3 V_189 = 0 ;
T_1 V_190 ;
V_101 = & V_2 -> V_110 [ V_179 ] ;
while ( ! ( V_101 -> V_114 & F_29 ( V_2 , V_115 ) ) ) {
V_190 = F_32 ( V_2 , V_101 -> V_114 ) ;
V_189 = V_101 -> V_191 ;
if ( -- V_187 < 0 )
break;
if ( * V_186 <= 0 ) {
V_188 = 1 ;
break;
}
( * V_186 ) -- ;
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
if ( ! V_2 -> V_32 -> V_141 )
F_67 (
F_68 ( F_54 ( V_101 -> V_84 , 4 ) ) ,
V_189 + 2 ) ;
V_68 = V_2 -> V_96 [ V_179 ] ;
V_2 -> V_96 [ V_179 ] = NULL ;
if ( V_2 -> V_32 -> V_126 )
F_28 ( V_68 , V_127 ) ;
F_69 ( & V_7 -> V_112 , V_101 -> V_84 ,
V_2 -> V_111 ,
V_113 ) ;
F_70 ( V_68 , V_189 ) ;
V_68 -> V_207 = F_71 ( V_68 , V_7 ) ;
F_72 ( V_68 ) ;
V_7 -> V_182 . V_208 ++ ;
V_7 -> V_182 . V_209 += V_189 ;
}
V_101 -> V_114 |= F_29 ( V_2 , V_115 ) ;
V_179 = ( ++ V_2 -> V_106 ) % V_2 -> V_97 ;
V_101 = & V_2 -> V_110 [ V_179 ] ;
}
for (; V_2 -> V_106 - V_2 -> V_108 > 0 ; V_2 -> V_108 ++ ) {
V_179 = V_2 -> V_108 % V_2 -> V_97 ;
V_101 = & V_2 -> V_110 [ V_179 ] ;
V_101 -> V_117 = F_54 ( V_2 -> V_111 , 16 ) ;
if ( V_2 -> V_96 [ V_179 ] == NULL ) {
V_68 = F_50 ( V_7 , V_2 -> V_111 ) ;
V_2 -> V_96 [ V_179 ] = V_68 ;
if ( V_68 == NULL )
break;
F_51 ( & V_7 -> V_112 , V_68 -> V_71 , V_2 -> V_111 ,
V_113 ) ;
F_27 ( V_68 ) ;
F_73 ( V_68 ) ;
V_101 -> V_84 = F_52 ( F_53 ( V_68 -> V_71 , 4 ) ) ;
}
if ( V_179 >= V_2 -> V_97 - 1 )
V_101 -> V_114 |=
F_29 ( V_2 , V_115 | V_116 | V_119 ) ;
else
V_101 -> V_114 |=
F_29 ( V_2 , V_115 | V_116 ) ;
}
if ( ! ( F_8 ( V_7 , V_177 ) & V_176 ) ) {
if ( V_185 & V_210 ) {
T_1 V_211 = ( F_8 ( V_7 , V_60 ) -
F_8 ( V_7 , V_59 ) ) >> 4 ;
V_2 -> V_106 = V_211 ;
V_2 -> V_108 = V_211 ;
}
F_6 ( V_7 , V_176 , V_177 ) ;
}
return V_188 ;
}
static void F_74 ( struct V_6 * V_7 )
{
F_6 ( V_7 , F_8 ( V_7 , V_15 ) &
~ ( V_163 | V_162 ) , V_15 ) ;
}
static void F_75 ( struct V_6 * V_7 )
{
F_6 ( V_7 , F_8 ( V_7 , V_15 ) |
( V_163 | V_162 ) , V_15 ) ;
}
static void F_76 ( struct V_6 * V_7 , int V_185 )
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
F_74 ( V_7 ) ;
} else {
F_6 ( V_7 , F_8 ( V_7 , V_139 ) &
~ V_225 , V_139 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_165 ) ,
V_165 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_139 ) |
V_225 , V_139 ) ;
F_75 ( V_7 ) ;
}
}
}
V_221:
if ( V_185 & V_226 ) {
if ( V_185 & V_227 ) {
V_7 -> V_182 . V_228 ++ ;
F_77 ( V_2 , V_229 , V_7 , L_3 ) ;
}
}
if ( V_185 & V_230 ) {
if ( V_185 & V_231 ) {
V_7 -> V_182 . V_204 ++ ;
F_77 ( V_2 , V_232 , V_7 , L_4 ) ;
}
}
if ( V_185 & V_233 ) {
V_7 -> V_182 . V_234 ++ ;
F_77 ( V_2 , V_229 , V_7 , L_5 ) ;
}
if ( V_185 & V_235 ) {
V_7 -> V_182 . V_234 ++ ;
F_77 ( V_2 , V_229 , V_7 , L_6 ) ;
}
if ( V_185 & V_210 ) {
V_7 -> V_182 . V_206 ++ ;
F_77 ( V_2 , V_232 , V_7 , L_7 ) ;
}
if ( V_185 & V_236 ) {
V_7 -> V_182 . V_237 ++ ;
F_77 ( V_2 , V_232 , V_7 , L_8 ) ;
}
if ( ! V_2 -> V_32 -> V_238 && ( V_185 & V_239 ) ) {
V_7 -> V_182 . V_234 ++ ;
F_77 ( V_2 , V_229 , V_7 , L_9 ) ;
}
V_214 = V_226 | V_227 | V_239 | V_233 | V_235 ;
if ( V_2 -> V_32 -> V_238 )
V_214 &= ~ V_239 ;
if ( V_185 & V_214 ) {
T_1 V_240 = F_8 ( V_7 , V_241 ) ;
F_25 ( V_7 , L_10 ,
V_185 , V_2 -> V_107 , V_2 -> V_109 ,
( T_1 ) V_7 -> V_242 , V_240 ) ;
F_63 ( V_7 ) ;
if ( V_240 ^ F_37 ( V_2 ) ) {
F_6 ( V_7 , F_37 ( V_2 ) , V_241 ) ;
}
F_78 ( V_7 ) ;
}
}
static T_4 F_79 ( int V_243 , void * V_244 )
{
struct V_6 * V_7 = V_244 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_31 * V_32 = V_2 -> V_32 ;
T_4 V_48 = V_245 ;
unsigned long V_185 , V_246 ;
F_80 ( & V_2 -> V_247 ) ;
V_185 = F_8 ( V_7 , V_159 ) ;
V_246 = F_8 ( V_7 , V_139 ) ;
V_185 &= V_246 | V_225 ;
if ( V_185 & ( V_248 | V_32 -> V_44 | V_32 -> V_46 ) )
V_48 = V_249 ;
else
goto V_250;
if ( V_185 & V_248 ) {
if ( F_81 ( & V_2 -> V_251 ) ) {
F_6 ( V_7 , V_246 & ~ V_248 ,
V_139 ) ;
F_82 ( & V_2 -> V_251 ) ;
} else {
F_5 ( V_7 ,
L_11 ,
V_185 , V_246 ) ;
}
}
if ( V_185 & V_32 -> V_44 ) {
F_6 ( V_7 , V_185 & V_32 -> V_44 , V_159 ) ;
F_63 ( V_7 ) ;
F_78 ( V_7 ) ;
}
if ( V_185 & V_32 -> V_46 ) {
F_6 ( V_7 , V_185 & V_32 -> V_46 , V_159 ) ;
F_76 ( V_7 , V_185 ) ;
}
V_250:
F_83 ( & V_2 -> V_247 ) ;
return V_48 ;
}
static int F_84 ( struct V_252 * V_251 , int V_253 )
{
struct V_1 * V_2 = F_42 ( V_251 , struct V_1 ,
V_251 ) ;
struct V_6 * V_7 = V_251 -> V_112 ;
int V_186 = V_253 ;
unsigned long V_185 ;
for (; ; ) {
V_185 = F_8 ( V_7 , V_159 ) ;
if ( ! ( V_185 & V_248 ) )
break;
F_6 ( V_7 , V_185 & V_248 , V_159 ) ;
if ( F_66 ( V_7 , V_185 , & V_186 ) )
goto V_254;
}
F_85 ( V_251 ) ;
F_6 ( V_7 , V_2 -> V_32 -> V_160 , V_139 ) ;
V_254:
return V_253 - V_186 ;
}
static void F_86 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_255 * V_256 = V_2 -> V_256 ;
int V_257 = 0 ;
if ( V_256 -> V_258 ) {
if ( V_256 -> V_14 != V_2 -> V_14 ) {
V_257 = 1 ;
V_2 -> V_14 = V_256 -> V_14 ;
if ( V_2 -> V_32 -> V_259 )
V_2 -> V_32 -> V_259 ( V_7 ) ;
}
if ( V_256 -> V_17 != V_2 -> V_17 ) {
V_257 = 1 ;
V_2 -> V_17 = V_256 -> V_17 ;
if ( V_2 -> V_32 -> V_164 )
V_2 -> V_32 -> V_164 ( V_7 ) ;
}
if ( ! V_2 -> V_258 ) {
F_6 ( V_7 ,
F_8 ( V_7 , V_15 ) & ~ V_260 ,
V_15 ) ;
V_257 = 1 ;
V_2 -> V_258 = V_256 -> V_258 ;
if ( V_2 -> V_32 -> V_219 || V_2 -> V_220 )
F_75 ( V_7 ) ;
}
} else if ( V_2 -> V_258 ) {
V_257 = 1 ;
V_2 -> V_258 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_14 = - 1 ;
if ( V_2 -> V_32 -> V_219 || V_2 -> V_220 )
F_74 ( V_7 ) ;
}
if ( V_257 && F_87 ( V_2 ) )
F_88 ( V_256 ) ;
}
static int F_89 ( struct V_6 * V_7 )
{
struct V_261 * V_262 = V_7 -> V_112 . V_263 -> V_264 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_255 * V_256 = NULL ;
V_2 -> V_258 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_14 = - 1 ;
if ( V_262 ) {
struct V_261 * V_265 ;
V_265 = F_90 ( V_262 , L_12 , 0 ) ;
V_256 = F_91 ( V_7 , V_265 ,
F_86 , 0 ,
V_2 -> V_9 ) ;
if ( ! V_256 )
V_256 = F_92 ( - V_266 ) ;
} else {
char V_267 [ V_268 + 3 ] ;
snprintf ( V_267 , sizeof( V_267 ) , V_269 ,
V_2 -> V_270 -> V_271 , V_2 -> V_267 ) ;
V_256 = F_93 ( V_7 , V_267 , F_86 ,
V_2 -> V_9 ) ;
}
if ( F_94 ( V_256 ) ) {
F_25 ( V_7 , L_13 ) ;
return F_95 ( V_256 ) ;
}
F_96 ( V_7 , L_14 ,
V_256 -> V_84 , V_256 -> V_243 , V_256 -> V_272 -> V_273 ) ;
V_2 -> V_256 = V_256 ;
return 0 ;
}
static int F_97 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_48 ;
V_48 = F_89 ( V_7 ) ;
if ( V_48 )
return V_48 ;
F_98 ( V_2 -> V_256 ) ;
return 0 ;
}
static int F_99 ( struct V_6 * V_7 ,
struct V_274 * V_275 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
unsigned long V_276 ;
int V_48 ;
F_100 ( & V_2 -> V_247 , V_276 ) ;
V_48 = F_101 ( V_2 -> V_256 , V_275 ) ;
F_102 ( & V_2 -> V_247 , V_276 ) ;
return V_48 ;
}
static int F_103 ( struct V_6 * V_7 ,
struct V_274 * V_275 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
unsigned long V_276 ;
int V_48 ;
F_100 ( & V_2 -> V_247 , V_276 ) ;
F_74 ( V_7 ) ;
V_48 = F_104 ( V_2 -> V_256 , V_275 ) ;
if ( V_48 )
goto V_277;
if ( V_275 -> V_14 == V_278 )
V_2 -> V_14 = 1 ;
else
V_2 -> V_14 = 0 ;
if ( V_2 -> V_32 -> V_259 )
V_2 -> V_32 -> V_259 ( V_7 ) ;
V_277:
F_17 ( 1 ) ;
F_75 ( V_7 ) ;
F_102 ( & V_2 -> V_247 , V_276 ) ;
return V_48 ;
}
static int F_105 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
unsigned long V_276 ;
int V_48 ;
F_100 ( & V_2 -> V_247 , V_276 ) ;
V_48 = F_106 ( V_2 -> V_256 ) ;
F_102 ( & V_2 -> V_247 , V_276 ) ;
return V_48 ;
}
static T_1 F_107 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
return V_2 -> V_279 ;
}
static void F_108 ( struct V_6 * V_7 , T_1 V_8 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
V_2 -> V_279 = V_8 ;
}
static int F_109 ( struct V_6 * V_244 , int V_280 )
{
switch ( V_280 ) {
case V_281 :
return V_282 ;
default:
return - V_283 ;
}
}
static void F_110 ( struct V_6 * V_7 ,
struct V_284 * V_182 , T_5 * V_71 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 = 0 ;
V_71 [ V_21 ++ ] = V_2 -> V_106 ;
V_71 [ V_21 ++ ] = V_2 -> V_107 ;
V_71 [ V_21 ++ ] = V_2 -> V_108 ;
V_71 [ V_21 ++ ] = V_2 -> V_109 ;
}
static void F_111 ( struct V_6 * V_7 , T_1 V_285 , T_6 * V_71 )
{
switch ( V_285 ) {
case V_281 :
memcpy ( V_71 , * V_286 ,
sizeof( V_286 ) ) ;
break;
}
}
static void F_112 ( struct V_6 * V_7 ,
struct V_287 * V_288 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
V_288 -> V_289 = V_290 ;
V_288 -> V_291 = V_292 ;
V_288 -> V_293 = V_2 -> V_97 ;
V_288 -> V_294 = V_2 -> V_99 ;
}
static int F_113 ( struct V_6 * V_7 ,
struct V_287 * V_288 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_48 ;
if ( V_288 -> V_294 > V_292 ||
V_288 -> V_293 > V_290 ||
V_288 -> V_294 < V_295 ||
V_288 -> V_293 < V_296 )
return - V_297 ;
if ( V_288 -> V_298 || V_288 -> V_299 )
return - V_297 ;
if ( F_114 ( V_7 ) ) {
F_115 ( V_7 ) ;
F_6 ( V_7 , 0x0000 , V_139 ) ;
F_6 ( V_7 , 0 , V_241 ) ;
F_6 ( V_7 , 0 , V_177 ) ;
F_116 ( V_7 -> V_243 ) ;
}
F_46 ( V_7 ) ;
F_59 ( V_2 ) ;
V_2 -> V_97 = V_288 -> V_293 ;
V_2 -> V_99 = V_288 -> V_294 ;
V_48 = F_55 ( V_7 ) ;
if ( V_48 < 0 ) {
F_25 ( V_7 , L_15 , V_300 ) ;
return V_48 ;
}
V_48 = F_60 ( V_7 , false ) ;
if ( V_48 < 0 ) {
F_25 ( V_7 , L_16 , V_300 ) ;
return V_48 ;
}
if ( F_114 ( V_7 ) ) {
F_6 ( V_7 , V_2 -> V_32 -> V_160 , V_139 ) ;
F_6 ( V_7 , V_176 , V_177 ) ;
F_78 ( V_7 ) ;
}
return 0 ;
}
static int F_117 ( struct V_6 * V_7 )
{
int V_48 = 0 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_118 ( & V_2 -> V_301 -> V_112 ) ;
F_119 ( & V_2 -> V_251 ) ;
V_48 = F_120 ( V_7 -> V_243 , F_79 ,
V_2 -> V_32 -> V_302 , V_7 -> V_273 , V_7 ) ;
if ( V_48 ) {
F_25 ( V_7 , L_17 ) ;
goto V_303;
}
V_48 = F_55 ( V_7 ) ;
if ( V_48 )
goto V_304;
V_48 = F_60 ( V_7 , true ) ;
if ( V_48 )
goto V_304;
V_48 = F_97 ( V_7 ) ;
if ( V_48 )
goto V_304;
return V_48 ;
V_304:
F_121 ( V_7 -> V_243 , V_7 ) ;
V_303:
F_122 ( & V_2 -> V_251 ) ;
F_123 ( & V_2 -> V_301 -> V_112 ) ;
return V_48 ;
}
static void F_124 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_100 * V_101 ;
int V_21 ;
F_125 ( V_7 ) ;
F_77 ( V_2 , V_305 , V_7 ,
L_18 ,
( int ) F_8 ( V_7 , V_159 ) ) ;
V_7 -> V_182 . V_306 ++ ;
for ( V_21 = 0 ; V_21 < V_2 -> V_97 ; V_21 ++ ) {
V_101 = & V_2 -> V_110 [ V_21 ] ;
V_101 -> V_114 = 0 ;
V_101 -> V_84 = 0xBADF00D0 ;
if ( V_2 -> V_96 [ V_21 ] )
F_47 ( V_2 -> V_96 [ V_21 ] ) ;
V_2 -> V_96 [ V_21 ] = NULL ;
}
for ( V_21 = 0 ; V_21 < V_2 -> V_99 ; V_21 ++ ) {
if ( V_2 -> V_98 [ V_21 ] )
F_47 ( V_2 -> V_98 [ V_21 ] ) ;
V_2 -> V_98 [ V_21 ] = NULL ;
}
F_60 ( V_7 , true ) ;
}
static int F_126 ( struct V_67 * V_68 , struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_102 * V_103 ;
T_1 V_179 ;
unsigned long V_276 ;
F_100 ( & V_2 -> V_247 , V_276 ) ;
if ( ( V_2 -> V_107 - V_2 -> V_109 ) >= ( V_2 -> V_99 - 4 ) ) {
if ( ! F_63 ( V_7 ) ) {
F_127 ( V_2 , V_307 , V_7 , L_19 ) ;
F_125 ( V_7 ) ;
F_102 ( & V_2 -> V_247 , V_276 ) ;
return V_308 ;
}
}
F_102 ( & V_2 -> V_247 , V_276 ) ;
V_179 = V_2 -> V_107 % V_2 -> V_99 ;
V_2 -> V_98 [ V_179 ] = V_68 ;
V_103 = & V_2 -> V_120 [ V_179 ] ;
if ( ! V_2 -> V_32 -> V_141 )
F_67 ( F_68 ( F_54 ( V_103 -> V_84 , 4 ) ) ,
V_68 -> V_309 + 2 ) ;
V_103 -> V_84 = F_51 ( & V_7 -> V_112 , V_68 -> V_71 , V_68 -> V_309 ,
V_181 ) ;
if ( V_68 -> V_309 < V_310 )
V_103 -> V_117 = V_310 ;
else
V_103 -> V_117 = V_68 -> V_309 ;
if ( V_179 >= V_2 -> V_99 - 1 )
V_103 -> V_114 |= F_29 ( V_2 , V_180 | V_123 ) ;
else
V_103 -> V_114 |= F_29 ( V_2 , V_180 ) ;
V_2 -> V_107 ++ ;
if ( ! ( F_8 ( V_7 , V_241 ) & F_37 ( V_2 ) ) )
F_6 ( V_7 , F_37 ( V_2 ) , V_241 ) ;
return V_311 ;
}
static int F_128 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_125 ( V_7 ) ;
F_6 ( V_7 , 0x0000 , V_139 ) ;
F_6 ( V_7 , 0 , V_241 ) ;
F_6 ( V_7 , 0 , V_177 ) ;
if ( V_2 -> V_256 ) {
F_129 ( V_2 -> V_256 ) ;
F_130 ( V_2 -> V_256 ) ;
}
F_121 ( V_7 -> V_243 , V_7 ) ;
F_122 ( & V_2 -> V_251 ) ;
F_46 ( V_7 ) ;
F_59 ( V_2 ) ;
F_123 ( & V_2 -> V_301 -> V_112 ) ;
return 0 ;
}
static struct V_312 * F_131 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
if ( F_2 ( V_2 ) )
return & V_7 -> V_182 ;
F_118 ( & V_2 -> V_301 -> V_112 ) ;
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
F_123 ( & V_2 -> V_301 -> V_112 ) ;
return & V_7 -> V_182 ;
}
static int F_132 ( struct V_6 * V_7 , struct V_321 * V_322 , int V_323 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_255 * V_256 = V_2 -> V_256 ;
if ( ! F_114 ( V_7 ) )
return - V_297 ;
if ( ! V_256 )
return - V_324 ;
return F_133 ( V_256 , V_322 , V_323 ) ;
}
static void * F_134 ( struct V_1 * V_2 ,
int V_179 )
{
return F_135 ( V_2 , V_325 ) + ( V_179 / 8 * 4 ) ;
}
static T_1 F_136 ( int V_179 )
{
return 0x0f << ( 28 - ( ( V_179 % 8 ) * 4 ) ) ;
}
static T_1 F_137 ( struct V_1 * V_2 , int V_179 )
{
return ( 0x08 >> ( V_2 -> V_326 << 1 ) ) << ( 28 - ( ( V_179 % 8 ) * 4 ) ) ;
}
static void F_138 ( struct V_6 * V_7 ,
int V_179 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_327 ;
void * V_3 ;
V_3 = F_134 ( V_2 , V_179 ) ;
V_327 = F_13 ( V_3 ) ;
F_16 ( V_327 | F_137 ( V_2 , V_179 ) , V_3 ) ;
}
static bool F_139 ( struct V_6 * V_7 ,
int V_179 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_328 , V_329 , V_327 ;
void * V_3 ;
V_3 = F_134 ( V_2 , V_179 ) ;
V_328 = F_136 ( V_179 ) ;
V_329 = F_137 ( V_2 , V_179 ) & ~ V_328 ;
V_327 = F_13 ( V_3 ) ;
F_16 ( V_327 & ~ V_328 , V_3 ) ;
return V_327 & V_329 ;
}
static int F_140 ( struct V_6 * V_7 )
{
int V_330 = V_331 * 100 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
while ( ( F_141 ( V_2 , V_332 ) & V_333 ) ) {
F_142 ( 10 ) ;
V_330 -- ;
if ( V_330 <= 0 ) {
F_25 ( V_7 , L_20 , V_300 ) ;
return - V_51 ;
}
}
return 0 ;
}
static int F_143 ( struct V_6 * V_7 , void * V_334 ,
const T_6 * V_84 )
{
T_1 V_134 ;
V_134 = V_84 [ 0 ] << 24 | V_84 [ 1 ] << 16 | V_84 [ 2 ] << 8 | V_84 [ 3 ] ;
F_16 ( V_134 , V_334 ) ;
if ( F_140 ( V_7 ) < 0 )
return - V_335 ;
V_134 = V_84 [ 4 ] << 8 | V_84 [ 5 ] ;
F_16 ( V_134 , V_334 + 4 ) ;
if ( F_140 ( V_7 ) < 0 )
return - V_335 ;
return 0 ;
}
static void F_144 ( void * V_334 , T_6 * V_84 )
{
T_1 V_134 ;
V_134 = F_13 ( V_334 ) ;
V_84 [ 0 ] = ( V_134 >> 24 ) & 0xff ;
V_84 [ 1 ] = ( V_134 >> 16 ) & 0xff ;
V_84 [ 2 ] = ( V_134 >> 8 ) & 0xff ;
V_84 [ 3 ] = V_134 & 0xff ;
V_134 = F_13 ( V_334 + 4 ) ;
V_84 [ 4 ] = ( V_134 >> 8 ) & 0xff ;
V_84 [ 5 ] = V_134 & 0xff ;
}
static int F_145 ( struct V_6 * V_7 , const T_6 * V_84 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
void * V_3 = F_135 ( V_2 , V_336 ) ;
int V_21 ;
T_6 V_337 [ V_81 ] ;
for ( V_21 = 0 ; V_21 < V_338 ; V_21 ++ , V_3 += 8 ) {
F_144 ( V_3 , V_337 ) ;
if ( F_146 ( V_84 , V_337 ) )
return V_21 ;
}
return - V_266 ;
}
static int F_147 ( struct V_6 * V_7 )
{
T_6 V_339 [ V_81 ] ;
int V_179 ;
memset ( V_339 , 0 , sizeof( V_339 ) ) ;
V_179 = F_145 ( V_7 , V_339 ) ;
return ( V_179 < 0 ) ? - V_129 : V_179 ;
}
static int F_148 ( struct V_6 * V_7 ,
int V_179 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
void * V_3 = F_135 ( V_2 , V_336 ) ;
int V_48 ;
T_6 V_339 [ V_81 ] ;
F_20 ( V_2 , F_141 ( V_2 , V_340 ) &
~ ( 1 << ( 31 - V_179 ) ) , V_340 ) ;
memset ( V_339 , 0 , sizeof( V_339 ) ) ;
V_48 = F_143 ( V_7 , V_3 + V_179 * 8 , V_339 ) ;
if ( V_48 < 0 )
return V_48 ;
return 0 ;
}
static int F_149 ( struct V_6 * V_7 , const T_6 * V_84 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
void * V_3 = F_135 ( V_2 , V_336 ) ;
int V_21 , V_48 ;
if ( ! V_2 -> V_32 -> V_341 )
return 0 ;
V_21 = F_145 ( V_7 , V_84 ) ;
if ( V_21 < 0 ) {
V_21 = F_147 ( V_7 ) ;
if ( V_21 < 0 )
return - V_129 ;
V_48 = F_143 ( V_7 , V_3 + V_21 * 8 , V_84 ) ;
if ( V_48 < 0 )
return V_48 ;
F_20 ( V_2 , F_141 ( V_2 , V_340 ) |
( 1 << ( 31 - V_21 ) ) , V_340 ) ;
}
F_138 ( V_7 , V_21 ) ;
return 0 ;
}
static int F_150 ( struct V_6 * V_7 , const T_6 * V_84 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 , V_48 ;
if ( ! V_2 -> V_32 -> V_341 )
return 0 ;
V_21 = F_145 ( V_7 , V_84 ) ;
if ( V_21 ) {
if ( F_139 ( V_7 , V_21 ) )
goto V_342;
V_48 = F_148 ( V_7 , V_21 ) ;
if ( V_48 < 0 )
return V_48 ;
}
V_342:
return 0 ;
}
static int F_151 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 , V_48 ;
if ( F_152 ( ! V_2 -> V_32 -> V_341 ) )
return 0 ;
for ( V_21 = 0 ; V_21 < V_338 ; V_21 ++ ) {
if ( F_139 ( V_7 , V_21 ) )
continue;
V_48 = F_148 ( V_7 , V_21 ) ;
if ( V_48 < 0 )
return V_48 ;
}
return 0 ;
}
static void F_153 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_6 V_84 [ V_81 ] ;
void * V_3 = F_135 ( V_2 , V_336 ) ;
int V_21 ;
if ( F_152 ( ! V_2 -> V_32 -> V_341 ) )
return;
for ( V_21 = 0 ; V_21 < V_338 ; V_21 ++ , V_3 += 8 ) {
F_144 ( V_3 , V_84 ) ;
if ( F_154 ( V_84 ) )
F_150 ( V_7 , V_84 ) ;
}
}
static void F_155 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_343 ;
int V_344 = 0 ;
unsigned long V_276 ;
F_100 ( & V_2 -> V_247 , V_276 ) ;
V_343 = ( F_8 ( V_7 , V_15 ) & ~ V_345 ) | V_346 ;
if ( ! ( V_7 -> V_276 & V_347 ) ) {
F_153 ( V_7 ) ;
V_344 = 1 ;
}
if ( V_7 -> V_276 & V_348 ) {
F_153 ( V_7 ) ;
V_343 &= ~ V_346 ;
V_344 = 1 ;
}
if ( V_7 -> V_276 & V_349 ) {
F_151 ( V_7 ) ;
V_343 = ( V_343 & ~ V_346 ) | V_345 ;
} else if ( V_2 -> V_32 -> V_341 ) {
struct V_350 * V_351 ;
F_156 (ha, ndev) {
if ( V_344 && F_154 ( V_351 -> V_84 ) )
continue;
if ( F_149 ( V_7 , V_351 -> V_84 ) < 0 ) {
if ( ! V_344 ) {
F_153 ( V_7 ) ;
V_343 &= ~ V_346 ;
V_344 = 1 ;
}
}
}
} else {
V_343 = ( V_343 & ~ V_345 ) | V_346 ;
}
F_6 ( V_7 , V_343 , V_15 ) ;
F_102 ( & V_2 -> V_247 , V_276 ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_326 )
return V_352 ;
else
return V_353 ;
}
static int F_158 ( struct V_6 * V_7 ,
T_7 V_354 , T_3 V_355 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_356 = F_157 ( V_2 ) ;
if ( F_152 ( ! V_2 -> V_32 -> V_341 ) )
return - V_357 ;
if ( ! V_355 )
return 0 ;
V_2 -> V_358 ++ ;
if ( V_2 -> V_358 > 1 ) {
F_20 ( V_2 , 0 , V_356 ) ;
return 0 ;
}
F_20 ( V_2 , V_359 | ( V_355 & V_360 ) ,
V_356 ) ;
return 0 ;
}
static int F_159 ( struct V_6 * V_7 ,
T_7 V_354 , T_3 V_355 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_356 = F_157 ( V_2 ) ;
if ( F_152 ( ! V_2 -> V_32 -> V_341 ) )
return - V_357 ;
if ( ! V_355 )
return 0 ;
V_2 -> V_358 -- ;
F_20 ( V_2 , 0 , V_356 ) ;
return 0 ;
}
static void F_160 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
F_20 ( V_2 , 0 , V_340 ) ;
return;
}
F_20 ( V_2 , 0 , V_361 ) ;
F_20 ( V_2 , 0 , V_362 ) ;
F_20 ( V_2 , 0 , V_363 ) ;
F_20 ( V_2 , 0xc , V_364 ) ;
F_20 ( V_2 , 0xc , V_365 ) ;
F_20 ( V_2 , 0 , V_366 ) ;
F_20 ( V_2 , 0 , V_367 ) ;
F_20 ( V_2 , 0 , V_368 ) ;
F_20 ( V_2 , 0 , V_369 ) ;
F_20 ( V_2 , V_370 | V_371 , V_372 ) ;
if ( F_1 ( V_2 ) ) {
F_20 ( V_2 , 0 , V_373 ) ;
F_20 ( V_2 , 0 , V_374 ) ;
} else {
F_20 ( V_2 , 0 , V_375 ) ;
F_20 ( V_2 , 0 , V_376 ) ;
}
F_20 ( V_2 , 0 , V_377 ) ;
F_20 ( V_2 , 0 , V_378 ) ;
F_20 ( V_2 , 0 , V_340 ) ;
F_20 ( V_2 , 0 , V_325 ) ;
F_20 ( V_2 , 0 , V_379 ) ;
F_20 ( V_2 , 0 , V_380 ) ;
F_20 ( V_2 , 0 , V_381 ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
F_162 ( V_2 -> V_270 ) ;
F_163 ( V_2 -> V_270 ) ;
return 0 ;
}
static int F_164 ( struct V_1 * V_2 ,
struct V_382 * V_383 )
{
int V_48 , V_21 ;
struct V_89 * V_90 ;
struct V_384 * V_301 = V_2 -> V_301 ;
struct V_385 * V_112 = & V_2 -> V_301 -> V_112 ;
V_90 = F_165 ( V_112 , sizeof( struct V_89 ) , V_128 ) ;
if ( ! V_90 )
return - V_129 ;
V_90 -> V_84 = V_2 -> V_84 + V_2 -> V_3 [ V_386 ] ;
V_90 -> V_91 = V_383 -> V_387 ;
V_90 -> V_94 = V_388 ;
V_90 -> V_93 = V_389 ;
V_90 -> V_92 = V_390 ;
V_90 -> V_95 = V_391 ;
V_90 -> V_87 . V_392 = & V_393 ;
V_2 -> V_270 = F_166 ( & V_90 -> V_87 ) ;
if ( ! V_2 -> V_270 )
return - V_129 ;
V_2 -> V_270 -> V_273 = L_21 ;
V_2 -> V_270 -> V_263 = V_112 ;
snprintf ( V_2 -> V_270 -> V_271 , V_268 , L_22 ,
V_301 -> V_273 , V_301 -> V_271 ) ;
V_2 -> V_270 -> V_243 = F_165 ( V_112 , sizeof( int ) * V_394 ,
V_128 ) ;
if ( ! V_2 -> V_270 -> V_243 ) {
V_48 = - V_129 ;
goto V_395;
}
if ( V_112 -> V_264 ) {
V_48 = F_167 ( V_2 -> V_270 , V_112 -> V_264 ) ;
} else {
for ( V_21 = 0 ; V_21 < V_394 ; V_21 ++ )
V_2 -> V_270 -> V_243 [ V_21 ] = V_396 ;
if ( V_383 -> V_397 > 0 )
V_2 -> V_270 -> V_243 [ V_383 -> V_398 ] = V_383 -> V_397 ;
V_48 = F_168 ( V_2 -> V_270 ) ;
}
if ( V_48 )
goto V_395;
return 0 ;
V_395:
F_163 ( V_2 -> V_270 ) ;
return V_48 ;
}
static const T_3 * F_169 ( int V_399 )
{
const T_3 * V_3 = NULL ;
switch ( V_399 ) {
case V_400 :
V_3 = V_4 ;
break;
case V_401 :
V_3 = V_5 ;
break;
case V_402 :
V_3 = V_403 ;
break;
case V_404 :
V_3 = V_405 ;
break;
case V_406 :
V_3 = V_407 ;
break;
default:
break;
}
return V_3 ;
}
static struct V_382 * F_170 ( struct V_385 * V_112 )
{
struct V_261 * V_262 = V_112 -> V_264 ;
struct V_382 * V_408 ;
const char * V_409 ;
V_408 = F_165 ( V_112 , sizeof( * V_408 ) , V_128 ) ;
if ( ! V_408 )
return NULL ;
V_408 -> V_9 = F_171 ( V_262 ) ;
V_409 = F_172 ( V_262 ) ;
if ( V_409 )
memcpy ( V_408 -> V_409 , V_409 , V_81 ) ;
V_408 -> V_220 =
F_173 ( V_262 , L_23 ) ;
V_408 -> V_223 =
F_173 ( V_262 , L_24 ) ;
return V_408 ;
}
static inline struct V_382 * F_170 ( struct V_385 * V_112 )
{
return NULL ;
}
static int F_174 ( struct V_384 * V_301 )
{
int V_48 , V_410 = 0 ;
struct V_411 * V_412 ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_382 * V_383 = F_175 ( & V_301 -> V_112 ) ;
const struct V_413 * V_271 = F_176 ( V_301 ) ;
V_412 = F_177 ( V_301 , V_414 , 0 ) ;
if ( F_152 ( V_412 == NULL ) ) {
F_178 ( & V_301 -> V_112 , L_25 ) ;
return - V_297 ;
}
V_7 = F_179 ( sizeof( struct V_1 ) ) ;
if ( ! V_7 )
return - V_129 ;
F_180 ( & V_301 -> V_112 ) ;
F_118 ( & V_301 -> V_112 ) ;
V_7 -> V_415 = V_412 -> V_133 ;
V_410 = V_301 -> V_271 ;
if ( V_410 < 0 )
V_410 = 0 ;
V_7 -> V_416 = - 1 ;
V_48 = F_181 ( V_301 , 0 ) ;
if ( V_48 < 0 ) {
V_48 = - V_324 ;
goto V_417;
}
V_7 -> V_243 = V_48 ;
F_182 ( V_7 , & V_301 -> V_112 ) ;
V_2 = F_4 ( V_7 ) ;
V_2 -> V_99 = V_418 ;
V_2 -> V_97 = V_419 ;
V_2 -> V_84 = F_183 ( & V_301 -> V_112 , V_412 ) ;
if ( F_94 ( V_2 -> V_84 ) ) {
V_48 = F_95 ( V_2 -> V_84 ) ;
goto V_417;
}
F_184 ( & V_2 -> V_247 ) ;
V_2 -> V_301 = V_301 ;
if ( V_301 -> V_112 . V_264 )
V_383 = F_170 ( & V_301 -> V_112 ) ;
if ( ! V_383 ) {
F_178 ( & V_301 -> V_112 , L_26 ) ;
V_48 = - V_297 ;
goto V_417;
}
V_2 -> V_267 = V_383 -> V_398 ;
V_2 -> V_9 = V_383 -> V_9 ;
V_2 -> V_74 = V_383 -> V_74 ;
V_2 -> V_220 = V_383 -> V_220 ;
V_2 -> V_223 = V_383 -> V_223 ;
if ( V_271 ) {
V_2 -> V_32 = (struct V_31 * ) V_271 -> V_420 ;
} else {
const struct V_421 * V_422 ;
V_422 = F_185 ( F_186 ( V_423 ) ,
& V_301 -> V_112 ) ;
V_2 -> V_32 = (struct V_31 * ) V_422 -> V_71 ;
}
V_2 -> V_3 = F_169 ( V_2 -> V_32 -> V_399 ) ;
if ( ! V_2 -> V_3 ) {
F_178 ( & V_301 -> V_112 , L_27 ,
V_2 -> V_32 -> V_399 ) ;
V_48 = - V_297 ;
goto V_417;
}
F_23 ( V_2 -> V_32 ) ;
if ( V_2 -> V_32 -> V_341 )
V_7 -> V_424 = & V_425 ;
else
V_7 -> V_424 = & V_426 ;
F_187 ( V_7 , & V_427 ) ;
V_7 -> V_428 = V_429 ;
V_2 -> V_279 = V_430 ;
F_36 ( V_7 , V_383 -> V_409 ) ;
if ( ! F_188 ( V_7 -> V_77 ) ) {
F_189 ( & V_301 -> V_112 ,
L_28 ) ;
F_190 ( V_7 ) ;
}
if ( V_2 -> V_32 -> V_341 ) {
struct V_411 * V_431 ;
V_431 = F_177 ( V_301 , V_414 , 1 ) ;
V_2 -> V_432 = F_183 ( & V_301 -> V_112 , V_431 ) ;
if ( F_94 ( V_2 -> V_432 ) ) {
V_48 = F_95 ( V_2 -> V_432 ) ;
goto V_417;
}
V_2 -> V_326 = V_410 % 2 ;
V_7 -> V_433 = V_434 ;
}
if ( ! V_410 || V_383 -> V_435 ) {
if ( V_2 -> V_32 -> V_436 )
V_2 -> V_32 -> V_436 ( V_7 ) ;
if ( V_2 -> V_32 -> V_341 ) {
F_160 ( V_2 ) ;
}
}
V_48 = F_164 ( V_2 , V_383 ) ;
if ( V_48 ) {
F_178 ( & V_7 -> V_112 , L_29 ) ;
goto V_417;
}
F_191 ( V_7 , & V_2 -> V_251 , F_84 , 64 ) ;
V_48 = F_192 ( V_7 ) ;
if ( V_48 )
goto V_437;
F_96 ( V_7 , L_30 ,
( T_1 ) V_7 -> V_415 , V_7 -> V_77 , V_7 -> V_243 ) ;
F_193 ( & V_301 -> V_112 ) ;
F_194 ( V_301 , V_7 ) ;
return V_48 ;
V_437:
F_195 ( & V_2 -> V_251 ) ;
F_161 ( V_2 ) ;
V_417:
if ( V_7 )
F_196 ( V_7 ) ;
F_193 ( & V_301 -> V_112 ) ;
F_197 ( & V_301 -> V_112 ) ;
return V_48 ;
}
static int F_198 ( struct V_384 * V_301 )
{
struct V_6 * V_7 = F_199 ( V_301 ) ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_200 ( V_7 ) ;
F_195 ( & V_2 -> V_251 ) ;
F_161 ( V_2 ) ;
F_197 ( & V_301 -> V_112 ) ;
F_196 ( V_7 ) ;
return 0 ;
}
static int F_201 ( struct V_385 * V_112 )
{
return 0 ;
}
