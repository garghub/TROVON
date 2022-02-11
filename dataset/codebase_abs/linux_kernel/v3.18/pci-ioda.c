static void F_1 ( const struct V_1 * V_2 , const char * V_3 ,
const char * V_4 , ... )
{
struct V_5 V_6 ;
T_1 args ;
char V_7 [ 32 ] ;
va_start ( args , V_4 ) ;
V_6 . V_4 = V_4 ;
V_6 . V_8 = & args ;
if ( V_2 -> V_9 )
F_2 ( V_7 , F_3 ( & V_2 -> V_9 -> V_10 ) , sizeof( V_7 ) ) ;
else
sprintf ( V_7 , L_1 ,
F_4 ( V_2 -> V_11 ) , V_2 -> V_11 -> V_12 ) ;
F_5 ( L_2 ,
V_3 , V_7 , V_2 -> V_13 , & V_6 ) ;
va_end ( args ) ;
}
static inline void F_6 ( T_2 V_14 , volatile void T_3 * V_15 )
{
__asm__ __volatile__("stdcix %0,0,%1"
: : "r" (val), "r" (paddr) : "memory");
}
static inline bool F_7 ( unsigned long V_16 )
{
return ( ( V_16 & ( V_17 | V_18 ) ) ==
( V_17 | V_18 ) ) ;
}
static int F_8 ( struct V_19 * V_20 )
{
unsigned long V_2 ;
do {
V_2 = F_9 ( V_20 -> V_21 . V_22 ,
V_20 -> V_21 . V_23 , 0 ) ;
if ( V_2 >= V_20 -> V_21 . V_23 )
return V_24 ;
} while( F_10 ( V_2 , V_20 -> V_21 . V_22 ) );
V_20 -> V_21 . V_25 [ V_2 ] . V_20 = V_20 ;
V_20 -> V_21 . V_25 [ V_2 ] . V_13 = V_2 ;
return V_2 ;
}
static void F_11 ( struct V_19 * V_20 , int V_2 )
{
F_12 ( V_20 -> V_21 . V_25 [ V_2 ] . V_9 ) ;
memset ( & V_20 -> V_21 . V_25 [ V_2 ] , 0 , sizeof( struct V_1 ) ) ;
F_13 ( V_2 , V_20 -> V_21 . V_22 ) ;
}
static int F_14 ( struct V_19 * V_20 )
{
const char * V_26 ;
struct V_27 * V_28 ;
T_4 V_29 ;
V_29 = F_15 ( V_20 -> V_30 ,
V_31 ,
V_20 -> V_21 . V_32 ,
V_20 -> V_21 . V_33 ,
0 ,
V_20 -> V_21 . V_34 ) ;
if ( V_29 != V_35 ) {
V_26 = L_3 ;
goto V_36;
}
V_29 = F_16 ( V_20 -> V_30 ,
V_31 ,
V_20 -> V_21 . V_32 ,
V_37 ) ;
if ( V_29 != V_35 ) {
V_26 = L_4 ;
goto V_36;
}
F_17 ( V_20 -> V_21 . V_32 , & V_20 -> V_21 . V_38 ) ;
V_28 = & V_20 -> V_39 -> V_40 [ 1 ] ;
if ( V_20 -> V_21 . V_41 == 0 )
V_28 -> V_42 += V_20 -> V_21 . V_43 ;
else if ( V_20 -> V_21 . V_41 == ( V_20 -> V_21 . V_23 - 1 ) )
V_28 -> V_44 -= V_20 -> V_21 . V_43 ;
else
F_18 ( L_5 ,
V_20 -> V_21 . V_41 ) ;
return 0 ;
V_36:
F_18 ( L_6 ,
V_29 , V_26 , V_20 -> V_21 . V_32 ) ;
F_16 ( V_20 -> V_30 ,
V_31 ,
V_20 -> V_21 . V_32 ,
V_45 ) ;
return - V_46 ;
}
static void F_19 ( struct V_19 * V_20 )
{
T_5 V_47 = V_20 -> V_21 . V_43 ;
struct V_48 * V_9 ;
struct V_27 * V_28 ;
int V_49 , V_50 , V_51 ;
F_20 (pdev, &phb->hose->bus->devices, bus_list) {
for ( V_51 = V_52 ;
V_51 <= V_53 ; V_51 ++ ) {
V_28 = & V_9 -> V_27 [ V_51 ] ;
if ( ! V_28 -> V_54 ||
! F_7 ( V_28 -> V_16 ) )
continue;
V_49 = ( V_28 -> V_42 - V_20 -> V_21 . V_33 ) / V_47 ;
for ( V_50 = 0 ; V_50 < F_21 ( V_28 ) / V_47 ; V_50 ++ )
F_17 ( V_49 + V_50 , V_20 -> V_21 . V_22 ) ;
}
}
}
static int F_22 ( struct V_19 * V_20 ,
struct V_55 * V_56 , int V_57 )
{
T_5 V_58 = V_20 -> V_21 . V_43 ;
struct V_48 * V_9 ;
struct V_27 * V_28 ;
struct V_1 * V_59 , * V_2 ;
unsigned long V_60 , * V_22 ;
bool V_61 ;
int V_42 , V_51 , V_62 ;
if ( F_23 ( V_56 ) )
return V_24 ;
V_61 = false ;
F_24 (bus, r, i) {
if ( V_28 && V_28 -> V_54 &&
F_7 ( V_28 -> V_16 ) ) {
V_61 = true ;
break;
}
}
if ( ! V_61 )
return V_24 ;
V_60 = F_25 ( V_20 -> V_21 . V_23 / 8 , sizeof( unsigned long ) ) ;
V_22 = F_26 ( V_60 , V_63 ) ;
if ( ! V_22 ) {
F_18 ( L_7 ,
V_64 ) ;
return V_24 ;
}
V_42 = ( V_28 -> V_42 - V_20 -> V_21 . V_33 ) / V_58 ;
for ( V_51 = 0 ; V_51 < F_21 ( V_28 ) / V_58 ; V_51 ++ )
F_17 ( V_42 + V_51 , V_22 ) ;
if ( V_57 )
goto V_65;
F_20 (pdev, &bus->devices, bus_list) {
if ( ! V_9 -> V_66 )
continue;
F_24 (pdev->subordinate, r, i) {
if ( ! V_28 || ! V_28 -> V_54 ||
! F_7 ( V_28 -> V_16 ) )
continue;
V_42 = ( V_28 -> V_42 - V_20 -> V_21 . V_33 ) / V_58 ;
for ( V_62 = 0 ; V_62 < F_21 ( V_28 ) / V_58 ; V_62 ++ )
F_13 ( V_42 + V_62 , V_22 ) ;
}
}
if ( F_27 ( V_22 , V_20 -> V_21 . V_23 ) ) {
F_28 ( V_22 ) ;
return V_24 ;
}
V_65:
V_59 = NULL ;
V_51 = - 1 ;
while ( ( V_51 = F_29 ( V_22 , V_20 -> V_21 . V_23 , V_51 + 1 ) ) <
V_20 -> V_21 . V_23 ) {
V_2 = & V_20 -> V_21 . V_25 [ V_51 ] ;
V_2 -> V_20 = V_20 ;
V_2 -> V_13 = V_51 ;
if ( ! V_59 ) {
V_2 -> V_16 |= V_67 ;
F_30 ( & V_2 -> V_68 ) ;
V_59 = V_2 ;
} else {
V_2 -> V_16 |= V_69 ;
V_2 -> V_70 = V_59 ;
F_31 ( & V_2 -> V_71 , & V_59 -> V_68 ) ;
}
}
F_28 ( V_22 ) ;
return V_59 -> V_13 ;
}
static void T_6 F_32 ( struct V_19 * V_20 )
{
struct V_72 * V_39 = V_20 -> V_39 ;
struct V_73 * V_74 = V_39 -> V_74 ;
struct V_27 * V_75 ;
const T_7 * V_28 ;
T_2 V_76 ;
if ( ! F_33 ( V_77 ) ) {
F_34 ( L_8 ) ;
return;
}
V_28 = F_35 ( V_74 , L_9 , NULL ) ;
if ( ! V_28 ) {
F_34 ( L_10 ,
V_74 -> V_78 ) ;
return;
}
if ( V_20 -> type != V_79 ) {
F_34 ( L_11 ) ;
return;
}
V_75 = & V_39 -> V_40 [ 1 ] ;
V_75 -> V_42 = F_36 ( V_74 , V_28 + 2 ) ;
V_75 -> V_44 = V_75 -> V_42 + F_37 ( V_28 + 4 , 2 ) - 1 ;
V_75 -> V_16 = ( V_80 | V_17 | V_18 ) ;
V_76 = F_37 ( V_28 , 2 ) ;
V_39 -> V_81 [ 1 ] = V_75 -> V_42 - V_76 ;
V_20 -> V_21 . V_34 = F_21 ( V_75 ) ;
V_20 -> V_21 . V_43 = V_20 -> V_21 . V_34 / V_20 -> V_21 . V_23 ;
V_20 -> V_21 . V_33 = V_76 ;
V_20 -> V_21 . V_32 = 15 ;
V_20 -> V_82 = F_14 ;
V_20 -> V_83 = F_19 ;
V_20 -> V_84 = F_22 ;
}
static void F_38 ( struct V_19 * V_20 , int V_85 )
{
struct V_1 * V_2 = & V_20 -> V_21 . V_25 [ V_85 ] ;
struct V_1 * V_86 ;
T_4 V_29 ;
if ( V_2 -> V_16 & V_69 ) {
V_2 = V_2 -> V_70 ;
F_12 ( ! V_2 || ! ( V_2 -> V_16 & V_67 ) ) ;
V_85 = V_2 -> V_13 ;
}
V_29 = F_39 ( V_20 -> V_30 ,
V_85 ,
V_87 ) ;
if ( V_29 != V_35 ) {
F_18 ( L_12 ,
V_64 , V_29 , V_20 -> V_39 -> V_88 , V_85 ) ;
return;
}
if ( ! ( V_2 -> V_16 & V_67 ) )
return;
F_20 (slave, &pe->slaves, list) {
V_29 = F_39 ( V_20 -> V_30 ,
V_86 -> V_13 ,
V_87 ) ;
if ( V_29 != V_35 )
F_18 ( L_12 ,
V_64 , V_29 , V_20 -> V_39 -> V_88 ,
V_86 -> V_13 ) ;
}
}
static int F_40 ( struct V_19 * V_20 , int V_85 , int V_89 )
{
struct V_1 * V_2 , * V_86 ;
T_4 V_29 ;
V_2 = & V_20 -> V_21 . V_25 [ V_85 ] ;
if ( V_2 -> V_16 & V_69 ) {
V_2 = V_2 -> V_70 ;
F_12 ( ! V_2 || ! ( V_2 -> V_16 & V_67 ) ) ;
V_85 = V_2 -> V_13 ;
}
V_29 = F_41 ( V_20 -> V_30 , V_85 , V_89 ) ;
if ( V_29 != V_35 ) {
F_18 ( L_13 ,
V_64 , V_29 , V_89 , V_20 -> V_39 -> V_88 , V_85 ) ;
return - V_46 ;
}
if ( ! ( V_2 -> V_16 & V_67 ) )
return 0 ;
F_20 (slave, &pe->slaves, list) {
V_29 = F_41 ( V_20 -> V_30 ,
V_86 -> V_13 ,
V_89 ) ;
if ( V_29 != V_35 ) {
F_18 ( L_13 ,
V_64 , V_29 , V_89 , V_20 -> V_39 -> V_88 ,
V_86 -> V_13 ) ;
return - V_46 ;
}
}
return 0 ;
}
static int F_42 ( struct V_19 * V_20 , int V_85 )
{
struct V_1 * V_86 , * V_2 ;
T_8 V_90 , V_91 ;
T_9 V_92 ;
T_4 V_29 ;
if ( V_85 < 0 || V_85 >= V_20 -> V_21 . V_23 )
return V_93 ;
V_2 = & V_20 -> V_21 . V_25 [ V_85 ] ;
if ( V_2 -> V_16 & V_69 ) {
V_2 = V_2 -> V_70 ;
F_12 ( ! V_2 || ! ( V_2 -> V_16 & V_67 ) ) ;
V_85 = V_2 -> V_13 ;
}
V_29 = F_43 ( V_20 -> V_30 , V_85 ,
& V_91 , & V_92 , NULL ) ;
if ( V_29 != V_35 ) {
F_18 ( L_14
L_15 ,
V_64 , V_29 ,
V_20 -> V_39 -> V_88 , V_85 ) ;
return V_94 ;
}
if ( ! ( V_2 -> V_16 & V_67 ) )
return V_91 ;
F_20 (slave, &pe->slaves, list) {
V_29 = F_43 ( V_20 -> V_30 ,
V_86 -> V_13 ,
& V_90 ,
& V_92 ,
NULL ) ;
if ( V_29 != V_35 ) {
F_18 ( L_14
L_15 ,
V_64 , V_29 ,
V_20 -> V_39 -> V_88 , V_86 -> V_13 ) ;
return V_94 ;
}
if ( V_90 > V_91 )
V_91 = V_90 ;
}
return V_91 ;
}
static struct V_1 * F_44 ( struct V_48 * V_10 )
{
struct V_72 * V_39 = F_45 ( V_10 -> V_56 ) ;
struct V_19 * V_20 = V_39 -> V_95 ;
struct V_96 * V_97 = F_46 ( V_10 ) ;
if ( ! V_97 )
return NULL ;
if ( V_97 -> V_13 == V_24 )
return NULL ;
return & V_20 -> V_21 . V_25 [ V_97 -> V_13 ] ;
}
static int F_47 ( struct V_19 * V_20 , struct V_1 * V_2 )
{
struct V_48 * V_54 ;
T_10 V_98 , V_99 , V_100 ;
long V_29 , V_101 , V_102 ;
if ( V_2 -> V_11 ) {
int V_103 ;
V_99 = V_104 ;
V_100 = V_105 ;
V_54 = V_2 -> V_11 -> V_106 ;
if ( V_2 -> V_16 & V_107 )
V_103 = V_2 -> V_11 -> V_108 . V_44 - V_2 -> V_11 -> V_108 . V_42 + 1 ;
else
V_103 = 1 ;
switch( V_103 ) {
case 1 : V_98 = V_109 ; break;
case 2 : V_98 = V_110 ; break;
case 4 : V_98 = V_111 ; break;
case 8 : V_98 = V_112 ; break;
case 16 : V_98 = V_113 ; break;
case 32 : V_98 = V_114 ; break;
default:
F_48 ( L_16
L_17 ,
F_49 ( V_2 -> V_11 -> V_106 ) , V_103 ) ;
V_98 = V_109 ;
}
V_101 = V_2 -> V_102 + ( V_103 << 8 ) ;
} else {
V_54 = V_2 -> V_9 -> V_56 -> V_106 ;
V_98 = V_109 ;
V_99 = V_115 ;
V_100 = V_116 ;
V_101 = V_2 -> V_102 + 1 ;
}
V_29 = F_50 ( V_20 -> V_30 , V_2 -> V_13 , V_2 -> V_102 ,
V_98 , V_99 , V_100 , V_117 ) ;
if ( V_29 ) {
F_51 ( V_2 , L_18 , V_29 ) ;
return - V_118 ;
}
V_29 = F_52 ( V_20 -> V_30 , V_2 -> V_13 ,
V_2 -> V_13 , V_119 ) ;
if ( V_29 )
F_53 ( V_2 , L_19 , V_29 ) ;
F_41 ( V_20 -> V_30 , V_2 -> V_13 ,
V_120 ) ;
while ( V_54 ) {
struct V_96 * V_97 = F_46 ( V_54 ) ;
if ( V_97 && V_97 -> V_13 != V_24 ) {
V_29 = F_52 ( V_20 -> V_30 , V_97 -> V_13 ,
V_2 -> V_13 , V_119 ) ;
}
V_54 = V_54 -> V_56 -> V_106 ;
}
for ( V_102 = V_2 -> V_102 ; V_102 < V_101 ; V_102 ++ )
V_20 -> V_21 . V_121 [ V_102 ] = V_2 -> V_13 ;
if ( V_20 -> type == V_122 ) {
V_2 -> V_123 = V_2 -> V_13 ;
V_29 = F_54 ( V_20 -> V_30 , V_2 -> V_123 ,
V_2 -> V_13 ) ;
if ( V_29 ) {
F_51 ( V_2 , L_20 ,
V_29 , V_2 -> V_123 ) ;
V_2 -> V_123 = - 1 ;
} else {
V_29 = F_55 ( V_20 -> V_30 ,
V_2 -> V_123 , V_124 ) ;
if ( V_29 ) {
F_51 ( V_2 , L_21 ,
V_29 , V_2 -> V_123 ) ;
V_2 -> V_123 = - 1 ;
}
}
} else if ( V_20 -> type == V_79 )
V_2 -> V_123 = 0 ;
return 0 ;
}
static void F_56 ( struct V_19 * V_20 ,
struct V_1 * V_2 )
{
struct V_1 * V_125 ;
F_20 (lpe, &phb->ioda.pe_dma_list, dma_link) {
if ( V_125 -> V_126 < V_2 -> V_126 ) {
F_31 ( & V_2 -> V_127 , & V_125 -> V_127 ) ;
return;
}
}
F_31 ( & V_2 -> V_127 , & V_20 -> V_21 . V_128 ) ;
}
static unsigned int F_57 ( struct V_48 * V_10 )
{
if ( V_10 -> V_129 != V_130 )
return 0 ;
if ( V_10 -> V_131 == V_132 ||
V_10 -> V_131 == V_133 ||
V_10 -> V_131 == V_134 )
return 3 ;
if ( ( V_10 -> V_131 >> 8 ) == V_135 )
return 15 ;
return 10 ;
}
static void F_58 ( struct V_55 * V_56 , struct V_1 * V_2 )
{
struct V_48 * V_10 ;
F_20 (dev, &bus->devices, bus_list) {
struct V_96 * V_97 = F_46 ( V_10 ) ;
if ( V_97 == NULL ) {
F_18 ( L_22 ,
F_49 ( V_10 ) ) ;
continue;
}
V_97 -> V_136 = V_10 ;
V_97 -> V_13 = V_2 -> V_13 ;
V_2 -> V_126 += F_57 ( V_10 ) ;
if ( ( V_2 -> V_16 & V_107 ) && V_10 -> V_66 )
F_58 ( V_10 -> V_66 , V_2 ) ;
}
}
static void F_59 ( struct V_55 * V_56 , int V_57 )
{
struct V_72 * V_39 = F_45 ( V_56 ) ;
struct V_19 * V_20 = V_39 -> V_95 ;
struct V_1 * V_2 ;
int V_137 = V_24 ;
if ( V_20 -> V_84 )
V_137 = V_20 -> V_84 ( V_20 , V_56 , V_57 ) ;
if ( V_137 == V_24 )
V_137 = F_8 ( V_20 ) ;
if ( V_137 == V_24 ) {
F_60 ( L_23 ,
V_64 , F_4 ( V_56 ) , V_56 -> V_12 ) ;
return;
}
V_2 = & V_20 -> V_21 . V_25 [ V_137 ] ;
V_2 -> V_16 |= ( V_57 ? V_107 : V_138 ) ;
V_2 -> V_11 = V_56 ;
V_2 -> V_9 = NULL ;
V_2 -> V_139 = - 1 ;
V_2 -> V_123 = - 1 ;
V_2 -> V_102 = V_56 -> V_108 . V_42 << 8 ;
V_2 -> V_126 = 0 ;
if ( V_57 )
F_61 ( V_2 , L_24 ,
V_56 -> V_108 . V_42 , V_56 -> V_108 . V_44 , V_137 ) ;
else
F_61 ( V_2 , L_25 ,
V_56 -> V_108 . V_42 , V_137 ) ;
if ( F_47 ( V_20 , V_2 ) ) {
if ( V_137 )
F_11 ( V_20 , V_137 ) ;
V_2 -> V_11 = NULL ;
return;
}
F_58 ( V_56 , V_2 ) ;
F_31 ( & V_2 -> V_71 , & V_20 -> V_21 . V_140 ) ;
if ( V_2 -> V_126 != 0 ) {
V_20 -> V_21 . V_126 += V_2 -> V_126 ;
V_20 -> V_21 . V_141 ++ ;
}
F_56 ( V_20 , V_2 ) ;
}
static void F_62 ( struct V_55 * V_56 )
{
struct V_48 * V_10 ;
F_59 ( V_56 , 0 ) ;
F_20 (dev, &bus->devices, bus_list) {
if ( V_10 -> V_66 ) {
if ( F_63 ( V_10 ) == V_142 )
F_59 ( V_10 -> V_66 , 1 ) ;
else
F_62 ( V_10 -> V_66 ) ;
}
}
}
static void F_64 ( void )
{
struct V_72 * V_39 , * V_143 ;
struct V_19 * V_20 ;
F_65 (hose, tmp, &hose_list, list_node) {
V_20 = V_39 -> V_95 ;
if ( V_20 -> V_83 )
V_20 -> V_83 ( V_20 ) ;
F_62 ( V_39 -> V_56 ) ;
}
}
static void F_66 ( struct V_19 * V_20 , struct V_48 * V_9 )
{
struct V_96 * V_97 = F_46 ( V_9 ) ;
struct V_1 * V_2 ;
if ( ! V_97 || V_97 -> V_13 == V_24 )
return;
V_2 = & V_20 -> V_21 . V_25 [ V_97 -> V_13 ] ;
F_12 ( F_67 ( & V_9 -> V_10 ) != & V_144 ) ;
F_68 ( & V_9 -> V_10 , & V_2 -> V_145 ) ;
}
static int F_69 ( struct V_19 * V_20 ,
struct V_48 * V_9 , T_2 V_146 )
{
struct V_96 * V_97 = F_46 ( V_9 ) ;
struct V_1 * V_2 ;
T_11 V_147 ;
bool V_148 = false ;
if ( F_12 ( ! V_97 || V_97 -> V_13 == V_24 ) )
return - V_149 ; ;
V_2 = & V_20 -> V_21 . V_25 [ V_97 -> V_13 ] ;
if ( V_2 -> V_150 ) {
V_147 = V_2 -> V_151 + F_70 () - 1 ;
V_148 = ( V_146 >= V_147 ) ;
}
if ( V_148 ) {
F_71 ( & V_9 -> V_10 , L_26 ) ;
F_72 ( & V_9 -> V_10 , & V_152 ) ;
F_73 ( & V_9 -> V_10 , V_2 -> V_151 ) ;
} else {
F_71 ( & V_9 -> V_10 , L_27 ) ;
F_72 ( & V_9 -> V_10 , & V_144 ) ;
F_74 ( & V_9 -> V_10 , & V_2 -> V_145 ) ;
}
* V_9 -> V_10 . V_146 = V_146 ;
return 0 ;
}
static T_2 F_75 ( struct V_19 * V_20 ,
struct V_48 * V_9 )
{
struct V_96 * V_97 = F_46 ( V_9 ) ;
struct V_1 * V_2 ;
T_2 V_44 , V_153 ;
if ( F_12 ( ! V_97 || V_97 -> V_13 == V_24 ) )
return 0 ;
V_2 = & V_20 -> V_21 . V_25 [ V_97 -> V_13 ] ;
if ( ! V_2 -> V_150 )
return F_76 ( & V_9 -> V_10 ) ;
V_44 = V_2 -> V_151 + F_70 () ;
V_153 = 1ULL << ( F_77 ( V_44 ) - 1 ) ;
V_153 += V_153 - 1 ;
return V_153 ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
bool V_154 )
{
struct V_48 * V_10 ;
F_20 (dev, &bus->devices, bus_list) {
if ( V_154 )
F_68 ( & V_10 -> V_10 ,
& V_2 -> V_145 ) ;
else
F_74 ( & V_10 -> V_10 , & V_2 -> V_145 ) ;
if ( V_10 -> V_66 )
F_78 ( V_2 , V_10 -> V_66 ,
V_154 ) ;
}
}
static void F_79 ( struct V_1 * V_2 ,
struct V_155 * V_156 ,
T_12 * V_157 , T_12 * V_158 , bool V_159 )
{
T_12 T_3 * V_160 = V_159 ?
( T_12 T_3 * ) V_2 -> V_161 :
( T_12 T_3 * ) V_156 -> V_162 ;
unsigned long V_42 , V_44 , V_163 ;
const unsigned V_164 = V_156 -> V_165 ;
V_42 = F_80 ( V_157 ) ;
V_44 = F_80 ( V_158 ) ;
if ( V_156 -> V_166 ) {
V_42 <<= V_164 ;
V_44 <<= V_164 ;
V_163 = 128ull << V_164 ;
V_42 |= V_156 -> V_166 ;
V_44 |= V_156 -> V_166 ;
} else if ( V_156 -> V_167 & V_168 ) {
V_42 |= ( 1ull << 63 ) ;
V_44 |= ( 1ull << 63 ) ;
V_163 = 16 ;
} else {
V_163 = 128 ;
}
V_44 |= V_163 - 1 ;
F_81 () ;
while ( V_42 <= V_44 ) {
if ( V_159 )
F_6 ( F_82 ( V_42 ) , V_160 ) ;
else
F_83 ( F_82 ( V_42 ) , V_160 ) ;
V_42 += V_163 ;
}
}
static void F_84 ( struct V_1 * V_2 ,
struct V_155 * V_156 ,
T_12 * V_157 , T_12 * V_158 , bool V_159 )
{
unsigned long V_42 , V_44 , V_163 ;
T_12 T_3 * V_160 = V_159 ?
( T_12 T_3 * ) V_2 -> V_161 :
( T_12 T_3 * ) V_156 -> V_162 ;
const unsigned V_164 = V_156 -> V_165 ;
V_42 = 0x2ull << 60 ;
V_42 |= ( V_2 -> V_13 & 0xFF ) ;
V_44 = V_42 ;
V_163 = V_156 -> V_169 + ( ( ( T_2 ) V_157 - V_156 -> V_170 ) / sizeof( T_2 ) ) ;
V_42 |= ( V_163 << V_164 ) ;
V_163 = V_156 -> V_169 + ( ( ( T_2 ) V_158 - V_156 -> V_170 ) / sizeof( T_2 ) ) ;
V_44 |= ( V_163 << V_164 ) ;
V_163 = ( 0x1ull << V_164 ) ;
F_81 () ;
while ( V_42 <= V_44 ) {
if ( V_159 )
F_6 ( F_82 ( V_42 ) , V_160 ) ;
else
F_83 ( F_82 ( V_42 ) , V_160 ) ;
V_42 += V_163 ;
}
}
void F_85 ( struct V_155 * V_156 ,
T_12 * V_157 , T_12 * V_158 , bool V_159 )
{
struct V_1 * V_2 = F_86 ( V_156 , struct V_1 ,
V_145 ) ;
struct V_19 * V_20 = V_2 -> V_20 ;
if ( V_20 -> type == V_122 )
F_79 ( V_2 , V_156 , V_157 , V_158 , V_159 ) ;
else
F_84 ( V_2 , V_156 , V_157 , V_158 , V_159 ) ;
}
static void F_87 ( struct V_19 * V_20 ,
struct V_1 * V_2 , unsigned int V_49 ,
unsigned int V_171 )
{
struct V_172 * V_173 = NULL ;
const T_12 * V_174 ;
struct V_155 * V_156 ;
unsigned int V_51 ;
T_13 V_29 ;
void * V_175 ;
#define F_88 ((0x10000000 / 0x1000) * 8)
if ( F_12 ( V_2 -> V_139 >= 0 ) )
return;
V_2 -> V_139 = V_49 ;
F_61 ( V_2 , L_28 ,
( V_49 << 28 ) , ( ( V_49 + V_171 ) << 28 ) - 1 ) ;
V_173 = F_89 ( V_20 -> V_39 -> V_176 , V_63 ,
F_90 ( F_88 * V_171 ) ) ;
if ( ! V_173 ) {
F_51 ( V_2 , L_29 ) ;
goto V_36;
}
V_175 = F_91 ( V_173 ) ;
memset ( V_175 , 0 , F_88 * V_171 ) ;
for ( V_51 = 0 ; V_51 < V_171 ; V_51 ++ ) {
V_29 = F_92 ( V_20 -> V_30 ,
V_2 -> V_13 ,
V_49 + V_51 , 1 ,
F_80 ( V_175 ) + F_88 * V_51 ,
F_88 , 0x1000 ) ;
if ( V_29 ) {
F_51 ( V_2 , L_30
L_31 , V_29 ) ;
goto V_36;
}
}
V_156 = & V_2 -> V_145 ;
F_93 ( V_156 , V_175 , F_88 * V_171 ,
V_49 << 28 , V_177 ) ;
V_174 = F_35 ( V_20 -> V_39 -> V_74 , L_32 , NULL ) ;
if ( V_174 ) {
V_2 -> V_161 = F_94 ( V_174 ) ;
V_156 -> V_162 = ( unsigned long ) F_95 ( V_2 -> V_161 ,
8 ) ;
V_156 -> V_167 |= ( V_178 |
V_179 |
V_168 ) ;
}
F_96 ( V_156 , V_20 -> V_39 -> V_176 ) ;
F_97 ( V_156 , V_20 -> V_39 -> V_88 , V_2 -> V_13 ) ;
if ( V_2 -> V_9 )
F_68 ( & V_2 -> V_9 -> V_10 , V_156 ) ;
else
F_78 ( V_2 , V_2 -> V_11 , true ) ;
return;
V_36:
if ( V_2 -> V_139 >= 0 )
V_2 -> V_139 = - 1 ;
if ( V_173 )
F_98 ( V_173 , F_90 ( F_88 * V_171 ) ) ;
}
static void F_99 ( struct V_155 * V_156 , bool V_180 )
{
struct V_1 * V_2 = F_86 ( V_156 , struct V_1 ,
V_145 ) ;
T_14 V_181 = ( V_2 -> V_13 << 1 ) + 1 ;
T_13 V_29 ;
F_61 ( V_2 , L_33 , V_180 ? L_34 : L_35 ) ;
if ( V_180 ) {
T_15 V_147 = F_70 () ;
V_147 = F_100 ( V_147 ) ;
V_29 = F_101 ( V_2 -> V_20 -> V_30 ,
V_2 -> V_13 ,
V_181 ,
V_2 -> V_151 ,
V_147 ) ;
} else {
V_29 = F_101 ( V_2 -> V_20 -> V_30 ,
V_2 -> V_13 ,
V_181 ,
V_2 -> V_151 ,
0 ) ;
if ( V_2 -> V_9 )
F_74 ( & V_2 -> V_9 -> V_10 , V_156 ) ;
else
F_78 ( V_2 , V_2 -> V_11 , false ) ;
}
if ( V_29 )
F_51 ( V_2 , L_36 , V_29 ) ;
else
V_2 -> V_150 = V_180 ;
}
static void F_102 ( struct V_19 * V_20 ,
struct V_1 * V_2 )
{
V_2 -> V_151 = 1ull << 59 ;
V_2 -> V_145 . V_182 = F_99 ;
F_99 ( & V_2 -> V_145 , true ) ;
}
static void F_103 ( struct V_19 * V_20 ,
struct V_1 * V_2 )
{
struct V_172 * V_173 = NULL ;
void * V_175 ;
const T_12 * V_174 ;
struct V_155 * V_156 ;
unsigned int V_183 , V_44 ;
T_13 V_29 ;
if ( F_12 ( V_2 -> V_139 >= 0 ) )
return;
V_2 -> V_139 = 0 ;
V_44 = ( 1 << F_104 ( V_20 -> V_21 . V_184 ) ) ;
V_183 = ( V_44 / 0x1000 ) * 8 ;
F_61 ( V_2 , L_37 ,
V_44 ) ;
V_173 = F_89 ( V_20 -> V_39 -> V_176 , V_63 ,
F_90 ( V_183 ) ) ;
if ( ! V_173 ) {
F_51 ( V_2 , L_38 ) ;
goto V_36;
}
V_175 = F_91 ( V_173 ) ;
memset ( V_175 , 0 , V_183 ) ;
V_29 = F_92 ( V_20 -> V_30 , V_2 -> V_13 ,
V_2 -> V_13 << 1 , 1 , F_80 ( V_175 ) ,
V_183 , 0x1000 ) ;
if ( V_29 ) {
F_51 ( V_2 , L_39
L_31 , V_29 ) ;
goto V_36;
}
V_156 = & V_2 -> V_145 ;
F_93 ( V_156 , V_175 , V_183 , 0 ,
V_177 ) ;
V_174 = F_35 ( V_20 -> V_39 -> V_74 , L_32 , NULL ) ;
if ( V_174 ) {
V_2 -> V_161 = F_94 ( V_174 ) ;
V_156 -> V_162 = ( unsigned long ) F_95 ( V_2 -> V_161 ,
8 ) ;
V_156 -> V_167 |= ( V_178 | V_179 ) ;
}
F_96 ( V_156 , V_20 -> V_39 -> V_176 ) ;
F_97 ( V_156 , V_20 -> V_39 -> V_88 , V_2 -> V_13 ) ;
if ( V_2 -> V_9 )
F_68 ( & V_2 -> V_9 -> V_10 , V_156 ) ;
else
F_78 ( V_2 , V_2 -> V_11 , true ) ;
F_102 ( V_20 , V_2 ) ;
return;
V_36:
if ( V_2 -> V_139 >= 0 )
V_2 -> V_139 = - 1 ;
if ( V_173 )
F_98 ( V_173 , F_90 ( V_183 ) ) ;
}
static void F_105 ( struct V_19 * V_20 )
{
struct V_72 * V_39 = V_20 -> V_39 ;
unsigned int V_185 , V_186 , V_171 , V_187 , V_49 ;
struct V_1 * V_2 ;
if ( V_20 -> V_21 . V_141 > V_20 -> V_21 . V_188 )
V_185 = 0 ;
else
V_185 = V_20 -> V_21 . V_188 -
V_20 -> V_21 . V_141 ;
F_34 ( L_40 ,
V_39 -> V_88 , V_20 -> V_21 . V_188 ) ;
F_34 ( L_41 ,
V_20 -> V_21 . V_141 , V_20 -> V_21 . V_126 ) ;
V_186 = V_20 -> V_21 . V_188 ;
V_187 = V_20 -> V_21 . V_126 ;
V_49 = 0 ;
F_20 (pe, &phb->ioda.pe_dma_list, dma_link) {
if ( ! V_2 -> V_126 )
continue;
if ( ! V_186 ) {
F_53 ( V_2 , L_42 ) ;
continue;
}
V_171 = 1 ;
if ( V_185 ) {
V_171 += ( ( V_2 -> V_126 * V_185 ) + ( V_187 / 2 ) ) / V_187 ;
if ( V_171 > V_186 )
V_171 = V_186 ;
}
if ( V_20 -> type == V_122 ) {
F_61 ( V_2 , L_43 ,
V_2 -> V_126 , V_171 ) ;
F_87 ( V_20 , V_2 , V_49 , V_171 ) ;
} else {
F_61 ( V_2 , L_44 ) ;
V_171 = 0 ;
F_103 ( V_20 , V_2 ) ;
}
V_186 -= V_171 ;
V_49 += V_171 ;
}
}
static void F_106 ( struct V_189 * V_190 )
{
unsigned int V_191 = ( unsigned int ) F_107 ( V_190 ) ;
struct V_192 * V_193 = F_108 ( V_190 ) ;
struct V_19 * V_20 = F_86 ( V_193 , struct V_19 ,
V_21 . V_192 ) ;
T_13 V_29 ;
V_29 = F_109 ( V_20 -> V_30 , V_191 ) ;
F_110 ( V_29 ) ;
F_111 ( V_190 ) ;
}
static void F_112 ( struct V_19 * V_20 , unsigned int V_194 )
{
struct V_189 * V_195 ;
struct V_192 * V_196 ;
if ( V_20 -> type != V_79 )
return;
if ( ! V_20 -> V_21 . V_197 ) {
V_195 = F_113 ( V_194 ) ;
V_196 = F_108 ( V_195 ) ;
V_20 -> V_21 . V_197 = 1 ;
V_20 -> V_21 . V_192 = * V_196 ;
V_20 -> V_21 . V_192 . V_198 = F_106 ;
}
F_114 ( V_194 , & V_20 -> V_21 . V_192 ) ;
}
struct V_73 * F_115 ( struct V_48 * V_10 )
{
struct V_72 * V_39 = F_45 ( V_10 -> V_56 ) ;
return V_39 -> V_74 ;
}
int F_116 ( struct V_48 * V_10 )
{
struct V_72 * V_39 = F_45 ( V_10 -> V_56 ) ;
struct V_19 * V_20 = V_39 -> V_95 ;
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_44 ( V_10 ) ;
if ( ! V_2 )
return - V_149 ;
F_61 ( V_2 , L_45 ) ;
V_29 = F_117 ( V_20 -> V_30 , 1 , V_2 -> V_13 ) ;
if ( V_29 )
F_118 ( & V_10 -> V_10 , L_46 , V_29 ) ;
return V_29 ;
}
int F_119 ( struct V_48 * V_10 , int V_199 )
{
struct V_72 * V_39 = F_45 ( V_10 -> V_56 ) ;
struct V_19 * V_20 = V_39 -> V_95 ;
int V_200 = F_120 ( & V_20 -> V_201 , V_199 ) ;
if ( V_200 < 0 ) {
F_121 ( & V_10 -> V_10 , L_47 ) ;
return - V_202 ;
}
return V_20 -> V_203 + V_200 ;
}
void F_122 ( struct V_48 * V_10 , int V_200 , int V_199 )
{
struct V_72 * V_39 = F_45 ( V_10 -> V_56 ) ;
struct V_19 * V_20 = V_39 -> V_95 ;
F_123 ( & V_20 -> V_201 , V_200 - V_20 -> V_203 , V_199 ) ;
}
void F_124 ( struct V_204 * V_205 ,
struct V_48 * V_10 )
{
struct V_72 * V_39 = F_45 ( V_10 -> V_56 ) ;
struct V_19 * V_20 = V_39 -> V_95 ;
int V_51 , V_200 ;
for ( V_51 = 1 ; V_51 < V_206 ; V_51 ++ ) {
if ( ! V_205 -> V_207 [ V_51 ] )
continue;
F_125 ( L_48 ,
V_51 , V_205 -> V_208 [ V_51 ] ,
V_205 -> V_207 [ V_51 ] ) ;
V_200 = V_205 -> V_208 [ V_51 ] - V_20 -> V_203 ;
F_123 ( & V_20 -> V_201 , V_200 ,
V_205 -> V_207 [ V_51 ] ) ;
}
}
int F_126 ( struct V_204 * V_205 ,
struct V_48 * V_10 , int V_199 )
{
struct V_72 * V_39 = F_45 ( V_10 -> V_56 ) ;
struct V_19 * V_20 = V_39 -> V_95 ;
int V_51 , V_200 , V_209 ;
memset ( V_205 , 0 , sizeof( struct V_204 ) ) ;
for ( V_51 = 1 ; V_51 < V_206 && V_199 ; V_51 ++ ) {
V_209 = V_199 ;
while ( V_209 ) {
V_200 = F_120 ( & V_20 -> V_201 , V_209 ) ;
if ( V_200 >= 0 )
break;
V_209 /= 2 ;
}
if ( ! V_209 )
goto V_36;
V_205 -> V_208 [ V_51 ] = V_20 -> V_203 + V_200 ;
V_205 -> V_207 [ V_51 ] = V_209 ;
F_125 ( L_49 ,
V_51 , V_205 -> V_208 [ V_51 ] , V_205 -> V_207 [ V_51 ] ) ;
V_199 -= V_209 ;
}
if ( V_199 )
goto V_36;
return 0 ;
V_36:
F_124 ( V_205 , V_10 ) ;
return - V_202 ;
}
int F_127 ( struct V_48 * V_10 )
{
struct V_72 * V_39 = F_45 ( V_10 -> V_56 ) ;
struct V_19 * V_20 = V_39 -> V_95 ;
return V_20 -> V_201 . V_210 ;
}
int F_128 ( struct V_48 * V_10 , unsigned int V_200 ,
unsigned int V_194 )
{
struct V_72 * V_39 = F_45 ( V_10 -> V_56 ) ;
struct V_19 * V_20 = V_39 -> V_95 ;
unsigned int V_211 = V_200 - V_20 -> V_203 ;
struct V_1 * V_2 ;
int V_29 ;
if ( ! ( V_2 = F_44 ( V_10 ) ) )
return - V_149 ;
V_29 = F_129 ( V_20 -> V_30 , V_2 -> V_13 , V_211 ) ;
if ( V_29 ) {
F_53 ( V_2 , L_50
L_51 ,
F_49 ( V_10 ) , V_29 , V_20 -> V_203 , V_200 , V_211 ) ;
return - V_46 ;
}
F_112 ( V_20 , V_194 ) ;
return 0 ;
}
static int F_130 ( struct V_19 * V_20 , struct V_48 * V_10 ,
unsigned int V_200 , unsigned int V_194 ,
unsigned int V_212 , struct V_213 * V_214 )
{
struct V_1 * V_2 = F_44 ( V_10 ) ;
unsigned int V_211 = V_200 - V_20 -> V_203 ;
T_16 V_215 ;
int V_29 ;
if ( V_2 == NULL )
return - V_118 ;
if ( V_2 -> V_123 < 0 )
return - V_118 ;
if ( V_10 -> V_216 )
V_212 = 0 ;
V_29 = F_129 ( V_20 -> V_30 , V_2 -> V_13 , V_211 ) ;
if ( V_29 ) {
F_18 ( L_52 ,
F_49 ( V_10 ) , V_29 , V_211 ) ;
return - V_46 ;
}
if ( V_212 ) {
T_12 V_217 ;
V_29 = F_131 ( V_20 -> V_30 , V_2 -> V_123 , V_211 , 1 ,
& V_217 , & V_215 ) ;
if ( V_29 ) {
F_18 ( L_53 ,
F_49 ( V_10 ) , V_29 ) ;
return - V_46 ;
}
V_214 -> V_218 = F_132 ( V_217 ) >> 32 ;
V_214 -> V_219 = F_132 ( V_217 ) & 0xfffffffful ;
} else {
T_16 V_220 ;
V_29 = F_133 ( V_20 -> V_30 , V_2 -> V_123 , V_211 , 1 ,
& V_220 , & V_215 ) ;
if ( V_29 ) {
F_18 ( L_54 ,
F_49 ( V_10 ) , V_29 ) ;
return - V_46 ;
}
V_214 -> V_218 = 0 ;
V_214 -> V_219 = F_134 ( V_220 ) ;
}
V_214 -> V_215 = F_134 ( V_215 ) ;
F_112 ( V_20 , V_194 ) ;
F_125 ( L_55
L_56 ,
F_49 ( V_10 ) , V_212 ? L_57 : L_58 , V_200 , V_211 ,
V_214 -> V_218 , V_214 -> V_219 , V_215 , V_2 -> V_13 ) ;
return 0 ;
}
static void F_135 ( struct V_19 * V_20 )
{
unsigned int V_103 ;
const T_16 * V_221 = F_35 ( V_20 -> V_39 -> V_74 ,
L_59 , NULL ) ;
if ( ! V_221 ) {
V_221 = F_35 ( V_20 -> V_39 -> V_74 , L_60 , NULL ) ;
}
if ( ! V_221 )
return;
V_20 -> V_203 = F_136 ( V_221 ) ;
V_103 = F_136 ( V_221 + 1 ) ;
if ( F_137 ( & V_20 -> V_201 , V_103 , V_20 -> V_39 -> V_74 ) ) {
F_48 ( L_61 ,
V_20 -> V_39 -> V_88 ) ;
return;
}
V_20 -> V_222 = F_130 ;
V_20 -> V_223 = 1 ;
F_34 ( L_62 ,
V_103 , V_20 -> V_203 ) ;
}
static void F_135 ( struct V_19 * V_20 ) { }
static void F_138 ( struct V_72 * V_39 ,
struct V_1 * V_2 )
{
struct V_19 * V_20 = V_39 -> V_95 ;
struct V_224 V_225 ;
struct V_27 * V_75 ;
int V_51 , V_226 ;
int V_29 ;
F_139 ( ! ( V_2 -> V_16 & ( V_138 | V_107 ) ) ) ;
F_24 (pe->pbus, res, i) {
if ( ! V_75 || ! V_75 -> V_16 ||
V_75 -> V_42 > V_75 -> V_44 )
continue;
if ( V_75 -> V_16 & V_227 ) {
V_225 . V_42 = V_75 -> V_42 - V_20 -> V_21 . V_228 ;
V_225 . V_44 = V_75 -> V_44 - V_20 -> V_21 . V_228 ;
V_226 = V_225 . V_42 / V_20 -> V_21 . V_229 ;
while ( V_226 < V_20 -> V_21 . V_23 &&
V_225 . V_42 <= V_225 . V_44 ) {
V_20 -> V_21 . V_230 [ V_226 ] = V_2 -> V_13 ;
V_29 = F_140 ( V_20 -> V_30 ,
V_2 -> V_13 , V_231 , 0 , V_226 ) ;
if ( V_29 != V_35 ) {
F_48 ( L_63
L_64 ,
V_64 , V_29 , V_226 , V_2 -> V_13 ) ;
break;
}
V_225 . V_42 += V_20 -> V_21 . V_229 ;
V_226 ++ ;
}
} else if ( V_75 -> V_16 & V_80 ) {
V_225 . V_42 = V_75 -> V_42 -
V_39 -> V_81 [ 0 ] -
V_20 -> V_21 . V_184 ;
V_225 . V_44 = V_75 -> V_44 -
V_39 -> V_81 [ 0 ] -
V_20 -> V_21 . V_184 ;
V_226 = V_225 . V_42 / V_20 -> V_21 . V_232 ;
while ( V_226 < V_20 -> V_21 . V_23 &&
V_225 . V_42 <= V_225 . V_44 ) {
V_20 -> V_21 . V_233 [ V_226 ] = V_2 -> V_13 ;
V_29 = F_140 ( V_20 -> V_30 ,
V_2 -> V_13 , V_234 , 0 , V_226 ) ;
if ( V_29 != V_35 ) {
F_48 ( L_65
L_66 ,
V_64 , V_29 , V_226 , V_2 -> V_13 ) ;
break;
}
V_225 . V_42 += V_20 -> V_21 . V_232 ;
V_226 ++ ;
}
}
}
}
static void F_141 ( void )
{
struct V_72 * V_143 , * V_39 ;
struct V_19 * V_20 ;
struct V_1 * V_2 ;
F_65 (hose, tmp, &hose_list, list_node) {
V_20 = V_39 -> V_95 ;
F_20 (pe, &phb->ioda.pe_list, list) {
F_138 ( V_39 , V_2 ) ;
}
}
}
static void F_142 ( void )
{
struct V_72 * V_39 , * V_143 ;
struct V_19 * V_20 ;
F_65 (hose, tmp, &hose_list, list_node) {
F_105 ( V_39 -> V_95 ) ;
V_20 = V_39 -> V_95 ;
V_20 -> V_235 = 1 ;
}
}
static void F_143 ( void )
{
#ifdef F_144
struct V_72 * V_39 , * V_143 ;
struct V_19 * V_20 ;
char V_236 [ 16 ] ;
F_65 (hose, tmp, &hose_list, list_node) {
V_20 = V_39 -> V_95 ;
sprintf ( V_236 , L_67 , V_39 -> V_88 ) ;
V_20 -> V_237 = F_145 ( V_236 , V_238 ) ;
if ( ! V_20 -> V_237 )
F_60 ( L_68 ,
V_64 , V_39 -> V_88 ) ;
}
#endif
}
static void F_146 ( void )
{
F_64 () ;
F_141 () ;
F_142 () ;
F_143 () ;
#ifdef F_147
F_148 () ;
F_149 () ;
#endif
}
static T_5 F_150 ( struct V_55 * V_56 ,
unsigned long type )
{
struct V_48 * V_239 ;
struct V_72 * V_39 = F_45 ( V_56 ) ;
struct V_19 * V_20 = V_39 -> V_95 ;
int V_240 = 0 ;
V_239 = V_56 -> V_106 ;
while ( V_239 ) {
if ( F_63 ( V_239 ) == V_142 ) {
V_240 ++ ;
if ( V_240 >= 2 )
return 1 ;
}
V_239 = V_239 -> V_56 -> V_106 ;
}
if ( V_20 -> V_21 . V_43 &&
F_7 ( type ) )
return V_20 -> V_21 . V_43 ;
if ( type & V_80 )
return V_20 -> V_21 . V_232 ;
return V_20 -> V_21 . V_229 ;
}
static int F_151 ( struct V_48 * V_10 )
{
struct V_72 * V_39 = F_45 ( V_10 -> V_56 ) ;
struct V_19 * V_20 = V_39 -> V_95 ;
struct V_96 * V_97 ;
if ( ! V_20 -> V_235 )
return 0 ;
V_97 = F_46 ( V_10 ) ;
if ( ! V_97 || V_97 -> V_13 == V_24 )
return - V_241 ;
return 0 ;
}
static T_7 F_152 ( struct V_19 * V_20 , struct V_55 * V_56 ,
T_7 V_242 )
{
return V_20 -> V_21 . V_121 [ ( V_56 -> V_12 << 8 ) | V_242 ] ;
}
static void F_153 ( struct V_19 * V_20 )
{
F_154 ( V_20 -> V_30 , V_243 ,
V_244 ) ;
}
static void T_6 F_155 ( struct V_73 * V_245 ,
T_2 V_246 , int V_247 )
{
struct V_72 * V_39 ;
struct V_19 * V_20 ;
unsigned long V_60 , V_248 , V_249 , V_250 = 0 ;
const T_12 * V_251 ;
const T_16 * V_252 ;
int V_253 ;
T_2 V_254 ;
void * V_255 ;
long V_29 ;
F_34 ( L_69 , V_247 , V_245 -> V_78 ) ;
V_251 = F_35 ( V_245 , L_70 , NULL ) ;
if ( ! V_251 ) {
F_48 ( L_71 ) ;
return;
}
V_254 = F_94 ( V_251 ) ;
F_156 ( L_72 , V_254 ) ;
V_20 = F_157 ( sizeof( struct V_19 ) ) ;
if ( ! V_20 ) {
F_48 ( L_73 ) ;
return;
}
memset ( V_20 , 0 , sizeof( struct V_19 ) ) ;
V_20 -> V_39 = V_39 = F_158 ( V_245 ) ;
if ( ! V_20 -> V_39 ) {
F_48 ( L_74 ,
V_245 -> V_78 ) ;
F_159 ( ( unsigned long ) V_20 , sizeof( struct V_19 ) ) ;
return;
}
F_160 ( & V_20 -> V_256 ) ;
V_252 = F_35 ( V_245 , L_75 , & V_253 ) ;
if ( V_252 && V_253 == 8 ) {
V_39 -> V_257 = F_134 ( V_252 [ 0 ] ) ;
V_39 -> V_258 = F_134 ( V_252 [ 1 ] ) ;
} else {
F_18 ( L_76 , V_245 -> V_78 ) ;
V_39 -> V_257 = 0 ;
V_39 -> V_258 = 0xff ;
}
V_39 -> V_95 = V_20 ;
V_20 -> V_246 = V_246 ;
V_20 -> V_30 = V_254 ;
V_20 -> type = V_247 ;
if ( F_161 ( V_245 , L_77 ) )
V_20 -> V_259 = V_260 ;
else if ( F_161 ( V_245 , L_78 ) )
V_20 -> V_259 = V_261 ;
else
V_20 -> V_259 = V_262 ;
F_162 ( V_39 , V_245 , ! V_39 -> V_88 ) ;
V_20 -> V_263 = F_163 ( V_245 , 0 ) ;
if ( V_20 -> V_263 == NULL )
F_48 ( L_79 ) ;
V_20 -> V_21 . V_23 = 1 ;
V_252 = F_35 ( V_245 , L_80 , NULL ) ;
if ( V_252 )
V_20 -> V_21 . V_23 = F_136 ( V_252 ) ;
V_252 = F_35 ( V_245 , L_81 , NULL ) ;
if ( V_252 )
V_20 -> V_21 . V_41 = F_136 ( V_252 ) ;
F_32 ( V_20 ) ;
V_20 -> V_21 . V_264 = F_21 ( & V_39 -> V_40 [ 0 ] ) ;
V_20 -> V_21 . V_264 += 0x10000 ;
V_20 -> V_21 . V_232 = V_20 -> V_21 . V_264 / V_20 -> V_21 . V_23 ;
V_20 -> V_21 . V_184 = V_39 -> V_40 [ 0 ] . V_42 - V_39 -> V_81 [ 0 ] ;
V_20 -> V_21 . V_265 = V_39 -> V_266 ;
V_20 -> V_21 . V_229 = V_20 -> V_21 . V_265 / V_20 -> V_21 . V_23 ;
V_20 -> V_21 . V_228 = 0 ;
V_60 = F_25 ( V_20 -> V_21 . V_23 / 8 , sizeof( unsigned long ) ) ;
V_248 = V_60 ;
V_60 += V_20 -> V_21 . V_23 * sizeof( V_20 -> V_21 . V_233 [ 0 ] ) ;
if ( V_20 -> type == V_122 ) {
V_250 = V_60 ;
V_60 += V_20 -> V_21 . V_23 * sizeof( V_20 -> V_21 . V_230 [ 0 ] ) ;
}
V_249 = V_60 ;
V_60 += V_20 -> V_21 . V_23 * sizeof( struct V_1 ) ;
V_255 = F_157 ( V_60 ) ;
memset ( V_255 , 0 , V_60 ) ;
V_20 -> V_21 . V_22 = V_255 ;
V_20 -> V_21 . V_233 = V_255 + V_248 ;
if ( V_20 -> type == V_122 )
V_20 -> V_21 . V_230 = V_255 + V_250 ;
V_20 -> V_21 . V_25 = V_255 + V_249 ;
F_17 ( V_20 -> V_21 . V_41 , V_20 -> V_21 . V_22 ) ;
F_30 ( & V_20 -> V_21 . V_128 ) ;
F_30 ( & V_20 -> V_21 . V_140 ) ;
V_20 -> V_21 . V_188 = V_20 -> V_21 . V_184 >> 28 ;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
F_34 ( L_82 ,
V_20 -> V_21 . V_23 , V_20 -> V_21 . V_41 ,
V_20 -> V_21 . V_264 , V_20 -> V_21 . V_232 ) ;
if ( V_20 -> V_21 . V_34 )
F_34 ( L_83 ,
V_20 -> V_21 . V_34 , V_20 -> V_21 . V_43 ) ;
if ( V_20 -> V_21 . V_265 )
F_34 ( L_84 ,
V_20 -> V_21 . V_265 , V_20 -> V_21 . V_229 ) ;
V_20 -> V_39 -> V_267 = & V_268 ;
V_20 -> V_269 = F_42 ;
V_20 -> V_270 = F_38 ;
V_20 -> V_271 = F_40 ;
#ifdef F_147
V_20 -> V_272 = & V_273 ;
#endif
V_20 -> V_274 = F_152 ;
V_20 -> V_275 = F_66 ;
V_20 -> V_276 = F_69 ;
V_20 -> V_277 = F_75 ;
V_20 -> V_278 = F_153 ;
F_135 ( V_20 ) ;
V_279 . V_280 = F_146 ;
V_279 . V_281 = F_151 ;
V_279 . V_282 = F_150 ;
V_279 . V_283 = V_284 ;
F_164 ( V_285 ) ;
V_29 = F_154 ( V_254 , V_243 , V_244 ) ;
if ( V_29 )
F_60 ( L_85 , V_29 ) ;
if ( F_165 () ) {
F_34 ( L_86 ) ;
F_166 ( V_39 , V_286 ) ;
F_166 ( V_39 , V_287 ) ;
}
if ( V_20 -> V_82 && V_20 -> V_82 ( V_20 ) )
V_39 -> V_40 [ 1 ] . V_16 = 0 ;
}
void T_6 F_167 ( struct V_73 * V_245 )
{
F_155 ( V_245 , 0 , V_79 ) ;
}
void T_6 F_168 ( struct V_73 * V_245 )
{
struct V_73 * V_288 ;
const T_12 * V_251 ;
T_2 V_246 ;
F_34 ( L_87 , V_245 -> V_78 ) ;
V_251 = F_35 ( V_245 , L_88 , NULL ) ;
if ( ! V_251 ) {
F_48 ( L_89 ) ;
return;
}
V_246 = F_94 ( V_251 ) ;
F_125 ( L_90 , V_246 ) ;
F_169 (np, phbn) {
if ( F_161 ( V_288 , L_91 ) )
F_155 ( V_288 , V_246 , V_122 ) ;
}
}
