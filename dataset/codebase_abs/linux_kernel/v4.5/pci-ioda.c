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
static inline bool F_11 ( unsigned long V_9 )
{
return ( ( V_9 & ( V_25 | V_26 ) ) ==
( V_25 | V_26 ) ) ;
}
static void F_12 ( struct V_27 * V_28 , int V_29 )
{
if ( ! ( V_29 >= 0 && V_29 < V_28 -> V_30 . V_31 ) ) {
F_13 ( L_7 ,
V_32 , V_29 , V_28 -> V_33 -> V_34 ) ;
return;
}
if ( F_14 ( V_29 , V_28 -> V_30 . V_35 ) )
F_15 ( L_8 ,
V_32 , V_29 , V_28 -> V_33 -> V_34 ) ;
V_28 -> V_30 . V_36 [ V_29 ] . V_28 = V_28 ;
V_28 -> V_30 . V_36 [ V_29 ] . V_21 = V_29 ;
}
static int F_16 ( struct V_27 * V_28 )
{
unsigned long V_2 ;
do {
V_2 = F_17 ( V_28 -> V_30 . V_35 ,
V_28 -> V_30 . V_31 , 0 ) ;
if ( V_2 >= V_28 -> V_30 . V_31 )
return V_37 ;
} while( F_14 ( V_2 , V_28 -> V_30 . V_35 ) );
V_28 -> V_30 . V_36 [ V_2 ] . V_28 = V_28 ;
V_28 -> V_30 . V_36 [ V_2 ] . V_21 = V_2 ;
return V_2 ;
}
static void F_18 ( struct V_27 * V_28 , int V_2 )
{
F_19 ( V_28 -> V_30 . V_36 [ V_2 ] . V_11 ) ;
memset ( & V_28 -> V_30 . V_36 [ V_2 ] , 0 , sizeof( struct V_1 ) ) ;
F_20 ( V_2 , V_28 -> V_30 . V_35 ) ;
}
static int F_21 ( struct V_27 * V_28 )
{
const char * V_38 ;
struct V_39 * V_40 ;
T_3 V_41 ;
V_41 = F_22 ( V_28 -> V_42 ,
V_43 ,
V_28 -> V_30 . V_44 ,
V_28 -> V_30 . V_45 ,
0 ,
V_28 -> V_30 . V_46 ) ;
if ( V_41 != V_47 ) {
V_38 = L_9 ;
goto V_48;
}
V_41 = F_23 ( V_28 -> V_42 ,
V_43 ,
V_28 -> V_30 . V_44 ,
V_49 ) ;
if ( V_41 != V_47 ) {
V_38 = L_10 ;
goto V_48;
}
F_24 ( V_28 -> V_30 . V_44 , & V_28 -> V_30 . V_50 ) ;
V_40 = & V_28 -> V_33 -> V_51 [ 1 ] ;
if ( V_28 -> V_30 . V_52 == 0 )
V_40 -> V_53 += V_28 -> V_30 . V_54 ;
else if ( V_28 -> V_30 . V_52 == ( V_28 -> V_30 . V_31 - 1 ) )
V_40 -> V_55 -= V_28 -> V_30 . V_54 ;
else
F_13 ( L_11 ,
V_28 -> V_30 . V_52 ) ;
return 0 ;
V_48:
F_13 ( L_12 ,
V_41 , V_38 , V_28 -> V_30 . V_44 ) ;
F_23 ( V_28 -> V_42 ,
V_43 ,
V_28 -> V_30 . V_44 ,
V_56 ) ;
return - V_57 ;
}
static void F_25 ( struct V_58 * V_11 ,
unsigned long * V_59 )
{
struct V_60 * V_33 = F_26 ( V_11 -> V_19 ) ;
struct V_27 * V_28 = V_33 -> V_61 ;
struct V_39 * V_40 ;
T_4 V_62 , V_63 , V_53 , V_55 ;
int V_64 , V_65 ;
V_62 = V_28 -> V_30 . V_45 ;
V_63 = V_28 -> V_30 . V_54 ;
for ( V_65 = 0 ; V_65 <= V_66 ; V_65 ++ ) {
V_40 = & V_11 -> V_39 [ V_65 ] ;
if ( ! V_40 -> V_67 || ! F_11 ( V_40 -> V_9 ) )
continue;
V_53 = F_27 ( V_40 -> V_53 - V_62 , V_63 ) ;
V_55 = F_28 ( V_40 -> V_55 - V_62 , V_63 ) ;
for ( V_64 = V_53 / V_63 ; V_64 < V_55 / V_63 ; V_64 ++ ) {
if ( V_59 )
F_24 ( V_64 , V_59 ) ;
else
F_12 ( V_28 , V_64 ) ;
}
}
}
static void F_29 ( struct V_68 * V_19 ,
unsigned long * V_59 ,
bool V_69 )
{
struct V_58 * V_11 ;
F_30 (pdev, &bus->devices, bus_list) {
F_25 ( V_11 , V_59 ) ;
if ( V_69 && V_11 -> V_70 )
F_29 ( V_11 -> V_70 ,
V_59 , V_69 ) ;
}
}
static int F_31 ( struct V_68 * V_19 , bool V_69 )
{
struct V_60 * V_33 = F_26 ( V_19 ) ;
struct V_27 * V_28 = V_33 -> V_61 ;
struct V_1 * V_71 , * V_2 ;
unsigned long V_72 , * V_35 ;
int V_65 ;
if ( F_32 ( V_19 ) )
return V_37 ;
V_72 = F_28 ( V_28 -> V_30 . V_31 / 8 , sizeof( unsigned long ) ) ;
V_35 = F_33 ( V_72 , V_73 ) ;
if ( ! V_35 ) {
F_13 ( L_13 ,
V_32 ) ;
return V_37 ;
}
F_29 ( V_19 , V_35 , V_69 ) ;
if ( F_34 ( V_35 , V_28 -> V_30 . V_31 ) ) {
F_35 ( V_35 ) ;
return V_37 ;
}
V_71 = NULL ;
V_65 = - 1 ;
while ( ( V_65 = F_36 ( V_35 , V_28 -> V_30 . V_31 , V_65 + 1 ) ) <
V_28 -> V_30 . V_31 ) {
V_2 = & V_28 -> V_30 . V_36 [ V_65 ] ;
if ( ! V_71 ) {
V_2 -> V_9 |= V_74 ;
F_37 ( & V_2 -> V_75 ) ;
V_71 = V_2 ;
} else {
V_2 -> V_9 |= V_76 ;
V_2 -> V_77 = V_71 ;
F_38 ( & V_2 -> V_78 , & V_71 -> V_75 ) ;
}
}
F_35 ( V_35 ) ;
return V_71 -> V_21 ;
}
static void T_2 F_39 ( struct V_27 * V_28 )
{
struct V_60 * V_33 = V_28 -> V_33 ;
struct V_79 * V_80 = V_33 -> V_80 ;
struct V_39 * V_81 ;
const T_5 * V_40 ;
T_6 V_82 ;
if ( V_28 -> type != V_83 ) {
F_10 ( L_14 ) ;
return;
}
if ( ! F_40 ( V_84 ) ) {
F_10 ( L_15 ) ;
return;
}
V_40 = F_41 ( V_80 , L_16 , NULL ) ;
if ( ! V_40 ) {
F_10 ( L_17 ,
V_80 -> V_85 ) ;
return;
}
V_81 = & V_33 -> V_51 [ 1 ] ;
V_81 -> V_86 = V_80 -> V_85 ;
V_81 -> V_53 = F_42 ( V_80 , V_40 + 2 ) ;
V_81 -> V_55 = V_81 -> V_53 + F_43 ( V_40 + 4 , 2 ) - 1 ;
V_81 -> V_9 = ( V_87 | V_25 | V_26 ) ;
V_82 = F_43 ( V_40 , 2 ) ;
V_33 -> V_88 [ 1 ] = V_81 -> V_53 - V_82 ;
V_28 -> V_30 . V_46 = F_44 ( V_81 ) ;
V_28 -> V_30 . V_54 = V_28 -> V_30 . V_46 / V_28 -> V_30 . V_31 ;
V_28 -> V_30 . V_45 = V_82 ;
F_10 ( L_18 ,
V_81 -> V_53 , V_81 -> V_55 , V_82 ) ;
V_28 -> V_30 . V_44 = 15 ;
V_28 -> V_89 = F_21 ;
V_28 -> V_90 = F_29 ;
V_28 -> V_91 = F_31 ;
}
static void F_45 ( struct V_27 * V_28 , int V_29 )
{
struct V_1 * V_2 = & V_28 -> V_30 . V_36 [ V_29 ] ;
struct V_1 * V_92 ;
T_3 V_41 ;
if ( V_2 -> V_9 & V_76 ) {
V_2 = V_2 -> V_77 ;
if ( F_19 ( ! V_2 || ! ( V_2 -> V_9 & V_74 ) ) )
return;
V_29 = V_2 -> V_21 ;
}
V_41 = F_46 ( V_28 -> V_42 ,
V_29 ,
V_93 ) ;
if ( V_41 != V_47 ) {
F_13 ( L_19 ,
V_32 , V_41 , V_28 -> V_33 -> V_34 , V_29 ) ;
return;
}
if ( ! ( V_2 -> V_9 & V_74 ) )
return;
F_30 (slave, &pe->slaves, list) {
V_41 = F_46 ( V_28 -> V_42 ,
V_92 -> V_21 ,
V_93 ) ;
if ( V_41 != V_47 )
F_13 ( L_19 ,
V_32 , V_41 , V_28 -> V_33 -> V_34 ,
V_92 -> V_21 ) ;
}
}
static int F_47 ( struct V_27 * V_28 , int V_29 , int V_94 )
{
struct V_1 * V_2 , * V_92 ;
T_3 V_41 ;
V_2 = & V_28 -> V_30 . V_36 [ V_29 ] ;
if ( V_2 -> V_9 & V_76 ) {
V_2 = V_2 -> V_77 ;
F_19 ( ! V_2 || ! ( V_2 -> V_9 & V_74 ) ) ;
V_29 = V_2 -> V_21 ;
}
V_41 = F_48 ( V_28 -> V_42 , V_29 , V_94 ) ;
if ( V_41 != V_47 ) {
F_13 ( L_20 ,
V_32 , V_41 , V_94 , V_28 -> V_33 -> V_34 , V_29 ) ;
return - V_57 ;
}
if ( ! ( V_2 -> V_9 & V_74 ) )
return 0 ;
F_30 (slave, &pe->slaves, list) {
V_41 = F_48 ( V_28 -> V_42 ,
V_92 -> V_21 ,
V_94 ) ;
if ( V_41 != V_47 ) {
F_13 ( L_20 ,
V_32 , V_41 , V_94 , V_28 -> V_33 -> V_34 ,
V_92 -> V_21 ) ;
return - V_57 ;
}
}
return 0 ;
}
static int F_49 ( struct V_27 * V_28 , int V_29 )
{
struct V_1 * V_92 , * V_2 ;
T_7 V_95 , V_96 ;
T_8 V_97 ;
T_3 V_41 ;
if ( V_29 < 0 || V_29 >= V_28 -> V_30 . V_31 )
return V_98 ;
V_2 = & V_28 -> V_30 . V_36 [ V_29 ] ;
if ( V_2 -> V_9 & V_76 ) {
V_2 = V_2 -> V_77 ;
F_19 ( ! V_2 || ! ( V_2 -> V_9 & V_74 ) ) ;
V_29 = V_2 -> V_21 ;
}
V_41 = F_50 ( V_28 -> V_42 , V_29 ,
& V_96 , & V_97 , NULL ) ;
if ( V_41 != V_47 ) {
F_13 ( L_21
L_22 ,
V_32 , V_41 ,
V_28 -> V_33 -> V_34 , V_29 ) ;
return V_99 ;
}
if ( ! ( V_2 -> V_9 & V_74 ) )
return V_96 ;
F_30 (slave, &pe->slaves, list) {
V_41 = F_50 ( V_28 -> V_42 ,
V_92 -> V_21 ,
& V_95 ,
& V_97 ,
NULL ) ;
if ( V_41 != V_47 ) {
F_13 ( L_21
L_22 ,
V_32 , V_41 ,
V_28 -> V_33 -> V_34 , V_92 -> V_21 ) ;
return V_99 ;
}
if ( V_95 > V_96 )
V_96 = V_95 ;
}
return V_96 ;
}
static struct V_1 * F_51 ( struct V_58 * V_12 )
{
struct V_60 * V_33 = F_26 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_33 -> V_61 ;
struct V_100 * V_101 = F_52 ( V_12 ) ;
if ( ! V_101 )
return NULL ;
if ( V_101 -> V_21 == V_37 )
return NULL ;
return & V_28 -> V_30 . V_36 [ V_101 -> V_21 ] ;
}
static int F_53 ( struct V_27 * V_28 ,
struct V_1 * V_67 ,
struct V_1 * V_102 ,
bool V_103 )
{
const char * V_38 = V_103 ? L_23 : L_24 ;
T_9 V_104 = V_103 ? V_105 :
V_106 ;
struct V_1 * V_92 ;
long V_41 ;
V_41 = F_54 ( V_28 -> V_42 , V_67 -> V_21 ,
V_102 -> V_21 , V_104 ) ;
if ( V_41 != V_47 ) {
F_55 ( V_102 , L_25 ,
V_41 , V_38 ) ;
return - V_107 ;
}
if ( ! ( V_102 -> V_9 & V_74 ) )
return 0 ;
F_30 (slave, &child->slaves, list) {
V_41 = F_54 ( V_28 -> V_42 , V_67 -> V_21 ,
V_92 -> V_21 , V_104 ) ;
if ( V_41 != V_47 ) {
F_55 ( V_92 , L_25 ,
V_41 , V_38 ) ;
return - V_107 ;
}
}
return 0 ;
}
static int F_56 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
bool V_103 )
{
struct V_1 * V_92 ;
struct V_58 * V_11 = NULL ;
int V_108 ;
if ( V_103 ) {
F_48 ( V_28 -> V_42 , V_2 -> V_21 ,
V_109 ) ;
if ( V_2 -> V_9 & V_74 ) {
F_30 (slave, &pe->slaves, list)
F_48 ( V_28 -> V_42 ,
V_92 -> V_21 ,
V_109 ) ;
}
}
V_108 = F_53 ( V_28 , V_2 , V_2 , V_103 ) ;
if ( V_108 )
return V_108 ;
if ( V_2 -> V_9 & V_74 ) {
F_30 (slave, &pe->slaves, list) {
V_108 = F_53 ( V_28 , V_92 , V_2 , V_103 ) ;
if ( V_108 )
return V_108 ;
}
}
if ( V_2 -> V_9 & ( V_14 | V_13 ) )
V_11 = V_2 -> V_15 -> V_110 ;
else if ( V_2 -> V_9 & V_10 )
V_11 = V_2 -> V_11 -> V_19 -> V_110 ;
#ifdef F_5
else if ( V_2 -> V_9 & V_17 )
V_11 = V_2 -> V_18 ;
#endif
while ( V_11 ) {
struct V_100 * V_101 = F_52 ( V_11 ) ;
struct V_1 * V_67 ;
if ( V_101 && V_101 -> V_21 != V_37 ) {
V_67 = & V_28 -> V_30 . V_36 [ V_101 -> V_21 ] ;
V_108 = F_53 ( V_28 , V_67 , V_2 , V_103 ) ;
if ( V_108 )
return V_108 ;
}
V_11 = V_11 -> V_19 -> V_110 ;
}
return 0 ;
}
static int F_57 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
struct V_58 * V_67 ;
T_9 V_111 , V_112 , V_113 ;
T_10 V_41 ;
long V_114 , V_20 ;
if ( V_2 -> V_15 ) {
int V_115 ;
V_112 = V_116 ;
V_113 = V_117 ;
V_67 = V_2 -> V_15 -> V_110 ;
if ( V_2 -> V_9 & V_14 )
V_115 = V_2 -> V_15 -> V_118 . V_55 - V_2 -> V_15 -> V_118 . V_53 + 1 ;
else
V_115 = 1 ;
switch( V_115 ) {
case 1 : V_111 = V_119 ; break;
case 2 : V_111 = V_120 ; break;
case 4 : V_111 = V_121 ; break;
case 8 : V_111 = V_122 ; break;
case 16 : V_111 = V_123 ; break;
case 32 : V_111 = V_124 ; break;
default:
F_58 ( & V_2 -> V_15 -> V_12 , L_26 ,
V_115 ) ;
V_111 = V_119 ;
}
V_114 = V_2 -> V_20 + ( V_115 << 8 ) ;
} else {
if ( V_2 -> V_9 & V_17 )
V_67 = V_2 -> V_18 ;
else
V_67 = V_2 -> V_11 -> V_19 -> V_110 ;
V_111 = V_119 ;
V_112 = V_125 ;
V_113 = V_126 ;
V_114 = V_2 -> V_20 + 1 ;
}
for ( V_20 = V_2 -> V_20 ; V_20 < V_114 ; V_20 ++ )
V_28 -> V_30 . V_127 [ V_20 ] = 0 ;
while ( V_67 ) {
struct V_100 * V_101 = F_52 ( V_67 ) ;
if ( V_101 && V_101 -> V_21 != V_37 ) {
V_41 = F_54 ( V_28 -> V_42 , V_101 -> V_21 ,
V_2 -> V_21 , V_106 ) ;
}
V_67 = V_67 -> V_19 -> V_110 ;
}
F_48 ( V_28 -> V_42 , V_2 -> V_21 ,
V_109 ) ;
V_41 = F_54 ( V_28 -> V_42 , V_2 -> V_21 ,
V_2 -> V_21 , V_106 ) ;
if ( V_41 )
F_55 ( V_2 , L_27 , V_41 ) ;
V_41 = F_59 ( V_28 -> V_42 , V_2 -> V_21 , V_2 -> V_20 ,
V_111 , V_112 , V_113 , V_128 ) ;
if ( V_41 )
F_60 ( V_2 , L_28 , V_41 ) ;
V_2 -> V_15 = NULL ;
V_2 -> V_11 = NULL ;
V_2 -> V_18 = NULL ;
return 0 ;
}
static int F_61 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
struct V_58 * V_67 ;
T_9 V_111 , V_112 , V_113 ;
long V_41 , V_114 , V_20 ;
if ( V_2 -> V_15 ) {
int V_115 ;
V_112 = V_116 ;
V_113 = V_117 ;
V_67 = V_2 -> V_15 -> V_110 ;
if ( V_2 -> V_9 & V_14 )
V_115 = V_2 -> V_15 -> V_118 . V_55 - V_2 -> V_15 -> V_118 . V_53 + 1 ;
else
V_115 = 1 ;
switch( V_115 ) {
case 1 : V_111 = V_119 ; break;
case 2 : V_111 = V_120 ; break;
case 4 : V_111 = V_121 ; break;
case 8 : V_111 = V_122 ; break;
case 16 : V_111 = V_123 ; break;
case 32 : V_111 = V_124 ; break;
default:
F_58 ( & V_2 -> V_15 -> V_12 , L_26 ,
V_115 ) ;
V_111 = V_119 ;
}
V_114 = V_2 -> V_20 + ( V_115 << 8 ) ;
} else {
#ifdef F_5
if ( V_2 -> V_9 & V_17 )
V_67 = V_2 -> V_18 ;
else
#endif
V_67 = V_2 -> V_11 -> V_19 -> V_110 ;
V_111 = V_119 ;
V_112 = V_125 ;
V_113 = V_126 ;
V_114 = V_2 -> V_20 + 1 ;
}
V_41 = F_59 ( V_28 -> V_42 , V_2 -> V_21 , V_2 -> V_20 ,
V_111 , V_112 , V_113 , V_129 ) ;
if ( V_41 ) {
F_60 ( V_2 , L_28 , V_41 ) ;
return - V_107 ;
}
if ( V_28 -> type != V_130 )
F_56 ( V_28 , V_2 , true ) ;
for ( V_20 = V_2 -> V_20 ; V_20 < V_114 ; V_20 ++ )
V_28 -> V_30 . V_127 [ V_20 ] = V_2 -> V_21 ;
if ( V_28 -> type != V_131 ) {
V_2 -> V_132 = 0 ;
goto V_133;
}
V_2 -> V_132 = V_2 -> V_21 ;
V_41 = F_62 ( V_28 -> V_42 , V_2 -> V_132 , V_2 -> V_21 ) ;
if ( V_41 != V_47 ) {
F_60 ( V_2 , L_29 ,
V_41 , V_2 -> V_132 ) ;
V_2 -> V_132 = - 1 ;
} else {
V_41 = F_63 ( V_28 -> V_42 ,
V_2 -> V_132 , V_134 ) ;
if ( V_41 ) {
F_60 ( V_2 , L_30 ,
V_41 , V_2 -> V_132 ) ;
V_2 -> V_132 = - 1 ;
}
}
V_133:
return 0 ;
}
static void F_64 ( struct V_27 * V_28 ,
struct V_1 * V_2 )
{
struct V_1 * V_135 ;
F_30 (lpe, &phb->ioda.pe_dma_list, dma_link) {
if ( V_135 -> V_136 < V_2 -> V_136 ) {
F_38 ( & V_2 -> V_137 , & V_135 -> V_137 ) ;
return;
}
}
F_38 ( & V_2 -> V_137 , & V_28 -> V_30 . V_138 ) ;
}
static unsigned int F_65 ( struct V_58 * V_12 )
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
static int F_66 ( struct V_58 * V_12 , int V_146 )
{
struct V_100 * V_101 = F_52 ( V_12 ) ;
int V_65 ;
struct V_39 * V_81 , V_147 ;
T_4 V_72 ;
T_11 V_148 ;
if ( ! V_12 -> V_149 )
return - V_23 ;
V_148 = V_101 -> V_148 ;
for ( V_65 = 0 ; V_65 < V_150 ; V_65 ++ ) {
V_81 = & V_12 -> V_39 [ V_65 + V_151 ] ;
if ( ! V_81 -> V_9 || ! V_81 -> V_67 )
continue;
if ( ! F_11 ( V_81 -> V_9 ) )
continue;
V_72 = F_67 ( V_12 , V_65 + V_151 ) ;
V_147 . V_9 = V_81 -> V_9 ;
V_147 . V_53 = V_81 -> V_53 + ( V_72 * V_146 ) ;
V_147 . V_55 = V_147 . V_53 + ( V_72 * V_148 ) - 1 ;
if ( V_147 . V_55 > V_81 -> V_55 ) {
F_58 ( & V_12 -> V_12 , L_31 ,
V_65 , & V_147 , V_81 , V_148 , V_146 ) ;
return - V_152 ;
}
}
for ( V_65 = 0 ; V_65 < V_150 ; V_65 ++ ) {
V_81 = & V_12 -> V_39 [ V_65 + V_151 ] ;
if ( ! V_81 -> V_9 || ! V_81 -> V_67 )
continue;
if ( ! F_11 ( V_81 -> V_9 ) )
continue;
V_72 = F_67 ( V_12 , V_65 + V_151 ) ;
V_147 = * V_81 ;
V_81 -> V_53 += V_72 * V_146 ;
F_68 ( & V_12 -> V_12 , L_32 ,
V_65 , & V_147 , V_81 , ( V_146 > 0 ) ? L_33 : L_34 ,
V_148 , V_146 ) ;
F_69 ( V_12 , V_65 + V_151 ) ;
}
return 0 ;
}
static struct V_1 * F_70 ( struct V_58 * V_12 )
{
struct V_60 * V_33 = F_26 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_33 -> V_61 ;
struct V_100 * V_101 = F_52 ( V_12 ) ;
struct V_1 * V_2 ;
int V_153 ;
if ( ! V_101 ) {
F_71 ( L_35 ,
F_72 ( V_12 ) ) ;
return NULL ;
}
if ( V_101 -> V_21 != V_37 )
return NULL ;
V_153 = F_16 ( V_28 ) ;
if ( V_153 == V_37 ) {
F_73 ( L_36 ,
F_72 ( V_12 ) ) ;
return NULL ;
}
V_2 = & V_28 -> V_30 . V_36 [ V_153 ] ;
F_74 ( V_12 ) ;
V_101 -> V_154 = V_12 ;
V_101 -> V_21 = V_153 ;
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = V_12 ;
V_2 -> V_15 = NULL ;
V_2 -> V_155 = - 1 ;
V_2 -> V_132 = - 1 ;
V_2 -> V_20 = V_12 -> V_19 -> V_16 << 8 | V_101 -> V_156 ;
F_75 ( V_2 , L_37 ) ;
if ( F_61 ( V_28 , V_2 ) ) {
if ( V_153 )
F_18 ( V_28 , V_153 ) ;
V_101 -> V_21 = V_37 ;
V_2 -> V_11 = NULL ;
F_76 ( V_12 ) ;
return NULL ;
}
V_2 -> V_136 = F_65 ( V_12 ) ;
if ( V_2 -> V_136 != 0 ) {
V_28 -> V_30 . V_136 += V_2 -> V_136 ;
V_28 -> V_30 . V_157 ++ ;
}
F_64 ( V_28 , V_2 ) ;
return V_2 ;
}
static void F_77 ( struct V_68 * V_19 , struct V_1 * V_2 )
{
struct V_58 * V_12 ;
F_30 (dev, &bus->devices, bus_list) {
struct V_100 * V_101 = F_52 ( V_12 ) ;
if ( V_101 == NULL ) {
F_13 ( L_38 ,
F_72 ( V_12 ) ) ;
continue;
}
V_101 -> V_154 = V_12 ;
V_101 -> V_21 = V_2 -> V_21 ;
V_2 -> V_136 += F_65 ( V_12 ) ;
if ( ( V_2 -> V_9 & V_14 ) && V_12 -> V_70 )
F_77 ( V_12 -> V_70 , V_2 ) ;
}
}
static void F_78 ( struct V_68 * V_19 , bool V_69 )
{
struct V_60 * V_33 = F_26 ( V_19 ) ;
struct V_27 * V_28 = V_33 -> V_61 ;
struct V_1 * V_2 ;
int V_153 = V_37 ;
if ( V_28 -> V_91 )
V_153 = V_28 -> V_91 ( V_19 , V_69 ) ;
if ( V_153 == V_37 )
V_153 = F_16 ( V_28 ) ;
if ( V_153 == V_37 ) {
F_73 ( L_39 ,
V_32 , F_4 ( V_19 ) , V_19 -> V_16 ) ;
return;
}
V_2 = & V_28 -> V_30 . V_36 [ V_153 ] ;
V_2 -> V_9 |= ( V_69 ? V_14 : V_13 ) ;
V_2 -> V_15 = V_19 ;
V_2 -> V_11 = NULL ;
V_2 -> V_155 = - 1 ;
V_2 -> V_132 = - 1 ;
V_2 -> V_20 = V_19 -> V_118 . V_53 << 8 ;
V_2 -> V_136 = 0 ;
if ( V_69 )
F_75 ( V_2 , L_40 ,
V_19 -> V_118 . V_53 , V_19 -> V_118 . V_55 , V_153 ) ;
else
F_75 ( V_2 , L_41 ,
V_19 -> V_118 . V_53 , V_153 ) ;
if ( F_61 ( V_28 , V_2 ) ) {
if ( V_153 )
F_18 ( V_28 , V_153 ) ;
V_2 -> V_15 = NULL ;
return;
}
F_77 ( V_19 , V_2 ) ;
F_38 ( & V_2 -> V_78 , & V_28 -> V_30 . V_158 ) ;
if ( V_2 -> V_136 != 0 ) {
V_28 -> V_30 . V_136 += V_2 -> V_136 ;
V_28 -> V_30 . V_157 ++ ;
}
F_64 ( V_28 , V_2 ) ;
}
static struct V_1 * F_79 ( struct V_58 * V_159 )
{
int V_153 , V_160 = false , V_41 ;
long V_20 ;
struct V_1 * V_2 ;
struct V_58 * V_161 ;
struct V_100 * V_162 ;
struct V_60 * V_33 = F_26 ( V_159 -> V_19 ) ;
struct V_27 * V_28 = V_33 -> V_61 ;
V_161 = F_80 ( V_159 ) ;
for ( V_153 = 0 ; V_153 < V_28 -> V_30 . V_31 ; V_153 ++ ) {
V_2 = & V_28 -> V_30 . V_36 [ V_153 ] ;
if ( ! V_2 -> V_11 )
continue;
if ( F_80 ( V_2 -> V_11 ) == V_161 ) {
F_68 ( & V_159 -> V_12 ,
L_42 , V_153 ) ;
F_74 ( V_159 ) ;
V_162 = F_52 ( V_159 ) ;
V_20 = V_159 -> V_19 -> V_16 << 8 | V_162 -> V_156 ;
V_162 -> V_154 = V_159 ;
V_162 -> V_21 = V_153 ;
V_2 -> V_136 += F_65 ( V_159 ) ;
V_28 -> V_30 . V_127 [ V_20 ] = V_2 -> V_21 ;
V_41 = F_59 ( V_28 -> V_42 , V_153 , V_20 ,
V_119 ,
V_125 ,
V_126 ,
V_129 ) ;
F_19 ( V_41 != V_47 ) ;
V_160 = true ;
break;
}
}
if ( ! V_160 )
return F_70 ( V_159 ) ;
else
return V_2 ;
}
static void F_81 ( struct V_68 * V_19 )
{
struct V_58 * V_11 ;
F_30 (pdev, &bus->devices, bus_list)
F_79 ( V_11 ) ;
}
static void F_82 ( struct V_68 * V_19 )
{
struct V_58 * V_12 ;
F_78 ( V_19 , false ) ;
F_30 (dev, &bus->devices, bus_list) {
if ( V_12 -> V_70 ) {
if ( F_83 ( V_12 ) == V_163 )
F_78 ( V_12 -> V_70 , true ) ;
else
F_82 ( V_12 -> V_70 ) ;
}
}
}
static void F_84 ( void )
{
struct V_60 * V_33 , * V_164 ;
struct V_27 * V_28 ;
F_85 (hose, tmp, &hose_list, list_node) {
V_28 = V_33 -> V_61 ;
if ( V_28 -> V_90 )
V_28 -> V_90 ( V_33 -> V_19 , NULL , true ) ;
if ( V_28 -> type == V_130 ) {
F_12 ( V_28 , 0 ) ;
F_81 ( V_33 -> V_19 ) ;
} else
F_82 ( V_33 -> V_19 ) ;
}
}
static int F_86 ( struct V_58 * V_11 )
{
struct V_68 * V_19 ;
struct V_60 * V_33 ;
struct V_27 * V_28 ;
struct V_100 * V_101 ;
int V_65 , V_165 ;
V_19 = V_11 -> V_19 ;
V_33 = F_26 ( V_19 ) ;
V_28 = V_33 -> V_61 ;
V_101 = F_52 ( V_11 ) ;
for ( V_65 = 0 ; V_65 < V_150 ; V_65 ++ )
for ( V_165 = 0 ; V_165 < V_166 ; V_165 ++ ) {
if ( V_101 -> V_167 [ V_65 ] [ V_165 ] == V_168 )
continue;
F_23 ( V_28 -> V_42 ,
V_43 , V_101 -> V_167 [ V_65 ] [ V_165 ] , 0 ) ;
F_20 ( V_101 -> V_167 [ V_65 ] [ V_165 ] , & V_28 -> V_30 . V_50 ) ;
V_101 -> V_167 [ V_65 ] [ V_165 ] = V_168 ;
}
return 0 ;
}
static int F_87 ( struct V_58 * V_11 , T_11 V_148 )
{
struct V_68 * V_19 ;
struct V_60 * V_33 ;
struct V_27 * V_28 ;
struct V_100 * V_101 ;
unsigned int V_169 ;
struct V_39 * V_81 ;
int V_65 , V_165 ;
T_10 V_41 ;
int V_170 ;
T_4 V_72 , V_53 ;
int V_153 ;
int V_171 ;
int V_172 ;
V_19 = V_11 -> V_19 ;
V_33 = F_26 ( V_19 ) ;
V_28 = V_33 -> V_61 ;
V_101 = F_52 ( V_11 ) ;
V_170 = F_88 ( V_11 ) ;
for ( V_65 = 0 ; V_65 < V_150 ; V_65 ++ )
for ( V_165 = 0 ; V_165 < V_166 ; V_165 ++ )
V_101 -> V_167 [ V_65 ] [ V_165 ] = V_168 ;
if ( V_101 -> V_173 == V_166 ) {
V_171 = ( V_148 <= V_166 ) ? V_148 : V_166 ;
V_172 = ( V_148 <= V_166 ) ? 1 :
F_89 ( V_148 ) / V_101 -> V_173 ;
} else {
V_171 = 1 ;
V_172 = 1 ;
}
for ( V_65 = 0 ; V_65 < V_150 ; V_65 ++ ) {
V_81 = & V_11 -> V_39 [ V_65 + V_151 ] ;
if ( ! V_81 -> V_9 || ! V_81 -> V_67 )
continue;
if ( ! F_11 ( V_81 -> V_9 ) )
continue;
for ( V_165 = 0 ; V_165 < V_171 ; V_165 ++ ) {
do {
V_169 = F_17 ( & V_28 -> V_30 . V_50 ,
V_28 -> V_30 . V_44 + 1 , 0 ) ;
if ( V_169 >= V_28 -> V_30 . V_44 + 1 )
goto V_174;
} while ( F_14 ( V_169 , & V_28 -> V_30 . V_50 ) );
V_101 -> V_167 [ V_65 ] [ V_165 ] = V_169 ;
if ( V_101 -> V_173 == V_166 ) {
V_72 = F_67 ( V_11 ,
V_151 + V_65 ) ;
V_72 = V_72 * V_172 ;
V_53 = V_81 -> V_53 + V_72 * V_165 ;
} else {
V_72 = F_44 ( V_81 ) ;
V_53 = V_81 -> V_53 ;
}
if ( V_101 -> V_173 == V_166 ) {
V_153 = V_101 -> V_146 + V_165 ;
V_41 = F_90 ( V_28 -> V_42 ,
V_153 , V_43 ,
V_101 -> V_167 [ V_65 ] [ V_165 ] , 0 ) ;
}
V_41 = F_22 ( V_28 -> V_42 ,
V_43 ,
V_101 -> V_167 [ V_65 ] [ V_165 ] ,
V_53 ,
0 ,
V_72 ) ;
if ( V_41 != V_47 ) {
F_58 ( & V_11 -> V_12 , L_43 ,
V_169 , V_41 ) ;
goto V_174;
}
if ( V_101 -> V_173 == V_166 )
V_41 = F_23 ( V_28 -> V_42 ,
V_43 , V_101 -> V_167 [ V_65 ] [ V_165 ] , 2 ) ;
else
V_41 = F_23 ( V_28 -> V_42 ,
V_43 , V_101 -> V_167 [ V_65 ] [ V_165 ] , 1 ) ;
if ( V_41 != V_47 ) {
F_58 ( & V_11 -> V_12 , L_44 ,
V_169 , V_41 ) ;
goto V_174;
}
}
}
return 0 ;
V_174:
F_86 ( V_11 ) ;
return - V_152 ;
}
static void F_91 ( struct V_58 * V_12 , struct V_1 * V_2 )
{
struct V_175 * V_176 ;
T_10 V_41 ;
V_176 = V_2 -> V_177 . V_178 [ 0 ] ;
V_41 = F_92 ( & V_2 -> V_177 , 0 ) ;
if ( V_41 )
F_55 ( V_2 , L_45 , V_41 ) ;
F_93 ( V_2 , false ) ;
if ( V_2 -> V_177 . V_179 ) {
F_94 ( V_2 -> V_177 . V_179 ) ;
F_95 ( V_2 -> V_177 . V_179 ) ;
}
F_96 ( V_176 ) ;
F_97 ( V_176 , F_98 ( V_12 -> V_12 . V_180 ) ) ;
}
static void F_99 ( struct V_58 * V_11 , T_11 V_148 )
{
struct V_68 * V_19 ;
struct V_60 * V_33 ;
struct V_27 * V_28 ;
struct V_1 * V_2 , * V_181 ;
struct V_100 * V_101 ;
T_11 V_182 ;
T_10 V_41 ;
V_19 = V_11 -> V_19 ;
V_33 = F_26 ( V_19 ) ;
V_28 = V_33 -> V_61 ;
V_101 = F_52 ( V_11 ) ;
if ( ! V_11 -> V_149 )
return;
if ( V_101 -> V_173 == V_166 && V_148 > V_166 ) {
int V_183 ;
int V_172 ;
int V_184 ;
V_172 = F_89 ( V_148 ) / V_101 -> V_173 ;
for ( V_183 = 0 ; V_183 < V_166 ; V_183 ++ )
for ( V_182 = V_183 * V_172 ;
V_182 < ( V_183 + 1 ) * V_172 &&
V_182 < V_148 ;
V_182 ++ )
for ( V_184 = V_183 * V_172 ;
V_184 < ( V_183 + 1 ) * V_172 &&
V_184 < V_148 ;
V_184 ++ ) {
V_41 = F_54 ( V_28 -> V_42 ,
V_101 -> V_146 + V_182 ,
V_101 -> V_146 + V_184 ,
V_106 ) ;
if ( V_41 )
F_100 ( & V_11 -> V_12 , L_46 ,
V_32 ,
V_101 -> V_146 + V_184 , V_41 ) ;
}
}
F_85 (pe, pe_n, &phb->ioda.pe_list, list) {
if ( V_2 -> V_18 != V_11 )
continue;
F_91 ( V_11 , V_2 ) ;
F_101 ( & V_28 -> V_30 . V_185 ) ;
F_102 ( & V_2 -> V_78 ) ;
F_103 ( & V_28 -> V_30 . V_185 ) ;
F_57 ( V_28 , V_2 ) ;
F_18 ( V_28 , V_2 -> V_21 ) ;
}
}
void F_104 ( struct V_58 * V_11 )
{
struct V_68 * V_19 ;
struct V_60 * V_33 ;
struct V_27 * V_28 ;
struct V_100 * V_101 ;
struct V_186 * V_187 ;
T_11 V_148 ;
V_19 = V_11 -> V_19 ;
V_33 = F_26 ( V_19 ) ;
V_28 = V_33 -> V_61 ;
V_101 = F_52 ( V_11 ) ;
V_187 = V_11 -> V_188 ;
V_148 = V_101 -> V_148 ;
F_99 ( V_11 , V_148 ) ;
if ( V_28 -> type == V_83 ) {
if ( V_101 -> V_173 == 1 )
F_66 ( V_11 , - V_101 -> V_146 ) ;
F_86 ( V_11 ) ;
F_105 ( V_28 -> V_30 . V_35 , V_101 -> V_146 , V_148 ) ;
V_101 -> V_146 = 0 ;
}
}
static void F_106 ( struct V_58 * V_11 , T_11 V_148 )
{
struct V_68 * V_19 ;
struct V_60 * V_33 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
int V_153 ;
T_11 V_182 ;
struct V_100 * V_101 ;
T_10 V_41 ;
V_19 = V_11 -> V_19 ;
V_33 = F_26 ( V_19 ) ;
V_28 = V_33 -> V_61 ;
V_101 = F_52 ( V_11 ) ;
if ( ! V_11 -> V_149 )
return;
for ( V_182 = 0 ; V_182 < V_148 ; V_182 ++ ) {
V_153 = V_101 -> V_146 + V_182 ;
V_2 = & V_28 -> V_30 . V_36 [ V_153 ] ;
V_2 -> V_21 = V_153 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_9 = V_17 ;
V_2 -> V_15 = NULL ;
V_2 -> V_18 = V_11 ;
V_2 -> V_155 = - 1 ;
V_2 -> V_132 = - 1 ;
V_2 -> V_20 = ( F_107 ( V_11 , V_182 ) << 8 ) |
F_108 ( V_11 , V_182 ) ;
F_75 ( V_2 , L_47 ,
V_33 -> V_34 , V_11 -> V_19 -> V_16 ,
F_6 ( F_108 ( V_11 , V_182 ) ) ,
F_7 ( F_108 ( V_11 , V_182 ) ) , V_153 ) ;
if ( F_61 ( V_28 , V_2 ) ) {
if ( V_153 )
F_18 ( V_28 , V_153 ) ;
V_2 -> V_11 = NULL ;
continue;
}
F_101 ( & V_28 -> V_30 . V_185 ) ;
F_38 ( & V_2 -> V_78 , & V_28 -> V_30 . V_158 ) ;
F_103 ( & V_28 -> V_30 . V_185 ) ;
F_109 ( V_28 , V_2 ) ;
}
if ( V_101 -> V_173 == V_166 && V_148 > V_166 ) {
int V_183 ;
int V_172 ;
int V_184 ;
V_172 = F_89 ( V_148 ) / V_101 -> V_173 ;
for ( V_183 = 0 ; V_183 < V_166 ; V_183 ++ ) {
for ( V_182 = V_183 * V_172 ;
V_182 < ( V_183 + 1 ) * V_172 &&
V_182 < V_148 ;
V_182 ++ ) {
for ( V_184 = V_183 * V_172 ;
V_184 < ( V_183 + 1 ) * V_172 &&
V_184 < V_148 ;
V_184 ++ ) {
V_41 = F_54 ( V_28 -> V_42 ,
V_101 -> V_146 + V_182 ,
V_101 -> V_146 + V_184 ,
V_105 ) ;
if ( V_41 )
F_100 ( & V_11 -> V_12 , L_48 ,
V_32 ,
V_101 -> V_146 + V_184 , V_41 ) ;
}
}
}
}
}
int F_110 ( struct V_58 * V_11 , T_11 V_148 )
{
struct V_68 * V_19 ;
struct V_60 * V_33 ;
struct V_27 * V_28 ;
struct V_100 * V_101 ;
int V_108 ;
V_19 = V_11 -> V_19 ;
V_33 = F_26 ( V_19 ) ;
V_28 = V_33 -> V_61 ;
V_101 = F_52 ( V_11 ) ;
if ( V_28 -> type == V_83 ) {
F_101 ( & V_28 -> V_30 . V_189 ) ;
V_101 -> V_146 = F_111 (
V_28 -> V_30 . V_35 , V_28 -> V_30 . V_31 ,
0 , V_148 , 0 ) ;
if ( V_101 -> V_146 >= V_28 -> V_30 . V_31 ) {
F_103 ( & V_28 -> V_30 . V_189 ) ;
F_68 ( & V_11 -> V_12 , L_49 , V_148 ) ;
V_101 -> V_146 = 0 ;
return - V_152 ;
}
F_112 ( V_28 -> V_30 . V_35 , V_101 -> V_146 , V_148 ) ;
V_101 -> V_148 = V_148 ;
F_103 ( & V_28 -> V_30 . V_189 ) ;
V_108 = F_87 ( V_11 , V_148 ) ;
if ( V_108 ) {
F_68 ( & V_11 -> V_12 , L_50 ) ;
goto V_174;
}
if ( V_101 -> V_173 == 1 ) {
V_108 = F_66 ( V_11 , V_101 -> V_146 ) ;
if ( V_108 )
goto V_174;
}
}
F_106 ( V_11 , V_148 ) ;
return 0 ;
V_174:
F_105 ( V_28 -> V_30 . V_35 , V_101 -> V_146 , V_148 ) ;
V_101 -> V_146 = 0 ;
return V_108 ;
}
int F_113 ( struct V_58 * V_11 )
{
F_104 ( V_11 ) ;
F_114 ( V_11 ) ;
return 0 ;
}
int F_115 ( struct V_58 * V_11 , T_11 V_148 )
{
F_116 ( V_11 ) ;
F_110 ( V_11 , V_148 ) ;
return 0 ;
}
static void F_117 ( struct V_27 * V_28 , struct V_58 * V_11 )
{
struct V_100 * V_101 = F_52 ( V_11 ) ;
struct V_1 * V_2 ;
if ( ! V_101 || V_101 -> V_21 == V_37 )
return;
V_2 = & V_28 -> V_30 . V_36 [ V_101 -> V_21 ] ;
F_19 ( F_118 ( & V_11 -> V_12 ) != & V_190 ) ;
F_119 ( & V_11 -> V_12 , V_2 -> V_191 ) ;
F_120 ( & V_11 -> V_12 , V_2 -> V_177 . V_178 [ 0 ] ) ;
}
static int F_121 ( struct V_58 * V_11 , T_6 V_192 )
{
struct V_60 * V_33 = F_26 ( V_11 -> V_19 ) ;
struct V_27 * V_28 = V_33 -> V_61 ;
struct V_100 * V_101 = F_52 ( V_11 ) ;
struct V_1 * V_2 ;
T_12 V_193 ;
bool V_194 = false ;
struct V_58 * V_195 ;
int V_65 ;
if ( F_19 ( ! V_101 || V_101 -> V_21 == V_37 ) )
return - V_196 ; ;
V_2 = & V_28 -> V_30 . V_36 [ V_101 -> V_21 ] ;
if ( V_2 -> V_197 ) {
V_193 = V_2 -> V_191 + F_122 () - 1 ;
V_194 = ( V_192 >= V_193 ) ;
}
if ( V_194 ) {
F_68 ( & V_11 -> V_12 , L_51 ) ;
F_123 ( & V_11 -> V_12 , & V_198 ) ;
} else {
F_68 ( & V_11 -> V_12 , L_52 ) ;
F_123 ( & V_11 -> V_12 , & V_190 ) ;
}
* V_11 -> V_12 . V_192 = V_192 ;
if ( V_2 -> V_9 & V_199 )
for ( V_65 = 0 ; V_65 < V_200 ; V_65 ++ ) {
if ( ! V_2 -> V_201 [ V_65 ] )
continue;
V_195 = V_2 -> V_201 [ V_65 ] -> V_11 ;
if ( F_124 ( & V_195 -> V_12 ) != V_192 )
F_125 ( & V_195 -> V_12 , V_192 ) ;
}
return 0 ;
}
static T_6 F_126 ( struct V_58 * V_11 )
{
struct V_60 * V_33 = F_26 ( V_11 -> V_19 ) ;
struct V_27 * V_28 = V_33 -> V_61 ;
struct V_100 * V_101 = F_52 ( V_11 ) ;
struct V_1 * V_2 ;
T_6 V_55 , V_202 ;
if ( F_19 ( ! V_101 || V_101 -> V_21 == V_37 ) )
return 0 ;
V_2 = & V_28 -> V_30 . V_36 [ V_101 -> V_21 ] ;
if ( ! V_2 -> V_197 )
return F_127 ( & V_11 -> V_12 ) ;
V_55 = V_2 -> V_191 + F_122 () ;
V_202 = 1ULL << ( F_128 ( V_55 ) - 1 ) ;
V_202 += V_202 - 1 ;
return V_202 ;
}
static void F_129 ( struct V_1 * V_2 ,
struct V_68 * V_19 )
{
struct V_58 * V_12 ;
F_30 (dev, &bus->devices, bus_list) {
F_120 ( & V_12 -> V_12 , V_2 -> V_177 . V_178 [ 0 ] ) ;
F_119 ( & V_12 -> V_12 , V_2 -> V_191 ) ;
F_130 ( & V_12 -> V_12 ) ;
if ( ( V_2 -> V_9 & V_14 ) && V_12 -> V_70 )
F_129 ( V_2 , V_12 -> V_70 ) ;
}
}
static void F_131 ( struct V_175 * V_176 ,
unsigned long V_203 , unsigned long V_204 , bool V_205 )
{
struct V_206 * V_207 = F_132 (
& V_176 -> V_208 , struct V_206 ,
V_209 ) ;
struct V_1 * V_2 = F_133 ( V_207 -> V_177 ,
struct V_1 , V_177 ) ;
T_13 T_14 * V_210 = V_205 ?
( T_13 T_14 * ) V_2 -> V_28 -> V_30 . V_211 :
V_2 -> V_28 -> V_30 . V_212 ;
unsigned long V_53 , V_55 , V_213 ;
const unsigned V_214 = V_176 -> V_215 ;
V_53 = F_134 ( ( ( T_13 * ) V_176 -> V_216 ) + V_203 - V_176 -> V_217 ) ;
V_55 = F_134 ( ( ( T_13 * ) V_176 -> V_216 ) + V_203 - V_176 -> V_217 +
V_204 - 1 ) ;
if ( V_176 -> V_218 ) {
V_53 <<= V_214 ;
V_55 <<= V_214 ;
V_213 = 128ull << V_214 ;
V_53 |= V_176 -> V_218 ;
V_55 |= V_176 -> V_218 ;
} else if ( V_176 -> V_219 & V_220 ) {
V_53 |= ( 1ull << 63 ) ;
V_55 |= ( 1ull << 63 ) ;
V_213 = 16 ;
} else {
V_213 = 128 ;
}
V_55 |= V_213 - 1 ;
F_135 () ;
while ( V_53 <= V_55 ) {
if ( V_205 )
F_136 ( F_137 ( V_53 ) , V_210 ) ;
else
F_138 ( F_137 ( V_53 ) , V_210 ) ;
V_53 += V_213 ;
}
}
static int F_139 ( struct V_175 * V_176 , long V_203 ,
long V_204 , unsigned long V_221 ,
enum V_222 V_223 ,
struct V_224 * V_225 )
{
int V_108 = F_140 ( V_176 , V_203 , V_204 , V_221 , V_223 ,
V_225 ) ;
if ( ! V_108 && ( V_176 -> V_219 & V_226 ) )
F_131 ( V_176 , V_203 , V_204 , false ) ;
return V_108 ;
}
static int F_141 ( struct V_175 * V_176 , long V_203 ,
unsigned long * V_227 , enum V_222 * V_223 )
{
long V_108 = F_142 ( V_176 , V_203 , V_227 , V_223 ) ;
if ( ! V_108 && ( V_176 -> V_219 &
( V_226 | V_228 ) ) )
F_131 ( V_176 , V_203 , 1 , false ) ;
return V_108 ;
}
static void F_143 ( struct V_175 * V_176 , long V_203 ,
long V_204 )
{
F_144 ( V_176 , V_203 , V_204 ) ;
if ( V_176 -> V_219 & V_228 )
F_131 ( V_176 , V_203 , V_204 , false ) ;
}
static inline void F_145 ( struct V_1 * V_2 )
{
unsigned long V_229 = ( 0x4ull << 60 ) | ( V_2 -> V_21 & 0xFF ) ;
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_1 * V_230 ;
int V_65 ;
if ( ! V_28 -> V_30 . V_212 )
return;
F_135 () ;
F_138 ( F_137 ( V_229 ) , V_28 -> V_30 . V_212 ) ;
if ( V_2 -> V_9 & V_199 )
for ( V_65 = 0 ; V_65 < V_200 ; V_65 ++ ) {
V_230 = V_2 -> V_201 [ V_65 ] ;
if ( ! V_230 || V_230 -> V_28 -> type != V_130 )
continue;
F_146 ( V_230 ) ;
}
}
static void F_147 ( unsigned V_21 , bool V_205 ,
T_13 T_14 * V_210 , unsigned V_214 ,
unsigned long V_203 , unsigned long V_204 )
{
unsigned long V_53 , V_55 , V_213 ;
V_53 = 0x2ull << 60 ;
V_53 |= ( V_21 & 0xFF ) ;
V_55 = V_53 ;
V_53 |= ( V_203 << V_214 ) ;
V_55 |= ( ( V_203 + V_204 - 1 ) << V_214 ) ;
V_213 = ( 0x1ull << V_214 ) ;
F_135 () ;
while ( V_53 <= V_55 ) {
if ( V_205 )
F_136 ( F_137 ( V_53 ) , V_210 ) ;
else
F_138 ( F_137 ( V_53 ) , V_210 ) ;
V_53 += V_213 ;
}
}
static void F_148 ( struct V_175 * V_176 ,
unsigned long V_203 , unsigned long V_204 , bool V_205 )
{
struct V_206 * V_207 ;
F_149 (tgl, &tbl->it_group_list, next) {
struct V_1 * V_230 ;
struct V_1 * V_2 = F_133 ( V_207 -> V_177 ,
struct V_1 , V_177 ) ;
T_13 T_14 * V_210 = V_205 ?
( T_13 T_14 * ) V_2 -> V_28 -> V_30 . V_211 :
V_2 -> V_28 -> V_30 . V_212 ;
int V_65 ;
F_147 ( V_2 -> V_21 , V_205 ,
V_210 , V_176 -> V_215 ,
V_203 , V_204 ) ;
if ( V_2 -> V_9 & V_199 )
for ( V_65 = 0 ; V_65 < V_200 ; V_65 ++ ) {
V_230 = V_2 -> V_201 [ V_65 ] ;
if ( ! V_230 || V_230 -> V_28 -> type != V_130 )
continue;
F_150 ( V_230 , V_176 , V_203 ,
V_204 , V_205 ) ;
}
}
}
static int F_151 ( struct V_175 * V_176 , long V_203 ,
long V_204 , unsigned long V_221 ,
enum V_222 V_223 ,
struct V_224 * V_225 )
{
int V_108 = F_140 ( V_176 , V_203 , V_204 , V_221 , V_223 ,
V_225 ) ;
if ( ! V_108 && ( V_176 -> V_219 & V_226 ) )
F_148 ( V_176 , V_203 , V_204 , false ) ;
return V_108 ;
}
static int F_152 ( struct V_175 * V_176 , long V_203 ,
unsigned long * V_227 , enum V_222 * V_223 )
{
long V_108 = F_142 ( V_176 , V_203 , V_227 , V_223 ) ;
if ( ! V_108 && ( V_176 -> V_219 &
( V_226 | V_228 ) ) )
F_148 ( V_176 , V_203 , 1 , false ) ;
return V_108 ;
}
static void F_153 ( struct V_175 * V_176 , long V_203 ,
long V_204 )
{
F_144 ( V_176 , V_203 , V_204 ) ;
if ( V_176 -> V_219 & V_228 )
F_148 ( V_176 , V_203 , V_204 , false ) ;
}
static void F_154 ( struct V_175 * V_176 )
{
F_96 ( V_176 ) ;
F_97 ( V_176 , L_53 ) ;
}
static void F_155 ( struct V_27 * V_28 ,
struct V_1 * V_2 , unsigned int V_62 ,
unsigned int V_231 )
{
struct V_232 * V_233 = NULL ;
struct V_175 * V_176 ;
unsigned int V_65 ;
T_10 V_41 ;
void * V_234 ;
if ( F_19 ( V_2 -> V_155 >= 0 ) )
return;
V_176 = F_156 ( V_28 -> V_33 -> V_235 ) ;
F_157 ( & V_2 -> V_177 , V_28 -> V_33 -> V_34 ,
V_2 -> V_21 ) ;
F_158 ( V_28 -> V_33 -> V_235 , 0 , V_176 , & V_2 -> V_177 ) ;
V_2 -> V_155 = V_62 ;
F_75 ( V_2 , L_54 ,
( V_62 << 28 ) , ( ( V_62 + V_231 ) << 28 ) - 1 ) ;
V_233 = F_159 ( V_28 -> V_33 -> V_235 , V_73 ,
F_160 ( V_236 * V_231 ) ) ;
if ( ! V_233 ) {
F_60 ( V_2 , L_55 ) ;
goto V_48;
}
V_234 = F_161 ( V_233 ) ;
memset ( V_234 , 0 , V_236 * V_231 ) ;
for ( V_65 = 0 ; V_65 < V_231 ; V_65 ++ ) {
V_41 = F_162 ( V_28 -> V_42 ,
V_2 -> V_21 ,
V_62 + V_65 , 1 ,
F_134 ( V_234 ) + V_236 * V_65 ,
V_236 , 0x1000 ) ;
if ( V_41 ) {
F_60 ( V_2 , L_56
L_57 , V_41 ) ;
goto V_48;
}
}
F_163 ( V_176 , V_234 , V_236 * V_231 ,
V_62 << 28 , V_237 ) ;
if ( V_28 -> V_30 . V_212 )
V_176 -> V_219 |= ( V_226 |
V_228 |
V_220 ) ;
V_176 -> V_238 = & V_239 ;
V_2 -> V_177 . V_240 = V_176 -> V_217 << V_176 -> V_215 ;
V_2 -> V_177 . V_241 = V_176 -> V_242 << V_176 -> V_215 ;
F_164 ( V_176 , V_28 -> V_33 -> V_235 ) ;
if ( V_2 -> V_9 & V_10 ) {
F_120 ( & V_2 -> V_11 -> V_12 , V_176 ) ;
F_130 ( & V_2 -> V_11 -> V_12 ) ;
} else if ( V_2 -> V_9 & ( V_13 | V_14 ) )
F_129 ( V_2 , V_2 -> V_15 ) ;
return;
V_48:
if ( V_2 -> V_155 >= 0 )
V_2 -> V_155 = - 1 ;
if ( V_233 )
F_165 ( V_233 , F_160 ( V_236 * V_231 ) ) ;
if ( V_176 ) {
F_166 ( V_176 , & V_2 -> V_177 ) ;
F_97 ( V_176 , L_53 ) ;
}
}
static long F_167 ( struct V_243 * V_177 ,
int V_244 , struct V_175 * V_176 )
{
struct V_1 * V_2 = F_133 ( V_177 , struct V_1 ,
V_177 ) ;
struct V_27 * V_28 = V_2 -> V_28 ;
T_10 V_41 ;
const unsigned long V_72 = V_176 -> V_245 ?
V_176 -> V_246 : V_176 -> V_242 ;
const T_15 V_247 = V_176 -> V_217 << V_176 -> V_215 ;
const T_15 V_248 = V_176 -> V_242 << V_176 -> V_215 ;
F_75 ( V_2 , L_58 , V_244 ,
V_247 , V_247 + V_248 - 1 ,
F_168 ( V_176 ) ) ;
V_41 = F_162 ( V_28 -> V_42 ,
V_2 -> V_21 ,
( V_2 -> V_21 << 1 ) + V_244 ,
V_176 -> V_245 + 1 ,
F_134 ( V_176 -> V_216 ) ,
V_72 << 3 ,
F_168 ( V_176 ) ) ;
if ( V_41 ) {
F_60 ( V_2 , L_59 , V_41 ) ;
return V_41 ;
}
F_158 ( V_28 -> V_33 -> V_235 , V_244 ,
V_176 , & V_2 -> V_177 ) ;
F_145 ( V_2 ) ;
return 0 ;
}
static void F_93 ( struct V_1 * V_2 , bool V_249 )
{
T_16 V_250 = ( V_2 -> V_21 << 1 ) + 1 ;
T_10 V_41 ;
F_75 ( V_2 , L_60 , V_249 ? L_33 : L_34 ) ;
if ( V_249 ) {
T_17 V_193 = F_122 () ;
V_193 = F_89 ( V_193 ) ;
V_41 = F_169 ( V_2 -> V_28 -> V_42 ,
V_2 -> V_21 ,
V_250 ,
V_2 -> V_191 ,
V_193 ) ;
} else {
V_41 = F_169 ( V_2 -> V_28 -> V_42 ,
V_2 -> V_21 ,
V_250 ,
V_2 -> V_191 ,
0 ) ;
}
if ( V_41 )
F_60 ( V_2 , L_61 , V_41 ) ;
else
V_2 -> V_197 = V_249 ;
}
static long F_170 ( struct V_243 * V_177 ,
int V_244 , T_18 V_251 , T_15 V_252 , T_18 V_253 ,
struct V_175 * * V_254 )
{
struct V_1 * V_2 = F_133 ( V_177 , struct V_1 ,
V_177 ) ;
int V_255 = V_2 -> V_28 -> V_33 -> V_235 ;
T_15 V_256 = V_244 ? V_2 -> V_191 : V_177 -> V_240 ;
long V_108 ;
struct V_175 * V_176 ;
V_176 = F_156 ( V_255 ) ;
if ( ! V_176 )
return - V_257 ;
V_108 = F_171 ( V_255 ,
V_256 , V_251 , V_252 ,
V_253 , V_176 ) ;
if ( V_108 ) {
F_97 ( V_176 , L_53 ) ;
return V_108 ;
}
V_176 -> V_238 = & V_258 ;
if ( V_2 -> V_28 -> V_30 . V_212 )
V_176 -> V_219 |= ( V_226 | V_228 ) ;
* V_254 = V_176 ;
return 0 ;
}
static long F_172 ( struct V_1 * V_2 )
{
struct V_175 * V_176 = NULL ;
long V_41 ;
const T_6 V_259 = F_173 ( F_174 () ) ;
const T_6 V_252 = F_175 ( ( T_6 ) V_2 -> V_177 . V_241 , V_259 ) ;
V_41 = F_170 ( & V_2 -> V_177 , 0 ,
V_237 ,
V_252 ,
V_260 , & V_176 ) ;
if ( V_41 ) {
F_60 ( V_2 , L_62 ,
V_41 ) ;
return V_41 ;
}
F_164 ( V_176 , V_2 -> V_28 -> V_33 -> V_235 ) ;
V_41 = F_167 ( & V_2 -> V_177 , 0 , V_176 ) ;
if ( V_41 ) {
F_60 ( V_2 , L_63 ,
V_41 ) ;
F_154 ( V_176 ) ;
return V_41 ;
}
if ( ! V_24 )
F_93 ( V_2 , true ) ;
if ( V_2 -> V_28 -> V_30 . V_212 )
V_176 -> V_219 |= ( V_226 | V_228 ) ;
if ( V_2 -> V_9 & V_10 )
F_120 ( & V_2 -> V_11 -> V_12 , V_176 ) ;
return 0 ;
}
static long F_92 ( struct V_243 * V_177 ,
int V_244 )
{
struct V_1 * V_2 = F_133 ( V_177 , struct V_1 ,
V_177 ) ;
struct V_27 * V_28 = V_2 -> V_28 ;
long V_108 ;
F_75 ( V_2 , L_64 , V_244 ) ;
V_108 = F_162 ( V_28 -> V_42 , V_2 -> V_21 ,
( V_2 -> V_21 << 1 ) + V_244 ,
0 , 0 ,
0 , 0 ) ;
if ( V_108 )
F_55 ( V_2 , L_65 , V_108 ) ;
else
F_145 ( V_2 ) ;
F_166 ( V_177 -> V_178 [ V_244 ] , V_177 ) ;
return V_108 ;
}
static unsigned long F_176 ( T_18 V_251 ,
T_15 V_252 , T_18 V_253 )
{
unsigned long V_261 = 0 ;
const unsigned V_262 = F_177 ( V_252 ) ;
unsigned V_263 = V_262 - V_251 ;
unsigned V_264 = V_263 + 3 ;
unsigned long V_265 = F_178 ( 0x1000UL , 1UL << V_264 ) ;
unsigned long V_266 ;
if ( ! V_253 || ( V_253 > V_267 ) ||
( V_252 > F_174 () ) ||
! F_179 ( V_252 ) )
return 0 ;
V_263 = ( V_263 + V_253 - 1 ) / V_253 ;
V_264 = V_263 + 3 ;
V_264 = F_180 ( unsigned , V_264 , V_268 ) ;
V_266 = 1UL << V_264 ;
for ( ; V_253 ; -- V_253 ) {
V_261 += F_28 ( V_265 , V_266 ) ;
V_265 /= V_266 ;
V_265 <<= 3 ;
V_265 = F_28 ( V_265 , V_266 ) ;
}
return V_261 ;
}
static void F_181 ( struct V_243 * V_177 )
{
struct V_1 * V_2 = F_133 ( V_177 , struct V_1 ,
V_177 ) ;
struct V_175 * V_176 = V_2 -> V_177 . V_178 [ 0 ] ;
F_93 ( V_2 , false ) ;
F_92 ( & V_2 -> V_177 , 0 ) ;
F_154 ( V_176 ) ;
}
static void F_182 ( struct V_243 * V_177 )
{
struct V_1 * V_2 = F_133 ( V_177 , struct V_1 ,
V_177 ) ;
F_172 ( V_2 ) ;
}
static void F_183 ( struct V_27 * V_28 )
{
const T_13 * V_269 ;
V_269 = F_41 ( V_28 -> V_33 -> V_80 , L_66 , NULL ) ;
if ( ! V_269 )
return;
V_28 -> V_30 . V_211 = F_184 ( V_269 ) ;
V_28 -> V_30 . V_212 = F_185 ( V_28 -> V_30 . V_211 , 8 ) ;
}
static T_13 * F_186 ( int V_255 , unsigned V_214 ,
unsigned V_253 , unsigned long V_270 ,
unsigned long * V_271 , unsigned long * V_272 )
{
struct V_232 * V_233 = NULL ;
T_13 * V_234 , * V_164 ;
unsigned V_273 = F_180 ( unsigned , V_214 , V_268 ) - V_268 ;
unsigned long V_274 = 1UL << ( V_273 + V_268 ) ;
unsigned V_275 = 1UL << ( V_214 - 3 ) ;
long V_65 ;
V_233 = F_159 ( V_255 , V_73 , V_273 ) ;
if ( ! V_233 ) {
F_71 ( L_67 , V_273 ) ;
return NULL ;
}
V_234 = F_161 ( V_233 ) ;
memset ( V_234 , 0 , V_274 ) ;
* V_272 += V_274 ;
-- V_253 ;
if ( ! V_253 ) {
* V_271 += V_274 ;
return V_234 ;
}
for ( V_65 = 0 ; V_65 < V_275 ; ++ V_65 ) {
V_164 = F_186 ( V_255 , V_214 ,
V_253 , V_270 , V_271 , V_272 ) ;
if ( ! V_164 )
break;
V_234 [ V_65 ] = F_137 ( F_134 ( V_164 ) |
V_276 | V_277 ) ;
if ( * V_271 >= V_270 )
break;
}
return V_234 ;
}
static long F_171 ( int V_255 , T_15 V_256 ,
T_18 V_251 , T_15 V_252 , T_18 V_253 ,
struct V_175 * V_176 )
{
void * V_234 ;
unsigned long V_146 = 0 , V_278 , V_272 = 0 ;
const unsigned V_262 = F_177 ( V_252 ) ;
unsigned V_263 = V_262 - V_251 ;
unsigned V_264 = F_180 ( unsigned , V_263 + 3 , V_268 ) ;
const unsigned long V_265 = 1UL << V_264 ;
if ( ! V_253 || ( V_253 > V_267 ) )
return - V_23 ;
if ( ( V_252 > F_174 () ) || ! F_179 ( V_252 ) )
return - V_23 ;
V_263 = ( V_263 + V_253 - 1 ) / V_253 ;
V_278 = V_263 + 3 ;
V_278 = F_180 ( unsigned , V_278 , V_268 ) ;
V_234 = F_186 ( V_255 , V_278 ,
V_253 , V_265 , & V_146 , & V_272 ) ;
if ( ! V_234 )
return - V_257 ;
if ( V_146 < V_265 ) {
F_187 ( V_234 ,
1ULL << ( V_278 - 3 ) , V_253 - 1 ) ;
return - V_257 ;
}
F_163 ( V_176 , V_234 , V_265 , V_256 ,
V_251 ) ;
V_176 -> V_246 = 1ULL << ( V_278 - 3 ) ;
V_176 -> V_245 = V_253 - 1 ;
V_176 -> V_279 = V_272 ;
F_188 ( L_68 ,
V_252 , V_265 , V_256 ) ;
return 0 ;
}
static void F_187 ( T_13 * V_234 ,
unsigned long V_72 , unsigned V_3 )
{
const unsigned long V_280 = ( unsigned long ) V_234 &
~ ( V_276 | V_277 ) ;
if ( V_3 ) {
long V_65 ;
T_6 * V_164 = ( T_6 * ) V_280 ;
for ( V_65 = 0 ; V_65 < V_72 ; ++ V_65 ) {
unsigned long V_227 = F_189 ( V_164 [ V_65 ] ) ;
if ( ! ( V_227 & ( V_276 | V_277 ) ) )
continue;
F_187 ( F_190 ( V_227 ) , V_72 ,
V_3 - 1 ) ;
}
}
F_191 ( V_280 , F_160 ( V_72 << 3 ) ) ;
}
static void F_96 ( struct V_175 * V_176 )
{
const unsigned long V_72 = V_176 -> V_245 ?
V_176 -> V_246 : V_176 -> V_242 ;
if ( ! V_176 -> V_242 )
return;
F_187 ( ( T_13 * ) V_176 -> V_216 , V_72 ,
V_176 -> V_245 ) ;
}
static void F_109 ( struct V_27 * V_28 ,
struct V_1 * V_2 )
{
T_10 V_41 ;
if ( F_19 ( V_2 -> V_155 >= 0 ) )
return;
V_2 -> V_191 = 1ull << 59 ;
F_157 ( & V_2 -> V_177 , V_28 -> V_33 -> V_34 ,
V_2 -> V_21 ) ;
V_2 -> V_155 = 0 ;
F_75 ( V_2 , L_69 ,
V_28 -> V_30 . V_281 ) ;
V_2 -> V_177 . V_240 = 0 ;
V_2 -> V_177 . V_241 = V_28 -> V_30 . V_281 ;
V_2 -> V_177 . V_282 =
V_283 ;
V_2 -> V_177 . V_284 = V_267 ;
V_2 -> V_177 . V_285 = V_286 | V_287 | V_288 ;
#ifdef F_192
V_2 -> V_177 . V_289 = & V_290 ;
#endif
V_41 = F_172 ( V_2 ) ;
if ( V_41 ) {
if ( V_2 -> V_155 >= 0 )
V_2 -> V_155 = - 1 ;
return;
}
if ( V_2 -> V_9 & V_10 )
F_130 ( & V_2 -> V_11 -> V_12 ) ;
else if ( V_2 -> V_9 & ( V_13 | V_14 ) )
F_129 ( V_2 , V_2 -> V_15 ) ;
}
static void F_193 ( struct V_27 * V_28 )
{
struct V_60 * V_33 = V_28 -> V_33 ;
unsigned int V_291 , V_292 , V_231 , V_293 , V_62 ;
struct V_1 * V_2 ;
if ( V_28 -> V_30 . V_157 > V_28 -> V_30 . V_294 )
V_291 = 0 ;
else
V_291 = V_28 -> V_30 . V_294 -
V_28 -> V_30 . V_157 ;
F_10 ( L_70 ,
V_33 -> V_34 , V_28 -> V_30 . V_294 ) ;
F_10 ( L_71 ,
V_28 -> V_30 . V_157 , V_28 -> V_30 . V_136 ) ;
F_183 ( V_28 ) ;
V_292 = V_28 -> V_30 . V_294 ;
V_293 = V_28 -> V_30 . V_136 ;
V_62 = 0 ;
F_30 (pe, &phb->ioda.pe_dma_list, dma_link) {
if ( ! V_2 -> V_136 )
continue;
if ( ! V_292 ) {
F_55 ( V_2 , L_72 ) ;
continue;
}
V_231 = 1 ;
if ( V_291 ) {
V_231 += ( ( V_2 -> V_136 * V_291 ) + ( V_293 / 2 ) ) / V_293 ;
if ( V_231 > V_292 )
V_231 = V_292 ;
}
if ( V_28 -> type == V_131 ) {
F_75 ( V_2 , L_73 ,
V_2 -> V_136 , V_231 ) ;
F_155 ( V_28 , V_2 , V_62 , V_231 ) ;
} else if ( V_28 -> type == V_83 ) {
F_75 ( V_2 , L_74 ) ;
V_231 = 0 ;
F_109 ( V_28 , V_2 ) ;
} else if ( V_28 -> type == V_130 ) {
}
V_292 -= V_231 ;
V_62 += V_231 ;
}
}
static void F_194 ( struct V_295 * V_296 )
{
unsigned int V_297 = ( unsigned int ) F_195 ( V_296 ) ;
struct V_298 * V_299 = F_196 ( V_296 ) ;
struct V_27 * V_28 = F_133 ( V_299 , struct V_27 ,
V_30 . V_298 ) ;
T_10 V_41 ;
V_41 = F_197 ( V_28 -> V_42 , V_297 ) ;
F_198 ( V_41 ) ;
F_199 ( V_296 ) ;
}
static void F_200 ( struct V_27 * V_28 , unsigned int V_300 )
{
struct V_295 * V_301 ;
struct V_298 * V_302 ;
if ( V_28 -> type != V_83 )
return;
if ( ! V_28 -> V_30 . V_303 ) {
V_301 = F_201 ( V_300 ) ;
V_302 = F_196 ( V_301 ) ;
V_28 -> V_30 . V_303 = 1 ;
V_28 -> V_30 . V_298 = * V_302 ;
V_28 -> V_30 . V_298 . V_304 = F_194 ;
}
F_202 ( V_300 , & V_28 -> V_30 . V_298 ) ;
}
struct V_79 * F_203 ( struct V_58 * V_12 )
{
struct V_60 * V_33 = F_26 ( V_12 -> V_19 ) ;
return F_204 ( V_33 -> V_80 ) ;
}
int F_205 ( struct V_58 * V_12 , T_12 V_305 )
{
struct V_60 * V_33 = F_26 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_33 -> V_61 ;
struct V_1 * V_2 ;
int V_41 ;
V_2 = F_51 ( V_12 ) ;
if ( ! V_2 )
return - V_196 ;
F_75 ( V_2 , L_75 ) ;
V_41 = F_206 ( V_28 -> V_42 , V_305 , V_2 -> V_21 ) ;
if ( V_41 )
F_58 ( & V_12 -> V_12 , L_76 , V_41 ) ;
return V_41 ;
}
int F_207 ( struct V_58 * V_12 , int V_244 )
{
struct V_60 * V_33 = F_26 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_33 -> V_61 ;
int V_306 = F_208 ( & V_28 -> V_307 , V_244 ) ;
if ( V_306 < 0 ) {
F_100 ( & V_12 -> V_12 , L_77 ) ;
return - V_308 ;
}
return V_28 -> V_309 + V_306 ;
}
void F_209 ( struct V_58 * V_12 , int V_306 , int V_244 )
{
struct V_60 * V_33 = F_26 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_33 -> V_61 ;
F_210 ( & V_28 -> V_307 , V_306 - V_28 -> V_309 , V_244 ) ;
}
void F_211 ( struct V_310 * V_311 ,
struct V_58 * V_12 )
{
struct V_60 * V_33 = F_26 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_33 -> V_61 ;
int V_65 , V_306 ;
for ( V_65 = 1 ; V_65 < V_312 ; V_65 ++ ) {
if ( ! V_311 -> V_313 [ V_65 ] )
continue;
F_188 ( L_78 ,
V_65 , V_311 -> V_146 [ V_65 ] ,
V_311 -> V_313 [ V_65 ] ) ;
V_306 = V_311 -> V_146 [ V_65 ] - V_28 -> V_309 ;
F_210 ( & V_28 -> V_307 , V_306 ,
V_311 -> V_313 [ V_65 ] ) ;
}
}
int F_212 ( struct V_310 * V_311 ,
struct V_58 * V_12 , int V_244 )
{
struct V_60 * V_33 = F_26 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_33 -> V_61 ;
int V_65 , V_306 , V_314 ;
memset ( V_311 , 0 , sizeof( struct V_310 ) ) ;
for ( V_65 = 1 ; V_65 < V_312 && V_244 ; V_65 ++ ) {
V_314 = V_244 ;
while ( V_314 ) {
V_306 = F_208 ( & V_28 -> V_307 , V_314 ) ;
if ( V_306 >= 0 )
break;
V_314 /= 2 ;
}
if ( ! V_314 )
goto V_48;
V_311 -> V_146 [ V_65 ] = V_28 -> V_309 + V_306 ;
V_311 -> V_313 [ V_65 ] = V_314 ;
F_188 ( L_79 ,
V_65 , V_311 -> V_146 [ V_65 ] , V_311 -> V_313 [ V_65 ] ) ;
V_244 -= V_314 ;
}
if ( V_244 )
goto V_48;
return 0 ;
V_48:
F_211 ( V_311 , V_12 ) ;
return - V_308 ;
}
int F_213 ( struct V_58 * V_12 )
{
struct V_60 * V_33 = F_26 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_33 -> V_61 ;
return V_28 -> V_307 . V_315 ;
}
int F_214 ( struct V_58 * V_12 , unsigned int V_306 ,
unsigned int V_300 )
{
struct V_60 * V_33 = F_26 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_33 -> V_61 ;
unsigned int V_316 = V_306 - V_28 -> V_309 ;
struct V_1 * V_2 ;
int V_41 ;
if ( ! ( V_2 = F_51 ( V_12 ) ) )
return - V_196 ;
V_41 = F_215 ( V_28 -> V_42 , V_2 -> V_21 , V_316 ) ;
if ( V_41 ) {
F_55 ( V_2 , L_80
L_81 ,
F_72 ( V_12 ) , V_41 , V_28 -> V_309 , V_306 , V_316 ) ;
return - V_57 ;
}
F_200 ( V_28 , V_300 ) ;
return 0 ;
}
static int F_216 ( struct V_27 * V_28 , struct V_58 * V_12 ,
unsigned int V_306 , unsigned int V_300 ,
unsigned int V_317 , struct V_318 * V_319 )
{
struct V_1 * V_2 = F_51 ( V_12 ) ;
unsigned int V_316 = V_306 - V_28 -> V_309 ;
T_19 V_320 ;
int V_41 ;
if ( V_2 == NULL )
return - V_107 ;
if ( V_2 -> V_132 < 0 )
return - V_107 ;
if ( V_12 -> V_321 )
V_317 = 0 ;
V_41 = F_215 ( V_28 -> V_42 , V_2 -> V_21 , V_316 ) ;
if ( V_41 ) {
F_13 ( L_82 ,
F_72 ( V_12 ) , V_41 , V_316 ) ;
return - V_57 ;
}
if ( V_317 ) {
T_13 V_322 ;
V_41 = F_217 ( V_28 -> V_42 , V_2 -> V_132 , V_316 , 1 ,
& V_322 , & V_320 ) ;
if ( V_41 ) {
F_13 ( L_83 ,
F_72 ( V_12 ) , V_41 ) ;
return - V_57 ;
}
V_319 -> V_323 = F_189 ( V_322 ) >> 32 ;
V_319 -> V_324 = F_189 ( V_322 ) & 0xfffffffful ;
} else {
T_19 V_325 ;
V_41 = F_218 ( V_28 -> V_42 , V_2 -> V_132 , V_316 , 1 ,
& V_325 , & V_320 ) ;
if ( V_41 ) {
F_13 ( L_84 ,
F_72 ( V_12 ) , V_41 ) ;
return - V_57 ;
}
V_319 -> V_323 = 0 ;
V_319 -> V_324 = F_219 ( V_325 ) ;
}
V_319 -> V_320 = F_219 ( V_320 ) ;
F_200 ( V_28 , V_300 ) ;
F_188 ( L_85
L_86 ,
F_72 ( V_12 ) , V_317 ? L_87 : L_88 , V_306 , V_316 ,
V_319 -> V_323 , V_319 -> V_324 , V_320 , V_2 -> V_21 ) ;
return 0 ;
}
static void F_220 ( struct V_27 * V_28 )
{
unsigned int V_115 ;
const T_19 * V_326 = F_41 ( V_28 -> V_33 -> V_80 ,
L_89 , NULL ) ;
if ( ! V_326 ) {
V_326 = F_41 ( V_28 -> V_33 -> V_80 , L_90 , NULL ) ;
}
if ( ! V_326 )
return;
V_28 -> V_309 = F_221 ( V_326 ) ;
V_115 = F_221 ( V_326 + 1 ) ;
if ( F_222 ( & V_28 -> V_307 , V_115 , V_28 -> V_33 -> V_80 ) ) {
F_71 ( L_91 ,
V_28 -> V_33 -> V_34 ) ;
return;
}
V_28 -> V_327 = F_216 ;
V_28 -> V_328 = 1 ;
F_10 ( L_92 ,
V_115 , V_28 -> V_309 ) ;
}
static void F_220 ( struct V_27 * V_28 ) { }
static void F_223 ( struct V_58 * V_11 )
{
struct V_60 * V_33 ;
struct V_27 * V_28 ;
struct V_39 * V_81 ;
int V_65 ;
T_4 V_72 ;
struct V_100 * V_101 ;
int V_329 , V_170 ;
if ( ! V_11 -> V_149 || V_11 -> V_330 )
return;
V_33 = F_26 ( V_11 -> V_19 ) ;
V_28 = V_33 -> V_61 ;
V_101 = F_52 ( V_11 ) ;
V_101 -> V_331 = 0 ;
V_170 = F_88 ( V_11 ) ;
V_101 -> V_173 = 1 ;
V_329 = V_28 -> V_30 . V_31 ;
for ( V_65 = 0 ; V_65 < V_150 ; V_65 ++ ) {
V_81 = & V_11 -> V_39 [ V_65 + V_151 ] ;
if ( ! V_81 -> V_9 || V_81 -> V_67 )
continue;
if ( ! F_11 ( V_81 -> V_9 ) ) {
F_100 ( & V_11 -> V_12 , L_93 ,
V_65 , V_81 ) ;
continue;
}
V_72 = F_67 ( V_11 , V_65 + V_151 ) ;
if ( V_72 > ( 1 << 26 ) ) {
F_68 ( & V_11 -> V_12 , L_94 ,
V_65 , V_81 ) ;
V_101 -> V_173 = V_166 ;
V_329 = F_89 ( V_170 ) ;
break;
}
}
for ( V_65 = 0 ; V_65 < V_150 ; V_65 ++ ) {
V_81 = & V_11 -> V_39 [ V_65 + V_151 ] ;
if ( ! V_81 -> V_9 || V_81 -> V_67 )
continue;
if ( ! F_11 ( V_81 -> V_9 ) ) {
F_100 ( & V_11 -> V_12 , L_95 ,
V_65 , V_81 ) ;
continue;
}
F_224 ( & V_11 -> V_12 , L_96 , V_65 , V_81 ) ;
V_72 = F_67 ( V_11 , V_65 + V_151 ) ;
V_81 -> V_55 = V_81 -> V_53 + V_72 * V_329 - 1 ;
F_224 ( & V_11 -> V_12 , L_97 , V_81 ) ;
F_68 ( & V_11 -> V_12 , L_98 ,
V_65 , V_81 , V_329 ) ;
}
V_101 -> V_331 = V_329 ;
}
static void F_225 ( struct V_60 * V_33 ,
struct V_1 * V_2 )
{
struct V_27 * V_28 = V_33 -> V_61 ;
struct V_332 V_333 ;
struct V_39 * V_81 ;
int V_65 , V_203 ;
int V_41 ;
F_95 ( ! ( V_2 -> V_9 & ( V_13 | V_14 ) ) ) ;
F_226 (pe->pbus, res, i) {
if ( ! V_81 || ! V_81 -> V_9 ||
V_81 -> V_53 > V_81 -> V_55 )
continue;
if ( V_81 -> V_9 & V_334 ) {
V_333 . V_53 = V_81 -> V_53 - V_28 -> V_30 . V_335 ;
V_333 . V_55 = V_81 -> V_55 - V_28 -> V_30 . V_335 ;
V_203 = V_333 . V_53 / V_28 -> V_30 . V_336 ;
while ( V_203 < V_28 -> V_30 . V_31 &&
V_333 . V_53 <= V_333 . V_55 ) {
V_28 -> V_30 . V_337 [ V_203 ] = V_2 -> V_21 ;
V_41 = F_90 ( V_28 -> V_42 ,
V_2 -> V_21 , V_338 , 0 , V_203 ) ;
if ( V_41 != V_47 ) {
F_71 ( L_99
L_100 ,
V_32 , V_41 , V_203 , V_2 -> V_21 ) ;
break;
}
V_333 . V_53 += V_28 -> V_30 . V_336 ;
V_203 ++ ;
}
} else if ( ( V_81 -> V_9 & V_87 ) &&
! F_11 ( V_81 -> V_9 ) ) {
V_333 . V_53 = V_81 -> V_53 -
V_33 -> V_88 [ 0 ] -
V_28 -> V_30 . V_281 ;
V_333 . V_55 = V_81 -> V_55 -
V_33 -> V_88 [ 0 ] -
V_28 -> V_30 . V_281 ;
V_203 = V_333 . V_53 / V_28 -> V_30 . V_339 ;
while ( V_203 < V_28 -> V_30 . V_31 &&
V_333 . V_53 <= V_333 . V_55 ) {
V_28 -> V_30 . V_340 [ V_203 ] = V_2 -> V_21 ;
V_41 = F_90 ( V_28 -> V_42 ,
V_2 -> V_21 , V_341 , 0 , V_203 ) ;
if ( V_41 != V_47 ) {
F_71 ( L_101
L_102 ,
V_32 , V_41 , V_203 , V_2 -> V_21 ) ;
break;
}
V_333 . V_53 += V_28 -> V_30 . V_339 ;
V_203 ++ ;
}
}
}
}
static void F_227 ( void )
{
struct V_60 * V_164 , * V_33 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
F_85 (hose, tmp, &hose_list, list_node) {
V_28 = V_33 -> V_61 ;
if ( V_28 -> type == V_130 )
continue;
F_30 (pe, &phb->ioda.pe_list, list) {
F_225 ( V_33 , V_2 ) ;
}
}
}
static void F_228 ( void )
{
struct V_60 * V_33 , * V_164 ;
struct V_27 * V_28 ;
F_85 (hose, tmp, &hose_list, list_node) {
F_193 ( V_33 -> V_61 ) ;
V_28 = V_33 -> V_61 ;
V_28 -> V_342 = 1 ;
}
}
static void F_229 ( void )
{
#ifdef F_230
struct V_60 * V_33 , * V_164 ;
struct V_27 * V_28 ;
char V_86 [ 16 ] ;
F_85 (hose, tmp, &hose_list, list_node) {
V_28 = V_33 -> V_61 ;
sprintf ( V_86 , L_103 , V_33 -> V_34 ) ;
V_28 -> V_343 = F_231 ( V_86 , V_344 ) ;
if ( ! V_28 -> V_343 )
F_73 ( L_104 ,
V_32 , V_33 -> V_34 ) ;
}
#endif
}
static void F_232 ( void )
{
bool V_345 ;
struct V_60 * V_33 , * V_164 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
F_85 (hose, tmp, &hose_list, list_node) {
V_28 = V_33 -> V_61 ;
if ( V_28 -> type != V_130 )
continue;
F_30 (pe, &phb->ioda.pe_dma_list, dma_link) {
V_345 = F_124 ( & V_2 -> V_11 -> V_12 ) ==
F_233 ( 64 ) ;
F_234 ( V_2 ) ;
F_235 ( V_2 , V_345 ) ;
}
}
}
static void F_236 ( void )
{
F_84 () ;
F_227 () ;
F_228 () ;
F_229 () ;
#ifdef F_237
F_238 () ;
F_239 () ;
#endif
F_232 () ;
}
static T_4 F_240 ( struct V_68 * V_19 ,
unsigned long type )
{
struct V_58 * V_346 ;
struct V_60 * V_33 = F_26 ( V_19 ) ;
struct V_27 * V_28 = V_33 -> V_61 ;
int V_347 = 0 ;
V_346 = V_19 -> V_110 ;
while ( V_346 ) {
if ( F_83 ( V_346 ) == V_163 ) {
V_347 ++ ;
if ( V_347 >= 2 )
return 1 ;
}
V_346 = V_346 -> V_19 -> V_110 ;
}
if ( V_28 -> V_30 . V_54 &&
F_11 ( type ) )
return V_28 -> V_30 . V_54 ;
if ( type & V_87 )
return V_28 -> V_30 . V_339 ;
return V_28 -> V_30 . V_336 ;
}
static T_4 F_241 ( struct V_58 * V_11 ,
int V_348 )
{
struct V_100 * V_101 = F_52 ( V_11 ) ;
T_4 V_349 , V_350 ;
V_350 = F_44 ( & V_11 -> V_39 [ V_348 ] ) ;
if ( V_350 )
return V_350 ;
V_349 = F_67 ( V_11 , V_348 ) ;
if ( V_101 -> V_331 )
return V_101 -> V_331 * V_349 ;
return V_349 ;
}
static bool F_242 ( struct V_58 * V_12 )
{
struct V_60 * V_33 = F_26 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_33 -> V_61 ;
struct V_100 * V_101 ;
if ( ! V_28 -> V_342 )
return true ;
V_101 = F_52 ( V_12 ) ;
if ( ! V_101 || V_101 -> V_21 == V_37 )
return false ;
return true ;
}
static T_5 F_243 ( struct V_27 * V_28 , struct V_68 * V_19 ,
T_5 V_156 )
{
return V_28 -> V_30 . V_127 [ ( V_19 -> V_16 << 8 ) | V_156 ] ;
}
static void F_244 ( struct V_60 * V_33 )
{
struct V_27 * V_28 = V_33 -> V_61 ;
F_245 ( V_28 -> V_42 , V_351 ,
V_352 ) ;
}
static void T_2 F_246 ( struct V_79 * V_353 ,
T_6 V_354 , int V_355 )
{
struct V_60 * V_33 ;
struct V_27 * V_28 ;
unsigned long V_72 , V_356 , V_357 , V_358 = 0 ;
const T_13 * V_359 ;
const T_19 * V_360 ;
int V_361 ;
T_6 V_362 ;
void * V_363 ;
long V_41 ;
F_10 ( L_105 , V_355 , V_353 -> V_85 ) ;
V_359 = F_41 ( V_353 , L_106 , NULL ) ;
if ( ! V_359 ) {
F_71 ( L_107 ) ;
return;
}
V_362 = F_184 ( V_359 ) ;
F_15 ( L_108 , V_362 ) ;
V_28 = F_247 ( sizeof( struct V_27 ) , 0 ) ;
V_28 -> V_33 = V_33 = F_248 ( V_353 ) ;
if ( ! V_28 -> V_33 ) {
F_71 ( L_109 ,
V_353 -> V_85 ) ;
F_249 ( F_134 ( V_28 ) , sizeof( struct V_27 ) ) ;
return;
}
F_250 ( & V_28 -> V_364 ) ;
V_360 = F_41 ( V_353 , L_110 , & V_361 ) ;
if ( V_360 && V_361 == 8 ) {
V_33 -> V_365 = F_219 ( V_360 [ 0 ] ) ;
V_33 -> V_366 = F_219 ( V_360 [ 1 ] ) ;
} else {
F_13 ( L_111 , V_353 -> V_85 ) ;
V_33 -> V_365 = 0 ;
V_33 -> V_366 = 0xff ;
}
V_33 -> V_61 = V_28 ;
V_28 -> V_354 = V_354 ;
V_28 -> V_42 = V_362 ;
V_28 -> type = V_355 ;
F_251 ( & V_28 -> V_30 . V_189 ) ;
if ( F_252 ( V_353 , L_112 ) )
V_28 -> V_367 = V_368 ;
else if ( F_252 ( V_353 , L_113 ) )
V_28 -> V_367 = V_369 ;
else if ( F_252 ( V_353 , L_114 ) )
V_28 -> V_367 = V_370 ;
else
V_28 -> V_367 = V_371 ;
F_253 ( V_33 , V_353 , ! V_33 -> V_34 ) ;
V_28 -> V_372 = F_254 ( V_353 , 0 ) ;
if ( V_28 -> V_372 == NULL )
F_71 ( L_115 ) ;
V_28 -> V_30 . V_31 = 1 ;
V_360 = F_41 ( V_353 , L_116 , NULL ) ;
if ( V_360 )
V_28 -> V_30 . V_31 = F_221 ( V_360 ) ;
V_360 = F_41 ( V_353 , L_117 , NULL ) ;
if ( V_360 )
V_28 -> V_30 . V_52 = F_221 ( V_360 ) ;
F_39 ( V_28 ) ;
V_28 -> V_30 . V_373 = F_44 ( & V_33 -> V_51 [ 0 ] ) ;
V_28 -> V_30 . V_373 += 0x10000 ;
V_28 -> V_30 . V_339 = V_28 -> V_30 . V_373 / V_28 -> V_30 . V_31 ;
V_28 -> V_30 . V_281 = V_33 -> V_51 [ 0 ] . V_53 - V_33 -> V_88 [ 0 ] ;
V_28 -> V_30 . V_374 = V_33 -> V_375 ;
V_28 -> V_30 . V_336 = V_28 -> V_30 . V_374 / V_28 -> V_30 . V_31 ;
V_28 -> V_30 . V_335 = 0 ;
V_72 = F_28 ( V_28 -> V_30 . V_31 / 8 , sizeof( unsigned long ) ) ;
V_356 = V_72 ;
V_72 += V_28 -> V_30 . V_31 * sizeof( V_28 -> V_30 . V_340 [ 0 ] ) ;
if ( V_28 -> type == V_131 ) {
V_358 = V_72 ;
V_72 += V_28 -> V_30 . V_31 * sizeof( V_28 -> V_30 . V_337 [ 0 ] ) ;
}
V_357 = V_72 ;
V_72 += V_28 -> V_30 . V_31 * sizeof( struct V_1 ) ;
V_363 = F_247 ( V_72 , 0 ) ;
V_28 -> V_30 . V_35 = V_363 ;
V_28 -> V_30 . V_340 = V_363 + V_356 ;
if ( V_28 -> type == V_131 )
V_28 -> V_30 . V_337 = V_363 + V_358 ;
V_28 -> V_30 . V_36 = V_363 + V_357 ;
F_24 ( V_28 -> V_30 . V_52 , V_28 -> V_30 . V_35 ) ;
F_37 ( & V_28 -> V_30 . V_138 ) ;
F_37 ( & V_28 -> V_30 . V_158 ) ;
F_251 ( & V_28 -> V_30 . V_185 ) ;
V_28 -> V_30 . V_294 = V_28 -> V_30 . V_281 >> 28 ;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
F_10 ( L_118 ,
V_28 -> V_30 . V_31 , V_28 -> V_30 . V_52 ,
V_28 -> V_30 . V_373 , V_28 -> V_30 . V_339 ) ;
if ( V_28 -> V_30 . V_46 )
F_10 ( L_119 ,
V_28 -> V_30 . V_46 , V_28 -> V_30 . V_54 ) ;
if ( V_28 -> V_30 . V_374 )
F_10 ( L_120 ,
V_28 -> V_30 . V_374 , V_28 -> V_30 . V_336 ) ;
V_28 -> V_33 -> V_289 = & V_376 ;
V_28 -> V_377 = F_49 ;
V_28 -> V_378 = F_45 ;
V_28 -> V_379 = F_47 ;
V_28 -> V_380 = F_243 ;
V_28 -> V_381 = F_117 ;
F_220 ( V_28 ) ;
V_382 . V_383 = F_236 ;
if ( V_28 -> type == V_130 )
V_33 -> V_384 = V_385 ;
else
V_33 -> V_384 = V_386 ;
#ifdef F_5
V_382 . V_387 = F_223 ;
V_382 . V_388 = F_241 ;
#endif
F_255 ( V_389 ) ;
V_41 = F_245 ( V_362 , V_351 , V_352 ) ;
if ( V_41 )
F_73 ( L_121 , V_41 ) ;
if ( F_256 () ) {
F_10 ( L_122 ) ;
F_257 ( V_33 , V_390 ) ;
F_257 ( V_33 , V_391 ) ;
}
if ( ! V_28 -> V_89 || V_28 -> V_89 ( V_28 ) )
V_33 -> V_51 [ 1 ] . V_9 = 0 ;
}
void T_2 F_258 ( struct V_79 * V_353 )
{
F_246 ( V_353 , 0 , V_83 ) ;
}
void T_2 F_259 ( struct V_79 * V_353 )
{
F_246 ( V_353 , 0 , V_130 ) ;
}
void T_2 F_260 ( struct V_79 * V_353 )
{
struct V_79 * V_392 ;
const T_13 * V_359 ;
T_6 V_354 ;
F_10 ( L_123 , V_353 -> V_85 ) ;
V_359 = F_41 ( V_353 , L_124 , NULL ) ;
if ( ! V_359 ) {
F_71 ( L_125 ) ;
return;
}
V_354 = F_184 ( V_359 ) ;
F_188 ( L_126 , V_354 ) ;
F_261 (np, phbn) {
if ( F_252 ( V_392 , L_127 ) )
F_246 ( V_392 , V_354 , V_131 ) ;
}
}
