static int F_1 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_4 )
{
T_1 V_5 ;
unsigned long V_6 ;
V_3 ++ ;
do {
V_5 = V_7 | V_8 ;
V_2 -> V_9 =
F_2 ( V_5 , -- V_3 ) ;
} while ( V_2 -> V_9 == 0 && V_3 > V_4 );
if ( ! V_2 -> V_9 )
return - V_10 ;
V_2 -> V_11 = F_3 ( ( void * ) V_2 -> V_9 ) ;
V_2 -> V_12 = V_13 << V_3 ;
V_2 -> V_14 = V_3 ;
memset ( ( void * ) V_2 -> V_9 , 0x00 , V_2 -> V_12 ) ;
for ( V_6 = V_2 -> V_9 ; V_6 < V_2 -> V_9 + V_2 -> V_12 ; V_6 += V_13 ) {
F_4 ( F_5 ( V_6 ) ) ;
}
F_6 ( F_5 ( V_2 -> V_9 ) , V_2 -> V_12 >> V_15 ) ;
F_7 (KERN_DEBUG MODULE_NAME
L_1 ,
va->size, va->phys) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned long V_16 ;
if ( V_2 -> V_9 ) {
F_9 ( F_5 ( V_2 -> V_9 ) ,
V_2 -> V_12 >> V_15 ) ;
for ( V_16 = V_2 -> V_9 ; V_16 < V_2 -> V_9 + V_2 -> V_12 ;
V_16 += V_13 ) {
( void ) F_10 ( F_5 ( V_16 ) ) ;
}
F_7 (KERN_DEBUG MODULE_NAME
L_2 ,
va->size, va->phys) ;
F_11 ( V_2 -> V_9 , V_2 -> V_14 ) ;
V_2 -> V_9 = 0 ;
}
}
static void F_12 ( struct V_17 * V_18 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_18 -> V_19 ; ++ V_6 ) {
F_8 ( & V_18 -> V_20 [ V_6 ] ) ;
}
V_18 -> V_19 = 0 ;
}
static int F_13 ( struct V_17 * V_18 ,
T_2 V_21 ,
T_2 V_22 , T_2 V_23 )
{
int V_6 , V_16 ;
int V_14 ;
int V_24 ;
int V_25 ;
struct V_1 * V_2 ;
struct V_1 * V_26 ;
V_18 -> V_19 = 0 ;
for ( V_6 = 0 ; V_6 < V_27 ; ++ V_6 ) {
V_2 = & V_18 -> V_20 [ V_6 ] ;
V_14 = 0 ;
while ( V_21 > ( V_13 << V_14 ) && V_14 < V_28 )
V_14 ++ ;
V_25 = F_1 ( V_2 , V_14 , 0 ) ;
if ( V_25 )
break;
if ( V_6 == 0 ) {
V_18 -> V_29 = V_2 -> V_11 ;
V_18 -> V_30 = ( void V_31 * ) V_2 -> V_9 ;
V_18 -> V_32 = V_2 -> V_12 ;
V_18 -> V_19 = 1 ;
} else {
V_24 = 0 ;
for ( V_16 = 0 ; V_16 < V_6 ; ++ V_16 ) {
V_26 = & V_18 -> V_20 [ V_16 ] ;
if ( V_2 -> V_11 + V_2 -> V_12 == V_26 -> V_11 ||
V_26 -> V_11 + V_26 -> V_12 == V_2 -> V_11 ) {
V_24 = 1 ;
break;
}
}
if ( V_24 ) {
V_18 -> V_19 ++ ;
if ( V_2 -> V_11 < V_18 -> V_29 ) {
V_18 -> V_29 = V_2 -> V_11 ;
V_18 -> V_30 =
( void V_31 * ) V_2 -> V_9 ;
}
V_18 -> V_32 += V_2 -> V_12 ;
} else {
F_8 ( V_2 ) ;
break;
}
}
if ( V_21 < V_2 -> V_12 )
break;
else
V_21 -= V_2 -> V_12 ;
}
if ( V_18 -> V_32 > V_22 &&
V_18 -> V_32 > V_23 ) {
F_7 (KERN_DEBUG MODULE_NAME
L_3 ,
(unsigned long)vinfo->vram_contig_size,
(unsigned long)vinfo->vram_start) ;
return 0 ;
}
F_7 (KERN_ERR MODULE_NAME
L_4 ) ;
F_12 ( V_18 ) ;
return - V_10 ;
}
static int F_14 ( struct V_33 * V_34 )
{
F_15 ( & V_35 ) ;
V_34 -> V_36 = F_16 ( V_37 , V_38 , NULL ) ;
if ( ! V_34 -> V_36 ) {
F_17 ( & V_35 ) ;
return - V_39 ;
}
F_17 ( & V_35 ) ;
if ( F_18 ( V_34 -> V_36 ) < 0 )
return - V_39 ;
return 0 ;
}
static int F_19 ( struct V_17 * V_18 , unsigned long V_40 )
{
unsigned long V_41 ;
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_18 -> V_19 ; ++ V_6 ) {
V_41 = V_40 - ( V_18 -> V_20 [ V_6 ] . V_11 - V_18 -> V_29 ) ;
if ( V_41 < V_18 -> V_20 [ V_6 ] . V_12 ) {
return 0 ;
}
}
return - V_42 ;
}
static int F_20 ( struct V_33 * V_34 )
{
int V_25 ;
V_34 -> V_43 = F_21 ( V_34 -> V_44 , 0 ) ;
V_34 -> V_45 = F_22 ( V_34 -> V_44 , 0 ) ;
if ( ! F_23 ( V_34 -> V_43 , V_34 -> V_45 , L_5 ) ) {
F_7 (KERN_ERR MODULE_NAME
L_6 ) ;
return - V_46 ;
}
V_34 -> V_47 = F_24 ( V_34 -> V_43 , V_34 -> V_45 ) ;
if ( V_34 -> V_47 == NULL ) {
F_7 (KERN_ERR MODULE_NAME
L_7 ) ;
V_25 = - V_10 ;
goto V_48;
}
V_34 -> V_49 = F_21 ( V_34 -> V_36 , 0 ) ;
V_34 -> V_50 = F_22 ( V_34 -> V_36 , 0 ) ;
if ( ! F_23 ( V_34 -> V_49 , V_34 -> V_50 , L_5 ) ) {
F_7 (KERN_ERR MODULE_NAME L_8 ) ;
V_25 = - V_46 ;
goto V_51;
}
V_34 -> V_52 = F_24 ( V_34 -> V_49 , V_34 -> V_50 ) ;
if ( V_34 -> V_52 == NULL ) {
F_7 (KERN_ERR MODULE_NAME L_9 ) ;
V_25 = - V_10 ;
goto V_53;
}
return 0 ;
V_53:
F_25 ( V_34 -> V_49 , V_34 -> V_50 ) ;
V_51:
F_26 ( V_34 -> V_47 ) ;
V_48:
F_25 ( V_34 -> V_43 , V_34 -> V_45 ) ;
return V_25 ;
}
static void F_27 ( struct V_33 * V_34 )
{
F_26 ( V_34 -> V_52 ) ;
F_25 ( V_34 -> V_49 , V_34 -> V_50 ) ;
F_26 ( V_34 -> V_47 ) ;
F_25 ( V_34 -> V_43 , V_34 -> V_45 ) ;
}
static void F_28 ( struct V_33 * V_34 )
{
if ( F_29 ( & V_34 -> V_54 ) ) {
F_30 ( V_34 -> V_36 ) ;
F_30 ( V_34 -> V_44 ) ;
}
}
static void F_31 ( struct V_55 * V_56 )
{
struct V_57 * V_58 ;
struct V_17 * V_18 ;
struct V_33 * V_34 ;
V_58 = F_32 ( V_56 ) ;
if ( V_58 ) {
V_18 = F_33 ( V_58 , struct V_17 , V_58 ) ;
V_34 = V_18 -> V_34 ;
F_15 ( & V_35 ) ;
F_34 ( V_58 ) ;
F_35 ( & V_58 -> V_59 ) ;
F_12 ( V_18 ) ;
F_27 ( V_34 ) ;
F_28 ( V_34 ) ;
F_36 ( V_18 ) ;
F_36 ( V_34 ) ;
F_17 ( & V_35 ) ;
}
}
static void F_37 ( struct V_60 * V_61 )
{
switch ( V_61 -> V_62 ) {
case 16 :
V_61 -> V_63 . V_40 = 0 ;
V_61 -> V_63 . V_64 = 5 ;
V_61 -> V_65 . V_40 = 5 ;
V_61 -> V_65 . V_64 = 5 ;
V_61 -> V_66 . V_40 = 10 ;
V_61 -> V_66 . V_64 = 5 ;
V_61 -> V_67 . V_40 = 15 ;
V_61 -> V_67 . V_64 = 1 ;
break;
case 32 :
V_61 -> V_63 . V_40 = 0 ;
V_61 -> V_63 . V_64 = 8 ;
V_61 -> V_65 . V_40 = 8 ;
V_61 -> V_65 . V_64 = 8 ;
V_61 -> V_66 . V_40 = 16 ;
V_61 -> V_66 . V_64 = 8 ;
V_61 -> V_67 . V_40 = 24 ;
V_61 -> V_67 . V_64 = 0 ;
break;
default:
break;
}
V_61 -> V_63 . V_68 = V_61 -> V_65 . V_68 =
V_61 -> V_66 . V_68 = V_61 -> V_67 . V_68 = 0 ;
}
static int F_38 ( struct V_55 * V_56 , const struct V_69 * V_70 )
{
struct V_17 * V_18 ;
struct V_57 * V_58 ;
struct V_33 * V_34 ;
int V_25 = 0 ;
V_34 = F_39 ( sizeof( * V_34 ) , V_71 ) ;
if ( V_34 == NULL )
return - V_10 ;
V_18 = F_39 ( sizeof( * V_18 ) , V_71 ) ;
if ( V_18 == NULL ) {
V_25 = - V_10 ;
goto V_48;
}
V_18 -> V_34 = V_34 ;
V_34 -> V_44 = V_56 ;
F_40 ( & V_34 -> V_54 , 1 ) ;
switch ( V_70 -> V_72 ) {
case V_73 :
if ( ( V_25 = F_14 ( V_34 ) ) )
goto V_51;
F_41 ( V_56 , & V_18 -> V_58 ) ;
break;
default:
V_25 = - V_39 ;
goto V_51;
}
V_58 = & V_18 -> V_58 ;
V_58 -> V_5 = V_74 | V_75 ;
V_25 = F_20 ( V_34 ) ;
if ( V_25 )
goto V_53;
V_25 = F_13 ( V_18 , V_76 ,
V_77 , V_78 ) ;
if ( V_25 )
goto V_79;
strcpy ( V_58 -> V_80 . V_70 , L_10 ) ;
V_58 -> V_80 . V_81 = 0 ;
V_58 -> V_80 . V_82 = 0 ;
V_58 -> V_80 . V_83 = V_18 -> V_29 ;
V_58 -> V_80 . V_84 = V_18 -> V_32 ;
V_58 -> V_80 . type = V_85 ;
V_58 -> V_80 . V_86 = V_87 ;
V_58 -> V_80 . V_88 = 1 ;
V_58 -> V_80 . V_89 = 1 ;
V_58 -> V_80 . V_90 = 0 ;
V_58 -> V_80 . V_91 = V_92 ;
V_58 -> V_93 = V_18 -> V_30 ;
V_58 -> V_94 = V_18 -> V_94 ;
V_58 -> V_34 = V_34 ;
V_58 -> V_95 = & V_96 ;
V_58 -> V_72 = & V_56 -> V_56 ;
F_42 ( & V_18 -> V_97 ) ;
V_18 -> V_98 = 1 ;
V_18 -> V_99 = V_100 ;
V_58 -> V_61 . V_101 = 0 ;
V_58 -> V_61 . V_62 = 16 ;
F_37 ( & V_58 -> V_61 ) ;
if ( ! F_43
( & V_58 -> V_61 , V_58 , V_102 , NULL , 0 , & V_103 , 16 ) ) {
F_7 (KERN_ERR MODULE_NAME L_11 ) ;
}
if ( F_44 ( & V_58 -> V_59 , 256 , 1 ) < 0 ) {
V_25 = - V_10 ;
goto V_104;
}
V_25 = F_45 ( V_58 ) ;
if ( V_25 ) {
F_7 (KERN_ERR MODULE_NAME L_12 ) ;
goto V_105;
}
F_7 ( L_13 ) ;
return 0 ;
V_105:
F_35 ( & V_58 -> V_59 ) ;
V_104:
F_12 ( V_18 ) ;
V_79:
F_27 ( V_34 ) ;
V_53:
F_28 ( V_34 ) ;
V_51:
F_36 ( V_18 ) ;
V_48:
F_36 ( V_34 ) ;
return V_25 ;
}
static int F_46 ( struct V_57 * V_58 , int V_106 )
{
return 0 ;
}
static int F_47 ( struct V_57 * V_58 , int V_106 )
{
return 0 ;
}
static int F_48 ( int clock )
{
int V_6 ;
int V_107 ;
int V_108 ;
int V_109 ;
V_107 = 0 ;
V_108 = clock - V_110 [ 0 ] ;
V_108 = ( V_108 < 0 ) ? - V_108 : V_108 ;
for ( V_6 = 1 ; V_6 < V_111 ; ++ V_6 ) {
V_109 = clock - V_110 [ V_6 ] ;
V_109 = ( V_109 < 0 ) ? - V_109 : V_109 ;
if ( V_109 < V_108 ) {
V_107 = V_6 ;
V_108 = V_109 ;
}
}
return V_110 [ V_107 ] ;
}
static int F_49 ( struct V_60 * V_61 ,
struct V_17 * V_18 )
{
T_3 V_112 ;
T_4 V_113 ;
int V_114 ;
int clock ;
int V_115 ;
struct V_60 V_116 ;
V_116 = * V_61 ;
clock = F_50 ( V_61 -> V_117 ) ;
if ( V_118 && V_118 -> V_114 ) {
V_114 = V_118 -> V_114 ( V_118 , clock ) ;
} else {
V_114 = F_48 ( clock ) ;
}
V_115 = V_114 - clock ;
V_115 = ( V_115 < 0 ) ? - V_115 : V_115 ;
if ( V_115 > clock / 5 ) {
#if 0
printk(KERN_DEBUG MODULE_NAME ": Diff failure. %d %d\n",clock_diff,clock);
#endif
return - V_42 ;
}
V_116 . V_117 = F_51 ( V_114 ) ;
if ( V_61 -> V_119 > V_120 || V_61 -> V_121 > V_122 ) {
F_7 (KERN_DEBUG MODULE_NAME L_14 ) ;
return - V_42 ;
}
if ( V_61 -> V_123 > V_124 ) {
F_7 (KERN_DEBUG MODULE_NAME
L_15 ) ;
return - V_42 ;
}
switch ( V_116 . V_62 ) {
case 0 ... 16 :
V_116 . V_62 = 16 ;
break;
case 17 ... 32 :
V_116 . V_62 = 32 ;
break;
default:
F_7 (KERN_DEBUG MODULE_NAME L_16 ,
var->bits_per_pixel) ;
return - V_42 ;
}
V_112 = F_52 ( ( V_61 -> V_119 * V_61 -> V_62 ) >> 3 , 0x40 ) ;
V_113 = V_112 * V_61 -> V_125 ;
if ( V_113 > V_18 -> V_32 ) {
return - V_10 ;
}
switch ( V_116 . V_62 ) {
case 16 :
if ( V_61 -> V_63 . V_40 != 0 ||
V_61 -> V_63 . V_64 != 5 ||
V_61 -> V_65 . V_40 != 5 ||
V_61 -> V_65 . V_64 != 5 ||
V_61 -> V_66 . V_40 != 10 ||
V_61 -> V_66 . V_64 != 5 ||
V_61 -> V_67 . V_40 != 15 || V_61 -> V_67 . V_64 != 1 ) {
F_37 ( & V_116 ) ;
}
break;
case 32 :
if ( V_61 -> V_63 . V_40 != 0 ||
V_61 -> V_63 . V_64 != 8 ||
V_61 -> V_65 . V_40 != 8 ||
V_61 -> V_65 . V_64 != 8 ||
V_61 -> V_66 . V_40 != 16 ||
V_61 -> V_66 . V_64 != 8 ||
( V_61 -> V_67 . V_64 != 0 && V_61 -> V_67 . V_64 != 8 ) ||
( V_61 -> V_67 . V_64 == 8 && V_61 -> V_67 . V_40 != 24 ) ) {
F_37 ( & V_116 ) ;
}
break;
default:
return - V_42 ;
}
* V_61 = V_116 ;
return 0 ;
}
static int F_53 ( struct V_60 * V_61 , struct V_57 * V_58 )
{
struct V_17 * V_18 = F_33 ( V_58 , struct V_17 , V_58 ) ;
int V_126 ;
F_15 ( & V_35 ) ;
V_126 = F_49 ( V_61 , V_18 ) ;
F_17 ( & V_35 ) ;
return V_126 ;
}
static void F_54 ( struct V_17 * V_18 )
{
F_55 ( 20 ) ;
}
static void F_56 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = V_18 -> V_34 ;
F_57 ( V_34 , V_127 , 0 ) ;
while ( ! ( F_58 ( V_34 , V_127 ) & V_128 ) ) ;
F_57 ( V_34 , V_129 ,
F_58 ( V_34 , V_129 ) & ~ V_130 ) ;
( void ) F_58 ( V_34 , V_129 ) ;
F_54 ( V_18 ) ;
F_57 ( V_34 , V_131 , 0 ) ;
( void ) F_58 ( V_34 , V_131 ) ;
V_18 -> V_98 = 1 ;
}
static void F_59 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = V_18 -> V_34 ;
F_7 (KERN_DEBUG MODULE_NAME L_17 ) ;
F_7 (KERN_DEBUG MODULE_NAME L_18 ,
(unsigned)VML_READ32(par, VML_HTOTAL_A)) ;
F_7 (KERN_DEBUG MODULE_NAME L_19 ,
(unsigned)VML_READ32(par, VML_HBLANK_A)) ;
F_7 (KERN_DEBUG MODULE_NAME L_20 ,
(unsigned)VML_READ32(par, VML_HSYNC_A)) ;
F_7 (KERN_DEBUG MODULE_NAME L_21 ,
(unsigned)VML_READ32(par, VML_VTOTAL_A)) ;
F_7 (KERN_DEBUG MODULE_NAME L_22 ,
(unsigned)VML_READ32(par, VML_VBLANK_A)) ;
F_7 (KERN_DEBUG MODULE_NAME L_23 ,
(unsigned)VML_READ32(par, VML_VSYNC_A)) ;
F_7 (KERN_DEBUG MODULE_NAME L_24 ,
(unsigned)VML_READ32(par, VML_DSPCSTRIDE)) ;
F_7 (KERN_DEBUG MODULE_NAME L_25 ,
(unsigned)VML_READ32(par, VML_DSPCSIZE)) ;
F_7 (KERN_DEBUG MODULE_NAME L_26 ,
(unsigned)VML_READ32(par, VML_DSPCPOS)) ;
F_7 (KERN_DEBUG MODULE_NAME L_27 ,
(unsigned)VML_READ32(par, VML_DSPARB)) ;
F_7 (KERN_DEBUG MODULE_NAME L_28 ,
(unsigned)VML_READ32(par, VML_DSPCADDR)) ;
F_7 (KERN_DEBUG MODULE_NAME L_29 ,
(unsigned)VML_READ32(par, VML_BCLRPAT_A)) ;
F_7 (KERN_DEBUG MODULE_NAME L_30 ,
(unsigned)VML_READ32(par, VML_CANVSCLR_A)) ;
F_7 (KERN_DEBUG MODULE_NAME L_31 ,
(unsigned)VML_READ32(par, VML_PIPEASRC)) ;
F_7 (KERN_DEBUG MODULE_NAME L_32 ,
(unsigned)VML_READ32(par, VML_PIPEACONF)) ;
F_7 (KERN_DEBUG MODULE_NAME L_33 ,
(unsigned)VML_READ32(par, VML_DSPCCNTR)) ;
F_7 (KERN_DEBUG MODULE_NAME L_34 ,
(unsigned)VML_READ32(par, VML_RCOMPSTAT)) ;
F_7 (KERN_DEBUG MODULE_NAME L_35 ) ;
}
static int F_60 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = V_18 -> V_34 ;
struct V_57 * V_58 = & V_18 -> V_58 ;
struct V_60 * V_61 = & V_58 -> V_61 ;
T_3 V_132 , V_133 , V_134 , V_135 , V_136 , V_137 ;
T_3 V_138 , V_139 , V_140 , V_141 , V_142 , V_143 ;
T_3 V_144 ;
int clock ;
V_18 -> V_145 = V_61 -> V_62 >> 3 ;
V_18 -> V_146 = F_52 ( V_61 -> V_123 * V_18 -> V_145 , 0x40 ) ;
V_58 -> V_80 . V_147 = V_18 -> V_146 ;
if ( ! V_118 )
return 0 ;
V_132 =
V_61 -> V_119 + V_61 -> V_148 + V_61 -> V_149 + V_61 -> V_150 ;
V_133 = V_61 -> V_119 ;
V_134 = V_61 -> V_119 ;
V_135 = V_132 ;
V_136 = V_133 + V_61 -> V_148 ;
V_137 = V_136 + V_61 -> V_149 ;
V_138 =
V_61 -> V_121 + V_61 -> V_151 + V_61 -> V_152 + V_61 -> V_153 ;
V_139 = V_61 -> V_121 ;
V_140 = V_61 -> V_121 ;
V_141 = V_138 ;
V_142 = V_139 + V_61 -> V_151 ;
V_143 = V_142 + V_61 -> V_152 ;
V_144 = V_130 | V_154 ;
clock = F_50 ( V_61 -> V_117 ) ;
if ( V_118 -> V_114 ) {
clock = V_118 -> V_114 ( V_118 , clock ) ;
} else {
clock = F_48 ( clock ) ;
}
F_7 (KERN_DEBUG MODULE_NAME
L_36 , clock / htotal,
((clock / htotal) * 1000) / vtotal) ;
switch ( V_61 -> V_62 ) {
case 16 :
V_144 |= V_155 ;
break;
case 32 :
if ( V_61 -> V_67 . V_64 == 8 )
V_144 |= V_156 | V_157 ;
else
V_144 |= V_158 ;
break;
default:
return - V_42 ;
}
F_56 ( V_18 ) ;
F_61 () ;
if ( V_118 -> V_159 )
V_118 -> V_159 ( V_118 , clock ) ;
else
return - V_42 ;
F_57 ( V_34 , V_160 , ( ( V_132 - 1 ) << 16 ) | ( V_133 - 1 ) ) ;
F_57 ( V_34 , V_161 ,
( ( V_135 - 1 ) << 16 ) | ( V_134 - 1 ) ) ;
F_57 ( V_34 , V_162 ,
( ( V_137 - 1 ) << 16 ) | ( V_136 - 1 ) ) ;
F_57 ( V_34 , V_163 , ( ( V_138 - 1 ) << 16 ) | ( V_139 - 1 ) ) ;
F_57 ( V_34 , V_164 ,
( ( V_141 - 1 ) << 16 ) | ( V_140 - 1 ) ) ;
F_57 ( V_34 , V_165 ,
( ( V_143 - 1 ) << 16 ) | ( V_142 - 1 ) ) ;
F_57 ( V_34 , V_166 , V_18 -> V_146 ) ;
F_57 ( V_34 , V_167 ,
( ( V_61 -> V_121 - 1 ) << 16 ) | ( V_61 -> V_119 - 1 ) ) ;
F_57 ( V_34 , V_168 , 0x00000000 ) ;
F_57 ( V_34 , V_169 , V_170 ) ;
F_57 ( V_34 , V_171 , 0x00000000 ) ;
F_57 ( V_34 , V_172 , 0x00000000 ) ;
F_57 ( V_34 , V_173 ,
( ( V_61 -> V_119 - 1 ) << 16 ) | ( V_61 -> V_121 - 1 ) ) ;
F_62 () ;
F_57 ( V_34 , V_131 , V_174 ) ;
F_62 () ;
F_57 ( V_34 , V_129 , V_144 ) ;
F_62 () ;
F_57 ( V_34 , V_175 , ( T_3 ) V_18 -> V_29 +
V_61 -> V_176 * V_18 -> V_146 +
V_61 -> V_177 * V_18 -> V_145 ) ;
F_57 ( V_34 , V_127 , V_178 ) ;
while ( ! ( F_58 ( V_34 , V_127 ) &
( V_128 | V_178 ) ) ) ;
V_18 -> V_98 = 0 ;
#ifdef F_63
F_59 ( V_18 ) ;
#endif
return 0 ;
}
static int F_64 ( struct V_57 * V_58 )
{
struct V_17 * V_18 = F_33 ( V_58 , struct V_17 , V_58 ) ;
int V_126 ;
F_15 ( & V_35 ) ;
F_65 ( & V_18 -> V_97 , ( V_118 ) ? & V_179 : & V_180 ) ;
V_126 = F_60 ( V_18 ) ;
F_17 ( & V_35 ) ;
return V_126 ;
}
static int F_66 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = V_18 -> V_34 ;
T_3 V_181 = F_58 ( V_34 , V_131 ) ;
switch ( V_18 -> V_99 ) {
case V_100 :
if ( V_18 -> V_98 ) {
F_60 ( V_18 ) ;
}
F_57 ( V_34 , V_131 , V_181 & ~ V_182 ) ;
( void ) F_58 ( V_34 , V_131 ) ;
break;
case V_183 :
if ( V_18 -> V_98 ) {
F_60 ( V_18 ) ;
}
F_57 ( V_34 , V_131 , V_181 | V_182 ) ;
( void ) F_58 ( V_34 , V_131 ) ;
break;
case V_184 :
case V_185 :
if ( ! V_18 -> V_98 ) {
F_56 ( V_18 ) ;
}
break;
case V_186 :
if ( ! V_18 -> V_98 ) {
F_56 ( V_18 ) ;
}
break;
default:
return - V_42 ;
}
return 0 ;
}
static int F_67 ( int V_187 , struct V_57 * V_58 )
{
struct V_17 * V_18 = F_33 ( V_58 , struct V_17 , V_58 ) ;
int V_126 ;
F_15 ( & V_35 ) ;
V_18 -> V_99 = V_187 ;
V_126 = F_66 ( V_18 ) ;
F_17 ( & V_35 ) ;
return V_126 ;
}
static int F_68 ( struct V_60 * V_61 ,
struct V_57 * V_58 )
{
struct V_17 * V_18 = F_33 ( V_58 , struct V_17 , V_58 ) ;
struct V_33 * V_34 = V_18 -> V_34 ;
F_15 ( & V_35 ) ;
F_57 ( V_34 , V_175 , ( T_3 ) V_18 -> V_29 +
V_61 -> V_176 * V_18 -> V_146 +
V_61 -> V_177 * V_18 -> V_145 ) ;
( void ) F_58 ( V_34 , V_175 ) ;
F_17 ( & V_35 ) ;
return 0 ;
}
static int F_69 ( T_5 V_188 , T_5 V_66 , T_5 V_65 , T_5 V_63 ,
T_5 V_67 , struct V_57 * V_58 )
{
T_3 V_116 ;
if ( V_188 >= 16 )
return - V_42 ;
if ( V_58 -> V_61 . V_101 ) {
V_66 = V_65 = V_63 = ( V_66 * 77 + V_65 * 151 + V_63 * 28 ) >> 8 ;
}
if ( V_58 -> V_80 . V_86 != V_87 )
return - V_42 ;
V_66 = F_70 ( V_66 , V_58 -> V_61 . V_66 . V_64 ) ;
V_63 = F_70 ( V_63 , V_58 -> V_61 . V_63 . V_64 ) ;
V_65 = F_70 ( V_65 , V_58 -> V_61 . V_65 . V_64 ) ;
V_67 = F_70 ( V_67 , V_58 -> V_61 . V_67 . V_64 ) ;
V_116 = ( V_66 << V_58 -> V_61 . V_66 . V_40 ) |
( V_65 << V_58 -> V_61 . V_65 . V_40 ) |
( V_63 << V_58 -> V_61 . V_63 . V_40 ) |
( V_67 << V_58 -> V_61 . V_67 . V_40 ) ;
switch ( V_58 -> V_61 . V_62 ) {
case 16 :
( ( T_3 * ) V_58 -> V_94 ) [ V_188 ] = V_116 ;
break;
case 24 :
case 32 :
( ( T_3 * ) V_58 -> V_94 ) [ V_188 ] = V_116 ;
break;
}
return 0 ;
}
static int F_71 ( struct V_57 * V_58 , struct V_189 * V_190 )
{
struct V_17 * V_18 = F_33 ( V_58 , struct V_17 , V_58 ) ;
unsigned long V_40 = V_190 -> V_191 << V_15 ;
int V_126 ;
V_126 = F_19 ( V_18 , V_40 ) ;
if ( V_126 )
return - V_42 ;
F_72 ( V_190 -> V_192 ) |= V_193 ;
F_72 ( V_190 -> V_192 ) &= ~ V_194 ;
return F_73 ( V_190 , V_18 -> V_29 ,
V_18 -> V_32 ) ;
}
static int F_74 ( struct V_57 * V_58 )
{
return 0 ;
}
static int F_75 ( struct V_57 * V_58 , struct V_195 * V_196 )
{
return - V_42 ;
}
static void T_6 F_76 ( void )
{
F_77 ( & V_197 ) ;
}
static int T_7 F_78 ( void )
{
#ifndef F_79
char * V_198 = NULL ;
if ( F_80 ( V_199 , & V_198 ) )
return - V_39 ;
#endif
F_7 (KERN_DEBUG MODULE_NAME L_37 ) ;
F_81 ( & V_35 ) ;
F_42 ( & V_180 ) ;
F_42 ( & V_179 ) ;
return F_82 ( & V_197 ) ;
}
int F_83 ( struct V_200 * V_201 )
{
struct V_17 * V_202 ;
struct V_203 * V_204 ;
T_3 V_205 ;
F_15 ( & V_35 ) ;
if ( V_118 != NULL ) {
V_118 -> V_206 ( V_118 ) ;
}
V_118 = V_201 ;
V_118 -> V_207 ( V_118 ) ;
V_204 = V_180 . V_208 ;
while ( V_204 != & V_180 ) {
F_84 ( V_204 ) ;
V_202 = F_85 ( V_204 , struct V_17 , V_97 ) ;
if ( ! F_49 ( & V_202 -> V_58 . V_61 , V_202 ) ) {
F_60 ( V_202 ) ;
F_86 ( V_204 , & V_179 ) ;
} else {
F_17 ( & V_35 ) ;
V_205 = V_202 -> V_58 . V_61 . V_209 ;
V_202 -> V_58 . V_61 . V_62 = 16 ;
F_37 ( & V_202 -> V_58 . V_61 ) ;
if ( F_43 ( & V_202 -> V_58 . V_61 ,
& V_202 -> V_58 ,
V_102 , NULL , 0 , NULL , 16 ) ) {
V_202 -> V_58 . V_61 . V_209 |=
V_210 | V_211 ;
F_87 ( & V_202 -> V_58 , & V_202 -> V_58 . V_61 ) ;
} else {
F_7 (KERN_ERR MODULE_NAME
L_38 ) ;
}
V_202 -> V_58 . V_61 . V_209 = V_205 ;
F_15 ( & V_35 ) ;
}
F_66 ( V_202 ) ;
V_204 = V_180 . V_208 ;
}
F_17 ( & V_35 ) ;
F_7 (KERN_DEBUG MODULE_NAME L_39 ,
subsys->name ? subsys->name : L_40 ) ;
return 0 ;
}
void F_88 ( struct V_200 * V_201 )
{
struct V_17 * V_202 , * V_208 ;
F_15 ( & V_35 ) ;
if ( V_118 != V_201 ) {
F_17 ( & V_35 ) ;
return;
}
V_118 -> V_206 ( V_118 ) ;
V_118 = NULL ;
F_89 (entry, next, &global_has_mode, head) {
F_7 (KERN_DEBUG MODULE_NAME L_41 ) ;
F_56 ( V_202 ) ;
F_90 ( & V_202 -> V_97 , & V_180 ) ;
}
F_17 ( & V_35 ) ;
}
