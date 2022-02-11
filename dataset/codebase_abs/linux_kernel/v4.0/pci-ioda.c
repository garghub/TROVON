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
static int T_2 F_6 ( char * V_14 )
{
if ( ! V_14 )
return - V_15 ;
while ( * V_14 ) {
if ( ! strncmp ( V_14 , L_3 , 8 ) ) {
V_16 = true ;
F_7 ( L_4 ) ;
break;
}
V_14 += strcspn ( V_14 , L_5 ) ;
if ( * V_14 == ',' )
V_14 ++ ;
}
return 0 ;
}
static inline void F_8 ( T_3 V_17 , volatile void T_4 * V_18 )
{
__asm__ __volatile__("stdcix %0,0,%1"
: : "r" (val), "r" (paddr) : "memory");
}
static inline bool F_9 ( unsigned long V_19 )
{
return ( ( V_19 & ( V_20 | V_21 ) ) ==
( V_20 | V_21 ) ) ;
}
static void F_10 ( struct V_22 * V_23 , int V_24 )
{
if ( ! ( V_24 >= 0 && V_24 < V_23 -> V_25 . V_26 ) ) {
F_11 ( L_6 ,
V_27 , V_24 , V_23 -> V_28 -> V_29 ) ;
return;
}
if ( F_12 ( V_24 , V_23 -> V_25 . V_30 ) ) {
F_11 ( L_7 ,
V_27 , V_24 , V_23 -> V_28 -> V_29 ) ;
return;
}
V_23 -> V_25 . V_31 [ V_24 ] . V_23 = V_23 ;
V_23 -> V_25 . V_31 [ V_24 ] . V_13 = V_24 ;
}
static int F_13 ( struct V_22 * V_23 )
{
unsigned long V_2 ;
do {
V_2 = F_14 ( V_23 -> V_25 . V_30 ,
V_23 -> V_25 . V_26 , 0 ) ;
if ( V_2 >= V_23 -> V_25 . V_26 )
return V_32 ;
} while( F_12 ( V_2 , V_23 -> V_25 . V_30 ) );
V_23 -> V_25 . V_31 [ V_2 ] . V_23 = V_23 ;
V_23 -> V_25 . V_31 [ V_2 ] . V_13 = V_2 ;
return V_2 ;
}
static void F_15 ( struct V_22 * V_23 , int V_2 )
{
F_16 ( V_23 -> V_25 . V_31 [ V_2 ] . V_9 ) ;
memset ( & V_23 -> V_25 . V_31 [ V_2 ] , 0 , sizeof( struct V_1 ) ) ;
F_17 ( V_2 , V_23 -> V_25 . V_30 ) ;
}
static int F_18 ( struct V_22 * V_23 )
{
const char * V_33 ;
struct V_34 * V_35 ;
T_5 V_36 ;
V_36 = F_19 ( V_23 -> V_37 ,
V_38 ,
V_23 -> V_25 . V_39 ,
V_23 -> V_25 . V_40 ,
0 ,
V_23 -> V_25 . V_41 ) ;
if ( V_36 != V_42 ) {
V_33 = L_8 ;
goto V_43;
}
V_36 = F_20 ( V_23 -> V_37 ,
V_38 ,
V_23 -> V_25 . V_39 ,
V_44 ) ;
if ( V_36 != V_42 ) {
V_33 = L_9 ;
goto V_43;
}
F_21 ( V_23 -> V_25 . V_39 , & V_23 -> V_25 . V_45 ) ;
V_35 = & V_23 -> V_28 -> V_46 [ 1 ] ;
if ( V_23 -> V_25 . V_47 == 0 )
V_35 -> V_48 += V_23 -> V_25 . V_49 ;
else if ( V_23 -> V_25 . V_47 == ( V_23 -> V_25 . V_26 - 1 ) )
V_35 -> V_50 -= V_23 -> V_25 . V_49 ;
else
F_11 ( L_10 ,
V_23 -> V_25 . V_47 ) ;
return 0 ;
V_43:
F_11 ( L_11 ,
V_36 , V_33 , V_23 -> V_25 . V_39 ) ;
F_20 ( V_23 -> V_37 ,
V_38 ,
V_23 -> V_25 . V_39 ,
V_51 ) ;
return - V_52 ;
}
static void F_22 ( struct V_22 * V_23 )
{
T_6 V_53 = V_23 -> V_25 . V_49 ;
struct V_54 * V_9 ;
struct V_34 * V_35 ;
int V_55 , V_56 , V_57 ;
F_23 (pdev, &phb->hose->bus->devices, bus_list) {
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ ) {
V_35 = & V_9 -> V_34 [ V_59 + V_57 ] ;
if ( ! V_35 -> V_60 ||
! F_9 ( V_35 -> V_19 ) )
continue;
V_55 = ( V_35 -> V_48 - V_23 -> V_25 . V_40 ) / V_53 ;
for ( V_56 = 0 ; V_56 < F_24 ( V_35 ) / V_53 ; V_56 ++ )
F_10 ( V_23 , V_55 + V_56 ) ;
}
}
}
static int F_25 ( struct V_22 * V_23 ,
struct V_61 * V_62 , int V_63 )
{
T_6 V_64 = V_23 -> V_25 . V_49 ;
struct V_54 * V_9 ;
struct V_34 * V_35 ;
struct V_1 * V_65 , * V_2 ;
unsigned long V_66 , * V_30 ;
bool V_67 ;
int V_48 , V_57 , V_68 ;
if ( F_26 ( V_62 ) )
return V_32 ;
V_67 = false ;
F_27 (bus, r, i) {
if ( V_35 && V_35 -> V_60 &&
F_9 ( V_35 -> V_19 ) ) {
V_67 = true ;
break;
}
}
if ( ! V_67 )
return V_32 ;
V_66 = F_28 ( V_23 -> V_25 . V_26 / 8 , sizeof( unsigned long ) ) ;
V_30 = F_29 ( V_66 , V_69 ) ;
if ( ! V_30 ) {
F_11 ( L_12 ,
V_27 ) ;
return V_32 ;
}
V_48 = ( V_35 -> V_48 - V_23 -> V_25 . V_40 ) / V_64 ;
for ( V_57 = 0 ; V_57 < F_24 ( V_35 ) / V_64 ; V_57 ++ )
F_21 ( V_48 + V_57 , V_30 ) ;
if ( V_63 )
goto V_70;
F_23 (pdev, &bus->devices, bus_list) {
if ( ! V_9 -> V_71 )
continue;
F_27 (pdev->subordinate, r, i) {
if ( ! V_35 || ! V_35 -> V_60 ||
! F_9 ( V_35 -> V_19 ) )
continue;
V_48 = ( V_35 -> V_48 - V_23 -> V_25 . V_40 ) / V_64 ;
for ( V_68 = 0 ; V_68 < F_24 ( V_35 ) / V_64 ; V_68 ++ )
F_17 ( V_48 + V_68 , V_30 ) ;
}
}
if ( F_30 ( V_30 , V_23 -> V_25 . V_26 ) ) {
F_31 ( V_30 ) ;
return V_32 ;
}
V_70:
V_65 = NULL ;
V_57 = - 1 ;
while ( ( V_57 = F_32 ( V_30 , V_23 -> V_25 . V_26 , V_57 + 1 ) ) <
V_23 -> V_25 . V_26 ) {
V_2 = & V_23 -> V_25 . V_31 [ V_57 ] ;
if ( ! V_65 ) {
V_2 -> V_19 |= V_72 ;
F_33 ( & V_2 -> V_73 ) ;
V_65 = V_2 ;
} else {
V_2 -> V_19 |= V_74 ;
V_2 -> V_75 = V_65 ;
F_34 ( & V_2 -> V_76 , & V_65 -> V_73 ) ;
}
}
F_31 ( V_30 ) ;
return V_65 -> V_13 ;
}
static void T_2 F_35 ( struct V_22 * V_23 )
{
struct V_77 * V_28 = V_23 -> V_28 ;
struct V_78 * V_79 = V_28 -> V_79 ;
struct V_34 * V_80 ;
const T_7 * V_35 ;
T_3 V_81 ;
if ( V_23 -> type != V_82 ) {
F_7 ( L_13 ) ;
return;
}
if ( ! F_36 ( V_83 ) ) {
F_7 ( L_14 ) ;
return;
}
V_35 = F_37 ( V_79 , L_15 , NULL ) ;
if ( ! V_35 ) {
F_7 ( L_16 ,
V_79 -> V_84 ) ;
return;
}
V_80 = & V_28 -> V_46 [ 1 ] ;
V_80 -> V_48 = F_38 ( V_79 , V_35 + 2 ) ;
V_80 -> V_50 = V_80 -> V_48 + F_39 ( V_35 + 4 , 2 ) - 1 ;
V_80 -> V_19 = ( V_85 | V_20 | V_21 ) ;
V_81 = F_39 ( V_35 , 2 ) ;
V_28 -> V_86 [ 1 ] = V_80 -> V_48 - V_81 ;
V_23 -> V_25 . V_41 = F_24 ( V_80 ) ;
V_23 -> V_25 . V_49 = V_23 -> V_25 . V_41 / V_23 -> V_25 . V_26 ;
V_23 -> V_25 . V_40 = V_81 ;
F_7 ( L_17 ,
V_80 -> V_48 , V_80 -> V_50 , V_81 ) ;
V_23 -> V_25 . V_39 = 15 ;
V_23 -> V_87 = F_18 ;
V_23 -> V_88 = F_22 ;
V_23 -> V_89 = F_25 ;
}
static void F_40 ( struct V_22 * V_23 , int V_24 )
{
struct V_1 * V_2 = & V_23 -> V_25 . V_31 [ V_24 ] ;
struct V_1 * V_90 ;
T_5 V_36 ;
if ( V_2 -> V_19 & V_74 ) {
V_2 = V_2 -> V_75 ;
if ( F_16 ( ! V_2 || ! ( V_2 -> V_19 & V_72 ) ) )
return;
V_24 = V_2 -> V_13 ;
}
V_36 = F_41 ( V_23 -> V_37 ,
V_24 ,
V_91 ) ;
if ( V_36 != V_42 ) {
F_11 ( L_18 ,
V_27 , V_36 , V_23 -> V_28 -> V_29 , V_24 ) ;
return;
}
if ( ! ( V_2 -> V_19 & V_72 ) )
return;
F_23 (slave, &pe->slaves, list) {
V_36 = F_41 ( V_23 -> V_37 ,
V_90 -> V_13 ,
V_91 ) ;
if ( V_36 != V_42 )
F_11 ( L_18 ,
V_27 , V_36 , V_23 -> V_28 -> V_29 ,
V_90 -> V_13 ) ;
}
}
static int F_42 ( struct V_22 * V_23 , int V_24 , int V_92 )
{
struct V_1 * V_2 , * V_90 ;
T_5 V_36 ;
V_2 = & V_23 -> V_25 . V_31 [ V_24 ] ;
if ( V_2 -> V_19 & V_74 ) {
V_2 = V_2 -> V_75 ;
F_16 ( ! V_2 || ! ( V_2 -> V_19 & V_72 ) ) ;
V_24 = V_2 -> V_13 ;
}
V_36 = F_43 ( V_23 -> V_37 , V_24 , V_92 ) ;
if ( V_36 != V_42 ) {
F_11 ( L_19 ,
V_27 , V_36 , V_92 , V_23 -> V_28 -> V_29 , V_24 ) ;
return - V_52 ;
}
if ( ! ( V_2 -> V_19 & V_72 ) )
return 0 ;
F_23 (slave, &pe->slaves, list) {
V_36 = F_43 ( V_23 -> V_37 ,
V_90 -> V_13 ,
V_92 ) ;
if ( V_36 != V_42 ) {
F_11 ( L_19 ,
V_27 , V_36 , V_92 , V_23 -> V_28 -> V_29 ,
V_90 -> V_13 ) ;
return - V_52 ;
}
}
return 0 ;
}
static int F_44 ( struct V_22 * V_23 , int V_24 )
{
struct V_1 * V_90 , * V_2 ;
T_8 V_93 , V_94 ;
T_9 V_95 ;
T_5 V_36 ;
if ( V_24 < 0 || V_24 >= V_23 -> V_25 . V_26 )
return V_96 ;
V_2 = & V_23 -> V_25 . V_31 [ V_24 ] ;
if ( V_2 -> V_19 & V_74 ) {
V_2 = V_2 -> V_75 ;
F_16 ( ! V_2 || ! ( V_2 -> V_19 & V_72 ) ) ;
V_24 = V_2 -> V_13 ;
}
V_36 = F_45 ( V_23 -> V_37 , V_24 ,
& V_94 , & V_95 , NULL ) ;
if ( V_36 != V_42 ) {
F_11 ( L_20
L_21 ,
V_27 , V_36 ,
V_23 -> V_28 -> V_29 , V_24 ) ;
return V_97 ;
}
if ( ! ( V_2 -> V_19 & V_72 ) )
return V_94 ;
F_23 (slave, &pe->slaves, list) {
V_36 = F_45 ( V_23 -> V_37 ,
V_90 -> V_13 ,
& V_93 ,
& V_95 ,
NULL ) ;
if ( V_36 != V_42 ) {
F_11 ( L_20
L_21 ,
V_27 , V_36 ,
V_23 -> V_28 -> V_29 , V_90 -> V_13 ) ;
return V_97 ;
}
if ( V_93 > V_94 )
V_94 = V_93 ;
}
return V_94 ;
}
static struct V_1 * F_46 ( struct V_54 * V_10 )
{
struct V_77 * V_28 = F_47 ( V_10 -> V_62 ) ;
struct V_22 * V_23 = V_28 -> V_98 ;
struct V_99 * V_100 = F_48 ( V_10 ) ;
if ( ! V_100 )
return NULL ;
if ( V_100 -> V_13 == V_32 )
return NULL ;
return & V_23 -> V_25 . V_31 [ V_100 -> V_13 ] ;
}
static int F_49 ( struct V_22 * V_23 ,
struct V_1 * V_60 ,
struct V_1 * V_101 ,
bool V_102 )
{
const char * V_33 = V_102 ? L_22 : L_23 ;
T_10 V_103 = V_102 ? V_104 :
V_105 ;
struct V_1 * V_90 ;
long V_36 ;
V_36 = F_50 ( V_23 -> V_37 , V_60 -> V_13 ,
V_101 -> V_13 , V_103 ) ;
if ( V_36 != V_42 ) {
F_51 ( V_101 , L_24 ,
V_36 , V_33 ) ;
return - V_106 ;
}
if ( ! ( V_101 -> V_19 & V_72 ) )
return 0 ;
F_23 (slave, &child->slaves, list) {
V_36 = F_50 ( V_23 -> V_37 , V_60 -> V_13 ,
V_90 -> V_13 , V_103 ) ;
if ( V_36 != V_42 ) {
F_51 ( V_90 , L_24 ,
V_36 , V_33 ) ;
return - V_106 ;
}
}
return 0 ;
}
static int F_52 ( struct V_22 * V_23 ,
struct V_1 * V_2 ,
bool V_102 )
{
struct V_1 * V_90 ;
struct V_54 * V_9 ;
int V_107 ;
if ( V_102 ) {
F_43 ( V_23 -> V_37 , V_2 -> V_13 ,
V_108 ) ;
if ( V_2 -> V_19 & V_72 ) {
F_23 (slave, &pe->slaves, list)
F_43 ( V_23 -> V_37 ,
V_90 -> V_13 ,
V_108 ) ;
}
}
V_107 = F_49 ( V_23 , V_2 , V_2 , V_102 ) ;
if ( V_107 )
return V_107 ;
if ( V_2 -> V_19 & V_72 ) {
F_23 (slave, &pe->slaves, list) {
V_107 = F_49 ( V_23 , V_90 , V_2 , V_102 ) ;
if ( V_107 )
return V_107 ;
}
}
if ( V_2 -> V_19 & ( V_109 | V_110 ) )
V_9 = V_2 -> V_11 -> V_111 ;
else
V_9 = V_2 -> V_9 -> V_62 -> V_111 ;
while ( V_9 ) {
struct V_99 * V_100 = F_48 ( V_9 ) ;
struct V_1 * V_60 ;
if ( V_100 && V_100 -> V_13 != V_32 ) {
V_60 = & V_23 -> V_25 . V_31 [ V_100 -> V_13 ] ;
V_107 = F_49 ( V_23 , V_60 , V_2 , V_102 ) ;
if ( V_107 )
return V_107 ;
}
V_9 = V_9 -> V_62 -> V_111 ;
}
return 0 ;
}
static int F_53 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
struct V_54 * V_60 ;
T_10 V_112 , V_113 , V_114 ;
long V_36 , V_115 , V_116 ;
if ( V_2 -> V_11 ) {
int V_117 ;
V_113 = V_118 ;
V_114 = V_119 ;
V_60 = V_2 -> V_11 -> V_111 ;
if ( V_2 -> V_19 & V_109 )
V_117 = V_2 -> V_11 -> V_120 . V_50 - V_2 -> V_11 -> V_120 . V_48 + 1 ;
else
V_117 = 1 ;
switch( V_117 ) {
case 1 : V_112 = V_121 ; break;
case 2 : V_112 = V_122 ; break;
case 4 : V_112 = V_123 ; break;
case 8 : V_112 = V_124 ; break;
case 16 : V_112 = V_125 ; break;
case 32 : V_112 = V_126 ; break;
default:
F_54 ( L_25
L_26 ,
F_55 ( V_2 -> V_11 -> V_111 ) , V_117 ) ;
V_112 = V_121 ;
}
V_115 = V_2 -> V_116 + ( V_117 << 8 ) ;
} else {
V_60 = V_2 -> V_9 -> V_62 -> V_111 ;
V_112 = V_121 ;
V_113 = V_127 ;
V_114 = V_128 ;
V_115 = V_2 -> V_116 + 1 ;
}
V_36 = F_56 ( V_23 -> V_37 , V_2 -> V_13 , V_2 -> V_116 ,
V_112 , V_113 , V_114 , V_129 ) ;
if ( V_36 ) {
F_57 ( V_2 , L_27 , V_36 ) ;
return - V_106 ;
}
F_52 ( V_23 , V_2 , true ) ;
for ( V_116 = V_2 -> V_116 ; V_116 < V_115 ; V_116 ++ )
V_23 -> V_25 . V_130 [ V_116 ] = V_2 -> V_13 ;
if ( V_23 -> type != V_131 ) {
V_2 -> V_132 = 0 ;
goto V_133;
}
V_2 -> V_132 = V_2 -> V_13 ;
V_36 = F_58 ( V_23 -> V_37 , V_2 -> V_132 , V_2 -> V_13 ) ;
if ( V_36 != V_42 ) {
F_57 ( V_2 , L_28 ,
V_36 , V_2 -> V_132 ) ;
V_2 -> V_132 = - 1 ;
} else {
V_36 = F_59 ( V_23 -> V_37 ,
V_2 -> V_132 , V_134 ) ;
if ( V_36 ) {
F_57 ( V_2 , L_29 ,
V_36 , V_2 -> V_132 ) ;
V_2 -> V_132 = - 1 ;
}
}
V_133:
return 0 ;
}
static void F_60 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_1 * V_135 ;
F_23 (lpe, &phb->ioda.pe_dma_list, dma_link) {
if ( V_135 -> V_136 < V_2 -> V_136 ) {
F_34 ( & V_2 -> V_137 , & V_135 -> V_137 ) ;
return;
}
}
F_34 ( & V_2 -> V_137 , & V_23 -> V_25 . V_138 ) ;
}
static unsigned int F_61 ( struct V_54 * V_10 )
{
if ( V_10 -> V_139 != V_140 )
return 0 ;
if ( V_10 -> V_141 == V_142 ||
V_10 -> V_141 == V_143 ||
V_10 -> V_141 == V_144 )
return 3 ;
if ( ( V_10 -> V_141 >> 8 ) == V_145 )
return 15 ;
return 10 ;
}
static void F_62 ( struct V_61 * V_62 , struct V_1 * V_2 )
{
struct V_54 * V_10 ;
F_23 (dev, &bus->devices, bus_list) {
struct V_99 * V_100 = F_48 ( V_10 ) ;
if ( V_100 == NULL ) {
F_11 ( L_30 ,
F_55 ( V_10 ) ) ;
continue;
}
V_100 -> V_146 = V_10 ;
V_100 -> V_13 = V_2 -> V_13 ;
V_2 -> V_136 += F_61 ( V_10 ) ;
if ( ( V_2 -> V_19 & V_109 ) && V_10 -> V_71 )
F_62 ( V_10 -> V_71 , V_2 ) ;
}
}
static void F_63 ( struct V_61 * V_62 , int V_63 )
{
struct V_77 * V_28 = F_47 ( V_62 ) ;
struct V_22 * V_23 = V_28 -> V_98 ;
struct V_1 * V_2 ;
int V_147 = V_32 ;
if ( V_23 -> V_89 )
V_147 = V_23 -> V_89 ( V_23 , V_62 , V_63 ) ;
if ( V_147 == V_32 )
V_147 = F_13 ( V_23 ) ;
if ( V_147 == V_32 ) {
F_64 ( L_31 ,
V_27 , F_4 ( V_62 ) , V_62 -> V_12 ) ;
return;
}
V_2 = & V_23 -> V_25 . V_31 [ V_147 ] ;
V_2 -> V_19 |= ( V_63 ? V_109 : V_110 ) ;
V_2 -> V_11 = V_62 ;
V_2 -> V_9 = NULL ;
V_2 -> V_148 = - 1 ;
V_2 -> V_132 = - 1 ;
V_2 -> V_116 = V_62 -> V_120 . V_48 << 8 ;
V_2 -> V_136 = 0 ;
if ( V_63 )
F_65 ( V_2 , L_32 ,
V_62 -> V_120 . V_48 , V_62 -> V_120 . V_50 , V_147 ) ;
else
F_65 ( V_2 , L_33 ,
V_62 -> V_120 . V_48 , V_147 ) ;
if ( F_53 ( V_23 , V_2 ) ) {
if ( V_147 )
F_15 ( V_23 , V_147 ) ;
V_2 -> V_11 = NULL ;
return;
}
F_62 ( V_62 , V_2 ) ;
F_34 ( & V_2 -> V_76 , & V_23 -> V_25 . V_149 ) ;
if ( V_2 -> V_136 != 0 ) {
V_23 -> V_25 . V_136 += V_2 -> V_136 ;
V_23 -> V_25 . V_150 ++ ;
}
F_60 ( V_23 , V_2 ) ;
}
static void F_66 ( struct V_61 * V_62 )
{
struct V_54 * V_10 ;
F_63 ( V_62 , 0 ) ;
F_23 (dev, &bus->devices, bus_list) {
if ( V_10 -> V_71 ) {
if ( F_67 ( V_10 ) == V_151 )
F_63 ( V_10 -> V_71 , 1 ) ;
else
F_66 ( V_10 -> V_71 ) ;
}
}
}
static void F_68 ( void )
{
struct V_77 * V_28 , * V_152 ;
struct V_22 * V_23 ;
F_69 (hose, tmp, &hose_list, list_node) {
V_23 = V_28 -> V_98 ;
if ( V_23 -> V_88 )
V_23 -> V_88 ( V_23 ) ;
F_66 ( V_28 -> V_62 ) ;
}
}
static void F_70 ( struct V_22 * V_23 , struct V_54 * V_9 )
{
struct V_99 * V_100 = F_48 ( V_9 ) ;
struct V_1 * V_2 ;
if ( ! V_100 || V_100 -> V_13 == V_32 )
return;
V_2 = & V_23 -> V_25 . V_31 [ V_100 -> V_13 ] ;
F_16 ( F_71 ( & V_9 -> V_10 ) != & V_153 ) ;
F_72 ( & V_9 -> V_10 , & V_2 -> V_154 ) ;
}
static int F_73 ( struct V_22 * V_23 ,
struct V_54 * V_9 , T_3 V_155 )
{
struct V_99 * V_100 = F_48 ( V_9 ) ;
struct V_1 * V_2 ;
T_11 V_156 ;
bool V_157 = false ;
if ( F_16 ( ! V_100 || V_100 -> V_13 == V_32 ) )
return - V_158 ; ;
V_2 = & V_23 -> V_25 . V_31 [ V_100 -> V_13 ] ;
if ( V_2 -> V_159 ) {
V_156 = V_2 -> V_160 + F_74 () - 1 ;
V_157 = ( V_155 >= V_156 ) ;
}
if ( V_157 ) {
F_75 ( & V_9 -> V_10 , L_34 ) ;
F_76 ( & V_9 -> V_10 , & V_161 ) ;
F_77 ( & V_9 -> V_10 , V_2 -> V_160 ) ;
} else {
F_75 ( & V_9 -> V_10 , L_35 ) ;
F_76 ( & V_9 -> V_10 , & V_153 ) ;
F_78 ( & V_9 -> V_10 , & V_2 -> V_154 ) ;
}
* V_9 -> V_10 . V_155 = V_155 ;
return 0 ;
}
static T_3 F_79 ( struct V_22 * V_23 ,
struct V_54 * V_9 )
{
struct V_99 * V_100 = F_48 ( V_9 ) ;
struct V_1 * V_2 ;
T_3 V_50 , V_162 ;
if ( F_16 ( ! V_100 || V_100 -> V_13 == V_32 ) )
return 0 ;
V_2 = & V_23 -> V_25 . V_31 [ V_100 -> V_13 ] ;
if ( ! V_2 -> V_159 )
return F_80 ( & V_9 -> V_10 ) ;
V_50 = V_2 -> V_160 + F_74 () ;
V_162 = 1ULL << ( F_81 ( V_50 ) - 1 ) ;
V_162 += V_162 - 1 ;
return V_162 ;
}
static void F_82 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
bool V_163 )
{
struct V_54 * V_10 ;
F_23 (dev, &bus->devices, bus_list) {
if ( V_163 )
F_72 ( & V_10 -> V_10 ,
& V_2 -> V_154 ) ;
else
F_78 ( & V_10 -> V_10 , & V_2 -> V_154 ) ;
if ( V_10 -> V_71 )
F_82 ( V_2 , V_10 -> V_71 ,
V_163 ) ;
}
}
static void F_83 ( struct V_1 * V_2 ,
struct V_164 * V_165 ,
T_12 * V_166 , T_12 * V_167 , bool V_168 )
{
T_12 T_4 * V_169 = V_168 ?
( T_12 T_4 * ) V_2 -> V_170 :
( T_12 T_4 * ) V_165 -> V_171 ;
unsigned long V_48 , V_50 , V_172 ;
const unsigned V_173 = V_165 -> V_174 ;
V_48 = F_84 ( V_166 ) ;
V_50 = F_84 ( V_167 ) ;
if ( V_165 -> V_175 ) {
V_48 <<= V_173 ;
V_50 <<= V_173 ;
V_172 = 128ull << V_173 ;
V_48 |= V_165 -> V_175 ;
V_50 |= V_165 -> V_175 ;
} else if ( V_165 -> V_176 & V_177 ) {
V_48 |= ( 1ull << 63 ) ;
V_50 |= ( 1ull << 63 ) ;
V_172 = 16 ;
} else {
V_172 = 128 ;
}
V_50 |= V_172 - 1 ;
F_85 () ;
while ( V_48 <= V_50 ) {
if ( V_168 )
F_8 ( F_86 ( V_48 ) , V_169 ) ;
else
F_87 ( F_86 ( V_48 ) , V_169 ) ;
V_48 += V_172 ;
}
}
static void F_88 ( struct V_1 * V_2 ,
struct V_164 * V_165 ,
T_12 * V_166 , T_12 * V_167 , bool V_168 )
{
unsigned long V_48 , V_50 , V_172 ;
T_12 T_4 * V_169 = V_168 ?
( T_12 T_4 * ) V_2 -> V_170 :
( T_12 T_4 * ) V_165 -> V_171 ;
const unsigned V_173 = V_165 -> V_174 ;
V_48 = 0x2ull << 60 ;
V_48 |= ( V_2 -> V_13 & 0xFF ) ;
V_50 = V_48 ;
V_172 = V_165 -> V_178 + ( ( ( T_3 ) V_166 - V_165 -> V_179 ) / sizeof( T_3 ) ) ;
V_48 |= ( V_172 << V_173 ) ;
V_172 = V_165 -> V_178 + ( ( ( T_3 ) V_167 - V_165 -> V_179 ) / sizeof( T_3 ) ) ;
V_50 |= ( V_172 << V_173 ) ;
V_172 = ( 0x1ull << V_173 ) ;
F_85 () ;
while ( V_48 <= V_50 ) {
if ( V_168 )
F_8 ( F_86 ( V_48 ) , V_169 ) ;
else
F_87 ( F_86 ( V_48 ) , V_169 ) ;
V_48 += V_172 ;
}
}
void F_89 ( struct V_164 * V_165 ,
T_12 * V_166 , T_12 * V_167 , bool V_168 )
{
struct V_1 * V_2 = F_90 ( V_165 , struct V_1 ,
V_154 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
if ( V_23 -> type == V_131 )
F_83 ( V_2 , V_165 , V_166 , V_167 , V_168 ) ;
else
F_88 ( V_2 , V_165 , V_166 , V_167 , V_168 ) ;
}
static void F_91 ( struct V_22 * V_23 ,
struct V_1 * V_2 , unsigned int V_55 ,
unsigned int V_180 )
{
struct V_181 * V_182 = NULL ;
const T_12 * V_183 ;
struct V_164 * V_165 ;
unsigned int V_57 ;
T_13 V_36 ;
void * V_184 ;
#define F_92 ((0x10000000 / 0x1000) * 8)
if ( F_16 ( V_2 -> V_148 >= 0 ) )
return;
V_2 -> V_148 = V_55 ;
F_65 ( V_2 , L_36 ,
( V_55 << 28 ) , ( ( V_55 + V_180 ) << 28 ) - 1 ) ;
V_182 = F_93 ( V_23 -> V_28 -> V_185 , V_69 ,
F_94 ( F_92 * V_180 ) ) ;
if ( ! V_182 ) {
F_57 ( V_2 , L_37 ) ;
goto V_43;
}
V_184 = F_95 ( V_182 ) ;
memset ( V_184 , 0 , F_92 * V_180 ) ;
for ( V_57 = 0 ; V_57 < V_180 ; V_57 ++ ) {
V_36 = F_96 ( V_23 -> V_37 ,
V_2 -> V_13 ,
V_55 + V_57 , 1 ,
F_84 ( V_184 ) + F_92 * V_57 ,
F_92 , 0x1000 ) ;
if ( V_36 ) {
F_57 ( V_2 , L_38
L_39 , V_36 ) ;
goto V_43;
}
}
V_165 = & V_2 -> V_154 ;
F_97 ( V_165 , V_184 , F_92 * V_180 ,
V_55 << 28 , V_186 ) ;
V_183 = F_37 ( V_23 -> V_28 -> V_79 , L_40 , NULL ) ;
if ( V_183 ) {
V_2 -> V_170 = F_98 ( V_183 ) ;
V_165 -> V_171 = ( unsigned long ) F_99 ( V_2 -> V_170 ,
8 ) ;
V_165 -> V_176 |= ( V_187 |
V_188 |
V_177 ) ;
}
F_100 ( V_165 , V_23 -> V_28 -> V_185 ) ;
F_101 ( V_165 , V_23 -> V_28 -> V_29 , V_2 -> V_13 ) ;
if ( V_2 -> V_9 )
F_72 ( & V_2 -> V_9 -> V_10 , V_165 ) ;
else
F_82 ( V_2 , V_2 -> V_11 , true ) ;
return;
V_43:
if ( V_2 -> V_148 >= 0 )
V_2 -> V_148 = - 1 ;
if ( V_182 )
F_102 ( V_182 , F_94 ( F_92 * V_180 ) ) ;
}
static void F_103 ( struct V_164 * V_165 , bool V_189 )
{
struct V_1 * V_2 = F_90 ( V_165 , struct V_1 ,
V_154 ) ;
T_14 V_190 = ( V_2 -> V_13 << 1 ) + 1 ;
T_13 V_36 ;
F_65 ( V_2 , L_41 , V_189 ? L_42 : L_43 ) ;
if ( V_189 ) {
T_15 V_156 = F_74 () ;
V_156 = F_104 ( V_156 ) ;
V_36 = F_105 ( V_2 -> V_23 -> V_37 ,
V_2 -> V_13 ,
V_190 ,
V_2 -> V_160 ,
V_156 ) ;
} else {
V_36 = F_105 ( V_2 -> V_23 -> V_37 ,
V_2 -> V_13 ,
V_190 ,
V_2 -> V_160 ,
0 ) ;
if ( V_2 -> V_9 )
F_78 ( & V_2 -> V_9 -> V_10 , V_165 ) ;
else
F_82 ( V_2 , V_2 -> V_11 , false ) ;
}
if ( V_36 )
F_57 ( V_2 , L_44 , V_36 ) ;
else
V_2 -> V_159 = V_189 ;
}
static void F_106 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
V_2 -> V_160 = 1ull << 59 ;
V_2 -> V_154 . V_191 = F_103 ;
F_103 ( & V_2 -> V_154 , true ) ;
}
static void F_107 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_181 * V_182 = NULL ;
void * V_184 ;
const T_12 * V_183 ;
struct V_164 * V_165 ;
unsigned int V_192 , V_50 ;
T_13 V_36 ;
if ( F_16 ( V_2 -> V_148 >= 0 ) )
return;
V_2 -> V_148 = 0 ;
V_50 = ( 1 << F_108 ( V_23 -> V_25 . V_193 ) ) ;
V_192 = ( V_50 / 0x1000 ) * 8 ;
F_65 ( V_2 , L_45 ,
V_50 ) ;
V_182 = F_93 ( V_23 -> V_28 -> V_185 , V_69 ,
F_94 ( V_192 ) ) ;
if ( ! V_182 ) {
F_57 ( V_2 , L_46 ) ;
goto V_43;
}
V_184 = F_95 ( V_182 ) ;
memset ( V_184 , 0 , V_192 ) ;
V_36 = F_96 ( V_23 -> V_37 , V_2 -> V_13 ,
V_2 -> V_13 << 1 , 1 , F_84 ( V_184 ) ,
V_192 , 0x1000 ) ;
if ( V_36 ) {
F_57 ( V_2 , L_47
L_39 , V_36 ) ;
goto V_43;
}
V_165 = & V_2 -> V_154 ;
F_97 ( V_165 , V_184 , V_192 , 0 ,
V_186 ) ;
V_183 = F_37 ( V_23 -> V_28 -> V_79 , L_40 , NULL ) ;
if ( V_183 ) {
V_2 -> V_170 = F_98 ( V_183 ) ;
V_165 -> V_171 = ( unsigned long ) F_99 ( V_2 -> V_170 ,
8 ) ;
V_165 -> V_176 |= ( V_187 | V_188 ) ;
}
F_100 ( V_165 , V_23 -> V_28 -> V_185 ) ;
F_101 ( V_165 , V_23 -> V_28 -> V_29 , V_2 -> V_13 ) ;
if ( V_2 -> V_9 )
F_72 ( & V_2 -> V_9 -> V_10 , V_165 ) ;
else
F_82 ( V_2 , V_2 -> V_11 , true ) ;
if ( ! V_16 )
F_106 ( V_23 , V_2 ) ;
return;
V_43:
if ( V_2 -> V_148 >= 0 )
V_2 -> V_148 = - 1 ;
if ( V_182 )
F_102 ( V_182 , F_94 ( V_192 ) ) ;
}
static void F_109 ( struct V_22 * V_23 )
{
struct V_77 * V_28 = V_23 -> V_28 ;
unsigned int V_194 , V_195 , V_180 , V_196 , V_55 ;
struct V_1 * V_2 ;
if ( V_23 -> V_25 . V_150 > V_23 -> V_25 . V_197 )
V_194 = 0 ;
else
V_194 = V_23 -> V_25 . V_197 -
V_23 -> V_25 . V_150 ;
F_7 ( L_48 ,
V_28 -> V_29 , V_23 -> V_25 . V_197 ) ;
F_7 ( L_49 ,
V_23 -> V_25 . V_150 , V_23 -> V_25 . V_136 ) ;
V_195 = V_23 -> V_25 . V_197 ;
V_196 = V_23 -> V_25 . V_136 ;
V_55 = 0 ;
F_23 (pe, &phb->ioda.pe_dma_list, dma_link) {
if ( ! V_2 -> V_136 )
continue;
if ( ! V_195 ) {
F_51 ( V_2 , L_50 ) ;
continue;
}
V_180 = 1 ;
if ( V_194 ) {
V_180 += ( ( V_2 -> V_136 * V_194 ) + ( V_196 / 2 ) ) / V_196 ;
if ( V_180 > V_195 )
V_180 = V_195 ;
}
if ( V_23 -> type == V_131 ) {
F_65 ( V_2 , L_51 ,
V_2 -> V_136 , V_180 ) ;
F_91 ( V_23 , V_2 , V_55 , V_180 ) ;
} else {
F_65 ( V_2 , L_52 ) ;
V_180 = 0 ;
F_107 ( V_23 , V_2 ) ;
}
V_195 -= V_180 ;
V_55 += V_180 ;
}
}
static void F_110 ( struct V_198 * V_199 )
{
unsigned int V_200 = ( unsigned int ) F_111 ( V_199 ) ;
struct V_201 * V_202 = F_112 ( V_199 ) ;
struct V_22 * V_23 = F_90 ( V_202 , struct V_22 ,
V_25 . V_201 ) ;
T_13 V_36 ;
V_36 = F_113 ( V_23 -> V_37 , V_200 ) ;
F_114 ( V_36 ) ;
F_115 ( V_199 ) ;
}
static void F_116 ( struct V_22 * V_23 , unsigned int V_203 )
{
struct V_198 * V_204 ;
struct V_201 * V_205 ;
if ( V_23 -> type != V_82 )
return;
if ( ! V_23 -> V_25 . V_206 ) {
V_204 = F_117 ( V_203 ) ;
V_205 = F_112 ( V_204 ) ;
V_23 -> V_25 . V_206 = 1 ;
V_23 -> V_25 . V_201 = * V_205 ;
V_23 -> V_25 . V_201 . V_207 = F_110 ;
}
F_118 ( V_203 , & V_23 -> V_25 . V_201 ) ;
}
struct V_78 * F_119 ( struct V_54 * V_10 )
{
struct V_77 * V_28 = F_47 ( V_10 -> V_62 ) ;
return F_120 ( V_28 -> V_79 ) ;
}
int F_121 ( struct V_54 * V_10 , T_11 V_208 )
{
struct V_77 * V_28 = F_47 ( V_10 -> V_62 ) ;
struct V_22 * V_23 = V_28 -> V_98 ;
struct V_1 * V_2 ;
int V_36 ;
V_2 = F_46 ( V_10 ) ;
if ( ! V_2 )
return - V_158 ;
F_65 ( V_2 , L_53 ) ;
V_36 = F_122 ( V_23 -> V_37 , V_208 , V_2 -> V_13 ) ;
if ( V_36 )
F_123 ( & V_10 -> V_10 , L_54 , V_36 ) ;
return V_36 ;
}
int F_124 ( struct V_54 * V_10 , int V_209 )
{
struct V_77 * V_28 = F_47 ( V_10 -> V_62 ) ;
struct V_22 * V_23 = V_28 -> V_98 ;
int V_210 = F_125 ( & V_23 -> V_211 , V_209 ) ;
if ( V_210 < 0 ) {
F_126 ( & V_10 -> V_10 , L_55 ) ;
return - V_212 ;
}
return V_23 -> V_213 + V_210 ;
}
void F_127 ( struct V_54 * V_10 , int V_210 , int V_209 )
{
struct V_77 * V_28 = F_47 ( V_10 -> V_62 ) ;
struct V_22 * V_23 = V_28 -> V_98 ;
F_128 ( & V_23 -> V_211 , V_210 - V_23 -> V_213 , V_209 ) ;
}
void F_129 ( struct V_214 * V_215 ,
struct V_54 * V_10 )
{
struct V_77 * V_28 = F_47 ( V_10 -> V_62 ) ;
struct V_22 * V_23 = V_28 -> V_98 ;
int V_57 , V_210 ;
for ( V_57 = 1 ; V_57 < V_216 ; V_57 ++ ) {
if ( ! V_215 -> V_217 [ V_57 ] )
continue;
F_130 ( L_56 ,
V_57 , V_215 -> V_218 [ V_57 ] ,
V_215 -> V_217 [ V_57 ] ) ;
V_210 = V_215 -> V_218 [ V_57 ] - V_23 -> V_213 ;
F_128 ( & V_23 -> V_211 , V_210 ,
V_215 -> V_217 [ V_57 ] ) ;
}
}
int F_131 ( struct V_214 * V_215 ,
struct V_54 * V_10 , int V_209 )
{
struct V_77 * V_28 = F_47 ( V_10 -> V_62 ) ;
struct V_22 * V_23 = V_28 -> V_98 ;
int V_57 , V_210 , V_219 ;
memset ( V_215 , 0 , sizeof( struct V_214 ) ) ;
for ( V_57 = 1 ; V_57 < V_216 && V_209 ; V_57 ++ ) {
V_219 = V_209 ;
while ( V_219 ) {
V_210 = F_125 ( & V_23 -> V_211 , V_219 ) ;
if ( V_210 >= 0 )
break;
V_219 /= 2 ;
}
if ( ! V_219 )
goto V_43;
V_215 -> V_218 [ V_57 ] = V_23 -> V_213 + V_210 ;
V_215 -> V_217 [ V_57 ] = V_219 ;
F_130 ( L_57 ,
V_57 , V_215 -> V_218 [ V_57 ] , V_215 -> V_217 [ V_57 ] ) ;
V_209 -= V_219 ;
}
if ( V_209 )
goto V_43;
return 0 ;
V_43:
F_129 ( V_215 , V_10 ) ;
return - V_212 ;
}
int F_132 ( struct V_54 * V_10 )
{
struct V_77 * V_28 = F_47 ( V_10 -> V_62 ) ;
struct V_22 * V_23 = V_28 -> V_98 ;
return V_23 -> V_211 . V_220 ;
}
int F_133 ( struct V_54 * V_10 , unsigned int V_210 ,
unsigned int V_203 )
{
struct V_77 * V_28 = F_47 ( V_10 -> V_62 ) ;
struct V_22 * V_23 = V_28 -> V_98 ;
unsigned int V_221 = V_210 - V_23 -> V_213 ;
struct V_1 * V_2 ;
int V_36 ;
if ( ! ( V_2 = F_46 ( V_10 ) ) )
return - V_158 ;
V_36 = F_134 ( V_23 -> V_37 , V_2 -> V_13 , V_221 ) ;
if ( V_36 ) {
F_51 ( V_2 , L_58
L_59 ,
F_55 ( V_10 ) , V_36 , V_23 -> V_213 , V_210 , V_221 ) ;
return - V_52 ;
}
F_116 ( V_23 , V_203 ) ;
return 0 ;
}
static int F_135 ( struct V_22 * V_23 , struct V_54 * V_10 ,
unsigned int V_210 , unsigned int V_203 ,
unsigned int V_222 , struct V_223 * V_224 )
{
struct V_1 * V_2 = F_46 ( V_10 ) ;
unsigned int V_221 = V_210 - V_23 -> V_213 ;
T_16 V_225 ;
int V_36 ;
if ( V_2 == NULL )
return - V_106 ;
if ( V_2 -> V_132 < 0 )
return - V_106 ;
if ( V_10 -> V_226 )
V_222 = 0 ;
V_36 = F_134 ( V_23 -> V_37 , V_2 -> V_13 , V_221 ) ;
if ( V_36 ) {
F_11 ( L_60 ,
F_55 ( V_10 ) , V_36 , V_221 ) ;
return - V_52 ;
}
if ( V_222 ) {
T_12 V_227 ;
V_36 = F_136 ( V_23 -> V_37 , V_2 -> V_132 , V_221 , 1 ,
& V_227 , & V_225 ) ;
if ( V_36 ) {
F_11 ( L_61 ,
F_55 ( V_10 ) , V_36 ) ;
return - V_52 ;
}
V_224 -> V_228 = F_137 ( V_227 ) >> 32 ;
V_224 -> V_229 = F_137 ( V_227 ) & 0xfffffffful ;
} else {
T_16 V_230 ;
V_36 = F_138 ( V_23 -> V_37 , V_2 -> V_132 , V_221 , 1 ,
& V_230 , & V_225 ) ;
if ( V_36 ) {
F_11 ( L_62 ,
F_55 ( V_10 ) , V_36 ) ;
return - V_52 ;
}
V_224 -> V_228 = 0 ;
V_224 -> V_229 = F_139 ( V_230 ) ;
}
V_224 -> V_225 = F_139 ( V_225 ) ;
F_116 ( V_23 , V_203 ) ;
F_130 ( L_63
L_64 ,
F_55 ( V_10 ) , V_222 ? L_65 : L_66 , V_210 , V_221 ,
V_224 -> V_228 , V_224 -> V_229 , V_225 , V_2 -> V_13 ) ;
return 0 ;
}
static void F_140 ( struct V_22 * V_23 )
{
unsigned int V_117 ;
const T_16 * V_231 = F_37 ( V_23 -> V_28 -> V_79 ,
L_67 , NULL ) ;
if ( ! V_231 ) {
V_231 = F_37 ( V_23 -> V_28 -> V_79 , L_68 , NULL ) ;
}
if ( ! V_231 )
return;
V_23 -> V_213 = F_141 ( V_231 ) ;
V_117 = F_141 ( V_231 + 1 ) ;
if ( F_142 ( & V_23 -> V_211 , V_117 , V_23 -> V_28 -> V_79 ) ) {
F_54 ( L_69 ,
V_23 -> V_28 -> V_29 ) ;
return;
}
V_23 -> V_232 = F_135 ;
V_23 -> V_233 = 1 ;
F_7 ( L_70 ,
V_117 , V_23 -> V_213 ) ;
}
static void F_140 ( struct V_22 * V_23 ) { }
static void F_143 ( struct V_77 * V_28 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_28 -> V_98 ;
struct V_234 V_235 ;
struct V_34 * V_80 ;
int V_57 , V_236 ;
int V_36 ;
F_144 ( ! ( V_2 -> V_19 & ( V_110 | V_109 ) ) ) ;
F_27 (pe->pbus, res, i) {
if ( ! V_80 || ! V_80 -> V_19 ||
V_80 -> V_48 > V_80 -> V_50 )
continue;
if ( V_80 -> V_19 & V_237 ) {
V_235 . V_48 = V_80 -> V_48 - V_23 -> V_25 . V_238 ;
V_235 . V_50 = V_80 -> V_50 - V_23 -> V_25 . V_238 ;
V_236 = V_235 . V_48 / V_23 -> V_25 . V_239 ;
while ( V_236 < V_23 -> V_25 . V_26 &&
V_235 . V_48 <= V_235 . V_50 ) {
V_23 -> V_25 . V_240 [ V_236 ] = V_2 -> V_13 ;
V_36 = F_145 ( V_23 -> V_37 ,
V_2 -> V_13 , V_241 , 0 , V_236 ) ;
if ( V_36 != V_42 ) {
F_54 ( L_71
L_72 ,
V_27 , V_36 , V_236 , V_2 -> V_13 ) ;
break;
}
V_235 . V_48 += V_23 -> V_25 . V_239 ;
V_236 ++ ;
}
} else if ( V_80 -> V_19 & V_85 ) {
V_235 . V_48 = V_80 -> V_48 -
V_28 -> V_86 [ 0 ] -
V_23 -> V_25 . V_193 ;
V_235 . V_50 = V_80 -> V_50 -
V_28 -> V_86 [ 0 ] -
V_23 -> V_25 . V_193 ;
V_236 = V_235 . V_48 / V_23 -> V_25 . V_242 ;
while ( V_236 < V_23 -> V_25 . V_26 &&
V_235 . V_48 <= V_235 . V_50 ) {
V_23 -> V_25 . V_243 [ V_236 ] = V_2 -> V_13 ;
V_36 = F_145 ( V_23 -> V_37 ,
V_2 -> V_13 , V_244 , 0 , V_236 ) ;
if ( V_36 != V_42 ) {
F_54 ( L_73
L_74 ,
V_27 , V_36 , V_236 , V_2 -> V_13 ) ;
break;
}
V_235 . V_48 += V_23 -> V_25 . V_242 ;
V_236 ++ ;
}
}
}
}
static void F_146 ( void )
{
struct V_77 * V_152 , * V_28 ;
struct V_22 * V_23 ;
struct V_1 * V_2 ;
F_69 (hose, tmp, &hose_list, list_node) {
V_23 = V_28 -> V_98 ;
F_23 (pe, &phb->ioda.pe_list, list) {
F_143 ( V_28 , V_2 ) ;
}
}
}
static void F_147 ( void )
{
struct V_77 * V_28 , * V_152 ;
struct V_22 * V_23 ;
F_69 (hose, tmp, &hose_list, list_node) {
F_109 ( V_28 -> V_98 ) ;
V_23 = V_28 -> V_98 ;
V_23 -> V_245 = 1 ;
}
}
static void F_148 ( void )
{
#ifdef F_149
struct V_77 * V_28 , * V_152 ;
struct V_22 * V_23 ;
char V_246 [ 16 ] ;
F_69 (hose, tmp, &hose_list, list_node) {
V_23 = V_28 -> V_98 ;
sprintf ( V_246 , L_75 , V_28 -> V_29 ) ;
V_23 -> V_247 = F_150 ( V_246 , V_248 ) ;
if ( ! V_23 -> V_247 )
F_64 ( L_76 ,
V_27 , V_28 -> V_29 ) ;
}
#endif
}
static void F_151 ( void )
{
F_68 () ;
F_146 () ;
F_147 () ;
F_148 () ;
#ifdef F_152
F_153 () ;
F_154 () ;
#endif
}
static T_6 F_155 ( struct V_61 * V_62 ,
unsigned long type )
{
struct V_54 * V_249 ;
struct V_77 * V_28 = F_47 ( V_62 ) ;
struct V_22 * V_23 = V_28 -> V_98 ;
int V_250 = 0 ;
V_249 = V_62 -> V_111 ;
while ( V_249 ) {
if ( F_67 ( V_249 ) == V_151 ) {
V_250 ++ ;
if ( V_250 >= 2 )
return 1 ;
}
V_249 = V_249 -> V_62 -> V_111 ;
}
if ( V_23 -> V_25 . V_49 &&
F_9 ( type ) )
return V_23 -> V_25 . V_49 ;
if ( type & V_85 )
return V_23 -> V_25 . V_242 ;
return V_23 -> V_25 . V_239 ;
}
static int F_156 ( struct V_54 * V_10 )
{
struct V_77 * V_28 = F_47 ( V_10 -> V_62 ) ;
struct V_22 * V_23 = V_28 -> V_98 ;
struct V_99 * V_100 ;
if ( ! V_23 -> V_245 )
return 0 ;
V_100 = F_48 ( V_10 ) ;
if ( ! V_100 || V_100 -> V_13 == V_32 )
return - V_15 ;
return 0 ;
}
static T_7 F_157 ( struct V_22 * V_23 , struct V_61 * V_62 ,
T_7 V_251 )
{
return V_23 -> V_25 . V_130 [ ( V_62 -> V_12 << 8 ) | V_251 ] ;
}
static void F_158 ( struct V_22 * V_23 )
{
F_159 ( V_23 -> V_37 , V_252 ,
V_253 ) ;
}
static void T_2 F_160 ( struct V_78 * V_254 ,
T_3 V_255 , int V_256 )
{
struct V_77 * V_28 ;
struct V_22 * V_23 ;
unsigned long V_66 , V_257 , V_258 , V_259 = 0 ;
const T_12 * V_260 ;
const T_16 * V_261 ;
int V_262 ;
T_3 V_263 ;
void * V_264 ;
long V_36 ;
F_7 ( L_77 , V_256 , V_254 -> V_84 ) ;
V_260 = F_37 ( V_254 , L_78 , NULL ) ;
if ( ! V_260 ) {
F_54 ( L_79 ) ;
return;
}
V_263 = F_98 ( V_260 ) ;
F_161 ( L_80 , V_263 ) ;
V_23 = F_162 ( sizeof( struct V_22 ) , 0 ) ;
V_23 -> V_28 = V_28 = F_163 ( V_254 ) ;
if ( ! V_23 -> V_28 ) {
F_54 ( L_81 ,
V_254 -> V_84 ) ;
F_164 ( F_84 ( V_23 ) , sizeof( struct V_22 ) ) ;
return;
}
F_165 ( & V_23 -> V_265 ) ;
V_261 = F_37 ( V_254 , L_82 , & V_262 ) ;
if ( V_261 && V_262 == 8 ) {
V_28 -> V_266 = F_139 ( V_261 [ 0 ] ) ;
V_28 -> V_267 = F_139 ( V_261 [ 1 ] ) ;
} else {
F_11 ( L_83 , V_254 -> V_84 ) ;
V_28 -> V_266 = 0 ;
V_28 -> V_267 = 0xff ;
}
V_28 -> V_98 = V_23 ;
V_23 -> V_255 = V_255 ;
V_23 -> V_37 = V_263 ;
V_23 -> type = V_256 ;
if ( F_166 ( V_254 , L_84 ) )
V_23 -> V_268 = V_269 ;
else if ( F_166 ( V_254 , L_85 ) )
V_23 -> V_268 = V_270 ;
else
V_23 -> V_268 = V_271 ;
F_167 ( V_28 , V_254 , ! V_28 -> V_29 ) ;
V_23 -> V_272 = F_168 ( V_254 , 0 ) ;
if ( V_23 -> V_272 == NULL )
F_54 ( L_86 ) ;
V_23 -> V_25 . V_26 = 1 ;
V_261 = F_37 ( V_254 , L_87 , NULL ) ;
if ( V_261 )
V_23 -> V_25 . V_26 = F_141 ( V_261 ) ;
V_261 = F_37 ( V_254 , L_88 , NULL ) ;
if ( V_261 )
V_23 -> V_25 . V_47 = F_141 ( V_261 ) ;
F_35 ( V_23 ) ;
V_23 -> V_25 . V_273 = F_24 ( & V_28 -> V_46 [ 0 ] ) ;
V_23 -> V_25 . V_273 += 0x10000 ;
V_23 -> V_25 . V_242 = V_23 -> V_25 . V_273 / V_23 -> V_25 . V_26 ;
V_23 -> V_25 . V_193 = V_28 -> V_46 [ 0 ] . V_48 - V_28 -> V_86 [ 0 ] ;
V_23 -> V_25 . V_274 = V_28 -> V_275 ;
V_23 -> V_25 . V_239 = V_23 -> V_25 . V_274 / V_23 -> V_25 . V_26 ;
V_23 -> V_25 . V_238 = 0 ;
V_66 = F_28 ( V_23 -> V_25 . V_26 / 8 , sizeof( unsigned long ) ) ;
V_257 = V_66 ;
V_66 += V_23 -> V_25 . V_26 * sizeof( V_23 -> V_25 . V_243 [ 0 ] ) ;
if ( V_23 -> type == V_131 ) {
V_259 = V_66 ;
V_66 += V_23 -> V_25 . V_26 * sizeof( V_23 -> V_25 . V_240 [ 0 ] ) ;
}
V_258 = V_66 ;
V_66 += V_23 -> V_25 . V_26 * sizeof( struct V_1 ) ;
V_264 = F_162 ( V_66 , 0 ) ;
V_23 -> V_25 . V_30 = V_264 ;
V_23 -> V_25 . V_243 = V_264 + V_257 ;
if ( V_23 -> type == V_131 )
V_23 -> V_25 . V_240 = V_264 + V_259 ;
V_23 -> V_25 . V_31 = V_264 + V_258 ;
F_21 ( V_23 -> V_25 . V_47 , V_23 -> V_25 . V_30 ) ;
F_33 ( & V_23 -> V_25 . V_138 ) ;
F_33 ( & V_23 -> V_25 . V_149 ) ;
V_23 -> V_25 . V_197 = V_23 -> V_25 . V_193 >> 28 ;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
F_7 ( L_89 ,
V_23 -> V_25 . V_26 , V_23 -> V_25 . V_47 ,
V_23 -> V_25 . V_273 , V_23 -> V_25 . V_242 ) ;
if ( V_23 -> V_25 . V_41 )
F_7 ( L_90 ,
V_23 -> V_25 . V_41 , V_23 -> V_25 . V_49 ) ;
if ( V_23 -> V_25 . V_274 )
F_7 ( L_91 ,
V_23 -> V_25 . V_274 , V_23 -> V_25 . V_239 ) ;
V_23 -> V_28 -> V_276 = & V_277 ;
V_23 -> V_278 = F_44 ;
V_23 -> V_279 = F_40 ;
V_23 -> V_280 = F_42 ;
#ifdef F_152
V_23 -> V_281 = & V_282 ;
#endif
V_23 -> V_283 = F_157 ;
V_23 -> V_284 = F_70 ;
V_23 -> V_285 = F_73 ;
V_23 -> V_286 = F_79 ;
V_23 -> V_287 = F_158 ;
F_140 ( V_23 ) ;
V_288 . V_289 = F_151 ;
V_288 . V_290 = F_156 ;
V_288 . V_291 = F_155 ;
V_288 . V_292 = V_293 ;
F_169 ( V_294 ) ;
V_36 = F_159 ( V_263 , V_252 , V_253 ) ;
if ( V_36 )
F_64 ( L_92 , V_36 ) ;
if ( F_170 () ) {
F_7 ( L_93 ) ;
F_171 ( V_28 , V_295 ) ;
F_171 ( V_28 , V_296 ) ;
}
if ( ! V_23 -> V_87 || V_23 -> V_87 ( V_23 ) )
V_28 -> V_46 [ 1 ] . V_19 = 0 ;
}
void T_2 F_172 ( struct V_78 * V_254 )
{
F_160 ( V_254 , 0 , V_82 ) ;
}
void T_2 F_173 ( struct V_78 * V_254 )
{
struct V_78 * V_297 ;
const T_12 * V_260 ;
T_3 V_255 ;
F_7 ( L_94 , V_254 -> V_84 ) ;
V_260 = F_37 ( V_254 , L_95 , NULL ) ;
if ( ! V_260 ) {
F_54 ( L_96 ) ;
return;
}
V_255 = F_98 ( V_260 ) ;
F_130 ( L_97 , V_255 ) ;
F_174 (np, phbn) {
if ( F_166 ( V_297 , L_98 ) )
F_160 ( V_297 , V_255 , V_131 ) ;
}
}
