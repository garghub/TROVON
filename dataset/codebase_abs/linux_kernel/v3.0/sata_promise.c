static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_2 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_7 = F_3 ( V_4 , sizeof( * V_7 ) , V_9 ) ;
if ( ! V_7 )
return - V_10 ;
V_7 -> V_11 = F_4 ( V_4 , 128 , & V_7 -> V_12 , V_9 ) ;
if ( ! V_7 -> V_11 )
return - V_10 ;
V_2 -> V_13 = V_7 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_1 ( V_2 ) ;
if ( V_8 )
return V_8 ;
if ( V_2 -> V_14 & V_15 ) {
void T_1 * V_16 = V_2 -> V_17 . V_18 ;
unsigned int V_19 ;
V_19 = F_6 ( V_16 + V_20 ) ;
V_19 = ( V_19 & ~ 3 ) | 1 ;
F_7 ( V_19 , V_16 + V_20 ) ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
void T_1 * V_16 = V_2 -> V_17 . V_18 ;
T_2 V_19 ;
V_19 = F_6 ( V_16 + V_21 ) ;
V_19 |= V_22 ;
V_19 |= V_23 ;
F_9 ( V_19 >> 8 , V_16 + V_21 + 1 ) ;
F_10 ( V_16 + V_21 + 1 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
void T_1 * V_16 = V_2 -> V_17 . V_18 ;
T_3 V_19 ;
V_19 = ( T_3 ) F_6 ( V_16 + V_21 ) ;
V_19 &= 0x7F ;
V_19 |= V_24 ;
F_9 ( V_19 , V_16 + V_21 ) ;
F_6 ( V_16 + V_21 ) ;
F_12 ( 100 ) ;
V_19 &= ~ V_24 ;
F_9 ( V_19 , V_16 + V_21 ) ;
F_6 ( V_16 + V_21 ) ;
F_8 ( V_2 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
void T_1 * V_16 = V_2 -> V_17 . V_18 ;
unsigned int V_25 ;
T_2 V_19 ;
for ( V_25 = 0 ; V_25 < 100 ; ++ V_25 ) {
F_7 ( 0 , V_16 + V_26 ) ;
V_19 = F_6 ( V_16 + V_27 ) ;
if ( ( V_19 & 0xF ) != 1 )
break;
F_12 ( 100 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
void T_1 * V_16 = V_2 -> V_17 . V_18 ;
F_7 ( 0xffffffff , V_16 + V_28 ) ;
F_7 ( 0xffff0000 , V_16 + V_29 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
void T_1 * V_30 = V_2 -> V_17 . V_31 + V_32 ;
unsigned int V_25 ;
T_2 V_19 ;
if ( V_2 -> V_14 & V_15 )
F_13 ( V_2 ) ;
V_19 = F_6 ( V_30 ) ;
V_19 |= V_33 ;
F_7 ( V_19 , V_30 ) ;
for ( V_25 = 11 ; V_25 > 0 ; V_25 -- ) {
V_19 = F_6 ( V_30 ) ;
if ( V_19 & V_33 )
break;
F_12 ( 100 ) ;
V_19 |= V_33 ;
F_7 ( V_19 , V_30 ) ;
}
V_19 &= ~ V_33 ;
F_7 ( V_19 , V_30 ) ;
F_6 ( V_30 ) ;
if ( F_16 ( & V_2 -> V_34 ) && ( V_2 -> V_14 & V_15 ) ) {
F_11 ( V_2 ) ;
F_14 ( V_2 ) ;
}
}
static int F_17 ( struct V_1 * V_2 )
{
T_3 V_19 ;
void T_1 * V_35 = V_2 -> V_17 . V_31 ;
V_19 = F_10 ( V_35 + V_32 + 3 ) ;
if ( V_19 & 0x01 )
return V_36 ;
return V_37 ;
}
static int F_18 ( struct V_1 * V_2 )
{
return V_38 ;
}
static int F_19 ( struct V_39 * V_34 ,
unsigned int V_40 , T_2 * V_41 )
{
if ( V_40 > V_42 )
return - V_43 ;
* V_41 = F_6 ( V_34 -> V_2 -> V_17 . V_18 + ( V_40 * 4 ) ) ;
return 0 ;
}
static int F_20 ( struct V_39 * V_34 ,
unsigned int V_40 , T_2 V_41 )
{
if ( V_40 > V_42 )
return - V_43 ;
F_7 ( V_41 , V_34 -> V_2 -> V_17 . V_18 + ( V_40 * 4 ) ) ;
return 0 ;
}
static void F_21 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
T_4 V_46 = V_2 -> V_47 ;
unsigned int V_48 = V_45 -> V_4 -> V_48 ;
T_3 * V_49 = V_45 -> V_49 ;
struct V_6 * V_7 = V_2 -> V_13 ;
T_3 * V_50 = V_7 -> V_11 ;
T_5 * V_51 = ( T_5 * ) V_50 ;
unsigned int V_52 , V_53 ;
switch ( V_45 -> V_54 . V_55 ) {
case V_56 :
if ( ! ( V_45 -> V_54 . V_14 & V_57 ) )
V_51 [ 0 ] = F_22 ( V_58 ) ;
else
V_51 [ 0 ] = 0 ;
break;
case V_59 :
V_51 [ 0 ] = F_22 ( V_60 ) ;
break;
default:
F_23 () ;
break;
}
V_51 [ 1 ] = F_22 ( V_46 ) ;
V_51 [ 2 ] = 0 ;
if ( F_16 ( & V_2 -> V_34 ) )
V_52 = V_61 ;
else
V_52 = V_45 -> V_54 . V_3 ;
V_50 [ 12 ] = ( 1 << 5 ) | V_62 ;
V_50 [ 13 ] = V_52 ;
V_50 [ 14 ] = ( 1 << 5 ) | V_62 | V_63 ;
V_50 [ 15 ] = V_52 ;
V_50 [ 16 ] = ( 1 << 5 ) | V_64 ;
V_50 [ 17 ] = V_45 -> V_54 . V_65 ;
V_50 [ 18 ] = ( 1 << 5 ) | V_66 ;
V_50 [ 19 ] = V_45 -> V_54 . V_67 ;
if ( V_45 -> V_54 . V_55 != V_56 )
V_53 = V_68 ;
else
V_53 = V_69 ;
V_50 [ 20 ] = ( 1 << 5 ) | V_70 ;
V_50 [ 21 ] = V_53 ;
V_50 [ 22 ] = ( 1 << 5 ) | V_71 ;
V_50 [ 23 ] = V_45 -> V_54 . V_72 ;
V_50 [ 24 ] = ( 1 << 5 ) | V_73 ;
V_50 [ 25 ] = V_45 -> V_54 . V_74 ;
V_50 [ 26 ] = ( 1 << 5 ) | V_75 ;
V_50 [ 27 ] = V_45 -> V_54 . V_76 ;
V_50 [ 28 ] = ( 1 << 5 ) | V_62 | V_77 ;
V_50 [ 29 ] = V_52 ;
F_24 ( V_48 & ~ 0x1E ) ;
V_50 [ 30 ] = ( ( ( V_48 >> 1 ) & 7 ) << 5 ) | V_78 | V_79 ;
memcpy ( V_50 + 31 , V_49 , V_48 ) ;
}
static void F_25 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
struct V_80 * V_81 = V_2 -> V_82 ;
struct V_83 * V_84 ;
const T_2 V_85 = 41 * 4 ;
unsigned int V_86 , V_87 ;
T_2 V_88 ;
if ( ! ( V_45 -> V_14 & V_89 ) )
return;
V_87 = 0 ;
F_26 (qc->sg, sg, qc->n_elem, si) {
T_2 V_90 , V_91 ;
T_2 V_92 ;
V_90 = ( T_2 ) F_27 ( V_84 ) ;
V_92 = F_28 ( V_84 ) ;
while ( V_92 ) {
V_91 = V_90 & 0xffff ;
V_88 = V_92 ;
if ( ( V_91 + V_92 ) > 0x10000 )
V_88 = 0x10000 - V_91 ;
V_81 [ V_87 ] . V_90 = F_22 ( V_90 ) ;
V_81 [ V_87 ] . V_93 = F_22 ( V_88 & 0xffff ) ;
F_29 ( L_1 , V_87 , V_90 , V_88 ) ;
V_87 ++ ;
V_92 -= V_88 ;
V_90 += V_88 ;
}
}
V_88 = F_30 ( V_81 [ V_87 - 1 ] . V_93 ) ;
if ( V_88 > V_85 ) {
T_2 V_90 ;
F_29 ( L_2 ) ;
V_90 = F_30 ( V_81 [ V_87 - 1 ] . V_90 ) ;
V_81 [ V_87 - 1 ] . V_93 = F_22 ( V_88 - V_85 ) ;
F_29 ( L_1 , V_87 - 1 , V_90 , V_85 ) ;
V_90 = V_90 + V_88 - V_85 ;
V_88 = V_85 ;
V_81 [ V_87 ] . V_90 = F_22 ( V_90 ) ;
V_81 [ V_87 ] . V_93 = F_22 ( V_88 ) ;
F_29 ( L_1 , V_87 , V_90 , V_88 ) ;
V_87 ++ ;
}
V_81 [ V_87 - 1 ] . V_93 |= F_22 ( V_94 ) ;
}
static void F_31 ( struct V_44 * V_45 )
{
struct V_6 * V_7 = V_45 -> V_2 -> V_13 ;
unsigned int V_25 ;
F_29 ( L_3 ) ;
switch ( V_45 -> V_54 . V_55 ) {
case V_95 :
F_25 ( V_45 ) ;
case V_96 :
V_25 = F_32 ( & V_45 -> V_54 , V_45 -> V_2 -> V_47 ,
V_45 -> V_4 -> V_97 , V_7 -> V_11 ) ;
if ( V_45 -> V_54 . V_14 & V_98 )
V_25 = F_33 ( & V_45 -> V_54 , V_7 -> V_11 , V_25 ) ;
else
V_25 = F_34 ( & V_45 -> V_54 , V_7 -> V_11 , V_25 ) ;
F_35 ( & V_45 -> V_54 , V_7 -> V_11 , V_25 ) ;
break;
case V_99 :
F_25 ( V_45 ) ;
break;
case V_56 :
F_25 ( V_45 ) ;
case V_59 :
F_21 ( V_45 ) ;
break;
default:
break;
}
}
static int F_36 ( unsigned long V_14 )
{
const unsigned long V_100 = V_15 | V_101 ;
return ( V_14 & V_100 ) == V_100 ;
}
static unsigned int F_37 ( unsigned int V_102 ,
int V_103 )
{
static const unsigned char V_104 [ 4 ] = { 3 , 1 , 0 , 2 } ;
return V_103 ? V_104 [ V_102 ] : V_102 ;
}
static unsigned int F_38 ( const struct V_1 * V_2 )
{
return ( V_2 -> V_14 & V_101 ) ? 4 : 2 ;
}
static unsigned int F_39 ( const struct V_1 * V_2 )
{
const struct V_105 * V_5 = V_2 -> V_5 ;
unsigned int V_106 = F_38 ( V_2 ) ;
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_106 && V_5 -> V_107 [ V_25 ] != V_2 ; ++ V_25 )
;
F_24 ( V_25 >= V_106 ) ;
return F_37 ( V_25 , F_36 ( V_2 -> V_14 ) ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
void T_1 * V_35 = V_2 -> V_17 . V_31 ;
T_2 V_19 ;
V_19 = F_6 ( V_35 + V_32 ) ;
V_19 |= V_108 ;
V_19 &= ~ V_109 ;
F_7 ( V_19 , V_35 + V_32 ) ;
F_6 ( V_35 + V_32 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_105 * V_5 = V_2 -> V_5 ;
void T_1 * V_110 = V_5 -> V_111 [ V_112 ] ;
unsigned int V_113 = V_114 ;
unsigned int V_115 = F_39 ( V_2 ) ;
T_2 V_116 ;
V_116 = F_6 ( V_110 + V_113 ) ;
V_116 |= 0x11 << ( V_115 + 16 ) ;
F_7 ( V_116 , V_110 + V_113 ) ;
F_6 ( V_110 + V_113 ) ;
F_40 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
void T_1 * V_35 = V_2 -> V_17 . V_31 ;
T_2 V_19 ;
F_6 ( V_35 + V_117 ) ;
V_19 = F_6 ( V_35 + V_32 ) ;
V_19 &= ~ V_108 ;
F_7 ( V_19 , V_35 + V_32 ) ;
F_6 ( V_35 + V_32 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_105 * V_5 = V_2 -> V_5 ;
void T_1 * V_110 = V_5 -> V_111 [ V_112 ] ;
unsigned int V_113 = V_114 ;
unsigned int V_115 = F_39 ( V_2 ) ;
T_2 V_116 ;
F_42 ( V_2 ) ;
V_116 = F_6 ( V_110 + V_113 ) ;
V_116 |= 0x11 << V_115 ;
V_116 &= ~ ( 0x11 << ( V_115 + 16 ) ) ;
F_7 ( V_116 , V_110 + V_113 ) ;
F_6 ( V_110 + V_113 ) ;
}
static int F_44 ( struct V_39 * V_34 , unsigned int * V_118 ,
unsigned long V_119 )
{
F_15 ( V_34 -> V_2 ) ;
return F_45 ( V_34 , V_118 , V_119 ) ;
}
static unsigned int F_46 ( const struct V_1 * V_2 )
{
void T_1 * V_35 = V_2 -> V_17 . V_31 ;
void T_1 * V_110 = V_2 -> V_5 -> V_111 [ V_112 ] ;
return ( V_35 - V_110 - 0x200 ) / 0x80 ;
}
static void F_47 ( struct V_1 * V_2 )
{
void T_1 * V_110 = V_2 -> V_5 -> V_111 [ V_112 ] ;
void T_1 * V_120 = V_110 + V_121 + 1 ;
unsigned int V_115 = F_46 ( V_2 ) ;
T_3 V_19 ;
F_48 ( & V_2 -> V_5 -> V_122 ) ;
V_19 = F_10 ( V_120 ) ;
V_19 &= ~ ( 0x10 << V_115 ) ;
F_9 ( V_19 , V_120 ) ;
F_10 ( V_120 ) ;
F_12 ( 100 ) ;
V_19 |= ( 0x10 << V_115 ) ;
F_9 ( V_19 , V_120 ) ;
F_10 ( V_120 ) ;
F_49 ( & V_2 -> V_5 -> V_122 ) ;
}
static int F_50 ( struct V_39 * V_34 , unsigned int * V_118 ,
unsigned long V_119 )
{
if ( V_34 -> V_2 -> V_14 & V_15 )
F_13 ( V_34 -> V_2 ) ;
F_47 ( V_34 -> V_2 ) ;
F_15 ( V_34 -> V_2 ) ;
return F_51 ( V_34 , V_118 , V_119 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_123 & V_124 ) )
F_15 ( V_2 ) ;
F_53 ( V_2 ) ;
}
static void F_54 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
if ( V_45 -> V_14 & V_125 )
F_15 ( V_2 ) ;
}
static void F_55 ( struct V_1 * V_2 , struct V_44 * V_45 ,
T_2 V_126 , T_2 V_127 )
{
struct V_128 * V_129 = & V_2 -> V_34 . V_130 ;
unsigned int V_131 = 0 ;
F_56 ( V_129 ) ;
F_57 ( V_129 , L_4 , V_126 ) ;
V_126 &= V_127 ;
if ( V_126 & V_132 )
V_131 |= V_133 ;
if ( V_126 & ( V_134 | V_135 ) )
V_131 |= V_136 ;
if ( V_126 & ( V_137 | V_138 ) )
V_131 |= V_139 ;
if ( V_126 & ( V_140 | V_141 | V_142 | V_143
| V_144 | V_145 ) )
V_131 |= V_146 ;
if ( F_16 ( & V_2 -> V_34 ) ) {
T_2 V_147 ;
F_19 ( & V_2 -> V_34 , V_148 , & V_147 ) ;
V_129 -> V_147 |= V_147 ;
}
V_45 -> V_127 |= V_131 ;
F_15 ( V_2 ) ;
F_58 ( V_2 ) ;
}
static unsigned int F_59 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
unsigned int V_149 = 0 ;
void T_1 * V_35 = V_2 -> V_17 . V_31 ;
T_2 V_126 , V_127 ;
V_127 = V_150 ;
if ( V_2 -> V_14 & V_15 )
V_127 &= ~ V_151 ;
else
V_127 &= ~ V_152 ;
V_126 = F_6 ( V_35 + V_153 ) ;
if ( F_60 ( V_126 & V_127 ) ) {
F_55 ( V_2 , V_45 , V_126 , V_127 ) ;
return 1 ;
}
switch ( V_45 -> V_54 . V_55 ) {
case V_95 :
case V_96 :
case V_56 :
case V_59 :
V_45 -> V_127 |= V_131 ( F_61 ( V_2 ) ) ;
F_62 ( V_45 ) ;
V_149 = 1 ;
break;
default:
V_2 -> V_154 . V_155 ++ ;
break;
}
return V_149 ;
}
static void F_63 ( struct V_1 * V_2 )
{
void T_1 * V_35 = V_2 -> V_17 . V_31 ;
F_6 ( V_35 + V_117 ) ;
}
static T_6 F_64 ( int V_156 , void * V_157 )
{
struct V_105 * V_5 = V_157 ;
struct V_1 * V_2 ;
T_2 V_100 = 0 ;
unsigned int V_25 , V_19 ;
unsigned int V_149 = 0 ;
void T_1 * V_110 ;
unsigned int V_113 , V_115 ;
T_2 V_116 ;
int V_103 ;
F_29 ( L_3 ) ;
if ( ! V_5 || ! V_5 -> V_111 [ V_112 ] ) {
F_29 ( L_5 ) ;
return V_158 ;
}
V_110 = V_5 -> V_111 [ V_112 ] ;
F_48 ( & V_5 -> V_122 ) ;
if ( V_5 -> V_107 [ 0 ] -> V_14 & V_15 ) {
V_113 = V_114 ;
V_116 = F_6 ( V_110 + V_113 ) ;
if ( V_116 & 0xff )
F_7 ( V_116 | 0xff , V_110 + V_113 ) ;
V_116 &= 0xff ;
} else
V_116 = 0 ;
V_100 = F_6 ( V_110 + V_159 ) ;
if ( V_100 == 0xffffffff && V_116 == 0 ) {
F_29 ( L_6 ) ;
goto V_160;
}
V_100 &= 0xffff ;
if ( V_100 == 0 && V_116 == 0 ) {
F_29 ( L_7 ) ;
goto V_160;
}
F_7 ( V_100 , V_110 + V_159 ) ;
V_103 = F_36 ( V_5 -> V_107 [ 0 ] -> V_14 ) ;
for ( V_25 = 0 ; V_25 < V_5 -> V_161 ; V_25 ++ ) {
F_29 ( L_8 , V_25 ) ;
V_2 = V_5 -> V_107 [ V_25 ] ;
V_115 = F_37 ( V_25 , V_103 ) ;
V_19 = V_116 & ( 0x11 << V_115 ) ;
if ( V_19 ) {
struct V_128 * V_129 = & V_2 -> V_34 . V_130 ;
F_56 ( V_129 ) ;
F_65 ( V_129 ) ;
F_57 ( V_129 , L_9 , V_19 ) ;
F_66 ( V_2 ) ;
++ V_149 ;
continue;
}
V_19 = V_100 & ( 1 << ( V_25 + 1 ) ) ;
if ( V_19 ) {
struct V_44 * V_45 ;
V_45 = F_67 ( V_2 , V_2 -> V_34 . V_162 ) ;
if ( V_45 && ( ! ( V_45 -> V_54 . V_14 & V_163 ) ) )
V_149 += F_59 ( V_2 , V_45 ) ;
}
}
F_29 ( L_10 ) ;
V_160:
F_49 ( & V_5 -> V_122 ) ;
return F_68 ( V_149 ) ;
}
static void F_69 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
struct V_6 * V_7 = V_2 -> V_13 ;
void T_1 * V_110 = V_2 -> V_5 -> V_111 [ V_112 ] ;
void T_1 * V_35 = V_2 -> V_17 . V_31 ;
unsigned int V_102 = V_2 -> V_102 ;
T_3 V_164 = ( T_3 ) ( V_102 + 1 ) ;
F_29 ( L_11 , V_2 ) ;
F_7 ( 0x00000001 , V_110 + ( V_164 * 4 ) ) ;
F_6 ( V_110 + ( V_164 * 4 ) ) ;
V_7 -> V_11 [ 2 ] = V_164 ;
F_70 () ;
F_7 ( V_7 -> V_12 , V_35 + V_165 ) ;
F_6 ( V_35 + V_165 ) ;
}
static unsigned int F_71 ( struct V_44 * V_45 )
{
switch ( V_45 -> V_54 . V_55 ) {
case V_59 :
if ( V_45 -> V_4 -> V_14 & V_166 )
break;
case V_96 :
if ( V_45 -> V_54 . V_14 & V_163 )
break;
case V_56 :
case V_95 :
F_69 ( V_45 ) ;
return 0 ;
default:
break;
}
return F_72 ( V_45 ) ;
}
static void F_73 ( struct V_1 * V_2 , const struct V_167 * V_54 )
{
F_74 ( V_54 -> V_55 == V_95 || V_54 -> V_55 == V_56 ) ;
F_75 ( V_2 , V_54 ) ;
}
static void F_76 ( struct V_1 * V_2 ,
const struct V_167 * V_54 )
{
F_74 ( V_54 -> V_55 == V_95 || V_54 -> V_55 == V_56 ) ;
F_77 ( V_2 , V_54 ) ;
}
static int F_78 ( struct V_44 * V_45 )
{
T_3 * V_168 = V_45 -> V_168 -> V_169 ;
int V_170 = 1 ;
switch ( V_168 [ 0 ] ) {
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case 0xad :
case 0xbe :
V_170 = 0 ;
}
if ( V_168 [ 0 ] == V_172 ) {
unsigned int V_177 =
( V_168 [ 2 ] << 24 ) |
( V_168 [ 3 ] << 16 ) |
( V_168 [ 4 ] << 8 ) |
V_168 [ 5 ] ;
if ( V_177 >= 0xFFFF4FA2 )
V_170 = 1 ;
}
return V_170 ;
}
static int F_79 ( struct V_44 * V_45 )
{
return 1 ;
}
static void F_80 ( struct V_1 * V_2 ,
void T_1 * V_178 , void T_1 * V_18 )
{
V_2 -> V_17 . V_31 = V_178 ;
V_2 -> V_17 . V_179 = V_178 ;
V_2 -> V_17 . V_180 =
V_2 -> V_17 . V_181 = V_178 + 0x4 ;
V_2 -> V_17 . V_182 = V_178 + 0x8 ;
V_2 -> V_17 . V_183 = V_178 + 0xc ;
V_2 -> V_17 . V_184 = V_178 + 0x10 ;
V_2 -> V_17 . V_185 = V_178 + 0x14 ;
V_2 -> V_17 . V_186 = V_178 + 0x18 ;
V_2 -> V_17 . V_187 =
V_2 -> V_17 . V_188 = V_178 + 0x1c ;
V_2 -> V_17 . V_189 =
V_2 -> V_17 . V_190 = V_178 + 0x38 ;
V_2 -> V_17 . V_18 = V_18 ;
}
static void F_81 ( struct V_105 * V_5 )
{
void T_1 * V_110 = V_5 -> V_111 [ V_112 ] ;
int V_191 = V_5 -> V_107 [ 0 ] -> V_14 & V_15 ;
int V_113 ;
T_2 V_19 ;
if ( V_191 )
V_113 = V_114 ;
else
V_113 = V_192 ;
V_19 = F_6 ( V_110 + V_193 ) ;
V_19 |= 0x02000 ;
if ( ! V_191 )
V_19 |= 0x10000 ;
F_7 ( V_19 , V_110 + V_193 ) ;
V_19 = F_6 ( V_110 + V_113 ) ;
F_7 ( V_19 | 0xff , V_110 + V_113 ) ;
V_19 = F_6 ( V_110 + V_113 ) ;
if ( V_191 )
F_7 ( V_19 & ~ 0xff0000 , V_110 + V_113 ) ;
else
F_7 ( V_19 | 0xff0000 , V_110 + V_113 ) ;
if ( V_191 )
return;
V_19 = F_6 ( V_110 + V_194 ) ;
V_19 &= ~ 0x30000 ;
V_19 |= 0x10000 ;
F_7 ( V_19 , V_110 + V_194 ) ;
F_6 ( V_110 + V_194 ) ;
F_82 ( 10 ) ;
V_19 = F_6 ( V_110 + V_195 ) ;
V_19 &= 0xFFFFF03F ;
V_19 |= 0x00000900 ;
F_7 ( V_19 , V_110 + V_195 ) ;
}
static int F_83 ( struct V_196 * V_197 ,
const struct V_198 * V_199 )
{
static int V_200 ;
const struct V_201 * V_202 = & V_203 [ V_199 -> V_204 ] ;
const struct V_201 * V_205 [ V_206 ] ;
struct V_105 * V_5 ;
void T_1 * V_110 ;
int V_161 , V_25 , V_8 ;
int V_103 ;
if ( ! V_200 ++ )
F_84 ( V_207 , & V_197 -> V_4 , L_12 V_208 L_13 ) ;
V_8 = F_85 ( V_197 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_86 ( V_197 , 1 << V_112 , V_209 ) ;
if ( V_8 == - V_210 )
F_87 ( V_197 ) ;
if ( V_8 )
return V_8 ;
V_110 = F_88 ( V_197 ) [ V_112 ] ;
V_161 = 2 ;
if ( V_202 -> V_14 & V_101 )
V_161 = 4 ;
for ( V_25 = 0 ; V_25 < V_161 ; V_25 ++ )
V_205 [ V_25 ] = V_202 ;
if ( V_202 -> V_14 & V_211 ) {
T_3 V_19 = F_10 ( V_110 + V_193 + 1 ) ;
if ( ! ( V_19 & 0x80 ) )
V_205 [ V_161 ++ ] = V_202 + 1 ;
}
V_5 = F_89 ( & V_197 -> V_4 , V_205 , V_161 ) ;
if ( ! V_5 ) {
F_84 ( V_212 , & V_197 -> V_4 , L_14 ) ;
return - V_10 ;
}
V_5 -> V_111 = F_88 ( V_197 ) ;
V_103 = F_36 ( V_202 -> V_14 ) ;
for ( V_25 = 0 ; V_25 < V_5 -> V_161 ; V_25 ++ ) {
struct V_1 * V_2 = V_5 -> V_107 [ V_25 ] ;
unsigned int V_115 = F_37 ( V_25 , V_103 ) ;
unsigned int V_213 = 0x200 + V_115 * 0x80 ;
unsigned int V_214 = 0x400 + V_115 * 0x100 ;
F_80 ( V_2 , V_110 + V_213 , V_110 + V_214 ) ;
F_90 ( V_2 , V_112 , - 1 , L_15 ) ;
F_90 ( V_2 , V_112 , V_213 , L_16 ) ;
}
F_81 ( V_5 ) ;
V_8 = F_91 ( V_197 , V_215 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_92 ( V_197 , V_215 ) ;
if ( V_8 )
return V_8 ;
F_93 ( V_197 ) ;
return F_94 ( V_5 , V_197 -> V_156 , F_64 , V_216 ,
& V_217 ) ;
}
static int T_7 F_95 ( void )
{
return F_96 ( & V_218 ) ;
}
static void T_8 F_97 ( void )
{
F_98 ( & V_218 ) ;
}
