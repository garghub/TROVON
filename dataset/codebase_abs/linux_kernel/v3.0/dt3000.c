static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return F_2 ( V_2 , V_5 . V_6 ) ;
}
static void T_2 F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
static int T_3 F_5 ( void )
{
int V_7 ;
V_7 = F_6 ( & V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_8 . V_9 = ( char * ) V_5 . V_6 ;
return F_7 ( & V_8 ) ;
}
static void T_4 F_8 ( void )
{
F_9 ( & V_8 ) ;
F_10 ( & V_5 ) ;
}
static int F_11 ( struct V_10 * V_2 , unsigned int V_11 )
{
int V_12 ;
unsigned int V_13 = 0 ;
F_12 ( V_11 , V_14 -> V_15 + V_16 ) ;
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ ) {
V_13 = F_13 ( V_14 -> V_15 + V_16 ) ;
if ( ( V_13 & V_18 ) != V_19 )
break;
F_14 ( 1 ) ;
}
if ( ( V_13 & V_18 ) == V_20 )
return 0 ;
F_15 ( L_1 , V_13 ) ;
return - V_21 ;
}
static unsigned int F_16 ( struct V_10 * V_2 ,
unsigned int V_22 , unsigned int V_23 ,
unsigned int V_24 )
{
F_12 ( V_22 , V_14 -> V_15 + V_25 ) ;
F_12 ( V_23 , V_14 -> V_15 + F_17 ( 0 ) ) ;
F_12 ( V_24 , V_14 -> V_15 + F_17 ( 1 ) ) ;
F_11 ( V_2 , V_26 ) ;
return F_13 ( V_14 -> V_15 + F_17 ( 2 ) ) ;
}
static void F_18 ( struct V_10 * V_2 , unsigned int V_22 ,
unsigned int V_23 , unsigned int V_27 )
{
F_12 ( V_22 , V_14 -> V_15 + V_25 ) ;
F_12 ( V_23 , V_14 -> V_15 + F_17 ( 0 ) ) ;
F_12 ( 0 , V_14 -> V_15 + F_17 ( 1 ) ) ;
F_12 ( V_27 , V_14 -> V_15 + F_17 ( 2 ) ) ;
F_11 ( V_2 , V_28 ) ;
}
static T_5 F_19 ( int V_29 , void * V_30 )
{
struct V_10 * V_2 = V_30 ;
struct V_31 * V_32 ;
unsigned int V_13 ;
if ( ! V_2 -> V_33 )
return V_34 ;
V_32 = V_2 -> V_35 + 0 ;
V_13 = F_13 ( V_14 -> V_15 + V_36 ) ;
#ifdef F_20
F_21 ( V_13 ) ;
#endif
if ( V_13 & V_37 ) {
F_22 ( V_2 , V_32 ) ;
V_32 -> V_38 -> V_39 |= V_40 ;
}
if ( V_13 & ( V_41 | V_42 ) )
V_32 -> V_38 -> V_39 |= V_43 | V_44 ;
V_45 ++ ;
if ( V_45 >= 10 ) {
F_23 ( V_2 , V_32 ) ;
V_32 -> V_38 -> V_39 |= V_44 ;
}
F_24 ( V_2 , V_32 ) ;
return V_46 ;
}
static void F_21 ( unsigned int V_47 )
{
int V_12 ;
F_15 ( L_2 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
if ( V_47 & ( 1 << V_12 ) )
F_15 ( L_3 , V_48 [ V_12 ] ) ;
}
F_15 ( L_4 ) ;
}
static void F_22 ( struct V_10 * V_2 ,
struct V_31 * V_32 )
{
int V_49 ;
int V_50 ;
int V_51 ;
int V_12 ;
short V_27 ;
V_49 = F_13 ( V_14 -> V_15 + V_52 ) ;
V_51 = V_49 - V_14 -> V_53 ;
if ( V_51 < 0 )
V_51 += V_54 ;
F_15 ( L_5 , V_51 ) ;
V_50 = V_14 -> V_55 ;
for ( V_12 = 0 ; V_12 < V_51 ; V_12 ++ ) {
V_27 = F_13 ( V_14 -> V_15 + V_56 + V_50 ) ;
F_25 ( V_32 -> V_38 , V_27 ) ;
V_50 ++ ;
if ( V_50 >= V_54 )
V_50 = 0 ;
}
V_14 -> V_55 = V_50 ;
F_12 ( V_50 , V_14 -> V_15 + V_57 ) ;
}
static int F_26 ( struct V_10 * V_2 ,
struct V_31 * V_32 , struct V_58 * V_11 )
{
int V_59 = 0 ;
int V_60 ;
V_60 = V_11 -> V_61 ;
V_11 -> V_61 &= V_62 ;
if ( ! V_11 -> V_61 || V_60 != V_11 -> V_61 )
V_59 ++ ;
V_60 = V_11 -> V_63 ;
V_11 -> V_63 &= V_64 ;
if ( ! V_11 -> V_63 || V_60 != V_11 -> V_63 )
V_59 ++ ;
V_60 = V_11 -> V_65 ;
V_11 -> V_65 &= V_64 ;
if ( ! V_11 -> V_65 || V_60 != V_11 -> V_65 )
V_59 ++ ;
V_60 = V_11 -> V_66 ;
V_11 -> V_66 &= V_67 ;
if ( ! V_11 -> V_66 || V_60 != V_11 -> V_66 )
V_59 ++ ;
V_60 = V_11 -> V_68 ;
V_11 -> V_68 &= V_67 ;
if ( ! V_11 -> V_68 || V_60 != V_11 -> V_68 )
V_59 ++ ;
if ( V_59 )
return 1 ;
if ( V_59 )
return 2 ;
if ( V_11 -> V_69 != 0 ) {
V_11 -> V_69 = 0 ;
V_59 ++ ;
}
if ( V_11 -> V_63 == V_64 ) {
if ( V_11 -> V_70 < V_71 -> V_72 ) {
V_11 -> V_70 = V_71 -> V_72 ;
V_59 ++ ;
}
if ( V_11 -> V_70 > 100 * 16 * 65535 ) {
V_11 -> V_70 = 100 * 16 * 65535 ;
V_59 ++ ;
}
} else {
}
if ( V_11 -> V_65 == V_64 ) {
if ( V_11 -> V_73 < V_71 -> V_72 ) {
V_11 -> V_73 = V_71 -> V_72 ;
V_59 ++ ;
}
if ( V_11 -> V_73 > 50 * 16 * 65535 ) {
V_11 -> V_73 = 50 * 16 * 65535 ;
V_59 ++ ;
}
} else {
}
if ( V_11 -> V_74 != V_11 -> V_75 ) {
V_11 -> V_74 = V_11 -> V_75 ;
V_59 ++ ;
}
if ( V_11 -> V_68 == V_67 ) {
if ( V_11 -> V_76 > 0x00ffffff ) {
V_11 -> V_76 = 0x00ffffff ;
V_59 ++ ;
}
} else {
if ( V_11 -> V_76 != 0 ) {
V_11 -> V_76 = 0 ;
V_59 ++ ;
}
}
if ( V_59 )
return 3 ;
if ( V_11 -> V_63 == V_64 ) {
V_60 = V_11 -> V_70 ;
F_27 ( 100 , & V_11 -> V_70 ,
V_11 -> V_47 & V_77 ) ;
if ( V_60 != V_11 -> V_70 )
V_59 ++ ;
} else {
}
if ( V_11 -> V_65 == V_64 ) {
V_60 = V_11 -> V_73 ;
F_27 ( 50 , & V_11 -> V_73 ,
V_11 -> V_47 & V_77 ) ;
if ( V_60 != V_11 -> V_73 )
V_59 ++ ;
if ( V_11 -> V_63 == V_64 &&
V_11 -> V_70 <
V_11 -> V_73 * V_11 -> V_74 ) {
V_11 -> V_70 =
V_11 -> V_73 * V_11 -> V_74 ;
V_59 ++ ;
}
} else {
}
if ( V_59 )
return 4 ;
return 0 ;
}
static int F_27 ( unsigned int V_78 , unsigned int * V_79 ,
unsigned int V_80 )
{
int V_81 , V_82 , V_83 ;
for ( V_83 = 0 ; V_83 < 16 ; V_83 ++ ) {
V_82 = V_78 * ( V_83 + 1 ) ;
switch ( V_80 ) {
case V_84 :
default:
V_81 = ( * V_79 + V_82 / 2 ) / V_82 ;
break;
case V_85 :
V_81 = ( * V_79 ) / V_82 ;
break;
case V_86 :
V_81 = ( * V_79 ) / V_82 ;
break;
}
if ( V_81 < 65536 ) {
* V_79 = V_81 * V_82 ;
return ( V_83 << 16 ) | ( V_81 ) ;
}
}
V_83 = 15 ;
V_82 = V_78 * ( 1 << V_83 ) ;
V_81 = 65535 ;
* V_79 = V_81 * V_82 ;
return ( V_83 << 16 ) | ( V_81 ) ;
}
static int F_28 ( struct V_10 * V_2 , struct V_31 * V_32 )
{
struct V_58 * V_11 = & V_32 -> V_38 -> V_11 ;
int V_12 ;
unsigned int V_23 , V_87 , V_88 ;
unsigned int V_81 ;
unsigned int V_89 ;
int V_90 ;
unsigned int V_91 ;
F_15 ( L_6 ) ;
for ( V_12 = 0 ; V_12 < V_11 -> V_75 ; V_12 ++ ) {
V_23 = F_29 ( V_11 -> V_92 [ V_12 ] ) ;
V_87 = F_30 ( V_11 -> V_92 [ V_12 ] ) ;
F_12 ( ( V_87 << 6 ) | V_23 ,
V_14 -> V_15 + V_56 + V_12 ) ;
}
V_88 = F_31 ( V_11 -> V_92 [ 0 ] ) ;
F_12 ( V_11 -> V_74 , V_14 -> V_15 + F_17 ( 0 ) ) ;
F_15 ( L_7 , V_11 -> V_74 ) ;
if ( V_11 -> V_65 == V_64 ) {
V_81 = F_27 ( 50 , & V_11 -> V_73 ,
V_11 -> V_47 & V_77 ) ;
F_12 ( ( V_81 >> 16 ) , V_14 -> V_15 + F_17 ( 1 ) ) ;
F_15 ( L_8 , V_81 >> 16 ) ;
F_12 ( ( V_81 & 0xffff ) , V_14 -> V_15 + F_17 ( 2 ) ) ;
F_15 ( L_9 , V_81 & 0xffff ) ;
} else {
}
if ( V_11 -> V_63 == V_64 ) {
V_89 = F_27 ( 100 , & V_11 -> V_70 ,
V_11 -> V_47 & V_77 ) ;
F_12 ( ( V_89 >> 16 ) , V_14 -> V_15 + F_17 ( 3 ) ) ;
F_15 ( L_10 , V_89 >> 16 ) ;
F_12 ( ( V_89 & 0xffff ) , V_14 -> V_15 + F_17 ( 4 ) ) ;
F_15 ( L_11 , V_89 & 0xffff ) ;
} else {
}
V_91 = V_93 | 0 | 0 ;
F_12 ( V_91 , V_14 -> V_15 + F_17 ( 5 ) ) ;
F_15 ( L_12 , V_91 ) ;
F_12 ( V_88 == V_94 , V_14 -> V_15 + F_17 ( 6 ) ) ;
F_15 ( L_13 , V_88 == V_94 ) ;
F_12 ( V_54 / 2 , V_14 -> V_15 + F_17 ( 7 ) ) ;
F_15 ( L_14 , V_54 / 2 ) ;
F_12 ( V_95 , V_14 -> V_15 + V_25 ) ;
V_90 = F_11 ( V_2 , V_96 ) ;
F_12 ( V_37 | V_41 | V_42 ,
V_14 -> V_15 + V_97 ) ;
V_45 = 0 ;
F_12 ( V_95 , V_14 -> V_15 + V_25 ) ;
V_90 = F_11 ( V_2 , V_98 ) ;
return 0 ;
}
static int F_23 ( struct V_10 * V_2 , struct V_31 * V_32 )
{
int V_90 ;
F_12 ( V_95 , V_14 -> V_15 + V_25 ) ;
V_90 = F_11 ( V_2 , V_99 ) ;
F_12 ( 0 , V_14 -> V_15 + V_97 ) ;
return 0 ;
}
static int F_32 ( struct V_10 * V_2 , struct V_31 * V_32 ,
struct V_100 * V_101 , unsigned int * V_27 )
{
int V_12 ;
unsigned int V_23 , V_24 , V_88 ;
V_23 = F_29 ( V_101 -> V_102 ) ;
V_24 = F_30 ( V_101 -> V_102 ) ;
V_88 = F_31 ( V_101 -> V_102 ) ;
for ( V_12 = 0 ; V_12 < V_101 -> V_103 ; V_12 ++ )
V_27 [ V_12 ] = F_16 ( V_2 , V_95 , V_23 , V_24 ) ;
return V_12 ;
}
static int F_33 ( struct V_10 * V_2 , struct V_31 * V_32 ,
struct V_100 * V_101 , unsigned int * V_27 )
{
int V_12 ;
unsigned int V_23 ;
V_23 = F_29 ( V_101 -> V_102 ) ;
for ( V_12 = 0 ; V_12 < V_101 -> V_103 ; V_12 ++ ) {
F_18 ( V_2 , V_104 , V_23 , V_27 [ V_12 ] ) ;
V_14 -> V_105 [ V_23 ] = V_27 [ V_12 ] ;
}
return V_12 ;
}
static int F_34 ( struct V_10 * V_2 ,
struct V_31 * V_32 ,
struct V_100 * V_101 , unsigned int * V_27 )
{
int V_12 ;
unsigned int V_23 ;
V_23 = F_29 ( V_101 -> V_102 ) ;
for ( V_12 = 0 ; V_12 < V_101 -> V_103 ; V_12 ++ )
V_27 [ V_12 ] = V_14 -> V_105 [ V_23 ] ;
return V_12 ;
}
static void F_35 ( struct V_10 * V_2 , int V_106 )
{
F_12 ( V_107 , V_14 -> V_15 + V_25 ) ;
F_12 ( V_106 , V_14 -> V_15 + F_17 ( 0 ) ) ;
#if 0
writew(0, devpriv->io_addr + DPR_Params(1));
writew(0, devpriv->io_addr + DPR_Params(2));
#endif
F_11 ( V_2 , V_96 ) ;
}
static int F_36 ( struct V_10 * V_2 ,
struct V_31 * V_32 ,
struct V_100 * V_101 , unsigned int * V_27 )
{
int V_108 ;
V_108 = ( F_29 ( V_101 -> V_102 ) < 4 ) ? 0x0f : 0xf0 ;
switch ( V_27 [ 0 ] ) {
case V_109 :
V_32 -> V_110 |= V_108 ;
break;
case V_111 :
V_32 -> V_110 &= ~ V_108 ;
break;
case V_112 :
V_27 [ 1 ] =
( V_32 ->
V_110 & ( 1 << F_29 ( V_101 -> V_102 ) ) ) ? V_113 :
V_114 ;
return V_101 -> V_103 ;
break;
default:
return - V_115 ;
break;
}
V_108 = ( V_32 -> V_110 & 0x01 ) | ( ( V_32 -> V_110 & 0x10 ) >> 3 ) ;
F_35 ( V_2 , V_108 ) ;
return V_101 -> V_103 ;
}
static int F_37 ( struct V_10 * V_2 ,
struct V_31 * V_32 ,
struct V_100 * V_101 , unsigned int * V_27 )
{
if ( V_101 -> V_103 != 2 )
return - V_115 ;
if ( V_27 [ 0 ] ) {
V_32 -> V_116 &= ~ V_27 [ 0 ] ;
V_32 -> V_116 |= V_27 [ 1 ] & V_27 [ 0 ] ;
F_18 ( V_2 , V_107 , 0 , V_32 -> V_116 ) ;
}
V_27 [ 1 ] = F_16 ( V_2 , V_117 , 0 , 0 ) ;
return 2 ;
}
static int F_38 ( struct V_10 * V_2 ,
struct V_31 * V_32 ,
struct V_100 * V_101 , unsigned int * V_27 )
{
unsigned int V_118 = F_29 ( V_101 -> V_102 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_101 -> V_103 ; V_12 ++ ) {
F_12 ( V_119 , V_14 -> V_15 + V_25 ) ;
F_12 ( V_118 , V_14 -> V_15 + F_17 ( 0 ) ) ;
F_12 ( 1 , V_14 -> V_15 + F_17 ( 1 ) ) ;
F_11 ( V_2 , V_120 ) ;
V_27 [ V_12 ] = F_13 ( V_14 -> V_15 + F_17 ( 2 ) ) ;
}
return V_12 ;
}
static int F_39 ( struct V_10 * V_2 , struct V_121 * V_122 )
{
struct V_31 * V_32 ;
int V_123 , V_124 ;
int V_90 = 0 ;
F_15 ( L_15 ) ;
V_123 = V_122 -> V_125 [ 0 ] ;
V_124 = V_122 -> V_125 [ 1 ] ;
V_90 = F_40 ( V_2 , sizeof( struct V_126 ) ) ;
if ( V_90 < 0 )
return V_90 ;
V_90 = F_41 ( V_2 , V_123 , V_124 ) ;
if ( V_90 < 0 )
return V_90 ;
if ( V_90 == 0 ) {
F_15 ( L_16 ) ;
return - V_127 ;
}
V_2 -> V_128 = V_71 -> V_9 ;
if ( F_42 ( V_14 -> V_1 -> V_29 , F_19 , V_129 ,
L_17 , V_2 ) ) {
F_15 ( L_18 , V_14 -> V_1 -> V_29 ) ;
return - V_115 ;
}
V_2 -> V_29 = V_14 -> V_1 -> V_29 ;
V_90 = F_43 ( V_2 , 4 ) ;
if ( V_90 < 0 )
return V_90 ;
V_32 = V_2 -> V_35 ;
V_2 -> V_130 = V_32 ;
V_32 -> type = V_131 ;
V_32 -> V_132 = V_133 | V_134 | V_135 | V_136 ;
V_32 -> V_137 = V_71 -> V_138 ;
V_32 -> V_139 = F_32 ;
V_32 -> V_140 = ( 1 << V_71 -> V_141 ) - 1 ;
V_32 -> V_142 = 512 ;
V_32 -> V_143 = & V_144 ;
V_32 -> V_145 = F_28 ;
V_32 -> V_146 = F_26 ;
V_32 -> V_147 = F_23 ;
V_32 ++ ;
V_32 -> type = V_148 ;
V_32 -> V_132 = V_149 ;
V_32 -> V_137 = 2 ;
V_32 -> V_139 = F_34 ;
V_32 -> V_150 = F_33 ;
V_32 -> V_140 = ( 1 << V_71 -> V_151 ) - 1 ;
V_32 -> V_142 = 1 ;
V_32 -> V_143 = & V_152 ;
V_32 ++ ;
V_32 -> type = V_153 ;
V_32 -> V_132 = V_133 | V_149 ;
V_32 -> V_137 = 8 ;
V_32 -> V_154 = F_36 ;
V_32 -> V_155 = F_37 ;
V_32 -> V_140 = 1 ;
V_32 -> V_142 = 8 ;
V_32 -> V_143 = & V_156 ;
V_32 ++ ;
V_32 -> type = V_157 ;
V_32 -> V_132 = V_133 ;
V_32 -> V_137 = 0x1000 ;
V_32 -> V_139 = F_38 ;
V_32 -> V_140 = 0xff ;
V_32 -> V_142 = 1 ;
V_32 -> V_143 = & V_158 ;
#if 0
s++;
s->type = COMEDI_SUBD_PROC;
#endif
return 0 ;
}
static int F_44 ( struct V_10 * V_2 )
{
if ( V_2 -> V_29 )
F_45 ( V_2 -> V_29 , V_2 ) ;
if ( V_14 ) {
if ( V_14 -> V_1 ) {
if ( V_14 -> V_159 )
F_46 ( V_14 -> V_1 ) ;
F_47 ( V_14 -> V_1 ) ;
}
if ( V_14 -> V_15 )
F_48 ( V_14 -> V_15 ) ;
}
return 0 ;
}
static int F_41 ( struct V_10 * V_2 , int V_123 , int V_124 )
{
int V_160 ;
int V_90 ;
struct V_1 * V_161 ;
V_161 = NULL ;
while ( ( V_161 = F_49 ( V_161 , & V_160 ) ) != NULL ) {
if ( ( V_123 == 0 && V_124 == 0 ) ||
( V_161 -> V_123 -> V_162 == V_123 &&
F_50 ( V_161 -> V_163 ) == V_124 ) ) {
break;
}
}
V_14 -> V_1 = V_161 ;
if ( V_160 >= 0 )
V_2 -> V_164 = V_165 + V_160 ;
if ( ! V_14 -> V_1 )
return 0 ;
V_90 = F_51 ( V_2 ) ;
if ( V_90 < 0 )
return V_90 ;
return 1 ;
}
static int F_51 ( struct V_10 * V_2 )
{
T_6 V_118 ;
int V_90 ;
V_90 = F_52 ( V_14 -> V_1 , L_17 ) ;
if ( V_90 < 0 )
return V_90 ;
V_118 = F_53 ( V_14 -> V_1 , 0 ) ;
V_14 -> V_159 = V_118 ;
V_14 -> V_15 = F_54 ( V_14 -> V_159 , V_166 ) ;
if ( ! V_14 -> V_15 )
return - V_167 ;
#if F_20
F_15 ( L_19 ,
( unsigned long long ) V_14 -> V_159 , V_14 -> V_15 ) ;
#endif
return 0 ;
}
static struct V_1 * F_49 ( struct V_1 * V_168 , int * V_160 )
{
int V_12 ;
for ( V_168 = F_55 ( V_169 , V_170 , V_168 ) ;
V_168 != NULL ;
V_168 = F_55 ( V_169 , V_170 , V_168 ) ) {
for ( V_12 = 0 ; V_12 < V_171 ; V_12 ++ ) {
if ( V_168 -> V_172 == V_165 [ V_12 ] . V_173 ) {
* V_160 = V_12 ;
return V_168 ;
}
}
F_15
( L_20 ,
V_168 -> V_172 ) ;
}
* V_160 = - 1 ;
return V_168 ;
}
