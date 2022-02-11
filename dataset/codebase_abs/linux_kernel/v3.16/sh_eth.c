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
}
static int F_24 ( struct V_6 * V_7 )
{
int V_46 = 0 ;
int V_47 = 100 ;
while ( V_47 > 0 ) {
if ( ! ( F_8 ( V_7 , V_48 ) & 0x3 ) )
break;
F_17 ( 1 ) ;
V_47 -- ;
}
if ( V_47 <= 0 ) {
F_25 ( V_7 , L_2 ) ;
V_46 = - V_49 ;
}
return V_46 ;
}
static int F_26 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_46 = 0 ;
if ( F_1 ( V_2 ) || F_2 ( V_2 ) ) {
F_6 ( V_7 , V_50 , V_51 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_48 ) | V_52 ,
V_48 ) ;
V_46 = F_24 ( V_7 ) ;
if ( V_46 )
return V_46 ;
F_6 ( V_7 , 0x0 , V_53 ) ;
F_6 ( V_7 , 0x0 , V_54 ) ;
F_6 ( V_7 , 0x0 , V_55 ) ;
F_6 ( V_7 , 0x0 , V_56 ) ;
F_6 ( V_7 , 0x0 , V_57 ) ;
F_6 ( V_7 , 0x0 , V_58 ) ;
F_6 ( V_7 , 0x0 , V_59 ) ;
F_6 ( V_7 , 0x0 , V_60 ) ;
if ( V_2 -> V_32 -> V_61 )
F_6 ( V_7 , 0x0 , V_62 ) ;
if ( V_2 -> V_32 -> V_63 )
F_3 ( V_7 ) ;
} else {
F_6 ( V_7 , F_8 ( V_7 , V_48 ) | V_64 ,
V_48 ) ;
F_17 ( 3 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_48 ) & ~ V_64 ,
V_48 ) ;
}
return V_46 ;
}
static void F_27 ( struct V_65 * V_66 )
{
int V_67 ;
V_67 = V_68 - ( ( T_1 ) V_66 -> V_69 & ( V_68 - 1 ) ) ;
if ( V_67 )
F_28 ( V_66 , V_67 ) ;
}
static void F_27 ( struct V_65 * V_66 )
{
F_28 ( V_66 , V_70 ) ;
}
static inline T_2 F_29 ( struct V_1 * V_2 , T_1 V_71 )
{
switch ( V_2 -> V_72 ) {
case V_73 :
return F_30 ( V_71 ) ;
case V_74 :
return F_31 ( V_71 ) ;
}
return V_71 ;
}
static inline T_2 F_32 ( struct V_1 * V_2 , T_1 V_71 )
{
switch ( V_2 -> V_72 ) {
case V_73 :
return F_33 ( V_71 ) ;
case V_74 :
return F_34 ( V_71 ) ;
}
return V_71 ;
}
static void F_35 ( struct V_6 * V_7 )
{
F_6 ( V_7 ,
( V_7 -> V_75 [ 0 ] << 24 ) | ( V_7 -> V_75 [ 1 ] << 16 ) |
( V_7 -> V_75 [ 2 ] << 8 ) | ( V_7 -> V_75 [ 3 ] ) , V_76 ) ;
F_6 ( V_7 ,
( V_7 -> V_75 [ 4 ] << 8 ) | ( V_7 -> V_75 [ 5 ] ) , V_77 ) ;
}
static void F_36 ( struct V_6 * V_7 , unsigned char * V_78 )
{
if ( V_78 [ 0 ] || V_78 [ 1 ] || V_78 [ 2 ] || V_78 [ 3 ] || V_78 [ 4 ] || V_78 [ 5 ] ) {
memcpy ( V_7 -> V_75 , V_78 , V_79 ) ;
} else {
V_7 -> V_75 [ 0 ] = ( F_8 ( V_7 , V_76 ) >> 24 ) ;
V_7 -> V_75 [ 1 ] = ( F_8 ( V_7 , V_76 ) >> 16 ) & 0xFF ;
V_7 -> V_75 [ 2 ] = ( F_8 ( V_7 , V_76 ) >> 8 ) & 0xFF ;
V_7 -> V_75 [ 3 ] = ( F_8 ( V_7 , V_76 ) & 0xFF ) ;
V_7 -> V_75 [ 4 ] = ( F_8 ( V_7 , V_77 ) >> 8 ) & 0xFF ;
V_7 -> V_75 [ 5 ] = ( F_8 ( V_7 , V_77 ) & 0xFF ) ;
}
}
static unsigned long F_37 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) || F_2 ( V_2 ) )
return V_80 ;
else
return V_81 ;
}
static void F_38 ( void * V_82 , T_1 V_83 )
{
F_16 ( F_13 ( V_82 ) | V_83 , V_82 ) ;
}
static void F_39 ( void * V_82 , T_1 V_83 )
{
F_16 ( ( F_13 ( V_82 ) & ~ V_83 ) , V_82 ) ;
}
static int F_40 ( void * V_82 , T_1 V_83 )
{
return ( F_13 ( V_82 ) & V_83 ) != 0 ;
}
static void F_41 ( struct V_84 * V_85 , int V_86 )
{
struct V_87 * V_88 = F_42 ( V_85 , struct V_87 , V_85 ) ;
if ( V_88 -> V_89 )
V_88 -> V_89 ( V_88 -> V_82 ) ;
if ( V_86 )
F_38 ( V_88 -> V_82 , V_88 -> V_90 ) ;
else
F_39 ( V_88 -> V_82 , V_88 -> V_90 ) ;
}
static void F_43 ( struct V_84 * V_85 , int V_86 )
{
struct V_87 * V_88 = F_42 ( V_85 , struct V_87 , V_85 ) ;
if ( V_88 -> V_89 )
V_88 -> V_89 ( V_88 -> V_82 ) ;
if ( V_86 )
F_38 ( V_88 -> V_82 , V_88 -> V_91 ) ;
else
F_39 ( V_88 -> V_82 , V_88 -> V_91 ) ;
}
static int F_44 ( struct V_84 * V_85 )
{
struct V_87 * V_88 = F_42 ( V_85 , struct V_87 , V_85 ) ;
if ( V_88 -> V_89 )
V_88 -> V_89 ( V_88 -> V_82 ) ;
return F_40 ( V_88 -> V_82 , V_88 -> V_92 ) ;
}
static void F_45 ( struct V_84 * V_85 , int V_86 )
{
struct V_87 * V_88 = F_42 ( V_85 , struct V_87 , V_85 ) ;
if ( V_88 -> V_89 )
V_88 -> V_89 ( V_88 -> V_82 ) ;
if ( V_86 )
F_38 ( V_88 -> V_82 , V_88 -> V_93 ) ;
else
F_39 ( V_88 -> V_82 , V_88 -> V_93 ) ;
}
static void F_46 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 ;
if ( V_2 -> V_94 ) {
for ( V_21 = 0 ; V_21 < V_2 -> V_95 ; V_21 ++ ) {
if ( V_2 -> V_94 [ V_21 ] )
F_47 ( V_2 -> V_94 [ V_21 ] ) ;
}
}
F_48 ( V_2 -> V_94 ) ;
V_2 -> V_94 = NULL ;
if ( V_2 -> V_96 ) {
for ( V_21 = 0 ; V_21 < V_2 -> V_97 ; V_21 ++ ) {
if ( V_2 -> V_96 [ V_21 ] )
F_47 ( V_2 -> V_96 [ V_21 ] ) ;
}
}
F_48 ( V_2 -> V_96 ) ;
V_2 -> V_96 = NULL ;
}
static void F_49 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 ;
struct V_65 * V_66 ;
struct V_98 * V_99 = NULL ;
struct V_100 * V_101 = NULL ;
int V_102 = sizeof( * V_99 ) * V_2 -> V_95 ;
int V_103 = sizeof( * V_101 ) * V_2 -> V_97 ;
V_2 -> V_104 = 0 ;
V_2 -> V_105 = 0 ;
V_2 -> V_106 = 0 ;
V_2 -> V_107 = 0 ;
memset ( V_2 -> V_108 , 0 , V_102 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_95 ; V_21 ++ ) {
V_2 -> V_94 [ V_21 ] = NULL ;
V_66 = F_50 ( V_7 , V_2 -> V_109 ) ;
V_2 -> V_94 [ V_21 ] = V_66 ;
if ( V_66 == NULL )
break;
F_51 ( & V_7 -> V_110 , V_66 -> V_69 , V_2 -> V_109 ,
V_111 ) ;
F_27 ( V_66 ) ;
V_99 = & V_2 -> V_108 [ V_21 ] ;
V_99 -> V_82 = F_52 ( F_53 ( V_66 -> V_69 , 4 ) ) ;
V_99 -> V_112 = F_29 ( V_2 , V_113 | V_114 ) ;
V_99 -> V_115 = F_54 ( V_2 -> V_109 , 16 ) ;
if ( V_21 == 0 ) {
F_6 ( V_7 , V_2 -> V_116 , V_57 ) ;
if ( F_1 ( V_2 ) ||
F_2 ( V_2 ) )
F_6 ( V_7 , V_2 -> V_116 , V_58 ) ;
}
}
V_2 -> V_106 = ( T_1 ) ( V_21 - V_2 -> V_95 ) ;
V_99 -> V_112 |= F_29 ( V_2 , V_117 ) ;
memset ( V_2 -> V_118 , 0 , V_103 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_97 ; V_21 ++ ) {
V_2 -> V_96 [ V_21 ] = NULL ;
V_101 = & V_2 -> V_118 [ V_21 ] ;
V_101 -> V_112 = F_29 ( V_2 , V_119 ) ;
V_101 -> V_115 = 0 ;
if ( V_21 == 0 ) {
F_6 ( V_7 , V_2 -> V_120 , V_53 ) ;
if ( F_1 ( V_2 ) ||
F_2 ( V_2 ) )
F_6 ( V_7 , V_2 -> V_120 , V_54 ) ;
}
}
V_101 -> V_112 |= F_29 ( V_2 , V_121 ) ;
}
static int F_55 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_102 , V_103 , V_46 = 0 ;
V_2 -> V_109 = ( V_7 -> V_122 <= 1492 ? V_123 :
( ( ( V_7 -> V_122 + 26 + 7 ) & ~ 7 ) + 2 + 16 ) ) ;
if ( V_2 -> V_32 -> V_124 )
V_2 -> V_109 += V_125 ;
V_2 -> V_94 = F_56 ( V_2 -> V_95 ,
sizeof( * V_2 -> V_94 ) , V_126 ) ;
if ( ! V_2 -> V_94 ) {
V_46 = - V_127 ;
return V_46 ;
}
V_2 -> V_96 = F_56 ( V_2 -> V_97 ,
sizeof( * V_2 -> V_96 ) , V_126 ) ;
if ( ! V_2 -> V_96 ) {
V_46 = - V_127 ;
goto V_128;
}
V_102 = sizeof( struct V_98 ) * V_2 -> V_95 ;
V_2 -> V_108 = F_57 ( NULL , V_102 , & V_2 -> V_116 ,
V_126 ) ;
if ( ! V_2 -> V_108 ) {
V_46 = - V_127 ;
goto V_129;
}
V_2 -> V_106 = 0 ;
V_103 = sizeof( struct V_100 ) * V_2 -> V_97 ;
V_2 -> V_118 = F_57 ( NULL , V_103 , & V_2 -> V_120 ,
V_126 ) ;
if ( ! V_2 -> V_118 ) {
V_46 = - V_127 ;
goto V_129;
}
return V_46 ;
V_129:
F_58 ( NULL , V_102 , V_2 -> V_108 , V_2 -> V_116 ) ;
V_128:
F_46 ( V_7 ) ;
V_2 -> V_118 = NULL ;
V_2 -> V_108 = NULL ;
return V_46 ;
}
static void F_59 ( struct V_1 * V_2 )
{
int V_130 ;
if ( V_2 -> V_108 ) {
V_130 = sizeof( struct V_98 ) * V_2 -> V_95 ;
F_58 ( NULL , V_130 , V_2 -> V_108 ,
V_2 -> V_116 ) ;
V_2 -> V_108 = NULL ;
}
if ( V_2 -> V_118 ) {
V_130 = sizeof( struct V_100 ) * V_2 -> V_97 ;
F_58 ( NULL , V_130 , V_2 -> V_118 ,
V_2 -> V_120 ) ;
V_2 -> V_118 = NULL ;
}
}
static int F_60 ( struct V_6 * V_7 , bool V_131 )
{
int V_46 = 0 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_132 ;
V_46 = F_26 ( V_7 ) ;
if ( V_46 )
return V_46 ;
if ( V_2 -> V_32 -> V_133 )
F_6 ( V_7 , 0x1 , V_134 ) ;
F_49 ( V_7 ) ;
if ( V_2 -> V_32 -> V_124 )
F_6 ( V_7 , V_2 -> V_32 -> V_135 , V_136 ) ;
F_6 ( V_7 , 0 , V_137 ) ;
#if F_61 ( V_138 )
if ( V_2 -> V_32 -> V_139 )
F_6 ( V_7 , V_140 , V_48 ) ;
else
#endif
F_6 ( V_7 , 0 , V_48 ) ;
F_6 ( V_7 , V_2 -> V_32 -> V_40 , V_141 ) ;
F_6 ( V_7 , 0 , V_142 ) ;
F_6 ( V_7 , V_143 , V_144 ) ;
F_6 ( V_7 , V_145 | V_146 | V_147 , V_148 ) ;
if ( V_2 -> V_32 -> V_149 )
F_6 ( V_7 , 0x800 , V_150 ) ;
F_6 ( V_7 , V_2 -> V_32 -> V_37 , V_151 ) ;
if ( ! V_2 -> V_32 -> V_152 )
F_6 ( V_7 , 0 , V_153 ) ;
F_6 ( V_7 , V_7 -> V_122 + V_154 + V_155 + V_156 ,
V_157 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_158 ) , V_158 ) ;
if ( V_131 )
F_6 ( V_7 , V_2 -> V_32 -> V_159 , V_137 ) ;
V_132 = ( F_8 ( V_7 , V_15 ) & V_16 ) |
V_160 | ( V_2 -> V_14 ? V_16 : 0 ) | V_161 | V_162 ;
F_6 ( V_7 , V_132 , V_15 ) ;
if ( V_2 -> V_32 -> V_163 )
V_2 -> V_32 -> V_163 ( V_7 ) ;
F_6 ( V_7 , V_2 -> V_32 -> V_33 , V_164 ) ;
if ( V_131 )
F_6 ( V_7 , V_2 -> V_32 -> V_35 , V_165 ) ;
F_35 ( V_7 ) ;
if ( V_2 -> V_32 -> V_166 )
F_6 ( V_7 , V_167 , V_168 ) ;
if ( V_2 -> V_32 -> V_169 )
F_6 ( V_7 , V_170 , V_171 ) ;
if ( V_2 -> V_32 -> V_172 )
F_6 ( V_7 , V_173 , V_174 ) ;
if ( V_131 ) {
F_6 ( V_7 , V_175 , V_176 ) ;
F_62 ( V_7 ) ;
}
return V_46 ;
}
static int F_63 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_100 * V_101 ;
int V_177 = 0 ;
int V_178 = 0 ;
for (; V_2 -> V_105 - V_2 -> V_107 > 0 ; V_2 -> V_107 ++ ) {
V_178 = V_2 -> V_107 % V_2 -> V_97 ;
V_101 = & V_2 -> V_118 [ V_178 ] ;
if ( V_101 -> V_112 & F_29 ( V_2 , V_179 ) )
break;
if ( V_2 -> V_96 [ V_178 ] ) {
F_64 ( & V_7 -> V_110 , V_101 -> V_82 ,
V_101 -> V_115 , V_180 ) ;
F_65 ( V_2 -> V_96 [ V_178 ] ) ;
V_2 -> V_96 [ V_178 ] = NULL ;
V_177 ++ ;
}
V_101 -> V_112 = F_29 ( V_2 , V_119 ) ;
if ( V_178 >= V_2 -> V_97 - 1 )
V_101 -> V_112 |= F_29 ( V_2 , V_121 ) ;
V_7 -> V_181 . V_182 ++ ;
V_7 -> V_181 . V_183 += V_101 -> V_115 ;
}
return V_177 ;
}
static int F_66 ( struct V_6 * V_7 , T_1 V_184 , int * V_185 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_98 * V_99 ;
int V_178 = V_2 -> V_104 % V_2 -> V_95 ;
int V_186 = ( V_2 -> V_106 + V_2 -> V_95 ) - V_2 -> V_104 ;
struct V_65 * V_66 ;
T_3 V_187 = 0 ;
T_1 V_188 ;
V_99 = & V_2 -> V_108 [ V_178 ] ;
while ( ! ( V_99 -> V_112 & F_29 ( V_2 , V_113 ) ) ) {
V_188 = F_32 ( V_2 , V_99 -> V_112 ) ;
V_187 = V_99 -> V_189 ;
if ( -- V_186 < 0 )
break;
if ( * V_185 <= 0 )
break;
( * V_185 ) -- ;
if ( ! ( V_188 & V_190 ) )
V_7 -> V_181 . V_191 ++ ;
if ( V_2 -> V_32 -> V_192 )
V_188 >>= 16 ;
if ( V_188 & ( V_193 | V_194 | V_195 | V_196 |
V_197 | V_198 | V_199 ) ) {
V_7 -> V_181 . V_200 ++ ;
if ( V_188 & V_193 )
V_7 -> V_181 . V_201 ++ ;
if ( V_188 & V_194 )
V_7 -> V_181 . V_202 ++ ;
if ( V_188 & V_195 )
V_7 -> V_181 . V_191 ++ ;
if ( V_188 & V_196 )
V_7 -> V_181 . V_191 ++ ;
if ( V_188 & V_198 )
V_7 -> V_181 . V_203 ++ ;
if ( V_188 & V_199 )
V_7 -> V_181 . V_204 ++ ;
} else {
if ( ! V_2 -> V_32 -> V_139 )
F_67 (
F_68 ( F_54 ( V_99 -> V_82 , 4 ) ) ,
V_187 + 2 ) ;
V_66 = V_2 -> V_94 [ V_178 ] ;
V_2 -> V_94 [ V_178 ] = NULL ;
if ( V_2 -> V_32 -> V_124 )
F_28 ( V_66 , V_125 ) ;
F_69 ( & V_7 -> V_110 , V_99 -> V_82 ,
V_2 -> V_109 ,
V_111 ) ;
F_70 ( V_66 , V_187 ) ;
V_66 -> V_205 = F_71 ( V_66 , V_7 ) ;
F_72 ( V_66 ) ;
V_7 -> V_181 . V_206 ++ ;
V_7 -> V_181 . V_207 += V_187 ;
}
V_178 = ( ++ V_2 -> V_104 ) % V_2 -> V_95 ;
V_99 = & V_2 -> V_108 [ V_178 ] ;
}
for (; V_2 -> V_104 - V_2 -> V_106 > 0 ; V_2 -> V_106 ++ ) {
V_178 = V_2 -> V_106 % V_2 -> V_95 ;
V_99 = & V_2 -> V_108 [ V_178 ] ;
V_99 -> V_115 = F_54 ( V_2 -> V_109 , 16 ) ;
if ( V_2 -> V_94 [ V_178 ] == NULL ) {
V_66 = F_50 ( V_7 , V_2 -> V_109 ) ;
V_2 -> V_94 [ V_178 ] = V_66 ;
if ( V_66 == NULL )
break;
F_51 ( & V_7 -> V_110 , V_66 -> V_69 , V_2 -> V_109 ,
V_111 ) ;
F_27 ( V_66 ) ;
F_73 ( V_66 ) ;
V_99 -> V_82 = F_52 ( F_53 ( V_66 -> V_69 , 4 ) ) ;
}
if ( V_178 >= V_2 -> V_95 - 1 )
V_99 -> V_112 |=
F_29 ( V_2 , V_113 | V_114 | V_117 ) ;
else
V_99 -> V_112 |=
F_29 ( V_2 , V_113 | V_114 ) ;
}
if ( ! ( F_8 ( V_7 , V_176 ) & V_175 ) ) {
if ( V_184 & V_208 ) {
T_1 V_209 = ( F_8 ( V_7 , V_58 ) -
F_8 ( V_7 , V_57 ) ) >> 4 ;
V_2 -> V_104 = V_209 ;
V_2 -> V_106 = V_209 ;
}
F_6 ( V_7 , V_175 , V_176 ) ;
}
return * V_185 <= 0 ;
}
static void F_74 ( struct V_6 * V_7 )
{
F_6 ( V_7 , F_8 ( V_7 , V_15 ) &
~ ( V_162 | V_161 ) , V_15 ) ;
}
static void F_75 ( struct V_6 * V_7 )
{
F_6 ( V_7 , F_8 ( V_7 , V_15 ) |
( V_162 | V_161 ) , V_15 ) ;
}
static void F_76 ( struct V_6 * V_7 , int V_184 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_210 ;
T_1 V_211 ;
T_1 V_212 ;
if ( V_184 & V_213 ) {
V_210 = F_8 ( V_7 , V_164 ) ;
F_6 ( V_7 , V_210 , V_164 ) ;
if ( V_210 & V_214 )
V_7 -> V_181 . V_215 ++ ;
if ( V_210 & V_216 ) {
if ( V_2 -> V_32 -> V_217 || V_2 -> V_218 ) {
goto V_219;
} else {
V_211 = ( F_8 ( V_7 , V_220 ) ) ;
if ( V_2 -> V_221 )
V_211 = ~ V_211 ;
}
if ( ! ( V_211 & V_222 ) ) {
F_74 ( V_7 ) ;
} else {
F_6 ( V_7 , F_8 ( V_7 , V_137 ) &
~ V_223 , V_137 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_164 ) ,
V_164 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_137 ) |
V_223 , V_137 ) ;
F_75 ( V_7 ) ;
}
}
}
V_219:
if ( V_184 & V_224 ) {
if ( V_184 & V_225 ) {
V_7 -> V_181 . V_226 ++ ;
F_77 ( V_2 , V_227 , V_7 , L_3 ) ;
}
}
if ( V_184 & V_228 ) {
if ( V_184 & V_229 ) {
V_7 -> V_181 . V_202 ++ ;
F_77 ( V_2 , V_230 , V_7 , L_4 ) ;
}
}
if ( V_184 & V_231 ) {
V_7 -> V_181 . V_232 ++ ;
F_77 ( V_2 , V_227 , V_7 , L_5 ) ;
}
if ( V_184 & V_233 ) {
V_7 -> V_181 . V_232 ++ ;
F_77 ( V_2 , V_227 , V_7 , L_6 ) ;
}
if ( V_184 & V_208 ) {
V_7 -> V_181 . V_204 ++ ;
F_77 ( V_2 , V_230 , V_7 , L_7 ) ;
}
if ( V_184 & V_234 ) {
V_7 -> V_181 . V_235 ++ ;
F_77 ( V_2 , V_230 , V_7 , L_8 ) ;
}
if ( ! V_2 -> V_32 -> V_236 && ( V_184 & V_237 ) ) {
V_7 -> V_181 . V_232 ++ ;
F_77 ( V_2 , V_227 , V_7 , L_9 ) ;
}
V_212 = V_224 | V_225 | V_237 | V_231 | V_233 ;
if ( V_2 -> V_32 -> V_236 )
V_212 &= ~ V_237 ;
if ( V_184 & V_212 ) {
T_1 V_238 = F_8 ( V_7 , V_239 ) ;
F_25 ( V_7 , L_10 ,
V_184 , V_2 -> V_105 , V_2 -> V_107 ,
( T_1 ) V_7 -> V_240 , V_238 ) ;
F_63 ( V_7 ) ;
if ( V_238 ^ F_37 ( V_2 ) ) {
F_6 ( V_7 , F_37 ( V_2 ) , V_239 ) ;
}
F_78 ( V_7 ) ;
}
}
static T_4 F_79 ( int V_241 , void * V_242 )
{
struct V_6 * V_7 = V_242 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_31 * V_32 = V_2 -> V_32 ;
T_4 V_46 = V_243 ;
unsigned long V_184 , V_244 ;
F_80 ( & V_2 -> V_245 ) ;
V_184 = F_8 ( V_7 , V_158 ) ;
V_244 = F_8 ( V_7 , V_137 ) ;
V_184 &= V_244 | V_223 ;
if ( V_184 & ( V_246 | V_32 -> V_42 | V_32 -> V_44 ) )
V_46 = V_247 ;
else
goto V_248;
if ( V_184 & V_246 ) {
if ( F_81 ( & V_2 -> V_249 ) ) {
F_6 ( V_7 , V_244 & ~ V_246 ,
V_137 ) ;
F_82 ( & V_2 -> V_249 ) ;
} else {
F_5 ( V_7 ,
L_11 ,
V_184 , V_244 ) ;
}
}
if ( V_184 & V_32 -> V_42 ) {
F_6 ( V_7 , V_184 & V_32 -> V_42 , V_158 ) ;
F_63 ( V_7 ) ;
F_78 ( V_7 ) ;
}
if ( V_184 & V_32 -> V_44 ) {
F_6 ( V_7 , V_184 & V_32 -> V_44 , V_158 ) ;
F_76 ( V_7 , V_184 ) ;
}
V_248:
F_83 ( & V_2 -> V_245 ) ;
return V_46 ;
}
static int F_84 ( struct V_250 * V_249 , int V_251 )
{
struct V_1 * V_2 = F_42 ( V_249 , struct V_1 ,
V_249 ) ;
struct V_6 * V_7 = V_249 -> V_110 ;
int V_185 = V_251 ;
unsigned long V_184 ;
for (; ; ) {
V_184 = F_8 ( V_7 , V_158 ) ;
if ( ! ( V_184 & V_246 ) )
break;
F_6 ( V_7 , V_184 & V_246 , V_158 ) ;
if ( F_66 ( V_7 , V_184 , & V_185 ) )
goto V_252;
}
F_85 ( V_249 ) ;
F_6 ( V_7 , V_2 -> V_32 -> V_159 , V_137 ) ;
V_252:
return V_251 - V_185 ;
}
static void F_86 ( struct V_6 * V_7 )
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
if ( V_2 -> V_32 -> V_163 )
V_2 -> V_32 -> V_163 ( V_7 ) ;
}
if ( ! V_2 -> V_256 ) {
F_6 ( V_7 ,
F_8 ( V_7 , V_15 ) & ~ V_258 ,
V_15 ) ;
V_255 = 1 ;
V_2 -> V_256 = V_254 -> V_256 ;
if ( V_2 -> V_32 -> V_217 || V_2 -> V_218 )
F_75 ( V_7 ) ;
}
} else if ( V_2 -> V_256 ) {
V_255 = 1 ;
V_2 -> V_256 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_14 = - 1 ;
if ( V_2 -> V_32 -> V_217 || V_2 -> V_218 )
F_74 ( V_7 ) ;
}
if ( V_255 && F_87 ( V_2 ) )
F_88 ( V_254 ) ;
}
static int F_89 ( struct V_6 * V_7 )
{
struct V_259 * V_260 = V_7 -> V_110 . V_261 -> V_262 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_253 * V_254 = NULL ;
V_2 -> V_256 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_14 = - 1 ;
if ( V_260 ) {
struct V_259 * V_263 ;
V_263 = F_90 ( V_260 , L_12 , 0 ) ;
V_254 = F_91 ( V_7 , V_263 ,
F_86 , 0 ,
V_2 -> V_9 ) ;
if ( ! V_254 )
V_254 = F_92 ( - V_264 ) ;
} else {
char V_265 [ V_266 + 3 ] ;
snprintf ( V_265 , sizeof( V_265 ) , V_267 ,
V_2 -> V_268 -> V_269 , V_2 -> V_265 ) ;
V_254 = F_93 ( V_7 , V_265 , F_86 ,
V_2 -> V_9 ) ;
}
if ( F_94 ( V_254 ) ) {
F_25 ( V_7 , L_13 ) ;
return F_95 ( V_254 ) ;
}
F_96 ( V_7 , L_14 ,
V_254 -> V_82 , V_254 -> V_241 , V_254 -> V_270 -> V_271 ) ;
V_2 -> V_254 = V_254 ;
return 0 ;
}
static int F_97 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_46 ;
V_46 = F_89 ( V_7 ) ;
if ( V_46 )
return V_46 ;
F_98 ( V_2 -> V_254 ) ;
return 0 ;
}
static int F_99 ( struct V_6 * V_7 ,
struct V_272 * V_273 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
unsigned long V_274 ;
int V_46 ;
F_100 ( & V_2 -> V_245 , V_274 ) ;
V_46 = F_101 ( V_2 -> V_254 , V_273 ) ;
F_102 ( & V_2 -> V_245 , V_274 ) ;
return V_46 ;
}
static int F_103 ( struct V_6 * V_7 ,
struct V_272 * V_273 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
unsigned long V_274 ;
int V_46 ;
F_100 ( & V_2 -> V_245 , V_274 ) ;
F_74 ( V_7 ) ;
V_46 = F_104 ( V_2 -> V_254 , V_273 ) ;
if ( V_46 )
goto V_275;
if ( V_273 -> V_14 == V_276 )
V_2 -> V_14 = 1 ;
else
V_2 -> V_14 = 0 ;
if ( V_2 -> V_32 -> V_257 )
V_2 -> V_32 -> V_257 ( V_7 ) ;
V_275:
F_17 ( 1 ) ;
F_75 ( V_7 ) ;
F_102 ( & V_2 -> V_245 , V_274 ) ;
return V_46 ;
}
static int F_105 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
unsigned long V_274 ;
int V_46 ;
F_100 ( & V_2 -> V_245 , V_274 ) ;
V_46 = F_106 ( V_2 -> V_254 ) ;
F_102 ( & V_2 -> V_245 , V_274 ) ;
return V_46 ;
}
static T_1 F_107 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
return V_2 -> V_277 ;
}
static void F_108 ( struct V_6 * V_7 , T_1 V_8 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
V_2 -> V_277 = V_8 ;
}
static int F_109 ( struct V_6 * V_242 , int V_278 )
{
switch ( V_278 ) {
case V_279 :
return V_280 ;
default:
return - V_281 ;
}
}
static void F_110 ( struct V_6 * V_7 ,
struct V_282 * V_181 , T_5 * V_69 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 = 0 ;
V_69 [ V_21 ++ ] = V_2 -> V_104 ;
V_69 [ V_21 ++ ] = V_2 -> V_105 ;
V_69 [ V_21 ++ ] = V_2 -> V_106 ;
V_69 [ V_21 ++ ] = V_2 -> V_107 ;
}
static void F_111 ( struct V_6 * V_7 , T_1 V_283 , T_6 * V_69 )
{
switch ( V_283 ) {
case V_279 :
memcpy ( V_69 , * V_284 ,
sizeof( V_284 ) ) ;
break;
}
}
static void F_112 ( struct V_6 * V_7 ,
struct V_285 * V_286 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
V_286 -> V_287 = V_288 ;
V_286 -> V_289 = V_290 ;
V_286 -> V_291 = V_2 -> V_95 ;
V_286 -> V_292 = V_2 -> V_97 ;
}
static int F_113 ( struct V_6 * V_7 ,
struct V_285 * V_286 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_46 ;
if ( V_286 -> V_292 > V_290 ||
V_286 -> V_291 > V_288 ||
V_286 -> V_292 < V_293 ||
V_286 -> V_291 < V_294 )
return - V_295 ;
if ( V_286 -> V_296 || V_286 -> V_297 )
return - V_295 ;
if ( F_114 ( V_7 ) ) {
F_115 ( V_7 ) ;
F_6 ( V_7 , 0x0000 , V_137 ) ;
F_6 ( V_7 , 0 , V_239 ) ;
F_6 ( V_7 , 0 , V_176 ) ;
F_116 ( V_7 -> V_241 ) ;
}
F_46 ( V_7 ) ;
F_59 ( V_2 ) ;
V_2 -> V_95 = V_286 -> V_291 ;
V_2 -> V_97 = V_286 -> V_292 ;
V_46 = F_55 ( V_7 ) ;
if ( V_46 < 0 ) {
F_25 ( V_7 , L_15 , V_298 ) ;
return V_46 ;
}
V_46 = F_60 ( V_7 , false ) ;
if ( V_46 < 0 ) {
F_25 ( V_7 , L_16 , V_298 ) ;
return V_46 ;
}
if ( F_114 ( V_7 ) ) {
F_6 ( V_7 , V_2 -> V_32 -> V_159 , V_137 ) ;
F_6 ( V_7 , V_175 , V_176 ) ;
F_78 ( V_7 ) ;
}
return 0 ;
}
static int F_117 ( struct V_6 * V_7 )
{
int V_46 = 0 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_118 ( & V_2 -> V_299 -> V_110 ) ;
F_119 ( & V_2 -> V_249 ) ;
V_46 = F_120 ( V_7 -> V_241 , F_79 ,
V_2 -> V_32 -> V_300 , V_7 -> V_271 , V_7 ) ;
if ( V_46 ) {
F_25 ( V_7 , L_17 ) ;
goto V_301;
}
V_46 = F_55 ( V_7 ) ;
if ( V_46 )
goto V_302;
V_46 = F_60 ( V_7 , true ) ;
if ( V_46 )
goto V_302;
V_46 = F_97 ( V_7 ) ;
if ( V_46 )
goto V_302;
return V_46 ;
V_302:
F_121 ( V_7 -> V_241 , V_7 ) ;
V_301:
F_122 ( & V_2 -> V_249 ) ;
F_123 ( & V_2 -> V_299 -> V_110 ) ;
return V_46 ;
}
static void F_124 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_98 * V_99 ;
int V_21 ;
F_125 ( V_7 ) ;
F_77 ( V_2 , V_303 , V_7 ,
L_18 ,
( int ) F_8 ( V_7 , V_158 ) ) ;
V_7 -> V_181 . V_304 ++ ;
for ( V_21 = 0 ; V_21 < V_2 -> V_95 ; V_21 ++ ) {
V_99 = & V_2 -> V_108 [ V_21 ] ;
V_99 -> V_112 = 0 ;
V_99 -> V_82 = 0xBADF00D0 ;
if ( V_2 -> V_94 [ V_21 ] )
F_47 ( V_2 -> V_94 [ V_21 ] ) ;
V_2 -> V_94 [ V_21 ] = NULL ;
}
for ( V_21 = 0 ; V_21 < V_2 -> V_97 ; V_21 ++ ) {
if ( V_2 -> V_96 [ V_21 ] )
F_47 ( V_2 -> V_96 [ V_21 ] ) ;
V_2 -> V_96 [ V_21 ] = NULL ;
}
F_60 ( V_7 , true ) ;
}
static int F_126 ( struct V_65 * V_66 , struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_100 * V_101 ;
T_1 V_178 ;
unsigned long V_274 ;
F_100 ( & V_2 -> V_245 , V_274 ) ;
if ( ( V_2 -> V_105 - V_2 -> V_107 ) >= ( V_2 -> V_97 - 4 ) ) {
if ( ! F_63 ( V_7 ) ) {
F_127 ( V_2 , V_305 , V_7 , L_19 ) ;
F_125 ( V_7 ) ;
F_102 ( & V_2 -> V_245 , V_274 ) ;
return V_306 ;
}
}
F_102 ( & V_2 -> V_245 , V_274 ) ;
V_178 = V_2 -> V_105 % V_2 -> V_97 ;
V_2 -> V_96 [ V_178 ] = V_66 ;
V_101 = & V_2 -> V_118 [ V_178 ] ;
if ( ! V_2 -> V_32 -> V_139 )
F_67 ( F_68 ( F_54 ( V_101 -> V_82 , 4 ) ) ,
V_66 -> V_307 + 2 ) ;
V_101 -> V_82 = F_51 ( & V_7 -> V_110 , V_66 -> V_69 , V_66 -> V_307 ,
V_180 ) ;
if ( V_66 -> V_307 < V_308 )
V_101 -> V_115 = V_308 ;
else
V_101 -> V_115 = V_66 -> V_307 ;
if ( V_178 >= V_2 -> V_97 - 1 )
V_101 -> V_112 |= F_29 ( V_2 , V_179 | V_121 ) ;
else
V_101 -> V_112 |= F_29 ( V_2 , V_179 ) ;
V_2 -> V_105 ++ ;
if ( ! ( F_8 ( V_7 , V_239 ) & F_37 ( V_2 ) ) )
F_6 ( V_7 , F_37 ( V_2 ) , V_239 ) ;
return V_309 ;
}
static int F_128 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_125 ( V_7 ) ;
F_6 ( V_7 , 0x0000 , V_137 ) ;
F_6 ( V_7 , 0 , V_239 ) ;
F_6 ( V_7 , 0 , V_176 ) ;
if ( V_2 -> V_254 ) {
F_129 ( V_2 -> V_254 ) ;
F_130 ( V_2 -> V_254 ) ;
}
F_121 ( V_7 -> V_241 , V_7 ) ;
F_122 ( & V_2 -> V_249 ) ;
F_46 ( V_7 ) ;
F_59 ( V_2 ) ;
F_123 ( & V_2 -> V_299 -> V_110 ) ;
return 0 ;
}
static struct V_310 * F_131 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
if ( F_2 ( V_2 ) )
return & V_7 -> V_181 ;
F_118 ( & V_2 -> V_299 -> V_110 ) ;
V_7 -> V_181 . V_311 += F_8 ( V_7 , V_312 ) ;
F_6 ( V_7 , 0 , V_312 ) ;
V_7 -> V_181 . V_313 += F_8 ( V_7 , V_314 ) ;
F_6 ( V_7 , 0 , V_314 ) ;
V_7 -> V_181 . V_215 += F_8 ( V_7 , V_315 ) ;
F_6 ( V_7 , 0 , V_315 ) ;
if ( F_1 ( V_2 ) ) {
V_7 -> V_181 . V_215 += F_8 ( V_7 , V_316 ) ;
F_6 ( V_7 , 0 , V_316 ) ;
V_7 -> V_181 . V_215 += F_8 ( V_7 , V_317 ) ;
F_6 ( V_7 , 0 , V_317 ) ;
} else {
V_7 -> V_181 . V_215 += F_8 ( V_7 , V_318 ) ;
F_6 ( V_7 , 0 , V_318 ) ;
}
F_123 ( & V_2 -> V_299 -> V_110 ) ;
return & V_7 -> V_181 ;
}
static int F_132 ( struct V_6 * V_7 , struct V_319 * V_320 , int V_321 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_253 * V_254 = V_2 -> V_254 ;
if ( ! F_114 ( V_7 ) )
return - V_295 ;
if ( ! V_254 )
return - V_322 ;
return F_133 ( V_254 , V_320 , V_321 ) ;
}
static void * F_134 ( struct V_1 * V_2 ,
int V_178 )
{
return F_135 ( V_2 , V_323 ) + ( V_178 / 8 * 4 ) ;
}
static T_1 F_136 ( int V_178 )
{
return 0x0f << ( 28 - ( ( V_178 % 8 ) * 4 ) ) ;
}
static T_1 F_137 ( struct V_1 * V_2 , int V_178 )
{
return ( 0x08 >> ( V_2 -> V_324 << 1 ) ) << ( 28 - ( ( V_178 % 8 ) * 4 ) ) ;
}
static void F_138 ( struct V_6 * V_7 ,
int V_178 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_325 ;
void * V_3 ;
V_3 = F_134 ( V_2 , V_178 ) ;
V_325 = F_13 ( V_3 ) ;
F_16 ( V_325 | F_137 ( V_2 , V_178 ) , V_3 ) ;
}
static bool F_139 ( struct V_6 * V_7 ,
int V_178 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_326 , V_327 , V_325 ;
void * V_3 ;
V_3 = F_134 ( V_2 , V_178 ) ;
V_326 = F_136 ( V_178 ) ;
V_327 = F_137 ( V_2 , V_178 ) & ~ V_326 ;
V_325 = F_13 ( V_3 ) ;
F_16 ( V_325 & ~ V_326 , V_3 ) ;
return V_325 & V_327 ;
}
static int F_140 ( struct V_6 * V_7 )
{
int V_328 = V_329 * 100 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
while ( ( F_141 ( V_2 , V_330 ) & V_331 ) ) {
F_142 ( 10 ) ;
V_328 -- ;
if ( V_328 <= 0 ) {
F_25 ( V_7 , L_20 , V_298 ) ;
return - V_49 ;
}
}
return 0 ;
}
static int F_143 ( struct V_6 * V_7 , void * V_332 ,
const T_6 * V_82 )
{
T_1 V_132 ;
V_132 = V_82 [ 0 ] << 24 | V_82 [ 1 ] << 16 | V_82 [ 2 ] << 8 | V_82 [ 3 ] ;
F_16 ( V_132 , V_332 ) ;
if ( F_140 ( V_7 ) < 0 )
return - V_333 ;
V_132 = V_82 [ 4 ] << 8 | V_82 [ 5 ] ;
F_16 ( V_132 , V_332 + 4 ) ;
if ( F_140 ( V_7 ) < 0 )
return - V_333 ;
return 0 ;
}
static void F_144 ( void * V_332 , T_6 * V_82 )
{
T_1 V_132 ;
V_132 = F_13 ( V_332 ) ;
V_82 [ 0 ] = ( V_132 >> 24 ) & 0xff ;
V_82 [ 1 ] = ( V_132 >> 16 ) & 0xff ;
V_82 [ 2 ] = ( V_132 >> 8 ) & 0xff ;
V_82 [ 3 ] = V_132 & 0xff ;
V_132 = F_13 ( V_332 + 4 ) ;
V_82 [ 4 ] = ( V_132 >> 8 ) & 0xff ;
V_82 [ 5 ] = V_132 & 0xff ;
}
static int F_145 ( struct V_6 * V_7 , const T_6 * V_82 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
void * V_3 = F_135 ( V_2 , V_334 ) ;
int V_21 ;
T_6 V_335 [ V_79 ] ;
for ( V_21 = 0 ; V_21 < V_336 ; V_21 ++ , V_3 += 8 ) {
F_144 ( V_3 , V_335 ) ;
if ( F_146 ( V_82 , V_335 ) )
return V_21 ;
}
return - V_264 ;
}
static int F_147 ( struct V_6 * V_7 )
{
T_6 V_337 [ V_79 ] ;
int V_178 ;
memset ( V_337 , 0 , sizeof( V_337 ) ) ;
V_178 = F_145 ( V_7 , V_337 ) ;
return ( V_178 < 0 ) ? - V_127 : V_178 ;
}
static int F_148 ( struct V_6 * V_7 ,
int V_178 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
void * V_3 = F_135 ( V_2 , V_334 ) ;
int V_46 ;
T_6 V_337 [ V_79 ] ;
F_20 ( V_2 , F_141 ( V_2 , V_338 ) &
~ ( 1 << ( 31 - V_178 ) ) , V_338 ) ;
memset ( V_337 , 0 , sizeof( V_337 ) ) ;
V_46 = F_143 ( V_7 , V_3 + V_178 * 8 , V_337 ) ;
if ( V_46 < 0 )
return V_46 ;
return 0 ;
}
static int F_149 ( struct V_6 * V_7 , const T_6 * V_82 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
void * V_3 = F_135 ( V_2 , V_334 ) ;
int V_21 , V_46 ;
if ( ! V_2 -> V_32 -> V_339 )
return 0 ;
V_21 = F_145 ( V_7 , V_82 ) ;
if ( V_21 < 0 ) {
V_21 = F_147 ( V_7 ) ;
if ( V_21 < 0 )
return - V_127 ;
V_46 = F_143 ( V_7 , V_3 + V_21 * 8 , V_82 ) ;
if ( V_46 < 0 )
return V_46 ;
F_20 ( V_2 , F_141 ( V_2 , V_338 ) |
( 1 << ( 31 - V_21 ) ) , V_338 ) ;
}
F_138 ( V_7 , V_21 ) ;
return 0 ;
}
static int F_150 ( struct V_6 * V_7 , const T_6 * V_82 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 , V_46 ;
if ( ! V_2 -> V_32 -> V_339 )
return 0 ;
V_21 = F_145 ( V_7 , V_82 ) ;
if ( V_21 ) {
if ( F_139 ( V_7 , V_21 ) )
goto V_340;
V_46 = F_148 ( V_7 , V_21 ) ;
if ( V_46 < 0 )
return V_46 ;
}
V_340:
return 0 ;
}
static int F_151 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 , V_46 ;
if ( F_152 ( ! V_2 -> V_32 -> V_339 ) )
return 0 ;
for ( V_21 = 0 ; V_21 < V_336 ; V_21 ++ ) {
if ( F_139 ( V_7 , V_21 ) )
continue;
V_46 = F_148 ( V_7 , V_21 ) ;
if ( V_46 < 0 )
return V_46 ;
}
return 0 ;
}
static void F_153 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_6 V_82 [ V_79 ] ;
void * V_3 = F_135 ( V_2 , V_334 ) ;
int V_21 ;
if ( F_152 ( ! V_2 -> V_32 -> V_339 ) )
return;
for ( V_21 = 0 ; V_21 < V_336 ; V_21 ++ , V_3 += 8 ) {
F_144 ( V_3 , V_82 ) ;
if ( F_154 ( V_82 ) )
F_150 ( V_7 , V_82 ) ;
}
}
static void F_155 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_341 ;
int V_342 = 0 ;
unsigned long V_274 ;
F_100 ( & V_2 -> V_245 , V_274 ) ;
V_341 = ( F_8 ( V_7 , V_15 ) & ~ V_343 ) | V_344 ;
if ( ! ( V_7 -> V_274 & V_345 ) ) {
F_153 ( V_7 ) ;
V_342 = 1 ;
}
if ( V_7 -> V_274 & V_346 ) {
F_153 ( V_7 ) ;
V_341 &= ~ V_344 ;
V_342 = 1 ;
}
if ( V_7 -> V_274 & V_347 ) {
F_151 ( V_7 ) ;
V_341 = ( V_341 & ~ V_344 ) | V_343 ;
} else if ( V_2 -> V_32 -> V_339 ) {
struct V_348 * V_349 ;
F_156 (ha, ndev) {
if ( V_342 && F_154 ( V_349 -> V_82 ) )
continue;
if ( F_149 ( V_7 , V_349 -> V_82 ) < 0 ) {
if ( ! V_342 ) {
F_153 ( V_7 ) ;
V_341 &= ~ V_344 ;
V_342 = 1 ;
}
}
}
} else {
V_341 = ( V_341 & ~ V_343 ) | V_344 ;
}
F_6 ( V_7 , V_341 , V_15 ) ;
F_102 ( & V_2 -> V_245 , V_274 ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_324 )
return V_350 ;
else
return V_351 ;
}
static int F_158 ( struct V_6 * V_7 ,
T_7 V_352 , T_3 V_353 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_354 = F_157 ( V_2 ) ;
if ( F_152 ( ! V_2 -> V_32 -> V_339 ) )
return - V_355 ;
if ( ! V_353 )
return 0 ;
V_2 -> V_356 ++ ;
if ( V_2 -> V_356 > 1 ) {
F_20 ( V_2 , 0 , V_354 ) ;
return 0 ;
}
F_20 ( V_2 , V_357 | ( V_353 & V_358 ) ,
V_354 ) ;
return 0 ;
}
static int F_159 ( struct V_6 * V_7 ,
T_7 V_352 , T_3 V_353 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_354 = F_157 ( V_2 ) ;
if ( F_152 ( ! V_2 -> V_32 -> V_339 ) )
return - V_355 ;
if ( ! V_353 )
return 0 ;
V_2 -> V_356 -- ;
F_20 ( V_2 , 0 , V_354 ) ;
return 0 ;
}
static void F_160 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
F_20 ( V_2 , 0 , V_338 ) ;
return;
}
F_20 ( V_2 , 0 , V_359 ) ;
F_20 ( V_2 , 0 , V_360 ) ;
F_20 ( V_2 , 0 , V_361 ) ;
F_20 ( V_2 , 0xc , V_362 ) ;
F_20 ( V_2 , 0xc , V_363 ) ;
F_20 ( V_2 , 0 , V_364 ) ;
F_20 ( V_2 , 0 , V_365 ) ;
F_20 ( V_2 , 0 , V_366 ) ;
F_20 ( V_2 , 0 , V_367 ) ;
F_20 ( V_2 , V_368 | V_369 , V_370 ) ;
if ( F_1 ( V_2 ) ) {
F_20 ( V_2 , 0 , V_371 ) ;
F_20 ( V_2 , 0 , V_372 ) ;
} else {
F_20 ( V_2 , 0 , V_373 ) ;
F_20 ( V_2 , 0 , V_374 ) ;
}
F_20 ( V_2 , 0 , V_375 ) ;
F_20 ( V_2 , 0 , V_376 ) ;
F_20 ( V_2 , 0 , V_338 ) ;
F_20 ( V_2 , 0 , V_323 ) ;
F_20 ( V_2 , 0 , V_377 ) ;
F_20 ( V_2 , 0 , V_378 ) ;
F_20 ( V_2 , 0 , V_379 ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
F_162 ( V_2 -> V_268 ) ;
F_163 ( V_2 -> V_268 ) ;
return 0 ;
}
static int F_164 ( struct V_1 * V_2 ,
struct V_380 * V_381 )
{
int V_46 , V_21 ;
struct V_87 * V_88 ;
struct V_382 * V_299 = V_2 -> V_299 ;
struct V_383 * V_110 = & V_2 -> V_299 -> V_110 ;
V_88 = F_165 ( V_110 , sizeof( struct V_87 ) , V_126 ) ;
if ( ! V_88 )
return - V_127 ;
V_88 -> V_82 = V_2 -> V_82 + V_2 -> V_3 [ V_384 ] ;
V_88 -> V_89 = V_381 -> V_385 ;
V_88 -> V_92 = V_386 ;
V_88 -> V_91 = V_387 ;
V_88 -> V_90 = V_388 ;
V_88 -> V_93 = V_389 ;
V_88 -> V_85 . V_390 = & V_391 ;
V_2 -> V_268 = F_166 ( & V_88 -> V_85 ) ;
if ( ! V_2 -> V_268 )
return - V_127 ;
V_2 -> V_268 -> V_271 = L_21 ;
V_2 -> V_268 -> V_261 = V_110 ;
snprintf ( V_2 -> V_268 -> V_269 , V_266 , L_22 ,
V_299 -> V_271 , V_299 -> V_269 ) ;
V_2 -> V_268 -> V_241 = F_167 ( V_110 , V_392 , sizeof( int ) ,
V_126 ) ;
if ( ! V_2 -> V_268 -> V_241 ) {
V_46 = - V_127 ;
goto V_393;
}
if ( V_110 -> V_262 ) {
V_46 = F_168 ( V_2 -> V_268 , V_110 -> V_262 ) ;
} else {
for ( V_21 = 0 ; V_21 < V_392 ; V_21 ++ )
V_2 -> V_268 -> V_241 [ V_21 ] = V_394 ;
if ( V_381 -> V_395 > 0 )
V_2 -> V_268 -> V_241 [ V_381 -> V_396 ] = V_381 -> V_395 ;
V_46 = F_169 ( V_2 -> V_268 ) ;
}
if ( V_46 )
goto V_393;
return 0 ;
V_393:
F_163 ( V_2 -> V_268 ) ;
return V_46 ;
}
static const T_3 * F_170 ( int V_397 )
{
const T_3 * V_3 = NULL ;
switch ( V_397 ) {
case V_398 :
V_3 = V_4 ;
break;
case V_399 :
V_3 = V_5 ;
break;
case V_400 :
V_3 = V_401 ;
break;
case V_402 :
V_3 = V_403 ;
break;
case V_404 :
V_3 = V_405 ;
break;
default:
break;
}
return V_3 ;
}
static struct V_380 * F_171 ( struct V_383 * V_110 )
{
struct V_259 * V_260 = V_110 -> V_262 ;
struct V_380 * V_406 ;
const char * V_407 ;
V_406 = F_165 ( V_110 , sizeof( * V_406 ) , V_126 ) ;
if ( ! V_406 )
return NULL ;
V_406 -> V_9 = F_172 ( V_260 ) ;
V_407 = F_173 ( V_260 ) ;
if ( V_407 )
memcpy ( V_406 -> V_407 , V_407 , V_79 ) ;
V_406 -> V_218 =
F_174 ( V_260 , L_23 ) ;
V_406 -> V_221 =
F_174 ( V_260 , L_24 ) ;
return V_406 ;
}
static inline struct V_380 * F_171 ( struct V_383 * V_110 )
{
return NULL ;
}
static int F_175 ( struct V_382 * V_299 )
{
int V_46 , V_408 = 0 ;
struct V_409 * V_410 ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_380 * V_381 = F_176 ( & V_299 -> V_110 ) ;
const struct V_411 * V_269 = F_177 ( V_299 ) ;
V_410 = F_178 ( V_299 , V_412 , 0 ) ;
if ( F_152 ( V_410 == NULL ) ) {
F_179 ( & V_299 -> V_110 , L_25 ) ;
return - V_295 ;
}
V_7 = F_180 ( sizeof( struct V_1 ) ) ;
if ( ! V_7 )
return - V_127 ;
F_181 ( & V_299 -> V_110 ) ;
F_118 ( & V_299 -> V_110 ) ;
V_7 -> V_413 = V_410 -> V_131 ;
V_408 = V_299 -> V_269 ;
if ( V_408 < 0 )
V_408 = 0 ;
V_7 -> V_414 = - 1 ;
V_46 = F_182 ( V_299 , 0 ) ;
if ( V_46 < 0 ) {
V_46 = - V_322 ;
goto V_415;
}
V_7 -> V_241 = V_46 ;
F_183 ( V_7 , & V_299 -> V_110 ) ;
V_2 = F_4 ( V_7 ) ;
V_2 -> V_97 = V_416 ;
V_2 -> V_95 = V_417 ;
V_2 -> V_82 = F_184 ( & V_299 -> V_110 , V_410 ) ;
if ( F_94 ( V_2 -> V_82 ) ) {
V_46 = F_95 ( V_2 -> V_82 ) ;
goto V_415;
}
F_185 ( & V_2 -> V_245 ) ;
V_2 -> V_299 = V_299 ;
if ( V_299 -> V_110 . V_262 )
V_381 = F_171 ( & V_299 -> V_110 ) ;
if ( ! V_381 ) {
F_179 ( & V_299 -> V_110 , L_26 ) ;
V_46 = - V_295 ;
goto V_415;
}
V_2 -> V_265 = V_381 -> V_396 ;
V_2 -> V_9 = V_381 -> V_9 ;
V_2 -> V_72 = V_381 -> V_72 ;
V_2 -> V_218 = V_381 -> V_218 ;
V_2 -> V_221 = V_381 -> V_221 ;
if ( V_269 ) {
V_2 -> V_32 = (struct V_31 * ) V_269 -> V_418 ;
} else {
const struct V_419 * V_420 ;
V_420 = F_186 ( F_187 ( V_421 ) ,
& V_299 -> V_110 ) ;
V_2 -> V_32 = (struct V_31 * ) V_420 -> V_69 ;
}
V_2 -> V_3 = F_170 ( V_2 -> V_32 -> V_397 ) ;
if ( ! V_2 -> V_3 ) {
F_179 ( & V_299 -> V_110 , L_27 ,
V_2 -> V_32 -> V_397 ) ;
V_46 = - V_295 ;
goto V_415;
}
F_23 ( V_2 -> V_32 ) ;
if ( V_2 -> V_32 -> V_339 )
V_7 -> V_422 = & V_423 ;
else
V_7 -> V_422 = & V_424 ;
V_7 -> V_425 = & V_426 ;
V_7 -> V_427 = V_428 ;
V_2 -> V_277 = V_429 ;
F_36 ( V_7 , V_381 -> V_407 ) ;
if ( ! F_188 ( V_7 -> V_75 ) ) {
F_189 ( & V_299 -> V_110 ,
L_28 ) ;
F_190 ( V_7 ) ;
}
if ( V_2 -> V_32 -> V_339 ) {
struct V_409 * V_430 ;
V_430 = F_178 ( V_299 , V_412 , 1 ) ;
V_2 -> V_431 = F_184 ( & V_299 -> V_110 , V_430 ) ;
if ( F_94 ( V_2 -> V_431 ) ) {
V_46 = F_95 ( V_2 -> V_431 ) ;
goto V_415;
}
V_2 -> V_324 = V_408 % 2 ;
V_7 -> V_432 = V_433 ;
}
if ( ! V_408 || V_381 -> V_434 ) {
if ( V_2 -> V_32 -> V_435 )
V_2 -> V_32 -> V_435 ( V_7 ) ;
if ( V_2 -> V_32 -> V_339 ) {
F_160 ( V_2 ) ;
}
}
V_46 = F_164 ( V_2 , V_381 ) ;
if ( V_46 ) {
F_179 ( & V_7 -> V_110 , L_29 ) ;
goto V_415;
}
F_191 ( V_7 , & V_2 -> V_249 , F_84 , 64 ) ;
V_46 = F_192 ( V_7 ) ;
if ( V_46 )
goto V_436;
F_96 ( V_7 , L_30 ,
( T_1 ) V_7 -> V_413 , V_7 -> V_75 , V_7 -> V_241 ) ;
F_193 ( & V_299 -> V_110 ) ;
F_194 ( V_299 , V_7 ) ;
return V_46 ;
V_436:
F_195 ( & V_2 -> V_249 ) ;
F_161 ( V_2 ) ;
V_415:
if ( V_7 )
F_196 ( V_7 ) ;
F_193 ( & V_299 -> V_110 ) ;
F_197 ( & V_299 -> V_110 ) ;
return V_46 ;
}
static int F_198 ( struct V_382 * V_299 )
{
struct V_6 * V_7 = F_199 ( V_299 ) ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_200 ( V_7 ) ;
F_195 ( & V_2 -> V_249 ) ;
F_161 ( V_2 ) ;
F_197 ( & V_299 -> V_110 ) ;
F_196 ( V_7 ) ;
return 0 ;
}
static int F_201 ( struct V_383 * V_110 )
{
return 0 ;
}
