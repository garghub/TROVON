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
if ( F_15 ( V_31 , V_30 -> V_32 . V_37 ) )
F_16 ( L_8 ,
V_34 , V_31 , V_30 -> V_35 -> V_36 ) ;
V_30 -> V_32 . V_38 [ V_31 ] . V_30 = V_30 ;
V_30 -> V_32 . V_38 [ V_31 ] . V_21 = V_31 ;
}
static int F_17 ( struct V_29 * V_30 )
{
unsigned long V_2 ;
do {
V_2 = F_18 ( V_30 -> V_32 . V_37 ,
V_30 -> V_32 . V_33 , 0 ) ;
if ( V_2 >= V_30 -> V_32 . V_33 )
return V_39 ;
} while( F_15 ( V_2 , V_30 -> V_32 . V_37 ) );
V_30 -> V_32 . V_38 [ V_2 ] . V_30 = V_30 ;
V_30 -> V_32 . V_38 [ V_2 ] . V_21 = V_2 ;
return V_2 ;
}
static void F_19 ( struct V_29 * V_30 , int V_2 )
{
F_20 ( V_30 -> V_32 . V_38 [ V_2 ] . V_11 ) ;
memset ( & V_30 -> V_32 . V_38 [ V_2 ] , 0 , sizeof( struct V_1 ) ) ;
F_21 ( V_2 , V_30 -> V_32 . V_37 ) ;
}
static int F_22 ( struct V_29 * V_30 )
{
const char * V_40 ;
struct V_41 * V_42 ;
T_5 V_43 ;
V_43 = F_23 ( V_30 -> V_44 ,
V_45 ,
V_30 -> V_32 . V_46 ,
V_30 -> V_32 . V_47 ,
0 ,
V_30 -> V_32 . V_48 ) ;
if ( V_43 != V_49 ) {
V_40 = L_9 ;
goto V_50;
}
V_43 = F_24 ( V_30 -> V_44 ,
V_45 ,
V_30 -> V_32 . V_46 ,
V_51 ) ;
if ( V_43 != V_49 ) {
V_40 = L_10 ;
goto V_50;
}
F_25 ( V_30 -> V_32 . V_46 , & V_30 -> V_32 . V_52 ) ;
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
F_24 ( V_30 -> V_44 ,
V_45 ,
V_30 -> V_32 . V_46 ,
V_58 ) ;
return - V_59 ;
}
static void F_26 ( struct V_60 * V_11 ,
unsigned long * V_61 )
{
struct V_62 * V_35 = F_27 ( V_11 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_63 ;
struct V_41 * V_42 ;
T_6 V_64 , V_65 , V_55 , V_57 ;
int V_66 , V_67 ;
V_64 = V_30 -> V_32 . V_47 ;
V_65 = V_30 -> V_32 . V_56 ;
for ( V_67 = 0 ; V_67 <= V_68 ; V_67 ++ ) {
V_42 = & V_11 -> V_41 [ V_67 ] ;
if ( ! V_42 -> V_69 || ! F_12 ( V_42 -> V_9 ) )
continue;
V_55 = F_28 ( V_42 -> V_55 - V_64 , V_65 ) ;
V_57 = F_29 ( V_42 -> V_57 - V_64 , V_65 ) ;
for ( V_66 = V_55 / V_65 ; V_66 < V_57 / V_65 ; V_66 ++ ) {
if ( V_61 )
F_25 ( V_66 , V_61 ) ;
else
F_13 ( V_30 , V_66 ) ;
}
}
}
static void F_30 ( struct V_70 * V_19 ,
unsigned long * V_61 ,
bool V_71 )
{
struct V_60 * V_11 ;
F_31 (pdev, &bus->devices, bus_list) {
F_26 ( V_11 , V_61 ) ;
if ( V_71 && V_11 -> V_72 )
F_30 ( V_11 -> V_72 ,
V_61 , V_71 ) ;
}
}
static int F_32 ( struct V_70 * V_19 , bool V_71 )
{
struct V_62 * V_35 = F_27 ( V_19 ) ;
struct V_29 * V_30 = V_35 -> V_63 ;
struct V_1 * V_73 , * V_2 ;
unsigned long V_74 , * V_37 ;
int V_67 ;
if ( F_33 ( V_19 ) )
return V_39 ;
V_74 = F_29 ( V_30 -> V_32 . V_33 / 8 , sizeof( unsigned long ) ) ;
V_37 = F_34 ( V_74 , V_75 ) ;
if ( ! V_37 ) {
F_14 ( L_13 ,
V_34 ) ;
return V_39 ;
}
F_30 ( V_19 , V_37 , V_71 ) ;
if ( F_35 ( V_37 , V_30 -> V_32 . V_33 ) ) {
F_36 ( V_37 ) ;
return V_39 ;
}
V_73 = NULL ;
V_67 = - 1 ;
while ( ( V_67 = F_37 ( V_37 , V_30 -> V_32 . V_33 , V_67 + 1 ) ) <
V_30 -> V_32 . V_33 ) {
V_2 = & V_30 -> V_32 . V_38 [ V_67 ] ;
if ( ! V_73 ) {
V_2 -> V_9 |= V_76 ;
F_38 ( & V_2 -> V_77 ) ;
V_73 = V_2 ;
} else {
V_2 -> V_9 |= V_78 ;
V_2 -> V_79 = V_73 ;
F_39 ( & V_2 -> V_80 , & V_73 -> V_77 ) ;
}
}
F_36 ( V_37 ) ;
return V_73 -> V_21 ;
}
static void T_2 F_40 ( struct V_29 * V_30 )
{
struct V_62 * V_35 = V_30 -> V_35 ;
struct V_81 * V_82 = V_35 -> V_82 ;
struct V_41 * V_83 ;
const T_7 * V_42 ;
T_3 V_84 ;
if ( V_30 -> type != V_85 ) {
F_10 ( L_14 ) ;
return;
}
if ( ! F_41 ( V_86 ) ) {
F_10 ( L_15 ) ;
return;
}
V_42 = F_42 ( V_82 , L_16 , NULL ) ;
if ( ! V_42 ) {
F_10 ( L_17 ,
V_82 -> V_87 ) ;
return;
}
V_83 = & V_35 -> V_53 [ 1 ] ;
V_83 -> V_55 = F_43 ( V_82 , V_42 + 2 ) ;
V_83 -> V_57 = V_83 -> V_55 + F_44 ( V_42 + 4 , 2 ) - 1 ;
V_83 -> V_9 = ( V_88 | V_27 | V_28 ) ;
V_84 = F_44 ( V_42 , 2 ) ;
V_35 -> V_89 [ 1 ] = V_83 -> V_55 - V_84 ;
V_30 -> V_32 . V_48 = F_45 ( V_83 ) ;
V_30 -> V_32 . V_56 = V_30 -> V_32 . V_48 / V_30 -> V_32 . V_33 ;
V_30 -> V_32 . V_47 = V_84 ;
F_10 ( L_18 ,
V_83 -> V_55 , V_83 -> V_57 , V_84 ) ;
V_30 -> V_32 . V_46 = 15 ;
V_30 -> V_90 = F_22 ;
V_30 -> V_91 = F_30 ;
V_30 -> V_92 = F_32 ;
}
static void F_46 ( struct V_29 * V_30 , int V_31 )
{
struct V_1 * V_2 = & V_30 -> V_32 . V_38 [ V_31 ] ;
struct V_1 * V_93 ;
T_5 V_43 ;
if ( V_2 -> V_9 & V_78 ) {
V_2 = V_2 -> V_79 ;
if ( F_20 ( ! V_2 || ! ( V_2 -> V_9 & V_76 ) ) )
return;
V_31 = V_2 -> V_21 ;
}
V_43 = F_47 ( V_30 -> V_44 ,
V_31 ,
V_94 ) ;
if ( V_43 != V_49 ) {
F_14 ( L_19 ,
V_34 , V_43 , V_30 -> V_35 -> V_36 , V_31 ) ;
return;
}
if ( ! ( V_2 -> V_9 & V_76 ) )
return;
F_31 (slave, &pe->slaves, list) {
V_43 = F_47 ( V_30 -> V_44 ,
V_93 -> V_21 ,
V_94 ) ;
if ( V_43 != V_49 )
F_14 ( L_19 ,
V_34 , V_43 , V_30 -> V_35 -> V_36 ,
V_93 -> V_21 ) ;
}
}
static int F_48 ( struct V_29 * V_30 , int V_31 , int V_95 )
{
struct V_1 * V_2 , * V_93 ;
T_5 V_43 ;
V_2 = & V_30 -> V_32 . V_38 [ V_31 ] ;
if ( V_2 -> V_9 & V_78 ) {
V_2 = V_2 -> V_79 ;
F_20 ( ! V_2 || ! ( V_2 -> V_9 & V_76 ) ) ;
V_31 = V_2 -> V_21 ;
}
V_43 = F_49 ( V_30 -> V_44 , V_31 , V_95 ) ;
if ( V_43 != V_49 ) {
F_14 ( L_20 ,
V_34 , V_43 , V_95 , V_30 -> V_35 -> V_36 , V_31 ) ;
return - V_59 ;
}
if ( ! ( V_2 -> V_9 & V_76 ) )
return 0 ;
F_31 (slave, &pe->slaves, list) {
V_43 = F_49 ( V_30 -> V_44 ,
V_93 -> V_21 ,
V_95 ) ;
if ( V_43 != V_49 ) {
F_14 ( L_20 ,
V_34 , V_43 , V_95 , V_30 -> V_35 -> V_36 ,
V_93 -> V_21 ) ;
return - V_59 ;
}
}
return 0 ;
}
static int F_50 ( struct V_29 * V_30 , int V_31 )
{
struct V_1 * V_93 , * V_2 ;
T_8 V_96 , V_97 ;
T_9 V_98 ;
T_5 V_43 ;
if ( V_31 < 0 || V_31 >= V_30 -> V_32 . V_33 )
return V_99 ;
V_2 = & V_30 -> V_32 . V_38 [ V_31 ] ;
if ( V_2 -> V_9 & V_78 ) {
V_2 = V_2 -> V_79 ;
F_20 ( ! V_2 || ! ( V_2 -> V_9 & V_76 ) ) ;
V_31 = V_2 -> V_21 ;
}
V_43 = F_51 ( V_30 -> V_44 , V_31 ,
& V_97 , & V_98 , NULL ) ;
if ( V_43 != V_49 ) {
F_14 ( L_21
L_22 ,
V_34 , V_43 ,
V_30 -> V_35 -> V_36 , V_31 ) ;
return V_100 ;
}
if ( ! ( V_2 -> V_9 & V_76 ) )
return V_97 ;
F_31 (slave, &pe->slaves, list) {
V_43 = F_51 ( V_30 -> V_44 ,
V_93 -> V_21 ,
& V_96 ,
& V_98 ,
NULL ) ;
if ( V_43 != V_49 ) {
F_14 ( L_21
L_22 ,
V_34 , V_43 ,
V_30 -> V_35 -> V_36 , V_93 -> V_21 ) ;
return V_100 ;
}
if ( V_96 > V_97 )
V_97 = V_96 ;
}
return V_97 ;
}
static struct V_1 * F_52 ( struct V_60 * V_12 )
{
struct V_62 * V_35 = F_27 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_63 ;
struct V_101 * V_102 = F_53 ( V_12 ) ;
if ( ! V_102 )
return NULL ;
if ( V_102 -> V_21 == V_39 )
return NULL ;
return & V_30 -> V_32 . V_38 [ V_102 -> V_21 ] ;
}
static int F_54 ( struct V_29 * V_30 ,
struct V_1 * V_69 ,
struct V_1 * V_103 ,
bool V_104 )
{
const char * V_40 = V_104 ? L_23 : L_24 ;
T_10 V_105 = V_104 ? V_106 :
V_107 ;
struct V_1 * V_93 ;
long V_43 ;
V_43 = F_55 ( V_30 -> V_44 , V_69 -> V_21 ,
V_103 -> V_21 , V_105 ) ;
if ( V_43 != V_49 ) {
F_56 ( V_103 , L_25 ,
V_43 , V_40 ) ;
return - V_108 ;
}
if ( ! ( V_103 -> V_9 & V_76 ) )
return 0 ;
F_31 (slave, &child->slaves, list) {
V_43 = F_55 ( V_30 -> V_44 , V_69 -> V_21 ,
V_93 -> V_21 , V_105 ) ;
if ( V_43 != V_49 ) {
F_56 ( V_93 , L_25 ,
V_43 , V_40 ) ;
return - V_108 ;
}
}
return 0 ;
}
static int F_57 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
bool V_104 )
{
struct V_1 * V_93 ;
struct V_60 * V_11 = NULL ;
int V_109 ;
if ( V_104 ) {
F_49 ( V_30 -> V_44 , V_2 -> V_21 ,
V_110 ) ;
if ( V_2 -> V_9 & V_76 ) {
F_31 (slave, &pe->slaves, list)
F_49 ( V_30 -> V_44 ,
V_93 -> V_21 ,
V_110 ) ;
}
}
V_109 = F_54 ( V_30 , V_2 , V_2 , V_104 ) ;
if ( V_109 )
return V_109 ;
if ( V_2 -> V_9 & V_76 ) {
F_31 (slave, &pe->slaves, list) {
V_109 = F_54 ( V_30 , V_93 , V_2 , V_104 ) ;
if ( V_109 )
return V_109 ;
}
}
if ( V_2 -> V_9 & ( V_14 | V_13 ) )
V_11 = V_2 -> V_15 -> V_111 ;
else if ( V_2 -> V_9 & V_10 )
V_11 = V_2 -> V_11 -> V_19 -> V_111 ;
#ifdef F_5
else if ( V_2 -> V_9 & V_17 )
V_11 = V_2 -> V_18 ;
#endif
while ( V_11 ) {
struct V_101 * V_102 = F_53 ( V_11 ) ;
struct V_1 * V_69 ;
if ( V_102 && V_102 -> V_21 != V_39 ) {
V_69 = & V_30 -> V_32 . V_38 [ V_102 -> V_21 ] ;
V_109 = F_54 ( V_30 , V_69 , V_2 , V_104 ) ;
if ( V_109 )
return V_109 ;
}
V_11 = V_11 -> V_19 -> V_111 ;
}
return 0 ;
}
static int F_58 ( struct V_29 * V_30 , struct V_1 * V_2 )
{
struct V_60 * V_69 ;
T_10 V_112 , V_113 , V_114 ;
T_11 V_43 ;
long V_115 , V_20 ;
if ( V_2 -> V_15 ) {
int V_116 ;
V_113 = V_117 ;
V_114 = V_118 ;
V_69 = V_2 -> V_15 -> V_111 ;
if ( V_2 -> V_9 & V_14 )
V_116 = V_2 -> V_15 -> V_119 . V_57 - V_2 -> V_15 -> V_119 . V_55 + 1 ;
else
V_116 = 1 ;
switch( V_116 ) {
case 1 : V_112 = V_120 ; break;
case 2 : V_112 = V_121 ; break;
case 4 : V_112 = V_122 ; break;
case 8 : V_112 = V_123 ; break;
case 16 : V_112 = V_124 ; break;
case 32 : V_112 = V_125 ; break;
default:
F_59 ( & V_2 -> V_15 -> V_12 , L_26 ,
V_116 ) ;
V_112 = V_120 ;
}
V_115 = V_2 -> V_20 + ( V_116 << 8 ) ;
} else {
if ( V_2 -> V_9 & V_17 )
V_69 = V_2 -> V_18 ;
else
V_69 = V_2 -> V_11 -> V_19 -> V_111 ;
V_112 = V_120 ;
V_113 = V_126 ;
V_114 = V_127 ;
V_115 = V_2 -> V_20 + 1 ;
}
for ( V_20 = V_2 -> V_20 ; V_20 < V_115 ; V_20 ++ )
V_30 -> V_32 . V_128 [ V_20 ] = 0 ;
while ( V_69 ) {
struct V_101 * V_102 = F_53 ( V_69 ) ;
if ( V_102 && V_102 -> V_21 != V_39 ) {
V_43 = F_55 ( V_30 -> V_44 , V_102 -> V_21 ,
V_2 -> V_21 , V_107 ) ;
}
V_69 = V_69 -> V_19 -> V_111 ;
}
F_49 ( V_30 -> V_44 , V_2 -> V_21 ,
V_110 ) ;
V_43 = F_55 ( V_30 -> V_44 , V_2 -> V_21 ,
V_2 -> V_21 , V_107 ) ;
if ( V_43 )
F_56 ( V_2 , L_27 , V_43 ) ;
V_43 = F_60 ( V_30 -> V_44 , V_2 -> V_21 , V_2 -> V_20 ,
V_112 , V_113 , V_114 , V_129 ) ;
if ( V_43 )
F_61 ( V_2 , L_28 , V_43 ) ;
V_2 -> V_15 = NULL ;
V_2 -> V_11 = NULL ;
V_2 -> V_18 = NULL ;
return 0 ;
}
static int F_62 ( struct V_29 * V_30 , struct V_1 * V_2 )
{
struct V_60 * V_69 ;
T_10 V_112 , V_113 , V_114 ;
long V_43 , V_115 , V_20 ;
if ( V_2 -> V_15 ) {
int V_116 ;
V_113 = V_117 ;
V_114 = V_118 ;
V_69 = V_2 -> V_15 -> V_111 ;
if ( V_2 -> V_9 & V_14 )
V_116 = V_2 -> V_15 -> V_119 . V_57 - V_2 -> V_15 -> V_119 . V_55 + 1 ;
else
V_116 = 1 ;
switch( V_116 ) {
case 1 : V_112 = V_120 ; break;
case 2 : V_112 = V_121 ; break;
case 4 : V_112 = V_122 ; break;
case 8 : V_112 = V_123 ; break;
case 16 : V_112 = V_124 ; break;
case 32 : V_112 = V_125 ; break;
default:
F_59 ( & V_2 -> V_15 -> V_12 , L_26 ,
V_116 ) ;
V_112 = V_120 ;
}
V_115 = V_2 -> V_20 + ( V_116 << 8 ) ;
} else {
#ifdef F_5
if ( V_2 -> V_9 & V_17 )
V_69 = V_2 -> V_18 ;
else
#endif
V_69 = V_2 -> V_11 -> V_19 -> V_111 ;
V_112 = V_120 ;
V_113 = V_126 ;
V_114 = V_127 ;
V_115 = V_2 -> V_20 + 1 ;
}
V_43 = F_60 ( V_30 -> V_44 , V_2 -> V_21 , V_2 -> V_20 ,
V_112 , V_113 , V_114 , V_130 ) ;
if ( V_43 ) {
F_61 ( V_2 , L_28 , V_43 ) ;
return - V_108 ;
}
F_57 ( V_30 , V_2 , true ) ;
for ( V_20 = V_2 -> V_20 ; V_20 < V_115 ; V_20 ++ )
V_30 -> V_32 . V_128 [ V_20 ] = V_2 -> V_21 ;
if ( V_30 -> type != V_131 ) {
V_2 -> V_132 = 0 ;
goto V_133;
}
V_2 -> V_132 = V_2 -> V_21 ;
V_43 = F_63 ( V_30 -> V_44 , V_2 -> V_132 , V_2 -> V_21 ) ;
if ( V_43 != V_49 ) {
F_61 ( V_2 , L_29 ,
V_43 , V_2 -> V_132 ) ;
V_2 -> V_132 = - 1 ;
} else {
V_43 = F_64 ( V_30 -> V_44 ,
V_2 -> V_132 , V_134 ) ;
if ( V_43 ) {
F_61 ( V_2 , L_30 ,
V_43 , V_2 -> V_132 ) ;
V_2 -> V_132 = - 1 ;
}
}
V_133:
return 0 ;
}
static void F_65 ( struct V_29 * V_30 ,
struct V_1 * V_2 )
{
struct V_1 * V_135 ;
F_31 (lpe, &phb->ioda.pe_dma_list, dma_link) {
if ( V_135 -> V_136 < V_2 -> V_136 ) {
F_39 ( & V_2 -> V_137 , & V_135 -> V_137 ) ;
return;
}
}
F_39 ( & V_2 -> V_137 , & V_30 -> V_32 . V_138 ) ;
}
static unsigned int F_66 ( struct V_60 * V_12 )
{
if ( V_12 -> V_139 != V_140 )
return 0 ;
if ( V_12 -> V_141 == V_142 ||
V_12 -> V_141 == V_143 ||
V_12 -> V_141 == V_144 )
return 3 ;
if ( ( V_12 -> V_141 >> 8 ) == V_145 )
return 15 ;
return 10 ;
}
static int F_67 ( struct V_60 * V_12 , int V_146 )
{
struct V_101 * V_102 = F_53 ( V_12 ) ;
int V_67 ;
struct V_41 * V_83 , V_147 ;
T_6 V_74 ;
T_12 V_148 ;
if ( ! V_12 -> V_149 )
return - V_23 ;
V_148 = V_102 -> V_148 ;
for ( V_67 = 0 ; V_67 < V_150 ; V_67 ++ ) {
V_83 = & V_12 -> V_41 [ V_67 + V_151 ] ;
if ( ! V_83 -> V_9 || ! V_83 -> V_69 )
continue;
if ( ! F_12 ( V_83 -> V_9 ) )
continue;
V_74 = F_68 ( V_12 , V_67 + V_151 ) ;
V_147 . V_9 = V_83 -> V_9 ;
V_147 . V_55 = V_83 -> V_55 + ( V_74 * V_146 ) ;
V_147 . V_57 = V_147 . V_55 + ( V_74 * V_148 ) - 1 ;
if ( V_147 . V_57 > V_83 -> V_57 ) {
F_59 ( & V_12 -> V_12 , L_31 ,
V_67 , & V_147 , V_83 , V_148 , V_146 ) ;
return - V_152 ;
}
}
for ( V_67 = 0 ; V_67 < V_150 ; V_67 ++ ) {
V_83 = & V_12 -> V_41 [ V_67 + V_151 ] ;
if ( ! V_83 -> V_9 || ! V_83 -> V_69 )
continue;
if ( ! F_12 ( V_83 -> V_9 ) )
continue;
V_74 = F_68 ( V_12 , V_67 + V_151 ) ;
V_147 = * V_83 ;
V_83 -> V_55 += V_74 * V_146 ;
F_69 ( & V_12 -> V_12 , L_32 ,
V_67 , & V_147 , V_83 , ( V_146 > 0 ) ? L_33 : L_34 ,
V_148 , V_146 ) ;
F_70 ( V_12 , V_67 + V_151 ) ;
}
return 0 ;
}
static void F_71 ( struct V_70 * V_19 , struct V_1 * V_2 )
{
struct V_60 * V_12 ;
F_31 (dev, &bus->devices, bus_list) {
struct V_101 * V_102 = F_53 ( V_12 ) ;
if ( V_102 == NULL ) {
F_14 ( L_35 ,
F_72 ( V_12 ) ) ;
continue;
}
V_102 -> V_21 = V_2 -> V_21 ;
V_2 -> V_136 += F_66 ( V_12 ) ;
if ( ( V_2 -> V_9 & V_14 ) && V_12 -> V_72 )
F_71 ( V_12 -> V_72 , V_2 ) ;
}
}
static void F_73 ( struct V_70 * V_19 , bool V_71 )
{
struct V_62 * V_35 = F_27 ( V_19 ) ;
struct V_29 * V_30 = V_35 -> V_63 ;
struct V_1 * V_2 ;
int V_153 = V_39 ;
if ( V_30 -> V_92 )
V_153 = V_30 -> V_92 ( V_19 , V_71 ) ;
if ( V_153 == V_39 )
V_153 = F_17 ( V_30 ) ;
if ( V_153 == V_39 ) {
F_74 ( L_36 ,
V_34 , F_4 ( V_19 ) , V_19 -> V_16 ) ;
return;
}
V_2 = & V_30 -> V_32 . V_38 [ V_153 ] ;
V_2 -> V_9 |= ( V_71 ? V_14 : V_13 ) ;
V_2 -> V_15 = V_19 ;
V_2 -> V_11 = NULL ;
V_2 -> V_154 = - 1 ;
V_2 -> V_132 = - 1 ;
V_2 -> V_20 = V_19 -> V_119 . V_55 << 8 ;
V_2 -> V_136 = 0 ;
if ( V_71 )
F_75 ( V_2 , L_37 ,
V_19 -> V_119 . V_55 , V_19 -> V_119 . V_57 , V_153 ) ;
else
F_75 ( V_2 , L_38 ,
V_19 -> V_119 . V_55 , V_153 ) ;
if ( F_62 ( V_30 , V_2 ) ) {
if ( V_153 )
F_19 ( V_30 , V_153 ) ;
V_2 -> V_15 = NULL ;
return;
}
F_71 ( V_19 , V_2 ) ;
F_39 ( & V_2 -> V_80 , & V_30 -> V_32 . V_155 ) ;
if ( V_2 -> V_136 != 0 ) {
V_30 -> V_32 . V_136 += V_2 -> V_136 ;
V_30 -> V_32 . V_156 ++ ;
}
F_65 ( V_30 , V_2 ) ;
}
static void F_76 ( struct V_70 * V_19 )
{
struct V_60 * V_12 ;
F_73 ( V_19 , false ) ;
F_31 (dev, &bus->devices, bus_list) {
if ( V_12 -> V_72 ) {
if ( F_77 ( V_12 ) == V_157 )
F_73 ( V_12 -> V_72 , true ) ;
else
F_76 ( V_12 -> V_72 ) ;
}
}
}
static void F_78 ( void )
{
struct V_62 * V_35 , * V_158 ;
struct V_29 * V_30 ;
F_79 (hose, tmp, &hose_list, list_node) {
V_30 = V_35 -> V_63 ;
if ( V_30 -> V_91 )
V_30 -> V_91 ( V_35 -> V_19 , NULL , true ) ;
F_76 ( V_35 -> V_19 ) ;
}
}
static int F_80 ( struct V_60 * V_11 )
{
struct V_70 * V_19 ;
struct V_62 * V_35 ;
struct V_29 * V_30 ;
struct V_101 * V_102 ;
int V_67 , V_159 ;
V_19 = V_11 -> V_19 ;
V_35 = F_27 ( V_19 ) ;
V_30 = V_35 -> V_63 ;
V_102 = F_53 ( V_11 ) ;
for ( V_67 = 0 ; V_67 < V_150 ; V_67 ++ )
for ( V_159 = 0 ; V_159 < V_160 ; V_159 ++ ) {
if ( V_102 -> V_161 [ V_67 ] [ V_159 ] == V_162 )
continue;
F_24 ( V_30 -> V_44 ,
V_45 , V_102 -> V_161 [ V_67 ] [ V_159 ] , 0 ) ;
F_21 ( V_102 -> V_161 [ V_67 ] [ V_159 ] , & V_30 -> V_32 . V_52 ) ;
V_102 -> V_161 [ V_67 ] [ V_159 ] = V_162 ;
}
return 0 ;
}
static int F_81 ( struct V_60 * V_11 , T_12 V_148 )
{
struct V_70 * V_19 ;
struct V_62 * V_35 ;
struct V_29 * V_30 ;
struct V_101 * V_102 ;
unsigned int V_163 ;
struct V_41 * V_83 ;
int V_67 , V_159 ;
T_11 V_43 ;
int V_164 ;
T_6 V_74 , V_55 ;
int V_153 ;
int V_165 ;
int V_166 ;
V_19 = V_11 -> V_19 ;
V_35 = F_27 ( V_19 ) ;
V_30 = V_35 -> V_63 ;
V_102 = F_53 ( V_11 ) ;
V_164 = F_82 ( V_11 ) ;
for ( V_67 = 0 ; V_67 < V_150 ; V_67 ++ )
for ( V_159 = 0 ; V_159 < V_160 ; V_159 ++ )
V_102 -> V_161 [ V_67 ] [ V_159 ] = V_162 ;
if ( V_102 -> V_167 == V_160 ) {
V_165 = ( V_148 <= V_160 ) ? V_148 : V_160 ;
V_166 = ( V_148 <= V_160 ) ? 1 :
F_83 ( V_148 ) / V_102 -> V_167 ;
} else {
V_165 = 1 ;
V_166 = 1 ;
}
for ( V_67 = 0 ; V_67 < V_150 ; V_67 ++ ) {
V_83 = & V_11 -> V_41 [ V_67 + V_151 ] ;
if ( ! V_83 -> V_9 || ! V_83 -> V_69 )
continue;
if ( ! F_12 ( V_83 -> V_9 ) )
continue;
for ( V_159 = 0 ; V_159 < V_165 ; V_159 ++ ) {
do {
V_163 = F_18 ( & V_30 -> V_32 . V_52 ,
V_30 -> V_32 . V_46 + 1 , 0 ) ;
if ( V_163 >= V_30 -> V_32 . V_46 + 1 )
goto V_168;
} while ( F_15 ( V_163 , & V_30 -> V_32 . V_52 ) );
V_102 -> V_161 [ V_67 ] [ V_159 ] = V_163 ;
if ( V_102 -> V_167 == V_160 ) {
V_74 = F_68 ( V_11 ,
V_151 + V_67 ) ;
V_74 = V_74 * V_166 ;
V_55 = V_83 -> V_55 + V_74 * V_159 ;
} else {
V_74 = F_45 ( V_83 ) ;
V_55 = V_83 -> V_55 ;
}
if ( V_102 -> V_167 == V_160 ) {
V_153 = V_102 -> V_146 + V_159 ;
V_43 = F_84 ( V_30 -> V_44 ,
V_153 , V_45 ,
V_102 -> V_161 [ V_67 ] [ V_159 ] , 0 ) ;
}
V_43 = F_23 ( V_30 -> V_44 ,
V_45 ,
V_102 -> V_161 [ V_67 ] [ V_159 ] ,
V_55 ,
0 ,
V_74 ) ;
if ( V_43 != V_49 ) {
F_59 ( & V_11 -> V_12 , L_39 ,
V_163 , V_43 ) ;
goto V_168;
}
if ( V_102 -> V_167 == V_160 )
V_43 = F_24 ( V_30 -> V_44 ,
V_45 , V_102 -> V_161 [ V_67 ] [ V_159 ] , 2 ) ;
else
V_43 = F_24 ( V_30 -> V_44 ,
V_45 , V_102 -> V_161 [ V_67 ] [ V_159 ] , 1 ) ;
if ( V_43 != V_49 ) {
F_59 ( & V_11 -> V_12 , L_40 ,
V_163 , V_43 ) ;
goto V_168;
}
}
}
return 0 ;
V_168:
F_80 ( V_11 ) ;
return - V_152 ;
}
static void F_85 ( struct V_60 * V_12 , struct V_1 * V_2 )
{
struct V_169 * V_170 ;
T_11 V_43 ;
V_170 = V_2 -> V_171 . V_172 [ 0 ] ;
V_43 = F_86 ( & V_2 -> V_171 , 0 ) ;
if ( V_43 )
F_56 ( V_2 , L_41 , V_43 ) ;
F_87 ( V_2 , false ) ;
if ( V_2 -> V_171 . V_173 ) {
F_88 ( V_2 -> V_171 . V_173 ) ;
F_89 ( V_2 -> V_171 . V_173 ) ;
}
F_90 ( V_170 ) ;
F_91 ( V_170 , F_92 ( V_12 -> V_12 . V_174 ) ) ;
}
static void F_93 ( struct V_60 * V_11 , T_12 V_148 )
{
struct V_70 * V_19 ;
struct V_62 * V_35 ;
struct V_29 * V_30 ;
struct V_1 * V_2 , * V_175 ;
struct V_101 * V_102 ;
T_12 V_176 ;
T_11 V_43 ;
V_19 = V_11 -> V_19 ;
V_35 = F_27 ( V_19 ) ;
V_30 = V_35 -> V_63 ;
V_102 = F_53 ( V_11 ) ;
if ( ! V_11 -> V_149 )
return;
if ( V_102 -> V_167 == V_160 && V_148 > V_160 ) {
int V_177 ;
int V_166 ;
int V_178 ;
V_166 = F_83 ( V_148 ) / V_102 -> V_167 ;
for ( V_177 = 0 ; V_177 < V_160 ; V_177 ++ )
for ( V_176 = V_177 * V_166 ;
V_176 < ( V_177 + 1 ) * V_166 &&
V_176 < V_148 ;
V_176 ++ )
for ( V_178 = V_177 * V_166 ;
V_178 < ( V_177 + 1 ) * V_166 &&
V_178 < V_148 ;
V_178 ++ ) {
V_43 = F_55 ( V_30 -> V_44 ,
V_102 -> V_146 + V_176 ,
V_102 -> V_146 + V_178 ,
V_107 ) ;
if ( V_43 )
F_94 ( & V_11 -> V_12 , L_42 ,
V_34 ,
V_102 -> V_146 + V_178 , V_43 ) ;
}
}
F_79 (pe, pe_n, &phb->ioda.pe_list, list) {
if ( V_2 -> V_18 != V_11 )
continue;
F_85 ( V_11 , V_2 ) ;
F_95 ( & V_30 -> V_32 . V_179 ) ;
F_96 ( & V_2 -> V_80 ) ;
F_97 ( & V_30 -> V_32 . V_179 ) ;
F_58 ( V_30 , V_2 ) ;
F_19 ( V_30 , V_2 -> V_21 ) ;
}
}
void F_98 ( struct V_60 * V_11 )
{
struct V_70 * V_19 ;
struct V_62 * V_35 ;
struct V_29 * V_30 ;
struct V_101 * V_102 ;
struct V_180 * V_181 ;
T_12 V_148 ;
V_19 = V_11 -> V_19 ;
V_35 = F_27 ( V_19 ) ;
V_30 = V_35 -> V_63 ;
V_102 = F_53 ( V_11 ) ;
V_181 = V_11 -> V_182 ;
V_148 = V_102 -> V_148 ;
F_93 ( V_11 , V_148 ) ;
if ( V_30 -> type == V_85 ) {
if ( V_102 -> V_167 == 1 )
F_67 ( V_11 , - V_102 -> V_146 ) ;
F_80 ( V_11 ) ;
F_99 ( V_30 -> V_32 . V_37 , V_102 -> V_146 , V_148 ) ;
V_102 -> V_146 = 0 ;
}
}
static void F_100 ( struct V_60 * V_11 , T_12 V_148 )
{
struct V_70 * V_19 ;
struct V_62 * V_35 ;
struct V_29 * V_30 ;
struct V_1 * V_2 ;
int V_153 ;
T_12 V_176 ;
struct V_101 * V_102 ;
T_11 V_43 ;
V_19 = V_11 -> V_19 ;
V_35 = F_27 ( V_19 ) ;
V_30 = V_35 -> V_63 ;
V_102 = F_53 ( V_11 ) ;
if ( ! V_11 -> V_149 )
return;
for ( V_176 = 0 ; V_176 < V_148 ; V_176 ++ ) {
V_153 = V_102 -> V_146 + V_176 ;
V_2 = & V_30 -> V_32 . V_38 [ V_153 ] ;
V_2 -> V_21 = V_153 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_9 = V_17 ;
V_2 -> V_15 = NULL ;
V_2 -> V_18 = V_11 ;
V_2 -> V_154 = - 1 ;
V_2 -> V_132 = - 1 ;
V_2 -> V_20 = ( F_101 ( V_11 , V_176 ) << 8 ) |
F_102 ( V_11 , V_176 ) ;
F_75 ( V_2 , L_43 ,
V_35 -> V_36 , V_11 -> V_19 -> V_16 ,
F_6 ( F_102 ( V_11 , V_176 ) ) ,
F_7 ( F_102 ( V_11 , V_176 ) ) , V_153 ) ;
if ( F_62 ( V_30 , V_2 ) ) {
if ( V_153 )
F_19 ( V_30 , V_153 ) ;
V_2 -> V_11 = NULL ;
continue;
}
F_95 ( & V_30 -> V_32 . V_179 ) ;
F_39 ( & V_2 -> V_80 , & V_30 -> V_32 . V_155 ) ;
F_97 ( & V_30 -> V_32 . V_179 ) ;
F_103 ( V_30 , V_2 ) ;
}
if ( V_102 -> V_167 == V_160 && V_148 > V_160 ) {
int V_177 ;
int V_166 ;
int V_178 ;
V_166 = F_83 ( V_148 ) / V_102 -> V_167 ;
for ( V_177 = 0 ; V_177 < V_160 ; V_177 ++ ) {
for ( V_176 = V_177 * V_166 ;
V_176 < ( V_177 + 1 ) * V_166 &&
V_176 < V_148 ;
V_176 ++ ) {
for ( V_178 = V_177 * V_166 ;
V_178 < ( V_177 + 1 ) * V_166 &&
V_178 < V_148 ;
V_178 ++ ) {
V_43 = F_55 ( V_30 -> V_44 ,
V_102 -> V_146 + V_176 ,
V_102 -> V_146 + V_178 ,
V_106 ) ;
if ( V_43 )
F_94 ( & V_11 -> V_12 , L_44 ,
V_34 ,
V_102 -> V_146 + V_178 , V_43 ) ;
}
}
}
}
}
int F_104 ( struct V_60 * V_11 , T_12 V_148 )
{
struct V_70 * V_19 ;
struct V_62 * V_35 ;
struct V_29 * V_30 ;
struct V_101 * V_102 ;
int V_109 ;
V_19 = V_11 -> V_19 ;
V_35 = F_27 ( V_19 ) ;
V_30 = V_35 -> V_63 ;
V_102 = F_53 ( V_11 ) ;
if ( V_30 -> type == V_85 ) {
F_95 ( & V_30 -> V_32 . V_183 ) ;
V_102 -> V_146 = F_105 (
V_30 -> V_32 . V_37 , V_30 -> V_32 . V_33 ,
0 , V_148 , 0 ) ;
if ( V_102 -> V_146 >= V_30 -> V_32 . V_33 ) {
F_97 ( & V_30 -> V_32 . V_183 ) ;
F_69 ( & V_11 -> V_12 , L_45 , V_148 ) ;
V_102 -> V_146 = 0 ;
return - V_152 ;
}
F_106 ( V_30 -> V_32 . V_37 , V_102 -> V_146 , V_148 ) ;
V_102 -> V_148 = V_148 ;
F_97 ( & V_30 -> V_32 . V_183 ) ;
V_109 = F_81 ( V_11 , V_148 ) ;
if ( V_109 ) {
F_69 ( & V_11 -> V_12 , L_46 ) ;
goto V_168;
}
if ( V_102 -> V_167 == 1 ) {
V_109 = F_67 ( V_11 , V_102 -> V_146 ) ;
if ( V_109 )
goto V_168;
}
}
F_100 ( V_11 , V_148 ) ;
return 0 ;
V_168:
F_99 ( V_30 -> V_32 . V_37 , V_102 -> V_146 , V_148 ) ;
V_102 -> V_146 = 0 ;
return V_109 ;
}
int F_107 ( struct V_60 * V_11 )
{
F_98 ( V_11 ) ;
F_108 ( V_11 ) ;
return 0 ;
}
int F_109 ( struct V_60 * V_11 , T_12 V_148 )
{
F_110 ( V_11 ) ;
F_104 ( V_11 , V_148 ) ;
return 0 ;
}
static void F_111 ( struct V_29 * V_30 , struct V_60 * V_11 )
{
struct V_101 * V_102 = F_53 ( V_11 ) ;
struct V_1 * V_2 ;
if ( ! V_102 || V_102 -> V_21 == V_39 )
return;
V_2 = & V_30 -> V_32 . V_38 [ V_102 -> V_21 ] ;
F_20 ( F_112 ( & V_11 -> V_12 ) != & V_184 ) ;
F_113 ( & V_11 -> V_12 , V_2 -> V_185 ) ;
F_114 ( & V_11 -> V_12 , V_2 -> V_171 . V_172 [ 0 ] ) ;
}
static int F_115 ( struct V_60 * V_11 , T_3 V_186 )
{
struct V_62 * V_35 = F_27 ( V_11 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_63 ;
struct V_101 * V_102 = F_53 ( V_11 ) ;
struct V_1 * V_2 ;
T_13 V_187 ;
bool V_188 = false ;
if ( F_20 ( ! V_102 || V_102 -> V_21 == V_39 ) )
return - V_189 ; ;
V_2 = & V_30 -> V_32 . V_38 [ V_102 -> V_21 ] ;
if ( V_2 -> V_190 ) {
V_187 = V_2 -> V_185 + F_116 () - 1 ;
V_188 = ( V_186 >= V_187 ) ;
}
if ( V_188 ) {
F_69 ( & V_11 -> V_12 , L_47 ) ;
F_117 ( & V_11 -> V_12 , & V_191 ) ;
} else {
F_69 ( & V_11 -> V_12 , L_48 ) ;
F_117 ( & V_11 -> V_12 , & V_184 ) ;
}
* V_11 -> V_12 . V_186 = V_186 ;
return 0 ;
}
static T_3 F_118 ( struct V_60 * V_11 )
{
struct V_62 * V_35 = F_27 ( V_11 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_63 ;
struct V_101 * V_102 = F_53 ( V_11 ) ;
struct V_1 * V_2 ;
T_3 V_57 , V_192 ;
if ( F_20 ( ! V_102 || V_102 -> V_21 == V_39 ) )
return 0 ;
V_2 = & V_30 -> V_32 . V_38 [ V_102 -> V_21 ] ;
if ( ! V_2 -> V_190 )
return F_119 ( & V_11 -> V_12 ) ;
V_57 = V_2 -> V_185 + F_116 () ;
V_192 = 1ULL << ( F_120 ( V_57 ) - 1 ) ;
V_192 += V_192 - 1 ;
return V_192 ;
}
static void F_121 ( struct V_1 * V_2 ,
struct V_70 * V_19 )
{
struct V_60 * V_12 ;
F_31 (dev, &bus->devices, bus_list) {
F_114 ( & V_12 -> V_12 , V_2 -> V_171 . V_172 [ 0 ] ) ;
F_113 ( & V_12 -> V_12 , V_2 -> V_185 ) ;
F_122 ( & V_12 -> V_12 ) ;
if ( ( V_2 -> V_9 & V_14 ) && V_12 -> V_72 )
F_121 ( V_2 , V_12 -> V_72 ) ;
}
}
static void F_123 ( struct V_169 * V_170 ,
unsigned long V_193 , unsigned long V_194 , bool V_195 )
{
struct V_196 * V_197 = F_124 (
& V_170 -> V_198 , struct V_196 ,
V_199 ) ;
struct V_1 * V_2 = F_125 ( V_197 -> V_171 ,
struct V_1 , V_171 ) ;
T_14 T_4 * V_200 = V_195 ?
( T_14 T_4 * ) V_2 -> V_30 -> V_32 . V_201 :
V_2 -> V_30 -> V_32 . V_202 ;
unsigned long V_55 , V_57 , V_203 ;
const unsigned V_204 = V_170 -> V_205 ;
V_55 = F_126 ( ( ( T_14 * ) V_170 -> V_206 ) + V_193 - V_170 -> V_207 ) ;
V_57 = F_126 ( ( ( T_14 * ) V_170 -> V_206 ) + V_193 - V_170 -> V_207 +
V_194 - 1 ) ;
if ( V_170 -> V_208 ) {
V_55 <<= V_204 ;
V_57 <<= V_204 ;
V_203 = 128ull << V_204 ;
V_55 |= V_170 -> V_208 ;
V_57 |= V_170 -> V_208 ;
} else if ( V_170 -> V_209 & V_210 ) {
V_55 |= ( 1ull << 63 ) ;
V_57 |= ( 1ull << 63 ) ;
V_203 = 16 ;
} else {
V_203 = 128 ;
}
V_57 |= V_203 - 1 ;
F_127 () ;
while ( V_55 <= V_57 ) {
if ( V_195 )
F_11 ( F_128 ( V_55 ) , V_200 ) ;
else
F_129 ( F_128 ( V_55 ) , V_200 ) ;
V_55 += V_203 ;
}
}
static int F_130 ( struct V_169 * V_170 , long V_193 ,
long V_194 , unsigned long V_211 ,
enum V_212 V_213 ,
struct V_214 * V_215 )
{
int V_109 = F_131 ( V_170 , V_193 , V_194 , V_211 , V_213 ,
V_215 ) ;
if ( ! V_109 && ( V_170 -> V_209 & V_216 ) )
F_123 ( V_170 , V_193 , V_194 , false ) ;
return V_109 ;
}
static int F_132 ( struct V_169 * V_170 , long V_193 ,
unsigned long * V_217 , enum V_212 * V_213 )
{
long V_109 = F_133 ( V_170 , V_193 , V_217 , V_213 ) ;
if ( ! V_109 && ( V_170 -> V_209 &
( V_216 | V_218 ) ) )
F_123 ( V_170 , V_193 , 1 , false ) ;
return V_109 ;
}
static void F_134 ( struct V_169 * V_170 , long V_193 ,
long V_194 )
{
F_135 ( V_170 , V_193 , V_194 ) ;
if ( V_170 -> V_209 & V_218 )
F_123 ( V_170 , V_193 , V_194 , false ) ;
}
static inline void F_136 ( struct V_1 * V_2 )
{
unsigned long V_25 = ( 0x4ull << 60 ) | ( V_2 -> V_21 & 0xFF ) ;
struct V_29 * V_30 = V_2 -> V_30 ;
if ( ! V_30 -> V_32 . V_202 )
return;
F_127 () ;
F_129 ( F_128 ( V_25 ) , V_30 -> V_32 . V_202 ) ;
}
static void F_137 ( unsigned V_21 , bool V_195 ,
T_14 T_4 * V_200 , unsigned V_204 ,
unsigned long V_193 , unsigned long V_194 )
{
unsigned long V_55 , V_57 , V_203 ;
V_55 = 0x2ull << 60 ;
V_55 |= ( V_21 & 0xFF ) ;
V_57 = V_55 ;
V_55 |= ( V_193 << V_204 ) ;
V_57 |= ( ( V_193 + V_194 - 1 ) << V_204 ) ;
V_203 = ( 0x1ull << V_204 ) ;
F_127 () ;
while ( V_55 <= V_57 ) {
if ( V_195 )
F_11 ( F_128 ( V_55 ) , V_200 ) ;
else
F_129 ( F_128 ( V_55 ) , V_200 ) ;
V_55 += V_203 ;
}
}
static void F_138 ( struct V_169 * V_170 ,
unsigned long V_193 , unsigned long V_194 , bool V_195 )
{
struct V_196 * V_197 ;
F_139 (tgl, &tbl->it_group_list, next) {
struct V_1 * V_2 = F_125 ( V_197 -> V_171 ,
struct V_1 , V_171 ) ;
T_14 T_4 * V_200 = V_195 ?
( T_14 T_4 * ) V_2 -> V_30 -> V_32 . V_201 :
V_2 -> V_30 -> V_32 . V_202 ;
F_137 ( V_2 -> V_21 , V_195 ,
V_200 , V_170 -> V_205 ,
V_193 , V_194 ) ;
}
}
static int F_140 ( struct V_169 * V_170 , long V_193 ,
long V_194 , unsigned long V_211 ,
enum V_212 V_213 ,
struct V_214 * V_215 )
{
int V_109 = F_131 ( V_170 , V_193 , V_194 , V_211 , V_213 ,
V_215 ) ;
if ( ! V_109 && ( V_170 -> V_209 & V_216 ) )
F_138 ( V_170 , V_193 , V_194 , false ) ;
return V_109 ;
}
static int F_141 ( struct V_169 * V_170 , long V_193 ,
unsigned long * V_217 , enum V_212 * V_213 )
{
long V_109 = F_133 ( V_170 , V_193 , V_217 , V_213 ) ;
if ( ! V_109 && ( V_170 -> V_209 &
( V_216 | V_218 ) ) )
F_138 ( V_170 , V_193 , 1 , false ) ;
return V_109 ;
}
static void F_142 ( struct V_169 * V_170 , long V_193 ,
long V_194 )
{
F_135 ( V_170 , V_193 , V_194 ) ;
if ( V_170 -> V_209 & V_218 )
F_138 ( V_170 , V_193 , V_194 , false ) ;
}
static void F_143 ( struct V_169 * V_170 )
{
F_90 ( V_170 ) ;
F_91 ( V_170 , L_49 ) ;
}
static void F_144 ( struct V_29 * V_30 ,
struct V_1 * V_2 , unsigned int V_64 ,
unsigned int V_219 )
{
struct V_220 * V_221 = NULL ;
struct V_169 * V_170 ;
unsigned int V_67 ;
T_11 V_43 ;
void * V_222 ;
if ( F_20 ( V_2 -> V_154 >= 0 ) )
return;
V_170 = F_145 ( V_30 -> V_35 -> V_223 ) ;
F_146 ( & V_2 -> V_171 , V_30 -> V_35 -> V_36 ,
V_2 -> V_21 ) ;
F_147 ( V_30 -> V_35 -> V_223 , 0 , V_170 , & V_2 -> V_171 ) ;
V_2 -> V_154 = V_64 ;
F_75 ( V_2 , L_50 ,
( V_64 << 28 ) , ( ( V_64 + V_219 ) << 28 ) - 1 ) ;
V_221 = F_148 ( V_30 -> V_35 -> V_223 , V_75 ,
F_149 ( V_224 * V_219 ) ) ;
if ( ! V_221 ) {
F_61 ( V_2 , L_51 ) ;
goto V_50;
}
V_222 = F_150 ( V_221 ) ;
memset ( V_222 , 0 , V_224 * V_219 ) ;
for ( V_67 = 0 ; V_67 < V_219 ; V_67 ++ ) {
V_43 = F_151 ( V_30 -> V_44 ,
V_2 -> V_21 ,
V_64 + V_67 , 1 ,
F_126 ( V_222 ) + V_224 * V_67 ,
V_224 , 0x1000 ) ;
if ( V_43 ) {
F_61 ( V_2 , L_52
L_53 , V_43 ) ;
goto V_50;
}
}
F_152 ( V_170 , V_222 , V_224 * V_219 ,
V_64 << 28 , V_225 ) ;
if ( V_30 -> V_32 . V_202 )
V_170 -> V_209 |= ( V_216 |
V_218 |
V_210 ) ;
V_170 -> V_226 = & V_227 ;
V_2 -> V_171 . V_228 = V_170 -> V_207 << V_170 -> V_205 ;
V_2 -> V_171 . V_229 = V_170 -> V_230 << V_170 -> V_205 ;
F_153 ( V_170 , V_30 -> V_35 -> V_223 ) ;
if ( V_2 -> V_9 & V_10 ) {
F_114 ( & V_2 -> V_11 -> V_12 , V_170 ) ;
F_122 ( & V_2 -> V_11 -> V_12 ) ;
} else if ( V_2 -> V_9 & ( V_13 | V_14 ) )
F_121 ( V_2 , V_2 -> V_15 ) ;
return;
V_50:
if ( V_2 -> V_154 >= 0 )
V_2 -> V_154 = - 1 ;
if ( V_221 )
F_154 ( V_221 , F_149 ( V_224 * V_219 ) ) ;
if ( V_170 ) {
F_155 ( V_170 , & V_2 -> V_171 ) ;
F_91 ( V_170 , L_49 ) ;
}
}
static long F_156 ( struct V_231 * V_171 ,
int V_232 , struct V_169 * V_170 )
{
struct V_1 * V_2 = F_125 ( V_171 , struct V_1 ,
V_171 ) ;
struct V_29 * V_30 = V_2 -> V_30 ;
T_11 V_43 ;
const unsigned long V_74 = V_170 -> V_233 ?
V_170 -> V_234 : V_170 -> V_230 ;
const T_15 V_235 = V_170 -> V_207 << V_170 -> V_205 ;
const T_15 V_236 = V_170 -> V_230 << V_170 -> V_205 ;
F_75 ( V_2 , L_54 , V_232 ,
V_235 , V_235 + V_236 - 1 ,
F_157 ( V_170 ) ) ;
V_43 = F_151 ( V_30 -> V_44 ,
V_2 -> V_21 ,
( V_2 -> V_21 << 1 ) + V_232 ,
V_170 -> V_233 + 1 ,
F_126 ( V_170 -> V_206 ) ,
V_74 << 3 ,
F_157 ( V_170 ) ) ;
if ( V_43 ) {
F_61 ( V_2 , L_55 , V_43 ) ;
return V_43 ;
}
F_147 ( V_30 -> V_35 -> V_223 , V_232 ,
V_170 , & V_2 -> V_171 ) ;
F_136 ( V_2 ) ;
return 0 ;
}
static void F_87 ( struct V_1 * V_2 , bool V_237 )
{
T_16 V_238 = ( V_2 -> V_21 << 1 ) + 1 ;
T_11 V_43 ;
F_75 ( V_2 , L_56 , V_237 ? L_33 : L_34 ) ;
if ( V_237 ) {
T_17 V_187 = F_116 () ;
V_187 = F_83 ( V_187 ) ;
V_43 = F_158 ( V_2 -> V_30 -> V_44 ,
V_2 -> V_21 ,
V_238 ,
V_2 -> V_185 ,
V_187 ) ;
} else {
V_43 = F_158 ( V_2 -> V_30 -> V_44 ,
V_2 -> V_21 ,
V_238 ,
V_2 -> V_185 ,
0 ) ;
}
if ( V_43 )
F_61 ( V_2 , L_57 , V_43 ) ;
else
V_2 -> V_190 = V_237 ;
}
static long F_159 ( struct V_231 * V_171 ,
int V_232 , T_18 V_239 , T_15 V_240 , T_18 V_241 ,
struct V_169 * * V_242 )
{
struct V_1 * V_2 = F_125 ( V_171 , struct V_1 ,
V_171 ) ;
int V_243 = V_2 -> V_30 -> V_35 -> V_223 ;
T_15 V_244 = V_232 ? V_2 -> V_185 : V_171 -> V_228 ;
long V_109 ;
struct V_169 * V_170 ;
V_170 = F_145 ( V_243 ) ;
if ( ! V_170 )
return - V_245 ;
V_109 = F_160 ( V_243 ,
V_244 , V_239 , V_240 ,
V_241 , V_170 ) ;
if ( V_109 ) {
F_91 ( V_170 , L_49 ) ;
return V_109 ;
}
V_170 -> V_226 = & V_246 ;
if ( V_2 -> V_30 -> V_32 . V_202 )
V_170 -> V_209 |= ( V_216 | V_218 ) ;
* V_242 = V_170 ;
return 0 ;
}
static long F_161 ( struct V_1 * V_2 )
{
struct V_169 * V_170 = NULL ;
long V_43 ;
const T_3 V_247 = F_162 ( F_163 () ) ;
const T_3 V_240 = F_164 ( ( T_3 ) V_2 -> V_171 . V_229 , V_247 ) ;
V_43 = F_159 ( & V_2 -> V_171 , 0 ,
V_225 ,
V_240 ,
V_248 , & V_170 ) ;
if ( V_43 ) {
F_61 ( V_2 , L_58 ,
V_43 ) ;
return V_43 ;
}
F_153 ( V_170 , V_2 -> V_30 -> V_35 -> V_223 ) ;
V_43 = F_156 ( & V_2 -> V_171 , 0 , V_170 ) ;
if ( V_43 ) {
F_61 ( V_2 , L_59 ,
V_43 ) ;
F_143 ( V_170 ) ;
return V_43 ;
}
if ( ! V_24 )
F_87 ( V_2 , true ) ;
if ( V_2 -> V_30 -> V_32 . V_202 )
V_170 -> V_209 |= ( V_216 | V_218 ) ;
if ( V_2 -> V_9 & V_10 )
F_114 ( & V_2 -> V_11 -> V_12 , V_170 ) ;
return 0 ;
}
static long F_86 ( struct V_231 * V_171 ,
int V_232 )
{
struct V_1 * V_2 = F_125 ( V_171 , struct V_1 ,
V_171 ) ;
struct V_29 * V_30 = V_2 -> V_30 ;
long V_109 ;
F_75 ( V_2 , L_60 , V_232 ) ;
V_109 = F_151 ( V_30 -> V_44 , V_2 -> V_21 ,
( V_2 -> V_21 << 1 ) + V_232 ,
0 , 0 ,
0 , 0 ) ;
if ( V_109 )
F_56 ( V_2 , L_61 , V_109 ) ;
else
F_136 ( V_2 ) ;
F_155 ( V_171 -> V_172 [ V_232 ] , V_171 ) ;
return V_109 ;
}
static unsigned long F_165 ( T_18 V_239 ,
T_15 V_240 , T_18 V_241 )
{
unsigned long V_249 = 0 ;
const unsigned V_250 = F_166 ( V_240 ) ;
unsigned V_251 = V_250 - V_239 ;
unsigned V_252 = V_251 + 3 ;
unsigned long V_253 = F_167 ( 0x1000UL , 1UL << V_252 ) ;
unsigned long V_254 ;
if ( ! V_241 || ( V_241 > V_255 ) ||
( V_240 > F_163 () ) ||
! F_168 ( V_240 ) )
return 0 ;
V_251 = ( V_251 + V_241 - 1 ) / V_241 ;
V_252 = V_251 + 3 ;
V_252 = F_169 ( unsigned , V_252 , V_256 ) ;
V_254 = 1UL << V_252 ;
for ( ; V_241 ; -- V_241 ) {
V_249 += F_29 ( V_253 , V_254 ) ;
V_253 /= V_254 ;
V_253 <<= 3 ;
V_253 = F_29 ( V_253 , V_254 ) ;
}
return V_249 ;
}
static void F_170 ( struct V_231 * V_171 )
{
struct V_1 * V_2 = F_125 ( V_171 , struct V_1 ,
V_171 ) ;
struct V_169 * V_170 = V_2 -> V_171 . V_172 [ 0 ] ;
F_87 ( V_2 , false ) ;
F_86 ( & V_2 -> V_171 , 0 ) ;
F_143 ( V_170 ) ;
}
static void F_171 ( struct V_231 * V_171 )
{
struct V_1 * V_2 = F_125 ( V_171 , struct V_1 ,
V_171 ) ;
F_161 ( V_2 ) ;
}
static void F_172 ( struct V_29 * V_30 )
{
const T_14 * V_257 ;
V_257 = F_42 ( V_30 -> V_35 -> V_82 , L_62 , NULL ) ;
if ( ! V_257 )
return;
V_30 -> V_32 . V_201 = F_173 ( V_257 ) ;
V_30 -> V_32 . V_202 = F_174 ( V_30 -> V_32 . V_201 , 8 ) ;
}
static T_14 * F_175 ( int V_243 , unsigned V_204 ,
unsigned V_241 , unsigned long V_258 ,
unsigned long * V_259 , unsigned long * V_260 )
{
struct V_220 * V_221 = NULL ;
T_14 * V_222 , * V_158 ;
unsigned V_261 = F_169 ( unsigned , V_204 , V_256 ) - V_256 ;
unsigned long V_262 = 1UL << ( V_261 + V_256 ) ;
unsigned V_263 = 1UL << ( V_204 - 3 ) ;
long V_67 ;
V_221 = F_148 ( V_243 , V_75 , V_261 ) ;
if ( ! V_221 ) {
F_176 ( L_63 , V_261 ) ;
return NULL ;
}
V_222 = F_150 ( V_221 ) ;
memset ( V_222 , 0 , V_262 ) ;
* V_260 += V_262 ;
-- V_241 ;
if ( ! V_241 ) {
* V_259 += V_262 ;
return V_222 ;
}
for ( V_67 = 0 ; V_67 < V_263 ; ++ V_67 ) {
V_158 = F_175 ( V_243 , V_204 ,
V_241 , V_258 , V_259 , V_260 ) ;
if ( ! V_158 )
break;
V_222 [ V_67 ] = F_128 ( F_126 ( V_158 ) |
V_264 | V_265 ) ;
if ( * V_259 >= V_258 )
break;
}
return V_222 ;
}
static long F_160 ( int V_243 , T_15 V_244 ,
T_18 V_239 , T_15 V_240 , T_18 V_241 ,
struct V_169 * V_170 )
{
void * V_222 ;
unsigned long V_146 = 0 , V_266 , V_260 = 0 ;
const unsigned V_250 = F_166 ( V_240 ) ;
unsigned V_251 = V_250 - V_239 ;
unsigned V_252 = F_169 ( unsigned , V_251 + 3 , V_256 ) ;
const unsigned long V_253 = 1UL << V_252 ;
if ( ! V_241 || ( V_241 > V_255 ) )
return - V_23 ;
if ( ( V_240 > F_163 () ) || ! F_168 ( V_240 ) )
return - V_23 ;
V_251 = ( V_251 + V_241 - 1 ) / V_241 ;
V_266 = V_251 + 3 ;
V_266 = F_169 ( unsigned , V_266 , V_256 ) ;
V_222 = F_175 ( V_243 , V_266 ,
V_241 , V_253 , & V_146 , & V_260 ) ;
if ( ! V_222 )
return - V_245 ;
if ( V_146 < V_253 ) {
F_177 ( V_222 ,
1ULL << ( V_266 - 3 ) , V_241 - 1 ) ;
return - V_245 ;
}
F_152 ( V_170 , V_222 , V_253 , V_244 ,
V_239 ) ;
V_170 -> V_234 = 1ULL << ( V_266 - 3 ) ;
V_170 -> V_233 = V_241 - 1 ;
V_170 -> V_267 = V_260 ;
F_178 ( L_64 ,
V_240 , V_253 , V_244 ) ;
return 0 ;
}
static void F_177 ( T_14 * V_222 ,
unsigned long V_74 , unsigned V_3 )
{
const unsigned long V_268 = ( unsigned long ) V_222 &
~ ( V_264 | V_265 ) ;
if ( V_3 ) {
long V_67 ;
T_3 * V_158 = ( T_3 * ) V_268 ;
for ( V_67 = 0 ; V_67 < V_74 ; ++ V_67 ) {
unsigned long V_217 = F_179 ( V_158 [ V_67 ] ) ;
if ( ! ( V_217 & ( V_264 | V_265 ) ) )
continue;
F_177 ( F_180 ( V_217 ) , V_74 ,
V_3 - 1 ) ;
}
}
F_181 ( V_268 , F_149 ( V_74 << 3 ) ) ;
}
static void F_90 ( struct V_169 * V_170 )
{
const unsigned long V_74 = V_170 -> V_233 ?
V_170 -> V_234 : V_170 -> V_230 ;
if ( ! V_170 -> V_230 )
return;
F_177 ( ( T_14 * ) V_170 -> V_206 , V_74 ,
V_170 -> V_233 ) ;
}
static void F_103 ( struct V_29 * V_30 ,
struct V_1 * V_2 )
{
T_11 V_43 ;
if ( F_20 ( V_2 -> V_154 >= 0 ) )
return;
V_2 -> V_185 = 1ull << 59 ;
F_146 ( & V_2 -> V_171 , V_30 -> V_35 -> V_36 ,
V_2 -> V_21 ) ;
V_2 -> V_154 = 0 ;
F_75 ( V_2 , L_65 ,
V_30 -> V_32 . V_269 ) ;
V_2 -> V_171 . V_228 = 0 ;
V_2 -> V_171 . V_229 = V_30 -> V_32 . V_269 ;
V_2 -> V_171 . V_270 =
V_271 ;
V_2 -> V_171 . V_272 = V_255 ;
V_2 -> V_171 . V_273 = V_274 | V_275 | V_276 ;
#ifdef F_182
V_2 -> V_171 . V_277 = & V_278 ;
#endif
V_43 = F_161 ( V_2 ) ;
if ( V_43 ) {
if ( V_2 -> V_154 >= 0 )
V_2 -> V_154 = - 1 ;
return;
}
if ( V_2 -> V_9 & V_10 )
F_122 ( & V_2 -> V_11 -> V_12 ) ;
else if ( V_2 -> V_9 & ( V_13 | V_14 ) )
F_121 ( V_2 , V_2 -> V_15 ) ;
}
static void F_183 ( struct V_29 * V_30 )
{
struct V_62 * V_35 = V_30 -> V_35 ;
unsigned int V_279 , V_280 , V_219 , V_281 , V_64 ;
struct V_1 * V_2 ;
if ( V_30 -> V_32 . V_156 > V_30 -> V_32 . V_282 )
V_279 = 0 ;
else
V_279 = V_30 -> V_32 . V_282 -
V_30 -> V_32 . V_156 ;
F_10 ( L_66 ,
V_35 -> V_36 , V_30 -> V_32 . V_282 ) ;
F_10 ( L_67 ,
V_30 -> V_32 . V_156 , V_30 -> V_32 . V_136 ) ;
F_172 ( V_30 ) ;
V_280 = V_30 -> V_32 . V_282 ;
V_281 = V_30 -> V_32 . V_136 ;
V_64 = 0 ;
F_31 (pe, &phb->ioda.pe_dma_list, dma_link) {
if ( ! V_2 -> V_136 )
continue;
if ( ! V_280 ) {
F_56 ( V_2 , L_68 ) ;
continue;
}
V_219 = 1 ;
if ( V_279 ) {
V_219 += ( ( V_2 -> V_136 * V_279 ) + ( V_281 / 2 ) ) / V_281 ;
if ( V_219 > V_280 )
V_219 = V_280 ;
}
if ( V_30 -> type == V_131 ) {
F_75 ( V_2 , L_69 ,
V_2 -> V_136 , V_219 ) ;
F_144 ( V_30 , V_2 , V_64 , V_219 ) ;
} else {
F_75 ( V_2 , L_70 ) ;
V_219 = 0 ;
F_103 ( V_30 , V_2 ) ;
}
V_280 -= V_219 ;
V_64 += V_219 ;
}
}
static void F_184 ( struct V_283 * V_284 )
{
unsigned int V_285 = ( unsigned int ) F_185 ( V_284 ) ;
struct V_286 * V_287 = F_186 ( V_284 ) ;
struct V_29 * V_30 = F_125 ( V_287 , struct V_29 ,
V_32 . V_286 ) ;
T_11 V_43 ;
V_43 = F_187 ( V_30 -> V_44 , V_285 ) ;
F_188 ( V_43 ) ;
F_189 ( V_284 ) ;
}
static void F_190 ( struct V_29 * V_30 , unsigned int V_288 )
{
struct V_283 * V_289 ;
struct V_286 * V_290 ;
if ( V_30 -> type != V_85 )
return;
if ( ! V_30 -> V_32 . V_291 ) {
V_289 = F_191 ( V_288 ) ;
V_290 = F_186 ( V_289 ) ;
V_30 -> V_32 . V_291 = 1 ;
V_30 -> V_32 . V_286 = * V_290 ;
V_30 -> V_32 . V_286 . V_292 = F_184 ;
}
F_192 ( V_288 , & V_30 -> V_32 . V_286 ) ;
}
struct V_81 * F_193 ( struct V_60 * V_12 )
{
struct V_62 * V_35 = F_27 ( V_12 -> V_19 ) ;
return F_194 ( V_35 -> V_82 ) ;
}
int F_195 ( struct V_60 * V_12 , T_13 V_293 )
{
struct V_62 * V_35 = F_27 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_63 ;
struct V_1 * V_2 ;
int V_43 ;
V_2 = F_52 ( V_12 ) ;
if ( ! V_2 )
return - V_189 ;
F_75 ( V_2 , L_71 ) ;
V_43 = F_196 ( V_30 -> V_44 , V_293 , V_2 -> V_21 ) ;
if ( V_43 )
F_59 ( & V_12 -> V_12 , L_72 , V_43 ) ;
return V_43 ;
}
int F_197 ( struct V_60 * V_12 , int V_232 )
{
struct V_62 * V_35 = F_27 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_63 ;
int V_294 = F_198 ( & V_30 -> V_295 , V_232 ) ;
if ( V_294 < 0 ) {
F_94 ( & V_12 -> V_12 , L_73 ) ;
return - V_296 ;
}
return V_30 -> V_297 + V_294 ;
}
void F_199 ( struct V_60 * V_12 , int V_294 , int V_232 )
{
struct V_62 * V_35 = F_27 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_63 ;
F_200 ( & V_30 -> V_295 , V_294 - V_30 -> V_297 , V_232 ) ;
}
void F_201 ( struct V_298 * V_299 ,
struct V_60 * V_12 )
{
struct V_62 * V_35 = F_27 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_63 ;
int V_67 , V_294 ;
for ( V_67 = 1 ; V_67 < V_300 ; V_67 ++ ) {
if ( ! V_299 -> V_301 [ V_67 ] )
continue;
F_178 ( L_74 ,
V_67 , V_299 -> V_146 [ V_67 ] ,
V_299 -> V_301 [ V_67 ] ) ;
V_294 = V_299 -> V_146 [ V_67 ] - V_30 -> V_297 ;
F_200 ( & V_30 -> V_295 , V_294 ,
V_299 -> V_301 [ V_67 ] ) ;
}
}
int F_202 ( struct V_298 * V_299 ,
struct V_60 * V_12 , int V_232 )
{
struct V_62 * V_35 = F_27 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_63 ;
int V_67 , V_294 , V_302 ;
memset ( V_299 , 0 , sizeof( struct V_298 ) ) ;
for ( V_67 = 1 ; V_67 < V_300 && V_232 ; V_67 ++ ) {
V_302 = V_232 ;
while ( V_302 ) {
V_294 = F_198 ( & V_30 -> V_295 , V_302 ) ;
if ( V_294 >= 0 )
break;
V_302 /= 2 ;
}
if ( ! V_302 )
goto V_50;
V_299 -> V_146 [ V_67 ] = V_30 -> V_297 + V_294 ;
V_299 -> V_301 [ V_67 ] = V_302 ;
F_178 ( L_75 ,
V_67 , V_299 -> V_146 [ V_67 ] , V_299 -> V_301 [ V_67 ] ) ;
V_232 -= V_302 ;
}
if ( V_232 )
goto V_50;
return 0 ;
V_50:
F_201 ( V_299 , V_12 ) ;
return - V_296 ;
}
int F_203 ( struct V_60 * V_12 )
{
struct V_62 * V_35 = F_27 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_63 ;
return V_30 -> V_295 . V_303 ;
}
int F_204 ( struct V_60 * V_12 , unsigned int V_294 ,
unsigned int V_288 )
{
struct V_62 * V_35 = F_27 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_63 ;
unsigned int V_304 = V_294 - V_30 -> V_297 ;
struct V_1 * V_2 ;
int V_43 ;
if ( ! ( V_2 = F_52 ( V_12 ) ) )
return - V_189 ;
V_43 = F_205 ( V_30 -> V_44 , V_2 -> V_21 , V_304 ) ;
if ( V_43 ) {
F_56 ( V_2 , L_76
L_77 ,
F_72 ( V_12 ) , V_43 , V_30 -> V_297 , V_294 , V_304 ) ;
return - V_59 ;
}
F_190 ( V_30 , V_288 ) ;
return 0 ;
}
static int F_206 ( struct V_29 * V_30 , struct V_60 * V_12 ,
unsigned int V_294 , unsigned int V_288 ,
unsigned int V_305 , struct V_306 * V_307 )
{
struct V_1 * V_2 = F_52 ( V_12 ) ;
unsigned int V_304 = V_294 - V_30 -> V_297 ;
T_19 V_308 ;
int V_43 ;
if ( V_2 == NULL )
return - V_108 ;
if ( V_2 -> V_132 < 0 )
return - V_108 ;
if ( V_12 -> V_309 )
V_305 = 0 ;
V_43 = F_205 ( V_30 -> V_44 , V_2 -> V_21 , V_304 ) ;
if ( V_43 ) {
F_14 ( L_78 ,
F_72 ( V_12 ) , V_43 , V_304 ) ;
return - V_59 ;
}
if ( V_305 ) {
T_14 V_310 ;
V_43 = F_207 ( V_30 -> V_44 , V_2 -> V_132 , V_304 , 1 ,
& V_310 , & V_308 ) ;
if ( V_43 ) {
F_14 ( L_79 ,
F_72 ( V_12 ) , V_43 ) ;
return - V_59 ;
}
V_307 -> V_311 = F_179 ( V_310 ) >> 32 ;
V_307 -> V_312 = F_179 ( V_310 ) & 0xfffffffful ;
} else {
T_19 V_313 ;
V_43 = F_208 ( V_30 -> V_44 , V_2 -> V_132 , V_304 , 1 ,
& V_313 , & V_308 ) ;
if ( V_43 ) {
F_14 ( L_80 ,
F_72 ( V_12 ) , V_43 ) ;
return - V_59 ;
}
V_307 -> V_311 = 0 ;
V_307 -> V_312 = F_209 ( V_313 ) ;
}
V_307 -> V_308 = F_209 ( V_308 ) ;
F_190 ( V_30 , V_288 ) ;
F_178 ( L_81
L_82 ,
F_72 ( V_12 ) , V_305 ? L_83 : L_84 , V_294 , V_304 ,
V_307 -> V_311 , V_307 -> V_312 , V_308 , V_2 -> V_21 ) ;
return 0 ;
}
static void F_210 ( struct V_29 * V_30 )
{
unsigned int V_116 ;
const T_19 * V_314 = F_42 ( V_30 -> V_35 -> V_82 ,
L_85 , NULL ) ;
if ( ! V_314 ) {
V_314 = F_42 ( V_30 -> V_35 -> V_82 , L_86 , NULL ) ;
}
if ( ! V_314 )
return;
V_30 -> V_297 = F_211 ( V_314 ) ;
V_116 = F_211 ( V_314 + 1 ) ;
if ( F_212 ( & V_30 -> V_295 , V_116 , V_30 -> V_35 -> V_82 ) ) {
F_176 ( L_87 ,
V_30 -> V_35 -> V_36 ) ;
return;
}
V_30 -> V_315 = F_206 ;
V_30 -> V_316 = 1 ;
F_10 ( L_88 ,
V_116 , V_30 -> V_297 ) ;
}
static void F_210 ( struct V_29 * V_30 ) { }
static void F_213 ( struct V_60 * V_11 )
{
struct V_62 * V_35 ;
struct V_29 * V_30 ;
struct V_41 * V_83 ;
int V_67 ;
T_6 V_74 ;
struct V_101 * V_102 ;
int V_317 , V_164 ;
if ( ! V_11 -> V_149 || V_11 -> V_318 )
return;
V_35 = F_27 ( V_11 -> V_19 ) ;
V_30 = V_35 -> V_63 ;
V_102 = F_53 ( V_11 ) ;
V_102 -> V_319 = 0 ;
V_164 = F_82 ( V_11 ) ;
V_102 -> V_167 = 1 ;
V_317 = V_30 -> V_32 . V_33 ;
for ( V_67 = 0 ; V_67 < V_150 ; V_67 ++ ) {
V_83 = & V_11 -> V_41 [ V_67 + V_151 ] ;
if ( ! V_83 -> V_9 || V_83 -> V_69 )
continue;
if ( ! F_12 ( V_83 -> V_9 ) ) {
F_94 ( & V_11 -> V_12 , L_89 ,
V_67 , V_83 ) ;
continue;
}
V_74 = F_68 ( V_11 , V_67 + V_151 ) ;
if ( V_74 > ( 1 << 26 ) ) {
F_69 ( & V_11 -> V_12 , L_90 ,
V_67 , V_83 ) ;
V_102 -> V_167 = V_160 ;
V_317 = F_83 ( V_164 ) ;
break;
}
}
for ( V_67 = 0 ; V_67 < V_150 ; V_67 ++ ) {
V_83 = & V_11 -> V_41 [ V_67 + V_151 ] ;
if ( ! V_83 -> V_9 || V_83 -> V_69 )
continue;
if ( ! F_12 ( V_83 -> V_9 ) ) {
F_94 ( & V_11 -> V_12 , L_91 ,
V_67 , V_83 ) ;
continue;
}
F_214 ( & V_11 -> V_12 , L_92 , V_67 , V_83 ) ;
V_74 = F_68 ( V_11 , V_67 + V_151 ) ;
V_83 -> V_57 = V_83 -> V_55 + V_74 * V_317 - 1 ;
F_214 ( & V_11 -> V_12 , L_93 , V_83 ) ;
F_69 ( & V_11 -> V_12 , L_94 ,
V_67 , V_83 , V_317 ) ;
}
V_102 -> V_319 = V_317 ;
}
static void F_215 ( struct V_62 * V_35 ,
struct V_1 * V_2 )
{
struct V_29 * V_30 = V_35 -> V_63 ;
struct V_320 V_321 ;
struct V_41 * V_83 ;
int V_67 , V_193 ;
int V_43 ;
F_89 ( ! ( V_2 -> V_9 & ( V_13 | V_14 ) ) ) ;
F_216 (pe->pbus, res, i) {
if ( ! V_83 || ! V_83 -> V_9 ||
V_83 -> V_55 > V_83 -> V_57 )
continue;
if ( V_83 -> V_9 & V_322 ) {
V_321 . V_55 = V_83 -> V_55 - V_30 -> V_32 . V_323 ;
V_321 . V_57 = V_83 -> V_57 - V_30 -> V_32 . V_323 ;
V_193 = V_321 . V_55 / V_30 -> V_32 . V_324 ;
while ( V_193 < V_30 -> V_32 . V_33 &&
V_321 . V_55 <= V_321 . V_57 ) {
V_30 -> V_32 . V_325 [ V_193 ] = V_2 -> V_21 ;
V_43 = F_84 ( V_30 -> V_44 ,
V_2 -> V_21 , V_326 , 0 , V_193 ) ;
if ( V_43 != V_49 ) {
F_176 ( L_95
L_96 ,
V_34 , V_43 , V_193 , V_2 -> V_21 ) ;
break;
}
V_321 . V_55 += V_30 -> V_32 . V_324 ;
V_193 ++ ;
}
} else if ( ( V_83 -> V_9 & V_88 ) &&
! F_12 ( V_83 -> V_9 ) ) {
V_321 . V_55 = V_83 -> V_55 -
V_35 -> V_89 [ 0 ] -
V_30 -> V_32 . V_269 ;
V_321 . V_57 = V_83 -> V_57 -
V_35 -> V_89 [ 0 ] -
V_30 -> V_32 . V_269 ;
V_193 = V_321 . V_55 / V_30 -> V_32 . V_327 ;
while ( V_193 < V_30 -> V_32 . V_33 &&
V_321 . V_55 <= V_321 . V_57 ) {
V_30 -> V_32 . V_328 [ V_193 ] = V_2 -> V_21 ;
V_43 = F_84 ( V_30 -> V_44 ,
V_2 -> V_21 , V_329 , 0 , V_193 ) ;
if ( V_43 != V_49 ) {
F_176 ( L_97
L_98 ,
V_34 , V_43 , V_193 , V_2 -> V_21 ) ;
break;
}
V_321 . V_55 += V_30 -> V_32 . V_327 ;
V_193 ++ ;
}
}
}
}
static void F_217 ( void )
{
struct V_62 * V_158 , * V_35 ;
struct V_29 * V_30 ;
struct V_1 * V_2 ;
F_79 (hose, tmp, &hose_list, list_node) {
V_30 = V_35 -> V_63 ;
F_31 (pe, &phb->ioda.pe_list, list) {
F_215 ( V_35 , V_2 ) ;
}
}
}
static void F_218 ( void )
{
struct V_62 * V_35 , * V_158 ;
struct V_29 * V_30 ;
F_79 (hose, tmp, &hose_list, list_node) {
F_183 ( V_35 -> V_63 ) ;
V_30 = V_35 -> V_63 ;
V_30 -> V_330 = 1 ;
}
}
static void F_219 ( void )
{
#ifdef F_220
struct V_62 * V_35 , * V_158 ;
struct V_29 * V_30 ;
char V_331 [ 16 ] ;
F_79 (hose, tmp, &hose_list, list_node) {
V_30 = V_35 -> V_63 ;
sprintf ( V_331 , L_99 , V_35 -> V_36 ) ;
V_30 -> V_332 = F_221 ( V_331 , V_333 ) ;
if ( ! V_30 -> V_332 )
F_74 ( L_100 ,
V_34 , V_35 -> V_36 ) ;
}
#endif
}
static void F_222 ( void )
{
F_78 () ;
F_217 () ;
F_218 () ;
F_219 () ;
#ifdef F_223
F_224 () ;
F_225 () ;
#endif
}
static T_6 F_226 ( struct V_70 * V_19 ,
unsigned long type )
{
struct V_60 * V_334 ;
struct V_62 * V_35 = F_27 ( V_19 ) ;
struct V_29 * V_30 = V_35 -> V_63 ;
int V_335 = 0 ;
V_334 = V_19 -> V_111 ;
while ( V_334 ) {
if ( F_77 ( V_334 ) == V_157 ) {
V_335 ++ ;
if ( V_335 >= 2 )
return 1 ;
}
V_334 = V_334 -> V_19 -> V_111 ;
}
if ( V_30 -> V_32 . V_56 &&
F_12 ( type ) )
return V_30 -> V_32 . V_56 ;
if ( type & V_88 )
return V_30 -> V_32 . V_327 ;
return V_30 -> V_32 . V_324 ;
}
static T_6 F_227 ( struct V_60 * V_11 ,
int V_336 )
{
struct V_101 * V_102 = F_53 ( V_11 ) ;
T_6 V_337 , V_338 ;
V_338 = F_45 ( & V_11 -> V_41 [ V_336 ] ) ;
if ( V_338 )
return V_338 ;
V_337 = F_68 ( V_11 , V_336 ) ;
if ( V_102 -> V_319 )
return V_102 -> V_319 * V_337 ;
return V_337 ;
}
static bool F_228 ( struct V_60 * V_12 )
{
struct V_62 * V_35 = F_27 ( V_12 -> V_19 ) ;
struct V_29 * V_30 = V_35 -> V_63 ;
struct V_101 * V_102 ;
if ( ! V_30 -> V_330 )
return true ;
V_102 = F_53 ( V_12 ) ;
if ( ! V_102 || V_102 -> V_21 == V_39 )
return false ;
return true ;
}
static T_7 F_229 ( struct V_29 * V_30 , struct V_70 * V_19 ,
T_7 V_339 )
{
return V_30 -> V_32 . V_128 [ ( V_19 -> V_16 << 8 ) | V_339 ] ;
}
static void F_230 ( struct V_62 * V_35 )
{
struct V_29 * V_30 = V_35 -> V_63 ;
F_231 ( V_30 -> V_44 , V_340 ,
V_341 ) ;
}
static void T_2 F_232 ( struct V_81 * V_342 ,
T_3 V_343 , int V_344 )
{
struct V_62 * V_35 ;
struct V_29 * V_30 ;
unsigned long V_74 , V_345 , V_346 , V_347 = 0 ;
const T_14 * V_348 ;
const T_19 * V_349 ;
int V_350 ;
T_3 V_351 ;
void * V_352 ;
long V_43 ;
F_10 ( L_101 , V_344 , V_342 -> V_87 ) ;
V_348 = F_42 ( V_342 , L_102 , NULL ) ;
if ( ! V_348 ) {
F_176 ( L_103 ) ;
return;
}
V_351 = F_173 ( V_348 ) ;
F_16 ( L_104 , V_351 ) ;
V_30 = F_233 ( sizeof( struct V_29 ) , 0 ) ;
V_30 -> V_35 = V_35 = F_234 ( V_342 ) ;
if ( ! V_30 -> V_35 ) {
F_176 ( L_105 ,
V_342 -> V_87 ) ;
F_235 ( F_126 ( V_30 ) , sizeof( struct V_29 ) ) ;
return;
}
F_236 ( & V_30 -> V_353 ) ;
V_349 = F_42 ( V_342 , L_106 , & V_350 ) ;
if ( V_349 && V_350 == 8 ) {
V_35 -> V_354 = F_209 ( V_349 [ 0 ] ) ;
V_35 -> V_355 = F_209 ( V_349 [ 1 ] ) ;
} else {
F_14 ( L_107 , V_342 -> V_87 ) ;
V_35 -> V_354 = 0 ;
V_35 -> V_355 = 0xff ;
}
V_35 -> V_63 = V_30 ;
V_30 -> V_343 = V_343 ;
V_30 -> V_44 = V_351 ;
V_30 -> type = V_344 ;
F_237 ( & V_30 -> V_32 . V_183 ) ;
if ( F_238 ( V_342 , L_108 ) )
V_30 -> V_356 = V_357 ;
else if ( F_238 ( V_342 , L_109 ) )
V_30 -> V_356 = V_358 ;
else
V_30 -> V_356 = V_359 ;
F_239 ( V_35 , V_342 , ! V_35 -> V_36 ) ;
V_30 -> V_360 = F_240 ( V_342 , 0 ) ;
if ( V_30 -> V_360 == NULL )
F_176 ( L_110 ) ;
V_30 -> V_32 . V_33 = 1 ;
V_349 = F_42 ( V_342 , L_111 , NULL ) ;
if ( V_349 )
V_30 -> V_32 . V_33 = F_211 ( V_349 ) ;
V_349 = F_42 ( V_342 , L_112 , NULL ) ;
if ( V_349 )
V_30 -> V_32 . V_54 = F_211 ( V_349 ) ;
F_40 ( V_30 ) ;
V_30 -> V_32 . V_361 = F_45 ( & V_35 -> V_53 [ 0 ] ) ;
V_30 -> V_32 . V_361 += 0x10000 ;
V_30 -> V_32 . V_327 = V_30 -> V_32 . V_361 / V_30 -> V_32 . V_33 ;
V_30 -> V_32 . V_269 = V_35 -> V_53 [ 0 ] . V_55 - V_35 -> V_89 [ 0 ] ;
V_30 -> V_32 . V_362 = V_35 -> V_363 ;
V_30 -> V_32 . V_324 = V_30 -> V_32 . V_362 / V_30 -> V_32 . V_33 ;
V_30 -> V_32 . V_323 = 0 ;
V_74 = F_29 ( V_30 -> V_32 . V_33 / 8 , sizeof( unsigned long ) ) ;
V_345 = V_74 ;
V_74 += V_30 -> V_32 . V_33 * sizeof( V_30 -> V_32 . V_328 [ 0 ] ) ;
if ( V_30 -> type == V_131 ) {
V_347 = V_74 ;
V_74 += V_30 -> V_32 . V_33 * sizeof( V_30 -> V_32 . V_325 [ 0 ] ) ;
}
V_346 = V_74 ;
V_74 += V_30 -> V_32 . V_33 * sizeof( struct V_1 ) ;
V_352 = F_233 ( V_74 , 0 ) ;
V_30 -> V_32 . V_37 = V_352 ;
V_30 -> V_32 . V_328 = V_352 + V_345 ;
if ( V_30 -> type == V_131 )
V_30 -> V_32 . V_325 = V_352 + V_347 ;
V_30 -> V_32 . V_38 = V_352 + V_346 ;
F_25 ( V_30 -> V_32 . V_54 , V_30 -> V_32 . V_37 ) ;
F_38 ( & V_30 -> V_32 . V_138 ) ;
F_38 ( & V_30 -> V_32 . V_155 ) ;
F_237 ( & V_30 -> V_32 . V_179 ) ;
V_30 -> V_32 . V_282 = V_30 -> V_32 . V_269 >> 28 ;
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
V_30 -> V_32 . V_361 , V_30 -> V_32 . V_327 ) ;
if ( V_30 -> V_32 . V_48 )
F_10 ( L_114 ,
V_30 -> V_32 . V_48 , V_30 -> V_32 . V_56 ) ;
if ( V_30 -> V_32 . V_362 )
F_10 ( L_115 ,
V_30 -> V_32 . V_362 , V_30 -> V_32 . V_324 ) ;
V_30 -> V_35 -> V_277 = & V_364 ;
V_30 -> V_365 = F_50 ;
V_30 -> V_366 = F_46 ;
V_30 -> V_367 = F_48 ;
V_30 -> V_368 = F_229 ;
V_30 -> V_369 = F_111 ;
F_210 ( V_30 ) ;
V_370 . V_371 = F_222 ;
V_35 -> V_372 = V_373 ;
#ifdef F_5
V_370 . V_374 = F_213 ;
V_370 . V_375 = F_227 ;
#endif
F_241 ( V_376 ) ;
V_43 = F_231 ( V_351 , V_340 , V_341 ) ;
if ( V_43 )
F_74 ( L_116 , V_43 ) ;
if ( F_242 () ) {
F_10 ( L_117 ) ;
F_243 ( V_35 , V_377 ) ;
F_243 ( V_35 , V_378 ) ;
}
if ( ! V_30 -> V_90 || V_30 -> V_90 ( V_30 ) )
V_35 -> V_53 [ 1 ] . V_9 = 0 ;
}
void T_2 F_244 ( struct V_81 * V_342 )
{
F_232 ( V_342 , 0 , V_85 ) ;
}
void T_2 F_245 ( struct V_81 * V_342 )
{
struct V_81 * V_379 ;
const T_14 * V_348 ;
T_3 V_343 ;
F_10 ( L_118 , V_342 -> V_87 ) ;
V_348 = F_42 ( V_342 , L_119 , NULL ) ;
if ( ! V_348 ) {
F_176 ( L_120 ) ;
return;
}
V_343 = F_173 ( V_348 ) ;
F_178 ( L_121 , V_343 ) ;
F_246 (np, phbn) {
if ( F_238 ( V_379 , L_122 ) )
F_232 ( V_379 , V_343 , V_131 ) ;
}
}
