static inline void F_1 ( T_1 V_1 , volatile void T_2 * V_2 )
{
__asm__ __volatile__("stdcix %0,0,%1"
: : "r" (val), "r" (paddr) : "memory");
}
static inline bool F_2 ( unsigned long V_3 )
{
return ( ( V_3 & ( V_4 | V_5 ) ) ==
( V_4 | V_5 ) ) ;
}
static int F_3 ( struct V_6 * V_7 )
{
unsigned long V_8 ;
do {
V_8 = F_4 ( V_7 -> V_9 . V_10 ,
V_7 -> V_9 . V_11 , 0 ) ;
if ( V_8 >= V_7 -> V_9 . V_11 )
return V_12 ;
} while( F_5 ( V_8 , V_7 -> V_9 . V_10 ) );
V_7 -> V_9 . V_13 [ V_8 ] . V_7 = V_7 ;
V_7 -> V_9 . V_13 [ V_8 ] . V_14 = V_8 ;
return V_8 ;
}
static void F_6 ( struct V_6 * V_7 , int V_8 )
{
F_7 ( V_7 -> V_9 . V_13 [ V_8 ] . V_15 ) ;
memset ( & V_7 -> V_9 . V_13 [ V_8 ] , 0 , sizeof( struct V_16 ) ) ;
F_8 ( V_8 , V_7 -> V_9 . V_10 ) ;
}
static int F_9 ( struct V_6 * V_7 )
{
const char * V_17 ;
struct V_18 * V_19 ;
T_3 V_20 ;
V_20 = F_10 ( V_7 -> V_21 ,
V_22 ,
V_7 -> V_9 . V_23 ,
V_7 -> V_9 . V_24 ,
0 ,
V_7 -> V_9 . V_25 ) ;
if ( V_20 != V_26 ) {
V_17 = L_1 ;
goto V_27;
}
V_20 = F_11 ( V_7 -> V_21 ,
V_22 ,
V_7 -> V_9 . V_23 ,
V_28 ) ;
if ( V_20 != V_26 ) {
V_17 = L_2 ;
goto V_27;
}
F_12 ( V_7 -> V_9 . V_23 , & V_7 -> V_9 . V_29 ) ;
V_19 = & V_7 -> V_30 -> V_31 [ 1 ] ;
if ( V_7 -> V_9 . V_32 == 0 )
V_19 -> V_33 += V_7 -> V_9 . V_34 ;
else if ( V_7 -> V_9 . V_32 == ( V_7 -> V_9 . V_11 - 1 ) )
V_19 -> V_35 -= V_7 -> V_9 . V_34 ;
else
F_13 ( L_3 ,
V_7 -> V_9 . V_32 ) ;
return 0 ;
V_27:
F_13 ( L_4 ,
V_20 , V_17 , V_7 -> V_9 . V_23 ) ;
F_11 ( V_7 -> V_21 ,
V_22 ,
V_7 -> V_9 . V_23 ,
V_36 ) ;
return - V_37 ;
}
static void F_14 ( struct V_6 * V_7 )
{
T_4 V_38 = V_7 -> V_9 . V_34 ;
struct V_39 * V_15 ;
struct V_18 * V_19 ;
int V_40 , V_41 , V_42 ;
F_15 (pdev, &phb->hose->bus->devices, bus_list) {
for ( V_42 = V_43 ;
V_42 <= V_44 ; V_42 ++ ) {
V_19 = & V_15 -> V_18 [ V_42 ] ;
if ( ! V_19 -> V_45 ||
! F_2 ( V_19 -> V_3 ) )
continue;
V_40 = ( V_19 -> V_33 - V_7 -> V_9 . V_24 ) / V_38 ;
for ( V_41 = 0 ; V_41 < F_16 ( V_19 ) / V_38 ; V_41 ++ )
F_12 ( V_40 + V_41 , V_7 -> V_9 . V_10 ) ;
}
}
}
static int F_17 ( struct V_6 * V_7 ,
struct V_46 * V_47 , int V_48 )
{
T_4 V_49 = V_7 -> V_9 . V_34 ;
struct V_39 * V_15 ;
struct V_18 * V_19 ;
struct V_16 * V_50 , * V_8 ;
unsigned long V_51 , * V_10 ;
bool V_52 ;
int V_33 , V_42 , V_53 ;
if ( F_18 ( V_47 ) )
return V_12 ;
V_52 = false ;
F_19 (bus, r, i) {
if ( V_19 && V_19 -> V_45 &&
F_2 ( V_19 -> V_3 ) ) {
V_52 = true ;
break;
}
}
if ( ! V_52 )
return V_12 ;
V_51 = F_20 ( V_7 -> V_9 . V_11 / 8 , sizeof( unsigned long ) ) ;
V_10 = F_21 ( V_51 , V_54 ) ;
if ( ! V_10 ) {
F_13 ( L_5 ,
V_55 ) ;
return V_12 ;
}
V_33 = ( V_19 -> V_33 - V_7 -> V_9 . V_24 ) / V_49 ;
for ( V_42 = 0 ; V_42 < F_16 ( V_19 ) / V_49 ; V_42 ++ )
F_12 ( V_33 + V_42 , V_10 ) ;
if ( V_48 )
goto V_56;
F_15 (pdev, &bus->devices, bus_list) {
if ( ! V_15 -> V_57 )
continue;
F_19 (pdev->subordinate, r, i) {
if ( ! V_19 || ! V_19 -> V_45 ||
! F_2 ( V_19 -> V_3 ) )
continue;
V_33 = ( V_19 -> V_33 - V_7 -> V_9 . V_24 ) / V_49 ;
for ( V_53 = 0 ; V_53 < F_16 ( V_19 ) / V_49 ; V_53 ++ )
F_8 ( V_33 + V_53 , V_10 ) ;
}
}
if ( F_22 ( V_10 , V_7 -> V_9 . V_11 ) ) {
F_23 ( V_10 ) ;
return V_12 ;
}
V_56:
V_50 = NULL ;
V_42 = - 1 ;
while ( ( V_42 = F_24 ( V_10 , V_7 -> V_9 . V_11 , V_42 + 1 ) ) <
V_7 -> V_9 . V_11 ) {
V_8 = & V_7 -> V_9 . V_13 [ V_42 ] ;
V_8 -> V_7 = V_7 ;
V_8 -> V_14 = V_42 ;
if ( ! V_50 ) {
V_8 -> V_3 |= V_58 ;
F_25 ( & V_8 -> V_59 ) ;
V_50 = V_8 ;
} else {
V_8 -> V_3 |= V_60 ;
V_8 -> V_61 = V_50 ;
F_26 ( & V_8 -> V_62 , & V_50 -> V_59 ) ;
}
}
F_23 ( V_10 ) ;
return V_50 -> V_14 ;
}
static void T_5 F_27 ( struct V_6 * V_7 )
{
struct V_63 * V_30 = V_7 -> V_30 ;
struct V_64 * V_65 = V_30 -> V_65 ;
struct V_18 * V_66 ;
const T_6 * V_19 ;
T_1 V_67 ;
if ( ! F_28 ( V_68 ) ) {
F_29 ( L_6 ) ;
return;
}
V_19 = F_30 ( V_65 , L_7 , NULL ) ;
if ( ! V_19 ) {
F_29 ( L_8 ,
V_65 -> V_69 ) ;
return;
}
if ( V_7 -> type != V_70 ) {
F_29 ( L_9 ) ;
return;
}
V_66 = & V_30 -> V_31 [ 1 ] ;
V_66 -> V_33 = F_31 ( V_65 , V_19 + 2 ) ;
V_66 -> V_35 = V_66 -> V_33 + F_32 ( V_19 + 4 , 2 ) - 1 ;
V_66 -> V_3 = ( V_71 | V_4 | V_5 ) ;
V_67 = F_32 ( V_19 , 2 ) ;
V_30 -> V_72 [ 1 ] = V_66 -> V_33 - V_67 ;
V_7 -> V_9 . V_25 = F_16 ( V_66 ) ;
V_7 -> V_9 . V_34 = V_7 -> V_9 . V_25 / V_7 -> V_9 . V_11 ;
V_7 -> V_9 . V_24 = V_67 ;
V_7 -> V_9 . V_23 = 15 ;
V_7 -> V_73 = F_9 ;
V_7 -> V_74 = F_14 ;
V_7 -> V_75 = F_17 ;
}
static void F_33 ( struct V_6 * V_7 , int V_76 )
{
struct V_16 * V_8 = & V_7 -> V_9 . V_13 [ V_76 ] ;
struct V_16 * V_77 ;
T_3 V_20 ;
if ( V_8 -> V_3 & V_60 ) {
V_8 = V_8 -> V_61 ;
F_7 ( ! V_8 || ! ( V_8 -> V_3 & V_58 ) ) ;
V_76 = V_8 -> V_14 ;
}
V_20 = F_34 ( V_7 -> V_21 ,
V_76 ,
V_78 ) ;
if ( V_20 != V_26 ) {
F_13 ( L_10 ,
V_55 , V_20 , V_7 -> V_30 -> V_79 , V_76 ) ;
return;
}
if ( ! ( V_8 -> V_3 & V_58 ) )
return;
F_15 (slave, &pe->slaves, list) {
V_20 = F_34 ( V_7 -> V_21 ,
V_77 -> V_14 ,
V_78 ) ;
if ( V_20 != V_26 )
F_13 ( L_10 ,
V_55 , V_20 , V_7 -> V_30 -> V_79 ,
V_77 -> V_14 ) ;
}
}
int F_35 ( struct V_6 * V_7 , int V_76 , int V_80 )
{
struct V_16 * V_8 , * V_77 ;
T_3 V_20 ;
V_8 = & V_7 -> V_9 . V_13 [ V_76 ] ;
if ( V_8 -> V_3 & V_60 ) {
V_8 = V_8 -> V_61 ;
F_7 ( ! V_8 || ! ( V_8 -> V_3 & V_58 ) ) ;
V_76 = V_8 -> V_14 ;
}
V_20 = F_36 ( V_7 -> V_21 , V_76 , V_80 ) ;
if ( V_20 != V_26 ) {
F_13 ( L_11 ,
V_55 , V_20 , V_80 , V_7 -> V_30 -> V_79 , V_76 ) ;
return - V_37 ;
}
if ( ! ( V_8 -> V_3 & V_58 ) )
return 0 ;
F_15 (slave, &pe->slaves, list) {
V_20 = F_36 ( V_7 -> V_21 ,
V_77 -> V_14 ,
V_80 ) ;
if ( V_20 != V_26 ) {
F_13 ( L_11 ,
V_55 , V_20 , V_80 , V_7 -> V_30 -> V_79 ,
V_77 -> V_14 ) ;
return - V_37 ;
}
}
return 0 ;
}
static int F_37 ( struct V_6 * V_7 , int V_76 )
{
struct V_16 * V_77 , * V_8 ;
T_7 V_81 , V_82 ;
T_8 V_83 ;
T_3 V_20 ;
if ( V_76 < 0 || V_76 >= V_7 -> V_9 . V_11 )
return V_84 ;
V_8 = & V_7 -> V_9 . V_13 [ V_76 ] ;
if ( V_8 -> V_3 & V_60 ) {
V_8 = V_8 -> V_61 ;
F_7 ( ! V_8 || ! ( V_8 -> V_3 & V_58 ) ) ;
V_76 = V_8 -> V_14 ;
}
V_20 = F_38 ( V_7 -> V_21 , V_76 ,
& V_82 , & V_83 , NULL ) ;
if ( V_20 != V_26 ) {
F_13 ( L_12
L_13 ,
V_55 , V_20 ,
V_7 -> V_30 -> V_79 , V_76 ) ;
return V_85 ;
}
if ( ! ( V_8 -> V_3 & V_58 ) )
return V_82 ;
F_15 (slave, &pe->slaves, list) {
V_20 = F_38 ( V_7 -> V_21 ,
V_77 -> V_14 ,
& V_81 ,
& V_83 ,
NULL ) ;
if ( V_20 != V_26 ) {
F_13 ( L_12
L_13 ,
V_55 , V_20 ,
V_7 -> V_30 -> V_79 , V_77 -> V_14 ) ;
return V_85 ;
}
if ( V_81 > V_82 )
V_82 = V_81 ;
}
return V_82 ;
}
static struct V_16 * F_39 ( struct V_39 * V_86 )
{
struct V_63 * V_30 = F_40 ( V_86 -> V_47 ) ;
struct V_6 * V_7 = V_30 -> V_87 ;
struct V_88 * V_89 = F_41 ( V_86 ) ;
if ( ! V_89 )
return NULL ;
if ( V_89 -> V_14 == V_12 )
return NULL ;
return & V_7 -> V_9 . V_13 [ V_89 -> V_14 ] ;
}
static int F_42 ( struct V_6 * V_7 , struct V_16 * V_8 )
{
struct V_39 * V_45 ;
T_9 V_90 , V_91 , V_92 ;
long V_20 , V_93 , V_94 ;
if ( V_8 -> V_95 ) {
int V_96 ;
V_91 = V_97 ;
V_92 = V_98 ;
V_45 = V_8 -> V_95 -> V_99 ;
if ( V_8 -> V_3 & V_100 )
V_96 = V_8 -> V_95 -> V_101 . V_35 - V_8 -> V_95 -> V_101 . V_33 + 1 ;
else
V_96 = 1 ;
switch( V_96 ) {
case 1 : V_90 = V_102 ; break;
case 2 : V_90 = V_103 ; break;
case 4 : V_90 = V_104 ; break;
case 8 : V_90 = V_105 ; break;
case 16 : V_90 = V_106 ; break;
case 32 : V_90 = V_107 ; break;
default:
F_43 ( L_14
L_15 ,
F_44 ( V_8 -> V_95 -> V_99 ) , V_96 ) ;
V_90 = V_102 ;
}
V_93 = V_8 -> V_94 + ( V_96 << 8 ) ;
} else {
V_45 = V_8 -> V_15 -> V_47 -> V_99 ;
V_90 = V_102 ;
V_91 = V_108 ;
V_92 = V_109 ;
V_93 = V_8 -> V_94 + 1 ;
}
V_20 = F_45 ( V_7 -> V_21 , V_8 -> V_14 , V_8 -> V_94 ,
V_90 , V_91 , V_92 , V_110 ) ;
if ( V_20 ) {
F_46 ( V_8 , L_16 , V_20 ) ;
return - V_111 ;
}
V_20 = F_47 ( V_7 -> V_21 , V_8 -> V_14 ,
V_8 -> V_14 , V_112 ) ;
if ( V_20 )
F_48 ( V_8 , L_17 , V_20 ) ;
F_36 ( V_7 -> V_21 , V_8 -> V_14 ,
V_113 ) ;
while ( V_45 ) {
struct V_88 * V_89 = F_41 ( V_45 ) ;
if ( V_89 && V_89 -> V_14 != V_12 ) {
V_20 = F_47 ( V_7 -> V_21 , V_89 -> V_14 ,
V_8 -> V_14 , V_112 ) ;
}
V_45 = V_45 -> V_47 -> V_99 ;
}
for ( V_94 = V_8 -> V_94 ; V_94 < V_93 ; V_94 ++ )
V_7 -> V_9 . V_114 [ V_94 ] = V_8 -> V_14 ;
if ( V_7 -> type == V_115 ) {
V_8 -> V_116 = V_8 -> V_14 ;
V_20 = F_49 ( V_7 -> V_21 , V_8 -> V_116 ,
V_8 -> V_14 ) ;
if ( V_20 ) {
F_46 ( V_8 , L_18 ,
V_20 , V_8 -> V_116 ) ;
V_8 -> V_116 = - 1 ;
} else {
V_20 = F_50 ( V_7 -> V_21 ,
V_8 -> V_116 , V_117 ) ;
if ( V_20 ) {
F_46 ( V_8 , L_19 ,
V_20 , V_8 -> V_116 ) ;
V_8 -> V_116 = - 1 ;
}
}
} else if ( V_7 -> type == V_70 )
V_8 -> V_116 = 0 ;
return 0 ;
}
static void F_51 ( struct V_6 * V_7 ,
struct V_16 * V_8 )
{
struct V_16 * V_118 ;
F_15 (lpe, &phb->ioda.pe_dma_list, dma_link) {
if ( V_118 -> V_119 < V_8 -> V_119 ) {
F_26 ( & V_8 -> V_120 , & V_118 -> V_120 ) ;
return;
}
}
F_26 ( & V_8 -> V_120 , & V_7 -> V_9 . V_121 ) ;
}
static unsigned int F_52 ( struct V_39 * V_86 )
{
if ( V_86 -> V_122 != V_123 )
return 0 ;
if ( V_86 -> V_124 == V_125 ||
V_86 -> V_124 == V_126 ||
V_86 -> V_124 == V_127 )
return 3 ;
if ( ( V_86 -> V_124 >> 8 ) == V_128 )
return 15 ;
return 10 ;
}
static void F_53 ( struct V_46 * V_47 , struct V_16 * V_8 )
{
struct V_39 * V_86 ;
F_15 (dev, &bus->devices, bus_list) {
struct V_88 * V_89 = F_41 ( V_86 ) ;
if ( V_89 == NULL ) {
F_13 ( L_20 ,
F_44 ( V_86 ) ) ;
continue;
}
V_89 -> V_129 = V_86 ;
V_89 -> V_14 = V_8 -> V_14 ;
V_8 -> V_119 += F_52 ( V_86 ) ;
if ( ( V_8 -> V_3 & V_100 ) && V_86 -> V_57 )
F_53 ( V_86 -> V_57 , V_8 ) ;
}
}
static void F_54 ( struct V_46 * V_47 , int V_48 )
{
struct V_63 * V_30 = F_40 ( V_47 ) ;
struct V_6 * V_7 = V_30 -> V_87 ;
struct V_16 * V_8 ;
int V_130 = V_12 ;
if ( V_7 -> V_75 )
V_130 = V_7 -> V_75 ( V_7 , V_47 , V_48 ) ;
if ( V_130 == V_12 )
V_130 = F_3 ( V_7 ) ;
if ( V_130 == V_12 ) {
F_55 ( L_21 ,
V_55 , F_56 ( V_47 ) , V_47 -> V_131 ) ;
return;
}
V_8 = & V_7 -> V_9 . V_13 [ V_130 ] ;
V_8 -> V_3 |= ( V_48 ? V_100 : V_132 ) ;
V_8 -> V_95 = V_47 ;
V_8 -> V_15 = NULL ;
V_8 -> V_133 = - 1 ;
V_8 -> V_116 = - 1 ;
V_8 -> V_94 = V_47 -> V_101 . V_33 << 8 ;
V_8 -> V_119 = 0 ;
if ( V_48 )
F_57 ( V_8 , L_22 ,
V_47 -> V_101 . V_33 , V_47 -> V_101 . V_35 , V_130 ) ;
else
F_57 ( V_8 , L_23 ,
V_47 -> V_101 . V_33 , V_130 ) ;
if ( F_42 ( V_7 , V_8 ) ) {
if ( V_130 )
F_6 ( V_7 , V_130 ) ;
V_8 -> V_95 = NULL ;
return;
}
F_53 ( V_47 , V_8 ) ;
F_26 ( & V_8 -> V_62 , & V_7 -> V_9 . V_134 ) ;
if ( V_8 -> V_119 != 0 ) {
V_7 -> V_9 . V_119 += V_8 -> V_119 ;
V_7 -> V_9 . V_135 ++ ;
}
F_51 ( V_7 , V_8 ) ;
}
static void F_58 ( struct V_46 * V_47 )
{
struct V_39 * V_86 ;
F_54 ( V_47 , 0 ) ;
F_15 (dev, &bus->devices, bus_list) {
if ( V_86 -> V_57 ) {
if ( F_59 ( V_86 ) == V_136 )
F_54 ( V_86 -> V_57 , 1 ) ;
else
F_58 ( V_86 -> V_57 ) ;
}
}
}
static void F_60 ( void )
{
struct V_63 * V_30 , * V_137 ;
struct V_6 * V_7 ;
F_61 (hose, tmp, &hose_list, list_node) {
V_7 = V_30 -> V_87 ;
if ( V_7 -> V_74 )
V_7 -> V_74 ( V_7 ) ;
F_58 ( V_30 -> V_47 ) ;
}
}
static void F_62 ( struct V_6 * V_7 , struct V_39 * V_15 )
{
struct V_88 * V_89 = F_41 ( V_15 ) ;
struct V_16 * V_8 ;
if ( ! V_89 || V_89 -> V_14 == V_12 )
return;
V_8 = & V_7 -> V_9 . V_13 [ V_89 -> V_14 ] ;
F_7 ( F_63 ( & V_15 -> V_86 ) != & V_138 ) ;
F_64 ( & V_15 -> V_86 , & V_8 -> V_139 ) ;
}
static int F_65 ( struct V_6 * V_7 ,
struct V_39 * V_15 , T_1 V_140 )
{
struct V_88 * V_89 = F_41 ( V_15 ) ;
struct V_16 * V_8 ;
T_10 V_141 ;
bool V_142 = false ;
if ( F_7 ( ! V_89 || V_89 -> V_14 == V_12 ) )
return - V_143 ; ;
V_8 = & V_7 -> V_9 . V_13 [ V_89 -> V_14 ] ;
if ( V_8 -> V_144 ) {
V_141 = V_8 -> V_145 + F_66 () - 1 ;
V_142 = ( V_140 >= V_141 ) ;
}
if ( V_142 ) {
F_67 ( & V_15 -> V_86 , L_24 ) ;
F_68 ( & V_15 -> V_86 , & V_146 ) ;
F_69 ( & V_15 -> V_86 , V_8 -> V_145 ) ;
} else {
F_67 ( & V_15 -> V_86 , L_25 ) ;
F_68 ( & V_15 -> V_86 , & V_138 ) ;
F_70 ( & V_15 -> V_86 , & V_8 -> V_139 ) ;
}
* V_15 -> V_86 . V_140 = V_140 ;
return 0 ;
}
static void F_71 ( struct V_16 * V_8 ,
struct V_46 * V_47 ,
bool V_147 )
{
struct V_39 * V_86 ;
F_15 (dev, &bus->devices, bus_list) {
if ( V_147 )
F_64 ( & V_86 -> V_86 ,
& V_8 -> V_139 ) ;
else
F_70 ( & V_86 -> V_86 , & V_8 -> V_139 ) ;
if ( V_86 -> V_57 )
F_71 ( V_8 , V_86 -> V_57 ,
V_147 ) ;
}
}
static void F_72 ( struct V_16 * V_8 ,
struct V_148 * V_149 ,
T_11 * V_150 , T_11 * V_151 , bool V_152 )
{
T_11 T_2 * V_153 = V_152 ?
( T_11 T_2 * ) V_8 -> V_154 :
( T_11 T_2 * ) V_149 -> V_155 ;
unsigned long V_33 , V_35 , V_156 ;
const unsigned V_157 = V_149 -> V_158 ;
V_33 = F_73 ( V_150 ) ;
V_35 = F_73 ( V_151 ) ;
if ( V_149 -> V_159 ) {
V_33 <<= V_157 ;
V_35 <<= V_157 ;
V_156 = 128ull << V_157 ;
V_33 |= V_149 -> V_159 ;
V_35 |= V_149 -> V_159 ;
} else if ( V_149 -> V_160 & V_161 ) {
V_33 |= ( 1ull << 63 ) ;
V_35 |= ( 1ull << 63 ) ;
V_156 = 16 ;
} else {
V_156 = 128 ;
}
V_35 |= V_156 - 1 ;
F_74 () ;
while ( V_33 <= V_35 ) {
if ( V_152 )
F_1 ( F_75 ( V_33 ) , V_153 ) ;
else
F_76 ( F_75 ( V_33 ) , V_153 ) ;
V_33 += V_156 ;
}
}
static void F_77 ( struct V_16 * V_8 ,
struct V_148 * V_149 ,
T_11 * V_150 , T_11 * V_151 , bool V_152 )
{
unsigned long V_33 , V_35 , V_156 ;
T_11 T_2 * V_153 = V_152 ?
( T_11 T_2 * ) V_8 -> V_154 :
( T_11 T_2 * ) V_149 -> V_155 ;
const unsigned V_157 = V_149 -> V_158 ;
V_33 = 0x2ull << 60 ;
V_33 |= ( V_8 -> V_14 & 0xFF ) ;
V_35 = V_33 ;
V_156 = V_149 -> V_162 + ( ( ( T_1 ) V_150 - V_149 -> V_163 ) / sizeof( T_1 ) ) ;
V_33 |= ( V_156 << V_157 ) ;
V_156 = V_149 -> V_162 + ( ( ( T_1 ) V_151 - V_149 -> V_163 ) / sizeof( T_1 ) ) ;
V_35 |= ( V_156 << V_157 ) ;
V_156 = ( 0x1ull << V_157 ) ;
F_74 () ;
while ( V_33 <= V_35 ) {
if ( V_152 )
F_1 ( F_75 ( V_33 ) , V_153 ) ;
else
F_76 ( F_75 ( V_33 ) , V_153 ) ;
V_33 += V_156 ;
}
}
void F_78 ( struct V_148 * V_149 ,
T_11 * V_150 , T_11 * V_151 , bool V_152 )
{
struct V_16 * V_8 = F_79 ( V_149 , struct V_16 ,
V_139 ) ;
struct V_6 * V_7 = V_8 -> V_7 ;
if ( V_7 -> type == V_115 )
F_72 ( V_8 , V_149 , V_150 , V_151 , V_152 ) ;
else
F_77 ( V_8 , V_149 , V_150 , V_151 , V_152 ) ;
}
static void F_80 ( struct V_6 * V_7 ,
struct V_16 * V_8 , unsigned int V_40 ,
unsigned int V_164 )
{
struct V_165 * V_166 = NULL ;
const T_11 * V_167 ;
struct V_148 * V_149 ;
unsigned int V_42 ;
T_12 V_20 ;
void * V_168 ;
#define F_81 ((0x10000000 / 0x1000) * 8)
if ( F_7 ( V_8 -> V_133 >= 0 ) )
return;
V_8 -> V_133 = V_40 ;
F_57 ( V_8 , L_26 ,
( V_40 << 28 ) , ( ( V_40 + V_164 ) << 28 ) - 1 ) ;
V_166 = F_82 ( V_7 -> V_30 -> V_169 , V_54 ,
F_83 ( F_81 * V_164 ) ) ;
if ( ! V_166 ) {
F_46 ( V_8 , L_27 ) ;
goto V_27;
}
V_168 = F_84 ( V_166 ) ;
memset ( V_168 , 0 , F_81 * V_164 ) ;
for ( V_42 = 0 ; V_42 < V_164 ; V_42 ++ ) {
V_20 = F_85 ( V_7 -> V_21 ,
V_8 -> V_14 ,
V_40 + V_42 , 1 ,
F_73 ( V_168 ) + F_81 * V_42 ,
F_81 , 0x1000 ) ;
if ( V_20 ) {
F_46 ( V_8 , L_28
L_29 , V_20 ) ;
goto V_27;
}
}
V_149 = & V_8 -> V_139 ;
F_86 ( V_149 , V_168 , F_81 * V_164 ,
V_40 << 28 , V_170 ) ;
V_167 = F_30 ( V_7 -> V_30 -> V_65 , L_30 , NULL ) ;
if ( V_167 ) {
V_8 -> V_154 = F_87 ( V_167 ) ;
V_149 -> V_155 = ( unsigned long ) F_88 ( V_8 -> V_154 ,
8 ) ;
V_149 -> V_160 |= ( V_171 |
V_172 |
V_161 ) ;
}
F_89 ( V_149 , V_7 -> V_30 -> V_169 ) ;
F_90 ( V_149 , V_7 -> V_30 -> V_79 , V_8 -> V_14 ) ;
if ( V_8 -> V_15 )
F_64 ( & V_8 -> V_15 -> V_86 , V_149 ) ;
else
F_71 ( V_8 , V_8 -> V_95 , true ) ;
return;
V_27:
if ( V_8 -> V_133 >= 0 )
V_8 -> V_133 = - 1 ;
if ( V_166 )
F_91 ( V_166 , F_83 ( F_81 * V_164 ) ) ;
}
static void F_92 ( struct V_148 * V_149 , bool V_173 )
{
struct V_16 * V_8 = F_79 ( V_149 , struct V_16 ,
V_139 ) ;
T_13 V_174 = ( V_8 -> V_14 << 1 ) + 1 ;
T_12 V_20 ;
F_57 ( V_8 , L_31 , V_173 ? L_32 : L_33 ) ;
if ( V_173 ) {
T_14 V_141 = F_66 () ;
V_141 = F_93 ( V_141 ) ;
V_20 = F_94 ( V_8 -> V_7 -> V_21 ,
V_8 -> V_14 ,
V_174 ,
V_8 -> V_145 ,
V_141 ) ;
} else {
V_20 = F_94 ( V_8 -> V_7 -> V_21 ,
V_8 -> V_14 ,
V_174 ,
V_8 -> V_145 ,
0 ) ;
if ( V_8 -> V_15 )
F_70 ( & V_8 -> V_15 -> V_86 , V_149 ) ;
else
F_71 ( V_8 , V_8 -> V_95 , false ) ;
}
if ( V_20 )
F_46 ( V_8 , L_34 , V_20 ) ;
else
V_8 -> V_144 = V_173 ;
}
static void F_95 ( struct V_6 * V_7 ,
struct V_16 * V_8 )
{
V_8 -> V_145 = 1ull << 59 ;
V_8 -> V_139 . V_175 = F_92 ;
F_92 ( & V_8 -> V_139 , true ) ;
}
static void F_96 ( struct V_6 * V_7 ,
struct V_16 * V_8 )
{
struct V_165 * V_166 = NULL ;
void * V_168 ;
const T_11 * V_167 ;
struct V_148 * V_149 ;
unsigned int V_176 , V_35 ;
T_12 V_20 ;
if ( F_7 ( V_8 -> V_133 >= 0 ) )
return;
V_8 -> V_133 = 0 ;
V_35 = ( 1 << F_97 ( V_7 -> V_9 . V_177 ) ) ;
V_176 = ( V_35 / 0x1000 ) * 8 ;
F_57 ( V_8 , L_35 ,
V_35 ) ;
V_166 = F_82 ( V_7 -> V_30 -> V_169 , V_54 ,
F_83 ( V_176 ) ) ;
if ( ! V_166 ) {
F_46 ( V_8 , L_36 ) ;
goto V_27;
}
V_168 = F_84 ( V_166 ) ;
memset ( V_168 , 0 , V_176 ) ;
V_20 = F_85 ( V_7 -> V_21 , V_8 -> V_14 ,
V_8 -> V_14 << 1 , 1 , F_73 ( V_168 ) ,
V_176 , 0x1000 ) ;
if ( V_20 ) {
F_46 ( V_8 , L_37
L_29 , V_20 ) ;
goto V_27;
}
V_149 = & V_8 -> V_139 ;
F_86 ( V_149 , V_168 , V_176 , 0 ,
V_170 ) ;
V_167 = F_30 ( V_7 -> V_30 -> V_65 , L_30 , NULL ) ;
if ( V_167 ) {
V_8 -> V_154 = F_87 ( V_167 ) ;
V_149 -> V_155 = ( unsigned long ) F_88 ( V_8 -> V_154 ,
8 ) ;
V_149 -> V_160 |= ( V_171 | V_172 ) ;
}
F_89 ( V_149 , V_7 -> V_30 -> V_169 ) ;
F_90 ( V_149 , V_7 -> V_30 -> V_79 , V_8 -> V_14 ) ;
if ( V_8 -> V_15 )
F_64 ( & V_8 -> V_15 -> V_86 , V_149 ) ;
else
F_71 ( V_8 , V_8 -> V_95 , true ) ;
F_95 ( V_7 , V_8 ) ;
return;
V_27:
if ( V_8 -> V_133 >= 0 )
V_8 -> V_133 = - 1 ;
if ( V_166 )
F_91 ( V_166 , F_83 ( V_176 ) ) ;
}
static void F_98 ( struct V_6 * V_7 )
{
struct V_63 * V_30 = V_7 -> V_30 ;
unsigned int V_178 , V_179 , V_164 , V_180 , V_40 ;
struct V_16 * V_8 ;
if ( V_7 -> V_9 . V_135 > V_7 -> V_9 . V_181 )
V_178 = 0 ;
else
V_178 = V_7 -> V_9 . V_181 -
V_7 -> V_9 . V_135 ;
F_29 ( L_38 ,
V_30 -> V_79 , V_7 -> V_9 . V_181 ) ;
F_29 ( L_39 ,
V_7 -> V_9 . V_135 , V_7 -> V_9 . V_119 ) ;
V_179 = V_7 -> V_9 . V_181 ;
V_180 = V_7 -> V_9 . V_119 ;
V_40 = 0 ;
F_15 (pe, &phb->ioda.pe_dma_list, dma_link) {
if ( ! V_8 -> V_119 )
continue;
if ( ! V_179 ) {
F_48 ( V_8 , L_40 ) ;
continue;
}
V_164 = 1 ;
if ( V_178 ) {
V_164 += ( ( V_8 -> V_119 * V_178 ) + ( V_180 / 2 ) ) / V_180 ;
if ( V_164 > V_179 )
V_164 = V_179 ;
}
if ( V_7 -> type == V_115 ) {
F_57 ( V_8 , L_41 ,
V_8 -> V_119 , V_164 ) ;
F_80 ( V_7 , V_8 , V_40 , V_164 ) ;
} else {
F_57 ( V_8 , L_42 ) ;
V_164 = 0 ;
F_96 ( V_7 , V_8 ) ;
}
V_179 -= V_164 ;
V_40 += V_164 ;
}
}
static void F_99 ( struct V_182 * V_183 )
{
unsigned int V_184 = ( unsigned int ) F_100 ( V_183 ) ;
struct V_185 * V_186 = F_101 ( V_183 ) ;
struct V_6 * V_7 = F_79 ( V_186 , struct V_6 ,
V_9 . V_185 ) ;
T_12 V_20 ;
V_20 = F_102 ( V_7 -> V_21 , V_184 ) ;
F_103 ( V_20 ) ;
F_104 ( V_183 ) ;
}
static int F_105 ( struct V_6 * V_7 , struct V_39 * V_86 ,
unsigned int V_187 , unsigned int V_188 ,
unsigned int V_189 , struct V_190 * V_191 )
{
struct V_16 * V_8 = F_39 ( V_86 ) ;
struct V_88 * V_89 = F_41 ( V_86 ) ;
struct V_182 * V_192 ;
struct V_185 * V_193 ;
unsigned int V_194 = V_187 - V_7 -> V_195 ;
T_15 V_196 ;
int V_20 ;
if ( V_8 == NULL )
return - V_111 ;
if ( V_8 -> V_116 < 0 )
return - V_111 ;
if ( V_89 && V_89 -> V_197 )
V_189 = 0 ;
V_20 = F_106 ( V_7 -> V_21 , V_8 -> V_14 , V_194 ) ;
if ( V_20 ) {
F_13 ( L_43 ,
F_44 ( V_86 ) , V_20 , V_194 ) ;
return - V_37 ;
}
if ( V_189 ) {
T_11 V_198 ;
V_20 = F_107 ( V_7 -> V_21 , V_8 -> V_116 , V_194 , 1 ,
& V_198 , & V_196 ) ;
if ( V_20 ) {
F_13 ( L_44 ,
F_44 ( V_86 ) , V_20 ) ;
return - V_37 ;
}
V_191 -> V_199 = F_108 ( V_198 ) >> 32 ;
V_191 -> V_200 = F_108 ( V_198 ) & 0xfffffffful ;
} else {
T_15 V_201 ;
V_20 = F_109 ( V_7 -> V_21 , V_8 -> V_116 , V_194 , 1 ,
& V_201 , & V_196 ) ;
if ( V_20 ) {
F_13 ( L_45 ,
F_44 ( V_86 ) , V_20 ) ;
return - V_37 ;
}
V_191 -> V_199 = 0 ;
V_191 -> V_200 = F_110 ( V_201 ) ;
}
V_191 -> V_196 = F_110 ( V_196 ) ;
if ( V_7 -> type == V_70 ) {
if ( ! V_7 -> V_9 . V_202 ) {
V_192 = F_111 ( V_188 ) ;
V_193 = F_101 ( V_192 ) ;
V_7 -> V_9 . V_202 = 1 ;
V_7 -> V_9 . V_185 = * V_193 ;
V_7 -> V_9 . V_185 . V_203 = F_99 ;
}
F_112 ( V_188 , & V_7 -> V_9 . V_185 ) ;
}
F_113 ( L_46
L_47 ,
F_44 ( V_86 ) , V_189 ? L_48 : L_49 , V_187 , V_194 ,
V_191 -> V_199 , V_191 -> V_200 , V_196 , V_8 -> V_14 ) ;
return 0 ;
}
static void F_114 ( struct V_6 * V_7 )
{
unsigned int V_96 ;
const T_15 * V_204 = F_30 ( V_7 -> V_30 -> V_65 ,
L_50 , NULL ) ;
if ( ! V_204 ) {
V_204 = F_30 ( V_7 -> V_30 -> V_65 , L_51 , NULL ) ;
}
if ( ! V_204 )
return;
V_7 -> V_195 = F_115 ( V_204 ) ;
V_96 = F_115 ( V_204 + 1 ) ;
if ( F_116 ( & V_7 -> V_205 , V_96 , V_7 -> V_30 -> V_65 ) ) {
F_43 ( L_52 ,
V_7 -> V_30 -> V_79 ) ;
return;
}
V_7 -> V_206 = F_105 ;
V_7 -> V_207 = 1 ;
F_29 ( L_53 ,
V_96 , V_7 -> V_195 ) ;
}
static void F_114 ( struct V_6 * V_7 ) { }
static void F_117 ( struct V_63 * V_30 ,
struct V_16 * V_8 )
{
struct V_6 * V_7 = V_30 -> V_87 ;
struct V_208 V_209 ;
struct V_18 * V_66 ;
int V_42 , V_210 ;
int V_20 ;
F_118 ( ! ( V_8 -> V_3 & ( V_132 | V_100 ) ) ) ;
F_19 (pe->pbus, res, i) {
if ( ! V_66 || ! V_66 -> V_3 ||
V_66 -> V_33 > V_66 -> V_35 )
continue;
if ( V_66 -> V_3 & V_211 ) {
V_209 . V_33 = V_66 -> V_33 - V_7 -> V_9 . V_212 ;
V_209 . V_35 = V_66 -> V_35 - V_7 -> V_9 . V_212 ;
V_210 = V_209 . V_33 / V_7 -> V_9 . V_213 ;
while ( V_210 < V_7 -> V_9 . V_11 &&
V_209 . V_33 <= V_209 . V_35 ) {
V_7 -> V_9 . V_214 [ V_210 ] = V_8 -> V_14 ;
V_20 = F_119 ( V_7 -> V_21 ,
V_8 -> V_14 , V_215 , 0 , V_210 ) ;
if ( V_20 != V_26 ) {
F_43 ( L_54
L_55 ,
V_55 , V_20 , V_210 , V_8 -> V_14 ) ;
break;
}
V_209 . V_33 += V_7 -> V_9 . V_213 ;
V_210 ++ ;
}
} else if ( V_66 -> V_3 & V_71 ) {
V_209 . V_33 = V_66 -> V_33 -
V_30 -> V_72 [ 0 ] -
V_7 -> V_9 . V_177 ;
V_209 . V_35 = V_66 -> V_35 -
V_30 -> V_72 [ 0 ] -
V_7 -> V_9 . V_177 ;
V_210 = V_209 . V_33 / V_7 -> V_9 . V_216 ;
while ( V_210 < V_7 -> V_9 . V_11 &&
V_209 . V_33 <= V_209 . V_35 ) {
V_7 -> V_9 . V_217 [ V_210 ] = V_8 -> V_14 ;
V_20 = F_119 ( V_7 -> V_21 ,
V_8 -> V_14 , V_218 , 0 , V_210 ) ;
if ( V_20 != V_26 ) {
F_43 ( L_56
L_57 ,
V_55 , V_20 , V_210 , V_8 -> V_14 ) ;
break;
}
V_209 . V_33 += V_7 -> V_9 . V_216 ;
V_210 ++ ;
}
}
}
}
static void F_120 ( void )
{
struct V_63 * V_137 , * V_30 ;
struct V_6 * V_7 ;
struct V_16 * V_8 ;
F_61 (hose, tmp, &hose_list, list_node) {
V_7 = V_30 -> V_87 ;
F_15 (pe, &phb->ioda.pe_list, list) {
F_117 ( V_30 , V_8 ) ;
}
}
}
static void F_121 ( void )
{
struct V_63 * V_30 , * V_137 ;
struct V_6 * V_7 ;
F_61 (hose, tmp, &hose_list, list_node) {
F_98 ( V_30 -> V_87 ) ;
V_7 = V_30 -> V_87 ;
V_7 -> V_219 = 1 ;
}
}
static void F_122 ( void )
{
#ifdef F_123
struct V_63 * V_30 , * V_137 ;
struct V_6 * V_7 ;
char V_220 [ 16 ] ;
F_61 (hose, tmp, &hose_list, list_node) {
V_7 = V_30 -> V_87 ;
sprintf ( V_220 , L_58 , V_30 -> V_79 ) ;
V_7 -> V_221 = F_124 ( V_220 , V_222 ) ;
if ( ! V_7 -> V_221 )
F_55 ( L_59 ,
V_55 , V_30 -> V_79 ) ;
}
#endif
}
static void F_125 ( void )
{
F_60 () ;
F_120 () ;
F_121 () ;
F_122 () ;
#ifdef F_126
F_127 () ;
F_128 () ;
#endif
}
static T_4 F_129 ( struct V_46 * V_47 ,
unsigned long type )
{
struct V_39 * V_223 ;
struct V_63 * V_30 = F_40 ( V_47 ) ;
struct V_6 * V_7 = V_30 -> V_87 ;
int V_224 = 0 ;
V_223 = V_47 -> V_99 ;
while ( V_223 ) {
if ( F_59 ( V_223 ) == V_136 ) {
V_224 ++ ;
if ( V_224 >= 2 )
return 1 ;
}
V_223 = V_223 -> V_47 -> V_99 ;
}
if ( V_7 -> V_9 . V_34 &&
F_2 ( type ) )
return V_7 -> V_9 . V_34 ;
if ( type & V_71 )
return V_7 -> V_9 . V_216 ;
return V_7 -> V_9 . V_213 ;
}
static int F_130 ( struct V_39 * V_86 )
{
struct V_63 * V_30 = F_40 ( V_86 -> V_47 ) ;
struct V_6 * V_7 = V_30 -> V_87 ;
struct V_88 * V_89 ;
if ( ! V_7 -> V_219 )
return 0 ;
V_89 = F_41 ( V_86 ) ;
if ( ! V_89 || V_89 -> V_14 == V_12 )
return - V_225 ;
return 0 ;
}
static T_6 F_131 ( struct V_6 * V_7 , struct V_46 * V_47 ,
T_6 V_226 )
{
return V_7 -> V_9 . V_114 [ ( V_47 -> V_131 << 8 ) | V_226 ] ;
}
static void F_132 ( struct V_6 * V_7 )
{
F_133 ( V_7 -> V_21 , V_227 ,
V_228 ) ;
}
void T_5 F_134 ( struct V_64 * V_229 ,
T_1 V_230 , int V_231 )
{
struct V_63 * V_30 ;
struct V_6 * V_7 ;
unsigned long V_51 , V_232 , V_233 , V_234 = 0 ;
const T_11 * V_235 ;
const T_15 * V_236 ;
int V_237 ;
T_1 V_238 ;
void * V_239 ;
long V_20 ;
F_29 ( L_60 , V_231 , V_229 -> V_69 ) ;
V_235 = F_30 ( V_229 , L_61 , NULL ) ;
if ( ! V_235 ) {
F_43 ( L_62 ) ;
return;
}
V_238 = F_87 ( V_235 ) ;
F_135 ( L_63 , V_238 ) ;
V_7 = F_136 ( sizeof( struct V_6 ) ) ;
if ( ! V_7 ) {
F_43 ( L_64 ) ;
return;
}
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
V_7 -> V_30 = V_30 = F_137 ( V_229 ) ;
if ( ! V_7 -> V_30 ) {
F_43 ( L_65 ,
V_229 -> V_69 ) ;
F_138 ( ( unsigned long ) V_7 , sizeof( struct V_6 ) ) ;
return;
}
F_139 ( & V_7 -> V_240 ) ;
V_236 = F_30 ( V_229 , L_66 , & V_237 ) ;
if ( V_236 && V_237 == 8 ) {
V_30 -> V_241 = F_110 ( V_236 [ 0 ] ) ;
V_30 -> V_242 = F_110 ( V_236 [ 1 ] ) ;
} else {
F_13 ( L_67 , V_229 -> V_69 ) ;
V_30 -> V_241 = 0 ;
V_30 -> V_242 = 0xff ;
}
V_30 -> V_87 = V_7 ;
V_7 -> V_230 = V_230 ;
V_7 -> V_21 = V_238 ;
V_7 -> type = V_231 ;
if ( F_140 ( V_229 , L_68 ) )
V_7 -> V_243 = V_244 ;
else if ( F_140 ( V_229 , L_69 ) )
V_7 -> V_243 = V_245 ;
else
V_7 -> V_243 = V_246 ;
F_141 ( V_30 , V_229 , ! V_30 -> V_79 ) ;
V_7 -> V_247 = F_142 ( V_229 , 0 ) ;
if ( V_7 -> V_247 == NULL )
F_43 ( L_70 ) ;
V_7 -> V_9 . V_11 = 1 ;
V_236 = F_30 ( V_229 , L_71 , NULL ) ;
if ( V_236 )
V_7 -> V_9 . V_11 = F_115 ( V_236 ) ;
V_236 = F_30 ( V_229 , L_72 , NULL ) ;
if ( V_236 )
V_7 -> V_9 . V_32 = F_115 ( V_236 ) ;
F_27 ( V_7 ) ;
V_7 -> V_9 . V_248 = F_16 ( & V_30 -> V_31 [ 0 ] ) ;
V_7 -> V_9 . V_248 += 0x10000 ;
V_7 -> V_9 . V_216 = V_7 -> V_9 . V_248 / V_7 -> V_9 . V_11 ;
V_7 -> V_9 . V_177 = V_30 -> V_31 [ 0 ] . V_33 - V_30 -> V_72 [ 0 ] ;
V_7 -> V_9 . V_249 = V_30 -> V_250 ;
V_7 -> V_9 . V_213 = V_7 -> V_9 . V_249 / V_7 -> V_9 . V_11 ;
V_7 -> V_9 . V_212 = 0 ;
V_51 = F_20 ( V_7 -> V_9 . V_11 / 8 , sizeof( unsigned long ) ) ;
V_232 = V_51 ;
V_51 += V_7 -> V_9 . V_11 * sizeof( V_7 -> V_9 . V_217 [ 0 ] ) ;
if ( V_7 -> type == V_115 ) {
V_234 = V_51 ;
V_51 += V_7 -> V_9 . V_11 * sizeof( V_7 -> V_9 . V_214 [ 0 ] ) ;
}
V_233 = V_51 ;
V_51 += V_7 -> V_9 . V_11 * sizeof( struct V_16 ) ;
V_239 = F_136 ( V_51 ) ;
memset ( V_239 , 0 , V_51 ) ;
V_7 -> V_9 . V_10 = V_239 ;
V_7 -> V_9 . V_217 = V_239 + V_232 ;
if ( V_7 -> type == V_115 )
V_7 -> V_9 . V_214 = V_239 + V_234 ;
V_7 -> V_9 . V_13 = V_239 + V_233 ;
F_12 ( V_7 -> V_9 . V_32 , V_7 -> V_9 . V_10 ) ;
F_25 ( & V_7 -> V_9 . V_121 ) ;
F_25 ( & V_7 -> V_9 . V_134 ) ;
V_7 -> V_9 . V_181 = V_7 -> V_9 . V_177 >> 28 ;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
F_29 ( L_73 ,
V_7 -> V_9 . V_11 , V_7 -> V_9 . V_32 ,
V_7 -> V_9 . V_248 , V_7 -> V_9 . V_216 ) ;
if ( V_7 -> V_9 . V_25 )
F_29 ( L_74 ,
V_7 -> V_9 . V_25 , V_7 -> V_9 . V_34 ) ;
if ( V_7 -> V_9 . V_249 )
F_29 ( L_75 ,
V_7 -> V_9 . V_249 , V_7 -> V_9 . V_213 ) ;
V_7 -> V_30 -> V_251 = & V_252 ;
V_7 -> V_253 = F_37 ;
V_7 -> V_254 = F_33 ;
V_7 -> V_255 = F_35 ;
#ifdef F_126
V_7 -> V_256 = & V_257 ;
#endif
V_7 -> V_258 = F_131 ;
V_7 -> V_259 = F_62 ;
V_7 -> V_260 = F_65 ;
V_7 -> V_261 = F_132 ;
F_114 ( V_7 ) ;
V_262 . V_263 = F_125 ;
V_262 . V_264 = F_130 ;
V_262 . V_265 = F_129 ;
V_262 . V_266 = V_267 ;
F_143 ( V_268 ) ;
V_20 = F_133 ( V_238 , V_227 , V_228 ) ;
if ( V_20 )
F_55 ( L_76 , V_20 ) ;
if ( F_144 () ) {
F_29 ( L_77 ) ;
F_145 ( V_30 , V_269 ) ;
F_145 ( V_30 , V_270 ) ;
}
if ( V_7 -> V_73 && V_7 -> V_73 ( V_7 ) )
V_30 -> V_31 [ 1 ] . V_3 = 0 ;
}
void T_5 F_146 ( struct V_64 * V_229 )
{
F_134 ( V_229 , 0 , V_70 ) ;
}
void T_5 F_147 ( struct V_64 * V_229 )
{
struct V_64 * V_271 ;
const T_11 * V_235 ;
T_1 V_230 ;
F_29 ( L_78 , V_229 -> V_69 ) ;
V_235 = F_30 ( V_229 , L_79 , NULL ) ;
if ( ! V_235 ) {
F_43 ( L_80 ) ;
return;
}
V_230 = F_87 ( V_235 ) ;
F_113 ( L_81 , V_230 ) ;
F_148 (np, phbn) {
if ( F_140 ( V_271 , L_82 ) )
F_134 ( V_271 , V_230 , V_115 ) ;
}
}
