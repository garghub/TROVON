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
static void F_8 ( struct V_19 * V_20 , int V_21 )
{
if ( ! ( V_21 >= 0 && V_21 < V_20 -> V_22 . V_23 ) ) {
F_9 ( L_3 ,
V_24 , V_21 , V_20 -> V_25 -> V_26 ) ;
return;
}
if ( F_10 ( V_21 , V_20 -> V_22 . V_27 ) ) {
F_9 ( L_4 ,
V_24 , V_21 , V_20 -> V_25 -> V_26 ) ;
return;
}
V_20 -> V_22 . V_28 [ V_21 ] . V_20 = V_20 ;
V_20 -> V_22 . V_28 [ V_21 ] . V_13 = V_21 ;
}
static int F_11 ( struct V_19 * V_20 )
{
unsigned long V_2 ;
do {
V_2 = F_12 ( V_20 -> V_22 . V_27 ,
V_20 -> V_22 . V_23 , 0 ) ;
if ( V_2 >= V_20 -> V_22 . V_23 )
return V_29 ;
} while( F_10 ( V_2 , V_20 -> V_22 . V_27 ) );
V_20 -> V_22 . V_28 [ V_2 ] . V_20 = V_20 ;
V_20 -> V_22 . V_28 [ V_2 ] . V_13 = V_2 ;
return V_2 ;
}
static void F_13 ( struct V_19 * V_20 , int V_2 )
{
F_14 ( V_20 -> V_22 . V_28 [ V_2 ] . V_9 ) ;
memset ( & V_20 -> V_22 . V_28 [ V_2 ] , 0 , sizeof( struct V_1 ) ) ;
F_15 ( V_2 , V_20 -> V_22 . V_27 ) ;
}
static int F_16 ( struct V_19 * V_20 )
{
const char * V_30 ;
struct V_31 * V_32 ;
T_4 V_33 ;
V_33 = F_17 ( V_20 -> V_34 ,
V_35 ,
V_20 -> V_22 . V_36 ,
V_20 -> V_22 . V_37 ,
0 ,
V_20 -> V_22 . V_38 ) ;
if ( V_33 != V_39 ) {
V_30 = L_5 ;
goto V_40;
}
V_33 = F_18 ( V_20 -> V_34 ,
V_35 ,
V_20 -> V_22 . V_36 ,
V_41 ) ;
if ( V_33 != V_39 ) {
V_30 = L_6 ;
goto V_40;
}
F_19 ( V_20 -> V_22 . V_36 , & V_20 -> V_22 . V_42 ) ;
V_32 = & V_20 -> V_25 -> V_43 [ 1 ] ;
if ( V_20 -> V_22 . V_44 == 0 )
V_32 -> V_45 += V_20 -> V_22 . V_46 ;
else if ( V_20 -> V_22 . V_44 == ( V_20 -> V_22 . V_23 - 1 ) )
V_32 -> V_47 -= V_20 -> V_22 . V_46 ;
else
F_9 ( L_7 ,
V_20 -> V_22 . V_44 ) ;
return 0 ;
V_40:
F_9 ( L_8 ,
V_33 , V_30 , V_20 -> V_22 . V_36 ) ;
F_18 ( V_20 -> V_34 ,
V_35 ,
V_20 -> V_22 . V_36 ,
V_48 ) ;
return - V_49 ;
}
static void F_20 ( struct V_19 * V_20 )
{
T_5 V_50 = V_20 -> V_22 . V_46 ;
struct V_51 * V_9 ;
struct V_31 * V_32 ;
int V_52 , V_53 , V_54 ;
F_21 (pdev, &phb->hose->bus->devices, bus_list) {
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
V_32 = & V_9 -> V_31 [ V_56 + V_54 ] ;
if ( ! V_32 -> V_57 ||
! F_7 ( V_32 -> V_16 ) )
continue;
V_52 = ( V_32 -> V_45 - V_20 -> V_22 . V_37 ) / V_50 ;
for ( V_53 = 0 ; V_53 < F_22 ( V_32 ) / V_50 ; V_53 ++ )
F_8 ( V_20 , V_52 + V_53 ) ;
}
}
}
static int F_23 ( struct V_19 * V_20 ,
struct V_58 * V_59 , int V_60 )
{
T_5 V_61 = V_20 -> V_22 . V_46 ;
struct V_51 * V_9 ;
struct V_31 * V_32 ;
struct V_1 * V_62 , * V_2 ;
unsigned long V_63 , * V_27 ;
bool V_64 ;
int V_45 , V_54 , V_65 ;
if ( F_24 ( V_59 ) )
return V_29 ;
V_64 = false ;
F_25 (bus, r, i) {
if ( V_32 && V_32 -> V_57 &&
F_7 ( V_32 -> V_16 ) ) {
V_64 = true ;
break;
}
}
if ( ! V_64 )
return V_29 ;
V_63 = F_26 ( V_20 -> V_22 . V_23 / 8 , sizeof( unsigned long ) ) ;
V_27 = F_27 ( V_63 , V_66 ) ;
if ( ! V_27 ) {
F_9 ( L_9 ,
V_24 ) ;
return V_29 ;
}
V_45 = ( V_32 -> V_45 - V_20 -> V_22 . V_37 ) / V_61 ;
for ( V_54 = 0 ; V_54 < F_22 ( V_32 ) / V_61 ; V_54 ++ )
F_19 ( V_45 + V_54 , V_27 ) ;
if ( V_60 )
goto V_67;
F_21 (pdev, &bus->devices, bus_list) {
if ( ! V_9 -> V_68 )
continue;
F_25 (pdev->subordinate, r, i) {
if ( ! V_32 || ! V_32 -> V_57 ||
! F_7 ( V_32 -> V_16 ) )
continue;
V_45 = ( V_32 -> V_45 - V_20 -> V_22 . V_37 ) / V_61 ;
for ( V_65 = 0 ; V_65 < F_22 ( V_32 ) / V_61 ; V_65 ++ )
F_15 ( V_45 + V_65 , V_27 ) ;
}
}
if ( F_28 ( V_27 , V_20 -> V_22 . V_23 ) ) {
F_29 ( V_27 ) ;
return V_29 ;
}
V_67:
V_62 = NULL ;
V_54 = - 1 ;
while ( ( V_54 = F_30 ( V_27 , V_20 -> V_22 . V_23 , V_54 + 1 ) ) <
V_20 -> V_22 . V_23 ) {
V_2 = & V_20 -> V_22 . V_28 [ V_54 ] ;
if ( ! V_62 ) {
V_2 -> V_16 |= V_69 ;
F_31 ( & V_2 -> V_70 ) ;
V_62 = V_2 ;
} else {
V_2 -> V_16 |= V_71 ;
V_2 -> V_72 = V_62 ;
F_32 ( & V_2 -> V_73 , & V_62 -> V_70 ) ;
}
}
F_29 ( V_27 ) ;
return V_62 -> V_13 ;
}
static void T_6 F_33 ( struct V_19 * V_20 )
{
struct V_74 * V_25 = V_20 -> V_25 ;
struct V_75 * V_76 = V_25 -> V_76 ;
struct V_31 * V_77 ;
const T_7 * V_32 ;
T_2 V_78 ;
if ( V_20 -> type != V_79 ) {
F_34 ( L_10 ) ;
return;
}
if ( ! F_35 ( V_80 ) ) {
F_34 ( L_11 ) ;
return;
}
V_32 = F_36 ( V_76 , L_12 , NULL ) ;
if ( ! V_32 ) {
F_34 ( L_13 ,
V_76 -> V_81 ) ;
return;
}
V_77 = & V_25 -> V_43 [ 1 ] ;
V_77 -> V_45 = F_37 ( V_76 , V_32 + 2 ) ;
V_77 -> V_47 = V_77 -> V_45 + F_38 ( V_32 + 4 , 2 ) - 1 ;
V_77 -> V_16 = ( V_82 | V_17 | V_18 ) ;
V_78 = F_38 ( V_32 , 2 ) ;
V_25 -> V_83 [ 1 ] = V_77 -> V_45 - V_78 ;
V_20 -> V_22 . V_38 = F_22 ( V_77 ) ;
V_20 -> V_22 . V_46 = V_20 -> V_22 . V_38 / V_20 -> V_22 . V_23 ;
V_20 -> V_22 . V_37 = V_78 ;
V_20 -> V_22 . V_36 = 15 ;
V_20 -> V_84 = F_16 ;
V_20 -> V_85 = F_20 ;
V_20 -> V_86 = F_23 ;
}
static void F_39 ( struct V_19 * V_20 , int V_21 )
{
struct V_1 * V_2 = & V_20 -> V_22 . V_28 [ V_21 ] ;
struct V_1 * V_87 ;
T_4 V_33 ;
if ( V_2 -> V_16 & V_71 ) {
V_2 = V_2 -> V_72 ;
if ( F_14 ( ! V_2 || ! ( V_2 -> V_16 & V_69 ) ) )
return;
V_21 = V_2 -> V_13 ;
}
V_33 = F_40 ( V_20 -> V_34 ,
V_21 ,
V_88 ) ;
if ( V_33 != V_39 ) {
F_9 ( L_14 ,
V_24 , V_33 , V_20 -> V_25 -> V_26 , V_21 ) ;
return;
}
if ( ! ( V_2 -> V_16 & V_69 ) )
return;
F_21 (slave, &pe->slaves, list) {
V_33 = F_40 ( V_20 -> V_34 ,
V_87 -> V_13 ,
V_88 ) ;
if ( V_33 != V_39 )
F_9 ( L_14 ,
V_24 , V_33 , V_20 -> V_25 -> V_26 ,
V_87 -> V_13 ) ;
}
}
static int F_41 ( struct V_19 * V_20 , int V_21 , int V_89 )
{
struct V_1 * V_2 , * V_87 ;
T_4 V_33 ;
V_2 = & V_20 -> V_22 . V_28 [ V_21 ] ;
if ( V_2 -> V_16 & V_71 ) {
V_2 = V_2 -> V_72 ;
F_14 ( ! V_2 || ! ( V_2 -> V_16 & V_69 ) ) ;
V_21 = V_2 -> V_13 ;
}
V_33 = F_42 ( V_20 -> V_34 , V_21 , V_89 ) ;
if ( V_33 != V_39 ) {
F_9 ( L_15 ,
V_24 , V_33 , V_89 , V_20 -> V_25 -> V_26 , V_21 ) ;
return - V_49 ;
}
if ( ! ( V_2 -> V_16 & V_69 ) )
return 0 ;
F_21 (slave, &pe->slaves, list) {
V_33 = F_42 ( V_20 -> V_34 ,
V_87 -> V_13 ,
V_89 ) ;
if ( V_33 != V_39 ) {
F_9 ( L_15 ,
V_24 , V_33 , V_89 , V_20 -> V_25 -> V_26 ,
V_87 -> V_13 ) ;
return - V_49 ;
}
}
return 0 ;
}
static int F_43 ( struct V_19 * V_20 , int V_21 )
{
struct V_1 * V_87 , * V_2 ;
T_8 V_90 , V_91 ;
T_9 V_92 ;
T_4 V_33 ;
if ( V_21 < 0 || V_21 >= V_20 -> V_22 . V_23 )
return V_93 ;
V_2 = & V_20 -> V_22 . V_28 [ V_21 ] ;
if ( V_2 -> V_16 & V_71 ) {
V_2 = V_2 -> V_72 ;
F_14 ( ! V_2 || ! ( V_2 -> V_16 & V_69 ) ) ;
V_21 = V_2 -> V_13 ;
}
V_33 = F_44 ( V_20 -> V_34 , V_21 ,
& V_91 , & V_92 , NULL ) ;
if ( V_33 != V_39 ) {
F_9 ( L_16
L_17 ,
V_24 , V_33 ,
V_20 -> V_25 -> V_26 , V_21 ) ;
return V_94 ;
}
if ( ! ( V_2 -> V_16 & V_69 ) )
return V_91 ;
F_21 (slave, &pe->slaves, list) {
V_33 = F_44 ( V_20 -> V_34 ,
V_87 -> V_13 ,
& V_90 ,
& V_92 ,
NULL ) ;
if ( V_33 != V_39 ) {
F_9 ( L_16
L_17 ,
V_24 , V_33 ,
V_20 -> V_25 -> V_26 , V_87 -> V_13 ) ;
return V_94 ;
}
if ( V_90 > V_91 )
V_91 = V_90 ;
}
return V_91 ;
}
static struct V_1 * F_45 ( struct V_51 * V_10 )
{
struct V_74 * V_25 = F_46 ( V_10 -> V_59 ) ;
struct V_19 * V_20 = V_25 -> V_95 ;
struct V_96 * V_97 = F_47 ( V_10 ) ;
if ( ! V_97 )
return NULL ;
if ( V_97 -> V_13 == V_29 )
return NULL ;
return & V_20 -> V_22 . V_28 [ V_97 -> V_13 ] ;
}
static int F_48 ( struct V_19 * V_20 ,
struct V_1 * V_57 ,
struct V_1 * V_98 ,
bool V_99 )
{
const char * V_30 = V_99 ? L_18 : L_19 ;
T_10 V_100 = V_99 ? V_101 :
V_102 ;
struct V_1 * V_87 ;
long V_33 ;
V_33 = F_49 ( V_20 -> V_34 , V_57 -> V_13 ,
V_98 -> V_13 , V_100 ) ;
if ( V_33 != V_39 ) {
F_50 ( V_98 , L_20 ,
V_33 , V_30 ) ;
return - V_103 ;
}
if ( ! ( V_98 -> V_16 & V_69 ) )
return 0 ;
F_21 (slave, &child->slaves, list) {
V_33 = F_49 ( V_20 -> V_34 , V_57 -> V_13 ,
V_87 -> V_13 , V_100 ) ;
if ( V_33 != V_39 ) {
F_50 ( V_87 , L_20 ,
V_33 , V_30 ) ;
return - V_103 ;
}
}
return 0 ;
}
static int F_51 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
bool V_99 )
{
struct V_1 * V_87 ;
struct V_51 * V_9 ;
int V_104 ;
if ( V_99 ) {
F_42 ( V_20 -> V_34 , V_2 -> V_13 ,
V_105 ) ;
if ( V_2 -> V_16 & V_69 ) {
F_21 (slave, &pe->slaves, list)
F_42 ( V_20 -> V_34 ,
V_87 -> V_13 ,
V_105 ) ;
}
}
V_104 = F_48 ( V_20 , V_2 , V_2 , V_99 ) ;
if ( V_104 )
return V_104 ;
if ( V_2 -> V_16 & V_69 ) {
F_21 (slave, &pe->slaves, list) {
V_104 = F_48 ( V_20 , V_87 , V_2 , V_99 ) ;
if ( V_104 )
return V_104 ;
}
}
if ( V_2 -> V_16 & ( V_106 | V_107 ) )
V_9 = V_2 -> V_11 -> V_108 ;
else
V_9 = V_2 -> V_9 -> V_59 -> V_108 ;
while ( V_9 ) {
struct V_96 * V_97 = F_47 ( V_9 ) ;
struct V_1 * V_57 ;
if ( V_97 && V_97 -> V_13 != V_29 ) {
V_57 = & V_20 -> V_22 . V_28 [ V_97 -> V_13 ] ;
V_104 = F_48 ( V_20 , V_57 , V_2 , V_99 ) ;
if ( V_104 )
return V_104 ;
}
V_9 = V_9 -> V_59 -> V_108 ;
}
return 0 ;
}
static int F_52 ( struct V_19 * V_20 , struct V_1 * V_2 )
{
struct V_51 * V_57 ;
T_10 V_109 , V_110 , V_111 ;
long V_33 , V_112 , V_113 ;
if ( V_2 -> V_11 ) {
int V_114 ;
V_110 = V_115 ;
V_111 = V_116 ;
V_57 = V_2 -> V_11 -> V_108 ;
if ( V_2 -> V_16 & V_106 )
V_114 = V_2 -> V_11 -> V_117 . V_47 - V_2 -> V_11 -> V_117 . V_45 + 1 ;
else
V_114 = 1 ;
switch( V_114 ) {
case 1 : V_109 = V_118 ; break;
case 2 : V_109 = V_119 ; break;
case 4 : V_109 = V_120 ; break;
case 8 : V_109 = V_121 ; break;
case 16 : V_109 = V_122 ; break;
case 32 : V_109 = V_123 ; break;
default:
F_53 ( L_21
L_22 ,
F_54 ( V_2 -> V_11 -> V_108 ) , V_114 ) ;
V_109 = V_118 ;
}
V_112 = V_2 -> V_113 + ( V_114 << 8 ) ;
} else {
V_57 = V_2 -> V_9 -> V_59 -> V_108 ;
V_109 = V_118 ;
V_110 = V_124 ;
V_111 = V_125 ;
V_112 = V_2 -> V_113 + 1 ;
}
V_33 = F_55 ( V_20 -> V_34 , V_2 -> V_13 , V_2 -> V_113 ,
V_109 , V_110 , V_111 , V_126 ) ;
if ( V_33 ) {
F_56 ( V_2 , L_23 , V_33 ) ;
return - V_103 ;
}
F_51 ( V_20 , V_2 , true ) ;
for ( V_113 = V_2 -> V_113 ; V_113 < V_112 ; V_113 ++ )
V_20 -> V_22 . V_127 [ V_113 ] = V_2 -> V_13 ;
if ( V_20 -> type != V_128 ) {
V_2 -> V_129 = 0 ;
goto V_130;
}
V_2 -> V_129 = V_2 -> V_13 ;
V_33 = F_57 ( V_20 -> V_34 , V_2 -> V_129 , V_2 -> V_13 ) ;
if ( V_33 != V_39 ) {
F_56 ( V_2 , L_24 ,
V_33 , V_2 -> V_129 ) ;
V_2 -> V_129 = - 1 ;
} else {
V_33 = F_58 ( V_20 -> V_34 ,
V_2 -> V_129 , V_131 ) ;
if ( V_33 ) {
F_56 ( V_2 , L_25 ,
V_33 , V_2 -> V_129 ) ;
V_2 -> V_129 = - 1 ;
}
}
V_130:
return 0 ;
}
static void F_59 ( struct V_19 * V_20 ,
struct V_1 * V_2 )
{
struct V_1 * V_132 ;
F_21 (lpe, &phb->ioda.pe_dma_list, dma_link) {
if ( V_132 -> V_133 < V_2 -> V_133 ) {
F_32 ( & V_2 -> V_134 , & V_132 -> V_134 ) ;
return;
}
}
F_32 ( & V_2 -> V_134 , & V_20 -> V_22 . V_135 ) ;
}
static unsigned int F_60 ( struct V_51 * V_10 )
{
if ( V_10 -> V_136 != V_137 )
return 0 ;
if ( V_10 -> V_138 == V_139 ||
V_10 -> V_138 == V_140 ||
V_10 -> V_138 == V_141 )
return 3 ;
if ( ( V_10 -> V_138 >> 8 ) == V_142 )
return 15 ;
return 10 ;
}
static void F_61 ( struct V_58 * V_59 , struct V_1 * V_2 )
{
struct V_51 * V_10 ;
F_21 (dev, &bus->devices, bus_list) {
struct V_96 * V_97 = F_47 ( V_10 ) ;
if ( V_97 == NULL ) {
F_9 ( L_26 ,
F_54 ( V_10 ) ) ;
continue;
}
V_97 -> V_143 = V_10 ;
V_97 -> V_13 = V_2 -> V_13 ;
V_2 -> V_133 += F_60 ( V_10 ) ;
if ( ( V_2 -> V_16 & V_106 ) && V_10 -> V_68 )
F_61 ( V_10 -> V_68 , V_2 ) ;
}
}
static void F_62 ( struct V_58 * V_59 , int V_60 )
{
struct V_74 * V_25 = F_46 ( V_59 ) ;
struct V_19 * V_20 = V_25 -> V_95 ;
struct V_1 * V_2 ;
int V_144 = V_29 ;
if ( V_20 -> V_86 )
V_144 = V_20 -> V_86 ( V_20 , V_59 , V_60 ) ;
if ( V_144 == V_29 )
V_144 = F_11 ( V_20 ) ;
if ( V_144 == V_29 ) {
F_63 ( L_27 ,
V_24 , F_4 ( V_59 ) , V_59 -> V_12 ) ;
return;
}
V_2 = & V_20 -> V_22 . V_28 [ V_144 ] ;
V_2 -> V_16 |= ( V_60 ? V_106 : V_107 ) ;
V_2 -> V_11 = V_59 ;
V_2 -> V_9 = NULL ;
V_2 -> V_145 = - 1 ;
V_2 -> V_129 = - 1 ;
V_2 -> V_113 = V_59 -> V_117 . V_45 << 8 ;
V_2 -> V_133 = 0 ;
if ( V_60 )
F_64 ( V_2 , L_28 ,
V_59 -> V_117 . V_45 , V_59 -> V_117 . V_47 , V_144 ) ;
else
F_64 ( V_2 , L_29 ,
V_59 -> V_117 . V_45 , V_144 ) ;
if ( F_52 ( V_20 , V_2 ) ) {
if ( V_144 )
F_13 ( V_20 , V_144 ) ;
V_2 -> V_11 = NULL ;
return;
}
F_61 ( V_59 , V_2 ) ;
F_32 ( & V_2 -> V_73 , & V_20 -> V_22 . V_146 ) ;
if ( V_2 -> V_133 != 0 ) {
V_20 -> V_22 . V_133 += V_2 -> V_133 ;
V_20 -> V_22 . V_147 ++ ;
}
F_59 ( V_20 , V_2 ) ;
}
static void F_65 ( struct V_58 * V_59 )
{
struct V_51 * V_10 ;
F_62 ( V_59 , 0 ) ;
F_21 (dev, &bus->devices, bus_list) {
if ( V_10 -> V_68 ) {
if ( F_66 ( V_10 ) == V_148 )
F_62 ( V_10 -> V_68 , 1 ) ;
else
F_65 ( V_10 -> V_68 ) ;
}
}
}
static void F_67 ( void )
{
struct V_74 * V_25 , * V_149 ;
struct V_19 * V_20 ;
F_68 (hose, tmp, &hose_list, list_node) {
V_20 = V_25 -> V_95 ;
if ( V_20 -> V_85 )
V_20 -> V_85 ( V_20 ) ;
F_65 ( V_25 -> V_59 ) ;
}
}
static void F_69 ( struct V_19 * V_20 , struct V_51 * V_9 )
{
struct V_96 * V_97 = F_47 ( V_9 ) ;
struct V_1 * V_2 ;
if ( ! V_97 || V_97 -> V_13 == V_29 )
return;
V_2 = & V_20 -> V_22 . V_28 [ V_97 -> V_13 ] ;
F_14 ( F_70 ( & V_9 -> V_10 ) != & V_150 ) ;
F_71 ( & V_9 -> V_10 , & V_2 -> V_151 ) ;
}
static int F_72 ( struct V_19 * V_20 ,
struct V_51 * V_9 , T_2 V_152 )
{
struct V_96 * V_97 = F_47 ( V_9 ) ;
struct V_1 * V_2 ;
T_11 V_153 ;
bool V_154 = false ;
if ( F_14 ( ! V_97 || V_97 -> V_13 == V_29 ) )
return - V_155 ; ;
V_2 = & V_20 -> V_22 . V_28 [ V_97 -> V_13 ] ;
if ( V_2 -> V_156 ) {
V_153 = V_2 -> V_157 + F_73 () - 1 ;
V_154 = ( V_152 >= V_153 ) ;
}
if ( V_154 ) {
F_74 ( & V_9 -> V_10 , L_30 ) ;
F_75 ( & V_9 -> V_10 , & V_158 ) ;
F_76 ( & V_9 -> V_10 , V_2 -> V_157 ) ;
} else {
F_74 ( & V_9 -> V_10 , L_31 ) ;
F_75 ( & V_9 -> V_10 , & V_150 ) ;
F_77 ( & V_9 -> V_10 , & V_2 -> V_151 ) ;
}
* V_9 -> V_10 . V_152 = V_152 ;
return 0 ;
}
static T_2 F_78 ( struct V_19 * V_20 ,
struct V_51 * V_9 )
{
struct V_96 * V_97 = F_47 ( V_9 ) ;
struct V_1 * V_2 ;
T_2 V_47 , V_159 ;
if ( F_14 ( ! V_97 || V_97 -> V_13 == V_29 ) )
return 0 ;
V_2 = & V_20 -> V_22 . V_28 [ V_97 -> V_13 ] ;
if ( ! V_2 -> V_156 )
return F_79 ( & V_9 -> V_10 ) ;
V_47 = V_2 -> V_157 + F_73 () ;
V_159 = 1ULL << ( F_80 ( V_47 ) - 1 ) ;
V_159 += V_159 - 1 ;
return V_159 ;
}
static void F_81 ( struct V_1 * V_2 ,
struct V_58 * V_59 ,
bool V_160 )
{
struct V_51 * V_10 ;
F_21 (dev, &bus->devices, bus_list) {
if ( V_160 )
F_71 ( & V_10 -> V_10 ,
& V_2 -> V_151 ) ;
else
F_77 ( & V_10 -> V_10 , & V_2 -> V_151 ) ;
if ( V_10 -> V_68 )
F_81 ( V_2 , V_10 -> V_68 ,
V_160 ) ;
}
}
static void F_82 ( struct V_1 * V_2 ,
struct V_161 * V_162 ,
T_12 * V_163 , T_12 * V_164 , bool V_165 )
{
T_12 T_3 * V_166 = V_165 ?
( T_12 T_3 * ) V_2 -> V_167 :
( T_12 T_3 * ) V_162 -> V_168 ;
unsigned long V_45 , V_47 , V_169 ;
const unsigned V_170 = V_162 -> V_171 ;
V_45 = F_83 ( V_163 ) ;
V_47 = F_83 ( V_164 ) ;
if ( V_162 -> V_172 ) {
V_45 <<= V_170 ;
V_47 <<= V_170 ;
V_169 = 128ull << V_170 ;
V_45 |= V_162 -> V_172 ;
V_47 |= V_162 -> V_172 ;
} else if ( V_162 -> V_173 & V_174 ) {
V_45 |= ( 1ull << 63 ) ;
V_47 |= ( 1ull << 63 ) ;
V_169 = 16 ;
} else {
V_169 = 128 ;
}
V_47 |= V_169 - 1 ;
F_84 () ;
while ( V_45 <= V_47 ) {
if ( V_165 )
F_6 ( F_85 ( V_45 ) , V_166 ) ;
else
F_86 ( F_85 ( V_45 ) , V_166 ) ;
V_45 += V_169 ;
}
}
static void F_87 ( struct V_1 * V_2 ,
struct V_161 * V_162 ,
T_12 * V_163 , T_12 * V_164 , bool V_165 )
{
unsigned long V_45 , V_47 , V_169 ;
T_12 T_3 * V_166 = V_165 ?
( T_12 T_3 * ) V_2 -> V_167 :
( T_12 T_3 * ) V_162 -> V_168 ;
const unsigned V_170 = V_162 -> V_171 ;
V_45 = 0x2ull << 60 ;
V_45 |= ( V_2 -> V_13 & 0xFF ) ;
V_47 = V_45 ;
V_169 = V_162 -> V_175 + ( ( ( T_2 ) V_163 - V_162 -> V_176 ) / sizeof( T_2 ) ) ;
V_45 |= ( V_169 << V_170 ) ;
V_169 = V_162 -> V_175 + ( ( ( T_2 ) V_164 - V_162 -> V_176 ) / sizeof( T_2 ) ) ;
V_47 |= ( V_169 << V_170 ) ;
V_169 = ( 0x1ull << V_170 ) ;
F_84 () ;
while ( V_45 <= V_47 ) {
if ( V_165 )
F_6 ( F_85 ( V_45 ) , V_166 ) ;
else
F_86 ( F_85 ( V_45 ) , V_166 ) ;
V_45 += V_169 ;
}
}
void F_88 ( struct V_161 * V_162 ,
T_12 * V_163 , T_12 * V_164 , bool V_165 )
{
struct V_1 * V_2 = F_89 ( V_162 , struct V_1 ,
V_151 ) ;
struct V_19 * V_20 = V_2 -> V_20 ;
if ( V_20 -> type == V_128 )
F_82 ( V_2 , V_162 , V_163 , V_164 , V_165 ) ;
else
F_87 ( V_2 , V_162 , V_163 , V_164 , V_165 ) ;
}
static void F_90 ( struct V_19 * V_20 ,
struct V_1 * V_2 , unsigned int V_52 ,
unsigned int V_177 )
{
struct V_178 * V_179 = NULL ;
const T_12 * V_180 ;
struct V_161 * V_162 ;
unsigned int V_54 ;
T_13 V_33 ;
void * V_181 ;
#define F_91 ((0x10000000 / 0x1000) * 8)
if ( F_14 ( V_2 -> V_145 >= 0 ) )
return;
V_2 -> V_145 = V_52 ;
F_64 ( V_2 , L_32 ,
( V_52 << 28 ) , ( ( V_52 + V_177 ) << 28 ) - 1 ) ;
V_179 = F_92 ( V_20 -> V_25 -> V_182 , V_66 ,
F_93 ( F_91 * V_177 ) ) ;
if ( ! V_179 ) {
F_56 ( V_2 , L_33 ) ;
goto V_40;
}
V_181 = F_94 ( V_179 ) ;
memset ( V_181 , 0 , F_91 * V_177 ) ;
for ( V_54 = 0 ; V_54 < V_177 ; V_54 ++ ) {
V_33 = F_95 ( V_20 -> V_34 ,
V_2 -> V_13 ,
V_52 + V_54 , 1 ,
F_83 ( V_181 ) + F_91 * V_54 ,
F_91 , 0x1000 ) ;
if ( V_33 ) {
F_56 ( V_2 , L_34
L_35 , V_33 ) ;
goto V_40;
}
}
V_162 = & V_2 -> V_151 ;
F_96 ( V_162 , V_181 , F_91 * V_177 ,
V_52 << 28 , V_183 ) ;
V_180 = F_36 ( V_20 -> V_25 -> V_76 , L_36 , NULL ) ;
if ( V_180 ) {
V_2 -> V_167 = F_97 ( V_180 ) ;
V_162 -> V_168 = ( unsigned long ) F_98 ( V_2 -> V_167 ,
8 ) ;
V_162 -> V_173 |= ( V_184 |
V_185 |
V_174 ) ;
}
F_99 ( V_162 , V_20 -> V_25 -> V_182 ) ;
F_100 ( V_162 , V_20 -> V_25 -> V_26 , V_2 -> V_13 ) ;
if ( V_2 -> V_9 )
F_71 ( & V_2 -> V_9 -> V_10 , V_162 ) ;
else
F_81 ( V_2 , V_2 -> V_11 , true ) ;
return;
V_40:
if ( V_2 -> V_145 >= 0 )
V_2 -> V_145 = - 1 ;
if ( V_179 )
F_101 ( V_179 , F_93 ( F_91 * V_177 ) ) ;
}
static void F_102 ( struct V_161 * V_162 , bool V_186 )
{
struct V_1 * V_2 = F_89 ( V_162 , struct V_1 ,
V_151 ) ;
T_14 V_187 = ( V_2 -> V_13 << 1 ) + 1 ;
T_13 V_33 ;
F_64 ( V_2 , L_37 , V_186 ? L_38 : L_39 ) ;
if ( V_186 ) {
T_15 V_153 = F_73 () ;
V_153 = F_103 ( V_153 ) ;
V_33 = F_104 ( V_2 -> V_20 -> V_34 ,
V_2 -> V_13 ,
V_187 ,
V_2 -> V_157 ,
V_153 ) ;
} else {
V_33 = F_104 ( V_2 -> V_20 -> V_34 ,
V_2 -> V_13 ,
V_187 ,
V_2 -> V_157 ,
0 ) ;
if ( V_2 -> V_9 )
F_77 ( & V_2 -> V_9 -> V_10 , V_162 ) ;
else
F_81 ( V_2 , V_2 -> V_11 , false ) ;
}
if ( V_33 )
F_56 ( V_2 , L_40 , V_33 ) ;
else
V_2 -> V_156 = V_186 ;
}
static void F_105 ( struct V_19 * V_20 ,
struct V_1 * V_2 )
{
V_2 -> V_157 = 1ull << 59 ;
V_2 -> V_151 . V_188 = F_102 ;
F_102 ( & V_2 -> V_151 , true ) ;
}
static void F_106 ( struct V_19 * V_20 ,
struct V_1 * V_2 )
{
struct V_178 * V_179 = NULL ;
void * V_181 ;
const T_12 * V_180 ;
struct V_161 * V_162 ;
unsigned int V_189 , V_47 ;
T_13 V_33 ;
if ( F_14 ( V_2 -> V_145 >= 0 ) )
return;
V_2 -> V_145 = 0 ;
V_47 = ( 1 << F_107 ( V_20 -> V_22 . V_190 ) ) ;
V_189 = ( V_47 / 0x1000 ) * 8 ;
F_64 ( V_2 , L_41 ,
V_47 ) ;
V_179 = F_92 ( V_20 -> V_25 -> V_182 , V_66 ,
F_93 ( V_189 ) ) ;
if ( ! V_179 ) {
F_56 ( V_2 , L_42 ) ;
goto V_40;
}
V_181 = F_94 ( V_179 ) ;
memset ( V_181 , 0 , V_189 ) ;
V_33 = F_95 ( V_20 -> V_34 , V_2 -> V_13 ,
V_2 -> V_13 << 1 , 1 , F_83 ( V_181 ) ,
V_189 , 0x1000 ) ;
if ( V_33 ) {
F_56 ( V_2 , L_43
L_35 , V_33 ) ;
goto V_40;
}
V_162 = & V_2 -> V_151 ;
F_96 ( V_162 , V_181 , V_189 , 0 ,
V_183 ) ;
V_180 = F_36 ( V_20 -> V_25 -> V_76 , L_36 , NULL ) ;
if ( V_180 ) {
V_2 -> V_167 = F_97 ( V_180 ) ;
V_162 -> V_168 = ( unsigned long ) F_98 ( V_2 -> V_167 ,
8 ) ;
V_162 -> V_173 |= ( V_184 | V_185 ) ;
}
F_99 ( V_162 , V_20 -> V_25 -> V_182 ) ;
F_100 ( V_162 , V_20 -> V_25 -> V_26 , V_2 -> V_13 ) ;
if ( V_2 -> V_9 )
F_71 ( & V_2 -> V_9 -> V_10 , V_162 ) ;
else
F_81 ( V_2 , V_2 -> V_11 , true ) ;
F_105 ( V_20 , V_2 ) ;
return;
V_40:
if ( V_2 -> V_145 >= 0 )
V_2 -> V_145 = - 1 ;
if ( V_179 )
F_101 ( V_179 , F_93 ( V_189 ) ) ;
}
static void F_108 ( struct V_19 * V_20 )
{
struct V_74 * V_25 = V_20 -> V_25 ;
unsigned int V_191 , V_192 , V_177 , V_193 , V_52 ;
struct V_1 * V_2 ;
if ( V_20 -> V_22 . V_147 > V_20 -> V_22 . V_194 )
V_191 = 0 ;
else
V_191 = V_20 -> V_22 . V_194 -
V_20 -> V_22 . V_147 ;
F_34 ( L_44 ,
V_25 -> V_26 , V_20 -> V_22 . V_194 ) ;
F_34 ( L_45 ,
V_20 -> V_22 . V_147 , V_20 -> V_22 . V_133 ) ;
V_192 = V_20 -> V_22 . V_194 ;
V_193 = V_20 -> V_22 . V_133 ;
V_52 = 0 ;
F_21 (pe, &phb->ioda.pe_dma_list, dma_link) {
if ( ! V_2 -> V_133 )
continue;
if ( ! V_192 ) {
F_50 ( V_2 , L_46 ) ;
continue;
}
V_177 = 1 ;
if ( V_191 ) {
V_177 += ( ( V_2 -> V_133 * V_191 ) + ( V_193 / 2 ) ) / V_193 ;
if ( V_177 > V_192 )
V_177 = V_192 ;
}
if ( V_20 -> type == V_128 ) {
F_64 ( V_2 , L_47 ,
V_2 -> V_133 , V_177 ) ;
F_90 ( V_20 , V_2 , V_52 , V_177 ) ;
} else {
F_64 ( V_2 , L_48 ) ;
V_177 = 0 ;
F_106 ( V_20 , V_2 ) ;
}
V_192 -= V_177 ;
V_52 += V_177 ;
}
}
static void F_109 ( struct V_195 * V_196 )
{
unsigned int V_197 = ( unsigned int ) F_110 ( V_196 ) ;
struct V_198 * V_199 = F_111 ( V_196 ) ;
struct V_19 * V_20 = F_89 ( V_199 , struct V_19 ,
V_22 . V_198 ) ;
T_13 V_33 ;
V_33 = F_112 ( V_20 -> V_34 , V_197 ) ;
F_113 ( V_33 ) ;
F_114 ( V_196 ) ;
}
static void F_115 ( struct V_19 * V_20 , unsigned int V_200 )
{
struct V_195 * V_201 ;
struct V_198 * V_202 ;
if ( V_20 -> type != V_79 )
return;
if ( ! V_20 -> V_22 . V_203 ) {
V_201 = F_116 ( V_200 ) ;
V_202 = F_111 ( V_201 ) ;
V_20 -> V_22 . V_203 = 1 ;
V_20 -> V_22 . V_198 = * V_202 ;
V_20 -> V_22 . V_198 . V_204 = F_109 ;
}
F_117 ( V_200 , & V_20 -> V_22 . V_198 ) ;
}
struct V_75 * F_118 ( struct V_51 * V_10 )
{
struct V_74 * V_25 = F_46 ( V_10 -> V_59 ) ;
return V_25 -> V_76 ;
}
int F_119 ( struct V_51 * V_10 )
{
struct V_74 * V_25 = F_46 ( V_10 -> V_59 ) ;
struct V_19 * V_20 = V_25 -> V_95 ;
struct V_1 * V_2 ;
int V_33 ;
V_2 = F_45 ( V_10 ) ;
if ( ! V_2 )
return - V_155 ;
F_64 ( V_2 , L_49 ) ;
V_33 = F_120 ( V_20 -> V_34 , 1 , V_2 -> V_13 ) ;
if ( V_33 )
F_121 ( & V_10 -> V_10 , L_50 , V_33 ) ;
return V_33 ;
}
int F_122 ( struct V_51 * V_10 , int V_205 )
{
struct V_74 * V_25 = F_46 ( V_10 -> V_59 ) ;
struct V_19 * V_20 = V_25 -> V_95 ;
int V_206 = F_123 ( & V_20 -> V_207 , V_205 ) ;
if ( V_206 < 0 ) {
F_124 ( & V_10 -> V_10 , L_51 ) ;
return - V_208 ;
}
return V_20 -> V_209 + V_206 ;
}
void F_125 ( struct V_51 * V_10 , int V_206 , int V_205 )
{
struct V_74 * V_25 = F_46 ( V_10 -> V_59 ) ;
struct V_19 * V_20 = V_25 -> V_95 ;
F_126 ( & V_20 -> V_207 , V_206 - V_20 -> V_209 , V_205 ) ;
}
void F_127 ( struct V_210 * V_211 ,
struct V_51 * V_10 )
{
struct V_74 * V_25 = F_46 ( V_10 -> V_59 ) ;
struct V_19 * V_20 = V_25 -> V_95 ;
int V_54 , V_206 ;
for ( V_54 = 1 ; V_54 < V_212 ; V_54 ++ ) {
if ( ! V_211 -> V_213 [ V_54 ] )
continue;
F_128 ( L_52 ,
V_54 , V_211 -> V_214 [ V_54 ] ,
V_211 -> V_213 [ V_54 ] ) ;
V_206 = V_211 -> V_214 [ V_54 ] - V_20 -> V_209 ;
F_126 ( & V_20 -> V_207 , V_206 ,
V_211 -> V_213 [ V_54 ] ) ;
}
}
int F_129 ( struct V_210 * V_211 ,
struct V_51 * V_10 , int V_205 )
{
struct V_74 * V_25 = F_46 ( V_10 -> V_59 ) ;
struct V_19 * V_20 = V_25 -> V_95 ;
int V_54 , V_206 , V_215 ;
memset ( V_211 , 0 , sizeof( struct V_210 ) ) ;
for ( V_54 = 1 ; V_54 < V_212 && V_205 ; V_54 ++ ) {
V_215 = V_205 ;
while ( V_215 ) {
V_206 = F_123 ( & V_20 -> V_207 , V_215 ) ;
if ( V_206 >= 0 )
break;
V_215 /= 2 ;
}
if ( ! V_215 )
goto V_40;
V_211 -> V_214 [ V_54 ] = V_20 -> V_209 + V_206 ;
V_211 -> V_213 [ V_54 ] = V_215 ;
F_128 ( L_53 ,
V_54 , V_211 -> V_214 [ V_54 ] , V_211 -> V_213 [ V_54 ] ) ;
V_205 -= V_215 ;
}
if ( V_205 )
goto V_40;
return 0 ;
V_40:
F_127 ( V_211 , V_10 ) ;
return - V_208 ;
}
int F_130 ( struct V_51 * V_10 )
{
struct V_74 * V_25 = F_46 ( V_10 -> V_59 ) ;
struct V_19 * V_20 = V_25 -> V_95 ;
return V_20 -> V_207 . V_216 ;
}
int F_131 ( struct V_51 * V_10 , unsigned int V_206 ,
unsigned int V_200 )
{
struct V_74 * V_25 = F_46 ( V_10 -> V_59 ) ;
struct V_19 * V_20 = V_25 -> V_95 ;
unsigned int V_217 = V_206 - V_20 -> V_209 ;
struct V_1 * V_2 ;
int V_33 ;
if ( ! ( V_2 = F_45 ( V_10 ) ) )
return - V_155 ;
V_33 = F_132 ( V_20 -> V_34 , V_2 -> V_13 , V_217 ) ;
if ( V_33 ) {
F_50 ( V_2 , L_54
L_55 ,
F_54 ( V_10 ) , V_33 , V_20 -> V_209 , V_206 , V_217 ) ;
return - V_49 ;
}
F_115 ( V_20 , V_200 ) ;
return 0 ;
}
static int F_133 ( struct V_19 * V_20 , struct V_51 * V_10 ,
unsigned int V_206 , unsigned int V_200 ,
unsigned int V_218 , struct V_219 * V_220 )
{
struct V_1 * V_2 = F_45 ( V_10 ) ;
unsigned int V_217 = V_206 - V_20 -> V_209 ;
T_16 V_221 ;
int V_33 ;
if ( V_2 == NULL )
return - V_103 ;
if ( V_2 -> V_129 < 0 )
return - V_103 ;
if ( V_10 -> V_222 )
V_218 = 0 ;
V_33 = F_132 ( V_20 -> V_34 , V_2 -> V_13 , V_217 ) ;
if ( V_33 ) {
F_9 ( L_56 ,
F_54 ( V_10 ) , V_33 , V_217 ) ;
return - V_49 ;
}
if ( V_218 ) {
T_12 V_223 ;
V_33 = F_134 ( V_20 -> V_34 , V_2 -> V_129 , V_217 , 1 ,
& V_223 , & V_221 ) ;
if ( V_33 ) {
F_9 ( L_57 ,
F_54 ( V_10 ) , V_33 ) ;
return - V_49 ;
}
V_220 -> V_224 = F_135 ( V_223 ) >> 32 ;
V_220 -> V_225 = F_135 ( V_223 ) & 0xfffffffful ;
} else {
T_16 V_226 ;
V_33 = F_136 ( V_20 -> V_34 , V_2 -> V_129 , V_217 , 1 ,
& V_226 , & V_221 ) ;
if ( V_33 ) {
F_9 ( L_58 ,
F_54 ( V_10 ) , V_33 ) ;
return - V_49 ;
}
V_220 -> V_224 = 0 ;
V_220 -> V_225 = F_137 ( V_226 ) ;
}
V_220 -> V_221 = F_137 ( V_221 ) ;
F_115 ( V_20 , V_200 ) ;
F_128 ( L_59
L_60 ,
F_54 ( V_10 ) , V_218 ? L_61 : L_62 , V_206 , V_217 ,
V_220 -> V_224 , V_220 -> V_225 , V_221 , V_2 -> V_13 ) ;
return 0 ;
}
static void F_138 ( struct V_19 * V_20 )
{
unsigned int V_114 ;
const T_16 * V_227 = F_36 ( V_20 -> V_25 -> V_76 ,
L_63 , NULL ) ;
if ( ! V_227 ) {
V_227 = F_36 ( V_20 -> V_25 -> V_76 , L_64 , NULL ) ;
}
if ( ! V_227 )
return;
V_20 -> V_209 = F_139 ( V_227 ) ;
V_114 = F_139 ( V_227 + 1 ) ;
if ( F_140 ( & V_20 -> V_207 , V_114 , V_20 -> V_25 -> V_76 ) ) {
F_53 ( L_65 ,
V_20 -> V_25 -> V_26 ) ;
return;
}
V_20 -> V_228 = F_133 ;
V_20 -> V_229 = 1 ;
F_34 ( L_66 ,
V_114 , V_20 -> V_209 ) ;
}
static void F_138 ( struct V_19 * V_20 ) { }
static void F_141 ( struct V_74 * V_25 ,
struct V_1 * V_2 )
{
struct V_19 * V_20 = V_25 -> V_95 ;
struct V_230 V_231 ;
struct V_31 * V_77 ;
int V_54 , V_232 ;
int V_33 ;
F_142 ( ! ( V_2 -> V_16 & ( V_107 | V_106 ) ) ) ;
F_25 (pe->pbus, res, i) {
if ( ! V_77 || ! V_77 -> V_16 ||
V_77 -> V_45 > V_77 -> V_47 )
continue;
if ( V_77 -> V_16 & V_233 ) {
V_231 . V_45 = V_77 -> V_45 - V_20 -> V_22 . V_234 ;
V_231 . V_47 = V_77 -> V_47 - V_20 -> V_22 . V_234 ;
V_232 = V_231 . V_45 / V_20 -> V_22 . V_235 ;
while ( V_232 < V_20 -> V_22 . V_23 &&
V_231 . V_45 <= V_231 . V_47 ) {
V_20 -> V_22 . V_236 [ V_232 ] = V_2 -> V_13 ;
V_33 = F_143 ( V_20 -> V_34 ,
V_2 -> V_13 , V_237 , 0 , V_232 ) ;
if ( V_33 != V_39 ) {
F_53 ( L_67
L_68 ,
V_24 , V_33 , V_232 , V_2 -> V_13 ) ;
break;
}
V_231 . V_45 += V_20 -> V_22 . V_235 ;
V_232 ++ ;
}
} else if ( V_77 -> V_16 & V_82 ) {
V_231 . V_45 = V_77 -> V_45 -
V_25 -> V_83 [ 0 ] -
V_20 -> V_22 . V_190 ;
V_231 . V_47 = V_77 -> V_47 -
V_25 -> V_83 [ 0 ] -
V_20 -> V_22 . V_190 ;
V_232 = V_231 . V_45 / V_20 -> V_22 . V_238 ;
while ( V_232 < V_20 -> V_22 . V_23 &&
V_231 . V_45 <= V_231 . V_47 ) {
V_20 -> V_22 . V_239 [ V_232 ] = V_2 -> V_13 ;
V_33 = F_143 ( V_20 -> V_34 ,
V_2 -> V_13 , V_240 , 0 , V_232 ) ;
if ( V_33 != V_39 ) {
F_53 ( L_69
L_70 ,
V_24 , V_33 , V_232 , V_2 -> V_13 ) ;
break;
}
V_231 . V_45 += V_20 -> V_22 . V_238 ;
V_232 ++ ;
}
}
}
}
static void F_144 ( void )
{
struct V_74 * V_149 , * V_25 ;
struct V_19 * V_20 ;
struct V_1 * V_2 ;
F_68 (hose, tmp, &hose_list, list_node) {
V_20 = V_25 -> V_95 ;
F_21 (pe, &phb->ioda.pe_list, list) {
F_141 ( V_25 , V_2 ) ;
}
}
}
static void F_145 ( void )
{
struct V_74 * V_25 , * V_149 ;
struct V_19 * V_20 ;
F_68 (hose, tmp, &hose_list, list_node) {
F_108 ( V_25 -> V_95 ) ;
V_20 = V_25 -> V_95 ;
V_20 -> V_241 = 1 ;
}
}
static void F_146 ( void )
{
#ifdef F_147
struct V_74 * V_25 , * V_149 ;
struct V_19 * V_20 ;
char V_242 [ 16 ] ;
F_68 (hose, tmp, &hose_list, list_node) {
V_20 = V_25 -> V_95 ;
sprintf ( V_242 , L_71 , V_25 -> V_26 ) ;
V_20 -> V_243 = F_148 ( V_242 , V_244 ) ;
if ( ! V_20 -> V_243 )
F_63 ( L_72 ,
V_24 , V_25 -> V_26 ) ;
}
#endif
}
static void F_149 ( void )
{
F_67 () ;
F_144 () ;
F_145 () ;
F_146 () ;
#ifdef F_150
F_151 () ;
F_152 () ;
#endif
}
static T_5 F_153 ( struct V_58 * V_59 ,
unsigned long type )
{
struct V_51 * V_245 ;
struct V_74 * V_25 = F_46 ( V_59 ) ;
struct V_19 * V_20 = V_25 -> V_95 ;
int V_246 = 0 ;
V_245 = V_59 -> V_108 ;
while ( V_245 ) {
if ( F_66 ( V_245 ) == V_148 ) {
V_246 ++ ;
if ( V_246 >= 2 )
return 1 ;
}
V_245 = V_245 -> V_59 -> V_108 ;
}
if ( V_20 -> V_22 . V_46 &&
F_7 ( type ) )
return V_20 -> V_22 . V_46 ;
if ( type & V_82 )
return V_20 -> V_22 . V_238 ;
return V_20 -> V_22 . V_235 ;
}
static int F_154 ( struct V_51 * V_10 )
{
struct V_74 * V_25 = F_46 ( V_10 -> V_59 ) ;
struct V_19 * V_20 = V_25 -> V_95 ;
struct V_96 * V_97 ;
if ( ! V_20 -> V_241 )
return 0 ;
V_97 = F_47 ( V_10 ) ;
if ( ! V_97 || V_97 -> V_13 == V_29 )
return - V_247 ;
return 0 ;
}
static T_7 F_155 ( struct V_19 * V_20 , struct V_58 * V_59 ,
T_7 V_248 )
{
return V_20 -> V_22 . V_127 [ ( V_59 -> V_12 << 8 ) | V_248 ] ;
}
static void F_156 ( struct V_19 * V_20 )
{
F_157 ( V_20 -> V_34 , V_249 ,
V_250 ) ;
}
static void T_6 F_158 ( struct V_75 * V_251 ,
T_2 V_252 , int V_253 )
{
struct V_74 * V_25 ;
struct V_19 * V_20 ;
unsigned long V_63 , V_254 , V_255 , V_256 = 0 ;
const T_12 * V_257 ;
const T_16 * V_258 ;
int V_259 ;
T_2 V_260 ;
void * V_261 ;
long V_33 ;
F_34 ( L_73 , V_253 , V_251 -> V_81 ) ;
V_257 = F_36 ( V_251 , L_74 , NULL ) ;
if ( ! V_257 ) {
F_53 ( L_75 ) ;
return;
}
V_260 = F_97 ( V_257 ) ;
F_159 ( L_76 , V_260 ) ;
V_20 = F_160 ( sizeof( struct V_19 ) , 0 ) ;
V_20 -> V_25 = V_25 = F_161 ( V_251 ) ;
if ( ! V_20 -> V_25 ) {
F_53 ( L_77 ,
V_251 -> V_81 ) ;
F_162 ( F_83 ( V_20 ) , sizeof( struct V_19 ) ) ;
return;
}
F_163 ( & V_20 -> V_262 ) ;
V_258 = F_36 ( V_251 , L_78 , & V_259 ) ;
if ( V_258 && V_259 == 8 ) {
V_25 -> V_263 = F_137 ( V_258 [ 0 ] ) ;
V_25 -> V_264 = F_137 ( V_258 [ 1 ] ) ;
} else {
F_9 ( L_79 , V_251 -> V_81 ) ;
V_25 -> V_263 = 0 ;
V_25 -> V_264 = 0xff ;
}
V_25 -> V_95 = V_20 ;
V_20 -> V_252 = V_252 ;
V_20 -> V_34 = V_260 ;
V_20 -> type = V_253 ;
if ( F_164 ( V_251 , L_80 ) )
V_20 -> V_265 = V_266 ;
else if ( F_164 ( V_251 , L_81 ) )
V_20 -> V_265 = V_267 ;
else
V_20 -> V_265 = V_268 ;
F_165 ( V_25 , V_251 , ! V_25 -> V_26 ) ;
V_20 -> V_269 = F_166 ( V_251 , 0 ) ;
if ( V_20 -> V_269 == NULL )
F_53 ( L_82 ) ;
V_20 -> V_22 . V_23 = 1 ;
V_258 = F_36 ( V_251 , L_83 , NULL ) ;
if ( V_258 )
V_20 -> V_22 . V_23 = F_139 ( V_258 ) ;
V_258 = F_36 ( V_251 , L_84 , NULL ) ;
if ( V_258 )
V_20 -> V_22 . V_44 = F_139 ( V_258 ) ;
F_33 ( V_20 ) ;
V_20 -> V_22 . V_270 = F_22 ( & V_25 -> V_43 [ 0 ] ) ;
V_20 -> V_22 . V_270 += 0x10000 ;
V_20 -> V_22 . V_238 = V_20 -> V_22 . V_270 / V_20 -> V_22 . V_23 ;
V_20 -> V_22 . V_190 = V_25 -> V_43 [ 0 ] . V_45 - V_25 -> V_83 [ 0 ] ;
V_20 -> V_22 . V_271 = V_25 -> V_272 ;
V_20 -> V_22 . V_235 = V_20 -> V_22 . V_271 / V_20 -> V_22 . V_23 ;
V_20 -> V_22 . V_234 = 0 ;
V_63 = F_26 ( V_20 -> V_22 . V_23 / 8 , sizeof( unsigned long ) ) ;
V_254 = V_63 ;
V_63 += V_20 -> V_22 . V_23 * sizeof( V_20 -> V_22 . V_239 [ 0 ] ) ;
if ( V_20 -> type == V_128 ) {
V_256 = V_63 ;
V_63 += V_20 -> V_22 . V_23 * sizeof( V_20 -> V_22 . V_236 [ 0 ] ) ;
}
V_255 = V_63 ;
V_63 += V_20 -> V_22 . V_23 * sizeof( struct V_1 ) ;
V_261 = F_160 ( V_63 , 0 ) ;
V_20 -> V_22 . V_27 = V_261 ;
V_20 -> V_22 . V_239 = V_261 + V_254 ;
if ( V_20 -> type == V_128 )
V_20 -> V_22 . V_236 = V_261 + V_256 ;
V_20 -> V_22 . V_28 = V_261 + V_255 ;
F_19 ( V_20 -> V_22 . V_44 , V_20 -> V_22 . V_27 ) ;
F_31 ( & V_20 -> V_22 . V_135 ) ;
F_31 ( & V_20 -> V_22 . V_146 ) ;
V_20 -> V_22 . V_194 = V_20 -> V_22 . V_190 >> 28 ;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
F_34 ( L_85 ,
V_20 -> V_22 . V_23 , V_20 -> V_22 . V_44 ,
V_20 -> V_22 . V_270 , V_20 -> V_22 . V_238 ) ;
if ( V_20 -> V_22 . V_38 )
F_34 ( L_86 ,
V_20 -> V_22 . V_38 , V_20 -> V_22 . V_46 ) ;
if ( V_20 -> V_22 . V_271 )
F_34 ( L_87 ,
V_20 -> V_22 . V_271 , V_20 -> V_22 . V_235 ) ;
V_20 -> V_25 -> V_273 = & V_274 ;
V_20 -> V_275 = F_43 ;
V_20 -> V_276 = F_39 ;
V_20 -> V_277 = F_41 ;
#ifdef F_150
V_20 -> V_278 = & V_279 ;
#endif
V_20 -> V_280 = F_155 ;
V_20 -> V_281 = F_69 ;
V_20 -> V_282 = F_72 ;
V_20 -> V_283 = F_78 ;
V_20 -> V_284 = F_156 ;
F_138 ( V_20 ) ;
V_285 . V_286 = F_149 ;
V_285 . V_287 = F_154 ;
V_285 . V_288 = F_153 ;
V_285 . V_289 = V_290 ;
F_167 ( V_291 ) ;
V_33 = F_157 ( V_260 , V_249 , V_250 ) ;
if ( V_33 )
F_63 ( L_88 , V_33 ) ;
if ( F_168 () ) {
F_34 ( L_89 ) ;
F_169 ( V_25 , V_292 ) ;
F_169 ( V_25 , V_293 ) ;
}
if ( ! V_20 -> V_84 || V_20 -> V_84 ( V_20 ) )
V_25 -> V_43 [ 1 ] . V_16 = 0 ;
}
void T_6 F_170 ( struct V_75 * V_251 )
{
F_158 ( V_251 , 0 , V_79 ) ;
}
void T_6 F_171 ( struct V_75 * V_251 )
{
struct V_75 * V_294 ;
const T_12 * V_257 ;
T_2 V_252 ;
F_34 ( L_90 , V_251 -> V_81 ) ;
V_257 = F_36 ( V_251 , L_91 , NULL ) ;
if ( ! V_257 ) {
F_53 ( L_92 ) ;
return;
}
V_252 = F_97 ( V_257 ) ;
F_128 ( L_93 , V_252 ) ;
F_172 (np, phbn) {
if ( F_164 ( V_294 , L_94 ) )
F_158 ( V_294 , V_252 , V_128 ) ;
}
}
