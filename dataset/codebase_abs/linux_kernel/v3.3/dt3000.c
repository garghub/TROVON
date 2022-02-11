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
F_15 ( V_2 -> V_21 , L_1 ,
V_13 ) ;
return - V_22 ;
}
static unsigned int F_16 ( struct V_10 * V_2 ,
unsigned int V_23 , unsigned int V_24 ,
unsigned int V_25 )
{
F_12 ( V_23 , V_14 -> V_15 + V_26 ) ;
F_12 ( V_24 , V_14 -> V_15 + F_17 ( 0 ) ) ;
F_12 ( V_25 , V_14 -> V_15 + F_17 ( 1 ) ) ;
F_11 ( V_2 , V_27 ) ;
return F_13 ( V_14 -> V_15 + F_17 ( 2 ) ) ;
}
static void F_18 ( struct V_10 * V_2 , unsigned int V_23 ,
unsigned int V_24 , unsigned int V_28 )
{
F_12 ( V_23 , V_14 -> V_15 + V_26 ) ;
F_12 ( V_24 , V_14 -> V_15 + F_17 ( 0 ) ) ;
F_12 ( 0 , V_14 -> V_15 + F_17 ( 1 ) ) ;
F_12 ( V_28 , V_14 -> V_15 + F_17 ( 2 ) ) ;
F_11 ( V_2 , V_29 ) ;
}
static T_5 F_19 ( int V_30 , void * V_31 )
{
struct V_10 * V_2 = V_31 ;
struct V_32 * V_33 ;
unsigned int V_13 ;
if ( ! V_2 -> V_34 )
return V_35 ;
V_33 = V_2 -> V_36 + 0 ;
V_13 = F_13 ( V_14 -> V_15 + V_37 ) ;
#ifdef F_20
F_21 ( V_13 ) ;
#endif
if ( V_13 & V_38 ) {
F_22 ( V_2 , V_33 ) ;
V_33 -> V_39 -> V_40 |= V_41 ;
}
if ( V_13 & ( V_42 | V_43 ) )
V_33 -> V_39 -> V_40 |= V_44 | V_45 ;
V_46 ++ ;
if ( V_46 >= 10 ) {
F_23 ( V_2 , V_33 ) ;
V_33 -> V_39 -> V_40 |= V_45 ;
}
F_24 ( V_2 , V_33 ) ;
return V_47 ;
}
static void F_21 ( unsigned int V_48 )
{
int V_12 ;
F_25 ( V_49 L_2 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
if ( V_48 & ( 1 << V_12 ) )
F_25 ( V_50 L_3 , V_51 [ V_12 ] ) ;
}
F_25 ( V_50 L_4 ) ;
}
static void F_22 ( struct V_10 * V_2 ,
struct V_32 * V_33 )
{
int V_52 ;
int V_53 ;
int V_54 ;
int V_12 ;
short V_28 ;
V_52 = F_13 ( V_14 -> V_15 + V_55 ) ;
V_54 = V_52 - V_14 -> V_56 ;
if ( V_54 < 0 )
V_54 += V_57 ;
F_15 ( V_2 -> V_21 , L_5 , V_54 ) ;
V_53 = V_14 -> V_58 ;
for ( V_12 = 0 ; V_12 < V_54 ; V_12 ++ ) {
V_28 = F_13 ( V_14 -> V_15 + V_59 + V_53 ) ;
F_26 ( V_33 -> V_39 , V_28 ) ;
V_53 ++ ;
if ( V_53 >= V_57 )
V_53 = 0 ;
}
V_14 -> V_58 = V_53 ;
F_12 ( V_53 , V_14 -> V_15 + V_60 ) ;
}
static int F_27 ( struct V_10 * V_2 ,
struct V_32 * V_33 , struct V_61 * V_11 )
{
int V_62 = 0 ;
int V_63 ;
V_63 = V_11 -> V_64 ;
V_11 -> V_64 &= V_65 ;
if ( ! V_11 -> V_64 || V_63 != V_11 -> V_64 )
V_62 ++ ;
V_63 = V_11 -> V_66 ;
V_11 -> V_66 &= V_67 ;
if ( ! V_11 -> V_66 || V_63 != V_11 -> V_66 )
V_62 ++ ;
V_63 = V_11 -> V_68 ;
V_11 -> V_68 &= V_67 ;
if ( ! V_11 -> V_68 || V_63 != V_11 -> V_68 )
V_62 ++ ;
V_63 = V_11 -> V_69 ;
V_11 -> V_69 &= V_70 ;
if ( ! V_11 -> V_69 || V_63 != V_11 -> V_69 )
V_62 ++ ;
V_63 = V_11 -> V_71 ;
V_11 -> V_71 &= V_70 ;
if ( ! V_11 -> V_71 || V_63 != V_11 -> V_71 )
V_62 ++ ;
if ( V_62 )
return 1 ;
if ( V_62 )
return 2 ;
if ( V_11 -> V_72 != 0 ) {
V_11 -> V_72 = 0 ;
V_62 ++ ;
}
if ( V_11 -> V_66 == V_67 ) {
if ( V_11 -> V_73 < V_74 -> V_75 ) {
V_11 -> V_73 = V_74 -> V_75 ;
V_62 ++ ;
}
if ( V_11 -> V_73 > 100 * 16 * 65535 ) {
V_11 -> V_73 = 100 * 16 * 65535 ;
V_62 ++ ;
}
} else {
}
if ( V_11 -> V_68 == V_67 ) {
if ( V_11 -> V_76 < V_74 -> V_75 ) {
V_11 -> V_76 = V_74 -> V_75 ;
V_62 ++ ;
}
if ( V_11 -> V_76 > 50 * 16 * 65535 ) {
V_11 -> V_76 = 50 * 16 * 65535 ;
V_62 ++ ;
}
} else {
}
if ( V_11 -> V_77 != V_11 -> V_78 ) {
V_11 -> V_77 = V_11 -> V_78 ;
V_62 ++ ;
}
if ( V_11 -> V_71 == V_70 ) {
if ( V_11 -> V_79 > 0x00ffffff ) {
V_11 -> V_79 = 0x00ffffff ;
V_62 ++ ;
}
} else {
if ( V_11 -> V_79 != 0 ) {
V_11 -> V_79 = 0 ;
V_62 ++ ;
}
}
if ( V_62 )
return 3 ;
if ( V_11 -> V_66 == V_67 ) {
V_63 = V_11 -> V_73 ;
F_28 ( 100 , & V_11 -> V_73 ,
V_11 -> V_48 & V_80 ) ;
if ( V_63 != V_11 -> V_73 )
V_62 ++ ;
} else {
}
if ( V_11 -> V_68 == V_67 ) {
V_63 = V_11 -> V_76 ;
F_28 ( 50 , & V_11 -> V_76 ,
V_11 -> V_48 & V_80 ) ;
if ( V_63 != V_11 -> V_76 )
V_62 ++ ;
if ( V_11 -> V_66 == V_67 &&
V_11 -> V_73 <
V_11 -> V_76 * V_11 -> V_77 ) {
V_11 -> V_73 =
V_11 -> V_76 * V_11 -> V_77 ;
V_62 ++ ;
}
} else {
}
if ( V_62 )
return 4 ;
return 0 ;
}
static int F_28 ( unsigned int V_81 , unsigned int * V_82 ,
unsigned int V_83 )
{
int V_84 , V_85 , V_86 ;
for ( V_86 = 0 ; V_86 < 16 ; V_86 ++ ) {
V_85 = V_81 * ( V_86 + 1 ) ;
switch ( V_83 ) {
case V_87 :
default:
V_84 = ( * V_82 + V_85 / 2 ) / V_85 ;
break;
case V_88 :
V_84 = ( * V_82 ) / V_85 ;
break;
case V_89 :
V_84 = ( * V_82 ) / V_85 ;
break;
}
if ( V_84 < 65536 ) {
* V_82 = V_84 * V_85 ;
return ( V_86 << 16 ) | ( V_84 ) ;
}
}
V_86 = 15 ;
V_85 = V_81 * ( 1 << V_86 ) ;
V_84 = 65535 ;
* V_82 = V_84 * V_85 ;
return ( V_86 << 16 ) | ( V_84 ) ;
}
static int F_29 ( struct V_10 * V_2 , struct V_32 * V_33 )
{
struct V_61 * V_11 = & V_33 -> V_39 -> V_11 ;
int V_12 ;
unsigned int V_24 , V_90 , V_91 ;
unsigned int V_84 ;
unsigned int V_92 ;
int V_93 ;
unsigned int V_94 ;
F_15 ( V_2 -> V_21 , L_6 ) ;
for ( V_12 = 0 ; V_12 < V_11 -> V_78 ; V_12 ++ ) {
V_24 = F_30 ( V_11 -> V_95 [ V_12 ] ) ;
V_90 = F_31 ( V_11 -> V_95 [ V_12 ] ) ;
F_12 ( ( V_90 << 6 ) | V_24 ,
V_14 -> V_15 + V_59 + V_12 ) ;
}
V_91 = F_32 ( V_11 -> V_95 [ 0 ] ) ;
F_12 ( V_11 -> V_77 , V_14 -> V_15 + F_17 ( 0 ) ) ;
F_15 ( V_2 -> V_21 , L_7 , V_11 -> V_77 ) ;
if ( V_11 -> V_68 == V_67 ) {
V_84 = F_28 ( 50 , & V_11 -> V_76 ,
V_11 -> V_48 & V_80 ) ;
F_12 ( ( V_84 >> 16 ) , V_14 -> V_15 + F_17 ( 1 ) ) ;
F_15 ( V_2 -> V_21 , L_8 , V_84 >> 16 ) ;
F_12 ( ( V_84 & 0xffff ) , V_14 -> V_15 + F_17 ( 2 ) ) ;
F_15 ( V_2 -> V_21 , L_9 , V_84 & 0xffff ) ;
} else {
}
if ( V_11 -> V_66 == V_67 ) {
V_92 = F_28 ( 100 , & V_11 -> V_73 ,
V_11 -> V_48 & V_80 ) ;
F_12 ( ( V_92 >> 16 ) , V_14 -> V_15 + F_17 ( 3 ) ) ;
F_15 ( V_2 -> V_21 , L_10 , V_92 >> 16 ) ;
F_12 ( ( V_92 & 0xffff ) , V_14 -> V_15 + F_17 ( 4 ) ) ;
F_15 ( V_2 -> V_21 , L_11 , V_92 & 0xffff ) ;
} else {
}
V_94 = V_96 | 0 | 0 ;
F_12 ( V_94 , V_14 -> V_15 + F_17 ( 5 ) ) ;
F_15 ( V_2 -> V_21 , L_12 , V_94 ) ;
F_12 ( V_91 == V_97 , V_14 -> V_15 + F_17 ( 6 ) ) ;
F_15 ( V_2 -> V_21 , L_13 , V_91 == V_97 ) ;
F_12 ( V_57 / 2 , V_14 -> V_15 + F_17 ( 7 ) ) ;
F_15 ( V_2 -> V_21 , L_14 , V_57 / 2 ) ;
F_12 ( V_98 , V_14 -> V_15 + V_26 ) ;
V_93 = F_11 ( V_2 , V_99 ) ;
F_12 ( V_38 | V_42 | V_43 ,
V_14 -> V_15 + V_100 ) ;
V_46 = 0 ;
F_12 ( V_98 , V_14 -> V_15 + V_26 ) ;
V_93 = F_11 ( V_2 , V_101 ) ;
return 0 ;
}
static int F_23 ( struct V_10 * V_2 , struct V_32 * V_33 )
{
int V_93 ;
F_12 ( V_98 , V_14 -> V_15 + V_26 ) ;
V_93 = F_11 ( V_2 , V_102 ) ;
F_12 ( 0 , V_14 -> V_15 + V_100 ) ;
return 0 ;
}
static int F_33 ( struct V_10 * V_2 , struct V_32 * V_33 ,
struct V_103 * V_104 , unsigned int * V_28 )
{
int V_12 ;
unsigned int V_24 , V_25 , V_91 ;
V_24 = F_30 ( V_104 -> V_105 ) ;
V_25 = F_31 ( V_104 -> V_105 ) ;
V_91 = F_32 ( V_104 -> V_105 ) ;
for ( V_12 = 0 ; V_12 < V_104 -> V_106 ; V_12 ++ )
V_28 [ V_12 ] = F_16 ( V_2 , V_98 , V_24 , V_25 ) ;
return V_12 ;
}
static int F_34 ( struct V_10 * V_2 , struct V_32 * V_33 ,
struct V_103 * V_104 , unsigned int * V_28 )
{
int V_12 ;
unsigned int V_24 ;
V_24 = F_30 ( V_104 -> V_105 ) ;
for ( V_12 = 0 ; V_12 < V_104 -> V_106 ; V_12 ++ ) {
F_18 ( V_2 , V_107 , V_24 , V_28 [ V_12 ] ) ;
V_14 -> V_108 [ V_24 ] = V_28 [ V_12 ] ;
}
return V_12 ;
}
static int F_35 ( struct V_10 * V_2 ,
struct V_32 * V_33 ,
struct V_103 * V_104 , unsigned int * V_28 )
{
int V_12 ;
unsigned int V_24 ;
V_24 = F_30 ( V_104 -> V_105 ) ;
for ( V_12 = 0 ; V_12 < V_104 -> V_106 ; V_12 ++ )
V_28 [ V_12 ] = V_14 -> V_108 [ V_24 ] ;
return V_12 ;
}
static void F_36 ( struct V_10 * V_2 , int V_109 )
{
F_12 ( V_110 , V_14 -> V_15 + V_26 ) ;
F_12 ( V_109 , V_14 -> V_15 + F_17 ( 0 ) ) ;
#if 0
writew(0, devpriv->io_addr + DPR_Params(1));
writew(0, devpriv->io_addr + DPR_Params(2));
#endif
F_11 ( V_2 , V_99 ) ;
}
static int F_37 ( struct V_10 * V_2 ,
struct V_32 * V_33 ,
struct V_103 * V_104 , unsigned int * V_28 )
{
int V_111 ;
V_111 = ( F_30 ( V_104 -> V_105 ) < 4 ) ? 0x0f : 0xf0 ;
switch ( V_28 [ 0 ] ) {
case V_112 :
V_33 -> V_113 |= V_111 ;
break;
case V_114 :
V_33 -> V_113 &= ~ V_111 ;
break;
case V_115 :
V_28 [ 1 ] =
( V_33 ->
V_113 & ( 1 << F_30 ( V_104 -> V_105 ) ) ) ? V_116 :
V_117 ;
return V_104 -> V_106 ;
break;
default:
return - V_118 ;
break;
}
V_111 = ( V_33 -> V_113 & 0x01 ) | ( ( V_33 -> V_113 & 0x10 ) >> 3 ) ;
F_36 ( V_2 , V_111 ) ;
return V_104 -> V_106 ;
}
static int F_38 ( struct V_10 * V_2 ,
struct V_32 * V_33 ,
struct V_103 * V_104 , unsigned int * V_28 )
{
if ( V_104 -> V_106 != 2 )
return - V_118 ;
if ( V_28 [ 0 ] ) {
V_33 -> V_119 &= ~ V_28 [ 0 ] ;
V_33 -> V_119 |= V_28 [ 1 ] & V_28 [ 0 ] ;
F_18 ( V_2 , V_110 , 0 , V_33 -> V_119 ) ;
}
V_28 [ 1 ] = F_16 ( V_2 , V_120 , 0 , 0 ) ;
return 2 ;
}
static int F_39 ( struct V_10 * V_2 ,
struct V_32 * V_33 ,
struct V_103 * V_104 , unsigned int * V_28 )
{
unsigned int V_121 = F_30 ( V_104 -> V_105 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_104 -> V_106 ; V_12 ++ ) {
F_12 ( V_122 , V_14 -> V_15 + V_26 ) ;
F_12 ( V_121 , V_14 -> V_15 + F_17 ( 0 ) ) ;
F_12 ( 1 , V_14 -> V_15 + F_17 ( 1 ) ) ;
F_11 ( V_2 , V_123 ) ;
V_28 [ V_12 ] = F_13 ( V_14 -> V_15 + F_17 ( 2 ) ) ;
}
return V_12 ;
}
static int F_40 ( struct V_10 * V_2 , struct V_124 * V_125 )
{
struct V_32 * V_33 ;
int V_126 , V_127 ;
int V_93 = 0 ;
F_15 ( V_2 -> V_21 , L_15 ) ;
V_126 = V_125 -> V_128 [ 0 ] ;
V_127 = V_125 -> V_128 [ 1 ] ;
V_93 = F_41 ( V_2 , sizeof( struct V_129 ) ) ;
if ( V_93 < 0 )
return V_93 ;
V_93 = F_42 ( V_2 , V_126 , V_127 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( V_93 == 0 ) {
F_43 ( V_2 -> V_21 , L_16 ) ;
return - V_130 ;
}
V_2 -> V_131 = V_74 -> V_9 ;
if ( F_44 ( V_14 -> V_1 -> V_30 , F_19 , V_132 ,
L_17 , V_2 ) ) {
F_45 ( V_2 -> V_21 , L_18 ,
V_14 -> V_1 -> V_30 ) ;
return - V_118 ;
}
V_2 -> V_30 = V_14 -> V_1 -> V_30 ;
V_93 = F_46 ( V_2 , 4 ) ;
if ( V_93 < 0 )
return V_93 ;
V_33 = V_2 -> V_36 ;
V_2 -> V_133 = V_33 ;
V_33 -> type = V_134 ;
V_33 -> V_135 = V_136 | V_137 | V_138 | V_139 ;
V_33 -> V_140 = V_74 -> V_141 ;
V_33 -> V_142 = F_33 ;
V_33 -> V_143 = ( 1 << V_74 -> V_144 ) - 1 ;
V_33 -> V_145 = 512 ;
V_33 -> V_146 = & V_147 ;
V_33 -> V_148 = F_29 ;
V_33 -> V_149 = F_27 ;
V_33 -> V_150 = F_23 ;
V_33 ++ ;
V_33 -> type = V_151 ;
V_33 -> V_135 = V_152 ;
V_33 -> V_140 = 2 ;
V_33 -> V_142 = F_35 ;
V_33 -> V_153 = F_34 ;
V_33 -> V_143 = ( 1 << V_74 -> V_154 ) - 1 ;
V_33 -> V_145 = 1 ;
V_33 -> V_146 = & V_155 ;
V_33 ++ ;
V_33 -> type = V_156 ;
V_33 -> V_135 = V_136 | V_152 ;
V_33 -> V_140 = 8 ;
V_33 -> V_157 = F_37 ;
V_33 -> V_158 = F_38 ;
V_33 -> V_143 = 1 ;
V_33 -> V_145 = 8 ;
V_33 -> V_146 = & V_159 ;
V_33 ++ ;
V_33 -> type = V_160 ;
V_33 -> V_135 = V_136 ;
V_33 -> V_140 = 0x1000 ;
V_33 -> V_142 = F_39 ;
V_33 -> V_143 = 0xff ;
V_33 -> V_145 = 1 ;
V_33 -> V_146 = & V_161 ;
#if 0
s++;
s->type = COMEDI_SUBD_PROC;
#endif
return 0 ;
}
static int F_47 ( struct V_10 * V_2 )
{
if ( V_2 -> V_30 )
F_48 ( V_2 -> V_30 , V_2 ) ;
if ( V_14 ) {
if ( V_14 -> V_1 ) {
if ( V_14 -> V_162 )
F_49 ( V_14 -> V_1 ) ;
F_50 ( V_14 -> V_1 ) ;
}
if ( V_14 -> V_15 )
F_51 ( V_14 -> V_15 ) ;
}
return 0 ;
}
static int F_42 ( struct V_10 * V_2 , int V_126 , int V_127 )
{
int V_163 ;
int V_93 ;
struct V_1 * V_164 ;
V_164 = NULL ;
while ( ( V_164 = F_52 ( V_164 , & V_163 ) ) != NULL ) {
if ( ( V_126 == 0 && V_127 == 0 ) ||
( V_164 -> V_126 -> V_165 == V_126 &&
F_53 ( V_164 -> V_166 ) == V_127 ) ) {
break;
}
}
V_14 -> V_1 = V_164 ;
if ( V_163 >= 0 )
V_2 -> V_167 = V_168 + V_163 ;
if ( ! V_14 -> V_1 )
return 0 ;
V_93 = F_54 ( V_2 ) ;
if ( V_93 < 0 )
return V_93 ;
return 1 ;
}
static int F_54 ( struct V_10 * V_2 )
{
T_6 V_121 ;
int V_93 ;
V_93 = F_55 ( V_14 -> V_1 , L_17 ) ;
if ( V_93 < 0 )
return V_93 ;
V_121 = F_56 ( V_14 -> V_1 , 0 ) ;
V_14 -> V_162 = V_121 ;
V_14 -> V_15 = F_57 ( V_14 -> V_162 , V_169 ) ;
if ( ! V_14 -> V_15 )
return - V_170 ;
#if F_20
F_25 ( L_19 ,
( unsigned long long ) V_14 -> V_162 , V_14 -> V_15 ) ;
#endif
return 0 ;
}
static struct V_1 * F_52 ( struct V_1 * V_171 , int * V_163 )
{
int V_12 ;
for ( V_171 = F_58 ( V_172 , V_173 , V_171 ) ;
V_171 != NULL ;
V_171 = F_58 ( V_172 , V_173 , V_171 ) ) {
for ( V_12 = 0 ; V_12 < V_174 ; V_12 ++ ) {
if ( V_171 -> V_175 == V_168 [ V_12 ] . V_176 ) {
* V_163 = V_12 ;
return V_171 ;
}
}
F_25
( L_20 ,
V_171 -> V_175 ) ;
}
* V_163 = - 1 ;
return V_171 ;
}
