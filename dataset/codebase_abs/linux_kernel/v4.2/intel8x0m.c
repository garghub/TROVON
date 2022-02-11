static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline T_3 F_3 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_4 ( V_2 -> V_4 + V_3 ) ;
}
static inline T_2 F_5 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_6 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_5 )
{
F_8 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_2 V_3 , T_3 V_5 )
{
F_10 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_5 )
{
F_12 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_3 F_13 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_4 ( V_2 -> V_6 + V_3 ) ;
}
static inline void F_14 ( struct V_1 * V_2 , T_2 V_3 , T_3 V_5 )
{
F_10 ( V_5 , V_2 -> V_6 + V_3 ) ;
}
static unsigned int F_15 ( struct V_1 * V_2 , unsigned int V_7 )
{
static unsigned int V_8 [ 3 ] = {
V_9 , V_10 , V_11
} ;
if ( F_16 ( V_7 >= 3 ) )
return V_9 ;
return V_8 [ V_7 ] ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_7 )
{
int time ;
if ( V_7 > 1 )
return - V_12 ;
V_7 = F_15 ( V_2 , V_7 ) ;
if ( ( F_5 ( V_2 , F_18 ( V_13 ) ) & V_7 ) == 0 )
return - V_12 ;
time = 100 ;
do {
if ( ! ( F_1 ( V_2 , F_18 ( V_14 ) ) & V_15 ) )
return 0 ;
F_19 ( 10 ) ;
} while ( time -- );
F_20 ( V_2 -> V_16 -> V_17 ,
L_1 ,
F_1 ( V_2 , F_18 ( V_14 ) ) , F_5 ( V_2 , F_18 ( V_13 ) ) ) ;
F_13 ( V_2 , 0 ) ;
return - V_18 ;
}
static void F_21 ( struct V_19 * V_20 ,
unsigned short V_21 ,
unsigned short V_5 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
if ( F_17 ( V_2 , V_20 -> V_23 ) < 0 ) {
if ( ! V_2 -> V_24 )
F_20 ( V_2 -> V_16 -> V_17 ,
L_2 ,
V_20 -> V_23 , V_21 ) ;
}
F_14 ( V_2 , V_21 + V_20 -> V_23 * 0x80 , V_5 ) ;
}
static unsigned short F_22 ( struct V_19 * V_20 ,
unsigned short V_21 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
unsigned short V_25 ;
unsigned int V_26 ;
if ( F_17 ( V_2 , V_20 -> V_23 ) < 0 ) {
if ( ! V_2 -> V_24 )
F_20 ( V_2 -> V_16 -> V_17 ,
L_3 ,
V_20 -> V_23 , V_21 ) ;
V_25 = 0xffff ;
} else {
V_25 = F_13 ( V_2 , V_21 + V_20 -> V_23 * 0x80 ) ;
if ( ( V_26 = F_5 ( V_2 , F_18 ( V_13 ) ) ) & V_27 ) {
F_11 ( V_2 , F_18 ( V_13 ) ,
V_26 & ~ ( V_28 | V_29 | V_30 | V_31 ) ) ;
if ( ! V_2 -> V_24 )
F_20 ( V_2 -> V_16 -> V_17 ,
L_4 ,
V_20 -> V_23 , V_21 ) ;
V_25 = 0xffff ;
}
}
if ( V_21 == V_32 )
F_13 ( V_2 , 0 ) ;
return V_25 ;
}
static void F_23 ( struct V_1 * V_2 , struct V_33 * V_33 )
{
int V_34 ;
T_2 * V_35 = V_33 -> V_35 ;
unsigned long V_36 = V_33 -> V_37 ;
F_11 ( V_2 , V_36 + V_38 , V_33 -> V_39 ) ;
if ( V_33 -> V_40 == V_33 -> V_41 ) {
V_33 -> V_42 = V_33 -> V_43 = 2 ;
V_33 -> V_44 = V_33 -> V_41 >> 1 ;
for ( V_34 = 0 ; V_34 < ( V_45 + 1 ) * 2 ; V_34 += 4 ) {
V_35 [ V_34 + 0 ] = F_24 ( V_33 -> V_46 ) ;
V_35 [ V_34 + 1 ] = F_24 ( 0x80000000 |
V_33 -> V_44 >> V_2 -> V_47 ) ;
V_35 [ V_34 + 2 ] = F_24 ( V_33 -> V_46 + ( V_33 -> V_40 >> 1 ) ) ;
V_35 [ V_34 + 3 ] = F_24 ( 0x80000000 |
V_33 -> V_44 >> V_2 -> V_47 ) ;
}
V_33 -> V_48 = 2 ;
} else {
V_33 -> V_42 = V_33 -> V_43 = 1 ;
V_33 -> V_44 = V_33 -> V_41 ;
for ( V_34 = 0 ; V_34 < ( V_45 + 1 ) * 2 ; V_34 += 2 ) {
V_35 [ V_34 + 0 ] = F_24 ( V_33 -> V_46 + ( ( ( V_34 >> 1 ) * V_33 -> V_41 ) % V_33 -> V_40 ) ) ;
V_35 [ V_34 + 1 ] = F_24 ( 0x80000000 |
V_33 -> V_41 >> V_2 -> V_47 ) ;
}
V_33 -> V_48 = V_33 -> V_40 / V_33 -> V_41 ;
}
F_7 ( V_2 , V_36 + V_49 , V_33 -> V_50 = V_45 ) ;
V_33 -> V_51 = 0 ;
F_7 ( V_2 , V_36 + V_52 , 0 ) ;
V_33 -> V_53 = V_45 % V_33 -> V_48 ;
V_33 -> V_54 = 0 ;
#if 0
dev_dbg(chip->card->dev,
"lvi_frag = %i, frags = %i, period_size = 0x%x, period_size1 = 0x%x\n",
ichdev->lvi_frag, ichdev->frags, ichdev->fragsize,
ichdev->fragsize1);
#endif
F_7 ( V_2 , V_36 + V_33 -> V_55 , V_56 | V_57 | V_58 ) ;
}
static inline void F_25 ( struct V_1 * V_2 , struct V_33 * V_33 )
{
unsigned long V_36 = V_33 -> V_37 ;
int V_51 , V_59 , V_60 ;
int V_43 = 0 ;
V_51 = F_1 ( V_2 , V_36 + V_52 ) ;
if ( V_51 == V_33 -> V_51 ) {
V_60 = 1 ;
V_33 -> V_51 ++ ;
V_33 -> V_51 &= V_45 ;
} else {
V_60 = V_51 - V_33 -> V_51 ;
if ( V_60 < 0 )
V_60 += V_45 + 1 ;
V_33 -> V_51 = V_51 ;
}
V_33 -> V_54 += V_60 * V_33 -> V_44 ;
V_33 -> V_54 %= V_33 -> V_40 ;
V_33 -> V_50 += V_60 ;
V_33 -> V_50 &= V_45 ;
F_7 ( V_2 , V_36 + V_49 , V_33 -> V_50 ) ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
V_33 -> V_53 ++ ;
V_33 -> V_53 %= V_33 -> V_48 ;
V_33 -> V_35 [ V_33 -> V_50 * 2 ] = F_24 ( V_33 -> V_46 +
V_33 -> V_53 *
V_33 -> V_44 ) ;
#if 0
dev_dbg(chip->card->dev,
"new: bdbar[%i] = 0x%x [0x%x], prefetch = %i, all = 0x%x, 0x%x\n",
ichdev->lvi * 2, ichdev->bdbar[ichdev->lvi * 2],
ichdev->bdbar[ichdev->lvi * 2 + 1], inb(ICH_REG_OFF_PIV + port),
inl(port + 4), inb(port + ICH_REG_OFF_CR));
#endif
if ( -- V_33 -> V_43 == 0 ) {
V_33 -> V_43 = V_33 -> V_42 ;
V_43 = 1 ;
}
}
if ( V_43 && V_33 -> V_61 ) {
F_26 ( & V_2 -> V_62 ) ;
F_27 ( V_33 -> V_61 ) ;
F_28 ( & V_2 -> V_62 ) ;
}
F_7 ( V_2 , V_36 + V_33 -> V_55 , V_56 | V_57 | V_58 ) ;
}
static T_4 F_29 ( int V_63 , void * V_64 )
{
struct V_1 * V_2 = V_64 ;
struct V_33 * V_33 ;
unsigned int V_65 ;
unsigned int V_59 ;
F_28 ( & V_2 -> V_62 ) ;
V_65 = F_5 ( V_2 , V_2 -> V_66 ) ;
if ( V_65 == 0xffffffff ) {
F_26 ( & V_2 -> V_62 ) ;
return V_67 ;
}
if ( ( V_65 & V_2 -> V_68 ) == 0 ) {
if ( V_65 )
F_11 ( V_2 , V_2 -> V_66 , V_65 ) ;
F_26 ( & V_2 -> V_62 ) ;
return V_67 ;
}
for ( V_59 = 0 ; V_59 < V_2 -> V_69 ; V_59 ++ ) {
V_33 = & V_2 -> V_70 [ V_59 ] ;
if ( V_65 & V_33 -> V_68 )
F_25 ( V_2 , V_33 ) ;
}
F_11 ( V_2 , V_2 -> V_66 , V_65 & V_2 -> V_68 ) ;
F_26 ( & V_2 -> V_62 ) ;
return V_71 ;
}
static int F_30 ( struct V_72 * V_61 , int V_73 )
{
struct V_1 * V_2 = F_31 ( V_61 ) ;
struct V_33 * V_33 = F_32 ( V_61 ) ;
unsigned char V_5 = 0 ;
unsigned long V_36 = V_33 -> V_37 ;
switch ( V_73 ) {
case V_74 :
case V_75 :
V_5 = V_76 | V_77 ;
break;
case V_78 :
case V_79 :
V_5 = 0 ;
break;
case V_80 :
V_5 = V_76 ;
break;
case V_81 :
V_5 = V_76 | V_77 ;
break;
default:
return - V_82 ;
}
F_7 ( V_2 , V_36 + V_83 , V_5 ) ;
if ( V_73 == V_78 ) {
while ( ! ( F_1 ( V_2 , V_36 + V_33 -> V_55 ) & V_84 ) ) ;
F_7 ( V_2 , V_36 + V_83 , V_85 ) ;
}
return 0 ;
}
static int F_33 ( struct V_72 * V_61 ,
struct V_86 * V_87 )
{
return F_34 ( V_61 , F_35 ( V_87 ) ) ;
}
static int F_36 ( struct V_72 * V_61 )
{
return F_37 ( V_61 ) ;
}
static T_5 F_38 ( struct V_72 * V_61 )
{
struct V_1 * V_2 = F_31 ( V_61 ) ;
struct V_33 * V_33 = F_32 ( V_61 ) ;
T_6 V_88 , V_89 ;
V_88 = F_3 ( V_2 , V_33 -> V_37 + V_33 -> V_90 ) << V_2 -> V_47 ;
if ( V_88 != 0 )
V_89 = V_33 -> V_44 - V_88 ;
else
V_89 = 0 ;
V_89 += V_33 -> V_54 ;
if ( V_89 >= V_33 -> V_40 )
return 0 ;
return F_39 ( V_61 -> V_91 , V_89 ) ;
}
static int F_40 ( struct V_72 * V_61 )
{
struct V_1 * V_2 = F_31 ( V_61 ) ;
struct V_92 * V_91 = V_61 -> V_91 ;
struct V_33 * V_33 = F_32 ( V_61 ) ;
V_33 -> V_46 = V_91 -> V_93 ;
V_33 -> V_40 = F_41 ( V_61 ) ;
V_33 -> V_41 = F_42 ( V_61 ) ;
F_43 ( V_33 -> V_20 , V_94 , V_91 -> V_95 ) ;
F_43 ( V_33 -> V_20 , V_96 , 0 ) ;
F_23 ( V_2 , V_33 ) ;
return 0 ;
}
static int F_44 ( struct V_72 * V_61 , struct V_33 * V_33 )
{
static unsigned int V_97 [] = { 8000 , 9600 , 12000 , 16000 } ;
static struct V_98 V_99 = {
. V_100 = F_45 ( V_97 ) ,
. V_101 = V_97 ,
. V_102 = 0 ,
} ;
struct V_92 * V_91 = V_61 -> V_91 ;
int V_103 ;
V_33 -> V_61 = V_61 ;
V_91 -> V_104 = V_105 ;
V_103 = V_98 ( V_91 , 0 , V_106 ,
& V_99 ) ;
if ( V_103 < 0 )
return V_103 ;
V_91 -> V_22 = V_33 ;
return 0 ;
}
static int F_46 ( struct V_72 * V_61 )
{
struct V_1 * V_2 = F_31 ( V_61 ) ;
return F_44 ( V_61 , & V_2 -> V_70 [ V_107 ] ) ;
}
static int F_47 ( struct V_72 * V_61 )
{
struct V_1 * V_2 = F_31 ( V_61 ) ;
V_2 -> V_70 [ V_107 ] . V_61 = NULL ;
return 0 ;
}
static int F_48 ( struct V_72 * V_61 )
{
struct V_1 * V_2 = F_31 ( V_61 ) ;
return F_44 ( V_61 , & V_2 -> V_70 [ V_108 ] ) ;
}
static int F_49 ( struct V_72 * V_61 )
{
struct V_1 * V_2 = F_31 ( V_61 ) ;
V_2 -> V_70 [ V_108 ] . V_61 = NULL ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , int V_109 ,
struct V_110 * V_111 )
{
struct V_112 * V_113 ;
int V_103 ;
char V_114 [ 32 ] ;
if ( V_111 -> V_115 )
sprintf ( V_114 , L_5 , V_111 -> V_115 ) ;
else
strcpy ( V_114 , L_6 ) ;
V_103 = F_51 ( V_2 -> V_16 , V_114 , V_109 ,
V_111 -> V_116 ? 1 : 0 ,
V_111 -> V_117 ? 1 : 0 , & V_113 ) ;
if ( V_103 < 0 )
return V_103 ;
if ( V_111 -> V_116 )
F_52 ( V_113 , V_118 , V_111 -> V_116 ) ;
if ( V_111 -> V_117 )
F_52 ( V_113 , V_119 , V_111 -> V_117 ) ;
V_113 -> V_22 = V_2 ;
V_113 -> V_120 = 0 ;
V_113 -> V_121 = V_122 ;
if ( V_111 -> V_115 )
sprintf ( V_113 -> V_114 , L_7 , V_2 -> V_16 -> V_123 , V_111 -> V_115 ) ;
else
strcpy ( V_113 -> V_114 , V_2 -> V_16 -> V_123 ) ;
V_2 -> V_113 [ V_109 ] = V_113 ;
F_53 ( V_113 , V_124 ,
F_54 ( V_2 -> V_125 ) ,
V_111 -> V_126 ,
V_111 -> V_127 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_59 , V_128 , V_109 , V_103 ;
struct V_110 * V_129 , * V_111 ;
#if 1
V_129 = V_130 ;
V_128 = 1 ;
#else
switch ( V_2 -> V_131 ) {
case V_132 :
V_129 = V_133 ;
V_128 = F_45 ( V_133 ) ;
break;
case V_134 :
V_129 = V_135 ;
V_128 = F_45 ( V_135 ) ;
break;
default:
V_129 = V_130 ;
V_128 = 2 ;
break;
}
#endif
V_109 = 0 ;
for ( V_59 = 0 ; V_59 < V_128 ; V_59 ++ ) {
V_111 = V_129 + V_59 ;
if ( V_59 > 0 && V_111 -> V_136 ) {
if ( ! V_2 -> V_70 [ V_111 -> V_136 ] . V_20 )
continue;
}
V_103 = F_50 ( V_2 , V_109 , V_111 ) ;
if ( V_103 < 0 )
return V_103 ;
V_109 ++ ;
}
V_2 -> V_137 = V_109 ;
return 0 ;
}
static void F_56 ( struct V_138 * V_139 )
{
struct V_1 * V_2 = V_139 -> V_22 ;
V_2 -> V_140 = NULL ;
}
static void F_57 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
V_2 -> V_20 = NULL ;
}
static int F_58 ( struct V_1 * V_2 , int V_141 )
{
struct V_138 * V_142 ;
struct V_143 V_20 ;
struct V_19 * V_144 ;
int V_103 ;
unsigned int V_145 = 0 ;
static struct V_146 V_147 = {
. V_148 = F_21 ,
. V_149 = F_22 ,
} ;
V_2 -> V_24 = 1 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_22 = V_2 ;
V_20 . V_150 = F_57 ;
V_20 . V_151 = V_152 | V_153 ;
V_145 = F_5 ( V_2 , F_18 ( V_13 ) ) ;
if ( ( V_103 = V_138 ( V_2 -> V_16 , 0 , & V_147 , V_2 , & V_142 ) ) < 0 )
goto V_154;
V_142 -> V_150 = F_56 ;
if ( V_141 >= 8000 && V_141 <= 48000 )
V_142 -> clock = V_141 ;
V_2 -> V_140 = V_142 ;
V_20 . V_125 = V_2 -> V_125 ;
V_20 . V_23 = V_145 & V_10 ? 1 : 0 ;
if ( ( V_103 = F_59 ( V_142 , & V_20 , & V_144 ) ) < 0 ) {
F_20 ( V_2 -> V_16 -> V_17 ,
L_8 , V_20 . V_23 ) ;
if ( V_20 . V_23 == 0 )
goto V_154;
return V_103 ;
}
V_2 -> V_20 = V_144 ;
if( F_60 ( V_144 ) && ! V_2 -> V_70 [ V_108 ] . V_20 ) {
V_2 -> V_70 [ V_108 ] . V_20 = V_144 ;
V_2 -> V_70 [ V_107 ] . V_20 = V_144 ;
}
V_2 -> V_24 = 0 ;
return 0 ;
V_154:
if ( V_2 -> V_131 != V_134 )
F_11 ( V_2 , F_18 ( V_155 ) ,
F_5 ( V_2 , F_18 ( V_155 ) ) & ~ V_156 ) ;
return V_103 ;
}
static int F_61 ( struct V_1 * V_2 , int V_157 )
{
unsigned long V_158 ;
unsigned int V_159 , V_65 , V_160 ;
V_65 = V_27 | V_161 | V_162 ;
V_159 = F_5 ( V_2 , F_18 ( V_13 ) ) ;
F_11 ( V_2 , F_18 ( V_13 ) , V_159 & V_65 ) ;
V_159 = F_5 ( V_2 , F_18 ( V_155 ) ) ;
V_159 &= ~ ( V_163 ) ;
V_159 |= ( V_159 & V_156 ) == 0 ? V_156 : V_164 ;
F_11 ( V_2 , F_18 ( V_155 ) , V_159 ) ;
F_62 ( 500 , 1000 ) ;
V_158 = V_165 + V_166 / 4 ;
do {
if ( ( F_5 ( V_2 , F_18 ( V_155 ) ) & V_164 ) == 0 )
goto V_167;
F_63 ( 1 ) ;
} while ( F_64 ( V_158 , V_165 ) );
F_20 ( V_2 -> V_16 -> V_17 , L_9 ,
F_5 ( V_2 , F_18 ( V_155 ) ) ) ;
return - V_12 ;
V_167:
if ( V_157 ) {
V_158 = V_165 + V_166 ;
do {
V_65 = F_5 ( V_2 , F_18 ( V_13 ) ) &
( V_9 | V_10 | V_11 ) ;
if ( V_65 )
break;
F_63 ( 1 ) ;
} while ( F_64 ( V_158 , V_165 ) );
if ( ! V_65 ) {
F_20 ( V_2 -> V_16 -> V_17 ,
L_10 ,
F_5 ( V_2 , F_18 ( V_13 ) ) ) ;
return - V_12 ;
}
V_160 = V_9 | V_10 ;
V_158 = V_165 + V_166 / 4 ;
while ( V_65 != V_160 && F_64 ( V_158 , V_165 ) ) {
F_63 ( 1 ) ;
V_65 |= F_5 ( V_2 , F_18 ( V_13 ) ) & V_160 ;
}
} else {
V_65 = 0 ;
if ( V_2 -> V_20 )
V_65 |= F_15 ( V_2 , V_2 -> V_20 -> V_23 ) ;
V_158 = V_165 + V_166 ;
do {
V_160 = F_5 ( V_2 , F_18 ( V_13 ) ) &
( V_9 | V_10 | V_11 ) ;
if ( V_65 == V_160 )
break;
F_63 ( 1 ) ;
} while ( F_64 ( V_158 , V_165 ) );
}
if ( V_2 -> V_131 == V_168 ) {
F_9 ( V_2 , 0x4c , F_3 ( V_2 , 0x4c ) | 1 ) ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , int V_157 )
{
unsigned int V_59 ;
int V_103 ;
if ( ( V_103 = F_61 ( V_2 , V_157 ) ) < 0 )
return V_103 ;
F_13 ( V_2 , 0 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_69 ; V_59 ++ )
F_7 ( V_2 , V_83 + V_2 -> V_70 [ V_59 ] . V_37 , 0x00 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_69 ; V_59 ++ )
F_7 ( V_2 , V_83 + V_2 -> V_70 [ V_59 ] . V_37 , V_85 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_69 ; V_59 ++ )
F_11 ( V_2 , V_38 + V_2 -> V_70 [ V_59 ] . V_37 , V_2 -> V_70 [ V_59 ] . V_39 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
unsigned int V_59 ;
if ( V_2 -> V_63 < 0 )
goto V_169;
for ( V_59 = 0 ; V_59 < V_2 -> V_69 ; V_59 ++ )
F_7 ( V_2 , V_83 + V_2 -> V_70 [ V_59 ] . V_37 , 0x00 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_69 ; V_59 ++ )
F_7 ( V_2 , V_83 + V_2 -> V_70 [ V_59 ] . V_37 , V_85 ) ;
V_169:
if ( V_2 -> V_63 >= 0 )
F_67 ( V_2 -> V_63 , V_2 ) ;
if ( V_2 -> V_170 . V_171 )
F_68 ( & V_2 -> V_170 ) ;
if ( V_2 -> V_6 )
F_69 ( V_2 -> V_125 , V_2 -> V_6 ) ;
if ( V_2 -> V_4 )
F_69 ( V_2 -> V_125 , V_2 -> V_4 ) ;
F_70 ( V_2 -> V_125 ) ;
F_71 ( V_2 -> V_125 ) ;
F_72 ( V_2 ) ;
return 0 ;
}
static int F_73 ( struct V_109 * V_17 )
{
struct V_172 * V_16 = F_74 ( V_17 ) ;
struct V_1 * V_2 = V_16 -> V_22 ;
int V_59 ;
F_75 ( V_16 , V_173 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_137 ; V_59 ++ )
F_76 ( V_2 -> V_113 [ V_59 ] ) ;
F_77 ( V_2 -> V_20 ) ;
if ( V_2 -> V_63 >= 0 ) {
F_67 ( V_2 -> V_63 , V_2 ) ;
V_2 -> V_63 = - 1 ;
}
return 0 ;
}
static int F_78 ( struct V_109 * V_17 )
{
struct V_174 * V_125 = F_79 ( V_17 ) ;
struct V_172 * V_16 = F_74 ( V_17 ) ;
struct V_1 * V_2 = V_16 -> V_22 ;
if ( F_80 ( V_125 -> V_63 , F_29 ,
V_175 , V_176 , V_2 ) ) {
F_20 ( V_17 , L_11 ,
V_125 -> V_63 ) ;
F_81 ( V_16 ) ;
return - V_12 ;
}
V_2 -> V_63 = V_125 -> V_63 ;
F_65 ( V_2 , 0 ) ;
F_82 ( V_2 -> V_20 ) ;
F_75 ( V_16 , V_177 ) ;
return 0 ;
}
static void F_83 ( struct V_178 * V_179 ,
struct V_180 * V_181 )
{
struct V_1 * V_2 = V_179 -> V_22 ;
unsigned int V_26 ;
F_84 ( V_181 , L_12 ) ;
if ( V_2 -> V_131 == V_134 )
return;
V_26 = F_5 ( V_2 , F_18 ( V_13 ) ) ;
F_84 ( V_181 , L_13 ,
F_5 ( V_2 , F_18 ( V_155 ) ) ) ;
F_84 ( V_181 , L_14 , V_26 ) ;
F_84 ( V_181 , L_15 ,
V_26 & V_9 ? L_16 : L_17 ,
V_26 & V_10 ? L_18 : L_17 ,
V_26 & V_11 ? L_19 : L_17 ,
( V_26 & ( V_9 | V_10 | V_11 ) ) == 0 ? L_20 : L_17 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_178 * V_179 ;
if ( ! F_86 ( V_2 -> V_16 , L_21 , & V_179 ) )
F_87 ( V_179 , V_2 , F_83 ) ;
}
static int F_88 ( struct V_182 * V_109 )
{
struct V_1 * V_2 = V_109 -> V_183 ;
return F_66 ( V_2 ) ;
}
static int F_89 ( struct V_172 * V_16 ,
struct V_174 * V_125 ,
unsigned long V_131 ,
struct V_1 * * V_184 )
{
struct V_1 * V_2 ;
int V_103 ;
unsigned int V_59 ;
unsigned int V_185 ;
struct V_33 * V_33 ;
static struct V_186 V_147 = {
. V_187 = F_88 ,
} ;
static struct V_188 V_189 [ 2 ] = {
{ V_161 , 0 } ,
{ V_162 , 0x10 } ,
} ;
struct V_188 * V_129 ;
* V_184 = NULL ;
if ( ( V_103 = F_90 ( V_125 ) ) < 0 )
return V_103 ;
V_2 = F_91 ( sizeof( * V_2 ) , V_190 ) ;
if ( V_2 == NULL ) {
F_71 ( V_125 ) ;
return - V_191 ;
}
F_92 ( & V_2 -> V_62 ) ;
V_2 -> V_131 = V_131 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_125 = V_125 ;
V_2 -> V_63 = - 1 ;
if ( ( V_103 = F_93 ( V_125 , V_16 -> V_123 ) ) < 0 ) {
F_72 ( V_2 ) ;
F_71 ( V_125 ) ;
return V_103 ;
}
if ( V_131 == V_134 ) {
V_2 -> V_4 = F_94 ( V_125 , 0 , 0 ) ;
goto V_192;
}
if ( F_95 ( V_125 , 2 ) & V_193 )
V_2 -> V_6 = F_94 ( V_125 , 2 , 0 ) ;
else
V_2 -> V_6 = F_94 ( V_125 , 0 , 0 ) ;
if ( ! V_2 -> V_6 ) {
F_20 ( V_16 -> V_17 , L_22 ) ;
F_66 ( V_2 ) ;
return - V_12 ;
}
if ( F_95 ( V_125 , 3 ) & V_193 )
V_2 -> V_4 = F_94 ( V_125 , 3 , 0 ) ;
else
V_2 -> V_4 = F_94 ( V_125 , 1 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_20 ( V_16 -> V_17 , L_23 ) ;
F_66 ( V_2 ) ;
return - V_12 ;
}
V_192:
if ( F_80 ( V_125 -> V_63 , F_29 , V_175 ,
V_176 , V_2 ) ) {
F_20 ( V_16 -> V_17 , L_24 , V_125 -> V_63 ) ;
F_66 ( V_2 ) ;
return - V_18 ;
}
V_2 -> V_63 = V_125 -> V_63 ;
F_96 ( V_125 ) ;
F_97 ( V_2 -> V_63 ) ;
V_2 -> V_69 = 2 ;
V_129 = V_189 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_69 ; V_59 ++ ) {
V_33 = & V_2 -> V_70 [ V_59 ] ;
V_33 -> V_70 = V_59 ;
V_33 -> V_37 = V_129 [ V_59 ] . V_3 ;
V_33 -> V_68 = V_129 [ V_59 ] . V_68 ;
if ( V_131 == V_168 ) {
V_33 -> V_55 = V_194 ;
V_33 -> V_90 = V_195 ;
} else {
V_33 -> V_55 = V_195 ;
V_33 -> V_90 = V_194 ;
}
if ( V_131 == V_134 )
V_33 -> V_196 = ( V_33 -> V_37 - 0x40 ) / 0x10 ;
}
V_2 -> V_47 = ( V_131 == V_168 ) ? 0 : 1 ;
if ( F_98 ( V_124 , F_54 ( V_125 ) ,
V_2 -> V_69 * sizeof( T_2 ) * V_197 * 2 ,
& V_2 -> V_170 ) < 0 ) {
F_66 ( V_2 ) ;
return - V_191 ;
}
V_185 = 0 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_69 ; V_59 ++ ) {
V_33 = & V_2 -> V_70 [ V_59 ] ;
V_33 -> V_35 = ( ( T_2 * ) V_2 -> V_170 . V_171 ) + ( V_59 * V_197 * 2 ) ;
V_33 -> V_39 = V_2 -> V_170 . V_6 + ( V_59 * sizeof( T_2 ) * V_197 * 2 ) ;
V_185 |= V_33 -> V_68 ;
}
V_2 -> V_66 = V_198 ;
V_2 -> V_68 = V_185 ;
if ( ( V_103 = F_65 ( V_2 , 1 ) ) < 0 ) {
F_66 ( V_2 ) ;
return V_103 ;
}
if ( ( V_103 = F_99 ( V_16 , V_199 , V_2 , & V_147 ) ) < 0 ) {
F_66 ( V_2 ) ;
return V_103 ;
}
* V_184 = V_2 ;
return 0 ;
}
static int F_100 ( struct V_174 * V_125 ,
const struct V_200 * V_201 )
{
struct V_172 * V_16 ;
struct V_1 * V_2 ;
int V_103 ;
struct V_202 * V_114 ;
V_103 = F_101 ( & V_125 -> V_17 , V_203 , V_204 , V_205 , 0 , & V_16 ) ;
if ( V_103 < 0 )
return V_103 ;
strcpy ( V_16 -> V_206 , L_25 ) ;
strcpy ( V_16 -> V_123 , L_6 ) ;
for ( V_114 = V_207 ; V_114 -> V_204 ; V_114 ++ ) {
if ( V_125 -> V_109 == V_114 -> V_204 ) {
strcpy ( V_16 -> V_123 , V_114 -> V_208 ) ;
break;
}
}
strcat ( V_16 -> V_123 , L_26 ) ;
if ( ( V_103 = F_89 ( V_16 , V_125 , V_201 -> V_209 , & V_2 ) ) < 0 ) {
F_102 ( V_16 ) ;
return V_103 ;
}
V_16 -> V_22 = V_2 ;
if ( ( V_103 = F_58 ( V_2 , V_141 ) ) < 0 ) {
F_102 ( V_16 ) ;
return V_103 ;
}
if ( ( V_103 = F_55 ( V_2 ) ) < 0 ) {
F_102 ( V_16 ) ;
return V_103 ;
}
F_85 ( V_2 ) ;
sprintf ( V_16 -> V_210 , L_27 ,
V_16 -> V_123 , V_2 -> V_63 ) ;
if ( ( V_103 = F_103 ( V_16 ) ) < 0 ) {
F_102 ( V_16 ) ;
return V_103 ;
}
F_104 ( V_125 , V_16 ) ;
return 0 ;
}
static void F_105 ( struct V_174 * V_125 )
{
F_102 ( F_106 ( V_125 ) ) ;
}
