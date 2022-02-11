static int F_1 ( unsigned V_1 , unsigned V_2 , unsigned V_3 ,
unsigned V_4 , unsigned V_5 , struct V_6 * V_7 ) {
T_1 V_8 ;
#define F_2 (container_of(info, struct matroxfb_dh_fb_info, fbcon))
if ( V_1 >= 16 )
return 1 ;
if ( F_2 -> V_9 . V_10 . V_11 ) {
V_2 = V_3 = V_4 = ( V_2 * 77 + V_3 * 151 + V_4 * 28 ) >> 8 ;
}
V_2 = F_3 ( V_2 , F_2 -> V_9 . V_10 . V_2 . V_12 ) ;
V_3 = F_3 ( V_3 , F_2 -> V_9 . V_10 . V_3 . V_12 ) ;
V_4 = F_3 ( V_4 , F_2 -> V_9 . V_10 . V_4 . V_12 ) ;
V_5 = F_3 ( V_5 , F_2 -> V_9 . V_10 . V_5 . V_12 ) ;
V_8 = ( V_2 << F_2 -> V_9 . V_10 . V_2 . V_13 ) |
( V_3 << F_2 -> V_9 . V_10 . V_3 . V_13 ) |
( V_4 << F_2 -> V_9 . V_10 . V_4 . V_13 ) |
( V_5 << F_2 -> V_9 . V_10 . V_5 . V_13 ) ;
switch ( F_2 -> V_9 . V_10 . V_14 ) {
case 16 :
F_2 -> V_15 [ V_1 ] = V_8 | ( V_8 << 16 ) ;
break;
case 32 :
F_2 -> V_15 [ V_1 ] = V_8 ;
break;
}
return 0 ;
#undef F_2
}
static void F_4 ( struct V_16 * F_2 ,
struct V_17 * V_18 ,
int V_19 ,
unsigned int V_20 ) {
T_1 V_21 ;
T_1 V_22 ;
struct V_23 * V_24 = F_2 -> V_25 ;
switch ( V_19 ) {
case 15 :
V_21 = 0x00200000 ;
break;
case 16 :
V_21 = 0x00400000 ;
break;
default:
V_21 = 0x00800000 ;
break;
}
V_21 |= 0x00000001 ;
V_22 = 0 ;
if ( V_24 -> V_26 [ 1 ] . V_27 == V_28 ) {
if ( V_24 -> V_29 . V_30 ) {
V_21 |= 0x00000006 ;
if ( V_24 -> V_26 [ 1 ] . V_19 != V_31 ) {
V_21 |= 0xC0001000 ;
}
} else {
V_21 |= 0x00000002 ;
V_21 |= 0xC0000000 ;
}
} else if ( V_24 -> V_26 [ 0 ] . V_27 == V_28 ) {
V_21 |= 0x00000004 ;
}
if ( V_24 -> V_26 [ 0 ] . V_27 == V_28 ) {
V_21 |= 0x00100000 ;
}
if ( V_18 -> V_32 ) {
V_21 |= 0x02000000 ;
V_18 -> V_33 >>= 1 ;
V_18 -> V_34 >>= 1 ;
V_18 -> V_35 >>= 1 ;
V_18 -> V_36 >>= 1 ;
}
if ( ( V_18 -> V_37 & 7 ) == 2 ) {
V_22 |= 0x00000010 ;
V_18 -> V_37 &= ~ 7 ;
}
V_21 |= 0x10000000 ;
F_5 ( 0x3C14 , ( ( V_18 -> V_38 - 8 ) << 16 ) | ( V_18 -> V_37 - 8 ) ) ;
F_5 ( 0x3C18 , ( ( V_18 -> V_39 - 8 ) << 16 ) | ( V_18 -> V_40 - 8 ) ) ;
F_5 ( 0x3C1C , ( ( V_18 -> V_33 - 1 ) << 16 ) | ( V_18 -> V_36 - 1 ) ) ;
F_5 ( 0x3C20 , ( ( V_18 -> V_35 - 1 ) << 16 ) | ( V_18 -> V_34 - 1 ) ) ;
F_5 ( 0x3C24 , ( ( V_18 -> V_34 ) << 16 ) | ( V_18 -> V_40 ) ) ;
{
T_1 V_41 = F_2 -> V_9 . V_10 . V_42 * ( F_2 -> V_9 . V_10 . V_14 >> 3 ) ;
if ( V_21 & 0x02000000 ) {
F_5 ( 0x3C2C , V_20 ) ;
F_5 ( 0x3C28 , V_20 + V_41 ) ;
V_41 <<= 1 ;
F_2 -> V_32 = 1 ;
} else {
F_5 ( 0x3C28 , V_20 ) ;
F_2 -> V_32 = 0 ;
}
F_5 ( 0x3C40 , V_41 ) ;
}
F_5 ( 0x3C4C , V_22 ) ;
if ( V_21 & 0x02000000 ) {
int V_43 ;
F_5 ( 0x3C10 , V_21 & ~ 0x02000000 ) ;
for ( V_43 = 0 ; V_43 < 2 ; V_43 ++ ) {
unsigned int V_44 ;
unsigned int V_45 = 0 ;
while ( ( V_44 = F_6 ( 0x3C48 ) & 0xFFF ) >= V_45 ) {
V_45 = V_44 ;
}
}
}
F_5 ( 0x3C10 , V_21 ) ;
V_24 -> V_46 . V_47 . V_48 = V_21 ;
V_21 = V_18 -> V_33 << 16 ;
if ( V_18 -> V_49 & V_50 )
V_21 |= 0x00000100 ;
if ( V_18 -> V_49 & V_51 )
V_21 |= 0x00000200 ;
F_5 ( 0x3C44 , V_21 ) ;
}
static void F_7 ( struct V_16 * F_2 ) {
struct V_23 * V_24 = F_2 -> V_25 ;
F_5 ( 0x3C10 , 0x00000004 ) ;
V_24 -> V_46 . V_47 . V_48 = 0x00000004 ;
}
static void F_8 ( struct V_16 * F_2 ,
struct V_52 * V_10 ) {
unsigned int V_20 ;
unsigned int V_41 ;
unsigned int V_53 ;
struct V_23 * V_24 = F_2 -> V_25 ;
F_2 -> V_9 . V_10 . V_54 = V_10 -> V_54 ;
F_2 -> V_9 . V_10 . V_55 = V_10 -> V_55 ;
V_53 = F_2 -> V_9 . V_10 . V_14 >> 3 ;
V_41 = F_2 -> V_9 . V_10 . V_42 * V_53 ;
V_20 = F_2 -> V_9 . V_10 . V_55 * V_41 + F_2 -> V_9 . V_10 . V_54 * V_53 ;
V_20 += F_2 -> V_56 . V_57 ;
if ( F_2 -> V_32 ) {
F_5 ( 0x3C2C , V_20 ) ;
F_5 ( 0x3C28 , V_20 + V_41 ) ;
} else {
F_5 ( 0x3C28 , V_20 ) ;
}
}
static int F_9 ( struct V_16 * F_2 ,
struct V_52 * V_10 ,
int * V_58 ,
int * V_59 ,
int * V_19 ) {
unsigned int V_60 ;
unsigned int V_61 ;
unsigned int V_62 ;
switch ( V_10 -> V_14 ) {
case 16 : V_60 = 0x1F ;
break;
case 32 : V_60 = 0x0F ;
break;
default: return - V_63 ;
}
V_62 = F_2 -> V_56 . V_64 ;
if ( V_10 -> V_65 < V_10 -> V_66 )
V_10 -> V_65 = V_10 -> V_66 ;
if ( V_10 -> V_42 < V_10 -> V_67 )
V_10 -> V_42 = V_10 -> V_67 ;
V_10 -> V_42 = ( V_10 -> V_42 + V_60 ) & ~ V_60 ;
if ( V_10 -> V_65 > 32767 )
return - V_63 ;
V_61 = V_10 -> V_42 * V_10 -> V_65 * ( V_10 -> V_14 >> 3 ) ;
if ( V_61 > V_62 )
return - V_63 ;
if ( V_10 -> V_54 + V_10 -> V_67 > V_10 -> V_42 )
V_10 -> V_54 = V_10 -> V_42 - V_10 -> V_67 ;
if ( V_10 -> V_55 + V_10 -> V_66 > V_10 -> V_65 )
V_10 -> V_55 = V_10 -> V_65 - V_10 -> V_66 ;
V_10 -> V_67 &= ~ 7 ;
V_10 -> V_68 &= ~ 7 ;
V_10 -> V_69 &= ~ 7 ;
V_10 -> V_70 &= ~ 7 ;
* V_19 = V_10 -> V_14 ;
if ( V_10 -> V_14 == 16 ) {
if ( V_10 -> V_3 . V_12 == 5 ) {
V_10 -> V_2 . V_13 = 10 ;
V_10 -> V_2 . V_12 = 5 ;
V_10 -> V_3 . V_13 = 5 ;
V_10 -> V_3 . V_12 = 5 ;
V_10 -> V_4 . V_13 = 0 ;
V_10 -> V_4 . V_12 = 5 ;
V_10 -> V_5 . V_13 = 15 ;
V_10 -> V_5 . V_12 = 1 ;
* V_19 = 15 ;
} else {
V_10 -> V_2 . V_13 = 11 ;
V_10 -> V_2 . V_12 = 5 ;
V_10 -> V_3 . V_13 = 5 ;
V_10 -> V_3 . V_12 = 6 ;
V_10 -> V_4 . V_13 = 0 ;
V_10 -> V_4 . V_12 = 5 ;
V_10 -> V_5 . V_13 = 0 ;
V_10 -> V_5 . V_12 = 0 ;
}
} else {
V_10 -> V_2 . V_13 = 16 ;
V_10 -> V_2 . V_12 = 8 ;
V_10 -> V_3 . V_13 = 8 ;
V_10 -> V_3 . V_12 = 8 ;
V_10 -> V_4 . V_13 = 0 ;
V_10 -> V_4 . V_12 = 8 ;
V_10 -> V_5 . V_13 = 24 ;
V_10 -> V_5 . V_12 = 8 ;
}
* V_58 = V_71 ;
* V_59 = 16 ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 , int V_72 ) {
#define F_2 (container_of(info, struct matroxfb_dh_fb_info, fbcon))
struct V_23 * V_24 = F_2 -> V_25 ;
if ( V_24 ) {
int V_73 ;
if ( V_24 -> V_74 ) {
return - V_75 ;
}
V_73 = V_24 -> V_76 . V_77 ( & V_24 -> V_9 , V_72 ) ;
if ( V_73 ) {
return V_73 ;
}
}
return 0 ;
#undef F_2
}
static int F_11 ( struct V_6 * V_7 , int V_72 ) {
#define F_2 (container_of(info, struct matroxfb_dh_fb_info, fbcon))
int V_73 = 0 ;
struct V_23 * V_24 = F_2 -> V_25 ;
if ( V_24 ) {
V_73 = V_24 -> V_76 . V_78 ( & V_24 -> V_9 , V_72 ) ;
}
return V_73 ;
#undef F_2
}
static void F_12 ( struct V_16 * F_2 )
{
struct V_79 * V_80 = & F_2 -> V_9 . V_80 ;
strcpy ( V_80 -> V_81 , L_1 ) ;
V_80 -> V_82 = F_2 -> V_56 . V_83 ;
V_80 -> V_84 = F_2 -> V_56 . V_64 ;
V_80 -> V_85 = 1 ;
V_80 -> V_86 = 0 ;
V_80 -> V_87 = 8 ;
V_80 -> V_88 = F_2 -> V_89 . V_83 ;
V_80 -> V_90 = F_2 -> V_89 . V_91 ;
V_80 -> V_92 = 0 ;
}
static int F_13 ( struct V_52 * V_10 , struct V_6 * V_7 ) {
#define F_2 (container_of(info, struct matroxfb_dh_fb_info, fbcon))
int V_58 ;
int V_93 ;
int V_19 ;
return F_9 ( F_2 , V_10 , & V_58 , & V_93 , & V_19 ) ;
#undef F_2
}
static int F_14 ( struct V_6 * V_7 ) {
#define F_2 (container_of(info, struct matroxfb_dh_fb_info, fbcon))
int V_58 ;
int V_93 ;
int V_19 ;
int V_73 ;
struct V_52 * V_10 = & V_7 -> V_10 ;
struct V_23 * V_24 = F_2 -> V_25 ;
if ( ( V_73 = F_9 ( F_2 , V_10 , & V_58 , & V_93 , & V_19 ) ) != 0 )
return V_73 ;
{
F_2 -> V_9 . V_94 = F_15 ( F_2 -> V_56 . V_95 ) ;
F_2 -> V_9 . V_80 . V_58 = V_58 ;
F_2 -> V_9 . V_80 . type = V_96 ;
F_2 -> V_9 . V_80 . V_97 = 0 ;
F_2 -> V_9 . V_80 . V_98 = ( V_10 -> V_42 * V_10 -> V_14 ) >> 3 ;
}
{
struct V_17 V_18 ;
unsigned int V_20 ;
int V_99 ;
int V_100 ;
F_16 ( & F_2 -> V_9 . V_10 , & V_18 ) ;
V_18 . V_101 = V_28 ;
V_18 . V_102 = 34 ;
V_20 = ( F_2 -> V_9 . V_10 . V_55 * F_2 -> V_9 . V_10 . V_42 + F_2 -> V_9 . V_10 . V_54 ) * F_2 -> V_9 . V_10 . V_14 >> 3 ;
V_20 += F_2 -> V_56 . V_57 ;
V_100 = 0 ;
F_17 ( & V_24 -> V_103 . V_104 ) ;
for ( V_99 = 0 ; V_99 < V_105 ; V_99 ++ ) {
if ( V_24 -> V_26 [ V_99 ] . V_27 == V_28 ) {
V_100 ++ ;
if ( V_24 -> V_26 [ V_99 ] . V_106 -> V_107 ) {
V_24 -> V_26 [ V_99 ] . V_106 -> V_107 ( V_24 -> V_26 [ V_99 ] . V_108 , & V_18 ) ;
}
}
}
V_24 -> V_47 . V_109 = V_18 . V_109 ;
V_24 -> V_47 . V_110 = V_18 . V_110 ;
F_18 ( & V_24 -> V_103 . V_104 ) ;
if ( V_100 ) {
F_4 ( F_2 , & V_18 , V_19 , V_20 ) ;
} else {
F_7 ( F_2 ) ;
}
F_19 ( V_24 ) ;
F_20 ( V_24 ) ;
F_17 ( & V_24 -> V_103 . V_104 ) ;
for ( V_99 = 0 ; V_99 < V_105 ; V_99 ++ ) {
if ( V_24 -> V_26 [ V_99 ] . V_27 == V_28 &&
V_24 -> V_26 [ V_99 ] . V_106 -> V_111 ) {
V_24 -> V_26 [ V_99 ] . V_106 -> V_111 ( V_24 -> V_26 [ V_99 ] . V_108 ) ;
}
}
for ( V_99 = 0 ; V_99 < V_105 ; V_99 ++ ) {
if ( V_24 -> V_26 [ V_99 ] . V_27 == V_28 &&
V_24 -> V_26 [ V_99 ] . V_106 -> V_112 ) {
V_24 -> V_26 [ V_99 ] . V_106 -> V_112 ( V_24 -> V_26 [ V_99 ] . V_108 ) ;
}
}
F_18 ( & V_24 -> V_103 . V_104 ) ;
}
F_2 -> V_113 = 1 ;
return 0 ;
#undef F_2
}
static int F_21 ( struct V_52 * V_10 , struct V_6 * V_7 ) {
#define F_2 (container_of(info, struct matroxfb_dh_fb_info, fbcon))
F_8 ( F_2 , V_10 ) ;
return 0 ;
#undef F_2
}
static int F_22 ( const struct V_16 * F_2 , struct V_114 * V_115 ) {
struct V_23 * V_24 = F_2 -> V_25 ;
F_23 ( V_24 , 0 ) ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
V_115 -> V_116 = V_117 | V_118 ;
V_115 -> V_119 = F_6 ( 0x3C48 ) & 0x000007FF ;
if ( V_115 -> V_119 >= F_2 -> V_9 . V_10 . V_66 )
V_115 -> V_116 |= V_120 ;
if ( F_24 ( 0 , & V_24 -> V_121 ) ) {
V_115 -> V_116 |= V_122 ;
V_115 -> V_123 = V_24 -> V_47 . V_124 . V_100 ;
}
return 0 ;
}
static int F_25 ( struct V_6 * V_7 ,
unsigned int V_125 ,
unsigned long V_126 )
{
#define F_2 (container_of(info, struct matroxfb_dh_fb_info, fbcon))
struct V_23 * V_24 = F_2 -> V_25 ;
F_26 (__func__)
switch ( V_125 ) {
case V_127 :
{
struct V_114 V_115 ;
int V_73 ;
V_73 = F_22 ( F_2 , & V_115 ) ;
if ( V_73 )
return V_73 ;
if ( F_27 ( ( void V_128 * ) V_126 , & V_115 , sizeof( V_115 ) ) )
return - V_129 ;
return 0 ;
}
case V_130 :
{
T_1 V_131 ;
if ( F_28 ( V_131 , ( T_1 V_128 * ) V_126 ) )
return - V_129 ;
if ( V_131 != 0 )
return - V_132 ;
return F_29 ( V_24 , 1 ) ;
}
case V_133 :
case V_134 :
case V_135 :
{
return V_24 -> V_9 . V_76 -> V_136 ( & V_24 -> V_9 , V_125 , V_126 ) ;
}
case V_137 :
{
T_1 V_21 ;
int V_99 ;
int V_138 ;
if ( F_28 ( V_21 , ( T_1 V_128 * ) V_126 ) )
return - V_129 ;
for ( V_99 = 0 ; V_99 < 32 ; V_99 ++ ) {
if ( V_21 & ( 1 << V_99 ) ) {
if ( V_99 >= V_105 )
return - V_75 ;
if ( ! V_24 -> V_26 [ V_99 ] . V_106 )
return - V_75 ;
switch ( V_24 -> V_26 [ V_99 ] . V_27 ) {
case V_139 :
case V_28 :
break;
default:
return - V_140 ;
}
}
}
if ( V_24 -> V_29 . V_141 ) {
if ( V_21 & V_142 )
return - V_63 ;
if ( ( V_24 -> V_26 [ 2 ] . V_27 == V_143 ) && V_21 )
return - V_140 ;
}
V_138 = 0 ;
for ( V_99 = 0 ; V_99 < V_105 ; V_99 ++ ) {
if ( V_21 & ( 1 << V_99 ) ) {
if ( V_24 -> V_26 [ V_99 ] . V_27 != V_28 ) {
V_138 = 1 ;
V_24 -> V_26 [ V_99 ] . V_27 = V_28 ;
}
} else if ( V_24 -> V_26 [ V_99 ] . V_27 == V_28 ) {
V_138 = 1 ;
V_24 -> V_26 [ V_99 ] . V_27 = V_139 ;
}
}
if ( ! V_138 )
return 0 ;
F_14 ( V_7 ) ;
return 0 ;
}
case V_144 :
{
T_1 V_145 = 0 ;
int V_99 ;
for ( V_99 = 0 ; V_99 < V_105 ; V_99 ++ ) {
if ( V_24 -> V_26 [ V_99 ] . V_27 == V_28 ) {
V_145 |= 1 << V_99 ;
}
}
if ( F_30 ( V_145 , ( T_1 V_128 * ) V_126 ) )
return - V_129 ;
return 0 ;
}
case V_146 :
{
T_1 V_21 = 0 ;
int V_99 ;
for ( V_99 = 0 ; V_99 < V_105 ; V_99 ++ ) {
if ( V_24 -> V_26 [ V_99 ] . V_106 ) {
switch ( V_24 -> V_26 [ V_99 ] . V_27 ) {
case V_139 :
case V_28 :
V_21 |= 1 << V_99 ;
break;
}
}
}
if ( V_24 -> V_29 . V_141 ) {
V_21 &= ~ V_142 ;
if ( V_24 -> V_26 [ 2 ] . V_27 == V_143 ) {
V_21 = 0 ;
}
}
if ( F_30 ( V_21 , ( T_1 V_128 * ) V_126 ) )
return - V_129 ;
return 0 ;
}
}
return - V_147 ;
#undef F_2
}
static int F_31 ( int V_148 , struct V_6 * V_7 ) {
#define F_2 (container_of(info, struct matroxfb_dh_fb_info, fbcon))
switch ( V_148 ) {
case 1 :
case 2 :
case 3 :
case 4 :
default: ;
}
return 0 ;
#undef F_2
}
static int F_32 ( const struct V_23 * V_24 ,
struct V_16 * F_2 )
{
#define V_24 (m2info->primary_dev)
void * V_149 ;
F_2 -> V_9 . V_76 = & V_150 ;
F_2 -> V_9 . V_116 = V_151 ;
F_2 -> V_9 . V_116 |= V_152 |
V_153 ;
F_2 -> V_9 . V_154 = F_2 -> V_15 ;
F_33 ( & F_2 -> V_9 . V_15 , 256 , 1 ) ;
if ( V_155 < 64 )
V_155 *= 1024 ;
if ( V_155 < 64 * 1024 )
V_155 *= 1024 ;
V_155 &= ~ 0x00000FFF ;
if ( V_24 -> V_56 . V_64 + V_155 <= V_24 -> V_56 . V_91 )
F_2 -> V_56 . V_57 = V_24 -> V_56 . V_91 - V_155 ;
else if ( V_24 -> V_56 . V_91 < V_155 ) {
return - V_156 ;
} else {
F_2 -> V_56 . V_157 = V_155 ;
V_24 -> V_56 . V_64 -= V_155 ;
F_2 -> V_56 . V_57 = V_24 -> V_56 . V_64 ;
}
F_2 -> V_56 . V_83 = V_24 -> V_56 . V_83 + F_2 -> V_56 . V_57 ;
F_2 -> V_56 . V_91 = F_2 -> V_56 . V_64 = F_2 -> V_56 . V_158 = V_155 ;
F_2 -> V_56 . V_95 . V_159 = F_15 ( V_24 -> V_56 . V_95 ) + F_2 -> V_56 . V_57 ;
F_2 -> V_89 . V_83 = V_24 -> V_89 . V_83 ;
F_2 -> V_89 . V_95 = V_24 -> V_89 . V_95 ;
F_2 -> V_89 . V_91 = V_24 -> V_89 . V_91 ;
F_12 ( F_2 ) ;
if ( F_34 ( & F_2 -> V_9 ) ) {
return - V_75 ;
}
if ( ! F_2 -> V_113 )
F_35 ( & F_2 -> V_9 , & V_160 ) ;
F_36 ( & V_24 -> V_47 . V_104 ) ;
V_149 = V_24 -> V_47 . V_7 ;
V_24 -> V_47 . V_7 = F_2 ;
F_37 ( & V_24 -> V_47 . V_104 ) ;
if ( V_149 ) {
F_38 ( V_161 L_2 ,
V_149 ) ;
}
return 0 ;
#undef V_24
}
static int F_39 ( struct V_16 * F_2 ) {
#define V_24 (m2info->primary_dev)
if ( F_32 ( V_24 , F_2 ) ) {
F_38 ( V_161 L_3 ) ;
return - 1 ;
}
F_38 ( V_162 L_4 ,
V_24 -> V_9 . V_163 , F_2 -> V_9 . V_163 ) ;
F_2 -> V_164 = 1 ;
return 0 ;
#undef V_24
}
static void F_40 ( struct V_16 * F_2 ) {
#define V_24 (m2info->primary_dev)
if ( F_2 -> V_164 ) {
int V_81 ;
struct V_16 * V_47 ;
F_36 ( & V_24 -> V_47 . V_104 ) ;
V_47 = V_24 -> V_47 . V_7 ;
if ( V_47 == F_2 )
V_24 -> V_47 . V_7 = NULL ;
F_37 ( & V_24 -> V_47 . V_104 ) ;
if ( V_47 != F_2 ) {
F_38 ( V_161 L_5 ,
V_47 , F_2 ) ;
F_38 ( V_161 L_6 ) ;
return;
}
V_81 = F_2 -> V_9 . V_163 ;
F_41 ( & F_2 -> V_9 ) ;
V_24 -> V_56 . V_64 += F_2 -> V_56 . V_157 ;
F_38 ( V_162 L_7 , V_81 ) ;
F_2 -> V_164 = 0 ;
}
#undef V_24
}
static void * F_42 ( struct V_23 * V_24 ) {
struct V_16 * F_2 ;
if ( ! V_24 -> V_29 . V_47 )
return NULL ;
F_2 = F_43 ( sizeof( * F_2 ) , V_165 ) ;
if ( ! F_2 ) {
F_38 ( V_161 L_8 ) ;
return NULL ;
}
F_2 -> V_25 = V_24 ;
if ( F_39 ( F_2 ) ) {
F_44 ( F_2 ) ;
F_38 ( V_161 L_9 ) ;
return NULL ;
}
return F_2 ;
}
static void F_45 ( struct V_23 * V_24 , void * V_47 ) {
F_40 ( V_47 ) ;
F_44 ( V_47 ) ;
}
static int F_46 ( void ) {
if ( F_47 ( L_10 , NULL ) )
return - V_132 ;
F_48 ( & V_47 ) ;
return 0 ;
}
static void F_49 ( void ) {
F_50 ( & V_47 ) ;
}
