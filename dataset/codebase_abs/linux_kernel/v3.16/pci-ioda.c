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
V_21 -> V_69 = V_15 ;
V_21 -> V_11 = V_5 -> V_11 ;
V_5 -> V_58 += F_24 ( V_15 ) ;
if ( ( V_5 -> V_34 & V_35 ) && V_15 -> V_70 )
F_25 ( V_15 -> V_70 , V_5 ) ;
}
}
static void F_27 ( struct V_68 * V_18 , int V_71 )
{
struct V_16 * V_17 = F_9 ( V_18 ) ;
struct V_3 * V_4 = V_17 -> V_19 ;
struct V_13 * V_5 ;
int V_72 ;
V_72 = F_2 ( V_4 ) ;
if ( V_72 == V_9 ) {
F_28 ( L_8 ,
V_73 , F_29 ( V_18 ) , V_18 -> V_74 ) ;
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
F_30 ( V_5 , L_9 ,
V_18 -> V_36 . V_38 , V_18 -> V_36 . V_37 , V_72 ) ;
else
F_30 ( V_5 , L_10 ,
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
static void F_31 ( struct V_68 * V_18 )
{
struct V_14 * V_15 ;
F_27 ( V_18 , 0 ) ;
F_22 (dev, &bus->devices, bus_list) {
if ( V_15 -> V_70 ) {
if ( F_32 ( V_15 ) == V_80 )
F_27 ( V_15 -> V_70 , 1 ) ;
else
F_31 ( V_15 -> V_70 ) ;
}
}
}
static void F_33 ( void )
{
struct V_16 * V_17 , * V_81 ;
F_34 (hose, tmp, &hose_list, list_node) {
F_31 ( V_17 -> V_18 ) ;
}
}
static void F_35 ( struct V_3 * V_4 , struct V_14 * V_12 )
{
struct V_20 * V_21 = F_10 ( V_12 ) ;
struct V_13 * V_5 ;
if ( ! V_21 || V_21 -> V_11 == V_9 )
return;
V_5 = & V_4 -> V_6 . V_10 [ V_21 -> V_11 ] ;
F_6 ( F_36 ( & V_12 -> V_15 ) != & V_82 ) ;
F_37 ( & V_12 -> V_15 , & V_5 -> V_83 ) ;
}
static int F_38 ( struct V_3 * V_4 ,
struct V_14 * V_12 , T_1 V_84 )
{
struct V_20 * V_21 = F_10 ( V_12 ) ;
struct V_13 * V_5 ;
T_4 V_85 ;
bool V_86 = false ;
if ( F_6 ( ! V_21 || V_21 -> V_11 == V_9 ) )
return - V_87 ; ;
V_5 = & V_4 -> V_6 . V_10 [ V_21 -> V_11 ] ;
if ( V_5 -> V_88 ) {
V_85 = V_5 -> V_89 + F_39 () - 1 ;
V_86 = ( V_84 >= V_85 ) ;
}
if ( V_86 ) {
F_40 ( & V_12 -> V_15 , L_11 ) ;
F_41 ( & V_12 -> V_15 , & V_90 ) ;
F_42 ( & V_12 -> V_15 , V_5 -> V_89 ) ;
} else {
F_40 ( & V_12 -> V_15 , L_12 ) ;
F_41 ( & V_12 -> V_15 , & V_82 ) ;
F_37 ( & V_12 -> V_15 , & V_5 -> V_83 ) ;
}
return 0 ;
}
static void F_43 ( struct V_13 * V_5 , struct V_68 * V_18 )
{
struct V_14 * V_15 ;
F_22 (dev, &bus->devices, bus_list) {
F_44 ( & V_15 -> V_15 , & V_5 -> V_83 ) ;
if ( V_15 -> V_70 )
F_43 ( V_5 , V_15 -> V_70 ) ;
}
}
static void F_45 ( struct V_13 * V_5 ,
struct V_91 * V_92 ,
T_5 * V_93 , T_5 * V_94 , bool V_95 )
{
T_5 T_2 * V_96 = V_95 ?
( T_5 T_2 * ) V_5 -> V_97 :
( T_5 T_2 * ) V_92 -> V_98 ;
unsigned long V_38 , V_37 , V_99 ;
V_38 = F_46 ( V_93 ) ;
V_37 = F_46 ( V_94 ) ;
if ( V_92 -> V_100 ) {
V_38 <<= 12 ;
V_37 <<= 12 ;
V_99 = 128 << 12 ;
V_38 |= V_92 -> V_100 ;
V_37 |= V_92 -> V_100 ;
} else if ( V_92 -> V_101 & V_102 ) {
V_38 |= ( 1ull << 63 ) ;
V_37 |= ( 1ull << 63 ) ;
V_99 = 16 ;
} else {
V_99 = 128 ;
}
V_37 |= V_99 - 1 ;
F_47 () ;
while ( V_38 <= V_37 ) {
if ( V_95 )
F_1 ( F_48 ( V_38 ) , V_96 ) ;
else
F_49 ( F_48 ( V_38 ) , V_96 ) ;
V_38 += V_99 ;
}
}
static void F_50 ( struct V_13 * V_5 ,
struct V_91 * V_92 ,
T_5 * V_93 , T_5 * V_94 , bool V_95 )
{
unsigned long V_38 , V_37 , V_99 ;
T_5 T_2 * V_96 = V_95 ?
( T_5 T_2 * ) V_5 -> V_97 :
( T_5 T_2 * ) V_92 -> V_98 ;
V_38 = 0x2ul << 60 ;
V_38 |= ( V_5 -> V_11 & 0xFF ) ;
V_37 = V_38 ;
V_99 = V_92 -> V_103 + ( ( ( T_1 ) V_93 - V_92 -> V_104 ) / sizeof( T_1 ) ) ;
V_38 |= ( V_99 << 12 ) ;
V_99 = V_92 -> V_103 + ( ( ( T_1 ) V_94 - V_92 -> V_104 ) / sizeof( T_1 ) ) ;
V_37 |= ( V_99 << 12 ) ;
V_99 = ( 0x1ul << 12 ) ;
F_47 () ;
while ( V_38 <= V_37 ) {
if ( V_95 )
F_1 ( F_48 ( V_38 ) , V_96 ) ;
else
F_49 ( F_48 ( V_38 ) , V_96 ) ;
V_38 += V_99 ;
}
}
void F_51 ( struct V_91 * V_92 ,
T_5 * V_93 , T_5 * V_94 , bool V_95 )
{
struct V_13 * V_5 = F_52 ( V_92 , struct V_13 ,
V_83 ) ;
struct V_3 * V_4 = V_5 -> V_4 ;
if ( V_4 -> type == V_53 )
F_45 ( V_5 , V_92 , V_93 , V_94 , V_95 ) ;
else
F_50 ( V_5 , V_92 , V_93 , V_94 , V_95 ) ;
}
static void F_53 ( struct V_3 * V_4 ,
struct V_13 * V_5 , unsigned int V_105 ,
unsigned int V_106 )
{
struct V_107 * V_108 = NULL ;
const T_5 * V_109 ;
struct V_91 * V_92 ;
unsigned int V_110 ;
T_6 V_26 ;
void * V_111 ;
#define F_54 ((0x10000000 / 0x1000) * 8)
if ( F_6 ( V_5 -> V_76 >= 0 ) )
return;
V_5 -> V_76 = V_105 ;
F_30 ( V_5 , L_13 ,
( V_105 << 28 ) , ( ( V_105 + V_106 ) << 28 ) - 1 ) ;
V_108 = F_55 ( V_4 -> V_17 -> V_112 , V_113 ,
F_56 ( F_54 * V_106 ) ) ;
if ( ! V_108 ) {
F_15 ( V_5 , L_14 ) ;
goto V_114;
}
V_111 = F_57 ( V_108 ) ;
memset ( V_111 , 0 , F_54 * V_106 ) ;
for ( V_110 = 0 ; V_110 < V_106 ; V_110 ++ ) {
V_26 = F_58 ( V_4 -> V_47 ,
V_5 -> V_11 ,
V_105 + V_110 , 1 ,
F_46 ( V_111 ) + F_54 * V_110 ,
F_54 , 0x1000 ) ;
if ( V_26 ) {
F_15 ( V_5 , L_15
L_16 , V_26 ) ;
goto V_114;
}
}
V_92 = & V_5 -> V_83 ;
F_59 ( V_92 , V_111 , F_54 * V_106 ,
V_105 << 28 ) ;
V_109 = F_60 ( V_4 -> V_17 -> V_115 , L_17 , NULL ) ;
if ( V_109 ) {
V_5 -> V_97 = F_61 ( V_109 ) ;
V_92 -> V_98 = ( unsigned long ) F_62 ( V_5 -> V_97 ,
8 ) ;
V_92 -> V_101 |= ( V_116 |
V_117 |
V_102 ) ;
}
F_63 ( V_92 , V_4 -> V_17 -> V_112 ) ;
F_64 ( V_92 , V_4 -> V_17 -> V_118 , V_5 -> V_11 ) ;
if ( V_5 -> V_12 )
F_44 ( & V_5 -> V_12 -> V_15 , V_92 ) ;
else
F_43 ( V_5 , V_5 -> V_29 ) ;
return;
V_114:
if ( V_5 -> V_76 >= 0 )
V_5 -> V_76 = - 1 ;
if ( V_108 )
F_65 ( V_108 , F_56 ( F_54 * V_106 ) ) ;
}
static void F_66 ( struct V_91 * V_92 , bool V_119 )
{
struct V_13 * V_5 = F_52 ( V_92 , struct V_13 ,
V_83 ) ;
T_7 V_120 = ( V_5 -> V_11 << 1 ) + 1 ;
T_6 V_26 ;
F_30 ( V_5 , L_18 , V_119 ? L_19 : L_20 ) ;
if ( V_119 ) {
T_8 V_85 = F_39 () ;
V_85 = F_67 ( V_85 ) ;
V_26 = F_68 ( V_5 -> V_4 -> V_47 ,
V_5 -> V_11 ,
V_120 ,
V_5 -> V_89 ,
V_85 ) ;
} else {
V_26 = F_68 ( V_5 -> V_4 -> V_47 ,
V_5 -> V_11 ,
V_120 ,
V_5 -> V_89 ,
0 ) ;
}
if ( V_26 )
F_15 ( V_5 , L_21 , V_26 ) ;
else
V_5 -> V_88 = V_119 ;
}
static void F_69 ( struct V_3 * V_4 ,
struct V_13 * V_5 )
{
V_5 -> V_89 = 1ull << 59 ;
V_5 -> V_83 . V_121 = F_66 ;
F_66 ( & V_5 -> V_83 , true ) ;
}
static void F_70 ( struct V_3 * V_4 ,
struct V_13 * V_5 )
{
struct V_107 * V_108 = NULL ;
void * V_111 ;
const T_5 * V_109 ;
struct V_91 * V_92 ;
unsigned int V_122 , V_37 ;
T_6 V_26 ;
if ( F_6 ( V_5 -> V_76 >= 0 ) )
return;
V_5 -> V_76 = 0 ;
V_37 = ( 1 << F_71 ( V_4 -> V_6 . V_123 ) ) ;
V_122 = ( V_37 / 0x1000 ) * 8 ;
F_30 ( V_5 , L_22 ,
V_37 ) ;
V_108 = F_55 ( V_4 -> V_17 -> V_112 , V_113 ,
F_56 ( V_122 ) ) ;
if ( ! V_108 ) {
F_15 ( V_5 , L_23 ) ;
goto V_114;
}
V_111 = F_57 ( V_108 ) ;
memset ( V_111 , 0 , V_122 ) ;
V_26 = F_58 ( V_4 -> V_47 , V_5 -> V_11 ,
V_5 -> V_11 << 1 , 1 , F_46 ( V_111 ) ,
V_122 , 0x1000 ) ;
if ( V_26 ) {
F_15 ( V_5 , L_24
L_16 , V_26 ) ;
goto V_114;
}
V_92 = & V_5 -> V_83 ;
F_59 ( V_92 , V_111 , V_122 , 0 ) ;
V_109 = F_60 ( V_4 -> V_17 -> V_115 , L_17 , NULL ) ;
if ( V_109 ) {
V_5 -> V_97 = F_61 ( V_109 ) ;
V_92 -> V_98 = ( unsigned long ) F_62 ( V_5 -> V_97 ,
8 ) ;
V_92 -> V_101 |= ( V_116 | V_117 ) ;
}
F_63 ( V_92 , V_4 -> V_17 -> V_112 ) ;
F_64 ( V_92 , V_4 -> V_17 -> V_118 , V_5 -> V_11 ) ;
if ( V_5 -> V_12 )
F_44 ( & V_5 -> V_12 -> V_15 , V_92 ) ;
else
F_43 ( V_5 , V_5 -> V_29 ) ;
F_69 ( V_4 , V_5 ) ;
return;
V_114:
if ( V_5 -> V_76 >= 0 )
V_5 -> V_76 = - 1 ;
if ( V_108 )
F_65 ( V_108 , F_56 ( V_122 ) ) ;
}
static void F_72 ( struct V_3 * V_4 )
{
struct V_16 * V_17 = V_4 -> V_17 ;
unsigned int V_124 , V_125 , V_106 , V_126 , V_105 ;
struct V_13 * V_5 ;
if ( V_4 -> V_6 . V_79 > V_4 -> V_6 . V_127 )
V_124 = 0 ;
else
V_124 = V_4 -> V_6 . V_127 -
V_4 -> V_6 . V_79 ;
F_73 ( L_25 ,
V_17 -> V_118 , V_4 -> V_6 . V_127 ) ;
F_73 ( L_26 ,
V_4 -> V_6 . V_79 , V_4 -> V_6 . V_58 ) ;
V_125 = V_4 -> V_6 . V_127 ;
V_126 = V_4 -> V_6 . V_58 ;
V_105 = 0 ;
F_22 (pe, &phb->ioda.pe_dma_list, dma_link) {
if ( ! V_5 -> V_58 )
continue;
if ( ! V_125 ) {
F_17 ( V_5 , L_27 ) ;
continue;
}
V_106 = 1 ;
if ( V_124 ) {
V_106 += ( ( V_5 -> V_58 * V_124 ) + ( V_126 / 2 ) ) / V_126 ;
if ( V_106 > V_125 )
V_106 = V_125 ;
}
if ( V_4 -> type == V_53 ) {
F_30 ( V_5 , L_28 ,
V_5 -> V_58 , V_106 ) ;
F_53 ( V_4 , V_5 , V_105 , V_106 ) ;
} else {
F_30 ( V_5 , L_29 ) ;
V_106 = 0 ;
F_70 ( V_4 , V_5 ) ;
}
V_125 -= V_106 ;
V_105 += V_106 ;
}
}
static void F_74 ( struct V_128 * V_129 )
{
unsigned int V_130 = ( unsigned int ) F_75 ( V_129 ) ;
struct V_131 * V_132 = F_76 ( V_129 ) ;
struct V_3 * V_4 = F_52 ( V_132 , struct V_3 ,
V_6 . V_131 ) ;
T_6 V_26 ;
V_26 = F_77 ( V_4 -> V_47 , V_130 ) ;
F_78 ( V_26 ) ;
F_79 ( V_129 ) ;
}
static int F_80 ( struct V_3 * V_4 , struct V_14 * V_15 ,
unsigned int V_133 , unsigned int V_134 ,
unsigned int V_135 , struct V_136 * V_137 )
{
struct V_13 * V_5 = F_8 ( V_15 ) ;
struct V_20 * V_21 = F_10 ( V_15 ) ;
struct V_128 * V_138 ;
struct V_131 * V_139 ;
unsigned int V_140 = V_133 - V_4 -> V_141 ;
T_9 V_142 ;
int V_26 ;
if ( V_5 == NULL )
return - V_49 ;
if ( V_5 -> V_54 < 0 )
return - V_49 ;
if ( V_21 && V_21 -> V_143 )
V_135 = 0 ;
V_26 = F_81 ( V_4 -> V_47 , V_5 -> V_11 , V_140 ) ;
if ( V_26 ) {
F_26 ( L_30 ,
F_13 ( V_15 ) , V_26 , V_140 ) ;
return - V_144 ;
}
if ( V_135 ) {
T_5 V_145 ;
V_26 = F_82 ( V_4 -> V_47 , V_5 -> V_54 , V_140 , 1 ,
& V_145 , & V_142 ) ;
if ( V_26 ) {
F_26 ( L_31 ,
F_13 ( V_15 ) , V_26 ) ;
return - V_144 ;
}
V_137 -> V_146 = F_83 ( V_145 ) >> 32 ;
V_137 -> V_147 = F_83 ( V_145 ) & 0xfffffffful ;
} else {
T_9 V_148 ;
V_26 = F_84 ( V_4 -> V_47 , V_5 -> V_54 , V_140 , 1 ,
& V_148 , & V_142 ) ;
if ( V_26 ) {
F_26 ( L_32 ,
F_13 ( V_15 ) , V_26 ) ;
return - V_144 ;
}
V_137 -> V_146 = 0 ;
V_137 -> V_147 = F_85 ( V_148 ) ;
}
V_137 -> V_142 = F_85 ( V_142 ) ;
if ( V_4 -> type == V_56 ) {
if ( ! V_4 -> V_6 . V_149 ) {
V_138 = F_86 ( V_134 ) ;
V_139 = F_76 ( V_138 ) ;
V_4 -> V_6 . V_149 = 1 ;
V_4 -> V_6 . V_131 = * V_139 ;
V_4 -> V_6 . V_131 . V_150 = F_74 ;
}
F_87 ( V_134 , & V_4 -> V_6 . V_131 ) ;
}
F_88 ( L_33
L_34 ,
F_13 ( V_15 ) , V_135 ? L_35 : L_36 , V_133 , V_140 ,
V_137 -> V_146 , V_137 -> V_147 , V_142 , V_5 -> V_11 ) ;
return 0 ;
}
static void F_89 ( struct V_3 * V_4 )
{
unsigned int V_30 ;
const T_9 * V_151 = F_60 ( V_4 -> V_17 -> V_115 ,
L_37 , NULL ) ;
if ( ! V_151 ) {
V_151 = F_60 ( V_4 -> V_17 -> V_115 , L_38 , NULL ) ;
}
if ( ! V_151 )
return;
V_4 -> V_141 = F_90 ( V_151 ) ;
V_30 = F_90 ( V_151 + 1 ) ;
if ( F_91 ( & V_4 -> V_152 , V_30 , V_4 -> V_17 -> V_115 ) ) {
F_12 ( L_39 ,
V_4 -> V_17 -> V_118 ) ;
return;
}
V_4 -> V_153 = F_80 ;
V_4 -> V_154 = 1 ;
F_73 ( L_40 ,
V_30 , V_4 -> V_141 ) ;
}
static void F_89 ( struct V_3 * V_4 ) { }
static void F_92 ( struct V_16 * V_17 ,
struct V_13 * V_5 )
{
struct V_3 * V_4 = V_17 -> V_19 ;
struct V_155 V_156 ;
struct V_157 * V_158 ;
int V_110 , V_159 ;
int V_26 ;
F_93 ( ! ( V_5 -> V_34 & ( V_75 | V_35 ) ) ) ;
F_94 (pe->pbus, res, i) {
if ( ! V_158 || ! V_158 -> V_34 ||
V_158 -> V_38 > V_158 -> V_37 )
continue;
if ( V_158 -> V_34 & V_160 ) {
V_156 . V_38 = V_158 -> V_38 - V_4 -> V_6 . V_161 ;
V_156 . V_37 = V_158 -> V_37 - V_4 -> V_6 . V_161 ;
V_159 = V_156 . V_38 / V_4 -> V_6 . V_162 ;
while ( V_159 < V_4 -> V_6 . V_8 &&
V_156 . V_38 <= V_156 . V_37 ) {
V_4 -> V_6 . V_163 [ V_159 ] = V_5 -> V_11 ;
V_26 = F_95 ( V_4 -> V_47 ,
V_5 -> V_11 , V_164 , 0 , V_159 ) ;
if ( V_26 != V_165 ) {
F_12 ( L_41
L_42 ,
V_73 , V_26 , V_159 , V_5 -> V_11 ) ;
break;
}
V_156 . V_38 += V_4 -> V_6 . V_162 ;
V_159 ++ ;
}
} else if ( V_158 -> V_34 & V_166 ) {
V_156 . V_38 = V_158 -> V_38 -
V_17 -> V_167 [ 0 ] -
V_4 -> V_6 . V_123 ;
V_156 . V_37 = V_158 -> V_37 -
V_17 -> V_167 [ 0 ] -
V_4 -> V_6 . V_123 ;
V_159 = V_156 . V_38 / V_4 -> V_6 . V_168 ;
while ( V_159 < V_4 -> V_6 . V_8 &&
V_156 . V_38 <= V_156 . V_37 ) {
V_4 -> V_6 . V_169 [ V_159 ] = V_5 -> V_11 ;
V_26 = F_95 ( V_4 -> V_47 ,
V_5 -> V_11 , V_170 , 0 , V_159 ) ;
if ( V_26 != V_165 ) {
F_12 ( L_43
L_44 ,
V_73 , V_26 , V_159 , V_5 -> V_11 ) ;
break;
}
V_156 . V_38 += V_4 -> V_6 . V_168 ;
V_159 ++ ;
}
}
}
}
static void F_96 ( void )
{
struct V_16 * V_81 , * V_17 ;
struct V_3 * V_4 ;
struct V_13 * V_5 ;
F_34 (hose, tmp, &hose_list, list_node) {
V_4 = V_17 -> V_19 ;
F_22 (pe, &phb->ioda.pe_list, list) {
F_92 ( V_17 , V_5 ) ;
}
}
}
static void F_97 ( void )
{
struct V_16 * V_17 , * V_81 ;
struct V_3 * V_4 ;
F_34 (hose, tmp, &hose_list, list_node) {
F_72 ( V_17 -> V_19 ) ;
V_4 = V_17 -> V_19 ;
V_4 -> V_171 = 1 ;
}
}
static void F_98 ( void )
{
#ifdef F_99
struct V_16 * V_17 , * V_81 ;
struct V_3 * V_4 ;
char V_172 [ 16 ] ;
F_34 (hose, tmp, &hose_list, list_node) {
V_4 = V_17 -> V_19 ;
sprintf ( V_172 , L_45 , V_17 -> V_118 ) ;
V_4 -> V_173 = F_100 ( V_172 , V_174 ) ;
if ( ! V_4 -> V_173 )
F_28 ( L_46 ,
V_73 , V_17 -> V_118 ) ;
}
#endif
}
static void F_101 ( void )
{
F_33 () ;
F_96 () ;
F_97 () ;
F_98 () ;
#ifdef F_102
F_103 ( V_175 ) ;
F_104 () ;
F_105 () ;
#endif
}
static T_10 F_106 ( struct V_68 * V_18 ,
unsigned long type )
{
struct V_14 * V_176 ;
struct V_16 * V_17 = F_9 ( V_18 ) ;
struct V_3 * V_4 = V_17 -> V_19 ;
int V_177 = 0 ;
V_176 = V_18 -> V_33 ;
while ( V_176 ) {
if ( F_32 ( V_176 ) == V_80 ) {
V_177 ++ ;
if ( V_177 >= 2 )
return 1 ;
}
V_176 = V_176 -> V_18 -> V_33 ;
}
if ( type & V_166 )
return V_4 -> V_6 . V_168 ;
return V_4 -> V_6 . V_162 ;
}
static int F_107 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_9 ( V_15 -> V_18 ) ;
struct V_3 * V_4 = V_17 -> V_19 ;
struct V_20 * V_21 ;
if ( ! V_4 -> V_171 )
return 0 ;
V_21 = F_10 ( V_15 ) ;
if ( ! V_21 || V_21 -> V_11 == V_9 )
return - V_178 ;
return 0 ;
}
static T_11 F_108 ( struct V_3 * V_4 , struct V_68 * V_18 ,
T_11 V_179 )
{
return V_4 -> V_6 . V_52 [ ( V_18 -> V_74 << 8 ) | V_179 ] ;
}
static void F_109 ( struct V_3 * V_4 )
{
F_110 ( V_4 -> V_47 , V_180 ,
V_181 ) ;
}
void T_12 F_111 ( struct V_182 * V_183 ,
T_1 V_184 , int V_185 )
{
struct V_16 * V_17 ;
struct V_3 * V_4 ;
unsigned long V_186 , V_187 , V_188 , V_189 = 0 ;
const T_5 * V_190 ;
const T_9 * V_191 ;
int V_192 ;
T_1 V_193 ;
void * V_194 ;
long V_26 ;
F_73 ( L_47 , V_185 , V_183 -> V_195 ) ;
V_190 = F_60 ( V_183 , L_48 , NULL ) ;
if ( ! V_190 ) {
F_12 ( L_49 ) ;
return;
}
V_193 = F_61 ( V_190 ) ;
F_112 ( L_50 , V_193 ) ;
V_4 = F_113 ( sizeof( struct V_3 ) ) ;
if ( ! V_4 ) {
F_12 ( L_51 ) ;
return;
}
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 -> V_17 = V_17 = F_114 ( V_183 ) ;
if ( ! V_4 -> V_17 ) {
F_12 ( L_52 ,
V_183 -> V_195 ) ;
F_115 ( ( unsigned long ) V_4 , sizeof( struct V_3 ) ) ;
return;
}
F_116 ( & V_4 -> V_196 ) ;
V_191 = F_60 ( V_183 , L_53 , & V_192 ) ;
if ( V_191 && V_192 == 8 ) {
V_17 -> V_197 = F_85 ( V_191 [ 0 ] ) ;
V_17 -> V_198 = F_85 ( V_191 [ 1 ] ) ;
} else {
F_26 ( L_54 , V_183 -> V_195 ) ;
V_17 -> V_197 = 0 ;
V_17 -> V_198 = 0xff ;
}
V_17 -> V_19 = V_4 ;
V_4 -> V_184 = V_184 ;
V_4 -> V_47 = V_193 ;
V_4 -> type = V_185 ;
if ( F_117 ( V_183 , L_55 ) )
V_4 -> V_199 = V_200 ;
else if ( F_117 ( V_183 , L_56 ) )
V_4 -> V_199 = V_201 ;
else
V_4 -> V_199 = V_202 ;
F_118 ( V_17 , V_183 , ! V_17 -> V_118 ) ;
V_4 -> V_203 = F_119 ( V_183 , 0 ) ;
if ( V_4 -> V_203 == NULL )
F_12 ( L_57 ) ;
V_4 -> V_6 . V_8 = 1 ;
V_191 = F_60 ( V_183 , L_58 , NULL ) ;
if ( V_191 )
V_4 -> V_6 . V_8 = F_90 ( V_191 ) ;
V_191 = F_60 ( V_183 , L_59 , NULL ) ;
if ( V_191 )
V_4 -> V_6 . V_204 = F_90 ( V_191 ) ;
V_4 -> V_6 . V_205 = F_120 ( & V_17 -> V_206 [ 0 ] ) ;
V_4 -> V_6 . V_205 += 0x10000 ;
V_4 -> V_6 . V_168 = V_4 -> V_6 . V_205 / V_4 -> V_6 . V_8 ;
V_4 -> V_6 . V_123 = V_17 -> V_206 [ 0 ] . V_38 - V_17 -> V_167 [ 0 ] ;
V_4 -> V_6 . V_207 = V_17 -> V_208 ;
V_4 -> V_6 . V_162 = V_4 -> V_6 . V_207 / V_4 -> V_6 . V_8 ;
V_4 -> V_6 . V_161 = 0 ;
V_186 = F_121 ( V_4 -> V_6 . V_8 / 8 , sizeof( unsigned long ) ) ;
V_187 = V_186 ;
V_186 += V_4 -> V_6 . V_8 * sizeof( V_4 -> V_6 . V_169 [ 0 ] ) ;
if ( V_4 -> type == V_53 ) {
V_189 = V_186 ;
V_186 += V_4 -> V_6 . V_8 * sizeof( V_4 -> V_6 . V_163 [ 0 ] ) ;
}
V_188 = V_186 ;
V_186 += V_4 -> V_6 . V_8 * sizeof( struct V_13 ) ;
V_194 = F_113 ( V_186 ) ;
memset ( V_194 , 0 , V_186 ) ;
V_4 -> V_6 . V_7 = V_194 ;
V_4 -> V_6 . V_169 = V_194 + V_187 ;
if ( V_4 -> type == V_53 )
V_4 -> V_6 . V_163 = V_194 + V_189 ;
V_4 -> V_6 . V_10 = V_194 + V_188 ;
F_122 ( V_4 -> V_6 . V_204 , V_4 -> V_6 . V_7 ) ;
F_123 ( & V_4 -> V_6 . V_60 ) ;
F_123 ( & V_4 -> V_6 . V_78 ) ;
V_4 -> V_6 . V_127 = V_4 -> V_6 . V_123 >> 28 ;
V_17 -> V_206 [ 1 ] . V_34 = 0 ;
V_17 -> V_206 [ 1 ] . V_38 = 0 ;
V_17 -> V_206 [ 1 ] . V_37 = 0 ;
V_17 -> V_206 [ 2 ] . V_34 = 0 ;
V_17 -> V_206 [ 2 ] . V_38 = 0 ;
V_17 -> V_206 [ 2 ] . V_37 = 0 ;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
F_73 ( L_60
L_61 ,
V_4 -> V_6 . V_8 ,
V_4 -> V_6 . V_204 ,
V_4 -> V_6 . V_205 , V_4 -> V_6 . V_168 ,
V_4 -> V_6 . V_207 , V_4 -> V_6 . V_162 ) ;
V_4 -> V_17 -> V_209 = & V_210 ;
#ifdef F_102
V_4 -> V_211 = & V_212 ;
#endif
V_4 -> V_213 = F_108 ;
V_4 -> V_214 = F_35 ;
V_4 -> V_215 = F_38 ;
V_4 -> V_216 = F_109 ;
F_89 ( V_4 ) ;
V_217 . V_218 = F_101 ;
V_217 . V_219 = F_107 ;
V_217 . V_220 = F_106 ;
V_217 . V_221 = V_222 ;
F_124 ( V_223 ) ;
V_26 = F_110 ( V_193 , V_180 , V_181 ) ;
if ( V_26 )
F_28 ( L_62 , V_26 ) ;
if ( F_125 () ) {
F_73 ( L_63 ) ;
F_126 ( V_17 , V_224 ) ;
F_126 ( V_17 , V_225 ) ;
}
}
void T_12 F_127 ( struct V_182 * V_183 )
{
F_111 ( V_183 , 0 , V_56 ) ;
}
void T_12 F_128 ( struct V_182 * V_183 )
{
struct V_182 * V_226 ;
const T_5 * V_190 ;
T_1 V_184 ;
F_73 ( L_64 , V_183 -> V_195 ) ;
V_190 = F_60 ( V_183 , L_65 , NULL ) ;
if ( ! V_190 ) {
F_12 ( L_66 ) ;
return;
}
V_184 = F_61 ( V_190 ) ;
F_88 ( L_67 , V_184 ) ;
F_129 (np, phbn) {
if ( F_117 ( V_226 , L_68 ) )
F_111 ( V_226 , V_184 , V_53 ) ;
}
}
