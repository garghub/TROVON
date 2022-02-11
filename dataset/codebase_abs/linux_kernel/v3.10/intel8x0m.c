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
F_20 ( V_16 L_1 ,
F_1 ( V_2 , F_18 ( V_14 ) ) , F_5 ( V_2 , F_18 ( V_13 ) ) ) ;
F_13 ( V_2 , 0 ) ;
return - V_17 ;
}
static void F_21 ( struct V_18 * V_19 ,
unsigned short V_20 ,
unsigned short V_5 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
if ( F_17 ( V_2 , V_19 -> V_22 ) < 0 ) {
if ( ! V_2 -> V_23 )
F_20 ( V_16 L_2 , V_19 -> V_22 , V_20 ) ;
}
F_14 ( V_2 , V_20 + V_19 -> V_22 * 0x80 , V_5 ) ;
}
static unsigned short F_22 ( struct V_18 * V_19 ,
unsigned short V_20 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
unsigned short V_24 ;
unsigned int V_25 ;
if ( F_17 ( V_2 , V_19 -> V_22 ) < 0 ) {
if ( ! V_2 -> V_23 )
F_20 ( V_16 L_3 , V_19 -> V_22 , V_20 ) ;
V_24 = 0xffff ;
} else {
V_24 = F_13 ( V_2 , V_20 + V_19 -> V_22 * 0x80 ) ;
if ( ( V_25 = F_5 ( V_2 , F_18 ( V_13 ) ) ) & V_26 ) {
F_11 ( V_2 , F_18 ( V_13 ) ,
V_25 & ~ ( V_27 | V_28 | V_29 | V_30 ) ) ;
if ( ! V_2 -> V_23 )
F_20 ( V_16 L_4 , V_19 -> V_22 , V_20 ) ;
V_24 = 0xffff ;
}
}
if ( V_20 == V_31 )
F_13 ( V_2 , 0 ) ;
return V_24 ;
}
static void F_23 ( struct V_1 * V_2 , struct V_32 * V_32 )
{
int V_33 ;
T_2 * V_34 = V_32 -> V_34 ;
unsigned long V_35 = V_32 -> V_36 ;
F_11 ( V_2 , V_35 + V_37 , V_32 -> V_38 ) ;
if ( V_32 -> V_39 == V_32 -> V_40 ) {
V_32 -> V_41 = V_32 -> V_42 = 2 ;
V_32 -> V_43 = V_32 -> V_40 >> 1 ;
for ( V_33 = 0 ; V_33 < ( V_44 + 1 ) * 2 ; V_33 += 4 ) {
V_34 [ V_33 + 0 ] = F_24 ( V_32 -> V_45 ) ;
V_34 [ V_33 + 1 ] = F_24 ( 0x80000000 |
V_32 -> V_43 >> V_2 -> V_46 ) ;
V_34 [ V_33 + 2 ] = F_24 ( V_32 -> V_45 + ( V_32 -> V_39 >> 1 ) ) ;
V_34 [ V_33 + 3 ] = F_24 ( 0x80000000 |
V_32 -> V_43 >> V_2 -> V_46 ) ;
}
V_32 -> V_47 = 2 ;
} else {
V_32 -> V_41 = V_32 -> V_42 = 1 ;
V_32 -> V_43 = V_32 -> V_40 ;
for ( V_33 = 0 ; V_33 < ( V_44 + 1 ) * 2 ; V_33 += 2 ) {
V_34 [ V_33 + 0 ] = F_24 ( V_32 -> V_45 + ( ( ( V_33 >> 1 ) * V_32 -> V_40 ) % V_32 -> V_39 ) ) ;
V_34 [ V_33 + 1 ] = F_24 ( 0x80000000 |
V_32 -> V_40 >> V_2 -> V_46 ) ;
}
V_32 -> V_47 = V_32 -> V_39 / V_32 -> V_40 ;
}
F_7 ( V_2 , V_35 + V_48 , V_32 -> V_49 = V_44 ) ;
V_32 -> V_50 = 0 ;
F_7 ( V_2 , V_35 + V_51 , 0 ) ;
V_32 -> V_52 = V_44 % V_32 -> V_47 ;
V_32 -> V_53 = 0 ;
#if 0
printk(KERN_DEBUG "lvi_frag = %i, frags = %i, period_size = 0x%x, "
"period_size1 = 0x%x\n",
ichdev->lvi_frag, ichdev->frags, ichdev->fragsize,
ichdev->fragsize1);
#endif
F_7 ( V_2 , V_35 + V_32 -> V_54 , V_55 | V_56 | V_57 ) ;
}
static inline void F_25 ( struct V_1 * V_2 , struct V_32 * V_32 )
{
unsigned long V_35 = V_32 -> V_36 ;
int V_50 , V_58 , V_59 ;
int V_42 = 0 ;
V_50 = F_1 ( V_2 , V_35 + V_51 ) ;
if ( V_50 == V_32 -> V_50 ) {
V_59 = 1 ;
V_32 -> V_50 ++ ;
V_32 -> V_50 &= V_44 ;
} else {
V_59 = V_50 - V_32 -> V_50 ;
if ( V_59 < 0 )
V_59 += V_44 + 1 ;
V_32 -> V_50 = V_50 ;
}
V_32 -> V_53 += V_59 * V_32 -> V_43 ;
V_32 -> V_53 %= V_32 -> V_39 ;
V_32 -> V_49 += V_59 ;
V_32 -> V_49 &= V_44 ;
F_7 ( V_2 , V_35 + V_48 , V_32 -> V_49 ) ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
V_32 -> V_52 ++ ;
V_32 -> V_52 %= V_32 -> V_47 ;
V_32 -> V_34 [ V_32 -> V_49 * 2 ] = F_24 ( V_32 -> V_45 +
V_32 -> V_52 *
V_32 -> V_43 ) ;
#if 0
printk(KERN_DEBUG "new: bdbar[%i] = 0x%x [0x%x], "
"prefetch = %i, all = 0x%x, 0x%x\n",
ichdev->lvi * 2, ichdev->bdbar[ichdev->lvi * 2],
ichdev->bdbar[ichdev->lvi * 2 + 1], inb(ICH_REG_OFF_PIV + port),
inl(port + 4), inb(port + ICH_REG_OFF_CR));
#endif
if ( -- V_32 -> V_42 == 0 ) {
V_32 -> V_42 = V_32 -> V_41 ;
V_42 = 1 ;
}
}
if ( V_42 && V_32 -> V_60 ) {
F_26 ( & V_2 -> V_61 ) ;
F_27 ( V_32 -> V_60 ) ;
F_28 ( & V_2 -> V_61 ) ;
}
F_7 ( V_2 , V_35 + V_32 -> V_54 , V_55 | V_56 | V_57 ) ;
}
static T_4 F_29 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
struct V_32 * V_32 ;
unsigned int V_64 ;
unsigned int V_58 ;
F_28 ( & V_2 -> V_61 ) ;
V_64 = F_5 ( V_2 , V_2 -> V_65 ) ;
if ( V_64 == 0xffffffff ) {
F_26 ( & V_2 -> V_61 ) ;
return V_66 ;
}
if ( ( V_64 & V_2 -> V_67 ) == 0 ) {
if ( V_64 )
F_11 ( V_2 , V_2 -> V_65 , V_64 ) ;
F_26 ( & V_2 -> V_61 ) ;
return V_66 ;
}
for ( V_58 = 0 ; V_58 < V_2 -> V_68 ; V_58 ++ ) {
V_32 = & V_2 -> V_69 [ V_58 ] ;
if ( V_64 & V_32 -> V_67 )
F_25 ( V_2 , V_32 ) ;
}
F_11 ( V_2 , V_2 -> V_65 , V_64 & V_2 -> V_67 ) ;
F_26 ( & V_2 -> V_61 ) ;
return V_70 ;
}
static int F_30 ( struct V_71 * V_60 , int V_72 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_32 * V_32 = F_32 ( V_60 ) ;
unsigned char V_5 = 0 ;
unsigned long V_35 = V_32 -> V_36 ;
switch ( V_72 ) {
case V_73 :
case V_74 :
V_5 = V_75 | V_76 ;
break;
case V_77 :
case V_78 :
V_5 = 0 ;
break;
case V_79 :
V_5 = V_75 ;
break;
case V_80 :
V_5 = V_75 | V_76 ;
break;
default:
return - V_81 ;
}
F_7 ( V_2 , V_35 + V_82 , V_5 ) ;
if ( V_72 == V_77 ) {
while ( ! ( F_1 ( V_2 , V_35 + V_32 -> V_54 ) & V_83 ) ) ;
F_7 ( V_2 , V_35 + V_82 , V_84 ) ;
}
return 0 ;
}
static int F_33 ( struct V_71 * V_60 ,
struct V_85 * V_86 )
{
return F_34 ( V_60 , F_35 ( V_86 ) ) ;
}
static int F_36 ( struct V_71 * V_60 )
{
return F_37 ( V_60 ) ;
}
static T_5 F_38 ( struct V_71 * V_60 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_32 * V_32 = F_32 ( V_60 ) ;
T_6 V_87 , V_88 ;
V_87 = F_3 ( V_2 , V_32 -> V_36 + V_32 -> V_89 ) << V_2 -> V_46 ;
if ( V_87 != 0 )
V_88 = V_32 -> V_43 - V_87 ;
else
V_88 = 0 ;
V_88 += V_32 -> V_53 ;
if ( V_88 >= V_32 -> V_39 )
return 0 ;
return F_39 ( V_60 -> V_90 , V_88 ) ;
}
static int F_40 ( struct V_71 * V_60 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_91 * V_90 = V_60 -> V_90 ;
struct V_32 * V_32 = F_32 ( V_60 ) ;
V_32 -> V_45 = V_90 -> V_92 ;
V_32 -> V_39 = F_41 ( V_60 ) ;
V_32 -> V_40 = F_42 ( V_60 ) ;
F_43 ( V_32 -> V_19 , V_93 , V_90 -> V_94 ) ;
F_43 ( V_32 -> V_19 , V_95 , 0 ) ;
F_23 ( V_2 , V_32 ) ;
return 0 ;
}
static int F_44 ( struct V_71 * V_60 , struct V_32 * V_32 )
{
static unsigned int V_96 [] = { 8000 , 9600 , 12000 , 16000 } ;
static struct V_97 V_98 = {
. V_99 = F_45 ( V_96 ) ,
. V_100 = V_96 ,
. V_101 = 0 ,
} ;
struct V_91 * V_90 = V_60 -> V_90 ;
int V_102 ;
V_32 -> V_60 = V_60 ;
V_90 -> V_103 = V_104 ;
V_102 = V_97 ( V_90 , 0 , V_105 ,
& V_98 ) ;
if ( V_102 < 0 )
return V_102 ;
V_90 -> V_21 = V_32 ;
return 0 ;
}
static int F_46 ( struct V_71 * V_60 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
return F_44 ( V_60 , & V_2 -> V_69 [ V_106 ] ) ;
}
static int F_47 ( struct V_71 * V_60 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
V_2 -> V_69 [ V_106 ] . V_60 = NULL ;
return 0 ;
}
static int F_48 ( struct V_71 * V_60 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
return F_44 ( V_60 , & V_2 -> V_69 [ V_107 ] ) ;
}
static int F_49 ( struct V_71 * V_60 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
V_2 -> V_69 [ V_107 ] . V_60 = NULL ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , int V_108 ,
struct V_109 * V_110 )
{
struct V_111 * V_112 ;
int V_102 ;
char V_113 [ 32 ] ;
if ( V_110 -> V_114 )
sprintf ( V_113 , L_5 , V_110 -> V_114 ) ;
else
strcpy ( V_113 , L_6 ) ;
V_102 = F_51 ( V_2 -> V_115 , V_113 , V_108 ,
V_110 -> V_116 ? 1 : 0 ,
V_110 -> V_117 ? 1 : 0 , & V_112 ) ;
if ( V_102 < 0 )
return V_102 ;
if ( V_110 -> V_116 )
F_52 ( V_112 , V_118 , V_110 -> V_116 ) ;
if ( V_110 -> V_117 )
F_52 ( V_112 , V_119 , V_110 -> V_117 ) ;
V_112 -> V_21 = V_2 ;
V_112 -> V_120 = 0 ;
V_112 -> V_121 = V_122 ;
if ( V_110 -> V_114 )
sprintf ( V_112 -> V_113 , L_7 , V_2 -> V_115 -> V_123 , V_110 -> V_114 ) ;
else
strcpy ( V_112 -> V_113 , V_2 -> V_115 -> V_123 ) ;
V_2 -> V_112 [ V_108 ] = V_112 ;
F_53 ( V_112 , V_124 ,
F_54 ( V_2 -> V_125 ) ,
V_110 -> V_126 ,
V_110 -> V_127 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_58 , V_128 , V_108 , V_102 ;
struct V_109 * V_129 , * V_110 ;
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
V_108 = 0 ;
for ( V_58 = 0 ; V_58 < V_128 ; V_58 ++ ) {
V_110 = V_129 + V_58 ;
if ( V_58 > 0 && V_110 -> V_136 ) {
if ( ! V_2 -> V_69 [ V_110 -> V_136 ] . V_19 )
continue;
}
V_102 = F_50 ( V_2 , V_108 , V_110 ) ;
if ( V_102 < 0 )
return V_102 ;
V_108 ++ ;
}
V_2 -> V_137 = V_108 ;
return 0 ;
}
static void F_56 ( struct V_138 * V_139 )
{
struct V_1 * V_2 = V_139 -> V_21 ;
V_2 -> V_140 = NULL ;
}
static void F_57 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
V_2 -> V_19 = NULL ;
}
static int F_58 ( struct V_1 * V_2 , int V_141 )
{
struct V_138 * V_142 ;
struct V_143 V_19 ;
struct V_18 * V_144 ;
int V_102 ;
unsigned int V_145 = 0 ;
static struct V_146 V_147 = {
. V_148 = F_21 ,
. V_149 = F_22 ,
} ;
V_2 -> V_23 = 1 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_21 = V_2 ;
V_19 . V_150 = F_57 ;
V_19 . V_151 = V_152 | V_153 ;
V_145 = F_5 ( V_2 , F_18 ( V_13 ) ) ;
if ( ( V_102 = V_138 ( V_2 -> V_115 , 0 , & V_147 , V_2 , & V_142 ) ) < 0 )
goto V_154;
V_142 -> V_150 = F_56 ;
if ( V_141 >= 8000 && V_141 <= 48000 )
V_142 -> clock = V_141 ;
V_2 -> V_140 = V_142 ;
V_19 . V_125 = V_2 -> V_125 ;
V_19 . V_22 = V_145 & V_10 ? 1 : 0 ;
if ( ( V_102 = F_59 ( V_142 , & V_19 , & V_144 ) ) < 0 ) {
F_20 ( V_16 L_8 , V_19 . V_22 ) ;
if ( V_19 . V_22 == 0 )
goto V_154;
return V_102 ;
}
V_2 -> V_19 = V_144 ;
if( F_60 ( V_144 ) && ! V_2 -> V_69 [ V_107 ] . V_19 ) {
V_2 -> V_69 [ V_107 ] . V_19 = V_144 ;
V_2 -> V_69 [ V_106 ] . V_19 = V_144 ;
}
V_2 -> V_23 = 0 ;
return 0 ;
V_154:
if ( V_2 -> V_131 != V_134 )
F_11 ( V_2 , F_18 ( V_155 ) ,
F_5 ( V_2 , F_18 ( V_155 ) ) & ~ V_156 ) ;
return V_102 ;
}
static int F_61 ( struct V_1 * V_2 , int V_157 )
{
unsigned long V_158 ;
unsigned int V_159 , V_64 , V_160 ;
V_64 = V_26 | V_161 | V_162 ;
V_159 = F_5 ( V_2 , F_18 ( V_13 ) ) ;
F_11 ( V_2 , F_18 ( V_13 ) , V_159 & V_64 ) ;
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
F_20 ( V_16 L_9 ,
F_5 ( V_2 , F_18 ( V_155 ) ) ) ;
return - V_12 ;
V_167:
if ( V_157 ) {
V_158 = V_165 + V_166 ;
do {
V_64 = F_5 ( V_2 , F_18 ( V_13 ) ) &
( V_9 | V_10 | V_11 ) ;
if ( V_64 )
break;
F_63 ( 1 ) ;
} while ( F_64 ( V_158 , V_165 ) );
if ( ! V_64 ) {
F_20 ( V_16 L_10 ,
F_5 ( V_2 , F_18 ( V_13 ) ) ) ;
return - V_12 ;
}
V_160 = V_9 | V_10 ;
V_158 = V_165 + V_166 / 4 ;
while ( V_64 != V_160 && F_64 ( V_158 , V_165 ) ) {
F_63 ( 1 ) ;
V_64 |= F_5 ( V_2 , F_18 ( V_13 ) ) & V_160 ;
}
} else {
V_64 = 0 ;
if ( V_2 -> V_19 )
V_64 |= F_15 ( V_2 , V_2 -> V_19 -> V_22 ) ;
V_158 = V_165 + V_166 ;
do {
V_160 = F_5 ( V_2 , F_18 ( V_13 ) ) &
( V_9 | V_10 | V_11 ) ;
if ( V_64 == V_160 )
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
unsigned int V_58 ;
int V_102 ;
if ( ( V_102 = F_61 ( V_2 , V_157 ) ) < 0 )
return V_102 ;
F_13 ( V_2 , 0 ) ;
for ( V_58 = 0 ; V_58 < V_2 -> V_68 ; V_58 ++ )
F_7 ( V_2 , V_82 + V_2 -> V_69 [ V_58 ] . V_36 , 0x00 ) ;
for ( V_58 = 0 ; V_58 < V_2 -> V_68 ; V_58 ++ )
F_7 ( V_2 , V_82 + V_2 -> V_69 [ V_58 ] . V_36 , V_84 ) ;
for ( V_58 = 0 ; V_58 < V_2 -> V_68 ; V_58 ++ )
F_11 ( V_2 , V_37 + V_2 -> V_69 [ V_58 ] . V_36 , V_2 -> V_69 [ V_58 ] . V_38 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
unsigned int V_58 ;
if ( V_2 -> V_62 < 0 )
goto V_169;
for ( V_58 = 0 ; V_58 < V_2 -> V_68 ; V_58 ++ )
F_7 ( V_2 , V_82 + V_2 -> V_69 [ V_58 ] . V_36 , 0x00 ) ;
for ( V_58 = 0 ; V_58 < V_2 -> V_68 ; V_58 ++ )
F_7 ( V_2 , V_82 + V_2 -> V_69 [ V_58 ] . V_36 , V_84 ) ;
V_169:
if ( V_2 -> V_62 >= 0 )
F_67 ( V_2 -> V_62 , V_2 ) ;
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
static int F_73 ( struct V_108 * V_172 )
{
struct V_173 * V_125 = F_74 ( V_172 ) ;
struct V_174 * V_115 = F_75 ( V_172 ) ;
struct V_1 * V_2 = V_115 -> V_21 ;
int V_58 ;
F_76 ( V_115 , V_175 ) ;
for ( V_58 = 0 ; V_58 < V_2 -> V_137 ; V_58 ++ )
F_77 ( V_2 -> V_112 [ V_58 ] ) ;
F_78 ( V_2 -> V_19 ) ;
if ( V_2 -> V_62 >= 0 ) {
F_67 ( V_2 -> V_62 , V_2 ) ;
V_2 -> V_62 = - 1 ;
}
F_71 ( V_125 ) ;
F_79 ( V_125 ) ;
F_80 ( V_125 , V_176 ) ;
return 0 ;
}
static int F_81 ( struct V_108 * V_172 )
{
struct V_173 * V_125 = F_74 ( V_172 ) ;
struct V_174 * V_115 = F_75 ( V_172 ) ;
struct V_1 * V_2 = V_115 -> V_21 ;
F_80 ( V_125 , V_177 ) ;
F_82 ( V_125 ) ;
if ( F_83 ( V_125 ) < 0 ) {
F_84 ( V_16 L_11
L_12 ) ;
F_85 ( V_115 ) ;
return - V_12 ;
}
F_86 ( V_125 ) ;
if ( F_87 ( V_125 -> V_62 , F_29 ,
V_178 , V_179 , V_2 ) ) {
F_84 ( V_16 L_13
L_12 , V_125 -> V_62 ) ;
F_85 ( V_115 ) ;
return - V_12 ;
}
V_2 -> V_62 = V_125 -> V_62 ;
F_65 ( V_2 , 0 ) ;
F_88 ( V_2 -> V_19 ) ;
F_76 ( V_115 , V_180 ) ;
return 0 ;
}
static void F_89 ( struct V_181 * V_182 ,
struct V_183 * V_184 )
{
struct V_1 * V_2 = V_182 -> V_21 ;
unsigned int V_25 ;
F_90 ( V_184 , L_14 ) ;
if ( V_2 -> V_131 == V_134 )
return;
V_25 = F_5 ( V_2 , F_18 ( V_13 ) ) ;
F_90 ( V_184 , L_15 ,
F_5 ( V_2 , F_18 ( V_155 ) ) ) ;
F_90 ( V_184 , L_16 , V_25 ) ;
F_90 ( V_184 , L_17 ,
V_25 & V_9 ? L_18 : L_19 ,
V_25 & V_10 ? L_20 : L_19 ,
V_25 & V_11 ? L_21 : L_19 ,
( V_25 & ( V_9 | V_10 | V_11 ) ) == 0 ? L_22 : L_19 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_181 * V_182 ;
if ( ! F_92 ( V_2 -> V_115 , L_23 , & V_182 ) )
F_93 ( V_182 , V_2 , F_89 ) ;
}
static int F_94 ( struct V_185 * V_108 )
{
struct V_1 * V_2 = V_108 -> V_186 ;
return F_66 ( V_2 ) ;
}
static int F_95 ( struct V_174 * V_115 ,
struct V_173 * V_125 ,
unsigned long V_131 ,
struct V_1 * * V_187 )
{
struct V_1 * V_2 ;
int V_102 ;
unsigned int V_58 ;
unsigned int V_188 ;
struct V_32 * V_32 ;
static struct V_189 V_147 = {
. V_190 = F_94 ,
} ;
static struct V_191 V_192 [ 2 ] = {
{ V_161 , 0 } ,
{ V_162 , 0x10 } ,
} ;
struct V_191 * V_129 ;
* V_187 = NULL ;
if ( ( V_102 = F_83 ( V_125 ) ) < 0 )
return V_102 ;
V_2 = F_96 ( sizeof( * V_2 ) , V_193 ) ;
if ( V_2 == NULL ) {
F_71 ( V_125 ) ;
return - V_194 ;
}
F_97 ( & V_2 -> V_61 ) ;
V_2 -> V_131 = V_131 ;
V_2 -> V_115 = V_115 ;
V_2 -> V_125 = V_125 ;
V_2 -> V_62 = - 1 ;
if ( ( V_102 = F_98 ( V_125 , V_115 -> V_123 ) ) < 0 ) {
F_72 ( V_2 ) ;
F_71 ( V_125 ) ;
return V_102 ;
}
if ( V_131 == V_134 ) {
V_2 -> V_4 = F_99 ( V_125 , 0 , 0 ) ;
goto V_195;
}
if ( F_100 ( V_125 , 2 ) & V_196 )
V_2 -> V_6 = F_99 ( V_125 , 2 , 0 ) ;
else
V_2 -> V_6 = F_99 ( V_125 , 0 , 0 ) ;
if ( ! V_2 -> V_6 ) {
F_20 ( V_16 L_24 ) ;
F_66 ( V_2 ) ;
return - V_12 ;
}
if ( F_100 ( V_125 , 3 ) & V_196 )
V_2 -> V_4 = F_99 ( V_125 , 3 , 0 ) ;
else
V_2 -> V_4 = F_99 ( V_125 , 1 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_20 ( V_16 L_25 ) ;
F_66 ( V_2 ) ;
return - V_12 ;
}
V_195:
if ( F_87 ( V_125 -> V_62 , F_29 , V_178 ,
V_179 , V_2 ) ) {
F_20 ( V_16 L_26 , V_125 -> V_62 ) ;
F_66 ( V_2 ) ;
return - V_17 ;
}
V_2 -> V_62 = V_125 -> V_62 ;
F_86 ( V_125 ) ;
F_101 ( V_2 -> V_62 ) ;
V_2 -> V_68 = 2 ;
V_129 = V_192 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_68 ; V_58 ++ ) {
V_32 = & V_2 -> V_69 [ V_58 ] ;
V_32 -> V_69 = V_58 ;
V_32 -> V_36 = V_129 [ V_58 ] . V_3 ;
V_32 -> V_67 = V_129 [ V_58 ] . V_67 ;
if ( V_131 == V_168 ) {
V_32 -> V_54 = V_197 ;
V_32 -> V_89 = V_198 ;
} else {
V_32 -> V_54 = V_198 ;
V_32 -> V_89 = V_197 ;
}
if ( V_131 == V_134 )
V_32 -> V_199 = ( V_32 -> V_36 - 0x40 ) / 0x10 ;
}
V_2 -> V_46 = ( V_131 == V_168 ) ? 0 : 1 ;
if ( F_102 ( V_124 , F_54 ( V_125 ) ,
V_2 -> V_68 * sizeof( T_2 ) * V_200 * 2 ,
& V_2 -> V_170 ) < 0 ) {
F_66 ( V_2 ) ;
return - V_194 ;
}
V_188 = 0 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_68 ; V_58 ++ ) {
V_32 = & V_2 -> V_69 [ V_58 ] ;
V_32 -> V_34 = ( ( T_2 * ) V_2 -> V_170 . V_171 ) + ( V_58 * V_200 * 2 ) ;
V_32 -> V_38 = V_2 -> V_170 . V_6 + ( V_58 * sizeof( T_2 ) * V_200 * 2 ) ;
V_188 |= V_32 -> V_67 ;
}
V_2 -> V_65 = V_201 ;
V_2 -> V_67 = V_188 ;
if ( ( V_102 = F_65 ( V_2 , 1 ) ) < 0 ) {
F_66 ( V_2 ) ;
return V_102 ;
}
if ( ( V_102 = F_103 ( V_115 , V_202 , V_2 , & V_147 ) ) < 0 ) {
F_66 ( V_2 ) ;
return V_102 ;
}
F_104 ( V_115 , & V_125 -> V_172 ) ;
* V_187 = V_2 ;
return 0 ;
}
static int F_105 ( struct V_173 * V_125 ,
const struct V_203 * V_204 )
{
struct V_174 * V_115 ;
struct V_1 * V_2 ;
int V_102 ;
struct V_205 * V_113 ;
V_102 = F_106 ( V_206 , V_207 , V_208 , 0 , & V_115 ) ;
if ( V_102 < 0 )
return V_102 ;
strcpy ( V_115 -> V_209 , L_27 ) ;
strcpy ( V_115 -> V_123 , L_6 ) ;
for ( V_113 = V_210 ; V_113 -> V_207 ; V_113 ++ ) {
if ( V_125 -> V_108 == V_113 -> V_207 ) {
strcpy ( V_115 -> V_123 , V_113 -> V_211 ) ;
break;
}
}
strcat ( V_115 -> V_123 , L_28 ) ;
if ( ( V_102 = F_95 ( V_115 , V_125 , V_204 -> V_212 , & V_2 ) ) < 0 ) {
F_107 ( V_115 ) ;
return V_102 ;
}
V_115 -> V_21 = V_2 ;
if ( ( V_102 = F_58 ( V_2 , V_141 ) ) < 0 ) {
F_107 ( V_115 ) ;
return V_102 ;
}
if ( ( V_102 = F_55 ( V_2 ) ) < 0 ) {
F_107 ( V_115 ) ;
return V_102 ;
}
F_91 ( V_2 ) ;
sprintf ( V_115 -> V_213 , L_29 ,
V_115 -> V_123 , V_2 -> V_62 ) ;
if ( ( V_102 = F_108 ( V_115 ) ) < 0 ) {
F_107 ( V_115 ) ;
return V_102 ;
}
F_109 ( V_125 , V_115 ) ;
return 0 ;
}
static void F_110 ( struct V_173 * V_125 )
{
F_107 ( F_111 ( V_125 ) ) ;
F_109 ( V_125 , NULL ) ;
}
