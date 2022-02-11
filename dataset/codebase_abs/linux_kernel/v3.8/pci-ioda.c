static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_3 ) ;
if ( ! V_5 )
return NULL ;
return F_3 ( V_5 ) ;
}
static int F_4 ( struct V_6 * V_7 )
{
unsigned long V_8 ;
do {
V_8 = F_5 ( V_7 -> V_9 . V_10 ,
V_7 -> V_9 . V_11 , 0 ) ;
if ( V_8 >= V_7 -> V_9 . V_11 )
return V_12 ;
} while( F_6 ( V_8 , V_7 -> V_9 . V_10 ) );
V_7 -> V_9 . V_13 [ V_8 ] . V_14 = V_8 ;
return V_8 ;
}
static void F_7 ( struct V_6 * V_7 , int V_8 )
{
F_8 ( V_7 -> V_9 . V_13 [ V_8 ] . V_15 ) ;
memset ( & V_7 -> V_9 . V_13 [ V_8 ] , 0 , sizeof( struct V_16 ) ) ;
F_9 ( V_8 , V_7 -> V_9 . V_10 ) ;
}
static struct V_16 * F_10 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_11 ( V_3 -> V_19 ) ;
struct V_6 * V_7 = V_18 -> V_20 ;
struct V_1 * V_21 = F_1 ( V_3 ) ;
if ( ! V_21 )
return NULL ;
if ( V_21 -> V_14 == V_12 )
return NULL ;
return & V_7 -> V_9 . V_13 [ V_21 -> V_14 ] ;
}
static int F_12 ( struct V_6 * V_7 , struct V_16 * V_8 )
{
struct V_2 * V_22 ;
T_1 V_23 , V_24 , V_25 ;
long V_26 , V_27 , V_28 ;
if ( V_8 -> V_29 ) {
int V_30 ;
V_24 = V_31 ;
V_25 = V_32 ;
V_22 = V_8 -> V_29 -> V_33 ;
if ( V_8 -> V_34 & V_35 )
V_30 = V_8 -> V_29 -> V_36 . V_37 - V_8 -> V_29 -> V_36 . V_38 + 1 ;
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
F_13 ( L_1
L_2 ,
F_14 ( V_8 -> V_29 -> V_33 ) , V_30 ) ;
V_23 = V_39 ;
}
V_27 = V_8 -> V_28 + ( V_30 << 8 ) ;
} else {
V_22 = V_8 -> V_15 -> V_19 -> V_33 ;
V_23 = V_39 ;
V_24 = V_45 ;
V_25 = V_46 ;
V_27 = V_8 -> V_28 + 1 ;
}
V_26 = F_15 ( V_7 -> V_47 , V_8 -> V_14 , V_8 -> V_28 ,
V_23 , V_24 , V_25 , V_48 ) ;
if ( V_26 ) {
F_16 ( V_8 , L_3 , V_26 ) ;
return - V_49 ;
}
F_17 ( V_7 -> V_47 , V_8 -> V_14 ,
V_50 ) ;
while ( V_22 ) {
struct V_1 * V_21 = F_1 ( V_22 ) ;
if ( V_21 && V_21 -> V_14 != V_12 ) {
V_26 = F_18 ( V_7 -> V_47 , V_21 -> V_14 ,
V_8 -> V_14 , V_51 ) ;
}
V_22 = V_22 -> V_19 -> V_33 ;
}
for ( V_28 = V_8 -> V_28 ; V_28 < V_27 ; V_28 ++ )
V_7 -> V_9 . V_52 [ V_28 ] = V_8 -> V_14 ;
if ( V_7 -> type == V_53 ) {
V_8 -> V_54 = V_8 -> V_14 ;
V_26 = F_19 ( V_7 -> V_47 , V_8 -> V_54 ,
V_8 -> V_14 ) ;
if ( V_26 ) {
F_16 ( V_8 , L_4 ,
V_26 , V_8 -> V_54 ) ;
V_8 -> V_54 = - 1 ;
} else {
V_26 = F_20 ( V_7 -> V_47 ,
V_8 -> V_54 , V_55 ) ;
if ( V_26 ) {
F_16 ( V_8 , L_5 ,
V_26 , V_8 -> V_54 ) ;
V_8 -> V_54 = - 1 ;
}
}
} else if ( V_7 -> type == V_56 )
V_8 -> V_54 = 0 ;
return 0 ;
}
static void F_21 ( struct V_6 * V_7 ,
struct V_16 * V_8 )
{
struct V_16 * V_57 ;
F_22 (lpe, &phb->ioda.pe_dma_list, dma_link) {
if ( V_57 -> V_58 < V_8 -> V_58 ) {
F_23 ( & V_8 -> V_59 , & V_57 -> V_59 ) ;
return;
}
}
F_23 ( & V_8 -> V_59 , & V_7 -> V_9 . V_60 ) ;
}
static unsigned int F_24 ( struct V_2 * V_3 )
{
if ( V_3 -> V_61 != V_62 )
return 0 ;
if ( V_3 -> V_63 == V_64 ||
V_3 -> V_63 == V_65 ||
V_3 -> V_63 == V_66 )
return 3 ;
if ( ( V_3 -> V_63 >> 8 ) == V_67 )
return 15 ;
return 10 ;
}
static void F_25 ( struct V_68 * V_19 , struct V_16 * V_8 )
{
struct V_2 * V_3 ;
F_22 (dev, &bus->devices, bus_list) {
struct V_1 * V_21 = F_1 ( V_3 ) ;
if ( V_21 == NULL ) {
F_26 ( L_6 ,
F_14 ( V_3 ) ) ;
continue;
}
F_27 ( V_3 ) ;
V_21 -> V_69 = V_3 ;
V_21 -> V_14 = V_8 -> V_14 ;
V_8 -> V_58 += F_24 ( V_3 ) ;
if ( ( V_8 -> V_34 & V_35 ) && V_3 -> V_70 )
F_25 ( V_3 -> V_70 , V_8 ) ;
}
}
static void F_28 ( struct V_68 * V_19 , int V_71 )
{
struct V_17 * V_18 = F_11 ( V_19 ) ;
struct V_6 * V_7 = V_18 -> V_20 ;
struct V_16 * V_8 ;
int V_72 ;
V_72 = F_4 ( V_7 ) ;
if ( V_72 == V_12 ) {
F_29 ( L_7 ,
V_73 , F_30 ( V_19 ) , V_19 -> V_74 ) ;
return;
}
V_8 = & V_7 -> V_9 . V_13 [ V_72 ] ;
V_8 -> V_34 = ( V_71 ? V_35 : V_75 ) ;
V_8 -> V_29 = V_19 ;
V_8 -> V_15 = NULL ;
V_8 -> V_76 = - 1 ;
V_8 -> V_54 = - 1 ;
V_8 -> V_28 = V_19 -> V_36 . V_38 << 8 ;
V_8 -> V_58 = 0 ;
if ( V_71 )
F_31 ( V_8 , L_8 ,
V_19 -> V_36 . V_38 , V_19 -> V_36 . V_37 , V_72 ) ;
else
F_31 ( V_8 , L_9 ,
V_19 -> V_36 . V_38 , V_72 ) ;
if ( F_12 ( V_7 , V_8 ) ) {
if ( V_72 )
F_7 ( V_7 , V_72 ) ;
V_8 -> V_29 = NULL ;
return;
}
F_25 ( V_19 , V_8 ) ;
F_23 ( & V_8 -> V_77 , & V_7 -> V_9 . V_78 ) ;
if ( V_8 -> V_58 != 0 ) {
V_7 -> V_9 . V_58 += V_8 -> V_58 ;
V_7 -> V_9 . V_79 ++ ;
}
F_21 ( V_7 , V_8 ) ;
}
static void F_32 ( struct V_68 * V_19 )
{
struct V_2 * V_3 ;
F_28 ( V_19 , 0 ) ;
F_22 (dev, &bus->devices, bus_list) {
if ( V_3 -> V_70 ) {
if ( F_33 ( V_3 ) == V_80 )
F_28 ( V_3 -> V_70 , 1 ) ;
else
F_32 ( V_3 -> V_70 ) ;
}
}
}
static void F_34 ( void )
{
struct V_17 * V_18 , * V_81 ;
F_35 (hose, tmp, &hose_list, list_node) {
F_32 ( V_18 -> V_19 ) ;
}
}
static void F_36 ( struct V_6 * V_7 , struct V_2 * V_3 )
{
}
static void F_37 ( struct V_16 * V_8 , struct V_68 * V_19 )
{
struct V_2 * V_3 ;
F_22 (dev, &bus->devices, bus_list) {
F_38 ( & V_3 -> V_3 , & V_8 -> V_82 ) ;
if ( V_3 -> V_70 )
F_37 ( V_8 , V_3 -> V_70 ) ;
}
}
static void F_39 ( struct V_6 * V_7 ,
struct V_16 * V_8 , unsigned int V_83 ,
unsigned int V_84 )
{
struct V_85 * V_86 = NULL ;
const T_2 * V_87 ;
struct V_88 * V_89 ;
unsigned int V_90 ;
T_3 V_26 ;
void * V_91 ;
#define F_40 ((0x10000000 / 0x1000) * 8)
if ( F_8 ( V_8 -> V_76 >= 0 ) )
return;
V_8 -> V_76 = V_83 ;
F_31 ( V_8 , L_10 ,
( V_83 << 28 ) , ( ( V_83 + V_84 ) << 28 ) - 1 ) ;
V_86 = F_41 ( V_7 -> V_18 -> V_92 , V_93 ,
F_42 ( F_40 * V_84 ) ) ;
if ( ! V_86 ) {
F_16 ( V_8 , L_11 ) ;
goto V_94;
}
V_91 = F_43 ( V_86 ) ;
memset ( V_91 , 0 , F_40 * V_84 ) ;
for ( V_90 = 0 ; V_90 < V_84 ; V_90 ++ ) {
V_26 = F_44 ( V_7 -> V_47 ,
V_8 -> V_14 ,
V_83 + V_90 , 1 ,
F_45 ( V_91 ) + F_40 * V_90 ,
F_40 , 0x1000 ) ;
if ( V_26 ) {
F_16 ( V_8 , L_12
L_13 , V_26 ) ;
goto V_94;
}
}
V_89 = & V_8 -> V_82 ;
F_46 ( V_89 , V_91 , F_40 * V_84 ,
V_83 << 28 ) ;
V_87 = F_47 ( V_7 -> V_18 -> V_95 , L_14 , NULL ) ;
if ( V_87 ) {
V_89 -> V_96 = 0 ;
V_89 -> V_97 = ( unsigned long ) F_48 ( F_49 ( V_87 ) , 8 ) ;
V_89 -> V_98 = V_99 | V_100
| V_101 ;
}
F_50 ( V_89 , V_7 -> V_18 -> V_92 ) ;
if ( V_8 -> V_15 )
F_38 ( & V_8 -> V_15 -> V_3 , V_89 ) ;
else
F_37 ( V_8 , V_8 -> V_29 ) ;
return;
V_94:
if ( V_8 -> V_76 >= 0 )
V_8 -> V_76 = - 1 ;
if ( V_86 )
F_51 ( V_86 , F_42 ( F_40 * V_84 ) ) ;
}
static void F_52 ( struct V_6 * V_7 )
{
struct V_17 * V_18 = V_7 -> V_18 ;
unsigned int V_102 , V_103 , V_84 , V_104 , V_83 ;
struct V_16 * V_8 ;
if ( V_7 -> V_9 . V_79 > V_7 -> V_9 . V_105 )
V_102 = 0 ;
else
V_102 = V_7 -> V_9 . V_105 -
V_7 -> V_9 . V_79 ;
F_53 ( L_15 ,
V_18 -> V_106 , V_7 -> V_9 . V_105 ) ;
F_53 ( L_16 ,
V_7 -> V_9 . V_79 , V_7 -> V_9 . V_58 ) ;
V_103 = V_7 -> V_9 . V_105 ;
V_104 = V_7 -> V_9 . V_58 ;
V_83 = 0 ;
F_22 (pe, &phb->ioda.pe_dma_list, dma_link) {
if ( ! V_8 -> V_58 )
continue;
if ( ! V_103 ) {
F_54 ( V_8 , L_17 ) ;
continue;
}
V_84 = 1 ;
if ( V_102 ) {
V_84 += ( ( V_8 -> V_58 * V_102 ) + ( V_104 / 2 ) ) / V_104 ;
if ( V_84 > V_103 )
V_84 = V_103 ;
}
F_31 ( V_8 , L_18 ,
V_8 -> V_58 , V_84 ) ;
F_39 ( V_7 , V_8 , V_83 , V_84 ) ;
V_103 -= V_84 ;
V_83 += V_84 ;
}
}
static int F_55 ( struct V_6 * V_7 , struct V_2 * V_3 ,
unsigned int V_107 , unsigned int V_108 ,
struct V_109 * V_110 )
{
struct V_16 * V_8 = F_10 ( V_3 ) ;
unsigned int V_111 = V_107 - V_7 -> V_112 ;
T_4 V_113 ;
T_5 V_114 , V_115 ;
int V_26 ;
if ( V_8 == NULL )
return - V_49 ;
if ( V_8 -> V_54 < 0 )
return - V_49 ;
V_26 = F_56 ( V_7 -> V_47 , V_8 -> V_14 , V_111 ) ;
if ( V_26 ) {
F_26 ( L_19 ,
F_14 ( V_3 ) , V_26 , V_111 ) ;
return - V_116 ;
}
if ( V_108 ) {
V_26 = F_57 ( V_7 -> V_47 , V_8 -> V_54 , V_111 , 1 ,
& V_113 , & V_115 ) ;
if ( V_26 ) {
F_26 ( L_20 ,
F_14 ( V_3 ) , V_26 ) ;
return - V_116 ;
}
V_110 -> V_117 = V_113 >> 32 ;
V_110 -> V_118 = V_113 & 0xfffffffful ;
} else {
V_26 = F_58 ( V_7 -> V_47 , V_8 -> V_54 , V_111 , 1 ,
& V_114 , & V_115 ) ;
if ( V_26 ) {
F_26 ( L_21 ,
F_14 ( V_3 ) , V_26 ) ;
return - V_116 ;
}
V_110 -> V_117 = 0 ;
V_110 -> V_118 = V_114 ;
}
V_110 -> V_115 = V_115 ;
F_59 ( L_22
L_23 ,
F_14 ( V_3 ) , V_108 ? L_24 : L_25 , V_107 , V_111 ,
V_110 -> V_117 , V_110 -> V_118 , V_115 , V_8 -> V_14 ) ;
return 0 ;
}
static void F_60 ( struct V_6 * V_7 )
{
unsigned int V_119 ;
const T_6 * V_120 = F_47 ( V_7 -> V_18 -> V_95 ,
L_26 , NULL ) ;
if ( ! V_120 ) {
V_120 = F_47 ( V_7 -> V_18 -> V_95 , L_27 , NULL ) ;
}
if ( ! V_120 )
return;
V_7 -> V_112 = F_61 ( V_120 ) ;
V_7 -> V_121 = F_61 ( V_120 + 1 ) ;
V_119 = F_62 ( V_7 -> V_121 ) * sizeof( unsigned long ) ;
V_7 -> V_122 = F_63 ( V_119 , V_93 ) ;
if ( ! V_7 -> V_122 ) {
F_13 ( L_28 ,
V_7 -> V_18 -> V_106 ) ;
return;
}
V_7 -> V_123 = F_55 ;
V_7 -> V_124 = 1 ;
F_53 ( L_29 ,
V_7 -> V_121 , V_7 -> V_112 ) ;
}
static void F_60 ( struct V_6 * V_7 ) { }
static void F_64 ( struct V_17 * V_18 ,
struct V_16 * V_8 )
{
struct V_6 * V_7 = V_18 -> V_20 ;
struct V_125 V_126 ;
struct V_127 * V_128 ;
int V_90 , V_129 ;
int V_26 ;
F_65 ( ! ( V_8 -> V_34 & ( V_75 | V_35 ) ) ) ;
F_66 (pe->pbus, res, i) {
if ( ! V_128 || ! V_128 -> V_34 ||
V_128 -> V_38 > V_128 -> V_37 )
continue;
if ( V_128 -> V_34 & V_130 ) {
V_126 . V_38 = V_128 -> V_38 - V_7 -> V_9 . V_131 ;
V_126 . V_37 = V_128 -> V_37 - V_7 -> V_9 . V_131 ;
V_129 = V_126 . V_38 / V_7 -> V_9 . V_132 ;
while ( V_129 < V_7 -> V_9 . V_11 &&
V_126 . V_38 <= V_126 . V_37 ) {
V_7 -> V_9 . V_133 [ V_129 ] = V_8 -> V_14 ;
V_26 = F_67 ( V_7 -> V_47 ,
V_8 -> V_14 , V_134 , 0 , V_129 ) ;
if ( V_26 != V_135 ) {
F_13 ( L_30
L_31 ,
V_73 , V_26 , V_129 , V_8 -> V_14 ) ;
break;
}
V_126 . V_38 += V_7 -> V_9 . V_132 ;
V_129 ++ ;
}
} else if ( V_128 -> V_34 & V_136 ) {
V_126 . V_38 = V_128 -> V_38 -
V_18 -> V_137 -
V_7 -> V_9 . V_138 ;
V_126 . V_37 = V_128 -> V_37 -
V_18 -> V_137 -
V_7 -> V_9 . V_138 ;
V_129 = V_126 . V_38 / V_7 -> V_9 . V_139 ;
while ( V_129 < V_7 -> V_9 . V_11 &&
V_126 . V_38 <= V_126 . V_37 ) {
V_7 -> V_9 . V_140 [ V_129 ] = V_8 -> V_14 ;
V_26 = F_67 ( V_7 -> V_47 ,
V_8 -> V_14 , V_141 , 0 , V_129 ) ;
if ( V_26 != V_135 ) {
F_13 ( L_32
L_33 ,
V_73 , V_26 , V_129 , V_8 -> V_14 ) ;
break;
}
V_126 . V_38 += V_7 -> V_9 . V_139 ;
V_129 ++ ;
}
}
}
}
static void F_68 ( void )
{
struct V_17 * V_81 , * V_18 ;
struct V_6 * V_7 ;
struct V_16 * V_8 ;
F_35 (hose, tmp, &hose_list, list_node) {
V_7 = V_18 -> V_20 ;
F_22 (pe, &phb->ioda.pe_list, list) {
F_64 ( V_18 , V_8 ) ;
}
}
}
static void F_69 ( void )
{
struct V_17 * V_18 , * V_81 ;
struct V_6 * V_7 ;
F_35 (hose, tmp, &hose_list, list_node) {
F_52 ( V_18 -> V_20 ) ;
V_7 = V_18 -> V_20 ;
V_7 -> V_142 = 1 ;
}
}
static void F_70 ( void )
{
F_34 () ;
F_68 () ;
F_69 () ;
}
static T_7 F_71 ( struct V_68 * V_19 ,
unsigned long type )
{
struct V_2 * V_143 ;
struct V_17 * V_18 = F_11 ( V_19 ) ;
struct V_6 * V_7 = V_18 -> V_20 ;
int V_144 = 0 ;
V_143 = V_19 -> V_33 ;
while ( V_143 ) {
if ( F_33 ( V_143 ) == V_80 ) {
V_144 ++ ;
if ( V_144 >= 2 )
return 1 ;
}
V_143 = V_143 -> V_19 -> V_33 ;
}
if ( type & V_136 )
return V_7 -> V_9 . V_139 ;
return V_7 -> V_9 . V_132 ;
}
static int F_72 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_11 ( V_3 -> V_19 ) ;
struct V_6 * V_7 = V_18 -> V_20 ;
struct V_1 * V_21 ;
if ( ! V_7 -> V_142 )
return 0 ;
V_21 = F_1 ( V_3 ) ;
if ( ! V_21 || V_21 -> V_14 == V_12 )
return - V_145 ;
return 0 ;
}
static T_8 F_73 ( struct V_6 * V_7 , struct V_68 * V_19 ,
T_8 V_146 )
{
return V_7 -> V_9 . V_52 [ ( V_19 -> V_74 << 8 ) | V_146 ] ;
}
void T_9 F_74 ( struct V_4 * V_5 )
{
struct V_17 * V_18 ;
static int V_147 = 1 ;
struct V_6 * V_7 ;
unsigned long V_148 , V_149 , V_150 , V_151 ;
const T_10 * V_152 ;
T_10 V_153 ;
void * V_154 ;
long V_26 ;
F_53 ( L_34 , V_5 -> V_155 ) ;
V_152 = F_47 ( V_5 , L_35 , NULL ) ;
if ( ! V_152 ) {
F_13 ( L_36 ) ;
return;
}
V_153 = F_49 ( V_152 ) ;
F_75 ( L_37 , V_153 ) ;
V_7 = F_76 ( sizeof( struct V_6 ) ) ;
if ( V_7 ) {
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
V_7 -> V_18 = V_18 = F_77 ( V_5 ) ;
}
if ( ! V_7 || ! V_7 -> V_18 ) {
F_13 ( L_38 ,
V_5 -> V_155 ) ;
return;
}
F_78 ( & V_7 -> V_156 ) ;
V_18 -> V_157 = 0 ;
V_18 -> V_158 = 0xff ;
V_18 -> V_20 = V_7 ;
V_7 -> V_47 = V_153 ;
V_7 -> type = V_53 ;
if ( F_79 ( V_5 , L_39 ) )
V_7 -> V_159 = V_160 ;
else
V_7 -> V_159 = V_161 ;
F_80 ( V_7 -> V_18 , V_5 , V_147 ) ;
V_147 = 0 ;
V_7 -> V_162 = F_81 ( V_5 , 0 ) ;
if ( V_7 -> V_162 == NULL )
F_13 ( L_40 ) ;
V_7 -> V_9 . V_11 = 128 ;
V_7 -> V_9 . V_163 = F_82 ( & V_18 -> V_164 [ 0 ] ) ;
V_7 -> V_9 . V_163 += 0x10000 ;
V_7 -> V_9 . V_139 = V_7 -> V_9 . V_163 / V_7 -> V_9 . V_11 ;
V_7 -> V_9 . V_138 = V_18 -> V_164 [ 0 ] . V_38 -
V_18 -> V_137 ;
V_7 -> V_9 . V_165 = V_18 -> V_166 ;
V_7 -> V_9 . V_132 = V_7 -> V_9 . V_165 / V_7 -> V_9 . V_11 ;
V_7 -> V_9 . V_131 = 0 ;
V_148 = F_83 ( V_7 -> V_9 . V_11 / 8 , sizeof( unsigned long ) ) ;
V_149 = V_148 ;
V_148 += V_7 -> V_9 . V_11 * sizeof( V_7 -> V_9 . V_140 [ 0 ] ) ;
V_150 = V_148 ;
V_148 += V_7 -> V_9 . V_11 * sizeof( V_7 -> V_9 . V_133 [ 0 ] ) ;
V_151 = V_148 ;
V_148 += V_7 -> V_9 . V_11 * sizeof( struct V_16 ) ;
V_154 = F_76 ( V_148 ) ;
memset ( V_154 , 0 , V_148 ) ;
V_7 -> V_9 . V_10 = V_154 ;
V_7 -> V_9 . V_140 = V_154 + V_149 ;
V_7 -> V_9 . V_133 = V_154 + V_150 ;
V_7 -> V_9 . V_13 = V_154 + V_151 ;
F_84 ( 0 , V_7 -> V_9 . V_10 ) ;
F_85 ( & V_7 -> V_9 . V_60 ) ;
F_85 ( & V_7 -> V_9 . V_78 ) ;
V_7 -> V_9 . V_105 = V_7 -> V_9 . V_138 >> 28 ;
V_18 -> V_164 [ 1 ] . V_34 = 0 ;
V_18 -> V_164 [ 1 ] . V_38 = 0 ;
V_18 -> V_164 [ 1 ] . V_37 = 0 ;
V_18 -> V_164 [ 2 ] . V_34 = 0 ;
V_18 -> V_164 [ 2 ] . V_38 = 0 ;
V_18 -> V_164 [ 2 ] . V_37 = 0 ;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
F_53 ( L_41 ,
V_7 -> V_9 . V_11 ,
V_7 -> V_9 . V_163 , V_7 -> V_9 . V_139 ,
V_7 -> V_9 . V_165 , V_7 -> V_9 . V_132 ) ;
if ( V_7 -> V_162 ) {
F_59 ( L_42 , F_86 ( V_7 -> V_162 + 0x100 ) ) ;
F_59 ( L_43 , F_86 ( V_7 -> V_162 + 0x160 ) ) ;
F_59 ( L_44 , F_86 ( V_7 -> V_162 + 0x170 ) ) ;
F_59 ( L_45 , F_86 ( V_7 -> V_162 + 0x178 ) ) ;
F_59 ( L_46 , F_86 ( V_7 -> V_162 + 0x180 ) ) ;
F_59 ( L_47 , F_86 ( V_7 -> V_162 + 0x190 ) ) ;
F_59 ( L_48 , F_86 ( V_7 -> V_162 + 0x198 ) ) ;
F_59 ( L_49 , F_86 ( V_7 -> V_162 + 0x1a0 ) ) ;
}
V_7 -> V_18 -> V_167 = & V_168 ;
V_7 -> V_169 = F_73 ;
V_7 -> V_170 = F_36 ;
F_60 ( V_7 ) ;
V_171 . V_172 = F_70 ;
V_171 . V_173 = F_72 ;
V_171 . V_174 = F_71 ;
F_87 ( V_175 ) ;
V_26 = F_88 ( V_153 , V_176 , V_177 ) ;
if ( V_26 )
F_29 ( L_50 , V_26 ) ;
F_15 ( V_153 , 0 , 0 , 7 , 1 , 1 , V_48 ) ;
}
void T_9 F_89 ( struct V_4 * V_5 )
{
struct V_4 * V_178 ;
const T_10 * V_152 ;
T_10 V_179 ;
F_53 ( L_51 , V_5 -> V_155 ) ;
V_152 = F_47 ( V_5 , L_52 , NULL ) ;
if ( ! V_152 ) {
F_13 ( L_53 ) ;
return;
}
V_179 = F_49 ( V_152 ) ;
F_59 ( L_54 , V_179 ) ;
F_90 (np, phbn) {
if ( F_79 ( V_178 , L_55 ) )
F_74 ( V_178 ) ;
}
}
