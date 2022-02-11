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
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_41 ;
F_19 ( V_4 , V_14 , V_34 ) ;
F_11 ( 1 ) ;
switch ( V_4 -> V_42 ) {
case V_43 :
V_41 = 2 ;
break;
case V_44 :
V_41 = 1 ;
break;
case V_45 :
default:
V_41 = 0 ;
break;
}
F_3 ( V_2 , V_41 , V_46 ) ;
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
static void F_21 ( struct V_31 * V_47 )
{
if ( ! V_47 -> V_48 )
V_47 -> V_48 = V_49 ;
if ( ! V_47 -> V_50 )
V_47 -> V_50 = V_51 ;
if ( ! V_47 -> V_52 )
V_47 -> V_52 = V_53 | \
V_54 ;
if ( ! V_47 -> V_55 )
V_47 -> V_55 = V_56 ;
if ( ! V_47 -> V_57 )
V_47 -> V_57 = V_58 ;
if ( ! V_47 -> V_59 )
V_47 -> V_59 = V_60 ;
if ( ! V_47 -> V_61 )
V_47 -> V_61 = V_62 ;
if ( ! V_47 -> V_63 )
V_47 -> V_63 = V_64 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_4 ( V_2 , V_18 ) | V_29 , V_18 ) ;
F_11 ( 3 ) ;
F_3 ( V_2 , F_4 ( V_2 , V_18 ) & ~ V_29 , V_18 ) ;
}
static void F_22 ( struct V_65 * V_66 )
{
int V_67 ;
V_67 = V_68 - ( ( V_69 ) V_66 -> V_70 & ( V_68 - 1 ) ) ;
if ( V_67 )
F_23 ( V_66 , V_67 ) ;
}
static void F_22 ( struct V_65 * V_66 )
{
F_23 ( V_66 , V_71 ) ;
}
static inline T_1 F_24 ( struct V_3 * V_4 , V_69 V_72 )
{
switch ( V_4 -> V_73 ) {
case V_74 :
return F_25 ( V_72 ) ;
case V_75 :
return F_26 ( V_72 ) ;
}
return V_72 ;
}
static inline T_1 F_27 ( struct V_3 * V_4 , V_69 V_72 )
{
switch ( V_4 -> V_73 ) {
case V_74 :
return F_28 ( V_72 ) ;
case V_75 :
return F_29 ( V_72 ) ;
}
return V_72 ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_3 ( V_2 ,
( V_2 -> V_76 [ 0 ] << 24 ) | ( V_2 -> V_76 [ 1 ] << 16 ) |
( V_2 -> V_76 [ 2 ] << 8 ) | ( V_2 -> V_76 [ 3 ] ) , V_77 ) ;
F_3 ( V_2 ,
( V_2 -> V_76 [ 4 ] << 8 ) | ( V_2 -> V_76 [ 5 ] ) , V_78 ) ;
}
static void F_31 ( struct V_1 * V_2 , unsigned char * V_79 )
{
if ( V_79 [ 0 ] || V_79 [ 1 ] || V_79 [ 2 ] || V_79 [ 3 ] || V_79 [ 4 ] || V_79 [ 5 ] ) {
memcpy ( V_2 -> V_76 , V_79 , 6 ) ;
} else {
V_2 -> V_76 [ 0 ] = ( F_4 ( V_2 , V_77 ) >> 24 ) ;
V_2 -> V_76 [ 1 ] = ( F_4 ( V_2 , V_77 ) >> 16 ) & 0xFF ;
V_2 -> V_76 [ 2 ] = ( F_4 ( V_2 , V_77 ) >> 8 ) & 0xFF ;
V_2 -> V_76 [ 3 ] = ( F_4 ( V_2 , V_77 ) & 0xFF ) ;
V_2 -> V_76 [ 4 ] = ( F_4 ( V_2 , V_78 ) >> 8 ) & 0xFF ;
V_2 -> V_76 [ 5 ] = ( F_4 ( V_2 , V_78 ) & 0xFF ) ;
}
}
static int F_13 ( struct V_3 * V_4 )
{
if ( V_4 -> V_80 == V_81 )
return 1 ;
else
return 0 ;
}
static unsigned long F_32 ( struct V_3 * V_4 )
{
if ( F_13 ( V_4 ) )
return V_82 ;
else
return V_83 ;
}
static void F_33 ( void * V_84 , V_69 V_85 )
{
F_10 ( F_7 ( V_84 ) | V_85 , V_84 ) ;
}
static void F_34 ( void * V_84 , V_69 V_85 )
{
F_10 ( ( F_7 ( V_84 ) & ~ V_85 ) , V_84 ) ;
}
static int F_35 ( void * V_84 , V_69 V_85 )
{
return ( F_7 ( V_84 ) & V_85 ) != 0 ;
}
static void F_36 ( struct V_86 * V_87 , int V_88 )
{
struct V_89 * V_90 = F_37 ( V_87 , struct V_89 , V_87 ) ;
if ( V_90 -> V_91 )
V_90 -> V_91 ( V_90 -> V_84 ) ;
if ( V_88 )
F_33 ( V_90 -> V_84 , V_90 -> V_92 ) ;
else
F_34 ( V_90 -> V_84 , V_90 -> V_92 ) ;
}
static void F_38 ( struct V_86 * V_87 , int V_88 )
{
struct V_89 * V_90 = F_37 ( V_87 , struct V_89 , V_87 ) ;
if ( V_90 -> V_91 )
V_90 -> V_91 ( V_90 -> V_84 ) ;
if ( V_88 )
F_33 ( V_90 -> V_84 , V_90 -> V_93 ) ;
else
F_34 ( V_90 -> V_84 , V_90 -> V_93 ) ;
}
static int F_39 ( struct V_86 * V_87 )
{
struct V_89 * V_90 = F_37 ( V_87 , struct V_89 , V_87 ) ;
if ( V_90 -> V_91 )
V_90 -> V_91 ( V_90 -> V_84 ) ;
return F_35 ( V_90 -> V_84 , V_90 -> V_94 ) ;
}
static void F_40 ( struct V_86 * V_87 , int V_88 )
{
struct V_89 * V_90 = F_37 ( V_87 , struct V_89 , V_87 ) ;
if ( V_90 -> V_91 )
V_90 -> V_91 ( V_90 -> V_84 ) ;
if ( V_88 )
F_33 ( V_90 -> V_84 , V_90 -> V_95 ) ;
else
F_34 ( V_90 -> V_84 , V_90 -> V_95 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_11 ;
if ( V_4 -> V_96 ) {
for ( V_11 = 0 ; V_11 < V_97 ; V_11 ++ ) {
if ( V_4 -> V_96 [ V_11 ] )
F_42 ( V_4 -> V_96 [ V_11 ] ) ;
}
}
F_43 ( V_4 -> V_96 ) ;
if ( V_4 -> V_98 ) {
for ( V_11 = 0 ; V_11 < V_99 ; V_11 ++ ) {
if ( V_4 -> V_98 [ V_11 ] )
F_42 ( V_4 -> V_98 [ V_11 ] ) ;
}
}
F_43 ( V_4 -> V_98 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_11 ;
struct V_65 * V_66 ;
struct V_100 * V_101 = NULL ;
struct V_102 * V_103 = NULL ;
int V_104 = sizeof( * V_101 ) * V_97 ;
int V_105 = sizeof( * V_103 ) * V_99 ;
V_4 -> V_106 = V_4 -> V_107 = 0 ;
V_4 -> V_108 = V_4 -> V_109 = 0 ;
memset ( V_4 -> V_110 , 0 , V_104 ) ;
for ( V_11 = 0 ; V_11 < V_97 ; V_11 ++ ) {
V_4 -> V_96 [ V_11 ] = NULL ;
V_66 = F_45 ( V_2 , V_4 -> V_111 ) ;
V_4 -> V_96 [ V_11 ] = V_66 ;
if ( V_66 == NULL )
break;
F_46 ( & V_2 -> V_112 , V_66 -> V_70 , V_4 -> V_111 ,
V_113 ) ;
F_22 ( V_66 ) ;
V_101 = & V_4 -> V_110 [ V_11 ] ;
V_101 -> V_84 = F_47 ( F_48 ( V_66 -> V_70 , 4 ) ) ;
V_101 -> V_114 = F_24 ( V_4 , V_115 | V_116 ) ;
V_101 -> V_117 = F_49 ( V_4 -> V_111 , 16 ) ;
if ( V_11 == 0 ) {
F_3 ( V_2 , V_4 -> V_118 , V_25 ) ;
if ( F_13 ( V_4 ) )
F_3 ( V_2 , V_4 -> V_118 , V_26 ) ;
}
}
V_4 -> V_108 = ( V_69 ) ( V_11 - V_97 ) ;
V_101 -> V_114 |= F_24 ( V_4 , V_119 ) ;
memset ( V_4 -> V_120 , 0 , V_105 ) ;
for ( V_11 = 0 ; V_11 < V_99 ; V_11 ++ ) {
V_4 -> V_98 [ V_11 ] = NULL ;
V_103 = & V_4 -> V_120 [ V_11 ] ;
V_103 -> V_114 = F_24 ( V_4 , V_121 ) ;
V_103 -> V_117 = 0 ;
if ( V_11 == 0 ) {
F_3 ( V_2 , V_4 -> V_122 , V_21 ) ;
if ( F_13 ( V_4 ) )
F_3 ( V_2 , V_4 -> V_122 , V_22 ) ;
}
}
V_103 -> V_114 |= F_24 ( V_4 , V_123 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_104 , V_105 , V_124 = 0 ;
V_4 -> V_111 = ( V_2 -> V_125 <= 1492 ? V_126 :
( ( ( V_2 -> V_125 + 26 + 7 ) & ~ 7 ) + 2 + 16 ) ) ;
if ( V_4 -> V_47 -> V_127 )
V_4 -> V_111 += V_128 ;
V_4 -> V_96 = F_51 ( sizeof( * V_4 -> V_96 ) * V_97 ,
V_129 ) ;
if ( ! V_4 -> V_96 ) {
F_52 ( & V_2 -> V_112 , L_2 ) ;
V_124 = - V_130 ;
return V_124 ;
}
V_4 -> V_98 = F_51 ( sizeof( * V_4 -> V_98 ) * V_99 ,
V_129 ) ;
if ( ! V_4 -> V_98 ) {
F_52 ( & V_2 -> V_112 , L_3 ) ;
V_124 = - V_130 ;
goto V_131;
}
V_104 = sizeof( struct V_100 ) * V_97 ;
V_4 -> V_110 = F_53 ( NULL , V_104 , & V_4 -> V_118 ,
V_129 ) ;
if ( ! V_4 -> V_110 ) {
F_52 ( & V_2 -> V_112 , L_4 ,
V_104 ) ;
V_124 = - V_130 ;
goto V_132;
}
V_4 -> V_108 = 0 ;
V_105 = sizeof( struct V_102 ) * V_99 ;
V_4 -> V_120 = F_53 ( NULL , V_105 , & V_4 -> V_122 ,
V_129 ) ;
if ( ! V_4 -> V_120 ) {
F_52 ( & V_2 -> V_112 , L_5 ,
V_105 ) ;
V_124 = - V_130 ;
goto V_132;
}
return V_124 ;
V_132:
F_54 ( NULL , V_104 , V_4 -> V_110 , V_4 -> V_118 ) ;
V_131:
F_41 ( V_2 ) ;
return V_124 ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_124 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_133 , V_134 ;
V_69 V_135 ;
F_12 ( V_2 ) ;
F_44 ( V_2 ) ;
if ( V_4 -> V_47 -> V_127 )
F_3 ( V_2 , V_4 -> V_47 -> V_136 , V_137 ) ;
F_3 ( V_2 , 0 , V_138 ) ;
#if F_56 ( V_139 )
if ( V_4 -> V_47 -> V_140 )
F_3 ( V_2 , V_141 , V_18 ) ;
else
#endif
F_3 ( V_2 , 0 , V_18 ) ;
F_3 ( V_2 , V_4 -> V_47 -> V_55 , V_142 ) ;
F_3 ( V_2 , 0 , V_143 ) ;
F_3 ( V_2 , V_4 -> V_47 -> V_57 , V_144 ) ;
V_133 = V_4 -> V_133 = V_145 | V_146 ;
V_134 = V_4 -> V_134 = V_147 ;
F_3 ( V_2 , V_133 | V_134 , V_148 ) ;
if ( V_4 -> V_47 -> V_149 )
F_3 ( V_2 , 0x800 , V_150 ) ;
F_3 ( V_2 , V_4 -> V_47 -> V_52 , V_151 ) ;
if ( ! V_4 -> V_47 -> V_152 )
F_3 ( V_2 , 0 , V_153 ) ;
F_3 ( V_2 , V_2 -> V_125 + V_154 + V_155 + V_156 ,
V_157 ) ;
F_3 ( V_2 , F_4 ( V_2 , V_158 ) , V_158 ) ;
F_3 ( V_2 , V_4 -> V_47 -> V_159 , V_138 ) ;
V_135 = ( F_4 ( V_2 , V_6 ) & V_7 ) |
V_160 | ( V_4 -> V_5 ? V_7 : 0 ) | V_161 | V_162 ;
F_3 ( V_2 , V_135 , V_6 ) ;
if ( V_4 -> V_47 -> V_163 )
V_4 -> V_47 -> V_163 ( V_2 ) ;
F_3 ( V_2 , V_4 -> V_47 -> V_48 , V_164 ) ;
F_3 ( V_2 , V_4 -> V_47 -> V_50 , V_165 ) ;
F_30 ( V_2 ) ;
if ( V_4 -> V_47 -> V_166 )
F_3 ( V_2 , V_167 , V_168 ) ;
if ( V_4 -> V_47 -> V_169 )
F_3 ( V_2 , V_170 , V_171 ) ;
if ( V_4 -> V_47 -> V_172 )
F_3 ( V_2 , V_173 , V_174 ) ;
F_3 ( V_2 , V_175 , V_176 ) ;
F_57 ( V_2 ) ;
return V_124 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_102 * V_103 ;
int V_177 = 0 ;
int V_178 = 0 ;
for (; V_4 -> V_107 - V_4 -> V_109 > 0 ; V_4 -> V_109 ++ ) {
V_178 = V_4 -> V_109 % V_99 ;
V_103 = & V_4 -> V_120 [ V_178 ] ;
if ( V_103 -> V_114 & F_24 ( V_4 , V_179 ) )
break;
if ( V_4 -> V_98 [ V_178 ] ) {
F_59 ( & V_2 -> V_112 , V_103 -> V_84 ,
V_103 -> V_117 , V_180 ) ;
F_60 ( V_4 -> V_98 [ V_178 ] ) ;
V_4 -> V_98 [ V_178 ] = NULL ;
V_177 ++ ;
}
V_103 -> V_114 = F_24 ( V_4 , V_121 ) ;
if ( V_178 >= V_99 - 1 )
V_103 -> V_114 |= F_24 ( V_4 , V_123 ) ;
V_2 -> V_181 . V_182 ++ ;
V_2 -> V_181 . V_183 += V_103 -> V_117 ;
}
return V_177 ;
}
static int F_61 ( struct V_1 * V_2 , V_69 V_184 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_100 * V_101 ;
int V_178 = V_4 -> V_106 % V_97 ;
int V_185 = ( V_4 -> V_108 + V_97 ) - V_4 -> V_106 ;
struct V_65 * V_66 ;
T_3 V_186 = 0 ;
V_69 V_187 ;
V_101 = & V_4 -> V_110 [ V_178 ] ;
while ( ! ( V_101 -> V_114 & F_24 ( V_4 , V_115 ) ) ) {
V_187 = F_27 ( V_4 , V_101 -> V_114 ) ;
V_186 = V_101 -> V_188 ;
#if F_56 ( V_189 )
V_187 >>= 16 ;
#endif
if ( -- V_185 < 0 )
break;
if ( ! ( V_187 & V_190 ) )
V_2 -> V_181 . V_191 ++ ;
if ( V_187 & ( V_192 | V_193 | V_194 | V_195 |
V_196 | V_197 | V_198 ) ) {
V_2 -> V_181 . V_199 ++ ;
if ( V_187 & V_192 )
V_2 -> V_181 . V_200 ++ ;
if ( V_187 & V_193 )
V_2 -> V_181 . V_201 ++ ;
if ( V_187 & V_194 )
V_2 -> V_181 . V_191 ++ ;
if ( V_187 & V_195 )
V_2 -> V_181 . V_191 ++ ;
if ( V_187 & V_197 )
V_2 -> V_181 . V_202 ++ ;
if ( V_187 & V_198 )
V_2 -> V_181 . V_203 ++ ;
} else {
if ( ! V_4 -> V_47 -> V_140 )
F_62 (
F_63 ( F_49 ( V_101 -> V_84 , 4 ) ) ,
V_186 + 2 ) ;
V_66 = V_4 -> V_96 [ V_178 ] ;
V_4 -> V_96 [ V_178 ] = NULL ;
if ( V_4 -> V_47 -> V_127 )
F_23 ( V_66 , V_128 ) ;
F_64 ( V_66 , V_186 ) ;
V_66 -> V_204 = F_65 ( V_66 , V_2 ) ;
F_66 ( V_66 ) ;
V_2 -> V_181 . V_205 ++ ;
V_2 -> V_181 . V_206 += V_186 ;
}
V_101 -> V_114 |= F_24 ( V_4 , V_115 ) ;
V_178 = ( ++ V_4 -> V_106 ) % V_97 ;
V_101 = & V_4 -> V_110 [ V_178 ] ;
}
for (; V_4 -> V_106 - V_4 -> V_108 > 0 ; V_4 -> V_108 ++ ) {
V_178 = V_4 -> V_108 % V_97 ;
V_101 = & V_4 -> V_110 [ V_178 ] ;
V_101 -> V_117 = F_49 ( V_4 -> V_111 , 16 ) ;
if ( V_4 -> V_96 [ V_178 ] == NULL ) {
V_66 = F_45 ( V_2 , V_4 -> V_111 ) ;
V_4 -> V_96 [ V_178 ] = V_66 ;
if ( V_66 == NULL )
break;
F_46 ( & V_2 -> V_112 , V_66 -> V_70 , V_4 -> V_111 ,
V_113 ) ;
F_22 ( V_66 ) ;
F_67 ( V_66 ) ;
V_101 -> V_84 = F_47 ( F_48 ( V_66 -> V_70 , 4 ) ) ;
}
if ( V_178 >= V_97 - 1 )
V_101 -> V_114 |=
F_24 ( V_4 , V_115 | V_116 | V_119 ) ;
else
V_101 -> V_114 |=
F_24 ( V_4 , V_115 | V_116 ) ;
}
if ( ! ( F_4 ( V_2 , V_176 ) & V_175 ) ) {
if ( V_184 & V_207 )
V_4 -> V_106 = V_4 -> V_108 =
( F_4 ( V_2 , V_26 ) -
F_4 ( V_2 , V_25 ) ) >> 4 ;
F_3 ( V_2 , V_175 , V_176 ) ;
}
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_4 ( V_2 , V_6 ) &
~ ( V_162 | V_161 ) , V_6 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_4 ( V_2 , V_6 ) |
( V_162 | V_161 ) , V_6 ) ;
}
static void F_70 ( struct V_1 * V_2 , int V_184 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_69 V_208 ;
V_69 V_209 ;
V_69 V_210 ;
if ( V_184 & V_211 ) {
V_208 = F_4 ( V_2 , V_164 ) ;
F_3 ( V_2 , V_208 , V_164 ) ;
if ( V_208 & V_212 )
V_2 -> V_181 . V_213 ++ ;
if ( V_208 & V_214 ) {
if ( V_4 -> V_47 -> V_215 || V_4 -> V_216 ) {
if ( V_4 -> V_217 == V_218 )
V_209 = 0 ;
else
V_209 = V_219 ;
} else {
V_209 = ( F_4 ( V_2 , V_220 ) ) ;
if ( V_4 -> V_221 )
V_209 = ~ V_209 ;
}
if ( ! ( V_209 & V_219 ) )
F_68 ( V_2 ) ;
else {
F_3 ( V_2 , F_4 ( V_2 , V_138 ) &
~ V_222 , V_138 ) ;
F_3 ( V_2 , F_4 ( V_2 , V_164 ) ,
V_164 ) ;
F_3 ( V_2 , F_4 ( V_2 , V_138 ) |
V_222 , V_138 ) ;
F_69 ( V_2 ) ;
}
}
}
if ( V_184 & V_223 ) {
if ( V_184 & V_224 )
V_2 -> V_181 . V_225 ++ ;
if ( F_71 ( V_4 ) )
F_52 ( & V_2 -> V_112 , L_6 ) ;
}
if ( V_184 & V_226 ) {
if ( V_184 & V_227 ) {
V_2 -> V_181 . V_201 ++ ;
if ( F_72 ( V_4 ) )
F_52 ( & V_2 -> V_112 , L_7 ) ;
}
}
if ( V_184 & V_228 ) {
V_2 -> V_181 . V_229 ++ ;
if ( F_71 ( V_4 ) )
F_52 ( & V_2 -> V_112 , L_8 ) ;
}
if ( V_184 & V_230 ) {
V_2 -> V_181 . V_229 ++ ;
if ( F_71 ( V_4 ) )
F_52 ( & V_2 -> V_112 , L_9 ) ;
}
if ( V_184 & V_207 ) {
V_2 -> V_181 . V_203 ++ ;
if ( F_72 ( V_4 ) )
F_52 ( & V_2 -> V_112 , L_10 ) ;
}
if ( V_184 & V_231 ) {
V_2 -> V_181 . V_232 ++ ;
if ( F_72 ( V_4 ) )
F_52 ( & V_2 -> V_112 , L_11 ) ;
}
if ( ! V_4 -> V_47 -> V_233 && ( V_184 & V_234 ) ) {
V_2 -> V_181 . V_229 ++ ;
if ( F_71 ( V_4 ) )
F_52 ( & V_2 -> V_112 , L_12 ) ;
}
V_210 = V_223 | V_224 | V_234 | V_228 | V_230 ;
if ( V_4 -> V_47 -> V_233 )
V_210 &= ~ V_234 ;
if ( V_184 & V_210 ) {
V_69 V_235 = F_4 ( V_2 , V_236 ) ;
F_52 ( & V_2 -> V_112 , L_13 ,
V_184 , V_4 -> V_107 ) ;
F_52 ( & V_2 -> V_112 , L_14 ,
V_4 -> V_109 , ( V_69 ) V_2 -> V_237 , V_235 ) ;
F_58 ( V_2 ) ;
if ( V_235 ^ F_32 ( V_4 ) ) {
F_3 ( V_2 , F_32 ( V_4 ) , V_236 ) ;
}
F_73 ( V_2 ) ;
}
}
static T_4 F_74 ( int V_238 , void * V_239 )
{
struct V_1 * V_2 = V_239 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_31 * V_47 = V_4 -> V_47 ;
T_4 V_124 = V_240 ;
V_69 V_184 = 0 ;
F_75 ( & V_4 -> V_241 ) ;
V_184 = F_4 ( V_2 , V_158 ) ;
if ( V_184 & ( V_242 | V_243 | V_244 |
V_245 | V_246 | V_247 | V_248 |
V_47 -> V_59 | V_47 -> V_61 ) ) {
F_3 ( V_2 , V_184 , V_158 ) ;
V_124 = V_249 ;
} else
goto V_250;
if ( V_184 & ( V_242 |
V_243 |
V_244 |
V_245 |
V_246 |
V_247 |
V_248 ) ) {
F_61 ( V_2 , V_184 ) ;
}
if ( V_184 & V_47 -> V_59 ) {
F_58 ( V_2 ) ;
F_73 ( V_2 ) ;
}
if ( V_184 & V_47 -> V_61 )
F_70 ( V_2 , V_184 ) ;
V_250:
F_76 ( & V_4 -> V_241 ) ;
return V_124 ;
}
static void F_77 ( unsigned long V_70 )
{
struct V_1 * V_2 = (struct V_1 * ) V_70 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_78 ( & V_4 -> V_251 , V_252 + ( 10 * V_253 ) ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_254 * V_255 = V_4 -> V_255 ;
int V_256 = 0 ;
if ( V_255 -> V_217 != V_218 ) {
if ( V_255 -> V_5 != V_4 -> V_5 ) {
V_256 = 1 ;
V_4 -> V_5 = V_255 -> V_5 ;
if ( V_4 -> V_47 -> V_257 )
V_4 -> V_47 -> V_257 ( V_2 ) ;
}
if ( V_255 -> V_8 != V_4 -> V_8 ) {
V_256 = 1 ;
V_4 -> V_8 = V_255 -> V_8 ;
if ( V_4 -> V_47 -> V_163 )
V_4 -> V_47 -> V_163 ( V_2 ) ;
}
if ( V_4 -> V_217 == V_218 ) {
F_3 ( V_2 ,
( F_4 ( V_2 , V_6 ) & ~ V_258 ) , V_6 ) ;
V_256 = 1 ;
V_4 -> V_217 = V_255 -> V_217 ;
}
} else if ( V_4 -> V_217 ) {
V_256 = 1 ;
V_4 -> V_217 = V_218 ;
V_4 -> V_8 = 0 ;
V_4 -> V_5 = - 1 ;
}
if ( V_256 && F_80 ( V_4 ) )
F_81 ( V_255 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
char V_259 [ V_260 + 3 ] ;
struct V_254 * V_255 = NULL ;
snprintf ( V_259 , sizeof( V_259 ) , V_261 ,
V_4 -> V_262 -> V_263 , V_4 -> V_259 ) ;
V_4 -> V_217 = V_218 ;
V_4 -> V_8 = 0 ;
V_4 -> V_5 = - 1 ;
V_255 = F_83 ( V_2 , V_259 , F_79 ,
0 , V_4 -> V_42 ) ;
if ( F_84 ( V_255 ) ) {
F_52 ( & V_2 -> V_112 , L_15 ) ;
return F_85 ( V_255 ) ;
}
F_86 ( & V_2 -> V_112 , L_16 ,
V_255 -> V_84 , V_255 -> V_264 -> V_265 ) ;
V_4 -> V_255 = V_255 ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_124 ;
V_124 = F_82 ( V_2 ) ;
if ( V_124 )
return V_124 ;
F_88 ( V_4 -> V_255 , V_266 , V_267 ) ;
F_89 ( V_4 -> V_255 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_268 * V_269 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_270 ;
int V_124 ;
F_91 ( & V_4 -> V_241 , V_270 ) ;
V_124 = F_92 ( V_4 -> V_255 , V_269 ) ;
F_93 ( & V_4 -> V_241 , V_270 ) ;
return V_124 ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_268 * V_269 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_270 ;
int V_124 ;
F_91 ( & V_4 -> V_241 , V_270 ) ;
F_68 ( V_2 ) ;
V_124 = F_95 ( V_4 -> V_255 , V_269 ) ;
if ( V_124 )
goto V_271;
if ( V_269 -> V_5 == V_272 )
V_4 -> V_5 = 1 ;
else
V_4 -> V_5 = 0 ;
if ( V_4 -> V_47 -> V_257 )
V_4 -> V_47 -> V_257 ( V_2 ) ;
V_271:
F_11 ( 1 ) ;
F_69 ( V_2 ) ;
F_93 ( & V_4 -> V_241 , V_270 ) ;
return V_124 ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_270 ;
int V_124 ;
F_91 ( & V_4 -> V_241 , V_270 ) ;
V_124 = F_97 ( V_4 -> V_255 ) ;
F_93 ( & V_4 -> V_241 , V_270 ) ;
return V_124 ;
}
static V_69 F_98 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_273 ;
}
static void F_99 ( struct V_1 * V_2 , V_69 V_274 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_273 = V_274 ;
}
static int F_100 ( struct V_1 * V_239 , int V_275 )
{
switch ( V_275 ) {
case V_276 :
return V_277 ;
default:
return - V_278 ;
}
}
static void F_101 ( struct V_1 * V_2 ,
struct V_279 * V_181 , T_5 * V_70 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_11 = 0 ;
V_70 [ V_11 ++ ] = V_4 -> V_106 ;
V_70 [ V_11 ++ ] = V_4 -> V_107 ;
V_70 [ V_11 ++ ] = V_4 -> V_108 ;
V_70 [ V_11 ++ ] = V_4 -> V_109 ;
}
static void F_102 ( struct V_1 * V_2 , V_69 V_280 , T_6 * V_70 )
{
switch ( V_280 ) {
case V_276 :
memcpy ( V_70 , * V_281 ,
sizeof( V_281 ) ) ;
break;
}
}
static int F_103 ( struct V_1 * V_2 )
{
int V_124 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_104 ( & V_4 -> V_282 -> V_112 ) ;
V_124 = F_105 ( V_2 -> V_238 , F_74 ,
#if F_56 ( V_283 ) || \
F_56 ( V_284 ) || \
F_56 ( V_285 )
V_286 ,
#else
0 ,
#endif
V_2 -> V_265 , V_2 ) ;
if ( V_124 ) {
F_52 ( & V_2 -> V_112 , L_17 ) ;
return V_124 ;
}
V_124 = F_50 ( V_2 ) ;
if ( V_124 )
goto V_287;
V_124 = F_55 ( V_2 ) ;
if ( V_124 )
goto V_287;
V_124 = F_87 ( V_2 ) ;
if ( V_124 )
goto V_287;
F_106 ( & V_4 -> V_251 ) ;
V_4 -> V_251 . V_288 = ( V_252 + ( 24 * V_253 ) ) / 10 ;
F_107 ( & V_4 -> V_251 , F_77 , ( unsigned long ) V_2 ) ;
return V_124 ;
V_287:
F_108 ( V_2 -> V_238 , V_2 ) ;
F_109 ( & V_4 -> V_282 -> V_112 ) ;
return V_124 ;
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_100 * V_101 ;
int V_11 ;
F_111 ( V_2 ) ;
if ( F_112 ( V_4 ) )
F_52 ( & V_2 -> V_112 , L_18
L_19 , V_2 -> V_265 , ( int ) F_4 ( V_2 , V_158 ) ) ;
V_2 -> V_181 . V_289 ++ ;
F_113 ( & V_4 -> V_251 ) ;
for ( V_11 = 0 ; V_11 < V_97 ; V_11 ++ ) {
V_101 = & V_4 -> V_110 [ V_11 ] ;
V_101 -> V_114 = 0 ;
V_101 -> V_84 = 0xBADF00D0 ;
if ( V_4 -> V_96 [ V_11 ] )
F_42 ( V_4 -> V_96 [ V_11 ] ) ;
V_4 -> V_96 [ V_11 ] = NULL ;
}
for ( V_11 = 0 ; V_11 < V_99 ; V_11 ++ ) {
if ( V_4 -> V_98 [ V_11 ] )
F_42 ( V_4 -> V_98 [ V_11 ] ) ;
V_4 -> V_98 [ V_11 ] = NULL ;
}
F_55 ( V_2 ) ;
V_4 -> V_251 . V_288 = ( V_252 + ( 24 * V_253 ) ) / 10 ;
F_114 ( & V_4 -> V_251 ) ;
}
static int F_115 ( struct V_65 * V_66 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_102 * V_103 ;
V_69 V_178 ;
unsigned long V_270 ;
F_91 ( & V_4 -> V_241 , V_270 ) ;
if ( ( V_4 -> V_107 - V_4 -> V_109 ) >= ( V_99 - 4 ) ) {
if ( ! F_58 ( V_2 ) ) {
if ( F_116 ( V_4 ) )
F_117 ( & V_2 -> V_112 , L_20 ) ;
F_111 ( V_2 ) ;
F_93 ( & V_4 -> V_241 , V_270 ) ;
return V_290 ;
}
}
F_93 ( & V_4 -> V_241 , V_270 ) ;
V_178 = V_4 -> V_107 % V_99 ;
V_4 -> V_98 [ V_178 ] = V_66 ;
V_103 = & V_4 -> V_120 [ V_178 ] ;
if ( ! V_4 -> V_47 -> V_140 )
F_62 ( F_63 ( F_49 ( V_103 -> V_84 , 4 ) ) ,
V_66 -> V_291 + 2 ) ;
V_103 -> V_84 = F_46 ( & V_2 -> V_112 , V_66 -> V_70 , V_66 -> V_291 ,
V_180 ) ;
if ( V_66 -> V_291 < V_292 )
V_103 -> V_117 = V_292 ;
else
V_103 -> V_117 = V_66 -> V_291 ;
if ( V_178 >= V_99 - 1 )
V_103 -> V_114 |= F_24 ( V_4 , V_179 | V_123 ) ;
else
V_103 -> V_114 |= F_24 ( V_4 , V_179 ) ;
V_4 -> V_107 ++ ;
if ( ! ( F_4 ( V_2 , V_236 ) & F_32 ( V_4 ) ) )
F_3 ( V_2 , F_32 ( V_4 ) , V_236 ) ;
return V_293 ;
}
static int F_118 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_294 ;
F_111 ( V_2 ) ;
F_3 ( V_2 , 0x0000 , V_138 ) ;
F_3 ( V_2 , 0 , V_236 ) ;
F_3 ( V_2 , 0 , V_176 ) ;
if ( V_4 -> V_255 ) {
F_119 ( V_4 -> V_255 ) ;
F_120 ( V_4 -> V_255 ) ;
}
F_108 ( V_2 -> V_238 , V_2 ) ;
F_113 ( & V_4 -> V_251 ) ;
F_41 ( V_2 ) ;
V_294 = sizeof( struct V_100 ) * V_97 ;
F_54 ( NULL , V_294 , V_4 -> V_110 , V_4 -> V_118 ) ;
V_294 = sizeof( struct V_102 ) * V_99 ;
F_54 ( NULL , V_294 , V_4 -> V_120 , V_4 -> V_122 ) ;
F_109 ( & V_4 -> V_282 -> V_112 ) ;
return 0 ;
}
static struct V_295 * F_121 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_104 ( & V_4 -> V_282 -> V_112 ) ;
V_2 -> V_181 . V_296 += F_4 ( V_2 , V_297 ) ;
F_3 ( V_2 , 0 , V_297 ) ;
V_2 -> V_181 . V_298 += F_4 ( V_2 , V_299 ) ;
F_3 ( V_2 , 0 , V_299 ) ;
V_2 -> V_181 . V_213 += F_4 ( V_2 , V_300 ) ;
F_3 ( V_2 , 0 , V_300 ) ;
if ( F_13 ( V_4 ) ) {
V_2 -> V_181 . V_213 += F_4 ( V_2 , V_301 ) ;
F_3 ( V_2 , 0 , V_301 ) ;
V_2 -> V_181 . V_213 += F_4 ( V_2 , V_302 ) ;
F_3 ( V_2 , 0 , V_302 ) ;
} else {
V_2 -> V_181 . V_213 += F_4 ( V_2 , V_303 ) ;
F_3 ( V_2 , 0 , V_303 ) ;
}
F_109 ( & V_4 -> V_282 -> V_112 ) ;
return & V_2 -> V_181 ;
}
static int F_122 ( struct V_1 * V_2 , struct V_304 * V_305 ,
int V_306 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_254 * V_255 = V_4 -> V_255 ;
if ( ! F_123 ( V_2 ) )
return - V_307 ;
if ( ! V_255 )
return - V_308 ;
return F_124 ( V_255 , V_305 , V_306 ) ;
}
static void * F_125 ( struct V_3 * V_4 ,
int V_178 )
{
return F_126 ( V_4 , V_309 ) + ( V_178 / 8 * 4 ) ;
}
static V_69 F_127 ( int V_178 )
{
return 0x0f << ( 28 - ( ( V_178 % 8 ) * 4 ) ) ;
}
static V_69 F_128 ( struct V_3 * V_4 , int V_178 )
{
return ( 0x08 >> ( V_4 -> V_310 << 1 ) ) << ( 28 - ( ( V_178 % 8 ) * 4 ) ) ;
}
static void F_129 ( struct V_1 * V_2 ,
int V_178 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_69 V_311 ;
void * V_80 ;
V_80 = F_125 ( V_4 , V_178 ) ;
V_311 = F_7 ( V_80 ) ;
F_10 ( V_311 | F_128 ( V_4 , V_178 ) , V_80 ) ;
}
static bool F_130 ( struct V_1 * V_2 ,
int V_178 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_69 V_312 , V_313 , V_311 ;
void * V_80 ;
V_80 = F_125 ( V_4 , V_178 ) ;
V_312 = F_127 ( V_178 ) ;
V_313 = F_128 ( V_4 , V_178 ) & ~ V_312 ;
V_311 = F_7 ( V_80 ) ;
F_10 ( V_311 & ~ V_312 , V_80 ) ;
return V_311 & V_313 ;
}
static int F_131 ( struct V_1 * V_2 )
{
int V_314 = V_315 * 100 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
while ( ( F_132 ( V_4 , V_316 ) & V_317 ) ) {
F_133 ( 10 ) ;
V_314 -- ;
if ( V_314 <= 0 ) {
F_52 ( & V_2 -> V_112 , L_21 , V_318 ) ;
return - V_319 ;
}
}
return 0 ;
}
static int F_134 ( struct V_1 * V_2 , void * V_320 ,
const T_6 * V_84 )
{
V_69 V_135 ;
V_135 = V_84 [ 0 ] << 24 | V_84 [ 1 ] << 16 | V_84 [ 2 ] << 8 | V_84 [ 3 ] ;
F_10 ( V_135 , V_320 ) ;
if ( F_131 ( V_2 ) < 0 )
return - V_321 ;
V_135 = V_84 [ 4 ] << 8 | V_84 [ 5 ] ;
F_10 ( V_135 , V_320 + 4 ) ;
if ( F_131 ( V_2 ) < 0 )
return - V_321 ;
return 0 ;
}
static void F_135 ( void * V_320 , T_6 * V_84 )
{
V_69 V_135 ;
V_135 = F_7 ( V_320 ) ;
V_84 [ 0 ] = ( V_135 >> 24 ) & 0xff ;
V_84 [ 1 ] = ( V_135 >> 16 ) & 0xff ;
V_84 [ 2 ] = ( V_135 >> 8 ) & 0xff ;
V_84 [ 3 ] = V_135 & 0xff ;
V_135 = F_7 ( V_320 + 4 ) ;
V_84 [ 4 ] = ( V_135 >> 8 ) & 0xff ;
V_84 [ 5 ] = V_135 & 0xff ;
}
static int F_136 ( struct V_1 * V_2 , const T_6 * V_84 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void * V_80 = F_126 ( V_4 , V_322 ) ;
int V_11 ;
T_6 V_323 [ V_324 ] ;
for ( V_11 = 0 ; V_11 < V_325 ; V_11 ++ , V_80 += 8 ) {
F_135 ( V_80 , V_323 ) ;
if ( memcmp ( V_84 , V_323 , V_324 ) == 0 )
return V_11 ;
}
return - V_326 ;
}
static int F_137 ( struct V_1 * V_2 )
{
T_6 V_327 [ V_324 ] ;
int V_178 ;
memset ( V_327 , 0 , sizeof( V_327 ) ) ;
V_178 = F_136 ( V_2 , V_327 ) ;
return ( V_178 < 0 ) ? - V_130 : V_178 ;
}
static int F_138 ( struct V_1 * V_2 ,
int V_178 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void * V_80 = F_126 ( V_4 , V_322 ) ;
int V_124 ;
T_6 V_327 [ V_324 ] ;
F_19 ( V_4 , F_132 ( V_4 , V_328 ) &
~ ( 1 << ( 31 - V_178 ) ) , V_328 ) ;
memset ( V_327 , 0 , sizeof( V_327 ) ) ;
V_124 = F_134 ( V_2 , V_80 + V_178 * 8 , V_327 ) ;
if ( V_124 < 0 )
return V_124 ;
return 0 ;
}
static int F_139 ( struct V_1 * V_2 , const T_6 * V_84 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void * V_80 = F_126 ( V_4 , V_322 ) ;
int V_11 , V_124 ;
if ( ! V_4 -> V_47 -> V_329 )
return 0 ;
V_11 = F_136 ( V_2 , V_84 ) ;
if ( V_11 < 0 ) {
V_11 = F_137 ( V_2 ) ;
if ( V_11 < 0 )
return - V_130 ;
V_124 = F_134 ( V_2 , V_80 + V_11 * 8 , V_84 ) ;
if ( V_124 < 0 )
return V_124 ;
F_19 ( V_4 , F_132 ( V_4 , V_328 ) |
( 1 << ( 31 - V_11 ) ) , V_328 ) ;
}
F_129 ( V_2 , V_11 ) ;
return 0 ;
}
static int F_140 ( struct V_1 * V_2 , const T_6 * V_84 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_11 , V_124 ;
if ( ! V_4 -> V_47 -> V_329 )
return 0 ;
V_11 = F_136 ( V_2 , V_84 ) ;
if ( V_11 ) {
if ( F_130 ( V_2 , V_11 ) )
goto V_330;
V_124 = F_138 ( V_2 , V_11 ) ;
if ( V_124 < 0 )
return V_124 ;
}
V_330:
return 0 ;
}
static int F_141 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_11 , V_124 ;
if ( F_142 ( ! V_4 -> V_47 -> V_329 ) )
return 0 ;
for ( V_11 = 0 ; V_11 < V_325 ; V_11 ++ ) {
if ( F_130 ( V_2 , V_11 ) )
continue;
V_124 = F_138 ( V_2 , V_11 ) ;
if ( V_124 < 0 )
return V_124 ;
}
return 0 ;
}
static void F_143 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_6 V_84 [ V_324 ] ;
void * V_80 = F_126 ( V_4 , V_322 ) ;
int V_11 ;
if ( F_142 ( ! V_4 -> V_47 -> V_329 ) )
return;
for ( V_11 = 0 ; V_11 < V_325 ; V_11 ++ , V_80 += 8 ) {
F_135 ( V_80 , V_84 ) ;
if ( F_144 ( V_84 ) )
F_140 ( V_2 , V_84 ) ;
}
}
static void F_145 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_69 V_331 ;
int V_332 = 0 ;
unsigned long V_270 ;
F_91 ( & V_4 -> V_241 , V_270 ) ;
V_331 = ( F_4 ( V_2 , V_6 ) & ~ V_333 ) | V_334 ;
if ( ! ( V_2 -> V_270 & V_335 ) ) {
F_143 ( V_2 ) ;
V_332 = 1 ;
}
if ( V_2 -> V_270 & V_336 ) {
F_143 ( V_2 ) ;
V_331 &= ~ V_334 ;
V_332 = 1 ;
}
if ( V_2 -> V_270 & V_337 ) {
F_141 ( V_2 ) ;
V_331 = ( V_331 & ~ V_334 ) | V_333 ;
} else if ( V_4 -> V_47 -> V_329 ) {
struct V_338 * V_339 ;
F_146 (ha, ndev) {
if ( V_332 && F_144 ( V_339 -> V_84 ) )
continue;
if ( F_139 ( V_2 , V_339 -> V_84 ) < 0 ) {
if ( ! V_332 ) {
F_143 ( V_2 ) ;
V_331 &= ~ V_334 ;
V_332 = 1 ;
}
}
}
} else {
V_331 = ( V_331 & ~ V_333 ) | V_334 ;
}
F_3 ( V_2 , V_331 , V_6 ) ;
F_93 ( & V_4 -> V_241 , V_270 ) ;
}
static int F_147 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_310 )
return V_340 ;
else
return V_341 ;
}
static int F_148 ( struct V_1 * V_2 , T_3 V_342 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_343 = F_147 ( V_4 ) ;
if ( F_142 ( ! V_4 -> V_47 -> V_329 ) )
return - V_344 ;
if ( ! V_342 )
return 0 ;
V_4 -> V_345 ++ ;
if ( V_4 -> V_345 > 1 ) {
F_19 ( V_4 , 0 , V_343 ) ;
return 0 ;
}
F_19 ( V_4 , V_346 | ( V_342 & V_347 ) ,
V_343 ) ;
return 0 ;
}
static int F_149 ( struct V_1 * V_2 , T_3 V_342 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_343 = F_147 ( V_4 ) ;
if ( F_142 ( ! V_4 -> V_47 -> V_329 ) )
return - V_344 ;
if ( ! V_342 )
return 0 ;
V_4 -> V_345 -- ;
F_19 ( V_4 , 0 , V_343 ) ;
return 0 ;
}
static void F_150 ( struct V_3 * V_4 )
{
F_19 ( V_4 , 0 , V_348 ) ;
F_19 ( V_4 , 0 , V_349 ) ;
F_19 ( V_4 , 0 , V_350 ) ;
F_19 ( V_4 , 0xc , V_351 ) ;
F_19 ( V_4 , 0xc , V_352 ) ;
F_19 ( V_4 , 0 , V_353 ) ;
F_19 ( V_4 , 0 , V_354 ) ;
F_19 ( V_4 , 0 , V_355 ) ;
F_19 ( V_4 , 0 , V_356 ) ;
F_19 ( V_4 , V_357 | V_358 , V_359 ) ;
if ( F_13 ( V_4 ) ) {
F_19 ( V_4 , 0 , V_360 ) ;
F_19 ( V_4 , 0 , V_361 ) ;
} else {
F_19 ( V_4 , 0 , V_362 ) ;
F_19 ( V_4 , 0 , V_363 ) ;
}
F_19 ( V_4 , 0 , V_364 ) ;
F_19 ( V_4 , 0 , V_365 ) ;
F_19 ( V_4 , 0 , V_328 ) ;
F_19 ( V_4 , 0 , V_309 ) ;
F_19 ( V_4 , 0 , V_366 ) ;
F_19 ( V_4 , 0 , V_367 ) ;
F_19 ( V_4 , 0 , V_368 ) ;
}
static int F_151 ( struct V_1 * V_2 )
{
struct V_262 * V_369 = F_152 ( & V_2 -> V_112 ) ;
F_153 ( V_369 ) ;
F_154 ( & V_2 -> V_112 , NULL ) ;
F_43 ( V_369 -> V_238 ) ;
F_155 ( V_369 ) ;
return 0 ;
}
static int F_156 ( struct V_1 * V_2 , int V_263 ,
struct V_370 * V_371 )
{
int V_124 , V_11 ;
struct V_89 * V_90 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_90 = F_157 ( sizeof( struct V_89 ) , V_129 ) ;
if ( ! V_90 ) {
V_124 = - V_130 ;
goto V_372;
}
V_90 -> V_84 = V_4 -> V_84 + V_4 -> V_80 [ V_373 ] ;
V_90 -> V_91 = V_371 -> V_374 ;
V_90 -> V_94 = 0x08 ;
V_90 -> V_93 = 0x04 ;
V_90 -> V_92 = 0x02 ;
V_90 -> V_95 = 0x01 ;
V_90 -> V_87 . V_375 = & V_376 ;
V_4 -> V_262 = F_158 ( & V_90 -> V_87 ) ;
if ( ! V_4 -> V_262 ) {
V_124 = - V_130 ;
goto V_377;
}
V_4 -> V_262 -> V_265 = L_22 ;
V_4 -> V_262 -> V_378 = & V_2 -> V_112 ;
snprintf ( V_4 -> V_262 -> V_263 , V_260 , L_23 ,
V_4 -> V_282 -> V_265 , V_263 ) ;
V_4 -> V_262 -> V_238 = F_51 ( sizeof( int ) * V_379 , V_129 ) ;
if ( ! V_4 -> V_262 -> V_238 ) {
V_124 = - V_130 ;
goto V_380;
}
for ( V_11 = 0 ; V_11 < V_379 ; V_11 ++ )
V_4 -> V_262 -> V_238 [ V_11 ] = V_381 ;
V_124 = F_159 ( V_4 -> V_262 ) ;
if ( V_124 )
goto V_287;
F_154 ( & V_2 -> V_112 , V_4 -> V_262 ) ;
return 0 ;
V_287:
F_43 ( V_4 -> V_262 -> V_238 ) ;
V_380:
F_155 ( V_4 -> V_262 ) ;
V_377:
F_43 ( V_90 ) ;
V_372:
return V_124 ;
}
static const T_3 * F_160 ( int V_382 )
{
const T_3 * V_80 = NULL ;
switch ( V_382 ) {
case V_383 :
V_80 = V_81 ;
break;
case V_384 :
V_80 = V_385 ;
break;
case V_386 :
V_80 = V_387 ;
break;
default:
F_14 ( V_20 L_24 , V_382 ) ;
break;
}
return V_80 ;
}
static int F_161 ( struct V_388 * V_282 )
{
int V_124 , V_389 = 0 ;
struct V_390 * V_391 ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_370 * V_371 ;
V_391 = F_162 ( V_282 , V_392 , 0 ) ;
if ( F_142 ( V_391 == NULL ) ) {
F_52 ( & V_282 -> V_112 , L_25 ) ;
V_124 = - V_307 ;
goto V_372;
}
V_2 = F_163 ( sizeof( struct V_3 ) ) ;
if ( ! V_2 ) {
V_124 = - V_130 ;
goto V_372;
}
V_2 -> V_393 = V_391 -> V_394 ;
V_389 = V_282 -> V_263 ;
if ( V_389 < 0 )
V_389 = 0 ;
V_2 -> V_395 = - 1 ;
V_124 = F_164 ( V_282 , 0 ) ;
if ( V_124 < 0 ) {
V_124 = - V_308 ;
goto V_396;
}
V_2 -> V_238 = V_124 ;
F_165 ( V_2 , & V_282 -> V_112 ) ;
F_166 ( V_2 ) ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_84 = F_167 ( V_391 -> V_394 , F_168 ( V_391 ) ) ;
if ( V_4 -> V_84 == NULL ) {
V_124 = - V_130 ;
F_52 ( & V_282 -> V_112 , L_26 ) ;
goto V_396;
}
F_169 ( & V_4 -> V_241 ) ;
V_4 -> V_282 = V_282 ;
F_170 ( & V_282 -> V_112 ) ;
F_171 ( & V_282 -> V_112 ) ;
V_371 = (struct V_370 * ) ( V_282 -> V_112 . V_397 ) ;
V_4 -> V_259 = V_371 -> V_398 ;
V_4 -> V_42 = V_371 -> V_42 ;
V_4 -> V_73 = V_371 -> V_73 ;
V_4 -> V_216 = V_371 -> V_216 ;
V_4 -> V_221 = V_371 -> V_221 ;
V_4 -> V_80 = F_160 ( V_371 -> V_382 ) ;
#if F_56 ( V_399 )
V_4 -> V_47 = F_17 ( V_4 ) ;
#else
V_4 -> V_47 = & V_33 ;
#endif
F_21 ( V_4 -> V_47 ) ;
V_2 -> V_400 = & V_401 ;
F_172 ( V_2 , & V_402 ) ;
V_2 -> V_403 = V_404 ;
V_4 -> V_273 = V_405 ;
V_4 -> V_406 = V_407 >> ( V_389 << 1 ) ;
V_4 -> V_408 = V_409 >> ( V_389 << 1 ) ;
F_31 ( V_2 , V_371 -> V_410 ) ;
if ( V_4 -> V_47 -> V_329 ) {
struct V_390 * V_411 ;
V_411 = F_162 ( V_282 , V_392 , 1 ) ;
if ( ! V_411 ) {
F_52 ( & V_282 -> V_112 , L_27 ) ;
goto V_396;
}
V_4 -> V_412 = F_167 ( V_411 -> V_394 ,
F_168 ( V_411 ) ) ;
V_4 -> V_310 = V_389 % 2 ;
V_2 -> V_413 = V_414 ;
}
if ( ! V_389 || V_371 -> V_415 ) {
if ( V_4 -> V_47 -> V_416 )
V_4 -> V_47 -> V_416 ( V_2 ) ;
if ( V_4 -> V_47 -> V_329 ) {
F_150 ( V_4 ) ;
}
}
V_124 = F_173 ( V_2 ) ;
if ( V_124 )
goto V_396;
V_124 = F_156 ( V_2 , V_282 -> V_263 , V_371 ) ;
if ( V_124 )
goto V_417;
F_174 ( L_28 ,
( V_69 ) V_2 -> V_393 , V_2 -> V_76 , V_2 -> V_238 ) ;
F_175 ( V_282 , V_2 ) ;
return V_124 ;
V_417:
F_176 ( V_2 ) ;
V_396:
if ( V_4 && V_4 -> V_84 )
F_177 ( V_4 -> V_84 ) ;
if ( V_4 && V_4 -> V_412 )
F_177 ( V_4 -> V_412 ) ;
if ( V_2 )
F_178 ( V_2 ) ;
V_372:
return V_124 ;
}
static int F_179 ( struct V_388 * V_282 )
{
struct V_1 * V_2 = F_180 ( V_282 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_47 -> V_329 )
F_177 ( V_4 -> V_412 ) ;
F_151 ( V_2 ) ;
F_176 ( V_2 ) ;
F_181 ( & V_282 -> V_112 ) ;
F_177 ( V_4 -> V_84 ) ;
F_178 ( V_2 ) ;
F_175 ( V_282 , NULL ) ;
return 0 ;
}
static int F_182 ( struct V_418 * V_112 )
{
return 0 ;
}
