static int F_1 ( const char * V_1 , const struct V_2 * V_3 ,
struct V_4 * V_5 )
{
char V_6 [ 32 ] ;
if ( V_3 -> V_7 )
F_2 ( V_6 , F_3 ( & V_3 -> V_7 -> V_8 ) , sizeof( V_6 ) ) ;
else
sprintf ( V_6 , L_1 ,
F_4 ( V_3 -> V_9 ) , V_3 -> V_9 -> V_10 ) ;
return F_5 ( L_2 , V_1 , V_6 , V_3 -> V_11 , V_5 ) ;
}
static struct V_12 * F_6 ( struct V_13 * V_8 )
{
struct V_14 * V_15 ;
V_15 = F_7 ( V_8 ) ;
if ( ! V_15 )
return NULL ;
return F_8 ( V_15 ) ;
}
static int T_1 F_9 ( struct V_16 * V_17 )
{
unsigned long V_3 ;
do {
V_3 = F_10 ( V_17 -> V_18 . V_19 ,
V_17 -> V_18 . V_20 , 0 ) ;
if ( V_3 >= V_17 -> V_18 . V_20 )
return V_21 ;
} while( F_11 ( V_3 , V_17 -> V_18 . V_19 ) );
V_17 -> V_18 . V_22 [ V_3 ] . V_11 = V_3 ;
return V_3 ;
}
static void T_1 F_12 ( struct V_16 * V_17 , int V_3 )
{
F_13 ( V_17 -> V_18 . V_22 [ V_3 ] . V_7 ) ;
memset ( & V_17 -> V_18 . V_22 [ V_3 ] , 0 , sizeof( struct V_2 ) ) ;
F_14 ( V_3 , V_17 -> V_18 . V_19 ) ;
}
static struct V_2 * T_1 F_15 ( struct V_13 * V_8 )
{
struct V_23 * V_24 = F_16 ( V_8 -> V_25 ) ;
struct V_16 * V_17 = V_24 -> V_26 ;
struct V_12 * V_27 = F_6 ( V_8 ) ;
if ( ! V_27 )
return NULL ;
if ( V_27 -> V_11 == V_21 )
return NULL ;
return & V_17 -> V_18 . V_22 [ V_27 -> V_11 ] ;
}
static int T_1 F_17 ( struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_13 * V_28 ;
T_2 V_29 , V_30 , V_31 ;
long V_32 , V_33 , V_34 ;
if ( V_3 -> V_9 ) {
int V_35 ;
V_30 = V_36 ;
V_31 = V_37 ;
V_28 = V_3 -> V_9 -> V_38 ;
if ( V_3 -> V_39 & V_40 )
V_35 = V_3 -> V_9 -> V_41 . V_42 - V_3 -> V_9 -> V_41 . V_43 + 1 ;
else
V_35 = 1 ;
switch( V_35 ) {
case 1 : V_29 = V_44 ; break;
case 2 : V_29 = V_45 ; break;
case 4 : V_29 = V_46 ; break;
case 8 : V_29 = V_47 ; break;
case 16 : V_29 = V_48 ; break;
case 32 : V_29 = V_49 ; break;
default:
F_18 ( L_3
L_4 ,
F_19 ( V_3 -> V_9 -> V_38 ) , V_35 ) ;
V_29 = V_44 ;
}
V_33 = V_3 -> V_34 + ( V_35 << 8 ) ;
} else {
V_28 = V_3 -> V_7 -> V_25 -> V_38 ;
V_29 = V_44 ;
V_30 = V_50 ;
V_31 = V_51 ;
V_33 = V_3 -> V_34 + 1 ;
}
V_32 = F_20 ( V_17 -> V_52 , V_3 -> V_11 , V_3 -> V_34 ,
V_29 , V_30 , V_31 , V_53 ) ;
if ( V_32 ) {
F_21 ( V_3 , L_5 , V_32 ) ;
return - V_54 ;
}
F_22 ( V_17 -> V_52 , V_3 -> V_11 ,
V_55 ) ;
while ( V_28 ) {
struct V_12 * V_27 = F_6 ( V_28 ) ;
if ( V_27 && V_27 -> V_11 != V_21 ) {
V_32 = F_23 ( V_17 -> V_52 , V_27 -> V_11 ,
V_3 -> V_11 , V_56 ) ;
}
V_28 = V_28 -> V_25 -> V_38 ;
}
for ( V_34 = V_3 -> V_34 ; V_34 < V_33 ; V_34 ++ )
V_17 -> V_18 . V_57 [ V_34 ] = V_3 -> V_11 ;
if ( V_17 -> type == V_58 ) {
V_3 -> V_59 = V_3 -> V_11 ;
V_32 = F_24 ( V_17 -> V_52 , V_3 -> V_59 ,
V_3 -> V_11 ) ;
if ( V_32 ) {
F_21 ( V_3 , L_6 ,
V_32 , V_3 -> V_59 ) ;
V_3 -> V_59 = - 1 ;
} else {
V_32 = F_25 ( V_17 -> V_52 ,
V_3 -> V_59 , V_60 ) ;
if ( V_32 ) {
F_21 ( V_3 , L_7 ,
V_32 , V_3 -> V_59 ) ;
V_3 -> V_59 = - 1 ;
}
}
} else if ( V_17 -> type == V_61 )
V_3 -> V_59 = 0 ;
return 0 ;
}
static void T_1 F_26 ( struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_2 * V_62 ;
F_27 (lpe, &phb->ioda.pe_dma_list, dma_link) {
if ( V_62 -> V_63 < V_3 -> V_63 ) {
F_28 ( & V_3 -> V_64 , & V_62 -> V_64 ) ;
return;
}
}
F_28 ( & V_3 -> V_64 , & V_17 -> V_18 . V_65 ) ;
}
static unsigned int F_29 ( struct V_13 * V_8 )
{
if ( V_8 -> V_66 != V_67 )
return 0 ;
if ( V_8 -> V_68 == V_69 ||
V_8 -> V_68 == V_70 ||
V_8 -> V_68 == V_71 )
return 3 ;
if ( ( V_8 -> V_68 >> 8 ) == V_72 )
return 15 ;
return 10 ;
}
static void F_30 ( struct V_73 * V_25 , struct V_2 * V_3 )
{
struct V_13 * V_8 ;
F_27 (dev, &bus->devices, bus_list) {
struct V_12 * V_27 = F_6 ( V_8 ) ;
if ( V_27 == NULL ) {
F_31 ( L_8 ,
F_19 ( V_8 ) ) ;
continue;
}
F_32 ( V_8 ) ;
V_27 -> V_74 = V_8 ;
V_27 -> V_11 = V_3 -> V_11 ;
V_3 -> V_63 += F_29 ( V_8 ) ;
if ( ( V_3 -> V_39 & V_40 ) && V_8 -> V_75 )
F_30 ( V_8 -> V_75 , V_3 ) ;
}
}
static void T_1 F_33 ( struct V_73 * V_25 , int V_76 )
{
struct V_23 * V_24 = F_16 ( V_25 ) ;
struct V_16 * V_17 = V_24 -> V_26 ;
struct V_2 * V_3 ;
int V_77 ;
V_77 = F_9 ( V_17 ) ;
if ( V_77 == V_21 ) {
F_34 ( L_9 ,
V_78 , F_4 ( V_25 ) , V_25 -> V_10 ) ;
return;
}
V_3 = & V_17 -> V_18 . V_22 [ V_77 ] ;
V_3 -> V_39 = ( V_76 ? V_40 : V_79 ) ;
V_3 -> V_9 = V_25 ;
V_3 -> V_7 = NULL ;
V_3 -> V_80 = - 1 ;
V_3 -> V_59 = - 1 ;
V_3 -> V_34 = V_25 -> V_41 . V_43 << 8 ;
V_3 -> V_63 = 0 ;
if ( V_76 )
F_35 ( V_3 , L_10 ,
V_25 -> V_41 . V_43 , V_25 -> V_41 . V_42 , V_77 ) ;
else
F_35 ( V_3 , L_11 ,
V_25 -> V_41 . V_43 , V_77 ) ;
if ( F_17 ( V_17 , V_3 ) ) {
if ( V_77 )
F_12 ( V_17 , V_77 ) ;
V_3 -> V_9 = NULL ;
return;
}
F_30 ( V_25 , V_3 ) ;
F_28 ( & V_3 -> V_81 , & V_17 -> V_18 . V_82 ) ;
if ( V_3 -> V_63 != 0 ) {
V_17 -> V_18 . V_63 += V_3 -> V_63 ;
V_17 -> V_18 . V_83 ++ ;
}
F_26 ( V_17 , V_3 ) ;
}
static void T_1 F_36 ( struct V_73 * V_25 )
{
struct V_13 * V_8 ;
F_33 ( V_25 , 0 ) ;
F_27 (dev, &bus->devices, bus_list) {
if ( V_8 -> V_75 ) {
if ( F_37 ( V_8 ) == V_84 )
F_33 ( V_8 -> V_75 , 1 ) ;
else
F_36 ( V_8 -> V_75 ) ;
}
}
}
static void T_1 F_38 ( void )
{
struct V_23 * V_24 , * V_85 ;
F_39 (hose, tmp, &hose_list, list_node) {
F_36 ( V_24 -> V_25 ) ;
}
}
static void T_1 F_40 ( struct V_16 * V_17 ,
struct V_13 * V_8 )
{
}
static void T_1 F_41 ( struct V_2 * V_3 ,
struct V_73 * V_25 )
{
struct V_13 * V_8 ;
F_27 (dev, &bus->devices, bus_list) {
F_42 ( & V_8 -> V_8 , & V_3 -> V_86 ) ;
if ( V_8 -> V_75 )
F_41 ( V_3 , V_8 -> V_75 ) ;
}
}
static void T_1 F_43 ( struct V_16 * V_17 ,
struct V_2 * V_3 ,
unsigned int V_87 ,
unsigned int V_88 )
{
struct V_89 * V_90 = NULL ;
const T_3 * V_91 ;
struct V_92 * V_93 ;
unsigned int V_94 ;
T_4 V_32 ;
void * V_95 ;
#define F_44 ((0x10000000 / 0x1000) * 8)
if ( F_13 ( V_3 -> V_80 >= 0 ) )
return;
V_3 -> V_80 = V_87 ;
F_35 ( V_3 , L_12 ,
( V_87 << 28 ) , ( ( V_87 + V_88 ) << 28 ) - 1 ) ;
V_90 = F_45 ( V_17 -> V_24 -> V_96 , V_97 ,
F_46 ( F_44 * V_88 ) ) ;
if ( ! V_90 ) {
F_21 ( V_3 , L_13 ) ;
goto V_98;
}
V_95 = F_47 ( V_90 ) ;
memset ( V_95 , 0 , F_44 * V_88 ) ;
for ( V_94 = 0 ; V_94 < V_88 ; V_94 ++ ) {
V_32 = F_48 ( V_17 -> V_52 ,
V_3 -> V_11 ,
V_87 + V_94 , 1 ,
F_49 ( V_95 ) + F_44 * V_94 ,
F_44 , 0x1000 ) ;
if ( V_32 ) {
F_21 ( V_3 , L_14
L_15 , V_32 ) ;
goto V_98;
}
}
V_93 = & V_3 -> V_86 ;
F_50 ( V_93 , V_95 , F_44 * V_88 ,
V_87 << 28 ) ;
V_91 = F_51 ( V_17 -> V_24 -> V_99 , L_16 , NULL ) ;
if ( V_91 ) {
V_93 -> V_100 = 0 ;
V_93 -> V_101 = ( unsigned long ) F_52 ( F_53 ( V_91 ) , 8 ) ;
V_93 -> V_102 = V_103 | V_104
| V_105 ;
}
F_54 ( V_93 , V_17 -> V_24 -> V_96 ) ;
if ( V_3 -> V_7 )
F_42 ( & V_3 -> V_7 -> V_8 , V_93 ) ;
else
F_41 ( V_3 , V_3 -> V_9 ) ;
return;
V_98:
if ( V_3 -> V_80 >= 0 )
V_3 -> V_80 = - 1 ;
if ( V_90 )
F_55 ( V_90 , F_46 ( F_44 * V_88 ) ) ;
}
static void T_1 F_56 ( struct V_16 * V_17 )
{
struct V_23 * V_24 = V_17 -> V_24 ;
unsigned int V_106 , V_107 , V_88 , V_108 , V_87 ;
struct V_2 * V_3 ;
if ( V_17 -> V_18 . V_83 > V_17 -> V_18 . V_109 )
V_106 = 0 ;
else
V_106 = V_17 -> V_18 . V_109 -
V_17 -> V_18 . V_83 ;
F_57 ( L_17 ,
V_24 -> V_110 , V_17 -> V_18 . V_109 ) ;
F_57 ( L_18 ,
V_17 -> V_18 . V_83 , V_17 -> V_18 . V_63 ) ;
V_107 = V_17 -> V_18 . V_109 ;
V_108 = V_17 -> V_18 . V_63 ;
V_87 = 0 ;
F_27 (pe, &phb->ioda.pe_dma_list, dma_link) {
if ( ! V_3 -> V_63 )
continue;
if ( ! V_107 ) {
F_58 ( V_3 , L_19 ) ;
continue;
}
V_88 = 1 ;
if ( V_106 ) {
V_88 += ( ( V_3 -> V_63 * V_106 ) + ( V_108 / 2 ) ) / V_108 ;
if ( V_88 > V_107 )
V_88 = V_107 ;
}
F_35 ( V_3 , L_20 ,
V_3 -> V_63 , V_88 ) ;
F_43 ( V_17 , V_3 , V_87 , V_88 ) ;
V_107 -= V_88 ;
V_87 += V_88 ;
}
}
static int F_59 ( struct V_16 * V_17 , struct V_13 * V_8 ,
unsigned int V_111 , unsigned int V_112 ,
struct V_113 * V_114 )
{
struct V_2 * V_3 = F_15 ( V_8 ) ;
unsigned int V_115 = V_111 - V_17 -> V_116 ;
T_5 V_117 ;
T_6 V_118 , V_119 ;
int V_32 ;
if ( V_3 == NULL )
return - V_54 ;
if ( V_3 -> V_59 < 0 )
return - V_54 ;
V_32 = F_60 ( V_17 -> V_52 , V_3 -> V_11 , V_115 ) ;
if ( V_32 ) {
F_31 ( L_21 ,
F_19 ( V_8 ) , V_32 , V_115 ) ;
return - V_120 ;
}
if ( V_112 ) {
V_32 = F_61 ( V_17 -> V_52 , V_3 -> V_59 , V_115 , 1 ,
& V_117 , & V_119 ) ;
if ( V_32 ) {
F_31 ( L_22 ,
F_19 ( V_8 ) , V_32 ) ;
return - V_120 ;
}
V_114 -> V_121 = V_117 >> 32 ;
V_114 -> V_122 = V_117 & 0xfffffffful ;
} else {
V_32 = F_62 ( V_17 -> V_52 , V_3 -> V_59 , V_115 , 1 ,
& V_118 , & V_119 ) ;
if ( V_32 ) {
F_31 ( L_23 ,
F_19 ( V_8 ) , V_32 ) ;
return - V_120 ;
}
V_114 -> V_121 = 0 ;
V_114 -> V_122 = V_118 ;
}
V_114 -> V_119 = V_119 ;
F_63 ( L_24
L_25 ,
F_19 ( V_8 ) , V_112 ? L_26 : L_27 , V_111 , V_115 ,
V_114 -> V_121 , V_114 -> V_122 , V_119 , V_3 -> V_11 ) ;
return 0 ;
}
static void F_64 ( struct V_16 * V_17 )
{
unsigned int V_123 ;
const T_7 * V_124 = F_51 ( V_17 -> V_24 -> V_99 ,
L_28 , NULL ) ;
if ( ! V_124 ) {
V_124 = F_51 ( V_17 -> V_24 -> V_99 , L_29 , NULL ) ;
}
if ( ! V_124 )
return;
V_17 -> V_116 = F_65 ( V_124 ) ;
V_17 -> V_125 = F_65 ( V_124 + 1 ) ;
V_123 = F_66 ( V_17 -> V_125 ) * sizeof( unsigned long ) ;
V_17 -> V_126 = F_67 ( V_123 , V_97 ) ;
if ( ! V_17 -> V_126 ) {
F_18 ( L_30 ,
V_17 -> V_24 -> V_110 ) ;
return;
}
V_17 -> V_127 = F_59 ;
V_17 -> V_128 = 1 ;
F_57 ( L_31 ,
V_17 -> V_125 , V_17 -> V_116 ) ;
}
static void F_64 ( struct V_16 * V_17 ) { }
static void T_1 F_68 ( struct V_23 * V_24 ,
struct V_2 * V_3 )
{
struct V_16 * V_17 = V_24 -> V_26 ;
struct V_129 V_130 ;
struct V_131 * V_132 ;
int V_94 , V_133 ;
int V_32 ;
F_69 ( ! ( V_3 -> V_39 & ( V_79 | V_40 ) ) ) ;
F_70 (pe->pbus, res, i) {
if ( ! V_132 || ! V_132 -> V_39 ||
V_132 -> V_43 > V_132 -> V_42 )
continue;
if ( V_132 -> V_39 & V_134 ) {
V_130 . V_43 = V_132 -> V_43 - V_17 -> V_18 . V_135 ;
V_130 . V_42 = V_132 -> V_42 - V_17 -> V_18 . V_135 ;
V_133 = V_130 . V_43 / V_17 -> V_18 . V_136 ;
while ( V_133 < V_17 -> V_18 . V_20 &&
V_130 . V_43 <= V_130 . V_42 ) {
V_17 -> V_18 . V_137 [ V_133 ] = V_3 -> V_11 ;
V_32 = F_71 ( V_17 -> V_52 ,
V_3 -> V_11 , V_138 , 0 , V_133 ) ;
if ( V_32 != V_139 ) {
F_18 ( L_32
L_33 ,
V_78 , V_32 , V_133 , V_3 -> V_11 ) ;
break;
}
V_130 . V_43 += V_17 -> V_18 . V_136 ;
V_133 ++ ;
}
} else if ( V_132 -> V_39 & V_140 ) {
V_130 . V_43 = V_132 -> V_43 -
V_24 -> V_141 -
V_17 -> V_18 . V_142 ;
V_130 . V_42 = V_132 -> V_42 -
V_24 -> V_141 -
V_17 -> V_18 . V_142 ;
V_133 = V_130 . V_43 / V_17 -> V_18 . V_143 ;
while ( V_133 < V_17 -> V_18 . V_20 &&
V_130 . V_43 <= V_130 . V_42 ) {
V_17 -> V_18 . V_144 [ V_133 ] = V_3 -> V_11 ;
V_32 = F_71 ( V_17 -> V_52 ,
V_3 -> V_11 , V_145 , 0 , V_133 ) ;
if ( V_32 != V_139 ) {
F_18 ( L_34
L_35 ,
V_78 , V_32 , V_133 , V_3 -> V_11 ) ;
break;
}
V_130 . V_43 += V_17 -> V_18 . V_143 ;
V_133 ++ ;
}
}
}
}
static void T_1 F_72 ( void )
{
struct V_23 * V_85 , * V_24 ;
struct V_16 * V_17 ;
struct V_2 * V_3 ;
F_39 (hose, tmp, &hose_list, list_node) {
V_17 = V_24 -> V_26 ;
F_27 (pe, &phb->ioda.pe_list, list) {
F_68 ( V_24 , V_3 ) ;
}
}
}
static void T_1 F_73 ( void )
{
struct V_23 * V_24 , * V_85 ;
struct V_16 * V_17 ;
F_39 (hose, tmp, &hose_list, list_node) {
F_56 ( V_24 -> V_26 ) ;
V_17 = V_24 -> V_26 ;
V_17 -> V_146 = 1 ;
}
}
static void T_1 F_74 ( void )
{
F_38 () ;
F_72 () ;
F_73 () ;
}
static T_8 F_75 ( struct V_73 * V_25 ,
unsigned long type )
{
struct V_13 * V_147 ;
struct V_23 * V_24 = F_16 ( V_25 ) ;
struct V_16 * V_17 = V_24 -> V_26 ;
int V_148 = 0 ;
V_147 = V_25 -> V_38 ;
while ( V_147 ) {
if ( F_37 ( V_147 ) == V_84 ) {
V_148 ++ ;
if ( V_148 >= 2 )
return 1 ;
}
V_147 = V_147 -> V_25 -> V_38 ;
}
if ( type & V_140 )
return V_17 -> V_18 . V_143 ;
return V_17 -> V_18 . V_136 ;
}
static int T_1 F_76 ( struct V_13 * V_8 )
{
struct V_23 * V_24 = F_16 ( V_8 -> V_25 ) ;
struct V_16 * V_17 = V_24 -> V_26 ;
struct V_12 * V_27 ;
if ( ! V_17 -> V_146 )
return 0 ;
V_27 = F_6 ( V_8 ) ;
if ( ! V_27 || V_27 -> V_11 == V_21 )
return - V_149 ;
return 0 ;
}
static T_9 F_77 ( struct V_16 * V_17 , struct V_73 * V_25 ,
T_9 V_150 )
{
return V_17 -> V_18 . V_57 [ ( V_25 -> V_10 << 8 ) | V_150 ] ;
}
void T_10 F_78 ( struct V_14 * V_15 )
{
struct V_23 * V_24 ;
static int V_151 = 1 ;
struct V_16 * V_17 ;
unsigned long V_152 , V_153 , V_154 , V_155 ;
const T_11 * V_156 ;
T_11 V_157 ;
void * V_158 ;
long V_32 ;
F_57 ( L_36 , V_15 -> V_159 ) ;
V_156 = F_51 ( V_15 , L_37 , NULL ) ;
if ( ! V_156 ) {
F_18 ( L_38 ) ;
return;
}
V_157 = F_53 ( V_156 ) ;
F_79 ( L_39 , V_157 ) ;
V_17 = F_80 ( sizeof( struct V_16 ) ) ;
if ( V_17 ) {
memset ( V_17 , 0 , sizeof( struct V_16 ) ) ;
V_17 -> V_24 = V_24 = F_81 ( V_15 ) ;
}
if ( ! V_17 || ! V_17 -> V_24 ) {
F_18 ( L_40 ,
V_15 -> V_159 ) ;
return;
}
F_82 ( & V_17 -> V_160 ) ;
V_24 -> V_161 = 0 ;
V_24 -> V_162 = 0xff ;
V_24 -> V_26 = V_17 ;
V_17 -> V_52 = V_157 ;
V_17 -> type = V_58 ;
if ( F_83 ( V_15 , L_41 ) )
V_17 -> V_163 = V_164 ;
else
V_17 -> V_163 = V_165 ;
F_84 ( V_17 -> V_24 , V_15 , V_151 ) ;
V_151 = 0 ;
V_17 -> V_166 = F_85 ( V_15 , 0 ) ;
if ( V_17 -> V_166 == NULL )
F_18 ( L_42 ) ;
V_17 -> V_18 . V_20 = 128 ;
V_17 -> V_18 . V_167 = F_86 ( & V_24 -> V_168 [ 0 ] ) ;
V_17 -> V_18 . V_167 += 0x10000 ;
V_17 -> V_18 . V_143 = V_17 -> V_18 . V_167 / V_17 -> V_18 . V_20 ;
V_17 -> V_18 . V_142 = V_24 -> V_168 [ 0 ] . V_43 -
V_24 -> V_141 ;
V_17 -> V_18 . V_169 = V_24 -> V_170 ;
V_17 -> V_18 . V_136 = V_17 -> V_18 . V_169 / V_17 -> V_18 . V_20 ;
V_17 -> V_18 . V_135 = 0 ;
V_152 = F_87 ( V_17 -> V_18 . V_20 / 8 , sizeof( unsigned long ) ) ;
V_153 = V_152 ;
V_152 += V_17 -> V_18 . V_20 * sizeof( V_17 -> V_18 . V_144 [ 0 ] ) ;
V_154 = V_152 ;
V_152 += V_17 -> V_18 . V_20 * sizeof( V_17 -> V_18 . V_137 [ 0 ] ) ;
V_155 = V_152 ;
V_152 += V_17 -> V_18 . V_20 * sizeof( struct V_2 ) ;
V_158 = F_80 ( V_152 ) ;
memset ( V_158 , 0 , V_152 ) ;
V_17 -> V_18 . V_19 = V_158 ;
V_17 -> V_18 . V_144 = V_158 + V_153 ;
V_17 -> V_18 . V_137 = V_158 + V_154 ;
V_17 -> V_18 . V_22 = V_158 + V_155 ;
F_88 ( 0 , V_17 -> V_18 . V_19 ) ;
F_89 ( & V_17 -> V_18 . V_65 ) ;
F_89 ( & V_17 -> V_18 . V_82 ) ;
V_17 -> V_18 . V_109 = V_17 -> V_18 . V_142 >> 28 ;
V_24 -> V_168 [ 1 ] . V_39 = 0 ;
V_24 -> V_168 [ 1 ] . V_43 = 0 ;
V_24 -> V_168 [ 1 ] . V_42 = 0 ;
V_24 -> V_168 [ 2 ] . V_39 = 0 ;
V_24 -> V_168 [ 2 ] . V_43 = 0 ;
V_24 -> V_168 [ 2 ] . V_42 = 0 ;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
F_57 ( L_43 ,
V_17 -> V_18 . V_20 ,
V_17 -> V_18 . V_167 , V_17 -> V_18 . V_143 ,
V_17 -> V_18 . V_169 , V_17 -> V_18 . V_136 ) ;
if ( V_17 -> V_166 ) {
F_63 ( L_44 , F_90 ( V_17 -> V_166 + 0x100 ) ) ;
F_63 ( L_45 , F_90 ( V_17 -> V_166 + 0x160 ) ) ;
F_63 ( L_46 , F_90 ( V_17 -> V_166 + 0x170 ) ) ;
F_63 ( L_47 , F_90 ( V_17 -> V_166 + 0x178 ) ) ;
F_63 ( L_48 , F_90 ( V_17 -> V_166 + 0x180 ) ) ;
F_63 ( L_49 , F_90 ( V_17 -> V_166 + 0x190 ) ) ;
F_63 ( L_50 , F_90 ( V_17 -> V_166 + 0x198 ) ) ;
F_63 ( L_51 , F_90 ( V_17 -> V_166 + 0x1a0 ) ) ;
}
V_17 -> V_24 -> V_171 = & V_172 ;
V_17 -> V_173 = F_77 ;
V_17 -> V_174 = F_40 ;
F_64 ( V_17 ) ;
V_175 . V_176 = F_74 ;
V_175 . V_177 = F_76 ;
V_175 . V_178 = F_75 ;
F_91 ( V_179 ) ;
V_32 = F_92 ( V_157 , V_180 , V_181 ) ;
if ( V_32 )
F_34 ( L_52 , V_32 ) ;
F_20 ( V_157 , 0 , 0 , 7 , 1 , 1 , V_53 ) ;
}
void T_10 F_93 ( struct V_14 * V_15 )
{
struct V_14 * V_182 ;
const T_11 * V_156 ;
T_11 V_183 ;
F_57 ( L_53 , V_15 -> V_159 ) ;
V_156 = F_51 ( V_15 , L_54 , NULL ) ;
if ( ! V_156 ) {
F_18 ( L_55 ) ;
return;
}
V_183 = F_53 ( V_156 ) ;
F_63 ( L_56 , V_183 ) ;
F_94 (np, phbn) {
if ( F_83 ( V_182 , L_57 ) )
F_78 ( V_182 ) ;
}
}
