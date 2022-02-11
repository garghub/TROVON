static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = V_4 ;
V_2 -> V_10 = V_6 ;
V_2 -> V_11 = V_8 ;
}
static void F_2 ( struct V_1 * V_2 , T_1 V_12 )
{
switch ( F_3 ( V_12 ) ) {
case V_13 : {
if ( V_2 -> V_14 < 3 )
F_4 ( L_1 ,
( unsigned ) V_15 , F_5 ( V_12 ) ) ;
if ( V_2 -> V_16 == F_5 ( V_12 ) ) {
F_4 ( L_2 ) ;
break;
}
V_2 -> V_14 ++ ;
if ( F_6 ( V_17 , & V_2 -> V_18 ) )
F_7 ( V_2 , 0 ) ;
V_2 -> V_16 = F_5 ( V_12 ) ;
V_2 -> V_19 += V_2 -> V_20 ;
if ( V_2 -> V_19 > V_2 -> V_21 )
V_2 -> V_19 = 0 ;
F_8 ( V_2 -> V_22 ) ;
break;
}
case V_23 :
if ( V_2 -> V_24 == F_5 ( V_12 ) )
break;
V_2 -> V_24 = F_5 ( V_12 ) ;
V_2 -> V_25 += V_2 -> V_26 ;
if ( V_2 -> V_25 > ( V_2 -> V_27 ) )
V_2 -> V_25 = 0 ;
if ( F_6 ( V_28 , & V_2 -> V_18 ) )
F_9 ( V_2 , V_2 -> V_24 ) ;
F_8 ( V_2 -> V_29 ) ;
break;
case V_30 :
switch ( F_5 ( V_12 ) ) {
#ifndef F_10
case V_31 :
#endif
case V_32 :
F_11 (KERN_WARNING LOGNAME L_3 ,
chip->banksPlayed) ;
if ( V_2 -> V_14 > 2 )
F_12 ( V_17 , & V_2 -> V_18 ) ;
break;
case V_33 :
F_11 (KERN_WARNING LOGNAME L_4 ) ;
F_12 ( V_28 , & V_2 -> V_18 ) ;
break;
default:
F_11 (KERN_WARNING LOGNAME
L_5 ,
LOBYTE(wMessage), LOBYTE(wMessage)) ;
break;
}
break;
case V_34 :
if ( V_2 -> V_35 )
F_13 ( V_2 -> V_35 ) ;
break;
default:
F_11 (KERN_WARNING LOGNAME L_6 ,
HIBYTE(wMessage), HIBYTE(wMessage)) ;
break;
}
}
static T_2 F_14 ( int V_36 , void * V_37 )
{
struct V_1 * V_2 = V_37 ;
void * V_38 = V_2 -> V_39 + V_40 ;
T_1 V_41 , V_42 , V_43 ;
V_41 = F_15 ( V_2 -> V_44 + V_45 ) ;
V_42 = F_15 ( V_2 -> V_44 + V_46 ) ;
V_43 = F_15 ( V_2 -> V_44 + V_47 ) ;
if ( V_41 > V_43 || V_42 > V_43 )
goto V_48;
while ( V_41 != V_42 ) {
F_2 ( V_2 , F_15 ( V_38 + 2 * V_41 ) ) ;
if ( ++ V_41 > V_43 )
V_41 = 0 ;
F_16 ( V_41 , V_2 -> V_44 + V_45 ) ;
}
V_48:
F_17 ( V_2 -> V_49 + V_50 ) ;
return V_51 ;
}
static int F_18 ( long V_49 , unsigned char * V_52 )
{
int V_53 = 100 ;
F_19 ( V_54 , V_49 + V_55 ) ;
F_20 ( 1 ) ;
#ifndef F_10
if ( V_52 )
* V_52 = F_17 ( V_49 + V_56 ) ;
#endif
F_19 ( V_57 , V_49 + V_55 ) ;
F_20 ( 1 ) ;
while ( V_53 -- > 0 ) {
if ( F_17 ( V_49 + V_58 ) == V_59 )
return 0 ;
F_20 ( 1 ) ;
}
F_21 (KERN_ERR LOGNAME L_7 ) ;
return - V_60 ;
}
static int F_22 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_63 ;
unsigned char V_52 ;
#ifndef F_10
char * V_64 , * V_65 = NULL ;
char * V_66 = L_8 , * V_67 = L_9 ;
char * V_68 = L_10 ;
#endif
if ( ! F_23 ( V_2 -> V_49 , V_69 , L_11 ) ) {
F_21 (KERN_ERR LOGNAME L_12 ) ;
return - V_70 ;
}
if ( F_18 ( V_2 -> V_49 , & V_52 ) < 0 ) {
F_24 ( V_2 -> V_49 , V_69 ) ;
return - V_70 ;
}
#ifdef F_10
strcpy ( V_62 -> V_71 , L_13 ) ;
strcpy ( V_62 -> V_72 , L_14 ) ;
F_25 (KERN_INFO LOGNAME L_15
L_16 ,
card->shortname,
chip->io, chip->io + DSP_NUMIO - 1 ,
chip->irq,
chip->base, chip->base + 0x7fff ) ;
#else
switch ( V_52 >> 4 ) {
case 0xf :
V_64 = L_17 ;
break;
case 0x1 :
V_64 = L_18 ;
break;
case 0x2 :
V_64 = L_19 ;
break;
case 0x3 :
V_64 = L_20 ;
break;
default:
V_64 = L_21 ;
break;
}
switch ( V_52 & 0x7 ) {
case 0x0 :
V_65 = L_22 ;
strcpy ( V_62 -> V_71 , V_66 ) ;
break;
case 0x1 :
V_65 = L_23 ;
strcpy ( V_62 -> V_71 , V_66 ) ;
break;
case 0x2 :
V_65 = L_24 ;
strcpy ( V_62 -> V_71 , V_66 ) ;
break;
case 0x3 :
V_65 = L_25 ;
strcpy ( V_62 -> V_71 , V_66 ) ;
break;
case 0x4 :
V_65 = L_26 ;
strcpy ( V_62 -> V_71 , V_67 ) ;
break;
case 0x5 :
V_65 = L_27 ;
strcpy ( V_62 -> V_71 , V_67 ) ;
break;
case 0x6 :
V_65 = L_28 ;
strcpy ( V_62 -> V_71 , V_67 ) ;
break;
case 0x7 :
V_65 = L_29 ;
strcpy ( V_62 -> V_71 , V_68 ) ;
break;
}
strcpy ( V_62 -> V_72 , L_30 ) ;
F_25 (KERN_INFO LOGNAME L_31
L_16 ,
card->shortname,
rev, xv,
chip->io, chip->io + DSP_NUMIO - 1 ,
chip->irq,
chip->base, chip->base + 0x7fff ) ;
#endif
F_24 ( V_2 -> V_49 , V_69 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
static int V_73 ;
T_1 V_74 , V_75 ;
unsigned long V_18 ;
#ifdef F_10
F_19 ( V_2 -> V_76 , V_2 -> V_49 + V_77 ) ;
#endif
F_19 ( V_78 , V_2 -> V_49 + V_79 ) ;
V_2 -> V_80 = V_2 -> V_39 + V_81 ;
if ( V_73 ) {
V_74 = F_15 ( V_2 -> V_80 + V_82 ) ;
V_75 = F_15 ( V_2 -> V_80 + V_83 ) ;
} else
V_74 = V_75 = 0 ;
F_27 ( V_2 -> V_39 , 0 , 0x8000 ) ;
F_28 ( & V_2 -> V_84 , V_18 ) ;
F_19 ( V_85 , V_2 -> V_49 + V_79 ) ;
F_27 ( V_2 -> V_39 , 0 , 0x8000 ) ;
F_19 ( V_78 , V_2 -> V_49 + V_79 ) ;
F_29 ( & V_2 -> V_84 , V_18 ) ;
V_2 -> V_86 = V_2 -> V_39 + V_87 ;
F_30 ( V_2 -> V_86 , V_88 , V_89 ) ;
V_2 -> V_90 = V_2 -> V_39 + V_91 ;
F_30 ( V_2 -> V_90 , V_92 , V_93 ) ;
V_2 -> V_94 = V_2 -> V_39 + V_95 ;
F_30 ( V_2 -> V_94 , V_96 , V_97 ) ;
V_2 -> V_98 = V_2 -> V_39 + V_99 ;
F_30 ( V_2 -> V_98 , V_100 , V_101 ) ;
V_2 -> V_44 = V_2 -> V_39 + V_102 ;
F_30 ( V_2 -> V_44 , V_40 , V_103 ) ;
#ifndef F_10
F_16 ( 1 , V_2 -> V_80 + V_104 ) ;
F_16 ( V_2 -> V_3 , V_2 -> V_80 + V_105 ) ;
F_16 ( V_2 -> V_7 , V_2 -> V_80 + V_106 ) ;
F_16 ( V_2 -> V_5 , V_2 -> V_80 + V_107 ) ;
#endif
F_16 ( V_2 -> V_5 , V_2 -> V_80 + V_108 ) ;
F_16 ( V_74 , V_2 -> V_80 + V_82 ) ;
F_16 ( V_75 , V_2 -> V_80 + V_83 ) ;
#ifndef F_10
F_31 ( 0x00010000 , V_2 -> V_80 + V_109 ) ;
F_31 ( 0x00000001 , V_2 -> V_80 + V_110 ) ;
#endif
F_16 ( 0x303 , V_2 -> V_80 + V_111 ) ;
V_73 = 1 ;
return 0 ;
}
static int F_32 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_63 ;
const struct V_112 * V_113 = NULL , * V_114 = NULL ;
int V_115 ;
F_19 ( V_78 , V_2 -> V_49 + V_79 ) ;
V_115 = F_33 ( & V_113 , V_116 , V_62 -> V_117 ) ;
if ( V_115 < 0 ) {
F_25 (KERN_ERR LOGNAME L_32 INITCODEFILE) ;
goto V_118;
}
V_115 = F_33 ( & V_114 , V_119 , V_62 -> V_117 ) ;
if ( V_115 < 0 ) {
F_25 (KERN_ERR LOGNAME L_32 PERMCODEFILE) ;
goto V_120;
}
F_34 ( V_2 -> V_39 , V_114 -> V_121 , V_114 -> V_43 ) ;
if ( F_35 ( V_2 , V_113 -> V_121 , V_113 -> V_43 ) < 0 ) {
F_25 (KERN_WARNING LOGNAME L_33 ) ;
V_115 = - V_70 ;
goto V_120;
}
F_25 (KERN_INFO LOGNAME L_34 ) ;
V_115 = 0 ;
V_120:
F_36 ( V_114 ) ;
V_118:
F_36 ( V_113 ) ;
return V_115 ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_19 ( V_122 , V_2 -> V_49 + V_123 ) ;
F_20 ( V_124 ) ;
F_19 ( V_125 , V_2 -> V_49 + V_123 ) ;
F_20 ( V_126 ) ;
}
static int F_38 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_63 ;
int V_115 , V_53 ;
#ifdef F_10
F_19 ( V_127 , V_2 -> V_49 + V_128 ) ;
F_19 ( V_129 , V_2 -> V_49 + V_130 ) ;
F_37 ( V_2 ) ;
#endif
V_115 = F_26 ( V_2 ) ;
if ( V_115 < 0 ) {
F_25 (KERN_WARNING LOGNAME L_35 ) ;
return V_115 ;
}
V_115 = F_18 ( V_2 -> V_49 , NULL ) ;
if ( V_115 < 0 )
return V_115 ;
V_115 = F_32 ( V_62 ) ;
if ( V_115 < 0 ) {
F_25 (KERN_WARNING LOGNAME L_36 ) ;
return V_115 ;
}
V_53 = 200 ;
while ( F_15 ( V_2 -> V_39 ) ) {
F_20 ( 1 ) ;
if ( ! V_53 -- ) {
F_11 (KERN_ERR LOGNAME L_37 ) ;
return - V_60 ;
}
}
F_39 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_63 ;
int V_131 ;
if ( F_6 ( V_132 , & V_2 -> V_18 ) || ++ V_2 -> V_133 > 10 )
return 0 ;
F_41 ( V_132 , & V_2 -> V_18 ) ;
F_42 ( V_2 , NULL ) ;
V_131 = F_38 ( V_62 ) ;
if ( V_131 )
F_25 (KERN_WARNING LOGNAME L_38 ) ;
F_43 ( V_2 , 0 ) ;
F_12 ( V_132 , & V_2 -> V_18 ) ;
return V_131 ;
}
static int F_44 ( struct V_134 * V_135 )
{
F_4 ( L_39 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , T_3 V_136 )
{
if ( F_46 ( V_2 , V_136 ) == 0 )
return 0 ;
F_40 ( V_2 -> V_62 ) ;
return F_46 ( V_2 , V_136 ) ;
}
static int F_47 ( struct V_1 * V_2 , T_1 V_137 )
{
F_4 ( L_40 , V_137 ) ;
F_16 ( V_137 , V_2 -> V_80 + V_108 ) ;
if ( V_2 -> V_138 == 0 )
F_16 ( F_15 ( V_2 -> V_80 + V_139 )
| 0x0001 , V_2 -> V_80 + V_139 ) ;
else
F_16 ( F_15 ( V_2 -> V_80 + V_139 )
& ~ 0x0001 , V_2 -> V_80 + V_139 ) ;
if ( F_48 ( V_2 , 0 , 0 , V_140 ) == 0 &&
F_45 ( V_2 , V_141 ) == 0 ) {
F_49 ( F_50 ( 333 ) ) ;
return 0 ;
}
F_25 (KERN_WARNING LOGNAME L_41 ) ;
return - V_60 ;
}
static int F_51 ( struct V_142 * V_143 )
{
F_52 ( V_143 -> V_63 ) ;
F_46 ( V_143 -> V_63 , V_144 ) ;
return 0 ;
}
static void F_53 ( struct V_142 * V_143 )
{
F_46 ( V_143 -> V_63 , V_145 ) ;
F_54 ( V_143 -> V_63 ) ;
}
static int F_55 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_63 ;
int V_115 ;
static struct V_146 V_147 = {
. V_148 = F_44 ,
} ;
V_115 = F_56 ( V_2 -> V_36 , F_14 , 0 , V_62 -> V_71 ,
V_2 ) ;
if ( V_115 < 0 ) {
F_25 (KERN_ERR LOGNAME L_42 , chip->irq) ;
return V_115 ;
}
if ( F_23 ( V_2 -> V_49 , V_69 , V_62 -> V_71 ) == NULL ) {
F_57 ( V_2 -> V_36 , V_2 ) ;
return - V_149 ;
}
if ( ! F_58 ( V_2 -> V_150 , V_151 , V_62 -> V_71 ) ) {
F_25 (KERN_ERR LOGNAME
L_43 ,
chip->base, chip->base + BUFFSIZE - 1 ) ;
F_24 ( V_2 -> V_49 , V_69 ) ;
F_57 ( V_2 -> V_36 , V_2 ) ;
return - V_149 ;
}
V_2 -> V_39 = F_59 ( V_2 -> V_150 , 0x8000 ) ;
if ( ! V_2 -> V_39 ) {
F_25 (KERN_ERR LOGNAME
L_44 ,
chip->base, chip->base + BUFFSIZE - 1 ) ;
V_115 = - V_60 ;
goto V_152;
}
V_115 = F_40 ( V_62 ) ;
if ( V_115 < 0 )
goto V_152;
V_115 = F_60 ( V_62 , V_153 , V_2 , & V_147 ) ;
if ( V_115 < 0 )
goto V_152;
V_115 = F_61 ( V_62 , 0 ) ;
if ( V_115 < 0 ) {
F_25 (KERN_ERR LOGNAME L_45 ) ;
goto V_152;
}
V_115 = F_62 ( V_62 ) ;
if ( V_115 < 0 ) {
F_25 (KERN_ERR LOGNAME L_46 ) ;
goto V_152;
}
if ( V_154 [ 0 ] != V_155 ) {
struct V_142 * V_143 ;
V_115 = F_63 ( V_62 , 0 , V_156 ,
V_154 [ 0 ] ,
V_157 |
V_158 ,
V_159 [ 0 ] ,
& V_2 -> V_160 ) ;
if ( V_115 < 0 ) {
F_25 (KERN_ERR LOGNAME
L_47 ) ;
goto V_152;
}
V_143 = V_2 -> V_160 -> V_63 ;
V_143 -> V_161 = F_51 ;
V_143 -> V_162 = F_53 ;
V_143 -> V_63 = V_2 ;
}
F_64 ( V_2 -> V_36 ) ;
F_47 ( V_2 , V_2 -> V_5 ) ;
F_43 ( V_2 , 0 ) ;
V_115 = F_65 ( V_62 ) ;
if ( V_115 < 0 )
goto V_152;
return 0 ;
V_152:
F_66 ( V_2 -> V_39 ) ;
F_67 ( V_2 -> V_150 , V_151 ) ;
F_24 ( V_2 -> V_49 , V_69 ) ;
F_57 ( V_2 -> V_36 , V_2 ) ;
return V_115 ;
}
static void F_68 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_63 ;
F_66 ( V_2 -> V_39 ) ;
F_67 ( V_2 -> V_150 , V_151 ) ;
F_24 ( V_2 -> V_49 , V_69 ) ;
F_57 ( V_2 -> V_36 , V_2 ) ;
F_69 ( V_62 ) ;
}
static int F_70 ( int V_163 , int V_164 , int V_165 )
{
F_19 ( V_164 , V_163 ) ;
F_19 ( V_165 , V_163 + 1 ) ;
if ( V_165 != F_17 ( V_163 + 1 ) ) {
F_25 (KERN_ERR LOGNAME L_48 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_71 ( int V_163 , int V_166 , T_1 V_49 )
{
if ( F_70 ( V_163 , V_167 , V_166 ) )
return - V_60 ;
if ( F_70 ( V_163 , V_168 , F_3 ( V_49 ) ) )
return - V_60 ;
if ( F_70 ( V_163 , V_169 , F_5 ( V_49 ) ) )
return - V_60 ;
return 0 ;
}
static int F_72 ( int V_163 , int V_166 , T_1 V_49 )
{
if ( F_70 ( V_163 , V_167 , V_166 ) )
return - V_60 ;
if ( F_70 ( V_163 , V_170 , F_3 ( V_49 ) ) )
return - V_60 ;
if ( F_70 ( V_163 , V_171 , F_5 ( V_49 ) ) )
return - V_60 ;
return 0 ;
}
static int F_73 ( int V_163 , int V_166 , T_1 V_36 )
{
if ( F_70 ( V_163 , V_167 , V_166 ) )
return - V_60 ;
if ( F_70 ( V_163 , V_172 , F_5 ( V_36 ) ) )
return - V_60 ;
if ( F_70 ( V_163 , V_173 , V_174 ) )
return - V_60 ;
return 0 ;
}
static int F_74 ( int V_163 , int V_166 , int V_175 )
{
T_1 V_176 ;
V_175 >>= 8 ;
V_176 = ( T_1 ) ( V_175 & 0xfff ) ;
if ( F_70 ( V_163 , V_167 , V_166 ) )
return - V_60 ;
if ( F_70 ( V_163 , V_177 , F_3 ( V_176 ) ) )
return - V_60 ;
if ( F_70 ( V_163 , V_178 , F_5 ( V_176 ) ) )
return - V_60 ;
if ( V_176 && F_70 ( V_163 , V_179 ,
V_180 | V_181 ) )
return - V_60 ;
return 0 ;
}
static int F_75 ( int V_163 , int V_166 )
{
if ( F_70 ( V_163 , V_167 , V_166 ) )
return - V_60 ;
if ( F_70 ( V_163 , V_182 , V_183 ) )
return - V_60 ;
return 0 ;
}
static int F_76 ( int V_163 , int V_166 , T_1 V_184 ,
T_1 V_185 , T_1 V_36 , int V_175 )
{
if ( F_70 ( V_163 , V_167 , V_166 ) )
return - V_60 ;
if ( F_71 ( V_163 , V_166 , V_184 ) )
return - V_60 ;
if ( F_72 ( V_163 , V_166 , V_185 ) )
return - V_60 ;
if ( F_73 ( V_163 , V_166 , V_36 ) )
return - V_60 ;
if ( F_74 ( V_163 , V_166 , V_175 ) )
return - V_60 ;
if ( F_75 ( V_163 , V_166 ) )
return - V_60 ;
return 0 ;
}
static int F_77 ( int V_163 )
{
int V_186 ;
F_25 (KERN_INFO LOGNAME L_49 ) ;
for ( V_186 = 0 ; V_186 < 4 ; ++ V_186 )
if ( F_76 ( V_163 , V_186 , 0 , 0 , 0 , 0 ) )
return - V_60 ;
return 0 ;
}
static int F_78 ( struct V_135 * V_187 , unsigned int V_186 )
{
if ( V_49 [ V_186 ] == V_155 )
return 0 ;
if ( V_36 [ V_186 ] == V_155 || V_175 [ V_186 ] == V_155 ) {
F_25 (KERN_WARNING LOGNAME L_50 ) ;
return 0 ;
}
#ifdef F_10
if ( ! ( V_49 [ V_186 ] == 0x290 ||
V_49 [ V_186 ] == 0x260 ||
V_49 [ V_186 ] == 0x250 ||
V_49 [ V_186 ] == 0x240 ||
V_49 [ V_186 ] == 0x230 ||
V_49 [ V_186 ] == 0x220 ||
V_49 [ V_186 ] == 0x210 ||
V_49 [ V_186 ] == 0x3e0 ) ) {
F_25 (KERN_ERR LOGNAME L_51
L_52
L_53 ) ;
return 0 ;
}
#else
if ( V_49 [ V_186 ] < 0x100 || V_49 [ V_186 ] > 0x3e0 || ( V_49 [ V_186 ] % 0x10 ) != 0 ) {
F_25 (KERN_ERR LOGNAME
L_54
L_55 ) ;
return 0 ;
}
#endif
if ( ! ( V_36 [ V_186 ] == 5 ||
V_36 [ V_186 ] == 7 ||
V_36 [ V_186 ] == 9 ||
V_36 [ V_186 ] == 10 ||
V_36 [ V_186 ] == 11 ||
V_36 [ V_186 ] == 12 ) ) {
F_25 (KERN_ERR LOGNAME
L_56 ) ;
return 0 ;
}
if ( ! ( V_175 [ V_186 ] == 0xb0000 ||
V_175 [ V_186 ] == 0xc8000 ||
V_175 [ V_186 ] == 0xd0000 ||
V_175 [ V_186 ] == 0xd8000 ||
V_175 [ V_186 ] == 0xe0000 ||
V_175 [ V_186 ] == 0xe8000 ) ) {
F_25 (KERN_ERR LOGNAME L_57
L_58
L_59 ) ;
return 0 ;
}
#ifndef F_10
if ( V_163 [ V_186 ] == V_155 ) {
F_25 (KERN_INFO LOGNAME L_60 ) ;
} else if ( V_163 [ V_186 ] != 0x250 && V_163 [ V_186 ] != 0x260 && V_163 [ V_186 ] != 0x270 ) {
F_25 (KERN_INFO LOGNAME
L_61
L_62 ) ;
return 0 ;
}
#endif
return 1 ;
}
static int F_79 ( struct V_135 * V_187 , unsigned int V_188 )
{
int V_115 ;
struct V_61 * V_62 ;
struct V_1 * V_2 ;
if ( F_80 ( V_188 )
#ifndef F_10
|| V_163 [ V_188 ] == V_155
#endif
) {
F_25 (KERN_INFO LOGNAME L_60 ) ;
return - V_70 ;
}
V_115 = F_81 ( V_187 , V_189 [ V_188 ] , V_190 [ V_188 ] , V_191 ,
sizeof( struct V_1 ) , & V_62 ) ;
if ( V_115 < 0 )
return V_115 ;
V_2 = V_62 -> V_63 ;
V_2 -> V_62 = V_62 ;
#ifdef F_10
switch ( V_36 [ V_188 ] ) {
case 5 :
V_2 -> V_192 = V_193 ; break;
case 7 :
V_2 -> V_192 = V_194 ; break;
case 9 :
V_2 -> V_192 = V_195 ; break;
case 10 :
V_2 -> V_192 = V_196 ; break;
case 11 :
V_2 -> V_192 = V_197 ; break;
case 12 :
V_2 -> V_192 = V_198 ; break;
}
switch ( V_175 [ V_188 ] ) {
case 0xb0000 :
V_2 -> V_76 = V_199 ; break;
case 0xc8000 :
V_2 -> V_76 = V_200 ; break;
case 0xd0000 :
V_2 -> V_76 = V_201 ; break;
case 0xd8000 :
V_2 -> V_76 = V_202 ; break;
case 0xe0000 :
V_2 -> V_76 = V_203 ; break;
case 0xe8000 :
V_2 -> V_76 = V_204 ; break;
}
#else
F_25 (KERN_INFO LOGNAME L_63 ,
cfg[idx]) ;
if ( ! F_23 ( V_163 [ V_188 ] , 2 , L_64 ) ) {
F_25 (KERN_ERR LOGNAME L_65 ,
cfg[idx]) ;
F_69 ( V_62 ) ;
return - V_60 ;
}
if ( V_205 [ V_188 ] )
if ( F_77 ( V_163 [ V_188 ] ) ) {
V_115 = - V_60 ;
goto V_206;
}
V_115 = F_76 ( V_163 [ V_188 ] , 0 ,
V_49 [ V_188 ] , 0 ,
V_36 [ V_188 ] , V_175 [ V_188 ] ) ;
if ( V_115 )
goto V_206;
if ( V_154 [ V_188 ] != V_155
&& V_159 [ V_188 ] != V_207 ) {
F_25 (KERN_INFO LOGNAME
L_66 ,
mpu_io[idx], mpu_irq[idx]) ;
V_115 = F_76 ( V_163 [ V_188 ] , 1 ,
V_154 [ V_188 ] , 0 ,
V_159 [ V_188 ] , 0 ) ;
if ( V_115 )
goto V_206;
}
if ( V_208 [ V_188 ] != V_155
&& V_209 [ V_188 ] != V_155
&& V_210 [ V_188 ] != V_207 ) {
F_25 (KERN_INFO LOGNAME
L_67 ,
ide_io0[idx], ide_io1[idx], ide_irq[idx]) ;
V_115 = F_76 ( V_163 [ V_188 ] , 2 ,
V_208 [ V_188 ] , V_209 [ V_188 ] ,
V_210 [ V_188 ] , 0 ) ;
if ( V_115 )
goto V_206;
}
if ( V_211 [ V_188 ] != V_155 ) {
F_25 (KERN_INFO LOGNAME
L_68 ,
joystick_io[idx]) ;
V_115 = F_76 ( V_163 [ V_188 ] , 3 ,
V_211 [ V_188 ] , 0 ,
0 , 0 ) ;
if ( V_115 )
goto V_206;
}
F_24 ( V_163 [ V_188 ] , 2 ) ;
#endif
F_1 ( V_2 ) ;
#ifdef F_10
V_2 -> type = V_212 ;
#else
V_2 -> type = V_213 ;
#endif
V_2 -> V_49 = V_49 [ V_188 ] ;
V_2 -> V_36 = V_36 [ V_188 ] ;
V_2 -> V_150 = V_175 [ V_188 ] ;
V_2 -> V_138 = V_138 ? 1 : 0 ;
V_2 -> V_214 = 0 ;
V_2 -> V_215 = V_40 ;
V_2 -> V_216 = V_103 ;
if ( V_217 [ V_188 ] )
F_12 ( V_218 , & V_2 -> V_18 ) ;
else
F_41 ( V_218 , & V_2 -> V_18 ) ;
#ifndef F_10
if ( V_219 [ V_188 ] )
F_41 ( V_220 , & V_2 -> V_18 ) ;
#endif
F_82 ( & V_2 -> V_84 ) ;
V_115 = F_22 ( V_62 ) ;
if ( V_115 < 0 ) {
F_25 (KERN_ERR LOGNAME L_69 ) ;
F_69 ( V_62 ) ;
return V_115 ;
}
V_115 = F_55 ( V_62 ) ;
if ( V_115 < 0 ) {
F_25 (KERN_ERR LOGNAME L_70 ) ;
F_69 ( V_62 ) ;
return V_115 ;
}
F_83 ( V_187 , V_62 ) ;
return 0 ;
#ifndef F_10
V_206:
F_24 ( V_163 [ V_188 ] , 2 ) ;
F_69 ( V_62 ) ;
return V_115 ;
#endif
}
static int F_84 ( struct V_135 * V_187 , unsigned int V_117 )
{
F_68 ( F_85 ( V_187 ) ) ;
return 0 ;
}
static int F_86 ( struct V_221 * V_222 ,
const struct V_223 * V_224 )
{
static int V_188 ;
struct V_225 * V_225 ;
struct V_225 * V_226 ;
struct V_61 * V_62 ;
struct V_1 * V_2 ;
int V_227 ;
for ( ; V_188 < V_228 ; V_188 ++ ) {
if ( F_80 ( V_188 ) )
break;
}
if ( V_188 >= V_228 )
return - V_70 ;
V_225 = F_87 ( V_222 , V_224 -> V_229 [ 0 ] . V_190 , NULL ) ;
if ( ! V_225 )
return - V_70 ;
V_226 = F_87 ( V_222 , V_224 -> V_229 [ 1 ] . V_190 , NULL ) ;
if ( ! V_226 )
return - V_70 ;
if ( ! F_88 ( V_225 ) && F_89 ( V_225 ) < 0 ) {
F_25 ( V_230 L_71 ) ;
return - V_149 ;
}
if ( ! F_88 ( V_226 ) && F_89 ( V_226 ) < 0 ) {
F_25 ( V_230 L_72 ) ;
return - V_149 ;
}
V_227 = F_81 ( & V_222 -> V_62 -> V_117 ,
V_189 [ V_188 ] , V_190 [ V_188 ] , V_191 ,
sizeof( struct V_1 ) , & V_62 ) ;
if ( V_227 < 0 )
return V_227 ;
V_2 = V_62 -> V_63 ;
V_2 -> V_62 = V_62 ;
V_49 [ V_188 ] = F_90 ( V_225 , 0 ) ;
V_36 [ V_188 ] = F_91 ( V_225 , 0 ) ;
V_175 [ V_188 ] = F_92 ( V_225 , 0 ) ;
V_154 [ V_188 ] = F_90 ( V_226 , 0 ) ;
V_159 [ V_188 ] = F_91 ( V_226 , 0 ) ;
F_1 ( V_2 ) ;
#ifdef F_10
V_2 -> type = V_212 ;
#else
V_2 -> type = V_213 ;
#endif
V_2 -> V_49 = V_49 [ V_188 ] ;
V_2 -> V_36 = V_36 [ V_188 ] ;
V_2 -> V_150 = V_175 [ V_188 ] ;
V_2 -> V_138 = V_138 ? 1 : 0 ;
V_2 -> V_214 = 0 ;
V_2 -> V_215 = V_40 ;
V_2 -> V_216 = V_103 ;
if ( V_217 [ V_188 ] )
F_12 ( V_218 , & V_2 -> V_18 ) ;
else
F_41 ( V_218 , & V_2 -> V_18 ) ;
#ifndef F_10
if ( V_219 [ V_188 ] )
F_41 ( V_220 , & V_2 -> V_18 ) ;
#endif
F_82 ( & V_2 -> V_84 ) ;
V_227 = F_22 ( V_62 ) ;
if ( V_227 < 0 ) {
F_25 (KERN_ERR LOGNAME L_69 ) ;
goto V_231;
}
V_227 = F_55 ( V_62 ) ;
if ( V_227 < 0 ) {
F_25 (KERN_ERR LOGNAME L_70 ) ;
goto V_231;
}
F_93 ( V_222 , V_62 ) ;
++ V_188 ;
return 0 ;
V_231:
F_69 ( V_62 ) ;
return V_227 ;
}
static void F_94 ( struct V_221 * V_222 )
{
F_68 ( F_95 ( V_222 ) ) ;
F_93 ( V_222 , NULL ) ;
}
static int T_4 F_96 ( void )
{
int V_115 ;
V_115 = F_97 ( & V_232 , V_228 ) ;
#ifdef F_98
if ( ! V_115 )
V_233 = 1 ;
V_115 = F_99 ( & V_234 ) ;
if ( ! V_115 )
V_235 = 1 ;
if ( V_233 )
V_115 = 0 ;
#endif
return V_115 ;
}
static void T_5 F_100 ( void )
{
#ifdef F_98
if ( V_235 )
F_101 ( & V_234 ) ;
if ( V_233 )
#endif
F_102 ( & V_232 ) ;
}
