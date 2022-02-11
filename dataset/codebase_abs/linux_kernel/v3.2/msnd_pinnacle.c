static void T_1 F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = V_4 ;
V_2 -> V_10 = V_6 ;
V_2 -> V_11 = V_8 ;
}
static void F_2 ( struct V_1 * V_2 , T_2 V_12 )
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
static T_3 F_14 ( int V_36 , void * V_37 )
{
struct V_1 * V_2 = V_37 ;
void * V_38 = V_2 -> V_39 + V_40 ;
while ( F_15 ( V_2 -> V_41 + V_42 ) != F_15 ( V_2 -> V_41 + V_43 ) ) {
T_2 V_44 ;
F_2 ( V_2 ,
F_15 ( V_38 + 2 * F_15 ( V_2 -> V_41 + V_43 ) ) ) ;
V_44 = F_15 ( V_2 -> V_41 + V_43 ) + 1 ;
if ( V_44 > F_15 ( V_2 -> V_41 + V_45 ) )
F_16 ( 0 , V_2 -> V_41 + V_43 ) ;
else
F_16 ( V_44 , V_2 -> V_41 + V_43 ) ;
}
F_17 ( V_2 -> V_46 + V_47 ) ;
return V_48 ;
}
static int F_18 ( long V_46 , unsigned char * V_49 )
{
int V_50 = 100 ;
F_19 ( V_51 , V_46 + V_52 ) ;
F_20 ( 1 ) ;
#ifndef F_10
if ( V_49 )
* V_49 = F_17 ( V_46 + V_53 ) ;
#endif
F_19 ( V_54 , V_46 + V_52 ) ;
F_20 ( 1 ) ;
while ( V_50 -- > 0 ) {
if ( F_17 ( V_46 + V_55 ) == V_56 )
return 0 ;
F_20 ( 1 ) ;
}
F_21 (KERN_ERR LOGNAME L_7 ) ;
return - V_57 ;
}
static int T_1 F_22 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
unsigned char V_49 ;
#ifndef F_10
char * V_61 , * V_62 = NULL ;
char * V_63 = L_8 , * V_64 = L_9 ;
char * V_65 = L_10 ;
#endif
if ( ! F_23 ( V_2 -> V_46 , V_66 , L_11 ) ) {
F_21 (KERN_ERR LOGNAME L_12 ) ;
return - V_67 ;
}
if ( F_18 ( V_2 -> V_46 , & V_49 ) < 0 ) {
F_24 ( V_2 -> V_46 , V_66 ) ;
return - V_67 ;
}
#ifdef F_10
strcpy ( V_59 -> V_68 , L_13 ) ;
strcpy ( V_59 -> V_69 , L_14 ) ;
F_25 (KERN_INFO LOGNAME L_15
L_16 ,
card->shortname,
chip->io, chip->io + DSP_NUMIO - 1 ,
chip->irq,
chip->base, chip->base + 0x7fff ) ;
#else
switch ( V_49 >> 4 ) {
case 0xf :
V_61 = L_17 ;
break;
case 0x1 :
V_61 = L_18 ;
break;
case 0x2 :
V_61 = L_19 ;
break;
case 0x3 :
V_61 = L_20 ;
break;
default:
V_61 = L_21 ;
break;
}
switch ( V_49 & 0x7 ) {
case 0x0 :
V_62 = L_22 ;
strcpy ( V_59 -> V_68 , V_63 ) ;
break;
case 0x1 :
V_62 = L_23 ;
strcpy ( V_59 -> V_68 , V_63 ) ;
break;
case 0x2 :
V_62 = L_24 ;
strcpy ( V_59 -> V_68 , V_63 ) ;
break;
case 0x3 :
V_62 = L_25 ;
strcpy ( V_59 -> V_68 , V_63 ) ;
break;
case 0x4 :
V_62 = L_26 ;
strcpy ( V_59 -> V_68 , V_64 ) ;
break;
case 0x5 :
V_62 = L_27 ;
strcpy ( V_59 -> V_68 , V_64 ) ;
break;
case 0x6 :
V_62 = L_28 ;
strcpy ( V_59 -> V_68 , V_64 ) ;
break;
case 0x7 :
V_62 = L_29 ;
strcpy ( V_59 -> V_68 , V_65 ) ;
break;
}
strcpy ( V_59 -> V_69 , L_30 ) ;
F_25 (KERN_INFO LOGNAME L_31
L_16 ,
card->shortname,
rev, xv,
chip->io, chip->io + DSP_NUMIO - 1 ,
chip->irq,
chip->base, chip->base + 0x7fff ) ;
#endif
F_24 ( V_2 -> V_46 , V_66 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
static int V_70 ;
T_2 V_71 , V_72 ;
unsigned long V_18 ;
#ifdef F_10
F_19 ( V_2 -> V_73 , V_2 -> V_46 + V_74 ) ;
#endif
F_19 ( V_75 , V_2 -> V_46 + V_76 ) ;
V_2 -> V_77 = V_2 -> V_39 + V_78 ;
if ( V_70 ) {
V_71 = F_15 ( V_2 -> V_77 + V_79 ) ;
V_72 = F_15 ( V_2 -> V_77 + V_80 ) ;
} else
V_71 = V_72 = 0 ;
F_27 ( V_2 -> V_39 , 0 , 0x8000 ) ;
F_28 ( & V_2 -> V_81 , V_18 ) ;
F_19 ( V_82 , V_2 -> V_46 + V_76 ) ;
F_27 ( V_2 -> V_39 , 0 , 0x8000 ) ;
F_19 ( V_75 , V_2 -> V_46 + V_76 ) ;
F_29 ( & V_2 -> V_81 , V_18 ) ;
V_2 -> V_83 = V_2 -> V_39 + V_84 ;
F_30 ( V_2 -> V_83 , V_85 , V_86 ) ;
V_2 -> V_87 = V_2 -> V_39 + V_88 ;
F_30 ( V_2 -> V_87 , V_89 , V_90 ) ;
V_2 -> V_91 = V_2 -> V_39 + V_92 ;
F_30 ( V_2 -> V_91 , V_93 , V_94 ) ;
V_2 -> V_95 = V_2 -> V_39 + V_96 ;
F_30 ( V_2 -> V_95 , V_97 , V_98 ) ;
V_2 -> V_41 = V_2 -> V_39 + V_99 ;
F_30 ( V_2 -> V_41 , V_40 , V_100 ) ;
#ifndef F_10
F_16 ( 1 , V_2 -> V_77 + V_101 ) ;
F_16 ( V_2 -> V_3 , V_2 -> V_77 + V_102 ) ;
F_16 ( V_2 -> V_7 , V_2 -> V_77 + V_103 ) ;
F_16 ( V_2 -> V_5 , V_2 -> V_77 + V_104 ) ;
#endif
F_16 ( V_2 -> V_5 , V_2 -> V_77 + V_105 ) ;
F_16 ( V_71 , V_2 -> V_77 + V_79 ) ;
F_16 ( V_72 , V_2 -> V_77 + V_80 ) ;
#ifndef F_10
F_31 ( 0x00010000 , V_2 -> V_77 + V_106 ) ;
F_31 ( 0x00000001 , V_2 -> V_77 + V_107 ) ;
#endif
F_16 ( 0x303 , V_2 -> V_77 + V_108 ) ;
V_70 = 1 ;
return 0 ;
}
static int F_32 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
const struct V_109 * V_110 = NULL , * V_111 = NULL ;
int V_112 ;
F_19 ( V_75 , V_2 -> V_46 + V_76 ) ;
V_112 = F_33 ( & V_110 , V_113 , V_59 -> V_114 ) ;
if ( V_112 < 0 ) {
F_25 (KERN_ERR LOGNAME L_32 INITCODEFILE) ;
goto V_115;
}
V_112 = F_33 ( & V_111 , V_116 , V_59 -> V_114 ) ;
if ( V_112 < 0 ) {
F_25 (KERN_ERR LOGNAME L_32 PERMCODEFILE) ;
goto V_117;
}
F_34 ( V_2 -> V_39 , V_111 -> V_118 , V_111 -> V_119 ) ;
if ( F_35 ( V_2 , V_110 -> V_118 , V_110 -> V_119 ) < 0 ) {
F_25 (KERN_WARNING LOGNAME L_33 ) ;
V_112 = - V_67 ;
goto V_117;
}
F_25 (KERN_INFO LOGNAME L_34 ) ;
V_112 = 0 ;
V_117:
F_36 ( V_111 ) ;
V_115:
F_36 ( V_110 ) ;
return V_112 ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_19 ( V_120 , V_2 -> V_46 + V_121 ) ;
F_20 ( V_122 ) ;
F_19 ( V_123 , V_2 -> V_46 + V_121 ) ;
F_20 ( V_124 ) ;
}
static int F_38 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
int V_112 , V_50 ;
#ifdef F_10
F_19 ( V_125 , V_2 -> V_46 + V_126 ) ;
F_19 ( V_127 , V_2 -> V_46 + V_128 ) ;
F_37 ( V_2 ) ;
#endif
V_112 = F_26 ( V_2 ) ;
if ( V_112 < 0 ) {
F_25 (KERN_WARNING LOGNAME L_35 ) ;
return V_112 ;
}
V_112 = F_18 ( V_2 -> V_46 , NULL ) ;
if ( V_112 < 0 )
return V_112 ;
V_112 = F_32 ( V_59 ) ;
if ( V_112 < 0 ) {
F_25 (KERN_WARNING LOGNAME L_36 ) ;
return V_112 ;
}
V_50 = 200 ;
while ( F_15 ( V_2 -> V_39 ) ) {
F_20 ( 1 ) ;
if ( ! V_50 -- ) {
F_11 (KERN_ERR LOGNAME L_37 ) ;
return - V_57 ;
}
}
F_39 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
int V_129 ;
if ( F_6 ( V_130 , & V_2 -> V_18 ) || ++ V_2 -> V_131 > 10 )
return 0 ;
F_41 ( V_130 , & V_2 -> V_18 ) ;
F_42 ( V_2 , NULL ) ;
V_129 = F_38 ( V_59 ) ;
if ( V_129 )
F_25 (KERN_WARNING LOGNAME L_38 ) ;
F_43 ( V_2 , 0 ) ;
F_12 ( V_130 , & V_2 -> V_18 ) ;
return V_129 ;
}
static int F_44 ( struct V_132 * V_133 )
{
F_4 ( L_39 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , T_4 V_134 )
{
if ( F_46 ( V_2 , V_134 ) == 0 )
return 0 ;
F_40 ( V_2 -> V_59 ) ;
return F_46 ( V_2 , V_134 ) ;
}
static int T_1 F_47 ( struct V_1 * V_2 , T_2 V_135 )
{
F_4 ( L_40 , V_135 ) ;
F_16 ( V_135 , V_2 -> V_77 + V_105 ) ;
if ( V_2 -> V_136 == 0 )
F_16 ( F_15 ( V_2 -> V_77 + V_137 )
| 0x0001 , V_2 -> V_77 + V_137 ) ;
else
F_16 ( F_15 ( V_2 -> V_77 + V_137 )
& ~ 0x0001 , V_2 -> V_77 + V_137 ) ;
if ( F_48 ( V_2 , 0 , 0 , V_138 ) == 0 &&
F_45 ( V_2 , V_139 ) == 0 ) {
F_49 ( F_50 ( 333 ) ) ;
return 0 ;
}
F_25 (KERN_WARNING LOGNAME L_41 ) ;
return - V_57 ;
}
static int F_51 ( struct V_140 * V_141 )
{
F_52 ( V_141 -> V_60 ) ;
F_46 ( V_141 -> V_60 , V_142 ) ;
return 0 ;
}
static void F_53 ( struct V_140 * V_141 )
{
F_46 ( V_141 -> V_60 , V_143 ) ;
F_54 ( V_141 -> V_60 ) ;
}
static int T_1 F_55 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
int V_112 ;
static struct V_144 V_145 = {
. V_146 = F_44 ,
} ;
V_112 = F_56 ( V_2 -> V_36 , F_14 , 0 , V_59 -> V_68 ,
V_2 ) ;
if ( V_112 < 0 ) {
F_25 (KERN_ERR LOGNAME L_42 , chip->irq) ;
return V_112 ;
}
if ( F_23 ( V_2 -> V_46 , V_66 , V_59 -> V_68 ) == NULL ) {
F_57 ( V_2 -> V_36 , V_2 ) ;
return - V_147 ;
}
if ( ! F_58 ( V_2 -> V_148 , V_149 , V_59 -> V_68 ) ) {
F_25 (KERN_ERR LOGNAME
L_43 ,
chip->base, chip->base + BUFFSIZE - 1 ) ;
F_24 ( V_2 -> V_46 , V_66 ) ;
F_57 ( V_2 -> V_36 , V_2 ) ;
return - V_147 ;
}
V_2 -> V_39 = F_59 ( V_2 -> V_148 , 0x8000 ) ;
if ( ! V_2 -> V_39 ) {
F_25 (KERN_ERR LOGNAME
L_44 ,
chip->base, chip->base + BUFFSIZE - 1 ) ;
V_112 = - V_57 ;
goto V_150;
}
V_112 = F_40 ( V_59 ) ;
if ( V_112 < 0 )
goto V_150;
V_112 = F_60 ( V_59 , V_151 , V_2 , & V_145 ) ;
if ( V_112 < 0 )
goto V_150;
V_112 = F_61 ( V_59 , 0 , NULL ) ;
if ( V_112 < 0 ) {
F_25 (KERN_ERR LOGNAME L_45 ) ;
goto V_150;
}
V_112 = F_62 ( V_59 ) ;
if ( V_112 < 0 ) {
F_25 (KERN_ERR LOGNAME L_46 ) ;
goto V_150;
}
if ( V_152 [ 0 ] != V_153 ) {
struct V_140 * V_141 ;
V_112 = F_63 ( V_59 , 0 , V_154 ,
V_152 [ 0 ] ,
V_155 |
V_156 ,
V_157 [ 0 ] ,
& V_2 -> V_158 ) ;
if ( V_112 < 0 ) {
F_25 (KERN_ERR LOGNAME
L_47 ) ;
goto V_150;
}
V_141 = V_2 -> V_158 -> V_60 ;
V_141 -> V_159 = F_51 ;
V_141 -> V_160 = F_53 ;
V_141 -> V_60 = V_2 ;
}
F_64 ( V_2 -> V_36 ) ;
F_47 ( V_2 , V_2 -> V_5 ) ;
F_43 ( V_2 , 0 ) ;
V_112 = F_65 ( V_59 ) ;
if ( V_112 < 0 )
goto V_150;
return 0 ;
V_150:
if ( V_2 -> V_39 )
F_66 ( V_2 -> V_39 ) ;
F_67 ( V_2 -> V_148 , V_149 ) ;
F_24 ( V_2 -> V_46 , V_66 ) ;
F_57 ( V_2 -> V_36 , V_2 ) ;
return V_112 ;
}
static void T_5 F_68 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
F_66 ( V_2 -> V_39 ) ;
F_67 ( V_2 -> V_148 , V_149 ) ;
F_24 ( V_2 -> V_46 , V_66 ) ;
F_57 ( V_2 -> V_36 , V_2 ) ;
F_69 ( V_59 ) ;
}
static int T_1 F_70 ( int V_161 , int V_162 , int V_163 )
{
F_19 ( V_162 , V_161 ) ;
F_19 ( V_163 , V_161 + 1 ) ;
if ( V_163 != F_17 ( V_161 + 1 ) ) {
F_25 (KERN_ERR LOGNAME L_48 ) ;
return - V_57 ;
}
return 0 ;
}
static int T_1 F_71 ( int V_161 , int V_164 , T_2 V_46 )
{
if ( F_70 ( V_161 , V_165 , V_164 ) )
return - V_57 ;
if ( F_70 ( V_161 , V_166 , F_3 ( V_46 ) ) )
return - V_57 ;
if ( F_70 ( V_161 , V_167 , F_5 ( V_46 ) ) )
return - V_57 ;
return 0 ;
}
static int T_1 F_72 ( int V_161 , int V_164 , T_2 V_46 )
{
if ( F_70 ( V_161 , V_165 , V_164 ) )
return - V_57 ;
if ( F_70 ( V_161 , V_168 , F_3 ( V_46 ) ) )
return - V_57 ;
if ( F_70 ( V_161 , V_169 , F_5 ( V_46 ) ) )
return - V_57 ;
return 0 ;
}
static int T_1 F_73 ( int V_161 , int V_164 , T_2 V_36 )
{
if ( F_70 ( V_161 , V_165 , V_164 ) )
return - V_57 ;
if ( F_70 ( V_161 , V_170 , F_5 ( V_36 ) ) )
return - V_57 ;
if ( F_70 ( V_161 , V_171 , V_172 ) )
return - V_57 ;
return 0 ;
}
static int T_1 F_74 ( int V_161 , int V_164 , int V_173 )
{
T_2 V_174 ;
V_173 >>= 8 ;
V_174 = ( T_2 ) ( V_173 & 0xfff ) ;
if ( F_70 ( V_161 , V_165 , V_164 ) )
return - V_57 ;
if ( F_70 ( V_161 , V_175 , F_3 ( V_174 ) ) )
return - V_57 ;
if ( F_70 ( V_161 , V_176 , F_5 ( V_174 ) ) )
return - V_57 ;
if ( V_174 && F_70 ( V_161 , V_177 ,
V_178 | V_179 ) )
return - V_57 ;
return 0 ;
}
static int T_1 F_75 ( int V_161 , int V_164 )
{
if ( F_70 ( V_161 , V_165 , V_164 ) )
return - V_57 ;
if ( F_70 ( V_161 , V_180 , V_181 ) )
return - V_57 ;
return 0 ;
}
static int T_1 F_76 ( int V_161 , int V_164 , T_2 V_182 ,
T_2 V_183 , T_2 V_36 , int V_173 )
{
if ( F_70 ( V_161 , V_165 , V_164 ) )
return - V_57 ;
if ( F_71 ( V_161 , V_164 , V_182 ) )
return - V_57 ;
if ( F_72 ( V_161 , V_164 , V_183 ) )
return - V_57 ;
if ( F_73 ( V_161 , V_164 , V_36 ) )
return - V_57 ;
if ( F_74 ( V_161 , V_164 , V_173 ) )
return - V_57 ;
if ( F_75 ( V_161 , V_164 ) )
return - V_57 ;
return 0 ;
}
static int T_1 F_77 ( int V_161 )
{
int V_184 ;
F_25 (KERN_INFO LOGNAME L_49 ) ;
for ( V_184 = 0 ; V_184 < 4 ; ++ V_184 )
if ( F_76 ( V_161 , V_184 , 0 , 0 , 0 , 0 ) )
return - V_57 ;
return 0 ;
}
static int T_1 F_78 ( struct V_133 * V_185 , unsigned int V_184 )
{
if ( V_46 [ V_184 ] == V_153 )
return 0 ;
if ( V_36 [ V_184 ] == V_153 || V_173 [ V_184 ] == V_153 ) {
F_25 (KERN_WARNING LOGNAME L_50 ) ;
return 0 ;
}
#ifdef F_10
if ( ! ( V_46 [ V_184 ] == 0x290 ||
V_46 [ V_184 ] == 0x260 ||
V_46 [ V_184 ] == 0x250 ||
V_46 [ V_184 ] == 0x240 ||
V_46 [ V_184 ] == 0x230 ||
V_46 [ V_184 ] == 0x220 ||
V_46 [ V_184 ] == 0x210 ||
V_46 [ V_184 ] == 0x3e0 ) ) {
F_25 (KERN_ERR LOGNAME L_51
L_52
L_53 ) ;
return 0 ;
}
#else
if ( V_46 [ V_184 ] < 0x100 || V_46 [ V_184 ] > 0x3e0 || ( V_46 [ V_184 ] % 0x10 ) != 0 ) {
F_25 (KERN_ERR LOGNAME
L_54
L_55 ) ;
return 0 ;
}
#endif
if ( ! ( V_36 [ V_184 ] == 5 ||
V_36 [ V_184 ] == 7 ||
V_36 [ V_184 ] == 9 ||
V_36 [ V_184 ] == 10 ||
V_36 [ V_184 ] == 11 ||
V_36 [ V_184 ] == 12 ) ) {
F_25 (KERN_ERR LOGNAME
L_56 ) ;
return 0 ;
}
if ( ! ( V_173 [ V_184 ] == 0xb0000 ||
V_173 [ V_184 ] == 0xc8000 ||
V_173 [ V_184 ] == 0xd0000 ||
V_173 [ V_184 ] == 0xd8000 ||
V_173 [ V_184 ] == 0xe0000 ||
V_173 [ V_184 ] == 0xe8000 ) ) {
F_25 (KERN_ERR LOGNAME L_57
L_58
L_59 ) ;
return 0 ;
}
#ifndef F_10
if ( V_161 [ V_184 ] == V_153 ) {
F_25 (KERN_INFO LOGNAME L_60 ) ;
} else if ( V_161 [ V_184 ] != 0x250 && V_161 [ V_184 ] != 0x260 && V_161 [ V_184 ] != 0x270 ) {
F_25 (KERN_INFO LOGNAME
L_61
L_62 ) ;
return 0 ;
}
#endif
return 1 ;
}
static int T_1 F_79 ( struct V_133 * V_185 , unsigned int V_186 )
{
int V_112 ;
struct V_58 * V_59 ;
struct V_1 * V_2 ;
if ( F_80 ( V_186 )
#ifndef F_10
|| V_161 [ V_186 ] == V_153
#endif
) {
F_25 (KERN_INFO LOGNAME L_60 ) ;
return - V_67 ;
}
V_112 = F_81 ( V_187 [ V_186 ] , V_188 [ V_186 ] , V_189 ,
sizeof( struct V_1 ) , & V_59 ) ;
if ( V_112 < 0 )
return V_112 ;
F_82 ( V_59 , V_185 ) ;
V_2 = V_59 -> V_60 ;
V_2 -> V_59 = V_59 ;
#ifdef F_10
switch ( V_36 [ V_186 ] ) {
case 5 :
V_2 -> V_190 = V_191 ; break;
case 7 :
V_2 -> V_190 = V_192 ; break;
case 9 :
V_2 -> V_190 = V_193 ; break;
case 10 :
V_2 -> V_190 = V_194 ; break;
case 11 :
V_2 -> V_190 = V_195 ; break;
case 12 :
V_2 -> V_190 = V_196 ; break;
}
switch ( V_173 [ V_186 ] ) {
case 0xb0000 :
V_2 -> V_73 = V_197 ; break;
case 0xc8000 :
V_2 -> V_73 = V_198 ; break;
case 0xd0000 :
V_2 -> V_73 = V_199 ; break;
case 0xd8000 :
V_2 -> V_73 = V_200 ; break;
case 0xe0000 :
V_2 -> V_73 = V_201 ; break;
case 0xe8000 :
V_2 -> V_73 = V_202 ; break;
}
#else
F_25 (KERN_INFO LOGNAME L_63 ,
cfg[idx]) ;
if ( ! F_23 ( V_161 [ V_186 ] , 2 , L_64 ) ) {
F_25 (KERN_ERR LOGNAME L_65 ,
cfg[idx]) ;
F_69 ( V_59 ) ;
return - V_57 ;
}
if ( V_203 [ V_186 ] )
if ( F_77 ( V_161 [ V_186 ] ) ) {
V_112 = - V_57 ;
goto V_204;
}
V_112 = F_76 ( V_161 [ V_186 ] , 0 ,
V_46 [ V_186 ] , 0 ,
V_36 [ V_186 ] , V_173 [ V_186 ] ) ;
if ( V_112 )
goto V_204;
if ( V_152 [ V_186 ] != V_153
&& V_157 [ V_186 ] != V_205 ) {
F_25 (KERN_INFO LOGNAME
L_66 ,
mpu_io[idx], mpu_irq[idx]) ;
V_112 = F_76 ( V_161 [ V_186 ] , 1 ,
V_152 [ V_186 ] , 0 ,
V_157 [ V_186 ] , 0 ) ;
if ( V_112 )
goto V_204;
}
if ( V_206 [ V_186 ] != V_153
&& V_207 [ V_186 ] != V_153
&& V_208 [ V_186 ] != V_205 ) {
F_25 (KERN_INFO LOGNAME
L_67 ,
ide_io0[idx], ide_io1[idx], ide_irq[idx]) ;
V_112 = F_76 ( V_161 [ V_186 ] , 2 ,
V_206 [ V_186 ] , V_207 [ V_186 ] ,
V_208 [ V_186 ] , 0 ) ;
if ( V_112 )
goto V_204;
}
if ( V_209 [ V_186 ] != V_153 ) {
F_25 (KERN_INFO LOGNAME
L_68 ,
joystick_io[idx]) ;
V_112 = F_76 ( V_161 [ V_186 ] , 3 ,
V_209 [ V_186 ] , 0 ,
0 , 0 ) ;
if ( V_112 )
goto V_204;
}
F_24 ( V_161 [ V_186 ] , 2 ) ;
#endif
F_1 ( V_2 ) ;
#ifdef F_10
V_2 -> type = V_210 ;
#else
V_2 -> type = V_211 ;
#endif
V_2 -> V_46 = V_46 [ V_186 ] ;
V_2 -> V_36 = V_36 [ V_186 ] ;
V_2 -> V_148 = V_173 [ V_186 ] ;
V_2 -> V_136 = V_136 ? 1 : 0 ;
V_2 -> V_212 = 0 ;
V_2 -> V_213 = V_40 ;
V_2 -> V_214 = V_100 ;
if ( V_215 [ V_186 ] )
F_12 ( V_216 , & V_2 -> V_18 ) ;
else
F_41 ( V_216 , & V_2 -> V_18 ) ;
#ifndef F_10
if ( V_217 [ V_186 ] )
F_41 ( V_218 , & V_2 -> V_18 ) ;
#endif
F_83 ( & V_2 -> V_81 ) ;
V_112 = F_22 ( V_59 ) ;
if ( V_112 < 0 ) {
F_25 (KERN_ERR LOGNAME L_69 ) ;
F_69 ( V_59 ) ;
return V_112 ;
}
V_112 = F_55 ( V_59 ) ;
if ( V_112 < 0 ) {
F_25 (KERN_ERR LOGNAME L_70 ) ;
F_69 ( V_59 ) ;
return V_112 ;
}
F_84 ( V_185 , V_59 ) ;
return 0 ;
#ifndef F_10
V_204:
F_24 ( V_161 [ V_186 ] , 2 ) ;
F_69 ( V_59 ) ;
return V_112 ;
#endif
}
static int T_5 F_85 ( struct V_133 * V_185 , unsigned int V_114 )
{
F_68 ( F_86 ( V_185 ) ) ;
F_84 ( V_185 , NULL ) ;
return 0 ;
}
static int T_1 F_87 ( struct V_219 * V_220 ,
const struct V_221 * V_222 )
{
static int V_186 ;
struct V_223 * V_223 ;
struct V_223 * V_224 ;
struct V_58 * V_59 ;
struct V_1 * V_2 ;
int V_225 ;
for ( ; V_186 < V_226 ; V_186 ++ ) {
if ( F_80 ( V_186 ) )
break;
}
if ( V_186 >= V_226 )
return - V_67 ;
V_223 = F_88 ( V_220 , V_222 -> V_227 [ 0 ] . V_188 , NULL ) ;
if ( ! V_223 )
return - V_67 ;
V_224 = F_88 ( V_220 , V_222 -> V_227 [ 1 ] . V_188 , NULL ) ;
if ( ! V_224 )
return - V_67 ;
if ( ! F_89 ( V_223 ) && F_90 ( V_223 ) < 0 ) {
F_25 ( V_228 L_71 ) ;
return - V_147 ;
}
if ( ! F_89 ( V_224 ) && F_90 ( V_224 ) < 0 ) {
F_25 ( V_228 L_72 ) ;
return - V_147 ;
}
V_225 = F_81 ( V_187 [ V_186 ] , V_188 [ V_186 ] , V_189 ,
sizeof( struct V_1 ) , & V_59 ) ;
if ( V_225 < 0 )
return V_225 ;
V_2 = V_59 -> V_60 ;
V_2 -> V_59 = V_59 ;
F_82 ( V_59 , & V_220 -> V_59 -> V_114 ) ;
V_46 [ V_186 ] = F_91 ( V_223 , 0 ) ;
V_36 [ V_186 ] = F_92 ( V_223 , 0 ) ;
V_173 [ V_186 ] = F_93 ( V_223 , 0 ) ;
V_152 [ V_186 ] = F_91 ( V_224 , 0 ) ;
V_157 [ V_186 ] = F_92 ( V_224 , 0 ) ;
F_1 ( V_2 ) ;
#ifdef F_10
V_2 -> type = V_210 ;
#else
V_2 -> type = V_211 ;
#endif
V_2 -> V_46 = V_46 [ V_186 ] ;
V_2 -> V_36 = V_36 [ V_186 ] ;
V_2 -> V_148 = V_173 [ V_186 ] ;
V_2 -> V_136 = V_136 ? 1 : 0 ;
V_2 -> V_212 = 0 ;
V_2 -> V_213 = V_40 ;
V_2 -> V_214 = V_100 ;
if ( V_215 [ V_186 ] )
F_12 ( V_216 , & V_2 -> V_18 ) ;
else
F_41 ( V_216 , & V_2 -> V_18 ) ;
#ifndef F_10
if ( V_217 [ V_186 ] )
F_41 ( V_218 , & V_2 -> V_18 ) ;
#endif
F_83 ( & V_2 -> V_81 ) ;
V_225 = F_22 ( V_59 ) ;
if ( V_225 < 0 ) {
F_25 (KERN_ERR LOGNAME L_69 ) ;
goto V_229;
}
V_225 = F_55 ( V_59 ) ;
if ( V_225 < 0 ) {
F_25 (KERN_ERR LOGNAME L_70 ) ;
goto V_229;
}
F_94 ( V_220 , V_59 ) ;
++ V_186 ;
return 0 ;
V_229:
F_69 ( V_59 ) ;
return V_225 ;
}
static void T_5 F_95 ( struct V_219 * V_220 )
{
F_68 ( F_96 ( V_220 ) ) ;
F_94 ( V_220 , NULL ) ;
}
static int T_6 F_97 ( void )
{
int V_112 ;
V_112 = F_98 ( & V_230 , V_226 ) ;
#ifdef F_99
if ( ! V_112 )
V_231 = 1 ;
V_112 = F_100 ( & V_232 ) ;
if ( ! V_112 )
V_233 = 1 ;
if ( V_231 )
V_112 = 0 ;
#endif
return V_112 ;
}
static void T_7 F_101 ( void )
{
#ifdef F_99
if ( V_233 )
F_102 ( & V_232 ) ;
if ( V_231 )
#endif
F_103 ( & V_230 ) ;
}
