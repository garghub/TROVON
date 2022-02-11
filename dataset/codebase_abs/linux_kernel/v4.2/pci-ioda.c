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
F_69 ( V_19 , V_2 ) ;
F_37 ( & V_2 -> V_82 , & V_30 -> V_32 . V_159 ) ;
if ( V_2 -> V_140 != 0 ) {
V_30 -> V_32 . V_140 += V_2 -> V_140 ;
V_30 -> V_32 . V_160 ++ ;
}
F_63 ( V_30 , V_2 ) ;
}
static void F_74 ( struct V_68 * V_19 )
{
struct V_61 * V_12 ;
F_71 ( V_19 , 0 ) ;
F_26 (dev, &bus->devices, bus_list) {
if ( V_12 -> V_77 ) {
if ( F_75 ( V_12 ) == V_161 )
F_71 ( V_12 -> V_77 , 1 ) ;
else
F_74 ( V_12 -> V_77 ) ;
}
}
}
static void F_76 ( void )
{
struct V_83 * V_35 , * V_162 ;
struct V_29 * V_30 ;
F_77 (hose, tmp, &hose_list, list_node) {
V_30 = V_35 -> V_104 ;
if ( V_30 -> V_94 )
V_30 -> V_94 ( V_30 ) ;
F_74 ( V_35 -> V_19 ) ;
}
}
static int F_78 ( struct V_61 * V_11 )
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
for ( V_74 = 0 ; V_74 < V_163 ; V_74 ++ ) {
if ( V_106 -> V_164 [ V_64 ] [ V_74 ] == V_165 )
continue;
F_23 ( V_30 -> V_44 ,
V_45 , V_106 -> V_164 [ V_64 ] [ V_74 ] , 0 ) ;
F_20 ( V_106 -> V_164 [ V_64 ] [ V_74 ] , & V_30 -> V_32 . V_52 ) ;
V_106 -> V_164 [ V_64 ] [ V_74 ] = V_165 ;
}
return 0 ;
}
static int F_79 ( struct V_61 * V_11 , T_12 V_152 )
{
struct V_68 * V_19 ;
struct V_83 * V_35 ;
struct V_29 * V_30 ;
struct V_105 * V_106 ;
unsigned int V_166 ;
struct V_41 * V_86 ;
int V_64 , V_74 ;
T_11 V_43 ;
int V_167 ;
T_6 V_72 , V_55 ;
int V_157 ;
int V_168 ;
int V_169 ;
V_19 = V_11 -> V_19 ;
V_35 = F_50 ( V_19 ) ;
V_30 = V_35 -> V_104 ;
V_106 = F_51 ( V_11 ) ;
V_167 = F_80 ( V_11 ) ;
for ( V_64 = 0 ; V_64 < V_154 ; V_64 ++ )
for ( V_74 = 0 ; V_74 < V_163 ; V_74 ++ )
V_106 -> V_164 [ V_64 ] [ V_74 ] = V_165 ;
if ( V_106 -> V_170 == V_163 ) {
V_168 = ( V_152 <= V_163 ) ? V_152 : V_163 ;
V_169 = ( V_152 <= V_163 ) ? 1 :
F_81 ( V_152 ) / V_106 -> V_170 ;
} else {
V_168 = 1 ;
V_169 = 1 ;
}
for ( V_64 = 0 ; V_64 < V_154 ; V_64 ++ ) {
V_86 = & V_11 -> V_41 [ V_64 + V_155 ] ;
if ( ! V_86 -> V_9 || ! V_86 -> V_67 )
continue;
if ( ! F_12 ( V_86 -> V_9 ) )
continue;
for ( V_74 = 0 ; V_74 < V_168 ; V_74 ++ ) {
do {
V_166 = F_17 ( & V_30 -> V_32 . V_52 ,
V_30 -> V_32 . V_46 + 1 , 0 ) ;
if ( V_166 >= V_30 -> V_32 . V_46 + 1 )
goto V_171;
} while ( F_15 ( V_166 , & V_30 -> V_32 . V_52 ) );
V_106 -> V_164 [ V_64 ] [ V_74 ] = V_166 ;
if ( V_106 -> V_170 == V_163 ) {
V_72 = F_66 ( V_11 ,
V_155 + V_64 ) ;
V_72 = V_72 * V_169 ;
V_55 = V_86 -> V_55 + V_72 * V_74 ;
} else {
V_72 = F_27 ( V_86 ) ;
V_55 = V_86 -> V_55 ;
}
if ( V_106 -> V_170 == V_163 ) {
V_157 = V_106 -> V_150 + V_74 ;
V_43 = F_82 ( V_30 -> V_44 ,
V_157 , V_45 ,
V_106 -> V_164 [ V_64 ] [ V_74 ] , 0 ) ;
}
V_43 = F_22 ( V_30 -> V_44 ,
V_45 ,
V_106 -> V_164 [ V_64 ] [ V_74 ] ,
V_55 ,
0 ,
V_72 ) ;
if ( V_43 != V_49 ) {
F_57 ( & V_11 -> V_12 , L_37 ,
V_166 , V_43 ) ;
goto V_171;
}
if ( V_106 -> V_170 == V_163 )
V_43 = F_23 ( V_30 -> V_44 ,
V_45 , V_106 -> V_164 [ V_64 ] [ V_74 ] , 2 ) ;
else
V_43 = F_23 ( V_30 -> V_44 ,
V_45 , V_106 -> V_164 [ V_64 ] [ V_74 ] , 1 ) ;
if ( V_43 != V_49 ) {
F_57 ( & V_11 -> V_12 , L_38 ,
V_166 , V_43 ) ;
goto V_171;
}
}
}
return 0 ;
V_171:
F_78 ( V_11 ) ;
return - V_156 ;
}
static void F_83 ( struct V_61 * V_12 , struct V_1 * V_2 )
{
struct V_172 * V_173 ;
T_11 V_43 ;
V_173 = V_2 -> V_174 . V_175 [ 0 ] ;
V_43 = F_84 ( & V_2 -> V_174 , 0 ) ;
if ( V_43 )
F_54 ( V_2 , L_39 , V_43 ) ;
F_85 ( V_2 , false ) ;
if ( V_2 -> V_174 . V_176 ) {
F_86 ( V_2 -> V_174 . V_176 ) ;
F_87 ( V_2 -> V_174 . V_176 ) ;
}
F_88 ( V_173 ) ;
F_89 ( V_173 , F_90 ( V_12 -> V_12 . V_177 ) ) ;
}
static void F_91 ( struct V_61 * V_11 , T_12 V_152 )
{
struct V_68 * V_19 ;
struct V_83 * V_35 ;
struct V_29 * V_30 ;
struct V_1 * V_2 , * V_178 ;
struct V_105 * V_106 ;
T_12 V_179 ;
T_11 V_43 ;
V_19 = V_11 -> V_19 ;
V_35 = F_50 ( V_19 ) ;
V_30 = V_35 -> V_104 ;
V_106 = F_51 ( V_11 ) ;
if ( ! V_11 -> V_153 )
return;
if ( V_106 -> V_170 == V_163 && V_152 > V_163 ) {
int V_180 ;
int V_169 ;
int V_181 ;
V_169 = F_81 ( V_152 ) / V_106 -> V_170 ;
for ( V_180 = 0 ; V_180 < V_163 ; V_180 ++ )
for ( V_179 = V_180 * V_169 ;
V_179 < ( V_180 + 1 ) * V_169 &&
V_179 < V_152 ;
V_179 ++ )
for ( V_181 = V_180 * V_169 ;
V_181 < ( V_180 + 1 ) * V_169 &&
V_181 < V_152 ;
V_181 ++ ) {
V_43 = F_53 ( V_30 -> V_44 ,
V_106 -> V_150 + V_179 ,
V_106 -> V_150 + V_181 ,
V_111 ) ;
if ( V_43 )
F_92 ( & V_11 -> V_12 , L_40 ,
V_34 ,
V_106 -> V_150 + V_181 , V_43 ) ;
}
}
F_77 (pe, pe_n, &phb->ioda.pe_list, list) {
if ( V_2 -> V_18 != V_11 )
continue;
F_83 ( V_11 , V_2 ) ;
F_93 ( & V_30 -> V_32 . V_182 ) ;
F_94 ( & V_2 -> V_82 ) ;
F_95 ( & V_30 -> V_32 . V_182 ) ;
F_56 ( V_30 , V_2 ) ;
F_18 ( V_30 , V_2 -> V_21 ) ;
}
}
void F_96 ( struct V_61 * V_11 )
{
struct V_68 * V_19 ;
struct V_83 * V_35 ;
struct V_29 * V_30 ;
struct V_105 * V_106 ;
struct V_183 * V_184 ;
T_12 V_152 ;
V_19 = V_11 -> V_19 ;
V_35 = F_50 ( V_19 ) ;
V_30 = V_35 -> V_104 ;
V_106 = F_51 ( V_11 ) ;
V_184 = V_11 -> V_185 ;
V_152 = V_106 -> V_152 ;
F_91 ( V_11 , V_152 ) ;
if ( V_30 -> type == V_88 ) {
if ( V_106 -> V_170 == 1 )
F_65 ( V_11 , - V_106 -> V_150 ) ;
F_78 ( V_11 ) ;
F_97 ( V_30 -> V_32 . V_37 , V_106 -> V_150 , V_152 ) ;
V_106 -> V_150 = 0 ;
}
}
static void F_98 ( struct V_61 * V_11 , T_12 V_152 )
{
struct V_68 * V_19 ;
struct V_83 * V_35 ;
struct V_29 * V_30 ;
struct V_1 * V_2 ;
int V_157 ;
T_12 V_179 ;
struct V_105 * V_106 ;
T_11 V_43 ;
V_19 = V_11 -> V_19 ;
V_35 = F_50 ( V_19 ) ;
V_30 = V_35 -> V_104 ;
V_106 = F_51 ( V_11 ) ;
if ( ! V_11 -> V_153 )
return;
for ( V_179 = 0 ; V_179 < V_152 ; V_179 ++ ) {
V_157 = V_106 -> V_150 + V_179 ;
V_2 = & V_30 -> V_32 . V_38 [ V_157 ] ;
V_2 -> V_21 = V_157 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_9 = V_17 ;
V_2 -> V_15 = NULL ;
V_2 -> V_18 = V_11 ;
V_2 -> V_158 = - 1 ;
V_2 -> V_136 = - 1 ;
V_2 -> V_20 = ( F_99 ( V_11 , V_179 ) << 8 ) |
F_100 ( V_11 , V_179 ) ;
F_73 ( V_2 , L_41 ,
V_35 -> V_36 , V_11 -> V_19 -> V_16 ,
F_6 ( F_100 ( V_11 , V_179 ) ) ,
F_7 ( F_100 ( V_11 , V_179 ) ) , V_157 ) ;
if ( F_60 ( V_30 , V_2 ) ) {
if ( V_157 )
F_18 ( V_30 , V_157 ) ;
V_2 -> V_11 = NULL ;
continue;
}
F_93 ( & V_30 -> V_32 . V_182 ) ;
F_37 ( & V_2 -> V_82 , & V_30 -> V_32 . V_159 ) ;
F_95 ( & V_30 -> V_32 . V_182 ) ;
F_101 ( V_30 , V_2 ) ;
}
if ( V_106 -> V_170 == V_163 && V_152 > V_163 ) {
int V_180 ;
int V_169 ;
int V_181 ;
V_169 = F_81 ( V_152 ) / V_106 -> V_170 ;
for ( V_180 = 0 ; V_180 < V_163 ; V_180 ++ ) {
for ( V_179 = V_180 * V_169 ;
V_179 < ( V_180 + 1 ) * V_169 &&
V_179 < V_152 ;
V_179 ++ ) {
for ( V_181 = V_180 * V_169 ;
V_181 < ( V_180 + 1 ) * V_169 &&
V_181 < V_152 ;
V_181 ++ ) {
V_43 = F_53 ( V_30 -> V_44 ,
V_106 -> V_150 + V_179 ,
V_106 -> V_150 + V_181 ,
V_110 ) ;
if ( V_43 )
F_92 ( & V_11 -> V_12 , L_42 ,
V_34 ,
V_106 -> V_150 + V_181 , V_43 ) ;
}
}
}
}
}
int F_102 ( struct V_61 * V_11 , T_12 V_152 )
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
F_93 ( & V_30 -> V_32 . V_186 ) ;
V_106 -> V_150 = F_103 (
V_30 -> V_32 . V_37 , V_30 -> V_32 . V_33 ,
0 , V_152 , 0 ) ;
if ( V_106 -> V_150 >= V_30 -> V_32 . V_33 ) {
F_95 ( & V_30 -> V_32 . V_186 ) ;
F_67 ( & V_11 -> V_12 , L_43 , V_152 ) ;
V_106 -> V_150 = 0 ;
return - V_156 ;
}
F_104 ( V_30 -> V_32 . V_37 , V_106 -> V_150 , V_152 ) ;
V_106 -> V_152 = V_152 ;
F_95 ( & V_30 -> V_32 . V_186 ) ;
V_113 = F_79 ( V_11 , V_152 ) ;
if ( V_113 ) {
F_67 ( & V_11 -> V_12 , L_44 ) ;
goto V_171;
}
if ( V_106 -> V_170 == 1 ) {
V_113 = F_65 ( V_11 , V_106 -> V_150 ) ;
if ( V_113 )
goto V_171;
}
}
F_98 ( V_11 , V_152 ) ;
return 0 ;
V_171:
F_97 ( V_30 -> V_32 . V_37 , V_106 -> V_150 , V_152 ) ;
V_106 -> V_150 = 0 ;
return V_113 ;
}
int F_105 ( struct V_61 * V_11 )
{
F_96 ( V_11 ) ;
F_106 ( V_11 ) ;
return 0 ;
}
int F_107 ( struct V_61 * V_11 , T_12 V_152 )
{
F_108 ( V_11 ) ;
F_102 ( V_11 , V_152 ) ;
return 0 ;
}
static void F_109 ( struct V_29 * V_30 , struct V_61 * V_11 )
{
struct V_105 * V_106 = F_51 ( V_11 ) ;
struct V_1 * V_2 ;
if ( ! V_106 || V_106 -> V_21 == V_39 )
return;
V_2 = & V_30 -> V_32 . V_38 [ V_106 -> V_21 ] ;
F_19 ( F_110 ( & V_11 -> V_12 ) != & V_187 ) ;
F_111 ( & V_11 -> V_12 , V_2 -> V_174 . V_175 [ 0 ] ) ;
}
static int F_112 ( struct V_61 * V_11 , T_3 V_188 )
{
struct V_83 * V_35 = F_50 ( V_11 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
struct V_105 * V_106 = F_51 ( V_11 ) ;
struct V_1 * V_2 ;
T_13 V_189 ;
bool V_190 = false ;
if ( F_19 ( ! V_106 || V_106 -> V_21 == V_39 ) )
return - V_191 ; ;
V_2 = & V_30 -> V_32 . V_38 [ V_106 -> V_21 ] ;
if ( V_2 -> V_192 ) {
V_189 = V_2 -> V_193 + F_113 () - 1 ;
V_190 = ( V_188 >= V_189 ) ;
}
if ( V_190 ) {
F_67 ( & V_11 -> V_12 , L_45 ) ;
F_114 ( & V_11 -> V_12 , & V_194 ) ;
F_115 ( & V_11 -> V_12 , V_2 -> V_193 ) ;
} else {
F_67 ( & V_11 -> V_12 , L_46 ) ;
F_114 ( & V_11 -> V_12 , & V_187 ) ;
F_111 ( & V_11 -> V_12 , V_2 -> V_174 . V_175 [ 0 ] ) ;
}
* V_11 -> V_12 . V_188 = V_188 ;
return 0 ;
}
static T_3 F_116 ( struct V_29 * V_30 ,
struct V_61 * V_11 )
{
struct V_105 * V_106 = F_51 ( V_11 ) ;
struct V_1 * V_2 ;
T_3 V_57 , V_195 ;
if ( F_19 ( ! V_106 || V_106 -> V_21 == V_39 ) )
return 0 ;
V_2 = & V_30 -> V_32 . V_38 [ V_106 -> V_21 ] ;
if ( ! V_2 -> V_192 )
return F_117 ( & V_11 -> V_12 ) ;
V_57 = V_2 -> V_193 + F_113 () ;
V_195 = 1ULL << ( F_118 ( V_57 ) - 1 ) ;
V_195 += V_195 - 1 ;
return V_195 ;
}
static void F_119 ( struct V_1 * V_2 ,
struct V_68 * V_19 )
{
struct V_61 * V_12 ;
F_26 (dev, &bus->devices, bus_list) {
F_111 ( & V_12 -> V_12 , V_2 -> V_174 . V_175 [ 0 ] ) ;
F_120 ( & V_12 -> V_12 ) ;
if ( ( V_2 -> V_9 & V_14 ) && V_12 -> V_77 )
F_119 ( V_2 , V_12 -> V_77 ) ;
}
}
static void F_121 ( struct V_172 * V_173 ,
unsigned long V_196 , unsigned long V_197 , bool V_198 )
{
struct V_199 * V_200 = F_122 (
& V_173 -> V_201 , struct V_199 ,
V_202 ) ;
struct V_1 * V_2 = F_123 ( V_200 -> V_174 ,
struct V_1 , V_174 ) ;
T_14 T_4 * V_203 = V_198 ?
( T_14 T_4 * ) V_2 -> V_30 -> V_32 . V_204 :
V_2 -> V_30 -> V_32 . V_205 ;
unsigned long V_55 , V_57 , V_206 ;
const unsigned V_207 = V_173 -> V_208 ;
V_55 = F_124 ( ( ( T_14 * ) V_173 -> V_209 ) + V_196 - V_173 -> V_210 ) ;
V_57 = F_124 ( ( ( T_14 * ) V_173 -> V_209 ) + V_196 - V_173 -> V_210 +
V_197 - 1 ) ;
if ( V_173 -> V_211 ) {
V_55 <<= V_207 ;
V_57 <<= V_207 ;
V_206 = 128ull << V_207 ;
V_55 |= V_173 -> V_211 ;
V_57 |= V_173 -> V_211 ;
} else if ( V_173 -> V_212 & V_213 ) {
V_55 |= ( 1ull << 63 ) ;
V_57 |= ( 1ull << 63 ) ;
V_206 = 16 ;
} else {
V_206 = 128 ;
}
V_57 |= V_206 - 1 ;
F_125 () ;
while ( V_55 <= V_57 ) {
if ( V_198 )
F_11 ( F_126 ( V_55 ) , V_203 ) ;
else
F_127 ( F_126 ( V_55 ) , V_203 ) ;
V_55 += V_206 ;
}
}
static int F_128 ( struct V_172 * V_173 , long V_196 ,
long V_197 , unsigned long V_214 ,
enum V_215 V_216 ,
struct V_217 * V_218 )
{
int V_113 = F_129 ( V_173 , V_196 , V_197 , V_214 , V_216 ,
V_218 ) ;
if ( ! V_113 && ( V_173 -> V_212 & V_219 ) )
F_121 ( V_173 , V_196 , V_197 , false ) ;
return V_113 ;
}
static int F_130 ( struct V_172 * V_173 , long V_196 ,
unsigned long * V_220 , enum V_215 * V_216 )
{
long V_113 = F_131 ( V_173 , V_196 , V_220 , V_216 ) ;
if ( ! V_113 && ( V_173 -> V_212 &
( V_219 | V_221 ) ) )
F_121 ( V_173 , V_196 , 1 , false ) ;
return V_113 ;
}
static void F_132 ( struct V_172 * V_173 , long V_196 ,
long V_197 )
{
F_133 ( V_173 , V_196 , V_197 ) ;
if ( V_173 -> V_212 & V_221 )
F_121 ( V_173 , V_196 , V_197 , false ) ;
}
static inline void F_134 ( struct V_1 * V_2 )
{
unsigned long V_25 = ( 0x4ull << 60 ) | ( V_2 -> V_21 & 0xFF ) ;
struct V_29 * V_30 = V_2 -> V_30 ;
if ( ! V_30 -> V_32 . V_205 )
return;
F_125 () ;
F_127 ( F_126 ( V_25 ) , V_30 -> V_32 . V_205 ) ;
}
static void F_135 ( unsigned V_21 , bool V_198 ,
T_14 T_4 * V_203 , unsigned V_207 ,
unsigned long V_196 , unsigned long V_197 )
{
unsigned long V_55 , V_57 , V_206 ;
V_55 = 0x2ull << 60 ;
V_55 |= ( V_21 & 0xFF ) ;
V_57 = V_55 ;
V_55 |= ( V_196 << V_207 ) ;
V_57 |= ( ( V_196 + V_197 - 1 ) << V_207 ) ;
V_206 = ( 0x1ull << V_207 ) ;
F_125 () ;
while ( V_55 <= V_57 ) {
if ( V_198 )
F_11 ( F_126 ( V_55 ) , V_203 ) ;
else
F_127 ( F_126 ( V_55 ) , V_203 ) ;
V_55 += V_206 ;
}
}
static void F_136 ( struct V_172 * V_173 ,
unsigned long V_196 , unsigned long V_197 , bool V_198 )
{
struct V_199 * V_200 ;
F_137 (tgl, &tbl->it_group_list, next) {
struct V_1 * V_2 = F_123 ( V_200 -> V_174 ,
struct V_1 , V_174 ) ;
T_14 T_4 * V_203 = V_198 ?
( T_14 T_4 * ) V_2 -> V_30 -> V_32 . V_204 :
V_2 -> V_30 -> V_32 . V_205 ;
F_135 ( V_2 -> V_21 , V_198 ,
V_203 , V_173 -> V_208 ,
V_196 , V_197 ) ;
}
}
static int F_138 ( struct V_172 * V_173 , long V_196 ,
long V_197 , unsigned long V_214 ,
enum V_215 V_216 ,
struct V_217 * V_218 )
{
int V_113 = F_129 ( V_173 , V_196 , V_197 , V_214 , V_216 ,
V_218 ) ;
if ( ! V_113 && ( V_173 -> V_212 & V_219 ) )
F_136 ( V_173 , V_196 , V_197 , false ) ;
return V_113 ;
}
static int F_139 ( struct V_172 * V_173 , long V_196 ,
unsigned long * V_220 , enum V_215 * V_216 )
{
long V_113 = F_131 ( V_173 , V_196 , V_220 , V_216 ) ;
if ( ! V_113 && ( V_173 -> V_212 &
( V_219 | V_221 ) ) )
F_136 ( V_173 , V_196 , 1 , false ) ;
return V_113 ;
}
static void F_140 ( struct V_172 * V_173 , long V_196 ,
long V_197 )
{
F_133 ( V_173 , V_196 , V_197 ) ;
if ( V_173 -> V_212 & V_221 )
F_136 ( V_173 , V_196 , V_197 , false ) ;
}
static void F_141 ( struct V_172 * V_173 )
{
F_88 ( V_173 ) ;
F_89 ( V_173 , L_47 ) ;
}
static void F_142 ( struct V_29 * V_30 ,
struct V_1 * V_2 , unsigned int V_62 ,
unsigned int V_222 )
{
struct V_223 * V_224 = NULL ;
struct V_172 * V_173 ;
unsigned int V_64 ;
T_11 V_43 ;
void * V_225 ;
if ( F_19 ( V_2 -> V_158 >= 0 ) )
return;
V_173 = F_143 ( V_30 -> V_35 -> V_226 ) ;
F_144 ( & V_2 -> V_174 , V_30 -> V_35 -> V_36 ,
V_2 -> V_21 ) ;
F_145 ( V_30 -> V_35 -> V_226 , 0 , V_173 , & V_2 -> V_174 ) ;
V_2 -> V_158 = V_62 ;
F_73 ( V_2 , L_48 ,
( V_62 << 28 ) , ( ( V_62 + V_222 ) << 28 ) - 1 ) ;
V_224 = F_146 ( V_30 -> V_35 -> V_226 , V_75 ,
F_147 ( V_227 * V_222 ) ) ;
if ( ! V_224 ) {
F_59 ( V_2 , L_49 ) ;
goto V_50;
}
V_225 = F_148 ( V_224 ) ;
memset ( V_225 , 0 , V_227 * V_222 ) ;
for ( V_64 = 0 ; V_64 < V_222 ; V_64 ++ ) {
V_43 = F_149 ( V_30 -> V_44 ,
V_2 -> V_21 ,
V_62 + V_64 , 1 ,
F_124 ( V_225 ) + V_227 * V_64 ,
V_227 , 0x1000 ) ;
if ( V_43 ) {
F_59 ( V_2 , L_50
L_51 , V_43 ) ;
goto V_50;
}
}
F_150 ( V_173 , V_225 , V_227 * V_222 ,
V_62 << 28 , V_228 ) ;
if ( V_30 -> V_32 . V_205 )
V_173 -> V_212 |= ( V_219 |
V_221 |
V_213 ) ;
V_173 -> V_229 = & V_230 ;
V_2 -> V_174 . V_231 = V_173 -> V_210 << V_173 -> V_208 ;
V_2 -> V_174 . V_232 = V_173 -> V_233 << V_173 -> V_208 ;
F_151 ( V_173 , V_30 -> V_35 -> V_226 ) ;
if ( V_2 -> V_9 & V_10 ) {
F_111 ( & V_2 -> V_11 -> V_12 , V_173 ) ;
F_120 ( & V_2 -> V_11 -> V_12 ) ;
} else if ( V_2 -> V_9 & ( V_13 | V_14 ) )
F_119 ( V_2 , V_2 -> V_15 ) ;
return;
V_50:
if ( V_2 -> V_158 >= 0 )
V_2 -> V_158 = - 1 ;
if ( V_224 )
F_152 ( V_224 , F_147 ( V_227 * V_222 ) ) ;
if ( V_173 ) {
F_153 ( V_173 , & V_2 -> V_174 ) ;
F_89 ( V_173 , L_47 ) ;
}
}
static long F_154 ( struct V_234 * V_174 ,
int V_235 , struct V_172 * V_173 )
{
struct V_1 * V_2 = F_123 ( V_174 , struct V_1 ,
V_174 ) ;
struct V_29 * V_30 = V_2 -> V_30 ;
T_11 V_43 ;
const unsigned long V_72 = V_173 -> V_236 ?
V_173 -> V_237 : V_173 -> V_233 ;
const T_15 V_238 = V_173 -> V_210 << V_173 -> V_208 ;
const T_15 V_239 = V_173 -> V_233 << V_173 -> V_208 ;
F_73 ( V_2 , L_52 , V_235 ,
V_238 , V_238 + V_239 - 1 ,
F_155 ( V_173 ) ) ;
V_43 = F_149 ( V_30 -> V_44 ,
V_2 -> V_21 ,
( V_2 -> V_21 << 1 ) + V_235 ,
V_173 -> V_236 + 1 ,
F_124 ( V_173 -> V_209 ) ,
V_72 << 3 ,
F_155 ( V_173 ) ) ;
if ( V_43 ) {
F_59 ( V_2 , L_53 , V_43 ) ;
return V_43 ;
}
F_145 ( V_30 -> V_35 -> V_226 , V_235 ,
V_173 , & V_2 -> V_174 ) ;
F_134 ( V_2 ) ;
return 0 ;
}
static void F_85 ( struct V_1 * V_2 , bool V_240 )
{
T_16 V_241 = ( V_2 -> V_21 << 1 ) + 1 ;
T_11 V_43 ;
F_73 ( V_2 , L_54 , V_240 ? L_55 : L_56 ) ;
if ( V_240 ) {
T_17 V_189 = F_113 () ;
V_189 = F_81 ( V_189 ) ;
V_43 = F_156 ( V_2 -> V_30 -> V_44 ,
V_2 -> V_21 ,
V_241 ,
V_2 -> V_193 ,
V_189 ) ;
} else {
V_43 = F_156 ( V_2 -> V_30 -> V_44 ,
V_2 -> V_21 ,
V_241 ,
V_2 -> V_193 ,
0 ) ;
}
if ( V_43 )
F_59 ( V_2 , L_57 , V_43 ) ;
else
V_2 -> V_192 = V_240 ;
}
static long F_157 ( struct V_234 * V_174 ,
int V_235 , T_18 V_242 , T_15 V_243 , T_18 V_244 ,
struct V_172 * * V_245 )
{
struct V_1 * V_2 = F_123 ( V_174 , struct V_1 ,
V_174 ) ;
int V_246 = V_2 -> V_30 -> V_35 -> V_226 ;
T_15 V_247 = V_235 ? V_2 -> V_193 : V_174 -> V_231 ;
long V_113 ;
struct V_172 * V_173 ;
V_173 = F_143 ( V_246 ) ;
if ( ! V_173 )
return - V_248 ;
V_113 = F_158 ( V_246 ,
V_247 , V_242 , V_243 ,
V_244 , V_173 ) ;
if ( V_113 ) {
F_89 ( V_173 , L_47 ) ;
return V_113 ;
}
V_173 -> V_229 = & V_249 ;
if ( V_2 -> V_30 -> V_32 . V_205 )
V_173 -> V_212 |= ( V_219 | V_221 ) ;
* V_245 = V_173 ;
return 0 ;
}
static long F_159 ( struct V_1 * V_2 )
{
struct V_172 * V_173 = NULL ;
long V_43 ;
V_43 = F_157 ( & V_2 -> V_174 , 0 ,
V_228 ,
V_2 -> V_174 . V_232 ,
V_250 , & V_173 ) ;
if ( V_43 ) {
F_59 ( V_2 , L_58 ,
V_43 ) ;
return V_43 ;
}
F_151 ( V_173 , V_2 -> V_30 -> V_35 -> V_226 ) ;
V_43 = F_154 ( & V_2 -> V_174 , 0 , V_173 ) ;
if ( V_43 ) {
F_59 ( V_2 , L_59 ,
V_43 ) ;
F_141 ( V_173 ) ;
return V_43 ;
}
if ( ! V_24 )
F_85 ( V_2 , true ) ;
if ( V_2 -> V_30 -> V_32 . V_205 )
V_173 -> V_212 |= ( V_219 | V_221 ) ;
if ( V_2 -> V_9 & V_10 )
F_111 ( & V_2 -> V_11 -> V_12 , V_173 ) ;
return 0 ;
}
static long F_84 ( struct V_234 * V_174 ,
int V_235 )
{
struct V_1 * V_2 = F_123 ( V_174 , struct V_1 ,
V_174 ) ;
struct V_29 * V_30 = V_2 -> V_30 ;
long V_113 ;
F_73 ( V_2 , L_60 , V_235 ) ;
V_113 = F_149 ( V_30 -> V_44 , V_2 -> V_21 ,
( V_2 -> V_21 << 1 ) + V_235 ,
0 , 0 ,
0 , 0 ) ;
if ( V_113 )
F_54 ( V_2 , L_61 , V_113 ) ;
else
F_134 ( V_2 ) ;
F_153 ( V_174 -> V_175 [ V_235 ] , V_174 ) ;
return V_113 ;
}
static unsigned long F_160 ( T_18 V_242 ,
T_15 V_243 , T_18 V_244 )
{
unsigned long V_251 = 0 ;
const unsigned V_252 = F_161 ( V_243 ) ;
unsigned V_253 = V_252 - V_242 ;
unsigned V_254 = V_253 + 3 ;
unsigned long V_255 = F_162 ( 0x1000UL , 1UL << V_254 ) ;
unsigned long V_256 ;
if ( ! V_244 || ( V_244 > V_257 ) ||
( V_243 > F_163 () ) ||
! F_164 ( V_243 ) )
return 0 ;
V_253 = ( V_253 + V_244 - 1 ) / V_244 ;
V_254 = V_253 + 3 ;
V_254 = F_165 ( unsigned , V_254 , V_258 ) ;
V_256 = 1UL << V_254 ;
for ( ; V_244 ; -- V_244 ) {
V_251 += F_31 ( V_255 , V_256 ) ;
V_255 /= V_256 ;
V_255 <<= 3 ;
V_255 = F_31 ( V_255 , V_256 ) ;
}
return V_251 ;
}
static void F_166 ( struct V_234 * V_174 )
{
struct V_1 * V_2 = F_123 ( V_174 , struct V_1 ,
V_174 ) ;
struct V_172 * V_173 = V_2 -> V_174 . V_175 [ 0 ] ;
F_85 ( V_2 , false ) ;
F_84 ( & V_2 -> V_174 , 0 ) ;
F_141 ( V_173 ) ;
}
static void F_167 ( struct V_234 * V_174 )
{
struct V_1 * V_2 = F_123 ( V_174 , struct V_1 ,
V_174 ) ;
F_159 ( V_2 ) ;
}
static void F_168 ( struct V_29 * V_30 )
{
const T_14 * V_259 ;
V_259 = F_40 ( V_30 -> V_35 -> V_85 , L_62 , NULL ) ;
if ( ! V_259 )
return;
V_30 -> V_32 . V_204 = F_169 ( V_259 ) ;
V_30 -> V_32 . V_205 = F_170 ( V_30 -> V_32 . V_204 , 8 ) ;
}
static T_14 * F_171 ( int V_246 , unsigned V_207 ,
unsigned V_244 , unsigned long V_260 ,
unsigned long * V_261 , unsigned long * V_262 )
{
struct V_223 * V_224 = NULL ;
T_14 * V_225 , * V_162 ;
unsigned V_263 = F_165 ( unsigned , V_207 , V_258 ) - V_258 ;
unsigned long V_264 = 1UL << ( V_263 + V_258 ) ;
unsigned V_265 = 1UL << ( V_207 - 3 ) ;
long V_64 ;
V_224 = F_146 ( V_246 , V_75 , V_263 ) ;
if ( ! V_224 ) {
F_172 ( L_63 , V_263 ) ;
return NULL ;
}
V_225 = F_148 ( V_224 ) ;
memset ( V_225 , 0 , V_264 ) ;
* V_262 += V_264 ;
-- V_244 ;
if ( ! V_244 ) {
* V_261 += V_264 ;
return V_225 ;
}
for ( V_64 = 0 ; V_64 < V_265 ; ++ V_64 ) {
V_162 = F_171 ( V_246 , V_207 ,
V_244 , V_260 , V_261 , V_262 ) ;
if ( ! V_162 )
break;
V_225 [ V_64 ] = F_126 ( F_124 ( V_162 ) |
V_266 | V_267 ) ;
if ( * V_261 >= V_260 )
break;
}
return V_225 ;
}
static long F_158 ( int V_246 , T_15 V_247 ,
T_18 V_242 , T_15 V_243 , T_18 V_244 ,
struct V_172 * V_173 )
{
void * V_225 ;
unsigned long V_150 = 0 , V_268 , V_262 = 0 ;
const unsigned V_252 = F_161 ( V_243 ) ;
unsigned V_253 = V_252 - V_242 ;
unsigned V_254 = F_165 ( unsigned , V_253 + 3 , V_258 ) ;
const unsigned long V_255 = 1UL << V_254 ;
if ( ! V_244 || ( V_244 > V_257 ) )
return - V_23 ;
if ( ( V_243 > F_163 () ) || ! F_164 ( V_243 ) )
return - V_23 ;
V_253 = ( V_253 + V_244 - 1 ) / V_244 ;
V_268 = V_253 + 3 ;
V_268 = F_165 ( unsigned , V_268 , V_258 ) ;
V_225 = F_171 ( V_246 , V_268 ,
V_244 , V_255 , & V_150 , & V_262 ) ;
if ( ! V_225 )
return - V_248 ;
if ( V_150 < V_255 ) {
F_173 ( V_225 ,
1ULL << ( V_268 - 3 ) , V_244 - 1 ) ;
return - V_248 ;
}
F_150 ( V_173 , V_225 , V_255 , V_247 ,
V_242 ) ;
V_173 -> V_237 = 1ULL << ( V_268 - 3 ) ;
V_173 -> V_236 = V_244 - 1 ;
V_173 -> V_269 = V_262 ;
F_174 ( L_64 ,
V_243 , V_255 , V_247 ) ;
return 0 ;
}
static void F_173 ( T_14 * V_225 ,
unsigned long V_72 , unsigned V_3 )
{
const unsigned long V_270 = ( unsigned long ) V_225 &
~ ( V_266 | V_267 ) ;
if ( V_3 ) {
long V_64 ;
T_3 * V_162 = ( T_3 * ) V_270 ;
for ( V_64 = 0 ; V_64 < V_72 ; ++ V_64 ) {
unsigned long V_220 = F_175 ( V_162 [ V_64 ] ) ;
if ( ! ( V_220 & ( V_266 | V_267 ) ) )
continue;
F_173 ( F_176 ( V_220 ) , V_72 ,
V_3 - 1 ) ;
}
}
F_177 ( V_270 , F_147 ( V_72 << 3 ) ) ;
}
static void F_88 ( struct V_172 * V_173 )
{
const unsigned long V_72 = V_173 -> V_236 ?
V_173 -> V_237 : V_173 -> V_233 ;
if ( ! V_173 -> V_233 )
return;
F_173 ( ( T_14 * ) V_173 -> V_209 , V_72 ,
V_173 -> V_236 ) ;
}
static void F_101 ( struct V_29 * V_30 ,
struct V_1 * V_2 )
{
T_11 V_43 ;
if ( F_19 ( V_2 -> V_158 >= 0 ) )
return;
V_2 -> V_193 = 1ull << 59 ;
F_144 ( & V_2 -> V_174 , V_30 -> V_35 -> V_36 ,
V_2 -> V_21 ) ;
V_2 -> V_158 = 0 ;
F_73 ( V_2 , L_65 ,
V_30 -> V_32 . V_271 ) ;
V_2 -> V_174 . V_231 = 0 ;
V_2 -> V_174 . V_232 = V_30 -> V_32 . V_271 ;
V_2 -> V_174 . V_272 =
V_273 ;
V_2 -> V_174 . V_274 = V_257 ;
V_2 -> V_174 . V_275 = V_276 | V_277 | V_278 ;
#ifdef F_178
V_2 -> V_174 . V_279 = & V_280 ;
#endif
V_43 = F_159 ( V_2 ) ;
if ( V_43 ) {
if ( V_2 -> V_158 >= 0 )
V_2 -> V_158 = - 1 ;
return;
}
if ( V_2 -> V_9 & V_10 )
F_120 ( & V_2 -> V_11 -> V_12 ) ;
else if ( V_2 -> V_9 & ( V_13 | V_14 ) )
F_119 ( V_2 , V_2 -> V_15 ) ;
}
static void F_179 ( struct V_29 * V_30 )
{
struct V_83 * V_35 = V_30 -> V_35 ;
unsigned int V_281 , V_282 , V_222 , V_283 , V_62 ;
struct V_1 * V_2 ;
if ( V_30 -> V_32 . V_160 > V_30 -> V_32 . V_284 )
V_281 = 0 ;
else
V_281 = V_30 -> V_32 . V_284 -
V_30 -> V_32 . V_160 ;
F_10 ( L_66 ,
V_35 -> V_36 , V_30 -> V_32 . V_284 ) ;
F_10 ( L_67 ,
V_30 -> V_32 . V_160 , V_30 -> V_32 . V_140 ) ;
F_168 ( V_30 ) ;
V_282 = V_30 -> V_32 . V_284 ;
V_283 = V_30 -> V_32 . V_140 ;
V_62 = 0 ;
F_26 (pe, &phb->ioda.pe_dma_list, dma_link) {
if ( ! V_2 -> V_140 )
continue;
if ( ! V_282 ) {
F_54 ( V_2 , L_68 ) ;
continue;
}
V_222 = 1 ;
if ( V_281 ) {
V_222 += ( ( V_2 -> V_140 * V_281 ) + ( V_283 / 2 ) ) / V_283 ;
if ( V_222 > V_282 )
V_222 = V_282 ;
}
if ( V_30 -> type == V_135 ) {
F_73 ( V_2 , L_69 ,
V_2 -> V_140 , V_222 ) ;
F_142 ( V_30 , V_2 , V_62 , V_222 ) ;
} else {
F_73 ( V_2 , L_70 ) ;
V_222 = 0 ;
F_101 ( V_30 , V_2 ) ;
}
V_282 -= V_222 ;
V_62 += V_222 ;
}
}
static void F_180 ( struct V_285 * V_286 )
{
unsigned int V_287 = ( unsigned int ) F_181 ( V_286 ) ;
struct V_288 * V_289 = F_182 ( V_286 ) ;
struct V_29 * V_30 = F_123 ( V_289 , struct V_29 ,
V_32 . V_288 ) ;
T_11 V_43 ;
V_43 = F_183 ( V_30 -> V_44 , V_287 ) ;
F_184 ( V_43 ) ;
F_185 ( V_286 ) ;
}
static void F_186 ( struct V_29 * V_30 , unsigned int V_290 )
{
struct V_285 * V_291 ;
struct V_288 * V_292 ;
if ( V_30 -> type != V_88 )
return;
if ( ! V_30 -> V_32 . V_293 ) {
V_291 = F_187 ( V_290 ) ;
V_292 = F_182 ( V_291 ) ;
V_30 -> V_32 . V_293 = 1 ;
V_30 -> V_32 . V_288 = * V_292 ;
V_30 -> V_32 . V_288 . V_294 = F_180 ;
}
F_188 ( V_290 , & V_30 -> V_32 . V_288 ) ;
}
struct V_84 * F_189 ( struct V_61 * V_12 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
return F_190 ( V_35 -> V_85 ) ;
}
int F_191 ( struct V_61 * V_12 , T_13 V_295 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
struct V_1 * V_2 ;
int V_43 ;
V_2 = F_49 ( V_12 ) ;
if ( ! V_2 )
return - V_191 ;
F_73 ( V_2 , L_71 ) ;
V_43 = F_192 ( V_30 -> V_44 , V_295 , V_2 -> V_21 ) ;
if ( V_43 )
F_57 ( & V_12 -> V_12 , L_72 , V_43 ) ;
return V_43 ;
}
int F_193 ( struct V_61 * V_12 , int V_235 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
int V_296 = F_194 ( & V_30 -> V_297 , V_235 ) ;
if ( V_296 < 0 ) {
F_92 ( & V_12 -> V_12 , L_73 ) ;
return - V_298 ;
}
return V_30 -> V_299 + V_296 ;
}
void F_195 ( struct V_61 * V_12 , int V_296 , int V_235 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
F_196 ( & V_30 -> V_297 , V_296 - V_30 -> V_299 , V_235 ) ;
}
void F_197 ( struct V_300 * V_301 ,
struct V_61 * V_12 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
int V_64 , V_296 ;
for ( V_64 = 1 ; V_64 < V_302 ; V_64 ++ ) {
if ( ! V_301 -> V_303 [ V_64 ] )
continue;
F_174 ( L_74 ,
V_64 , V_301 -> V_150 [ V_64 ] ,
V_301 -> V_303 [ V_64 ] ) ;
V_296 = V_301 -> V_150 [ V_64 ] - V_30 -> V_299 ;
F_196 ( & V_30 -> V_297 , V_296 ,
V_301 -> V_303 [ V_64 ] ) ;
}
}
int F_198 ( struct V_300 * V_301 ,
struct V_61 * V_12 , int V_235 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
int V_64 , V_296 , V_304 ;
memset ( V_301 , 0 , sizeof( struct V_300 ) ) ;
for ( V_64 = 1 ; V_64 < V_302 && V_235 ; V_64 ++ ) {
V_304 = V_235 ;
while ( V_304 ) {
V_296 = F_194 ( & V_30 -> V_297 , V_304 ) ;
if ( V_296 >= 0 )
break;
V_304 /= 2 ;
}
if ( ! V_304 )
goto V_50;
V_301 -> V_150 [ V_64 ] = V_30 -> V_299 + V_296 ;
V_301 -> V_303 [ V_64 ] = V_304 ;
F_174 ( L_75 ,
V_64 , V_301 -> V_150 [ V_64 ] , V_301 -> V_303 [ V_64 ] ) ;
V_235 -= V_304 ;
}
if ( V_235 )
goto V_50;
return 0 ;
V_50:
F_197 ( V_301 , V_12 ) ;
return - V_298 ;
}
int F_199 ( struct V_61 * V_12 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
return V_30 -> V_297 . V_305 ;
}
int F_200 ( struct V_61 * V_12 , unsigned int V_296 ,
unsigned int V_290 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
unsigned int V_306 = V_296 - V_30 -> V_299 ;
struct V_1 * V_2 ;
int V_43 ;
if ( ! ( V_2 = F_49 ( V_12 ) ) )
return - V_191 ;
V_43 = F_201 ( V_30 -> V_44 , V_2 -> V_21 , V_306 ) ;
if ( V_43 ) {
F_54 ( V_2 , L_76
L_77 ,
F_70 ( V_12 ) , V_43 , V_30 -> V_299 , V_296 , V_306 ) ;
return - V_59 ;
}
F_186 ( V_30 , V_290 ) ;
return 0 ;
}
static int F_202 ( struct V_29 * V_30 , struct V_61 * V_12 ,
unsigned int V_296 , unsigned int V_290 ,
unsigned int V_307 , struct V_308 * V_309 )
{
struct V_1 * V_2 = F_49 ( V_12 ) ;
unsigned int V_306 = V_296 - V_30 -> V_299 ;
T_19 V_310 ;
int V_43 ;
if ( V_2 == NULL )
return - V_112 ;
if ( V_2 -> V_136 < 0 )
return - V_112 ;
if ( V_12 -> V_311 )
V_307 = 0 ;
V_43 = F_201 ( V_30 -> V_44 , V_2 -> V_21 , V_306 ) ;
if ( V_43 ) {
F_14 ( L_78 ,
F_70 ( V_12 ) , V_43 , V_306 ) ;
return - V_59 ;
}
if ( V_307 ) {
T_14 V_312 ;
V_43 = F_203 ( V_30 -> V_44 , V_2 -> V_136 , V_306 , 1 ,
& V_312 , & V_310 ) ;
if ( V_43 ) {
F_14 ( L_79 ,
F_70 ( V_12 ) , V_43 ) ;
return - V_59 ;
}
V_309 -> V_313 = F_175 ( V_312 ) >> 32 ;
V_309 -> V_314 = F_175 ( V_312 ) & 0xfffffffful ;
} else {
T_19 V_315 ;
V_43 = F_204 ( V_30 -> V_44 , V_2 -> V_136 , V_306 , 1 ,
& V_315 , & V_310 ) ;
if ( V_43 ) {
F_14 ( L_80 ,
F_70 ( V_12 ) , V_43 ) ;
return - V_59 ;
}
V_309 -> V_313 = 0 ;
V_309 -> V_314 = F_205 ( V_315 ) ;
}
V_309 -> V_310 = F_205 ( V_310 ) ;
F_186 ( V_30 , V_290 ) ;
F_174 ( L_81
L_82 ,
F_70 ( V_12 ) , V_307 ? L_83 : L_84 , V_296 , V_306 ,
V_309 -> V_313 , V_309 -> V_314 , V_310 , V_2 -> V_21 ) ;
return 0 ;
}
static void F_206 ( struct V_29 * V_30 )
{
unsigned int V_120 ;
const T_19 * V_316 = F_40 ( V_30 -> V_35 -> V_85 ,
L_85 , NULL ) ;
if ( ! V_316 ) {
V_316 = F_40 ( V_30 -> V_35 -> V_85 , L_86 , NULL ) ;
}
if ( ! V_316 )
return;
V_30 -> V_299 = F_207 ( V_316 ) ;
V_120 = F_207 ( V_316 + 1 ) ;
if ( F_208 ( & V_30 -> V_297 , V_120 , V_30 -> V_35 -> V_85 ) ) {
F_172 ( L_87 ,
V_30 -> V_35 -> V_36 ) ;
return;
}
V_30 -> V_317 = F_202 ;
V_30 -> V_318 = 1 ;
F_10 ( L_88 ,
V_120 , V_30 -> V_299 ) ;
}
static void F_206 ( struct V_29 * V_30 ) { }
static void F_209 ( struct V_61 * V_11 )
{
struct V_83 * V_35 ;
struct V_29 * V_30 ;
struct V_41 * V_86 ;
int V_64 ;
T_6 V_72 ;
struct V_105 * V_106 ;
int V_319 , V_167 ;
if ( ! V_11 -> V_153 || V_11 -> V_320 )
return;
V_35 = F_50 ( V_11 -> V_19 ) ;
V_30 = V_35 -> V_104 ;
V_106 = F_51 ( V_11 ) ;
V_106 -> V_321 = 0 ;
V_167 = F_80 ( V_11 ) ;
V_106 -> V_170 = 1 ;
V_319 = V_30 -> V_32 . V_33 ;
for ( V_64 = 0 ; V_64 < V_154 ; V_64 ++ ) {
V_86 = & V_11 -> V_41 [ V_64 + V_155 ] ;
if ( ! V_86 -> V_9 || V_86 -> V_67 )
continue;
if ( ! F_12 ( V_86 -> V_9 ) ) {
F_92 ( & V_11 -> V_12 , L_89 ,
V_64 , V_86 ) ;
continue;
}
V_72 = F_66 ( V_11 , V_64 + V_155 ) ;
if ( V_72 > ( 1 << 26 ) ) {
F_67 ( & V_11 -> V_12 , L_90 ,
V_64 , V_86 ) ;
V_106 -> V_170 = V_163 ;
V_319 = F_81 ( V_167 ) ;
break;
}
}
for ( V_64 = 0 ; V_64 < V_154 ; V_64 ++ ) {
V_86 = & V_11 -> V_41 [ V_64 + V_155 ] ;
if ( ! V_86 -> V_9 || V_86 -> V_67 )
continue;
if ( ! F_12 ( V_86 -> V_9 ) ) {
F_92 ( & V_11 -> V_12 , L_91 ,
V_64 , V_86 ) ;
continue;
}
F_210 ( & V_11 -> V_12 , L_92 , V_64 , V_86 ) ;
V_72 = F_66 ( V_11 , V_64 + V_155 ) ;
V_86 -> V_57 = V_86 -> V_55 + V_72 * V_319 - 1 ;
F_210 ( & V_11 -> V_12 , L_93 , V_86 ) ;
F_67 ( & V_11 -> V_12 , L_94 ,
V_64 , V_86 , V_319 ) ;
}
V_106 -> V_321 = V_319 ;
}
static void F_211 ( struct V_83 * V_35 ,
struct V_1 * V_2 )
{
struct V_29 * V_30 = V_35 -> V_104 ;
struct V_322 V_323 ;
struct V_41 * V_86 ;
int V_64 , V_196 ;
int V_43 ;
F_87 ( ! ( V_2 -> V_9 & ( V_13 | V_14 ) ) ) ;
F_30 (pe->pbus, res, i) {
if ( ! V_86 || ! V_86 -> V_9 ||
V_86 -> V_55 > V_86 -> V_57 )
continue;
if ( V_86 -> V_9 & V_324 ) {
V_323 . V_55 = V_86 -> V_55 - V_30 -> V_32 . V_325 ;
V_323 . V_57 = V_86 -> V_57 - V_30 -> V_32 . V_325 ;
V_196 = V_323 . V_55 / V_30 -> V_32 . V_326 ;
while ( V_196 < V_30 -> V_32 . V_33 &&
V_323 . V_55 <= V_323 . V_57 ) {
V_30 -> V_32 . V_327 [ V_196 ] = V_2 -> V_21 ;
V_43 = F_82 ( V_30 -> V_44 ,
V_2 -> V_21 , V_328 , 0 , V_196 ) ;
if ( V_43 != V_49 ) {
F_172 ( L_95
L_96 ,
V_34 , V_43 , V_196 , V_2 -> V_21 ) ;
break;
}
V_323 . V_55 += V_30 -> V_32 . V_326 ;
V_196 ++ ;
}
} else if ( ( V_86 -> V_9 & V_91 ) &&
! F_12 ( V_86 -> V_9 ) ) {
V_323 . V_55 = V_86 -> V_55 -
V_35 -> V_92 [ 0 ] -
V_30 -> V_32 . V_271 ;
V_323 . V_57 = V_86 -> V_57 -
V_35 -> V_92 [ 0 ] -
V_30 -> V_32 . V_271 ;
V_196 = V_323 . V_55 / V_30 -> V_32 . V_329 ;
while ( V_196 < V_30 -> V_32 . V_33 &&
V_323 . V_55 <= V_323 . V_57 ) {
V_30 -> V_32 . V_330 [ V_196 ] = V_2 -> V_21 ;
V_43 = F_82 ( V_30 -> V_44 ,
V_2 -> V_21 , V_331 , 0 , V_196 ) ;
if ( V_43 != V_49 ) {
F_172 ( L_97
L_98 ,
V_34 , V_43 , V_196 , V_2 -> V_21 ) ;
break;
}
V_323 . V_55 += V_30 -> V_32 . V_329 ;
V_196 ++ ;
}
}
}
}
static void F_212 ( void )
{
struct V_83 * V_162 , * V_35 ;
struct V_29 * V_30 ;
struct V_1 * V_2 ;
F_77 (hose, tmp, &hose_list, list_node) {
V_30 = V_35 -> V_104 ;
F_26 (pe, &phb->ioda.pe_list, list) {
F_211 ( V_35 , V_2 ) ;
}
}
}
static void F_213 ( void )
{
struct V_83 * V_35 , * V_162 ;
struct V_29 * V_30 ;
F_77 (hose, tmp, &hose_list, list_node) {
F_179 ( V_35 -> V_104 ) ;
V_30 = V_35 -> V_104 ;
V_30 -> V_332 = 1 ;
}
}
static void F_214 ( void )
{
#ifdef F_215
struct V_83 * V_35 , * V_162 ;
struct V_29 * V_30 ;
char V_333 [ 16 ] ;
F_77 (hose, tmp, &hose_list, list_node) {
V_30 = V_35 -> V_104 ;
sprintf ( V_333 , L_99 , V_35 -> V_36 ) ;
V_30 -> V_334 = F_216 ( V_333 , V_335 ) ;
if ( ! V_30 -> V_334 )
F_72 ( L_100 ,
V_34 , V_35 -> V_36 ) ;
}
#endif
}
static void F_217 ( void )
{
F_76 () ;
F_212 () ;
F_213 () ;
F_214 () ;
#ifdef F_218
F_219 () ;
F_220 () ;
#endif
}
static T_6 F_221 ( struct V_68 * V_19 ,
unsigned long type )
{
struct V_61 * V_336 ;
struct V_83 * V_35 = F_50 ( V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
int V_337 = 0 ;
V_336 = V_19 -> V_115 ;
while ( V_336 ) {
if ( F_75 ( V_336 ) == V_161 ) {
V_337 ++ ;
if ( V_337 >= 2 )
return 1 ;
}
V_336 = V_336 -> V_19 -> V_115 ;
}
if ( V_30 -> V_32 . V_56 &&
F_12 ( type ) )
return V_30 -> V_32 . V_56 ;
if ( type & V_91 )
return V_30 -> V_32 . V_329 ;
return V_30 -> V_32 . V_326 ;
}
static T_6 F_222 ( struct V_61 * V_11 ,
int V_338 )
{
struct V_105 * V_106 = F_51 ( V_11 ) ;
T_6 V_339 , V_340 ;
V_340 = F_27 ( & V_11 -> V_41 [ V_338 ] ) ;
if ( V_340 )
return V_340 ;
V_339 = F_66 ( V_11 , V_338 ) ;
if ( V_106 -> V_321 )
return V_106 -> V_321 * V_339 ;
return V_339 ;
}
static bool F_223 ( struct V_61 * V_12 )
{
struct V_83 * V_35 = F_50 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_104 ;
struct V_105 * V_106 ;
if ( ! V_30 -> V_332 )
return true ;
V_106 = F_51 ( V_12 ) ;
if ( ! V_106 || V_106 -> V_21 == V_39 )
return false ;
return true ;
}
static T_7 F_224 ( struct V_29 * V_30 , struct V_68 * V_19 ,
T_7 V_341 )
{
return V_30 -> V_32 . V_132 [ ( V_19 -> V_16 << 8 ) | V_341 ] ;
}
static void F_225 ( struct V_83 * V_35 )
{
struct V_29 * V_30 = V_35 -> V_104 ;
F_226 ( V_30 -> V_44 , V_342 ,
V_343 ) ;
}
static void T_2 F_227 ( struct V_84 * V_344 ,
T_3 V_345 , int V_346 )
{
struct V_83 * V_35 ;
struct V_29 * V_30 ;
unsigned long V_72 , V_347 , V_348 , V_349 = 0 ;
const T_14 * V_350 ;
const T_19 * V_351 ;
int V_352 ;
T_3 V_353 ;
void * V_354 ;
long V_43 ;
F_10 ( L_101 , V_346 , V_344 -> V_90 ) ;
V_350 = F_40 ( V_344 , L_102 , NULL ) ;
if ( ! V_350 ) {
F_172 ( L_103 ) ;
return;
}
V_353 = F_169 ( V_350 ) ;
F_228 ( L_104 , V_353 ) ;
V_30 = F_229 ( sizeof( struct V_29 ) , 0 ) ;
V_30 -> V_35 = V_35 = F_230 ( V_344 ) ;
if ( ! V_30 -> V_35 ) {
F_172 ( L_105 ,
V_344 -> V_90 ) ;
F_231 ( F_124 ( V_30 ) , sizeof( struct V_29 ) ) ;
return;
}
F_232 ( & V_30 -> V_355 ) ;
V_351 = F_40 ( V_344 , L_106 , & V_352 ) ;
if ( V_351 && V_352 == 8 ) {
V_35 -> V_356 = F_205 ( V_351 [ 0 ] ) ;
V_35 -> V_357 = F_205 ( V_351 [ 1 ] ) ;
} else {
F_14 ( L_107 , V_344 -> V_90 ) ;
V_35 -> V_356 = 0 ;
V_35 -> V_357 = 0xff ;
}
V_35 -> V_104 = V_30 ;
V_30 -> V_345 = V_345 ;
V_30 -> V_44 = V_353 ;
V_30 -> type = V_346 ;
F_233 ( & V_30 -> V_32 . V_186 ) ;
if ( F_234 ( V_344 , L_108 ) )
V_30 -> V_358 = V_359 ;
else if ( F_234 ( V_344 , L_109 ) )
V_30 -> V_358 = V_360 ;
else
V_30 -> V_358 = V_361 ;
F_235 ( V_35 , V_344 , ! V_35 -> V_36 ) ;
V_30 -> V_362 = F_236 ( V_344 , 0 ) ;
if ( V_30 -> V_362 == NULL )
F_172 ( L_110 ) ;
V_30 -> V_32 . V_33 = 1 ;
V_351 = F_40 ( V_344 , L_111 , NULL ) ;
if ( V_351 )
V_30 -> V_32 . V_33 = F_207 ( V_351 ) ;
V_351 = F_40 ( V_344 , L_112 , NULL ) ;
if ( V_351 )
V_30 -> V_32 . V_54 = F_207 ( V_351 ) ;
F_38 ( V_30 ) ;
V_30 -> V_32 . V_363 = F_27 ( & V_35 -> V_53 [ 0 ] ) ;
V_30 -> V_32 . V_363 += 0x10000 ;
V_30 -> V_32 . V_329 = V_30 -> V_32 . V_363 / V_30 -> V_32 . V_33 ;
V_30 -> V_32 . V_271 = V_35 -> V_53 [ 0 ] . V_55 - V_35 -> V_92 [ 0 ] ;
V_30 -> V_32 . V_364 = V_35 -> V_365 ;
V_30 -> V_32 . V_326 = V_30 -> V_32 . V_364 / V_30 -> V_32 . V_33 ;
V_30 -> V_32 . V_325 = 0 ;
V_72 = F_31 ( V_30 -> V_32 . V_33 / 8 , sizeof( unsigned long ) ) ;
V_347 = V_72 ;
V_72 += V_30 -> V_32 . V_33 * sizeof( V_30 -> V_32 . V_330 [ 0 ] ) ;
if ( V_30 -> type == V_135 ) {
V_349 = V_72 ;
V_72 += V_30 -> V_32 . V_33 * sizeof( V_30 -> V_32 . V_327 [ 0 ] ) ;
}
V_348 = V_72 ;
V_72 += V_30 -> V_32 . V_33 * sizeof( struct V_1 ) ;
V_354 = F_229 ( V_72 , 0 ) ;
V_30 -> V_32 . V_37 = V_354 ;
V_30 -> V_32 . V_330 = V_354 + V_347 ;
if ( V_30 -> type == V_135 )
V_30 -> V_32 . V_327 = V_354 + V_349 ;
V_30 -> V_32 . V_38 = V_354 + V_348 ;
F_24 ( V_30 -> V_32 . V_54 , V_30 -> V_32 . V_37 ) ;
F_36 ( & V_30 -> V_32 . V_142 ) ;
F_36 ( & V_30 -> V_32 . V_159 ) ;
F_233 ( & V_30 -> V_32 . V_182 ) ;
V_30 -> V_32 . V_284 = V_30 -> V_32 . V_271 >> 28 ;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
F_10 ( L_113 ,
V_30 -> V_32 . V_33 , V_30 -> V_32 . V_54 ,
V_30 -> V_32 . V_363 , V_30 -> V_32 . V_329 ) ;
if ( V_30 -> V_32 . V_48 )
F_10 ( L_114 ,
V_30 -> V_32 . V_48 , V_30 -> V_32 . V_56 ) ;
if ( V_30 -> V_32 . V_364 )
F_10 ( L_115 ,
V_30 -> V_32 . V_364 , V_30 -> V_32 . V_326 ) ;
V_30 -> V_35 -> V_279 = & V_366 ;
V_30 -> V_367 = F_47 ;
V_30 -> V_368 = F_43 ;
V_30 -> V_369 = F_45 ;
V_30 -> V_370 = F_224 ;
V_30 -> V_371 = F_109 ;
V_30 -> V_372 = F_116 ;
F_206 ( V_30 ) ;
V_373 . V_374 = F_217 ;
V_35 -> V_375 = V_376 ;
#ifdef F_5
V_373 . V_377 = F_209 ;
V_373 . V_378 = F_222 ;
#endif
F_237 ( V_379 ) ;
V_43 = F_226 ( V_353 , V_342 , V_343 ) ;
if ( V_43 )
F_72 ( L_116 , V_43 ) ;
if ( F_238 () ) {
F_10 ( L_117 ) ;
F_239 ( V_35 , V_380 ) ;
F_239 ( V_35 , V_381 ) ;
}
if ( ! V_30 -> V_93 || V_30 -> V_93 ( V_30 ) )
V_35 -> V_53 [ 1 ] . V_9 = 0 ;
}
void T_2 F_240 ( struct V_84 * V_344 )
{
F_227 ( V_344 , 0 , V_88 ) ;
}
void T_2 F_241 ( struct V_84 * V_344 )
{
struct V_84 * V_382 ;
const T_14 * V_350 ;
T_3 V_345 ;
F_10 ( L_118 , V_344 -> V_90 ) ;
V_350 = F_40 ( V_344 , L_119 , NULL ) ;
if ( ! V_350 ) {
F_172 ( L_120 ) ;
return;
}
V_345 = F_169 ( V_350 ) ;
F_174 ( L_121 , V_345 ) ;
F_242 (np, phbn) {
if ( F_234 ( V_382 , L_122 ) )
F_227 ( V_382 , V_345 , V_135 ) ;
}
}
