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
T_2 V_67 = ( T_2 ) V_66 -> V_68 & ( V_69 - 1 ) ;
if ( V_67 )
F_28 ( V_66 , V_69 - V_67 ) ;
}
static inline T_3 F_29 ( struct V_1 * V_2 , T_1 V_70 )
{
switch ( V_2 -> V_71 ) {
case V_72 :
return F_30 ( V_70 ) ;
case V_73 :
return F_31 ( V_70 ) ;
}
return V_70 ;
}
static inline T_3 F_32 ( struct V_1 * V_2 , T_1 V_70 )
{
switch ( V_2 -> V_71 ) {
case V_72 :
return F_33 ( V_70 ) ;
case V_73 :
return F_34 ( V_70 ) ;
}
return V_70 ;
}
static void F_35 ( struct V_6 * V_7 )
{
F_6 ( V_7 ,
( V_7 -> V_74 [ 0 ] << 24 ) | ( V_7 -> V_74 [ 1 ] << 16 ) |
( V_7 -> V_74 [ 2 ] << 8 ) | ( V_7 -> V_74 [ 3 ] ) , V_75 ) ;
F_6 ( V_7 ,
( V_7 -> V_74 [ 4 ] << 8 ) | ( V_7 -> V_74 [ 5 ] ) , V_76 ) ;
}
static void F_36 ( struct V_6 * V_7 , unsigned char * V_77 )
{
if ( V_77 [ 0 ] || V_77 [ 1 ] || V_77 [ 2 ] || V_77 [ 3 ] || V_77 [ 4 ] || V_77 [ 5 ] ) {
memcpy ( V_7 -> V_74 , V_77 , V_78 ) ;
} else {
V_7 -> V_74 [ 0 ] = ( F_8 ( V_7 , V_75 ) >> 24 ) ;
V_7 -> V_74 [ 1 ] = ( F_8 ( V_7 , V_75 ) >> 16 ) & 0xFF ;
V_7 -> V_74 [ 2 ] = ( F_8 ( V_7 , V_75 ) >> 8 ) & 0xFF ;
V_7 -> V_74 [ 3 ] = ( F_8 ( V_7 , V_75 ) & 0xFF ) ;
V_7 -> V_74 [ 4 ] = ( F_8 ( V_7 , V_76 ) >> 8 ) & 0xFF ;
V_7 -> V_74 [ 5 ] = ( F_8 ( V_7 , V_76 ) & 0xFF ) ;
}
}
static unsigned long F_37 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) || F_2 ( V_2 ) )
return V_79 ;
else
return V_80 ;
}
static void F_38 ( void * V_81 , T_1 V_82 )
{
F_16 ( F_13 ( V_81 ) | V_82 , V_81 ) ;
}
static void F_39 ( void * V_81 , T_1 V_82 )
{
F_16 ( ( F_13 ( V_81 ) & ~ V_82 ) , V_81 ) ;
}
static int F_40 ( void * V_81 , T_1 V_82 )
{
return ( F_13 ( V_81 ) & V_82 ) != 0 ;
}
static void F_41 ( struct V_83 * V_84 , int V_85 )
{
struct V_86 * V_87 = F_42 ( V_84 , struct V_86 , V_84 ) ;
if ( V_87 -> V_88 )
V_87 -> V_88 ( V_87 -> V_81 ) ;
if ( V_85 )
F_38 ( V_87 -> V_81 , V_87 -> V_89 ) ;
else
F_39 ( V_87 -> V_81 , V_87 -> V_89 ) ;
}
static void F_43 ( struct V_83 * V_84 , int V_85 )
{
struct V_86 * V_87 = F_42 ( V_84 , struct V_86 , V_84 ) ;
if ( V_87 -> V_88 )
V_87 -> V_88 ( V_87 -> V_81 ) ;
if ( V_85 )
F_38 ( V_87 -> V_81 , V_87 -> V_90 ) ;
else
F_39 ( V_87 -> V_81 , V_87 -> V_90 ) ;
}
static int F_44 ( struct V_83 * V_84 )
{
struct V_86 * V_87 = F_42 ( V_84 , struct V_86 , V_84 ) ;
if ( V_87 -> V_88 )
V_87 -> V_88 ( V_87 -> V_81 ) ;
return F_40 ( V_87 -> V_81 , V_87 -> V_91 ) ;
}
static void F_45 ( struct V_83 * V_84 , int V_85 )
{
struct V_86 * V_87 = F_42 ( V_84 , struct V_86 , V_84 ) ;
if ( V_87 -> V_88 )
V_87 -> V_88 ( V_87 -> V_81 ) ;
if ( V_85 )
F_38 ( V_87 -> V_81 , V_87 -> V_92 ) ;
else
F_39 ( V_87 -> V_81 , V_87 -> V_92 ) ;
}
static void F_46 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 ;
if ( V_2 -> V_93 ) {
for ( V_21 = 0 ; V_21 < V_2 -> V_94 ; V_21 ++ )
F_47 ( V_2 -> V_93 [ V_21 ] ) ;
}
F_48 ( V_2 -> V_93 ) ;
V_2 -> V_93 = NULL ;
if ( V_2 -> V_95 ) {
for ( V_21 = 0 ; V_21 < V_2 -> V_96 ; V_21 ++ )
F_47 ( V_2 -> V_95 [ V_21 ] ) ;
}
F_48 ( V_2 -> V_95 ) ;
V_2 -> V_95 = NULL ;
}
static void F_49 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 ;
struct V_65 * V_66 ;
struct V_97 * V_98 = NULL ;
struct V_99 * V_100 = NULL ;
int V_101 = sizeof( * V_98 ) * V_2 -> V_94 ;
int V_102 = sizeof( * V_100 ) * V_2 -> V_96 ;
int V_103 = V_2 -> V_104 + V_69 - 1 ;
V_2 -> V_105 = 0 ;
V_2 -> V_106 = 0 ;
V_2 -> V_107 = 0 ;
V_2 -> V_108 = 0 ;
memset ( V_2 -> V_109 , 0 , V_101 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_94 ; V_21 ++ ) {
V_2 -> V_93 [ V_21 ] = NULL ;
V_66 = F_50 ( V_7 , V_103 ) ;
V_2 -> V_93 [ V_21 ] = V_66 ;
if ( V_66 == NULL )
break;
F_27 ( V_66 ) ;
V_98 = & V_2 -> V_109 [ V_21 ] ;
V_98 -> V_110 = F_51 ( V_2 -> V_104 , 16 ) ;
F_52 ( & V_7 -> V_111 , V_66 -> V_68 , V_98 -> V_110 ,
V_112 ) ;
V_98 -> V_81 = F_53 ( F_54 ( V_66 -> V_68 , 4 ) ) ;
V_98 -> V_113 = F_29 ( V_2 , V_114 | V_115 ) ;
if ( V_21 == 0 ) {
F_6 ( V_7 , V_2 -> V_116 , V_57 ) ;
if ( F_1 ( V_2 ) ||
F_2 ( V_2 ) )
F_6 ( V_7 , V_2 -> V_116 , V_58 ) ;
}
}
V_2 -> V_107 = ( T_1 ) ( V_21 - V_2 -> V_94 ) ;
V_98 -> V_113 |= F_29 ( V_2 , V_117 ) ;
memset ( V_2 -> V_118 , 0 , V_102 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_96 ; V_21 ++ ) {
V_2 -> V_95 [ V_21 ] = NULL ;
V_100 = & V_2 -> V_118 [ V_21 ] ;
V_100 -> V_113 = F_29 ( V_2 , V_119 ) ;
V_100 -> V_110 = 0 ;
if ( V_21 == 0 ) {
F_6 ( V_7 , V_2 -> V_120 , V_53 ) ;
if ( F_1 ( V_2 ) ||
F_2 ( V_2 ) )
F_6 ( V_7 , V_2 -> V_120 , V_54 ) ;
}
}
V_100 -> V_113 |= F_29 ( V_2 , V_121 ) ;
}
static int F_55 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_101 , V_102 , V_46 = 0 ;
V_2 -> V_104 = ( V_7 -> V_122 <= 1492 ? V_123 :
( ( ( V_7 -> V_122 + 26 + 7 ) & ~ 7 ) + 2 + 16 ) ) ;
if ( V_2 -> V_32 -> V_124 )
V_2 -> V_104 += V_125 ;
V_2 -> V_93 = F_56 ( V_2 -> V_94 ,
sizeof( * V_2 -> V_93 ) , V_126 ) ;
if ( ! V_2 -> V_93 ) {
V_46 = - V_127 ;
return V_46 ;
}
V_2 -> V_95 = F_56 ( V_2 -> V_96 ,
sizeof( * V_2 -> V_95 ) , V_126 ) ;
if ( ! V_2 -> V_95 ) {
V_46 = - V_127 ;
goto V_128;
}
V_101 = sizeof( struct V_97 ) * V_2 -> V_94 ;
V_2 -> V_109 = F_57 ( NULL , V_101 , & V_2 -> V_116 ,
V_126 ) ;
if ( ! V_2 -> V_109 ) {
V_46 = - V_127 ;
goto V_129;
}
V_2 -> V_107 = 0 ;
V_102 = sizeof( struct V_99 ) * V_2 -> V_96 ;
V_2 -> V_118 = F_57 ( NULL , V_102 , & V_2 -> V_120 ,
V_126 ) ;
if ( ! V_2 -> V_118 ) {
V_46 = - V_127 ;
goto V_129;
}
return V_46 ;
V_129:
F_58 ( NULL , V_101 , V_2 -> V_109 , V_2 -> V_116 ) ;
V_128:
F_46 ( V_7 ) ;
V_2 -> V_118 = NULL ;
V_2 -> V_109 = NULL ;
return V_46 ;
}
static void F_59 ( struct V_1 * V_2 )
{
int V_130 ;
if ( V_2 -> V_109 ) {
V_130 = sizeof( struct V_97 ) * V_2 -> V_94 ;
F_58 ( NULL , V_130 , V_2 -> V_109 ,
V_2 -> V_116 ) ;
V_2 -> V_109 = NULL ;
}
if ( V_2 -> V_118 ) {
V_130 = sizeof( struct V_99 ) * V_2 -> V_96 ;
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
struct V_99 * V_100 ;
int V_177 = 0 ;
int V_178 = 0 ;
for (; V_2 -> V_106 - V_2 -> V_108 > 0 ; V_2 -> V_108 ++ ) {
V_178 = V_2 -> V_108 % V_2 -> V_96 ;
V_100 = & V_2 -> V_118 [ V_178 ] ;
if ( V_100 -> V_113 & F_29 ( V_2 , V_179 ) )
break;
if ( V_2 -> V_95 [ V_178 ] ) {
F_64 ( & V_7 -> V_111 , V_100 -> V_81 ,
V_100 -> V_110 , V_180 ) ;
F_65 ( V_2 -> V_95 [ V_178 ] ) ;
V_2 -> V_95 [ V_178 ] = NULL ;
V_177 ++ ;
}
V_100 -> V_113 = F_29 ( V_2 , V_119 ) ;
if ( V_178 >= V_2 -> V_96 - 1 )
V_100 -> V_113 |= F_29 ( V_2 , V_121 ) ;
V_7 -> V_181 . V_182 ++ ;
V_7 -> V_181 . V_183 += V_100 -> V_110 ;
}
return V_177 ;
}
static int F_66 ( struct V_6 * V_7 , T_1 V_184 , int * V_185 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_97 * V_98 ;
int V_178 = V_2 -> V_105 % V_2 -> V_94 ;
int V_186 = ( V_2 -> V_107 + V_2 -> V_94 ) - V_2 -> V_105 ;
struct V_65 * V_66 ;
T_4 V_187 = 0 ;
T_1 V_188 ;
int V_103 = V_2 -> V_104 + V_69 - 1 ;
V_98 = & V_2 -> V_109 [ V_178 ] ;
while ( ! ( V_98 -> V_113 & F_29 ( V_2 , V_114 ) ) ) {
V_188 = F_32 ( V_2 , V_98 -> V_113 ) ;
V_187 = V_98 -> V_189 ;
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
F_68 ( F_51 ( V_98 -> V_81 , 4 ) ) ,
V_187 + 2 ) ;
V_66 = V_2 -> V_93 [ V_178 ] ;
V_2 -> V_93 [ V_178 ] = NULL ;
if ( V_2 -> V_32 -> V_124 )
F_28 ( V_66 , V_125 ) ;
F_69 ( & V_7 -> V_111 , V_98 -> V_81 ,
F_51 ( V_2 -> V_104 , 16 ) ,
V_112 ) ;
F_70 ( V_66 , V_187 ) ;
V_66 -> V_205 = F_71 ( V_66 , V_7 ) ;
F_72 ( V_66 ) ;
V_7 -> V_181 . V_206 ++ ;
V_7 -> V_181 . V_207 += V_187 ;
}
V_178 = ( ++ V_2 -> V_105 ) % V_2 -> V_94 ;
V_98 = & V_2 -> V_109 [ V_178 ] ;
}
for (; V_2 -> V_105 - V_2 -> V_107 > 0 ; V_2 -> V_107 ++ ) {
V_178 = V_2 -> V_107 % V_2 -> V_94 ;
V_98 = & V_2 -> V_109 [ V_178 ] ;
V_98 -> V_110 = F_51 ( V_2 -> V_104 , 16 ) ;
if ( V_2 -> V_93 [ V_178 ] == NULL ) {
V_66 = F_50 ( V_7 , V_103 ) ;
V_2 -> V_93 [ V_178 ] = V_66 ;
if ( V_66 == NULL )
break;
F_27 ( V_66 ) ;
F_52 ( & V_7 -> V_111 , V_66 -> V_68 ,
V_98 -> V_110 , V_112 ) ;
F_73 ( V_66 ) ;
V_98 -> V_81 = F_53 ( F_54 ( V_66 -> V_68 , 4 ) ) ;
}
if ( V_178 >= V_2 -> V_94 - 1 )
V_98 -> V_113 |=
F_29 ( V_2 , V_114 | V_115 | V_117 ) ;
else
V_98 -> V_113 |=
F_29 ( V_2 , V_114 | V_115 ) ;
}
if ( ! ( F_8 ( V_7 , V_176 ) & V_175 ) ) {
if ( V_184 & V_208 ) {
T_1 V_209 = ( F_8 ( V_7 , V_58 ) -
F_8 ( V_7 , V_57 ) ) >> 4 ;
V_2 -> V_105 = V_209 ;
V_2 -> V_107 = V_209 ;
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
V_184 , V_2 -> V_106 , V_2 -> V_108 ,
( T_1 ) V_7 -> V_240 , V_238 ) ;
F_63 ( V_7 ) ;
if ( V_238 ^ F_37 ( V_2 ) ) {
F_6 ( V_7 , F_37 ( V_2 ) , V_239 ) ;
}
F_78 ( V_7 ) ;
}
}
static T_5 F_79 ( int V_241 , void * V_242 )
{
struct V_6 * V_7 = V_242 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_31 * V_32 = V_2 -> V_32 ;
T_5 V_46 = V_243 ;
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
struct V_6 * V_7 = V_249 -> V_111 ;
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
struct V_259 * V_260 = V_7 -> V_111 . V_261 -> V_262 ;
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
V_254 -> V_81 , V_254 -> V_241 , V_254 -> V_270 -> V_271 ) ;
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
struct V_282 * V_181 , T_6 * V_68 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 = 0 ;
V_68 [ V_21 ++ ] = V_2 -> V_105 ;
V_68 [ V_21 ++ ] = V_2 -> V_106 ;
V_68 [ V_21 ++ ] = V_2 -> V_107 ;
V_68 [ V_21 ++ ] = V_2 -> V_108 ;
}
static void F_111 ( struct V_6 * V_7 , T_1 V_283 , T_7 * V_68 )
{
switch ( V_283 ) {
case V_279 :
memcpy ( V_68 , * V_284 ,
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
V_286 -> V_291 = V_2 -> V_94 ;
V_286 -> V_292 = V_2 -> V_96 ;
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
V_2 -> V_94 = V_286 -> V_291 ;
V_2 -> V_96 = V_286 -> V_292 ;
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
F_118 ( & V_2 -> V_299 -> V_111 ) ;
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
V_2 -> V_303 = 1 ;
return V_46 ;
V_302:
F_121 ( V_7 -> V_241 , V_7 ) ;
V_301:
F_122 ( & V_2 -> V_249 ) ;
F_123 ( & V_2 -> V_299 -> V_111 ) ;
return V_46 ;
}
static void F_124 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_97 * V_98 ;
int V_21 ;
F_125 ( V_7 ) ;
F_77 ( V_2 , V_304 , V_7 ,
L_18 ,
( int ) F_8 ( V_7 , V_158 ) ) ;
V_7 -> V_181 . V_305 ++ ;
for ( V_21 = 0 ; V_21 < V_2 -> V_94 ; V_21 ++ ) {
V_98 = & V_2 -> V_109 [ V_21 ] ;
V_98 -> V_113 = 0 ;
V_98 -> V_81 = 0xBADF00D0 ;
F_47 ( V_2 -> V_93 [ V_21 ] ) ;
V_2 -> V_93 [ V_21 ] = NULL ;
}
for ( V_21 = 0 ; V_21 < V_2 -> V_96 ; V_21 ++ ) {
F_47 ( V_2 -> V_95 [ V_21 ] ) ;
V_2 -> V_95 [ V_21 ] = NULL ;
}
F_60 ( V_7 , true ) ;
}
static int F_126 ( struct V_65 * V_66 , struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_99 * V_100 ;
T_1 V_178 ;
unsigned long V_274 ;
F_100 ( & V_2 -> V_245 , V_274 ) ;
if ( ( V_2 -> V_106 - V_2 -> V_108 ) >= ( V_2 -> V_96 - 4 ) ) {
if ( ! F_63 ( V_7 ) ) {
F_127 ( V_2 , V_306 , V_7 , L_19 ) ;
F_125 ( V_7 ) ;
F_102 ( & V_2 -> V_245 , V_274 ) ;
return V_307 ;
}
}
F_102 ( & V_2 -> V_245 , V_274 ) ;
V_178 = V_2 -> V_106 % V_2 -> V_96 ;
V_2 -> V_95 [ V_178 ] = V_66 ;
V_100 = & V_2 -> V_118 [ V_178 ] ;
if ( ! V_2 -> V_32 -> V_139 )
F_67 ( F_68 ( F_51 ( V_100 -> V_81 , 4 ) ) ,
V_66 -> V_308 + 2 ) ;
V_100 -> V_81 = F_52 ( & V_7 -> V_111 , V_66 -> V_68 , V_66 -> V_308 ,
V_180 ) ;
if ( V_66 -> V_308 < V_309 )
V_100 -> V_110 = V_309 ;
else
V_100 -> V_110 = V_66 -> V_308 ;
if ( V_178 >= V_2 -> V_96 - 1 )
V_100 -> V_113 |= F_29 ( V_2 , V_179 | V_121 ) ;
else
V_100 -> V_113 |= F_29 ( V_2 , V_179 ) ;
V_2 -> V_106 ++ ;
if ( ! ( F_8 ( V_7 , V_239 ) & F_37 ( V_2 ) ) )
F_6 ( V_7 , F_37 ( V_2 ) , V_239 ) ;
return V_310 ;
}
static struct V_311 * F_128 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
if ( F_2 ( V_2 ) )
return & V_7 -> V_181 ;
if ( ! V_2 -> V_303 )
return & V_7 -> V_181 ;
V_7 -> V_181 . V_312 += F_8 ( V_7 , V_313 ) ;
F_6 ( V_7 , 0 , V_313 ) ;
V_7 -> V_181 . V_314 += F_8 ( V_7 , V_315 ) ;
F_6 ( V_7 , 0 , V_315 ) ;
V_7 -> V_181 . V_215 += F_8 ( V_7 , V_316 ) ;
F_6 ( V_7 , 0 , V_316 ) ;
if ( F_1 ( V_2 ) ) {
V_7 -> V_181 . V_215 += F_8 ( V_7 , V_317 ) ;
F_6 ( V_7 , 0 , V_317 ) ;
V_7 -> V_181 . V_215 += F_8 ( V_7 , V_318 ) ;
F_6 ( V_7 , 0 , V_318 ) ;
} else {
V_7 -> V_181 . V_215 += F_8 ( V_7 , V_319 ) ;
F_6 ( V_7 , 0 , V_319 ) ;
}
return & V_7 -> V_181 ;
}
static int F_129 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_125 ( V_7 ) ;
F_6 ( V_7 , 0x0000 , V_137 ) ;
F_6 ( V_7 , 0 , V_239 ) ;
F_6 ( V_7 , 0 , V_176 ) ;
F_128 ( V_7 ) ;
if ( V_2 -> V_254 ) {
F_130 ( V_2 -> V_254 ) ;
F_131 ( V_2 -> V_254 ) ;
}
F_121 ( V_7 -> V_241 , V_7 ) ;
F_122 ( & V_2 -> V_249 ) ;
F_46 ( V_7 ) ;
F_59 ( V_2 ) ;
F_123 ( & V_2 -> V_299 -> V_111 ) ;
V_2 -> V_303 = 0 ;
return 0 ;
}
static int F_132 ( struct V_6 * V_7 , struct V_320 * V_321 , int V_322 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_253 * V_254 = V_2 -> V_254 ;
if ( ! F_114 ( V_7 ) )
return - V_295 ;
if ( ! V_254 )
return - V_323 ;
return F_133 ( V_254 , V_321 , V_322 ) ;
}
static void * F_134 ( struct V_1 * V_2 ,
int V_178 )
{
return F_135 ( V_2 , V_324 ) + ( V_178 / 8 * 4 ) ;
}
static T_1 F_136 ( int V_178 )
{
return 0x0f << ( 28 - ( ( V_178 % 8 ) * 4 ) ) ;
}
static T_1 F_137 ( struct V_1 * V_2 , int V_178 )
{
return ( 0x08 >> ( V_2 -> V_325 << 1 ) ) << ( 28 - ( ( V_178 % 8 ) * 4 ) ) ;
}
static void F_138 ( struct V_6 * V_7 ,
int V_178 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_326 ;
void * V_3 ;
V_3 = F_134 ( V_2 , V_178 ) ;
V_326 = F_13 ( V_3 ) ;
F_16 ( V_326 | F_137 ( V_2 , V_178 ) , V_3 ) ;
}
static bool F_139 ( struct V_6 * V_7 ,
int V_178 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_327 , V_328 , V_326 ;
void * V_3 ;
V_3 = F_134 ( V_2 , V_178 ) ;
V_327 = F_136 ( V_178 ) ;
V_328 = F_137 ( V_2 , V_178 ) & ~ V_327 ;
V_326 = F_13 ( V_3 ) ;
F_16 ( V_326 & ~ V_327 , V_3 ) ;
return V_326 & V_328 ;
}
static int F_140 ( struct V_6 * V_7 )
{
int V_329 = V_330 * 100 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
while ( ( F_141 ( V_2 , V_331 ) & V_332 ) ) {
F_142 ( 10 ) ;
V_329 -- ;
if ( V_329 <= 0 ) {
F_25 ( V_7 , L_20 , V_298 ) ;
return - V_49 ;
}
}
return 0 ;
}
static int F_143 ( struct V_6 * V_7 , void * V_333 ,
const T_7 * V_81 )
{
T_1 V_132 ;
V_132 = V_81 [ 0 ] << 24 | V_81 [ 1 ] << 16 | V_81 [ 2 ] << 8 | V_81 [ 3 ] ;
F_16 ( V_132 , V_333 ) ;
if ( F_140 ( V_7 ) < 0 )
return - V_334 ;
V_132 = V_81 [ 4 ] << 8 | V_81 [ 5 ] ;
F_16 ( V_132 , V_333 + 4 ) ;
if ( F_140 ( V_7 ) < 0 )
return - V_334 ;
return 0 ;
}
static void F_144 ( void * V_333 , T_7 * V_81 )
{
T_1 V_132 ;
V_132 = F_13 ( V_333 ) ;
V_81 [ 0 ] = ( V_132 >> 24 ) & 0xff ;
V_81 [ 1 ] = ( V_132 >> 16 ) & 0xff ;
V_81 [ 2 ] = ( V_132 >> 8 ) & 0xff ;
V_81 [ 3 ] = V_132 & 0xff ;
V_132 = F_13 ( V_333 + 4 ) ;
V_81 [ 4 ] = ( V_132 >> 8 ) & 0xff ;
V_81 [ 5 ] = V_132 & 0xff ;
}
static int F_145 ( struct V_6 * V_7 , const T_7 * V_81 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
void * V_3 = F_135 ( V_2 , V_335 ) ;
int V_21 ;
T_7 V_336 [ V_78 ] ;
for ( V_21 = 0 ; V_21 < V_337 ; V_21 ++ , V_3 += 8 ) {
F_144 ( V_3 , V_336 ) ;
if ( F_146 ( V_81 , V_336 ) )
return V_21 ;
}
return - V_264 ;
}
static int F_147 ( struct V_6 * V_7 )
{
T_7 V_338 [ V_78 ] ;
int V_178 ;
memset ( V_338 , 0 , sizeof( V_338 ) ) ;
V_178 = F_145 ( V_7 , V_338 ) ;
return ( V_178 < 0 ) ? - V_127 : V_178 ;
}
static int F_148 ( struct V_6 * V_7 ,
int V_178 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
void * V_3 = F_135 ( V_2 , V_335 ) ;
int V_46 ;
T_7 V_338 [ V_78 ] ;
F_20 ( V_2 , F_141 ( V_2 , V_339 ) &
~ ( 1 << ( 31 - V_178 ) ) , V_339 ) ;
memset ( V_338 , 0 , sizeof( V_338 ) ) ;
V_46 = F_143 ( V_7 , V_3 + V_178 * 8 , V_338 ) ;
if ( V_46 < 0 )
return V_46 ;
return 0 ;
}
static int F_149 ( struct V_6 * V_7 , const T_7 * V_81 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
void * V_3 = F_135 ( V_2 , V_335 ) ;
int V_21 , V_46 ;
if ( ! V_2 -> V_32 -> V_340 )
return 0 ;
V_21 = F_145 ( V_7 , V_81 ) ;
if ( V_21 < 0 ) {
V_21 = F_147 ( V_7 ) ;
if ( V_21 < 0 )
return - V_127 ;
V_46 = F_143 ( V_7 , V_3 + V_21 * 8 , V_81 ) ;
if ( V_46 < 0 )
return V_46 ;
F_20 ( V_2 , F_141 ( V_2 , V_339 ) |
( 1 << ( 31 - V_21 ) ) , V_339 ) ;
}
F_138 ( V_7 , V_21 ) ;
return 0 ;
}
static int F_150 ( struct V_6 * V_7 , const T_7 * V_81 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 , V_46 ;
if ( ! V_2 -> V_32 -> V_340 )
return 0 ;
V_21 = F_145 ( V_7 , V_81 ) ;
if ( V_21 ) {
if ( F_139 ( V_7 , V_21 ) )
goto V_341;
V_46 = F_148 ( V_7 , V_21 ) ;
if ( V_46 < 0 )
return V_46 ;
}
V_341:
return 0 ;
}
static int F_151 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_21 , V_46 ;
if ( F_152 ( ! V_2 -> V_32 -> V_340 ) )
return 0 ;
for ( V_21 = 0 ; V_21 < V_337 ; V_21 ++ ) {
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
T_7 V_81 [ V_78 ] ;
void * V_3 = F_135 ( V_2 , V_335 ) ;
int V_21 ;
if ( F_152 ( ! V_2 -> V_32 -> V_340 ) )
return;
for ( V_21 = 0 ; V_21 < V_337 ; V_21 ++ , V_3 += 8 ) {
F_144 ( V_3 , V_81 ) ;
if ( F_154 ( V_81 ) )
F_150 ( V_7 , V_81 ) ;
}
}
static void F_155 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_342 ;
int V_343 = 0 ;
unsigned long V_274 ;
F_100 ( & V_2 -> V_245 , V_274 ) ;
V_342 = ( F_8 ( V_7 , V_15 ) & ~ V_344 ) | V_345 ;
if ( ! ( V_7 -> V_274 & V_346 ) ) {
F_153 ( V_7 ) ;
V_343 = 1 ;
}
if ( V_7 -> V_274 & V_347 ) {
F_153 ( V_7 ) ;
V_342 &= ~ V_345 ;
V_343 = 1 ;
}
if ( V_7 -> V_274 & V_348 ) {
F_151 ( V_7 ) ;
V_342 = ( V_342 & ~ V_345 ) | V_344 ;
} else if ( V_2 -> V_32 -> V_340 ) {
struct V_349 * V_350 ;
F_156 (ha, ndev) {
if ( V_343 && F_154 ( V_350 -> V_81 ) )
continue;
if ( F_149 ( V_7 , V_350 -> V_81 ) < 0 ) {
if ( ! V_343 ) {
F_153 ( V_7 ) ;
V_342 &= ~ V_345 ;
V_343 = 1 ;
}
}
}
} else {
V_342 = ( V_342 & ~ V_344 ) | V_345 ;
}
F_6 ( V_7 , V_342 , V_15 ) ;
F_102 ( & V_2 -> V_245 , V_274 ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_325 )
return V_351 ;
else
return V_352 ;
}
static int F_158 ( struct V_6 * V_7 ,
T_8 V_353 , T_4 V_354 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_355 = F_157 ( V_2 ) ;
if ( F_152 ( ! V_2 -> V_32 -> V_340 ) )
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
static int F_159 ( struct V_6 * V_7 ,
T_8 V_353 , T_4 V_354 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_355 = F_157 ( V_2 ) ;
if ( F_152 ( ! V_2 -> V_32 -> V_340 ) )
return - V_356 ;
if ( ! V_354 )
return 0 ;
V_2 -> V_357 -- ;
F_20 ( V_2 , 0 , V_355 ) ;
return 0 ;
}
static void F_160 ( struct V_1 * V_2 )
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
static int F_161 ( struct V_1 * V_2 )
{
F_162 ( V_2 -> V_268 ) ;
F_163 ( V_2 -> V_268 ) ;
return 0 ;
}
static int F_164 ( struct V_1 * V_2 ,
struct V_381 * V_382 )
{
int V_46 , V_21 ;
struct V_86 * V_87 ;
struct V_383 * V_299 = V_2 -> V_299 ;
struct V_384 * V_111 = & V_2 -> V_299 -> V_111 ;
V_87 = F_165 ( V_111 , sizeof( struct V_86 ) , V_126 ) ;
if ( ! V_87 )
return - V_127 ;
V_87 -> V_81 = V_2 -> V_81 + V_2 -> V_3 [ V_385 ] ;
V_87 -> V_88 = V_382 -> V_386 ;
V_87 -> V_91 = V_387 ;
V_87 -> V_90 = V_388 ;
V_87 -> V_89 = V_389 ;
V_87 -> V_92 = V_390 ;
V_87 -> V_84 . V_391 = & V_392 ;
V_2 -> V_268 = F_166 ( & V_87 -> V_84 ) ;
if ( ! V_2 -> V_268 )
return - V_127 ;
V_2 -> V_268 -> V_271 = L_21 ;
V_2 -> V_268 -> V_261 = V_111 ;
snprintf ( V_2 -> V_268 -> V_269 , V_266 , L_22 ,
V_299 -> V_271 , V_299 -> V_269 ) ;
V_2 -> V_268 -> V_241 = F_167 ( V_111 , V_393 , sizeof( int ) ,
V_126 ) ;
if ( ! V_2 -> V_268 -> V_241 ) {
V_46 = - V_127 ;
goto V_394;
}
if ( V_111 -> V_262 ) {
V_46 = F_168 ( V_2 -> V_268 , V_111 -> V_262 ) ;
} else {
for ( V_21 = 0 ; V_21 < V_393 ; V_21 ++ )
V_2 -> V_268 -> V_241 [ V_21 ] = V_395 ;
if ( V_382 -> V_396 > 0 )
V_2 -> V_268 -> V_241 [ V_382 -> V_397 ] = V_382 -> V_396 ;
V_46 = F_169 ( V_2 -> V_268 ) ;
}
if ( V_46 )
goto V_394;
return 0 ;
V_394:
F_163 ( V_2 -> V_268 ) ;
return V_46 ;
}
static const T_4 * F_170 ( int V_398 )
{
const T_4 * V_3 = NULL ;
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
static struct V_381 * F_171 ( struct V_384 * V_111 )
{
struct V_259 * V_260 = V_111 -> V_262 ;
struct V_381 * V_407 ;
const char * V_408 ;
V_407 = F_165 ( V_111 , sizeof( * V_407 ) , V_126 ) ;
if ( ! V_407 )
return NULL ;
V_407 -> V_9 = F_172 ( V_260 ) ;
V_408 = F_173 ( V_260 ) ;
if ( V_408 )
memcpy ( V_407 -> V_408 , V_408 , V_78 ) ;
V_407 -> V_218 =
F_174 ( V_260 , L_23 ) ;
V_407 -> V_221 =
F_174 ( V_260 , L_24 ) ;
return V_407 ;
}
static inline struct V_381 * F_171 ( struct V_384 * V_111 )
{
return NULL ;
}
static int F_175 ( struct V_383 * V_299 )
{
int V_46 , V_409 = 0 ;
struct V_410 * V_411 ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_381 * V_382 = F_176 ( & V_299 -> V_111 ) ;
const struct V_412 * V_269 = F_177 ( V_299 ) ;
V_411 = F_178 ( V_299 , V_413 , 0 ) ;
if ( F_152 ( V_411 == NULL ) ) {
F_179 ( & V_299 -> V_111 , L_25 ) ;
return - V_295 ;
}
V_7 = F_180 ( sizeof( struct V_1 ) ) ;
if ( ! V_7 )
return - V_127 ;
F_181 ( & V_299 -> V_111 ) ;
F_118 ( & V_299 -> V_111 ) ;
V_7 -> V_414 = V_411 -> V_131 ;
V_409 = V_299 -> V_269 ;
if ( V_409 < 0 )
V_409 = 0 ;
V_7 -> V_415 = - 1 ;
V_46 = F_182 ( V_299 , 0 ) ;
if ( V_46 < 0 ) {
V_46 = - V_323 ;
goto V_416;
}
V_7 -> V_241 = V_46 ;
F_183 ( V_7 , & V_299 -> V_111 ) ;
V_2 = F_4 ( V_7 ) ;
V_2 -> V_96 = V_417 ;
V_2 -> V_94 = V_418 ;
V_2 -> V_81 = F_184 ( & V_299 -> V_111 , V_411 ) ;
if ( F_94 ( V_2 -> V_81 ) ) {
V_46 = F_95 ( V_2 -> V_81 ) ;
goto V_416;
}
F_185 ( & V_2 -> V_245 ) ;
V_2 -> V_299 = V_299 ;
if ( V_299 -> V_111 . V_262 )
V_382 = F_171 ( & V_299 -> V_111 ) ;
if ( ! V_382 ) {
F_179 ( & V_299 -> V_111 , L_26 ) ;
V_46 = - V_295 ;
goto V_416;
}
V_2 -> V_265 = V_382 -> V_397 ;
V_2 -> V_9 = V_382 -> V_9 ;
V_2 -> V_71 = V_382 -> V_71 ;
V_2 -> V_218 = V_382 -> V_218 ;
V_2 -> V_221 = V_382 -> V_221 ;
if ( V_269 ) {
V_2 -> V_32 = (struct V_31 * ) V_269 -> V_419 ;
} else {
const struct V_420 * V_421 ;
V_421 = F_186 ( F_187 ( V_422 ) ,
& V_299 -> V_111 ) ;
V_2 -> V_32 = (struct V_31 * ) V_421 -> V_68 ;
}
V_2 -> V_3 = F_170 ( V_2 -> V_32 -> V_398 ) ;
if ( ! V_2 -> V_3 ) {
F_179 ( & V_299 -> V_111 , L_27 ,
V_2 -> V_32 -> V_398 ) ;
V_46 = - V_295 ;
goto V_416;
}
F_23 ( V_2 -> V_32 ) ;
if ( V_2 -> V_32 -> V_340 )
V_7 -> V_423 = & V_424 ;
else
V_7 -> V_423 = & V_425 ;
V_7 -> V_426 = & V_427 ;
V_7 -> V_428 = V_429 ;
V_2 -> V_277 = V_430 ;
F_36 ( V_7 , V_382 -> V_408 ) ;
if ( ! F_188 ( V_7 -> V_74 ) ) {
F_189 ( & V_299 -> V_111 ,
L_28 ) ;
F_190 ( V_7 ) ;
}
if ( V_2 -> V_32 -> V_340 ) {
struct V_410 * V_431 ;
V_431 = F_178 ( V_299 , V_413 , 1 ) ;
V_2 -> V_432 = F_184 ( & V_299 -> V_111 , V_431 ) ;
if ( F_94 ( V_2 -> V_432 ) ) {
V_46 = F_95 ( V_2 -> V_432 ) ;
goto V_416;
}
V_2 -> V_325 = V_409 % 2 ;
V_7 -> V_433 = V_434 ;
}
if ( ! V_409 || V_382 -> V_435 ) {
if ( V_2 -> V_32 -> V_436 )
V_2 -> V_32 -> V_436 ( V_7 ) ;
if ( V_2 -> V_32 -> V_340 ) {
F_160 ( V_2 ) ;
}
}
V_46 = F_164 ( V_2 , V_382 ) ;
if ( V_46 ) {
F_179 ( & V_7 -> V_111 , L_29 ) ;
goto V_416;
}
F_191 ( V_7 , & V_2 -> V_249 , F_84 , 64 ) ;
V_46 = F_192 ( V_7 ) ;
if ( V_46 )
goto V_437;
F_96 ( V_7 , L_30 ,
( T_1 ) V_7 -> V_414 , V_7 -> V_74 , V_7 -> V_241 ) ;
F_193 ( & V_299 -> V_111 ) ;
F_194 ( V_299 , V_7 ) ;
return V_46 ;
V_437:
F_195 ( & V_2 -> V_249 ) ;
F_161 ( V_2 ) ;
V_416:
if ( V_7 )
F_196 ( V_7 ) ;
F_193 ( & V_299 -> V_111 ) ;
F_197 ( & V_299 -> V_111 ) ;
return V_46 ;
}
static int F_198 ( struct V_383 * V_299 )
{
struct V_6 * V_7 = F_199 ( V_299 ) ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_200 ( V_7 ) ;
F_195 ( & V_2 -> V_249 ) ;
F_161 ( V_2 ) ;
F_197 ( & V_299 -> V_111 ) ;
F_196 ( V_7 ) ;
return 0 ;
}
static int F_201 ( struct V_384 * V_111 )
{
return 0 ;
}
