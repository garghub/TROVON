static void F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
F_2 ( V_5 L_1
L_2 , V_2 -> V_6 ) ;
V_4 = ( V_7 == V_8 ) ? 2 : 4 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_2 ( V_5
L_3
L_4 ,
V_3 + 1 ,
V_2 -> V_9 [ V_3 ] . V_10 , V_2 -> V_9 [ V_3 ] . V_11 ,
V_2 -> V_9 [ V_3 ] . V_12 , V_2 -> V_9 [ V_3 ] . V_13 ) ;
F_2 ( L_5 , ( void * ) V_2 -> V_9 [ V_3 ] . V_11 ) ;
}
}
void F_3 ( struct V_14 * V_15 , long V_16 )
{
char V_17 [ 32 ] ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_6 , V_15 ,
0 , V_16 , V_20 ) == V_21 )
return;
if ( V_16 < 0x100 ) {
sprintf ( V_17 , L_7 , V_16 ) ;
F_5 ( V_17 , V_15 ) ;
}
V_16 -= 0x100 ;
if ( V_15 -> V_10 & V_22 ) {
sprintf ( V_17 , L_8 , V_16 ) ;
F_5 ( V_17 , V_15 ) ;
}
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_25 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_28 ;
V_18 . V_29 = ( void V_30 * ) V_15 -> V_11 ;
V_18 . V_31 = V_16 ;
F_7 ( V_25 , & V_18 , V_32 ) ;
}
void F_8 ( struct V_14 * V_15 , long V_16 )
{
char V_17 [ 32 ] ;
if ( F_4 ( V_33 , L_9 , V_15 ,
0 , V_16 , V_20 ) == V_21 )
return;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
sprintf ( V_17 , L_10 , V_16 ) ;
F_5 ( V_17 , V_15 ) ;
}
void F_9 ( const char * V_34 , int line )
{
F_10 ( 1 ) ;
F_2 ( L_11 , V_34 , line ) ;
}
static int F_11 ( int V_35 , unsigned long V_36 , char * V_37 , int V_38 )
{
unsigned long V_39 ;
int V_40 = - V_41 ;
F_12 ( & V_42 , V_39 ) ;
if ( V_43 ) {
V_40 = V_43 ( V_35 , V_36 , V_37 , V_38 ) ;
} else if ( V_7 == V_44 ) {
if ( F_13 ( V_35 , V_36 , V_37 , V_38 ) == - 1 )
V_40 = - V_45 ;
else
V_40 = 0 ;
} else
V_40 = - V_41 ;
F_14 ( & V_42 , V_39 ) ;
return V_40 ;
}
int F_15 ( T_2 V_46 )
{
unsigned long V_39 ;
int V_40 = 0 ;
F_12 ( & V_42 , V_39 ) ;
if ( ! V_43 )
V_43 = V_46 ;
else
V_40 = - V_47 ;
F_14 ( & V_42 , V_39 ) ;
return V_40 ;
}
void F_16 ( T_2 V_46 )
{
unsigned long V_39 ;
F_12 ( & V_42 , V_39 ) ;
if ( V_43 == V_46 )
V_43 = NULL ;
F_14 ( & V_42 , V_39 ) ;
}
void F_17 ( struct V_14 * V_15 , unsigned long V_48 , unsigned long V_49 )
{
enum V_50 V_51 = F_18 () ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_12 , V_15 ,
0 , 0x8 , V_20 ) == V_21 )
goto V_52;
if ( V_15 -> V_10 & V_22 ) {
F_2 ( L_13
L_14 , V_48 , V_49 ) ;
F_5 ( L_15 , V_15 ) ;
}
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_53 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_54 ;
V_18 . V_29 = ( void V_30 * ) V_15 -> V_11 ;
V_18 . V_31 = 0 ;
F_7 ( V_53 , & V_18 , V_32 ) ;
V_52:
F_19 ( V_51 ) ;
}
void F_20 ( struct V_14 * V_15 , unsigned long V_48 , unsigned long V_49 )
{
if ( F_4 ( V_33 , L_16 , V_15 ,
0 , 0x8 , V_20 ) == V_21 )
return;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_17 ( V_15 , V_48 , V_49 ) ;
}
void F_21 ( struct V_14 * V_15 , unsigned long V_55 , unsigned long V_56 )
{
unsigned short type = ( V_56 >> 16 ) ;
unsigned short V_57 = ( V_56 & 0xffff ) ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_12 , V_15 ,
0 , 0x8 , V_20 ) == V_21 )
return;
if ( V_15 -> V_10 & V_22 ) {
F_2 ( L_17
L_18 ,
V_55 , V_57 , type ) ;
F_5 ( L_15 , V_15 ) ;
}
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_53 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_54 ;
V_18 . V_29 = ( void V_30 * ) V_55 ;
V_18 . V_31 = 0 ;
F_7 ( V_53 , & V_18 , V_32 ) ;
}
void F_22 ( struct V_14 * V_15 , unsigned long V_55 , unsigned long V_56 )
{
if ( F_4 ( V_33 , L_16 , V_15 ,
0 , 0x8 , V_20 ) == V_21 )
return;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_21 ( V_15 , V_55 , V_56 ) ;
}
void F_23 ( struct V_14 * V_15 , unsigned long V_48 , unsigned long V_49 )
{
enum V_50 V_51 = F_18 () ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_19 , V_15 ,
0 , 0x30 , V_20 ) == V_21 )
goto V_52;
if ( V_15 -> V_10 & V_22 ) {
const struct V_58 * V_59 ;
V_59 = F_24 ( V_15 -> V_11 ) ;
if ( V_59 ) {
#ifdef F_25
F_2 ( L_20 , V_15 -> V_11 ) ;
F_2 ( L_21 ,
V_15 -> V_11 , V_59 -> V_60 ) ;
#endif
V_15 -> V_11 = V_59 -> V_60 ;
V_15 -> V_12 = V_15 -> V_11 + 4 ;
goto V_52;
}
F_2 ( L_22
L_14 , V_48 , V_49 ) ;
F_5 ( L_23 , V_15 ) ;
}
V_18 . V_24 = V_53 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_54 ;
V_18 . V_29 = ( void V_30 * ) V_49 ;
V_18 . V_31 = 0 ;
F_7 ( V_53 , & V_18 , V_32 ) ;
V_52:
F_19 ( V_51 ) ;
}
void F_26 ( struct V_14 * V_15 , unsigned long V_48 , unsigned long V_49 )
{
if ( F_4 ( V_33 , L_24 , V_15 ,
0 , 0x30 , V_20 ) == V_21 )
return;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_23 ( V_15 , V_48 , V_49 ) ;
}
void F_27 ( struct V_14 * V_15 , unsigned long V_55 , unsigned long V_56 )
{
unsigned short type = ( V_56 >> 16 ) ;
unsigned short V_57 = ( V_56 & 0xffff ) ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_19 , V_15 ,
0 , 0x8 , V_20 ) == V_21 )
return;
if ( V_15 -> V_10 & V_22 ) {
const struct V_58 * V_59 ;
V_59 = F_24 ( V_15 -> V_11 ) ;
if ( V_59 ) {
#ifdef F_25
F_2 ( L_20 , V_15 -> V_11 ) ;
F_2 ( L_21 ,
V_15 -> V_11 , V_59 -> V_60 ) ;
#endif
V_15 -> V_11 = V_59 -> V_60 ;
V_15 -> V_12 = V_15 -> V_11 + 4 ;
return;
}
F_2 ( L_25
L_18 ,
V_55 , V_57 , type ) ;
F_5 ( L_23 , V_15 ) ;
}
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_53 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_54 ;
V_18 . V_29 = ( void V_30 * ) V_55 ;
V_18 . V_31 = 0 ;
F_7 ( V_53 , & V_18 , V_32 ) ;
}
void F_28 ( struct V_14 * V_15 , unsigned long V_55 , unsigned long V_56 )
{
if ( F_4 ( V_33 , L_24 , V_15 ,
0 , 0x8 , V_20 ) == V_21 )
return;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_27 ( V_15 , V_55 , V_56 ) ;
}
static void F_29 ( void )
{
unsigned long V_61 ;
if ( V_7 != V_44 )
F_30 () ;
for ( V_61 = 0 ; V_61 < ( V_62 << 1 ) ; V_61 += 32 ) {
F_31 ( V_61 , 0x0 ) ;
F_32 ( V_61 , 0x0 ) ;
}
__asm__ __volatile__("flush %%g6\n\t"
"membar #Sync\n\t"
"stxa %0, [%%g0] %1\n\t"
"membar #Sync"
:
: "r" (LSU_CONTROL_IC | LSU_CONTROL_DC |
LSU_CONTROL_IM | LSU_CONTROL_DM),
"i" (ASI_LSU_CONTROL)
: "memory");
}
static void F_33 ( void )
{
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync"
:
: "r" (ESTATE_ERR_ALL),
"i" (ASI_ESTATE_ERROR_EN));
}
static void F_34 ( unsigned long V_63 , unsigned long V_64 , unsigned long V_65 , unsigned long V_66 )
{
unsigned short V_67 ;
char V_68 [ 64 ] , * V_2 ;
if ( V_65 & V_66 ) {
V_67 = V_69 [ V_65 & 0xff ] ;
if ( F_11 ( V_67 , V_63 , V_68 , sizeof( V_68 ) ) < 0 )
V_2 = V_70 ;
else
V_2 = V_68 ;
F_2 ( V_71 L_26
L_27 ,
F_35 () , V_67 , V_2 ) ;
}
if ( V_64 & V_66 ) {
V_67 = V_69 [ V_64 & 0xff ] ;
if ( F_11 ( V_67 , V_63 , V_68 , sizeof( V_68 ) ) < 0 )
V_2 = V_70 ;
else
V_2 = V_68 ;
F_2 ( V_71 L_28
L_27 ,
F_35 () , V_67 , V_2 ) ;
}
}
static void F_36 ( unsigned long V_72 , unsigned long V_63 , unsigned long V_64 , unsigned long V_65 , int V_73 , struct V_14 * V_15 )
{
F_2 ( V_71 L_29
L_30 ,
F_35 () , V_72 , V_63 , V_65 , V_64 , V_73 ) ;
F_34 ( V_63 , V_64 , V_65 , V_74 ) ;
F_4 ( V_19 , L_31 , V_15 ,
0 , V_75 , V_20 ) ;
F_33 () ;
}
static void F_37 ( unsigned long V_72 , unsigned long V_63 , unsigned long V_64 , unsigned long V_65 , unsigned long V_13 , int V_73 , struct V_14 * V_15 )
{
T_1 V_18 ;
F_2 ( V_71 L_32
L_33 ,
F_35 () , V_72 , V_63 , V_65 , V_64 , V_13 , V_73 ) ;
F_34 ( V_63 , V_64 , V_65 , V_76 ) ;
F_4 ( V_19 , L_34 , V_15 ,
0 , V_13 , V_20 ) ;
if ( V_15 -> V_10 & V_22 ) {
if ( V_73 )
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_35 , V_15 ) ;
}
F_29 () ;
F_33 () ;
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_77 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_78 ;
V_18 . V_29 = ( void * ) 0 ;
V_18 . V_31 = 0 ;
F_7 ( V_77 , & V_18 , V_32 ) ;
}
void F_38 ( struct V_14 * V_15 , unsigned long V_79 , unsigned long V_63 )
{
unsigned long V_72 , V_13 , V_64 , V_65 ;
int V_73 ;
V_72 = ( V_79 & V_80 ) >> V_81 ;
V_13 = ( V_79 & V_82 ) >> V_83 ;
V_73 = ( V_79 & V_84 ) ? 1 : 0 ;
V_65 = ( V_79 & V_85 ) >> V_86 ;
V_64 = ( V_79 & V_87 ) >> V_88 ;
#ifdef F_39
if ( V_13 == V_89 &&
V_90 && V_91 == F_35 () ) {
F_29 () ;
F_33 () ;
V_92 = 1 ;
V_15 -> V_12 = V_15 -> V_11 + 4 ;
return;
}
#endif
if ( V_72 & V_93 )
F_37 ( V_72 , V_63 , V_64 , V_65 , V_13 , V_73 , V_15 ) ;
if ( V_13 == V_75 ) {
if ( V_72 & V_93 ) {
if ( V_64 & V_74 ) {
__asm__ __volatile__(
"stxa %0, [%1] %2\n\t"
"membar #Sync"
:
: "r" (udbh & UDBE_CE),
"r" (0x0), "i" (ASI_UDB_ERROR_W));
}
if ( V_65 & V_74 ) {
__asm__ __volatile__(
"stxa %0, [%1] %2\n\t"
"membar #Sync"
:
: "r" (udbl & UDBE_CE),
"r" (0x18), "i" (ASI_UDB_ERROR_W));
}
}
F_36 ( V_72 , V_63 , V_64 , V_65 , V_73 , V_15 ) ;
}
}
void F_40 ( void )
{
unsigned long V_94 ;
F_2 ( L_36 ,
F_35 () ) ;
__asm__ __volatile__("ldxa [%%g0] %1, %0"
: "=r" (dcr)
: "i" (ASI_DCU_CONTROL_REG));
V_94 |= ( V_95 | V_96 | V_97 | V_98 ) ;
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync"
:
: "r" (dcr), "i" (ASI_DCU_CONTROL_REG));
}
static inline struct V_99 * F_41 ( unsigned long V_72 )
{
struct V_99 * V_2 ;
int V_100 = F_35 () ;
if ( ! V_101 )
return NULL ;
V_2 = V_101 + ( V_100 * 2 ) ;
if ( ( V_72 & V_102 ) != 0UL )
V_2 ++ ;
return V_2 ;
}
void T_3 F_42 ( void )
{
unsigned long V_103 , V_104 , V_105 , V_106 ;
int V_3 , V_107 ;
V_103 = 0UL ;
V_104 = ~ 0UL ;
for ( V_3 = 0 ; V_3 < V_108 ; V_3 ++ ) {
unsigned long V_109 ;
V_109 = F_43 ( V_3 ) . V_110 ;
if ( ! V_109 )
continue;
if ( V_109 > V_103 )
V_103 = V_109 ;
V_109 = F_43 ( V_3 ) . V_111 ;
if ( V_109 < V_104 )
V_104 = V_109 ;
}
if ( V_103 == 0UL || V_104 == ~ 0UL ) {
F_44 ( L_37
L_38 ) ;
F_45 () ;
}
V_112 = ( 2 * V_103 ) ;
V_113 = V_104 ;
V_114 = F_46 ( V_112 ) ;
if ( V_114 == ~ 0UL ) {
F_44 ( L_39
L_40 ,
V_112 ) ;
F_45 () ;
}
V_107 = V_108 * ( 2 * sizeof( struct V_99 ) ) ;
for ( V_105 = 0 ; V_105 < V_115 ; V_105 ++ ) {
if ( ( V_62 << V_105 ) >= V_107 )
break;
}
V_101 = (struct V_99 * )
F_47 ( V_116 , V_105 ) ;
if ( ! V_101 ) {
F_44 ( L_41
L_42 , V_107 ) ;
F_45 () ;
}
memset ( V_101 , 0 , V_62 << V_105 ) ;
for ( V_3 = 0 ; V_3 < 2 * V_108 ; V_3 ++ )
V_101 [ V_3 ] . V_72 = V_117 ;
__asm__ ("rdpr %%ver, %0" : "=r" (ver));
if ( ( V_106 >> 32 ) == V_118 ||
( V_106 >> 32 ) == V_119 ) {
V_120 = & V_121 [ 0 ] ;
V_122 = V_123 ;
} else if ( ( V_106 >> 32 ) == 0x003e0015 ) {
V_120 = & V_124 [ 0 ] ;
V_122 = V_125 ;
} else {
V_120 = & V_126 [ 0 ] ;
V_122 = V_127 ;
}
memcpy ( V_128 , V_129 , ( 8 * 4 ) ) ;
memcpy ( V_130 , V_131 , ( 8 * 4 ) ) ;
memcpy ( V_132 , V_133 , ( 8 * 4 ) ) ;
memcpy ( V_134 , V_135 , ( 8 * 4 ) ) ;
memcpy ( V_136 , V_137 , ( 8 * 4 ) ) ;
memcpy ( V_138 , V_139 , ( 8 * 4 ) ) ;
memcpy ( V_140 , V_137 , ( 8 * 4 ) ) ;
memcpy ( V_141 , V_139 , ( 8 * 4 ) ) ;
if ( V_7 == V_142 ) {
memcpy ( V_143 , V_144 , ( 8 * 4 ) ) ;
memcpy ( V_145 , V_146 , ( 8 * 4 ) ) ;
memcpy ( V_147 , V_148 , ( 8 * 4 ) ) ;
memcpy ( V_149 , V_150 , ( 8 * 4 ) ) ;
}
F_48 ( V_151 ) ;
}
static void F_49 ( void )
{
unsigned long V_152 = V_114 ;
unsigned long V_153 = V_113 ;
unsigned long V_154 = V_112 ;
__asm__ __volatile__("1: subcc %0, %4, %0\n\t"
" bne,pt %%xcc, 1b\n\t"
" ldxa [%2 + %0] %3, %%g0\n\t"
: "=&r" (flush_size)
: "0" (flush_size), "r" (flush_base),
"i" (ASI_PHYS_USE_EC), "r" (flush_linesize));
}
static void F_50 ( unsigned long V_155 )
{
unsigned long V_156 ;
V_155 &= ~ ( 8UL - 1UL ) ;
V_155 = ( V_114 +
( V_155 & ( ( V_112 >> 1UL ) - 1UL ) ) ) ;
V_156 = V_155 + ( V_112 >> 1UL ) ;
__asm__ __volatile__("ldxa [%0] %2, %%g0\n\t"
"ldxa [%1] %2, %%g0\n\t"
"membar #Sync"
:
: "r" (physaddr), "r" (alias),
"i" (ASI_PHYS_USE_EC));
}
static void F_51 ( void )
{
unsigned int V_157 , V_158 ;
unsigned long V_55 ;
V_157 = F_52 () . V_157 ;
V_158 = F_52 () . V_158 ;
for ( V_55 = 0 ; V_55 < V_157 ; V_55 += V_158 ) {
__asm__ __volatile__("stxa %%g0, [%0] %1\n\t"
"membar #Sync"
:
: "r" (addr | (2 << 3)),
"i" (ASI_IC_TAG));
}
}
static void F_53 ( void )
{
unsigned long V_159 ;
__asm__ __volatile__("ldxa [%%g0] %1, %0\n\t"
"or %0, %2, %%g1\n\t"
"stxa %%g1, [%%g0] %1\n\t"
"membar #Sync"
: "=r" (dcu_save)
: "i" (ASI_DCU_CONTROL_REG), "i" (DCU_IC)
: "g1");
F_51 () ;
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync"
:
: "r" (dcu_save), "i" (ASI_DCU_CONTROL_REG));
}
static void F_54 ( void )
{
unsigned int V_160 , V_161 ;
unsigned long V_55 ;
V_160 = F_52 () . V_160 ;
V_161 = F_52 () . V_161 ;
for ( V_55 = 0 ; V_55 < V_160 ; V_55 += V_161 ) {
__asm__ __volatile__("stxa %%g0, [%0] %1\n\t"
"membar #Sync"
:
: "r" (addr), "i" (ASI_DCACHE_TAG));
}
}
static void F_55 ( void )
{
unsigned int V_160 , V_161 ;
unsigned long V_55 ;
V_160 = F_52 () . V_160 ;
V_161 = F_52 () . V_161 ;
for ( V_55 = 0 ; V_55 < V_160 ; V_55 += V_161 ) {
unsigned long V_162 = ( V_55 >> 14 ) ;
unsigned long line ;
__asm__ __volatile__("membar #Sync\n\t"
"stxa %0, [%1] %2\n\t"
"membar #Sync"
:
: "r" (tag), "r" (addr),
"i" (ASI_DCACHE_UTAG));
for ( line = V_55 ; line < V_55 + V_161 ; line += 8 )
__asm__ __volatile__("membar #Sync\n\t"
"stxa %%g0, [%0] %1\n\t"
"membar #Sync"
:
: "r" (line),
"i" (ASI_DCACHE_DATA));
}
}
static inline unsigned long F_56 ( unsigned long V_72 )
{
unsigned long V_163 = 0 ;
int V_3 ;
for ( V_3 = 0 ; V_120 [ V_3 ] . V_164 ; V_3 ++ ) {
if ( ( V_163 = ( V_72 & V_120 [ V_3 ] . V_164 ) ) != 0UL )
return V_163 ;
}
return V_163 ;
}
static const char * F_57 ( unsigned long V_66 )
{
int V_3 ;
for ( V_3 = 0 ; V_120 [ V_3 ] . V_164 ; V_3 ++ ) {
if ( ( V_66 & V_120 [ V_3 ] . V_164 ) != 0UL )
return V_120 [ V_3 ] . V_165 ;
}
return L_43 ;
}
static void F_58 ( struct V_14 * V_15 , struct V_99 * V_18 ,
unsigned long V_72 , unsigned long V_63 , int V_166 )
{
unsigned long V_167 ;
char V_168 [ 256 ] ;
F_2 ( L_44 L_45 ,
( V_166 ? V_71 : V_169 ) , F_35 () ,
V_72 , V_63 ,
( V_72 & V_102 ) ? 1 : 0 ) ;
F_2 ( L_44 L_46 ,
( V_166 ? V_71 : V_169 ) , F_35 () ,
V_15 -> V_11 , V_15 -> V_12 , V_15 -> V_170 [ V_171 ] , V_15 -> V_10 ) ;
F_2 ( L_44 L_47 ,
( V_166 ? V_71 : V_169 ) , F_35 () ) ;
F_2 ( L_48 , ( void * ) V_15 -> V_11 ) ;
F_2 ( L_44 L_49 ,
( V_166 ? V_71 : V_169 ) , F_35 () ,
( V_72 & V_172 ) >> V_173 ,
( V_72 & V_174 ) >> V_175 ,
( V_72 & V_176 ) ? L_50 : L_51 ,
( V_72 & V_177 ) ? L_52 : L_51 ) ;
V_167 = F_56 ( V_72 ) ;
F_2 ( L_44 L_53 ,
( V_166 ? V_71 : V_169 ) , F_35 () ,
V_167 , F_57 ( V_167 ) ) ;
#define F_59 (CHAFSR_IVC | CHAFSR_IVU | \
CHAFSR_CPC | CHAFSR_CPU | \
CHAFSR_UE | CHAFSR_CE | \
CHAFSR_EDC | CHAFSR_EDU | \
CHAFSR_UCC | CHAFSR_UCU | \
CHAFSR_WDU | CHAFSR_WDC)
#define F_60 (CHAFSR_EMC | CHAFSR_EMU)
if ( V_72 & F_59 ) {
int V_178 ;
int V_40 ;
V_178 = ( V_72 & V_174 ) >> V_175 ;
V_178 = V_179 [ V_178 ] ;
V_40 = F_11 ( V_178 , V_63 , V_168 , sizeof( V_168 ) ) ;
if ( V_40 != - 1 )
F_2 ( L_44 L_54 ,
( V_166 ? V_71 : V_169 ) ,
F_35 () , V_168 ) ;
} else if ( V_72 & F_60 ) {
int V_178 ;
int V_40 ;
V_178 = ( V_72 & V_172 ) >> V_173 ;
V_178 = V_180 [ V_178 ] ;
V_40 = F_11 ( V_178 , V_63 , V_168 , sizeof( V_168 ) ) ;
if ( V_40 != - 1 )
F_2 ( L_44 L_55 ,
( V_166 ? V_71 : V_169 ) ,
F_35 () , V_168 ) ;
}
F_2 ( L_44 L_56 ,
( V_166 ? V_71 : V_169 ) , F_35 () ,
( int ) V_18 -> V_181 ,
V_18 -> V_182 ,
V_18 -> V_183 ,
V_18 -> V_184 ) ;
F_2 ( L_44 L_57 ,
( V_166 ? V_71 : V_169 ) , F_35 () ,
V_18 -> V_185 [ 0 ] ,
V_18 -> V_185 [ 1 ] ,
V_18 -> V_185 [ 2 ] ,
V_18 -> V_185 [ 3 ] ) ;
F_2 ( L_44 L_58
L_59 ,
( V_166 ? V_71 : V_169 ) , F_35 () ,
( int ) V_18 -> V_186 ,
V_18 -> V_187 ,
V_18 -> V_188 ,
V_18 -> V_189 ,
V_18 -> V_190 ,
V_18 -> V_191 ) ;
F_2 ( L_44 L_60 ,
( V_166 ? V_71 : V_169 ) , F_35 () ,
V_18 -> V_192 [ 0 ] ,
V_18 -> V_192 [ 1 ] ,
V_18 -> V_192 [ 2 ] ,
V_18 -> V_192 [ 3 ] ) ;
F_2 ( L_44 L_61 ,
( V_166 ? V_71 : V_169 ) , F_35 () ,
V_18 -> V_192 [ 4 ] ,
V_18 -> V_192 [ 5 ] ,
V_18 -> V_192 [ 6 ] ,
V_18 -> V_192 [ 7 ] ) ;
F_2 ( L_44 L_62 ,
( V_166 ? V_71 : V_169 ) , F_35 () ,
( int ) V_18 -> V_193 , V_18 -> V_194 ) ;
F_2 ( L_44 L_63 ,
( V_166 ? V_71 : V_169 ) , F_35 () ,
V_18 -> V_195 [ 0 ] ,
V_18 -> V_195 [ 1 ] ,
V_18 -> V_195 [ 2 ] ,
V_18 -> V_195 [ 3 ] ) ;
V_72 = ( V_72 & ~ V_167 ) & V_122 ;
while ( V_72 != 0UL ) {
unsigned long V_66 = F_56 ( V_72 ) ;
F_2 ( L_44 L_64 ,
( V_166 ? V_71 : V_169 ) ,
V_66 , F_57 ( V_66 ) ) ;
V_72 &= ~ V_66 ;
}
if ( ! V_166 )
F_2 ( V_169 L_65 ) ;
}
static int F_61 ( struct V_99 * V_196 )
{
unsigned long V_72 , V_63 ;
int V_40 = 0 ;
__asm__ __volatile__("ldxa [%%g0] %1, %0\n\t"
: "=r" (afsr)
: "i" (ASI_AFSR));
if ( ( V_72 & V_122 ) != 0 ) {
if ( V_196 != NULL ) {
__asm__ __volatile__("ldxa [%%g0] %1, %0\n\t"
: "=r" (afar)
: "i" (ASI_AFAR));
V_196 -> V_72 = V_72 ;
V_196 -> V_63 = V_63 ;
}
V_40 = 1 ;
}
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync\n\t"
: : "r" (afsr), "i" (ASI_AFSR));
return V_40 ;
}
void F_62 ( struct V_14 * V_15 , unsigned long V_72 , unsigned long V_63 )
{
struct V_99 V_197 , * V_2 ;
int V_166 ;
F_49 () ;
V_2 = F_41 ( V_72 ) ;
if ( ! V_2 ) {
F_44 ( L_66 ,
V_72 , V_63 ) ;
F_44 ( L_67 ,
F_35 () , V_15 -> V_11 , V_15 -> V_12 , V_15 -> V_10 ) ;
F_45 () ;
}
memcpy ( & V_197 , V_2 , sizeof( V_197 ) ) ;
if ( V_2 -> V_72 != V_72 || V_2 -> V_63 != V_63 )
V_197 . V_72 = V_117 ;
else
V_2 -> V_72 = V_117 ;
F_53 () ;
F_54 () ;
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_DCU_CONTROL_REG),
"i" (DCU_DC | DCU_IC)
: "g1");
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_ESTATE_ERROR_EN),
"i" (ESTATE_ERROR_NCEEN | ESTATE_ERROR_CEEN)
: "g1");
V_166 = 1 ;
if ( V_72 & ( V_198 | V_199 | V_200 ) )
V_166 = 0 ;
if ( F_61 ( & V_197 ) ) {
unsigned long V_201 = V_197 . V_72 ;
if ( V_201 & ( V_202 | V_203 |
V_204 | V_205 |
V_206 | V_207 |
V_208 | V_209 ) )
V_166 = 0 ;
}
F_58 ( V_15 , & V_197 , V_72 , V_63 , V_166 ) ;
if ( ! V_166 )
F_63 ( L_68 ) ;
F_49 () ;
}
static int F_64 ( unsigned long V_155 )
{
unsigned long V_210 ;
unsigned long V_211 , V_212 ;
int V_40 ;
__asm__ __volatile__("ldxa [%%g0] %2, %0\n\t"
"andn %0, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %2\n\t"
"membar #Sync"
: "=&r" (orig_estate)
: "i" (ESTATE_ERROR_CEEN),
"i" (ASI_ESTATE_ERROR_EN)
: "g1");
V_155 &= ~ ( 8UL - 1UL ) ;
V_211 = ( V_114 +
( V_155 & ( ( V_112 >> 1 ) - 1 ) ) ) ;
V_212 = V_211 + ( V_112 >> 1 ) ;
__asm__ __volatile__("ldxa [%0] %3, %%g0\n\t"
"ldxa [%1] %3, %%g0\n\t"
"casxa [%2] %3, %%g0, %%g0\n\t"
"ldxa [%0] %3, %%g0\n\t"
"ldxa [%1] %3, %%g0\n\t"
"membar #Sync"
:
: "r" (alias1), "r" (alias2),
"r" (physaddr), "i" (ASI_PHYS_USE_EC));
if ( F_61 ( NULL ) ) {
__asm__ __volatile__("ldxa [%0] %1, %%g0\n\t"
"membar #Sync"
: : "r" (physaddr), "i" (ASI_PHYS_USE_EC));
if ( F_61 ( NULL ) )
V_40 = 2 ;
else
V_40 = 1 ;
} else {
V_40 = 0 ;
}
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync"
: : "r" (orig_estate), "i" (ASI_ESTATE_ERROR_EN));
return V_40 ;
}
static int F_65 ( unsigned long V_36 )
{
unsigned long V_213 = V_151 + V_36 ;
if ( V_213 > ( unsigned long ) V_214 )
return 0 ;
return F_66 ( V_213 ) ;
}
void F_67 ( struct V_14 * V_15 , unsigned long V_72 , unsigned long V_63 )
{
struct V_99 V_197 , * V_2 ;
int V_166 , V_215 ;
V_2 = F_41 ( V_72 ) ;
if ( ! V_2 ) {
F_44 ( L_69 ,
V_72 , V_63 ) ;
F_44 ( L_67 ,
F_35 () , V_15 -> V_11 , V_15 -> V_12 , V_15 -> V_10 ) ;
F_45 () ;
}
memcpy ( & V_197 , V_2 , sizeof( V_197 ) ) ;
if ( V_2 -> V_72 != V_72 || V_2 -> V_63 != V_63 )
V_197 . V_72 = V_117 ;
else
V_2 -> V_72 = V_117 ;
V_215 = F_65 ( V_63 ) ;
if ( V_215 && ( V_72 & V_216 ) != 0UL ) {
F_64 ( V_63 ) ;
}
{
int V_217 , V_218 ;
V_217 = V_218 = 0 ;
if ( ( V_72 & V_219 ) != 0UL ) {
if ( ( V_72 & V_122 ) == V_219 )
V_218 = 1 ;
else
V_217 = 1 ;
} else if ( ( V_72 & V_220 ) != 0UL ) {
if ( ( V_72 & V_122 ) == V_220 )
V_218 = 1 ;
else
V_217 = 1 ;
}
F_53 () ;
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_DCU_CONTROL_REG),
"i" (DCU_IC)
: "g1");
if ( V_217 )
F_49 () ;
else if ( V_218 )
F_50 ( V_63 ) ;
}
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_ESTATE_ERROR_EN),
"i" (ESTATE_ERROR_CEEN)
: "g1");
V_166 = 1 ;
if ( V_72 & ( V_198 | V_199 | V_200 ) )
V_166 = 0 ;
( void ) F_61 ( & V_197 ) ;
F_58 ( V_15 , & V_197 , V_72 , V_63 , V_166 ) ;
if ( ! V_166 )
F_63 ( L_70 ) ;
}
void F_68 ( struct V_14 * V_15 , unsigned long V_72 , unsigned long V_63 )
{
struct V_99 V_197 , * V_2 ;
int V_166 , V_215 ;
#ifdef F_39
if ( V_90 && V_91 == F_35 () ) {
F_53 () ;
F_54 () ;
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_DCU_CONTROL_REG),
"i" (DCU_DC | DCU_IC)
: "g1");
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_ESTATE_ERROR_EN),
"i" (ESTATE_ERROR_NCEEN | ESTATE_ERROR_CEEN)
: "g1");
( void ) F_61 ( NULL ) ;
V_92 = 1 ;
V_15 -> V_11 += 4 ;
V_15 -> V_12 = V_15 -> V_11 + 4 ;
return;
}
#endif
V_2 = F_41 ( V_72 ) ;
if ( ! V_2 ) {
F_44 ( L_71 ,
V_72 , V_63 ) ;
F_44 ( L_67 ,
F_35 () , V_15 -> V_11 , V_15 -> V_12 , V_15 -> V_10 ) ;
F_45 () ;
}
memcpy ( & V_197 , V_2 , sizeof( V_197 ) ) ;
if ( V_2 -> V_72 != V_72 || V_2 -> V_63 != V_63 )
V_197 . V_72 = V_117 ;
else
V_2 -> V_72 = V_117 ;
V_215 = F_65 ( V_63 ) ;
{
int V_217 , V_218 ;
V_217 = V_218 = 0 ;
if ( ( V_72 & V_203 ) != 0UL ) {
if ( ( V_72 & V_122 ) == V_203 )
V_218 = 1 ;
else
V_217 = 1 ;
} else if ( ( V_72 & V_208 ) != 0UL ) {
if ( ( V_72 & V_122 ) == V_208 )
V_218 = 1 ;
else
V_217 = 1 ;
}
F_53 () ;
F_54 () ;
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_DCU_CONTROL_REG),
"i" (DCU_IC | DCU_DC)
: "g1");
if ( V_217 )
F_49 () ;
else if ( V_218 )
F_50 ( V_63 ) ;
}
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_ESTATE_ERROR_EN),
"i" (ESTATE_ERROR_NCEEN | ESTATE_ERROR_CEEN)
: "g1");
V_166 = 1 ;
if ( V_72 & ( V_198 | V_199 | V_200 ) )
V_166 = 0 ;
if ( F_61 ( & V_197 ) ) {
unsigned long V_201 = V_197 . V_72 ;
if ( V_201 & ( V_202 | V_203 |
V_204 | V_205 |
V_206 | V_207 |
V_208 | V_209 ) )
V_166 = 0 ;
}
F_58 ( V_15 , & V_197 , V_72 , V_63 , V_166 ) ;
if ( V_166 && V_215 ) {
if ( ( V_15 -> V_10 & V_22 ) == 0UL ) {
V_166 = 1 ;
} else {
const struct V_58 * V_59 ;
V_59 = F_24 ( V_15 -> V_11 ) ;
if ( V_59 ) {
V_166 = 1 ;
} else {
V_166 = 0 ;
}
if ( V_166 ) {
if ( F_69 ( V_63 >> V_221 ) )
F_70 ( F_71 ( V_63 >> V_221 ) ) ;
else
V_166 = 0 ;
if ( V_166 ) {
V_15 -> V_11 = V_59 -> V_60 ;
V_15 -> V_12 = V_15 -> V_11 + 4 ;
}
}
}
} else {
V_166 = 0 ;
}
if ( ! V_166 )
F_63 ( L_72 ) ;
}
void F_72 ( int type , struct V_14 * V_15 )
{
if ( type & 0x1 )
F_51 () ;
else
F_55 () ;
F_54 () ;
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_DCU_CONTROL_REG),
"i" (DCU_DC | DCU_IC)
: "g1");
if ( type & 0x2 ) {
F_2 ( V_5 L_73 ,
F_35 () ,
( type & 0x1 ) ? 'I' : 'D' ,
V_15 -> V_11 ) ;
F_2 ( V_5 L_48 , ( void * ) V_15 -> V_11 ) ;
F_63 ( L_74 ) ;
}
F_2 ( V_71 L_73 ,
F_35 () ,
( type & 0x1 ) ? 'I' : 'D' ,
V_15 -> V_11 ) ;
F_2 ( V_71 L_48 , ( void * ) V_15 -> V_11 ) ;
}
static const char * F_73 ( T_4 type )
{
static const char * V_222 [ V_223 ] = {
L_75 ,
L_76 ,
L_77 ,
L_78 ,
L_79 ,
L_80 ,
L_81 ,
} ;
if ( type < V_223 )
return V_222 [ type ] ;
return L_82 ;
}
static void F_74 ( T_5 V_224 )
{
static const char * V_225 [] = {
L_83 ,
L_84 ,
L_85 ,
L_86 ,
L_87 ,
L_88 ,
L_89 ,
L_90 ,
L_91 ,
} ;
static const char * V_226 [] = {
L_92 ,
L_93 ,
L_94 ,
L_95 ,
} ;
static const char * V_227 [] = {
L_96 ,
L_97 ,
L_98 ,
L_99 ,
} ;
T_5 V_228 , V_229 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < F_75 ( V_225 ) ; V_3 ++ ) {
if ( V_224 & ( 1U << V_3 ) ) {
const char * V_230 = V_225 [ V_3 ] ;
F_76 ( L_100 , V_230 ) ;
}
}
V_228 = ( ( V_224 & V_231 ) >>
V_232 ) ;
F_76 ( L_100 , V_226 [ V_228 ] ) ;
V_229 = ( ( V_224 & V_233 ) >>
V_234 ) ;
F_76 ( L_100 , V_227 [ V_229 ] ) ;
if ( V_224 & V_235 )
F_76 ( L_101 ) ;
}
static void F_77 ( const char * V_236 , struct V_14 * V_15 )
{
unsigned int V_237 ;
T_6 V_55 ;
if ( ! ( V_15 -> V_10 & V_22 ) )
return;
V_237 = * ( unsigned int * ) V_15 -> V_11 ;
V_55 = F_78 ( V_15 , V_237 , 0 ) ;
F_2 ( L_102 ,
V_236 , V_55 ) ;
}
static void F_79 ( struct V_14 * V_15 , struct V_238 * V_239 ,
int V_100 , const char * V_236 , T_7 * V_240 )
{
T_6 * V_241 = ( T_6 * ) V_239 ;
T_5 V_224 ;
int V_242 ;
F_2 ( L_103 , V_236 , V_100 ) ;
F_2 ( L_104 ,
V_236 , V_15 -> V_11 , ( void * ) V_15 -> V_11 ) ;
F_2 ( L_105 ,
V_236 , V_241 [ 0 ] , V_241 [ 1 ] , V_241 [ 2 ] , V_241 [ 3 ] ) ;
F_2 ( L_106 ,
V_236 , V_241 [ 4 ] , V_241 [ 5 ] , V_241 [ 6 ] , V_241 [ 7 ] ) ;
F_2 ( L_107 ,
V_236 , V_239 -> V_243 , V_239 -> V_244 ) ;
F_2 ( L_108 , V_236 , F_73 ( V_239 -> V_245 ) ) ;
V_224 = V_239 -> V_246 ;
F_2 ( L_109 , V_236 , V_224 ) ;
F_74 ( V_224 ) ;
F_76 ( L_110 ) ;
if ( V_224 & ( V_247 |
V_248 |
V_249 ) ) {
F_2 ( L_111 , V_236 , V_239 -> V_250 ) ;
if ( V_239 -> V_250 == ~ ( T_6 ) 0 )
F_77 ( V_236 , V_15 ) ;
}
if ( V_224 & ( V_247 | V_249 ) )
F_2 ( L_112 , V_236 , V_239 -> V_251 ) ;
if ( V_224 & ( V_252 |
V_253 |
V_254 |
V_255 ) )
F_2 ( L_113 , V_236 , V_239 -> V_256 ) ;
if ( V_224 & V_249 )
F_2 ( L_114 , V_236 , V_239 -> V_257 ) ;
if ( ( V_224 & ( V_253 |
V_254 |
V_255 ) ) &&
( V_239 -> V_258 & V_259 ) != 0 )
F_2 ( L_115 ,
V_236 , V_239 -> V_258 & ~ V_259 ) ;
F_80 ( V_15 ) ;
if ( ( V_242 = F_81 ( V_240 ) ) != 0 ) {
F_82 ( V_240 , 0 ) ;
F_83 () ;
F_2 ( L_116 ,
V_236 , V_242 ) ;
}
}
void F_84 ( struct V_14 * V_15 , unsigned long V_260 )
{
enum V_50 V_51 = F_18 () ;
struct V_238 * V_239 , V_261 ;
struct V_262 * V_263 ;
unsigned long V_36 ;
int V_100 ;
V_100 = F_85 () ;
V_263 = & V_264 [ V_100 ] ;
V_36 = V_263 -> V_265 + V_260 ;
V_239 = F_86 ( V_36 ) ;
memcpy ( & V_261 , V_239 , sizeof( struct V_238 ) ) ;
V_239 -> V_243 = 0 ;
F_83 () ;
F_87 () ;
if ( V_261 . V_245 == V_266 ) {
F_88 ( L_117 ,
V_261 . V_267 ) ;
F_89 ( true ) ;
goto V_52;
}
F_79 ( V_15 , & V_261 , V_100 ,
V_268 L_118 ,
& V_269 ) ;
V_52:
F_19 ( V_51 ) ;
}
void F_90 ( struct V_14 * V_15 )
{
F_91 ( & V_269 ) ;
}
void F_92 ( struct V_14 * V_15 , unsigned long V_260 )
{
struct V_238 * V_239 , V_261 ;
struct V_262 * V_263 ;
unsigned long V_36 ;
int V_100 ;
V_100 = F_85 () ;
V_263 = & V_264 [ V_100 ] ;
V_36 = V_263 -> V_270 + V_260 ;
V_239 = F_86 ( V_36 ) ;
memcpy ( & V_261 , V_239 , sizeof( struct V_238 ) ) ;
V_239 -> V_243 = 0 ;
F_83 () ;
F_87 () ;
#ifdef F_39
if ( V_90 && V_91 == V_100 ) {
V_92 = 1 ;
V_15 -> V_11 += 4 ;
V_15 -> V_12 = V_15 -> V_11 + 4 ;
return;
}
#endif
F_79 ( V_15 , & V_261 , V_100 ,
V_5 L_119 ,
& V_271 ) ;
F_63 ( L_120 ) ;
}
void F_93 ( struct V_14 * V_15 )
{
F_91 ( & V_271 ) ;
}
static void F_94 ( struct V_14 * V_15 )
{
F_5 ( L_121 , V_15 ) ;
}
void F_95 ( struct V_14 * V_15 , int V_6 )
{
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_2 ( V_5 L_122 ,
V_15 -> V_11 , V_6 ) ;
F_2 ( V_5 L_123 , ( void * ) V_15 -> V_11 ) ;
F_2 ( V_5 L_124 , V_15 -> V_170 [ V_171 ] ) ;
F_2 ( V_5 L_125 ,
( void * ) V_15 -> V_170 [ V_171 ] ) ;
F_2 ( V_5 L_126
L_127 ,
V_272 , V_273 ,
V_274 , V_275 ) ;
F_94 ( V_15 ) ;
}
void F_96 ( struct V_14 * V_15 , int V_6 )
{
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_2 ( V_5 L_128 ,
V_15 -> V_11 , V_6 ) ;
F_2 ( V_5 L_129 , ( void * ) V_15 -> V_11 ) ;
F_2 ( V_5 L_130 , V_15 -> V_170 [ V_171 ] ) ;
F_2 ( V_5 L_131 ,
( void * ) V_15 -> V_170 [ V_171 ] ) ;
F_2 ( V_5 L_132
L_127 ,
V_276 , V_277 ,
V_278 , V_279 ) ;
F_94 ( V_15 ) ;
}
void F_97 ( unsigned long V_280 , unsigned long V_281 )
{
F_2 ( V_169 L_133 ,
V_280 , V_281 ) ;
}
void F_98 ( unsigned long V_280 , unsigned long V_281 )
{
F_2 ( V_169 L_134 ,
V_280 , V_281 ) ;
}
static void F_99 ( struct V_14 * V_15 )
{
if ( V_15 -> V_10 & V_22 ) {
V_15 -> V_11 = V_15 -> V_12 ;
V_15 -> V_12 += 4 ;
} else {
unsigned long V_282 = F_100 () -> V_283 [ 0 ] ;
T_1 V_18 ;
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_284 ;
V_18 . V_26 = 0 ;
V_18 . V_29 = ( void V_30 * ) V_15 -> V_11 ;
V_18 . V_31 = 0 ;
V_18 . V_27 = V_285 ;
if ( ( V_282 & 0x1c000 ) == ( 1 << 14 ) ) {
if ( V_282 & 0x10 )
V_18 . V_27 = V_286 ;
else if ( V_282 & 0x08 )
V_18 . V_27 = V_287 ;
else if ( V_282 & 0x04 )
V_18 . V_27 = V_288 ;
else if ( V_282 & 0x02 )
V_18 . V_27 = V_289 ;
else if ( V_282 & 0x01 )
V_18 . V_27 = V_290 ;
}
F_7 ( V_284 , & V_18 , V_32 ) ;
}
}
void F_101 ( struct V_14 * V_15 )
{
enum V_50 V_51 = F_18 () ;
if ( F_4 ( V_19 , L_135 , V_15 ,
0 , 0x24 , V_284 ) == V_21 )
goto V_52;
F_99 ( V_15 ) ;
V_52:
F_19 ( V_51 ) ;
}
void F_102 ( struct V_14 * V_15 )
{
enum V_50 V_51 = F_18 () ;
struct V_291 * V_292 = V_293 ;
int V_40 = 0 ;
if ( F_4 ( V_19 , L_136 , V_15 ,
0 , 0x25 , V_284 ) == V_21 )
goto V_52;
switch ( ( F_100 () -> V_283 [ 0 ] & 0x1c000 ) ) {
case ( 2 << 14 ) :
case ( 3 << 14 ) :
V_40 = F_103 ( V_15 , V_292 , false ) ;
break;
}
if ( V_40 )
goto V_52;
F_99 ( V_15 ) ;
V_52:
F_19 ( V_51 ) ;
}
void F_104 ( struct V_14 * V_15 )
{
enum V_50 V_51 = F_18 () ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_137 , V_15 ,
0 , 0x26 , V_294 ) == V_21 )
goto V_52;
if ( V_15 -> V_10 & V_22 )
F_5 ( L_138 , V_15 ) ;
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_294 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_295 ;
V_18 . V_29 = ( void V_30 * ) V_15 -> V_11 ;
V_18 . V_31 = 0 ;
F_7 ( V_294 , & V_18 , V_32 ) ;
V_52:
F_19 ( V_51 ) ;
}
void F_105 ( struct V_14 * V_15 )
{
enum V_50 V_51 = F_18 () ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_139 , V_15 ,
0 , 0x28 , V_284 ) == V_21 )
goto V_52;
if ( V_15 -> V_10 & V_22 )
F_5 ( L_140 , V_15 ) ;
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_284 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_296 ;
V_18 . V_29 = ( void V_30 * ) V_15 -> V_11 ;
V_18 . V_31 = 0 ;
F_7 ( V_284 , & V_18 , V_32 ) ;
V_52:
F_19 ( V_51 ) ;
}
static void F_106 ( unsigned int * V_297 )
{
int V_3 ;
if ( ( ( ( unsigned long ) V_297 ) & 3 ) )
return;
F_2 ( L_141 ) ;
for ( V_3 = - 3 ; V_3 < 6 ; V_3 ++ )
F_2 ( L_142 , V_3 ? ' ' : '<' , V_297 [ V_3 ] , V_3 ? ' ' : '>' ) ;
F_2 ( L_143 ) ;
}
static void F_107 ( unsigned int V_30 * V_297 )
{
int V_3 ;
unsigned int V_37 [ 9 ] ;
if ( ( ( ( unsigned long ) V_297 ) & 3 ) )
return;
if ( F_108 ( V_37 , V_297 - 3 , sizeof( V_37 ) ) )
return;
F_2 ( L_141 ) ;
for ( V_3 = 0 ; V_3 < 9 ; V_3 ++ )
F_2 ( L_142 , V_3 == 3 ? ' ' : '<' , V_37 [ V_3 ] , V_3 == 3 ? ' ' : '>' ) ;
F_2 ( L_143 ) ;
}
void F_109 ( struct V_298 * V_299 , unsigned long * V_300 )
{
unsigned long V_301 , V_302 ;
struct V_303 * V_304 ;
int V_305 = 0 ;
#ifdef F_110
int V_306 = 0 ;
#endif
V_302 = ( unsigned long ) V_300 ;
if ( ! V_299 )
V_299 = V_32 ;
V_304 = F_111 ( V_299 ) ;
if ( V_302 == 0UL ) {
if ( V_299 == V_32 )
asm("mov %%fp, %0" : "=r" (ksp));
else
V_302 = V_304 -> V_302 ;
}
if ( V_304 == F_100 () )
F_112 () ;
V_301 = V_302 + V_307 ;
F_2 ( L_144 ) ;
do {
struct V_308 * V_309 ;
struct V_14 * V_15 ;
unsigned long V_297 ;
if ( ! F_113 ( V_304 , V_301 ) )
break;
V_309 = (struct V_308 * ) V_301 ;
V_15 = (struct V_14 * ) ( V_309 + 1 ) ;
if ( F_114 ( V_304 , V_15 ) ) {
if ( ! ( V_15 -> V_10 & V_22 ) )
break;
V_297 = V_15 -> V_11 ;
V_301 = V_15 -> V_170 [ V_310 ] + V_307 ;
} else {
V_297 = V_309 -> V_311 ;
V_301 = ( unsigned long ) V_309 -> V_301 + V_307 ;
}
F_2 ( L_145 , V_297 , ( void * ) V_297 ) ;
#ifdef F_110
if ( ( V_297 + 8UL ) == ( unsigned long ) & V_312 ) {
int V_313 = V_299 -> V_314 ;
if ( V_299 -> V_315 && V_313 >= V_306 ) {
V_297 = V_299 -> V_315 [ V_313 - V_306 ] . V_40 ;
F_2 ( L_145 , V_297 , ( void * ) V_297 ) ;
V_306 ++ ;
}
}
#endif
} while ( ++ V_305 < 16 );
}
static inline struct V_316 * F_115 ( struct V_316 * V_317 )
{
unsigned long V_301 = V_317 -> V_318 [ 6 ] ;
if ( ! V_301 )
return NULL ;
return (struct V_316 * ) ( V_301 + V_307 ) ;
}
void T_8 F_5 ( char * V_319 , struct V_14 * V_15 )
{
static int V_320 ;
int V_305 = 0 ;
F_2 (
L_146
L_147
L_148
L_149 ) ;
F_2 ( L_150 , V_32 -> V_321 , F_116 ( V_32 ) , V_319 , ++ V_320 ) ;
F_4 ( V_322 , V_319 , V_15 , 0 , 255 , V_53 ) ;
__asm__ __volatile__("flushw");
F_80 ( V_15 ) ;
F_117 ( V_323 , V_324 ) ;
if ( V_15 -> V_10 & V_22 ) {
struct V_303 * V_304 = F_100 () ;
struct V_316 * V_317 = (struct V_316 * )
( V_15 -> V_170 [ V_325 ] + V_307 ) ;
while ( V_317 &&
V_305 ++ < 30 &&
F_113 ( V_304 , ( unsigned long ) V_317 ) ) {
F_2 ( L_151 , V_317 -> V_318 [ 7 ] ,
( void * ) V_317 -> V_318 [ 7 ] ) ;
V_317 = F_115 ( V_317 ) ;
}
F_106 ( ( unsigned int * ) V_15 -> V_11 ) ;
} else {
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
F_107 ( ( unsigned int V_30 * ) V_15 -> V_11 ) ;
}
if ( V_326 )
F_63 ( L_152 ) ;
if ( V_15 -> V_10 & V_22 )
F_118 ( V_327 ) ;
F_118 ( V_53 ) ;
}
void F_119 ( struct V_14 * V_15 )
{
enum V_50 V_51 = F_18 () ;
unsigned long V_297 = V_15 -> V_11 ;
unsigned long V_10 = V_15 -> V_10 ;
T_5 V_237 ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_153 , V_15 ,
0 , 0x10 , V_25 ) == V_21 )
goto V_52;
if ( V_10 & V_22 )
F_5 ( L_154 , V_15 ) ;
if ( F_6 ( V_23 ) )
V_297 = ( T_5 ) V_297 ;
if ( F_120 ( V_237 , ( T_5 V_30 * ) V_297 ) != - V_328 ) {
if ( ( V_237 & 0xc1ffc000 ) == 0x81700000 ) {
if ( F_121 ( V_237 , V_15 ) )
goto V_52;
} else if ( ( V_237 & 0xc1580000 ) == 0xc1100000 ) {
if ( F_122 ( V_237 , V_15 ) )
goto V_52;
} else if ( V_7 == V_8 ) {
if ( ( V_237 & V_329 ) == V_330 ) {
if ( ! F_123 ( V_15 , V_237 ) )
goto V_52;
} else {
struct V_291 * V_292 = V_293 ;
if ( F_103 ( V_15 , V_292 , true ) )
goto V_52;
}
}
}
V_18 . V_24 = V_25 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_331 ;
V_18 . V_29 = ( void V_30 * ) V_297 ;
V_18 . V_31 = 0 ;
F_7 ( V_25 , & V_18 , V_32 ) ;
V_52:
F_19 ( V_51 ) ;
}
void F_124 ( struct V_14 * V_15 , unsigned long V_49 , unsigned long V_48 )
{
enum V_50 V_51 = F_18 () ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_155 , V_15 ,
0 , 0x34 , V_53 ) == V_21 )
goto V_52;
if ( V_15 -> V_10 & V_22 ) {
F_125 ( V_15 , * ( ( unsigned int * ) V_15 -> V_11 ) ) ;
goto V_52;
}
V_18 . V_24 = V_77 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_332 ;
V_18 . V_29 = ( void V_30 * ) V_49 ;
V_18 . V_31 = 0 ;
F_7 ( V_77 , & V_18 , V_32 ) ;
V_52:
F_19 ( V_51 ) ;
}
void F_126 ( struct V_14 * V_15 , unsigned long V_55 , unsigned long V_56 )
{
T_1 V_18 ;
if ( F_4 ( V_19 , L_155 , V_15 ,
0 , 0x34 , V_53 ) == V_21 )
return;
if ( V_15 -> V_10 & V_22 ) {
F_125 ( V_15 , * ( ( unsigned int * ) V_15 -> V_11 ) ) ;
return;
}
V_18 . V_24 = V_77 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_332 ;
V_18 . V_29 = ( void V_30 * ) V_55 ;
V_18 . V_31 = 0 ;
F_7 ( V_77 , & V_18 , V_32 ) ;
}
void F_127 ( struct V_14 * V_15 )
{
enum V_50 V_51 = F_18 () ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_156 , V_15 ,
0 , 0x11 , V_25 ) == V_21 )
goto V_52;
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_25 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_333 ;
V_18 . V_29 = ( void V_30 * ) V_15 -> V_11 ;
V_18 . V_31 = 0 ;
F_7 ( V_25 , & V_18 , V_32 ) ;
V_52:
F_19 ( V_51 ) ;
}
void F_128 ( struct V_14 * V_15 )
{
F_127 ( V_15 ) ;
}
void F_129 ( struct V_14 * V_15 )
{
F_18 () ;
F_5 ( L_157 , V_15 ) ;
}
void F_130 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_158 , V_15 ) ;
}
void F_131 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_159 , V_15 ) ;
}
void F_132 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_160 , V_15 ) ;
}
void F_133 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_161 , V_15 ) ;
}
void F_134 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_162 , V_15 ) ;
}
void F_135 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_163 , V_15 ) ;
}
void F_136 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_164 , V_15 ) ;
}
void F_137 ( struct V_14 * V_15 )
{
F_18 () ;
F_5 ( L_165 , V_15 ) ;
}
void F_138 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_166 , V_15 ) ;
}
void F_139 ( struct V_14 * V_15 )
{
F_18 () ;
F_5 ( L_167 , V_15 ) ;
}
void F_140 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_168 , V_15 ) ;
}
void F_141 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_169 , V_15 ) ;
}
void F_142 ( struct V_14 * V_15 )
{
V_15 -> V_170 [ V_334 ] = F_143 ( V_15 -> V_10 ) ;
V_15 -> V_11 = V_15 -> V_12 ;
V_15 -> V_12 += 4 ;
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
}
void T_9 F_144 ( struct V_303 * V_335 )
{
int V_100 = F_145 () ;
struct V_262 * V_2 = & V_264 [ V_100 ] ;
V_2 -> V_336 = V_335 ;
V_2 -> V_337 = 0 ;
}
void T_3 F_146 ( void )
{
F_147 ( V_338 != F_148 ( struct V_303 , V_339 ) ||
V_340 != F_148 ( struct V_303 , V_39 ) ||
V_341 != F_148 ( struct V_303 , V_100 ) ||
V_342 != F_148 ( struct V_303 , V_343 ) ||
V_344 != F_148 ( struct V_303 , V_302 ) ||
V_345 != F_148 ( struct V_303 ,
V_346 ) ||
V_347 != F_148 ( struct V_303 , V_348 ) ||
V_349 != F_148 ( struct V_303 , V_350 ) ||
V_351 != F_148 ( struct V_303 ,
V_316 ) ||
V_352 != F_148 ( struct V_303 ,
V_353 ) ||
V_354 != F_148 ( struct V_303 , V_355 ) ||
V_356 != F_148 ( struct V_303 , V_283 ) ||
V_357 != F_148 ( struct V_303 ,
V_358 ) ||
V_359 != F_148 ( struct V_303 , V_360 ) ||
V_361 != F_148 ( struct V_303 ,
V_362 ) ||
V_363 != F_148 ( struct V_303 ,
V_364 ) ||
V_365 != F_148 ( struct V_303 ,
V_366 ) ||
V_367 != F_148 ( struct V_303 , V_368 ) ||
( V_367 & ( 64 - 1 ) ) ) ;
F_147 ( V_369 != F_148 ( struct V_262 ,
V_336 ) ||
( V_370 !=
F_148 ( struct V_262 , V_337 ) ) ||
( V_371 !=
F_148 ( struct V_262 , V_372 ) ) ||
( V_373 !=
F_148 ( struct V_262 , V_374 ) ) ||
( V_375 !=
F_148 ( struct V_262 , V_376 ) ) ||
( V_377 !=
F_148 ( struct V_262 , V_265 ) ) ||
( V_378 !=
F_148 ( struct V_262 , V_379 ) ) ||
( V_380 !=
F_148 ( struct V_262 , V_270 ) ) ||
( V_381 !=
F_148 ( struct V_262 , V_382 ) ) ||
( V_383 !=
F_148 ( struct V_262 , V_384 ) ) ||
( V_385 !=
F_148 ( struct V_262 , V_386 ) ) ||
( V_387 !=
F_148 ( struct V_262 , V_388 ) ) ||
( V_389 !=
F_148 ( struct V_262 , V_390 ) ) ||
( V_391 !=
F_148 ( struct V_262 , V_392 ) ) ||
( V_393 !=
F_148 ( struct V_262 , V_394 ) ) ||
( V_395 !=
F_148 ( struct V_262 , V_396 ) ) ||
( V_397 !=
F_148 ( struct V_262 , V_398 ) ) ||
( V_399 !=
F_148 ( struct V_262 , V_400 ) ) ||
( V_401 !=
F_148 ( struct V_262 , V_402 ) ) ) ;
F_147 ( ( V_403 !=
F_148 ( struct V_404 , V_405 ) ) ||
( V_406 !=
F_148 ( struct V_404 , V_407 ) ) ||
( V_408 !=
F_148 ( struct V_404 , V_409 ) ) ||
( V_410 !=
F_148 ( struct V_404 , V_411 ) ) ||
( V_412 !=
F_148 ( struct V_404 , V_413 ) ) ||
( V_414 !=
F_148 ( struct V_404 , V_415 ) ) ) ;
F_91 ( & V_416 . V_417 ) ;
V_32 -> V_418 = & V_416 ;
}
