static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
do {
V_3 = F_2 ( V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 , 0 ) ;
if ( V_3 >= V_2 -> V_4 . V_6 )
return V_7 ;
} while( F_3 ( V_3 , V_2 -> V_4 . V_5 ) );
V_2 -> V_4 . V_8 [ V_3 ] . V_2 = V_2 ;
V_2 -> V_4 . V_8 [ V_3 ] . V_9 = V_3 ;
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 )
{
F_5 ( V_2 -> V_4 . V_8 [ V_3 ] . V_10 ) ;
memset ( & V_2 -> V_4 . V_8 [ V_3 ] , 0 , sizeof( struct V_11 ) ) ;
F_6 ( V_3 , V_2 -> V_4 . V_5 ) ;
}
static struct V_11 * F_7 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_8 ( V_13 -> V_16 ) ;
struct V_1 * V_2 = V_15 -> V_17 ;
struct V_18 * V_19 = F_9 ( V_13 ) ;
if ( ! V_19 )
return NULL ;
if ( V_19 -> V_9 == V_7 )
return NULL ;
return & V_2 -> V_4 . V_8 [ V_19 -> V_9 ] ;
}
static int F_10 ( struct V_1 * V_2 , struct V_11 * V_3 )
{
struct V_12 * V_20 ;
T_1 V_21 , V_22 , V_23 ;
long V_24 , V_25 , V_26 ;
if ( V_3 -> V_27 ) {
int V_28 ;
V_22 = V_29 ;
V_23 = V_30 ;
V_20 = V_3 -> V_27 -> V_31 ;
if ( V_3 -> V_32 & V_33 )
V_28 = V_3 -> V_27 -> V_34 . V_35 - V_3 -> V_27 -> V_34 . V_36 + 1 ;
else
V_28 = 1 ;
switch( V_28 ) {
case 1 : V_21 = V_37 ; break;
case 2 : V_21 = V_38 ; break;
case 4 : V_21 = V_39 ; break;
case 8 : V_21 = V_40 ; break;
case 16 : V_21 = V_41 ; break;
case 32 : V_21 = V_42 ; break;
default:
F_11 ( L_1
L_2 ,
F_12 ( V_3 -> V_27 -> V_31 ) , V_28 ) ;
V_21 = V_37 ;
}
V_25 = V_3 -> V_26 + ( V_28 << 8 ) ;
} else {
V_20 = V_3 -> V_10 -> V_16 -> V_31 ;
V_21 = V_37 ;
V_22 = V_43 ;
V_23 = V_44 ;
V_25 = V_3 -> V_26 + 1 ;
}
V_24 = F_13 ( V_2 -> V_45 , V_3 -> V_9 , V_3 -> V_26 ,
V_21 , V_22 , V_23 , V_46 ) ;
if ( V_24 ) {
F_14 ( V_3 , L_3 , V_24 ) ;
return - V_47 ;
}
F_15 ( V_2 -> V_45 , V_3 -> V_9 ,
V_48 ) ;
while ( V_20 ) {
struct V_18 * V_19 = F_9 ( V_20 ) ;
if ( V_19 && V_19 -> V_9 != V_7 ) {
V_24 = F_16 ( V_2 -> V_45 , V_19 -> V_9 ,
V_3 -> V_9 , V_49 ) ;
}
V_20 = V_20 -> V_16 -> V_31 ;
}
for ( V_26 = V_3 -> V_26 ; V_26 < V_25 ; V_26 ++ )
V_2 -> V_4 . V_50 [ V_26 ] = V_3 -> V_9 ;
if ( V_2 -> type == V_51 ) {
V_3 -> V_52 = V_3 -> V_9 ;
V_24 = F_17 ( V_2 -> V_45 , V_3 -> V_52 ,
V_3 -> V_9 ) ;
if ( V_24 ) {
F_14 ( V_3 , L_4 ,
V_24 , V_3 -> V_52 ) ;
V_3 -> V_52 = - 1 ;
} else {
V_24 = F_18 ( V_2 -> V_45 ,
V_3 -> V_52 , V_53 ) ;
if ( V_24 ) {
F_14 ( V_3 , L_5 ,
V_24 , V_3 -> V_52 ) ;
V_3 -> V_52 = - 1 ;
}
}
} else if ( V_2 -> type == V_54 )
V_3 -> V_52 = 0 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_11 * V_3 )
{
struct V_11 * V_55 ;
F_20 (lpe, &phb->ioda.pe_dma_list, dma_link) {
if ( V_55 -> V_56 < V_3 -> V_56 ) {
F_21 ( & V_3 -> V_57 , & V_55 -> V_57 ) ;
return;
}
}
F_21 ( & V_3 -> V_57 , & V_2 -> V_4 . V_58 ) ;
}
static unsigned int F_22 ( struct V_12 * V_13 )
{
if ( V_13 -> V_59 != V_60 )
return 0 ;
if ( V_13 -> V_61 == V_62 ||
V_13 -> V_61 == V_63 ||
V_13 -> V_61 == V_64 )
return 3 ;
if ( ( V_13 -> V_61 >> 8 ) == V_65 )
return 15 ;
return 10 ;
}
static void F_23 ( struct V_66 * V_16 , struct V_11 * V_3 )
{
struct V_12 * V_13 ;
F_20 (dev, &bus->devices, bus_list) {
struct V_18 * V_19 = F_9 ( V_13 ) ;
if ( V_19 == NULL ) {
F_24 ( L_6 ,
F_12 ( V_13 ) ) ;
continue;
}
F_25 ( V_13 ) ;
V_19 -> V_67 = V_13 ;
V_19 -> V_9 = V_3 -> V_9 ;
V_3 -> V_56 += F_22 ( V_13 ) ;
if ( ( V_3 -> V_32 & V_33 ) && V_13 -> V_68 )
F_23 ( V_13 -> V_68 , V_3 ) ;
}
}
static void F_26 ( struct V_66 * V_16 , int V_69 )
{
struct V_14 * V_15 = F_8 ( V_16 ) ;
struct V_1 * V_2 = V_15 -> V_17 ;
struct V_11 * V_3 ;
int V_70 ;
V_70 = F_1 ( V_2 ) ;
if ( V_70 == V_7 ) {
F_27 ( L_7 ,
V_71 , F_28 ( V_16 ) , V_16 -> V_72 ) ;
return;
}
V_3 = & V_2 -> V_4 . V_8 [ V_70 ] ;
V_3 -> V_32 = ( V_69 ? V_33 : V_73 ) ;
V_3 -> V_27 = V_16 ;
V_3 -> V_10 = NULL ;
V_3 -> V_74 = - 1 ;
V_3 -> V_52 = - 1 ;
V_3 -> V_26 = V_16 -> V_34 . V_36 << 8 ;
V_3 -> V_56 = 0 ;
if ( V_69 )
F_29 ( V_3 , L_8 ,
V_16 -> V_34 . V_36 , V_16 -> V_34 . V_35 , V_70 ) ;
else
F_29 ( V_3 , L_9 ,
V_16 -> V_34 . V_36 , V_70 ) ;
if ( F_10 ( V_2 , V_3 ) ) {
if ( V_70 )
F_4 ( V_2 , V_70 ) ;
V_3 -> V_27 = NULL ;
return;
}
F_23 ( V_16 , V_3 ) ;
F_21 ( & V_3 -> V_75 , & V_2 -> V_4 . V_76 ) ;
if ( V_3 -> V_56 != 0 ) {
V_2 -> V_4 . V_56 += V_3 -> V_56 ;
V_2 -> V_4 . V_77 ++ ;
}
F_19 ( V_2 , V_3 ) ;
}
static void F_30 ( struct V_66 * V_16 )
{
struct V_12 * V_13 ;
F_26 ( V_16 , 0 ) ;
F_20 (dev, &bus->devices, bus_list) {
if ( V_13 -> V_68 ) {
if ( F_31 ( V_13 ) == V_78 )
F_26 ( V_13 -> V_68 , 1 ) ;
else
F_30 ( V_13 -> V_68 ) ;
}
}
}
static void F_32 ( void )
{
struct V_14 * V_15 , * V_79 ;
F_33 (hose, tmp, &hose_list, list_node) {
F_30 ( V_15 -> V_16 ) ;
}
}
static void F_34 ( struct V_1 * V_2 , struct V_12 * V_10 )
{
struct V_18 * V_19 = F_9 ( V_10 ) ;
struct V_11 * V_3 ;
if ( ! V_19 || V_19 -> V_9 == V_7 )
return;
V_3 = & V_2 -> V_4 . V_8 [ V_19 -> V_9 ] ;
F_35 ( & V_10 -> V_13 , & V_3 -> V_80 ) ;
}
static void F_36 ( struct V_81 * V_82 ,
T_2 * V_83 , T_2 * V_84 )
{
T_2 T_3 * V_85 = ( T_2 T_3 * ) V_82 -> V_86 ;
unsigned long V_36 , V_35 , V_87 ;
V_36 = F_37 ( V_83 ) ;
V_35 = F_37 ( V_84 ) ;
if ( V_82 -> V_88 ) {
V_36 <<= 12 ;
V_35 <<= 12 ;
V_87 = 128 << 12 ;
V_36 |= V_82 -> V_88 ;
V_35 |= V_82 -> V_88 ;
} else if ( V_82 -> V_89 & V_90 ) {
V_36 |= ( 1ull << 63 ) ;
V_35 |= ( 1ull << 63 ) ;
V_87 = 16 ;
} else {
V_87 = 128 ;
}
V_35 |= V_87 - 1 ;
F_38 () ;
while ( V_36 <= V_35 ) {
F_39 ( V_36 , V_85 ) ;
V_36 += V_87 ;
}
}
static void F_40 ( struct V_11 * V_3 ,
struct V_81 * V_82 ,
T_2 * V_83 , T_2 * V_84 )
{
unsigned long V_36 , V_35 , V_87 ;
T_2 T_3 * V_85 = ( T_2 T_3 * ) V_82 -> V_86 ;
V_36 = 0x2ul << 60 ;
V_36 |= ( V_3 -> V_9 & 0xFF ) ;
V_35 = V_36 ;
V_87 = V_82 -> V_91 + ( ( ( T_2 ) V_83 - V_82 -> V_92 ) / sizeof( T_2 ) ) ;
V_36 |= ( V_87 << 12 ) ;
V_87 = V_82 -> V_91 + ( ( ( T_2 ) V_84 - V_82 -> V_92 ) / sizeof( T_2 ) ) ;
V_35 |= ( V_87 << 12 ) ;
V_87 = ( 0x1ul << 12 ) ;
F_38 () ;
while ( V_36 <= V_35 ) {
F_39 ( V_36 , V_85 ) ;
V_36 += V_87 ;
}
}
void F_41 ( struct V_81 * V_82 ,
T_2 * V_83 , T_2 * V_84 )
{
struct V_11 * V_3 = F_42 ( V_82 , struct V_11 ,
V_80 ) ;
struct V_1 * V_2 = V_3 -> V_2 ;
if ( V_2 -> type == V_51 )
F_36 ( V_82 , V_83 , V_84 ) ;
else
F_40 ( V_3 , V_82 , V_83 , V_84 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_11 * V_3 , unsigned int V_93 ,
unsigned int V_94 )
{
struct V_95 * V_96 = NULL ;
const T_4 * V_97 ;
struct V_81 * V_82 ;
unsigned int V_98 ;
T_5 V_24 ;
void * V_99 ;
#define F_44 ((0x10000000 / 0x1000) * 8)
if ( F_5 ( V_3 -> V_74 >= 0 ) )
return;
V_3 -> V_74 = V_93 ;
F_29 ( V_3 , L_10 ,
( V_93 << 28 ) , ( ( V_93 + V_94 ) << 28 ) - 1 ) ;
V_96 = F_45 ( V_2 -> V_15 -> V_100 , V_101 ,
F_46 ( F_44 * V_94 ) ) ;
if ( ! V_96 ) {
F_14 ( V_3 , L_11 ) ;
goto V_102;
}
V_99 = F_47 ( V_96 ) ;
memset ( V_99 , 0 , F_44 * V_94 ) ;
for ( V_98 = 0 ; V_98 < V_94 ; V_98 ++ ) {
V_24 = F_48 ( V_2 -> V_45 ,
V_3 -> V_9 ,
V_93 + V_98 , 1 ,
F_37 ( V_99 ) + F_44 * V_98 ,
F_44 , 0x1000 ) ;
if ( V_24 ) {
F_14 ( V_3 , L_12
L_13 , V_24 ) ;
goto V_102;
}
}
V_82 = & V_3 -> V_80 ;
F_49 ( V_82 , V_99 , F_44 * V_94 ,
V_93 << 28 ) ;
V_97 = F_50 ( V_2 -> V_15 -> V_103 , L_14 , NULL ) ;
if ( V_97 ) {
V_82 -> V_88 = 0 ;
V_82 -> V_86 = ( unsigned long ) F_51 ( F_52 ( V_97 ) , 8 ) ;
V_82 -> V_89 = V_104 | V_105 |
V_90 ;
}
F_53 ( V_82 , V_2 -> V_15 -> V_100 ) ;
return;
V_102:
if ( V_3 -> V_74 >= 0 )
V_3 -> V_74 = - 1 ;
if ( V_96 )
F_54 ( V_96 , F_46 ( F_44 * V_94 ) ) ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_11 * V_3 )
{
struct V_95 * V_96 = NULL ;
void * V_99 ;
const T_4 * V_97 ;
struct V_81 * V_82 ;
unsigned int V_106 , V_35 ;
T_5 V_24 ;
if ( F_5 ( V_3 -> V_74 >= 0 ) )
return;
V_3 -> V_74 = 0 ;
V_35 = ( 1 << F_56 ( V_2 -> V_4 . V_107 ) ) ;
V_106 = ( V_35 / 0x1000 ) * 8 ;
F_29 ( V_3 , L_15 ,
V_35 ) ;
V_96 = F_45 ( V_2 -> V_15 -> V_100 , V_101 ,
F_46 ( V_106 ) ) ;
if ( ! V_96 ) {
F_14 ( V_3 , L_16 ) ;
goto V_102;
}
V_99 = F_47 ( V_96 ) ;
memset ( V_99 , 0 , V_106 ) ;
V_24 = F_48 ( V_2 -> V_45 , V_3 -> V_9 ,
V_3 -> V_9 << 1 , 1 , F_37 ( V_99 ) ,
V_106 , 0x1000 ) ;
if ( V_24 ) {
F_14 ( V_3 , L_17
L_13 , V_24 ) ;
goto V_102;
}
V_82 = & V_3 -> V_80 ;
F_49 ( V_82 , V_99 , V_106 , 0 ) ;
V_97 = F_50 ( V_2 -> V_15 -> V_103 , L_14 , NULL ) ;
if ( V_97 ) {
V_82 -> V_88 = 0 ;
V_82 -> V_86 = ( unsigned long ) F_51 ( F_52 ( V_97 ) , 8 ) ;
V_82 -> V_89 = V_104 | V_105 ;
}
F_53 ( V_82 , V_2 -> V_15 -> V_100 ) ;
return;
V_102:
if ( V_3 -> V_74 >= 0 )
V_3 -> V_74 = - 1 ;
if ( V_96 )
F_54 ( V_96 , F_46 ( V_106 ) ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned int V_108 , V_109 , V_94 , V_110 , V_93 ;
struct V_11 * V_3 ;
if ( V_2 -> V_4 . V_77 > V_2 -> V_4 . V_111 )
V_108 = 0 ;
else
V_108 = V_2 -> V_4 . V_111 -
V_2 -> V_4 . V_77 ;
F_58 ( L_18 ,
V_15 -> V_112 , V_2 -> V_4 . V_111 ) ;
F_58 ( L_19 ,
V_2 -> V_4 . V_77 , V_2 -> V_4 . V_56 ) ;
V_109 = V_2 -> V_4 . V_111 ;
V_110 = V_2 -> V_4 . V_56 ;
V_93 = 0 ;
F_20 (pe, &phb->ioda.pe_dma_list, dma_link) {
if ( ! V_3 -> V_56 )
continue;
if ( ! V_109 ) {
F_59 ( V_3 , L_20 ) ;
continue;
}
V_94 = 1 ;
if ( V_108 ) {
V_94 += ( ( V_3 -> V_56 * V_108 ) + ( V_110 / 2 ) ) / V_110 ;
if ( V_94 > V_109 )
V_94 = V_109 ;
}
if ( V_2 -> type == V_51 ) {
F_29 ( V_3 , L_21 ,
V_3 -> V_56 , V_94 ) ;
F_43 ( V_2 , V_3 , V_93 , V_94 ) ;
} else {
F_29 ( V_3 , L_22 ) ;
V_94 = 0 ;
F_55 ( V_2 , V_3 ) ;
}
V_109 -= V_94 ;
V_93 += V_94 ;
}
}
static void F_60 ( struct V_113 * V_114 )
{
unsigned int V_115 = ( unsigned int ) F_61 ( V_114 ) ;
struct V_116 * V_117 = F_62 ( V_114 ) ;
struct V_1 * V_2 = F_42 ( V_117 , struct V_1 ,
V_4 . V_116 ) ;
T_5 V_24 ;
V_24 = F_63 ( V_2 -> V_45 , V_115 ) ;
F_64 ( V_24 ) ;
F_65 ( V_114 ) ;
}
static int F_66 ( struct V_1 * V_2 , struct V_12 * V_13 ,
unsigned int V_118 , unsigned int V_119 ,
unsigned int V_120 , struct V_121 * V_122 )
{
struct V_11 * V_3 = F_7 ( V_13 ) ;
struct V_18 * V_19 = F_9 ( V_13 ) ;
struct V_113 * V_123 ;
struct V_116 * V_124 ;
unsigned int V_125 = V_118 - V_2 -> V_126 ;
T_6 V_127 ;
T_7 V_128 , V_129 ;
int V_24 ;
if ( V_3 == NULL )
return - V_47 ;
if ( V_3 -> V_52 < 0 )
return - V_47 ;
if ( V_19 && V_19 -> V_130 )
V_120 = 0 ;
V_24 = F_67 ( V_2 -> V_45 , V_3 -> V_9 , V_125 ) ;
if ( V_24 ) {
F_24 ( L_23 ,
F_12 ( V_13 ) , V_24 , V_125 ) ;
return - V_131 ;
}
if ( V_120 ) {
V_24 = F_68 ( V_2 -> V_45 , V_3 -> V_52 , V_125 , 1 ,
& V_127 , & V_129 ) ;
if ( V_24 ) {
F_24 ( L_24 ,
F_12 ( V_13 ) , V_24 ) ;
return - V_131 ;
}
V_122 -> V_132 = V_127 >> 32 ;
V_122 -> V_133 = V_127 & 0xfffffffful ;
} else {
V_24 = F_69 ( V_2 -> V_45 , V_3 -> V_52 , V_125 , 1 ,
& V_128 , & V_129 ) ;
if ( V_24 ) {
F_24 ( L_25 ,
F_12 ( V_13 ) , V_24 ) ;
return - V_131 ;
}
V_122 -> V_132 = 0 ;
V_122 -> V_133 = V_128 ;
}
V_122 -> V_129 = V_129 ;
if ( V_2 -> type == V_54 ) {
if ( ! V_2 -> V_4 . V_134 ) {
V_123 = F_70 ( V_119 ) ;
V_124 = F_62 ( V_123 ) ;
V_2 -> V_4 . V_134 = 1 ;
V_2 -> V_4 . V_116 = * V_124 ;
V_2 -> V_4 . V_116 . V_135 = F_60 ;
}
F_71 ( V_119 , & V_2 -> V_4 . V_116 ) ;
}
F_72 ( L_26
L_27 ,
F_12 ( V_13 ) , V_120 ? L_28 : L_29 , V_118 , V_125 ,
V_122 -> V_132 , V_122 -> V_133 , V_129 , V_3 -> V_9 ) ;
return 0 ;
}
static void F_73 ( struct V_1 * V_2 )
{
unsigned int V_28 ;
const T_8 * V_136 = F_50 ( V_2 -> V_15 -> V_103 ,
L_30 , NULL ) ;
if ( ! V_136 ) {
V_136 = F_50 ( V_2 -> V_15 -> V_103 , L_31 , NULL ) ;
}
if ( ! V_136 )
return;
V_2 -> V_126 = F_74 ( V_136 ) ;
V_28 = F_74 ( V_136 + 1 ) ;
if ( F_75 ( & V_2 -> V_137 , V_28 , V_2 -> V_15 -> V_103 ) ) {
F_11 ( L_32 ,
V_2 -> V_15 -> V_112 ) ;
return;
}
V_2 -> V_138 = F_66 ;
V_2 -> V_139 = 1 ;
F_58 ( L_33 ,
V_28 , V_2 -> V_126 ) ;
}
static void F_73 ( struct V_1 * V_2 ) { }
static void F_76 ( struct V_14 * V_15 ,
struct V_11 * V_3 )
{
struct V_1 * V_2 = V_15 -> V_17 ;
struct V_140 V_141 ;
struct V_142 * V_143 ;
int V_98 , V_144 ;
int V_24 ;
F_77 ( ! ( V_3 -> V_32 & ( V_73 | V_33 ) ) ) ;
F_78 (pe->pbus, res, i) {
if ( ! V_143 || ! V_143 -> V_32 ||
V_143 -> V_36 > V_143 -> V_35 )
continue;
if ( V_143 -> V_32 & V_145 ) {
V_141 . V_36 = V_143 -> V_36 - V_2 -> V_4 . V_146 ;
V_141 . V_35 = V_143 -> V_35 - V_2 -> V_4 . V_146 ;
V_144 = V_141 . V_36 / V_2 -> V_4 . V_147 ;
while ( V_144 < V_2 -> V_4 . V_6 &&
V_141 . V_36 <= V_141 . V_35 ) {
V_2 -> V_4 . V_148 [ V_144 ] = V_3 -> V_9 ;
V_24 = F_79 ( V_2 -> V_45 ,
V_3 -> V_9 , V_149 , 0 , V_144 ) ;
if ( V_24 != V_150 ) {
F_11 ( L_34
L_35 ,
V_71 , V_24 , V_144 , V_3 -> V_9 ) ;
break;
}
V_141 . V_36 += V_2 -> V_4 . V_147 ;
V_144 ++ ;
}
} else if ( V_143 -> V_32 & V_151 ) {
V_141 . V_36 = V_143 -> V_36 -
V_15 -> V_152 [ 0 ] -
V_2 -> V_4 . V_107 ;
V_141 . V_35 = V_143 -> V_35 -
V_15 -> V_152 [ 0 ] -
V_2 -> V_4 . V_107 ;
V_144 = V_141 . V_36 / V_2 -> V_4 . V_153 ;
while ( V_144 < V_2 -> V_4 . V_6 &&
V_141 . V_36 <= V_141 . V_35 ) {
V_2 -> V_4 . V_154 [ V_144 ] = V_3 -> V_9 ;
V_24 = F_79 ( V_2 -> V_45 ,
V_3 -> V_9 , V_155 , 0 , V_144 ) ;
if ( V_24 != V_150 ) {
F_11 ( L_36
L_37 ,
V_71 , V_24 , V_144 , V_3 -> V_9 ) ;
break;
}
V_141 . V_36 += V_2 -> V_4 . V_153 ;
V_144 ++ ;
}
}
}
}
static void F_80 ( void )
{
struct V_14 * V_79 , * V_15 ;
struct V_1 * V_2 ;
struct V_11 * V_3 ;
F_33 (hose, tmp, &hose_list, list_node) {
V_2 = V_15 -> V_17 ;
F_20 (pe, &phb->ioda.pe_list, list) {
F_76 ( V_15 , V_3 ) ;
}
}
}
static void F_81 ( void )
{
struct V_14 * V_15 , * V_79 ;
struct V_1 * V_2 ;
F_33 (hose, tmp, &hose_list, list_node) {
F_57 ( V_15 -> V_17 ) ;
V_2 = V_15 -> V_17 ;
V_2 -> V_156 = 1 ;
}
}
static void F_82 ( void )
{
F_32 () ;
F_80 () ;
F_81 () ;
}
static T_9 F_83 ( struct V_66 * V_16 ,
unsigned long type )
{
struct V_12 * V_157 ;
struct V_14 * V_15 = F_8 ( V_16 ) ;
struct V_1 * V_2 = V_15 -> V_17 ;
int V_158 = 0 ;
V_157 = V_16 -> V_31 ;
while ( V_157 ) {
if ( F_31 ( V_157 ) == V_78 ) {
V_158 ++ ;
if ( V_158 >= 2 )
return 1 ;
}
V_157 = V_157 -> V_16 -> V_31 ;
}
if ( type & V_151 )
return V_2 -> V_4 . V_153 ;
return V_2 -> V_4 . V_147 ;
}
static int F_84 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_8 ( V_13 -> V_16 ) ;
struct V_1 * V_2 = V_15 -> V_17 ;
struct V_18 * V_19 ;
if ( ! V_2 -> V_156 )
return 0 ;
V_19 = F_9 ( V_13 ) ;
if ( ! V_19 || V_19 -> V_9 == V_7 )
return - V_159 ;
return 0 ;
}
static T_10 F_85 ( struct V_1 * V_2 , struct V_66 * V_16 ,
T_10 V_160 )
{
return V_2 -> V_4 . V_50 [ ( V_16 -> V_72 << 8 ) | V_160 ] ;
}
static void F_86 ( struct V_1 * V_2 )
{
F_87 ( V_2 -> V_45 , V_161 ,
V_162 ) ;
}
void T_11 F_88 ( struct V_163 * V_164 , int V_165 )
{
struct V_14 * V_15 ;
static int V_166 = 1 ;
struct V_1 * V_2 ;
unsigned long V_167 , V_168 , V_169 , V_170 ;
const T_2 * V_171 ;
const T_10 * V_172 ;
T_2 V_173 ;
void * V_174 ;
long V_24 ;
F_58 ( L_38 , V_165 , V_164 -> V_175 ) ;
V_171 = F_50 ( V_164 , L_39 , NULL ) ;
if ( ! V_171 ) {
F_11 ( L_40 ) ;
return;
}
V_173 = F_52 ( V_171 ) ;
F_89 ( L_41 , V_173 ) ;
V_2 = F_90 ( sizeof( struct V_1 ) ) ;
if ( V_2 ) {
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_15 = V_15 = F_91 ( V_164 ) ;
}
if ( ! V_2 || ! V_2 -> V_15 ) {
F_11 ( L_42 ,
V_164 -> V_175 ) ;
return;
}
F_92 ( & V_2 -> V_176 ) ;
V_15 -> V_177 = 0 ;
V_15 -> V_178 = 0xff ;
V_15 -> V_17 = V_2 ;
V_2 -> V_45 = V_173 ;
V_2 -> type = V_165 ;
if ( F_93 ( V_164 , L_43 ) )
V_2 -> V_179 = V_180 ;
else if ( F_93 ( V_164 , L_44 ) )
V_2 -> V_179 = V_181 ;
else
V_2 -> V_179 = V_182 ;
F_94 ( V_2 -> V_15 , V_164 , V_166 ) ;
V_166 = 0 ;
V_2 -> V_183 = F_95 ( V_164 , 0 ) ;
if ( V_2 -> V_183 == NULL )
F_11 ( L_45 ) ;
V_172 = F_50 ( V_164 , L_46 , NULL ) ;
if ( ! V_172 )
V_2 -> V_4 . V_6 = 1 ;
else
V_2 -> V_4 . V_6 = * V_172 ;
V_2 -> V_4 . V_184 = F_96 ( & V_15 -> V_185 [ 0 ] ) ;
V_2 -> V_4 . V_184 += 0x10000 ;
V_2 -> V_4 . V_153 = V_2 -> V_4 . V_184 / V_2 -> V_4 . V_6 ;
V_2 -> V_4 . V_107 = V_15 -> V_185 [ 0 ] . V_36 - V_15 -> V_152 [ 0 ] ;
V_2 -> V_4 . V_186 = V_15 -> V_187 ;
V_2 -> V_4 . V_147 = V_2 -> V_4 . V_186 / V_2 -> V_4 . V_6 ;
V_2 -> V_4 . V_146 = 0 ;
V_167 = F_97 ( V_2 -> V_4 . V_6 / 8 , sizeof( unsigned long ) ) ;
V_168 = V_167 ;
V_167 += V_2 -> V_4 . V_6 * sizeof( V_2 -> V_4 . V_154 [ 0 ] ) ;
V_169 = V_167 ;
V_167 += V_2 -> V_4 . V_6 * sizeof( V_2 -> V_4 . V_148 [ 0 ] ) ;
V_170 = V_167 ;
V_167 += V_2 -> V_4 . V_6 * sizeof( struct V_11 ) ;
V_174 = F_90 ( V_167 ) ;
memset ( V_174 , 0 , V_167 ) ;
V_2 -> V_4 . V_5 = V_174 ;
V_2 -> V_4 . V_154 = V_174 + V_168 ;
V_2 -> V_4 . V_148 = V_174 + V_169 ;
V_2 -> V_4 . V_8 = V_174 + V_170 ;
F_98 ( 0 , V_2 -> V_4 . V_5 ) ;
F_99 ( & V_2 -> V_4 . V_58 ) ;
F_99 ( & V_2 -> V_4 . V_76 ) ;
V_2 -> V_4 . V_111 = V_2 -> V_4 . V_107 >> 28 ;
V_15 -> V_185 [ 1 ] . V_32 = 0 ;
V_15 -> V_185 [ 1 ] . V_36 = 0 ;
V_15 -> V_185 [ 1 ] . V_35 = 0 ;
V_15 -> V_185 [ 2 ] . V_32 = 0 ;
V_15 -> V_185 [ 2 ] . V_36 = 0 ;
V_15 -> V_185 [ 2 ] . V_35 = 0 ;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
F_58 ( L_47 ,
V_2 -> V_4 . V_6 ,
V_2 -> V_4 . V_184 , V_2 -> V_4 . V_153 ,
V_2 -> V_4 . V_186 , V_2 -> V_4 . V_147 ) ;
V_2 -> V_15 -> V_188 = & V_189 ;
V_2 -> V_190 = F_85 ;
V_2 -> V_191 = F_34 ;
V_2 -> V_192 = F_86 ;
F_73 ( V_2 ) ;
V_193 . V_194 = F_82 ;
V_193 . V_195 = F_84 ;
V_193 . V_196 = F_83 ;
F_100 ( V_197 ) ;
V_24 = F_87 ( V_173 , V_161 , V_162 ) ;
if ( V_24 )
F_27 ( L_48 , V_24 ) ;
if ( V_165 == V_51 )
F_13 ( V_173 , 0 , 0 , 7 , 1 , 1 , V_46 ) ;
}
void F_101 ( struct V_163 * V_164 )
{
F_88 ( V_164 , V_54 ) ;
}
void T_11 F_102 ( struct V_163 * V_164 )
{
struct V_163 * V_198 ;
const T_2 * V_171 ;
T_2 V_199 ;
F_58 ( L_49 , V_164 -> V_175 ) ;
V_171 = F_50 ( V_164 , L_50 , NULL ) ;
if ( ! V_171 ) {
F_11 ( L_51 ) ;
return;
}
V_199 = F_52 ( V_171 ) ;
F_72 ( L_52 , V_199 ) ;
F_103 (np, phbn) {
if ( F_93 ( V_198 , L_53 ) )
F_88 ( V_198 , V_51 ) ;
}
}
