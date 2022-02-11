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
F_5 ( L_1 ) ;
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
F_25 ( L_2 ) ;
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
goto V_55;
F_6 ( V_7 , 0x0 , V_56 ) ;
F_6 ( V_7 , 0x0 , V_57 ) ;
F_6 ( V_7 , 0x0 , V_58 ) ;
F_6 ( V_7 , 0x0 , V_59 ) ;
F_6 ( V_7 , 0x0 , V_60 ) ;
F_6 ( V_7 , 0x0 , V_61 ) ;
F_6 ( V_7 , 0x0 , V_62 ) ;
F_6 ( V_7 , 0x0 , V_63 ) ;
if ( V_2 -> V_32 -> V_64 )
F_6 ( V_7 , 0x0 , V_65 ) ;
if ( V_2 -> V_32 -> V_66 )
F_3 ( V_7 ) ;
} else {
F_6 ( V_7 , F_8 ( V_7 , V_50 ) | V_67 ,
V_50 ) ;
F_17 ( 3 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_50 ) & ~ V_67 ,
V_50 ) ;
}
V_55:
return V_48 ;
}
static void F_27 ( struct V_68 * V_69 )
{
int V_70 ;
V_70 = V_71 - ( ( T_1 ) V_69 -> V_72 & ( V_71 - 1 ) ) ;
if ( V_70 )
F_28 ( V_69 , V_70 ) ;
}
static void F_27 ( struct V_68 * V_69 )
{
F_28 ( V_69 , V_73 ) ;
}
static inline T_2 F_29 ( struct V_1 * V_2 , T_1 V_74 )
{
switch ( V_2 -> V_75 ) {
case V_76 :
return F_30 ( V_74 ) ;
case V_77 :
return F_31 ( V_74 ) ;
}
return V_74 ;
}
static inline T_2 F_32 ( struct V_1 * V_2 , T_1 V_74 )
{
switch ( V_2 -> V_75 ) {
case V_76 :
return F_33 ( V_74 ) ;
case V_77 :
return F_34 ( V_74 ) ;
}
return V_74 ;
}
static void F_35 ( struct V_6 * V_7 )
{
F_6 ( V_7 ,
( V_7 -> V_78 [ 0 ] << 24 ) | ( V_7 -> V_78 [ 1 ] << 16 ) |
( V_7 -> V_78 [ 2 ] << 8 ) | ( V_7 -> V_78 [ 3 ] ) , V_79 ) ;
F_6 ( V_7 ,
( V_7 -> V_78 [ 4 ] << 8 ) | ( V_7 -> V_78 [ 5 ] ) , V_80 ) ;
}
static void F_36 ( struct V_6 * V_7 , unsigned char * V_81 )
{
if ( V_81 [ 0 ] || V_81 [ 1 ] || V_81 [ 2 ] || V_81 [ 3 ] || V_81 [ 4 ] || V_81 [ 5 ] ) {
memcpy ( V_7 -> V_78 , V_81 , V_82 ) ;
} else {
V_7 -> V_78 [ 0 ] = ( F_8 ( V_7 , V_79 ) >> 24 ) ;
V_7 -> V_78 [ 1 ] = ( F_8 ( V_7 , V_79 ) >> 16 ) & 0xFF ;
V_7 -> V_78 [ 2 ] = ( F_8 ( V_7 , V_79 ) >> 8 ) & 0xFF ;
V_7 -> V_78 [ 3 ] = ( F_8 ( V_7 , V_79 ) & 0xFF ) ;
V_7 -> V_78 [ 4 ] = ( F_8 ( V_7 , V_80 ) >> 8 ) & 0xFF ;
V_7 -> V_78 [ 5 ] = ( F_8 ( V_7 , V_80 ) & 0xFF ) ;
}
}
static unsigned long F_37 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) || F_2 ( V_2 ) )
return V_83 ;
else
return V_84 ;
}
static void F_38 ( void * V_85 , T_1 V_86 )
{
F_16 ( F_13 ( V_85 ) | V_86 , V_85 ) ;
}
static void F_39 ( void * V_85 , T_1 V_86 )
{
F_16 ( ( F_13 ( V_85 ) & ~ V_86 ) , V_85 ) ;
}
static int F_40 ( void * V_85 , T_1 V_86 )
{
return ( F_13 ( V_85 ) & V_86 ) != 0 ;
}
static void F_41 ( struct V_87 * V_88 , int V_89 )
{
struct V_90 * V_91 = F_42 ( V_88 , struct V_90 , V_88 ) ;
if ( V_91 -> V_92 )
V_91 -> V_92 ( V_91 -> V_85 ) ;
if ( V_89 )
F_38 ( V_91 -> V_85 , V_91 -> V_93 ) ;
else
F_39 ( V_91 -> V_85 , V_91 -> V_93 ) ;
}
static void F_43 ( struct V_87 * V_88 , int V_89 )
{
struct V_90 * V_91 = F_42 ( V_88 , struct V_90 , V_88 ) ;
if ( V_91 -> V_92 )
V_91 -> V_92 ( V_91 -> V_85 ) ;
if ( V_89 )
F_38 ( V_91 -> V_85 , V_91 -> V_94 ) ;
else
F_39 ( V_91 -> V_85 , V_91 -> V_94 ) ;
}
static int F_44 ( struct V_87 * V_88 )
{
struct V_90 * V_91 = F_42 ( V_88 , struct V_90 , V_88 ) ;
if ( V_91 -> V_92 )
V_91 -> V_92 ( V_91 -> V_85 ) ;
return F_40 ( V_91 -> V_85 , V_91 -> V_95 ) ;
}
static void F_45 ( struct V_87 * V_88 , int V_89 )
{
struct V_90 * V_91 = F_42 ( V_88 , struct V_90 , V_88 ) ;
if ( V_91 -> V_92 )
V_91 -> V_92 ( V_91 -> V_85 ) ;
if ( V_89 )
F_38 ( V_91 -> V_85 , V_91 -> V_96 ) ;
else
F_39 ( V_91 -> V_85 , V_91 -> V_96 ) ;
}
static void F_46 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 ;
if ( V_2 -> V_97 ) {
for ( V_21 = 0 ; V_21 < V_2 -> V_98 ; V_21 ++ ) {
if ( V_2 -> V_97 [ V_21 ] )
F_47 ( V_2 -> V_97 [ V_21 ] ) ;
}
}
F_48 ( V_2 -> V_97 ) ;
V_2 -> V_97 = NULL ;
if ( V_2 -> V_99 ) {
for ( V_21 = 0 ; V_21 < V_2 -> V_100 ; V_21 ++ ) {
if ( V_2 -> V_99 [ V_21 ] )
F_47 ( V_2 -> V_99 [ V_21 ] ) ;
}
}
F_48 ( V_2 -> V_99 ) ;
V_2 -> V_99 = NULL ;
}
static void F_49 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 ;
struct V_68 * V_69 ;
struct V_101 * V_102 = NULL ;
struct V_103 * V_104 = NULL ;
int V_105 = sizeof( * V_102 ) * V_2 -> V_98 ;
int V_106 = sizeof( * V_104 ) * V_2 -> V_100 ;
V_2 -> V_107 = 0 ;
V_2 -> V_108 = 0 ;
V_2 -> V_109 = 0 ;
V_2 -> V_110 = 0 ;
memset ( V_2 -> V_111 , 0 , V_105 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_98 ; V_21 ++ ) {
V_2 -> V_97 [ V_21 ] = NULL ;
V_69 = F_50 ( V_7 , V_2 -> V_112 ) ;
V_2 -> V_97 [ V_21 ] = V_69 ;
if ( V_69 == NULL )
break;
F_51 ( & V_7 -> V_113 , V_69 -> V_72 , V_2 -> V_112 ,
V_114 ) ;
F_27 ( V_69 ) ;
V_102 = & V_2 -> V_111 [ V_21 ] ;
V_102 -> V_85 = F_52 ( F_53 ( V_69 -> V_72 , 4 ) ) ;
V_102 -> V_115 = F_29 ( V_2 , V_116 | V_117 ) ;
V_102 -> V_118 = F_54 ( V_2 -> V_112 , 16 ) ;
if ( V_21 == 0 ) {
F_6 ( V_7 , V_2 -> V_119 , V_60 ) ;
if ( F_1 ( V_2 ) ||
F_2 ( V_2 ) )
F_6 ( V_7 , V_2 -> V_119 , V_61 ) ;
}
}
V_2 -> V_109 = ( T_1 ) ( V_21 - V_2 -> V_98 ) ;
V_102 -> V_115 |= F_29 ( V_2 , V_120 ) ;
memset ( V_2 -> V_121 , 0 , V_106 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_100 ; V_21 ++ ) {
V_2 -> V_99 [ V_21 ] = NULL ;
V_104 = & V_2 -> V_121 [ V_21 ] ;
V_104 -> V_115 = F_29 ( V_2 , V_122 ) ;
V_104 -> V_118 = 0 ;
if ( V_21 == 0 ) {
F_6 ( V_7 , V_2 -> V_123 , V_56 ) ;
if ( F_1 ( V_2 ) ||
F_2 ( V_2 ) )
F_6 ( V_7 , V_2 -> V_123 , V_57 ) ;
}
}
V_104 -> V_115 |= F_29 ( V_2 , V_124 ) ;
}
static int F_55 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_105 , V_106 , V_48 = 0 ;
V_2 -> V_112 = ( V_7 -> V_125 <= 1492 ? V_126 :
( ( ( V_7 -> V_125 + 26 + 7 ) & ~ 7 ) + 2 + 16 ) ) ;
if ( V_2 -> V_32 -> V_127 )
V_2 -> V_112 += V_128 ;
V_2 -> V_97 = F_56 ( V_2 -> V_98 ,
sizeof( * V_2 -> V_97 ) , V_129 ) ;
if ( ! V_2 -> V_97 ) {
V_48 = - V_130 ;
return V_48 ;
}
V_2 -> V_99 = F_56 ( V_2 -> V_100 ,
sizeof( * V_2 -> V_99 ) , V_129 ) ;
if ( ! V_2 -> V_99 ) {
V_48 = - V_130 ;
goto V_131;
}
V_105 = sizeof( struct V_101 ) * V_2 -> V_98 ;
V_2 -> V_111 = F_57 ( NULL , V_105 , & V_2 -> V_119 ,
V_129 ) ;
if ( ! V_2 -> V_111 ) {
V_48 = - V_130 ;
goto V_132;
}
V_2 -> V_109 = 0 ;
V_106 = sizeof( struct V_103 ) * V_2 -> V_100 ;
V_2 -> V_121 = F_57 ( NULL , V_106 , & V_2 -> V_123 ,
V_129 ) ;
if ( ! V_2 -> V_121 ) {
V_48 = - V_130 ;
goto V_132;
}
return V_48 ;
V_132:
F_58 ( NULL , V_105 , V_2 -> V_111 , V_2 -> V_119 ) ;
V_131:
F_46 ( V_7 ) ;
V_2 -> V_121 = NULL ;
V_2 -> V_111 = NULL ;
return V_48 ;
}
static void F_59 ( struct V_1 * V_2 )
{
int V_133 ;
if ( V_2 -> V_111 ) {
V_133 = sizeof( struct V_101 ) * V_2 -> V_98 ;
F_58 ( NULL , V_133 , V_2 -> V_111 ,
V_2 -> V_119 ) ;
V_2 -> V_111 = NULL ;
}
if ( V_2 -> V_121 ) {
V_133 = sizeof( struct V_103 ) * V_2 -> V_100 ;
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
goto V_55;
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
F_6 ( V_7 , V_2 -> V_32 -> V_42 , V_146 ) ;
F_6 ( V_7 , V_147 | V_148 | V_149 , V_150 ) ;
if ( V_2 -> V_32 -> V_151 )
F_6 ( V_7 , 0x800 , V_152 ) ;
F_6 ( V_7 , V_2 -> V_32 -> V_37 , V_153 ) ;
if ( ! V_2 -> V_32 -> V_154 )
F_6 ( V_7 , 0 , V_155 ) ;
F_6 ( V_7 , V_7 -> V_125 + V_156 + V_157 + V_158 ,
V_159 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_160 ) , V_160 ) ;
if ( V_134 )
F_6 ( V_7 , V_2 -> V_32 -> V_161 , V_140 ) ;
V_135 = ( F_8 ( V_7 , V_15 ) & V_16 ) |
V_162 | ( V_2 -> V_14 ? V_16 : 0 ) | V_163 | V_164 ;
F_6 ( V_7 , V_135 , V_15 ) ;
if ( V_2 -> V_32 -> V_165 )
V_2 -> V_32 -> V_165 ( V_7 ) ;
F_6 ( V_7 , V_2 -> V_32 -> V_33 , V_166 ) ;
if ( V_134 )
F_6 ( V_7 , V_2 -> V_32 -> V_35 , V_167 ) ;
F_35 ( V_7 ) ;
if ( V_2 -> V_32 -> V_168 )
F_6 ( V_7 , V_169 , V_170 ) ;
if ( V_2 -> V_32 -> V_171 )
F_6 ( V_7 , V_172 , V_173 ) ;
if ( V_2 -> V_32 -> V_174 )
F_6 ( V_7 , V_175 , V_176 ) ;
if ( V_134 ) {
F_6 ( V_7 , V_177 , V_178 ) ;
F_62 ( V_7 ) ;
}
V_55:
return V_48 ;
}
static int F_63 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_103 * V_104 ;
int V_179 = 0 ;
int V_180 = 0 ;
for (; V_2 -> V_108 - V_2 -> V_110 > 0 ; V_2 -> V_110 ++ ) {
V_180 = V_2 -> V_110 % V_2 -> V_100 ;
V_104 = & V_2 -> V_121 [ V_180 ] ;
if ( V_104 -> V_115 & F_29 ( V_2 , V_181 ) )
break;
if ( V_2 -> V_99 [ V_180 ] ) {
F_64 ( & V_7 -> V_113 , V_104 -> V_85 ,
V_104 -> V_118 , V_182 ) ;
F_65 ( V_2 -> V_99 [ V_180 ] ) ;
V_2 -> V_99 [ V_180 ] = NULL ;
V_179 ++ ;
}
V_104 -> V_115 = F_29 ( V_2 , V_122 ) ;
if ( V_180 >= V_2 -> V_100 - 1 )
V_104 -> V_115 |= F_29 ( V_2 , V_124 ) ;
V_7 -> V_183 . V_184 ++ ;
V_7 -> V_183 . V_185 += V_104 -> V_118 ;
}
return V_179 ;
}
static int F_66 ( struct V_6 * V_7 , T_1 V_186 , int * V_187 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_101 * V_102 ;
int V_180 = V_2 -> V_107 % V_2 -> V_98 ;
int V_188 = ( V_2 -> V_109 + V_2 -> V_98 ) - V_2 -> V_107 ;
struct V_68 * V_69 ;
int V_189 = 0 ;
T_3 V_190 = 0 ;
T_1 V_191 ;
V_102 = & V_2 -> V_111 [ V_180 ] ;
while ( ! ( V_102 -> V_115 & F_29 ( V_2 , V_116 ) ) ) {
V_191 = F_32 ( V_2 , V_102 -> V_115 ) ;
V_190 = V_102 -> V_192 ;
if ( -- V_188 < 0 )
break;
if ( * V_187 <= 0 ) {
V_189 = 1 ;
break;
}
( * V_187 ) -- ;
if ( ! ( V_191 & V_193 ) )
V_7 -> V_183 . V_194 ++ ;
if ( V_2 -> V_32 -> V_195 )
V_191 >>= 16 ;
if ( V_191 & ( V_196 | V_197 | V_198 | V_199 |
V_200 | V_201 | V_202 ) ) {
V_7 -> V_183 . V_203 ++ ;
if ( V_191 & V_196 )
V_7 -> V_183 . V_204 ++ ;
if ( V_191 & V_197 )
V_7 -> V_183 . V_205 ++ ;
if ( V_191 & V_198 )
V_7 -> V_183 . V_194 ++ ;
if ( V_191 & V_199 )
V_7 -> V_183 . V_194 ++ ;
if ( V_191 & V_201 )
V_7 -> V_183 . V_206 ++ ;
if ( V_191 & V_202 )
V_7 -> V_183 . V_207 ++ ;
} else {
if ( ! V_2 -> V_32 -> V_142 )
F_67 (
F_68 ( F_54 ( V_102 -> V_85 , 4 ) ) ,
V_190 + 2 ) ;
V_69 = V_2 -> V_97 [ V_180 ] ;
V_2 -> V_97 [ V_180 ] = NULL ;
if ( V_2 -> V_32 -> V_127 )
F_28 ( V_69 , V_128 ) ;
F_69 ( & V_7 -> V_113 , V_102 -> V_85 ,
V_2 -> V_112 ,
V_114 ) ;
F_70 ( V_69 , V_190 ) ;
V_69 -> V_208 = F_71 ( V_69 , V_7 ) ;
F_72 ( V_69 ) ;
V_7 -> V_183 . V_209 ++ ;
V_7 -> V_183 . V_210 += V_190 ;
}
V_102 -> V_115 |= F_29 ( V_2 , V_116 ) ;
V_180 = ( ++ V_2 -> V_107 ) % V_2 -> V_98 ;
V_102 = & V_2 -> V_111 [ V_180 ] ;
}
for (; V_2 -> V_107 - V_2 -> V_109 > 0 ; V_2 -> V_109 ++ ) {
V_180 = V_2 -> V_109 % V_2 -> V_98 ;
V_102 = & V_2 -> V_111 [ V_180 ] ;
V_102 -> V_118 = F_54 ( V_2 -> V_112 , 16 ) ;
if ( V_2 -> V_97 [ V_180 ] == NULL ) {
V_69 = F_50 ( V_7 , V_2 -> V_112 ) ;
V_2 -> V_97 [ V_180 ] = V_69 ;
if ( V_69 == NULL )
break;
F_51 ( & V_7 -> V_113 , V_69 -> V_72 , V_2 -> V_112 ,
V_114 ) ;
F_27 ( V_69 ) ;
F_73 ( V_69 ) ;
V_102 -> V_85 = F_52 ( F_53 ( V_69 -> V_72 , 4 ) ) ;
}
if ( V_180 >= V_2 -> V_98 - 1 )
V_102 -> V_115 |=
F_29 ( V_2 , V_116 | V_117 | V_120 ) ;
else
V_102 -> V_115 |=
F_29 ( V_2 , V_116 | V_117 ) ;
}
if ( ! ( F_8 ( V_7 , V_178 ) & V_177 ) ) {
if ( V_186 & V_211 ) {
T_1 V_212 = ( F_8 ( V_7 , V_61 ) -
F_8 ( V_7 , V_60 ) ) >> 4 ;
V_2 -> V_107 = V_212 ;
V_2 -> V_109 = V_212 ;
}
F_6 ( V_7 , V_177 , V_178 ) ;
}
return V_189 ;
}
static void F_74 ( struct V_6 * V_7 )
{
F_6 ( V_7 , F_8 ( V_7 , V_15 ) &
~ ( V_164 | V_163 ) , V_15 ) ;
}
static void F_75 ( struct V_6 * V_7 )
{
F_6 ( V_7 , F_8 ( V_7 , V_15 ) |
( V_164 | V_163 ) , V_15 ) ;
}
static void F_76 ( struct V_6 * V_7 , int V_186 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_213 ;
T_1 V_214 ;
T_1 V_215 ;
if ( V_186 & V_216 ) {
V_213 = F_8 ( V_7 , V_166 ) ;
F_6 ( V_7 , V_213 , V_166 ) ;
if ( V_213 & V_217 )
V_7 -> V_183 . V_218 ++ ;
if ( V_213 & V_219 ) {
if ( V_2 -> V_32 -> V_220 || V_2 -> V_221 ) {
goto V_222;
} else {
V_214 = ( F_8 ( V_7 , V_223 ) ) ;
if ( V_2 -> V_224 )
V_214 = ~ V_214 ;
}
if ( ! ( V_214 & V_225 ) ) {
F_74 ( V_7 ) ;
} else {
F_6 ( V_7 , F_8 ( V_7 , V_140 ) &
~ V_226 , V_140 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_166 ) ,
V_166 ) ;
F_6 ( V_7 , F_8 ( V_7 , V_140 ) |
V_226 , V_140 ) ;
F_75 ( V_7 ) ;
}
}
}
V_222:
if ( V_186 & V_227 ) {
if ( V_186 & V_228 ) {
V_7 -> V_183 . V_229 ++ ;
if ( F_77 ( V_2 ) )
F_78 ( & V_7 -> V_113 , L_3 ) ;
}
}
if ( V_186 & V_230 ) {
if ( V_186 & V_231 ) {
V_7 -> V_183 . V_205 ++ ;
if ( F_79 ( V_2 ) )
F_78 ( & V_7 -> V_113 , L_4 ) ;
}
}
if ( V_186 & V_232 ) {
V_7 -> V_183 . V_233 ++ ;
if ( F_77 ( V_2 ) )
F_78 ( & V_7 -> V_113 , L_5 ) ;
}
if ( V_186 & V_234 ) {
V_7 -> V_183 . V_233 ++ ;
if ( F_77 ( V_2 ) )
F_78 ( & V_7 -> V_113 , L_6 ) ;
}
if ( V_186 & V_211 ) {
V_7 -> V_183 . V_207 ++ ;
if ( F_79 ( V_2 ) )
F_78 ( & V_7 -> V_113 , L_7 ) ;
}
if ( V_186 & V_235 ) {
V_7 -> V_183 . V_236 ++ ;
if ( F_79 ( V_2 ) )
F_78 ( & V_7 -> V_113 , L_8 ) ;
}
if ( ! V_2 -> V_32 -> V_237 && ( V_186 & V_238 ) ) {
V_7 -> V_183 . V_233 ++ ;
if ( F_77 ( V_2 ) )
F_78 ( & V_7 -> V_113 , L_9 ) ;
}
V_215 = V_227 | V_228 | V_238 | V_232 | V_234 ;
if ( V_2 -> V_32 -> V_237 )
V_215 &= ~ V_238 ;
if ( V_186 & V_215 ) {
T_1 V_239 = F_8 ( V_7 , V_240 ) ;
F_78 ( & V_7 -> V_113 , L_10 ,
V_186 , V_2 -> V_108 , V_2 -> V_110 ,
( T_1 ) V_7 -> V_241 , V_239 ) ;
F_63 ( V_7 ) ;
if ( V_239 ^ F_37 ( V_2 ) ) {
F_6 ( V_7 , F_37 ( V_2 ) , V_240 ) ;
}
F_80 ( V_7 ) ;
}
}
static T_4 F_81 ( int V_242 , void * V_243 )
{
struct V_6 * V_7 = V_243 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_31 * V_32 = V_2 -> V_32 ;
T_4 V_48 = V_244 ;
unsigned long V_186 , V_245 ;
F_82 ( & V_2 -> V_246 ) ;
V_186 = F_8 ( V_7 , V_160 ) ;
V_245 = F_8 ( V_7 , V_140 ) ;
V_186 &= V_245 | V_226 ;
if ( V_186 & ( V_247 | V_32 -> V_44 | V_32 -> V_46 ) )
V_48 = V_248 ;
else
goto V_249;
if ( V_186 & V_247 ) {
if ( F_83 ( & V_2 -> V_250 ) ) {
F_6 ( V_7 , V_245 & ~ V_247 ,
V_140 ) ;
F_84 ( & V_2 -> V_250 ) ;
} else {
F_85 ( & V_7 -> V_113 ,
L_11 ,
V_186 , V_245 ) ;
}
}
if ( V_186 & V_32 -> V_44 ) {
F_6 ( V_7 , V_186 & V_32 -> V_44 , V_160 ) ;
F_63 ( V_7 ) ;
F_80 ( V_7 ) ;
}
if ( V_186 & V_32 -> V_46 ) {
F_6 ( V_7 , V_186 & V_32 -> V_46 , V_160 ) ;
F_76 ( V_7 , V_186 ) ;
}
V_249:
F_86 ( & V_2 -> V_246 ) ;
return V_48 ;
}
static int F_87 ( struct V_251 * V_250 , int V_252 )
{
struct V_1 * V_2 = F_42 ( V_250 , struct V_1 ,
V_250 ) ;
struct V_6 * V_7 = V_250 -> V_113 ;
int V_187 = V_252 ;
unsigned long V_186 ;
for (; ; ) {
V_186 = F_8 ( V_7 , V_160 ) ;
if ( ! ( V_186 & V_247 ) )
break;
F_6 ( V_7 , V_186 & V_247 , V_160 ) ;
if ( F_66 ( V_7 , V_186 , & V_187 ) )
goto V_55;
}
F_88 ( V_250 ) ;
F_6 ( V_7 , V_2 -> V_32 -> V_161 , V_140 ) ;
V_55:
return V_252 - V_187 ;
}
static void F_89 ( struct V_6 * V_7 )
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
if ( V_2 -> V_32 -> V_165 )
V_2 -> V_32 -> V_165 ( V_7 ) ;
}
if ( ! V_2 -> V_256 ) {
F_6 ( V_7 ,
F_8 ( V_7 , V_15 ) & ~ V_258 ,
V_15 ) ;
V_255 = 1 ;
V_2 -> V_256 = V_254 -> V_256 ;
if ( V_2 -> V_32 -> V_220 || V_2 -> V_221 )
F_75 ( V_7 ) ;
}
} else if ( V_2 -> V_256 ) {
V_255 = 1 ;
V_2 -> V_256 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_14 = - 1 ;
if ( V_2 -> V_32 -> V_220 || V_2 -> V_221 )
F_74 ( V_7 ) ;
}
if ( V_255 && F_90 ( V_2 ) )
F_91 ( V_254 ) ;
}
static int F_92 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
char V_259 [ V_260 + 3 ] ;
struct V_253 * V_254 = NULL ;
snprintf ( V_259 , sizeof( V_259 ) , V_261 ,
V_2 -> V_262 -> V_263 , V_2 -> V_259 ) ;
V_2 -> V_256 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_14 = - 1 ;
V_254 = F_93 ( V_7 , V_259 , F_89 ,
V_2 -> V_9 ) ;
if ( F_94 ( V_254 ) ) {
F_78 ( & V_7 -> V_113 , L_12 ) ;
return F_95 ( V_254 ) ;
}
F_96 ( & V_7 -> V_113 , L_13 ,
V_254 -> V_85 , V_254 -> V_242 , V_254 -> V_264 -> V_265 ) ;
V_2 -> V_254 = V_254 ;
return 0 ;
}
static int F_97 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_48 ;
V_48 = F_92 ( V_7 ) ;
if ( V_48 )
return V_48 ;
F_98 ( V_2 -> V_254 ) ;
return 0 ;
}
static int F_99 ( struct V_6 * V_7 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
unsigned long V_268 ;
int V_48 ;
F_100 ( & V_2 -> V_246 , V_268 ) ;
V_48 = F_101 ( V_2 -> V_254 , V_267 ) ;
F_102 ( & V_2 -> V_246 , V_268 ) ;
return V_48 ;
}
static int F_103 ( struct V_6 * V_7 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
unsigned long V_268 ;
int V_48 ;
F_100 ( & V_2 -> V_246 , V_268 ) ;
F_74 ( V_7 ) ;
V_48 = F_104 ( V_2 -> V_254 , V_267 ) ;
if ( V_48 )
goto V_269;
if ( V_267 -> V_14 == V_270 )
V_2 -> V_14 = 1 ;
else
V_2 -> V_14 = 0 ;
if ( V_2 -> V_32 -> V_257 )
V_2 -> V_32 -> V_257 ( V_7 ) ;
V_269:
F_17 ( 1 ) ;
F_75 ( V_7 ) ;
F_102 ( & V_2 -> V_246 , V_268 ) ;
return V_48 ;
}
static int F_105 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
unsigned long V_268 ;
int V_48 ;
F_100 ( & V_2 -> V_246 , V_268 ) ;
V_48 = F_106 ( V_2 -> V_254 ) ;
F_102 ( & V_2 -> V_246 , V_268 ) ;
return V_48 ;
}
static T_1 F_107 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
return V_2 -> V_271 ;
}
static void F_108 ( struct V_6 * V_7 , T_1 V_8 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
V_2 -> V_271 = V_8 ;
}
static int F_109 ( struct V_6 * V_243 , int V_272 )
{
switch ( V_272 ) {
case V_273 :
return V_274 ;
default:
return - V_275 ;
}
}
static void F_110 ( struct V_6 * V_7 ,
struct V_276 * V_183 , T_5 * V_72 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 = 0 ;
V_72 [ V_21 ++ ] = V_2 -> V_107 ;
V_72 [ V_21 ++ ] = V_2 -> V_108 ;
V_72 [ V_21 ++ ] = V_2 -> V_109 ;
V_72 [ V_21 ++ ] = V_2 -> V_110 ;
}
static void F_111 ( struct V_6 * V_7 , T_1 V_277 , T_6 * V_72 )
{
switch ( V_277 ) {
case V_273 :
memcpy ( V_72 , * V_278 ,
sizeof( V_278 ) ) ;
break;
}
}
static void F_112 ( struct V_6 * V_7 ,
struct V_279 * V_280 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
V_280 -> V_281 = V_282 ;
V_280 -> V_283 = V_284 ;
V_280 -> V_285 = V_2 -> V_98 ;
V_280 -> V_286 = V_2 -> V_100 ;
}
static int F_113 ( struct V_6 * V_7 ,
struct V_279 * V_280 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_48 ;
if ( V_280 -> V_286 > V_284 ||
V_280 -> V_285 > V_282 ||
V_280 -> V_286 < V_287 ||
V_280 -> V_285 < V_288 )
return - V_289 ;
if ( V_280 -> V_290 || V_280 -> V_291 )
return - V_289 ;
if ( F_114 ( V_7 ) ) {
F_115 ( V_7 ) ;
F_6 ( V_7 , 0x0000 , V_140 ) ;
F_6 ( V_7 , 0 , V_240 ) ;
F_6 ( V_7 , 0 , V_178 ) ;
F_116 ( V_7 -> V_242 ) ;
}
F_46 ( V_7 ) ;
F_59 ( V_2 ) ;
V_2 -> V_98 = V_280 -> V_285 ;
V_2 -> V_100 = V_280 -> V_286 ;
V_48 = F_55 ( V_7 ) ;
if ( V_48 < 0 ) {
F_78 ( & V_7 -> V_113 , L_14 , V_292 ) ;
return V_48 ;
}
V_48 = F_60 ( V_7 , false ) ;
if ( V_48 < 0 ) {
F_78 ( & V_7 -> V_113 , L_15 , V_292 ) ;
return V_48 ;
}
if ( F_114 ( V_7 ) ) {
F_6 ( V_7 , V_2 -> V_32 -> V_161 , V_140 ) ;
F_6 ( V_7 , V_177 , V_178 ) ;
F_80 ( V_7 ) ;
}
return 0 ;
}
static int F_117 ( struct V_6 * V_7 )
{
int V_48 = 0 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_118 ( & V_2 -> V_293 -> V_113 ) ;
F_119 ( & V_2 -> V_250 ) ;
V_48 = F_120 ( V_7 -> V_242 , F_81 ,
V_2 -> V_32 -> V_294 , V_7 -> V_265 , V_7 ) ;
if ( V_48 ) {
F_78 ( & V_7 -> V_113 , L_16 ) ;
goto V_295;
}
V_48 = F_55 ( V_7 ) ;
if ( V_48 )
goto V_296;
V_48 = F_60 ( V_7 , true ) ;
if ( V_48 )
goto V_296;
V_48 = F_97 ( V_7 ) ;
if ( V_48 )
goto V_296;
return V_48 ;
V_296:
F_121 ( V_7 -> V_242 , V_7 ) ;
V_295:
F_122 ( & V_2 -> V_250 ) ;
F_123 ( & V_2 -> V_293 -> V_113 ) ;
return V_48 ;
}
static void F_124 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_101 * V_102 ;
int V_21 ;
F_125 ( V_7 ) ;
if ( F_126 ( V_2 ) ) {
F_78 ( & V_7 -> V_113 , L_17 ,
V_7 -> V_265 , ( int ) F_8 ( V_7 , V_160 ) ) ;
}
V_7 -> V_183 . V_297 ++ ;
for ( V_21 = 0 ; V_21 < V_2 -> V_98 ; V_21 ++ ) {
V_102 = & V_2 -> V_111 [ V_21 ] ;
V_102 -> V_115 = 0 ;
V_102 -> V_85 = 0xBADF00D0 ;
if ( V_2 -> V_97 [ V_21 ] )
F_47 ( V_2 -> V_97 [ V_21 ] ) ;
V_2 -> V_97 [ V_21 ] = NULL ;
}
for ( V_21 = 0 ; V_21 < V_2 -> V_100 ; V_21 ++ ) {
if ( V_2 -> V_99 [ V_21 ] )
F_47 ( V_2 -> V_99 [ V_21 ] ) ;
V_2 -> V_99 [ V_21 ] = NULL ;
}
F_60 ( V_7 , true ) ;
}
static int F_127 ( struct V_68 * V_69 , struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_103 * V_104 ;
T_1 V_180 ;
unsigned long V_268 ;
F_100 ( & V_2 -> V_246 , V_268 ) ;
if ( ( V_2 -> V_108 - V_2 -> V_110 ) >= ( V_2 -> V_100 - 4 ) ) {
if ( ! F_63 ( V_7 ) ) {
if ( F_128 ( V_2 ) )
F_85 ( & V_7 -> V_113 , L_18 ) ;
F_125 ( V_7 ) ;
F_102 ( & V_2 -> V_246 , V_268 ) ;
return V_298 ;
}
}
F_102 ( & V_2 -> V_246 , V_268 ) ;
V_180 = V_2 -> V_108 % V_2 -> V_100 ;
V_2 -> V_99 [ V_180 ] = V_69 ;
V_104 = & V_2 -> V_121 [ V_180 ] ;
if ( ! V_2 -> V_32 -> V_142 )
F_67 ( F_68 ( F_54 ( V_104 -> V_85 , 4 ) ) ,
V_69 -> V_299 + 2 ) ;
V_104 -> V_85 = F_51 ( & V_7 -> V_113 , V_69 -> V_72 , V_69 -> V_299 ,
V_182 ) ;
if ( V_69 -> V_299 < V_300 )
V_104 -> V_118 = V_300 ;
else
V_104 -> V_118 = V_69 -> V_299 ;
if ( V_180 >= V_2 -> V_100 - 1 )
V_104 -> V_115 |= F_29 ( V_2 , V_181 | V_124 ) ;
else
V_104 -> V_115 |= F_29 ( V_2 , V_181 ) ;
V_2 -> V_108 ++ ;
if ( ! ( F_8 ( V_7 , V_240 ) & F_37 ( V_2 ) ) )
F_6 ( V_7 , F_37 ( V_2 ) , V_240 ) ;
return V_301 ;
}
static int F_129 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_125 ( V_7 ) ;
F_6 ( V_7 , 0x0000 , V_140 ) ;
F_6 ( V_7 , 0 , V_240 ) ;
F_6 ( V_7 , 0 , V_178 ) ;
if ( V_2 -> V_254 ) {
F_130 ( V_2 -> V_254 ) ;
F_131 ( V_2 -> V_254 ) ;
}
F_121 ( V_7 -> V_242 , V_7 ) ;
F_122 ( & V_2 -> V_250 ) ;
F_46 ( V_7 ) ;
F_59 ( V_2 ) ;
F_123 ( & V_2 -> V_293 -> V_113 ) ;
return 0 ;
}
static struct V_302 * F_132 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
if ( F_2 ( V_2 ) )
return & V_7 -> V_183 ;
F_118 ( & V_2 -> V_293 -> V_113 ) ;
V_7 -> V_183 . V_303 += F_8 ( V_7 , V_304 ) ;
F_6 ( V_7 , 0 , V_304 ) ;
V_7 -> V_183 . V_305 += F_8 ( V_7 , V_306 ) ;
F_6 ( V_7 , 0 , V_306 ) ;
V_7 -> V_183 . V_218 += F_8 ( V_7 , V_307 ) ;
F_6 ( V_7 , 0 , V_307 ) ;
if ( F_1 ( V_2 ) ) {
V_7 -> V_183 . V_218 += F_8 ( V_7 , V_308 ) ;
F_6 ( V_7 , 0 , V_308 ) ;
V_7 -> V_183 . V_218 += F_8 ( V_7 , V_309 ) ;
F_6 ( V_7 , 0 , V_309 ) ;
} else {
V_7 -> V_183 . V_218 += F_8 ( V_7 , V_310 ) ;
F_6 ( V_7 , 0 , V_310 ) ;
}
F_123 ( & V_2 -> V_293 -> V_113 ) ;
return & V_7 -> V_183 ;
}
static int F_133 ( struct V_6 * V_7 , struct V_311 * V_312 , int V_313 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_253 * V_254 = V_2 -> V_254 ;
if ( ! F_114 ( V_7 ) )
return - V_289 ;
if ( ! V_254 )
return - V_314 ;
return F_134 ( V_254 , V_312 , V_313 ) ;
}
static void * F_135 ( struct V_1 * V_2 ,
int V_180 )
{
return F_136 ( V_2 , V_315 ) + ( V_180 / 8 * 4 ) ;
}
static T_1 F_137 ( int V_180 )
{
return 0x0f << ( 28 - ( ( V_180 % 8 ) * 4 ) ) ;
}
static T_1 F_138 ( struct V_1 * V_2 , int V_180 )
{
return ( 0x08 >> ( V_2 -> V_316 << 1 ) ) << ( 28 - ( ( V_180 % 8 ) * 4 ) ) ;
}
static void F_139 ( struct V_6 * V_7 ,
int V_180 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_317 ;
void * V_3 ;
V_3 = F_135 ( V_2 , V_180 ) ;
V_317 = F_13 ( V_3 ) ;
F_16 ( V_317 | F_138 ( V_2 , V_180 ) , V_3 ) ;
}
static bool F_140 ( struct V_6 * V_7 ,
int V_180 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_318 , V_319 , V_317 ;
void * V_3 ;
V_3 = F_135 ( V_2 , V_180 ) ;
V_318 = F_137 ( V_180 ) ;
V_319 = F_138 ( V_2 , V_180 ) & ~ V_318 ;
V_317 = F_13 ( V_3 ) ;
F_16 ( V_317 & ~ V_318 , V_3 ) ;
return V_317 & V_319 ;
}
static int F_141 ( struct V_6 * V_7 )
{
int V_320 = V_321 * 100 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
while ( ( F_142 ( V_2 , V_322 ) & V_323 ) ) {
F_143 ( 10 ) ;
V_320 -- ;
if ( V_320 <= 0 ) {
F_78 ( & V_7 -> V_113 , L_19 , V_292 ) ;
return - V_51 ;
}
}
return 0 ;
}
static int F_144 ( struct V_6 * V_7 , void * V_324 ,
const T_6 * V_85 )
{
T_1 V_135 ;
V_135 = V_85 [ 0 ] << 24 | V_85 [ 1 ] << 16 | V_85 [ 2 ] << 8 | V_85 [ 3 ] ;
F_16 ( V_135 , V_324 ) ;
if ( F_141 ( V_7 ) < 0 )
return - V_325 ;
V_135 = V_85 [ 4 ] << 8 | V_85 [ 5 ] ;
F_16 ( V_135 , V_324 + 4 ) ;
if ( F_141 ( V_7 ) < 0 )
return - V_325 ;
return 0 ;
}
static void F_145 ( void * V_324 , T_6 * V_85 )
{
T_1 V_135 ;
V_135 = F_13 ( V_324 ) ;
V_85 [ 0 ] = ( V_135 >> 24 ) & 0xff ;
V_85 [ 1 ] = ( V_135 >> 16 ) & 0xff ;
V_85 [ 2 ] = ( V_135 >> 8 ) & 0xff ;
V_85 [ 3 ] = V_135 & 0xff ;
V_135 = F_13 ( V_324 + 4 ) ;
V_85 [ 4 ] = ( V_135 >> 8 ) & 0xff ;
V_85 [ 5 ] = V_135 & 0xff ;
}
static int F_146 ( struct V_6 * V_7 , const T_6 * V_85 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
void * V_3 = F_136 ( V_2 , V_326 ) ;
int V_21 ;
T_6 V_327 [ V_82 ] ;
for ( V_21 = 0 ; V_21 < V_328 ; V_21 ++ , V_3 += 8 ) {
F_145 ( V_3 , V_327 ) ;
if ( F_147 ( V_85 , V_327 ) )
return V_21 ;
}
return - V_329 ;
}
static int F_148 ( struct V_6 * V_7 )
{
T_6 V_330 [ V_82 ] ;
int V_180 ;
memset ( V_330 , 0 , sizeof( V_330 ) ) ;
V_180 = F_146 ( V_7 , V_330 ) ;
return ( V_180 < 0 ) ? - V_130 : V_180 ;
}
static int F_149 ( struct V_6 * V_7 ,
int V_180 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
void * V_3 = F_136 ( V_2 , V_326 ) ;
int V_48 ;
T_6 V_330 [ V_82 ] ;
F_20 ( V_2 , F_142 ( V_2 , V_331 ) &
~ ( 1 << ( 31 - V_180 ) ) , V_331 ) ;
memset ( V_330 , 0 , sizeof( V_330 ) ) ;
V_48 = F_144 ( V_7 , V_3 + V_180 * 8 , V_330 ) ;
if ( V_48 < 0 )
return V_48 ;
return 0 ;
}
static int F_150 ( struct V_6 * V_7 , const T_6 * V_85 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
void * V_3 = F_136 ( V_2 , V_326 ) ;
int V_21 , V_48 ;
if ( ! V_2 -> V_32 -> V_332 )
return 0 ;
V_21 = F_146 ( V_7 , V_85 ) ;
if ( V_21 < 0 ) {
V_21 = F_148 ( V_7 ) ;
if ( V_21 < 0 )
return - V_130 ;
V_48 = F_144 ( V_7 , V_3 + V_21 * 8 , V_85 ) ;
if ( V_48 < 0 )
return V_48 ;
F_20 ( V_2 , F_142 ( V_2 , V_331 ) |
( 1 << ( 31 - V_21 ) ) , V_331 ) ;
}
F_139 ( V_7 , V_21 ) ;
return 0 ;
}
static int F_151 ( struct V_6 * V_7 , const T_6 * V_85 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 , V_48 ;
if ( ! V_2 -> V_32 -> V_332 )
return 0 ;
V_21 = F_146 ( V_7 , V_85 ) ;
if ( V_21 ) {
if ( F_140 ( V_7 , V_21 ) )
goto V_333;
V_48 = F_149 ( V_7 , V_21 ) ;
if ( V_48 < 0 )
return V_48 ;
}
V_333:
return 0 ;
}
static int F_152 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 , V_48 ;
if ( F_153 ( ! V_2 -> V_32 -> V_332 ) )
return 0 ;
for ( V_21 = 0 ; V_21 < V_328 ; V_21 ++ ) {
if ( F_140 ( V_7 , V_21 ) )
continue;
V_48 = F_149 ( V_7 , V_21 ) ;
if ( V_48 < 0 )
return V_48 ;
}
return 0 ;
}
static void F_154 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_6 V_85 [ V_82 ] ;
void * V_3 = F_136 ( V_2 , V_326 ) ;
int V_21 ;
if ( F_153 ( ! V_2 -> V_32 -> V_332 ) )
return;
for ( V_21 = 0 ; V_21 < V_328 ; V_21 ++ , V_3 += 8 ) {
F_145 ( V_3 , V_85 ) ;
if ( F_155 ( V_85 ) )
F_151 ( V_7 , V_85 ) ;
}
}
static void F_156 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_334 ;
int V_335 = 0 ;
unsigned long V_268 ;
F_100 ( & V_2 -> V_246 , V_268 ) ;
V_334 = ( F_8 ( V_7 , V_15 ) & ~ V_336 ) | V_337 ;
if ( ! ( V_7 -> V_268 & V_338 ) ) {
F_154 ( V_7 ) ;
V_335 = 1 ;
}
if ( V_7 -> V_268 & V_339 ) {
F_154 ( V_7 ) ;
V_334 &= ~ V_337 ;
V_335 = 1 ;
}
if ( V_7 -> V_268 & V_340 ) {
F_152 ( V_7 ) ;
V_334 = ( V_334 & ~ V_337 ) | V_336 ;
} else if ( V_2 -> V_32 -> V_332 ) {
struct V_341 * V_342 ;
F_157 (ha, ndev) {
if ( V_335 && F_155 ( V_342 -> V_85 ) )
continue;
if ( F_150 ( V_7 , V_342 -> V_85 ) < 0 ) {
if ( ! V_335 ) {
F_154 ( V_7 ) ;
V_334 &= ~ V_337 ;
V_335 = 1 ;
}
}
}
} else {
V_334 = ( V_334 & ~ V_336 ) | V_337 ;
}
F_6 ( V_7 , V_334 , V_15 ) ;
F_102 ( & V_2 -> V_246 , V_268 ) ;
}
static int F_158 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_316 )
return V_343 ;
else
return V_344 ;
}
static int F_159 ( struct V_6 * V_7 ,
T_7 V_345 , T_3 V_346 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_347 = F_158 ( V_2 ) ;
if ( F_153 ( ! V_2 -> V_32 -> V_332 ) )
return - V_348 ;
if ( ! V_346 )
return 0 ;
V_2 -> V_349 ++ ;
if ( V_2 -> V_349 > 1 ) {
F_20 ( V_2 , 0 , V_347 ) ;
return 0 ;
}
F_20 ( V_2 , V_350 | ( V_346 & V_351 ) ,
V_347 ) ;
return 0 ;
}
static int F_160 ( struct V_6 * V_7 ,
T_7 V_345 , T_3 V_346 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_347 = F_158 ( V_2 ) ;
if ( F_153 ( ! V_2 -> V_32 -> V_332 ) )
return - V_348 ;
if ( ! V_346 )
return 0 ;
V_2 -> V_349 -- ;
F_20 ( V_2 , 0 , V_347 ) ;
return 0 ;
}
static void F_161 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
F_20 ( V_2 , 0 , V_331 ) ;
return;
}
F_20 ( V_2 , 0 , V_352 ) ;
F_20 ( V_2 , 0 , V_353 ) ;
F_20 ( V_2 , 0 , V_354 ) ;
F_20 ( V_2 , 0xc , V_355 ) ;
F_20 ( V_2 , 0xc , V_356 ) ;
F_20 ( V_2 , 0 , V_357 ) ;
F_20 ( V_2 , 0 , V_358 ) ;
F_20 ( V_2 , 0 , V_359 ) ;
F_20 ( V_2 , 0 , V_360 ) ;
F_20 ( V_2 , V_361 | V_362 , V_363 ) ;
if ( F_1 ( V_2 ) ) {
F_20 ( V_2 , 0 , V_364 ) ;
F_20 ( V_2 , 0 , V_365 ) ;
} else {
F_20 ( V_2 , 0 , V_366 ) ;
F_20 ( V_2 , 0 , V_367 ) ;
}
F_20 ( V_2 , 0 , V_368 ) ;
F_20 ( V_2 , 0 , V_369 ) ;
F_20 ( V_2 , 0 , V_331 ) ;
F_20 ( V_2 , 0 , V_315 ) ;
F_20 ( V_2 , 0 , V_370 ) ;
F_20 ( V_2 , 0 , V_371 ) ;
F_20 ( V_2 , 0 , V_372 ) ;
}
static int F_162 ( struct V_6 * V_7 )
{
struct V_262 * V_373 = F_163 ( & V_7 -> V_113 ) ;
F_164 ( V_373 ) ;
F_165 ( & V_7 -> V_113 , NULL ) ;
F_166 ( V_373 ) ;
return 0 ;
}
static int F_167 ( struct V_6 * V_7 , int V_263 ,
struct V_374 * V_375 )
{
int V_48 , V_21 ;
struct V_90 * V_91 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
V_91 = F_168 ( & V_7 -> V_113 , sizeof( struct V_90 ) ,
V_129 ) ;
if ( ! V_91 ) {
V_48 = - V_130 ;
goto V_55;
}
V_91 -> V_85 = V_2 -> V_85 + V_2 -> V_3 [ V_376 ] ;
V_91 -> V_92 = V_375 -> V_377 ;
V_91 -> V_95 = V_378 ;
V_91 -> V_94 = V_379 ;
V_91 -> V_93 = V_380 ;
V_91 -> V_96 = V_381 ;
V_91 -> V_88 . V_382 = & V_383 ;
V_2 -> V_262 = F_169 ( & V_91 -> V_88 ) ;
if ( ! V_2 -> V_262 ) {
V_48 = - V_130 ;
goto V_55;
}
V_2 -> V_262 -> V_265 = L_20 ;
V_2 -> V_262 -> V_384 = & V_7 -> V_113 ;
snprintf ( V_2 -> V_262 -> V_263 , V_260 , L_21 ,
V_2 -> V_293 -> V_265 , V_263 ) ;
V_2 -> V_262 -> V_242 = F_168 ( & V_7 -> V_113 ,
sizeof( int ) * V_385 ,
V_129 ) ;
if ( ! V_2 -> V_262 -> V_242 ) {
V_48 = - V_130 ;
goto V_386;
}
for ( V_21 = 0 ; V_21 < V_385 ; V_21 ++ )
V_2 -> V_262 -> V_242 [ V_21 ] = V_387 ;
if ( V_375 -> V_388 > 0 )
V_2 -> V_262 -> V_242 [ V_375 -> V_389 ] = V_375 -> V_388 ;
V_48 = F_170 ( V_2 -> V_262 ) ;
if ( V_48 )
goto V_386;
F_165 ( & V_7 -> V_113 , V_2 -> V_262 ) ;
return 0 ;
V_386:
F_166 ( V_2 -> V_262 ) ;
V_55:
return V_48 ;
}
static const T_3 * F_171 ( int V_390 )
{
const T_3 * V_3 = NULL ;
switch ( V_390 ) {
case V_391 :
V_3 = V_4 ;
break;
case V_392 :
V_3 = V_5 ;
break;
case V_393 :
V_3 = V_394 ;
break;
case V_395 :
V_3 = V_396 ;
break;
case V_397 :
V_3 = V_398 ;
break;
default:
F_25 ( L_22 , V_390 ) ;
break;
}
return V_3 ;
}
static int F_172 ( struct V_399 * V_293 )
{
int V_48 , V_400 = 0 ;
struct V_401 * V_402 ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_374 * V_375 = F_173 ( & V_293 -> V_113 ) ;
const struct V_403 * V_263 = F_174 ( V_293 ) ;
V_402 = F_175 ( V_293 , V_404 , 0 ) ;
if ( F_153 ( V_402 == NULL ) ) {
F_78 ( & V_293 -> V_113 , L_23 ) ;
V_48 = - V_289 ;
goto V_55;
}
V_7 = F_176 ( sizeof( struct V_1 ) ) ;
if ( ! V_7 ) {
V_48 = - V_130 ;
goto V_55;
}
V_7 -> V_405 = V_402 -> V_134 ;
V_400 = V_293 -> V_263 ;
if ( V_400 < 0 )
V_400 = 0 ;
V_7 -> V_406 = - 1 ;
V_48 = F_177 ( V_293 , 0 ) ;
if ( V_48 < 0 ) {
V_48 = - V_314 ;
goto V_407;
}
V_7 -> V_242 = V_48 ;
F_178 ( V_7 , & V_293 -> V_113 ) ;
V_2 = F_4 ( V_7 ) ;
V_2 -> V_100 = V_408 ;
V_2 -> V_98 = V_409 ;
V_2 -> V_85 = F_179 ( & V_293 -> V_113 , V_402 ) ;
if ( F_94 ( V_2 -> V_85 ) ) {
V_48 = F_95 ( V_2 -> V_85 ) ;
goto V_407;
}
F_180 ( & V_2 -> V_246 ) ;
V_2 -> V_293 = V_293 ;
F_181 ( & V_293 -> V_113 ) ;
F_182 ( & V_293 -> V_113 ) ;
if ( ! V_375 ) {
F_78 ( & V_293 -> V_113 , L_24 ) ;
V_48 = - V_289 ;
goto V_407;
}
V_2 -> V_259 = V_375 -> V_389 ;
V_2 -> V_9 = V_375 -> V_9 ;
V_2 -> V_75 = V_375 -> V_75 ;
V_2 -> V_221 = V_375 -> V_221 ;
V_2 -> V_224 = V_375 -> V_224 ;
V_2 -> V_32 = (struct V_31 * ) V_263 -> V_410 ;
V_2 -> V_3 = F_171 ( V_2 -> V_32 -> V_390 ) ;
F_23 ( V_2 -> V_32 ) ;
if ( V_2 -> V_32 -> V_332 )
V_7 -> V_411 = & V_412 ;
else
V_7 -> V_411 = & V_413 ;
F_183 ( V_7 , & V_414 ) ;
V_7 -> V_415 = V_416 ;
V_2 -> V_271 = V_417 ;
F_36 ( V_7 , V_375 -> V_418 ) ;
if ( ! F_184 ( V_7 -> V_78 ) ) {
F_85 ( & V_293 -> V_113 ,
L_25 ) ;
F_185 ( V_7 ) ;
}
if ( V_2 -> V_32 -> V_332 ) {
struct V_401 * V_419 ;
V_419 = F_175 ( V_293 , V_404 , 1 ) ;
V_2 -> V_420 = F_179 ( & V_293 -> V_113 , V_419 ) ;
if ( F_94 ( V_2 -> V_420 ) ) {
V_48 = F_95 ( V_2 -> V_420 ) ;
goto V_407;
}
V_2 -> V_316 = V_400 % 2 ;
V_7 -> V_421 = V_422 ;
}
if ( ! V_400 || V_375 -> V_423 ) {
if ( V_2 -> V_32 -> V_424 )
V_2 -> V_32 -> V_424 ( V_7 ) ;
if ( V_2 -> V_32 -> V_332 ) {
F_161 ( V_2 ) ;
}
}
F_186 ( V_7 , & V_2 -> V_250 , F_87 , 64 ) ;
V_48 = F_187 ( V_7 ) ;
if ( V_48 )
goto V_425;
V_48 = F_167 ( V_7 , V_293 -> V_263 , V_375 ) ;
if ( V_48 )
goto V_426;
F_188 ( L_26 ,
( T_1 ) V_7 -> V_405 , V_7 -> V_78 , V_7 -> V_242 ) ;
F_189 ( V_293 , V_7 ) ;
return V_48 ;
V_426:
F_190 ( V_7 ) ;
V_425:
F_191 ( & V_2 -> V_250 ) ;
V_407:
if ( V_7 )
F_192 ( V_7 ) ;
V_55:
return V_48 ;
}
static int F_193 ( struct V_399 * V_293 )
{
struct V_6 * V_7 = F_194 ( V_293 ) ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_162 ( V_7 ) ;
F_190 ( V_7 ) ;
F_191 ( & V_2 -> V_250 ) ;
F_195 ( & V_293 -> V_113 ) ;
F_192 ( V_7 ) ;
return 0 ;
}
static int F_196 ( struct V_427 * V_113 )
{
return 0 ;
}
