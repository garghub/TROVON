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
F_20 ( V_2 ) ;
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
static void F_20 ( struct V_1 * V_2 )
{
if ( V_33 . V_39 )
F_3 ( V_2 , 0x0 , V_40 ) ;
}
static void F_21 ( struct V_31 * V_41 )
{
if ( ! V_41 -> V_42 )
V_41 -> V_42 = V_43 ;
if ( ! V_41 -> V_44 )
V_41 -> V_44 = V_45 ;
if ( ! V_41 -> V_46 )
V_41 -> V_46 = V_47 | \
V_48 ;
if ( ! V_41 -> V_49 )
V_41 -> V_49 = V_50 ;
if ( ! V_41 -> V_51 )
V_41 -> V_51 = V_52 ;
if ( ! V_41 -> V_53 )
V_41 -> V_53 = V_54 ;
if ( ! V_41 -> V_55 )
V_41 -> V_55 = V_56 ;
if ( ! V_41 -> V_57 )
V_41 -> V_57 = V_58 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_4 ( V_2 , V_18 ) | V_29 , V_18 ) ;
F_11 ( 3 ) ;
F_3 ( V_2 , F_4 ( V_2 , V_18 ) & ~ V_29 , V_18 ) ;
}
static void F_22 ( struct V_59 * V_60 )
{
int V_61 ;
V_61 = V_62 - ( ( V_63 ) V_60 -> V_64 & ( V_62 - 1 ) ) ;
if ( V_61 )
F_23 ( V_60 , V_61 ) ;
}
static void F_22 ( struct V_59 * V_60 )
{
F_23 ( V_60 , V_65 ) ;
}
static inline T_1 F_24 ( struct V_3 * V_4 , V_63 V_66 )
{
switch ( V_4 -> V_67 ) {
case V_68 :
return F_25 ( V_66 ) ;
case V_69 :
return F_26 ( V_66 ) ;
}
return V_66 ;
}
static inline T_1 F_27 ( struct V_3 * V_4 , V_63 V_66 )
{
switch ( V_4 -> V_67 ) {
case V_68 :
return F_28 ( V_66 ) ;
case V_69 :
return F_29 ( V_66 ) ;
}
return V_66 ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_3 ( V_2 ,
( V_2 -> V_70 [ 0 ] << 24 ) | ( V_2 -> V_70 [ 1 ] << 16 ) |
( V_2 -> V_70 [ 2 ] << 8 ) | ( V_2 -> V_70 [ 3 ] ) , V_71 ) ;
F_3 ( V_2 ,
( V_2 -> V_70 [ 4 ] << 8 ) | ( V_2 -> V_70 [ 5 ] ) , V_72 ) ;
}
static void F_31 ( struct V_1 * V_2 , unsigned char * V_73 )
{
if ( V_73 [ 0 ] || V_73 [ 1 ] || V_73 [ 2 ] || V_73 [ 3 ] || V_73 [ 4 ] || V_73 [ 5 ] ) {
memcpy ( V_2 -> V_70 , V_73 , 6 ) ;
} else {
V_2 -> V_70 [ 0 ] = ( F_4 ( V_2 , V_71 ) >> 24 ) ;
V_2 -> V_70 [ 1 ] = ( F_4 ( V_2 , V_71 ) >> 16 ) & 0xFF ;
V_2 -> V_70 [ 2 ] = ( F_4 ( V_2 , V_71 ) >> 8 ) & 0xFF ;
V_2 -> V_70 [ 3 ] = ( F_4 ( V_2 , V_71 ) & 0xFF ) ;
V_2 -> V_70 [ 4 ] = ( F_4 ( V_2 , V_72 ) >> 8 ) & 0xFF ;
V_2 -> V_70 [ 5 ] = ( F_4 ( V_2 , V_72 ) & 0xFF ) ;
}
}
static int F_13 ( struct V_3 * V_4 )
{
if ( V_4 -> V_74 == V_75 )
return 1 ;
else
return 0 ;
}
static unsigned long F_32 ( struct V_3 * V_4 )
{
if ( F_13 ( V_4 ) )
return V_76 ;
else
return V_77 ;
}
static void F_33 ( void * V_78 , V_63 V_79 )
{
F_10 ( F_7 ( V_78 ) | V_79 , V_78 ) ;
}
static void F_34 ( void * V_78 , V_63 V_79 )
{
F_10 ( ( F_7 ( V_78 ) & ~ V_79 ) , V_78 ) ;
}
static int F_35 ( void * V_78 , V_63 V_79 )
{
return ( F_7 ( V_78 ) & V_79 ) != 0 ;
}
static void F_36 ( struct V_80 * V_81 , int V_82 )
{
struct V_83 * V_84 = F_37 ( V_81 , struct V_83 , V_81 ) ;
if ( V_84 -> V_85 )
V_84 -> V_85 ( V_84 -> V_78 ) ;
if ( V_82 )
F_33 ( V_84 -> V_78 , V_84 -> V_86 ) ;
else
F_34 ( V_84 -> V_78 , V_84 -> V_86 ) ;
}
static void F_38 ( struct V_80 * V_81 , int V_82 )
{
struct V_83 * V_84 = F_37 ( V_81 , struct V_83 , V_81 ) ;
if ( V_84 -> V_85 )
V_84 -> V_85 ( V_84 -> V_78 ) ;
if ( V_82 )
F_33 ( V_84 -> V_78 , V_84 -> V_87 ) ;
else
F_34 ( V_84 -> V_78 , V_84 -> V_87 ) ;
}
static int F_39 ( struct V_80 * V_81 )
{
struct V_83 * V_84 = F_37 ( V_81 , struct V_83 , V_81 ) ;
if ( V_84 -> V_85 )
V_84 -> V_85 ( V_84 -> V_78 ) ;
return F_35 ( V_84 -> V_78 , V_84 -> V_88 ) ;
}
static void F_40 ( struct V_80 * V_81 , int V_82 )
{
struct V_83 * V_84 = F_37 ( V_81 , struct V_83 , V_81 ) ;
if ( V_84 -> V_85 )
V_84 -> V_85 ( V_84 -> V_78 ) ;
if ( V_82 )
F_33 ( V_84 -> V_78 , V_84 -> V_89 ) ;
else
F_34 ( V_84 -> V_78 , V_84 -> V_89 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_11 ;
if ( V_4 -> V_90 ) {
for ( V_11 = 0 ; V_11 < V_91 ; V_11 ++ ) {
if ( V_4 -> V_90 [ V_11 ] )
F_42 ( V_4 -> V_90 [ V_11 ] ) ;
}
}
F_43 ( V_4 -> V_90 ) ;
if ( V_4 -> V_92 ) {
for ( V_11 = 0 ; V_11 < V_93 ; V_11 ++ ) {
if ( V_4 -> V_92 [ V_11 ] )
F_42 ( V_4 -> V_92 [ V_11 ] ) ;
}
}
F_43 ( V_4 -> V_92 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_11 ;
struct V_59 * V_60 ;
struct V_94 * V_95 = NULL ;
struct V_96 * V_97 = NULL ;
int V_98 = sizeof( * V_95 ) * V_91 ;
int V_99 = sizeof( * V_97 ) * V_93 ;
V_4 -> V_100 = V_4 -> V_101 = 0 ;
V_4 -> V_102 = V_4 -> V_103 = 0 ;
memset ( V_4 -> V_104 , 0 , V_98 ) ;
for ( V_11 = 0 ; V_11 < V_91 ; V_11 ++ ) {
V_4 -> V_90 [ V_11 ] = NULL ;
V_60 = F_45 ( V_2 , V_4 -> V_105 ) ;
V_4 -> V_90 [ V_11 ] = V_60 ;
if ( V_60 == NULL )
break;
F_46 ( & V_2 -> V_106 , V_60 -> V_64 , V_4 -> V_105 ,
V_107 ) ;
F_22 ( V_60 ) ;
V_95 = & V_4 -> V_104 [ V_11 ] ;
V_95 -> V_78 = F_47 ( F_48 ( V_60 -> V_64 , 4 ) ) ;
V_95 -> V_108 = F_24 ( V_4 , V_109 | V_110 ) ;
V_95 -> V_111 = F_49 ( V_4 -> V_105 , 16 ) ;
if ( V_11 == 0 ) {
F_3 ( V_2 , V_4 -> V_112 , V_25 ) ;
if ( F_13 ( V_4 ) )
F_3 ( V_2 , V_4 -> V_112 , V_26 ) ;
}
}
V_4 -> V_102 = ( V_63 ) ( V_11 - V_91 ) ;
V_95 -> V_108 |= F_24 ( V_4 , V_113 ) ;
memset ( V_4 -> V_114 , 0 , V_99 ) ;
for ( V_11 = 0 ; V_11 < V_93 ; V_11 ++ ) {
V_4 -> V_92 [ V_11 ] = NULL ;
V_97 = & V_4 -> V_114 [ V_11 ] ;
V_97 -> V_108 = F_24 ( V_4 , V_115 ) ;
V_97 -> V_111 = 0 ;
if ( V_11 == 0 ) {
F_3 ( V_2 , V_4 -> V_116 , V_21 ) ;
if ( F_13 ( V_4 ) )
F_3 ( V_2 , V_4 -> V_116 , V_22 ) ;
}
}
V_97 -> V_108 |= F_24 ( V_4 , V_117 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_98 , V_99 , V_118 = 0 ;
V_4 -> V_105 = ( V_2 -> V_119 <= 1492 ? V_120 :
( ( ( V_2 -> V_119 + 26 + 7 ) & ~ 7 ) + 2 + 16 ) ) ;
if ( V_4 -> V_41 -> V_121 )
V_4 -> V_105 += V_122 ;
V_4 -> V_90 = F_51 ( sizeof( * V_4 -> V_90 ) * V_91 ,
V_123 ) ;
if ( ! V_4 -> V_90 ) {
F_52 ( & V_2 -> V_106 , L_2 ) ;
V_118 = - V_124 ;
return V_118 ;
}
V_4 -> V_92 = F_51 ( sizeof( * V_4 -> V_92 ) * V_93 ,
V_123 ) ;
if ( ! V_4 -> V_92 ) {
F_52 ( & V_2 -> V_106 , L_3 ) ;
V_118 = - V_124 ;
goto V_125;
}
V_98 = sizeof( struct V_94 ) * V_91 ;
V_4 -> V_104 = F_53 ( NULL , V_98 , & V_4 -> V_112 ,
V_123 ) ;
if ( ! V_4 -> V_104 ) {
F_52 ( & V_2 -> V_106 , L_4 ,
V_98 ) ;
V_118 = - V_124 ;
goto V_126;
}
V_4 -> V_102 = 0 ;
V_99 = sizeof( struct V_96 ) * V_93 ;
V_4 -> V_114 = F_53 ( NULL , V_99 , & V_4 -> V_116 ,
V_123 ) ;
if ( ! V_4 -> V_114 ) {
F_52 ( & V_2 -> V_106 , L_5 ,
V_99 ) ;
V_118 = - V_124 ;
goto V_126;
}
return V_118 ;
V_126:
F_54 ( NULL , V_98 , V_4 -> V_104 , V_4 -> V_112 ) ;
V_125:
F_41 ( V_2 ) ;
return V_118 ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_118 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_127 , V_128 ;
V_63 V_129 ;
F_12 ( V_2 ) ;
F_44 ( V_2 ) ;
if ( V_4 -> V_41 -> V_121 )
F_3 ( V_2 , V_4 -> V_41 -> V_130 , V_131 ) ;
F_3 ( V_2 , 0 , V_132 ) ;
#if F_56 ( V_133 )
if ( V_4 -> V_41 -> V_134 )
F_3 ( V_2 , V_135 , V_18 ) ;
else
#endif
F_3 ( V_2 , 0 , V_18 ) ;
F_3 ( V_2 , V_4 -> V_41 -> V_49 , V_136 ) ;
F_3 ( V_2 , 0 , V_137 ) ;
F_3 ( V_2 , V_4 -> V_41 -> V_51 , V_138 ) ;
V_127 = V_4 -> V_127 = V_139 | V_140 ;
V_128 = V_4 -> V_128 = V_141 ;
F_3 ( V_2 , V_127 | V_128 , V_142 ) ;
if ( V_4 -> V_41 -> V_143 )
F_3 ( V_2 , 0x800 , V_144 ) ;
F_3 ( V_2 , V_4 -> V_41 -> V_46 , V_145 ) ;
if ( ! V_4 -> V_41 -> V_146 )
F_3 ( V_2 , 0 , V_147 ) ;
F_3 ( V_2 , V_2 -> V_119 + V_148 + V_149 + V_150 ,
V_151 ) ;
F_3 ( V_2 , F_4 ( V_2 , V_152 ) , V_152 ) ;
F_3 ( V_2 , V_4 -> V_41 -> V_153 , V_132 ) ;
V_129 = ( F_4 ( V_2 , V_6 ) & V_7 ) |
V_154 | ( V_4 -> V_5 ? V_7 : 0 ) | V_155 | V_156 ;
F_3 ( V_2 , V_129 , V_6 ) ;
if ( V_4 -> V_41 -> V_157 )
V_4 -> V_41 -> V_157 ( V_2 ) ;
F_3 ( V_2 , V_4 -> V_41 -> V_42 , V_158 ) ;
F_3 ( V_2 , V_4 -> V_41 -> V_44 , V_159 ) ;
F_30 ( V_2 ) ;
if ( V_4 -> V_41 -> V_160 )
F_3 ( V_2 , V_161 , V_162 ) ;
if ( V_4 -> V_41 -> V_163 )
F_3 ( V_2 , V_164 , V_165 ) ;
if ( V_4 -> V_41 -> V_166 )
F_3 ( V_2 , V_167 , V_168 ) ;
F_3 ( V_2 , V_169 , V_170 ) ;
F_57 ( V_2 ) ;
return V_118 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_96 * V_97 ;
int V_171 = 0 ;
int V_172 = 0 ;
for (; V_4 -> V_101 - V_4 -> V_103 > 0 ; V_4 -> V_103 ++ ) {
V_172 = V_4 -> V_103 % V_93 ;
V_97 = & V_4 -> V_114 [ V_172 ] ;
if ( V_97 -> V_108 & F_24 ( V_4 , V_173 ) )
break;
if ( V_4 -> V_92 [ V_172 ] ) {
F_59 ( & V_2 -> V_106 , V_97 -> V_78 ,
V_97 -> V_111 , V_174 ) ;
F_60 ( V_4 -> V_92 [ V_172 ] ) ;
V_4 -> V_92 [ V_172 ] = NULL ;
V_171 ++ ;
}
V_97 -> V_108 = F_24 ( V_4 , V_115 ) ;
if ( V_172 >= V_93 - 1 )
V_97 -> V_108 |= F_24 ( V_4 , V_117 ) ;
V_2 -> V_175 . V_176 ++ ;
V_2 -> V_175 . V_177 += V_97 -> V_111 ;
}
return V_171 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_94 * V_95 ;
int V_172 = V_4 -> V_100 % V_91 ;
int V_178 = ( V_4 -> V_102 + V_91 ) - V_4 -> V_100 ;
struct V_59 * V_60 ;
T_3 V_179 = 0 ;
V_63 V_180 ;
V_95 = & V_4 -> V_104 [ V_172 ] ;
while ( ! ( V_95 -> V_108 & F_24 ( V_4 , V_109 ) ) ) {
V_180 = F_27 ( V_4 , V_95 -> V_108 ) ;
V_179 = V_95 -> V_181 ;
if ( -- V_178 < 0 )
break;
if ( ! ( V_180 & V_182 ) )
V_2 -> V_175 . V_183 ++ ;
if ( V_180 & ( V_184 | V_185 | V_186 | V_187 |
V_188 | V_189 | V_190 ) ) {
V_2 -> V_175 . V_191 ++ ;
if ( V_180 & V_184 )
V_2 -> V_175 . V_192 ++ ;
if ( V_180 & V_185 )
V_2 -> V_175 . V_193 ++ ;
if ( V_180 & V_186 )
V_2 -> V_175 . V_183 ++ ;
if ( V_180 & V_187 )
V_2 -> V_175 . V_183 ++ ;
if ( V_180 & V_189 )
V_2 -> V_175 . V_194 ++ ;
if ( V_180 & V_190 )
V_2 -> V_175 . V_195 ++ ;
} else {
if ( ! V_4 -> V_41 -> V_134 )
F_62 (
F_63 ( F_49 ( V_95 -> V_78 , 4 ) ) ,
V_179 + 2 ) ;
V_60 = V_4 -> V_90 [ V_172 ] ;
V_4 -> V_90 [ V_172 ] = NULL ;
if ( V_4 -> V_41 -> V_121 )
F_23 ( V_60 , V_122 ) ;
F_64 ( V_60 , V_179 ) ;
V_60 -> V_196 = F_65 ( V_60 , V_2 ) ;
F_66 ( V_60 ) ;
V_2 -> V_175 . V_197 ++ ;
V_2 -> V_175 . V_198 += V_179 ;
}
V_95 -> V_108 |= F_24 ( V_4 , V_109 ) ;
V_172 = ( ++ V_4 -> V_100 ) % V_91 ;
V_95 = & V_4 -> V_104 [ V_172 ] ;
}
for (; V_4 -> V_100 - V_4 -> V_102 > 0 ; V_4 -> V_102 ++ ) {
V_172 = V_4 -> V_102 % V_91 ;
V_95 = & V_4 -> V_104 [ V_172 ] ;
V_95 -> V_111 = F_49 ( V_4 -> V_105 , 16 ) ;
if ( V_4 -> V_90 [ V_172 ] == NULL ) {
V_60 = F_45 ( V_2 , V_4 -> V_105 ) ;
V_4 -> V_90 [ V_172 ] = V_60 ;
if ( V_60 == NULL )
break;
F_46 ( & V_2 -> V_106 , V_60 -> V_64 , V_4 -> V_105 ,
V_107 ) ;
F_22 ( V_60 ) ;
F_67 ( V_60 ) ;
V_95 -> V_78 = F_47 ( F_48 ( V_60 -> V_64 , 4 ) ) ;
}
if ( V_172 >= V_91 - 1 )
V_95 -> V_108 |=
F_24 ( V_4 , V_109 | V_110 | V_113 ) ;
else
V_95 -> V_108 |=
F_24 ( V_4 , V_109 | V_110 ) ;
}
if ( ! ( F_4 ( V_2 , V_170 ) & V_169 ) )
F_3 ( V_2 , V_169 , V_170 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_4 ( V_2 , V_6 ) &
~ ( V_156 | V_155 ) , V_6 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_4 ( V_2 , V_6 ) |
( V_156 | V_155 ) , V_6 ) ;
}
static void F_70 ( struct V_1 * V_2 , int V_199 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_63 V_200 ;
V_63 V_201 ;
V_63 V_202 ;
if ( V_199 & V_203 ) {
V_200 = F_4 ( V_2 , V_158 ) ;
F_3 ( V_2 , V_200 , V_158 ) ;
if ( V_200 & V_204 )
V_2 -> V_175 . V_205 ++ ;
if ( V_200 & V_206 ) {
if ( V_4 -> V_41 -> V_207 || V_4 -> V_208 ) {
if ( V_4 -> V_209 == V_210 )
V_201 = 0 ;
else
V_201 = V_211 ;
} else {
V_201 = ( F_4 ( V_2 , V_212 ) ) ;
if ( V_4 -> V_213 )
V_201 = ~ V_201 ;
}
if ( ! ( V_201 & V_211 ) )
F_68 ( V_2 ) ;
else {
F_3 ( V_2 , F_4 ( V_2 , V_132 ) &
~ V_214 , V_132 ) ;
F_3 ( V_2 , F_4 ( V_2 , V_158 ) ,
V_158 ) ;
F_3 ( V_2 , F_4 ( V_2 , V_132 ) |
V_214 , V_132 ) ;
F_69 ( V_2 ) ;
}
}
}
if ( V_199 & V_215 ) {
if ( V_199 & V_216 )
V_2 -> V_175 . V_217 ++ ;
if ( F_71 ( V_4 ) )
F_52 ( & V_2 -> V_106 , L_6 ) ;
}
if ( V_199 & V_218 ) {
if ( V_199 & V_219 ) {
V_2 -> V_175 . V_193 ++ ;
if ( F_72 ( V_4 ) )
F_52 ( & V_2 -> V_106 , L_7 ) ;
}
}
if ( V_199 & V_220 ) {
V_2 -> V_175 . V_221 ++ ;
if ( F_71 ( V_4 ) )
F_52 ( & V_2 -> V_106 , L_8 ) ;
}
if ( V_199 & V_222 ) {
V_2 -> V_175 . V_221 ++ ;
if ( F_71 ( V_4 ) )
F_52 ( & V_2 -> V_106 , L_9 ) ;
}
if ( V_199 & V_223 ) {
V_2 -> V_175 . V_195 ++ ;
if ( F_4 ( V_2 , V_170 ) ^ V_169 )
F_3 ( V_2 , V_169 , V_170 ) ;
if ( F_72 ( V_4 ) )
F_52 ( & V_2 -> V_106 , L_10 ) ;
}
if ( V_199 & V_224 ) {
V_2 -> V_175 . V_225 ++ ;
if ( F_72 ( V_4 ) )
F_52 ( & V_2 -> V_106 , L_11 ) ;
}
if ( ! V_4 -> V_41 -> V_226 && ( V_199 & V_227 ) ) {
V_2 -> V_175 . V_221 ++ ;
if ( F_71 ( V_4 ) )
F_52 ( & V_2 -> V_106 , L_12 ) ;
}
V_202 = V_215 | V_216 | V_227 | V_220 | V_222 ;
if ( V_4 -> V_41 -> V_226 )
V_202 &= ~ V_227 ;
if ( V_199 & V_202 ) {
V_63 V_228 = F_4 ( V_2 , V_229 ) ;
F_52 ( & V_2 -> V_106 , L_13 ,
V_199 , V_4 -> V_101 ) ;
F_52 ( & V_2 -> V_106 , L_14 ,
V_4 -> V_103 , ( V_63 ) V_2 -> V_230 , V_228 ) ;
F_58 ( V_2 ) ;
if ( V_228 ^ F_32 ( V_4 ) ) {
F_3 ( V_2 , F_32 ( V_4 ) , V_229 ) ;
}
F_73 ( V_2 ) ;
}
}
static T_4 F_74 ( int V_231 , void * V_232 )
{
struct V_1 * V_2 = V_232 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_31 * V_41 = V_4 -> V_41 ;
T_4 V_118 = V_233 ;
V_63 V_199 = 0 ;
F_75 ( & V_4 -> V_234 ) ;
V_199 = F_4 ( V_2 , V_152 ) ;
if ( V_199 & ( V_235 | V_236 | V_237 |
V_238 | V_239 | V_240 | V_241 |
V_41 -> V_53 | V_41 -> V_55 ) ) {
F_3 ( V_2 , V_199 , V_152 ) ;
V_118 = V_242 ;
} else
goto V_243;
if ( V_199 & ( V_235 |
V_236 |
V_237 |
V_238 |
V_239 |
V_240 |
V_241 ) ) {
F_61 ( V_2 ) ;
}
if ( V_199 & V_41 -> V_53 ) {
F_58 ( V_2 ) ;
F_73 ( V_2 ) ;
}
if ( V_199 & V_41 -> V_55 )
F_70 ( V_2 , V_199 ) ;
V_243:
F_76 ( & V_4 -> V_234 ) ;
return V_118 ;
}
static void F_77 ( unsigned long V_64 )
{
struct V_1 * V_2 = (struct V_1 * ) V_64 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_78 ( & V_4 -> V_244 , V_245 + ( 10 * V_246 ) ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_247 * V_248 = V_4 -> V_248 ;
int V_249 = 0 ;
if ( V_248 -> V_209 != V_210 ) {
if ( V_248 -> V_5 != V_4 -> V_5 ) {
V_249 = 1 ;
V_4 -> V_5 = V_248 -> V_5 ;
if ( V_4 -> V_41 -> V_250 )
V_4 -> V_41 -> V_250 ( V_2 ) ;
}
if ( V_248 -> V_8 != V_4 -> V_8 ) {
V_249 = 1 ;
V_4 -> V_8 = V_248 -> V_8 ;
if ( V_4 -> V_41 -> V_157 )
V_4 -> V_41 -> V_157 ( V_2 ) ;
}
if ( V_4 -> V_209 == V_210 ) {
F_3 ( V_2 ,
( F_4 ( V_2 , V_6 ) & ~ V_251 ) , V_6 ) ;
V_249 = 1 ;
V_4 -> V_209 = V_248 -> V_209 ;
}
} else if ( V_4 -> V_209 ) {
V_249 = 1 ;
V_4 -> V_209 = V_210 ;
V_4 -> V_8 = 0 ;
V_4 -> V_5 = - 1 ;
}
if ( V_249 && F_80 ( V_4 ) )
F_81 ( V_248 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
char V_252 [ V_253 + 3 ] ;
struct V_247 * V_248 = NULL ;
snprintf ( V_252 , sizeof( V_252 ) , V_254 ,
V_4 -> V_255 -> V_256 , V_4 -> V_252 ) ;
V_4 -> V_209 = V_210 ;
V_4 -> V_8 = 0 ;
V_4 -> V_5 = - 1 ;
V_248 = F_83 ( V_2 , V_252 , F_79 ,
0 , V_4 -> V_257 ) ;
if ( F_84 ( V_248 ) ) {
F_52 ( & V_2 -> V_106 , L_15 ) ;
return F_85 ( V_248 ) ;
}
F_86 ( & V_2 -> V_106 , L_16 ,
V_248 -> V_78 , V_248 -> V_258 -> V_259 ) ;
V_4 -> V_248 = V_248 ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_118 ;
V_118 = F_82 ( V_2 ) ;
if ( V_118 )
return V_118 ;
F_88 ( V_4 -> V_248 , V_260 , V_261 ) ;
F_89 ( V_4 -> V_248 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_262 * V_263 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_264 ;
int V_118 ;
F_91 ( & V_4 -> V_234 , V_264 ) ;
V_118 = F_92 ( V_4 -> V_248 , V_263 ) ;
F_93 ( & V_4 -> V_234 , V_264 ) ;
return V_118 ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_262 * V_263 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_264 ;
int V_118 ;
F_91 ( & V_4 -> V_234 , V_264 ) ;
F_68 ( V_2 ) ;
V_118 = F_95 ( V_4 -> V_248 , V_263 ) ;
if ( V_118 )
goto V_265;
if ( V_263 -> V_5 == V_266 )
V_4 -> V_5 = 1 ;
else
V_4 -> V_5 = 0 ;
if ( V_4 -> V_41 -> V_250 )
V_4 -> V_41 -> V_250 ( V_2 ) ;
V_265:
F_11 ( 1 ) ;
F_69 ( V_2 ) ;
F_93 ( & V_4 -> V_234 , V_264 ) ;
return V_118 ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_264 ;
int V_118 ;
F_91 ( & V_4 -> V_234 , V_264 ) ;
V_118 = F_97 ( V_4 -> V_248 ) ;
F_93 ( & V_4 -> V_234 , V_264 ) ;
return V_118 ;
}
static V_63 F_98 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_267 ;
}
static void F_99 ( struct V_1 * V_2 , V_63 V_268 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_267 = V_268 ;
}
static int F_100 ( struct V_1 * V_232 , int V_269 )
{
switch ( V_269 ) {
case V_270 :
return V_271 ;
default:
return - V_272 ;
}
}
static void F_101 ( struct V_1 * V_2 ,
struct V_273 * V_175 , T_5 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_11 = 0 ;
V_64 [ V_11 ++ ] = V_4 -> V_100 ;
V_64 [ V_11 ++ ] = V_4 -> V_101 ;
V_64 [ V_11 ++ ] = V_4 -> V_102 ;
V_64 [ V_11 ++ ] = V_4 -> V_103 ;
}
static void F_102 ( struct V_1 * V_2 , V_63 V_274 , T_6 * V_64 )
{
switch ( V_274 ) {
case V_270 :
memcpy ( V_64 , * V_275 ,
sizeof( V_275 ) ) ;
break;
}
}
static int F_103 ( struct V_1 * V_2 )
{
int V_118 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_104 ( & V_4 -> V_276 -> V_106 ) ;
V_118 = F_105 ( V_2 -> V_231 , F_74 ,
#if F_56 ( V_277 ) || \
F_56 ( V_278 ) || \
F_56 ( V_279 )
V_280 ,
#else
0 ,
#endif
V_2 -> V_259 , V_2 ) ;
if ( V_118 ) {
F_52 ( & V_2 -> V_106 , L_17 ) ;
return V_118 ;
}
V_118 = F_50 ( V_2 ) ;
if ( V_118 )
goto V_281;
V_118 = F_55 ( V_2 ) ;
if ( V_118 )
goto V_281;
V_118 = F_87 ( V_2 ) ;
if ( V_118 )
goto V_281;
F_106 ( & V_4 -> V_244 ) ;
V_4 -> V_244 . V_282 = ( V_245 + ( 24 * V_246 ) ) / 10 ;
F_107 ( & V_4 -> V_244 , F_77 , ( unsigned long ) V_2 ) ;
return V_118 ;
V_281:
F_108 ( V_2 -> V_231 , V_2 ) ;
F_109 ( & V_4 -> V_276 -> V_106 ) ;
return V_118 ;
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_94 * V_95 ;
int V_11 ;
F_111 ( V_2 ) ;
if ( F_112 ( V_4 ) )
F_52 ( & V_2 -> V_106 , L_18
L_19 , V_2 -> V_259 , ( int ) F_4 ( V_2 , V_152 ) ) ;
V_2 -> V_175 . V_283 ++ ;
F_113 ( & V_4 -> V_244 ) ;
for ( V_11 = 0 ; V_11 < V_91 ; V_11 ++ ) {
V_95 = & V_4 -> V_104 [ V_11 ] ;
V_95 -> V_108 = 0 ;
V_95 -> V_78 = 0xBADF00D0 ;
if ( V_4 -> V_90 [ V_11 ] )
F_42 ( V_4 -> V_90 [ V_11 ] ) ;
V_4 -> V_90 [ V_11 ] = NULL ;
}
for ( V_11 = 0 ; V_11 < V_93 ; V_11 ++ ) {
if ( V_4 -> V_92 [ V_11 ] )
F_42 ( V_4 -> V_92 [ V_11 ] ) ;
V_4 -> V_92 [ V_11 ] = NULL ;
}
F_55 ( V_2 ) ;
V_4 -> V_244 . V_282 = ( V_245 + ( 24 * V_246 ) ) / 10 ;
F_114 ( & V_4 -> V_244 ) ;
}
static int F_115 ( struct V_59 * V_60 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_96 * V_97 ;
V_63 V_172 ;
unsigned long V_264 ;
F_91 ( & V_4 -> V_234 , V_264 ) ;
if ( ( V_4 -> V_101 - V_4 -> V_103 ) >= ( V_93 - 4 ) ) {
if ( ! F_58 ( V_2 ) ) {
if ( F_116 ( V_4 ) )
F_117 ( & V_2 -> V_106 , L_20 ) ;
F_111 ( V_2 ) ;
F_93 ( & V_4 -> V_234 , V_264 ) ;
return V_284 ;
}
}
F_93 ( & V_4 -> V_234 , V_264 ) ;
V_172 = V_4 -> V_101 % V_93 ;
V_4 -> V_92 [ V_172 ] = V_60 ;
V_97 = & V_4 -> V_114 [ V_172 ] ;
if ( ! V_4 -> V_41 -> V_134 )
F_62 ( F_63 ( F_49 ( V_97 -> V_78 , 4 ) ) ,
V_60 -> V_285 + 2 ) ;
V_97 -> V_78 = F_46 ( & V_2 -> V_106 , V_60 -> V_64 , V_60 -> V_285 ,
V_174 ) ;
if ( V_60 -> V_285 < V_286 )
V_97 -> V_111 = V_286 ;
else
V_97 -> V_111 = V_60 -> V_285 ;
if ( V_172 >= V_93 - 1 )
V_97 -> V_108 |= F_24 ( V_4 , V_173 | V_117 ) ;
else
V_97 -> V_108 |= F_24 ( V_4 , V_173 ) ;
V_4 -> V_101 ++ ;
if ( ! ( F_4 ( V_2 , V_229 ) & F_32 ( V_4 ) ) )
F_3 ( V_2 , F_32 ( V_4 ) , V_229 ) ;
return V_287 ;
}
static int F_118 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_288 ;
F_111 ( V_2 ) ;
F_3 ( V_2 , 0x0000 , V_132 ) ;
F_3 ( V_2 , 0 , V_229 ) ;
F_3 ( V_2 , 0 , V_170 ) ;
if ( V_4 -> V_248 ) {
F_119 ( V_4 -> V_248 ) ;
F_120 ( V_4 -> V_248 ) ;
}
F_108 ( V_2 -> V_231 , V_2 ) ;
F_113 ( & V_4 -> V_244 ) ;
F_41 ( V_2 ) ;
V_288 = sizeof( struct V_94 ) * V_91 ;
F_54 ( NULL , V_288 , V_4 -> V_104 , V_4 -> V_112 ) ;
V_288 = sizeof( struct V_96 ) * V_93 ;
F_54 ( NULL , V_288 , V_4 -> V_114 , V_4 -> V_116 ) ;
F_109 ( & V_4 -> V_276 -> V_106 ) ;
return 0 ;
}
static struct V_289 * F_121 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_104 ( & V_4 -> V_276 -> V_106 ) ;
V_2 -> V_175 . V_290 += F_4 ( V_2 , V_291 ) ;
F_3 ( V_2 , 0 , V_291 ) ;
V_2 -> V_175 . V_292 += F_4 ( V_2 , V_293 ) ;
F_3 ( V_2 , 0 , V_293 ) ;
V_2 -> V_175 . V_205 += F_4 ( V_2 , V_294 ) ;
F_3 ( V_2 , 0 , V_294 ) ;
if ( F_13 ( V_4 ) ) {
V_2 -> V_175 . V_205 += F_4 ( V_2 , V_295 ) ;
F_3 ( V_2 , 0 , V_295 ) ;
V_2 -> V_175 . V_205 += F_4 ( V_2 , V_296 ) ;
F_3 ( V_2 , 0 , V_296 ) ;
} else {
V_2 -> V_175 . V_205 += F_4 ( V_2 , V_297 ) ;
F_3 ( V_2 , 0 , V_297 ) ;
}
F_109 ( & V_4 -> V_276 -> V_106 ) ;
return & V_2 -> V_175 ;
}
static int F_122 ( struct V_1 * V_2 , struct V_298 * V_299 ,
int V_300 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_247 * V_248 = V_4 -> V_248 ;
if ( ! F_123 ( V_2 ) )
return - V_301 ;
if ( ! V_248 )
return - V_302 ;
return F_124 ( V_248 , V_299 , V_300 ) ;
}
static void * F_125 ( struct V_3 * V_4 ,
int V_172 )
{
return F_126 ( V_4 , V_303 ) + ( V_172 / 8 * 4 ) ;
}
static V_63 F_127 ( int V_172 )
{
return 0x0f << ( 28 - ( ( V_172 % 8 ) * 4 ) ) ;
}
static V_63 F_128 ( struct V_3 * V_4 , int V_172 )
{
return ( 0x08 >> ( V_4 -> V_304 << 1 ) ) << ( 28 - ( ( V_172 % 8 ) * 4 ) ) ;
}
static void F_129 ( struct V_1 * V_2 ,
int V_172 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_63 V_305 ;
void * V_74 ;
V_74 = F_125 ( V_4 , V_172 ) ;
V_305 = F_7 ( V_74 ) ;
F_10 ( V_305 | F_128 ( V_4 , V_172 ) , V_74 ) ;
}
static bool F_130 ( struct V_1 * V_2 ,
int V_172 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_63 V_306 , V_307 , V_305 ;
void * V_74 ;
V_74 = F_125 ( V_4 , V_172 ) ;
V_306 = F_127 ( V_172 ) ;
V_307 = F_128 ( V_4 , V_172 ) & ~ V_306 ;
V_305 = F_7 ( V_74 ) ;
F_10 ( V_305 & ~ V_306 , V_74 ) ;
return V_305 & V_307 ;
}
static int F_131 ( struct V_1 * V_2 )
{
int V_308 = V_309 * 100 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
while ( ( F_132 ( V_4 , V_310 ) & V_311 ) ) {
F_133 ( 10 ) ;
V_308 -- ;
if ( V_308 <= 0 ) {
F_52 ( & V_2 -> V_106 , L_21 , V_312 ) ;
return - V_313 ;
}
}
return 0 ;
}
static int F_134 ( struct V_1 * V_2 , void * V_314 ,
const T_6 * V_78 )
{
V_63 V_129 ;
V_129 = V_78 [ 0 ] << 24 | V_78 [ 1 ] << 16 | V_78 [ 2 ] << 8 | V_78 [ 3 ] ;
F_10 ( V_129 , V_314 ) ;
if ( F_131 ( V_2 ) < 0 )
return - V_315 ;
V_129 = V_78 [ 4 ] << 8 | V_78 [ 5 ] ;
F_10 ( V_129 , V_314 + 4 ) ;
if ( F_131 ( V_2 ) < 0 )
return - V_315 ;
return 0 ;
}
static void F_135 ( void * V_314 , T_6 * V_78 )
{
V_63 V_129 ;
V_129 = F_7 ( V_314 ) ;
V_78 [ 0 ] = ( V_129 >> 24 ) & 0xff ;
V_78 [ 1 ] = ( V_129 >> 16 ) & 0xff ;
V_78 [ 2 ] = ( V_129 >> 8 ) & 0xff ;
V_78 [ 3 ] = V_129 & 0xff ;
V_129 = F_7 ( V_314 + 4 ) ;
V_78 [ 4 ] = ( V_129 >> 8 ) & 0xff ;
V_78 [ 5 ] = V_129 & 0xff ;
}
static int F_136 ( struct V_1 * V_2 , const T_6 * V_78 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void * V_74 = F_126 ( V_4 , V_316 ) ;
int V_11 ;
T_6 V_317 [ V_318 ] ;
for ( V_11 = 0 ; V_11 < V_319 ; V_11 ++ , V_74 += 8 ) {
F_135 ( V_74 , V_317 ) ;
if ( memcmp ( V_78 , V_317 , V_318 ) == 0 )
return V_11 ;
}
return - V_320 ;
}
static int F_137 ( struct V_1 * V_2 )
{
T_6 V_321 [ V_318 ] ;
int V_172 ;
memset ( V_321 , 0 , sizeof( V_321 ) ) ;
V_172 = F_136 ( V_2 , V_321 ) ;
return ( V_172 < 0 ) ? - V_124 : V_172 ;
}
static int F_138 ( struct V_1 * V_2 ,
int V_172 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void * V_74 = F_126 ( V_4 , V_316 ) ;
int V_118 ;
T_6 V_321 [ V_318 ] ;
F_19 ( V_4 , F_132 ( V_4 , V_322 ) &
~ ( 1 << ( 31 - V_172 ) ) , V_322 ) ;
memset ( V_321 , 0 , sizeof( V_321 ) ) ;
V_118 = F_134 ( V_2 , V_74 + V_172 * 8 , V_321 ) ;
if ( V_118 < 0 )
return V_118 ;
return 0 ;
}
static int F_139 ( struct V_1 * V_2 , const T_6 * V_78 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void * V_74 = F_126 ( V_4 , V_316 ) ;
int V_11 , V_118 ;
if ( ! V_4 -> V_41 -> V_323 )
return 0 ;
V_11 = F_136 ( V_2 , V_78 ) ;
if ( V_11 < 0 ) {
V_11 = F_137 ( V_2 ) ;
if ( V_11 < 0 )
return - V_124 ;
V_118 = F_134 ( V_2 , V_74 + V_11 * 8 , V_78 ) ;
if ( V_118 < 0 )
return V_118 ;
F_19 ( V_4 , F_132 ( V_4 , V_322 ) |
( 1 << ( 31 - V_11 ) ) , V_322 ) ;
}
F_129 ( V_2 , V_11 ) ;
return 0 ;
}
static int F_140 ( struct V_1 * V_2 , const T_6 * V_78 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_11 , V_118 ;
if ( ! V_4 -> V_41 -> V_323 )
return 0 ;
V_11 = F_136 ( V_2 , V_78 ) ;
if ( V_11 ) {
if ( F_130 ( V_2 , V_11 ) )
goto V_324;
V_118 = F_138 ( V_2 , V_11 ) ;
if ( V_118 < 0 )
return V_118 ;
}
V_324:
return 0 ;
}
static int F_141 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_11 , V_118 ;
if ( F_142 ( ! V_4 -> V_41 -> V_323 ) )
return 0 ;
for ( V_11 = 0 ; V_11 < V_319 ; V_11 ++ ) {
if ( F_130 ( V_2 , V_11 ) )
continue;
V_118 = F_138 ( V_2 , V_11 ) ;
if ( V_118 < 0 )
return V_118 ;
}
return 0 ;
}
static void F_143 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_6 V_78 [ V_318 ] ;
void * V_74 = F_126 ( V_4 , V_316 ) ;
int V_11 ;
if ( F_142 ( ! V_4 -> V_41 -> V_323 ) )
return;
for ( V_11 = 0 ; V_11 < V_319 ; V_11 ++ , V_74 += 8 ) {
F_135 ( V_74 , V_78 ) ;
if ( F_144 ( V_78 ) )
F_140 ( V_2 , V_78 ) ;
}
}
static void F_145 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_63 V_325 ;
int V_326 = 0 ;
unsigned long V_264 ;
F_91 ( & V_4 -> V_234 , V_264 ) ;
V_325 = ( F_4 ( V_2 , V_6 ) & ~ V_327 ) | V_328 ;
if ( ! ( V_2 -> V_264 & V_329 ) ) {
F_143 ( V_2 ) ;
V_326 = 1 ;
}
if ( V_2 -> V_264 & V_330 ) {
F_143 ( V_2 ) ;
V_325 &= ~ V_328 ;
V_326 = 1 ;
}
if ( V_2 -> V_264 & V_331 ) {
F_141 ( V_2 ) ;
V_325 = ( V_325 & ~ V_328 ) | V_327 ;
} else if ( V_4 -> V_41 -> V_323 ) {
struct V_332 * V_333 ;
F_146 (ha, ndev) {
if ( V_326 && F_144 ( V_333 -> V_78 ) )
continue;
if ( F_139 ( V_2 , V_333 -> V_78 ) < 0 ) {
if ( ! V_326 ) {
F_143 ( V_2 ) ;
V_325 &= ~ V_328 ;
V_326 = 1 ;
}
}
}
} else {
V_325 = ( V_325 & ~ V_327 ) | V_328 ;
}
F_3 ( V_2 , V_325 , V_6 ) ;
F_93 ( & V_4 -> V_234 , V_264 ) ;
}
static int F_147 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_304 )
return V_334 ;
else
return V_335 ;
}
static int F_148 ( struct V_1 * V_2 , T_3 V_336 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_337 = F_147 ( V_4 ) ;
if ( F_142 ( ! V_4 -> V_41 -> V_323 ) )
return - V_338 ;
if ( ! V_336 )
return 0 ;
V_4 -> V_339 ++ ;
if ( V_4 -> V_339 > 1 ) {
F_19 ( V_4 , 0 , V_337 ) ;
return 0 ;
}
F_19 ( V_4 , V_340 | ( V_336 & V_341 ) ,
V_337 ) ;
return 0 ;
}
static int F_149 ( struct V_1 * V_2 , T_3 V_336 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_337 = F_147 ( V_4 ) ;
if ( F_142 ( ! V_4 -> V_41 -> V_323 ) )
return - V_338 ;
if ( ! V_336 )
return 0 ;
V_4 -> V_339 -- ;
F_19 ( V_4 , 0 , V_337 ) ;
return 0 ;
}
static void F_150 ( struct V_3 * V_4 )
{
F_19 ( V_4 , 0 , V_342 ) ;
F_19 ( V_4 , 0 , V_343 ) ;
F_19 ( V_4 , 0 , V_344 ) ;
F_19 ( V_4 , 0xc , V_345 ) ;
F_19 ( V_4 , 0xc , V_346 ) ;
F_19 ( V_4 , 0 , V_347 ) ;
F_19 ( V_4 , 0 , V_348 ) ;
F_19 ( V_4 , 0 , V_349 ) ;
F_19 ( V_4 , 0 , V_350 ) ;
F_19 ( V_4 , V_351 | V_352 , V_353 ) ;
if ( F_13 ( V_4 ) ) {
F_19 ( V_4 , 0 , V_354 ) ;
F_19 ( V_4 , 0 , V_355 ) ;
} else {
F_19 ( V_4 , 0 , V_356 ) ;
F_19 ( V_4 , 0 , V_357 ) ;
}
F_19 ( V_4 , 0 , V_358 ) ;
F_19 ( V_4 , 0 , V_359 ) ;
F_19 ( V_4 , 0 , V_322 ) ;
F_19 ( V_4 , 0 , V_303 ) ;
F_19 ( V_4 , 0 , V_360 ) ;
F_19 ( V_4 , 0 , V_361 ) ;
F_19 ( V_4 , 0 , V_362 ) ;
}
static int F_151 ( struct V_1 * V_2 )
{
struct V_255 * V_363 = F_152 ( & V_2 -> V_106 ) ;
F_153 ( V_363 ) ;
F_154 ( & V_2 -> V_106 , NULL ) ;
F_43 ( V_363 -> V_231 ) ;
F_155 ( V_363 ) ;
return 0 ;
}
static int F_156 ( struct V_1 * V_2 , int V_256 ,
struct V_364 * V_365 )
{
int V_118 , V_11 ;
struct V_83 * V_84 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_84 = F_157 ( sizeof( struct V_83 ) , V_123 ) ;
if ( ! V_84 ) {
V_118 = - V_124 ;
goto V_366;
}
V_84 -> V_78 = V_4 -> V_78 + V_4 -> V_74 [ V_367 ] ;
V_84 -> V_85 = V_365 -> V_368 ;
V_84 -> V_88 = 0x08 ;
V_84 -> V_87 = 0x04 ;
V_84 -> V_86 = 0x02 ;
V_84 -> V_89 = 0x01 ;
V_84 -> V_81 . V_369 = & V_370 ;
V_4 -> V_255 = F_158 ( & V_84 -> V_81 ) ;
if ( ! V_4 -> V_255 ) {
V_118 = - V_124 ;
goto V_371;
}
V_4 -> V_255 -> V_259 = L_22 ;
V_4 -> V_255 -> V_372 = & V_2 -> V_106 ;
snprintf ( V_4 -> V_255 -> V_256 , V_253 , L_23 ,
V_4 -> V_276 -> V_259 , V_256 ) ;
V_4 -> V_255 -> V_231 = F_51 ( sizeof( int ) * V_373 , V_123 ) ;
if ( ! V_4 -> V_255 -> V_231 ) {
V_118 = - V_124 ;
goto V_374;
}
for ( V_11 = 0 ; V_11 < V_373 ; V_11 ++ )
V_4 -> V_255 -> V_231 [ V_11 ] = V_375 ;
V_118 = F_159 ( V_4 -> V_255 ) ;
if ( V_118 )
goto V_281;
F_154 ( & V_2 -> V_106 , V_4 -> V_255 ) ;
return 0 ;
V_281:
F_43 ( V_4 -> V_255 -> V_231 ) ;
V_374:
F_155 ( V_4 -> V_255 ) ;
V_371:
F_43 ( V_84 ) ;
V_366:
return V_118 ;
}
static const T_3 * F_160 ( int V_376 )
{
const T_3 * V_74 = NULL ;
switch ( V_376 ) {
case V_377 :
V_74 = V_75 ;
break;
case V_378 :
V_74 = V_379 ;
break;
case V_380 :
V_74 = V_381 ;
break;
default:
F_14 ( V_20 L_24 , V_376 ) ;
break;
}
return V_74 ;
}
static int F_161 ( struct V_382 * V_276 )
{
int V_118 , V_383 = 0 ;
struct V_384 * V_385 ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_364 * V_365 ;
V_385 = F_162 ( V_276 , V_386 , 0 ) ;
if ( F_142 ( V_385 == NULL ) ) {
F_52 ( & V_276 -> V_106 , L_25 ) ;
V_118 = - V_301 ;
goto V_366;
}
V_2 = F_163 ( sizeof( struct V_3 ) ) ;
if ( ! V_2 ) {
V_118 = - V_124 ;
goto V_366;
}
V_2 -> V_387 = V_385 -> V_388 ;
V_383 = V_276 -> V_256 ;
if ( V_383 < 0 )
V_383 = 0 ;
V_2 -> V_389 = - 1 ;
V_118 = F_164 ( V_276 , 0 ) ;
if ( V_118 < 0 ) {
V_118 = - V_302 ;
goto V_390;
}
V_2 -> V_231 = V_118 ;
F_165 ( V_2 , & V_276 -> V_106 ) ;
F_166 ( V_2 ) ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_78 = F_167 ( V_385 -> V_388 , F_168 ( V_385 ) ) ;
if ( V_4 -> V_78 == NULL ) {
V_118 = - V_124 ;
F_52 ( & V_276 -> V_106 , L_26 ) ;
goto V_390;
}
F_169 ( & V_4 -> V_234 ) ;
V_4 -> V_276 = V_276 ;
F_170 ( & V_276 -> V_106 ) ;
F_171 ( & V_276 -> V_106 ) ;
V_365 = (struct V_364 * ) ( V_276 -> V_106 . V_391 ) ;
V_4 -> V_252 = V_365 -> V_392 ;
V_4 -> V_257 = V_365 -> V_257 ;
V_4 -> V_67 = V_365 -> V_67 ;
V_4 -> V_208 = V_365 -> V_208 ;
V_4 -> V_213 = V_365 -> V_213 ;
V_4 -> V_74 = F_160 ( V_365 -> V_376 ) ;
#if F_56 ( V_393 )
V_4 -> V_41 = F_17 ( V_4 ) ;
#else
V_4 -> V_41 = & V_33 ;
#endif
F_21 ( V_4 -> V_41 ) ;
V_2 -> V_394 = & V_395 ;
F_172 ( V_2 , & V_396 ) ;
V_2 -> V_397 = V_398 ;
V_4 -> V_267 = V_399 ;
V_4 -> V_400 = V_401 >> ( V_383 << 1 ) ;
V_4 -> V_402 = V_403 >> ( V_383 << 1 ) ;
F_31 ( V_2 , V_365 -> V_404 ) ;
if ( V_4 -> V_41 -> V_323 ) {
struct V_384 * V_405 ;
V_405 = F_162 ( V_276 , V_386 , 1 ) ;
if ( ! V_405 ) {
F_52 ( & V_276 -> V_106 , L_27 ) ;
goto V_390;
}
V_4 -> V_406 = F_167 ( V_405 -> V_388 ,
F_168 ( V_405 ) ) ;
V_4 -> V_304 = V_383 % 2 ;
V_2 -> V_407 = V_408 ;
}
if ( ! V_383 || V_365 -> V_409 ) {
if ( V_4 -> V_41 -> V_410 )
V_4 -> V_41 -> V_410 ( V_2 ) ;
if ( V_4 -> V_41 -> V_323 ) {
F_150 ( V_4 ) ;
}
}
V_118 = F_173 ( V_2 ) ;
if ( V_118 )
goto V_390;
V_118 = F_156 ( V_2 , V_276 -> V_256 , V_365 ) ;
if ( V_118 )
goto V_411;
F_174 ( L_28 ,
( V_63 ) V_2 -> V_387 , V_2 -> V_70 , V_2 -> V_231 ) ;
F_175 ( V_276 , V_2 ) ;
return V_118 ;
V_411:
F_176 ( V_2 ) ;
V_390:
if ( V_4 && V_4 -> V_78 )
F_177 ( V_4 -> V_78 ) ;
if ( V_4 && V_4 -> V_406 )
F_177 ( V_4 -> V_406 ) ;
if ( V_2 )
F_178 ( V_2 ) ;
V_366:
return V_118 ;
}
static int F_179 ( struct V_382 * V_276 )
{
struct V_1 * V_2 = F_180 ( V_276 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_41 -> V_323 )
F_177 ( V_4 -> V_406 ) ;
F_151 ( V_2 ) ;
F_176 ( V_2 ) ;
F_181 ( & V_276 -> V_106 ) ;
F_177 ( V_4 -> V_78 ) ;
F_178 ( V_2 ) ;
F_175 ( V_276 , NULL ) ;
return 0 ;
}
static int F_182 ( struct V_412 * V_106 )
{
return 0 ;
}
