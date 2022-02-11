static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
F_3 ( V_2 , F_4 ( V_2 , V_6 ) | V_7 , V_6 ) ;
else
F_3 ( V_2 , F_4 ( V_2 , V_6 ) & ~ V_7 , V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_8 ) {
case 10 :
F_3 ( V_2 , F_4 ( V_2 , V_6 ) & ~ V_9 , V_6 ) ;
break;
case 100 :
F_3 ( V_2 , F_4 ( V_2 , V_6 ) | V_9 , V_6 ) ;
break;
default:
break;
}
}
static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
F_3 ( V_2 , F_4 ( V_2 , V_6 ) | V_7 , V_6 ) ;
else
F_3 ( V_2 , F_4 ( V_2 , V_6 ) & ~ V_7 , V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_8 ) {
case 10 :
F_3 ( V_2 , 0 , V_10 ) ;
break;
case 100 :
F_3 ( V_2 , 1 , V_10 ) ;
break;
default:
break;
}
}
static void F_6 ( struct V_1 * V_2 )
{
int V_11 ;
unsigned long V_12 [ 2 ] , V_13 [ 2 ] ;
for ( V_11 = 0 ; V_11 < 2 ; V_11 ++ ) {
V_13 [ V_11 ] = F_7 ( ( void * ) F_8 ( V_11 ) ) ;
V_12 [ V_11 ] = F_7 ( ( void * ) F_9 ( V_11 ) ) ;
}
F_10 ( V_14 , ( void * ) ( V_15 + 0x1800 ) ) ;
F_11 ( 1 ) ;
for ( V_11 = 0 ; V_11 < 2 ; V_11 ++ ) {
F_10 ( V_13 [ V_11 ] , ( void * ) F_8 ( V_11 ) ) ;
F_10 ( V_12 [ V_11 ] , ( void * ) F_9 ( V_11 ) ) ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_16 = 100 ;
if ( F_13 ( V_4 ) ) {
F_3 ( V_2 , 0x03 , V_17 ) ;
F_3 ( V_2 , F_4 ( V_2 , V_18 ) | V_19 ,
V_18 ) ;
while ( V_16 > 0 ) {
if ( ! ( F_4 ( V_2 , V_18 ) & 0x3 ) )
break;
F_11 ( 1 ) ;
V_16 -- ;
}
if ( V_16 < 0 )
F_14 ( V_20 L_1 ) ;
F_3 ( V_2 , 0x0 , V_21 ) ;
F_3 ( V_2 , 0x0 , V_22 ) ;
F_3 ( V_2 , 0x0 , V_23 ) ;
F_3 ( V_2 , 0x0 , V_24 ) ;
F_3 ( V_2 , 0x0 , V_25 ) ;
F_3 ( V_2 , 0x0 , V_26 ) ;
F_3 ( V_2 , 0x0 , V_27 ) ;
F_3 ( V_2 , 0x0 , V_28 ) ;
} else {
F_3 ( V_2 , F_4 ( V_2 , V_18 ) | V_29 ,
V_18 ) ;
F_11 ( 3 ) ;
F_3 ( V_2 , F_4 ( V_2 , V_18 ) & ~ V_29 ,
V_18 ) ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
F_3 ( V_2 , F_4 ( V_2 , V_6 ) | V_7 , V_6 ) ;
else
F_3 ( V_2 , F_4 ( V_2 , V_6 ) & ~ V_7 , V_6 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_8 ) {
case 10 :
F_3 ( V_2 , 0x00000000 , V_30 ) ;
break;
case 100 :
F_3 ( V_2 , 0x00000010 , V_30 ) ;
break;
case 1000 :
F_3 ( V_2 , 0x00000020 , V_30 ) ;
break;
default:
break;
}
}
static struct V_31 * F_17 ( struct V_3 * V_4 )
{
if ( F_13 ( V_4 ) )
return & V_32 ;
else
return & V_33 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_19 ( V_4 , V_14 , V_34 ) ;
F_11 ( 1 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
int V_16 = 100 ;
F_3 ( V_2 , V_35 , V_17 ) ;
F_3 ( V_2 , F_4 ( V_2 , V_18 ) | V_19 , V_18 ) ;
while ( V_16 > 0 ) {
if ( ! ( F_4 ( V_2 , V_18 ) & 0x3 ) )
break;
F_11 ( 1 ) ;
V_16 -- ;
}
if ( V_16 == 0 )
F_14 ( V_20 L_1 ) ;
F_3 ( V_2 , 0x0 , V_21 ) ;
F_3 ( V_2 , 0x0 , V_22 ) ;
F_3 ( V_2 , 0x0 , V_23 ) ;
F_3 ( V_2 , 0x0 , V_24 ) ;
F_3 ( V_2 , 0x0 , V_25 ) ;
F_3 ( V_2 , 0x0 , V_26 ) ;
F_3 ( V_2 , 0x0 , V_27 ) ;
F_3 ( V_2 , 0x0 , V_28 ) ;
}
static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
F_3 ( V_2 , F_4 ( V_2 , V_6 ) | V_7 , V_6 ) ;
else
F_3 ( V_2 , F_4 ( V_2 , V_6 ) & ~ V_7 , V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_8 ) {
case 10 :
F_3 ( V_2 , V_36 , V_30 ) ;
break;
case 100 :
F_3 ( V_2 , V_37 , V_30 ) ;
break;
case 1000 :
F_3 ( V_2 , V_38 , V_30 ) ;
break;
default:
break;
}
}
static void F_20 ( struct V_31 * V_39 )
{
if ( ! V_39 -> V_40 )
V_39 -> V_40 = V_41 ;
if ( ! V_39 -> V_42 )
V_39 -> V_42 = V_43 ;
if ( ! V_39 -> V_44 )
V_39 -> V_44 = V_45 | \
V_46 ;
if ( ! V_39 -> V_47 )
V_39 -> V_47 = V_48 ;
if ( ! V_39 -> V_49 )
V_39 -> V_49 = V_50 ;
if ( ! V_39 -> V_51 )
V_39 -> V_51 = V_52 ;
if ( ! V_39 -> V_53 )
V_39 -> V_53 = V_54 ;
if ( ! V_39 -> V_55 )
V_39 -> V_55 = V_56 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_4 ( V_2 , V_18 ) | V_29 , V_18 ) ;
F_11 ( 3 ) ;
F_3 ( V_2 , F_4 ( V_2 , V_18 ) & ~ V_29 , V_18 ) ;
}
static void F_21 ( struct V_57 * V_58 )
{
int V_59 ;
V_59 = V_60 - ( ( V_61 ) V_58 -> V_62 & ( V_60 - 1 ) ) ;
if ( V_59 )
F_22 ( V_58 , V_59 ) ;
}
static void F_21 ( struct V_57 * V_58 )
{
F_22 ( V_58 , V_63 ) ;
}
static inline T_1 F_23 ( struct V_3 * V_4 , V_61 V_64 )
{
switch ( V_4 -> V_65 ) {
case V_66 :
return F_24 ( V_64 ) ;
case V_67 :
return F_25 ( V_64 ) ;
}
return V_64 ;
}
static inline T_1 F_26 ( struct V_3 * V_4 , V_61 V_64 )
{
switch ( V_4 -> V_65 ) {
case V_66 :
return F_27 ( V_64 ) ;
case V_67 :
return F_28 ( V_64 ) ;
}
return V_64 ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_3 ( V_2 ,
( V_2 -> V_68 [ 0 ] << 24 ) | ( V_2 -> V_68 [ 1 ] << 16 ) |
( V_2 -> V_68 [ 2 ] << 8 ) | ( V_2 -> V_68 [ 3 ] ) , V_69 ) ;
F_3 ( V_2 ,
( V_2 -> V_68 [ 4 ] << 8 ) | ( V_2 -> V_68 [ 5 ] ) , V_70 ) ;
}
static void F_30 ( struct V_1 * V_2 , unsigned char * V_71 )
{
if ( V_71 [ 0 ] || V_71 [ 1 ] || V_71 [ 2 ] || V_71 [ 3 ] || V_71 [ 4 ] || V_71 [ 5 ] ) {
memcpy ( V_2 -> V_68 , V_71 , 6 ) ;
} else {
V_2 -> V_68 [ 0 ] = ( F_4 ( V_2 , V_69 ) >> 24 ) ;
V_2 -> V_68 [ 1 ] = ( F_4 ( V_2 , V_69 ) >> 16 ) & 0xFF ;
V_2 -> V_68 [ 2 ] = ( F_4 ( V_2 , V_69 ) >> 8 ) & 0xFF ;
V_2 -> V_68 [ 3 ] = ( F_4 ( V_2 , V_69 ) & 0xFF ) ;
V_2 -> V_68 [ 4 ] = ( F_4 ( V_2 , V_70 ) >> 8 ) & 0xFF ;
V_2 -> V_68 [ 5 ] = ( F_4 ( V_2 , V_70 ) & 0xFF ) ;
}
}
static int F_13 ( struct V_3 * V_4 )
{
if ( V_4 -> V_72 == V_73 )
return 1 ;
else
return 0 ;
}
static unsigned long F_31 ( struct V_3 * V_4 )
{
if ( F_13 ( V_4 ) )
return V_74 ;
else
return V_75 ;
}
static void F_32 ( void * V_76 , V_61 V_77 )
{
F_10 ( F_7 ( V_76 ) | V_77 , V_76 ) ;
}
static void F_33 ( void * V_76 , V_61 V_77 )
{
F_10 ( ( F_7 ( V_76 ) & ~ V_77 ) , V_76 ) ;
}
static int F_34 ( void * V_76 , V_61 V_77 )
{
return ( F_7 ( V_76 ) & V_77 ) != 0 ;
}
static void F_35 ( struct V_78 * V_79 , int V_80 )
{
struct V_81 * V_82 = F_36 ( V_79 , struct V_81 , V_79 ) ;
if ( V_82 -> V_83 )
V_82 -> V_83 ( V_82 -> V_76 ) ;
if ( V_80 )
F_32 ( V_82 -> V_76 , V_82 -> V_84 ) ;
else
F_33 ( V_82 -> V_76 , V_82 -> V_84 ) ;
}
static void F_37 ( struct V_78 * V_79 , int V_80 )
{
struct V_81 * V_82 = F_36 ( V_79 , struct V_81 , V_79 ) ;
if ( V_82 -> V_83 )
V_82 -> V_83 ( V_82 -> V_76 ) ;
if ( V_80 )
F_32 ( V_82 -> V_76 , V_82 -> V_85 ) ;
else
F_33 ( V_82 -> V_76 , V_82 -> V_85 ) ;
}
static int F_38 ( struct V_78 * V_79 )
{
struct V_81 * V_82 = F_36 ( V_79 , struct V_81 , V_79 ) ;
if ( V_82 -> V_83 )
V_82 -> V_83 ( V_82 -> V_76 ) ;
return F_34 ( V_82 -> V_76 , V_82 -> V_86 ) ;
}
static void F_39 ( struct V_78 * V_79 , int V_80 )
{
struct V_81 * V_82 = F_36 ( V_79 , struct V_81 , V_79 ) ;
if ( V_82 -> V_83 )
V_82 -> V_83 ( V_82 -> V_76 ) ;
if ( V_80 )
F_32 ( V_82 -> V_76 , V_82 -> V_87 ) ;
else
F_33 ( V_82 -> V_76 , V_82 -> V_87 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_11 ;
if ( V_4 -> V_88 ) {
for ( V_11 = 0 ; V_11 < V_89 ; V_11 ++ ) {
if ( V_4 -> V_88 [ V_11 ] )
F_41 ( V_4 -> V_88 [ V_11 ] ) ;
}
}
F_42 ( V_4 -> V_88 ) ;
if ( V_4 -> V_90 ) {
for ( V_11 = 0 ; V_11 < V_91 ; V_11 ++ ) {
if ( V_4 -> V_90 [ V_11 ] )
F_41 ( V_4 -> V_90 [ V_11 ] ) ;
}
}
F_42 ( V_4 -> V_90 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_11 ;
struct V_57 * V_58 ;
struct V_92 * V_93 = NULL ;
struct V_94 * V_95 = NULL ;
int V_96 = sizeof( * V_93 ) * V_89 ;
int V_97 = sizeof( * V_95 ) * V_91 ;
V_4 -> V_98 = V_4 -> V_99 = 0 ;
V_4 -> V_100 = V_4 -> V_101 = 0 ;
memset ( V_4 -> V_102 , 0 , V_96 ) ;
for ( V_11 = 0 ; V_11 < V_89 ; V_11 ++ ) {
V_4 -> V_88 [ V_11 ] = NULL ;
V_58 = F_44 ( V_4 -> V_103 ) ;
V_4 -> V_88 [ V_11 ] = V_58 ;
if ( V_58 == NULL )
break;
F_45 ( & V_2 -> V_104 , V_58 -> V_105 , V_4 -> V_103 ,
V_106 ) ;
V_58 -> V_104 = V_2 ;
F_21 ( V_58 ) ;
V_93 = & V_4 -> V_102 [ V_11 ] ;
V_93 -> V_76 = F_46 ( F_47 ( V_58 -> V_62 , 4 ) ) ;
V_93 -> V_107 = F_23 ( V_4 , V_108 | V_109 ) ;
V_93 -> V_110 = F_48 ( V_4 -> V_103 , 16 ) ;
if ( V_11 == 0 ) {
F_3 ( V_2 , V_4 -> V_111 , V_25 ) ;
if ( F_13 ( V_4 ) )
F_3 ( V_2 , V_4 -> V_111 , V_26 ) ;
}
}
V_4 -> V_100 = ( V_61 ) ( V_11 - V_89 ) ;
V_93 -> V_107 |= F_23 ( V_4 , V_112 ) ;
memset ( V_4 -> V_113 , 0 , V_97 ) ;
for ( V_11 = 0 ; V_11 < V_91 ; V_11 ++ ) {
V_4 -> V_90 [ V_11 ] = NULL ;
V_95 = & V_4 -> V_113 [ V_11 ] ;
V_95 -> V_107 = F_23 ( V_4 , V_114 ) ;
V_95 -> V_110 = 0 ;
if ( V_11 == 0 ) {
F_3 ( V_2 , V_4 -> V_115 , V_21 ) ;
if ( F_13 ( V_4 ) )
F_3 ( V_2 , V_4 -> V_115 , V_22 ) ;
}
}
V_95 -> V_107 |= F_23 ( V_4 , V_116 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_96 , V_97 , V_117 = 0 ;
V_4 -> V_103 = ( V_2 -> V_118 <= 1492 ? V_119 :
( ( ( V_2 -> V_118 + 26 + 7 ) & ~ 7 ) + 2 + 16 ) ) ;
if ( V_4 -> V_39 -> V_120 )
V_4 -> V_103 += V_121 ;
V_4 -> V_88 = F_50 ( sizeof( * V_4 -> V_88 ) * V_89 ,
V_122 ) ;
if ( ! V_4 -> V_88 ) {
F_51 ( & V_2 -> V_104 , L_2 ) ;
V_117 = - V_123 ;
return V_117 ;
}
V_4 -> V_90 = F_50 ( sizeof( * V_4 -> V_90 ) * V_91 ,
V_122 ) ;
if ( ! V_4 -> V_90 ) {
F_51 ( & V_2 -> V_104 , L_3 ) ;
V_117 = - V_123 ;
goto V_124;
}
V_96 = sizeof( struct V_92 ) * V_89 ;
V_4 -> V_102 = F_52 ( NULL , V_96 , & V_4 -> V_111 ,
V_122 ) ;
if ( ! V_4 -> V_102 ) {
F_51 ( & V_2 -> V_104 , L_4 ,
V_96 ) ;
V_117 = - V_123 ;
goto V_125;
}
V_4 -> V_100 = 0 ;
V_97 = sizeof( struct V_94 ) * V_91 ;
V_4 -> V_113 = F_52 ( NULL , V_97 , & V_4 -> V_115 ,
V_122 ) ;
if ( ! V_4 -> V_113 ) {
F_51 ( & V_2 -> V_104 , L_5 ,
V_97 ) ;
V_117 = - V_123 ;
goto V_125;
}
return V_117 ;
V_125:
F_53 ( NULL , V_96 , V_4 -> V_102 , V_4 -> V_111 ) ;
V_124:
F_40 ( V_2 ) ;
return V_117 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_117 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_126 , V_127 ;
V_61 V_128 ;
F_12 ( V_2 ) ;
F_43 ( V_2 ) ;
if ( V_4 -> V_39 -> V_120 )
F_3 ( V_2 , V_4 -> V_39 -> V_129 , V_130 ) ;
F_3 ( V_2 , 0 , V_131 ) ;
#if F_55 ( V_132 )
if ( V_4 -> V_39 -> V_133 )
F_3 ( V_2 , V_134 , V_18 ) ;
else
#endif
F_3 ( V_2 , 0 , V_18 ) ;
F_3 ( V_2 , V_4 -> V_39 -> V_47 , V_135 ) ;
F_3 ( V_2 , 0 , V_136 ) ;
F_3 ( V_2 , V_4 -> V_39 -> V_49 , V_137 ) ;
V_126 = V_4 -> V_126 = V_138 | V_139 ;
V_127 = V_4 -> V_127 = V_140 ;
F_3 ( V_2 , V_126 | V_127 , V_141 ) ;
if ( V_4 -> V_39 -> V_142 )
F_3 ( V_2 , 0x800 , V_143 ) ;
F_3 ( V_2 , V_4 -> V_39 -> V_44 , V_144 ) ;
if ( ! V_4 -> V_39 -> V_145 )
F_3 ( V_2 , 0 , V_146 ) ;
F_3 ( V_2 , V_147 , V_148 ) ;
F_3 ( V_2 , F_4 ( V_2 , V_149 ) , V_149 ) ;
F_3 ( V_2 , V_4 -> V_39 -> V_150 , V_131 ) ;
V_128 = ( F_4 ( V_2 , V_6 ) & V_7 ) |
V_151 | ( V_4 -> V_5 ? V_7 : 0 ) | V_152 | V_153 ;
F_3 ( V_2 , V_128 , V_6 ) ;
if ( V_4 -> V_39 -> V_154 )
V_4 -> V_39 -> V_154 ( V_2 ) ;
F_3 ( V_2 , V_4 -> V_39 -> V_40 , V_155 ) ;
F_3 ( V_2 , V_4 -> V_39 -> V_42 , V_156 ) ;
F_29 ( V_2 ) ;
if ( V_4 -> V_39 -> V_157 )
F_3 ( V_2 , V_158 , V_159 ) ;
if ( V_4 -> V_39 -> V_160 )
F_3 ( V_2 , V_161 , V_162 ) ;
if ( V_4 -> V_39 -> V_163 )
F_3 ( V_2 , V_164 , V_165 ) ;
F_3 ( V_2 , V_166 , V_167 ) ;
F_56 ( V_2 ) ;
return V_117 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_94 * V_95 ;
int V_168 = 0 ;
int V_169 = 0 ;
for (; V_4 -> V_99 - V_4 -> V_101 > 0 ; V_4 -> V_101 ++ ) {
V_169 = V_4 -> V_101 % V_91 ;
V_95 = & V_4 -> V_113 [ V_169 ] ;
if ( V_95 -> V_107 & F_23 ( V_4 , V_170 ) )
break;
if ( V_4 -> V_90 [ V_169 ] ) {
F_58 ( & V_2 -> V_104 , V_95 -> V_76 ,
V_95 -> V_110 , V_171 ) ;
F_59 ( V_4 -> V_90 [ V_169 ] ) ;
V_4 -> V_90 [ V_169 ] = NULL ;
V_168 ++ ;
}
V_95 -> V_107 = F_23 ( V_4 , V_114 ) ;
if ( V_169 >= V_91 - 1 )
V_95 -> V_107 |= F_23 ( V_4 , V_116 ) ;
V_4 -> V_172 . V_173 ++ ;
V_4 -> V_172 . V_174 += V_95 -> V_110 ;
}
return V_168 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_92 * V_93 ;
int V_169 = V_4 -> V_98 % V_89 ;
int V_175 = ( V_4 -> V_100 + V_89 ) - V_4 -> V_98 ;
struct V_57 * V_58 ;
T_3 V_176 = 0 ;
V_61 V_177 ;
V_93 = & V_4 -> V_102 [ V_169 ] ;
while ( ! ( V_93 -> V_107 & F_23 ( V_4 , V_108 ) ) ) {
V_177 = F_26 ( V_4 , V_93 -> V_107 ) ;
V_176 = V_93 -> V_178 ;
if ( -- V_175 < 0 )
break;
if ( ! ( V_177 & V_179 ) )
V_4 -> V_172 . V_180 ++ ;
if ( V_177 & ( V_181 | V_182 | V_183 | V_184 |
V_185 | V_186 | V_187 ) ) {
V_4 -> V_172 . V_188 ++ ;
if ( V_177 & V_181 )
V_4 -> V_172 . V_189 ++ ;
if ( V_177 & V_182 )
V_4 -> V_172 . V_190 ++ ;
if ( V_177 & V_183 )
V_4 -> V_172 . V_180 ++ ;
if ( V_177 & V_184 )
V_4 -> V_172 . V_180 ++ ;
if ( V_177 & V_186 )
V_4 -> V_172 . V_191 ++ ;
if ( V_177 & V_187 )
V_4 -> V_172 . V_192 ++ ;
} else {
if ( ! V_4 -> V_39 -> V_133 )
F_61 (
F_62 ( F_48 ( V_93 -> V_76 , 4 ) ) ,
V_176 + 2 ) ;
V_58 = V_4 -> V_88 [ V_169 ] ;
V_4 -> V_88 [ V_169 ] = NULL ;
if ( V_4 -> V_39 -> V_120 )
F_22 ( V_58 , V_121 ) ;
F_63 ( V_58 , V_176 ) ;
V_58 -> V_193 = F_64 ( V_58 , V_2 ) ;
F_65 ( V_58 ) ;
V_4 -> V_172 . V_194 ++ ;
V_4 -> V_172 . V_195 += V_176 ;
}
V_93 -> V_107 |= F_23 ( V_4 , V_108 ) ;
V_169 = ( ++ V_4 -> V_98 ) % V_89 ;
V_93 = & V_4 -> V_102 [ V_169 ] ;
}
for (; V_4 -> V_98 - V_4 -> V_100 > 0 ; V_4 -> V_100 ++ ) {
V_169 = V_4 -> V_100 % V_89 ;
V_93 = & V_4 -> V_102 [ V_169 ] ;
V_93 -> V_110 = F_48 ( V_4 -> V_103 , 16 ) ;
if ( V_4 -> V_88 [ V_169 ] == NULL ) {
V_58 = F_44 ( V_4 -> V_103 ) ;
V_4 -> V_88 [ V_169 ] = V_58 ;
if ( V_58 == NULL )
break;
F_45 ( & V_2 -> V_104 , V_58 -> V_105 , V_4 -> V_103 ,
V_106 ) ;
V_58 -> V_104 = V_2 ;
F_21 ( V_58 ) ;
F_66 ( V_58 ) ;
V_93 -> V_76 = F_46 ( F_47 ( V_58 -> V_62 , 4 ) ) ;
}
if ( V_169 >= V_89 - 1 )
V_93 -> V_107 |=
F_23 ( V_4 , V_108 | V_109 | V_112 ) ;
else
V_93 -> V_107 |=
F_23 ( V_4 , V_108 | V_109 ) ;
}
if ( ! ( F_4 ( V_2 , V_167 ) & V_166 ) )
F_3 ( V_2 , V_166 , V_167 ) ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_4 ( V_2 , V_6 ) &
~ ( V_153 | V_152 ) , V_6 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_4 ( V_2 , V_6 ) |
( V_153 | V_152 ) , V_6 ) ;
}
static void F_69 ( struct V_1 * V_2 , int V_196 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_61 V_197 ;
V_61 V_198 ;
V_61 V_199 ;
if ( V_196 & V_200 ) {
V_197 = F_4 ( V_2 , V_155 ) ;
F_3 ( V_2 , V_197 , V_155 ) ;
if ( V_197 & V_201 )
V_4 -> V_172 . V_202 ++ ;
if ( V_197 & V_203 ) {
if ( V_4 -> V_39 -> V_204 || V_4 -> V_205 ) {
if ( V_4 -> V_206 == V_207 )
V_198 = 0 ;
else
V_198 = V_208 ;
} else {
V_198 = ( F_4 ( V_2 , V_209 ) ) ;
if ( V_4 -> V_210 )
V_198 = ~ V_198 ;
}
if ( ! ( V_198 & V_208 ) )
F_67 ( V_2 ) ;
else {
F_3 ( V_2 , F_4 ( V_2 , V_131 ) &
~ V_211 , V_131 ) ;
F_3 ( V_2 , F_4 ( V_2 , V_155 ) ,
V_155 ) ;
F_3 ( V_2 , F_4 ( V_2 , V_131 ) |
V_211 , V_131 ) ;
F_68 ( V_2 ) ;
}
}
}
if ( V_196 & V_212 ) {
if ( V_196 & V_213 )
V_4 -> V_172 . V_214 ++ ;
if ( F_70 ( V_4 ) )
F_51 ( & V_2 -> V_104 , L_6 ) ;
}
if ( V_196 & V_215 ) {
if ( V_196 & V_216 ) {
V_4 -> V_172 . V_190 ++ ;
if ( F_71 ( V_4 ) )
F_51 ( & V_2 -> V_104 , L_7 ) ;
}
}
if ( V_196 & V_217 ) {
V_4 -> V_172 . V_218 ++ ;
if ( F_70 ( V_4 ) )
F_51 ( & V_2 -> V_104 , L_8 ) ;
}
if ( V_196 & V_219 ) {
V_4 -> V_172 . V_218 ++ ;
if ( F_70 ( V_4 ) )
F_51 ( & V_2 -> V_104 , L_9 ) ;
}
if ( V_196 & V_220 ) {
V_4 -> V_172 . V_192 ++ ;
if ( F_4 ( V_2 , V_167 ) ^ V_166 )
F_3 ( V_2 , V_166 , V_167 ) ;
if ( F_71 ( V_4 ) )
F_51 ( & V_2 -> V_104 , L_10 ) ;
}
if ( V_196 & V_221 ) {
V_4 -> V_172 . V_222 ++ ;
if ( F_71 ( V_4 ) )
F_51 ( & V_2 -> V_104 , L_11 ) ;
}
if ( ! V_4 -> V_39 -> V_223 && ( V_196 & V_224 ) ) {
V_4 -> V_172 . V_218 ++ ;
if ( F_70 ( V_4 ) )
F_51 ( & V_2 -> V_104 , L_12 ) ;
}
V_199 = V_212 | V_213 | V_224 | V_217 | V_219 ;
if ( V_4 -> V_39 -> V_223 )
V_199 &= ~ V_224 ;
if ( V_196 & V_199 ) {
V_61 V_225 = F_4 ( V_2 , V_226 ) ;
F_51 ( & V_2 -> V_104 , L_13 ,
V_196 , V_4 -> V_99 ) ;
F_51 ( & V_2 -> V_104 , L_14 ,
V_4 -> V_101 , ( V_61 ) V_2 -> V_227 , V_225 ) ;
F_57 ( V_2 ) ;
if ( V_225 ^ F_31 ( V_4 ) ) {
F_3 ( V_2 , F_31 ( V_4 ) , V_226 ) ;
}
F_72 ( V_2 ) ;
}
}
static T_4 F_73 ( int V_228 , void * V_229 )
{
struct V_1 * V_2 = V_229 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_31 * V_39 = V_4 -> V_39 ;
T_4 V_117 = V_230 ;
V_61 V_196 = 0 ;
F_74 ( & V_4 -> V_231 ) ;
V_196 = F_4 ( V_2 , V_149 ) ;
if ( V_196 & ( V_232 | V_233 | V_234 |
V_235 | V_236 | V_237 | V_238 |
V_39 -> V_51 | V_39 -> V_53 ) ) {
F_3 ( V_2 , V_196 , V_149 ) ;
V_117 = V_239 ;
} else
goto V_240;
if ( V_196 & ( V_232 |
V_233 |
V_234 |
V_235 |
V_236 |
V_237 |
V_238 ) ) {
F_60 ( V_2 ) ;
}
if ( V_196 & V_39 -> V_51 ) {
F_57 ( V_2 ) ;
F_72 ( V_2 ) ;
}
if ( V_196 & V_39 -> V_53 )
F_69 ( V_2 , V_196 ) ;
V_240:
F_75 ( & V_4 -> V_231 ) ;
return V_117 ;
}
static void F_76 ( unsigned long V_62 )
{
struct V_1 * V_2 = (struct V_1 * ) V_62 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_77 ( & V_4 -> V_241 , V_242 + ( 10 * V_243 ) ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_244 * V_245 = V_4 -> V_245 ;
int V_246 = 0 ;
if ( V_245 -> V_206 != V_207 ) {
if ( V_245 -> V_5 != V_4 -> V_5 ) {
V_246 = 1 ;
V_4 -> V_5 = V_245 -> V_5 ;
if ( V_4 -> V_39 -> V_247 )
V_4 -> V_39 -> V_247 ( V_2 ) ;
}
if ( V_245 -> V_8 != V_4 -> V_8 ) {
V_246 = 1 ;
V_4 -> V_8 = V_245 -> V_8 ;
if ( V_4 -> V_39 -> V_154 )
V_4 -> V_39 -> V_154 ( V_2 ) ;
}
if ( V_4 -> V_206 == V_207 ) {
F_3 ( V_2 ,
( F_4 ( V_2 , V_6 ) & ~ V_248 ) , V_6 ) ;
V_246 = 1 ;
V_4 -> V_206 = V_245 -> V_206 ;
}
} else if ( V_4 -> V_206 ) {
V_246 = 1 ;
V_4 -> V_206 = V_207 ;
V_4 -> V_8 = 0 ;
V_4 -> V_5 = - 1 ;
}
if ( V_246 && F_79 ( V_4 ) )
F_80 ( V_245 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
char V_249 [ V_250 + 3 ] ;
struct V_244 * V_245 = NULL ;
snprintf ( V_249 , sizeof( V_249 ) , V_251 ,
V_4 -> V_252 -> V_253 , V_4 -> V_249 ) ;
V_4 -> V_206 = V_207 ;
V_4 -> V_8 = 0 ;
V_4 -> V_5 = - 1 ;
V_245 = F_82 ( V_2 , V_249 , F_78 ,
0 , V_4 -> V_254 ) ;
if ( F_83 ( V_245 ) ) {
F_51 ( & V_2 -> V_104 , L_15 ) ;
return F_84 ( V_245 ) ;
}
F_85 ( & V_2 -> V_104 , L_16 ,
V_245 -> V_76 , V_245 -> V_255 -> V_256 ) ;
V_4 -> V_245 = V_245 ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_117 ;
V_117 = F_81 ( V_2 ) ;
if ( V_117 )
return V_117 ;
F_87 ( V_4 -> V_245 , V_257 , V_258 ) ;
F_88 ( V_4 -> V_245 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_259 * V_260 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_261 ;
int V_117 ;
F_90 ( & V_4 -> V_231 , V_261 ) ;
V_117 = F_91 ( V_4 -> V_245 , V_260 ) ;
F_92 ( & V_4 -> V_231 , V_261 ) ;
return V_117 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_259 * V_260 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_261 ;
int V_117 ;
F_90 ( & V_4 -> V_231 , V_261 ) ;
F_67 ( V_2 ) ;
V_117 = F_94 ( V_4 -> V_245 , V_260 ) ;
if ( V_117 )
goto V_262;
if ( V_260 -> V_5 == V_263 )
V_4 -> V_5 = 1 ;
else
V_4 -> V_5 = 0 ;
if ( V_4 -> V_39 -> V_247 )
V_4 -> V_39 -> V_247 ( V_2 ) ;
V_262:
F_11 ( 1 ) ;
F_68 ( V_2 ) ;
F_92 ( & V_4 -> V_231 , V_261 ) ;
return V_117 ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_261 ;
int V_117 ;
F_90 ( & V_4 -> V_231 , V_261 ) ;
V_117 = F_96 ( V_4 -> V_245 ) ;
F_92 ( & V_4 -> V_231 , V_261 ) ;
return V_117 ;
}
static V_61 F_97 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_264 ;
}
static void F_98 ( struct V_1 * V_2 , V_61 V_265 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_264 = V_265 ;
}
static int F_99 ( struct V_1 * V_229 , int V_266 )
{
switch ( V_266 ) {
case V_267 :
return V_268 ;
default:
return - V_269 ;
}
}
static void F_100 ( struct V_1 * V_2 ,
struct V_270 * V_172 , T_5 * V_62 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_11 = 0 ;
V_62 [ V_11 ++ ] = V_4 -> V_98 ;
V_62 [ V_11 ++ ] = V_4 -> V_99 ;
V_62 [ V_11 ++ ] = V_4 -> V_100 ;
V_62 [ V_11 ++ ] = V_4 -> V_101 ;
}
static void F_101 ( struct V_1 * V_2 , V_61 V_271 , T_6 * V_62 )
{
switch ( V_271 ) {
case V_267 :
memcpy ( V_62 , * V_272 ,
sizeof( V_272 ) ) ;
break;
}
}
static int F_102 ( struct V_1 * V_2 )
{
int V_117 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_103 ( & V_4 -> V_273 -> V_104 ) ;
V_117 = F_104 ( V_2 -> V_228 , F_73 ,
#if F_55 ( V_274 ) || \
F_55 ( V_275 ) || \
F_55 ( V_276 )
V_277 ,
#else
0 ,
#endif
V_2 -> V_256 , V_2 ) ;
if ( V_117 ) {
F_51 ( & V_2 -> V_104 , L_17 ) ;
return V_117 ;
}
V_117 = F_49 ( V_2 ) ;
if ( V_117 )
goto V_278;
V_117 = F_54 ( V_2 ) ;
if ( V_117 )
goto V_278;
V_117 = F_86 ( V_2 ) ;
if ( V_117 )
goto V_278;
F_105 ( & V_4 -> V_241 ) ;
V_4 -> V_241 . V_279 = ( V_242 + ( 24 * V_243 ) ) / 10 ;
F_106 ( & V_4 -> V_241 , F_76 , ( unsigned long ) V_2 ) ;
return V_117 ;
V_278:
F_107 ( V_2 -> V_228 , V_2 ) ;
F_108 ( & V_4 -> V_273 -> V_104 ) ;
return V_117 ;
}
static void F_109 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_92 * V_93 ;
int V_11 ;
F_110 ( V_2 ) ;
if ( F_111 ( V_4 ) )
F_51 ( & V_2 -> V_104 , L_18
L_19 , V_2 -> V_256 , ( int ) F_4 ( V_2 , V_149 ) ) ;
V_4 -> V_172 . V_280 ++ ;
F_112 ( & V_4 -> V_241 ) ;
for ( V_11 = 0 ; V_11 < V_89 ; V_11 ++ ) {
V_93 = & V_4 -> V_102 [ V_11 ] ;
V_93 -> V_107 = 0 ;
V_93 -> V_76 = 0xBADF00D0 ;
if ( V_4 -> V_88 [ V_11 ] )
F_41 ( V_4 -> V_88 [ V_11 ] ) ;
V_4 -> V_88 [ V_11 ] = NULL ;
}
for ( V_11 = 0 ; V_11 < V_91 ; V_11 ++ ) {
if ( V_4 -> V_90 [ V_11 ] )
F_41 ( V_4 -> V_90 [ V_11 ] ) ;
V_4 -> V_90 [ V_11 ] = NULL ;
}
F_54 ( V_2 ) ;
V_4 -> V_241 . V_279 = ( V_242 + ( 24 * V_243 ) ) / 10 ;
F_113 ( & V_4 -> V_241 ) ;
}
static int F_114 ( struct V_57 * V_58 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_94 * V_95 ;
V_61 V_169 ;
unsigned long V_261 ;
F_90 ( & V_4 -> V_231 , V_261 ) ;
if ( ( V_4 -> V_99 - V_4 -> V_101 ) >= ( V_91 - 4 ) ) {
if ( ! F_57 ( V_2 ) ) {
if ( F_115 ( V_4 ) )
F_116 ( & V_2 -> V_104 , L_20 ) ;
F_110 ( V_2 ) ;
F_92 ( & V_4 -> V_231 , V_261 ) ;
return V_281 ;
}
}
F_92 ( & V_4 -> V_231 , V_261 ) ;
V_169 = V_4 -> V_99 % V_91 ;
V_4 -> V_90 [ V_169 ] = V_58 ;
V_95 = & V_4 -> V_113 [ V_169 ] ;
if ( ! V_4 -> V_39 -> V_133 )
F_61 ( F_62 ( F_48 ( V_95 -> V_76 , 4 ) ) ,
V_58 -> V_282 + 2 ) ;
V_95 -> V_76 = F_45 ( & V_2 -> V_104 , V_58 -> V_62 , V_58 -> V_282 ,
V_171 ) ;
if ( V_58 -> V_282 < V_283 )
V_95 -> V_110 = V_283 ;
else
V_95 -> V_110 = V_58 -> V_282 ;
if ( V_169 >= V_91 - 1 )
V_95 -> V_107 |= F_23 ( V_4 , V_170 | V_116 ) ;
else
V_95 -> V_107 |= F_23 ( V_4 , V_170 ) ;
V_4 -> V_99 ++ ;
if ( ! ( F_4 ( V_2 , V_226 ) & F_31 ( V_4 ) ) )
F_3 ( V_2 , F_31 ( V_4 ) , V_226 ) ;
return V_284 ;
}
static int F_117 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_285 ;
F_110 ( V_2 ) ;
F_3 ( V_2 , 0x0000 , V_131 ) ;
F_3 ( V_2 , 0 , V_226 ) ;
F_3 ( V_2 , 0 , V_167 ) ;
if ( V_4 -> V_245 ) {
F_118 ( V_4 -> V_245 ) ;
F_119 ( V_4 -> V_245 ) ;
}
F_107 ( V_2 -> V_228 , V_2 ) ;
F_112 ( & V_4 -> V_241 ) ;
F_40 ( V_2 ) ;
V_285 = sizeof( struct V_92 ) * V_89 ;
F_53 ( NULL , V_285 , V_4 -> V_102 , V_4 -> V_111 ) ;
V_285 = sizeof( struct V_94 ) * V_91 ;
F_53 ( NULL , V_285 , V_4 -> V_113 , V_4 -> V_115 ) ;
F_108 ( & V_4 -> V_273 -> V_104 ) ;
return 0 ;
}
static struct V_286 * F_120 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_103 ( & V_4 -> V_273 -> V_104 ) ;
V_4 -> V_172 . V_287 += F_4 ( V_2 , V_288 ) ;
F_3 ( V_2 , 0 , V_288 ) ;
V_4 -> V_172 . V_289 += F_4 ( V_2 , V_290 ) ;
F_3 ( V_2 , 0 , V_290 ) ;
V_4 -> V_172 . V_202 += F_4 ( V_2 , V_291 ) ;
F_3 ( V_2 , 0 , V_291 ) ;
if ( F_13 ( V_4 ) ) {
V_4 -> V_172 . V_202 += F_4 ( V_2 , V_292 ) ;
F_3 ( V_2 , 0 , V_292 ) ;
V_4 -> V_172 . V_202 += F_4 ( V_2 , V_293 ) ;
F_3 ( V_2 , 0 , V_293 ) ;
} else {
V_4 -> V_172 . V_202 += F_4 ( V_2 , V_294 ) ;
F_3 ( V_2 , 0 , V_294 ) ;
}
F_108 ( & V_4 -> V_273 -> V_104 ) ;
return & V_4 -> V_172 ;
}
static int F_121 ( struct V_1 * V_2 , struct V_295 * V_296 ,
int V_297 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_244 * V_245 = V_4 -> V_245 ;
if ( ! F_122 ( V_2 ) )
return - V_298 ;
if ( ! V_245 )
return - V_299 ;
return F_123 ( V_245 , V_296 , V_297 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
if ( V_2 -> V_261 & V_300 ) {
F_3 ( V_2 , ( F_4 ( V_2 , V_6 ) & ~ V_301 ) |
V_302 , V_6 ) ;
} else {
F_3 ( V_2 , ( F_4 ( V_2 , V_6 ) & ~ V_302 ) |
V_301 , V_6 ) ;
}
}
static void F_125 ( struct V_3 * V_4 )
{
F_19 ( V_4 , 0 , V_303 ) ;
F_19 ( V_4 , 0 , V_304 ) ;
F_19 ( V_4 , 0 , V_305 ) ;
F_19 ( V_4 , 0xc , V_306 ) ;
F_19 ( V_4 , 0xc , V_307 ) ;
F_19 ( V_4 , 0 , V_308 ) ;
F_19 ( V_4 , 0 , V_309 ) ;
F_19 ( V_4 , 0 , V_310 ) ;
F_19 ( V_4 , 0 , V_311 ) ;
F_19 ( V_4 , V_312 | V_313 , V_314 ) ;
if ( F_13 ( V_4 ) ) {
F_19 ( V_4 , 0 , V_315 ) ;
F_19 ( V_4 , 0 , V_316 ) ;
} else {
F_19 ( V_4 , 0 , V_317 ) ;
F_19 ( V_4 , 0 , V_318 ) ;
}
F_19 ( V_4 , 0 , V_319 ) ;
F_19 ( V_4 , 0 , V_320 ) ;
F_19 ( V_4 , 0 , V_321 ) ;
F_19 ( V_4 , 0 , V_322 ) ;
F_19 ( V_4 , 0 , V_323 ) ;
F_19 ( V_4 , 0 , V_324 ) ;
F_19 ( V_4 , 0 , V_325 ) ;
}
static int F_126 ( struct V_1 * V_2 )
{
struct V_252 * V_326 = F_127 ( & V_2 -> V_104 ) ;
F_128 ( V_326 ) ;
F_129 ( & V_2 -> V_104 , NULL ) ;
F_42 ( V_326 -> V_228 ) ;
F_130 ( V_326 ) ;
return 0 ;
}
static int F_131 ( struct V_1 * V_2 , int V_253 ,
struct V_327 * V_328 )
{
int V_117 , V_11 ;
struct V_81 * V_82 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_82 = F_132 ( sizeof( struct V_81 ) , V_122 ) ;
if ( ! V_82 ) {
V_117 = - V_123 ;
goto V_329;
}
V_82 -> V_76 = V_4 -> V_76 + V_4 -> V_72 [ V_330 ] ;
V_82 -> V_83 = V_328 -> V_331 ;
V_82 -> V_86 = 0x08 ;
V_82 -> V_85 = 0x04 ;
V_82 -> V_84 = 0x02 ;
V_82 -> V_87 = 0x01 ;
V_82 -> V_79 . V_332 = & V_333 ;
V_4 -> V_252 = F_133 ( & V_82 -> V_79 ) ;
if ( ! V_4 -> V_252 ) {
V_117 = - V_123 ;
goto V_334;
}
V_4 -> V_252 -> V_256 = L_21 ;
V_4 -> V_252 -> V_335 = & V_2 -> V_104 ;
snprintf ( V_4 -> V_252 -> V_253 , V_250 , L_22 , V_253 ) ;
V_4 -> V_252 -> V_228 = F_50 ( sizeof( int ) * V_336 , V_122 ) ;
if ( ! V_4 -> V_252 -> V_228 ) {
V_117 = - V_123 ;
goto V_337;
}
for ( V_11 = 0 ; V_11 < V_336 ; V_11 ++ )
V_4 -> V_252 -> V_228 [ V_11 ] = V_338 ;
V_117 = F_134 ( V_4 -> V_252 ) ;
if ( V_117 )
goto V_278;
F_129 ( & V_2 -> V_104 , V_4 -> V_252 ) ;
return 0 ;
V_278:
F_42 ( V_4 -> V_252 -> V_228 ) ;
V_337:
F_130 ( V_4 -> V_252 ) ;
V_334:
F_42 ( V_82 ) ;
V_329:
return V_117 ;
}
static const T_3 * F_135 ( int V_339 )
{
const T_3 * V_72 = NULL ;
switch ( V_339 ) {
case V_340 :
V_72 = V_73 ;
break;
case V_341 :
V_72 = V_342 ;
break;
case V_343 :
V_72 = V_344 ;
break;
default:
F_14 ( V_20 L_23 , V_339 ) ;
break;
}
return V_72 ;
}
static int F_136 ( struct V_345 * V_273 )
{
int V_117 , V_346 = 0 ;
struct V_347 * V_348 ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_327 * V_328 ;
V_348 = F_137 ( V_273 , V_349 , 0 ) ;
if ( F_138 ( V_348 == NULL ) ) {
F_51 ( & V_273 -> V_104 , L_24 ) ;
V_117 = - V_298 ;
goto V_329;
}
V_2 = F_139 ( sizeof( struct V_3 ) ) ;
if ( ! V_2 ) {
F_51 ( & V_273 -> V_104 , L_25 ) ;
V_117 = - V_123 ;
goto V_329;
}
V_2 -> V_350 = V_348 -> V_351 ;
V_346 = V_273 -> V_253 ;
if ( V_346 < 0 )
V_346 = 0 ;
V_2 -> V_352 = - 1 ;
V_117 = F_140 ( V_273 , 0 ) ;
if ( V_117 < 0 ) {
V_117 = - V_299 ;
goto V_353;
}
V_2 -> V_228 = V_117 ;
F_141 ( V_2 , & V_273 -> V_104 ) ;
F_142 ( V_2 ) ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_76 = F_143 ( V_348 -> V_351 , F_144 ( V_348 ) ) ;
if ( V_4 -> V_76 == NULL ) {
V_117 = - V_123 ;
F_51 ( & V_273 -> V_104 , L_26 ) ;
goto V_353;
}
F_145 ( & V_4 -> V_231 ) ;
V_4 -> V_273 = V_273 ;
F_146 ( & V_273 -> V_104 ) ;
F_147 ( & V_273 -> V_104 ) ;
V_328 = (struct V_327 * ) ( V_273 -> V_104 . V_354 ) ;
V_4 -> V_249 = V_328 -> V_355 ;
V_4 -> V_254 = V_328 -> V_254 ;
V_4 -> V_65 = V_328 -> V_65 ;
V_4 -> V_205 = V_328 -> V_205 ;
V_4 -> V_210 = V_328 -> V_210 ;
V_4 -> V_72 = F_135 ( V_328 -> V_339 ) ;
#if F_55 ( V_356 )
V_4 -> V_39 = F_17 ( V_4 ) ;
#else
V_4 -> V_39 = & V_33 ;
#endif
F_20 ( V_4 -> V_39 ) ;
V_2 -> V_357 = & V_358 ;
F_148 ( V_2 , & V_359 ) ;
V_2 -> V_360 = V_361 ;
V_4 -> V_264 = V_362 ;
V_4 -> V_363 = V_364 >> ( V_346 << 1 ) ;
V_4 -> V_365 = V_366 >> ( V_346 << 1 ) ;
F_30 ( V_2 , V_328 -> V_367 ) ;
if ( ! V_346 ) {
if ( V_4 -> V_39 -> V_368 ) {
struct V_347 * V_369 ;
V_369 = F_137 ( V_273 , V_349 , 1 ) ;
if ( ! V_369 ) {
F_51 ( & V_273 -> V_104 , L_27 ) ;
goto V_353;
}
V_4 -> V_370 = F_143 ( V_369 -> V_351 ,
F_144 ( V_369 ) ) ;
}
if ( V_4 -> V_39 -> V_371 )
V_4 -> V_39 -> V_371 ( V_2 ) ;
if ( V_4 -> V_39 -> V_368 ) {
F_125 ( V_4 ) ;
}
}
V_117 = F_149 ( V_2 ) ;
if ( V_117 )
goto V_353;
V_117 = F_131 ( V_2 , V_273 -> V_253 , V_328 ) ;
if ( V_117 )
goto V_372;
F_150 ( L_28 ,
( V_61 ) V_2 -> V_350 , V_2 -> V_68 , V_2 -> V_228 ) ;
F_151 ( V_273 , V_2 ) ;
return V_117 ;
V_372:
F_152 ( V_2 ) ;
V_353:
if ( V_4 && V_4 -> V_76 )
F_153 ( V_4 -> V_76 ) ;
if ( V_4 && V_4 -> V_370 )
F_153 ( V_4 -> V_370 ) ;
if ( V_2 )
F_154 ( V_2 ) ;
V_329:
return V_117 ;
}
static int F_155 ( struct V_345 * V_273 )
{
struct V_1 * V_2 = F_156 ( V_273 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_153 ( V_4 -> V_370 ) ;
F_126 ( V_2 ) ;
F_152 ( V_2 ) ;
F_157 ( & V_273 -> V_104 ) ;
F_153 ( V_4 -> V_76 ) ;
F_154 ( V_2 ) ;
F_151 ( V_273 , NULL ) ;
return 0 ;
}
static int F_158 ( struct V_373 * V_104 )
{
return 0 ;
}
static int T_7 F_159 ( void )
{
return F_160 ( & V_374 ) ;
}
static void T_8 F_161 ( void )
{
F_162 ( & V_374 ) ;
}
