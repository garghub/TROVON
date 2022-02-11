static void F_1 ( const struct V_1 * V_2 , const char * V_3 ,
const char * V_4 , ... )
{
struct V_5 V_6 ;
T_1 args ;
char V_7 [ 32 ] ;
va_start ( args , V_4 ) ;
V_6 . V_4 = V_4 ;
V_6 . V_8 = & args ;
if ( V_2 -> V_9 & V_10 )
F_2 ( V_7 , F_3 ( & V_2 -> V_11 -> V_12 ) , sizeof( V_7 ) ) ;
else if ( V_2 -> V_9 & ( V_13 | V_14 ) )
sprintf ( V_7 , L_1 ,
F_4 ( V_2 -> V_15 ) , V_2 -> V_15 -> V_16 ) ;
#ifdef F_5
else if ( V_2 -> V_9 & V_17 )
sprintf ( V_7 , L_2 ,
F_4 ( V_2 -> V_18 -> V_19 ) ,
( V_2 -> V_20 & 0xff00 ) >> 8 ,
F_6 ( V_2 -> V_20 ) , F_7 ( V_2 -> V_20 ) ) ;
#endif
F_8 ( L_3 ,
V_3 , V_7 , V_2 -> V_21 , & V_6 ) ;
va_end ( args ) ;
}
static int T_2 F_9 ( char * V_22 )
{
if ( ! V_22 )
return - V_23 ;
while ( * V_22 ) {
if ( ! strncmp ( V_22 , L_4 , 8 ) ) {
V_24 = true ;
F_10 ( L_5 ) ;
break;
}
V_22 += strcspn ( V_22 , L_6 ) ;
if ( * V_22 == ',' )
V_22 ++ ;
}
return 0 ;
}
static inline void F_11 ( T_3 V_25 , volatile void T_4 * V_26 )
{
__asm__ __volatile__("stdcix %0,0,%1"
: : "r" (val), "r" (paddr) : "memory");
}
static inline bool F_12 ( unsigned long V_9 )
{
return ( ( V_9 & ( V_27 | V_28 ) ) ==
( V_27 | V_28 ) ) ;
}
static void F_13 ( struct V_29 * V_30 , int V_31 )
{
if ( ! ( V_31 >= 0 && V_31 < V_30 -> V_32 . V_33 ) ) {
F_14 ( L_7 ,
V_34 , V_31 , V_30 -> V_35 -> V_36 ) ;
return;
}
if ( F_15 ( V_31 , V_30 -> V_32 . V_37 ) ) {
F_14 ( L_8 ,
V_34 , V_31 , V_30 -> V_35 -> V_36 ) ;
return;
}
V_30 -> V_32 . V_38 [ V_31 ] . V_30 = V_30 ;
V_30 -> V_32 . V_38 [ V_31 ] . V_21 = V_31 ;
}
static int F_16 ( struct V_29 * V_30 )
{
unsigned long V_2 ;
do {
V_2 = F_17 ( V_30 -> V_32 . V_37 ,
V_30 -> V_32 . V_33 , 0 ) ;
if ( V_2 >= V_30 -> V_32 . V_33 )
return V_39 ;
} while( F_15 ( V_2 , V_30 -> V_32 . V_37 ) );
V_30 -> V_32 . V_38 [ V_2 ] . V_30 = V_30 ;
V_30 -> V_32 . V_38 [ V_2 ] . V_21 = V_2 ;
return V_2 ;
}
static void F_18 ( struct V_29 * V_30 , int V_2 )
{
F_19 ( V_30 -> V_32 . V_38 [ V_2 ] . V_11 ) ;
memset ( & V_30 -> V_32 . V_38 [ V_2 ] , 0 , sizeof( struct V_1 ) ) ;
F_20 ( V_2 , V_30 -> V_32 . V_37 ) ;
}
static int F_21 ( struct V_29 * V_30 )
{
const char * V_40 ;
struct V_41 * V_42 ;
T_5 V_43 ;
V_43 = F_22 ( V_30 -> V_44 ,
V_45 ,
V_30 -> V_32 . V_46 ,
V_30 -> V_32 . V_47 ,
0 ,
V_30 -> V_32 . V_48 ) ;
if ( V_43 != V_49 ) {
V_40 = L_9 ;
goto V_50;
}
V_43 = F_23 ( V_30 -> V_44 ,
V_45 ,
V_30 -> V_32 . V_46 ,
V_51 ) ;
if ( V_43 != V_49 ) {
V_40 = L_10 ;
goto V_50;
}
F_24 ( V_30 -> V_32 . V_46 , & V_30 -> V_32 . V_52 ) ;
V_42 = & V_30 -> V_35 -> V_53 [ 1 ] ;
if ( V_30 -> V_32 . V_54 == 0 )
V_42 -> V_55 += V_30 -> V_32 . V_56 ;
else if ( V_30 -> V_32 . V_54 == ( V_30 -> V_32 . V_33 - 1 ) )
V_42 -> V_57 -= V_30 -> V_32 . V_56 ;
else
F_14 ( L_11 ,
V_30 -> V_32 . V_54 ) ;
return 0 ;
V_50:
F_14 ( L_12 ,
V_43 , V_40 , V_30 -> V_32 . V_46 ) ;
F_23 ( V_30 -> V_44 ,
V_45 ,
V_30 -> V_32 . V_46 ,
V_58 ) ;
return - V_59 ;
}
static void F_25 ( struct V_29 * V_30 )
{
T_6 V_60 = V_30 -> V_32 . V_56 ;
struct V_61 * V_11 ;
struct V_41 * V_42 ;
int V_62 , V_63 , V_64 ;
F_26 (pdev, &phb->hose->bus->devices, bus_list) {
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
V_42 = & V_11 -> V_41 [ V_66 + V_64 ] ;
if ( ! V_42 -> V_67 ||
! F_12 ( V_42 -> V_9 ) )
continue;
V_62 = ( V_42 -> V_55 - V_30 -> V_32 . V_47 ) / V_60 ;
for ( V_63 = 0 ; V_63 < F_27 ( V_42 ) / V_60 ; V_63 ++ )
F_13 ( V_30 , V_62 + V_63 ) ;
}
}
}
static int F_28 ( struct V_29 * V_30 ,
struct V_68 * V_19 , int V_69 )
{
T_6 V_70 = V_30 -> V_32 . V_56 ;
struct V_61 * V_11 ;
struct V_41 * V_42 ;
struct V_1 * V_71 , * V_2 ;
unsigned long V_72 , * V_37 ;
bool V_73 ;
int V_55 , V_64 , V_74 ;
if ( F_29 ( V_19 ) )
return V_39 ;
V_73 = false ;
F_30 (bus, r, i) {
if ( V_42 && V_42 -> V_67 &&
F_12 ( V_42 -> V_9 ) ) {
V_73 = true ;
break;
}
}
if ( ! V_73 )
return V_39 ;
V_72 = F_31 ( V_30 -> V_32 . V_33 / 8 , sizeof( unsigned long ) ) ;
V_37 = F_32 ( V_72 , V_75 ) ;
if ( ! V_37 ) {
F_14 ( L_13 ,
V_34 ) ;
return V_39 ;
}
V_55 = ( V_42 -> V_55 - V_30 -> V_32 . V_47 ) / V_70 ;
for ( V_64 = 0 ; V_64 < F_27 ( V_42 ) / V_70 ; V_64 ++ )
F_24 ( V_55 + V_64 , V_37 ) ;
if ( V_69 )
goto V_76;
F_26 (pdev, &bus->devices, bus_list) {
if ( ! V_11 -> V_77 )
continue;
F_30 (pdev->subordinate, r, i) {
if ( ! V_42 || ! V_42 -> V_67 ||
! F_12 ( V_42 -> V_9 ) )
continue;
V_55 = ( V_42 -> V_55 - V_30 -> V_32 . V_47 ) / V_70 ;
for ( V_74 = 0 ; V_74 < F_27 ( V_42 ) / V_70 ; V_74 ++ )
F_20 ( V_55 + V_74 , V_37 ) ;
}
}
if ( F_33 ( V_37 , V_30 -> V_32 . V_33 ) ) {
F_34 ( V_37 ) ;
return V_39 ;
}
V_76:
V_71 = NULL ;
V_64 = - 1 ;
while ( ( V_64 = F_35 ( V_37 , V_30 -> V_32 . V_33 , V_64 + 1 ) ) <
V_30 -> V_32 . V_33 ) {
V_2 = & V_30 -> V_32 . V_38 [ V_64 ] ;
if ( ! V_71 ) {
V_2 -> V_9 |= V_78 ;
F_36 ( & V_2 -> V_79 ) ;
V_71 = V_2 ;
} else {
V_2 -> V_9 |= V_80 ;
V_2 -> V_81 = V_71 ;
F_37 ( & V_2 -> V_82 , & V_71 -> V_79 ) ;
}
}
F_34 ( V_37 ) ;
return V_71 -> V_21 ;
}
static void T_2 F_38 ( struct V_29 * V_30 )
{
struct V_83 * V_35 = V_30 -> V_35 ;
struct V_84 * V_85 = V_35 -> V_85 ;
struct V_41 * V_86 ;
const T_7 * V_42 ;
T_3 V_87 ;
if ( V_30 -> type != V_88 ) {
F_10 ( L_14 ) ;
return;
}
if ( ! F_39 ( V_89 ) ) {
F_10 ( L_15 ) ;
return;
}
V_42 = F_40 ( V_85 , L_16 , NULL ) ;
if ( ! V_42 ) {
F_10 ( L_17 ,
V_85 -> V_90 ) ;
return;
}
V_86 = & V_35 -> V_53 [ 1 ] ;
V_86 -> V_55 = F_41 ( V_85 , V_42 + 2 ) ;
V_86 -> V_57 = V_86 -> V_55 + F_42 ( V_42 + 4 , 2 ) - 1 ;
V_86 -> V_9 = ( V_91 | V_27 | V_28 ) ;
V_87 = F_42 ( V_42 , 2 ) ;
V_35 -> V_92 [ 1 ] = V_86 -> V_55 - V_87 ;
V_30 -> V_32 . V_48 = F_27 ( V_86 ) ;
V_30 -> V_32 . V_56 = V_30 -> V_32 . V_48 / V_30 -> V_32 . V_33 ;
V_30 -> V_32 . V_47 = V_87 ;
F_10 ( L_18 ,
V_86 -> V_55 , V_86 -> V_57 , V_87 ) ;
V_30 -> V_32 . V_46 = 15 ;
V_30 -> V_93 = F_21 ;
V_30 -> V_94 = F_25 ;
V_30 -> V_95 = F_28 ;
}
static void F_43 ( struct V_29 * V_30 , int V_31 )
{
struct V_1 * V_2 = & V_30 -> V_32 . V_38 [ V_31 ] ;
struct V_1 * V_96 ;
T_5 V_43 ;
if ( V_2 -> V_9 & V_80 ) {
V_2 = V_2 -> V_81 ;
if ( F_19 ( ! V_2 || ! ( V_2 -> V_9 & V_78 ) ) )
return;
V_31 = V_2 -> V_21 ;
}
V_43 = F_44 ( V_30 -> V_44 ,
V_31 ,
V_97 ) ;
if ( V_43 != V_49 ) {
F_14 ( L_19 ,
V_34 , V_43 , V_30 -> V_35 -> V_36 , V_31 ) ;
return;
}
if ( ! ( V_2 -> V_9 & V_78 ) )
return;
F_26 (slave, &pe->slaves, list) {
V_43 = F_44 ( V_30 -> V_44 ,
V_96 -> V_21 ,
V_97 ) ;
if ( V_43 != V_49 )
F_14 ( L_19 ,
V_34 , V_43 , V_30 -> V_35 -> V_36 ,
V_96 -> V_21 ) ;
}
}
static int F_45 ( struct V_29 * V_30 , int V_31 , int V_98 )
{
struct V_1 * V_2 , * V_96 ;
T_5 V_43 ;
V_2 = & V_30 -> V_32 . V_38 [ V_31 ] ;
if ( V_2 -> V_9 & V_80 ) {
V_2 = V_2 -> V_81 ;
F_19 ( ! V_2 || ! ( V_2 -> V_9 & V_78 ) ) ;
V_31 = V_2 -> V_21 ;
}
V_43 = F_46 ( V_30 -> V_44 , V_31 , V_98 ) ;
if ( V_43 != V_49 ) {
F_14 ( L_20 ,
V_34 , V_43 , V_98 , V_30 -> V_35 -> V_36 , V_31 ) ;
return - V_59 ;
}
if ( ! ( V_2 -> V_9 & V_78 ) )
return 0 ;
F_26 (slave, &pe->slaves, list) {
V_43 = F_46 ( V_30 -> V_44 ,
V_96 -> V_21 ,
V_98 ) ;
if ( V_43 != V_49 ) {
F_14 ( L_20 ,
V_34 , V_43 , V_98 , V_30 -> V_35 -> V_36 ,
V_96 -> V_21 ) ;
return - V_59 ;
}
}
return 0 ;
}
static int F_47 ( struct V_29 * V_30 , int V_31 )
{
struct V_1 * V_96 , * V_2 ;
T_8 V_99 , V_100 ;
T_9 V_101 ;
T_5 V_43 ;
if ( V_31 < 0 || V_31 >= V_30 -> V_32 . V_33 )
return V_102 ;
V_2 = & V_30 -> V_32 . V_38 [ V_31 ] ;
if ( V_2 -> V_9 & V_80 ) {
V_2 = V_2 -> V_81 ;
F_19 ( ! V_2 || ! ( V_2 -> V_9 & V_78 ) ) ;
V_31 = V_2 -> V_21 ;
}
V_43 = F_48 ( V_30 -> V_44 , V_31 ,
& V_100 , & V_101 , NULL ) ;
if ( V_43 != V_49 ) {
F_14 ( L_21
L_22 ,
V_34 , V_43 ,
V_30 -> V_35 -> V_36 , V_31 ) ;
return V_103 ;
}
if ( ! ( V_2 -> V_9 & V_78 ) )
return V_100 ;
F_26 (slave, &pe->slaves, list) {
V_43 = F_48 ( V_30 -> V_44 ,
V_96 -> V_21 ,
& V_99 ,
& V_101 ,
NULL ) ;
if ( V_43 != V_49 ) {
F_14 ( L_21
L_22 ,
V_34 , V_43 ,
V_30 -> V_35 -> V_36 , V_96 -> V_21 ) ;
return V_103 ;
}
if ( V_99 > V_100 )
V_100 = V_99 ;
}
return V_100 ;
}
static struct V_1 * F_49 ( struct V_61 * V_12 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
struct V_105 * V_106 = F_51 ( V_12 ) ;
if ( ! V_106 )
return NULL ;
if ( V_106 -> V_21 == V_39 )
return NULL ;
return & V_30 -> V_32 . V_38 [ V_106 -> V_21 ] ;
}
static int F_52 ( struct V_29 * V_30 ,
struct V_1 * V_67 ,
struct V_1 * V_107 ,
bool V_108 )
{
const char * V_40 = V_108 ? L_23 : L_24 ;
T_10 V_109 = V_108 ? V_110 :
V_111 ;
struct V_1 * V_96 ;
long V_43 ;
V_43 = F_53 ( V_30 -> V_44 , V_67 -> V_21 ,
V_107 -> V_21 , V_109 ) ;
if ( V_43 != V_49 ) {
F_54 ( V_107 , L_25 ,
V_43 , V_40 ) ;
return - V_112 ;
}
if ( ! ( V_107 -> V_9 & V_78 ) )
return 0 ;
F_26 (slave, &child->slaves, list) {
V_43 = F_53 ( V_30 -> V_44 , V_67 -> V_21 ,
V_96 -> V_21 , V_109 ) ;
if ( V_43 != V_49 ) {
F_54 ( V_96 , L_25 ,
V_43 , V_40 ) ;
return - V_112 ;
}
}
return 0 ;
}
static int F_55 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
bool V_108 )
{
struct V_1 * V_96 ;
struct V_61 * V_11 = NULL ;
int V_113 ;
if ( V_108 ) {
F_46 ( V_30 -> V_44 , V_2 -> V_21 ,
V_114 ) ;
if ( V_2 -> V_9 & V_78 ) {
F_26 (slave, &pe->slaves, list)
F_46 ( V_30 -> V_44 ,
V_96 -> V_21 ,
V_114 ) ;
}
}
V_113 = F_52 ( V_30 , V_2 , V_2 , V_108 ) ;
if ( V_113 )
return V_113 ;
if ( V_2 -> V_9 & V_78 ) {
F_26 (slave, &pe->slaves, list) {
V_113 = F_52 ( V_30 , V_96 , V_2 , V_108 ) ;
if ( V_113 )
return V_113 ;
}
}
if ( V_2 -> V_9 & ( V_14 | V_13 ) )
V_11 = V_2 -> V_15 -> V_115 ;
else if ( V_2 -> V_9 & V_10 )
V_11 = V_2 -> V_11 -> V_19 -> V_115 ;
#ifdef F_5
else if ( V_2 -> V_9 & V_17 )
V_11 = V_2 -> V_18 -> V_19 -> V_115 ;
#endif
while ( V_11 ) {
struct V_105 * V_106 = F_51 ( V_11 ) ;
struct V_1 * V_67 ;
if ( V_106 && V_106 -> V_21 != V_39 ) {
V_67 = & V_30 -> V_32 . V_38 [ V_106 -> V_21 ] ;
V_113 = F_52 ( V_30 , V_67 , V_2 , V_108 ) ;
if ( V_113 )
return V_113 ;
}
V_11 = V_11 -> V_19 -> V_115 ;
}
return 0 ;
}
static int F_56 ( struct V_29 * V_30 , struct V_1 * V_2 )
{
struct V_61 * V_67 ;
T_10 V_116 , V_117 , V_118 ;
T_11 V_43 ;
long V_119 , V_20 ;
if ( V_2 -> V_15 ) {
int V_120 ;
V_117 = V_121 ;
V_118 = V_122 ;
V_67 = V_2 -> V_15 -> V_115 ;
if ( V_2 -> V_9 & V_14 )
V_120 = V_2 -> V_15 -> V_123 . V_57 - V_2 -> V_15 -> V_123 . V_55 + 1 ;
else
V_120 = 1 ;
switch( V_120 ) {
case 1 : V_116 = V_124 ; break;
case 2 : V_116 = V_125 ; break;
case 4 : V_116 = V_126 ; break;
case 8 : V_116 = V_127 ; break;
case 16 : V_116 = V_128 ; break;
case 32 : V_116 = V_129 ; break;
default:
F_57 ( & V_2 -> V_15 -> V_12 , L_26 ,
V_120 ) ;
V_116 = V_124 ;
}
V_119 = V_2 -> V_20 + ( V_120 << 8 ) ;
} else {
if ( V_2 -> V_9 & V_17 )
V_67 = V_2 -> V_18 ;
else
V_67 = V_2 -> V_11 -> V_19 -> V_115 ;
V_116 = V_124 ;
V_117 = V_130 ;
V_118 = V_131 ;
V_119 = V_2 -> V_20 + 1 ;
}
for ( V_20 = V_2 -> V_20 ; V_20 < V_119 ; V_20 ++ )
V_30 -> V_32 . V_132 [ V_20 ] = 0 ;
while ( V_67 ) {
struct V_105 * V_106 = F_51 ( V_67 ) ;
if ( V_106 && V_106 -> V_21 != V_39 ) {
V_43 = F_53 ( V_30 -> V_44 , V_106 -> V_21 ,
V_2 -> V_21 , V_111 ) ;
}
V_67 = V_67 -> V_19 -> V_115 ;
}
F_44 ( V_30 -> V_44 , V_2 -> V_21 ,
V_114 ) ;
V_43 = F_53 ( V_30 -> V_44 , V_2 -> V_21 ,
V_2 -> V_21 , V_111 ) ;
if ( V_43 )
F_54 ( V_2 , L_27 , V_43 ) ;
V_43 = F_58 ( V_30 -> V_44 , V_2 -> V_21 , V_2 -> V_20 ,
V_116 , V_117 , V_118 , V_133 ) ;
if ( V_43 )
F_59 ( V_2 , L_28 , V_43 ) ;
V_2 -> V_15 = NULL ;
V_2 -> V_11 = NULL ;
V_2 -> V_18 = NULL ;
return 0 ;
}
static int F_60 ( struct V_29 * V_30 , struct V_1 * V_2 )
{
struct V_61 * V_67 ;
T_10 V_116 , V_117 , V_118 ;
long V_43 , V_119 , V_20 ;
if ( V_2 -> V_15 ) {
int V_120 ;
V_117 = V_121 ;
V_118 = V_122 ;
V_67 = V_2 -> V_15 -> V_115 ;
if ( V_2 -> V_9 & V_14 )
V_120 = V_2 -> V_15 -> V_123 . V_57 - V_2 -> V_15 -> V_123 . V_55 + 1 ;
else
V_120 = 1 ;
switch( V_120 ) {
case 1 : V_116 = V_124 ; break;
case 2 : V_116 = V_125 ; break;
case 4 : V_116 = V_126 ; break;
case 8 : V_116 = V_127 ; break;
case 16 : V_116 = V_128 ; break;
case 32 : V_116 = V_129 ; break;
default:
F_57 ( & V_2 -> V_15 -> V_12 , L_26 ,
V_120 ) ;
V_116 = V_124 ;
}
V_119 = V_2 -> V_20 + ( V_120 << 8 ) ;
} else {
#ifdef F_5
if ( V_2 -> V_9 & V_17 )
V_67 = V_2 -> V_18 ;
else
#endif
V_67 = V_2 -> V_11 -> V_19 -> V_115 ;
V_116 = V_124 ;
V_117 = V_130 ;
V_118 = V_131 ;
V_119 = V_2 -> V_20 + 1 ;
}
V_43 = F_58 ( V_30 -> V_44 , V_2 -> V_21 , V_2 -> V_20 ,
V_116 , V_117 , V_118 , V_134 ) ;
if ( V_43 ) {
F_59 ( V_2 , L_28 , V_43 ) ;
return - V_112 ;
}
F_55 ( V_30 , V_2 , true ) ;
for ( V_20 = V_2 -> V_20 ; V_20 < V_119 ; V_20 ++ )
V_30 -> V_32 . V_132 [ V_20 ] = V_2 -> V_21 ;
if ( V_30 -> type != V_135 ) {
V_2 -> V_136 = 0 ;
goto V_137;
}
V_2 -> V_136 = V_2 -> V_21 ;
V_43 = F_61 ( V_30 -> V_44 , V_2 -> V_136 , V_2 -> V_21 ) ;
if ( V_43 != V_49 ) {
F_59 ( V_2 , L_29 ,
V_43 , V_2 -> V_136 ) ;
V_2 -> V_136 = - 1 ;
} else {
V_43 = F_62 ( V_30 -> V_44 ,
V_2 -> V_136 , V_138 ) ;
if ( V_43 ) {
F_59 ( V_2 , L_30 ,
V_43 , V_2 -> V_136 ) ;
V_2 -> V_136 = - 1 ;
}
}
V_137:
return 0 ;
}
static void F_63 ( struct V_29 * V_30 ,
struct V_1 * V_2 )
{
struct V_1 * V_139 ;
F_26 (lpe, &phb->ioda.pe_dma_list, dma_link) {
if ( V_139 -> V_140 < V_2 -> V_140 ) {
F_37 ( & V_2 -> V_141 , & V_139 -> V_141 ) ;
return;
}
}
F_37 ( & V_2 -> V_141 , & V_30 -> V_32 . V_142 ) ;
}
static unsigned int F_64 ( struct V_61 * V_12 )
{
if ( V_12 -> V_143 != V_144 )
return 0 ;
if ( V_12 -> V_145 == V_146 ||
V_12 -> V_145 == V_147 ||
V_12 -> V_145 == V_148 )
return 3 ;
if ( ( V_12 -> V_145 >> 8 ) == V_149 )
return 15 ;
return 10 ;
}
static int F_65 ( struct V_61 * V_12 , int V_150 )
{
struct V_105 * V_106 = F_51 ( V_12 ) ;
int V_64 ;
struct V_41 * V_86 , V_151 ;
T_6 V_72 ;
T_12 V_152 ;
if ( ! V_12 -> V_153 )
return - V_23 ;
V_152 = V_106 -> V_152 ;
for ( V_64 = 0 ; V_64 < V_154 ; V_64 ++ ) {
V_86 = & V_12 -> V_41 [ V_64 + V_155 ] ;
if ( ! V_86 -> V_9 || ! V_86 -> V_67 )
continue;
if ( ! F_12 ( V_86 -> V_9 ) )
continue;
V_72 = F_66 ( V_12 , V_64 + V_155 ) ;
V_151 . V_9 = V_86 -> V_9 ;
V_151 . V_55 = V_86 -> V_55 + ( V_72 * V_150 ) ;
V_151 . V_57 = V_151 . V_55 + ( V_72 * V_152 ) - 1 ;
if ( V_151 . V_57 > V_86 -> V_57 ) {
F_57 ( & V_12 -> V_12 , L_31 ,
V_64 , & V_151 , V_86 , V_152 , V_150 ) ;
return - V_156 ;
}
}
for ( V_64 = 0 ; V_64 < V_154 ; V_64 ++ ) {
V_86 = & V_12 -> V_41 [ V_64 + V_155 ] ;
if ( ! V_86 -> V_9 || ! V_86 -> V_67 )
continue;
if ( ! F_12 ( V_86 -> V_9 ) )
continue;
V_72 = F_66 ( V_12 , V_64 + V_155 ) ;
V_151 = * V_86 ;
V_86 -> V_55 += V_72 * V_150 ;
F_67 ( & V_12 -> V_12 , L_32 ,
V_64 , & V_151 , V_86 , V_152 , V_150 ) ;
F_68 ( V_12 , V_64 + V_155 ) ;
}
return 0 ;
}
static void F_69 ( struct V_68 * V_19 , struct V_1 * V_2 )
{
struct V_61 * V_12 ;
F_26 (dev, &bus->devices, bus_list) {
struct V_105 * V_106 = F_51 ( V_12 ) ;
if ( V_106 == NULL ) {
F_14 ( L_33 ,
F_70 ( V_12 ) ) ;
continue;
}
V_106 -> V_21 = V_2 -> V_21 ;
V_2 -> V_140 += F_64 ( V_12 ) ;
if ( ( V_2 -> V_9 & V_14 ) && V_12 -> V_77 )
F_69 ( V_12 -> V_77 , V_2 ) ;
}
}
static void F_71 ( struct V_68 * V_19 , int V_69 )
{
struct V_83 * V_35 = F_50 ( V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
struct V_1 * V_2 ;
int V_157 = V_39 ;
if ( V_30 -> V_95 )
V_157 = V_30 -> V_95 ( V_30 , V_19 , V_69 ) ;
if ( V_157 == V_39 )
V_157 = F_16 ( V_30 ) ;
if ( V_157 == V_39 ) {
F_72 ( L_34 ,
V_34 , F_4 ( V_19 ) , V_19 -> V_16 ) ;
return;
}
V_2 = & V_30 -> V_32 . V_38 [ V_157 ] ;
V_2 -> V_9 |= ( V_69 ? V_14 : V_13 ) ;
V_2 -> V_15 = V_19 ;
V_2 -> V_11 = NULL ;
V_2 -> V_158 = - 1 ;
V_2 -> V_136 = - 1 ;
V_2 -> V_20 = V_19 -> V_123 . V_55 << 8 ;
V_2 -> V_140 = 0 ;
if ( V_69 )
F_73 ( V_2 , L_35 ,
V_19 -> V_123 . V_55 , V_19 -> V_123 . V_57 , V_157 ) ;
else
F_73 ( V_2 , L_36 ,
V_19 -> V_123 . V_55 , V_157 ) ;
if ( F_60 ( V_30 , V_2 ) ) {
if ( V_157 )
F_18 ( V_30 , V_157 ) ;
V_2 -> V_15 = NULL ;
return;
}
V_2 -> V_159 = F_74 ( sizeof( struct V_160 ) ,
V_75 , V_35 -> V_161 ) ;
V_2 -> V_159 -> V_162 = V_2 ;
F_69 ( V_19 , V_2 ) ;
F_37 ( & V_2 -> V_82 , & V_30 -> V_32 . V_163 ) ;
if ( V_2 -> V_140 != 0 ) {
V_30 -> V_32 . V_140 += V_2 -> V_140 ;
V_30 -> V_32 . V_164 ++ ;
}
F_63 ( V_30 , V_2 ) ;
}
static void F_75 ( struct V_68 * V_19 )
{
struct V_61 * V_12 ;
F_71 ( V_19 , 0 ) ;
F_26 (dev, &bus->devices, bus_list) {
if ( V_12 -> V_77 ) {
if ( F_76 ( V_12 ) == V_165 )
F_71 ( V_12 -> V_77 , 1 ) ;
else
F_75 ( V_12 -> V_77 ) ;
}
}
}
static void F_77 ( void )
{
struct V_83 * V_35 , * V_166 ;
struct V_29 * V_30 ;
F_78 (hose, tmp, &hose_list, list_node) {
V_30 = V_35 -> V_104 ;
if ( V_30 -> V_94 )
V_30 -> V_94 ( V_30 ) ;
F_75 ( V_35 -> V_19 ) ;
}
}
static int F_79 ( struct V_61 * V_11 )
{
struct V_68 * V_19 ;
struct V_83 * V_35 ;
struct V_29 * V_30 ;
struct V_105 * V_106 ;
int V_64 , V_74 ;
V_19 = V_11 -> V_19 ;
V_35 = F_50 ( V_19 ) ;
V_30 = V_35 -> V_104 ;
V_106 = F_51 ( V_11 ) ;
for ( V_64 = 0 ; V_64 < V_154 ; V_64 ++ )
for ( V_74 = 0 ; V_74 < V_167 ; V_74 ++ ) {
if ( V_106 -> V_168 [ V_64 ] [ V_74 ] == V_169 )
continue;
F_23 ( V_30 -> V_44 ,
V_45 , V_106 -> V_168 [ V_64 ] [ V_74 ] , 0 ) ;
F_20 ( V_106 -> V_168 [ V_64 ] [ V_74 ] , & V_30 -> V_32 . V_52 ) ;
V_106 -> V_168 [ V_64 ] [ V_74 ] = V_169 ;
}
return 0 ;
}
static int F_80 ( struct V_61 * V_11 , T_12 V_152 )
{
struct V_68 * V_19 ;
struct V_83 * V_35 ;
struct V_29 * V_30 ;
struct V_105 * V_106 ;
unsigned int V_170 ;
struct V_41 * V_86 ;
int V_64 , V_74 ;
T_11 V_43 ;
int V_171 ;
T_6 V_72 , V_55 ;
int V_157 ;
int V_172 ;
int V_173 ;
V_19 = V_11 -> V_19 ;
V_35 = F_50 ( V_19 ) ;
V_30 = V_35 -> V_104 ;
V_106 = F_51 ( V_11 ) ;
V_171 = F_81 ( V_11 ) ;
for ( V_64 = 0 ; V_64 < V_154 ; V_64 ++ )
for ( V_74 = 0 ; V_74 < V_167 ; V_74 ++ )
V_106 -> V_168 [ V_64 ] [ V_74 ] = V_169 ;
if ( V_106 -> V_174 == V_167 ) {
V_172 = ( V_152 <= V_167 ) ? V_152 : V_167 ;
V_173 = ( V_152 <= V_167 ) ? 1 :
F_82 ( V_152 ) / V_106 -> V_174 ;
} else {
V_172 = 1 ;
V_173 = 1 ;
}
for ( V_64 = 0 ; V_64 < V_154 ; V_64 ++ ) {
V_86 = & V_11 -> V_41 [ V_64 + V_155 ] ;
if ( ! V_86 -> V_9 || ! V_86 -> V_67 )
continue;
if ( ! F_12 ( V_86 -> V_9 ) )
continue;
for ( V_74 = 0 ; V_74 < V_172 ; V_74 ++ ) {
do {
V_170 = F_17 ( & V_30 -> V_32 . V_52 ,
V_30 -> V_32 . V_46 + 1 , 0 ) ;
if ( V_170 >= V_30 -> V_32 . V_46 + 1 )
goto V_175;
} while ( F_15 ( V_170 , & V_30 -> V_32 . V_52 ) );
V_106 -> V_168 [ V_64 ] [ V_74 ] = V_170 ;
if ( V_106 -> V_174 == V_167 ) {
V_72 = F_66 ( V_11 ,
V_155 + V_64 ) ;
V_72 = V_72 * V_173 ;
V_55 = V_86 -> V_55 + V_72 * V_74 ;
} else {
V_72 = F_27 ( V_86 ) ;
V_55 = V_86 -> V_55 ;
}
if ( V_106 -> V_174 == V_167 ) {
V_157 = V_106 -> V_150 + V_74 ;
V_43 = F_83 ( V_30 -> V_44 ,
V_157 , V_45 ,
V_106 -> V_168 [ V_64 ] [ V_74 ] , 0 ) ;
}
V_43 = F_22 ( V_30 -> V_44 ,
V_45 ,
V_106 -> V_168 [ V_64 ] [ V_74 ] ,
V_55 ,
0 ,
V_72 ) ;
if ( V_43 != V_49 ) {
F_57 ( & V_11 -> V_12 , L_37 ,
V_170 , V_43 ) ;
goto V_175;
}
if ( V_106 -> V_174 == V_167 )
V_43 = F_23 ( V_30 -> V_44 ,
V_45 , V_106 -> V_168 [ V_64 ] [ V_74 ] , 2 ) ;
else
V_43 = F_23 ( V_30 -> V_44 ,
V_45 , V_106 -> V_168 [ V_64 ] [ V_74 ] , 1 ) ;
if ( V_43 != V_49 ) {
F_57 ( & V_11 -> V_12 , L_38 ,
V_170 , V_43 ) ;
goto V_175;
}
}
}
return 0 ;
V_175:
F_79 ( V_11 ) ;
return - V_156 ;
}
static void F_84 ( struct V_61 * V_12 , struct V_1 * V_2 )
{
struct V_68 * V_19 ;
struct V_83 * V_35 ;
struct V_29 * V_30 ;
struct V_160 * V_176 ;
unsigned long V_177 ;
T_11 V_43 ;
V_19 = V_12 -> V_19 ;
V_35 = F_50 ( V_19 ) ;
V_30 = V_35 -> V_104 ;
V_176 = V_2 -> V_159 ;
V_177 = V_176 -> V_178 ;
F_85 ( V_30 -> V_44 , V_2 -> V_21 ,
V_2 -> V_21 << 1 , 1 , F_86 ( V_177 ) ,
0 , 0x1000 ) ;
V_43 = F_87 ( V_2 -> V_30 -> V_44 ,
V_2 -> V_21 ,
( V_2 -> V_21 << 1 ) + 1 ,
V_2 -> V_179 ,
0 ) ;
if ( V_43 )
F_54 ( V_2 , L_39 , V_43 ) ;
F_88 ( V_176 , F_89 ( V_12 -> V_12 . V_180 ) ) ;
F_90 ( V_177 , F_91 ( V_181 ) ) ;
V_2 -> V_159 = NULL ;
}
static void F_92 ( struct V_61 * V_11 , T_12 V_152 )
{
struct V_68 * V_19 ;
struct V_83 * V_35 ;
struct V_29 * V_30 ;
struct V_1 * V_2 , * V_182 ;
struct V_105 * V_106 ;
T_12 V_183 ;
T_11 V_43 ;
V_19 = V_11 -> V_19 ;
V_35 = F_50 ( V_19 ) ;
V_30 = V_35 -> V_104 ;
V_106 = F_51 ( V_11 ) ;
if ( ! V_11 -> V_153 )
return;
if ( V_106 -> V_174 == V_167 && V_152 > V_167 ) {
int V_184 ;
int V_173 ;
int V_185 ;
V_173 = F_82 ( V_152 ) / V_106 -> V_174 ;
for ( V_184 = 0 ; V_184 < V_167 ; V_184 ++ )
for ( V_183 = V_184 * V_173 ;
V_183 < ( V_184 + 1 ) * V_173 &&
V_183 < V_152 ;
V_183 ++ )
for ( V_185 = V_184 * V_173 ;
V_185 < ( V_184 + 1 ) * V_173 &&
V_185 < V_152 ;
V_185 ++ ) {
V_43 = F_53 ( V_30 -> V_44 ,
V_106 -> V_150 + V_183 ,
V_106 -> V_150 + V_185 ,
V_111 ) ;
if ( V_43 )
F_93 ( & V_11 -> V_12 , L_40 ,
V_34 ,
V_106 -> V_150 + V_185 , V_43 ) ;
}
}
F_78 (pe, pe_n, &phb->ioda.pe_list, list) {
if ( V_2 -> V_18 != V_11 )
continue;
F_84 ( V_11 , V_2 ) ;
F_94 ( & V_30 -> V_32 . V_186 ) ;
F_95 ( & V_2 -> V_82 ) ;
F_96 ( & V_30 -> V_32 . V_186 ) ;
F_56 ( V_30 , V_2 ) ;
F_18 ( V_30 , V_2 -> V_21 ) ;
}
}
void F_97 ( struct V_61 * V_11 )
{
struct V_68 * V_19 ;
struct V_83 * V_35 ;
struct V_29 * V_30 ;
struct V_105 * V_106 ;
struct V_187 * V_188 ;
T_12 V_152 ;
V_19 = V_11 -> V_19 ;
V_35 = F_50 ( V_19 ) ;
V_30 = V_35 -> V_104 ;
V_106 = F_51 ( V_11 ) ;
V_188 = V_11 -> V_189 ;
V_152 = V_106 -> V_152 ;
F_92 ( V_11 , V_152 ) ;
if ( V_30 -> type == V_88 ) {
if ( V_106 -> V_174 == 1 )
F_65 ( V_11 , - V_106 -> V_150 ) ;
F_79 ( V_11 ) ;
F_98 ( V_30 -> V_32 . V_37 , V_106 -> V_150 , V_152 ) ;
V_106 -> V_150 = 0 ;
}
}
static void F_99 ( struct V_61 * V_11 , T_12 V_152 )
{
struct V_68 * V_19 ;
struct V_83 * V_35 ;
struct V_29 * V_30 ;
struct V_1 * V_2 ;
int V_157 ;
T_12 V_183 ;
struct V_105 * V_106 ;
T_11 V_43 ;
V_19 = V_11 -> V_19 ;
V_35 = F_50 ( V_19 ) ;
V_30 = V_35 -> V_104 ;
V_106 = F_51 ( V_11 ) ;
if ( ! V_11 -> V_153 )
return;
for ( V_183 = 0 ; V_183 < V_152 ; V_183 ++ ) {
V_157 = V_106 -> V_150 + V_183 ;
V_2 = & V_30 -> V_32 . V_38 [ V_157 ] ;
V_2 -> V_21 = V_157 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_9 = V_17 ;
V_2 -> V_15 = NULL ;
V_2 -> V_18 = V_11 ;
V_2 -> V_158 = - 1 ;
V_2 -> V_136 = - 1 ;
V_2 -> V_20 = ( F_100 ( V_11 , V_183 ) << 8 ) |
F_101 ( V_11 , V_183 ) ;
F_73 ( V_2 , L_41 ,
V_35 -> V_36 , V_11 -> V_19 -> V_16 ,
F_6 ( F_101 ( V_11 , V_183 ) ) ,
F_7 ( F_101 ( V_11 , V_183 ) ) , V_157 ) ;
if ( F_60 ( V_30 , V_2 ) ) {
if ( V_157 )
F_18 ( V_30 , V_157 ) ;
V_2 -> V_11 = NULL ;
continue;
}
V_2 -> V_159 = F_74 ( sizeof( struct V_160 ) ,
V_75 , V_35 -> V_161 ) ;
V_2 -> V_159 -> V_162 = V_2 ;
F_94 ( & V_30 -> V_32 . V_186 ) ;
F_37 ( & V_2 -> V_82 , & V_30 -> V_32 . V_163 ) ;
F_96 ( & V_30 -> V_32 . V_186 ) ;
F_102 ( V_30 , V_2 ) ;
}
if ( V_106 -> V_174 == V_167 && V_152 > V_167 ) {
int V_184 ;
int V_173 ;
int V_185 ;
V_173 = F_82 ( V_152 ) / V_106 -> V_174 ;
for ( V_184 = 0 ; V_184 < V_167 ; V_184 ++ ) {
for ( V_183 = V_184 * V_173 ;
V_183 < ( V_184 + 1 ) * V_173 &&
V_183 < V_152 ;
V_183 ++ ) {
for ( V_185 = V_184 * V_173 ;
V_185 < ( V_184 + 1 ) * V_173 &&
V_185 < V_152 ;
V_185 ++ ) {
V_43 = F_53 ( V_30 -> V_44 ,
V_106 -> V_150 + V_183 ,
V_106 -> V_150 + V_185 ,
V_110 ) ;
if ( V_43 )
F_93 ( & V_11 -> V_12 , L_42 ,
V_34 ,
V_106 -> V_150 + V_185 , V_43 ) ;
}
}
}
}
}
int F_103 ( struct V_61 * V_11 , T_12 V_152 )
{
struct V_68 * V_19 ;
struct V_83 * V_35 ;
struct V_29 * V_30 ;
struct V_105 * V_106 ;
int V_113 ;
V_19 = V_11 -> V_19 ;
V_35 = F_50 ( V_19 ) ;
V_30 = V_35 -> V_104 ;
V_106 = F_51 ( V_11 ) ;
if ( V_30 -> type == V_88 ) {
F_94 ( & V_30 -> V_32 . V_190 ) ;
V_106 -> V_150 = F_104 (
V_30 -> V_32 . V_37 , V_30 -> V_32 . V_33 ,
0 , V_152 , 0 ) ;
if ( V_106 -> V_150 >= V_30 -> V_32 . V_33 ) {
F_96 ( & V_30 -> V_32 . V_190 ) ;
F_67 ( & V_11 -> V_12 , L_43 , V_152 ) ;
V_106 -> V_150 = 0 ;
return - V_156 ;
}
F_105 ( V_30 -> V_32 . V_37 , V_106 -> V_150 , V_152 ) ;
V_106 -> V_152 = V_152 ;
F_96 ( & V_30 -> V_32 . V_190 ) ;
V_113 = F_80 ( V_11 , V_152 ) ;
if ( V_113 ) {
F_67 ( & V_11 -> V_12 , L_44 ) ;
goto V_175;
}
if ( V_106 -> V_174 == 1 ) {
V_113 = F_65 ( V_11 , V_106 -> V_150 ) ;
if ( V_113 )
goto V_175;
}
}
F_99 ( V_11 , V_152 ) ;
return 0 ;
V_175:
F_98 ( V_30 -> V_32 . V_37 , V_106 -> V_150 , V_152 ) ;
V_106 -> V_150 = 0 ;
return V_113 ;
}
int F_106 ( struct V_61 * V_11 )
{
F_97 ( V_11 ) ;
F_107 ( V_11 ) ;
return 0 ;
}
int F_108 ( struct V_61 * V_11 , T_12 V_152 )
{
F_109 ( V_11 ) ;
F_103 ( V_11 , V_152 ) ;
return 0 ;
}
static void F_110 ( struct V_29 * V_30 , struct V_61 * V_11 )
{
struct V_105 * V_106 = F_51 ( V_11 ) ;
struct V_1 * V_2 ;
if ( ! V_106 || V_106 -> V_21 == V_39 )
return;
V_2 = & V_30 -> V_32 . V_38 [ V_106 -> V_21 ] ;
F_19 ( F_111 ( & V_11 -> V_12 ) != & V_191 ) ;
F_112 ( & V_11 -> V_12 , V_2 -> V_159 ) ;
}
static int F_113 ( struct V_29 * V_30 ,
struct V_61 * V_11 , T_3 V_192 )
{
struct V_105 * V_106 = F_51 ( V_11 ) ;
struct V_1 * V_2 ;
T_13 V_193 ;
bool V_194 = false ;
if ( F_19 ( ! V_106 || V_106 -> V_21 == V_39 ) )
return - V_195 ; ;
V_2 = & V_30 -> V_32 . V_38 [ V_106 -> V_21 ] ;
if ( V_2 -> V_196 ) {
V_193 = V_2 -> V_179 + F_114 () - 1 ;
V_194 = ( V_192 >= V_193 ) ;
}
if ( V_194 ) {
F_67 ( & V_11 -> V_12 , L_45 ) ;
F_115 ( & V_11 -> V_12 , & V_197 ) ;
F_116 ( & V_11 -> V_12 , V_2 -> V_179 ) ;
} else {
F_67 ( & V_11 -> V_12 , L_46 ) ;
F_115 ( & V_11 -> V_12 , & V_191 ) ;
F_117 ( & V_11 -> V_12 , V_2 -> V_159 ) ;
}
* V_11 -> V_12 . V_192 = V_192 ;
return 0 ;
}
static T_3 F_118 ( struct V_29 * V_30 ,
struct V_61 * V_11 )
{
struct V_105 * V_106 = F_51 ( V_11 ) ;
struct V_1 * V_2 ;
T_3 V_57 , V_198 ;
if ( F_19 ( ! V_106 || V_106 -> V_21 == V_39 ) )
return 0 ;
V_2 = & V_30 -> V_32 . V_38 [ V_106 -> V_21 ] ;
if ( ! V_2 -> V_196 )
return F_119 ( & V_11 -> V_12 ) ;
V_57 = V_2 -> V_179 + F_114 () ;
V_198 = 1ULL << ( F_120 ( V_57 ) - 1 ) ;
V_198 += V_198 - 1 ;
return V_198 ;
}
static void F_121 ( struct V_1 * V_2 ,
struct V_68 * V_19 ,
bool V_199 )
{
struct V_61 * V_12 ;
F_26 (dev, &bus->devices, bus_list) {
if ( V_199 )
F_112 ( & V_12 -> V_12 ,
V_2 -> V_159 ) ;
else
F_117 ( & V_12 -> V_12 , V_2 -> V_159 ) ;
if ( V_12 -> V_77 )
F_121 ( V_2 , V_12 -> V_77 ,
V_199 ) ;
}
}
static void F_122 ( struct V_1 * V_2 ,
struct V_160 * V_176 ,
T_14 * V_200 , T_14 * V_201 , bool V_202 )
{
T_14 T_4 * V_203 = V_202 ?
( T_14 T_4 * ) V_2 -> V_204 :
( T_14 T_4 * ) V_176 -> V_205 ;
unsigned long V_55 , V_57 , V_206 ;
const unsigned V_207 = V_176 -> V_208 ;
V_55 = F_86 ( V_200 ) ;
V_57 = F_86 ( V_201 ) ;
if ( V_176 -> V_209 ) {
V_55 <<= V_207 ;
V_57 <<= V_207 ;
V_206 = 128ull << V_207 ;
V_55 |= V_176 -> V_209 ;
V_57 |= V_176 -> V_209 ;
} else if ( V_176 -> V_210 & V_211 ) {
V_55 |= ( 1ull << 63 ) ;
V_57 |= ( 1ull << 63 ) ;
V_206 = 16 ;
} else {
V_206 = 128 ;
}
V_57 |= V_206 - 1 ;
F_123 () ;
while ( V_55 <= V_57 ) {
if ( V_202 )
F_11 ( F_124 ( V_55 ) , V_203 ) ;
else
F_125 ( F_124 ( V_55 ) , V_203 ) ;
V_55 += V_206 ;
}
}
static void F_126 ( struct V_1 * V_2 ,
struct V_160 * V_176 ,
T_14 * V_200 , T_14 * V_201 , bool V_202 )
{
unsigned long V_55 , V_57 , V_206 ;
T_14 T_4 * V_203 = V_202 ?
( T_14 T_4 * ) V_2 -> V_204 :
( T_14 T_4 * ) V_176 -> V_205 ;
const unsigned V_207 = V_176 -> V_208 ;
V_55 = 0x2ull << 60 ;
V_55 |= ( V_2 -> V_21 & 0xFF ) ;
V_57 = V_55 ;
V_206 = V_176 -> V_212 + ( ( ( T_3 ) V_200 - V_176 -> V_178 ) / sizeof( T_3 ) ) ;
V_55 |= ( V_206 << V_207 ) ;
V_206 = V_176 -> V_212 + ( ( ( T_3 ) V_201 - V_176 -> V_178 ) / sizeof( T_3 ) ) ;
V_57 |= ( V_206 << V_207 ) ;
V_206 = ( 0x1ull << V_207 ) ;
F_123 () ;
while ( V_55 <= V_57 ) {
if ( V_202 )
F_11 ( F_124 ( V_55 ) , V_203 ) ;
else
F_125 ( F_124 ( V_55 ) , V_203 ) ;
V_55 += V_206 ;
}
}
void F_127 ( struct V_160 * V_176 ,
T_14 * V_200 , T_14 * V_201 , bool V_202 )
{
struct V_1 * V_2 = V_176 -> V_162 ;
struct V_29 * V_30 = V_2 -> V_30 ;
if ( V_30 -> type == V_135 )
F_122 ( V_2 , V_176 , V_200 , V_201 , V_202 ) ;
else
F_126 ( V_2 , V_176 , V_200 , V_201 , V_202 ) ;
}
static void F_128 ( struct V_29 * V_30 ,
struct V_1 * V_2 , unsigned int V_62 ,
unsigned int V_213 )
{
struct V_214 * V_215 = NULL ;
const T_14 * V_216 ;
struct V_160 * V_176 ;
unsigned int V_64 ;
T_11 V_43 ;
void * V_177 ;
if ( F_19 ( V_2 -> V_158 >= 0 ) )
return;
V_2 -> V_158 = V_62 ;
F_73 ( V_2 , L_47 ,
( V_62 << 28 ) , ( ( V_62 + V_213 ) << 28 ) - 1 ) ;
V_215 = F_129 ( V_30 -> V_35 -> V_161 , V_75 ,
F_91 ( V_181 * V_213 ) ) ;
if ( ! V_215 ) {
F_59 ( V_2 , L_48 ) ;
goto V_50;
}
V_177 = F_130 ( V_215 ) ;
memset ( V_177 , 0 , V_181 * V_213 ) ;
for ( V_64 = 0 ; V_64 < V_213 ; V_64 ++ ) {
V_43 = F_85 ( V_30 -> V_44 ,
V_2 -> V_21 ,
V_62 + V_64 , 1 ,
F_86 ( V_177 ) + V_181 * V_64 ,
V_181 , 0x1000 ) ;
if ( V_43 ) {
F_59 ( V_2 , L_49
L_50 , V_43 ) ;
goto V_50;
}
}
V_176 = V_2 -> V_159 ;
F_131 ( V_176 , V_177 , V_181 * V_213 ,
V_62 << 28 , V_217 ) ;
V_216 = F_40 ( V_30 -> V_35 -> V_85 , L_51 , NULL ) ;
if ( V_216 ) {
V_2 -> V_204 = F_132 ( V_216 ) ;
V_176 -> V_205 = ( unsigned long ) F_133 ( V_2 -> V_204 ,
8 ) ;
V_176 -> V_210 |= ( V_218 |
V_219 |
V_211 ) ;
}
F_134 ( V_176 , V_30 -> V_35 -> V_161 ) ;
if ( V_2 -> V_9 & V_10 ) {
F_135 ( V_176 , V_30 -> V_35 -> V_36 ,
V_2 -> V_21 ) ;
F_112 ( & V_2 -> V_11 -> V_12 , V_176 ) ;
} else if ( V_2 -> V_9 & ( V_13 | V_14 ) ) {
F_135 ( V_176 , V_30 -> V_35 -> V_36 ,
V_2 -> V_21 ) ;
F_121 ( V_2 , V_2 -> V_15 , true ) ;
} else if ( V_2 -> V_9 & V_17 ) {
F_135 ( V_176 , V_30 -> V_35 -> V_36 ,
V_2 -> V_21 ) ;
}
return;
V_50:
if ( V_2 -> V_158 >= 0 )
V_2 -> V_158 = - 1 ;
if ( V_215 )
F_136 ( V_215 , F_91 ( V_181 * V_213 ) ) ;
}
static void F_137 ( struct V_160 * V_176 , bool V_220 )
{
struct V_1 * V_2 = V_176 -> V_162 ;
T_15 V_221 = ( V_2 -> V_21 << 1 ) + 1 ;
T_11 V_43 ;
F_73 ( V_2 , L_52 , V_220 ? L_53 : L_54 ) ;
if ( V_220 ) {
T_16 V_193 = F_114 () ;
V_193 = F_82 ( V_193 ) ;
V_43 = F_87 ( V_2 -> V_30 -> V_44 ,
V_2 -> V_21 ,
V_221 ,
V_2 -> V_179 ,
V_193 ) ;
} else {
V_43 = F_87 ( V_2 -> V_30 -> V_44 ,
V_2 -> V_21 ,
V_221 ,
V_2 -> V_179 ,
0 ) ;
if ( V_2 -> V_11 )
F_117 ( & V_2 -> V_11 -> V_12 , V_176 ) ;
else
F_121 ( V_2 , V_2 -> V_15 , false ) ;
}
if ( V_43 )
F_59 ( V_2 , L_55 , V_43 ) ;
else
V_2 -> V_196 = V_220 ;
}
static void F_138 ( struct V_29 * V_30 ,
struct V_1 * V_2 )
{
V_2 -> V_179 = 1ull << 59 ;
V_2 -> V_159 -> V_222 = F_137 ;
F_137 ( V_2 -> V_159 , true ) ;
}
static void F_102 ( struct V_29 * V_30 ,
struct V_1 * V_2 )
{
struct V_214 * V_215 = NULL ;
void * V_177 ;
const T_14 * V_216 ;
struct V_160 * V_176 ;
unsigned int V_223 , V_57 ;
T_11 V_43 ;
if ( F_19 ( V_2 -> V_158 >= 0 ) )
return;
V_2 -> V_158 = 0 ;
V_57 = ( 1 << F_139 ( V_30 -> V_32 . V_224 ) ) ;
V_223 = ( V_57 / 0x1000 ) * 8 ;
F_73 ( V_2 , L_56 ,
V_57 ) ;
V_215 = F_129 ( V_30 -> V_35 -> V_161 , V_75 ,
F_91 ( V_223 ) ) ;
if ( ! V_215 ) {
F_59 ( V_2 , L_57 ) ;
goto V_50;
}
V_177 = F_130 ( V_215 ) ;
memset ( V_177 , 0 , V_223 ) ;
V_43 = F_85 ( V_30 -> V_44 , V_2 -> V_21 ,
V_2 -> V_21 << 1 , 1 , F_86 ( V_177 ) ,
V_223 , 0x1000 ) ;
if ( V_43 ) {
F_59 ( V_2 , L_58
L_50 , V_43 ) ;
goto V_50;
}
V_176 = V_2 -> V_159 ;
F_131 ( V_176 , V_177 , V_223 , 0 ,
V_217 ) ;
V_216 = F_40 ( V_30 -> V_35 -> V_85 , L_51 , NULL ) ;
if ( V_216 ) {
V_2 -> V_204 = F_132 ( V_216 ) ;
V_176 -> V_205 = ( unsigned long ) F_133 ( V_2 -> V_204 ,
8 ) ;
V_176 -> V_210 |= ( V_218 | V_219 ) ;
}
F_134 ( V_176 , V_30 -> V_35 -> V_161 ) ;
if ( V_2 -> V_9 & V_10 ) {
F_135 ( V_176 , V_30 -> V_35 -> V_36 ,
V_2 -> V_21 ) ;
F_112 ( & V_2 -> V_11 -> V_12 , V_176 ) ;
} else if ( V_2 -> V_9 & ( V_13 | V_14 ) ) {
F_135 ( V_176 , V_30 -> V_35 -> V_36 ,
V_2 -> V_21 ) ;
F_121 ( V_2 , V_2 -> V_15 , true ) ;
} else if ( V_2 -> V_9 & V_17 ) {
F_135 ( V_176 , V_30 -> V_35 -> V_36 ,
V_2 -> V_21 ) ;
}
if ( ! V_24 )
F_138 ( V_30 , V_2 ) ;
return;
V_50:
if ( V_2 -> V_158 >= 0 )
V_2 -> V_158 = - 1 ;
if ( V_215 )
F_136 ( V_215 , F_91 ( V_223 ) ) ;
}
static void F_140 ( struct V_29 * V_30 )
{
struct V_83 * V_35 = V_30 -> V_35 ;
unsigned int V_225 , V_226 , V_213 , V_227 , V_62 ;
struct V_1 * V_2 ;
if ( V_30 -> V_32 . V_164 > V_30 -> V_32 . V_228 )
V_225 = 0 ;
else
V_225 = V_30 -> V_32 . V_228 -
V_30 -> V_32 . V_164 ;
F_10 ( L_59 ,
V_35 -> V_36 , V_30 -> V_32 . V_228 ) ;
F_10 ( L_60 ,
V_30 -> V_32 . V_164 , V_30 -> V_32 . V_140 ) ;
V_226 = V_30 -> V_32 . V_228 ;
V_227 = V_30 -> V_32 . V_140 ;
V_62 = 0 ;
F_26 (pe, &phb->ioda.pe_dma_list, dma_link) {
if ( ! V_2 -> V_140 )
continue;
if ( ! V_226 ) {
F_54 ( V_2 , L_61 ) ;
continue;
}
V_213 = 1 ;
if ( V_225 ) {
V_213 += ( ( V_2 -> V_140 * V_225 ) + ( V_227 / 2 ) ) / V_227 ;
if ( V_213 > V_226 )
V_213 = V_226 ;
}
if ( V_30 -> type == V_135 ) {
F_73 ( V_2 , L_62 ,
V_2 -> V_140 , V_213 ) ;
F_128 ( V_30 , V_2 , V_62 , V_213 ) ;
} else {
F_73 ( V_2 , L_63 ) ;
V_213 = 0 ;
F_102 ( V_30 , V_2 ) ;
}
V_226 -= V_213 ;
V_62 += V_213 ;
}
}
static void F_141 ( struct V_229 * V_230 )
{
unsigned int V_231 = ( unsigned int ) F_142 ( V_230 ) ;
struct V_232 * V_233 = F_143 ( V_230 ) ;
struct V_29 * V_30 = F_144 ( V_233 , struct V_29 ,
V_32 . V_232 ) ;
T_11 V_43 ;
V_43 = F_145 ( V_30 -> V_44 , V_231 ) ;
F_146 ( V_43 ) ;
F_147 ( V_230 ) ;
}
static void F_148 ( struct V_29 * V_30 , unsigned int V_234 )
{
struct V_229 * V_235 ;
struct V_232 * V_236 ;
if ( V_30 -> type != V_88 )
return;
if ( ! V_30 -> V_32 . V_237 ) {
V_235 = F_149 ( V_234 ) ;
V_236 = F_143 ( V_235 ) ;
V_30 -> V_32 . V_237 = 1 ;
V_30 -> V_32 . V_232 = * V_236 ;
V_30 -> V_32 . V_232 . V_238 = F_141 ;
}
F_150 ( V_234 , & V_30 -> V_32 . V_232 ) ;
}
struct V_84 * F_151 ( struct V_61 * V_12 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
return F_152 ( V_35 -> V_85 ) ;
}
int F_153 ( struct V_61 * V_12 , T_13 V_239 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
struct V_1 * V_2 ;
int V_43 ;
V_2 = F_49 ( V_12 ) ;
if ( ! V_2 )
return - V_195 ;
F_73 ( V_2 , L_64 ) ;
V_43 = F_154 ( V_30 -> V_44 , V_239 , V_2 -> V_21 ) ;
if ( V_43 )
F_57 ( & V_12 -> V_12 , L_65 , V_43 ) ;
return V_43 ;
}
int F_155 ( struct V_61 * V_12 , int V_240 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
int V_241 = F_156 ( & V_30 -> V_242 , V_240 ) ;
if ( V_241 < 0 ) {
F_93 ( & V_12 -> V_12 , L_66 ) ;
return - V_243 ;
}
return V_30 -> V_244 + V_241 ;
}
void F_157 ( struct V_61 * V_12 , int V_241 , int V_240 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
F_158 ( & V_30 -> V_242 , V_241 - V_30 -> V_244 , V_240 ) ;
}
void F_159 ( struct V_245 * V_246 ,
struct V_61 * V_12 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
int V_64 , V_241 ;
for ( V_64 = 1 ; V_64 < V_247 ; V_64 ++ ) {
if ( ! V_246 -> V_248 [ V_64 ] )
continue;
F_160 ( L_67 ,
V_64 , V_246 -> V_150 [ V_64 ] ,
V_246 -> V_248 [ V_64 ] ) ;
V_241 = V_246 -> V_150 [ V_64 ] - V_30 -> V_244 ;
F_158 ( & V_30 -> V_242 , V_241 ,
V_246 -> V_248 [ V_64 ] ) ;
}
}
int F_161 ( struct V_245 * V_246 ,
struct V_61 * V_12 , int V_240 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
int V_64 , V_241 , V_249 ;
memset ( V_246 , 0 , sizeof( struct V_245 ) ) ;
for ( V_64 = 1 ; V_64 < V_247 && V_240 ; V_64 ++ ) {
V_249 = V_240 ;
while ( V_249 ) {
V_241 = F_156 ( & V_30 -> V_242 , V_249 ) ;
if ( V_241 >= 0 )
break;
V_249 /= 2 ;
}
if ( ! V_249 )
goto V_50;
V_246 -> V_150 [ V_64 ] = V_30 -> V_244 + V_241 ;
V_246 -> V_248 [ V_64 ] = V_249 ;
F_160 ( L_68 ,
V_64 , V_246 -> V_150 [ V_64 ] , V_246 -> V_248 [ V_64 ] ) ;
V_240 -= V_249 ;
}
if ( V_240 )
goto V_50;
return 0 ;
V_50:
F_159 ( V_246 , V_12 ) ;
return - V_243 ;
}
int F_162 ( struct V_61 * V_12 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
return V_30 -> V_242 . V_250 ;
}
int F_163 ( struct V_61 * V_12 , unsigned int V_241 ,
unsigned int V_234 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
unsigned int V_251 = V_241 - V_30 -> V_244 ;
struct V_1 * V_2 ;
int V_43 ;
if ( ! ( V_2 = F_49 ( V_12 ) ) )
return - V_195 ;
V_43 = F_164 ( V_30 -> V_44 , V_2 -> V_21 , V_251 ) ;
if ( V_43 ) {
F_54 ( V_2 , L_69
L_70 ,
F_70 ( V_12 ) , V_43 , V_30 -> V_244 , V_241 , V_251 ) ;
return - V_59 ;
}
F_148 ( V_30 , V_234 ) ;
return 0 ;
}
static int F_165 ( struct V_29 * V_30 , struct V_61 * V_12 ,
unsigned int V_241 , unsigned int V_234 ,
unsigned int V_252 , struct V_253 * V_254 )
{
struct V_1 * V_2 = F_49 ( V_12 ) ;
unsigned int V_251 = V_241 - V_30 -> V_244 ;
T_17 V_162 ;
int V_43 ;
if ( V_2 == NULL )
return - V_112 ;
if ( V_2 -> V_136 < 0 )
return - V_112 ;
if ( V_12 -> V_255 )
V_252 = 0 ;
V_43 = F_164 ( V_30 -> V_44 , V_2 -> V_21 , V_251 ) ;
if ( V_43 ) {
F_14 ( L_71 ,
F_70 ( V_12 ) , V_43 , V_251 ) ;
return - V_59 ;
}
if ( V_252 ) {
T_14 V_256 ;
V_43 = F_166 ( V_30 -> V_44 , V_2 -> V_136 , V_251 , 1 ,
& V_256 , & V_162 ) ;
if ( V_43 ) {
F_14 ( L_72 ,
F_70 ( V_12 ) , V_43 ) ;
return - V_59 ;
}
V_254 -> V_257 = F_167 ( V_256 ) >> 32 ;
V_254 -> V_258 = F_167 ( V_256 ) & 0xfffffffful ;
} else {
T_17 V_259 ;
V_43 = F_168 ( V_30 -> V_44 , V_2 -> V_136 , V_251 , 1 ,
& V_259 , & V_162 ) ;
if ( V_43 ) {
F_14 ( L_73 ,
F_70 ( V_12 ) , V_43 ) ;
return - V_59 ;
}
V_254 -> V_257 = 0 ;
V_254 -> V_258 = F_169 ( V_259 ) ;
}
V_254 -> V_162 = F_169 ( V_162 ) ;
F_148 ( V_30 , V_234 ) ;
F_160 ( L_74
L_75 ,
F_70 ( V_12 ) , V_252 ? L_76 : L_77 , V_241 , V_251 ,
V_254 -> V_257 , V_254 -> V_258 , V_162 , V_2 -> V_21 ) ;
return 0 ;
}
static void F_170 ( struct V_29 * V_30 )
{
unsigned int V_120 ;
const T_17 * V_260 = F_40 ( V_30 -> V_35 -> V_85 ,
L_78 , NULL ) ;
if ( ! V_260 ) {
V_260 = F_40 ( V_30 -> V_35 -> V_85 , L_79 , NULL ) ;
}
if ( ! V_260 )
return;
V_30 -> V_244 = F_171 ( V_260 ) ;
V_120 = F_171 ( V_260 + 1 ) ;
if ( F_172 ( & V_30 -> V_242 , V_120 , V_30 -> V_35 -> V_85 ) ) {
F_173 ( L_80 ,
V_30 -> V_35 -> V_36 ) ;
return;
}
V_30 -> V_261 = F_165 ;
V_30 -> V_262 = 1 ;
F_10 ( L_81 ,
V_120 , V_30 -> V_244 ) ;
}
static void F_170 ( struct V_29 * V_30 ) { }
static void F_174 ( struct V_61 * V_11 )
{
struct V_83 * V_35 ;
struct V_29 * V_30 ;
struct V_41 * V_86 ;
int V_64 ;
T_6 V_72 ;
struct V_105 * V_106 ;
int V_263 , V_171 ;
if ( ! V_11 -> V_153 || V_11 -> V_264 )
return;
V_35 = F_50 ( V_11 -> V_19 ) ;
V_30 = V_35 -> V_104 ;
V_106 = F_51 ( V_11 ) ;
V_106 -> V_265 = 0 ;
V_171 = F_81 ( V_11 ) ;
V_106 -> V_174 = 1 ;
V_263 = V_30 -> V_32 . V_33 ;
for ( V_64 = 0 ; V_64 < V_154 ; V_64 ++ ) {
V_86 = & V_11 -> V_41 [ V_64 + V_155 ] ;
if ( ! V_86 -> V_9 || V_86 -> V_67 )
continue;
if ( ! F_12 ( V_86 -> V_9 ) ) {
F_93 ( & V_11 -> V_12 , L_82 ,
V_64 , V_86 ) ;
continue;
}
V_72 = F_66 ( V_11 , V_64 + V_155 ) ;
if ( V_72 > ( 1 << 26 ) ) {
F_67 ( & V_11 -> V_12 , L_83 ,
V_64 , V_86 ) ;
V_106 -> V_174 = V_167 ;
V_263 = F_82 ( V_171 ) ;
break;
}
}
for ( V_64 = 0 ; V_64 < V_154 ; V_64 ++ ) {
V_86 = & V_11 -> V_41 [ V_64 + V_155 ] ;
if ( ! V_86 -> V_9 || V_86 -> V_67 )
continue;
if ( ! F_12 ( V_86 -> V_9 ) ) {
F_93 ( & V_11 -> V_12 , L_84 ,
V_64 , V_86 ) ;
continue;
}
F_175 ( & V_11 -> V_12 , L_85 , V_64 , V_86 ) ;
V_72 = F_66 ( V_11 , V_64 + V_155 ) ;
V_86 -> V_57 = V_86 -> V_55 + V_72 * V_263 - 1 ;
F_175 ( & V_11 -> V_12 , L_86 , V_86 ) ;
F_67 ( & V_11 -> V_12 , L_87 ,
V_64 , V_86 , V_263 ) ;
}
V_106 -> V_265 = V_263 ;
}
static void F_176 ( struct V_83 * V_35 ,
struct V_1 * V_2 )
{
struct V_29 * V_30 = V_35 -> V_104 ;
struct V_266 V_267 ;
struct V_41 * V_86 ;
int V_64 , V_268 ;
int V_43 ;
F_177 ( ! ( V_2 -> V_9 & ( V_13 | V_14 ) ) ) ;
F_30 (pe->pbus, res, i) {
if ( ! V_86 || ! V_86 -> V_9 ||
V_86 -> V_55 > V_86 -> V_57 )
continue;
if ( V_86 -> V_9 & V_269 ) {
V_267 . V_55 = V_86 -> V_55 - V_30 -> V_32 . V_270 ;
V_267 . V_57 = V_86 -> V_57 - V_30 -> V_32 . V_270 ;
V_268 = V_267 . V_55 / V_30 -> V_32 . V_271 ;
while ( V_268 < V_30 -> V_32 . V_33 &&
V_267 . V_55 <= V_267 . V_57 ) {
V_30 -> V_32 . V_272 [ V_268 ] = V_2 -> V_21 ;
V_43 = F_83 ( V_30 -> V_44 ,
V_2 -> V_21 , V_273 , 0 , V_268 ) ;
if ( V_43 != V_49 ) {
F_173 ( L_88
L_89 ,
V_34 , V_43 , V_268 , V_2 -> V_21 ) ;
break;
}
V_267 . V_55 += V_30 -> V_32 . V_271 ;
V_268 ++ ;
}
} else if ( ( V_86 -> V_9 & V_91 ) &&
! F_12 ( V_86 -> V_9 ) ) {
V_267 . V_55 = V_86 -> V_55 -
V_35 -> V_92 [ 0 ] -
V_30 -> V_32 . V_224 ;
V_267 . V_57 = V_86 -> V_57 -
V_35 -> V_92 [ 0 ] -
V_30 -> V_32 . V_224 ;
V_268 = V_267 . V_55 / V_30 -> V_32 . V_274 ;
while ( V_268 < V_30 -> V_32 . V_33 &&
V_267 . V_55 <= V_267 . V_57 ) {
V_30 -> V_32 . V_275 [ V_268 ] = V_2 -> V_21 ;
V_43 = F_83 ( V_30 -> V_44 ,
V_2 -> V_21 , V_276 , 0 , V_268 ) ;
if ( V_43 != V_49 ) {
F_173 ( L_90
L_91 ,
V_34 , V_43 , V_268 , V_2 -> V_21 ) ;
break;
}
V_267 . V_55 += V_30 -> V_32 . V_274 ;
V_268 ++ ;
}
}
}
}
static void F_178 ( void )
{
struct V_83 * V_166 , * V_35 ;
struct V_29 * V_30 ;
struct V_1 * V_2 ;
F_78 (hose, tmp, &hose_list, list_node) {
V_30 = V_35 -> V_104 ;
F_26 (pe, &phb->ioda.pe_list, list) {
F_176 ( V_35 , V_2 ) ;
}
}
}
static void F_179 ( void )
{
struct V_83 * V_35 , * V_166 ;
struct V_29 * V_30 ;
F_78 (hose, tmp, &hose_list, list_node) {
F_140 ( V_35 -> V_104 ) ;
V_30 = V_35 -> V_104 ;
V_30 -> V_277 = 1 ;
}
}
static void F_180 ( void )
{
#ifdef F_181
struct V_83 * V_35 , * V_166 ;
struct V_29 * V_30 ;
char V_278 [ 16 ] ;
F_78 (hose, tmp, &hose_list, list_node) {
V_30 = V_35 -> V_104 ;
sprintf ( V_278 , L_92 , V_35 -> V_36 ) ;
V_30 -> V_279 = F_182 ( V_278 , V_280 ) ;
if ( ! V_30 -> V_279 )
F_72 ( L_93 ,
V_34 , V_35 -> V_36 ) ;
}
#endif
}
static void F_183 ( void )
{
F_77 () ;
F_178 () ;
F_179 () ;
F_180 () ;
#ifdef F_184
F_185 () ;
F_186 () ;
#endif
}
static T_6 F_187 ( struct V_68 * V_19 ,
unsigned long type )
{
struct V_61 * V_281 ;
struct V_83 * V_35 = F_50 ( V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
int V_282 = 0 ;
V_281 = V_19 -> V_115 ;
while ( V_281 ) {
if ( F_76 ( V_281 ) == V_165 ) {
V_282 ++ ;
if ( V_282 >= 2 )
return 1 ;
}
V_281 = V_281 -> V_19 -> V_115 ;
}
if ( V_30 -> V_32 . V_56 &&
F_12 ( type ) )
return V_30 -> V_32 . V_56 ;
if ( type & V_91 )
return V_30 -> V_32 . V_274 ;
return V_30 -> V_32 . V_271 ;
}
static T_6 F_188 ( struct V_61 * V_11 ,
int V_283 )
{
struct V_105 * V_106 = F_51 ( V_11 ) ;
T_6 V_284 , V_285 ;
V_285 = F_27 ( & V_11 -> V_41 [ V_283 ] ) ;
if ( V_285 )
return V_285 ;
V_284 = F_66 ( V_11 , V_283 ) ;
if ( V_106 -> V_265 )
return V_106 -> V_265 * V_284 ;
return V_284 ;
}
static bool F_189 ( struct V_61 * V_12 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
struct V_105 * V_106 ;
if ( ! V_30 -> V_277 )
return true ;
V_106 = F_51 ( V_12 ) ;
if ( ! V_106 || V_106 -> V_21 == V_39 )
return false ;
return true ;
}
static T_7 F_190 ( struct V_29 * V_30 , struct V_68 * V_19 ,
T_7 V_286 )
{
return V_30 -> V_32 . V_132 [ ( V_19 -> V_16 << 8 ) | V_286 ] ;
}
static void F_191 ( struct V_29 * V_30 )
{
F_192 ( V_30 -> V_44 , V_287 ,
V_288 ) ;
}
static void T_2 F_193 ( struct V_84 * V_289 ,
T_3 V_290 , int V_291 )
{
struct V_83 * V_35 ;
struct V_29 * V_30 ;
unsigned long V_72 , V_292 , V_293 , V_294 = 0 ;
const T_14 * V_295 ;
const T_17 * V_296 ;
int V_297 ;
T_3 V_298 ;
void * V_299 ;
long V_43 ;
F_10 ( L_94 , V_291 , V_289 -> V_90 ) ;
V_295 = F_40 ( V_289 , L_95 , NULL ) ;
if ( ! V_295 ) {
F_173 ( L_96 ) ;
return;
}
V_298 = F_132 ( V_295 ) ;
F_194 ( L_97 , V_298 ) ;
V_30 = F_195 ( sizeof( struct V_29 ) , 0 ) ;
V_30 -> V_35 = V_35 = F_196 ( V_289 ) ;
if ( ! V_30 -> V_35 ) {
F_173 ( L_98 ,
V_289 -> V_90 ) ;
F_197 ( F_86 ( V_30 ) , sizeof( struct V_29 ) ) ;
return;
}
F_198 ( & V_30 -> V_300 ) ;
V_296 = F_40 ( V_289 , L_99 , & V_297 ) ;
if ( V_296 && V_297 == 8 ) {
V_35 -> V_301 = F_169 ( V_296 [ 0 ] ) ;
V_35 -> V_302 = F_169 ( V_296 [ 1 ] ) ;
} else {
F_14 ( L_100 , V_289 -> V_90 ) ;
V_35 -> V_301 = 0 ;
V_35 -> V_302 = 0xff ;
}
V_35 -> V_104 = V_30 ;
V_30 -> V_290 = V_290 ;
V_30 -> V_44 = V_298 ;
V_30 -> type = V_291 ;
F_199 ( & V_30 -> V_32 . V_190 ) ;
if ( F_200 ( V_289 , L_101 ) )
V_30 -> V_303 = V_304 ;
else if ( F_200 ( V_289 , L_102 ) )
V_30 -> V_303 = V_305 ;
else
V_30 -> V_303 = V_306 ;
F_201 ( V_35 , V_289 , ! V_35 -> V_36 ) ;
V_30 -> V_307 = F_202 ( V_289 , 0 ) ;
if ( V_30 -> V_307 == NULL )
F_173 ( L_103 ) ;
V_30 -> V_32 . V_33 = 1 ;
V_296 = F_40 ( V_289 , L_104 , NULL ) ;
if ( V_296 )
V_30 -> V_32 . V_33 = F_171 ( V_296 ) ;
V_296 = F_40 ( V_289 , L_105 , NULL ) ;
if ( V_296 )
V_30 -> V_32 . V_54 = F_171 ( V_296 ) ;
F_38 ( V_30 ) ;
V_30 -> V_32 . V_308 = F_27 ( & V_35 -> V_53 [ 0 ] ) ;
V_30 -> V_32 . V_308 += 0x10000 ;
V_30 -> V_32 . V_274 = V_30 -> V_32 . V_308 / V_30 -> V_32 . V_33 ;
V_30 -> V_32 . V_224 = V_35 -> V_53 [ 0 ] . V_55 - V_35 -> V_92 [ 0 ] ;
V_30 -> V_32 . V_309 = V_35 -> V_310 ;
V_30 -> V_32 . V_271 = V_30 -> V_32 . V_309 / V_30 -> V_32 . V_33 ;
V_30 -> V_32 . V_270 = 0 ;
V_72 = F_31 ( V_30 -> V_32 . V_33 / 8 , sizeof( unsigned long ) ) ;
V_292 = V_72 ;
V_72 += V_30 -> V_32 . V_33 * sizeof( V_30 -> V_32 . V_275 [ 0 ] ) ;
if ( V_30 -> type == V_135 ) {
V_294 = V_72 ;
V_72 += V_30 -> V_32 . V_33 * sizeof( V_30 -> V_32 . V_272 [ 0 ] ) ;
}
V_293 = V_72 ;
V_72 += V_30 -> V_32 . V_33 * sizeof( struct V_1 ) ;
V_299 = F_195 ( V_72 , 0 ) ;
V_30 -> V_32 . V_37 = V_299 ;
V_30 -> V_32 . V_275 = V_299 + V_292 ;
if ( V_30 -> type == V_135 )
V_30 -> V_32 . V_272 = V_299 + V_294 ;
V_30 -> V_32 . V_38 = V_299 + V_293 ;
F_24 ( V_30 -> V_32 . V_54 , V_30 -> V_32 . V_37 ) ;
F_36 ( & V_30 -> V_32 . V_142 ) ;
F_36 ( & V_30 -> V_32 . V_163 ) ;
F_199 ( & V_30 -> V_32 . V_186 ) ;
V_30 -> V_32 . V_228 = V_30 -> V_32 . V_224 >> 28 ;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
F_10 ( L_106 ,
V_30 -> V_32 . V_33 , V_30 -> V_32 . V_54 ,
V_30 -> V_32 . V_308 , V_30 -> V_32 . V_274 ) ;
if ( V_30 -> V_32 . V_48 )
F_10 ( L_107 ,
V_30 -> V_32 . V_48 , V_30 -> V_32 . V_56 ) ;
if ( V_30 -> V_32 . V_309 )
F_10 ( L_108 ,
V_30 -> V_32 . V_309 , V_30 -> V_32 . V_271 ) ;
V_30 -> V_35 -> V_311 = & V_312 ;
V_30 -> V_313 = F_47 ;
V_30 -> V_314 = F_43 ;
V_30 -> V_315 = F_45 ;
V_30 -> V_316 = F_190 ;
V_30 -> V_317 = F_110 ;
V_30 -> V_318 = F_113 ;
V_30 -> V_319 = F_118 ;
V_30 -> V_320 = F_191 ;
F_170 ( V_30 ) ;
V_321 . V_322 = F_183 ;
V_323 . V_324 = F_189 ;
V_323 . V_325 = F_187 ;
V_323 . V_326 = V_327 ;
V_35 -> V_328 = V_323 ;
#ifdef F_5
V_321 . V_329 = F_174 ;
V_321 . V_330 = F_188 ;
#endif
F_203 ( V_331 ) ;
V_43 = F_192 ( V_298 , V_287 , V_288 ) ;
if ( V_43 )
F_72 ( L_109 , V_43 ) ;
if ( F_204 () ) {
F_10 ( L_110 ) ;
F_205 ( V_35 , V_332 ) ;
F_205 ( V_35 , V_333 ) ;
}
if ( ! V_30 -> V_93 || V_30 -> V_93 ( V_30 ) )
V_35 -> V_53 [ 1 ] . V_9 = 0 ;
}
void T_2 F_206 ( struct V_84 * V_289 )
{
F_193 ( V_289 , 0 , V_88 ) ;
}
void T_2 F_207 ( struct V_84 * V_289 )
{
struct V_84 * V_334 ;
const T_14 * V_295 ;
T_3 V_290 ;
F_10 ( L_111 , V_289 -> V_90 ) ;
V_295 = F_40 ( V_289 , L_112 , NULL ) ;
if ( ! V_295 ) {
F_173 ( L_113 ) ;
return;
}
V_290 = F_132 ( V_295 ) ;
F_160 ( L_114 , V_290 ) ;
F_208 (np, phbn) {
if ( F_200 ( V_334 , L_115 ) )
F_193 ( V_334 , V_290 , V_135 ) ;
}
}
