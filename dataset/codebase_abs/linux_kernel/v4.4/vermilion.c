static int F_1 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_4 )
{
T_1 V_5 ;
unsigned long V_6 ;
V_3 ++ ;
do {
V_5 = V_7 | V_8 | V_9 ;
V_2 -> V_10 =
F_2 ( V_5 , -- V_3 ) ;
} while ( V_2 -> V_10 == 0 && V_3 > V_4 );
if ( ! V_2 -> V_10 )
return - V_11 ;
V_2 -> V_12 = F_3 ( ( void * ) V_2 -> V_10 ) ;
V_2 -> V_13 = V_14 << V_3 ;
V_2 -> V_15 = V_3 ;
memset ( ( void * ) V_2 -> V_10 , 0x00 , V_2 -> V_13 ) ;
for ( V_6 = V_2 -> V_10 ; V_6 < V_2 -> V_10 + V_2 -> V_13 ; V_6 += V_14 ) {
F_4 ( F_5 ( V_6 ) ) ;
}
F_6 ( F_5 ( V_2 -> V_10 ) , V_2 -> V_13 >> V_16 ) ;
F_7 (KERN_DEBUG MODULE_NAME
L_1 ,
va->size, va->phys) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned long V_17 ;
if ( V_2 -> V_10 ) {
F_9 ( F_5 ( V_2 -> V_10 ) ,
V_2 -> V_13 >> V_16 ) ;
for ( V_17 = V_2 -> V_10 ; V_17 < V_2 -> V_10 + V_2 -> V_13 ;
V_17 += V_14 ) {
( void ) F_10 ( F_5 ( V_17 ) ) ;
}
F_7 (KERN_DEBUG MODULE_NAME
L_2 ,
va->size, va->phys) ;
F_11 ( V_2 -> V_10 , V_2 -> V_15 ) ;
V_2 -> V_10 = 0 ;
}
}
static void F_12 ( struct V_18 * V_19 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_19 -> V_20 ; ++ V_6 ) {
F_8 ( & V_19 -> V_21 [ V_6 ] ) ;
}
V_19 -> V_20 = 0 ;
}
static int F_13 ( struct V_18 * V_19 ,
T_2 V_22 ,
T_2 V_23 , T_2 V_24 )
{
int V_6 , V_17 ;
int V_15 ;
int V_25 ;
int V_26 ;
struct V_1 * V_2 ;
struct V_1 * V_27 ;
V_19 -> V_20 = 0 ;
for ( V_6 = 0 ; V_6 < V_28 ; ++ V_6 ) {
V_2 = & V_19 -> V_21 [ V_6 ] ;
V_15 = 0 ;
while ( V_22 > ( V_14 << V_15 ) && V_15 < V_29 )
V_15 ++ ;
V_26 = F_1 ( V_2 , V_15 , 0 ) ;
if ( V_26 )
break;
if ( V_6 == 0 ) {
V_19 -> V_30 = V_2 -> V_12 ;
V_19 -> V_31 = ( void V_32 * ) V_2 -> V_10 ;
V_19 -> V_33 = V_2 -> V_13 ;
V_19 -> V_20 = 1 ;
} else {
V_25 = 0 ;
for ( V_17 = 0 ; V_17 < V_6 ; ++ V_17 ) {
V_27 = & V_19 -> V_21 [ V_17 ] ;
if ( V_2 -> V_12 + V_2 -> V_13 == V_27 -> V_12 ||
V_27 -> V_12 + V_27 -> V_13 == V_2 -> V_12 ) {
V_25 = 1 ;
break;
}
}
if ( V_25 ) {
V_19 -> V_20 ++ ;
if ( V_2 -> V_12 < V_19 -> V_30 ) {
V_19 -> V_30 = V_2 -> V_12 ;
V_19 -> V_31 =
( void V_32 * ) V_2 -> V_10 ;
}
V_19 -> V_33 += V_2 -> V_13 ;
} else {
F_8 ( V_2 ) ;
break;
}
}
if ( V_22 < V_2 -> V_13 )
break;
else
V_22 -= V_2 -> V_13 ;
}
if ( V_19 -> V_33 > V_23 &&
V_19 -> V_33 > V_24 ) {
F_7 (KERN_DEBUG MODULE_NAME
L_3 ,
(unsigned long)vinfo->vram_contig_size,
(unsigned long)vinfo->vram_start) ;
return 0 ;
}
F_7 (KERN_ERR MODULE_NAME
L_4 ) ;
F_12 ( V_19 ) ;
return - V_11 ;
}
static int F_14 ( struct V_34 * V_35 )
{
F_15 ( & V_36 ) ;
V_35 -> V_37 = F_16 ( V_38 , V_39 , NULL ) ;
if ( ! V_35 -> V_37 ) {
F_17 ( & V_36 ) ;
return - V_40 ;
}
F_17 ( & V_36 ) ;
if ( F_18 ( V_35 -> V_37 ) < 0 )
return - V_40 ;
return 0 ;
}
static int F_19 ( struct V_18 * V_19 , unsigned long V_41 )
{
unsigned long V_42 ;
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_19 -> V_20 ; ++ V_6 ) {
V_42 = V_41 - ( V_19 -> V_21 [ V_6 ] . V_12 - V_19 -> V_30 ) ;
if ( V_42 < V_19 -> V_21 [ V_6 ] . V_13 ) {
return 0 ;
}
}
return - V_43 ;
}
static int F_20 ( struct V_34 * V_35 )
{
int V_26 ;
V_35 -> V_44 = F_21 ( V_35 -> V_45 , 0 ) ;
V_35 -> V_46 = F_22 ( V_35 -> V_45 , 0 ) ;
if ( ! F_23 ( V_35 -> V_44 , V_35 -> V_46 , L_5 ) ) {
F_7 (KERN_ERR MODULE_NAME
L_6 ) ;
return - V_47 ;
}
V_35 -> V_48 = F_24 ( V_35 -> V_44 , V_35 -> V_46 ) ;
if ( V_35 -> V_48 == NULL ) {
F_7 (KERN_ERR MODULE_NAME
L_7 ) ;
V_26 = - V_11 ;
goto V_49;
}
V_35 -> V_50 = F_21 ( V_35 -> V_37 , 0 ) ;
V_35 -> V_51 = F_22 ( V_35 -> V_37 , 0 ) ;
if ( ! F_23 ( V_35 -> V_50 , V_35 -> V_51 , L_5 ) ) {
F_7 (KERN_ERR MODULE_NAME L_8 ) ;
V_26 = - V_47 ;
goto V_52;
}
V_35 -> V_53 = F_24 ( V_35 -> V_50 , V_35 -> V_51 ) ;
if ( V_35 -> V_53 == NULL ) {
F_7 (KERN_ERR MODULE_NAME L_9 ) ;
V_26 = - V_11 ;
goto V_54;
}
return 0 ;
V_54:
F_25 ( V_35 -> V_50 , V_35 -> V_51 ) ;
V_52:
F_26 ( V_35 -> V_48 ) ;
V_49:
F_25 ( V_35 -> V_44 , V_35 -> V_46 ) ;
return V_26 ;
}
static void F_27 ( struct V_34 * V_35 )
{
F_26 ( V_35 -> V_53 ) ;
F_25 ( V_35 -> V_50 , V_35 -> V_51 ) ;
F_26 ( V_35 -> V_48 ) ;
F_25 ( V_35 -> V_44 , V_35 -> V_46 ) ;
}
static void F_28 ( struct V_34 * V_35 )
{
if ( F_29 ( & V_35 -> V_55 ) ) {
F_30 ( V_35 -> V_37 ) ;
F_30 ( V_35 -> V_45 ) ;
}
}
static void F_31 ( struct V_56 * V_57 )
{
struct V_58 * V_59 ;
struct V_18 * V_19 ;
struct V_34 * V_35 ;
V_59 = F_32 ( V_57 ) ;
if ( V_59 ) {
V_19 = F_33 ( V_59 , struct V_18 , V_59 ) ;
V_35 = V_19 -> V_35 ;
F_15 ( & V_36 ) ;
F_34 ( V_59 ) ;
F_35 ( & V_59 -> V_60 ) ;
F_12 ( V_19 ) ;
F_27 ( V_35 ) ;
F_28 ( V_35 ) ;
F_36 ( V_19 ) ;
F_36 ( V_35 ) ;
F_17 ( & V_36 ) ;
}
}
static void F_37 ( struct V_61 * V_62 )
{
switch ( V_62 -> V_63 ) {
case 16 :
V_62 -> V_64 . V_41 = 0 ;
V_62 -> V_64 . V_65 = 5 ;
V_62 -> V_66 . V_41 = 5 ;
V_62 -> V_66 . V_65 = 5 ;
V_62 -> V_67 . V_41 = 10 ;
V_62 -> V_67 . V_65 = 5 ;
V_62 -> V_68 . V_41 = 15 ;
V_62 -> V_68 . V_65 = 1 ;
break;
case 32 :
V_62 -> V_64 . V_41 = 0 ;
V_62 -> V_64 . V_65 = 8 ;
V_62 -> V_66 . V_41 = 8 ;
V_62 -> V_66 . V_65 = 8 ;
V_62 -> V_67 . V_41 = 16 ;
V_62 -> V_67 . V_65 = 8 ;
V_62 -> V_68 . V_41 = 24 ;
V_62 -> V_68 . V_65 = 0 ;
break;
default:
break;
}
V_62 -> V_64 . V_69 = V_62 -> V_66 . V_69 =
V_62 -> V_67 . V_69 = V_62 -> V_68 . V_69 = 0 ;
}
static int F_38 ( struct V_56 * V_57 , const struct V_70 * V_71 )
{
struct V_18 * V_19 ;
struct V_58 * V_59 ;
struct V_34 * V_35 ;
int V_26 = 0 ;
V_35 = F_39 ( sizeof( * V_35 ) , V_72 ) ;
if ( V_35 == NULL )
return - V_11 ;
V_19 = F_39 ( sizeof( * V_19 ) , V_72 ) ;
if ( V_19 == NULL ) {
V_26 = - V_11 ;
goto V_49;
}
V_19 -> V_35 = V_35 ;
V_35 -> V_45 = V_57 ;
F_40 ( & V_35 -> V_55 , 1 ) ;
switch ( V_71 -> V_73 ) {
case V_74 :
if ( ( V_26 = F_14 ( V_35 ) ) )
goto V_52;
F_41 ( V_57 , & V_19 -> V_59 ) ;
break;
default:
V_26 = - V_40 ;
goto V_52;
}
V_59 = & V_19 -> V_59 ;
V_59 -> V_5 = V_75 | V_76 ;
V_26 = F_20 ( V_35 ) ;
if ( V_26 )
goto V_54;
V_26 = F_13 ( V_19 , V_77 ,
V_78 , V_79 ) ;
if ( V_26 )
goto V_80;
strcpy ( V_59 -> V_81 . V_71 , L_10 ) ;
V_59 -> V_81 . V_82 = 0 ;
V_59 -> V_81 . V_83 = 0 ;
V_59 -> V_81 . V_84 = V_19 -> V_30 ;
V_59 -> V_81 . V_85 = V_19 -> V_33 ;
V_59 -> V_81 . type = V_86 ;
V_59 -> V_81 . V_87 = V_88 ;
V_59 -> V_81 . V_89 = 1 ;
V_59 -> V_81 . V_90 = 1 ;
V_59 -> V_81 . V_91 = 0 ;
V_59 -> V_81 . V_92 = V_93 ;
V_59 -> V_94 = V_19 -> V_31 ;
V_59 -> V_95 = V_19 -> V_95 ;
V_59 -> V_35 = V_35 ;
V_59 -> V_96 = & V_97 ;
V_59 -> V_73 = & V_57 -> V_57 ;
F_42 ( & V_19 -> V_98 ) ;
V_19 -> V_99 = 1 ;
V_19 -> V_100 = V_101 ;
V_59 -> V_62 . V_102 = 0 ;
V_59 -> V_62 . V_63 = 16 ;
F_37 ( & V_59 -> V_62 ) ;
if ( ! F_43
( & V_59 -> V_62 , V_59 , V_103 , NULL , 0 , & V_104 , 16 ) ) {
F_7 (KERN_ERR MODULE_NAME L_11 ) ;
}
if ( F_44 ( & V_59 -> V_60 , 256 , 1 ) < 0 ) {
V_26 = - V_11 ;
goto V_105;
}
V_26 = F_45 ( V_59 ) ;
if ( V_26 ) {
F_7 (KERN_ERR MODULE_NAME L_12 ) ;
goto V_106;
}
F_7 ( L_13 ) ;
return 0 ;
V_106:
F_35 ( & V_59 -> V_60 ) ;
V_105:
F_12 ( V_19 ) ;
V_80:
F_27 ( V_35 ) ;
V_54:
F_28 ( V_35 ) ;
V_52:
F_36 ( V_19 ) ;
V_49:
F_36 ( V_35 ) ;
return V_26 ;
}
static int F_46 ( struct V_58 * V_59 , int V_107 )
{
return 0 ;
}
static int F_47 ( struct V_58 * V_59 , int V_107 )
{
return 0 ;
}
static int F_48 ( int clock )
{
int V_6 ;
int V_108 ;
int V_109 ;
int V_110 ;
V_108 = 0 ;
V_109 = clock - V_111 [ 0 ] ;
V_109 = ( V_109 < 0 ) ? - V_109 : V_109 ;
for ( V_6 = 1 ; V_6 < V_112 ; ++ V_6 ) {
V_110 = clock - V_111 [ V_6 ] ;
V_110 = ( V_110 < 0 ) ? - V_110 : V_110 ;
if ( V_110 < V_109 ) {
V_108 = V_6 ;
V_109 = V_110 ;
}
}
return V_111 [ V_108 ] ;
}
static int F_49 ( struct V_61 * V_62 ,
struct V_18 * V_19 )
{
T_3 V_113 ;
T_4 V_114 ;
int V_115 ;
int clock ;
int V_116 ;
struct V_61 V_117 ;
V_117 = * V_62 ;
clock = F_50 ( V_62 -> V_118 ) ;
if ( V_119 && V_119 -> V_115 ) {
V_115 = V_119 -> V_115 ( V_119 , clock ) ;
} else {
V_115 = F_48 ( clock ) ;
}
V_116 = V_115 - clock ;
V_116 = ( V_116 < 0 ) ? - V_116 : V_116 ;
if ( V_116 > clock / 5 ) {
#if 0
printk(KERN_DEBUG MODULE_NAME ": Diff failure. %d %d\n",clock_diff,clock);
#endif
return - V_43 ;
}
V_117 . V_118 = F_51 ( V_115 ) ;
if ( V_62 -> V_120 > V_121 || V_62 -> V_122 > V_123 ) {
F_7 (KERN_DEBUG MODULE_NAME L_14 ) ;
return - V_43 ;
}
if ( V_62 -> V_124 > V_125 ) {
F_7 (KERN_DEBUG MODULE_NAME
L_15 ) ;
return - V_43 ;
}
switch ( V_117 . V_63 ) {
case 0 ... 16 :
V_117 . V_63 = 16 ;
break;
case 17 ... 32 :
V_117 . V_63 = 32 ;
break;
default:
F_7 (KERN_DEBUG MODULE_NAME L_16 ,
var->bits_per_pixel) ;
return - V_43 ;
}
V_113 = F_52 ( ( V_62 -> V_120 * V_62 -> V_63 ) >> 3 , 0x40 ) ;
V_114 = V_113 * V_62 -> V_126 ;
if ( V_114 > V_19 -> V_33 ) {
return - V_11 ;
}
switch ( V_117 . V_63 ) {
case 16 :
if ( V_62 -> V_64 . V_41 != 0 ||
V_62 -> V_64 . V_65 != 5 ||
V_62 -> V_66 . V_41 != 5 ||
V_62 -> V_66 . V_65 != 5 ||
V_62 -> V_67 . V_41 != 10 ||
V_62 -> V_67 . V_65 != 5 ||
V_62 -> V_68 . V_41 != 15 || V_62 -> V_68 . V_65 != 1 ) {
F_37 ( & V_117 ) ;
}
break;
case 32 :
if ( V_62 -> V_64 . V_41 != 0 ||
V_62 -> V_64 . V_65 != 8 ||
V_62 -> V_66 . V_41 != 8 ||
V_62 -> V_66 . V_65 != 8 ||
V_62 -> V_67 . V_41 != 16 ||
V_62 -> V_67 . V_65 != 8 ||
( V_62 -> V_68 . V_65 != 0 && V_62 -> V_68 . V_65 != 8 ) ||
( V_62 -> V_68 . V_65 == 8 && V_62 -> V_68 . V_41 != 24 ) ) {
F_37 ( & V_117 ) ;
}
break;
default:
return - V_43 ;
}
* V_62 = V_117 ;
return 0 ;
}
static int F_53 ( struct V_61 * V_62 , struct V_58 * V_59 )
{
struct V_18 * V_19 = F_33 ( V_59 , struct V_18 , V_59 ) ;
int V_127 ;
F_15 ( & V_36 ) ;
V_127 = F_49 ( V_62 , V_19 ) ;
F_17 ( & V_36 ) ;
return V_127 ;
}
static void F_54 ( struct V_18 * V_19 )
{
F_55 ( 20 ) ;
}
static void F_56 ( struct V_18 * V_19 )
{
struct V_34 * V_35 = V_19 -> V_35 ;
F_57 ( V_35 , V_128 , 0 ) ;
while ( ! ( F_58 ( V_35 , V_128 ) & V_129 ) ) ;
F_57 ( V_35 , V_130 ,
F_58 ( V_35 , V_130 ) & ~ V_131 ) ;
( void ) F_58 ( V_35 , V_130 ) ;
F_54 ( V_19 ) ;
F_57 ( V_35 , V_132 , 0 ) ;
( void ) F_58 ( V_35 , V_132 ) ;
V_19 -> V_99 = 1 ;
}
static void F_59 ( struct V_18 * V_19 )
{
struct V_34 * V_35 = V_19 -> V_35 ;
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
static int F_60 ( struct V_18 * V_19 )
{
struct V_34 * V_35 = V_19 -> V_35 ;
struct V_58 * V_59 = & V_19 -> V_59 ;
struct V_61 * V_62 = & V_59 -> V_62 ;
T_3 V_133 , V_134 , V_135 , V_136 , V_137 , V_138 ;
T_3 V_139 , V_140 , V_141 , V_142 , V_143 , V_144 ;
T_3 V_145 ;
int clock ;
V_19 -> V_146 = V_62 -> V_63 >> 3 ;
V_19 -> V_147 = F_52 ( V_62 -> V_124 * V_19 -> V_146 , 0x40 ) ;
V_59 -> V_81 . V_148 = V_19 -> V_147 ;
if ( ! V_119 )
return 0 ;
V_133 =
V_62 -> V_120 + V_62 -> V_149 + V_62 -> V_150 + V_62 -> V_151 ;
V_134 = V_62 -> V_120 ;
V_135 = V_62 -> V_120 ;
V_136 = V_133 ;
V_137 = V_134 + V_62 -> V_149 ;
V_138 = V_137 + V_62 -> V_150 ;
V_139 =
V_62 -> V_122 + V_62 -> V_152 + V_62 -> V_153 + V_62 -> V_154 ;
V_140 = V_62 -> V_122 ;
V_141 = V_62 -> V_122 ;
V_142 = V_139 ;
V_143 = V_140 + V_62 -> V_152 ;
V_144 = V_143 + V_62 -> V_153 ;
V_145 = V_131 | V_155 ;
clock = F_50 ( V_62 -> V_118 ) ;
if ( V_119 -> V_115 ) {
clock = V_119 -> V_115 ( V_119 , clock ) ;
} else {
clock = F_48 ( clock ) ;
}
F_7 (KERN_DEBUG MODULE_NAME
L_36 , clock / htotal,
((clock / htotal) * 1000) / vtotal) ;
switch ( V_62 -> V_63 ) {
case 16 :
V_145 |= V_156 ;
break;
case 32 :
if ( V_62 -> V_68 . V_65 == 8 )
V_145 |= V_157 | V_158 ;
else
V_145 |= V_159 ;
break;
default:
return - V_43 ;
}
F_56 ( V_19 ) ;
F_61 () ;
if ( V_119 -> V_160 )
V_119 -> V_160 ( V_119 , clock ) ;
else
return - V_43 ;
F_57 ( V_35 , V_161 , ( ( V_133 - 1 ) << 16 ) | ( V_134 - 1 ) ) ;
F_57 ( V_35 , V_162 ,
( ( V_136 - 1 ) << 16 ) | ( V_135 - 1 ) ) ;
F_57 ( V_35 , V_163 ,
( ( V_138 - 1 ) << 16 ) | ( V_137 - 1 ) ) ;
F_57 ( V_35 , V_164 , ( ( V_139 - 1 ) << 16 ) | ( V_140 - 1 ) ) ;
F_57 ( V_35 , V_165 ,
( ( V_142 - 1 ) << 16 ) | ( V_141 - 1 ) ) ;
F_57 ( V_35 , V_166 ,
( ( V_144 - 1 ) << 16 ) | ( V_143 - 1 ) ) ;
F_57 ( V_35 , V_167 , V_19 -> V_147 ) ;
F_57 ( V_35 , V_168 ,
( ( V_62 -> V_122 - 1 ) << 16 ) | ( V_62 -> V_120 - 1 ) ) ;
F_57 ( V_35 , V_169 , 0x00000000 ) ;
F_57 ( V_35 , V_170 , V_171 ) ;
F_57 ( V_35 , V_172 , 0x00000000 ) ;
F_57 ( V_35 , V_173 , 0x00000000 ) ;
F_57 ( V_35 , V_174 ,
( ( V_62 -> V_120 - 1 ) << 16 ) | ( V_62 -> V_122 - 1 ) ) ;
F_62 () ;
F_57 ( V_35 , V_132 , V_175 ) ;
F_62 () ;
F_57 ( V_35 , V_130 , V_145 ) ;
F_62 () ;
F_57 ( V_35 , V_176 , ( T_3 ) V_19 -> V_30 +
V_62 -> V_177 * V_19 -> V_147 +
V_62 -> V_178 * V_19 -> V_146 ) ;
F_57 ( V_35 , V_128 , V_179 ) ;
while ( ! ( F_58 ( V_35 , V_128 ) &
( V_129 | V_179 ) ) ) ;
V_19 -> V_99 = 0 ;
#ifdef F_63
F_59 ( V_19 ) ;
#endif
return 0 ;
}
static int F_64 ( struct V_58 * V_59 )
{
struct V_18 * V_19 = F_33 ( V_59 , struct V_18 , V_59 ) ;
int V_127 ;
F_15 ( & V_36 ) ;
F_65 ( & V_19 -> V_98 , ( V_119 ) ? & V_180 : & V_181 ) ;
V_127 = F_60 ( V_19 ) ;
F_17 ( & V_36 ) ;
return V_127 ;
}
static int F_66 ( struct V_18 * V_19 )
{
struct V_34 * V_35 = V_19 -> V_35 ;
T_3 V_182 = F_58 ( V_35 , V_132 ) ;
switch ( V_19 -> V_100 ) {
case V_101 :
if ( V_19 -> V_99 ) {
F_60 ( V_19 ) ;
}
F_57 ( V_35 , V_132 , V_182 & ~ V_183 ) ;
( void ) F_58 ( V_35 , V_132 ) ;
break;
case V_184 :
if ( V_19 -> V_99 ) {
F_60 ( V_19 ) ;
}
F_57 ( V_35 , V_132 , V_182 | V_183 ) ;
( void ) F_58 ( V_35 , V_132 ) ;
break;
case V_185 :
case V_186 :
if ( ! V_19 -> V_99 ) {
F_56 ( V_19 ) ;
}
break;
case V_187 :
if ( ! V_19 -> V_99 ) {
F_56 ( V_19 ) ;
}
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_67 ( int V_188 , struct V_58 * V_59 )
{
struct V_18 * V_19 = F_33 ( V_59 , struct V_18 , V_59 ) ;
int V_127 ;
F_15 ( & V_36 ) ;
V_19 -> V_100 = V_188 ;
V_127 = F_66 ( V_19 ) ;
F_17 ( & V_36 ) ;
return V_127 ;
}
static int F_68 ( struct V_61 * V_62 ,
struct V_58 * V_59 )
{
struct V_18 * V_19 = F_33 ( V_59 , struct V_18 , V_59 ) ;
struct V_34 * V_35 = V_19 -> V_35 ;
F_15 ( & V_36 ) ;
F_57 ( V_35 , V_176 , ( T_3 ) V_19 -> V_30 +
V_62 -> V_177 * V_19 -> V_147 +
V_62 -> V_178 * V_19 -> V_146 ) ;
( void ) F_58 ( V_35 , V_176 ) ;
F_17 ( & V_36 ) ;
return 0 ;
}
static int F_69 ( T_5 V_189 , T_5 V_67 , T_5 V_66 , T_5 V_64 ,
T_5 V_68 , struct V_58 * V_59 )
{
T_3 V_117 ;
if ( V_189 >= 16 )
return - V_43 ;
if ( V_59 -> V_62 . V_102 ) {
V_67 = V_66 = V_64 = ( V_67 * 77 + V_66 * 151 + V_64 * 28 ) >> 8 ;
}
if ( V_59 -> V_81 . V_87 != V_88 )
return - V_43 ;
V_67 = F_70 ( V_67 , V_59 -> V_62 . V_67 . V_65 ) ;
V_64 = F_70 ( V_64 , V_59 -> V_62 . V_64 . V_65 ) ;
V_66 = F_70 ( V_66 , V_59 -> V_62 . V_66 . V_65 ) ;
V_68 = F_70 ( V_68 , V_59 -> V_62 . V_68 . V_65 ) ;
V_117 = ( V_67 << V_59 -> V_62 . V_67 . V_41 ) |
( V_66 << V_59 -> V_62 . V_66 . V_41 ) |
( V_64 << V_59 -> V_62 . V_64 . V_41 ) |
( V_68 << V_59 -> V_62 . V_68 . V_41 ) ;
switch ( V_59 -> V_62 . V_63 ) {
case 16 :
( ( T_3 * ) V_59 -> V_95 ) [ V_189 ] = V_117 ;
break;
case 24 :
case 32 :
( ( T_3 * ) V_59 -> V_95 ) [ V_189 ] = V_117 ;
break;
}
return 0 ;
}
static int F_71 ( struct V_58 * V_59 , struct V_190 * V_191 )
{
struct V_18 * V_19 = F_33 ( V_59 , struct V_18 , V_59 ) ;
unsigned long V_41 = V_191 -> V_192 << V_16 ;
int V_127 ;
unsigned long V_193 ;
V_127 = F_19 ( V_19 , V_41 ) ;
if ( V_127 )
return - V_43 ;
V_193 = F_72 ( V_191 -> V_194 ) & ~ V_195 ;
F_72 ( V_191 -> V_194 ) =
V_193 | F_73 ( V_196 ) ;
return F_74 ( V_191 , V_19 -> V_30 ,
V_19 -> V_33 ) ;
}
static int F_75 ( struct V_58 * V_59 )
{
return 0 ;
}
static int F_76 ( struct V_58 * V_59 , struct V_197 * V_198 )
{
return - V_43 ;
}
static void T_6 F_77 ( void )
{
F_78 ( & V_199 ) ;
}
static int T_7 F_79 ( void )
{
#ifndef F_80
char * V_200 = NULL ;
if ( F_81 ( V_201 , & V_200 ) )
return - V_40 ;
#endif
F_7 (KERN_DEBUG MODULE_NAME L_37 ) ;
F_82 ( & V_36 ) ;
F_42 ( & V_181 ) ;
F_42 ( & V_180 ) ;
return F_83 ( & V_199 ) ;
}
int F_84 ( struct V_202 * V_203 )
{
struct V_18 * V_204 ;
struct V_205 * V_206 ;
T_3 V_207 ;
F_15 ( & V_36 ) ;
if ( V_119 != NULL ) {
V_119 -> V_208 ( V_119 ) ;
}
V_119 = V_203 ;
V_119 -> V_209 ( V_119 ) ;
V_206 = V_181 . V_210 ;
while ( V_206 != & V_181 ) {
F_85 ( V_206 ) ;
V_204 = F_86 ( V_206 , struct V_18 , V_98 ) ;
if ( ! F_49 ( & V_204 -> V_59 . V_62 , V_204 ) ) {
F_60 ( V_204 ) ;
F_87 ( V_206 , & V_180 ) ;
} else {
F_17 ( & V_36 ) ;
V_207 = V_204 -> V_59 . V_62 . V_211 ;
V_204 -> V_59 . V_62 . V_63 = 16 ;
F_37 ( & V_204 -> V_59 . V_62 ) ;
if ( F_43 ( & V_204 -> V_59 . V_62 ,
& V_204 -> V_59 ,
V_103 , NULL , 0 , NULL , 16 ) ) {
V_204 -> V_59 . V_62 . V_211 |=
V_212 | V_213 ;
F_88 ( & V_204 -> V_59 , & V_204 -> V_59 . V_62 ) ;
} else {
F_7 (KERN_ERR MODULE_NAME
L_38 ) ;
}
V_204 -> V_59 . V_62 . V_211 = V_207 ;
F_15 ( & V_36 ) ;
}
F_66 ( V_204 ) ;
V_206 = V_181 . V_210 ;
}
F_17 ( & V_36 ) ;
F_7 (KERN_DEBUG MODULE_NAME L_39 ,
subsys->name ? subsys->name : L_40 ) ;
return 0 ;
}
void F_89 ( struct V_202 * V_203 )
{
struct V_18 * V_204 , * V_210 ;
F_15 ( & V_36 ) ;
if ( V_119 != V_203 ) {
F_17 ( & V_36 ) ;
return;
}
V_119 -> V_208 ( V_119 ) ;
V_119 = NULL ;
F_90 (entry, next, &global_has_mode, head) {
F_7 (KERN_DEBUG MODULE_NAME L_41 ) ;
F_56 ( V_204 ) ;
F_91 ( & V_204 -> V_98 , & V_181 ) ;
}
F_17 ( & V_36 ) ;
}
