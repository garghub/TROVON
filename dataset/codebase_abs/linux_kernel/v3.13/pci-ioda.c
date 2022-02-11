static inline void F_1 ( T_1 V_1 , volatile void T_2 * V_2 )
{
__asm__ __volatile__("stdcix %0,0,%1"
: : "r" (val), "r" (paddr) : "memory");
}
static int F_2 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
do {
V_5 = F_3 ( V_4 -> V_6 . V_7 ,
V_4 -> V_6 . V_8 , 0 ) ;
if ( V_5 >= V_4 -> V_6 . V_8 )
return V_9 ;
} while( F_4 ( V_5 , V_4 -> V_6 . V_7 ) );
V_4 -> V_6 . V_10 [ V_5 ] . V_4 = V_4 ;
V_4 -> V_6 . V_10 [ V_5 ] . V_11 = V_5 ;
return V_5 ;
}
static void F_5 ( struct V_3 * V_4 , int V_5 )
{
F_6 ( V_4 -> V_6 . V_10 [ V_5 ] . V_12 ) ;
memset ( & V_4 -> V_6 . V_10 [ V_5 ] , 0 , sizeof( struct V_13 ) ) ;
F_7 ( V_5 , V_4 -> V_6 . V_7 ) ;
}
static struct V_13 * F_8 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_9 ( V_15 -> V_18 ) ;
struct V_3 * V_4 = V_17 -> V_19 ;
struct V_20 * V_21 = F_10 ( V_15 ) ;
if ( ! V_21 )
return NULL ;
if ( V_21 -> V_11 == V_9 )
return NULL ;
return & V_4 -> V_6 . V_10 [ V_21 -> V_11 ] ;
}
static int F_11 ( struct V_3 * V_4 , struct V_13 * V_5 )
{
struct V_14 * V_22 ;
T_3 V_23 , V_24 , V_25 ;
long V_26 , V_27 , V_28 ;
if ( V_5 -> V_29 ) {
int V_30 ;
V_24 = V_31 ;
V_25 = V_32 ;
V_22 = V_5 -> V_29 -> V_33 ;
if ( V_5 -> V_34 & V_35 )
V_30 = V_5 -> V_29 -> V_36 . V_37 - V_5 -> V_29 -> V_36 . V_38 + 1 ;
else
V_30 = 1 ;
switch( V_30 ) {
case 1 : V_23 = V_39 ; break;
case 2 : V_23 = V_40 ; break;
case 4 : V_23 = V_41 ; break;
case 8 : V_23 = V_42 ; break;
case 16 : V_23 = V_43 ; break;
case 32 : V_23 = V_44 ; break;
default:
F_12 ( L_1
L_2 ,
F_13 ( V_5 -> V_29 -> V_33 ) , V_30 ) ;
V_23 = V_39 ;
}
V_27 = V_5 -> V_28 + ( V_30 << 8 ) ;
} else {
V_22 = V_5 -> V_12 -> V_18 -> V_33 ;
V_23 = V_39 ;
V_24 = V_45 ;
V_25 = V_46 ;
V_27 = V_5 -> V_28 + 1 ;
}
V_26 = F_14 ( V_4 -> V_47 , V_5 -> V_11 , V_5 -> V_28 ,
V_23 , V_24 , V_25 , V_48 ) ;
if ( V_26 ) {
F_15 ( V_5 , L_3 , V_26 ) ;
return - V_49 ;
}
V_26 = F_16 ( V_4 -> V_47 , V_5 -> V_11 ,
V_5 -> V_11 , V_50 ) ;
if ( V_26 )
F_17 ( V_5 , L_4 , V_26 ) ;
F_18 ( V_4 -> V_47 , V_5 -> V_11 ,
V_51 ) ;
while ( V_22 ) {
struct V_20 * V_21 = F_10 ( V_22 ) ;
if ( V_21 && V_21 -> V_11 != V_9 ) {
V_26 = F_16 ( V_4 -> V_47 , V_21 -> V_11 ,
V_5 -> V_11 , V_50 ) ;
}
V_22 = V_22 -> V_18 -> V_33 ;
}
for ( V_28 = V_5 -> V_28 ; V_28 < V_27 ; V_28 ++ )
V_4 -> V_6 . V_52 [ V_28 ] = V_5 -> V_11 ;
if ( V_4 -> type == V_53 ) {
V_5 -> V_54 = V_5 -> V_11 ;
V_26 = F_19 ( V_4 -> V_47 , V_5 -> V_54 ,
V_5 -> V_11 ) ;
if ( V_26 ) {
F_15 ( V_5 , L_5 ,
V_26 , V_5 -> V_54 ) ;
V_5 -> V_54 = - 1 ;
} else {
V_26 = F_20 ( V_4 -> V_47 ,
V_5 -> V_54 , V_55 ) ;
if ( V_26 ) {
F_15 ( V_5 , L_6 ,
V_26 , V_5 -> V_54 ) ;
V_5 -> V_54 = - 1 ;
}
}
} else if ( V_4 -> type == V_56 )
V_5 -> V_54 = 0 ;
return 0 ;
}
static void F_21 ( struct V_3 * V_4 ,
struct V_13 * V_5 )
{
struct V_13 * V_57 ;
F_22 (lpe, &phb->ioda.pe_dma_list, dma_link) {
if ( V_57 -> V_58 < V_5 -> V_58 ) {
F_23 ( & V_5 -> V_59 , & V_57 -> V_59 ) ;
return;
}
}
F_23 ( & V_5 -> V_59 , & V_4 -> V_6 . V_60 ) ;
}
static unsigned int F_24 ( struct V_14 * V_15 )
{
if ( V_15 -> V_61 != V_62 )
return 0 ;
if ( V_15 -> V_63 == V_64 ||
V_15 -> V_63 == V_65 ||
V_15 -> V_63 == V_66 )
return 3 ;
if ( ( V_15 -> V_63 >> 8 ) == V_67 )
return 15 ;
return 10 ;
}
static void F_25 ( struct V_68 * V_18 , struct V_13 * V_5 )
{
struct V_14 * V_15 ;
F_22 (dev, &bus->devices, bus_list) {
struct V_20 * V_21 = F_10 ( V_15 ) ;
if ( V_21 == NULL ) {
F_26 ( L_7 ,
F_13 ( V_15 ) ) ;
continue;
}
F_27 ( V_15 ) ;
V_21 -> V_69 = V_15 ;
V_21 -> V_11 = V_5 -> V_11 ;
V_5 -> V_58 += F_24 ( V_15 ) ;
if ( ( V_5 -> V_34 & V_35 ) && V_15 -> V_70 )
F_25 ( V_15 -> V_70 , V_5 ) ;
}
}
static void F_28 ( struct V_68 * V_18 , int V_71 )
{
struct V_16 * V_17 = F_9 ( V_18 ) ;
struct V_3 * V_4 = V_17 -> V_19 ;
struct V_13 * V_5 ;
int V_72 ;
V_72 = F_2 ( V_4 ) ;
if ( V_72 == V_9 ) {
F_29 ( L_8 ,
V_73 , F_30 ( V_18 ) , V_18 -> V_74 ) ;
return;
}
V_5 = & V_4 -> V_6 . V_10 [ V_72 ] ;
V_5 -> V_34 = ( V_71 ? V_35 : V_75 ) ;
V_5 -> V_29 = V_18 ;
V_5 -> V_12 = NULL ;
V_5 -> V_76 = - 1 ;
V_5 -> V_54 = - 1 ;
V_5 -> V_28 = V_18 -> V_36 . V_38 << 8 ;
V_5 -> V_58 = 0 ;
if ( V_71 )
F_31 ( V_5 , L_9 ,
V_18 -> V_36 . V_38 , V_18 -> V_36 . V_37 , V_72 ) ;
else
F_31 ( V_5 , L_10 ,
V_18 -> V_36 . V_38 , V_72 ) ;
if ( F_11 ( V_4 , V_5 ) ) {
if ( V_72 )
F_5 ( V_4 , V_72 ) ;
V_5 -> V_29 = NULL ;
return;
}
F_25 ( V_18 , V_5 ) ;
F_23 ( & V_5 -> V_77 , & V_4 -> V_6 . V_78 ) ;
if ( V_5 -> V_58 != 0 ) {
V_4 -> V_6 . V_58 += V_5 -> V_58 ;
V_4 -> V_6 . V_79 ++ ;
}
F_21 ( V_4 , V_5 ) ;
}
static void F_32 ( struct V_68 * V_18 )
{
struct V_14 * V_15 ;
F_28 ( V_18 , 0 ) ;
F_22 (dev, &bus->devices, bus_list) {
if ( V_15 -> V_70 ) {
if ( F_33 ( V_15 ) == V_80 )
F_28 ( V_15 -> V_70 , 1 ) ;
else
F_32 ( V_15 -> V_70 ) ;
}
}
}
static void F_34 ( void )
{
struct V_16 * V_17 , * V_81 ;
F_35 (hose, tmp, &hose_list, list_node) {
F_32 ( V_17 -> V_18 ) ;
}
}
static void F_36 ( struct V_3 * V_4 , struct V_14 * V_12 )
{
struct V_20 * V_21 = F_10 ( V_12 ) ;
struct V_13 * V_5 ;
if ( ! V_21 || V_21 -> V_11 == V_9 )
return;
V_5 = & V_4 -> V_6 . V_10 [ V_21 -> V_11 ] ;
F_37 ( & V_12 -> V_15 , & V_5 -> V_82 ) ;
}
static void F_38 ( struct V_13 * V_5 , struct V_68 * V_18 )
{
struct V_14 * V_15 ;
F_22 (dev, &bus->devices, bus_list) {
F_37 ( & V_15 -> V_15 , & V_5 -> V_82 ) ;
if ( V_15 -> V_70 )
F_38 ( V_5 , V_15 -> V_70 ) ;
}
}
static void F_39 ( struct V_13 * V_5 ,
struct V_83 * V_84 ,
T_4 * V_85 , T_4 * V_86 , bool V_87 )
{
T_4 T_2 * V_88 = V_87 ?
( T_4 T_2 * ) V_5 -> V_89 :
( T_4 T_2 * ) V_84 -> V_90 ;
unsigned long V_38 , V_37 , V_91 ;
V_38 = F_40 ( V_85 ) ;
V_37 = F_40 ( V_86 ) ;
if ( V_84 -> V_92 ) {
V_38 <<= 12 ;
V_37 <<= 12 ;
V_91 = 128 << 12 ;
V_38 |= V_84 -> V_92 ;
V_37 |= V_84 -> V_92 ;
} else if ( V_84 -> V_93 & V_94 ) {
V_38 |= ( 1ull << 63 ) ;
V_37 |= ( 1ull << 63 ) ;
V_91 = 16 ;
} else {
V_91 = 128 ;
}
V_37 |= V_91 - 1 ;
F_41 () ;
while ( V_38 <= V_37 ) {
if ( V_87 )
F_1 ( F_42 ( V_38 ) , V_88 ) ;
else
F_43 ( F_42 ( V_38 ) , V_88 ) ;
V_38 += V_91 ;
}
}
static void F_44 ( struct V_13 * V_5 ,
struct V_83 * V_84 ,
T_4 * V_85 , T_4 * V_86 , bool V_87 )
{
unsigned long V_38 , V_37 , V_91 ;
T_4 T_2 * V_88 = V_87 ?
( T_4 T_2 * ) V_5 -> V_89 :
( T_4 T_2 * ) V_84 -> V_90 ;
V_38 = 0x2ul << 60 ;
V_38 |= ( V_5 -> V_11 & 0xFF ) ;
V_37 = V_38 ;
V_91 = V_84 -> V_95 + ( ( ( T_1 ) V_85 - V_84 -> V_96 ) / sizeof( T_1 ) ) ;
V_38 |= ( V_91 << 12 ) ;
V_91 = V_84 -> V_95 + ( ( ( T_1 ) V_86 - V_84 -> V_96 ) / sizeof( T_1 ) ) ;
V_37 |= ( V_91 << 12 ) ;
V_91 = ( 0x1ul << 12 ) ;
F_41 () ;
while ( V_38 <= V_37 ) {
if ( V_87 )
F_1 ( F_42 ( V_38 ) , V_88 ) ;
else
F_43 ( F_42 ( V_38 ) , V_88 ) ;
V_38 += V_91 ;
}
}
void F_45 ( struct V_83 * V_84 ,
T_4 * V_85 , T_4 * V_86 , bool V_87 )
{
struct V_13 * V_5 = F_46 ( V_84 , struct V_13 ,
V_82 ) ;
struct V_3 * V_4 = V_5 -> V_4 ;
if ( V_4 -> type == V_53 )
F_39 ( V_5 , V_84 , V_85 , V_86 , V_87 ) ;
else
F_44 ( V_5 , V_84 , V_85 , V_86 , V_87 ) ;
}
static void F_47 ( struct V_3 * V_4 ,
struct V_13 * V_5 , unsigned int V_97 ,
unsigned int V_98 )
{
struct V_99 * V_100 = NULL ;
const T_4 * V_101 ;
struct V_83 * V_84 ;
unsigned int V_102 ;
T_5 V_26 ;
void * V_103 ;
#define F_48 ((0x10000000 / 0x1000) * 8)
if ( F_6 ( V_5 -> V_76 >= 0 ) )
return;
V_5 -> V_76 = V_97 ;
F_31 ( V_5 , L_11 ,
( V_97 << 28 ) , ( ( V_97 + V_98 ) << 28 ) - 1 ) ;
V_100 = F_49 ( V_4 -> V_17 -> V_104 , V_105 ,
F_50 ( F_48 * V_98 ) ) ;
if ( ! V_100 ) {
F_15 ( V_5 , L_12 ) ;
goto V_106;
}
V_103 = F_51 ( V_100 ) ;
memset ( V_103 , 0 , F_48 * V_98 ) ;
for ( V_102 = 0 ; V_102 < V_98 ; V_102 ++ ) {
V_26 = F_52 ( V_4 -> V_47 ,
V_5 -> V_11 ,
V_97 + V_102 , 1 ,
F_40 ( V_103 ) + F_48 * V_102 ,
F_48 , 0x1000 ) ;
if ( V_26 ) {
F_15 ( V_5 , L_13
L_14 , V_26 ) ;
goto V_106;
}
}
V_84 = & V_5 -> V_82 ;
F_53 ( V_84 , V_103 , F_48 * V_98 ,
V_97 << 28 ) ;
V_101 = F_54 ( V_4 -> V_17 -> V_107 , L_15 , NULL ) ;
if ( V_101 ) {
V_84 -> V_92 = 0 ;
V_5 -> V_89 = F_55 ( V_101 ) ;
V_84 -> V_90 = ( unsigned long ) F_56 ( V_5 -> V_89 ,
8 ) ;
V_84 -> V_93 = V_108 | V_109 |
V_94 ;
}
F_57 ( V_84 , V_4 -> V_17 -> V_104 ) ;
F_58 ( V_84 , F_30 ( V_5 -> V_29 ) , V_5 -> V_11 ) ;
if ( V_5 -> V_12 )
F_37 ( & V_5 -> V_12 -> V_15 , V_84 ) ;
else
F_38 ( V_5 , V_5 -> V_29 ) ;
return;
V_106:
if ( V_5 -> V_76 >= 0 )
V_5 -> V_76 = - 1 ;
if ( V_100 )
F_59 ( V_100 , F_50 ( F_48 * V_98 ) ) ;
}
static void F_60 ( struct V_3 * V_4 ,
struct V_13 * V_5 )
{
struct V_99 * V_100 = NULL ;
void * V_103 ;
const T_4 * V_101 ;
struct V_83 * V_84 ;
unsigned int V_110 , V_37 ;
T_5 V_26 ;
if ( F_6 ( V_5 -> V_76 >= 0 ) )
return;
V_5 -> V_76 = 0 ;
V_37 = ( 1 << F_61 ( V_4 -> V_6 . V_111 ) ) ;
V_110 = ( V_37 / 0x1000 ) * 8 ;
F_31 ( V_5 , L_16 ,
V_37 ) ;
V_100 = F_49 ( V_4 -> V_17 -> V_104 , V_105 ,
F_50 ( V_110 ) ) ;
if ( ! V_100 ) {
F_15 ( V_5 , L_17 ) ;
goto V_106;
}
V_103 = F_51 ( V_100 ) ;
memset ( V_103 , 0 , V_110 ) ;
V_26 = F_52 ( V_4 -> V_47 , V_5 -> V_11 ,
V_5 -> V_11 << 1 , 1 , F_40 ( V_103 ) ,
V_110 , 0x1000 ) ;
if ( V_26 ) {
F_15 ( V_5 , L_18
L_14 , V_26 ) ;
goto V_106;
}
V_84 = & V_5 -> V_82 ;
F_53 ( V_84 , V_103 , V_110 , 0 ) ;
V_101 = F_54 ( V_4 -> V_17 -> V_107 , L_15 , NULL ) ;
if ( V_101 ) {
V_84 -> V_92 = 0 ;
V_5 -> V_89 = F_55 ( V_101 ) ;
V_84 -> V_90 = ( unsigned long ) F_56 ( V_5 -> V_89 ,
8 ) ;
V_84 -> V_93 = V_108 | V_109 ;
}
F_57 ( V_84 , V_4 -> V_17 -> V_104 ) ;
F_58 ( V_84 , F_30 ( V_5 -> V_29 ) , V_5 -> V_11 ) ;
if ( V_5 -> V_12 )
F_37 ( & V_5 -> V_12 -> V_15 , V_84 ) ;
else
F_38 ( V_5 , V_5 -> V_29 ) ;
return;
V_106:
if ( V_5 -> V_76 >= 0 )
V_5 -> V_76 = - 1 ;
if ( V_100 )
F_59 ( V_100 , F_50 ( V_110 ) ) ;
}
static void F_62 ( struct V_3 * V_4 )
{
struct V_16 * V_17 = V_4 -> V_17 ;
unsigned int V_112 , V_113 , V_98 , V_114 , V_97 ;
struct V_13 * V_5 ;
if ( V_4 -> V_6 . V_79 > V_4 -> V_6 . V_115 )
V_112 = 0 ;
else
V_112 = V_4 -> V_6 . V_115 -
V_4 -> V_6 . V_79 ;
F_63 ( L_19 ,
V_17 -> V_116 , V_4 -> V_6 . V_115 ) ;
F_63 ( L_20 ,
V_4 -> V_6 . V_79 , V_4 -> V_6 . V_58 ) ;
V_113 = V_4 -> V_6 . V_115 ;
V_114 = V_4 -> V_6 . V_58 ;
V_97 = 0 ;
F_22 (pe, &phb->ioda.pe_dma_list, dma_link) {
if ( ! V_5 -> V_58 )
continue;
if ( ! V_113 ) {
F_17 ( V_5 , L_21 ) ;
continue;
}
V_98 = 1 ;
if ( V_112 ) {
V_98 += ( ( V_5 -> V_58 * V_112 ) + ( V_114 / 2 ) ) / V_114 ;
if ( V_98 > V_113 )
V_98 = V_113 ;
}
if ( V_4 -> type == V_53 ) {
F_31 ( V_5 , L_22 ,
V_5 -> V_58 , V_98 ) ;
F_47 ( V_4 , V_5 , V_97 , V_98 ) ;
} else {
F_31 ( V_5 , L_23 ) ;
V_98 = 0 ;
F_60 ( V_4 , V_5 ) ;
}
V_113 -= V_98 ;
V_97 += V_98 ;
}
}
static void F_64 ( struct V_117 * V_118 )
{
unsigned int V_119 = ( unsigned int ) F_65 ( V_118 ) ;
struct V_120 * V_121 = F_66 ( V_118 ) ;
struct V_3 * V_4 = F_46 ( V_121 , struct V_3 ,
V_6 . V_120 ) ;
T_5 V_26 ;
V_26 = F_67 ( V_4 -> V_47 , V_119 ) ;
F_68 ( V_26 ) ;
F_69 ( V_118 ) ;
}
static int F_70 ( struct V_3 * V_4 , struct V_14 * V_15 ,
unsigned int V_122 , unsigned int V_123 ,
unsigned int V_124 , struct V_125 * V_126 )
{
struct V_13 * V_5 = F_8 ( V_15 ) ;
struct V_20 * V_21 = F_10 ( V_15 ) ;
struct V_117 * V_127 ;
struct V_120 * V_128 ;
unsigned int V_129 = V_122 - V_4 -> V_130 ;
T_6 V_131 ;
int V_26 ;
if ( V_5 == NULL )
return - V_49 ;
if ( V_5 -> V_54 < 0 )
return - V_49 ;
if ( V_21 && V_21 -> V_132 )
V_124 = 0 ;
V_26 = F_71 ( V_4 -> V_47 , V_5 -> V_11 , V_129 ) ;
if ( V_26 ) {
F_26 ( L_24 ,
F_13 ( V_15 ) , V_26 , V_129 ) ;
return - V_133 ;
}
if ( V_124 ) {
T_4 V_134 ;
V_26 = F_72 ( V_4 -> V_47 , V_5 -> V_54 , V_129 , 1 ,
& V_134 , & V_131 ) ;
if ( V_26 ) {
F_26 ( L_25 ,
F_13 ( V_15 ) , V_26 ) ;
return - V_133 ;
}
V_126 -> V_135 = F_73 ( V_134 ) >> 32 ;
V_126 -> V_136 = F_73 ( V_134 ) & 0xfffffffful ;
} else {
T_6 V_137 ;
V_26 = F_74 ( V_4 -> V_47 , V_5 -> V_54 , V_129 , 1 ,
& V_137 , & V_131 ) ;
if ( V_26 ) {
F_26 ( L_26 ,
F_13 ( V_15 ) , V_26 ) ;
return - V_133 ;
}
V_126 -> V_135 = 0 ;
V_126 -> V_136 = F_75 ( V_137 ) ;
}
V_126 -> V_131 = F_75 ( V_131 ) ;
if ( V_4 -> type == V_56 ) {
if ( ! V_4 -> V_6 . V_138 ) {
V_127 = F_76 ( V_123 ) ;
V_128 = F_66 ( V_127 ) ;
V_4 -> V_6 . V_138 = 1 ;
V_4 -> V_6 . V_120 = * V_128 ;
V_4 -> V_6 . V_120 . V_139 = F_64 ;
}
F_77 ( V_123 , & V_4 -> V_6 . V_120 ) ;
}
F_78 ( L_27
L_28 ,
F_13 ( V_15 ) , V_124 ? L_29 : L_30 , V_122 , V_129 ,
V_126 -> V_135 , V_126 -> V_136 , V_131 , V_5 -> V_11 ) ;
return 0 ;
}
static void F_79 ( struct V_3 * V_4 )
{
unsigned int V_30 ;
const T_6 * V_140 = F_54 ( V_4 -> V_17 -> V_107 ,
L_31 , NULL ) ;
if ( ! V_140 ) {
V_140 = F_54 ( V_4 -> V_17 -> V_107 , L_32 , NULL ) ;
}
if ( ! V_140 )
return;
V_4 -> V_130 = F_80 ( V_140 ) ;
V_30 = F_80 ( V_140 + 1 ) ;
if ( F_81 ( & V_4 -> V_141 , V_30 , V_4 -> V_17 -> V_107 ) ) {
F_12 ( L_33 ,
V_4 -> V_17 -> V_116 ) ;
return;
}
V_4 -> V_142 = F_70 ;
V_4 -> V_143 = 1 ;
F_63 ( L_34 ,
V_30 , V_4 -> V_130 ) ;
}
static void F_79 ( struct V_3 * V_4 ) { }
static void F_82 ( struct V_16 * V_17 ,
struct V_13 * V_5 )
{
struct V_3 * V_4 = V_17 -> V_19 ;
struct V_144 V_145 ;
struct V_146 * V_147 ;
int V_102 , V_148 ;
int V_26 ;
F_83 ( ! ( V_5 -> V_34 & ( V_75 | V_35 ) ) ) ;
F_84 (pe->pbus, res, i) {
if ( ! V_147 || ! V_147 -> V_34 ||
V_147 -> V_38 > V_147 -> V_37 )
continue;
if ( V_147 -> V_34 & V_149 ) {
V_145 . V_38 = V_147 -> V_38 - V_4 -> V_6 . V_150 ;
V_145 . V_37 = V_147 -> V_37 - V_4 -> V_6 . V_150 ;
V_148 = V_145 . V_38 / V_4 -> V_6 . V_151 ;
while ( V_148 < V_4 -> V_6 . V_8 &&
V_145 . V_38 <= V_145 . V_37 ) {
V_4 -> V_6 . V_152 [ V_148 ] = V_5 -> V_11 ;
V_26 = F_85 ( V_4 -> V_47 ,
V_5 -> V_11 , V_153 , 0 , V_148 ) ;
if ( V_26 != V_154 ) {
F_12 ( L_35
L_36 ,
V_73 , V_26 , V_148 , V_5 -> V_11 ) ;
break;
}
V_145 . V_38 += V_4 -> V_6 . V_151 ;
V_148 ++ ;
}
} else if ( V_147 -> V_34 & V_155 ) {
V_145 . V_38 = V_147 -> V_38 -
V_17 -> V_156 [ 0 ] -
V_4 -> V_6 . V_111 ;
V_145 . V_37 = V_147 -> V_37 -
V_17 -> V_156 [ 0 ] -
V_4 -> V_6 . V_111 ;
V_148 = V_145 . V_38 / V_4 -> V_6 . V_157 ;
while ( V_148 < V_4 -> V_6 . V_8 &&
V_145 . V_38 <= V_145 . V_37 ) {
V_4 -> V_6 . V_158 [ V_148 ] = V_5 -> V_11 ;
V_26 = F_85 ( V_4 -> V_47 ,
V_5 -> V_11 , V_159 , 0 , V_148 ) ;
if ( V_26 != V_154 ) {
F_12 ( L_37
L_38 ,
V_73 , V_26 , V_148 , V_5 -> V_11 ) ;
break;
}
V_145 . V_38 += V_4 -> V_6 . V_157 ;
V_148 ++ ;
}
}
}
}
static void F_86 ( void )
{
struct V_16 * V_81 , * V_17 ;
struct V_3 * V_4 ;
struct V_13 * V_5 ;
F_35 (hose, tmp, &hose_list, list_node) {
V_4 = V_17 -> V_19 ;
F_22 (pe, &phb->ioda.pe_list, list) {
F_82 ( V_17 , V_5 ) ;
}
}
}
static void F_87 ( void )
{
struct V_16 * V_17 , * V_81 ;
struct V_3 * V_4 ;
F_35 (hose, tmp, &hose_list, list_node) {
F_62 ( V_17 -> V_19 ) ;
V_4 = V_17 -> V_19 ;
V_4 -> V_160 = 1 ;
}
}
static void F_88 ( void )
{
#ifdef F_89
struct V_16 * V_17 , * V_81 ;
struct V_3 * V_4 ;
char V_161 [ 16 ] ;
F_35 (hose, tmp, &hose_list, list_node) {
V_4 = V_17 -> V_19 ;
sprintf ( V_161 , L_39 , V_17 -> V_116 ) ;
V_4 -> V_162 = F_90 ( V_161 , V_163 ) ;
if ( ! V_4 -> V_162 )
F_29 ( L_40 ,
V_73 , V_17 -> V_116 ) ;
}
#endif
}
static void F_91 ( void )
{
F_34 () ;
F_86 () ;
F_87 () ;
F_88 () ;
#ifdef F_92
F_93 ( V_164 ) ;
F_94 () ;
F_95 () ;
#endif
}
static T_7 F_96 ( struct V_68 * V_18 ,
unsigned long type )
{
struct V_14 * V_165 ;
struct V_16 * V_17 = F_9 ( V_18 ) ;
struct V_3 * V_4 = V_17 -> V_19 ;
int V_166 = 0 ;
V_165 = V_18 -> V_33 ;
while ( V_165 ) {
if ( F_33 ( V_165 ) == V_80 ) {
V_166 ++ ;
if ( V_166 >= 2 )
return 1 ;
}
V_165 = V_165 -> V_18 -> V_33 ;
}
if ( type & V_155 )
return V_4 -> V_6 . V_157 ;
return V_4 -> V_6 . V_151 ;
}
static int F_97 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_9 ( V_15 -> V_18 ) ;
struct V_3 * V_4 = V_17 -> V_19 ;
struct V_20 * V_21 ;
if ( ! V_4 -> V_160 )
return 0 ;
V_21 = F_10 ( V_15 ) ;
if ( ! V_21 || V_21 -> V_11 == V_9 )
return - V_167 ;
return 0 ;
}
static T_8 F_98 ( struct V_3 * V_4 , struct V_68 * V_18 ,
T_8 V_168 )
{
return V_4 -> V_6 . V_52 [ ( V_18 -> V_74 << 8 ) | V_168 ] ;
}
static void F_99 ( struct V_3 * V_4 )
{
F_100 ( V_4 -> V_47 , V_169 ,
V_170 ) ;
}
void T_9 F_101 ( struct V_171 * V_172 ,
T_1 V_173 , int V_174 )
{
struct V_16 * V_17 ;
struct V_3 * V_4 ;
unsigned long V_175 , V_176 , V_177 , V_178 ;
const T_4 * V_179 ;
const T_6 * V_180 ;
int V_181 ;
T_1 V_182 ;
void * V_183 ;
long V_26 ;
F_63 ( L_41 , V_174 , V_172 -> V_184 ) ;
V_179 = F_54 ( V_172 , L_42 , NULL ) ;
if ( ! V_179 ) {
F_12 ( L_43 ) ;
return;
}
V_182 = F_55 ( V_179 ) ;
F_102 ( L_44 , V_182 ) ;
V_4 = F_103 ( sizeof( struct V_3 ) ) ;
if ( ! V_4 ) {
F_12 ( L_45 ) ;
return;
}
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 -> V_17 = V_17 = F_104 ( V_172 ) ;
if ( ! V_4 -> V_17 ) {
F_12 ( L_46 ,
V_172 -> V_184 ) ;
F_105 ( ( unsigned long ) V_4 , sizeof( struct V_3 ) ) ;
return;
}
F_106 ( & V_4 -> V_185 ) ;
V_180 = F_54 ( V_172 , L_47 , & V_181 ) ;
if ( V_180 && V_181 == 8 ) {
V_17 -> V_186 = F_75 ( V_180 [ 0 ] ) ;
V_17 -> V_187 = F_75 ( V_180 [ 1 ] ) ;
} else {
F_26 ( L_48 , V_172 -> V_184 ) ;
V_17 -> V_186 = 0 ;
V_17 -> V_187 = 0xff ;
}
V_17 -> V_19 = V_4 ;
V_4 -> V_173 = V_173 ;
V_4 -> V_47 = V_182 ;
V_4 -> type = V_174 ;
if ( F_107 ( V_172 , L_49 ) )
V_4 -> V_188 = V_189 ;
else if ( F_107 ( V_172 , L_50 ) )
V_4 -> V_188 = V_190 ;
else
V_4 -> V_188 = V_191 ;
F_108 ( V_17 , V_172 , ! V_17 -> V_116 ) ;
V_4 -> V_192 = F_109 ( V_172 , 0 ) ;
if ( V_4 -> V_192 == NULL )
F_12 ( L_51 ) ;
V_4 -> V_6 . V_8 = 1 ;
V_180 = F_54 ( V_172 , L_52 , NULL ) ;
if ( V_180 )
V_4 -> V_6 . V_8 = F_80 ( V_180 ) ;
V_180 = F_54 ( V_172 , L_53 , NULL ) ;
if ( V_180 )
V_4 -> V_6 . V_193 = F_80 ( V_180 ) ;
V_4 -> V_6 . V_194 = F_110 ( & V_17 -> V_195 [ 0 ] ) ;
V_4 -> V_6 . V_194 += 0x10000 ;
V_4 -> V_6 . V_157 = V_4 -> V_6 . V_194 / V_4 -> V_6 . V_8 ;
V_4 -> V_6 . V_111 = V_17 -> V_195 [ 0 ] . V_38 - V_17 -> V_156 [ 0 ] ;
V_4 -> V_6 . V_196 = V_17 -> V_197 ;
V_4 -> V_6 . V_151 = V_4 -> V_6 . V_196 / V_4 -> V_6 . V_8 ;
V_4 -> V_6 . V_150 = 0 ;
V_175 = F_111 ( V_4 -> V_6 . V_8 / 8 , sizeof( unsigned long ) ) ;
V_176 = V_175 ;
V_175 += V_4 -> V_6 . V_8 * sizeof( V_4 -> V_6 . V_158 [ 0 ] ) ;
V_177 = V_175 ;
if ( V_4 -> type == V_53 ) {
V_177 = V_175 ;
V_175 += V_4 -> V_6 . V_8 * sizeof( V_4 -> V_6 . V_152 [ 0 ] ) ;
}
V_178 = V_175 ;
V_175 += V_4 -> V_6 . V_8 * sizeof( struct V_13 ) ;
V_183 = F_103 ( V_175 ) ;
memset ( V_183 , 0 , V_175 ) ;
V_4 -> V_6 . V_7 = V_183 ;
V_4 -> V_6 . V_158 = V_183 + V_176 ;
if ( V_4 -> type == V_53 )
V_4 -> V_6 . V_152 = V_183 + V_177 ;
V_4 -> V_6 . V_10 = V_183 + V_178 ;
F_112 ( V_4 -> V_6 . V_193 , V_4 -> V_6 . V_7 ) ;
F_113 ( & V_4 -> V_6 . V_60 ) ;
F_113 ( & V_4 -> V_6 . V_78 ) ;
V_4 -> V_6 . V_115 = V_4 -> V_6 . V_111 >> 28 ;
V_17 -> V_195 [ 1 ] . V_34 = 0 ;
V_17 -> V_195 [ 1 ] . V_38 = 0 ;
V_17 -> V_195 [ 1 ] . V_37 = 0 ;
V_17 -> V_195 [ 2 ] . V_34 = 0 ;
V_17 -> V_195 [ 2 ] . V_38 = 0 ;
V_17 -> V_195 [ 2 ] . V_37 = 0 ;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
F_63 ( L_54
L_55 ,
V_4 -> V_6 . V_8 ,
V_4 -> V_6 . V_193 ,
V_4 -> V_6 . V_194 , V_4 -> V_6 . V_157 ,
V_4 -> V_6 . V_196 , V_4 -> V_6 . V_151 ) ;
V_4 -> V_17 -> V_198 = & V_199 ;
#ifdef F_92
V_4 -> V_200 = & V_201 ;
#endif
V_4 -> V_202 = F_98 ;
V_4 -> V_203 = F_36 ;
V_4 -> V_204 = F_99 ;
F_79 ( V_4 ) ;
V_205 . V_206 = F_91 ;
V_205 . V_207 = F_97 ;
V_205 . V_208 = F_96 ;
F_114 ( V_209 ) ;
V_26 = F_100 ( V_182 , V_169 , V_170 ) ;
if ( V_26 )
F_29 ( L_56 , V_26 ) ;
}
void T_9 F_115 ( struct V_171 * V_172 )
{
F_101 ( V_172 , 0 , V_56 ) ;
}
void T_9 F_116 ( struct V_171 * V_172 )
{
struct V_171 * V_210 ;
const T_4 * V_179 ;
T_1 V_173 ;
F_63 ( L_57 , V_172 -> V_184 ) ;
V_179 = F_54 ( V_172 , L_58 , NULL ) ;
if ( ! V_179 ) {
F_12 ( L_59 ) ;
return;
}
V_173 = F_55 ( V_179 ) ;
F_78 ( L_60 , V_173 ) ;
F_117 (np, phbn) {
if ( F_107 ( V_210 , L_61 ) )
F_101 ( V_210 , V_173 , V_53 ) ;
}
}
