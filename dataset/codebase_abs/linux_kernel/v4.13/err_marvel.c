static void
F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
struct V_3 * V_4 ;
struct { int type ; char * V_5 ; } V_6 [] = {
{ V_7 ,
L_1 } ,
{ V_8 ,
L_2 } ,
{ V_9 ,
L_3 } ,
{ V_10 ,
L_4 } ,
{ V_11 ,
L_5 } ,
{ V_12 ,
L_6 } ,
{ V_13 ,
L_7 } ,
{ 0 , NULL }
} ;
int V_14 ;
for ( V_14 = 0 ; V_6 [ V_14 ] . type != 0 ; V_14 ++ ) {
V_4 = V_2 -> V_4 [ F_3 ( V_6 [ V_14 ] . type ) ] ;
if ( ! V_4 )
continue;
F_4 ( L_8 ,
V_15 ,
V_6 [ V_14 ] . V_5 ,
V_4 -> V_16 ,
V_4 -> V_17 ) ;
F_4 ( L_9
L_10 ,
V_15 ,
V_4 -> V_18 ,
V_4 -> V_19 ,
V_4 -> V_20 ) ;
}
#endif
}
static int
F_5 ( struct V_1 * V_2 , int V_21 )
{
int V_22 = V_23 ;
int V_14 ;
for ( V_14 = F_3 ( V_7 ) ;
V_14 <= F_3 ( V_13 ) ;
V_14 ++ ) {
if ( V_2 -> V_4 [ V_14 ] )
V_22 = V_24 ;
}
if ( V_21 )
F_1 ( V_2 ) ;
return V_22 ;
}
static void
F_6 ( T_1 V_25 )
{
static char * V_26 [] = {
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 ,
L_12 ,
L_12 ,
L_12
} ;
#define F_7 (1UL << 0)
#define F_8 (1UL << 1)
#define F_9 (6)
#define F_10 (0x7)
#define F_11 (1UL << 5)
#define F_12 (2)
#define F_13 (0x7)
F_4 ( L_17
L_18 ,
V_15 ,
V_26 [ F_14 ( V_25 , V_27 ) ] ,
V_15 ,
( V_25 & F_11 ) ? L_19 : L_20 ,
F_14 ( V_25 , V_28 ) ,
( V_25 & F_7 ) ? L_21 : L_22 ,
( V_25 & F_8 ) ? L_23 : L_22 ) ;
}
static void
F_15 ( T_1 V_29 )
{
#define F_16 (0)
#define F_17 (0x7f)
#define F_18 (7)
#define F_19 (0x1ff)
F_4 ( L_24
L_25 ,
V_15 ,
V_15 , F_14 ( V_29 , V_30 ) ) ;
F_6 ( F_14 ( V_29 , V_31 ) ) ;
}
static void
F_20 ( T_1 V_32 , T_1 V_33 )
{
static char * V_34 [] = { L_26 , L_27 , L_28 , L_29 } ;
static char * V_35 [] = {
L_11 ,
L_30 ,
L_31 ,
L_32
} ;
static char * V_36 [] = { L_33 , L_34 ,
L_35 , L_36 ,
L_37 , L_37 ,
L_37 , L_38 } ;
int V_37 , V_14 ;
#define F_21 (0)
#define F_22 (0x7f)
#define F_23 (7)
#define F_24 (0x1ff)
#define F_25 (16)
#define F_26 (0xff)
#define F_27 (1UL << 24)
#define F_28 (1UL << 25)
#define F_29 (1UL << 26)
#define F_30 (1UL << 27)
#define F_31 (1UL << 28)
#define F_32 (1UL << 29)
#define F_33 (1UL << 30)
#define F_34 (1UL << 31)
#define F_35 (32)
#define F_36 (0xff)
#define F_37 (40)
#define F_38 (0xff)
#define F_39 (48)
#define F_40 (0x3ff)
#define F_41 (0)
#define F_42 (0x3)
#define F_43 (2)
#define F_44 (0x7)
#define F_45 (5)
#define F_46 (0x3)
#define F_47 (0)
#define F_48 (0x1ff)
#define F_49 (1UL << 9)
F_4 ( L_39 , V_15 ) ;
V_32 &= V_33 ;
if ( F_14 ( V_33 , V_38 ) )
F_4 ( L_25 ,
V_15 ,
F_14 ( V_32 , V_38 ) ) ;
if ( F_14 ( V_33 , V_39 ) )
F_6 ( F_14 ( V_32 ,
V_39 ) ) ;
V_37 = F_14 ( V_32 , V_40 ) ;
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ , V_37 >>= 2 ) {
if ( V_37 & 0x3 )
F_4 ( L_40 ,
V_15 ,
V_34 [ V_14 ] , V_35 [ V_37 & 0x3 ] ) ;
}
if ( V_32 & F_27 )
F_4 ( L_41 ,
V_15 ) ;
if ( V_32 & F_28 )
F_4 ( L_42 ,
V_15 ) ;
if ( V_32 & F_29 )
F_4 ( L_43 ,
V_15 ) ;
if ( V_32 & F_30 )
F_4 ( L_44 ,
V_15 ) ;
if ( V_32 & F_31 )
F_4 ( L_45 ,
V_15 ) ;
if ( V_32 & F_32 )
F_4 ( L_46 ,
V_15 ) ;
if ( V_32 & F_33 )
F_4 ( L_47 ,
V_15 ) ;
if ( V_32 & F_34 )
F_4 ( L_48 ,
V_15 ) ;
if ( ( V_37 = F_14 ( V_32 , V_41 ) ) ) {
int V_42 = V_37 & ( 1UL << 4 ) ;
V_37 &= ~ V_42 ;
for ( V_14 = 0 ; V_14 < 8 ; V_14 ++ , V_37 >>= 1 ) {
if ( ! ( V_37 & 1 ) )
continue;
F_4 ( L_49 ,
V_15 , V_36 [ V_14 ] ) ;
}
if ( V_42 )
F_4 ( L_50 ,
V_15 ) ;
}
if ( ( V_37 = F_14 ( V_32 , V_43 ) ) ) {
for ( V_14 = 0 ; V_14 < 8 ; V_14 ++ , V_37 >>= 1 ) {
if ( ! ( V_37 & 1 ) )
continue;
F_4 ( L_51 ,
V_15 , V_36 [ V_14 ] ) ;
}
}
if ( F_14 ( V_33 , V_44 ) ) {
char V_45 [ 80 ] ;
V_37 = F_14 ( V_32 , V_44 ) ;
if ( V_37 & F_49 )
sprintf ( V_45 ,
L_52 ,
F_14 ( V_37 , V_46 ) ) ;
else
sprintf ( V_45 ,
L_53 ,
'A' + F_14 ( V_37 ,
V_47 ) ,
F_14 ( V_37 , V_48 ) ,
F_14 ( V_37 , V_49 ) ) ;
F_4 ( L_54 ,
V_15 , V_45 ) ;
}
}
static void
F_50 ( T_1 V_50 )
{
char V_51 [ 10 ] ;
#define F_51 (6)
#define F_52 (0xfffffffful)
#define F_53 (40)
#define F_54 (0xff)
#define F_55 (48)
#define F_56 (0xf)
#define F_57 (52)
#define F_58 (0x7ff)
#define F_59 (1UL << 63)
if ( ! ( V_50 & F_59 ) )
return;
switch( F_14 ( V_50 , V_52 ) ) {
case 0x51 :
sprintf ( V_51 , L_55 ) ;
break;
case 0x50 :
sprintf ( V_51 , L_56 ) ;
break;
case 0x54 :
sprintf ( V_51 , L_57 ) ;
break;
case 0xD8 :
sprintf ( V_51 , L_58 ) ;
break;
case 0xC5 :
sprintf ( V_51 , L_59 ) ;
break;
default:
sprintf ( V_51 , L_60 ,
F_14 ( V_50 , V_52 ) ) ;
break;
}
F_4 ( L_61
L_62 ,
V_15 ,
V_15 ,
F_14 ( V_50 , V_53 ) ,
F_14 ( V_50 , V_54 ) ,
V_51 ) ;
if ( 0xC5 != F_14 ( V_50 , V_52 ) )
F_4 ( L_63 ,
V_15 ,
F_14 ( V_50 , V_55 ) ) ;
}
static void
F_60 ( struct V_56 * V_57 )
{
T_1 V_58 = 0 ;
#define F_61 (1UL << 32)
#define F_62 (1UL << 33)
#define F_63 (1UL << 34)
#define F_64 (1UL << 35)
#define F_65 (1UL << 36)
#define F_66 (1UL << 37)
#define F_67 (1UL << 38)
#define F_68 (1UL << 39)
#define F_69 (1UL << 40)
#define F_70 (1UL << 41)
#define F_71 (1UL << 42)
#define F_72 (1UL << 43)
#define F_73 (1UL << 44)
#define F_74 (1UL << 45)
#define F_75 (1UL << 46)
#define F_76 (1UL << 47)
#define F_77 (1UL << 51)
#define F_78 (1UL << 52)
#define F_79 (1UL << 53)
#define F_80 (1UL << 54)
#define F_81 (1UL << 55)
#define F_82 (1UL << 56)
#define F_83 (1UL << 57)
#define F_84 (1UL << 58)
#define F_85 (1UL << 59)
#define F_86 (1UL << 60)
#define F_87 (1UL << 61)
#define F_88 (1UL << 62)
#define F_89 (1UL << 63)
#define F_90 (IO7__PO7_ERRSUM__ERR_VALID | \
IO7__PO7_ERRSUM__CR_SBE)
if ( V_57 -> V_59 & F_61 ) {
F_4 ( L_64 ,
V_15 ,
( V_57 -> V_59 & F_62 )
? L_65 : L_22 ) ;
F_15 ( V_57 -> V_60 ) ;
}
if ( V_57 -> V_59 & F_82 )
F_4 ( L_66 , V_15 ) ;
if ( V_57 -> V_59 & F_83 ) {
F_4 ( L_67 ,
V_15 ) ;
V_58 |= F_91 ( V_43 ) ;
}
if ( V_57 -> V_59 & F_84 )
F_4 ( L_68 ,
V_15 ) ;
if ( V_57 -> V_59 & F_85 ) {
F_4 ( L_69 , V_15 ) ;
V_58 |= F_91 ( V_44 ) ;
}
if ( V_57 -> V_59 & F_86 ) {
F_4 ( L_70 , V_15 ) ;
V_58 |= F_91 ( V_43 ) ;
}
if ( ! ( V_57 -> V_59 & F_89 ) )
goto V_61;
V_58 |= F_91 ( V_41 ) ;
if ( ! ( V_57 -> V_59 & ( F_63 |
F_64 |
F_66 |
F_67 |
F_71 ) ) )
V_58 |= 0x3ffffffful ;
if ( V_57 -> V_59 & F_63 )
F_4 ( L_71 , V_15 ) ;
if ( V_57 -> V_59 & F_64 )
F_4 ( L_72 , V_15 ) ;
if ( V_57 -> V_59 & F_65 )
F_4 ( L_73 ,
V_15 ) ;
if ( V_57 -> V_59 & F_66 )
F_4 ( L_74 ,
V_15 ) ;
if ( V_57 -> V_59 & F_67 )
F_4 ( L_75 , V_15 ) ;
if ( V_57 -> V_59 & F_68 )
F_4 ( L_76 , V_15 ) ;
if ( V_57 -> V_59 & F_69 )
F_4 ( L_77 ,
V_15 ) ;
if ( V_57 -> V_59 & F_70 )
F_4 ( L_78 ,
V_15 ) ;
if ( V_57 -> V_59 & F_72 ) {
F_4 ( L_79 ,
V_15 ) ;
F_50 ( V_57 -> V_62 ) ;
}
if ( V_57 -> V_59 & F_73 )
F_4 ( L_80 ,
V_15 ) ;
if ( V_57 -> V_59 & F_74 )
F_4 ( L_81 , V_15 ) ;
if ( V_57 -> V_59 & F_75 )
F_4 ( L_82 , V_15 ) ;
if ( V_57 -> V_59 & F_76 )
F_4 ( L_83 ,
V_15 ) ;
if ( V_57 -> V_59 & F_71 )
F_4 ( L_84 ,
V_15 ) ;
if ( V_57 -> V_59 & F_77 )
F_4 ( L_85 , V_15 ) ;
if ( V_57 -> V_59 & F_78 )
F_4 ( L_86 ,
V_15 ) ;
if ( V_57 -> V_59 & F_79 )
F_4 ( L_87 ,
V_15 ) ;
if ( V_57 -> V_59 & F_80 )
F_4 ( L_88 ,
V_15 ) ;
if ( V_57 -> V_59 & F_81 )
F_4 ( L_89 ,
V_15 ) ;
if ( V_57 -> V_59 & F_88 )
F_4 ( L_90 , V_15 ) ;
F_4 ( L_91
L_92
L_93 ,
V_15 ,
V_15 , V_57 -> V_63 ,
V_15 , V_57 -> V_64 ) ;
V_61:
if ( V_58 )
F_20 ( V_57 -> V_65 , V_58 ) ;
}
static void
F_92 ( T_1 V_66 )
{
static char * V_67 [] = {
L_11 ,
L_94 ,
L_95 ,
L_96
} ;
#define F_93 (1UL << 63)
#define F_94 (0)
#define F_95 (0x3)
#define F_96 (3)
#define F_97 (0x7)
#define F_98 (6)
#define F_99 (0x3fffffffffful)
if ( ! ( V_66 & F_93 ) )
return;
F_4 ( L_97
L_98
L_99 ,
V_15 ,
F_14 ( V_66 , V_68 ) ,
V_15 ,
V_67 [ F_14 ( V_66 , V_69 ) ] ,
V_15 ,
F_14 ( V_66 , V_70 ) << 6 ) ;
}
static void
F_100 ( T_1 V_71 )
{
char V_72 [ 80 ] ;
#define F_101 (0)
#define F_102 (0x0fffffffful)
#define F_103 (40)
#define F_104 (0xfful)
#define F_105 (35)
#define F_106 (0x1ful)
#define F_107 (32)
#define F_108 (0x07ul)
#define F_109 (28)
#define F_110 (0xf)
#define F_111 (20)
#define F_112 (0xff)
#define F_113 (20)
#define F_114 (0xfff)
#define F_115 (12)
#define F_116 (0x7f)
#define F_117 (0)
#define F_118 (0xfff)
F_4 ( L_100
L_101 ,
V_15 ,
V_15 ,
F_14 ( V_71 , V_73 ) ,
F_14 ( V_71 , V_74 ) ,
F_14 ( V_71 , V_75 ) ) ;
switch( F_14 ( V_71 , V_76 ) ) {
case 0x000 :
sprintf ( V_72 , L_102 ) ;
break;
case 0x100 :
sprintf ( V_72 , L_103 ) ;
break;
case 0x101 :
sprintf ( V_72 , L_104 ) ;
break;
case 0x102 :
sprintf ( V_72 , L_105 ) ;
break;
case 0x200 :
sprintf ( V_72 , L_106 ) ;
break;
case 0x201 :
sprintf ( V_72 , L_107 ) ;
break;
default:
sprintf ( V_72 , L_108 ,
F_14 ( V_71 , V_77 ) ) ;
break;
}
F_4 ( L_109 , V_15 , V_72 ) ;
}
static void
F_119 ( T_1 V_78 )
{
static const char * const V_79 [] = {
L_110 ,
L_111 ,
L_112 ,
L_113 ,
L_114 ,
L_115 ,
L_116 ,
L_117 ,
L_118 ,
L_119 ,
L_120 ,
L_121 ,
L_122 ,
L_123 ,
L_124 ,
L_125
} ;
#define F_120 (0)
#define F_121 (0x3fffffffffffful)
#define F_122 (1UL << 50)
#define F_123 (52)
#define F_124 (0xf)
#define F_125 (56)
#define F_126 (0xf)
#define F_127 (1UL << 63)
if ( ! ( V_78 & F_127 ) )
return;
F_4 ( L_126
L_127
L_128
L_129 ,
V_15 ,
V_15 ,
F_14 ( V_78 , V_80 ) ,
V_79 [ F_14 ( V_78 , V_80 ) ] ,
V_15 ,
F_14 ( V_78 , V_81 ) ,
( V_78 & F_122 ) ? L_130 : L_22 ,
V_15 ,
F_14 ( V_78 , V_82 ) ) ;
}
static void
F_128 ( T_1 V_83 , struct V_84 * V_85 )
{
#define F_129 (1UL << 4)
#define F_130 (1UL << 5)
#define F_131 (1UL << 6)
#define F_132 (1UL << 7)
#define F_133 (1UL << 8)
#define F_134 (1UL << 9)
#define F_135 (1UL << 10)
#define F_136 (1UL << 11)
#define F_137 (1UL << 12)
#define F_138 (1UL << 13)
#define F_139 (1UL << 14)
#define F_140 (1UL << 15)
#define F_141 (IO7__POX_ERRSUM__ALL_MABORTS|\
IO7__POX_ERRSUM__MABORT)
#define F_142 (1UL << 16)
#define F_143 (1UL << 17)
#define F_144 (IO7__POX_ERRSUM__PT_TABORT | \
IO7__POX_ERRSUM__PM_TABORT)
#define F_145 (1UL << 18)
#define F_146 (1UL << 19)
#define F_147 (1UL << 20)
#define F_148 (1UL << 21)
#define F_149 (1UL << 22)
#define F_150 (1UL << 23)
#define F_151 (1UL << 24)
#define F_152 (1UL << 26)
#define F_153 (1UL << 28)
#define F_154 (51)
#define F_155 (0xffUL)
#define F_156 GEN_MASK(IO7__POX_ERRSUM__UPE_ERROR)
#define F_157 (1UL << 59)
#define F_158 (1UL << 63)
#define F_159 (IO7__POX_ERRSUM__MRETRY_TO | \
IO7__POX_ERRSUM__PCIX_UX_SPL | \
IO7__POX_ERRSUM__PCIX_SPLIT_TO | \
IO7__POX_ERRSUM__DMA_TO | \
IO7__POX_ERRSUM__MABORT_MASK | \
IO7__POX_ERRSUM__TABORT_MASK | \
IO7__POX_ERRSUM__SERR | \
IO7__POX_ERRSUM__ADDRERR_STB | \
IO7__POX_ERRSUM__PERR | \
IO7__POX_ERRSUM__DATAERR_STB_NIOW |\
IO7__POX_ERRSUM__DETECTED_PERR | \
IO7__POX_ERRSUM__PM_PERR | \
IO7__POX_ERRSUM__PT_SCERROR | \
IO7__POX_ERRSUM__UPE_ERROR)
if ( ! ( V_83 & F_158 ) )
return;
if ( V_83 & F_131 )
F_4 ( L_131 ,
V_15 ) ;
if ( V_83 & F_132 )
F_4 ( L_132 ,
V_15 ) ;
if ( V_83 & F_133 )
F_4 ( L_133 ,
V_15 ) ;
if ( V_83 & F_138 )
F_4 ( L_134 ,
V_15 ) ;
if ( V_83 & F_141 )
F_4 ( L_135 , V_15 ) ;
if ( V_83 & F_142 )
F_4 ( L_136 , V_15 ) ;
if ( V_83 & F_143 )
F_4 ( L_137 , V_15 ) ;
if ( V_83 & F_146 ) {
F_4 ( L_138 ,
V_15 ) ;
if ( V_83 & F_145 )
F_4 ( L_139 , V_15 ) ;
}
if ( V_83 & F_148 ) {
if ( V_83 & F_149 )
F_4 ( L_140 ,
V_15 ) ;
else
F_4 ( L_141
L_142 , V_15 ) ;
}
if ( V_83 & F_150 )
F_4 ( L_143 , V_15 ) ;
if ( V_83 & F_151 )
F_4 ( L_144 , V_15 ) ;
if ( V_83 & F_152 ) {
F_4 ( L_145 ,
V_15 ) ;
F_100 ( V_85 -> V_86 ) ;
}
if ( V_83 & F_156 ) {
unsigned int V_87 = F_14 ( V_83 ,
F_156 ) ;
int V_14 ;
static char * V_88 [] = {
L_146 ,
L_147 ,
L_148 ,
L_149 ,
L_150 ,
L_151 ,
L_152 ,
L_153
} ;
F_4 ( L_154 , V_15 ) ;
for ( V_14 = 0 ; V_14 < 8 ; V_14 ++ ) {
if ( V_87 & ( 1 << V_14 ) )
F_4 ( L_155 , V_15 ,
V_88 [ V_14 ] ) ;
}
}
if ( V_83 & F_159 )
F_119 ( V_85 -> V_89 ) ;
if ( V_83 & F_157 ) {
F_4 ( L_156 , V_15 ) ;
F_92 ( V_85 -> V_90 ) ;
}
if ( V_83 & F_129 )
F_4 ( L_157 , V_15 ) ;
if ( V_83 & F_130 )
F_4 ( L_158 , V_15 ) ;
if ( V_83 & F_134 )
F_4 ( L_159 , V_15 ) ;
if ( V_83 & F_135 )
F_4 ( L_160 , V_15 ) ;
if ( V_83 & F_136 )
F_4 ( L_161 , V_15 ) ;
if ( V_83 & F_137 )
F_4 ( L_162 , V_15 ) ;
if ( V_83 & F_147 )
F_4 ( L_163 , V_15 ) ;
if ( V_83 & F_153 )
F_4 ( L_164 , V_15 ) ;
}
static struct V_56 *
F_160 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = V_2 -> V_57 ;
struct V_91 * V_91 ;
int V_14 ;
if ( ! V_57 )
return NULL ;
memset ( V_57 , 0x55 , sizeof( * V_57 ) ) ;
for ( V_91 = NULL ; NULL != ( V_91 = F_161 ( V_91 ) ) ; ) {
unsigned long V_83 = 0 ;
V_83 |= V_91 -> V_92 -> V_93 . V_94 ;
for ( V_14 = 0 ; V_14 < V_95 ; V_14 ++ ) {
if ( ! V_91 -> V_96 [ V_14 ] . V_97 )
continue;
V_83 |= V_91 -> V_96 [ V_14 ] . V_92 -> V_98 . V_94 ;
}
if ( V_83 & ( 1UL << 63 ) )
break;
}
if ( ! V_91 )
return NULL ;
V_57 -> V_99 = V_91 -> V_92 -> V_100 . V_94 ;
V_57 -> V_101 = V_91 -> V_92 -> V_102 . V_94 ;
V_57 -> V_103 = V_91 -> V_92 -> V_104 . V_94 ;
V_57 -> V_105 = V_91 -> V_92 -> V_106 . V_94 ;
V_57 -> V_107 = V_91 -> V_92 -> V_108 . V_94 ;
V_57 -> V_109 = V_91 -> V_92 -> V_110 . V_94 ;
V_57 -> V_59 = V_91 -> V_92 -> V_93 . V_94 ;
V_57 -> V_65 = V_91 -> V_92 -> V_111 . V_94 ;
V_57 -> V_60 = V_91 -> V_92 -> V_112 . V_94 ;
V_57 -> V_62 = V_91 -> V_92 -> V_113 . V_94 ;
V_57 -> V_63 = V_91 -> V_92 -> V_114 [ 0 ] . V_94 ;
V_57 -> V_64 = V_91 -> V_92 -> V_114 [ 1 ] . V_94 ;
for ( V_14 = 0 ; V_14 < V_95 ; V_14 ++ ) {
T_2 * V_92 = V_91 -> V_96 [ V_14 ] . V_92 ;
if ( ! V_91 -> V_96 [ V_14 ] . V_97 )
continue;
V_57 -> V_96 [ V_14 ] . V_115 = V_92 -> V_98 . V_94 ;
V_57 -> V_96 [ V_14 ] . V_90 = V_92 -> V_116 . V_94 ;
V_57 -> V_96 [ V_14 ] . V_86 = V_92 -> V_117 . V_94 ;
V_57 -> V_96 [ V_14 ] . V_89 = V_92 -> V_118 . V_94 ;
V_57 -> V_96 [ V_14 ] . V_119 = V_92 -> V_120 . V_94 ;
V_57 -> V_96 [ V_14 ] . V_121 = V_92 -> V_122 . V_94 ;
V_57 -> V_96 [ V_14 ] . V_123 = V_92 -> V_124 . V_94 ;
V_57 -> V_96 [ V_14 ] . V_125 = V_92 -> V_126 . V_94 ;
V_57 -> V_96 [ V_14 ] . V_127 = V_92 -> V_128 . V_94 ;
V_57 -> V_96 [ V_14 ] . V_129 = V_92 -> V_130 . V_94 ;
V_92 -> V_116 . V_94 = V_57 -> V_96 [ V_14 ] . V_90 ;
V_92 -> V_98 . V_94 = V_57 -> V_96 [ V_14 ] . V_115 ;
F_162 () ;
V_92 -> V_98 . V_94 ;
}
V_91 -> V_92 -> V_93 . V_94 = V_57 -> V_59 ;
F_162 () ;
V_91 -> V_92 -> V_93 . V_94 ;
V_2 -> V_131 = V_91 -> V_132 ;
return V_57 ;
}
static int
F_163 ( struct V_1 * V_2 , int V_21 )
{
int V_22 = V_23 ;
#ifdef F_2
struct V_56 * V_57 = V_2 -> V_57 ;
int V_14 ;
#endif
#define F_164 ( T_3 ) ((x) & (1UL << 63))
if ( ! V_2 -> V_133 || ! V_2 -> V_57 )
return V_22 ;
if ( ( V_2 -> V_57 -> V_59 & ( 1UL << 32 ) ) ||
( ( V_2 -> V_57 -> V_59 |
V_2 -> V_57 -> V_96 [ 0 ] . V_115 |
V_2 -> V_57 -> V_96 [ 1 ] . V_115 |
V_2 -> V_57 -> V_96 [ 2 ] . V_115 |
V_2 -> V_57 -> V_96 [ 3 ] . V_115 ) & ( 1UL << 63 ) ) ) {
if ( ! F_160 ( V_2 ) )
return V_22 ;
}
V_22 = V_24 ;
#ifdef F_2
if ( ! V_21 )
return V_22 ;
F_4 ( L_165 ,
V_15 , V_2 -> V_131 ) ;
if ( V_2 -> V_57 -> V_59 & F_90 ) {
F_60 ( V_57 ) ;
#if 0
printk("%s PORT 7 ERROR:\n"
"%s PO7_ERROR_SUM: %016llx\n"
"%s PO7_UNCRR_SYM: %016llx\n"
"%s PO7_CRRCT_SYM: %016llx\n"
"%s PO7_UGBGE_SYM: %016llx\n"
"%s PO7_ERR_PKT0: %016llx\n"
"%s PO7_ERR_PKT1: %016llx\n",
err_print_prefix,
err_print_prefix, io->po7_error_sum,
err_print_prefix, io->po7_uncrr_sym,
err_print_prefix, io->po7_crrct_sym,
err_print_prefix, io->po7_ugbge_sym,
err_print_prefix, io->po7_err_pkt0,
err_print_prefix, io->po7_err_pkt1);
#endif
}
for ( V_14 = 0 ; V_14 < V_95 ; V_14 ++ ) {
if ( ! F_164 ( V_57 -> V_96 [ V_14 ] . V_115 ) )
continue;
F_4 ( L_166 ,
V_15 ,
V_2 -> V_131 , V_14 , V_57 -> V_96 [ V_14 ] . V_115 ) ;
F_128 ( V_57 -> V_96 [ V_14 ] . V_115 , & V_57 -> V_96 [ V_14 ] ) ;
F_4 ( L_167 ,
V_15 , V_57 -> V_96 [ V_14 ] . V_119 ) ;
F_128 ( V_57 -> V_96 [ V_14 ] . V_119 ,
& V_57 -> V_96 [ V_14 ] ) ;
}
#endif
return V_22 ;
}
static int
F_165 ( struct V_1 * V_2 , int V_21 )
{
int V_22 = V_23 ;
#define F_166 0x20000400ul
if ( V_2 -> V_133 &&
( V_2 -> V_133 -> V_134 & 0x20000400ul ) )
V_22 = F_163 ( V_2 , V_21 ) ;
if ( V_2 -> V_135 &&
( V_2 -> V_135 -> V_136 == 0x14 ) &&
! ( V_2 -> V_135 -> V_137 & 0x8 ) &&
( ( V_2 -> V_135 -> V_138 & 0x400ff000000ul )
== 0x400fe000000ul ) )
V_22 = V_139 ;
return V_22 ;
}
void
F_167 ( unsigned long V_140 , unsigned long V_141 )
{
struct V_142 * V_143 = (struct V_142 * ) V_141 ;
int (* F_168)( struct V_1 * , int ) = NULL ;
struct V_1 V_144 = { NULL , } ;
struct V_56 V_145 = { 0 , } ;
struct V_1 * V_2 = NULL ;
int V_146 = V_23 ;
char * V_147 = V_15 ;
char * V_148 = NULL ;
F_162 () ;
F_169 () ;
switch( V_140 ) {
case V_149 :
F_168 = F_5 ;
V_148 = L_168 ;
break;
case V_150 :
F_168 = F_165 ;
V_148 = L_169 ;
break;
case V_151 :
F_168 = F_165 ;
V_148 = L_170 ;
break;
default:
F_170 ( V_140 , V_141 ) ;
return;
}
V_15 = V_152 ;
V_2 =
F_171 ( V_143 ,
& V_144 ) ;
if ( F_168 && V_2 && V_2 -> V_133 ) {
if ( ! V_2 -> V_57 )
V_2 -> V_57 = & V_145 ;
V_2 -> V_131 = V_2 -> V_133 -> V_153 ;
V_146 = F_168 ( V_2 , 0 ) ;
}
switch( V_146 ) {
case V_139 :
break;
case V_24 :
F_4 ( L_171 ,
V_15 , V_148 ,
( unsigned int ) V_140 , ( int ) F_172 () ) ;
F_173 ( & V_2 -> V_133 -> V_154 ) ;
F_168 ( V_2 , 1 ) ;
break;
default:
F_4 ( L_171 ,
V_15 , V_148 ,
( unsigned int ) V_140 , ( int ) F_172 () ) ;
F_174 ( V_143 ) ;
break;
}
V_15 = V_147 ;
F_175 ( 0x7 ) ;
F_162 () ;
}
void T_4
F_176 ( void )
{
F_177 () ;
}
